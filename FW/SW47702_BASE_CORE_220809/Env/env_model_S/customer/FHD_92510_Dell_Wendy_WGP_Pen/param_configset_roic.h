/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : param_configset_roic.h
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

#ifndef _PARAM_CONFIGSET_ROIC_H_
#define _PARAM_CONFIGSET_ROIC_H_


/************************************************************************************************************/
/*											WGP ROIC Setting												*/
/************************************************************************************************************/
#define PARAMSET_ROIC_CFGR_PRE_DRV_CTL_pdrv_mode			 	(0) // 1: phd mode enable

/*
 * Channel Control
 */

#define PARAMSET_ROIC_CFGR_CH_NUM_fig_ch_num					(18)
#define PARAMSET_ROIC_CFGR_CH_NUM_pen_ch_num			 		(18)
#define PARAMSET_ROIC_CFGR_CH_NUM_pdrv_ch_num					(18)

/*
 * Total Mux Num Control
 */
#define PARAMSET_ROIC_CFGR_MUX_CTL_tot_mux_num					(9) // N+1
#define PARAMSET_ROIC_CFGR_IDLE_MUX_CTL_tot_mux_num				(0) // N+1

/*
 * fINGER MUX Sensing Order
 */
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01			(1)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02			(2)

#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03			(3)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04			(4)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05			(5)

#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06			(6)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07			(7)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08			(8)

#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09			(9)

#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_10			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_11			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_12			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_13			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_14			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_15			(0)

#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_00		(11)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_01		(0)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_02		(0)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_03		(0)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_04		(0)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_05		(0)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_06		(0)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_07		(0)

#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_nxt_lhb_mode			(0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_tsync_num				(16)
#if USED_IDLE_MODE_30Hz_CONTROL
	#define PARAMSET_ROIC_IDLE_CFGR_RCOM_LHB_CFG_tsync_num		(20)
#elif USED_IDLE_MODE_20Hz_CONTROL
	#define PARAMSET_ROIC_IDLE_CFGR_RCOM_LHB_CFG_tsync_num		(30)
#else
	#define PARAMSET_ROIC_IDLE_CFGR_RCOM_LHB_CFG_tsync_num		(16)
#endif
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_dum_tsync_num			(0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_beacon_en				(0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_rdcom_en				(0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_sgap_num				(0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_r0pd					(0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_r1pd					(0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_sel_hover				(0)

/*
 * Finger Mux delay Control
 */
#define PARAMSET_ROIC_CFGR_MUX_DLY0_mux_1_dly					(0)
#define PARAMSET_ROIC_CFGR_MUX_DLY0_mux_2_dly					(0)
#define PARAMSET_ROIC_CFGR_MUX_DLY0_mux_3_dly					(0)
#define PARAMSET_ROIC_CFGR_MUX_DLY0_mux_4_dly					(0)
#define PARAMSET_ROIC_CFGR_MUX_DLY0_mux_5_dly					(0)
#define PARAMSET_ROIC_CFGR_MUX_DLY1_mux_6_dly					(0)
#define PARAMSET_ROIC_CFGR_MUX_DLY1_mux_7_dly					(0)
#define PARAMSET_ROIC_CFGR_MUX_DLY1_mux_8_dly					(0)
#define PARAMSET_ROIC_CFGR_MUX_DLY1_mux_9_dly					(0)
#define PARAMSET_ROIC_CFGR_MUX_DLY1_mux_10_dly					(0)

/*
 * SD Off Control
 */
#define PARAMSET_ROIC_SDIC_CFG_sd_off_en						(0)//(1)
#define PARAMSET_ROIC_SDIC_sd_off_ctl							(0)//(2) // 1 : ADC Done�� SD On, 2 : T-Sync Low���� SD Off

/*
 * Finger Sensing
 */
#define PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_act_num				(7)//(8) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_mgap_num				(1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num				(4)//(9)
#define PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_set_num				(1)

#define PARAMSET_ROIC_CFGR_PWM_FIG_HOPPFRQ_CTL_pwm_act_num		(8) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_HOPPFRQ_CTL_pwm_mgap_num		(1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_HOPPFRQ_CTL_pwm_dum_num		(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)
#define PARAMSET_ROIC_CFGR_PWM_FIG_HOPPFRQ_CTL_pwm_set_num		(1)

#define PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_act_num			(5) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_mgap_num		(1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_dum_num			(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)
#define PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_set_num			(1)

/*
 * Pen Position and Tilt Sensing
 */
#define PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_pdrv_num				(0)
#define PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_act_num				(17)// (N+1)
#define PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_mgap_num				(1)
#define PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_dum_num				(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)
#define PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_set_num				(1)

#define PARAMSET_ROIC_CFGR_PWM_POS_HOPPFRQ_CTL_pwm_pdrv_num		(0)
#define PARAMSET_ROIC_CFGR_PWM_POS_HOPPFRQ_CTL_pwm_act_num		(15) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_POS_HOPPFRQ_CTL_pwm_mgap_num		(1)
#define PARAMSET_ROIC_CFGR_PWM_POS_HOPPFRQ_CTL_pwm_dum_num		(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)
#define PARAMSET_ROIC_CFGR_PWM_POS_HOPPFRQ_CTL_pwm_set_num		(1)

#define PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_pdrv_num		(0)
#define PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_act_num			(15) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_mgap_num		(1)
#define PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_dum_num			(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)
#define PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_set_num			(1)

/*
 * Pen Data Sensing
 */
#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_pdrv_num				(0)
#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_pre_act_num				(4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_act_num					(4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_mgap_num				(0)
#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
	#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_dum_num					(4)
#else /* USED_TOUCH_WGP_PREDRV_MUX_SENSING */
	#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_dum_num					(9)
#endif /* USED_TOUCH_WGP_PREDRV_MUX_SENSING */
#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_set_num					(1)

#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_pdrv_num		(0)
#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_pre_act_num		(4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_act_num			(4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_mgap_num		(0)
#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
	#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_dum_num			(4)
#else /* USED_TOUCH_WGP_PREDRV_MUX_SENSING */
	#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_dum_num			(9)
#endif /* USED_TOUCH_WGP_PREDRV_MUX_SENSING */
#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_set_num			(1)

/*
 * LHB Mode Setting
 */
#if USED_PEN_MODE_OPERATION
	#define PARAMSET_ROIC_FULL_LHB_1_mode						(SW92510_MODE_BEACON)
#else
	#define PARAMSET_ROIC_FULL_LHB_1_mode						(SW92510_MODE_DUMMY)
#endif
#define PARAMSET_ROIC_FULL_LHB_2_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_3_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_4_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_5_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_FULL_LHB_6_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_FULL_LHB_7_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_FULL_LHB_8_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_FULL_LHB_9_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_10_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_11_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_12_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_13_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_FULL_LHB_14_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_FULL_LHB_15_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_FULL_LHB_16_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_FULL_LHB_17_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_18_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_19_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_20_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_21_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_22_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_23_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_24_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_25_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_26_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_27_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_28_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_29_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_30_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_31_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_FULL_LHB_32_mode							(SW92510_MODE_DUMMY)


#define PARAMSET_ROIC_LOCAL_LHB_1_mode							(SW92510_MODE_BEACON)
#define PARAMSET_ROIC_LOCAL_LHB_2_mode							(SW92510_MODE_PEN_POS)
#define PARAMSET_ROIC_LOCAL_LHB_3_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_4_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_LOCAL_LHB_5_mode							(SW92510_MODE_PEN_TILT)
#define PARAMSET_ROIC_LOCAL_LHB_6_mode							(SW92510_MODE_PEN_POS)
#define PARAMSET_ROIC_LOCAL_LHB_7_mode							(SW92510_MODE_PEN_DAT)
#define PARAMSET_ROIC_LOCAL_LHB_8_mode							(SW92510_MODE_PEN_DAT)
#define PARAMSET_ROIC_LOCAL_LHB_9_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_LOCAL_LHB_10_mode							(SW92510_MODE_PEN_POS)
#define PARAMSET_ROIC_LOCAL_LHB_11_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_LOCAL_LHB_12_mode							(SW92510_MODE_FINGER)
#define PARAMSET_ROIC_LOCAL_LHB_13_mode							(SW92510_MODE_PEN_TILT)
#define PARAMSET_ROIC_LOCAL_LHB_14_mode							(SW92510_MODE_PEN_POS)
#define PARAMSET_ROIC_LOCAL_LHB_15_mode							(SW92510_MODE_PEN_DAT)
#define PARAMSET_ROIC_LOCAL_LHB_16_mode							(SW92510_MODE_PEN_DAT)
#define PARAMSET_ROIC_LOCAL_LHB_17_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_18_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_19_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_20_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_21_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_22_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_23_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_24_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_25_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_26_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_27_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_28_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_29_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_30_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_31_mode							(SW92510_MODE_DUMMY)
#define PARAMSET_ROIC_LOCAL_LHB_32_mode							(SW92510_MODE_DUMMY)


#if USED_FAST_SWITCH_LOCAL_IDLE_TO_ACTIVE
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode					(SW92510_MODE_NOISE_SCAN)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode					(SW92510_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_17_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_18_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_19_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_20_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_21_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_22_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_23_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_24_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_25_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_26_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_27_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_28_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_29_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_30_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_31_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_32_mode					(SW92510_MODE_DUMMY)
#else /* USED_FAST_SWITCH_LOCAL_IDLE_TO_ACTIVE */
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mode						(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode					(SW92510_MODE_NOISE_SCAN)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode					(SW92510_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_17_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_18_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_19_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_20_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_21_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_22_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_23_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_24_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_25_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_26_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_27_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_28_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_29_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_30_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_31_mode					(SW92510_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_32_mode					(SW92510_MODE_DUMMY)
#endif /* USED_FAST_SWITCH_LOCAL_IDLE_TO_ACTIVE */
//#define PARAMSET_ROIC_FULL_IDLE_LHB_1_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_2_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_3_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_4_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_5_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_6_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_7_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_8_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_9_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_10_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_11_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_12_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_13_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_14_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_15_mode						(SW92510_MODE_DUMMY)
//#define PARAMSET_ROIC_FULL_IDLE_LHB_16_mode						(SW92510_MODE_NOISE_SCAN)


/*
 * AFE Control
 */
#if USED_PEN_MODE_OPERATION
	// 114KHz Base
	#define PARAMSET_ROIC_CFGR_PWM_PRD_fig_pwm_prd					(46)
	#define PARAMSET_ROIC_CFGR_PWM_PRD_pen_pwm_prd					(46)

	#define PARAMSET_ROIC_CFGR_SMPL_CTL_fig_smop_prd				(7)
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_pen_smop_prd				(7)
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_nd_smop_prd					(7)
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_cr_repeat_num				(0)

	// PREAMP Timing
	#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_fig_rstp_rise_num		(15)
	#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_pen_rstp_rise_num		(15)

	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num1		(10)
	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num1 	(10)

	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num2  	(2)
	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num2	 	(2)

	#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num1		(5)
	#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num2		(5)

	#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num1		(17) // stuck1 - (100)
	#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num2 	(17) // stuck1 - (100)

	#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_fig_phtcr_rise_num	(44)
	#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_pen_phtcr_rise_num	(44)

	#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_fig_phtcr_fall_num	(30)
	#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_pen_phtcr_fall_num	(30)

	#define PARAMSET_ROIC_CFGR_VCR_NUM_fig_vcr_num					(40)
	#define PARAMSET_ROIC_CFGR_VCR_NUM_pen_vcr_num					(40)


	// INT Timing
	#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_fig_rsti_rise_num		(15)
	#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_pen_rsti_rise_num		(15)

	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_fig_rsti_fall_num1	(40)
	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_pen_rsti_fall_num1	(40)

	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_fig_rsti_fall_num2	(35)
	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_pen_rsti_fall_num2	(35)

	#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_fig_phth0_rise_num	(30)
	#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_pen_phth0_rise_num	(30)

	#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_fig_phth0_fall_num	(19)
	#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_pen_phth0_fall_num	(19)

	#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_fig_phth1_rise_num	(19)
	#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_pen_phth1_rise_num	(19)

	#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_fig_phth1_fall_num	(30)
	#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_pen_phth1_fall_num	(30)


	// SHA Timing
	#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_fig_pht_rise_num		(28)
	#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_pen_pht_rise_num		(28)

	#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_fig_pht_fall_num		(21)
	#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_pen_pht_fall_num		(21)
#else /* USED_PEN_MODE_OPERATION */

	#if USED_PWM_FRQ_114KHz
		// 114KHz Base
		#define PARAMSET_ROIC_CFGR_PWM_PRD_fig_pwm_prd					(46)
		#define PARAMSET_ROIC_CFGR_PWM_PRD_pen_pwm_prd					(46)

		#define PARAMSET_ROIC_CFGR_SMPL_CTL_fig_smop_prd				(7)
		#define PARAMSET_ROIC_CFGR_SMPL_CTL_pen_smop_prd				(7)
		#define PARAMSET_ROIC_CFGR_SMPL_CTL_nd_smop_prd					(7)
		#define PARAMSET_ROIC_CFGR_SMPL_CTL_cr_repeat_num				(0)

		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_fig_smop_prd			(1)//(1)
		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_pen_smop_prd			(1)//(1)
		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_nd_smop_prd			(1)//(1)
		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_cr_repeat_num			(1)//(1)
		// PREAMP Timing
		#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_fig_rstp_rise_num		(15)
		#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_pen_rstp_rise_num		(15)

		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num1		(10)
		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num1 	(10)

		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num2  	(2)
		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num2	 	(2)

		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num1		(5)
		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num2		(5)

		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num1		(16) // stuck1 - (100)
		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num2 	(16) // stuck1 - (100)

		#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_fig_phtcr_rise_num	(44)
		#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_pen_phtcr_rise_num	(44)

		#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_fig_phtcr_fall_num	(30)
		#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_pen_phtcr_fall_num	(30)

		#define PARAMSET_ROIC_CFGR_VCR_NUM_fig_vcr_num					(40)
		#define PARAMSET_ROIC_CFGR_VCR_NUM_pen_vcr_num					(40)


		// INT Timing
		#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_fig_rsti_rise_num		(15)
		#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_pen_rsti_rise_num		(15)

		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_fig_rsti_fall_num1	(42)
		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_pen_rsti_fall_num1	(42)

		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_fig_rsti_fall_num2	(42)
		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_pen_rsti_fall_num2	(42)

		#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_fig_phth0_rise_num	(30)
		#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_pen_phth0_rise_num	(30)

		#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_fig_phth0_fall_num	(17)
		#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_pen_phth0_fall_num	(17)

		#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_fig_phth1_rise_num	(17)
		#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_pen_phth1_rise_num	(17)

		#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_fig_phth1_fall_num	(30)
		#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_pen_phth1_fall_num	(30)


		// SHA Timing
		#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_fig_pht_rise_num		(24)
		#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_pen_pht_rise_num		(24)

		#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_fig_pht_fall_num		(18)
		#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_pen_pht_fall_num		(18)
		#elif USED_PWM_FRQ_142KHz
		// 140KHz Base
		#define PARAMSET_ROIC_CFGR_PWM_PRD_fig_pwm_prd					(36)
		#define PARAMSET_ROIC_CFGR_PWM_PRD_pen_pwm_prd					(36)

		#define PARAMSET_ROIC_CFGR_SMPL_CTL_fig_smop_prd				(3)
		#define PARAMSET_ROIC_CFGR_SMPL_CTL_pen_smop_prd				(3)
		#define PARAMSET_ROIC_CFGR_SMPL_CTL_nd_smop_prd					(3)
		#define PARAMSET_ROIC_CFGR_SMPL_CTL_cr_repeat_num				(0)

		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_fig_smop_prd			(1)//(1)
		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_pen_smop_prd			(1)//(1)
		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_nd_smop_prd			(1)//(1)
		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_cr_repeat_num			(1)//(1)
		// PREAMP Timing
		#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_fig_rstp_rise_num		(15)
		#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_pen_rstp_rise_num		(15)

		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num1		(10)
		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num1 	(10)

		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num2  	(2)
		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num2	 	(2)

		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num1		(5)
		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num2		(5)

		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num1		(16) // stuck1 - (100)
		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num2 	(16) // stuck1 - (100)

		#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_fig_phtcr_rise_num	(32)
		#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_pen_phtcr_rise_num	(32)

		#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_fig_phtcr_fall_num	(27)
		#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_pen_phtcr_fall_num	(27)

		#define PARAMSET_ROIC_CFGR_VCR_NUM_fig_vcr_num					(30)
		#define PARAMSET_ROIC_CFGR_VCR_NUM_pen_vcr_num					(30)


		// INT Timing
		#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_fig_rsti_rise_num		(15)
		#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_pen_rsti_rise_num		(15)

		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_fig_rsti_fall_num1	(32)
		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_pen_rsti_fall_num1	(32)

		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_fig_rsti_fall_num2	(32)
		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_pen_rsti_fall_num2	(32)

		#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_fig_phth0_rise_num	(26)
		#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_pen_phth0_rise_num	(26)

		#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_fig_phth0_fall_num	(17)
		#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_pen_phth0_fall_num	(17)

		#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_fig_phth1_rise_num	(17)
		#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_pen_phth1_rise_num	(17)

		#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_fig_phth1_fall_num	(26)
		#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_pen_phth1_fall_num	(26)


		// SHA Timing
		#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_fig_pht_rise_num		(24)
		#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_pen_pht_rise_num		(24)

		#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_fig_pht_fall_num		(18)
		#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_pen_pht_fall_num		(18)
	#else /* USED_PWM_FRQ_142KHz */
		// 91KHz Base
		#define PARAMSET_ROIC_CFGR_PWM_PRD_fig_pwm_prd					(58)
		#define PARAMSET_ROIC_CFGR_PWM_PRD_pen_pwm_prd					(58)

		#define PARAMSET_ROIC_CFGR_SMPL_CTL_fig_smop_prd				(10)
		#define PARAMSET_ROIC_CFGR_SMPL_CTL_pen_smop_prd				(10)
		#define PARAMSET_ROIC_CFGR_SMPL_CTL_nd_smop_prd					(10)
		#define PARAMSET_ROIC_CFGR_SMPL_CTL_cr_repeat_num				(0)

		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_fig_smop_prd			(1)
		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_pen_smop_prd			(1)
		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_nd_smop_prd			(1)
		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_cr_repeat_num			(1)

		// PREAMP Timing
		#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_fig_rstp_rise_num		(15)
		#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_pen_rstp_rise_num		(15)

		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num1		(10)
		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num1 	(10)

		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num2  	(2)
		#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num2	 	(2)

		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num1		(5)
		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num2		(5)

		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num1		(17) // stuck1 - (100)
		#define PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num2 	(17) // stuck1 - (100)

		#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_fig_phtcr_rise_num	(54)
		#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_pen_phtcr_rise_num	(54)

		#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_fig_phtcr_fall_num	(40)
		#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_pen_phtcr_fall_num	(40)

		#define PARAMSET_ROIC_CFGR_VCR_NUM_fig_vcr_num					(50)
		#define PARAMSET_ROIC_CFGR_VCR_NUM_pen_vcr_num					(50)


		// INT Timing
		#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_fig_rsti_rise_num		(15)
		#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_pen_rsti_rise_num		(15)

		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_fig_rsti_fall_num1	(52)
		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_pen_rsti_fall_num1	(52)

		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_fig_rsti_fall_num2	(52)
		#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_pen_rsti_fall_num2	(52)

		#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_fig_phth0_rise_num	(38)
		#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_pen_phth0_rise_num	(38)

		#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_fig_phth0_fall_num	(19)
		#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_pen_phth0_fall_num	(19)

		#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_fig_phth1_rise_num	(19)
		#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_pen_phth1_rise_num	(19)

		#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_fig_phth1_fall_num	(38)
		#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_pen_phth1_fall_num	(38)


		// SHA Timing
		#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_fig_pht_rise_num		(32)
		#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_pen_pht_rise_num		(32)

		#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_fig_pht_fall_num		(21)
		#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_pen_pht_fall_num		(21)
	
		// Hopping
		// 133KHz Base
		#define PARAMSET_HOPP_ROIC_CFGR_PWM_PRD_fig_pwm_prd					(38)
		#define PARAMSET_HOPP_ROIC_CFGR_PWM_PRD_pen_pwm_prd					(38)

		#define PARAMSET_HOPP_ROIC_CFGR_SMPL_CTL_fig_smop_prd				(5)
		#define PARAMSET_HOPP_ROIC_CFGR_SMPL_CTL_pen_smop_prd				(5)
		#define PARAMSET_HOPP_ROIC_CFGR_SMPL_CTL_nd_smop_prd				(5)
		#define PARAMSET_HOPP_ROIC_CFGR_SMPL_CTL_cr_repeat_num				(0)


		// PREAMP Timing
		#define PARAMSET_HOPP_ROIC_CFGR_RSTP_RISE_NUM_fig_rstp_rise_num		(15)
		#define PARAMSET_HOPP_ROIC_CFGR_RSTP_RISE_NUM_pen_rstp_rise_num		(15)

		#define PARAMSET_HOPP_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num1	(10)
		#define PARAMSET_HOPP_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num1 	(10)

		#define PARAMSET_HOPP_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num2  	(2)
		#define PARAMSET_HOPP_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num2 	(2)

		#define PARAMSET_HOPP_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num1	(5)
		#define PARAMSET_HOPP_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num2	(5)

		#define PARAMSET_HOPP_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num1	(16) // stuck1 - (100)
		#define PARAMSET_HOPP_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num2 	(16) // stuck1 - (100)

		#define PARAMSET_HOPP_ROIC_CFGR_PHTCR_RISE_NUM_fig_phtcr_rise_num	(34)
		#define PARAMSET_HOPP_ROIC_CFGR_PHTCR_RISE_NUM_pen_phtcr_rise_num	(34)

		#define PARAMSET_HOPP_ROIC_CFGR_PHTCR_FALL_NUM_fig_phtcr_fall_num	(27)
		#define PARAMSET_HOPP_ROIC_CFGR_PHTCR_FALL_NUM_pen_phtcr_fall_num	(27)

		#define PARAMSET_HOPP_ROIC_CFGR_VCR_NUM_fig_vcr_num					(32)
		#define PARAMSET_HOPP_ROIC_CFGR_VCR_NUM_pen_vcr_num					(32)


		// INT Timing
		#define PARAMSET_HOPP_ROIC_CFGR_RSTI_RISE_NUM_fig_rsti_rise_num		(15)
		#define PARAMSET_HOPP_ROIC_CFGR_RSTI_RISE_NUM_pen_rsti_rise_num		(15)

		#define PARAMSET_HOPP_ROIC_CFGR_RSTI_FALL_NUM1_fig_rsti_fall_num1	(34)
		#define PARAMSET_HOPP_ROIC_CFGR_RSTI_FALL_NUM1_pen_rsti_fall_num1	(34)

		#define PARAMSET_HOPP_ROIC_CFGR_RSTI_FALL_NUM2_fig_rsti_fall_num2	(34)
		#define PARAMSET_HOPP_ROIC_CFGR_RSTI_FALL_NUM2_pen_rsti_fall_num2	(34)

		#define PARAMSET_HOPP_ROIC_CFGR_PHTH0_RISE_NUM_fig_phth0_rise_num	(26)
		#define PARAMSET_HOPP_ROIC_CFGR_PHTH0_RISE_NUM_pen_phth0_rise_num	(26)

		#define PARAMSET_HOPP_ROIC_CFGR_PHTH0_FALL_NUM_fig_phth0_fall_num	(17)
		#define PARAMSET_HOPP_ROIC_CFGR_PHTH0_FALL_NUM_pen_phth0_fall_num	(17)

		#define PARAMSET_HOPP_ROIC_CFGR_PHTH1_RISE_NUM_fig_phth1_rise_num	(17)
		#define PARAMSET_HOPP_ROIC_CFGR_PHTH1_RISE_NUM_pen_phth1_rise_num	(17)

		#define PARAMSET_HOPP_ROIC_CFGR_PHTH1_FALL_NUM_fig_phth1_fall_num	(26)
		#define PARAMSET_HOPP_ROIC_CFGR_PHTH1_FALL_NUM_pen_phth1_fall_num	(26)


		// SHA Timing
		#define PARAMSET_HOPP_ROIC_CFGR_RISE_PHT_NUM_fig_pht_rise_num		(24)
		#define PARAMSET_HOPP_ROIC_CFGR_RISE_PHT_NUM_pen_pht_rise_num		(24)

		#define PARAMSET_HOPP_ROIC_CFGR_FALL_PHT_NUM_fig_pht_fall_num		(18)
		#define PARAMSET_HOPP_ROIC_CFGR_FALL_PHT_NUM_pen_pht_fall_num		(18)
	#endif /* USED_PWM_FRQ_142KHz */

#endif /* USED_PEN_MODE_OPERATION */

/*
 * Uplink State Control
 */
#define PARAMSET_ROIC_CFGR_ADC_IN_CTL_uplink_mux				(1023) // LSB 1bit : 1st Mux, Mux Selection Option
#define PARAMSET_ROIC_CFGR_ADC_IN_CTL_uplink_state				(0) //(0) // 0 : VCom, 1 : Mux Connection of AFE, 2 : Mux Floating

/*
 * ADC Clock Control
 */
#define PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_in					(1)
#define PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_op_opt                (0)

#define PARAMSET_ROIC_CFGR_ADC_CTL1_adc_clk_opt           		(2)
#define PARAMSET_ROIC_CFGR_ADC_CTL1_adc_clk_pol           		(0)
#define PARAMSET_ROIC_CFGR_ADC_CTL1_fig_adc_clk_prd       		(1)//(0) //(1) // 0: 6 MHz, 1: 3 MHz
#define PARAMSET_ROIC_CFGR_ADC_CTL1_pen_adc_clk_prd       		(0) //(1) // 0: 6 MHz, 1: 3 MHz
#define PARAMSET_ROIC_CFGR_ADC_CTL1_pdrv_adc_clk_prd      		(0) // 0: 6 MHz, 1: 3 MHz
#define PARAMSET_ROIC_CFGR_ADC_CTL1_fig_conv_smpl_num     		(4)//(8) //(2)
#define PARAMSET_ROIC_CFGR_ADC_CTL1_pen_conv_smpl_num     		(8) //(2)
#define PARAMSET_ROIC_CFGR_ADC_CTL1_pdrv_conv_smpl_num    		(0)
#define PARAMSET_ROIC_CFGR_ADC_CTL1_adc_clk_spt           		(0)
#define PARAMSET_ROIC_CFGR_ADC_CTL1_phd_adc_done_skip     		(1)

#define PARAMSET_ROIC_CFGR_ADC_CTL2_adc_stc_dly   				(10)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_adc_sgap_num            	(4)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_adc_stc_prd             	(1)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_adc_pgap_num            	(4)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_adc_in_pos              	(2)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_adc_clk_num             	(7)

#define PARAMSET_ROIC_CFGR_ADC_CTL3_pdrv_adc_stc_dly            (5)
#define PARAMSET_ROIC_CFGR_ADC_CTL3_pdrv_adc_sgap_num           (5)
#define PARAMSET_ROIC_CFGR_ADC_CTL3_pdrv_adc_stc_prd            (3)
#define PARAMSET_ROIC_CFGR_ADC_CTL3_pdrv_adc_pgap_num           (5)

/*
 * LHB Mux Control
 */
#define PARAMSET_ROIC_LHB_MUX_CTL_r0_mux_m1_bit_en				(0x3FF)
#define PARAMSET_ROIC_LHB_MUX_CTL_r0_mux_nd_bit_en				(0x3FF)
#define PARAMSET_ROIC_LHB_MUX_CTL_r0_mux_pp_bit_en				(31)
#define PARAMSET_ROIC_LHB_MUX_CTL_r0_mux_pd_bit_en				(31)

#define PARAMSET_ROIC_LHB_MUX_CTL_r1_mux_m1_bit_en				(0x3FF)
#define PARAMSET_ROIC_LHB_MUX_CTL_r1_mux_nd_bit_en				(0x3FF)
#define PARAMSET_ROIC_LHB_MUX_CTL_r1_mux_pp_bit_en				(31)
#define PARAMSET_ROIC_LHB_MUX_CTL_r1_mux_pd_bit_en				(31)

#define PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_m1_bit_en			(0x3FF)//(0x155)
#define PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_nd_bit_en			(0x3FF)//(0x155)
#define PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_pp_bit_en			(31)
#define PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_pd_bit_en			(31)

#define PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r1_mux_m1_bit_en			(0x3FF)//(0x155)
#define PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r1_mux_nd_bit_en			(0x3FF)//(0x155)
#define PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r1_mux_pp_bit_en			(31)
#define PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r1_mux_pd_bit_en			(31)

/*
 * Mux Setting in LHB
 */
#define PARAMSET_ROIC_CFGR_LHB_MUX_NUM_fig_lhb_mux_num			(2) // (N+1)
#define PARAMSET_ROIC_CFGR_LHB_MUX_NUM_pen_pos1_lhb_mux_num		(1) // (N+1)
#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
	#define PARAMSET_ROIC_CFGR_LHB_MUX_NUM_pen_dat1_lhb_mux_num		(7) // (N+1)
#else
	#define PARAMSET_ROIC_CFGR_LHB_MUX_NUM_pen_dat1_lhb_mux_num		(6) // (N+1)
#endif

#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_NUM_fig_lhb_mux_num			(0) // (N+1)
#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_NUM_pen_pos1_lhb_mux_num		(1) // (N+1)
#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
	#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_NUM_pen_dat1_lhb_mux_num		(7) // (N+1)
#else
	#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_NUM_pen_dat1_lhb_mux_num		(6) // (N+1)
#endif

/*
 * Power / Bcon Control
 */
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pen_dc_md_pen           	(2)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pen_dc_md_fig           	(0)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pre_ch_conb_en          	(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pre_ch_conb_inv         	(0)

#define PARAMSET_ROIC_AFE_SENSE_CTL1_pen_dc_md_stuck         	(3)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pre_comp                	(0)

#define PARAMSET_ROIC_AFE_SENSE_CTL1_fig_int_ref             	(4)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pen_int_ref             	(4)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_fig_sha_ref             	(4)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pen_sha_ref             	(4)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_fig_pre_bs_lp           	(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pen_pre_bs_lp           	(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pdrv_pre_bs_lp          	(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_fig_int_bs_lp           	(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pen_int_bs_lp           	(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_fig_sha_bs_lp           	(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pen_sha_bs_lp           	(1)

#define PARAMSET_ROIC_AFE_SENSE_CTL2_fig_pre_gc              	(7)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pen_pre_gc_con             (6)//(7)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pen_pre_gc_hov             (4) //(7)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_pre_gc_con         	(7)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_pre_gc_hov         	(7)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_fig_int_gc              	(3)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_gc_con         	(3) //(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_gc_hov         	(1) //(2)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_fig_int_half            	(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_half_con        	(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_half_hov        	(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_int_half_con       	(1)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_int_half_hov       	(1)

#define PARAMSET_ROIC_AFE_SENSE_CTL3_fig_hv_ssu_bcon            (0)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_pen_hv_ssu_bcon            (0)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_pdrv_hv_ssu_bcon           (0)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_fig_lv_ssu_bcon            (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_pen_lv_ssu_bcon            (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_fig_lv_ssu_bcons           (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_pen_lv_ssu_bcons           (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_lv_ssu_bconp               (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_lv_ssu_bconp_buf           (0)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_ref_bcon                   (0)

#define PARAMSET_ROIC_ADC_SENSE_CTL_fig_lv_adc_ref_bcon         (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pen_lv_adc_ref_bcon         (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_lv_adc_ref_bcon        (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL_fig_lv_adc_bcon             (3)//(7) //(3)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pen_lv_adc_bcon             (7) //(3)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_lv_adc_bcon            (7)
#define PARAMSET_ROIC_ADC_SENSE_CTL_adc_clk_div_1p5             (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL_adc_stc_insel               (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_comp_bias_ctl       (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_comp_bias_ctl       (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_comp_bias_ctl      (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_mdac_comp_ctl       (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_mdac_comp_ctl       (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_mdac_comp_ctl      (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_mdac_slew_ctl       (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_mdac_slew_ctl       (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_mdac_slew_ctl      (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_ref_idrv_ctl        (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_ref_idrv_ctl        (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_ref_idrv_ctl       (0)

#define PARAMSET_ROIC_PDB_CTL_stuck_hvbias     					(1) // 0: Stuck, 1: mux_op_end 2: start ~ adc_done   3: Tsyncn
#define PARAMSET_ROIC_PDB_CTL_stuck_hvc        					(1) // 0: Stuck, 1: mux_op_end 2: start ~ adc_done   3: Tsyncn
#define PARAMSET_ROIC_PDB_CTL_stuck_lvbias     					(1) // 0: Stuck, 1: start ~ adc_done 2: Tsyncn
#define PARAMSET_ROIC_PDB_CTL_stuck_int        					(1) // 0: Stuck, 1: start ~ adc_done 2: Tsyncn
#define PARAMSET_ROIC_PDB_CTL_stuck_sha        					(2) // 0: Stuck, 1: sha op     2: start ~ adc_done 3: Tsyncn
#define PARAMSET_ROIC_PDB_CTL_stuck_bgr_en     					(0) // 0: Stuck, 1: Tsync      2: start ~ adc_done
#define PARAMSET_ROIC_PDB_CTL_stuck_bias_en    					(1) //(0) // 0: Stuck, 1: Tsync      2: start ~ adc_done
#define PARAMSET_ROIC_PDB_CTL_stuck_adc        					(2) // 0: Stuck, 1: adc op     2: shart ~ adc_done 3: Tsyncn

#include "param_configset_roic_cr_tune.h"

#endif /* _PARAM_CONFIGSET_ROIC_H_ */
