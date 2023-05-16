/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _sw92502_parampreset.h
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

#ifndef __SW92502_PARAMPRESET_H_
#define __SW92502_PARAMPRESET_H_


#if (USED_ROIC_DEF == ROIC_SW92502)
#define SRIC_Conf_Set	\
	.CFGR_DEVICE_ID = \
	{ \
		.tBit.device_id = 0x2502, \
	}, \
	.CFGR_REV_ID = \
	{ \
		.tBit.r0_rev_id = 0, \
		.tBit.r1_rev_id = 0, \
	}, \
	.CFGR_SYS_CFG = \
	{ \
		.tBit.scan_start = 0, \
		.tBit.tg_clk_on = 0, \
		.tBit.buf_clk_on = 0, \
		.tBit.tg_reset = 0, \
		.tBit.sw_reset = 0, \
		.tBit.mcnt_reset = 0, \
	}, \
	.CFGR_PEN_POS1 = \
	{ \
		.tBit.lhb_type = 0, \
		.tBit.local_position1 = 0, \
		.tBit.local_position2 = 0, \
	}, \
	.CFGR_PEN_POS2 = \
	{ \
		.tBit.local_position3 = 0, \
		.tBit.local_position4 = 0, \
	}, \
	.CFGR_SDIC_CFG = \
	{ \
		.tBit.sdic_lcd_off = 0, \
		.tBit.sdic_lfd_float_r0 = 0, \
		.tBit.sdic_lfd_float_r1 = 0, \
		.tBit.sdic_gnd_r0 = 0, \
		.tBit.sdic_gnd_r1 = 0, \
		.tBit.tsync_in_pol = 0, \
		.tBit.pwm_pol = 0, \
		.tBit.cfg_2mux_short = 1, \
		.tBit.half_pwm_en = 0, \
		.tBit.tsync2_en = 0, \
		.tBit.tsync2_in_pol = 0, \
		.tBit.adc_stc_insel = 0, \
	}, \
	.CFGR_ADC_CFG = \
	{ \
		.tBit.adc_op_opt0 = 0, \
		.tBit.adc_op_opt1 = 0, \
		.tBit.adc_clk_opt = 1, \
		.tBit.adc_clk_div_f = 1, \
		.tBit.adc_clk_div_p = 1, \
		.tBit.adc_stc_dly = 0x1F, \
		.tBit.adc_in_pos = 0x2, \
	}, \
	.CFGR_PWR_CFG1 = \
	{ \
		.tBit.pwr_lv_bias = 2, \
		.tBit.pwr_hv_bias = 3, \
		.tBit.pwr_adc = 2, \
		.tBit.pwr_bgr = 1, \
		.tBit.ch_dum_drv_en_0 = 0, \
		.tBit.ch_dum_drv_en_1 = 0, \
		.tBit.lvr_pwr_opt = 2, \
		.tBit.hvr_pwr_opt = 3, \
	}, \
	.CFGR_PWR_CFG2 = \
	{ \
		.tBit.r0_pwr_ch_lv = 0x7F, \
		.tBit.r0_pwr_ch_hv = 0x1FF, \
	}, \
	.CFGR_PWR_CFG3 = \
	{ \
		.tBit.r1_pwr_ch_lv = 0x7F, \
		.tBit.r1_pwr_ch_hv = 0x1FF, \
	}, \
	.CFGR_SPI_CFG = \
	{ \
		.tBit.chip0_len = 56, \
		.tBit.double_buf_en = 1, \
		.tBit.pad_ds_miso = 0, \
		.tBit.irq_en = 1, \
		.tBit.sel_raw_bufd = 0, \
	}, \
	.CFGR_PWM_PRD1 = \
	{ \
		.tBit.pwm_prd1 = 0x3A, \
		.tBit.pwm_prd2 = 0x3A, \
	}, \
	.CFGR_PWM_PRD2 = \
	{ \
		.tBit.pwm_prd3 = 0x3A, \
	}, \
	.CFGR_SMPL_CTL1 = \
	{ \
		.tBit.smop_prd1 = 0x7, \
		.tBit.crrpt_num_1 = 0, \
		.tBit.crrpt_num_2 = 0, \
	}, \
	.CFGR_RSTP_NUM1 = \
	{ \
		.tBit.rstp_num1 = 0x8, \
		.tBit.rstp_num2 = 0x3, \
	}, \
	.CFGR_PHTCR_NUM1 = \
	{ \
		.tBit.phtcr_num1 = 0x27, \
		.tBit.phtcr_num2 = 0xF, \
	}, \
	.CFGR_VCR_NUM1 = \
	{ \
		.tBit.vcr_num1 = 0x20, \
		.tBit.vcr_inv = 0, \
		.tBit.vcr_en_off = 0, \
	}, \
	.CFGR_VCR_EN_NUM1 = \
	{ \
		.tBit.vcr_en_num1 = 0x2b, \
		.tBit.vcr_en_num2 = 0x0C, \
	}, \
	.CFGR_PHTH0_NUM1 = \
	{ \
		.tBit.phth0_num1 = 0x0A, \
		.tBit.phth0_num2 = 0x01, \
	}, \
	.CFGR_PHTH1_NUM1 = \
	{ \
		.tBit.phth1_num1 = 0x09, \
		.tBit.phth1_num2 = 0x1D, \
	}, \
	.CFGR_RSTI_NUM1 = \
	{ \
		.tBit.rsti_num1 = 0x08, \
		.tBit.rsti_num2 = 0x03, \
	}, \
	.CFGR_PHT_ETIME1 = \
	{ \
		.tBit.rsti_num3 = 0x03, \
		.tBit.pht_etime = 0x0A, \
	}, \
	.CFGR_PHT_CTL1 = \
	{ \
		.tBit.pht_prd = 0x06, \
		.tBit.pht_opt_smp = 0, \
		.tBit.pht_opt_inv = 0x1, \
	}, \
	.CFGR_PHT_NUM1 = \
	{ \
		.tBit.pht_num1 = 0x0F, \
		.tBit.pht_num2 = 0x0A, \
	}, \
	.CFGR_SMPL_CTL2 = \
	{ \
		.tBit.smop_prd1 = 0x7, \
		.tBit.crrpt_num_1 = 1, \
		.tBit.crrpt_num_2 = 1, \
	}, \
	.CFGR_RSTP_NUM2 = \
	{ \
		.tBit.rstp_num1 = 0x8, \
		.tBit.rstp_num2 = 0x3, \
	}, \
	.CFGR_PHTCR_NUM2 = \
	{ \
		.tBit.phtcr_num1 = 0x27, \
		.tBit.phtcr_num2 = 0xF, \
	}, \
	.CFGR_VCR_NUM2 = \
	{ \
		.tBit.vcr_num1 = 0x23, \
		.tBit.vcr_inv_p = 0, \
		.tBit.vcr_inv_d = 0, \
		.tBit.vcr_en_off_p = 0, \
		.tBit.vcr_en_off_d = 0, \
	}, \
	.CFGR_VCR_EN_NUM2 = \
	{ \
		.tBit.vcr_en_num1 = 0x2B, \
		.tBit.vcr_en_num2 = 0x0C, \
	}, \
	.CFGR_PHTH0_NUM2 = \
	{ \
		.tBit.phth0_num1 = 0xA, \
		.tBit.phth0_num2 = 0x1, \
	}, \
	.CFGR_PHTH1_NUM2 = \
	{ \
		.tBit.phth1_num1 = 0x9, \
		.tBit.phth1_num2 = 0x19, \
	}, \
	.CFGR_RSTI_NUM2 = \
	{ \
		.tBit.rsti_num1 = 0x8, \
		.tBit.rsti_num2 = 0x3, \
	}, \
	.CFGR_PHT_ETIME2 = \
	{ \
		.tBit.rsti_num3 = 0x3, \
		.tBit.pht_etime = 0xA, \
	}, \
	.CFGR_PHT_CTL2 = \
	{ \
		.tBit.pht_prd = 0x6, \
		.tBit.pht_opt_smp = 0, \
		.tBit.pht_opt_inv = 1, \
	}, \
	.CFGR_PHT_NUM2 = \
	{ \
		.tBit.pht_num1 = 0xF, \
		.tBit.pht_num2 = 0xA, \
	}, \
	.CFGR_SMPL_CTL3 = \
	{ \
		.tBit.smop_prd1 = 0x7, \
		.tBit.crrpt_num_1 = 0, \
		.tBit.crrpt_num_2 = 0, \
	}, \
	.CFGR_RSTP_NUM3 = \
	{ \
		.tBit.rstp_num1 = 0x8, \
		.tBit.rstp_num2 = 0x3, \
	}, \
	.CFGR_PHTCR_NUM3 = \
	{ \
		.tBit.phtcr_num1 = 0x27, \
		.tBit.phtcr_num2 = 0xF, \
	}, \
	.CFGR_VCR_NUM3 = \
	{ \
		.tBit.vcr_num1 = 0x23, \
		.tBit.vcr_inv = 0, \
		.tBit.vcr_en_off = 0, \
	}, \
	.CFGR_VCR_EN_NUM3 = \
	{ \
		.tBit.vcr_en_num1 = 0x2B, \
		.tBit.vcr_en_num2 = 0xC, \
	}, \
	.CFGR_PHTH0_NUM3 = \
	{ \
		.tBit.phth0_num1 = 0xA, \
		.tBit.phth0_num2 = 0x1, \
	}, \
	.CFGR_PHTH1_NUM3 = \
	{ \
		.tBit.phth1_num1 = 0x9, \
		.tBit.phth1_num2 = 0x19, \
	}, \
	.CFGR_RSTI_NUM3 = \
	{ \
		.tBit.rsti_num1 = 0x8, \
		.tBit.rsti_num2 = 0x3, \
	}, \
	.CFGR_PHT_ETIME3 = \
	{ \
		.tBit.rsti_num3 = 0x3, \
		.tBit.pht_etime = 0xA, \
	}, \
	.CFGR_PHT_CTL3 = \
	{ \
		.tBit.pht_prd = 0x6, \
		.tBit.pht_opt_smp = 0, \
		.tBit.pht_opt_inv = 1, \
	}, \
	.CFGR_PHT_NUM3 = \
	{ \
		.tBit.pht_num1 = 0xF, \
		.tBit.pht_num2 = 0xA, \
	}, \
	.CFGR_HALF_COPY = \
	{ \
		.tBit.half_copy_dat = 0, \
		.tBit.half_copy_pos = 0, \
		.tBit.partial_pos_opt1 = 0, \
		.tBit.partial_pos1 = 0, \
		.tBit.partial_pos_opt2 = 0, \
		.tBit.partial_pos2 = 0, \
	}, \
	.CFGR_TEST_OPT1 = \
	{ \
		.tBit.stuck_rstp = 0, \
		.tBit.stuck_phtcr = 0, \
		.tBit.stuck_vcr = 0, \
		.tBit.stuck_rsti = 0, \
		.tBit.stuck_phth0 = 0, \
		.tBit.stuck_phth1 = 0, \
		.tBit.stuck_pht0 = 0, \
		.tBit.stuck_pht1 = 0, \
	}, \
	.CFGR_TEST_OPT2 = \
	{ \
		.tBit.stuck_vcren_odd = 0x3, \
		.tBit.stuck_vcren_even = 0x3, \
		.tBit.pow_sel = 0, \
		.tBit.display_vcomr = 0, \
		.tBit.touch_vcomr = 0, \
		.tBit.uplink_vcomr = 0, \
		.tBit.stuck_enable = 0, \
		.tBit.stuck_level = 0, \
		.tBit.tsync_opt = 0, \
		.tBit.muxs_ctl_en = 0, \
		.tBit.muxf_ctl_en = 0, \
	}, \
	.CFGR_TEST_OPT3 = \
	{ \
		.tBit.muxs_ctl_bit = 0xFFF, \
		.tBit.mux_int_sel = 0xF, \
	}, \
	.CFGR_TEST_OPT4 = \
	{ \
		.tBit.muxf_ctl_bit = 0, \
	}, \
	.CFGR_CMUX_REMAP1 = \
	{ \
		.tBit.mx_order_01 = 0x0, \
		.tBit.mx_order_02 = 0x1, \
		.tBit.mx_order_03 = 0x2, \
		.tBit.mx_order_04 = 0x3, \
	}, \
	.CFGR_CMUX_REMAP2 = \
	{ \
		.tBit.mx_order_05 = 0x4, \
		.tBit.mx_order_06 = 0x5, \
		.tBit.mx_order_07 = 0x6, \
		.tBit.mx_order_08 = 0x7, \
	}, \
	.CFGR_CMUX_REMAP3 = \
	{ \
		.tBit.mx_order_09 = 0x8, \
		.tBit.mx_order_10 = 0x9, \
		.tBit.mx_order_11 = 0xA, \
		.tBit.mx_order_12 = 0xB, \
	}, \
	.CFGR_MD1_MUX_SEL1 = BIT(0), \
	.CFGR_MD1_MUX_SEL2 = BIT(1), \
	.CFGR_MD1_MUX_SEL3 = BIT(2), \
	.CFGR_MD1_MUX_SEL4 = BIT(3), \
	.CFGR_MD1_MUX_SEL5 = BIT(4), \
	.CFGR_MD1_MUX_SEL6 = BIT(5), \
	.CFGR_MD1_MUX_SEL7 = BIT(6), \
	.CFGR_MD1_MUX_SEL8 = BIT(7), \
	.CFGR_MD1_MUX_SEL9 = BIT(8), \
	.CFGR_MD1_MUX_SEL10 = BIT(9), \
	.CFGR_MD1_MUX_SEL11 = BIT(10), \
	.CFGR_MD1_MUX_SEL12 = BIT(11), \
	.CFGR_MD2_MUX_SEL1 = 0x0FFF, \
	.CFGR_MD2_MUX_SEL2 = BIT(1), \
	.CFGR_MD2_MUX_SEL3 = BIT(2), \
	.CFGR_MD2_MUX_SEL4 = BIT(3), \
	.CFGR_MD2_MUX_SEL5 = BIT(4), \
	.CFGR_MD2_MUX_SEL6 = BIT(5), \
	.CFGR_MD2_MUX_SEL7 = BIT(6), \
	.CFGR_MD2_MUX_SEL8 = BIT(7), \
	.CFGR_MD2_MUX_SEL9 = BIT(8), \
	.CFGR_MD2_MUX_SEL10 = BIT(9), \
	.CFGR_MD2_MUX_SEL11 = BIT(10), \
	.CFGR_MD2_MUX_SEL12 = BIT(11), \
	.CFGR_RSV_0 = \
	{ \
		.tBit.RESERVED0 = 0, \
	}, \
	.CFGR_LHB_CFG1 = \
	{ \
		.tBit.md1_lhb_mux = 0x2, \
		.tBit.md2_lhb_mux = 0x1, \
		.tBit.md3_lhb_mux = 0x2, \
	}, \
	.CFGR_LHB_CFG2 = \
	{ \
		.tBit.md5_lhb_mux = 0x2, \
		.tBit.md6_lhb_mux = 0x2, \
		.tBit.end_mux_num = 0xC, \
	}, \
	.CFGR_MD1_MUX_CFG = \
	{ \
		.tBit.mux_cfg_en = 0x0, \
		.tBit.mux_cfg_bit1 = 0x0, \
	}, \
	.CFGR_MD1_PWM_CFG = \
	{ \
		.tBit.pre_pwm = 3, \
		.tBit.set_pwm_en = 1, \
		.tBit.act_pwm = 11, \
	}, \
	.CFGR_MD1_BCON_CFG = \
	{ \
		.tBit.bcon_pre = 4, \
		.tBit.pre_bs_lp = 1, \
		.tBit.bcon_int = 0, \
		.tBit.int_bs_lp = 0, \
		.tBit.bcon_sha = 1, \
		.tBit.sha_bs_lp = 0, \
		.tBit.bcon_adc = 0, \
	}, \
	.CFGR_MD1_AFE_CFG = \
	{ \
		.tBit.pre_gc = 0x3, \
		.tBit.int_gc = 0x2, \
		.tBit.int_half = 0x1, \
		.tBit.cr_g_tune = 0x1, \
		.tBit.int_ref = 0x2, \
		.tBit.sha_ref = 0x2, \
	}, \
	.CFGR_MD2_MUX_CFG = \
	{ \
		.tBit.mux_cfg_en = 0x0, \
		.tBit.mux_cfg_bit1 = 0x0, \
	}, \
	.CFGR_MD2_PWM_CFG = \
	{ \
		.tBit.pre_pwm = 3, \
		.tBit.set_pwm_en = 1, \
		.tBit.act_pwm = 6, \
	}, \
	.CFGR_MD2_BCON_CFG = \
	{ \
		.tBit.bcon_pre = 0x0, \
		.tBit.pre_bs_lp = 0x0, \
		.tBit.bcon_int = 0x0, \
		.tBit.int_bs_lp = 0x0, \
		.tBit.bcon_sha = 0x0, \
		.tBit.sha_bs_lp = 0x0, \
		.tBit.bcon_adc = 0x0, \
	}, \
	.CFGR_MD2_AFE_CFG = \
	{ \
		.tBit.pre_gc = 0x3, \
		.tBit.int_gc = 0x3, \
		.tBit.int_half = 0x0, \
		.tBit.cr_g_tune = 2, \
		.tBit.int_ref = 0x0, \
		.tBit.sha_ref = 0x0, \
	}, \
	.CFGR_MD3_MUX_CFG1 = \
	{ \
		.tBit.mux_cfg_bit1 = 0x0, \
	}, \
	.CFGR_MD3_MUX_CFG2 = \
	{ \
		.tBit.mux_cfg_bit2 = 0x0, \
	}, \
	.CFGR_MD3_MUX_CFG3 = \
	{ \
		.tBit.mux_cfg_bit3 = 0x0, \
	}, \
	.CFGR_MD3_MUX_CFG4 = \
	{ \
		.tBit.mux_cfg_bit4 = 0x0, \
	}, \
	.CFGR_MD3_PWM_CFG = \
	{ \
		.tBit.pre_pwm = 0x2, \
		.tBit.set_pwm_en = 0x1, \
		.tBit.act_pwm = 0x6, \
	}, \
	.CFGR_MD3_BCON_CFG = \
	{ \
		.tBit.bcon_pre = 0x0, \
		.tBit.pre_bs_lp = 0x0, \
		.tBit.bcon_int = 0x0, \
		.tBit.int_bs_lp = 0x0, \
		.tBit.bcon_sha = 0x0, \
		.tBit.sha_bs_lp = 0x0, \
		.tBit.bcon_adc = 0x0, \
	}, \
	.CFGR_MD3_AFE_CFG = \
	{ \
		.tBit.pre_gc = 0x3, \
		.tBit.int_gc = 0x3, \
		.tBit.int_half = 0x0, \
		.tBit.cr_g_tune = 0x0, \
		.tBit.int_ref = 0x0, \
		.tBit.sha_ref = 0x0, \
	}, \
	.CFGR_MD5_PWM_CFG = \
	{ \
		.tBit.pre_pwm = 0x2, \
		.tBit.set_pwm_en = 0x1, \
		.tBit.act_pwm = 0x6, \
	}, \
	.CFGR_MD5_BCON_CFG = \
	{ \
		.tBit.bcon_pre = 0x0, \
		.tBit.pre_bs_lp = 0x0, \
		.tBit.bcon_int = 0x0, \
		.tBit.int_bs_lp = 0x0, \
		.tBit.bcon_sha = 0x0, \
		.tBit.sha_bs_lp = 0x0, \
		.tBit.bcon_adc = 0x0, \
	}, \
	.CFGR_MD5_AFE_CFG = \
	{ \
		.tBit.pre_gc = 0x3, \
		.tBit.int_gc = 0x3, \
		.tBit.int_half = 0x0, \
		.tBit.cr_g_tune = 0x0, \
		.tBit.int_ref = 0x0, \
		.tBit.sha_ref = 0x0, \
	}, \
	.CFGR_MD6_PWM_CFG = \
	{ \
		.tBit.pre_pwm = 0x2, \
		.tBit.set_pwm_en = 0x1, \
		.tBit.act_pwm = 0x6, \
	}, \
	.CFGR_CR_SEL = \
	{ \
		.tBit.cr_group_r0 = 0, \
		.tBit.cr_group_r1 = 1, \
		.tBit.r0_cr_sel_c0 = 0, \
		.tBit.r0_cr_sel_c1 = 1, \
		.tBit.r0_cr_sel_c2 = 2, \
		.tBit.r1_cr_sel_c0 = 0, \
		.tBit.r1_cr_sel_c1 = 1, \
		.tBit.r1_cr_sel_c2 = 2, \
	}, \
	.CFGR_R0_MD1_CRT_MX1 = \
	{ \
		.tBit.md1_crt_mx1_g1 = 3, \
		.tBit.md1_crt_mx1_g2 = 3, \
		.tBit.md1_crt_mx1_g3 = 3, \
	}, \
	.CFGR_R0_MD1_CR_MX1 = \
	{ \
		.tBit.md1_cr_mx1_g1 = 0, \
		.tBit.md1_cr_mx1_g2 = 1, \
		.tBit.md1_cr_mx1_g3 = 0, \
	}, \
	.CFGR_R0_MD1_CR_MX2 = \
	{ \
		.tBit.md1_cr_mx2_g1 = 0, \
		.tBit.md1_cr_mx2_g2 = 1, \
		.tBit.md1_cr_mx2_g3 = 0, \
	}, \
	.CFGR_R0_MD1_CR_MX3 = \
	{ \
		.tBit.md1_cr_mx3_g1 = 1, \
		.tBit.md1_cr_mx3_g2 = 2, \
		.tBit.md1_cr_mx3_g3 = 1, \
	}, \
	.CFGR_R0_MD1_CR_MX4 = \
	{ \
		.tBit.md1_cr_mx4_g1 = 1, \
		.tBit.md1_cr_mx4_g2 = 2, \
		.tBit.md1_cr_mx4_g3 = 1, \
	}, \
	.CFGR_R0_MD1_CR_MX5 = \
	{ \
		.tBit.md1_cr_mx5_g1 = 1, \
		.tBit.md1_cr_mx5_g2 = 2, \
		.tBit.md1_cr_mx5_g3 = 1, \
	}, \
	.CFGR_R0_MD1_CR_MX6 = \
	{ \
		.tBit.md1_cr_mx6_g1 = 1, \
		.tBit.md1_cr_mx6_g2 = 2, \
		.tBit.md1_cr_mx6_g3 = 1, \
	}, \
	.CFGR_R0_MD1_CR_MX7 = \
	{ \
		.tBit.md1_cr_mx7_g1 = 1, \
		.tBit.md1_cr_mx7_g2 = 2, \
		.tBit.md1_cr_mx7_g3 = 1, \
	}, \
	.CFGR_R0_MD1_CR_MX8 = \
	{ \
		.tBit.md1_cr_mx8_g1 = 2, \
		.tBit.md1_cr_mx8_g2 = 3, \
		.tBit.md1_cr_mx8_g3 = 2, \
	}, \
	.CFGR_R0_MD1_CR_MX9 = \
	{ \
		.tBit.md1_cr_mx9_g1 = 2, \
		.tBit.md1_cr_mx9_g2 = 3, \
		.tBit.md1_cr_mx9_g3 = 2, \
	}, \
	.CFGR_R0_MD1_CR_MX10 = \
	{ \
		.tBit.md1_cr_mx10_g1 = 3, \
		.tBit.md1_cr_mx10_g2 = 3, \
		.tBit.md1_cr_mx10_g3 = 3, \
	}, \
	.CFGR_R0_MD1_CR_MX11 = \
	{ \
		.tBit.md1_cr_mx11_g1 = 3, \
		.tBit.md1_cr_mx11_g2 = 3, \
		.tBit.md1_cr_mx11_g3 = 3, \
	}, \
	.CFGR_R0_MD1_CR_MX12 = \
	{ \
		.tBit.md1_cr_mx12_g1 = 3, \
		.tBit.md1_cr_mx12_g2 = 3, \
		.tBit.md1_cr_mx12_g3 = 3, \
	}, \
	.CFGR_R0_MD1_CRB_MX12 = \
	{ \
		.tBit.md1_crb_mx12_g1 = 3, \
		.tBit.md1_crb_mx12_g2 = 3, \
		.tBit.md1_crb_mx12_g3 = 3, \
	}, \
	.CFGR_R1_MD1_CRT_MX1 = \
	{ \
		.tBit.md1_crt_mx1_g1 = 3, \
		.tBit.md1_crt_mx1_g2 = 3, \
		.tBit.md1_crt_mx1_g3 = 3, \
	}, \
	.CFGR_R1_MD1_CR_MX1 = \
	{ \
		.tBit.md1_cr_mx1_g1 = 0, \
		.tBit.md1_cr_mx1_g2 = 1, \
		.tBit.md1_cr_mx1_g3 = 0, \
	}, \
	.CFGR_R1_MD1_CR_MX2 = \
	{ \
		.tBit.md1_cr_mx2_g1 = 0, \
		.tBit.md1_cr_mx2_g2 = 1, \
		.tBit.md1_cr_mx2_g3 = 0, \
	}, \
	.CFGR_R1_MD1_CR_MX3 = \
	{ \
		.tBit.md1_cr_mx3_g1 = 1, \
		.tBit.md1_cr_mx3_g2 = 2, \
		.tBit.md1_cr_mx3_g3 = 1, \
	}, \
	.CFGR_R1_MD1_CR_MX4 = \
	{ \
		.tBit.md1_cr_mx4_g1 = 1, \
		.tBit.md1_cr_mx4_g2 = 2, \
		.tBit.md1_cr_mx4_g3 = 1, \
	}, \
	.CFGR_R1_MD1_CR_MX5 = \
	{ \
		.tBit.md1_cr_mx5_g1 = 1, \
		.tBit.md1_cr_mx5_g2 = 2, \
		.tBit.md1_cr_mx5_g3 = 1, \
	}, \
	.CFGR_R1_MD1_CR_MX6 = \
	{ \
		.tBit.md1_cr_mx6_g1 = 1, \
		.tBit.md1_cr_mx6_g2 = 2, \
		.tBit.md1_cr_mx6_g3 = 1, \
	}, \
	.CFGR_R1_MD1_CR_MX7 = \
	{ \
		.tBit.md1_cr_mx7_g1 = 1, \
		.tBit.md1_cr_mx7_g2 = 2, \
		.tBit.md1_cr_mx7_g3 = 1, \
	}, \
	.CFGR_R1_MD1_CR_MX8 = \
	{ \
		.tBit.md1_cr_mx8_g1 = 2, \
		.tBit.md1_cr_mx8_g2 = 3, \
		.tBit.md1_cr_mx8_g3 = 2, \
	}, \
	.CFGR_R1_MD1_CR_MX9 = \
	{ \
		.tBit.md1_cr_mx9_g1 = 2, \
		.tBit.md1_cr_mx9_g2 = 3, \
		.tBit.md1_cr_mx9_g3 = 2, \
	}, \
	.CFGR_R1_MD1_CR_MX10 = \
	{ \
		.tBit.md1_cr_mx10_g1 = 3, \
		.tBit.md1_cr_mx10_g2 = 3, \
		.tBit.md1_cr_mx10_g3 = 3, \
	}, \
	.CFGR_R1_MD1_CR_MX11 = \
	{ \
		.tBit.md1_cr_mx11_g1 = 3, \
		.tBit.md1_cr_mx11_g2 = 3, \
		.tBit.md1_cr_mx11_g3 = 3, \
	}, \
	.CFGR_R1_MD1_CR_MX12 = \
	{ \
		.tBit.md1_cr_mx12_g1 = 3, \
		.tBit.md1_cr_mx12_g2 = 3, \
		.tBit.md1_cr_mx12_g3 = 3, \
	}, \
	.CFGR_R1_MD1_CRB_MX12 = \
	{ \
		.tBit.md1_crb_mx12_g1 = 0x4, \
		.tBit.md1_crb_mx12_g2 = 0x4, \
		.tBit.md1_crb_mx12_g3 = 0x4, \
	}, \
	.CFGR_R0_MD2_CRT_MX1 = \
	{ \
		.tBit.md2_crt_mx1_g1 = 0x1F, \
		.tBit.md2_crt_mx1_g2 = 0x1F, \
		.tBit.md2_crt_mx1_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX1 = \
	{ \
		.tBit.md2_cr_mx1_g1 = 0x1F, \
		.tBit.md2_cr_mx1_g2 = 0x1F, \
		.tBit.md2_cr_mx1_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX2 = \
	{ \
		.tBit.md2_cr_mx2_g1 = 0x1F, \
		.tBit.md2_cr_mx2_g2 = 0x1F, \
		.tBit.md2_cr_mx2_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX3 = \
	{ \
		.tBit.md2_cr_mx3_g1 = 0x1F, \
		.tBit.md2_cr_mx3_g2 = 0x1F, \
		.tBit.md2_cr_mx3_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX4 = \
	{ \
		.tBit.md2_cr_mx4_g1 = 0x1F, \
		.tBit.md2_cr_mx4_g2 = 0x1F, \
		.tBit.md2_cr_mx4_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX5 = \
	{ \
		.tBit.md2_cr_mx5_g1 = 0x1F, \
		.tBit.md2_cr_mx5_g2 = 0x1F, \
		.tBit.md2_cr_mx5_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX6 = \
	{ \
		.tBit.md2_cr_mx6_g1 = 0x1F, \
		.tBit.md2_cr_mx6_g2 = 0x1F, \
		.tBit.md2_cr_mx6_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX7 = \
	{ \
		.tBit.md2_cr_mx7_g1 = 0x1F, \
		.tBit.md2_cr_mx7_g2 = 0x1F, \
		.tBit.md2_cr_mx7_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX8 = \
	{ \
		.tBit.md2_cr_mx8_g1 = 0x1F, \
		.tBit.md2_cr_mx8_g2 = 0x1F, \
		.tBit.md2_cr_mx8_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX9 = \
	{ \
		.tBit.md2_cr_mx9_g1 = 0x1F, \
		.tBit.md2_cr_mx9_g2 = 0x1F, \
		.tBit.md2_cr_mx9_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX10 = \
	{ \
		.tBit.md2_cr_mx10_g1 = 0x1F, \
		.tBit.md2_cr_mx10_g2 = 0x1F, \
		.tBit.md2_cr_mx10_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX11 = \
	{ \
		.tBit.md2_cr_mx11_g1 = 0x1F, \
		.tBit.md2_cr_mx11_g2 = 0x1F, \
		.tBit.md2_cr_mx11_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CR_MX12 = \
	{ \
		.tBit.md2_cr_mx12_g1 = 0x1F, \
		.tBit.md2_cr_mx12_g2 = 0x1F, \
		.tBit.md2_cr_mx12_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD2_CRB_MX12 = \
	{ \
		.tBit.md2_crb_mx12_g1 = 0x1F, \
		.tBit.md2_crb_mx12_g2 = 0x1F, \
		.tBit.md2_crb_mx12_g3 = 0x0, \
	}, \
	.CFGR_R1_MD2_CRT_MX1 = \
	{ \
		.tBit.md2_crt_mx1_g1 = 0x1F, \
		.tBit.md2_crt_mx1_g2 = 0x1F, \
		.tBit.md2_crt_mx1_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX1 = \
	{ \
		.tBit.md2_cr_mx1_g1 = 0x1F, \
		.tBit.md2_cr_mx1_g2 = 0x1F, \
		.tBit.md2_cr_mx1_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX2 = \
	{ \
		.tBit.md2_cr_mx2_g1 = 0x1F, \
		.tBit.md2_cr_mx2_g2 = 0x1F, \
		.tBit.md2_cr_mx2_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX3 = \
	{ \
		.tBit.md2_cr_mx3_g1 = 0x1F, \
		.tBit.md2_cr_mx3_g2 = 0x1F, \
		.tBit.md2_cr_mx3_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX4 = \
	{ \
		.tBit.md2_cr_mx4_g1 = 0x1F, \
		.tBit.md2_cr_mx4_g2 = 0x1F, \
		.tBit.md2_cr_mx4_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX5 = \
	{ \
		.tBit.md2_cr_mx5_g1 = 0x1F, \
		.tBit.md2_cr_mx5_g2 = 0x1F, \
		.tBit.md2_cr_mx5_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX6 = \
	{ \
		.tBit.md2_cr_mx6_g1 = 0x1F, \
		.tBit.md2_cr_mx6_g2 = 0x1F, \
		.tBit.md2_cr_mx6_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX7 = \
	{ \
		.tBit.md2_cr_mx7_g1 = 0x1F, \
		.tBit.md2_cr_mx7_g2 = 0x1F, \
		.tBit.md2_cr_mx7_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX8 = \
	{ \
		.tBit.md2_cr_mx8_g1 = 0x1F, \
		.tBit.md2_cr_mx8_g2 = 0x1F, \
		.tBit.md2_cr_mx8_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX9 = \
	{ \
		.tBit.md2_cr_mx9_g1 = 0x1F, \
		.tBit.md2_cr_mx9_g2 = 0x1F, \
		.tBit.md2_cr_mx9_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX10 = \
	{ \
		.tBit.md2_cr_mx10_g1 = 0x1F, \
		.tBit.md2_cr_mx10_g2 = 0x1F, \
		.tBit.md2_cr_mx10_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX11 = \
	{ \
		.tBit.md2_cr_mx11_g1 = 0x1F, \
		.tBit.md2_cr_mx11_g2 = 0x1F, \
		.tBit.md2_cr_mx11_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CR_MX12 = \
	{ \
		.tBit.md2_cr_mx12_g1 = 0x1F, \
		.tBit.md2_cr_mx12_g2 = 0x1F, \
		.tBit.md2_cr_mx12_g3 = 0x1F, \
	}, \
	.CFGR_R1_MD2_CRB_MX12 = \
	{ \
		.tBit.md2_crb_mx12_g1 = 0x1F, \
		.tBit.md2_crb_mx12_g2 = 0x1F, \
		.tBit.md2_crb_mx12_g3 = 0x1F, \
	}, \
	.CFGR_R0_MD3_CRT_MX1 = \
	{ \
		.tBit.md3_crt_mx1_g1 = 0x0, \
		.tBit.md3_crt_mx1_g2 = 0x0, \
		.tBit.md3_crt_mx1_g3 = 0x0, \
	}, \
	.CFGR_R0_MD3_CR_MX1 = \
	{ \
		.tBit.md3_cr_mx1_g1 = 0x0, \
		.tBit.md3_cr_mx1_g2 = 0x0, \
		.tBit.md3_cr_mx1_g3 = 0x0, \
	}, \
	.CFGR_R0_MD3_CR_MX2 = \
	{ \
		.tBit.md3_cr_mx2_g1 = 0x0, \
		.tBit.md3_cr_mx2_g2 = 0x0, \
		.tBit.md3_cr_mx2_g3 = 0x0, \
	}, \
	.CFGR_R0_MD3_CR_MX3 = \
	{ \
		.tBit.md3_cr_mx3_g1 = 0x0, \
		.tBit.md3_cr_mx3_g2 = 0x0, \
		.tBit.md3_cr_mx3_g3 = 0x0, \
	}, \
	.CFGR_R0_MD3_CR_MX4 = \
	{ \
		.tBit.md3_cr_mx4_g1 = 0x0, \
		.tBit.md3_cr_mx4_g2 = 0x0, \
		.tBit.md3_cr_mx4_g3 = 0x0, \
	}, \
	.CFGR_R1_MD3_CRT_MX1 = \
	{ \
		.tBit.md3_crt_mx1_g1 = 0x0, \
		.tBit.md3_crt_mx1_g2 = 0x0, \
		.tBit.md3_crt_mx1_g3 = 0x0, \
	}, \
	.CFGR_R1_MD3_CR_MX1 = \
	{ \
		.tBit.md3_cr_mx1_g1 = 0x0, \
		.tBit.md3_cr_mx1_g2 = 0x0, \
		.tBit.md3_cr_mx1_g3 = 0x0, \
	}, \
	.CFGR_R1_MD3_CR_MX2 = \
	{ \
		.tBit.md3_cr_mx2_g1 = 0x0, \
		.tBit.md3_cr_mx2_g2 = 0x0, \
		.tBit.md3_cr_mx2_g3 = 0x0, \
	}, \
	.CFGR_R1_MD3_CR_MX3 = \
	{ \
		.tBit.md3_cr_mx3_g1 = 0x0, \
		.tBit.md3_cr_mx3_g2 = 0x0, \
		.tBit.md3_cr_mx3_g3 = 0x0, \
	}, \
	.CFGR_R1_MD3_CR_MX4 = \
	{ \
		.tBit.md3_cr_mx4_g1 = 0x0, \
		.tBit.md3_cr_mx4_g2 = 0x0, \
		.tBit.md3_cr_mx4_g3 = 0x0, \
	}, \
	.CFGR_R0_MD5_CRT_MX1 = \
	{ \
		.tBit.md5_crt_mx1_g1 = 0x0, \
		.tBit.md5_crt_mx1_g2 = 0x0, \
		.tBit.md5_crt_mx1_g3 = 0x0, \
	}, \
	.CFGR_R0_MD5_CR_MX1 = \
	{ \
		.tBit.md5_cr_mx1_g1 = 0x0, \
		.tBit.md5_cr_mx1_g2 = 0x0, \
		.tBit.md5_cr_mx1_g3 = 0x0, \
	}, \
	.CFGR_R0_MD5_CR_MX2 = \
	{ \
		.tBit.md5_cr_mx2_g1 = 0x0, \
		.tBit.md5_cr_mx2_g2 = 0x0, \
		.tBit.md5_cr_mx2_g3 = 0x0, \
	}, \
	.CFGR_R0_MD5_CR_MX3 = \
	{ \
		.tBit.md5_cr_mx3_g1 = 0x0, \
		.tBit.md5_cr_mx3_g2 = 0x0, \
		.tBit.md5_cr_mx3_g3 = 0x0, \
	}, \
	.CFGR_R0_MD5_CR_MX4 = \
	{ \
		.tBit.md5_cr_mx4_g1 = 0x0, \
		.tBit.md5_cr_mx4_g2 = 0x0, \
		.tBit.md5_cr_mx4_g3 = 0x0, \
	}, \
	.CFGR_R0_MD5_CR_MX5 = \
	{ \
		.tBit.md5_cr_mx5_g1 = 0x0, \
		.tBit.md5_cr_mx5_g2 = 0x0, \
		.tBit.md5_cr_mx5_g3 = 0x0, \
	}, \
	.CFGR_R0_MD5_CR_MX9 = \
	{ \
		.tBit.md5_cr_mx9_g1 = 0x0, \
		.tBit.md5_cr_mx9_g2 = 0x0, \
		.tBit.md5_cr_mx9_g3 = 0x0, \
	}, \
	.CFGR_R0_MD5_CR_MX10 = \
	{ \
		.tBit.md5_cr_mx10_g1 = 0x0, \
		.tBit.md5_cr_mx10_g2 = 0x0, \
		.tBit.md5_cr_mx10_g3 = 0x0, \
	}, \
	.CFGR_R0_MD5_CR_MX11 = \
	{ \
		.tBit.md5_cr_mx11_g1 = 0x0, \
		.tBit.md5_cr_mx11_g2 = 0x0, \
		.tBit.md5_cr_mx11_g3 = 0x0, \
	}, \
	.CFGR_R0_MD5_CR_MX12 = \
	{ \
		.tBit.md5_cr_mx12_g1 = 0x0, \
		.tBit.md5_cr_mx12_g2 = 0x0, \
		.tBit.md5_cr_mx12_g3 = 0x0, \
	}, \
	.CFGR_R0_MD5_CRB_MX12 = \
	{ \
		.tBit.md5_crb_mx12_g1 = 0x0, \
		.tBit.md5_crb_mx12_g2 = 0x0, \
		.tBit.md5_crb_mx12_g3 = 0x0, \
	}, \
	.CFGR_R1_MD5_CRT_MX1 = \
	{ \
		.tBit.md5_crt_mx1_g1 = 0x0, \
		.tBit.md5_crt_mx1_g2 = 0x0, \
		.tBit.md5_crt_mx1_g3 = 0x0, \
	}, \
	.CFGR_R1_MD5_CR_MX1 = \
	{ \
		.tBit.md5_cr_mx1_g1 = 0x0, \
		.tBit.md5_cr_mx1_g2 = 0x0, \
		.tBit.md5_cr_mx1_g3 = 0x0, \
	}, \
	.CFGR_R1_MD5_CR_MX2 = \
	{ \
		.tBit.md5_cr_mx2_g1 = 0x0, \
		.tBit.md5_cr_mx2_g2 = 0x0, \
		.tBit.md5_cr_mx2_g3 = 0x0, \
	}, \
	.CFGR_R1_MD5_CR_MX3 = \
	{ \
		.tBit.md5_cr_mx3_g1 = 0x0, \
		.tBit.md5_cr_mx3_g2 = 0x0, \
		.tBit.md5_cr_mx3_g3 = 0x0, \
	}, \
	.CFGR_R1_MD5_CR_MX4 = \
	{ \
		.tBit.md5_cr_mx4_g1 = 0x0, \
		.tBit.md5_cr_mx4_g2 = 0x0, \
		.tBit.md5_cr_mx4_g3 = 0x0, \
	}, \
	.CFGR_R1_MD5_CR_MX5 = \
	{ \
		.tBit.md5_cr_mx5_g1 = 0x0, \
		.tBit.md5_cr_mx5_g2 = 0x0, \
		.tBit.md5_cr_mx5_g3 = 0x0, \
	}, \
	.CFGR_R1_MD5_CR_MX9 = \
	{ \
		.tBit.md5_cr_mx9_g1 = 0x0, \
		.tBit.md5_cr_mx9_g2 = 0x0, \
		.tBit.md5_cr_mx9_g3 = 0x0, \
	}, \
	.CFGR_R1_MD5_CR_MX10 = \
	{ \
		.tBit.md5_cr_mx10_g1 = 0x0, \
		.tBit.md5_cr_mx10_g2 = 0x0, \
		.tBit.md5_cr_mx10_g3 = 0x0, \
	}, \
	.CFGR_R1_MD5_CR_MX11 = \
	{ \
		.tBit.md5_cr_mx11_g1 = 0x0, \
		.tBit.md5_cr_mx11_g2 = 0x0, \
		.tBit.md5_cr_mx11_g3 = 0x0, \
	}, \
	.CFGR_R1_MD5_CR_MX12 = \
	{ \
		.tBit.md5_cr_mx12_g1 = 0x0, \
		.tBit.md5_cr_mx12_g2 = 0x0, \
		.tBit.md5_cr_mx12_g3 = 0x0, \
	}, \
	.CFGR_R1_MD5_CRB_MX12 = \
	{ \
		.tBit.md5_crb_mx12_g1 = 0x0, \
		.tBit.md5_crb_mx12_g2 = 0x0, \
		.tBit.md5_crb_mx12_g3 = 0x0, \
	}, \
	.CFGR_GPO_FUNC = \
	{ \
		.tBit.miso_func = 0x0, \
		.tBit.gpo0_func = 0x0, \
		.tBit.gpo1_func = 0x0, \
	}, \
	.CFGR_ND_CTRL = \
	{ \
		.tBit.nd_num = 0x0, \
		.tBit.nd_en = 0x0, \
	}, \
	.CFGR_CH_EN_NUM = \
	{ \
		.tBit.ch_en_num0 = 0x1C, \
		.tBit.ch_en_num1 = 0x1C, \
	}, \
	.CFGR_ROIC_REV = \
	{ \
		.tBit.r0_roic_rev = 0, \
		.tBit.r1_roic_rev = 0, \
	}, \
	.CFGR_RESERVE_0 = 0, \
	.CFGR_ERR_CLR = \
	{ \
		.tBit.tsync_fault_clr = 0, \
		.tBit.pwm_fault_clr = 0, \
		.tBit.chksum_fault_clr = 0, \
	}, \
	.CFGR_ERR_STATUS = \
	{ \
		.tBit.tsync_fault = 0, \
		.tBit.pwm_fault = 0, \
		.tBit.chksum_fault = 0, \
	}

#endif /* (USED_ROIC_DEF == ROIC_SW92502) */

#endif /* __SW92502_PARAMPRESET_H_ */
