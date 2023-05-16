/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _SW98500_conf.h
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

#ifndef __SW98500_CONF_H_
#define __SW98500_CONF_H_

#if (USED_ROIC_DEF == ROIC_SW98500)

#define SW98500_MODE_FINGER				(0)
#define SW98500_MODE_BEACON				(1)
#define SW98500_MODE_PEN_POS			(2)
#define SW98500_MODE_PEN_TILT			(2)
#define SW98500_MODE_PEN_DATA			(3)
#define SW98500_MODE_NOISE_SCAN			(4)
#define SW98500_MODE_FINGER_VB			(5)
#define SW98500_MODE_DUMMY				(6)

typedef union {
	struct
	{
		__I uint32_t revid : 8;
		__I uint32_t part_num : 24;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PRODUCT_ID_t;

typedef union {
	struct
	{
		__IO uint32_t chksum_opt : 1;
		__IO uint32_t spis_irq_en : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tSPIS_CFG_t;

typedef union {
	struct
	{
		__IO uint32_t spi_chksum_clr : 1;
		__IO uint32_t tsync_fault_clr : 1;
		__IO uint32_t pwm_fault_clr : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tSPIS_ERROR_CLR_t;

typedef union {
	struct
	{
		__IO uint32_t spi_chksum_err : 8;
		__IO uint32_t tsync_fault_err : 1;
		__IO uint32_t pwm_fault_err : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tSPIS_ERROR_ST_t;

typedef union {
	struct
	{
		__IO uint32_t miso_ds : 1;
		__IO uint32_t miso_dout : 1;
		__IO uint32_t miso_func : 4;
		__IO uint32_t mosi_ds : 1;
		__IO uint32_t mosi_dout : 1;
		__IO uint32_t mosi_func : 3;
		__IO uint32_t tattn_out : 1;
		__IO uint32_t tattn_oe : 1;
		__IO uint32_t tattn_ds : 1;
		__IO uint32_t tattn_func : 1;
		__IO uint32_t tattn_sel0 : 1;
		__IO uint32_t tattn_sel1 : 1;
		__IO uint32_t tattn_func2 : 4;
		__IO uint32_t pad_tattn_test : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tSPIS_PAD_CTL_t;

typedef union {
	struct
	{
		__IO uint32_t tg_reset : 1;
		__IO uint32_t sw_reset : 1;
		__IO uint32_t tg_clk_all_on : 1;
		__IO uint32_t buf_clk_on : 1;
		__IO uint32_t cfclk_on : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_SYS_CFG_t;

typedef union {
	struct
	{
		__IO uint32_t tc_start : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_TC_START_t;

typedef union {
	struct
	{
		__IO uint32_t tc_stop : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_TC_STOP_t;

typedef union {
	struct
	{
		__IO uint32_t ch_num : 6;
		__IO uint32_t ch_en_lvr : 7;
		__IO uint32_t ch_en_hvr : 9;
		__IO uint32_t dum_drv_en : 2;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_R0_CH_EN_t;

typedef union {
	struct
	{
		__IO uint32_t ch_num : 6;
		__IO uint32_t ch_en_lvr : 7;
		__IO uint32_t ch_en_hvr : 9;
		__IO uint32_t dum_drv_en : 2;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_R1_CH_EN_t;

typedef union {
	struct
	{
		__IO uint32_t mux_int_en : 4;
		__IO uint32_t mux_num_tot : 4;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_MUX_EN_t;

typedef union {
	struct
	{
		__IO uint32_t mux_dly : 7;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_MUX_DLY_t;

typedef union {
	struct
	{
		__IO uint32_t sd_off : 1;
		__IO uint32_t sd_float : 1;
		__IO uint32_t tsync_in_pol : 1;
		__IO uint32_t pwm_pol : 1;
		__IO uint32_t tsync_out_pol : 1;
		__IO uint32_t tsync_out_bypass : 1;
		__IO uint32_t tsync_out_stuck : 1;
		__IO uint32_t tsync_out_level : 1;
		__IO uint32_t vsync_pol : 1;
		__IO uint32_t vsync_tg_en : 1;
		__IO uint32_t vsync_tg_act : 1;
		__IO uint32_t sd_gnd : 1;
		__IO uint32_t stuck_abd : 1;
		__IO uint32_t cfgr_abd : 1;
		__IO uint32_t cfgr_abd_pol : 1;
		__IO uint32_t cfgr_abd_inv : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_DIC_CFG_t;

typedef union {
	struct
	{
		__IO uint32_t pwm_pdrv_num : 7;
		__IO uint32_t pwm_act_num : 7;
		__IO uint32_t pwm_mgap_num : 7;
		__IO uint32_t pwm_dum_num : 7;
		__IO uint32_t pwm_set_num : 2;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PWM_CTL_t;

typedef union {
	struct
	{
		__IO uint32_t pwm_pdrv_num : 7;
		__IO uint32_t pwm_act_num : 7;
		__IO uint32_t pwm_mgap_num : 7;
		__IO uint32_t pwm_dum_num : 7;
		__IO uint32_t pwm_set_num : 2;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PWM_POS_CTL_t;

typedef union {
	struct
	{
		__IO uint32_t pwm_pdrv_num : 7;
		__IO uint32_t pwm_act_num : 7;
		__IO uint32_t pwm_mgap_num : 7;
		__IO uint32_t pwm_dum_num : 7;
		__IO uint32_t pwm_set_num : 2;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PWM_DAT_CTL_t;

typedef union {
	struct
	{
		__IO uint32_t nd_pwm_act_num : 7;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tND_CTRL_t;

typedef union {
	struct
	{
		__IO uint32_t pwm_prd1 : 12;
		__IO uint32_t pwm_prd2 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PWM_PRD_t;

typedef union {
	struct
	{
		__IO uint32_t smop_prd_1 : 7;
		__IO uint32_t smop_prd_2 : 7;
		__IO uint32_t smop_prd_3 : 7;
		__IO uint32_t crrpt_num : 3;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_SMPL_CTL_t;

typedef union {
	struct
	{
		__IO uint32_t rstp_num1 : 12;
		__IO uint32_t rstp_num2 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_RSTP_NUM1_t;

typedef union {
	struct
	{
		__IO uint32_t phtcr_num1_1 : 12;
		__IO uint32_t phtcr_num1_2 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PHTCR_NUM1_t;

typedef union {
	struct
	{
		__IO uint32_t phtcr_num2_1 : 12;
		__IO uint32_t phtcr_num2_2 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PHTCR_NUM2_t;

typedef union {
	struct
	{
		__IO uint32_t vcr_num1_1 : 12;
		__IO uint32_t vcr_num1_2 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_VCR_NUM1_t;

typedef union {
	struct
	{
		__IO uint32_t rsti_num1 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_RSTI_NUM1_t;

typedef union {
	struct
	{
		__IO uint32_t rsti_num2_1 : 12;
		__IO uint32_t rsti_num2_2 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_RSTI_NUM2_t;

typedef union {
	struct
	{
		__IO uint32_t phth0_num1_1 : 12;
		__IO uint32_t phth0_num1_2 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PHTH0_NUM1_t;

typedef union {
	struct
	{
		__IO uint32_t phth1_num1_1 : 12;
		__IO uint32_t phth1_num1_2 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PHTH1_NUM1_t;

typedef union {
	struct
	{
		__IO uint32_t phth0_num2 : 12;
		__IO uint32_t phth1_num2 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PHTH_NUM2_t;

typedef union {
	struct
	{
		__IO uint32_t pht_prd : 8;
		__IO uint32_t pht_opt_smpl : 1;
		__IO uint32_t pht_opt_inv : 1;
		__IO uint32_t pht_etime : 12;
		__IO uint32_t pht_act_en : 1;
		__IO uint32_t pht_act_pwm_num : 3;
		__IO uint32_t pht_act_pwr_num : 3;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PHT_CTL_t;

typedef union {
	struct
	{
		__IO uint32_t pht_num1 : 12;
		__IO uint32_t pht_num2 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PHT_NUM1_t;

typedef union {
	struct
	{
		__IO uint32_t adc_op_opt : 1;
		__IO uint32_t adc_clk_opt : 2;
		__IO uint32_t adc_clk_pol : 1;
		__IO uint32_t adc_clk_prd : 3;
		__IO uint32_t adc_clk_num : 4;
		__IO uint32_t adc_in_pos : 4;
		__IO uint32_t adc_stc_dly : 5;
		__IO uint32_t adc_clk_spt : 1;
		__IO uint32_t adc_clk_prd_f : 3;
		__IO uint32_t cfgr_tm_adc : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_ADC_CTRL_t;

typedef union {
	struct
	{
		__IO uint32_t display_vcomr : 2;
		__IO uint32_t touch_f_vcomr : 2;
		__IO uint32_t touch_p_vcomr : 2;
		__IO uint32_t stuck_left : 1;
		__IO uint32_t stuck_right : 1;
		__IO uint32_t stuck_level : 1;
		__IO uint32_t tsync_opt : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_VCOMR_OPT_t;

typedef union {
	struct
	{
		__IO uint32_t double_buf_en : 1;
		__IO uint32_t raw_buf_ctl_en : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_BUF_OPT_t;

typedef union {
	struct
	{
		__IO uint32_t stuck_rstp : 2;
		__IO uint32_t stuck_phtcr : 2;
		__IO uint32_t stuck_vcr : 2;
		__IO uint32_t stuck_rsti : 2;
		__IO uint32_t stuck_phth0 : 2;
		__IO uint32_t stuck_phth1 : 2;
		__IO uint32_t stuck_pht0 : 2;
		__IO uint32_t stuck_pht1 : 2;
		__IO uint32_t stuck_vcr_odd_en0 : 1;
		__IO uint32_t stuck_vcr_even_en0 : 1;
		__IO uint32_t stuck_vcr_odd_en1 : 1;
		__IO uint32_t stuck_vcr_even_en1 : 1;
		__IO uint32_t stuck_muxf_en : 1;
		__IO uint32_t stuck_muxs_en : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_TG_STUCK_t;

typedef union {
	struct
	{
		__IO uint32_t adc_in : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_ADC_IN_t;

typedef union {
	struct
	{
		__IO uint32_t mux_s_stuck_val : 6;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_MUX_S_STUCK_VAL_t;

typedef union {
	struct
	{
		__IO uint32_t mux_f_stuck_val : 6;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_MUX_F_STUCK_VAL_t;

typedef union {
	struct
	{
		__IO uint32_t MUX_00 : 4;
		__IO uint32_t MUX_01 : 4;
		__IO uint32_t MUX_02 : 4;
		__IO uint32_t MUX_03 : 4;
		__IO uint32_t MUX_04 : 4;
		__IO uint32_t MUX_05 : 4;
		__IO uint32_t MUX_06 : 4;
		__IO uint32_t MUX_07 : 4;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_MUX_CFG_00_t;

typedef union {
	struct
	{
		__IO uint32_t MUX_08 : 4;
		__IO uint32_t MUX_09 : 4;
		__IO uint32_t MUX_10 : 4;
		__IO uint32_t MUX_11 : 4;
		__IO uint32_t MUX_12 : 4;
		__IO uint32_t MUX_13 : 4;
		__IO uint32_t MUX_14 : 4;
		__IO uint32_t MUX_15 : 4;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_MUX_CFG_01_t;

typedef union {
	struct
	{
		__IO uint32_t mode : 3;
		__IO uint32_t tsync_num : 5;
		__IO uint32_t dum_tsync_num : 4;
		__IO uint32_t beacon_en : 1;
		__IO uint32_t rdcom_en : 1;
		__IO uint32_t sgap_num : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tRCOM_LHB_CFG_t;

typedef union {
	struct
	{
		__IO uint32_t mode01 : 3;
		__IO uint32_t mode02 : 3;
		__IO uint32_t mode03 : 3;
		__IO uint32_t mode04 : 3;
		__IO uint32_t mode05 : 3;
		__IO uint32_t mode06 : 3;
		__IO uint32_t mode07 : 3;
		__IO uint32_t mode08 : 3;
		__IO uint32_t mode09 : 3;
		__IO uint32_t mode10 : 3;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tDEFA_LHB_MCFG00_t;

typedef union {
	struct
	{
		__IO uint32_t mode11 : 3;
		__IO uint32_t mode12 : 3;
		__IO uint32_t mode13 : 3;
		__IO uint32_t mode14 : 3;
		__IO uint32_t mode15 : 3;
		__IO uint32_t mode16 : 3;
		__IO uint32_t mode17 : 3;
		__IO uint32_t mode18 : 3;
		__IO uint32_t mode19 : 3;
		__IO uint32_t mode20 : 3;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tDEFA_LHB_MCFG01_t;

typedef union {
	struct
	{
		__IO uint32_t lhbmuxnum : 4;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_FG_LHB_CFG_t;

typedef union {
	struct
	{
		__IO uint32_t lhbmuxnum : 4;
		__IO uint32_t pp_mux_cfg0 : 6;
		__IO uint32_t pp_mux_cfg1 : 6;
		__IO uint32_t pp_mux_cfg2 : 6;
		__IO uint32_t pp_mux_cfg3 : 6;
		__IO uint32_t pd_tmuxnum : 4;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PP_LHB_CFG_t;

typedef union {
	struct
	{
		__IO uint32_t lhbmuxnum : 4;
		__IO uint32_t pd_mux_cfg0 : 6;
		__IO uint32_t pd_mux_cfg1 : 6;
		__IO uint32_t pd_mux_cfg2 : 6;
		__IO uint32_t pd_mux_cfg3 : 6;
		__IO uint32_t pd_tsync_muxnum : 4;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PD_LHB_CFG_t;

typedef union {
	struct
	{
		__IO uint32_t mux_fctl_num1 : 12;
		__IO uint32_t mux_fctl_num2 : 12;
		__IO uint32_t fctl_rsti_off : 1;
		__IO uint32_t mux_off_en : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_MUX_FCTL_NUM_t;

typedef union {
	struct
	{
		__IO uint32_t uplink_mux0 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_UPLINK_MUX0_t;

typedef union {
	struct
	{
		__IO uint32_t uplink_mux1 : 22;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_UPLINK_MUX1_t;

typedef union {
	struct
	{
		__IO uint32_t nd_phtcr_num1 : 12;
		__IO uint32_t nd_phtcr_num2 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_ND_PHTCR_t;

typedef union {
	struct
	{
		__IO uint32_t nd_pwm_prd : 12;
		__IO uint32_t nd_vcr_num1 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_ND_PWM_t;

typedef union {
	struct
	{
		__IO uint32_t nd_phth0_num1 : 12;
		__IO uint32_t nd_phth1_num1 : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_ND_PHTH_t;

typedef union {
	struct
	{
		__IO uint32_t reserved53 : 30;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tReserved53_t;

typedef union {
	struct
	{
		__IO uint32_t reserved54 : 30;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tReserved54_t;

typedef union {
	struct
	{
		__IO uint32_t reserved55 : 30;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tReserved55_t;

typedef union {
	struct
	{
		__IO uint32_t reserved56 : 30;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tReserved56_t;

typedef union {
	struct
	{
		__IO uint32_t mux_m1_bit_en : 10;
		__IO uint32_t mux_nd_bit_en : 10;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_LHB_MUX_CTRL_t;

typedef union {
	struct
	{
		__IO uint32_t ping_max : 12;
		__IO uint32_t ping_pwm_num : 7;
		__IO uint32_t uplink_dc : 1;
		__IO uint32_t uplink_float : 1;
		__IO uint32_t ping_mux_sel : 1;
		__IO uint32_t ping_mode : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PING_MUX_CTRL_t;

typedef union {
	struct
	{
		__IO uint32_t pdrv_mode : 1;
		__IO uint32_t pdrv_adc_en : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_PRE_DRV_CTRL_t;

typedef union {
	struct
	{
		__IO uint32_t reserved57 : 30;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tReserved57_t;

typedef union {
	struct
	{
		__IO uint32_t reserved58 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tReserved58_t;

typedef union {
	struct
	{
		__IO uint32_t sd_pwrcr1 : 6;
		__IO uint32_t sd_pwrcr2 : 6;
		__IO uint32_t sd_pwrcr3 : 6;
		__IO uint32_t sd_pwrcr4 : 6;
		__IO uint32_t sd_pwrcr5 : 6;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tSD_PWRCR1_t;

typedef union {
	struct
	{
		__IO uint32_t sd_pwrcr6 : 6;
		__IO uint32_t sd_pwrcr7 : 6;
		__IO uint32_t sd_pwrcr8 : 6;
		__IO uint32_t sd_pwrcr9 : 6;
		__IO uint32_t sd_pwrcr10 : 6;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tSD_PWRCR2_t;

typedef union {
	struct
	{
		__IO uint32_t sd_pwrcr11 : 6;
		__IO uint32_t sd_pwrcr12 : 6;
		__IO uint32_t sd_pwrcr13 : 6;
		__IO uint32_t sd_pwrcr14 : 6;
		__IO uint32_t sd_pwrcr15 : 6;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tSD_PWRCR3_t;

typedef union {
	struct
	{
		__IO uint32_t sd_pwrcr16 : 6;
		__IO uint32_t sd_pwrcr17 : 6;
		__IO uint32_t sd_pwrcr18 : 6;
		__IO uint32_t sd_pwrcr19 : 6;
		__IO uint32_t sd_lhbnum : 5;
		__IO uint32_t set_sel : 1;
		__IO uint32_t roc_en : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tSD_PWRCR4_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_r1g1 : 5;
		__IO uint32_t cr1_r1g2 : 5;
		__IO uint32_t cr1_r1g3 : 5;
		__IO uint32_t cr1_r2g1 : 5;
		__IO uint32_t cr1_r2g2 : 5;
		__IO uint32_t cr1_r2g3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX1_1_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_r3g1 : 5;
		__IO uint32_t cr1_r3g2 : 5;
		__IO uint32_t cr1_r3g3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX1_2_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX2_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX3_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX4_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX5_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX6_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX7_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX8_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX9_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_r1g1 : 5;
		__IO uint32_t cr1_r1g2 : 5;
		__IO uint32_t cr1_r1g3 : 5;
		__IO uint32_t cr1_r2g1 : 5;
		__IO uint32_t cr1_r2g2 : 5;
		__IO uint32_t cr1_r2g3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX10_1_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_r3g1 : 5;
		__IO uint32_t cr1_r3g2 : 5;
		__IO uint32_t cr1_r3g3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR1_MUX10_2_t;

typedef union {
	struct
	{
		__IO uint32_t cr_fg_gtune : 2;
		__IO uint32_t cr_pn_gtune : 2;
		__IO uint32_t cr_pd_gtune : 2;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CR_GTUNE_t;

typedef union {
	struct
	{
		__IO uint32_t cr_rg2_sel : 5;
		__IO uint32_t cr_rg3_sel : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR0_CFGR_TUNE_GROUP_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_00 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_00_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_01 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_01_t;

typedef union {
	struct
	{
		__IO uint32_t r0_a_addr_init : 8;
		__IO uint32_t r0_b_addr_init : 8;
		__IO uint32_t r0_addr_limit_cnt : 8;
		__IO uint32_t r0_addr_int_num : 8;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_R0_RAW_CTRL1_t;

typedef union {
	struct
	{
		__IO uint32_t r0_addr_minus_num : 8;
		__IO uint32_t r0_addr_last : 8;
		__IO uint32_t r0_addr_last_tmp : 8;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_R0_RAW_CTRL2_t;

typedef union {
	struct
	{
		__IO uint32_t r1_a_addr_init : 8;
		__IO uint32_t r1_b_addr_init : 8;
		__IO uint32_t r1_addr_limit_cnt : 8;
		__IO uint32_t r1_addr_int_num : 8;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_R1_RAW_CTRL1_t;

typedef union {
	struct
	{
		__IO uint32_t r1_addr_minus_num : 8;
		__IO uint32_t r1_addr_last : 8;
		__IO uint32_t r1_addr_last_tmp : 8;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_R1_RAW_CTRL2_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_07 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_07_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_08 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_08_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_09 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_09_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_10 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_10_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_11 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_11_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_12 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_12_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_13 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_13_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_14 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_14_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_15 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_15_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_16 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_16_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_17 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_17_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_l_reserved_18 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_L_Reserved_18_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_r1g1 : 5;
		__IO uint32_t cr1_r1g2 : 5;
		__IO uint32_t cr1_r1g3 : 5;
		__IO uint32_t cr1_r2g1 : 5;
		__IO uint32_t cr1_r2g2 : 5;
		__IO uint32_t cr1_r2g3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX1_1_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_r3g1 : 5;
		__IO uint32_t cr1_r3g2 : 5;
		__IO uint32_t cr1_r3g3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX1_2_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX2_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX3_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX4_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX5_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX6_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX7_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX8_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_rg1 : 5;
		__IO uint32_t cr1_rg2 : 5;
		__IO uint32_t cr1_rg3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX9_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_r1g1 : 5;
		__IO uint32_t cr1_r1g2 : 5;
		__IO uint32_t cr1_r1g3 : 5;
		__IO uint32_t cr1_r2g1 : 5;
		__IO uint32_t cr1_r2g2 : 5;
		__IO uint32_t cr1_r2g3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX10_1_t;

typedef union {
	struct
	{
		__IO uint32_t cr1_r3g1 : 5;
		__IO uint32_t cr1_r3g2 : 5;
		__IO uint32_t cr1_r3g3 : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR1_MUX10_2_t;

typedef union {
	struct
	{
		__IO uint32_t cr_fg_gtune : 2;
		__IO uint32_t cr_pn_gtune : 2;
		__IO uint32_t cr_pd_gtune : 2;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CR_GTUNE_t;

typedef union {
	struct
	{
		__IO uint32_t cr_rg2_sel : 5;
		__IO uint32_t cr_rg3_sel : 5;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tR1_CFGR_TUNE_GROUP_t;

typedef union {
	struct
	{
		__IO uint32_t lv_ssu_bcon : 3;
		__IO uint32_t lv_ssu_bcons : 3;
		__IO uint32_t hv_ssu_bcon : 3;
		__IO uint32_t pen_dc_md : 2;
		__IO uint32_t pen_dc_md_stuck : 2;
		__IO uint32_t integ_half_f: 1;
		__IO uint32_t integ_half_p: 1;
		__IO uint32_t integ_half_comp: 1;
		__IO uint32_t pre_gc_f: 2;
		__IO uint32_t pre_gc_p: 2;
		__IO uint32_t pre_gc_comp: 2;
		__IO uint32_t int_gc_f: 2;
		__IO uint32_t int_gc_p: 2;
		__IO uint32_t int_gc_comp:2;
		__IO uint32_t powsel : 1;
		__IO uint32_t pre_bs_lp : 1;
		__IO uint32_t int_bs_lp : 1;
		__IO uint32_t tm_ssu_pen : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_SENSE_CTRL_t;

typedef union {
	struct
	{
		__IO uint32_t adc_bcon : 2;
		__IO uint32_t adc_stc_insel : 1;
		__IO uint32_t adc_dsf : 1;
		__IO uint32_t adc_ref_sel : 2;
		__IO uint32_t int_ref : 3;
		__IO uint32_t sha_ref : 3;
		__IO uint32_t sha_bs_lp : 1;
		__IO uint32_t ref_res_sel : 1;
		__IO uint32_t lv_comp_bcon : 1;
		__IO uint32_t comp_hys_ctrl : 4;
		__IO uint32_t tm_comp : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_COMP_ADC_CTRL_t;

typedef union {
	struct
	{
		__IO uint32_t pdb_hvbias : 1;
		__IO uint32_t pdb_hvr : 1;
		__IO uint32_t pdb_lvbias : 1;
		__IO uint32_t pdb_lvr : 1;
		__IO uint32_t pdb_sha : 1;
		__IO uint32_t bgr_en : 1;
		__IO uint32_t pdb_adc : 1;
		__IO uint32_t pdb_compbias : 1;
		__IO uint32_t pdb_comp : 1;
		__IO uint32_t stuck_hvbias : 2;
		__IO uint32_t stuck_hvr : 2;
		__IO uint32_t stuck_lvbias : 2;
		__IO uint32_t stuck_lvr : 2;
		__IO uint32_t stuck_sha : 2;
		__IO uint32_t stuck_bgr : 2;
		__IO uint32_t stuck_adc : 2;
		__IO uint32_t stuck_compbias : 2;
		__IO uint32_t stuck_comp : 2;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_SSU_PW_CTRL_t;

typedef union {
	struct
	{
		__IO uint32_t lower_mux_num : 4;
		__IO uint32_t cr_rg2_sel : 9;
		__IO uint32_t cr_rg3_sel : 9;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_TUNE_LOWER_t;

typedef union {
	struct
	{
		__IO uint32_t upper_mux_num : 4;
		__IO uint32_t cr_rg2_sel : 9;
		__IO uint32_t cr_rg3_sel : 9;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_TUNE_UPPER_t;

typedef union {
	struct
	{
		__IO uint32_t tafe_rev_sig : 8;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tTAFE_REV_SIG_t;

typedef union {
	struct
	{
		__IO uint32_t sys_dummy0 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tSYS_DUMMY0_t;

typedef union {
	struct
	{
		__IO uint32_t sys_dummy1 : 32;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tSYS_DUMMY1_t;

typedef union {
	struct
	{
		__IO uint32_t sel_offset : 1;
		__IO uint32_t comp_err_chk_en : 1;
		__IO uint32_t sel_opcnt : 1;
		__IO uint32_t err_sel_val : 1;
		__IO uint32_t insert_dly_val : 1;
		__IO uint32_t sel_rw_width : 2;
		__IO uint32_t pwm_int_offset : 10;
		__IO uint32_t max_insert_dly : 8;
		__IO uint32_t cfgr_mon_en : 7;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_COMP_CTRL_t;

typedef union {
	struct
	{
		__IO uint32_t sel_comp_redge : 2;
		__IO uint32_t sel_comp_fedge : 2;
		__IO uint32_t pdrv_pwm_rdum : 4;
		__IO uint32_t pdrv_pwm_fdum : 4;
		__IO uint32_t div_opt : 4;
		__IO uint32_t comp_pwm_prd : 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_COMP_CTRL2_t;

typedef union {
	struct
	{
		__IO uint32_t comp_rsti_num1 : 8;
		__IO uint32_t comp_rsti_num2 : 8;
		__IO uint32_t rsti_select : 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_COMP_RSTI_NUM_t;
typedef union {
	struct
	{
		__IO uint32_t comp_rwidth_redge : 8;
		__IO uint32_t comp_rwidth_fedge : 8;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_COMP_WINDOW_1_t;

typedef union {
	struct
	{
		__IO uint32_t comp_fwidth_redge : 8;
		__IO uint32_t comp_fwidth_fedge : 8;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_COMP_WINDOW_2_t;

typedef union {
	struct
	{
		__IO uint32_t insert_dly_val : 8;
		__IO uint32_t rwidth_rdat : 8;
		__IO uint32_t fwidth_rdat : 8;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCOMP_STATUS_t;

typedef union {
	struct
	{
		__IO uint32_t cfgr_r0_pre_comp : 3;
		__IO uint32_t cfgr_r1_pre_comp : 3;
		__IO uint32_t cfgr_r0_pre_ch_con_en : 3;
		__IO uint32_t cfgr_r1_pre_ch_con_en : 3;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_SENSE_CTRL_2_t;

typedef union {
	struct
	{
		__IO uint32_t cfgr_tm0_sum_mon_en : 1;
		__IO uint32_t cfgr_tm1_sum_mon_en : 1;
		__IO uint32_t cfgr_tm0_ssu_mon : 3;
		__IO uint32_t cfgr_tm1_ssu_mon : 3;
	} __PACKED tBit;
	__IO uint32_t ulBulk;
} __PACKED tCFGR_MON_CTRL_t;

typedef struct
{
//	tCFGR_PRODUCT_ID_t CFGR_PRODUCT_ID;			  		// 0x0000(0)	R  	 Default Val:0x0985_0000
	tSPIS_CFG_t SPIS_CFG;						  		// 0x0004(1)	R/W  Default Val:0x0000_0003
	tSPIS_ERROR_CLR_t SPIS_ERROR_CLR;			  		// 0x0008(2)	R/W  Default Val:0x0000_0000
	tSPIS_ERROR_ST_t SPIS_ERROR_ST;				  		// 0x000C(3)	R    Default Val:0x0000_0000
	tSPIS_PAD_CTL_t SPIS_PAD_CTL;				  		// 0x0010(4)	R/W  Default Val:0x0001_1041
	tCFGR_SYS_CFG_t CFGR_SYS_CFG;				  		// 0x0014(5)	R/W  Default Val:0x0000_000C
	tCFGR_TC_START_t CFGR_TC_START;				  		// 0x0018(6)	R/W  Default Val:0x0000_0000
	tCFGR_TC_STOP_t CFGR_TC_STOP;				  		// 0x001C(7)	R/W  Default Val:0x0000_0000
	tCFGR_R0_CH_EN_t CFGR_R0_CH_EN;				  		// 0x0020(8)	R/W  Default Val:0x003F_FFD2
	tCFGR_R1_CH_EN_t CFGR_R1_CH_EN;				  		// 0x0024(9)	R/W  Default Val:0x003F_FFD2
	tCFGR_MUX_EN_t CFGR_MUX_EN;					  		// 0x0028(10)	R/W  Default Val:0x0000_0000
	tCFGR_MUX_DLY_t CFGR_MUX_DLY;				  		// 0x002C(11)	R/W  Default Val:0x0000_0000
	tCFGR_DIC_CFG_t CFGR_DIC_CFG;				  		// 0x0030(12)	R/W  Default Val:0x0000_4020
	tCFGR_PWM_CTL_t CFGR_PWM_CTL;				  		// 0x0034(13)	R/W  Default Val:0x0001_8307
	tCFGR_PWM_POS_CTL_t CFGR_PWM_POS_CTL;		  		// 0x0038(14)	R/W  Default Val:0x0001_8307
	tCFGR_PWM_DAT_CTL_t CFGR_PWM_DAT_CTL;		  		// 0x003C(15)	R/W  Default Val:0x0001_8307
	tND_CTRL_t ND_CTRL;							  		// 0x0040(16)	R/W  Default Val:0x0000_0007
	tCFGR_PWM_PRD_t CFGR_PWM_PRD;				  		// 0x0044(17)	R/W  Default Val:0x0007_3073
	tCFGR_SMPL_CTL_t CFGR_SMPL_CTL;				  		// 0x0048(18)	R/W  Default Val:0x0000_4387
	tCFGR_RSTP_NUM1_t CFGR_RSTP_NUM1;			  		// 0x004C(19)	R/W  Default Val:0x0000_300E
	tCFGR_PHTCR_NUM1_t CFGR_PHTCR_NUM1;			  		// 0x0050(20)	R/W  Default Val:0x0005_E05E
	tCFGR_PHTCR_NUM2_t CFGR_PHTCR_NUM2;			  		// 0x0054(21)	R/W  Default Val:0x0001_E01E
	tCFGR_VCR_NUM1_t CFGR_VCR_NUM1;				  		// 0x0058(22)	R/W  Default Val:0x0005_1051
	tCFGR_RSTI_NUM1_t CFGR_RSTI_NUM1;			  		// 0x005C(23)	R/W  Default Val:0x0000_0035
	tCFGR_RSTI_NUM2_t CFGR_RSTI_NUM2;			  		// 0x0060(24)	R/W  Default Val:0x0001_B01B
	tCFGR_PHTH0_NUM1_t CFGR_PHTH0_NUM1;			  		// 0x0064(25)	R/W  Default Val:0x0001_0010
	tCFGR_PHTH1_NUM1_t CFGR_PHTH1_NUM1;			  		// 0x0068(26)	R/W  Default Val:0x0001_0010
	tCFGR_PHTH_NUM2_t CFGR_PHTH_NUM2;			  		// 0x006C(27)	R/W  Default Val:0x0004_E002
	tCFGR_PHT_CTL_t CFGR_PHT_CTL;				  		// 0x0070(28)	R/W  Default Val:0x0040_5206
	tCFGR_PHT_NUM1_t CFGR_PHT_NUM1;				  		// 0x0074(29)	R/W  Default Val:0x0001_102A
	tCFGR_ADC_CTRL_t CFGR_ADC_CTRL;				  		// 0x0078(30)	R/W  Default Val:0x000F_9394
	tCFGR_VCOMR_OPT_t CFGR_VCOMR_OPT;			  		// 0x007C(31)	R/W  Default Val:0x0000_0000
	tCFGR_BUF_OPT_t CFGR_BUF_OPT;				  		// 0x0080(32)	R/W  Default Val:0x0000_0001
	tCFGR_TG_STUCK_t CFGR_TG_STUCK;				  		// 0x0084(33)	R/W  Default Val:0x0000_0000
	tCFGR_ADC_IN_t CFGR_ADC_IN;					  		// 0x0088(34)	R/W  Default Val:0x0000_0000
	tCFGR_MUX_S_STUCK_VAL_t CFGR_MUX_S_STUCK_VAL; 		// 0x008C(35)	R/W  Default Val:0x0000_0000
	tCFGR_MUX_F_STUCK_VAL_t CFGR_MUX_F_STUCK_VAL; 		// 0x0090(36)	R/W  Default Val:0x0000_0000
	tCFGR_MUX_CFG_00_t CFGR_MUX_CFG_00;			  		// 0x0094(37)	R/W  Default Val:0x8765_4321
	tCFGR_MUX_CFG_01_t CFGR_MUX_CFG_01;			  		// 0x0098(38)	R/W  Default Val:0x0FED_CBA9
	tRCOM_LHB_CFG_t RCOM_LHB_CFG;				  		// 0x009C(39)	R/W  Default Val:0x0000_0000
	tDEFA_LHB_MCFG00_t DEFA_LHB_MCFG00[3];			  		// 0x00A0(40)	R/W  Default Val:0x0000_0000
	tDEFA_LHB_MCFG01_t DEFA_LHB_MCFG01[3];			  		// 0x00A4(41)	R/W  Default Val:0x0000_0000
	tCFGR_FG_LHB_CFG_t CFGR_FG_LHB_CFG;			  		// 0x00A8(42)	R/W  Default Val:0x0000_0000
	tCFGR_PP_LHB_CFG_t CFGR_PP_LHB_CFG;			  		// 0x00AC(43)	R/W  Default Val:0x0000_0000
	tCFGR_PD_LHB_CFG_t CFGR_PD_LHB_CFG;			  		// 0x00B0(44)	R/W  Default Val:0x0000_0000
	tCFGR_MUX_FCTL_NUM_t CFGR_MUX_FCTL_NUM;		  		// 0x00B4(45)	R/W  Default Val:0x0000_0000
	tCFGR_UPLINK_MUX0_t CFGR_UPLINK_MUX0;		  		// 0x00B8(46)	R/W  Default Val:0x0000_0000
	tCFGR_UPLINK_MUX1_t CFGR_UPLINK_MUX1;		  		// 0x00BC(47)	R/W  Default Val:0x0000_0000
	tCFGR_ND_PHTCR_t CFGR_ND_PHTCR;				  		// 0x00C0(48)	R/W  Default Val:0x0000_0000
	tCFGR_ND_PWM_t CFGR_ND_PWM;					  		// 0x00C4(49)	R/W  Default Val:0x0000_0000
	tCFGR_ND_PHTH_t CFGR_ND_PHTH;				  		// 0x00C8(50)	R/W  Default Val:0x0000_0000
//	tReserved53_t Reserved53;					  		// 0x00CC(51)	R/W  Default Val:0x0000_0000
//	tReserved54_t Reserved54;					  		// 0x00D0(52)	R/W  Default Val:0x0000_0000
//	tReserved55_t Reserved55;					  		// 0x00D4(53)	R/W  Default Val:0x0000_0000
//	tReserved56_t Reserved56;					  		// 0x00D8(54)	R/W  Default Val:0x0000_0000
	tCFGR_LHB_MUX_CTRL_t CFGR_LHB_MUX_CTRL;		  		// 0x00DC(55)	R/W  Default Val:0x000F_FFFF
	tCFGR_PING_MUX_CTRL_t CFGR_PING_MUX_CTRL;	  		// 0x00E0(56)	R/W  Default Val:0x0000_0000
	tCFGR_PRE_DRV_CTRL_t CFGR_PRE_DRV_CTRL;		  		// 0x00E4(57)	R/W  Default Val:0x0000_0000
//	tReserved57_t Reserved57;					  		// 0x00E8(58)	R/W  Default Val:0x0000_0000
//	tReserved58_t Reserved58;					  		// 0x00EC(59)	R/W  Default Val:0x0000_0000
	tSD_PWRCR1_t SD_PWRCR1;						  		// 0x00F0(60)	R/W  Default Val:0x0000_000F
	tSD_PWRCR2_t SD_PWRCR2;						  		// 0x00F4(61)	R/W  Default Val:0x0000_0000
	tSD_PWRCR3_t SD_PWRCR3;						  		// 0x00F8(62)	R/W  Default Val:0x0000_0000
	tSD_PWRCR4_t SD_PWRCR4;						  		// 0x00FC(63)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX1_1_t R0_CR1_MUX1_1[6];					  		// 0x0100(64)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX1_2_t R0_CR1_MUX1_2[6];				  		// 0x0104(65)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX2_t R0_CR1_MUX2[6];					  		// 0x0108(66)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX3_t R0_CR1_MUX3[6];					  		// 0x010C(67)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX4_t R0_CR1_MUX4[6];					  		// 0x0110(68)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX5_t R0_CR1_MUX5[6];					  		// 0x0114(69)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX6_t R0_CR1_MUX6[6];					  		// 0x0118(70)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX7_t R0_CR1_MUX7[6];					  		// 0x011C(71)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX8_t R0_CR1_MUX8[6];					  		// 0x0120(72)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX9_t R0_CR1_MUX9[6];					  		// 0x0124(73)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX10_1_t R0_CR1_MUX10_1[6];			  		// 0x0128(74)	R/W  Default Val:0x0000_0000
	tR0_CR1_MUX10_2_t R0_CR1_MUX10_2[6];			  		// 0x012C(75)	R/W  Default Val:0x0000_0000
	tR0_CR_GTUNE_t R0_CR_GTUNE[6];					  		// 0x0130(76)	R/W  Default Val:0x0000_0000
	tR0_CFGR_TUNE_GROUP_t R0_CFGR_TUNE_GROUP;	  		// 0x0134(77)	R/W  Default Val:0x0000_0382
//	tTAFE_L_Reserved_00_t TAFE_L_Reserved_00;	  		// 0x0138(78)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_01_t TAFE_L_Reserved_01;	  		// 0x013C(79)	R/W  Default Val:0x0000_0000
	tCFGR_R0_RAW_CTRL1_t CFGR_R0_RAW_CTRL1;		  		// 0x0140(80)	R/W  Default Val:0x1C5A_0E00
	tCFGR_R0_RAW_CTRL2_t CFGR_R0_RAW_CTRL2;		  		// 0x0144(81)	R/W  Default Val:0x007E_6861
	tCFGR_R1_RAW_CTRL1_t CFGR_R1_RAW_CTRL1;		  		// 0x0148(82)	R/W  Default Val:0x1C61_1B0D
	tCFGR_R1_RAW_CTRL2_t CFGR_R1_RAW_CTRL2;		  		// 0x014C(83)	R/W  Default Val:0x007F_6963
//	tTAFE_L_Reserved_07_t TAFE_L_Reserved_07;	  		// 0x0150(84)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_08_t TAFE_L_Reserved_08;	  		// 0x0154(85)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_09_t TAFE_L_Reserved_09;	  		// 0x0158(86)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_10_t TAFE_L_Reserved_10;	  		// 0x015C(87)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_11_t TAFE_L_Reserved_11;	  		// 0x0160(88)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_12_t TAFE_L_Reserved_12;	  		// 0x0164(89)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_13_t TAFE_L_Reserved_13;	  		// 0x0168(90)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_14_t TAFE_L_Reserved_14;	  		// 0x016C(91)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_15_t TAFE_L_Reserved_15;	  		// 0x0170(92)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_16_t TAFE_L_Reserved_16;	  		// 0x0174(93)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_17_t TAFE_L_Reserved_17;	  		// 0x0178(94)	R/W  Default Val:0x0000_0000
//	tTAFE_L_Reserved_18_t TAFE_L_Reserved_18;	  		// 0x017C(95)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX1_1_t R1_CR1_MUX1_1[6];				  		// 0x0180(96)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX1_2_t R1_CR1_MUX1_2[6];				  		// 0x0184(97)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX2_t R1_CR1_MUX2[6];					  		// 0x0188(98)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX3_t R1_CR1_MUX3[6];					  		// 0x018C(99)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX4_t R1_CR1_MUX4[6];					  		// 0x0190(100)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX5_t R1_CR1_MUX5[6];					  		// 0x0194(101)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX6_t R1_CR1_MUX6[6];					  		// 0x0198(102)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX7_t R1_CR1_MUX7[6];					  		// 0x019C(103)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX8_t R1_CR1_MUX8[6];					  		// 0x01A0(104)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX9_t R1_CR1_MUX9[6];					  		// 0x01A4(105)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX10_1_t R1_CR1_MUX10_1[6];			  		// 0x01A8(106)	R/W  Default Val:0x0000_0000
	tR1_CR1_MUX10_2_t R1_CR1_MUX10_2[6];			  		// 0x01AC(107)	R/W  Default Val:0x0000_0000
	tR1_CR_GTUNE_t R1_CR_GTUNE[6];					  		// 0x01B0(108)	R/W  Default Val:0x0000_0000
	tR1_CFGR_TUNE_GROUP_t R1_CFGR_TUNE_GROUP;	  		// 0x01B4(109)	R/W  Default Val:0x0000_0382
	tCFGR_SENSE_CTRL_t CFGR_SENSE_CTRL;			  		// 0x01B8(110)	R/W  Default Val:0x0FEA_E0DB
	tCFGR_COMP_ADC_CTRL_t CFGR_COMP_ADC_CTRL;	  		// 0x01BC(111)	R/W  Default Val:0x0000_0481
	tCFGR_SSU_PW_CTRL_t CFGR_SSU_PW_CTRL;		  		// 0x01C0(112)	R/W  Default Val:0x0000_0000
	tCFGR_TUNE_LOWER_t CFGR_TUNE_LOWER;			  		// 0x01C4(113)	R/W  Default Val:0x0000_3820
	tCFGR_TUNE_UPPER_t CFGR_TUNE_UPPER;			  		// 0x01C8(114)	R/W  Default Val:0x0000_3829
	tTAFE_REV_SIG_t TAFE_REV_SIG;				  		// 0x01CC(115)	R/W  Default Val:0x0000_00CC
	tSYS_DUMMY0_t SYS_DUMMY0;					  		// 0x01D0(116)	R/W  Default Val:0x0000_0000
	tSYS_DUMMY1_t SYS_DUMMY1;					  		// 0x01D4(117)	R/W  Default Val:0xFFFF_FFFF
	tCFGR_COMP_CTRL_t CFGR_COMP_CTRL;			  		// 0x01D8(118)	R/W  Default Val:0x00C8_0000
	tCFGR_COMP_CTRL2_t CFGR_COMP_CTRL2;			  		// 0x01DC(119)	R/W  Default Val:0x002D_2005
	tCFGR_COMP_RSTI_NUM_t CFGR_COMP_RSTI_NUM;	  		// 0x01E0(120)	R/W  Default Val:0x0001_1416
	tCFGR_COMP_WINDOW_1_t CFGR_COMP_WINDOW_1;	  		// 0x01E4(121)	R/W  Default Val:0x0000_0039
	tCFGR_COMP_WINDOW_2_t CFGR_COMP_WINDOW_2;	  		// 0x01E8(122)	R/W  Default Val:0x0000_0039
	tCOMP_STATUS_t COMP_STATUS;					  		// 0x01EC(123)	R    Default Val:0x0000_0000
	tCFGR_SENSE_CTRL_2_t CFGR_SENSE_CTRL_2;		  		// 0x01F0(124)	R/W  Default Val:0x0000_0000
	tCFGR_MON_CTRL_t CFGR_MON_CTRL;				  		// 0x01F4(125)	R/W  Default Val:0x0000_0000
} __PACKED tModuleSRICCommonConf_t;

#include "_sw98500_parampreset.h"

#endif /* (USED_ROIC_DEF == ROIC_SW98500) */

#endif /* __SW98500_CONF_H_ */
