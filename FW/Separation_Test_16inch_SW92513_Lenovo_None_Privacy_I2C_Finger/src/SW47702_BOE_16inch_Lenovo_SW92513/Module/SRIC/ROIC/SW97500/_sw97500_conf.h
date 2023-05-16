/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _sw97500_conf.h
 * created on : 20. 2. 2019
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

#ifndef __SW97500_CONF_H_
#define __SW97500_CONF_H_


#if (USED_ROIC_DEF == ROIC_SW97500)

typedef union
{
	struct
	{
		__IO uint32_t revid					: 8;
		__IO uint32_t part_num				: 24;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_PRODUCT_ID_t;

typedef union
{
	struct
	{
		__IO uint32_t spis_irq_en 			: 1;
		__IO uint32_t miso_func				: 4;
	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_SPIS_CFG_t;

typedef union
{
	struct
	{
		__IO uint32_t spi_chksum_clr		: 1;
		__IO uint32_t tsync_fault_clr		: 1;
		__IO uint32_t pwm_fault_clr			: 1;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_SPIS_ERROR_CLR_t;

typedef union
{
	struct
	{
		__IO uint32_t spi_chksum_err 		: 1;
		__IO uint32_t tsync_fault_err		: 1;
		__IO uint32_t pwm_fault_err			: 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_SPIS_ERROR_ST_t;

typedef union
{
	struct
	{
		__IO uint32_t tg_reset 				: 1;
		__IO uint32_t sw_reset 				: 1;
		__IO uint32_t tg_clk_all_on 		: 1;
		__IO uint32_t buf_clk_on			: 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_SYS_CFG_t;

typedef union
{
	struct
	{
		__IO uint32_t tc_start				: 1;
		__IO uint32_t scan_cont				: 1;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_TC_START_t;

typedef union
{
	struct
	{
		__IO uint32_t tc_stop				: 1;
	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_TC_STOP_t;

typedef union
{
	struct
	{
		__IO uint32_t ch_num				: 6;
		__IO uint32_t ch_en_lvr				: 5;
		__IO uint32_t reserve0				: 5;
		__IO uint32_t ch_en_hvr				: 7;
		__IO uint32_t reserve1				: 5;
		__IO uint32_t dum_drv_en			: 2;
		__IO uint32_t stuck_lvr_en			: 1;
		__IO uint32_t stuck_hvr_en			: 1;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_CH_EN_t;

typedef union
{
	struct
	{
		__IO uint32_t mux_bit_en			: 15;
		__IO uint32_t mux_int_en			: 3;
		__IO uint32_t mux_num_tot			: 4;
		__IO uint32_t mux_num_tsync			: 4;
		__IO uint32_t m1_mux_en				: 1;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_MUX_EN_t;

typedef union
{
	struct
	{
		__IO uint32_t sd_off				: 1;
		__IO uint32_t sd_float				: 1;
		__IO uint32_t tsync_in_pol			: 1;
		__IO uint32_t pwm_pol				: 1;
		__IO uint32_t tsync_out_pol			: 1;
		__IO uint32_t tsync_out_bypass		: 1;
		__IO uint32_t tsync_out_stuck		: 1;
		__IO uint32_t tsync_out_level		: 1;
		__IO uint32_t vsync_pol				: 1;
		__IO uint32_t vsync_tg_en			: 1;
		__IO uint32_t vsync_tg_act			: 1;
		__IO uint32_t stuck_abd				: 1;
		__IO uint32_t cfgr_abd				: 1;
		__IO uint32_t cfgr_abd_pol			: 1;
		__IO uint32_t cfgr_abd_inv			: 1;
		__IO uint32_t sd_hvdd				: 1;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_DIC_CFG_t;

typedef union
{
	struct
	{
		__IO uint32_t pwm_num 				: 7;
		__IO uint32_t pwm_act_num 			: 7;
		__IO uint32_t pwm_smpl_num			: 7;
		__IO uint32_t pwm_dum_num			: 7;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_PWM_CTL_t;

typedef union
{
	struct
	{
		__IO uint32_t nd_dum_dly 			: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_ND_CTRL_t;

typedef union
{
	struct
	{
		__IO uint32_t pwm_prd1				: 12;
		__IO uint32_t pwm_prd2				: 12;
	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_PWM_PRD_t;

typedef union
{
	struct
	{
		__IO uint32_t smop_prd_1 			: 7;
		__IO uint32_t smop_prd_2 			: 7;
		__IO uint32_t crrpt_num				: 3;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_SMPL_CTL_t;

typedef union
{
	struct
	{
		__IO uint32_t rstp_num1				: 12;
		__IO uint32_t rstp_num2				: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_RSTP_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t phtcr_num1_1			: 12;
		__IO uint32_t phtcr_num1_2 			: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_PHTCR_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t phtcr_num2_1			: 12;
		__IO uint32_t phtcr_num2_2			: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_PHTCR_NUM2_t;

typedef union
{
	struct
	{
		__IO uint32_t vcr_num1_1 			: 12;
		__IO uint32_t vcr_num1_2			: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_VCR_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t vcr_en_num1_1			: 12;
		__IO uint32_t vcr_en_num1_2			: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_VCR_EN_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t vcr_en_num2_1			: 12;
		__IO uint32_t vcr_en_num2_2			: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_VCR_EN_NUM2_t;

typedef union
{
	struct
	{
		__IO uint32_t phth0_num1_1 			: 12;
		__IO uint32_t phth0_num1_2 			: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_PHTH0_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t phth1_num1_1			: 12;
		__IO uint32_t phth1_num1_2			: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_PHTH1_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t phth0_num2			: 12;
		__IO uint32_t phth1_num2 			: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_PHTH_NUM2_t;

typedef union
{
	struct
	{
		__IO uint32_t pht_prd				: 8;
		__IO uint32_t pht_opt_smpl			: 1;
		__IO uint32_t pht_opt_inv			: 1;
		__IO uint32_t pht_etime				: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_PHT_CTL_t;

typedef union
{
	struct
	{
		__IO uint32_t pht_num1 				: 12;
		__IO uint32_t pht_num2 				: 12;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_PHT_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t adc_op_opt			: 1;
		__IO uint32_t adc_clk_opt			: 2;
		__IO uint32_t adc_clk_pol			: 1;
		__IO uint32_t adc_clk_prd			: 3;
		__IO uint32_t adc_clk_num			: 4;
		__IO uint32_t adc_in_pos			: 4;
		__IO uint32_t adc_stc_dly			: 5;
		__IO uint32_t cfgr_tm_adc			: 1;
		__IO uint32_t adc_buf_pos			: 1;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_ADC_CTRL_t;

//typedef union
//{
//	struct
//	{
//		__IO uint32_t vcomr_opt				: 1;
//
//	} __PACKED tBit;
//	__IO uint32_t ulBulk;
//
//} __PACKED tSRIC_CFGR_VCOMR_OPT_t;

typedef union
{
	struct
	{
		__IO uint32_t double_buf_en			: 1;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_BUF_OPT_t;

typedef union
{
	struct
	{
		__IO uint32_t stuck_rstp			: 2;
		__IO uint32_t stuck_phtcr			: 2;
		__IO uint32_t stuck_vcr				: 2;
		__IO uint32_t stuck_vcr_odd_en		: 2;
		__IO uint32_t stuck_vcr_even_en		: 2;
		__IO uint32_t stuck_phth0			: 2;
		__IO uint32_t stuck_phth1			: 2;
		__IO uint32_t stuck_pht0			: 2;
		__IO uint32_t stuck_pht1			: 2;
		__IO uint32_t stuck_rsti			: 2;
		__IO uint32_t stuck_mux_en			: 1;
		__IO uint32_t stuck_adc_in			: 1;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_TG_STUCK_t;

typedef union
{
	struct
	{
		__IO uint32_t adc_in				: 25;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_ADC_IN_t;

typedef union
{
	struct
	{
		__IO uint32_t mux_stuck_val			: 10;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_MUX_STUCK_VAL_t;

typedef union
{
	struct
	{
		__IO uint32_t mux_00				: 4;
		__IO uint32_t mux_01				: 4;
		__IO uint32_t mux_02				: 4;
		__IO uint32_t mux_03				: 4;
		__IO uint32_t mux_04				: 4;
		__IO uint32_t mux_05				: 4;
		__IO uint32_t mux_06				: 4;
		__IO uint32_t mux_07				: 4;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_MUX_CFG_00_t;

typedef union
{
	struct
	{
		__IO uint32_t mux_08				: 4;
		__IO uint32_t mux_09				: 4;
		__IO uint32_t mux_10				: 4;
		__IO uint32_t mux_11				: 4;
		__IO uint32_t mux_12				: 4;
		__IO uint32_t mux_13				: 4;
		__IO uint32_t mux_14				: 4;
		__IO uint32_t mux_nd				: 4;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_MUX_CFG_01_t;

typedef union
{
	struct
	{
		__IO uint32_t sys_dummy0			: 32;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_SYS_DUMMY0_t;

typedef union
{
	struct
	{
		__IO uint32_t sys_dummy1			: 32;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_SYS_DUMMY1_t;


typedef union
{
	struct
	{
		__IO uint32_t cr1_r1g1				: 5;
		__IO uint32_t cr1_r1g2				: 5;
		__IO uint32_t cr1_r1g3				: 5;
		__IO uint32_t cr1_r2g1				: 5;
		__IO uint32_t cr1_r2g2				: 5;
		__IO uint32_t cr1_r2g3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX1_1_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_r3g1				: 5;
		__IO uint32_t cr1_r3g2				: 5;
		__IO uint32_t cr1_r3g3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX1_2_t;


typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1				: 5;
		__IO uint32_t cr1_rg2				: 5;
		__IO uint32_t cr1_rg3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX2_t;


typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1				: 5;
		__IO uint32_t cr1_rg2				: 5;
		__IO uint32_t cr1_rg3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX3_t;


typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1				: 5;
		__IO uint32_t cr1_rg2				: 5;
		__IO uint32_t cr1_rg3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX4_t;


typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1				: 5;
		__IO uint32_t cr1_rg2				: 5;
		__IO uint32_t cr1_rg3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX5_t;


typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1				: 5;
		__IO uint32_t cr1_rg2				: 5;
		__IO uint32_t cr1_rg3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX6_t;


typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1				: 5;
		__IO uint32_t cr1_rg2				: 5;
		__IO uint32_t cr1_rg3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX7_t;


typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1				: 5;
		__IO uint32_t cr1_rg2				: 5;
		__IO uint32_t cr1_rg3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX8_t;


typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1				: 5;
		__IO uint32_t cr1_rg2				: 5;
		__IO uint32_t cr1_rg3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX9_t;


typedef union
{
	struct
	{
		__IO uint32_t cr1_r1g1				: 5;
		__IO uint32_t cr1_r1g2				: 5;
		__IO uint32_t cr1_r1g3				: 5;
		__IO uint32_t cr1_r2g1				: 5;
		__IO uint32_t cr1_r2g2				: 5;
		__IO uint32_t cr1_r2g3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX10_1_t;


typedef union
{
	struct
	{
		__IO uint32_t cr1_r3g1				: 5;
		__IO uint32_t cr1_r3g2				: 5;
		__IO uint32_t cr1_r3g3				: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR1_MUX10_2_t;


typedef union
{
	struct
	{
		__IO uint32_t cr_m1o_rg1			: 5;
		__IO uint32_t cr_m1o_rg2			: 5;
		__IO uint32_t cr_m1o_rg3 			: 5;
		__IO uint32_t cr_m1e_rg1			: 5;
		__IO uint32_t cr_m1e_rg2			: 5;
		__IO uint32_t cr_m1e_rg3			: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR_M1_LTUNE_t;


typedef union
{
	struct
	{
		__IO uint32_t cr_gtune				: 3;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CR_GTUNE_t;


typedef union
{
	struct
	{
		__IO uint32_t lower_mux_num			: 4;
		__IO uint32_t cr_rg2_sel			: 5;
		__IO uint32_t cr_rg3_sel			: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_TUNE_LOWER_t;


typedef union
{
	struct
	{
		__IO uint32_t upper_mux_num			: 4;
		__IO uint32_t cr_rg2_sel			: 5;
		__IO uint32_t cr_rg3_sel			: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_TUNE_UPPER_t;


typedef union
{
	struct
	{
		__IO uint32_t cr_rg2_sel			: 5;
		__IO uint32_t cr_rg3_sel			: 5;
		__IO uint32_t cr_m1_g2_sel			: 5;
		__IO uint32_t cr_m1_g3_sel			: 5;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_TUNE_GROUP_t;


typedef union
{
	struct
	{
		__IO uint32_t adc_bcon 				: 2;
		__IO uint32_t adc_stc_insel 		: 1;
		__IO uint32_t int_ref			 	: 2;
		__IO uint32_t sha_ref 				: 2;
		__IO uint32_t lv_ssu_bcon 			: 3;
		__IO uint32_t lv_ssu_bcons 			: 3;
		__IO uint32_t hv_ssu_bcon 			: 3;
		__IO uint32_t integ_half 			: 1;
		__IO uint32_t pre_gc 				: 3;
		__IO uint32_t int_gc			 	: 3;
		__IO uint32_t powsel 				: 1;
		__IO uint32_t pre_bs_lp 			: 1;
		__IO uint32_t int_bs_lp 			: 1;
		__IO uint32_t sha_bs_lp 			: 1;


	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_SENSE_CTRL_t;


typedef union
{
	struct
	{
		__IO uint32_t tm_ssu_pen			: 1;
		__IO uint32_t vpen_en 				: 1;
		__IO uint32_t vpen_pol				: 1;
		__IO uint32_t tm_alp_mon			: 1;
		__IO uint32_t alp_mon				: 3;
		__IO uint32_t cfgr_adc_data_dly		: 2;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_SENSE_CTRL_2_t;


typedef union
{
	struct
	{
		__IO uint32_t pdb_hvbias			: 1;
		__IO uint32_t pdb_hvr				: 1;
		__IO uint32_t pdb_lvbias			: 1;
		__IO uint32_t pdb_lvr				: 1;
		__IO uint32_t bgr_en				: 1;
		__IO uint32_t pdb_adc				: 1;
		__IO uint32_t stuck_hvbias			: 2;
		__IO uint32_t stuck_hvr				: 2;
		__IO uint32_t stuck_lvbias			: 2;
		__IO uint32_t stuck_lvr				: 2;
		__IO uint32_t stuck_bgr				: 1;
		__IO uint32_t stuck_adc				: 1;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_CFGR_SSU_PW_CTRL_t;


typedef union
{
	struct
	{
		__IO uint32_t roic_dummy 			: 4;

	} __PACKED tBit;
	__IO uint32_t ulBulk;

} __PACKED tSRIC_ROIC_DUMMY_t;


typedef struct
{
//	tSRIC_CFGR_PRODUCT_ID_t tParam_CFGR_PRODUCT_ID;
	tSRIC_SPIS_CFG_t tParam_SPIS_CFG;
	tSRIC_SPIS_ERROR_CLR_t tParam_SPIS_ERROR_CLR;
	tSRIC_SPIS_ERROR_ST_t tParam_SPIS_ERROR_ST;
	tSRIC_CFGR_SYS_CFG_t tParam_CFGR_SYS_CFG;
	tSRIC_CFGR_TC_START_t tParam_CFGR_TC_START;
	tSRIC_CFGR_TC_STOP_t tParam_CFGR_TC_STOP;
	tSRIC_CFGR_CH_EN_t tParam_CFGR_CH_EN;
	tSRIC_CFGR_MUX_EN_t tParam_CFGR_MUX_EN;
	tSRIC_CFGR_DIC_CFG_t tParam_CFGR_DIC_CFG;
	tSRIC_CFGR_PWM_CTL_t tParam_CFGR_PWM_CTL;
	tSRIC_ND_CTRL_t tParam_ND_CTRL;
	tSRIC_CFGR_PWM_PRD_t tParam_CFGR_PWM_PRD;
	tSRIC_CFGR_SMPL_CTL_t tParam_CFGR_SMPL_CTL;
	tSRIC_CFGR_RSTP_NUM1_t tParam_CFGR_RSTP_NUM1;
	tSRIC_CFGR_PHTCR_NUM1_t tParam_CFGR_PHTCR_NUM1;
	tSRIC_CFGR_PHTCR_NUM2_t tParam_CFGR_PHTCR_NUM2;
	tSRIC_CFGR_VCR_NUM1_t tParam_CFGR_VCR_NUM1;
	tSRIC_CFGR_VCR_EN_NUM1_t tParam_CFGR_VCR_EN_NUM1;
	tSRIC_CFGR_VCR_EN_NUM2_t tParam_CFGR_VCR_EN_NUM2;
	tSRIC_CFGR_PHTH0_NUM1_t tParam_CFGR_PHTH0_NUM1;
	tSRIC_CFGR_PHTH1_NUM1_t tParam_CFGR_PHTH1_NUM1;
	tSRIC_CFGR_PHTH_NUM2_t tParam_CFGR_PHTH_NUM2;
	tSRIC_CFGR_PHT_CTL_t tParam_CFGR_PHT_CTL;
	tSRIC_CFGR_PHT_NUM1_t tParam_CFGR_PHT_NUM1;
	tSRIC_CFGR_ADC_CTRL_t tParam_CFGR_ADC_CTRL;
//	tSRIC_CFGR_VCOMR_OPT_t tParam_CFGR_VCOMR_OPT;
	tSRIC_CFGR_BUF_OPT_t tParam_CFGR_BUF_OPT;
	tSRIC_CFGR_TG_STUCK_t tParam_CFGR_TG_STUCK;
	tSRIC_CFGR_ADC_IN_t tParam_CFGR_ADC_IN;
	tSRIC_CFGR_MUX_STUCK_VAL_t tParam_CFGR_MUX_STUCK_VAL;
	tSRIC_CFGR_MUX_CFG_00_t tParam_CFGR_MUX_CFG_00;
	tSRIC_CFGR_MUX_CFG_01_t tParam_CFGR_MUX_CFG_01;
	tSRIC_SYS_DUMMY0_t tParam_SYS_DUMMY0;
	tSRIC_SYS_DUMMY1_t tParam_SYS_DUMMY1;

	tSRIC_CR1_MUX1_1_t tParam_R0_CR1_MUX1_1[8];
	tSRIC_CR1_MUX1_2_t tParam_R0_CR1_MUX1_2[8];
	tSRIC_CR1_MUX2_t tParam_R0_CR1_MUX2[8];
	tSRIC_CR1_MUX3_t tParam_R0_CR1_MUX3[8];
	tSRIC_CR1_MUX4_t tParam_R0_CR1_MUX4[8];
	tSRIC_CR1_MUX5_t tParam_R0_CR1_MUX5[8];
	tSRIC_CR1_MUX6_t tParam_R0_CR1_MUX6[8];
	tSRIC_CR1_MUX7_t tParam_R0_CR1_MUX7[8];
	tSRIC_CR1_MUX8_t tParam_R0_CR1_MUX8[8];
	tSRIC_CR1_MUX9_t tParam_R0_CR1_MUX9[8];
	tSRIC_CR1_MUX10_1_t tParam_R0_CR1_MUX10_1[8];
	tSRIC_CR1_MUX10_2_t tParam_R0_CR1_MUX10_2[8];

	tSRIC_CR1_MUX1_1_t tParam_R1_CR1_MUX1_1[8];
	tSRIC_CR1_MUX1_2_t tParam_R1_CR1_MUX1_2[8];
	tSRIC_CR1_MUX2_t tParam_R1_CR1_MUX2[8];
	tSRIC_CR1_MUX3_t tParam_R1_CR1_MUX3[8];
	tSRIC_CR1_MUX4_t tParam_R1_CR1_MUX4[8];
	tSRIC_CR1_MUX5_t tParam_R1_CR1_MUX5[8];
	tSRIC_CR1_MUX6_t tParam_R1_CR1_MUX6[8];
	tSRIC_CR1_MUX7_t tParam_R1_CR1_MUX7[8];
	tSRIC_CR1_MUX8_t tParam_R1_CR1_MUX8[8];
	tSRIC_CR1_MUX9_t tParam_R1_CR1_MUX9[8];
	tSRIC_CR1_MUX10_1_t tParam_R1_CR1_MUX10_1[8];
	tSRIC_CR1_MUX10_2_t tParam_R1_CR1_MUX10_2[8];

	tSRIC_CR_M1_LTUNE_t tParam_R0_CR_M1_LTUNE[8];
	tSRIC_CR_M1_LTUNE_t tParam_R1_CR_M1_LTUNE[8];

	tSRIC_CR_GTUNE_t tParam_CR_GTUNE;
	tSRIC_CFGR_TUNE_LOWER_t tParam_CFGR_TUNE_LOWER;
	tSRIC_CFGR_TUNE_UPPER_t tParam_CFGR_TUNE_UPPER;
	tSRIC_CFGR_TUNE_GROUP_t tParam_CFGR_TUNE_GROUP;
	tSRIC_CFGR_SENSE_CTRL_t tParam_CFGR_SENSE_CTRL;
	tSRIC_CFGR_SENSE_CTRL_2_t tParam_CFGR_SENSE_CTRL_2;
	tSRIC_CFGR_SSU_PW_CTRL_t tParam_CFGR_SSU_PW_CTRL;

} __PACKED tModuleSRICCommonConf_t;

#include "_sw97500_parampreset.h"

#endif /* (USED_ROIC_DEF == ROIC_SW97500) */


#endif /* __SW97500_CONF_H_ */
