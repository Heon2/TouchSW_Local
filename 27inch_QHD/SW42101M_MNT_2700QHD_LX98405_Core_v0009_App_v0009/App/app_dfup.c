/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_dfup.h
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
#include "param_def.h"
#include "Mspi.h"


__IO int dfup;

eTouchOperMainState_t app_dfup_oper_handler(void)
{
	eTouchOperMainState_t eRegMainState;
	dfup = 1;
	protocol_dfup_PendReadyStatus();
	vtProtocolBufferPointers.pParameterBuffer = (void *)DFUP_BUFFER;
	#ifdef MODE_I2C
	NVIC_SetPriority(I2C_IRQn, 0);
	NVIC_EnableIRQ (I2C_IRQn);    /* Interrupt Enable */
	I2C->I2C_GLB_CR_b.I2cItrptEn = 0x1;
	I2C->I2C_GLB_CR_b.I2cByteItrptEn = 0x1;
	I2C->I2C_GLB_CR_b.I2cAddChkItrptEn = 0x1;
	#endif
	protocol_init();
	while(YES)
	{
		hal_flitf_another_process();

#ifdef MODE_I2C
		QueueCommonData_I2C();
#else
		QueueCommonData_USB();
#endif
	}

	return eRegMainState;
}
