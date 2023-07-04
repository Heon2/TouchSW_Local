/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : module_types.h
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

#ifndef _MODULE_TYPES_H_
#define _MODULE_TYPES_H_


typedef enum
{
	IRQ_ID_PWMDRV = 0,
	IRQ_ID_FULL_SAMPLE,
	IRQ_ID_FULL_SAMPLE_NI,
	IRQ_ID_LOCAL_SAMPLE,
	IRQ_ID_TIMER_0,
	IRQ_ID_TIMER_123,
	IRQ_ID_HWACC,
	IRQ_ID_FLITF,
	IRQ_ID_MAX
} eIrqId_t;

typedef enum
{
	PARTIAL_PEN_BEACON = 0,
	PARTIAL_PEN_COORD1,
	PARTIAL_PEN_COORD2,
	PARTIAL_PEN_COORD3,
	PARTIAL_PEN_COORD4,
	PARTIAL_PEN_DATA1,
	PARTIAL_PEN_DATA2,
	PARTIAL_PEN_DATA3,
	PARTIAL_PEN_DATA4,
	PARTIAL_PEN_DATA5,
	PARTIAL_FINGER1,
	PARTIAL_FINGER2,
	PARTIAL_FINGER3,
	PARTIAL_FINGER4,
	PARTIAL_FINGER5,
	PARTIAL_FINGER6,
	PARTIAL_MAX,
} ePartialSensing_t;

#endif /* _MODULE_TYPES_H_ */
