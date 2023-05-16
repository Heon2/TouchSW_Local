/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : hal_fnc.c
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


/*
 * 아래 Function들은 -o0옵셥으로 컴파일을 해야 하나의 Section으로 생성이 된다. 전체 빌드 옵션인 -03로 빌드를 돌리게 되면.. 각각 독립 Section으로 잡히게 되기 때문에
 * +First옵션을 사용 할 수 없게 됨을 유념한다.
 */
#pragma O0

void (*Fncp_PendSV_IRQHandler)(void);
void (*Fncp_Systick_IRQHandler)(void);

void (*Fncp_WDGT_IRQHandler)(void);				// [0]
void (*Fncp_TIMER_IRQHandler)(void);			// [1]
void (*Fncp_DBG_I2C_IRQHandler)(void);			// [2]
void (*Fncp_FLITF_IRQHandler)(void);			// [3]
void (*Fncp_DBG_SPI_IRQHandler)(void);			// [4]
void (*Fncp_AB_ACC_IRQHandler)(void);			// [5]
void (*Fncp_GDMA_IRQHandler)(void);				// [6]
void (*Fncp_USER_IRQHandler)(void);				// [7]
void (*Fncp_GPIOA_IRQHandler)(void);			// [8]
void (*Fncp_GPIOM_IRQHandler)(void);			// [9]
void (*Fncp_VSYNC_IN_IRQHandler)(void);			// [10]
void (*Fncp_TSYNC_IN_IRQHandler)(void);			// [11]
void (*Fncp_TSYNC_OUT_IRQHandler)(void);		// [12]
void (*Fncp_PWMDRV_IRQHandler)(void);			// [13]
void (*Fncp_DSP_A_IRQHandler)(void);			// [14]
void (*Fncp_DSP_B_IRQHandler)(void);			// [15]
void (*Fncp_USB_IRQHandler)(void);				// [16]
												// [17] Reserved
												// [18] Reserved
void (*Fncp_MSPI_IRQHandler)(void);				// [19]
void (*Fncp_TLVDS_IRQHandler)(void);			// [19]
//void (*Fncp_MPI_IRQHandler)(void);			// [19]
												// [20] Reserved
												// [21] Reserved
void (*Fncp_I2C_MST_IRQHandler)(void);			// [22]
void (*Fncp_I2C_MST_Sleep_IRQHandler)(void);	// [23]
void (*Fncp_I2C_MST_Wakeup_IRQHandler)(void);	// [24]
void (*Fncp_I2C_SLV_IRQHandler)(void);			// [25]
void (*Fncp_I2C_SLV_Sleep_IRQHandler)(void);	// [26]
void (*Fncp_I2C_SLV_Wakeup_IRQHandler)(void);	// [27]

