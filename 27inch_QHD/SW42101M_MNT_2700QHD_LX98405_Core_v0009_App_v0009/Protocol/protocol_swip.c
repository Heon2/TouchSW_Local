/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  param_config.c
 * created on :  17. 4. 2017
 * Author :  mhjang
 *
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *   - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name of SiW nor the names of its contributors may be used
 *   to endorse or promote products derived from this software without
 *   specific prior written permission.
 * *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************************************/


#if defined(USE_BOOTLOADER_CODE)
#include "MFTP.h"
//#include "algorithm_conf.h"
#else /* USE_BOOTLOADER_CODE */
#include "core_def.h"
#endif /* USE_BOOTLOADER_CODE */
#include "protocol_log.h"
#include "protocol_swip.h"
#include "protocol_conf.h"
#include "i2c.h" // NOTE : warning����
#include "crc.h"
#include "gpio.h"
#include "param_def.h"


static const tProtocolCommonConf_t * thisCommonConf = NULL;
static tProtocolInfo_t * thisInfo = NULL;
static tAlgorithmInfo_t * sptAlgorithmInfo = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////
static tSWIPPanel_t ktSWIPInfoPanel;
static tSWIPFirmwareSectionVersion_t ktSWIPInfoFirmwareSectionVersion;
static tSWIPFirmwareSectionAddress_t ktSWIPInfoFirmwareSectionAddress;
static tSWIPFirmwareIntegrity_t ktSWIPInfoFirmwareIntegrity;

static tSWIPInterface_t ktSWIPInfoInterface  =
{
	.vcProtocolName = "SWIP",
	.bcdProtocolVersion = 0x0110,
	.I2C_VID = UNIQUE_VID,
	.I2C_PID = UNIQUE_APP_PID,
};

#if defined(SUPPORT_ANDROID)
static u4byteString_t stSprChipID  = PSTR(SPR_CHIP_ID);
static u8byteString_t ktSWIPPProductID  = PSTR(TC_PRODUCT_ID);
static chip_version_t stChipVersion = 
{
  .boot = BOOT_VER,
	.core = CORE_VER
};


static tc_version_t stTcVersion =
{
	.minor    = 1,
	.major    = 0,
	.build    = 0,
	.chip     = 15,
	.protocol = 4,
	.rsvd     = 0
};

static tSWIPAndroidBaseInfo_t tSWIPAndroidBaseInfo =
{
		.ptSprChipID      = &(stSprChipID),
		.ptTcVersion      = &(stTcVersion),
		.ptChipVersion    = &(stChipVersion),
		.ptTcProductId    = &(ktSWIPPProductID)
};


static uint32_t stSWIPAndroidSprInfo[] =
{
		0x00,
		SPR_BOOT_STS,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		SPR_SUBDISP_STS,
		0x00	
};

static tSWIPAndroidSprChipInfo_t tSWIPAndroidSprInfo =
{
		.ptSprChipTest   = (&stSWIPAndroidSprInfo[0]), 	 //0x400
		.ptSprBootSts    = (&stSWIPAndroidSprInfo[1]), 	 //0x401
		.ptTcDeviceCtl   = (&stSWIPAndroidSprInfo[2]), 	 //0x402
		.ptTcInterruptCtl= (&stSWIPAndroidSprInfo[3]), 	 //0x403
		.ptImeState  		 = (&stSWIPAndroidSprInfo[4]), 	 //0x404
		.ptTciEnableW    = (&stSWIPAndroidSprInfo[5]), 	 //0x405
		.ptSwipeEnableW  = (&stSWIPAndroidSprInfo[6]), 	 //0x406
		.ptSprSubDispSts = (&stSWIPAndroidSprInfo[7]), 	 //0x407
		.ptTcDriveCtl    = (&stSWIPAndroidSprInfo[8]) 	 //0x408
};

static int stAndroidItemSize = 0;
static uint32_t	stIc_Status = IC_STATUS;
static tTouchData_t stTouchData;

static tAndroidDevInfo_t tSwipAndroidDevInfo = 
{
  ._ic_status = IC_STATUS,		
};

static tReportPacket_t tSWIPAndroidReportPacket =
{
		.ic_status     = &(tSwipAndroidDevInfo._ic_status),			
		.tc_status     = &(tSwipAndroidDevInfo._tc_status),
    .info          = &(tSwipAndroidDevInfo._info),    
    .data          = &(tSwipAndroidDevInfo._data[0]),
};
#endif

static tSWIPExtra_t ktSWIPInfoExtra ;
static tSWIPTrimCodeSet_t ktSWIPInfoTrimCode;

static tSWIPInfo_t tSWIPInfo =
{
    .ptPanel			= &(ktSWIPInfoPanel),
    .ptVersion			= &(ktSWIPInfoFirmwareSectionVersion),
    .ptSectionAddress	= &(ktSWIPInfoFirmwareSectionAddress),
    .ptIntegrity		= &(ktSWIPInfoFirmwareIntegrity),
    .ptInterface		= &(ktSWIPInfoInterface),
    .ptExtra			= &(ktSWIPInfoExtra),
	.ptTrimCode			= &(ktSWIPInfoTrimCode)
};

/////////////////////////////////////////////////////////////////////////////////////////////////
#if (!USED_MOBILE_I2C_PROTOCOL)
static tSWIPEventFormat_t tSWIPEventFormat ;
#endif /* (!USED_MOBILE_I2C_PROTOCOL) */

#if USED_MOBILE_I2C_PROTOCOL
static tSWIPEvent_t tSWIPEvent;
#else /* USED_MOBILE_I2C_PROTOCOL */
static tSWIPEvent_t tSWIPEvent  =
{
	.ptEventFormat = &tSWIPEventFormat,
    //vtTouchItem�� malloc���� ���� �����.
    //Packet�� INTR ���� �� ������ �� ���� �ٸ� ������ �����ϹǷ� scope�� ���ѹ��� �ʴ� dedicated buffer Ȱ���ؾ� �ϱ� ������.
};
#endif /* USED_MOBILE_I2C_PROTOCOL */

tSWIPPacketInfo_t ptDummyPacketInfo = 
{
#if USED_MOBILE_I2C_PROTOCOL
	.tTouchinfo.palmBit = 0,
	.tTouchinfo.touch_cnt = 0,
#else /* USED_MOBILE_I2C_PROTOCOL */
	.ReportSize = 0x0000,
	.ReportID   = 0x01,
#endif /* USED_MOBILE_I2C_PROTOCOL */
};

/////////////////////////////////////////////////////////////////////////////////////////////////
static tSWIPTestInfo_t ktSWIPTestInfo  =
{
	.usBufferAddr = SWIP_REG_ADDR_GENERAL_BUFFER,
	.usProtocolId = SWIP_TEST_PROTOCOL_ID
};

static tSWIPTestControl_t ktSWIPTestControl  =
{
	.eTestType = CTT_NONE
};

static tSWIPTest_t tSWIPTest  =
{
    .tTest =
    {
        .ptInfo = &(ktSWIPTestInfo),
        .ptCtrl = &(ktSWIPTestControl),
    },
};

/////////////////////////////////////////////////////////////////////////////////////////////////
static tSWIPControlForTuning_t ktSWIPControlForTuning  =
{
	.bGNDNoiseStatus = NO,
	.bLCDNoiseStatus = NO,
	.ucOscVal = 0xFF,
	.bReadModuleConfig = NO,
};

static tSWIPSpecialAction_t tSWIPSpecialAction  =
{
    .ptControlForTuning = &(ktSWIPControlForTuning),
    .ptPWMDRVParam = NULL,
    .ptROICParam   = NULL
};

/////////////////////////////////////////////////////////////////////////////////////////////////
static tSWIPParameterInfo_t ktSWIPParameterInfo  =
{
	.usBufferAddr = SWIP_REG_ADDR_PARAMETER_BUFFER,
	.usProtocolId = SWIP_PARAMETER_PROTOCOL_ID
};

static tSWIPParameter_t tSWIPParameter  =
{
    .ptInfo = &(ktSWIPParameterInfo),
};

/////////////////////////////////////////////////////////////////////////////////////////////////
static uint16_t ktProtocolBufferStartAddr[]  =
{
	SWIP_REG_ADDR_GENERAL_BUFFER,
	SWIP_REG_ADDR_PARAMETER_BUFFER
};

static tSWIPBufferInfo_t tSWIPBufferInfo  =
{
    .ppucBuffer = (uint8_t**)&vtProtocolBufferPointers,
    .vusStartAddr = (uint16_t *)ktProtocolBufferStartAddr,
    .iSize = sizeof(vtProtocolBufferPointers)/sizeof(void*)
};

#if defined(SUPPORT_ANDROID)
// SWIP_REG_ADDR_ANDR_BASE_INFO
static uint8_t SWIP_REG_ADDR_ANDR_BASE_INFO_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_SPR_CHIP_ID),
	LSB(SWIP_REG_ADDR_TC_VERSION),
	LSB(SWIP_REG_ADDR_CHIP_VERSION),
	LSB(SWIP_REG_ADDR_TC_PRODUCT_ID)
};

// SWIP_REG_ADDR_ANDROID_EVENT
static uint8_t SWIP_REG_ADDR_ANDR_TOUCH_INFO_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_ANDROID_IC_STATUS),		
	LSB(SWIP_REG_ADDR_ANDROID_TC_STATUS),	
	LSB(SWIP_REG_ADDR_ANDROID_TOUCH_INFO),	
	LSB(SWIP_REG_ADDR_ANDROID_PACKET_DATA),
};


// SWIP_REG_ADDR_SPR_CHIP_INFO
static uint8_t SWIP_REG_ADDR_ANDR_SPRCHIP_INFO_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_SPR_CHIP_TEST),		
	LSB(SWIP_REG_ADDR_SPR_BOOT_STS),	
	LSB(SWIP_REG_ADDR_TC_DEVICE_CTL),	
	LSB(SWIP_REG_ADDR_TC_INTERRUPT_CTL),
	LSB(SWIP_REG_ADDR_IME_STATE),		
	LSB(SWIP_REG_ADDR_TCI_ENABLE_W),	
	LSB(SWIP_REG_ADDR_SWIPE_ENABLE_W),	
	LSB(SWIP_REG_ADDR_SPR_SUBDISP_STS),	
	LSB(SWIP_REG_ADDR_TC_DRIVE_CTL)
};
#endif

// SWIP_REG_ADDR_INFO
static uint8_t SWIP_REG_ADDR_INFO_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_INFO_PANEL),
	LSB(SWIP_REG_ADDR_INFO_SECTION_VERSION),
	LSB(SWIP_REG_ADDR_INFO_SECTION_ADDR),
	LSB(SWIP_REG_ADDR_INFO_INTEGRITY),
	LSB(SWIP_REG_ADDR_INFO_INTERFACE),
	LSB(SWIP_REG_ADDR_INFO_EXTRA),
	LSB(SWIP_REG_ADDR_INFO_TRIMCODE_1),
	LSB(SWIP_REG_ADDR_INFO_TRIMCODE_2)
};

static uint8_t SWIP_REG_ADDR_EVENT_LOWER_ADDR[]  =
{
#if USED_MOBILE_I2C_PROTOCOL
		LSB(SWIP_REG_ADDR_EVENT_PACKET_FORMAT),
		LSB(SWIP_REG_ADDR_EVENT_PACKET_INFO),
		LSB(SWIP_REG_ADDR_EVENT_PACKET_CONTENT)
#else /* USED_MOBILE_I2C_PROTOCOL */
		LSB(SWIP_REG_ADDR_EVENT_FORMAT),
		LSB(SWIP_REG_ADDR_EVENT_PACKET_INFO),
		LSB(SWIP_REG_ADDR_EVENT_PACKET_CONTENT)
#endif /* USED_MOBILE_I2C_PROTOCOL */
};

static uint8_t SWIP_REG_ADDR_CTRL_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_CTRL_GETTER),
	LSB(SWIP_REG_ADDR_CTRL_SETTER)
};

static uint8_t SWIP_REG_ADDR_PARAMETER_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_PARAMETER_INFO),
//	LSB(SWIP_REG_ADDR_PARAMETER_CONTROL)
};

static uint8_t SWIP_REG_ADDR_TEST_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_TEST_CM_INFO),
	LSB(SWIP_REG_ADDR_TEST_CM_CONTROL),
	LSB(SWIP_REG_ADDR_TEST_CM_DATA_FORMAT),
};

static uint8_t SWIP_REG_ADDR_IMAGE_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_IMAGE_INFO),
	LSB(SWIP_REG_ADDR_IMAGE_CONTROL),
	LSB(SWIP_REG_ADDR_IMAGE_DATA_FORMAT),
	LSB(SWIP_REG_ADDR_IMAGE_FINGER_NUM),
	LSB(SWIP_REG_ADDR_IMAGE_FINGER_AREA),
};

static uint8_t SWIP_REG_ADDR_LOG_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_LOG_INFO),
	LSB(SWIP_REG_ADDR_LOG_CONTROL),
	LSB(SWIP_REG_ADDR_LOG_DATA_FORMAT)
};

static uint8_t SWIP_REG_ADDR_SPECIAL_ACTION_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_CONTROL_FOR_TUNING),
	LSB(SWIP_REG_ADDR_PWMDRV_FOR_TUNING),
	LSB(SWIP_REG_ADDR_DRIVER_FOR_TUNING)
};

static uint8_t SWIP_REG_ADDR_FLASH_IAP_CTRL_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_FLASH_IAP_CTRL_CMD)
};

#if defined(SUPPORT_ANDROID)
static tSWIPSubsetInfo_t ktAndroidSubsetInfo  =
{
	.ppucData = (uint8_t**)&tSWIPAndroidBaseInfo,
	.vucStartLAddr = SWIP_REG_ADDR_ANDR_BASE_INFO_LOWER_ADDR,
	.iSize = sizeof(tSWIPAndroidBaseInfo)/sizeof(void*)
};

static tSWIPSubsetInfo_t ktAndroidSubsetEvent  =
{
	.ppucData = (uint8_t**)&tSWIPAndroidReportPacket,
	.vucStartLAddr = SWIP_REG_ADDR_ANDR_TOUCH_INFO_LOWER_ADDR,
	.iSize = sizeof(tSWIPAndroidReportPacket)/sizeof(void*)
};

static tSWIPSubsetInfo_t ktAndroidSubsetSprInfo  =
{
	.ppucData = (uint8_t**)&tSWIPAndroidSprInfo,
	.vucStartLAddr = SWIP_REG_ADDR_ANDR_SPRCHIP_INFO_LOWER_ADDR,
	.iSize = sizeof(tSWIPAndroidSprInfo)/sizeof(void*)
};
#endif


static tSWIPSubsetInfo_t ktSubsetInfo  =
{
	.ppucData = (uint8_t**)&tSWIPInfo,
	.vucStartLAddr = SWIP_REG_ADDR_INFO_LOWER_ADDR,
	.iSize = sizeof(tSWIPInfo)/sizeof(void*)
};

static tSWIPSubsetInfo_t ktSubsetEvent  =
{
	.ppucData = (uint8_t**)&tSWIPEvent,
	.vucStartLAddr = SWIP_REG_ADDR_EVENT_LOWER_ADDR,
	.iSize = sizeof(tSWIPEvent)/sizeof(void*)
};

static tSWIPSubsetInfo_t ktSubsetCtrl  =
{
	.ppucData = (uint8_t**)&tProtocolCtrl,
	.vucStartLAddr = SWIP_REG_ADDR_CTRL_LOWER_ADDR,
	.iSize = sizeof(tProtocolCtrl)/sizeof(void*)
};

static tSWIPSubsetInfo_t ktSubsetParam  =
{
	.ppucData = (uint8_t**)&tSWIPParameter,
	.vucStartLAddr = SWIP_REG_ADDR_PARAMETER_LOWER_ADDR,
	.iSize = sizeof(tSWIPParameter)/sizeof(void*)
};

static tSWIPSubsetInfo_t ktSubsetTest  =
{
	.ppucData = (uint8_t**)&tSWIPTest,
	.vucStartLAddr = SWIP_REG_ADDR_TEST_LOWER_ADDR,
	.iSize = sizeof(tSWIPTest)/sizeof(void*)
};

static tSWIPSubsetInfo_t ktSubsetImage  =
{
	.ppucData = (uint8_t**)&tProtocolImage,
	.vucStartLAddr = SWIP_REG_ADDR_IMAGE_LOWER_ADDR,
	.iSize = sizeof(tProtocolImage)/sizeof(void*)
};

static tSWIPSubsetInfo_t ktSubsetLog  =
{
	.ppucData = (uint8_t**)&tProtocolLog,
	.vucStartLAddr = SWIP_REG_ADDR_LOG_LOWER_ADDR,
	.iSize = sizeof(tProtocolLog)/sizeof(void*)
};

static tSWIPSubsetInfo_t ktSubsetSpecialAction  =
{
	.ppucData = (uint8_t**)&tSWIPSpecialAction,
	.vucStartLAddr = SWIP_REG_ADDR_SPECIAL_ACTION_LOWER_ADDR,
	.iSize = sizeof(tSWIPSpecialAction)/sizeof(void*)
};

static tSWIPSubsetInfo_t ktSubsetIAP  =
{
	.ppucData = (uint8_t**)&tFlashIAPPacket,
	.vucStartLAddr = SWIP_REG_ADDR_FLASH_IAP_CTRL_LOWER_ADDR,
	.iSize = sizeof(tFlashIAPPacket)/sizeof(void*)
};

static tSWIPSubsetInfo_t* vtMRmiMap[]  =
{
#if defined(SUPPORT_ANDROID)
    [MSB(SWIP_REG_ADDR_ANDR_BASE_INFO)] = &(ktAndroidSubsetInfo),
#endif    
    [MSB(SWIP_REG_ADDR_INFO)          ] = &(ktSubsetInfo),
    [MSB(SWIP_REG_ADDR_EVENT)         ] = &(ktSubsetEvent),
#if defined(SUPPORT_ANDROID)
	
		[MSB(SWIP_REG_ADDR_ANDROID_EVENT)] = &(ktAndroidSubsetEvent),
		[MSB(SWIP_REG_ADDR_SPR_CHIP_INFO)] = &(ktAndroidSubsetSprInfo),
#endif  
    //[0x05] = NULL,
    [MSB(SWIP_REG_ADDR_CTRL)          ] = &(ktSubsetCtrl),
    //[0x07] = NULL,
    [MSB(SWIP_REG_ADDR_PARAMETER)     ] = &(ktSubsetParam),
    //[0x09] = NULL,
    [MSB(SWIP_REG_ADDR_TEST)          ] = &(ktSubsetTest),
    //[0x0B] = NULL,
    [MSB(SWIP_REG_ADDR_IMAGE)         ] = &(ktSubsetImage),
    //[0x0D] = NULL,
    //[0x0E] = NULL,
    //[0x0F] = NULL,
    //[0x10] = NULL,
    [MSB(SWIP_REG_ADDR_LOG)           ] = &(ktSubsetLog),
    [MSB(SWIP_REG_ADDR_SPECIAL_ACTION)] = &(ktSubsetSpecialAction),
    [MSB(SWIP_REG_ADDR_FLASH_IAP_CTRL)] = &(ktSubsetIAP),
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void Hal_ClearIntr(void) 
{
  if(CheckI2CReady() || !protocol_swip_GetEventIntrType()) return;
	
	GPIO->tGPIO_DATA_1.tBit.GPB10 = 0x01;
}

bool_t Hal_GetIntr(void)
{
 
 if(CheckI2CReady()||!protocol_swip_GetEventIntrType()) return 0;
	
	if(GPIO->tGPIO_DATA_1.tBit.GPB10 == 0x00)
	{
		GPIO->tGPIO_DATA_1.tBit.GPB10 = 0x01;
	}

	return 0;
}
void Hal_PendIntr(void)
{
  
  if(CheckI2CReady() || !protocol_swip_GetEventIntrType()) return;
	GPIO->tGPIO_DATA_1.tBit.GPB10 = 0x00;
}

extern volatile unsigned long BaseAddr;
extern unsigned char* fullBuffer;
unsigned int crc_value;
void protocol_swip_Init(void)
{
//	volatile unsigned long  BOOT_ADDR = 0x00001FFAUL;
#if defined(SUPPORT_ANDROID)		
	char PRODUCID_temp[9];
	volatile unsigned long TC_ADDR= 0x0001FFECUL;
	volatile unsigned long CHIPVER_ADDR= 0x0001FFE8UL;
	volatile unsigned long PRODUCID_ADDR= 0x0001FFF0UL;
#endif /* SUPPORT_ANDROID */
//    tAlgorithmCommonConf_t* _ptAlgorithmCommonConf 	= algorithm_GetCommonConfig();
//    tModuleCommonConf_t   *	_ptModuleCommonConf 	= module_GetCommonConfig();
//    tModuleInfo_t         *	_ptModuleInfo 			= module_GetInfo();

	thisCommonConf = protocol_GetCommonConfig();
	thisInfo = protocol_GetInfo();
	sptAlgorithmInfo = algorithm_GetInfo();

//    memcpy(tSWIPInfo.ptPanel->vcProductName, _ptAppCommonConf->vcProductCode, sizeof(_ptAppCommonConf->vcProductCode));
//
#if defined(SUPPORT_ANDROID)
	tSWIPInfo.ptPanel->usXResolution = 1920;
	tSWIPInfo.ptPanel->usYResolution = 1080;
#else
	tSWIPInfo.ptPanel->usXResolution = I2C_X_RESOLUTION;//32768;
	tSWIPInfo.ptPanel->usYResolution = I2C_Y_RESOLUTION;//32768;
#endif

	tSWIPInfo.ptPanel->ucXNode_ = COL_MAX;
	tSWIPInfo.ptPanel->ucYNode_ = ROW_MAX;
	
#ifdef USE_BOOTLOADER_16KB
	if( BACKUP_BOOT_INFO_1->I2C_BOOT_INFO_b.BOOT_VERSION == 0xFFFF)
	{			
		tSWIPInfo.ptVersion->bcdBootVer = BOOT_VER;
	}
	else
	{
		tSWIPInfo.ptVersion->bcdBootVer = BACKUP_BOOT_INFO_1->I2C_BOOT_INFO_b.BOOT_VERSION;
	}
#endif
    tSWIPInfo.ptVersion->bcdCoreVer = CORE_VERSION;
    tSWIPInfo.ptVersion->bcdAppVer  = APP_VERSION;
    tSWIPInfo.ptVersion->bcdParaVer = PARA_VERSION;

#if defined(SUPPORT_ANDROID)
	// Read  android version ================================================================
	if (((*(volatile uint32_t *)TC_ADDR) & 0xFFFFFFFF) != 0xFFFFFFFF)
	{
		tSWIPAndroidBaseInfo.ptTcVersion->minor = (*(volatile uint8_t *)TC_ADDR) & 0xFF;
		tSWIPAndroidBaseInfo.ptTcVersion->major = (*(volatile uint8_t *)(TC_ADDR+1)) & 0x0F;
		tSWIPAndroidBaseInfo.ptTcVersion->build = (*(volatile uint8_t *)(TC_ADDR+1)) & 0xF0;
		tSWIPAndroidBaseInfo.ptTcVersion->chip = (*(volatile uint8_t *)(TC_ADDR+2)) & 0xFF;
		tSWIPAndroidBaseInfo.ptTcVersion->protocol = (*(volatile uint8_t *)(TC_ADDR+3)) & 0x0F;
	}

	if (((*(volatile uint32_t *)CHIPVER_ADDR) & 0xFFFFFFFF) != 0xFFFFFFFF)
	{
		tSWIPAndroidBaseInfo.ptChipVersion->boot = (*(volatile uint16_t *)CHIPVER_ADDR) & 0xFFFF;
		tSWIPAndroidBaseInfo.ptChipVersion->core = (*(volatile uint16_t *)(CHIPVER_ADDR+2)) & 0xFFFF;
	}

	if (((*(volatile uint64_t *)PRODUCID_ADDR) & 0xFFFFFFFFFFFFFFFF) != 0xFFFFFFFFFFFFFFFF)
	{
		PRODUCID_temp[0] = (*(volatile uint8_t *)(PRODUCID_ADDR)) & 0xFF;
		PRODUCID_temp[1] = (*(volatile uint8_t *)(PRODUCID_ADDR+1)) & 0xFF;
		PRODUCID_temp[2] = (*(volatile uint8_t *)(PRODUCID_ADDR+2)) & 0xFF;
		PRODUCID_temp[3] = (*(volatile uint8_t *)(PRODUCID_ADDR+3)) & 0xFF;
		PRODUCID_temp[4] = (*(volatile uint8_t *)(PRODUCID_ADDR+4)) & 0xFF;
		PRODUCID_temp[5] = (*(volatile uint8_t *)(PRODUCID_ADDR+5)) & 0xFF;
		PRODUCID_temp[6] = (*(volatile uint8_t *)(PRODUCID_ADDR+6)) & 0xFF;
		PRODUCID_temp[7] = (*(volatile uint8_t *)(PRODUCID_ADDR+7)) & 0xFF;


		tSWIPAndroidBaseInfo.ptTcProductId->string[0] = PRODUCID_temp[0];
		tSWIPAndroidBaseInfo.ptTcProductId->string[1] = PRODUCID_temp[1];
		tSWIPAndroidBaseInfo.ptTcProductId->string[2] = PRODUCID_temp[2];
		tSWIPAndroidBaseInfo.ptTcProductId->string[3] = PRODUCID_temp[3];
		tSWIPAndroidBaseInfo.ptTcProductId->string[4] = PRODUCID_temp[4];
		tSWIPAndroidBaseInfo.ptTcProductId->string[5] = PRODUCID_temp[5];
		tSWIPAndroidBaseInfo.ptTcProductId->string[6] = PRODUCID_temp[6];
		tSWIPAndroidBaseInfo.ptTcProductId->string[7] = PRODUCID_temp[7];
	}

	//=============================================================================================
#endif /* SUPPORT_ANDROID */

//	if(((*(volatile uint8_t *)BOOT_ADDR) & 0xFF) == 0xFF)
//	{
//		tSWIPInfo.ptVersion->bcdBootVer = BOOT_VER;
//#if defined(SUPPORT_ANDROID)
//		tSWIPAndroidBaseInfo.ptChipVersion->boot = tSWIPInfo.ptVersion->bcdBootVer;
//#endif /* SUPPORT_ANDROID */
//	}
//	else
//	{
//		tSWIPInfo.ptVersion->bcdBootVer = (*(volatile uint8_t *)BOOT_ADDR) & 0xFF;
//#if defined(SUPPORT_ANDROID)
//		tSWIPAndroidBaseInfo.ptChipVersion->boot = tSWIPInfo.ptVersion->bcdBootVer;
//#endif
//	}

//	fullBuffer = (unsigned char *)BaseAddr; // NOTE : warning����
//	crc_value = (uint32_t)(Crc16WordCalc((const uint16_t*)&fullBuffer[0], FW_SIZE / 2 - 4, 0) | (Crc16WordCalc((const uint16_t*)&fullBuffer[2], FW_SIZE / 2 - 4, 0) << 16)); // NOTE : warning����
//	crc_value = crc_value ^ 0xFFFFFFFF;
//	crc_value = 0x00000000;

//	tSWIPInfo.ptIntegrity->ulParamCRC = 0x00000000;
#if (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_91K)
	tSWIPInfo.ptExtra->usPWMTxFrequecy = 94;
#elif (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_133K)
	tSWIPInfo.ptExtra->usPWMTxFrequecy = 133;
#elif (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_150K)
	tSWIPInfo.ptExtra->usPWMTxFrequecy = 150;
#else /* (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_200K) */
	tSWIPInfo.ptExtra->usPWMTxFrequecy = 200;
#endif /* (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_91K) */

#if USED_MOBILE_I2C_PROTOCOL
//	int iItemSize = 0x06;
	int iTouchEventPacketSize  = sizeof(tSWIPPacketInfo_t);

//	tSWIPEvent.ptEventFormat->ucTouchPacketItemSize = iItemSize;
	tSWIPEvent.ptPacketInfo = malloc(iTouchEventPacketSize);
	memset(tSWIPEvent.ptPacketInfo, 0, iTouchEventPacketSize);
#else /* USED_MOBILE_I2C_PROTOCOL */

	fullBuffer = (unsigned char *)BaseAddr;
	
#if defined(USE_BOOTLOADER_16KB)
	crc_value = (uint32_t)Crc16WordCalc((const uint16_t*)&fullBuffer[0], FW_CRC_SIZE / 2, 0) | (Crc16WordCalc((const uint16_t*)&fullBuffer[2], FW_CRC_SIZE / 2, 0) << 16);
#else
//	crc_value = (uint32_t)Crc16WordCalc((const uint16_t*)&fullBuffer[0], FW_SIZE / 2 - 4, 0) | (Crc16WordCalc((const uint16_t*)&fullBuffer[2], FW_SIZE / 2 - 4, 0) << 16);
//	crc_value = (uint32_t)Crc16WordCalc((const uint16_t*)&fullBuffer[0], 120*1024 / 2, 0) | (Crc16WordCalc((const uint16_t*)&fullBuffer[2], 120*1024 / 2, 0) << 16);
	crc_value = (uint32_t)Crc16WordCalc((const uint16_t*)&fullBuffer[0], 108*1024 / 2, 0) | (Crc16WordCalc((const uint16_t*)&fullBuffer[2], 108*1024 / 2, 0) << 16);
	#endif

	crc_value = crc_value ^ 0xFFFFFFFF;

	tSWIPInfo.ptIntegrity->usCalculateCRC1 = (crc_value>>24) & 0xFF;
	tSWIPInfo.ptIntegrity->usCalculateCRC2 = (crc_value>>16) & 0xFF;
	tSWIPInfo.ptIntegrity->usCalculateCRC3 = (crc_value>>8) & 0xFF;
	tSWIPInfo.ptIntegrity->usCalculateCRC4 = crc_value & 0xFF;

	tSWIPInfo.ptExtra->usPWMTxFrequecy = 91;


		tSWIPEvent.ptEventFormat->ePacketFormatId = thisCommonConf->ePacketFormatId;

	int iItemSize = 0x06;
	int iTouchEventPacketSize  = 0x0042;


	tSWIPEvent.ptEventFormat->ucTouchPacketItemSize = iItemSize;
	tSWIPEvent.ptPacketInfo = malloc(iTouchEventPacketSize);
	memset(tSWIPEvent.ptPacketInfo, 0, iTouchEventPacketSize);
#endif /* USED_MOBILE_I2C_PROTOCOL */

#if defined(SUPPORT_ANDROID)
	int AndroidItemSize = sizeof(tTouchData_t);
	int AndroidPacketSize  = (AndroidItemSize * MAX_TOUCH_);//120;
	stAndroidItemSize = AndroidItemSize;

	memset(tSWIPAndroidReportPacket.data, 0, AndroidPacketSize);


	tSWIPAndroidReportPacket.tc_status->running_sts        = 0x7;
	tSWIPAndroidReportPacket.tc_status->device_checked_sts = 0x0; //Check if system set TC_DEVICE_CTL = 1 then set this register = 1
	tSWIPAndroidReportPacket.tc_status->code_valid				 = 0x1;
	tSWIPAndroidReportPacket.tc_status->cfg_valid 				 = 0x1;
	tSWIPAndroidReportPacket.tc_status->font_valid				 = 0x1;
	tSWIPAndroidReportPacket.tc_status->abnormal_sts			 = 0x0;
	tSWIPAndroidReportPacket.tc_status->esd_error_sts 		 = 0x0;
	tSWIPAndroidReportPacket.tc_status->reserved0 				 = 0x0;
	tSWIPAndroidReportPacket.tc_status->disp_mode_mismatch = 0x0;
	tSWIPAndroidReportPacket.tc_status->reserved1 				 = 0x0;
	tSWIPAndroidReportPacket.tc_status->interrupt_sts 		 = 0x1;
	tSWIPAndroidReportPacket.tc_status->interrupt_type		 = 0x5;
	tSWIPAndroidReportPacket.tc_status->touch_int_en_sts	 = 0x1;
	tSWIPAndroidReportPacket.tc_status->dwatch_int_en_sts  = 0x0;
	tSWIPAndroidReportPacket.tc_status->tc_drv_valid			 = 0x1;
	tSWIPAndroidReportPacket.tc_status->tc_cfg_load_type	 = 0x0;
	tSWIPAndroidReportPacket.tc_status->dic_disp_sts			 = 0x1;
	tSWIPAndroidReportPacket.tc_status->model_id_load_flag = 0x1;
	tSWIPAndroidReportPacket.tc_status->pt_info_error 		 = 0x0;
	tSWIPAndroidReportPacket.tc_status->reserved2 				 = 0x0;
#endif /* SUPPORT_ANDROID */
	vtProtocolBufferPointers.pParameterBuffer = (void *)PARAM_GetPreMainSet();
}

void protocol_swip_PendEventInterrupt(void)
{
#if defined(SUPPORT_ANDROID)
    protocol_android_SetEventIntrType();
#endif		
    thisInfo->eEventTriggerType = tProtocolCtrl.setter->eEventTriggerType;
    switch( thisInfo->eEventTriggerType )
    {
    case ETT_INTERRUPT:
        Hal_PendIntr();
        break;
    case ETT_REGISTER:
        tProtocolCtrl.getter->bEventReady = YES;
        break;
    }
}

void protocol_swip_ClearEventInterrupt(void)
{
    switch( thisInfo->eEventTriggerType )
    {
    case ETT_INTERRUPT:
        Hal_ClearIntr();
        break;
    case ETT_REGISTER:
        tProtocolCtrl.getter->bEventReady = NO;
        break;
    }
}

bool_t protocol_swip_CheckEventInterrupt(void)
{
    thisInfo->eEventTriggerType = tProtocolCtrl.setter->eEventTriggerType;
    switch( thisInfo->eEventTriggerType )
    {
    case ETT_INTERRUPT:
        if(GPIO->tGPIO_DATA_1.tBit.GPB10 == 0x01 )	return YES;
		else									return NO;
//        break; // NOTE : warning����
    case ETT_REGISTER:
        if(tProtocolCtrl.getter->bEventReady == NO) 	return YES;
		else											return NO;
//        break; // NOTE : warning����
    default:
    	break;
    }

    return NO; // NOTE : warning����
}

void protocol_swip_WaitEventInterruptCleared(void)
{
#define INTR_HIGH_              300
#define WAIT_FOR_INTERRUPT_     0xFFFF
	int intr = NO;
	int cnt = WAIT_FOR_INTERRUPT_;
	
	do
	{
		switch( thisInfo->eEventTriggerType )
		{
			case ETT_INTERRUPT:
			{
				intr = Hal_GetIntr();
				if( cnt-- == 0 )
				{
					Hal_ClearIntr();
					int i;
					for (i = INTR_HIGH_; i--;)
					__NOP();
					Hal_PendIntr();
					cnt = WAIT_FOR_INTERRUPT_;
				}
			}
			break;

			case ETT_REGISTER:
			{
				intr = tProtocolCtrl.getter->bEventReady;
				if( intr )
				{
					protocol_swip_ClearEventInterrupt();
				}
			}
			break;

			case ETT_NONE:
				intr = NO;
			break;
		}

		if( thisInfo->eEventTriggerType != tProtocolCtrl.setter->eEventTriggerType )
		{
			thisInfo->eEventTriggerType = tProtocolCtrl.setter->eEventTriggerType;
			protocol_swip_ClearEventInterrupt();
			break;
		}
	}
	while (intr);
}

eProtocolMode_t protocol_swip_GetMode(void)
{
    return tProtocolCtrl.setter->eMode;
}

void protocol_swip_SetMode(eProtocolMode_t _eMode)
{
	tProtocolCtrl.setter->eMode = _eMode;
}

bool_t protocol_swip_GetEventIntrType(void)
{
   return (tProtocolCtrl.setter->eEventTriggerType == ETT_INTERRUPT) ? YES : NO;
}

#if defined(SUPPORT_ANDROID)
bool_t protocol_android_SetEventIntrType(void)
{
   if(tProtocolCtrl.setter->eEventTriggerType != ETT_INTERRUPT)
   {
      if(tSWIPAndroidSprInfo.ptTcInterruptCtl)
      {
        tProtocolCtrl.setter->eEventTriggerType = ETT_INTERRUPT;
      }
   }
}
bool_t protocol_android_SetDevCtlSts(void)
{ 
  if(!tSWIPAndroidReportPacket.tc_status->device_checked_sts)
  {
		if(tSWIPAndroidSprInfo.ptTcDeviceCtl)
		{
			tSWIPAndroidReportPacket.tc_status->device_checked_sts = 0x1;
		}
  }
}
#endif
bool_t protocol_swip_GetRecalibrate(void)
{
    return tProtocolCtrl.setter->bRecalibrate;
}

void protocol_swip_SetRecalibrate(bool_t _bRecalibrate)
{
	tProtocolCtrl.setter->bRecalibrate = _bRecalibrate;
}

ePowerConsumptionState_t protocol_swip_GetPowerConsumptionState(void)
{
    return tProtocolCtrl.setter->ePowerConsumptionState;
}

void protocol_swip_SetPowerConsumptionState(ePowerConsumptionState_t _eState)
{
	tProtocolCtrl.setter->ePowerConsumptionState = _eState;
}

uint32_t protocol_swip_GetGestureType(void)
{
    return tProtocolCtrl.setter->ulGestureType;
}

void protocol_swip_SetGestureType(uint32_t _ulGestureType)
{
	tProtocolCtrl.setter->ulGestureType = _ulGestureType;
}

bool_t protocol_swip_GetDisableESDAlert(void)
{
    return tProtocolCtrl.setter->bDisableESDAlert;
}

void protocol_swip_SetDiableESDAlert(bool_t _bVal)
{
	tProtocolCtrl.setter->bDisableESDAlert = _bVal;
}

bool_t protocol_swip_GetChargerAttached(void)
{
    return tProtocolCtrl.setter->bChargerAttached;
}

void protocol_swip_SetChargetAttached(bool_t _bVal)
{
	tProtocolCtrl.setter->bChargerAttached = _bVal;
}

bool_t protocol_swip_GetSensingOnWindowEnable(void)
{
    return tProtocolCtrl.setter->bSensingOnWindowEnable;
}

void protocol_swip_SetSensingOnWindowEnable(bool_t _bVal)
{
	tProtocolCtrl.setter->bSensingOnWindowEnable = _bVal;
}

bool_t protocol_swip_GetGloveSensingEnable(void)
{
    return tProtocolCtrl.setter->bGloveSensingEnable;
}

void protocol_swip_SetGloveSensingEnable(bool_t _bVal)
{
	tProtocolCtrl.setter->bGloveSensingEnable = _bVal;
}

bool_t protocol_swip_GetPalmRejectionEnable(void)
{
    return tProtocolCtrl.setter->bPalmRejectionEnable;
}

void protocol_swip_SetPalmRejectionEnable(bool_t _bVal)
{
	tProtocolCtrl.setter->bPalmRejectionEnable = _bVal;
}

bool_t protocol_swip_GetDisableEdgeExpand(void)
{
    return tProtocolCtrl.setter->bDisableEdgeExpand;
}

void protocol_swip_SetDisableEdgeExpand(bool_t _bVal)
{
    tProtocolCtrl.setter->bDisableEdgeExpand = _bVal;
}

uint8_t protocol_swip_GetABSDiffCount(void)
{
    return tSWIPTest.tTest.ptCtrl->ucABSDiffCount;
}

uint8_t protocol_swip_GetABSCount(void)
{
    return tSWIPTest.tTest.ptCtrl->ucABSCount;
}

uint8_t protocol_swip_GetDCABSCount(void)
{
    return tSWIPTest.tTest.ptCtrl->ucDCABSCount;
}

uint8_t protocol_swip_GetJitterAVGCount(void)
{
    return tSWIPTest.tTest.ptCtrl->ucJitterAVGCount;
}

uint8_t protocol_swip_GetJitterMAXCount(void)
{
    return tSWIPTest.tTest.ptCtrl->ucJitterMAXCount;
}

//uint32_t protocol_swip_GetCRCValue(void)
//{
//	return tSWIPTest.tTest.ptCtrl->lCRCValue;
//}
//void protocol_swip_SetCRCValue(uint32_t _lCRCValue)
//{
//	tSWIPTest.tTest.ptCtrl->lCRCValue = _lCRCValue;
//}

void protocol_swip_PendReadyStatus(void)
{
    tProtocolCtrl.getter->eReadyStatus = RS_READY;
    while( tProtocolCtrl.getter->eReadyStatus == RS_READY );
}

void protocol_swip_PendReadyStatusCustom(eProtocolReadyStatus_t data) // NOTE : warning����
{
    tProtocolCtrl.getter->eReadyStatus = data;
    while( tProtocolCtrl.getter->eReadyStatus == data )
        ;
}

void protocol_swip_SetParameterBuffer(void* p)
{
    vtProtocolBufferPointers.pGeneralBuffer = p;
}

void protocol_swip_SetTestType(eSWIPTestType_t _t)
{
    tSWIPTest.tTest.ptCtrl->eTestType = _t;
}

eSWIPTestType_t protocol_swip_GetTestType(void)
{
    return tSWIPTest.tTest.ptCtrl->eTestType;
}

void protocol_swip_PendTestResult(const tSWIPTestDataFmt_t* _ptDataFormat, const void* _pBuf)
{
    tSWIPTest.tTest.ptCtrl->eTestType = CTT_NONE;
    //Set data format.
    tSWIPTest.tTest.ptFormat = _ptDataFormat;

    //Set buffer address.
    vtProtocolBufferPointers.pGeneralBuffer = (void*)_pBuf;

    //Pend wait flag and wait for image type setting.
    tProtocolCtrl.getter->eReadyStatus = RS_READY;
	while(tSWIPTest.tTest.ptCtrl->eTestType == CTT_NONE && tProtocolCtrl.setter->eMode == M_TOUCH_DIAG);
}

eSWIPPacketFormatId_t protocol_swip_GetPacketFormatId(void)
{
    return thisCommonConf->ePacketFormatId;
}

void protocol_swip_InitTouchEventBuffer(void)
{
//		int i; // NOTE : warning����

		thisInfo->iEventPacket_ = 0;

#if defined(SUPPORT_ANDROID)		
		tSWIPAndroidReportPacket.info->touch_cnt = 0;
		protocol_android_SetDevCtlSts();
#endif
		thisInfo->bEnableHandShake = 0;//tProtocolCtrl.setter->bEnableHandShake;		
		thisInfo->bApplyCoordinate = tProtocolCtrl.setter->bApplyCoordinate;
		
//		if(thisInfo->bEnableHandShake && tSWIPEvent.ptPacketInfo->ReportSize == TEST_DEVICE_READ_PACKED)
//		{
//			tSWIPEvent.ptPacketInfo->ReportSize = 0;
//		}
		
		#ifdef MODE_I2C
			protocol_swip_WaitEventInterruptCleared();	
		#endif
	
}
#if (SWIP_QUEUE_MODE)
	tSWIPPacketInfo_t ptPacketInfoQueue[SWIP_QUEUE_SIZE];
#endif

#if defined(SUPPORT_ANDROID)
void protocol_Android_PushTouchEvent(const uSWIPTouchItem_t* _kptItem)
{
		int index = (_kptItem->tItem00.tInfo.b4FingerID-1);

		tSWIPAndroidReportPacket.data[index].event    = _kptItem->tItem00.tInfo.bTouch;

		tSWIPAndroidReportPacket.data[index].track_id = index;//_kptItem->tItem00.tInfo.b4FingerID;
		tSWIPAndroidReportPacket.data[index].x        = _kptItem->tItem00.ucXHigh<<8 | _kptItem->tItem00.ucXLow;
		tSWIPAndroidReportPacket.data[index].y        = _kptItem->tItem00.ucYHigh<<8 | _kptItem->tItem00.ucYLow; 
		tSWIPAndroidReportPacket.data[index].pressure = (_kptItem->tItem00.tInfo.bTouch) ? 100 : _kptItem->tItem00.usStrength;
		tSWIPAndroidReportPacket.data[index].angle    = 0; //Not used
		tSWIPAndroidReportPacket.data[index].width_major = _kptItem->tItem00.ucWidth;
		tSWIPAndroidReportPacket.data[index].width_minor = _kptItem->tItem00.ucWidth;		
		tSWIPAndroidReportPacket.data[index].tool_type= 0; //finger touch : 0

		tSWIPAndroidReportPacket.info->touch_cnt++;
}
#endif

void protocol_swip_PushTouchEvent(const uSWIPTouchItem_t* _kptItem)
{
#if USED_MOBILE_I2C_PROTOCOL
//    int size = 0;
	int index = 0, i = 0;
//	uint16_t BinArray[MAX_TOUCH_] = {0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200};

#if (SWIP_QUEUE_MODE)
	if(sptAlgorithmInfo->bQueueStart == 0)
	{
		sptAlgorithmInfo->bQueueStart = 1;
		if( (sptAlgorithmInfo->QueueRear + 1) % SWIP_QUEUE_SIZE == sptAlgorithmInfo->QueueFront ) // Queue Full Check
		{
			uint8_t CurrFrontIdx, NextFrontIdx;

			if( protocol_swip_CheckEventInterrupt() == YES ){
				CurrFrontIdx = (sptAlgorithmInfo->QueueRear + 1) % SWIP_QUEUE_SIZE;
			}
			else{
				CurrFrontIdx = (sptAlgorithmInfo->QueueRear + 2) % SWIP_QUEUE_SIZE;
			}
			NextFrontIdx = (CurrFrontIdx + 1) % SWIP_QUEUE_SIZE;

			for(index=0; index<MAX_TOUCH_; index++)
			{
				if(ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].event == 0 && ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].track_id > 0)
//				if( ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].Status == 0 && ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].track_id > 0)
				{
					ptPacketInfoQueue[NextFrontIdx].tTouchData[index].tool_type = ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].tool_type;
					ptPacketInfoQueue[NextFrontIdx].tTouchData[index].event = ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].event;
					ptPacketInfoQueue[NextFrontIdx].tTouchData[index].track_id = ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].track_id;
					ptPacketInfoQueue[NextFrontIdx].tTouchData[index].x = ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].x;
					ptPacketInfoQueue[NextFrontIdx].tTouchData[index].y = ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].y;
					ptPacketInfoQueue[NextFrontIdx].tTouchData[index].pressure = ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].pressure;
					ptPacketInfoQueue[NextFrontIdx].tTouchData[index].angle = ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].angle;
					ptPacketInfoQueue[NextFrontIdx].tTouchData[index].width_major = ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].width_major;
					ptPacketInfoQueue[NextFrontIdx].tTouchData[index].width_minor = ptPacketInfoQueue[CurrFrontIdx].tTouchData[index].width_minor;
				}

//				if( ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].Status == 0 && ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].ID > 0)
//				{
//					ptPacketInfoQueue[NextFrontIdx].tTouchInfo[index].Status = ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].Status;
//					ptPacketInfoQueue[NextFrontIdx].tTouchInfo[index].ID 	 = ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].ID;
//					ptPacketInfoQueue[NextFrontIdx].tTouchInfo[index].ucX 	 = ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].ucX;
//					ptPacketInfoQueue[NextFrontIdx].tTouchInfo[index].ucY 	 = ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].ucY;
//				}
			}
			ptPacketInfoQueue[NextFrontIdx].tTouchinfo.touch_cnt = ptPacketInfoQueue[CurrFrontIdx].tTouchinfo.touch_cnt;

			sptAlgorithmInfo->QueueFront++;
			sptAlgorithmInfo->QueueFront = (sptAlgorithmInfo->QueueFront) % SWIP_QUEUE_SIZE;
		}
		memset(&ptPacketInfoQueue[sptAlgorithmInfo->QueueRear], 0x00, sizeof(tSWIPPacketInfo_t));
	}
#endif

	index = (_kptItem->tItem00.tInfo.b4FingerID-1);
//	size = tSWIPEvent.ptEventFormat->ucTouchPacketItemSize;

	if(thisInfo->bEnableHandShake)
	{
		ptDummyPacketInfo.tTouchData[index].tool_type = 0x0;
		ptDummyPacketInfo.tTouchData[index].event = _kptItem->tItem00.tInfo.bTouch;
		ptDummyPacketInfo.tTouchData[index].track_id = _kptItem->tItem00.tInfo.b4FingerID;
		ptDummyPacketInfo.tTouchData[index].x = (_kptItem->tItem00.ucXHigh<<8 | _kptItem->tItem00.ucXLow) * I2C_X_RESOLUTION / DEFAULT_X_RESOLUTION;
		ptDummyPacketInfo.tTouchData[index].y = (_kptItem->tItem00.ucYHigh<<8 | _kptItem->tItem00.ucYLow) * I2C_Y_RESOLUTION / DEFAULT_Y_RESOLUTION;
		ptDummyPacketInfo.tTouchData[index].pressure = _kptItem->tItem00.usStrength;
		ptDummyPacketInfo.tTouchData[index].angle = 0x0;
		ptDummyPacketInfo.tTouchData[index].width_major = 0x0;
		ptDummyPacketInfo.tTouchData[index].width_minor = 0x0;
//		ptDummyPacketInfo.tTouchInfo[index].Status = _kptItem->tItem00.tInfo.bTouch;
//		ptDummyPacketInfo.tTouchInfo[index].ID = _kptItem->tItem00.tInfo.b4FingerID;
//		ptDummyPacketInfo.tTouchInfo[index].ucX = _kptItem->tItem00.ucXHigh<<8 | _kptItem->tItem00.ucXLow;
//		ptDummyPacketInfo.tTouchInfo[index].ucY = _kptItem->tItem00.ucYHigh<<8 | _kptItem->tItem00.ucYLow;
		ptDummyPacketInfo.RowStart = _kptItem->tItem00.ucRowStart;
		ptDummyPacketInfo.ucContactCnt = index;
		thisInfo->iEventPacket_++;//+= size;
		ptDummyPacketInfo.tTouchinfo.touch_cnt++;

		if(thisInfo->bApplyCoordinate)
		{
			for( i=0; i<ptMemConf->iMaxTouch_; i++ )
			{
//				tSWIPEvent.ptPacketInfo->ReportSize = (ptDummyPacketInfo.tTouchInfo[i].Status) \
//				? (tSWIPEvent.ptPacketInfo->ReportSize | BinArray[i]) : (tSWIPEvent.ptPacketInfo->ReportSize & ~BinArray[i]);

				tSWIPEvent.ptPacketInfo->tTouchData[i].tool_type = ptDummyPacketInfo.tTouchData[i].tool_type;
				tSWIPEvent.ptPacketInfo->tTouchData[i].event = ptDummyPacketInfo.tTouchData[i].event;
				tSWIPEvent.ptPacketInfo->tTouchData[i].track_id = ptDummyPacketInfo.tTouchData[i].track_id;
				tSWIPEvent.ptPacketInfo->tTouchData[i].x = ptDummyPacketInfo.tTouchData[i].x;
				tSWIPEvent.ptPacketInfo->tTouchData[i].y = ptDummyPacketInfo.tTouchData[i].y;
				tSWIPEvent.ptPacketInfo->tTouchData[i].pressure = ptDummyPacketInfo.tTouchData[i].pressure;
				tSWIPEvent.ptPacketInfo->tTouchData[i].angle = ptDummyPacketInfo.tTouchData[i].angle;
				tSWIPEvent.ptPacketInfo->tTouchData[i].width_major = ptDummyPacketInfo.tTouchData[i].width_major;
				tSWIPEvent.ptPacketInfo->tTouchData[i].width_minor = ptDummyPacketInfo.tTouchData[i].width_minor;

//				tSWIPEvent.ptPacketInfo->tTouchInfo[i].Status = ptDummyPacketInfo.tTouchInfo[i].Status;
//				tSWIPEvent.ptPacketInfo->tTouchInfo[i].ID     = ptDummyPacketInfo.tTouchInfo[i].ID ;
//				tSWIPEvent.ptPacketInfo->tTouchInfo[i].ucX    = ptDummyPacketInfo.tTouchInfo[i].ucX;
//				tSWIPEvent.ptPacketInfo->tTouchInfo[i].ucY    = ptDummyPacketInfo.tTouchInfo[i].ucY;
			}
			tSWIPEvent.ptPacketInfo->tTouchinfo.touch_cnt = ptDummyPacketInfo.tTouchinfo.touch_cnt;
			tSWIPEvent.ptPacketInfo->RowStart     = ptDummyPacketInfo.RowStart;
			tSWIPEvent.ptPacketInfo->ucContactCnt = ptDummyPacketInfo.ucContactCnt;
		}
	}
	else
	{
#if (SWIP_QUEUE_MODE)
		tSWIPEvent.ptPacketInfo->tTouchinfo.touch_cnt = ptDummyPacketInfo.tTouchinfo.touch_cnt;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchData[index].tool_type = 0x0;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchData[index].event = _kptItem->tItem00.tInfo.bTouch;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchData[index].track_id = _kptItem->tItem00.tInfo.b4FingerID;

		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchData[index].x = (_kptItem->tItem00.ucXHigh<<8 | _kptItem->tItem00.ucXLow) * I2C_X_RESOLUTION / DEFAULT_X_RESOLUTION;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchData[index].y = (_kptItem->tItem00.ucYHigh<<8 | _kptItem->tItem00.ucYLow) * I2C_Y_RESOLUTION / DEFAULT_Y_RESOLUTION;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchData[index].pressure = _kptItem->tItem00.usStrength;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchData[index].angle = 0x0;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchData[index].width_major = 0x0;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchData[index].width_minor = 0x0;

//		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchInfo[index].Status = _kptItem->tItem00.tInfo.bTouch;
//		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchInfo[index].ID 	= _kptItem->tItem00.tInfo.b4FingerID;
//		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchInfo[index].ucX 	= _kptItem->tItem00.ucXHigh<<8 | _kptItem->tItem00.ucXLow;
//		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchInfo[index].ucY 	= _kptItem->tItem00.ucYHigh<<8 | _kptItem->tItem00.ucYLow;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].RowStart = _kptItem->tItem00.ucRowStart;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].ucContactCnt = index;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchinfo.touch_cnt++;
#else
		tSWIPEvent.ptPacketInfo->tTouchInfo[index].Status 	= _kptItem->tItem00.tInfo.bTouch;
		tSWIPEvent.ptPacketInfo->tTouchInfo[index].ID 		= _kptItem->tItem00.tInfo.b4FingerID;
		tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucX 		= _kptItem->tItem00.ucXHigh<<8 | _kptItem->tItem00.ucXLow;
		tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucY 		= _kptItem->tItem00.ucYHigh<<8 | _kptItem->tItem00.ucYLow;
		tSWIPEvent.ptPacketInfo->RowStart 					= _kptItem->tItem00.ucRowStart;
		tSWIPEvent.ptPacketInfo->ucContactCnt 				= index;
		thisInfo->iEventPacket_ += size;
#endif
	}
#else /* USED_MOBILE_I2C_PROTOCOL */
    int size = 0;
	int index = 0, i = 0;		
	uint16_t BinArray[MAX_TOUCH_] = {0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200};

	
#if (SWIP_QUEUE_MODE)
	if(sptAlgorithmInfo->bQueueStart == 0)
	{
		sptAlgorithmInfo->bQueueStart = 1;
		if( (sptAlgorithmInfo->QueueRear + 1) % SWIP_QUEUE_SIZE == sptAlgorithmInfo->QueueFront ) // Queue Full Check
		{	
			uint8_t CurrFrontIdx, NextFrontIdx;

			if( protocol_swip_CheckEventInterrupt() == YES ){
				CurrFrontIdx = (sptAlgorithmInfo->QueueRear + 1) % SWIP_QUEUE_SIZE;
			}
			else{
				CurrFrontIdx = (sptAlgorithmInfo->QueueRear + 2) % SWIP_QUEUE_SIZE;
			}
			NextFrontIdx = (CurrFrontIdx + 1) % SWIP_QUEUE_SIZE;
			
			for(index=0; index<MAX_TOUCH_; index++)				
			{
				if( ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].Status == 0 && ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].ID > 0)
				{
					ptPacketInfoQueue[NextFrontIdx].tTouchInfo[index].Status = ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].Status; 
					ptPacketInfoQueue[NextFrontIdx].tTouchInfo[index].ID 	 = ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].ID; 	 
					ptPacketInfoQueue[NextFrontIdx].tTouchInfo[index].ucX 	 = ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].ucX; 	 
					ptPacketInfoQueue[NextFrontIdx].tTouchInfo[index].ucY 	 = ptPacketInfoQueue[CurrFrontIdx].tTouchInfo[index].ucY;	 
				}
			}
			
			sptAlgorithmInfo->QueueFront++;
			sptAlgorithmInfo->QueueFront = (sptAlgorithmInfo->QueueFront) % SWIP_QUEUE_SIZE;
		}
		memset(&ptPacketInfoQueue[sptAlgorithmInfo->QueueRear], 0x00, sizeof(tSWIPPacketInfo_t));
	}
#endif
	
	index = (_kptItem->tItem00.tInfo.b4FingerID-1);
	size = tSWIPEvent.ptEventFormat->ucTouchPacketItemSize;
	
	if(thisInfo->bEnableHandShake)
	{
#if USED_SHARP_SPECIFIC_PROTOCOL
		ptDummyPacketInfo.tTouchInfo[index].Status = ((_kptItem->tItem00.tInfo.b6Type << 1) | (_kptItem->tItem00.tInfo.b1Status & 0x01)) & 0xff;
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
		ptDummyPacketInfo.tTouchInfo[index].Status = _kptItem->tItem00.tInfo.bTouch;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
		ptDummyPacketInfo.tTouchInfo[index].ID = _kptItem->tItem00.tInfo.b4FingerID;
		ptDummyPacketInfo.tTouchInfo[index].ucX = _kptItem->tItem00.ucXHigh<<8 | _kptItem->tItem00.ucXLow;
		ptDummyPacketInfo.tTouchInfo[index].ucY = _kptItem->tItem00.ucYHigh<<8 | _kptItem->tItem00.ucYLow;
		ptDummyPacketInfo.RowStart = _kptItem->tItem00.ucRowStart;
		ptDummyPacketInfo.ucContactCnt = index;
		thisInfo->iEventPacket_ += size;

		if(thisInfo->bApplyCoordinate)
		{
			for( i=0; i<MAX_TOUCH_; i++ )
			{
				tSWIPEvent.ptPacketInfo->ReportSize = (ptDummyPacketInfo.tTouchInfo[i].Status) \
				? (tSWIPEvent.ptPacketInfo->ReportSize | BinArray[i]) : (tSWIPEvent.ptPacketInfo->ReportSize & ~BinArray[i]);
				
				tSWIPEvent.ptPacketInfo->tTouchInfo[i].Status = ptDummyPacketInfo.tTouchInfo[i].Status;
				tSWIPEvent.ptPacketInfo->tTouchInfo[i].ID     = ptDummyPacketInfo.tTouchInfo[i].ID ;
				tSWIPEvent.ptPacketInfo->tTouchInfo[i].ucX    = ptDummyPacketInfo.tTouchInfo[i].ucX;
				tSWIPEvent.ptPacketInfo->tTouchInfo[i].ucY    = ptDummyPacketInfo.tTouchInfo[i].ucY;
			}
			tSWIPEvent.ptPacketInfo->RowStart     = ptDummyPacketInfo.RowStart;
			tSWIPEvent.ptPacketInfo->ucContactCnt = ptDummyPacketInfo.ucContactCnt;					
		}
	}
	else
	{	
#if (SWIP_QUEUE_MODE)
#if USED_SHARP_SPECIFIC_PROTOCOL
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchInfo[index].Status = ((_kptItem->tItem00.tInfo.b6Type << 1) | (_kptItem->tItem00.tInfo.b1Status & 0x01)) & 0xff;
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchInfo[index].Status = _kptItem->tItem00.tInfo.bTouch;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchInfo[index].ID 	= _kptItem->tItem00.tInfo.b4FingerID;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchInfo[index].ucX 	= _kptItem->tItem00.ucXHigh<<8 | _kptItem->tItem00.ucXLow;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].tTouchInfo[index].ucY 	= _kptItem->tItem00.ucYHigh<<8 | _kptItem->tItem00.ucYLow;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].RowStart 				= _kptItem->tItem00.ucRowStart;
		ptPacketInfoQueue[sptAlgorithmInfo->QueueRear].ucContactCnt 			= index;
#else
		tSWIPEvent.ptPacketInfo->tTouchInfo[index].Status 	= _kptItem->tItem00.tInfo.bTouch;
		tSWIPEvent.ptPacketInfo->tTouchInfo[index].ID 		= _kptItem->tItem00.tInfo.b4FingerID;
		tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucX 		= _kptItem->tItem00.ucXHigh<<8 | _kptItem->tItem00.ucXLow;
		tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucY 		= _kptItem->tItem00.ucYHigh<<8 | _kptItem->tItem00.ucYLow;
		tSWIPEvent.ptPacketInfo->RowStart 					= _kptItem->tItem00.ucRowStart;
		tSWIPEvent.ptPacketInfo->ucContactCnt 				= index;
		thisInfo->iEventPacket_ += size;
#endif
	}
#endif /* USED_MOBILE_I2C_PROTOCOL */
}

void protocol_swip_SendTouchEvent(void)
{
#if USED_MOBILE_I2C_PROTOCOL
	int index = 0;

	if(thisInfo->bEnableHandShake)
	{
		if(!thisInfo->bApplyCoordinate) return;

		if(thisInfo->iEventPacket_ )
		{
//			tSWIPEvent.ptPacketInfo->ReportID = 0x01;
			tProtocolCtrl.setter->bApplyCoordinate = NO;
			protocol_swip_PendEventInterrupt();
		}
		else
		{
			tSWIPEvent.ptPacketInfo->ucContactCnt = 0;
		}
	}
	else
	{
#if (SWIP_QUEUE_MODE)
		if( sptAlgorithmInfo->QueueFront != sptAlgorithmInfo->QueueRear && protocol_swip_CheckEventInterrupt() == YES ) // Not Queue Empty
		{
			for(index=0; index<MAX_TOUCH_; index++)
			{
				tSWIPEvent.ptPacketInfo->tTouchData[index].tool_type = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].tool_type;
				tSWIPEvent.ptPacketInfo->tTouchData[index].event = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].event;
				tSWIPEvent.ptPacketInfo->tTouchData[index].track_id = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].track_id;
				tSWIPEvent.ptPacketInfo->tTouchData[index].x = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].x;
				tSWIPEvent.ptPacketInfo->tTouchData[index].y = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].y;
				tSWIPEvent.ptPacketInfo->tTouchData[index].pressure = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].pressure;
				tSWIPEvent.ptPacketInfo->tTouchData[index].angle = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].angle;
				tSWIPEvent.ptPacketInfo->tTouchData[index].width_major = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].width_major;
				tSWIPEvent.ptPacketInfo->tTouchData[index].width_minor = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].width_minor;

//				tSWIPEvent.ptPacketInfo->tTouchInfo[index].Status 	= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].Status;
//				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ID 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ID;
//				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucX 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ucX;
//				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucY 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ucY;
			}
			tSWIPEvent.ptPacketInfo->RowStart = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].RowStart;
			tSWIPEvent.ptPacketInfo->ucContactCnt = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].ucContactCnt;
//			tSWIPEvent.ptPacketInfo->ReportID 	= 0x01;
//			tSWIPEvent.ptPacketInfo->ReportSize = TEST_DEVICE_READ_PACKED;
			tSWIPEvent.ptPacketInfo->tTouchinfo.touch_cnt = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchinfo.touch_cnt;
			protocol_swip_PendEventInterrupt();
		}
#else
		if( thisInfo->iEventPacket_ )
		{
			tSWIPEvent.ptPacketInfo->ReportID = 0x01;
			tSWIPEvent.ptPacketInfo->ReportSize = TEST_DEVICE_READ_PACKED;
			protocol_swip_PendEventInterrupt();
		}
		else
		{
			tSWIPEvent.ptPacketInfo->ucContactCnt = 0;
		}
#endif
	}
#else /* USED_MOBILE_I2C_PROTOCOL */
	int index = 0;

	if(thisInfo->bEnableHandShake)
	{
		if(!thisInfo->bApplyCoordinate) return;

		if(thisInfo->iEventPacket_ )
		{
			tSWIPEvent.ptPacketInfo->ReportID = 0x01;
			tProtocolCtrl.setter->bApplyCoordinate = NO;
			protocol_swip_PendEventInterrupt();
		}
		else
		{
			tSWIPEvent.ptPacketInfo->ucContactCnt = 0;
		}
	}
	else
	{
#if (SWIP_QUEUE_MODE)
		if( sptAlgorithmInfo->QueueFront != sptAlgorithmInfo->QueueRear && protocol_swip_CheckEventInterrupt() == YES ) // Not Queue Empty
		{
			for(index=0; index<MAX_TOUCH_; index++)
			{
				tSWIPEvent.ptPacketInfo->tTouchInfo[index].Status 	= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].Status;
				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ID 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ID;
				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucX 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ucX;
				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucY 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ucY;
				tSWIPEvent.ptPacketInfo->RowStart 					= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].RowStart;
				tSWIPEvent.ptPacketInfo->ucContactCnt 				= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].ucContactCnt;
			}
			tSWIPEvent.ptPacketInfo->ReportID 	= 0x01;
			tSWIPEvent.ptPacketInfo->ReportSize = TEST_DEVICE_READ_PACKED;
			protocol_swip_PendEventInterrupt();
		}
#else
		if( thisInfo->iEventPacket_ )
		{
			tSWIPEvent.ptPacketInfo->ReportID = 0x01;
			tSWIPEvent.ptPacketInfo->ReportSize = TEST_DEVICE_READ_PACKED;
			protocol_swip_PendEventInterrupt();
		}
		else
		{
			tSWIPEvent.ptPacketInfo->ucContactCnt = 0;
		}
#endif
	}
#endif /* USED_MOBILE_I2C_PROTOCOL */
}

void protocol_swip_SendPenEvent(void)
{
#if USED_MOBILE_I2C_PROTOCOL
    int i = 0, nFindIdx = 0, index;
	tSWIPPacketInfo_t tPenTouch = { 0, };
//	uint16_t BinArray[MAX_TOUCH_] = {0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200};


	if(thisInfo->bEnableHandShake)
	{
		if(!thisInfo->bApplyCoordinate) return;

		if(thisInfo->iEventPacket_ )
		{
//			tSWIPEvent.ptPacketInfo->ReportID = 0x01;
			tProtocolCtrl.setter->bApplyCoordinate = NO;

			tPenTouch.tTouchData[index].tool_type = tSWIPEvent.ptPacketInfo->tTouchData[index].tool_type;
			tPenTouch.tTouchData[index].event = tSWIPEvent.ptPacketInfo->tTouchData[index].event;
			tPenTouch.tTouchData[index].track_id = tSWIPEvent.ptPacketInfo->tTouchData[index].track_id;
			tPenTouch.tTouchData[index].x = tSWIPEvent.ptPacketInfo->tTouchData[index].x;
			tPenTouch.tTouchData[index].y = tSWIPEvent.ptPacketInfo->tTouchData[index].y;
			tPenTouch.tTouchData[index].pressure = tSWIPEvent.ptPacketInfo->tTouchData[index].pressure;
			tPenTouch.tTouchData[index].angle = tSWIPEvent.ptPacketInfo->tTouchData[index].angle;
			tPenTouch.tTouchData[index].width_major = tSWIPEvent.ptPacketInfo->tTouchData[index].width_major;
			tPenTouch.tTouchData[index].width_minor = tSWIPEvent.ptPacketInfo->tTouchData[index].width_minor;
//			tPenTouch.tTouchInfo[0].Status = tSWIPEvent.ptPacketInfo->tTouchInfo[0].Status;
//			tPenTouch.tTouchInfo[0].ID     = tSWIPEvent.ptPacketInfo->tTouchInfo[0].ID;
//			tPenTouch.tTouchInfo[0].ucX    = tSWIPEvent.ptPacketInfo->tTouchInfo[0].ucX;
//			tPenTouch.tTouchInfo[0].ucY    = tSWIPEvent.ptPacketInfo->tTouchInfo[0].ucY;

			for( i=0; i<ptMemConf->iMaxTouch_; i++ )
			{
				if(tSWIPEvent.ptPacketInfo->tTouchData[i].event == 0)
//				if(tSWIPEvent.ptPacketInfo->tTouchInfo[i].Status == 0)
				{
					nFindIdx = i;
				}

//				tSWIPEvent.ptPacketInfo->ReportSize = (tSWIPEvent.ptPacketInfo->ReportSize & ~BinArray[i]);
				tSWIPEvent.ptPacketInfo->tTouchData[i].event = 0;
//				tSWIPEvent.ptPacketInfo->tTouchInfo[i].Status = 0;
			}

			tSWIPEvent.ptPacketInfo->tTouchData[nFindIdx].tool_type = tPenTouch.tTouchData[0].tool_type;
			tSWIPEvent.ptPacketInfo->tTouchData[nFindIdx].event = tPenTouch.tTouchData[0].event;
			tSWIPEvent.ptPacketInfo->tTouchData[nFindIdx].track_id = tPenTouch.tTouchData[0].track_id;
			tSWIPEvent.ptPacketInfo->tTouchData[nFindIdx].x = tPenTouch.tTouchData[0].x;
			tSWIPEvent.ptPacketInfo->tTouchData[nFindIdx].y = tPenTouch.tTouchData[0].y;
			tSWIPEvent.ptPacketInfo->tTouchData[nFindIdx].pressure = tPenTouch.tTouchData[0].pressure;
			tSWIPEvent.ptPacketInfo->tTouchData[nFindIdx].angle = tPenTouch.tTouchData[0].angle;
			tSWIPEvent.ptPacketInfo->tTouchData[nFindIdx].width_major = tPenTouch.tTouchData[0].width_major;
			tSWIPEvent.ptPacketInfo->tTouchData[nFindIdx].width_minor = tPenTouch.tTouchData[0].width_minor;

//			tSWIPEvent.ptPacketInfo->tTouchInfo[nFindIdx].Status = tPenTouch.tTouchInfo[0].Status;
//			tSWIPEvent.ptPacketInfo->tTouchInfo[nFindIdx].ID     = tPenTouch.tTouchInfo[0].ID ;
//			tSWIPEvent.ptPacketInfo->tTouchInfo[nFindIdx].ucX    = tPenTouch.tTouchInfo[0].ucX;
//			tSWIPEvent.ptPacketInfo->tTouchInfo[nFindIdx].ucY    = tPenTouch.tTouchInfo[0].ucY;


			protocol_swip_PendEventInterrupt();
		}
		else
		{
			tSWIPEvent.ptPacketInfo->ucContactCnt = 0;
		}
	}
	else
	{
#if (SWIP_QUEUE_MODE)
		if( sptAlgorithmInfo->QueueFront != sptAlgorithmInfo->QueueRear && protocol_swip_CheckEventInterrupt() == YES ) // Not Queue Empty
		{
			for(index=0; index<MAX_TOUCH_; index++)
			{
				tSWIPEvent.ptPacketInfo->tTouchData[index].tool_type = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].tool_type;
				tSWIPEvent.ptPacketInfo->tTouchData[index].event = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].event;
				tSWIPEvent.ptPacketInfo->tTouchData[index].track_id = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].track_id;
				tSWIPEvent.ptPacketInfo->tTouchData[index].x = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].x;
				tSWIPEvent.ptPacketInfo->tTouchData[index].y = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].y;
				tSWIPEvent.ptPacketInfo->tTouchData[index].pressure = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].pressure;
				tSWIPEvent.ptPacketInfo->tTouchData[index].angle = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].angle;
				tSWIPEvent.ptPacketInfo->tTouchData[index].width_major = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].width_major;
				tSWIPEvent.ptPacketInfo->tTouchData[index].width_minor = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchData[index].width_minor;

//				tSWIPEvent.ptPacketInfo->tTouchInfo[index].Status 	= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].Status;
//				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ID 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ID;
//				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucX 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ucX;
//				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucY 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ucY;
			}

			tSWIPEvent.ptPacketInfo->RowStart = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].RowStart;
			tSWIPEvent.ptPacketInfo->ucContactCnt = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].ucContactCnt;
//			tSWIPEvent.ptPacketInfo->ReportID 	= 0x01;
//			tSWIPEvent.ptPacketInfo->ReportSize = TEST_DEVICE_READ_PACKED;
			tSWIPEvent.ptPacketInfo->tTouchinfo.touch_cnt = ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchinfo.touch_cnt;

			protocol_swip_PendEventInterrupt();
		}
#else
		if( thisInfo->iEventPacket_ )
		{
			tSWIPEvent.ptPacketInfo->ReportID = 0x01;
			tSWIPEvent.ptPacketInfo->ReportSize = TEST_DEVICE_READ_PACKED;
			protocol_swip_PendEventInterrupt();
		}
		else
		{
			tSWIPEvent.ptPacketInfo->ucContactCnt = 0;
		}
#endif
	}
#else /* USED_MOBILE_I2C_PROTOCOL */
    int i = 0, nFindIdx = 0, index;
	tSWIPPacketInfo_t tPenTouch = { 0, };
	uint16_t BinArray[MAX_TOUCH_] = {0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200};


	if(thisInfo->bEnableHandShake)
	{
		if(!thisInfo->bApplyCoordinate) return;

		if(thisInfo->iEventPacket_ )
		{
			tSWIPEvent.ptPacketInfo->ReportID = 0x01;
			tProtocolCtrl.setter->bApplyCoordinate = NO;

			tPenTouch.tTouchInfo[0].Status = tSWIPEvent.ptPacketInfo->tTouchInfo[0].Status;
			tPenTouch.tTouchInfo[0].ID     = tSWIPEvent.ptPacketInfo->tTouchInfo[0].ID;
			tPenTouch.tTouchInfo[0].ucX    = tSWIPEvent.ptPacketInfo->tTouchInfo[0].ucX;
			tPenTouch.tTouchInfo[0].ucY    = tSWIPEvent.ptPacketInfo->tTouchInfo[0].ucY;

			for( i=0; i<MAX_TOUCH_; i++ )
			{
				if(tSWIPEvent.ptPacketInfo->tTouchInfo[i].Status == 0)
				{
					nFindIdx = i;
				}
				
				tSWIPEvent.ptPacketInfo->ReportSize = (tSWIPEvent.ptPacketInfo->ReportSize & ~BinArray[i]);
				tSWIPEvent.ptPacketInfo->tTouchInfo[i].Status = 0;
			}

			tSWIPEvent.ptPacketInfo->tTouchInfo[nFindIdx].Status = tPenTouch.tTouchInfo[0].Status;
			tSWIPEvent.ptPacketInfo->tTouchInfo[nFindIdx].ID     = tPenTouch.tTouchInfo[0].ID ;
			tSWIPEvent.ptPacketInfo->tTouchInfo[nFindIdx].ucX    = tPenTouch.tTouchInfo[0].ucX;
			tSWIPEvent.ptPacketInfo->tTouchInfo[nFindIdx].ucY    = tPenTouch.tTouchInfo[0].ucY;


			protocol_swip_PendEventInterrupt();
		}
		else
		{
			tSWIPEvent.ptPacketInfo->ucContactCnt = 0;
		}
	}
	else
	{
#if (SWIP_QUEUE_MODE)
		if( sptAlgorithmInfo->QueueFront != sptAlgorithmInfo->QueueRear && protocol_swip_CheckEventInterrupt() == YES ) // Not Queue Empty
		{
			for(index=0; index<MAX_TOUCH_; index++)
			{
				tSWIPEvent.ptPacketInfo->tTouchInfo[index].Status 	= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].Status;
				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ID 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ID;
				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucX 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ucX;
				tSWIPEvent.ptPacketInfo->tTouchInfo[index].ucY 		= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].tTouchInfo[index].ucY;
				tSWIPEvent.ptPacketInfo->RowStart 					= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].RowStart;
				tSWIPEvent.ptPacketInfo->ucContactCnt 				= ptPacketInfoQueue[sptAlgorithmInfo->QueueFront].ucContactCnt;
			}
			tSWIPEvent.ptPacketInfo->ReportID 	= 0x01;
			tSWIPEvent.ptPacketInfo->ReportSize = TEST_DEVICE_READ_PACKED;
			protocol_swip_PendEventInterrupt();
		}
#else			
		if( thisInfo->iEventPacket_ )
		{
			tSWIPEvent.ptPacketInfo->ReportID = 0x01;
			tSWIPEvent.ptPacketInfo->ReportSize = TEST_DEVICE_READ_PACKED;
			protocol_swip_PendEventInterrupt();
		}
		else
		{
			tSWIPEvent.ptPacketInfo->ucContactCnt = 0;
		}
#endif
	}
#endif /* USED_MOBILE_I2C_PROTOCOL */
}

bool_t protocol_swip_GetGNDNoiseHandlingStatus(void)
{
    return tSWIPSpecialAction.ptControlForTuning->bGNDNoiseStatus;
}

void protocol_swip_SetGNDNoiseHandlingStatus(bool_t _bStatus)
{
	tSWIPSpecialAction.ptControlForTuning->bGNDNoiseStatus = _bStatus;
}

bool_t protocol_swip_GetLCDNoiseHandlingStatus(void)
{
    return tSWIPSpecialAction.ptControlForTuning->bLCDNoiseStatus;
}

void protocol_swip_SetLCDNoiseHandlingStatus(bool_t _bStatus)
{
	tSWIPSpecialAction.ptControlForTuning->bLCDNoiseStatus = _bStatus;
}

uint8_t protocol_swip_GetOscVal(void)
{
    return tSWIPSpecialAction.ptControlForTuning->ucOscVal;
}

void protocol_swip_SetOscVal(uint8_t oscval)
{
	tSWIPSpecialAction.ptControlForTuning->ucOscVal = oscval;
}

bool_t protocol_swip_GetReadModuleConfigStatus(void)
{
    return tSWIPSpecialAction.ptControlForTuning->bReadModuleConfig;
}

void protocol_swip_SetReadModuleConfigStatus(bool_t _bStatus)
{
	tSWIPSpecialAction.ptControlForTuning->bReadModuleConfig = _bStatus;
}


uint8_t* protocol_swip_GetMappedPointer(uint16_t _addr)
{
	int i;
	uint8_t maddr = MSB(_addr), laddr = LSB(_addr);

	if(_addr >= SWIP_REG_ADDR_RESERVED)
		return (uint8_t*)0;
	if(maddr < GET_ARRAY_(vtMRmiMap))
	{
		const tSWIPSubsetInfo_t* info = vtMRmiMap[maddr];
		for(i = info->iSize; i--;)
		{
			int start_addr = info->vucStartLAddr[i];
			if(laddr >= start_addr)
			{
				return info->ppucData[i] + laddr - start_addr;
			}
		}
	}
	else //16K buffers.
	{
		for(i = tSWIPBufferInfo.iSize; i--;)
		{
			int start_addr = tSWIPBufferInfo.vusStartAddr[i];

			if(_addr >= start_addr)
			{
				return tSWIPBufferInfo.ppucBuffer[i] + _addr - start_addr;
			}
		}
	}
	return (uint8_t*)NULL;
}

void protocol_swip_ClearInterrupt(uint16_t _addr)
{
	uint16_t SWIP_REG_ADDR;
	
	if(thisInfo->eEventTriggerType == ETT_REGISTER)
	{
		SWIP_REG_ADDR = SWIP_REG_ADDR_EVENT_PACKET_INFO;
	}
	else
	{
		SWIP_REG_ADDR = SWIP_REG_ADDR_EVENT_PACKET_CONTENT;
	}

    if( _addr == SWIP_REG_ADDR_CTRL_GETTER + offsetof(tProtocolGetter_t, eReadyStatus) )
    {
        if( tProtocolCtrl.getter->eReadyStatus != RS_NONE )
            tProtocolCtrl.getter->eReadyStatus = RS_NONE;
    }
    //Touch packet�� ������ data�� �о ��,
    else if( _addr == SWIP_REG_ADDR + TEST_DEVICE_READ_PACKED - 1 )
    {
#if (SWIP_QUEUE_MODE)
		if(sptAlgorithmInfo->QueueFront != sptAlgorithmInfo->QueueRear) // Not Queue Empty
		{
			sptAlgorithmInfo->QueueFront++;
			sptAlgorithmInfo->QueueFront = (sptAlgorithmInfo->QueueFront) % SWIP_QUEUE_SIZE;
		}
#endif
        protocol_swip_ClearEventInterrupt();
    }

#if defined(SUPPORT_ANDROID)
		else if( _addr == SWIP_REG_ADDR_ANDROID_PACKET_DATA + 12)
		{
			protocol_swip_ClearEventInterrupt();
		}
#endif		
}
