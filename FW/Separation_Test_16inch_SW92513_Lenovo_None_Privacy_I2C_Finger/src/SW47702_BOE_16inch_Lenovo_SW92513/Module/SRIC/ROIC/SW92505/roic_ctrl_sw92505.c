/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : roic_ctrl_SW92505.c
 * created on : 20. 2. 2019
 * Author : mhjang
 *
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright
 *	 notice, this list of conditions and the following disclaimer.
 *	 - Redistributions in binary form must reproduce the above copyright
 *	 notice, this list of conditions and the following disclaimer in the
 *	 documentation and/or other materials provided with the distribution.
 * - Neither the name of SiW nor the names of its contributors may be used
 *	 to endorse or promote products derived from this software without
 *	 specific prior written permission.
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

#include "hal_def.h"
#include "module_def.h"
#include "roic_ctrl_SW92505.h"
#include "param_def.h"


#if (USED_ROIC_DEF == ROIC_SW92505)

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
tSW92505_FullLocal_CFG_t tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg =
{
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
	.CFGR_RSTP_NUM1 = \
	{ \
		.tBit.rstp_num1 = PARAMSET_ROIC_MPP_CFGR_RSTP_NUM1_rstp_num1, \
		.tBit.rstp_num2 = PARAMSET_ROIC_MPP_CFGR_RSTP_NUM1_rstp_num2, \
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
	.CFGR_PHT_NUM1 = \
	{ \
		.tBit.pht_num1 = PARAMSET_ROIC_MPP_CFGR_PHT_NUM1_pht_num1, \
		.tBit.pht_num2 = PARAMSET_ROIC_MPP_CFGR_PHT_NUM1_pht_num2, \
	}, \
	.CFGR_PWM_SET_EN_BIT = \
	{ \
		.tBit.pwm_set_en_finger = PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_finger, \
		.tBit.pwm_set_en_pen_pos = PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_pos, \
		.tBit.pwm_set_en_pen_dat = PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_dat, \
	}, \
	.LHB_CFG = { \
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
};

tSW92505_FullLocal_CFG_t tSW92505ActivePen_Runtime_Change_WGP_Local_Reg =
{
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
	.CFGR_RSTP_NUM1 = \
	{ \
		.tBit.rstp_num1 = PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num1, \
		.tBit.rstp_num2 = PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num2, \
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
	.CFGR_PHT_NUM1 = \
	{ \
		.tBit.pht_num1 = PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num1, \
		.tBit.pht_num2 = PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num2, \
	}, \
	.CFGR_PWM_SET_EN_BIT = \
	{ \
		.tBit.pwm_set_en_finger = PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_finger, \
		.tBit.pwm_set_en_pen_pos = PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_pos, \
		.tBit.pwm_set_en_pen_dat = PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_dat, \
	}, \
	.LHB_CFG = { \
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
		},\
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
};
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
const tModuleSRICCommonConf_t * s_pktmoduleSRICCommonConf = NULL;

static void SW92505_Reg_CRTuneSetting(void)
{
#if USED_TOUCH_TUNING_PROCESS
#include "app_tuning_process.h"
	uint32_t ulSRICIDX;
	tR0_CR1_MUX1_1_t R0_CR1_MUX1_1[MSPI_NUM];
	tR0_CR1_MUX1_2_t R0_CR1_MUX1_2[MSPI_NUM];
	tR0_CR1_MUX2_t R0_CR1_MUX2[MSPI_NUM];
	tR0_CR1_MUX3_t R0_CR1_MUX3[MSPI_NUM];
	tR0_CR1_MUX4_t R0_CR1_MUX4[MSPI_NUM];
	tR0_CR1_MUX5_t R0_CR1_MUX5[MSPI_NUM];
	tR0_CR1_MUX6_t R0_CR1_MUX6[MSPI_NUM];
	tR0_CR1_MUX7_t R0_CR1_MUX7[MSPI_NUM];
	tR0_CR1_MUX8_t R0_CR1_MUX8[MSPI_NUM];
	tR0_CR1_MUX9_t R0_CR1_MUX9[MSPI_NUM];
	tR0_CR1_MUX10_1_t R0_CR1_MUX10_1[MSPI_NUM];
	tR0_CR1_MUX10_2_t R0_CR1_MUX10_2[MSPI_NUM];

	tR0_CR1_MUX1_1_t R1_CR1_MUX1_1[MSPI_NUM];
	tR0_CR1_MUX1_2_t R1_CR1_MUX1_2[MSPI_NUM];
	tR0_CR1_MUX2_t R1_CR1_MUX2[MSPI_NUM];
	tR0_CR1_MUX3_t R1_CR1_MUX3[MSPI_NUM];
	tR0_CR1_MUX4_t R1_CR1_MUX4[MSPI_NUM];
	tR0_CR1_MUX5_t R1_CR1_MUX5[MSPI_NUM];
	tR0_CR1_MUX6_t R1_CR1_MUX6[MSPI_NUM];
	tR0_CR1_MUX7_t R1_CR1_MUX7[MSPI_NUM];
	tR0_CR1_MUX8_t R1_CR1_MUX8[MSPI_NUM];
	tR0_CR1_MUX9_t R1_CR1_MUX9[MSPI_NUM];
	tR0_CR1_MUX10_1_t R1_CR1_MUX10_1[MSPI_NUM];
	tR0_CR1_MUX10_2_t R1_CR1_MUX10_2[MSPI_NUM];

	for(ulSRICIDX=0; ulSRICIDX<MSPI_NUM; ulSRICIDX++)
	{
		R0_CR1_MUX1_1[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[ulSRICIDX].ulBulk;
		R0_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r1g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r1g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r1g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r2g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r2g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r2g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R0_CR1_MUX1_2[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[ulSRICIDX].ulBulk;
		R0_CR1_MUX1_2[ulSRICIDX].tBit.cr1_r3g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX1_2[ulSRICIDX].tBit.cr1_r3g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX1_2[ulSRICIDX].tBit.cr1_r3g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R0_CR1_MUX2[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX2[ulSRICIDX].ulBulk;
		R0_CR1_MUX2[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX2[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX2[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R0_CR1_MUX3[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX3[ulSRICIDX].ulBulk;
		R0_CR1_MUX3[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX3[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX3[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R0_CR1_MUX4[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX4[ulSRICIDX].ulBulk;
		R0_CR1_MUX4[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX4[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX4[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R0_CR1_MUX5[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX5[ulSRICIDX].ulBulk;
		R0_CR1_MUX5[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX5[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX5[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R0_CR1_MUX6[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX6[ulSRICIDX].ulBulk;
		R0_CR1_MUX6[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX6[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX6[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R0_CR1_MUX7[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX7[ulSRICIDX].ulBulk;
		R0_CR1_MUX7[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX7[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX7[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R0_CR1_MUX8[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX8[ulSRICIDX].ulBulk;
		R0_CR1_MUX8[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX8[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX8[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R0_CR1_MUX9[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX9[ulSRICIDX].ulBulk;
		R0_CR1_MUX9[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX9[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX9[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R0_CR1_MUX10_1[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[ulSRICIDX].ulBulk;
		R0_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r1g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r1g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r1g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r2g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r2g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r2g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R0_CR1_MUX10_2[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[ulSRICIDX].ulBulk;
		R0_CR1_MUX10_2[ulSRICIDX].tBit.cr1_r3g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX10_2[ulSRICIDX].tBit.cr1_r3g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R0_CR1_MUX10_2[ulSRICIDX].tBit.cr1_r3g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;


		R1_CR1_MUX1_1[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[ulSRICIDX].ulBulk;
		R1_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r1g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r1g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r1g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r2g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r2g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX1_1[ulSRICIDX].tBit.cr1_r2g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R1_CR1_MUX1_2[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[ulSRICIDX].ulBulk;
		R1_CR1_MUX1_2[ulSRICIDX].tBit.cr1_r3g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX1_2[ulSRICIDX].tBit.cr1_r3g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX1_2[ulSRICIDX].tBit.cr1_r3g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R1_CR1_MUX2[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX2[ulSRICIDX].ulBulk;
		R1_CR1_MUX2[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX2[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX2[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R1_CR1_MUX3[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX3[ulSRICIDX].ulBulk;
		R1_CR1_MUX3[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX3[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX3[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R1_CR1_MUX4[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX4[ulSRICIDX].ulBulk;
		R1_CR1_MUX4[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX4[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX4[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R1_CR1_MUX5[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX5[ulSRICIDX].ulBulk;
		R1_CR1_MUX5[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX5[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX5[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R1_CR1_MUX6[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX6[ulSRICIDX].ulBulk;
		R1_CR1_MUX6[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX6[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX6[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R1_CR1_MUX7[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX7[ulSRICIDX].ulBulk;
		R1_CR1_MUX7[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX7[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX7[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R1_CR1_MUX8[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX8[ulSRICIDX].ulBulk;
		R1_CR1_MUX8[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX8[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX8[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R1_CR1_MUX9[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX9[ulSRICIDX].ulBulk;
		R1_CR1_MUX9[ulSRICIDX].tBit.cr1_rg1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX9[ulSRICIDX].tBit.cr1_rg2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX9[ulSRICIDX].tBit.cr1_rg3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R1_CR1_MUX10_1[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[ulSRICIDX].ulBulk;
		R1_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r1g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r1g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r1g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r2g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r2g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX10_1[ulSRICIDX].tBit.cr1_r2g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;

		R1_CR1_MUX10_2[ulSRICIDX].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[ulSRICIDX].ulBulk;
		R1_CR1_MUX10_2[ulSRICIDX].tBit.cr1_r3g1 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX10_2[ulSRICIDX].tBit.cr1_r3g2 += gtTuning_Ctrl_Type.ulCR_OFFSET;
		R1_CR1_MUX10_2[ulSRICIDX].tBit.cr1_r3g3 += gtTuning_Ctrl_Type.ulCR_OFFSET;
	}

	MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&R0_CR1_MUX1_1[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&R0_CR1_MUX1_2[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0108), (uint32_t *)&R0_CR1_MUX2[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x010C), (uint32_t *)&R0_CR1_MUX3[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0110), (uint32_t *)&R0_CR1_MUX4[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0114), (uint32_t *)&R0_CR1_MUX5[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0118), (uint32_t *)&R0_CR1_MUX6[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x011C), (uint32_t *)&R0_CR1_MUX7[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0120), (uint32_t *)&R0_CR1_MUX8[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0124), (uint32_t *)&R0_CR1_MUX9[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0128), (uint32_t *)&R0_CR1_MUX10_1[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x012C), (uint32_t *)&R0_CR1_MUX10_2[0].ulBulk);

	MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0134), s_pktmoduleSRICCommonConf->R0_CFGR_TUNE_GROUP.ulBulk);

	MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&R1_CR1_MUX1_1[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&R1_CR1_MUX1_2[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0188), (uint32_t *)&R1_CR1_MUX2[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x018C), (uint32_t *)&R1_CR1_MUX3[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0190), (uint32_t *)&R1_CR1_MUX4[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0194), (uint32_t *)&R1_CR1_MUX5[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0198), (uint32_t *)&R1_CR1_MUX6[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x019C), (uint32_t *)&R1_CR1_MUX7[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x01A0), (uint32_t *)&R1_CR1_MUX8[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x01A4), (uint32_t *)&R1_CR1_MUX9[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x01A8), (uint32_t *)&R1_CR1_MUX10_1[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x01AC), (uint32_t *)&R1_CR1_MUX10_2[0].ulBulk);

	MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x01B4), s_pktmoduleSRICCommonConf->R1_CFGR_TUNE_GROUP.ulBulk);

	MSPI_RegisterWrite((uint32_t)(0x01C4), s_pktmoduleSRICCommonConf->CFGR_TUNE_LOWER.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x01C8), s_pktmoduleSRICCommonConf->CFGR_TUNE_UPPER.ulBulk);
#else /* USED_TOUCH_TUNING_PROCESS */
	MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0108), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX2[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x010C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX3[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0110), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX4[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0114), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX5[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0118), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX6[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x011C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX7[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0120), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX8[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0124), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX9[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0128), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x012C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[0].ulBulk);

	MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0134), s_pktmoduleSRICCommonConf->R0_CFGR_TUNE_GROUP.ulBulk);

	MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0188), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX2[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x018C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX3[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0190), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX4[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0194), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX5[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x0198), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX6[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x019C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX7[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x01A0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX8[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x01A4), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX9[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x01A8), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[0].ulBulk);
	MSPI_RegisterMultiWrite((uint32_t)(0x01AC), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[0].ulBulk);

	MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x01B4), s_pktmoduleSRICCommonConf->R1_CFGR_TUNE_GROUP.ulBulk);

	MSPI_RegisterWrite((uint32_t)(0x01C4), s_pktmoduleSRICCommonConf->CFGR_TUNE_LOWER.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x01C8), s_pktmoduleSRICCommonConf->CFGR_TUNE_UPPER.ulBulk);
#endif /* USED_TOUCH_TUNING_PROCESS */
}

static void SW92505_Reg_LHBSetting(uint32_t ulType)
{
	uint32_t ulIdx;
	for(ulIdx = 0; ulIdx < SW92505_MAX_LHB_NUM; ulIdx++)
	{
		MSPI_RegisterWrite((uint32_t)(0x009C + (0x4 * ulIdx)), s_pktmoduleSRICCommonConf->LHB_CFG[ulType][ulIdx].ulBulk);
	}
}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
static void SW92505_Reg_LHBSetting_ByChangeMode(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
	uint32_t ulIdx;
	tLHB_CFG_t * pLHB_CFG;
	switch(eMode)
	{
		case ROIC_REG_SET_CHAGNE_WGPPen_Local_Setting:
		{
			pLHB_CFG = &tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.LHB_CFG[0];
			break;
		}
		case ROIC_REG_SET_CHAGNE_MSPen_Local_Setting:
		{
			pLHB_CFG = &tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.LHB_CFG[0];
			break;
		}
	}
	for(ulIdx = 0; ulIdx < SW92505_MAX_LHB_NUM; ulIdx++)
	{
		MSPI_RegisterWrite((uint32_t)(0x009C + (0x4 * ulIdx)), pLHB_CFG[ulIdx].ulBulk);
	}
}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */

void SW92505_Initialize(void)
{
	s_pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
}

void SW92505_Reset(eSENSING_MODE_t eSensingMode)
{
	GPIO_Init(_GPIO_RSTN_SRIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
	delay_usec(100);

#if !USED_OPERATION_STAND_ALONE
	if(!IS_S3_MODE(eSensingMode))
	{
		while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 1);
		while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 0);
	}
	delay_usec(10);
#endif /* !USED_OPERATION_STAND_ALONE */
	_gOut(_GPIO_RSTN_SRIC, GPIO_DATA_LOW);
	delay_usec(10);
	_gOut(_GPIO_RSTN_SRIC, GPIO_DATA_HIGH);
	delay_usec(100);
}

#define ROIC_REG_NUM		(196)

#define SW92505_READ_WRITE_CHECK	(NO)
uint32_t ulTestReadBuf[MSPI_NUM];
tModuleSRICCommonConf_t tReadTestROICBuf[MSPI_NUM];
tCFGR_PRODUCT_ID_t tTestProductROICBuf[MSPI_NUM];
bool_t SW92505_RegisterInit(eSENSING_MODE_t eSensingMode)
{
	bool_t bReg = YES;
	uint32_t ulIdx;
//	uint32_t ulBuf[6];
//	uint16_t * pRegVal;

//	while(1)
//	{
//		MSPI_RegisterWrite((uint32_t)(0x0090), s_pktmoduleSRICCommonConf->CFGR_MUX_F_STUCK_VAL.ulBulk);
//		delay_msec(10);
//	}

//	MSPI_RegisterRead(0x400, &ulBuf[0], MSPI_READ_SM0_R0);

//	pRegVal = (uint32_t *)s_pktmoduleSRICCommonConf;
//
//	for (ulIdx = 0; ulIdx < ROIC_REG_NUM; ulIdx++)
//	{
//		MSPI_RegisterWrite((uint32_t)((ulIdx<<1) + 0x400), pRegVal[ulIdx]);
//	}

//	MSPI_RegisterWrite((uint32_t)(0x0000), s_pktmoduleSRICCommonConf->CFGR_PRODUCT_ID.ulBulk);
	MSPI_RegisterRead((uint32_t)(0x0000), (uint32_t *)&tTestProductROICBuf[0], MSPI_READ_SM0_R0);

	MSPI_RegisterWrite((uint32_t)(0x0004), s_pktmoduleSRICCommonConf->SPIS_CFG.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0004), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].SPIS_CFG.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */

	MSPI_RegisterWrite((uint32_t)(0x0008), s_pktmoduleSRICCommonConf->SPIS_ERROR_CLR.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x000C), s_pktmoduleSRICCommonConf->SPIS_ERROR_ST.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0010), s_pktmoduleSRICCommonConf->SPIS_PAD_CTL.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0010), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].SPIS_PAD_CTL.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0014), s_pktmoduleSRICCommonConf->CFGR_SYS_CFG.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0018), s_pktmoduleSRICCommonConf->CFGR_TC_START.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x001C), s_pktmoduleSRICCommonConf->CFGR_TC_STOP.ulBulk);


	MSPI_RegisterWrite((uint32_t)(0x0020), s_pktmoduleSRICCommonConf->CFGR_R0_CH_EN.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0020), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_R0_CH_EN.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */

	MSPI_RegisterWrite((uint32_t)(0x0024), s_pktmoduleSRICCommonConf->CFGR_R1_CH_EN.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0024), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_R1_CH_EN.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */

	MSPI_RegisterWrite((uint32_t)(0x0028), s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0028), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_MUX_EN.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x002C), s_pktmoduleSRICCommonConf->CFGR_MUX_DLY.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x002C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_MUX_DLY.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0030), s_pktmoduleSRICCommonConf->CFGR_DIC_CFG.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0030), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_DIC_CFG.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->CFGR_PWM_CTL.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0034), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_PWM_CTL.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0038), s_pktmoduleSRICCommonConf->CFGR_PWM_POS_CTL.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0038), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_PWM_POS_CTL.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x003C), s_pktmoduleSRICCommonConf->CFGR_PWM_DAT_CTL.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x003C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_PWM_DAT_CTL.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0040), s_pktmoduleSRICCommonConf->ND_CTRL.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0040), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].ND_CTRL.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0044), s_pktmoduleSRICCommonConf->CFGR_PWM_PRD.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0044), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_PWM_PRD.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->CFGR_SMPL_CTL.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0048), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_SMPL_CTL.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x004C), s_pktmoduleSRICCommonConf->CFGR_RSTP_NUM1.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x004C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_RSTP_NUM1.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0050), s_pktmoduleSRICCommonConf->CFGR_PHTCR_NUM1.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0050), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_PHTCR_NUM1.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0054), s_pktmoduleSRICCommonConf->CFGR_PHTCR_NUM2.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0054), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_PHTCR_NUM2.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0058), s_pktmoduleSRICCommonConf->CFGR_VCR_NUM1.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0058), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_VCR_NUM1.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x005C), s_pktmoduleSRICCommonConf->CFGR_VCR_EN_NUM1.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x005C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_VCR_EN_NUM1.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0060), s_pktmoduleSRICCommonConf->CFGR_VCR_EN_NUM2.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0060), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_VCR_EN_NUM2.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0064), s_pktmoduleSRICCommonConf->CFGR_PHTH0_NUM1.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0064), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_PHTH0_NUM1.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0068), s_pktmoduleSRICCommonConf->CFGR_PHTH1_NUM1.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0068), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_PHTH1_NUM1.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x006C), s_pktmoduleSRICCommonConf->CFGR_PHTH_NUM2.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x006C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_PHTH_NUM2.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0070), s_pktmoduleSRICCommonConf->CFGR_PHT_CTL.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0070), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_PHT_CTL.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0074), s_pktmoduleSRICCommonConf->CFGR_PHT_NUM1.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0074), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_PHT_NUM1.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0078), s_pktmoduleSRICCommonConf->CFGR_ADC_CTRL.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0078), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_ADC_CTRL.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x007C), s_pktmoduleSRICCommonConf->CFGR_VCOMR_OPT.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x007C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_VCOMR_OPT.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0080), s_pktmoduleSRICCommonConf->CFGR_BUF_OPT.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0080), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_BUF_OPT.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0084), s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[0].ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0088), s_pktmoduleSRICCommonConf->CFGR_ADC_IN.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0088), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_ADC_IN.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x008C), s_pktmoduleSRICCommonConf->CFGR_MUX_S_STUCK_VAL.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x008C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_MUX_S_STUCK_VAL.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0090), s_pktmoduleSRICCommonConf->CFGR_MUX_F_STUCK_VAL.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0090), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_MUX_F_STUCK_VAL.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0094), s_pktmoduleSRICCommonConf->CFGR_MUX_CFG_00.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0094), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_MUX_CFG_00.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */
	MSPI_RegisterWrite((uint32_t)(0x0098), s_pktmoduleSRICCommonConf->CFGR_MUX_CFG_01.ulBulk);
#if SW92505_READ_WRITE_CHECK
	MSPI_RegisterRead((uint32_t)(0x0098), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
	for(ulIdx=0; ulIdx<MSPI_NUM; ulIdx++)
	{
		tReadTestROICBuf[ulIdx].CFGR_MUX_CFG_01.ulBulk = ulTestReadBuf[ulIdx];
	}
#endif /* SW92505_READ_WRITE_CHECK */

	if(IS_FINGER_PEN_MODE(eSensingMode))
	{
		SW92505_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);
	}
	else
	{
		SW92505_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
	}

	MSPI_RegisterWrite((uint32_t)(0x00DC), s_pktmoduleSRICCommonConf->CFGR_PWM_SET_EN_BIT.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x00E0), s_pktmoduleSRICCommonConf->CFGR_LHB_MUX_CTRL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x00E4), s_pktmoduleSRICCommonConf->CFGR_PING_MUX_CTRL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x00E8), s_pktmoduleSRICCommonConf->CFGR_PRE_DRV_CTRL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x00EC), s_pktmoduleSRICCommonConf->CFGR_PEN_MUX_BIT_EN.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x00F0), s_pktmoduleSRICCommonConf->CFGR_PDRV_SUB_BIT_EN.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x00F4), s_pktmoduleSRICCommonConf->DFE_reserved1.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x00F8), s_pktmoduleSRICCommonConf->DFE_reserved2.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x00FC), s_pktmoduleSRICCommonConf->DFE_reserved3.ulBulk);
	SW92505_Reg_CRTuneSetting();
	MSPI_RegisterWrite((uint32_t)(0x01B8), s_pktmoduleSRICCommonConf->CFGR_SENSE_CTRL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x01BC), s_pktmoduleSRICCommonConf->CFGR_COMP_ADC_CTRL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x01C0), s_pktmoduleSRICCommonConf->CFGR_SSU_PW_CTRL.ulBulk);

	MSPI_RegisterWrite((uint32_t)(0x01CC), s_pktmoduleSRICCommonConf->TAFE_REV_SIG.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x01D0), s_pktmoduleSRICCommonConf->SYS_DUMMY0.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x01D4), s_pktmoduleSRICCommonConf->SYS_DUMMY1.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x01D8), s_pktmoduleSRICCommonConf->CFGR_COMP_CTRL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x01DC), s_pktmoduleSRICCommonConf->CFGR_COMP_RSTI_NUM.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x01E0), s_pktmoduleSRICCommonConf->CFGR_COMP_WINDOW_1.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x01E4), s_pktmoduleSRICCommonConf->CFGR_COMP_WINDOW_2.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x01E8), s_pktmoduleSRICCommonConf->COMP_STATUS.ulBulk);

//	{
//		tCFGR_DIC_CFG_t LOCAL_CFGR_DIC_CFG;
//		LOCAL_CFGR_DIC_CFG.ulBulk = s_pktmoduleSRICCommonConf->CFGR_DIC_CFG.ulBulk;
//		LOCAL_CFGR_DIC_CFG.tBit.sd_off = 1;
//		MSPI_RegisterWrite((uint32_t)(0x0030), LOCAL_CFGR_DIC_CFG.ulBulk);
//	}

	return bReg;
}

void SW92505_Run(uint8_t Enable)
{
	tCFGR_TC_START_t tCFGR_TC_START;
	tCFGR_SYS_CFG_t tCFGR_SYS_CFG;
	tCFGR_TC_START.ulBulk = 0;
	tCFGR_TC_START.tBit.tc_start = Enable;
	tCFGR_TC_START.tBit.scan_cont = Enable;
	MSPI_RegisterWrite((uint32_t)(0x018), tCFGR_TC_START.ulBulk);

	tCFGR_SYS_CFG.ulBulk = s_pktmoduleSRICCommonConf->CFGR_SYS_CFG.ulBulk;
	tCFGR_SYS_CFG.tBit.tg_reset = 1;
	MSPI_RegisterWrite((uint32_t)(0x0014), tCFGR_SYS_CFG.ulBulk);
	tCFGR_SYS_CFG.tBit.tg_reset = 0;
	MSPI_RegisterWrite((uint32_t)(0x0014), tCFGR_SYS_CFG.ulBulk);
}

static uint32_t ulLocalIndexAddress[16] =
{
	0x009C, 0x00A0,	0x00A4,	0x00A8,
	0x00AC,	0x00B0,	0x00B4,	0x00B8,
	0x00BC,	0x00C0,	0x00C4,	0x00C8,
	0x00CC,	0x00D0,	0x00D4,	0x00D8,
};

extern __IO uint16_t sensingRowStart_Tilt;
extern int8_t sensingRowStart_Tilt_Offset;
void SW92505_SetLocalIndex(uint32_t ulIdx)
{
	uint32_t _ulIndex;
	uint32_t ulLocalIndex;
	uint32_t ulMSPIIndex;
	uint32_t ulStartLHBIndex;
	uint32_t ulEndLHBIndex;
	tLHB_CFG_t tLHB_CFG;

	ulLocalIndex = (uint32_t)((ulIdx)&(0xFFFF));
	ulMSPIIndex = (uint32_t)((ulIdx)>>16);

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	switch(hal_Info_GetControlActivePenSettingType())
	{
		case ACTIVEPEN_TYPE_LOCAL_MS:
		{
			switch(ulMSPIIndex)
			{
				case 4:
				{
					ulStartLHBIndex = 5;
					ulEndLHBIndex = 6;
					break;
				}
				case 6:
				{
					ulStartLHBIndex = 9;
					ulEndLHBIndex = 12;
					break;
				}
				case 8:
				{
					ulStartLHBIndex = 13;
					ulEndLHBIndex = 15;
					break;
				}
				case 0:
				{
					ulStartLHBIndex = 1;
					ulEndLHBIndex = 4;
					break;
				}
			}
			break;
		}
		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			switch(ulMSPIIndex)
			{
				case 2:
				{
					ulStartLHBIndex = 5;
					ulEndLHBIndex = 7;
					break;
				}
				case 6:
				{
					ulStartLHBIndex = 9;
					ulEndLHBIndex = 12;
					break;
				}
				case 10:
				{
					ulStartLHBIndex = 13;
					ulEndLHBIndex = 15;
					break;
				}
				case 0:
				{
					ulStartLHBIndex = 1;
					ulEndLHBIndex = 4;
					break;
				}
			}
			break;
		}
	}
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
	switch(ulMSPIIndex)
	{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
		case 4:
		{
			ulStartLHBIndex = 5;
			ulEndLHBIndex = 6;
			break;
		}
		case 6:
		{
			ulStartLHBIndex = 9;
			ulEndLHBIndex = 12;
			break;
		}
		case 8:
		{
			ulStartLHBIndex = 13;
			ulEndLHBIndex = 15;
			break;
		}
		case 0:
		{
			ulStartLHBIndex = 1;
			ulEndLHBIndex = 4;
			break;
		}
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
		case 2:
		{
			ulStartLHBIndex = 5;
			ulEndLHBIndex = 7;
			break;
		}
		case 6:
		{
			ulStartLHBIndex = 9;
			ulEndLHBIndex = 12;
			break;
		}
		case 10:
		{
			ulStartLHBIndex = 13;
			ulEndLHBIndex = 15;
			break;
		}
		case 0:
		{
			ulStartLHBIndex = 1;
			ulEndLHBIndex = 4;
			break;
		}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) */
	}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
	
	tHalIntrHandle.ulLocalSensingDoneRowIdx = ulLocalIndex;
#ifdef TILT_ON
	if((ulMSPIIndex == 0 || ulMSPIIndex == 6) && hal_Info_GetControlActivePenSettingType() == ACTIVEPEN_TYPE_LOCAL_WGP)
	{
		tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt = MAX(0,MIN(ROW_MAX-PEN_COORD_ROW_MAX,(int)(ulLocalIndex + sensingRowStart_Tilt_Offset)));
		//tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt;
	}
	else if((ulMSPIIndex == 0 || ulMSPIIndex == 6) && hal_Info_GetControlActivePenSettingType() == ACTIVEPEN_TYPE_LOCAL_MS)
	{
		sensingRowStart_Tilt = tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = MAX(0,MIN(ROW_MAX-PEN_COORD_ROW_MAX,(int)(ulLocalIndex + sensingRowStart_Tilt_Offset)));
		//tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt;
	}
#endif /* TILT_ON */

	for(_ulIndex = ulStartLHBIndex; _ulIndex <= ulEndLHBIndex; _ulIndex++)
	{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		switch(hal_Info_GetControlActivePenSettingType())
		{
			case ACTIVEPEN_TYPE_LOCAL_MS:
			{
				tLHB_CFG.ulBulk = tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.LHB_CFG[_ulIndex].ulBulk;
				break;
			}
			case ACTIVEPEN_TYPE_LOCAL_WGP:
			{
				tLHB_CFG.ulBulk = tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.LHB_CFG[_ulIndex].ulBulk;
				break;
			}
		}
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
		tLHB_CFG.ulBulk = s_pktmoduleSRICCommonConf->LHB_CFG[PWM_LOCAL_PEN_MODE][_ulIndex].ulBulk;
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */

		if(tLHB_CFG.tBit.mode == SW92505_MODE_PEN_POS ||
			tLHB_CFG.tBit.mode == SW92505_MODE_PEN_DATA)
		{
#ifdef TILT_ON
			uint8_t shift_val = 0;
			uint8_t shift_direc = 0;
			if( ((ulMSPIIndex == 0 && _ulIndex == 4) || (ulMSPIIndex == 6 && _ulIndex == 12)) &&
				hal_Info_GetControlActivePenSettingType() == ACTIVEPEN_TYPE_LOCAL_WGP)
			{
				tLHB_CFG.tBit.local_pos0 = sensingRowStart_Tilt;
			}
			else if(hal_Info_GetControlActivePenSettingType() == ACTIVEPEN_TYPE_LOCAL_MS && ((ulMSPIIndex == 6 && _ulIndex == 9) || (ulMSPIIndex == 0 && _ulIndex == 4)))
			{
				if(ulLocalIndex != sensingRowStart_Tilt)
				{
					shift_val = 1;
					if(sensingRowStart_Tilt > ulLocalIndex)shift_direc = 1;
				}
				tLHB_CFG.tBit.local_pos0 = ulLocalIndex;
				tLHB_CFG.tBit.local_pos1 = shift_val;
				tLHB_CFG.tBit.local_pos2 = shift_direc;
			}
			else
#endif /* TILT_ON */
			{
				tLHB_CFG.tBit.local_pos0 = ulLocalIndex;
				tLHB_CFG.tBit.local_pos1 = 0;
				tLHB_CFG.tBit.local_pos2 = 0;
			}
			MSPI_RegisterWrite(ulLocalIndexAddress[_ulIndex], tLHB_CFG.ulBulk);
		}
	}
}

void SW92505_SetIdleOperationMode(void)
{
//	if((PARAMSET_PWMDRV_TSYNC_IDLE_BITMASK & 0x1) && 0x1)
//	{
//		tCFGR_PEN_POS1_t tCFGR_PEN_POS1;
//		tCFGR_PEN_POS1.ulBulk = s_pktmoduleSRICCommonConf->CFGR_PEN_POS1.ulBulk;
//		tCFGR_PEN_POS1.tBit.lhb_type = 1; // Finger2
//		MSPI_RegisterWrite(0x406, tCFGR_PEN_POS1.ulBulk);
//	}
//
////	tCFGR_LHB_CFG1_t tCFGR_LHB_CFG1;
////	tCFGR_LHB_CFG1.ulBulk = s_pktmoduleSRICCommonConf->CFGR_LHB_CFG1.ulBulk;
////	tCFGR_LHB_CFG1.tBit.md2_lhb_mux = 1;
////	MSPI_RegisterWrite(0x49E, tCFGR_LHB_CFG1.ulBulk);
//
//	tCFGR_LHB_CFG2_t tCFGR_LHB_CFG2;
//	tCFGR_LHB_CFG2.ulBulk = s_pktmoduleSRICCommonConf->CFGR_LHB_CFG2.ulBulk;
//	tCFGR_LHB_CFG2.tBit.end_mux_num = 1;
//	MSPI_RegisterWrite(0x4A0, tCFGR_LHB_CFG2.ulBulk);
	
//	uint16_t tCFGR_MD2_MUX_SEL1;
//	tCFGR_MD2_MUX_SEL1 = 0x0FFF;
//	MSPI_RegisterWrite(0x484, tCFGR_MD2_MUX_SEL1);
}

void SW92505_SetActiveOperationMode(void)
{
//	if((PARAMSET_PWMDRV_TSYNC_ACTIVE_BITMASK & 0x1) && 0x1)
//	{
//		tCFGR_PEN_POS1_t tCFGR_PEN_POS1;
//		tCFGR_PEN_POS1.ulBulk = s_pktmoduleSRICCommonConf->CFGR_PEN_POS1.ulBulk;
//		tCFGR_PEN_POS1.tBit.lhb_type = 0; // Finger2
//		MSPI_RegisterWrite(0x406, tCFGR_PEN_POS1.ulBulk);
//	}
//
//	tCFGR_LHB_CFG2_t tCFGR_LHB_CFG2;
//	tCFGR_LHB_CFG2.ulBulk = s_pktmoduleSRICCommonConf->CFGR_LHB_CFG2.ulBulk;
//	tCFGR_LHB_CFG2.tBit.end_mux_num = 0xC;
//	MSPI_RegisterWrite(0x4A0, tCFGR_LHB_CFG2.ulBulk);
}

//void SW92505_SetFingerPenFullModeChange(bool_t bIsFullMode)
//{
//	if(bIsFullMode)
//	{
//		SW92505_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
//	}
//	else
//	{
//		SW92505_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);
//	}
//}

#if (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL)
tR0_CR_GTUNE_t R0_Idle_CR_GTUNE[6] =
{
	[0] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_0_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_0_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_0_R0_CR_GTUNE_PenData_Global_Tune,
	},
	[1] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_1_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_1_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_1_R0_CR_GTUNE_PenData_Global_Tune,
	},
	[2] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_2_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_2_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_2_R0_CR_GTUNE_PenData_Global_Tune,
	},
	[3] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_3_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_3_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_3_R0_CR_GTUNE_PenData_Global_Tune,
	},
	[4] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_4_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_4_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_4_R0_CR_GTUNE_PenData_Global_Tune,
	},
	[5] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_5_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_5_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_5_R0_CR_GTUNE_PenData_Global_Tune,
	},
};

tR1_CR_GTUNE_t R1_Idle_CR_GTUNE[6] =
{
	[0] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_0_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_0_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_0_R1_CR_GTUNE_PenData_Global_Tune,
	},
	[1] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_1_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_1_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_1_R1_CR_GTUNE_PenData_Global_Tune,
	},
	[2] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_2_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_2_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_2_R1_CR_GTUNE_PenData_Global_Tune,
	},
	[3] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_3_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_3_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_3_R1_CR_GTUNE_PenData_Global_Tune,
	},
	[4] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_4_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_4_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_4_R1_CR_GTUNE_PenData_Global_Tune,
	},
	[5] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_5_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_5_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_5_R1_CR_GTUNE_PenData_Global_Tune,
	},
};

tR0_CR1_MUX1_1_t R0_Idle_CR1_MUX1_1[6] =
{
	[0] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Middle_Line_g3,
	},
	[1] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Middle_Line_g3,
	},
	[2] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Middle_Line_g3,
	},
	[3] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Middle_Line_g3,
	},
	[4] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Middle_Line_g3,
	},
	[5] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Middle_Line_g3,
	},
};
tR0_CR1_MUX1_2_t R0_Idle_CR1_MUX1_2[6] =
{
	[0] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Bottom_Line_g3,
	},
	[1] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Bottom_Line_g3,
	},
	[2] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Bottom_Line_g3,
	},
	[3] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Bottom_Line_g3,
	},
	[4] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Bottom_Line_g3,
	},
	[5] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Bottom_Line_g3,
	},
};
tR1_CR1_MUX1_1_t R1_Idle_CR1_MUX1_1[6] =
{
	[0] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Middle_Line_g3,
	},
	[1] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Middle_Line_g3,
	},
	[2] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Middle_Line_g3,
	},
	[3] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Middle_Line_g3,
	},
	[4] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Middle_Line_g3,
	},
	[5] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Middle_Line_g3,
	},
};
tR1_CR1_MUX1_2_t R1_Idle_CR1_MUX1_2[6] =
{
	[0] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Bottom_Line_g3,
	},
	[1] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Bottom_Line_g3,
	},
	[2] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Bottom_Line_g3,
	},
	[3] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Bottom_Line_g3,
	},
	[4] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Bottom_Line_g3,
	},
	[5] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Bottom_Line_g3,
	},
};

tCFGR_PWM_CTL_t CFGR_Idle_PWM_CTL =
{
	.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_pdrv_num,
	.tBit.pwm_act_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_act_num,
	.tBit.pwm_smpl_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_smpl_num,
	.tBit.pwm_dum_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_dum_num,
	.tBit.pdrv_dum_num = PARAMSET_ROIC_PWM_IDLE_CTL_pdrv_dum_num,
	.tBit.pwm_set_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_set_num,
};

tCFGR_PEN_MUX_BIT_EN_t CFGR_PEN_IDLE_MUX_BIT_EN =
{
	.tBit.mux_beacon_bit_en = PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_beacon_bit_en,
	.tBit.mux_pen_pos_bit_en = PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_pen_pos_bit_en,
	.tBit.mux_pen_dat_bit_en = PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_pen_dat_bit_en,
};
#endif /* (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL) */

void SW92505_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
	switch(eMode)
	{
		case ROIC_REG_SET_CHANGE_MUX_REMAP:
		{
			break;
		}
		case ROIC_REG_SET_CHAGNE_CR_TUNE:
		{
			SW92505_Reg_CRTuneSetting();
			break;
		}
		case ROIC_REG_SET_CHAGNE_WGPPen_Local_Setting: // WGP Local
		{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			MSPI_RegisterWrite((uint32_t)(0x0034), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0038), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_POS_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x003C), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_DAT_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0040), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.ND_CTRL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0044), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_PRD.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x004C), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_RSTP_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0050), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0054), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTCR_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0058), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_VCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x005C), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_VCR_EN_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0064), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTH0_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0068), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTH1_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x006C), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTH_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0074), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHT_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x00DC), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_SET_EN_BIT.ulBulk);
			SW92505_Reg_LHBSetting_ByChangeMode(ROIC_REG_SET_CHAGNE_WGPPen_Local_Setting);
			MSPI_RegisterWrite((uint32_t)(0x01B8), tSW92505ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_SENSE_CTRL.ulBulk);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
			break;
		}
		case ROIC_REG_SET_CHAGNE_WGPPen_Full_Setting: // WGP Full
		{
			break;
		}
		case ROIC_REG_SET_CHAGNE_MSPen_Local_Setting: // MS Local
		{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			MSPI_RegisterWrite((uint32_t)(0x0034), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0038), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_POS_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x003C), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_DAT_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0040), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.ND_CTRL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0044), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_PRD.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x004C), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_RSTP_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0050), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0054), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTCR_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0058), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_VCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x005C), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_VCR_EN_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0064), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTH0_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0068), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTH1_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x006C), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTH_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0074), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHT_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x00DC), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_SET_EN_BIT.ulBulk);
			SW92505_Reg_LHBSetting_ByChangeMode(ROIC_REG_SET_CHAGNE_MSPen_Local_Setting);
			MSPI_RegisterWrite((uint32_t)(0x01B8), tSW92505ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_SENSE_CTRL.ulBulk);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
			break;
		}
		case ROIC_REG_SET_CHAGNE_MSPen_Full_Setting: // MS Full
		{
			break;
		}

#if USED_PEN_MODE_OPERATION
		case ROIC_REG_SET_CHANGE_Full_To_Local:
		{
			SW92505_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);

			break;
		}
		case ROIC_REG_SET_CHANGE_Local_To_Full:
		{
			SW92505_Reg_LHBSetting(PWM_FULL_FINGER_MODE);

			break;
		}
#endif /* USED_PEN_MODE_OPERATION */
#if USED_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_Full_To_FullIdle:
		{
			break;
		}
#endif /* USED_IDLE_MODE_CONTROL */
#if USED_LOCAL_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_Local_To_LocalIdle:
		{
			break;
		}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
#if USED_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_FullIdle_To_Full:
		{
			break;
		}
#endif /* USED_IDLE_MODE_CONTROL */
#if USED_LOCAL_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_LocalIdle_To_Local:
		{
			break;
		}
		case ROIC_REG_SET_CHANGE_LocalIdle_To_Full:
		{
			break;
		}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
#if USED_NOISE_HOPPING_FREQ
		case ROIC_REG_SET_FreHopp_CHANGE_Main_Freq:
		{
			break;
		}
		case ROIC_REG_SET_FreHopp_CHANGE_Hopp1_Freq:
		{
			break;
		}
#endif /* USED_NOISE_HOPPING_FREQ */
//		case ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_ACTIVE:
//		{
//			SW92505_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);
//#if USED_LOCAL_IDLE_MODE_CONTROL
//			if(IS_IDLE_MODE(HAL_GetSensingMode()))
//			{
//				MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);
//				MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);
//
//				MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[0].ulBulk);
//				MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[0].ulBulk);
//				MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[0].ulBulk);
//				MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[0].ulBulk);
//
//				MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->CFGR_PWM_CTL.ulBulk);
//				MSPI_RegisterWrite((uint32_t)(0x00EC), s_pktmoduleSRICCommonConf->CFGR_PEN_MUX_BIT_EN.ulBulk);
//			}
//#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
//			break;
//		}
//#if (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL)
//		case ROIC_REG_SET_CHANGE_FINGER_PEN_FULL_IDLE:
//		case ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_IDLE:
//		{
//			SW92505_Reg_LHBSetting(PWM_LOCAL_PEN_IDLE_MODE);
//
//			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&R0_Idle_CR_GTUNE[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&R1_Idle_CR_GTUNE[0].ulBulk);
//
//			MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&R0_Idle_CR1_MUX1_1[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&R0_Idle_CR1_MUX1_2[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&R1_Idle_CR1_MUX1_1[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&R1_Idle_CR1_MUX1_2[0].ulBulk);
//
//			MSPI_RegisterWrite((uint32_t)(0x0034), CFGR_Idle_PWM_CTL.ulBulk);
//			MSPI_RegisterWrite((uint32_t)(0x00EC), CFGR_PEN_IDLE_MUX_BIT_EN.ulBulk);
//			break;
//		}
//#endif /* (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL) */
//		case ROIC_REG_SET_CHANGE_FINGER_PEN_FULL:
//		{
//			SW92505_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
//#if (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL)
//			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);
//
//			MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[0].ulBulk);
//
//			MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->CFGR_PWM_CTL.ulBulk);
//			MSPI_RegisterWrite((uint32_t)(0x00EC), s_pktmoduleSRICCommonConf->CFGR_PEN_MUX_BIT_EN.ulBulk);
//#endif /* (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL) */
//			break;
//		}
	}
}

#if USED_RAWDATA_TUNE_CALIBRATION
#define DEF_ROIC_TUNE_ROW_GROUP_NUM			(13)
#define DEF_ROIC_TUNE_COL_GROUP_NUM			(3)
bool_t bIsAutoCalFinish = NO;
uint32_t ulTestFrameNum = 0;
uint32_t ulTestCountNum = 0;

uint32_t RawValue_sum_R0[DEF_ROIC_TUNE_ROW_GROUP_NUM][MSPI_NUM][DEF_ROIC_TUNE_COL_GROUP_NUM];
uint32_t RawValue_sum_R1[DEF_ROIC_TUNE_ROW_GROUP_NUM][MSPI_NUM][DEF_ROIC_TUNE_COL_GROUP_NUM];
uint8_t RawSumCnt_R0[DEF_ROIC_TUNE_ROW_GROUP_NUM][MSPI_NUM][DEF_ROIC_TUNE_COL_GROUP_NUM];
uint8_t RawSumCnt_R1[DEF_ROIC_TUNE_ROW_GROUP_NUM][MSPI_NUM][DEF_ROIC_TUNE_COL_GROUP_NUM];

uint16_t RawValue_R0[DEF_ROIC_TUNE_ROW_GROUP_NUM][MSPI_NUM][DEF_ROIC_TUNE_COL_GROUP_NUM];
uint16_t RawValue_R1[DEF_ROIC_TUNE_ROW_GROUP_NUM][MSPI_NUM][DEF_ROIC_TUNE_COL_GROUP_NUM];


uint8_t AutoCalfinish_R0[DEF_ROIC_TUNE_ROW_GROUP_NUM][MSPI_NUM][DEF_ROIC_TUNE_COL_GROUP_NUM];
uint8_t AutoCalfinish_R1[DEF_ROIC_TUNE_ROW_GROUP_NUM][MSPI_NUM][DEF_ROIC_TUNE_COL_GROUP_NUM];

uint8_t ulCRIndex[ROW_MAX] = {
	/*1 Mux*/0,1,1,1,2,
	/*2 Mux*/3,3,3,3,3,
	/*3 Mux*/4,4,4,4,4,
	/*4 Mux*/5,5,5,5,5,
	/*5 Mux*/6,6,6,6,6,
	/*6 Mux*/7,7,7,7,7,
	/*7 Mux*/8,8,8,8,8,
	/*8 Mux*/9,9,9,9,9,
	/*9 Mux*/10,11,11,11,12
};

uint8_t ulMSPIIndex[COL_MAX] = {
	/*SRIC_0*/ /*R0*/0,	0,	0,	0,	0,	0,	0,	/*R1*/5,	5,	5,	5,	5,	5,	5,
	/*SRIC_1*/ /*R0*/1,	1,	1,	1,	1,	1,	1,	/*R1*/6,	6,	6,	6,	6,	6,	6,
	/*SRIC_2*/ /*R0*/2,	2,	2,	2,	2,	2,	2,	/*R1*/7,	7,	7,	7,	7,	7,	7,
	/*SRIC_3*/ /*R0*/3,	3,	3,	3,	3,	3,	3,	/*R1*/8,	8,	8,	8,	8,	8,	8,
	/*SRIC_4*/ /*R0*/4,	4,	4,	4,	4,	4,	4,	/*R1*/9,	9,	9,	9,	9,	9,	9,
};

uint8_t ulROIC_gNum[COL_MAX] = {
	/* Group Idx */ /*R0*/0,	1,	1,	1,	1,	1,	2,	/*R1*/2,	1,	1,	1,	1,	1,	0,
	/* Group Idx */ /*R0*/0,	1,	1,	1,	1,	1,	2,	/*R1*/2,	1,	1,	1,	1,	1,	0,
	/* Group Idx */ /*R0*/0,	1,	1,	1,	1,	1,	2,	/*R1*/2,	1,	1,	1,	1,	1,	0,
	/* Group Idx */ /*R0*/0,	1,	1,	1,	1,	1,	2,	/*R1*/2,	1,	1,	1,	1,	1,	0,
	/* Group Idx */ /*R0*/0,	1,	1,	1,	1,	1,	2,	/*R1*/2,	1,	1,	1,	1,	1,	0,
};

uint8_t ucROIC_RegIdx_DubleCheck[DEF_ROIC_TUNE_ROW_GROUP_NUM] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0
};
uint8_t ucROIC_CRRegIdx[DEF_ROIC_TUNE_ROW_GROUP_NUM] = {
	0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 10, 11
};

uint32_t Change_CR_Value = 0;
uint32_t auto_Cal_Start = 0;

uint32_t auto_Cal_MiddleStart = 0;

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
}__PACKED tSW92505_ROIC_CR_MUX_t;

extern tParamPreMainSet_t * s_ptParamPreMainSet;
tModuleSRICCommonConf_t * g_ptSRICConfig;

tSW92505_ROIC_CR_MUX_t * g_pR0_CR_MUX_Tune;
tSW92505_ROIC_CR_MUX_t * g_pR1_CR_MUX_Tune;
bool_t bISAllFinish = NO;
uint16_t usTemp_RawData;

#define AUTO_CAL_AVERAGE_FRAME_NUM			(100)
#define AUTO_CAL_AVERAGE_SKIP_FRAME_NUM		(10) // Avoid GIP Offset Noise
void SW92505_RawDataCalibration(void)
{
	bool_t bIsLoop = YES;
	uint32_t r, c, g, framenum, framenum_2;
	uint32_t ulReal_Col;
	uint32_t ulROIC_Reg_r_Idx;
	uint32_t ulROIC_Reg_Idx;
	uint32_t temp_data;
	int16_t sPosTempDiff;
	int16_t sNegTempDiff;
#if USED_ONLY_LOCAL_MODE
	ePartialSensing_t lDataIndex = PARTIAL_PEN_BEACON;
#endif /* USED_ONLY_LOCAL_MODE */

	g_ptSRICConfig = (tModuleSRICCommonConf_t *)&(s_ptParamPreMainSet->tParamCommonConf.tModule.tSRIC_Conf);
	g_pR0_CR_MUX_Tune = (tSW92505_ROIC_CR_MUX_t *)&g_ptSRICConfig->R0_CR1_MUX1_1[0].ulBulk;
	g_pR1_CR_MUX_Tune = (tSW92505_ROIC_CR_MUX_t *)&g_ptSRICConfig->R1_CR1_MUX1_1[0].ulBulk;

	memset((void*)(&AutoCalfinish_R0[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_TUNE_ROW_GROUP_NUM*MSPI_NUM*DEF_ROIC_TUNE_COL_GROUP_NUM);
	memset((void*)(&AutoCalfinish_R1[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_TUNE_ROW_GROUP_NUM*MSPI_NUM*DEF_ROIC_TUNE_COL_GROUP_NUM);

    tHalIntrHandle.ulLocalIndexChangeStart = 1;
#if (USED_ONLY_LOCAL_MODE == NO)
	if(IS_FINGER_PEN_MODE(HAL_GetSensingMode()))
	{
		HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);
	}
#endif /* (USED_ONLY_LOCAL_MODE == NO) */

#if (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO)
	for(r=0; r<DEF_ROIC_TUNE_ROW_GROUP_NUM; r++)
	{
		ulROIC_Reg_r_Idx = ucROIC_RegIdx_DubleCheck[r];
		ulROIC_Reg_Idx = ucROIC_CRRegIdx[r];
		ulReal_Col = 0;
		for(c=0; c<MSPI_NUM; c++)
		{
			if(ulROIC_Reg_r_Idx == 0)
			{
				g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g1 = 0;
				g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g1 = 0;
				ulReal_Col++;

				g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g2 = 0;
				g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g2 = 0;
				ulReal_Col++;

				g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g3 = 0;
				g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g3 = 0;
				ulReal_Col++;
			}
			else
			{
				g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g1 = 0;
				g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g1 = 0;
				ulReal_Col++;

				g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g2 = 0;
				g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g2 = 0;
				ulReal_Col++;

				g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g3 = 0;
				g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g3 = 0;
				ulReal_Col++;
			}
		}
	}

#if USED_ONLY_LOCAL_MODE
	framenum = 0;
	while(1)
	{
		lDataIndex = module_wait_local_sample_done();
		if(lDataIndex == LOCAL_OP_LAST_LHB)
		{
			framenum++;
			if(framenum == 100)
			{
				break;
			}
		}
	}
#else /* USED_ONLY_LOCAL_MODE */
    for( framenum=0; framenum<100; framenum++ )
    {
    	module_wait_full_sample_done();
    }
#endif /* USED_ONLY_LOCAL_MODE */

#endif /* (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO) */

	while(bIsLoop)
	{
#ifdef MODE_WDT
		KICK_DOG();
#endif /* MODE_WDT */

#if USED_ONLY_LOCAL_MODE
	    while(YES)
	    {
			lDataIndex = module_wait_local_sample_done();

			if(lDataIndex == LOCAL_FINGER_LAST_LHB)
			{
				break;
			}
		}
#else /* USED_ONLY_LOCAL_MODE */
		module_wait_full_sample_done();
#endif /* USED_ONLY_LOCAL_MODE */

		protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);
		protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);

#if (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO)
		if(bIsAutoCalFinish == NO)
		{
			ulTestCountNum++;
			/*
			 * RawData Sum
			 */
			memset((void*)(HAL_GET_COMMON_IMAGE_PTR()), 0, sizeof(uint32_t)*COL_MAX*ROW_MAX);

			ulTestFrameNum = 0;
			for(framenum = 0; framenum < AUTO_CAL_AVERAGE_FRAME_NUM; framenum++)
			{
				{
	#if USED_ONLY_LOCAL_MODE
					framenum_2 = 0;
					while(1)
					{
						lDataIndex = module_wait_local_sample_done();
						if(lDataIndex == LOCAL_OP_LAST_LHB)
						{
							framenum_2++;
							if(framenum_2 == AUTO_CAL_AVERAGE_SKIP_FRAME_NUM)
							{
								break;
							}
						}
					}
	#else /* USED_ONLY_LOCAL_MODE */
					for( framenum_2=0; framenum_2<AUTO_CAL_AVERAGE_SKIP_FRAME_NUM; framenum_2++ )
					{
						module_wait_full_sample_done();
					}
	#endif /* USED_ONLY_LOCAL_MODE */
				}

				ulTestFrameNum++;
#ifdef MODE_WDT
				KICK_DOG();
#endif /* MODE_WDT */
#if USED_ONLY_LOCAL_MODE
			    while(YES)
			    {
					lDataIndex = module_wait_local_sample_done();

					if(lDataIndex == LOCAL_FINGER_LAST_LHB)
					{
						break;
					}
				}
#else /* USED_ONLY_LOCAL_MODE */
				module_wait_full_sample_done();
#endif /* USED_ONLY_LOCAL_MODE */
				for( r=ROW_MAX; r--; )
				{
					for( c=COL_MAX; c--; )
					{
						temp_data = HAL_READ_COMMON_IMAGE(r, c) + (uint32_t)HAL_READ_RAW_IMAGE(r, c);
						HAL_WRITE_COMMON_IMAGE(r, c, temp_data);
					}
				}
			}

			for( r=ROW_MAX; r--; )
			{
				for( c=COL_MAX; c--; )
				{
					temp_data = HAL_READ_COMMON_IMAGE(r, c) / ulTestFrameNum;
					HAL_WRITE_COMMON_IMAGE(r, c, temp_data);
				}
			}

			memset((void*)(&RawValue_sum_R0[0][0][0]), 0, sizeof(uint32_t)*DEF_ROIC_TUNE_ROW_GROUP_NUM*MSPI_NUM*DEF_ROIC_TUNE_COL_GROUP_NUM);
			memset((void*)(&RawValue_sum_R1[0][0][0]), 0, sizeof(uint32_t)*DEF_ROIC_TUNE_ROW_GROUP_NUM*MSPI_NUM*DEF_ROIC_TUNE_COL_GROUP_NUM);

			memset((void*)(&RawSumCnt_R0[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_TUNE_ROW_GROUP_NUM*MSPI_NUM*DEF_ROIC_TUNE_COL_GROUP_NUM);
			memset((void*)(&RawSumCnt_R1[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_TUNE_ROW_GROUP_NUM*MSPI_NUM*DEF_ROIC_TUNE_COL_GROUP_NUM);

			for( r=ROW_MAX; r--; )
			{
				for( c=COL_MAX; c--; )
				{
					temp_data = HAL_READ_COMMON_IMAGE(r, c);
					if(ulMSPIIndex[c] < MSPI_NUM)
					{
						RawValue_sum_R0[ulCRIndex[r]][ulMSPIIndex[c]][ulROIC_gNum[c]] += temp_data;
						RawSumCnt_R0[ulCRIndex[r]][ulMSPIIndex[c]][ulROIC_gNum[c]]++;
					}
					else
					{
						RawValue_sum_R1[ulCRIndex[r]][ulMSPIIndex[c]-MSPI_NUM][ulROIC_gNum[c]] += temp_data;
						RawSumCnt_R1[ulCRIndex[r]][ulMSPIIndex[c]-MSPI_NUM][ulROIC_gNum[c]]++;
					}
				}
			}

			for( r=DEF_ROIC_TUNE_ROW_GROUP_NUM; r--; )
			{
				for( c=MSPI_NUM; c--; )
				{
					for(g=DEF_ROIC_TUNE_COL_GROUP_NUM; g--; )
					{
						ulROIC_Reg_r_Idx = ucROIC_RegIdx_DubleCheck[r];
						ulROIC_Reg_Idx = ucROIC_CRRegIdx[r];

						if(AutoCalfinish_R0[r][c][g] == 0)
						{
							usTemp_RawData = (uint16_t)(RawValue_sum_R0[r][c][g]/RawSumCnt_R0[r][c][g]);

							if(RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL < usTemp_RawData)
							{
								switch(g)
								{
									case 0:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g1 += 1;
										}
										else
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g1 += 1;
										}
										break;
									}
									case 1:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g2 += 1;
										}
										else
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g2 += 1;
										}
										break;
									}
									case 2:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g3 += 1;
										}
										else
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g3 += 1;
										}
										break;
									}
								}
							}
							else
							{
								sNegTempDiff = RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL - (int16_t)usTemp_RawData;
								sPosTempDiff = (int16_t)RawValue_R0[r][c][g] - RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL;
								if(sPosTempDiff < sNegTempDiff)
								{
									switch(g)
									{
										case 0:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g1 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g1 -= 1;
												}
											}
											else
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g1 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g1 -= 1;
												}
											}
											break;
										}
										case 1:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g2 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g2 -= 1;
												}
											}
											else
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g2 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g2 -= 1;
												}
											}
											break;
										}
										case 2:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g3 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g3 -= 1;
												}
											}
											else
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g3 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g3 -= 1;
												}
											}
											break;
										}
									}
								}
								AutoCalfinish_R0[r][c][g] = 1;
							}

							RawValue_R0[r][c][g] = usTemp_RawData;
						}

						if(AutoCalfinish_R1[r][c][g] == 0)
						{
							usTemp_RawData = (uint16_t)(RawValue_sum_R1[r][c][g]/RawSumCnt_R1[r][c][g]);
							if(RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL < usTemp_RawData)
							{
								switch(g)
								{
									case 0:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g1 += 1;
										}
										else
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g1 += 1;
										}
										break;
									}
									case 1:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g2 += 1;
										}
										else
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g2 += 1;
										}
										break;
									}
									case 2:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g3 += 1;
										}
										else
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g3 += 1;
										}
										break;
									}
								}
							}
							else
							{
								sNegTempDiff = RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL - usTemp_RawData;
								sPosTempDiff = RawValue_R1[r][c][g] - RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL;
								if(sPosTempDiff < sNegTempDiff)
								{
									switch(g)
									{
										case 0:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g1 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g1 -= 1;
												}
											}
											else
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g1 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g1 -= 1;
												}
											}
											break;
										}
										case 1:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g2 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g2 -= 1;
												}
											}
											else
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g2 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g2 -= 1;
												}
											}
											break;
										}
										case 2:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g3 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g3 -= 1;
												}
											}
											else
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g3 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g3 -= 1;
												}
											}
											break;
										}
									}
								}
								AutoCalfinish_R1[r][c][g] = 1;
							}

							RawValue_R1[r][c][g] = usTemp_RawData;
						}
					}
				}
			}

			bISAllFinish = YES;
			for( r=DEF_ROIC_TUNE_ROW_GROUP_NUM; r--; )
			{
				for( c=MSPI_NUM; c--; )
				{
					for(g=DEF_ROIC_TUNE_COL_GROUP_NUM; g--; )
					{
						if(AutoCalfinish_R0[r][c][g] == 0)
						{
							bISAllFinish = NO;
						}
						if(AutoCalfinish_R1[r][c][g] == 0)
						{
							bISAllFinish = NO;
						}
					}
				}
			}

			if(bISAllFinish)
			{
				bIsAutoCalFinish = YES;

				for(r=0; r<DEF_ROIC_TUNE_ROW_GROUP_NUM; r++)
				{
					ulROIC_Reg_r_Idx = ucROIC_RegIdx_DubleCheck[r];
					ulROIC_Reg_Idx = ucROIC_CRRegIdx[r];
					ulReal_Col = 0;
					for(c=0; c<MSPI_NUM; c++)
					{
						if(ulROIC_Reg_r_Idx == 0)
						{
							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g1;
							HAL_WRITE_DELTA_IMAGE(r, ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g1;
							HAL_WRITE_DELTA_IMAGE(r + DEF_ROIC_TUNE_ROW_GROUP_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;

							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g2;
							HAL_WRITE_DELTA_IMAGE(r, ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g2;
							HAL_WRITE_DELTA_IMAGE(r + DEF_ROIC_TUNE_ROW_GROUP_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;

							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g3;
							HAL_WRITE_DELTA_IMAGE(r, ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r1g3;
							HAL_WRITE_DELTA_IMAGE(r + DEF_ROIC_TUNE_ROW_GROUP_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;
						}
						else
						{
							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g1;
							HAL_WRITE_DELTA_IMAGE(r, ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g1;
							HAL_WRITE_DELTA_IMAGE(r + DEF_ROIC_TUNE_ROW_GROUP_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;

							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g2;
							HAL_WRITE_DELTA_IMAGE(r, ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g2;
							HAL_WRITE_DELTA_IMAGE(r + DEF_ROIC_TUNE_ROW_GROUP_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;

							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g3;
							HAL_WRITE_DELTA_IMAGE(r, ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr1_r2g3;
							HAL_WRITE_DELTA_IMAGE(r + DEF_ROIC_TUNE_ROW_GROUP_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;
						}
					}
				}
			}
			else
			{
				Change_CR_Value = 1;
			}

			if(Change_CR_Value)
			{
				Change_CR_Value = 0;
				HAL_SetROICRegSetChangeMode(ROIC_REG_SET_CHAGNE_CR_TUNE);
#if USED_ONLY_LOCAL_MODE
			    while(YES)
			    {
					lDataIndex = module_wait_local_sample_done();

					if(lDataIndex == LOCAL_OP_LAST_LHB)
					{
						break;
					}
				}
#else /* USED_ONLY_LOCAL_MODE */
				module_wait_full_sample_done();
#endif /* USED_ONLY_LOCAL_MODE */
			}
#if USED_ONLY_LOCAL_MODE
		    while(YES)
		    {
				lDataIndex = module_wait_local_sample_done();

				if(lDataIndex == LOCAL_OP_LAST_LHB)
				{
					break;
				}
			}
#else /* USED_ONLY_LOCAL_MODE */
			module_wait_full_sample_done();
#endif /* USED_ONLY_LOCAL_MODE */
		}
#elif (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_MANUAL)
		if(Change_CR_Value)
		{
			Change_CR_Value = 0;
			HAL_SetROICRegSetChangeMode(ROIC_REG_SET_CHAGNE_CR_TUNE);
			module_wait_full_sample_done();
		}
#endif /* (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO) */

		if(protocol_swip_GetMode() == M_TOUCH_DFUP)
		{
			break;
		}
	}
}
#endif /* USED_RAWDATA_TUNE_CALIBRATION */

void SW92505_SetDiagTestOperationMode(eDIAG_TEST_CHANGE_MODE_t TestMode)
{
	tCFGR_DIC_CFG_t tCFGR_DIC_CFG;
	tR0_CR_GTUNE_t tR0_CR_GTUNE;
	tR1_CR_GTUNE_t tR1_CR_GTUNE;
	tCFGR_SENSE_CTRL_t tCFGR_SENSE_CTRL;
	tCFGR_MUX_EN_t tCFGR_MUX_EN;
	tCFGR_TG_STUCK_t tCFGR_TG_STUCK[6];
	
	tCFGR_ADC_CTRL_t tCFGR_ADC_CTRL;
	tCFGR_COMP_ADC_CTRL_t tCFGR_COMP_ADC_CTRL;

	tR0_CR_GTUNE_t R0_CR_GTUNE_[5];
	tR1_CR_GTUNE_t R1_CR_GTUNE_[6];

	tR0_CR1_MUX1_1_t R0_CR1_MUX1_1_[5];
	tR0_CR1_MUX1_2_t R0_CR1_MUX1_2_[5];
	tR0_CR1_MUX2_t R0_CR1_MUX2_[5];
	tR0_CR1_MUX3_t R0_CR1_MUX3_[5];
	tR0_CR1_MUX4_t R0_CR1_MUX4_[5];
	tR0_CR1_MUX5_t R0_CR1_MUX5_[5];
	tR0_CR1_MUX6_t R0_CR1_MUX6_[5];
	tR0_CR1_MUX7_t R0_CR1_MUX7_[5];
	tR0_CR1_MUX8_t R0_CR1_MUX8_[5];
	tR0_CR1_MUX9_t R0_CR1_MUX9_[5];
	tR0_CR1_MUX10_1_t R0_CR1_MUX10_1_[5];
	tR0_CR1_MUX10_2_t R0_CR1_MUX10_2_[5];
	tR0_CFGR_TUNE_GROUP_t R0_CFGR_TUNE_GROUP_t[5];

	tR1_CR1_MUX1_1_t R1_CR1_MUX1_1_[5];
	tR1_CR1_MUX1_2_t R1_CR1_MUX1_2_[5];
	tR1_CR1_MUX2_t R1_CR1_MUX2_[5];
	tR1_CR1_MUX3_t R1_CR1_MUX3_[5];
	tR1_CR1_MUX4_t R1_CR1_MUX4_[5];
	tR1_CR1_MUX5_t R1_CR1_MUX5_[5];
	tR1_CR1_MUX6_t R1_CR1_MUX6_[5];
	tR1_CR1_MUX7_t R1_CR1_MUX7_[5];
	tR1_CR1_MUX8_t R1_CR1_MUX8_[5];
	tR1_CR1_MUX9_t R1_CR1_MUX9_[5];
	tR1_CR1_MUX10_1_t R1_CR1_MUX10_1_[5];
	tR1_CR1_MUX10_2_t R1_CR1_MUX10_2_[5];
	tR1_CFGR_TUNE_GROUP_t R1_CFGR_TUNE_GROUP_[5];

	switch(TestMode)
	{
		case DIAG_CHANGE_SHORT1_TEST_STEP1:
			/* even odd start */
			tCFGR_TG_STUCK[0].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[0].ulBulk;
			tCFGR_TG_STUCK[1].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[1].ulBulk;
			tCFGR_TG_STUCK[2].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[2].ulBulk;
			tCFGR_TG_STUCK[3].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[3].ulBulk;
			tCFGR_TG_STUCK[4].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[4].ulBulk;

			tCFGR_TG_STUCK[0].tBit.stuck_vcr_odd_en = 1;
			tCFGR_TG_STUCK[0].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[1].tBit.stuck_vcr_odd_en = 1;
			tCFGR_TG_STUCK[1].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[2].tBit.stuck_vcr_odd_en = 1;
			tCFGR_TG_STUCK[2].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[3].tBit.stuck_vcr_odd_en = 1;
			tCFGR_TG_STUCK[3].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[4].tBit.stuck_vcr_odd_en = 1;
			tCFGR_TG_STUCK[4].tBit.stuck_vcr_even_en = 1;

			MSPI_RegisterMultiWrite((uint32_t)(0x0084), (uint32_t *)&tCFGR_TG_STUCK[0].ulBulk);
			/* even odd end */

			tCFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk;
			tCFGR_MUX_EN.tBit.mux_int_en = 1;
			MSPI_RegisterWrite((uint32_t)(0x0028), tCFGR_MUX_EN.ulBulk);	
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP2:
			tCFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk;
			tCFGR_MUX_EN.tBit.mux_int_en = 2;
			MSPI_RegisterWrite((uint32_t)(0x0028), tCFGR_MUX_EN.ulBulk);	
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP3:
			tCFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk;
			tCFGR_MUX_EN.tBit.mux_int_en = 3;
			MSPI_RegisterWrite((uint32_t)(0x0028), tCFGR_MUX_EN.ulBulk);	
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP4:
			tCFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk;
			tCFGR_MUX_EN.tBit.mux_int_en = 4;
			MSPI_RegisterWrite((uint32_t)(0x0028), tCFGR_MUX_EN.ulBulk);	
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP5:
			tCFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk;
			tCFGR_MUX_EN.tBit.mux_int_en = 5;
			MSPI_RegisterWrite((uint32_t)(0x0028), tCFGR_MUX_EN.ulBulk);	
			break;
//		case DIAG_CHANGE_SHORT1_TEST_STEP6:	// <<<<
//			tCFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk;
//			tCFGR_MUX_EN.tBit.mux_int_en = 1;
//			MSPI_RegisterWrite((uint32_t)(0x0028), tCFGR_MUX_EN.ulBulk);
//
//			tR0_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk;
//			tR0_CR_GTUNE.tBit.cr_fg_gtune = 3;
//			MSPI_RegisterWrite((uint32_t)(0x0130), tR0_CR_GTUNE.ulBulk);
//
//			tR1_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk;
//			tR1_CR_GTUNE.tBit.cr_fg_gtune = 3;
//			MSPI_RegisterWrite((uint32_t)(0x01B0), tR1_CR_GTUNE.ulBulk);
//			break;
//		case DIAG_CHANGE_SHORT1_TEST_STEP7:
//			tCFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk;
//			tCFGR_MUX_EN.tBit.mux_int_en = 2;
//			MSPI_RegisterWrite((uint32_t)(0x0028), tCFGR_MUX_EN.ulBulk);
//
//			tR0_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk;
//			tR0_CR_GTUNE.tBit.cr_fg_gtune = 3;
//			MSPI_RegisterWrite((uint32_t)(0x0130), tR0_CR_GTUNE.ulBulk);
//
//			tR1_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk;
//			tR1_CR_GTUNE.tBit.cr_fg_gtune = 3;
//			MSPI_RegisterWrite((uint32_t)(0x01B0), tR1_CR_GTUNE.ulBulk);
//			break;
//		case DIAG_CHANGE_SHORT1_TEST_STEP8:
//			tCFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk;
//			tCFGR_MUX_EN.tBit.mux_int_en = 3;
//			MSPI_RegisterWrite((uint32_t)(0x0028), tCFGR_MUX_EN.ulBulk);
//
//			tR0_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk;
//			tR0_CR_GTUNE.tBit.cr_fg_gtune = 3;
//			MSPI_RegisterWrite((uint32_t)(0x0130), tR0_CR_GTUNE.ulBulk);
//
//			tR1_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk;
//			tR1_CR_GTUNE.tBit.cr_fg_gtune = 3;
//			MSPI_RegisterWrite((uint32_t)(0x01B0), tR1_CR_GTUNE.ulBulk);
//			break;
//		case DIAG_CHANGE_SHORT1_TEST_STEP9:
//			tCFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk;
//			tCFGR_MUX_EN.tBit.mux_int_en = 4;
//			MSPI_RegisterWrite((uint32_t)(0x0028), tCFGR_MUX_EN.ulBulk);
//
//			tR0_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk;
//			tR0_CR_GTUNE.tBit.cr_fg_gtune = 3;
//			MSPI_RegisterWrite((uint32_t)(0x0130), tR0_CR_GTUNE.ulBulk);
//
//			tR1_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk;
//			tR1_CR_GTUNE.tBit.cr_fg_gtune = 3;
//			MSPI_RegisterWrite((uint32_t)(0x01B0), tR1_CR_GTUNE.ulBulk);
//			break;
//		case DIAG_CHANGE_SHORT1_TEST_STEP10:
//			tCFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk;
//			tCFGR_MUX_EN.tBit.mux_int_en = 5;
//			MSPI_RegisterWrite((uint32_t)(0x0028), tCFGR_MUX_EN.ulBulk);
//
//			tR0_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk;
//			tR0_CR_GTUNE.tBit.cr_fg_gtune = 3;
//			MSPI_RegisterWrite((uint32_t)(0x0130), tR0_CR_GTUNE.ulBulk);
//
//			tR1_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk;
//			tR1_CR_GTUNE.tBit.cr_fg_gtune = 3;
//			MSPI_RegisterWrite((uint32_t)(0x01B0), tR1_CR_GTUNE.ulBulk);
//			break;
		case DIAG_CHANGE_SHORT1_TEST_RECOVERY:
			/* even odd start */
			MSPI_RegisterWrite((uint32_t)(0x0084), s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[0].ulBulk);
			/* even odd end */
			MSPI_RegisterWrite((uint32_t)(0x0028), s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk);
			break;

		case DIAG_CHANGE_SHORT2_TEST_STEP1:	// 1st Frame
			/* Global tune set start */
			R0_CR_GTUNE_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk;
			R0_CR_GTUNE_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[1].ulBulk;
			R0_CR_GTUNE_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[2].ulBulk;
			R0_CR_GTUNE_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[3].ulBulk;
			R0_CR_GTUNE_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[4].ulBulk;

			R0_CR_GTUNE_[0].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[1].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[2].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[3].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[4].tBit.cr_fg_gtune = 3;

			R1_CR_GTUNE_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk;
			R1_CR_GTUNE_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[1].ulBulk;
			R1_CR_GTUNE_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[2].ulBulk;
			R1_CR_GTUNE_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[3].ulBulk;
			R1_CR_GTUNE_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[4].ulBulk;

			R1_CR_GTUNE_[0].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[1].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[2].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[3].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[4].tBit.cr_fg_gtune = 3;
			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&R0_CR_GTUNE_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&R1_CR_GTUNE_[0].ulBulk);
			/* Global tune set end */

			/* even odd start */
			tCFGR_TG_STUCK[0].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[0].ulBulk;
			tCFGR_TG_STUCK[1].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[1].ulBulk;
			tCFGR_TG_STUCK[2].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[2].ulBulk;
			tCFGR_TG_STUCK[3].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[3].ulBulk;
			tCFGR_TG_STUCK[4].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[4].ulBulk;

			tCFGR_TG_STUCK[0].tBit.stuck_vcr_odd_en = 1;
			tCFGR_TG_STUCK[0].tBit.stuck_vcr_even_en = 3;

			tCFGR_TG_STUCK[1].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[1].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[2].tBit.stuck_vcr_odd_en = 1;
			tCFGR_TG_STUCK[2].tBit.stuck_vcr_even_en = 3;

			tCFGR_TG_STUCK[3].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[3].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[4].tBit.stuck_vcr_odd_en = 1;
			tCFGR_TG_STUCK[4].tBit.stuck_vcr_even_en = 3;

			MSPI_RegisterMultiWrite((uint32_t)(0x0084), (uint32_t *)&tCFGR_TG_STUCK[0].ulBulk);
			/* even odd end */

			/* adc conversion rate 500KS/s setting start*/
			tCFGR_ADC_CTRL.ulBulk = s_pktmoduleSRICCommonConf->CFGR_ADC_CTRL.ulBulk;
			tCFGR_ADC_CTRL.tBit.adc_clk_prd = 2;
			MSPI_RegisterWrite((uint32_t)(0x0078), tCFGR_ADC_CTRL.ulBulk);
			/* adc conversion rate 500KS/s setting end*/

			break;
		case DIAG_CHANGE_SHORT2_TEST_STEP2:	// 2nd Frame
			/* Global tune set start */
			R0_CR_GTUNE_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk;
			R0_CR_GTUNE_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[1].ulBulk;
			R0_CR_GTUNE_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[2].ulBulk;
			R0_CR_GTUNE_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[3].ulBulk;
			R0_CR_GTUNE_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[4].ulBulk;

			R0_CR_GTUNE_[0].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[1].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[2].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[3].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[4].tBit.cr_fg_gtune = 3;

			R1_CR_GTUNE_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk;
			R1_CR_GTUNE_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[1].ulBulk;
			R1_CR_GTUNE_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[2].ulBulk;
			R1_CR_GTUNE_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[3].ulBulk;
			R1_CR_GTUNE_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[4].ulBulk;

			R1_CR_GTUNE_[0].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[1].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[2].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[3].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[4].tBit.cr_fg_gtune = 3;
			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&R0_CR_GTUNE_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&R1_CR_GTUNE_[0].ulBulk);
			/* Global tune set end */

			/* even odd start */
			tCFGR_TG_STUCK[0].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[0].ulBulk;
			tCFGR_TG_STUCK[1].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[1].ulBulk;
			tCFGR_TG_STUCK[2].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[2].ulBulk;
			tCFGR_TG_STUCK[3].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[3].ulBulk;
			tCFGR_TG_STUCK[4].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[4].ulBulk;

			tCFGR_TG_STUCK[0].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[0].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[1].tBit.stuck_vcr_odd_en = 1;
			tCFGR_TG_STUCK[1].tBit.stuck_vcr_even_en = 3;

			tCFGR_TG_STUCK[2].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[2].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[3].tBit.stuck_vcr_odd_en = 1;
			tCFGR_TG_STUCK[3].tBit.stuck_vcr_even_en = 3;

			tCFGR_TG_STUCK[4].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[4].tBit.stuck_vcr_even_en = 1;

			MSPI_RegisterMultiWrite((uint32_t)(0x0084), (uint32_t *)&tCFGR_TG_STUCK[0].ulBulk);
			/* even odd end */

			/* adc conversion rate 500KS/s setting start*/
			tCFGR_ADC_CTRL.ulBulk = s_pktmoduleSRICCommonConf->CFGR_ADC_CTRL.ulBulk;
			tCFGR_ADC_CTRL.tBit.adc_clk_prd = 2;
			MSPI_RegisterWrite((uint32_t)(0x0078), tCFGR_ADC_CTRL.ulBulk);
			/* adc conversion rate 500KS/s setting end*/
			break;
		case DIAG_CHANGE_SHORT2_TEST_STEP3:	// 3rd Frame
			/* Local tune set start */
			/* R0 */
			R0_CR1_MUX1_1_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[0].ulBulk;
			R0_CR1_MUX1_1_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[1].ulBulk;
			R0_CR1_MUX1_1_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[2].ulBulk;
			R0_CR1_MUX1_1_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[3].ulBulk;
			R0_CR1_MUX1_1_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[4].ulBulk;

			R0_CR1_MUX1_2_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[0].ulBulk;
			R0_CR1_MUX1_2_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[1].ulBulk;
			R0_CR1_MUX1_2_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[2].ulBulk;
			R0_CR1_MUX1_2_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[3].ulBulk;
			R0_CR1_MUX1_2_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[4].ulBulk;

			R0_CR1_MUX2_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX2[0].ulBulk;
			R0_CR1_MUX2_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX2[1].ulBulk;
			R0_CR1_MUX2_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX2[2].ulBulk;
			R0_CR1_MUX2_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX2[3].ulBulk;
			R0_CR1_MUX2_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX2[4].ulBulk;

			R0_CR1_MUX3_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX3[0].ulBulk;
			R0_CR1_MUX3_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX3[1].ulBulk;
			R0_CR1_MUX3_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX3[2].ulBulk;
			R0_CR1_MUX3_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX3[3].ulBulk;
			R0_CR1_MUX3_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX3[4].ulBulk;

			R0_CR1_MUX4_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX4[0].ulBulk;
			R0_CR1_MUX4_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX4[1].ulBulk;
			R0_CR1_MUX4_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX4[2].ulBulk;
			R0_CR1_MUX4_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX4[3].ulBulk;
			R0_CR1_MUX4_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX4[4].ulBulk;

			R0_CR1_MUX5_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX5[0].ulBulk;
			R0_CR1_MUX5_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX5[1].ulBulk;
			R0_CR1_MUX5_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX5[2].ulBulk;
			R0_CR1_MUX5_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX5[3].ulBulk;
			R0_CR1_MUX5_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX5[4].ulBulk;

			R0_CR1_MUX6_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX6[0].ulBulk;
			R0_CR1_MUX6_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX6[1].ulBulk;
			R0_CR1_MUX6_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX6[2].ulBulk;
			R0_CR1_MUX6_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX6[3].ulBulk;
			R0_CR1_MUX6_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX6[4].ulBulk;

			R0_CR1_MUX7_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX7[0].ulBulk;
			R0_CR1_MUX7_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX7[1].ulBulk;
			R0_CR1_MUX7_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX7[2].ulBulk;
			R0_CR1_MUX7_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX7[3].ulBulk;
			R0_CR1_MUX7_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX7[4].ulBulk;

			R0_CR1_MUX8_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX8[0].ulBulk;
			R0_CR1_MUX8_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX8[1].ulBulk;
			R0_CR1_MUX8_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX8[2].ulBulk;
			R0_CR1_MUX8_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX8[3].ulBulk;
			R0_CR1_MUX8_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX8[4].ulBulk;

			R0_CR1_MUX9_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX9[0].ulBulk;
			R0_CR1_MUX9_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX9[1].ulBulk;
			R0_CR1_MUX9_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX9[2].ulBulk;
			R0_CR1_MUX9_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX9[3].ulBulk;
			R0_CR1_MUX9_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX9[4].ulBulk;

			R0_CR1_MUX10_1_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[0].ulBulk;
			R0_CR1_MUX10_1_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[1].ulBulk;
			R0_CR1_MUX10_1_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[2].ulBulk;
			R0_CR1_MUX10_1_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[3].ulBulk;
			R0_CR1_MUX10_1_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[4].ulBulk;

			R0_CR1_MUX10_2_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[0].ulBulk;
			R0_CR1_MUX10_2_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[1].ulBulk;
			R0_CR1_MUX10_2_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[2].ulBulk;
			R0_CR1_MUX10_2_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[3].ulBulk;
			R0_CR1_MUX10_2_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[4].ulBulk;

			R0_CR1_MUX1_1_[0].tBit.cr1_r1g3 = 0;
			R0_CR1_MUX1_1_[1].tBit.cr1_r1g3 = 0;
			R0_CR1_MUX1_1_[2].tBit.cr1_r1g3 = 0;
			R0_CR1_MUX1_1_[3].tBit.cr1_r1g3 = 0;
			R0_CR1_MUX1_1_[4].tBit.cr1_r1g3 = 0;
			R0_CR1_MUX1_1_[0].tBit.cr1_r2g3 = 0;
			R0_CR1_MUX1_1_[1].tBit.cr1_r2g3 = 0;
			R0_CR1_MUX1_1_[2].tBit.cr1_r2g3 = 0;
			R0_CR1_MUX1_1_[3].tBit.cr1_r2g3 = 0;
			R0_CR1_MUX1_1_[4].tBit.cr1_r2g3 = 0;
			R0_CR1_MUX1_2_[0].tBit.cr1_r3g3 = 0;
			R0_CR1_MUX1_2_[1].tBit.cr1_r3g3 = 0;
			R0_CR1_MUX1_2_[2].tBit.cr1_r3g3 = 0;
			R0_CR1_MUX1_2_[3].tBit.cr1_r3g3 = 0;
			R0_CR1_MUX1_2_[4].tBit.cr1_r3g3 = 0;
			R0_CR1_MUX2_[0].tBit.cr1_rg3 = 0;
			R0_CR1_MUX2_[1].tBit.cr1_rg3 = 0;
			R0_CR1_MUX2_[2].tBit.cr1_rg3 = 0;
			R0_CR1_MUX2_[3].tBit.cr1_rg3 = 0;
			R0_CR1_MUX2_[4].tBit.cr1_rg3 = 0;
			R0_CR1_MUX3_[0].tBit.cr1_rg3 = 0;
			R0_CR1_MUX3_[1].tBit.cr1_rg3 = 0;
			R0_CR1_MUX3_[2].tBit.cr1_rg3 = 0;
			R0_CR1_MUX3_[3].tBit.cr1_rg3 = 0;
			R0_CR1_MUX3_[4].tBit.cr1_rg3 = 0;
			R0_CR1_MUX4_[0].tBit.cr1_rg3 = 0;
			R0_CR1_MUX4_[1].tBit.cr1_rg3 = 0;
			R0_CR1_MUX4_[2].tBit.cr1_rg3 = 0;
			R0_CR1_MUX4_[3].tBit.cr1_rg3 = 0;
			R0_CR1_MUX4_[4].tBit.cr1_rg3 = 0;
			R0_CR1_MUX5_[0].tBit.cr1_rg3 = 0;
			R0_CR1_MUX5_[1].tBit.cr1_rg3 = 0;
			R0_CR1_MUX5_[2].tBit.cr1_rg3 = 0;
			R0_CR1_MUX5_[3].tBit.cr1_rg3 = 0;
			R0_CR1_MUX5_[4].tBit.cr1_rg3 = 0;
			R0_CR1_MUX6_[0].tBit.cr1_rg3 = 0;
			R0_CR1_MUX6_[1].tBit.cr1_rg3 = 0;
			R0_CR1_MUX6_[2].tBit.cr1_rg3 = 0;
			R0_CR1_MUX6_[3].tBit.cr1_rg3 = 0;
			R0_CR1_MUX6_[4].tBit.cr1_rg3 = 0;
			R0_CR1_MUX7_[0].tBit.cr1_rg3 = 0;
			R0_CR1_MUX7_[1].tBit.cr1_rg3 = 0;
			R0_CR1_MUX7_[2].tBit.cr1_rg3 = 0;
			R0_CR1_MUX7_[3].tBit.cr1_rg3 = 0;
			R0_CR1_MUX7_[4].tBit.cr1_rg3 = 0;
			R0_CR1_MUX8_[0].tBit.cr1_rg3 = 0;
			R0_CR1_MUX8_[1].tBit.cr1_rg3 = 0;
			R0_CR1_MUX8_[2].tBit.cr1_rg3 = 0;
			R0_CR1_MUX8_[3].tBit.cr1_rg3 = 0;
			R0_CR1_MUX8_[4].tBit.cr1_rg3 = 0;
			R0_CR1_MUX9_[0].tBit.cr1_rg3 = 0;
			R0_CR1_MUX9_[1].tBit.cr1_rg3 = 0;
			R0_CR1_MUX9_[2].tBit.cr1_rg3 = 0;
			R0_CR1_MUX9_[3].tBit.cr1_rg3 = 0;
			R0_CR1_MUX9_[4].tBit.cr1_rg3 = 0;
			R0_CR1_MUX10_1_[0].tBit.cr1_r1g3 = 0;
			R0_CR1_MUX10_1_[1].tBit.cr1_r1g3 = 0;
			R0_CR1_MUX10_1_[2].tBit.cr1_r1g3 = 0;
			R0_CR1_MUX10_1_[3].tBit.cr1_r1g3 = 0;
			R0_CR1_MUX10_1_[4].tBit.cr1_r1g3 = 0;
			R0_CR1_MUX10_1_[0].tBit.cr1_r2g3 = 0;
			R0_CR1_MUX10_1_[1].tBit.cr1_r2g3 = 0;
			R0_CR1_MUX10_1_[2].tBit.cr1_r2g3 = 0;
			R0_CR1_MUX10_1_[3].tBit.cr1_r2g3 = 0;
			R0_CR1_MUX10_1_[4].tBit.cr1_r2g3 = 0;
			R0_CR1_MUX10_2_[0].tBit.cr1_r3g3 = 0;
			R0_CR1_MUX10_2_[1].tBit.cr1_r3g3 = 0;
			R0_CR1_MUX10_2_[2].tBit.cr1_r3g3 = 0;
			R0_CR1_MUX10_2_[3].tBit.cr1_r3g3 = 0;
			R0_CR1_MUX10_2_[4].tBit.cr1_r3g3 = 0;

			/* R1 */
			R1_CR1_MUX1_1_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[0].ulBulk;
			R1_CR1_MUX1_1_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[1].ulBulk;
			R1_CR1_MUX1_1_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[2].ulBulk;
			R1_CR1_MUX1_1_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[3].ulBulk;
			R1_CR1_MUX1_1_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[4].ulBulk;

			R1_CR1_MUX1_2_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[0].ulBulk;
			R1_CR1_MUX1_2_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[1].ulBulk;
			R1_CR1_MUX1_2_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[2].ulBulk;
			R1_CR1_MUX1_2_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[3].ulBulk;
			R1_CR1_MUX1_2_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[4].ulBulk;

			R1_CR1_MUX2_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX2[0].ulBulk;
			R1_CR1_MUX2_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX2[1].ulBulk;
			R1_CR1_MUX2_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX2[2].ulBulk;
			R1_CR1_MUX2_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX2[3].ulBulk;
			R1_CR1_MUX2_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX2[4].ulBulk;

			R1_CR1_MUX3_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX3[0].ulBulk;
			R1_CR1_MUX3_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX3[1].ulBulk;
			R1_CR1_MUX3_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX3[2].ulBulk;
			R1_CR1_MUX3_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX3[3].ulBulk;
			R1_CR1_MUX3_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX3[4].ulBulk;

			R1_CR1_MUX4_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX4[0].ulBulk;
			R1_CR1_MUX4_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX4[1].ulBulk;
			R1_CR1_MUX4_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX4[2].ulBulk;
			R1_CR1_MUX4_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX4[3].ulBulk;
			R1_CR1_MUX4_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX4[4].ulBulk;

			R1_CR1_MUX5_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX5[0].ulBulk;
			R1_CR1_MUX5_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX5[1].ulBulk;
			R1_CR1_MUX5_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX5[2].ulBulk;
			R1_CR1_MUX5_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX5[3].ulBulk;
			R1_CR1_MUX5_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX5[4].ulBulk;

			R1_CR1_MUX6_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX6[0].ulBulk;
			R1_CR1_MUX6_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX6[1].ulBulk;
			R1_CR1_MUX6_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX6[2].ulBulk;
			R1_CR1_MUX6_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX6[3].ulBulk;
			R1_CR1_MUX6_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX6[4].ulBulk;

			R1_CR1_MUX7_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX7[0].ulBulk;
			R1_CR1_MUX7_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX7[1].ulBulk;
			R1_CR1_MUX7_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX7[2].ulBulk;
			R1_CR1_MUX7_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX7[3].ulBulk;
			R1_CR1_MUX7_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX7[4].ulBulk;

			R1_CR1_MUX8_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX8[0].ulBulk;
			R1_CR1_MUX8_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX8[1].ulBulk;
			R1_CR1_MUX8_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX8[2].ulBulk;
			R1_CR1_MUX8_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX8[3].ulBulk;
			R1_CR1_MUX8_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX8[4].ulBulk;

			R1_CR1_MUX9_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX9[0].ulBulk;
			R1_CR1_MUX9_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX9[1].ulBulk;
			R1_CR1_MUX9_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX9[2].ulBulk;
			R1_CR1_MUX9_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX9[3].ulBulk;
			R1_CR1_MUX9_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX9[4].ulBulk;

			R1_CR1_MUX10_1_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[0].ulBulk;
			R1_CR1_MUX10_1_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[1].ulBulk;
			R1_CR1_MUX10_1_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[2].ulBulk;
			R1_CR1_MUX10_1_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[3].ulBulk;
			R1_CR1_MUX10_1_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[4].ulBulk;

			R1_CR1_MUX10_2_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[0].ulBulk;
			R1_CR1_MUX10_2_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[1].ulBulk;
			R1_CR1_MUX10_2_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[2].ulBulk;
			R1_CR1_MUX10_2_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[3].ulBulk;
			R1_CR1_MUX10_2_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[4].ulBulk;

			R1_CR1_MUX1_1_[0].tBit.cr1_r1g3 = 31;
			R1_CR1_MUX1_1_[1].tBit.cr1_r1g3 = 31;
			R1_CR1_MUX1_1_[2].tBit.cr1_r1g3 = 31;
			R1_CR1_MUX1_1_[3].tBit.cr1_r1g3 = 31;
			R1_CR1_MUX1_1_[4].tBit.cr1_r1g3 = 31;
			R1_CR1_MUX1_1_[0].tBit.cr1_r2g3 = 31;
			R1_CR1_MUX1_1_[1].tBit.cr1_r2g3 = 31;
			R1_CR1_MUX1_1_[2].tBit.cr1_r2g3 = 31;
			R1_CR1_MUX1_1_[3].tBit.cr1_r2g3 = 31;
			R1_CR1_MUX1_1_[4].tBit.cr1_r2g3 = 31;
			R1_CR1_MUX1_2_[0].tBit.cr1_r3g3 = 31;
			R1_CR1_MUX1_2_[1].tBit.cr1_r3g3 = 31;
			R1_CR1_MUX1_2_[2].tBit.cr1_r3g3 = 31;
			R1_CR1_MUX1_2_[3].tBit.cr1_r3g3 = 31;
			R1_CR1_MUX1_2_[4].tBit.cr1_r3g3 = 31;
			R1_CR1_MUX2_[0].tBit.cr1_rg3 = 31;
			R1_CR1_MUX2_[1].tBit.cr1_rg3 = 31;
			R1_CR1_MUX2_[2].tBit.cr1_rg3 = 31;
			R1_CR1_MUX2_[3].tBit.cr1_rg3 = 31;
			R1_CR1_MUX2_[4].tBit.cr1_rg3 = 31;
			R1_CR1_MUX3_[0].tBit.cr1_rg3 = 31;
			R1_CR1_MUX3_[1].tBit.cr1_rg3 = 31;
			R1_CR1_MUX3_[2].tBit.cr1_rg3 = 31;
			R1_CR1_MUX3_[3].tBit.cr1_rg3 = 31;
			R1_CR1_MUX3_[4].tBit.cr1_rg3 = 31;
			R1_CR1_MUX4_[0].tBit.cr1_rg3 = 31;
			R1_CR1_MUX4_[1].tBit.cr1_rg3 = 31;
			R1_CR1_MUX4_[2].tBit.cr1_rg3 = 31;
			R1_CR1_MUX4_[3].tBit.cr1_rg3 = 31;
			R1_CR1_MUX4_[4].tBit.cr1_rg3 = 31;
			R1_CR1_MUX5_[0].tBit.cr1_rg3 = 31;
			R1_CR1_MUX5_[1].tBit.cr1_rg3 = 31;
			R1_CR1_MUX5_[2].tBit.cr1_rg3 = 31;
			R1_CR1_MUX5_[3].tBit.cr1_rg3 = 31;
			R1_CR1_MUX5_[4].tBit.cr1_rg3 = 31;
			R1_CR1_MUX6_[0].tBit.cr1_rg3 = 31;
			R1_CR1_MUX6_[1].tBit.cr1_rg3 = 31;
			R1_CR1_MUX6_[2].tBit.cr1_rg3 = 31;
			R1_CR1_MUX6_[3].tBit.cr1_rg3 = 31;
			R1_CR1_MUX6_[4].tBit.cr1_rg3 = 31;
			R1_CR1_MUX7_[0].tBit.cr1_rg3 = 31;
			R1_CR1_MUX7_[1].tBit.cr1_rg3 = 31;
			R1_CR1_MUX7_[2].tBit.cr1_rg3 = 31;
			R1_CR1_MUX7_[3].tBit.cr1_rg3 = 31;
			R1_CR1_MUX7_[4].tBit.cr1_rg3 = 31;
			R1_CR1_MUX8_[0].tBit.cr1_rg3 = 31;
			R1_CR1_MUX8_[1].tBit.cr1_rg3 = 31;
			R1_CR1_MUX8_[2].tBit.cr1_rg3 = 31;
			R1_CR1_MUX8_[3].tBit.cr1_rg3 = 31;
			R1_CR1_MUX8_[4].tBit.cr1_rg3 = 31;
			R1_CR1_MUX9_[0].tBit.cr1_rg3 = 31;
			R1_CR1_MUX9_[1].tBit.cr1_rg3 = 31;
			R1_CR1_MUX9_[2].tBit.cr1_rg3 = 31;
			R1_CR1_MUX9_[3].tBit.cr1_rg3 = 31;
			R1_CR1_MUX9_[4].tBit.cr1_rg3 = 31;
			R1_CR1_MUX10_1_[0].tBit.cr1_r1g3 = 31;
			R1_CR1_MUX10_1_[1].tBit.cr1_r1g3 = 31;
			R1_CR1_MUX10_1_[2].tBit.cr1_r1g3 = 31;
			R1_CR1_MUX10_1_[3].tBit.cr1_r1g3 = 31;
			R1_CR1_MUX10_1_[4].tBit.cr1_r1g3 = 31;
			R1_CR1_MUX10_1_[0].tBit.cr1_r2g3 = 31;
			R1_CR1_MUX10_1_[1].tBit.cr1_r2g3 = 31;
			R1_CR1_MUX10_1_[2].tBit.cr1_r2g3 = 31;
			R1_CR1_MUX10_1_[3].tBit.cr1_r2g3 = 31;
			R1_CR1_MUX10_1_[4].tBit.cr1_r2g3 = 31;
			R1_CR1_MUX10_2_[0].tBit.cr1_r3g3 = 31;
			R1_CR1_MUX10_2_[1].tBit.cr1_r3g3 = 31;
			R1_CR1_MUX10_2_[2].tBit.cr1_r3g3 = 31;
			R1_CR1_MUX10_2_[3].tBit.cr1_r3g3 = 31;
			R1_CR1_MUX10_2_[4].tBit.cr1_r3g3 = 31;
			MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&R0_CR1_MUX1_1_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&R0_CR1_MUX1_2_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0108), (uint32_t *)&R0_CR1_MUX2_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x010C), (uint32_t *)&R0_CR1_MUX3_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0110), (uint32_t *)&R0_CR1_MUX4_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0114), (uint32_t *)&R0_CR1_MUX5_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0118), (uint32_t *)&R0_CR1_MUX6_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x011C), (uint32_t *)&R0_CR1_MUX7_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0120), (uint32_t *)&R0_CR1_MUX8_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0124), (uint32_t *)&R0_CR1_MUX9_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0128), (uint32_t *)&R0_CR1_MUX10_1_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x012C), (uint32_t *)&R0_CR1_MUX10_2_[0].ulBulk);

			MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&R1_CR1_MUX1_1_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&R1_CR1_MUX1_2_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0188), (uint32_t *)&R1_CR1_MUX2_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x018C), (uint32_t *)&R1_CR1_MUX3_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0190), (uint32_t *)&R1_CR1_MUX4_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0194), (uint32_t *)&R1_CR1_MUX5_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0198), (uint32_t *)&R1_CR1_MUX6_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x019C), (uint32_t *)&R1_CR1_MUX7_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01A0), (uint32_t *)&R1_CR1_MUX8_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01A4), (uint32_t *)&R1_CR1_MUX9_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01A8), (uint32_t *)&R1_CR1_MUX10_1_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01AC), (uint32_t *)&R1_CR1_MUX10_2_[0].ulBulk);
			/* Local tune set end */

			/* Global tune set start */
			R0_CR_GTUNE_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk;
			R0_CR_GTUNE_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[1].ulBulk;
			R0_CR_GTUNE_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[2].ulBulk;
			R0_CR_GTUNE_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[3].ulBulk;
			R0_CR_GTUNE_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[4].ulBulk;

			R0_CR_GTUNE_[0].tBit.cr_fg_gtune = 0;
			R0_CR_GTUNE_[1].tBit.cr_fg_gtune = 0;
			R0_CR_GTUNE_[2].tBit.cr_fg_gtune = 0;
			R0_CR_GTUNE_[3].tBit.cr_fg_gtune = 0;
			R0_CR_GTUNE_[4].tBit.cr_fg_gtune = 0;

			R1_CR_GTUNE_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk;
			R1_CR_GTUNE_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[1].ulBulk;
			R1_CR_GTUNE_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[2].ulBulk;
			R1_CR_GTUNE_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[3].ulBulk;
			R1_CR_GTUNE_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[4].ulBulk;

			R1_CR_GTUNE_[0].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[1].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[2].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[3].tBit.cr_fg_gtune = 3;
			R1_CR_GTUNE_[4].tBit.cr_fg_gtune = 3;
			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&R0_CR_GTUNE_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&R1_CR_GTUNE_[0].ulBulk);
			/* Global tune set end */

			/* even odd start */
			tCFGR_TG_STUCK[0].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[0].ulBulk;
			tCFGR_TG_STUCK[1].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[1].ulBulk;
			tCFGR_TG_STUCK[2].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[2].ulBulk;
			tCFGR_TG_STUCK[3].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[3].ulBulk;
			tCFGR_TG_STUCK[4].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[4].ulBulk;

			tCFGR_TG_STUCK[0].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[0].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[1].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[1].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[2].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[2].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[3].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[3].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[4].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[4].tBit.stuck_vcr_even_en = 1;

			MSPI_RegisterMultiWrite((uint32_t)(0x0084), (uint32_t *)&tCFGR_TG_STUCK[0].ulBulk);
			/* even odd end */
			/* adc conversion rate 500KS/s setting start*/
			tCFGR_ADC_CTRL.ulBulk = s_pktmoduleSRICCommonConf->CFGR_ADC_CTRL.ulBulk;
			tCFGR_ADC_CTRL.tBit.adc_clk_prd = 2;
			MSPI_RegisterWrite((uint32_t)(0x0078), tCFGR_ADC_CTRL.ulBulk);
			/* adc conversion rate 500KS/s setting end*/
			break;
		case DIAG_CHANGE_SHORT2_TEST_STEP4:	// 4th Frame
			/* Local tune set start */
			/* R0 */
			R0_CR1_MUX1_1_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[0].ulBulk;
			R0_CR1_MUX1_1_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[1].ulBulk;
			R0_CR1_MUX1_1_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[2].ulBulk;
			R0_CR1_MUX1_1_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[3].ulBulk;
			R0_CR1_MUX1_1_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[4].ulBulk;

			R0_CR1_MUX1_2_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[0].ulBulk;
			R0_CR1_MUX1_2_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[1].ulBulk;
			R0_CR1_MUX1_2_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[2].ulBulk;
			R0_CR1_MUX1_2_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[3].ulBulk;
			R0_CR1_MUX1_2_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[4].ulBulk;

			R0_CR1_MUX2_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX2[0].ulBulk;
			R0_CR1_MUX2_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX2[1].ulBulk;
			R0_CR1_MUX2_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX2[2].ulBulk;
			R0_CR1_MUX2_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX2[3].ulBulk;
			R0_CR1_MUX2_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX2[4].ulBulk;

			R0_CR1_MUX3_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX3[0].ulBulk;
			R0_CR1_MUX3_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX3[1].ulBulk;
			R0_CR1_MUX3_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX3[2].ulBulk;
			R0_CR1_MUX3_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX3[3].ulBulk;
			R0_CR1_MUX3_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX3[4].ulBulk;

			R0_CR1_MUX4_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX4[0].ulBulk;
			R0_CR1_MUX4_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX4[1].ulBulk;
			R0_CR1_MUX4_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX4[2].ulBulk;
			R0_CR1_MUX4_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX4[3].ulBulk;
			R0_CR1_MUX4_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX4[4].ulBulk;

			R0_CR1_MUX5_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX5[0].ulBulk;
			R0_CR1_MUX5_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX5[1].ulBulk;
			R0_CR1_MUX5_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX5[2].ulBulk;
			R0_CR1_MUX5_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX5[3].ulBulk;
			R0_CR1_MUX5_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX5[4].ulBulk;

			R0_CR1_MUX6_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX6[0].ulBulk;
			R0_CR1_MUX6_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX6[1].ulBulk;
			R0_CR1_MUX6_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX6[2].ulBulk;
			R0_CR1_MUX6_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX6[3].ulBulk;
			R0_CR1_MUX6_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX6[4].ulBulk;

			R0_CR1_MUX7_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX7[0].ulBulk;
			R0_CR1_MUX7_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX7[1].ulBulk;
			R0_CR1_MUX7_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX7[2].ulBulk;
			R0_CR1_MUX7_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX7[3].ulBulk;
			R0_CR1_MUX7_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX7[4].ulBulk;

			R0_CR1_MUX8_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX8[0].ulBulk;
			R0_CR1_MUX8_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX8[1].ulBulk;
			R0_CR1_MUX8_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX8[2].ulBulk;
			R0_CR1_MUX8_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX8[3].ulBulk;
			R0_CR1_MUX8_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX8[4].ulBulk;

			R0_CR1_MUX9_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX9[0].ulBulk;
			R0_CR1_MUX9_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX9[1].ulBulk;
			R0_CR1_MUX9_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX9[2].ulBulk;
			R0_CR1_MUX9_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX9[3].ulBulk;
			R0_CR1_MUX9_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX9[4].ulBulk;

			R0_CR1_MUX10_1_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[0].ulBulk;
			R0_CR1_MUX10_1_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[1].ulBulk;
			R0_CR1_MUX10_1_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[2].ulBulk;
			R0_CR1_MUX10_1_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[3].ulBulk;
			R0_CR1_MUX10_1_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[4].ulBulk;

			R0_CR1_MUX10_2_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[0].ulBulk;
			R0_CR1_MUX10_2_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[1].ulBulk;
			R0_CR1_MUX10_2_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[2].ulBulk;
			R0_CR1_MUX10_2_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[3].ulBulk;
			R0_CR1_MUX10_2_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[4].ulBulk;

			R0_CR1_MUX1_1_[0].tBit.cr1_r1g3 = 31;
			R0_CR1_MUX1_1_[1].tBit.cr1_r1g3 = 31;
			R0_CR1_MUX1_1_[2].tBit.cr1_r1g3 = 31;
			R0_CR1_MUX1_1_[3].tBit.cr1_r1g3 = 31;
			R0_CR1_MUX1_1_[4].tBit.cr1_r1g3 = 31;
			R0_CR1_MUX1_1_[0].tBit.cr1_r2g3 = 31;
			R0_CR1_MUX1_1_[1].tBit.cr1_r2g3 = 31;
			R0_CR1_MUX1_1_[2].tBit.cr1_r2g3 = 31;
			R0_CR1_MUX1_1_[3].tBit.cr1_r2g3 = 31;
			R0_CR1_MUX1_1_[4].tBit.cr1_r2g3 = 31;
			R0_CR1_MUX1_2_[0].tBit.cr1_r3g3 = 31;
			R0_CR1_MUX1_2_[1].tBit.cr1_r3g3 = 31;
			R0_CR1_MUX1_2_[2].tBit.cr1_r3g3 = 31;
			R0_CR1_MUX1_2_[3].tBit.cr1_r3g3 = 31;
			R0_CR1_MUX1_2_[4].tBit.cr1_r3g3 = 31;
			R0_CR1_MUX2_[0].tBit.cr1_rg3 = 31;
			R0_CR1_MUX2_[1].tBit.cr1_rg3 = 31;
			R0_CR1_MUX2_[2].tBit.cr1_rg3 = 31;
			R0_CR1_MUX2_[3].tBit.cr1_rg3 = 31;
			R0_CR1_MUX2_[4].tBit.cr1_rg3 = 31;
			R0_CR1_MUX3_[0].tBit.cr1_rg3 = 31;
			R0_CR1_MUX3_[1].tBit.cr1_rg3 = 31;
			R0_CR1_MUX3_[2].tBit.cr1_rg3 = 31;
			R0_CR1_MUX3_[3].tBit.cr1_rg3 = 31;
			R0_CR1_MUX3_[4].tBit.cr1_rg3 = 31;
			R0_CR1_MUX4_[0].tBit.cr1_rg3 = 31;
			R0_CR1_MUX4_[1].tBit.cr1_rg3 = 31;
			R0_CR1_MUX4_[2].tBit.cr1_rg3 = 31;
			R0_CR1_MUX4_[3].tBit.cr1_rg3 = 31;
			R0_CR1_MUX4_[4].tBit.cr1_rg3 = 31;
			R0_CR1_MUX5_[0].tBit.cr1_rg3 = 31;
			R0_CR1_MUX5_[1].tBit.cr1_rg3 = 31;
			R0_CR1_MUX5_[2].tBit.cr1_rg3 = 31;
			R0_CR1_MUX5_[3].tBit.cr1_rg3 = 31;
			R0_CR1_MUX5_[4].tBit.cr1_rg3 = 31;
			R0_CR1_MUX6_[0].tBit.cr1_rg3 = 31;
			R0_CR1_MUX6_[1].tBit.cr1_rg3 = 31;
			R0_CR1_MUX6_[2].tBit.cr1_rg3 = 31;
			R0_CR1_MUX6_[3].tBit.cr1_rg3 = 31;
			R0_CR1_MUX6_[4].tBit.cr1_rg3 = 31;
			R0_CR1_MUX7_[0].tBit.cr1_rg3 = 31;
			R0_CR1_MUX7_[1].tBit.cr1_rg3 = 31;
			R0_CR1_MUX7_[2].tBit.cr1_rg3 = 31;
			R0_CR1_MUX7_[3].tBit.cr1_rg3 = 31;
			R0_CR1_MUX7_[4].tBit.cr1_rg3 = 31;
			R0_CR1_MUX8_[0].tBit.cr1_rg3 = 31;
			R0_CR1_MUX8_[1].tBit.cr1_rg3 = 31;
			R0_CR1_MUX8_[2].tBit.cr1_rg3 = 31;
			R0_CR1_MUX8_[3].tBit.cr1_rg3 = 31;
			R0_CR1_MUX8_[4].tBit.cr1_rg3 = 31;
			R0_CR1_MUX9_[0].tBit.cr1_rg3 = 31;
			R0_CR1_MUX9_[1].tBit.cr1_rg3 = 31;
			R0_CR1_MUX9_[2].tBit.cr1_rg3 = 31;
			R0_CR1_MUX9_[3].tBit.cr1_rg3 = 31;
			R0_CR1_MUX9_[4].tBit.cr1_rg3 = 31;
			R0_CR1_MUX10_1_[0].tBit.cr1_r1g3 = 31;
			R0_CR1_MUX10_1_[1].tBit.cr1_r1g3 = 31;
			R0_CR1_MUX10_1_[2].tBit.cr1_r1g3 = 31;
			R0_CR1_MUX10_1_[3].tBit.cr1_r1g3 = 31;
			R0_CR1_MUX10_1_[4].tBit.cr1_r1g3 = 31;
			R0_CR1_MUX10_1_[0].tBit.cr1_r2g3 = 31;
			R0_CR1_MUX10_1_[1].tBit.cr1_r2g3 = 31;
			R0_CR1_MUX10_1_[2].tBit.cr1_r2g3 = 31;
			R0_CR1_MUX10_1_[3].tBit.cr1_r2g3 = 31;
			R0_CR1_MUX10_1_[4].tBit.cr1_r2g3 = 31;
			R0_CR1_MUX10_2_[0].tBit.cr1_r3g3 = 31;
			R0_CR1_MUX10_2_[1].tBit.cr1_r3g3 = 31;
			R0_CR1_MUX10_2_[2].tBit.cr1_r3g3 = 31;
			R0_CR1_MUX10_2_[3].tBit.cr1_r3g3 = 31;
			R0_CR1_MUX10_2_[4].tBit.cr1_r3g3 = 31;

			/* R1 */
			R1_CR1_MUX1_1_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[0].ulBulk;
			R1_CR1_MUX1_1_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[1].ulBulk;
			R1_CR1_MUX1_1_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[2].ulBulk;
			R1_CR1_MUX1_1_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[3].ulBulk;
			R1_CR1_MUX1_1_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[4].ulBulk;

			R1_CR1_MUX1_2_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[0].ulBulk;
			R1_CR1_MUX1_2_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[1].ulBulk;
			R1_CR1_MUX1_2_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[2].ulBulk;
			R1_CR1_MUX1_2_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[3].ulBulk;
			R1_CR1_MUX1_2_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[4].ulBulk;

			R1_CR1_MUX2_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX2[0].ulBulk;
			R1_CR1_MUX2_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX2[1].ulBulk;
			R1_CR1_MUX2_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX2[2].ulBulk;
			R1_CR1_MUX2_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX2[3].ulBulk;
			R1_CR1_MUX2_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX2[4].ulBulk;

			R1_CR1_MUX3_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX3[0].ulBulk;
			R1_CR1_MUX3_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX3[1].ulBulk;
			R1_CR1_MUX3_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX3[2].ulBulk;
			R1_CR1_MUX3_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX3[3].ulBulk;
			R1_CR1_MUX3_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX3[4].ulBulk;

			R1_CR1_MUX4_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX4[0].ulBulk;
			R1_CR1_MUX4_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX4[1].ulBulk;
			R1_CR1_MUX4_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX4[2].ulBulk;
			R1_CR1_MUX4_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX4[3].ulBulk;
			R1_CR1_MUX4_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX4[4].ulBulk;

			R1_CR1_MUX5_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX5[0].ulBulk;
			R1_CR1_MUX5_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX5[1].ulBulk;
			R1_CR1_MUX5_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX5[2].ulBulk;
			R1_CR1_MUX5_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX5[3].ulBulk;
			R1_CR1_MUX5_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX5[4].ulBulk;

			R1_CR1_MUX6_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX6[0].ulBulk;
			R1_CR1_MUX6_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX6[1].ulBulk;
			R1_CR1_MUX6_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX6[2].ulBulk;
			R1_CR1_MUX6_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX6[3].ulBulk;
			R1_CR1_MUX6_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX6[4].ulBulk;

			R1_CR1_MUX7_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX7[0].ulBulk;
			R1_CR1_MUX7_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX7[1].ulBulk;
			R1_CR1_MUX7_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX7[2].ulBulk;
			R1_CR1_MUX7_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX7[3].ulBulk;
			R1_CR1_MUX7_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX7[4].ulBulk;

			R1_CR1_MUX8_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX8[0].ulBulk;
			R1_CR1_MUX8_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX8[1].ulBulk;
			R1_CR1_MUX8_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX8[2].ulBulk;
			R1_CR1_MUX8_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX8[3].ulBulk;
			R1_CR1_MUX8_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX8[4].ulBulk;

			R1_CR1_MUX9_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX9[0].ulBulk;
			R1_CR1_MUX9_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX9[1].ulBulk;
			R1_CR1_MUX9_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX9[2].ulBulk;
			R1_CR1_MUX9_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX9[3].ulBulk;
			R1_CR1_MUX9_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX9[4].ulBulk;

			R1_CR1_MUX10_1_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[0].ulBulk;
			R1_CR1_MUX10_1_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[1].ulBulk;
			R1_CR1_MUX10_1_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[2].ulBulk;
			R1_CR1_MUX10_1_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[3].ulBulk;
			R1_CR1_MUX10_1_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[4].ulBulk;

			R1_CR1_MUX10_2_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[0].ulBulk;
			R1_CR1_MUX10_2_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[1].ulBulk;
			R1_CR1_MUX10_2_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[2].ulBulk;
			R1_CR1_MUX10_2_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[3].ulBulk;
			R1_CR1_MUX10_2_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[4].ulBulk;

			R1_CR1_MUX1_1_[0].tBit.cr1_r1g3 = 0;
			R1_CR1_MUX1_1_[1].tBit.cr1_r1g3 = 0;
			R1_CR1_MUX1_1_[2].tBit.cr1_r1g3 = 0;
			R1_CR1_MUX1_1_[3].tBit.cr1_r1g3 = 0;
			R1_CR1_MUX1_1_[4].tBit.cr1_r1g3 = 0;
			R1_CR1_MUX1_1_[0].tBit.cr1_r2g3 = 0;
			R1_CR1_MUX1_1_[1].tBit.cr1_r2g3 = 0;
			R1_CR1_MUX1_1_[2].tBit.cr1_r2g3 = 0;
			R1_CR1_MUX1_1_[3].tBit.cr1_r2g3 = 0;
			R1_CR1_MUX1_1_[4].tBit.cr1_r2g3 = 0;
			R1_CR1_MUX1_2_[0].tBit.cr1_r3g3 = 0;
			R1_CR1_MUX1_2_[1].tBit.cr1_r3g3 = 0;
			R1_CR1_MUX1_2_[2].tBit.cr1_r3g3 = 0;
			R1_CR1_MUX1_2_[3].tBit.cr1_r3g3 = 0;
			R1_CR1_MUX1_2_[4].tBit.cr1_r3g3 = 0;
			R1_CR1_MUX2_[0].tBit.cr1_rg3 = 0;
			R1_CR1_MUX2_[1].tBit.cr1_rg3 = 0;
			R1_CR1_MUX2_[2].tBit.cr1_rg3 = 0;
			R1_CR1_MUX2_[3].tBit.cr1_rg3 = 0;
			R1_CR1_MUX2_[4].tBit.cr1_rg3 = 0;
			R1_CR1_MUX3_[0].tBit.cr1_rg3 = 0;
			R1_CR1_MUX3_[1].tBit.cr1_rg3 = 0;
			R1_CR1_MUX3_[2].tBit.cr1_rg3 = 0;
			R1_CR1_MUX3_[3].tBit.cr1_rg3 = 0;
			R1_CR1_MUX3_[4].tBit.cr1_rg3 = 0;
			R1_CR1_MUX4_[0].tBit.cr1_rg3 = 0;
			R1_CR1_MUX4_[1].tBit.cr1_rg3 = 0;
			R1_CR1_MUX4_[2].tBit.cr1_rg3 = 0;
			R1_CR1_MUX4_[3].tBit.cr1_rg3 = 0;
			R1_CR1_MUX4_[4].tBit.cr1_rg3 = 0;
			R1_CR1_MUX5_[0].tBit.cr1_rg3 = 0;
			R1_CR1_MUX5_[1].tBit.cr1_rg3 = 0;
			R1_CR1_MUX5_[2].tBit.cr1_rg3 = 0;
			R1_CR1_MUX5_[3].tBit.cr1_rg3 = 0;
			R1_CR1_MUX5_[4].tBit.cr1_rg3 = 0;
			R1_CR1_MUX6_[0].tBit.cr1_rg3 = 0;
			R1_CR1_MUX6_[1].tBit.cr1_rg3 = 0;
			R1_CR1_MUX6_[2].tBit.cr1_rg3 = 0;
			R1_CR1_MUX6_[3].tBit.cr1_rg3 = 0;
			R1_CR1_MUX6_[4].tBit.cr1_rg3 = 0;
			R1_CR1_MUX7_[0].tBit.cr1_rg3 = 0;
			R1_CR1_MUX7_[1].tBit.cr1_rg3 = 0;
			R1_CR1_MUX7_[2].tBit.cr1_rg3 = 0;
			R1_CR1_MUX7_[3].tBit.cr1_rg3 = 0;
			R1_CR1_MUX7_[4].tBit.cr1_rg3 = 0;
			R1_CR1_MUX8_[0].tBit.cr1_rg3 = 0;
			R1_CR1_MUX8_[1].tBit.cr1_rg3 = 0;
			R1_CR1_MUX8_[2].tBit.cr1_rg3 = 0;
			R1_CR1_MUX8_[3].tBit.cr1_rg3 = 0;
			R1_CR1_MUX8_[4].tBit.cr1_rg3 = 0;
			R1_CR1_MUX9_[0].tBit.cr1_rg3 = 0;
			R1_CR1_MUX9_[1].tBit.cr1_rg3 = 0;
			R1_CR1_MUX9_[2].tBit.cr1_rg3 = 0;
			R1_CR1_MUX9_[3].tBit.cr1_rg3 = 0;
			R1_CR1_MUX9_[4].tBit.cr1_rg3 = 0;
			R1_CR1_MUX10_1_[0].tBit.cr1_r1g3 = 0;
			R1_CR1_MUX10_1_[1].tBit.cr1_r1g3 = 0;
			R1_CR1_MUX10_1_[2].tBit.cr1_r1g3 = 0;
			R1_CR1_MUX10_1_[3].tBit.cr1_r1g3 = 0;
			R1_CR1_MUX10_1_[4].tBit.cr1_r1g3 = 0;
			R1_CR1_MUX10_1_[0].tBit.cr1_r2g3 = 0;
			R1_CR1_MUX10_1_[1].tBit.cr1_r2g3 = 0;
			R1_CR1_MUX10_1_[2].tBit.cr1_r2g3 = 0;
			R1_CR1_MUX10_1_[3].tBit.cr1_r2g3 = 0;
			R1_CR1_MUX10_1_[4].tBit.cr1_r2g3 = 0;
			R1_CR1_MUX10_2_[0].tBit.cr1_r3g3 = 0;
			R1_CR1_MUX10_2_[1].tBit.cr1_r3g3 = 0;
			R1_CR1_MUX10_2_[2].tBit.cr1_r3g3 = 0;
			R1_CR1_MUX10_2_[3].tBit.cr1_r3g3 = 0;
			R1_CR1_MUX10_2_[4].tBit.cr1_r3g3 = 0;
			MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&R0_CR1_MUX1_1_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&R0_CR1_MUX1_2_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0108), (uint32_t *)&R0_CR1_MUX2_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x010C), (uint32_t *)&R0_CR1_MUX3_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0110), (uint32_t *)&R0_CR1_MUX4_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0114), (uint32_t *)&R0_CR1_MUX5_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0118), (uint32_t *)&R0_CR1_MUX6_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x011C), (uint32_t *)&R0_CR1_MUX7_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0120), (uint32_t *)&R0_CR1_MUX8_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0124), (uint32_t *)&R0_CR1_MUX9_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0128), (uint32_t *)&R0_CR1_MUX10_1_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x012C), (uint32_t *)&R0_CR1_MUX10_2_[0].ulBulk);

			MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&R1_CR1_MUX1_1_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&R1_CR1_MUX1_2_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0188), (uint32_t *)&R1_CR1_MUX2_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x018C), (uint32_t *)&R1_CR1_MUX3_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0190), (uint32_t *)&R1_CR1_MUX4_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0194), (uint32_t *)&R1_CR1_MUX5_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0198), (uint32_t *)&R1_CR1_MUX6_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x019C), (uint32_t *)&R1_CR1_MUX7_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01A0), (uint32_t *)&R1_CR1_MUX8_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01A4), (uint32_t *)&R1_CR1_MUX9_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01A8), (uint32_t *)&R1_CR1_MUX10_1_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01AC), (uint32_t *)&R1_CR1_MUX10_2_[0].ulBulk);
			/* Local tune set end */

			/* Global tune set start */
			R0_CR_GTUNE_[0].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk;
			R0_CR_GTUNE_[1].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[1].ulBulk;
			R0_CR_GTUNE_[2].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[2].ulBulk;
			R0_CR_GTUNE_[3].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[3].ulBulk;
			R0_CR_GTUNE_[4].ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[4].ulBulk;

			R0_CR_GTUNE_[0].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[1].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[2].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[3].tBit.cr_fg_gtune = 3;
			R0_CR_GTUNE_[4].tBit.cr_fg_gtune = 3;

			R1_CR_GTUNE_[0].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk;
			R1_CR_GTUNE_[1].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[1].ulBulk;
			R1_CR_GTUNE_[2].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[2].ulBulk;
			R1_CR_GTUNE_[3].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[3].ulBulk;
			R1_CR_GTUNE_[4].ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[4].ulBulk;

			R1_CR_GTUNE_[0].tBit.cr_fg_gtune = 0;
			R1_CR_GTUNE_[1].tBit.cr_fg_gtune = 0;
			R1_CR_GTUNE_[2].tBit.cr_fg_gtune = 0;
			R1_CR_GTUNE_[3].tBit.cr_fg_gtune = 0;
			R1_CR_GTUNE_[4].tBit.cr_fg_gtune = 0;
			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&R0_CR_GTUNE_[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&R1_CR_GTUNE_[0].ulBulk);
			/* Global tune set end */

			/* even odd start */
			tCFGR_TG_STUCK[0].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[0].ulBulk;
			tCFGR_TG_STUCK[1].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[1].ulBulk;
			tCFGR_TG_STUCK[2].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[2].ulBulk;
			tCFGR_TG_STUCK[3].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[3].ulBulk;
			tCFGR_TG_STUCK[4].ulBulk = s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[4].ulBulk;

			tCFGR_TG_STUCK[0].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[0].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[1].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[1].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[2].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[2].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[3].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[3].tBit.stuck_vcr_even_en = 1;

			tCFGR_TG_STUCK[4].tBit.stuck_vcr_odd_en = 3;
			tCFGR_TG_STUCK[4].tBit.stuck_vcr_even_en = 1;

			MSPI_RegisterMultiWrite((uint32_t)(0x0084), (uint32_t *)&tCFGR_TG_STUCK[0].ulBulk);
			/* even odd end */
			/* adc conversion rate 500KS/s setting start*/
			tCFGR_ADC_CTRL.ulBulk = s_pktmoduleSRICCommonConf->CFGR_ADC_CTRL.ulBulk;
			tCFGR_ADC_CTRL.tBit.adc_clk_prd = 2;
			MSPI_RegisterWrite((uint32_t)(0x0078), tCFGR_ADC_CTRL.ulBulk);
			/* adc conversion rate 500KS/s setting end*/
			break;
		case DIAG_CHANGE_SHORT2_TEST_RECOVERY:
			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);

			MSPI_RegisterWrite((uint32_t)(0x0078), s_pktmoduleSRICCommonConf->CFGR_ADC_CTRL.ulBulk);

			MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0108), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX2[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x010C), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX3[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0110), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX4[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0114), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX5[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0118), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX6[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x011C), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX7[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0120), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX8[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0124), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX9[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0128), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x012C), (uint32_t *)& s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[0].ulBulk);

			MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0188), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX2[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x018C), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX3[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0190), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX4[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0194), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX5[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0198), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX6[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x019C), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX7[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01A0), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX8[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01A4), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX9[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01A8), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01AC), (uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[0].ulBulk);

			MSPI_RegisterWrite((uint32_t)(0x0084), s_pktmoduleSRICCommonConf->CFGR_TG_STUCK[0].ulBulk);
			break;

//		case DIAG_CHANGE_SHORT2_TEST_GET_NORMAL:	// Normal
//			SRIC_Run(DISABLE);
//			SW92505_RegisterInit(HAL_GetSensingMode());
//			SRIC_Run(ENABLE);
//			break;
			
		case DIAG_CHANGE_OPEN_TEST_STEP1:
			tCFGR_DIC_CFG.ulBulk = s_pktmoduleSRICCommonConf->CFGR_DIC_CFG.ulBulk;
			tCFGR_DIC_CFG.tBit.sd_float = 1;
			tCFGR_DIC_CFG.tBit.cfgr_stuck_sd_stat = 1;
			tCFGR_DIC_CFG.tBit.sd_hvdd = 1;
			MSPI_RegisterWrite((uint32_t)(0x0030), tCFGR_DIC_CFG.ulBulk);

			tR0_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk;
			tR0_CR_GTUNE.tBit.cr_fg_gtune = 3;
			MSPI_RegisterWrite((uint32_t)(0x0130), tR0_CR_GTUNE.ulBulk);

			tR1_CR_GTUNE.ulBulk = s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk;
			tR1_CR_GTUNE.tBit.cr_fg_gtune = 3;
			MSPI_RegisterWrite((uint32_t)(0x01B0), tR1_CR_GTUNE.ulBulk);

			tCFGR_SENSE_CTRL.ulBulk = s_pktmoduleSRICCommonConf->CFGR_SENSE_CTRL.ulBulk;
			tCFGR_SENSE_CTRL.tBit.integ_half_f = 1;
			tCFGR_SENSE_CTRL.tBit.pre_gc_f = 3;
			tCFGR_SENSE_CTRL.tBit.int_gc_f = 3;
			MSPI_RegisterWrite((uint32_t)(0x01B8), tCFGR_SENSE_CTRL.ulBulk);
			break;
		case DIAG_CHANGE_OPEN_TEST_RECOVERY:
			MSPI_RegisterWrite((uint32_t)(0x0030), s_pktmoduleSRICCommonConf->CFGR_DIC_CFG.ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x01B8), s_pktmoduleSRICCommonConf->CFGR_SENSE_CTRL.ulBulk);
			break;
		default:
			break;
	}
}


#endif /* (USED_ROIC_DEF == ROIC_SW92505) */
