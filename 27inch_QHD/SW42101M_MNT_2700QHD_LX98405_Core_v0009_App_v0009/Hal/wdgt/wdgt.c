/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : wdgt.c
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


void WDGT_Init(WDT_TypeDef* WDGTx)
{
	WDGTS_InitTypeDef WDGT_InitStructure;
	
	WDGT_InitStructure.WDGT_Count = 0xffff;								// (WDT_WIDTH) Max : 0xffff, Watchdog Count Period Register Determines the counting periodof WDT	
	WDGT_InitStructure.WDGT_Prescaler = WDGT_CLOCK_PCLKDIVIDED128;		// (WDT_CON) Max : 7, Watchdog Clock Select Register
	WDGT_InitStructure.WDGT_ResetCount = 0x1;						 	// (WDT_RST_DUR) Max : 0xf, Watchdog Reset Width Register Determines the periodof the RESET
	WDGT_InitStructure.WDGT_ResetDelayCount = 0x1;					// (WDT_RST_DLY) Max : 0xffff, Watchdog Reset Delay Width Register Determines the delay periodbetween interrupt and Reset
	WDGT_InitStructure.WDGT_RSTIRQChannelCmd = DISABLE;	
	
	if(WDGT_GetAccessRegStatus(WDGTx) == (uint16_t)(0x0001))
		WDGT_SetLock(WDGTx);

	WDGT_SetConfig(WDGTx, &WDGT_InitStructure);	
	WDGT_Cmd(WDGTx, ENABLE);
	WDGT_ITConfig(WDGTx, ENABLE); //not use interrupt	
}

void WDGT_DeInit(WDT_TypeDef* WDGTx)
{	
	WDGT_SetCLR(WDGTx);

	if(WDGT_GetAccessRegStatus(WDGTx) == (uint16_t)(0x0000))
		WDGT_SetLock(WDGTx);
}

void WDGT_SetConfig(WDT_TypeDef* WDGTx, WDGTS_InitTypeDef* WDGT_InitStructure)
{	
	WDGTx->WDT_WIDTH_b.wdtwidth = WDGT_InitStructure->WDGT_Count;
	WDGTx->WDT_RST_DLY_b.rstdlywidth = WDGT_InitStructure->WDGT_ResetDelayCount;
	WDGTx->WDT_RST_DUR_b.rstdlywidth = WDGT_InitStructure->WDGT_ResetCount;
	WDGTx->WDT_CON_b.wdtclksel = WDGT_InitStructure->WDGT_Prescaler;

	if(WDGT_InitStructure->WDGT_RSTIRQChannelCmd != DISABLE)
	{
		WDGTx->WDT_CON |= WDGT_RESET_Enable;
	}
	else
	{
		WDGTx->WDT_CON &= WDGT_RESET_DisableMask;
	}		
}

void WDGT_SetLock(WDT_TypeDef* WDGTx)
{
	WDGTx->WDT_ACCE_b.wdtLock = WDGT_ACCEDSS_KEY;
}

void WDGT_SetCLR(WDT_TypeDef* WDGTx)
{
	WDGTx->WDT_CLR_b.wdtClr = WDGT_Clear;
}


void WDGT_ITConfig(WDT_TypeDef* WDGTx, FunctionalState NewFunction)
{
	if(NewFunction != DISABLE)
	{
		WDGTx->WDT_CON |= WDGT_INT_Enable;
	}
	else
	{
		WDGTx->WDT_CON &= WDGT_INT_DisableMask;
	}
}

void WDGT_Cmd(WDT_TypeDef* WDGTx, FunctionalState NewFunction)
{
	if(NewFunction != DISABLE)
	{
		WDGTx->WDT_CON |= WDGT_WDGT_Enable;
	}
	else
	{
		WDGTx->WDT_CON &= WDGT_WDGT_DisableMask;
	}
}

uint16_t WDGT_GetAccessRegStatus(WDT_TypeDef* WDGTx)
{
	return (WDGTx->WDT_ACCE_b.wdtLock & WDGT_AccessMask);
}

void WDT_InterruptHandler(void)
{
	if(I2C->I2C_GLB_SR.tBit.IspMode == 1)
	{
		Hal_WDT_DeInit();
	}
	else
	{
		UWDT->WDT_CLR_b.wdtClr = 1;
		UWDT->WDT_WIDTH_b.wdtwidth = 1;
		UWDT->WDT_CON_b.wdtrsten = 1;
		UWDT->WDT_CON_b.wdten = 1;
	}
}

void Hal_Kick_DOG(void)
{
	WDGT_SetCLR(UWDT);
	
	if(!WDGT_GetAccessRegStatus(UWDT))
		WDGT_Init(UWDT);
}

void Hal_Release_DOG(void)
{
	WDGT_SetCLR(UWDT);
}

__IO bool_t wdt_init = FALSE;
void Hal_WDT_Init(void)
{
	Fncp_WDT_IRQHandler = &WDT_InterruptHandler;
	SET_BIT(SCRB->CK_ENA_RUN0.ulBulk, (SCB_VECTKEY | 0x02)); // Enable WDT CLK
	NVIC_ClearPendingIRQ(WDT_IRQn);
	NVIC_SetPriority(WDT_IRQn, WDT_IRQn_Priority);
	NVIC_EnableIRQ(WDT_IRQn);
	WDGT_Init(UWDT);
	wdt_init = TRUE;
}

void Hal_WDT_DeInit(void)
{
//	NVIC_SetPriority(WDT_IRQn, WDT_IRQn_Priority);
	NVIC_DisableIRQ(WDT_IRQn);
	NVIC_ClearPendingIRQ(WDT_IRQn);
	WDGT_DeInit(UWDT);
	wdt_init = FALSE;
}
