/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : scrb.h
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

#ifndef _SCRB_H_
#define _SCRB_H_


#define SCB_VECTKEY_VALUE  				(0x05FA)
#define SCB_VECTKEY       				(SCB_VECTKEY_VALUE << 16)

#define TMCU_MAIN_NOTRIM_CLOCK_SPEED	(12)
#define TMCU_MAIN_TRIM_CLOCK_SPEED		(96)


typedef enum
{
	CLK_ENA_USB = 0,
	CLK_ENA_WDT = 1,
	CLK_ENA_TIM = 2,
	CLK_ENA_PWMDRV = 3,
	CLK_ENA_TSPI = 4,
	CLK_ENA_DSPA = 5,
	CLK_ENA_DSPB = 6,
	CLK_ENA_SRAM1 = 7,
	CLK_ENA_SRAM2 = 8,
	CLK_ENA_SRAM3 = 9,
	CLK_ENA_DMAC = 10,
	CLK_ENA_I2C = 11,
	CLK_ENA_FLITF = 12,
	CLK_ENA_GPIO = 13,

	CLK_ENA_MSPI01 = 14,
	CLK_ENA_MSPI23 = 15,
	CLK_ENA_MSPI45 = 16,
	CLK_ENA_SIF = 17,
	CLK_ENA_SFL = 18,

} eCLK_ENA_BLOCK_t;

#if USED_IDLE_LOW_POWER
typedef enum
{
	CLK_NORMAL_CTRL = 0,
	CLK_IDLE_CTRL = 1,
} eClK_CTRL_STATUS_t;
#endif /* USED_IDLE_LOW_POWER */

extern void SCRB_Initialize(void);
extern void SCRB_PLL_Clock_Off(bool_t bUsedSystemClk);
extern void SCRB_PLL_Clock_On(void);
extern void SCRB_USB_Reset(void);
extern void SCRB_Remap_And_Reset(uint8_t _num);

#if USED_IDLE_LOW_POWER
extern void SCRB_Clock_Control(eClK_CTRL_STATUS_t eStatus);
#endif /* USED_IDLE_LOW_POWER */

#endif /* _SCRB_H_ */
