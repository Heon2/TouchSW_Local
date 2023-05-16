/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : param_configset_roic.h
 * created on : 06. 08. 2021
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
#define USED_PEN_PHD_FUNCTION											(NO)
#if USED_PEN_PHD_FUNCTION
    #define PARAMSET_ROIC_CFGR_PRE_DRV_CTL_pdrv_mode                    (1) // 1: phd mode enable
#else
    #define PARAMSET_ROIC_CFGR_PRE_DRV_CTL_pdrv_mode                    (0) // 0: phd mode disable
#endif

#define PARAMSET_ROIC_SPIS_CFG_chksum_opt                               (1)
#define PARAMSET_ROIC_SPIS_CFG_spis_irq_en                              (1)


/*
 * Clock Control
 */

// Main CFGR
#define PARAMSET_ROIC_CFGR_SYS_CFG_tg_clk_all_on                        (1)
#define PARAMSET_ROIC_CFGR_SYS_CFG_cfclk_on                             (0)
#define PARAMSET_ROIC_CFGR_SYS_CFG_apen_clk_on                          (0)

// R0/R1 CFGR
#define PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf_clk_on                       (1)
#define PARAMSET_ROIC_CFGR_R_SYS_CFG_r_cfclk_on                         (1)
#define PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf1_clk_on                      (1)
#define PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf2_clk_on                      (1)
#define PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf3_clk_on                      (1)
#define PARAMSET_ROIC_CFGR_R_SYS_CFG_r_apen_clk_on                      (0)

// Apen CFGR
#define PARAMSET_ROIC_CFGR_APEN_CFCLK_ON_apen_cfclk_on                  (0)

/*
 * R0/R1 Select
 */
#define PARAMSET_ROIC_CFGR_SDIC_CFG_vsync_tg_en							(0)

#define PARAMSET_ROIC_0_CFGR_SDIC_CFG_tsync_r0_r1_sel                   (1) // 0 : R0, 1 : R1
#define PARAMSET_ROIC_1_CFGR_SDIC_CFG_tsync_r0_r1_sel                   (0) // 0 : R0, 1 : R1
#define PARAMSET_ROIC_2_CFGR_SDIC_CFG_tsync_r0_r1_sel                   (1) // 0 : R0, 1 : R1
#define PARAMSET_ROIC_3_CFGR_SDIC_CFG_tsync_r0_r1_sel                   (0) // 0 : R0, 1 : R1
//#define PARAMSET_ROIC_4_CFGR_SDIC_CFG_tsync_r0_r1_sel                   (1) // 0 : R0, 1 : R1
//#define PARAMSET_ROIC_5_CFGR_SDIC_CFG_tsync_r0_r1_sel                   (0) // 0 : R0, 1 : R1
#define PARAMSET_ROIC_0_CFGR_SDIC_CFG_pwm_r0_r1_sel                     (1) // 0 : R0, 1 : R1
#define PARAMSET_ROIC_1_CFGR_SDIC_CFG_pwm_r0_r1_sel                     (0) // 0 : R0, 1 : R1
#define PARAMSET_ROIC_2_CFGR_SDIC_CFG_pwm_r0_r1_sel                     (1) // 0 : R0, 1 : R1
#define PARAMSET_ROIC_3_CFGR_SDIC_CFG_pwm_r0_r1_sel                     (0) // 0 : R0, 1 : R1
//#define PARAMSET_ROIC_4_CFGR_SDIC_CFG_pwm_r0_r1_sel                     (1) // 0 : R0, 1 : R1
//#define PARAMSET_ROIC_5_CFGR_SDIC_CFG_pwm_r0_r1_sel                     (0) // 0 : R0, 1 : R1

/*
 * SDIC Control
 */
#define PARAMSET_ROIC_CFGR_SDIC_CFG_sd_rocen                            (0) // 0: 0 Stuck, 1: 1 Stuck, 2:
#define PARAMSET_ROIC_CFGR_SDIC_CFG_sd_off_ctl                          (0)
#define PARAMSET_ROIC_CFGR_SDIC_CFG_sd_float0_ctl                       (0)
#define PARAMSET_ROIC_CFGR_SDIC_CFG_sd_float1_ctl                       (0)
#define PARAMSET_ROIC_CFGR_SDIC_CFG_sd_gnd0_ctl                         (0)
#define PARAMSET_ROIC_CFGR_SDIC_CFG_sd_gnd1_ctl                         (0)

/*
 * Channel Control
 */

#define PARAMSET_ROIC_CFGR_CH_NUM_fig_ch_num					        (28)
#define PARAMSET_ROIC_CFGR_CH_NUM_pen_ch_num			 		        (28)
#define PARAMSET_ROIC_CFGR_CH_NUM_pdrv_ch_num					        (28)

/*
 * Total Mux Num Control
 */
#define PARAMSET_ROIC_CFGR_CH_NUM_tot_mux_num                           (9) // N+1, 10 Mux(1+1)
#if USED_IDLE_FINGER_EVEN_ODD
	#define PARAMSET_ROIC_CFGR_IDLE_CH_NUM_tot_mux_num                      (1) // N+1, 2 Mux(1+1)
#else /* USED_IDLE_FINGER_EVEN_ODD */
	#define PARAMSET_ROIC_CFGR_IDLE_CH_NUM_tot_mux_num                      (0) // N+1, 2 Mux(1+1)
#endif /* USED_IDLE_FINGER_EVEN_ODD */

/*
 * fINGER MUX Sensing Order
 */
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00			        (0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01			        (1)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02			        (2)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03			        (3)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04			        (4)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05			        (5)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06			        (6)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07			        (7)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08			        (8)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09			        (9)

#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_10			        (0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_11			        (0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_12			        (0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_13			        (0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_14			        (0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_15			        (0)

#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_00		        (11) // 11, 12
#if USED_IDLE_FINGER_EVEN_ODD
	#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_01		        (12) //	0: All MUX , 12: Even/Odd MUX
#else
	#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_01		        (0) //	0: All MUX , 12: Even/Odd MUX
#endif
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_02		        (0)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_03		        (0)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_04		        (0)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_05		        (0)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_06		        (0)
#define PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_07		        (0)

#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_nxt_lhb_mode			        (0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_tsync_num				        (16)  // Total LHB Number
#define PARAMSET_ROIC_IDLE_CFGR_RCOM_LHB_CFG_tsync_num		        	(16)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_dum_tsync_num			        (0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_beacon_en				        (0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_rdcom_en				        (0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_sgap_num				        (0)
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_r0pd					        (0) // R0 Analoge Power Down
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_r1pd					        (0) // R1 Analoge Power Down
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_sel_hover				        (0) // 1: hover, 0 : Contact
#define PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_fixed_pen_mux_dly_en            (0)

/*
 * Finger Mux delay Control
 */
#define PARAMSET_ROIC_CFGR_MUX_DLY0_mux_1_dly					        (0)
#define PARAMSET_ROIC_CFGR_MUX_DLY0_mux_2_dly					        (0)
#define PARAMSET_ROIC_CFGR_MUX_DLY0_mux_3_dly					        (0)
#define PARAMSET_ROIC_CFGR_MUX_DLY0_mux_4_dly					        (0)
#define PARAMSET_ROIC_CFGR_MUX_DLY0_mux_5_dly					        (0)
#define PARAMSET_ROIC_CFGR_MUX_DLY1_mux_6_dly					        (0)
#define PARAMSET_ROIC_CFGR_MUX_DLY1_mux_7_dly					        (0)
#define PARAMSET_ROIC_CFGR_MUX_DLY1_mux_8_dly					        (0)
#define PARAMSET_ROIC_CFGR_MUX_DLY1_mux_9_dly					        (0)
#define PARAMSET_ROIC_CFGR_MUX_DLY1_mux_10_dly					        (0)

///*
// * SD Off Control
// */
//#define PARAMSET_ROIC_SDIC_CFG_sd_off_en						(0)//(1)//(1)
//#define PARAMSET_ROIC_SDIC_sd_off_ctl							(0)//(2)//(2) // 1 : ADC Done�� SD On, 2 : T-Sync Low���� SD Off
//#define PARAMSET_ROIC_SDIC_rocen     							(0)//(1)      // 0 : ROIC Garbage Control Disable(Default), 1 : Enable // added
/*
 * MUX Control
 */
#if USED_CMUX_OFF
	#define PARAMSET_ROIC_CFGR_MUX_CTL_mux_s_stuck_en                       (1)
	#define PARAMSET_ROIC_CFGR_MUX_CTL_mux_s_stuck_val                      (0)

	#define PARAMSET_ROIC_CFGR_MUX_CTL_mux_f_stuck_en                       (1)
	#define PARAMSET_ROIC_CFGR_MUX_CTL_mux_f_stuck_val                      (0x3FF)
#else
	#define PARAMSET_ROIC_CFGR_MUX_CTL_mux_s_stuck_en                       (0)
	#define PARAMSET_ROIC_CFGR_MUX_CTL_mux_s_stuck_val                      (0)

	#define PARAMSET_ROIC_CFGR_MUX_CTL_mux_f_stuck_en                       (0)
	#define PARAMSET_ROIC_CFGR_MUX_CTL_mux_f_stuck_val                      (0)
#endif

#define PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_mux_int_en                     (0)
#define PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_mux_int_stuck_val              (0)

#define PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_uplink_mux                     (0x3FF)
#define PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_uplink_state                   (1)      // [0] : MUX_S On/Off,  [1] : MUX_F On/Off

#if USED_ESD_RECOVERY_SENSING_WITHOUT_MODULATION
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_m1_bit_en                    (0x155)   // For Idle Mode
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_nd_bit_en                    (0x155)   // For Idle Mode
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_pen_bit_en                   (0x1F)//(0x1F)
#else
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_m1_bit_en                    (0x3FF)   // For Idle Mode
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_nd_bit_en                    (0x3FF)   // For Idle Mode
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_pen_bit_en                   (0x1F)
#endif

#if USED_IDLE_FINGER_EVEN_ODD
	#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_CTL_mux_m1_bit_en               (0x155)	//(0x3FF)   // For Idle Mode
	#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_CTL_mux_nd_bit_en               (0x155)	//(0x3FF)   // For Idle Mode
	#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_CTL_mux_pen_bit_en              (0x1F)
#else /* USED_IDLE_FINGER_EVEN_ODD */
	#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_CTL_mux_m1_bit_en               (0x3FF)   // For Idle Mode
	#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_CTL_mux_nd_bit_en               (0x3FF)   // For Idle Mode
	#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_CTL_mux_pen_bit_en              (0x1F)
#endif /* USED_IDLE_FINGER_EVEN_ODD */


/*
 * Finger Sensing
 */
#define PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_act_num				(11) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_mgap_num				(1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num				(3)
#define PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_set_num				(1)

#define PARAMSET_ROIC_CFGR_PWM_FIG_HOPPFRQ_CTL_pwm_act_num		(14) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_HOPPFRQ_CTL_pwm_mgap_num		(1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_HOPPFRQ_CTL_pwm_dum_num		(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)
#define PARAMSET_ROIC_CFGR_PWM_FIG_HOPPFRQ_CTL_pwm_set_num		(1)

#define PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_act_num			(8) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_mgap_num		(1)
#define PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_dum_num			(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)
#define PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_set_num			(1)

/*
 * Pen Position Sensing
 */
#define PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_pdrv_num				        (0)
#define PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_mux1_act_num                 (7)//(15) // (N+1) = 11  1st mux pwm number
#define PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_act_num				        (7)//(15) // (N+1) = 11
#define PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_mgap_num				        (1)
#define PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_dum_num				        (PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)//(3)
#define PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_set_num				        (1)

#define PARAMSET_ROIC_CFGR_PWM_POS_HOPPFRQ_CTL_pwm_pdrv_num			    (0)
#define PARAMSET_ROIC_CFGR_PWM_POS_HOPPFRQ_CTL_pwm_mux1_act_num         (13)//(15) // (N+1) = 11  1st mux pwm number
#define PARAMSET_ROIC_CFGR_PWM_POS_HOPPFRQ_CTL_pwm_act_num				(13)//(15) // (N+1) = 11
#define PARAMSET_ROIC_CFGR_PWM_POS_HOPPFRQ_CTL_pwm_mgap_num				(1)
#define PARAMSET_ROIC_CFGR_PWM_POS_HOPPFRQ_CTL_pwm_dum_num				(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)//(3)
#define PARAMSET_ROIC_CFGR_PWM_POS_HOPPFRQ_CTL_pwm_set_num				(1)

#define PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_pdrv_num				(0)
#define PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_mux1_act_num            (7)//(15) // (N+1) = 11  1st mux pwm number
#define PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_act_num				    (7)//(15) // (N+1) = 11
#define PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_mgap_num				(1)
#define PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_dum_num				    (PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)//(3)
#define PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_set_num				    (1)

/*
 * Pen Tilt Sensing
 */
#define PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_pdrv_num			        (0)
#define PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_mux1_act_num		        (15) // (N+1) = 11
#define PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_act_num				        (15) // (N+1) = 11
#define PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_mgap_num			        (1)
#define PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_dum_num				        (PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)//(3)
#define PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_set_num				        (1)

#define PARAMSET_ROIC_CFGR_PWM_TILT_HOPPFRQ_CTL_pwm_pdrv_num			(0)
#define PARAMSET_ROIC_CFGR_PWM_TILT_HOPPFRQ_CTL_pwm_mux1_act_num		(15) // (N+1) = 11
#define PARAMSET_ROIC_CFGR_PWM_TILT_HOPPFRQ_CTL_pwm_act_num				(15) // (N+1) = 11
#define PARAMSET_ROIC_CFGR_PWM_TILT_HOPPFRQ_CTL_pwm_mgap_num			(1)
#define PARAMSET_ROIC_CFGR_PWM_TILT_HOPPFRQ_CTL_pwm_dum_num				(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)//(3)
#define PARAMSET_ROIC_CFGR_PWM_TILT_HOPPFRQ_CTL_pwm_set_num				(1)

#define PARAMSET_ROIC_CFGR_PWM_TILT_IDLE_CTL_pwm_pdrv_num			    (0)
#define PARAMSET_ROIC_CFGR_PWM_TILT_IDLE_CTL_pwm_mux1_act_num		    (15) // (N+1) = 11
#define PARAMSET_ROIC_CFGR_PWM_TILT_IDLE_CTL_pwm_act_num				(15) // (N+1) = 11
#define PARAMSET_ROIC_CFGR_PWM_TILT_IDLE_CTL_pwm_mgap_num			    (1)
#define PARAMSET_ROIC_CFGR_PWM_TILT_IDLE_CTL_pwm_dum_num				(PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num)//(3)
#define PARAMSET_ROIC_CFGR_PWM_TILT_IDLE_CTL_pwm_set_num				(1)


/*
 * Pen Data Sensing
 */
#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_pdrv_num			        (0)
#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_mux1_act_num		        (4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_mux2_act_num		        (4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_act_num				        (4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_mgap_num			        (0)
#ifdef USED_TOUCH_WGP_PREDRV_MUX_SENSING
	#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_dum_num			        (4)
#else /* USED_TOUCH_WGP_PREDRV_MUX_SENSING */
	#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_dum_num	                (9)
#endif /* USED_TOUCH_WGP_PREDRV_MUX_SENSING */
#define PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_set_num				        (1)

#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_pdrv_num			        (0)
#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_mux1_act_num		        (4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_mux2_act_num		        (4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_act_num				        (4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_mgap_num			        (0)
#ifdef USED_TOUCH_WGP_PREDRV_MUX_SENSING
	#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_dum_num			        (4)
#else /* USED_TOUCH_WGP_PREDRV_MUX_SENSING */
	#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_dum_num	                (9)
#endif /* USED_TOUCH_WGP_PREDRV_MUX_SENSING */
#define PARAMSET_ROIC_CFGR_PWM_DATA_HOPPFRQ_CTL_pwm_set_num				        (1)

#define PARAMSET_ROIC_CFGR_PWM_DATA_IDLE_CTL_pwm_pdrv_num			        (0)
#define PARAMSET_ROIC_CFGR_PWM_DATA_IDLE_CTL_pwm_mux1_act_num		        (4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_IDLE_CTL_pwm_mux2_act_num		        (4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_IDLE_CTL_pwm_act_num				    (4) // (N+1)
#define PARAMSET_ROIC_CFGR_PWM_DATA_IDLE_CTL_pwm_mgap_num			        (0)
#ifdef USED_TOUCH_WGP_PREDRV_MUX_SENSING
	#define PARAMSET_ROIC_CFGR_PWM_DATA_IDLE_CTL_pwm_dum_num			        (4)
#else /* USED_TOUCH_WGP_PREDRV_MUX_SENSING */
	#define PARAMSET_ROIC_CFGR_PWM_DATA_IDLE_CTL_pwm_dum_num	                (9)
#endif /* USED_TOUCH_WGP_PREDRV_MUX_SENSING */
#define PARAMSET_ROIC_CFGR_PWM_DATA_IDLE_CTL_pwm_set_num				        (1)


/*
 * LHB Mode Setting
 */
#if USED_DUMMY_LHB_MODULATION
	#define PARAMSET_ROIC_FULL_LHB_1_mode							(SW92513_MODE_BEACON)
	#define PARAMSET_ROIC_FULL_LHB_2_mode							(SW92513_MODE_BEACON)
	#if USED_ESD_RECOVERY_SENSING_WITHOUT_MODULATION
		#define PARAMSET_ROIC_FULL_LHB_3_mode							(SW92513_MODE_ESD_SCAN)
	#else
		#define PARAMSET_ROIC_FULL_LHB_3_mode							(SW92513_MODE_BEACON)
	#endif
	#define PARAMSET_ROIC_FULL_LHB_4_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_5_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_6_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_7_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_8_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_9_mode							(SW92513_MODE_BEACON)
	#define PARAMSET_ROIC_FULL_LHB_10_mode							(SW92513_MODE_BEACON)
	#if USED_ESD_RECOVERY_SENSING_WITHOUT_MODULATION
		#define PARAMSET_ROIC_FULL_LHB_11_mode							(SW92513_MODE_ESD_SCAN)
	#else
		#define PARAMSET_ROIC_FULL_LHB_11_mode							(SW92513_MODE_BEACON)
	#endif
	#define PARAMSET_ROIC_FULL_LHB_12_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_13_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_14_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_15_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_16_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_17_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_18_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_19_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_20_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_21_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_22_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_23_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_24_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_25_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_26_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_27_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_28_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_29_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_30_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_31_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_32_mode							(SW92513_MODE_DUMMY)
#else
	#if USED_PEN_MODE_OPERATION
		#define PARAMSET_ROIC_FULL_LHB_1_mode						(SW92513_MODE_BEACON)
	#else
		#define PARAMSET_ROIC_FULL_LHB_1_mode						(SW92513_MODE_DUMMY)
	#endif
	#define PARAMSET_ROIC_FULL_LHB_2_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_3_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_4_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_5_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_6_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_7_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_8_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_9_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_10_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_11_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_12_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_13_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_14_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_15_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_16_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_17_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_18_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_19_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_20_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_21_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_22_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_23_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_24_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_25_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_26_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_27_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_28_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_29_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_30_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_31_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_32_mode							(SW92513_MODE_DUMMY)
#endif


	#define PARAMSET_ROIC_LOCAL_LHB_1_mode							(SW92513_MODE_BEACON)
	#define PARAMSET_ROIC_LOCAL_LHB_2_mode							(SW92513_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_LHB_3_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_4_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_LOCAL_LHB_5_mode							(SW92513_MODE_PEN_TILT)
	#define PARAMSET_ROIC_LOCAL_LHB_6_mode							(SW92513_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_LHB_7_mode							(SW92513_MODE_PEN_DAT)
	#define PARAMSET_ROIC_LOCAL_LHB_8_mode							(SW92513_MODE_PEN_DAT)
	#define PARAMSET_ROIC_LOCAL_LHB_9_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_LOCAL_LHB_10_mode							(SW92513_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_LHB_11_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_LOCAL_LHB_12_mode							(SW92513_MODE_FINGER)
	#define PARAMSET_ROIC_LOCAL_LHB_13_mode							(SW92513_MODE_PEN_TILT)
	#define PARAMSET_ROIC_LOCAL_LHB_14_mode							(SW92513_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_LHB_15_mode							(SW92513_MODE_PEN_DAT)
	#define PARAMSET_ROIC_LOCAL_LHB_16_mode							(SW92513_MODE_PEN_DAT)
	#define PARAMSET_ROIC_LOCAL_LHB_17_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_18_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_19_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_20_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_21_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_22_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_23_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_24_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_25_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_26_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_27_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_28_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_29_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_30_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_31_mode							(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_32_mode							(SW92513_MODE_DUMMY)

#if USED_IDLE_MODE_30Hz_CONTROL
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_17_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_18_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_19_mode					(SW92513_MODE_NOISE_SCAN)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_20_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_21_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_22_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_23_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_24_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_25_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_26_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_27_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_28_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_29_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_30_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_31_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_32_mode					(SW92513_MODE_DUMMY)
#elif USED_IDLE_MODE_20Hz_CONTROL
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mode						(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_17_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_18_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_19_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_20_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_21_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_22_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_23_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_24_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_25_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_26_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_27_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_28_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_29_mode					(SW92513_MODE_NOISE_SCAN)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_30_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_31_mode					(SW92513_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_32_mode					(SW92513_MODE_DUMMY)
#else
	#if USED_FULLSCAN_SWITCH_IDLE_TO_ACTIVE
		#if USED_DUMMY_LHB_MODULATION
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mode						(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mode						(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mode						(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mode						(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mode						(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mode						(SW92513_MODE_BEACON)
			#if USED_ESD_RECOVERY_SENSING_WITHOUT_MODULATION
				#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode						(SW92513_MODE_ESD_SCAN)
			#else
				#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode						(SW92513_MODE_BEACON)
			#endif
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mode						(SW92513_MODE_NOISE_SCAN)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mode						(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mode					(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mode					(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mode					(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mode					(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode					(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode					(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode					(SW92513_MODE_BEACON)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_17_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_18_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_19_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_20_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_21_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_22_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_23_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_24_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_25_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_26_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_27_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_28_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_29_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_30_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_31_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_32_mode					(SW92513_MODE_DUMMY)
		#else /* USED_DUMMY_LHB_MODULATION */
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mode						(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mode						(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mode						(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mode						(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mode						(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mode						(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode						(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mode						(SW92513_MODE_NOISE_SCAN)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mode						(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_17_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_18_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_19_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_20_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_21_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_22_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_23_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_24_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_25_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_26_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_27_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_28_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_29_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_30_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_31_mode					(SW92513_MODE_DUMMY)
			#define PARAMSET_ROIC_LOCAL_IDLE_LHB_32_mode					(SW92513_MODE_DUMMY)
		#endif /* USED_DUMMY_LHB_MODULATION */
	#else /* USED_IDLE_MODE_FULL_SENSING */
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mode						(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mode						(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mode						(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mode						(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mode						(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mode						(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode						(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mode						(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mode						(SW92513_MODE_NOISE_SCAN)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_17_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_18_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_19_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_20_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_21_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_22_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_23_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_24_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_25_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_26_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_27_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_28_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_29_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_30_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_31_mode					(SW92513_MODE_DUMMY)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_32_mode					(SW92513_MODE_DUMMY)
	#endif /* USED_IDLE_MODE_FULL_SENSING */
#endif


/*
 * AFE Control - All
 */

// CVC1 DRV Ctrl

#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_fig_tg_cvc1_drv_en             (1)
#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_fig_tg_cvc1_drv_d_en           (1)
#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_fig_tg_cvc1_drv_init           (1)
#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_fig_tg_cvc1_drv_d_init         (1)
#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_fig_tg_cvc1_rstp_en            (1)

// Do not use Cvc1 Control in Pen Mode - this for Test
#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_pen_tg_cvc1_drv_en             (0)
#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_pen_tg_cvc1_drv_d_en           (0)
#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_pen_tg_cvc1_drv_init           (1)
#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_pen_tg_cvc1_drv_d_init         (1)
#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_pen_tg_cvc1_rstp_en            (0)

// For Stable Time
#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_tg_cvc1_rstp_dum_en            (1)

// VCR & PHTCR Ctrl
#define PARAMSET_ROIC_CFGR_VCR_NUM_fig_vcr_off_en                       (0)
#define PARAMSET_ROIC_CFGR_VCR_NUM_fig_phtcr_off_en                     (0)

#define PARAMSET_ROIC_CFGR_VCR_NUM_pen_vcr_off_en                       (0)//(1)
#define PARAMSET_ROIC_CFGR_VCR_NUM_pen_phtcr_off_en                     (0)//(1)

#define PARAMSET_ROIC_CFGR_VCR_NUM_phtcr_dum_en                         (1) // Check
#define PARAMSET_ROIC_CFGR_VCR_NUM_vcr_dum_en                           (1) // Check

// PHT CTL
#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_prd                              (6)
#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_opt_inv                          (1)
#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_end_time                         (20)
#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_act_pwm_num                      (1)
#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_act_pwr_num                      (3)

#define PARAMSET_ROIC_CFGR_PHT_CTL_fig_pre_pht_sel                      (0)
#define PARAMSET_ROIC_CFGR_PHT_CTL_pen_pos_pre_pht_sel                  (0)
#define PARAMSET_ROIC_CFGR_PHT_CTL_pen_dat_pre_pht_sel                  (0)
#define PARAMSET_ROIC_CFGR_PHT_CTL_pen_tilt_pre_pht_sel                 (0)


#if USED_PEN_MODE_OPERATION
		// 114KHz Base
	#define PARAMSET_ROIC_CFGR_PWM_PRD_fig_pwm_prd					        (46)

	// PRE
	#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL2_fig_cvc1_drv_rstp_dly          (13)

	#define PARAMSET_ROIC_CFGR_CVC1_DRV_fig_cvc1_drv_fall_num               (40)
	#define PARAMSET_ROIC_CFGR_CVC1_DRV_fig_cvc1_drv_rise_num               (27)

	#define PARAMSET_ROIC_CFGR_CVC1_DRV_D_fig_cvc1_drv_d_fall_num           (39)
	#define PARAMSET_ROIC_CFGR_CVC1_DRV_D_fig_cvc1_drv_d_rise_num           (26)

	// Finger Mode - RSTP --> CVC1 Reset
	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM1_fig_rstp_fall_num1	        (30)
	#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_fig_rstp_rise_num		        (42)
	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM2_fig_rstp_fall_num2  	        (30)

	// VCR & PHTCR
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_fig_smop_prd                        (3)
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_fig_cr_repeat_num                   (0)

	#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_fig_smop_prd                   (3)
	#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_fig_cr_repeat_num              (0)

	#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_fig_phtcr_rise_num	        (38)
	#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_fig_phtcr_fall_num	        (30)

	#define PARAMSET_ROIC_CFGR_VCR_NUM_fig_vcr_num					        (36)

	// INT Timing
	#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_fig_phth0_rise_num            (25)
	#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_fig_phth0_fall_num            (17)

	#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_fig_phth1_rise_num            (10)
	#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_fig_phth1_fall_num            (30)

	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_fig_rsti_fall_num1            (44)
	#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_fig_rsti_rise_num              (15)
	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_fig_rsti_fall_num2            (26)

	// SHA Timing
	#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_fig_pht_rise_num                (24)
	#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_fig_pht_fall_num                (18)


	// 114KHz Base (PEN))
	// PEN - Stuck CVC1_DRV & CVC1_DRV_D
	#define PARAMSET_ROIC_CFGR_PWM_PRD_pen_pwm_prd					        (46)
	#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL2_pen_cvc1_drv_rstp_dly          (13)

	#define PARAMSET_ROIC_CFGR_CVC1_DRV_pen_cvc1_drv_fall_num               (40)
	#define PARAMSET_ROIC_CFGR_CVC1_DRV_pen_cvc1_drv_rise_num               (27)

	#define PARAMSET_ROIC_CFGR_CVC1_DRV_D_pen_cvc1_drv_d_fall_num           (40-1)
	#define PARAMSET_ROIC_CFGR_CVC1_DRV_D_pen_cvc1_drv_d_rise_num           (27-1)

	// RSTP - for Pen
	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM1_pen_rstp_fall_num1 	        (15)
	#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_pen_rstp_rise_num		        (10)
	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM2_pen_rstp_fall_num2	        (2)

	// VCR & PHTCR - Not Use in Pen Mode
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_pen_smop_prd                        (3)
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_pen_cr_repeat_num                   (0)

	#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_pen_smop_prd                   (3)
	#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_pen_cr_repeat_num              (0)

	#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_pen_phtcr_rise_num	        (38)
	#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_pen_phtcr_fall_num	        (30)

	#define PARAMSET_ROIC_CFGR_VCR_NUM_pen_vcr_num					        (36)

	// INT Timing
	#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_pen_phth0_rise_num            (25)
	#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_pen_phth0_fall_num            (17)

	#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_pen_phth1_fall_num            (30)
	#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_pen_phth1_rise_num            (17)

	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_pen_rsti_fall_num1            (44)
	#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_pen_rsti_rise_num              (15)
	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_pen_rsti_fall_num2            (26)

	// SHA Timing
	#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_pen_pht_rise_num                (24)
	#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_pen_pht_fall_num                (18)
#else /* USED_PEN_MODE_OPERATION */
/****************************************** Finger ********************************************/
/*****************************************  91 KHz  *******************************************/
	#define PARAMSET_ROIC_CFGR_PWM_PRD_fig_pwm_prd					        (58)

	// CVC1
	#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL2_fig_cvc1_drv_rstp_dly          (4)

	#define PARAMSET_ROIC_CFGR_CVC1_DRV_fig_cvc1_drv_fall_num               (54)
	#define PARAMSET_ROIC_CFGR_CVC1_DRV_fig_cvc1_drv_rise_num               (42)

	#define PARAMSET_ROIC_CFGR_CVC1_DRV_D_fig_cvc1_drv_d_fall_num           (53)
	#define PARAMSET_ROIC_CFGR_CVC1_DRV_D_fig_cvc1_drv_d_rise_num           (41)

	// Finger Mode - RSTP --> CVC1 Reset
	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM1_fig_rstp_fall_num1		    (44)
	#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_fig_rstp_rise_num		        (56)
	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM2_fig_rstp_fall_num2  	        (44)

	// VCR & PHTCR
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_fig_smop_prd                        (10)
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_fig_cr_repeat_num                   (0)

	#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_fig_smop_prd                   (10)
	#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_fig_cr_repeat_num              (0)

	#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_fig_phtcr_rise_num	        (51)
	#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_fig_phtcr_fall_num	        (10)// Setting for PT Short 2 Test(CR 3 times)

	#define PARAMSET_ROIC_CFGR_VCR_NUM_fig_vcr_num					        (46)

	// INT Timing
	#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_fig_phth0_rise_num            (34)
	#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_fig_phth0_fall_num            (4)

	#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_fig_phth1_rise_num            (4)
	#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_fig_phth1_fall_num            (34)

	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_fig_rsti_fall_num1            (54)
	#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_fig_rsti_rise_num              (2)
	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_fig_rsti_fall_num2            (54)

	// SHA Timing
	#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_fig_pht_rise_num                (15)
	#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_fig_pht_fall_num                (5)

/*****************************************  133 KHz  *******************************************/
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PWM_PRD_fig_pwm_prd					        (38)//(38)//(39)//(58)

	// CVC1
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_CVC1_DRV_CTL2_fig_cvc1_drv_rstp_dly          (4)//(4)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_CVC1_DRV_fig_cvc1_drv_fall_num               (35)//(54)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_CVC1_DRV_fig_cvc1_drv_rise_num               (23)//(42)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_CVC1_DRV_D_fig_cvc1_drv_d_fall_num           (34)//(53)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_CVC1_DRV_D_fig_cvc1_drv_d_rise_num           (22)//(41)

	// Finger Mode - RSTP --> CVC1 Reset
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTP_FALL_NUM1_fig_rstp_fall_num1		    (24)//(24)//(25)//(44)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTP_RISE_NUM_fig_rstp_rise_num		        (36)//(36)//(37)//(56)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTP_FALL_NUM2_fig_rstp_fall_num2  	        (24)//(24)//(25)//(44)

	// VCR & PHTCR
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_SMPL_CTL_fig_smop_prd                        (3)//(3)//(7)//(10)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_SMPL_CTL_fig_cr_repeat_num                   (0)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_RISE_NUM_fig_phtcr_rise_num	        (31)//(51)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_FALL_NUM_fig_phtcr_fall_num	        (20)//(10)// Setting for PT Short 2 Test(CR 3 times)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_NUM_fig_vcr_num					        (27)//(46)

	// INT Timing
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH0_RISE_NUM_fig_phth0_rise_num            (18)//(34)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH0_FALL_NUM_fig_phth0_fall_num            (5)//(4)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH1_RISE_NUM_fig_phth1_rise_num            (5)//(4)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH1_FALL_NUM_fig_phth1_fall_num            (18)//(34)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTI_FALL_NUM1_fig_rsti_fall_num1            (36)//(36)//(37)//(54)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTI_RISE_NUM_fig_rsti_rise_num              (2)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTI_FALL_NUM2_fig_rsti_fall_num2            (36)//(36)//(37)//(54)

	// SHA Timing
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RISE_PHT_NUM_fig_pht_rise_num                (16)//(15)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_FALL_PHT_NUM_fig_pht_fall_num                (6)//(5)

/******************************************  PEN   ********************************************/
/*****************************************  91 KHz  ******************************************/
	// PEN - Stuck CVC1_DRV & CVC1_DRV_D
	#define PARAMSET_ROIC_CFGR_PWM_PRD_pen_pwm_prd					        (58)
		#define PARAMSET_ROIC_CFGR_CVC1_DRV_CTL2_pen_cvc1_drv_rstp_dly          (4)

		#define PARAMSET_ROIC_CFGR_CVC1_DRV_pen_cvc1_drv_fall_num               (54)
		#define PARAMSET_ROIC_CFGR_CVC1_DRV_pen_cvc1_drv_rise_num               (42)

		#define PARAMSET_ROIC_CFGR_CVC1_DRV_D_pen_cvc1_drv_d_fall_num           (53)
		#define PARAMSET_ROIC_CFGR_CVC1_DRV_D_pen_cvc1_drv_d_rise_num           (41)

	// RSTP - for Pen
	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM1_pen_rstp_fall_num1 	        (15)
	#define PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_pen_rstp_rise_num		        (10)
	#define PARAMSET_ROIC_CFGR_RSTP_FALL_NUM2_pen_rstp_fall_num2	        (2)

		// VCR & PHTCR - Not Use in Pen Mode
		#define PARAMSET_ROIC_CFGR_SMPL_CTL_pen_smop_prd                        (10)
		#define PARAMSET_ROIC_CFGR_SMPL_CTL_pen_cr_repeat_num                   (0)

		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_pen_smop_prd                   (10)
		#define PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_pen_cr_repeat_num              (0)

		#define PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_pen_phtcr_rise_num	        (51)
		#define PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_pen_phtcr_fall_num	        (10)

		#define PARAMSET_ROIC_CFGR_VCR_NUM_pen_vcr_num					        (46)

	// INT Timing
	#define PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_pen_phth0_rise_num            (34)
	#define PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_pen_phth0_fall_num            (12)

	#define PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_pen_phth1_rise_num            (12)
	#define PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_pen_phth1_fall_num            (34)

	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_pen_rsti_fall_num1            (54)
	#define PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_pen_rsti_rise_num              (10)
	#define PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_pen_rsti_fall_num2            (54)

	// SHA Timing
	#define PARAMSET_ROIC_CFGR_RISE_PHT_NUM_pen_pht_rise_num                (20)
	#define PARAMSET_ROIC_CFGR_FALL_PHT_NUM_pen_pht_fall_num                (14)

/*****************************************  133 KHz  *******************************************/
	// PEN - Stuck CVC1_DRV & CVC1_DRV_D
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PWM_PRD_pen_pwm_prd					        (38)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_CVC1_DRV_CTL2_pen_cvc1_drv_rstp_dly          (5)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_CVC1_DRV_pen_cvc1_drv_fall_num               (35)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_CVC1_DRV_pen_cvc1_drv_rise_num               (23)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_CVC1_DRV_D_pen_cvc1_drv_d_fall_num           (34)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_CVC1_DRV_D_pen_cvc1_drv_d_rise_num           (22)

	// RSTP - for Pen
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTP_FALL_NUM1_pen_rstp_fall_num1 	        (15)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTP_RISE_NUM_pen_rstp_rise_num		        (10)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTP_FALL_NUM2_pen_rstp_fall_num2	        (2)

	// VCR & PHTCR - Not Use in Pen Mode
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_SMPL_CTL_pen_smop_prd                        (3)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_SMPL_CTL_pen_cr_repeat_num                   (0)

	#define PARAMSET_IDLE_ROIC_HOPPFRQ_CFGR_SMPL_CTL_pen_smop_prd                   (3)
	#define PARAMSET_IDLE_ROIC_HOPPFRQ_CFGR_SMPL_CTL_pen_cr_repeat_num              (0)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_RISE_NUM_pen_phtcr_rise_num	        (31)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_FALL_NUM_pen_phtcr_fall_num	        (20)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_NUM_pen_vcr_num					        (27)

	// INT Timing
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH0_RISE_NUM_pen_phth0_rise_num            (24)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH0_FALL_NUM_pen_phth0_fall_num            (12)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH1_RISE_NUM_pen_phth1_rise_num            (12)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH1_FALL_NUM_pen_phth1_fall_num            (24)

	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTI_FALL_NUM1_pen_rsti_fall_num1            (36)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTI_RISE_NUM_pen_rsti_rise_num              (10)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTI_FALL_NUM2_pen_rsti_fall_num2            (36)

	// SHA Timing
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_RISE_PHT_NUM_pen_pht_rise_num                (20)
	#define PARAMSET_ROIC_HOPPFRQ_CFGR_FALL_PHT_NUM_pen_pht_fall_num                (14)
#endif /* USED_PEN_MODE_OPERATION */


/*
 * ADC Clock Control
 */
#define PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_in					        (1)
#define PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_op_opt                        (0)

// Common
#define PARAMSET_ROIC_CFGR_ADC_CTL2_adc_clk_opt                         (2)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_adc_clk_pol                         (0)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_adc_clk_spt                         (0)

// Finger ADC
#define PARAMSET_ROIC_CFGR_ADC_CTL3_fig_adc_stc_dly                     (10)
#define PARAMSET_ROIC_CFGR_ADC_CTL3_fig_adc_sgap_num                    (4)
#define PARAMSET_ROIC_CFGR_ADC_CTL3_fig_adc_stc_prd                     (1)
#define PARAMSET_ROIC_CFGR_ADC_CTL3_fig_adc_pgap_num                    (4)

#define PARAMSET_ROIC_CFGR_ADC_CTL5_fig_adc_in_pos                      (2)
#define PARAMSET_ROIC_CFGR_ADC_CTL5_fig_adc_clk_num                     (7)
#define PARAMSET_ROIC_CFGR_ADC_CTL1_fig_conv_smpl_num                   (3)//(8)//(4)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_fig_adc_clk_prd                     (1)//(1)

// Pen ADC
#define PARAMSET_ROIC_CFGR_ADC_CTL4_pen_adc_stc_dly                     (10)
#define PARAMSET_ROIC_CFGR_ADC_CTL4_pen_adc_sgap_num                    (4)
#define PARAMSET_ROIC_CFGR_ADC_CTL4_pen_adc_stc_prd                     (1)
#define PARAMSET_ROIC_CFGR_ADC_CTL4_pen_adc_pgap_num                    (4)

// Pen Pos
#define PARAMSET_ROIC_CFGR_ADC_CTL5_pp_adc_in_pos                       (2)
#define PARAMSET_ROIC_CFGR_ADC_CTL5_pp_adc_clk_num                      (7)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_pp_adc_clk_prd                      (0)
#define PARAMSET_ROIC_CFGR_ADC_CTL1_pp_conv_smpl_num                    (8)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_pp_mux1_adc_done_skip               (0)

// Pen Tilt
#define PARAMSET_ROIC_CFGR_ADC_CTL5_tilt_adc_in_pos                     (2)
#define PARAMSET_ROIC_CFGR_ADC_CTL5_tilt_adc_clk_num                    (7)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_tilt_adc_clk_prd                    (0)
#define PARAMSET_ROIC_CFGR_ADC_CTL1_tilt_conv_smpl_num                  (8)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_tilt_mux1_adc_done_skip             (0)

// Pen Data
#define PARAMSET_ROIC_CFGR_ADC_CTL5_pd_adc_in_pos                       (2)
#define PARAMSET_ROIC_CFGR_ADC_CTL5_pd_adc_clk_num                      (7)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_pd_adc_clk_prd                      (0)
#define PARAMSET_ROIC_CFGR_ADC_CTL1_pd_conv_smpl_num                    (8)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_pd_mux1_adc_done_skip               (0)

// Pen Pre-Drv


/*
 * PDRV ADC Control
 */

#define PARAMSET_ROIC_CFGR_ADC_CTL6_pdrv_adc_stc_dly                    (31)
#define PARAMSET_ROIC_CFGR_ADC_CTL6_pdrv_adc_sgap_num                   (2)
#define PARAMSET_ROIC_CFGR_ADC_CTL6_pdrv_adc_stc_prd                    (0)
#define PARAMSET_ROIC_CFGR_ADC_CTL6_pdrv_adc_pgap_num                   (1)
#define PARAMSET_ROIC_CFGR_ADC_CTL6_pdrv_adc_clk_num                    (7)

#define PARAMSET_ROIC_CFGR_ADC_CTL2_pdrv_adc_clk_prd                    (0)
#define PARAMSET_ROIC_CFGR_ADC_CTL1_pdrv_conv_smpl_num                  (0)
#define PARAMSET_ROIC_CFGR_ADC_CTL2_phd_adc_done_skip                   (1)


/*
 * Mux Setting in LHB
 */
#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_fig_lhb_mux_num			        (1) // (N+1)
#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_pos_lhb_mux_num		        (1) // (N+1)
#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_tilt_lhb_mux_num		    (1) // (N+1)
#ifdef USED_TOUCH_WGP_PREDRV_MUX_SENSING
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_lhb_mux_num		    (7) // (N+1)
#else
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_lhb_mux_num		    (6) // (N+1)
#endif

#ifdef USED_TOUCH_WGP_PREDRV_MUX_SENSING
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_tmuxnum1            (7)
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_tmuxnum2            (7)
#else
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_tmuxnum1            (6)
	#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_tmuxnum2            (6)
#endif
#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_tsync_muxnum1           (0)
#define PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_tsync_muxnum2           (0)

#if USED_IDLE_FINGER_EVEN_ODD
	#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_CTL1_fig_lhb_mux_num			(1) // (N+1)
#else /* USED_IDLE_FINGER_EVEN_ODD */
	#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_CTL1_fig_lhb_mux_num			(0) // (N+1)
#endif /* USED_IDLE_FINGER_EVEN_ODD */
#define PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_CTL1_pen_pos_lhb_mux_num		(1) // (N+1)


/*
 * Power / Bcon Control
 */

#define PARAMSET_ROIC_AFE_SENSE_CTL1_fig_cvc1_comp                      (0)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pen_cvc1_comp                      (0)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pdrv_cvc1_comp                     (0)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_fig_int_ref                        (4)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pen_int_ref                        (4)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_fig_sha_ref                        (4)
#define PARAMSET_ROIC_AFE_SENSE_CTL1_pen_sha_ref                        (4)

#define PARAMSET_ROIC_AFE_SENSE_CTL2_fig_cvc1_gc                        (2)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_fig_cvc2_gc                        (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_fig_int_gc                         (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_fig_int_half                       (1)

// Contact
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pp_cvc1_gc_con                     (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pd_cvc1_gc_con                     (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_tilt_cvc1_gc_con                   (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_cvc1_gc_con                   (3)

#define PARAMSET_ROIC_AFE_SENSE_CTL3_pp_cvc2_gc_con                     (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_pd_cvc2_gc_con                     (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_tilt_cvc2_gc_con                   (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_pdrv_cvc2_gc_con                   (3)

#define PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_gc_con                      (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_gc_con                      (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_gc_con                    (3)

#define PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_half_con                    (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_half_con                    (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_half_con                  (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_pdrv_int_half_con                  (1)
// Hover
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pp_cvc1_gc_hov                     (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pd_cvc1_gc_hov                     (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_tilt_cvc1_gc_hov                   (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_cvc1_gc_hov                   (3)

#define PARAMSET_ROIC_AFE_SENSE_CTL3_pp_cvc2_gc_hov                     (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_pd_cvc2_gc_hov                     (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_tilt_cvc2_gc_hov                   (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL3_pdrv_cvc2_gc_hov                   (3)


#define PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_gc_hov                      (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_gc_hov                      (3)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_gc_hov                    (3)

#define PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_half_hov                    (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_half_hov                    (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_half_hov                  (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL4_pdrv_int_half_hov                  (1)


// BCON

#define PARAMSET_ROIC_AFE_SENSE_CTL5_fig_hv_ssu_bcon_cvc1               (2)
#define PARAMSET_ROIC_AFE_SENSE_CTL5_pen_hv_ssu_bcon_cvc1               (2)
#define PARAMSET_ROIC_AFE_SENSE_CTL5_pdrv_hv_ssu_bcon_cvc1              (2)

#define PARAMSET_ROIC_AFE_SENSE_CTL5_fig_hv_ssu_bcon_cvc2               (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL5_pen_hv_ssu_bcon_cvc2               (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL5_pdrv_hv_ssu_bcon_cvc2              (1)

#define PARAMSET_ROIC_AFE_SENSE_CTL5_fig_lv_ssu_bcon                    (1)
#define PARAMSET_ROIC_AFE_SENSE_CTL5_pen_lv_ssu_bcon                    (1)

#define PARAMSET_ROIC_AFE_SENSE_CTL5_fig_lv_ssu_bcons                   (2)
#define PARAMSET_ROIC_AFE_SENSE_CTL5_pp_lv_ssu_bcons                    (2)
#define PARAMSET_ROIC_AFE_SENSE_CTL5_tilt_lv_ssu_bcons                  (2)
#define PARAMSET_ROIC_AFE_SENSE_CTL5_pd_lv_ssu_bcons                    (2)

#define PARAMSET_ROIC_AFE_SENSE_CTL5_lv_ssu_bconp                       (2)
#define PARAMSET_ROIC_AFE_SENSE_CTL5_lv_ssu_bconp_buf                   (0)
#define PARAMSET_ROIC_AFE_SENSE_CTL5_ref_bcon                           (0)


/*
 * ADC Control Control
 */

#define PARAMSET_ROIC_ADD_INT_CTL_adc_in                                (1)
#define PARAMSET_ROIC_ADD_INT_CTL_adc_op_opt                            (0)  // 1: ADC_IN inversion

#define PARAMSET_ROIC_ADC_SENSE_CTL1_fig_lv_adc_ref_bcon                (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL1_pp_lv_adc_ref_bcon                 (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL1_tilt_lv_adc_ref_bcon               (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL1_pd_lv_adc_ref_bcon                 (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL1_pdrv_lv_adc_ref_bcon               (1)

#define PARAMSET_ROIC_ADC_SENSE_CTL1_fig_lv_adc_bcon                    (3)//(7)//(3)
#define PARAMSET_ROIC_ADC_SENSE_CTL1_pp_lv_adc_bcon                     (7)
#define PARAMSET_ROIC_ADC_SENSE_CTL1_tilt_lv_adc_bcon                   (7)
#define PARAMSET_ROIC_ADC_SENSE_CTL1_pd_lv_adc_bcon                     (7)
#define PARAMSET_ROIC_ADC_SENSE_CTL1_pdrv_lv_adc_bcon                   (7)

#define PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_comp_bias_ctl              (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_comp_bias_ctl               (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_tilt_adc_comp_bias_ctl             (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_comp_bias_ctl               (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_comp_bias_ctl             (0)

#define PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_mdac_comp_ctl              (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_mdac_comp_ctl               (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_tilt_adc_mdac_comp_ctl             (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_mdac_comp_ctl               (1)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_mdac_comp_ctl             (1)

#define PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_mdac_slew_ctl              (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_mdac_slew_ctl               (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_mdac_slew_ctl               (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_tilt_adc_mdac_slew_ctl             (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_mdac_slew_ctl             (0)

#define PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_ref_idrv_ctl               (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_ref_idrv_ctl                (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_ref_idrv_ctl                (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_tilt_adc_ref_idrv_ctl              (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_ref_idrv_ctl              (0)

#define PARAMSET_ROIC_ADC_SENSE_CTL2_adc_clk_div_1p5                    (0)
#define PARAMSET_ROIC_ADC_SENSE_CTL_adc_stc_insel                       (0)

/*
 * PDB/AFE Control
 */

#define PARAMSET_ROIC_CH_EN_r0_ch_dum_drv_en                    (0)
#define PARAMSET_ROIC_CH_EN_r0_ch_en_hvc                        (0xFFFF)
#define PARAMSET_ROIC_CH_EN_r0_ch_en_int                        (0x7FF)

#define PARAMSET_ROIC_CH_EN_r1_ch_dum_drv_en                    (0x10)//(0)
#define PARAMSET_ROIC_CH_EN_r1_ch_en_hvc                        (0x3FFF)//(0xFFFF)
#define PARAMSET_ROIC_CH_EN_r1_ch_en_int                        (0x3FF)//(0x7FF)


#define PARAMSET_ROIC_PDB_CTL_pdb_hvbias     					(1)
#define PARAMSET_ROIC_PDB_CTL_pdb_hvc        					(1)
#define PARAMSET_ROIC_PDB_CTL_pdb_lvbias     					(1)
#define PARAMSET_ROIC_PDB_CTL_pdb_int        					(1)
#define PARAMSET_ROIC_PDB_CTL_pdb_sha        					(1)
#define PARAMSET_ROIC_PDB_CTL_pdb_bgr_en     					(1)
#define PARAMSET_ROIC_PDB_CTL_pdb_bias_en    					(1)
#define PARAMSET_ROIC_PDB_CTL_pdb_adc        					(1)

#define PARAMSET_ROIC_PDB_CTL_stuck_hvbias     					(1) // 0: Stuck, 1: mux_op_end		2: start~adc_done	3: Tsyncn
#define PARAMSET_ROIC_PDB_CTL_stuck_hvc        					(1) // 0: Stuck, 1: mux_op_end 		2: start~adc_done	3: Tsyncn
#define PARAMSET_ROIC_PDB_CTL_stuck_lvbias     					(1) // 0: Stuck, 1: start~adc_done	2: Tsyncn
#define PARAMSET_ROIC_PDB_CTL_stuck_int        					(2) // 0: Stuck, 1: int op			2: start~adc_done	3: Tsyncn
#define PARAMSET_ROIC_PDB_CTL_stuck_sha        					(2) // 0: Stuck, 1: sha op     		2: start~adc_done	3: Tsyncn
#define PARAMSET_ROIC_PDB_CTL_stuck_bgr_en     					(0) // 0: Stuck, 1: Tsync      		2: start~adc_done
#define PARAMSET_ROIC_PDB_CTL_stuck_bias_en    					(2) // 0: Stuck, 1: Tsync			2: start~adc_done
#define PARAMSET_ROIC_PDB_CTL_stuck_adc        					(2) // 0: Stuck, 1: adc op     		2: start~adc_done	3: Tsyncn


#define PARAMSET_ROIC_TG_STUCK_stuck_cvc1_drv                   (0)
#define PARAMSET_ROIC_TG_STUCK_stuck_cvc1_drv_d                 (0)
#define PARAMSET_ROIC_TG_STUCK_stuck_rstp                       (0)
#define PARAMSET_ROIC_TG_STUCK_stuck_phtcr                      (0)
#define PARAMSET_ROIC_TG_STUCK_stuck_vcr                        (0)
#define PARAMSET_ROIC_TG_STUCK_stuck_rsti                       (0)
#define PARAMSET_ROIC_TG_STUCK_stuck_phth0                      (0)
#define PARAMSET_ROIC_TG_STUCK_stuck_phth1                      (0)
#define PARAMSET_ROIC_TG_STUCK_stuck_pht0                       (0)
#define PARAMSET_ROIC_TG_STUCK_stuck_pht1                       (0)
#define PARAMSET_ROIC_TG_STUCK_fig_vcr_inv_en                   (1)
#define PARAMSET_ROIC_TG_STUCK_pen_vcr_inv_en                   (1)//(0)
#define PARAMSET_ROIC_TG_STUCK_fig_stuck_vcr_en_odd             (1)
#define PARAMSET_ROIC_TG_STUCK_pen_stuck_vcr_en_odd             (1)//(0)
#define PARAMSET_ROIC_TG_STUCK_fig_stuck_vcr_en_even            (1)
#define PARAMSET_ROIC_TG_STUCK_pen_stuck_vcr_en_even            (1)//(0)

#define PARAMSET_ROIC_TEST_MUX_CTL_qcnt_vcom_th_en_pen          (1)//(0)   //ESD_PEN
#define PARAMSET_ROIC_TEST_MUX_CTL_qcnt_vcom_th_en_fig          (0) // 1: VCOM, 2: TH
#define PARAMSET_ROIC_TEST_MUX_CTL_fig_mux_st_num               (1)
#define PARAMSET_ROIC_TEST_MUX_CTL_pen_mux_st_num               (1)

/*
 * VCOMR Control
 */
#define PARAMSET_ROIC_VCOMR_OPT_display_vcomr                   (0)
#define PARAMSET_ROIC_VCOMR_OPT_touch_f_vcomr                   (0)
#define PARAMSET_ROIC_VCOMR_OPT_touch_p_vcomr                   (0)

/*
 * PHD Control - after setup
 */

#define PARAMSET_ROIC_BUF_OPT_r_pre_drv_en                      (0)

#define PARAMSET_ROIC_TEST_CTL_phd_phtcr_vcr_en                 (0)
#define PARAMSET_ROIC_TEST_CTL_phd_phtcr_ctl                    (0)
#define PARAMSET_ROIC_TEST_CTL_phd_vcr_ctl                      (0)

#define PARAMSET_ROIC_PDB_SENSE_CTL1_rst_phd_fall_num           (0)
#define PARAMSET_ROIC_PDB_SENSE_CTL1_phd_all_fall_num           (0)
#define PARAMSET_ROIC_PDB_SENSE_CTL1_adc_in_phd_rise_num        (0)

#define PARAMSET_ROIC_PHD_CTL_edgecnt_th                        (0)
#define PARAMSET_ROIC_PHD_CTL_sel_delay                         (0)
#define PARAMSET_ROIC_PHD_CTL_invalid_dly                       (0)
#define PARAMSET_ROIC_PHD_CTL_pen_mux_dly                       (0)
#define PARAMSET_ROIC_PHD_CTL_offset_val                        (0)
#define PARAMSET_ROIC_PHD_CTL_phd_delay_hold_en                 (0)
#define PARAMSET_ROIC_PHD_CTL_invalid_chk_en                    (1)

#define PARAMSET_ROIC_PDB_PHD_CTL_pdrv_mode                     (0)
#define PARAMSET_ROIC_PDB_PHD_CTL_phd_en_op_num                 (75)
#define PARAMSET_ROIC_PDB_PHD_CTL_phd_md_op_num                 (75)
#define PARAMSET_ROIC_PDB_PHD_CTL_pdb_phd_sha_off_sel           (0)

#define PARAMSET_ROIC_PDB_CTL_pdb_phd                           (0)
#define PARAMSET_ROIC_PDB_CTL_pdb_phd_buf                       (0)
#define PARAMSET_ROIC_PDB_CTL_stuck_phd                         (0)
#define PARAMSET_ROIC_PDB_CTL_stuck_phd_buf                     (0)

#define PARAMSET_ROIC_PHD_SENSE_CTL1_phd_in_s                   (1)
#define PARAMSET_ROIC_PHD_SENSE_CTL1_phd_en                     (0)
#define PARAMSET_ROIC_PHD_SENSE_CTL1_rst_phd_en                 (0)
#define PARAMSET_ROIC_PHD_SENSE_CTL1_phd_gc_con                 (2)
#define PARAMSET_ROIC_PHD_SENSE_CTL1_phd_gc_hov                 (2)
#define PARAMSET_ROIC_PHD_SENSE_CTL1_phd_md                     (0)
#define PARAMSET_ROIC_PHD_SENSE_CTL1_adc_in_phd                 (0)
#define PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_rst_phd              (0)
#define PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_adc_in_phd           (0)
#define PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_phd_md               (0)
#define PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_phd_en               (0)
#define PARAMSET_ROIC_PHD_SENSE_CTL1_max_phd_dly_sel            (0)

#define PARAMSET_ROIC_PHD_CTL1_r0_adc_skipnum_hov               (0)
#define PARAMSET_ROIC_PHD_CTL1_r0_adc_th_hov                    (0)
#define PARAMSET_ROIC_PHD_CTL1_r0_bypass_en_hov                 (0)
#define PARAMSET_ROIC_PHD_CTL1_r0_coef_val1_hov                 (0)
#define PARAMSET_ROIC_PHD_CTL1_r0_coef_val2_hov                 (0)

#define PARAMSET_ROIC_PHD_CTL2_r0_dly_th_hov                    (0)
#define PARAMSET_ROIC_PHD_CTL2_r0_offset_dly_hov                (0)
#define PARAMSET_ROIC_PHD_CTL2_r0_invalid_dly_hov               (0)
#define PARAMSET_ROIC_PHD_CTL2_r0_max_phd_dly_hov               (0)

#define PARAMSET_ROIC_PHD_CTL3_r0_adc_skipnum_con               (0)
#define PARAMSET_ROIC_PHD_CTL3_r0_adc_th_con                    (0)
#define PARAMSET_ROIC_PHD_CTL3_r0_bypass_en_con                 (0)
#define PARAMSET_ROIC_PHD_CTL3_r0_coef_val1_con                 (0)
#define PARAMSET_ROIC_PHD_CTL3_r0_coef_val2_con                 (0)

#define PARAMSET_ROIC_PHD_CTL4_r0_dly_th_con                    (0)
#define PARAMSET_ROIC_PHD_CTL4_r0_offset_dly_con                (0)
#define PARAMSET_ROIC_PHD_CTL4_r0_invalid_dly_con               (0)
#define PARAMSET_ROIC_PHD_CTL4_r0_max_phd_dly_con               (0)

#define PARAMSET_ROIC_PHD_CTL1_r1_adc_skipnum_hov               (0)
#define PARAMSET_ROIC_PHD_CTL1_r1_adc_th_hov                    (0)
#define PARAMSET_ROIC_PHD_CTL1_r1_bypass_en_hov                 (0)
#define PARAMSET_ROIC_PHD_CTL1_r1_coef_val1_hov                 (0)
#define PARAMSET_ROIC_PHD_CTL1_r1_coef_val2_hov                 (0)

#define PARAMSET_ROIC_PHD_CTL2_r1_dly_th_hov                    (0)
#define PARAMSET_ROIC_PHD_CTL2_r1_offset_dly_hov                (0)
#define PARAMSET_ROIC_PHD_CTL2_r1_invalid_dly_hov               (0)
#define PARAMSET_ROIC_PHD_CTL2_r1_max_phd_dly_hov               (0)

#define PARAMSET_ROIC_PHD_CTL3_r1_adc_skipnum_con               (0)
#define PARAMSET_ROIC_PHD_CTL3_r1_adc_th_con                    (0)
#define PARAMSET_ROIC_PHD_CTL3_r1_bypass_en_con                 (0)
#define PARAMSET_ROIC_PHD_CTL3_r1_coef_val1_con                 (0)
#define PARAMSET_ROIC_PHD_CTL3_r1_coef_val2_con                 (0)

#define PARAMSET_ROIC_PHD_CTL4_r1_dly_th_con                    (0)
#define PARAMSET_ROIC_PHD_CTL4_r1_offset_dly_con                (0)
#define PARAMSET_ROIC_PHD_CTL4_r1_invalid_dly_con               (0)
#define PARAMSET_ROIC_PHD_CTL4_r1_max_phd_dly_con               (0)

#include "param_configset_roic_cr_tune.h"


#endif /* _PARAM_CONFIGSET_ROIC_H_ */
