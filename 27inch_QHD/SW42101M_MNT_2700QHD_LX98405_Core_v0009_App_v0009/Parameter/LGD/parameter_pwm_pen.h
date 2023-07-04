/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : parameter_pwm_pen.h
 * created on : 18. 9. 2017
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

#ifndef _CUSTOM_PWM_PEN_H_
#define _CUSTOM_PWM_PEN_H_


#define PWMDRV_DEF_FW_CTRL_PEN_MODE			(1)
#define PWMDRV_DEF_DSSS_CFG_BEACON_EN		(1)
#define PWMDRV_DEF_DSSS_CFG_PING_EN			(1)

#define PWMDRV_DEF_PRE_0_TX_PRD				(0)
#define PWMDRV_DEF_PRE_0_TX_LOW				(0)
#define PWMDRV_DEF_PRE_1_TX_NUM				(0)
#define PWMDRV_DEF_PRE_1_PRE_DLY			(0)
#define PWMDRV_DEF_PRE_2_DSSS_DLY_12MCNT	(20)

#define PWMDRV_DEF_GBL_ENA_PRTX_P0			(0)
#define PWMDRV_DEF_GBL_ENA_PRTX_D0			(0)
#define PWMDRV_DEF_GBL_ENA_DSSS_P			(1)
#define PWMDRV_DEF_GBL_ENA_DSSS_D			(1)
#define PWMDRV_DEF_GBL_ENA_PRTX_P1			(0)
#define PWMDRV_DEF_GBL_ENA_PRTX_D1			(0)
#define PWMDRV_DEF_GBL_ENA_PRTX_P1			(0)
#define PWMDRV_DEF_GBL_ENA_PRTX_D1			(0)
#define PWMDRV_DEF_GBL_ENA_ACTX_PD			(1)

#define PWMDRV_DEF_ENA_PWM_0_T_0_DSSS		(0)
#define PWMDRV_DEF_ENA_PWM_0_T_0_PRE		(0)
#define PWMDRV_DEF_ENA_PWM_0_T_0_ACT		(1)
#define PWMDRV_DEF_ENA_PWM_0_T_0_PRE_LFD_0	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_0_PRE_LFD_1	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_0_ACT_LFD_0	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_0_ACT_LFD_1	(0)

#define PWMDRV_DEF_ENA_PWM_0_T_1_DSSS		(1)
#define PWMDRV_DEF_ENA_PWM_0_T_1_PRE		(0)
#define PWMDRV_DEF_ENA_PWM_0_T_1_ACT		(1)
#define PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_0	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_1	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_0	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_1	(1)

#define PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz		(91)
#define PWMDRV_DEF_FG_F_F0_ACT_DLY_usec		(0)

#endif /* _CUSTOM_PWM_PEN_H_ */
