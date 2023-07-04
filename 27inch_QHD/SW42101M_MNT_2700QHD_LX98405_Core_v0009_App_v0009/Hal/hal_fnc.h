/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : hal_fnc.h
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

#ifndef _HAL_FNC_H_
#define _HAL_FNC_H_


extern void (*Fncp_PendSV_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_Systick_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_I2C_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_WDT_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_EXTI0_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_EXTI1_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_TIMER_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_TSPI_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_USB_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_PWMDRV_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_MSPI_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_GPDMA_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_DSP_A_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_DSP_B_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_PLL_IRQHandler)(void) __DATA_HEAD;
extern void (*Fncp_FLITF_IRQHandler)(void) __DATA_HEAD;


#endif /* _HAL_FNC_H_ */
