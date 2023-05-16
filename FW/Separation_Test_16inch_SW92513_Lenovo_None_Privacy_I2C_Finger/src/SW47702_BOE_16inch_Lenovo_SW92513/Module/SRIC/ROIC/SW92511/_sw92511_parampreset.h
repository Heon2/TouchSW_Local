/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _sw92511_parampreset.h
 * created on : 29. 12. 2020
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
 * POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************************************/

#ifndef __SW92511_PARAMPRESET_H_
#define __SW92511_PARAMPRESET_H_


#if (USED_ROIC_DEF == ROIC_SW92511)
#define SRIC_WGPPEN_Conf_Set	\
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
    }, \
    .SYS_CFG = \
    { \
     .tBit.tg_reset = 0, \
     .tBit.sw_reset = 0, \
     .tBit.tg_clk_all_on = 1, \
     .tBit.cfclk_on = 0, \
    }, \
    .TC_START = \
    { \
     .tBit.tc_start = 0, \
    }, \
    .CH_NUM = \
    { \
     .tBit.fig_ch_num = PARAMSET_ROIC_CFGR_CH_NUM_fig_ch_num, \
     .tBit.pp_ch_num = PARAMSET_ROIC_CFGR_CH_NUM_pen_ch_num, \
     .tBit.pdrv_ch_num = PARAMSET_ROIC_CFGR_CH_NUM_pdrv_ch_num, \
    }, \
    .MUX_CTL = \
    { \
     .tBit.tot_mux_num = PARAMSET_ROIC_CFGR_MUX_CTL_tot_mux_num, \
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
    .MUX_DLY_2 = \
    { \
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
     .tBit.sd_off_en = PARAMSET_ROIC_SDIC_CFG_sd_off_en, \
     .tBit.sd_float_en = 0, \
     .tBit.sd_gnd_en = 0, \
     .tBit.sd_off_ctl = PARAMSET_ROIC_SDIC_sd_off_ctl, \
     .tBit.sd_float_ctl = 0, \
     .tBit.sd_gnd_ctl = 0, \
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
     .tBit.pwm_pos_act_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_act_num, \
     .tBit.pwm_pos_mgap_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_mgap_num, \
     .tBit.pwm_pos_dum_num = PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_dum_num + PARAMSET_ROIC_CFGR_PWM_POS_CTL_pwm_set_num, \
    }, \
    .PWM_DAT_CTL = \
    { \
     .tBit.pwm_dat_pdrv_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_pdrv_num, \
     .tBit.pwm_dat_pre_act_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_pre_act_num, \
     .tBit.pwm_dat_act_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_act_num, \
     .tBit.pwm_dat_mgap_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_mgap_num, \
     .tBit.pwm_dat_dum_num = PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_dum_num + PARAMSET_ROIC_CFGR_PWM_DATA_CTL_pwm_set_num, \
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
     .tBit.fig_smop_prd = PARAMSET_ROIC_CFGR_SMPL_CTL_fig_smop_prd, \
     .tBit.pen_smop_prd = PARAMSET_ROIC_CFGR_SMPL_CTL_fig_smop_prd, \
     .tBit.nd_smop_prd = PARAMSET_ROIC_CFGR_SMPL_CTL_nd_smop_prd, \
     .tBit.cr_repeat_num = PARAMSET_ROIC_CFGR_SMPL_CTL_cr_repeat_num, \
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
     .tBit.nd_rsti_rise_num = 15, \
    }, \
    .RSTI_FALL_NUM1 = \
    { \
     .tBit.fig_rsti_fall_num1 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_fig_rsti_fall_num1, \
     .tBit.pen_rsti_fall_num1 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM1_pen_rsti_fall_num1, \
     .tBit.nd_rsti_fall_num1 = 30, \
    }, \
    .RSTI_FALL_NUM2 = \
    { \
     .tBit.fig_rsti_fall_num2 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_fig_rsti_fall_num2, \
     .tBit.pen_rsti_fall_num2 = PARAMSET_ROIC_CFGR_RSTI_FALL_NUM2_pen_rsti_fall_num2, \
     .tBit.nd_rsti_fall_num2 = 3, \
    }, \
    .PHTH0_RISE_NUM = \
    { \
     .tBit.fig_phth0_rise_num = PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_fig_phth0_rise_num, \
     .tBit.pen_phth0_rise_num = PARAMSET_ROIC_CFGR_PHTH0_RISE_NUM_pen_phth0_rise_num, \
     .tBit.nd_phth0_rise_num = 30, \
    }, \
    .PHTH0_FALL_NUM = \
    { \
     .tBit.fig_phth0_fall_num = PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_fig_phth0_fall_num, \
     .tBit.pen_phth0_fall_num = PARAMSET_ROIC_CFGR_PHTH0_FALL_NUM_pen_phth0_fall_num, \
     .tBit.nd_phth0_fall_num = 20, \
    }, \
    .PHTH1_RISE_NUM = \
    { \
     .tBit.fig_phth1_rise_num = PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_fig_phth1_rise_num, \
     .tBit.pen_phth1_rise_num = PARAMSET_ROIC_CFGR_PHTH1_RISE_NUM_pen_phth1_rise_num, \
     .tBit.nd_phth1_rise_num = 17, \
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
     .tBit.adc_clk_opt = PARAMSET_ROIC_CFGR_ADC_CTL1_adc_clk_opt, \
     .tBit.adc_clk_pol = PARAMSET_ROIC_CFGR_ADC_CTL1_adc_clk_pol, \
     .tBit.fig_adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTL1_fig_adc_clk_prd, \
     .tBit.pen_adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTL1_pen_adc_clk_prd, \
     .tBit.pdrv_adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTL1_pdrv_adc_clk_prd, \
     .tBit.fig_conv_smpl_num = PARAMSET_ROIC_CFGR_ADC_CTL1_fig_conv_smpl_num, \
     .tBit.pen_conv_smpl_num = PARAMSET_ROIC_CFGR_ADC_CTL1_pen_conv_smpl_num, \
     .tBit.pdrv_conv_smpl_num = PARAMSET_ROIC_CFGR_ADC_CTL1_pdrv_conv_smpl_num, \
     .tBit.adc_clk_spt  = PARAMSET_ROIC_CFGR_ADC_CTL1_adc_clk_spt, \
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
    .TG_STUCK = \
    { \
     .tBit.fig_vcr_off_en = 0, \
     .tBit.fig_phtcr_off_en = 0, \
     .tBit.pen_vcr_off_en = 1, \
     .tBit.pen_phtcr_off_en = 1, \
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
    }, \
    .DEFA_LHB_MCFG00 = \
    { \
    	[PWM_FULL_FINGER_MODE] = \
		{ \
			 .tBit.lhb_mode01 = PARAMSET_ROIC_FULL_LHB_1_mode/*1*/, \
			 .tBit.lhb_mode02 = PARAMSET_ROIC_FULL_LHB_2_mode/*2*/, \
			 .tBit.lhb_mode03 = PARAMSET_ROIC_FULL_LHB_3_mode/*0*/, \
			 .tBit.lhb_mode04 = PARAMSET_ROIC_FULL_LHB_4_mode/*0*/, \
			 .tBit.lhb_mode05 = PARAMSET_ROIC_FULL_LHB_5_mode/*2*/, \
			 .tBit.lhb_mode06 = PARAMSET_ROIC_FULL_LHB_6_mode/*2*/, \
			 .tBit.lhb_mode07 = PARAMSET_ROIC_FULL_LHB_7_mode/*3*/, \
			 .tBit.lhb_mode08 = PARAMSET_ROIC_FULL_LHB_8_mode/*3*/, \
		} , \
    	[PWM_LOCAL_PEN_MODE] = \
		{ \
			 .tBit.lhb_mode01 = PARAMSET_ROIC_LOCAL_LHB_1_mode/*1*/, \
			 .tBit.lhb_mode02 = PARAMSET_ROIC_LOCAL_LHB_2_mode/*2*/, \
			 .tBit.lhb_mode03 = PARAMSET_ROIC_LOCAL_LHB_3_mode/*0*/, \
			 .tBit.lhb_mode04 = PARAMSET_ROIC_LOCAL_LHB_4_mode/*0*/, \
			 .tBit.lhb_mode05 = PARAMSET_ROIC_LOCAL_LHB_5_mode/*2*/, \
			 .tBit.lhb_mode06 = PARAMSET_ROIC_LOCAL_LHB_6_mode/*2*/, \
			 .tBit.lhb_mode07 = PARAMSET_ROIC_LOCAL_LHB_7_mode/*3*/, \
			 .tBit.lhb_mode08 = PARAMSET_ROIC_LOCAL_LHB_8_mode/*3*/, \
		} , \
    	[PWM_LOCAL_PEN_IDLE_MODE] = \
		{ \
			 .tBit.lhb_mode01 = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mode/*1*/, \
			 .tBit.lhb_mode02 = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mode/*2*/, \
			 .tBit.lhb_mode03 = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mode/*0*/, \
			 .tBit.lhb_mode04 = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mode/*0*/, \
			 .tBit.lhb_mode05 = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mode/*2*/, \
			 .tBit.lhb_mode06 = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mode/*2*/, \
			 .tBit.lhb_mode07 = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode/*3*/, \
			 .tBit.lhb_mode08 = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mode/*3*/, \
		} , \
    }, \
    .DEFA_LHB_MCFG01 = \
    { \
    	[PWM_FULL_FINGER_MODE] = \
		{ \
			.tBit.lhb_mode09 = PARAMSET_ROIC_FULL_LHB_9_mode/*9*/, \
			.tBit.lhb_mode10 = PARAMSET_ROIC_FULL_LHB_10_mode/*10*/, \
			.tBit.lhb_mode11 = PARAMSET_ROIC_FULL_LHB_11_mode/*11*/, \
			.tBit.lhb_mode12 = PARAMSET_ROIC_FULL_LHB_12_mode/*12*/, \
			.tBit.lhb_mode13 = PARAMSET_ROIC_FULL_LHB_13_mode/*13*/, \
			.tBit.lhb_mode14 = PARAMSET_ROIC_FULL_LHB_14_mode/*14*/, \
			.tBit.lhb_mode15 = PARAMSET_ROIC_FULL_LHB_15_mode/*15*/, \
			.tBit.lhb_mode16 = PARAMSET_ROIC_FULL_LHB_16_mode/*16*/, \
		} , \
    	[PWM_LOCAL_PEN_MODE] = \
		{ \
			.tBit.lhb_mode09 = PARAMSET_ROIC_LOCAL_LHB_9_mode/*9*/, \
			.tBit.lhb_mode10 = PARAMSET_ROIC_LOCAL_LHB_10_mode/*10*/, \
			.tBit.lhb_mode11 = PARAMSET_ROIC_LOCAL_LHB_11_mode/*11*/, \
			.tBit.lhb_mode12 = PARAMSET_ROIC_LOCAL_LHB_12_mode/*12*/, \
			.tBit.lhb_mode13 = PARAMSET_ROIC_LOCAL_LHB_13_mode/*13*/, \
			.tBit.lhb_mode14 = PARAMSET_ROIC_LOCAL_LHB_14_mode/*14*/, \
			.tBit.lhb_mode15 = PARAMSET_ROIC_LOCAL_LHB_15_mode/*15*/, \
			.tBit.lhb_mode16 = PARAMSET_ROIC_LOCAL_LHB_16_mode/*16*/, \
		} , \
    	[PWM_LOCAL_PEN_IDLE_MODE] = \
		{ \
			.tBit.lhb_mode09 = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mode/*9*/, \
			.tBit.lhb_mode10 = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mode/*10*/, \
			.tBit.lhb_mode11 = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mode/*11*/, \
			.tBit.lhb_mode12 = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mode/*12*/, \
			.tBit.lhb_mode13 = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mode/*13*/, \
			.tBit.lhb_mode14 = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode/*14*/, \
			.tBit.lhb_mode15 = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode/*15*/, \
			.tBit.lhb_mode16 = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode/*16*/, \
		} , \
    }, \
    .DEFA_LHB_MCFG02 = \
    { \
    	[PWM_FULL_FINGER_MODE] = \
		{ \
			.tBit.lhb_mode17 = PARAMSET_ROIC_FULL_LHB_17_mode, \
			.tBit.lhb_mode18 = PARAMSET_ROIC_FULL_LHB_18_mode, \
			.tBit.lhb_mode19 = PARAMSET_ROIC_FULL_LHB_19_mode, \
			.tBit.lhb_mode20 = PARAMSET_ROIC_FULL_LHB_20_mode, \
			.tBit.lhb_mode21 = PARAMSET_ROIC_FULL_LHB_21_mode, \
			.tBit.lhb_mode22 = PARAMSET_ROIC_FULL_LHB_22_mode, \
			.tBit.lhb_mode23 = PARAMSET_ROIC_FULL_LHB_23_mode, \
			.tBit.lhb_mode24 = PARAMSET_ROIC_FULL_LHB_24_mode, \
		} , \
    	[PWM_LOCAL_PEN_MODE] = \
		{ \
			.tBit.lhb_mode17 = PARAMSET_ROIC_LOCAL_LHB_17_mode, \
			.tBit.lhb_mode18 = PARAMSET_ROIC_LOCAL_LHB_18_mode, \
			.tBit.lhb_mode19 = PARAMSET_ROIC_LOCAL_LHB_19_mode, \
			.tBit.lhb_mode20 = PARAMSET_ROIC_LOCAL_LHB_20_mode, \
			.tBit.lhb_mode21 = PARAMSET_ROIC_LOCAL_LHB_21_mode, \
			.tBit.lhb_mode22 = PARAMSET_ROIC_LOCAL_LHB_22_mode, \
			.tBit.lhb_mode23 = PARAMSET_ROIC_LOCAL_LHB_23_mode, \
			.tBit.lhb_mode24 = PARAMSET_ROIC_LOCAL_LHB_24_mode, \
		} , \
    	[PWM_LOCAL_PEN_IDLE_MODE] = \
		{ \
			.tBit.lhb_mode17 = PARAMSET_ROIC_LOCAL_IDLE_LHB_17_mode, \
			.tBit.lhb_mode18 = PARAMSET_ROIC_LOCAL_IDLE_LHB_18_mode, \
			.tBit.lhb_mode19 = PARAMSET_ROIC_LOCAL_IDLE_LHB_19_mode, \
			.tBit.lhb_mode20 = PARAMSET_ROIC_LOCAL_IDLE_LHB_20_mode, \
			.tBit.lhb_mode21 = PARAMSET_ROIC_LOCAL_IDLE_LHB_21_mode, \
			.tBit.lhb_mode22 = PARAMSET_ROIC_LOCAL_IDLE_LHB_22_mode, \
			.tBit.lhb_mode23 = PARAMSET_ROIC_LOCAL_IDLE_LHB_23_mode, \
			.tBit.lhb_mode24 = PARAMSET_ROIC_LOCAL_IDLE_LHB_24_mode, \
		} , \
    }, \
    .DEFA_LHB_MCFG03 = \
    { \
    	[PWM_FULL_FINGER_MODE] = \
		{ \
			.tBit.lhb_mode25 = PARAMSET_ROIC_FULL_LHB_25_mode, \
			.tBit.lhb_mode26 = PARAMSET_ROIC_FULL_LHB_26_mode, \
			.tBit.lhb_mode27 = PARAMSET_ROIC_FULL_LHB_27_mode, \
			.tBit.lhb_mode28 = PARAMSET_ROIC_FULL_LHB_28_mode, \
			.tBit.lhb_mode29 = PARAMSET_ROIC_FULL_LHB_29_mode, \
			.tBit.lhb_mode30 = PARAMSET_ROIC_FULL_LHB_30_mode, \
			.tBit.lhb_mode31 = PARAMSET_ROIC_FULL_LHB_31_mode, \
			.tBit.lhb_mode32 = PARAMSET_ROIC_FULL_LHB_32_mode, \
		} , \
    	[PWM_LOCAL_PEN_MODE] = \
		{ \
			.tBit.lhb_mode25 = PARAMSET_ROIC_LOCAL_LHB_25_mode, \
			.tBit.lhb_mode26 = PARAMSET_ROIC_LOCAL_LHB_26_mode, \
			.tBit.lhb_mode27 = PARAMSET_ROIC_LOCAL_LHB_27_mode, \
			.tBit.lhb_mode28 = PARAMSET_ROIC_LOCAL_LHB_28_mode, \
			.tBit.lhb_mode29 = PARAMSET_ROIC_LOCAL_LHB_29_mode, \
			.tBit.lhb_mode30 = PARAMSET_ROIC_LOCAL_LHB_30_mode, \
			.tBit.lhb_mode31 = PARAMSET_ROIC_LOCAL_LHB_31_mode, \
			.tBit.lhb_mode32 = PARAMSET_ROIC_LOCAL_LHB_32_mode, \
		} , \
    	[PWM_LOCAL_PEN_IDLE_MODE] = \
		{ \
			.tBit.lhb_mode25 = PARAMSET_ROIC_LOCAL_IDLE_LHB_25_mode, \
			.tBit.lhb_mode26 = PARAMSET_ROIC_LOCAL_IDLE_LHB_26_mode, \
			.tBit.lhb_mode27 = PARAMSET_ROIC_LOCAL_IDLE_LHB_27_mode, \
			.tBit.lhb_mode28 = PARAMSET_ROIC_LOCAL_IDLE_LHB_28_mode, \
			.tBit.lhb_mode29 = PARAMSET_ROIC_LOCAL_IDLE_LHB_29_mode, \
			.tBit.lhb_mode30 = PARAMSET_ROIC_LOCAL_IDLE_LHB_30_mode, \
			.tBit.lhb_mode31 = PARAMSET_ROIC_LOCAL_IDLE_LHB_31_mode, \
			.tBit.lhb_mode32 = PARAMSET_ROIC_LOCAL_IDLE_LHB_32_mode, \
		} , \
    }, \
    .LHB_MUX_NUM = \
    { \
     .tBit.fig_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_NUM_fig_lhb_mux_num, \
     .tBit.pen_pos1_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_NUM_pen_pos1_lhb_mux_num, \
     .tBit.pen_dat1_lhb_mux_num = PARAMSET_ROIC_CFGR_LHB_MUX_NUM_pen_dat1_lhb_mux_num, \
    }, \
    .PEN_POS1_LHB_CFG = \
    { \
     .tBit.pen_pos1_mux_cfg0 = 0, \
     .tBit.pen_pos1_mux_cfg1 = 0, \
     .tBit.pen_pos1_mux_cfg2 = 0, \
     .tBit.pen_pos1_mux_cfg3 = 0, \
    }, \
    .PEN_DAT1_LHB_CFG = \
    { \
     .tBit.pen_dat1_mux_cfg0 = 0, \
     .tBit.pen_dat1_mux_cfg1 = 0, \
     .tBit.pen_dat1_mux_cfg2 = 0, \
     .tBit.pen_dat1_mux_cfg3 = 0, \
     .tBit.pen_dat1_tmuxnum = PARAMSET_ROIC_CFGR_LHB_MUX_NUM_pen_dat1_lhb_mux_num, \
     .tBit.pen_dat1_tsync_muxnum = 0, \
    }, \
    .MUX_FCTL_NUM1 = \
    { \
     .tBit.mux_fctl_rise_num1 = PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num1, \
     .tBit.mux_fctl_rise_num2 = PARAMSET_ROIC_CFGR_MUX_FCTL_NUM1_mux_fctl_rise_num2, \
     .tBit.fctl_rsti_off = 0, \
    }, \
    .MUX_FCTL_NUM2 = \
    { \
     .tBit.mux_fctl_fall_num1 = PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num1, \
     .tBit.mux_fctl_fall_num2 = PARAMSET_ROIC_CFGR_MUX_FCTL_NUM2_mux_fctl_fall_num2, \
    }, \
    .PING_MUX_CTL = \
    { \
     .tBit.ping_max = 0, \
     .tBit.ping_pwm_num = 0, \
     .tBit.ping_mux_sel = 0, \
     .tBit.ping_mode = 0, \
    }, \
    .PRE_DRV_CTL = \
    { \
     .tBit.pdrv_mode = PARAMSET_ROIC_CFGR_PRE_DRV_CTL_pdrv_mode, \
     .tBit.pdrv_adc_en = 0, \
    }, \
    .AFE_SENSE_CTL1 = \
    { \
     .tBit.pen_dc_md_pen = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_dc_md_pen, \
     .tBit.pen_dc_md_fig = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_dc_md_fig, \
     .tBit.pre_ch_conb_en = PARAMSET_ROIC_AFE_SENSE_CTL1_pre_ch_conb_en, \
     .tBit.pre_ch_conb_inv = PARAMSET_ROIC_AFE_SENSE_CTL1_pre_ch_conb_inv, \
    }, \
    .PHD_SENSE_CTL2 = \
    { \
     .tBit.rst_phd_fall_num = 0, \
     .tBit.phd_all_fall_num = 0, \
     .tBit.adc_in_phd_rise_num = 0, \
    }, \
    .PDB_PHD_CTL = \
    { \
     .tBit.phd_en_op_num = 40, \
     .tBit.phd_md_op_num = 40, \
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
     .tBit.phd_mon_sel = 0, \
    }, \
    .PHD_CTL2 = \
    { \
     .tBit.edgecnt_th = 0, \
     .tBit.sel_delay = 0, \
     .tBit.invalid_dly = 0, \
    }, \
    .PHD_CTL3 = \
    { \
     .tBit.offset_val = 0, \
    }, \
    .R0_SYS_CFG = \
    { \
     .tBit.r0_buf_clk_on = 1, \
     .tBit.r0_cfclk_on = 0, \
    }, \
    .R0_CH_EN = \
    { \
     .tBit.r0_dum_drv_en = 0, \
     .tBit.r0_ch_en_int = 127, \
     .tBit.r0_ch_en_hvc = 511, \
    }, \
    .R0_MUX_CTL = \
    { \
     .tBit.r0_top_mux_num = 0, \
     .tBit.r0_bot_mux_num = 9, \
     .tBit.r0_mux_int_en = 0, \
     .tBit.r0_mux_int_stuck_val = 0, \
     .tBit.r0_mux_off_en = 0, \
    }, \
    .R0_MUX_S_STUCK_VAL = \
    { \
     .tBit.r0_mux_s_stuck = 0, \
     .tBit.r0_mux_s_line_stuck = 0, \
    }, \
    .R0_MUX_F_STUCK_VAL = \
    { \
     .tBit.r0_mux_f_stuck_val = 0, \
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
     [4] = { \
      .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_4_R0_1stMux_r1_g1, \
      .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_4_R0_1stMux_r1_g2, \
      .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_4_R0_1stMux_r1_g3, \
      .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_4_R0_2ndMux_r1_g1, \
      .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_4_R0_2ndMux_r1_g2, \
      .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_4_R0_2ndMux_r1_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_5_R0_1stMux_r1_g1, \
      .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_5_R0_1stMux_r1_g2, \
      .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_5_R0_1stMux_r1_g3, \
      .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_5_R0_2ndMux_r1_g1, \
      .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_5_R0_2ndMux_r1_g2, \
      .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_5_R0_2ndMux_r1_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_4_R0_1stMux_r2_g1, \
      .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_4_R0_1stMux_r2_g2, \
      .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_4_R0_1stMux_r2_g3, \
      .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_4_R0_2ndMux_r2_g1, \
      .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_4_R0_2ndMux_r2_g2, \
      .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_4_R0_2ndMux_r2_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_5_R0_1stMux_r2_g1, \
      .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_5_R0_1stMux_r2_g2, \
      .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_5_R0_1stMux_r2_g3, \
      .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_5_R0_2ndMux_r2_g1, \
      .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_5_R0_2ndMux_r2_g2, \
      .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_5_R0_2ndMux_r2_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_4_R0_1stMux_r3_g1, \
      .tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_4_R0_1stMux_r3_g2, \
      .tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_4_R0_1stMux_r3_g3, \
      .tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_4_R0_2ndMux_r3_g1, \
      .tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_4_R0_2ndMux_r3_g2, \
      .tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_4_R0_2ndMux_r3_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux1_r3g1 = PARAMSET_ROIC_5_R0_1stMux_r3_g1, \
      .tBit.r0_cr_mux1_r3g2 = PARAMSET_ROIC_5_R0_1stMux_r3_g2, \
      .tBit.r0_cr_mux1_r3g3 = PARAMSET_ROIC_5_R0_1stMux_r3_g3, \
      .tBit.r0_cr_mux2_r3g1 = PARAMSET_ROIC_5_R0_2ndMux_r3_g1, \
      .tBit.r0_cr_mux2_r3g2 = PARAMSET_ROIC_5_R0_2ndMux_r3_g2, \
      .tBit.r0_cr_mux2_r3g3 = PARAMSET_ROIC_5_R0_2ndMux_r3_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_4_R0_3rdMux_r1_g1, \
      .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_4_R0_3rdMux_r1_g2, \
      .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_4_R0_3rdMux_r1_g3, \
      .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_4_R0_4thMux_r1_g1, \
      .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_4_R0_4thMux_r1_g2, \
      .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_4_R0_4thMux_r1_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_5_R0_3rdMux_r1_g1, \
      .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_5_R0_3rdMux_r1_g2, \
      .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_5_R0_3rdMux_r1_g3, \
      .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_5_R0_4thMux_r1_g1, \
      .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_5_R0_4thMux_r1_g2, \
      .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_5_R0_4thMux_r1_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_4_R0_3rdMux_r2_g1, \
      .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_4_R0_3rdMux_r2_g2, \
      .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_4_R0_3rdMux_r2_g3, \
      .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_4_R0_4thMux_r2_g1, \
      .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_4_R0_4thMux_r2_g2, \
      .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_4_R0_4thMux_r2_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_5_R0_3rdMux_r2_g1, \
      .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_5_R0_3rdMux_r2_g2, \
      .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_5_R0_3rdMux_r2_g3, \
      .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_5_R0_4thMux_r2_g1, \
      .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_5_R0_4thMux_r2_g2, \
      .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_5_R0_4thMux_r2_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_4_R0_3rdMux_r3_g1, \
      .tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_4_R0_3rdMux_r3_g2, \
      .tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_4_R0_3rdMux_r3_g3, \
      .tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_4_R0_4thMux_r3_g1, \
      .tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_4_R0_4thMux_r3_g2, \
      .tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_4_R0_4thMux_r3_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux3_r3g1 = PARAMSET_ROIC_5_R0_3rdMux_r3_g1, \
      .tBit.r0_cr_mux3_r3g2 = PARAMSET_ROIC_5_R0_3rdMux_r3_g2, \
      .tBit.r0_cr_mux3_r3g3 = PARAMSET_ROIC_5_R0_3rdMux_r3_g3, \
      .tBit.r0_cr_mux4_r3g1 = PARAMSET_ROIC_5_R0_4thMux_r3_g1, \
      .tBit.r0_cr_mux4_r3g2 = PARAMSET_ROIC_5_R0_4thMux_r3_g2, \
      .tBit.r0_cr_mux4_r3g3 = PARAMSET_ROIC_5_R0_4thMux_r3_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_4_R0_5thMux_r1_g1, \
      .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_4_R0_5thMux_r1_g2, \
      .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_4_R0_5thMux_r1_g3, \
      .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_4_R0_6thMux_r1_g1, \
      .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_4_R0_6thMux_r1_g2, \
      .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_4_R0_6thMux_r1_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_5_R0_5thMux_r1_g1, \
      .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_5_R0_5thMux_r1_g2, \
      .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_5_R0_5thMux_r1_g3, \
      .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_5_R0_6thMux_r1_g1, \
      .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_5_R0_6thMux_r1_g2, \
      .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_5_R0_6thMux_r1_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_4_R0_5thMux_r2_g1, \
      .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_4_R0_5thMux_r2_g2, \
      .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_4_R0_5thMux_r2_g3, \
      .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_4_R0_6thMux_r2_g1, \
      .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_4_R0_6thMux_r2_g2, \
      .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_4_R0_6thMux_r2_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_5_R0_5thMux_r2_g1, \
      .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_5_R0_5thMux_r2_g2, \
      .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_5_R0_5thMux_r2_g3, \
      .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_5_R0_6thMux_r2_g1, \
      .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_5_R0_6thMux_r2_g2, \
      .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_5_R0_6thMux_r2_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_4_R0_5thMux_r3_g1, \
      .tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_4_R0_5thMux_r3_g2, \
      .tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_4_R0_5thMux_r3_g3, \
      .tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_4_R0_6thMux_r3_g1, \
      .tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_4_R0_6thMux_r3_g2, \
      .tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_4_R0_6thMux_r3_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux5_r3g1 = PARAMSET_ROIC_5_R0_5thMux_r3_g1, \
      .tBit.r0_cr_mux5_r3g2 = PARAMSET_ROIC_5_R0_5thMux_r3_g2, \
      .tBit.r0_cr_mux5_r3g3 = PARAMSET_ROIC_5_R0_5thMux_r3_g3, \
      .tBit.r0_cr_mux6_r3g1 = PARAMSET_ROIC_5_R0_6thMux_r3_g1, \
      .tBit.r0_cr_mux6_r3g2 = PARAMSET_ROIC_5_R0_6thMux_r3_g2, \
      .tBit.r0_cr_mux6_r3g3 = PARAMSET_ROIC_5_R0_6thMux_r3_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_4_R0_7thMux_r1_g1, \
      .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_4_R0_7thMux_r1_g2, \
      .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_4_R0_7thMux_r1_g3, \
      .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_4_R0_8thMux_r1_g1, \
      .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_4_R0_8thMux_r1_g2, \
      .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_4_R0_8thMux_r1_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_5_R0_7thMux_r1_g1, \
      .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_5_R0_7thMux_r1_g2, \
      .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_5_R0_7thMux_r1_g3, \
      .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_5_R0_8thMux_r1_g1, \
      .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_5_R0_8thMux_r1_g2, \
      .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_5_R0_8thMux_r1_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_4_R0_7thMux_r2_g1, \
      .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_4_R0_7thMux_r2_g2, \
      .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_4_R0_7thMux_r2_g3, \
      .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_4_R0_8thMux_r2_g1, \
      .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_4_R0_8thMux_r2_g2, \
      .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_4_R0_8thMux_r2_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_5_R0_7thMux_r2_g1, \
      .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_5_R0_7thMux_r2_g2, \
      .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_5_R0_7thMux_r2_g3, \
      .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_5_R0_8thMux_r2_g1, \
      .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_5_R0_8thMux_r2_g2, \
      .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_5_R0_8thMux_r2_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux7_r3g1 = PARAMSET_ROIC_4_R0_7thMux_r3_g1, \
      .tBit.r0_cr_mux7_r3g2 = PARAMSET_ROIC_4_R0_7thMux_r3_g2, \
      .tBit.r0_cr_mux7_r3g3 = PARAMSET_ROIC_4_R0_7thMux_r3_g3, \
      .tBit.r0_cr_mux8_r3g1 = PARAMSET_ROIC_4_R0_8thMux_r3_g1, \
      .tBit.r0_cr_mux8_r3g2 = PARAMSET_ROIC_4_R0_8thMux_r3_g2, \
      .tBit.r0_cr_mux8_r3g3 = PARAMSET_ROIC_4_R0_8thMux_r3_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux7_r3g1 = PARAMSET_ROIC_5_R0_7thMux_r3_g1, \
      .tBit.r0_cr_mux7_r3g2 = PARAMSET_ROIC_5_R0_7thMux_r3_g2, \
      .tBit.r0_cr_mux7_r3g3 = PARAMSET_ROIC_5_R0_7thMux_r3_g3, \
      .tBit.r0_cr_mux8_r3g1 = PARAMSET_ROIC_5_R0_8thMux_r3_g1, \
      .tBit.r0_cr_mux8_r3g2 = PARAMSET_ROIC_5_R0_8thMux_r3_g2, \
      .tBit.r0_cr_mux8_r3g3 = PARAMSET_ROIC_5_R0_8thMux_r3_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_4_R0_9thMux_r1_g1, \
      .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_4_R0_9thMux_r1_g2, \
      .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_4_R0_9thMux_r1_g3, \
      .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_4_R0_10thMux_r1_g1, \
      .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_4_R0_10thMux_r1_g2, \
      .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_4_R0_10thMux_r1_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_5_R0_9thMux_r1_g1, \
      .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_5_R0_9thMux_r1_g2, \
      .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_5_R0_9thMux_r1_g3, \
      .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_5_R0_10thMux_r1_g1, \
      .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_5_R0_10thMux_r1_g2, \
      .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_5_R0_10thMux_r1_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_4_R0_9thMux_r2_g1, \
      .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_4_R0_9thMux_r2_g2, \
      .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_4_R0_9thMux_r2_g3, \
      .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_4_R0_10thMux_r2_g1, \
      .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_4_R0_10thMux_r2_g2, \
      .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_4_R0_10thMux_r2_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_5_R0_9thMux_r2_g1, \
      .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_5_R0_9thMux_r2_g2, \
      .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_5_R0_9thMux_r2_g3, \
      .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_5_R0_10thMux_r2_g1, \
      .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_5_R0_10thMux_r2_g2, \
      .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_5_R0_10thMux_r2_g3, \
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
     [4] = { \
      .tBit.r0_cr_mux9_r3g1 = PARAMSET_ROIC_4_R0_9thMux_r3_g1, \
      .tBit.r0_cr_mux9_r3g2 = PARAMSET_ROIC_4_R0_9thMux_r3_g2, \
      .tBit.r0_cr_mux9_r3g3 = PARAMSET_ROIC_4_R0_9thMux_r3_g3, \
      .tBit.r0_cr_mux10_r3g1 = PARAMSET_ROIC_4_R0_10thMux_r3_g1, \
      .tBit.r0_cr_mux10_r3g2 = PARAMSET_ROIC_4_R0_10thMux_r3_g2, \
      .tBit.r0_cr_mux10_r3g3 = PARAMSET_ROIC_4_R0_10thMux_r3_g3, \
     }, \
     [5] = { \
      .tBit.r0_cr_mux9_r3g1 = PARAMSET_ROIC_5_R0_9thMux_r3_g1, \
      .tBit.r0_cr_mux9_r3g2 = PARAMSET_ROIC_5_R0_9thMux_r3_g2, \
      .tBit.r0_cr_mux9_r3g3 = PARAMSET_ROIC_5_R0_9thMux_r3_g3, \
      .tBit.r0_cr_mux10_r3g1 = PARAMSET_ROIC_5_R0_10thMux_r3_g1, \
      .tBit.r0_cr_mux10_r3g2 = PARAMSET_ROIC_5_R0_10thMux_r3_g2, \
      .tBit.r0_cr_mux10_r3g3 = PARAMSET_ROIC_5_R0_10thMux_r3_g3, \
     }, \
    }, \
    .R0_CR_GTUNE = \
    { \
     [0] = { \
      .tBit.r0_top_fig_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r0_mid_fig_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r0_bot_fig_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r0_pen_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r0_pdrv_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
     [1] = { \
      .tBit.r0_top_fig_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r0_mid_fig_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r0_bot_fig_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r0_pen_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r0_pdrv_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
     [2] = { \
      .tBit.r0_top_fig_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r0_mid_fig_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r0_bot_fig_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r0_pen_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r0_pdrv_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
     [3] = { \
      .tBit.r0_top_fig_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r0_mid_fig_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r0_bot_fig_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r0_pen_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r0_pdrv_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
     [4] = { \
      .tBit.r0_top_fig_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r0_mid_fig_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r0_bot_fig_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r0_pen_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r0_pdrv_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
     [5] = { \
      .tBit.r0_top_fig_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r0_mid_fig_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r0_bot_fig_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r0_pen_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r0_pdrv_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
    }, \
    .R0_TUNE_ROW_MUX1_2 = \
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
    }, \
    .R0_TUNE_ROW_MUX3_4 = \
    { \
     .tBit.r0_cr_mux3_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux3_row1_gsel, \
     .tBit.r0_cr_mux3_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux3_row2_gsel, \
     .tBit.r0_cr_mux3_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux3_row3_gsel, \
     .tBit.r0_cr_mux3_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux3_row4_gsel, \
     .tBit.r0_cr_mux3_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux3_row5_gsel, \
     .tBit.r0_cr_mux4_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux4_row1_gsel, \
     .tBit.r0_cr_mux4_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux4_row2_gsel, \
     .tBit.r0_cr_mux4_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux4_row3_gsel, \
     .tBit.r0_cr_mux4_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux4_row4_gsel, \
     .tBit.r0_cr_mux4_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux4_row5_gsel, \
    }, \
    .R0_TUNE_ROW_MUX5_6 = \
    { \
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
    .R0_TUNE_ROW_MUX7_8 = \
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
    }, \
    .R0_TUNE_ROW_MUX9_10 = \
    { \
     .tBit.r0_cr_mux9_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux9_row1_gsel, \
     .tBit.r0_cr_mux9_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux9_row2_gsel, \
     .tBit.r0_cr_mux9_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux9_row3_gsel, \
     .tBit.r0_cr_mux9_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux9_row4_gsel, \
     .tBit.r0_cr_mux9_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux9_row5_gsel, \
     .tBit.r0_cr_mux10_row1_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux10_row1_gsel, \
     .tBit.r0_cr_mux10_row2_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux10_row2_gsel, \
     .tBit.r0_cr_mux10_row3_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux10_row3_gsel, \
     .tBit.r0_cr_mux10_row4_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux10_row4_gsel, \
     .tBit.r0_cr_mux10_row5_gsel = PARAMSET_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux10_row5_gsel, \
    }, \
    .R0_TUNE_GROUP_COL = \
    { \
     .tBit.r0_cr_col1_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col1_gsel, \
     .tBit.r0_cr_col2_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col2_gsel, \
     .tBit.r0_cr_col3_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col3_gsel, \
     .tBit.r0_cr_col4_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col4_gsel, \
     .tBit.r0_cr_col5_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r0_cr_col5_gsel, \
    }, \
    .R0_PHD_CTL1 = \
    { \
     .tBit.r0_adc_skipnum = 0, \
     .tBit.r0_adc_th = 0, \
    }, \
    .R0_PHD_CTL2 = \
    { \
     .tBit.r0_dly_th = 0, \
     .tBit.r0_offset_dly = 0, \
     .tBit.r0_invalid_dly = 0, \
    }, \
    .R0_PHD_CTL3 = \
    { \
     .tBit.r0_bypass_en = 0, \
     .tBit.r0_coef_val1 = 0, \
     .tBit.r0_coef_val2 = 0, \
     .tBit.r0_adc_mon_data_sel = 0, \
     .tBit.r0_phd_mon_en = 0, \
    }, \
    .R0_PHD_CTL4 = \
    { \
     .tBit.r0_adc_mon_th_r = 0, \
     .tBit.r0_adc_mon_th_f = 0, \
    }, \
    .R0_PHD_SENSE_CTL1 = \
    { \
     .tBit.r0_phd_in_s = 1, \
     .tBit.r0_phd_en = 0, \
     .tBit.r0_rst_phd_en = 1, \
     .tBit.r0_phd_gc_con = 1, \
     .tBit.r0_phd_gc_hov = 1, \
     .tBit.r0_phd_md = 0, \
     .tBit.r0_adc_in_phd = 0, \
     .tBit.r0_stuck_rst_phd = 0, \
     .tBit.r0_stuck_adc_in_phd = 0, \
     .tBit.r0_stuck_phd_md = 0, \
     .tBit.r0_stuck_phd_en = 0, \
    }, \
    .R0_ADC_SENSE_CTL = \
    { \
     .tBit.r0_fig_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_fig_lv_adc_ref_bcon, \
     .tBit.r0_pen_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_pen_lv_adc_ref_bcon, \
     .tBit.r0_pdrv_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_lv_adc_ref_bcon, \
     .tBit.r0_fig_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_fig_lv_adc_bcon, \
     .tBit.r0_pen_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_pen_lv_adc_bcon, \
     .tBit.r0_pdrv_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_lv_adc_bcon, \
     .tBit.r0_adc_clk_div_1p5 = PARAMSET_ROIC_ADC_SENSE_CTL_adc_clk_div_1p5, \
     .tBit.r0_adc_stc_insel = PARAMSET_ROIC_ADC_SENSE_CTL_adc_stc_insel, \
     .tBit.r0_fig_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_comp_bias_ctl, \
     .tBit.r0_pen_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_comp_bias_ctl, \
     .tBit.r0_pdrv_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_comp_bias_ctl, \
     .tBit.r0_fig_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_mdac_comp_ctl, \
     .tBit.r0_pen_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_mdac_comp_ctl, \
     .tBit.r0_pdrv_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_mdac_comp_ctl, \
     .tBit.r0_fig_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_mdac_slew_ctl, \
     .tBit.r0_pen_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_mdac_slew_ctl, \
     .tBit.r0_pdrv_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_mdac_slew_ctl, \
     .tBit.r0_fig_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_ref_idrv_ctl, \
     .tBit.r0_pen_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_ref_idrv_ctl, \
     .tBit.r0_pdrv_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_ref_idrv_ctl, \
    }, \
    .R0_PDB_CTL = \
    { \
     .tBit.r0_pdb_hvbias = 1, \
     .tBit.r0_pdb_hvc = 1, \
     .tBit.r0_pdb_lvbias = 1, \
     .tBit.r0_pdb_int = 1, \
     .tBit.r0_pdb_sha = 1, \
     .tBit.r0_bgr_en = 1, \
     .tBit.r0_bias_en = 1, \
     .tBit.r0_pdb_adc = 1, \
     .tBit.r0_stuck_hvbias = PARAMSET_ROIC_PDB_CTL_stuck_hvbias, \
     .tBit.r0_stuck_hvc = PARAMSET_ROIC_PDB_CTL_stuck_hvc, \
     .tBit.r0_stuck_lvbias = PARAMSET_ROIC_PDB_CTL_stuck_lvbias, \
     .tBit.r0_stuck_int = PARAMSET_ROIC_PDB_CTL_stuck_int, \
     .tBit.r0_stuck_sha = PARAMSET_ROIC_PDB_CTL_stuck_sha, \
     .tBit.r0_stuck_bgr_en = PARAMSET_ROIC_PDB_CTL_stuck_bgr_en, \
     .tBit.r0_stuck_bias_en = PARAMSET_ROIC_PDB_CTL_stuck_bias_en, \
     .tBit.r0_stuck_adc = PARAMSET_ROIC_PDB_CTL_stuck_adc, \
    }, \
    .R0_PDB_PHD_CTL = \
    { \
     .tBit.r0_pdb_phd = 0, \
     .tBit.r0_pdb_phd_buf = 0, \
     .tBit.r0_stuck_phd = 0, \
     .tBit.r0_stuck_phd_buf = 0, \
    }, \
    .R0_RESERVE = \
    { \
     .tBit.r0_reserve = 0, \
    }, \
    .R0_AFE_SENSE_CTL1 = \
    { \
     .tBit.r0_pen_dc_md_stuck = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_dc_md_stuck, \
     .tBit.r0_pre_comp = PARAMSET_ROIC_AFE_SENSE_CTL1_pre_comp, \
     .tBit.r0_fig_int_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_int_ref, \
     .tBit.r0_pen_int_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_int_ref, \
     .tBit.r0_fig_sha_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_int_ref, \
     .tBit.r0_pen_sha_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_sha_ref, \
     .tBit.r0_fig_pre_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_pre_bs_lp, \
     .tBit.r0_pen_pre_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_pre_bs_lp, \
     .tBit.r0_pdrv_pre_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_pdrv_pre_bs_lp, \
     .tBit.r0_fig_int_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_int_bs_lp, \
     .tBit.r0_pen_int_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_int_bs_lp, \
     .tBit.r0_fig_sha_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_sha_bs_lp, \
     .tBit.r0_pen_sha_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_sha_bs_lp, \
    }, \
    .R0_AFE_SENSE_CTL2 = \
    { \
     .tBit.r0_fig_pre_gc = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_pre_gc, \
     .tBit.r0_pen_pre_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_pre_gc_con, \
     .tBit.r0_pen_pre_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_pre_gc_hov, \
     .tBit.r0_pdrv_pre_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_pre_gc_con, \
     .tBit.r0_pdrv_pre_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_pre_gc_hov, \
     .tBit.r0_fig_int_gc = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_int_gc, \
     .tBit.r0_pen_int_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_gc_con, \
     .tBit.r0_pen_int_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_gc_hov, \
     .tBit.r0_fig_int_half = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_int_half, \
     .tBit.r0_pen_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_half_con, \
     .tBit.r0_pen_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_half_hov, \
     .tBit.r0_pdrv_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_int_half_con, \
     .tBit.r0_pdrv_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_int_half_hov, \
    }, \
    .R0_AFE_SENSE_CTL3 = \
    { \
     .tBit.r0_fig_hv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_fig_hv_ssu_bcon, \
     .tBit.r0_pen_hv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_pen_hv_ssu_bcon, \
     .tBit.r0_pdrv_hv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_pdrv_hv_ssu_bcon, \
     .tBit.r0_fig_lv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_fig_lv_ssu_bcon, \
     .tBit.r0_pen_lv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_pen_lv_ssu_bcon, \
     .tBit.r0_fig_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL3_fig_lv_ssu_bcons, \
     .tBit.r0_pen_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL3_pen_lv_ssu_bcons, \
     .tBit.r0_lv_ssu_bconp = PARAMSET_ROIC_AFE_SENSE_CTL3_lv_ssu_bconp, \
     .tBit.r0_lv_ssu_bconp_buf = PARAMSET_ROIC_AFE_SENSE_CTL3_lv_ssu_bconp_buf, \
     .tBit.r0_ref_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_ref_bcon, \
    }, \
    .R0_VCOMR_OPT = \
    { \
     .tBit.r0_display_vcomr = 0, \
     .tBit.r0_touch_f_vcomr = 0, \
     .tBit.r0_touch_p_vcomr = 0, \
     .tBit.r0_stuck_vcomr = 0, \
     .tBit.r0_stuck_vcomr_level = 0, \
     .tBit.r0_tsync_opt = 0, \
    }, \
    .R0_BUF_OPT = \
    { \
     .tBit.r0_double_buf_en = 1, \
     .tBit.r0_pre_drv_en = 0, \
     .tBit.r0_pdrv_buf_st_num = 0, \
    }, \
    .R0_TG_STUCK = \
    { \
     .tBit.r0_stuck_rstp = 0, \
     .tBit.r0_stuck_phtcr = 0, \
     .tBit.r0_stuck_vcr = 0, \
     .tBit.r0_stuck_rsti = 0, \
     .tBit.r0_stuck_phth0 = 0, \
     .tBit.r0_stuck_phth1 = 0, \
     .tBit.r0_stuck_pht0 = 0, \
     .tBit.r0_stuck_pht1 = 0, \
     .tBit.r0_stuck_muxs_en = 0, \
     .tBit.r0_stuck_muxf_en = 0, \
     .tBit.r0_vcr_inv_en = 0, \
     .tBit.r0_fig_stuck_vcr_en_odd = 1, \
     .tBit.r0_pen_stuck_vcr_en_odd = 0, \
     .tBit.r0_fig_stuck_vcr_en_even = 1, \
     .tBit.r0_pen_stuck_vcr_en_even = 0, \
    }, \
    .R0_ADC_IN_CTL = \
    { \
     .tBit.r0_adc_in = PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_in, \
     .tBit.r0_adc_op_opt = PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_op_opt, \
    }, \
    .R0_UPLINK_MUX = \
    { \
     .tBit.r0_uplink_mux = 1023, \
     .tBit.r0_uplink_state = 0, \
    }, \
    .R0_LHB_MUX_CTL = \
    { \
     .tBit.r0_mux_m1_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_r0_mux_m1_bit_en, \
     .tBit.r0_mux_nd_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_r0_mux_nd_bit_en, \
     .tBit.r0_mux_pp_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_r0_mux_pp_bit_en, \
     .tBit.r0_mux_pd_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_r0_mux_pd_bit_en, \
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
    }, \
    .R1_SYS_CFG = \
    { \
     .tBit.r1_buf_clk_on = 1, \
     .tBit.r1_cfclk_on = 0, \
    }, \
    .R1_CH_EN = \
    { \
     .tBit.r1_dum_drv_en = 0, \
     .tBit.r1_ch_en_int = 127, \
     .tBit.r1_ch_en_hvc = 511, \
    }, \
    .R1_MUX_CTL = \
    { \
     .tBit.r1_top_mux_num = 0, \
     .tBit.r1_bot_mux_num = 9, \
     .tBit.r1_mux_int_en = 0, \
     .tBit.r1_mux_int_stuck_val = 0, \
     .tBit.r1_mux_off_en = 0, \
    }, \
    .R1_MUX_S_STUCK_VAL = \
    { \
     .tBit.r1_mux_s_stuck = 0, \
     .tBit.r1_mux_s_line_stuck = 0, \
    }, \
    .R1_MUX_F_STUCK_VAL = \
    { \
     .tBit.r1_mux_f_stuck_val = 0, \
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
     [4] = { \
      .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_4_R1_1stMux_r1_g1, \
      .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_4_R1_1stMux_r1_g2, \
      .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_4_R1_1stMux_r1_g3, \
      .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_4_R1_2ndMux_r1_g1, \
      .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_4_R1_2ndMux_r1_g2, \
      .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_4_R1_2ndMux_r1_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_5_R1_1stMux_r1_g1, \
      .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_5_R1_1stMux_r1_g2, \
      .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_5_R1_1stMux_r1_g3, \
      .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_5_R1_2ndMux_r1_g1, \
      .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_5_R1_2ndMux_r1_g2, \
      .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_5_R1_2ndMux_r1_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_4_R1_1stMux_r2_g1, \
      .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_4_R1_1stMux_r2_g2, \
      .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_4_R1_1stMux_r2_g3, \
      .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_4_R1_2ndMux_r2_g1, \
      .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_4_R1_2ndMux_r2_g2, \
      .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_4_R1_2ndMux_r2_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_5_R1_1stMux_r2_g1, \
      .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_5_R1_1stMux_r2_g2, \
      .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_5_R1_1stMux_r2_g3, \
      .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_5_R1_2ndMux_r2_g1, \
      .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_5_R1_2ndMux_r2_g2, \
      .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_5_R1_2ndMux_r2_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_4_R1_1stMux_r3_g1, \
      .tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_4_R1_1stMux_r3_g2, \
      .tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_4_R1_1stMux_r3_g3, \
      .tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_4_R1_2ndMux_r3_g1, \
      .tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_4_R1_2ndMux_r3_g2, \
      .tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_4_R1_2ndMux_r3_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux1_r3g1 = PARAMSET_ROIC_5_R1_1stMux_r3_g1, \
      .tBit.r1_cr_mux1_r3g2 = PARAMSET_ROIC_5_R1_1stMux_r3_g2, \
      .tBit.r1_cr_mux1_r3g3 = PARAMSET_ROIC_5_R1_1stMux_r3_g3, \
      .tBit.r1_cr_mux2_r3g1 = PARAMSET_ROIC_5_R1_2ndMux_r3_g1, \
      .tBit.r1_cr_mux2_r3g2 = PARAMSET_ROIC_5_R1_2ndMux_r3_g2, \
      .tBit.r1_cr_mux2_r3g3 = PARAMSET_ROIC_5_R1_2ndMux_r3_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_4_R1_3rdMux_r1_g1, \
      .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_4_R1_3rdMux_r1_g2, \
      .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_4_R1_3rdMux_r1_g3, \
      .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_4_R1_4thMux_r1_g1, \
      .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_4_R1_4thMux_r1_g2, \
      .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_4_R1_4thMux_r1_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_5_R1_3rdMux_r1_g1, \
      .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_5_R1_3rdMux_r1_g2, \
      .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_5_R1_3rdMux_r1_g3, \
      .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_5_R1_4thMux_r1_g1, \
      .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_5_R1_4thMux_r1_g2, \
      .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_5_R1_4thMux_r1_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_4_R1_3rdMux_r2_g1, \
      .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_4_R1_3rdMux_r2_g2, \
      .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_4_R1_3rdMux_r2_g3, \
      .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_4_R1_4thMux_r2_g1, \
      .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_4_R1_4thMux_r2_g2, \
      .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_4_R1_4thMux_r2_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_5_R1_3rdMux_r2_g1, \
      .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_5_R1_3rdMux_r2_g2, \
      .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_5_R1_3rdMux_r2_g3, \
      .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_5_R1_4thMux_r2_g1, \
      .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_5_R1_4thMux_r2_g2, \
      .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_5_R1_4thMux_r2_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_4_R1_3rdMux_r3_g1, \
      .tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_4_R1_3rdMux_r3_g2, \
      .tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_4_R1_3rdMux_r3_g3, \
      .tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_4_R1_4thMux_r3_g1, \
      .tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_4_R1_4thMux_r3_g2, \
      .tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_4_R1_4thMux_r3_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux3_r3g1 = PARAMSET_ROIC_5_R1_3rdMux_r3_g1, \
      .tBit.r1_cr_mux3_r3g2 = PARAMSET_ROIC_5_R1_3rdMux_r3_g2, \
      .tBit.r1_cr_mux3_r3g3 = PARAMSET_ROIC_5_R1_3rdMux_r3_g3, \
      .tBit.r1_cr_mux4_r3g1 = PARAMSET_ROIC_5_R1_4thMux_r3_g1, \
      .tBit.r1_cr_mux4_r3g2 = PARAMSET_ROIC_5_R1_4thMux_r3_g2, \
      .tBit.r1_cr_mux4_r3g3 = PARAMSET_ROIC_5_R1_4thMux_r3_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_4_R1_5thMux_r1_g1, \
      .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_4_R1_5thMux_r1_g2, \
      .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_4_R1_5thMux_r1_g3, \
      .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_4_R1_6thMux_r1_g1, \
      .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_4_R1_6thMux_r1_g2, \
      .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_4_R1_6thMux_r1_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_5_R1_5thMux_r1_g1, \
      .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_5_R1_5thMux_r1_g2, \
      .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_5_R1_5thMux_r1_g3, \
      .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_5_R1_6thMux_r1_g1, \
      .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_5_R1_6thMux_r1_g2, \
      .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_5_R1_6thMux_r1_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_4_R1_5thMux_r2_g1, \
      .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_4_R1_5thMux_r2_g2, \
      .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_4_R1_5thMux_r2_g3, \
      .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_4_R1_6thMux_r2_g1, \
      .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_4_R1_6thMux_r2_g2, \
      .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_4_R1_6thMux_r2_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_5_R1_5thMux_r2_g1, \
      .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_5_R1_5thMux_r2_g2, \
      .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_5_R1_5thMux_r2_g3, \
      .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_5_R1_6thMux_r2_g1, \
      .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_5_R1_6thMux_r2_g2, \
      .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_5_R1_6thMux_r2_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_4_R1_5thMux_r3_g1, \
      .tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_4_R1_5thMux_r3_g2, \
      .tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_4_R1_5thMux_r3_g3, \
      .tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_4_R1_6thMux_r3_g1, \
      .tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_4_R1_6thMux_r3_g2, \
      .tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_4_R1_6thMux_r3_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux5_r3g1 = PARAMSET_ROIC_5_R1_5thMux_r3_g1, \
      .tBit.r1_cr_mux5_r3g2 = PARAMSET_ROIC_5_R1_5thMux_r3_g2, \
      .tBit.r1_cr_mux5_r3g3 = PARAMSET_ROIC_5_R1_5thMux_r3_g3, \
      .tBit.r1_cr_mux6_r3g1 = PARAMSET_ROIC_5_R1_6thMux_r3_g1, \
      .tBit.r1_cr_mux6_r3g2 = PARAMSET_ROIC_5_R1_6thMux_r3_g2, \
      .tBit.r1_cr_mux6_r3g3 = PARAMSET_ROIC_5_R1_6thMux_r3_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_4_R1_7thMux_r1_g1, \
      .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_4_R1_7thMux_r1_g2, \
      .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_4_R1_7thMux_r1_g3, \
      .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_4_R1_8thMux_r1_g1, \
      .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_4_R1_8thMux_r1_g2, \
      .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_4_R1_8thMux_r1_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_5_R1_7thMux_r1_g1, \
      .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_5_R1_7thMux_r1_g2, \
      .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_5_R1_7thMux_r1_g3, \
      .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_5_R1_8thMux_r1_g1, \
      .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_5_R1_8thMux_r1_g2, \
      .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_5_R1_8thMux_r1_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_4_R1_7thMux_r2_g1, \
      .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_4_R1_7thMux_r2_g2, \
      .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_4_R1_7thMux_r2_g3, \
      .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_4_R1_8thMux_r2_g1, \
      .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_4_R1_8thMux_r2_g2, \
      .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_4_R1_8thMux_r2_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_5_R1_7thMux_r2_g1, \
      .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_5_R1_7thMux_r2_g2, \
      .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_5_R1_7thMux_r2_g3, \
      .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_5_R1_8thMux_r2_g1, \
      .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_5_R1_8thMux_r2_g2, \
      .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_5_R1_8thMux_r2_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux7_r3g1 = PARAMSET_ROIC_4_R1_7thMux_r3_g1, \
      .tBit.r1_cr_mux7_r3g2 = PARAMSET_ROIC_4_R1_7thMux_r3_g2, \
      .tBit.r1_cr_mux7_r3g3 = PARAMSET_ROIC_4_R1_7thMux_r3_g3, \
      .tBit.r1_cr_mux8_r3g1 = PARAMSET_ROIC_4_R1_8thMux_r3_g1, \
      .tBit.r1_cr_mux8_r3g2 = PARAMSET_ROIC_4_R1_8thMux_r3_g2, \
      .tBit.r1_cr_mux8_r3g3 = PARAMSET_ROIC_4_R1_8thMux_r3_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux7_r3g1 = PARAMSET_ROIC_5_R1_7thMux_r3_g1, \
      .tBit.r1_cr_mux7_r3g2 = PARAMSET_ROIC_5_R1_7thMux_r3_g2, \
      .tBit.r1_cr_mux7_r3g3 = PARAMSET_ROIC_5_R1_7thMux_r3_g3, \
      .tBit.r1_cr_mux8_r3g1 = PARAMSET_ROIC_5_R1_8thMux_r3_g1, \
      .tBit.r1_cr_mux8_r3g2 = PARAMSET_ROIC_5_R1_8thMux_r3_g2, \
      .tBit.r1_cr_mux8_r3g3 = PARAMSET_ROIC_5_R1_8thMux_r3_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_4_R1_9thMux_r1_g1, \
      .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_4_R1_9thMux_r1_g2, \
      .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_4_R1_9thMux_r1_g3, \
      .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_4_R1_10thMux_r1_g1, \
      .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_4_R1_10thMux_r1_g2, \
      .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_4_R1_10thMux_r1_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_5_R1_9thMux_r1_g1, \
      .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_5_R1_9thMux_r1_g2, \
      .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_5_R1_9thMux_r1_g3, \
      .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_5_R1_10thMux_r1_g1, \
      .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_5_R1_10thMux_r1_g2, \
      .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_5_R1_10thMux_r1_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_4_R1_9thMux_r2_g1, \
      .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_4_R1_9thMux_r2_g2, \
      .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_4_R1_9thMux_r2_g3, \
      .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_4_R1_10thMux_r2_g1, \
      .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_4_R1_10thMux_r2_g2, \
      .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_4_R1_10thMux_r2_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_5_R1_9thMux_r2_g1, \
      .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_5_R1_9thMux_r2_g2, \
      .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_5_R1_9thMux_r2_g3, \
      .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_5_R1_10thMux_r2_g1, \
      .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_5_R1_10thMux_r2_g2, \
      .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_5_R1_10thMux_r2_g3, \
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
     [4] = { \
      .tBit.r1_cr_mux9_r3g1 = PARAMSET_ROIC_4_R1_9thMux_r3_g1, \
      .tBit.r1_cr_mux9_r3g2 = PARAMSET_ROIC_4_R1_9thMux_r3_g2, \
      .tBit.r1_cr_mux9_r3g3 = PARAMSET_ROIC_4_R1_9thMux_r3_g3, \
      .tBit.r1_cr_mux10_r3g1 = PARAMSET_ROIC_4_R1_10thMux_r3_g1, \
      .tBit.r1_cr_mux10_r3g2 = PARAMSET_ROIC_4_R1_10thMux_r3_g2, \
      .tBit.r1_cr_mux10_r3g3 = PARAMSET_ROIC_4_R1_10thMux_r3_g3, \
     }, \
     [5] = { \
      .tBit.r1_cr_mux9_r3g1 = PARAMSET_ROIC_5_R1_9thMux_r3_g1, \
      .tBit.r1_cr_mux9_r3g2 = PARAMSET_ROIC_5_R1_9thMux_r3_g2, \
      .tBit.r1_cr_mux9_r3g3 = PARAMSET_ROIC_5_R1_9thMux_r3_g3, \
      .tBit.r1_cr_mux10_r3g1 = PARAMSET_ROIC_5_R1_10thMux_r3_g1, \
      .tBit.r1_cr_mux10_r3g2 = PARAMSET_ROIC_5_R1_10thMux_r3_g2, \
      .tBit.r1_cr_mux10_r3g3 = PARAMSET_ROIC_5_R1_10thMux_r3_g3, \
     }, \
    }, \
    .R1_CR_GTUNE = \
    { \
     [0] = { \
      .tBit.r1_top_fig_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r1_mid_fig_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r1_bot_fig_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r1_pen_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r1_pdrv_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
     [1] = { \
      .tBit.r1_top_fig_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r1_mid_fig_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r1_bot_fig_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r1_pen_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r1_pdrv_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
     [2] = { \
      .tBit.r1_top_fig_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r1_mid_fig_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r1_bot_fig_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r1_pen_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r1_pdrv_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
     [3] = { \
      .tBit.r1_top_fig_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r1_mid_fig_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r1_bot_fig_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r1_pen_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r1_pdrv_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
     [4] = { \
      .tBit.r1_top_fig_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r1_mid_fig_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r1_bot_fig_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r1_pen_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r1_pdrv_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
     [5] = { \
      .tBit.r1_top_fig_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_Finger_Top_Global_Tune, \
      .tBit.r1_mid_fig_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_Finger_Middle_Global_Tune, \
      .tBit.r1_bot_fig_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_Finger_Bottom_Global_Tune, \
      .tBit.r1_pen_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_Pen_Global_Tune, \
      .tBit.r1_pdrv_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_PRE_DRV_Global_Tune, \
     }, \
    }, \
    .R1_TUNE_ROW_MUX1_2 = \
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
    }, \
    .R1_TUNE_ROW_MUX3_4 = \
    { \
     .tBit.r1_cr_mux3_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux3_row1_gsel, \
     .tBit.r1_cr_mux3_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux3_row2_gsel, \
     .tBit.r1_cr_mux3_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux3_row3_gsel, \
     .tBit.r1_cr_mux3_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux3_row4_gsel, \
     .tBit.r1_cr_mux3_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux3_row5_gsel, \
     .tBit.r1_cr_mux4_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux4_row1_gsel, \
     .tBit.r1_cr_mux4_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux4_row2_gsel, \
     .tBit.r1_cr_mux4_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux4_row3_gsel, \
     .tBit.r1_cr_mux4_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux4_row4_gsel, \
     .tBit.r1_cr_mux4_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux4_row5_gsel, \
    }, \
    .R1_TUNE_ROW_MUX5_6 = \
    { \
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
    .R1_TUNE_ROW_MUX7_8 = \
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
    }, \
    .R1_TUNE_ROW_MUX9_10 = \
    { \
     .tBit.r1_cr_mux9_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux9_row1_gsel, \
     .tBit.r1_cr_mux9_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux9_row2_gsel, \
     .tBit.r1_cr_mux9_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux9_row3_gsel, \
     .tBit.r1_cr_mux9_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux9_row4_gsel, \
     .tBit.r1_cr_mux9_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux9_row5_gsel, \
     .tBit.r1_cr_mux10_row1_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux10_row1_gsel, \
     .tBit.r1_cr_mux10_row2_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux10_row2_gsel, \
     .tBit.r1_cr_mux10_row3_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux10_row3_gsel, \
     .tBit.r1_cr_mux10_row4_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux10_row4_gsel, \
     .tBit.r1_cr_mux10_row5_gsel = PARAMSET_ROIC_R1_TUNE_ROW_MUX_r1_cr_mux10_row5_gsel, \
    }, \
    .R1_TUNE_GROUP_COL = \
    { \
     .tBit.r1_cr_col1_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col1_gsel, \
     .tBit.r1_cr_col2_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col2_gsel, \
     .tBit.r1_cr_col3_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col3_gsel, \
     .tBit.r1_cr_col4_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col4_gsel, \
     .tBit.r1_cr_col5_gsel = PARAMSET_ROIC_CFGR_R_TUNE_GROUP_COL_r1_cr_col5_gsel, \
    }, \
    .R1_PHD_CTL1 = \
    { \
     .tBit.r1_adc_skipnum = 0, \
     .tBit.r1_adc_th = 0, \
    }, \
    .R1_PHD_CTL2 = \
    { \
     .tBit.r1_dly_th = 0, \
     .tBit.r1_offset_dly = 0, \
     .tBit.r1_invalid_dly = 0, \
    }, \
    .R1_PHD_CTL3 = \
    { \
     .tBit.r1_bypass_en = 0, \
     .tBit.r1_coef_val1 = 0, \
     .tBit.r1_coef_val2 = 0, \
     .tBit.r1_adc_mon_data_sel = 0, \
     .tBit.r1_phd_mon_en = 0, \
    }, \
    .R1_PHD_CTL4 = \
    { \
     .tBit.r1_adc_mon_th_r = 0, \
     .tBit.r1_adc_mon_th_f = 0, \
    }, \
    .R1_PHD_SENSE_CTL1 = \
    { \
     .tBit.r1_phd_in_s = 1, \
     .tBit.r1_phd_en = 0, \
     .tBit.r1_rst_phd_en = 1, \
     .tBit.r1_phd_gc_con = 2, \
     .tBit.r1_phd_gc_hov = 2, \
     .tBit.r1_phd_md = 0, \
     .tBit.r1_adc_in_phd = 0, \
     .tBit.r1_stuck_rst_phd = 0, \
     .tBit.r1_stuck_adc_in_phd = 0, \
     .tBit.r1_stuck_phd_md = 0, \
     .tBit.r1_stuck_phd_en = 0, \
    }, \
    .R1_ADC_SENSE_CTL = \
    { \
     .tBit.r1_fig_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_fig_lv_adc_ref_bcon, \
     .tBit.r1_pen_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_fig_lv_adc_ref_bcon, \
     .tBit.r1_pdrv_lv_adc_ref_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_fig_lv_adc_ref_bcon, \
     .tBit.r1_fig_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_fig_lv_adc_bcon, \
     .tBit.r1_pen_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_pen_lv_adc_bcon, \
     .tBit.r1_pdrv_lv_adc_bcon = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_lv_adc_bcon, \
     .tBit.r1_adc_clk_div_1p5 = PARAMSET_ROIC_ADC_SENSE_CTL_adc_clk_div_1p5, \
     .tBit.r1_adc_stc_insel = PARAMSET_ROIC_ADC_SENSE_CTL_adc_stc_insel, \
     .tBit.r1_fig_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_comp_bias_ctl, \
     .tBit.r1_pen_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_comp_bias_ctl, \
     .tBit.r1_pdrv_adc_comp_bias_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_comp_bias_ctl, \
     .tBit.r1_fig_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_mdac_comp_ctl, \
     .tBit.r1_pen_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_mdac_comp_ctl, \
     .tBit.r1_pdrv_adc_mdac_comp_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_mdac_comp_ctl, \
     .tBit.r1_fig_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_mdac_slew_ctl, \
     .tBit.r1_pen_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_mdac_slew_ctl, \
     .tBit.r1_pdrv_adc_mdac_slew_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_mdac_slew_ctl, \
     .tBit.r1_fig_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_fig_adc_ref_idrv_ctl, \
     .tBit.r1_pen_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pen_adc_ref_idrv_ctl, \
     .tBit.r1_pdrv_adc_ref_idrv_ctl = PARAMSET_ROIC_ADC_SENSE_CTL_pdrv_adc_ref_idrv_ctl, \
    }, \
    .R1_PDB_CTL = \
    { \
     .tBit.r1_pdb_hvbias = 1, \
     .tBit.r1_pdb_hvc = 1, \
     .tBit.r1_pdb_lvbias = 1, \
     .tBit.r1_pdb_int = 1, \
     .tBit.r1_pdb_sha = 1, \
     .tBit.r1_bgr_en = 1, \
     .tBit.r1_bias_en = 1, \
     .tBit.r1_pdb_adc = 1, \
     .tBit.r1_stuck_hvbias = PARAMSET_ROIC_PDB_CTL_stuck_hvbias, \
     .tBit.r1_stuck_hvc = PARAMSET_ROIC_PDB_CTL_stuck_hvc, \
     .tBit.r1_stuck_lvbias = PARAMSET_ROIC_PDB_CTL_stuck_lvbias, \
     .tBit.r1_stuck_int = PARAMSET_ROIC_PDB_CTL_stuck_int, \
     .tBit.r1_stuck_sha = PARAMSET_ROIC_PDB_CTL_stuck_sha, \
     .tBit.r1_stuck_bgr_en = PARAMSET_ROIC_PDB_CTL_stuck_bgr_en, \
     .tBit.r1_stuck_bias_en = PARAMSET_ROIC_PDB_CTL_stuck_bias_en, \
     .tBit.r1_stuck_adc = PARAMSET_ROIC_PDB_CTL_stuck_adc, \
    }, \
    .R1_PDB_PHD_CTL = \
    { \
     .tBit.r1_pdb_phd = 0, \
     .tBit.r1_pdb_phd_buf = 0, \
     .tBit.r1_stuck_phd = 0, \
     .tBit.r1_stuck_phd_buf = 0, \
    }, \
    .R1_RESERVE = \
    { \
     .tBit.r1_reserve = 0, \
    }, \
    .R1_AFE_SENSE_CTL1 = \
    { \
     .tBit.r1_pen_dc_md_stuck = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_dc_md_stuck, \
     .tBit.r1_pre_comp = PARAMSET_ROIC_AFE_SENSE_CTL1_pre_comp, \
     .tBit.r1_fig_int_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_int_ref, \
     .tBit.r1_pen_int_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_int_ref, \
     .tBit.r1_fig_sha_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_sha_ref, \
     .tBit.r1_pen_sha_ref = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_sha_ref, \
     .tBit.r1_fig_pre_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_pre_bs_lp, \
     .tBit.r1_pen_pre_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_pre_bs_lp, \
     .tBit.r1_pdrv_pre_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_pdrv_pre_bs_lp, \
     .tBit.r1_fig_int_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_int_bs_lp, \
     .tBit.r1_pen_int_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_int_bs_lp, \
     .tBit.r1_fig_sha_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_fig_sha_bs_lp, \
     .tBit.r1_pen_sha_bs_lp = PARAMSET_ROIC_AFE_SENSE_CTL1_pen_sha_bs_lp, \
    }, \
    .R1_AFE_SENSE_CTL2 = \
    { \
     .tBit.r1_fig_pre_gc = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_pre_gc, \
     .tBit.r1_pen_pre_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_pre_gc_con, \
     .tBit.r1_pen_pre_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_pre_gc_hov, \
     .tBit.r1_pdrv_pre_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_pre_gc_con, \
     .tBit.r1_pdrv_pre_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_pre_gc_hov, \
     .tBit.r1_fig_int_gc = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_int_gc, \
     .tBit.r1_pen_int_gc_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_gc_con, \
     .tBit.r1_pen_int_gc_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_gc_hov, \
     .tBit.r1_fig_int_half = PARAMSET_ROIC_AFE_SENSE_CTL2_fig_int_half, \
     .tBit.r1_pen_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_half_con, \
     .tBit.r1_pen_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pen_int_half_hov, \
     .tBit.r1_pdrv_int_half_con = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_int_half_con, \
     .tBit.r1_pdrv_int_half_hov = PARAMSET_ROIC_AFE_SENSE_CTL2_pdrv_int_half_hov, \
    }, \
    .R1_AFE_SENSE_CTL3 = \
    { \
     .tBit.r1_fig_hv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_fig_hv_ssu_bcon, \
     .tBit.r1_pen_hv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_pen_hv_ssu_bcon, \
     .tBit.r1_pdrv_hv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_pdrv_hv_ssu_bcon, \
     .tBit.r1_fig_lv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_fig_lv_ssu_bcon, \
     .tBit.r1_pen_lv_ssu_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_pen_lv_ssu_bcon, \
     .tBit.r1_fig_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL3_fig_lv_ssu_bcons, \
     .tBit.r1_pen_lv_ssu_bcons = PARAMSET_ROIC_AFE_SENSE_CTL3_pen_lv_ssu_bcons, \
     .tBit.r1_lv_ssu_bconp = PARAMSET_ROIC_AFE_SENSE_CTL3_lv_ssu_bconp, \
     .tBit.r1_lv_ssu_bconp_buf = PARAMSET_ROIC_AFE_SENSE_CTL3_lv_ssu_bconp_buf, \
     .tBit.r1_ref_bcon = PARAMSET_ROIC_AFE_SENSE_CTL3_ref_bcon, \
    }, \
    .R1_VCOMR_OPT = \
    { \
     .tBit.r1_display_vcomr = 0, \
     .tBit.r1_touch_f_vcomr = 0, \
     .tBit.r1_touch_p_vcomr = 0, \
     .tBit.r1_stuck_vcomr = 0, \
     .tBit.r1_stuck_vcomr_level = 0, \
     .tBit.r1_tsync_opt = 0, \
    }, \
    .R1_BUF_OPT = \
    { \
     .tBit.r1_double_buf_en = 1, \
     .tBit.r1_pre_drv_en = 0, \
     .tBit.r1_pdrv_buf_st_num = 0, \
    }, \
    .R1_TG_STUCK = \
    { \
     .tBit.r1_stuck_rstp = 0, \
     .tBit.r1_stuck_phtcr = 0, \
     .tBit.r1_stuck_vcr = 0, \
     .tBit.r1_stuck_rsti = 0, \
     .tBit.r1_stuck_phth0 = 0, \
     .tBit.r1_stuck_phth1 = 0, \
     .tBit.r1_stuck_pht0 = 0, \
     .tBit.r1_stuck_pht1 = 0, \
     .tBit.r1_stuck_muxs_en = 0, \
     .tBit.r1_stuck_muxf_en = 0, \
     .tBit.r1_vcr_inv_en = 0, \
     .tBit.r1_fig_stuck_vcr_en_odd = 1, \
     .tBit.r1_pen_stuck_vcr_en_odd = 0, \
     .tBit.r1_fig_stuck_vcr_en_even = 1, \
     .tBit.r1_pen_stuck_vcr_en_even = 0, \
    }, \
    .R1_ADC_IN_CTL = \
    { \
     .tBit.r1_adc_in = PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_in, \
     .tBit.r1_adc_op_opt = PARAMSET_ROIC_CFGR_ADC_IN_CTL_adc_op_opt, \
    }, \
    .R1_UPLINK_MUX = \
    { \
     .tBit.r1_uplink_mux = 1023, \
     .tBit.r1_uplink_state = 0, \
    }, \
    .R1_LHB_MUX_CTL = \
    { \
     .tBit.r1_mux_m1_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_r1_mux_m1_bit_en, \
     .tBit.r1_mux_nd_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_r1_mux_nd_bit_en, \
     .tBit.r1_mux_pp_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_r1_mux_pp_bit_en, \
     .tBit.r1_mux_pd_bit_en = PARAMSET_ROIC_LHB_MUX_CTL_r1_mux_pd_bit_en, \
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
    }, \
    .APEN_CFCLK_ON = \
    { \
     .tBit.apen_cfclk_on = 0, \
    },


#define SRIC_MSPEN_Conf_Set	\
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
	.SPIS_ERROR_ST = \
	{ \
		.tBit.spi_chksum_err = 0, \
		.tBit.tsync_fault_err = 0, \
		.tBit.pwm_fault_err = 0, \
	}, \
	.SPIS_PAD_CTL = \
	{ \
		.tBit.miso_ds = 1, \
		.tBit.miso_dout = 0, \
		.tBit.miso_func = 0, \
		.tBit.mosi_ds = 1, \
		.tBit.mosi_dout = 0, \
		.tBit.mosi_func = 0, \
	}, \
	.CFGR_SYS_CFG = \
	{ \
		.tBit.tg_reset = 0, \
		.tBit.sw_reset = 0, \
		.tBit.tg_clk_all_on = 1, \
		.tBit.buf_clk_on = 1, \
		.tBit.cfclk_on = 0, \
	}, \
	.CFGR_TC_START = \
	{ \
		.tBit.tc_start = 0, \
		.tBit.scan_cont = 1, \
	}, \
	.CFGR_TC_STOP = \
	{ \
		.tBit.tc_stop = 0, \
	}, \
	.CFGR_R0_CH_EN = \
	{ \
		.tBit.ch_num = 18, \
		.tBit.ch_en_lvr = 127, \
		.tBit.ch_en_hvr = 511, \
		.tBit.dum_drv_en = 0, \
	}, \
	.CFGR_R1_CH_EN = \
	{ \
		.tBit.ch_num = 18, \
		.tBit.ch_en_lvr = 127, \
		.tBit.ch_en_hvr = 511, \
		.tBit.dum_drv_en = 0, \
	}, \
	.CFGR_MUX_EN = \
	{ \
		.tBit.mux_int_en = 0, \
		.tBit.mux_num_tot = 8, \
	}, \
	.CFGR_MUX_DLY = \
	{ \
		.tBit.mux_dly = 0, \
	}, \
	.CFGR_DIC_CFG = \
	{ \
		.tBit.sd_off = 0, \
		.tBit.sd_float = 0, \
		.tBit.tsync_in_pol = 0, \
		.tBit.pwm_pol = 0, \
		.tBit.tsync_out_pol = 0, \
		.tBit.tsync_out_bypass = 1, \
		.tBit.tsync_out_stuck = 0, \
		.tBit.tsync_out_level = 0, \
		.tBit.vsync_pol = 0, \
		.tBit.vsync_tg_en = 0, \
		.tBit.vsync_tg_act = 0, \
		.tBit.cfgr_stuck_sd_stat = 0, \
		.tBit.cfgr_sr_stat = 0, \
		.tBit.cfgr_sd_all = 0, \
		.tBit.cfgr_sd_dir = 0, \
		.tBit.sd_hvdd = 0, \
		.tBit.tsync2_pol = 0, \
	}, \
	.CFGR_PWM_CTL = \
	{ \
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_MPP_PWM_CTL_pwm_pdrv_num, \
		.tBit.pwm_act_num = PARAMSET_ROIC_MPP_PWM_CTL_pwm_act_num, \
		.tBit.pwm_smpl_num = PARAMSET_ROIC_MPP_PWM_CTL_pwm_smpl_num, \
		.tBit.pwm_dum_num = PARAMSET_ROIC_MPP_PWM_CTL_pwm_dum_num, \
		.tBit.pdrv_dum_num = PARAMSET_ROIC_MPP_PWM_CTL_pdrv_dum_num, \
		.tBit.pwm_set_num = PARAMSET_ROIC_MPP_PWM_CTL_pwm_set_num, \
	}, \
	.CFGR_PWM_POS_CTL = \
	{ \
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_pdrv_num, \
		.tBit.pwm_act_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_act_num, \
		.tBit.pwm_smpl_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_smpl_num, \
		.tBit.pwm_dum_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_dum_num, \
		.tBit.pdrv_dum_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pdrv_dum_num, \
		.tBit.pwm_set_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_set_num, \
	}, \
	.CFGR_PWM_DAT_CTL = \
	{ \
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_pdrv_num, \
		.tBit.pwm_act_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_act_num, \
		.tBit.pwm_smpl_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_smpl_num, \
		.tBit.pwm_dum_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_dum_num, \
		.tBit.pdrv_dum_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pdrv_dum_num, \
		.tBit.pwm_set_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_set_num, \
	}, \
	.ND_CTRL = \
	{ \
		.tBit.nd_dum_dly = PARAMSET_ROIC_MPP_ND_CTRL_nd_dum_dly, \
	}, \
	.CFGR_PWM_PRD = \
	{ \
		.tBit.pwm_prd1 = PARAMSET_ROIC_MPP_CFGR_PWM_PRD_pwm_prd1, \
		.tBit.pwm_prd2 = PARAMSET_ROIC_MPP_CFGR_PWM_PRD_pwm_prd2, \
	}, \
	.CFGR_SMPL_CTL = \
	{ \
		.tBit.smop_prd_1 = PARAMSET_ROIC_MPP_CFGR_SMPL_CTL_smop_prd_1, \
		.tBit.smop_prd_2 = PARAMSET_ROIC_MPP_CFGR_SMPL_CTL_smop_prd_2, \
		.tBit.crrpt_num = PARAMSET_ROIC_MPP_CFGR_SMPL_CTL_crrpt_num, \
	}, \
	.CFGR_RSTP_NUM1 = \
	{ \
		.tBit.rstp_num1 = PARAMSET_ROIC_MPP_CFGR_RSTP_NUM1_rstp_num1, \
		.tBit.rstp_num2 = PARAMSET_ROIC_MPP_CFGR_RSTP_NUM1_rstp_num2, \
	}, \
	.CFGR_PHT_NUM1 = \
	{ \
		.tBit.pht_num1 = PARAMSET_ROIC_MPP_CFGR_PHT_NUM1_pht_num1, \
		.tBit.pht_num2 = PARAMSET_ROIC_MPP_CFGR_PHT_NUM1_pht_num2, \
	}, \
	.CFGR_PHTCR_NUM1 = \
	{ \
		.tBit.phtcr_num1_1 = PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM1_phtcr_num1_1, \
		.tBit.phtcr_num1_2 = PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM1_phtcr_num1_2, \
	}, \
	.CFGR_PHTCR_NUM2 = \
	{ \
		.tBit.phtcr_num2_1 = PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM2_phtcr_num2_1, \
		.tBit.phtcr_num2_2 = PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM2_phtcr_num2_2, \
	}, \
	.CFGR_VCR_NUM1 = \
	{ \
		.tBit.vcr_num1_1 = PARAMSET_ROIC_MPP_CFGR_VCR_NUM1_vcr_num1_1, \
		.tBit.vcr_num1_2 = PARAMSET_ROIC_MPP_CFGR_VCR_NUM1_vcr_num1_2, \
	}, \
	.CFGR_VCR_EN_NUM1 = \
	{ \
		.tBit.vcr_en_num1_1 = PARAMSET_ROIC_MPP_CFGR_VCR_EN_NUM1_vcr_en_num1_1, \
		.tBit.vcr_en_num1_2 = PARAMSET_ROIC_MPP_CFGR_VCR_EN_NUM1_vcr_en_num1_2, \
	}, \
	.CFGR_VCR_EN_NUM2 = \
	{ \
		.tBit.vcr_en_num2_1 = PARAMSET_ROIC_MPP_CFGR_VCR_EN_NUM2_vcr_en_num2_1, \
		.tBit.vcr_en_num2_2 = PARAMSET_ROIC_MPP_CFGR_VCR_EN_NUM2_vcr_en_num2_2, \
	}, \
	.CFGR_PHTH0_NUM1 = \
	{ \
		.tBit.phth0_num1_1 = PARAMSET_ROIC_MPP_CFGR_PHTH0_NUM1_phth0_num1_1, \
		.tBit.phth0_num1_2 = PARAMSET_ROIC_MPP_CFGR_PHTH0_NUM1_phth0_num1_2, \
	}, \
	.CFGR_PHTH1_NUM1 = \
	{ \
		.tBit.phth1_num1_1 = PARAMSET_ROIC_MPP_CFGR_PHTH1_NUM1_phth1_num1_1, \
		.tBit.phth1_num1_2 = PARAMSET_ROIC_MPP_CFGR_PHTH1_NUM1_phth1_num1_2, \
	}, \
	.CFGR_PHTH_NUM2 = \
	{ \
		.tBit.phth0_num2 = PARAMSET_ROIC_MPP_CFGR_PHTH_NUM2_phth0_num2, \
		.tBit.phth1_num2 = PARAMSET_ROIC_MPP_CFGR_PHTH_NUM2_phth1_num2, \
	}, \
	.CFGR_PHT_CTL = \
	{ \
		.tBit.pht_prd = PARAMSET_ROIC_MPP_CFGR_PHT_CTL_pht_prd, \
		.tBit.pht_opt_smpl = PARAMSET_ROIC_MPP_CFGR_PHT_CTL_pht_opt_smpl, \
		.tBit.pht_opt_inv = PARAMSET_ROIC_MPP_CFGR_PHT_CTL_pht_opt_inv, \
		.tBit.pht_etime = PARAMSET_ROIC_MPP_CFGR_PHT_CTL_pht_etime, \
	}, \
	.CFGR_ADC_CTRL = \
	{ \
		.tBit.adc_op_opt = PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_op_opt, \
		.tBit.adc_clk_opt = PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_clk_opt, \
		.tBit.adc_clk_pol = PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_clk_pol, \
		.tBit.adc_clk_prd = PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_clk_prd, \
		.tBit.adc_clk_num = PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_clk_num, \
		.tBit.adc_in_pos = PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_in_pos, \
		.tBit.adc_stc_dly = PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_stc_dly, \
		.tBit.adc_clk_spt = PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_clk_spt, \
		.tBit.cfgr_tm_adc = PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_cfgr_tm_adc, \
	}, \
	.CFGR_VCOMR_OPT = \
	{ \
		.tBit.display_vcomr = PARAMSET_MPP_VCOMR, \
		.tBit.touch_f_vcomr = PARAMSET_MPP_VCOMR, \
		.tBit.touch_p_vcomr = PARAMSET_MPP_VCOMR, \
		.tBit.stuck_left = 0, \
		.tBit.stuck_right = 0, \
		.tBit.stuck_level = 0, \
		.tBit.tsync_opt = 0, \
	}, \
	.CFGR_BUF_OPT = \
	{ \
		.tBit.double_buf_en = 1, \
	}, \
	.CFGR_TG_STUCK = \
	{ \
		[0] = \
		{ \
			.tBit.stuck_rstp = 0, \
			.tBit.stuck_phtcr = 0, \
			.tBit.stuck_vcr = 0,/*1, VCR Low, 0 VCR High*/ \
			.tBit.stuck_rsti = 0, \
			.tBit.stuck_phth0 = 0, \
			.tBit.stuck_phth1 = 0, \
			.tBit.stuck_pht0 = 0, \
			.tBit.stuck_pht1 = 0, \
			.tBit.stuck_vcr_odd_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_vcr_even_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_muxs_en = 0, /*0,*/ \
			.tBit.stuck_muxf_en = 0, \
		}, \
		[1] = \
		{ \
			.tBit.stuck_rstp = 0, \
			.tBit.stuck_phtcr = 0, \
			.tBit.stuck_vcr = 0,/*1, VCR Low, 0 VCR High*/ \
			.tBit.stuck_rsti = 0, \
			.tBit.stuck_phth0 = 0, \
			.tBit.stuck_phth1 = 0, \
			.tBit.stuck_pht0 = 0, \
			.tBit.stuck_pht1 = 0, \
			.tBit.stuck_vcr_odd_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_vcr_even_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_muxs_en = 0, /*0,*/ \
			.tBit.stuck_muxf_en = 0, \
		}, \
		[2] = \
		{ \
			.tBit.stuck_rstp = 0, \
			.tBit.stuck_phtcr = 0, \
			.tBit.stuck_vcr = 0,/*1, VCR Low, 0 VCR High*/ \
			.tBit.stuck_rsti = 0, \
			.tBit.stuck_phth0 = 0, \
			.tBit.stuck_phth1 = 0, \
			.tBit.stuck_pht0 = 0, \
			.tBit.stuck_pht1 = 0, \
			.tBit.stuck_vcr_odd_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_vcr_even_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_muxs_en = 0, /*0,*/ \
			.tBit.stuck_muxf_en = 0, \
		}, \
		[3] = \
		{ \
			.tBit.stuck_rstp = 0, \
			.tBit.stuck_phtcr = 0, \
			.tBit.stuck_vcr = 0,/*1, VCR Low, 0 VCR High*/ \
			.tBit.stuck_rsti = 0, \
			.tBit.stuck_phth0 = 0, \
			.tBit.stuck_phth1 = 0, \
			.tBit.stuck_pht0 = 0, \
			.tBit.stuck_pht1 = 0, \
			.tBit.stuck_vcr_odd_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_vcr_even_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_muxs_en = 0, /*0,*/ \
			.tBit.stuck_muxf_en = 0, \
		}, \
		[4] = \
		{ \
			.tBit.stuck_rstp = 0, \
			.tBit.stuck_phtcr = 0, \
			.tBit.stuck_vcr = 0,/*1, VCR Low, 0 VCR High*/ \
			.tBit.stuck_rsti = 0, \
			.tBit.stuck_phth0 = 0, \
			.tBit.stuck_phth1 = 0, \
			.tBit.stuck_pht0 = 0, \
			.tBit.stuck_pht1 = 0, \
			.tBit.stuck_vcr_odd_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_vcr_even_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_muxs_en = 0, /*0,*/ \
			.tBit.stuck_muxf_en = 0, \
		}, \
		[5] = \
		{ \
			.tBit.stuck_rstp = 0, \
			.tBit.stuck_phtcr = 0, \
			.tBit.stuck_vcr = 0,/*1, VCR Low, 0 VCR High*/ \
			.tBit.stuck_rsti = 0, \
			.tBit.stuck_phth0 = 0, \
			.tBit.stuck_phth1 = 0, \
			.tBit.stuck_pht0 = 0, \
			.tBit.stuck_pht1 = 0, \
			.tBit.stuck_vcr_odd_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_vcr_even_en = 3,/*1, VCR disable, 3 VCR enable*/ \
			.tBit.stuck_muxs_en = 0, /*0,*/ \
			.tBit.stuck_muxf_en = 0, \
		}, \
	}, \
	.CFGR_ADC_IN = \
	{ \
		.tBit.adc_in = 1, \
	}, \
	.CFGR_MUX_S_STUCK_VAL = \
	{ \
		.tBit.mux_s_stuck_val = 0, \
	}, \
	.CFGR_MUX_F_STUCK_VAL = \
	{ \
		.tBit.mux_f_stuck_val = 0, \
	}, \
	.CFGR_MUX_CFG_00 = \
	{ \
		.tBit.MUX_00 = 0, \
		.tBit.MUX_01 = 1, \
		.tBit.MUX_02 = 2, \
		.tBit.MUX_03 = 3, \
		.tBit.MUX_04 = 4, \
		.tBit.MUX_05 = 5, \
		.tBit.MUX_06 = 6, \
		.tBit.MUX_07 = 7, \
	}, \
	.CFGR_MUX_CFG_01 = \
	{ \
		.tBit.MUX_08 = 8, \
		.tBit.MUX_09 = 9, \
		.tBit.MUX_10 = 10, \
		.tBit.MUX_11 = 11, \
		.tBit.MUX_12 = 12, \
		.tBit.MUX_13 = 13, \
		.tBit.MUX_14 = 14, \
		.tBit.MUX_15 = 15, \
	}, \
	.LHB_CFG = { \
		[PWM_FULL_FINGER_MODE] = \
		{ \
			[0] = \
			{ \
				.tBit.mode = SW92511_MODE_BEACON, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[1] = \
			{ \
				.tBit.mode = SW92511_MODE_DUMMY, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[2] = \
			{ \
				.tBit.mode = SW92511_MODE_DUMMY, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[3] = \
			{ \
				.tBit.mode = SW92511_MODE_DUMMY, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[4] = \
			{ \
				.tBit.mode = SW92511_MODE_FINGER, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 2, \
				.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_1Mux, \
				.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_2Mux, \
				.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_3Mux, \
				.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_4Mux, \
			}, \
			[5] = \
			{ \
				.tBit.mode = SW92511_MODE_DUMMY, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[6] = \
			{ \
				.tBit.mode = SW92511_MODE_FINGER, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 2, \
				.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_1Mux, \
				.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_2Mux, \
				.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_3Mux, \
				.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_4Mux, \
			}, \
			[7] = \
			{ \
				.tBit.mode = SW92511_MODE_FINGER, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 2, \
				.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_1Mux, \
				.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_2Mux, \
				.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_3Mux, \
				.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_4Mux, \
			}, \
			[8] = \
			{ \
				.tBit.mode = SW92511_MODE_BEACON, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[9] = \
			{ \
				.tBit.mode = SW92511_MODE_DUMMY, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[10] = \
			{ \
				.tBit.mode = SW92511_MODE_DUMMY, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[11] = \
			{ \
				.tBit.mode = SW92511_MODE_DUMMY, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[12] = \
			{ \
				.tBit.mode = SW92511_MODE_FINGER, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 2, \
				.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_1Mux, \
				.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_2Mux, \
				.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_3Mux, \
				.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_4Mux, \
			}, \
			[13] = \
			{ \
				.tBit.mode = SW92511_MODE_DUMMY, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[14] = \
			{ \
				.tBit.mode = SW92511_MODE_FINGER, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 2, \
				.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_1Mux, \
				.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_2Mux, \
				.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_3Mux, \
				.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_4Mux, \
			}, \
			[15] = \
			{ \
				.tBit.mode = SW92511_MODE_FINGER, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 2, \
				.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_1Mux, \
				.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_2Mux, \
				.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_3Mux, \
				.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_4Mux, \
			}, \
		}, \
		[PWM_LOCAL_PEN_MODE] = \
		{ \
			[0] = \
			{ \
				.tBit.mode = SW92511_MODE_BEACON, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[1] = \
			{ \
				.tBit.mode = SW92511_MODE_PEN_POS, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 5, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[2] = \
			{ \
				.tBit.mode = SW92511_MODE_PEN_DATA, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 5, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[3] = \
			{ \
				.tBit.mode = SW92511_MODE_PEN_DATA, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 5, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[4] = \
			{ \
				.tBit.mode = SW92511_MODE_PEN_DATA, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 5, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[5] = \
			{ \
				.tBit.mode = SW92511_MODE_PEN_POS, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 5, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[6] = \
			{ \
				.tBit.mode = SW92511_MODE_PEN_DATA, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 5, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[7] = \
			{ \
				.tBit.mode = SW92511_MODE_DUMMY, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[8] = \
			{ \
				.tBit.mode = SW92511_MODE_BEACON, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[9] = \
			{ \
				.tBit.mode = SW92511_MODE_PEN_DATA, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 5, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[10] = \
			{ \
				.tBit.mode = SW92511_MODE_DUMMY, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[11] = \
			{ \
				.tBit.mode = SW92511_MODE_DUMMY, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 0, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 0, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[12] = \
			{ \
				.tBit.mode = SW92511_MODE_FINGER, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 2, \
				.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_1Mux, \
				.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_2Mux, \
				.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_3Mux, \
				.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_4Mux, \
			}, \
			[13] = \
			{ \
				.tBit.mode = SW92511_MODE_PEN_POS, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 5, \
				.tBit.local_pos0 = 0, \
				.tBit.local_pos1 = 0, \
				.tBit.local_pos2 = 0, \
				.tBit.local_pos3 = 0, \
			}, \
			[14] = \
			{ \
				.tBit.mode = SW92511_MODE_FINGER, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 2, \
				.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_1Mux, \
				.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_2Mux, \
				.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_3Mux, \
				.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_4Mux, \
			}, \
			[15] = \
			{ \
				.tBit.mode = SW92511_MODE_FINGER, \
				.tBit.ping_en = 0, \
				.tBit.pre_drv = 1, \
				.tBit.pre_drvs_en = 0, \
				.tBit.extmuxcmd = 0, \
				.tBit.mux_type = 0, \
				.tBit.lhb_mux_cnt = 2, \
				.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_1Mux, \
				.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_2Mux, \
				.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_3Mux, \
				.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_4Mux, \
			}, \
		}, \
	}, \
	.CFGR_PWM_SET_EN_BIT = \
	{ \
		.tBit.pwm_set_en_finger = PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_finger, \
		.tBit.pwm_set_en_pen_pos = PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_pos, \
		.tBit.pwm_set_en_pen_dat = PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_dat, \
	}, \
	.CFGR_LHB_MUX_CTRL = \
	{ \
		.tBit.m1_mode_sel = 0, \
		.tBit.pd_mux_num = 3, \
		.tBit.mux_m1_bit_en = 0x3FF, \
		.tBit.mux_nd_bit_en = 0, \
		.tBit.max_lhb_cnt = 15,/*14,*/ \
		.tBit.ping_mux_type = 0, \
		.tBit.ping_mux_local_sel = 0, \
	}, \
	.CFGR_PING_MUX_CTRL = \
	{ \
		.tBit.ping_max = 0, \
		.tBit.ping_end_offset = 0, \
		.tBit.mux_ping_bit_en = 0, \
		.tBit.pin_mux_sel = 0, \
		.tBit.ping_mode = 0, \
	}, \
	.CFGR_PRE_DRV_CTRL = \
	{ \
		.tBit.mux_pdrv_bit_en = 1, \
		.tBit.pdrv_mux_sel = 1, \
	}, \
	.CFGR_PEN_MUX_BIT_EN = \
	{ \
		.tBit.mux_beacon_bit_en = 0, \
		.tBit.mux_pen_pos_bit_en = 1, \
		.tBit.mux_pen_dat_bit_en = 1, \
	}, \
	.CFGR_PDRV_SUB_BIT_EN = \
	{ \
		.tBit.mux_pdrv_pos_sub_bit = 255, \
		.tBit.mux_pdrv_dat_sub_bit = 255, \
	}, \
	.R0_CR1_MUX1_1 = \
	{ \
		[0] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_0_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_0_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_0_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_1_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_1_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_1_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_2_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_2_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_2_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_3_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_3_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_3_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_4_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_4_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_4_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_5_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_5_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_5_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g3, \
		}, \
	}, \
	.R0_CR1_MUX1_2 = \
	{ \
		[0] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g3, \
		}, \
	}, \
	.R0_CR1_MUX2 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R0_2ndMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R0_2ndMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R0_2ndMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R0_2ndMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R0_2ndMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R0_2ndMux_g3, \
		}, \
	}, \
	.R0_CR1_MUX3 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R0_3rdMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R0_3rdMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R0_3rdMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R0_3rdMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R0_3rdMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R0_3rdMux_g3, \
		}, \
	}, \
	.R0_CR1_MUX4 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R0_4thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R0_4thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R0_4thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R0_4thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R0_4thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R0_4thMux_g3, \
		}, \
	}, \
	.R0_CR1_MUX5 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R0_5thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R0_5thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R0_5thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R0_5thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R0_5thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R0_5thMux_g3, \
		}, \
	}, \
	.R0_CR1_MUX6 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R0_6thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R0_6thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R0_6thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R0_6thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R0_6thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R0_6thMux_g3, \
		}, \
	}, \
	.R0_CR1_MUX7 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R0_7thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R0_7thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R0_7thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R0_7thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R0_7thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R0_7thMux_g3, \
		}, \
	}, \
	.R0_CR1_MUX8 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R0_8thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R0_8thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R0_8thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R0_8thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R0_8thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R0_8thMux_g3, \
		}, \
	}, \
	.R0_CR1_MUX9 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R0_9thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R0_9thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R0_9thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R0_9thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R0_9thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R0_9thMux_g3, \
		}, \
	}, \
	.R0_CR1_MUX10_1 = \
	{ \
		[0] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_0_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_0_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_0_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_1_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_1_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_1_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_2_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_2_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_2_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_3_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_3_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_3_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_4_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_4_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_4_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_5_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_5_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_5_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g3, \
		}, \
	}, \
	.R0_CR1_MUX10_2 = \
	{ \
		[0] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g3, \
		}, \
	}, \
	.R0_CR_GTUNE = \
	{ \
		[0] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE_PenData_Global_Tune, \
		}, \
		[1] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE_PenData_Global_Tune, \
		}, \
		[2] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE_PenData_Global_Tune, \
		}, \
		[3] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE_PenData_Global_Tune, \
		}, \
		[4] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE_PenData_Global_Tune, \
		}, \
		[5] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE_PenData_Global_Tune, \
		}, \
	}, \
	.R0_CFGR_TUNE_GROUP = \
	{ \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_R0_TUNE_GROUP_cr_rg2_sel,/* 2, */ \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_R0_TUNE_GROUP_cr_rg3_sel,/* 28, */ \
	}, \
	.R1_CR1_MUX1_1 = \
	{ \
		[0] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_0_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_0_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_0_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_1_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_1_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_1_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_2_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_2_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_2_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_3_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_3_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_3_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_4_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_4_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_4_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_5_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_5_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_5_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g3, \
		}, \
	}, \
	.R1_CR1_MUX1_2 = \
	{ \
		[0] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g3, \
		}, \
	}, \
	.R1_CR1_MUX2 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R1_2ndMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R1_2ndMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R1_2ndMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R1_2ndMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R1_2ndMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R1_2ndMux_g3, \
		}, \
	}, \
	.R1_CR1_MUX3 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R1_3rdMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R1_3rdMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R1_3rdMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R1_3rdMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R1_3rdMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R1_3rdMux_g3, \
		}, \
	}, \
	.R1_CR1_MUX4 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R1_4thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R1_4thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R1_4thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R1_4thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R1_4thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R1_4thMux_g3, \
		}, \
	}, \
	.R1_CR1_MUX5 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R1_5thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R1_5thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R1_5thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R1_5thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R1_5thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R1_5thMux_g3, \
		}, \
	}, \
	.R1_CR1_MUX6 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R1_6thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R1_6thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R1_6thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R1_6thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R1_6thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R1_6thMux_g3, \
		}, \
	}, \
	.R1_CR1_MUX7 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R1_7thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R1_7thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R1_7thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R1_7thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R1_7thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R1_7thMux_g3, \
		}, \
	}, \
	.R1_CR1_MUX8 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R1_8thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R1_8thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R1_8thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R1_8thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R1_8thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R1_8thMux_g3, \
		}, \
	}, \
	.R1_CR1_MUX9 = \
	{ \
		[0] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_0_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_0_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_0_R1_9thMux_g3, \
		}, \
		[1] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_1_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_1_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_1_R1_9thMux_g3, \
		}, \
		[2] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_2_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_2_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_2_R1_9thMux_g3, \
		}, \
		[3] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_3_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_3_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_3_R1_9thMux_g3, \
		}, \
		[4] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_4_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_4_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_4_R1_9thMux_g3, \
		}, \
		[5] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_5_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_5_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_5_R1_9thMux_g3, \
		}, \
	}, \
	.R1_CR1_MUX10_1 = \
	{ \
		[0] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_0_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_0_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_0_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g3, \
		}, \
		[1] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_1_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_1_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_1_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g3, \
		}, \
		[2] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_2_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_2_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_2_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g3, \
		}, \
		[3] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_3_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_3_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_3_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g3, \
		}, \
		[4] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_4_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_4_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_4_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g3, \
		}, \
		[5] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_5_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_5_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_5_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g3, \
		}, \
	}, \
	.R1_CR1_MUX10_2 = \
	{ \
		[0] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g3, \
		}, \
		[1] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g3, \
		}, \
		[2] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g3, \
		}, \
		[3] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g3, \
		}, \
		[4] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g3, \
		}, \
		[5] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g3, \
		}, \
	}, \
	.R1_CR_GTUNE = \
	{ \
		[0] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE_PenData_Global_Tune, \
		}, \
		[1] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE_PenData_Global_Tune, \
		}, \
		[2] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE_PenData_Global_Tune, \
		}, \
		[3] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE_PenData_Global_Tune, \
		}, \
		[4] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE_PenData_Global_Tune, \
		}, \
		[5] = { \
			.tBit.cr_fg_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_Finger_Global_Tune, \
			.tBit.cr_pn_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_PenPos_Global_Tune, \
			.tBit.cr_pd_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE_PenData_Global_Tune, \
		}, \
	}, \
	.R1_CFGR_TUNE_GROUP = \
	{ \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_R1_TUNE_GROUP_cr_rg2_sel,/* 2, */ \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_R1_TUNE_GROUP_cr_rg3_sel,/* 28, */ \
	}, \
	.CFGR_SENSE_CTRL = \
	{ \
		.tBit.lv_ssu_bcon = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_lv_ssu_bcon, \
		.tBit.lv_ssu_bcons = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_lv_ssu_bcons, \
		.tBit.hv_ssu_bcon = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_hv_ssu_bcon, \
		.tBit.pen_dc_md = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pen_dc_md, \
		.tBit.pen_dc_md_stuck = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pen_dc_md_stuck, \
		.tBit.integ_half_f = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_f, \
		.tBit.integ_half_comp = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_comp, \
		.tBit.integ_half_p = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_p, \
		.tBit.pre_gc_f = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_f, \
		.tBit.pre_gc_comp = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_comp, \
		.tBit.pre_gc_p = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_p, \
		.tBit.int_gc_f = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_f, \
		.tBit.int_gc_comp = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_comp, \
		.tBit.int_gc_p = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_p, \
		.tBit.powsel = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_powsel, \
		.tBit.pre_bs_lp = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_bs_lp, \
		.tBit.int_bs_lp = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_bs_lp, \
		.tBit.tm_ssu_pen = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_tm_ssu_pen, \
	}, \
	.CFGR_COMP_ADC_CTRL = \
	{ \
		.tBit.adc_bcon = PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_bcon, \
		.tBit.adc_stc_insel = PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_stc_insel, \
		.tBit.adc_dsf = PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_dsf, \
		.tBit.adc_ref_sel = PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_ref_sel, \
		.tBit.int_ref = PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_int_ref, \
		.tBit.sha_ref = PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_sha_ref, \
		.tBit.sha_bs_lp = PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_sha_bs_lp, \
		.tBit.ref_res_sel = PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_ref_res_sel, \
		.tBit.lv_comp_bcon = PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_lv_comp_bcon, \
		.tBit.comp_hys_ctrl = PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_comp_hys_ctrl, \
		.tBit.tm_comp = PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_tm_comp, \
	}, \
	.CFGR_SSU_PW_CTRL = \
	{ \
		.tBit.pdb_hvbias = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_hvbias, \
		.tBit.pdb_hvr = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_hvr, \
		.tBit.pdb_lvbias = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_lvbias, \
		.tBit.pdb_lvr = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_lvr, \
		.tBit.pdb_sha = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_sha, \
		.tBit.bgr_en = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_bgr_en, \
		.tBit.pdb_adc = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_adc, \
		.tBit.pdb_compbias = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_compbias, \
		.tBit.pdb_comp = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_comp, \
		.tBit.stuck_hvbias = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_hvbias, \
		.tBit.stuck_hvr = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_hvr, \
		.tBit.stuck_lvbias = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_lvbias, \
		.tBit.stuck_lvr = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_lvr, \
		.tBit.stuck_sha = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_sha, \
		.tBit.stuck_bgr = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_bgr, \
		.tBit.stuck_adc = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_adc, \
		.tBit.stuck_compbias = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_compbias, \
		.tBit.stuck_comp = PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_comp, \
	}, \
	.CFGR_TUNE_LOWER = \
	{ \
		.tBit.lower_mux_num = PARAMSET_ROIC_1stMUX_IDX, \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_1stMUX_TUNE_GROUP_cr_rg2_sel, \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_1stMUX_TUNE_GROUP_cr_rg3_sel, \
	}, \
	.CFGR_TUNE_UPPER = \
	{ \
		.tBit.upper_mux_num = PARAMSET_ROIC_LastMUX_IDX, \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_LastMUX_TUNE_GROUP_cr_rg2_sel, \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_LastMUX_TUNE_GROUP_cr_rg3_sel, \
	}, \
	.TAFE_REV_SIG = \
	{ \
 		.tBit.r0_pre_ch_con_en	= PARAMSET_MPP_PRE_CH_CON_EN, \
		.tBit.r0_pre_comp	    = PARAMSET_MPP_PRE_COMP, \
		.tBit.r0_reserve     	= 2, \
		.tBit.r1_pre_ch_con_en	= PARAMSET_MPP_PRE_CH_CON_EN, \
		.tBit.r1_pre_comp	    = PARAMSET_MPP_PRE_COMP, \
		.tBit.r1_reserve	    = 2, \
	}, \
	.SYS_DUMMY0 = \
	{ \
		.tBit.sd_rocen	= 0, \
		.tBit.sd_pwrcr2	= 0, \
		.tBit.sd_pwrcr3	= 0, \
		.tBit.reserve	= 0, \
	}, \
	.SYS_DUMMY1 = \
	{ \
		.tBit.sd_pwrcr1	= 1, \
		.tBit.reserve	= 0x7FFFFFFF, \
	}, \
	.CFGR_COMP_CTRL = \
	{ \
		.tBit.sel_rw_width = 2, \
		.tBit.dly_offset = 0, \
		.tBit.max_insert_dly = 100, \
		.tBit.insert_dly_sel = 1, \
		.tBit.comp_mon_sel = 0, \
		.tBit.sel_offset = 0, \
		.tBit.comp_err_chk_en = 0, \
		.tBit.sel_comp_redge = 0, \
		.tBit.sel_comp_fedge = 0, \
	}, \
	.CFGR_COMP_RSTI_NUM = \
	{ \
		.tBit.comp_rsti_num1 = 22, \
		.tBit.comp_rsti_num2 = 20, \
		.tBit.rsti_select = 0, \
	}, \
	.CFGR_COMP_WINDOW_1 = \
	{ \
		.tBit.comp_rwidth_redge = 45, \
		.tBit.comp_rwidth_fedge = 0, \
	}, \
	.CFGR_COMP_WINDOW_2 = \
	{ \
		.tBit.comp_fwidth_redge = 45, \
		.tBit.comp_fwidth_fedge = 0, \
	}, \
	.COMP_STATUS = \
	{ \
		.tBit.insert_dly_val = 0, \
		.tBit.rwidth_rdat = 0, \
		.tBit.fwidth_rdat = 0, \
	}, \


#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
#define SRIC_Conf_Set		SRIC_WGPPEN_Conf_Set
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
#define SRIC_Conf_Set		SRIC_MSPEN_Conf_Set
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN)
#define SRIC_Conf_Set		SRIC_WACOMPEN_Conf_Set
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
#define SRIC_Conf_Set		SRIC_MSPEN_Conf_Set
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) */

#endif /* (USED_ROIC_DEF == ROIC_SW92511) */

#endif /* __SW92511_PARAMPRESET_H_ */
