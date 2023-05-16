/******************************************************************************************************
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


#include "core_def.h"
#include "protocol_log.h"
#include "protocol_swip.h"
#include "protocol_conf.h"
#include "i2c.h" // NOTE : warning제거
#include "crc.h"
//#include "sflash_dfup.h"
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
static tSWIPEventFormat_t tSWIPEventFormat;
static tSWIPEvent_t tSWIPEvent  =
{
	.ptEventFormat = &tSWIPEventFormat,
    //vtTouchItem은 malloc으로 공간 잡아줌.
    //Packet은 INTR 생성 후 가져갈 때 까지 다른 로직을 수행하므로 scope에 제한받지 않는 dedicated buffer 활용해야 하기 때문임.
};

tSWIPPacketInfo_t ptDummyPacketInfo = 
{
	.ReportSize = 0x0000,
	.ReportID   = 0x01,
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

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
tSWIPPTInspectionInfo_t ktSWIPPTInspectionGetInfo;
tSWIPPTInspectionInfo_t tSWIPPTInspectionSetInfo;

static tSWIPPTInspection_t tSWIPPTInspection  =
{
	.ptGetInfo = &(ktSWIPPTInspectionGetInfo),
	.ptSetInfo = &(tSWIPPTInspectionSetInfo),
};

#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

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
	LSB(SWIP_REG_ADDR_EVENT_FORMAT),
	LSB(SWIP_REG_ADDR_EVENT_PACKET_INFO),
	LSB(SWIP_REG_ADDR_EVENT_PACKET_CONTENT)
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

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
static uint8_t SWIP_REG_ADDR_PTINSPECTION_LOWER_ADDR[]  =
{
	LSB(SWIP_REG_ADDR_PTINSPECTION_GET_INFO),
	LSB(SWIP_REG_ADDR_PTINSPECTION_SET_INFO),
};
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

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

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
static tSWIPSubsetInfo_t ktSubsetPTInspection  =
{
	.ppucData = (uint8_t**)&tSWIPPTInspection,
	.vucStartLAddr = SWIP_REG_ADDR_PTINSPECTION_LOWER_ADDR,
	.iSize = sizeof(tSWIPPTInspection)/sizeof(void*)
};
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

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

static tSWIPSubsetInfo_t* vtMRmiMap[]  =
{
    [MSB(SWIP_REG_ADDR_INFO)          ] = &(ktSubsetInfo),
    [MSB(SWIP_REG_ADDR_EVENT)         ] = &(ktSubsetEvent),
    //[0x05] = NULL,
    [MSB(SWIP_REG_ADDR_CTRL)          ] = &(ktSubsetCtrl),
    //[0x07] = NULL,
    [MSB(SWIP_REG_ADDR_PARAMETER)     ] = &(ktSubsetParam),
    //[0x09] = NULL,
    [MSB(SWIP_REG_ADDR_TEST)          ] = &(ktSubsetTest),
#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	[MSB(SWIP_REG_ADDR_PTINSPECTION)  ] = &(ktSubsetPTInspection),
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
    [MSB(SWIP_REG_ADDR_IMAGE)         ] = &(ktSubsetImage),
    //[0x0D] = NULL,
    //[0x0E] = NULL,
    //[0x0F] = NULL,
    //[0x10] = NULL,
    [MSB(SWIP_REG_ADDR_LOG)           ] = &(ktSubsetLog),
    [MSB(SWIP_REG_ADDR_SPECIAL_ACTION)] = &(ktSubsetSpecialAction),
    [MSB(SWIP_REG_ADDR_FLASH_IAP_CTRL)] = NULL//&(ktSubsetIAP),
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

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

bool_t protocol_swip_GetLocalIdxFixedEn(void)
{
   return tProtocolCtrl.setter->LocalIdxFixedEn;
}

bool_t protocol_swip_GetLocalIdx(void)
{
   return tProtocolCtrl.setter->LocalIdx;
}

bool_t protocol_swip_GetEnableBulkLog(void)
{
	return tProtocolCtrl.setter->bEnableBulkLog;
}

void protocol_swip_SetEnableBulkLog(bool_t _bVal)
{
	tProtocolCtrl.setter->bEnableBulkLog = _bVal;
}

bool_t protocol_swip_GetDFUP_Ready(void)
{
	return tProtocolCtrl.setter->bDFUP_Ready;
}

void protocol_swip_SetDFUP_Ready(bool_t _bVal)
{
	tProtocolCtrl.setter->bDFUP_Ready = _bVal;
}

void protocol_swip_PendReadyStatus(void)
{
    tProtocolCtrl.getter->eReadyStatus = RS_READY;
    while( tProtocolCtrl.getter->eReadyStatus == RS_READY );
}

// Protocol for Test Mode
uint8_t protocol_swip_GetABSAvrCount(void)
{
	return tSWIPTest.tTest.ptCtrl->ucABSAvrCount;
}

uint8_t protocol_swip_GetDCABSAvrCount(void)
{
	return tSWIPTest.tTest.ptCtrl->ucDCABSAvrCount;
}

uint8_t protocol_swip_GetOpenAvrCount(void)
{
	return tSWIPTest.tTest.ptCtrl->ucOpenAvrCount;
}

uint8_t protocol_swip_GetShortAvrCount(void)
{
	return tSWIPTest.tTest.ptCtrl->ucShortAvrCount;
}

uint8_t protocol_swip_GetJitterAvrCount(void)
{
	return tSWIPTest.tTest.ptCtrl->ucJitterAvrCount;
}

uint8_t protocol_swip_GetJitterCheckCount(void)
{
	return tSWIPTest.tTest.ptCtrl->ucJitterCheckCount;
}

eSWIPTestType_t protocol_swip_GetTestType(void)
{
    return tSWIPTest.tTest.ptCtrl->eTestType;
}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
uint8_t* protocol_swip_GetPTInspectionSetBufPrt(void)
{
	return (uint8_t *)&tSWIPPTInspectionSetInfo.usCounterValue;
}

void protocol_swip_UpdatePTInspectionGetInfo(void)
{
	FLITF_TPInspectionInfoCodeFlashRead((uint8_t *)&ktSWIPPTInspectionGetInfo.usCounterValue);
}
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

void Hal_ClearIntr(void) 
{
  if(/*CheckI2CReady() ||*/ !protocol_swip_GetEventIntrType()) return;
	
	GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_HIGH);
}

bool_t Hal_GetIntr(void)
{
 
 if(/*CheckI2CReady()||*/!protocol_swip_GetEventIntrType()) return 0;
	
	if(IS_GPIO_PIN(_GPIO_TP_INTR) == GPIO_DATA_LOW)
	{
		GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_HIGH);
	}

	return 0;
}
void Hal_PendIntr(void)
{
  
  if(/*CheckI2CReady() ||*/ !protocol_swip_GetEventIntrType()) return;
	GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_LOW);
}

void protocol_swip_PendEventInterrupt(void)
{
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
        if(IS_GPIO_PIN(_GPIO_TP_INTR) == GPIO_DATA_HIGH )	return YES;
		else									return NO;
//        break; // NOTE : warning제거
    case ETT_REGISTER:
        if(tProtocolCtrl.getter->bEventReady == NO) 	return YES;
		else											return NO;
//        break; // NOTE : warning제거
    default:
    	break;
    }

    return NO; // NOTE : warning제거
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

extern  uint8_t g_bCallReadyStatus;

void protocol_swip_PendTestResult(const tSWIPTestDataFmt_t* _ptDataFormat, const void* _pBuf)
{
    tSWIPTest.tTest.ptCtrl->eTestType = CTT_NONE;
    //Set data format.
    tSWIPTest.tTest.ptFormat = _ptDataFormat;

    //Set buffer address.
    vtProtocolBufferPointers.pGeneralBuffer = (void*)_pBuf;

#ifdef MODE_I2C
	// 2021.12.06
	g_bCallReadyStatus = TRUE;
#endif

    //Pend wait flag and wait for image type setting.
    tProtocolCtrl.getter->eReadyStatus = RS_READY;
    while( tSWIPTest.tTest.ptCtrl->eTestType == CTT_NONE
            && tProtocolCtrl.setter->eMode == M_TOUCH_DIAG )
        ;
}

eSWIPPacketFormatId_t protocol_swip_GetPacketFormatId(void)
{
    return thisCommonConf->ePacketFormatId;
}

void protocol_swip_InitTouchEventBuffer(void)
{
	thisInfo->iEventPacket_ = 0;
#ifdef MODE_I2C
	protocol_swip_WaitEventInterruptCleared();	
#endif
}


uint8_t* protocol_swip_GetMappedPointer(uint16_t _addr)
{
    int i;
    uint8_t maddr = MSB(_addr), laddr = LSB(_addr);
    //TODO: remove it! 임시로 기존 프로토콜 사용하기 위해서 작업해 두었습니다.
    if( _addr >= SWIP_REG_ADDR_RESERVED )
    {
        return (uint8_t*)0;
    }

    if( maddr < GET_ARRAY_(vtMRmiMap) )
    {
		const tSWIPSubsetInfo_t* info = vtMRmiMap[maddr];
		if(info != NULL)
		{
			for( i=info->iSize; i--; )
			{
				int start_addr = info->vucStartLAddr[i];
				if( laddr >= start_addr )
				{
					return info->ppucData[i] + laddr - start_addr;
				}
			}
		}
		else
		{
			info = NULL;
		}
    }
    else //16K buffers.
    {
        for( i=tSWIPBufferInfo.iSize; i--; )
        {
            int start_addr = tSWIPBufferInfo.vusStartAddr[i];

            if( _addr >= start_addr)
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
	
	if(thisInfo->eEventTriggerType == ETT_REGISTER){
		SWIP_REG_ADDR = SWIP_REG_ADDR_EVENT_PACKET_INFO;
	}
	else{
		SWIP_REG_ADDR = SWIP_REG_ADDR_EVENT_PACKET_CONTENT;
	}

    if( _addr == SWIP_REG_ADDR_CTRL_GETTER + offsetof(tProtocolGetter_t, eReadyStatus) )
    {
        if( tProtocolCtrl.getter->eReadyStatus != RS_NONE )
            tProtocolCtrl.getter->eReadyStatus = RS_NONE;
    }
    //Touch packet의 마지막 data를 읽어갈 때,
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
}



#if (SWIP_QUEUE_MODE)
__IO tSWIPPacketInfo_t ptPacketInfoQueue[SWIP_QUEUE_SIZE];
#endif
void protocol_swip_PushTouchEvent(const uSWIPTouchItem_t* _kptItem)
{
	int index = 0;

#if (SWIP_QUEUE_MODE)
	if(sptAlgorithmInfo->bQueueStart == 0)
	{
		sptAlgorithmInfo->bQueueStart = 1;
		if((sptAlgorithmInfo->QueueRear + 1) % SWIP_QUEUE_SIZE == sptAlgorithmInfo->QueueFront ) // Queue Full Check
		{	
			uint8_t CurrFrontIdx, NextFrontIdx;

			if( protocol_swip_CheckEventInterrupt() == YES )
			{
				CurrFrontIdx = (sptAlgorithmInfo->QueueRear + 1) % SWIP_QUEUE_SIZE;
			}
			else
			{
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
		memset((void *)&ptPacketInfoQueue[sptAlgorithmInfo->QueueRear], 0x00, sizeof(tSWIPPacketInfo_t));
	}
#endif

	index = (_kptItem->tItem00.tInfo.b4FingerID-1);

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
	thisInfo->iEventPacket_ += ((int)tSWIPEvent.ptEventFormat->ucTouchPacketItemSize);
#endif
}

void protocol_swip_SendTouchEvent(void)
{
	int index = 0;	

#if (SWIP_QUEUE_MODE)
	if(sptAlgorithmInfo->QueueFront != sptAlgorithmInfo->QueueRear && protocol_swip_CheckEventInterrupt() == YES ) // Not Queue Empty
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

void protocol_swip_SendPenEvent(void)
{
	int index;

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

void protocol_swip_Init(void)
{
	volatile unsigned long  BOOT_ADDR = 0x00001FFAUL;

	thisCommonConf = protocol_GetCommonConfig();
	thisInfo = protocol_GetInfo();
	sptAlgorithmInfo = algorithm_GetInfo();

	tSWIPInfo.ptPanel->usXResolution = I2C_X_RESOLUTION;//32768;
	tSWIPInfo.ptPanel->usYResolution = I2C_Y_RESOLUTION;//32768;

	tSWIPInfo.ptPanel->ucXNode_ = COL_MAX;
	tSWIPInfo.ptPanel->ucYNode_ = ROW_MAX;
	tSWIPInfo.ptPanel->ucLocalYNode_ = PEN_COORD_ROW_MAX;
#ifdef _USE_WITH_BOOT_
    tSWIPInfo.ptVersion->bcdBootVer = (*(uint16_t *)(0x2FF4));
#else
    tSWIPInfo.ptVersion->bcdBootVer = BOOT_VERSION;
#endif
    tSWIPInfo.ptVersion->bcdAppVer = APP_VERSION;
    tSWIPInfo.ptVersion->bcdParamVer = CONFIG_VERSION;

#ifdef _USE_WITH_BOOT_
	tSWIPInfo.ptIntegrity->ulBootCRC = (*(volatile unsigned short *)(0x2FFC));
	tSWIPInfo.ptIntegrity->ulAppCRC = (*(volatile unsigned short *)(0x1FFFC));
#else
	tSWIPInfo.ptIntegrity->ulBootCRC = 0xFFFF;//SYSCFG_SPI_BOOT_crc_code_read();
	tSWIPInfo.ptIntegrity->ulAppCRC = 0xFFFF;//SYSCFG_SPI_APP_crc_code_read();
#endif /* _USE_WITH_BOOT_ */

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	protocol_swip_UpdatePTInspectionGetInfo();
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

	tSWIPInfo.ptIntegrity->ulParamCRC = 0x00000000;
	tSWIPInfo.ptExtra->usPWMTxFrequecy = PWMDRV_USED_FREQUENCY;

	tSWIPEvent.ptEventFormat->ePacketFormatId = thisCommonConf->ePacketFormatId;

	int iItemSize = 0x06;
	int iTouchEventPacketSize  = 0x0042;

	tSWIPEvent.ptEventFormat->ucTouchPacketItemSize = iItemSize;
	tSWIPEvent.ptPacketInfo = malloc(iTouchEventPacketSize);
	memset(tSWIPEvent.ptPacketInfo, 0, iTouchEventPacketSize);

	vtProtocolBufferPointers.pParameterBuffer = (void *)PARAM_GetPreMainSet();
}

