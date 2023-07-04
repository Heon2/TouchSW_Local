/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : parameter_sric.h
 * created on : 18. 9. 2017
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

#ifndef _PARAMETER_SRIC_H_
#define _PARAMETER_SRIC_H_






#if 1

#else


#if USED_1LHB_3MUX_SENSING
#define SRIC_SENSING_TSYNC_ACTIVE_BITMASK	(0x78F)//(0xF1E)
#define SRIC_SENSING_TSYNC_IDLE_BITMASK		(0xF)//(0x1E)
#else /* USED_1LHB_3MUX_SENSING */
#define SRIC_SENSING_TSYNC_ACTIVE_BITMASK	(0x3F7E)
#define SRIC_SENSING_TSYNC_IDLE_BITMASK		(0x7E)
#endif /* USED_1LHB_3MUX_SENSING */

/*
 * CFGR_MD_GENERAL0
 */
#define _PARAM_SRIC_MD_GENERAL0_md_one_frm			(0) // One Frame Muxing in 1 TSYNC (default: 1)
#define _PARAM_SRIC_MD_GENERAL0_md_two_frm			(0)
#define _PARAM_SRIC_MD_GENERAL0_md_lhb_pen			(0)
#define _PARAM_SRIC_MD_GENERAL0_md_lhb_one			(0)
#define _PARAM_SRIC_MD_GENERAL0_md_lhb				(1)
#define _PARAM_SRIC_MD_GENERAL0_md_dintg			(0)
#define _PARAM_SRIC_MD_GENERAL0_md_double			(1)
#define _PARAM_SRIC_MD_GENERAL0_md_24mhz			(0)
#define _PARAM_SRIC_MD_GENERAL0_md_ni_f1			(0)
#define _PARAM_SRIC_MD_GENERAL0_md_ni_f2			(0)
#define _PARAM_SRIC_MD_GENERAL0_md_ni_f3			(0)
#define _PARAM_SRIC_MD_GENERAL0_md_ni_f4			(0)
#if USED_MUX_SENSING_REVERSE
#define _PARAM_SRIC_MD_GENERAL0_cmux_remap			(1)
#else /* USED_MUX_SENSING_REVERSE */
#define _PARAM_SRIC_MD_GENERAL0_cmux_remap			(0)
#endif /* USED_MUX_SENSING_REVERSE */
#define _PARAM_SRIC_MD_GENERAL0_tsync_flt			(1)
#define _PARAM_SRIC_MD_GENERAL0_tsync_pos			(1)

/*
 * CFGR_AIP_ADC
 */
#define _PARAM_SRIC_AIP_ADC_bgr_ena					(1)
#define _PARAM_SRIC_AIP_ADC_bgr_ena_auto			(1)
#define _PARAM_SRIC_AIP_ADC_lv_ssu_bias_on			(1)
#define _PARAM_SRIC_AIP_ADC_hv_ssu_bias_on			(1)
#define _PARAM_SRIC_AIP_ADC_adc_on					(1)
#define _PARAM_SRIC_AIP_ADC_sw_power_ena			(1)
#define _PARAM_SRIC_AIP_ADC_adc_bcon				(1)
#define _PARAM_SRIC_AIP_ADC_adc_freq				(3)
#define _PARAM_SRIC_AIP_ADC_adc_fast_clk			(1)
#define _PARAM_SRIC_AIP_ADC_adc_wdiv				(0)
#define _PARAM_SRIC_AIP_ADC_adc_int_stc				(0)

/*
 * CFGR_SSU_CTRL
 */
#define _PARAM_SRIC_SSU_CTRL_int_ref				(1)
#define _PARAM_SRIC_SSU_CTRL_sha_ref				(2)

#if USED_AFE_SRIC_SSU_CONTROL
#define _PARAM_SRIC_SSU_CTRL_lv_ssu_bcon			(0)
#define _PARAM_SRIC_SSU_CTRL_lv_ssu_bcons			(2)
#define _PARAM_SRIC_SSU_CTRL_hv_ssu_bcon			(0)
#else
#define _PARAM_SRIC_SSU_CTRL_lv_ssu_bcon			(0)
#define _PARAM_SRIC_SSU_CTRL_lv_ssu_bcons			(3)
#define _PARAM_SRIC_SSU_CTRL_hv_ssu_bcon			(0)
#endif

/*
 * CFGR_TSYNC_NUM0, CFGR_TSYNC_NUM1, CFGR_TSYNC_DMMY,
 */
#if USED_1LHB_3MUX_SENSING
#define _PARAM_SRIC_TSYNC_NUM0_str_tsync0			(0)
#define _PARAM_SRIC_TSYNC_NUM0_end_tsync0			(3)
#define _PARAM_SRIC_TSYNC_NUM1_str_tsync1			(3)
#define _PARAM_SRIC_TSYNC_NUM1_end_tsync1			(6)
#define _PARAM_SRIC_TSYNC_DUMMY_dmy_tsync1			(5)
#else /* USED_1LHB_3MUX_SENSING */
#define _PARAM_SRIC_TSYNC_NUM0_str_tsync0			(1)
#define _PARAM_SRIC_TSYNC_NUM0_end_tsync0			(6)
#define _PARAM_SRIC_TSYNC_NUM1_str_tsync1			(1)
#define _PARAM_SRIC_TSYNC_NUM1_end_tsync1			(6)
#define _PARAM_SRIC_TSYNC_DUMMY_dmy_tsync1			(2)
#endif /* USED_1LHB_3MUX_SENSING */

/*
 * CFGR_TSYNC_NUM_PEN, CFGR_TSYNC_DMMY_PEN
 */
#define _PARAM_SRIC_TSYNC_NUM_PEN_str_tsync0_pen	(1)
#define _PARAM_SRIC_TSYNC_NUM_PEN_end_tsync0_pen	(15)
#define _PARAM_SRIC_TSYNC_DMMY_PEN_dmy_tsync_pen	(0)

/*
 * CFGR_PWM_NUM0, CFGR_PWM_NUM1, CFGR_PWM_NUM2, CFGR_PWM_NUM3, CFGR_PWM_NUM4, CFGR_PWM_NUM5
 */

#define _PARAM_SRIC_PWM_NUM0_num_pre_pwm			(3)
#define _PARAM_SRIC_PWM_NUM0_num_set_pwm			(1)
#define _PARAM_SRIC_PWM_NUM1_num_act_pwm			(9)//(11)
#define _PARAM_SRIC_PWM_NUM1_num_act_pwm_S3_ACTIVE	(9)
#define _PARAM_SRIC_PWM_NUM1_num_act_pwm_S3_IDLE	(9)
#define _PARAM_SRIC_PWM_NUM1_num_din_pwm			(0)
#define _PARAM_SRIC_PWM_NUM2_num_fgr1_act_pwm		(13)
#define _PARAM_SRIC_PWM_NUM2_num_fgr1_din_pwm		(0)
#define _PARAM_SRIC_PWM_NUM3_num_pen_act_pwm		(13)
#define _PARAM_SRIC_PWM_NUM3_num_pen_din_pwm		(0)
#define _PARAM_SRIC_PWM_NUM4_num_data_act_pwm		(8)
#define _PARAM_SRIC_PWM_NUM4_num_data_din_pwm		(0)
#define _PARAM_SRIC_PWM_NUM5_num_fgr1_set_pwm		(1)
#define _PARAM_SRIC_PWM_NUM5_num_pen_set_pwm		(1)
#define _PARAM_SRIC_PWM_NUM5_num_data_set_pwm		(1)
/*
 * CFGR_CMUX_NORM
 */
#define _PARAM_SRIC_CMUX_NORM_str_cmux				(0)
#define _PARAM_SRIC_CMUX_NORM_end_cmux				(11)
#define _PARAM_SRIC_CMUX_NORM_end_row				(47)

/*
 * CFGR_CMUX_NUM_PEN
 */
#define _PARAM_SRIC_CMUX_NUM_PEN_num_pen_fgr_mux		(34)
#define _PARAM_SRIC_CMUX_NUM_PEN_num_pen_only_mux		(30)
#define _PARAM_SRIC_CMUX_NUM_PEN_pen_data_sum_by_row	(0)

/*
 * CFGR_CMUX_NUM
 */
#if USED_1LHB_3MUX_SENSING
#define _PARAM_SRIC_CMUX_NUM_num_frg0_cmux			(3)
#else /* USED_1LHB_3MUX_SENSING */
#define _PARAM_SRIC_CMUX_NUM_num_frg0_cmux			(2)
#endif /* USED_1LHB_3MUX_SENSING */
#define _PARAM_SRIC_CMUX_NUM_num_frg1_cmux			(2)
#define _PARAM_SRIC_CMUX_NUM_num_pen_cmux			(2)
#define _PARAM_SRIC_CMUX_NUM_num_data_cmux			(4)

/*
 * CFGR_CHIP0_LEN
 */
#define _PARAM_SRIC_CHIP0_LEN_chip0_len				(0x38)
#if USED_SRIC_CHANNEL_PAD_OFF
#define _PARAM_SRIC_CHIP0_LEN_tie0_cmux				(1)
#else /* USED_SRIC_CHANNEL_PAD_OFF */
#define _PARAM_SRIC_CHIP0_LEN_tie0_cmux				(0)
#endif /* USED_SRIC_CHANNEL_PAD_OFF */
#define _PARAM_SRIC_CHIP0_LEN_tie1_cmux				(0)
#define _PARAM_SRIC_CHIP0_LEN_tie0_local_cmux		(0)
#define _PARAM_SRIC_CHIP0_LEN_tie1_local_cmux		(0)
#define _PARAM_SRIC_CHIP0_LEN_all_tied1_cmux		(0)

/*
 * CFGR_COL_NUM
 */
#define _PARAM_SRIC_COL_NUM_str_col					(0)
#define _PARAM_SRIC_COL_NUM_end_col					(6)
#define _PARAM_SRIC_COL_NUM_col_len0				(7)

/*
 * CFGR_OUTER
 */
#define _PARAM_SRIC_OUTER_touter_ena				(0)
#define _PARAM_SRIC_OUTER_bouter_ena				(0)
#define _PARAM_SRIC_OUTER_louter_ena				(0)
#define _PARAM_SRIC_OUTER_router_ena				(0)
#define _PARAM_SRIC_OUTER_dg_ena					(0)
#define _PARAM_SRIC_OUTER_offset					(6)

/*
 * CFGR_NIH_STD
 */
#define _PARAM_SRIC_NIH_STD_nih_cado				(0)
#define _PARAM_SRIC_NIH_STD_self_td_th				(32)
#define _PARAM_SRIC_NIH_STD_self_td_sel				(8)
#define _PARAM_SRIC_NIH_STD_self_td_or				(0)

/*
 * AFE Analog Block Register Parameter Value
 * CFGR_SHA_STR, CFGR_RSTP_WIDTH, CFGR_VCR_STR, CFGR_VCR2_MD, CFGR_VCR2_PHTCR
 * CFGR_PHTH0_WIDTH, CFGR_PHTH1_WIDTH, CFGR_SHA_RUN, CFGR_RSTP_DLY1, CFGR_RSTP_DLY2,
 */
/* 91KHz Frequency */
#define _PARAM_SRIC_SHA_STR_sha_str					(27)
#define _PARAM_SRIC_RSTP_WIDTH_rstp_width			(8)
#define _PARAM_SRIC_VCR_STR_vcr_str					(10)//(6)//(10)
#define _PARAM_SRIC_VCR_STR_vcr_ena					(1)
#define _PARAM_SRIC_VCR_STR_vcr_hperiod				(6)//(3)//(6)
#define _PARAM_SRIC_VCR2_MD_vcr_p_num				(1)//(3)//(1)
#define _PARAM_SRIC_VCR2_MD_vcr2_md					(1)//(0)//(1)
#define _PARAM_SRIC_VCR2_MD_vcr2_str_dly			(4)
#define _PARAM_SRIC_VCR2_PHTCR_vcr2_phtcr_hiw		(8)
#define _PARAM_SRIC_PHTH0_WIDTH_phth0_width			(1)
#define _PARAM_SRIC_PHTH1_WIDTH_phth1_width			(39)
#define _PARAM_SRIC_SHA_RUN_cfgr_itg_sha_run		(8)
#define _PARAM_SRIC_SHA_RUN_cfgr_sha_run			(11)
#define _PARAM_SRIC_RSTP_DLY1_rstp_dly1				(1)
#define _PARAM_SRIC_RSTP_DLY1_rstp_dly2				(1)
#define _PARAM_SRIC_RSTP_DLY2_rsti_dly1				(2)
#define _PARAM_SRIC_RSTP_DLY2_rsti_dly2				(1)

/*
 * CFGR_TEST_OPT
 */
#define _PARAM_SRIC_TEST_OPT_ssu_on_row				(3)
#define _PARAM_SRIC_TEST_OPT_pow_sel				(0)
#define _PARAM_SRIC_TEST_OPT_sbuf_cp_ena			(1)
#define _PARAM_SRIC_TEST_OPT_tsyncn_bypass			(0)
#define _PARAM_SRIC_TEST_OPT_rstp_high				(0)
#define _PARAM_SRIC_TEST_OPT_adc_rst				(0)
#define _PARAM_SRIC_TEST_OPT_cr_tgl_off				(0)

/*
 * CFGR_LV_SSU_ON, CFGR_HV_SSU_ON
 */
#define LV_CH_1			((1) << 0) // USED AFE
#define LV_CH_2			((1) << 1) // USED AFE
#define LV_CH_3			((1) << 2) // USED AFE
#define LV_CH_4			((1) << 3) // USED AFE
#define LV_CH_5			((0) << 4) // Not Used but Dummy On
#define LV_CH_6			((0) << 5) // Not Used
#define LV_CH_7			((0) << 6) // Not Used
#define LV_CH_8			((0) << 7) // Not Used
#define LV_CH_9			((0) << 8) // Not Used but Dummy On
#define LV_CH_10		((1) << 9) // USED AFE
#define LV_CH_11		((1) << 10)// USED AFE
#define LV_CH_12		((1) << 11)// USED AFE

#define HV_CH_1			((1) << 0) // USED AFE
#define HV_CH_2			((1) << 1) // USED AFE
#define HV_CH_3			((1) << 2) // USED AFE
#define HV_CH_4			((1) << 3) // USED AFE
#define HV_CH_5			((1) << 4) // Not Used but Dummy On
#define HV_CH_6			((0) << 5) // Not Used
#define HV_CH_7			((0) << 6) // Not Used
#define HV_CH_8			((0) << 7) // Not Used
#define HV_CH_9			((1) << 8) // Not Used but Dummy On
#define HV_CH_10		((1) << 9) // USED AFE
#define HV_CH_11		((1) << 10)// USED AFE
#define HV_CH_12		((1) << 11)// USED AFE

#define _PARAM_SRIC_LV_SSU_ON_lv_ssu_on		(LV_CH_1 | LV_CH_2 | LV_CH_3 | LV_CH_4 | LV_CH_5 | LV_CH_6 | LV_CH_7 | LV_CH_8 | LV_CH_9 | LV_CH_10 | LV_CH_11 | LV_CH_12)
#define _PARAM_SRIC_HV_SSU_ON_hv_ssu_on		(HV_CH_1 | HV_CH_2 | HV_CH_3 | HV_CH_4 | HV_CH_5 | HV_CH_6 | HV_CH_7 | HV_CH_8 | HV_CH_9 | HV_CH_10 | HV_CH_11 | HV_CH_12)


/*
 * CFGR_SSU_CR_I : R0
 */
#define _PARAM_SRIC_SSU_CR_mx00_i_R0_S0				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_i_R0_S0				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_i_R0_S0				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_i_R0_S0				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_i_R0_S0				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_i_R0_S0				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R0_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R0_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R0_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R0_S0				(4)

#define _PARAM_SRIC_SSU_CR_mx00_i_R0_S1				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_i_R0_S1				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_i_R0_S1				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_i_R0_S1				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_i_R0_S1				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_i_R0_S1				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R0_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R0_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R0_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R0_S1				(4)

#define _PARAM_SRIC_SSU_CR_mx00_i_R0_S2				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_i_R0_S2				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_i_R0_S2				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_i_R0_S2				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_i_R0_S2				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_i_R0_S2				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R0_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R0_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R0_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R0_S2				(4)

#define _PARAM_SRIC_SSU_CR_mx00_i_R0_S3				(13)	//(9)
#define _PARAM_SRIC_SSU_CR_mx02_i_R0_S3				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_i_R0_S3				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_i_R0_S3				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_i_R0_S3				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_i_R0_S3				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R0_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R0_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R0_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R0_S3				(4)

#define _PARAM_SRIC_SSU_CR_mx00_i_R0_S4				(13)	//(9)
#define _PARAM_SRIC_SSU_CR_mx02_i_R0_S4				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_i_R0_S4				(11)	//(8)
#define _PARAM_SRIC_SSU_CR_mx06_i_R0_S4				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_i_R0_S4				(9)		//(7)
#define _PARAM_SRIC_SSU_CR_mx10_i_R0_S4				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R0_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R0_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R0_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R0_S4				(4)

#define _PARAM_SRIC_SSU_CR_mx00_i_R0_S5				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_i_R0_S5				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_i_R0_S5				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_i_R0_S5				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_i_R0_S5				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_i_R0_S5				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R0_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R0_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R0_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R0_S5				(4)

/*
 * CFGR_SSU_CR_I : R1
 */
#define _PARAM_SRIC_SSU_CR_mx00_i_R1_S0				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_i_R1_S0				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_i_R1_S0				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_i_R1_S0				(10)	//(9)
#define _PARAM_SRIC_SSU_CR_mx08_i_R1_S0				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_i_R1_S0				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R1_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R1_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R1_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R1_S0				(4)

#define _PARAM_SRIC_SSU_CR_mx00_i_R1_S1				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_i_R1_S1				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_i_R1_S1				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_i_R1_S1				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_i_R1_S1				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_i_R1_S1				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R1_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R1_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R1_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R1_S1				(4)

#define _PARAM_SRIC_SSU_CR_mx00_i_R1_S2				(13)	//(9)
#define _PARAM_SRIC_SSU_CR_mx02_i_R1_S2				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_i_R1_S2				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_i_R1_S2				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_i_R1_S2				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_i_R1_S2				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R1_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R1_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R1_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R1_S2				(4)

#define _PARAM_SRIC_SSU_CR_mx00_i_R1_S3				(13)	//(9)
#define _PARAM_SRIC_SSU_CR_mx02_i_R1_S3				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_i_R1_S3				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_i_R1_S3				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_i_R1_S3				(9)		//(7)
#define _PARAM_SRIC_SSU_CR_mx10_i_R1_S3				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R1_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R1_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R1_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R1_S3				(4)

#define _PARAM_SRIC_SSU_CR_mx00_i_R1_S4				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_i_R1_S4				(12)	//(8)
#define _PARAM_SRIC_SSU_CR_mx04_i_R1_S4				(11)	//(8)
#define _PARAM_SRIC_SSU_CR_mx06_i_R1_S4				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_i_R1_S4				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_i_R1_S4				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R1_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R1_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R1_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R1_S4				(4)

#define _PARAM_SRIC_SSU_CR_mx00_i_R1_S5				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_i_R1_S5				(12)	//(8)
#define _PARAM_SRIC_SSU_CR_mx04_i_R1_S5				(11)	//(8)
#define _PARAM_SRIC_SSU_CR_mx06_i_R1_S5				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_i_R1_S5				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_i_R1_S5				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_i_R1_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx13_i_R1_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx14_i_R1_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx15_i_R1_S5				(4)

/*
 * CFGR_SSU_CR_E : R0
 */
#define _PARAM_SRIC_SSU_CR_mx00_e_R0_S0				(13)	//(7)
#define _PARAM_SRIC_SSU_CR_mx02_e_R0_S0				(12)	//(8)
#define _PARAM_SRIC_SSU_CR_mx04_e_R0_S0				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_e_R0_S0				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R0_S0				(9)		//(9)
#define _PARAM_SRIC_SSU_CR_mx10_e_R0_S0				(9)		//(10)
#define _PARAM_SRIC_SSU_CR_mx12_e_R0_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R0_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R0_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R0_S0				(4)

#define _PARAM_SRIC_SSU_CR_mx00_e_R0_S1				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_e_R0_S1				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_e_R0_S1				(11)	//(8)
#define _PARAM_SRIC_SSU_CR_mx06_e_R0_S1				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R0_S1				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_e_R0_S1				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_e_R0_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R0_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R0_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R0_S1				(4)

#define _PARAM_SRIC_SSU_CR_mx00_e_R0_S2				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_e_R0_S2				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_e_R0_S2				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_e_R0_S2				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R0_S2				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_e_R0_S2				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_e_R0_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R0_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R0_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R0_S2				(4)

#define _PARAM_SRIC_SSU_CR_mx00_e_R0_S3				(13)	//(9)
#define _PARAM_SRIC_SSU_CR_mx02_e_R0_S3				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_e_R0_S3				(11)	//(8)
#define _PARAM_SRIC_SSU_CR_mx06_e_R0_S3				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R0_S3				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_e_R0_S3				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_e_R0_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R0_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R0_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R0_S3				(4)

#define _PARAM_SRIC_SSU_CR_mx00_e_R0_S4				(13)	//(9)
#define _PARAM_SRIC_SSU_CR_mx02_e_R0_S4				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_e_R0_S4				(11)	//(8)
#define _PARAM_SRIC_SSU_CR_mx06_e_R0_S4				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R0_S4				(9)		//(7)
#define _PARAM_SRIC_SSU_CR_mx10_e_R0_S4				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_e_R0_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R0_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R0_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R0_S4				(4)

#define _PARAM_SRIC_SSU_CR_mx00_e_R0_S5				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_e_R0_S5				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_e_R0_S5				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_e_R0_S5				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R0_S5				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_e_R0_S5				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_e_R0_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R0_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R0_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R0_S5				(4)

/*
 * CFGR_SSU_CR_E : R1
 */
#define _PARAM_SRIC_SSU_CR_mx00_e_R1_S0				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_e_R1_S0				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_e_R1_S0				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_e_R1_S0				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R1_S0				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_e_R1_S0				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_e_R1_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R1_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R1_S0				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R1_S0				(4)

#define _PARAM_SRIC_SSU_CR_mx00_e_R1_S1				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_e_R1_S1				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_e_R1_S1				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_e_R1_S1				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R1_S1				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_e_R1_S1				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_e_R1_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R1_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R1_S1				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R1_S1				(8)

#define _PARAM_SRIC_SSU_CR_mx00_e_R1_S2				(13)	//(9)
#define _PARAM_SRIC_SSU_CR_mx02_e_R1_S2				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_e_R1_S2				(11)	//(9)
#define _PARAM_SRIC_SSU_CR_mx06_e_R1_S2				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R1_S2				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_e_R1_S2				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_e_R1_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R1_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R1_S2				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R1_S2				(4)

#define _PARAM_SRIC_SSU_CR_mx00_e_R1_S3				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_e_R1_S3				(12)	//(9)
#define _PARAM_SRIC_SSU_CR_mx04_e_R1_S3				(11)	//(8)
#define _PARAM_SRIC_SSU_CR_mx06_e_R1_S3				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R1_S3				(9)		//(7)
#define _PARAM_SRIC_SSU_CR_mx10_e_R1_S3				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_e_R1_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R1_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R1_S3				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R1_S3				(4)

#define _PARAM_SRIC_SSU_CR_mx00_e_R1_S4				(13)	//(8)
#define _PARAM_SRIC_SSU_CR_mx02_e_R1_S4				(12)	//(8)
#define _PARAM_SRIC_SSU_CR_mx04_e_R1_S4				(11)	//(8)
#define _PARAM_SRIC_SSU_CR_mx06_e_R1_S4				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R1_S4				(9)		//(7)
#define _PARAM_SRIC_SSU_CR_mx10_e_R1_S4				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx12_e_R1_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R1_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R1_S4				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R1_S4				(4)

#define _PARAM_SRIC_SSU_CR_mx00_e_R1_S5				(13)	//(9)
#define _PARAM_SRIC_SSU_CR_mx02_e_R1_S5				(12)	//(8)
#define _PARAM_SRIC_SSU_CR_mx04_e_R1_S5				(11)	//(8)
#define _PARAM_SRIC_SSU_CR_mx06_e_R1_S5				(10)	//(8)
#define _PARAM_SRIC_SSU_CR_mx08_e_R1_S5				(9)		//(8)
#define _PARAM_SRIC_SSU_CR_mx10_e_R1_S5				(9)		//(9)
#define _PARAM_SRIC_SSU_CR_mx12_e_R1_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx13_e_R1_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx14_e_R1_S5				(4)
#define _PARAM_SRIC_SSU_CR_mx15_e_R1_S5				(4)

/*
 * CFGR_EDGE_CR_SEL
 */
#define _PARAM_SRIC_EDGE_CR_SEL_ssu_cr_left0		(1)
#define _PARAM_SRIC_EDGE_CR_SEL_ssu_cr_left1		(1)
#define _PARAM_SRIC_EDGE_CR_SEL_ssu_cr_right0		(1)
#define _PARAM_SRIC_EDGE_CR_SEL_ssu_cr_right1		(1)
#define _PARAM_SRIC_EDGE_CR_SEL_rep_cr_i			(0)
#define _PARAM_SRIC_EDGE_CR_SEL_rep_cr_e			(0)
#define _PARAM_SRIC_EDGE_CR_SEL_fg0_int_half		(1)//(1)
#define _PARAM_SRIC_EDGE_CR_SEL_fg1_int_half		(0)
#define _PARAM_SRIC_EDGE_CR_SEL_pen_int_half		(0)
#define _PARAM_SRIC_EDGE_CR_SEL_data_int_half		(0)
#define _PARAM_SRIC_EDGE_CR_SEL_ni_int_half			(0)
#define _PARAM_SRIC_EDGE_CR_SEL_ssu_pre_gc_ni		(2)
#define _PARAM_SRIC_EDGE_CR_SEL_ssu_int_gc_ni		(2)

/*
 * CFGR_SSU_PRE_GC
 */
#define _PARAM_SRIC_SSU_PRE_GC_ssu_pre_gc_fgr0		(2)
#define _PARAM_SRIC_SSU_PRE_GC_ssu_pre_gc_fgr1		(2)
#define _PARAM_SRIC_SSU_PRE_GC_ssu_pre_gc_pen		(2)
#define _PARAM_SRIC_SSU_PRE_GC_ssu_pre_gc_data		(2)
#define _PARAM_SRIC_SSU_PRE_GC_ssu_int_gc_fgr0		(2)
#define _PARAM_SRIC_SSU_PRE_GC_ssu_int_gc_fgr1		(2)
#define _PARAM_SRIC_SSU_PRE_GC_ssu_int_gc_pen		(2)
#define _PARAM_SRIC_SSU_PRE_GC_ssu_int_gc_data		(2)

/*
 * CFGR_CMUX_REMAP
 */
#define _PARAM_SRIC_CMUX_REMAP0_remap_mx00			(5)
#define _PARAM_SRIC_CMUX_REMAP0_remap_mx02			(4)
#define _PARAM_SRIC_CMUX_REMAP1_remap_mx04			(3)
#define _PARAM_SRIC_CMUX_REMAP1_remap_mx06			(2)
#define _PARAM_SRIC_CMUX_REMAP2_remap_mx08			(1)
#define _PARAM_SRIC_CMUX_REMAP2_remap_mx10			(0)

/*
 * CFGR_PWM_NUM_NI
 */
#define _PARAM_SRIC_PWM_NUM_NI_ni_act_pwm			(4)
#define _PARAM_SRIC_PWM_NUM_NI_ni_set_pwm			(0)
#define _PARAM_SRIC_PWM_NUM_NI_ni_dintg				(0)
#define _PARAM_SRIC_PWM_NUM_NI_fgr1_dintg			(0)
#define _PARAM_SRIC_PWM_NUM_NI_pen_dintg			(0)
#define _PARAM_SRIC_PWM_NUM_NI_data_dintg			(0)

/*
 * CFGR_CMUX_NI1
 */
#define _PARAM_SRIC_CMUX_NI1_ni1_cmux				(0x555)
#define _PARAM_SRIC_CMUX_NI2_ni2_cmux				(0xAAA)
#define _PARAM_SRIC_CMUX_NI3_ni3_cmux				(0x555)
#define _PARAM_SRIC_CMUX_NI4_ni4_cmux				(0xAAA)

/*
 * CFGR_AFE_DUM
 */
#define _PARAM_SRIC_AFE_DUM_sm_enable				(0)
#define _PARAM_SRIC_AFE_DUM_spi_rd_back				(0)
#define _PARAM_SRIC_AFE_DUM_pad_ds_miso				(0)
#define _PARAM_SRIC_AFE_DUM_adc_in_ctrl				(1)

/*
 * CFGR_MD_IDLE
 */
#define _PARAM_SRIC_MD_IDLE_md_idle					(0)
#define _PARAM_SRIC_MD_IDLE_md_self_td				(0)
#if USED_OPERATION_STAND_ALONE
#define _PARAM_SRIC_MD_IDLE_sdic_lcd_off			(1)
#else /* USED_OPERATION_STAND_ALONE */
#define _PARAM_SRIC_MD_IDLE_sdic_lcd_off			(0)
#endif /* USED_OPERATION_STAND_ALONE */
#define _PARAM_SRIC_MD_IDLE_sdic_lfd_float			(0)
#define _PARAM_SRIC_MD_IDLE_md_flt_brdg				(0)
#define _PARAM_SRIC_MD_IDLE_md_cmx_mult				(0)
#define _PARAM_SRIC_MD_IDLE_lcd_rotate				(0)

/*
 * CFGR_HALF_COPY
 */
#define _PARAM_SRIC_HALF_COPY_tg_local_position		(0)
#define _PARAM_SRIC_HALF_COPY_tg_md_pen				(0)

/*
 * CFGR_PEN_0_TSYNC
 */
#if USED_WACOM_PEN
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn0		(PEN_TSYNC_BEACON)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn1		(PEN_TSYNC_POSITION)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn2		(PEN_TSYNC_DATA)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn3		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn4		(PEN_TSYNC_POSITION)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn5		(PEN_TSYNC_DATA)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn6		(PEN_TSYNC_DATA)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn7		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn8		(PEN_TSYNC_POSITION)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn9		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn10		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn11		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn12		(PEN_TSYNC_POSITION)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn13		(PEN_TSYNC_DATA)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn14		(PEN_TSYNC_DATA)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn15		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn16		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn17		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn18		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn19		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn20		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn21		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn22		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn23		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn24		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn25		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn26		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn27		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn28		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn29		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn30		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn31		(PEN_TSYNC_NOTUSED)
#else
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn0		(PEN_TSYNC_BEACON)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn1		(PEN_TSYNC_POSITION)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn2		(PEN_TSYNC_DATA)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn3		(PEN_TSYNC_DATA)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn4		(PEN_TSYNC_DATA)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn5		(PEN_TSYNC_POSITION)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn6		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC0_pen0_tsycn7		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn8		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn9		(PEN_TSYNC_POSITION)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn10		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn11		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn12		(PEN_TSYNC_DATA)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn13		(PEN_TSYNC_DATA)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn14		(PEN_TSYNC_POSITION)
#define _PARAM_SRIC_PEN_0_TSYNC1_pen0_tsycn15		(PEN_TSYNC_FINGER)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn16		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn17		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn18		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn19		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn20		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn21		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn22		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC2_pen0_tsycn23		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn24		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn25		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn26		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn27		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn28		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn29		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn30		(PEN_TSYNC_NOTUSED)
#define _PARAM_SRIC_PEN_0_TSYNC3_pen0_tsycn31		(PEN_TSYNC_NOTUSED)
#endif

/*
 * CFGR_BEACON_PWM0
 */
#define _PARAM_SRIC_BEACON_PWM0_num_bcon_act_pwm	(_PARAM_SRIC_PWM_NUM3_num_pen_act_pwm)
#define _PARAM_SRIC_BEACON_PWM0_num_bcon_set_pwm	(_PARAM_SRIC_PWM_NUM5_num_pen_set_pwm)

#endif


#endif /* _PARAMETER_SRIC_H_ */
