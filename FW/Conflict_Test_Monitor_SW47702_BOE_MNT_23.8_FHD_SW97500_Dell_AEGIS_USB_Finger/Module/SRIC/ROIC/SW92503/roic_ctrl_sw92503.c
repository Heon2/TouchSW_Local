/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : roic_ctrl_SW92503.c
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
#include "roic_ctrl_SW92503.h"
#include "param_def.h"


#if (USED_ROIC_DEF == ROIC_SW92503)

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
tSW92503_FullLocal_CFG_t tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg =
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
	.CFGR_PHTH_NUM2 = \
	{ \
		.tBit.phth0_num2 = PARAMSET_ROIC_MPP_CFGR_PHTH_NUM2_phth0_num2, \
		.tBit.phth1_num2 = PARAMSET_ROIC_MPP_CFGR_PHTH_NUM2_phth1_num2, \
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
			.tBit.mode = SW92503_MODE_BEACON, \
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
			.tBit.mode = SW92503_MODE_PEN_POS, \
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
			.tBit.mode = SW92503_MODE_PEN_DATA, \
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
			.tBit.mode = SW92503_MODE_PEN_DATA, \
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
			.tBit.mode = SW92503_MODE_PEN_DATA, \
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
			.tBit.mode = SW92503_MODE_PEN_POS, \
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
			.tBit.mode = SW92503_MODE_PEN_DATA, \
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
			.tBit.mode = SW92503_MODE_DUMMY, \
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
			.tBit.mode = SW92503_MODE_BEACON, \
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
			.tBit.mode = SW92503_MODE_PEN_DATA, \
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
			.tBit.mode = SW92503_MODE_DUMMY, \
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
			.tBit.mode = SW92503_MODE_DUMMY, \
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
			.tBit.mode = SW92503_MODE_FINGER, \
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
			.tBit.mode = SW92503_MODE_PEN_POS, \
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
			.tBit.mode = SW92503_MODE_FINGER, \
			.tBit.ping_en = 0, \
			.tBit.pre_drv = 1, \
			.tBit.pre_drvs_en = 0, \
			.tBit.extmuxcmd = 0, \
			.tBit.mux_type = 0, \
			.tBit.lhb_mux_cnt = 2, \
			.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_1Mux, \
			.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_2Mux, \
			.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_3Mux, \
			.tBit.local_pos3 =PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_4Mux, \
		},\
		[15] = \
		{ \
			.tBit.mode = SW92503_MODE_FINGER, \
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

tSW92503_FullLocal_CFG_t tSW92503ActivePen_Runtime_Change_WGP_Local_Reg =
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
	.CFGR_PHTH_NUM2 = \
	{ \
		.tBit.phth0_num2 = PARAMSET_ROIC_CFGR_PHTH_NUM2_phth0_num2, \
		.tBit.phth1_num2 = PARAMSET_ROIC_CFGR_PHTH_NUM2_phth1_num2, \
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

static void SW92503_Reg_CRTuneSetting(void)
{
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
}

static void SW92503_Reg_LHBSetting(uint32_t ulType)
{
	uint32_t ulIdx;
	for(ulIdx = 0; ulIdx < SW92503_MAX_LHB_NUM; ulIdx++)
	{
		MSPI_RegisterWrite((uint32_t)(0x009C + (0x4 * ulIdx)), s_pktmoduleSRICCommonConf->LHB_CFG[ulType][ulIdx].ulBulk);
	}
}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
static void SW92503_Reg_LHBSetting_ByChangeMode(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
	uint32_t ulIdx;
	tLHB_CFG_t * pLHB_CFG;
	switch(eMode)
	{
		case ROIC_REG_SET_CHAGNE_WGPPen_Local_Setting:
		{
			pLHB_CFG = &tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.LHB_CFG[0];
			break;
		}
		case ROIC_REG_SET_CHAGNE_MSPen_Local_Setting:
		{
			pLHB_CFG = &tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.LHB_CFG[0];
			break;
		}
	}
	for(ulIdx = 0; ulIdx < SW92503_MAX_LHB_NUM; ulIdx++)
	{
		MSPI_RegisterWrite((uint32_t)(0x009C + (0x4 * ulIdx)), pLHB_CFG[ulIdx].ulBulk);
	}
}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */

void SW92503_Initialize(void)
{
	s_pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
}

void SW92503_Reset(eSENSING_MODE_t eSensingMode)
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

bool_t SW92503_RegisterInit(eSENSING_MODE_t eSensingMode)
{
	bool_t bReg = YES;
//	uint32_t ulIdx;
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
	MSPI_RegisterWrite((uint32_t)(0x0004), s_pktmoduleSRICCommonConf->SPIS_CFG.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0008), s_pktmoduleSRICCommonConf->SPIS_ERROR_CLR.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x000C), s_pktmoduleSRICCommonConf->SPIS_ERROR_ST.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0010), s_pktmoduleSRICCommonConf->SPIS_PAD_CTL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0014), s_pktmoduleSRICCommonConf->CFGR_SYS_CFG.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0018), s_pktmoduleSRICCommonConf->CFGR_TC_START.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x001C), s_pktmoduleSRICCommonConf->CFGR_TC_STOP.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0020), s_pktmoduleSRICCommonConf->CFGR_R0_CH_EN.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0024), s_pktmoduleSRICCommonConf->CFGR_R1_CH_EN.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0028), s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x002C), s_pktmoduleSRICCommonConf->CFGR_MUX_DLY.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0030), s_pktmoduleSRICCommonConf->CFGR_DIC_CFG.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->CFGR_PWM_CTL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0038), s_pktmoduleSRICCommonConf->CFGR_PWM_POS_CTL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x003C), s_pktmoduleSRICCommonConf->CFGR_PWM_DAT_CTL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0040), s_pktmoduleSRICCommonConf->ND_CTRL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0044), s_pktmoduleSRICCommonConf->CFGR_PWM_PRD.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->CFGR_SMPL_CTL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x004C), s_pktmoduleSRICCommonConf->CFGR_RSTP_NUM1.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0050), s_pktmoduleSRICCommonConf->CFGR_PHTCR_NUM1.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0054), s_pktmoduleSRICCommonConf->CFGR_PHTCR_NUM2.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0058), s_pktmoduleSRICCommonConf->CFGR_VCR_NUM1.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x005C), s_pktmoduleSRICCommonConf->CFGR_VCR_EN_NUM1.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0060), s_pktmoduleSRICCommonConf->CFGR_VCR_EN_NUM2.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0064), s_pktmoduleSRICCommonConf->CFGR_PHTH0_NUM1.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0068), s_pktmoduleSRICCommonConf->CFGR_PHTH1_NUM1.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x006C), s_pktmoduleSRICCommonConf->CFGR_PHTH_NUM2.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0070), s_pktmoduleSRICCommonConf->CFGR_PHT_CTL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0074), s_pktmoduleSRICCommonConf->CFGR_PHT_NUM1.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0078), s_pktmoduleSRICCommonConf->CFGR_ADC_CTRL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x007C), s_pktmoduleSRICCommonConf->CFGR_VCOMR_OPT.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0080), s_pktmoduleSRICCommonConf->CFGR_BUF_OPT.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0084), s_pktmoduleSRICCommonConf->CFGR_TG_STUCK.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0088), s_pktmoduleSRICCommonConf->CFGR_ADC_IN.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x008C), s_pktmoduleSRICCommonConf->CFGR_MUX_S_STUCK_VAL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0090), s_pktmoduleSRICCommonConf->CFGR_MUX_F_STUCK_VAL.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0094), s_pktmoduleSRICCommonConf->CFGR_MUX_CFG_00.ulBulk);
	MSPI_RegisterWrite((uint32_t)(0x0098), s_pktmoduleSRICCommonConf->CFGR_MUX_CFG_01.ulBulk);

	if(IS_FINGER_PEN_MODE(eSensingMode))
	{
		SW92503_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);
	}
	else
	{
		SW92503_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
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
	SW92503_Reg_CRTuneSetting();
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

void SW92503_Run(uint8_t Enable)
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
void SW92503_SetLocalIndex(uint32_t ulIdx)
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
#if USED_WGP_16LHB_ACTIVEPEN
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
#else /* USED_WGP_16LHB_ACTIVEPEN */
		case 2:
		{
			ulStartLHBIndex = 4;
			ulEndLHBIndex = 6;
			break;
		}
		case 6:
		{
			ulStartLHBIndex = 8;
			ulEndLHBIndex = 11;
			break;
		}
		case 10:
		{
			ulStartLHBIndex = 12;
			ulEndLHBIndex = 14;
			break;
		}
		case 0:
		{
			ulStartLHBIndex = 1;
			ulEndLHBIndex = 3;
			break;
		}
#endif /* USED_WGP_16LHB_ACTIVEPEN */
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) */
	}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
	
	tHalIntrHandle.ulLocalSensingDoneRowIdx = ulLocalIndex;
#ifdef TILT_ON
	if((ulMSPIIndex == 0 || ulMSPIIndex == 6) && hal_Info_GetControlActivePenSettingType() == ACTIVEPEN_TYPE_LOCAL_WGP)
	{
		tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt;
	}
	else if((/*ulMSPIIndex == 0 ||*/ ulMSPIIndex == 6) && hal_Info_GetControlActivePenSettingType() == ACTIVEPEN_TYPE_LOCAL_MS)
	{
		tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt;
	}
#endif /* TILT_ON */

	for(_ulIndex = ulStartLHBIndex; _ulIndex <= ulEndLHBIndex; _ulIndex++)
	{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		switch(hal_Info_GetControlActivePenSettingType())
		{
			case ACTIVEPEN_TYPE_LOCAL_MS:
			{
				tLHB_CFG.ulBulk = tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.LHB_CFG[_ulIndex].ulBulk;
				break;
			}
			case ACTIVEPEN_TYPE_LOCAL_WGP:
			{
				tLHB_CFG.ulBulk = tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.LHB_CFG[_ulIndex].ulBulk;
				break;
			}
		}
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
		tLHB_CFG.ulBulk = s_pktmoduleSRICCommonConf->LHB_CFG[PWM_LOCAL_PEN_MODE][_ulIndex].ulBulk;
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */

		if(tLHB_CFG.tBit.mode == SW92503_MODE_PEN_POS ||
			tLHB_CFG.tBit.mode == SW92503_MODE_PEN_DATA)
		{
			uint8_t shift_val = 0;
			uint8_t shift_direc = 0;
#ifdef TILT_ON
#if USED_WGP_16LHB_ACTIVEPEN
			if( ((ulMSPIIndex == 0 && _ulIndex == 4) || (ulMSPIIndex == 6 && _ulIndex == 12)) &&
				hal_Info_GetControlActivePenSettingType() == ACTIVEPEN_TYPE_LOCAL_WGP)
#else /* USED_WGP_16LHB_ACTIVEPEN */
			if( ((ulMSPIIndex == 0 && _ulIndex == 3) || (ulMSPIIndex == 6 && _ulIndex == 11)) &&
				hal_Info_GetControlActivePenSettingType() == ACTIVEPEN_TYPE_LOCAL_WGP)
#endif /* USED_WGP_16LHB_ACTIVEPEN */
			{
				tLHB_CFG.tBit.local_pos0 = sensingRowStart_Tilt;
			}
			else if(hal_Info_GetControlActivePenSettingType() == ACTIVEPEN_TYPE_LOCAL_MS && ((ulMSPIIndex == 6 && _ulIndex == 9) /*|| (ulMSPIIndex == 0 && _ulIndex == 1)*/))
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
				tLHB_CFG.tBit.local_pos1 = 0;//shift_val;
				tLHB_CFG.tBit.local_pos2 = 0;//shift_direc;
			}
			MSPI_RegisterWrite(ulLocalIndexAddress[_ulIndex], tLHB_CFG.ulBulk);
		}
	}
}

void SW92503_SetIdleOperationMode(void)
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

void SW92503_SetActiveOperationMode(void)
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

//void SW92503_SetFingerPenFullModeChange(bool_t bIsFullMode)
//{
//	if(bIsFullMode)
//	{
//		SW92503_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
//	}
//	else
//	{
//		SW92503_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);
//	}
//}

void SW92503_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
//	uint32_t ulIndex;
	switch(eMode)
	{
		case ROIC_REG_SET_CHANGE_MUX_REMAP:
		{
			break;
		}
		case ROIC_REG_SET_CHAGNE_CR_TUNE:
		{
			SW92503_Reg_CRTuneSetting();
			break;
		}
		case ROIC_REG_SET_CHAGNE_WGPPen_Local_Setting: // WGP Local
		{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			MSPI_RegisterWrite((uint32_t)(0x0034), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0038), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_POS_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x003C), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_DAT_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0040), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.ND_CTRL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0044), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_PRD.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x004C), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_RSTP_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0050), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0054), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTCR_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0058), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_VCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x005C), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_VCR_EN_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x006C), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTH_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x00DC), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_SET_EN_BIT.ulBulk);
			SW92503_Reg_LHBSetting_ByChangeMode(ROIC_REG_SET_CHAGNE_WGPPen_Local_Setting);
			MSPI_RegisterWrite((uint32_t)(0x01B8), tSW92503ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_SENSE_CTRL.ulBulk);
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
			MSPI_RegisterWrite((uint32_t)(0x0034), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0038), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_POS_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x003C), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_DAT_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0040), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.ND_CTRL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0044), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_PRD.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x004C), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_RSTP_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0050), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0054), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTCR_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0058), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_VCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x005C), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_VCR_EN_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x006C), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTH_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x00DC), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_SET_EN_BIT.ulBulk);
			SW92503_Reg_LHBSetting_ByChangeMode(ROIC_REG_SET_CHAGNE_MSPen_Local_Setting);
			MSPI_RegisterWrite((uint32_t)(0x01B8), tSW92503ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_SENSE_CTRL.ulBulk);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
			break;
		}
		case ROIC_REG_SET_CHAGNE_MSPen_Full_Setting: // MS Full
		{
			break;
		}
		case ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_ACTIVE:
		{
			SW92503_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);
			break;
		}
		case ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_IDLE:
		{
			SW92503_Reg_LHBSetting(PWM_LOCAL_PEN_IDLE_MODE);
			break;
		}
		case ROIC_REG_SET_CHANGE_FINGER_PEN_FULL:
		{
			SW92503_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
			break;
		}
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
	/*SRIC_0*/ /*R0*/0,	0,	0,	0,	0,	0,	0,	/*R1*/6,	6,	6,	6,	6,	6,	6,
	/*SRIC_1*/ /*R0*/1,	1,	1,	1,	1,	1,	1,	/*R1*/7,	7,	7,	7,	7,	7,	7,
	/*SRIC_2*/ /*R0*/2,	2,	2,	2,	2,	2,	2,	/*R1*/8,	8,	8,	8,	8,	8,	8,
	/*SRIC_3*/ /*R0*/3,	3,	3,	3,	3,	3,	3,	/*R1*/9,	9,	9,	9,	9,	9,	9,
	/*SRIC_4*/ /*R0*/4,	4,	4,	4,	4,	4,	4,	/*R1*/10,	10,	10,	10,	10,	10,	10,
	/*SRIC_5*/ /*R0*/5,	5,	5,	5,	5,	5,	5,	/*R1*/11,	11,	11,	11,	11,	11,	11,
};

uint8_t ulROIC_gNum[COL_MAX] = {
	/* Group Idx */ /*R0*/0,	1,	1,	1,	1,	1,	2,	/*R1*/2,	1,	1,	1,	1,	1,	0,
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
}__PACKED tSW92503_ROIC_CR_MUX_t;

extern tParamPreMainSet_t * s_ptParamPreMainSet;
tModuleSRICCommonConf_t * g_ptSRICConfig;

tSW92503_ROIC_CR_MUX_t * g_pR0_CR_MUX_Tune;
tSW92503_ROIC_CR_MUX_t * g_pR1_CR_MUX_Tune;
bool_t bISAllFinish = NO;
uint16_t usTemp_RawData;

#define AUTO_CAL_AVERAGE_FRAME_NUM			(100)
void SW92503_RawDataCalibration(void)
{
	bool_t bIsLoop = YES;
	uint32_t r, c, g, framenum;
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
	g_pR0_CR_MUX_Tune = (tSW92503_ROIC_CR_MUX_t *)&g_ptSRICConfig->R0_CR1_MUX1_1[0].ulBulk;
	g_pR1_CR_MUX_Tune = (tSW92503_ROIC_CR_MUX_t *)&g_ptSRICConfig->R1_CR1_MUX1_1[0].ulBulk;

	memset((void*)(&AutoCalfinish_R0[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_TUNE_ROW_GROUP_NUM*MSPI_NUM*DEF_ROIC_TUNE_COL_GROUP_NUM);
	memset((void*)(&AutoCalfinish_R1[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_TUNE_ROW_GROUP_NUM*MSPI_NUM*DEF_ROIC_TUNE_COL_GROUP_NUM);

    tHalIntrHandle.ulLocalIndexChangeStart = 1;
#if (USED_ONLY_LOCAL_MODE == NO)
	if(IS_FINGER_PEN_MODE(HAL_GetSensingMode()))
	{
		HAL_SetSensingChangeMode(SM_CHANGE_FINGER_PEN_SEARCH_MODE);
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

		protocol_LogMatrix(LT_RAWDATA, 84, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);
		protocol_LogPaddedMatrix(LT_INTENSITY, 84, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);

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


#endif /* (USED_ROIC_DEF == ROIC_SW92503) */
