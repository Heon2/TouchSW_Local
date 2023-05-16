/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _SW98502_parampreset.h
 * created on : 12. 8. 2020
 * Author : mhjang
 *
 * All rights RESERVED.
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
 * POSSIBILITY OF SUCH D.
 *******************************************************************************************************/

#ifndef __SW98502_PARAMETERSET_H_
#define __SW98502_PARAMETERSET_H_

#if (USED_ROIC_DEF == ROIC_SW98502)
#define SRIC_WGPPEN_Conf_Set \
	.SPIS_CFG = \
	{ \
		.tBit.chksum_opt = 1, \
		.tBit.spis_irq_en = 1, \
	}, \
	.SPIS_ERROR_CLR = \
	{ \
		.tBit.spi_chksum_clr = 0, \
		.tBit.tsync_fault_clr = 0, \
		.tBit.pwm_fault_clr = 0, \
	}, \
	.SPIS_PAD_CTL = \
	{ \
		.tBit.miso_ds = 0, \
		.tBit.miso_dout = 0, \
		.tBit.miso_func = 0, \
		.tBit.mosi_ds = 0, \
		.tBit.mosi_dout = 0, \
		.tBit.mosi_func = 0, \
		.tBit.tattn_out = 0, \
		.tBit.tattn_oe = 0, \
		.tBit.tattn_ds = 0, \
		.tBit.tattn_func = 0, \
		.tBit.tattn_sel0 = 0, \
		.tBit.tattn_sel1 = 1, \
		.tBit.tattn_func2 = 0, \
		.tBit.pad_tattn_test = 0, \
	}, \
	.SYS_CFG = \
	{ \
		.tBit.tg_reset = 0, \
		.tBit.sw_reset = 0, \
		.tBit.tg_clk_all_on = 1, \
		.tBit.buf_clk_on = 1, \
		.tBit.cfclk_on = 0, \
	}, \
	.TC_START = \
	{ \
		.tBit.tc_start = 0, \
	}, \
	.R0_CH_EN = \
	{ \
		.tBit.r0_dum_drv_en = 0, \
		.tBit.r0_ch_en_int = 127, \
		.tBit.r0_ch_en_hvr = 511, \
		.tBit.r0_ch_en_hvc = 511, \
	}, \
	.R1_CH_EN = \
	{ \
		.tBit.r1_dum_drv_en = 0, \
		.tBit.r1_ch_en_int = 127, \
		.tBit.r1_ch_en_hvr = 511, \
		.tBit.r1_ch_en_hvc = 511, \
	}, \
	.CH_NUM = \
	{ \
		.tBit.fig_ch_num = PARAMSET_ROIC_CFGR_CH_NUM_fig_ch_num, \
		.tBit.pp_ch_num = PARAMSET_ROIC_CFGR_CH_NUM_pp_ch_num, \
		.tBit.pd_ch_num = PARAMSET_ROIC_CFGR_CH_NUM_pd_ch_num, \
		.tBit.pdrv_ch_num = PARAMSET_ROIC_CFGR_CH_NUM_pdrv_ch_num, \
	}, \
	.MUX_CTL = \
	{ \
		.tBit.tot_mux_num = 5, \
		.tBit.mux_int_en = 0, \
		.tBit.mux_int_stuck_val = 0, \
		.tBit.top_mux_num = 0, \
		.tBit.bot_mux_num = 5, \
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
		.tBit.mux_7_dly = 0, \
		.tBit.mux_8_dly = 0, \
		.tBit.mux_9_dly = 0, \
		.tBit.mux_10_dly = 0, \
	}, \
	.MUX_DLY_2 = \
	{ \
		.tBit.mux_m1_even_dly = 0, \
		.tBit.mux_m1_odd_dly = 0, \
		.tBit.mux_nd_dly = 0, \
		.tBit.pen_mux_dly = 0, \
	}, \
	.SDIC_CFG = \
	{ \
		.tBit.vsync_pol = 0, \
		.tBit.vsync_tg_en = 0, \
		.tBit.vsync_tg_act = 0, \
		.tBit.tsync_in_pol = 0, \
		.tBit.tsync_out_pol = 0, \
		.tBit.tsync_out_bypass = 1, \
		.tBit.tsync_out_stuck = 0, \
		.tBit.tsync_out_level = 0, \
		.tBit.pwm_pol = 0, \
		.tBit.sd_off_en = 0, \
		.tBit.sd_float_en = 0, \
		.tBit.sd_gnd_en = 0, \
		.tBit.sd_off_ctl = 0, \
		.tBit.sd_float_ctl = 0, \
		.tBit.sd_gnd_ctl = 0, \
		.tBit.stuck_abd = 0, \
		.tBit.abd = 0, \
		.tBit.abd_pol = 0, \
		.tBit.abd_inv = 1, \
	}, \
	.PWM_FIG_CTL = \
	{ \
		.tBit.pwm_fig_act_num = PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_act_num, \
		.tBit.pwm_fig_mgap_num = PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_mgap_num, \
		.tBit.pwm_fig_dum_num = PARAMSET_ROIC_CFGR_PWM_FIG_CTL_pwm_dum_num, \
	}, \
	.PWM_POS_CTL = \
	{ \
		.tBit.pwm_pos_pdrv_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_pdrv_num, \
		.tBit.pwm_pos_act_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_act_num, \
		.tBit.pwm_pos_mgap_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_mgap_num, \
		.tBit.pwm_pos_dum_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_dum_num, \
	}, \
	.PWM_DAT_CTL = \
	{ \
		.tBit.pwm_dat_pdrv_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_pdrv_num, \
		.tBit.pwm_dat_pre_act_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_pre_act_num, \
		.tBit.pwm_dat_act_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_act_num, \
		.tBit.pwm_dat_mgap_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_mgap_num, \
		.tBit.pwm_dat_dum_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_dum_num, \
	}, \
	.PWM_ND_CTL = \
	{ \
		.tBit.pwm_nd_pdrv_num = 0, \
		.tBit.pwm_nd_act_num = 6, \
		.tBit.pwm_nd_mgap_num = 1, \
		.tBit.pwm_nd_dum_num = 7, \
	}, \
	.PWM_PRD = \
	{ \
		.tBit.fig_pwm_prd = PARAMSET_ROIC_CFGR_PWM_PRD_fig_pwm_prd, \
		.tBit.pen_pwm_prd = PARAMSET_ROIC_CFGR_PWM_PRD_pen_pwm_prd, \
		.tBit.nd_pwm_prd = 46, \
	}, \
	.SMPL_CTL = \
	{ \
		.tBit.fig_smop_prd = 7, \
		.tBit.pen_smop_prd = 7, \
		.tBit.nd_smop_prd = 7, \
		.tBit.cr_repeat_num = 0, \
	}, \
	.RSTP_RISE_NUM = \
	{ \
		.tBit.fig_rstp_rise_num = PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_fig_rstp_rise_num, \
		.tBit.pen_rstp_rise_num = PARAMSET_ROIC_CFGR_RSTP_RISE_NUM_pen_rstp_rise_num, \
		.tBit.nd_rstp_rise_num = 14, \
	}, \
	.RSTP_FALL_NUM1 = \
	{ \
		.tBit.fig_rstp_fall_num1 = PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num1, \
		.tBit.pen_rstp_fall_num1 = PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num1, \
		.tBit.nd_rstp_fall_num1 = 3, \
	}, \
	.RSTP_FALL_NUM2 = \
	{ \
		.tBit.fig_rstp_fall_num2 = PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_fig_rstp_fall_num2, \
		.tBit.pen_rstp_fall_num2 = PARAMSET_ROIC_CFGR_RSTP_FALL_NUM_pen_rstp_fall_num2, \
		.tBit.nd_rstp_fall_num2 = 3, \
	}, \
	.PHTCR_RISE_NUM = \
	{ \
		.tBit.fig_phtcr_rise_num = PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_fig_phtcr_rise_num, \
		.tBit.pen_phtcr_rise_num = PARAMSET_ROIC_CFGR_PHTCR_RISE_NUM_pen_phtcr_rise_num, \
		.tBit.nd_phtcr_rise_num = 44, \
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
		.tBit.nd_vcr_num = 40, \
	}, \
	.RSTI_RISE_NUM = \
	{ \
		.tBit.fig_rsti_rise_num = PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_fig_rsti_rise_num, \
		.tBit.pen_rsti_rise_num = PARAMSET_ROIC_CFGR_RSTI_RISE_NUM_pen_rsti_rise_num, \
		.tBit.nd_rsti_rise_num = 53, \
	}, \
	.RSTI_FALL_NUM1 = \
	{ \
		.tBit.fig_rsti_fall_num1 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_fig_rsti_fall_num1, \
		.tBit.pen_rsti_fall_num1 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_pen_rsti_fall_num1, \
		.tBit.nd_rsti_fall_num1 = 27, \
	}, \
	.RSTI_FALL_NUM2 = \
	{ \
		.tBit.fig_rsti_fall_num2 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_fig_rsti_fall_num2, \
		.tBit.pen_rsti_fall_num2 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_pen_rsti_fall_num2, \
		.tBit.nd_rsti_fall_num2 = 27, \
	}, \
	.PHTH0_RISE_NUM = \
	{ \
		.tBit.fig_phth0_rise_num = PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_fig_phth0_rise_num, \
		.tBit.pen_phth0_rise_num = PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_pen_phth0_rise_num, \
		.tBit.nd_phth0_rise_num = 17, \
	}, \
	.PHTH0_FALL_NUM = \
	{ \
		.tBit.fig_phth0_fall_num = PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_fig_phth0_fall_num, \
		.tBit.pen_phth0_fall_num = PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_pen_phth0_fall_num, \
		.tBit.nd_phth0_fall_num = 16, \
	}, \
	.PHTH1_RISE_NUM = \
	{ \
		.tBit.fig_phth1_rise_num = PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_fig_phth1_rise_num, \
		.tBit.pen_phth1_rise_num = PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_pen_phth1_rise_num, \
		.tBit.nd_phth1_rise_num = 16, \
	}, \
	.PHTH1_FALL_NUM = \
	{ \
		.tBit.fig_phth1_fall_num = PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_fig_phth1_fall_num, \
		.tBit.pen_phth1_fall_num = PARAMSET_ROIC_CFGR_PHTH1_FALL_NUM_pen_phth1_fall_num, \
		.tBit.nd_phth1_fall_num = 16, \
	}, \
	.PHT_CTL = \
	{ \
		.tBit.pht_prd = 6, \
		.tBit.pht_opt_inv = 1, \
		.tBit.pht_end_time = 10, \
		.tBit.pht_act_en = 0, \
		.tBit.pht_act_pwm_num = 0, \
		.tBit.pht_act_pwr_num = 0, \
		.tBit.fig_pre_pht_sel = 0, \
		.tBit.pen_pos_pre_pht_sel = 0, \
		.tBit.pen_dat_pre_pht_sel = 0, \
		.tBit.nd_pre_pht_sel = 0, \
	}, \
	.PHT_RISE_NUM = \
	{ \
		.tBit.fig_pht_rise_num = PARAMSET_ROIC_CFGR_RISE_PHT_NUM_fig_pht_rise_num, \
		.tBit.pen_pht_rise_num = PARAMSET_ROIC_CFGR_RISE_PHT_NUM_pen_pht_rise_num, \
		.tBit.nd_pht_rise_num = 23, \
	}, \
	.PHT_FALL_NUM = \
	{ \
		.tBit.fig_pht_fall_num = PARAMSET_ROIC_CFGR_FALL_PHT_NUM_fig_pht_fall_num, \
		.tBit.pen_pht_fall_num = PARAMSET_ROIC_CFGR_FALL_PHT_NUM_pen_pht_fall_num, \
		.tBit.nd_pht_fall_num = 17, \
	}, \
	.ADC_CTL1 = \
	{ \
		.tBit.adc_op_opt = PARAMSET_ROIC_CFGR_ADC_CTL1_adc_op_opt, \
		.tBit.adc_clk_opt = PARAMSET_ROIC_CFGR_ADC_CTL1_adc_clk_opt, \
		.tBit.adc_clk_pol = PARAMSET_ROIC_CFGR_ADC_CTL1_adc_clk_pol, \
		.tBit.fig_adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTL1_fig_adc_clk_prd, \
		.tBit.pen_adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTL1_pen_adc_clk_prd, \
		.tBit.pdrv_adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTL1_pdrv_adc_clk_prd, \
		.tBit.fig_conv_smpl_num = PARAMSET_ROIC_CFGR_ADC_CTL1_fig_conv_smpl_num, \
		.tBit.pen_conv_smpl_num = PARAMSET_ROIC_CFGR_ADC_CTL1_pen_conv_smpl_num, \
		.tBit.pdrv_conv_smpl_num = PARAMSET_ROIC_CFGR_ADC_CTL1_pdrv_conv_smpl_num, \
		.tBit.adc_clk_spt = PARAMSET_ROIC_CFGR_ADC_CTL1_adc_clk_spt, \
		.tBit.phd_adc_done_skip = PARAMSET_ROIC_CFGR_ADC_CTL1_phd_adc_done_skip, \
	}, \
	.ADC_CTL2 = \
	{ \
		.tBit.adc_stc_dly = PARAMSET_ROIC_CFGR_ADC_CTL2_adc_stc_dly, \
		.tBit.adc_sgap_num = PARAMSET_ROIC_CFGR_ADC_CTL2_adc_sgap_num, \
		.tBit.adc_stc_prd = PARAMSET_ROIC_CFGR_ADC_CTL2_adc_stc_prd, \
		.tBit.adc_pgap_num = PARAMSET_ROIC_CFGR_ADC_CTL2_adc_pgap_num, \
		.tBit.adc_in_pos = PARAMSET_ROIC_CFGR_ADC_CTL2_adc_in_pos, \
		.tBit.adc_clk_num = PARAMSET_ROIC_CFGR_ADC_CTL2_adc_clk_num, \
	}, \
	.ADC_CTL3 = \
	{ \
		.tBit.pdrv_adc_stc_dly = PARAMSET_ROIC_CFGR_ADC_CTL3_pdrv_adc_stc_dly, \
		.tBit.pdrv_adc_sgap_num = PARAMSET_ROIC_CFGR_ADC_CTL3_pdrv_adc_sgap_num, \
		.tBit.pdrv_adc_stc_prd = PARAMSET_ROIC_CFGR_ADC_CTL3_pdrv_adc_stc_prd, \
		.tBit.pdrv_adc_pgap_num = PARAMSET_ROIC_CFGR_ADC_CTL3_pdrv_adc_pgap_num, \
	}, \
	.VCOMR_OPT = \
	{ \
		.tBit.display_vcomr = 0, \
		.tBit.touch_f_vcomr = 0, \
		.tBit.touch_p_vcomr = 0, \
		.tBit.stuck_vcomr_left = 0, \
		.tBit.stuck_vcomr_right = 0, \
		.tBit.stuck_vcomr_level = 0, \
		.tBit.tsync_opt = 0, \
	}, \
	.BUF_OPT = \
	{ \
		.tBit.double_buf_en = 1, \
		.tBit.pre_drv_en = 0, \
	}, \
	.TG_STUCK = \
	{ \
		.tBit.stuck_rstp = 0, \
		.tBit.stuck_phtcr = 0, \
		.tBit.stuck_vcr = 0, \
		.tBit.stuck_rsti = 0, \
		.tBit.stuck_phth0 = 0, \
		.tBit.stuck_phth1 = 0, \
		.tBit.stuck_pht0 = 0, \
		.tBit.stuck_pht1 = 0, \
		.tBit.r0_fig_stuck_vcr_en_odd = 1, \
		.tBit.r0_pen_stuck_vcr_en_odd = 0, \
		.tBit.r1_fig_stuck_vcr_en_odd = 1, \
		.tBit.r1_pen_stuck_vcr_en_odd = 0, \
		.tBit.r0_fig_stuck_vcr_en_even = 1, \
		.tBit.r0_pen_stuck_vcr_en_even = 0, \
		.tBit.r1_fig_stuck_vcr_en_even = 1, \
		.tBit.r1_pen_stuck_vcr_en_even = 0, \
		.tBit.stuck_muxs_en = 0, \
		.tBit.stuck_muxf_en = 0, \
		.tBit.vcr_inv_en = 0, \
		.tBit.fig_vcr_off_en = 0, \
		.tBit.fig_phtcr_off_en = 0, \
		.tBit.pen_vcr_off_en = 1, \
		.tBit.pen_phtcr_off_en = 1, \
	}, \
	.ADC_IN = \
	{ \
		.tBit.adc_in = 1, \
	}, \
	.MUX_S_STUCK_VAL = \
	{ \
		.tBit.mux_s_stuck = 0, \
		.tBit.mux_s_line_stuck = 0, \
	}, \
	.MUX_F_STUCK_VAL = \
	{ \
		.tBit.mux_f_stuck_val = 0, \
	}, \
	.FIG_MUX_CFG_00 = \
	{ \
		.tBit.fig_mux_00 = 0, \
		.tBit.fig_mux_01 = 1, \
		.tBit.fig_mux_02 = 2, \
		.tBit.fig_mux_03 = 3, \
		.tBit.fig_mux_04 = 4, \
		.tBit.fig_mux_05 = 5, \
		.tBit.fig_mux_06 = 6, \
		.tBit.fig_mux_07 = 7, \
	}, \
	.FIG_MUX_CFG_01 = \
	{ \
		.tBit.fig_mux_08 = 8, \
		.tBit.fig_mux_09 = 9, \
		.tBit.fig_mux_10 = 0, \
		.tBit.fig_mux_11 = 0, \
		.tBit.fig_mux_12 = 0, \
		.tBit.fig_mux_13 = 0, \
		.tBit.fig_mux_14 = 0, \
		.tBit.fig_mux_15 = 0, \
	}, \
	.RCOM_LHB_CFG = \
	{ \
		.tBit.nxt_lhb_mode = 0, \
		.tBit.tsync_num = 8, \
		.tBit.dum_tsync_num = 0, \
		.tBit.beacon_en = 0, \
		.tBit.rdcom_en = 0, \
		.tBit.sgap_num = 0, \
		.tBit.r0pd = 0, \
		.tBit.r1pd = 0, \
		.tBit.sel_hover = 0, \
	}, \
	.DEFA_LHB_MCFG00 = \
	{ \
		.tBit.lhb_mode01 = 1/*6*/, \
		.tBit.lhb_mode02 = 3/*0*/, \
		.tBit.lhb_mode03 = 2/*6*/, \
		.tBit.lhb_mode04 = 3/*0*/, \
		.tBit.lhb_mode05 = 0/*6*/, \
		.tBit.lhb_mode06 = 3/*0*/, \
		.tBit.lhb_mode07 = 0/*6*/, \
		.tBit.lhb_mode08 = 3/*0*/, \
	}, \
	.DEFA_LHB_MCFG01 = \
	{ \
		.tBit.lhb_mode09 = 6, \
		.tBit.lhb_mode10 = 6, \
		.tBit.lhb_mode11 = 6, \
		.tBit.lhb_mode12 = 6, \
		.tBit.lhb_mode13 = 6, \
		.tBit.lhb_mode14 = 6, \
		.tBit.lhb_mode15 = 6, \
		.tBit.lhb_mode16 = 6, \
	}, \
	.DEFA_LHB_MCFG02 = \
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
	.DEFA_LHB_MCFG03 = \
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
	.LHB_MUX_NUM = \
	{ \
		.tBit.fig_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_NUM_fig_lhb_mux_num, \
		.tBit.pen_pos1_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_NUM_pen_pos1_lhb_mux_num, \
		.tBit.pen_pos2_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_NUM_pen_pos2_lhb_mux_num, \
		.tBit.pen_dat1_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_NUM_pen_dat1_lhb_mux_num, \
		.tBit.pen_dat2_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_NUM_pen_dat2_lhb_mux_num, \
	}, \
	.PEN_POS1_LHB_CFG = \
	{ \
		.tBit.pen_pos1_mux_cfg0 = 0, \
		.tBit.pen_pos1_mux_cfg1 = 0, \
		.tBit.pen_pos1_mux_cfg2 = 0, \
		.tBit.pen_pos1_mux_cfg3 = 0, \
	}, \
	.PEN_POS2_LHB_CFG = \
	{ \
		.tBit.pen_pos2_mux_cfg0 = 0, \
		.tBit.pen_pos2_mux_cfg1 = 0, \
		.tBit.pen_pos2_mux_cfg2 = 0, \
		.tBit.pen_pos2_mux_cfg3 = 0, \
	}, \
	.PEN_DAT1_LHB_CFG = \
	{ \
		.tBit.pen_dat1_mux_cfg0 = 0, \
		.tBit.pen_dat1_mux_cfg1 = 0, \
		.tBit.pen_dat1_mux_cfg2 = 0, \
		.tBit.pen_dat1_mux_cfg3 = 0, \
		.tBit.pen_dat1_tmuxnum = 6, \
		.tBit.pen_dat1_tsync_muxnum = 0, \
	}, \
	.PEN_DAT2_LHB_CFG = \
	{ \
		.tBit.pen_dat2_mux_cfg0 = 0, \
		.tBit.pen_dat2_mux_cfg1 = 0, \
		.tBit.pen_dat2_mux_cfg2 = 0, \
		.tBit.pen_dat2_mux_cfg3 = 0, \
		.tBit.pen_dat2_tmuxnum = 0, \
		.tBit.pen_dat2_tsync_muxnum = 0, \
	}, \
	.MUX_FCTL_NUM1 = \
	{ \
		.tBit.mux_fctl_rise_num1 = PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num1, \
		.tBit.mux_fctl_rise_num2 = PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num2, \
		.tBit.fctl_rsti_off = 0, \
		.tBit.mux_off_en = 0, \
	}, \
	.MUX_FCTL_NUM2 = \
	{ \
		.tBit.mux_fctl_fall_num1 = PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num1, \
		.tBit.mux_fctl_fall_num2 = PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num2, \
	}, \
	.UPLINK_MUX = \
	{ \
		.tBit.r0_uplink_mux = PARAMSET_ROIC_CFGR_UPLINK_MUX_r0_uplink_mux, \
		.tBit.r1_uplink_mux = PARAMSET_ROIC_CFGR_UPLINK_MUX_r1_uplink_mux, \
	}, \
	.LHB_MUX_CTL = \
	{ \
		.tBit.mux_m1_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_mux_m1_bit_en, \
		.tBit.mux_nd_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_mux_nd_bit_en, \
		.tBit.mux_pp_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_mux_pp_bit_en, \
		.tBit.mux_pd_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_mux_pd_bit_en, \
		.tBit.m1_mode_sel = PARAMSET_ROIC_LHB_MUX_CTL_m1_mode_sel, \
	}, \
	.PING_MUX_CTL = \
	{ \
		.tBit.ping_max = 0, \
		.tBit.ping_pwm_num = 0, \
		.tBit.uplink_state = 0, \
		.tBit.ping_mux_sel = 0, \
		.tBit.ping_mode = 0, \
	}, \
	.PRE_DRV_CTL = \
	{ \
		.tBit.pdrv_mode = PARAMSET_ROIC_CFGR_PRE_DRV_CTL_pdrv_mode, \
		.tBit.pdrv_adc_en = 0, \
	}, \
	.R0_CR_MUX1_1 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_0_R0_1stMux_Top_Line_g1, \
			.tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_0_R0_1stMux_Top_Line_g2, \
			.tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_0_R0_1stMux_Top_Line_g3, \
			.tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g1, \
			.tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g2, \
			.tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_1_R0_1stMux_Top_Line_g1, \
			.tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_1_R0_1stMux_Top_Line_g2, \
			.tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_1_R0_1stMux_Top_Line_g3, \
			.tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g1, \
			.tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g2, \
			.tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_2_R0_1stMux_Top_Line_g1, \
			.tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_2_R0_1stMux_Top_Line_g2, \
			.tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_2_R0_1stMux_Top_Line_g3, \
			.tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g1, \
			.tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g2, \
			.tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_3_R0_1stMux_Top_Line_g1, \
			.tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_3_R0_1stMux_Top_Line_g2, \
			.tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_3_R0_1stMux_Top_Line_g3, \
			.tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g1, \
			.tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g2, \
			.tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_4_R0_1stMux_Top_Line_g1, \
			.tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_4_R0_1stMux_Top_Line_g2, \
			.tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_4_R0_1stMux_Top_Line_g3, \
			.tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g1, \
			.tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g2, \
			.tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_5_R0_1stMux_Top_Line_g1, \
			.tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_5_R0_1stMux_Top_Line_g2, \
			.tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_5_R0_1stMux_Top_Line_g3, \
			.tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g1, \
			.tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g2, \
			.tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g3, \
		}, \
	}, \
	.R0_CR_MUX1_2 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g3, \
		}, \
	}, \
	.R0_CR_MUX2_1 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_0_R0_2ndMux_Top_Line_g1, \
			.tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_0_R0_2ndMux_Top_Line_g2, \
			.tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_0_R0_2ndMux_Top_Line_g3, \
			.tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_0_R0_2ndMux_Middle_Line_g1, \
			.tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_0_R0_2ndMux_Middle_Line_g2, \
			.tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_0_R0_2ndMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_1_R0_2ndMux_Top_Line_g1, \
			.tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_1_R0_2ndMux_Top_Line_g2, \
			.tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_1_R0_2ndMux_Top_Line_g3, \
			.tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_1_R0_2ndMux_Middle_Line_g1, \
			.tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_1_R0_2ndMux_Middle_Line_g2, \
			.tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_1_R0_2ndMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_2_R0_2ndMux_Top_Line_g1, \
			.tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_2_R0_2ndMux_Top_Line_g2, \
			.tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_2_R0_2ndMux_Top_Line_g3, \
			.tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_2_R0_2ndMux_Middle_Line_g1, \
			.tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_2_R0_2ndMux_Middle_Line_g2, \
			.tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_2_R0_2ndMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_3_R0_2ndMux_Top_Line_g1, \
			.tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_3_R0_2ndMux_Top_Line_g2, \
			.tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_3_R0_2ndMux_Top_Line_g3, \
			.tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_3_R0_2ndMux_Middle_Line_g1, \
			.tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_3_R0_2ndMux_Middle_Line_g2, \
			.tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_3_R0_2ndMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_4_R0_2ndMux_Top_Line_g1, \
			.tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_4_R0_2ndMux_Top_Line_g2, \
			.tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_4_R0_2ndMux_Top_Line_g3, \
			.tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_4_R0_2ndMux_Middle_Line_g1, \
			.tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_4_R0_2ndMux_Middle_Line_g2, \
			.tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_4_R0_2ndMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_5_R0_2ndMux_Top_Line_g1, \
			.tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_5_R0_2ndMux_Top_Line_g2, \
			.tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_5_R0_2ndMux_Top_Line_g3, \
			.tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_5_R0_2ndMux_Middle_Line_g1, \
			.tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_5_R0_2ndMux_Middle_Line_g2, \
			.tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_5_R0_2ndMux_Middle_Line_g3, \
		}, \
	}, \
	.R0_CR_MUX2_2 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_0_R0_2ndMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_0_R0_2ndMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_0_R0_2ndMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_1_R0_2ndMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_1_R0_2ndMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_1_R0_2ndMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_2_R0_2ndMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_2_R0_2ndMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_2_R0_2ndMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_3_R0_2ndMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_3_R0_2ndMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_3_R0_2ndMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_4_R0_2ndMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_4_R0_2ndMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_4_R0_2ndMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_5_R0_2ndMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_5_R0_2ndMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_5_R0_2ndMux_Bottom_Line_g3, \
		}, \
	}, \
	.R0_CR_MUX3_1 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_0_R0_3rdMux_Top_Line_g1, \
			.tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_0_R0_3rdMux_Top_Line_g2, \
			.tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_0_R0_3rdMux_Top_Line_g3, \
			.tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_0_R0_3rdMux_Middle_Line_g1, \
			.tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_0_R0_3rdMux_Middle_Line_g2, \
			.tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_0_R0_3rdMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_1_R0_3rdMux_Top_Line_g1, \
			.tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_1_R0_3rdMux_Top_Line_g2, \
			.tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_1_R0_3rdMux_Top_Line_g3, \
			.tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_1_R0_3rdMux_Middle_Line_g1, \
			.tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_1_R0_3rdMux_Middle_Line_g2, \
			.tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_1_R0_3rdMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_2_R0_3rdMux_Top_Line_g1, \
			.tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_2_R0_3rdMux_Top_Line_g2, \
			.tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_2_R0_3rdMux_Top_Line_g3, \
			.tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_2_R0_3rdMux_Middle_Line_g1, \
			.tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_2_R0_3rdMux_Middle_Line_g2, \
			.tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_2_R0_3rdMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_3_R0_3rdMux_Top_Line_g1, \
			.tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_3_R0_3rdMux_Top_Line_g2, \
			.tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_3_R0_3rdMux_Top_Line_g3, \
			.tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_3_R0_3rdMux_Middle_Line_g1, \
			.tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_3_R0_3rdMux_Middle_Line_g2, \
			.tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_3_R0_3rdMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_4_R0_3rdMux_Top_Line_g1, \
			.tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_4_R0_3rdMux_Top_Line_g2, \
			.tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_4_R0_3rdMux_Top_Line_g3, \
			.tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_4_R0_3rdMux_Middle_Line_g1, \
			.tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_4_R0_3rdMux_Middle_Line_g2, \
			.tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_4_R0_3rdMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_5_R0_3rdMux_Top_Line_g1, \
			.tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_5_R0_3rdMux_Top_Line_g2, \
			.tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_5_R0_3rdMux_Top_Line_g3, \
			.tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_5_R0_3rdMux_Middle_Line_g1, \
			.tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_5_R0_3rdMux_Middle_Line_g2, \
			.tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_5_R0_3rdMux_Middle_Line_g3, \
		}, \
	}, \
	.R0_CR_MUX3_2 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_0_R0_3rdMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_0_R0_3rdMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_0_R0_3rdMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_1_R0_3rdMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_1_R0_3rdMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_1_R0_3rdMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_2_R0_3rdMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_2_R0_3rdMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_2_R0_3rdMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_3_R0_3rdMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_3_R0_3rdMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_3_R0_3rdMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_4_R0_3rdMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_4_R0_3rdMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_4_R0_3rdMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_5_R0_3rdMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_5_R0_3rdMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_5_R0_3rdMux_Bottom_Line_g3, \
		}, \
	}, \
	.R0_CR_MUX4_1 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_0_R0_4thMux_Top_Line_g1, \
			.tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_0_R0_4thMux_Top_Line_g2, \
			.tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_0_R0_4thMux_Top_Line_g3, \
			.tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_0_R0_4thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_0_R0_4thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_0_R0_4thMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_1_R0_4thMux_Top_Line_g1, \
			.tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_1_R0_4thMux_Top_Line_g2, \
			.tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_1_R0_4thMux_Top_Line_g3, \
			.tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_1_R0_4thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_1_R0_4thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_1_R0_4thMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_2_R0_4thMux_Top_Line_g1, \
			.tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_2_R0_4thMux_Top_Line_g2, \
			.tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_2_R0_4thMux_Top_Line_g3, \
			.tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_2_R0_4thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_2_R0_4thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_2_R0_4thMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_3_R0_4thMux_Top_Line_g1, \
			.tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_3_R0_4thMux_Top_Line_g2, \
			.tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_3_R0_4thMux_Top_Line_g3, \
			.tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_3_R0_4thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_3_R0_4thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_3_R0_4thMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_4_R0_4thMux_Top_Line_g1, \
			.tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_4_R0_4thMux_Top_Line_g2, \
			.tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_4_R0_4thMux_Top_Line_g3, \
			.tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_4_R0_4thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_4_R0_4thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_4_R0_4thMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_5_R0_4thMux_Top_Line_g1, \
			.tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_5_R0_4thMux_Top_Line_g2, \
			.tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_5_R0_4thMux_Top_Line_g3, \
			.tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_5_R0_4thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_5_R0_4thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_5_R0_4thMux_Middle_Line_g3, \
		}, \
	}, \
	.R0_CR_MUX4_2 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_0_R0_4thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_0_R0_4thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_0_R0_4thMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_1_R0_4thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_1_R0_4thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_1_R0_4thMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_2_R0_4thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_2_R0_4thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_2_R0_4thMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_3_R0_4thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_3_R0_4thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_3_R0_4thMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_4_R0_4thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_4_R0_4thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_4_R0_4thMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_5_R0_4thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_5_R0_4thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_5_R0_4thMux_Bottom_Line_g3, \
		}, \
	}, \
	.R0_CR_MUX5_1 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_0_R0_5thMux_Top_Line_g1, \
			.tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_0_R0_5thMux_Top_Line_g2, \
			.tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_0_R0_5thMux_Top_Line_g3, \
			.tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_0_R0_5thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_0_R0_5thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_0_R0_5thMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_1_R0_5thMux_Top_Line_g1, \
			.tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_1_R0_5thMux_Top_Line_g2, \
			.tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_1_R0_5thMux_Top_Line_g3, \
			.tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_1_R0_5thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_1_R0_5thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_1_R0_5thMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_2_R0_5thMux_Top_Line_g1, \
			.tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_2_R0_5thMux_Top_Line_g2, \
			.tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_2_R0_5thMux_Top_Line_g3, \
			.tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_2_R0_5thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_2_R0_5thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_2_R0_5thMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_3_R0_5thMux_Top_Line_g1, \
			.tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_3_R0_5thMux_Top_Line_g2, \
			.tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_3_R0_5thMux_Top_Line_g3, \
			.tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_3_R0_5thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_3_R0_5thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_3_R0_5thMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_4_R0_5thMux_Top_Line_g1, \
			.tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_4_R0_5thMux_Top_Line_g2, \
			.tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_4_R0_5thMux_Top_Line_g3, \
			.tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_4_R0_5thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_4_R0_5thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_4_R0_5thMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_5_R0_5thMux_Top_Line_g1, \
			.tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_5_R0_5thMux_Top_Line_g2, \
			.tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_5_R0_5thMux_Top_Line_g3, \
			.tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_5_R0_5thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_5_R0_5thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_5_R0_5thMux_Middle_Line_g3, \
		}, \
	}, \
	.R0_CR_MUX5_2 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_0_R0_5thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_0_R0_5thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_0_R0_5thMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_1_R0_5thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_1_R0_5thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_1_R0_5thMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_2_R0_5thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_2_R0_5thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_2_R0_5thMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_3_R0_5thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_3_R0_5thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_3_R0_5thMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_4_R0_5thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_4_R0_5thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_4_R0_5thMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_5_R0_5thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_5_R0_5thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_5_R0_5thMux_Bottom_Line_g3, \
		}, \
	}, \
	.R0_CR_MUX6_1 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_0_R0_6thMux_Top_Line_g1, \
			.tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_0_R0_6thMux_Top_Line_g2, \
			.tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_0_R0_6thMux_Top_Line_g3, \
			.tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_0_R0_6thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_0_R0_6thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_0_R0_6thMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_1_R0_6thMux_Top_Line_g1, \
			.tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_1_R0_6thMux_Top_Line_g2, \
			.tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_1_R0_6thMux_Top_Line_g3, \
			.tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_1_R0_6thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_1_R0_6thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_1_R0_6thMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_2_R0_6thMux_Top_Line_g1, \
			.tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_2_R0_6thMux_Top_Line_g2, \
			.tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_2_R0_6thMux_Top_Line_g3, \
			.tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_2_R0_6thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_2_R0_6thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_2_R0_6thMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_3_R0_6thMux_Top_Line_g1, \
			.tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_3_R0_6thMux_Top_Line_g2, \
			.tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_3_R0_6thMux_Top_Line_g3, \
			.tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_3_R0_6thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_3_R0_6thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_3_R0_6thMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_4_R0_6thMux_Top_Line_g1, \
			.tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_4_R0_6thMux_Top_Line_g2, \
			.tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_4_R0_6thMux_Top_Line_g3, \
			.tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_4_R0_6thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_4_R0_6thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_4_R0_6thMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_5_R0_6thMux_Top_Line_g1, \
			.tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_5_R0_6thMux_Top_Line_g2, \
			.tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_5_R0_6thMux_Top_Line_g3, \
			.tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_5_R0_6thMux_Middle_Line_g1, \
			.tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_5_R0_6thMux_Middle_Line_g2, \
			.tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_5_R0_6thMux_Middle_Line_g3, \
		}, \
	}, \
	.R0_CR_MUX6_2 = \
	{ \
		[0] = { \
			.tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_0_R0_6thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_0_R0_6thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_0_R0_6thMux_Bottom_Line_g3, \
		}, \
				[1] = { \
			.tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_1_R0_6thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_1_R0_6thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_1_R0_6thMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_2_R0_6thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_2_R0_6thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_2_R0_6thMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_3_R0_6thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_3_R0_6thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_3_R0_6thMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_4_R0_6thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_4_R0_6thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_4_R0_6thMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_5_R0_6thMux_Bottom_Line_g1, \
			.tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_5_R0_6thMux_Bottom_Line_g2, \
			.tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_5_R0_6thMux_Bottom_Line_g3, \
		}, \
	}, \
	.R0_CR_M1 = \
	{ \
		.tBit.r0_cr_m1_odd_g1 = 0, \
		.tBit.r0_cr_m1_odd_g2 = 0, \
		.tBit.r0_cr_m1_odd_g3 = 0, \
		.tBit.r0_cr_m1_even_g1 = 0, \
		.tBit.r0_cr_m1_even_g2 = 0, \
		.tBit.r0_cr_m1_even_g3 = 0, \
	}, \
	.R1_CR_MUX1_1 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_0_R1_1stMux_Top_Line_g1, \
			.tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_0_R1_1stMux_Top_Line_g2, \
			.tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_0_R1_1stMux_Top_Line_g3, \
			.tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g1, \
			.tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g2, \
			.tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_1_R1_1stMux_Top_Line_g1, \
			.tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_1_R1_1stMux_Top_Line_g2, \
			.tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_1_R1_1stMux_Top_Line_g3, \
			.tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g1, \
			.tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g2, \
			.tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_2_R1_1stMux_Top_Line_g1, \
			.tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_2_R1_1stMux_Top_Line_g2, \
			.tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_2_R1_1stMux_Top_Line_g3, \
			.tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g1, \
			.tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g2, \
			.tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_3_R1_1stMux_Top_Line_g1, \
			.tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_3_R1_1stMux_Top_Line_g2, \
			.tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_3_R1_1stMux_Top_Line_g3, \
			.tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g1, \
			.tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g2, \
			.tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_4_R1_1stMux_Top_Line_g1, \
			.tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_4_R1_1stMux_Top_Line_g2, \
			.tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_4_R1_1stMux_Top_Line_g3, \
			.tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g1, \
			.tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g2, \
			.tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_5_R1_1stMux_Top_Line_g1, \
			.tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_5_R1_1stMux_Top_Line_g2, \
			.tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_5_R1_1stMux_Top_Line_g3, \
			.tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g1, \
			.tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g2, \
			.tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g3, \
		}, \
	}, \
	.R1_CR_MUX1_2 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g3, \
		}, \
	}, \
	.R1_CR_MUX2_1 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_0_R1_2ndMux_Top_Line_g1, \
			.tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_0_R1_2ndMux_Top_Line_g2, \
			.tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_0_R1_2ndMux_Top_Line_g3, \
			.tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_0_R1_2ndMux_Middle_Line_g1, \
			.tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_0_R1_2ndMux_Middle_Line_g2, \
			.tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_0_R1_2ndMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_1_R1_2ndMux_Top_Line_g1, \
			.tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_1_R1_2ndMux_Top_Line_g2, \
			.tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_1_R1_2ndMux_Top_Line_g3, \
			.tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_1_R1_2ndMux_Middle_Line_g1, \
			.tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_1_R1_2ndMux_Middle_Line_g2, \
			.tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_1_R1_2ndMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_2_R1_2ndMux_Top_Line_g1, \
			.tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_2_R1_2ndMux_Top_Line_g2, \
			.tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_2_R1_2ndMux_Top_Line_g3, \
			.tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_2_R1_2ndMux_Middle_Line_g1, \
			.tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_2_R1_2ndMux_Middle_Line_g2, \
			.tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_2_R1_2ndMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_3_R1_2ndMux_Top_Line_g1, \
			.tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_3_R1_2ndMux_Top_Line_g2, \
			.tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_3_R1_2ndMux_Top_Line_g3, \
			.tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_3_R1_2ndMux_Middle_Line_g1, \
			.tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_3_R1_2ndMux_Middle_Line_g2, \
			.tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_3_R1_2ndMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_4_R1_2ndMux_Top_Line_g1, \
			.tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_4_R1_2ndMux_Top_Line_g2, \
			.tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_4_R1_2ndMux_Top_Line_g3, \
			.tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_4_R1_2ndMux_Middle_Line_g1, \
			.tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_4_R1_2ndMux_Middle_Line_g2, \
			.tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_4_R1_2ndMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_5_R1_2ndMux_Top_Line_g1, \
			.tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_5_R1_2ndMux_Top_Line_g2, \
			.tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_5_R1_2ndMux_Top_Line_g3, \
			.tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_5_R1_2ndMux_Middle_Line_g1, \
			.tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_5_R1_2ndMux_Middle_Line_g2, \
			.tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_5_R1_2ndMux_Middle_Line_g3, \
		}, \
	}, \
	.R1_CR_MUX2_2 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_0_R1_2ndMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_0_R1_2ndMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_0_R1_2ndMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_1_R1_2ndMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_1_R1_2ndMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_1_R1_2ndMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_2_R1_2ndMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_2_R1_2ndMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_2_R1_2ndMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_3_R1_2ndMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_3_R1_2ndMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_3_R1_2ndMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_4_R1_2ndMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_4_R1_2ndMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_4_R1_2ndMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_5_R1_2ndMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_5_R1_2ndMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_5_R1_2ndMux_Bottom_Line_g3, \
		}, \
	}, \
	.R1_CR_MUX3_1 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_0_R1_3rdMux_Top_Line_g1, \
			.tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_0_R1_3rdMux_Top_Line_g2, \
			.tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_0_R1_3rdMux_Top_Line_g3, \
			.tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_0_R1_3rdMux_Middle_Line_g1, \
			.tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_0_R1_3rdMux_Middle_Line_g2, \
			.tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_0_R1_3rdMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_1_R1_3rdMux_Top_Line_g1, \
			.tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_1_R1_3rdMux_Top_Line_g2, \
			.tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_1_R1_3rdMux_Top_Line_g3, \
			.tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_1_R1_3rdMux_Middle_Line_g1, \
			.tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_1_R1_3rdMux_Middle_Line_g2, \
			.tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_1_R1_3rdMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_2_R1_3rdMux_Top_Line_g1, \
			.tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_2_R1_3rdMux_Top_Line_g2, \
			.tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_2_R1_3rdMux_Top_Line_g3, \
			.tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_2_R1_3rdMux_Middle_Line_g1, \
			.tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_2_R1_3rdMux_Middle_Line_g2, \
			.tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_2_R1_3rdMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_3_R1_3rdMux_Top_Line_g1, \
			.tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_3_R1_3rdMux_Top_Line_g2, \
			.tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_3_R1_3rdMux_Top_Line_g3, \
			.tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_3_R1_3rdMux_Middle_Line_g1, \
			.tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_3_R1_3rdMux_Middle_Line_g2, \
			.tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_3_R1_3rdMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_4_R1_3rdMux_Top_Line_g1, \
			.tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_4_R1_3rdMux_Top_Line_g2, \
			.tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_4_R1_3rdMux_Top_Line_g3, \
			.tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_4_R1_3rdMux_Middle_Line_g1, \
			.tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_4_R1_3rdMux_Middle_Line_g2, \
			.tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_4_R1_3rdMux_Middle_Line_g3, \
		}, \
				[5] = { \
			.tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_5_R1_3rdMux_Top_Line_g1, \
			.tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_5_R1_3rdMux_Top_Line_g2, \
			.tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_5_R1_3rdMux_Top_Line_g3, \
			.tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_5_R1_3rdMux_Middle_Line_g1, \
			.tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_5_R1_3rdMux_Middle_Line_g2, \
			.tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_5_R1_3rdMux_Middle_Line_g3, \
		}, \
	}, \
	.R1_CR_MUX3_2 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_0_R1_3rdMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_0_R1_3rdMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_0_R1_3rdMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_1_R1_3rdMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_1_R1_3rdMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_1_R1_3rdMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_2_R1_3rdMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_2_R1_3rdMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_2_R1_3rdMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_3_R1_3rdMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_3_R1_3rdMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_3_R1_3rdMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_4_R1_3rdMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_4_R1_3rdMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_4_R1_3rdMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_5_R1_3rdMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_5_R1_3rdMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_5_R1_3rdMux_Bottom_Line_g3, \
		}, \
	}, \
	.R1_CR_MUX4_1 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_0_R1_4thMux_Top_Line_g1, \
			.tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_0_R1_4thMux_Top_Line_g2, \
			.tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_0_R1_4thMux_Top_Line_g3, \
			.tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_0_R1_4thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_0_R1_4thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_0_R1_4thMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_1_R1_4thMux_Top_Line_g1, \
			.tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_1_R1_4thMux_Top_Line_g2, \
			.tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_1_R1_4thMux_Top_Line_g3, \
			.tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_1_R1_4thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_1_R1_4thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_1_R1_4thMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_2_R1_4thMux_Top_Line_g1, \
			.tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_2_R1_4thMux_Top_Line_g2, \
			.tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_2_R1_4thMux_Top_Line_g3, \
			.tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_2_R1_4thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_2_R1_4thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_2_R1_4thMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_3_R1_4thMux_Top_Line_g1, \
			.tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_3_R1_4thMux_Top_Line_g2, \
			.tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_3_R1_4thMux_Top_Line_g3, \
			.tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_3_R1_4thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_3_R1_4thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_3_R1_4thMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_4_R1_4thMux_Top_Line_g1, \
			.tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_4_R1_4thMux_Top_Line_g2, \
			.tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_4_R1_4thMux_Top_Line_g3, \
			.tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_4_R1_4thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_4_R1_4thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_4_R1_4thMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_5_R1_4thMux_Top_Line_g1, \
			.tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_5_R1_4thMux_Top_Line_g2, \
			.tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_5_R1_4thMux_Top_Line_g3, \
			.tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_5_R1_4thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_5_R1_4thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_5_R1_4thMux_Middle_Line_g3, \
		}, \
	}, \
	.R1_CR_MUX4_2 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_0_R1_4thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_0_R1_4thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_0_R1_4thMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_1_R1_4thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_1_R1_4thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_1_R1_4thMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_2_R1_4thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_2_R1_4thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_2_R1_4thMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_3_R1_4thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_3_R1_4thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_3_R1_4thMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_4_R1_4thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_4_R1_4thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_4_R1_4thMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_5_R1_4thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_5_R1_4thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_5_R1_4thMux_Bottom_Line_g3, \
		}, \
	}, \
	.R1_CR_MUX5_1 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_0_R1_5thMux_Top_Line_g1, \
			.tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_0_R1_5thMux_Top_Line_g2, \
			.tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_0_R1_5thMux_Top_Line_g3, \
			.tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_0_R1_5thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_0_R1_5thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_0_R1_5thMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_1_R1_5thMux_Top_Line_g1, \
			.tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_1_R1_5thMux_Top_Line_g2, \
			.tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_1_R1_5thMux_Top_Line_g3, \
			.tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_1_R1_5thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_1_R1_5thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_1_R1_5thMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_2_R1_5thMux_Top_Line_g1, \
			.tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_2_R1_5thMux_Top_Line_g2, \
			.tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_2_R1_5thMux_Top_Line_g3, \
			.tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_2_R1_5thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_2_R1_5thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_2_R1_5thMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_3_R1_5thMux_Top_Line_g1, \
			.tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_3_R1_5thMux_Top_Line_g2, \
			.tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_3_R1_5thMux_Top_Line_g3, \
			.tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_3_R1_5thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_3_R1_5thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_3_R1_5thMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_4_R1_5thMux_Top_Line_g1, \
			.tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_4_R1_5thMux_Top_Line_g2, \
			.tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_4_R1_5thMux_Top_Line_g3, \
			.tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_4_R1_5thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_4_R1_5thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_4_R1_5thMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_5_R1_5thMux_Top_Line_g1, \
			.tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_5_R1_5thMux_Top_Line_g2, \
			.tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_5_R1_5thMux_Top_Line_g3, \
			.tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_5_R1_5thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_5_R1_5thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_5_R1_5thMux_Middle_Line_g3, \
		}, \
	}, \
	.R1_CR_MUX5_2 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_0_R1_5thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_0_R1_5thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_0_R1_5thMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_1_R1_5thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_1_R1_5thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_1_R1_5thMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_2_R1_5thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_2_R1_5thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_2_R1_5thMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_3_R1_5thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_3_R1_5thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_3_R1_5thMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_4_R1_5thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_4_R1_5thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_4_R1_5thMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_5_R1_5thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_5_R1_5thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_5_R1_5thMux_Bottom_Line_g3, \
		}, \
	}, \
	.R1_CR_MUX6_1 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_0_R1_6thMux_Top_Line_g1, \
			.tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_0_R1_6thMux_Top_Line_g2, \
			.tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_0_R1_6thMux_Top_Line_g3, \
			.tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_0_R1_6thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_0_R1_6thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_0_R1_6thMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_1_R1_6thMux_Top_Line_g1, \
			.tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_1_R1_6thMux_Top_Line_g2, \
			.tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_1_R1_6thMux_Top_Line_g3, \
			.tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_1_R1_6thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_1_R1_6thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_1_R1_6thMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_2_R1_6thMux_Top_Line_g1, \
			.tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_2_R1_6thMux_Top_Line_g2, \
			.tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_2_R1_6thMux_Top_Line_g3, \
			.tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_2_R1_6thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_2_R1_6thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_2_R1_6thMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_3_R1_6thMux_Top_Line_g1, \
			.tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_3_R1_6thMux_Top_Line_g2, \
			.tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_3_R1_6thMux_Top_Line_g3, \
			.tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_3_R1_6thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_3_R1_6thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_3_R1_6thMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_4_R1_6thMux_Top_Line_g1, \
			.tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_4_R1_6thMux_Top_Line_g2, \
			.tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_4_R1_6thMux_Top_Line_g3, \
			.tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_4_R1_6thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_4_R1_6thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_4_R1_6thMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_5_R1_6thMux_Top_Line_g1, \
			.tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_5_R1_6thMux_Top_Line_g2, \
			.tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_5_R1_6thMux_Top_Line_g3, \
			.tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_5_R1_6thMux_Middle_Line_g1, \
			.tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_5_R1_6thMux_Middle_Line_g2, \
			.tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_5_R1_6thMux_Middle_Line_g3, \
		}, \
	}, \
	.R1_CR_MUX6_2 = \
	{ \
		[0] = { \
			.tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_0_R1_6thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_0_R1_6thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_0_R1_6thMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_1_R1_6thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_1_R1_6thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_1_R1_6thMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_2_R1_6thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_2_R1_6thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_2_R1_6thMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_3_R1_6thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_3_R1_6thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_3_R1_6thMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_4_R1_6thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_4_R1_6thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_4_R1_6thMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_5_R1_6thMux_Bottom_Line_g1, \
			.tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_5_R1_6thMux_Bottom_Line_g2, \
			.tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_5_R1_6thMux_Bottom_Line_g3, \
		}, \
	}, \
	.R1_CR_M1 = \
	{ \
		.tBit.r1_cr_m1_odd_g1 = 0, \
		.tBit.r1_cr_m1_odd_g2 = 0, \
		.tBit.r1_cr_m1_odd_g3 = 0, \
		.tBit.r1_cr_m1_even_g1 = 0, \
		.tBit.r1_cr_m1_even_g2 = 0, \
		.tBit.r1_cr_m1_even_g3 = 0, \
	}, \
	.R_CR_ND = \
	{ \
		.tBit.r0_cr_nd_g1 = 0, \
		.tBit.r0_cr_nd_g2 = 0, \
		.tBit.r0_cr_nd_g3 = 0, \
		.tBit.r1_cr_nd_g1 = 0, \
		.tBit.r1_cr_nd_g2 = 0, \
		.tBit.r1_cr_nd_g3 = 0, \
	}, \
	.R_CR_GTUNE = \
	{ \
		[0] = { \
			.tBit.r0_top_fig_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r0_mid_fig_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r0_bot_fig_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r0_pen_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r0_pdrv_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_PRE_DRV_Global_Tune		, \
			.tBit.r1_top_fig_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r1_mid_fig_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r1_bot_fig_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r1_pen_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r1_pdrv_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_PRE_DRV_Global_Tune		, \
		}, \
		[1] = { \
			.tBit.r0_top_fig_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r0_mid_fig_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r0_bot_fig_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r0_pen_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r0_pdrv_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_PRE_DRV_Global_Tune		, \
			.tBit.r1_top_fig_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r1_mid_fig_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r1_bot_fig_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r1_pen_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r1_pdrv_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_PRE_DRV_Global_Tune		, \
		}, \
		[2] = { \
			.tBit.r0_top_fig_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r0_mid_fig_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r0_bot_fig_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r0_pen_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r0_pdrv_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_PRE_DRV_Global_Tune		, \
			.tBit.r1_top_fig_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r1_mid_fig_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r1_bot_fig_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r1_pen_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r1_pdrv_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_PRE_DRV_Global_Tune		, \
		}, \
		[3] = { \
			.tBit.r0_top_fig_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r0_mid_fig_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r0_bot_fig_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r0_pen_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r0_pdrv_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_PRE_DRV_Global_Tune		, \
			.tBit.r1_top_fig_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r1_mid_fig_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r1_bot_fig_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r1_pen_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r1_pdrv_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_PRE_DRV_Global_Tune		, \
		}, \
		[4] = { \
			.tBit.r0_top_fig_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r0_mid_fig_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r0_bot_fig_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r0_pen_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r0_pdrv_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_PRE_DRV_Global_Tune		, \
			.tBit.r1_top_fig_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r1_mid_fig_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r1_bot_fig_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r1_pen_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r1_pdrv_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_PRE_DRV_Global_Tune		, \
		}, \
		[5] = { \
			.tBit.r0_top_fig_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r0_mid_fig_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r0_bot_fig_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r0_pen_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r0_pdrv_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_PRE_DRV_Global_Tune		, \
			.tBit.r1_top_fig_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_Finger_Top_Global_Tune	, \
			.tBit.r1_mid_fig_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
			.tBit.r1_bot_fig_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
			.tBit.r1_pen_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_Pen_Global_Tune	, \
			.tBit.r1_pdrv_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_PRE_DRV_Global_Tune		, \
		}, \
	}, \
	.R0_TUNE_ROW_MUX1 = \
	{ \
		.tBit.r0_cr_mux1_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX1_r0_cr_mux1_row1_gsel, \
		.tBit.r0_cr_mux1_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX1_r0_cr_mux1_row2_gsel, \
		.tBit.r0_cr_mux1_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX1_r0_cr_mux1_row3_gsel, \
		.tBit.r0_cr_mux1_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX1_r0_cr_mux1_row4_gsel, \
		.tBit.r0_cr_mux1_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX1_r0_cr_mux1_row5_gsel, \
		.tBit.r0_cr_mux1_row6_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX1_r0_cr_mux1_row6_gsel, \
		.tBit.r0_cr_mux1_row7_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX1_r0_cr_mux1_row7_gsel, \
		.tBit.r0_cr_mux1_row8_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX1_r0_cr_mux1_row8_gsel, \
		.tBit.r0_cr_mux1_row9_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX1_r0_cr_mux1_row9_gsel, \
	}, \
	.R0_TUNE_ROW_MUX2 = \
	{ \
		.tBit.r0_cr_mux2_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX2_r0_cr_mux2_row1_gsel, \
		.tBit.r0_cr_mux2_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX2_r0_cr_mux2_row2_gsel, \
		.tBit.r0_cr_mux2_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX2_r0_cr_mux2_row3_gsel, \
		.tBit.r0_cr_mux2_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX2_r0_cr_mux2_row4_gsel, \
		.tBit.r0_cr_mux2_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX2_r0_cr_mux2_row5_gsel, \
		.tBit.r0_cr_mux2_row6_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX2_r0_cr_mux2_row6_gsel, \
		.tBit.r0_cr_mux2_row7_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX2_r0_cr_mux2_row7_gsel, \
		.tBit.r0_cr_mux2_row8_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX2_r0_cr_mux2_row8_gsel, \
		.tBit.r0_cr_mux2_row9_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX2_r0_cr_mux2_row9_gsel, \
	}, \
	.R0_TUNE_ROW_MUX3 = \
	{ \
		.tBit.r0_cr_mux3_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX3_r0_cr_mux3_row1_gsel, \
		.tBit.r0_cr_mux3_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX3_r0_cr_mux3_row2_gsel, \
		.tBit.r0_cr_mux3_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX3_r0_cr_mux3_row3_gsel, \
		.tBit.r0_cr_mux3_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX3_r0_cr_mux3_row4_gsel, \
		.tBit.r0_cr_mux3_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX3_r0_cr_mux3_row5_gsel, \
		.tBit.r0_cr_mux3_row6_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX3_r0_cr_mux3_row6_gsel, \
		.tBit.r0_cr_mux3_row7_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX3_r0_cr_mux3_row7_gsel, \
		.tBit.r0_cr_mux3_row8_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX3_r0_cr_mux3_row8_gsel, \
		.tBit.r0_cr_mux3_row9_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX3_r0_cr_mux3_row9_gsel, \
	}, \
	.R0_TUNE_ROW_MUX4 = \
	{ \
		.tBit.r0_cr_mux4_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX4_r0_cr_mux4_row1_gsel, \
		.tBit.r0_cr_mux4_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX4_r0_cr_mux4_row2_gsel, \
		.tBit.r0_cr_mux4_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX4_r0_cr_mux4_row3_gsel, \
		.tBit.r0_cr_mux4_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX4_r0_cr_mux4_row4_gsel, \
		.tBit.r0_cr_mux4_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX4_r0_cr_mux4_row5_gsel, \
		.tBit.r0_cr_mux4_row6_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX4_r0_cr_mux4_row6_gsel, \
		.tBit.r0_cr_mux4_row7_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX4_r0_cr_mux4_row7_gsel, \
		.tBit.r0_cr_mux4_row8_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX4_r0_cr_mux4_row8_gsel, \
		.tBit.r0_cr_mux4_row9_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX4_r0_cr_mux4_row9_gsel, \
	}, \
	.R0_TUNE_ROW_MUX5 = \
	{ \
		.tBit.r0_cr_mux5_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX5_r0_cr_mux5_row1_gsel, \
		.tBit.r0_cr_mux5_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX5_r0_cr_mux5_row2_gsel, \
		.tBit.r0_cr_mux5_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX5_r0_cr_mux5_row3_gsel, \
		.tBit.r0_cr_mux5_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX5_r0_cr_mux5_row4_gsel, \
		.tBit.r0_cr_mux5_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX5_r0_cr_mux5_row5_gsel, \
		.tBit.r0_cr_mux5_row6_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX5_r0_cr_mux5_row6_gsel, \
		.tBit.r0_cr_mux5_row7_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX5_r0_cr_mux5_row7_gsel, \
		.tBit.r0_cr_mux5_row8_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX5_r0_cr_mux5_row8_gsel, \
		.tBit.r0_cr_mux5_row9_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX5_r0_cr_mux5_row9_gsel, \
	}, \
	.R0_TUNE_ROW_MUX6 = \
	{ \
		.tBit.r0_cr_mux6_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX6_r0_cr_mux6_row1_gsel, \
		.tBit.r0_cr_mux6_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX6_r0_cr_mux6_row2_gsel, \
		.tBit.r0_cr_mux6_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX6_r0_cr_mux6_row3_gsel, \
		.tBit.r0_cr_mux6_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX6_r0_cr_mux6_row4_gsel, \
		.tBit.r0_cr_mux6_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX6_r0_cr_mux6_row5_gsel, \
		.tBit.r0_cr_mux6_row6_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX6_r0_cr_mux6_row6_gsel, \
		.tBit.r0_cr_mux6_row7_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX6_r0_cr_mux6_row7_gsel, \
		.tBit.r0_cr_mux6_row8_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX6_r0_cr_mux6_row8_gsel, \
		.tBit.r0_cr_mux6_row9_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX6_r0_cr_mux6_row9_gsel, \
	}, \
	.R1_TUNE_ROW_MUX1 = \
	{ \
		.tBit.r1_cr_mux1_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX1_r1_cr_mux1_row1_gsel, \
		.tBit.r1_cr_mux1_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX1_r1_cr_mux1_row2_gsel, \
		.tBit.r1_cr_mux1_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX1_r1_cr_mux1_row3_gsel, \
		.tBit.r1_cr_mux1_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX1_r1_cr_mux1_row4_gsel, \
		.tBit.r1_cr_mux1_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX1_r1_cr_mux1_row5_gsel, \
		.tBit.r1_cr_mux1_row6_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX1_r1_cr_mux1_row6_gsel, \
		.tBit.r1_cr_mux1_row7_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX1_r1_cr_mux1_row7_gsel, \
		.tBit.r1_cr_mux1_row8_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX1_r1_cr_mux1_row8_gsel, \
		.tBit.r1_cr_mux1_row9_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX1_r1_cr_mux1_row9_gsel, \
	}, \
	.R1_TUNE_ROW_MUX2 = \
	{ \
		.tBit.r1_cr_mux2_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX2_r1_cr_mux2_row1_gsel, \
		.tBit.r1_cr_mux2_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX2_r1_cr_mux2_row2_gsel, \
		.tBit.r1_cr_mux2_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX2_r1_cr_mux2_row3_gsel, \
		.tBit.r1_cr_mux2_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX2_r1_cr_mux2_row4_gsel, \
		.tBit.r1_cr_mux2_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX2_r1_cr_mux2_row5_gsel, \
		.tBit.r1_cr_mux2_row6_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX2_r1_cr_mux2_row6_gsel, \
		.tBit.r1_cr_mux2_row7_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX2_r1_cr_mux2_row7_gsel, \
		.tBit.r1_cr_mux2_row8_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX2_r1_cr_mux2_row8_gsel, \
		.tBit.r1_cr_mux2_row9_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX2_r1_cr_mux2_row9_gsel, \
	}, \
	.R1_TUNE_ROW_MUX3 = \
	{ \
		.tBit.r1_cr_mux3_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX3_r1_cr_mux3_row1_gsel, \
		.tBit.r1_cr_mux3_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX3_r1_cr_mux3_row2_gsel, \
		.tBit.r1_cr_mux3_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX3_r1_cr_mux3_row3_gsel, \
		.tBit.r1_cr_mux3_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX3_r1_cr_mux3_row4_gsel, \
		.tBit.r1_cr_mux3_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX3_r1_cr_mux3_row5_gsel, \
		.tBit.r1_cr_mux3_row6_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX3_r1_cr_mux3_row6_gsel, \
		.tBit.r1_cr_mux3_row7_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX3_r1_cr_mux3_row7_gsel, \
		.tBit.r1_cr_mux3_row8_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX3_r1_cr_mux3_row8_gsel, \
		.tBit.r1_cr_mux3_row9_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX3_r1_cr_mux3_row9_gsel, \
	}, \
	.R1_TUNE_ROW_MUX4 = \
	{ \
		.tBit.r1_cr_mux4_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX4_r1_cr_mux4_row1_gsel, \
		.tBit.r1_cr_mux4_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX4_r1_cr_mux4_row2_gsel, \
		.tBit.r1_cr_mux4_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX4_r1_cr_mux4_row3_gsel, \
		.tBit.r1_cr_mux4_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX4_r1_cr_mux4_row4_gsel, \
		.tBit.r1_cr_mux4_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX4_r1_cr_mux4_row5_gsel, \
		.tBit.r1_cr_mux4_row6_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX4_r1_cr_mux4_row6_gsel, \
		.tBit.r1_cr_mux4_row7_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX4_r1_cr_mux4_row7_gsel, \
		.tBit.r1_cr_mux4_row8_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX4_r1_cr_mux4_row8_gsel, \
		.tBit.r1_cr_mux4_row9_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX4_r1_cr_mux4_row9_gsel, \
	}, \
	.R1_TUNE_ROW_MUX5 = \
	{ \
		.tBit.r1_cr_mux5_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX5_r1_cr_mux5_row1_gsel, \
		.tBit.r1_cr_mux5_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX5_r1_cr_mux5_row2_gsel, \
		.tBit.r1_cr_mux5_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX5_r1_cr_mux5_row3_gsel, \
		.tBit.r1_cr_mux5_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX5_r1_cr_mux5_row4_gsel, \
		.tBit.r1_cr_mux5_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX5_r1_cr_mux5_row5_gsel, \
		.tBit.r1_cr_mux5_row6_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX5_r1_cr_mux5_row6_gsel, \
		.tBit.r1_cr_mux5_row7_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX5_r1_cr_mux5_row7_gsel, \
		.tBit.r1_cr_mux5_row8_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX5_r1_cr_mux5_row8_gsel, \
		.tBit.r1_cr_mux5_row9_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX5_r1_cr_mux5_row9_gsel, \
	}, \
	.R1_TUNE_ROW_MUX6 = \
	{ \
		.tBit.r1_cr_mux6_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX6_r1_cr_mux6_row1_gsel, \
		.tBit.r1_cr_mux6_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX6_r1_cr_mux6_row2_gsel, \
		.tBit.r1_cr_mux6_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX6_r1_cr_mux6_row3_gsel, \
		.tBit.r1_cr_mux6_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX6_r1_cr_mux6_row4_gsel, \
		.tBit.r1_cr_mux6_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX6_r1_cr_mux6_row5_gsel, \
		.tBit.r1_cr_mux6_row6_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX6_r1_cr_mux6_row6_gsel, \
		.tBit.r1_cr_mux6_row7_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX6_r1_cr_mux6_row7_gsel, \
		.tBit.r1_cr_mux6_row8_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX6_r1_cr_mux6_row8_gsel, \
		.tBit.r1_cr_mux6_row9_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX6_r1_cr_mux6_row9_gsel, \
	}, \
	.R_TUNE_GROUP_COL = \
	{ \
		.tBit.r0_cr_col1_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col1_gsel, \
		.tBit.r0_cr_col2_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col2_gsel, \
		.tBit.r0_cr_col3_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col3_gsel, \
		.tBit.r0_cr_col4_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col4_gsel, \
		.tBit.r0_cr_col5_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col5_gsel, \
		.tBit.r1_cr_col1_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col1_gsel, \
		.tBit.r1_cr_col2_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col2_gsel, \
		.tBit.r1_cr_col3_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col3_gsel, \
		.tBit.r1_cr_col4_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col4_gsel, \
		.tBit.r1_cr_col5_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col5_gsel, \
	}, \
	.SD_PWRCR1 = \
	{ \
		.tBit.pwrcr1 = 0, \
		.tBit.pwrcr2 = 0, \
		.tBit.pwrcr3 = 0, \
		.tBit.pwrcr4 = 0, \
		.tBit.pwrcr5 = 0, \
	}, \
	.SD_PWRCR2 = \
	{ \
		.tBit.pwrcr6 = 0, \
		.tBit.pwrcr7 = 0, \
		.tBit.pwrcr8 = 0, \
		.tBit.pwrcr9 = 0, \
		.tBit.pwrcr10 = 0, \
	}, \
	.SD_PWRCR3 = \
	{ \
		.tBit.pwrcr11 = 0, \
		.tBit.pwrcr12 = 0, \
		.tBit.pwrcr13 = 0, \
		.tBit.pwrcr14 = 0, \
		.tBit.pwrcr15 = 0, \
	}, \
	.SD_PWRCR4 = \
	{ \
		.tBit.pwrcr16 = 0, \
		.tBit.pwrcr17 = 0, \
		.tBit.pwrcr18 = 0, \
		.tBit.pwrcr19 = 0, \
		.tBit.pwrcr20 = 0, \
	}, \
	.SD_PWRCR5 = \
	{ \
		.tBit.pwrcr21 = 0, \
		.tBit.pwrcr22 = 0, \
		.tBit.pwrcr23 = 0, \
		.tBit.pwrcr24 = 0, \
		.tBit.pwrcr25 = 0, \
	}, \
	.SD_PWRCR6 = \
	{ \
		.tBit.pwrcr26 = 0, \
		.tBit.pwrcr27 = 0, \
		.tBit.pwrcr28 = 0, \
		.tBit.pwrcr29 = 0, \
		.tBit.pwrcr30 = 0, \
	}, \
	.SD_PWRCR7 = \
	{ \
		.tBit.pwrcr31 = 0, \
		.tBit.pwrcr32 = 0, \
		.tBit.sd_lhbnum = 8, \
		.tBit.set_sel = 0, \
		.tBit.rocen = 0, \
	}, \
	.AFE_SENSE_CTL1 = \
	{ \
		.tBit.pen_dc_md_pen = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_dc_md_pen, \
		.tBit.pen_dc_md_fig = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_dc_md_fig, \
		.tBit.pen_dc_md_stuck = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_dc_md_stuck, \
		.tBit.pre_comp = PARAMSET_ROIC_AFE_SENSE_CTL1_pre_comp, \
		.tBit.pre_ch_conb_en = PARAMSET_ROIC_AFE_SENSE_CTL1_pre_ch_conb_en, \
		.tBit.pre_ch_conb_inv = PARAMSET_ROIC_AFE_SENSE_CTL1_pre_ch_conb_inv, \
		.tBit.fig_int_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_int_ref, \
		.tBit.pen_int_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_int_ref, \
		.tBit.fig_sha_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_sha_ref, \
		.tBit.pen_sha_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_sha_ref, \
	}, \
	.AFE_SENSE_CTL2 = \
	{ \
		.tBit.fig_pre_gc = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_pre_gc, \
		.tBit.pen_pre_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_pre_gc_con, \
		.tBit.pen_pre_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_pre_gc_hov, \
		.tBit.pdrv_pre_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_pre_gc_con, \
		.tBit.pdrv_pre_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_pre_gc_hov, \
		.tBit.fig_int_gc = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_int_gc, \
		.tBit.pen_int_gc = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_gc, \
		.tBit.fig_int_half = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_int_half, \
		.tBit.pen_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_half_con, \
		.tBit.pen_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_half_hov, \
		.tBit.pdrv_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_int_half_con, \
		.tBit.pdrv_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_int_half_hov, \
		.tBit.fig_pre_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_pre_bs_lp, \
		.tBit.pen_pre_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_pre_bs_lp, \
		.tBit.pdrv_pre_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_pre_bs_lp, \
		.tBit.fig_int_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_int_bs_lp, \
		.tBit.pen_int_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_bs_lp, \
		.tBit.fig_sha_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_sha_bs_lp, \
		.tBit.pen_sha_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_sha_bs_lp, \
	}, \
	.AFE_SENSE_CTL3 = \
	{ \
		.tBit.fig_hv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_fig_hv_ssu_bcon, \
		.tBit.pen_hv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_pen_hv_ssu_bcon, \
		.tBit.pdrv_hv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_pdrv_hv_ssu_bcon, \
		.tBit.fig_lv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_fig_lv_ssu_bcon, \
		.tBit.pen_lv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_pen_lv_ssu_bcon, \
		.tBit.fig_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL3_fig_lv_ssu_bcons, \
		.tBit.pen_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL3_pen_lv_ssu_bcons, \
		.tBit.lv_ssu_bconp = PARAMSET_ROIC_AFE_SENSE_CTL3_lv_ssu_bconp, \
		.tBit.lv_ssu_bconp_buf = PARAMSET_ROIC_AFE_SENSE_CTL3_lv_ssu_bconp_buf, \
		.tBit.ref_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_ref_bcon, \
	}, \
	.PHD_SENSE_CTL1 = \
	{ \
		.tBit.rst_phd_en = 0, \
		.tBit.phd_gc_con = 0, \
		.tBit.phd_gc_hov = 0, \
		.tBit.phd_md = 0, \
		.tBit.adc_in_phd = 0, \
		.tBit.r0_phd_in_s = 1, \
		.tBit.r1_phd_in_s = 1, \
		.tBit.r0_phd_en = 0, \
		.tBit.r1_phd_en = 0, \
		.tBit.stuck_rst_phd = 0, \
		.tBit.stuck_adc_in_phd = 0, \
		.tBit.stuck_phd_md = 0, \
		.tBit.stuck_phd_en = 0, \
	}, \
	.PHD_SENSE_CTL2 = \
	{ \
		.tBit.rst_phd_fall_num = 0, \
		.tBit.phd_all_fall_num = 0, \
		.tBit.adc_in_phd_rise_num = 0, \
	}, \
	.ADC_SENSE_CTL = \
	{ \
		.tBit.fig_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_fig_lv_adc_ref_bcon, \
		.tBit.pen_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_pen_lv_adc_ref_bcon, \
		.tBit.pdrv_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_lv_adc_ref_bcon, \
		.tBit.fig_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_fig_lv_adc_bcon, \
		.tBit.pen_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_pen_lv_adc_bcon, \
		.tBit.pdrv_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_lv_adc_bcon, \
		.tBit.adc_clk_div_1p5 = PARAMSET_ROIC_ADC_SENSE_CTL_adc_clk_div_1p5, \
		.tBit.adc_stc_insel = PARAMSET_ROIC_ADC_SENSE_CTL_adc_stc_insel, \
		.tBit.fig_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_comp_bias_ctl, \
		.tBit.pen_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_comp_bias_ctl, \
		.tBit.pdrv_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_comp_bias_ctl, \
		.tBit.fig_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_mdac_comp_ctl, \
		.tBit.pen_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_mdac_comp_ctl, \
		.tBit.pdrv_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_mdac_comp_ctl, \
		.tBit.fig_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_mdac_slew_ctl, \
		.tBit.pen_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_mdac_slew_ctl, \
		.tBit.pdrv_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_mdac_slew_ctl, \
		.tBit.fig_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_ref_idrv_ctl, \
		.tBit.pen_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_ref_idrv_ctl, \
		.tBit.pdrv_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_ref_idrv_ctl, \
	}, \
	.PDB_CTL = \
	{ \
		.tBit.pdb_hvbias = 1, \
		.tBit.pdb_hvc = 1, \
		.tBit.pdb_hvr = 1, \
		.tBit.pdb_lvbias = 1, \
		.tBit.pdb_int = 1, \
		.tBit.pdb_sha = 1, \
		.tBit.bgr_en = 1, \
		.tBit.bias_en = 1, \
		.tBit.pdb_adc = 1, \
		.tBit.stuck_hvbias = PARAMSET_ROIC_PDB_CTL_stuck_hvbias, \
		.tBit.stuck_hvc = PARAMSET_ROIC_PDB_CTL_stuck_hvc, \
		.tBit.stuck_hvr = PARAMSET_ROIC_PDB_CTL_stuck_hvr, \
		.tBit.stuck_lvbias = PARAMSET_ROIC_PDB_CTL_stuck_lvbias, \
		.tBit.stuck_int = PARAMSET_ROIC_PDB_CTL_stuck_int, \
		.tBit.stuck_sha = PARAMSET_ROIC_PDB_CTL_stuck_sha, \
		.tBit.stuck_bgr_en = PARAMSET_ROIC_PDB_CTL_stuck_bgr_en, \
		.tBit.stuck_bias_en = PARAMSET_ROIC_PDB_CTL_stuck_bias_en, \
		.tBit.stuck_adc = PARAMSET_ROIC_PDB_CTL_stuck_adc, \
		.tBit.pdb_hvr_shift_en = PARAMSET_ROIC_PDB_CTL_pdb_hvr_shift_en, \
	}, \
	.PDB_PHD_CTL = \
	{ \
		.tBit.pdb_phd = 0, \
		.tBit.pdb_phd_buf = 0, \
		.tBit.stuck_phd = 0, \
		.tBit.stuck_phd_buf = 0, \
		.tBit.phd_en_op_num = 25, \
		.tBit.phd_md_op_num = 25, \
	}, \
	.ADC_IN_SHIFT_CTL1 = \
	{ \
		.tBit.adc_in_shift_num0 = 0, \
		.tBit.adc_in_shift_num1 = 3, \
		.tBit.adc_in_shift_num2 = 7, \
		.tBit.adc_in_shift_num3 = 10, \
		.tBit.adc_in_shift_num4 = 14, \
	}, \
	.ADC_IN_SHIFT_CTL2 = \
	{ \
		.tBit.adc_in_shift_num5 = 17, \
		.tBit.adc_in_shift_num6 = 21, \
		.tBit.adc_in_shift_num7 = 24, \
		.tBit.adc_in_shift_num8 = 28, \
	}, \
	.R_RESERVE = \
	{ \
		.tBit.r0_reserve = 0, \
		.tBit.r1_reserve = 0, \
	}, \
	.SYS_DUMMY0 = \
	{ \
		.tBit.sys_dummy0 = 0x00000000, \
	}, \
	.SYS_DUMMY1 = \
	{ \
		.tBit.sys_dummy1 = 0xFFFFFFFF, \
	}, \
	.TEST_MUX_CTL = \
	{ \
		.tBit.r0_tm_mon_en = 0, \
		.tBit.r1_tm_mon_en = 0, \
		.tBit.r0_tm_mon_s = 0, \
		.tBit.r1_tm_mon_s = 0, \
		.tBit.r0_pen_mode_en = 1, \
		.tBit.r1_pen_mode_en = 1, \
		.tBit.r0_tm_ssu_pen = 0, \
		.tBit.r1_tm_ssu_pen = 0, \
		.tBit.r0_test_adc_a = 0, \
		.tBit.r0_test_adc_b = 0, \
		.tBit.r1_test_adc_a = 0, \
		.tBit.r1_test_adc_b = 0, \
		.tBit.test_adc_sel = 0, \
		.tBit.test_adc_dec = 0, \
		.tBit.mon_adcdo_en = 0, \
		.tBit.test_adc_eoc_sel = 0, \
		.tBit.phd_mon_sel = 0, \
	}, \
	.PHD_CTL1 = \
	{ \
		.tBit.adc_skipnum = 0, \
		.tBit.adc_th0 = 0, \
		.tBit.adc_th1 = 0, \
	}, \
	.PHD_CTL2 = \
	{ \
		.tBit.dly_th = 0, \
		.tBit.edgecnt_th = 0, \
		.tBit.offset_dly = 0, \
		.tBit.invalid_dly = 0, \
		.tBit.sel_delay = 0, \
	}, \
	.PHD_CTL3 = \
	{ \
		.tBit.bypass_en = 0, \
		.tBit.coef_val = 0, \
		.tBit.offset_val = 0, \
		.tBit.adc_mon_data_sel = 0, \
		.tBit.phd_mon_en = 0, \
	}, \
	.PHD_CTL4 = \
	{ \
		.tBit.adc_mon_th_r = 0, \
		.tBit.adc_mon_th_f = 0, \
	},

#define SRIC_Conf_Set        SRIC_WGPPEN_Conf_Set

#endif

#endif

