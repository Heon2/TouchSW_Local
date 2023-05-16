/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _SW92505_parampreset.h
 * created on : 18. 8. 2020
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

#ifndef __SW92505_PARAMPRESET_H_
#define __SW92505_PARAMPRESET_H_


#if (USED_ROIC_DEF == ROIC_SW92505)
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
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_CTL_pwm_pdrv_num, \
		.tBit.pwm_act_num = PARAMSET_ROIC_PWM_CTL_pwm_act_num, \
		.tBit.pwm_smpl_num = PARAMSET_ROIC_PWM_CTL_pwm_smpl_num, \
		.tBit.pwm_dum_num = PARAMSET_ROIC_PWM_CTL_pwm_dum_num, \
		.tBit.pdrv_dum_num = PARAMSET_ROIC_PWM_CTL_pdrv_dum_num, \
		.tBit.pwm_set_num = PARAMSET_ROIC_PWM_CTL_pwm_set_num, \
	}, \
	.CFGR_PWM_POS_CTL = \
	{ \
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_pdrv_num, \
		.tBit.pwm_act_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_act_num, \
		.tBit.pwm_smpl_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_smpl_num, \
		.tBit.pwm_dum_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_dum_num, \
		.tBit.pdrv_dum_num = PARAMSET_ROIC_PWM_POS_CTL_pdrv_dum_num, \
		.tBit.pwm_set_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_set_num, \
	}, \
	.CFGR_PWM_DAT_CTL = \
	{ \
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_DAT_CTL_pwm_pdrv_num, \
		.tBit.pwm_act_num = PARAMSET_ROIC_PWM_DAT_CTL_pwm_act_num, \
		.tBit.pwm_smpl_num = PARAMSET_ROIC_PWM_DAT_CTL_pwm_smpl_num, \
		.tBit.pwm_dum_num = PARAMSET_ROIC_PWM_DAT_CTL_pwm_dum_num, \
		.tBit.pdrv_dum_num = PARAMSET_ROIC_PWM_DAT_CTL_pdrv_dum_num, \
		.tBit.pwm_set_num = PARAMSET_ROIC_PWM_DAT_CTL_pwm_set_num, \
	}, \
	.ND_CTRL = \
	{ \
		.tBit.nd_dum_dly = PARAMSET_ROIC_ND_CTRL_nd_dum_dly, \
	}, \
	.CFGR_PWM_PRD = \
	{ \
		.tBit.pwm_prd1 = PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd1, \
		.tBit.pwm_prd2 = PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd2, \
	}, \
	.CFGR_SMPL_CTL = \
	{ \
		.tBit.smop_prd_1 = PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd_1, \
		.tBit.smop_prd_2 = PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd_2, \
		.tBit.crrpt_num = PARAMSET_ROIC_CFGR_SMPL_CTL_crrpt_num, \
	}, \
	.CFGR_RSTP_NUM1 = \
	{ \
		.tBit.rstp_num1 = PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num1, \
		.tBit.rstp_num2 = PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num2, \
	}, \
	.CFGR_PHT_NUM1 = \
	{ \
		.tBit.pht_num1 = PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num1, \
		.tBit.pht_num2 = PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num2, \
	}, \
	.CFGR_PHTCR_NUM1 = \
	{ \
		.tBit.phtcr_num1_1 = PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_1, \
		.tBit.phtcr_num1_2 = PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_2, \
	}, \
	.CFGR_PHTCR_NUM2 = \
	{ \
		.tBit.phtcr_num2_1 = PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_1, \
		.tBit.phtcr_num2_2 = PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_2, \
	}, \
	.CFGR_VCR_NUM1 = \
	{ \
		.tBit.vcr_num1_1 = PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_1, \
		.tBit.vcr_num1_2 = PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_2, \
	}, \
	.CFGR_VCR_EN_NUM1 = \
	{ \
		.tBit.vcr_en_num1_1 = PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_1, \
		.tBit.vcr_en_num1_2 = PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_2, \
	}, \
	.CFGR_VCR_EN_NUM2 = \
	{ \
		.tBit.vcr_en_num2_1 = PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_1, \
		.tBit.vcr_en_num2_2 = PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_2, \
	}, \
	.CFGR_PHTH0_NUM1 = \
	{ \
		.tBit.phth0_num1_1 = PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_1, \
		.tBit.phth0_num1_2 = PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_2, \
	}, \
	.CFGR_PHTH1_NUM1 = \
	{ \
		.tBit.phth1_num1_1 = PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_1, \
		.tBit.phth1_num1_2 = PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_2, \
	}, \
	.CFGR_PHTH_NUM2 = \
	{ \
		.tBit.phth0_num2 = PARAMSET_ROIC_CFGR_PHTH_NUM2_phth0_num2, \
		.tBit.phth1_num2 = PARAMSET_ROIC_CFGR_PHTH_NUM2_phth1_num2, \
	}, \
	.CFGR_PHT_CTL = \
	{ \
		.tBit.pht_prd = PARAMSET_ROIC_CFGR_PHT_CTL_pht_prd, \
		.tBit.pht_opt_smpl = PARAMSET_ROIC_CFGR_PHT_CTL_pht_opt_smpl, \
		.tBit.pht_opt_inv = PARAMSET_ROIC_CFGR_PHT_CTL_pht_opt_inv, \
		.tBit.pht_etime = PARAMSET_ROIC_CFGR_PHT_CTL_pht_etime, \
	}, \
	.CFGR_ADC_CTRL = \
	{ \
		.tBit.adc_op_opt = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_op_opt, \
		.tBit.adc_clk_opt = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_opt, \
		.tBit.adc_clk_pol = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_pol, \
		.tBit.adc_clk_prd = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_prd, \
		.tBit.adc_clk_num = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_num, \
		.tBit.adc_in_pos = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_in_pos, \
		.tBit.adc_stc_dly = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_stc_dly, \
		.tBit.adc_clk_spt = PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_spt, \
		.tBit.cfgr_tm_adc = PARAMSET_ROIC_CFGR_ADC_CTRL_cfgr_tm_adc, \
	}, \
	.CFGR_VCOMR_OPT = \
	{ \
		.tBit.display_vcomr = PARAMSET_VCOMR, \
		.tBit.touch_f_vcomr = PARAMSET_VCOMR, \
		.tBit.touch_p_vcomr = PARAMSET_VCOMR, \
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
			.tBit.stuck_vcr = 0,/*0,*/ \
			.tBit.stuck_rsti = 0, \
			.tBit.stuck_phth0 = 0, \
			.tBit.stuck_phth1 = 0, \
			.tBit.stuck_pht0 = 0, \
			.tBit.stuck_pht1 = 0, \
			.tBit.stuck_vcr_odd_en = 3, \
			.tBit.stuck_vcr_even_en = 3, \
			.tBit.stuck_muxs_en = 0, /*0,*/ \
			.tBit.stuck_muxf_en = 0, \
		}, \
		[1] = \
		{ \
			.tBit.stuck_rstp = 0, \
			.tBit.stuck_phtcr = 0, \
			.tBit.stuck_vcr = 0, \
			.tBit.stuck_rsti = 0, \
			.tBit.stuck_phth0 = 0, \
			.tBit.stuck_phth1 = 0, \
			.tBit.stuck_pht0 = 0, \
			.tBit.stuck_pht1 = 0, \
			.tBit.stuck_vcr_odd_en = 3, \
			.tBit.stuck_vcr_even_en = 3, \
			.tBit.stuck_muxs_en = 0, /*0,*/ \
			.tBit.stuck_muxf_en = 0, \
		}, \
		[2] = \
		{ \
			.tBit.stuck_rstp = 0, \
			.tBit.stuck_phtcr = 0, \
			.tBit.stuck_vcr = 0, \
			.tBit.stuck_rsti = 0, \
			.tBit.stuck_phth0 = 0, \
			.tBit.stuck_phth1 = 0, \
			.tBit.stuck_pht0 = 0, \
			.tBit.stuck_pht1 = 0, \
			.tBit.stuck_vcr_odd_en = 3, \
			.tBit.stuck_vcr_even_en = 3, \
			.tBit.stuck_muxs_en = 0, /*0,*/ \
			.tBit.stuck_muxf_en = 0, \
		}, \
		[3] = \
		{ \
			.tBit.stuck_rstp = 0, \
			.tBit.stuck_phtcr = 0, \
			.tBit.stuck_vcr = 0, \
			.tBit.stuck_rsti = 0, \
			.tBit.stuck_phth0 = 0, \
			.tBit.stuck_phth1 = 0, \
			.tBit.stuck_pht0 = 0, \
			.tBit.stuck_pht1 = 0, \
			.tBit.stuck_vcr_odd_en = 3, \
			.tBit.stuck_vcr_even_en = 3, \
			.tBit.stuck_muxs_en = 0, /*0,*/ \
			.tBit.stuck_muxf_en = 0, \
		}, \
		[4] = \
		{ \
			.tBit.stuck_rstp = 0, \
			.tBit.stuck_phtcr = 0, \
			.tBit.stuck_vcr = 0, \
			.tBit.stuck_rsti = 0, \
			.tBit.stuck_phth0 = 0, \
			.tBit.stuck_phth1 = 0, \
			.tBit.stuck_pht0 = 0, \
			.tBit.stuck_pht1 = 0, \
			.tBit.stuck_vcr_odd_en = 3, \
			.tBit.stuck_vcr_even_en = 3, \
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
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_1_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_1_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_1_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_1_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_1_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_1_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_1_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_1_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_1_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_1_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_1_local_pos3, \
			}, \
			[1] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_2_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_2_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_2_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_2_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_2_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_2_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_2_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_2_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_2_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_2_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_2_local_pos3, \
			}, \
			[2] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_3_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_3_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_3_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_3_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_3_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_3_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_3_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_3_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_3_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_3_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_3_local_pos3, \
			}, \
			[3] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_4_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_4_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_4_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_4_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_4_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_4_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_4_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_4_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_4_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_4_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_4_local_pos3, \
			}, \
			[4] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_5_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_5_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_5_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_5_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_5_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_5_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_5_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_5_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_5_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_5_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_5_local_pos3, \
			}, \
			[5] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_6_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_6_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_6_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_6_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_6_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_6_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_6_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_6_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_6_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_6_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_6_local_pos3, \
			}, \
			[6] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_7_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_7_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_7_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_7_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_7_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_7_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_7_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_7_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_7_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_7_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_7_local_pos3, \
			}, \
			[7] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_8_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_8_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_8_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_8_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_8_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_8_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_8_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_8_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_8_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_8_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_8_local_pos3, \
			}, \
			[8] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_9_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_9_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_9_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_9_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_9_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_9_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_9_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_9_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_9_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_9_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_9_local_pos3, \
			}, \
			[9] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_10_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_10_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_10_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_10_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_10_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_10_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_10_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_10_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_10_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_10_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_10_local_pos3, \
			}, \
			[10] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_11_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_11_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_11_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_11_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_11_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_11_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_11_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_11_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_11_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_11_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_11_local_pos3, \
			}, \
			[11] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_12_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_12_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_12_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_12_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_12_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_12_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_12_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_12_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_12_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_12_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_12_local_pos3, \
			}, \
			[12] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_13_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_13_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_13_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_13_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_13_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_13_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_13_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_13_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_13_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_13_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_13_local_pos3, \
			}, \
			[13] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_14_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_14_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_14_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_14_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_14_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_14_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_14_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_14_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_14_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_14_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_14_local_pos3, \
			}, \
			[14] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_15_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_15_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_15_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_15_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_15_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_15_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_15_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_15_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_15_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_15_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_15_local_pos3, \
			}, \
			[15] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_FULL_LHB_16_mode, \
				.tBit.ping_en = PARAMSET_ROIC_FULL_LHB_16_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_FULL_LHB_16_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_FULL_LHB_16_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_FULL_LHB_16_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_FULL_LHB_16_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_FULL_LHB_16_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_FULL_LHB_16_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_FULL_LHB_16_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_FULL_LHB_16_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_FULL_LHB_16_local_pos3, \
			}, \
		}, \
		[PWM_LOCAL_PEN_MODE] = \
		{ \
			[0] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_1_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_1_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_1_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_1_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_1_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_1_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_1_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_1_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_1_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_1_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_1_local_pos3, \
			}, \
			[1] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_2_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_2_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_2_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_2_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_2_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_2_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_2_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_2_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_2_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_2_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_2_local_pos3, \
			}, \
			[2] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_3_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_3_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_3_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_3_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_3_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_3_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_3_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_3_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_3_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_3_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_3_local_pos3, \
			}, \
			[3] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_4_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_4_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_4_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_4_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_4_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_4_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_4_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_4_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_4_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_4_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_4_local_pos3, \
			}, \
			[4] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_5_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_5_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_5_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_5_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_5_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_5_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_5_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_5_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_5_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_5_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_5_local_pos3, \
			}, \
			[5] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_6_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_6_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_6_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_6_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_6_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_6_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_6_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_6_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_6_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_6_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_6_local_pos3, \
			}, \
			[6] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_7_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_7_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_7_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_7_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_7_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_7_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_7_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_7_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_7_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_7_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_7_local_pos3, \
			}, \
			[7] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_8_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_8_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_8_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_8_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_8_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_8_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_8_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_8_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_8_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_8_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_8_local_pos3, \
			}, \
			[8] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_9_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_9_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_9_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_9_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_9_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_9_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_9_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_9_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_9_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_9_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_9_local_pos3, \
			}, \
			[9] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_10_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_10_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_10_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_10_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_10_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_10_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_10_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_10_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_10_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_10_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_10_local_pos3, \
			}, \
			[10] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_11_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_11_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_11_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_11_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_11_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_11_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_11_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_11_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_11_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_11_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_11_local_pos3, \
			}, \
			[11] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_12_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_12_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_12_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_12_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_12_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_12_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_12_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_12_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_12_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_12_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_12_local_pos3, \
			}, \
			[12] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_13_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_13_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_13_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_13_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_13_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_13_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_13_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_13_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_13_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_13_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_13_local_pos3, \
			}, \
			[13] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_14_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_14_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_14_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_14_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_14_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_14_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_14_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_14_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_14_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_14_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_14_local_pos3, \
			}, \
			[14] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_15_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_15_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_15_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_15_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_15_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_15_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_15_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_15_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_15_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_15_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_15_local_pos3, \
			}, \
			[15] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_16_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_16_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_16_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_16_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_16_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_16_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_16_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_16_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_16_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_16_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_16_local_pos3, \
			}, \
		}, \
		[PWM_LOCAL_PEN_IDLE_MODE] = \
		{ \
			[0] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_1_local_pos3, \
			}, \
			[1] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_2_local_pos3, \
			}, \
			[2] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_3_local_pos3, \
			}, \
			[3] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_4_local_pos3, \
			}, \
			[4] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_5_local_pos3, \
			}, \
			[5] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_6_local_pos3, \
			}, \
			[6] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_7_local_pos3, \
			}, \
			[7] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_8_local_pos3, \
			}, \
			[8] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_9_local_pos3, \
			}, \
			[9] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_10_local_pos3, \
			}, \
			[10] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_11_local_pos3, \
			}, \
			[11] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_12_local_pos3, \
			}, \
			[12] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_13_local_pos3, \
			}, \
			[13] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos3, \
			}, \
			[14] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos3, \
			}, \
			[15] = \
			{ \
				.tBit.mode = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode, \
				.tBit.ping_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_ping_en, \
				.tBit.pre_drv = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_pre_drv, \
				.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_pre_drvs_en, \
				.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_extmuxcmd, \
				.tBit.mux_type = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mux_type, \
				.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_lhb_mux_cnt, \
				.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos0, \
				.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos1, \
				.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos2, \
				.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos3, \
			}, \
		}, \
	}, \
	.CFGR_PWM_SET_EN_BIT = \
	{ \
		.tBit.pwm_set_en_finger = PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_finger, \
		.tBit.pwm_set_en_pen_pos = PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_pos, \
		.tBit.pwm_set_en_pen_dat = PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_dat, \
	}, \
	.CFGR_LHB_MUX_CTRL = \
	{ \
		.tBit.m1_mode_sel = PARAMSET_ROIC_LHB_MUX_CTRL_m1_mode_sel, \
		.tBit.pd_mux_num = PARAMSET_ROIC_LHB_MUX_CTRL_pd_mux_num, \
		.tBit.mux_m1_bit_en = PARAMSET_ROIC_LHB_MUX_CTRL_mux_m1_bit_en, \
		.tBit.mux_nd_bit_en = PARAMSET_ROIC_LHB_MUX_CTRL_mux_nd_bit_en, \
		.tBit.max_lhb_cnt = PARAMSET_ROIC_LHB_MUX_CTRL_max_lhb_cnt, \
		.tBit.ping_mux_type = PARAMSET_ROIC_LHB_MUX_CTRL_ping_mux_type, \
		.tBit.ping_mux_local_sel = PARAMSET_ROIC_LHB_MUX_CTRL_ping_mux_local_sel, \
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
	}, \
	.R1_CFGR_TUNE_GROUP = \
	{ \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_R1_TUNE_GROUP_cr_rg2_sel,/* 2, */ \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_R1_TUNE_GROUP_cr_rg3_sel,/* 28, */ \
	}, \
	.CFGR_SENSE_CTRL = \
	{ \
		.tBit.lv_ssu_bcon = PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcon, \
		.tBit.lv_ssu_bcons = PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcons, \
		.tBit.hv_ssu_bcon = PARAMSET_ROIC_CFGR_SENSE_CTRL_hv_ssu_bcon, \
		.tBit.pen_dc_md = PARAMSET_ROIC_CFGR_SENSE_CTRL_pen_dc_md, \
		.tBit.pen_dc_md_stuck = PARAMSET_ROIC_CFGR_SENSE_CTRL_pen_dc_md_stuck, \
		.tBit.integ_half_f = PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_f, \
		.tBit.integ_half_comp = PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_comp, \
		.tBit.integ_half_p = PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_p, \
		.tBit.pre_gc_f = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_f, \
		.tBit.pre_gc_comp = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_comp, \
		.tBit.pre_gc_p = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_p, \
		.tBit.int_gc_f = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_f, \
		.tBit.int_gc_comp = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_comp, \
		.tBit.int_gc_p = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_p, \
		.tBit.powsel = PARAMSET_ROIC_CFGR_SENSE_CTRL_powsel, \
		.tBit.pre_bs_lp = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_bs_lp, \
		.tBit.int_bs_lp = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_bs_lp, \
		.tBit.tm_ssu_pen = PARAMSET_ROIC_CFGR_SENSE_CTRL_tm_ssu_pen, \
	}, \
	.CFGR_COMP_ADC_CTRL = \
	{ \
		.tBit.adc_bcon = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_bcon, \
		.tBit.adc_stc_insel = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_stc_insel, \
		.tBit.adc_dsf = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_dsf, \
		.tBit.adc_ref_sel = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_ref_sel, \
		.tBit.int_ref = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_int_ref, \
		.tBit.sha_ref = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_sha_ref, \
		.tBit.sha_bs_lp = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_sha_bs_lp, \
		.tBit.ref_res_sel = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_ref_res_sel, \
		.tBit.lv_comp_bcon = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_lv_comp_bcon, \
		.tBit.comp_hys_ctrl = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_comp_hys_ctrl, \
		.tBit.tm_comp = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_tm_comp, \
	}, \
	.CFGR_SSU_PW_CTRL = \
	{ \
		.tBit.pdb_hvbias = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_hvbias, \
		.tBit.pdb_hvr = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_hvr, \
		.tBit.pdb_lvbias = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_lvbias, \
		.tBit.pdb_lvr = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_lvr, \
		.tBit.pdb_sha = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_sha, \
		.tBit.bgr_en = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_bgr_en, \
		.tBit.pdb_adc = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_adc, \
		.tBit.pdb_compbias = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_compbias, \
		.tBit.pdb_comp = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_comp, \
		.tBit.stuck_hvbias = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_hvbias, \
		.tBit.stuck_hvr = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_hvr, \
		.tBit.stuck_lvbias = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_lvbias, \
		.tBit.stuck_lvr = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_lvr, \
		.tBit.stuck_sha = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_sha, \
		.tBit.stuck_bgr = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_bgr, \
		.tBit.stuck_adc = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_adc, \
		.tBit.stuck_compbias = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_compbias, \
		.tBit.stuck_comp = PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_comp, \
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
 		.tBit.r0_pre_ch_con_en	= PARAMSET_PRE_CH_CON_EN, \
		.tBit.r0_pre_comp	    = PARAMSET_PRE_COMP, \
		.tBit.r0_reserve     	= 2, \
		.tBit.r1_pre_ch_con_en	= PARAMSET_PRE_CH_CON_EN, \
		.tBit.r1_pre_comp	    = PARAMSET_PRE_COMP, \
		.tBit.r1_reserve	    = 2, \
	}, \
	.SYS_DUMMY0 = \
	{ \
		.tBit.sd_rocen	=0 , \
		.tBit.sd_pwrcr2	=0 , \
		.tBit.sd_pwrcr3	=0 , \
		.tBit.reserve	=0 , \
	}, \
	.SYS_DUMMY1 = \
	{ \
		.tBit.sd_pwrcr1	=1 , \
		.tBit.reserve	=0x7FFFFFFF , \
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
		.tBit.sd_off = 1, \
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
			.tBit.stuck_muxf_en = 0, /*0,*/ \
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
		.tBit.mux_f_stuck_val = 0,/*0,*/ \
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
				.tBit.mode = SW92505_MODE_BEACON, \
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
				.tBit.mode = SW92505_MODE_DUMMY, \
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
				.tBit.mode = SW92505_MODE_DUMMY, \
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
				.tBit.mode = SW92505_MODE_DUMMY, \
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
				.tBit.mode = SW92505_MODE_FINGER, \
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
				.tBit.mode = SW92505_MODE_DUMMY, \
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
				.tBit.mode = SW92505_MODE_FINGER, \
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
				.tBit.mode = SW92505_MODE_FINGER, \
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
				.tBit.mode = SW92505_MODE_BEACON, \
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
				.tBit.mode = SW92505_MODE_DUMMY, \
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
				.tBit.mode = SW92505_MODE_DUMMY, \
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
				.tBit.mode = SW92505_MODE_DUMMY, \
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
				.tBit.mode = SW92505_MODE_FINGER, \
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
				.tBit.mode = SW92505_MODE_DUMMY, \
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
				.tBit.mode = SW92505_MODE_FINGER, \
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
				.tBit.mode = SW92505_MODE_FINGER, \
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
				.tBit.mode = SW92505_MODE_BEACON, \
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
				.tBit.mode = SW92505_MODE_PEN_POS, \
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
				.tBit.mode = SW92505_MODE_PEN_DATA, \
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
				.tBit.mode = SW92505_MODE_PEN_DATA, \
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
				.tBit.mode = SW92505_MODE_PEN_DATA, \
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
				.tBit.mode = SW92505_MODE_PEN_POS, \
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
				.tBit.mode = SW92505_MODE_PEN_DATA, \
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
				.tBit.mode = SW92505_MODE_DUMMY, \
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
				.tBit.mode = SW92505_MODE_BEACON, \
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
				.tBit.mode = SW92505_MODE_PEN_DATA, \
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
				.tBit.mode = SW92505_MODE_DUMMY, \
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
				.tBit.mode = SW92505_MODE_DUMMY, \
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
				.tBit.mode = SW92505_MODE_FINGER, \
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
				.tBit.mode = SW92505_MODE_PEN_POS, \
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
				.tBit.mode = SW92505_MODE_FINGER, \
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
				.tBit.mode = SW92505_MODE_FINGER, \
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
		.tBit.sd_rocen	=0 , \
		.tBit.sd_pwrcr2	=0 , \
		.tBit.sd_pwrcr3	=0 , \
		.tBit.reserve	=0 , \
	}, \
	.SYS_DUMMY1 = \
	{ \
		.tBit.sd_pwrcr1	=1 , \
		.tBit.reserve	=0x7FFFFFFF , \
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

#endif /* (USED_ROIC_DEF == ROIC_SW92505) */

#endif /* __SW92505_PARAMPRESET_H_ */
