/******************************************************************************************************
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
#if USED_TOUCH_TUNING_PROCESS
#include "app_tuning_process.h"
#endif /* USED_TOUCH_TUNING_PROCESS */
#include "param_def.h"

static const tModuleFixedConf_t * thisFixedConf = NULL;
#if USED_NOISE_HOPPING_FREQ
static const tAppCommonConf_t * thisCommonConf = NULL;
static tAppInfo_t * ptAppInfo = NULL;
#endif
#if USED_PEN_MODE_OPERATION
static const tAlgorithmModeConf_t * thisModeConf = NULL;
#endif
extern eActivePenType_t gAlgoRawDataType;
//extern uint8_t DebugPenRawView;

#if IS_WGPUHDPEN_PROTOCOL_OPERATION
#if USED_SPI_NBIT_TRANSMODE
uint8_t vclMSPIBufLocalRowIndexTable[ROIC_ALIGNED_LOCAL_PEN_ROW_LEN][PEN_COORD_ROW_MAX] = {
#if IS_ROIC_DEF_SW98502
	#if (PEN_COORD_ROW_MAX == 5)
		#if USED_PEN_ROW_5Line_SCAN_SW98502
			{0,1,2,3,4}, /* Local Index 0 */
			{0,1,2,3,4}, /* Local Index 1 */
			{0,1,2,3,4}, /* Local Index 2 */
			{0,1,2,3,4}, /* Local Index 3 */
			{0,1,2,3,4}, /* Local Index 4 */
		#else /* USED_PEN_ROW_5Line_SCAN_SW98502 */
			{0,1,2,3,4}, /* Local Index 0 */
			{0,1,2,3,4}, /* Local Index 1 */
			{0,1,2,3,4}, /* Local Index 2 */
			{0,1,2,3,4}, /* Local Index 3 */
			{0,1,2,3,4}, /* Local Index 4 */
			{0,1,2,3,4}, /* Local Index 5 */
			{0,1,2,3,4}, /* Local Index 6 */
			{0,1,2,3,4}, /* Local Index 7 */
			{0,1,2,3,4}, /* Local Index 8 */
		#endif /* USED_PEN_ROW_5Line_SCAN_SW98502 */
	#elif (PEN_COORD_ROW_MAX == 6)
			{0,1,2,3,4,5}, /* Local Index 0 */
			{1,2,3,4,5,6}, /* Local Index 1 */
			{2,3,4,5,6,7}, /* Local Index 2 */
			{3,4,5,6,7,8}, /* Local Index 3 */
			{4,5,6,7,8,0}, /* Local Index 4 */
			{5,6,7,8,0,1}, /* Local Index 5 */
			{6,7,8,0,1,2}, /* Local Index 6 */
			{7,8,0,1,2,3}, /* Local Index 7 */
			{8,0,1,2,3,4}, /* Local Index 8 */
	#elif (PEN_COORD_ROW_MAX == 7)
			{0,1,2,3,4,5,6}, /* Local Index 0 */
			{1,2,3,4,5,6,7}, /* Local Index 1 */
			{2,3,4,5,6,7,8}, /* Local Index 2 */
			{3,4,5,6,7,8,0}, /* Local Index 3 */
			{4,5,6,7,8,0,1}, /* Local Index 4 */
			{5,6,7,8,0,1,2}, /* Local Index 5 */
			{6,7,8,0,1,2,3}, /* Local Index 6 */
			{7,8,0,1,2,3,4}, /* Local Index 7 */
			{8,0,1,2,3,4,5}, /* Local Index 8 */
	#elif (PEN_COORD_ROW_MAX == 8)
			{0,1,2,3,4,5,6,7}, /* Local Index 0 */
			{1,2,3,4,5,6,7,8}, /* Local Index 1 */
			{2,3,4,5,6,7,8,0}, /* Local Index 2 */
			{3,4,5,6,7,8,0,1}, /* Local Index 3 */
			{4,5,6,7,8,0,1,2}, /* Local Index 4 */
			{5,6,7,8,0,1,2,3}, /* Local Index 5 */
			{6,7,8,0,1,2,3,4}, /* Local Index 6 */
			{7,8,0,1,2,3,4,5}, /* Local Index 7 */
			{8,0,1,2,3,4,5,6}, /* Local Index 8 */
	#elif (PEN_COORD_ROW_MAX == 9)
			{0,1,2,3,4,5,6,7,8}, /* Local Index 0 */
			{0,1,2,3,4,5,6,7,8}, /* Local Index 1 */
			{0,1,2,3,4,5,6,7,8}, /* Local Index 2 */
			{0,1,2,3,4,5,6,7,8}, /* Local Index 3 */
			{0,1,2,3,4,5,6,7,8}, /* Local Index 4 */
			{0,1,2,3,4,5,6,7,8}, /* Local Index 5 */
			{0,1,2,3,4,5,6,7,8}, /* Local Index 6 */
			{0,1,2,3,4,5,6,7,8}, /* Local Index 7 */
			{0,1,2,3,4,5,6,7,8}, /* Local Index 8 */
	#endif /* #if (PEN_COORD_ROW_MAX == 5) */
#else
	#if (PEN_COORD_ROW_MAX == 5)
			{0,1,2,3,4}, /* Local Index 0 */
			{1,2,3,4,5}, /* Local Index 1 */
			{2,3,4,5,6}, /* Local Index 2 */
			{3,4,5,6,7}, /* Local Index 3 */
			{4,5,6,7,8}, /* Local Index 4 */
			{5,6,7,8,0}, /* Local Index 5 */
			{6,7,8,0,1}, /* Local Index 6 */
			{7,8,0,1,2}, /* Local Index 7 */
			{8,0,1,2,3}, /* Local Index 8 */
	#elif (PEN_COORD_ROW_MAX == 6)
			{0,1,2,3,4,5}, /* Local Index 0 */
			{1,2,3,4,5,6}, /* Local Index 1 */
			{2,3,4,5,6,7}, /* Local Index 2 */
			{3,4,5,6,7,8}, /* Local Index 3 */
			{4,5,6,7,8,0}, /* Local Index 4 */
			{5,6,7,8,0,1}, /* Local Index 5 */
			{6,7,8,0,1,2}, /* Local Index 6 */
			{7,8,0,1,2,3}, /* Local Index 7 */
			{8,0,1,2,3,4}, /* Local Index 8 */
	#elif (PEN_COORD_ROW_MAX == 7)
			{0,1,2,3,4,5,6}, /* Local Index 0 */
			{1,2,3,4,5,6,7}, /* Local Index 1 */
			{2,3,4,5,6,7,8}, /* Local Index 2 */
			{3,4,5,6,7,8,0}, /* Local Index 3 */
			{4,5,6,7,8,0,1}, /* Local Index 4 */
			{5,6,7,8,0,1,2}, /* Local Index 5 */
			{6,7,8,0,1,2,3}, /* Local Index 6 */
			{7,8,0,1,2,3,4}, /* Local Index 7 */
			{8,0,1,2,3,4,5}, /* Local Index 8 */
	#elif (PEN_COORD_ROW_MAX == 8)
			{0,1,2,3,4,5,6,7}, /* Local Index 0 */
			{1,2,3,4,5,6,7,8}, /* Local Index 1 */
			{2,3,4,5,6,7,8,0}, /* Local Index 2 */
			{3,4,5,6,7,8,0,1}, /* Local Index 3 */
			{4,5,6,7,8,0,1,2}, /* Local Index 4 */
			{5,6,7,8,0,1,2,3}, /* Local Index 5 */
			{6,7,8,0,1,2,3,4}, /* Local Index 6 */
			{7,8,0,1,2,3,4,5}, /* Local Index 7 */
			{8,0,1,2,3,4,5,6}, /* Local Index 8 */
	#elif (PEN_COORD_ROW_MAX == 9)
			{0,1,2,3,4,5,6,7,8}, /* Local Index 0 */
			{1,2,3,4,5,6,7,8,0}, /* Local Index 1 */
			{2,3,4,5,6,7,8,0,1}, /* Local Index 2 */
			{3,4,5,6,7,8,0,1,2}, /* Local Index 3 */
			{4,5,6,7,8,0,1,2,3}, /* Local Index 4 */
			{5,6,7,8,0,1,2,3,4}, /* Local Index 5 */
			{6,7,8,0,1,2,3,4,5}, /* Local Index 6 */
			{7,8,0,1,2,3,4,5,6}, /* Local Index 7 */
			{8,0,1,2,3,4,5,6,7}, /* Local Index 8 */
	#endif /* #if (PEN_COORD_ROW_MAX == 5) */
#endif
};
#endif /* USED_SPI_NBIT_TRANSMODE */
#endif /* IS_WGPUHDPEN_PROTOCOL_OPERATION */

static void module_MspiBuff_Init(void)
{
	int i = 0;

	//Initialize MSPI_SRAM
	for (i=0;i<0x6000;i+=4)
	{
		HW_REG(BASE_RAW_SRAM+i)=0;
	}
}

static void module_System_Init(void)
{
//	SysTick_Initialize(TMCU_MAIN_TRIM_CLOCK_SPEED);
	SCRB_Initialize();
//	SYSCFG_Initialize(SPI_SCLK_RATIO_PLL_ON);
	TIMER_Initialize();
#if (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO)
	tHalIntrHandle.ulUSBSendData_TimerTick = NO;
#endif /* (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO) */
	TimerTick_Initialize(TIMER_TIM_CLOCK_MHZ);
#ifdef _USE_WITH_BOOT_
	HAL_CheckBootInterfaceInfoOnSecurityRegion();
#endif /* _USE_WITH_BOOT_ */
}

#if USED_TP_LCD_ON_OPERATION
static void module_Init_LcdOn(void)
{
	GPIO_Init(_GPIO_LCD_ON, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	GPIO_Set_PE(_GPIO_LCD_ON, GPIO_PE_PULL_DOWM); // Input
}
#endif /* USED_TP_LCD_ON_OPERATION */

#if USED_MNT_S3_MODE_FUNCTION
//static bool_t module_Wait_LcdOn(void)
//{
//	while(1)
//	{
//		if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
//		{
//			return YES;
//		}
//
//		if(IS_GPIO_PIN(_GPIO_S3_POWER_IN) == GPIO_DATA_LOW)
//		{
//			GPIO_Set_DATA(_GPIO_S3_SIGNAL_OUT, GPIO_DATA_HIGH);
//		}
//
//		if(protocol_swip_GetMode() == M_TOUCH_DFUP)
//		{
//			break;
//		}
//	}
//	return NO;
//}

#define USED_S3_ENTER_FRAME_CHECK_EN		(NO)
#if USED_S3_ENTER_FRAME_CHECK_EN
	#define S3_ENTER_FRAME_CHECK_FRAME_THD		(3)
	uint32_t ulS3EnterTestCount = 0;
	bool_t bIsS3EnterEn = NO;
#endif

static bool_t module_Check_S3_Power(void)
{
	bool_t bReg = YES;

//	if(IS_GPIO_PIN(_GPIO_S3_POWER_IN) == GPIO_DATA_HIGH)
//	{
//		GPIO_Set_DATA(_GPIO_S3_SIGNAL_OUT, GPIO_DATA_LOW);
//		bReg = YES;
//	}
//	else
//	{
//		// 수초간 Check!!
//		GPIO_Set_DATA(_GPIO_S3_SIGNAL_OUT, GPIO_DATA_HIGH);
//		bReg = NO;
//	}

#if USED_S3_ENTER_FRAME_CHECK_EN
	bIsS3EnterEn = YES;
	while(1)
	{
		if(IS_GPIO_PIN(_GPIO_S3_POWER_IN) == GPIO_DATA_LOW)
		{
			if(ulS3EnterTestCount < S3_ENTER_FRAME_CHECK_FRAME_THD)
			{
				bIsS3EnterEn = NO;
				ulS3EnterTestCount++;
				delay_msec(16);
			}
			else
			{
				bIsS3EnterEn = YES;
				GPIO_Set_DATA(_GPIO_S3_SIGNAL_OUT, GPIO_DATA_HIGH);
			}

			bReg = NO;
		}

	#if USED_TP_LCD_ON_OPERATION
		if(bIsS3EnterEn && IS_GPIO_PIN(_GPIO_LCD_ON) == GPIO_DATA_HIGH)
	#else /* USED_TP_LCD_ON_OPERATION */
		if(bIsS3EnterEn)
	#endif /* USED_TP_LCD_ON_OPERATION */
		{
			break;
		}

		if(protocol_swip_GetMode() == M_TOUCH_DFUP)
		{
			/*
			 * Receive DFUP Command!!
			 */
			bReg = YES;
			break;
		}
	}
#else
	while(1)
	{
		if(IS_GPIO_PIN(_GPIO_S3_POWER_IN) == GPIO_DATA_LOW)
		{
			GPIO_Set_DATA(_GPIO_S3_SIGNAL_OUT, GPIO_DATA_HIGH);
			bReg = NO;
		}

	#if USED_TP_LCD_ON_OPERATION
		if(IS_GPIO_PIN(_GPIO_LCD_ON) == GPIO_DATA_HIGH)
		{
			break;
		}
	#endif /* USED_TP_LCD_ON_OPERATION */

		if(protocol_swip_GetMode() == M_TOUCH_DFUP)
		{
			/*
			 * Receive DFUP Command!!
			 */
			bReg = YES;
			break;
		}
	}
#endif

	return bReg;
}
#else /* USED_MNT_S3_MODE_FUNCTION */

#if USED_VTSP_ONLY_LOW_POWER
bool_t bIsVTSPOnlyPLLOff = NO;
#endif /* USED_VTSP_ONLY_LOW_POWER */

#if USED_TP_LCD_ON_OPERATION
static bool_t module_Wait_LcdOn(void)
{
#if (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO)
	bool_t bIsEscapeLCDOnHigh = NO;
#endif /* (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO) */
	eProtocolMode_t currMode;

#ifdef MODE_I2C
	bool_t bIsWFIEnter = YES;
#endif

#if USED_OPERATION_STAND_ALONE
//	while(1)
//	{
//		if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x0)
//		{
//			break;
//		}
//	}
	return YES;
#else /* USED_OPERATION_STAND_ALONE */
#if USED_S3_MODE_FUNCTION
	uint32_t ulCount = 0;
	tTimerOpHandleInfo_t tTimerHandle;
	tTimerHandle.ulTimerUnit = TIMER_2UNIT;
	tTimerHandle.ulLoadCount = (3000000 / 30) >> 1;
	TIMER_SetOneShotMode(&tTimerHandle);
	TIMER_StartTimer(TIMER_2UNIT);

#if USED_FORCE_S3_MODE_OPER
	while(1)
	{
		if(ulCount > 0)
		{
			break;
		}
		TIMER_WaitForIrq(TIMER_2UNIT);
		ulCount++;
	}
#else /* USED_FORCE_S3_MODE_OPER */
	while(1)
	{
		if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
		{
			return YES;
		}
		else if(ulCount > 0)
		{
			break;
		}
		TIMER_WaitForIrq(TIMER_2UNIT);
		ulCount++;
	}
#endif /* USED_FORCE_S3_MODE_OPER */
	return NO;
#else /* USED_S3_MODE_FUNCTION */

//#if USED_VTSP_ONLY_LOW_POWER
//	if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x0)
//	{
//		/*
//		 * PLL Off
//		 */
//		bIsVTSPOnlyPLLOff = YES;
//		SCRB_PLL_Clock_Off(NO);
//	}
//#endif /* USED_VTSP_ONLY_LOW_POWER */

	while(1)
	{
		if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
		{
#if (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO)
			bIsEscapeLCDOnHigh = YES;
#endif /* (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO) */
			break;
		}

		currMode = protocol_swip_GetMode();
		if(currMode == M_TOUCH_DFUP || currMode == M_WATCH_DOG_RESET)
		{
#if (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO)
			bIsEscapeLCDOnHigh = NO;
#endif /* (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO) */
			break;
		}

#if (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO)
		tHalIntrHandle.ulUSBSendData_TimerTick = YES;
#endif /* (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO) */

#ifdef MODE_I2C
		if(bIsWFIEnter)
		{
			bIsWFIEnter = NO;
			__WFI();
		}
#endif
	}

#if (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO)
	if(bIsEscapeLCDOnHigh)
	{
		tHalIntrHandle.ulUSBSendData_TimerTick = NO;
	}
#endif /* (USED_QUEUECOMMONDATA_SEND_Timer_Tick == NO) */

//#if USED_VTSP_ONLY_LOW_POWER
//	if(bIsVTSPOnlyPLLOff)
//	{
//		/*
//		 * PLL On
//		 */
//		SCRB_PLL_Clock_On();
//		bIsVTSPOnlyPLLOff = NO;
//	}
//#endif /* USED_VTSP_ONLY_LOW_POWER */

	return YES;
#endif /* USED_S3_MODE_FUNCTION */
#endif /* USED_OPERATION_STAND_ALONE */
}
#endif /* USED_TP_LCD_ON_OPERATION */
#endif /* USED_MNT_S3_MODE_FUNCTION */

static bool_t module_RollBack_Sync(void)
{
#if USED_OPERATION_STAND_ALONE
	//Tsync In
	GPIO_Init(_GPIO_TSYNC_IN, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	GPIO_Set_PE(_GPIO_TSYNC_IN, GPIO_PE_PULL_DOWM);

	//Vsync In
	GPIO_Init(_GPIO_VSYNC, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	GPIO_Set_PE(_GPIO_VSYNC, GPIO_PE_PULL_DOWM);
#if USED_TSYNC2_INPUT_FROM_TCON
	GPIO_Init(_GPIO_TSYNC_2_IN, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	GPIO_Set_PE(_GPIO_TSYNC_2_IN, GPIO_PE_PULL_DOWM);
#endif /* USED_TSYNC2_INPUT_FROM_TCON */
#else /* USED_OPERATION_STAND_ALONE */
	//Tsync In
	GPIO_Init(_GPIO_TSYNC_IN, GPIO_MODE_FUNC_0, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	//Vsync In
	GPIO_Init(_GPIO_VSYNC, GPIO_MODE_FUNC_0, GPIO_DIR_INPUT, GPIO_DATA_NONE);
#if USED_TSYNC2_INPUT_FROM_TCON
	GPIO_Init(_GPIO_TSYNC_2_IN, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
#endif /* USED_TSYNC2_INPUT_FROM_TCON */
#endif /* USED_OPERATION_STAND_ALONE */
	return YES;
}

#if USED_TP_RST_OPERATION
static bool_t module_Wait_TPRST(void)
{
	uint32_t ulCount = 0;
#ifdef MODE_I2C
	bool_t bIsWFIEnter = YES;
#endif
	eProtocolMode_t currMode;

#if USED_VTSP_ONLY_LOW_POWER
	if(IS_GPIO_PIN(_GPIO_TP_RST) == 0x0)
	{
		/*
		 * PLL Off
		 */
		bIsVTSPOnlyPLLOff = YES;
		SCRB_PLL_Clock_Off(YES);
	}
#endif /* USED_VTSP_ONLY_LOW_POWER */

	while(1)
	{
		if(IS_GPIO_PIN(_GPIO_TP_RST) == 0x1)
		{
			if(ulCount > 1)
			{
				break;
			}
			ulCount++;
			delay_msec(10);
		}

#ifdef MODE_I2C
		if(bIsWFIEnter)
		{
			__WFI();
			bIsWFIEnter = NO;
		}
#endif

		currMode = protocol_swip_GetMode();
		if(currMode == M_TOUCH_DFUP || currMode == M_WATCH_DOG_RESET)
		{
			break;
		}
	}

#if USED_VTSP_ONLY_LOW_POWER
	if(bIsVTSPOnlyPLLOff)
	{
		/*
		 * PLL On
		 */
		SCRB_PLL_Clock_On();
		bIsVTSPOnlyPLLOff = NO;
	}
#endif /* USED_VTSP_ONLY_LOW_POWER */

	return YES;
}
#endif /* USED_TP_RST_OPERATION */

#if USED_TOUCH_SLEEP_CTRL_BY_HOST
static bool_t module_Wait_TOUCH_SLEEP(void)
{
	uint32_t ulCount = 0;
#ifdef MODE_I2C
	bool_t bIsWFIEnter = YES;
#endif
	eProtocolMode_t currMode;

#if USED_VTSP_ONLY_LOW_POWER
	if(IS_GPIO_PIN(_GPIO_SLEEP_EN) == 0x0)
	{
		/*
		 * PLL Off
		 */
		bIsVTSPOnlyPLLOff = YES;
		SCRB_PLL_Clock_Off(YES);
	}
#endif /* USED_VTSP_ONLY_LOW_POWER */

	while(1)
	{
		if(IS_GPIO_PIN(_GPIO_SLEEP_EN) == 0x1)
		{
			if(ulCount > 1)
			{
				break;
			}
			ulCount++;
			delay_msec(10);
		}

#ifdef MODE_I2C
		if(bIsWFIEnter)
		{
			__WFI();
			bIsWFIEnter = NO;
		}
#endif

		currMode = protocol_swip_GetMode();
		if(currMode == M_TOUCH_DFUP || currMode == M_WATCH_DOG_RESET)
		{
			break;
		}
	}

#if USED_VTSP_ONLY_LOW_POWER
	if(bIsVTSPOnlyPLLOff)
	{
		/*
		 * PLL On
		 */
		SCRB_PLL_Clock_On();
		bIsVTSPOnlyPLLOff = NO;
	}
#endif /* USED_VTSP_ONLY_LOW_POWER */

	return YES;
}
#endif /* USED_TOUCH_SLEEP_CTRL_BY_HOST */

void MODULE_Initialize(void)
{
	thisFixedConf = module_GetFixedConfig();
#if USED_NOISE_HOPPING_FREQ
	thisCommonConf = app_GetCommonConfig();
	ptAppInfo = app_GetInfo();
#endif
#if USED_PEN_MODE_OPERATION
	module_init_param();
#endif
//	GPIO_Initialize(); // 시점 변경!!
//	initBoardGPIO();

	SRIC_Initialize();
	initECLK();
	delay_msec(10);
}

#if USED_PEN_MODE_OPERATION
void module_init_param(void)
{
	thisModeConf  = algorithm_GetModeConfig();
}
#endif

void module_Protocol_Init(void)
{
#ifndef MODE_I2C
	int bSWreset = 0;
	SCRB->USB_CTRL_UC.ulBulk = 0x01;
	HW_REG(BASE_USB_SRAM|0xC4) =  HW_REG(BASE_USB_SRAM|0xC4)  | BIT3;
//	delay_ms(530); // NEC모델 적용 사항
	USB_DevInit();

	if(bSWreset)
	{
		mUsbSoftRstSet();
		while (wFOTGPeri_Port(0x100) & BIT4);
	}

	NVIC_ClearPendingIRQ(USB_IRQn);
	SCRB->USB_INTR_CLR.ulBulk = 0x7; // USB CM3 Internal Interrupt clear!!
	NVIC_EnableIRQ (USB_IRQn);
	NVIC_SetPriority(USB_IRQn, USB_IRQn_Priority);
#else
	USB_DevInit(); // Must Call this function since include application info initialize.
#endif
	//ETC
	HAL_PendSVHandlerInitialize();

	I2C_Initialize();
#if USED_TPIC_VCOM_LEVEL_I2CM_CONTROL
	I2CM_Initialize();
#endif /* USED_TPIC_VCOM_LEVEL_I2CM_CONTROL */

	protocol_init();
}

tGPIO_CtrlReg_t * _GPIO;
void module_HW_Init(void)
{
	_GPIO = GPIO;
	/*
	 * For Debug Pin
	 */

	GPIO_Init(_GPIO_TP_INTR, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);

	module_MspiBuff_Init();
	module_System_Init();
	module_Protocol_Init();
	init_DSP_B();
	DSPA_Initialize();
}

bool_t module_Start(void)
{
	bool_t retVal = YES;

	retVal = Hal_sric_start(NO);

	return retVal;
}

void module_Stop(bool_t bIsVCCOff)
{
#if USED_ECLK_ON_OFF_CONTROL
	HAL_SetECLKOnOffControl(NO);
#endif /* USED_ECLK_ON_OFF_CONTROL */
#if USED_TPIC_MUXEN_ON_OFF_CONTROL
	HAL_SetTPICMuxEnControl(NO, bIsVCCOff);
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
#if USED_TPIC_PENEN_ON_OFF_CONTROL
	HAL_SetTPICPenEnControl(NO);
#endif /* USED_TPIC_PENEN_ON_OFF_CONTROL */
#if USED_TOUCH_REPORT_ON_OFF_CONTROL
	HAL_SetTouchReportEnControl(NO);
#endif /* USED_TOUCH_REPORT_ON_OFF_CONTROL */
#if USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE
	HAL_SetHoppBaselineContinueEnControl(NO);
#endif /* USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE */
//	GPIO_Init(_GPIO_TSYNC_OUT, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);

	tPWM_INTR_CFG_t tPWM_INTR_CFG[4] =
	{
		{VSYNC_IN_IRQn, VSYNC_IN_IRQn_Priority, DISABLE},
		{TSYNC_IN_IRQn, TSYNC_IN_IRQn_Priority, DISABLE},
		{TSYNC_OUT_IRQn, TSYNC_OUT_IRQn_Priority, DISABLE},
		{PWMDRV_IRQn, PWMDRV_IRQn_Priority, DISABLE}
	};
	PWMDRV_ITConfig((tPWM_INTR_CFG_t *)&tPWM_INTR_CFG[0], 4);

	NVIC_DisableIRQ(GPIOA_IRQn);
	NVIC_DisableIRQ(GPIOM_IRQn);
	MSPI_ITConfig(DISABLE);
	MSPI_Cmd(DISABLE);
	PWMDRV_Cmd(DISABLE);

	SCRB->SYS_RST_CTL.tBit.pwm_rst = 1;
	SCRB->SYS_RST_CTL.tBit.pwm_rst = 0;

	PARAM_SetMode(PARAM_MODE_NONE);
}

void module_Watch_Enable(void)
{
	Hal_WDT_Init();
}

extern __IO bool_t wdt_init;
void module_Watch_Disable(void)
{
	if(wdt_init)
	{
		Hal_WDT_DeInit();
	}
}

bool_t module_Init_Signal(void)
{
	bool_t bReg = NO;
	module_Watch_Disable();

#if USED_TP_LCD_ON_OPERATION
	module_Init_LcdOn();
#endif /* USED_TP_LCD_ON_OPERATION */

	module_Init_TPEN();
#if USED_TP_RST_OPERATION
	module_Init_TPRST();
#endif /* USED_TP_RST_OPERATION */

#if USED_TOUCH_SLEEP_CTRL_BY_HOST
	module_Init_TOUCH_SLEEP();
#endif /* USED_TOUCH_SLEEP_CTRL_BY_HOST */

#if USED_MNT_S3_MODE_FUNCTION
	initMNT_S3_MODE_GPIO();

	if(module_Check_S3_Power())
	{
		module_RollBack_Sync();
		bReg = YES;
	}

	/*
	 * S3모드 진입 하게 될 경우 Signal Out이 High여야지만 PMIC가 구동 되면서 LCD_ON이 High가 됨!!
	 */
#else /* USED_MNT_S3_MODE_FUNCTION */
	{
	#if USED_TP_RSTnLCDON_DOUBLE_OPERATION
		if(module_Wait_TPRST() && module_Wait_LcdOn())
		{
			module_RollBack_Sync();
			GPIO_Set_INT(_GPIO_TP_RST, GPIO_INTEN_DISABLE, GPIO_INTTYPE_DISABLE);
			initBoardGPIO();
			return YES;
		}
	#elif USED_TP_RST_OPERATION
		if(module_Wait_TPRST())
		{
			module_RollBack_Sync();
			GPIO_Set_INT(_GPIO_TP_RST, GPIO_INTEN_DISABLE, GPIO_INTTYPE_DISABLE);
			initBoardGPIO();
			return YES;
		}
	#elif USED_TP_LCD_ON_OPERATION
		{
		#if USED_TOUCH_SLEEP_CTRL_BY_HOST
			if(module_Wait_LcdOn() && module_Wait_TOUCH_SLEEP())
			{
				module_RollBack_Sync();
				GPIO_Set_INT(_GPIO_SLEEP_EN, GPIO_INTEN_DISABLE, GPIO_INTTYPE_DISABLE);
				return YES;
			}
		#else /* USED_TOUCH_SLEEP_CTRL_BY_HOST */
			if(module_Wait_LcdOn())
			{
				module_RollBack_Sync();
				initBoardGPIO();
				return YES;
			}
		#endif /* USED_TOUCH_SLEEP_CTRL_BY_HOST */
		}
	#endif /* USED_TP_RSTnLCDON_DOUBLE_OPERATION */
	}
#endif /* USED_MNT_S3_MODE_FUNCTION */

	return bReg;
}

#if USED_SMT_OP_MODE
bool_t module_Check_SMT_Mode(void)
{
	if(IS_GPIO_PIN(_GPIO_SWCLK) == 0x00 && IS_GPIO_PIN(_GPIO_SWDIO) == 0x00)
	{
		return YES;
	}
	return NO;
}

void module_Enter_SMT_Mode(void)
{
	GPIO_Init(_GPIO_PWM_SRIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_PWM_TPIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#ifndef MODE_I2C
	NVIC_SetPendingIRQ(I2C_SLV_IRQn);
	NVIC_DisableIRQ(I2C_SLV_IRQn);    /* Interrupt Disable */

	GPIO_Init(_GPIO_SLV_SCL, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_SLV_SDA, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_TP_INTR, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
#endif /* #ifndef MODE_I2C */
}

void module_Exit_SMT_Mode(void)
{
#ifndef MODE_I2C
	I2C_Initialize();
#endif /* #ifndef MODE_I2C */
}

void module_SignalOut_SMT_Mode(void)
{
	delay_us(500);
	GPIO_Toggle(_GPIO_PWM_SRIC);
	GPIO_Toggle(_GPIO_PWM_TPIC);
}
#endif /* USED_SMT_OP_MODE */

#if USED_TP_LCD_ON_OPERATION
bool_t module_Check_LcdOn(void)
{
#if USED_OPERATION_STAND_ALONE
//	if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x0)
//	{
//		Hal_VccOff_State();
//		return NO;
//	}
	return YES;
#else /* USED_OPERATION_STAND_ALONE */
#if USED_FORCE_S3_MODE_OPER
//	if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x0)
	{
//		Hal_VccOff_State();
		return NO;
	}
#else /* USED_FORCE_S3_MODE_OPER */
	if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x0)
	{
		Hal_VccOff_State();
		return NO;
	}
#endif /* USED_FORCE_S3_MODE_OPER */

	return YES;
#endif /* USED_OPERATION_STAND_ALONE */
}
#endif /* USED_TP_LCD_ON_OPERATION */

bool_t module_Init_TPEN(void) // NOTE : missing return value
{
#if (CUSTOMER != MODEL_DEF_FHD_97500_MNT_S3)
	#if !DEF_TOUCH_SLEEP_CTRL_HOST_GPIO_TEST_TPEN
		GPIO_Init(_GPIO_TP_EN, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	#endif /* DEF_TOUCH_SLEEP_CTRL_HOST_GPIO_TEST_TPEN */
#endif /* (CUSTOMER != MODEL_DEF_FHD_97500_MNT_S3) */
	return YES;
}

bool_t module_Check_TPEN(void)
{
#if (CUSTOMER != MODEL_DEF_FHD_97500_MNT_S3)
	#if (!DEF_TOUCH_SLEEP_CTRL_HOST_GPIO_TEST_TPEN)
		if(IS_GPIO_PIN(_GPIO_TP_EN) == 0x0)
		{
			return YES;
		}
	#endif /* !DEF_TOUCH_SLEEP_CTRL_HOST_GPIO_TEST_TPEN */
#endif /* (CUSTOMER != MODEL_DEF_FHD_97500_MNT_S3) */
	return NO;
}

#if USED_TP_RST_OPERATION
void module_Init_TPRST(void)
{
	GPIO_Init(_GPIO_TP_RST, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	GPIO_Set_INT(_GPIO_TP_RST, GPIO_INTEN_ENABLE, GPIO_INTTYPE_BOTH_EDGE);
}

bool_t module_Check_TPRST(void)
{
	if(IS_GPIO_PIN(_GPIO_TP_RST) == 0x0)
	{
		return YES;
	}
	return NO;
}
#endif /* USED_TP_RST_OPERATION */

#if USED_TOUCH_SLEEP_CTRL_BY_HOST
void module_Init_TOUCH_SLEEP(void)
{
	GPIO_Init(_GPIO_SLEEP_EN, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	GPIO_Set_INT(_GPIO_SLEEP_EN, GPIO_INTEN_ENABLE, GPIO_INTTYPE_BOTH_EDGE);
}

bool_t module_Check_TOUCH_SLEEP(void)
{
	if(IS_GPIO_PIN(_GPIO_SLEEP_EN) == 0x0)
	{
		return YES;
	}
	return NO;
}
#endif /* USED_TOUCH_SLEEP_CTRL_BY_HOST */

#if USED_MNT_S3_MODE_FUNCTION
//#if USED_S3_SIGNAL_OUTPUT_CTRL
//void module_S3_Signal_OutPut_Enable(void)
//{
//
//}
//
//void module_S3_Signal_OutPut_Disable(void)
//{
//
//}
//#endif /* USED_S3_SIGNAL_OUTPUT_CTRL */

//#if USED_S3_VDD_OE_INPUT_OUTPUT_CTRL
//void module_Set_S3_VDD_OddEven_Ctrl(bool_t bIsEn)
//{
//	if(bIsEn == NO)
//	{
//		if(ptHalInfo->bIsS3VddOddEvenControlStart == YES)
//		{
//			GPIO_Set_DATA(_GPIO_MUX_EN_TPIC, GPIO_DATA_LOW);
//			GPIO_Init(_GPIO_VDDO_EVEN_CTRL, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
//			ptHalInfo->ucS3VddOddEvenStatus = GPIO_DATA_LOW;
//		}
//	}
//	else
//	{
//		if(ptHalInfo->bIsS3VddOddEvenControlStart == NO)
//		{
//			GPIO_Init(_GPIO_VDDO_EVEN_CTRL, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
//			ptHalInfo->bIsS3VddOddEvenControlStartCheckCnt = 0;
//			ptHalInfo->bIsS3VddOddEvenControlFrameCheckCnt = 0;
//			ptHalInfo->ucS3VddOddEvenStatus = GPIO_DATA_LOW;
//		}
//	}
//
//	ptHalInfo->bIsS3VddOddEvenControlStart = bIsEn;
//}
//
//bool_t module_Get_S3_VDD_OddEven_Ctrl(void)
//{
//	if(ptHalInfo->bIsS3VddOddEvenControlStartCheckCnt < TPIC_S3_VDD_OE_INPUT_OUTPUT_CTRL_START_CNT_THD)
//	{
//		ptHalInfo->bIsS3VddOddEvenControlStartCheckCnt++;
//	}
//
//	if(ptHalInfo->bIsS3VddOddEvenControlStartCheckCnt >= TPIC_S3_VDD_OE_INPUT_OUTPUT_CTRL_START_CNT_THD)
//	{
//		return ptHalInfo->bIsS3VddOddEvenControlStart;
//	}
//	else
//	{
//		return NO;
//	}
//}
//
//void module_Change_S3_VDD_OddEven_Stauts(void)
//{
//	if(module_Get_S3_VDD_OddEven_Ctrl())
//	{
//		if(ptHalInfo->bIsS3VddOddEvenControlFrameCheckCnt < TPIC_S3_VDD_OE_INPUT_OUTPUT_CTRL_FRAME_CNT_THD)
//		{
//			ptHalInfo->bIsS3VddOddEvenControlFrameCheckCnt++;
//		}
//
//		if(ptHalInfo->bIsS3VddOddEvenControlFrameCheckCnt >= TPIC_S3_VDD_OE_INPUT_OUTPUT_CTRL_FRAME_CNT_THD)
//		{
//			GPIO_Set_DATA(_GPIO_MUX_EN_TPIC, ptHalInfo->ucS3VddOddEvenStatus);
//			ptHalInfo->ucS3VddOddEvenStatus = (!ptHalInfo->ucS3VddOddEvenStatus);
//			ptHalInfo->bIsS3VddOddEvenControlFrameCheckCnt = 0;
//		}
//	}
//}
//#endif /* USED_S3_VDD_OE_INPUT_OUTPUT_CTRL */

#if USED_S3_PGAMMA_SW_I2C_CTRL
void module_S3_PGAMMA_I2C_SW_Enable(void)
{
	GPIO_Init(_GPIO_PGMA_SCL, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
	GPIO_Init(_GPIO_PGMA_SDL, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
	delay_us(10);
//	//Addr 0x74 //Data 0x00 0x02
//	GPIO->tGPIO_DATA_1.tBit.GPIOM10 = 1;
//	GPIO->tGPIO_AFIO_3.tBit.GPIOM10 = 0;
//	GPIO->tGPIO_DIR_1.tBit.GPIOM10 = 1;
//
//	GPIO->tGPIO_AFIO_2.tBit.GPIOM09 = 0;
//	GPIO->tGPIO_DIR_1.tBit.GPIOM09 = 1;
//	GPIO->tGPIO_DATA_1.tBit.GPIOM09 = 1;

	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(3);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	delay_us(2);
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data
	delay_us(3);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data
	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data
	delay_us(2);
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(2);

	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(4);

	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data
	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(6);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(2);
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data

	delay_us(10);
	GPIO_Init(_GPIO_PGMA_SCL, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	GPIO_Init(_GPIO_PGMA_SDL, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
}

void module_S3_PGAMMA_I2C_SW_Disable(void)
{
	GPIO_Init(_GPIO_PGMA_SCL, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
	GPIO_Init(_GPIO_PGMA_SDL, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
	delay_us(10);

//	//Addr 0x74 //Data 0x00 0x00
//	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;
//	GPIO->tGPIO_AFIO_3.tBit.GPIOM10 = 0;
//	GPIO->tGPIO_DIR_1.tBit.GPIOM10 = 1;
//
//	GPIO->tGPIO_AFIO_2.tBit.GPIOM09 = 0;
//	GPIO->tGPIO_DIR_1.tBit.GPIOM09 = 1;
//	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;

	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	delay_us(5);
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data
	delay_us(5);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data
	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data
	delay_us(2);
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(2);

	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(4);

	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(4);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 0;
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data
	//delay_us(2);
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 0;	// data
	delay_us(8);
	GPIO->GPIOM_OUT.tBit.GPIOM09 = 1;	delay_us(2);
	GPIO->GPIOM_OUT.tBit.GPIOM10 = 1;	// data

	delay_us(10);
	GPIO_Init(_GPIO_PGMA_SCL, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	GPIO_Init(_GPIO_PGMA_SDL, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
}
#endif /* USED_S3_PGAMMA_SW_I2C_CTRL */
#endif /* USED_MNT_S3_MODE_FUNCTION */

bool_t module_Skip_Event(void)
{
#if USED_DO_NOT_TOUCH_REPORT
	return YES;
#else /* USED_DO_NOT_TOUCH_REPORT */
#if USED_TOUCH_REPORT_ON_OFF_CONTROL
	if((module_Check_TPEN() == YES) || (HAL_GetTouchReportEnControl() == NO))
#else /* USED_TOUCH_REPORT_ON_OFF_CONTROL */
	if(module_Check_TPEN() == YES)
#endif /* USED_TOUCH_REPORT_ON_OFF_CONTROL */
	{
		return YES;
	}
	return NO;
#endif /* USED_DO_NOT_TOUCH_REPORT */
}

void module_start_delay(void)
{
#if USED_OPERATION_STAND_ALONE
	delay_msec(20);
#else /* USED_OPERATION_STAND_ALONE */
	GPIO_Init(_GPIO_VSYNC, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	int i=0;
#if ((USED_MODULE_DEF == MODULE_DEF_INX_1) && \
	(CUSTOMER == MODEL_DEF_FHD_92505_MS_FINGER_VBS))
	for(i=0; i<200; i++)
#else
	for(i=0; i<10; i++)
#endif
	{
		waitVsyncFalling();
	}
#endif /* USED_OPERATION_STAND_ALONE */
}

void module_wait_Vsync_signal(eSensingMode_t _mode, int _waitCnt)
{
    int gDiscardFrameCnt = 0;
    bool_t bIsWaitSkip = NO;
	while(1)
	{
		if(_mode == LOCAL_MODE)
		{
			ePartialSensing_t ePartialSensing;
			ePartialSensing = module_wait_local_sample_done();
			if(ePartialSensing == PARTIAL_MAX)
			{
				bIsWaitSkip = YES;
			}
		}
		else
		{
			if(!module_wait_full_sample_done())
			{
				bIsWaitSkip = YES;
			}
		}

		if(bIsWaitSkip)
		{
			break;
		}
		else if(tHalIntrHandle.ulVSyncFlag)
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
	#if USED_PEN_MODE_OPERATION
		tAlgorithmInfo_t *tAlgorithmInfo = algorithm_GetInfo();
		if(_Freq == thisCommonConf->MainFreq)
		{
			ptAppInfo->eSelectFreq = FREQ_MAIN;
			HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_MAIN_MODE);
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			if(tAlgorithmInfo->tPenInfo.bSearch_Mode_Flag == 0)
			{
				hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_HOPP_SETTABLE_BEACON);
			}
			else
			{
				hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_SETTABLE_BEACON);
			}
#endif
		}
		else if(_Freq == thisCommonConf->HoppFreq1)
		{
			ptAppInfo->eSelectFreq = FREQ_HOPP1;
			HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_HOP1_MODE);
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			if(tAlgorithmInfo->tPenInfo.bSearch_Mode_Flag == 0)
			{
				hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_HOPP_SETTABLE_BEACON);
			}
			else
			{
				hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_SETTABLE_BEACON);
			}
#endif
		}
//		else if(_Freq == thisCommonConf->HoppFreq2)
//		{
//			ptAppInfo->eSelectFreq = FREQ_HOPP2;
//		}
		else
		{
			ptAppInfo->eSelectFreq = FREQ_UNKNOWN;
		}
	#else /* USED_PEN_MODE_OPERATION */
		if(_Freq == thisCommonConf->MainFreq)
		{
			ptAppInfo->eSelectFreq = FREQ_MAIN;
			HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_MAIN_MODE);
		}
		else if(_Freq == thisCommonConf->HoppFreq1)
		{
			ptAppInfo->eSelectFreq = FREQ_HOPP1;
			HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_HOP1_MODE);
		}
//		else if(_Freq == thisCommonConf->HoppFreq2)
//		{
//			ptAppInfo->eSelectFreq = FREQ_HOPP2;
//		}
		else
		{
			ptAppInfo->eSelectFreq = FREQ_UNKNOWN;
		}
	#endif /* USED_PEN_MODE_OPERATION */

		retVal = TRUE;
	}

	return retVal;
}
#endif /* USED_NOISE_HOPPING_FREQ */

bool_t module_wait_full_sample_done(void)
{
#if USED_TP_LCD_ON_OPERATION
	bool_t sCheckVCC = YES;
#endif /* USED_TP_LCD_ON_OPERATION */
#if USED_TP_RST_OPERATION
	bool_t bCheckTPRST = YES;
#endif /* USED_TP_RST_OPERATION */
#if USED_TOUCH_SLEEP_CTRL_BY_HOST
	bool_t bCheckTOUCH_SLEEP = YES;
#endif /* USED_TOUCH_SLEEP_CTRL_BY_HOST */
	bool_t bLocalSample = YES;
//	bool_t bIsOneceWFIFlag = YES;
	eProtocolMode_t currMode = M_TOUCH_NORMAL;

	while(YES)
	{
#if USED_MNT_S3_MODE_FUNCTION
		if(sCheckVCC)
		{
			if(IS_GPIO_PIN(_GPIO_S3_POWER_IN) == 0x1)
			{
				sCheckVCC = YES;
			}
			else
			{
				sCheckVCC = NO;
			}
		}
		else
		{
//			Hal_VccOff_State();
//			SensingBufferInit();
			bLocalSample = NO;
			break;
		}

		if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
			if(sCheckVCC == YES)
			{
				module_read_full_sample_data();
				break;
			}
		}

		if(hal_get_irq_flag(IRQ_ID_NI_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_NI_SAMPLE);
		}

		if(hal_get_irq_flag(IRQ_ID_LOCAL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_LOCAL_SAMPLE);
		}

		if(hal_get_irq_flag(IRQ_ID_S3_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_S3_SAMPLE);
		}
#else /* USED_MNT_S3_MODE_FUNCTION */
	#if USED_TP_RSTnLCDON_DOUBLE_OPERATION
		if(sCheckVCC && bCheckTPRST)
		{
			if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
			{
				sCheckVCC = YES;
			}
			else
			{
				sCheckVCC = NO;
			}

			if(IS_GPIO_PIN(_GPIO_TP_RST) == 0x1)
			{
				bCheckTPRST = YES;
			}
			else
			{
				bCheckTPRST = NO;
			}
		}
		else
		{
			if(sCheckVCC == NO)
			{
				Hal_VccOff_State();
			}
			else if(bCheckTPRST == NO)
			{
				Hal_TPRSTOff_State();
			}
			SensingBufferInit();
			bLocalSample = NO;
			break;
		}

		if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
			if(sCheckVCC && bCheckTPRST)
			{
				module_read_full_sample_data();
				break;
			}
		}
	#else /* USED_TP_RSTnLCDON_DOUBLE_OPERATION */
		#if USED_TOUCH_SLEEP_CTRL_BY_HOST
		{
			if(sCheckVCC && bCheckTOUCH_SLEEP)
			{
				if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
				{
					sCheckVCC = YES;
				}
				else
				{
					sCheckVCC = NO;
				}

				if(IS_GPIO_PIN(_GPIO_SLEEP_EN) == 0x1)
				{
					bCheckTOUCH_SLEEP = YES;
				}
				else
				{
					bCheckTOUCH_SLEEP = NO;
				}
			}
			else
			{
				if(sCheckVCC == NO)
				{
					Hal_VccOff_State();
				}
				else if(bCheckTOUCH_SLEEP == NO)
				{
					Hal_TouchSleep_State();
				}
				SensingBufferInit();
				bLocalSample = NO;
				break;
			}

			if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
			{
				hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
				if(sCheckVCC && bCheckTOUCH_SLEEP)
				{
					module_read_full_sample_data();
					break;
				}
			}
		}
		#else /* USED_TOUCH_SLEEP_CTRL_BY_HOST */
		{
			#if USED_TP_RST_OPERATION
			if(bCheckTPRST)
			{
				if(IS_GPIO_PIN(_GPIO_TP_RST) == 0x1)
				{
					bCheckTPRST = YES;
				}
				else
				{
					bCheckTPRST = NO;
				}
			}
			else
			{
				Hal_TPRSTOff_State();
				SensingBufferInit();
				bLocalSample = NO;
				break;
			}

			if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
			{
				hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
				if(bCheckTPRST)
				{
					module_read_full_sample_data();
					break;
				}
			}

			#elif USED_TP_LCD_ON_OPERATION
			if(sCheckVCC)
			{
				if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
				{
					sCheckVCC = YES;
				}
				else
				{
					sCheckVCC = NO;
				}
			}
			else
			{
				Hal_VccOff_State();
				SensingBufferInit();
				bLocalSample = NO;
				break;
			}

			if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
			{
				hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
				if(sCheckVCC)
				{
					module_read_full_sample_data();
					break;
				}
			}
			#endif /* USED_TP_LCD_ON_OPERATION */
		}
		#endif /* USED_TOUCH_SLEEP_CTRL_BY_HOST */
	#endif /* USED_TP_RSTnLCDON_DOUBLE_OPERATION */

		if(hal_get_irq_flag(IRQ_ID_NI_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_NI_SAMPLE);
		}

		if(hal_get_irq_flag(IRQ_ID_LOCAL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_LOCAL_SAMPLE);
		}
#endif /* USED_MNT_S3_MODE_FUNCTION */

		currMode = protocol_swip_GetMode();
		if(currMode == M_TOUCH_DFUP || currMode == M_WATCH_DOG_RESET)
		{
			break;
		}

//		if(bIsOneceWFIFlag)
//		{
//			__WFI();
//		}
//		bIsOneceWFIFlag = NO;
	}

	return bLocalSample;
}

#if (USED_IDLE_MODE_CONTROL || USED_LOCAL_IDLE_MODE_CONTROL)
bool_t module_wait_NI_sample_done(void)
{
#if USED_TP_LCD_ON_OPERATION
	bool_t sCheckVCC = YES;
#endif /* USED_TP_LCD_ON_OPERATION */
#if USED_TP_RST_OPERATION
	bool_t bCheckTPRST = YES;
#endif /* USED_TP_RST_OPERATION */
#if USED_TOUCH_SLEEP_CTRL_BY_HOST
	bool_t bCheckTOUCH_SLEEP = YES;
#endif /* USED_TOUCH_SLEEP_CTRL_BY_HOST */
	bool_t bLocalSample = YES;
	eProtocolMode_t currMode = M_TOUCH_NORMAL;
//	bool_t bIsOneceWFIFlag = YES;
//	eSENSING_MODE_t eSensingMode;
//	eSensingMode = HAL_GetSensingMode();

	while(YES)
	{
#if USED_TP_RSTnLCDON_DOUBLE_OPERATION
		if(sCheckVCC && bCheckTPRST)
		{
			if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
			{
				sCheckVCC = YES;
			}
			else
			{
				sCheckVCC = NO;
			}

			if(IS_GPIO_PIN(_GPIO_TP_RST) == 0x1)
			{
				bCheckTPRST = YES;
			}
			else
			{
				bCheckTPRST = NO;
			}
		}
		else
		{
			if(sCheckVCC == NO)
			{
				Hal_VccOff_State();
			}
			else if(bCheckTPRST == NO)
			{
				Hal_TPRSTOff_State();
			}
			SensingBufferInit();
			bLocalSample = NO;
			break;
		}

		if(hal_get_irq_flag(IRQ_ID_NI_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_NI_SAMPLE);
			if(sCheckVCC && bCheckTPRST)
			{
				module_read_NI_sample_data();
				break;
			}
		}
#else /* USED_TP_RSTnLCDON_DOUBLE_OPERATION */
	#if USED_TOUCH_SLEEP_CTRL_BY_HOST
		if(sCheckVCC && bCheckTOUCH_SLEEP)
		{
			if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
			{
				sCheckVCC = YES;
			}
			else
			{
				sCheckVCC = NO;
			}

			if(IS_GPIO_PIN(_GPIO_SLEEP_EN) == 0x1)
			{
				bCheckTOUCH_SLEEP = YES;
			}
			else
			{
				bCheckTOUCH_SLEEP = NO;
			}
		}
		else
		{
			if(sCheckVCC == NO)
			{
				Hal_VccOff_State();
			}
			else if(bCheckTOUCH_SLEEP == NO)
			{
				Hal_TouchSleep_State();
			}
			SensingBufferInit();
			bLocalSample = NO;
			break;
		}

		if(hal_get_irq_flag(IRQ_ID_NI_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_NI_SAMPLE);
			if(sCheckVCC && bCheckTOUCH_SLEEP)
			{
				module_read_NI_sample_data();
				break;
			}
		}
	#else /* USED_TOUCH_SLEEP_CTRL_BY_HOST */
		#if USED_TP_RST_OPERATION
		{
			if(bCheckTPRST)
			{
				if(IS_GPIO_PIN(_GPIO_TP_RST) == 0x1)
				{
					bCheckTPRST = YES;
				}
				else
				{
					bCheckTPRST = NO;
				}
			}
			else
			{
				Hal_TPRSTOff_State();
				SensingBufferInit();
				bLocalSample = NO;
				break;
			}

			if(hal_get_irq_flag(IRQ_ID_NI_SAMPLE))
			{
				hal_clear_irq_flag(IRQ_ID_NI_SAMPLE);
				if(bCheckTPRST)
				{
					module_read_NI_sample_data();
					break;
				}
			}
		}
		#elif USED_TP_LCD_ON_OPERATION
		{
			if(sCheckVCC)
			{
				if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
				{
					sCheckVCC = YES;
				}
				else
				{
					sCheckVCC = NO;
				}
			}
			else
			{
				Hal_VccOff_State();
				SensingBufferInit();
				bLocalSample = NO;
				break;
			}

			if(hal_get_irq_flag(IRQ_ID_NI_SAMPLE))
			{
				hal_clear_irq_flag(IRQ_ID_NI_SAMPLE);
				if(sCheckVCC)
				{
					module_read_NI_sample_data();
					break;
				}
			}
		}
		#endif /* USED_TP_LCD_ON_OPERATION */
	#endif /* USED_TOUCH_SLEEP_CTRL_BY_HOST */
#endif /* USED_TP_RSTnLCDON_DOUBLE_OPERATION */

		if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
		}

		if(hal_get_irq_flag(IRQ_ID_LOCAL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_LOCAL_SAMPLE);
		}

#if USED_TOUCH_REPORT_ON_OFF_CONTROL
	#ifdef MODE_I2C
		if(HAL_GetTouchReportEnControl())
		{
			__WFI();
		}
	#endif
#endif /* USED_TOUCH_REPORT_ON_OFF_CONTROL */

		currMode = protocol_swip_GetMode();
		if(currMode == M_TOUCH_DFUP || currMode == M_WATCH_DOG_RESET)
		{
			break;
		}
	}

	return bLocalSample;
}
#endif /* (USED_IDLE_MODE_CONTROL || USED_LOCAL_IDLE_MODE_CONTROL) */

#if USED_MNT_S3_MODE_FUNCTION
#if USED_S3_WAKEUP_DEBUGING
extern uint32_t ulTestS3RawDataRead;
#endif
bool_t module_wait_S3_sample_done(void)
{
	bool_t sCheckVCC = YES;
	bool_t bLocalSample = YES;
//	bool_t bIsOneceWFIFlag = YES;
//	eSENSING_MODE_t eSensingMode;
//	eSensingMode = HAL_GetSensingMode();

	while(YES)
	{
		if(sCheckVCC)
		{
			if(IS_GPIO_PIN(_GPIO_S3_POWER_IN) == 0x0)
			{
				sCheckVCC = YES;
			}
			else
			{
				sCheckVCC = NO;
			}
		}
		else
		{
			bLocalSample = NO;
			break;
		}

		if(hal_get_irq_flag(IRQ_ID_S3_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_S3_SAMPLE);
			if(sCheckVCC)
			{
	#if USED_S3_WAKEUP_DEBUGING
				if(ulTestS3RawDataRead == YES)
	#endif
				module_read_S3_sample_data();
				break;
			}
		}

		if(hal_get_irq_flag(IRQ_ID_NI_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_NI_SAMPLE);
		}

		if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
		}

		if(hal_get_irq_flag(IRQ_ID_LOCAL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_LOCAL_SAMPLE);
		}
//		__WFI();
	}

	return bLocalSample;
}
#endif /* USED_MNT_S3_MODE_FUNCTION */

ePartialSensing_t module_wait_local_sample_done(void)
{
#if USED_TP_LCD_ON_OPERATION
	bool_t sCheckVCC = YES;
#endif /* USED_TP_LCD_ON_OPERATION */
#if USED_TP_RST_OPERATION
	bool_t bCheckTPRST = YES;
#endif /* USED_TP_RST_OPERATION */
	ePartialSensing_t RetVal = PARTIAL_PEN_BEACON;
//	bool_t bIsOneceWFIFlag = YES;

	while(YES)
	{
#if USED_TP_RSTnLCDON_DOUBLE_OPERATION
		if(sCheckVCC && bCheckTPRST)
		{
			if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
			{
				sCheckVCC = YES;
			}
			else
			{
				sCheckVCC = NO;
			}

			if(IS_GPIO_PIN(_GPIO_TP_RST) == 0x1)
			{
				bCheckTPRST = YES;
			}
			else
			{
				bCheckTPRST = NO;
			}
		}
		else
		{
			if(sCheckVCC == NO)
			{
				Hal_VccOff_State();
			}
			else if(bCheckTPRST == NO)
			{
				Hal_TPRSTOff_State();
			}
			SensingBufferInit();
			RetVal = PARTIAL_MAX;
			break;
		}

		if(hal_get_irq_flag(IRQ_ID_LOCAL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_LOCAL_SAMPLE);
			if(sCheckVCC && bCheckTPRST)
			{
				RetVal = hal_get_LocalType_flag();
				hal_clear_LocalType_flag();
				break;
			}
		}
#else /* USED_TP_RSTnLCDON_DOUBLE_OPERATION */
	#if USED_TP_RST_OPERATION
		if(bCheckTPRST)
		{
			if(IS_GPIO_PIN(_GPIO_TP_RST) == 0x1)
			{
				bCheckTPRST = YES;
			}
			else
			{
				bCheckTPRST = NO;
			}
		}
		else
		{
			Hal_TPRSTOff_State();
			SensingBufferInit();
			RetVal = PARTIAL_MAX;
			break;
		}

		if(hal_get_irq_flag(IRQ_ID_LOCAL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_LOCAL_SAMPLE);
			if(bCheckTPRST)
			{
				RetVal = hal_get_LocalType_flag();
				hal_clear_LocalType_flag();
				break;
			}
		}
	#elif USED_TP_LCD_ON_OPERATION
		if(sCheckVCC)
		{
			if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
			{
				sCheckVCC = YES;
			}
			else
			{
				sCheckVCC = NO;
			}
		}
		else
		{
			Hal_VccOff_State();
			SensingBufferInit();
			RetVal = PARTIAL_MAX;
			break;
		}

		if(hal_get_irq_flag(IRQ_ID_LOCAL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_LOCAL_SAMPLE);
			if(sCheckVCC)
			{
				RetVal = hal_get_LocalType_flag();
				hal_clear_LocalType_flag();
				break;
			}
		}
	#endif /* USED_TP_LCD_ON_OPERATION */
#endif /* USED_TP_RSTnLCDON_DOUBLE_OPERATION */

		if(hal_get_irq_flag(IRQ_ID_FULL_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_FULL_SAMPLE);
		}

		if(hal_get_irq_flag(IRQ_ID_NI_SAMPLE))
		{
			hal_clear_irq_flag(IRQ_ID_NI_SAMPLE);
		}
//		if(bIsOneceWFIFlag)
//		{
//			__WFI();
//		}
//		bIsOneceWFIFlag = NO;
	}

	return RetVal;
}

void module_wait_local_sample_last_done(void)
{
	ePartialSensing_t RetVal = PARTIAL_PEN_BEACON;
	while (YES)
	{
		RetVal = module_wait_local_sample_done();

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		if((RetVal == LOCAL_OP_LAST_LHB && OP_TYPE == ACTIVEPEN_TYPE_LOCAL_MS) || (RetVal == LOCAL_OP_2_LAST_LHB && OP_TYPE == ACTIVEPEN_TYPE_LOCAL_WGP))
#else
		if(RetVal == LOCAL_OP_LAST_LHB || RetVal == PARTIAL_MAX)
#endif
		{
			break;
		}
	}
}

#if (USED_PEN_MODE_OPERATION)
void module_read_full_sample_data(void)
{
	int c, r;
	int width = COL_MAX;
	int height = ROW_MAX;
	volatile unsigned long uiBaseAddr = BASE_RAW_SRAM;

	for (r = 0 ; r < height ; ++r)
	{
		for (c = 0 ; c < width ; ++c)
		{
			HAL_WRITE_RAW_IMAGE(r, c, *((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[r][c] + uiBaseAddr))));
		}
	}
}

#if (USED_IDLE_MODE_CONTROL || USED_LOCAL_IDLE_MODE_CONTROL)
void module_read_NI_sample_data(void)
{
	int c, r;
	int width = COL_MAX;
	int height = NI_ROW_MAX;
	volatile unsigned long uiBaseAddr = BASE_RAW_SRAM;

	for (r = 0 ; r < height ; ++r)
	{
		for (c = 0 ; c < width ; ++c)
		{
			HAL_WRITE_RAW_IMAGE(r, c, *((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[r][c] + uiBaseAddr))));
		}
	}
}
#endif /* (USED_IDLE_MODE_CONTROL || USED_LOCAL_IDLE_MODE_CONTROL) */

#if USED_MSPEN_MSPI_24BIT_TRANSMODE
volatile uint32_t PenCoordMSPIdata;
#endif /* USED_MSPEN_MSPI_24BIT_TRANSMODE */
volatile uint16_t PenCoordMSPIdata_1;
volatile uint16_t PenCoordMSPIdata_2;
volatile uint16_t PenCoordMSPIdata_3;
void module_read_local_finger_sample_data(ePartialSensing_t eLocalLHBType)
{
	uint32_t r, c;
	uint32_t width, height;
	uint32_t ulRealRowIndex;
#if USED_FINGER_DYNAMIC_MUX_SCAN_ORDER
	uint32_t ulFingerScanLHBOrderIdx;
#endif /* USED_FINGER_DYNAMIC_MUX_SCAN_ORDER */
	volatile unsigned long uiBaseAddr = BASE_RAW_SRAM;
	const tHalMspiControlConf_t * tHalMSPIControlConf = hal_mspi_GetControlConfig();
	eActivePenType_t eActivePenRawDataType = hal_Info_GetControlActivePenRawDataType();
	width = tHalMSPIControlConf->MSPI_BUF_Panel_ColNum;

	if (eLocalLHBType == LOCAL_FINGER_LAST_LHB)
	{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		if(hal_Info_GetControlLocalFingerOPType() != eActivePenRawDataType)
		{
			algorithm_baseline_init_FingerPoint();
			//To do ... May be use the separate Finger&Pen Param For MSnWGP, 20200707, HanCH 
		}
#endif
		
		hal_Info_SetControlLocalFingerOPType(eActivePenRawDataType);
	}

	switch(eLocalLHBType)
	{
		case PARTIAL_FINGER1:
		case PARTIAL_FINGER2:
		case PARTIAL_FINGER3:
		case PARTIAL_FINGER4:
		case PARTIAL_FINGER5:
		case PARTIAL_FINGER6:
		{
#if USED_FINGER_DYNAMIC_MUX_SCAN_ORDER
			ulFingerScanLHBOrderIdx = (uint32_t)(eLocalLHBType - PARTIAL_FINGER1);
			height = (LOCAL_FINGER_1MUX_ROW_NUM * LOCAL_FINGER_1LHB_SCAN_MUX_NUM);
			if(((ulFingerScanLHBOrderIdx + 1) * height) > ROW_MAX)
			{
				height = ((ulFingerScanLHBOrderIdx + 1) * height) - (ROW_MAX);
			}

			switch(eActivePenRawDataType)
			{
				case ACTIVEPEN_TYPE_LOCAL_MS:
				case ACTIVEPEN_TYPE_LOCAL_WGP:
				{
					for (r = 0 ; r < height ; ++r)
					{
						ulRealRowIndex = (tHalMSPIControlConf->tMspiFingerMuxScanOrder.ucLocalFingerMUXScanOrderIDX[ulFingerScanLHBOrderIdx][r/LOCAL_FINGER_1MUX_ROW_NUM] * LOCAL_FINGER_1MUX_ROW_NUM) + r%LOCAL_FINGER_1MUX_ROW_NUM;
						for (c = 0 ; c < width ; c++)
						{
							PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[r][c] + uiBaseAddr))));
							HAL_WRITE_LOCAL_FINGER_RAW_IMAGE(ulRealRowIndex, c, PenCoordMSPIdata_1);
						}
					}
					break;
				}
				case ACTIVEPEN_TYPE_LOCAL_WACOM:
				{
					break;
				}
				default:
					break;
			} /* switch(eActivePenOpType) */
#else /* USED_FINGER_DYNAMIC_MUX_SCAN_ORDER */
			switch(eActivePenRawDataType)
			{

	#if ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN))
				case ACTIVEPEN_TYPE_LOCAL_MS:
				{
					height = LOCAL_FINGER_1MUX_ROW_NUM * LOCAL_FINGER_1LHB_SCAN_MUX_NUM;
					ulRealRowIndex = ((uint32_t)(eLocalLHBType - PARTIAL_FINGER1)*height);

					if(ulRealRowIndex + height > ROW_MAX)
					{
						height = ROW_MAX - ulRealRowIndex;
					}

					for (r = 0 ; r < height ; ++r)
					{
						for (c = 0 ; c < width ; c++)
						{
							PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[r][c] + uiBaseAddr))));
							HAL_WRITE_LOCAL_FINGER_RAW_IMAGE(ulRealRowIndex, c, PenCoordMSPIdata_1);
						}
						ulRealRowIndex++;
					}
					break;
				}
	#endif /* ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)) */
				case ACTIVEPEN_TYPE_LOCAL_WGP:
				{
	#if IS_WGPUHDPEN_PROTOCOL_OPERATION
		#if (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_UHD_PEN)
					height = LOCAL_FINGER_1MUX_ROW_NUM * LOCAL_FINGER_1LHB_SCAN_MUX_NUM;
					ulRealRowIndex = ((uint32_t)(eLocalLHBType - PARTIAL_FINGER1)*height);
			#if USED_WGP_PEN_UHD_16LHB_OPERATION
					if(eLocalLHBType == LOCAL_FINGER_LAST_LHB)
					{
						height = 8;
					}
			#endif /* USED_WGP_PEN_UHD_16LHB_OPERATION */
		#else
					height = LOCAL_FINGER_1MUX_ROW_NUM * LOCAL_FINGER_1LHB_SCAN_MUX_NUM;
					ulRealRowIndex = ((uint32_t)(eLocalLHBType - PARTIAL_FINGER1)*height);
					if(eLocalLHBType == LOCAL_FINGER_LAST_LHB)
					{
						height = 21;
					}
		#endif
	#else /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
					height = (LOCAL_FINGER_1MUX_ROW_NUM * LOCAL_FINGER_1LHB_SCAN_MUX_NUM);
					ulRealRowIndex = ((uint32_t)(eLocalLHBType - PARTIAL_FINGER1)*height);
	#endif /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
					if(ulRealRowIndex + height > ROW_MAX)
					{
						height = ROW_MAX - ulRealRowIndex;
					}

					for (r = 0 ; r < height ; ++r)
					{
						for (c = 0 ; c < width ; c++)
						{
							PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[r][c] + uiBaseAddr))));
							HAL_WRITE_LOCAL_FINGER_RAW_IMAGE(ulRealRowIndex, c, PenCoordMSPIdata_1);
						}
						ulRealRowIndex++;
					}
					break;
				}
			} /* switch(eActivePenOpType) */
#endif /* USED_FINGER_DYNAMIC_MUX_SCAN_ORDER */
			break;
		}
		default:
			break;
	} /* switch(eLocalLHBType) */
}

#if IS_WGPPEN_PROTOCOL_OPERATION || ((IS_MULTI_PROTOCOL_OPERATION || IS_MSPEN_PROTOCOL_OPERATION) && USED_MPP_Pen_Protocol_Process_Change == NO)
void module_read_local_penposition_sample_data(ePartialSensing_t eLocalLHBType)
{
	uint32_t r, c;
	uint32_t width, height;
	uint32_t ulMSPIRowIndex;
	volatile uint32_t ulSensingDoneRowStart = 0;
	volatile unsigned long uiBaseAddr = BASE_RAW_SRAM;
	const tHalMspiControlConf_t * tHalMSPIControlConf = hal_mspi_GetControlConfig();
	eActivePenType_t eActivePenRawDataType = hal_Info_GetControlActivePenRawDataType();
	width = tHalMSPIControlConf->MSPI_BUF_Panel_ColNum;
	ulSensingDoneRowStart = tHalIntrHandle.ulLocalSensingDoneRowIdx;

	gAlgoRawDataType = eActivePenRawDataType;
	
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	algorithm_param_change_check();
	#endif
	
	switch(eLocalLHBType)
	{
		#ifdef PEN_POS1_DAT1_Replacement
		case PARTIAL_PEN_DATA1:
		#else
		case PARTIAL_PEN_COORD1:
		#endif
		case PARTIAL_PEN_COORD2:
		case PARTIAL_PEN_COORD3:
		case PARTIAL_PEN_COORD4:
		{
		#if IS_MULTI_PROTOCOL_OPERATION
			switch(eActivePenRawDataType)
			{
				case ACTIVEPEN_TYPE_LOCAL_MS:
				{
		#endif /* IS_MULTI_PROTOCOL_OPERATION */
		#if IS_MSPEN_PROTOCOL_OPERATION
					height = 10;
			#ifdef PEN_POS1_DAT1_Replacement
					int r_offset = 0;
					if(eLocalLHBType == PARTIAL_PEN_DATA1)r_offset=PEN_POS1_DAT1_Replacement;
					for (r = 0+r_offset; r < height+r_offset; ++r)
			#else
					for (r = 0; r < height; ++r)
			#endif
					{
						ulMSPIRowIndex = ((r + ulSensingDoneRowStart) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
						for (c = 0; c < width; c++)
						{
							PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
			#ifdef PEN_POS1_DAT1_Replacement
							HAL_WRITE_LOCAL_RAW_IMAGE(r-r_offset, c, PenCoordMSPIdata_1);
			#else
							HAL_WRITE_LOCAL_RAW_IMAGE(r, c, PenCoordMSPIdata_1);
			#endif
						}
					}

					if(PARTIAL_PEN_COORD3 == eLocalLHBType || PARTIAL_PEN_COORD1 == eLocalLHBType)
					{
						for (r = 20; r < 30; ++r)
						{
							//ulMSPIRowIndex = ((r + ulSensingDoneRowStart) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
							ulMSPIRowIndex = ((r + tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
							for (c = 0; c < width; c++)
							{
								PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
								HAL_WRITE_LOCAL_RING_RAW_IMAGE(r-20, c, PenCoordMSPIdata_1);
							}
						}
					}
		#endif /* IS_MSPEN_PROTOCOL_OPERATION */
		#if IS_MULTI_PROTOCOL_OPERATION
					break;
				}
		#endif /* IS_MULTI_PROTOCOL_OPERATION */
		#if IS_MULTI_PROTOCOL_OPERATION
				case ACTIVEPEN_TYPE_LOCAL_WGP:
				{
		#endif /* IS_MULTI_PROTOCOL_OPERATION */
		#if IS_WGPPEN_PROTOCOL_OPERATION
					height = 10;
					for (r = 0; r < height; ++r)
					{
						ulMSPIRowIndex = ((r + ulSensingDoneRowStart) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
						for (c = 0; c < width; c++)
						{
							PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
							HAL_WRITE_LOCAL_RAW_IMAGE(r, c, PenCoordMSPIdata_1);
						}
					}
		#endif /* IS_WGPPEN_PROTOCOL_OPERATION */
		#if IS_MULTI_PROTOCOL_OPERATION
					break;
				}
			}
		#endif /* IS_MULTI_PROTOCOL_OPERATION */

			break;
		}
	}
}
#endif /* IS_WGPPEN_PROTOCOL_OPERATION || ((IS_MULTI_PROTOCOL_OPERATION || IS_MSPEN_PROTOCOL_OPERATION) && USED_MPP_Pen_Protocol_Process_Change == NO) */

#if IS_WGPPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION
void module_read_local_pentilt_sample_data(ePartialSensing_t eLocalLHBType)
{
	uint32_t r, c;
	uint32_t width, height;
	uint32_t ulMSPIRowIndex;
	volatile uint32_t ulSensingDoneRowStart = 0;
	volatile unsigned long uiBaseAddr = BASE_RAW_SRAM;
	const tHalMspiControlConf_t * tHalMSPIControlConf = hal_mspi_GetControlConfig();
	eActivePenType_t eActivePenRawDataType = hal_Info_GetControlActivePenRawDataType();
	width = tHalMSPIControlConf->MSPI_BUF_Panel_ColNum;
	//ulSensingDoneRowStart = tHalIntrHandle.ulLocalSensingDoneRowIdx;
	ulSensingDoneRowStart = tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt;

	switch(eLocalLHBType)
	{
		case PARTIAL_TILT1:
		case PARTIAL_TILT2:
		{
			bool_t bIsRead = NO;
#if USED_TOUCH_TUNING_PROCESS
			switch(gtTuning_Ctrl_Type.ulTuning_Ctrl_PenTiltViewType)
			{
				case TUNING_CTRL_TYPE_PEN_TILT_VIEW_All:
				{
					bIsRead = YES;
					break;
				}
				case TUNING_CTRL_TYPE_PEN_TILT_VIEW_1:
				{
					if(eLocalLHBType == PARTIAL_TILT1)
					{
						bIsRead = YES;
					}
					break;
				}
				case TUNING_CTRL_TYPE_PEN_TILT_VIEW_2:
				{
					if(eLocalLHBType == PARTIAL_TILT2)
					{
						bIsRead = YES;
					}
					break;
				}
//				case TUNING_CTRL_TYPE_PEN_TILT_VIEW_3:
//				{
//					if(RetVal == PARTIAL_TILT3)
//					{
//							bIsRead = YES;
//					}
//					break;
//				}
//				case TUNING_CTRL_TYPE_PEN_TILT_VIEW_4:
//				{
//					if(RetVal == PARTIAL_TILT4)
//					{
//						bIsRead = YES;
//					}
//					break;
//				}
			}
#else /* USED_TOUCH_TUNING_PROCESS */
			bIsRead = YES;
#endif /* USED_TOUCH_TUNING_PROCESS */

			if(bIsRead)
			{
				switch(eActivePenRawDataType)
				{
//					case ACTIVEPEN_TYPE_LOCAL_MS:
//					{
//						break;
//					}
//					case ACTIVEPEN_TYPE_LOCAL_WACOM:
//					{
//						break;
//					}
					case ACTIVEPEN_TYPE_LOCAL_WGP:
					{
						uint8_t BaseOffset = thisModeConf->BaseLine.ucPP_MUX_Select * PEN_COORD_ROW_MAX;
	#if IS_WGPUHDPEN_PROTOCOL_OPERATION
		#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
						height = PEN_COORD_ROW_MAX + PEN_COORD_ROW_MAX;
		#else
						height = PEN_COORD_ROW_MAX;
		#endif
						for (r = 0; r < height; ++r)
						{
		#if USED_SPI_NBIT_TRANSMODE
							ulMSPIRowIndex = vclMSPIBufLocalRowIndexTable[ulSensingDoneRowStart%ROIC_ALIGNED_LOCAL_PEN_ROW_LEN][r%PEN_COORD_ROW_MAX] + ((r/PEN_COORD_ROW_MAX)*ROIC_ALIGNED_LOCAL_PEN_ROW_LEN);
							ulMSPIRowIndex += BaseOffset;
							for (c = 0; c < width; c++)
							{
								PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
								HAL_WRITE_LOCAL_RING_RAW_IMAGE(r, c, PenCoordMSPIdata_1);
							}
		#else
							ulMSPIRowIndex = ((r + ulSensingDoneRowStart) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
							ulMSPIRowIndex += BaseOffset;
							for (c = 0; c < width; c++)
							{
								PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
								HAL_WRITE_LOCAL_RING_RAW_IMAGE(r, c, PenCoordMSPIdata_1);
							}
		#endif
						}
	#else /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
						height = PEN_COORD_ROW_MAX;
						for (r = 0; r < height; ++r)
						{
							ulMSPIRowIndex = ((r + ulSensingDoneRowStart) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
							ulMSPIRowIndex += BaseOffset;
							for (c = 0; c < width; c++)
							{
								PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
								HAL_WRITE_LOCAL_RING_RAW_IMAGE(r, c, PenCoordMSPIdata_1);
							}
						}
	#endif /* IS_WGPUHDPEN_PROTOCOL_OPERATION */

						break;
					}
				}
			}

			break;
		}
	}
}
#endif /* IS_WGPPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION */

#if IS_WGPPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION || (IS_MSPEN_PROTOCOL_OPERATION && USED_MPP_Pen_Protocol_Process_Change == NO)
void module_read_local_pendata_sample_data(ePartialSensing_t eLocalLHBType)
{
	uint32_t r, c;
	uint32_t height;
//	uint32_t ulRealColIndex;
	uint32_t ulMSPIRowIndex;
	int32_t start_c, end_c;
	volatile uint32_t ulSensingDoneRowStart = 0;
	volatile unsigned long uiBaseAddr = BASE_RAW_SRAM;
	const tHalMspiControlConf_t * tHalMSPIControlConf = hal_mspi_GetControlConfig();
	eActivePenType_t eActivePenRawDataType = hal_Info_GetControlActivePenRawDataType();
//	width = tHalMSPIControlConf->MSPI_BUF_Panel_ColNum;
	ulSensingDoneRowStart = tHalIntrHandle.ulLocalSensingDoneRowIdx;

	gAlgoRawDataType = eActivePenRawDataType;

	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	algorithm_param_change_check();
	#endif
	
	switch(eLocalLHBType)
	{
		case PARTIAL_PEN_DATA1:
		case PARTIAL_PEN_DATA2:
		case PARTIAL_PEN_DATA3:
		case PARTIAL_PEN_DATA4:
		case PARTIAL_PEN_DATA5:
		{
			bool_t bIsRead = NO;
			bIsRead = YES;
			if(bIsRead)
			{
	#if IS_MULTI_PROTOCOL_OPERATION
				switch(eActivePenRawDataType)
				{
					case ACTIVEPEN_TYPE_LOCAL_MS:
					{
	#endif /* IS_MULTI_PROTOCOL_OPERATION */
		#if IS_MSPEN_PROTOCOL_OPERATION
						tAlgorithmInfo_t * pAlgorithmInfo = algorithm_GetInfo();
						start_c = pAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
						end_c = pAlgorithmInfo->tPenInfo.ucCurrentColumnEnd;
						height = 30;
						for (r = 0 ; r < height ; ++r)
						{
							ulMSPIRowIndex = ((r + ulSensingDoneRowStart) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
	//						ulRealColIndex = 0;
							for (c = start_c ; c <= end_c ; c++)
							{
								PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
								HAL_WRITE_LOCAL_DATA_RAW_IMAGE(r, c, PenCoordMSPIdata_1);
							}
						}
		#endif /* IS_MSPEN_PROTOCOL_OPERATION */
	#if IS_MULTI_PROTOCOL_OPERATION
						break;
					}
	#endif /* IS_MULTI_PROTOCOL_OPERATION */
	#if IS_MULTI_PROTOCOL_OPERATION
					case ACTIVEPEN_TYPE_LOCAL_WGP:
					{
	#endif /* IS_MULTI_PROTOCOL_OPERATION */
		#if IS_WGPPEN_PROTOCOL_OPERATION
						tAlgorithmInfo_t * pAlgorithmInfo = algorithm_GetInfo();
						start_c = pAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
						end_c = pAlgorithmInfo->tPenInfo.ucCurrentColumnEnd;
						height = 35;
						for (r = 0 ; r < height ; ++r)
						{
							ulMSPIRowIndex = ((r + ulSensingDoneRowStart) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
			#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
							ulMSPIRowIndex += PEN_COORD_ROW_MAX;
			#endif
			#if USED_TOUCH_TUNING_PROCESS
							for (c = 0 ; c < tHalMSPIControlConf->MSPI_BUF_Panel_ColNum ; c++)
			#else
							for (c = start_c ; c <= end_c ; c++)
			#endif
							{
								PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
								HAL_WRITE_LOCAL_DATA_RAW_IMAGE_3(r, c, PenCoordMSPIdata_1);
							}
						}
		#endif /* IS_WGPPEN_PROTOCOL_OPERATION */
		#if IS_MULTI_PROTOCOL_OPERATION
						break;
					}
				}
		#endif /* IS_MULTI_PROTOCOL_OPERATION */
			}

			break;
		}
	}
}
#endif /* IS_WGPPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION || (IS_MSPEN_PROTOCOL_OPERATION && USED_MPP_Pen_Protocol_Process_Change == NO) */

#if IS_WGPUHDPEN_PROTOCOL_OPERATION
void module_read_local_penposition_pendata_sample_data(ePartialSensing_t eLocalLHBType)
{
	uint32_t r, c;
	uint32_t width, height;
//	uint32_t ulRealColIndex;
	uint32_t ulMSPIRowIndex;
//	int32_t start_c, end_c;
	volatile uint32_t ulSensingDoneRowStart = 0;
	volatile unsigned long uiBaseAddr = BASE_RAW_SRAM;
	const tHalMspiControlConf_t * tHalMSPIControlConf = hal_mspi_GetControlConfig();
	eActivePenType_t eActivePenRawDataType = hal_Info_GetControlActivePenRawDataType();
	width = tHalMSPIControlConf->MSPI_BUF_Panel_ColNum;
	ulSensingDoneRowStart = tHalIntrHandle.ulLocalSensingDoneRowIdx;

	gAlgoRawDataType = eActivePenRawDataType;
	
	switch(eLocalLHBType)
	{
		case PARTIAL_PEN_COORD_DATA1:		// 1st Pen RAWDATA Check
		case PARTIAL_PEN_COORD_DATA2:		// 2nd Pen RAWDATA Check
		case PARTIAL_PEN_COORD_DATA3:		// 3rd Pen RAWDATA Check
		case PARTIAL_PEN_COORD_DATA4:		// 4th Pen RAWDATA Check
#if USED_WGP_PEN_UHD_16LHB_OPERATION
		case PARTIAL_PEN_COORD_DATA5:
		case PARTIAL_PEN_COORD_DATA6:
		case PARTIAL_PEN_COORD_DATA7:
		case PARTIAL_PEN_COORD_DATA8:
#endif /* USED_WGP_PEN_UHD_16LHB_OPERATION */
		{
			bool_t bIsRead = NO;
#if USED_TOUCH_TUNING_PROCESS
			switch(gtTuning_Ctrl_Type.ulTuning_Ctrl_PenPosViewType)
			{
				case TUNING_CTRL_TYPE_PEN_POS_VIEW_All:
				{
					bIsRead = YES;
					break;
				}
				case TUNING_CTRL_TYPE_PEN_POS_VIEW_1:
				{
					if(eLocalLHBType == PARTIAL_PEN_COORD_DATA1)
					{
						bIsRead = YES;
					}
					break;
				}
				case TUNING_CTRL_TYPE_PEN_POS_VIEW_2:
				{
					if(eLocalLHBType == PARTIAL_PEN_COORD_DATA2)
					{
						bIsRead = YES;
					}
					break;
				}
				case TUNING_CTRL_TYPE_PEN_POS_VIEW_3:
				{
					if(eLocalLHBType == PARTIAL_PEN_COORD_DATA3)
					{
						bIsRead = YES;
					}
					break;
				}
				case TUNING_CTRL_TYPE_PEN_POS_VIEW_4:
				{
					if(eLocalLHBType == PARTIAL_PEN_COORD_DATA4)
					{
						bIsRead = YES;
					}
					break;
				}
			}
#else /* USED_TOUCH_TUNING_PROCESS */
			bIsRead = YES;
#endif /* USED_TOUCH_TUNING_PROCESS */

			if(bIsRead)
			{
//				_gT(_GPIO_TP_INTR);
				switch(eActivePenRawDataType)
				{
					case ACTIVEPEN_TYPE_LOCAL_WGP:
					{
//						tAlgorithmInfo_t * pAlgorithmInfo = algorithm_GetInfo();
//						start_c = pAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
//						end_c = pAlgorithmInfo->tPenInfo.ucCurrentColumnEnd;
						height = PEN_DATA_ROW_MAX_3;
						for (r = 0; r < height; ++r)
						{
	#if USED_SPI_NBIT_TRANSMODE
							ulMSPIRowIndex = vclMSPIBufLocalRowIndexTable[ulSensingDoneRowStart%ROIC_ALIGNED_LOCAL_PEN_ROW_LEN][r%PEN_COORD_ROW_MAX] + ((r/PEN_COORD_ROW_MAX)*ROIC_ALIGNED_LOCAL_PEN_ROW_LEN);
		#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
							ulMSPIRowIndex += ROIC_ALIGNED_LOCAL_PEN_ROW_LEN;
		#endif
							for (c = 0; c < width; c++)
							{
								PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));

//	#if (!USED_TOUCH_TUNING_PROCESS)
//								if(c < 14)
//									PenCoordMSPIdata_1 = 1000;
//	#endif /* (!USED_TOUCH_TUNING_PROCESS) */

								HAL_WRITE_LOCAL_DATA_RAW_IMAGE_3(r, c, PenCoordMSPIdata_1);
							}
	#else
		#if IS_ROIC_DEF_SW92512
							ulMSPIRowIndex = ((r + ulSensingDoneRowStart) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
			#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
							ulMSPIRowIndex += ROIC_ALIGNED_LOCAL_PEN_ROW_LEN;
			#endif
							for (c = 0; c < width; c++)
							{
								PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
								HAL_WRITE_LOCAL_DATA_RAW_IMAGE_3(r, c, PenCoordMSPIdata_1);
							}
		#else
			#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
							ulMSPIRowIndex += ROIC_ALIGNED_LOCAL_PEN_ROW_LEN;
			#endif
							ulMSPIRowIndex = ((r + ulSensingDoneRowStart) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
							for (c = 0; c < width; c++)
							{
								PenCoordMSPIdata_1 = (*((volatile unsigned short *)((thisFixedConf->ulLocalSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
								HAL_WRITE_LOCAL_DATA_RAW_IMAGE_3(r, c, PenCoordMSPIdata_1);
							}
		#endif
	#endif
						}
						break;
					}
				}

			}

			break;
		}
	}
}
#endif /* IS_WGPUHDPEN_PROTOCOL_OPERATION */

#if (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) && (USED_MPP_Pen_Protocol_Process_Change == YES)
void module_read_local_penposition_pendata_sample_data(ePartialSensing_t eLocalLHBType)
{
	uint32_t r, c;
	uint32_t ulMSPIRowIndex;
	int32_t start_c, end_c;
	int32_t start_r, end_r;
	bool_t bIsIncludePenPos = NO;
	bool_t bIsIncludeRing = NO;
	uint16_t * pLocalPenPosImage;
	uint16_t * pLocalRingImage;
	uint16_t * pLocalDataImage;
	volatile uint32_t ulSensingDoneRowStart = 0;
	volatile unsigned long uiBaseAddr = BASE_RAW_SRAM;
	const tHalMspiControlConf_t * tHalMSPIControlConf = hal_mspi_GetControlConfig();
	eActivePenType_t eActivePenRawDataType = hal_Info_GetControlActivePenRawDataType();
	ulSensingDoneRowStart = tHalIntrHandle.ulLocalSensingDoneRowIdx;

	gAlgoRawDataType = eActivePenRawDataType;

	pLocalPenPosImage = HAL_GET_LOCAL_RAW_IMAGE_PTR();
	pLocalRingImage = HAL_GET_LOCAL_RING_RAW_IMAGE_PTR();
	pLocalDataImage = HAL_GET_LOCAL_DATA_RAW_IMAGE_PTR();

	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	algorithm_param_change_check();
	#endif

//	_gOut(_GPIO_TP_INTR, GPIO_DATA_LOW);

	switch(eLocalLHBType)
	{
		case PARTIAL_PEN_COORD_DATA1:
		case PARTIAL_PEN_COORD_DATA3:
		{
			bIsIncludeRing = YES;
		}
		/* no break */
		case PARTIAL_PEN_COORD_DATA2:
		case PARTIAL_PEN_COORD_DATA4:
		{
			bIsIncludePenPos = YES;
		}
		/* no break */
		case PARTIAL_PEN_DATA1:
		case PARTIAL_PEN_DATA2:
		case PARTIAL_PEN_DATA3:
		case PARTIAL_PEN_DATA4:
		{
//			bool_t bIsRead = NO;
//			bIsRead = YES;
//			if(bIsRead)
			{
				tAlgorithmInfo_t * pAlgorithmInfo = algorithm_GetInfo();
				start_c = pAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
				end_c = pAlgorithmInfo->tPenInfo.ucCurrentColumnEnd;
				start_r = 0;
				end_r = PEN_DATA_ROW_MAX;
				/*
				 * Pen Pos inculde Pen Data
				 */
				if(bIsIncludePenPos)
				{
					for(r = 0 ; r < (PEN_COORD_ROW_MAX<<1) ; ++r)
					{
						ulMSPIRowIndex = ((r + ulSensingDoneRowStart) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
						for (c = 0 ; c < COL_MAX ; c++)
						{
							pLocalPenPosImage[(r*COL_MAX) + c] = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
						}
					}
					start_r = (PEN_COORD_ROW_MAX<<1);
					end_r = PEN_DATA_ROW_MAX;
				}

				/*
				 * Ring include Pen Data;
				 */
				if(bIsIncludeRing)
				{
//					for(r = 0 ; r < (PEN_COORD_ROW_MAX<<1) ; ++r)
//					{
//						ulMSPIRowIndex = ((r + (PEN_COORD_ROW_MAX * 4) + tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt) % PEN_COORD_ROW_MAX) + (((r + (PEN_COORD_ROW_MAX * 4))/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
//						for (c = 0 ; c < COL_MAX ; c++)
//						{
//							pLocalRingImage[(r*COL_MAX) + c] = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
//						}
//					}
					for (r = 20; r < PEN_DATA_ROW_MAX; ++r)
					{
						ulMSPIRowIndex = ((r + tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
						for (c = 0; c < COL_MAX; c++)
						{
							pLocalRingImage[((r-20) *COL_MAX) + c] = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
						}
					}
					end_r = PEN_DATA_ROW_MAX - (PEN_COORD_ROW_MAX<<1);
				}

				/*
				 * Pen Data
				 */
				for (r = start_r ; r < end_r ; ++r)
				{
					ulMSPIRowIndex = ((r + ulSensingDoneRowStart) % PEN_COORD_ROW_MAX) + ((r/PEN_COORD_ROW_MAX)*PEN_COORD_ROW_MAX);
					for (c = start_c ; c <= end_c ; c++)
					{
						pLocalDataImage[(r*COL_MAX) + c] = (*((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[ulMSPIRowIndex][c] + uiBaseAddr))));
					}
				}
			}
			break;
		}
	}
//	_gOut(_GPIO_TP_INTR, GPIO_DATA_HIGH);
}
#endif /* (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) && (USED_MPP_Pen_Protocol_Process_Change == YES) */

#if USED_EVERY_VSYNC_TIMING_DYNAMIC_MATCHING
//uint32_t ulTestCount;
//uint32_t ulTestVSyncMatchingOperationEn;
//uint32_t bSyncMatchingCheckEn;
//tPenInfo_t * ptPenInfo;
extern void module_Check_VSync_Matching_Control(void)
{
	tPenInfo_t *ptPenInfo = &algorithm_GetInfo()->tPenInfo;
	ptPenInfo = &algorithm_GetInfo()->tPenInfo;
	bool_t bIsEnable = NO;

	bIsEnable = !((ptPenInfo->ucHover_cnt > DEF_EVERY_TSYNC_MATCHING_HOVER_CNT_THD) || ptPenInfo->bPenContact);

	if(bIsEnable)
	{
		/*
		 * This case is operation of Finger Only.
		 */
		if(tHalIntrHandle.ulVSyncTimingMatchingDisableCnt < DEF_EVERY_VSYNC_TIMING_DYNAMIC_MATCHING_CHANGE_CNT_THD)
		{
			tHalIntrHandle.ulVSyncTimingMatchingDisableCnt++;
		}
		else
		{
			tHalIntrHandle.bIsVSyncTimingMatching_En = YES;
			PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = NO;
			PWMDRV->VSYNC_CR.tBit.vsync_in_sel = PWM_VSYNC_INTR_EXTERNAL;
//			_gT(_GPIO_TP_INTR);
		}
	}
	else
	{
		/*
		 * This case is operation of Pen
		 */
		tHalIntrHandle.bIsVSyncTimingMatching_En = NO;
		PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = YES;
		PWMDRV->VSYNC_CR.tBit.vsync_in_sel = PWM_VSYNC_INTR_INTERNAL;
		if(ptPenInfo->bPenContact)
		{
			tHalIntrHandle.ulVSyncTimingMatchingDisableCnt = 0;
		}
		else
		{
			tHalIntrHandle.ulVSyncTimingMatchingDisableCnt = DEF_EVERY_VSYNC_TIMING_DYNAMIC_MATCHING_CHANGE_CNT_THD - DEF_EVERY_VSYNC_TIMING_DYNAMIC_MATCHING_Hysteresis_THD;
		}
	}
//	ulTestCount = tHalIntrHandle.ulVSyncTimingMatchingDisableCnt;
//	bSyncMatchingCheckEn = bIsEnable;
//	ulTestVSyncMatchingOperationEn = tHalIntrHandle.bIsVSyncTimingMatching_En;
}
#endif /* USED_EVERY_VSYNC_TIMING_DYNAMIC_MATCHING */

#else /* (USED_PEN_MODE_OPERATION) */

#if ((CUSTOMER == MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_Finger) || (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_PEN))
uint32_t ulRealRowIdx[ROW_MAX] =
{
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09 * 5)+2
};
#elif (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_Finger) || (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_FLIP_Finger)
uint32_t ulRealRowIdx[ROW_MAX] =
{
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08 * 5)+4,
	(PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09 * 5), (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09 * 5)+1, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09 * 5)+2, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09 * 5)+3, (PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09 * 5)+4,
};
#endif /* ((CUSTOMER == MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_Finger) || (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_Finger) || (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_PEN)) */

void module_read_full_sample_data(void)
{
	int c, r;
	int width = COL_MAX;
	int height = ROW_MAX;
	volatile unsigned long uiBaseAddr = BASE_RAW_SRAM;

	for (r = 0 ; r < height ; ++r)
	{
		for (c = 0 ; c < width ; ++c)
		{
	#if ((CUSTOMER == MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_Finger) || \
		(CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_Finger) || \
		(CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_FLIP_Finger) || \
		(CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_PEN))
			HAL_WRITE_RAW_IMAGE(ulRealRowIdx[r], c, *((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[r][c] + uiBaseAddr))));
	#else /* ((CUSTOMER == MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_Finger) || (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_Finger) || (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_PEN)) */
			HAL_WRITE_RAW_IMAGE(r, c, *((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[r][c] + uiBaseAddr))));
	#endif /* ((CUSTOMER == MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_Finger) || (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_Finger) || (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_PEN)) */
		}
	}
}

#if (USED_IDLE_MODE_CONTROL)
void module_read_NI_sample_data(void)
{
	int c, r;
	int width = COL_MAX;
	int height = NI_ROW_MAX;
	volatile unsigned long uiBaseAddr = BASE_RAW_SRAM;

	for (r = 0 ; r < height ; ++r)
	{
		for (c = 0 ; c < width ; ++c)
		{
			HAL_WRITE_RAW_IMAGE(r, c, *((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[r][c] + uiBaseAddr))));
		}
	}
}
#endif /* (USED_IDLE_MODE_CONTROL) */

#if USED_MNT_S3_MODE_FUNCTION
void module_read_S3_sample_data(void)
{
	int c, r;
	int width = COL_MAX;
	int height = NI_ROW_MAX;
	volatile unsigned long uiBaseAddr = BASE_RAW_SRAM;

	for (r = 0 ; r < height ; ++r)
	{
		for (c = 0 ; c < width ; ++c)
		{
			HAL_NI_WRITE_RAW_IMAGE(r, c, *((volatile unsigned short *)((thisFixedConf->ulFullSensing_Remap_Table[r][c] + uiBaseAddr))));
		}
	}
}
#endif /* USED_MNT_S3_MODE_FUNCTION */
#endif /* (USED_PEN_MODE_OPERATION) */


__IO bool_t gbIrqFlag[IRQ_ID_MAX] = { 0, };
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

__IO uint8_t gucOverlapFPend = 0;
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

__IO ePartialSensing_t gLocalTypeFlag  = PARTIAL_PEN_BEACON;
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

//volatile eNormalOperSubState_t gSubStateFlag  = TOUCH_NORMAL_OPER_NONCHANGE;
//void hal_set_SubState_flag(eNormalOperSubState_t _id)
//{
//	gSubStateFlag = _id;
//}
//
//void hal_clear_SubState_flag(void)
//{
//	gSubStateFlag = TOUCH_NORMAL_OPER_NONCHANGE;
//}
//
//eNormalOperSubState_t hal_get_SubState_flag(void)
//{
//	return gSubStateFlag;
//}

