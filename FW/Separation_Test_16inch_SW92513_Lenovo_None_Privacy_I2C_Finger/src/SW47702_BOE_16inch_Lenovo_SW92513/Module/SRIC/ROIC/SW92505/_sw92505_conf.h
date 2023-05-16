/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _SW92505_conf.h
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

#ifndef __SW92505_CONF_H_
#define __SW92505_CONF_H_

#if (USED_ROIC_DEF == ROIC_SW92505)

#define SW92505_MODE_FINGER					(0)
#define SW92505_MODE_BEACON					(1)
#define SW92505_MODE_PEN_POS				(2)
#define SW92505_MODE_PEN_TILT				(2)
#define SW92505_MODE_PEN_DATA				(3)
#define SW92505_MODE_NOISE_SCAN				(4)
#define SW92505_MODE_FINGER_VB				(5)
#define SW92505_MODE_DUMMY					(6)

typedef union
{
	struct
	{
		__I uint32_t revid: 8;
		__I uint32_t part_num: 24;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PRODUCT_ID_t;

typedef union
{
	struct
	{
		__IO uint32_t chksum_opt: 1;
		__IO uint32_t spis_irq_en: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tSPIS_CFG_t;

typedef union
{
	struct
	{
		__IO uint32_t spi_chksum_clr: 1;
		__IO uint32_t tsync_fault_clr: 1;
		__IO uint32_t pwm_fault_clr: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tSPIS_ERROR_CLR_t;

typedef union
{
	struct
	{
		__IO uint32_t spi_chksum_err: 8;
		__IO uint32_t tsync_fault_err: 1;
		__IO uint32_t pwm_fault_err: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tSPIS_ERROR_ST_t;

typedef union
{
	struct
	{
		__IO uint32_t miso_ds: 1;
		__IO uint32_t miso_dout: 1;
		__IO uint32_t miso_func: 3;
		__IO uint32_t mosi_ds: 1;
		__IO uint32_t mosi_dout: 1;
		__IO uint32_t mosi_func: 3;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tSPIS_PAD_CTL_t;

typedef union
{
	struct
	{
		__IO uint32_t tg_reset: 1;
		__IO uint32_t sw_reset: 1;
		__IO uint32_t tg_clk_all_on: 1;
		__IO uint32_t buf_clk_on: 1;
		__IO uint32_t cfclk_on: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_SYS_CFG_t;

typedef union
{
	struct
	{
		__IO uint32_t tc_start: 1;
		__IO uint32_t scan_cont: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_TC_START_t;

typedef union
{
	struct
	{
		__IO uint32_t tc_stop: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_TC_STOP_t;

typedef union
{
	struct
	{
		__IO uint32_t ch_num: 6;
		__IO uint32_t ch_en_lvr: 7;
		__IO uint32_t ch_en_hvr: 9;
		__IO uint32_t dum_drv_en: 2;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_R0_CH_EN_t;

typedef union
{
	struct
	{
		__IO uint32_t ch_num: 6;
		__IO uint32_t ch_en_lvr: 7;
		__IO uint32_t ch_en_hvr: 9;
		__IO uint32_t dum_drv_en: 2;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_R1_CH_EN_t;

typedef union
{
	struct
	{
		__IO uint32_t mux_int_en: 3;
		__IO uint32_t mux_num_tot: 4;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_MUX_EN_t;

typedef union
{
	struct
	{
		__IO uint32_t mux_dly: 7;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_MUX_DLY_t;

typedef union
{
	struct
	{
		__IO uint32_t sd_off: 1;
		__IO uint32_t sd_float: 1;
		__IO uint32_t tsync_in_pol: 1;
		__IO uint32_t pwm_pol: 1;
		__IO uint32_t tsync_out_pol: 1;
		__IO uint32_t tsync_out_bypass: 1;
		__IO uint32_t tsync_out_stuck: 1;
		__IO uint32_t tsync_out_level: 1;
		__IO uint32_t vsync_pol: 1;
		__IO uint32_t vsync_tg_en: 1;
		__IO uint32_t vsync_tg_act: 1;
		__IO uint32_t cfgr_stuck_sd_stat: 1;
		__IO uint32_t cfgr_sr_stat: 1;
		__IO uint32_t cfgr_sd_all: 1;
		__IO uint32_t cfgr_sd_dir: 1;
		__IO uint32_t sd_hvdd: 1;
		__IO uint32_t tsync2_pol: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_DIC_CFG_t;

typedef union
{
	struct
	{
		__IO uint32_t pwm_pdrv_num: 7;
		__IO uint32_t pwm_act_num: 7;
		__IO uint32_t pwm_smpl_num: 7;
		__IO uint32_t pwm_dum_num: 7;
		__IO uint32_t pdrv_dum_num: 2;
		__IO uint32_t pwm_set_num: 2;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PWM_CTL_t;

typedef union
{
	struct
	{
		__IO uint32_t pwm_pdrv_num: 7;
		__IO uint32_t pwm_act_num: 7;
		__IO uint32_t pwm_smpl_num: 7;
		__IO uint32_t pwm_dum_num: 7;
		__IO uint32_t pdrv_dum_num: 2;
		__IO uint32_t pwm_set_num: 2;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PWM_POS_CTL_t;

typedef union
{
	struct
	{
		__IO uint32_t pwm_pdrv_num: 7;
		__IO uint32_t pwm_act_num: 7;
		__IO uint32_t pwm_smpl_num: 7;
		__IO uint32_t pwm_dum_num: 7;
		__IO uint32_t pdrv_dum_num: 2;
		__IO uint32_t pwm_set_num: 2;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PWM_DAT_CTL_t;

typedef union
{
	struct
	{
		__IO uint32_t nd_dum_dly: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tND_CTRL_t;

typedef union
{
	struct
	{
		__IO uint32_t pwm_prd1: 12;
		__IO uint32_t pwm_prd2: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PWM_PRD_t;

typedef union
{
	struct
	{
		__IO uint32_t smop_prd_1: 7;
		__IO uint32_t smop_prd_2: 7;
		__IO uint32_t crrpt_num: 3;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_SMPL_CTL_t;

typedef union
{
	struct
	{
		__IO uint32_t rstp_num1: 12;
		__IO uint32_t rstp_num2: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_RSTP_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t phtcr_num1_1: 12;
		__IO uint32_t phtcr_num1_2: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PHTCR_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t phtcr_num2_1: 12;
		__IO uint32_t phtcr_num2_2: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PHTCR_NUM2_t;

typedef union
{
	struct
	{
		__IO uint32_t vcr_num1_1: 12;
		__IO uint32_t vcr_num1_2: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_VCR_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t vcr_en_num1_1: 12;
		__IO uint32_t vcr_en_num1_2: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_VCR_EN_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t vcr_en_num2_1: 12;
		__IO uint32_t vcr_en_num2_2: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_VCR_EN_NUM2_t;

typedef union
{
	struct
	{
		__IO uint32_t phth0_num1_1: 12;
		__IO uint32_t phth0_num1_2: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PHTH0_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t phth1_num1_1: 12;
		__IO uint32_t phth1_num1_2: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PHTH1_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t phth0_num2: 12;
		__IO uint32_t phth1_num2: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PHTH_NUM2_t;

typedef union
{
	struct
	{
		__IO uint32_t pht_prd: 8;
		__IO uint32_t pht_opt_smpl: 1;
		__IO uint32_t pht_opt_inv: 1;
		__IO uint32_t pht_etime: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PHT_CTL_t;

typedef union
{
	struct
	{
		__IO uint32_t pht_num1: 12;
		__IO uint32_t pht_num2: 12;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PHT_NUM1_t;

typedef union
{
	struct
	{
		__IO uint32_t adc_op_opt: 1;
		__IO uint32_t adc_clk_opt: 2;
		__IO uint32_t adc_clk_pol: 1;
		__IO uint32_t adc_clk_prd: 3;
		__IO uint32_t adc_clk_num: 4;
		__IO uint32_t adc_in_pos: 4;
		__IO uint32_t adc_stc_dly: 5;
		__IO uint32_t adc_clk_spt: 1;
		__IO uint32_t cfgr_tm_adc: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_ADC_CTRL_t;

typedef union
{
	struct
	{
		__IO uint32_t display_vcomr: 2;
		__IO uint32_t touch_f_vcomr: 2;
		__IO uint32_t touch_p_vcomr: 2;
		__IO uint32_t stuck_left: 1;
		__IO uint32_t stuck_right: 1;
		__IO uint32_t stuck_level: 1;
		__IO uint32_t tsync_opt: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_VCOMR_OPT_t;

typedef union
{
	struct
	{
		__IO uint32_t double_buf_en: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_BUF_OPT_t;

typedef union
{
	struct
	{
		__IO uint32_t stuck_rstp: 2;
		__IO uint32_t stuck_phtcr: 2;
		__IO uint32_t stuck_vcr: 2;
		__IO uint32_t stuck_rsti: 2;
		__IO uint32_t stuck_phth0: 2;
		__IO uint32_t stuck_phth1: 2;
		__IO uint32_t stuck_pht0: 2;
		__IO uint32_t stuck_pht1: 2;
		__IO uint32_t stuck_vcr_odd_en: 2;
		__IO uint32_t stuck_vcr_even_en: 2;
		__IO uint32_t stuck_muxs_en: 1;
		__IO uint32_t stuck_muxf_en: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_TG_STUCK_t;

typedef union
{
	struct
	{
		__IO uint32_t adc_in: 18;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_ADC_IN_t;

typedef union
{
	struct
	{
		__IO uint32_t mux_s_stuck_val: 10;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_MUX_S_STUCK_VAL_t;

typedef union
{
	struct
	{
		__IO uint32_t mux_f_stuck_val: 10;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_MUX_F_STUCK_VAL_t;

typedef union
{
	struct
	{
		__IO uint32_t MUX_00: 4;
		__IO uint32_t MUX_01: 4;
		__IO uint32_t MUX_02: 4;
		__IO uint32_t MUX_03: 4;
		__IO uint32_t MUX_04: 4;
		__IO uint32_t MUX_05: 4;
		__IO uint32_t MUX_06: 4;
		__IO uint32_t MUX_07: 4;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_MUX_CFG_00_t;

typedef union
{
	struct
	{
		__IO uint32_t MUX_08: 4;
		__IO uint32_t MUX_09: 4;
		__IO uint32_t MUX_10: 4;
		__IO uint32_t MUX_11: 4;
		__IO uint32_t MUX_12: 4;
		__IO uint32_t MUX_13: 4;
		__IO uint32_t MUX_14: 4;
		__IO uint32_t MUX_15: 4;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_MUX_CFG_01_t;

typedef union
{
	struct
	{
		__IO uint32_t mode: 3;
		__IO uint32_t ping_en: 1;
		__IO uint32_t pre_drv: 1;
		__IO uint32_t pre_drvs_en: 1;
		__IO uint32_t extmuxcmd: 1;
		__IO uint32_t mux_type: 1;
		__IO uint32_t lhb_mux_cnt: 4;
		__IO uint32_t local_pos0: 6;
		__IO uint32_t local_pos1: 4;
		__IO uint32_t local_pos2: 4;
		__IO uint32_t local_pos3: 4;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tLHB_CFG_t;

//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG01_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG02_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG03_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG04_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG05_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG06_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG07_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG08_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG09_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG10_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG11_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG12_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG13_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG14_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t mode: 3;
//		__IO uint32_t ping_en: 1;
//		__IO uint32_t pre_drv: 1;
//		__IO uint32_t pre_drvs_en: 1;
//		__IO uint32_t extmuxcmd: 1;
//		__IO uint32_t mux_type: 1;
//		__IO uint32_t lhb_mux_cnt: 4;
//		__IO uint32_t local_pos0: 6;
//		__IO uint32_t local_pos1: 4;
//		__IO uint32_t local_pos2: 4;
//		__IO uint32_t local_pos3: 4;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tLHB_CFG15_t;

typedef union
{
	struct
	{
		__IO uint32_t pwm_set_en_finger: 10;
		__IO uint32_t pwm_set_en_pen_pos: 10;
		__IO uint32_t pwm_set_en_pen_dat: 10;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PWM_SET_EN_BIT_t;

typedef union
{
	struct
	{
		__IO uint32_t m1_mode_sel: 2;
		__IO uint32_t pd_mux_num: 2;
		__IO uint32_t mux_m1_bit_en: 10;
		__IO uint32_t mux_nd_bit_en: 10;
		__IO uint32_t max_lhb_cnt: 4;
		__IO uint32_t ping_mux_type: 1;
		__IO uint32_t ping_mux_local_sel: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_LHB_MUX_CTRL_t;

typedef union
{
	struct
	{
		__IO uint32_t ping_max: 12;
		__IO uint32_t ping_end_offset: 8;
		__IO uint32_t mux_ping_bit_en: 10;
		__IO uint32_t pin_mux_sel: 1;
		__IO uint32_t ping_mode: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PING_MUX_CTRL_t;

typedef union
{
	struct
	{
		__IO uint32_t mux_pdrv_bit_en: 10;
		__IO uint32_t pdrv_mux_sel: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PRE_DRV_CTRL_t;

typedef union
{
	struct
	{
		__IO uint32_t mux_beacon_bit_en: 10;
		__IO uint32_t mux_pen_pos_bit_en: 10;
		__IO uint32_t mux_pen_dat_bit_en: 10;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PEN_MUX_BIT_EN_t;

typedef union
{
	struct
	{
		__IO uint32_t mux_pdrv_pos_sub_bit: 16;
		__IO uint32_t mux_pdrv_dat_sub_bit: 16;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_PDRV_SUB_BIT_EN_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_r1g1: 5;
		__IO uint32_t cr1_r1g2: 5;
		__IO uint32_t cr1_r1g3: 5;
		__IO uint32_t cr1_r2g1: 5;
		__IO uint32_t cr1_r2g2: 5;
		__IO uint32_t cr1_r2g3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX1_1_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_r3g1: 5;
		__IO uint32_t cr1_r3g2: 5;
		__IO uint32_t cr1_r3g3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX1_2_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX2_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX3_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX4_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX5_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX6_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX7_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX8_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX9_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_r1g1: 5;
		__IO uint32_t cr1_r1g2: 5;
		__IO uint32_t cr1_r1g3: 5;
		__IO uint32_t cr1_r2g1: 5;
		__IO uint32_t cr1_r2g2: 5;
		__IO uint32_t cr1_r2g3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX10_1_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_r3g1: 5;
		__IO uint32_t cr1_r3g2: 5;
		__IO uint32_t cr1_r3g3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR1_MUX10_2_t;

typedef union
{
	struct
	{
		__IO uint32_t cr_fg_gtune: 2;
		__IO uint32_t cr_pn_gtune: 2;
		__IO uint32_t cr_pd_gtune: 2;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CR_GTUNE_t;

typedef union
{
	struct
	{
		__IO uint32_t cr_rg2_sel: 5;
		__IO uint32_t cr_rg3_sel: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR0_CFGR_TUNE_GROUP_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_r1g1: 5;
		__IO uint32_t cr1_r1g2: 5;
		__IO uint32_t cr1_r1g3: 5;
		__IO uint32_t cr1_r2g1: 5;
		__IO uint32_t cr1_r2g2: 5;
		__IO uint32_t cr1_r2g3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX1_1_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_r3g1: 5;
		__IO uint32_t cr1_r3g2: 5;
		__IO uint32_t cr1_r3g3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX1_2_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX2_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX3_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX4_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX5_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX6_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX7_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX8_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_rg1: 5;
		__IO uint32_t cr1_rg2: 5;
		__IO uint32_t cr1_rg3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX9_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_r1g1: 5;
		__IO uint32_t cr1_r1g2: 5;
		__IO uint32_t cr1_r1g3: 5;
		__IO uint32_t cr1_r2g1: 5;
		__IO uint32_t cr1_r2g2: 5;
		__IO uint32_t cr1_r2g3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX10_1_t;

typedef union
{
	struct
	{
		__IO uint32_t cr1_r3g1: 5;
		__IO uint32_t cr1_r3g2: 5;
		__IO uint32_t cr1_r3g3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR1_MUX10_2_t;

typedef union
{
	struct
	{
		__IO uint32_t cr_fg_gtune: 2;
		__IO uint32_t cr_pn_gtune: 2;
		__IO uint32_t cr_pd_gtune: 2;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CR_GTUNE_t;

typedef union
{
	struct
	{
		__IO uint32_t cr_rg2_sel: 5;
		__IO uint32_t cr_rg3_sel: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tR1_CFGR_TUNE_GROUP_t;

typedef union
{
	struct
	{
		__IO uint32_t lv_ssu_bcon: 3;
		__IO uint32_t lv_ssu_bcons: 3;
		__IO uint32_t hv_ssu_bcon: 3;
		__IO uint32_t pen_dc_md: 2;
		__IO uint32_t pen_dc_md_stuck: 2;

//		__IO uint32_t integ_half: 3;
		__IO uint32_t integ_half_f: 1;
		__IO uint32_t integ_half_comp: 1;
		__IO uint32_t integ_half_p: 1;

//		__IO uint32_t pre_gc: 6;
		__IO uint32_t pre_gc_f: 2;
		__IO uint32_t pre_gc_comp: 2;
		__IO uint32_t pre_gc_p: 2;

//		__IO uint32_t int_gc: 6;
		__IO uint32_t int_gc_f: 2;
		__IO uint32_t int_gc_comp:2;
		__IO uint32_t int_gc_p: 2;

		__IO uint32_t powsel: 1;
		__IO uint32_t pre_bs_lp: 1;
		__IO uint32_t int_bs_lp: 1;
		__IO uint32_t tm_ssu_pen: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_SENSE_CTRL_t;

typedef union
{
	struct
	{
		__IO uint32_t adc_bcon: 2;
		__IO uint32_t adc_stc_insel: 1;
		__IO uint32_t adc_dsf: 1;
		__IO uint32_t adc_ref_sel: 2;
		__IO uint32_t int_ref: 3;
		__IO uint32_t sha_ref: 3;
		__IO uint32_t sha_bs_lp: 1;
		__IO uint32_t ref_res_sel: 1;
		__IO uint32_t lv_comp_bcon: 1;
		__IO uint32_t comp_hys_ctrl: 4;
		__IO uint32_t tm_comp: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_COMP_ADC_CTRL_t;

typedef union
{
	struct
	{
		__IO uint32_t pdb_hvbias: 1;
		__IO uint32_t pdb_hvr: 1;
		__IO uint32_t pdb_lvbias: 1;
		__IO uint32_t pdb_lvr: 1;
		__IO uint32_t pdb_sha: 1;
		__IO uint32_t bgr_en: 1;
		__IO uint32_t pdb_adc: 1;
		__IO uint32_t pdb_compbias: 1;
		__IO uint32_t pdb_comp: 1;
		__IO uint32_t stuck_hvbias: 2;
		__IO uint32_t stuck_hvr: 2;
		__IO uint32_t stuck_lvbias: 2;
		__IO uint32_t stuck_lvr: 2;
		__IO uint32_t stuck_sha: 2;
		__IO uint32_t stuck_bgr: 2;
		__IO uint32_t stuck_adc: 2;
		__IO uint32_t stuck_compbias: 2;
		__IO uint32_t stuck_comp: 2;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_SSU_PW_CTRL_t;

typedef union
{
	struct
	{
		__IO uint32_t lower_mux_num: 4;
		__IO uint32_t cr_rg2_sel: 5;
		__IO uint32_t cr_rg3_sel: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_TUNE_LOWER_t;

typedef union
{
	struct
	{
		__IO uint32_t upper_mux_num: 4;
		__IO uint32_t cr_rg2_sel: 5;
		__IO uint32_t cr_rg3_sel: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_TUNE_UPPER_t;

typedef union
{
	struct
	{
		__IO uint32_t r0_pre_ch_con_en	:1 ;
		__IO uint32_t r0_pre_comp	:1 ;
		__IO uint32_t r0_reserve	:2 ;
		__IO uint32_t r1_pre_ch_con_en	:1 ;
		__IO uint32_t r1_pre_comp	:1 ;
		__IO uint32_t r1_reserve	:2 ;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tTAFE_REV_SIG_t;

typedef union
{
	struct
	{
		__IO uint32_t sd_rocen	:1 ;
		__IO uint32_t sd_pwrcr2	:1 ;
		__IO uint32_t sd_pwrcr3	:1 ;
		__IO uint32_t reserve	:29 ;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tSYS_DUMMY0_t;

typedef union
{
	struct
	{
		__IO uint32_t sd_pwrcr1	:1 ;
		__IO uint32_t reserve	:31 ;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tSYS_DUMMY1_t;

typedef union
{
	struct
	{
		__IO uint32_t sel_rw_width: 2;
		__IO uint32_t dly_offset: 10;
		__IO uint32_t max_insert_dly: 7;
		__IO uint32_t insert_dly_sel: 1;
		__IO uint32_t comp_mon_sel: 7;
		__IO uint32_t sel_offset: 1;
		__IO uint32_t comp_err_chk_en: 1;
		__IO uint32_t sel_comp_redge: 1;
		__IO uint32_t sel_comp_fedge: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_COMP_CTRL_t;

typedef union
{
	struct
	{
		__IO uint32_t comp_rsti_num1: 8;
		__IO uint32_t comp_rsti_num2: 8;
		__IO uint32_t rsti_select: 1;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_COMP_RSTI_NUM_t;

typedef union
{
	struct
	{
		__IO uint32_t comp_rwidth_redge: 8;
		__IO uint32_t comp_rwidth_fedge: 8;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_COMP_WINDOW_1_t;

typedef union
{
	struct
	{
		__IO uint32_t comp_fwidth_redge: 8;
		__IO uint32_t comp_fwidth_fedge: 8;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCFGR_COMP_WINDOW_2_t;

typedef union
{
	struct
	{
		__IO uint32_t insert_dly_val: 8;
		__IO uint32_t rwidth_rdat: 8;
		__IO uint32_t fwidth_rdat: 8;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tCOMP_STATUS_t;

typedef struct
{
//	tCFGR_PRODUCT_ID_t CFGR_PRODUCT_ID;					//	0x0000	R	  0x0925_0300
	tSPIS_CFG_t SPIS_CFG;								//	0x0004	R/W	  0x0000_0003
	tSPIS_ERROR_CLR_t SPIS_ERROR_CLR;					//	0x0008	R/W	  0x0000_0000
	tSPIS_ERROR_ST_t SPIS_ERROR_ST;						//	0x000C	R	  0x0000_0000
	tSPIS_PAD_CTL_t SPIS_PAD_CTL;						//	0x0010	R/W	  0x0000_0021
	tCFGR_SYS_CFG_t CFGR_SYS_CFG;						//	0x0014	R/W	  0x0000_000C
	tCFGR_TC_START_t CFGR_TC_START;						//	0x0018	R/W	  0x0000_0002
	tCFGR_TC_STOP_t CFGR_TC_STOP;						//	0x001C	R/W	  0x0000_0000
	tCFGR_R0_CH_EN_t CFGR_R0_CH_EN;						//	0x0020	R/W	  0x003F_FFD2
	tCFGR_R1_CH_EN_t CFGR_R1_CH_EN;						//	0x0024	R/W	  0x003F_FFD2
	tCFGR_MUX_EN_t CFGR_MUX_EN;							//	0x0028	R/W	  0x0000_0058
	tCFGR_MUX_DLY_t CFGR_MUX_DLY;						//	0x002C	R/W	  0x0000_0000
	tCFGR_DIC_CFG_t CFGR_DIC_CFG;						//	0x0030	R/W	  0x0000_0020
	tCFGR_PWM_CTL_t CFGR_PWM_CTL;						//	0x0034	R/W	  0x0061_8300
	tCFGR_PWM_POS_CTL_t CFGR_PWM_POS_CTL;				//	0x0038	R/W	  0x0001_8300
	tCFGR_PWM_DAT_CTL_t CFGR_PWM_DAT_CTL;				//	0x003C	R/W	  0x0001_8300
	tND_CTRL_t ND_CTRL;									//	0x0040	R/W	  0x0000_0030
	tCFGR_PWM_PRD_t CFGR_PWM_PRD;						//	0x0044	R/W	  0x0003_0030
	tCFGR_SMPL_CTL_t CFGR_SMPL_CTL;						//	0x0048	R/W	  0x0000_0387
	tCFGR_RSTP_NUM1_t CFGR_RSTP_NUM1;					//	0x004C	R/W	  0x0000_300A
	tCFGR_PHTCR_NUM1_t CFGR_PHTCR_NUM1;					//	0x0050	R/W	  0x0002_C02C
	tCFGR_PHTCR_NUM2_t CFGR_PHTCR_NUM2;					//	0x0054	R/W	  0x0001_E01E
	tCFGR_VCR_NUM1_t CFGR_VCR_NUM1;						//	0x0058	R/W	  0x0002_8028
	tCFGR_VCR_EN_NUM1_t CFGR_VCR_EN_NUM1;				//	0x005C	R/W	  0x0002_1021
	tCFGR_VCR_EN_NUM2_t CFGR_VCR_EN_NUM2;				//	0x0060	R/W	  0x0000_C00C
	tCFGR_PHTH0_NUM1_t CFGR_PHTH0_NUM1;					//	0x0064	R/W	  0x0001_0010
	tCFGR_PHTH1_NUM1_t CFGR_PHTH1_NUM1;					//	0x0068	R/W	  0x0000_F00F
	tCFGR_PHTH_NUM2_t CFGR_PHTH_NUM2;					//	0x006C	R/W	  0x0001_E002
	tCFGR_PHT_CTL_t CFGR_PHT_CTL;						//	0x0070	R/W	  0x0000_4202
	tCFGR_PHT_NUM1_t CFGR_PHT_NUM1;						//	0x0074	R/W	  0x0000_D017
	tCFGR_ADC_CTRL_t CFGR_ADC_CTRL;						//	0x0078	R/W	  0x000F_AB94
	tCFGR_VCOMR_OPT_t CFGR_VCOMR_OPT;					//	0x007C	R/W	  0x0000_0000
	tCFGR_BUF_OPT_t CFGR_BUF_OPT;						//	0x0080	R/W	  0x0000_0001
	tCFGR_TG_STUCK_t CFGR_TG_STUCK[5];						//	0x0084	R/W	  0x000F_03C0
	tCFGR_ADC_IN_t CFGR_ADC_IN;							//	0x0088	R/W	  0x0000_0001
	tCFGR_MUX_S_STUCK_VAL_t CFGR_MUX_S_STUCK_VAL;		//	0x008C	R/W	  0x0000_0000
	tCFGR_MUX_F_STUCK_VAL_t CFGR_MUX_F_STUCK_VAL;		//	0x0090	R/W	  0x0000_0000
	tCFGR_MUX_CFG_00_t CFGR_MUX_CFG_00;					//	0x0094	R/W	  0x7654_3210
	tCFGR_MUX_CFG_01_t CFGR_MUX_CFG_01;					//	0x0098	R/W	  0xFEDC_BA98
	tLHB_CFG_t LHB_CFG[3][16];
//	tLHB_CFG00_t LHB_CFG00;								//	0x009C	R/W	  0x0084_0200
//	tLHB_CFG01_t LHB_CFG01;								//	0x00A0	R/W	  0x0150_3200
//	tLHB_CFG02_t LHB_CFG02;								//	0x00A4	R/W	  0x021C_6200
//	tLHB_CFG03_t LHB_CFG03;								//	0x00A8	R/W	  0x0264_9200
//	tLHB_CFG04_t LHB_CFG04;								//	0x00AC	R/W	  0x0084_0200
//	tLHB_CFG05_t LHB_CFG05;								//	0x00B0	R/W	  0x0150_3200
//	tLHB_CFG06_t LHB_CFG06;								//	0x00B4	R/W	  0x021C_6200
//	tLHB_CFG07_t LHB_CFG07;								//	0x00B8	R/W	  0x0264_9200
//	tLHB_CFG08_t LHB_CFG08;								//	0x00BC	R/W	  0x0000_0000
//	tLHB_CFG09_t LHB_CFG09;								//	0x00C0	R/W	  0x0000_0000
//	tLHB_CFG10_t LHB_CFG10;								//	0x00C4	R/W	  0x0000_0000
//	tLHB_CFG11_t LHB_CFG11;								//	0x00C8	R/W	  0x0000_0000
//	tLHB_CFG12_t LHB_CFG12;								//	0x00CC	R/W	  0x0000_0000
//	tLHB_CFG13_t LHB_CFG13;								//	0x00D0	R/W	  0x0000_0000
//	tLHB_CFG14_t LHB_CFG14;								//	0x00D4	R/W	  0x0000_0000
//	tLHB_CFG15_t LHB_CFG15;								//	0x00D8	R/W	  0x0000_0000
	tCFGR_PWM_SET_EN_BIT_t CFGR_PWM_SET_EN_BIT;			//	0x00DC	R/W	  0x0000_03FF
	tCFGR_LHB_MUX_CTRL_t CFGR_LHB_MUX_CTRL;				//	0x00E0	R/W	  0x073F_CFF4
	tCFGR_PING_MUX_CTRL_t CFGR_PING_MUX_CTRL;			//	0x00E4	R/W	  0x0000_0000
	tCFGR_PRE_DRV_CTRL_t CFGR_PRE_DRV_CTRL;				//	0x00E8	R/W	  0x0000_0000
	tCFGR_PEN_MUX_BIT_EN_t CFGR_PEN_MUX_BIT_EN;			//	0x00EC	R/W	  0x0000_0000
	tCFGR_PDRV_SUB_BIT_EN_t CFGR_PDRV_SUB_BIT_EN;		//	0x00F0	R/W	  0x0000_0000
//	tDFE_reserved1_t DFE_reserved1;						//	0x00F4	R/W	  0x0000_0000
//	tDFE_reserved2_t DFE_reserved2;						//	0x00F8	R/W	  0x0000_0000
//	tDFE_reserved3_t DFE_reserved3;						//	0x00FC	R/W	  0x0000_0000

	tR0_CR1_MUX1_1_t R0_CR1_MUX1_1[5];						//	0x0100	R/W	  0x0000_0000
	tR0_CR1_MUX1_2_t R0_CR1_MUX1_2[5];						//	0x0104	R/W	  0x0000_0000
	tR0_CR1_MUX2_t R0_CR1_MUX2[5];							//	0x0108	R/W	  0x0000_0000
	tR0_CR1_MUX3_t R0_CR1_MUX3[5];							//	0x010C	R/W	  0x0000_0000
	tR0_CR1_MUX4_t R0_CR1_MUX4[5];							//	0x0110	R/W	  0x0000_0000
	tR0_CR1_MUX5_t R0_CR1_MUX5[5];							//	0x0114	R/W	  0x0000_0000
	tR0_CR1_MUX6_t R0_CR1_MUX6[5];							//	0x0118	R/W	  0x0000_0000
	tR0_CR1_MUX7_t R0_CR1_MUX7[5];							//	0x011C	R/W	  0x0000_0000
	tR0_CR1_MUX8_t R0_CR1_MUX8[5];							//	0x0120	R/W	  0x0000_0000
	tR0_CR1_MUX9_t R0_CR1_MUX9[5];							//	0x0124	R/W	  0x0000_0000
	tR0_CR1_MUX10_1_t R0_CR1_MUX10_1[5];					//	0x0128	R/W	  0x0000_0000
	tR0_CR1_MUX10_2_t R0_CR1_MUX10_2[5];					//	0x012C	R/W	  0x0000_0000
	tR0_CR_GTUNE_t R0_CR_GTUNE[5];							//	0x0130	R/W	  0x0000_0000
	tR0_CFGR_TUNE_GROUP_t R0_CFGR_TUNE_GROUP;			//	0x0134	R/W	  0x0000_0382
//	tTAFE_L_Reserved_00_t TAFE_L_Reserved_00;			//	0x0138	R/W	  0x0000_0000
//	tTAFE_L_Reserved_01_t TAFE_L_Reserved_01;			//	0x013C	R/W	  0x0000_0000
//	tTAFE_L_Reserved_02_t TAFE_L_Reserved_02;			//	0x0140	R/W	  0x0000_0000
//	tTAFE_L_Reserved_03_t TAFE_L_Reserved_03;			//	0x0144	R/W	  0x0000_0000
//	tTAFE_L_Reserved_04_t TAFE_L_Reserved_04;			//	0x0148	R/W	  0x0000_0000
//	tTAFE_L_Reserved_05_t TAFE_L_Reserved_05;			//	0x014C	R/W	  0x0000_0000
//	tTAFE_L_Reserved_06_t TAFE_L_Reserved_06;			//	0x0150	R/W	  0x0000_0000
//	tTAFE_L_Reserved_07_t TAFE_L_Reserved_07;			//	0x0154	R/W	  0x0000_0000
//	tTAFE_L_Reserved_08_t TAFE_L_Reserved_08;			//	0x0158	R/W	  0x0000_0000
//	tTAFE_L_Reserved_09_t TAFE_L_Reserved_09;			//	0x015C	R/W	  0x0000_0000
//	tTAFE_L_Reserved_10_t TAFE_L_Reserved_10;			//	0x0160	R/W	  0x0000_0000
//	tTAFE_L_Reserved_11_t TAFE_L_Reserved_11;			//	0x0164	R/W	  0x0000_0000
//	tTAFE_L_Reserved_12_t TAFE_L_Reserved_12;			//	0x0168	R/W	  0x0000_0000
//	tTAFE_L_Reserved_13_t TAFE_L_Reserved_13;			//	0x016C	R/W	  0x0000_0000
//	tTAFE_L_Reserved_14_t TAFE_L_Reserved_14;			//	0x0170	R/W	  0x0000_0000
//	tTAFE_L_Reserved_15_t TAFE_L_Reserved_15;			//	0x0174	R/W	  0x0000_0000
//	tTAFE_L_Reserved_16_t TAFE_L_Reserved_16;			//	0x0178	R/W	  0x0000_0000
//	tTAFE_L_Reserved_17_t TAFE_L_Reserved_17;			//	0x017C	R/W	  0x0000_0000
	tR1_CR1_MUX1_1_t R1_CR1_MUX1_1[5];						//	0x0180	R/W	  0x0000_0000
	tR1_CR1_MUX1_2_t R1_CR1_MUX1_2[5];						//	0x0184	R/W	  0x0000_0000
	tR1_CR1_MUX2_t R1_CR1_MUX2[5];							//	0x0188	R/W	  0x0000_0000
	tR1_CR1_MUX3_t R1_CR1_MUX3[5];							//	0x018C	R/W	  0x0000_0000
	tR1_CR1_MUX4_t R1_CR1_MUX4[5];							//	0x0190	R/W	  0x0000_0000
	tR1_CR1_MUX5_t R1_CR1_MUX5[5];							//	0x0194	R/W	  0x0000_0000
	tR1_CR1_MUX6_t R1_CR1_MUX6[5];							//	0x0198	R/W	  0x0000_0000
	tR1_CR1_MUX7_t R1_CR1_MUX7[5];							//	0x019C	R/W	  0x0000_0000
	tR1_CR1_MUX8_t R1_CR1_MUX8[5];							//	0x01A0	R/W	  0x0000_0000
	tR1_CR1_MUX9_t R1_CR1_MUX9[5];							//	0x01A4	R/W	  0x0000_0000
	tR1_CR1_MUX10_1_t R1_CR1_MUX10_1[5];					//	0x01A8	R/W	  0x0000_0000
	tR1_CR1_MUX10_2_t R1_CR1_MUX10_2[5];					//	0x01AC	R/W	  0x0000_0000
	tR1_CR_GTUNE_t R1_CR_GTUNE[5];							//	0x01B0	R/W	  0x0000_0000
	tR1_CFGR_TUNE_GROUP_t R1_CFGR_TUNE_GROUP;			//	0x01B4	R/W	  0x0000_0382
	tCFGR_SENSE_CTRL_t CFGR_SENSE_CTRL;					//	0x01B8	R/W	  0x0FFF_0008
	tCFGR_COMP_ADC_CTRL_t CFGR_COMP_ADC_CTRL;			//	0x01BC	R/W	  0x0000_090B
	tCFGR_SSU_PW_CTRL_t CFGR_SSU_PW_CTRL;				//	0x01C0	R/W	  0x02AA_AA00
	tCFGR_TUNE_LOWER_t CFGR_TUNE_LOWER;					//	0x01C4	R/W	  0x0000_3820
	tCFGR_TUNE_UPPER_t CFGR_TUNE_UPPER;					//	0x01C8	R/W	  0x0000_3829
	tTAFE_REV_SIG_t TAFE_REV_SIG;						//	0x01CC	R/W	  0x0000_00CC
	tSYS_DUMMY0_t SYS_DUMMY0;							//	0x01D0	R/W	  0x0000_0000
	tSYS_DUMMY1_t SYS_DUMMY1;							//	0x01D4	R/W	  0xFFFF_FFFF
	tCFGR_COMP_CTRL_t CFGR_COMP_CTRL;					//	0x01D8	R/W	  0x0002_800E
	tCFGR_COMP_RSTI_NUM_t CFGR_COMP_RSTI_NUM;			//	0x01DC	R/W	  0x0001_1923
	tCFGR_COMP_WINDOW_1_t CFGR_COMP_WINDOW_1;			//	0x01E0	R/W	  0x0000_1025
	tCFGR_COMP_WINDOW_2_t CFGR_COMP_WINDOW_2;			//	0x01E4	R/W	  0x0000_1025
	tCOMP_STATUS_t COMP_STATUS;							//	0x01E8	R	  0x0000_0000
} __PACKED tModuleSRICCommonConf_t;

typedef struct
{
	tCFGR_PWM_CTL_t CFGR_PWM_CTL;						//	0x0034	R/W	  0x0061_8300
	tCFGR_PWM_POS_CTL_t CFGR_PWM_POS_CTL;				//	0x0038	R/W	  0x0001_8300
	tCFGR_PWM_DAT_CTL_t CFGR_PWM_DAT_CTL;				//	0x003C	R/W	  0x0001_8300
	tND_CTRL_t ND_CTRL;									//	0x0040	R/W	  0x0000_0030
	tCFGR_PWM_PRD_t CFGR_PWM_PRD;						//	0x0044	R/W	  0x0003_0030
	tCFGR_RSTP_NUM1_t CFGR_RSTP_NUM1;					//	0x004C	R/W	  0x0000_300A
	tCFGR_PHTCR_NUM1_t CFGR_PHTCR_NUM1;					//	0x0050	R/W	  0x0002_C02C
	tCFGR_PHTCR_NUM2_t CFGR_PHTCR_NUM2;					//	0x0054	R/W	  0x0001_E01E
	tCFGR_VCR_NUM1_t CFGR_VCR_NUM1;						//	0x0058	R/W	  0x0002_8028
	tCFGR_VCR_EN_NUM1_t CFGR_VCR_EN_NUM1;				//	0x005C	R/W	  0x0002_1021
	tCFGR_PHTH_NUM2_t CFGR_PHTH_NUM2;					//	0x006C	R/W	  0x0001_E002
	tCFGR_PWM_SET_EN_BIT_t CFGR_PWM_SET_EN_BIT;			//	0x00DC	R/W	  0x0000_03FF
	tLHB_CFG_t LHB_CFG[16];
	tCFGR_SENSE_CTRL_t CFGR_SENSE_CTRL;					//	0x01B8	R/W	  0x0FFF_0008

} __PACKED tSW92505_FullLocal_CFG_t;

#include "_sw92505_parampreset.h"

#endif /* (USED_ROIC_DEF == ROIC_SW92505) */


#endif /* __SW92505_CONF_H_ */
