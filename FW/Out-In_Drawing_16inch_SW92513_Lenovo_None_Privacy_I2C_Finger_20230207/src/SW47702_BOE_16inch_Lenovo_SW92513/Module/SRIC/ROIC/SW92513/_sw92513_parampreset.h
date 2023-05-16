/******************************************************************************************************
 * Copyright (c) 2017 - 2025 LXSemicon LIMITED
 *
 * file : _sw92513_parampreset.h
 * created on : 23. 09. 2021
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


#ifndef __SW92513_PARAMETERSET_H_
#define __SW92513_PARAMETERSET_H_


#if (USED_ROIC_DEF == ROIC_SW92513)
#define SRIC_WGPPEN_Conf_Set \
	 .SPIS_CFG = \
	 { \
	  .tBit.chksum_opt = PARAMSET_ROIC_SPIS_CFG_chksum_opt, \
	  .tBit.spis_irq_en = PARAMSET_ROIC_SPIS_CFG_spis_irq_en, \
	  .tBit.spis_irq_dly_num = 0, \
	  .tBit.tg_buf_pnt_clr_en = 1, /* buf pnt clr at TSync Rising Edge!! */\
	 }, \
	 .SPIS_ERROR_CLR = \
	 { \
	  .tBit.spi_chksum_clr = 0, \
	  .tBit.tsync_fault_clr = 0, \
	  .tBit.pwm_fault_clr = 0, \
	  .tBit.buf_pnt_clr = 0, \
	 }, \
	 .SPIS_PAD_CTL = \
	 { \
	  .tBit.miso_ds = 0, \
	  .tBit.miso_dout = 0, \
	  .tBit.miso_func = 0, \
	  .tBit.mosi_ds = 0, \
	  .tBit.mosi_dout = 0, \
	  .tBit.mosi_func = 0, \
	  .tBit.tattn_r0_out = 0, \
	  .tBit.tattn_r0_oe = 0, \
	  .tBit.tattn_r0_ds = 0, \
	  .tBit.tattn_r0_func = 0, \
	  .tBit.tattn_r0_sel0 = 0, \
	  .tBit.tattn_r0_sel1 = 0, \
	  .tBit.tattn_r0_func2 = 0, \
	  .tBit.tattn_r0_test = 0, \
	  .tBit.tattn_r1_out = 0, \
	  .tBit.tattn_r1_oe = 0, \
	  .tBit.tattn_r1_ds = 0, \
	  .tBit.tattn_r1_func = 0, \
	  .tBit.tattn_r1_sel0 = 0, \
	  .tBit.tattn_r1_sel1 = 0, \
	  .tBit.tattn_r1_func2 = 0, \
	  .tBit.tattn_r1_test = 0, \
	 }, \
	 .SYS_CFG = \
	 { \
	  .tBit.tg_reset = 0, \
	  .tBit.sw_reset = 0, \
	  .tBit.tg_clk_all_on = PARAMSET_ROIC_CFGR_SYS_CFG_tg_clk_all_on, \
	  .tBit.cfclk_on = PARAMSET_ROIC_CFGR_SYS_CFG_cfclk_on, \
	  .tBit.apen_clk_on = PARAMSET_ROIC_CFGR_SYS_CFG_cfclk_on, \
	 }, \
	 .TC_START = \
	 { \
	  .tBit.tc_start = 0, \
	 }, \
	 .CH_MUX_NUM = \
	 { \
	  .tBit.fig_ch_num = PARAMSET_ROIC_CFGR_CH_NUM_fig_ch_num, \
	  .tBit.pen_ch_num = PARAMSET_ROIC_CFGR_CH_NUM_pen_ch_num, \
	  .tBit.pdrv_ch_num = PARAMSET_ROIC_CFGR_CH_NUM_pdrv_ch_num, \
	  .tBit.tot_mux_num = PARAMSET_ROIC_CFGR_CH_NUM_tot_mux_num, \
	 }, \
	 .MUX_DLY_0 = \
	 { \
	  .tBit.mux_1_dly = PARAMSET_ROIC_CFGR_MUX_DLY0_mux_1_dly, \
	  .tBit.mux_2_dly = PARAMSET_ROIC_CFGR_MUX_DLY0_mux_2_dly, \
	  .tBit.mux_3_dly = PARAMSET_ROIC_CFGR_MUX_DLY0_mux_3_dly, \
	  .tBit.mux_4_dly = PARAMSET_ROIC_CFGR_MUX_DLY0_mux_4_dly, \
	  .tBit.mux_5_dly = PARAMSET_ROIC_CFGR_MUX_DLY0_mux_5_dly, \
	 }, \
	 .MUX_DLY_1 = \
	 { \
	  .tBit.mux_6_dly = PARAMSET_ROIC_CFGR_MUX_DLY1_mux_6_dly, \
	  .tBit.mux_7_dly = PARAMSET_ROIC_CFGR_MUX_DLY1_mux_7_dly, \
	  .tBit.mux_8_dly = PARAMSET_ROIC_CFGR_MUX_DLY1_mux_8_dly, \
	  .tBit.mux_9_dly = PARAMSET_ROIC_CFGR_MUX_DLY1_mux_9_dly, \
	  .tBit.mux_10_dly = PARAMSET_ROIC_CFGR_MUX_DLY1_mux_10_dly, \
	 }, \
	 .SDIC_CFG = \
	 { \
	  [0] = { \
	  .tBit.vsync_pol = 0, \
	  .tBit.vsync_tg_en = PARAMSET_ROIC_CFGR_SDIC_CFG_vsync_tg_en, \
	  .tBit.vsync_tg_act = 0, \
	  .tBit.tsync_r0_r1_sel = PARAMSET_ROIC_0_CFGR_SDIC_CFG_tsync_r0_r1_sel, \
	  .tBit.tsync_in_pol = 0, \
	  .tBit.tsync_out_pol = 0, \
	  .tBit.tsync_out_bypass = 1, \
	  .tBit.tsync_out_stuck = 0, \
	  .tBit.tsync_out_level = 0, \
	  .tBit.pwm_r0_r1_sel = PARAMSET_ROIC_0_CFGR_SDIC_CFG_pwm_r0_r1_sel, \
	  .tBit.pwm_pol = 0, \
	  .tBit.sd_rocen = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_rocen, \
	  .tBit.sd_off_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_off_ctl, \
	  .tBit.sd_float0_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_float0_ctl, \
	  .tBit.sd_float1_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_float1_ctl, \
	  .tBit.sd_gnd0_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_gnd0_ctl, \
	  .tBit.sd_gnd1_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_gnd1_ctl, \
	  }, \
	  [1] = { \
	  .tBit.vsync_pol = 0, \
	  .tBit.vsync_tg_en = PARAMSET_ROIC_CFGR_SDIC_CFG_vsync_tg_en, \
	  .tBit.vsync_tg_act = 0, \
	  .tBit.tsync_r0_r1_sel = PARAMSET_ROIC_1_CFGR_SDIC_CFG_tsync_r0_r1_sel, \
	  .tBit.tsync_in_pol = 0, \
	  .tBit.tsync_out_pol = 0, \
	  .tBit.tsync_out_bypass = 1, \
	  .tBit.tsync_out_stuck = 0, \
	  .tBit.tsync_out_level = 0, \
	  .tBit.pwm_r0_r1_sel = PARAMSET_ROIC_1_CFGR_SDIC_CFG_pwm_r0_r1_sel, \
	  .tBit.pwm_pol = 0, \
	  .tBit.sd_rocen = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_rocen, \
	  .tBit.sd_off_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_off_ctl, \
	  .tBit.sd_float0_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_float0_ctl, \
	  .tBit.sd_float1_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_float1_ctl, \
	  .tBit.sd_gnd0_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_gnd0_ctl, \
	  .tBit.sd_gnd1_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_gnd1_ctl, \
	  }, \
	  [2] = { \
	  .tBit.vsync_pol = 0, \
	  .tBit.vsync_tg_en = PARAMSET_ROIC_CFGR_SDIC_CFG_vsync_tg_en, \
	  .tBit.vsync_tg_act = 0, \
	  .tBit.tsync_r0_r1_sel = PARAMSET_ROIC_2_CFGR_SDIC_CFG_tsync_r0_r1_sel, \
	  .tBit.tsync_in_pol = 0, \
	  .tBit.tsync_out_pol = 0, \
	  .tBit.tsync_out_bypass = 1, \
	  .tBit.tsync_out_stuck = 0, \
	  .tBit.tsync_out_level = 0, \
	  .tBit.pwm_r0_r1_sel = PARAMSET_ROIC_2_CFGR_SDIC_CFG_pwm_r0_r1_sel, \
	  .tBit.pwm_pol = 0, \
	  .tBit.sd_rocen = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_rocen, \
	  .tBit.sd_off_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_off_ctl, \
	  .tBit.sd_float0_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_float0_ctl, \
	  .tBit.sd_float1_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_float1_ctl, \
	  .tBit.sd_gnd0_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_gnd0_ctl, \
	  .tBit.sd_gnd1_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_gnd1_ctl, \
	  }, \
	  [3] = { \
	  .tBit.vsync_pol = 0, \
	  .tBit.vsync_tg_en = PARAMSET_ROIC_CFGR_SDIC_CFG_vsync_tg_en, \
	  .tBit.vsync_tg_act = 0, \
	  .tBit.tsync_r0_r1_sel = PARAMSET_ROIC_3_CFGR_SDIC_CFG_tsync_r0_r1_sel, \
	  .tBit.tsync_in_pol = 0, \
	  .tBit.tsync_out_pol = 0, \
	  .tBit.tsync_out_bypass = 1, \
	  .tBit.tsync_out_stuck = 0, \
	  .tBit.tsync_out_level = 0, \
	  .tBit.pwm_r0_r1_sel = PARAMSET_ROIC_3_CFGR_SDIC_CFG_pwm_r0_r1_sel, \
	  .tBit.pwm_pol = 0, \
	  .tBit.sd_rocen = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_rocen, \
	  .tBit.sd_off_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_off_ctl, \
	  .tBit.sd_float0_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_float0_ctl, \
	  .tBit.sd_float1_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_float1_ctl, \
	  .tBit.sd_gnd0_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_gnd0_ctl, \
	  .tBit.sd_gnd1_ctl = PARAMSET_ROIC_CFGR_SDIC_CFG_sd_gnd1_ctl, \
	  }, \
	 }, \
	 .PWM_FIG_CTL = \
	 { \
	  .tBit.pwm_fig_act_num = PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_act_num, \
	  .tBit.pwm_fig_mgap_num = PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_mgap_num, \
	  .tBit.pwm_fig_dum_num = PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num + PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_set_num, \
	 }, \
	 .PWM_POS_CTL = \
	 { \
	  .tBit.pwm_pos_pdrv_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_pdrv_num, \
	  .tBit.pwm_pos_mux1_act_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_act_num, \
	  .tBit.pwm_pos_act_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_act_num, \
	  .tBit.pwm_pos_mgap_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_mgap_num, \
	  .tBit.pwm_pos_dum_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_dum_num + PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_set_num, \
	 }, \
	 .PWM_DAT_CTL = \
	 { \
	  .tBit.pwm_dat_pdrv_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_pdrv_num, \
	  .tBit.pwm_dat_mux1_act_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_mux1_act_num, \
	  .tBit.pwm_dat_mux2_act_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_mux2_act_num, \
	  .tBit.pwm_dat_act_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_act_num, \
	  .tBit.pwm_dat_mgap_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_mgap_num, \
	  .tBit.pwm_dat_dum_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_dum_num + PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_set_num, \
	 }, \
	 .PWM_TILT_CTL = \
	 { \
	  .tBit.pwm_tilt_pdrv_num = PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_pdrv_num, \
	  .tBit.pwm_tilt_mux1_act_num = PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_mux1_act_num, \
	  .tBit.pwm_tilt_act_num = PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_act_num, \
	  .tBit.pwm_tilt_mgap_num = PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_mgap_num, \
	  .tBit.pwm_tilt_dum_num = PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_dum_num + PARAMSET_ROIC_CFGR_PWM_TILT_CTL_pwm_set_num, \
	 }, \
	 .PWM_ND_CTL = \
	 { \
	  .tBit.pwm_nd_pdrv_num = 0, \
	  .tBit.pwm_nd_act_num = 6, \
	  .tBit.pwm_nd_mgap_num = 1, \
	  .tBit.pwm_nd_dum_num = 7, \
	 }, \
	 .PWM_PRD_CTL = \
	 { \
	  .tBit.fig_pwm_prd = PARAMSET_ROIC_CFGR_PWM_PRD_fig_pwm_prd, \
	  .tBit.pen_pwm_prd = PARAMSET_ROIC_CFGR_PWM_PRD_pen_pwm_prd, \
	  .tBit.nd_pwm_prd = 46, \
	  .tBit.nd_pwm_prd_margin = 0, \
	 }, \
	 .CVC1_DRV_CTL1 = \
	 { \
	  .tBit.fig_tg_cvc1_drv_en = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_fig_tg_cvc1_drv_en, \
	  .tBit.pen_tg_cvc1_drv_en = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_pen_tg_cvc1_drv_en, \
	  .tBit.nd_tg_cvc1_drv_en = 1, \
	  .tBit.fig_tg_cvc1_drv_d_en = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_fig_tg_cvc1_drv_d_en, \
	  .tBit.pen_tg_cvc1_drv_d_en = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_pen_tg_cvc1_drv_d_en, \
	  .tBit.nd_tg_cvc1_drv_d_en = 1, \
	  .tBit.fig_tg_cvc1_drv_init = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_fig_tg_cvc1_drv_init, \
	  .tBit.pen_tg_cvc1_drv_init = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_pen_tg_cvc1_drv_init, \
	  .tBit.nd_tg_cvc1_drv_init = 1, \
	  .tBit.fig_tg_cvc1_drv_d_init = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_fig_tg_cvc1_drv_d_init, \
	  .tBit.pen_tg_cvc1_drv_d_init = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_pen_tg_cvc1_drv_d_init, \
	  .tBit.nd_tg_cvc1_drv_d_init = 1, \
	  .tBit.fig_tg_cvc1_rstp_en = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_fig_tg_cvc1_rstp_en, \
	  .tBit.pen_tg_cvc1_rstp_en = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_pen_tg_cvc1_rstp_en, \
	  .tBit.nd_tg_cvc1_rstp_en = 1, \
	  .tBit.tg_cvc1_rstp_dum_en = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL1_tg_cvc1_rstp_dum_en, \
	 }, \
	 .CVC1_DRV_CTL2 = \
	 { \
	  .tBit.fig_cvc1_drv_rstp_dly = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL2_fig_cvc1_drv_rstp_dly, \
	  .tBit.pen_cvc1_drv_rstp_dly = PARAMSET_ROIC_CFGR_CVC1_DRV_CTL2_pen_cvc1_drv_rstp_dly, \
	  .tBit.nd_cvc1_drv_rstp_dly = 15, \
	 }, \
	 .CVC1_DRV_RISE_NUM = \
	 { \
	  .tBit.fig_cvc1_drv_rise_num = PARAMSET_ROIC_CFGR_CVC1_DRV_fig_cvc1_drv_rise_num, \
	  .tBit.pen_cvc1_drv_rise_num = PARAMSET_ROIC_CFGR_CVC1_DRV_pen_cvc1_drv_rise_num, \
	  .tBit.nd_cvc1_drv_rise_num = 25, \
	 }, \
	 .CVC1_DRV_FALL_NUM = \
	 { \
	  .tBit.fig_cvc1_drv_fall_num = PARAMSET_ROIC_CFGR_CVC1_DRV_fig_cvc1_drv_fall_num, \
	  .tBit.pen_cvc1_drv_fall_num = PARAMSET_ROIC_CFGR_CVC1_DRV_pen_cvc1_drv_fall_num, \
	  .tBit.nd_cvc1_drv_fall_num = 38, \
	 }, \
	 .CVC1_DRV_D_RISE_NUM = \
	 { \
	  .tBit.fig_cvc1_drv_d_rise_num = PARAMSET_ROIC_CFGR_CVC1_DRV_D_fig_cvc1_drv_d_rise_num, \
	  .tBit.pen_cvc1_drv_d_rise_num = PARAMSET_ROIC_CFGR_CVC1_DRV_D_pen_cvc1_drv_d_rise_num, \
	  .tBit.nd_cvc1_drv_d_rise_num = 23, \
	 }, \
	 .CVC1_DRV_D_FALL_NUM = \
	 { \
	  .tBit.fig_cvc1_drv_d_fall_num = PARAMSET_ROIC_CFGR_CVC1_DRV_D_fig_cvc1_drv_d_fall_num, \
	  .tBit.pen_cvc1_drv_d_fall_num = PARAMSET_ROIC_CFGR_CVC1_DRV_D_pen_cvc1_drv_d_fall_num, \
	  .tBit.nd_cvc1_drv_d_fall_num = 38, \
	 }, \
	 .SMPL_CTL = \
	 { \
	  .tBit.fig_smop_prd = PARAMSET_ROIC_CFGR_SMPL_CTL_fig_smop_prd, \
	  .tBit.pen_smop_prd = PARAMSET_ROIC_CFGR_SMPL_CTL_pen_smop_prd, \
	  .tBit.nd_smop_prd = 3, \
	  .tBit.fig_cr_repeat_num = PARAMSET_ROIC_CFGR_SMPL_CTL_fig_cr_repeat_num, \
	  .tBit.pen_cr_repeat_num = PARAMSET_ROIC_CFGR_SMPL_CTL_pen_cr_repeat_num, \
	  .tBit.nd_cr_repeat_num = 0, \
	 }, \
	 .RSTP_RISE_NUM = \
	 { \
	  .tBit.fig_rstp_rise_num = PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_fig_rstp_rise_num, \
	  .tBit.pen_rstp_rise_num = PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_pen_rstp_rise_num, \
	  .tBit.nd_rstp_rise_num = 40, \
	 }, \
	 .RSTP_FALL_NUM1 = \
	 { \
	  .tBit.fig_rstp_fall_num1 = PARAMSET_ROIC_CFGR_RSTP_FALL_NUM1_fig_rstp_fall_num1, \
	  .tBit.pen_rstp_fall_num1 = PARAMSET_ROIC_CFGR_RSTP_FALL_NUM1_pen_rstp_fall_num1, \
	  .tBit.nd_rstp_fall_num1 = 30, \
	 }, \
	 .RSTP_FALL_NUM2 = \
	 { \
	  .tBit.fig_rstp_fall_num2 = PARAMSET_ROIC_CFGR_RSTP_FALL_NUM2_fig_rstp_fall_num2, \
	  .tBit.pen_rstp_fall_num2 = PARAMSET_ROIC_CFGR_RSTP_FALL_NUM2_pen_rstp_fall_num2, \
	  .tBit.nd_rstp_fall_num2 = 30, \
	 }, \
	 .PHTCR_RISE_NUM = \
	 { \
	  .tBit.fig_phtcr_rise_num = PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_fig_phtcr_rise_num, \
	  .tBit.pen_phtcr_rise_num = PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_pen_phtcr_rise_num, \
	  .tBit.nd_phtcr_rise_num = 40, \
	 }, \
	 .PHTCR_FALL_NUM = \
	 { \
	  .tBit.fig_phtcr_fall_num = PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_fig_phtcr_fall_num, \
	  .tBit.pen_phtcr_fall_num = PARAMSET_ROIC_CFGR_PHTCR_FALL_NUM_pen_phtcr_fall_num, \
	  .tBit.nd_phtcr_fall_num = 30, \
	 }, \
	 .VCR_NUM = \
	 { \
	  .tBit.fig_vcr_num = PARAMSET_ROIC_CFGR_VCR_NUM_fig_vcr_num, \
	  .tBit.pen_vcr_num = PARAMSET_ROIC_CFGR_VCR_NUM_pen_vcr_num, \
	  .tBit.nd_vcr_num = 36, \
	  .tBit.fig_vcr_off_en = PARAMSET_ROIC_CFGR_VCR_NUM_fig_vcr_off_en, \
	  .tBit.fig_phtcr_off_en = PARAMSET_ROIC_CFGR_VCR_NUM_fig_phtcr_off_en, \
	  .tBit.pen_vcr_off_en = PARAMSET_ROIC_CFGR_VCR_NUM_pen_vcr_off_en, \
	  .tBit.pen_phtcr_off_en = PARAMSET_ROIC_CFGR_VCR_NUM_pen_phtcr_off_en, \
	  .tBit.phtcr_dum_en = PARAMSET_ROIC_CFGR_VCR_NUM_phtcr_dum_en, \
	  .tBit.vcr_dum_en = PARAMSET_ROIC_CFGR_VCR_NUM_vcr_dum_en, \
	 }, \
	 .RSTI_RISE_NUM = \
	 { \
	  .tBit.fig_rsti_rise_num = PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_fig_rsti_rise_num, \
	  .tBit.pen_rsti_rise_num = PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_pen_rsti_rise_num, \
	  .tBit.nd_rsti_rise_num = 15, \
	 }, \
	 .RSTI_FALL_NUM1 = \
	 { \
	  .tBit.fig_rsti_fall_num1 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_fig_rsti_fall_num1, \
	  .tBit.pen_rsti_fall_num1 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_pen_rsti_fall_num1, \
	  .tBit.nd_rsti_fall_num1 = 44, \
	 }, \
	 .RSTI_FALL_NUM2 = \
	 { \
	  .tBit.fig_rsti_fall_num2 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_fig_rsti_fall_num2, \
	  .tBit.pen_rsti_fall_num2 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_pen_rsti_fall_num2, \
	  .tBit.nd_rsti_fall_num2 = 26, \
	 }, \
	 .PHTH0_RISE_NUM = \
	 { \
	  .tBit.fig_phth0_rise_num = PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_fig_phth0_rise_num, \
	  .tBit.pen_phth0_rise_num = PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_pen_phth0_rise_num, \
	  .tBit.nd_phth0_rise_num = 25, \
	 }, \
	 .PHTH0_FALL_NUM = \
	 { \
	  .tBit.fig_phth0_fall_num = PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_fig_phth0_fall_num, \
	  .tBit.pen_phth0_fall_num = PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_pen_phth0_fall_num, \
	  .tBit.nd_phth0_fall_num = 17, \
	 }, \
	 .PHTH1_RISE_NUM = \
	 { \
	  .tBit.fig_phth1_rise_num = PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_fig_phth1_rise_num, \
	  .tBit.pen_phth1_rise_num = PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_pen_phth1_rise_num, \
	  .tBit.nd_phth1_rise_num = 10, \
	 }, \
	 .PHTH1_FALL_NUM = \
	 { \
	  .tBit.fig_phth1_fall_num = PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_fig_phth1_fall_num, \
	  .tBit.pen_phth1_fall_num = PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_pen_phth1_fall_num, \
	  .tBit.nd_phth1_fall_num = 30, \
	 }, \
	 .PHT_CTL = \
	 { \
	  .tBit.pht_prd = 6, \
	  .tBit.pht_opt_inv = 1, \
	  .tBit.pht_end_time = 20, \
	  .tBit.pht_act_pwm_num = 0, \
	  .tBit.pht_act_pwr_num = 0, \
	  .tBit.fig_pre_pht_sel = 0, \
	  .tBit.pen_pos_pre_pht_sel = 0, \
	  .tBit.pen_dat_pre_pht_sel = 0, \
	  .tBit.pen_tilt_pre_pht_sel = 0, \
	  .tBit.nd_pre_pht_sel = 0, \
	 }, \
	 .PHT_RISE_NUM = \
	 { \
	  .tBit.fig_pht_rise_num = PARAMSET_ROIC_CFGR_RISE_PHT_NUM_fig_pht_rise_num, \
	  .tBit.pen_pht_rise_num = PARAMSET_ROIC_CFGR_RISE_PHT_NUM_pen_pht_rise_num, \
	  .tBit.nd_pht_rise_num = 24, \
	 }, \
	 .PHT_FALL_NUM = \
	 { \
	  .tBit.fig_pht_fall_num = PARAMSET_ROIC_CFGR_FALL_PHT_NUM_fig_pht_fall_num, \
	  .tBit.pen_pht_fall_num = PARAMSET_ROIC_CFGR_FALL_PHT_NUM_pen_pht_fall_num, \
	  .tBit.nd_pht_fall_num = 28, \
	 }, \
	 .ADC_CTL1 = \
	 { \
	  .tBit.fig_conv_smpl_num = PARAMSET_ROIC_CFGR_ADC_CTL1_fig_conv_smpl_num, \
	  .tBit.pp_conv_smpl_num = PARAMSET_ROIC_CFGR_ADC_CTL1_pp_conv_smpl_num, \
	  .tBit.tilt_conv_smpl_num = PARAMSET_ROIC_CFGR_ADC_CTL1_tilt_conv_smpl_num, \
	  .tBit.pd_conv_smpl_num = PARAMSET_ROIC_CFGR_ADC_CTL1_pd_conv_smpl_num, \
	  .tBit.pdrv_conv_smpl_num = PARAMSET_ROIC_CFGR_ADC_CTL1_pdrv_conv_smpl_num, \
	 }, \
	 .ADC_CTL2 = \
	 { \
	  .tBit.fig_adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTL2_fig_adc_clk_prd, \
	  .tBit.pp_adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTL2_pp_adc_clk_prd, \
	  .tBit.tilt_adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTL2_tilt_adc_clk_prd, \
	  .tBit.pd_adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTL2_pd_adc_clk_prd, \
	  .tBit.pdrv_adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTL2_pdrv_adc_clk_prd, \
	  .tBit.adc_clk_opt = PARAMSET_ROIC_CFGR_ADC_CTL2_adc_clk_opt, \
	  .tBit.adc_clk_pol = PARAMSET_ROIC_CFGR_ADC_CTL2_adc_clk_pol, \
	  .tBit.adc_clk_spt = PARAMSET_ROIC_CFGR_ADC_CTL2_adc_clk_spt, \
	  .tBit.phd_adc_done_skip = PARAMSET_ROIC_CFGR_ADC_CTL2_phd_adc_done_skip, \
	  .tBit.pp_mux1_adc_done_skip = PARAMSET_ROIC_CFGR_ADC_CTL2_pp_mux1_adc_done_skip, \
	  .tBit.pd_mux1_adc_done_skip = PARAMSET_ROIC_CFGR_ADC_CTL2_pd_mux1_adc_done_skip, \
	  .tBit.tilt_mux1_adc_done_skip = PARAMSET_ROIC_CFGR_ADC_CTL2_tilt_mux1_adc_done_skip, \
	 }, \
	 .ADC_CTL3 = \
	 { \
	  .tBit.fig_adc_stc_dly = PARAMSET_ROIC_CFGR_ADC_CTL3_fig_adc_stc_dly, \
	  .tBit.fig_adc_sgap_num = PARAMSET_ROIC_CFGR_ADC_CTL3_fig_adc_sgap_num, \
	  .tBit.fig_adc_stc_prd = PARAMSET_ROIC_CFGR_ADC_CTL3_fig_adc_stc_prd, \
	  .tBit.fig_adc_pgap_num = PARAMSET_ROIC_CFGR_ADC_CTL3_fig_adc_pgap_num, \
	 }, \
	 .ADC_CTL4 = \
	 { \
	  .tBit.pen_adc_stc_dly = PARAMSET_ROIC_CFGR_ADC_CTL4_pen_adc_stc_dly, \
	  .tBit.pen_adc_sgap_num = PARAMSET_ROIC_CFGR_ADC_CTL4_pen_adc_sgap_num, \
	  .tBit.pen_adc_stc_prd = PARAMSET_ROIC_CFGR_ADC_CTL4_pen_adc_stc_prd, \
	  .tBit.pen_adc_pgap_num = PARAMSET_ROIC_CFGR_ADC_CTL4_pen_adc_pgap_num, \
	 }, \
	 .ADC_CTL5 = \
	 { \
	  .tBit.fig_adc_in_pos = PARAMSET_ROIC_CFGR_ADC_CTL5_fig_adc_in_pos, \
	  .tBit.pp_adc_in_pos = PARAMSET_ROIC_CFGR_ADC_CTL5_pp_adc_in_pos, \
	  .tBit.tilt_adc_in_pos = PARAMSET_ROIC_CFGR_ADC_CTL5_tilt_adc_in_pos, \
	  .tBit.pd_adc_in_pos = PARAMSET_ROIC_CFGR_ADC_CTL5_pd_adc_in_pos, \
	  .tBit.fig_adc_clk_num = PARAMSET_ROIC_CFGR_ADC_CTL5_fig_adc_clk_num, \
	  .tBit.pp_adc_clk_num = PARAMSET_ROIC_CFGR_ADC_CTL5_pp_adc_clk_num, \
	  .tBit.tilt_adc_clk_num = PARAMSET_ROIC_CFGR_ADC_CTL5_tilt_adc_clk_num, \
	  .tBit.pd_adc_clk_num = PARAMSET_ROIC_CFGR_ADC_CTL5_pd_adc_clk_num, \
	 }, \
	 .ADC_CTL6 = \
	 { \
	  .tBit.pdrv_adc_stc_dly = PARAMSET_ROIC_CFGR_ADC_CTL6_pdrv_adc_stc_dly, \
	  .tBit.pdrv_adc_sgap_num = PARAMSET_ROIC_CFGR_ADC_CTL6_pdrv_adc_sgap_num, \
	  .tBit.pdrv_adc_stc_prd = PARAMSET_ROIC_CFGR_ADC_CTL6_pdrv_adc_stc_prd, \
	  .tBit.pdrv_adc_pgap_num = PARAMSET_ROIC_CFGR_ADC_CTL6_pdrv_adc_pgap_num, \
	  .tBit.pdrv_adc_clk_num = PARAMSET_ROIC_CFGR_ADC_CTL6_pdrv_adc_clk_num, \
	 }, \
	 .FIG_MUX_CFG_00 = \
	 { \
	  .tBit.fig_mux_00 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00, \
	  .tBit.fig_mux_01 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01, \
	  .tBit.fig_mux_02 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02, \
	  .tBit.fig_mux_03 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03, \
	  .tBit.fig_mux_04 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04, \
	  .tBit.fig_mux_05 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05, \
	  .tBit.fig_mux_06 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06, \
	  .tBit.fig_mux_07 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07, \
	 }, \
	 .FIG_MUX_CFG_01 = \
	 { \
	  .tBit.fig_mux_08 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08, \
	  .tBit.fig_mux_09 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09, \
	  .tBit.fig_mux_10 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_10, \
	  .tBit.fig_mux_11 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_11, \
	  .tBit.fig_mux_12 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_12, \
	  .tBit.fig_mux_13 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_13, \
	  .tBit.fig_mux_14 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_14, \
	  .tBit.fig_mux_15 = PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_15, \
	 }, \
	 .RCOM_LHB_CFG = \
	 { \
	  .tBit.nxt_lhb_mode = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_nxt_lhb_mode, \
	  .tBit.tsync_num = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_tsync_num, \
	  .tBit.dum_tsync_num = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_dum_tsync_num, \
	  .tBit.beacon_en = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_beacon_en, \
	  .tBit.rdcom_en = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_rdcom_en, \
	  .tBit.sgap_num = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_sgap_num, \
	  .tBit.r0pd = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_r0pd, \
	  .tBit.r1pd = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_r1pd, \
	  .tBit.sel_hover = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_sel_hover, \
	  .tBit.fixed_pen_mux_dly_en = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_fixed_pen_mux_dly_en, \
	 }, \
	 .DEFA_LHB_MCFG00 = \
	 { \
		 [PWM_FULL_FINGER_MODE] = \
		 { \
			.tBit.lhb_mode01 = PARAMSET_ROIC_FULL_LHB_1_mode, \
			.tBit.lhb_mode02 = PARAMSET_ROIC_FULL_LHB_2_mode, \
			.tBit.lhb_mode03 = PARAMSET_ROIC_FULL_LHB_3_mode, \
			.tBit.lhb_mode04 = PARAMSET_ROIC_FULL_LHB_4_mode, \
			.tBit.lhb_mode05 = PARAMSET_ROIC_FULL_LHB_5_mode, \
			.tBit.lhb_mode06 = PARAMSET_ROIC_FULL_LHB_6_mode, \
			.tBit.lhb_mode07 = PARAMSET_ROIC_FULL_LHB_7_mode, \
			.tBit.lhb_mode08 = PARAMSET_ROIC_FULL_LHB_8_mode, \
		 }, \
		 [PWM_LOCAL_PEN_MODE] = \
		 { \
			.tBit.lhb_mode01 = PARAMSET_ROIC_LOCAL_LHB_1_mode, \
			.tBit.lhb_mode02 = PARAMSET_ROIC_LOCAL_LHB_2_mode, \
			.tBit.lhb_mode03 = PARAMSET_ROIC_LOCAL_LHB_3_mode, \
			.tBit.lhb_mode04 = PARAMSET_ROIC_LOCAL_LHB_4_mode, \
			.tBit.lhb_mode05 = PARAMSET_ROIC_LOCAL_LHB_5_mode, \
			.tBit.lhb_mode06 = PARAMSET_ROIC_LOCAL_LHB_6_mode, \
			.tBit.lhb_mode07 = PARAMSET_ROIC_LOCAL_LHB_7_mode, \
			.tBit.lhb_mode08 = PARAMSET_ROIC_LOCAL_LHB_8_mode, \
		 }, \
		 [PWM_FULL_FINGER_IDLE_MODE] = \
		 { \
			.tBit.lhb_mode01 = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mode, \
			.tBit.lhb_mode02 = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mode, \
			.tBit.lhb_mode03 = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mode, \
			.tBit.lhb_mode04 = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mode, \
			.tBit.lhb_mode05 = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mode, \
			.tBit.lhb_mode06 = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mode, \
			.tBit.lhb_mode07 = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode, \
			.tBit.lhb_mode08 = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mode, \
		 }, \
	 }, \
	 .DEFA_LHB_MCFG01 = \
	 { \
		[PWM_FULL_FINGER_MODE] = \
		{ \
			.tBit.lhb_mode09 = PARAMSET_ROIC_FULL_LHB_9_mode, \
			.tBit.lhb_mode10 = PARAMSET_ROIC_FULL_LHB_10_mode, \
			.tBit.lhb_mode11 = PARAMSET_ROIC_FULL_LHB_11_mode, \
			.tBit.lhb_mode12 = PARAMSET_ROIC_FULL_LHB_12_mode, \
			.tBit.lhb_mode13 = PARAMSET_ROIC_FULL_LHB_13_mode, \
			.tBit.lhb_mode14 = PARAMSET_ROIC_FULL_LHB_14_mode, \
			.tBit.lhb_mode15 = PARAMSET_ROIC_FULL_LHB_15_mode, \
			.tBit.lhb_mode16 = PARAMSET_ROIC_FULL_LHB_16_mode, \
		}, \
		[PWM_LOCAL_PEN_MODE] = \
		{ \
			.tBit.lhb_mode09 = PARAMSET_ROIC_LOCAL_LHB_9_mode, \
			.tBit.lhb_mode10 = PARAMSET_ROIC_LOCAL_LHB_10_mode, \
			.tBit.lhb_mode11 = PARAMSET_ROIC_LOCAL_LHB_11_mode, \
			.tBit.lhb_mode12 = PARAMSET_ROIC_LOCAL_LHB_12_mode, \
			.tBit.lhb_mode13 = PARAMSET_ROIC_LOCAL_LHB_13_mode, \
			.tBit.lhb_mode14 = PARAMSET_ROIC_LOCAL_LHB_14_mode, \
			.tBit.lhb_mode15 = PARAMSET_ROIC_LOCAL_LHB_15_mode, \
			.tBit.lhb_mode16 = PARAMSET_ROIC_LOCAL_LHB_16_mode, \
		}, \
		[PWM_FULL_FINGER_IDLE_MODE] = \
		{ \
			.tBit.lhb_mode09 = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mode, \
			.tBit.lhb_mode10 = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mode, \
			.tBit.lhb_mode11 = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mode, \
			.tBit.lhb_mode12 = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mode, \
			.tBit.lhb_mode13 = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mode, \
			.tBit.lhb_mode14 = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode, \
			.tBit.lhb_mode15 = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode, \
			.tBit.lhb_mode16 = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode, \
		}, \
	 }, \
	 .DEFA_LHB_MCFG02 = \
	 { \
		[PWM_FULL_FINGER_MODE] = \
		{ \
			.tBit.lhb_mode17 = 6, \
			.tBit.lhb_mode18 = 6, \
			.tBit.lhb_mode19 = 6, \
			.tBit.lhb_mode20 = 6, \
			.tBit.lhb_mode21 = 6, \
			.tBit.lhb_mode22 = 6, \
			.tBit.lhb_mode23 = 6, \
			.tBit.lhb_mode24 = 6, \
		}, \
		[PWM_LOCAL_PEN_MODE] = \
		{ \
			.tBit.lhb_mode17 = 6, \
			.tBit.lhb_mode18 = 6, \
			.tBit.lhb_mode19 = 6, \
			.tBit.lhb_mode20 = 6, \
			.tBit.lhb_mode21 = 6, \
			.tBit.lhb_mode22 = 6, \
			.tBit.lhb_mode23 = 6, \
			.tBit.lhb_mode24 = 6, \
		}, \
		[PWM_FULL_FINGER_IDLE_MODE] = \
		{ \
			.tBit.lhb_mode17 = 6, \
			.tBit.lhb_mode18 = 6, \
			.tBit.lhb_mode19 = 6, \
			.tBit.lhb_mode20 = 6, \
			.tBit.lhb_mode21 = 6, \
			.tBit.lhb_mode22 = 6, \
			.tBit.lhb_mode23 = 6, \
			.tBit.lhb_mode24 = 6, \
		}, \
	 }, \
	 .DEFA_LHB_MCFG03 = \
	 { \
		[PWM_FULL_FINGER_MODE] = \
		{ \
			.tBit.lhb_mode25 = 6, \
			.tBit.lhb_mode26 = 6, \
			.tBit.lhb_mode27 = 6, \
			.tBit.lhb_mode28 = 6, \
			.tBit.lhb_mode29 = 6, \
			.tBit.lhb_mode30 = 6, \
			.tBit.lhb_mode31 = 6, \
			.tBit.lhb_mode32 = 6, \
		}, \
		[PWM_LOCAL_PEN_MODE] = \
		{ \
			.tBit.lhb_mode25 = 6, \
			.tBit.lhb_mode26 = 6, \
			.tBit.lhb_mode27 = 6, \
			.tBit.lhb_mode28 = 6, \
			.tBit.lhb_mode29 = 6, \
			.tBit.lhb_mode30 = 6, \
			.tBit.lhb_mode31 = 6, \
			.tBit.lhb_mode32 = 6, \
		}, \
		[PWM_FULL_FINGER_IDLE_MODE] = \
		{ \
			.tBit.lhb_mode25 = 6, \
			.tBit.lhb_mode26 = 6, \
			.tBit.lhb_mode27 = 6, \
			.tBit.lhb_mode28 = 6, \
			.tBit.lhb_mode29 = 6, \
			.tBit.lhb_mode30 = 6, \
			.tBit.lhb_mode31 = 6, \
			.tBit.lhb_mode32 = 6, \
		}, \
	 }, \
	 .LHB_MUX_CTL1 = \
	 { \
	  .tBit.fig_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_fig_lhb_mux_num, \
	  .tBit.pen_pos_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_pos_lhb_mux_num, \
	  .tBit.pen_dat_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_lhb_mux_num, \
	  .tBit.pen_tilt_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_tilt_lhb_mux_num, \
	  .tBit.pen_dat_tmuxnum1 = PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_tmuxnum1, \
	  .tBit.pen_dat_tsync_muxnum1 = PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_tsync_muxnum1, \
	  .tBit.pen_dat_tmuxnum2 = PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_tmuxnum2, \
	  .tBit.pen_dat_tsync_muxnum2 = PARAMSET_ROIC_CFGR_LHB_MUX_CTL1_pen_dat_tsync_muxnum2, \
	 }, \
	 .PEN_POS1_LHB_CFG = \
	 { \
	  .tBit.pen_pos_mux_cfg0 = 62, \
	  .tBit.pen_pos_mux_cfg1 = 63, \
	  .tBit.pen_pos_mux_cfg2 = 0, \
	  .tBit.pen_pos_mux_cfg3 = 0, \
	  .tBit.pen_pos_mux_dly = 0, \
	 }, \
	 .PEN_DAT1_LHB_CFG = \
	 { \
	  .tBit.pen_dat_mux_cfg0 = 0, \
	  .tBit.pen_dat_mux_cfg1 = 0, \
	  .tBit.pen_dat_mux_cfg2 = 0, \
	  .tBit.pen_dat_mux_cfg3 = 0, \
	  .tBit.pen_dat_mux_dly = 0, \
	  .tBit.pen_dat_mux_sel = 0, \
	 }, \
	 .PEN_TILT_LHB_CFG = \
	 { \
	  .tBit.pen_tilt_mux_cfg0 = 0, \
	  .tBit.pen_tilt_mux_cfg1 = 0, \
	  .tBit.pen_tilt_mux_cfg2 = 0, \
	  .tBit.pen_tilt_mux_cfg3 = 0, \
	  .tBit.pen_tilt_mux_dly = 0, \
	 }, \
	 .PING_MUX_CTL = \
	 { \
	  .tBit.ping_max = 0, \
	  .tBit.ping_pwm_num = 0, \
	  .tBit.ping_mux_sel = 0, \
	  .tBit.ping_mode = 0, \
	 }, \
	 .PHD_SENSE_CTL1 = \
	 { \
	  .tBit.rst_phd_fall_num = PARAMSET_ROIC_PDB_SENSE_CTL1_rst_phd_fall_num, \
	  .tBit.phd_all_fall_num = PARAMSET_ROIC_PDB_SENSE_CTL1_phd_all_fall_num, \
	  .tBit.adc_in_phd_rise_num = PARAMSET_ROIC_PDB_SENSE_CTL1_adc_in_phd_rise_num, \
	 }, \
	 .PDB_PHD_CTL = \
	 { \
	  .tBit.pdrv_mode = PARAMSET_ROIC_PDB_PHD_CTL_pdrv_mode, \
	  .tBit.phd_en_op_num = PARAMSET_ROIC_PDB_PHD_CTL_phd_en_op_num, \
	  .tBit.phd_md_op_num = PARAMSET_ROIC_PDB_PHD_CTL_phd_md_op_num, \
	  .tBit.pdb_phd_sha_off_sel = PARAMSET_ROIC_PDB_PHD_CTL_pdb_phd_sha_off_sel, \
	 }, \
	 .SYS_DUMMY0 = \
	 { \
	  .tBit.sys_dummy0 = 0x00000000, \
	 }, \
	 .SYS_DUMMY1 = \
	 { \
	  .tBit.sys_dummy1 = 0x0000FFFF, \
	 }, \
	 .TEST_MUX_CTL = \
	 { \
	  .tBit.test_adc_sel = 0, \
	  .tBit.mon_adcdo_en = 0, \
	  .tBit.test_adc_eoc_sel = 0, \
	  .tBit.qcnt_vcom_th_en_pen = PARAMSET_ROIC_TEST_MUX_CTL_qcnt_vcom_th_en_pen, \
	  .tBit.qcnt_vcom_th_en_fig = PARAMSET_ROIC_TEST_MUX_CTL_qcnt_vcom_th_en_fig, \
	  .tBit.fig_mux_st_num = PARAMSET_ROIC_TEST_MUX_CTL_fig_mux_st_num, \
	  .tBit.pen_mux_st_num = PARAMSET_ROIC_TEST_MUX_CTL_pen_mux_st_num, \
	  .tBit.phd_phtcr_vcr_en = PARAMSET_ROIC_TEST_CTL_phd_phtcr_vcr_en, \
	  .tBit.phd_phtcr_ctl = PARAMSET_ROIC_TEST_CTL_phd_phtcr_ctl, \
	  .tBit.phd_vcr_ctl = PARAMSET_ROIC_TEST_CTL_phd_vcr_ctl, \
	 }, \
	 .PHD_CTL = \
	 { \
	  .tBit.edgecnt_th = PARAMSET_ROIC_PHD_CTL_edgecnt_th, \
	  .tBit.sel_delay = PARAMSET_ROIC_PHD_CTL_sel_delay, \
	  .tBit.invalid_dly = PARAMSET_ROIC_PHD_CTL_invalid_dly, \
	  .tBit.pen_mux_dly = PARAMSET_ROIC_PHD_CTL_pen_mux_dly, \
	  .tBit.offset_val = PARAMSET_ROIC_PHD_CTL_offset_val, \
	  .tBit.phd_delay_hold_en = PARAMSET_ROIC_PHD_CTL_phd_delay_hold_en, \
	  .tBit.invalid_chk_en = PARAMSET_ROIC_PHD_CTL_invalid_chk_en, \
	 }, \
	 .R0_SYS_CFG = \
	 { \
	  .tBit.r0_buf_clk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf_clk_on, \
	  .tBit.r0_cfclk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_cfclk_on, \
	  .tBit.r0_buf1_clk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf1_clk_on, \
	  .tBit.r0_buf2_clk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf2_clk_on, \
	  .tBit.r0_buf3_clk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf3_clk_on, \
	  .tBit.r0_apen_clk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_apen_clk_on, \
	 }, \
	 .R0_CH_EN = \
	 { \
	  .tBit.r0_ch_dum_drv_en = PARAMSET_ROIC_CH_EN_r0_ch_dum_drv_en, \
	  .tBit.r0_ch_en_int = PARAMSET_ROIC_CH_EN_r0_ch_en_int, \
	  .tBit.r0_ch_en_hvc = PARAMSET_ROIC_CH_EN_r0_ch_en_hvc, \
	 }, \
	 .R0_BUF_OPT = \
	 { \
	  .tBit.r0_triple_buf_en = 1, \
	  .tBit.r0_pre_drv_en = PARAMSET_ROIC_BUF_OPT_r_pre_drv_en, \
	  .tBit.r0_buf_cnt_ctl_en = 0, \
	  .tBit.r0_buf_cnt_num = 0, \
	  .tBit.r0_pdrv_buf_st_num = 0, \
	 }, \
	 .R0_VCOMR_OPT = \
	 { \
	  .tBit.r0_display_vcomr = PARAMSET_ROIC_VCOMR_OPT_display_vcomr, \
	  .tBit.r0_touch_f_vcomr = PARAMSET_ROIC_VCOMR_OPT_touch_f_vcomr, \
	  .tBit.r0_touch_p_vcomr = PARAMSET_ROIC_VCOMR_OPT_touch_p_vcomr, \
	  .tBit.r0_stuck_vcomr = 0, \
	  .tBit.r0_stuck_vcomr_level = 0, \
	  .tBit.r0_tsync_opt = 0, \
	 }, \
	 .R0_MUX_CTL = \
	 { \
	  .tBit.r0_mux_int_en = PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_mux_int_en, \
	  .tBit.r0_mux_int_stuck_val = PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_mux_int_stuck_val, \
	  .tBit.r0_uplink_mux = PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_uplink_mux, \
	  .tBit.r0_uplink_state = PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_uplink_state, \
	 }, \
	 .R0_MUX_STUCK_CTL = \
	 { \
	  .tBit.r0_mux_s_stuck_en = PARAMSET_ROIC_CFGR_MUX_CTL_mux_s_stuck_en, \
	  .tBit.r0_mux_s_stuck_val = PARAMSET_ROIC_CFGR_MUX_CTL_mux_s_stuck_val, \
	  .tBit.r0_mux_f_stuck_en = PARAMSET_ROIC_CFGR_MUX_CTL_mux_f_stuck_en, \
	  .tBit.r0_mux_f_stuck_val = PARAMSET_ROIC_CFGR_MUX_CTL_mux_f_stuck_val, \
	 }, \
	 .R0_LHB_MUX_CTL = \
	 { \
	  .tBit.r0_mux_m1_bit_en = PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_m1_bit_en, \
	  .tBit.r0_mux_nd_bit_en = PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_nd_bit_en, \
	  .tBit.r0_mux_pen_bit_en = PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_pen_bit_en, \
	 }, \
	 .R0_CR_R1G_MUX1_2 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_0_R0_1stMux_r1_g1, \
	   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_0_R0_1stMux_r1_g2, \
	   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_0_R0_1stMux_r1_g3, \
	   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_0_R0_2ndMux_r1_g1, \
	   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_0_R0_2ndMux_r1_g2, \
	   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_0_R0_2ndMux_r1_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_1_R0_1stMux_r1_g1, \
	   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_1_R0_1stMux_r1_g2, \
	   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_1_R0_1stMux_r1_g3, \
	   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_1_R0_2ndMux_r1_g1, \
	   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_1_R0_2ndMux_r1_g2, \
	   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_1_R0_2ndMux_r1_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_2_R0_1stMux_r1_g1, \
	   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_2_R0_1stMux_r1_g2, \
	   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_2_R0_1stMux_r1_g3, \
	   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_2_R0_2ndMux_r1_g1, \
	   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_2_R0_2ndMux_r1_g2, \
	   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_2_R0_2ndMux_r1_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_3_R0_1stMux_r1_g1, \
	   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_3_R0_1stMux_r1_g2, \
	   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_3_R0_1stMux_r1_g3, \
	   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_3_R0_2ndMux_r1_g1, \
	   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_3_R0_2ndMux_r1_g2, \
	   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_3_R0_2ndMux_r1_g3, \
	  }, \
	 }, \
	 .R0_CR_R2G_MUX1_2 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_0_R0_1stMux_r2_g1, \
	   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_0_R0_1stMux_r2_g2, \
	   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_0_R0_1stMux_r2_g3, \
	   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_0_R0_2ndMux_r2_g1, \
	   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_0_R0_2ndMux_r2_g2, \
	   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_0_R0_2ndMux_r2_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_1_R0_1stMux_r2_g1, \
	   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_1_R0_1stMux_r2_g2, \
	   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_1_R0_1stMux_r2_g3, \
	   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_1_R0_2ndMux_r2_g1, \
	   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_1_R0_2ndMux_r2_g2, \
	   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_1_R0_2ndMux_r2_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_2_R0_1stMux_r2_g1, \
	   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_2_R0_1stMux_r2_g2, \
	   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_2_R0_1stMux_r2_g3, \
	   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_2_R0_2ndMux_r2_g1, \
	   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_2_R0_2ndMux_r2_g2, \
	   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_2_R0_2ndMux_r2_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_3_R0_1stMux_r2_g1, \
	   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_3_R0_1stMux_r2_g2, \
	   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_3_R0_1stMux_r2_g3, \
	   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_3_R0_2ndMux_r2_g1, \
	   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_3_R0_2ndMux_r2_g2, \
	   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_3_R0_2ndMux_r2_g3, \
	  }, \
	 }, \
	 .R0_CR_R3G_MUX1_2 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_0_R0_1stMux_r3_g1, \
	   .tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_0_R0_1stMux_r3_g2, \
	   .tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_0_R0_1stMux_r3_g3, \
	   .tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_0_R0_2ndMux_r3_g1, \
	   .tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_0_R0_2ndMux_r3_g2, \
	   .tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_0_R0_2ndMux_r3_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_1_R0_1stMux_r3_g1, \
	   .tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_1_R0_1stMux_r3_g2, \
	   .tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_1_R0_1stMux_r3_g3, \
	   .tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_1_R0_2ndMux_r3_g1, \
	   .tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_1_R0_2ndMux_r3_g2, \
	   .tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_1_R0_2ndMux_r3_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_2_R0_1stMux_r3_g1, \
	   .tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_2_R0_1stMux_r3_g2, \
	   .tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_2_R0_1stMux_r3_g3, \
	   .tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_2_R0_2ndMux_r3_g1, \
	   .tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_2_R0_2ndMux_r3_g2, \
	   .tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_2_R0_2ndMux_r3_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_3_R0_1stMux_r3_g1, \
	   .tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_3_R0_1stMux_r3_g2, \
	   .tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_3_R0_1stMux_r3_g3, \
	   .tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_3_R0_2ndMux_r3_g1, \
	   .tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_3_R0_2ndMux_r3_g2, \
	   .tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_3_R0_2ndMux_r3_g3, \
	  }, \
	 }, \
	 .R0_CR_R1G_MUX3_4 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_0_R0_3rdMux_r1_g1, \
	   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_0_R0_3rdMux_r1_g2, \
	   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_0_R0_3rdMux_r1_g3, \
	   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_0_R0_4thMux_r1_g1, \
	   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_0_R0_4thMux_r1_g2, \
	   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_0_R0_4thMux_r1_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_1_R0_3rdMux_r1_g1, \
	   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_1_R0_3rdMux_r1_g2, \
	   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_1_R0_3rdMux_r1_g3, \
	   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_1_R0_4thMux_r1_g1, \
	   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_1_R0_4thMux_r1_g2, \
	   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_1_R0_4thMux_r1_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_2_R0_3rdMux_r1_g1, \
	   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_2_R0_3rdMux_r1_g2, \
	   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_2_R0_3rdMux_r1_g3, \
	   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_2_R0_4thMux_r1_g1, \
	   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_2_R0_4thMux_r1_g2, \
	   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_2_R0_4thMux_r1_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_3_R0_3rdMux_r1_g1, \
	   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_3_R0_3rdMux_r1_g2, \
	   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_3_R0_3rdMux_r1_g3, \
	   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_3_R0_4thMux_r1_g1, \
	   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_3_R0_4thMux_r1_g2, \
	   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_3_R0_4thMux_r1_g3, \
	  }, \
	 }, \
	 .R0_CR_R2G_MUX3_4 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_0_R0_3rdMux_r2_g1, \
	   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_0_R0_3rdMux_r2_g2, \
	   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_0_R0_3rdMux_r2_g3, \
	   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_0_R0_4thMux_r2_g1, \
	   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_0_R0_4thMux_r2_g2, \
	   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_0_R0_4thMux_r2_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_1_R0_3rdMux_r2_g1, \
	   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_1_R0_3rdMux_r2_g2, \
	   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_1_R0_3rdMux_r2_g3, \
	   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_1_R0_4thMux_r2_g1, \
	   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_1_R0_4thMux_r2_g2, \
	   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_1_R0_4thMux_r2_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_2_R0_3rdMux_r2_g1, \
	   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_2_R0_3rdMux_r2_g2, \
	   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_2_R0_3rdMux_r2_g3, \
	   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_2_R0_4thMux_r2_g1, \
	   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_2_R0_4thMux_r2_g2, \
	   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_2_R0_4thMux_r2_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_3_R0_3rdMux_r2_g1, \
	   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_3_R0_3rdMux_r2_g2, \
	   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_3_R0_3rdMux_r2_g3, \
	   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_3_R0_4thMux_r2_g1, \
	   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_3_R0_4thMux_r2_g2, \
	   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_3_R0_4thMux_r2_g3, \
	  }, \
	 }, \
	 .R0_CR_R3G_MUX3_4 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_0_R0_3rdMux_r3_g1, \
	   .tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_0_R0_3rdMux_r3_g2, \
	   .tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_0_R0_3rdMux_r3_g3, \
	   .tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_0_R0_4thMux_r3_g1, \
	   .tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_0_R0_4thMux_r3_g2, \
	   .tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_0_R0_4thMux_r3_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_1_R0_3rdMux_r3_g1, \
	   .tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_1_R0_3rdMux_r3_g2, \
	   .tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_1_R0_3rdMux_r3_g3, \
	   .tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_1_R0_4thMux_r3_g1, \
	   .tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_1_R0_4thMux_r3_g2, \
	   .tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_1_R0_4thMux_r3_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_2_R0_3rdMux_r3_g1, \
	   .tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_2_R0_3rdMux_r3_g2, \
	   .tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_2_R0_3rdMux_r3_g3, \
	   .tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_2_R0_4thMux_r3_g1, \
	   .tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_2_R0_4thMux_r3_g2, \
	   .tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_2_R0_4thMux_r3_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_3_R0_3rdMux_r3_g1, \
	   .tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_3_R0_3rdMux_r3_g2, \
	   .tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_3_R0_3rdMux_r3_g3, \
	   .tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_3_R0_4thMux_r3_g1, \
	   .tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_3_R0_4thMux_r3_g2, \
	   .tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_3_R0_4thMux_r3_g3, \
	  }, \
	 }, \
	 .R0_CR_R1G_MUX5_6 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_0_R0_5thMux_r1_g1, \
	   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_0_R0_5thMux_r1_g2, \
	   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_0_R0_5thMux_r1_g3, \
	   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_0_R0_6thMux_r1_g1, \
	   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_0_R0_6thMux_r1_g2, \
	   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_0_R0_6thMux_r1_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_1_R0_5thMux_r1_g1, \
	   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_1_R0_5thMux_r1_g2, \
	   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_1_R0_5thMux_r1_g3, \
	   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_1_R0_6thMux_r1_g1, \
	   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_1_R0_6thMux_r1_g2, \
	   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_1_R0_6thMux_r1_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_2_R0_5thMux_r1_g1, \
	   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_2_R0_5thMux_r1_g2, \
	   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_2_R0_5thMux_r1_g3, \
	   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_2_R0_6thMux_r1_g1, \
	   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_2_R0_6thMux_r1_g2, \
	   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_2_R0_6thMux_r1_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_3_R0_5thMux_r1_g1, \
	   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_3_R0_5thMux_r1_g2, \
	   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_3_R0_5thMux_r1_g3, \
	   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_3_R0_6thMux_r1_g1, \
	   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_3_R0_6thMux_r1_g2, \
	   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_3_R0_6thMux_r1_g3, \
	  }, \
	 }, \
	 .R0_CR_R2G_MUX5_6 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_0_R0_5thMux_r2_g1, \
	   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_0_R0_5thMux_r2_g2, \
	   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_0_R0_5thMux_r2_g3, \
	   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_0_R0_6thMux_r2_g1, \
	   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_0_R0_6thMux_r2_g2, \
	   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_0_R0_6thMux_r2_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_1_R0_5thMux_r2_g1, \
	   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_1_R0_5thMux_r2_g2, \
	   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_1_R0_5thMux_r2_g3, \
	   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_1_R0_6thMux_r2_g1, \
	   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_1_R0_6thMux_r2_g2, \
	   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_1_R0_6thMux_r2_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_2_R0_5thMux_r2_g1, \
	   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_2_R0_5thMux_r2_g2, \
	   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_2_R0_5thMux_r2_g3, \
	   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_2_R0_6thMux_r2_g1, \
	   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_2_R0_6thMux_r2_g2, \
	   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_2_R0_6thMux_r2_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_3_R0_5thMux_r2_g1, \
	   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_3_R0_5thMux_r2_g2, \
	   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_3_R0_5thMux_r2_g3, \
	   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_3_R0_6thMux_r2_g1, \
	   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_3_R0_6thMux_r2_g2, \
	   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_3_R0_6thMux_r2_g3, \
	  }, \
	 }, \
	 .R0_CR_R3G_MUX5_6 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_0_R0_5thMux_r3_g1, \
	   .tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_0_R0_5thMux_r3_g2, \
	   .tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_0_R0_5thMux_r3_g3, \
	   .tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_0_R0_6thMux_r3_g1, \
	   .tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_0_R0_6thMux_r3_g2, \
	   .tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_0_R0_6thMux_r3_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_1_R0_5thMux_r3_g1, \
	   .tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_1_R0_5thMux_r3_g2, \
	   .tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_1_R0_5thMux_r3_g3, \
	   .tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_1_R0_6thMux_r3_g1, \
	   .tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_1_R0_6thMux_r3_g2, \
	   .tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_1_R0_6thMux_r3_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_2_R0_5thMux_r3_g1, \
	   .tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_2_R0_5thMux_r3_g2, \
	   .tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_2_R0_5thMux_r3_g3, \
	   .tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_2_R0_6thMux_r3_g1, \
	   .tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_2_R0_6thMux_r3_g2, \
	   .tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_2_R0_6thMux_r3_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_3_R0_5thMux_r3_g1, \
	   .tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_3_R0_5thMux_r3_g2, \
	   .tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_3_R0_5thMux_r3_g3, \
	   .tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_3_R0_6thMux_r3_g1, \
	   .tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_3_R0_6thMux_r3_g2, \
	   .tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_3_R0_6thMux_r3_g3, \
	  }, \
	 }, \
	 .R0_CR_R1G_MUX7_8 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_0_R0_7thMux_r1_g1, \
	   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_0_R0_7thMux_r1_g2, \
	   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_0_R0_7thMux_r1_g3, \
	   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_0_R0_8thMux_r1_g1, \
	   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_0_R0_8thMux_r1_g2, \
	   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_0_R0_8thMux_r1_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_1_R0_7thMux_r1_g1, \
	   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_1_R0_7thMux_r1_g2, \
	   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_1_R0_7thMux_r1_g3, \
	   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_1_R0_8thMux_r1_g1, \
	   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_1_R0_8thMux_r1_g2, \
	   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_1_R0_8thMux_r1_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_2_R0_7thMux_r1_g1, \
	   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_2_R0_7thMux_r1_g2, \
	   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_2_R0_7thMux_r1_g3, \
	   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_2_R0_8thMux_r1_g1, \
	   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_2_R0_8thMux_r1_g2, \
	   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_2_R0_8thMux_r1_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_3_R0_7thMux_r1_g1, \
	   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_3_R0_7thMux_r1_g2, \
	   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_3_R0_7thMux_r1_g3, \
	   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_3_R0_8thMux_r1_g1, \
	   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_3_R0_8thMux_r1_g2, \
	   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_3_R0_8thMux_r1_g3, \
	  }, \
	 }, \
	 .R0_CR_R2G_MUX7_8 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_0_R0_7thMux_r2_g1, \
	   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_0_R0_7thMux_r2_g2, \
	   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_0_R0_7thMux_r2_g3, \
	   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_0_R0_8thMux_r2_g1, \
	   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_0_R0_8thMux_r2_g2, \
	   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_0_R0_8thMux_r2_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_1_R0_7thMux_r2_g1, \
	   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_1_R0_7thMux_r2_g2, \
	   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_1_R0_7thMux_r2_g3, \
	   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_1_R0_8thMux_r2_g1, \
	   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_1_R0_8thMux_r2_g2, \
	   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_1_R0_8thMux_r2_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_2_R0_7thMux_r2_g1, \
	   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_2_R0_7thMux_r2_g2, \
	   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_2_R0_7thMux_r2_g3, \
	   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_2_R0_8thMux_r2_g1, \
	   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_2_R0_8thMux_r2_g2, \
	   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_2_R0_8thMux_r2_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_3_R0_7thMux_r2_g1, \
	   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_3_R0_7thMux_r2_g2, \
	   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_3_R0_7thMux_r2_g3, \
	   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_3_R0_8thMux_r2_g1, \
	   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_3_R0_8thMux_r2_g2, \
	   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_3_R0_8thMux_r2_g3, \
	  }, \
	 }, \
	 .R0_CR_R3G_MUX7_8 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux7_r3g1 = PARAMSET_ROIC_0_R0_7thMux_r3_g1, \
	   .tBit.r0_cr_mux7_r3g2 = PARAMSET_ROIC_0_R0_7thMux_r3_g2, \
	   .tBit.r0_cr_mux7_r3g3 = PARAMSET_ROIC_0_R0_7thMux_r3_g3, \
	   .tBit.r0_cr_mux8_r3g1 = PARAMSET_ROIC_0_R0_8thMux_r3_g1, \
	   .tBit.r0_cr_mux8_r3g2 = PARAMSET_ROIC_0_R0_8thMux_r3_g2, \
	   .tBit.r0_cr_mux8_r3g3 = PARAMSET_ROIC_0_R0_8thMux_r3_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux7_r3g1 = PARAMSET_ROIC_1_R0_7thMux_r3_g1, \
	   .tBit.r0_cr_mux7_r3g2 = PARAMSET_ROIC_1_R0_7thMux_r3_g2, \
	   .tBit.r0_cr_mux7_r3g3 = PARAMSET_ROIC_1_R0_7thMux_r3_g3, \
	   .tBit.r0_cr_mux8_r3g1 = PARAMSET_ROIC_1_R0_8thMux_r3_g1, \
	   .tBit.r0_cr_mux8_r3g2 = PARAMSET_ROIC_1_R0_8thMux_r3_g2, \
	   .tBit.r0_cr_mux8_r3g3 = PARAMSET_ROIC_1_R0_8thMux_r3_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux7_r3g1 = PARAMSET_ROIC_2_R0_7thMux_r3_g1, \
	   .tBit.r0_cr_mux7_r3g2 = PARAMSET_ROIC_2_R0_7thMux_r3_g2, \
	   .tBit.r0_cr_mux7_r3g3 = PARAMSET_ROIC_2_R0_7thMux_r3_g3, \
	   .tBit.r0_cr_mux8_r3g1 = PARAMSET_ROIC_2_R0_8thMux_r3_g1, \
	   .tBit.r0_cr_mux8_r3g2 = PARAMSET_ROIC_2_R0_8thMux_r3_g2, \
	   .tBit.r0_cr_mux8_r3g3 = PARAMSET_ROIC_2_R0_8thMux_r3_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux7_r3g1 = PARAMSET_ROIC_3_R0_7thMux_r3_g1, \
	   .tBit.r0_cr_mux7_r3g2 = PARAMSET_ROIC_3_R0_7thMux_r3_g2, \
	   .tBit.r0_cr_mux7_r3g3 = PARAMSET_ROIC_3_R0_7thMux_r3_g3, \
	   .tBit.r0_cr_mux8_r3g1 = PARAMSET_ROIC_3_R0_8thMux_r3_g1, \
	   .tBit.r0_cr_mux8_r3g2 = PARAMSET_ROIC_3_R0_8thMux_r3_g2, \
	   .tBit.r0_cr_mux8_r3g3 = PARAMSET_ROIC_3_R0_8thMux_r3_g3, \
	  }, \
	 }, \
	 .R0_CR_R1G_MUX9_10 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_0_R0_9thMux_r1_g1, \
	   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_0_R0_9thMux_r1_g2, \
	   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_0_R0_9thMux_r1_g3, \
	   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_0_R0_10thMux_r1_g1, \
	   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_0_R0_10thMux_r1_g2, \
	   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_0_R0_10thMux_r1_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_1_R0_9thMux_r1_g1, \
	   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_1_R0_9thMux_r1_g2, \
	   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_1_R0_9thMux_r1_g3, \
	   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_1_R0_10thMux_r1_g1, \
	   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_1_R0_10thMux_r1_g2, \
	   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_1_R0_10thMux_r1_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_2_R0_9thMux_r1_g1, \
	   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_2_R0_9thMux_r1_g2, \
	   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_2_R0_9thMux_r1_g3, \
	   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_2_R0_10thMux_r1_g1, \
	   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_2_R0_10thMux_r1_g2, \
	   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_2_R0_10thMux_r1_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_3_R0_9thMux_r1_g1, \
	   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_3_R0_9thMux_r1_g2, \
	   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_3_R0_9thMux_r1_g3, \
	   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_3_R0_10thMux_r1_g1, \
	   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_3_R0_10thMux_r1_g2, \
	   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_3_R0_10thMux_r1_g3, \
	  }, \
	 }, \
	 .R0_CR_R2G_MUX9_10 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_0_R0_9thMux_r2_g1, \
	   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_0_R0_9thMux_r2_g2, \
	   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_0_R0_9thMux_r2_g3, \
	   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_0_R0_10thMux_r2_g1, \
	   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_0_R0_10thMux_r2_g2, \
	   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_0_R0_10thMux_r2_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_1_R0_9thMux_r2_g1, \
	   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_1_R0_9thMux_r2_g2, \
	   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_1_R0_9thMux_r2_g3, \
	   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_1_R0_10thMux_r2_g1, \
	   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_1_R0_10thMux_r2_g2, \
	   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_1_R0_10thMux_r2_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_2_R0_9thMux_r2_g1, \
	   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_2_R0_9thMux_r2_g2, \
	   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_2_R0_9thMux_r2_g3, \
	   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_2_R0_10thMux_r2_g1, \
	   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_2_R0_10thMux_r2_g2, \
	   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_2_R0_10thMux_r2_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_3_R0_9thMux_r2_g1, \
	   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_3_R0_9thMux_r2_g2, \
	   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_3_R0_9thMux_r2_g3, \
	   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_3_R0_10thMux_r2_g1, \
	   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_3_R0_10thMux_r2_g2, \
	   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_3_R0_10thMux_r2_g3, \
	  }, \
	 }, \
	 .R0_CR_R3G_MUX9_10 = \
	 { \
	  [0] = { \
	   .tBit.r0_cr_mux9_r3g1 = PARAMSET_ROIC_0_R0_9thMux_r3_g1, \
	   .tBit.r0_cr_mux9_r3g2 = PARAMSET_ROIC_0_R0_9thMux_r3_g2, \
	   .tBit.r0_cr_mux9_r3g3 = PARAMSET_ROIC_0_R0_9thMux_r3_g3, \
	   .tBit.r0_cr_mux10_r3g1 = PARAMSET_ROIC_0_R0_10thMux_r3_g1, \
	   .tBit.r0_cr_mux10_r3g2 = PARAMSET_ROIC_0_R0_10thMux_r3_g2, \
	   .tBit.r0_cr_mux10_r3g3 = PARAMSET_ROIC_0_R0_10thMux_r3_g3, \
	  }, \
	  [1] = { \
	   .tBit.r0_cr_mux9_r3g1 = PARAMSET_ROIC_1_R0_9thMux_r3_g1, \
	   .tBit.r0_cr_mux9_r3g2 = PARAMSET_ROIC_1_R0_9thMux_r3_g2, \
	   .tBit.r0_cr_mux9_r3g3 = PARAMSET_ROIC_1_R0_9thMux_r3_g3, \
	   .tBit.r0_cr_mux10_r3g1 = PARAMSET_ROIC_1_R0_10thMux_r3_g1, \
	   .tBit.r0_cr_mux10_r3g2 = PARAMSET_ROIC_1_R0_10thMux_r3_g2, \
	   .tBit.r0_cr_mux10_r3g3 = PARAMSET_ROIC_1_R0_10thMux_r3_g3, \
	  }, \
	  [2] = { \
	   .tBit.r0_cr_mux9_r3g1 = PARAMSET_ROIC_2_R0_9thMux_r3_g1, \
	   .tBit.r0_cr_mux9_r3g2 = PARAMSET_ROIC_2_R0_9thMux_r3_g2, \
	   .tBit.r0_cr_mux9_r3g3 = PARAMSET_ROIC_2_R0_9thMux_r3_g3, \
	   .tBit.r0_cr_mux10_r3g1 = PARAMSET_ROIC_2_R0_10thMux_r3_g1, \
	   .tBit.r0_cr_mux10_r3g2 = PARAMSET_ROIC_2_R0_10thMux_r3_g2, \
	   .tBit.r0_cr_mux10_r3g3 = PARAMSET_ROIC_2_R0_10thMux_r3_g3, \
	  }, \
	  [3] = { \
	   .tBit.r0_cr_mux9_r3g1 = PARAMSET_ROIC_3_R0_9thMux_r3_g1, \
	   .tBit.r0_cr_mux9_r3g2 = PARAMSET_ROIC_3_R0_9thMux_r3_g2, \
	   .tBit.r0_cr_mux9_r3g3 = PARAMSET_ROIC_3_R0_9thMux_r3_g3, \
	   .tBit.r0_cr_mux10_r3g1 = PARAMSET_ROIC_3_R0_10thMux_r3_g1, \
	   .tBit.r0_cr_mux10_r3g2 = PARAMSET_ROIC_3_R0_10thMux_r3_g2, \
	   .tBit.r0_cr_mux10_r3g3 = PARAMSET_ROIC_3_R0_10thMux_r3_g3, \
	  }, \
	 }, \
	 .R0_CR_GTUNE1 = \
	 { \
	  [0] = { \
	   .tBit.r0_fig_mux1_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_MUX1_Global_Tune, \
	   .tBit.r0_fig_mux2_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_MUX2_Global_Tune, \
	   .tBit.r0_fig_mux3_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_MUX3_Global_Tune, \
	   .tBit.r0_fig_mux4_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_MUX4_Global_Tune, \
	   .tBit.r0_fig_mux5_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_MUX5_Global_Tune, \
	   .tBit.r0_fig_mux6_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_MUX6_Global_Tune, \
	   .tBit.r0_fig_mux7_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_MUX7_Global_Tune, \
	   .tBit.r0_fig_mux8_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_MUX8_Global_Tune, \
	   .tBit.r0_fig_mux9_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_MUX9_Global_Tune, \
	   .tBit.r0_fig_mux10_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_MUX10_Global_Tune, \
	  }, \
	  [1] = { \
	   .tBit.r0_fig_mux1_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_MUX1_Global_Tune, \
	   .tBit.r0_fig_mux2_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_MUX2_Global_Tune, \
	   .tBit.r0_fig_mux3_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_MUX3_Global_Tune, \
	   .tBit.r0_fig_mux4_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_MUX4_Global_Tune, \
	   .tBit.r0_fig_mux5_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_MUX5_Global_Tune, \
	   .tBit.r0_fig_mux6_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_MUX6_Global_Tune, \
	   .tBit.r0_fig_mux7_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_MUX7_Global_Tune, \
	   .tBit.r0_fig_mux8_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_MUX8_Global_Tune, \
	   .tBit.r0_fig_mux9_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_MUX9_Global_Tune, \
	   .tBit.r0_fig_mux10_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_MUX10_Global_Tune, \
	  }, \
	  [2] = { \
	   .tBit.r0_fig_mux1_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_MUX1_Global_Tune, \
	   .tBit.r0_fig_mux2_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_MUX2_Global_Tune, \
	   .tBit.r0_fig_mux3_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_MUX3_Global_Tune, \
	   .tBit.r0_fig_mux4_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_MUX4_Global_Tune, \
	   .tBit.r0_fig_mux5_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_MUX5_Global_Tune, \
	   .tBit.r0_fig_mux6_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_MUX6_Global_Tune, \
	   .tBit.r0_fig_mux7_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_MUX7_Global_Tune, \
	   .tBit.r0_fig_mux8_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_MUX8_Global_Tune, \
	   .tBit.r0_fig_mux9_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_MUX9_Global_Tune, \
	   .tBit.r0_fig_mux10_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_MUX10_Global_Tune, \
	  }, \
	  [3] = { \
	   .tBit.r0_fig_mux1_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_MUX1_Global_Tune, \
	   .tBit.r0_fig_mux2_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_MUX2_Global_Tune, \
	   .tBit.r0_fig_mux3_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_MUX3_Global_Tune, \
	   .tBit.r0_fig_mux4_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_MUX4_Global_Tune, \
	   .tBit.r0_fig_mux5_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_MUX5_Global_Tune, \
	   .tBit.r0_fig_mux6_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_MUX6_Global_Tune, \
	   .tBit.r0_fig_mux7_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_MUX7_Global_Tune, \
	   .tBit.r0_fig_mux8_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_MUX8_Global_Tune, \
	   .tBit.r0_fig_mux9_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_MUX9_Global_Tune, \
	   .tBit.r0_fig_mux10_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_MUX10_Global_Tune, \
	  }, \
	 }, \
	 .R0_CR_GTUNE2 = \
	 { \
	  [0] = { \
	   .tBit.r0_pen_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Pen_Global_Tune, \
	   .tBit.r0_pdrv_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_PRE_DRV_Global_Tune, \
	  }, \
	  [1] = { \
	   .tBit.r0_pen_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Pen_Global_Tune, \
	   .tBit.r0_pdrv_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_PRE_DRV_Global_Tune, \
	  }, \
	  [2] = { \
	   .tBit.r0_pen_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Pen_Global_Tune, \
	   .tBit.r0_pdrv_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_PRE_DRV_Global_Tune, \
	  }, \
	  [3] = { \
	   .tBit.r0_pen_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Pen_Global_Tune, \
	   .tBit.r0_pdrv_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_PRE_DRV_Global_Tune, \
	  }, \
	 }, \
	 .R0_TUNE_GROUP_SEL1 = \
	 { \
	  .tBit.r0_cr_mux1_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row1_gsel, \
	  .tBit.r0_cr_mux1_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row2_gsel, \
	  .tBit.r0_cr_mux1_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row3_gsel, \
	  .tBit.r0_cr_mux1_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row4_gsel, \
	  .tBit.r0_cr_mux1_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row5_gsel, \
	  .tBit.r0_cr_mux2_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row1_gsel, \
	  .tBit.r0_cr_mux2_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row2_gsel, \
	  .tBit.r0_cr_mux2_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row3_gsel, \
	  .tBit.r0_cr_mux2_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row4_gsel, \
	  .tBit.r0_cr_mux2_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row5_gsel, \
	  .tBit.r0_cr_mux3_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux3_row1_gsel, \
	  .tBit.r0_cr_mux3_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux3_row2_gsel, \
	  .tBit.r0_cr_mux3_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux3_row3_gsel, \
	  .tBit.r0_cr_mux3_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux3_row4_gsel, \
	  .tBit.r0_cr_mux3_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux3_row5_gsel, \
	 }, \
	 .R0_TUNE_GROUP_SEL2 = \
	 { \
	  .tBit.r0_cr_mux4_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux4_row1_gsel, \
	  .tBit.r0_cr_mux4_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux4_row2_gsel, \
	  .tBit.r0_cr_mux4_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux4_row3_gsel, \
	  .tBit.r0_cr_mux4_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux4_row4_gsel, \
	  .tBit.r0_cr_mux4_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux4_row5_gsel, \
	  .tBit.r0_cr_mux5_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux5_row1_gsel, \
	  .tBit.r0_cr_mux5_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux5_row2_gsel, \
	  .tBit.r0_cr_mux5_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux5_row3_gsel, \
	  .tBit.r0_cr_mux5_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux5_row4_gsel, \
	  .tBit.r0_cr_mux5_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux5_row5_gsel, \
	  .tBit.r0_cr_mux6_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux6_row1_gsel, \
	  .tBit.r0_cr_mux6_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux6_row2_gsel, \
	  .tBit.r0_cr_mux6_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux6_row3_gsel, \
	  .tBit.r0_cr_mux6_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux6_row4_gsel, \
	  .tBit.r0_cr_mux6_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux6_row5_gsel, \
	 }, \
	 .R0_TUNE_GROUP_SEL3 = \
	 { \
	  .tBit.r0_cr_mux7_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux7_row1_gsel, \
	  .tBit.r0_cr_mux7_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux7_row2_gsel, \
	  .tBit.r0_cr_mux7_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux7_row3_gsel, \
	  .tBit.r0_cr_mux7_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux7_row4_gsel, \
	  .tBit.r0_cr_mux7_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux7_row5_gsel, \
	  .tBit.r0_cr_mux8_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux8_row1_gsel, \
	  .tBit.r0_cr_mux8_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux8_row2_gsel, \
	  .tBit.r0_cr_mux8_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux8_row3_gsel, \
	  .tBit.r0_cr_mux8_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux8_row4_gsel, \
	  .tBit.r0_cr_mux8_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux8_row5_gsel, \
	  .tBit.r0_cr_mux9_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux9_row1_gsel, \
	  .tBit.r0_cr_mux9_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux9_row2_gsel, \
	  .tBit.r0_cr_mux9_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux9_row3_gsel, \
	  .tBit.r0_cr_mux9_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux9_row4_gsel, \
	  .tBit.r0_cr_mux9_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux9_row5_gsel, \
	 }, \
	 .R0_TUNE_GROUP_SEL4 = \
	 { \
	  .tBit.r0_cr_mux10_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux10_row1_gsel, \
	  .tBit.r0_cr_mux10_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux10_row2_gsel, \
	  .tBit.r0_cr_mux10_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux10_row3_gsel, \
	  .tBit.r0_cr_mux10_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux10_row4_gsel, \
	  .tBit.r0_cr_mux10_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux10_row5_gsel, \
	  .tBit.r0_cr_col1_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col1_gsel, \
	  .tBit.r0_cr_col2_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col2_gsel, \
	  .tBit.r0_cr_col3_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col3_gsel, \
	  .tBit.r0_cr_col4_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col4_gsel, \
	  .tBit.r0_cr_col5_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col5_gsel, \
	  .tBit.r0_cr_col6_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col6_gsel, \
	 }, \
	 .R0_ADC_IN_CTL = \
	 { \
	  .tBit.r0_adc_in = PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_in, \
	  .tBit.r0_adc_op_opt = PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_op_opt, \
	 }, \
	 .R0_ADC_SENSE_CTL1 = \
	 { \
	  .tBit.r0_fig_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_fig_lv_adc_ref_bcon, \
	  .tBit.r0_pp_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pp_lv_adc_ref_bcon, \
	  .tBit.r0_tilt_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_tilt_lv_adc_ref_bcon, \
	  .tBit.r0_pd_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pd_lv_adc_ref_bcon, \
	  .tBit.r0_pdrv_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pdrv_lv_adc_ref_bcon, \
	  .tBit.r0_fig_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_fig_lv_adc_bcon, \
	  .tBit.r0_pp_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pp_lv_adc_bcon, \
	  .tBit.r0_tilt_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_tilt_lv_adc_bcon, \
	  .tBit.r0_pd_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pd_lv_adc_bcon, \
	  .tBit.r0_pdrv_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pdrv_lv_adc_bcon, \
	 }, \
	 .R0_ADC_SENSE_CTL2 = \
	 { \
	  .tBit.r0_fig_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_comp_bias_ctl, \
	  .tBit.r0_pp_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_comp_bias_ctl, \
	  .tBit.r0_tilt_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_tilt_adc_comp_bias_ctl, \
	  .tBit.r0_pd_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_comp_bias_ctl, \
	  .tBit.r0_pdrv_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_comp_bias_ctl, \
	  .tBit.r0_fig_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_mdac_comp_ctl, \
	  .tBit.r0_pp_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_mdac_comp_ctl, \
	  .tBit.r0_tilt_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_mdac_comp_ctl, \
	  .tBit.r0_pd_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_mdac_comp_ctl, \
	  .tBit.r0_pdrv_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_mdac_comp_ctl, \
	  .tBit.r0_fig_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_mdac_slew_ctl, \
	  .tBit.r0_pp_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_mdac_slew_ctl, \
	  .tBit.r0_pd_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_mdac_slew_ctl, \
	  .tBit.r0_tilt_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_tilt_adc_mdac_slew_ctl, \
	  .tBit.r0_pdrv_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_mdac_slew_ctl, \
	  .tBit.r0_fig_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_ref_idrv_ctl, \
	  .tBit.r0_pp_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_ref_idrv_ctl, \
	  .tBit.r0_pd_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_ref_idrv_ctl, \
	  .tBit.r0_tilt_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_tilt_adc_ref_idrv_ctl, \
	  .tBit.r0_pdrv_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_ref_idrv_ctl, \
	  .tBit.r0_adc_clk_div_1p5 = PARAMSET_ROIC_ADC_SENSE_CTL2_adc_clk_div_1p5, \
	  .tBit.r0_adc_stc_insel = PARAMSET_ROIC_ADC_SENSE_CTL_adc_stc_insel, \
	 }, \
	 .R0_AFE_SENSE_CTL1 = \
	 { \
	  .tBit.r0_fig_cvc1_comp = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_cvc1_comp, \
	  .tBit.r0_pen_cvc1_comp = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_cvc1_comp, \
	  .tBit.r0_pdrv_cvc1_comp = PARAMSET_ROIC_AFE_SENSE_CTL1_pdrv_cvc1_comp, \
	  .tBit.r0_fig_int_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_int_ref, \
	  .tBit.r0_pen_int_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_int_ref, \
	  .tBit.r0_fig_sha_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_sha_ref, \
	  .tBit.r0_pen_sha_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_sha_ref, \
	 }, \
	 .R0_AFE_SENSE_CTL2 = \
	 { \
	  .tBit.r0_fig_cvc1_gc = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_cvc1_gc, \
	  .tBit.r0_pp_cvc1_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pp_cvc1_gc_con, \
	  .tBit.r0_pd_cvc1_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pd_cvc1_gc_con, \
	  .tBit.r0_tilt_cvc1_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_tilt_cvc1_gc_con, \
	  .tBit.r0_pp_cvc1_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pp_cvc1_gc_hov, \
	  .tBit.r0_pd_cvc1_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pd_cvc1_gc_hov, \
	  .tBit.r0_tilt_cvc1_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_tilt_cvc1_gc_hov, \
	  .tBit.r0_pdrv_cvc1_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_cvc1_gc_con, \
	  .tBit.r0_pdrv_cvc1_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_cvc1_gc_hov, \
	 }, \
	 .R0_AFE_SENSE_CTL3 = \
	 { \
	  .tBit.r0_fig_cvc2_gc = PARAMSET_ROIC_AFE_SENSE_CTL3_fig_cvc2_gc, \
	  .tBit.r0_pp_cvc2_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL3_pp_cvc2_gc_con, \
	  .tBit.r0_pd_cvc2_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL3_pd_cvc2_gc_con, \
	  .tBit.r0_tilt_cvc2_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL3_tilt_cvc2_gc_con, \
	  .tBit.r0_pp_cvc2_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL3_pp_cvc2_gc_hov, \
	  .tBit.r0_pd_cvc2_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL3_pd_cvc2_gc_hov, \
	  .tBit.r0_tilt_cvc2_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL3_tilt_cvc2_gc_hov, \
	  .tBit.r0_pdrv_cvc2_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL3_pdrv_cvc2_gc_con, \
	  .tBit.r0_pdrv_cvc2_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL3_pdrv_cvc2_gc_hov, \
	 }, \
	 .R0_AFE_SENSE_CTL4 = \
	 { \
	  .tBit.r0_fig_int_gc = PARAMSET_ROIC_AFE_SENSE_CTL4_fig_int_gc, \
	  .tBit.r0_pp_int_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_gc_con, \
	  .tBit.r0_pd_int_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_gc_con, \
	  .tBit.r0_tilt_int_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_gc_con, \
	  .tBit.r0_pp_int_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_gc_hov, \
	  .tBit.r0_pd_int_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_gc_hov, \
	  .tBit.r0_tilt_int_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_gc_hov, \
	  .tBit.r0_fig_int_half = PARAMSET_ROIC_AFE_SENSE_CTL4_fig_int_half, \
	  .tBit.r0_pp_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_half_con, \
	  .tBit.r0_pd_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_half_con, \
	  .tBit.r0_tilt_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_half_con, \
	  .tBit.r0_pp_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_half_hov, \
	  .tBit.r0_pd_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_half_hov, \
	  .tBit.r0_tilt_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_half_hov, \
	  .tBit.r0_pdrv_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL4_pdrv_int_half_con, \
	  .tBit.r0_pdrv_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_pdrv_int_half_hov, \
	 }, \
	 .R0_AFE_SENSE_CTL5 = \
	 { \
	  .tBit.r0_fig_hv_ssu_bcon_cvc1 = PARAMSET_ROIC_AFE_SENSE_CTL5_fig_hv_ssu_bcon_cvc1, \
	  .tBit.r0_pen_hv_ssu_bcon_cvc1 = PARAMSET_ROIC_AFE_SENSE_CTL5_pen_hv_ssu_bcon_cvc1, \
	  .tBit.r0_pdrv_hv_ssu_bcon_cvc1 = PARAMSET_ROIC_AFE_SENSE_CTL5_pdrv_hv_ssu_bcon_cvc1, \
	  .tBit.r0_fig_hv_ssu_bcon_cvc2 = PARAMSET_ROIC_AFE_SENSE_CTL5_fig_hv_ssu_bcon_cvc2, \
	  .tBit.r0_pen_hv_ssu_bcon_cvc2 = PARAMSET_ROIC_AFE_SENSE_CTL5_pen_hv_ssu_bcon_cvc2, \
	  .tBit.r0_pdrv_hv_ssu_bcon_cvc2 = PARAMSET_ROIC_AFE_SENSE_CTL5_pdrv_hv_ssu_bcon_cvc2, \
	  .tBit.r0_fig_lv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL5_fig_lv_ssu_bcon, \
	  .tBit.r0_pen_lv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL5_pen_lv_ssu_bcon, \
	  .tBit.r0_fig_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL5_fig_lv_ssu_bcons, \
	  .tBit.r0_pp_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL5_pp_lv_ssu_bcons, \
	  .tBit.r0_tilt_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL5_tilt_lv_ssu_bcons, \
	  .tBit.r0_pd_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL5_pd_lv_ssu_bcons, \
	  .tBit.r0_lv_ssu_bconp = PARAMSET_ROIC_AFE_SENSE_CTL5_lv_ssu_bconp, \
	  .tBit.r0_lv_ssu_bconp_buf = PARAMSET_ROIC_AFE_SENSE_CTL5_lv_ssu_bconp_buf, \
	  .tBit.r0_ref_bcon = PARAMSET_ROIC_AFE_SENSE_CTL5_ref_bcon, \
	 }, \
	 .R0_PDB_CTL = \
	 { \
	  .tBit.r0_pdb_hvbias = PARAMSET_ROIC_PDB_CTL_pdb_hvbias, \
	  .tBit.r0_pdb_hvc = PARAMSET_ROIC_PDB_CTL_pdb_hvc, \
	  .tBit.r0_pdb_lvbias = PARAMSET_ROIC_PDB_CTL_pdb_lvbias, \
	  .tBit.r0_pdb_int = PARAMSET_ROIC_PDB_CTL_pdb_int, \
	  .tBit.r0_pdb_sha = PARAMSET_ROIC_PDB_CTL_pdb_sha, \
	  .tBit.r0_bgr_en = PARAMSET_ROIC_PDB_CTL_pdb_bgr_en, \
	  .tBit.r0_bias_en = PARAMSET_ROIC_PDB_CTL_pdb_bias_en, \
	  .tBit.r0_pdb_adc = PARAMSET_ROIC_PDB_CTL_pdb_adc, \
	  .tBit.r0_pdb_phd = PARAMSET_ROIC_PDB_CTL_pdb_phd, \
	  .tBit.r0_pdb_phd_buf = PARAMSET_ROIC_PDB_CTL_pdb_phd_buf, \
	  .tBit.r0_stuck_hvbias = PARAMSET_ROIC_PDB_CTL_stuck_hvbias, \
	  .tBit.r0_stuck_hvc = PARAMSET_ROIC_PDB_CTL_stuck_hvc, \
	  .tBit.r0_stuck_lvbias = PARAMSET_ROIC_PDB_CTL_stuck_lvbias, \
	  .tBit.r0_stuck_int = PARAMSET_ROIC_PDB_CTL_stuck_int, \
	  .tBit.r0_stuck_sha = PARAMSET_ROIC_PDB_CTL_stuck_sha, \
	  .tBit.r0_stuck_bgr_en = PARAMSET_ROIC_PDB_CTL_stuck_bgr_en, \
	  .tBit.r0_stuck_bias_en = PARAMSET_ROIC_PDB_CTL_stuck_bias_en, \
	  .tBit.r0_stuck_adc = PARAMSET_ROIC_PDB_CTL_stuck_adc, \
	  .tBit.r0_stuck_phd = PARAMSET_ROIC_PDB_CTL_stuck_phd, \
	  .tBit.r0_stuck_phd_buf = PARAMSET_ROIC_PDB_CTL_stuck_phd_buf, \
	 }, \
	 .R0_TG_STUCK = \
	 { \
	  .tBit.r0_stuck_cvc1_drv = PARAMSET_ROIC_TG_STUCK_stuck_cvc1_drv, \
	  .tBit.r0_stuck_cvc1_drv_d = PARAMSET_ROIC_TG_STUCK_stuck_cvc1_drv_d, \
	  .tBit.r0_stuck_rstp = PARAMSET_ROIC_TG_STUCK_stuck_rstp, \
	  .tBit.r0_stuck_phtcr = PARAMSET_ROIC_TG_STUCK_stuck_phtcr, \
	  .tBit.r0_stuck_vcr = PARAMSET_ROIC_TG_STUCK_stuck_vcr, \
	  .tBit.r0_stuck_rsti = PARAMSET_ROIC_TG_STUCK_stuck_rsti, \
	  .tBit.r0_stuck_phth0 = PARAMSET_ROIC_TG_STUCK_stuck_phth0, \
	  .tBit.r0_stuck_phth1 = PARAMSET_ROIC_TG_STUCK_stuck_phth1, \
	  .tBit.r0_stuck_pht0 = PARAMSET_ROIC_TG_STUCK_stuck_pht0, \
	  .tBit.r0_stuck_pht1 = PARAMSET_ROIC_TG_STUCK_stuck_pht1, \
	  .tBit.r0_fig_vcr_inv_en = PARAMSET_ROIC_TG_STUCK_fig_vcr_inv_en, \
	  .tBit.r0_pen_vcr_inv_en = PARAMSET_ROIC_TG_STUCK_pen_vcr_inv_en, \
	  .tBit.r0_fig_stuck_vcr_en_odd = PARAMSET_ROIC_TG_STUCK_fig_stuck_vcr_en_odd, \
	  .tBit.r0_pen_stuck_vcr_en_odd = PARAMSET_ROIC_TG_STUCK_pen_stuck_vcr_en_odd, \
	  .tBit.r0_fig_stuck_vcr_en_even = PARAMSET_ROIC_TG_STUCK_fig_stuck_vcr_en_even, \
	  .tBit.r0_pen_stuck_vcr_en_even = PARAMSET_ROIC_TG_STUCK_pen_stuck_vcr_en_even, \
	 }, \
	 .R0_TEST_MUX_CTL = \
	 { \
	  .tBit.r0_tm_mon_en = 0, \
	  .tBit.r0_tm_mon_s = 0, \
	  .tBit.r0_tm_ps_ev = 0, \
	  .tBit.r0_tm_ps_od = 0, \
	  .tBit.r0_tm_ssu_pen = 0, \
	  .tBit.r0_test_adc_a = 0, \
	  .tBit.r0_test_adc_b = 0, \
	  .tBit.r0_tm_cr = 0, \
	  .tBit.r0_tm_phd_cr_en = 0, \
	  .tBit.r0_tm_phd_cr00 = 0, \
	  .tBit.r0_tm_phd_cr54 = 0, \
	 }, \
	 .R0_RESERVE = \
	 { \
	  .tBit.r0_reserve = 0, \
	 }, \
	 .R0_PHD_SENSE_CTL1 = \
	 { \
	  .tBit.r0_phd_in_s = PARAMSET_ROIC_PHD_SENSE_CTL1_phd_in_s, \
	  .tBit.r0_phd_en = PARAMSET_ROIC_PHD_SENSE_CTL1_phd_en, \
	  .tBit.r0_rst_phd_en = PARAMSET_ROIC_PHD_SENSE_CTL1_rst_phd_en, \
	  .tBit.r0_phd_gc_con = PARAMSET_ROIC_PHD_SENSE_CTL1_phd_gc_con, \
	  .tBit.r0_phd_gc_hov = PARAMSET_ROIC_PHD_SENSE_CTL1_phd_gc_hov, \
	  .tBit.r0_phd_md = PARAMSET_ROIC_PHD_SENSE_CTL1_phd_md, \
	  .tBit.r0_adc_in_phd = PARAMSET_ROIC_PHD_SENSE_CTL1_adc_in_phd, \
	  .tBit.r0_stuck_rst_phd = PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_rst_phd, \
	  .tBit.r0_stuck_adc_in_phd = PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_adc_in_phd, \
	  .tBit.r0_stuck_phd_md = PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_phd_md, \
	  .tBit.r0_stuck_phd_en = PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_phd_en, \
	  .tBit.r0_max_phd_dly_sel = PARAMSET_ROIC_PHD_SENSE_CTL1_max_phd_dly_sel, \
	 }, \
	 .R0_PHD_CTL1 = \
	 { \
	  .tBit.r0_adc_skipnum_hov = PARAMSET_ROIC_PHD_CTL1_r0_adc_skipnum_hov, \
	  .tBit.r0_adc_th_hov = PARAMSET_ROIC_PHD_CTL1_r0_adc_th_hov, \
	  .tBit.r0_bypass_en_hov = PARAMSET_ROIC_PHD_CTL1_r0_bypass_en_hov, \
	  .tBit.r0_coef_val1_hov = PARAMSET_ROIC_PHD_CTL1_r0_coef_val1_hov, \
	  .tBit.r0_coef_val2_hov = PARAMSET_ROIC_PHD_CTL1_r0_coef_val2_hov, \
	 }, \
	 .R0_PHD_CTL2 = \
	 { \
	  .tBit.r0_dly_th_hov = PARAMSET_ROIC_PHD_CTL2_r0_dly_th_hov, \
	  .tBit.r0_offset_dly_hov = PARAMSET_ROIC_PHD_CTL2_r0_offset_dly_hov, \
	  .tBit.r0_invalid_dly_hov = PARAMSET_ROIC_PHD_CTL2_r0_invalid_dly_hov, \
	  .tBit.r0_max_phd_dly_hov = PARAMSET_ROIC_PHD_CTL2_r0_max_phd_dly_hov, \
	 }, \
	 .R0_PHD_CTL3 = \
	 { \
	  .tBit.r0_adc_skipnum_con = PARAMSET_ROIC_PHD_CTL3_r0_adc_skipnum_con, \
	  .tBit.r0_adc_th_con = PARAMSET_ROIC_PHD_CTL3_r0_adc_th_con, \
	  .tBit.r0_bypass_en_con = PARAMSET_ROIC_PHD_CTL3_r0_bypass_en_con, \
	  .tBit.r0_coef_val1_con = PARAMSET_ROIC_PHD_CTL3_r0_coef_val1_con, \
	  .tBit.r0_coef_val2_con = PARAMSET_ROIC_PHD_CTL3_r0_coef_val2_con, \
	 }, \
	 .R0_PHD_CTL4 = \
	 { \
	  .tBit.r0_dly_th_con = PARAMSET_ROIC_PHD_CTL4_r0_dly_th_con, \
	  .tBit.r0_offset_dly_con = PARAMSET_ROIC_PHD_CTL4_r0_offset_dly_con, \
	  .tBit.r0_invalid_dly_con = PARAMSET_ROIC_PHD_CTL4_r0_invalid_dly_con, \
	  .tBit.r0_max_phd_dly_con = PARAMSET_ROIC_PHD_CTL4_r0_max_phd_dly_con, \
	 }, \
	 .R1_SYS_CFG = \
	 { \
	  .tBit.r1_buf_clk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf_clk_on, \
	  .tBit.r1_cfclk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_cfclk_on, \
	  .tBit.r1_buf1_clk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf1_clk_on, \
	  .tBit.r1_buf2_clk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf2_clk_on, \
	  .tBit.r1_buf3_clk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_buf3_clk_on, \
	  .tBit.r1_apen_clk_on = PARAMSET_ROIC_CFGR_R_SYS_CFG_r_apen_clk_on, \
	 }, \
	 .R1_CH_EN = \
	 { \
	  .tBit.r1_ch_dum_drv_en = PARAMSET_ROIC_CH_EN_r1_ch_dum_drv_en, \
	  .tBit.r1_ch_en_int = PARAMSET_ROIC_CH_EN_r1_ch_en_int, \
	  .tBit.r1_ch_en_hvc = PARAMSET_ROIC_CH_EN_r1_ch_en_hvc, \
	 }, \
	 .R1_BUF_OPT = \
	 { \
	  .tBit.r1_triple_buf_en = 1, \
	  .tBit.r1_pre_drv_en = PARAMSET_ROIC_BUF_OPT_r_pre_drv_en, \
	  .tBit.r1_buf_cnt_ctl_en = 0, \
	  .tBit.r1_buf_cnt_num = 0, \
	  .tBit.r1_pdrv_buf_st_num = 0, \
	 }, \
	 .R1_VCOMR_OPT = \
	 { \
	  .tBit.r1_display_vcomr = PARAMSET_ROIC_VCOMR_OPT_display_vcomr, \
	  .tBit.r1_touch_f_vcomr = PARAMSET_ROIC_VCOMR_OPT_touch_f_vcomr, \
	  .tBit.r1_touch_p_vcomr = PARAMSET_ROIC_VCOMR_OPT_touch_p_vcomr, \
	  .tBit.r1_stuck_vcomr = 0, \
	  .tBit.r1_stuck_vcomr_level = 0, \
	  .tBit.r1_tsync_opt = 0, \
	 }, \
	 .R1_MUX_CTL = \
	 { \
	  .tBit.r1_mux_int_en = PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_mux_int_en, \
	  .tBit.r1_mux_int_stuck_val = PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_mux_int_stuck_val, \
	  .tBit.r1_uplink_mux = PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_uplink_mux, \
	  .tBit.r1_uplink_state = PARAMSET_ROIC_CFGR_MUX_STUCK_CTL_uplink_state, \
	 }, \
	 .R1_MUX_STUCK_CTL = \
	 { \
	  .tBit.r1_mux_s_stuck_en = PARAMSET_ROIC_CFGR_MUX_CTL_mux_s_stuck_en, \
	  .tBit.r1_mux_s_stuck_val = PARAMSET_ROIC_CFGR_MUX_CTL_mux_s_stuck_val, \
	  .tBit.r1_mux_f_stuck_en = PARAMSET_ROIC_CFGR_MUX_CTL_mux_f_stuck_en, \
	  .tBit.r1_mux_f_stuck_val = PARAMSET_ROIC_CFGR_MUX_CTL_mux_f_stuck_val, \
	 }, \
	 .R1_LHB_MUX_CTL = \
	 { \
	  .tBit.r1_mux_m1_bit_en = PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_m1_bit_en, \
	  .tBit.r1_mux_nd_bit_en = PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_nd_bit_en, \
	  .tBit.r1_mux_pen_bit_en = PARAMSET_ROIC_CFGR_LHB_MUX_CTL_mux_pen_bit_en, \
	 }, \
	 .R1_CR_R1G_MUX1_2 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_0_R1_1stMux_r1_g1, \
	   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_0_R1_1stMux_r1_g2, \
	   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_0_R1_1stMux_r1_g3, \
	   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_0_R1_2ndMux_r1_g1, \
	   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_0_R1_2ndMux_r1_g2, \
	   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_0_R1_2ndMux_r1_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_1_R1_1stMux_r1_g1, \
	   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_1_R1_1stMux_r1_g2, \
	   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_1_R1_1stMux_r1_g3, \
	   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_1_R1_2ndMux_r1_g1, \
	   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_1_R1_2ndMux_r1_g2, \
	   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_1_R1_2ndMux_r1_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_2_R1_1stMux_r1_g1, \
	   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_2_R1_1stMux_r1_g2, \
	   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_2_R1_1stMux_r1_g3, \
	   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_2_R1_2ndMux_r1_g1, \
	   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_2_R1_2ndMux_r1_g2, \
	   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_2_R1_2ndMux_r1_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_3_R1_1stMux_r1_g1, \
	   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_3_R1_1stMux_r1_g2, \
	   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_3_R1_1stMux_r1_g3, \
	   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_3_R1_2ndMux_r1_g1, \
	   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_3_R1_2ndMux_r1_g2, \
	   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_3_R1_2ndMux_r1_g3, \
	  }, \
	 }, \
	 .R1_CR_R2G_MUX1_2 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_0_R1_1stMux_r2_g1, \
	   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_0_R1_1stMux_r2_g2, \
	   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_0_R1_1stMux_r2_g3, \
	   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_0_R1_2ndMux_r2_g1, \
	   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_0_R1_2ndMux_r2_g2, \
	   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_0_R1_2ndMux_r2_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_1_R1_1stMux_r2_g1, \
	   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_1_R1_1stMux_r2_g2, \
	   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_1_R1_1stMux_r2_g3, \
	   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_1_R1_2ndMux_r2_g1, \
	   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_1_R1_2ndMux_r2_g2, \
	   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_1_R1_2ndMux_r2_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_2_R1_1stMux_r2_g1, \
	   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_2_R1_1stMux_r2_g2, \
	   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_2_R1_1stMux_r2_g3, \
	   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_2_R1_2ndMux_r2_g1, \
	   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_2_R1_2ndMux_r2_g2, \
	   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_2_R1_2ndMux_r2_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_3_R1_1stMux_r2_g1, \
	   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_3_R1_1stMux_r2_g2, \
	   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_3_R1_1stMux_r2_g3, \
	   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_3_R1_2ndMux_r2_g1, \
	   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_3_R1_2ndMux_r2_g2, \
	   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_3_R1_2ndMux_r2_g3, \
	  }, \
	 }, \
	 .R1_CR_R3G_MUX1_2 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_0_R1_1stMux_r3_g1, \
	   .tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_0_R1_1stMux_r3_g2, \
	   .tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_0_R1_1stMux_r3_g3, \
	   .tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_0_R1_2ndMux_r3_g1, \
	   .tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_0_R1_2ndMux_r3_g2, \
	   .tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_0_R1_2ndMux_r3_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_1_R1_1stMux_r3_g1, \
	   .tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_1_R1_1stMux_r3_g2, \
	   .tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_1_R1_1stMux_r3_g3, \
	   .tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_1_R1_2ndMux_r3_g1, \
	   .tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_1_R1_2ndMux_r3_g2, \
	   .tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_1_R1_2ndMux_r3_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_2_R1_1stMux_r3_g1, \
	   .tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_2_R1_1stMux_r3_g2, \
	   .tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_2_R1_1stMux_r3_g3, \
	   .tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_2_R1_2ndMux_r3_g1, \
	   .tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_2_R1_2ndMux_r3_g2, \
	   .tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_2_R1_2ndMux_r3_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_3_R1_1stMux_r3_g1, \
	   .tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_3_R1_1stMux_r3_g2, \
	   .tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_3_R1_1stMux_r3_g3, \
	   .tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_3_R1_2ndMux_r3_g1, \
	   .tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_3_R1_2ndMux_r3_g2, \
	   .tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_3_R1_2ndMux_r3_g3, \
	  }, \
	 }, \
	 .R1_CR_R1G_MUX3_4 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_0_R1_3rdMux_r1_g1, \
	   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_0_R1_3rdMux_r1_g2, \
	   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_0_R1_3rdMux_r1_g3, \
	   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_0_R1_4thMux_r1_g1, \
	   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_0_R1_4thMux_r1_g2, \
	   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_0_R1_4thMux_r1_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_1_R1_3rdMux_r1_g1, \
	   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_1_R1_3rdMux_r1_g2, \
	   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_1_R1_3rdMux_r1_g3, \
	   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_1_R1_4thMux_r1_g1, \
	   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_1_R1_4thMux_r1_g2, \
	   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_1_R1_4thMux_r1_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_2_R1_3rdMux_r1_g1, \
	   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_2_R1_3rdMux_r1_g2, \
	   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_2_R1_3rdMux_r1_g3, \
	   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_2_R1_4thMux_r1_g1, \
	   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_2_R1_4thMux_r1_g2, \
	   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_2_R1_4thMux_r1_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_3_R1_3rdMux_r1_g1, \
	   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_3_R1_3rdMux_r1_g2, \
	   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_3_R1_3rdMux_r1_g3, \
	   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_3_R1_4thMux_r1_g1, \
	   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_3_R1_4thMux_r1_g2, \
	   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_3_R1_4thMux_r1_g3, \
	  }, \
	 }, \
	 .R1_CR_R2G_MUX3_4 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_0_R1_3rdMux_r2_g1, \
	   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_0_R1_3rdMux_r2_g2, \
	   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_0_R1_3rdMux_r2_g3, \
	   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_0_R1_4thMux_r2_g1, \
	   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_0_R1_4thMux_r2_g2, \
	   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_0_R1_4thMux_r2_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_1_R1_3rdMux_r2_g1, \
	   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_1_R1_3rdMux_r2_g2, \
	   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_1_R1_3rdMux_r2_g3, \
	   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_1_R1_4thMux_r2_g1, \
	   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_1_R1_4thMux_r2_g2, \
	   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_1_R1_4thMux_r2_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_2_R1_3rdMux_r2_g1, \
	   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_2_R1_3rdMux_r2_g2, \
	   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_2_R1_3rdMux_r2_g3, \
	   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_2_R1_4thMux_r2_g1, \
	   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_2_R1_4thMux_r2_g2, \
	   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_2_R1_4thMux_r2_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_3_R1_3rdMux_r2_g1, \
	   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_3_R1_3rdMux_r2_g2, \
	   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_3_R1_3rdMux_r2_g3, \
	   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_3_R1_4thMux_r2_g1, \
	   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_3_R1_4thMux_r2_g2, \
	   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_3_R1_4thMux_r2_g3, \
	  }, \
	 }, \
	 .R1_CR_R3G_MUX3_4 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_0_R1_3rdMux_r3_g1, \
	   .tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_0_R1_3rdMux_r3_g2, \
	   .tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_0_R1_3rdMux_r3_g3, \
	   .tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_0_R1_4thMux_r3_g1, \
	   .tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_0_R1_4thMux_r3_g2, \
	   .tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_0_R1_4thMux_r3_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_1_R1_3rdMux_r3_g1, \
	   .tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_1_R1_3rdMux_r3_g2, \
	   .tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_1_R1_3rdMux_r3_g3, \
	   .tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_1_R1_4thMux_r3_g1, \
	   .tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_1_R1_4thMux_r3_g2, \
	   .tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_1_R1_4thMux_r3_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_2_R1_3rdMux_r3_g1, \
	   .tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_2_R1_3rdMux_r3_g2, \
	   .tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_2_R1_3rdMux_r3_g3, \
	   .tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_2_R1_4thMux_r3_g1, \
	   .tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_2_R1_4thMux_r3_g2, \
	   .tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_2_R1_4thMux_r3_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_3_R1_3rdMux_r3_g1, \
	   .tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_3_R1_3rdMux_r3_g2, \
	   .tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_3_R1_3rdMux_r3_g3, \
	   .tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_3_R1_4thMux_r3_g1, \
	   .tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_3_R1_4thMux_r3_g2, \
	   .tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_3_R1_4thMux_r3_g3, \
	  }, \
	 }, \
	 .R1_CR_R1G_MUX5_6 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_0_R1_5thMux_r1_g1, \
	   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_0_R1_5thMux_r1_g2, \
	   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_0_R1_5thMux_r1_g3, \
	   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_0_R1_6thMux_r1_g1, \
	   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_0_R1_6thMux_r1_g2, \
	   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_0_R1_6thMux_r1_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_1_R1_5thMux_r1_g1, \
	   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_1_R1_5thMux_r1_g2, \
	   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_1_R1_5thMux_r1_g3, \
	   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_1_R1_6thMux_r1_g1, \
	   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_1_R1_6thMux_r1_g2, \
	   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_1_R1_6thMux_r1_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_2_R1_5thMux_r1_g1, \
	   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_2_R1_5thMux_r1_g2, \
	   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_2_R1_5thMux_r1_g3, \
	   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_2_R1_6thMux_r1_g1, \
	   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_2_R1_6thMux_r1_g2, \
	   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_2_R1_6thMux_r1_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_3_R1_5thMux_r1_g1, \
	   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_3_R1_5thMux_r1_g2, \
	   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_3_R1_5thMux_r1_g3, \
	   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_3_R1_6thMux_r1_g1, \
	   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_3_R1_6thMux_r1_g2, \
	   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_3_R1_6thMux_r1_g3, \
	  }, \
	 }, \
	 .R1_CR_R2G_MUX5_6 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_0_R1_5thMux_r2_g1, \
	   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_0_R1_5thMux_r2_g2, \
	   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_0_R1_5thMux_r2_g3, \
	   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_0_R1_6thMux_r2_g1, \
	   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_0_R1_6thMux_r2_g2, \
	   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_0_R1_6thMux_r2_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_1_R1_5thMux_r2_g1, \
	   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_1_R1_5thMux_r2_g2, \
	   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_1_R1_5thMux_r2_g3, \
	   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_1_R1_6thMux_r2_g1, \
	   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_1_R1_6thMux_r2_g2, \
	   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_1_R1_6thMux_r2_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_2_R1_5thMux_r2_g1, \
	   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_2_R1_5thMux_r2_g2, \
	   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_2_R1_5thMux_r2_g3, \
	   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_2_R1_6thMux_r2_g1, \
	   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_2_R1_6thMux_r2_g2, \
	   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_2_R1_6thMux_r2_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_3_R1_5thMux_r2_g1, \
	   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_3_R1_5thMux_r2_g2, \
	   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_3_R1_5thMux_r2_g3, \
	   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_3_R1_6thMux_r2_g1, \
	   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_3_R1_6thMux_r2_g2, \
	   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_3_R1_6thMux_r2_g3, \
	  }, \
	 }, \
	 .R1_CR_R3G_MUX5_6 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_0_R1_5thMux_r3_g1, \
	   .tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_0_R1_5thMux_r3_g2, \
	   .tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_0_R1_5thMux_r3_g3, \
	   .tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_0_R1_6thMux_r3_g1, \
	   .tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_0_R1_6thMux_r3_g2, \
	   .tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_0_R1_6thMux_r3_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_1_R1_5thMux_r3_g1, \
	   .tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_1_R1_5thMux_r3_g2, \
	   .tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_1_R1_5thMux_r3_g3, \
	   .tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_1_R1_6thMux_r3_g1, \
	   .tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_1_R1_6thMux_r3_g2, \
	   .tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_1_R1_6thMux_r3_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_2_R1_5thMux_r3_g1, \
	   .tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_2_R1_5thMux_r3_g2, \
	   .tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_2_R1_5thMux_r3_g3, \
	   .tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_2_R1_6thMux_r3_g1, \
	   .tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_2_R1_6thMux_r3_g2, \
	   .tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_2_R1_6thMux_r3_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_3_R1_5thMux_r3_g1, \
	   .tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_3_R1_5thMux_r3_g2, \
	   .tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_3_R1_5thMux_r3_g3, \
	   .tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_3_R1_6thMux_r3_g1, \
	   .tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_3_R1_6thMux_r3_g2, \
	   .tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_3_R1_6thMux_r3_g3, \
	  }, \
	 }, \
	 .R1_CR_R1G_MUX7_8 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_0_R1_7thMux_r1_g1, \
	   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_0_R1_7thMux_r1_g2, \
	   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_0_R1_7thMux_r1_g3, \
	   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_0_R1_8thMux_r1_g1, \
	   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_0_R1_8thMux_r1_g2, \
	   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_0_R1_8thMux_r1_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_1_R1_7thMux_r1_g1, \
	   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_1_R1_7thMux_r1_g2, \
	   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_1_R1_7thMux_r1_g3, \
	   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_1_R1_8thMux_r1_g1, \
	   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_1_R1_8thMux_r1_g2, \
	   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_1_R1_8thMux_r1_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_2_R1_7thMux_r1_g1, \
	   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_2_R1_7thMux_r1_g2, \
	   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_2_R1_7thMux_r1_g3, \
	   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_2_R1_8thMux_r1_g1, \
	   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_2_R1_8thMux_r1_g2, \
	   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_2_R1_8thMux_r1_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_3_R1_7thMux_r1_g1, \
	   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_3_R1_7thMux_r1_g2, \
	   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_3_R1_7thMux_r1_g3, \
	   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_3_R1_8thMux_r1_g1, \
	   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_3_R1_8thMux_r1_g2, \
	   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_3_R1_8thMux_r1_g3, \
	  }, \
	 }, \
	 .R1_CR_R2G_MUX7_8 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_0_R1_7thMux_r2_g1, \
	   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_0_R1_7thMux_r2_g2, \
	   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_0_R1_7thMux_r2_g3, \
	   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_0_R1_8thMux_r2_g1, \
	   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_0_R1_8thMux_r2_g2, \
	   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_0_R1_8thMux_r2_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_1_R1_7thMux_r2_g1, \
	   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_1_R1_7thMux_r2_g2, \
	   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_1_R1_7thMux_r2_g3, \
	   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_1_R1_8thMux_r2_g1, \
	   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_1_R1_8thMux_r2_g2, \
	   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_1_R1_8thMux_r2_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_2_R1_7thMux_r2_g1, \
	   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_2_R1_7thMux_r2_g2, \
	   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_2_R1_7thMux_r2_g3, \
	   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_2_R1_8thMux_r2_g1, \
	   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_2_R1_8thMux_r2_g2, \
	   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_2_R1_8thMux_r2_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_3_R1_7thMux_r2_g1, \
	   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_3_R1_7thMux_r2_g2, \
	   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_3_R1_7thMux_r2_g3, \
	   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_3_R1_8thMux_r2_g1, \
	   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_3_R1_8thMux_r2_g2, \
	   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_3_R1_8thMux_r2_g3, \
	  }, \
	 }, \
	 .R1_CR_R3G_MUX7_8 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux7_r3g1 = PARAMSET_ROIC_0_R1_7thMux_r3_g1, \
	   .tBit.r1_cr_mux7_r3g2 = PARAMSET_ROIC_0_R1_7thMux_r3_g2, \
	   .tBit.r1_cr_mux7_r3g3 = PARAMSET_ROIC_0_R1_7thMux_r3_g3, \
	   .tBit.r1_cr_mux8_r3g1 = PARAMSET_ROIC_0_R1_8thMux_r3_g1, \
	   .tBit.r1_cr_mux8_r3g2 = PARAMSET_ROIC_0_R1_8thMux_r3_g2, \
	   .tBit.r1_cr_mux8_r3g3 = PARAMSET_ROIC_0_R1_8thMux_r3_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux7_r3g1 = PARAMSET_ROIC_1_R1_7thMux_r3_g1, \
	   .tBit.r1_cr_mux7_r3g2 = PARAMSET_ROIC_1_R1_7thMux_r3_g2, \
	   .tBit.r1_cr_mux7_r3g3 = PARAMSET_ROIC_1_R1_7thMux_r3_g3, \
	   .tBit.r1_cr_mux8_r3g1 = PARAMSET_ROIC_1_R1_8thMux_r3_g1, \
	   .tBit.r1_cr_mux8_r3g2 = PARAMSET_ROIC_1_R1_8thMux_r3_g2, \
	   .tBit.r1_cr_mux8_r3g3 = PARAMSET_ROIC_1_R1_8thMux_r3_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux7_r3g1 = PARAMSET_ROIC_2_R1_7thMux_r3_g1, \
	   .tBit.r1_cr_mux7_r3g2 = PARAMSET_ROIC_2_R1_7thMux_r3_g2, \
	   .tBit.r1_cr_mux7_r3g3 = PARAMSET_ROIC_2_R1_7thMux_r3_g3, \
	   .tBit.r1_cr_mux8_r3g1 = PARAMSET_ROIC_2_R1_8thMux_r3_g1, \
	   .tBit.r1_cr_mux8_r3g2 = PARAMSET_ROIC_2_R1_8thMux_r3_g2, \
	   .tBit.r1_cr_mux8_r3g3 = PARAMSET_ROIC_2_R1_8thMux_r3_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux7_r3g1 = PARAMSET_ROIC_3_R1_7thMux_r3_g1, \
	   .tBit.r1_cr_mux7_r3g2 = PARAMSET_ROIC_3_R1_7thMux_r3_g2, \
	   .tBit.r1_cr_mux7_r3g3 = PARAMSET_ROIC_3_R1_7thMux_r3_g3, \
	   .tBit.r1_cr_mux8_r3g1 = PARAMSET_ROIC_3_R1_8thMux_r3_g1, \
	   .tBit.r1_cr_mux8_r3g2 = PARAMSET_ROIC_3_R1_8thMux_r3_g2, \
	   .tBit.r1_cr_mux8_r3g3 = PARAMSET_ROIC_3_R1_8thMux_r3_g3, \
	  }, \
	 }, \
	 .R1_CR_R1G_MUX9_10 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_0_R1_9thMux_r1_g1, \
	   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_0_R1_9thMux_r1_g2, \
	   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_0_R1_9thMux_r1_g3, \
	   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_0_R1_10thMux_r1_g1, \
	   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_0_R1_10thMux_r1_g2, \
	   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_0_R1_10thMux_r1_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_1_R1_9thMux_r1_g1, \
	   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_1_R1_9thMux_r1_g2, \
	   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_1_R1_9thMux_r1_g3, \
	   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_1_R1_10thMux_r1_g1, \
	   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_1_R1_10thMux_r1_g2, \
	   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_1_R1_10thMux_r1_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_2_R1_9thMux_r1_g1, \
	   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_2_R1_9thMux_r1_g2, \
	   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_2_R1_9thMux_r1_g3, \
	   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_2_R1_10thMux_r1_g1, \
	   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_2_R1_10thMux_r1_g2, \
	   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_2_R1_10thMux_r1_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_3_R1_9thMux_r1_g1, \
	   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_3_R1_9thMux_r1_g2, \
	   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_3_R1_9thMux_r1_g3, \
	   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_3_R1_10thMux_r1_g1, \
	   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_3_R1_10thMux_r1_g2, \
	   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_3_R1_10thMux_r1_g3, \
	  }, \
	 }, \
	 .R1_CR_R2G_MUX9_10 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_0_R1_9thMux_r2_g1, \
	   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_0_R1_9thMux_r2_g2, \
	   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_0_R1_9thMux_r2_g3, \
	   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_0_R1_10thMux_r2_g1, \
	   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_0_R1_10thMux_r2_g2, \
	   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_0_R1_10thMux_r2_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_1_R1_9thMux_r2_g1, \
	   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_1_R1_9thMux_r2_g2, \
	   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_1_R1_9thMux_r2_g3, \
	   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_1_R1_10thMux_r2_g1, \
	   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_1_R1_10thMux_r2_g2, \
	   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_1_R1_10thMux_r2_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_2_R1_9thMux_r2_g1, \
	   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_2_R1_9thMux_r2_g2, \
	   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_2_R1_9thMux_r2_g3, \
	   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_2_R1_10thMux_r2_g1, \
	   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_2_R1_10thMux_r2_g2, \
	   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_2_R1_10thMux_r2_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_3_R1_9thMux_r2_g1, \
	   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_3_R1_9thMux_r2_g2, \
	   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_3_R1_9thMux_r2_g3, \
	   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_3_R1_10thMux_r2_g1, \
	   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_3_R1_10thMux_r2_g2, \
	   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_3_R1_10thMux_r2_g3, \
	  }, \
	 }, \
	 .R1_CR_R3G_MUX9_10 = \
	 { \
	  [0] = { \
	   .tBit.r1_cr_mux9_r3g1 = PARAMSET_ROIC_0_R1_9thMux_r3_g1, \
	   .tBit.r1_cr_mux9_r3g2 = PARAMSET_ROIC_0_R1_9thMux_r3_g2, \
	   .tBit.r1_cr_mux9_r3g3 = PARAMSET_ROIC_0_R1_9thMux_r3_g3, \
	   .tBit.r1_cr_mux10_r3g1 = PARAMSET_ROIC_0_R1_10thMux_r3_g1, \
	   .tBit.r1_cr_mux10_r3g2 = PARAMSET_ROIC_0_R1_10thMux_r3_g2, \
	   .tBit.r1_cr_mux10_r3g3 = PARAMSET_ROIC_0_R1_10thMux_r3_g3, \
	  }, \
	  [1] = { \
	   .tBit.r1_cr_mux9_r3g1 = PARAMSET_ROIC_1_R1_9thMux_r3_g1, \
	   .tBit.r1_cr_mux9_r3g2 = PARAMSET_ROIC_1_R1_9thMux_r3_g2, \
	   .tBit.r1_cr_mux9_r3g3 = PARAMSET_ROIC_1_R1_9thMux_r3_g3, \
	   .tBit.r1_cr_mux10_r3g1 = PARAMSET_ROIC_1_R1_10thMux_r3_g1, \
	   .tBit.r1_cr_mux10_r3g2 = PARAMSET_ROIC_1_R1_10thMux_r3_g2, \
	   .tBit.r1_cr_mux10_r3g3 = PARAMSET_ROIC_1_R1_10thMux_r3_g3, \
	  }, \
	  [2] = { \
	   .tBit.r1_cr_mux9_r3g1 = PARAMSET_ROIC_2_R1_9thMux_r3_g1, \
	   .tBit.r1_cr_mux9_r3g2 = PARAMSET_ROIC_2_R1_9thMux_r3_g2, \
	   .tBit.r1_cr_mux9_r3g3 = PARAMSET_ROIC_2_R1_9thMux_r3_g3, \
	   .tBit.r1_cr_mux10_r3g1 = PARAMSET_ROIC_2_R1_10thMux_r3_g1, \
	   .tBit.r1_cr_mux10_r3g2 = PARAMSET_ROIC_2_R1_10thMux_r3_g2, \
	   .tBit.r1_cr_mux10_r3g3 = PARAMSET_ROIC_2_R1_10thMux_r3_g3, \
	  }, \
	  [3] = { \
	   .tBit.r1_cr_mux9_r3g1 = PARAMSET_ROIC_3_R1_9thMux_r3_g1, \
	   .tBit.r1_cr_mux9_r3g2 = PARAMSET_ROIC_3_R1_9thMux_r3_g2, \
	   .tBit.r1_cr_mux9_r3g3 = PARAMSET_ROIC_3_R1_9thMux_r3_g3, \
	   .tBit.r1_cr_mux10_r3g1 = PARAMSET_ROIC_3_R1_10thMux_r3_g1, \
	   .tBit.r1_cr_mux10_r3g2 = PARAMSET_ROIC_3_R1_10thMux_r3_g2, \
	   .tBit.r1_cr_mux10_r3g3 = PARAMSET_ROIC_3_R1_10thMux_r3_g3, \
	  }, \
	 }, \
	 .R1_CR_GTUNE1 = \
	 { \
	  [0] = { \
	   .tBit.r1_fig_mux1_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_MUX1_Global_Tune, \
	   .tBit.r1_fig_mux2_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_MUX2_Global_Tune, \
	   .tBit.r1_fig_mux3_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_MUX3_Global_Tune, \
	   .tBit.r1_fig_mux4_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_MUX4_Global_Tune, \
	   .tBit.r1_fig_mux5_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_MUX5_Global_Tune, \
	   .tBit.r1_fig_mux6_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_MUX6_Global_Tune, \
	   .tBit.r1_fig_mux7_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_MUX7_Global_Tune, \
	   .tBit.r1_fig_mux8_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_MUX8_Global_Tune, \
	   .tBit.r1_fig_mux9_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_MUX9_Global_Tune, \
	   .tBit.r1_fig_mux10_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_MUX10_Global_Tune, \
	  }, \
	  [1] = { \
	   .tBit.r1_fig_mux1_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_MUX1_Global_Tune, \
	   .tBit.r1_fig_mux2_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_MUX2_Global_Tune, \
	   .tBit.r1_fig_mux3_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_MUX3_Global_Tune, \
	   .tBit.r1_fig_mux4_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_MUX4_Global_Tune, \
	   .tBit.r1_fig_mux5_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_MUX5_Global_Tune, \
	   .tBit.r1_fig_mux6_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_MUX6_Global_Tune, \
	   .tBit.r1_fig_mux7_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_MUX7_Global_Tune, \
	   .tBit.r1_fig_mux8_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_MUX8_Global_Tune, \
	   .tBit.r1_fig_mux9_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_MUX9_Global_Tune, \
	   .tBit.r1_fig_mux10_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_MUX10_Global_Tune, \
	  }, \
	  [2] = { \
	   .tBit.r1_fig_mux1_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_MUX1_Global_Tune, \
	   .tBit.r1_fig_mux2_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_MUX2_Global_Tune, \
	   .tBit.r1_fig_mux3_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_MUX3_Global_Tune, \
	   .tBit.r1_fig_mux4_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_MUX4_Global_Tune, \
	   .tBit.r1_fig_mux5_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_MUX5_Global_Tune, \
	   .tBit.r1_fig_mux6_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_MUX6_Global_Tune, \
	   .tBit.r1_fig_mux7_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_MUX7_Global_Tune, \
	   .tBit.r1_fig_mux8_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_MUX8_Global_Tune, \
	   .tBit.r1_fig_mux9_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_MUX9_Global_Tune, \
	   .tBit.r1_fig_mux10_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_MUX10_Global_Tune, \
	  }, \
	  [3] = { \
	   .tBit.r1_fig_mux1_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_MUX1_Global_Tune, \
	   .tBit.r1_fig_mux2_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_MUX2_Global_Tune, \
	   .tBit.r1_fig_mux3_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_MUX3_Global_Tune, \
	   .tBit.r1_fig_mux4_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_MUX4_Global_Tune, \
	   .tBit.r1_fig_mux5_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_MUX5_Global_Tune, \
	   .tBit.r1_fig_mux6_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_MUX6_Global_Tune, \
	   .tBit.r1_fig_mux7_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_MUX7_Global_Tune, \
	   .tBit.r1_fig_mux8_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_MUX8_Global_Tune, \
	   .tBit.r1_fig_mux9_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_MUX9_Global_Tune, \
	   .tBit.r1_fig_mux10_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_MUX10_Global_Tune, \
	  }, \
	 }, \
	 .R1_CR_GTUNE2 = \
	 { \
	  [0] = { \
	   .tBit.r1_pen_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Pen_Global_Tune, \
	   .tBit.r1_pdrv_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_PRE_DRV_Global_Tune, \
	  }, \
	  [1] = { \
	   .tBit.r1_pen_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Pen_Global_Tune, \
	   .tBit.r1_pdrv_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_PRE_DRV_Global_Tune, \
	  }, \
	  [2] = { \
	   .tBit.r1_pen_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Pen_Global_Tune, \
	   .tBit.r1_pdrv_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_PRE_DRV_Global_Tune, \
	  }, \
	  [3] = { \
	   .tBit.r1_pen_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Pen_Global_Tune, \
	   .tBit.r1_pdrv_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_PRE_DRV_Global_Tune, \
	  }, \
	 }, \
	 .R1_TUNE_GROUP_SEL1 = \
	 { \
	  .tBit.r1_cr_mux1_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux1_row1_gsel, \
	  .tBit.r1_cr_mux1_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux1_row2_gsel, \
	  .tBit.r1_cr_mux1_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux1_row3_gsel, \
	  .tBit.r1_cr_mux1_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux1_row4_gsel, \
	  .tBit.r1_cr_mux1_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux1_row5_gsel, \
	  .tBit.r1_cr_mux2_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux2_row1_gsel, \
	  .tBit.r1_cr_mux2_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux2_row2_gsel, \
	  .tBit.r1_cr_mux2_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux2_row3_gsel, \
	  .tBit.r1_cr_mux2_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux2_row4_gsel, \
	  .tBit.r1_cr_mux2_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux2_row5_gsel, \
	  .tBit.r1_cr_mux3_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux3_row1_gsel, \
	  .tBit.r1_cr_mux3_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux3_row2_gsel, \
	  .tBit.r1_cr_mux3_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux3_row3_gsel, \
	  .tBit.r1_cr_mux3_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux3_row4_gsel, \
	  .tBit.r1_cr_mux3_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux3_row5_gsel, \
	 }, \
	 .R1_TUNE_GROUP_SEL2 = \
	 { \
	  .tBit.r1_cr_mux4_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux4_row1_gsel, \
	  .tBit.r1_cr_mux4_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux4_row2_gsel, \
	  .tBit.r1_cr_mux4_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux4_row3_gsel, \
	  .tBit.r1_cr_mux4_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux4_row4_gsel, \
	  .tBit.r1_cr_mux4_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux4_row5_gsel, \
	  .tBit.r1_cr_mux5_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux5_row1_gsel, \
	  .tBit.r1_cr_mux5_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux5_row2_gsel, \
	  .tBit.r1_cr_mux5_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux5_row3_gsel, \
	  .tBit.r1_cr_mux5_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux5_row4_gsel, \
	  .tBit.r1_cr_mux5_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux5_row5_gsel, \
	  .tBit.r1_cr_mux6_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux6_row1_gsel, \
	  .tBit.r1_cr_mux6_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux6_row2_gsel, \
	  .tBit.r1_cr_mux6_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux6_row3_gsel, \
	  .tBit.r1_cr_mux6_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux6_row4_gsel, \
	  .tBit.r1_cr_mux6_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux6_row5_gsel, \
	 }, \
	 .R1_TUNE_GROUP_SEL3 = \
	 { \
	  .tBit.r1_cr_mux7_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux7_row1_gsel, \
	  .tBit.r1_cr_mux7_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux7_row2_gsel, \
	  .tBit.r1_cr_mux7_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux7_row3_gsel, \
	  .tBit.r1_cr_mux7_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux7_row4_gsel, \
	  .tBit.r1_cr_mux7_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux7_row5_gsel, \
	  .tBit.r1_cr_mux8_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux8_row1_gsel, \
	  .tBit.r1_cr_mux8_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux8_row2_gsel, \
	  .tBit.r1_cr_mux8_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux8_row3_gsel, \
	  .tBit.r1_cr_mux8_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux8_row4_gsel, \
	  .tBit.r1_cr_mux8_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux8_row5_gsel, \
	  .tBit.r1_cr_mux9_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux9_row1_gsel, \
	  .tBit.r1_cr_mux9_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux9_row2_gsel, \
	  .tBit.r1_cr_mux9_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux9_row3_gsel, \
	  .tBit.r1_cr_mux9_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux9_row4_gsel, \
	  .tBit.r1_cr_mux9_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux9_row5_gsel, \
	 }, \
	 .R1_TUNE_GROUP_SEL4 = \
	 { \
	  .tBit.r1_cr_mux10_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux10_row1_gsel, \
	  .tBit.r1_cr_mux10_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux10_row2_gsel, \
	  .tBit.r1_cr_mux10_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux10_row3_gsel, \
	  .tBit.r1_cr_mux10_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux10_row4_gsel, \
	  .tBit.r1_cr_mux10_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux10_row5_gsel, \
	  .tBit.r1_cr_col1_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col1_gsel, \
	  .tBit.r1_cr_col2_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col2_gsel, \
	  .tBit.r1_cr_col3_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col3_gsel, \
	  .tBit.r1_cr_col4_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col4_gsel, \
	  .tBit.r1_cr_col5_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col5_gsel, \
	  .tBit.r1_cr_col6_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col5_gsel, \
	 }, \
	 .R1_ADC_IN_CTL = \
	 { \
	  .tBit.r1_adc_in = PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_in, \
	  .tBit.r1_adc_op_opt = PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_op_opt, \
	 }, \
	 .R1_ADC_SENSE_CTL1 = \
	 { \
	  .tBit.r1_fig_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_fig_lv_adc_ref_bcon, \
	  .tBit.r1_pp_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pp_lv_adc_ref_bcon, \
	  .tBit.r1_tilt_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_tilt_lv_adc_ref_bcon, \
	  .tBit.r1_pd_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pd_lv_adc_ref_bcon, \
	  .tBit.r1_pdrv_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pdrv_lv_adc_ref_bcon, \
	  .tBit.r1_fig_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_fig_lv_adc_bcon, \
	  .tBit.r1_pp_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pp_lv_adc_bcon, \
	  .tBit.r1_tilt_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_tilt_lv_adc_bcon, \
	  .tBit.r1_pd_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pd_lv_adc_bcon, \
	  .tBit.r1_pdrv_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL1_pdrv_lv_adc_bcon, \
	 }, \
	 .R1_ADC_SENSE_CTL2 = \
	 { \
	  .tBit.r1_fig_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_comp_bias_ctl, \
	  .tBit.r1_pp_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_comp_bias_ctl, \
	  .tBit.r1_tilt_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_tilt_adc_comp_bias_ctl, \
	  .tBit.r1_pd_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_comp_bias_ctl, \
	  .tBit.r1_pdrv_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_comp_bias_ctl, \
	  .tBit.r1_fig_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_mdac_comp_ctl, \
	  .tBit.r1_pp_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_mdac_comp_ctl, \
	  .tBit.r1_tilt_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_tilt_adc_mdac_comp_ctl, \
	  .tBit.r1_pd_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_mdac_comp_ctl, \
	  .tBit.r1_pdrv_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_mdac_comp_ctl, \
	  .tBit.r1_fig_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_mdac_slew_ctl, \
	  .tBit.r1_pp_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_mdac_slew_ctl, \
	  .tBit.r1_pd_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_mdac_slew_ctl, \
	  .tBit.r1_tilt_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_tilt_adc_mdac_slew_ctl, \
	  .tBit.r1_pdrv_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_mdac_slew_ctl, \
	  .tBit.r1_fig_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_fig_adc_ref_idrv_ctl, \
	  .tBit.r1_pp_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pp_adc_ref_idrv_ctl, \
	  .tBit.r1_pd_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pd_adc_ref_idrv_ctl, \
	  .tBit.r1_tilt_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_tilt_adc_ref_idrv_ctl, \
	  .tBit.r1_pdrv_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL2_pdrv_adc_ref_idrv_ctl, \
	  .tBit.r1_adc_clk_div_1p5 = PARAMSET_ROIC_ADC_SENSE_CTL2_adc_clk_div_1p5, \
	  .tBit.r1_adc_stc_insel = PARAMSET_ROIC_ADC_SENSE_CTL_adc_stc_insel, \
	 }, \
	 .R1_AFE_SENSE_CTL1 = \
	 { \
	  .tBit.r1_fig_cvc1_comp =PARAMSET_ROIC_AFE_SENSE_CTL1_fig_cvc1_comp, \
	  .tBit.r1_pen_cvc1_comp =PARAMSET_ROIC_AFE_SENSE_CTL1_pen_cvc1_comp, \
	  .tBit.r1_pdrv_cvc1_comp =PARAMSET_ROIC_AFE_SENSE_CTL1_pdrv_cvc1_comp, \
	  .tBit.r1_fig_int_ref =PARAMSET_ROIC_AFE_SENSE_CTL1_fig_int_ref, \
	  .tBit.r1_pen_int_ref =PARAMSET_ROIC_AFE_SENSE_CTL1_pen_int_ref, \
	  .tBit.r1_fig_sha_ref =PARAMSET_ROIC_AFE_SENSE_CTL1_fig_sha_ref, \
	  .tBit.r1_pen_sha_ref =PARAMSET_ROIC_AFE_SENSE_CTL1_pen_sha_ref, \
	 }, \
	 .R1_AFE_SENSE_CTL2 = \
	 { \
	  .tBit.r1_fig_cvc1_gc =PARAMSET_ROIC_AFE_SENSE_CTL2_fig_cvc1_gc, \
	  .tBit.r1_pp_cvc1_gc_con =PARAMSET_ROIC_AFE_SENSE_CTL2_pp_cvc1_gc_con, \
	  .tBit.r1_pd_cvc1_gc_con =PARAMSET_ROIC_AFE_SENSE_CTL2_pd_cvc1_gc_con, \
	  .tBit.r1_tilt_cvc1_gc_con =PARAMSET_ROIC_AFE_SENSE_CTL2_tilt_cvc1_gc_con, \
	  .tBit.r1_pp_cvc1_gc_hov =PARAMSET_ROIC_AFE_SENSE_CTL2_pp_cvc1_gc_hov, \
	  .tBit.r1_pd_cvc1_gc_hov =PARAMSET_ROIC_AFE_SENSE_CTL2_pd_cvc1_gc_hov, \
	  .tBit.r1_tilt_cvc1_gc_hov =PARAMSET_ROIC_AFE_SENSE_CTL2_tilt_cvc1_gc_hov, \
	  .tBit.r1_pdrv_cvc1_gc_con =PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_cvc1_gc_con, \
	  .tBit.r1_pdrv_cvc1_gc_hov =PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_cvc1_gc_hov, \
	 }, \
	 .R1_AFE_SENSE_CTL3 = \
	 { \
	  .tBit.r1_fig_cvc2_gc = PARAMSET_ROIC_AFE_SENSE_CTL3_fig_cvc2_gc, \
	  .tBit.r1_pp_cvc2_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL3_pp_cvc2_gc_con, \
	  .tBit.r1_pd_cvc2_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL3_pd_cvc2_gc_con, \
	  .tBit.r1_tilt_cvc2_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL3_tilt_cvc2_gc_con, \
	  .tBit.r1_pp_cvc2_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL3_pp_cvc2_gc_hov, \
	  .tBit.r1_pd_cvc2_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL3_pd_cvc2_gc_hov, \
	  .tBit.r1_tilt_cvc2_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL3_tilt_cvc2_gc_hov, \
	  .tBit.r1_pdrv_cvc2_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL3_pdrv_cvc2_gc_con, \
	  .tBit.r1_pdrv_cvc2_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL3_pdrv_cvc2_gc_hov, \
	 }, \
	 .R1_AFE_SENSE_CTL4 = \
	 { \
	  .tBit.r1_fig_int_gc = PARAMSET_ROIC_AFE_SENSE_CTL4_fig_int_gc, \
	  .tBit.r1_pp_int_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_gc_con, \
	  .tBit.r1_pd_int_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_gc_con, \
	  .tBit.r1_tilt_int_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_gc_con, \
	  .tBit.r1_pp_int_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_gc_hov, \
	  .tBit.r1_pd_int_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_gc_hov, \
	  .tBit.r1_tilt_int_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_gc_hov, \
	  .tBit.r1_fig_int_half = PARAMSET_ROIC_AFE_SENSE_CTL4_fig_int_half, \
	  .tBit.r1_pp_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_half_con, \
	  .tBit.r1_pd_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_half_con, \
	  .tBit.r1_tilt_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_half_con, \
	  .tBit.r1_pp_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_pp_int_half_hov, \
	  .tBit.r1_pd_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_pd_int_half_hov, \
	  .tBit.r1_tilt_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_tilt_int_half_hov, \
	  .tBit.r1_pdrv_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL4_pdrv_int_half_con, \
	  .tBit.r1_pdrv_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL4_pdrv_int_half_hov, \
	 }, \
	 .R1_AFE_SENSE_CTL5 = \
	 { \
	  .tBit.r1_fig_hv_ssu_bcon_cvc1 = PARAMSET_ROIC_AFE_SENSE_CTL5_fig_hv_ssu_bcon_cvc1, \
	  .tBit.r1_pen_hv_ssu_bcon_cvc1 = PARAMSET_ROIC_AFE_SENSE_CTL5_pen_hv_ssu_bcon_cvc1, \
	  .tBit.r1_pdrv_hv_ssu_bcon_cvc1 = PARAMSET_ROIC_AFE_SENSE_CTL5_pdrv_hv_ssu_bcon_cvc1, \
	  .tBit.r1_fig_hv_ssu_bcon_cvc2 = PARAMSET_ROIC_AFE_SENSE_CTL5_fig_hv_ssu_bcon_cvc2, \
	  .tBit.r1_pen_hv_ssu_bcon_cvc2 = PARAMSET_ROIC_AFE_SENSE_CTL5_pen_hv_ssu_bcon_cvc2, \
	  .tBit.r1_pdrv_hv_ssu_bcon_cvc2 = PARAMSET_ROIC_AFE_SENSE_CTL5_pdrv_hv_ssu_bcon_cvc2, \
	  .tBit.r1_fig_lv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL5_fig_lv_ssu_bcon, \
	  .tBit.r1_pen_lv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL5_pen_lv_ssu_bcon, \
	  .tBit.r1_fig_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL5_fig_lv_ssu_bcons, \
	  .tBit.r1_pp_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL5_pp_lv_ssu_bcons, \
	  .tBit.r1_tilt_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL5_tilt_lv_ssu_bcons, \
	  .tBit.r1_pd_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL5_pd_lv_ssu_bcons, \
	  .tBit.r1_lv_ssu_bconp = PARAMSET_ROIC_AFE_SENSE_CTL5_lv_ssu_bconp, \
	  .tBit.r1_lv_ssu_bconp_buf = PARAMSET_ROIC_AFE_SENSE_CTL5_lv_ssu_bconp_buf, \
	  .tBit.r1_ref_bcon = PARAMSET_ROIC_AFE_SENSE_CTL5_ref_bcon, \
	 }, \
	 .R1_PDB_CTL = \
	 { \
	  .tBit.r1_pdb_hvbias = PARAMSET_ROIC_PDB_CTL_pdb_hvbias, \
	  .tBit.r1_pdb_hvc = PARAMSET_ROIC_PDB_CTL_pdb_hvc, \
	  .tBit.r1_pdb_lvbias = PARAMSET_ROIC_PDB_CTL_pdb_lvbias, \
	  .tBit.r1_pdb_int = PARAMSET_ROIC_PDB_CTL_pdb_int, \
	  .tBit.r1_pdb_sha = PARAMSET_ROIC_PDB_CTL_pdb_sha, \
	  .tBit.r1_bgr_en = PARAMSET_ROIC_PDB_CTL_pdb_bgr_en, \
	  .tBit.r1_bias_en = PARAMSET_ROIC_PDB_CTL_pdb_bias_en, \
	  .tBit.r1_pdb_adc = PARAMSET_ROIC_PDB_CTL_pdb_adc, \
	  .tBit.r1_pdb_phd = PARAMSET_ROIC_PDB_CTL_pdb_phd, \
	  .tBit.r1_pdb_phd_buf = PARAMSET_ROIC_PDB_CTL_pdb_phd_buf, \
	  .tBit.r1_stuck_hvbias = PARAMSET_ROIC_PDB_CTL_stuck_hvbias, \
	  .tBit.r1_stuck_hvc = PARAMSET_ROIC_PDB_CTL_stuck_hvc, \
	  .tBit.r1_stuck_lvbias = PARAMSET_ROIC_PDB_CTL_stuck_lvbias, \
	  .tBit.r1_stuck_int = PARAMSET_ROIC_PDB_CTL_stuck_int, \
	  .tBit.r1_stuck_sha = PARAMSET_ROIC_PDB_CTL_stuck_sha, \
	  .tBit.r1_stuck_bgr_en = PARAMSET_ROIC_PDB_CTL_stuck_bgr_en, \
	  .tBit.r1_stuck_bias_en = PARAMSET_ROIC_PDB_CTL_stuck_bias_en, \
	  .tBit.r1_stuck_adc = PARAMSET_ROIC_PDB_CTL_stuck_adc, \
	  .tBit.r1_stuck_phd = PARAMSET_ROIC_PDB_CTL_stuck_phd, \
	  .tBit.r1_stuck_phd_buf = PARAMSET_ROIC_PDB_CTL_stuck_phd_buf, \
	 }, \
	 .R1_TG_STUCK = \
	 { \
	  .tBit.r1_stuck_cvc1_drv = PARAMSET_ROIC_TG_STUCK_stuck_cvc1_drv, \
	  .tBit.r1_stuck_cvc1_drv_d = PARAMSET_ROIC_TG_STUCK_stuck_cvc1_drv_d, \
	  .tBit.r1_stuck_rstp = PARAMSET_ROIC_TG_STUCK_stuck_rstp, \
	  .tBit.r1_stuck_phtcr = PARAMSET_ROIC_TG_STUCK_stuck_phtcr, \
	  .tBit.r1_stuck_vcr = PARAMSET_ROIC_TG_STUCK_stuck_vcr, \
	  .tBit.r1_stuck_rsti = PARAMSET_ROIC_TG_STUCK_stuck_rsti, \
	  .tBit.r1_stuck_phth0 = PARAMSET_ROIC_TG_STUCK_stuck_phth0, \
	  .tBit.r1_stuck_phth1 = PARAMSET_ROIC_TG_STUCK_stuck_phth1, \
	  .tBit.r1_stuck_pht0 = PARAMSET_ROIC_TG_STUCK_stuck_pht0, \
	  .tBit.r1_stuck_pht1 = PARAMSET_ROIC_TG_STUCK_stuck_pht1, \
	  .tBit.r1_fig_vcr_inv_en = PARAMSET_ROIC_TG_STUCK_fig_vcr_inv_en, \
	  .tBit.r1_pen_vcr_inv_en = PARAMSET_ROIC_TG_STUCK_pen_vcr_inv_en, \
	  .tBit.r1_fig_stuck_vcr_en_odd = PARAMSET_ROIC_TG_STUCK_fig_stuck_vcr_en_odd, \
	  .tBit.r1_pen_stuck_vcr_en_odd = PARAMSET_ROIC_TG_STUCK_pen_stuck_vcr_en_odd, \
	  .tBit.r1_fig_stuck_vcr_en_even = PARAMSET_ROIC_TG_STUCK_fig_stuck_vcr_en_even, \
	  .tBit.r1_pen_stuck_vcr_en_even = PARAMSET_ROIC_TG_STUCK_pen_stuck_vcr_en_even, \
	 }, \
	 .R1_TEST_MUX_CTL = \
	 { \
	  .tBit.r1_tm_mon_en = 0, \
	  .tBit.r1_tm_mon_s = 0, \
	  .tBit.r1_tm_ps_ev = 0, \
	  .tBit.r1_tm_ps_od = 0, \
	  .tBit.r1_tm_ssu_pen = 0, \
	  .tBit.r1_test_adc_a = 0, \
	  .tBit.r1_test_adc_b = 0, \
	  .tBit.r1_tm_cr = 0, \
	  .tBit.r1_tm_phd_cr_en = 0, \
	  .tBit.r1_tm_phd_cr00 = 0, \
	  .tBit.r1_tm_phd_cr54 = 0, \
	 }, \
	 .R1_RESERVE = \
	 { \
	  .tBit.r1_reserve = 0, \
	 }, \
	 .R1_PHD_SENSE_CTL1 = \
	 { \
	  .tBit.r1_phd_in_s = PARAMSET_ROIC_PHD_SENSE_CTL1_phd_in_s, \
	  .tBit.r1_phd_en = PARAMSET_ROIC_PHD_SENSE_CTL1_phd_en, \
	  .tBit.r1_rst_phd_en = PARAMSET_ROIC_PHD_SENSE_CTL1_rst_phd_en, \
	  .tBit.r1_phd_gc_con = PARAMSET_ROIC_PHD_SENSE_CTL1_phd_gc_con, \
	  .tBit.r1_phd_gc_hov = PARAMSET_ROIC_PHD_SENSE_CTL1_phd_gc_hov, \
	  .tBit.r1_phd_md = PARAMSET_ROIC_PHD_SENSE_CTL1_phd_md, \
	  .tBit.r1_adc_in_phd = PARAMSET_ROIC_PHD_SENSE_CTL1_adc_in_phd, \
	  .tBit.r1_stuck_rst_phd = PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_rst_phd, \
	  .tBit.r1_stuck_adc_in_phd = PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_adc_in_phd, \
	  .tBit.r1_stuck_phd_md = PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_phd_md, \
	  .tBit.r1_stuck_phd_en = PARAMSET_ROIC_PHD_SENSE_CTL1_stuck_phd_en, \
	  .tBit.r1_max_phd_dly_sel = PARAMSET_ROIC_PHD_SENSE_CTL1_max_phd_dly_sel, \
	 }, \
	 .R1_PHD_CTL1 = \
	 { \
	  .tBit.r1_adc_skipnum_hov = PARAMSET_ROIC_PHD_CTL1_r1_adc_skipnum_hov, \
	  .tBit.r1_adc_th_hov = PARAMSET_ROIC_PHD_CTL1_r1_adc_th_hov, \
	  .tBit.r1_bypass_en_hov = PARAMSET_ROIC_PHD_CTL1_r1_bypass_en_hov, \
	  .tBit.r1_coef_val1_hov = PARAMSET_ROIC_PHD_CTL1_r1_coef_val1_hov, \
	  .tBit.r1_coef_val2_hov = PARAMSET_ROIC_PHD_CTL1_r1_coef_val2_hov, \
	 }, \
	 .R1_PHD_CTL2 = \
	 { \
	  .tBit.r1_dly_th_hov = PARAMSET_ROIC_PHD_CTL2_r1_dly_th_hov, \
	  .tBit.r1_offset_dly_hov = PARAMSET_ROIC_PHD_CTL2_r1_offset_dly_hov, \
	  .tBit.r1_invalid_dly_hov = PARAMSET_ROIC_PHD_CTL2_r1_invalid_dly_hov, \
	  .tBit.r1_max_phd_dly_hov = PARAMSET_ROIC_PHD_CTL2_r1_max_phd_dly_hov, \
	 }, \
	 .R1_PHD_CTL3 = \
	 { \
	  .tBit.r1_adc_skipnum_con = PARAMSET_ROIC_PHD_CTL3_r1_adc_skipnum_con, \
	  .tBit.r1_adc_th_con = PARAMSET_ROIC_PHD_CTL3_r1_adc_th_con, \
	  .tBit.r1_bypass_en_con = PARAMSET_ROIC_PHD_CTL3_r1_bypass_en_con, \
	  .tBit.r1_coef_val1_con = PARAMSET_ROIC_PHD_CTL3_r1_coef_val1_con, \
	  .tBit.r1_coef_val2_con = PARAMSET_ROIC_PHD_CTL3_r1_coef_val2_con, \
	 }, \
	 .R1_PHD_CTL4 = \
	 { \
	  .tBit.r1_dly_th_con = PARAMSET_ROIC_PHD_CTL4_r1_dly_th_con, \
	  .tBit.r1_offset_dly_con = PARAMSET_ROIC_PHD_CTL4_r1_offset_dly_con, \
	  .tBit.r1_invalid_dly_con = PARAMSET_ROIC_PHD_CTL4_r1_invalid_dly_con, \
	  .tBit.r1_max_phd_dly_con = PARAMSET_ROIC_PHD_CTL4_r1_max_phd_dly_con, \
	 }, \
	 .APEN_CFCLK_ON = \
	 { \
	  .tBit.apen_cfclk_on = PARAMSET_ROIC_CFGR_APEN_CFCLK_ON_apen_cfclk_on, \
	 }, \

#define SRIC_Conf_Set        SRIC_WGPPEN_Conf_Set

#endif

#endif

