/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : parameter_pwm_finger.h
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

#ifndef _CUSTOM_PWM_FINGER_H_
#define _CUSTOM_PWM_FINGER_H_


#define PWMDRV_DEF_FW_CTRL_PEN_MODE			(0)
#define PWMDRV_DEF_DSSS_CFG_BEACON_EN		(0)
#define PWMDRV_DEF_DSSS_CFG_PING_EN			(0)

#define PWMDRV_DEF_PRE_0_TX_PRD_usec		(91)
//#define PWMDRV_DEF_PRE_0_TX_LOW				(0)
//#define PWMDRV_DEF_PRE_1_TX_NUM				(0)
#define PWMDRV_DEF_PRE_1_PRE_DLY			(0)
#define PWMDRV_DEF_PRE_2_DSSS_DLY_12MCNT	(0)

#define PWMDRV_DEF_GBL_ENA_PRTX_P0			(0)
#define PWMDRV_DEF_GBL_ENA_PRTX_D0			(0)
#define PWMDRV_DEF_GBL_ENA_DSSS_P			(0)
#define PWMDRV_DEF_GBL_ENA_DSSS_D			(0)
#define PWMDRV_DEF_GBL_ENA_PRTX_P1			(0)
#define PWMDRV_DEF_GBL_ENA_PRTX_D1			(0)
#define PWMDRV_DEF_GBL_ENA_ACTX_PD			(1)

#define PWMDRV_DEF_ENA_PWM_0_T_0_DSSS		(0)
#define PWMDRV_DEF_ENA_PWM_0_T_0_PRE		(1)
#define PWMDRV_DEF_ENA_PWM_0_T_0_ACT		(1)
#define PWMDRV_DEF_ENA_PWM_0_T_0_PRE_LFD_0	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_0_PRE_LFD_1	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_0_ACT_LFD_0	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_0_ACT_LFD_1	(1)

#define PWMDRV_DEF_ENA_PWM_0_T_1_DSSS		(0)
#define PWMDRV_DEF_ENA_PWM_0_T_1_PRE		(0)
#define PWMDRV_DEF_ENA_PWM_0_T_1_ACT		(1)
#define PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_0	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_1	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_0	(0)
#define PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_1	(1)

#if (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_91K)
#define PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz		(100)
#elif (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_133K)
#define PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz		(133)
#elif (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_150K)
#define PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz		(150)
#else /* (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_200K) */
#define PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz		(200)
#endif /* (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_91K) */

#if (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_91K)
#if USED_PLL_OUT_CLK_CONFIG
		#if (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) // MSPI 16M
		#define PWMDRV_DEF_FG_F_F0_ACT_DLY_usec		(0)//(0) //BOE 35
		#define PWMDRV_DEF_FG_F_F1_END_DLY_usec		(0)//(0) //BOE 35
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_90MHz) // MSPI 15M
		#define PWMDRV_DEF_FG_F_F0_ACT_DLY_usec		(0)//(0) //BOE 35
		#define PWMDRV_DEF_FG_F_F1_END_DLY_usec		(0)//(0) //BOE 35
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_45MHz) // MSPI 11.3M
		#define PWMDRV_DEF_FG_F_F0_ACT_DLY_usec		(30)//(0) //BOE 35
		#define PWMDRV_DEF_FG_F_F1_END_DLY_usec		(100)//(0) //BOE 35 11.3M
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_37p5MHz) // MSPI 9.4M
		#define PWMDRV_DEF_FG_F_F0_ACT_DLY_usec		(40)//(0) //BOE 35
		#define PWMDRV_DEF_FG_F_F1_END_DLY_usec		(120)//(0) //BOE 35.4M
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_31p5MHz) // MSPI 7.9M
		#define PWMDRV_DEF_FG_F_F0_ACT_DLY_usec		(50)//(0) //BOE 35
		#define PWMDRV_DEF_FG_F_F1_END_DLY_usec		(160)//(0) //BOE 35
	#else /* (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) */ // MSPI 15M
		#define PWMDRV_DEF_FG_F_F0_ACT_DLY_usec		(0)//(0) //BOE 35
		#define PWMDRV_DEF_FG_F_F1_END_DLY_usec		(0)//(0) //BOE 35
		#define MSPI_CLOCK_DIV						(MSPI_CLOCK_DIV_3) // 15M
	#endif /* (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) */
#else /* USED_PLL_OUT_CLK_CONFIG */
		#define PWMDRV_DEF_FG_F_F0_ACT_DLY_usec		(0)//(0) //BOE 35
		#define PWMDRV_DEF_FG_F_F1_END_DLY_usec		(0)//(0) //BOE 35
#endif /* USED_PLL_OUT_CLK_CONFIG */
#elif (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_133K)
#define PWMDRV_DEF_FG_F_F0_ACT_DLY_usec		(0) //BOE 35
#define PWMDRV_DEF_FG_F_F1_END_DLY_usec		(0)//(0) //BOE 35
#elif (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_150K)
#define PWMDRV_DEF_FG_F_F0_ACT_DLY_usec		(0) //BOE 35
#define PWMDRV_DEF_FG_F_F1_END_DLY_usec		(0)//(0) //BOE 35
#else /* (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_200K) */
#define PWMDRV_DEF_FG_F_F0_ACT_DLY_usec		(30) //BOE 35
#define PWMDRV_DEF_FG_F_F1_END_DLY_usec		(0)//(0) //BOE 35
#endif /* (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_91K) */

//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_
//#define PWMDRV_DEF_


#endif /* _CUSTOM_PWM_FINGER_H_ */
