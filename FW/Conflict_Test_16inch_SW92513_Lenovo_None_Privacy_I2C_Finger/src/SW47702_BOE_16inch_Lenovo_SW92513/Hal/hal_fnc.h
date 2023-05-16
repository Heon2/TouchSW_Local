/******************************************************************************************************
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

extern void (*Fncp_WDGT_IRQHandler)(void) __DATA_HEAD;				// [0]
extern void (*Fncp_TIMER_IRQHandler)(void) __DATA_HEAD;				// [1]
extern void (*Fncp_DBG_I2C_IRQHandler)(void) __DATA_HEAD;			// [2]
extern void (*Fncp_FLITF_IRQHandler)(void) __DATA_HEAD;				// [3]
extern void (*Fncp_DBG_SPI_IRQHandler)(void) __DATA_HEAD;			// [4]
extern void (*Fncp_AB_ACC_IRQHandler)(void) __DATA_HEAD;			// [5]
extern void (*Fncp_GDMA_IRQHandler)(void) __DATA_HEAD;				// [6]
extern void (*Fncp_USER_IRQHandler)(void) __DATA_HEAD;				// [7]
extern void (*Fncp_GPIOA_IRQHandler)(void) __DATA_HEAD;				// [8]
extern void (*Fncp_GPIOM_IRQHandler)(void) __DATA_HEAD;				// [9]
extern void (*Fncp_VSYNC_IN_IRQHandler)(void) __DATA_HEAD;			// [10]
extern void (*Fncp_TSYNC_IN_IRQHandler)(void) __DATA_HEAD;			// [11]
extern void (*Fncp_TSYNC_OUT_IRQHandler)(void) __DATA_HEAD;			// [12]
extern void (*Fncp_PWMDRV_IRQHandler)(void) __DATA_HEAD;			// [13]
extern void (*Fncp_DSP_A_IRQHandler)(void) __DATA_HEAD;				// [14]
extern void (*Fncp_DSP_B_IRQHandler)(void) __DATA_HEAD;				// [15]
extern void (*Fncp_USB_IRQHandler)(void) __DATA_HEAD;				// [16]
																	// [17] Reserved
																	// [18] Reserved
extern void (*Fncp_MSPI_IRQHandler)(void) __DATA_HEAD;				// [19]
extern void (*Fncp_TLVDS_IRQHandler)(void) __DATA_HEAD;				// [19]
//extern void (*Fncp_MPI_IRQHandler)(void) __DATA_HEAD;				// [19]
																	// [20] Reserved
																	// [21] Reserved
extern void (*Fncp_I2C_MST_IRQHandler)(void) __DATA_HEAD;			// [22]
extern void (*Fncp_I2C_MST_Sleep_IRQHandler)(void) __DATA_HEAD;		// [23]
extern void (*Fncp_I2C_MST_Wakeup_IRQHandler)(void) __DATA_HEAD;	// [24]
extern void (*Fncp_I2C_SLV_IRQHandler)(void) __DATA_HEAD;			// [25]
extern void (*Fncp_I2C_SLV_Sleep_IRQHandler)(void) __DATA_HEAD;		// [26]
extern void (*Fncp_I2C_SLV_Wakeup_IRQHandler)(void) __DATA_HEAD;	// [27]


#endif /* _HAL_FNC_H_ */
