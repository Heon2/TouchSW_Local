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
#include "misc.h"
#ifdef _USE_APP_LGD_LIB_
#include "pwm_lib_param.h"
#endif /* _USE_APP_LGD_LIB_ */


__IO tHalInterruptHandle_t tHalIntrHandle;
static tHalInfo_t * ptHalInfo = NULL;

void initBoardGPIO(void)
{
#if (USED_LPWG_MODE_CONTROL == NO)
	// TSYNCN_OUT
	GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT = 0x01;
	GPIO->tGPIO_DIR_1._GPIO_TSYNC_OUT = Output;  // OUTPUT
	GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 0x0;
#endif /* (USED_LPWG_MODE_CONTROL == NO) */
	
	// All DC
#ifdef _ALL_PWM_DC_
	GPIO->tGPIO_AFIO_1._GPIO_PWM_TPIC = 0x0; // PWM_DATA (PWM_LFD)
	GPIO->tGPIO_DIR_0._GPIO_PWM_TPIC = Output;  // OUTPUT
	GPIO->tGPIO_DATA_0._GPIO_PWM_TPIC = 1;
#endif

#if USED_TPIC_MUXEN_ON_OFF_CONTROL
	GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 0x0;
	GPIO->tGPIO_DIR_1._GPIO_TPIC_MUX_EN  = 0x1;  // OUTPUT
	GPIO->tGPIO_AFIO_2._GPIO_TPIC_MUX_EN = 0x0;
#else /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
	GPIO->tGPIO_AFIO_2._GPIO_TPIC_MUX_EN = 0x0;
	GPIO->tGPIO_DIR_1._GPIO_TPIC_MUX_EN  = 0x1;  // OUTPUT
	GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 0x1;
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */

	GPIO->tGPIO_AFIO_2._GPIO_TSYNC2_IN = 0x0;

#if USED_TSYNC2_INPUT_CONTROL
	GPIO->tGPIO_DIR_1._GPIO_TSYNC2_IN = Input;  // OUTPUT
#else /* USED_TSYNC2_INPUT_CONTROL */
	GPIO->tGPIO_DIR_1._GPIO_TSYNC2_IN = Output;  // OUTPUT
	GPIO->tGPIO_DATA_1._GPIO_TSYNC2_IN = 0;
#endif /* USED_TSYNC2_INPUT_CONTROL */

	GPIO->tGPIO_AFIO_3.tBit.GPB11 = 0; // SWV
	GPIO->tGPIO_DIR_1.tBit.GPB11 = Output; // SWV
	GPIO->tGPIO_DATA_1.tBit.GPB11 = 1; // SWV
	GPIO->tGPIO_DATA_1.tBit.GPB11 = 0;

	GPIO->tGPIO_AFIO_2._GPIO_TOGGLE = 0;
	GPIO->tGPIO_DIR_1._GPIO_TOGGLE = 1;
	GPIO->tGPIO_DATA_1._GPIO_TOGGLE = 0;
	
#if (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405)
	GPIO->tGPIO_DATA_1._GPIO_SLEEP_RST = 0x1;
	GPIO->tGPIO_DIR_1._GPIO_SLEEP_RST  = 0x1;
	GPIO->tGPIO_AFIO_2._GPIO_SLEEP_RST = 0x0;
#endif /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
	
	GPIO->tGPIO_AFIO_2._GPIO_VTSP18 = 0x1; // VTSP18
	GPIO->tGPIO_DIR_1._GPIO_VTSP18 = Input;	// Input
//	GPIO->tGPIO_DATA_1._GPIO_VTSP18 = 0;	// Input

}

void initECLK(void)
{
	// 8. ECLK Configuration  
	GPIO->tGPIO_AFIO_1._GPIO_ECLK_0 = 0x1;  // ECLK0
	GPIO->tGPIO_AFIO_1._GPIO_ECLK_1 = 0x1;  // ECLK1


	GPIO->tGPIO_P1_0._GPIO_ECLK_0 = ECLK_DRIVING_STRENGTH_0;
	GPIO->tGPIO_P2_0._GPIO_ECLK_0 = ECLK_DRIVING_STRENGTH_1;
	GPIO->tGPIO_P1_0._GPIO_ECLK_1 = ECLK_DRIVING_STRENGTH_0;
	GPIO->tGPIO_P2_0._GPIO_ECLK_1 = ECLK_DRIVING_STRENGTH_1;

//	GPIO->tGPIO_P1_0._GPIO_ECLK_0 = 0x0;
//	GPIO->tGPIO_P2_0._GPIO_ECLK_0 = 0x0;
//	GPIO->tGPIO_P1_0._GPIO_ECLK_1 = 0x0;
//	GPIO->tGPIO_P2_0._GPIO_ECLK_1 = 0x0;

	/* =================================================================
	  @ eclk source

	    Set the output of ECLK

		0 : Off
		1 : External OSC (12MHz)
		2 : System Clock (Internal or External OSC selected by GPIOM_03)
		3 : Intenral OSC (12MHz)
		4 : Internal OSC (1.25MHz / 40kHz)
		5 : USB Clock (30MHz)
		6 : PRE_CCLK (Clock selected by CCLK[1:0])
		7 : FCLK
		8 : HCLK_COR (HCLK for CM3)
		9 : PCLK
		10 : SSCG_FIN (Input Clock of SSCG)
		11 : SSCG_FOUT (Output Clock of SSCG)
		12 : TOUCH_CLK
		13 : WDT_CLK
		14 : TIMCLK_1
		15 : Not Used (Clock selected by USB_CLK_SEL)
	 */
	SCRB->ECLK_CFG.ulBulk = (
		SCB_VECTKEY
#if USED_ECLK_ON_OFF_CONTROL
		| 14         << 0		// ECLK_SEL ( Tim clock )
#else /* USED_ECLK_ON_OFF_CONTROL */
		| 2         << 0		// ECLK_SEL ( 12 mhz : system clock )
#endif /* USED_ECLK_ON_OFF_CONTROL */
		| 0         << 4		// ECLK_DIV
//		| 1         << 4		// ECLK_DIV ( divided clock = input clock / eclk_div + 1 )
		| 0		  	<< 7		// USB_CLK_SEL
		| 0  		<< 9		// USB_CLK_SEL
	);
#if USED_ECLK_ON_OFF_CONTROL
	TIMER->Timer0_CR_b.Timer0_En = 1;
#endif /* USED_ECLK_ON_OFF_CONTROL */

__NOP();
}

#if USED_ECLK_ON_OFF_CONTROL
static void Timer_Clock_Off(void)
{
	tCK_ENA_RUN0_t tCK_ENA_RUN0;
	tCK_ENA_SLP0_t tCK_ENA_SLP0;

	tCK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
	tCK_ENA_RUN0.tBit.r_TIM_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN0.ulBulk = tCK_ENA_RUN0.ulBulk;

	tCK_ENA_SLP0.ulBulk = SCRB->CK_ENA_SLP0.ulBulk;
	tCK_ENA_SLP0.tBit.s_TIM_CLK_ENA = 0;
	tCK_ENA_SLP0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_SLP0.ulBulk = tCK_ENA_SLP0.ulBulk;
}

static void Timer_Clock_On(void)
{
	tCK_ENA_RUN0_t tCK_ENA_RUN0;
	tCK_ENA_SLP0_t tCK_ENA_SLP0;

	tCK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
	tCK_ENA_RUN0.tBit.r_TIM_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN0.ulBulk = tCK_ENA_RUN0.ulBulk;

	tCK_ENA_SLP0.ulBulk = SCRB->CK_ENA_SLP0.ulBulk;
	tCK_ENA_SLP0.tBit.s_TIM_CLK_ENA = 1;
	tCK_ENA_SLP0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_SLP0.ulBulk = tCK_ENA_SLP0.ulBulk;
}

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
	Timer_Clock_On();
}

void HAL_ECLK_Off(void)
{
	Timer_Clock_Off();
}
#endif /* USED_ECLK_ON_OFF_CONTROL */

#if USED_TPIC_MUXEN_ON_OFF_CONTROL
void HAL_SetTPICMuxEnControl(bool_t bIsEn)
{
#if (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405)
	if(bIsEn)
	{
		if(ptHalInfo->bIsTPICMuxEnOnOffStart == NO)
		{
			ptHalInfo->bIsTPICMuxEnOnOfftartCheckCnt = 0;
		}
	}
#else /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
	if(bIsEn == NO)
	{
		if(ptHalInfo->bIsTPICMuxEnOnOffStart == YES)
		{
			GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 1;
		}
	}
	else
	{
		if(ptHalInfo->bIsTPICMuxEnOnOffStart == NO)
		{
			ptHalInfo->bIsTPICMuxEnOnOfftartCheckCnt = 0;
		}
	}
#endif /* (CUSTOMER == MODEL_LGD_SW92400) */

	ptHalInfo->bIsTPICMuxEnOnOffStart = bIsEn;
}

bool_t HAL_GetTPICMuxEnControl(void)
{
	if(ptHalInfo->bIsTPICMuxEnOnOfftartCheckCnt < TPIC_MUXEN_ON_OFF_CONTROL_START_CNT_THD)
	{
		ptHalInfo->bIsTPICMuxEnOnOfftartCheckCnt++;
	}

	if(ptHalInfo->bIsTPICMuxEnOnOfftartCheckCnt >= TPIC_MUXEN_ON_OFF_CONTROL_START_CNT_THD)
	{
		return ptHalInfo->bIsTPICMuxEnOnOffStart;
	}
	else
	{
		return NO;
	}
}
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */

void callPendSV(void)
{
	// Set a PendSV to request processing
	NVIC_INT_CTRL_REG = NVIC_PENDSVSET_BIT;
	/* Barriers are normally not required but do ensure the code is completely	within the specified behaviour for the architecture. */
	__asm volatile( "dsb" );
	__asm volatile( "isb" );
}

__IO uint16_t testbuff[6] = {0,};

bool_t Hal_sric_start(bool_t cmuxoff)
{
	int InitFail;
	static int fail; 
	eSENSING_MODE_t eSensingMode;
	eSensingMode = HAL_GetSensingMode();

#if USED_OPERATION_STAND_ALONE
	if(!IS_S3_MODE(eSensingMode))
	{
		while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0);
		while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 1);
	}
#endif /* !USED_OPERATION_STAND_ALONE */

#if (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405)
	PWMDRV_Init(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
#else /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
	PWMDRV_Init(eSensingMode);
#endif /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
//	SW92400_Reset(eSensingMode);
	GPIO->tGPIO_DATA_0._GPIO_RSTN_0 = 0;
	GPIO->tGPIO_DATA_0._GPIO_RSTN_1 = 0;
	delay_ms(50);
	GPIO->tGPIO_DATA_0._GPIO_RSTN_0 = 1;
	GPIO->tGPIO_DATA_0._GPIO_RSTN_1 = 1;

	delay_ms(100);
	MSPI_Reset();
	MSPI_Initialize();
	MSPI_Set_TLPMODE();
	
#if USED_LPWG_MODE_CONTROL
	if(module_Check_LcdOn(NO) == NO)
	{
		delay_ms(10);
	}
	else
	{
		while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x0);
		while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x1);
	}
#else /* USED_LPWG_MODE_CONTROL */
	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x0);
	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x1);
#endif /* USED_LPWG_MODE_CONTROL */
	
	if(SRIC_Init(eSensingMode)==FALSE)
		return FALSE;

#if USED_OPERATION_STAND_ALONE
	if(!IS_S3_MODE(eSensingMode))
	{
		while(gTSyncInRisingCnt != 16);
	}
#endif /* !USED_OPERATION_STAND_ALONE */

	//Skip 1st dummy data of SRIC
#if USED_LPWG_MODE_CONTROL
	if(IS_LPWG_MODE(HAL_GetSensingMode()))
	{	
		SRIC_Run();
		MSPI_Set_AITMODE(eSensingMode);
		MSPI_Cmd(ENABLE);
		HAL_Timer_Set_Count_us(TIM_Channel_0, 50000);
		HAL_Timer_Enable(TIM_Channel_0, ENABLE);
		GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT = 0x1;
		GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT = 0x0;
		delay_us(3000);
	}
	else
	{
		while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
		while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
		SRIC_Run();
		MSPI_Set_AITMODE(eSensingMode);
		MSPI_Cmd(ENABLE);
		while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
		while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
	}
#else /* USED_LPWG_MODE_CONTROL */
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
	SRIC_Run();
	MSPI_Set_AITMODE(eSensingMode);
	MSPI_Cmd(ENABLE);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
#endif /* USED_LPWG_MODE_CONTROL */
	
	MSPI_Cmd(ENABLE);
	PWMDRV_Cmd(ENABLE);
	MSPI_ITConfig(ENABLE);	

//	PWMDRV_Cmd(ENABLE);
#if USED_TPIC_MUXEN_ON_OFF_CONTROL
	HAL_SetTPICMuxEnControl(YES);
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
#if USED_TSYNC2_INPUT_CONTROL
	GPIO->tGPIO_PU_1._GPIO_TSYNC2_IN = 0x0;	// Input
	init_EXIT(PIN_GPA37, EDGE_DETECTION_GPIO, BOTH_EDGE_GPIO, POSITIVE_HIGH_GPIO, ENABLE_GPIO);
	NVIC_SetPriority(EXTI0_IRQn, EXTI0_IRQn_Priority);
	NVIC_EnableIRQ(EXTI0_IRQn);
#endif /* USED_TSYNC2_INPUT_CONTROL */

#if USED_NEW_TCON_BOARD
	PWMDRV->FW_CTRL_b.VSYNC_IN = 1;
////	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
////	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
#endif /* USED_NEW_TCON_BOARD */

	return YES;
}

void Hal_VccOff_State(void)
{
	// ECLK OFF
	SCRB->ECLK_CFG.ulBulk = ( SCB_VECTKEY
	| 0         << 0
	| 7         << 4
	| 0  << 9 );

	//Tsync Pull-Down
	//Out
	GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 0x0;
	GPIO->tGPIO_DIR_1._GPIO_TSYNC_OUT  = 0x1;  // OUTPUT
	GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT = 0x0;

	//In
	GPIO->tGPIO_AFIO_1._GPIO_TSYNC_IN = 0x0;
	GPIO->tGPIO_DIR_0._GPIO_TSYNC_IN  = 0x1;  // OUTPUT
	GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN = 0x0;

	//Vsync Pull-Down
	GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 0x0; // VSYNC
	GPIO->tGPIO_DIR_0._GPIO_VSYNC  = 0x1;  // OUTPUT
	GPIO->tGPIO_DATA_0._GPIO_VSYNC = 0x0;

	//MSPI Pull-Down
	initGPIO(PIN_MSPI_SSN_0,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_SSN_1,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_SSN_2,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_SSN_3,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_SSN_4,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_SSN_5,GPIO_Mode0_GPIO,Output);

	initGPIO(PIN_MSPI_MOSI_0,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_MOSI_1,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_MOSI_2,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_MOSI_3,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_MOSI_4,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_MOSI_5,GPIO_Mode0_GPIO,Output);

	initGPIO(PIN_MSPI_MISO_0,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_MISO_1,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_MISO_2,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_MISO_3,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_MISO_4,GPIO_Mode0_GPIO,Output);
	initGPIO(PIN_MSPI_MISO_5,GPIO_Mode0_GPIO,Output);

	writeBitToGPIO( PIN_MSPI_SSN_0, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_1, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_2, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_3, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_4, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_5, LOW);

	writeBitToGPIO( PIN_MSPI_MOSI_0, LOW);
	writeBitToGPIO( PIN_MSPI_MOSI_1, LOW);
	writeBitToGPIO( PIN_MSPI_MOSI_2, LOW);
	writeBitToGPIO( PIN_MSPI_MOSI_3, LOW);
	writeBitToGPIO( PIN_MSPI_MOSI_4, LOW);
	writeBitToGPIO( PIN_MSPI_MOSI_5, LOW);

	writeBitToGPIO( PIN_MSPI_MISO_0, LOW);
	writeBitToGPIO( PIN_MSPI_MISO_1, LOW);
	writeBitToGPIO( PIN_MSPI_MISO_2, LOW);
	writeBitToGPIO( PIN_MSPI_MISO_3, LOW);
	writeBitToGPIO( PIN_MSPI_MISO_4, LOW);
	writeBitToGPIO( PIN_MSPI_MISO_5, LOW);

	//TP EN -> GPIO -> Low
	GPIO->tGPIO_DATA_1._GPIO_TP_EN = 0x00;
	GPIO->tGPIO_DIR_1._GPIO_TP_EN = 0x1;  // OUTPUT
	GPIO->tGPIO_AFIO_2._GPIO_TP_EN = 0x0;

	//PWM Pull-Down
	GPIO->tGPIO_AFIO_1._GPIO_PWM_SRIC = 0x0; // PWM_TX
	GPIO->tGPIO_DIR_0._GPIO_PWM_SRIC  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_PWM_SRIC = 0x0;
#if USED_TEST_OPERATION_ENABLE
	GPIO->tGPIO_AFIO_1._GPIO_PWM_TPIC = 0x0; // LFD
	GPIO->tGPIO_DIR_0._GPIO_PWM_TPIC  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_PWM_TPIC = 0x0;
#endif
	//SCLK Pull-Down
	GPIO->tGPIO_AFIO_0._GPIO_MSPI_0_SCLK = 0x0; // 0:GPIO, 1:MSPI0_MST_SCLK
	GPIO->tGPIO_DIR_0._GPIO_MSPI_0_SCLK  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_MSPI_0_SCLK = 0x0;

	GPIO->tGPIO_AFIO_0._GPIO_MSPI_1_SCLK = 0x0; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DIR_0._GPIO_MSPI_1_SCLK  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_MSPI_1_SCLK = 0x0;

	GPIO->tGPIO_AFIO_0._GPIO_MSPI_2_SCLK = 0x0; // 0:GPIO, 1:MSPI2_MST_SCLK
	GPIO->tGPIO_DIR_0._GPIO_MSPI_2_SCLK  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_MSPI_2_SCLK = 0x0;

	GPIO->tGPIO_AFIO_0._GPIO_MSPI_3_SCLK = 0x0; // 0:GPIO, 1:MSPI3_MST_SCLK
	GPIO->tGPIO_DIR_0._GPIO_MSPI_3_SCLK  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_MSPI_3_SCLK = 0x0;

	GPIO->tGPIO_AFIO_1._GPIO_MSPI_4_SCLK = 0x0; // 0:GPIO, 1:MSPI4_MST_SCLK
	GPIO->tGPIO_DIR_0._GPIO_MSPI_4_SCLK  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_MSPI_4_SCLK = 0x0;

	GPIO->tGPIO_AFIO_1._GPIO_MSPI_5_SCLK = 0x0; // 0:GPIO, 1:MSPI5_MST_SCLK
	GPIO->tGPIO_DIR_0._GPIO_MSPI_5_SCLK  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_MSPI_5_SCLK = 0x0;

	//ECLK Pull-Down
	GPIO->tGPIO_AFIO_1._GPIO_ECLK_0 = 0x0;  // ECLK0
	GPIO->tGPIO_DIR_0._GPIO_ECLK_0  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_ECLK_0 = 0x0;

	GPIO->tGPIO_AFIO_1._GPIO_ECLK_1 = 0x0;  // ECLK1
	GPIO->tGPIO_DIR_0._GPIO_ECLK_1  = 0x1;  // output
	GPIO->tGPIO_DATA_0._GPIO_ECLK_1 = 0x0;
	
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
}

/*
 * NOTE : New Function
 */
void HAL_Initialize(bool_t bIsLPWG)
{
	ptHalInfo = hal_GetInfo();
#if (USED_LPWG_MODE_CONTROL == NO)
#if USED_PEN_MODE_OPERATION
#if USED_INIT_PEN_MODE
	ptHalInfo->eSensingMode = SM_FINGER_PEN_ACTIVE_MODE;
#else /* USED_INIT_PEN_MODE */
	ptHalInfo->eSensingMode = SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_MAIN_MODE;
#endif /* USED_INIT_PEN_MODE */
#else /* USED_PEN_MODE_OPERATION */
	if(bIsLPWG)
	{
		ptHalInfo->eSensingMode = SM_S3_ACTIVE_MODE;
	}
	else
	{
		ptHalInfo->eSensingMode = SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE;
	}
#endif /* USED_PEN_MODE_OPERATION */
#endif /* (USED_LPWG_MODE_CONTROL == NO) */	
	PWMDRV_Initialize();
}

eSENSING_CHANGE_MODE_t HAL_GetSensingChangeMode(void)
{
	return ptHalInfo->eSensingChangeMode;
}

void HAL_SetSensingChangeMode(eSENSING_CHANGE_MODE_t mode)
{
#if USED_ECLK_ON_OFF_CONTROL
	// Mode 蹂�寃쎌떆 EClk On/Off Control�쓣 Disable�떆耳쒖빞 �븳�떎.
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
	ptHalInfo->eSensingMode = mode;
}

#if USED_IDLE_MODE_CONTROL
__IO uint32_t ulVSyncIrqFlg = 0;
#endif /* USED_IDLE_MODE_CONTROL */

bool_t HAL_CheckSensningModeChange(eSENSING_CHANGE_MODE_t mode)
{
	bool_t bIsModeChange = YES;
	eSENSING_MODE_t ePastSensingMode = HAL_GetSensingMode();

	switch(mode)
	{
		case SM_CHANGE_ACTIVE_FRQ_MAIN_MODE:
		{
			if(ePastSensingMode == SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE)
			{
				PWMDRV_Set_Pulse_Config(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
				HAL_SetSensingMode(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
			}
			else
			{
				bIsModeChange = NO;
			}
			break;
		}
		case SM_CHANGE_ACTIVE_FRQ_HOP1_MODE:
		{
			PWMDRV_Set_Pulse_Config(SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE);
			HAL_SetSensingMode(SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE);
			break;
		}
		case SM_CHANGE_COMPLETE:
		{
			bIsModeChange = NO;
			break;
		}
		default:
		{
			bIsModeChange = NO;
			break;
		}
	}

	return bIsModeChange;
}

void HAL_SetLocalIndex(uint8_t index, uint8_t val)
{
	MSPI_Set_TLPMODE();
//	SW92400_Set_LocalPenSensingStatusCTRL(index, val);
	MSPI_Set_AITMODE(HAL_GetSensingMode());
}

uint16_t * HAL_GetBaseImagePointer(eSENSING_MODE_t mode, eBaseImageType_t type)
{
	uint16_t * pImage = NULL;

	if(IS_ACTIVE_MODE(mode))
	{
		if(IS_ACTIVE_MODE_FRQ_HOP1(mode))
		{
			if(type == BASELINE_TYPE_FULL)
			{
				pImage = HAL_GET_HOPP1_BASELINE_IMAGE_PTR();
			}
			else
			{
				pImage = HAL_NI_GET_BASELINE_IMAGE_PTR();
			}
		}
		else if(IS_ACTIVE_MODE_FRQ_HOP2(mode))
		{
			if(type == BASELINE_TYPE_FULL)
			{
				pImage = HAL_GET_HOPP2_BASELINE_IMAGE_PTR();
			}
			else
			{
				pImage = HAL_NI_GET_BASELINE_IMAGE_PTR();
			}
		}
		else
		{
			if(type == BASELINE_TYPE_FULL)
			{
				pImage = HAL_GET_BASELINE_IMAGE_PTR();
			}
			else
			{
				pImage = HAL_NI_GET_HOP1_BASELINE_IMAGE_PTR();
			}
		}
	}
	else
	{
		pImage = HAL_NI_GET_BASELINE_IMAGE_PTR();
	}

	return pImage;
}

#if USED_MCU_IDLE_LOW_PWR_CONTROL
uint32_t Hal_Exit_MCU_Sleep(void)
{
	tUMC_PLL_UC_t tUMC_PLL_UC;
	tUMC_PLL_UC.ulBulk = SCRB->UMC_PLL_UC.ulBulk;
	tUMC_PLL_UC.tBit.PLL_STBY_I = 0;
	tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
	tUMC_PLL_UC.tBit.FBDIV = 15;	// Feedback divider number = (FBDIV) : (5 ~ 50)
	tUMC_PLL_UC.tBit.OUTDIV = 1;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)

	BLOCK_RESET_DELAY;

	// wait PLL Locked
	while (SCRB->UMC_PLL_IS.tBit.PLL_LOCKED_O == 0)
	{
	};

	tCLK_DIV_t tCLK_DIV;
	tCLK_DIV.ulBulk = SCRB->CLK_DIV.ulBulk;
	tCLK_DIV.tBit.HCLK_DIV = 0;
	tCLK_DIV.tBit.PCLK_DIV = 1;
#if USED_ECLK_ON_OFF_CONTROL
	tCLK_DIV.tBit.TIMCLK_DIV = 0; /*timer clk : 0(/1), 1(/2), ... 7(/128) */
#else /* USED_ECLK_ON_OFF_CONTROL */
	tCLK_DIV.tBit.TIMCLK_DIV = 2; /*timer clk : 0(/1), 1(/2), ... 7(/128) */
#endif /* USED_ECLK_ON_OFF_CONTROL */
	tCLK_DIV.tBit.WDTCLK_DIV = 3;
	tCLK_DIV.tBit.SSCGIN_DIV = 1;
	tCLK_DIV.tBit.TOUCHCLK_DIV = 0;
	tCLK_DIV.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CLK_DIV.ulBulk = tCLK_DIV.ulBulk;

	tCK_ENA_RUN0_t tCK_ENA_RUN0;
	tCK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
#ifdef MODE_I2C
	tCK_ENA_RUN0.tBit.r_USB_CLK_ENA = 0;
#else
	tCK_ENA_RUN0.tBit.r_USB_CLK_ENA = 1;
#endif
	tCK_ENA_RUN0.tBit.r_WDT_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_TIM_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_LFDTX_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_TSPI_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_DSPA_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_DSPB_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_SRAM1_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM2_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM3_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_DMAC_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_I2C_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_FLITF_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_GPIO_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN0.ulBulk = tCK_ENA_RUN0.ulBulk;

	tCK_ENA_RUN1_t tCK_ENA_RUN1;
	tCK_ENA_RUN1.ulBulk = SCRB->CK_ENA_RUN1.ulBulk;
	tCK_ENA_RUN1.tBit.r_MSPI01_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI23_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI45_CLK_ENA = 1;
//	tCK_ENA_RUN1.tBit.r_SIF_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_SFL_CLK_ENA = 0;
	tCK_ENA_RUN1.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN1.ulBulk = tCK_ENA_RUN1.ulBulk;

#ifdef MODE_I2C
	tUSB_PHY_FC_t tUSB_PHY_FC;
	tUSB_PHY_FC.ulBulk = SCRB->USB_PHY_FC.ulBulk;
	tUSB_PHY_FC.tBit.PLLALIV = 0;
	tUSB_PHY_FC.tBit.PONRST = 0;
	SCRB->USB_PHY_FC.ulBulk = tUSB_PHY_FC.ulBulk;

	BLOCK_RESET_DELAY;

	SCRB->RST_CTRL.ulBulk &= ~(1 << 5);

	BLOCK_RESET_DELAY;

	SCRB->RST_CTRL.ulBulk |= 1 << 5;
#endif

	tLGD_SSC_UC_t tLGD_SSC_UC;
	tLGD_SSC_UC.ulBulk = SCRB->LGD_SSC_UC.ulBulk;
	tLGD_SSC_UC.tBit.SSCG_PDB = 1;
	tLGD_SSC_UC.tBit.SSCG_EN = 1;//1;
	tLGD_SSC_UC.tBit.SSCG_INIT = 0;
	tLGD_SSC_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->LGD_SSC_UC.ulBulk = tLGD_SSC_UC.ulBulk;

	return YES;
}

uint32_t Hal_Enter_MCU_Sleep(void)
{
	tUMC_PLL_UC_t tUMC_PLL_UC;
	tUMC_PLL_UC.ulBulk = SCRB->UMC_PLL_UC.ulBulk;
	tUMC_PLL_UC.tBit.PLL_STBY_I = 0;
	tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
	tUMC_PLL_UC.tBit.FBDIV = 10;	// Feedback divider number = (FBDIV) : (5 ~ 50)
	tUMC_PLL_UC.tBit.OUTDIV = 2;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)

	BLOCK_RESET_DELAY;

	// wait PLL Locked
	while (SCRB->UMC_PLL_IS.tBit.PLL_LOCKED_O == 0)
	{
	};

	tCLK_DIV_t tCLK_DIV;
	tCLK_DIV.ulBulk = SCRB->CLK_DIV.ulBulk;
	tCLK_DIV.tBit.HCLK_DIV = 0;
	tCLK_DIV.tBit.PCLK_DIV = 2;
#if USED_ECLK_ON_OFF_CONTROL
	tCLK_DIV.tBit.TIMCLK_DIV = 0; /*timer clk : 0(/1), 1(/2), ... 7(/128) */
#else /* USED_ECLK_ON_OFF_CONTROL */
	tCLK_DIV.tBit.TIMCLK_DIV = 7; /*timer clk : 0(/1), 1(/2), ... 7(/128) */
#endif /* USED_ECLK_ON_OFF_CONTROL */
	tCLK_DIV.tBit.WDTCLK_DIV = 7;
	tCLK_DIV.tBit.SSCGIN_DIV = 1;
	tCLK_DIV.tBit.TOUCHCLK_DIV = 0;
	tCLK_DIV.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CLK_DIV.ulBulk = tCLK_DIV.ulBulk;

	tCK_ENA_RUN0_t tCK_ENA_RUN0;
	tCK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
#ifdef MODE_I2C
	tCK_ENA_RUN0.tBit.r_USB_CLK_ENA = 0;
#else
	tCK_ENA_RUN0.tBit.r_USB_CLK_ENA = 1;
#endif
	tCK_ENA_RUN0.tBit.r_WDT_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_TIM_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_LFDTX_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_TSPI_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_DSPA_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_DSPB_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_SRAM1_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM2_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM3_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_DMAC_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_I2C_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_FLITF_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_GPIO_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN0.ulBulk = tCK_ENA_RUN0.ulBulk;

	tCK_ENA_RUN1_t tCK_ENA_RUN1;
	tCK_ENA_RUN1.ulBulk = SCRB->CK_ENA_RUN1.ulBulk;
	tCK_ENA_RUN1.tBit.r_MSPI01_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI23_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI45_CLK_ENA = 1;
//	tCK_ENA_RUN1.tBit.r_SIF_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_SFL_CLK_ENA = 0;
	tCK_ENA_RUN1.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN1.ulBulk = tCK_ENA_RUN1.ulBulk;

#ifdef MODE_I2C
	tUSB_PHY_FC_t tUSB_PHY_FC;
	tUSB_PHY_FC.ulBulk = SCRB->USB_PHY_FC.ulBulk;
	tUSB_PHY_FC.tBit.PLLALIV = 0;
	tUSB_PHY_FC.tBit.PONRST = 0;
	SCRB->USB_PHY_FC.ulBulk = tUSB_PHY_FC.ulBulk;

	BLOCK_RESET_DELAY;

	SCRB->RST_CTRL.ulBulk &= ~(1 << 5);

	BLOCK_RESET_DELAY;

	SCRB->RST_CTRL.ulBulk |= 1 << 5;
#endif

	tLGD_SSC_UC_t tLGD_SSC_UC;
	tLGD_SSC_UC.ulBulk = SCRB->LGD_SSC_UC.ulBulk;
	tLGD_SSC_UC.tBit.SSCG_PDB = 1;
	tLGD_SSC_UC.tBit.SSCG_EN = 1;//1;
	tLGD_SSC_UC.tBit.SSCG_INIT = 0;
	tLGD_SSC_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->LGD_SSC_UC.ulBulk = tLGD_SSC_UC.ulBulk;

	return NO;
}
#endif /* USED_MCU_IDLE_LOW_PWR_CONTROL */

#if USED_LPWG_MCU_SLEEP
void Hal_WaitSampleDoneSleep(void)
{
	tCK_ENA_RUN0_t tCK_ENA_RUN0;
	tCK_ENA_RUN1_t tCK_ENA_RUN1;
//	tCLK_SRC_SEL_t tCLK_SRC_SEL;


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
	 * Systick�룄 二쎌씠�옄..
	 * TODO : �씠濡� �씤�븳 Side Effect Check.. USB履쎌뿉�꽌 Systick�쑝濡� Scan time�쓣 Check�븳�떎.
	 */
	SysTick_DeInitialize();

	__WFI();
	/*
	 * Stand Alone�뿉�꽌�뒗 Timer IRQ�뿉�꽌 Clock�쓣 �썝蹂� �떆�궓�떎.
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
//		delay_usec(1); // PLL諛� Clock Divider�꽕�젙 �쟾�씠湲� �븣臾몄뿉.. �뒓由щ떎.. ���왂 1/10�젙�룄..
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
//		tCLK_DIV.tBit.PCLK_DIV = 3; // MSPI Clk�씠 諛쏆븘�꽌 �궗�슜..
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
//	 * Systick�룄 二쎌씠�옄..
//	 * TODO : �씠濡� �씤�븳 Side Effect Check.. USB履쎌뿉�꽌 Systick�쑝濡� Scan time�쓣 Check�븳�떎.
//	 */
//	SysTick_DeInitialize();
//
//	__WFI();
//	module_System_Init();
}
#endif /* USED_LPWG_MCU_SLEEP */
