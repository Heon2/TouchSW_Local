/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : param_configset_roic.h
 * created on : 3. 4. 2019
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

#ifndef _PARAM_CONFIGSET_ROIC_H_
#define _PARAM_CONFIGSET_ROIC_H_


/************************************************************************************************************/
/*											WGP ROIC Setting												*/
/************************************************************************************************************/
#if USE_PWM_86KHZ
	#define PARAMSET_ROIC_PWM_CTL_pwm_pdrv_num				(4)//(7) // (N+1)
	#define PARAMSET_ROIC_PWM_CTL_pwm_act_num				(8)//(7) // (N+1)
	#define PARAMSET_ROIC_PWM_CTL_pwm_smpl_num				(8)//(7) // (N+1)
	#define PARAMSET_ROIC_PWM_CTL_pwm_dum_num				(0)
	#define PARAMSET_ROIC_PWM_CTL_pdrv_dum_num				(0)
	#define PARAMSET_ROIC_PWM_CTL_pwm_set_num				(0)

	#define PARAMSET_ROIC_PWM_POS_CTL_pwm_pdrv_num			(4)//(7) // (N+1)
	#define PARAMSET_ROIC_PWM_POS_CTL_pwm_act_num			(12)//(10) // (N+1)
	#define PARAMSET_ROIC_PWM_POS_CTL_pwm_smpl_num			(12)//(10) // (N+1)
	#define PARAMSET_ROIC_PWM_POS_CTL_pwm_dum_num			(0)
	#define PARAMSET_ROIC_PWM_POS_CTL_pdrv_dum_num			(0)
	#define PARAMSET_ROIC_PWM_POS_CTL_pwm_set_num			(0)
#else
	#define PARAMSET_ROIC_PWM_CTL_pwm_pdrv_num				(9) // (N+1)
	#define PARAMSET_ROIC_PWM_CTL_pwm_act_num				(9) // (N+1)
	#define PARAMSET_ROIC_PWM_CTL_pwm_smpl_num				(9) // (N+1)
	#define PARAMSET_ROIC_PWM_CTL_pwm_dum_num				(0)
	#define PARAMSET_ROIC_PWM_CTL_pdrv_dum_num				(0)
	#define PARAMSET_ROIC_PWM_CTL_pwm_set_num				(0)

	#define PARAMSET_ROIC_PWM_POS_CTL_pwm_pdrv_num			(9) // (N+1)
	#define PARAMSET_ROIC_PWM_POS_CTL_pwm_act_num			(14) // (N+1)
	#define PARAMSET_ROIC_PWM_POS_CTL_pwm_smpl_num			(14) // (N+1)
	#define PARAMSET_ROIC_PWM_POS_CTL_pwm_dum_num			(0)
	#define PARAMSET_ROIC_PWM_POS_CTL_pdrv_dum_num			(0)
	#define PARAMSET_ROIC_PWM_POS_CTL_pwm_set_num			(0)
#endif

#if USE_PWM_142KHZ
	#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
		#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_pdrv_num		(5) // (N+1)
	#else
		#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_pdrv_num		(11) // (N+1)
	#endif
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_act_num			(5) // (N+1)
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_smpl_num			(5) // (N+1)
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_dum_num			(0)
#define PARAMSET_ROIC_PWM_DAT_CTL_pdrv_dum_num			(0)
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_set_num			(0)
#elif USE_PWM_86KHZ
	#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
		#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_pdrv_num		(1)//(3) // (N+1)
	#else
		#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_pdrv_num		(5)//(7)
	#endif
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_act_num				(3) // (N+1)
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_smpl_num				(3) // (N+1)
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_dum_num				(0)
#define PARAMSET_ROIC_PWM_DAT_CTL_pdrv_dum_num				(0)
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_set_num				(0)
#else
	#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
		#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_pdrv_num		(4) // (N+1)
	#else
		#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_pdrv_num		(9) // (N+1)
	#endif
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_act_num				(4) // (N+1)
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_smpl_num				(4) // (N+1)
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_dum_num				(0)
#define PARAMSET_ROIC_PWM_DAT_CTL_pdrv_dum_num				(0)
#define PARAMSET_ROIC_PWM_DAT_CTL_pwm_set_num				(0)
#endif

#define PARAMSET_ROIC_PWM_IDLE_CTL_pwm_pdrv_num				(5) // (N+1)
#define PARAMSET_ROIC_PWM_IDLE_CTL_pwm_act_num				(7)//(5) // (N+1)
#define PARAMSET_ROIC_PWM_IDLE_CTL_pwm_smpl_num				(7)//(5) // (N+1)
#define PARAMSET_ROIC_PWM_IDLE_CTL_pwm_dum_num				(0)
#define PARAMSET_ROIC_PWM_IDLE_CTL_pdrv_dum_num				(0)
#define PARAMSET_ROIC_PWM_IDLE_CTL_pwm_set_num				(0)

#define PARAMSET_ROIC_PWM_IDLE_POS_CTL_pwm_pdrv_num			(PARAMSET_ROIC_PWM_IDLE_CTL_pwm_pdrv_num) // (N+1)
#if USED_LOCAL_PEN_HOVER_IDLE_TO_ACTIVE
	#define PARAMSET_ROIC_PWM_IDLE_POS_CTL_pwm_act_num			(14) // (N+1)
	#define PARAMSET_ROIC_PWM_IDLE_POS_CTL_pwm_smpl_num			(14) // (N+1)
#else
	#define PARAMSET_ROIC_PWM_IDLE_POS_CTL_pwm_act_num			(7)//(10) // (N+1)
	#define PARAMSET_ROIC_PWM_IDLE_POS_CTL_pwm_smpl_num			(7)//(10) // (N+1)
#endif
#define PARAMSET_ROIC_PWM_IDLE_POS_CTL_pwm_dum_num			(0)
#define PARAMSET_ROIC_PWM_IDLE_POS_CTL_pdrv_dum_num			(0)
#define PARAMSET_ROIC_PWM_IDLE_POS_CTL_pwm_set_num			(0)

#define PARAMSET_ROIC_PWM_HOPPFRQ_CTL_pwm_pdrv_num			(4) // (N+1)
#define PARAMSET_ROIC_PWM_HOPPFRQ_CTL_pwm_act_num			(8) // (N+1)
#define PARAMSET_ROIC_PWM_HOPPFRQ_CTL_pwm_smpl_num			(8) // (N+1)
#define PARAMSET_ROIC_PWM_HOPPFRQ_CTL_pwm_dum_num			(0)
#define PARAMSET_ROIC_PWM_HOPPFRQ_CTL_pdrv_dum_num			(0)
#define PARAMSET_ROIC_PWM_HOPPFRQ_CTL_pwm_set_num			(0)

#define PARAMSET_ROIC_PWM_POS_HOPPFRQ_CTL_pwm_pdrv_num		(4) // (N+1)
#define PARAMSET_ROIC_PWM_POS_HOPPFRQ_CTL_pwm_act_num		(12) // (N+1)
#define PARAMSET_ROIC_PWM_POS_HOPPFRQ_CTL_pwm_smpl_num		(12) // (N+1)
#define PARAMSET_ROIC_PWM_POS_HOPPFRQ_CTL_pwm_dum_num		(0)
#define PARAMSET_ROIC_PWM_POS_HOPPFRQ_CTL_pdrv_dum_num		(0)
#define PARAMSET_ROIC_PWM_POS_HOPPFRQ_CTL_pwm_set_num		(0)

#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
	#define PARAMSET_ROIC_PWM_DAT_HOPPFRQ_CTL_pwm_pdrv_num		(1) // (N+1)
#else
	#define PARAMSET_ROIC_PWM_DAT_HOPPFRQ_CTL_pwm_pdrv_num		(5) // (N+1)
#endif
#define PARAMSET_ROIC_PWM_DAT_HOPPFRQ_CTL_pwm_act_num		(3) // (N+1)
#define PARAMSET_ROIC_PWM_DAT_HOPPFRQ_CTL_pwm_smpl_num		(3) // (N+1)
#define PARAMSET_ROIC_PWM_DAT_HOPPFRQ_CTL_pwm_dum_num		(0)
#define PARAMSET_ROIC_PWM_DAT_HOPPFRQ_CTL_pdrv_dum_num		(0)
#define PARAMSET_ROIC_PWM_DAT_HOPPFRQ_CTL_pwm_set_num		(0)

#define PARAMSET_ROIC_ND_CTRL_nd_dum_dly				(48)

#if USE_PWM_142KHZ
	#define PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd1				(36)	//	Change
	#define PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd2				(36)	//	Change

	#define PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd_1			(7)//(3)		//	Change
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd_2			(7)//(3)		//	Change
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_crrpt_num			(0)

	#define PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num1			(15)
	#define PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num2			(3)

	#define PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num1			(23)//(24)	//	Change
	#define PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num2			(17)//(18)

	#define PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_1		(34)//(32)	//	Change
	#define PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_2		(34)//(32)	//	Change

	#define PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_1		(25)//(27)	//	Change
	#define PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_2		(25)//(27)	//	Change

	#define PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_1			(32)//(30)	//	Change
	#define PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_2			(32)//(30)	//	Change

	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_1	(33)
	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_2	(33)

	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_1	(12)
	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_2	(12)

	#define PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_1		(16)
	#define PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_2		(16)

	#define PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_1		(16)	//	Change
	#define PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_2		(16)	//	Change

	#define PARAMSET_ROIC_CFGR_PHTH_NUM2_phth0_num2			(2)
	#define PARAMSET_ROIC_CFGR_PHTH_NUM2_phth1_num2			(24)//(26)	//	Change
#elif USE_PWM_86KHZ	//	86KHz

	#define PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd1				(64)//(66)
	#define PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd2				(64)//(66)

	#define PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd_1			(10)
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd_2			(10)
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_crrpt_num			(0)

	#define PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num1			(20)//(15)
	#define PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num2			(3)

	#define PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num1			(36)//(28)
	#define PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num2			(24)//(18)

	#define PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_1		(58)//(60)
	#define PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_2		(58)//(60)

	#define PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_1		(40)
	#define PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_2		(40)

	#define PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_1			(50)//(55)
	#define PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_2			(50)//(55)

	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_1	(50)//this setting not applied due to stuck_vcr_odd_en = stuck_vcr_even_en = 3
	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_2	(50)//this setting not applied due to stuck_vcr_odd_en = stuck_vcr_even_en = 3

	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_1	(50)//this setting not applied due to stuck_vcr_odd_en = stuck_vcr_even_en = 3
	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_2	(50)//this setting not applied due to stuck_vcr_odd_en = stuck_vcr_even_en = 3

	#define PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_1		(22)//(16)
	#define PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_2		(22)//(16)

	#define PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_1		(22)//(16)
	#define PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_2		(22)//(16)

	#define PARAMSET_ROIC_CFGR_PHTH_NUM2_phth0_num2			(2)
	#define PARAMSET_ROIC_CFGR_PHTH_NUM2_phth1_num2			(38)//(40)

#else	//	114KHz
	#define PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd1				(48)
	#define PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd2				(48)

	#define PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd_1			(7)
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd_2			(7)
	#define PARAMSET_ROIC_CFGR_SMPL_CTL_crrpt_num			(0)

	#define PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num1			(15)
	#define PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num2			(3)

	#define PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num1			(23)
	#define PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num2			(18)

	#define PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_1		(44)
	#define PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_2		(44)

	#define PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_1		(30)
	#define PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_2		(30)

	#define PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_1			(40)//(40) /* Pen/Finger */
	#define PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_2			(40) /* Noise */

	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_1	(33)
	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_2	(33)

	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_1	(12)
	#define PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_2	(12)

	#define PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_1		(16)
	#define PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_2		(16)

	#define PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_1		(15)
	#define PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_2		(15)

	#define PARAMSET_ROIC_CFGR_PHTH_NUM2_phth0_num2			(2)
	#define PARAMSET_ROIC_CFGR_PHTH_NUM2_phth1_num2			(30)
#endif

//#else // 86KHz
#define PARAMSET_ROIC_HOPPFRQ_CFGR_PWM_PRD_pwm_prd1				(64)//(66)
#define PARAMSET_ROIC_HOPPFRQ_CFGR_PWM_PRD_pwm_prd2				(64)//(66)

#define PARAMSET_ROIC_HOPPFRQ_CFGR_SMPL_CTL_smop_prd_1			(10)
#define PARAMSET_ROIC_HOPPFRQ_CFGR_SMPL_CTL_smop_prd_2			(10)
#define PARAMSET_ROIC_HOPPFRQ_CFGR_SMPL_CTL_crrpt_num			(0)

#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTP_NUM1_rstp_num1			(20)//(15)
#define PARAMSET_ROIC_HOPPFRQ_CFGR_RSTP_NUM1_rstp_num2			(3)

#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHT_NUM1_pht_num1			(36)//(28)
#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHT_NUM1_pht_num2			(24)//(18)

#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_NUM1_phtcr_num1_1		(58)//(60)
#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_NUM1_phtcr_num1_2		(58)//(60)

#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_NUM2_phtcr_num2_1		(40)
#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTCR_NUM2_phtcr_num2_2		(40)

#define PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_NUM1_vcr_num1_1			(50)//(55)
#define PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_NUM1_vcr_num1_2			(50)//(55)

#define PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_EN_NUM1_vcr_en_num1_1	(50)//this setting not applied due to stuck_vcr_odd_en = stuck_vcr_even_en = 3
#define PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_EN_NUM1_vcr_en_num1_2	(50)//this setting not applied due to stuck_vcr_odd_en = stuck_vcr_even_en = 3

#define PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_EN_NUM2_vcr_en_num2_1	(50)//this setting not applied due to stuck_vcr_odd_en = stuck_vcr_even_en = 3
#define PARAMSET_ROIC_HOPPFRQ_CFGR_VCR_EN_NUM2_vcr_en_num2_2	(50)//this setting not applied due to stuck_vcr_odd_en = stuck_vcr_even_en = 3

#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH0_NUM1_phth0_num1_1		(22)//(16)
#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH0_NUM1_phth0_num1_2		(22)//(16)

#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH1_NUM1_phth1_num1_1		(22)//(16)
#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH1_NUM1_phth1_num1_2		(22)//(16)

#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH_NUM2_phth0_num2			(2)
#define PARAMSET_ROIC_HOPPFRQ_CFGR_PHTH_NUM2_phth1_num2			(38)//(40)


#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_prd				(2)
#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_opt_smpl			(0)
#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_opt_inv			(1)
#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_etime			(16)

#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_op_opt			(0)
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_opt			(2)
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_pol			(0)
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_prd			(1)
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_num			(7)
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_in_pos			(5)
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_stc_dly			(31)
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_spt			(0)
#define PARAMSET_ROIC_CFGR_ADC_CTRL_cfgr_tm_adc			(0)

#define PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_finger			(1023)
#define PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_pos		(3)
#define PARAMSET_ROIC_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_dat		(1)

/* ---------------------- WGP LHB Setting ---------------------------------------- */
	#define PARAMSET_ROIC_FULL_LHB_1_mode					(SW92503S_MODE_BEACON)
	#define PARAMSET_ROIC_FULL_LHB_1_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_1_pre_drv				(0)
	#define PARAMSET_ROIC_FULL_LHB_1_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_1_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_1_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_1_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_FULL_LHB_1_local_pos0				(0)
	#define PARAMSET_ROIC_FULL_LHB_1_local_pos1				(0)
	#define PARAMSET_ROIC_FULL_LHB_1_local_pos2				(0)
	#define PARAMSET_ROIC_FULL_LHB_1_local_pos3				(0)

	#define PARAMSET_ROIC_FULL_LHB_2_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_2_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_2_pre_drv				(0)
	#define PARAMSET_ROIC_FULL_LHB_2_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_2_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_2_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_2_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_FULL_LHB_2_local_pos0				(0)
	#define PARAMSET_ROIC_FULL_LHB_2_local_pos1				(0)
	#define PARAMSET_ROIC_FULL_LHB_2_local_pos2				(0)
	#define PARAMSET_ROIC_FULL_LHB_2_local_pos3				(0)

	#define PARAMSET_ROIC_FULL_LHB_3_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_3_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_3_pre_drv				(0)
	#define PARAMSET_ROIC_FULL_LHB_3_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_3_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_3_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_3_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_FULL_LHB_3_local_pos0				(0)
	#define PARAMSET_ROIC_FULL_LHB_3_local_pos1				(0)
	#define PARAMSET_ROIC_FULL_LHB_3_local_pos2				(0)
	#define PARAMSET_ROIC_FULL_LHB_3_local_pos3				(0)

	#define PARAMSET_ROIC_FULL_LHB_4_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_4_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_4_pre_drv				(0)
	#define PARAMSET_ROIC_FULL_LHB_4_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_4_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_4_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_4_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_FULL_LHB_4_local_pos0				(0)
	#define PARAMSET_ROIC_FULL_LHB_4_local_pos1				(0)
	#define PARAMSET_ROIC_FULL_LHB_4_local_pos2				(0)
	#define PARAMSET_ROIC_FULL_LHB_4_local_pos3				(0)

	#define PARAMSET_ROIC_FULL_LHB_5_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_5_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_5_pre_drv				(0)
	#define PARAMSET_ROIC_FULL_LHB_5_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_5_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_5_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_5_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_FULL_LHB_5_local_pos0				(0)
	#define PARAMSET_ROIC_FULL_LHB_5_local_pos1				(0)
	#define PARAMSET_ROIC_FULL_LHB_5_local_pos2				(0)
	#define PARAMSET_ROIC_FULL_LHB_5_local_pos3				(0)

	#define PARAMSET_ROIC_FULL_LHB_6_mode					(SW92503S_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_6_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_6_pre_drv				(1)
	#define PARAMSET_ROIC_FULL_LHB_6_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_6_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_6_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_6_lhb_mux_cnt			(2)
	#define PARAMSET_ROIC_FULL_LHB_6_local_pos0				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_1Mux)
	#define PARAMSET_ROIC_FULL_LHB_6_local_pos1				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_2Mux)
	#define PARAMSET_ROIC_FULL_LHB_6_local_pos2				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_3Mux)
	#define PARAMSET_ROIC_FULL_LHB_6_local_pos3				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_4Mux)

	#define PARAMSET_ROIC_FULL_LHB_7_mode					(SW92503S_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_7_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_7_pre_drv				(1)
	#define PARAMSET_ROIC_FULL_LHB_7_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_7_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_7_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_7_lhb_mux_cnt			(2)
	#define PARAMSET_ROIC_FULL_LHB_7_local_pos0				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_1Mux)
	#define PARAMSET_ROIC_FULL_LHB_7_local_pos1				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_2Mux)
	#define PARAMSET_ROIC_FULL_LHB_7_local_pos2				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_3Mux)
	#define PARAMSET_ROIC_FULL_LHB_7_local_pos3				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_4Mux)

	#define PARAMSET_ROIC_FULL_LHB_8_mode					(SW92503S_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_8_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_8_pre_drv				(1)
	#define PARAMSET_ROIC_FULL_LHB_8_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_8_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_8_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_8_lhb_mux_cnt			(2)
	#define PARAMSET_ROIC_FULL_LHB_8_local_pos0				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_1Mux)
	#define PARAMSET_ROIC_FULL_LHB_8_local_pos1				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_2Mux)
	#define PARAMSET_ROIC_FULL_LHB_8_local_pos2				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_3Mux)
	#define PARAMSET_ROIC_FULL_LHB_8_local_pos3				(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_4Mux)

	#define PARAMSET_ROIC_FULL_LHB_9_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_9_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_9_pre_drv				(0)
	#define PARAMSET_ROIC_FULL_LHB_9_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_9_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_9_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_9_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_FULL_LHB_9_local_pos0				(0)
	#define PARAMSET_ROIC_FULL_LHB_9_local_pos1				(0)
	#define PARAMSET_ROIC_FULL_LHB_9_local_pos2				(0)
	#define PARAMSET_ROIC_FULL_LHB_9_local_pos3				(0)

	#define PARAMSET_ROIC_FULL_LHB_10_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_10_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_10_pre_drv				(0)
	#define PARAMSET_ROIC_FULL_LHB_10_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_10_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_10_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_10_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_FULL_LHB_10_local_pos0			(0)
	#define PARAMSET_ROIC_FULL_LHB_10_local_pos1			(0)
	#define PARAMSET_ROIC_FULL_LHB_10_local_pos2			(0)
	#define PARAMSET_ROIC_FULL_LHB_10_local_pos3			(0)

	#define PARAMSET_ROIC_FULL_LHB_11_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_11_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_11_pre_drv				(0)
	#define PARAMSET_ROIC_FULL_LHB_11_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_11_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_11_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_11_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_FULL_LHB_11_local_pos0			(0)
	#define PARAMSET_ROIC_FULL_LHB_11_local_pos1			(0)
	#define PARAMSET_ROIC_FULL_LHB_11_local_pos2			(0)
	#define PARAMSET_ROIC_FULL_LHB_11_local_pos3			(0)

	#define PARAMSET_ROIC_FULL_LHB_12_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_12_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_12_pre_drv				(0)
	#define PARAMSET_ROIC_FULL_LHB_12_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_12_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_12_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_12_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_FULL_LHB_12_local_pos0			(0)
	#define PARAMSET_ROIC_FULL_LHB_12_local_pos1			(0)
	#define PARAMSET_ROIC_FULL_LHB_12_local_pos2			(0)
	#define PARAMSET_ROIC_FULL_LHB_12_local_pos3			(0)

	#define PARAMSET_ROIC_FULL_LHB_13_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_FULL_LHB_13_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_13_pre_drv				(0)
	#define PARAMSET_ROIC_FULL_LHB_13_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_13_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_13_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_13_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_FULL_LHB_13_local_pos0			(0)
	#define PARAMSET_ROIC_FULL_LHB_13_local_pos1			(0)
	#define PARAMSET_ROIC_FULL_LHB_13_local_pos2			(0)
	#define PARAMSET_ROIC_FULL_LHB_13_local_pos3			(0)

	#define PARAMSET_ROIC_FULL_LHB_14_mode					(SW92503S_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_14_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_14_pre_drv				(1)
	#define PARAMSET_ROIC_FULL_LHB_14_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_14_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_14_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_14_lhb_mux_cnt			(2)
	#define PARAMSET_ROIC_FULL_LHB_14_local_pos0			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_1Mux)
	#define PARAMSET_ROIC_FULL_LHB_14_local_pos1			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_2Mux)
	#define PARAMSET_ROIC_FULL_LHB_14_local_pos2			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_3Mux)
	#define PARAMSET_ROIC_FULL_LHB_14_local_pos3			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_4Mux)

	#define PARAMSET_ROIC_FULL_LHB_15_mode					(SW92503S_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_15_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_15_pre_drv				(1)
	#define PARAMSET_ROIC_FULL_LHB_15_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_15_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_15_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_15_lhb_mux_cnt			(2)
	#define PARAMSET_ROIC_FULL_LHB_15_local_pos0			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_1Mux)
	#define PARAMSET_ROIC_FULL_LHB_15_local_pos1			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_2Mux)
	#define PARAMSET_ROIC_FULL_LHB_15_local_pos2			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_3Mux)
	#define PARAMSET_ROIC_FULL_LHB_15_local_pos3			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_4Mux)

	#define PARAMSET_ROIC_FULL_LHB_16_mode					(SW92503S_MODE_FINGER)
	#define PARAMSET_ROIC_FULL_LHB_16_ping_en				(0)
	#define PARAMSET_ROIC_FULL_LHB_16_pre_drv				(1)
	#define PARAMSET_ROIC_FULL_LHB_16_pre_drvs_en			(0)
	#define PARAMSET_ROIC_FULL_LHB_16_extmuxcmd				(0)
	#define PARAMSET_ROIC_FULL_LHB_16_mux_type				(0)
	#define PARAMSET_ROIC_FULL_LHB_16_lhb_mux_cnt			(2)
	#define PARAMSET_ROIC_FULL_LHB_16_local_pos0			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_1Mux)
	#define PARAMSET_ROIC_FULL_LHB_16_local_pos1			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_2Mux)
	#define PARAMSET_ROIC_FULL_LHB_16_local_pos2			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_3Mux)
	#define PARAMSET_ROIC_FULL_LHB_16_local_pos3			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_4Mux)

	#if USED_IDLE_FINGER_EVEN_ODD
		#define PARAMSET_ROIC_LHB_MUX_CTRL_m1_mode_sel			(1)
	#else
		#define PARAMSET_ROIC_LHB_MUX_CTRL_m1_mode_sel			(0)
	#endif
	#define PARAMSET_ROIC_LHB_MUX_CTRL_pd_mux_num			(0)
	#define PARAMSET_ROIC_LHB_MUX_CTRL_mux_m1_bit_en		(0x3FF)
	#define PARAMSET_ROIC_LHB_MUX_CTRL_mux_nd_bit_en		(0)
	#define PARAMSET_ROIC_LHB_MUX_CTRL_max_lhb_cnt			(15)
	#define PARAMSET_ROIC_LHB_MUX_CTRL_ping_mux_type		(0)
	#define PARAMSET_ROIC_LHB_MUX_CTRL_ping_mux_local_sel	(0)

	#define PARAMSET_ROIC_PEN_MUX_BIT_EN_mux_beacon_bit_en		(0)
	#define PARAMSET_ROIC_PEN_MUX_BIT_EN_mux_pen_pos_bit_en		(1) // Mux Short Control Register
	#define PARAMSET_ROIC_PEN_MUX_BIT_EN_mux_pen_dat_bit_en		(1)

	#define PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_beacon_bit_en			(0)
	#define PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_pen_pos_bit_en		(0x3FF) // Mux Short Control Register
	#define PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_pen_dat_bit_en		(0x3FF)

	#define PARAMSET_ROIC_LOCAL_LHB_1_mode					(SW92503S_MODE_BEACON)
	#define PARAMSET_ROIC_LOCAL_LHB_1_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_1_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_1_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_1_extmuxcmd				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_1_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_1_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_1_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_1_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_1_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_1_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_2_mode					(SW92503S_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_LHB_2_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_2_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_2_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_2_extmuxcmd				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_2_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_2_lhb_mux_cnt			(1)
	#define PARAMSET_ROIC_LOCAL_LHB_2_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_2_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_2_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_2_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_3_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_3_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_3_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_3_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_3_extmuxcmd				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_3_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_3_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_3_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_3_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_3_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_3_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_4_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_LHB_4_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_4_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_4_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_4_extmuxcmd				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_4_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_4_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_4_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_4_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_4_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_4_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_5_mode					(SW92503S_MODE_PEN_TILT)
	#define PARAMSET_ROIC_LOCAL_LHB_5_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_5_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_5_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_5_extmuxcmd				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_5_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_5_lhb_mux_cnt			(1)
	#define PARAMSET_ROIC_LOCAL_LHB_5_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_5_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_5_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_5_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_6_mode					(SW92503S_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_LHB_6_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_6_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_6_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_6_extmuxcmd				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_6_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_6_lhb_mux_cnt			(1)
	#define PARAMSET_ROIC_LOCAL_LHB_6_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_6_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_6_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_6_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_7_mode					(SW92503S_MODE_PEN_DATA)
	#define PARAMSET_ROIC_LOCAL_LHB_7_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_7_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_7_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_7_extmuxcmd				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_7_mux_type				(0)
	#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
		#define PARAMSET_ROIC_LOCAL_LHB_7_lhb_mux_cnt			(7)
	#else
		#define PARAMSET_ROIC_LOCAL_LHB_7_lhb_mux_cnt			(6)
	#endif
	#define PARAMSET_ROIC_LOCAL_LHB_7_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_7_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_7_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_7_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_8_mode					(SW92503S_MODE_PEN_DATA)
	#define PARAMSET_ROIC_LOCAL_LHB_8_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_8_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_8_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_8_extmuxcmd				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_8_mux_type				(0)
	#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
		#define PARAMSET_ROIC_LOCAL_LHB_8_lhb_mux_cnt			(7)
	#else
		#define PARAMSET_ROIC_LOCAL_LHB_8_lhb_mux_cnt			(6)
	#endif
	#define PARAMSET_ROIC_LOCAL_LHB_8_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_8_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_8_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_8_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_9_mode					(SW92503S_MODE_FINGER)
	#define PARAMSET_ROIC_LOCAL_LHB_9_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_9_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_9_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_9_extmuxcmd				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_9_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_9_lhb_mux_cnt			(2)
	#define PARAMSET_ROIC_LOCAL_LHB_9_local_pos0			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_1Mux)
	#define PARAMSET_ROIC_LOCAL_LHB_9_local_pos1			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_2Mux)
	#define PARAMSET_ROIC_LOCAL_LHB_9_local_pos2			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_3Mux)
	#define PARAMSET_ROIC_LOCAL_LHB_9_local_pos3			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_4Mux)

	#define PARAMSET_ROIC_LOCAL_LHB_10_mode					(SW92503S_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_LHB_10_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_10_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_10_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_10_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_10_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_10_lhb_mux_cnt			(1)
	#define PARAMSET_ROIC_LOCAL_LHB_10_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_10_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_10_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_10_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_11_mode					(SW92503S_MODE_FINGER)
	#define PARAMSET_ROIC_LOCAL_LHB_11_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_11_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_11_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_11_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_11_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_11_lhb_mux_cnt			(2)
	#define PARAMSET_ROIC_LOCAL_LHB_11_local_pos0			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_1Mux)
	#define PARAMSET_ROIC_LOCAL_LHB_11_local_pos1			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_2Mux)
	#define PARAMSET_ROIC_LOCAL_LHB_11_local_pos2			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_3Mux)
	#define PARAMSET_ROIC_LOCAL_LHB_11_local_pos3			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_4Mux)

	#define PARAMSET_ROIC_LOCAL_LHB_12_mode					(SW92503S_MODE_FINGER)
	#define PARAMSET_ROIC_LOCAL_LHB_12_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_12_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_12_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_12_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_12_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_12_lhb_mux_cnt			(2)
	#define PARAMSET_ROIC_LOCAL_LHB_12_local_pos0			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_1Mux)
	#define PARAMSET_ROIC_LOCAL_LHB_12_local_pos1			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_2Mux)
	#define PARAMSET_ROIC_LOCAL_LHB_12_local_pos2			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_3Mux)
	#define PARAMSET_ROIC_LOCAL_LHB_12_local_pos3			(PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_4Mux)

	#define PARAMSET_ROIC_LOCAL_LHB_13_mode					(SW92503S_MODE_PEN_TILT)
	#define PARAMSET_ROIC_LOCAL_LHB_13_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_13_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_13_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_13_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_13_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_13_lhb_mux_cnt			(1)
	#define PARAMSET_ROIC_LOCAL_LHB_13_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_13_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_13_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_13_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_14_mode					(SW92503S_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_LHB_14_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_14_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_14_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_14_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_14_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_14_lhb_mux_cnt			(1)
	#define PARAMSET_ROIC_LOCAL_LHB_14_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_14_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_14_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_14_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_15_mode					(SW92503S_MODE_PEN_DATA)
	#define PARAMSET_ROIC_LOCAL_LHB_15_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_15_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_15_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_15_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_15_mux_type				(0)
	#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
		#define PARAMSET_ROIC_LOCAL_LHB_15_lhb_mux_cnt			(7)
	#else
		#define PARAMSET_ROIC_LOCAL_LHB_15_lhb_mux_cnt			(6)
	#endif
	#define PARAMSET_ROIC_LOCAL_LHB_15_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_15_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_15_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_15_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_LHB_16_mode					(SW92503S_MODE_PEN_DATA)
	#define PARAMSET_ROIC_LOCAL_LHB_16_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_LHB_16_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_LHB_16_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_16_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_16_mux_type				(0)
	#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
		#define PARAMSET_ROIC_LOCAL_LHB_16_lhb_mux_cnt			(7)
	#else
		#define PARAMSET_ROIC_LOCAL_LHB_16_lhb_mux_cnt			(6)
	#endif
	#define PARAMSET_ROIC_LOCAL_LHB_16_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_16_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_16_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_LHB_16_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mode					(SW92503S_MODE_BEACON)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_1_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_2_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_3_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_4_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_5_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_6_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_7_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_8_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mode					(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_mux_type				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_9_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mode				(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_mux_type			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_10_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mode				(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_mux_type			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_11_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mode				(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_mux_type			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_12_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mode				(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_mux_type			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_13_local_pos3			(0)

#if USED_FAST_SWITCH_LOCAL_IDLE_TO_ACTIVE
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode				(SW92503S_MODE_NOISE_SCAN) //SW92503B_MODE_PEN_POS
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mux_type			(0)
	#if USED_IDLE_FINGER_EVEN_ODD
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_lhb_mux_cnt			(1)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos0			(0)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos1			(8)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos2			(0)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos3			(0)
	#else
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_lhb_mux_cnt			(0)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos0			(0)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos1			(0)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos2			(0)
		#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos3			(0)
	#endif

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode				(SW92503S_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mux_type			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_lhb_mux_cnt			(1)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode				(SW92503S_MODE_DUMMY)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mux_type			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos3			(0)
#else
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mode				(SW92503S_MODE_DUMMY) //SW92503B_MODE_PEN_POS
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_pre_drv				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_mux_type			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_14_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mode				(SW92503S_MODE_NOISE_SCAN)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_mux_type			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_lhb_mux_cnt			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_15_local_pos3			(0)

	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mode				(SW92503S_MODE_PEN_POS)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_ping_en				(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_pre_drv				(1)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_pre_drvs_en			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_extmuxcmd			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_mux_type			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_lhb_mux_cnt			(1)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos0			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos1			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos2			(0)
	#define PARAMSET_ROIC_LOCAL_IDLE_LHB_16_local_pos3			(0)
#endif

#if USED_ROIC_AFE_LP_OPTION
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcon			(1) /* Intrgrator */
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcons			(1)	/* Sample & Hold */
#if USE_PWM_142KHZ
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_hv_ssu_bcon			(1) /* Pre-Amp */
#else	//	114KHz
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_hv_ssu_bcon			(0) /* Pre-Amp */
#endif
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pen_dc_md				(1)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pen_dc_md_stuck		(0)

	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_f			(1)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_p			(1)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_comp		(1)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_data		(1)

	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_f				(3)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_p				(3)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_comp			(3)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_data			(3)

	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_f				(2)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_comp			(2)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_p				(2)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_data			(2)

	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_powsel				(0)
#if USE_PWM_142KHZ
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_bs_lp				(1)
#else	//	114KHz
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_bs_lp				(1)
#endif
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_bs_lp				(1)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_tm_ssu_pen			(0)

#if USE_PWM_142KHZ
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_bcon			(3)
#else	//	114KHz
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_bcon			(1)
#endif
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_stc_insel		(0)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_dsf			(0)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_ref_sel		(0)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_int_ref			(4)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_sha_ref			(4)

#if USE_PWM_142KHZ
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_sha_bs_lp			(1)
#else	//	114KHz
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_sha_bs_lp			(1)
#endif

	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_ref_res_sel		(0)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_lv_comp_bcon		(1) /* Comparator */
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_comp_hys_ctrl		(0)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_tm_comp			(0)

	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_hvbias			(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_hvr				(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_lvbias			(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_lvr				(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_sha				(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_bgr_en				(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_adc				(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_compbias			(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_comp				(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_hvbias			(2)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_hvr			(2)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_lvbias			(3)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_lvr			(3)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_sha			(3)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_bgr			(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_adc			(3)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_compbias		(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_comp			(0)

	#define PARAMSET_VCOMR										(2) /* revisin item --> must 2 */
	#define PARAMSET_PRE_CH_CON_EN								(1) /* new add*/
	#define PARAMSET_PRE_COMP									(0) /* new add*/

#else /* USED_ROIC_AFE_LP_OPTION */
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcon			(0) /* Intrgrator */
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcons			(1)	/* Sample & Hold */
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_hv_ssu_bcon			(1) /* Pre-Amp */
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pen_dc_md				(1)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pen_dc_md_stuck		(0)
	//#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half			(7)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_f			(1)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_p			(1)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_comp		(1)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half_data		(1)

	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_f				(3)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_p				(3)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_comp			(3)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc_data			(3)

	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_f				(2)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_comp			(2)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_p				(2)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc_data			(2)

	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_powsel				(0)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_bs_lp				(0)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_bs_lp				(0)
	#define PARAMSET_ROIC_CFGR_SENSE_CTRL_tm_ssu_pen			(0)

	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_bcon			(3)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_stc_insel		(0)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_dsf			(1)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_adc_ref_sel		(0)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_int_ref			(4)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_sha_ref			(4)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_sha_bs_lp			(0)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_ref_res_sel		(0)
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_lv_comp_bcon		(0) /* Comparator */
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_comp_hys_ctrl		(0) /* Comparator Hysterisys */
	#define PARAMSET_ROIC_CFGR_COMP_ADC_CTRL_tm_comp			(0)

	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_hvbias			(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_hvr				(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_lvbias			(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_lvr				(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_sha				(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_bgr_en				(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_adc				(1)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_compbias			(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_comp				(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_hvbias			(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_hvr			(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_lvbias			(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_lvr			(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_sha			(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_bgr			(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_adc			(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_compbias		(0)
	#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_comp			(0)

	#define PARAMSET_VCOMR										(2) /* revisin item --> must 2 */
	#define PARAMSET_PRE_CH_CON_EN								(1) /* new add*/
	#define PARAMSET_PRE_COMP									(1) /* new add*/
#endif /* USED_ROIC_AFE_LP_OPTION */


/************************************************************************************************************/
/*											MPP2.5 ROIC Setting												*/
/************************************************************************************************************/
#define PARAMSET_ROIC_MPP_PWM_CTL_pwm_pdrv_num				(2)
#define PARAMSET_ROIC_MPP_PWM_CTL_pwm_act_num				(9)
#define PARAMSET_ROIC_MPP_PWM_CTL_pwm_smpl_num				(9)
#define PARAMSET_ROIC_MPP_PWM_CTL_pwm_dum_num				(0)
#define PARAMSET_ROIC_MPP_PWM_CTL_pdrv_dum_num				(0)
#define PARAMSET_ROIC_MPP_PWM_CTL_pwm_set_num				(0)

#define PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_pdrv_num			(2)
#define PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_act_num			(4)
#define PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_smpl_num			(4)
#define PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_dum_num			(0)
#define PARAMSET_ROIC_MPP_PWM_POS_CTL_pdrv_dum_num			(0)
#define PARAMSET_ROIC_MPP_PWM_POS_CTL_pwm_set_num			(0)

#define PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_pdrv_num			(2)
#define PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_act_num			(4)
#define PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_smpl_num			(4)
#define PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_dum_num			(0)
#define PARAMSET_ROIC_MPP_PWM_DAT_CTL_pdrv_dum_num			(0)
#define PARAMSET_ROIC_MPP_PWM_DAT_CTL_pwm_set_num			(0)

#define PARAMSET_ROIC_MPP_ND_CTRL_nd_dum_dly				(66)

#define PARAMSET_ROIC_MPP_CFGR_PWM_PRD_pwm_prd1				(64)
#define PARAMSET_ROIC_MPP_CFGR_PWM_PRD_pwm_prd2				(64)

#define PARAMSET_ROIC_MPP_CFGR_SMPL_CTL_smop_prd_1			(7)
#define PARAMSET_ROIC_MPP_CFGR_SMPL_CTL_smop_prd_2			(7)
#define PARAMSET_ROIC_MPP_CFGR_SMPL_CTL_crrpt_num			(0)

#define PARAMSET_ROIC_MPP_CFGR_RSTP_NUM1_rstp_num1			(10)
#define PARAMSET_ROIC_MPP_CFGR_RSTP_NUM1_rstp_num2			(3)

#define PARAMSET_ROIC_MPP_CFGR_PHT_NUM1_pht_num1			(23)
#define PARAMSET_ROIC_MPP_CFGR_PHT_NUM1_pht_num2			(18)

#define PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM1_phtcr_num1_1		(58)
#define PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM1_phtcr_num1_2		(58)

#define PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM2_phtcr_num2_1		(40)
#define PARAMSET_ROIC_MPP_CFGR_PHTCR_NUM2_phtcr_num2_2		(40)

#define PARAMSET_ROIC_MPP_CFGR_VCR_NUM1_vcr_num1_1			(50)
#define PARAMSET_ROIC_MPP_CFGR_VCR_NUM1_vcr_num1_2			(50)

#define PARAMSET_ROIC_MPP_CFGR_VCR_EN_NUM1_vcr_en_num1_1	(43)
#define PARAMSET_ROIC_MPP_CFGR_VCR_EN_NUM1_vcr_en_num1_2	(43)

#define PARAMSET_ROIC_MPP_CFGR_VCR_EN_NUM2_vcr_en_num2_1	(12)
#define PARAMSET_ROIC_MPP_CFGR_VCR_EN_NUM2_vcr_en_num2_2	(12)

#define PARAMSET_ROIC_MPP_CFGR_PHTH0_NUM1_phth0_num1_1		(16)
#define PARAMSET_ROIC_MPP_CFGR_PHTH0_NUM1_phth0_num1_2		(16)

#define PARAMSET_ROIC_MPP_CFGR_PHTH1_NUM1_phth1_num1_1		(15)
#define PARAMSET_ROIC_MPP_CFGR_PHTH1_NUM1_phth1_num1_2		(15)

#define PARAMSET_ROIC_MPP_CFGR_PHTH_NUM2_phth0_num2			(2)
#define PARAMSET_ROIC_MPP_CFGR_PHTH_NUM2_phth1_num2			(45)

#define PARAMSET_ROIC_MPP_CFGR_PHT_CTL_pht_prd				(2)
#define PARAMSET_ROIC_MPP_CFGR_PHT_CTL_pht_opt_smpl			(0)
#define PARAMSET_ROIC_MPP_CFGR_PHT_CTL_pht_opt_inv			(1)
#define PARAMSET_ROIC_MPP_CFGR_PHT_CTL_pht_etime			(16)

#define PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_op_opt			(0)
#define PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_clk_opt			(2)
#define PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_clk_pol			(0)
#define PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_clk_prd			(1)
#define PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_clk_num			(7)
#define PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_in_pos			(5)
#define PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_stc_dly			(31)
#define PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_adc_clk_spt			(0)
#define PARAMSET_ROIC_MPP_CFGR_ADC_CTRL_cfgr_tm_adc			(0)

#define PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_finger			(1023)
#define PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_pos		(9)
#define PARAMSET_ROIC_MPP_CFGR_PWM_SET_EN_BIT_pwm_set_en_pen_dat		(9)

#if USED_ROIC_AFE_LP_OPTION
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_lv_ssu_bcon			(1) /* Intrgrator */
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_lv_ssu_bcons			(1)	/* Sample & Hold */
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_hv_ssu_bcon			(0)//(1) /* Pre-Amp */
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pen_dc_md				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pen_dc_md_stuck		(0)

	//#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half			(7)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_f			(1)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_comp		(1)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_p			(1)

	//#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc				(63)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_f				(3)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_comp			(3)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_p				(3)

	//#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc				(42)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_f				(2)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_comp			(2)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_p				(2)


	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_powsel				(0)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_bs_lp				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_bs_lp				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_tm_ssu_pen			(0)

	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_bcon			(1)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_stc_insel		(0)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_dsf			(0)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_ref_sel		(0)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_int_ref			(4)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_sha_ref			(4)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_sha_bs_lp			(1)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_ref_res_sel		(0)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_lv_comp_bcon		(1) /* Comparator */
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_comp_hys_ctrl		(0)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_tm_comp			(0)

	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_hvbias			(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_hvr				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_lvbias			(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_lvr				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_sha				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_bgr_en				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_adc				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_compbias			(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_comp				(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_hvbias			(2)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_hvr			(2)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_lvbias			(3)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_lvr			(3)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_sha			(3)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_bgr			(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_adc			(3)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_compbias		(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_comp			(0)

	#define PARAMSET_MPP_VCOMR										(2) /* revisin item --> must 2 */
	#define PARAMSET_MPP_PRE_CH_CON_EN								(1) /* new add*/
	#define PARAMSET_MPP_PRE_COMP									(0) /* new add*/

#else /* USED_ROIC_AFE_LP_OPTION */
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_lv_ssu_bcon			(0) /* Intrgrator */
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_lv_ssu_bcons			(1)	/* Sample & Hold */
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_hv_ssu_bcon			(1) /* Pre-Amp */
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pen_dc_md				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pen_dc_md_stuck		(0)
	//#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half			(7)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_f			(1)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_comp		(1)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_integ_half_p			(1)

	//#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc				(63)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_f			(3)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_comp		(3)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_gc_p			(3)

	//#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc				(42)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_f			(2)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_comp		(2)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_gc_p			(2)

	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_powsel				(0)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_pre_bs_lp				(0)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_int_bs_lp				(0)
	#define PARAMSET_ROIC_MPP_CFGR_SENSE_CTRL_tm_ssu_pen			(0)

	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_bcon			(3)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_stc_insel		(0)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_dsf			(1)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_adc_ref_sel		(0)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_int_ref			(4)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_sha_ref			(4)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_sha_bs_lp			(0)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_ref_res_sel		(0)
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_lv_comp_bcon		(0) /* Comparator */
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_comp_hys_ctrl		(0) /* Comparator Hysterisys */
	#define PARAMSET_ROIC_MPP_CFGR_COMP_ADC_CTRL_tm_comp			(0)

	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_hvbias			(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_hvr				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_lvbias			(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_lvr				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_sha				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_bgr_en				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_adc				(1)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_compbias			(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_pdb_comp				(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_hvbias			(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_hvr			(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_lvbias			(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_lvr			(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_sha			(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_bgr			(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_adc			(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_compbias		(0)
	#define PARAMSET_ROIC_MPP_CFGR_SSU_PW_CTRL_stuck_comp			(0)

	#define PARAMSET_MPP_VCOMR										(2) /* revisin item --> must 2 */
	#define PARAMSET_MPP_PRE_CH_CON_EN								(1) /* new add*/
	#define PARAMSET_MPP_PRE_COMP									(1) /* new add*/
#endif /* USED_ROIC_AFE_LP_OPTION */

#include "param_configset_roic_cr_tune.h"

#endif /* _PARAM_CONFIGSET_ROIC_H_ */
