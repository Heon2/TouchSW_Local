/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : param_configset_pwmdrv.h
 * created on : 29. 12. 2020
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

#ifndef _PARAM_COFIGSET_PWMDRV_H_
#define _PARAM_COFIGSET_PWMDRV_H_


/****************************************************************************************/
/*                            WGP PWM Setting Parameter                                 */
/****************************************************************************************/
#if USED_BEACON_SET_ADJUST
	#define DMSB(x)			 		((((x) >> 20) & 0xFFFFF) << 12)
	#define DLSB(x)			 		(((x) & 0xFFFFF) << 12)

	// Manchester code
	#define DSSS_GAP									(0x0000000000)
	#define DSSS_P										(0x95666A965A)
	#define DSSS_0										(0x9A5599AA59)
	#define DSSS_1										(0xA5A5599AA5)
	#define DSSS_2										(0xA965A5599A)
	#define DSSS_3										(0x965A5599AA)
	#define DSSS_4										(0x9666A965A5)
	#define DSSS_5										(0xA66A965A55)
	#define DSSS_6										(0xAA965A5599)
	#define DSSS_7										(0xA6A965A559)
	#define DSSS_8										(0x65AA6655A6)
	#define DSSS_9										(0x5A5AA6655A)
	#define DSSS_A										(0x569A5AA665)
	#define DSSS_B										(0x69A5AA6655)
	#define DSSS_C										(0x6999569A5A)
	#define DSSS_D										(0x599569A5AA)
	#define DSSS_E										(0x5569A5AA66)
	#define DSSS_F										(0x59569A5AA6)
	#define DSSS_M										(0x6A999569A5)

	#define Preamble									(16)
	#define GAP											(17)
#endif /* USED_BEACON_SET_ADJUST */

#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_fstart_en				(PWM_1FRAME_IN_1VSYNC)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_skip_num					(0)
#if USED_WGP_AGIC_PEN
	#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_beacon_data_num			(7)
#else
	#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_beacon_data_num			(9)
#endif
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_sric_dummy_num			(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_tpic_dummy_num			(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)

#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_HOPP1_sric_dummy_num		(PARAMSET_ROIC_CFGR_PWM_FIG_HOPPFRQ_CTL_pwm_dum_num)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_HOPP1_tpic_dummy_num		(PARAMSET_ROIC_CFGR_PWM_FIG_HOPPFRQ_CTL_pwm_dum_num)

#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_sric_idle_dummy_num		(PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_dum_num)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_tpic_idle_dummy_num		(PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_dum_num)

#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_dummy_gap_en				(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_pgap_en			     	(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_pen_s_pwmnum				((PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_act_num + 1) + 1)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_HOPP1_pen_s_pwmnum		((PARAMSET_ROIC_PWM_POS_HOPPFRQ_CTL_pwm_act_num + 1) + 1/*Set*/)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR1_pen_s_idle_pwmnum		((PARAMSET_ROIC_PWM_IDLE_POS_CTL_pwm_act_num + 1) + 1/*Set*/)


#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
	#define PARAMSET_PWMDRV_WGP_PWMGEN_CR2_pen_d_pwmnum				(PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_dum_num - PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num + ((PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_act_num + 1) * 8) + 1)//(36)
	#define PARAMSET_PWMDRV_WGP_PWMGEN_CR2_HOPP1_pen_d_pwmnum		(PARAMSET_ROIC_PWM_DAT_HOPPFRQ_CTL_pwm_dum_num - PARAMSET_ROIC_PWM_HOPPFRQ_CTL_pwm_dum_num + ((PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_pre_act_num + 1) * 8) + 1)//(36)
#else
	#define PARAMSET_PWMDRV_WGP_PWMGEN_CR2_pen_d_pwmnum				(PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_dum_num - PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num + ((PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_act_num + 1) * 7) + 1)//(36)
	#define PARAMSET_PWMDRV_WGP_PWMGEN_CR2_HOPP1_pen_d_pwmnum		(PARAMSET_ROIC_PWM_DAT_HOPPFRQ_CTL_pwm_dum_num - PARAMSET_ROIC_PWM_HOPPFRQ_CTL_pwm_dum_num + ((PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_pre_act_num + 1) * 7) + 1)//(36)
#endif


//#define PARAMSET_PWMDRV_WGP_PWMGEN_CR2_pen_d_pwmnum				(36)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR2_finger_pwmnum			((PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_act_num + 1) + 1)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR2_HoppFrq_finger_pwmnum	((PARAMSET_ROIC_CFGR_PWM_FIG_HOPPFRQ_CTL_pwm_act_num + 1) + 1)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR2_nm_num					((PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_act_num + 1) + 1)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR2_total_mux_num			(25)
#define PARAMSET_PWMDRV_WGP_PWMGEN_CR2_nm_total_mux_num			(2)

#define PARAMSET_PWMDRV_WGP_DLY_CNT1_sgap_prd					(19+360)
#define PARAMSET_PWMDRV_WGP_DLY_CNT1_ping_prd					(PWM_nsec(6460))

#define PARAMSET_PWMDRV_WGP_DLY_CNT2_mgap_prd_f					(0)
#define PARAMSET_PWMDRV_WGP_DLY_CNT2_mgap_prd_p_s				(0)
#define PARAMSET_PWMDRV_WGP_DLY_CNT2_mgap_prd_p_d				(0)

#define PARAMSET_PWMDRV_WGP_PWM_DLY1_pwm_sric_f					(0)
#define PARAMSET_PWMDRV_WGP_PWM_DLY1_pwm_tpic_f					(0)
#define PARAMSET_PWMDRV_WGP_PWM_DLY1_pwm_mux_f					(0)

#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_beacon_en				(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_s_ping_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_d_ping_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_finger_ping_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_s_en				(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_d_en				(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_finger_en				(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_s_dmy_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_d_dmy_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_finger_dmy_en			(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_s_set_tx_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_d_set_tx_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_finger_set_tx_en		(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_nm_en					(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_inv_en					(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_ping_only_en			(DISABLE)

#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_beacon_en				(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_s_ping_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_d_ping_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_finger_ping_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_s_en				(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_d_en				(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_finger_en				(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_s_dmy_en			(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_d_dmy_en			(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_finger_dmy_en			(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_s_set_tx_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_d_set_tx_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_finger_set_tx_en		(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_nm_en					(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_inv_en					(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pwm_2x_en				(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_s_tsync_d2_en		(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_d_tsync_d2_en		(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_finger_tsync_d2_en		(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_ping_only_en			(DISABLE)

#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_beacon_en				(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_s_ping_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_d_ping_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_finger_ping_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_s_en					(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_d_en					(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_finger_en				(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_s_dmy_en				(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_d_dmy_en				(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_finger_dmy_en			(ENABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_s_set_tx_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_d_set_tx_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_finger_set_tx_en			(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_nm_en					(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_inv_en					(DISABLE)
#define PARAMSET_PWMDRV_WGP_PWM_MUX_CR_ping_only_en				(DISABLE)

#if USE_PWM_142KHZ
#define PARAMSET_PWMDRV_WGP_FREQ								(142)
#define PARAMSET_PWMDRV_WGP_FREQ_142KHZ_FULL					(167)										//	(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_FREQ))
#define PARAMSET_PWMDRV_WGP_FREQ_142KHZ_HALF					(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_FREQ))	//	(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_FREQ)+1)

#define PARAMSET_PWMDRV_WGP_DMY_FREQ							(PARAMSET_PWMDRV_WGP_FREQ_142KHZ_FULL)

#define PARAMSET_PWMDRV_WGP_PEN_POS_FREQ						(PARAMSET_PWMDRV_WGP_FREQ_142KHZ_FULL)
#define PARAMSET_PWMDRV_WGP_PEN_DAT_FREQ						(PARAMSET_PWMDRV_WGP_FREQ_142KHZ_FULL)
#define PARAMSET_PWMDRV_WGP_FINGER_FREQ							(PARAMSET_PWMDRV_WGP_FREQ_142KHZ_FULL)

#define PARAMSET_PWMDRV_WGP_PWM_CR2_pen_s_h_pnt					(PARAMSET_PWMDRV_WGP_FREQ_142KHZ_HALF)
#define PARAMSET_PWMDRV_WGP_PWM_CR2_pen_d_h_pnt					(PARAMSET_PWMDRV_WGP_FREQ_142KHZ_HALF)
#define PARAMSET_PWMDRV_WGP_PWM_CR2_finger_h_pnt				(PARAMSET_PWMDRV_WGP_FREQ_142KHZ_HALF)
#define PARAMSET_PWMDRV_WGP_PWM_CR2_dmy_h_pnt					(PARAMSET_PWMDRV_WGP_FREQ_142KHZ_HALF)
#elif USE_PWM_86KHZ
#define PARAMSET_PWMDRV_WGP_FREQ								(86)
#define PARAMSET_PWMDRV_WGP_DMY_FREQ							(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_FREQ))

#define PARAMSET_PWMDRV_WGP_PEN_POS_FREQ						(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_FREQ))
#define PARAMSET_PWMDRV_WGP_PEN_DAT_FREQ						(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_FREQ))
#define PARAMSET_PWMDRV_WGP_FINGER_FREQ							(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_FREQ))

#define PARAMSET_PWMDRV_WGP_PWM_CR2_pen_s_h_pnt					(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_FREQ)+1)
#define PARAMSET_PWMDRV_WGP_PWM_CR2_pen_d_h_pnt					(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_FREQ)+1)
#define PARAMSET_PWMDRV_WGP_PWM_CR2_finger_h_pnt				(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_FREQ)+1)
#define PARAMSET_PWMDRV_WGP_PWM_CR2_dmy_h_pnt					(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_FREQ)+1)
#else
#define PARAMSET_PWMDRV_WGP_FREQ								(114)
#define PARAMSET_PWMDRV_WGP_DMY_FREQ							(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_FREQ))

#define PARAMSET_PWMDRV_WGP_PEN_POS_FREQ						(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_FREQ))
#define PARAMSET_PWMDRV_WGP_PEN_DAT_FREQ						(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_FREQ))
#define PARAMSET_PWMDRV_WGP_FINGER_FREQ							(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_FREQ))

#define PARAMSET_PWMDRV_WGP_PWM_CR2_pen_s_h_pnt					(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_FREQ)+1)
#define PARAMSET_PWMDRV_WGP_PWM_CR2_pen_d_h_pnt					(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_FREQ)+1)
#define PARAMSET_PWMDRV_WGP_PWM_CR2_finger_h_pnt				(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_FREQ)+1)
#define PARAMSET_PWMDRV_WGP_PWM_CR2_dmy_h_pnt					(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_FREQ)+1)
#endif

#if USED_NOISE_HOPPING_FREQ
#define PARAMSET_PWMDRV_WGP_HOPP1_FREQ							(86)
#define PARAMSET_PWMDRV_WGP_HOPP1_DMY_FREQ						(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_HOPP1_FREQ))

#define PARAMSET_PWMDRV_WGP_HOPP1_PEN_POS_FREQ					(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_HOPP1_FREQ))
#define PARAMSET_PWMDRV_WGP_HOPP1_PEN_DAT_FREQ					(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_HOPP1_FREQ))
#define PARAMSET_PWMDRV_WGP_HOPP1_FINGER_FREQ					(PWM_Full_KHz(PARAMSET_PWMDRV_WGP_HOPP1_FREQ))

#define PARAMSET_PWMDRV_WGP_HOPP1_PWM_CR2_pen_s_h_pnt			(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_HOPP1_FREQ)+1)
#define PARAMSET_PWMDRV_WGP_HOPP1_PWM_CR2_pen_d_h_pnt			(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_HOPP1_FREQ)+1)
#define PARAMSET_PWMDRV_WGP_HOPP1_PWM_CR2_finger_h_pnt			(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_HOPP1_FREQ)+1)
#define PARAMSET_PWMDRV_WGP_HOPP1_PWM_CR2_dmy_h_pnt				(PWM_Half_KHz(PARAMSET_PWMDRV_WGP_HOPP1_FREQ)+1)
#endif /* USED_NOISE_HOPPING_FREQ */

#define PARAMSET_PWMDRV_WGP_MUX_CR_pen_s						(2)
#define PARAMSET_PWMDRV_WGP_MUX_CR_pen_d						(1)
#define PARAMSET_PWMDRV_WGP_MUX_CR_finger						(3)
#define PARAMSET_PWMDRV_WGP_LAST_LHB_MUX_CR_finger				(1)
#define PARAMSET_PWMDRV_WGP_MUX_CR_nm							(1)
#define PARAMSET_PWMDRV_WGP_MUX_CR_Idle_pen_s					(2)
#define PARAMSET_PWMDRV_WGP_MUX_CR_Idle_finger					(1)

#if USE_PWM_86KHZ
	#define PARAMSET_PWMDRV_WGP_DLY_CNT4_bgap_prd					(312)
#else /* USE_PWM_86KHZ */
	#define PARAMSET_PWMDRV_WGP_DLY_CNT4_bgap_prd					(872)//(PWM_nsec(1050))
	#define PARAMSET_PWMDRV_WGP_HOPP1_DLY_CNT4_bgap_prd				(312)
#endif /* USE_PWM_86KHZ */
#define PARAMSET_PWMDRV_WGP_DLY_CNT4_bc_egap_prd				(0)

#if USED_PEN_MODE_OPERATION
#define PARAMSET_PWMDRV_WGP_FULL_LHB_1				(PWM_LHB_CONFIG_BEACON)
#else
#define PARAMSET_PWMDRV_WGP_FULL_LHB_1				(PWM_LHB_CONFIG_NONE)
#endif
#define PARAMSET_PWMDRV_WGP_FULL_LHB_2				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_3				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_4				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_5				(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_6				(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_7				(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_8				(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_9				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_10				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_11				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_12				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_13				(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_14				(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_15				(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_16				(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_17				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_18				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_19				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_20				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_21				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_22				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_23				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_24				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_25				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_26				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_27				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_28				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_29				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_30				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_31				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_FULL_LHB_32				(PWM_LHB_CONFIG_NONE)

#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_1				(PWM_LHB_CONFIG_BEACON)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_2				(PWM_LHB_CONFIG_PEN_POS)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_3				(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_4				(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_5				(PWM_LHB_CONFIG_PEN_TILT)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_6				(PWM_LHB_CONFIG_PEN_POS)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_7				(PWM_LHB_CONFIG_PEN_DATA)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_8				(PWM_LHB_CONFIG_PEN_DATA)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_9				(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_10			(PWM_LHB_CONFIG_PEN_POS)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_11			(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_12			(PWM_LHB_CONFIG_FINGER)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_13			(PWM_LHB_CONFIG_PEN_TILT)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_14			(PWM_LHB_CONFIG_PEN_POS)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_15			(PWM_LHB_CONFIG_PEN_DATA)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_16			(PWM_LHB_CONFIG_PEN_DATA)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_17			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_18			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_19			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_20			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_21			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_22			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_23			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_24			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_25			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_26			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_27			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_28			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_29			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_30			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_31			(PWM_LHB_CONFIG_NONE)
#define PARAMSET_PWMDRV_WGP_LOCAL_LHB_32			(PWM_LHB_CONFIG_NONE)

#if USED_FAST_SWITCH_LOCAL_IDLE_TO_ACTIVE
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_1		(PWM_LHB_CONFIG_BEACON)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_2		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_3		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_4		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_5		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_6		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_7		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_8		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_9		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_10		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_11		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_12		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_13		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_14		(PWM_LHB_CONFIG_FINGER) // PWM_LHB_CONFIG_PEN_POS
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_15		(PWM_LHB_CONFIG_PEN_POS)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_16		(PWM_LHB_CONFIG_NONE) // PWM_LHB_CONFIG_FINGER
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_17		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_18		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_19		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_20		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_21		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_22		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_23		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_24		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_25		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_26		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_27		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_28		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_29		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_30		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_31		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_32		(PWM_LHB_CONFIG_NONE)
#else
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_1		(PWM_LHB_CONFIG_BEACON)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_2		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_3		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_4		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_5		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_6		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_7		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_8		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_9		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_10		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_11		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_12		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_13		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_14		(PWM_LHB_CONFIG_NONE) // PWM_LHB_CONFIG_PEN_POS
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_15		(PWM_LHB_CONFIG_FINGER)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_16		(PWM_LHB_CONFIG_PEN_POS) // PWM_LHB_CONFIG_FINGER
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_17		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_18		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_19		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_20		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_21		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_22		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_23		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_24		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_25		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_26		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_27		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_28		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_29		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_30		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_31		(PWM_LHB_CONFIG_NONE)
	#define PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_32		(PWM_LHB_CONFIG_NONE)
#endif

#define PARAMSET_PWMDRV_WGP_TG_DUM5_tsync_tpic_out_bypass_enb	(1)


#endif /* _PARAM_COFIGSET_PWMDRV_H_ */
