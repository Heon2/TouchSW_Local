/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _swl92406_conf.h
 * created on : 13. 5. 2019
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

#ifndef __SWL92406_CONF_H_
#define __SWL92406_CONF_H_


#if (USED_ROIC_DEF == ROIC_SWL92406)

typedef struct
{
	uint16_t ulADDR;
	uint16_t ulR0Value;
	uint16_t ulR1Value;

} __PACKED tSW92406_CFG_t;

typedef struct
{
	uint16_t ulADDR;
	uint16_t ulMSLocalValue;
	uint16_t ulMSFullValue;
	uint16_t ulWacomLocalValue;
	uint16_t ulWacomFullValue;

} __PACKED tSW92406_FullLocal_CFG_t;

#define SRIC_PROTOCOL_RESET_COUNT   		(7)
#define SRIC_REG_INIT_VALUE_NUM				(95)

typedef struct
{
	tSW92406_CFG_t value[SRIC_REG_INIT_VALUE_NUM];

} __PACKED tModuleSRICCommonConf_t;

#include "_swl92406_parampreset.h"

#endif /* (USED_ROIC_DEF == ROIC_SW97500) */


#endif /* __SWL92406_CONF_H_ */
