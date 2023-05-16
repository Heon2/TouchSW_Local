/****************************************************************************************************//**
* Copyright (c) 2017 - 2025 SiliconWorks LIMITED
*
* file : hal.c
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


__IO tHalInterruptHandle_t tHalIntrHandle;
//static tHalInfo_t * ptHalInfo = NULL;
tHalInfo_t * ptHalInfo = NULL;
//__IO uint32_t gulTSyncSensingBitCheck;

void initBoardGPIO(void)
{
	// TSYNCN_OUT
	GPIO_Init(_GPIO_TSYNC_OUT, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
	
	// All DC
#ifdef _ALL_PWM_DC_
	GPIO_Init(_GPIO_PWM_TPIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
#endif


#if USED_GPIO_UPLINK_LEVEL_CONTROL
#if (DEF_UPLINK_CONTROL_OPERATION == DEF_UPLINK_HW_CONTROL)
	GPIO_Set_Mode(_GPIO_Uplink_GPIO, GPIO_MODE_FUNC_2);
#elif (DEF_UPLINK_CONTROL_OPERATION == DEF_UPLINK_SW_CONTROL)
	GPIO_Init(_GPIO_Uplink_GPIO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif /* (DEF_UPLINK_CONTROL_OPERATION == DEF_UPLINK_HW_CONTROL) */
#endif /* USED_GPIO_UPLINK_LEVEL_CONTROL */

//#if (USED_MODULE_DEF == MODULE_DEF_B_1)
//	GPIO_Init(_GPIO_MUX_EN_TPIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
//#else /* (USED_MODULE_DEF == MODULE_DEF_B_1) */
	GPIO_Init(_GPIO_MUX_EN_TPIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
//#endif /* (USED_MODULE_DEF == MODULE_DEF_B_1) */

#if USED_TPIC_MUXEN_2_ON_OFF_CONTROL
	GPIO_Init(_GPIO_MUX_EN2_TPIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
#endif /* USED_TPIC_MUXEN_2_ON_OFF_CONTROL */
}

#if USED_VCF_SYNC_CONTROL
void initVcfGPIO(void)
{
	// Input : PRIVACY_EN
	GPIO_Init(_GPIO_PRIVACY_EN, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
	GPIO_Set_PE(_GPIO_PRIVACY_EN, GPIO_PE_PULL_DOWM);
	
	// Output : VCF_SYNC
	GPIO_Init(_GPIO_VCF_SYNC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Set_PE(_GPIO_VCF_SYNC, GPIO_PE_PULL_DOWM);
	
	// Output : FLOATING_SYNC
	GPIO_Init(_GPIO_FLOAT_SYNC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Set_PE(_GPIO_FLOAT_SYNC, GPIO_PE_PULL_DOWM);
	
	// Output : DISCHARGE_SYNC
	GPIO_Init(_GPIO_DISCHG_SYNC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Set_PE(_GPIO_DISCHG_SYNC, GPIO_PE_PULL_DOWM);
}
#endif /* USED_VCF_SYNC_CONTROL */

#if USED_MNT_S3_MODE_FUNCTION
void initMNT_S3_MODE_GPIO(void)
{
#if USED_S3_POWER_INPUT_CHECK
	GPIO_Init(_GPIO_S3_POWER_IN, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
#endif /* USED_S3_POWER_INPUT_CHECK */

#if USED_S3_SIGNAL_OUTPUT_CTRL
	GPIO_Init(_GPIO_S3_SIGNAL_OUT, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif /* USED_S3_SIGNAL_OUTPUT_CTRL */
}
#endif /* USED_MNT_S3_MODE_FUNCTION */

void initECLK(void)
{
	const tHalPwmdrvCommonConf_t * pktHalPwmdrvCommonConf;
	pktHalPwmdrvCommonConf = hal_pwmdrv_GetCommonConfig();
	// 8. ECLK Configuration  
	GPIO_Set_Mode(_GPIO_ECLK_0, GPIO_MODE_FUNC_0);	// ECLK0
	GPIO_Set_DS(_GPIO_ECLK_0, USED_ECLK_DRIVING_STRENGTH);
#if USED_ECLK_1WAY_CONNECTION
	GPIO_Init(_GPIO_ECLK_1, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
#else
	GPIO_Set_Mode(_GPIO_ECLK_1, GPIO_MODE_FUNC_0);	// ECLK1
	GPIO_Set_DS(_GPIO_ECLK_1, USED_ECLK_DRIVING_STRENGTH);
#endif

//	SCRB->SYS_PWMCLK_CFG.tBit.pwmclkdiv_en = 0;	// PWMDRV_CLK off
	PWMDRV->ECLK_CR.ulBulk = pktHalPwmdrvCommonConf->tCP_ECLK_CR.ulBulk;
	PWMDRV->ECLK_CR.tBit.eclk_force_on = PWM_ECLK_ALWAYS_ON;			// ECLK always on. 0-TSYNC on/off
}

#if USED_VCF_SYNC_CONTROL
void HAL_SetPrivacyEnControl(bool_t bIsEn)
{
	ptHalInfo->bIsPrivacyEn = bIsEn;
}

bool_t HAL_GetPrivacyEnControl(void)
{
	return ptHalInfo->bIsPrivacyEn;
}
#endif /* USED_VCF_SYNC_CONTROL */

#if USED_ECLK_ON_OFF_CONTROL
void HAL_SetECLKOnOffControl(bool_t bIsEn)
{
	if(bIsEn == NO)
	{
		if(ptHalInfo->bIsECLKOnOffStart == YES)
		{
			HAL_ECLK_On();
		}
	}
	else
	{
		if(ptHalInfo->bIsECLKOnOffStart == NO)
		{
			ptHalInfo->bIsECLKOnOffStartCheckCnt = 0;
		}
	}

	ptHalInfo->bIsECLKOnOffStart = bIsEn;
}

bool_t HAL_GetECLKOnOffControl(void)
{
	if(ptHalInfo->bIsECLKOnOffStartCheckCnt < ECLK_ON_OFF_CONTROL_START_CNT_THD)
	{
		ptHalInfo->bIsECLKOnOffStartCheckCnt++;
	}

	if(ptHalInfo->bIsECLKOnOffStartCheckCnt >= ECLK_ON_OFF_CONTROL_START_CNT_THD)
	{
		return ptHalInfo->bIsECLKOnOffStart;
	}
	else
	{
		return NO;
	}
}

void HAL_ECLK_On(void)
{
#if USED_ECLK_FRQ_ADJUST_CONTROL
	/*
	 * Not Implementation
	 */
	PWMDRV->ECLK_CR.tBit.div_num = 0;
#else /* USED_ECLK_FRQ_ADJUST_CONTROL */
	tCP_ECLK_CR_t tCP_ECLK_CR_TMP;
	tCP_ECLK_CR_TMP.ulBulk = PWMDRV->ECLK_CR.ulBulk;
	tCP_ECLK_CR_TMP.tBit.eclk_en = DISABLE;
	tCP_ECLK_CR_TMP.tBit.eclk_force_on = ENABLE;
	PWMDRV->ECLK_CR.ulBulk = tCP_ECLK_CR_TMP.ulBulk;
#endif /* USED_ECLK_FRQ_ADJUST_CONTROL */
}

void HAL_ECLK_Off(void)
{
#if USED_ECLK_FRQ_ADJUST_CONTROL
	/*
	 * Not Implementation
	 */
	PWMDRV->ECLK_CR.tBit.div_num = 3;
#else /* USED_ECLK_FRQ_ADJUST_CONTROL */
	tCP_ECLK_CR_t tCP_ECLK_CR_TMP;
	tCP_ECLK_CR_TMP.ulBulk = PWMDRV->ECLK_CR.ulBulk;
	tCP_ECLK_CR_TMP.tBit.eclk_en = DISABLE;
	tCP_ECLK_CR_TMP.tBit.eclk_force_on = DISABLE;
	PWMDRV->ECLK_CR.ulBulk = tCP_ECLK_CR_TMP.ulBulk;
#endif /* USED_ECLK_FRQ_ADJUST_CONTROL */
}
#endif /* USED_ECLK_ON_OFF_CONTROL */

#if USED_TPIC_MUXEN_ON_OFF_CONTROL
void HAL_SetTPICMuxEnControl(bool_t bIsEn, bool_t bIsVCCOff)
{
	if(bIsEn == NO)
	{
		if(ptHalInfo->bIsTPICMuxEnOnOffStart == YES)
		{
			if(bIsVCCOff)
			{
				GPIO_Set_DATA(_GPIO_MUX_EN_TPIC, GPIO_DATA_LOW);
			}
			else
			{
				GPIO_Set_DATA(_GPIO_MUX_EN_TPIC, GPIO_DATA_HIGH);
			}
		}
	}
	else
	{
		if(ptHalInfo->bIsTPICMuxEnOnOffStart == NO)
		{
			ptHalInfo->bIsTPICMuxEnOnOffStartCheckCnt = 0;
		}
	}

	ptHalInfo->bIsTPICMuxEnOnOffStart = bIsEn;
}

bool_t HAL_GetTPICMuxEnControl(void)
{
	if(ptHalInfo->bIsTPICMuxEnOnOffStartCheckCnt < TPIC_MUXEN_ON_OFF_CONTROL_START_CNT_THD)
	{
		ptHalInfo->bIsTPICMuxEnOnOffStartCheckCnt++;
	}

	if(ptHalInfo->bIsTPICMuxEnOnOffStartCheckCnt >= TPIC_MUXEN_ON_OFF_CONTROL_START_CNT_THD)
	{
		return ptHalInfo->bIsTPICMuxEnOnOffStart;
	}
	else
	{
		return NO;
	}
}
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */

#if USED_S3_VDD_OE_INPUT_OUTPUT_CTRL
void HAL_Set_S3_VDD_OddEven_Ctrl(bool_t bIsEn)
{
	if(bIsEn == NO)
	{
		if(ptHalInfo->bIsS3VddOddEvenControlStart == YES)
		{
			GPIO_Set_DATA(_GPIO_VDDO_EVEN_CTRL, GPIO_DATA_LOW);
			GPIO_Init(_GPIO_VDDO_EVEN_CTRL, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
			ptHalInfo->ucS3VddOddEvenStatus = GPIO_DATA_LOW;
		}
	}
	else
	{
		if(ptHalInfo->bIsS3VddOddEvenControlStart == NO)
		{
			GPIO_Init(_GPIO_VDDO_EVEN_CTRL, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
			ptHalInfo->bIsS3VddOddEvenControlStartCheckCnt = 0;
			ptHalInfo->bIsS3VddOddEvenControlFrameCheckCnt = 0;
			ptHalInfo->ucS3VddOddEvenStatus = GPIO_DATA_LOW;
		}
	}

	ptHalInfo->bIsS3VddOddEvenControlStart = bIsEn;
}

bool_t HAL_Get_S3_VDD_OddEven_Ctrl(void)
{
	if(ptHalInfo->bIsS3VddOddEvenControlStartCheckCnt < TPIC_S3_VDD_OE_INPUT_OUTPUT_CTRL_START_CNT_THD)
	{
		ptHalInfo->bIsS3VddOddEvenControlStartCheckCnt++;
	}

	if(ptHalInfo->bIsS3VddOddEvenControlStartCheckCnt >= TPIC_S3_VDD_OE_INPUT_OUTPUT_CTRL_START_CNT_THD)
	{
		return ptHalInfo->bIsS3VddOddEvenControlStart;
	}
	else
	{
		return NO;
	}
}

void HAL_Change_S3_VDD_OddEven_Stauts(void)
{
	if(HAL_Get_S3_VDD_OddEven_Ctrl())
	{
		if(ptHalInfo->bIsS3VddOddEvenControlFrameCheckCnt < TPIC_S3_VDD_OE_INPUT_OUTPUT_CTRL_FRAME_CNT_THD)
		{
			ptHalInfo->bIsS3VddOddEvenControlFrameCheckCnt++;
		}

		if(ptHalInfo->bIsS3VddOddEvenControlFrameCheckCnt >= TPIC_S3_VDD_OE_INPUT_OUTPUT_CTRL_FRAME_CNT_THD)
		{
#if USED_S3_VDD_OE_INPUT_OUTPUT_ALWAYS_LOW_CTRL
			GPIO_Set_DATA(_GPIO_VDDO_EVEN_CTRL, GPIO_DATA_LOW);
#else /* USED_S3_VDD_OE_INPUT_OUTPUT_ALWAYS_LOW_CTRL */
			GPIO_Set_DATA(_GPIO_VDDO_EVEN_CTRL, (GPIODATA_TypeDef)ptHalInfo->ucS3VddOddEvenStatus);
#endif /* USED_S3_VDD_OE_INPUT_OUTPUT_ALWAYS_LOW_CTRL */
			ptHalInfo->ucS3VddOddEvenStatus = (!ptHalInfo->ucS3VddOddEvenStatus);
			ptHalInfo->bIsS3VddOddEvenControlFrameCheckCnt = 0;
		}
	}
}
#endif /* USED_S3_VDD_OE_INPUT_OUTPUT_CTRL */

#if USED_TOUCH_REPORT_ON_OFF_CONTROL
void HAL_SetTouchReportEnControl(bool_t bIsEn)
{
	if(bIsEn == YES)
	{
		if(ptHalInfo->bIsTouchReportOnOffStart == NO)
		{
			ptHalInfo->bIsTouchReportOnOffStartCheckCnt = 0;
		}
	}

	ptHalInfo->bIsTouchReportOnOffStart = bIsEn;
}

bool_t HAL_GetTouchReportEnControl(void)
{
	if(ptHalInfo->bIsTouchReportOnOffStartCheckCnt < TOUCH_REPORT_ON_OFF_CONTROL_START_CNT_THD)
	{
		ptHalInfo->bIsTouchReportOnOffStartCheckCnt++;
	}

	if(ptHalInfo->bIsTouchReportOnOffStartCheckCnt >= TOUCH_REPORT_ON_OFF_CONTROL_START_CNT_THD)
	{
		return ptHalInfo->bIsTouchReportOnOffStart;
	}
	else
	{
		return NO;
	}
}
#endif /* USED_TOUCH_REPORT_ON_OFF_CONTROL */

void callPendSV(void)
{
	// Set a PendSV to request processing
	NVIC_INT_CTRL_REG = NVIC_PENDSVSET_BIT;
	/* Barriers are normally not required but do ensure the code is completely	within the specified behaviour for the architecture. */
	__asm volatile( "dsb" );
	__asm volatile( "isb" );
}

//#if USED_TPIC_VCOM_LEVEL_I2CM_CONTROL
//eTPIC_VCOM_H_t eTPIC_VCOM_H_Level = VCOM_H_V_5_8v;
//uint8_t ulTPICSendData[2];
//uint8_t ulTPICRecvData[4];
//#endif /* USED_TPIC_VCOM_LEVEL_I2CM_CONTROL */
uint32_t ulRetryCount;
bool_t Hal_sric_start(bool_t cmuxoff)
{
	eSENSING_MODE_t eSensingMode;
	eSensingMode = HAL_GetSensingMode();

#if !USED_OPERATION_STAND_ALONE
	if(!IS_S3_MODE(eSensingMode))
	{
		while(IS_GPIO_PIN(_GPIO_VSYNC) == 0);
		while(IS_GPIO_PIN(_GPIO_VSYNC) == 1);
	}
#endif /* !USED_OPERATION_STAND_ALONE */

	tHalIntrHandle.ulInitFirstFrame = 1;

//	while(1)
//	{
//		ulTPICSendData[0] = TPIC_VCOM_H_ADDR;
//		ulTPICSendData[1] = (uint8_t)eTPIC_VCOM_H_Level;
//		I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, &ulTPICSendData[0], 2);
//		delay_usec(500);
//		I2CM_RcvByte(TPIC_CTRL_I2C_SLAVE_ADDR, TPIC_VCOM_H_ADDR, &ulTPICRecvData[0], 1);
//		I2CM_RcvByte(TPIC_CTRL_I2C_SLAVE_ADDR, TPIC_VCOM_L_ADDR, &ulTPICRecvData[1], 1);
//		I2CM_RcvByte(TPIC_CTRL_I2C_SLAVE_ADDR, TPIC_VGL1_H_ADDR, &ulTPICRecvData[2], 1);
//		I2CM_RcvByte(TPIC_CTRL_I2C_SLAVE_ADDR, TPIC_VGL2_H_ADDR, &ulTPICRecvData[3], 1);
//
//		delay_msec(10);
//	}

#if ((USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN) && USED_TPIC_VCOM_LEVEL_I2CM_CONTROL)
	HAL_TPIC_UplinkModulation_LevelCtrl_Enable();
#endif /* ((USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN) && USED_TPIC_VCOM_LEVEL_I2CM_CONTROL) */

	PWMDRV_Init(eSensingMode);

	SRIC_Reset(eSensingMode);
	delay_msec(10);
	MSPI_Initialize();

	MSPI_Set_TLPMODE();

	ulRetryCount = 0;
#if USED_SRIC_REG_INIT_RETRY
	{
#define DEF_SRIC_RETRY_COUNT_THD			(5)
		uint32_t ulReTryCount = 0;
		do
		{
			if(ulReTryCount > DEF_SRIC_RETRY_COUNT_THD)
			{
				return NO;
			}

			if(SRIC_RegisterInit(eSensingMode) == YES)
			{
				break;
			}

			SRIC_Reset(eSensingMode);
			delay_msec(10);

			ulReTryCount++;
			ulRetryCount++;
		} while(1);
	}
#else /* USED_SRIC_REG_INIT_RETRY */
	SRIC_RegisterInit(eSensingMode);
#endif /* USED_SRIC_REG_INIT_RETRY */

#if USED_OPERATION_STAND_ALONE
	delay_usec(500);
#else /* USED_OPERATION_STAND_ALONE */

	if(IS_S3_MODE(eSensingMode))
	{
#if USED_S3_VDD_OE_INPUT_OUTPUT_CTRL
		HAL_Set_S3_VDD_OddEven_Ctrl(YES);
#endif /* USED_S3_VDD_OE_INPUT_OUTPUT_CTRL */

		delay_usec(500);
#if USED_S3_PGAMMA_SW_I2C_CTRL
		module_S3_PGAMMA_I2C_SW_Disable();
#endif /* USED_S3_PGAMMA_SW_I2C_CTRL */
	}
	else
	{
		while(IS_GPIO_PIN(_GPIO_VSYNC) == 1);
//#if USED_S3_PGAMMA_SW_I2C_CTRL
//		_gT(_GPIO_TP_INTR);
//		module_S3_PGAMMA_I2C_SW_Enable();
//		_gT(_GPIO_TP_INTR);
//#endif /* USED_S3_PGAMMA_SW_I2C_CTRL */
		while(IS_GPIO_PIN(_GPIO_VSYNC) == 0);
		while(IS_GPIO_PIN(_GPIO_VSYNC) == 1);
		while(IS_GPIO_PIN(_GPIO_VSYNC) == 0);
	}
#endif /* USED_OPERATION_STAND_ALONE */

//	{
//		PWMDRV_Cmd(ENABLE);
//		PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = ENABLE;
//		tHalIntrHandle.ulInitFirstFrame = 0;
//		while(1) ;
//	}

#if USED_DO_NOT_TOUCH_ONLY_DISPLAY
	/*
	 * ECLK OFF시키자!! Default가 Enable이라 PLL On되면 ECLK바로 구동 되어 버림!!
	 */
	PWMDRV->ECLK_CR.tBit.eclk_force_on = 0;
	PWMDRV->ECLK_CR.tBit.eclk_en = 0;
	GPIO_Set_DATA(_GPIO_MUX_EN_TPIC, GPIO_DATA_LOW);
	Hal_VccOff_State();
	while(1)
	{
		__WFI();
	}
#endif /* USED_DO_NOT_TOUCH_ONLY_DISPLAY */
	SRIC_Run(ENABLE);

	MSPI_ITConfig(ENABLE);
	MSPI_Set_AITMODE(eSensingMode);

	MSPI_Set_BUFSIZE_FingerPenMode(0);

	PWMDRV_Cmd(ENABLE);
	MSPI->SPIAITSTART = MSPI_START_VAL;

//	PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = ENABLE;
	tHalIntrHandle.ulInitFirstFrame = 0;

#if USED_TPIC_MUXEN_ON_OFF_CONTROL
	HAL_SetTPICMuxEnControl(YES, NO);
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */

#if USED_TOUCH_REPORT_ON_OFF_CONTROL
	HAL_SetTouchReportEnControl(YES);
#endif /* USED_TOUCH_REPORT_ON_OFF_CONTROL */

	return YES;
}

void Hal_VccOff_State(void)
{
	// ECLK OFF
//	PWMDRV->ECLK_CR.tBit.eclk_en = DISABLE;
	PWMDRV->ECLK_CR.tBit.eclk_force_on = DISABLE;

#if (!USED_DO_NOT_TOUCH_ONLY_DISPLAY)
	GPIO_Init(_GPIO_TSYNC_OUT, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_TSYNC_IN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#if USED_TSYNC2_INPUT_FROM_TCON
	GPIO_Init(_GPIO_TSYNC_2_IN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif /* USED_TSYNC2_INPUT_FROM_TCON */
#endif /* (!USED_DO_NOT_TOUCH_ONLY_DISPLAY) */
#if !(USED_MODULE_DEF == MODULE_DEF_S_1 && (CUSTOMER == MODEL_DEF_FHD_92503S))
	GPIO_Init(_GPIO_TSYNC_TMIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif
	GPIO_Init(_GPIO_MUX_EN_TPIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	//Vsync Pull-Down
	GPIO_Init(_GPIO_VSYNC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	//MSPI Pull-Down
	GPIO_Init(_GPIO_MSPI_0_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_0_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_0_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_0_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_1_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_1_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_1_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_1_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_2_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_2_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_2_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_2_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_3_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_3_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_3_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_3_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_4_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_4_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_4_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_4_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_5_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_5_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	#if (USED_PCB_PINMAP != SHARP_NBPC_PIN_TYPE_S01)
		GPIO_Init(_GPIO_MSPI_5_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#endif /* (USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S01) */
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	GPIO_Init(_GPIO_MSPI_5_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	GPIO_Init(_GPIO_MSPI_5_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_6_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_6_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#if ((!((USED_MODULE_DEF == MODULE_DEF_B_1) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))) && (!USED_GPIO_MSPI_6_IS_MUX_EN))
		GPIO_Init(_GPIO_MSPI_6_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#endif /* (!((USED_MODULE_DEF == MODULE_DEF_B_1) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))) */
	GPIO_Init(_GPIO_MSPI_6_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

#if (USED_VCF_SYNC_CONTROL == NO)
	GPIO_Init(_GPIO_MSPI_7_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_7_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#if !USED_PWM_GATE_CONTROL
		GPIO_Init(_GPIO_MSPI_7_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#endif
	GPIO_Init(_GPIO_MSPI_7_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif /* USED_VCF_SYNC_CONTROL */

#if USED_VCF_SYNC_CONTROL
	//TP EN -> GPIO -> Low
	GPIO_Init(_GPIO_PRIVACY_EN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#else /* USED_VCF_SYNC_CONTROL */
	//TP EN -> GPIO -> Low
#if (CUSTOMER != MODEL_DEF_FHD_97500_MNT_S3)
	GPIO_Init(_GPIO_TP_EN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif /* (CUSTOMER != MODEL_DEF_FHD_97500_MNT_S3) */
#endif /* USED_VCF_SYNC_CONTROL */

	//PWM Pull-Down
	GPIO_Init(_GPIO_PWM_SRIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_PWM_TPIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#if USED_PWM_GATE_CONTROL
	GPIO_Init(_GPIO_PWM_GATE, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif /* USED_PWM_GATE_CONTROL */

	//ECLK Pull-Down
	GPIO_Init(_GPIO_ECLK_0, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_ECLK_1, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_TP_INTR, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);

	//Reset SRIC
	GPIO_Init(_GPIO_RSTN_SRIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	//Reset Uplink
	GPIO_Init(_GPIO_Uplink_GPIO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
}

#if USED_TP_RST_OPERATION
void Hal_TPRSTOff_State(void)
{
	// ECLK OFF
	PWMDRV->ECLK_CR.tBit.eclk_force_on = DISABLE;

	//MSPI Pull-Down
	GPIO_Init(_GPIO_MSPI_0_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_0_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_0_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_0_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_1_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_1_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_1_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_1_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_2_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_2_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_2_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_2_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_3_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_3_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_3_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_3_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_4_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_4_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_4_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_4_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_5_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_5_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	#if (USED_PCB_PINMAP != SHARP_NBPC_PIN_TYPE_S01)
		GPIO_Init(_GPIO_MSPI_5_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#endif /* (USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S01) */
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	GPIO_Init(_GPIO_MSPI_5_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	GPIO_Init(_GPIO_MSPI_5_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_6_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_6_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#if (!((USED_MODULE_DEF == MODULE_DEF_B_1) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3)))
		GPIO_Init(_GPIO_MSPI_6_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#endif /* (!((USED_MODULE_DEF == MODULE_DEF_B_1) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))) */
	GPIO_Init(_GPIO_MSPI_6_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

#if (USED_VCF_SYNC_CONTROL == NO)
	GPIO_Init(_GPIO_MSPI_7_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_7_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#if !USED_PWM_GATE_CONTROL
		GPIO_Init(_GPIO_MSPI_7_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#endif
	GPIO_Init(_GPIO_MSPI_7_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif /* USED_VCF_SYNC_CONTROL */

	//PWM Pull-Down
	GPIO_Init(_GPIO_PWM_SRIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_PWM_TPIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	//ECLK Pull-Down
	GPIO_Init(_GPIO_ECLK_0, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_ECLK_1, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
}
#endif /* USED_TP_RST_OPERATION */

/*
 * NOTE : New Function
 */
void HAL_Initialize(void)
{
	ptHalInfo = hal_GetInfo();
}

void HAL_ConfigInit(bool_t bIsS3)
{
#if USED_PEN_MODE_OPERATION
#if USED_INIT_PEN_MODE
	ptHalInfo->eSensingMode = SM_FINGER_PEN_ACTIVE_MODE;
#else /* USED_INIT_PEN_MODE */
	ptHalInfo->eSensingMode = SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_MAIN_MODE;
#endif /* USED_INIT_PEN_MODE */
#else /* USED_PEN_MODE_OPERATION */
	if(bIsS3)
	{
		ptHalInfo->eSensingMode = SM_S3_ACTIVE_MODE;
	}
	else
	{
		ptHalInfo->eSensingMode = SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE;
	}
#endif /* USED_PEN_MODE_OPERATION */
}

eSENSING_CHANGE_MODE_t HAL_GetSensingChangeMode(void)
{
	return ptHalInfo->eSensingChangeMode;
}

void HAL_SetSensingChangeMode(eSENSING_CHANGE_MODE_t mode)
{
#if USED_ECLK_ON_OFF_CONTROL
	// Mode 변경시 EClk On/Off Control을 Disable시켜야 한다.
	if(mode != SM_CHANGE_COMPLETE)
	{
		HAL_SetECLKOnOffControl(NO);
	}
#endif /* USED_ECLK_ON_OFF_CONTROL */
	ptHalInfo->eSensingChangeMode = mode;
}

eSENSING_MODE_t HAL_GetSensingMode(void)
{
	return ptHalInfo->eSensingMode;
}

void HAL_SetSensingMode(eSENSING_MODE_t mode)
{
	if(ptHalInfo != NULL)
		ptHalInfo->eSensingMode = mode;
}

eDIAG_TEST_CHANGE_MODE_t HAL_GetDiagTestSensingChangeMode(void)
{
	return ptHalInfo->eDiagTestChangeMode;
}

void HAL_SetDiagTestSensingChangeMode(eDIAG_TEST_CHANGE_MODE_t mode)
{
#if USED_ECLK_ON_OFF_CONTROL
	// Mode ????? EClk On/Off Control?? Disable????? ???.
	if(mode != SM_CHANGE_COMPLETE)
	{
		HAL_SetECLKOnOffControl(NO);
	}
#endif /* USED_ECLK_ON_OFF_CONTROL */
	ptHalInfo->eDiagTestChangeMode = mode;
	ptHalInfo->eSensingChangeMode = SM_CHANGE_DIAG_TEST;
}


eROIC_REG_SET_CHANGE_MODE_t HAL_GetROICRegSetChangeMode(void)
{
	return ptHalInfo->eROICRegSetChangeMode;
}

void HAL_SetROICRegSetChangeMode(eROIC_REG_SET_CHANGE_MODE_t mode)
{
#if USED_ECLK_ON_OFF_CONTROL
	// Mode 변경시 EClk On/Off Control을 Disable시켜야 한다.
	if(mode != SM_CHANGE_COMPLETE)
	{
		HAL_SetECLKOnOffControl(NO);
	}
#endif /* USED_ECLK_ON_OFF_CONTROL */
	ptHalInfo->eROICRegSetChangeMode = mode;
	ptHalInfo->eSensingChangeMode = SM_CHANGE_ROIC_REG_VAL;
}

#if USED_IDLE_MODE_CONTROL
__IO uint32_t ulVSyncIrqFlg = 0;
#endif /* USED_IDLE_MODE_CONTROL */

bool_t HAL_CheckSensningModeChange(eSENSING_CHANGE_MODE_t mode)
{
	bool_t bIsModeChange = YES;
#if USED_S3_ALL_MUX_SHORT
	const tModuleSRICCommonConf_t * pktmoduleSRICCommonConf;
	pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
#endif /* USED_S3_ALL_MUX_SHORT */
	eSENSING_MODE_t ePastSensingMode = HAL_GetSensingMode();

	switch(mode)
	{
		case SM_CHANGE_IDLE_MODE:
		{
//			if(IS_S3_MODE(ePastSensingMode))
//			{
//				tTimerOpHandleInfo_t tTimerHandle;
//				TIMER_StopTimer(TIMER_1UNIT);
//#if USED_S3_ALL_MUX_SHORT
//				{
//					/*
//					 * S3 Idle All Mux Short적용!!
//					 */
//					tSRIC_CFGR_CHIP0_LEN_t tParam_CHIP0_LEN;
//					tParam_CHIP0_LEN.ulBulk = pktmoduleSRICCommonConf->tParam_CHIP0_LEN.ulBulk;
//					tParam_CHIP0_LEN.tBit.tie1_cmux = 1;
//					SW92501_Set_Register(CHIP0_LEN, pktmoduleSRICCommonConf->tParam_CHIP0_LEN.ulBulk, ROIC_0);
//					PWMDRV_Set_Pulse_Config(SM_S3_IDLE_MODE);
//				}
//#endif /* USED_S3_ALL_MUX_SHORT */
//				tTimerHandle.ulTimerUnit = TIMER_1UNIT;
//#if USED_ECLK_ON_OFF_CONTROL
//	#if USED_S3_ALL_MUX_SHORT
//				tTimerHandle.ulLoadCount = 78260,//94660;//44650; // 60Hz //44650;//(3 * (1000000/20));//16.6msec //50012;
//	#else /* USED_S3_ALL_MUX_SHORT */
//				tTimerHandle.ulLoadCount = 89360,//94660;//44650; // 60Hz //44650;//(3 * (1000000/20));//16.6msec //50012;
//	#endif/* USED_S3_ALL_MUX_SHORT */
//#else /* USED_ECLK_ON_OFF_CONTROL */
//				tTimerHandle.ulLoadCount = 150000,//94660;//44650; // 60Hz //44650;//(3 * (1000000/20));//16.6msec //50012;
//#endif /* USED_ECLK_ON_OFF_CONTROL */
//				TIMER_SetPeriodicMode(&tTimerHandle);
//				TIMER_StartTimer(TIMER_1UNIT);
//				HAL_SetSensingMode(SM_S3_IDLE_MODE);
//			}
#if USED_IDLE_MODE_CONTROL
			if(IS_FINGER_ONLY_MODE(ePastSensingMode))
			{
				PWMDRV_RegisterInit(SM_FINGER_ONLY_IDLE_MODE);
				PWMDRV_Cmd(ENABLE);
				SRIC_SetRuntimeChangeRegister(ROIC_REG_SET_CHANGE_FINGER_PEN_FULL_IDLE);
				HAL_SetSensingMode(SM_FINGER_ONLY_IDLE_MODE);
			}
#endif /* USED_IDLE_MODE_CONTROL */
#if USED_LOCAL_IDLE_MODE_CONTROL
			if(IS_FINGER_PEN_MODE(ePastSensingMode))
			{
				PWMDRV_RegisterInit(SM_FINGER_PEN_IDLE_MODE);
				PWMDRV_Cmd(ENABLE);
				SRIC_SetRuntimeChangeRegister(ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_IDLE);
				HAL_SetSensingMode(SM_FINGER_PEN_IDLE_MODE);
			}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
			break;
		}
		case SM_CHANGE_ACTIVE_MODE:
		{
			if(IS_FINGER_ONLY_MODE(ePastSensingMode))
			{
				PWMDRV_RegisterInit(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
				PWMDRV_Cmd(ENABLE);
				SRIC_SetRuntimeChangeRegister(ROIC_REG_SET_CHANGE_FINGER_PEN_FULL);
				HAL_SetSensingMode(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
			}
			break;
		}
		case SM_CHANGE_ACTIVE_FRQ_MAIN_MODE:
		{
#if USED_NOISE_HOPPING_FREQ
			if(IS_FINGER_ONLY_MODE(ePastSensingMode))
			{
				PWMDRV_RegisterInit(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
				PWMDRV_Cmd(ENABLE);
				SRIC_SetRuntimeChangeRegister(ROIC_REG_SET_CHANGE_FREQ_MAIN_FINGER_PEN_FULL);
				HAL_SetSensingMode(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
			}
#endif
			break;
		}
		case SM_CHANGE_ACTIVE_FRQ_HOP1_MODE:
		{
#if USED_NOISE_HOPPING_FREQ
			if(IS_FINGER_ONLY_MODE(ePastSensingMode))
			{
				PWMDRV_RegisterInit(SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE);
				PWMDRV_Cmd(ENABLE);
				SRIC_SetRuntimeChangeRegister(ROIC_REG_SET_CHANGE_FREQ_HOPP1_FINGER_PEN_FULL);
				HAL_SetSensingMode(SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE);
			}
#endif
			break;
		}
		case SM_CHANGE_ACTIVE_FRQ_HOP2_MODE:
		{
			break;
		}
//		case SM_CHANGE_S3_MODE:
//		{
//			break;
//		}
		case SM_CHANGE_FINGER_ONLY_MODE:
		{
			break;
		}
		case SM_CHANGE_FINGER_PEN_SEARCH_MODE:
		{
			PWMDRV_RegisterInit(SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_MAIN_MODE);
			PWMDRV_Cmd(ENABLE);
//			PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = ENABLE;
			SRIC_SetRuntimeChangeRegister(ROIC_REG_SET_CHANGE_FINGER_PEN_FULL);
//			SRIC_SetFingerPenFullModeChange(YES);
			HAL_SetSensingMode(SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_MAIN_MODE);
			break;
		}
		case SM_CHANGE_FINGER_PEN_MODE:
		{
			PWMDRV_RegisterInit(SM_FINGER_PEN_ACTIVE_MODE);
			PWMDRV_Cmd(ENABLE);
//			PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = ENABLE;
			SRIC_SetRuntimeChangeRegister(ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_ACTIVE);
//			SRIC_SetFingerPenFullModeChange(NO);
			HAL_SetSensingMode(SM_FINGER_PEN_ACTIVE_MODE);
			break;
		}
		case SM_CHANGE_DIAG_TEST:
		{
			SRIC_SetDiagTestOperationMode(HAL_GetDiagTestSensingChangeMode());
			break;
		}
		case SM_CHANGE_ROIC_REG_VAL:
		{
			SRIC_SetRuntimeChangeRegister(HAL_GetROICRegSetChangeMode());
			break;
		}
		case SM_CHANGE_COMPLETE:
		default:
		{
			bIsModeChange = NO;
			break;
		}
	}

	return bIsModeChange;
}

uint16_t * HAL_GetBaseImagePointer(eSENSING_MODE_t mode, eBaseImageType_t type)
{
	uint16_t * pImage = NULL;
	eActivePenType_t eLocalFingerOPType = hal_Info_GetControlLocalFingerOPType();

#if USED_MNT_S3_MODE_FUNCTION
	if(IS_S3_MODE(mode))
	{
		pImage = HAL_NI_GET_BASELINE_IMAGE_PTR();
	}
	else
#endif /* USED_MNT_S3_MODE_FUNCTION */
	{
		if(IS_ACTIVE_MODE(mode))
		{
			if(IS_ACTIVE_MODE_FRQ_HOP1(mode))
			{
				if(type == BASELINE_TYPE_FULL)
				{
					//pImage = HAL_GET_HOPP1_BASELINE_IMAGE_PTR();	// leegc
				}
				else
				{
	//				pImage = HAL_NI_GET_BASELINE_IMAGE_PTR();
				}
			}
			else if(IS_ACTIVE_MODE_FRQ_HOP2(mode))
			{
				if(type == BASELINE_TYPE_FULL)
				{
					//pImage = HAL_GET_HOPP2_BASELINE_IMAGE_PTR();	// leegc
				}
				else
				{
	//				pImage = HAL_NI_GET_BASELINE_IMAGE_PTR();
				}
			}
			else
			{
				if(type == BASELINE_TYPE_FULL)
				{
					switch(eLocalFingerOPType)
					{
						case ACTIVEPEN_TYPE_LOCAL_MS:
						{
							pImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR();
							break;
						}
						case ACTIVEPEN_TYPE_LOCAL_WACOM:
						case ACTIVEPEN_TYPE_LOCAL_WGP:
						{
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
							pImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR();
	#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
							pImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_2_PTR();
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
							break;
						}
					}
				}
			}
		}
		else
		{
			pImage = HAL_NI_GET_BASELINE_IMAGE_PTR();
		}
	}

	return pImage;
}

void HAL_SetActivePenChagneType(eActivePenChangeType_t eType)
{
	ptHalInfo->ulActivePenChangeType = eType;
}

//extern __IO uint16_t sensingRowStart;

bool_t HAL_CheckActivePenChangeType(void)
{
	bool_t bReg = FALSE;

	switch(ptHalInfo->ulActivePenChangeType)
	{
		case ACTIVEPEN_CHANGE_LOCAL_MS:
		{
			hal_Info_SetControlActivePenSettingType(ACTIVEPEN_TYPE_LOCAL_MS);
			PWMDRV_RegisterInit(HAL_GetSensingMode());
			PWMDRV_Cmd(ENABLE);
//			PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = ENABLE;
			SRIC_SetRuntimeChangeRegister(ROIC_REG_SET_CHAGNE_MSPen_Local_Setting);
			hal_Info_SetControlActivePenOPType(ACTIVEPEN_TYPE_LOCAL_MS);
			bReg = TRUE;
			break;
		}
		case ACTIVEPEN_CHANGE_LOCAL_WACOM:
		{
			hal_Info_SetControlActivePenSettingType(ACTIVEPEN_TYPE_LOCAL_WACOM);
			PWMDRV_RegisterInit(HAL_GetSensingMode());
			PWMDRV_Cmd(ENABLE);
//			PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = ENABLE;
			SRIC_SetRuntimeChangeRegister(ROIC_REG_SET_CHAGNE_WacomPen_Local_Setting);
			hal_Info_SetControlActivePenOPType(ACTIVEPEN_TYPE_LOCAL_WACOM);
			bReg = TRUE;
			break;
		}
		case ACTIVEPEN_CHANGE_LOCAL_WGP:
		{
			hal_Info_SetControlActivePenSettingType(ACTIVEPEN_TYPE_LOCAL_WGP);
			PWMDRV_RegisterInit(HAL_GetSensingMode());
			PWMDRV_Cmd(ENABLE);
//			PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = ENABLE;
			SRIC_SetRuntimeChangeRegister(ROIC_REG_SET_CHAGNE_WGPPen_Local_Setting);
			hal_Info_SetControlActivePenOPType(ACTIVEPEN_TYPE_LOCAL_WGP);
			bReg = TRUE;
			break;
		}
	}

	return bReg;
}

bool_t HAL_CheckActivePenTypeSwap(void)
{
	bool_t bReg = FALSE;
	if(ptHalInfo->bIsPenDection)
	{
		ptHalInfo->ulPenTypeSwapCheckFrameCnt = 0;
	}
	else
	{
		if(ptHalInfo->bIsPenTypeSwapCheckStart)
		{
			eActivePenType_t ePenOPType = hal_Info_GetControlActivePenOPType();
			ptHalInfo->ulPenTypeSwapCheckFrameCnt++;
			switch(ePenOPType)
			{
				case ACTIVEPEN_TYPE_LOCAL_MS:
				{
					if(ptHalInfo->ulPenTypeSwapCheckFrameCnt >= ptHalInfo->ulMSPenIdleOpFrameNumTHD)
					{
						ptHalInfo->ulPenTypeSwapCheckFrameCnt = 0;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
						HAL_SetActivePenChagneType(ACTIVEPEN_CHANGE_LOCAL_WACOM);
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
						HAL_SetActivePenChagneType(ACTIVEPEN_CHANGE_LOCAL_WGP);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) */
						bReg = TRUE;
					}
					break;
				}
				case ACTIVEPEN_TYPE_LOCAL_WACOM:
				case ACTIVEPEN_TYPE_LOCAL_WGP:
				{
					if(ptHalInfo->ulPenTypeSwapCheckFrameCnt >= ptHalInfo->ulWacomPenIdleOpFrameNumTHD)
					{
						ptHalInfo->ulPenTypeSwapCheckFrameCnt = 0;
						HAL_SetActivePenChagneType(ACTIVEPEN_CHANGE_LOCAL_MS);
						bReg = TRUE;
					}
					break;
				}
			}
		}
		else if(ptHalInfo->ulActivePenChangeType != ACTIVEPEN_CHANGE_DONE)
		{
			bReg = TRUE;
		}
	}

	return bReg;
}

#if USED_TPIC_VCOM_LEVEL_I2CM_CONTROL
eTPIC_VCOM_H_t ucVom_H_V_PenLevel = VCOM_H_V_10_2v;
eTPIC_VCOM_L_t ucVom_L_V_PenLevel = VCOM_L_V_1v;
eTPIC_VGL1_H_t ucVgl1_H_V_PenLevel = VGL1_H_V_minus_2v;
eTPIC_VGL2_H_t ucVgl2_H_V_PenLevel = VGL2_H_V_minus_4v;
void HAL_TPIC_UplinkModulation_LevelCtrl_Enable(void)
{
	uint8_t ulData[2];
#if 1
	ulData[0] = TPIC_VCOM_H_ADDR;
	ulData[1] = (uint8_t)ucVom_H_V_PenLevel;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);

	ulData[0] = TPIC_VCOM_L_ADDR;
	ulData[1] = (uint8_t)ucVom_L_V_PenLevel;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);

//	ulData[0] = TPIC_VGL1_H_ADDR;
//	ulData[1] = (uint8_t)ucVgl1_H_V_PenLevel;
//	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);
//
//	ulData[0] = TPIC_VGL2_H_ADDR;
//	ulData[1] = (uint8_t)ucVgl2_H_V_PenLevel;
//	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN) */
	ulData[0] = TPIC_VCOM_H_ADDR;
	ulData[1] = (uint8_t)ucVom_H_V_PenLevel;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);

	ulData[0] = TPIC_VCOM_L_ADDR;
	ulData[1] = (uint8_t)ucVom_L_V_PenLevel;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);

	ulData[0] = TPIC_VGL1_H_ADDR;
	ulData[1] = (uint8_t)ucVgl1_H_V_PenLevel;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);

	ulData[0] = TPIC_VGL2_H_ADDR;
	ulData[1] = (uint8_t)ucVgl2_H_V_PenLevel;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN) */
}

void HAL_TPIC_UplinkModulation_LevelCtrl_Disable(void)
{
	uint8_t ulData[2];
#if 1
	ulData[0] = TPIC_VCOM_H_ADDR;
	ulData[1] = (uint8_t)VCOM_H_V_5_8v;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);

	ulData[0] = TPIC_VCOM_L_ADDR;
	ulData[1] = (uint8_t)VCOM_L_V_2_6v;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);

//	ulData[0] = TPIC_VGL1_H_ADDR;
//	ulData[1] = (uint8_t)VGL1_H_V_minus_3_8v;
//	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);
//
//	ulData[0] = TPIC_VGL2_H_ADDR;
//	ulData[1] = (uint8_t)VGL2_H_V_minus_5_8v;
//	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);
#else
	ulData[0] = TPIC_VCOM_H_ADDR;
	ulData[1] = (uint8_t)VCOM_H_V_5_8v;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);

	ulData[0] = TPIC_VCOM_L_ADDR;
	ulData[1] = (uint8_t)VCOM_L_V_2_6v;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);

	ulData[0] = TPIC_VGL1_H_ADDR;
	ulData[1] = (uint8_t)VGL1_H_V_minus_3_8v;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);

	ulData[0] = TPIC_VGL2_H_ADDR;
	ulData[1] = (uint8_t)VGL2_H_V_minus_5_8v;
	I2CM_SendByte(TPIC_CTRL_I2C_SLAVE_ADDR, ulData, 2);
#endif
}
#endif /* USED_TPIC_VCOM_LEVEL_I2CM_CONTROL */

/*
 * App
 */
void HAL_CheckBootInterfaceInfoOnSecurityRegion(void)
{
	if(FLITF_EnsureBootInterfaceCodeFlashIntegrity() == NO)
	{
		tSimpleBootFlashCtrlInfo_t * pSimpleBootFlashCtrlInfo = (tSimpleBootFlashCtrlInfo_t *)SRAM_SIMPLE_BOOT_CTRL_INFO_ADDR;
		pSimpleBootFlashCtrlInfo->tFlashBootInterfaceInfo.tDeviceId.BOOT_VID = UNIQUE_VID;
		pSimpleBootFlashCtrlInfo->tFlashBootInterfaceInfo.tDeviceId.BOOT_PID = UNIQUE_BOOT_PID;
		pSimpleBootFlashCtrlInfo->tFlashBootInterfaceInfo.tDeviceInfo.BOOT_I2C_SLV_ADDR = I2C_ADDRESS;
		pSimpleBootFlashCtrlInfo->tFlashBootInterfaceInfo.tDeviceInfo.APP_KBYTE_SIZE = FLASH_APPLICATION_KBYTE_SIZE;
		pSimpleBootFlashCtrlInfo->tFlashBootInterfaceInfo.BOOT_INFO_WRITE_EN_CODE = EFLASH_BOOT_INFO_WRITE_EN_CODE;
		pSimpleBootFlashCtrlInfo->tFlashBootInterfaceInfo.CheckSum = FLITF_Calc32bitCheckSum((uint32_t *)&pSimpleBootFlashCtrlInfo->tFlashBootInterfaceInfo, (EFLASH_VID_PID_I2CSLV_WORD_SIZE - 1));

		pSimpleBootFlashCtrlInfo->ulFlashUpdateType = SIMPLE_BOOT_FLASH_UPDATE_HOST_INTERFACE;
		pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim1.R_OSC12M_VTRIM = SCRB->SYS_ANA_TRIM.tBit.R_OSC12M_VTRIM;
		pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim1.R_OSC12M_ITRIM = SCRB->SYS_ANA_TRIM.tBit.R_OSC12M_ITRIM;
		pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim2.R_LDO_TRIM = SCRB->SYS_ANA_TRIM.tBit.R_LDO_TRIM;
		pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_VBGR_CTL = SCRB->SYS_ANA_TRIM.tBit.R_MAIN_VBGR_CTL;
		pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_IREF_TRIM = SCRB->SYS_ANA_TRIM.tBit.R_MAIN_IREF_TRIM;
		pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_VREF_TRIM = SCRB->SYS_ANA_TRIM.tBit.R_MAIN_VREF_TRIM;

		FLITF_FlashInformationRegionWriteOperation();
	}
}
#if USED_LPWG_MCU_SLEEP
void Hal_WaitSampleDoneSleep(void)
{
	tCK_ENA_RUN0_t tCK_ENA_RUN0;
	tCK_ENA_RUN1_t tCK_ENA_RUN1;
//	tCLK_SRC_SEL_t tCLK_SRC_SEL;

//	GPIO->tGPIO_DATA_1.tBit.GPB10 = 0;
//	GPIO->tGPIO_DATA_1.tBit.GPB10 = 1;

	tCK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
//	tCK_ENA_RUN0.tBit.r_USB_CLK_ENA = 1;
//		tCK_ENA_RUN0.tBit.r_WDT_CLK_ENA = 0;
//		tCK_ENA_RUN0.tBit.r_TIM_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_LFDTX_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_TSPI_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_DSPA_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_DSPB_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_SRAM1_CLK_ENA = 1;
//	tCK_ENA_RUN0.tBit.r_SRAM2_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM3_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_DMAC_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_I2C_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_FLITF_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_GPIO_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN0.ulBulk = tCK_ENA_RUN0.ulBulk;

	tCK_ENA_RUN1.ulBulk = SCRB->CK_ENA_RUN1.ulBulk;
//	tCK_ENA_RUN1.tBit.r_MSPI01_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_MSPI23_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_MSPI45_CLK_ENA = 0;
	tCK_ENA_RUN1.tBit.r_SIF_CLK_ENA = 0;
	tCK_ENA_RUN1.tBit.r_SFL_CLK_ENA = 0;
	tCK_ENA_RUN1.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN1.ulBulk = tCK_ENA_RUN1.ulBulk;

	/*
	 * Systick도 죽이자..
	 * TODO : 이로 인한 Side Effect Check.. USB쪽에서 Systick으로 Scan time을 Check한다.
	 */
	SysTick_DeInitialize();

	__WFI();
//	GPIO->tGPIO_DATA_1.tBit.GPB10 = 0;
//	GPIO->tGPIO_DATA_1.tBit.GPB10 = 1;
	/*
	 * Stand Alone에서는 Timer IRQ에서 Clock을 원복 시킨다.
	 */
}

void Hal_WaitModernStanbySleep(void)
{
//	tCK_ENA_RUN0_t tCK_ENA_RUN0;
//	tCK_ENA_RUN1_t tCK_ENA_RUN1;
//	tCLK_SRC_SEL_t tCLK_SRC_SEL;
//
//	tCK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
////	tCK_ENA_RUN0.tBit.r_USB_CLK_ENA = 1;
////		tCK_ENA_RUN0.tBit.r_WDT_CLK_ENA = 0;
////		tCK_ENA_RUN0.tBit.r_TIM_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_LFDTX_CLK_ENA = 0;
////	tCK_ENA_RUN0.tBit.r_TSPI_CLK_ENA = 0;
////	tCK_ENA_RUN0.tBit.r_DSPA_CLK_ENA = 0;
////	tCK_ENA_RUN0.tBit.r_DSPB_CLK_ENA = 0;
////	tCK_ENA_RUN0.tBit.r_SRAM1_CLK_ENA = 1;
////	tCK_ENA_RUN0.tBit.r_SRAM2_CLK_ENA = 1;
//	tCK_ENA_RUN0.tBit.r_SRAM3_CLK_ENA = 0;
////	tCK_ENA_RUN0.tBit.r_DMAC_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_I2C_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_FLITF_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit.r_GPIO_CLK_ENA = 0;
//	tCK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
//	SCRB->CK_ENA_RUN0.ulBulk = tCK_ENA_RUN0.ulBulk;
//
//	tCK_ENA_RUN1.ulBulk = SCRB->CK_ENA_RUN1.ulBulk;
//	tCK_ENA_RUN1.tBit.r_MSPI01_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_MSPI23_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_MSPI45_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_SIF_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_SFL_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit._VECTKEY = SCB_VECTKEY_VALUE;
//	SCRB->CK_ENA_RUN1.ulBulk = tCK_ENA_RUN1.ulBulk;
//
////	MSPI_GPIO_DeInit();
//
////	GPIO->tGPIO_DATA_1.tBit.GPB10 = 0;
////	GPIO->tGPIO_DATA_1.tBit.GPB10 = 1;
//
//	{
//		tCLK_SRC_SEL_t tCLK_SRC_SEL;
//		tCLK_SRC_SEL.ulBulk = SCRB->CLK_SRC_SEL.ulBulk;
//		/*
//		 * 0 : 12MHz(Internal or External OSC)
//		 * 1 : PLL Out Clock
//		 * 2,3 : 40KHz (Internal OSC)
//		 */
//		tCLK_SRC_SEL.tBit.CCLK_SEL = 0; // System Clock
//		tCLK_SRC_SEL.tBit.WDCLK_SEL = 0; // PCLK
//		tCLK_SRC_SEL.tBit.TIMCLK_SEL = 0;
//		tCLK_SRC_SEL.tBit.SSCGOUT_SEL = 0;
//		tCLK_SRC_SEL.tBit.SSCGOUT2X_SEL = 0;//1;
//		tCLK_SRC_SEL.tBit.TOUCHCLK_SEL = 0;
//		tCLK_SRC_SEL.tBit.PLLOUT_SEL = 0;
//		tCLK_SRC_SEL.tBit.SSCGIN_SEL = 0;
//		tCLK_SRC_SEL.tBit._VECTKEY = SCB_VECTKEY_VALUE;
//		SCRB->CLK_SRC_SEL.ulBulk = tCLK_SRC_SEL.ulBulk;
//	}
//
//	{
//		tUMC_PLL_UC_t tUMC_PLL_UC;
//		tUMC_PLL_UC.ulBulk = SCRB->UMC_PLL_UC.ulBulk;
//		tUMC_PLL_UC.tBit.PLL_STBY_I = 1;
//		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
//		tUMC_PLL_UC.tBit.FBDIV = 1;	// Feedback divider number = (FBDIV) : (5 ~ 50)
//		tUMC_PLL_UC.tBit.OUTDIV = 1;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
//		tUMC_PLL_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
//		SCRB->UMC_PLL_UC.ulBulk = tUMC_PLL_UC.ulBulk;
//
//		delay_usec(1); // PLL및 Clock Divider설정 전이기 때문에.. 느리다.. 대략 1/10정도..
//
//		tUMC_PLL_UC.tBit.PLL_STBY_I = 0;
//		tUMC_PLL_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
//		SCRB->UMC_PLL_UC.ulBulk = tUMC_PLL_UC.ulBulk;
//	}
//
//	{
//		tCLK_DIV_t tCLK_DIV;
//		tCLK_DIV.ulBulk = SCRB->CLK_DIV.ulBulk;
//		tCLK_DIV.tBit.HCLK_DIV = 7;
//		tCLK_DIV.tBit.PCLK_DIV = 3; // MSPI Clk이 받아서 사용..
//	#if USED_ECLK_SOURCE_TIMERCLK
//
//		tCLK_DIV.tBit.TIMCLK_DIV = 0; /*timer clk : 0(/1), 1(/2), ... 7(/128) */
//	#else /* USED_ECLK_SOURCE_TIMERCLK */
//		tCLK_DIV.tBit.TIMCLK_DIV = 7; /*timer clk : 0(/1), 1(/2), ... 7(/128) */
//	#endif /* USED_ECLK_SOURCE_TIMERCLK */
//		tCLK_DIV.tBit.WDTCLK_DIV = 7;
//		tCLK_DIV.tBit.SSCGIN_DIV = 3;
//		tCLK_DIV.tBit.TOUCHCLK_DIV = 3;
//		tCLK_DIV.tBit._VECTKEY = SCB_VECTKEY_VALUE;
//		SCRB->CLK_DIV.ulBulk = tCLK_DIV.ulBulk;
//	}
//
//	/*
//	 * Systick도 죽이자..
//	 * TODO : 이로 인한 Side Effect Check.. USB쪽에서 Systick으로 Scan time을 Check한다.
//	 */
//	SysTick_DeInitialize();
//
//	__WFI();
//	module_System_Init();
}
#endif /* USED_LPWG_MCU_SLEEP */
