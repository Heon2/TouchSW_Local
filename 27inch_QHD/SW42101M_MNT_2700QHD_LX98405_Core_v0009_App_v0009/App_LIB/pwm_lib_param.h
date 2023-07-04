/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : pwm_lib_param.h
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


#ifndef PWM_LIB_PARAM_H_
#define PWM_LIB_PARAM_H_

#include <stdint.h>

#define Touch_CLK 					(12E+6)
#define PWM_us(val)					((val == 0) ? 0 : (((Touch_CLK/1E+6)*(val))-3))
#define PWM_Full_PRD_KHz(val)		((val == 0) ? 0 : ((12000 / val)-2))
#define PWM_Half_PRD_KHz(val)		((val == 0) ? 0 : ((6000 / val)-2))


typedef struct
{
	uint8_t 			ucSelTsyncOut;
	uint16_t 			usPwmFreq;
	uint8_t 			ucPwmPreNum;
	uint8_t 			ucPwmSetNum;
	uint8_t 			ucPwmFingerActNum;
	uint8_t 			ucPwmFinger1LHBMuxNum;
	uint16_t 			usFullFingerPWMPreDly;
	uint16_t 			usFullFingerPWMIntervalDly;
	uint16_t 			usNIPwmFreq;
	uint8_t 			ucNIPwmFingerActNum;
	uint8_t 			ucPwmTotalMuxNum;
	uint8_t 			ucPwm1stMuxStart;
	uint8_t 			ucPwm2ndMuxStart;
	uint8_t 			ucPwm3rdMuxStart;

} __attribute__ ((packed)) tPWMDRV_LIB_REG_t;

extern tPWMDRV_LIB_REG_t g_tPWMDRV_lib_reg;


#endif /* PWM_LIB_PARAM_H_ */
