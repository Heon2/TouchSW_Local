/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : roic_ctrl_SW92512.c
 * created on : 29. 12. 2020
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
#include "roic_ctrl_SW92512.h"
#include "param_def.h"


#if (USED_ROIC_DEF == ROIC_SW92512)

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
tSW92512_FullLocal_CFG_t tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg =
{
	.CFGR_PWM_CTL =
	{
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_MPP_PWM_CTL_pwm_pdrv_num,
		.tBit.pwm_act_num = PARAMSET_ROIC_MPP_PWM_CTL_pwm_act_num,
		.tBit.pwm_smpl_num = PARAMSET_ROIC_MPP_PWM_CTL_pwm_smpl_num,
		.tBit.pwm_dum_num = PARAMSET_ROIC_MPP_PWM_CTL_pwm_dum_num,
		.tBit.pdrv_dum_num = PARAMSET_ROIC_MPP_PWM_CTL_pdrv_dum_num,
		.tBit.pwm_set_num = PARAMSET_ROIC_MPP_PWM_CTL_pwm_set_num,
	},
	.CFGR_PWM_POS_CTL =
	{
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_pdrv_num,
		.tBit.pwm_act_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_act_num,
		.tBit.pwm_smpl_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_smpl_num,
		.tBit.pwm_dum_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_dum_num,
		.tBit.pdrv_dum_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pdrv_dum_num,
		.tBit.pwm_set_num = PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_set_num,
	},
	.CFGR_PWM_DAT_CTL =
	{
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_pdrv_num,
		.tBit.pwm_act_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_act_num,
		.tBit.pwm_smpl_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_smpl_num,
		.tBit.pwm_dum_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_dum_num,
		.tBit.pdrv_dum_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pdrv_dum_num,
		.tBit.pwm_set_num = PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_set_num,
	},
	.ND_CTRL =
	{
		.tBit.nd_dum_dly = PARAMSET_ROIC_MPP_ND_CTRL_nd_dum_dly,
	},
	.CFGR_PWM_PRD =
	{
		.tBit.pwm_prd1 = PARAMSET_ROIC_MPP_CFGR_PWM_PRD_pwm_prd1,
		.tBit.pwm_prd2 = PARAMSET_ROIC_MPP_CFGR_PWM_PRD_pwm_prd2,
	},
	.CFGR_RSTP_NUM1 =
	{
		.tBit.rstp_num1 = PARAMSET_ROIC_MPP_CFGR_RSTP_NUM1_rstp_num1,
		.tBit.rstp_num2 = PARAMSET_ROIC_MPP_CFGR_RSTP_NUM1_rstp_num2,
	},
	.CFGR_PHTCR_NUM1 =
	{
		.tBit.phtcr_num1_1 = PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM1_phtcr_num1_1,
		.tBit.phtcr_num1_2 = PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM1_phtcr_num1_2,
	},
	.CFGR_PHTCR_NUM2 =
	{
		.tBit.phtcr_num2_1 = PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM2_phtcr_num2_1,
		.tBit.phtcr_num2_2 = PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM2_phtcr_num2_2,
	},
	.CFGR_VCR_NUM1 =
	{
		.tBit.vcr_num1_1 = PARAMSET_ROIC_MPP_CFGR_VCR_NUM1_vcr_num1_1,
		.tBit.vcr_num1_2 = PARAMSET_ROIC_MPP_CFGR_VCR_NUM1_vcr_num1_2,
	},
	.CFGR_VCR_EN_NUM1 =
	{
		.tBit.vcr_en_num1_1 = PARAMSET_ROIC_MPP_CFGR_VCR_EN_NUM1_vcr_en_num1_1,
		.tBit.vcr_en_num1_2 = PARAMSET_ROIC_MPP_CFGR_VCR_EN_NUM1_vcr_en_num1_2,
	},
	.CFGR_PHTH0_NUM1 =
	{
		.tBit.phth0_num1_1 = PARAMSET_ROIC_MPP_CFGR_PHTH0_NUM1_phth0_num1_1,
		.tBit.phth0_num1_2 = PARAMSET_ROIC_MPP_CFGR_PHTH0_NUM1_phth0_num1_2,
	},
	.CFGR_PHTH1_NUM1 =
	{
		.tBit.phth1_num1_1 = PARAMSET_ROIC_MPP_CFGR_PHTH1_NUM1_phth1_num1_1,
		.tBit.phth1_num1_2 = PARAMSET_ROIC_MPP_CFGR_PHTH1_NUM1_phth1_num1_2,
	},
	.CFGR_PHTH_NUM2 =
	{
		.tBit.phth0_num2 = PARAMSET_ROIC_MPP_CFGR_PHTH_NUM2_phth0_num2,
		.tBit.phth1_num2 = PARAMSET_ROIC_MPP_CFGR_PHTH_NUM2_phth1_num2,
	},
	.CFGR_PHT_NUM1 =
	{
		.tBit.pht_num1 = PARAMSET_ROIC_MPP_CFGR_PHT_NUM1_pht_num1,
		.tBit.pht_num2 = PARAMSET_ROIC_MPP_CFGR_PHT_NUM1_pht_num2,
	},
	.CFGR_PWM_SET_EN_BIT =
	{
		.tBit.pwm_set_en_finger = PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_finger,
		.tBit.pwm_set_en_pen_pos = PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_pos,
		.tBit.pwm_set_en_pen_dat = PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_dat,
	},
	.LHB_CFG = {
		[0] =
		{
			.tBit.mode = SW92512_MODE_BEACON,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 0,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 0,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[1] =
		{
			.tBit.mode = SW92512_MODE_PEN_POS,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 1,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 5,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[2] =
		{
			.tBit.mode = SW92512_MODE_PEN_DATA,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 1,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 5,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[3] =
		{
			.tBit.mode = SW92512_MODE_PEN_DATA,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 1,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 5,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[4] =
		{
			.tBit.mode = SW92512_MODE_PEN_DATA,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 1,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 5,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[5] =
		{
			.tBit.mode = SW92512_MODE_PEN_POS,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 1,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 5,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[6] =
		{
			.tBit.mode = SW92512_MODE_PEN_DATA,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 1,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 5,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[7] =
		{
			.tBit.mode = SW92512_MODE_DUMMY,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 0,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 0,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[8] =
		{
			.tBit.mode = SW92512_MODE_BEACON,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 0,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 0,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[9] =
		{
			.tBit.mode = SW92512_MODE_PEN_DATA,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 1,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 5,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[10] =
		{
			.tBit.mode = SW92512_MODE_DUMMY,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 0,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 0,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[11] =
		{
			.tBit.mode = SW92512_MODE_DUMMY,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 0,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 0,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[12] =
		{
			.tBit.mode = SW92512_MODE_FINGER,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 1,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 2,
			.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_1Mux,
			.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_2Mux,
			.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_3Mux,
			.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_4Mux,
		},\
		[13] =
		{
			.tBit.mode = SW92512_MODE_PEN_POS,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 1,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 5,
			.tBit.local_pos0 = 0,
			.tBit.local_pos1 = 0,
			.tBit.local_pos2 = 0,
			.tBit.local_pos3 = 0,
		},\
		[14] =
		{
			.tBit.mode = SW92512_MODE_FINGER,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 1,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 2,
			.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_1Mux,
			.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_2Mux,
			.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_3Mux,
			.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_4Mux,
		},\
		[15] =
		{
			.tBit.mode = SW92512_MODE_FINGER,
			.tBit.ping_en = 0,
			.tBit.pre_drv = 1,
			.tBit.pre_drvs_en = 0,
			.tBit.extmuxcmd = 0,
			.tBit.mux_type = 0,
			.tBit.lhb_mux_cnt = 2,
			.tBit.local_pos0 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_1Mux,
			.tBit.local_pos1 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_2Mux,
			.tBit.local_pos2 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_3Mux,
			.tBit.local_pos3 = PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_4Mux,
		},\
	},
	.CFGR_SENSE_CTRL =
	{
		.tBit.lv_ssu_bcon = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_lv_ssu_bcon,
		.tBit.lv_ssu_bcons = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_lv_ssu_bcons,
		.tBit.hv_ssu_bcon = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_hv_ssu_bcon,
		.tBit.pen_dc_md = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pen_dc_md,
		.tBit.pen_dc_md_stuck = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pen_dc_md_stuck,
		.tBit.integ_half_f = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_f,
		.tBit.integ_half_comp = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_comp,
		.tBit.integ_half_p = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_p,
		.tBit.pre_gc_f = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_f,
		.tBit.pre_gc_comp = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_comp,
		.tBit.pre_gc_p = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_p,
		.tBit.int_gc_f = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_f,
		.tBit.int_gc_comp = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_comp,
		.tBit.int_gc_p = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_p,
		.tBit.powsel = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_powsel,
		.tBit.pre_bs_lp = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_bs_lp,
		.tBit.int_bs_lp = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_bs_lp,
		.tBit.tm_ssu_pen = PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_tm_ssu_pen,
	},
};

tSW92512_FullLocal_CFG_t tSW92512ActivePen_Runtime_Change_WGP_Local_Reg =
{
	.CFGR_PWM_CTL =
	{
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_CTL_pwm_pdrv_num,
		.tBit.pwm_act_num = PARAMSET_ROIC_PWM_CTL_pwm_act_num,
		.tBit.pwm_smpl_num = PARAMSET_ROIC_PWM_CTL_pwm_smpl_num,
		.tBit.pwm_dum_num = PARAMSET_ROIC_PWM_CTL_pwm_dum_num,
		.tBit.pdrv_dum_num = PARAMSET_ROIC_PWM_CTL_pdrv_dum_num,
		.tBit.pwm_set_num = PARAMSET_ROIC_PWM_CTL_pwm_set_num,
	},
	.CFGR_PWM_POS_CTL =
	{
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_pdrv_num,
		.tBit.pwm_act_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_act_num,
		.tBit.pwm_smpl_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_smpl_num,
		.tBit.pwm_dum_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_dum_num,
		.tBit.pdrv_dum_num = PARAMSET_ROIC_PWM_POS_CTL_pdrv_dum_num,
		.tBit.pwm_set_num = PARAMSET_ROIC_PWM_POS_CTL_pwm_set_num,
	},
	.CFGR_PWM_DAT_CTL =
	{
		.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_DAT_CTL_pwm_pdrv_num,
		.tBit.pwm_act_num = PARAMSET_ROIC_PWM_DAT_CTL_pwm_act_num,
		.tBit.pwm_smpl_num = PARAMSET_ROIC_PWM_DAT_CTL_pwm_smpl_num,
		.tBit.pwm_dum_num = PARAMSET_ROIC_PWM_DAT_CTL_pwm_dum_num,
		.tBit.pdrv_dum_num = PARAMSET_ROIC_PWM_DAT_CTL_pdrv_dum_num,
		.tBit.pwm_set_num = PARAMSET_ROIC_PWM_DAT_CTL_pwm_set_num,
	},
	.ND_CTRL =
	{
		.tBit.nd_dum_dly = PARAMSET_ROIC_ND_CTRL_nd_dum_dly,
	},
	.CFGR_PWM_PRD =
	{
		.tBit.pwm_prd1 = PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd1,
		.tBit.pwm_prd2 = PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd2,
	},
	.CFGR_RSTP_NUM1 =
	{
		.tBit.rstp_num1 = PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num1,
		.tBit.rstp_num2 = PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num2,
	},
	.CFGR_PHTCR_NUM1 =
	{
		.tBit.phtcr_num1_1 = PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_1,
		.tBit.phtcr_num1_2 = PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_2,
	},
	.CFGR_PHTCR_NUM2 =
	{
		.tBit.phtcr_num2_1 = PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_1,
		.tBit.phtcr_num2_2 = PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_2,
	},
	.CFGR_VCR_NUM1 =
	{
		.tBit.vcr_num1_1 = PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_1,
		.tBit.vcr_num1_2 = PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_2,
	},
	.CFGR_VCR_EN_NUM1 =
	{
		.tBit.vcr_en_num1_1 = PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_1,
		.tBit.vcr_en_num1_2 = PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_2,
	},
	.CFGR_PHTH0_NUM1 =
	{
		.tBit.phth0_num1_1 = PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_1,
		.tBit.phth0_num1_2 = PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_2,
	},
	.CFGR_PHTH1_NUM1 =
	{
		.tBit.phth1_num1_1 = PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_1,
		.tBit.phth1_num1_2 = PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_2,
	},
	.CFGR_PHTH_NUM2 =
	{
		.tBit.phth0_num2 = PARAMSET_ROIC_CFGR_PHTH_NUM2_phth0_num2,
		.tBit.phth1_num2 = PARAMSET_ROIC_CFGR_PHTH_NUM2_phth1_num2,
	},
	.CFGR_PHT_NUM1 =
	{
		.tBit.pht_num1 = PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num1,
		.tBit.pht_num2 = PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num2,
	},
	.CFGR_PWM_SET_EN_BIT =
	{
		.tBit.pwm_set_en_finger = PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_finger,
		.tBit.pwm_set_en_pen_pos = PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_pos,
		.tBit.pwm_set_en_pen_dat = PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_dat,
	},
	.LHB_CFG = {
		[0] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_1_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_1_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_1_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_1_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_1_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_1_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_1_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_1_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_1_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_1_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_1_local_pos3,
		},\
		[1] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_2_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_2_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_2_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_2_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_2_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_2_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_2_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_2_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_2_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_2_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_2_local_pos3,
		},\
		[2] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_3_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_3_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_3_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_3_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_3_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_3_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_3_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_3_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_3_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_3_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_3_local_pos3,
		},\
		[3] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_4_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_4_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_4_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_4_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_4_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_4_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_4_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_4_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_4_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_4_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_4_local_pos3,
		},\
		[4] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_5_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_5_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_5_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_5_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_5_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_5_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_5_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_5_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_5_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_5_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_5_local_pos3,
		},\
		[5] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_6_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_6_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_6_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_6_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_6_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_6_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_6_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_6_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_6_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_6_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_6_local_pos3,
		},\
		[6] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_7_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_7_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_7_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_7_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_7_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_7_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_7_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_7_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_7_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_7_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_7_local_pos3,
		},\
		[7] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_8_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_8_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_8_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_8_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_8_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_8_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_8_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_8_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_8_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_8_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_8_local_pos3,
		},\
		[8] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_9_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_9_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_9_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_9_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_9_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_9_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_9_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_9_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_9_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_9_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_9_local_pos3,
		},\
		[9] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_10_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_10_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_10_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_10_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_10_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_10_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_10_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_10_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_10_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_10_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_10_local_pos3,
		},\
		[10] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_11_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_11_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_11_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_11_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_11_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_11_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_11_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_11_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_11_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_11_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_11_local_pos3,
		},\
		[11] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_12_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_12_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_12_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_12_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_12_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_12_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_12_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_12_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_12_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_12_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_12_local_pos3,
		},\
		[12] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_13_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_13_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_13_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_13_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_13_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_13_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_13_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_13_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_13_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_13_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_13_local_pos3,
		},\
		[13] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_14_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_14_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_14_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_14_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_14_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_14_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_14_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_14_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_14_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_14_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_14_local_pos3,
		},\
		[14] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_15_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_15_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_15_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_15_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_15_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_15_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_15_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_15_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_15_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_15_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_15_local_pos3,
		},\
		[15] =
		{
			.tBit.mode = PARAMSET_ROIC_LOCAL_LHB_16_mode,
			.tBit.ping_en = PARAMSET_ROIC_LOCAL_LHB_16_ping_en,
			.tBit.pre_drv = PARAMSET_ROIC_LOCAL_LHB_16_pre_drv,
			.tBit.pre_drvs_en = PARAMSET_ROIC_LOCAL_LHB_16_pre_drvs_en,
			.tBit.extmuxcmd = PARAMSET_ROIC_LOCAL_LHB_16_extmuxcmd,
			.tBit.mux_type = PARAMSET_ROIC_LOCAL_LHB_16_mux_type,
			.tBit.lhb_mux_cnt = PARAMSET_ROIC_LOCAL_LHB_16_lhb_mux_cnt,
			.tBit.local_pos0 = PARAMSET_ROIC_LOCAL_LHB_16_local_pos0,
			.tBit.local_pos1 = PARAMSET_ROIC_LOCAL_LHB_16_local_pos1,
			.tBit.local_pos2 = PARAMSET_ROIC_LOCAL_LHB_16_local_pos2,
			.tBit.local_pos3 = PARAMSET_ROIC_LOCAL_LHB_16_local_pos3,
		},\
	},
	.CFGR_SENSE_CTRL =
	{
		.tBit.lv_ssu_bcon = PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcon,
		.tBit.lv_ssu_bcons = PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcons,
		.tBit.hv_ssu_bcon = PARAMSET_ROIC_CFGR_SENSE_CTRL_hv_ssu_bcon,
		.tBit.pen_dc_md = PARAMSET_ROIC_CFGR_SENSE_CTRL_pen_dc_md,
		.tBit.pen_dc_md_stuck = PARAMSET_ROIC_CFGR_SENSE_CTRL_pen_dc_md_stuck,
		.tBit.integ_half_f = PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_f,
		.tBit.integ_half_comp = PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_comp,
		.tBit.integ_half_p = PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_p,
		.tBit.pre_gc_f = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_f,
		.tBit.pre_gc_comp = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_comp,
		.tBit.pre_gc_p = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_p,
		.tBit.int_gc_f = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_f,
		.tBit.int_gc_comp = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_comp,
		.tBit.int_gc_p = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_p,
		.tBit.powsel = PARAMSET_ROIC_CFGR_SENSE_CTRL_powsel,
		.tBit.pre_bs_lp = PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_bs_lp,
		.tBit.int_bs_lp = PARAMSET_ROIC_CFGR_SENSE_CTRL_int_bs_lp,
		.tBit.tm_ssu_pen = PARAMSET_ROIC_CFGR_SENSE_CTRL_tm_ssu_pen,
	},
};
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */

#if USED_NOISE_HOPPING_FREQ
tSW92512_CRReg_CFG_t tSW92512_HoppFrqCRReg_CFG =
{
	.R0_CR1_MUX1_1 =
	{
		[0] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_0_R0_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_0_R0_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_0_R0_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_0_R0_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_0_R0_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_0_R0_1stMux_Middle_Line_g3,
		},
		[1] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_1_R0_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_1_R0_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_1_R0_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_1_R0_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_1_R0_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_1_R0_1stMux_Middle_Line_g3,
		},
		[2] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_2_R0_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_2_R0_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_2_R0_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_2_R0_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_2_R0_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_2_R0_1stMux_Middle_Line_g3,
		},
		[3] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_3_R0_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_3_R0_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_3_R0_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_3_R0_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_3_R0_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_3_R0_1stMux_Middle_Line_g3,
		},
		[4] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_4_R0_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_4_R0_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_4_R0_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_4_R0_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_4_R0_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_4_R0_1stMux_Middle_Line_g3,
		},
		[5] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_5_R0_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_5_R0_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_5_R0_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_5_R0_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_5_R0_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_5_R0_1stMux_Middle_Line_g3,
		},
	},
	.R0_CR1_MUX1_2 =
	{
		[0] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_0_R0_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_0_R0_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_0_R0_1stMux_Bottom_Line_g3,
		},
		[1] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_1_R0_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_1_R0_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_1_R0_1stMux_Bottom_Line_g3,
		},
		[2] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_2_R0_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_2_R0_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_2_R0_1stMux_Bottom_Line_g3,
		},
		[3] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_3_R0_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_3_R0_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_3_R0_1stMux_Bottom_Line_g3,
		},
		[4] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_4_R0_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_4_R0_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_4_R0_1stMux_Bottom_Line_g3,
		},
		[5] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_5_R0_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_5_R0_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_5_R0_1stMux_Bottom_Line_g3,
		},
	},
	.R0_CR1_MUX2 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R0_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R0_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R0_2ndMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R0_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R0_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R0_2ndMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R0_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R0_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R0_2ndMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R0_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R0_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R0_2ndMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R0_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R0_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R0_2ndMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R0_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R0_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R0_2ndMux_g3,
		},
	},
	.R0_CR1_MUX3 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R0_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R0_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R0_3rdMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R0_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R0_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R0_3rdMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R0_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R0_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R0_3rdMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R0_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R0_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R0_3rdMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R0_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R0_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R0_3rdMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R0_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R0_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R0_3rdMux_g3,
		},
	},
	.R0_CR1_MUX4 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R0_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R0_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R0_4thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R0_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R0_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R0_4thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R0_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R0_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R0_4thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R0_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R0_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R0_4thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R0_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R0_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R0_4thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R0_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R0_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R0_4thMux_g3,
		},
	},
	.R0_CR1_MUX5 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R0_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R0_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R0_5thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R0_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R0_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R0_5thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R0_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R0_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R0_5thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R0_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R0_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R0_5thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R0_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R0_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R0_5thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R0_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R0_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R0_5thMux_g3,
		},
	},
	.R0_CR1_MUX6 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R0_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R0_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R0_6thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R0_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R0_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R0_6thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R0_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R0_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R0_6thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R0_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R0_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R0_6thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R0_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R0_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R0_6thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R0_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R0_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R0_6thMux_g3,
		},
	},
	.R0_CR1_MUX7 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R0_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R0_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R0_7thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R0_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R0_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R0_7thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R0_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R0_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R0_7thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R0_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R0_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R0_7thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R0_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R0_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R0_7thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R0_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R0_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R0_7thMux_g3,
		},
	},
	.R0_CR1_MUX8 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R0_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R0_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R0_8thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R0_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R0_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R0_8thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R0_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R0_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R0_8thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R0_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R0_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R0_8thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R0_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R0_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R0_8thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R0_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R0_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R0_8thMux_g3,
		},
	},
	.R0_CR1_MUX9 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R0_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R0_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R0_9thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R0_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R0_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R0_9thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R0_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R0_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R0_9thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R0_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R0_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R0_9thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R0_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R0_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R0_9thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R0_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R0_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R0_9thMux_g3,
		},
	},
	.R0_CR1_MUX10_1 =
	{
		[0] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_0_R0_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_0_R0_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_0_R0_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_0_R0_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_0_R0_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_0_R0_LastMux_Middle_Line_g3,
		},
		[1] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_1_R0_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_1_R0_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_1_R0_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_1_R0_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_1_R0_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_1_R0_LastMux_Middle_Line_g3,
		},
		[2] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_2_R0_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_2_R0_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_2_R0_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_2_R0_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_2_R0_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_2_R0_LastMux_Middle_Line_g3,
		},
		[3] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_3_R0_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_3_R0_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_3_R0_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_3_R0_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_3_R0_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_3_R0_LastMux_Middle_Line_g3,
		},
		[4] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_4_R0_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_4_R0_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_4_R0_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_4_R0_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_4_R0_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_4_R0_LastMux_Middle_Line_g3,
		},
		[5] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_5_R0_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_5_R0_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_5_R0_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_5_R0_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_5_R0_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_5_R0_LastMux_Middle_Line_g3,
		},
	},
	.R0_CR1_MUX10_2 =
	{
		[0] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_0_R0_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_0_R0_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_0_R0_LastMux_Bottom_Line_g3,
		},
		[1] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_1_R0_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_1_R0_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_1_R0_LastMux_Bottom_Line_g3,
		},
		[2] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_2_R0_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_2_R0_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_2_R0_LastMux_Bottom_Line_g3,
		},
		[3] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_3_R0_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_3_R0_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_3_R0_LastMux_Bottom_Line_g3,
		},
		[4] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_4_R0_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_4_R0_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_4_R0_LastMux_Bottom_Line_g3,
		},
		[5] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_5_R0_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_5_R0_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_5_R0_LastMux_Bottom_Line_g3,
		},
	},
	.R1_CR1_MUX1_1 =
	{
		[0] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_0_R1_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_0_R1_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_0_R1_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_0_R1_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_0_R1_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_0_R1_1stMux_Middle_Line_g3,
		},
		[1] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_1_R1_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_1_R1_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_1_R1_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_1_R1_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_1_R1_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_1_R1_1stMux_Middle_Line_g3,
		},
		[2] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_2_R1_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_2_R1_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_2_R1_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_2_R1_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_2_R1_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_2_R1_1stMux_Middle_Line_g3,
		},
		[3] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_3_R1_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_3_R1_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_3_R1_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_3_R1_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_3_R1_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_3_R1_1stMux_Middle_Line_g3,
		},
		[4] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_4_R1_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_4_R1_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_4_R1_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_4_R1_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_4_R1_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_4_R1_1stMux_Middle_Line_g3,
		},
		[5] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_5_R1_1stMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_5_R1_1stMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_5_R1_1stMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_5_R1_1stMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_5_R1_1stMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_5_R1_1stMux_Middle_Line_g3,
		},
	},
	.R1_CR1_MUX1_2 =
	{
		[0] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_0_R1_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_0_R1_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_0_R1_1stMux_Bottom_Line_g3,
		},
		[1] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_1_R1_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_1_R1_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_1_R1_1stMux_Bottom_Line_g3,
		},
		[2] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_2_R1_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_2_R1_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_2_R1_1stMux_Bottom_Line_g3,
		},
		[3] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_3_R1_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_3_R1_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_3_R1_1stMux_Bottom_Line_g3,
		},
		[4] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_4_R1_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_4_R1_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_4_R1_1stMux_Bottom_Line_g3,
		},
		[5] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_5_R1_1stMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_5_R1_1stMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_5_R1_1stMux_Bottom_Line_g3,
		},
	},
	.R1_CR1_MUX2 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R1_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R1_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R1_2ndMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R1_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R1_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R1_2ndMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R1_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R1_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R1_2ndMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R1_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R1_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R1_2ndMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R1_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R1_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R1_2ndMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R1_2ndMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R1_2ndMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R1_2ndMux_g3,
		},
	},
	.R1_CR1_MUX3 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R1_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R1_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R1_3rdMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R1_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R1_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R1_3rdMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R1_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R1_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R1_3rdMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R1_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R1_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R1_3rdMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R1_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R1_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R1_3rdMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R1_3rdMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R1_3rdMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R1_3rdMux_g3,
		},
	},
	.R1_CR1_MUX4 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R1_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R1_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R1_4thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R1_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R1_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R1_4thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R1_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R1_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R1_4thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R1_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R1_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R1_4thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R1_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R1_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R1_4thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R1_4thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R1_4thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R1_4thMux_g3,
		},
	},
	.R1_CR1_MUX5 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R1_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R1_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R1_5thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R1_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R1_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R1_5thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R1_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R1_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R1_5thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R1_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R1_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R1_5thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R1_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R1_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R1_5thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R1_5thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R1_5thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R1_5thMux_g3,
		},
	},
	.R1_CR1_MUX6 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R1_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R1_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R1_6thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R1_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R1_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R1_6thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R1_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R1_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R1_6thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R1_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R1_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R1_6thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R1_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R1_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R1_6thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R1_6thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R1_6thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R1_6thMux_g3,
		},
	},
	.R1_CR1_MUX7 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R1_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R1_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R1_7thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R1_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R1_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R1_7thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R1_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R1_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R1_7thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R1_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R1_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R1_7thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R1_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R1_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R1_7thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R1_7thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R1_7thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R1_7thMux_g3,
		},
	},
	.R1_CR1_MUX8 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R1_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R1_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R1_8thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R1_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R1_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R1_8thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R1_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R1_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R1_8thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R1_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R1_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R1_8thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R1_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R1_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R1_8thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R1_8thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R1_8thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R1_8thMux_g3,
		},
	},
	.R1_CR1_MUX9 =
	{
		[0] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_0_R1_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_0_R1_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_0_R1_9thMux_g3,
		},
		[1] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_1_R1_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_1_R1_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_1_R1_9thMux_g3,
		},
		[2] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_2_R1_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_2_R1_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_2_R1_9thMux_g3,
		},
		[3] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_3_R1_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_3_R1_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_3_R1_9thMux_g3,
		},
		[4] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_4_R1_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_4_R1_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_4_R1_9thMux_g3,
		},
		[5] = {
			.tBit.cr1_rg1 = PARAMSET_HOPPFRQ_ROIC_5_R1_9thMux_g1,
			.tBit.cr1_rg2 = PARAMSET_HOPPFRQ_ROIC_5_R1_9thMux_g2,
			.tBit.cr1_rg3 = PARAMSET_HOPPFRQ_ROIC_5_R1_9thMux_g3,
		},
	},
	.R1_CR1_MUX10_1 =
	{
		[0] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_0_R1_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_0_R1_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_0_R1_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_0_R1_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_0_R1_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_0_R1_LastMux_Middle_Line_g3,
		},
		[1] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_1_R1_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_1_R1_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_1_R1_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_1_R1_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_1_R1_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_1_R1_LastMux_Middle_Line_g3,
		},
		[2] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_2_R1_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_2_R1_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_2_R1_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_2_R1_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_2_R1_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_2_R1_LastMux_Middle_Line_g3,
		},
		[3] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_3_R1_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_3_R1_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_3_R1_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_3_R1_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_3_R1_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_3_R1_LastMux_Middle_Line_g3,
		},
		[4] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_4_R1_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_4_R1_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_4_R1_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_4_R1_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_4_R1_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_4_R1_LastMux_Middle_Line_g3,
		},
		[5] = {
			.tBit.cr1_r1g1 = PARAMSET_HOPPFRQ_ROIC_5_R1_LastMux_Top_Line_g1,
			.tBit.cr1_r1g2 = PARAMSET_HOPPFRQ_ROIC_5_R1_LastMux_Top_Line_g2,
			.tBit.cr1_r1g3 = PARAMSET_HOPPFRQ_ROIC_5_R1_LastMux_Top_Line_g3,
			.tBit.cr1_r2g1 = PARAMSET_HOPPFRQ_ROIC_5_R1_LastMux_Middle_Line_g1,
			.tBit.cr1_r2g2 = PARAMSET_HOPPFRQ_ROIC_5_R1_LastMux_Middle_Line_g2,
			.tBit.cr1_r2g3 = PARAMSET_HOPPFRQ_ROIC_5_R1_LastMux_Middle_Line_g3,
		},
	},
	.R1_CR1_MUX10_2 =
	{
		[0] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_0_R1_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_0_R1_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_0_R1_LastMux_Bottom_Line_g3,
		},
		[1] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_1_R1_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_1_R1_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_1_R1_LastMux_Bottom_Line_g3,
		},
		[2] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_2_R1_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_2_R1_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_2_R1_LastMux_Bottom_Line_g3,
		},
		[3] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_3_R1_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_3_R1_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_3_R1_LastMux_Bottom_Line_g3,
		},
		[4] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_4_R1_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_4_R1_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_4_R1_LastMux_Bottom_Line_g3,
		},
		[5] = {
			.tBit.cr1_r3g1 = PARAMSET_HOPPFRQ_ROIC_5_R1_LastMux_Bottom_Line_g1,
			.tBit.cr1_r3g2 = PARAMSET_HOPPFRQ_ROIC_5_R1_LastMux_Bottom_Line_g2,
			.tBit.cr1_r3g3 = PARAMSET_HOPPFRQ_ROIC_5_R1_LastMux_Bottom_Line_g3,
		},
	},
};
#endif /* USED_NOISE_HOPPING_FREQ */

const tModuleSRICCommonConf_t * s_pktmoduleSRICCommonConf = NULL;

static void SW92512_Reg_CRTuneSetting(eCRTuneType_t eCRTuneType)
{
	if(eCRTuneType == CRTUNE_TYPE_INIT || eCRTuneType == CRTUNE_TYPE_MAIN_FRQ)
	{
	    MSPI_RegisterMultiWrite((uint32_t)(0x0214), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX1_2[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0218), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX1_2[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x021C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX1_2[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0220), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX3_4[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0224), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX3_4[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0228), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX3_4[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x022C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX5_6[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0230), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX5_6[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0234), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX5_6[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0238), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX7_8[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x023C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX7_8[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0240), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX7_8[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0244), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX9_10[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0248), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX9_10[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x024C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX9_10[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0250), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0314), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX1_2[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0318), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX1_2[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x031C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX1_2[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0320), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX3_4[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0324), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX3_4[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0328), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX3_4[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x032C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX5_6[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0330), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX5_6[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0334), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX5_6[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0338), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX7_8[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x033C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX7_8[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0340), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX7_8[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0344), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX9_10[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0348), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX9_10[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x034C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX9_10[0].ulBulk);  // R/W
	    MSPI_RegisterMultiWrite((uint32_t)(0x0350), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);  // R/W
	}
#if USED_NOISE_HOPPING_FREQ
	else if(eCRTuneType == CRTUNE_TYPE_HOPP1_FRQ)
	{
		MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX1_1[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX1_2[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x0108), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX2[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x010C), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX3[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x0110), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX4[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x0114), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX5[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x0118), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX6[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x011C), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX7[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x0120), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX8[0].ulBulk);
	#if (FINGER_MUX_NUM > 9)
		MSPI_RegisterMultiWrite((uint32_t)(0x0124), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX9[0].ulBulk);
	#endif
		MSPI_RegisterMultiWrite((uint32_t)(0x0128), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX10_1[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x012C), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R0_CR1_MUX10_2[0].ulBulk);

		MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX1_1[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX1_2[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x0188), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX2[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x018C), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX3[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x0190), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX4[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x0194), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX5[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x0198), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX6[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x019C), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX7[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x01A0), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX8[0].ulBulk);
	#if (FINGER_MUX_NUM > 9)
		MSPI_RegisterMultiWrite((uint32_t)(0x01A4), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX9[0].ulBulk);
	#endif
		MSPI_RegisterMultiWrite((uint32_t)(0x01A8), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX10_1[0].ulBulk);
		MSPI_RegisterMultiWrite((uint32_t)(0x01AC), (uint32_t *)&tSW92512_HoppFrqCRReg_CFG.R1_CR1_MUX10_2[0].ulBulk);
	}
#endif /* USED_NOISE_HOPPING_FREQ */

//	if(eCRTuneType == CRTUNE_TYPE_INIT)
//	{
//		MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x0134), s_pktmoduleSRICCommonConf->R0_CFGR_TUNE_GROUP.ulBulk);
//		MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x01B4), s_pktmoduleSRICCommonConf->R1_CFGR_TUNE_GROUP.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x01C4), s_pktmoduleSRICCommonConf->CFGR_TUNE_LOWER.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x01C8), s_pktmoduleSRICCommonConf->CFGR_TUNE_UPPER.ulBulk);
//	}
}

#if USED_NOISE_HOPPING_FREQ
tSW92512_AFEReg_CFG_t tSW92512_HoppFreq_AFEReg_CFG =
{
	.CFGR_PWM_PRD =
	{
		.tBit.pwm_prd1 = PARAMSET_ROIC_HOPPFRQ_CFGR_PWM_PRD_pwm_prd1,
		.tBit.pwm_prd2 = PARAMSET_ROIC_HOPPFRQ_CFGR_PWM_PRD_pwm_prd2,
	},
	.CFGR_SMPL_CTL =
	{
		.tBit.smop_prd_1 = PARAMSET_ROIC_HOPPFRQ_CFGR_SMPL_CTL_smop_prd_1,
		.tBit.smop_prd_2 = PARAMSET_ROIC_HOPPFRQ_CFGR_SMPL_CTL_smop_prd_2,
		.tBit.crrpt_num = PARAMSET_ROIC_HOPPFRQ_CFGR_SMPL_CTL_crrpt_num,
	},
//	.CFGR_RSTP_NUM1 =
//	{
//		.tBit.rstp_num1 = PARAMSET_ROIC_HOPPFRQ_CFGR_RSTP_NUM1_rstp_num1,
//		.tBit.rstp_num2 = PARAMSET_ROIC_HOPPFRQ_CFGR_RSTP_NUM1_rstp_num2,
//	},
	.CFGR_PHT_NUM1 =
	{
		.tBit.pht_num1 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHT_NUM1_pht_num1,
		.tBit.pht_num2 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHT_NUM1_pht_num2,
	},
	.CFGR_PHTCR_NUM1 =
	{
		.tBit.phtcr_num1_1 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_NUM1_phtcr_num1_1,
		.tBit.phtcr_num1_2 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_NUM1_phtcr_num1_2,
	},
	.CFGR_PHTCR_NUM2 =
	{
		.tBit.phtcr_num2_1 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_NUM2_phtcr_num2_1,
		.tBit.phtcr_num2_2 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_NUM2_phtcr_num2_2,
	},
	.CFGR_VCR_NUM1 =
	{
		.tBit.vcr_num1_1 = PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_NUM1_vcr_num1_1,
		.tBit.vcr_num1_2 = PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_NUM1_vcr_num1_2,
	},
//	.CFGR_VCR_EN_NUM1 =
//	{
//		.tBit.vcr_en_num1_1 = PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_EN_NUM1_vcr_en_num1_1,
//		.tBit.vcr_en_num1_2 = PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_EN_NUM1_vcr_en_num1_2,
//	},
//	.CFGR_VCR_EN_NUM2 =
//	{
//		.tBit.vcr_en_num2_1 = PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_EN_NUM2_vcr_en_num2_1,
//		.tBit.vcr_en_num2_2 = PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_EN_NUM2_vcr_en_num2_2,
//	},
//	.CFGR_PHTH0_NUM1 =
//	{
//		.tBit.phth0_num1_1 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH0_NUM1_phth0_num1_1,
//		.tBit.phth0_num1_2 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH0_NUM1_phth0_num1_2,
//	},
//	.CFGR_PHTH1_NUM1 =
//	{
//		.tBit.phth1_num1_1 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH1_NUM1_phth1_num1_1,
//		.tBit.phth1_num1_2 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH1_NUM1_phth1_num1_2,
//	},
	.CFGR_PHTH_NUM2 =
	{
		.tBit.phth0_num2 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH_NUM2_phth0_num2,
		.tBit.phth1_num2 = PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH_NUM2_phth1_num2,
	},
};
#endif /* USED_NOISE_HOPPING_FREQ */

//static void SW92512_Reg_AFESetting(eSENSING_MODE_t eSensingMode)
//{
//#if USED_NOISE_HOPPING_FREQ
//	if (IS_ACTIVE_MODE_FRQ_MAIN(eSensingMode))
//	{
//		MSPI_RegisterWrite((uint32_t)(0x0044), s_pktmoduleSRICCommonConf->CFGR_PWM_PRD.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->CFGR_SMPL_CTL.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x0050), s_pktmoduleSRICCommonConf->CFGR_PHTCR_NUM1.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x0054), s_pktmoduleSRICCommonConf->CFGR_PHTCR_NUM2.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x0058), s_pktmoduleSRICCommonConf->CFGR_VCR_NUM1.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x006C), s_pktmoduleSRICCommonConf->CFGR_PHTH_NUM2.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x0074), s_pktmoduleSRICCommonConf->CFGR_PHT_NUM1.ulBulk);
//	}
//	else if (IS_ACTIVE_MODE_FRQ_HOP1(eSensingMode))
//	{
//		MSPI_RegisterWrite((uint32_t)(0x0044), tSW92512_HoppFreq_AFEReg_CFG.CFGR_PWM_PRD.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x0048), tSW92512_HoppFreq_AFEReg_CFG.CFGR_SMPL_CTL.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x0050), tSW92512_HoppFreq_AFEReg_CFG.CFGR_PHTCR_NUM1.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x0054), tSW92512_HoppFreq_AFEReg_CFG.CFGR_PHTCR_NUM2.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x0058), tSW92512_HoppFreq_AFEReg_CFG.CFGR_VCR_NUM1.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x006C), tSW92512_HoppFreq_AFEReg_CFG.CFGR_PHTH_NUM2.ulBulk);
//		MSPI_RegisterWrite((uint32_t)(0x0074), tSW92512_HoppFreq_AFEReg_CFG.CFGR_PHT_NUM1.ulBulk);
//	}
//#else /* USED_NOISE_HOPPING_FREQ */
//	MSPI_RegisterWrite((uint32_t)(0x0044), s_pktmoduleSRICCommonConf->CFGR_PWM_PRD.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->CFGR_SMPL_CTL.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x0050), s_pktmoduleSRICCommonConf->CFGR_PHTCR_NUM1.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x0054), s_pktmoduleSRICCommonConf->CFGR_PHTCR_NUM2.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x0058), s_pktmoduleSRICCommonConf->CFGR_VCR_NUM1.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x006C), s_pktmoduleSRICCommonConf->CFGR_PHTH_NUM2.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x0074), s_pktmoduleSRICCommonConf->CFGR_PHT_NUM1.ulBulk);
//#endif /* USED_NOISE_HOPPING_FREQ */
//}

static void SW92512_Reg_LHBSetting(uint32_t ulType)
{
    MSPI_RegisterWrite((uint32_t)(0x00A8), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG00[ulType].ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00AC), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG01[ulType].ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00B0), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG02[ulType].ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00B4), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG03[ulType].ulBulk);  // R/W
}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
static void SW92512_Reg_LHBSetting_ByChangeMode(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
	uint32_t ulIdx;
	tLHB_CFG_t * pLHB_CFG;
	switch(eMode)
	{
		case ROIC_REG_SET_CHAGNE_WGPPen_Local_Setting:
		{
			pLHB_CFG = &tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.LHB_CFG[0];
			break;
		}
		case ROIC_REG_SET_CHAGNE_MSPen_Local_Setting:
		{
			pLHB_CFG = &tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.LHB_CFG[0];
			break;
		}
	}
	for(ulIdx = 0; ulIdx < SW92512_MAX_LHB_NUM; ulIdx++)
	{
		MSPI_RegisterWrite((uint32_t)(0x009C + (0x4 * ulIdx)), pLHB_CFG[ulIdx].ulBulk);
	}
}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */

void SW92512_Initialize(void)
{
	s_pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
}

void SW92512_Reset(eSENSING_MODE_t eSensingMode)
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
tPRODUCT_ID_t tTestProductROICBuf[MSPI_NUM];
bool_t SW92512_RegisterInit(eSENSING_MODE_t eSensingMode)
{
	bool_t bReg = YES;
//    uint32_t ulBuf[6];

//    MSPI_RegisterWrite((uint32_t)(0x0000), s_pktmoduleSRICCommonConf->PRODUCT_ID[0].ulBulk);  // R
    MSPI_RegisterWrite((uint32_t)(0x0004), s_pktmoduleSRICCommonConf->SPIS_CFG.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0008), s_pktmoduleSRICCommonConf->SPIS_ERROR_CLR.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x000C), s_pktmoduleSRICCommonConf->SPIS_ERROR_ST[0].ulBulk);  // R
    MSPI_RegisterWrite((uint32_t)(0x0010), s_pktmoduleSRICCommonConf->SPIS_PAD_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0014), s_pktmoduleSRICCommonConf->SYS_CFG.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0018), s_pktmoduleSRICCommonConf->TC_START.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x001C), s_pktmoduleSRICCommonConf->CH_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0020), s_pktmoduleSRICCommonConf->MUX_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0024), s_pktmoduleSRICCommonConf->MUX_DLY_0.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0028), s_pktmoduleSRICCommonConf->MUX_DLY_1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x002C), s_pktmoduleSRICCommonConf->MUX_DLY_2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0030), s_pktmoduleSRICCommonConf->SDIC_CFG.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->PWM_FIG_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0038), s_pktmoduleSRICCommonConf->PWM_POS_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x003C), s_pktmoduleSRICCommonConf->PWM_DAT_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0040), s_pktmoduleSRICCommonConf->PWM_ND_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0044), s_pktmoduleSRICCommonConf->PWM_PRD.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->SMPL_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x004C), s_pktmoduleSRICCommonConf->RSTP_RISE_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0050), s_pktmoduleSRICCommonConf->RSTP_FALL_NUM1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0054), s_pktmoduleSRICCommonConf->RSTP_FALL_NUM2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0058), s_pktmoduleSRICCommonConf->PHTCR_RISE_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x005C), s_pktmoduleSRICCommonConf->PHTCR_FALL_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0060), s_pktmoduleSRICCommonConf->VCR_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0064), s_pktmoduleSRICCommonConf->RSTI_RISE_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0068), s_pktmoduleSRICCommonConf->RSTI_FALL_NUM1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x006C), s_pktmoduleSRICCommonConf->RSTI_FALL_NUM2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0070), s_pktmoduleSRICCommonConf->PHTH0_RISE_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0074), s_pktmoduleSRICCommonConf->PHTH0_FALL_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0078), s_pktmoduleSRICCommonConf->PHTH1_RISE_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x007C), s_pktmoduleSRICCommonConf->PHTH1_FALL_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0080), s_pktmoduleSRICCommonConf->PHT_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0084), s_pktmoduleSRICCommonConf->PHT_RISE_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0088), s_pktmoduleSRICCommonConf->PHT_FALL_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x008C), s_pktmoduleSRICCommonConf->ADC_CTL1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0090), s_pktmoduleSRICCommonConf->ADC_CTL2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0094), s_pktmoduleSRICCommonConf->ADC_CTL3.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0098), s_pktmoduleSRICCommonConf->TG_STUCK.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x009C), s_pktmoduleSRICCommonConf->FIG_MUX_CFG_00.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00A0), s_pktmoduleSRICCommonConf->FIG_MUX_CFG_01.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00A4), s_pktmoduleSRICCommonConf->RCOM_LHB_CFG.ulBulk);  // R/W

//    MSPI_RegisterWrite((uint32_t)(0x00A8), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG00.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x00AC), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG01.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x00B0), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG02.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x00B4), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG03.ulBulk);  // R/W
#if USED_PEN_MODE_OPERATION
	if(IS_FINGER_PEN_MODE(eSensingMode))
	{
		SW92512_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);
	}
	else
#endif /* USED_PEN_MODE_OPERATION */
	{
		SW92512_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
	}

    MSPI_RegisterWrite((uint32_t)(0x00B8), s_pktmoduleSRICCommonConf->LHB_MUX_NUM.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00BC), s_pktmoduleSRICCommonConf->PEN_POS1_LHB_CFG.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00C0), s_pktmoduleSRICCommonConf->PEN_DAT1_LHB_CFG.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00C4), s_pktmoduleSRICCommonConf->MUX_FCTL_NUM1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00C8), s_pktmoduleSRICCommonConf->MUX_FCTL_NUM2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00CC), s_pktmoduleSRICCommonConf->PING_MUX_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00D0), s_pktmoduleSRICCommonConf->PRE_DRV_CTL.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x00D4), s_pktmoduleSRICCommonConf->RESERVED_1.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x00D8), s_pktmoduleSRICCommonConf->RESERVED_2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00DC), s_pktmoduleSRICCommonConf->AFE_SENSE_CTL1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00E0), s_pktmoduleSRICCommonConf->PHD_SENSE_CTL2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00E4), s_pktmoduleSRICCommonConf->PDB_PHD_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00E8), s_pktmoduleSRICCommonConf->SYS_DUMMY0.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00EC), s_pktmoduleSRICCommonConf->SYS_DUMMY1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00F0), s_pktmoduleSRICCommonConf->TEST_MUX_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00F4), s_pktmoduleSRICCommonConf->PHD_CTL2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x00F8), s_pktmoduleSRICCommonConf->PHD_CTL3.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x00FC), s_pktmoduleSRICCommonConf->PHD_ST1[0].ulBulk);  // R
//    MSPI_RegisterWrite((uint32_t)(0x0100), s_pktmoduleSRICCommonConf->PHD_ST3 [0].ulBulk);  // R
//    MSPI_RegisterWrite((uint32_t)(0x0104), s_pktmoduleSRICCommonConf->MON_R0_ADCDO[0].ulBulk);  // R
//    MSPI_RegisterWrite((uint32_t)(0x0108), s_pktmoduleSRICCommonConf->MON_R1_ADCDO[0].ulBulk);  // R
    MSPI_RegisterWrite((uint32_t)(0x0200), s_pktmoduleSRICCommonConf->R0_SYS_CFG.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0204), s_pktmoduleSRICCommonConf->R0_CH_EN.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0208), s_pktmoduleSRICCommonConf->R0_MUX_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x020C), s_pktmoduleSRICCommonConf->R0_MUX_S_STUCK_VAL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0210), s_pktmoduleSRICCommonConf->R0_MUX_F_STUCK_VAL.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0214), s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX1_2[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0218), s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX1_2[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x021C), s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX1_2[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0220), s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX3_4[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0224), s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX3_4[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0228), s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX3_4[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x022C), s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX5_6[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0230), s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX5_6[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0234), s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX5_6[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0238), s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX7_8[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x023C), s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX7_8[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0240), s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX7_8[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0244), s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX9_10[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0248), s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX9_10[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x024C), s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX9_10[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0250), s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0254), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX1_2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0258), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX3_4.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x025C), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX5_6.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0260), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX7_8.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0264), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX9_10.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0268), s_pktmoduleSRICCommonConf->R0_TUNE_GROUP_COL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x026C), s_pktmoduleSRICCommonConf->R0_PHD_CTL1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0270), s_pktmoduleSRICCommonConf->R0_PHD_CTL2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0274), s_pktmoduleSRICCommonConf->R0_PHD_CTL3.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0278), s_pktmoduleSRICCommonConf->R0_PHD_CTL4.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x027C), s_pktmoduleSRICCommonConf->R0_PHD_ST1[0].ulBulk);  // R
//    MSPI_RegisterWrite((uint32_t)(0x0280), s_pktmoduleSRICCommonConf->R0_PHD_ST2[0].ulBulk);  // R
    MSPI_RegisterWrite((uint32_t)(0x0284), s_pktmoduleSRICCommonConf->R0_PHD_SENSE_CTL1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0288), s_pktmoduleSRICCommonConf->R0_ADC_SENSE_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x028C), s_pktmoduleSRICCommonConf->R0_PDB_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0290), s_pktmoduleSRICCommonConf->R0_PDB_PHD_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0294), s_pktmoduleSRICCommonConf->R0_RESERVE.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0298), s_pktmoduleSRICCommonConf->R0_AFE_SENSE_CTL1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x029C), s_pktmoduleSRICCommonConf->R0_AFE_SENSE_CTL2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x02A0), s_pktmoduleSRICCommonConf->R0_AFE_SENSE_CTL3.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x02A4), s_pktmoduleSRICCommonConf->R0_VCOMR_OPT.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x02A8), s_pktmoduleSRICCommonConf->R0_BUF_OPT.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x02AC), s_pktmoduleSRICCommonConf->R0_TG_STUCK.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x02B0), s_pktmoduleSRICCommonConf->R0_ADC_IN_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x02B4), s_pktmoduleSRICCommonConf->R0_UPLINK_MUX.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x02B8), s_pktmoduleSRICCommonConf->R0_LHB_MUX_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x02BC), s_pktmoduleSRICCommonConf->R0_TEST_MUX_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0300), s_pktmoduleSRICCommonConf->R1_SYS_CFG.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0304), s_pktmoduleSRICCommonConf->R1_CH_EN.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0308), s_pktmoduleSRICCommonConf->R1_MUX_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x030C), s_pktmoduleSRICCommonConf->R1_MUX_S_STUCK_VAL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0310), s_pktmoduleSRICCommonConf->R1_MUX_F_STUCK_VAL.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0314), s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX1_2[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0318), s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX1_2[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x031C), s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX1_2[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0320), s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX3_4[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0324), s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX3_4[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0328), s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX3_4[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x032C), s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX5_6[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0330), s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX5_6[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0334), s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX5_6[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0338), s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX7_8[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x033C), s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX7_8[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0340), s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX7_8[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0344), s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX9_10[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0348), s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX9_10[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x034C), s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX9_10[0].ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0350), s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0354), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX1_2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0358), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX3_4.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x035C), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX5_6.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0360), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX7_8.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0364), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX9_10.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0368), s_pktmoduleSRICCommonConf->R1_TUNE_GROUP_COL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x036C), s_pktmoduleSRICCommonConf->R1_PHD_CTL1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0370), s_pktmoduleSRICCommonConf->R1_PHD_CTL2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0374), s_pktmoduleSRICCommonConf->R1_PHD_CTL3.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0378), s_pktmoduleSRICCommonConf->R1_PHD_CTL4.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x037C), s_pktmoduleSRICCommonConf->R1_PHD_ST1[0].ulBulk);  // R
//    MSPI_RegisterWrite((uint32_t)(0x0380), s_pktmoduleSRICCommonConf->R1_PHD_ST2[0].ulBulk);  // R
    MSPI_RegisterWrite((uint32_t)(0x0384), s_pktmoduleSRICCommonConf->R1_PHD_SENSE_CTL1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0388), s_pktmoduleSRICCommonConf->R1_ADC_SENSE_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x038C), s_pktmoduleSRICCommonConf->R1_PDB_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0390), s_pktmoduleSRICCommonConf->R1_PDB_PHD_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0394), s_pktmoduleSRICCommonConf->R1_RESERVE.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0398), s_pktmoduleSRICCommonConf->R1_AFE_SENSE_CTL1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x039C), s_pktmoduleSRICCommonConf->R1_AFE_SENSE_CTL2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x03A0), s_pktmoduleSRICCommonConf->R1_AFE_SENSE_CTL3.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x03A4), s_pktmoduleSRICCommonConf->R1_VCOMR_OPT.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x03A8), s_pktmoduleSRICCommonConf->R1_BUF_OPT.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x03AC), s_pktmoduleSRICCommonConf->R1_TG_STUCK.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x03B0), s_pktmoduleSRICCommonConf->R1_ADC_IN_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x03B4), s_pktmoduleSRICCommonConf->R1_UPLINK_MUX.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x03B8), s_pktmoduleSRICCommonConf->R1_LHB_MUX_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x03BC), s_pktmoduleSRICCommonConf->R1_TEST_MUX_CTL.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x07F0), s_pktmoduleSRICCommonConf->APEN_CFCLK_ON.ulBulk);  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x07F4), s_pktmoduleSRICCommonConf->MON_CAL_DELAY[0].ulBulk);  // R
//    MSPI_RegisterWrite((uint32_t)(0x07F8), s_pktmoduleSRICCommonConf->MON_EDGE_SIGN_R0[0].ulBulk);  // R
//    MSPI_RegisterWrite((uint32_t)(0x07FC), s_pktmoduleSRICCommonConf->MON_EDGE_SIGN_R1[0].ulBulk);  // R
    SW92512_Reg_CRTuneSetting(CRTUNE_TYPE_INIT);

	return bReg;
}

void SW92512_Run(uint8_t Enable)
{
	tTC_START_t tCFGR_TC_START;
	tSYS_CFG_t tCFGR_SYS_CFG;
	tCFGR_TC_START.ulBulk = 0;
	tCFGR_TC_START.tBit.tc_start = Enable;
	MSPI_RegisterWrite((uint32_t)(0x018), tCFGR_TC_START.ulBulk);

	tCFGR_SYS_CFG.ulBulk = s_pktmoduleSRICCommonConf->SYS_CFG.ulBulk;
	tCFGR_SYS_CFG.tBit.tg_reset = 1;
	MSPI_RegisterWrite((uint32_t)(0x0014), tCFGR_SYS_CFG.ulBulk);
	tCFGR_SYS_CFG.tBit.tg_reset = 0;
	MSPI_RegisterWrite((uint32_t)(0x0014), tCFGR_SYS_CFG.ulBulk);
}

extern __IO uint16_t sensingRowStart_Tilt;
extern int8_t sensingRowStart_Tilt_Offset;
void SW92512_SetLocalIndex(uint32_t ulIdx)
{
#if IS_WGPUHDPEN_PROTOCOL_OPERATION
 	uint32_t ulLocalIndex;
 	uint32_t ulMSPIIndex;
 	tPEN_POS1_LHB_CFG_t tCHFG_PP_LHB_CFG;
 	tPEN_DAT1_LHB_CFG_t tCHFG_PD_LHB_CFG;

 	ulLocalIndex = (uint32_t)((ulIdx)&(0xFFFF));
	#ifdef TILT_ON
		ulMSPIIndex = (uint32_t)((ulIdx)>>16);
	#endif

	tHalIntrHandle.ulLocalSensingDoneRowIdx = ulLocalIndex;
	tCHFG_PD_LHB_CFG.ulBulk = s_pktmoduleSRICCommonConf->PEN_DAT1_LHB_CFG.ulBulk;
	tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg0 = ulLocalIndex;
	tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg1 = ulLocalIndex;
	tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg2 = ulLocalIndex;
	tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg3 = ulLocalIndex;
	MSPI_RegisterWrite((uint32_t)(0x00C0), tCHFG_PD_LHB_CFG.ulBulk);

	#ifdef TILT_ON
	{
		{
		#if USED_WGP_PEN_UHD_16LHB_OPERATION
			if(ulMSPIIndex == 0 || ulMSPIIndex == 7)
		#else /* USED_WGP_PEN_UHD_16LHB_OPERATION */
			if(ulMSPIIndex == 0)
		#endif /* USED_WGP_PEN_UHD_16LHB_OPERATION */
			{
				//tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt;// = MAX(0,MIN(ROW_MAX-PEN_COORD_ROW_MAX,(int)(ulLocalIndex + sensingRowStart_Tilt_Offset)));
				tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = MAX(0,MIN(ROW_MAX-PEN_COORD_ROW_MAX,(int)(ulLocalIndex + sensingRowStart_Tilt_Offset)));
				tCHFG_PP_LHB_CFG.ulBulk = s_pktmoduleSRICCommonConf->PEN_POS1_LHB_CFG.ulBulk;
				tCHFG_PP_LHB_CFG.tBit.pen_pos1_mux_cfg0 = sensingRowStart_Tilt;
				tCHFG_PP_LHB_CFG.tBit.pen_pos1_mux_cfg1 = sensingRowStart_Tilt;
				MSPI_RegisterWrite((uint32_t)(0x00BC), tCHFG_PP_LHB_CFG.ulBulk);
			}
		}
	}
	#endif /* TILT_ON */
#else
	{
	#ifdef TILT_ON
		bool_t bIsTiltMSPIIdx = NO;
		uint32_t ulMSPIIndex;
	#endif
		uint32_t ulLocalIndex;

		tPEN_POS1_LHB_CFG_t tCHFG_PP_LHB_CFG;
		tPEN_DAT1_LHB_CFG_t tCHFG_PD_LHB_CFG;

		ulLocalIndex = (uint32_t)((ulIdx)&(0xFFFF));
	#ifdef TILT_ON
		ulMSPIIndex = (uint32_t)((ulIdx)>>16);
	#endif

		tHalIntrHandle.ulLocalSensingDoneRowIdx = ulLocalIndex;

	#ifdef TILT_ON
		#if IS_MULTI_PROTOCOL_OPERATION
		{
			if(hal_Info_GetControlActivePenSettingType() == ACTIVEPEN_TYPE_LOCAL_WGP &&
				(ulMSPIIndex == 1 || ulMSPIIndex == 9))
			{
				tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt = MAX(0,MIN(ROW_MAX-PEN_COORD_ROW_MAX,(int)(ulLocalIndex + sensingRowStart_Tilt_Offset)));
				ulLocalIndex = sensingRowStart_Tilt;
				bIsTiltMSPIIdx = YES;
			}
			else if(hal_Info_GetControlActivePenSettingType() == ACTIVEPEN_TYPE_LOCAL_MS &&
				(ulMSPIIndex == 0 || ulMSPIIndex == 6))
			{
				sensingRowStart_Tilt = tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = MAX(0,MIN(ROW_MAX-PEN_COORD_ROW_MAX,(int)(ulLocalIndex + sensingRowStart_Tilt_Offset)));
			}
		}
		#else /* IS_MULTI_PROTOCOL_OPERATION */
		{
			#if IS_WGPPEN_PROTOCOL_OPERATION
				if(ulMSPIIndex == 1 || ulMSPIIndex == 9)
				{
					tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt = MAX(0,MIN(ROW_MAX-PEN_COORD_ROW_MAX,(int)(ulLocalIndex + sensingRowStart_Tilt_Offset)));
					ulLocalIndex = sensingRowStart_Tilt;
					bIsTiltMSPIIdx = YES;
				}
			#elif IS_MSPEN_PROTOCOL_OPERATION
				if(ulMSPIIndex == 0 || ulMSPIIndex == 6)
				{
					sensingRowStart_Tilt = tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = MAX(0,MIN(ROW_MAX-PEN_COORD_ROW_MAX,(int)(ulLocalIndex + sensingRowStart_Tilt_Offset)));
				}
			#endif /* IS_WGPPEN_PROTOCOL_OPERATION */
		}
		#endif /* IS_MULTI_PROTOCOL_OPERATION */
	#endif /* TILT_ON */

	#ifdef TILT_ON
		if(bIsTiltMSPIIdx == NO)
	#endif
		{
			tCHFG_PD_LHB_CFG.ulBulk = s_pktmoduleSRICCommonConf->PEN_DAT1_LHB_CFG.ulBulk;
			tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg0 = ulLocalIndex;
			tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg1 = ulLocalIndex;
			tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg2 = ulLocalIndex;
			tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg3 = ulLocalIndex;
			MSPI_RegisterWrite((uint32_t)(0x00C0), tCHFG_PD_LHB_CFG.ulBulk);
		}

		tCHFG_PP_LHB_CFG.ulBulk = s_pktmoduleSRICCommonConf->PEN_POS1_LHB_CFG.ulBulk;
		tCHFG_PP_LHB_CFG.tBit.pen_pos1_mux_cfg0 = ulLocalIndex;
		tCHFG_PP_LHB_CFG.tBit.pen_pos1_mux_cfg1 = ulLocalIndex;
		MSPI_RegisterWrite((uint32_t)(0x00BC), tCHFG_PP_LHB_CFG.ulBulk);
	}
#endif
}

void SW92512_SetIdleOperationMode(void)
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

void SW92512_SetActiveOperationMode(void)
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

//void SW92512_SetFingerPenFullModeChange(bool_t bIsFullMode)
//{
//	if(bIsFullMode)
//	{
//		SW92512_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
//	}
//	else
//	{
//		SW92512_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);
//	}
//}

#if (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL)
tLHB_MUX_NUM_t t_IDLE_LHB_MUX_NUM =
{
 .tBit.fig_lhb_mux_num = PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_NUM_fig_lhb_mux_num,
 .tBit.pen_pos1_lhb_mux_num = PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_NUM_pen_pos1_lhb_mux_num,
 .tBit.pen_dat1_lhb_mux_num = PARAMSET_IDLE_ROIC_CFGR_LHB_MUX_NUM_pen_dat1_lhb_mux_num,
};

tR0_CR_GTUNE_t t_IDLE_R0_CR_GTUNE[6] =
{
	[0] = {
		.tBit.r0_top_fig_gtune 	= PARAMSET_IDLE_ROIC_0_R0_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r0_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_0_R0_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r0_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_0_R0_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r0_pen_gtune 		= PARAMSET_IDLE_ROIC_0_R0_CR_GTUNE_Pen_Global_Tune,
		.tBit.r0_pdrv_gtune 	= PARAMSET_IDLE_ROIC_0_R0_CR_GTUNE_PRE_DRV_Global_Tune,
	},
	[1] = {
		.tBit.r0_top_fig_gtune 	= PARAMSET_IDLE_ROIC_1_R0_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r0_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_1_R0_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r0_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_1_R0_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r0_pen_gtune 		= PARAMSET_IDLE_ROIC_1_R0_CR_GTUNE_Pen_Global_Tune,
		.tBit.r0_pdrv_gtune 	= PARAMSET_IDLE_ROIC_1_R0_CR_GTUNE_PRE_DRV_Global_Tune,
	},
	[2] = {
		.tBit.r0_top_fig_gtune 	= PARAMSET_IDLE_ROIC_2_R0_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r0_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_2_R0_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r0_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_2_R0_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r0_pen_gtune 		= PARAMSET_IDLE_ROIC_2_R0_CR_GTUNE_Pen_Global_Tune,
		.tBit.r0_pdrv_gtune 	= PARAMSET_IDLE_ROIC_2_R0_CR_GTUNE_PRE_DRV_Global_Tune,
	},
	[3] = {
		.tBit.r0_top_fig_gtune 	= PARAMSET_IDLE_ROIC_3_R0_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r0_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_3_R0_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r0_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_3_R0_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r0_pen_gtune 		= PARAMSET_IDLE_ROIC_3_R0_CR_GTUNE_Pen_Global_Tune,
		.tBit.r0_pdrv_gtune 	= PARAMSET_IDLE_ROIC_3_R0_CR_GTUNE_PRE_DRV_Global_Tune,
	},
	[4] = {
		.tBit.r0_top_fig_gtune 	= PARAMSET_IDLE_ROIC_4_R0_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r0_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_4_R0_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r0_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_4_R0_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r0_pen_gtune 		= PARAMSET_IDLE_ROIC_4_R0_CR_GTUNE_Pen_Global_Tune,
		.tBit.r0_pdrv_gtune 	= PARAMSET_IDLE_ROIC_4_R0_CR_GTUNE_PRE_DRV_Global_Tune,
	},
	[5] = {
		.tBit.r0_top_fig_gtune 	= PARAMSET_IDLE_ROIC_5_R0_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r0_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_5_R0_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r0_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_5_R0_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r0_pen_gtune 		= PARAMSET_IDLE_ROIC_5_R0_CR_GTUNE_Pen_Global_Tune,
		.tBit.r0_pdrv_gtune 	= PARAMSET_IDLE_ROIC_5_R0_CR_GTUNE_PRE_DRV_Global_Tune,
	},
};

tR1_CR_GTUNE_t t_IDLE_R1_CR_GTUNE[6] =
{
	[0] = {
		.tBit.r1_top_fig_gtune 	= PARAMSET_IDLE_ROIC_0_R1_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r1_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_0_R1_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r1_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_0_R1_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r1_pen_gtune 		= PARAMSET_IDLE_ROIC_0_R1_CR_GTUNE_Pen_Global_Tune,
		.tBit.r1_pdrv_gtune 	= PARAMSET_IDLE_ROIC_0_R1_CR_GTUNE_PRE_DRV_Global_Tune,
	},
	[1] = {
		.tBit.r1_top_fig_gtune 	= PARAMSET_IDLE_ROIC_1_R1_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r1_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_1_R1_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r1_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_1_R1_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r1_pen_gtune 		= PARAMSET_IDLE_ROIC_1_R1_CR_GTUNE_Pen_Global_Tune,
		.tBit.r1_pdrv_gtune 	= PARAMSET_IDLE_ROIC_1_R1_CR_GTUNE_PRE_DRV_Global_Tune,
	},
	[2] = {
		.tBit.r1_top_fig_gtune 	= PARAMSET_IDLE_ROIC_2_R1_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r1_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_2_R1_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r1_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_2_R1_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r1_pen_gtune 		= PARAMSET_IDLE_ROIC_2_R1_CR_GTUNE_Pen_Global_Tune,
		.tBit.r1_pdrv_gtune 	= PARAMSET_IDLE_ROIC_2_R1_CR_GTUNE_PRE_DRV_Global_Tune,
	},
	[3] = {
		.tBit.r1_top_fig_gtune 	= PARAMSET_IDLE_ROIC_3_R1_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r1_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_3_R1_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r1_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_3_R1_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r1_pen_gtune 		= PARAMSET_IDLE_ROIC_3_R1_CR_GTUNE_Pen_Global_Tune,
		.tBit.r1_pdrv_gtune 	= PARAMSET_IDLE_ROIC_3_R1_CR_GTUNE_PRE_DRV_Global_Tune,
	},
	[4] = {
		.tBit.r1_top_fig_gtune 	= PARAMSET_IDLE_ROIC_4_R1_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r1_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_4_R1_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r1_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_4_R1_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r1_pen_gtune 		= PARAMSET_IDLE_ROIC_4_R1_CR_GTUNE_Pen_Global_Tune,
		.tBit.r1_pdrv_gtune 	= PARAMSET_IDLE_ROIC_4_R1_CR_GTUNE_PRE_DRV_Global_Tune,
	},
	[5] = {
		.tBit.r1_top_fig_gtune 	= PARAMSET_IDLE_ROIC_5_R1_CR_GTUNE_Finger_Top_Global_Tune,
		.tBit.r1_mid_fig_gtune 	= PARAMSET_IDLE_ROIC_5_R1_CR_GTUNE_Finger_Middle_Global_Tune,
		.tBit.r1_bot_fig_gtune 	= PARAMSET_IDLE_ROIC_5_R1_CR_GTUNE_Finger_Bottom_Global_Tune,
		.tBit.r1_pen_gtune 		= PARAMSET_IDLE_ROIC_5_R1_CR_GTUNE_Pen_Global_Tune,
		.tBit.r1_pdrv_gtune 	= PARAMSET_IDLE_ROIC_5_R1_CR_GTUNE_PRE_DRV_Global_Tune,
	},
};

tR0_CR_R1G_MUX1_2_t tIDLE_R0_CR_R1G_MUX1_2[MSPI_NUM] =
{
	 [0] = {
	  .tBit.r0_cr_mux1_r1g1 = PARAMSET_IDLE_ROIC_0_R0_1stMux_r1_g1,
	  .tBit.r0_cr_mux1_r1g2 = PARAMSET_IDLE_ROIC_0_R0_1stMux_r1_g2,
	  .tBit.r0_cr_mux1_r1g3 = PARAMSET_IDLE_ROIC_0_R0_1stMux_r1_g3,
	  .tBit.r0_cr_mux2_r1g1 = PARAMSET_IDLE_ROIC_0_R0_2ndMux_r1_g1,
	  .tBit.r0_cr_mux2_r1g2 = PARAMSET_IDLE_ROIC_0_R0_2ndMux_r1_g2,
	  .tBit.r0_cr_mux2_r1g3 = PARAMSET_IDLE_ROIC_0_R0_2ndMux_r1_g3,
	 },
	 [1] = {
	  .tBit.r0_cr_mux1_r1g1 = PARAMSET_IDLE_ROIC_1_R0_1stMux_r1_g1,
	  .tBit.r0_cr_mux1_r1g2 = PARAMSET_IDLE_ROIC_1_R0_1stMux_r1_g2,
	  .tBit.r0_cr_mux1_r1g3 = PARAMSET_IDLE_ROIC_1_R0_1stMux_r1_g3,
	  .tBit.r0_cr_mux2_r1g1 = PARAMSET_IDLE_ROIC_1_R0_2ndMux_r1_g1,
	  .tBit.r0_cr_mux2_r1g2 = PARAMSET_IDLE_ROIC_1_R0_2ndMux_r1_g2,
	  .tBit.r0_cr_mux2_r1g3 = PARAMSET_IDLE_ROIC_1_R0_2ndMux_r1_g3,
	 },
	 [2] = {
	  .tBit.r0_cr_mux1_r1g1 = PARAMSET_IDLE_ROIC_2_R0_1stMux_r1_g1,
	  .tBit.r0_cr_mux1_r1g2 = PARAMSET_IDLE_ROIC_2_R0_1stMux_r1_g2,
	  .tBit.r0_cr_mux1_r1g3 = PARAMSET_IDLE_ROIC_2_R0_1stMux_r1_g3,
	  .tBit.r0_cr_mux2_r1g1 = PARAMSET_IDLE_ROIC_2_R0_2ndMux_r1_g1,
	  .tBit.r0_cr_mux2_r1g2 = PARAMSET_IDLE_ROIC_2_R0_2ndMux_r1_g2,
	  .tBit.r0_cr_mux2_r1g3 = PARAMSET_IDLE_ROIC_2_R0_2ndMux_r1_g3,
	 },
	 [3] = {
	  .tBit.r0_cr_mux1_r1g1 = PARAMSET_IDLE_ROIC_3_R0_1stMux_r1_g1,
	  .tBit.r0_cr_mux1_r1g2 = PARAMSET_IDLE_ROIC_3_R0_1stMux_r1_g2,
	  .tBit.r0_cr_mux1_r1g3 = PARAMSET_IDLE_ROIC_3_R0_1stMux_r1_g3,
	  .tBit.r0_cr_mux2_r1g1 = PARAMSET_IDLE_ROIC_3_R0_2ndMux_r1_g1,
	  .tBit.r0_cr_mux2_r1g2 = PARAMSET_IDLE_ROIC_3_R0_2ndMux_r1_g2,
	  .tBit.r0_cr_mux2_r1g3 = PARAMSET_IDLE_ROIC_3_R0_2ndMux_r1_g3,
	 },
	 [4] = {
	  .tBit.r0_cr_mux1_r1g1 = PARAMSET_IDLE_ROIC_4_R0_1stMux_r1_g1,
	  .tBit.r0_cr_mux1_r1g2 = PARAMSET_IDLE_ROIC_4_R0_1stMux_r1_g2,
	  .tBit.r0_cr_mux1_r1g3 = PARAMSET_IDLE_ROIC_4_R0_1stMux_r1_g3,
	  .tBit.r0_cr_mux2_r1g1 = PARAMSET_IDLE_ROIC_4_R0_2ndMux_r1_g1,
	  .tBit.r0_cr_mux2_r1g2 = PARAMSET_IDLE_ROIC_4_R0_2ndMux_r1_g2,
	  .tBit.r0_cr_mux2_r1g3 = PARAMSET_IDLE_ROIC_4_R0_2ndMux_r1_g3,
	 },
};

tR0_CR_R2G_MUX1_2_t tIDLE_R0_CR_R2G_MUX1_2[6] =
{
	 [0] = {
	  .tBit.r0_cr_mux1_r2g1 = PARAMSET_IDLE_ROIC_0_R0_1stMux_r2_g1,
	  .tBit.r0_cr_mux1_r2g2 = PARAMSET_IDLE_ROIC_0_R0_1stMux_r2_g2,
	  .tBit.r0_cr_mux1_r2g3 = PARAMSET_IDLE_ROIC_0_R0_1stMux_r2_g3,
	  .tBit.r0_cr_mux2_r2g1 = PARAMSET_IDLE_ROIC_0_R0_2ndMux_r2_g1,
	  .tBit.r0_cr_mux2_r2g2 = PARAMSET_IDLE_ROIC_0_R0_2ndMux_r2_g2,
	  .tBit.r0_cr_mux2_r2g3 = PARAMSET_IDLE_ROIC_0_R0_2ndMux_r2_g3,
	 },
	 [1] = {
	  .tBit.r0_cr_mux1_r2g1 = PARAMSET_IDLE_ROIC_1_R0_1stMux_r2_g1,
	  .tBit.r0_cr_mux1_r2g2 = PARAMSET_IDLE_ROIC_1_R0_1stMux_r2_g2,
	  .tBit.r0_cr_mux1_r2g3 = PARAMSET_IDLE_ROIC_1_R0_1stMux_r2_g3,
	  .tBit.r0_cr_mux2_r2g1 = PARAMSET_IDLE_ROIC_1_R0_2ndMux_r2_g1,
	  .tBit.r0_cr_mux2_r2g2 = PARAMSET_IDLE_ROIC_1_R0_2ndMux_r2_g2,
	  .tBit.r0_cr_mux2_r2g3 = PARAMSET_IDLE_ROIC_1_R0_2ndMux_r2_g3,
	 },
	 [2] = {
	  .tBit.r0_cr_mux1_r2g1 = PARAMSET_IDLE_ROIC_2_R0_1stMux_r2_g1,
	  .tBit.r0_cr_mux1_r2g2 = PARAMSET_IDLE_ROIC_2_R0_1stMux_r2_g2,
	  .tBit.r0_cr_mux1_r2g3 = PARAMSET_IDLE_ROIC_2_R0_1stMux_r2_g3,
	  .tBit.r0_cr_mux2_r2g1 = PARAMSET_IDLE_ROIC_2_R0_2ndMux_r2_g1,
	  .tBit.r0_cr_mux2_r2g2 = PARAMSET_IDLE_ROIC_2_R0_2ndMux_r2_g2,
	  .tBit.r0_cr_mux2_r2g3 = PARAMSET_IDLE_ROIC_2_R0_2ndMux_r2_g3,
	 },
	 [3] = {
	  .tBit.r0_cr_mux1_r2g1 = PARAMSET_IDLE_ROIC_3_R0_1stMux_r2_g1,
	  .tBit.r0_cr_mux1_r2g2 = PARAMSET_IDLE_ROIC_3_R0_1stMux_r2_g2,
	  .tBit.r0_cr_mux1_r2g3 = PARAMSET_IDLE_ROIC_3_R0_1stMux_r2_g3,
	  .tBit.r0_cr_mux2_r2g1 = PARAMSET_IDLE_ROIC_3_R0_2ndMux_r2_g1,
	  .tBit.r0_cr_mux2_r2g2 = PARAMSET_IDLE_ROIC_3_R0_2ndMux_r2_g2,
	  .tBit.r0_cr_mux2_r2g3 = PARAMSET_IDLE_ROIC_3_R0_2ndMux_r2_g3,
	 },
	 [4] = {
	  .tBit.r0_cr_mux1_r2g1 = PARAMSET_IDLE_ROIC_4_R0_1stMux_r2_g1,
	  .tBit.r0_cr_mux1_r2g2 = PARAMSET_IDLE_ROIC_4_R0_1stMux_r2_g2,
	  .tBit.r0_cr_mux1_r2g3 = PARAMSET_IDLE_ROIC_4_R0_1stMux_r2_g3,
	  .tBit.r0_cr_mux2_r2g1 = PARAMSET_IDLE_ROIC_4_R0_2ndMux_r2_g1,
	  .tBit.r0_cr_mux2_r2g2 = PARAMSET_IDLE_ROIC_4_R0_2ndMux_r2_g2,
	  .tBit.r0_cr_mux2_r2g3 = PARAMSET_IDLE_ROIC_4_R0_2ndMux_r2_g3,
	 },
};

tR0_CR_R3G_MUX1_2_t tIDLE_R0_CR_R3G_MUX1_2[6] =
{
	 [0] = {
	  .tBit.r0_cr_mux1_r3g1 = PARAMSET_IDLE_ROIC_0_R0_1stMux_r3_g1,
	  .tBit.r0_cr_mux1_r3g2 = PARAMSET_IDLE_ROIC_0_R0_1stMux_r3_g2,
	  .tBit.r0_cr_mux1_r3g3 = PARAMSET_IDLE_ROIC_0_R0_1stMux_r3_g3,
	  .tBit.r0_cr_mux2_r3g1 = PARAMSET_IDLE_ROIC_0_R0_2ndMux_r3_g1,
	  .tBit.r0_cr_mux2_r3g2 = PARAMSET_IDLE_ROIC_0_R0_2ndMux_r3_g2,
	  .tBit.r0_cr_mux2_r3g3 = PARAMSET_IDLE_ROIC_0_R0_2ndMux_r3_g3,
	 },
	 [1] = {
	  .tBit.r0_cr_mux1_r3g1 = PARAMSET_IDLE_ROIC_1_R0_1stMux_r3_g1,
	  .tBit.r0_cr_mux1_r3g2 = PARAMSET_IDLE_ROIC_1_R0_1stMux_r3_g2,
	  .tBit.r0_cr_mux1_r3g3 = PARAMSET_IDLE_ROIC_1_R0_1stMux_r3_g3,
	  .tBit.r0_cr_mux2_r3g1 = PARAMSET_IDLE_ROIC_1_R0_2ndMux_r3_g1,
	  .tBit.r0_cr_mux2_r3g2 = PARAMSET_IDLE_ROIC_1_R0_2ndMux_r3_g2,
	  .tBit.r0_cr_mux2_r3g3 = PARAMSET_IDLE_ROIC_1_R0_2ndMux_r3_g3,
	 },
	 [2] = {
	  .tBit.r0_cr_mux1_r3g1 = PARAMSET_IDLE_ROIC_2_R0_1stMux_r3_g1,
	  .tBit.r0_cr_mux1_r3g2 = PARAMSET_IDLE_ROIC_2_R0_1stMux_r3_g2,
	  .tBit.r0_cr_mux1_r3g3 = PARAMSET_IDLE_ROIC_2_R0_1stMux_r3_g3,
	  .tBit.r0_cr_mux2_r3g1 = PARAMSET_IDLE_ROIC_2_R0_2ndMux_r3_g1,
	  .tBit.r0_cr_mux2_r3g2 = PARAMSET_IDLE_ROIC_2_R0_2ndMux_r3_g2,
	  .tBit.r0_cr_mux2_r3g3 = PARAMSET_IDLE_ROIC_2_R0_2ndMux_r3_g3,
	 },
	 [3] = {
	  .tBit.r0_cr_mux1_r3g1 = PARAMSET_IDLE_ROIC_3_R0_1stMux_r3_g1,
	  .tBit.r0_cr_mux1_r3g2 = PARAMSET_IDLE_ROIC_3_R0_1stMux_r3_g2,
	  .tBit.r0_cr_mux1_r3g3 = PARAMSET_IDLE_ROIC_3_R0_1stMux_r3_g3,
	  .tBit.r0_cr_mux2_r3g1 = PARAMSET_IDLE_ROIC_3_R0_2ndMux_r3_g1,
	  .tBit.r0_cr_mux2_r3g2 = PARAMSET_IDLE_ROIC_3_R0_2ndMux_r3_g2,
	  .tBit.r0_cr_mux2_r3g3 = PARAMSET_IDLE_ROIC_3_R0_2ndMux_r3_g3,
	 },
	 [4] = {
	  .tBit.r0_cr_mux1_r3g1 = PARAMSET_IDLE_ROIC_4_R0_1stMux_r3_g1,
	  .tBit.r0_cr_mux1_r3g2 = PARAMSET_IDLE_ROIC_4_R0_1stMux_r3_g2,
	  .tBit.r0_cr_mux1_r3g3 = PARAMSET_IDLE_ROIC_4_R0_1stMux_r3_g3,
	  .tBit.r0_cr_mux2_r3g1 = PARAMSET_IDLE_ROIC_4_R0_2ndMux_r3_g1,
	  .tBit.r0_cr_mux2_r3g2 = PARAMSET_IDLE_ROIC_4_R0_2ndMux_r3_g2,
	  .tBit.r0_cr_mux2_r3g3 = PARAMSET_IDLE_ROIC_4_R0_2ndMux_r3_g3,
	 },
};

tR1_CR_R1G_MUX1_2_t tIDLE_R1_CR_R1G_MUX1_2[6] =
{
	 [0] = {
	  .tBit.r1_cr_mux1_r1g1 = PARAMSET_IDLE_ROIC_0_R1_1stMux_r1_g1,
	  .tBit.r1_cr_mux1_r1g2 = PARAMSET_IDLE_ROIC_0_R1_1stMux_r1_g2,
	  .tBit.r1_cr_mux1_r1g3 = PARAMSET_IDLE_ROIC_0_R1_1stMux_r1_g3,
	  .tBit.r1_cr_mux2_r1g1 = PARAMSET_IDLE_ROIC_0_R1_2ndMux_r1_g1,
	  .tBit.r1_cr_mux2_r1g2 = PARAMSET_IDLE_ROIC_0_R1_2ndMux_r1_g2,
	  .tBit.r1_cr_mux2_r1g3 = PARAMSET_IDLE_ROIC_0_R1_2ndMux_r1_g3,
	 },
	 [1] = {
	  .tBit.r1_cr_mux1_r1g1 = PARAMSET_IDLE_ROIC_1_R1_1stMux_r1_g1,
	  .tBit.r1_cr_mux1_r1g2 = PARAMSET_IDLE_ROIC_1_R1_1stMux_r1_g2,
	  .tBit.r1_cr_mux1_r1g3 = PARAMSET_IDLE_ROIC_1_R1_1stMux_r1_g3,
	  .tBit.r1_cr_mux2_r1g1 = PARAMSET_IDLE_ROIC_1_R1_2ndMux_r1_g1,
	  .tBit.r1_cr_mux2_r1g2 = PARAMSET_IDLE_ROIC_1_R1_2ndMux_r1_g2,
	  .tBit.r1_cr_mux2_r1g3 = PARAMSET_IDLE_ROIC_1_R1_2ndMux_r1_g3,
	 },
	 [2] = {
	  .tBit.r1_cr_mux1_r1g1 = PARAMSET_IDLE_ROIC_2_R1_1stMux_r1_g1,
	  .tBit.r1_cr_mux1_r1g2 = PARAMSET_IDLE_ROIC_2_R1_1stMux_r1_g2,
	  .tBit.r1_cr_mux1_r1g3 = PARAMSET_IDLE_ROIC_2_R1_1stMux_r1_g3,
	  .tBit.r1_cr_mux2_r1g1 = PARAMSET_IDLE_ROIC_2_R1_2ndMux_r1_g1,
	  .tBit.r1_cr_mux2_r1g2 = PARAMSET_IDLE_ROIC_2_R1_2ndMux_r1_g2,
	  .tBit.r1_cr_mux2_r1g3 = PARAMSET_IDLE_ROIC_2_R1_2ndMux_r1_g3,
	 },
	 [3] = {
	  .tBit.r1_cr_mux1_r1g1 = PARAMSET_IDLE_ROIC_3_R1_1stMux_r1_g1,
	  .tBit.r1_cr_mux1_r1g2 = PARAMSET_IDLE_ROIC_3_R1_1stMux_r1_g2,
	  .tBit.r1_cr_mux1_r1g3 = PARAMSET_IDLE_ROIC_3_R1_1stMux_r1_g3,
	  .tBit.r1_cr_mux2_r1g1 = PARAMSET_IDLE_ROIC_3_R1_2ndMux_r1_g1,
	  .tBit.r1_cr_mux2_r1g2 = PARAMSET_IDLE_ROIC_3_R1_2ndMux_r1_g2,
	  .tBit.r1_cr_mux2_r1g3 = PARAMSET_IDLE_ROIC_3_R1_2ndMux_r1_g3,
	 },
	 [4] = {
	  .tBit.r1_cr_mux1_r1g1 = PARAMSET_IDLE_ROIC_4_R1_1stMux_r1_g1,
	  .tBit.r1_cr_mux1_r1g2 = PARAMSET_IDLE_ROIC_4_R1_1stMux_r1_g2,
	  .tBit.r1_cr_mux1_r1g3 = PARAMSET_IDLE_ROIC_4_R1_1stMux_r1_g3,
	  .tBit.r1_cr_mux2_r1g1 = PARAMSET_IDLE_ROIC_4_R1_2ndMux_r1_g1,
	  .tBit.r1_cr_mux2_r1g2 = PARAMSET_IDLE_ROIC_4_R1_2ndMux_r1_g2,
	  .tBit.r1_cr_mux2_r1g3 = PARAMSET_IDLE_ROIC_4_R1_2ndMux_r1_g3,
	 },
};

tR1_CR_R2G_MUX1_2_t tIDLE_R1_CR_R2G_MUX1_2[6] =
{
	 [0] = {
	  .tBit.r1_cr_mux1_r2g1 = PARAMSET_IDLE_ROIC_0_R1_1stMux_r2_g1,
	  .tBit.r1_cr_mux1_r2g2 = PARAMSET_IDLE_ROIC_0_R1_1stMux_r2_g2,
	  .tBit.r1_cr_mux1_r2g3 = PARAMSET_IDLE_ROIC_0_R1_1stMux_r2_g3,
	  .tBit.r1_cr_mux2_r2g1 = PARAMSET_IDLE_ROIC_0_R1_2ndMux_r2_g1,
	  .tBit.r1_cr_mux2_r2g2 = PARAMSET_IDLE_ROIC_0_R1_2ndMux_r2_g2,
	  .tBit.r1_cr_mux2_r2g3 = PARAMSET_IDLE_ROIC_0_R1_2ndMux_r2_g3,
	 },
	 [1] = {
	  .tBit.r1_cr_mux1_r2g1 = PARAMSET_IDLE_ROIC_1_R1_1stMux_r2_g1,
	  .tBit.r1_cr_mux1_r2g2 = PARAMSET_IDLE_ROIC_1_R1_1stMux_r2_g2,
	  .tBit.r1_cr_mux1_r2g3 = PARAMSET_IDLE_ROIC_1_R1_1stMux_r2_g3,
	  .tBit.r1_cr_mux2_r2g1 = PARAMSET_IDLE_ROIC_1_R1_2ndMux_r2_g1,
	  .tBit.r1_cr_mux2_r2g2 = PARAMSET_IDLE_ROIC_1_R1_2ndMux_r2_g2,
	  .tBit.r1_cr_mux2_r2g3 = PARAMSET_IDLE_ROIC_1_R1_2ndMux_r2_g3,
	 },
	 [2] = {
	  .tBit.r1_cr_mux1_r2g1 = PARAMSET_IDLE_ROIC_2_R1_1stMux_r2_g1,
	  .tBit.r1_cr_mux1_r2g2 = PARAMSET_IDLE_ROIC_2_R1_1stMux_r2_g2,
	  .tBit.r1_cr_mux1_r2g3 = PARAMSET_IDLE_ROIC_2_R1_1stMux_r2_g3,
	  .tBit.r1_cr_mux2_r2g1 = PARAMSET_IDLE_ROIC_2_R1_2ndMux_r2_g1,
	  .tBit.r1_cr_mux2_r2g2 = PARAMSET_IDLE_ROIC_2_R1_2ndMux_r2_g2,
	  .tBit.r1_cr_mux2_r2g3 = PARAMSET_IDLE_ROIC_2_R1_2ndMux_r2_g3,
	 },
	 [3] = {
	  .tBit.r1_cr_mux1_r2g1 = PARAMSET_IDLE_ROIC_3_R1_1stMux_r2_g1,
	  .tBit.r1_cr_mux1_r2g2 = PARAMSET_IDLE_ROIC_3_R1_1stMux_r2_g2,
	  .tBit.r1_cr_mux1_r2g3 = PARAMSET_IDLE_ROIC_3_R1_1stMux_r2_g3,
	  .tBit.r1_cr_mux2_r2g1 = PARAMSET_IDLE_ROIC_3_R1_2ndMux_r2_g1,
	  .tBit.r1_cr_mux2_r2g2 = PARAMSET_IDLE_ROIC_3_R1_2ndMux_r2_g2,
	  .tBit.r1_cr_mux2_r2g3 = PARAMSET_IDLE_ROIC_3_R1_2ndMux_r2_g3,
	 },
	 [4] = {
	  .tBit.r1_cr_mux1_r2g1 = PARAMSET_IDLE_ROIC_4_R1_1stMux_r2_g1,
	  .tBit.r1_cr_mux1_r2g2 = PARAMSET_IDLE_ROIC_4_R1_1stMux_r2_g2,
	  .tBit.r1_cr_mux1_r2g3 = PARAMSET_IDLE_ROIC_4_R1_1stMux_r2_g3,
	  .tBit.r1_cr_mux2_r2g1 = PARAMSET_IDLE_ROIC_4_R1_2ndMux_r2_g1,
	  .tBit.r1_cr_mux2_r2g2 = PARAMSET_IDLE_ROIC_4_R1_2ndMux_r2_g2,
	  .tBit.r1_cr_mux2_r2g3 = PARAMSET_IDLE_ROIC_4_R1_2ndMux_r2_g3,
	 },
};

tR1_CR_R3G_MUX1_2_t tIDLE_R1_CR_R3G_MUX1_2[6] =
{
	 [0] = {
	  .tBit.r1_cr_mux1_r3g1 = PARAMSET_IDLE_ROIC_0_R1_1stMux_r3_g1,
	  .tBit.r1_cr_mux1_r3g2 = PARAMSET_IDLE_ROIC_0_R1_1stMux_r3_g2,
	  .tBit.r1_cr_mux1_r3g3 = PARAMSET_IDLE_ROIC_0_R1_1stMux_r3_g3,
	  .tBit.r1_cr_mux2_r3g1 = PARAMSET_IDLE_ROIC_0_R1_2ndMux_r3_g1,
	  .tBit.r1_cr_mux2_r3g2 = PARAMSET_IDLE_ROIC_0_R1_2ndMux_r3_g2,
	  .tBit.r1_cr_mux2_r3g3 = PARAMSET_IDLE_ROIC_0_R1_2ndMux_r3_g3,
	 },
	 [1] = {
	  .tBit.r1_cr_mux1_r3g1 = PARAMSET_IDLE_ROIC_1_R1_1stMux_r3_g1,
	  .tBit.r1_cr_mux1_r3g2 = PARAMSET_IDLE_ROIC_1_R1_1stMux_r3_g2,
	  .tBit.r1_cr_mux1_r3g3 = PARAMSET_IDLE_ROIC_1_R1_1stMux_r3_g3,
	  .tBit.r1_cr_mux2_r3g1 = PARAMSET_IDLE_ROIC_1_R1_2ndMux_r3_g1,
	  .tBit.r1_cr_mux2_r3g2 = PARAMSET_IDLE_ROIC_1_R1_2ndMux_r3_g2,
	  .tBit.r1_cr_mux2_r3g3 = PARAMSET_IDLE_ROIC_1_R1_2ndMux_r3_g3,
	 },
	 [2] = {
	  .tBit.r1_cr_mux1_r3g1 = PARAMSET_IDLE_ROIC_2_R1_1stMux_r3_g1,
	  .tBit.r1_cr_mux1_r3g2 = PARAMSET_IDLE_ROIC_2_R1_1stMux_r3_g2,
	  .tBit.r1_cr_mux1_r3g3 = PARAMSET_IDLE_ROIC_2_R1_1stMux_r3_g3,
	  .tBit.r1_cr_mux2_r3g1 = PARAMSET_IDLE_ROIC_2_R1_2ndMux_r3_g1,
	  .tBit.r1_cr_mux2_r3g2 = PARAMSET_IDLE_ROIC_2_R1_2ndMux_r3_g2,
	  .tBit.r1_cr_mux2_r3g3 = PARAMSET_IDLE_ROIC_2_R1_2ndMux_r3_g3,
	 },
	 [3] = {
	  .tBit.r1_cr_mux1_r3g1 = PARAMSET_IDLE_ROIC_3_R1_1stMux_r3_g1,
	  .tBit.r1_cr_mux1_r3g2 = PARAMSET_IDLE_ROIC_3_R1_1stMux_r3_g2,
	  .tBit.r1_cr_mux1_r3g3 = PARAMSET_IDLE_ROIC_3_R1_1stMux_r3_g3,
	  .tBit.r1_cr_mux2_r3g1 = PARAMSET_IDLE_ROIC_3_R1_2ndMux_r3_g1,
	  .tBit.r1_cr_mux2_r3g2 = PARAMSET_IDLE_ROIC_3_R1_2ndMux_r3_g2,
	  .tBit.r1_cr_mux2_r3g3 = PARAMSET_IDLE_ROIC_3_R1_2ndMux_r3_g3,
	 },
	 [4] = {
	  .tBit.r1_cr_mux1_r3g1 = PARAMSET_IDLE_ROIC_4_R1_1stMux_r3_g1,
	  .tBit.r1_cr_mux1_r3g2 = PARAMSET_IDLE_ROIC_4_R1_1stMux_r3_g2,
	  .tBit.r1_cr_mux1_r3g3 = PARAMSET_IDLE_ROIC_4_R1_1stMux_r3_g3,
	  .tBit.r1_cr_mux2_r3g1 = PARAMSET_IDLE_ROIC_4_R1_2ndMux_r3_g1,
	  .tBit.r1_cr_mux2_r3g2 = PARAMSET_IDLE_ROIC_4_R1_2ndMux_r3_g2,
	  .tBit.r1_cr_mux2_r3g3 = PARAMSET_IDLE_ROIC_4_R1_2ndMux_r3_g3,
	 },
};

tR0_TUNE_ROW_MUX1_2_t tR0_TUNE_IDLE_ROW_MUX1_2 =
{
	.tBit.r0_cr_mux1_row1_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row1_gsel,
	.tBit.r0_cr_mux1_row2_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row2_gsel,
	.tBit.r0_cr_mux1_row3_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row3_gsel,
	.tBit.r0_cr_mux1_row4_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row4_gsel,
	.tBit.r0_cr_mux1_row5_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row5_gsel,
	.tBit.r0_cr_mux2_row1_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row1_gsel,
	.tBit.r0_cr_mux2_row2_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row2_gsel,
	.tBit.r0_cr_mux2_row3_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row3_gsel,
	.tBit.r0_cr_mux2_row4_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row4_gsel,
	.tBit.r0_cr_mux2_row5_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row5_gsel,
};

tR1_TUNE_ROW_MUX1_2_t tR1_TUNE_IDLE_ROW_MUX1_2 =
{
	.tBit.r1_cr_mux1_row1_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row1_gsel,
	.tBit.r1_cr_mux1_row2_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row2_gsel,
	.tBit.r1_cr_mux1_row3_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row3_gsel,
	.tBit.r1_cr_mux1_row4_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row4_gsel,
	.tBit.r1_cr_mux1_row5_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux1_row5_gsel,
	.tBit.r1_cr_mux2_row1_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row1_gsel,
	.tBit.r1_cr_mux2_row2_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row2_gsel,
	.tBit.r1_cr_mux2_row3_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row3_gsel,
	.tBit.r1_cr_mux2_row4_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row4_gsel,
	.tBit.r1_cr_mux2_row5_gsel = PARAMSET_IDLE_ROIC_R0_TUNE_ROW_MUX_r0_cr_mux2_row5_gsel,
};

tMUX_CTL_t tIdle_MUX_CTL =
{
	.tBit.tot_mux_num = PARAMSET_ROIC_CFGR_IDLE_MUX_CTL_tot_mux_num,
};

tFIG_MUX_CFG_00_t tIdle_FIG_MUX_CFG_00 =
{
	.tBit.fig_mux_00 = PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_00,
	.tBit.fig_mux_01 = PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_01,
	.tBit.fig_mux_02 = PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_02,
	.tBit.fig_mux_03 = PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_03,
	.tBit.fig_mux_04 = PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_04,
	.tBit.fig_mux_05 = PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_05,
	.tBit.fig_mux_06 = PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_06,
	.tBit.fig_mux_07 = PARAMSET_ROIC_IDLE_CFGR_FIG_MUX_CFG_00_fig_mux_07,
};

tPWM_FIG_CTL_t tIdle_PWM_FIG_CTL =
{
	.tBit.pwm_fig_act_num = PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_act_num,
	.tBit.pwm_fig_mgap_num = PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_mgap_num,
	.tBit.pwm_fig_dum_num = PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_dum_num + PARAMSET_ROIC_CFGR_PWM_FIG_IDLE_CTL_pwm_set_num,
};

tPWM_POS_CTL_t tIdle_PWM_PEN_POS_CTL =
{
	.tBit.pwm_pos_pdrv_num = PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_pdrv_num,
	.tBit.pwm_pos_act_num = PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_act_num,
	.tBit.pwm_pos_mgap_num = PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_mgap_num,
	.tBit.pwm_pos_dum_num = PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_dum_num + PARAMSET_ROIC_CFGR_PWM_POS_IDLE_CTL_pwm_set_num,
};

tR0_LHB_MUX_CTL_t tIdle_R0_LHB_MUX_CTL =
{
	.tBit.r0_mux_m1_bit_en = PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_m1_bit_en,
	.tBit.r0_mux_nd_bit_en = PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_nd_bit_en,
	.tBit.r0_mux_pp_bit_en = PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_pp_bit_en,
	.tBit.r0_mux_pd_bit_en = PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_pd_bit_en,
};

tR1_LHB_MUX_CTL_t tIdle_R1_LHB_MUX_CTL =
{
	.tBit.r1_mux_m1_bit_en = PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_m1_bit_en,
	.tBit.r1_mux_nd_bit_en = PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_nd_bit_en,
	.tBit.r1_mux_pp_bit_en = PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_pp_bit_en,
	.tBit.r1_mux_pd_bit_en = PARAMSET_IDLE_ROIC_LHB_MUX_CTL_r0_mux_pd_bit_en,
};

tSMPL_CTL_t tIdle_SMPL_CTL =
{
	.tBit.fig_smop_prd = PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_fig_smop_prd,
	.tBit.pen_smop_prd = PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_fig_smop_prd,
	.tBit.nd_smop_prd = PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_nd_smop_prd,
	.tBit.cr_repeat_num = PARAMSET_IDLE_ROIC_CFGR_SMPL_CTL_cr_repeat_num,
};

tRCOM_LHB_CFG_t tIdle_RCOM_LHB_CFG =
{
 .tBit.nxt_lhb_mode = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_nxt_lhb_mode,
 .tBit.tsync_num = PARAMSET_ROIC_IDLE_CFGR_RCOM_LHB_CFG_tsync_num,
 .tBit.dum_tsync_num = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_dum_tsync_num,
 .tBit.beacon_en = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_beacon_en,
 .tBit.rdcom_en = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_rdcom_en,
 .tBit.sgap_num = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_sgap_num,
 .tBit.r0pd = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_r0pd,
 .tBit.r1pd = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_r1pd,
 .tBit.sel_hover = PARAMSET_ROIC_CFGR_RCOM_LHB_CFG_sel_hover,
};
//tCFGR_PWM_CTL_t CFGR_Idle_PWM_CTL =
//{
//	.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_pdrv_num,
//	.tBit.pwm_act_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_act_num,
//	.tBit.pwm_smpl_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_smpl_num,
//	.tBit.pwm_dum_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_dum_num,
//	.tBit.pdrv_dum_num = PARAMSET_ROIC_PWM_IDLE_CTL_pdrv_dum_num,
//	.tBit.pwm_set_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_set_num,
//};
//
//tCFGR_PEN_MUX_BIT_EN_t CFGR_PEN_IDLE_MUX_BIT_EN =
//{
//	.tBit.mux_beacon_bit_en = PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_beacon_bit_en,
//	.tBit.mux_pen_pos_bit_en = PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_pen_pos_bit_en,
//	.tBit.mux_pen_dat_bit_en = PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_pen_dat_bit_en,
//};
#endif /* (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL) */

void SW92512_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
	switch(eMode)
	{
		case ROIC_REG_SET_CHANGE_MUX_REMAP:
		{
			break;
		}
		case ROIC_REG_SET_CHAGNE_CR_TUNE:
		{
			SW92512_Reg_CRTuneSetting(CRTUNE_TYPE_INIT);
			break;
		}
		case ROIC_REG_SET_CHAGNE_WGPPen_Local_Setting: // WGP Local
		{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			MSPI_RegisterWrite((uint32_t)(0x0034), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0038), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_POS_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x003C), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_DAT_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0040), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.ND_CTRL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0044), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_PRD.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x004C), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_RSTP_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0050), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0054), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTCR_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0058), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_VCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x005C), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_VCR_EN_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0064), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTH0_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0068), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTH1_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x006C), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHTH_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0074), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PHT_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x00DC), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_PWM_SET_EN_BIT.ulBulk);
			SW92512_Reg_LHBSetting_ByChangeMode(ROIC_REG_SET_CHAGNE_WGPPen_Local_Setting);
			MSPI_RegisterWrite((uint32_t)(0x01B8), tSW92512ActivePen_Runtime_Change_WGP_Local_Reg.CFGR_SENSE_CTRL.ulBulk);
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
			MSPI_RegisterWrite((uint32_t)(0x0034), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0038), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_POS_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x003C), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_DAT_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0040), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.ND_CTRL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0044), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_PRD.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x004C), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_RSTP_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0050), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0054), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTCR_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0058), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_VCR_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x005C), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_VCR_EN_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0064), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTH0_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0068), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTH1_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x006C), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHTH_NUM2.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0074), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PHT_NUM1.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x00DC), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_PWM_SET_EN_BIT.ulBulk);
			SW92512_Reg_LHBSetting_ByChangeMode(ROIC_REG_SET_CHAGNE_MSPen_Local_Setting);
			MSPI_RegisterWrite((uint32_t)(0x01B8), tSW92512ActivePen_Runtime_Change_MPP25_Local_Reg.CFGR_SENSE_CTRL.ulBulk);
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
			SW92512_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);

			break;
		}
		case ROIC_REG_SET_CHANGE_Local_To_Full:
		{
			SW92512_Reg_LHBSetting(PWM_FULL_FINGER_MODE);

			break;
		}
#endif /* USED_PEN_MODE_OPERATION */
#if USED_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_Full_To_FullIdle:
		{
			SW92512_Reg_LHBSetting(PWM_FULL_FINGER_IDLE_MODE);
			MSPI_RegisterMultiWrite((uint32_t)(0x0250), (uint32_t *)&t_IDLE_R0_CR_GTUNE[0].ulBulk);  // R/W
			MSPI_RegisterMultiWrite((uint32_t)(0x0350), (uint32_t *)&t_IDLE_R1_CR_GTUNE[0].ulBulk);  // R/W

		    MSPI_RegisterMultiWrite((uint32_t)(0x0214), (uint32_t *)&tIDLE_R0_CR_R1G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x0218), (uint32_t *)&tIDLE_R0_CR_R2G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x021C), (uint32_t *)&tIDLE_R0_CR_R3G_MUX1_2[0].ulBulk);  // R/W

		    MSPI_RegisterMultiWrite((uint32_t)(0x0314), (uint32_t *)&tIDLE_R1_CR_R1G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x0318), (uint32_t *)&tIDLE_R1_CR_R2G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x031C), (uint32_t *)&tIDLE_R1_CR_R3G_MUX1_2[0].ulBulk);  // R/W

		    MSPI_RegisterWrite((uint32_t)(0x0254), tR0_TUNE_IDLE_ROW_MUX1_2.ulBulk);  // R/W
		    MSPI_RegisterWrite((uint32_t)(0x0354), tR1_TUNE_IDLE_ROW_MUX1_2.ulBulk);  // R/W

			MSPI_RegisterWrite((uint32_t)(0x0020), tIdle_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x009C), tIdle_FIG_MUX_CFG_00.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0034), tIdle_PWM_FIG_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x02B8), tIdle_R0_LHB_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x03B8), tIdle_R1_LHB_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0048), tIdle_SMPL_CTL.ulBulk);  // R/W

			MSPI_RegisterWrite((uint32_t)(0x00A4), tIdle_RCOM_LHB_CFG.ulBulk);  // R/W

	#if USED_IDLE_MODE_30Hz_CONTROL || USED_IDLE_MODE_20Hz_CONTROL
			/*
			 * Dummy Write to finish the write in the tsync high section.
			 */
			{
				MSPI_RegisterWrite((uint32_t)(0x009C), tIdle_FIG_MUX_CFG_00.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x0034), tIdle_PWM_FIG_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x02B8), tIdle_R0_LHB_MUX_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x03B8), tIdle_R1_LHB_MUX_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x0048), tIdle_SMPL_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x00A4), tIdle_RCOM_LHB_CFG.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x03B8), tIdle_R1_LHB_MUX_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x0048), tIdle_SMPL_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x00A4), tIdle_RCOM_LHB_CFG.ulBulk);  // R/W
			}
	#endif /* USED_IDLE_MODE_30Hz_CONTROL */

//			MSPI_RegisterWrite((uint32_t)(0x0034), CFGR_Idle_PWM_CTL.ulBulk);
//			MSPI_RegisterWrite((uint32_t)(0x00EC), CFGR_PEN_IDLE_MUX_BIT_EN.ulBulk);

	#if USED_IDLE_MODE_30Hz_CONTROL || USED_IDLE_MODE_20Hz_CONTROL
			/*
			 * Must write in the tsync high section
			 */
			{
				tSYS_CFG_t tSYS_CFG;
				tSYS_CFG.ulBulk = s_pktmoduleSRICCommonConf->SYS_CFG.ulBulk;
				tSYS_CFG.tBit.tg_reset = 1;
				MSPI_RegisterWrite((uint32_t)(0x0014), tSYS_CFG.ulBulk);
				tSYS_CFG.tBit.tg_reset = 0;
				MSPI_RegisterWrite((uint32_t)(0x0014), tSYS_CFG.ulBulk);
			}
	#endif /* USED_IDLE_MODE_30Hz_CONTROL */
			break;
		}
#endif /* USED_IDLE_MODE_CONTROL */
#if USED_LOCAL_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_Local_To_LocalIdle:
		{
			SW92512_Reg_LHBSetting(PWM_LOCAL_PEN_IDLE_MODE);


			MSPI_RegisterMultiWrite((uint32_t)(0x0250), (uint32_t *)&t_IDLE_R0_CR_GTUNE[0].ulBulk);  // R/W
			MSPI_RegisterMultiWrite((uint32_t)(0x0350), (uint32_t *)&t_IDLE_R1_CR_GTUNE[0].ulBulk);  // R/W

		    MSPI_RegisterMultiWrite((uint32_t)(0x0214), (uint32_t *)&tIDLE_R0_CR_R1G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x0218), (uint32_t *)&tIDLE_R0_CR_R2G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x021C), (uint32_t *)&tIDLE_R0_CR_R3G_MUX1_2[0].ulBulk);  // R/W

		    MSPI_RegisterMultiWrite((uint32_t)(0x0314), (uint32_t *)&tIDLE_R1_CR_R1G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x0318), (uint32_t *)&tIDLE_R1_CR_R2G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x031C), (uint32_t *)&tIDLE_R1_CR_R3G_MUX1_2[0].ulBulk);  // R/W

		    MSPI_RegisterWrite((uint32_t)(0x0254), tR0_TUNE_IDLE_ROW_MUX1_2.ulBulk);  // R/W
		    MSPI_RegisterWrite((uint32_t)(0x0354), tR1_TUNE_IDLE_ROW_MUX1_2.ulBulk);  // R/W

			MSPI_RegisterWrite((uint32_t)(0x0020), tIdle_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x009C), tIdle_FIG_MUX_CFG_00.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0034), tIdle_PWM_FIG_CTL.ulBulk);  // R/W
		    MSPI_RegisterWrite((uint32_t)(0x0038), tIdle_PWM_PEN_POS_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x02B8), tIdle_R0_LHB_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x03B8), tIdle_R1_LHB_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0048), tIdle_SMPL_CTL.ulBulk);  // R/W


			{
			 	tPEN_POS1_LHB_CFG_t tCHFG_PP_LHB_CFG;
				tCHFG_PP_LHB_CFG.tBit.pen_pos1_mux_cfg0 = 62;
				tCHFG_PP_LHB_CFG.tBit.pen_pos1_mux_cfg1 = 63;
				MSPI_RegisterWrite((uint32_t)(0x00BC), tCHFG_PP_LHB_CFG.ulBulk);
			}

			MSPI_RegisterWrite((uint32_t)(0x00A4), tIdle_RCOM_LHB_CFG.ulBulk);  // R/W

			break;
		}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
#if USED_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_FullIdle_To_Full:
		{
			SW92512_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
			MSPI_RegisterMultiWrite((uint32_t)(0x0250), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);  // R/W
			MSPI_RegisterMultiWrite((uint32_t)(0x0350), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);  // R/W

		    MSPI_RegisterMultiWrite((uint32_t)(0x0214), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x0218), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x021C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX1_2[0].ulBulk);  // R/W

		    MSPI_RegisterMultiWrite((uint32_t)(0x0314), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x0318), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x031C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX1_2[0].ulBulk);  // R/W

		    MSPI_RegisterWrite((uint32_t)(0x0254), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX1_2.ulBulk);  // R/W
		    MSPI_RegisterWrite((uint32_t)(0x0354), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX1_2.ulBulk);  // R/W

			MSPI_RegisterWrite((uint32_t)(0x0020), s_pktmoduleSRICCommonConf->MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x009C), s_pktmoduleSRICCommonConf->FIG_MUX_CFG_00.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->PWM_FIG_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x02B8), s_pktmoduleSRICCommonConf->R0_LHB_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x03B8), s_pktmoduleSRICCommonConf->R1_LHB_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->SMPL_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x00A4), s_pktmoduleSRICCommonConf->RCOM_LHB_CFG.ulBulk);  // R/W

	#if USED_IDLE_MODE_30Hz_CONTROL || USED_IDLE_MODE_20Hz_CONTROL
			/*
			 * Dummy Write to finish the write in the tsync high section.
			 */
			{
				MSPI_RegisterWrite((uint32_t)(0x009C), s_pktmoduleSRICCommonConf->FIG_MUX_CFG_00.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->PWM_FIG_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x02B8), s_pktmoduleSRICCommonConf->R0_LHB_MUX_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x03B8), s_pktmoduleSRICCommonConf->R1_LHB_MUX_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->SMPL_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x00A4), s_pktmoduleSRICCommonConf->RCOM_LHB_CFG.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x009C), s_pktmoduleSRICCommonConf->FIG_MUX_CFG_00.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->PWM_FIG_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->SMPL_CTL.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x00A4), s_pktmoduleSRICCommonConf->RCOM_LHB_CFG.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x009C), s_pktmoduleSRICCommonConf->FIG_MUX_CFG_00.ulBulk);  // R/W
				MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->PWM_FIG_CTL.ulBulk);  // R/W
			}
	#endif /* USED_IDLE_MODE_30Hz_CONTROL */

//			MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->CFGR_PWM_CTL.ulBulk);
//			MSPI_RegisterWrite((uint32_t)(0x00EC), s_pktmoduleSRICCommonConf->CFGR_PEN_MUX_BIT_EN.ulBulk);

	#if USED_IDLE_MODE_30Hz_CONTROL || USED_IDLE_MODE_20Hz_CONTROL
			/*
			 * Must write in the tsync high section
			 */
			{
				tSYS_CFG_t tSYS_CFG;
				tSYS_CFG.ulBulk = s_pktmoduleSRICCommonConf->SYS_CFG.ulBulk;
				tSYS_CFG.tBit.tg_reset = 1;
				MSPI_RegisterWrite((uint32_t)(0x0014), tSYS_CFG.ulBulk);
				tSYS_CFG.tBit.tg_reset = 0;
				MSPI_RegisterWrite((uint32_t)(0x0014), tSYS_CFG.ulBulk);
			}
	#endif /* USED_IDLE_MODE_30Hz_CONTROL */
			break;
		}
#endif /* USED_IDLE_MODE_CONTROL */
#if USED_LOCAL_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_LocalIdle_To_Local:
		{
			SW92512_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);
			MSPI_RegisterMultiWrite((uint32_t)(0x0250), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);  // R/W
			MSPI_RegisterMultiWrite((uint32_t)(0x0350), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);  // R/W

		    MSPI_RegisterMultiWrite((uint32_t)(0x0214), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x0218), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x021C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX1_2[0].ulBulk);  // R/W

		    MSPI_RegisterMultiWrite((uint32_t)(0x0314), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x0318), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x031C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX1_2[0].ulBulk);  // R/W

		    MSPI_RegisterWrite((uint32_t)(0x0254), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX1_2.ulBulk);  // R/W
		    MSPI_RegisterWrite((uint32_t)(0x0354), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX1_2.ulBulk);  // R/W

			MSPI_RegisterWrite((uint32_t)(0x0020), s_pktmoduleSRICCommonConf->MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x009C), s_pktmoduleSRICCommonConf->FIG_MUX_CFG_00.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->PWM_FIG_CTL.ulBulk);  // R/W
		    MSPI_RegisterWrite((uint32_t)(0x0038), s_pktmoduleSRICCommonConf->PWM_POS_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x02B8), s_pktmoduleSRICCommonConf->R0_LHB_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x03B8), s_pktmoduleSRICCommonConf->R1_LHB_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->SMPL_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x00A4), s_pktmoduleSRICCommonConf->RCOM_LHB_CFG.ulBulk);  // R/W

			break;
		}
		case ROIC_REG_SET_CHANGE_LocalIdle_To_Full:
		{
			SW92512_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
			MSPI_RegisterMultiWrite((uint32_t)(0x0250), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);  // R/W
			MSPI_RegisterMultiWrite((uint32_t)(0x0350), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);  // R/W

		    MSPI_RegisterMultiWrite((uint32_t)(0x0214), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x0218), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R2G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x021C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R3G_MUX1_2[0].ulBulk);  // R/W

		    MSPI_RegisterMultiWrite((uint32_t)(0x0314), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x0318), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R2G_MUX1_2[0].ulBulk);  // R/W
		    MSPI_RegisterMultiWrite((uint32_t)(0x031C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R3G_MUX1_2[0].ulBulk);  // R/W

		    MSPI_RegisterWrite((uint32_t)(0x0254), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX1_2.ulBulk);  // R/W
		    MSPI_RegisterWrite((uint32_t)(0x0354), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX1_2.ulBulk);  // R/W

			MSPI_RegisterWrite((uint32_t)(0x0020), s_pktmoduleSRICCommonConf->MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x009C), s_pktmoduleSRICCommonConf->FIG_MUX_CFG_00.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->PWM_FIG_CTL.ulBulk);  // R/W
		    MSPI_RegisterWrite((uint32_t)(0x0038), s_pktmoduleSRICCommonConf->PWM_POS_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x02B8), s_pktmoduleSRICCommonConf->R0_LHB_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x03B8), s_pktmoduleSRICCommonConf->R1_LHB_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->SMPL_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x00A4), s_pktmoduleSRICCommonConf->RCOM_LHB_CFG.ulBulk);  // R/W
			break;
		}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
#if USED_NOISE_HOPPING_FREQ
		case ROIC_REG_SET_FreHopp_CHANGE_Main_Freq:
		{
			SW92512_Reg_AFESetting(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
			MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->CFGR_PWM_CTL.ulBulk);
			SW92512_Reg_CRTuneSetting(CRTUNE_TYPE_MAIN_FRQ);


			break;
		}
		case ROIC_REG_SET_FreHopp_CHANGE_Hopp1_Freq:
		{
			tCFGR_PWM_CTL_t tTempCFGR_PWM_CTL;
			tTempCFGR_PWM_CTL.ulBulk = s_pktmoduleSRICCommonConf->CFGR_PWM_CTL.ulBulk;
			tTempCFGR_PWM_CTL.tBit.pwm_act_num = PARAMSET_ROIC_PWM_HOPPFRQ_CTL_pwm_act_num;
			tTempCFGR_PWM_CTL.tBit.pwm_smpl_num = PARAMSET_ROIC_PWM_HOPPFRQ_CTL_pwm_smpl_num;
			SW92512_Reg_AFESetting(SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE);
			MSPI_RegisterWrite((uint32_t)(0x0034), tTempCFGR_PWM_CTL.ulBulk);
			SW92512_Reg_CRTuneSetting(CRTUNE_TYPE_HOPP1_FRQ);
			break;
		}
#endif /* USED_NOISE_HOPPING_FREQ */
	}
}

#if USED_RAWDATA_TUNE_CALIBRATION
#define DEF_ROIC_TUNE_ROW_GROUP_NUM			(30)
#define DEF_ROIC_TUNE_COL_GROUP_NUM			(3)
#define DEF_ROW_LOOF_NUM					(DEF_ROIC_TUNE_ROW_GROUP_NUM>>1)

#define DEF_CR_START_FRAME_SKIP_NUM			(100)
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
	/*1 Mux*/DEF_CR_row1_gsel	,DEF_CR_row2_gsel	,DEF_CR_row3_gsel	,DEF_CR_row4_gsel	,DEF_CR_row5_gsel	,
	/*2 Mux*/DEF_CR_row1_gsel+3	,DEF_CR_row2_gsel+3	,DEF_CR_row3_gsel+3	,DEF_CR_row4_gsel+3	,DEF_CR_row5_gsel+3	,
	/*3 Mux*/DEF_CR_row1_gsel+6	,DEF_CR_row2_gsel+6	,DEF_CR_row3_gsel+6	,DEF_CR_row4_gsel+6	,DEF_CR_row5_gsel+6	,
	/*4 Mux*/DEF_CR_row1_gsel+9	,DEF_CR_row2_gsel+9	,DEF_CR_row3_gsel+9	,DEF_CR_row4_gsel+9	,DEF_CR_row5_gsel+9	,
	/*5 Mux*/DEF_CR_row1_gsel+12,DEF_CR_row2_gsel+12,DEF_CR_row3_gsel+12,DEF_CR_row4_gsel+12,DEF_CR_row5_gsel+12,
	/*6 Mux*/DEF_CR_row1_gsel+15,DEF_CR_row2_gsel+15,DEF_CR_row3_gsel+15,DEF_CR_row4_gsel+15,DEF_CR_row5_gsel+15,
	/*7 Mux*/DEF_CR_row1_gsel+18,DEF_CR_row2_gsel+18,DEF_CR_row3_gsel+18,DEF_CR_row4_gsel+18,DEF_CR_row5_gsel+18,
	/*8 Mux*/DEF_CR_row1_gsel+21,DEF_CR_row2_gsel+21,DEF_CR_row3_gsel+21,DEF_CR_row4_gsel+21,DEF_CR_row5_gsel+21,
	/*9 Mux*/DEF_CR_row1_gsel+24,DEF_CR_row2_gsel+24,DEF_CR_row3_gsel+24,DEF_CR_row4_gsel+24,DEF_CR_row5_gsel+24,
	/*9 Mux*/DEF_CR_Last_Mux_row1_gsel+27,DEF_CR_Last_Mux_row2_gsel+27,DEF_CR_Last_Mux_row3_gsel+27
};

uint8_t ulMSPIIndex[COL_MAX] = {
	/*SRIC_0*/ /*R0*/0,	0,	0,	0,	0,	0,	0,	/*R1*/5,	5,	5,	5,	5,	5,	5,
	/*SRIC_1*/ /*R0*/1,	1,	1,	1,	1,	1,	1,	/*R1*/6,	6,	6,	6,	6,	6,	6,
	/*SRIC_2*/ /*R0*/2,	2,	2,	2,	2,	2,	2,	/*R1*/7,	7,	7,	7,	7,	7,	7,
	/*SRIC_3*/ /*R0*/3,	3,	3,	3,	3,	3,	3,	/*R1*/8,	8,	8,	8,	8,	8,	8,
	/*SRIC_4*/ /*R0*/4,	4,	4,	4,	4,	4,	4,	/*R1*/9,	9,	9,	9,	9,	9,	9,
//	/*SRIC_5*/ /*R0*/5,	5,	5,	5,	5,	5,	5,	/*R1*/11,	11,	11,	11,	11,	11,	11,
};

uint8_t ulROIC_gNum[COL_MAX] = {
	/*SRIC_0*/ /* Group Idx */ 	/*R0*/DEF_CR_col1_gsel, DEF_CR_col2_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col4_gsel, DEF_CR_col5_gsel,
								/*R1*/DEF_CR_col5_gsel, DEF_CR_col4_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col2_gsel, DEF_CR_col1_gsel,
	/*SRIC_1*/ /* Group Idx */ 	/*R0*/DEF_CR_col1_gsel, DEF_CR_col2_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col4_gsel, DEF_CR_col5_gsel,
								/*R1*/DEF_CR_col5_gsel, DEF_CR_col4_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col2_gsel, DEF_CR_col1_gsel,
	/*SRIC_2*/ /* Group Idx */ 	/*R0*/DEF_CR_col1_gsel, DEF_CR_col2_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col4_gsel, DEF_CR_col5_gsel,
								/*R1*/DEF_CR_col5_gsel, DEF_CR_col4_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col2_gsel, DEF_CR_col1_gsel,
	/*SRIC_3*/ /* Group Idx */ 	/*R0*/DEF_CR_col1_gsel, DEF_CR_col2_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col4_gsel, DEF_CR_col5_gsel,
								/*R1*/DEF_CR_col5_gsel, DEF_CR_col4_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col2_gsel, DEF_CR_col1_gsel,
	/*SRIC_4*/ /* Group Idx */ 	/*R0*/DEF_CR_col1_gsel, DEF_CR_col2_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col4_gsel, DEF_CR_col5_gsel,
								/*R1*/DEF_CR_col5_gsel, DEF_CR_col4_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col2_gsel, DEF_CR_col1_gsel,
//	/*SRIC_5*/ /* Group Idx */ 	/*R0*/DEF_CR_col1_gsel, DEF_CR_col2_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col4_gsel, DEF_CR_col5_gsel,
//								/*R1*/DEF_CR_col5_gsel, DEF_CR_col4_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col3_gsel, DEF_CR_col2_gsel, DEF_CR_col1_gsel,
};

uint8_t ucROIC_CRRegIdx[DEF_ROIC_TUNE_ROW_GROUP_NUM] = {
	0,	1,	2,	0,	1,	2,
	3,	4,	5,	3,	4,	5,
	6,	7,	8,	6,	7,	8,
	9,	10,	11,	9,	10,	11,
	12,	13,	14,	12,	13,	14
};

//uint8_t ucROIC_CRRegMuxIdx[DEF_ROIC_TUNE_ROW_GROUP_NUM] = {
//	0,	0,	0,	1,	1,	1,
//	0,	0,	0,	1,	1,	1,
//	0,	1,	2,	1,	1,	1,
//	0,	0,	0,	1,	1,	1,
//	0,	0,	0,	1,	1,	1
//};

uint32_t Change_CR_Value = 0;
uint32_t auto_Cal_Start = 0;

uint32_t auto_Cal_MiddleStart = 0;

typedef union
{
	struct
	{
        __IO uint32_t cr_mux1_g1 :5;
        __IO uint32_t cr_mux1_g2 :5;
        __IO uint32_t cr_mux1_g3 :5;
        __IO uint32_t cr_mux2_g1 :5;
        __IO uint32_t cr_mux2_g2 :5;
        __IO uint32_t cr_mux2_g3 :5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tSW92512_ROIC_CR_MUX_t;

extern tParamPreMainSet_t * s_ptParamPreMainSet;
tModuleSRICCommonConf_t * g_ptSRICConfig;

tSW92512_ROIC_CR_MUX_t * g_pR0_CR_MUX_Tune;
tSW92512_ROIC_CR_MUX_t * g_pR1_CR_MUX_Tune;
bool_t bISAllFinish = NO;
uint16_t usTemp_RawData;

#define AUTO_CAL_AVERAGE_FRAME_NUM			(100)
#define AUTO_CAL_AVERAGE_SKIP_FRAME_NUM		(10) // Avoid GIP Offset Noise
void SW92512_RawDataCalibration(void)
{
	bool_t bIsLoop = YES;
	uint32_t r, c, g, framenum, framenum_2;
	uint32_t ulReal_Col;
	uint32_t ulROIC_Reg_Idx;
	uint32_t ulROIC_Reg_MUX_Idx;
	uint32_t temp_data;
	int16_t sPosTempDiff;
	int16_t sNegTempDiff;
#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE)
	ePartialSensing_t lDataIndex = PARTIAL_PEN_BEACON;
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */

	g_ptSRICConfig = (tModuleSRICCommonConf_t *)&(s_ptParamPreMainSet->tParamCommonConf.tModule.tSRIC_Conf);
	g_pR0_CR_MUX_Tune = (tSW92512_ROIC_CR_MUX_t *)&g_ptSRICConfig->R0_CR_R1G_MUX1_2[0].ulBulk;
	g_pR1_CR_MUX_Tune = (tSW92512_ROIC_CR_MUX_t *)&g_ptSRICConfig->R1_CR_R1G_MUX1_2[0].ulBulk;

	memset((void*)(&AutoCalfinish_R0[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_TUNE_ROW_GROUP_NUM*MSPI_NUM*DEF_ROIC_TUNE_COL_GROUP_NUM);
	memset((void*)(&AutoCalfinish_R1[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_TUNE_ROW_GROUP_NUM*MSPI_NUM*DEF_ROIC_TUNE_COL_GROUP_NUM);

    tHalIntrHandle.ulLocalIndexChangeStart = 1;
#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE == NO)
	if(IS_FINGER_PEN_MODE(HAL_GetSensingMode()))
	{
		HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);
		module_wait_full_sample_done();
	}
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE == NO) */

#if (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO)
	for(r=0; r<DEF_ROW_LOOF_NUM; r++)
	{
		for(c=0; c<MSPI_NUM; c++)
		{
			g_pR0_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux1_g1 = 0;
			g_pR0_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux1_g2 = 0;
			g_pR0_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux1_g3 = 0;
			g_pR0_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux2_g1 = 0;
			g_pR0_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux2_g2 = 0;
			g_pR0_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux2_g3 = 0;

			g_pR1_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux1_g1 = 0;
			g_pR1_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux1_g2 = 0;
			g_pR1_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux1_g3 = 0;
			g_pR1_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux2_g1 = 0;
			g_pR1_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux2_g2 = 0;
			g_pR1_CR_MUX_Tune[c + (r*MSPI_NUM)].tBit.cr_mux2_g3 = 0;
		}
	}

	HAL_SetROICRegSetChangeMode(ROIC_REG_SET_CHAGNE_CR_TUNE);

#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE)
	framenum = 0;
	while(1)
	{
		lDataIndex = module_wait_local_sample_done();
		if(lDataIndex == LOCAL_OP_LAST_LHB)
		{
			framenum++;
			if(framenum == DEF_CR_START_FRAME_SKIP_NUM)
			{
				break;
			}
		}
	}
#else /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
    for( framenum=0; framenum<DEF_CR_START_FRAME_SKIP_NUM; framenum++ )
    {
    	module_wait_full_sample_done();
    }
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */

#endif /* (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO) */

	while(bIsLoop)
	{
#ifdef MODE_WDT
		KICK_DOG();
#endif /* MODE_WDT */

#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE)
	    while(YES)
	    {
			lDataIndex = module_wait_local_sample_done();

			if(lDataIndex == LOCAL_FINGER_LAST_LHB)
			{
				break;
			}
		}
#else /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
		module_wait_full_sample_done();
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */

		protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
		protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);

#if (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO)
		if(bIsAutoCalFinish == NO)
		{
			ulTestCountNum++;
			/*
			 * RawData Sum
			 */
			memset((void*)(HAL_GET_COMMON_IMAGE_PTR()), 0, sizeof(uint32_t)*COL_MAX*ROW_MAX);

			/*
			 * Frame skip every step.
			 */
			{
#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE)
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
#else /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
				for(framenum_2 = 0; framenum_2 < AUTO_CAL_AVERAGE_SKIP_FRAME_NUM; framenum_2++)
				{
					module_wait_full_sample_done();
				}
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
			}

			ulTestFrameNum = 0;
			for(framenum = 0; framenum < AUTO_CAL_AVERAGE_FRAME_NUM; framenum++)
			{
				ulTestFrameNum++;
#ifdef MODE_WDT
				KICK_DOG();
#endif /* MODE_WDT */
#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE)
			    while(YES)
			    {
					lDataIndex = module_wait_local_sample_done();

					if(lDataIndex == LOCAL_FINGER_LAST_LHB)
					{
						break;
					}
				}
#else /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
				module_wait_full_sample_done();
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
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

			for(r=DEF_ROIC_TUNE_ROW_GROUP_NUM; r--; )
			{
				for(c=MSPI_NUM; c--; )
				{
					for(g=DEF_ROIC_TUNE_COL_GROUP_NUM; g--; )
					{
						ulROIC_Reg_Idx = ucROIC_CRRegIdx[r];
						ulROIC_Reg_MUX_Idx = (r/3)%2;

						if(AutoCalfinish_R0[r][c][g] == 0)
						{
							usTemp_RawData = (uint16_t)(RawValue_sum_R0[r][c][g]/RawSumCnt_R0[r][c][g]);

							if(RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL < usTemp_RawData)
							{
								switch(g)
								{
									case 0:
									{
										if(ulROIC_Reg_MUX_Idx == 0)
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g1 += 1;
										}
										else
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g1 += 1;
										}
										break;
									}
									case 1:
									{
										if(ulROIC_Reg_MUX_Idx == 0)
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g2 += 1;
										}
										else
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g2 += 1;
										}
										break;
									}
									case 2:
									{
										if(ulROIC_Reg_MUX_Idx == 0)
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g3 += 1;
										}
										else
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g3 += 1;
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
											if(ulROIC_Reg_MUX_Idx == 0)
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g1 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g1 -= 1;
												}
											}
											else
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g1 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g1 -= 1;
												}
											}
											break;
										}
										case 1:
										{
											if(ulROIC_Reg_MUX_Idx == 0)
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g2 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g2 -= 1;
												}
											}
											else
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g2 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g2 -= 1;
												}
											}
											break;
										}
										case 2:
										{
											if(ulROIC_Reg_MUX_Idx == 0)
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g3 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g3 -= 1;
												}
											}
											else
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g3 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g3 -= 1;
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
										if(ulROIC_Reg_MUX_Idx == 0)
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g1 += 1;
										}
										else
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g1 += 1;
										}
										break;
									}
									case 1:
									{
										if(ulROIC_Reg_MUX_Idx == 0)
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g2 += 1;
										}
										else
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g2 += 1;
										}
										break;
									}
									case 2:
									{
										if(ulROIC_Reg_MUX_Idx == 0)
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g3 += 1;
										}
										else
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g3 += 1;
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
											if(ulROIC_Reg_MUX_Idx == 0)
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g1 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g1 -= 1;
												}
											}
											else
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g1 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g1 -= 1;
												}
											}
											break;
										}
										case 1:
										{
											if(ulROIC_Reg_MUX_Idx == 0)
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g2 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g2 -= 1;
												}
											}
											else
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g2 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g2 -= 1;
												}
											}
											break;
										}
										case 2:
										{
											if(ulROIC_Reg_MUX_Idx == 0)
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g3 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux1_g3 -= 1;
												}
											}
											else
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g3 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * MSPI_NUM)].tBit.cr_mux2_g3 -= 1;
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
			for(r=DEF_ROIC_TUNE_ROW_GROUP_NUM; r--; )
			{
				for(c=MSPI_NUM; c--; )
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
#define DEF_CR_VALUE_WRITE_COL_OFFSET			(18)
				bIsAutoCalFinish = YES;

				for(r=0; r<DEF_ROW_LOOF_NUM; r++)
				{
					ulReal_Col = 0;
//					ulROIC_Reg_Idx = ucROIC_CRRegIdx[r];

					for(c=0; c<MSPI_NUM; c++)
					{
						sPosTempDiff = g_pR0_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux1_g1;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3), ulReal_Col, sPosTempDiff);
						sPosTempDiff = g_pR1_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux1_g1;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3), ulReal_Col+DEF_CR_VALUE_WRITE_COL_OFFSET, sPosTempDiff);

						sPosTempDiff = g_pR0_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux2_g1;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3) + 3, ulReal_Col, sPosTempDiff);
						sPosTempDiff = g_pR1_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux2_g1;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3) + 3, ulReal_Col+DEF_CR_VALUE_WRITE_COL_OFFSET, sPosTempDiff);
						ulReal_Col++;

						sPosTempDiff = g_pR0_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux1_g2;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3), ulReal_Col, sPosTempDiff);
						sPosTempDiff = g_pR1_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux1_g2;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3), ulReal_Col+DEF_CR_VALUE_WRITE_COL_OFFSET, sPosTempDiff);

						sPosTempDiff = g_pR0_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux2_g2;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3) + 3, ulReal_Col, sPosTempDiff);
						sPosTempDiff = g_pR1_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux2_g2;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3) + 3, ulReal_Col+DEF_CR_VALUE_WRITE_COL_OFFSET, sPosTempDiff);
						ulReal_Col++;

						sPosTempDiff = g_pR0_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux1_g3;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3), ulReal_Col, sPosTempDiff);
						sPosTempDiff = g_pR1_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux1_g3;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3), ulReal_Col+DEF_CR_VALUE_WRITE_COL_OFFSET, sPosTempDiff);

						sPosTempDiff = g_pR0_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux2_g3;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3) + 3, ulReal_Col, sPosTempDiff);
						sPosTempDiff = g_pR1_CR_MUX_Tune[c + (r * MSPI_NUM)].tBit.cr_mux2_g3;
						HAL_WRITE_DELTA_IMAGE(r + ((r/3)*3) + 3, ulReal_Col+DEF_CR_VALUE_WRITE_COL_OFFSET, sPosTempDiff);
						ulReal_Col++;
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
#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE)
			    while(YES)
			    {
					lDataIndex = module_wait_local_sample_done();

					if(lDataIndex == LOCAL_OP_LAST_LHB)
					{
						break;
					}
				}
#else /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
				module_wait_full_sample_done();
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
			}
#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE)
		    while(YES)
		    {
				lDataIndex = module_wait_local_sample_done();

				if(lDataIndex == LOCAL_OP_LAST_LHB)
				{
					break;
				}
			}
#else /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
			module_wait_full_sample_done();
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
		}
#elif (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_MANUAL)
		if(Change_CR_Value)
		{
			Change_CR_Value = 0;
			HAL_SetROICRegSetChangeMode(ROIC_REG_SET_CHAGNE_CR_TUNE);
			module_wait_full_sample_done();
		}
#endif /* (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO) */

		{
			eProtocolMode_t eCurrentMode = protocol_swip_GetMode();
			if(eCurrentMode == M_TOUCH_DFUP || eCurrentMode == M_WATCH_DOG_RESET)
			{
				break;
			}
		}
	}
}
#endif /* USED_RAWDATA_TUNE_CALIBRATION */

void SW92512_SetDiagTestOperationMode(eDIAG_TEST_CHANGE_MODE_t TestMode)
{
	tSDIC_CFG_t tSDIC_CFG;
	tR0_TG_STUCK_t tR0_TG_STUCK;
	tR1_TG_STUCK_t tR1_TG_STUCK;
	tR0_MUX_CTL_t tR0_MUX_CTL;
	tR1_MUX_CTL_t tR1_MUX_CTL;
	tR0_CR_GTUNE_t tR0_CR_GTUNE;
	tR1_CR_GTUNE_t tR1_CR_GTUNE;
	tADC_CTL1_t tADC_CTL1;
	tR0_AFE_SENSE_CTL2_t tR0_AFE_SENSE_CTL2;
	tR1_AFE_SENSE_CTL2_t tR1_AFE_SENSE_CTL2;
#if 1
	switch(TestMode)
	{
		case DIAG_CHANGE_SHORT1_TEST_STEP1:
		{
			tR0_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->R0_TG_STUCK.ulBulk;
			tR0_TG_STUCK.tBit.r0_fig_stuck_vcr_en_odd = 0;
			tR0_TG_STUCK.tBit.r0_fig_stuck_vcr_en_even = 0;

			tR1_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->R1_TG_STUCK.ulBulk;
			tR1_TG_STUCK.tBit.r1_fig_stuck_vcr_en_odd = 0;
			tR1_TG_STUCK.tBit.r1_fig_stuck_vcr_en_even = 0;

			tR0_MUX_CTL.ulBulk = s_pktmoduleSRICCommonConf->R0_MUX_CTL.ulBulk;
			tR0_MUX_CTL.tBit.r0_mux_int_en = 1;

			tR1_MUX_CTL.ulBulk = s_pktmoduleSRICCommonConf->R1_MUX_CTL.ulBulk;
			tR1_MUX_CTL.tBit.r1_mux_int_en = 1;

			MSPI_RegisterWrite((uint32_t)(0x02AC), tR0_TG_STUCK.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x03AC), tR1_TG_STUCK.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0208), tR0_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0308), tR1_MUX_CTL.ulBulk);  // R/W
			break;
		}
		case DIAG_CHANGE_SHORT1_TEST_STEP2:
		{
			tR0_MUX_CTL.ulBulk = s_pktmoduleSRICCommonConf->R0_MUX_CTL.ulBulk;
			tR0_MUX_CTL.tBit.r0_mux_int_en = 2;

			tR1_MUX_CTL.ulBulk = s_pktmoduleSRICCommonConf->R1_MUX_CTL.ulBulk;
			tR1_MUX_CTL.tBit.r1_mux_int_en = 2;

			MSPI_RegisterWrite((uint32_t)(0x0208), tR0_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0308), tR1_MUX_CTL.ulBulk);  // R/W
			break;
		}
		case DIAG_CHANGE_SHORT1_TEST_STEP3:
		{
			tR0_MUX_CTL.ulBulk = s_pktmoduleSRICCommonConf->R0_MUX_CTL.ulBulk;
			tR0_MUX_CTL.tBit.r0_mux_int_en = 3;

			tR1_MUX_CTL.ulBulk = s_pktmoduleSRICCommonConf->R1_MUX_CTL.ulBulk;
			tR1_MUX_CTL.tBit.r1_mux_int_en = 3;

			MSPI_RegisterWrite((uint32_t)(0x0208), tR0_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0308), tR1_MUX_CTL.ulBulk);  // R/W
			break;
		}
		case DIAG_CHANGE_SHORT1_TEST_STEP4:
		{
			tR0_MUX_CTL.ulBulk = s_pktmoduleSRICCommonConf->R0_MUX_CTL.ulBulk;
			tR0_MUX_CTL.tBit.r0_mux_int_en = 4;

			tR1_MUX_CTL.ulBulk = s_pktmoduleSRICCommonConf->R1_MUX_CTL.ulBulk;
			tR1_MUX_CTL.tBit.r1_mux_int_en = 4;

			MSPI_RegisterWrite((uint32_t)(0x0208), tR0_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0308), tR1_MUX_CTL.ulBulk);  // R/W
			break;
		}
		case DIAG_CHANGE_SHORT1_TEST_STEP5:
		{
			tR0_MUX_CTL.ulBulk = s_pktmoduleSRICCommonConf->R0_MUX_CTL.ulBulk;
			tR0_MUX_CTL.tBit.r0_mux_int_en = 5;

			tR1_MUX_CTL.ulBulk = s_pktmoduleSRICCommonConf->R1_MUX_CTL.ulBulk;
			tR1_MUX_CTL.tBit.r1_mux_int_en = 5;

			MSPI_RegisterWrite((uint32_t)(0x0208), tR0_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0308), tR1_MUX_CTL.ulBulk);  // R/W
			break;
		}
		case DIAG_CHANGE_SHORT1_TEST_RECOVERY:
		{
			MSPI_RegisterWrite((uint32_t)(0x02AC), s_pktmoduleSRICCommonConf->R0_TG_STUCK.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x03AC), s_pktmoduleSRICCommonConf->R1_TG_STUCK.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0208), s_pktmoduleSRICCommonConf->R0_MUX_CTL.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0308), s_pktmoduleSRICCommonConf->R1_MUX_CTL.ulBulk);  // R/W
			break;
		}

		case DIAG_CHANGE_SHORT2_TEST_STEP1:	// 1st Frame
		{
			tR0_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->R0_TG_STUCK.ulBulk;
			tR0_TG_STUCK.tBit.r0_fig_stuck_vcr_en_odd = 0;
			tR0_TG_STUCK.tBit.r0_fig_stuck_vcr_en_even = 0;

			tR1_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->R1_TG_STUCK.ulBulk;
			tR1_TG_STUCK.tBit.r1_fig_stuck_vcr_en_odd = 0;
			tR1_TG_STUCK.tBit.r1_fig_stuck_vcr_en_even = 0;

			MSPI_RegisterWrite((uint32_t)(0x02AC), tR0_TG_STUCK.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x03AC), tR1_TG_STUCK.ulBulk);  // R/W
			break;
		}
		case DIAG_CHANGE_SHORT2_TEST_STEP2:	// 2nd Frame
		{
			tR0_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->R0_TG_STUCK.ulBulk;
			tR0_TG_STUCK.tBit.r0_fig_stuck_vcr_en_odd = 0;
			tR0_TG_STUCK.tBit.r0_fig_stuck_vcr_en_even = 1;

			tR1_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->R1_TG_STUCK.ulBulk;
			tR1_TG_STUCK.tBit.r1_fig_stuck_vcr_en_odd = 1;
			tR1_TG_STUCK.tBit.r1_fig_stuck_vcr_en_even = 0;

			tR0_CR_GTUNE.tBit.r0_top_fig_gtune = 7;
			tR0_CR_GTUNE.tBit.r0_mid_fig_gtune = 7;
			tR0_CR_GTUNE.tBit.r0_bot_fig_gtune = 7;

			tR1_CR_GTUNE.tBit.r1_top_fig_gtune = 7;
			tR1_CR_GTUNE.tBit.r1_mid_fig_gtune = 7;
			tR1_CR_GTUNE.tBit.r1_bot_fig_gtune = 7;

			tADC_CTL1.ulBulk = s_pktmoduleSRICCommonConf->ADC_CTL1.ulBulk;
			tADC_CTL1.tBit.fig_adc_clk_prd = 0;
			tADC_CTL1.tBit.fig_conv_smpl_num = 16;

			MSPI_RegisterWrite((uint32_t)(0x02AC), tR0_TG_STUCK.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x03AC), tR1_TG_STUCK.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0250), tR0_CR_GTUNE.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0350), tR1_CR_GTUNE.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x008C), tADC_CTL1.ulBulk);  // R/W
			break;
		}
		case DIAG_CHANGE_SHORT2_TEST_STEP3:	// 3rd Frame
		{
			tR0_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->R0_TG_STUCK.ulBulk;
			tR0_TG_STUCK.tBit.r0_fig_stuck_vcr_en_odd = 1;
			tR0_TG_STUCK.tBit.r0_fig_stuck_vcr_en_even = 0;

			tR1_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->R1_TG_STUCK.ulBulk;
			tR1_TG_STUCK.tBit.r1_fig_stuck_vcr_en_odd = 0;
			tR1_TG_STUCK.tBit.r1_fig_stuck_vcr_en_even = 1;

			MSPI_RegisterWrite((uint32_t)(0x02AC), tR0_TG_STUCK.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x03AC), tR1_TG_STUCK.ulBulk);  // R/W
			break;
		}
		case DIAG_CHANGE_SHORT2_TEST_RECOVERY:
		{
			MSPI_RegisterWrite((uint32_t)(0x02AC), s_pktmoduleSRICCommonConf->R0_TG_STUCK.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x03AC), s_pktmoduleSRICCommonConf->R1_TG_STUCK.ulBulk);  // R/W
			MSPI_RegisterMultiWrite((uint32_t)(0x0250), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);  // R/W
			MSPI_RegisterMultiWrite((uint32_t)(0x0350), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x008C), s_pktmoduleSRICCommonConf->ADC_CTL1.ulBulk);  // R/W
			break;
		}
			
		case DIAG_CHANGE_OPEN_TEST_STEP1:
		{
			tSDIC_CFG.ulBulk = s_pktmoduleSRICCommonConf->SDIC_CFG.ulBulk;
			tSDIC_CFG.tBit.sd_float_en = 1;
			tSDIC_CFG.tBit.sd_float_ctl = 1;
			tSDIC_CFG.tBit.sd_gnd_en = 1;
			tSDIC_CFG.tBit.sd_gnd_ctl = 1;

			tR0_CR_GTUNE.tBit.r0_top_fig_gtune = 7;
			tR0_CR_GTUNE.tBit.r0_mid_fig_gtune = 7;
			tR0_CR_GTUNE.tBit.r0_bot_fig_gtune = 7;

			tR1_CR_GTUNE.tBit.r1_top_fig_gtune = 7;
			tR1_CR_GTUNE.tBit.r1_mid_fig_gtune = 7;
			tR1_CR_GTUNE.tBit.r1_bot_fig_gtune = 7;

			tR0_AFE_SENSE_CTL2.ulBulk = s_pktmoduleSRICCommonConf->R0_AFE_SENSE_CTL2.ulBulk;
			tR0_AFE_SENSE_CTL2.tBit.r0_fig_pre_gc = 7;
			tR0_AFE_SENSE_CTL2.tBit.r0_fig_int_gc = 3;
			tR0_AFE_SENSE_CTL2.tBit.r0_fig_int_half = 1;

			tR1_AFE_SENSE_CTL2.ulBulk = s_pktmoduleSRICCommonConf->R1_AFE_SENSE_CTL2.ulBulk;
			tR1_AFE_SENSE_CTL2.tBit.r1_fig_pre_gc = 7;
			tR1_AFE_SENSE_CTL2.tBit.r1_fig_int_gc = 3;
			tR1_AFE_SENSE_CTL2.tBit.r1_fig_int_half = 1;

			MSPI_RegisterWrite((uint32_t)(0x0030), tSDIC_CFG.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0250), tR0_CR_GTUNE.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x0350), tR1_CR_GTUNE.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x029C), tR0_AFE_SENSE_CTL2.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x039C), tR1_AFE_SENSE_CTL2.ulBulk);  // R/W
			break;
		}
		case DIAG_CHANGE_OPEN_TEST_RECOVERY:
		{
			MSPI_RegisterWrite((uint32_t)(0x0030), s_pktmoduleSRICCommonConf->SDIC_CFG.ulBulk);  // R/W
			MSPI_RegisterMultiWrite((uint32_t)(0x0250), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);  // R/W
			MSPI_RegisterMultiWrite((uint32_t)(0x0350), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x029C), s_pktmoduleSRICCommonConf->R0_AFE_SENSE_CTL2.ulBulk);  // R/W
			MSPI_RegisterWrite((uint32_t)(0x039C), s_pktmoduleSRICCommonConf->R1_AFE_SENSE_CTL2.ulBulk);  // R/W
			break;
		}
		default:
			break;
	}
#endif
}


#endif /* (USED_ROIC_DEF == ROIC_SW92512) */
