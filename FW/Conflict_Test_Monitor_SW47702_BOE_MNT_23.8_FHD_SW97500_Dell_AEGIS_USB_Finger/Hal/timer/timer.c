/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : timer.c
 * created on : 10. 05. 2019
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


__IO uint32_t ulTimerIRQHandle[OPERATION_TIMER_UNITNUM] = {0, };
__IO uint8_t ulTimerOneShotEn[OPERATION_TIMER_UNITNUM] = {0, };

void TIMER_InterruptHandler(void)
{
	if(SCRB->SYS_INT_ST.tBit.int_timer0)
//	if (TIMER->TIMER_STATUS.tBit.timer0_status)
	{
		ulTimerIRQHandle[TIMER_1UNIT] = 1;
		if(Fncp_Systick_IRQHandler)
		{
			Fncp_Systick_IRQHandler();
		}
		TIMER->TIMER_INT_CLR.tBit.timer0_int_clr = 1;
	}

	if(SCRB->SYS_INT_ST.tBit.int_timer1)
//	if (TIMER->TIMER_STATUS.tBit.timer1_status)
	{
		ulTimerIRQHandle[TIMER_2UNIT] = 1;
		TIMER->TIMER_INT_CLR.tBit.timer1_int_clr = 1;
	}

	if(SCRB->SYS_INT_ST.tBit.int_timer2)
//	if (TIMER->TIMER_STATUS.tBit.timer2_status)
	{
		ulTimerIRQHandle[TIMER_3UNIT] = 1;
		TIMER->TIMER_INT_CLR.tBit.timer2_int_clr = 1;
	}

	if(SCRB->SYS_INT_ST.tBit.int_timer3)
//	if (TIMER->TIMER_STATUS.tBit.timer3_status)
	{
		ulTimerIRQHandle[TIMER_4UNIT] = 1;
		TIMER->TIMER_INT_CLR.tBit.timer3_int_clr = 1;
	}
}

void TIMER_Initialize(void)
{
	uint32_t ulTimerUnitIdx;

	Fncp_TIMER_IRQHandler = &TIMER_InterruptHandler;

	/*
	 * Timer Clock Set 12Mhz
	 */
	SCRB->SYS_MAINCLK_CFG.tBit.mclkdiv = 0;//12;	//	n+1 divider

	NVIC_ClearPendingIRQ(TIMER_IRQn);
	NVIC_SetPriority(TIMER_IRQn, TIMER_IRQn_Priority);
	NVIC_EnableIRQ(TIMER_IRQn);

	for( ulTimerUnitIdx = 0 ; ulTimerUnitIdx < OPERATION_TIMER_UNITNUM ; ulTimerUnitIdx++ )
		TIMER->TIMER_RELOAD[ulTimerUnitIdx].tBit.timer_prev_val = TIMER_CLOCK_DIV_1;
}

void TIMER_DeInitialize(void)
{
    TIMER->TIMER_CTRL.w = 0;

	NVIC_DisableIRQ(TIMER_IRQn);
	NVIC_ClearPendingIRQ(TIMER_IRQn);
	Fncp_TIMER_IRQHandler = NULL;
}

void TIMER_SetFreeRunningMode(tTimerOpHandleInfo_t * ptTimerHandle)
{
	switch( ptTimerHandle->ulTimerUnit ) {
	case 0:
		TIMER->TIMER_RELOAD[0].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk0_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer0_en = OFF;
		ulTimerOneShotEn[0] = 0;
		break;
	case 1:
		TIMER->TIMER_RELOAD[1].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk1_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer1_en = OFF;
		ulTimerOneShotEn[1] = 0;
		break;
	case 2:
		TIMER->TIMER_RELOAD[2].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk2_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer2_en = OFF;
		ulTimerOneShotEn[2] = 0;
		break;
	case 3:
		TIMER->TIMER_RELOAD[3].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk3_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer3_en = OFF;
		ulTimerOneShotEn[3] = 0;
		break;
	}
}

void TIMER_SetPeriodicMode(tTimerOpHandleInfo_t * ptTimerHandle)
{
	switch( ptTimerHandle->ulTimerUnit ) {
	case 0:
		TIMER->TIMER_RELOAD[0].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk0_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer0_en = ON;
		ulTimerOneShotEn[0] = 0;
		break;
	case 1:
		TIMER->TIMER_RELOAD[1].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk1_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer1_en = ON;
		ulTimerOneShotEn[1] = 0;
		break;
	case 2:
		TIMER->TIMER_RELOAD[2].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk2_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer2_en = ON;
		ulTimerOneShotEn[2] = 0;
		break;
	case 3:
		TIMER->TIMER_RELOAD[3].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk3_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer3_en = ON;
		ulTimerOneShotEn[3] = 0;
		break;
	}
}

void TIMER_SetOneShotMode(tTimerOpHandleInfo_t * ptTimerHandle)
{
	switch( ptTimerHandle->ulTimerUnit ) {
	case TIMER_1UNIT:
		TIMER->TIMER_RELOAD[0].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk0_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer0_en = ON;
		ulTimerOneShotEn[0] = 1;
		break;
	case TIMER_2UNIT:
		TIMER->TIMER_RELOAD[1].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk1_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer1_en = ON;
		ulTimerOneShotEn[1] = 1;
		break;
	case TIMER_3UNIT:
		TIMER->TIMER_RELOAD[2].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk2_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer2_en = ON;
		ulTimerOneShotEn[2] = 1;
		break;
	case TIMER_4UNIT:
		TIMER->TIMER_RELOAD[3].tBit.timer_reload_val = ptTimerHandle->ulLoadCount;
		SCRB->SYS_CLK_CTL.tBit.timclk3_en = ON;
		TIMER->TIMER_CTRL.tBit.int_timer3_en = ON;
		ulTimerOneShotEn[3] = 1;
		break;
	}
}

void TIMER_StartTimer(uint32_t Unit)
{
	switch( Unit ) {
	case TIMER_1UNIT:
		ulTimerIRQHandle[0] = 0;
		if( ulTimerOneShotEn[0] ) {
			TIMER->TIMER_OS_START.tBit.timer0_os_start = ON;
		}
		else {
			TIMER->TIMER_CTRL.tBit.timer0_en = ON;
		}
		break;
	case TIMER_2UNIT:
		ulTimerIRQHandle[1] = 0;
		if( ulTimerOneShotEn[1] ) {
			TIMER->TIMER_OS_START.tBit.timer1_os_start = ON;
		}
		else {
			TIMER->TIMER_CTRL.tBit.timer1_en = ON;
		}
		break;
	case TIMER_3UNIT:
		ulTimerIRQHandle[2] = 0;
		if( ulTimerOneShotEn[2] ) {
			TIMER->TIMER_OS_START.tBit.timer2_os_start = ON;
		}
		else {
			TIMER->TIMER_CTRL.tBit.timer2_en = ON;
		}
		break;
	case TIMER_4UNIT:
		ulTimerIRQHandle[3] = 0;
		if( ulTimerOneShotEn[3] ) {
			TIMER->TIMER_OS_START.tBit.timer3_os_start = ON;
		}
		else {
			TIMER->TIMER_CTRL.tBit.timer3_en = ON;
		}
		break;
	}
}

void TIMER_StopTimer(uint32_t Unit)
{
	switch( Unit ) {
	case TIMER_1UNIT:
		ulTimerIRQHandle[0] = 0;
		TIMER->TIMER_CTRL.tBit.int_timer0_en = OFF;
		TIMER->TIMER_CTRL.tBit.timer0_en = OFF;
		SCRB->SYS_CLK_CTL.tBit.timclk0_en = OFF;
		break;
	case TIMER_2UNIT:
		ulTimerIRQHandle[1] = 0;
		TIMER->TIMER_CTRL.tBit.int_timer1_en = OFF;
		TIMER->TIMER_CTRL.tBit.timer1_en = OFF;
		SCRB->SYS_CLK_CTL.tBit.timclk1_en = OFF;
		break;
	case TIMER_3UNIT:
		ulTimerIRQHandle[2] = 0;
		TIMER->TIMER_CTRL.tBit.int_timer2_en = OFF;
		TIMER->TIMER_CTRL.tBit.timer2_en = OFF;
		SCRB->SYS_CLK_CTL.tBit.timclk2_en = OFF;
		break;
	case TIMER_4UNIT:
		ulTimerIRQHandle[3] = 0;
		TIMER->TIMER_CTRL.tBit.int_timer3_en = OFF;
		TIMER->TIMER_CTRL.tBit.timer3_en = OFF;
		SCRB->SYS_CLK_CTL.tBit.timclk3_en = OFF;
		break;
	}
}

uint32_t TIMER_GetLoadCount(uint32_t Unit)
{
	uint32_t ulCount = 0;
	switch( Unit ) {
	case TIMER_1UNIT: ulCount = TIMER->TIMER_VALUE[0]; break;
	case TIMER_2UNIT: ulCount = TIMER->TIMER_VALUE[1]; break;
	case TIMER_3UNIT: ulCount = TIMER->TIMER_VALUE[2]; break;
	case TIMER_4UNIT: ulCount = TIMER->TIMER_VALUE[3]; break;
	}

	return ulCount;
}

void TIMER_WaitForIrq(uint32_t Unit)
{
	while(ulTimerIRQHandle[Unit] == 0)
	{
//		__WFI();
	}
	ulTimerIRQHandle[Unit] = 0;
}

void medium_delay(uint32_t usec)
{
	/*
	 	Base on 96MHz
	 	1 		:    1.43	us
		5		:    2.78	us
		10 		:    4.58	us
		100 	:   36.08	us
		1000	:  351.4	us
		10000	: 3503.0	us
		time(usec) = 2.854 x (Clock) - 3.019
	*/
    __IO uint32_t i = 0;
    uint32_t ulCheckClk;
    ulCheckClk = ((2854 * usec) - 3019)/1000;

    for (i = 0; i < ulCheckClk; i++)
    {
        __ISB();
    }
}
