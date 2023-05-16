/****************************************************************************************************/ /**
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


#define SRIC_FREQ_50K								0
#define SRIC_FREQ_80K								1
#define SRIC_FREQ_91K								2
#define SRIC_FREQ_95K								3
#define SRIC_FREQ_100K								4
#define SRIC_FREQ_112K								5
#define SRIC_FREQ_133K								6

#define SET_FREQ   									(SRIC_FREQ_80K)

#if (SET_FREQ == SRIC_FREQ_50K)
#define PWM_ACT_PRD									(238)       // 91k: 130, 50k:238
#define PWM_ACT_LOW									(118)       // 91k: 64 , 50k:118
#define USED_GOBAL_TUNE_VAL							(16)
#define CFGR_PWM_PRD_pwm_prd1						(115) 	    // 100k 59, 91k 60
#define CFGR_PWM_PRD_pwm_prd2						(115)		// 100k 59, 91k 60

#define CFGR_RSTP_NUM1_rstp_num1					(10)		// 100k 14,	91k 10
#define CFGR_RSTP_NUM1_rstp_num2					(3)

#define CFGR_PHTCR_NUM1_phtcr_num1_1				(109)		// 100k 54,	91k 54
#define CFGR_PHTCR_NUM1_phtcr_num1_2				(109)		// 100k 54, 91k 54

#define CFGR_PHTCR_NUM2_phtcr_num2_1				(95)		// 100k 39, 91k 40
#define CFGR_PHTCR_NUM2_phtcr_num2_2				(95)

#define CFGR_VCR_NUM1_vcr_num1_1					(105)		// 100k 46, 91k 50
#define CFGR_VCR_NUM1_vcr_num1_2					(105)

#define CFGR_VCR_EN_NUM1_vcr_en_num1_1				(98)	    // 100k 53, 91k 43
#define CFGR_VCR_EN_NUM1_vcr_en_num1_2				(98)	    // 100k 53, 91k 43

#define CFGR_VCR_EN_NUM2_vcr_en_num2_1				(67)	    // 100k 27, 91k 12
#define CFGR_VCR_EN_NUM2_vcr_en_num2_2				(67)	    // 100k 27, 91k 12

#define CFGR_SMPL_CTL_smop_prd_1					(4)	        // 7
#define CFGR_SMPL_CTL_smop_prd_2					(4)	        // 7
#define CFGR_SMPL_CTL_crrpt_num						(0)	        // 1

#define CFGR_PHTH0_NUM1_phth0_num1_1				(16)	    // 100k 16, 91k 11
#define CFGR_PHTH0_NUM1_phth0_num1_2				(16)	    // 100k 16, 91k 11

#define CFGR_PHTH1_NUM1_phth1_num1_1				(15)	    // 100k 16, 91k 9
#define CFGR_PHTH1_NUM1_phth1_num1_2				(15)	    // 100k 16, 91k 9

#define CFGR_PHTH_NUM2_phth0_num2					(1)	        // 100k 2,  91k 1
#define CFGR_PHTH_NUM2_phth1_num2					(100)	    // 100k 48, 91k 45


#define CFGR_PHT_CTL_pht_prd						(2)	        // 1
#define CFGR_PHT_pht_opt_smpl						(0)	        // 0
#define CFGR_PHT_pht_opt_inv						(1)	        // 1
#define CFGR_PHT_CTL_pht_etime						(16)	    // 20

#define CFGR_PHT_NUM1_pht_num1						(23)	    // 100k 27, 91k 23
#define CFGR_PHT_NUM1_pht_num2						(13)	    // 100k 16, 91k 13

#define CFGR_SENSE_CTRL_lv_ssu_bcon					(0)
#define CFGR_SENSE_CTRL_lv_ssu_bcons				(1)
#define CFGR_SENSE_CTRL_hv_ssu_bcon					(3)
#define CFGR_SENSE_CTRL_integ_half					(1)
#define CFGR_SENSE_CTRL_pre_gc						(7)
#define CFGR_SENSE_CTRL_int_gc						(7)
#define CFGR_SENSE_CTRL_pre_bs_lp					(0)
#define CFGR_SENSE_CTRL_int_bs_lp					(0)
#define CFGR_SENSE_CTRL_sha_bs_lp					(0)

#define CFGR_ADC_CTRL_adc_op_opt					(0)
#define CFGR_ADC_CTRL_adc_clk_opt					(2)
#define CFGR_ADC_CTRL_adc_clk_pol					(0)
#define CFGR_ADC_CTRL_adc_clk_prd					(2)
#define CFGR_ADC_CTRL_adc_clk_num					(7)
#define CFGR_ADC_CTRL_adc_in_pos					(2)
#define CFGR_ADC_CTRL_adc_stc_dly					(31)
#define CFGR_ADC_CTRL_cfgr_tm_adc					(0)
#define CFGR_ADC_CTRL_adc_buf_pos					(0)

#elif (SET_FREQ == SRIC_FREQ_80K)
#define PWM_ACT_PRD									(148) // 91k: 130, 50k:238
#define PWM_ACT_LOW									(73) // 91k: 64 , 50k:118

#define USED_GOBAL_TUNE_VAL							(20)

#define CFGR_PWM_PRD_pwm_prd1						(71) 	// 100k 59, 91k 60
#define CFGR_PWM_PRD_pwm_prd2						(71)		// 100k 59, 91k 60

#define CFGR_RSTP_NUM1_rstp_num1					(8)		// 100k 14,	91k 10
#define CFGR_RSTP_NUM1_rstp_num2					(2)

#define CFGR_PHTCR_NUM1_phtcr_num1_1				(65)		// 100k 54,	91k 54
#define CFGR_PHTCR_NUM1_phtcr_num1_2				(65)		// 100k 54, 91k 54

#define CFGR_PHTCR_NUM2_phtcr_num2_1				(49)		// 100k 39, 91k 40
#define CFGR_PHTCR_NUM2_phtcr_num2_2				(49)

#define CFGR_VCR_NUM1_vcr_num1_1					(61)		// 100k 46, 91k 50
#define CFGR_VCR_NUM1_vcr_num1_2					(61)		// 100k 46, 91k 50

#define CFGR_VCR_EN_NUM1_vcr_en_num1_1				(69)		// 100k 53, 91k 43
#define CFGR_VCR_EN_NUM1_vcr_en_num1_2				(69)		// 100k 53, 91k 43

#define CFGR_VCR_EN_NUM2_vcr_en_num2_1				(5)		// 100k 27, 91k 12
#define CFGR_VCR_EN_NUM2_vcr_en_num2_2				(5)		// 100k 27, 91k 12

#define CFGR_SMPL_CTL_smop_prd_1					(4)		// 7
#define CFGR_SMPL_CTL_smop_prd_2					(4)		// 7
#define CFGR_SMPL_CTL_crrpt_num						(0)		// 1

#define CFGR_PHTH0_NUM1_phth0_num1_1				(14)		// 100k 16, 91k 11
#define CFGR_PHTH0_NUM1_phth0_num1_2				(14)	// 100k 16, 91k 11

#define CFGR_PHTH1_NUM1_phth1_num1_1				(14)		// 100k 16, 91k 9
#define CFGR_PHTH1_NUM1_phth1_num1_2				(14)		// 100k 16, 91k 9

#define CFGR_PHTH_NUM2_phth0_num2					(1)	// 100k 2,  91k 1
#define CFGR_PHTH_NUM2_phth1_num2					(46)	// 100k 48, 91k 45

#define CFGR_PHT_CTL_pht_prd						(2)	// 1
#define CFGR_PHT_pht_opt_smpl						(0)	// 0
#define CFGR_PHT_pht_opt_inv						(1)	// 1
#define CFGR_PHT_CTL_pht_etime						(16)	// 20

#define CFGR_PHT_NUM1_pht_num1						(20)	// 100k 27, 91k 23
#define CFGR_PHT_NUM1_pht_num2						(11)	// 100k 16, 91k 13

#define CFGR_SENSE_CTRL_lv_ssu_bcon					(0)
#define CFGR_SENSE_CTRL_lv_ssu_bcons				(1)
#define CFGR_SENSE_CTRL_hv_ssu_bcon					(4)//3
#define CFGR_SENSE_CTRL_integ_half					(1)//(1)
#define CFGR_SENSE_CTRL_pre_gc						(7)//(6)//(7)
#define CFGR_SENSE_CTRL_int_gc						(7)//(6)//(7) //5
#define CFGR_SENSE_CTRL_pre_bs_lp					(0)
#define CFGR_SENSE_CTRL_int_bs_lp					(0)
#define CFGR_SENSE_CTRL_sha_bs_lp					(0)

#define CFGR_ADC_CTRL_adc_op_opt					(0)
#define CFGR_ADC_CTRL_adc_clk_opt					(2)
#define CFGR_ADC_CTRL_adc_clk_pol					(0)
#define CFGR_ADC_CTRL_adc_clk_prd					(2)
#define CFGR_ADC_CTRL_adc_clk_num					(7)
#define CFGR_ADC_CTRL_adc_in_pos					(2)
#define CFGR_ADC_CTRL_adc_stc_dly					(31)
#define CFGR_ADC_CTRL_cfgr_tm_adc					(0)
#define CFGR_ADC_CTRL_adc_buf_pos					(0)

#elif (SET_FREQ == SRIC_FREQ_91K)
#define PWM_ACT_PRD									130 // 91k: 130, 50k:238
#define PWM_ACT_LOW									64 // 91k: 64 , 50k:118

#define USED_GOBAL_TUNE_VAL							16

#define CFGR_PWM_PRD_pwm_prd1						60 	// 100k 59, 91k 60
#define CFGR_PWM_PRD_pwm_prd2						60		// 100k 59, 91k 60

#define CFGR_RSTP_NUM1_rstp_num1					10		// 100k 14,	91k 10
#define CFGR_RSTP_NUM1_rstp_num2					3

#define CFGR_PHTCR_NUM1_phtcr_num1_1				54		// 100k 54,	91k 54
#define CFGR_PHTCR_NUM1_phtcr_num1_2				54		// 100k 54, 91k 54

#define CFGR_PHTCR_NUM2_phtcr_num2_1				40		// 100k 39, 91k 40
#define CFGR_PHTCR_NUM2_phtcr_num2_2				40

#define CFGR_VCR_NUM1_vcr_num1_1					50		// 100k 46, 91k 50
#define CFGR_VCR_NUM1_vcr_num1_2					50

#define CFGR_VCR_EN_NUM1_vcr_en_num1_1				43	// 100k 53, 91k 43
#define CFGR_VCR_EN_NUM1_vcr_en_num1_2				43	// 100k 53, 91k 43

#define CFGR_VCR_EN_NUM2_vcr_en_num2_1				12	// 100k 27, 91k 12
#define CFGR_VCR_EN_NUM2_vcr_en_num2_2				12	// 100k 27, 91k 12

#define CFGR_SMPL_CTL_smop_prd_1					4	// 7
#define CFGR_SMPL_CTL_smop_prd_2					4	// 7
#define CFGR_SMPL_CTL_crrpt_num						0	// 1

#define CFGR_PHTH0_NUM1_phth0_num1_1				16	// 100k 16, 91k 11
#define CFGR_PHTH0_NUM1_phth0_num1_2				16	// 100k 16, 91k 11

#define CFGR_PHTH1_NUM1_phth1_num1_1				15	// 100k 16, 91k 9
#define CFGR_PHTH1_NUM1_phth1_num1_2				15	// 100k 16, 91k 9

#define CFGR_PHTH_NUM2_phth0_num2					1	// 100k 2,  91k 1
#define CFGR_PHTH_NUM2_phth1_num2					45	// 100k 48, 91k 45


#define CFGR_PHT_CTL_pht_prd						2	// 1
#define CFGR_PHT_pht_opt_smpl						0	// 0
#define CFGR_PHT_pht_opt_inv						1	// 1
#define CFGR_PHT_CTL_pht_etime						16	// 20

#define CFGR_PHT_NUM1_pht_num1						23	// 100k 27, 91k 23
#define CFGR_PHT_NUM1_pht_num2						13	// 100k 16, 91k 13

#define CFGR_SENSE_CTRL_lv_ssu_bcon					0
#define CFGR_SENSE_CTRL_lv_ssu_bcons				1
#define CFGR_SENSE_CTRL_hv_ssu_bcon					4
#define CFGR_SENSE_CTRL_integ_half					1
#define CFGR_SENSE_CTRL_pre_gc						7
#define CFGR_SENSE_CTRL_int_gc						7
#define CFGR_SENSE_CTRL_pre_bs_lp					0
#define CFGR_SENSE_CTRL_int_bs_lp					0
#define CFGR_SENSE_CTRL_sha_bs_lp					0

#define CFGR_ADC_CTRL_adc_op_opt					0
#define CFGR_ADC_CTRL_adc_clk_opt					2
#define CFGR_ADC_CTRL_adc_clk_pol					0
#define CFGR_ADC_CTRL_adc_clk_prd					2
#define CFGR_ADC_CTRL_adc_clk_num					7
#define CFGR_ADC_CTRL_adc_in_pos					2
#define CFGR_ADC_CTRL_adc_stc_dly					31
#define CFGR_ADC_CTRL_cfgr_tm_adc					0
#define CFGR_ADC_CTRL_adc_buf_pos					0

#elif (SET_FREQ == SRIC_FREQ_95K)
#define PWM_ACT_PRD									124 // 91k: 130, 50k:238
#define PWM_ACT_LOW									61 // 91k: 64 , 50k:118

#define USED_GOBAL_TUNE_VAL							16

#define CFGR_PWM_PRD_pwm_prd1						58 	// 100k 59, 91k 60
#define CFGR_PWM_PRD_pwm_prd2						58		// 100k 59, 91k 60

#define CFGR_RSTP_NUM1_rstp_num1					8		// 100k 14,	91k 10
#define CFGR_RSTP_NUM1_rstp_num2					2

#define CFGR_PHTCR_NUM1_phtcr_num1_1				52		// 100k 54,	91k 54
#define CFGR_PHTCR_NUM1_phtcr_num1_2				52		// 100k 54, 91k 54

#define CFGR_PHTCR_NUM2_phtcr_num2_1				36		// 100k 39, 91k 40
#define CFGR_PHTCR_NUM2_phtcr_num2_2				36

#define CFGR_VCR_NUM1_vcr_num1_1					48		// 100k 46, 91k 50
#define CFGR_VCR_NUM1_vcr_num1_2					48

#define CFGR_VCR_EN_NUM1_vcr_en_num1_1				56	// 100k 53, 91k 43
#define CFGR_VCR_EN_NUM1_vcr_en_num1_2				56	// 100k 53, 91k 43

#define CFGR_VCR_EN_NUM2_vcr_en_num2_1				5	// 100k 27, 91k 12
#define CFGR_VCR_EN_NUM2_vcr_en_num2_2				5	// 100k 27, 91k 12

#define CFGR_SMPL_CTL_smop_prd_1					4	// 7
#define CFGR_SMPL_CTL_smop_prd_2					4	// 7
#define CFGR_SMPL_CTL_crrpt_num						0	// 1

#define CFGR_PHTH0_NUM1_phth0_num1_1				14	// 100k 16, 91k 11
#define CFGR_PHTH0_NUM1_phth0_num1_2				14	// 100k 16, 91k 11

#define CFGR_PHTH1_NUM1_phth1_num1_1				14	// 100k 16, 91k 9
#define CFGR_PHTH1_NUM1_phth1_num1_2				14	// 100k 16, 91k 9

#define CFGR_PHTH_NUM2_phth0_num2					1	// 100k 2,  91k 1
#define CFGR_PHTH_NUM2_phth1_num2					33	// 100k 48, 91k 45


#define CFGR_PHT_CTL_pht_prd						2	// 1
#define CFGR_PHT_pht_opt_smpl						0	// 0
#define CFGR_PHT_pht_opt_inv						1	// 1
#define CFGR_PHT_CTL_pht_etime						16	// 20

#define CFGR_PHT_NUM1_pht_num1						20	// 100k 27, 91k 23
#define CFGR_PHT_NUM1_pht_num2						11	// 100k 16, 91k 13

#define CFGR_SENSE_CTRL_lv_ssu_bcon					0
#define CFGR_SENSE_CTRL_lv_ssu_bcons				1
#define CFGR_SENSE_CTRL_hv_ssu_bcon					4
#define CFGR_SENSE_CTRL_integ_half					1
#define CFGR_SENSE_CTRL_pre_gc						7
#define CFGR_SENSE_CTRL_int_gc						7
#define CFGR_SENSE_CTRL_pre_bs_lp					0
#define CFGR_SENSE_CTRL_int_bs_lp					0
#define CFGR_SENSE_CTRL_sha_bs_lp					0

#define CFGR_ADC_CTRL_adc_op_opt					0
#define CFGR_ADC_CTRL_adc_clk_opt					2
#define CFGR_ADC_CTRL_adc_clk_pol					0
#define CFGR_ADC_CTRL_adc_clk_prd					2
#define CFGR_ADC_CTRL_adc_clk_num					7
#define CFGR_ADC_CTRL_adc_in_pos					2
#define CFGR_ADC_CTRL_adc_stc_dly					31
#define CFGR_ADC_CTRL_cfgr_tm_adc					0
#define CFGR_ADC_CTRL_adc_buf_pos					0

#elif (SET_FREQ == SRIC_FREQ_100K)
#define PWM_ACT_PRD									118 // 91k: 130, 50k:238
#define PWM_ACT_LOW									58 // 91k: 64 , 50k:118

#define USED_GOBAL_TUNE_VAL							16

#define CFGR_PWM_PRD_pwm_prd1						53 	// 100k 59, 91k 60
#define CFGR_PWM_PRD_pwm_prd2						53		// 100k 59, 91k 60

#define CFGR_RSTP_NUM1_rstp_num1					8		// 100k 14,	91k 10
#define CFGR_RSTP_NUM1_rstp_num2					3

#define CFGR_PHTCR_NUM1_phtcr_num1_1				33		// 100k 54,	91k 54
#define CFGR_PHTCR_NUM1_phtcr_num1_2				33		// 100k 54, 91k 54

#define CFGR_PHTCR_NUM2_phtcr_num2_1				15		// 100k 39, 91k 40
#define CFGR_PHTCR_NUM2_phtcr_num2_2				15

#define CFGR_VCR_NUM1_vcr_num1_1					29		// 100k 46, 91k 50
#define CFGR_VCR_NUM1_vcr_num1_2					29

#define CFGR_VCR_EN_NUM1_vcr_en_num1_1				37	// 100k 53, 91k 43
#define CFGR_VCR_EN_NUM1_vcr_en_num1_2				37	// 100k 53, 91k 43

#define CFGR_VCR_EN_NUM2_vcr_en_num2_1				12	// 100k 27, 91k 12
#define CFGR_VCR_EN_NUM2_vcr_en_num2_2				12	// 100k 27, 91k 12

#define CFGR_SMPL_CTL_smop_prd_1					4	// 7
#define CFGR_SMPL_CTL_smop_prd_2					4	// 7
#define CFGR_SMPL_CTL_crrpt_num						0	// 1

#define CFGR_PHTH0_NUM1_phth0_num1_1				10	// 100k 16, 91k 11
#define CFGR_PHTH0_NUM1_phth0_num1_2				10	// 100k 16, 91k 11

#define CFGR_PHTH1_NUM1_phth1_num1_1				9	// 100k 16, 91k 9
#define CFGR_PHTH1_NUM1_phth1_num1_2				9	// 100k 16, 91k 9

#define CFGR_PHTH_NUM2_phth0_num2					1	// 100k 2,  91k 1
#define CFGR_PHTH_NUM2_phth1_num2					29	// 100k 48, 91k 45


#define CFGR_PHT_CTL_pht_prd						2	// 1
#define CFGR_PHT_pht_opt_smpl						0	// 0
#define CFGR_PHT_pht_opt_inv						1	// 1
#define CFGR_PHT_CTL_pht_etime						12	// 20

#define CFGR_PHT_NUM1_pht_num1						15	// 100k 27, 91k 23
#define CFGR_PHT_NUM1_pht_num2						10	// 100k 16, 91k 13

#define CFGR_SENSE_CTRL_lv_ssu_bcon					0
#define CFGR_SENSE_CTRL_lv_ssu_bcons				1
#define CFGR_SENSE_CTRL_hv_ssu_bcon					3
#define CFGR_SENSE_CTRL_integ_half					1
#define CFGR_SENSE_CTRL_pre_gc						7
#define CFGR_SENSE_CTRL_int_gc						7
#define CFGR_SENSE_CTRL_pre_bs_lp					0
#define CFGR_SENSE_CTRL_int_bs_lp					0
#define CFGR_SENSE_CTRL_sha_bs_lp					0

#define CFGR_ADC_CTRL_adc_op_opt					0
#define CFGR_ADC_CTRL_adc_clk_opt					2
#define CFGR_ADC_CTRL_adc_clk_pol					0
#define CFGR_ADC_CTRL_adc_clk_prd					2
#define CFGR_ADC_CTRL_adc_clk_num					7
#define CFGR_ADC_CTRL_adc_in_pos					2
#define CFGR_ADC_CTRL_adc_stc_dly					31
#define CFGR_ADC_CTRL_cfgr_tm_adc					0
#define CFGR_ADC_CTRL_adc_buf_pos					0

#elif (SET_FREQ == SRIC_FREQ_112K)
#define PWM_ACT_PRD									(148) // 91k: 130, 50k:238
#define PWM_ACT_LOW									(73) // 91k: 64 , 50k:118

#define USED_GOBAL_TUNE_VAL							(20)

#define CFGR_PWM_PRD_pwm_prd1						(48) 		// 100k 59, 91k 60, //	71: 80Khz, 48: 112Khz
#define CFGR_PWM_PRD_pwm_prd2						(48)		// 100k 59, 91k 60, //	71: 80Khz, 48: 112Khz

#define CFGR_RSTP_NUM1_rstp_num1					(8)			// 100k 14,	91k 10
#define CFGR_RSTP_NUM1_rstp_num2					(2)

#define CFGR_PHTCR_NUM1_phtcr_num1_1				(42)		// 100k 54,	91k 54	//	65: 80Khz, 42: 112Khz
#define CFGR_PHTCR_NUM1_phtcr_num1_2				(42)		// 100k 54, 91k 54	//	65: 80Khz, 42: 112Khz

#define CFGR_PHTCR_NUM2_phtcr_num2_1				(32)		// 100k 39, 91k 40	//	49: 80Khz, 32: 112Khz
#define CFGR_PHTCR_NUM2_phtcr_num2_2				(32)		// 100k 39, 91k 40	//	49: 80Khz, 32: 112Khz

#define CFGR_VCR_NUM1_vcr_num1_1					(38)		// 100k 46, 91k 50	//	61: 80Khz, 38: 112Khz
#define CFGR_VCR_NUM1_vcr_num1_2					(38)		// 100k 46, 91k 50	//	61: 80Khz, 38: 112Khz

#define CFGR_VCR_EN_NUM1_vcr_en_num1_1				(46)		// 100k 53, 91k 43	//	69: 80Khz, 46: 112Khz
#define CFGR_VCR_EN_NUM1_vcr_en_num1_2				(46)		// 100k 53, 91k 43	//	69: 80Khz, 46: 112Khz

#define CFGR_VCR_EN_NUM2_vcr_en_num2_1				(5)		// 100k 27, 91k 12
#define CFGR_VCR_EN_NUM2_vcr_en_num2_2				(5)		// 100k 27, 91k 12

#define CFGR_SMPL_CTL_smop_prd_1					(4)		// 7
#define CFGR_SMPL_CTL_smop_prd_2					(4)		// 7
#define CFGR_SMPL_CTL_crrpt_num						(0)		// 1

#define CFGR_PHTH0_NUM1_phth0_num1_1				(10)		// 100k 16, 91k 11	//	14: 80Khz, 10: 112Khz
#define CFGR_PHTH0_NUM1_phth0_num1_2				(10)		// 100k 16, 91k 11	//	14: 80Khz, 10: 112Khz

#define CFGR_PHTH1_NUM1_phth1_num1_1				(10)		// 100k 16, 91k 9	//	14: 80Khz, 10: 112Khz
#define CFGR_PHTH1_NUM1_phth1_num1_2				(10)		// 100k 16, 91k 9	//	14: 80Khz, 10: 112Khz

#define CFGR_PHTH_NUM2_phth0_num2					(1)			// 100k 2,  91k 1
#define CFGR_PHTH_NUM2_phth1_num2					(30)		// 100k 48, 91k 45	//	46: 80Khz, 30: 112Khz

#define CFGR_PHT_CTL_pht_prd						(2)	// 1
#define CFGR_PHT_pht_opt_smpl						(0)	// 0
#define CFGR_PHT_pht_opt_inv						(1)	// 1
#define CFGR_PHT_CTL_pht_etime						(16)	// 20

#define CFGR_PHT_NUM1_pht_num1						(20)			// 100k 27, 91k 23
#define CFGR_PHT_NUM1_pht_num2						(12)		// 100k 16, 91k 13	//	11: 80Khz, 12: 112Khz

#define CFGR_SENSE_CTRL_lv_ssu_bcon					(0)
#define CFGR_SENSE_CTRL_lv_ssu_bcons				(1)
#define CFGR_SENSE_CTRL_hv_ssu_bcon					(4)//3
#define CFGR_SENSE_CTRL_integ_half					(1)
#define CFGR_SENSE_CTRL_pre_gc						(7)
#define CFGR_SENSE_CTRL_int_gc						(7) //5
#define CFGR_SENSE_CTRL_pre_bs_lp					(0)
#define CFGR_SENSE_CTRL_int_bs_lp					(0)
#define CFGR_SENSE_CTRL_sha_bs_lp					(0)

#define CFGR_ADC_CTRL_adc_op_opt					(0)
#define CFGR_ADC_CTRL_adc_clk_opt					(2)
#define CFGR_ADC_CTRL_adc_clk_pol					(0)
#define CFGR_ADC_CTRL_adc_clk_prd					(2)
#define CFGR_ADC_CTRL_adc_clk_num					(7)
#define CFGR_ADC_CTRL_adc_in_pos					(2)
#define CFGR_ADC_CTRL_adc_stc_dly					(31)
#define CFGR_ADC_CTRL_cfgr_tm_adc					(0)
#define CFGR_ADC_CTRL_adc_buf_pos					(0)

#elif (SET_FREQ == SRIC_FREQ_133K)
#define PWM_ACT_PRD									88 // 91k: 130, 50k:238
#define PWM_ACT_LOW									43 // 91k: 64 , 50k:118

#define USED_GOBAL_TUNE_VAL							16

#define CFGR_PWM_PRD_pwm_prd1						41 	// 100k 59, 91k 60
#define CFGR_PWM_PRD_pwm_prd2						41		// 100k 59, 91k 60

#define CFGR_RSTP_NUM1_rstp_num1					8		// 100k 14,	91k 10
#define CFGR_RSTP_NUM1_rstp_num2					3

#define CFGR_PHTCR_NUM1_phtcr_num1_1				29		// 100k 54,	91k 54
#define CFGR_PHTCR_NUM1_phtcr_num1_2				29		// 100k 54, 91k 54

#define CFGR_PHTCR_NUM2_phtcr_num2_1				14		// 100k 39, 91k 40
#define CFGR_PHTCR_NUM2_phtcr_num2_2				14

#define CFGR_VCR_NUM1_vcr_num1_1					25		// 100k 46, 91k 50
#define CFGR_VCR_NUM1_vcr_num1_2					25

#define CFGR_VCR_EN_NUM1_vcr_en_num1_1				27	// 100k 53, 91k 43
#define CFGR_VCR_EN_NUM1_vcr_en_num1_2				27	// 100k 53, 91k 43

#define CFGR_VCR_EN_NUM2_vcr_en_num2_1				12	// 100k 27, 91k 12
#define CFGR_VCR_EN_NUM2_vcr_en_num2_2				12	// 100k 27, 91k 12

#define CFGR_SMPL_CTL_smop_prd_1					4	// 7
#define CFGR_SMPL_CTL_smop_prd_2					4	// 7
#define CFGR_SMPL_CTL_crrpt_num						0	// 1

#define CFGR_PHTH0_NUM1_phth0_num1_1				10	// 100k 16, 91k 11
#define CFGR_PHTH0_NUM1_phth0_num1_2				10	// 100k 16, 91k 11

#define CFGR_PHTH1_NUM1_phth1_num1_1				9	// 100k 16, 91k 9
#define CFGR_PHTH1_NUM1_phth1_num1_2				9	// 100k 16, 91k 9

#define CFGR_PHTH_NUM2_phth0_num2					1	// 100k 2,  91k 1
#define CFGR_PHTH_NUM2_phth1_num2					18	// 100k 48, 91k 45


#define CFGR_PHT_CTL_pht_prd						2	// 1
#define CFGR_PHT_pht_opt_smpl						0	// 0
#define CFGR_PHT_pht_opt_inv						1	// 1
#define CFGR_PHT_CTL_pht_etime						10	// 20

#define CFGR_PHT_NUM1_pht_num1						12	// 100k 27, 91k 23
#define CFGR_PHT_NUM1_pht_num2						8	// 100k 16, 91k 13

#define CFGR_SENSE_CTRL_lv_ssu_bcon					0
#define CFGR_SENSE_CTRL_lv_ssu_bcons				1
#define CFGR_SENSE_CTRL_hv_ssu_bcon					3
#define CFGR_SENSE_CTRL_integ_half					1
#define CFGR_SENSE_CTRL_pre_gc						7
#define CFGR_SENSE_CTRL_int_gc						7
#define CFGR_SENSE_CTRL_pre_bs_lp					0
#define CFGR_SENSE_CTRL_int_bs_lp					0
#define CFGR_SENSE_CTRL_sha_bs_lp					0

#define CFGR_ADC_CTRL_adc_op_opt					0
#define CFGR_ADC_CTRL_adc_clk_opt					2
#define CFGR_ADC_CTRL_adc_clk_pol					0
#define CFGR_ADC_CTRL_adc_clk_prd					2
#define CFGR_ADC_CTRL_adc_clk_num					7
#define CFGR_ADC_CTRL_adc_in_pos					2
#define CFGR_ADC_CTRL_adc_stc_dly					31
#define CFGR_ADC_CTRL_cfgr_tm_adc					0
#define CFGR_ADC_CTRL_adc_buf_pos					0

#endif	/* SET_FREQ */

/* ************************************************* */

#define PARAMSET_ROIC_SPIS_CFG_spis_irq_en                  (1)
#define PARAMSET_ROIC_SPIS_CFG_miso_func                    (0)

#define PARAMSET_ROIC_SPIS_ERROR_CLR_spi_chksum_clr         (1)
#define PARAMSET_ROIC_SPIS_ERROR_CLR_tsync_fault_clr        (1)
#define PARAMSET_ROIC_SPIS_ERROR_CLR_pwm_fault_clr          (1)

#define PARAMSET_ROIC_SPIS_ERROR_ST_spi_chksum_err          (0)
#define PARAMSET_ROIC_SPIS_ERROR_ST_tsync_fault_err         (0)
#define PARAMSET_ROIC_SPIS_ERROR_ST_pwm_fault_err           (0)

#define PARAMSET_ROIC_CFGR_SYS_CFG_tg_reset                 (0)
#define PARAMSET_ROIC_CFGR_SYS_CFG_sw_reset                 (0)
#define PARAMSET_ROIC_CFGR_SYS_CFG_tg_clk_all_on            (1)
#define PARAMSET_ROIC_CFGR_SYS_CFG_buf_clk_on               (1)

#define PARAMSET_ROIC_CFGR_TC_START_tc_start                (0)
#define PARAMSET_ROIC_CFGR_TC_START_scan_con                (0)

#define PARAMSET_ROIC_CFGR_TC_STOP_tc_stop                  (0)

#define PARAMSET_ROIC_CFGR_CH_EN_ch_num                     (25)
#define PARAMSET_ROIC_CFGR_CH_EN_ch_en_lvr                  (31)
#define PARAMSET_ROIC_CFGR_CH_EN_reserve0                   (0)
#define PARAMSET_ROIC_CFGR_CH_EN_ch_en_hvr                  (127)
#define PARAMSET_ROIC_CFGR_CH_EN_reserve1                   (0)
#define PARAMSET_ROIC_CFGR_CH_EN_dum_drv_en                 (0)
#define PARAMSET_ROIC_CFGR_CH_EN_stuck_lvr_en               (0)
#define PARAMSET_ROIC_CFGR_CH_EN_stuck_hvr_en               (0)

#define PARAMSET_ROIC_CFGR_MUX_EN_mux_bit_en                (2047)
#define PARAMSET_ROIC_CFGR_MUX_EN_mux_int_en                (0)
#define PARAMSET_ROIC_CFGR_MUX_EN_mux_num_tot               (FINGER_MUX_NUM - 1)        //<<
#define PARAMSET_ROIC_CFGR_MUX_EN_mux_num_tsync             (FINGER_MUX_NUM - 1)        //<<
#define PARAMSET_ROIC_CFGR_MUX_EN_m1_mux_en                 (0)

#define PARAMSET_ROIC_CFGR_DIC_CFG_sd_off                   (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_sd_float                 (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_tsync_in_pol             (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_pwm_pol                  (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_tsync_out_pol            (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_tsync_out_bypass         (1)
#define PARAMSET_ROIC_CFGR_DIC_CFG_tsync_out_stuck          (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_tsync_out_level          (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_vsync_pol                (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_vsync_tg_en              (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_vsync_tg_act             (0)

#define PARAMSET_ROIC_CFGR_DIC_CFG_stuck_abd                (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_cfgr_abd                 (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_cfgr_abd_pol             (0)
#define PARAMSET_ROIC_CFGR_DIC_CFG_cfgr_abd_inv             (0)

#define PARAMSET_ROIC_CFGR_DIC_CFG_sd_hvdd                  (0)

#define PARAMSET_PWMDRV_FINGER_ACT_NUM						(21)

#define PARAMSET_ROIC_CFGR_PWM_CTL_pwm_num                  (5+PARAMSET_PWMDRV_FINGER_ACT_NUM-1)//(PARAMSET_PWMDRV_Set_Num + PARAMSET_PWMDRV_Finger_Act_Num - 1)  //<<
#define PARAMSET_ROIC_CFGR_PWM_CTL_pwm_act_num              (PARAMSET_PWMDRV_FINGER_ACT_NUM-1)//(PARAMSET_PWMDRV_Finger_Act_Num - 1)  //<<
#define PARAMSET_ROIC_CFGR_PWM_CTL_pwm_smpl_num             (PARAMSET_PWMDRV_FINGER_ACT_NUM-1)//(PARAMSET_PWMDRV_Finger_Act_Num - 1)  //<<

#if USED_S3_MSPI_4MHz_OPERATION
	#define PARAMSET_ROIC_CFGR_PWM_CTL_Idle_pwm_num             (24+17-1)//(2+17-1)//(PARAMSET_PWMDRV_Set_Num + PARAMSET_PWMDRV_Finger_Act_Num - 1)  //<<
#else
	#define PARAMSET_ROIC_CFGR_PWM_CTL_Idle_pwm_num             (2+17-1)//(PARAMSET_PWMDRV_Set_Num + PARAMSET_PWMDRV_Finger_Act_Num - 1)  //<<
#endif
#define PARAMSET_ROIC_CFGR_PWM_CTL_Idle_pwm_act_num         (17-1)//(PARAMSET_PWMDRV_Finger_Act_Num - 1)  //<<
#define PARAMSET_ROIC_CFGR_PWM_CTL_Idle_pwm_smpl_num        (17-1)//(PARAMSET_PWMDRV_Finger_Act_Num - 1)  //<<

#define PARAMSET_ROIC_CFGR_PWM_CTL_pwm_dum_num              (3)//(PARAMSET_PWMDRV_Pre_Num)  //<<

#define PARAMSET_ROIC_ND_CTRL_nd_dum_dly                    (115)

#define PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd1                 (CFGR_PWM_PRD_pwm_prd1)  //<<
#define PARAMSET_ROIC_CFGR_PWM_PRD_pwm_prd2                 (CFGR_PWM_PRD_pwm_prd2)  //<<

#define PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd                (7)
#define PARAMSET_ROIC_CFGR_SMPL_CTL_smop_prd                (7)
#define PARAMSET_ROIC_CFGR_SMPL_CTL_crrpt_num               (1)

#define PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num1              (CFGR_RSTP_NUM1_rstp_num1)  //<<
#define PARAMSET_ROIC_CFGR_RSTP_NUM1_rstp_num2              (CFGR_RSTP_NUM1_rstp_num2)  //<<

#define PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_1          (CFGR_PHTCR_NUM1_phtcr_num1_1)  //<<
#define PARAMSET_ROIC_CFGR_PHTCR_NUM1_phtcr_num1_2          (CFGR_PHTCR_NUM1_phtcr_num1_2)  //<<

#define PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_1          (CFGR_PHTCR_NUM2_phtcr_num2_1)  //<<
#define PARAMSET_ROIC_CFGR_PHTCR_NUM2_phtcr_num2_2          (CFGR_PHTCR_NUM2_phtcr_num2_2)  //<<

#define PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_1              (CFGR_VCR_NUM1_vcr_num1_1)  //<<
#define PARAMSET_ROIC_CFGR_VCR_NUM1_vcr_num1_2              (CFGR_VCR_NUM1_vcr_num1_2)  //<<

#define PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_1        (CFGR_VCR_EN_NUM1_vcr_en_num1_1)  //<<
#define PARAMSET_ROIC_CFGR_VCR_EN_NUM1_vcr_en_num1_2        (CFGR_VCR_EN_NUM1_vcr_en_num1_2)  //<<

#define PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_1        (CFGR_VCR_EN_NUM2_vcr_en_num2_1)  //<<
#define PARAMSET_ROIC_CFGR_VCR_EN_NUM2_vcr_en_num2_2        (CFGR_VCR_EN_NUM2_vcr_en_num2_2)  //<<

#define PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_1          (CFGR_PHTH0_NUM1_phth0_num1_1)  //<<
#define PARAMSET_ROIC_CFGR_PHTH0_NUM1_phth0_num1_2          (CFGR_PHTH0_NUM1_phth0_num1_2)  //<<

#define PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_1          (CFGR_PHTH1_NUM1_phth1_num1_1)  //<<
#define PARAMSET_ROIC_CFGR_PHTH1_NUM1_phth1_num1_2          (CFGR_PHTH1_NUM1_phth1_num1_2)  //<<

#define PARAMSET_ROIC_CFGR_PHTH_NUM2_phth0_num2             (CFGR_PHTH_NUM2_phth0_num2)  //<<
#define PARAMSET_ROIC_CFGR_PHTH_NUM2_phth1_num2             (CFGR_PHTH_NUM2_phth1_num2)  //<<

#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_prd                  (CFGR_PHT_CTL_pht_prd)  //<<
#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_opt_smpl             (CFGR_PHT_pht_opt_smpl)  //<<
#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_opt_inv              (CFGR_PHT_pht_opt_inv)  //<<
#define PARAMSET_ROIC_CFGR_PHT_CTL_pht_etime                (CFGR_PHT_CTL_pht_etime)  //<<

#define PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num1                (CFGR_PHT_NUM1_pht_num1)  //<<
#define PARAMSET_ROIC_CFGR_PHT_NUM1_pht_num2                (CFGR_PHT_NUM1_pht_num2)  //<<

#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_op_opt              (CFGR_ADC_CTRL_adc_op_opt)  //<<
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_opt             (CFGR_ADC_CTRL_adc_clk_opt)  //<<
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_pol             (CFGR_ADC_CTRL_adc_clk_pol)  //<<
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_prd             (CFGR_ADC_CTRL_adc_clk_prd)  //<<
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_clk_num             (CFGR_ADC_CTRL_adc_clk_num)  //<<
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_in_pos              (CFGR_ADC_CTRL_adc_in_pos)  //<<
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_stc_dly             (CFGR_ADC_CTRL_adc_stc_dly)  //<<
#define PARAMSET_ROIC_CFGR_ADC_CTRL_cfgr_tm_adc             (CFGR_ADC_CTRL_cfgr_tm_adc)  //<<
#define PARAMSET_ROIC_CFGR_ADC_CTRL_adc_buf_pos             (CFGR_ADC_CTRL_adc_buf_pos)  //<<

#define PARAMSET_ROIC_CFGR_BUF_OPT_double_buf_en            (1)

#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_rstp              (0)
#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_phtcr             (0)
#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_vcr               (0)
#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_vcr_odd_en        (0)
#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_vcr_even_en       (0)
#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_phth0             (0)
#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_phth1             (0)
#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_pht0              (0)
#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_pht1              (0)
#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_rsti              (0)
#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_mux_en            (0)
#define PARAMSET_ROIC_CFGR_TG_STUCK_stuck_adc_in            (0)

#define PARAMSET_ROIC_CFGR_ADC_IN_adc_in                    (1)

#define PARAMSET_ROIC_CFGR_MUX_STUCK_VAL_mux_stuck_val      (0)

#define PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_00                (8)
#define PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_01                (7)
#define PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_02                (6)
#define PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_03                (5)
#define PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_04                (4)
#define PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_05                (3)
#define PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_06                (2)
#define PARAMSET_ROIC_CFGR_MUX_CFG_00_mux_07                (1)

#define PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_08                (0)
#define PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_09                (9)
#define PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_10                (10)
#define PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_11                (11)
#define PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_12                (12)
#define PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_13                (13)
#define PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_14                (14)
#define PARAMSET_ROIC_CFGR_MUX_CFG_01_mux_nd                (15)

#define PARAMSET_ROIC_SYS_DUMMY0_sys_dummy0                 (0)

#define PARAMSET_ROIC_SYS_DUMMY1_sys_dummy1                 (0xFFFFFFFF)


#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01			(1)//(1)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02			(2)//(2)

#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03			(3)//(3)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04			(4)//(4)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05			(5)//(5)

#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06			(6)//(6)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07			(7)//(7)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08			(8)//(8)

#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09			(9)//(9)

#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_10			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_11			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_12			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_13			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_14			(0)
#define PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_15			(0)

#if USED_RAWDATA_TUNE_CALIBRATION
#define PARAMSET_ROIC_CR_OFFSET		(0)
	#define PARAMSET_ROIC_0_R0_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R0_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R0_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R0_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R0_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R0_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R0_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R0_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R0_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R0_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R1_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_1stMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_1stMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_1stMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R1_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_2ndMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_2ndMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_2ndMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R1_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_3rdMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_3rdMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_3rdMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R1_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_4thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_4thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_4thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R1_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_5thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_5thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_5thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R1_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_6thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_6thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_6thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R1_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_7thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_7thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_7thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R1_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_8thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_8thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_8thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R1_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_9thMux_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_9thMux_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_9thMux_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)

	#define PARAMSET_ROIC_0_R1_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_LastMux_Top_Line_g1				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_LastMux_Top_Line_g2				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_LastMux_Top_Line_g3				(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g1			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g2			(0x0+PARAMSET_ROIC_CR_OFFSET)
	#define PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g3			(0x0+PARAMSET_ROIC_CR_OFFSET)
#else /* USED_RAWDATA_TUNE_CALIBRATION */
#if 1	//	Dell 23.8" Value
	#define PARAMSET_ROIC_0_R0_1stMux_Top_Line_g1	(16)
	#define PARAMSET_ROIC_0_R0_1stMux_Top_Line_g2	(16)
	#define PARAMSET_ROIC_0_R0_1stMux_Top_Line_g3	(16)
	#define PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g1	(17)
	#define PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g2	(17)
	#define PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g3	(16)
	#define PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g1	(15)
	#define PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g2	(17)
	#define PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g3	(18)
	#define PARAMSET_ROIC_1_R0_1stMux_Top_Line_g1	(16)
	#define PARAMSET_ROIC_1_R0_1stMux_Top_Line_g2	(15)
	#define PARAMSET_ROIC_1_R0_1stMux_Top_Line_g3	(15)
	#define PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g1	(16)
	#define PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g2	(16)
	#define PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g3	(16)
	#define PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g1	(14)
	#define PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g2	(15)
	#define PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g3	(15)
	#define PARAMSET_ROIC_2_R0_1stMux_Top_Line_g1	(14)
	#define PARAMSET_ROIC_2_R0_1stMux_Top_Line_g2	(14)
	#define PARAMSET_ROIC_2_R0_1stMux_Top_Line_g3	(15)
	#define PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g1	(16)
	#define PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g2	(15)
	#define PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g3	(15)
	#define PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g1	(14)
	#define PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g2	(14)
	#define PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g3	(14)
	#define PARAMSET_ROIC_3_R0_1stMux_Top_Line_g1	(15)
	#define PARAMSET_ROIC_3_R0_1stMux_Top_Line_g2	(15)
	#define PARAMSET_ROIC_3_R0_1stMux_Top_Line_g3	(15)
	#define PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g1	(15)
	#define PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g2	(15)
	#define PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g3	(15)
	#define PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g1	(15)
	#define PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g2	(14)
	#define PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g3	(16)
	#define PARAMSET_ROIC_4_R0_1stMux_Top_Line_g1	(16)
	#define PARAMSET_ROIC_4_R0_1stMux_Top_Line_g2	(15)
	#define PARAMSET_ROIC_4_R0_1stMux_Top_Line_g3	(15)
	#define PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g1	(16)
	#define PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g2	(16)
	#define PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g3	(15)
	#define PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g1	(15)
	#define PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g2	(15)
	#define PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g3	(15)
	#define PARAMSET_ROIC_5_R0_1stMux_Top_Line_g1	(16)
	#define PARAMSET_ROIC_5_R0_1stMux_Top_Line_g2	(16)
	#define PARAMSET_ROIC_5_R0_1stMux_Top_Line_g3	(15)
	#define PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g1	(17)
	#define PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g2	(16)
	#define PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g3	(15)
	#define PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g1	(14)
	#define PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g2	(15)
	#define PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g3	(15)
	#define PARAMSET_ROIC_6_R0_1stMux_Top_Line_g1	(17)
	#define PARAMSET_ROIC_6_R0_1stMux_Top_Line_g2	(16)
	#define PARAMSET_ROIC_6_R0_1stMux_Top_Line_g3	(15)
	#define PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g1	(18)
	#define PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g2	(17)
	#define PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g3	(16)
	#define PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g1	(17)
	#define PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g2	(16)
	#define PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g3	(16)
	#define PARAMSET_ROIC_7_R0_1stMux_Top_Line_g1	(16)
	#define PARAMSET_ROIC_7_R0_1stMux_Top_Line_g2	(19)
	#define PARAMSET_ROIC_7_R0_1stMux_Top_Line_g3	(18)
	#define PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g1	(19)
	#define PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g2	(19)
	#define PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g3	(19)
	#define PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g1	(21)
	#define PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g2	(21)
	#define PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g3	(19)

	#define PARAMSET_ROIC_0_R0_2ndMux_g1	(16)
	#define PARAMSET_ROIC_0_R0_2ndMux_g2	(16)
	#define PARAMSET_ROIC_0_R0_2ndMux_g3	(15)
	#define PARAMSET_ROIC_1_R0_2ndMux_g1	(15)
	#define PARAMSET_ROIC_1_R0_2ndMux_g2	(15)
	#define PARAMSET_ROIC_1_R0_2ndMux_g3	(15)
	#define PARAMSET_ROIC_2_R0_2ndMux_g1	(15)
	#define PARAMSET_ROIC_2_R0_2ndMux_g2	(14)
	#define PARAMSET_ROIC_2_R0_2ndMux_g3	(14)
	#define PARAMSET_ROIC_3_R0_2ndMux_g1	(15)
	#define PARAMSET_ROIC_3_R0_2ndMux_g2	(14)
	#define PARAMSET_ROIC_3_R0_2ndMux_g3	(15)
	#define PARAMSET_ROIC_4_R0_2ndMux_g1	(15)
	#define PARAMSET_ROIC_4_R0_2ndMux_g2	(15)
	#define PARAMSET_ROIC_4_R0_2ndMux_g3	(14)
	#define PARAMSET_ROIC_5_R0_2ndMux_g1	(15)
	#define PARAMSET_ROIC_5_R0_2ndMux_g2	(15)
	#define PARAMSET_ROIC_5_R0_2ndMux_g3	(14)
	#define PARAMSET_ROIC_6_R0_2ndMux_g1	(17)
	#define PARAMSET_ROIC_6_R0_2ndMux_g2	(16)
	#define PARAMSET_ROIC_6_R0_2ndMux_g3	(15)
	#define PARAMSET_ROIC_7_R0_2ndMux_g1	(15)
	#define PARAMSET_ROIC_7_R0_2ndMux_g2	(16)
	#define PARAMSET_ROIC_7_R0_2ndMux_g3	(16)

	#define PARAMSET_ROIC_0_R0_3rdMux_g1	(15)
	#define PARAMSET_ROIC_0_R0_3rdMux_g2	(14)
	#define PARAMSET_ROIC_0_R0_3rdMux_g3	(13)
	#define PARAMSET_ROIC_1_R0_3rdMux_g1	(14)
	#define PARAMSET_ROIC_1_R0_3rdMux_g2	(14)
	#define PARAMSET_ROIC_1_R0_3rdMux_g3	(14)
	#define PARAMSET_ROIC_2_R0_3rdMux_g1	(14)
	#define PARAMSET_ROIC_2_R0_3rdMux_g2	(13)
	#define PARAMSET_ROIC_2_R0_3rdMux_g3	(13)
	#define PARAMSET_ROIC_3_R0_3rdMux_g1	(14)
	#define PARAMSET_ROIC_3_R0_3rdMux_g2	(13)
	#define PARAMSET_ROIC_3_R0_3rdMux_g3	(14)
	#define PARAMSET_ROIC_4_R0_3rdMux_g1	(14)
	#define PARAMSET_ROIC_4_R0_3rdMux_g2	(14)
	#define PARAMSET_ROIC_4_R0_3rdMux_g3	(13)
	#define PARAMSET_ROIC_5_R0_3rdMux_g1	(15)
	#define PARAMSET_ROIC_5_R0_3rdMux_g2	(14)
	#define PARAMSET_ROIC_5_R0_3rdMux_g3	(14)
	#define PARAMSET_ROIC_6_R0_3rdMux_g1	(16)
	#define PARAMSET_ROIC_6_R0_3rdMux_g2	(15)
	#define PARAMSET_ROIC_6_R0_3rdMux_g3	(14)
	#define PARAMSET_ROIC_7_R0_3rdMux_g1	(14)
	#define PARAMSET_ROIC_7_R0_3rdMux_g2	(15)
	#define PARAMSET_ROIC_7_R0_3rdMux_g3	(15)

	#define PARAMSET_ROIC_0_R0_4thMux_g1	(14)
	#define PARAMSET_ROIC_0_R0_4thMux_g2	(13)
	#define PARAMSET_ROIC_0_R0_4thMux_g3	(13)
	#define PARAMSET_ROIC_1_R0_4thMux_g1	(13)
	#define PARAMSET_ROIC_1_R0_4thMux_g2	(13)
	#define PARAMSET_ROIC_1_R0_4thMux_g3	(13)
	#define PARAMSET_ROIC_2_R0_4thMux_g1	(13)
	#define PARAMSET_ROIC_2_R0_4thMux_g2	(12)
	#define PARAMSET_ROIC_2_R0_4thMux_g3	(13)
	#define PARAMSET_ROIC_3_R0_4thMux_g1	(13)
	#define PARAMSET_ROIC_3_R0_4thMux_g2	(13)
	#define PARAMSET_ROIC_3_R0_4thMux_g3	(13)
	#define PARAMSET_ROIC_4_R0_4thMux_g1	(14)
	#define PARAMSET_ROIC_4_R0_4thMux_g2	(13)
	#define PARAMSET_ROIC_4_R0_4thMux_g3	(13)
	#define PARAMSET_ROIC_5_R0_4thMux_g1	(14)
	#define PARAMSET_ROIC_5_R0_4thMux_g2	(14)
	#define PARAMSET_ROIC_5_R0_4thMux_g3	(13)
	#define PARAMSET_ROIC_6_R0_4thMux_g1	(15)
	#define PARAMSET_ROIC_6_R0_4thMux_g2	(14)
	#define PARAMSET_ROIC_6_R0_4thMux_g3	(13)
	#define PARAMSET_ROIC_7_R0_4thMux_g1	(13)
	#define PARAMSET_ROIC_7_R0_4thMux_g2	(14)
	#define PARAMSET_ROIC_7_R0_4thMux_g3	(14)

	#define PARAMSET_ROIC_0_R0_5thMux_g1	(13)
	#define PARAMSET_ROIC_0_R0_5thMux_g2	(13)
	#define PARAMSET_ROIC_0_R0_5thMux_g3	(12)
	#define PARAMSET_ROIC_1_R0_5thMux_g1	(13)
	#define PARAMSET_ROIC_1_R0_5thMux_g2	(12)
	#define PARAMSET_ROIC_1_R0_5thMux_g3	(12)
	#define PARAMSET_ROIC_2_R0_5thMux_g1	(13)
	#define PARAMSET_ROIC_2_R0_5thMux_g2	(12)
	#define PARAMSET_ROIC_2_R0_5thMux_g3	(12)
	#define PARAMSET_ROIC_3_R0_5thMux_g1	(13)
	#define PARAMSET_ROIC_3_R0_5thMux_g2	(12)
	#define PARAMSET_ROIC_3_R0_5thMux_g3	(13)
	#define PARAMSET_ROIC_4_R0_5thMux_g1	(13)
	#define PARAMSET_ROIC_4_R0_5thMux_g2	(13)
	#define PARAMSET_ROIC_4_R0_5thMux_g3	(12)
	#define PARAMSET_ROIC_5_R0_5thMux_g1	(13)
	#define PARAMSET_ROIC_5_R0_5thMux_g2	(13)
	#define PARAMSET_ROIC_5_R0_5thMux_g3	(12)
	#define PARAMSET_ROIC_6_R0_5thMux_g1	(14)
	#define PARAMSET_ROIC_6_R0_5thMux_g2	(13)
	#define PARAMSET_ROIC_6_R0_5thMux_g3	(13)
	#define PARAMSET_ROIC_7_R0_5thMux_g1	(13)
	#define PARAMSET_ROIC_7_R0_5thMux_g2	(13)
	#define PARAMSET_ROIC_7_R0_5thMux_g3	(13)

	#define PARAMSET_ROIC_0_R0_6thMux_g1	(12)
	#define PARAMSET_ROIC_0_R0_6thMux_g2	(12)
	#define PARAMSET_ROIC_0_R0_6thMux_g3	(12)
	#define PARAMSET_ROIC_1_R0_6thMux_g1	(12)
	#define PARAMSET_ROIC_1_R0_6thMux_g2	(12)
	#define PARAMSET_ROIC_1_R0_6thMux_g3	(12)
	#define PARAMSET_ROIC_2_R0_6thMux_g1	(12)
	#define PARAMSET_ROIC_2_R0_6thMux_g2	(12)
	#define PARAMSET_ROIC_2_R0_6thMux_g3	(12)
	#define PARAMSET_ROIC_3_R0_6thMux_g1	(12)
	#define PARAMSET_ROIC_3_R0_6thMux_g2	(12)
	#define PARAMSET_ROIC_3_R0_6thMux_g3	(12)
	#define PARAMSET_ROIC_4_R0_6thMux_g1	(13)
	#define PARAMSET_ROIC_4_R0_6thMux_g2	(12)
	#define PARAMSET_ROIC_4_R0_6thMux_g3	(12)
	#define PARAMSET_ROIC_5_R0_6thMux_g1	(13)
	#define PARAMSET_ROIC_5_R0_6thMux_g2	(13)
	#define PARAMSET_ROIC_5_R0_6thMux_g3	(12)
	#define PARAMSET_ROIC_6_R0_6thMux_g1	(13)
	#define PARAMSET_ROIC_6_R0_6thMux_g2	(13)
	#define PARAMSET_ROIC_6_R0_6thMux_g3	(12)
	#define PARAMSET_ROIC_7_R0_6thMux_g1	(12)
	#define PARAMSET_ROIC_7_R0_6thMux_g2	(13)
	#define PARAMSET_ROIC_7_R0_6thMux_g3	(13)

	#define PARAMSET_ROIC_0_R0_7thMux_g1	(12)
	#define PARAMSET_ROIC_0_R0_7thMux_g2	(12)
	#define PARAMSET_ROIC_0_R0_7thMux_g3	(11)
	#define PARAMSET_ROIC_1_R0_7thMux_g1	(12)
	#define PARAMSET_ROIC_1_R0_7thMux_g2	(12)
	#define PARAMSET_ROIC_1_R0_7thMux_g3	(12)
	#define PARAMSET_ROIC_2_R0_7thMux_g1	(12)
	#define PARAMSET_ROIC_2_R0_7thMux_g2	(11)
	#define PARAMSET_ROIC_2_R0_7thMux_g3	(12)
	#define PARAMSET_ROIC_3_R0_7thMux_g1	(12)
	#define PARAMSET_ROIC_3_R0_7thMux_g2	(12)
	#define PARAMSET_ROIC_3_R0_7thMux_g3	(12)
	#define PARAMSET_ROIC_4_R0_7thMux_g1	(12)
	#define PARAMSET_ROIC_4_R0_7thMux_g2	(12)
	#define PARAMSET_ROIC_4_R0_7thMux_g3	(12)
	#define PARAMSET_ROIC_5_R0_7thMux_g1	(12)
	#define PARAMSET_ROIC_5_R0_7thMux_g2	(12)
	#define PARAMSET_ROIC_5_R0_7thMux_g3	(12)
	#define PARAMSET_ROIC_6_R0_7thMux_g1	(13)
	#define PARAMSET_ROIC_6_R0_7thMux_g2	(12)
	#define PARAMSET_ROIC_6_R0_7thMux_g3	(12)
	#define PARAMSET_ROIC_7_R0_7thMux_g1	(12)
	#define PARAMSET_ROIC_7_R0_7thMux_g2	(12)
	#define PARAMSET_ROIC_7_R0_7thMux_g3	(12)

	#define PARAMSET_ROIC_0_R0_8thMux_g1	(12)
	#define PARAMSET_ROIC_0_R0_8thMux_g2	(12)
	#define PARAMSET_ROIC_0_R0_8thMux_g3	(11)
	#define PARAMSET_ROIC_1_R0_8thMux_g1	(12)
	#define PARAMSET_ROIC_1_R0_8thMux_g2	(11)
	#define PARAMSET_ROIC_1_R0_8thMux_g3	(11)
	#define PARAMSET_ROIC_2_R0_8thMux_g1	(12)
	#define PARAMSET_ROIC_2_R0_8thMux_g2	(11)
	#define PARAMSET_ROIC_2_R0_8thMux_g3	(11)
	#define PARAMSET_ROIC_3_R0_8thMux_g1	(12)
	#define PARAMSET_ROIC_3_R0_8thMux_g2	(11)
	#define PARAMSET_ROIC_3_R0_8thMux_g3	(12)
	#define PARAMSET_ROIC_4_R0_8thMux_g1	(12)
	#define PARAMSET_ROIC_4_R0_8thMux_g2	(12)
	#define PARAMSET_ROIC_4_R0_8thMux_g3	(11)
	#define PARAMSET_ROIC_5_R0_8thMux_g1	(12)
	#define PARAMSET_ROIC_5_R0_8thMux_g2	(12)
	#define PARAMSET_ROIC_5_R0_8thMux_g3	(11)
	#define PARAMSET_ROIC_6_R0_8thMux_g1	(12)
	#define PARAMSET_ROIC_6_R0_8thMux_g2	(12)
	#define PARAMSET_ROIC_6_R0_8thMux_g3	(12)
	#define PARAMSET_ROIC_7_R0_8thMux_g1	(12)
	#define PARAMSET_ROIC_7_R0_8thMux_g2	(12)
	#define PARAMSET_ROIC_7_R0_8thMux_g3	(12)

	#define PARAMSET_ROIC_0_R0_9thMux_g1	(0)
	#define PARAMSET_ROIC_0_R0_9thMux_g2	(0)
	#define PARAMSET_ROIC_0_R0_9thMux_g3	(0)
	#define PARAMSET_ROIC_1_R0_9thMux_g1	(0)
	#define PARAMSET_ROIC_1_R0_9thMux_g2	(0)
	#define PARAMSET_ROIC_1_R0_9thMux_g3	(0)
	#define PARAMSET_ROIC_2_R0_9thMux_g1	(0)
	#define PARAMSET_ROIC_2_R0_9thMux_g2	(0)
	#define PARAMSET_ROIC_2_R0_9thMux_g3	(0)
	#define PARAMSET_ROIC_3_R0_9thMux_g1	(0)
	#define PARAMSET_ROIC_3_R0_9thMux_g2	(0)
	#define PARAMSET_ROIC_3_R0_9thMux_g3	(0)
	#define PARAMSET_ROIC_4_R0_9thMux_g1	(0)
	#define PARAMSET_ROIC_4_R0_9thMux_g2	(0)
	#define PARAMSET_ROIC_4_R0_9thMux_g3	(0)
	#define PARAMSET_ROIC_5_R0_9thMux_g1	(0)
	#define PARAMSET_ROIC_5_R0_9thMux_g2	(0)
	#define PARAMSET_ROIC_5_R0_9thMux_g3	(0)
	#define PARAMSET_ROIC_6_R0_9thMux_g1	(0)
	#define PARAMSET_ROIC_6_R0_9thMux_g2	(0)
	#define PARAMSET_ROIC_6_R0_9thMux_g3	(0)
	#define PARAMSET_ROIC_7_R0_9thMux_g1	(0)
	#define PARAMSET_ROIC_7_R0_9thMux_g2	(0)
	#define PARAMSET_ROIC_7_R0_9thMux_g3	(0)

	#define PARAMSET_ROIC_0_R0_LastMux_Top_Line_g1	(9)
	#define PARAMSET_ROIC_0_R0_LastMux_Top_Line_g2	(9)
	#define PARAMSET_ROIC_0_R0_LastMux_Top_Line_g3	(8)
	#define PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g2	(11)
	#define PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g3	(11)
	#define PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g1	(11)
	#define PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g2	(12)
	#define PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g3	(11)
	#define PARAMSET_ROIC_1_R0_LastMux_Top_Line_g1	(9)
	#define PARAMSET_ROIC_1_R0_LastMux_Top_Line_g2	(8)
	#define PARAMSET_ROIC_1_R0_LastMux_Top_Line_g3	(9)
	#define PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g1	(11)
	#define PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g2	(11)
	#define PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g3	(11)
	#define PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g1	(11)
	#define PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g2	(11)
	#define PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g3	(11)
	#define PARAMSET_ROIC_2_R0_LastMux_Top_Line_g1	(8)
	#define PARAMSET_ROIC_2_R0_LastMux_Top_Line_g2	(8)
	#define PARAMSET_ROIC_2_R0_LastMux_Top_Line_g3	(9)
	#define PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g2	(11)
	#define PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g3	(11)
	#define PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g1	(12)
	#define PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g2	(11)
	#define PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g3	(11)
	#define PARAMSET_ROIC_3_R0_LastMux_Top_Line_g1	(9)
	#define PARAMSET_ROIC_3_R0_LastMux_Top_Line_g2	(9)
	#define PARAMSET_ROIC_3_R0_LastMux_Top_Line_g3	(9)
	#define PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g2	(11)
	#define PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g3	(11)
	#define PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g1	(12)
	#define PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g2	(11)
	#define PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g3	(12)
	#define PARAMSET_ROIC_4_R0_LastMux_Top_Line_g1	(9)
	#define PARAMSET_ROIC_4_R0_LastMux_Top_Line_g2	(9)
	#define PARAMSET_ROIC_4_R0_LastMux_Top_Line_g3	(9)
	#define PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g2	(12)
	#define PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g3	(11)
	#define PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g1	(12)
	#define PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g2	(12)
	#define PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g3	(11)
	#define PARAMSET_ROIC_5_R0_LastMux_Top_Line_g1	(9)
	#define PARAMSET_ROIC_5_R0_LastMux_Top_Line_g2	(9)
	#define PARAMSET_ROIC_5_R0_LastMux_Top_Line_g3	(9)
	#define PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g2	(12)
	#define PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g3	(11)
	#define PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g1	(11)
	#define PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g2	(12)
	#define PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g3	(11)
	#define PARAMSET_ROIC_6_R0_LastMux_Top_Line_g1	(10)
	#define PARAMSET_ROIC_6_R0_LastMux_Top_Line_g2	(9)
	#define PARAMSET_ROIC_6_R0_LastMux_Top_Line_g3	(9)
	#define PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g2	(12)
	#define PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g3	(12)
	#define PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g1	(12)
	#define PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g2	(12)
	#define PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g3	(11)
	#define PARAMSET_ROIC_7_R0_LastMux_Top_Line_g1	(9)
	#define PARAMSET_ROIC_7_R0_LastMux_Top_Line_g2	(10)
	#define PARAMSET_ROIC_7_R0_LastMux_Top_Line_g3	(10)
	#define PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g2	(12)
	#define PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g3	(12)
	#define PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g1	(12)
	#define PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g2	(12)
	#define PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g3	(12)

	#define PARAMSET_ROIC_0_R1_1stMux_Top_Line_g1	(16)
	#define PARAMSET_ROIC_0_R1_1stMux_Top_Line_g2	(16)
	#define PARAMSET_ROIC_0_R1_1stMux_Top_Line_g3	(16)
	#define PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g1	(18)
	#define PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g2	(18)
	#define PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g3	(17)
	#define PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g1	(19)
	#define PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g2	(19)
	#define PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g3	(18)
	#define PARAMSET_ROIC_1_R1_1stMux_Top_Line_g1	(17)
	#define PARAMSET_ROIC_1_R1_1stMux_Top_Line_g2	(16)
	#define PARAMSET_ROIC_1_R1_1stMux_Top_Line_g3	(16)
	#define PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g1	(17)
	#define PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g2	(16)
	#define PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g3	(16)
	#define PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g1	(15)
	#define PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g2	(16)
	#define PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g3	(17)
	#define PARAMSET_ROIC_2_R1_1stMux_Top_Line_g1	(16)
	#define PARAMSET_ROIC_2_R1_1stMux_Top_Line_g2	(15)
	#define PARAMSET_ROIC_2_R1_1stMux_Top_Line_g3	(15)
	#define PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g1	(16)
	#define PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g2	(15)
	#define PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g3	(15)
	#define PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g1	(15)
	#define PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g2	(15)
	#define PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g3	(15)
	#define PARAMSET_ROIC_3_R1_1stMux_Top_Line_g1	(15)
	#define PARAMSET_ROIC_3_R1_1stMux_Top_Line_g2	(14)
	#define PARAMSET_ROIC_3_R1_1stMux_Top_Line_g3	(14)
	#define PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g1	(15)
	#define PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g2	(15)
	#define PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g3	(14)
	#define PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g1	(14)
	#define PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g2	(14)
	#define PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g3	(15)
	#define PARAMSET_ROIC_4_R1_1stMux_Top_Line_g1	(16)
	#define PARAMSET_ROIC_4_R1_1stMux_Top_Line_g2	(15)
	#define PARAMSET_ROIC_4_R1_1stMux_Top_Line_g3	(16)
	#define PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g1	(16)
	#define PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g2	(16)
	#define PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g3	(15)
	#define PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g1	(15)
	#define PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g2	(15)
	#define PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g3	(16)
	#define PARAMSET_ROIC_5_R1_1stMux_Top_Line_g1	(17)
	#define PARAMSET_ROIC_5_R1_1stMux_Top_Line_g2	(15)
	#define PARAMSET_ROIC_5_R1_1stMux_Top_Line_g3	(15)
	#define PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g1	(16)
	#define PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g2	(15)
	#define PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g3	(16)
	#define PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g1	(14)
	#define PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g2	(15)
	#define PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g3	(17)
	#define PARAMSET_ROIC_6_R1_1stMux_Top_Line_g1	(15)
	#define PARAMSET_ROIC_6_R1_1stMux_Top_Line_g2	(16)
	#define PARAMSET_ROIC_6_R1_1stMux_Top_Line_g3	(16)
	#define PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g1	(16)
	#define PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g2	(16)
	#define PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g3	(17)
	#define PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g1	(16)
	#define PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g2	(16)
	#define PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g3	(17)
	#define PARAMSET_ROIC_7_R1_1stMux_Top_Line_g1	(17)
	#define PARAMSET_ROIC_7_R1_1stMux_Top_Line_g2	(17)
	#define PARAMSET_ROIC_7_R1_1stMux_Top_Line_g3	(18)
	#define PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g1	(18)
	#define PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g2	(18)
	#define PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g3	(18)
	#define PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g1	(18)
	#define PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g2	(18)
	#define PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g3	(19)

	#define PARAMSET_ROIC_0_R1_2ndMux_g1	(15)
	#define PARAMSET_ROIC_0_R1_2ndMux_g2	(16)
	#define PARAMSET_ROIC_0_R1_2ndMux_g3	(15)
	#define PARAMSET_ROIC_1_R1_2ndMux_g1	(16)
	#define PARAMSET_ROIC_1_R1_2ndMux_g2	(15)
	#define PARAMSET_ROIC_1_R1_2ndMux_g3	(15)
	#define PARAMSET_ROIC_2_R1_2ndMux_g1	(15)
	#define PARAMSET_ROIC_2_R1_2ndMux_g2	(15)
	#define PARAMSET_ROIC_2_R1_2ndMux_g3	(14)
	#define PARAMSET_ROIC_3_R1_2ndMux_g1	(15)
	#define PARAMSET_ROIC_3_R1_2ndMux_g2	(14)
	#define PARAMSET_ROIC_3_R1_2ndMux_g3	(14)
	#define PARAMSET_ROIC_4_R1_2ndMux_g1	(15)
	#define PARAMSET_ROIC_4_R1_2ndMux_g2	(15)
	#define PARAMSET_ROIC_4_R1_2ndMux_g3	(15)
	#define PARAMSET_ROIC_5_R1_2ndMux_g1	(15)
	#define PARAMSET_ROIC_5_R1_2ndMux_g2	(15)
	#define PARAMSET_ROIC_5_R1_2ndMux_g3	(15)
	#define PARAMSET_ROIC_6_R1_2ndMux_g1	(16)
	#define PARAMSET_ROIC_6_R1_2ndMux_g2	(15)
	#define PARAMSET_ROIC_6_R1_2ndMux_g3	(16)
	#define PARAMSET_ROIC_7_R1_2ndMux_g1	(17)
	#define PARAMSET_ROIC_7_R1_2ndMux_g2	(17)
	#define PARAMSET_ROIC_7_R1_2ndMux_g3	(16)

	#define PARAMSET_ROIC_0_R1_3rdMux_g1	(14)
	#define PARAMSET_ROIC_0_R1_3rdMux_g2	(14)
	#define PARAMSET_ROIC_0_R1_3rdMux_g3	(14)
	#define PARAMSET_ROIC_1_R1_3rdMux_g1	(15)
	#define PARAMSET_ROIC_1_R1_3rdMux_g2	(14)
	#define PARAMSET_ROIC_1_R1_3rdMux_g3	(14)
	#define PARAMSET_ROIC_2_R1_3rdMux_g1	(15)
	#define PARAMSET_ROIC_2_R1_3rdMux_g2	(14)
	#define PARAMSET_ROIC_2_R1_3rdMux_g3	(13)
	#define PARAMSET_ROIC_3_R1_3rdMux_g1	(14)
	#define PARAMSET_ROIC_3_R1_3rdMux_g2	(13)
	#define PARAMSET_ROIC_3_R1_3rdMux_g3	(13)
	#define PARAMSET_ROIC_4_R1_3rdMux_g1	(14)
	#define PARAMSET_ROIC_4_R1_3rdMux_g2	(14)
	#define PARAMSET_ROIC_4_R1_3rdMux_g3	(14)
	#define PARAMSET_ROIC_5_R1_3rdMux_g1	(14)
	#define PARAMSET_ROIC_5_R1_3rdMux_g2	(14)
	#define PARAMSET_ROIC_5_R1_3rdMux_g3	(14)
	#define PARAMSET_ROIC_6_R1_3rdMux_g1	(15)
	#define PARAMSET_ROIC_6_R1_3rdMux_g2	(14)
	#define PARAMSET_ROIC_6_R1_3rdMux_g3	(15)
	#define PARAMSET_ROIC_7_R1_3rdMux_g1	(16)
	#define PARAMSET_ROIC_7_R1_3rdMux_g2	(15)
	#define PARAMSET_ROIC_7_R1_3rdMux_g3	(15)

	#define PARAMSET_ROIC_0_R1_4thMux_g1	(13)
	#define PARAMSET_ROIC_0_R1_4thMux_g2	(13)
	#define PARAMSET_ROIC_0_R1_4thMux_g3	(13)
	#define PARAMSET_ROIC_1_R1_4thMux_g1	(14)
	#define PARAMSET_ROIC_1_R1_4thMux_g2	(13)
	#define PARAMSET_ROIC_1_R1_4thMux_g3	(13)
	#define PARAMSET_ROIC_2_R1_4thMux_g1	(14)
	#define PARAMSET_ROIC_2_R1_4thMux_g2	(13)
	#define PARAMSET_ROIC_2_R1_4thMux_g3	(13)
	#define PARAMSET_ROIC_3_R1_4thMux_g1	(13)
	#define PARAMSET_ROIC_3_R1_4thMux_g2	(13)
	#define PARAMSET_ROIC_3_R1_4thMux_g3	(12)
	#define PARAMSET_ROIC_4_R1_4thMux_g1	(14)
	#define PARAMSET_ROIC_4_R1_4thMux_g2	(13)
	#define PARAMSET_ROIC_4_R1_4thMux_g3	(14)
	#define PARAMSET_ROIC_5_R1_4thMux_g1	(14)
	#define PARAMSET_ROIC_5_R1_4thMux_g2	(13)
	#define PARAMSET_ROIC_5_R1_4thMux_g3	(13)
	#define PARAMSET_ROIC_6_R1_4thMux_g1	(14)
	#define PARAMSET_ROIC_6_R1_4thMux_g2	(14)
	#define PARAMSET_ROIC_6_R1_4thMux_g3	(14)
	#define PARAMSET_ROIC_7_R1_4thMux_g1	(15)
	#define PARAMSET_ROIC_7_R1_4thMux_g2	(15)
	#define PARAMSET_ROIC_7_R1_4thMux_g3	(14)

	#define PARAMSET_ROIC_0_R1_5thMux_g1	(12)
	#define PARAMSET_ROIC_0_R1_5thMux_g2	(12)
	#define PARAMSET_ROIC_0_R1_5thMux_g3	(12)
	#define PARAMSET_ROIC_1_R1_5thMux_g1	(13)
	#define PARAMSET_ROIC_1_R1_5thMux_g2	(13)
	#define PARAMSET_ROIC_1_R1_5thMux_g3	(13)
	#define PARAMSET_ROIC_2_R1_5thMux_g1	(13)
	#define PARAMSET_ROIC_2_R1_5thMux_g2	(13)
	#define PARAMSET_ROIC_2_R1_5thMux_g3	(12)
	#define PARAMSET_ROIC_3_R1_5thMux_g1	(13)
	#define PARAMSET_ROIC_3_R1_5thMux_g2	(12)
	#define PARAMSET_ROIC_3_R1_5thMux_g3	(12)
	#define PARAMSET_ROIC_4_R1_5thMux_g1	(13)
	#define PARAMSET_ROIC_4_R1_5thMux_g2	(13)
	#define PARAMSET_ROIC_4_R1_5thMux_g3	(13)
	#define PARAMSET_ROIC_5_R1_5thMux_g1	(13)
	#define PARAMSET_ROIC_5_R1_5thMux_g2	(13)
	#define PARAMSET_ROIC_5_R1_5thMux_g3	(13)
	#define PARAMSET_ROIC_6_R1_5thMux_g1	(14)
	#define PARAMSET_ROIC_6_R1_5thMux_g2	(13)
	#define PARAMSET_ROIC_6_R1_5thMux_g3	(13)
	#define PARAMSET_ROIC_7_R1_5thMux_g1	(14)
	#define PARAMSET_ROIC_7_R1_5thMux_g2	(14)
	#define PARAMSET_ROIC_7_R1_5thMux_g3	(13)

	#define PARAMSET_ROIC_0_R1_6thMux_g1	(12)
	#define PARAMSET_ROIC_0_R1_6thMux_g2	(12)
	#define PARAMSET_ROIC_0_R1_6thMux_g3	(12)
	#define PARAMSET_ROIC_1_R1_6thMux_g1	(13)
	#define PARAMSET_ROIC_1_R1_6thMux_g2	(12)
	#define PARAMSET_ROIC_1_R1_6thMux_g3	(12)
	#define PARAMSET_ROIC_2_R1_6thMux_g1	(13)
	#define PARAMSET_ROIC_2_R1_6thMux_g2	(12)
	#define PARAMSET_ROIC_2_R1_6thMux_g3	(12)
	#define PARAMSET_ROIC_3_R1_6thMux_g1	(13)
	#define PARAMSET_ROIC_3_R1_6thMux_g2	(12)
	#define PARAMSET_ROIC_3_R1_6thMux_g3	(12)
	#define PARAMSET_ROIC_4_R1_6thMux_g1	(13)
	#define PARAMSET_ROIC_4_R1_6thMux_g2	(12)
	#define PARAMSET_ROIC_4_R1_6thMux_g3	(13)
	#define PARAMSET_ROIC_5_R1_6thMux_g1	(13)
	#define PARAMSET_ROIC_5_R1_6thMux_g2	(12)
	#define PARAMSET_ROIC_5_R1_6thMux_g3	(12)
	#define PARAMSET_ROIC_6_R1_6thMux_g1	(13)
	#define PARAMSET_ROIC_6_R1_6thMux_g2	(12)
	#define PARAMSET_ROIC_6_R1_6thMux_g3	(13)
	#define PARAMSET_ROIC_7_R1_6thMux_g1	(14)
	#define PARAMSET_ROIC_7_R1_6thMux_g2	(13)
	#define PARAMSET_ROIC_7_R1_6thMux_g3	(13)

	#define PARAMSET_ROIC_0_R1_7thMux_g1	(11)
	#define PARAMSET_ROIC_0_R1_7thMux_g2	(12)
	#define PARAMSET_ROIC_0_R1_7thMux_g3	(12)
	#define PARAMSET_ROIC_1_R1_7thMux_g1	(13)
	#define PARAMSET_ROIC_1_R1_7thMux_g2	(12)
	#define PARAMSET_ROIC_1_R1_7thMux_g3	(12)
	#define PARAMSET_ROIC_2_R1_7thMux_g1	(13)
	#define PARAMSET_ROIC_2_R1_7thMux_g2	(12)
	#define PARAMSET_ROIC_2_R1_7thMux_g3	(12)
	#define PARAMSET_ROIC_3_R1_7thMux_g1	(12)
	#define PARAMSET_ROIC_3_R1_7thMux_g2	(12)
	#define PARAMSET_ROIC_3_R1_7thMux_g3	(11)
	#define PARAMSET_ROIC_4_R1_7thMux_g1	(13)
	#define PARAMSET_ROIC_4_R1_7thMux_g2	(12)
	#define PARAMSET_ROIC_4_R1_7thMux_g3	(12)
	#define PARAMSET_ROIC_5_R1_7thMux_g1	(13)
	#define PARAMSET_ROIC_5_R1_7thMux_g2	(12)
	#define PARAMSET_ROIC_5_R1_7thMux_g3	(12)
	#define PARAMSET_ROIC_6_R1_7thMux_g1	(13)
	#define PARAMSET_ROIC_6_R1_7thMux_g2	(12)
	#define PARAMSET_ROIC_6_R1_7thMux_g3	(12)
	#define PARAMSET_ROIC_7_R1_7thMux_g1	(13)
	#define PARAMSET_ROIC_7_R1_7thMux_g2	(13)
	#define PARAMSET_ROIC_7_R1_7thMux_g3	(12)

	#define PARAMSET_ROIC_0_R1_8thMux_g1	(11)
	#define PARAMSET_ROIC_0_R1_8thMux_g2	(12)
	#define PARAMSET_ROIC_0_R1_8thMux_g3	(11)
	#define PARAMSET_ROIC_1_R1_8thMux_g1	(13)
	#define PARAMSET_ROIC_1_R1_8thMux_g2	(12)
	#define PARAMSET_ROIC_1_R1_8thMux_g3	(12)
	#define PARAMSET_ROIC_2_R1_8thMux_g1	(13)
	#define PARAMSET_ROIC_2_R1_8thMux_g2	(12)
	#define PARAMSET_ROIC_2_R1_8thMux_g3	(11)
	#define PARAMSET_ROIC_3_R1_8thMux_g1	(12)
	#define PARAMSET_ROIC_3_R1_8thMux_g2	(12)
	#define PARAMSET_ROIC_3_R1_8thMux_g3	(11)
	#define PARAMSET_ROIC_4_R1_8thMux_g1	(13)
	#define PARAMSET_ROIC_4_R1_8thMux_g2	(12)
	#define PARAMSET_ROIC_4_R1_8thMux_g3	(12)
	#define PARAMSET_ROIC_5_R1_8thMux_g1	(13)
	#define PARAMSET_ROIC_5_R1_8thMux_g2	(12)
	#define PARAMSET_ROIC_5_R1_8thMux_g3	(12)
	#define PARAMSET_ROIC_6_R1_8thMux_g1	(13)
	#define PARAMSET_ROIC_6_R1_8thMux_g2	(12)
	#define PARAMSET_ROIC_6_R1_8thMux_g3	(12)
	#define PARAMSET_ROIC_7_R1_8thMux_g1	(13)
	#define PARAMSET_ROIC_7_R1_8thMux_g2	(12)
	#define PARAMSET_ROIC_7_R1_8thMux_g3	(12)

	#define PARAMSET_ROIC_0_R1_9thMux_g1	(0)
	#define PARAMSET_ROIC_0_R1_9thMux_g2	(0)
	#define PARAMSET_ROIC_0_R1_9thMux_g3	(0)
	#define PARAMSET_ROIC_1_R1_9thMux_g1	(0)
	#define PARAMSET_ROIC_1_R1_9thMux_g2	(0)
	#define PARAMSET_ROIC_1_R1_9thMux_g3	(0)
	#define PARAMSET_ROIC_2_R1_9thMux_g1	(0)
	#define PARAMSET_ROIC_2_R1_9thMux_g2	(0)
	#define PARAMSET_ROIC_2_R1_9thMux_g3	(0)
	#define PARAMSET_ROIC_3_R1_9thMux_g1	(0)
	#define PARAMSET_ROIC_3_R1_9thMux_g2	(0)
	#define PARAMSET_ROIC_3_R1_9thMux_g3	(0)
	#define PARAMSET_ROIC_4_R1_9thMux_g1	(0)
	#define PARAMSET_ROIC_4_R1_9thMux_g2	(0)
	#define PARAMSET_ROIC_4_R1_9thMux_g3	(0)
	#define PARAMSET_ROIC_5_R1_9thMux_g1	(0)
	#define PARAMSET_ROIC_5_R1_9thMux_g2	(0)
	#define PARAMSET_ROIC_5_R1_9thMux_g3	(0)
	#define PARAMSET_ROIC_6_R1_9thMux_g1	(0)
	#define PARAMSET_ROIC_6_R1_9thMux_g2	(0)
	#define PARAMSET_ROIC_6_R1_9thMux_g3	(0)
	#define PARAMSET_ROIC_7_R1_9thMux_g1	(0)
	#define PARAMSET_ROIC_7_R1_9thMux_g2	(0)
	#define PARAMSET_ROIC_7_R1_9thMux_g3	(0)

	#define PARAMSET_ROIC_0_R1_LastMux_Top_Line_g1	(10)
	#define PARAMSET_ROIC_0_R1_LastMux_Top_Line_g2	(8)
	#define PARAMSET_ROIC_0_R1_LastMux_Top_Line_g3	(8)
	#define PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g2	(12)
	#define PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g3	(11)
	#define PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g1	(11)
	#define PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g2	(11)
	#define PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g3	(12)
	#define PARAMSET_ROIC_1_R1_LastMux_Top_Line_g1	(11)
	#define PARAMSET_ROIC_1_R1_LastMux_Top_Line_g2	(9)
	#define PARAMSET_ROIC_1_R1_LastMux_Top_Line_g3	(9)
	#define PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g2	(11)
	#define PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g3	(12)
	#define PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g1	(12)
	#define PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g2	(11)
	#define PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g3	(12)
	#define PARAMSET_ROIC_2_R1_LastMux_Top_Line_g1	(10)
	#define PARAMSET_ROIC_2_R1_LastMux_Top_Line_g2	(9)
	#define PARAMSET_ROIC_2_R1_LastMux_Top_Line_g3	(9)
	#define PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g2	(11)
	#define PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g3	(11)
	#define PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g1	(13)
	#define PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g2	(11)
	#define PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g3	(11)
	#define PARAMSET_ROIC_3_R1_LastMux_Top_Line_g1	(10)
	#define PARAMSET_ROIC_3_R1_LastMux_Top_Line_g2	(9)
	#define PARAMSET_ROIC_3_R1_LastMux_Top_Line_g3	(8)
	#define PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g2	(11)
	#define PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g3	(11)
	#define PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g1	(12)
	#define PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g2	(11)
	#define PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g3	(11)
	#define PARAMSET_ROIC_4_R1_LastMux_Top_Line_g1	(10)
	#define PARAMSET_ROIC_4_R1_LastMux_Top_Line_g2	(9)
	#define PARAMSET_ROIC_4_R1_LastMux_Top_Line_g3	(10)
	#define PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g1	(13)
	#define PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g2	(12)
	#define PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g3	(12)
	#define PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g1	(13)
	#define PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g2	(11)
	#define PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g3	(12)
	#define PARAMSET_ROIC_5_R1_LastMux_Top_Line_g1	(11)
	#define PARAMSET_ROIC_5_R1_LastMux_Top_Line_g2	(9)
	#define PARAMSET_ROIC_5_R1_LastMux_Top_Line_g3	(9)
	#define PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g1	(12)
	#define PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g2	(12)
	#define PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g3	(12)
	#define PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g1	(13)
	#define PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g2	(12)
	#define PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g3	(12)
	#define PARAMSET_ROIC_6_R1_LastMux_Top_Line_g1	(10)
	#define PARAMSET_ROIC_6_R1_LastMux_Top_Line_g2	(9)
	#define PARAMSET_ROIC_6_R1_LastMux_Top_Line_g3	(10)
	#define PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g1	(13)
	#define PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g2	(12)
	#define PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g3	(12)
	#define PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g1	(13)
	#define PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g2	(12)
	#define PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g3	(12)
	#define PARAMSET_ROIC_7_R1_LastMux_Top_Line_g1	(10)
	#define PARAMSET_ROIC_7_R1_LastMux_Top_Line_g2	(10)
	#define PARAMSET_ROIC_7_R1_LastMux_Top_Line_g3	(10)
	#define PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g1	(13)
	#define PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g2	(12)
	#define PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g3	(12)
	#define PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g1	(14)
	#define PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g2	(12)
	#define PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g3	(12)
#else
#define PARAMSET_ROIC_0_R0_1stMux_Top_Line_g1		(19)
#define PARAMSET_ROIC_0_R0_1stMux_Top_Line_g2		(19)
#define PARAMSET_ROIC_0_R0_1stMux_Top_Line_g3		(20)
#define PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g1	(19)
#define PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g2	(19)
#define PARAMSET_ROIC_0_R0_1stMux_Middle_Line_g3	(19)
#define PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g1	(21)
#define PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g2	(19)
#define PARAMSET_ROIC_0_R0_1stMux_Bottom_Line_g3	(18)
#define PARAMSET_ROIC_1_R0_1stMux_Top_Line_g1		(18)
#define PARAMSET_ROIC_1_R0_1stMux_Top_Line_g2		(18)
#define PARAMSET_ROIC_1_R0_1stMux_Top_Line_g3		(18)
#define PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g1	(18)
#define PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g2	(18)
#define PARAMSET_ROIC_1_R0_1stMux_Middle_Line_g3	(18)
#define PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g1	(20)
#define PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g2	(18)
#define PARAMSET_ROIC_1_R0_1stMux_Bottom_Line_g3	(18)
#define PARAMSET_ROIC_2_R0_1stMux_Top_Line_g1		(17)
#define PARAMSET_ROIC_2_R0_1stMux_Top_Line_g2		(17)
#define PARAMSET_ROIC_2_R0_1stMux_Top_Line_g3		(17)
#define PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g1	(17)
#define PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g2	(17)
#define PARAMSET_ROIC_2_R0_1stMux_Middle_Line_g3	(17)
#define PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g1	(24)
#define PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g2	(17)
#define PARAMSET_ROIC_2_R0_1stMux_Bottom_Line_g3	(17)
#define PARAMSET_ROIC_3_R0_1stMux_Top_Line_g1		(16)
#define PARAMSET_ROIC_3_R0_1stMux_Top_Line_g2		(16)
#define PARAMSET_ROIC_3_R0_1stMux_Top_Line_g3		(16)
#define PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g1	(16)
#define PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g2	(16)
#define PARAMSET_ROIC_3_R0_1stMux_Middle_Line_g3	(16)
#define PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g1	(18)
#define PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g2	(16)
#define PARAMSET_ROIC_3_R0_1stMux_Bottom_Line_g3	(17)
#define PARAMSET_ROIC_4_R0_1stMux_Top_Line_g1		(16)
#define PARAMSET_ROIC_4_R0_1stMux_Top_Line_g2		(15)
#define PARAMSET_ROIC_4_R0_1stMux_Top_Line_g3		(15)
#define PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g1	(15)
#define PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g2	(15)
#define PARAMSET_ROIC_4_R0_1stMux_Middle_Line_g3	(15)
#define PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g1	(17)
#define PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g2	(15)
#define PARAMSET_ROIC_4_R0_1stMux_Bottom_Line_g3	(15)
#define PARAMSET_ROIC_5_R0_1stMux_Top_Line_g1		(15)
#define PARAMSET_ROIC_5_R0_1stMux_Top_Line_g2		(14)
#define PARAMSET_ROIC_5_R0_1stMux_Top_Line_g3		(14)
#define PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g1	(15)
#define PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g2	(14)
#define PARAMSET_ROIC_5_R0_1stMux_Middle_Line_g3	(14)
#define PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g1	(16)
#define PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g2	(14)
#define PARAMSET_ROIC_5_R0_1stMux_Bottom_Line_g3	(14)
#define PARAMSET_ROIC_6_R0_1stMux_Top_Line_g1		(14)
#define PARAMSET_ROIC_6_R0_1stMux_Top_Line_g2		(14)
#define PARAMSET_ROIC_6_R0_1stMux_Top_Line_g3		(14)
#define PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g1	(14)
#define PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g2	(14)
#define PARAMSET_ROIC_6_R0_1stMux_Middle_Line_g3	(14)
#define PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g1	(21)
#define PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g2	(14)
#define PARAMSET_ROIC_6_R0_1stMux_Bottom_Line_g3	(14)
#define PARAMSET_ROIC_7_R0_1stMux_Top_Line_g1		(14)
#define PARAMSET_ROIC_7_R0_1stMux_Top_Line_g2		(14)
#define PARAMSET_ROIC_7_R0_1stMux_Top_Line_g3		(13)
#define PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g1	(14)
#define PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g2	(14)
#define PARAMSET_ROIC_7_R0_1stMux_Middle_Line_g3	(13)
#define PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g1	(16)
#define PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g2	(14)
#define PARAMSET_ROIC_7_R0_1stMux_Bottom_Line_g3	(14)

#define PARAMSET_ROIC_0_R0_2ndMux_g1				(19)
#define PARAMSET_ROIC_0_R0_2ndMux_g2				(19)
#define PARAMSET_ROIC_0_R0_2ndMux_g3				(19)
#define PARAMSET_ROIC_1_R0_2ndMux_g1				(18)
#define PARAMSET_ROIC_1_R0_2ndMux_g2				(18)
#define PARAMSET_ROIC_1_R0_2ndMux_g3				(18)
#define PARAMSET_ROIC_2_R0_2ndMux_g1				(17)
#define PARAMSET_ROIC_2_R0_2ndMux_g2				(17)
#define PARAMSET_ROIC_2_R0_2ndMux_g3				(17)
#define PARAMSET_ROIC_3_R0_2ndMux_g1				(16)
#define PARAMSET_ROIC_3_R0_2ndMux_g2				(16)
#define PARAMSET_ROIC_3_R0_2ndMux_g3				(16)
#define PARAMSET_ROIC_4_R0_2ndMux_g1				(15)
#define PARAMSET_ROIC_4_R0_2ndMux_g2				(15)
#define PARAMSET_ROIC_4_R0_2ndMux_g3				(15)
#define PARAMSET_ROIC_5_R0_2ndMux_g1				(14)
#define PARAMSET_ROIC_5_R0_2ndMux_g2				(14)
#define PARAMSET_ROIC_5_R0_2ndMux_g3				(14)
#define PARAMSET_ROIC_6_R0_2ndMux_g1				(14)
#define PARAMSET_ROIC_6_R0_2ndMux_g2				(14)
#define PARAMSET_ROIC_6_R0_2ndMux_g3				(13)
#define PARAMSET_ROIC_7_R0_2ndMux_g1				(14)
#define PARAMSET_ROIC_7_R0_2ndMux_g2				(13)
#define PARAMSET_ROIC_7_R0_2ndMux_g3				(13)

#define PARAMSET_ROIC_0_R0_3rdMux_g1				(19)
#define PARAMSET_ROIC_0_R0_3rdMux_g2				(19)
#define PARAMSET_ROIC_0_R0_3rdMux_g3				(19)
#define PARAMSET_ROIC_1_R0_3rdMux_g1				(18)
#define PARAMSET_ROIC_1_R0_3rdMux_g2				(18)
#define PARAMSET_ROIC_1_R0_3rdMux_g3				(18)
#define PARAMSET_ROIC_2_R0_3rdMux_g1				(17)
#define PARAMSET_ROIC_2_R0_3rdMux_g2				(17)
#define PARAMSET_ROIC_2_R0_3rdMux_g3				(17)
#define PARAMSET_ROIC_3_R0_3rdMux_g1				(16)
#define PARAMSET_ROIC_3_R0_3rdMux_g2				(16)
#define PARAMSET_ROIC_3_R0_3rdMux_g3				(16)
#define PARAMSET_ROIC_4_R0_3rdMux_g1				(15)
#define PARAMSET_ROIC_4_R0_3rdMux_g2				(15)
#define PARAMSET_ROIC_4_R0_3rdMux_g3				(15)
#define PARAMSET_ROIC_5_R0_3rdMux_g1				(14)
#define PARAMSET_ROIC_5_R0_3rdMux_g2				(14)
#define PARAMSET_ROIC_5_R0_3rdMux_g3				(14)
#define PARAMSET_ROIC_6_R0_3rdMux_g1				(13)
#define PARAMSET_ROIC_6_R0_3rdMux_g2				(14)
#define PARAMSET_ROIC_6_R0_3rdMux_g3				(14)
#define PARAMSET_ROIC_7_R0_3rdMux_g1				(14)
#define PARAMSET_ROIC_7_R0_3rdMux_g2				(13)
#define PARAMSET_ROIC_7_R0_3rdMux_g3				(13)

#define PARAMSET_ROIC_0_R0_4thMux_g1				(19)
#define PARAMSET_ROIC_0_R0_4thMux_g2				(19)
#define PARAMSET_ROIC_0_R0_4thMux_g3				(19)
#define PARAMSET_ROIC_1_R0_4thMux_g1				(18)
#define PARAMSET_ROIC_1_R0_4thMux_g2				(18)
#define PARAMSET_ROIC_1_R0_4thMux_g3				(18)
#define PARAMSET_ROIC_2_R0_4thMux_g1				(17)
#define PARAMSET_ROIC_2_R0_4thMux_g2				(17)
#define PARAMSET_ROIC_2_R0_4thMux_g3				(17)
#define PARAMSET_ROIC_3_R0_4thMux_g1				(16)
#define PARAMSET_ROIC_3_R0_4thMux_g2				(16)
#define PARAMSET_ROIC_3_R0_4thMux_g3				(16)
#define PARAMSET_ROIC_4_R0_4thMux_g1				(15)
#define PARAMSET_ROIC_4_R0_4thMux_g2				(15)
#define PARAMSET_ROIC_4_R0_4thMux_g3				(15)
#define PARAMSET_ROIC_5_R0_4thMux_g1				(14)
#define PARAMSET_ROIC_5_R0_4thMux_g2				(14)
#define PARAMSET_ROIC_5_R0_4thMux_g3				(14)
#define PARAMSET_ROIC_6_R0_4thMux_g1				(14)
#define PARAMSET_ROIC_6_R0_4thMux_g2				(14)
#define PARAMSET_ROIC_6_R0_4thMux_g3				(14)
#define PARAMSET_ROIC_7_R0_4thMux_g1				(14)
#define PARAMSET_ROIC_7_R0_4thMux_g2				(13)
#define PARAMSET_ROIC_7_R0_4thMux_g3				(13)

#define PARAMSET_ROIC_0_R0_5thMux_g1				(19)
#define PARAMSET_ROIC_0_R0_5thMux_g2				(19)
#define PARAMSET_ROIC_0_R0_5thMux_g3				(19)
#define PARAMSET_ROIC_1_R0_5thMux_g1				(18)
#define PARAMSET_ROIC_1_R0_5thMux_g2				(18)
#define PARAMSET_ROIC_1_R0_5thMux_g3				(18)
#define PARAMSET_ROIC_2_R0_5thMux_g1				(17)
#define PARAMSET_ROIC_2_R0_5thMux_g2				(17)
#define PARAMSET_ROIC_2_R0_5thMux_g3				(17)
#define PARAMSET_ROIC_3_R0_5thMux_g1				(16)
#define PARAMSET_ROIC_3_R0_5thMux_g2				(16)
#define PARAMSET_ROIC_3_R0_5thMux_g3				(16)
#define PARAMSET_ROIC_4_R0_5thMux_g1				(15)
#define PARAMSET_ROIC_4_R0_5thMux_g2				(15)
#define PARAMSET_ROIC_4_R0_5thMux_g3				(15)
#define PARAMSET_ROIC_5_R0_5thMux_g1				(15)
#define PARAMSET_ROIC_5_R0_5thMux_g2				(14)
#define PARAMSET_ROIC_5_R0_5thMux_g3				(14)
#define PARAMSET_ROIC_6_R0_5thMux_g1				(14)
#define PARAMSET_ROIC_6_R0_5thMux_g2				(14)
#define PARAMSET_ROIC_6_R0_5thMux_g3				(14)
#define PARAMSET_ROIC_7_R0_5thMux_g1				(14)
#define PARAMSET_ROIC_7_R0_5thMux_g2				(13)
#define PARAMSET_ROIC_7_R0_5thMux_g3				(13)

#define PARAMSET_ROIC_0_R0_6thMux_g1				(19)
#define PARAMSET_ROIC_0_R0_6thMux_g2				(19)
#define PARAMSET_ROIC_0_R0_6thMux_g3				(19)
#define PARAMSET_ROIC_1_R0_6thMux_g1				(18)
#define PARAMSET_ROIC_1_R0_6thMux_g2				(18)
#define PARAMSET_ROIC_1_R0_6thMux_g3				(18)
#define PARAMSET_ROIC_2_R0_6thMux_g1				(17)
#define PARAMSET_ROIC_2_R0_6thMux_g2				(17)
#define PARAMSET_ROIC_2_R0_6thMux_g3				(17)
#define PARAMSET_ROIC_3_R0_6thMux_g1				(16)
#define PARAMSET_ROIC_3_R0_6thMux_g2				(16)
#define PARAMSET_ROIC_3_R0_6thMux_g3				(16)
#define PARAMSET_ROIC_4_R0_6thMux_g1				(15)
#define PARAMSET_ROIC_4_R0_6thMux_g2				(15)
#define PARAMSET_ROIC_4_R0_6thMux_g3				(15)
#define PARAMSET_ROIC_5_R0_6thMux_g1				(15)
#define PARAMSET_ROIC_5_R0_6thMux_g2				(14)
#define PARAMSET_ROIC_5_R0_6thMux_g3				(14)
#define PARAMSET_ROIC_6_R0_6thMux_g1				(14)
#define PARAMSET_ROIC_6_R0_6thMux_g2				(14)
#define PARAMSET_ROIC_6_R0_6thMux_g3				(14)
#define PARAMSET_ROIC_7_R0_6thMux_g1				(14)
#define PARAMSET_ROIC_7_R0_6thMux_g2				(14)
#define PARAMSET_ROIC_7_R0_6thMux_g3				(14)

#define PARAMSET_ROIC_0_R0_7thMux_g1				(19)
#define PARAMSET_ROIC_0_R0_7thMux_g2				(19)
#define PARAMSET_ROIC_0_R0_7thMux_g3				(19)
#define PARAMSET_ROIC_1_R0_7thMux_g1				(18)
#define PARAMSET_ROIC_1_R0_7thMux_g2				(18)
#define PARAMSET_ROIC_1_R0_7thMux_g3				(18)
#define PARAMSET_ROIC_2_R0_7thMux_g1				(17)
#define PARAMSET_ROIC_2_R0_7thMux_g2				(17)
#define PARAMSET_ROIC_2_R0_7thMux_g3				(17)
#define PARAMSET_ROIC_3_R0_7thMux_g1				(16)
#define PARAMSET_ROIC_3_R0_7thMux_g2				(16)
#define PARAMSET_ROIC_3_R0_7thMux_g3				(16)
#define PARAMSET_ROIC_4_R0_7thMux_g1				(16)
#define PARAMSET_ROIC_4_R0_7thMux_g2				(16)
#define PARAMSET_ROIC_4_R0_7thMux_g3				(15)
#define PARAMSET_ROIC_5_R0_7thMux_g1				(15)
#define PARAMSET_ROIC_5_R0_7thMux_g2				(15)
#define PARAMSET_ROIC_5_R0_7thMux_g3				(14)
#define PARAMSET_ROIC_6_R0_7thMux_g1				(14)
#define PARAMSET_ROIC_6_R0_7thMux_g2				(14)
#define PARAMSET_ROIC_6_R0_7thMux_g3				(14)
#define PARAMSET_ROIC_7_R0_7thMux_g1				(14)
#define PARAMSET_ROIC_7_R0_7thMux_g2				(14)
#define PARAMSET_ROIC_7_R0_7thMux_g3				(14)

#define PARAMSET_ROIC_0_R0_8thMux_g1				(19)
#define PARAMSET_ROIC_0_R0_8thMux_g2				(19)
#define PARAMSET_ROIC_0_R0_8thMux_g3				(20)
#define PARAMSET_ROIC_1_R0_8thMux_g1				(18)
#define PARAMSET_ROIC_1_R0_8thMux_g2				(19)
#define PARAMSET_ROIC_1_R0_8thMux_g3				(19)
#define PARAMSET_ROIC_2_R0_8thMux_g1				(17)
#define PARAMSET_ROIC_2_R0_8thMux_g2				(17)
#define PARAMSET_ROIC_2_R0_8thMux_g3				(17)
#define PARAMSET_ROIC_3_R0_8thMux_g1				(16)
#define PARAMSET_ROIC_3_R0_8thMux_g2				(16)
#define PARAMSET_ROIC_3_R0_8thMux_g3				(16)
#define PARAMSET_ROIC_4_R0_8thMux_g1				(16)
#define PARAMSET_ROIC_4_R0_8thMux_g2				(16)
#define PARAMSET_ROIC_4_R0_8thMux_g3				(15)
#define PARAMSET_ROIC_5_R0_8thMux_g1				(15)
#define PARAMSET_ROIC_5_R0_8thMux_g2				(15)
#define PARAMSET_ROIC_5_R0_8thMux_g3				(15)
#define PARAMSET_ROIC_6_R0_8thMux_g1				(14)
#define PARAMSET_ROIC_6_R0_8thMux_g2				(15)
#define PARAMSET_ROIC_6_R0_8thMux_g3				(14)
#define PARAMSET_ROIC_7_R0_8thMux_g1				(15)
#define PARAMSET_ROIC_7_R0_8thMux_g2				(14)
#define PARAMSET_ROIC_7_R0_8thMux_g3				(14)

#define PARAMSET_ROIC_0_R0_9thMux_g1				(0)
#define PARAMSET_ROIC_0_R0_9thMux_g2				(0)
#define PARAMSET_ROIC_0_R0_9thMux_g3				(0)
#define PARAMSET_ROIC_1_R0_9thMux_g1				(0)
#define PARAMSET_ROIC_1_R0_9thMux_g2				(0)
#define PARAMSET_ROIC_1_R0_9thMux_g3				(0)
#define PARAMSET_ROIC_2_R0_9thMux_g1				(0)
#define PARAMSET_ROIC_2_R0_9thMux_g2				(0)
#define PARAMSET_ROIC_2_R0_9thMux_g3				(0)
#define PARAMSET_ROIC_3_R0_9thMux_g1				(0)
#define PARAMSET_ROIC_3_R0_9thMux_g2				(0)
#define PARAMSET_ROIC_3_R0_9thMux_g3				(0)
#define PARAMSET_ROIC_4_R0_9thMux_g1				(0)
#define PARAMSET_ROIC_4_R0_9thMux_g2				(0)
#define PARAMSET_ROIC_4_R0_9thMux_g3				(0)
#define PARAMSET_ROIC_5_R0_9thMux_g1				(0)
#define PARAMSET_ROIC_5_R0_9thMux_g2				(0)
#define PARAMSET_ROIC_5_R0_9thMux_g3				(0)
#define PARAMSET_ROIC_6_R0_9thMux_g1				(0)
#define PARAMSET_ROIC_6_R0_9thMux_g2				(0)
#define PARAMSET_ROIC_6_R0_9thMux_g3				(0)
#define PARAMSET_ROIC_7_R0_9thMux_g1				(0)
#define PARAMSET_ROIC_7_R0_9thMux_g2				(0)
#define PARAMSET_ROIC_7_R0_9thMux_g3				(0)

#define PARAMSET_ROIC_0_R0_LastMux_Top_Line_g1		(20)
#define PARAMSET_ROIC_0_R0_LastMux_Top_Line_g2		(18)
#define PARAMSET_ROIC_0_R0_LastMux_Top_Line_g3		(21)
#define PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g1	(20)
#define PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g2	(20)
#define PARAMSET_ROIC_0_R0_LastMux_Middle_Line_g3	(20)
#define PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g1	(20)
#define PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g2	(20)
#define PARAMSET_ROIC_0_R0_LastMux_Bottom_Line_g3	(19)
#define PARAMSET_ROIC_1_R0_LastMux_Top_Line_g1		(3)
#define PARAMSET_ROIC_1_R0_LastMux_Top_Line_g2		(19)
#define PARAMSET_ROIC_1_R0_LastMux_Top_Line_g3		(20)
#define PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g1	(19)
#define PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g2	(19)
#define PARAMSET_ROIC_1_R0_LastMux_Middle_Line_g3	(19)
#define PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g1	(19)
#define PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g2	(18)
#define PARAMSET_ROIC_1_R0_LastMux_Bottom_Line_g3	(19)
#define PARAMSET_ROIC_2_R0_LastMux_Top_Line_g1		(18)
#define PARAMSET_ROIC_2_R0_LastMux_Top_Line_g2		(18)
#define PARAMSET_ROIC_2_R0_LastMux_Top_Line_g3		(2)
#define PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g1	(18)
#define PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g2	(18)
#define PARAMSET_ROIC_2_R0_LastMux_Middle_Line_g3	(18)
#define PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g1	(18)
#define PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g2	(17)
#define PARAMSET_ROIC_2_R0_LastMux_Bottom_Line_g3	(18)
#define PARAMSET_ROIC_3_R0_LastMux_Top_Line_g1		(17)
#define PARAMSET_ROIC_3_R0_LastMux_Top_Line_g2		(17)
#define PARAMSET_ROIC_3_R0_LastMux_Top_Line_g3		(17)
#define PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g1	(17)
#define PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g2	(17)
#define PARAMSET_ROIC_3_R0_LastMux_Middle_Line_g3	(17)
#define PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g1	(17)
#define PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g2	(16)
#define PARAMSET_ROIC_3_R0_LastMux_Bottom_Line_g3	(17)
#define PARAMSET_ROIC_4_R0_LastMux_Top_Line_g1		(9)
#define PARAMSET_ROIC_4_R0_LastMux_Top_Line_g2		(17)
#define PARAMSET_ROIC_4_R0_LastMux_Top_Line_g3		(16)
#define PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g1	(16)
#define PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g2	(16)
#define PARAMSET_ROIC_4_R0_LastMux_Middle_Line_g3	(16)
#define PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g1	(16)
#define PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g2	(16)
#define PARAMSET_ROIC_4_R0_LastMux_Bottom_Line_g3	(15)
#define PARAMSET_ROIC_5_R0_LastMux_Top_Line_g1		(16)
#define PARAMSET_ROIC_5_R0_LastMux_Top_Line_g2		(16)
#define PARAMSET_ROIC_5_R0_LastMux_Top_Line_g3		(16)
#define PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g1	(15)
#define PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g2	(15)
#define PARAMSET_ROIC_5_R0_LastMux_Middle_Line_g3	(15)
#define PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g1	(15)
#define PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g2	(15)
#define PARAMSET_ROIC_5_R0_LastMux_Bottom_Line_g3	(15)
#define PARAMSET_ROIC_6_R0_LastMux_Top_Line_g1		(15)
#define PARAMSET_ROIC_6_R0_LastMux_Top_Line_g2		(15)
#define PARAMSET_ROIC_6_R0_LastMux_Top_Line_g3		(15)
#define PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g1	(15)
#define PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g2	(15)
#define PARAMSET_ROIC_6_R0_LastMux_Middle_Line_g3	(15)
#define PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g1	(15)
#define PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g2	(15)
#define PARAMSET_ROIC_6_R0_LastMux_Bottom_Line_g3	(15)
#define PARAMSET_ROIC_7_R0_LastMux_Top_Line_g1		(15)
#define PARAMSET_ROIC_7_R0_LastMux_Top_Line_g2		(15)
#define PARAMSET_ROIC_7_R0_LastMux_Top_Line_g3		(15)
#define PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g1	(15)
#define PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g2	(15)
#define PARAMSET_ROIC_7_R0_LastMux_Middle_Line_g3	(15)
#define PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g1	(15)
#define PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g2	(14)
#define PARAMSET_ROIC_7_R0_LastMux_Bottom_Line_g3	(14)

#define PARAMSET_ROIC_0_R1_1stMux_Top_Line_g1		(19)
#define PARAMSET_ROIC_0_R1_1stMux_Top_Line_g2		(19)
#define PARAMSET_ROIC_0_R1_1stMux_Top_Line_g3		(19)
#define PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g1	(19)
#define PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g2	(19)
#define PARAMSET_ROIC_0_R1_1stMux_Middle_Line_g3	(19)
#define PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g1	(20)
#define PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g2	(16)
#define PARAMSET_ROIC_0_R1_1stMux_Bottom_Line_g3	(20)
#define PARAMSET_ROIC_1_R1_1stMux_Top_Line_g1		(18)
#define PARAMSET_ROIC_1_R1_1stMux_Top_Line_g2		(18)
#define PARAMSET_ROIC_1_R1_1stMux_Top_Line_g3		(18)
#define PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g1	(18)
#define PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g2	(18)
#define PARAMSET_ROIC_1_R1_1stMux_Middle_Line_g3	(18)
#define PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g1	(18)
#define PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g2	(18)
#define PARAMSET_ROIC_1_R1_1stMux_Bottom_Line_g3	(18)
#define PARAMSET_ROIC_2_R1_1stMux_Top_Line_g1		(17)
#define PARAMSET_ROIC_2_R1_1stMux_Top_Line_g2		(17)
#define PARAMSET_ROIC_2_R1_1stMux_Top_Line_g3		(17)
#define PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g1	(17)
#define PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g2	(17)
#define PARAMSET_ROIC_2_R1_1stMux_Middle_Line_g3	(17)
#define PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g1	(17)
#define PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g2	(17)
#define PARAMSET_ROIC_2_R1_1stMux_Bottom_Line_g3	(17)
#define PARAMSET_ROIC_3_R1_1stMux_Top_Line_g1		(16)
#define PARAMSET_ROIC_3_R1_1stMux_Top_Line_g2		(16)
#define PARAMSET_ROIC_3_R1_1stMux_Top_Line_g3		(16)
#define PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g1	(16)
#define PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g2	(16)
#define PARAMSET_ROIC_3_R1_1stMux_Middle_Line_g3	(16)
#define PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g1	(16)
#define PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g2	(16)
#define PARAMSET_ROIC_3_R1_1stMux_Bottom_Line_g3	(16)
#define PARAMSET_ROIC_4_R1_1stMux_Top_Line_g1		(16)
#define PARAMSET_ROIC_4_R1_1stMux_Top_Line_g2		(15)
#define PARAMSET_ROIC_4_R1_1stMux_Top_Line_g3		(15)
#define PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g1	(15)
#define PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g2	(15)
#define PARAMSET_ROIC_4_R1_1stMux_Middle_Line_g3	(15)
#define PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g1	(15)
#define PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g2	(15)
#define PARAMSET_ROIC_4_R1_1stMux_Bottom_Line_g3	(14)
#define PARAMSET_ROIC_5_R1_1stMux_Top_Line_g1		(14)
#define PARAMSET_ROIC_5_R1_1stMux_Top_Line_g2		(14)
#define PARAMSET_ROIC_5_R1_1stMux_Top_Line_g3		(14)
#define PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g1	(14)
#define PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g2	(14)
#define PARAMSET_ROIC_5_R1_1stMux_Middle_Line_g3	(14)
#define PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g1	(15)
#define PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g2	(14)
#define PARAMSET_ROIC_5_R1_1stMux_Bottom_Line_g3	(14)
#define PARAMSET_ROIC_6_R1_1stMux_Top_Line_g1		(13)
#define PARAMSET_ROIC_6_R1_1stMux_Top_Line_g2		(13)
#define PARAMSET_ROIC_6_R1_1stMux_Top_Line_g3		(14)
#define PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g1	(13)
#define PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g2	(13)
#define PARAMSET_ROIC_6_R1_1stMux_Middle_Line_g3	(13)
#define PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g1	(13)
#define PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g2	(13)
#define PARAMSET_ROIC_6_R1_1stMux_Bottom_Line_g3	(14)
#define PARAMSET_ROIC_7_R1_1stMux_Top_Line_g1		(13)
#define PARAMSET_ROIC_7_R1_1stMux_Top_Line_g2		(13)
#define PARAMSET_ROIC_7_R1_1stMux_Top_Line_g3		(13)
#define PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g1	(13)
#define PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g2	(13)
#define PARAMSET_ROIC_7_R1_1stMux_Middle_Line_g3	(14)
#define PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g1	(13)
#define PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g2	(13)
#define PARAMSET_ROIC_7_R1_1stMux_Bottom_Line_g3	(14)

#define PARAMSET_ROIC_0_R1_2ndMux_g1				(19)
#define PARAMSET_ROIC_0_R1_2ndMux_g2				(19)
#define PARAMSET_ROIC_0_R1_2ndMux_g3				(19)
#define PARAMSET_ROIC_1_R1_2ndMux_g1				(18)
#define PARAMSET_ROIC_1_R1_2ndMux_g2				(18)
#define PARAMSET_ROIC_1_R1_2ndMux_g3				(18)
#define PARAMSET_ROIC_2_R1_2ndMux_g1				(17)
#define PARAMSET_ROIC_2_R1_2ndMux_g2				(17)
#define PARAMSET_ROIC_2_R1_2ndMux_g3				(17)
#define PARAMSET_ROIC_3_R1_2ndMux_g1				(16)
#define PARAMSET_ROIC_3_R1_2ndMux_g2				(16)
#define PARAMSET_ROIC_3_R1_2ndMux_g3				(16)
#define PARAMSET_ROIC_4_R1_2ndMux_g1				(15)
#define PARAMSET_ROIC_4_R1_2ndMux_g2				(15)
#define PARAMSET_ROIC_4_R1_2ndMux_g3				(15)
#define PARAMSET_ROIC_5_R1_2ndMux_g1				(14)
#define PARAMSET_ROIC_5_R1_2ndMux_g2				(14)
#define PARAMSET_ROIC_5_R1_2ndMux_g3				(14)
#define PARAMSET_ROIC_6_R1_2ndMux_g1				(13)
#define PARAMSET_ROIC_6_R1_2ndMux_g2				(13)
#define PARAMSET_ROIC_6_R1_2ndMux_g3				(13)
#define PARAMSET_ROIC_7_R1_2ndMux_g1				(13)
#define PARAMSET_ROIC_7_R1_2ndMux_g2				(13)
#define PARAMSET_ROIC_7_R1_2ndMux_g3				(13)

#define PARAMSET_ROIC_0_R1_3rdMux_g1				(19)
#define PARAMSET_ROIC_0_R1_3rdMux_g2				(19)
#define PARAMSET_ROIC_0_R1_3rdMux_g3				(19)
#define PARAMSET_ROIC_1_R1_3rdMux_g1				(18)
#define PARAMSET_ROIC_1_R1_3rdMux_g2				(18)
#define PARAMSET_ROIC_1_R1_3rdMux_g3				(18)
#define PARAMSET_ROIC_2_R1_3rdMux_g1				(17)
#define PARAMSET_ROIC_2_R1_3rdMux_g2				(17)
#define PARAMSET_ROIC_2_R1_3rdMux_g3				(17)
#define PARAMSET_ROIC_3_R1_3rdMux_g1				(16)
#define PARAMSET_ROIC_3_R1_3rdMux_g2				(16)
#define PARAMSET_ROIC_3_R1_3rdMux_g3				(16)
#define PARAMSET_ROIC_4_R1_3rdMux_g1				(15)
#define PARAMSET_ROIC_4_R1_3rdMux_g2				(15)
#define PARAMSET_ROIC_4_R1_3rdMux_g3				(15)
#define PARAMSET_ROIC_5_R1_3rdMux_g1				(14)
#define PARAMSET_ROIC_5_R1_3rdMux_g2				(14)
#define PARAMSET_ROIC_5_R1_3rdMux_g3				(14)
#define PARAMSET_ROIC_6_R1_3rdMux_g1				(13)
#define PARAMSET_ROIC_6_R1_3rdMux_g2				(13)
#define PARAMSET_ROIC_6_R1_3rdMux_g3				(13)
#define PARAMSET_ROIC_7_R1_3rdMux_g1				(13)
#define PARAMSET_ROIC_7_R1_3rdMux_g2				(13)
#define PARAMSET_ROIC_7_R1_3rdMux_g3				(13)

#define PARAMSET_ROIC_0_R1_4thMux_g1				(19)
#define PARAMSET_ROIC_0_R1_4thMux_g2				(19)
#define PARAMSET_ROIC_0_R1_4thMux_g3				(19)
#define PARAMSET_ROIC_1_R1_4thMux_g1				(18)
#define PARAMSET_ROIC_1_R1_4thMux_g2				(18)
#define PARAMSET_ROIC_1_R1_4thMux_g3				(18)
#define PARAMSET_ROIC_2_R1_4thMux_g1				(17)
#define PARAMSET_ROIC_2_R1_4thMux_g2				(17)
#define PARAMSET_ROIC_2_R1_4thMux_g3				(17)
#define PARAMSET_ROIC_3_R1_4thMux_g1				(16)
#define PARAMSET_ROIC_3_R1_4thMux_g2				(16)
#define PARAMSET_ROIC_3_R1_4thMux_g3				(16)
#define PARAMSET_ROIC_4_R1_4thMux_g1				(15)
#define PARAMSET_ROIC_4_R1_4thMux_g2				(15)
#define PARAMSET_ROIC_4_R1_4thMux_g3				(15)
#define PARAMSET_ROIC_5_R1_4thMux_g1				(14)
#define PARAMSET_ROIC_5_R1_4thMux_g2				(14)
#define PARAMSET_ROIC_5_R1_4thMux_g3				(14)
#define PARAMSET_ROIC_6_R1_4thMux_g1				(13)
#define PARAMSET_ROIC_6_R1_4thMux_g2				(13)
#define PARAMSET_ROIC_6_R1_4thMux_g3				(13)
#define PARAMSET_ROIC_7_R1_4thMux_g1				(13)
#define PARAMSET_ROIC_7_R1_4thMux_g2				(13)
#define PARAMSET_ROIC_7_R1_4thMux_g3				(13)

#define PARAMSET_ROIC_0_R1_5thMux_g1				(19)
#define PARAMSET_ROIC_0_R1_5thMux_g2				(19)
#define PARAMSET_ROIC_0_R1_5thMux_g3				(19)
#define PARAMSET_ROIC_1_R1_5thMux_g1				(18)
#define PARAMSET_ROIC_1_R1_5thMux_g2				(18)
#define PARAMSET_ROIC_1_R1_5thMux_g3				(18)
#define PARAMSET_ROIC_2_R1_5thMux_g1				(17)
#define PARAMSET_ROIC_2_R1_5thMux_g2				(17)
#define PARAMSET_ROIC_2_R1_5thMux_g3				(17)
#define PARAMSET_ROIC_3_R1_5thMux_g1				(16)
#define PARAMSET_ROIC_3_R1_5thMux_g2				(16)
#define PARAMSET_ROIC_3_R1_5thMux_g3				(16)
#define PARAMSET_ROIC_4_R1_5thMux_g1				(15)
#define PARAMSET_ROIC_4_R1_5thMux_g2				(15)
#define PARAMSET_ROIC_4_R1_5thMux_g3				(15)
#define PARAMSET_ROIC_5_R1_5thMux_g1				(14)
#define PARAMSET_ROIC_5_R1_5thMux_g2				(14)
#define PARAMSET_ROIC_5_R1_5thMux_g3				(14)
#define PARAMSET_ROIC_6_R1_5thMux_g1				(14)
#define PARAMSET_ROIC_6_R1_5thMux_g2				(13)
#define PARAMSET_ROIC_6_R1_5thMux_g3				(14)
#define PARAMSET_ROIC_7_R1_5thMux_g1				(13)
#define PARAMSET_ROIC_7_R1_5thMux_g2				(13)
#define PARAMSET_ROIC_7_R1_5thMux_g3				(13)

#define PARAMSET_ROIC_0_R1_6thMux_g1				(19)
#define PARAMSET_ROIC_0_R1_6thMux_g2				(19)
#define PARAMSET_ROIC_0_R1_6thMux_g3				(19)
#define PARAMSET_ROIC_1_R1_6thMux_g1				(18)
#define PARAMSET_ROIC_1_R1_6thMux_g2				(18)
#define PARAMSET_ROIC_1_R1_6thMux_g3				(18)
#define PARAMSET_ROIC_2_R1_6thMux_g1				(17)
#define PARAMSET_ROIC_2_R1_6thMux_g2				(17)
#define PARAMSET_ROIC_2_R1_6thMux_g3				(17)
#define PARAMSET_ROIC_3_R1_6thMux_g1				(16)
#define PARAMSET_ROIC_3_R1_6thMux_g2				(16)
#define PARAMSET_ROIC_3_R1_6thMux_g3				(16)
#define PARAMSET_ROIC_4_R1_6thMux_g1				(15)
#define PARAMSET_ROIC_4_R1_6thMux_g2				(15)
#define PARAMSET_ROIC_4_R1_6thMux_g3				(15)
#define PARAMSET_ROIC_5_R1_6thMux_g1				(14)
#define PARAMSET_ROIC_5_R1_6thMux_g2				(15)
#define PARAMSET_ROIC_5_R1_6thMux_g3				(14)
#define PARAMSET_ROIC_6_R1_6thMux_g1				(14)
#define PARAMSET_ROIC_6_R1_6thMux_g2				(14)
#define PARAMSET_ROIC_6_R1_6thMux_g3				(14)
#define PARAMSET_ROIC_7_R1_6thMux_g1				(14)
#define PARAMSET_ROIC_7_R1_6thMux_g2				(14)
#define PARAMSET_ROIC_7_R1_6thMux_g3				(14)

#define PARAMSET_ROIC_0_R1_7thMux_g1				(20)
#define PARAMSET_ROIC_0_R1_7thMux_g2				(19)
#define PARAMSET_ROIC_0_R1_7thMux_g3				(19)
#define PARAMSET_ROIC_1_R1_7thMux_g1				(18)
#define PARAMSET_ROIC_1_R1_7thMux_g2				(18)
#define PARAMSET_ROIC_1_R1_7thMux_g3				(18)
#define PARAMSET_ROIC_2_R1_7thMux_g1				(17)
#define PARAMSET_ROIC_2_R1_7thMux_g2				(17)
#define PARAMSET_ROIC_2_R1_7thMux_g3				(17)
#define PARAMSET_ROIC_3_R1_7thMux_g1				(16)
#define PARAMSET_ROIC_3_R1_7thMux_g2				(16)
#define PARAMSET_ROIC_3_R1_7thMux_g3				(16)
#define PARAMSET_ROIC_4_R1_7thMux_g1				(16)
#define PARAMSET_ROIC_4_R1_7thMux_g2				(16)
#define PARAMSET_ROIC_4_R1_7thMux_g3				(15)
#define PARAMSET_ROIC_5_R1_7thMux_g1				(14)
#define PARAMSET_ROIC_5_R1_7thMux_g2				(15)
#define PARAMSET_ROIC_5_R1_7thMux_g3				(14)
#define PARAMSET_ROIC_6_R1_7thMux_g1				(14)
#define PARAMSET_ROIC_6_R1_7thMux_g2				(14)
#define PARAMSET_ROIC_6_R1_7thMux_g3				(14)
#define PARAMSET_ROIC_7_R1_7thMux_g1				(14)
#define PARAMSET_ROIC_7_R1_7thMux_g2				(14)
#define PARAMSET_ROIC_7_R1_7thMux_g3				(14)

#define PARAMSET_ROIC_0_R1_8thMux_g1				(20)
#define PARAMSET_ROIC_0_R1_8thMux_g2				(20)
#define PARAMSET_ROIC_0_R1_8thMux_g3				(20)
#define PARAMSET_ROIC_1_R1_8thMux_g1				(19)
#define PARAMSET_ROIC_1_R1_8thMux_g2				(18)
#define PARAMSET_ROIC_1_R1_8thMux_g3				(19)
#define PARAMSET_ROIC_2_R1_8thMux_g1				(17)
#define PARAMSET_ROIC_2_R1_8thMux_g2				(17)
#define PARAMSET_ROIC_2_R1_8thMux_g3				(18)
#define PARAMSET_ROIC_3_R1_8thMux_g1				(16)
#define PARAMSET_ROIC_3_R1_8thMux_g2				(17)
#define PARAMSET_ROIC_3_R1_8thMux_g3				(16)
#define PARAMSET_ROIC_4_R1_8thMux_g1				(16)
#define PARAMSET_ROIC_4_R1_8thMux_g2				(16)
#define PARAMSET_ROIC_4_R1_8thMux_g3				(16)
#define PARAMSET_ROIC_5_R1_8thMux_g1				(15)
#define PARAMSET_ROIC_5_R1_8thMux_g2				(15)
#define PARAMSET_ROIC_5_R1_8thMux_g3				(15)
#define PARAMSET_ROIC_6_R1_8thMux_g1				(14)
#define PARAMSET_ROIC_6_R1_8thMux_g2				(14)
#define PARAMSET_ROIC_6_R1_8thMux_g3				(14)
#define PARAMSET_ROIC_7_R1_8thMux_g1				(14)
#define PARAMSET_ROIC_7_R1_8thMux_g2				(14)
#define PARAMSET_ROIC_7_R1_8thMux_g3				(14)

#define PARAMSET_ROIC_0_R1_9thMux_g1				(0)
#define PARAMSET_ROIC_0_R1_9thMux_g2				(0)
#define PARAMSET_ROIC_0_R1_9thMux_g3				(0)
#define PARAMSET_ROIC_1_R1_9thMux_g1				(0)
#define PARAMSET_ROIC_1_R1_9thMux_g2				(0)
#define PARAMSET_ROIC_1_R1_9thMux_g3				(0)
#define PARAMSET_ROIC_2_R1_9thMux_g1				(0)
#define PARAMSET_ROIC_2_R1_9thMux_g2				(0)
#define PARAMSET_ROIC_2_R1_9thMux_g3				(0)
#define PARAMSET_ROIC_3_R1_9thMux_g1				(0)
#define PARAMSET_ROIC_3_R1_9thMux_g2				(0)
#define PARAMSET_ROIC_3_R1_9thMux_g3				(0)
#define PARAMSET_ROIC_4_R1_9thMux_g1				(0)
#define PARAMSET_ROIC_4_R1_9thMux_g2				(0)
#define PARAMSET_ROIC_4_R1_9thMux_g3				(0)
#define PARAMSET_ROIC_5_R1_9thMux_g1				(0)
#define PARAMSET_ROIC_5_R1_9thMux_g2				(0)
#define PARAMSET_ROIC_5_R1_9thMux_g3				(0)
#define PARAMSET_ROIC_6_R1_9thMux_g1				(0)
#define PARAMSET_ROIC_6_R1_9thMux_g2				(0)
#define PARAMSET_ROIC_6_R1_9thMux_g3				(0)
#define PARAMSET_ROIC_7_R1_9thMux_g1				(0)
#define PARAMSET_ROIC_7_R1_9thMux_g2				(0)
#define PARAMSET_ROIC_7_R1_9thMux_g3				(0)

#define PARAMSET_ROIC_0_R1_LastMux_Top_Line_g1		(21)
#define PARAMSET_ROIC_0_R1_LastMux_Top_Line_g2		(21)
#define PARAMSET_ROIC_0_R1_LastMux_Top_Line_g3		(21)
#define PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g1	(20)
#define PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g2	(20)
#define PARAMSET_ROIC_0_R1_LastMux_Middle_Line_g3	(20)
#define PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g1	(21)
#define PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g2	(20)
#define PARAMSET_ROIC_0_R1_LastMux_Bottom_Line_g3	(20)
#define PARAMSET_ROIC_1_R1_LastMux_Top_Line_g1		(20)
#define PARAMSET_ROIC_1_R1_LastMux_Top_Line_g2		(19)
#define PARAMSET_ROIC_1_R1_LastMux_Top_Line_g3		(20)
#define PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g1	(19)
#define PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g2	(19)
#define PARAMSET_ROIC_1_R1_LastMux_Middle_Line_g3	(19)
#define PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g1	(19)
#define PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g2	(19)
#define PARAMSET_ROIC_1_R1_LastMux_Bottom_Line_g3	(19)
#define PARAMSET_ROIC_2_R1_LastMux_Top_Line_g1		(19)
#define PARAMSET_ROIC_2_R1_LastMux_Top_Line_g2		(18)
#define PARAMSET_ROIC_2_R1_LastMux_Top_Line_g3		(18)
#define PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g1	(18)
#define PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g2	(18)
#define PARAMSET_ROIC_2_R1_LastMux_Middle_Line_g3	(18)
#define PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g1	(18)
#define PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g2	(18)
#define PARAMSET_ROIC_2_R1_LastMux_Bottom_Line_g3	(18)
#define PARAMSET_ROIC_3_R1_LastMux_Top_Line_g1		(17)
#define PARAMSET_ROIC_3_R1_LastMux_Top_Line_g2		(17)
#define PARAMSET_ROIC_3_R1_LastMux_Top_Line_g3		(18)
#define PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g1	(17)
#define PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g2	(17)
#define PARAMSET_ROIC_3_R1_LastMux_Middle_Line_g3	(17)
#define PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g1	(17)
#define PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g2	(17)
#define PARAMSET_ROIC_3_R1_LastMux_Bottom_Line_g3	(17)
#define PARAMSET_ROIC_4_R1_LastMux_Top_Line_g1		(17)
#define PARAMSET_ROIC_4_R1_LastMux_Top_Line_g2		(16)
#define PARAMSET_ROIC_4_R1_LastMux_Top_Line_g3		(16)
#define PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g1	(16)
#define PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g2	(16)
#define PARAMSET_ROIC_4_R1_LastMux_Middle_Line_g3	(16)
#define PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g1	(16)
#define PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g2	(16)
#define PARAMSET_ROIC_4_R1_LastMux_Bottom_Line_g3	(16)
#define PARAMSET_ROIC_5_R1_LastMux_Top_Line_g1		(15)
#define PARAMSET_ROIC_5_R1_LastMux_Top_Line_g2		(16)
#define PARAMSET_ROIC_5_R1_LastMux_Top_Line_g3		(16)
#define PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g1	(15)
#define PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g2	(15)
#define PARAMSET_ROIC_5_R1_LastMux_Middle_Line_g3	(15)
#define PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g1	(16)
#define PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g2	(15)
#define PARAMSET_ROIC_5_R1_LastMux_Bottom_Line_g3	(15)
#define PARAMSET_ROIC_6_R1_LastMux_Top_Line_g1		(15)
#define PARAMSET_ROIC_6_R1_LastMux_Top_Line_g2		(15)
#define PARAMSET_ROIC_6_R1_LastMux_Top_Line_g3		(15)
#define PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g1	(15)
#define PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g2	(15)
#define PARAMSET_ROIC_6_R1_LastMux_Middle_Line_g3	(15)
#define PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g1	(14)
#define PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g2	(14)
#define PARAMSET_ROIC_6_R1_LastMux_Bottom_Line_g3	(14)
#define PARAMSET_ROIC_7_R1_LastMux_Top_Line_g1		(15)
#define PARAMSET_ROIC_7_R1_LastMux_Top_Line_g2		(15)
#define PARAMSET_ROIC_7_R1_LastMux_Top_Line_g3		(15)
#define PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g1	(15)
#define PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g2	(15)
#define PARAMSET_ROIC_7_R1_LastMux_Middle_Line_g3	(15)
#define PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g1	(15)
#define PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g2	(14)
#define PARAMSET_ROIC_7_R1_LastMux_Bottom_Line_g3	(14)

#endif


#endif /* USED_RAWDATA_TUNE_CALIBRATION */

#define IDLE_TUNE_OFFSET	(-10)

#define PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_0_R0_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_1_R0_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_2_R0_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_3_R0_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_4_R0_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_5_R0_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_6_R0_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_7_R0_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)



#define PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)//(18)
#define PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)//(21)
#define PARAMSET_ROIC_0_R1_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)//(21)

#define PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_1_R1_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_2_R1_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_3_R1_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_4_R1_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_5_R1_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_6_R1_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1o_rg1                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1o_rg2                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1o_rg3                  (0)//(14+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1e_rg1                  (0)//(24+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1e_rg2                  (0)//(27+IDLE_TUNE_OFFSET)
#define PARAMSET_ROIC_7_R1_CR_M1_LTUNE_cr_m1e_rg3                  (0)//(27+IDLE_TUNE_OFFSET)

#define PARAMSET_ROIC_CR_GTUNE_cr_gtune                     (0)

#define PARAMSET_ROIC_CFGR_TUNE_LOWER_lower_mux_num         (0)
#define PARAMSET_ROIC_CFGR_TUNE_LOWER_cr_rg2_sel            (14)
#define PARAMSET_ROIC_CFGR_TUNE_LOWER_cr_rg3_sel            (16)

#define PARAMSET_ROIC_CFGR_TUNE_UPPER_upper_mux_num         (8)
#define PARAMSET_ROIC_CFGR_TUNE_UPPER_cr_rg2_sel            (14)
#define PARAMSET_ROIC_CFGR_TUNE_UPPER_cr_rg3_sel            (16)

#define PARAMSET_ROIC_CFGR_TUNE_GROUP_cr_rg2_sel            (14)
#define PARAMSET_ROIC_CFGR_TUNE_GROUP_cr_rg3_sel            (16)
#define PARAMSET_ROIC_CFGR_TUNE_GROUP_cr_m1_g2_sel          (14)
#define PARAMSET_ROIC_CFGR_TUNE_GROUP_cr_m1_g3_sel          (16)

#define PARAMSET_ROIC_CFGR_SENSE_CTRL_adc_bc                (0)
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_adc_stc_insel         (0)
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_ref               (2)
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_sha_ref               (2)
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcon           (CFGR_SENSE_CTRL_lv_ssu_bcon)  //<<
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_lv_ssu_bcons          (CFGR_SENSE_CTRL_lv_ssu_bcons)  //<<
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_hv_ssu_bcon           (CFGR_SENSE_CTRL_hv_ssu_bcon)  //<<
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_integ_half            (CFGR_SENSE_CTRL_integ_half)  //<<
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_gc                (CFGR_SENSE_CTRL_pre_gc)  //<<
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_gc                (CFGR_SENSE_CTRL_int_gc)  //<<
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_powsel                (0)
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_pre_bs_lp             (CFGR_SENSE_CTRL_pre_bs_lp)  //<<
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_int_bs_lp             (CFGR_SENSE_CTRL_int_bs_lp)  //<<
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_sha_bs_lp             (CFGR_SENSE_CTRL_sha_bs_lp)  //<<

#define PARAMSET_ROIC_CFGR_SENSE_CTRL_2_tm_ssu_pen          (0)
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_2_vpen_en             (0)
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_2_vpen_pol            (0)
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_2_tm_alp_mon          (0)
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_2_alp_mon             (0)
#define PARAMSET_ROIC_CFGR_SENSE_CTRL_2_cfgr_adc_data_dly   (2)

#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_hvbias           (1)//(0)//
#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_hvr              (1)//(0)//
#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_lvbias           (1)//(0)//
#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_lvr              (1)//(0)//
#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_bgr_en               (1)//(0)//
#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_pdb_adc              (1)//(0)//
#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_hvbias         (1)//(0)//
#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_hvr            (1)//(0)//
#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_lvbias         (1)//(0)//
#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_lvr            (1)//(0)//
#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_bgr            (0)//(1)//
#define PARAMSET_ROIC_CFGR_SSU_PW_CTRL_stuck_adc            (0)//(1)//

/* ************************************************* */


#endif /* _PARAM_CONFIGSET_ROIC_H_ */
