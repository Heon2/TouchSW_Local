/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : wdgt.c
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


void WDGT_InterruptHandler(void)
{
	if(I2C->I2C_GLB_SR.tBit.IspMode)		//	I2C slave case??
	{
		Hal_WDT_DeInit();
	}
	else
	{
		// TO_BE_DEFINED watchdog occurred!!!
	}
}

void WDGT_Initialize(void)
{
	Fncp_WDGT_IRQHandler = &WDGT_InterruptHandler;

	NVIC_ClearPendingIRQ(WDGT_IRQn);
	NVIC_SetPriority(WDGT_IRQn, WDGT_IRQn_Priority);
	NVIC_EnableIRQ(WDGT_IRQn);

	WDT->WDOG_LOAD = WDGT_LOAD_COUNT_NUM;//0xFFFFFFFF;
	
	WDT->WDOG_CONTROL.tBit.wdt_int_en = 1;       
	WDT->WDOG_CONTROL.tBit.wdt_rst_en = 1;       
	
	WDT->WDOG_RSTCTRL.tBit.watchdog_reset_en = 1;
}

void WDGT_DeInitialize(void)
{
	WDT->WDOG_CONTROL.w = 0;
	WDT->WDOG_RSTCTRL.tBit.watchdog_reset_en = 0;

	NVIC_DisableIRQ(WDGT_IRQn);
	NVIC_ClearPendingIRQ(WDGT_IRQn);
	Fncp_WDGT_IRQHandler = NULL;
}

void Hal_Kick_DOG(void)
{
	WDT->WDOG_LOAD = WDGT_LOAD_COUNT_NUM;
}

void Hal_Long_Kick_DOG(void)
{
	WDT->WDOG_LOAD = WDGT_LONG_LOAD_COUNT_NUM;
}

__IO bool_t wdt_init = FALSE;
void Hal_WDT_Init(void)
{
	WDGT_Initialize();
	wdt_init = TRUE;
}

void Hal_WDT_DeInit(void)
{
	WDGT_DeInitialize();
	wdt_init = FALSE;
}

void Hal_WDT_ForceReset(void)
{
	WDGT_Initialize();
	WDT->WDOG_LOAD = 10;
	while(1);
}
