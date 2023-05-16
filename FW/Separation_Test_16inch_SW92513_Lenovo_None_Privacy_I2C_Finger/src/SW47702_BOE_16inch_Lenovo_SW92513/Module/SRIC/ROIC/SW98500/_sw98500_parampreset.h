/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _SW98500_parampreset.h
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

#ifndef __SW98500_PARAMPRESET_H_
#define __SW98500_PARAMPRESET_H_


#if (USED_ROIC_DEF == ROIC_SW98500)
#define SRIC_WGPPEN_Conf_Set                 \
	.SPIS_CFG =                              \
		{                                    \
			.tBit.chksum_opt = 1,            \
			.tBit.spis_irq_en = 1,           \
	},                                       \
	.SPIS_ERROR_CLR =                        \
		{                                    \
			.tBit.spi_chksum_clr = 0,        \
			.tBit.tsync_fault_clr = 0,       \
			.tBit.pwm_fault_clr = 0,         \
	},                                       \
	.SPIS_ERROR_ST =                         \
		{                                    \
			.tBit.spi_chksum_err = 0,        \
			.tBit.tsync_fault_err = 0,       \
			.tBit.pwm_fault_err = 0,         \
	},                                       \
	.SPIS_PAD_CTL =                          \
		{                                    \
			.tBit.miso_ds = 0,               \
			.tBit.miso_dout = 0,             \
			.tBit.miso_func = 0,             \
			.tBit.mosi_ds = 0,               \
			.tBit.mosi_dout = 0,             \
			.tBit.mosi_func = 0,             \
			.tBit.tattn_out = 0,             \
			.tBit.tattn_oe = 0,              \
			.tBit.tattn_ds = 0,              \
			.tBit.tattn_func = 0,            \
			.tBit.tattn_sel0 = 1,            \
			.tBit.tattn_sel1 = 0,            \
			.tBit.tattn_func2 = 0,           \
			.tBit.pad_tattn_test = 0,        \
	},                                       \
	.CFGR_SYS_CFG =                          \
		{                                    \
			.tBit.tg_reset = 0,              \
			.tBit.sw_reset = 0,              \
			.tBit.tg_clk_all_on = 1,         \
			.tBit.buf_clk_on = 1,            \
			.tBit.cfclk_on = 0,              \
	},                                       \
	.CFGR_TC_START =                         \
		{                                    \
			.tBit.tc_start = 0,              \
	},                                       \
	.CFGR_TC_STOP =                          \
		{                                    \
			.tBit.tc_stop = 0,               \
	},                                       \
	.CFGR_R0_CH_EN =                         \
		{                                    \
			.tBit.ch_num = 32,               \
			.tBit.ch_en_lvr = PARAMSET_ROIC_CFGR_R0_CH_EN_ch_en_lvr,           \
			.tBit.ch_en_hvr = PARAMSET_ROIC_CFGR_R0_CH_EN_ch_en_hvr,           \
			.tBit.dum_drv_en = 0,            \
	},                                       \
	.CFGR_R1_CH_EN =                         \
		{                                    \
			.tBit.ch_num = 32,               \
			.tBit.ch_en_lvr = PARAMSET_ROIC_CFGR_R1_CH_EN_ch_en_lvr,           \
			.tBit.ch_en_hvr = PARAMSET_ROIC_CFGR_R1_CH_EN_ch_en_hvr,           \
			.tBit.dum_drv_en = 0,            \
	},                                       \
	.CFGR_MUX_EN =                           \
		{                                    \
			.tBit.mux_int_en = 0,            \
			.tBit.mux_num_tot = 5,           \
	},                                       \
	.CFGR_MUX_DLY =                          \
		{                                    \
			.tBit.mux_dly = 0,               \
	},                                       \
	.CFGR_DIC_CFG =                          \
		{                                    \
			.tBit.sd_off = 0,                \
			.tBit.sd_float = 0,              \
			.tBit.tsync_in_pol = 0,          \
			.tBit.pwm_pol = 0,               \
			.tBit.tsync_out_pol = 0,         \
			.tBit.tsync_out_bypass = 1,      \
			.tBit.tsync_out_stuck = 0,       \
			.tBit.tsync_out_level = 0,       \
			.tBit.vsync_pol = 0,             \
			.tBit.vsync_tg_en = 0,           \
			.tBit.vsync_tg_act = 0,          \
			.tBit.sd_gnd = 0,                \
			.tBit.stuck_abd = 0,             \
			.tBit.cfgr_abd = 0,              \
			.tBit.cfgr_abd_pol = 1,          \
			.tBit.cfgr_abd_inv = 0,          \
	},                                       \
	.CFGR_PWM_CTL =                          \
	{                                    \
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_CTL_pwm_pdrv_num, \
		.tBit.pwm_act_num = PARAMSET_ROIC_PWM_CTL_pwm_act_num,   \
		.tBit.pwm_mgap_num = PARAMSET_ROIC_PWM_CTL_pwm_mgap_num, \
		.tBit.pwm_dum_num = PARAMSET_ROIC_PWM_CTL_pwm_dum_num,   \
		.tBit.pwm_set_num = PARAMSET_ROIC_PWM_CTL_pwm_set_num,   \
	},                                       \
	.CFGR_PWM_POS_CTL =                      \
	{                                    \
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_pdrv_num, \
		.tBit.pwm_act_num  = PARAMSET_ROIC_PWM_POS_CTL_pwm_act_num,  \
		.tBit.pwm_mgap_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_mgap_num, \
		.tBit.pwm_dum_num  = PARAMSET_ROIC_PWM_POS_CTL_pwm_dum_num,  \
		.tBit.pwm_set_num  = PARAMSET_ROIC_PWM_POS_CTL_pwm_set_num,  \
	},                                       \
	.CFGR_PWM_DAT_CTL =                      \
	{                                    \
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_DATA_CTL_pwm_pdrv_num, \
		.tBit.pwm_act_num = PARAMSET_ROIC_PWM_DATA_CTL_pwm_act_num,   \
		.tBit.pwm_mgap_num = PARAMSET_ROIC_PWM_DATA_CTL_pwm_mgap_num, \
		.tBit.pwm_dum_num = PARAMSET_ROIC_PWM_DATA_CTL_pwm_dum_num,   \
		.tBit.pwm_set_num = PARAMSET_ROIC_PWM_DATA_CTL_pwm_set_num,   \
	},                                       \
	.ND_CTRL =                               \
		{                                    \
			.tBit.nd_pwm_act_num = 7,        \
	},                                       \
	.CFGR_PWM_PRD =                          \
		{                                    \
			.tBit.pwm_prd1 = PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd1,             \
			.tBit.pwm_prd2 = PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd2,             \
	},                                       \
	.CFGR_SMPL_CTL =                         \
		{                                    \
			.tBit.smop_prd_1 = 7,            \
			.tBit.smop_prd_2 = 7,            \
			.tBit.smop_prd_3 = 1,            \
			.tBit.crrpt_num = 0,             \
	},                                       \
	.CFGR_RSTP_NUM1 =                        \
		{                                    \
			.tBit.rstp_num1 = PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num1,            \
			.tBit.rstp_num2 = PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num2,             \
	},                                       \
	.CFGR_PHTCR_NUM1 =                       \
		{                                    \
			.tBit.phtcr_num1_1 = PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_1,         \
			.tBit.phtcr_num1_2 = PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_2,         \
	},                                       \
	.CFGR_PHTCR_NUM2 =                       \
		{                                    \
			.tBit.phtcr_num2_1 = PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_1,         \
			.tBit.phtcr_num2_2 = PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_2,         \
	},                                       \
	.CFGR_VCR_NUM1 =                         \
		{                                    \
			.tBit.vcr_num1_1 = PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_1,           \
			.tBit.vcr_num1_2 = PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_2,           \
	},                                       \
	.CFGR_RSTI_NUM1 =                        \
		{                                    \
			.tBit.rsti_num1 = PARAMSET_ROIC_CFGR_RSTI_NUM1_rsti_num1,            \
	},                                       \
	.CFGR_RSTI_NUM2 =                        \
		{                                    \
			.tBit.rsti_num2_1 = PARAMSET_ROIC_CFGR_RSTI_NUM2_rsti_num2_1,           \
			.tBit.rsti_num2_2 = PARAMSET_ROIC_CFGR_RSTI_NUM2_rsti_num2_2,           \
	},                                       \
	.CFGR_PHTH0_NUM1 =                       \
		{                                    \
			.tBit.phth0_num1_1 = PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_1,         \
			.tBit.phth0_num1_2 = PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_2,         \
	},                                       \
	.CFGR_PHTH1_NUM1 =                       \
		{                                    \
			.tBit.phth1_num1_1 = PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_1,         \
			.tBit.phth1_num1_2 = PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_2,         \
	},                                       \
	.CFGR_PHTH_NUM2 =                        \
		{                                    \
			.tBit.phth0_num2 = PARAMSET_ROIC_CFGR_PHTH_NUM2_phth0_num2,            \
			.tBit.phth1_num2 = PARAMSET_ROIC_CFGR_PHTH_NUM2_phth1_num2,           \
	},                                       \
	.CFGR_PHT_CTL =                          \
		{                                    \
			.tBit.pht_prd = 2,               \
			.tBit.pht_opt_smpl = 0,          \
			.tBit.pht_opt_inv = 1,           \
			.tBit.pht_etime = 16,            \
			.tBit.pht_act_en = 0,            \
			.tBit.pht_act_pwm_num = 0,       \
			.tBit.pht_act_pwr_num = 0,       \
	},                                       \
	.CFGR_PHT_NUM1 =                         \
		{                                    \
			.tBit.pht_num1 = PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num1,             \
			.tBit.pht_num2 = PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num2,             \
	},                                       \
	.CFGR_ADC_CTRL =                         \
		{                                    \
			.tBit.adc_op_opt  = 0,           \
			.tBit.adc_clk_opt = 1,           \
			.tBit.adc_clk_pol = 0,           \
			.tBit.adc_clk_prd = 0,/*0,*/           \
			.tBit.adc_clk_num = 7,           \
			.tBit.adc_in_pos  = 5,           \
			.tBit.adc_stc_dly = 31,          \
			.tBit.adc_clk_spt = 0,           \
			.tBit.adc_clk_prd_f = 1,/*0,*/         \
			.tBit.cfgr_tm_adc = 0,           \
	},                                       \
	.CFGR_VCOMR_OPT =                        \
		{                                    \
			.tBit.display_vcomr = 1,         \
			.tBit.touch_f_vcomr = 1,         \
			.tBit.touch_p_vcomr = 1,         \
			.tBit.stuck_left = 0,            \
			.tBit.stuck_right = 0,           \
			.tBit.stuck_level = 0,           \
			.tBit.tsync_opt = 0,             \
	},                                       \
	.CFGR_BUF_OPT =                          \
		{                                    \
			.tBit.double_buf_en = 1,         \
			.tBit.raw_buf_ctl_en = 1,        \
	},                                       \
	.CFGR_TG_STUCK =                         \
		{                                    \
			.tBit.stuck_rstp = 0,            \
			.tBit.stuck_phtcr = 0,           \
			.tBit.stuck_vcr = 0,             \
			.tBit.stuck_rsti = 0,            \
			.tBit.stuck_phth0 = 0,           \
			.tBit.stuck_phth1 = 0,           \
			.tBit.stuck_pht0 = 0,            \
			.tBit.stuck_pht1 = 0,            \
			.tBit.stuck_vcr_odd_en0 = 1,     \
			.tBit.stuck_vcr_even_en0 = 1,    \
			.tBit.stuck_vcr_odd_en1 = 1,     \
			.tBit.stuck_vcr_even_en1 = 1,    \
			.tBit.stuck_muxf_en = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_muxf_en,         \
			.tBit.stuck_muxs_en = PARAMSET_ROIC_CFGR_TG_STUCK_stuck_muxs_en,         \
	},                                       \
	.CFGR_ADC_IN =                           \
		{                                    \
			.tBit.adc_in = 1,                \
	},                                       \
	.CFGR_MUX_S_STUCK_VAL =                  \
		{                                    \
			.tBit.mux_s_stuck_val = PARAMSET_ROIC_CFGR_MUX_S_STUCK_VAL_mux_s_stuck_val,       \
	},                                       \
	.CFGR_MUX_F_STUCK_VAL =                  \
		{                                    \
			.tBit.mux_f_stuck_val = PARAMSET_ROIC_CFGR_MUX_F_STUCK_VAL_mux_f_stuck_val,       \
	},                                       \
	.CFGR_MUX_CFG_00 =                       \
		{                                    \
			.tBit.MUX_00 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_1Mux,	\
			.tBit.MUX_01 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_2Mux,	\
			.tBit.MUX_02 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_3Mux,	\
			.tBit.MUX_03 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_1Mux,	\
			.tBit.MUX_04 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_2Mux,	\
			.tBit.MUX_05 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_3Mux,	\
			.tBit.MUX_06 = 0,                \
			.tBit.MUX_07 = 0,                \
	},                                       \
	.CFGR_MUX_CFG_01 =                       \
		{                                    \
			.tBit.MUX_08 = 0,                \
			.tBit.MUX_09 = 0,                \
			.tBit.MUX_10 = 0,                \
			.tBit.MUX_11 = 0,                \
			.tBit.MUX_12 = 0,                \
			.tBit.MUX_13 = 0,                \
			.tBit.MUX_14 = 0,                \
			.tBit.MUX_15 = 0,                \
	},                                       \
	.RCOM_LHB_CFG =                          \
		{                                    \
			.tBit.mode = 0,                  \
			.tBit.tsync_num = PARAMSET_ROIC_CFGR_LHB_CFG_tsync_num,             \
			.tBit.dum_tsync_num = 0,         \
			.tBit.beacon_en = 0,             \
			.tBit.rdcom_en = 0,              \
			.tBit.sgap_num = 0,              \
	},                                       \
	.DEFA_LHB_MCFG00 = {                     \
		[PWM_FULL_FINGER_MODE] = \
		{ \
			.tBit.mode01 = PARAMSET_ROIC_CFGR_LHB_MCFG_1LHB_FULL,                \
			.tBit.mode02 = PARAMSET_ROIC_CFGR_LHB_MCFG_2LHB_FULL,                \
			.tBit.mode03 = PARAMSET_ROIC_CFGR_LHB_MCFG_3LHB_FULL,                \
			.tBit.mode04 = PARAMSET_ROIC_CFGR_LHB_MCFG_4LHB_FULL,                \
			.tBit.mode05 = PARAMSET_ROIC_CFGR_LHB_MCFG_5LHB_FULL,                \
			.tBit.mode06 = PARAMSET_ROIC_CFGR_LHB_MCFG_6LHB_FULL,                \
			.tBit.mode07 = PARAMSET_ROIC_CFGR_LHB_MCFG_7LHB_FULL,                \
			.tBit.mode08 = PARAMSET_ROIC_CFGR_LHB_MCFG_8LHB_FULL,                \
			.tBit.mode09 = PARAMSET_ROIC_CFGR_LHB_MCFG_9LHB_FULL,                \
			.tBit.mode10 = PARAMSET_ROIC_CFGR_LHB_MCFG_10LHB_FULL,                \
		},\
		[PWM_LOCAL_PEN_MODE] = \
		{ \
			.tBit.mode01 = PARAMSET_ROIC_CFGR_LHB_MCFG_1LHB_LOCAL,                \
			.tBit.mode02 = PARAMSET_ROIC_CFGR_LHB_MCFG_2LHB_LOCAL,                \
			.tBit.mode03 = PARAMSET_ROIC_CFGR_LHB_MCFG_3LHB_LOCAL,                \
			.tBit.mode04 = PARAMSET_ROIC_CFGR_LHB_MCFG_4LHB_LOCAL,                \
			.tBit.mode05 = PARAMSET_ROIC_CFGR_LHB_MCFG_5LHB_LOCAL,                \
			.tBit.mode06 = PARAMSET_ROIC_CFGR_LHB_MCFG_6LHB_LOCAL,                \
			.tBit.mode07 = PARAMSET_ROIC_CFGR_LHB_MCFG_7LHB_LOCAL,                \
			.tBit.mode08 = PARAMSET_ROIC_CFGR_LHB_MCFG_8LHB_LOCAL,                \
			.tBit.mode09 = PARAMSET_ROIC_CFGR_LHB_MCFG_9LHB_LOCAL,                \
			.tBit.mode10 = PARAMSET_ROIC_CFGR_LHB_MCFG_10LHB_LOCAL,                \
		},\
		[PWM_LOCAL_PEN_IDLE_MODE] = \
		{ \
			.tBit.mode01 = PARAMSET_ROIC_CFGR_LHB_MCFG_1LHB_IDLE,                \
			.tBit.mode02 = PARAMSET_ROIC_CFGR_LHB_MCFG_2LHB_IDLE,                \
			.tBit.mode03 = PARAMSET_ROIC_CFGR_LHB_MCFG_3LHB_IDLE,                \
			.tBit.mode04 = PARAMSET_ROIC_CFGR_LHB_MCFG_4LHB_IDLE,                \
			.tBit.mode05 = PARAMSET_ROIC_CFGR_LHB_MCFG_5LHB_IDLE,                \
			.tBit.mode06 = PARAMSET_ROIC_CFGR_LHB_MCFG_6LHB_IDLE,                \
			.tBit.mode07 = PARAMSET_ROIC_CFGR_LHB_MCFG_7LHB_IDLE,                \
			.tBit.mode08 = PARAMSET_ROIC_CFGR_LHB_MCFG_8LHB_IDLE,                \
			.tBit.mode09 = PARAMSET_ROIC_CFGR_LHB_MCFG_9LHB_IDLE,                \
			.tBit.mode10 = PARAMSET_ROIC_CFGR_LHB_MCFG_10LHB_IDLE,                \
		}, \
	},\
	.DEFA_LHB_MCFG01 = {                     \
		[PWM_FULL_FINGER_MODE] = \
		{ \
			.tBit.mode11 = PARAMSET_ROIC_CFGR_LHB_MCFG_11LHB_FULL,                \
			.tBit.mode12 = PARAMSET_ROIC_CFGR_LHB_MCFG_12LHB_FULL,                \
			.tBit.mode13 = PARAMSET_ROIC_CFGR_LHB_MCFG_13LHB_FULL,                \
			.tBit.mode14 = PARAMSET_ROIC_CFGR_LHB_MCFG_14LHB_FULL,                \
			.tBit.mode15 = PARAMSET_ROIC_CFGR_LHB_MCFG_15LHB_FULL,                \
			.tBit.mode16 = PARAMSET_ROIC_CFGR_LHB_MCFG_16LHB_FULL,                \
			.tBit.mode17 = PARAMSET_ROIC_CFGR_LHB_MCFG_17LHB_FULL,                \
			.tBit.mode18 = PARAMSET_ROIC_CFGR_LHB_MCFG_18LHB_FULL,                \
			.tBit.mode19 = PARAMSET_ROIC_CFGR_LHB_MCFG_19LHB_FULL,                \
			.tBit.mode20 = PARAMSET_ROIC_CFGR_LHB_MCFG_20LHB_FULL,                \
		},\
		[PWM_LOCAL_PEN_MODE] = \
		{ \
			.tBit.mode11 = PARAMSET_ROIC_CFGR_LHB_MCFG_11LHB_LOCAL,                \
			.tBit.mode12 = PARAMSET_ROIC_CFGR_LHB_MCFG_12LHB_LOCAL,                \
			.tBit.mode13 = PARAMSET_ROIC_CFGR_LHB_MCFG_13LHB_LOCAL,                \
			.tBit.mode14 = PARAMSET_ROIC_CFGR_LHB_MCFG_14LHB_LOCAL,                \
			.tBit.mode15 = PARAMSET_ROIC_CFGR_LHB_MCFG_15LHB_LOCAL,                \
			.tBit.mode16 = PARAMSET_ROIC_CFGR_LHB_MCFG_16LHB_LOCAL,                \
			.tBit.mode17 = PARAMSET_ROIC_CFGR_LHB_MCFG_17LHB_LOCAL,                \
			.tBit.mode18 = PARAMSET_ROIC_CFGR_LHB_MCFG_18LHB_LOCAL,                \
			.tBit.mode19 = PARAMSET_ROIC_CFGR_LHB_MCFG_19LHB_LOCAL,                \
			.tBit.mode20 = PARAMSET_ROIC_CFGR_LHB_MCFG_20LHB_LOCAL,                \
		},\
		[PWM_LOCAL_PEN_IDLE_MODE] = \
		{ \
			.tBit.mode11 = PARAMSET_ROIC_CFGR_LHB_MCFG_11LHB_IDLE,                \
			.tBit.mode12 = PARAMSET_ROIC_CFGR_LHB_MCFG_12LHB_IDLE,                \
			.tBit.mode13 = PARAMSET_ROIC_CFGR_LHB_MCFG_13LHB_IDLE,                \
			.tBit.mode14 = PARAMSET_ROIC_CFGR_LHB_MCFG_14LHB_IDLE,                \
			.tBit.mode15 = PARAMSET_ROIC_CFGR_LHB_MCFG_15LHB_IDLE,                \
			.tBit.mode16 = PARAMSET_ROIC_CFGR_LHB_MCFG_16LHB_IDLE,                \
			.tBit.mode17 = PARAMSET_ROIC_CFGR_LHB_MCFG_17LHB_IDLE,                \
			.tBit.mode18 = PARAMSET_ROIC_CFGR_LHB_MCFG_18LHB_IDLE,                \
			.tBit.mode19 = PARAMSET_ROIC_CFGR_LHB_MCFG_19LHB_IDLE,                \
			.tBit.mode20 = PARAMSET_ROIC_CFGR_LHB_MCFG_20LHB_IDLE,                \
		}, \
	},\
	.CFGR_FG_LHB_CFG =                       \
		{                                    \
			.tBit.lhbmuxnum = PARAMSET_ROIC_CFGR_FG_LHB_CFG_lhbmuxnum,             \
	},                                       \
	.CFGR_PP_LHB_CFG =                       \
		{                                    \
			.tBit.lhbmuxnum = PARAMSET_ROIC_CFGR_PP_LHB_CFG_lhbmuxnum,             \
			.tBit.pp_mux_cfg0 = PARAMSET_ROIC_CFGR_PP_LHB_CFG_pp_mux_cfg0,           \
			.tBit.pp_mux_cfg1 = PARAMSET_ROIC_CFGR_PP_LHB_CFG_pp_mux_cfg1,           \
			.tBit.pp_mux_cfg2 = PARAMSET_ROIC_CFGR_PP_LHB_CFG_pp_mux_cfg2,           \
			.tBit.pp_mux_cfg3 = PARAMSET_ROIC_CFGR_PP_LHB_CFG_pp_mux_cfg3,           \
			.tBit.pd_tmuxnum = PARAMSET_ROIC_CFGR_PP_LHB_CFG_pd_tmuxnum,            \
	},                                       \
	.CFGR_PD_LHB_CFG =                       \
		{                                    \
			.tBit.lhbmuxnum = PARAMSET_ROIC_CFGR_PD_LHB_CFG_lhbmuxnum,             \
			.tBit.pd_mux_cfg0 = PARAMSET_ROIC_CFGR_PD_LHB_CFG_pd_mux_cfg0,           \
			.tBit.pd_mux_cfg1 = PARAMSET_ROIC_CFGR_PD_LHB_CFG_pd_mux_cfg1,           \
			.tBit.pd_mux_cfg2 = PARAMSET_ROIC_CFGR_PD_LHB_CFG_pd_mux_cfg2,           \
			.tBit.pd_mux_cfg3 = PARAMSET_ROIC_CFGR_PD_LHB_CFG_pd_mux_cfg3,           \
			.tBit.pd_tsync_muxnum = PARAMSET_ROIC_CFGR_PD_LHB_CFG_pd_tsync_muxnum,       \
	},                                       \
	.CFGR_MUX_FCTL_NUM =                     \
		{                                    \
			.tBit.mux_fctl_num1 = 12,        \
			.tBit.mux_fctl_num2 = 4,         \
			.tBit.fctl_rsti_off = 0,         \
			.tBit.mux_off_en = 0,            \
	},                                       \
	.CFGR_UPLINK_MUX0 =                      \
		{                                    \
			.tBit.uplink_mux0 = 0xffffffff,  \
	},                                       \
	.CFGR_UPLINK_MUX1 =                      \
		{                                    \
			.tBit.uplink_mux1 = 0x3fffff,    \
	},                                       \
	.CFGR_ND_PHTCR =                         \
		{                                    \
			.tBit.nd_phtcr_num1 = 0,         \
			.tBit.nd_phtcr_num2 = 0,         \
	},                                       \
	.CFGR_ND_PWM =                           \
		{                                    \
			.tBit.nd_pwm_prd = 0,            \
			.tBit.nd_vcr_num1 = 0,           \
	},                                       \
	.CFGR_ND_PHTH =                          \
		{                                    \
			.tBit.nd_phth0_num1 = 0,         \
			.tBit.nd_phth1_num1 = 0,         \
	},                                       \
	.CFGR_LHB_MUX_CTRL =                     \
		{                                    \
			.tBit.mux_m1_bit_en = 0x3FF,      \
			.tBit.mux_nd_bit_en = 0x3FF,      \
	},                                       \
	.CFGR_PING_MUX_CTRL =                    \
		{                                    \
			.tBit.ping_max = 0,              \
			.tBit.ping_pwm_num = 0,          \
			.tBit.uplink_dc = 0,             \
			.tBit.uplink_float = 0,          \
			.tBit.ping_mux_sel = 0,          \
			.tBit.ping_mode = 0,             \
	},                                       \
	.CFGR_PRE_DRV_CTRL =                     \
		{                                    \
			.tBit.pdrv_mode = 0,             \
			.tBit.pdrv_adc_en = 0,           \
	},                                       \
	.SD_PWRCR1 =                             \
		{                                    \
			.tBit.sd_pwrcr1 = 0,            \
			.tBit.sd_pwrcr2 = 0,             \
			.tBit.sd_pwrcr3 = 0,             \
			.tBit.sd_pwrcr4 = 0,             \
			.tBit.sd_pwrcr5 = 0,             \
	},                                       \
	.SD_PWRCR2 =                             \
		{                                    \
			.tBit.sd_pwrcr6 = 0,             \
			.tBit.sd_pwrcr7 = 0,             \
			.tBit.sd_pwrcr8 = 0,             \
			.tBit.sd_pwrcr9 = 0,             \
			.tBit.sd_pwrcr10 = 0,            \
	},                                       \
	.SD_PWRCR3 =                             \
		{                                    \
			.tBit.sd_pwrcr11 = 0,            \
			.tBit.sd_pwrcr12 = 0,            \
			.tBit.sd_pwrcr13 = 0,            \
			.tBit.sd_pwrcr14 = 0,            \
			.tBit.sd_pwrcr15 = 0,            \
	},                                       \
	.SD_PWRCR4 =                             \
		{                                    \
			.tBit.sd_pwrcr16 = 0,            \
			.tBit.sd_pwrcr17 = 0,            \
			.tBit.sd_pwrcr18 = 0,            \
			.tBit.sd_pwrcr19 = 0,            \
			.tBit.sd_lhbnum = 7,             \
			.tBit.set_sel = 0,               \
			.tBit.roc_en = 0,                \
	},                                       \
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
	.R0_CFGR_TUNE_GROUP =                    \
	{                                    \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_R0_TUNE_GROUP_cr_rg2_sel,/* 2, */ \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_R0_TUNE_GROUP_cr_rg3_sel,/* 28, */ \
	},                                       \
	.CFGR_R0_RAW_CTRL1 =                     \
		{                                    \
			.tBit.r0_a_addr_init = 0,        \
			.tBit.r0_b_addr_init = 14,       \
			.tBit.r0_addr_limit_cnt = 90,    \
			.tBit.r0_addr_int_num = 28,      \
	},                                       \
	.CFGR_R0_RAW_CTRL2 =                     \
		{                                    \
			.tBit.r0_addr_minus_num = 97,    \
			.tBit.r0_addr_last = 104,        \
			.tBit.r0_addr_last_tmp = 126,    \
	},                                       \
	.CFGR_R1_RAW_CTRL1 =                     \
		{                                    \
			.tBit.r1_a_addr_init = 13,       \
			.tBit.r1_b_addr_init = 27,       \
			.tBit.r1_addr_limit_cnt = 97,    \
			.tBit.r1_addr_int_num = 28,      \
	},                                       \
	.CFGR_R1_RAW_CTRL2 =                     \
		{                                    \
			.tBit.r1_addr_minus_num = 99,    \
			.tBit.r1_addr_last = 105,        \
			.tBit.r1_addr_last_tmp = 127,    \
	},                                       \
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
	.R1_CFGR_TUNE_GROUP =                    \
	{                                    \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_R1_TUNE_GROUP_cr_rg2_sel,/* 2, */ \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_R1_TUNE_GROUP_cr_rg3_sel,/* 28, */ \
	},                                       \
	.CFGR_SENSE_CTRL =                       \
		{                                    \
			.tBit.lv_ssu_bcon = PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcon,           \
			.tBit.lv_ssu_bcons = PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcons,          \
			.tBit.hv_ssu_bcon = PARAMSET_ROIC_CFGR_SENSE_CTRL_hv_ssu_bcon,           \
			.tBit.pen_dc_md = PARAMSET_ROIC_CFGR_SENSE_CTRL_pen_dc_md,             \
			.tBit.pen_dc_md_stuck = PARAMSET_ROIC_CFGR_SENSE_CTRL_pen_dc_md_stuck,       \
			.tBit.integ_half_f = PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_f,          \
			.tBit.integ_half_p = PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_p,          \
			.tBit.integ_half_comp = PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_comp,       \
			.tBit.pre_gc_f = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_f,              \
			.tBit.pre_gc_p = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_p,              \
			.tBit.pre_gc_comp = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_comp,           \
			.tBit.int_gc_f = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_f,              \
			.tBit.int_gc_p = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_p,              \
			.tBit.int_gc_comp = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_comp,           \
			.tBit.powsel = PARAMSET_ROIC_CFGR_SENSE_CTRL_powsel,                \
			.tBit.pre_bs_lp = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_bs_lp,             \
			.tBit.int_bs_lp = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_bs_lp,             \
			.tBit.tm_ssu_pen = PARAMSET_ROIC_CFGR_SENSE_CTRL_tm_ssu_pen,            \
	},                                       \
	.CFGR_COMP_ADC_CTRL =                    \
		{                                    \
			.tBit.adc_bcon = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_bcon,              \
			.tBit.adc_stc_insel = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_stc_insel,         \
			.tBit.adc_dsf = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_dsf,               \
			.tBit.adc_ref_sel = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_ref_sel,           \
			.tBit.int_ref = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_int_ref,               \
			.tBit.sha_ref = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_sha_ref,               \
			.tBit.sha_bs_lp = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_sha_bs_lp,             \
			.tBit.ref_res_sel = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_ref_res_sel,           \
			.tBit.lv_comp_bcon = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_lv_comp_bcon,          \
			.tBit.comp_hys_ctrl = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_comp_hys_ctrl,         \
			.tBit.tm_comp = PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_tm_comp,               \
	},                                       \
	.CFGR_SSU_PW_CTRL =                      \
		{                                    \
			.tBit.pdb_hvbias = 1,            \
			.tBit.pdb_hvr = 1,               \
			.tBit.pdb_lvbias = 1,            \
			.tBit.pdb_lvr = 1,               \
			.tBit.pdb_sha = 1,               \
			.tBit.bgr_en = 1,                \
			.tBit.pdb_adc = 1,               \
			.tBit.pdb_compbias = 0,          \
			.tBit.pdb_comp = 0,              \
			.tBit.stuck_hvbias = 2,          \
			.tBit.stuck_hvr = 2,             \
			.tBit.stuck_lvbias = 2,          \
			.tBit.stuck_lvr = 2,             \
			.tBit.stuck_sha = 2,             \
			.tBit.stuck_bgr = 0,             \
			.tBit.stuck_adc = 2,             \
			.tBit.stuck_compbias = 0,        \
			.tBit.stuck_comp = 0,            \
	},                                       \
	.CFGR_TUNE_LOWER =                       \
		{                                    \
		.tBit.lower_mux_num = PARAMSET_ROIC_1stMUX_IDX, \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_1stMUX_TUNE_GROUP_cr_rg2_sel, \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_1stMUX_TUNE_GROUP_cr_rg3_sel, \
	},                                       \
	.CFGR_TUNE_UPPER =                       \
		{                                    \
		.tBit.upper_mux_num = PARAMSET_ROIC_LastMUX_IDX, \
		.tBit.cr_rg2_sel = PARAMSET_ROIC_LastMUX_TUNE_GROUP_cr_rg2_sel, \
		.tBit.cr_rg3_sel = PARAMSET_ROIC_LastMUX_TUNE_GROUP_cr_rg3_sel, \
	},                                       \
	.TAFE_REV_SIG =                          \
		{                                    \
			.tBit.tafe_rev_sig = 204,        \
	},                                       \
	.SYS_DUMMY0 =                            \
		{                                    \
			.tBit.sys_dummy0 = 0x12345678,   \
	},                                       \
	.SYS_DUMMY1 =                            \
		{                                    \
			.tBit.sys_dummy1 = 4294967295,   \
	},                                       \
	.CFGR_COMP_CTRL2 =                       \
		{                                    \
			.tBit.sel_comp_redge = 1,        \
			.tBit.sel_comp_fedge = 1,        \
			.tBit.pdrv_pwm_rdum = 0,         \
			.tBit.pdrv_pwm_fdum = 0,         \
			.tBit.div_opt = 2,               \
			.tBit.comp_pwm_prd = 45,         \
	},                                       \
	.CFGR_COMP_RSTI_NUM =                    \
		{                                    \
			.tBit.comp_rsti_num1 = 22,       \
			.tBit.comp_rsti_num2 = 20,       \
			.tBit.rsti_select = 1,           \
	},                                       \
	.CFGR_COMP_WINDOW_1 =                    \
		{                                    \
			.tBit.comp_rwidth_redge = 57,    \
			.tBit.comp_rwidth_fedge = 0,     \
	},                                       \
	.CFGR_COMP_WINDOW_2 =                    \
		{                                    \
			.tBit.comp_fwidth_redge = 57,    \
			.tBit.comp_fwidth_fedge = 0,     \
	},                                       \
	.COMP_STATUS =                           \
		{                                    \
			.tBit.insert_dly_val = 0,        \
			.tBit.rwidth_rdat = 0,           \
			.tBit.fwidth_rdat = 0,           \
	},                                       \
	.CFGR_SENSE_CTRL_2 =                     \
		{                                    \
			.tBit.cfgr_r0_pre_comp = 0,      \
			.tBit.cfgr_r1_pre_comp = 0,      \
			.tBit.cfgr_r0_pre_ch_con_en = 3, \
			.tBit.cfgr_r1_pre_ch_con_en = 3, \
	},                                       \
	.CFGR_MON_CTRL =                         \
		{                                    \
			.tBit.cfgr_tm0_sum_mon_en = 0,   \
			.tBit.cfgr_tm1_sum_mon_en = 0,   \
			.tBit.cfgr_tm0_ssu_mon = 0,      \
			.tBit.cfgr_tm1_ssu_mon = 0,      \
	},


#define SRIC_Conf_Set		SRIC_WGPPEN_Conf_Set

#endif /* (USED_ROIC_DEF == ROIC_SW98500) */

#endif /* __SW98500_PARAMPRESET_H_ */
