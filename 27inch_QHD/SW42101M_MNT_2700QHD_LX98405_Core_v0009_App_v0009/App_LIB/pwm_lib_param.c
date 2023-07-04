/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : pwm_lib_param.c
 * created on : 18. 10. 2018
 * Author : mhjang
 *
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright
 *	 notice, this list of conditions and the following disclaimer.
 *	 - Redistributions in binary form must reproduce the above copyright
 *	 notice, this list of conditions and the following disclaimer in the
 *	 documentation and/or other materials provided with the distribution.
 * - Neither the name of SiW nor the names of its contributors may be used
 *	 to endorse or promote products derived from this software without
 *	 specific prior written permission.
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


#include "pwm_lib_param.h"

tPWMDRV_LIB_REG_t g_tPWMDRV_lib_reg =
{
	.usPwmFreq = 94,
	.ucPwmPreNum = 4,
	.ucPwmSetNum = 1,
	.ucPwmFingerActNum = 20,
	.usFullFingerPWMPreDly = PWM_us(0),
	.usFullFingerPWMIntervalDly = PWM_us(10),
	.usNIPwmFreq = 130,
	.ucNIPwmFingerActNum = 20,
	.ucPwmTotalMuxNum = 13,
	.ucPwm1stMuxStart = 10,
	.ucPwm2ndMuxStart = 11,
	.ucPwm3rdMuxStart = 12,
};
