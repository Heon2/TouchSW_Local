/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _sw97500_parampreset.h
 * created on : 10. 3. 2019
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

#ifndef __SW97500_PARAMPRESET_H_
#define __SW97500_PARAMPRESET_H_


#if (USED_ROIC_DEF == ROIC_SW97500)
#define SRIC_Conf_Set	\
	.tParam_SPIS_CFG = \
	{ \
		.tBit.spis_irq_en = PARAMSET_ROIC_SPIS_CFG_spis_irq_en, \
		.tBit.miso_func = PARAMSET_ROIC_SPIS_CFG_miso_func, \
	}, \
	.tParam_SPIS_ERROR_CLR = \
	{ \
		.tBit.spi_chksum_clr = PARAMSET_ROIC_SPIS_ERROR_CLR_spi_chksum_clr, \
		.tBit.tsync_fault_clr = PARAMSET_ROIC_SPIS_ERROR_CLR_tsync_fault_clr, \
		.tBit.pwm_fault_clr = PARAMSET_ROIC_SPIS_ERROR_CLR_pwm_fault_clr, \
	}, \
	.tParam_SPIS_ERROR_ST = \
	{ \
		.tBit.spi_chksum_err = PARAMSET_ROIC_SPIS_ERROR_ST_spi_chksum_err, \
		.tBit.tsync_fault_err = PARAMSET_ROIC_SPIS_ERROR_ST_tsync_fault_err, \
		.tBit.pwm_fault_err = PARAMSET_ROIC_SPIS_ERROR_ST_pwm_fault_err, \
	}, \
	.tParam_CFGR_SYS_CFG = \
	{ \
		.tBit.tg_reset = PARAMSET_ROIC_CFGR_SYS_CFG_tg_reset, \
		.tBit.sw_reset = PARAMSET_ROIC_CFGR_SYS_CFG_sw_reset, \
		.tBit.tg_clk_all_on = PARAMSET_ROIC_CFGR_SYS_CFG_tg_clk_all_on, \
		.tBit.buf_clk_on = PARAMSET_ROIC_CFGR_SYS_CFG_buf_clk_on, \
	}, \
	.tParam_CFGR_TC_START = \
	{ \
		.tBit.tc_start = PARAMSET_ROIC_CFGR_TC_START_tc_start, \
		.tBit.scan_cont = PARAMSET_ROIC_CFGR_TC_START_scan_con, \
	}, \
	.tParam_CFGR_TC_STOP = \
	{ \
		.tBit.tc_stop = PARAMSET_ROIC_CFGR_TC_STOP_tc_stop, \
	}, \
	.tParam_CFGR_CH_EN = \
	{ \
		.tBit.ch_num = PARAMSET_ROIC_CFGR_CH_EN_ch_num, \
		.tBit.ch_en_lvr = PARAMSET_ROIC_CFGR_CH_EN_ch_en_lvr, \
		.tBit.reserve0 = PARAMSET_ROIC_CFGR_CH_EN_reserve0, \
		.tBit.ch_en_hvr = PARAMSET_ROIC_CFGR_CH_EN_ch_en_hvr, \
		.tBit.reserve1 = PARAMSET_ROIC_CFGR_CH_EN_reserve1, \
		.tBit.dum_drv_en = PARAMSET_ROIC_CFGR_CH_EN_dum_drv_en, \
		.tBit.stuck_lvr_en = PARAMSET_ROIC_CFGR_CH_EN_stuck_lvr_en, \
		.tBit.stuck_hvr_en = PARAMSET_ROIC_CFGR_CH_EN_stuck_hvr_en, \
	}, \
	.tParam_CFGR_MUX_EN = \
	{ \
		.tBit.mux_bit_en = PARAMSET_ROIC_CFGR_MUX_EN_mux_bit_en, \
		.tBit.mux_int_en = PARAMSET_ROIC_CFGR_MUX_EN_mux_int_en, \
		.tBit.mux_num_tot = PARAMSET_ROIC_CFGR_MUX_EN_mux_num_tot, \
		.tBit.mux_num_tsync = PARAMSET_ROIC_CFGR_MUX_EN_mux_num_tsync, \
		.tBit.m1_mux_en = PARAMSET_ROIC_CFGR_MUX_EN_m1_mux_en, \
	}, \
	.tParam_CFGR_DIC_CFG = \
	{ \
		.tBit.sd_off = PARAMSET_ROIC_CFGR_DIC_CFG_sd_off, \
		.tBit.sd_float = PARAMSET_ROIC_CFGR_DIC_CFG_sd_float, \
		.tBit.tsync_in_pol = PARAMSET_ROIC_CFGR_DIC_CFG_tsync_in_pol, \
		.tBit.pwm_pol = PARAMSET_ROIC_CFGR_DIC_CFG_pwm_pol, \
		.tBit.tsync_out_pol = PARAMSET_ROIC_CFGR_DIC_CFG_tsync_out_pol, \
		.tBit.tsync_out_bypass = PARAMSET_ROIC_CFGR_DIC_CFG_tsync_out_bypass, \
		.tBit.tsync_out_stuck = PARAMSET_ROIC_CFGR_DIC_CFG_tsync_out_stuck, \
		.tBit.tsync_out_level = PARAMSET_ROIC_CFGR_DIC_CFG_tsync_out_level, \
		.tBit.vsync_pol = PARAMSET_ROIC_CFGR_DIC_CFG_vsync_pol, \
		.tBit.vsync_tg_en = PARAMSET_ROIC_CFGR_DIC_CFG_vsync_tg_en, \
		.tBit.vsync_tg_act = PARAMSET_ROIC_CFGR_DIC_CFG_vsync_tg_act, \
		.tBit.stuck_abd = PARAMSET_ROIC_CFGR_DIC_CFG_stuck_abd, \
		.tBit.cfgr_abd = PARAMSET_ROIC_CFGR_DIC_CFG_cfgr_abd, \
		.tBit.cfgr_abd_pol = PARAMSET_ROIC_CFGR_DIC_CFG_cfgr_abd_pol, \
		.tBit.cfgr_abd_inv = PARAMSET_ROIC_CFGR_DIC_CFG_cfgr_abd_inv, \
		.tBit.sd_hvdd = PARAMSET_ROIC_CFGR_DIC_CFG_sd_hvdd, \
	}, \
	.tParam_CFGR_PWM_CTL = \
	{ \
		.tBit.pwm_num = PARAMSET_ROIC_CFGR_PWM_CTL_pwm_num, \
		.tBit.pwm_act_num = PARAMSET_ROIC_CFGR_PWM_CTL_pwm_act_num, \
		.tBit.pwm_smpl_num = PARAMSET_ROIC_CFGR_PWM_CTL_pwm_smpl_num, \
		.tBit.pwm_dum_num = PARAMSET_ROIC_CFGR_PWM_CTL_pwm_dum_num, \
	}, \
	.tParam_ND_CTRL = \
	{ \
		.tBit.nd_dum_dly = PARAMSET_ROIC_ND_CTRL_nd_dum_dly, \
	}, \
	.tParam_CFGR_PWM_PRD = \
	{ \
		.tBit.pwm_prd1 = PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd1, \
		.tBit.pwm_prd2 = PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd2, \
	}, \
	.tParam_CFGR_SMPL_CTL = \
	{ \
		.tBit.smop_prd_1 = PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd, \
		.tBit.smop_prd_2 = PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd, \
		.tBit.crrpt_num = PARAMSET_ROIC_CFGR_SMPL_CTL_crrpt_num, \
	}, \
	.tParam_CFGR_RSTP_NUM1 = \
	{ \
		.tBit.rstp_num1 = PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num1, \
		.tBit.rstp_num2 = PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num2, \
	}, \
	.tParam_CFGR_PHTCR_NUM1 = \
	{ \
		.tBit.phtcr_num1_1 = PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_1, \
		.tBit.phtcr_num1_2 = PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_2, \
	}, \
	.tParam_CFGR_PHTCR_NUM2 = \
	{ \
		.tBit.phtcr_num2_1 = PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_1, \
		.tBit.phtcr_num2_2 = PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_2, \
	}, \
	.tParam_CFGR_VCR_NUM1 = \
	{ \
		.tBit.vcr_num1_1 = PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_1, \
		.tBit.vcr_num1_2 = PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_2, \
	}, \
	.tParam_CFGR_VCR_EN_NUM1 = \
	{ \
		.tBit.vcr_en_num1_1 = PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_1, \
		.tBit.vcr_en_num1_2 = PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_2, \
	}, \
	.tParam_CFGR_VCR_EN_NUM2 = \
	{ \
		.tBit.vcr_en_num2_1 = PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_1, \
		.tBit.vcr_en_num2_2 = PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_2, \
	}, \
	.tParam_CFGR_PHTH0_NUM1 = \
	{ \
		.tBit.phth0_num1_1 = PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_1, \
		.tBit.phth0_num1_2 = PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_2, \
	}, \
	.tParam_CFGR_PHTH1_NUM1 = \
	{ \
		.tBit.phth1_num1_1 = PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_1, \
		.tBit.phth1_num1_2 = PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_2, \
	}, \
	.tParam_CFGR_PHTH_NUM2 = \
	{ \
		.tBit.phth0_num2 = PARAMSET_ROIC_CFGR_PHTH_NUM2_phth0_num2, \
		.tBit.phth1_num2 = PARAMSET_ROIC_CFGR_PHTH_NUM2_phth1_num2, \
	}, \
	.tParam_CFGR_PHT_CTL = \
	{ \
		.tBit.pht_prd = PARAMSET_ROIC_CFGR_PHT_CTL_pht_prd, \
		.tBit.pht_opt_smpl = PARAMSET_ROIC_CFGR_PHT_CTL_pht_opt_smpl, \
		.tBit.pht_opt_inv = PARAMSET_ROIC_CFGR_PHT_CTL_pht_opt_inv, \
		.tBit.pht_etime = PARAMSET_ROIC_CFGR_PHT_CTL_pht_etime, \
	}, \
	.tParam_CFGR_PHT_NUM1 = \
	{ \
		.tBit.pht_num1 = PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num1, \
		.tBit.pht_num2 = PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num2, \
	}, \
	.tParam_CFGR_ADC_CTRL = \
	{ \
		.tBit.adc_op_opt = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_op_opt, \
		.tBit.adc_clk_opt = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_opt, \
		.tBit.adc_clk_pol = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_pol, \
		.tBit.adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_prd, \
		.tBit.adc_clk_num = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_num, \
		.tBit.adc_in_pos = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_in_pos, \
		.tBit.adc_stc_dly = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_stc_dly, \
		.tBit.cfgr_tm_adc = PARAMSET_ROIC_CFGR_ADC_CTRL_cfgr_tm_adc, \
		.tBit.adc_buf_pos = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_buf_pos, \
	}, \
	.tParam_CFGR_BUF_OPT = \
	{ \
		.tBit.double_buf_en = PARAMSET_ROIC_CFGR_BUF_OPT_double_buf_en, \
	}, \
	.tParam_CFGR_TG_STUCK = \
	{ \
		.tBit.stuck_rstp = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_rstp, \
		.tBit.stuck_phtcr = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_phtcr, \
		.tBit.stuck_vcr = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_vcr, \
		.tBit.stuck_vcr_odd_en = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_vcr_odd_en, \
		.tBit.stuck_vcr_even_en = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_vcr_even_en, \
		.tBit.stuck_phth0 = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_phth0, \
		.tBit.stuck_phth1 = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_phth1, \
		.tBit.stuck_pht0 = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_pht0, \
		.tBit.stuck_pht1 = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_pht1, \
		.tBit.stuck_rsti = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_rsti, \
		.tBit.stuck_mux_en = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_mux_en, \
		.tBit.stuck_adc_in = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_adc_in, \
	}, \
	.tParam_CFGR_ADC_IN = \
	{ \
		.tBit.adc_in = PARAMSET_ROIC_CFGR_ADC_IN_adc_in, \
	}, \
	.tParam_CFGR_MUX_STUCK_VAL = \
	{ \
		.tBit.mux_stuck_val = PARAMSET_ROIC_CFGR_MUX_STUCK_VAL_mux_stuck_val, \
	}, \
	.tParam_CFGR_MUX_CFG_00 = \
	{ \
		.tBit.mux_00 = PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_00, \
		.tBit.mux_01 = PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_01, \
		.tBit.mux_02 = PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_02, \
		.tBit.mux_03 = PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_03, \
		.tBit.mux_04 = PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_04, \
		.tBit.mux_05 = PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_05, \
		.tBit.mux_06 = PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_06, \
		.tBit.mux_07 = PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_07, \
	}, \
	.tParam_CFGR_MUX_CFG_01 = \
	{ \
		.tBit.mux_08 = PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_08, \
		.tBit.mux_09 = PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_09, \
		.tBit.mux_10 = PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_10, \
		.tBit.mux_11 = PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_11, \
		.tBit.mux_12 = PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_12, \
		.tBit.mux_13 = PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_13, \
		.tBit.mux_14 = PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_14, \
		.tBit.mux_nd = PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_nd, \
	}, \
	.tParam_SYS_DUMMY0 = \
	{ \
		.tBit.sys_dummy0 = PARAMSET_ROIC_SYS_DUMMY0_sys_dummy0, \
	}, \
	.tParam_SYS_DUMMY1 = \
	{ \
		.tBit.sys_dummy1 = PARAMSET_ROIC_SYS_DUMMY1_sys_dummy1, \
	}, \
	.tParam_R0_CR1_MUX1_1 = \
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
		[6] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_6_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_6_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_6_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g3, \
		}, \
		[7] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_7_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_7_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_7_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g3, \
		}, \
		[8] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_8_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_8_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_8_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_8_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_8_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_8_R0_1stMux_Middle_Line_g3, \
		}, \
		[9] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_9_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_9_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_9_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_9_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_9_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_9_R0_1stMux_Middle_Line_g3, \
		}, \
		[10] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_10_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_10_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_10_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_10_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_10_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_10_R0_1stMux_Middle_Line_g3, \
		}, \
		[11] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_11_R0_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_11_R0_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_11_R0_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_11_R0_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_11_R0_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_11_R0_1stMux_Middle_Line_g3, \
		}, \
	}, \
	.tParam_R0_CR1_MUX1_2 = \
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
		[6] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g3, \
		}, \
		[7] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g3, \
		}, \
		[8] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_8_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_8_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_8_R0_1stMux_Bottom_Line_g3, \
		}, \
		[9] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_9_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_9_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_9_R0_1stMux_Bottom_Line_g3, \
		}, \
		[10] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_10_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_10_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_10_R0_1stMux_Bottom_Line_g3, \
		}, \
		[11] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_11_R0_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_11_R0_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_11_R0_1stMux_Bottom_Line_g3, \
		}, \
	}, \
	.tParam_R0_CR1_MUX2 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R0_2ndMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R0_2ndMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R0_2ndMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R0_2ndMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R0_2ndMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R0_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R0_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R0_2ndMux_g3, \
		}, \
	}, \
	.tParam_R0_CR1_MUX3 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R0_3rdMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R0_3rdMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R0_3rdMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R0_3rdMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R0_3rdMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R0_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R0_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R0_3rdMux_g3, \
		}, \
	}, \
	.tParam_R0_CR1_MUX4 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R0_4thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R0_4thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R0_4thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R0_4thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R0_4thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R0_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R0_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R0_4thMux_g3, \
		}, \
	}, \
	.tParam_R0_CR1_MUX5 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R0_5thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R0_5thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R0_5thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R0_5thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R0_5thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R0_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R0_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R0_5thMux_g3, \
		}, \
	}, \
	.tParam_R0_CR1_MUX6 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R0_6thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R0_6thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R0_6thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R0_6thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R0_6thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R0_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R0_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R0_6thMux_g3, \
		}, \
	}, \
	.tParam_R0_CR1_MUX7 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R0_7thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R0_7thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R0_7thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R0_7thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R0_7thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R0_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R0_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R0_7thMux_g3, \
		}, \
	}, \
	.tParam_R0_CR1_MUX8 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R0_8thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R0_8thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R0_8thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R0_8thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R0_8thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R0_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R0_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R0_8thMux_g3, \
		}, \
	}, \
	.tParam_R0_CR1_MUX9 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R0_9thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R0_9thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R0_9thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R0_9thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R0_9thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R0_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R0_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R0_9thMux_g3, \
		}, \
	}, \
	.tParam_R0_CR1_MUX10_1 = \
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
		[6] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_6_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_6_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_6_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g3, \
		}, \
		[7] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_7_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_7_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_7_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g3, \
		}, \
		[8] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_8_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_8_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_8_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_8_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_8_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_8_R0_LastMux_Middle_Line_g3, \
		}, \
		[9] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_9_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_9_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_9_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_9_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_9_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_9_R0_LastMux_Middle_Line_g3, \
		}, \
		[10] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_10_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_10_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_10_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_10_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_10_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_10_R0_LastMux_Middle_Line_g3, \
		}, \
		[11] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_11_R0_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_11_R0_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_11_R0_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_11_R0_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_11_R0_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_11_R0_LastMux_Middle_Line_g3, \
		}, \
	}, \
	.tParam_R0_CR1_MUX10_2 = \
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
		[6] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g3, \
		}, \
		[7] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g3, \
		}, \
		[8] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_8_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_8_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_8_R0_LastMux_Bottom_Line_g3, \
		}, \
		[9] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_9_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_9_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_9_R0_LastMux_Bottom_Line_g3, \
		}, \
		[10] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_10_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_10_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_10_R0_LastMux_Bottom_Line_g3, \
		}, \
		[11] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_11_R0_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_11_R0_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_11_R0_LastMux_Bottom_Line_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX1_1 = \
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
		[6] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_6_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_6_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_6_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g3, \
		}, \
		[7] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_7_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_7_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_7_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g3, \
		}, \
		[8] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_8_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_8_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_8_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_8_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_8_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_8_R1_1stMux_Middle_Line_g3, \
		}, \
		[9] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_9_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_9_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_9_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_9_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_9_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_9_R1_1stMux_Middle_Line_g3, \
		}, \
		[10] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_10_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_10_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_10_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_10_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_10_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_10_R1_1stMux_Middle_Line_g3, \
		}, \
		[11] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_11_R1_1stMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_11_R1_1stMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_11_R1_1stMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_11_R1_1stMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_11_R1_1stMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_11_R1_1stMux_Middle_Line_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX1_2 = \
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
		[6] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g3, \
		}, \
		[7] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g3, \
		}, \
		[8] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_8_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_8_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_8_R1_1stMux_Bottom_Line_g3, \
		}, \
		[9] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_9_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_9_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_9_R1_1stMux_Bottom_Line_g3, \
		}, \
		[10] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_10_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_10_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_10_R1_1stMux_Bottom_Line_g3, \
		}, \
		[11] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_11_R1_1stMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_11_R1_1stMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_11_R1_1stMux_Bottom_Line_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX2 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R1_2ndMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R1_2ndMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R1_2ndMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R1_2ndMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R1_2ndMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R1_2ndMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R1_2ndMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R1_2ndMux_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX3 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R1_3rdMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R1_3rdMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R1_3rdMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R1_3rdMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R1_3rdMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R1_3rdMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R1_3rdMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R1_3rdMux_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX4 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R1_4thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R1_4thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R1_4thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R1_4thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R1_4thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R1_4thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R1_4thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R1_4thMux_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX5 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R1_5thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R1_5thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R1_5thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R1_5thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R1_5thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R1_5thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R1_5thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R1_5thMux_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX6 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R1_6thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R1_6thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R1_6thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R1_6thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R1_6thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R1_6thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R1_6thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R1_6thMux_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX7 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R1_7thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R1_7thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R1_7thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R1_7thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R1_7thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R1_7thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R1_7thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R1_7thMux_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX8 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R1_8thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R1_8thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R1_8thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R1_8thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R1_8thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R1_8thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R1_8thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R1_8thMux_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX9 = \
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
		[6] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_6_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_6_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_6_R1_9thMux_g3, \
		}, \
		[7] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_7_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_7_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_7_R1_9thMux_g3, \
		}, \
		[8] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_8_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_8_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_8_R1_9thMux_g3, \
		}, \
		[9] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_9_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_9_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_9_R1_9thMux_g3, \
		}, \
		[10] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_10_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_10_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_10_R1_9thMux_g3, \
		}, \
		[11] = { \
			.tBit.cr1_rg1 = PARAMSET_ROIC_11_R1_9thMux_g1, \
			.tBit.cr1_rg2 = PARAMSET_ROIC_11_R1_9thMux_g2, \
			.tBit.cr1_rg3 = PARAMSET_ROIC_11_R1_9thMux_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX10_1 = \
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
		[6] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_6_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_6_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_6_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g3, \
		}, \
		[7] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_7_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_7_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_7_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g3, \
		}, \
		[8] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_8_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_8_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_8_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_8_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_8_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_8_R1_LastMux_Middle_Line_g3, \
		}, \
		[9] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_9_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_9_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_9_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_9_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_9_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_9_R1_LastMux_Middle_Line_g3, \
		}, \
		[10] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_10_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_10_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_10_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_10_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_10_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_10_R1_LastMux_Middle_Line_g3, \
		}, \
		[11] = { \
			.tBit.cr1_r1g1 = PARAMSET_ROIC_11_R1_LastMux_Top_Line_g1, \
			.tBit.cr1_r1g2 = PARAMSET_ROIC_11_R1_LastMux_Top_Line_g2, \
			.tBit.cr1_r1g3 = PARAMSET_ROIC_11_R1_LastMux_Top_Line_g3, \
			.tBit.cr1_r2g1 = PARAMSET_ROIC_11_R1_LastMux_Middle_Line_g1, \
			.tBit.cr1_r2g2 = PARAMSET_ROIC_11_R1_LastMux_Middle_Line_g2, \
			.tBit.cr1_r2g3 = PARAMSET_ROIC_11_R1_LastMux_Middle_Line_g3, \
		}, \
	}, \
	.tParam_R1_CR1_MUX10_2 = \
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
		[6] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g3, \
		}, \
		[7] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g3, \
		}, \
		[8] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_8_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_8_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_8_R1_LastMux_Bottom_Line_g3, \
		}, \
		[9] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_9_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_9_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_9_R1_LastMux_Bottom_Line_g3, \
		}, \
		[10] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_10_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_10_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_10_R1_LastMux_Bottom_Line_g3, \
		}, \
		[11] = { \
			.tBit.cr1_r3g1 = PARAMSET_ROIC_11_R1_LastMux_Bottom_Line_g1, \
			.tBit.cr1_r3g2 = PARAMSET_ROIC_11_R1_LastMux_Bottom_Line_g2, \
			.tBit.cr1_r3g3 = PARAMSET_ROIC_11_R1_LastMux_Bottom_Line_g3, \
		}, \
	}, \
	.tParam_R0_CR_M1_LTUNE = \
	{ \
		[0] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[1] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[2] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[3] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[4] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[5] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[6] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[7] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[8] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_8_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_8_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_8_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_8_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_8_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_8_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[9] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_9_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_9_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_9_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_9_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_9_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_9_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[10] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_10_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_10_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_10_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_10_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_10_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_10_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[11] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_11_R0_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_11_R0_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_11_R0_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_11_R0_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_11_R0_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_11_R0_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
	}, \
	.tParam_R1_CR_M1_LTUNE = \
	{ \
		[0] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[1] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[2] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[3] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[4] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[5] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[6] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[7] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[8] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_8_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_8_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_8_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_8_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_8_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_8_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[9] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_9_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_9_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_9_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_9_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_9_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_9_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[10] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_10_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_10_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_10_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_10_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_10_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_10_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
		[11] = { \
			.tBit.cr_m1o_rg1 = PARAMSET_ROIC_11_R1_CR_M1_LTUNE_cr_m1o_rg1, \
			.tBit.cr_m1o_rg2 = PARAMSET_ROIC_11_R1_CR_M1_LTUNE_cr_m1o_rg2, \
			.tBit.cr_m1o_rg3 = PARAMSET_ROIC_11_R1_CR_M1_LTUNE_cr_m1o_rg3, \
			.tBit.cr_m1e_rg1 = PARAMSET_ROIC_11_R1_CR_M1_LTUNE_cr_m1e_rg1, \
			.tBit.cr_m1e_rg2 = PARAMSET_ROIC_11_R1_CR_M1_LTUNE_cr_m1e_rg2, \
			.tBit.cr_m1e_rg3 = PARAMSET_ROIC_11_R1_CR_M1_LTUNE_cr_m1e_rg3, \
		}, \
	}, \
	.tParam_CR_GTUNE = \
	{ \
		.tBit.cr_gtune = PARAMSET_ROIC_CR_GTUNE_cr_gtune, \
	}, \
	.tParam_CFGR_TUNE_LOWER = \
	{ \
		.tBit.lower_mux_num = PARAMSET_ROIC_CFGR_TUNE_LOWER_lower_mux_num, \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_CFGR_TUNE_LOWER_cr_rg2_sel, \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_CFGR_TUNE_LOWER_cr_rg3_sel, \
	}, \
	.tParam_CFGR_TUNE_UPPER = \
	{ \
		.tBit.upper_mux_num = PARAMSET_ROIC_CFGR_TUNE_UPPER_upper_mux_num, \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_CFGR_TUNE_UPPER_cr_rg2_sel, \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_CFGR_TUNE_UPPER_cr_rg3_sel, \
	}, \
	.tParam_CFGR_TUNE_GROUP = \
	{ \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_CFGR_TUNE_GROUP_cr_rg2_sel, \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_CFGR_TUNE_GROUP_cr_rg3_sel, \
		.tBit.cr_m1_g2_sel = PARAMSET_ROIC_CFGR_TUNE_GROUP_cr_m1_g2_sel, \
		.tBit.cr_m1_g3_sel = PARAMSET_ROIC_CFGR_TUNE_GROUP_cr_m1_g3_sel, \
	}, \
	.tParam_CFGR_SENSE_CTRL = \
	{ \
		.tBit.adc_bcon = PARAMSET_ROIC_CFGR_SENSE_CTRL_adc_bc, \
		.tBit.adc_stc_insel = PARAMSET_ROIC_CFGR_SENSE_CTRL_adc_stc_insel, \
		.tBit.int_ref = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_ref, \
		.tBit.sha_ref = PARAMSET_ROIC_CFGR_SENSE_CTRL_sha_ref, \
		.tBit.lv_ssu_bcon = PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcon, \
		.tBit.lv_ssu_bcons = PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcons, \
		.tBit.hv_ssu_bcon = PARAMSET_ROIC_CFGR_SENSE_CTRL_hv_ssu_bcon, \
		.tBit.integ_half = PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half, \
		.tBit.pre_gc = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc, \
		.tBit.int_gc = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc, \
		.tBit.powsel = PARAMSET_ROIC_CFGR_SENSE_CTRL_powsel, \
		.tBit.pre_bs_lp = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_bs_lp, \
		.tBit.int_bs_lp = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_bs_lp, \
		.tBit.sha_bs_lp = PARAMSET_ROIC_CFGR_SENSE_CTRL_sha_bs_lp, \
	}, \
	.tParam_CFGR_SENSE_CTRL_2 = \
	{ \
		.tBit.tm_ssu_pen = PARAMSET_ROIC_CFGR_SENSE_CTRL_2_tm_ssu_pen, \
		.tBit.vpen_en = PARAMSET_ROIC_CFGR_SENSE_CTRL_2_vpen_en, \
		.tBit.vpen_pol = PARAMSET_ROIC_CFGR_SENSE_CTRL_2_vpen_pol, \
		.tBit.tm_alp_mon = PARAMSET_ROIC_CFGR_SENSE_CTRL_2_tm_alp_mon, \
		.tBit.alp_mon = PARAMSET_ROIC_CFGR_SENSE_CTRL_2_alp_mon, \
		.tBit.cfgr_adc_data_dly = PARAMSET_ROIC_CFGR_SENSE_CTRL_2_cfgr_adc_data_dly, \
	}, \
	.tParam_CFGR_SSU_PW_CTRL = \
	{ \
		.tBit.pdb_hvbias = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_hvbias, \
		.tBit.pdb_hvr = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_hvr, \
		.tBit.pdb_lvbias = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_lvbias, \
		.tBit.pdb_lvr = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_lvr, \
		.tBit.bgr_en = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_bgr_en, \
		.tBit.pdb_adc = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_adc, \
		.tBit.stuck_hvbias = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_hvbias, \
		.tBit.stuck_hvr = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_hvr, \
		.tBit.stuck_lvbias = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_lvbias, \
		.tBit.stuck_lvr = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_lvr, \
		.tBit.stuck_bgr = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_bgr, \
		.tBit.stuck_adc = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_adc, \
	}

#endif /* (USED_ROIC_DEF == ROIC_SW97500) */


#endif /* __SW97500_PARAMPRESET_H_ */
