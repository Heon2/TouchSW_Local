/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : module.c
 * created on : 17. 4. 2017
 * Author : mhjang
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

#include "hal_def.h"
#include "module_def.h"
#include "app_def.h"
#include "protocol_def.h"


static const tModuleFixedConf_t * thisFixedConf = NULL;
#if USED_SPEED_MESURE
static const tModuleCommonConf_t * _ptModuleCommonConf = NULL;
#endif /* USED_SPEED_MESURE */

#if USED_ESD_RECOVERY_CODE
static tAlgorithmInfo_t * sptAlgorithmInfo  = NULL;
#endif /* USED_ESD_RECOVERY_CODE */
			
#if USED_NOISE_HOPPING_FREQ	
static tAppInfo_t * ptAppInfo = NULL;
static const tAppCommonConf_t * thisCommonConf = NULL;
#endif /* USED_NOISE_HOPPING_FREQ */

enum_LOCAL_SENGSING_POSITION LocalSensingPos = LOCAL_0TH_POSITION;
enum_LOCAL_SENGSING_POSITION GetLocalSensingArea(void)
{
	return LocalSensingPos;
}

void SetLocalSensingArea(enum_LOCAL_SENGSING_POSITION area)
{
	LocalSensingPos = area;
}


volatile bool_t gbIrqFlag[IRQ_ID_MAX] = { 0, };

void hal_set_irq_flag(int _id)
{
	gbIrqFlag[_id] = 1;
}

void hal_clear_irq_flag(int _id)
{
	gbIrqFlag[_id] = 0;
}

bool_t hal_get_irq_flag(int _id)
{
	return gbIrqFlag[_id];
}

volatile uint8_t gucOverlapFPend = 0;

void hal_set_overlap_pen(void)
{
	gucOverlapFPend = 1;
}

void hal_clear_overlap_pen(void)
{
	gucOverlapFPend = 0;
}

uint8_t hal_get_overlap_pen(void)
{
	return gucOverlapFPend;
}

volatile ePartialSensing_t gLocalTypeFlag  = PARTIAL_PEN_BEACON;

void hal_set_LocalType_flag(ePartialSensing_t _id)
{
	gLocalTypeFlag = _id;
}

void hal_clear_LocalType_flag(void)
{
	gLocalTypeFlag = PARTIAL_PEN_BEACON;
}

ePartialSensing_t hal_get_LocalType_flag(void)
{
	return gLocalTypeFlag;
}

volatile eNormalOperSubState_t gSubStateFlag  = TOUCH_NORMAL_OPER_NONCHANGE;

void hal_set_SubState_flag(eNormalOperSubState_t _id)
{
	gSubStateFlag = _id;
}

void hal_clear_SubState_flag(void)
{
	gSubStateFlag = TOUCH_NORMAL_OPER_NONCHANGE;
}

eNormalOperSubState_t hal_get_SubState_flag(void)
{
	return gSubStateFlag;
}


void module_MspiBuff_Init(void)
{
	int i = 0;

	//Initialize MSPI_SRAM
	for (i=0;i<0x6000;i+=4)
	{
		HW_REG(BASE_MSPI_SRAM+i)=0;
	}
}

void module_System_Init(void)
{
	SysTick_Initialize(TMCU_MAIN_TRIM_CLOCK_SPEED);
	SCRB_Initialize();
	ReMapVectorTableToRam();
	GPIO_Initialize();
#if USED_LPWG_MODE_CONTROL
	HAL_Timer_Init();
#endif /* USED_LPWG_MODE_CONTROL */
}

//extern void protocol_init(void); // NOTE : hal.c�� ����Ǿ� �ִ� �Լ��� �����ϴ� �κп����� ��������� �����ϴ� ������ ��������!!
void module_Protocol_Init(void)
{
	int bSWreset = 0;
//	uint8_tAddress = 0; // NOTE : not used!!
	SCRB->USB_CTL_UC.ulBulk = 0x01;
	HW_REG(BASE_USB|0xC4) =  HW_REG(BASE_USB|0xC4)  | BIT3;
	//delay_ms(530); // NEC�� ���� ����
	USB_DevInit();

	if(bSWreset)
	{
		mUsbSoftRstSet();
		while (wFOTGPeri_Port(0x100) & BIT4);
	}

	NVIC_EnableIRQ (USB_IRQn);
	NVIC_SetPriority(USB_IRQn, USB_IRQn_Priority);

	//ETC
	hal_PendSVHandlerInitialize();

	I2C_Initialize();

	protocol_init();
//	Address = I2C->I2C_DEVICE_ADD_b.I2cId; // NOTE : not used!!
}

#if defined(USE_BOOTLOADER_16KB)
BACKUP_INFO_TypeDef TMP_INFO;
void module_Slv_addr_change(void)
{
	
	if(BACKUP_BOOT_INFO_3->I2C_BOOT_INFO_b.I2C_SADDR != I2C_ADDRESS)
	{
		TMP_INFO = *BACKUP_BOOT_INFO_1;
		TMP_INFO.I2C_BOOT_INFO_b.I2C_SADDR = I2C_ADDRESS;
		FLASH_Write((uint32_t)&BACKUP_BOOT_INFO_1->I2C_BOOT_INFO, TMP_INFO.I2C_BOOT_INFO);
		
		TMP_INFO = *BACKUP_BOOT_INFO_2;
		TMP_INFO.I2C_BOOT_INFO_b.I2C_SADDR = I2C_ADDRESS;
		FLASH_Write((uint32_t)&BACKUP_BOOT_INFO_2->I2C_BOOT_INFO, TMP_INFO.I2C_BOOT_INFO);
		
		TMP_INFO = *BACKUP_BOOT_INFO_3;
		TMP_INFO.I2C_BOOT_INFO_b.I2C_SADDR = I2C_ADDRESS;
		FLASH_Write((uint32_t)&BACKUP_BOOT_INFO_3->I2C_BOOT_INFO, TMP_INFO.I2C_BOOT_INFO);
	}
}
void module_boot_vidpid_change(void)
{
	if(BACKUP_BOOT_INFO_3->VID_PID_INFO_b.VID_INFO != UNIQUE_VID/*BOOT_VID*/)
	{
		TMP_INFO = *BACKUP_BOOT_INFO_1;
		TMP_INFO.VID_PID_INFO_b.VID_INFO = UNIQUE_VID/*BOOT_VID*/;
		FLASH_Write((uint32_t)&BACKUP_BOOT_INFO_1->VID_PID_INFO, TMP_INFO.VID_PID_INFO);
		
		TMP_INFO = *BACKUP_BOOT_INFO_2;
		TMP_INFO.VID_PID_INFO_b.VID_INFO = UNIQUE_VID/*BOOT_VID*/;
		FLASH_Write((uint32_t)&BACKUP_BOOT_INFO_2->VID_PID_INFO, TMP_INFO.VID_PID_INFO);
		
		TMP_INFO = *BACKUP_BOOT_INFO_3;
		TMP_INFO.VID_PID_INFO_b.VID_INFO = UNIQUE_VID/*BOOT_VID*/;
		FLASH_Write((uint32_t)&BACKUP_BOOT_INFO_3->VID_PID_INFO, TMP_INFO.VID_PID_INFO);	
	}

	if(BACKUP_BOOT_INFO_3->VID_PID_INFO_b.PID_INFO != UNIQUE_APP_PID/*BOOT_PID*/)
	{
		TMP_INFO = *BACKUP_BOOT_INFO_1;
		TMP_INFO.VID_PID_INFO_b.PID_INFO = UNIQUE_APP_PID/*BOOT_PID*/;
		FLASH_Write((uint32_t)&BACKUP_BOOT_INFO_1->VID_PID_INFO, TMP_INFO.VID_PID_INFO);
		
		TMP_INFO = *BACKUP_BOOT_INFO_2;
		TMP_INFO.VID_PID_INFO_b.PID_INFO = UNIQUE_APP_PID/*BOOT_PID*/;
		FLASH_Write((uint32_t)&BACKUP_BOOT_INFO_2->VID_PID_INFO, TMP_INFO.VID_PID_INFO);
		
		TMP_INFO = *BACKUP_BOOT_INFO_3;
		TMP_INFO.VID_PID_INFO_b.PID_INFO = UNIQUE_APP_PID/*BOOT_PID*/;
		FLASH_Write((uint32_t)&BACKUP_BOOT_INFO_3->VID_PID_INFO, TMP_INFO.VID_PID_INFO);	
	}
}
#endif /* (USE_BOOTLOADER_16KB) */


void module_HW_Init(void)
{
#if defined(USE_BOOTLOADER_16KB)
	module_Slv_addr_change();
	module_boot_vidpid_change();
#endif

	
	module_System_Init();
	module_Protocol_Init();
	
	module_MspiBuff_Init();
	
	GPIO->tGPIO_PU_0._GPIO_TSYNC_IN	= 0x0;	// OUTPUT
	GPIO->tGPIO_PU_0._GPIO_VSYNC	= 0x0;	// OUTPUT
	GPIO->tGPIO_PU_1._GPIO_LCD_ON  = 0x0;	// Input

	GPIO->tGPIO_PU_0._GPIO_MSPI_0_MISO = 0x0; // 0:GPIO, 1:MSPI0_MST_MISO
	GPIO->tGPIO_PU_0._GPIO_MSPI_1_MISO = 0x0; // 0:GPIO, 1:MSPI1_MST_MISO
	GPIO->tGPIO_PU_0._GPIO_MSPI_2_MISO = 0x0; // 0:GPIO, 1:MSPI2_MST_MISO
	GPIO->tGPIO_PU_0._GPIO_MSPI_3_MISO = 0x0; // 0:GPIO, 1:MSPI3_MST_MISO
	GPIO->tGPIO_PU_0._GPIO_MSPI_4_MISO = 0x0; // 0:GPIO, 1:MSPI4_MST_MISO
	GPIO->tGPIO_PU_0._GPIO_MSPI_5_MISO = 0x0; // 0:GPIO, 1:MSPI5_MST_MISO
	GPIO->tGPIO_AFIO_3._GPIO_TP_INTR = 0x0;
	GPIO->tGPIO_DIR_1._GPIO_TP_INTR = 0x1;
	GPIO->tGPIO_DATA_1._GPIO_TP_INTR = I2C_GPB10__HIGH;

	// SRIC Init control
	GPIO->tGPIO_AFIO_1._GPIO_RSTN_0 = 0;
	GPIO->tGPIO_DATA_0._GPIO_RSTN_0 = 1;
	GPIO->tGPIO_DIR_0._GPIO_RSTN_0 = 1;

	GPIO->tGPIO_AFIO_1._GPIO_RSTN_1 = 0;
	GPIO->tGPIO_DATA_0._GPIO_RSTN_1 = 1;
	GPIO->tGPIO_DIR_0._GPIO_RSTN_1 = 1;

#if USED_TSYNC2_INPUT_CONTROL
	GPIO->tGPIO_PU_1._GPIO_TSYNC2_IN	= 0x0;	// Input
	init_EXIT(PIN_GPA37, EDGE_DETECTION_GPIO, BOTH_EDGE_GPIO, POSITIVE_HIGH_GPIO, ENABLE_GPIO);
#endif /* USED_TSYNC2_INPUT_CONTROL */
//	GPIO->tGPIO_DIR_1._GPIO_TP_EN = 1;
//	GPIO->tGPIO_DATA_1._GPIO_TP_EN = 0;
}

#if USED_SPEED_MESURE
#define SPEED_MESURE_START_OFFSET				(3)
#define SPEED_MESURE_COL_DIRECTION_TOUCH_NUM	(5)
#define SPEED_MESURE_ROW_DIRECTION_TOUCH_NUM	(2)
#define SPEED_MESURE_FINGER_TOUCH_ROW_NUM		(3)
#define SPEED_MESURE_FINGER_TOUCH_COL_NUM		(3)
#define SPEED_MESURE_FINGER_TOUCH_NODE_NUM		(SPEED_MESURE_FINGER_TOUCH_ROW_NUM * SPEED_MESURE_FINGER_TOUCH_COL_NUM)
#define SPEED_MESURE_FINGER_MAX_TOUCH_NUM		(10)
#define SPEED_MESURE_INIT_COUNT_NUM				(100)
uint16_t mulMesureIntensityValue[SPEED_MESURE_FINGER_TOUCH_NODE_NUM] =
{100, 120, 100, 120, 180, 120, 100, 120, 100};

uint16_t mulMesureColIndex[SPEED_MESURE_FINGER_MAX_TOUCH_NUM] =
{0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
uint16_t mulMesureRowIndex[SPEED_MESURE_FINGER_MAX_TOUCH_NUM] =
{0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
uint16_t mulMesureVectorIndex[SPEED_MESURE_FINGER_TOUCH_NODE_NUM];
uint16_t mulMesureStartPosition[SPEED_MESURE_FINGER_MAX_TOUCH_NUM];
#endif /* USED_SPEED_MESURE */

void MODULE_Initialize(void)
{
#if USED_NOISE_HOPPING_FREQ	
	ptAppInfo = app_GetInfo();
	thisCommonConf = app_GetCommonConfig();
#endif /* USED_NOISE_HOPPING_FREQ */
	thisFixedConf = module_GetFixedConfig();

#if USED_ESD_RECOVERY_CODE
	sptAlgorithmInfo = algorithm_GetInfo();
#endif /* USED_ESD_RECOVERY_CODE */

	initBoardGPIO();
	SRIC_Initialize();
	//initECLK();
	//delay_ms(10);

#if USED_SPEED_MESURE
	{
		uint32_t ulIdx, ulRow, ulCol;
		uint32_t ulColOffset;
		uint32_t ulRowOffset;

		_ptModuleCommonConf = module_GetCommonConfig();
		ulColOffset = _ptModuleCommonConf->ucScreenCol_ / SPEED_MESURE_COL_DIRECTION_TOUCH_NUM;
		ulRowOffset = _ptModuleCommonConf->ucScreenRow_ / SPEED_MESURE_ROW_DIRECTION_TOUCH_NUM;

		ulIdx = 0;
		for(ulRow = 0; ulRow < SPEED_MESURE_FINGER_TOUCH_ROW_NUM; ulRow++)
		{
			for(ulCol = 0; ulCol < SPEED_MESURE_FINGER_TOUCH_COL_NUM; ulCol++)
			{
				mulMesureVectorIndex[ulIdx] = (_ptModuleCommonConf->ucScreenCol_ * ulRow) + ulCol;
				ulIdx++;
			}
		}

		for(ulIdx = 0; ulIdx < SPEED_MESURE_FINGER_MAX_TOUCH_NUM; ulIdx++)
		{
			mulMesureStartPosition[ulIdx] = ((SPEED_MESURE_START_OFFSET + (mulMesureRowIndex[ulIdx]*ulRowOffset))*_ptModuleCommonConf->ucScreenCol_)+(SPEED_MESURE_START_OFFSET + (mulMesureColIndex[ulIdx]*ulColOffset));
		}
	}
#endif /* USED_SPEED_MESURE */
}

void module_Watch_Enable(void)
{
	Hal_WDT_Init();
}

bool_t module_Start(void)
{
	bool_t retVal = YES;

	retVal = Hal_sric_start(NO);

	return retVal;
}

void module_DIag_Start(void)
{
	Hal_sric_start(NO);
}

void module_CmuxOff_Start(void)
{
	Hal_sric_start(YES);
}

uint16_t tbuf[300] = {0,};
uint32_t tbuf1[300] = {0,};
int tcnt = 0;
#if USED_SPEED_MESURE
uint32_t ulSpeedMesureInitCnt = 0;
#endif /* USED_SPEED_MESURE */

#if USED_ESD_RECOVERY_CODE
tXY_t 	 AbnormalDataXY[ABNORMAL_RAWDATA_CNT_THD] = {0,};
uint8_t	 AbnormalDataFlag[ABNORMAL_RAWDATA_CNT_THD] = {0,};
#endif /* USED_ESD_RECOVERY_CODE */

#if (USED_NORMAL_NI_SENSING || USED_IDLE_MODE_CONTROL)
#if (USED_IDLE_NI_SENSING_MUX_NUM == 3)
static uint32_t g_vulNiRowIdx[NI_ROW_MAX] = {0, 2, 4, 6, 1, 3, 5, 7, 8, 10, 12, 14};
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 2)
static uint32_t g_vulNiRowIdx[NI_ROW_MAX] = {0, 2, 4, 6, 1, 3, 5, 7};
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 1)
static uint32_t g_vulNiRowIdx[NI_ROW_MAX] = {0, 2, 4, 6};
#endif /* (USED_IDLE_NI_SENSING_MUX_NUM == 3) */
#endif /* (USED_NORMAL_NI_SENSING || USED_IDLE_MODE_CONTROL) */
void module_read_full_sample_data(void)
{
	int c, r;
	int width = COL_MAX;
	int height = ROW_MAX;
	volatile unsigned long uiBaseAddr = BASE_MSPI_SRAM;
#if USED_NORMAL_NI_SENSING
	volatile unsigned long uiNi1BaseAddr = BASE_MSPI_SRAM + 0x3E8;
#endif /* USED_NORMAL_NI_SENSING */

#if USED_ESD_RECOVERY_CODE
	uint16_t MinData = 8190;
	uint8_t  AbnormalDataIdx = 0;
	uint8_t  bAbnormalDataFlag = NO;
	sptAlgorithmInfo->usAbnormalRawdataNodeCnt = 0;
#endif /* USED_ESD_RECOVERY_CODE */

	tHalIntrHandle.ulFrameCnt++;

	for (r = 0; r < height; ++r)
	{
		for (c = 0; c < width; ++c)
		{
			HAL_WRITE_RAW_IMAGE(r, c, *((volatile unsigned short * )((thisFixedConf->ulFullSensing_Remap_Table[r][c] + uiBaseAddr))));

			//HAL_WRITE_RAW_IMAGE(r, c, (HAL_READ_RAW_IMAGE(r, c) * 2));

#if USED_ESD_RECOVERY_CODE
			if(HAL_READ_RAW_IMAGE(r, c) == 4095)
			{
				if(sptAlgorithmInfo->usAbnormalRawdataFrameCnt1 == 0)
				{
					if(sptAlgorithmInfo->usAbnormalRawdataNodeCnt < ABNORMAL_RAWDATA_CNT_THD)
					{
						AbnormalDataXY[sptAlgorithmInfo->usAbnormalRawdataNodeCnt].x = c;
						AbnormalDataXY[sptAlgorithmInfo->usAbnormalRawdataNodeCnt].y = r;		
						AbnormalDataFlag[sptAlgorithmInfo->usAbnormalRawdataNodeCnt] = YES;
					}
				}	
				sptAlgorithmInfo->usAbnormalRawdataNodeCnt++;
			}
			if(MinData > HAL_READ_RAW_IMAGE(r, c))
			{
				MinData = HAL_READ_RAW_IMAGE(r, c);
			}
#endif /* USED_ESD_RECOVERY_CODE */ 
		}
	}

#if USED_ESD_RECOVERY_CODE
	if(sptAlgorithmInfo->usAbnormalRawdataNodeCnt == 0)
	{
		sptAlgorithmInfo->usAbnormalRawdataFrameCnt1 = 0;
	}
	else if(sptAlgorithmInfo->usAbnormalRawdataFrameCnt1 == 0)
	{
		sptAlgorithmInfo->usAbnormalRawdataFrameCnt1++;
		sptAlgorithmInfo->usAbnormalRawdataNodeNum = sptAlgorithmInfo->usAbnormalRawdataNodeCnt;
	}
	else
	{
		for(AbnormalDataIdx = 0; AbnormalDataIdx < sptAlgorithmInfo->usAbnormalRawdataNodeNum; AbnormalDataIdx++)
		{
			if(AbnormalDataFlag[AbnormalDataIdx] == YES)
			{
				if(HAL_READ_RAW_IMAGE(AbnormalDataXY[AbnormalDataIdx].y, AbnormalDataXY[AbnormalDataIdx].x) == 4095)
				{
					bAbnormalDataFlag = YES;
				}
				else
				{
					AbnormalDataFlag[AbnormalDataIdx] = NO;
				}
			}
		}
		if(bAbnormalDataFlag == YES)
		{
			sptAlgorithmInfo->usAbnormalRawdataFrameCnt1++;
		}
		else
		{
			sptAlgorithmInfo->usAbnormalRawdataFrameCnt1 = 0;
		}
	}
	
	if(MinData < MINRAWDATA_MARGIN)
	{
		sptAlgorithmInfo->usAbnormalRawdataFrameCnt2++;
	}
	else
	{
		sptAlgorithmInfo->usAbnormalRawdataFrameCnt2 = 0;
	}
#endif /* USED_ESD_RECOVERY_CODE */ 	
	
#if USED_POOR_PANEL_COLLINE_DISABLE
	HAL_WRITE_RAW_IMAGE(39, 0, HAL_READ_RAW_IMAGE(38, 0));
#endif /* USED_POOR_PANEL_COLLINE_DISABLE */

#if USED_NORMAL_NI_SENSING
	height = NI_ROW_MAX;
	for (r = 0; r < height; ++r)
	{
		for (c = 0; c < width; ++c)
		{
			HAL_NI_WRITE_RAW_IMAGE(r, c, *((volatile unsigned short * )((thisFixedConf->ulFullSensing_Remap_Table[g_vulNiRowIdx[r]][c] + uiNi1BaseAddr))));
		}
	}
#endif /* USED_NORMAL_NI_SENSING */
}

#if USED_IDLE_MODE_CONTROL
void module_read_full_NI_sample_data(void)
{
	int c, r;
	int width = COL_MAX;
	int height = NI_ROW_MAX;

	volatile unsigned long uiBaseAddr = BASE_MSPI_SRAM;

	for (r = 0 ; r < height ; ++r)
	{
		for (c = 0 ; c < width ; ++c)
		{
			HAL_NI_WRITE_RAW_IMAGE(r, c, *((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[g_vulNiRowIdx[r]][c] + uiBaseAddr))));
		}
	}
}
#endif /* USED_IDLE_MODE_CONTROL */

void module_data_check(uint16_t lPenCoordRawdata)
{
  static int ResetFlagCnt = 0;
	if(lPenCoordRawdata > 1 )
	{
		ResetFlagCnt++;
	}
	else
	{
		ResetFlagCnt = 0;
	}

	if(ResetFlagCnt == 8 )
	{
		ResetFlagCnt = 0;
		while(1);
	}
}

volatile int PenCoordIdx = 0;
const ePartialSensing_t ePenPartialIndex[15] =
{
#if USED_WACOM_PEN
		PARTIAL_PEN_COORD1,		// 2LHB
		PARTIAL_PEN_DATA1,		// 3LHB
		PARTIAL_FINGER1,		// 4LHB
		PARTIAL_PEN_COORD2,		// 5LHB
		PARTIAL_PEN_DATA2,		// 6LHB
		PARTIAL_PEN_DATA3,		// 7LHB
		PARTIAL_FINGER2,		// 8LHB
		PARTIAL_PEN_COORD3,		// 9LHB
		PARTIAL_FINGER3,		// 10LHB
		PARTIAL_FINGER4,		// 11LHB
		PARTIAL_FINGER5,		// 12LHB
		PARTIAL_PEN_COORD4,		// 13LHB
		PARTIAL_PEN_DATA4,		// 14LHB
		PARTIAL_PEN_DATA5,		// 15LHB
		PARTIAL_FINGER6			// 16LHB
#else
		PARTIAL_PEN_COORD1,
		PARTIAL_PEN_DATA1,
		PARTIAL_PEN_DATA2,
		PARTIAL_PEN_DATA3,
		PARTIAL_PEN_COORD2,
		PARTIAL_FINGER1,
		PARTIAL_FINGER2,
		PARTIAL_FINGER3,
		PARTIAL_PEN_COORD3,
		PARTIAL_FINGER4,
		PARTIAL_FINGER5,
		PARTIAL_PEN_DATA4,
		PARTIAL_PEN_DATA5,
		PARTIAL_PEN_COORD4,
		PARTIAL_FINGER6
#endif
};

extern uint16_t sensingRowStart;

#if (!defined(FINGER_ONLY) || USED_PEN_MODE_OPERATION)
ePartialSensing_t module_read_local_sample_data(void)
{
	int c, r, lstart = 0;
	int width = COL_MAX;
	int height = 8;		// 8�� ���ǰ� �� ���� �ʳ�?
	ePartialSensing_t RetVal = PARTIAL_PEN_BEACON;

	uint16_t ulRawdata = 0;

	volatile unsigned long uiBaseAddr = BASE_MSPI_SRAM;

#if USED_WACOM_PEN
	int lRowIndex = 0;
	uint16_t lRowPos = 0;
	uint16_t PenAbnormalDataCnt = 0;
	uint16_t PenCoordRawdata = 0;
	uint16_t PenDataRawdata = 0; // << �߰� pen data�� �ϴ� ����


	uint8_t RowIndex[4][8] =
	{
		{0,1,2,3,4,5,6,7},
		{2,3,4,5,6,7,0,1},
		{4,5,6,7,0,1,2,3},
		{6,7,0,1,2,3,4,5}
	};

	RetVal = ePenPartialIndex[PenCoordIdx];



	switch(RetVal)
	{
		/*
		 * # Pen Position Process
		 *
		 */
//		case PARTIAL_PEN_COORD1:
		case PARTIAL_PEN_COORD2:
		case PARTIAL_PEN_COORD3:
		case PARTIAL_PEN_COORD4:
		{
			for(r = 0 ; r < height ; r++)
			{
				lRowPos = ( sensingRowStart > 7) ? sensingRowStart % 8 : sensingRowStart;
				lRowPos /= 2;
				lRowIndex = RowIndex[lRowPos][r];

				for (c = 0 ; c < width ; ++c)
				{
					PenCoordRawdata = (*((volatile unsigned short *) ((thisFixedConf->ulFullSensing_Remap_Table[lRowIndex][c] + uiBaseAddr))));
//					if (PenCoordRawdata == 0 || PenCoordRawdata > 4096)
//						PenAbnormalDataCnt++;
					HAL_WRITE_LOCAL_RAW_IMAGE(r, c, PenCoordRawdata);
				}
			}
		}
		break;
		/*
		 * # Pen Position Process
		 * - 1 MUX ( 4Line )
		 * - 1 LHB x 4 MUX = 16 Line
		 */
		case PARTIAL_PEN_DATA1:
		case PARTIAL_PEN_DATA2:
		case PARTIAL_PEN_DATA3:
		case PARTIAL_PEN_DATA4:
		case PARTIAL_PEN_DATA5:
		{
			for(r = 0 ; r < height ; r++)
			{
				lRowPos = ( sensingRowStart > 7) ? sensingRowStart % 8 : sensingRowStart;
				lRowPos /= 2;
				lRowIndex = RowIndex[lRowPos][r];

				for (c = 0 ; c < width ; ++c)
				{
					PenDataRawdata = (*((volatile unsigned short *) ((thisFixedConf->ulFullSensing_Remap_Table[lRowIndex][c] + uiBaseAddr))));
					HAL_WRITE_LOCAL_DATA_RAW_IMAGE(r, c, PenDataRawdata);
				}
			}
			break;
		}
		/*
		 * # Pen Finger Process
		 *
		 */
		case PARTIAL_FINGER1:
		case PARTIAL_FINGER2:
		case PARTIAL_FINGER3:
		case PARTIAL_FINGER4:
		case PARTIAL_FINGER5:
		case PARTIAL_FINGER6:
		{
			if (RetVal == PARTIAL_FINGER1)
			{
				lstart = 0;
			}
			else if (RetVal == PARTIAL_FINGER2)
			{
				lstart = 8;
			}
			else if (RetVal == PARTIAL_FINGER3)
			{
				lstart = 16;
			}
			else if (RetVal == PARTIAL_FINGER4)
			{
				lstart = 24;
			}
			else if (RetVal == PARTIAL_FINGER5)
			{
				lstart = 32;
			}
			else if (RetVal == PARTIAL_FINGER6)
			{
				lstart = 40;
			}

			for (r = 0; r < height; ++r)
			{
				for (c = 0; c < COL_MAX; ++c)
				{
					HAL_WRITE_LOCAL_FINGER_RAW_IMAGE(r + lstart, c, (*((volatile unsigned short * )((thisFixedConf->ulFullSensing_Remap_Table[r][c] + uiBaseAddr)))));
				}
			}
		}
		break;

		default:
		break;
	}
#else
	RetVal = ePenPartialIndex[PenCoordIdx];

	switch(RetVal)
	{
		/*
		 * # Pen Position Process
		 *
		 */
//		case PARTIAL_PEN_COORD1:
		case PARTIAL_PEN_COORD2:
		case PARTIAL_PEN_COORD3:
		case PARTIAL_PEN_COORD4:
		{
			height = PEN_COORD_ROW_MAX;
			for(r = 0 ; r < height ; r++)
			{
				for(c = 0 ; c < width ; c++)
				{
					ulRawdata = (*((volatile unsigned short *)((thisFixedConf->ulPartialSensing_RemapTable[r][c] + uiBaseAddr))));
#if USED_LOCAL_FULLFRAME_IMAGE
				  	HAL_WRITE_LOCAL_TEST_IMAGE(r + sensingRowStart, c, PenCoordRawdata);
#endif
				  	HAL_WRITE_LOCAL_RAW_IMAGE(r, c, ulRawdata);
				}
			}
			break;
		}
		/*
		 * # Pen Position Process
		 * - 1 MUX ( 4Line )
		 * - 1 LHB x 4 MUX = 16 Line
		 */
		case PARTIAL_PEN_DATA1:
		case PARTIAL_PEN_DATA2:
		case PARTIAL_PEN_DATA3:
		case PARTIAL_PEN_DATA4:
		case PARTIAL_PEN_DATA5:
		{
			height = PEN_DATA_ROW_MAX/2; /*4Mux Sensing ���� */
			for(r = 0 ; r < height; r++)
			{
				for(c = 0 ; c < width ; c++)
				{
					ulRawdata = (*((volatile unsigned short *)((thisFixedConf->ulPartialSensing_RemapTable[r][c] + uiBaseAddr))));
					HAL_WRITE_LOCAL_DATA_RAW_IMAGE(r, c, ulRawdata);
				}
			}
			break;
		}
		/*
		 * # Pen Finger Process
		 *
		 */
		case PARTIAL_FINGER6:
			lstart += 8;
			/* no break */
		case PARTIAL_FINGER5:
			lstart += 8;
			/* no break */
		case PARTIAL_FINGER4:
			lstart += 8;
			/* no break */
		case PARTIAL_FINGER3:
			lstart += 8;
			/* no break */
		case PARTIAL_FINGER2:
			lstart += 8;
			/* no break */
		case PARTIAL_FINGER1:
		{
			height = 8;
			for(r = 0; r < height; r++)
			{
				for(c = 0 ; c < COL_MAX ; c++)
				{
					ulRawdata = (*((volatile unsigned short *)((thisFixedConf->ulPartialSensing_RemapTable[r][c] + uiBaseAddr))));
					HAL_WRITE_LOCAL_FINGER_RAW_IMAGE(r + lstart, c, ulRawdata);
				}
			}
			break;
		}
		default:
			break;
	}

#endif
	PenCoordIdx++;
	if(PenCoordIdx == 15)
	{
		PenCoordIdx = 0;
#if USED_LOCAL_FULLFRAME_IMAGE
		if( bIsRefInitDone && bIsLocalReferenceInit)
		{
			sensingRowStart += 8;

			if(sensingRowStart == 48)
			{
				sensingRowStart = 0;
			}
		}
#endif
	}
	return RetVal;
}
#endif /* (!defined(FINGER_ONLY) || USED_PEN_MODE_OPERATION) */
uint8_t RESET_FLAG = 0;
extern volatile uint8_t FLAG_30Hz;

bool_t module_wait_full_sample_done(void)
{
	bool_t sCheckVCC = YES;
	bool_t bLocalSample = YES;
	eSENSING_MODE_t eSensingMode;
	eSensingMode = HAL_GetSensingMode();

	while(YES)
	{
		if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
			module_read_full_sample_data();
			break;
		}

		if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE_NI))
		{
			hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE_NI);
		}

		if(hal_get_irq_flag(IRQ_ID_LOCAL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_LOCAL_SAMPLE);
		}

#if USED_LPWG_MODE_CONTROL
		if(module_Check_LcdOn(NO) == NO && (IS_ACTIVE_MODE(eSensingMode) || IS_IDLE_MODE(eSensingMode)))
		{
			NVIC_DisableIRQ(EXTI0_IRQn);
			NVIC_DisableIRQ(EXTI1_IRQn);
			MSPI_ITConfig(DISABLE);
			PWMDRV_ITConfig(DISABLE);
			MSPI_Cmd(DISABLE);
			PWMDRV_Cmd(DISABLE);

			HAL_SetTPICMuxEnControl(NO);
			GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 0x0;
			HAL_SetSensingChangeMode(SM_CHANGE_LPWG_MODE);
			
			GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT = 0x0;
			GPIO->tGPIO_DIR_1._GPIO_TSYNC_OUT  = 0x1;
			GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 0x0;

			GPIO->tGPIO_DATA_1._GPIO_SLEEP_RST = 0x0;
			HAL_Timer_Set_Count_us(TIM_Channel_0, 30000);
			HAL_Timer_Enable(TIM_Channel_0, ENABLE);

#if (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405)
			delay_us(10000);
			if(module_Check_LcdOn(NO) == NO)
			{
				GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT = 0x0;
				GPIO->tGPIO_DIR_1._GPIO_TSYNC_OUT  = 0x1;
				GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 0x0;
				
				GPIO->tGPIO_DATA_1._GPIO_SLEEP_RST = 0x0;
				HAL_Timer_Set_Count_us(TIM_Channel_0, 30000);
				HAL_Timer_Enable(TIM_Channel_0, ENABLE);
			}
			else
			{
				HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_MAIN_MODE);
			}
#endif /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
			return NO;
		}
		else if(module_Check_LcdOn(NO) == YES && IS_LPWG_MODE(eSensingMode))
		{
			NVIC_DisableIRQ(EXTI0_IRQn);
			NVIC_DisableIRQ(EXTI1_IRQn);
			MSPI_ITConfig(DISABLE);
			PWMDRV_ITConfig(DISABLE);
			MSPI_Cmd(DISABLE);
			PWMDRV_Cmd(DISABLE);

			HAL_SetTPICMuxEnControl(NO);
			GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 0x0;
			HAL_Timer_Enable(TIM_Channel_0, DISABLE);
			HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_MAIN_MODE);
			return NO;
		}
#else /* USED_LPWG_MODE_CONTROL */
		if(sCheckVCC)
		{
			if(GPIO->tGPIO_DATA_1._GPIO_LCD_ON == 0x0)
			{
				sCheckVCC = NO;
			}
			else
			{
				sCheckVCC = YES;
			}
		}
		else
		{
			bLocalSample = NO;
			MSPI_Set_TLPMODE();
			MSPI_ITConfig(DISABLE);
			PWMDRV_ITConfig(DISABLE);
			MSPI_Cmd(DISABLE);
			PWMDRV_Cmd(DISABLE);
			SensingBufferInit();
			break;
		}
#endif /* USED_LPWG_MODE_CONTROL */

#if USED_LPWG_MCU_SLEEP
		Hal_WaitSampleDoneSleep();

		if(GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT == 1)
		{
			if(IS_S3_MODE(eSensingMode) &&
					IS_IDLE_MODE(eSensingMode) &&
					!protocol_swip_GetEventIntrType())
			{
				Hal_WaitSampleDoneSleep();
	//			__WFI();
			}
		}
#else /* USED_LPWG_MCU_SLEEP */
		__WFI();
#endif /* USED_LPWG_MCU_SLEEP */
//		if(FLAG_30Hz==1)
//			break;
				
		if(RESET_FLAG == 1)
			break;
//		if(FLAG_30Hz == 0)
//			break;
	}

	return bLocalSample;
}

#if USED_IDLE_MODE_CONTROL
bool_t module_wait_NI_sample_done(void)
{
	bool_t sCheckVCC = YES;
	bool_t bLocalSample = YES;
	eSENSING_MODE_t eSensingMode;
	eSensingMode = HAL_GetSensingMode();

	while(YES)
	{
		if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE_NI))
		{
			hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE_NI);
			module_read_full_NI_sample_data();
			break;
		}

		if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
		}

//		if(sCheckVCC)
//		{
//#if USED_FORCE_S3_MODE_OPER
//			if(GPIO->tGPIO_DATA_1._GPIO_LCD_ON == 0x1)
//			{
//				sCheckVCC = NO;
//			}
//			else
//			{
//				sCheckVCC = YES;
//			}

//			if(IS_S3_MODE(HAL_GetSensingMode()))
//			{
//				sCheckVCC = !sCheckVCC;
//			}
//#else /* USED_FORCE_S3_MODE_OPER */
//			if(GPIO->tGPIO_DATA_1._GPIO_LCD_ON == 0x1)
//			{
//				sCheckVCC = YES;
//			}
//			else
//			{
//				sCheckVCC = NO;
//			}

//			if(IS_S3_MODE(eSensingMode))
//			{
//				sCheckVCC = !sCheckVCC;
//			}
//#endif /* USED_FORCE_S3_MODE_OPER */
////			sCheckVCC = module_Check_LcdOn();
//		}
//		else
//		{
//			// TODO : LCD�� ������.. bLocalSample�� No�� �ǰ�.. ���� ������...
//			Hal_VccOff_State();
//			SensingBufferInit();
//			bLocalSample = NO;
//			break;
//		}
		__WFI();
	}

	return bLocalSample;
}
#endif /* USED_IDLE_MODE_CONTROL */

//bool_t module_wait_lpwg_sample_done(void)
//{
//	static bool_t sCheckVCC = YES;
//	bool_t bLocalSample = YES;
//
//	while(YES)
//	{
//		if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
//		{
//			hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
//#if USED_SPEED_MESURE
//#endif /* USED_SPEED_MESURE */
//			module_read_full_sample_data();
//#if USED_SPEED_MESURE
//#endif /* USED_SPEED_MESURE */
//			break;
//		}
//
//		// TODO : local Sensing����� Pen�ƴѰ�? Pen Define���� ��������!!
//		if(hal_get_irq_flag(IRQ_ID_LOCAL_SAMPLE))
//		{
//			hal_clear_irq_flag(IRQ_ID_LOCAL_SAMPLE);
//		}
//
//		if(sCheckVCC)
//		{
//			sCheckVCC = module_Check_LcdOn();
//		}
//		else
//		{
//			// TODO : LCD�� ������.. bLocalSample�� No�� �ǰ�.. ���� ������...
//			SensingBufferInit();
//			bLocalSample = NO;
//			break;
//		}
////		__WFI();
//	}
//
//	sCheckVCC = YES;
//	return bLocalSample;
//}

ePartialSensing_t module_wait_local_sample_done(void)
{
	static bool_t sLCheckVCC = YES;
	ePartialSensing_t RetVal = PARTIAL_PEN_BEACON;

	while(YES)
	{
		if(hal_get_irq_flag(IRQ_ID_LOCAL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_LOCAL_SAMPLE);

			RetVal = hal_get_LocalType_flag();
			hal_clear_LocalType_flag();
			break;
		}

		if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
		}

		if(sLCheckVCC)
		{
//			if(GPIO->tGPIO_DATA_1._GPIO_LCD_ON == 0x1)
//			{
//				sLCheckVCC = YES;
//			}
//			else
//			{
//				sLCheckVCC = NO;
//			}
//			sLCheckVCC = module_Check_LcdOn();
		}
		else
		{
			Hal_VccOff_State();
			SensingBufferInit();
			RetVal = PARTIAL_MAX;
			break;
		}
	}

	sLCheckVCC = YES;

//	protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_LOCAL_RAW_IMAGE_PTR(), COL_MAX, 8, 84/*MAX Intensity*/);
//	protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_LOCAL_DELTA_IMAGE_PTR(), COL_MAX, 8, 84/*MAX Intensity*/);
	return RetVal;
}

void module_wait_Vsync_signal(eSensingMode_t _mode, int _waitCnt)
{
    int gDiscardFrameCnt = 0;
	while(1)
	{
		if(_mode == LOCAL_MODE)
		{
			module_wait_local_sample_done();
		}
		else
		{
			module_wait_full_sample_done();
		}

		if(tHalIntrHandle.ulVSyncFlag)
		{
			tHalIntrHandle.ulVSyncFlag = 0;

			if(gDiscardFrameCnt == _waitCnt)
			{
				gDiscardFrameCnt = 0;
				break;
			}
			else
			{
				gDiscardFrameCnt++;
			}
		}
	}
}
#if USED_NOISE_HOPPING_FREQ	
bool_t module_Switch_Freq(eSENSING_FREQ_t _Freq)
{
 	bool_t retVal = FALSE;
	bool_t bFreqUse = thisCommonConf->bUseFreqHopp;

	if(_Freq == _FREQ_UNKNOWN_ || !bFreqUse)
	{
		retVal = FALSE;
	}
	else
	{
		if(_Freq == thisCommonConf->MainFreq)
		{
			ptAppInfo->eSelectFreq = FREQ_MAIN;
		}
		else if(_Freq == thisCommonConf->HoppFreq1)
		{
			ptAppInfo->eSelectFreq = FREQ_HOPP1;
		}
		else if(_Freq == thisCommonConf->HoppFreq2)
		{
			ptAppInfo->eSelectFreq = FREQ_HOPP2;
		}
		else
		{
			ptAppInfo->eSelectFreq = FREQ_UNKNOWN;
		}

		retVal = TRUE;
	}

	return retVal;
}
#endif /* USED_NOISE_HOPPING_FREQ */

extern __IO bool_t wdt_init;
void module_start_delay(void)
{
	int i;	
#if USED_LPWG_MODE_CONTROL
	if(module_Check_LcdOn(NO) == NO)
	{
		delay_ms(100);
		return;
	}
#else
	if(module_Check_LcdOn(YES) == NO)
	{ 
		while(GPIO->tGPIO_DATA_1._GPIO_LCD_ON == 0x0)
		{
			__WFI();
			if(protocol_swip_GetMode() == M_TOUCH_DFUP)	break;
		}
		initECLK();
		module_Init_TPEN();  
	}
#endif /* USED_LPWG_MODE_CONTROL */

	GPIO->tGPIO_DIR_0._GPIO_VSYNC = 0x0;	// Input
	GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 0x0;	// VSYNC
	
	for(i=0; i<10; i++)
	{
		waitVsyncFalling();
	}
}

void module_Stop(void)
{

}

bool_t module_Wait_LcdOn(void)
{
	while(1)
	{
		if(GPIO->tGPIO_DATA_1._GPIO_LCD_ON == 0x1 || protocol_swip_GetMode() == M_TOUCH_DFUP)
		{
			break;
		}
	}
	return YES;
}

bool_t module_Check_LcdOn(bool_t bPullDownGPIO)
{
	if(GPIO->tGPIO_DATA_1._GPIO_LCD_ON == 0x0)
	{
		if (bPullDownGPIO)
		{
			Hal_VccOff_State();
		}
		return NO;
	}

	return YES;
}

bool_t module_Init_TPEN(void) // NOTE : missing return value
{
	GPIO->tGPIO_DIR_1._GPIO_TP_EN = 0x0;	// input
	GPIO->tGPIO_AFIO_2._GPIO_TP_EN = 0x0;
	return YES;
}

bool_t module_RollBack_Sync(void) // NOTE : missing return value
{
#if USED_OPERATION_STAND_ALONE
	//Tsync In
	GPIO->tGPIO_AFIO_1._GPIO_TSYNC_IN = 0x0; // TSYNC
	GPIO->tGPIO_DIR_0._GPIO_TSYNC_IN = 0x1;  // output
	GPIO->tGPIO_PD_0._GPIO_TSYNC_IN = 0x1;  // output

	//Vsync In
	GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 0x0; // VSYNC
	GPIO->tGPIO_DIR_0._GPIO_VSYNC = 0x1;  // output
	GPIO->tGPIO_PD_0._GPIO_VSYNC = 0x1;  // output
#else /* USED_OPERATION_STAND_ALONE */
	//Tsync In
	GPIO->tGPIO_AFIO_1._GPIO_TSYNC_IN = 0x1; // TSYNC
	GPIO->tGPIO_DIR_0._GPIO_TSYNC_IN = 0x0;  // input

	//Vsync In
#if USED_NEW_TCON_BOARD
	GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 0x0; // VSYNC
	GPIO->tGPIO_DIR_0._GPIO_VSYNC = 0x0;  // input
#else /* USED_NEW_TCON_BOARD */
	GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 0x1; // VSYNC
	GPIO->tGPIO_DIR_0._GPIO_VSYNC = 0x0;  // input
#endif /* USED_NEW_TCON_BOARD */
#endif /* USED_OPERATION_STAND_ALONE */
	return YES;
}

bool_t module_Check_TPEN(void)
{
	if(GPIO->tGPIO_DATA_1._GPIO_TP_EN == 0x0)
	{
		return YES;
	}

	return NO;
}

#ifdef MODE_SMT
void module_Init_LcdOn(void)
{
	GPIO->tGPIO_AFIO_2._GPIO_LCD_ON = 0x0; // GPIO
	GPIO->tGPIO_DIR_1._GPIO_LCD_ON = 0x0;	// Input
}

void module_Tsync1_SignalBypass(void)
{
	delay_us(500);
	GPIO->tGPIO_DATA_0._GPIO_PWM_SRIC = ~GPIO->tGPIO_DATA_0._GPIO_PWM_SRIC;
#if USED_TEST_OPERATION_ENABLE
	GPIO->tGPIO_DATA_0._GPIO_PWM_TPIC = ~GPIO->tGPIO_DATA_0._GPIO_PWM_TPIC;
#endif
	GPIO->tGPIO_DATA_1._GPIO_TP_INTR = ~GPIO->tGPIO_DATA_1._GPIO_TP_INTR;
//	GPIO->tGPIO_DATA_1._GPIO_LCD_ON = ~GPIO->tGPIO_DATA_1._GPIO_LCD_ON;
}

void module_Smt_Mode_Enter(void)
{
	GPIO->tGPIO_AFIO_1._GPIO_TSYNC_IN = 0x1;
//	GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 0x1;

	GPIO->tGPIO_AFIO_1._GPIO_PWM_SRIC = 0x0; // PWM_TX
	GPIO->tGPIO_DIR_0._GPIO_PWM_SRIC  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_PWM_SRIC = 0x0;
#if USED_TEST_OPERATION_ENABLE
	GPIO->tGPIO_AFIO_1._GPIO_PWM_TPIC = 0x0; // LFD
	GPIO->tGPIO_DIR_0._GPIO_PWM_TPIC  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_PWM_TPIC = 0x0;
#endif
	GPIO->tGPIO_AFIO_3._GPIO_TP_INTR = 0x0;
	GPIO->tGPIO_DIR_1._GPIO_TP_INTR = 0x1;
	GPIO->tGPIO_DATA_1._GPIO_TP_INTR = 0x0;

//	GPIO->tGPIO_AFIO_2._GPIO_LCD_ON = 0x0;
//	GPIO->tGPIO_DIR_1._GPIO_LCD_ON  = 0x1;
//	GPIO->tGPIO_DATA_1._GPIO_LCD_ON = 0x0;
}
#endif /* MODE_SMT */

bool_t module_Init_Signal(void)
{
	if(wdt_init)
	{
		Hal_WDT_DeInit();
	}

	module_Init_LcdOn();
	module_Init_TPEN();

//	if(module_Wait_LcdOn())
//	{
//		module_RollBack_Sync();
//		return YES;
//	}

	return NO;
}

bool_t module_Skip_Event(void)
{
	if(module_Check_TPEN())
	{
		return YES;
	}
	return NO;
}

bool_t module_Defense_Recovery(void)
{
	if(GPIO->tGPIO_DATA_1._GPIO_SWDIO == 0x0 && GPIO->tGPIO_DATA_1._GPIO_SWCLK == 0x0)
	{
		return YES;
	}
	else
	{
		return NO;
	}

}
