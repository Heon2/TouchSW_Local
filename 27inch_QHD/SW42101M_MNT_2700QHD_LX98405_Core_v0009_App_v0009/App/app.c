/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_main.c
 * created on : 23. 4. 2018
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
#include "app_def.h"
#include "app.h"

#define STARTDELAY	2000000
volatile uint32_t delayCnt = 0;

int main(void)
{
//	for(delayCnt=0; delayCnt<STARTDELAY; delayCnt++);
	
	app_MainProc();
}

#pragma O0

__APP void PendSV_Handler(void)
{
	if(Fncp_PendSV_IRQHandler)
	{
		Fncp_PendSV_IRQHandler();
	}
}

__APP void SysTick_Handler(void)
{
	if(Fncp_Systick_IRQHandler)
	{
		Fncp_Systick_IRQHandler();
	}	
}

__APP void I2C_IRQHandler(void)
{
	if(Fncp_I2C_IRQHandler)
	{
		Fncp_I2C_IRQHandler();
	}
}

__APP void WDT_IRQHandler(void)
{
	if(Fncp_WDT_IRQHandler)
	{
		Fncp_WDT_IRQHandler();
	}
}

__APP void EXTI0_IRQHandler(void)
{
	if(Fncp_EXTI0_IRQHandler)
	{
		Fncp_EXTI0_IRQHandler();
	}
}

__APP void EXTI1_IRQHandler(void)
{
	if(Fncp_EXTI1_IRQHandler)
	{
		Fncp_EXTI1_IRQHandler();
	}
}

__APP void TIMER_IRQHandler(void)
{
	if(Fncp_TIMER_IRQHandler)
	{
		Fncp_TIMER_IRQHandler();
	}
}

__APP void TSPI_IRQHandler(void)
{
	if(Fncp_TSPI_IRQHandler)
	{
		Fncp_TSPI_IRQHandler();
	}
}

__APP void USB_IRQHandler(void)
{
	if(Fncp_USB_IRQHandler)
	{
		Fncp_USB_IRQHandler();
	}
}

__APP void PWMDRV_IRQHandler(void)
{
	if(Fncp_PWMDRV_IRQHandler)
	{
		Fncp_PWMDRV_IRQHandler();
	}
}

__APP void MSPI_IRQHandler(void)
{
	if(Fncp_MSPI_IRQHandler)
	{
		Fncp_MSPI_IRQHandler();
	}
}

__APP void GPDMA_IRQHandler(void)
{
	if(Fncp_GPDMA_IRQHandler)
	{
		Fncp_GPDMA_IRQHandler();
	}
}

__APP void DSP_A_IRQHandler(void)
{
	if(Fncp_DSP_A_IRQHandler)
	{
		Fncp_DSP_A_IRQHandler();
	}
}

__APP void DSP_B_IRQHandler(void)
{
	if(Fncp_DSP_B_IRQHandler)
	{
		Fncp_DSP_B_IRQHandler();
	}
}

__APP void PLL_IRQHandler(void)
{
	if(Fncp_PLL_IRQHandler)
	{
		Fncp_PLL_IRQHandler();
	}
}

__APP void FLITF_IRQHandler(void)
{
	if(Fncp_FLITF_IRQHandler)
	{
		Fncp_FLITF_IRQHandler();
	}
}
