/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  app_test_sric.c
 * created on :  17. 4. 2017
 * Author :  mhjang
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

#include "core_def.h"
#if USED_NEW_CONFIG_PARAMETER
#include "param_def.h"
#else /* USED_NEW_CONFIG_PARAMETER */
#include "custom_def.h"
#endif /* USED_NEW_CONFIG_PARAMETER */
#include "Mspi.h"
#include "DSP_B.h"
#include "wdgt.h"
#include "gpio.h"
#include "sric.h"
#include "pwmdrv.h"
#include "app_test_main.h"


#if USED_TEST_OPERATION_ENABLE
#define Charge_i						(0)
#define Charge_e						(1)
#define CHARGE_R_RAWDATA_TARGET_VAL		(2200)
#define CHARGE_R_RAWDATA_MAX_VAL		(4095)
#define CHARGE_R_RAWDATA_FINISH_VAL		(UINT32_MAX)
#define CHARGE_R_REG_MAX_VAL			(15)
#define CHARGE_R_ROIC0					(0)
#define CHARGE_R_ROIC1					(0)
#define CHARGE_R_ROIC_ROW_NUM			(8)
#define CHARGE_R_RAWDATA_AVR_FRAME_NUM	(10)
#define CHARGE_R_TOTAL_COUNT_NUM		((MSPI_NUM * 2 * (FINGER_MUX_NUM / 2)) * 2)

__IO uint8_t muChargeRemoveRegVal_ROIC0_Inner[6][MSPI_NUM] = {
		{_PARAM_SRIC_SSU_CR_mx00_i_R0_S0, _PARAM_SRIC_SSU_CR_mx00_i_R0_S1, _PARAM_SRIC_SSU_CR_mx00_i_R0_S2, _PARAM_SRIC_SSU_CR_mx00_i_R0_S3, _PARAM_SRIC_SSU_CR_mx00_i_R0_S4, _PARAM_SRIC_SSU_CR_mx00_i_R0_S5},
		{_PARAM_SRIC_SSU_CR_mx02_i_R0_S0, _PARAM_SRIC_SSU_CR_mx02_i_R0_S1, _PARAM_SRIC_SSU_CR_mx02_i_R0_S2, _PARAM_SRIC_SSU_CR_mx02_i_R0_S3, _PARAM_SRIC_SSU_CR_mx02_i_R0_S4, _PARAM_SRIC_SSU_CR_mx02_i_R0_S5},
		{_PARAM_SRIC_SSU_CR_mx04_i_R0_S0, _PARAM_SRIC_SSU_CR_mx04_i_R0_S1, _PARAM_SRIC_SSU_CR_mx04_i_R0_S2, _PARAM_SRIC_SSU_CR_mx04_i_R0_S3, _PARAM_SRIC_SSU_CR_mx04_i_R0_S4, _PARAM_SRIC_SSU_CR_mx04_i_R0_S5},
		{_PARAM_SRIC_SSU_CR_mx06_i_R0_S0, _PARAM_SRIC_SSU_CR_mx06_i_R0_S1, _PARAM_SRIC_SSU_CR_mx06_i_R0_S2, _PARAM_SRIC_SSU_CR_mx06_i_R0_S3, _PARAM_SRIC_SSU_CR_mx06_i_R0_S4, _PARAM_SRIC_SSU_CR_mx06_i_R0_S5},
		{_PARAM_SRIC_SSU_CR_mx08_i_R0_S0, _PARAM_SRIC_SSU_CR_mx08_i_R0_S1, _PARAM_SRIC_SSU_CR_mx08_i_R0_S2, _PARAM_SRIC_SSU_CR_mx08_i_R0_S3, _PARAM_SRIC_SSU_CR_mx08_i_R0_S4, _PARAM_SRIC_SSU_CR_mx08_i_R0_S5},
		{_PARAM_SRIC_SSU_CR_mx10_i_R0_S0, _PARAM_SRIC_SSU_CR_mx10_i_R0_S1, _PARAM_SRIC_SSU_CR_mx10_i_R0_S2, _PARAM_SRIC_SSU_CR_mx10_i_R0_S3, _PARAM_SRIC_SSU_CR_mx10_i_R0_S4, _PARAM_SRIC_SSU_CR_mx10_i_R0_S5}
};
__IO uint8_t muChargeRemoveRegVal_ROIC1_Inner[6][MSPI_NUM] = {
		{_PARAM_SRIC_SSU_CR_mx00_i_R1_S0, _PARAM_SRIC_SSU_CR_mx00_i_R1_S1, _PARAM_SRIC_SSU_CR_mx00_i_R1_S2, _PARAM_SRIC_SSU_CR_mx00_i_R1_S3, _PARAM_SRIC_SSU_CR_mx00_i_R1_S4, _PARAM_SRIC_SSU_CR_mx00_i_R1_S5},
		{_PARAM_SRIC_SSU_CR_mx02_i_R1_S0, _PARAM_SRIC_SSU_CR_mx02_i_R1_S1, _PARAM_SRIC_SSU_CR_mx02_i_R1_S2, _PARAM_SRIC_SSU_CR_mx02_i_R1_S3, _PARAM_SRIC_SSU_CR_mx02_i_R1_S4, _PARAM_SRIC_SSU_CR_mx02_i_R1_S5},
		{_PARAM_SRIC_SSU_CR_mx04_i_R1_S0, _PARAM_SRIC_SSU_CR_mx04_i_R1_S1, _PARAM_SRIC_SSU_CR_mx04_i_R1_S2, _PARAM_SRIC_SSU_CR_mx04_i_R1_S3, _PARAM_SRIC_SSU_CR_mx04_i_R1_S4, _PARAM_SRIC_SSU_CR_mx04_i_R1_S5},
		{_PARAM_SRIC_SSU_CR_mx06_i_R1_S0, _PARAM_SRIC_SSU_CR_mx06_i_R1_S1, _PARAM_SRIC_SSU_CR_mx06_i_R1_S2, _PARAM_SRIC_SSU_CR_mx06_i_R1_S3, _PARAM_SRIC_SSU_CR_mx06_i_R1_S4, _PARAM_SRIC_SSU_CR_mx06_i_R1_S5},
		{_PARAM_SRIC_SSU_CR_mx08_i_R1_S0, _PARAM_SRIC_SSU_CR_mx08_i_R1_S1, _PARAM_SRIC_SSU_CR_mx08_i_R1_S2, _PARAM_SRIC_SSU_CR_mx08_i_R1_S3, _PARAM_SRIC_SSU_CR_mx08_i_R1_S4, _PARAM_SRIC_SSU_CR_mx08_i_R1_S5},
		{_PARAM_SRIC_SSU_CR_mx10_i_R1_S0, _PARAM_SRIC_SSU_CR_mx10_i_R1_S1, _PARAM_SRIC_SSU_CR_mx10_i_R1_S2, _PARAM_SRIC_SSU_CR_mx10_i_R1_S3, _PARAM_SRIC_SSU_CR_mx10_i_R1_S4, _PARAM_SRIC_SSU_CR_mx10_i_R1_S5}
};

__IO uint8_t muChargeRemoveRegVal_ROIC0_Edge[6][MSPI_NUM] = {
		{_PARAM_SRIC_SSU_CR_mx00_e_R0_S0, _PARAM_SRIC_SSU_CR_mx00_e_R0_S1, _PARAM_SRIC_SSU_CR_mx00_e_R0_S2, _PARAM_SRIC_SSU_CR_mx00_e_R0_S3, _PARAM_SRIC_SSU_CR_mx00_e_R0_S4, _PARAM_SRIC_SSU_CR_mx00_e_R0_S5},
		{_PARAM_SRIC_SSU_CR_mx02_e_R0_S0, _PARAM_SRIC_SSU_CR_mx02_e_R0_S1, _PARAM_SRIC_SSU_CR_mx02_e_R0_S2, _PARAM_SRIC_SSU_CR_mx02_e_R0_S3, _PARAM_SRIC_SSU_CR_mx02_e_R0_S4, _PARAM_SRIC_SSU_CR_mx02_e_R0_S5},
		{_PARAM_SRIC_SSU_CR_mx04_e_R0_S0, _PARAM_SRIC_SSU_CR_mx04_e_R0_S1, _PARAM_SRIC_SSU_CR_mx04_e_R0_S2, _PARAM_SRIC_SSU_CR_mx04_e_R0_S3, _PARAM_SRIC_SSU_CR_mx04_e_R0_S4, _PARAM_SRIC_SSU_CR_mx04_e_R0_S5},
		{_PARAM_SRIC_SSU_CR_mx06_e_R0_S0, _PARAM_SRIC_SSU_CR_mx06_e_R0_S1, _PARAM_SRIC_SSU_CR_mx06_e_R0_S2, _PARAM_SRIC_SSU_CR_mx06_e_R0_S3, _PARAM_SRIC_SSU_CR_mx06_e_R0_S4, _PARAM_SRIC_SSU_CR_mx06_e_R0_S5},
		{_PARAM_SRIC_SSU_CR_mx08_e_R0_S0, _PARAM_SRIC_SSU_CR_mx08_e_R0_S1, _PARAM_SRIC_SSU_CR_mx08_e_R0_S2, _PARAM_SRIC_SSU_CR_mx08_e_R0_S3, _PARAM_SRIC_SSU_CR_mx08_e_R0_S4, _PARAM_SRIC_SSU_CR_mx08_e_R0_S5},
		{_PARAM_SRIC_SSU_CR_mx10_e_R0_S0, _PARAM_SRIC_SSU_CR_mx10_e_R0_S1, _PARAM_SRIC_SSU_CR_mx10_e_R0_S2, _PARAM_SRIC_SSU_CR_mx10_e_R0_S3, _PARAM_SRIC_SSU_CR_mx10_e_R0_S4, _PARAM_SRIC_SSU_CR_mx10_e_R0_S5}
};
__IO int8_t muChargeRemoveRegVal_ROIC1_Edge[6][MSPI_NUM] = {
		{_PARAM_SRIC_SSU_CR_mx00_e_R1_S0, _PARAM_SRIC_SSU_CR_mx00_e_R1_S1, _PARAM_SRIC_SSU_CR_mx00_e_R1_S2, _PARAM_SRIC_SSU_CR_mx00_e_R1_S3, _PARAM_SRIC_SSU_CR_mx00_e_R1_S4, _PARAM_SRIC_SSU_CR_mx00_e_R1_S5},
		{_PARAM_SRIC_SSU_CR_mx02_e_R1_S0, _PARAM_SRIC_SSU_CR_mx02_e_R1_S1, _PARAM_SRIC_SSU_CR_mx02_e_R1_S2, _PARAM_SRIC_SSU_CR_mx02_e_R1_S3, _PARAM_SRIC_SSU_CR_mx02_e_R1_S4, _PARAM_SRIC_SSU_CR_mx02_e_R1_S5},
		{_PARAM_SRIC_SSU_CR_mx04_e_R1_S0, _PARAM_SRIC_SSU_CR_mx04_e_R1_S1, _PARAM_SRIC_SSU_CR_mx04_e_R1_S2, _PARAM_SRIC_SSU_CR_mx04_e_R1_S3, _PARAM_SRIC_SSU_CR_mx04_e_R1_S4, _PARAM_SRIC_SSU_CR_mx04_e_R1_S5},
		{_PARAM_SRIC_SSU_CR_mx06_e_R1_S0, _PARAM_SRIC_SSU_CR_mx06_e_R1_S1, _PARAM_SRIC_SSU_CR_mx06_e_R1_S2, _PARAM_SRIC_SSU_CR_mx06_e_R1_S3, _PARAM_SRIC_SSU_CR_mx06_e_R1_S4, _PARAM_SRIC_SSU_CR_mx06_e_R1_S5},
		{_PARAM_SRIC_SSU_CR_mx08_e_R1_S0, _PARAM_SRIC_SSU_CR_mx08_e_R1_S1, _PARAM_SRIC_SSU_CR_mx08_e_R1_S2, _PARAM_SRIC_SSU_CR_mx08_e_R1_S3, _PARAM_SRIC_SSU_CR_mx08_e_R1_S4, _PARAM_SRIC_SSU_CR_mx08_e_R1_S5},
		{_PARAM_SRIC_SSU_CR_mx10_e_R1_S0, _PARAM_SRIC_SSU_CR_mx10_e_R1_S1, _PARAM_SRIC_SSU_CR_mx10_e_R1_S2, _PARAM_SRIC_SSU_CR_mx10_e_R1_S3, _PARAM_SRIC_SSU_CR_mx10_e_R1_S4, _PARAM_SRIC_SSU_CR_mx10_e_R1_S5}
};

//__IO uint8_t muChargeRemoveSelRegVal_ROIC0[4][MSPI_NUM] = {
//		__ssu_cr_left0_R0,
//		__ssu_cr_left1_R0,
//		__ssu_cr_right0_R0,
//		__ssu_cr_right1_R0
//};
//__IO uint8_t muChargeRemoveSelRegVal_ROIC1[4][MSPI_NUM] = {
//		__ssu_cr_left0_R1,
//		__ssu_cr_left1_R1,
//		__ssu_cr_right0_R1,
//		__ssu_cr_right1_R1
//};
__IO uint32_t ulCRApplyOffsetValue = 0;

static uint32_t muRawDataMax_ROIC0_Inner[6][MSPI_NUM];
static uint32_t muRawDataMax_ROIC1_Inner[6][MSPI_NUM];
static uint32_t muRawDataMax_ROIC0_Edge[6][MSPI_NUM];
static uint32_t muRawDataMax_ROIC1_Edge[6][MSPI_NUM];
static uint32_t muPastRawDataMax_ROIC0_Inner[6][MSPI_NUM];
static uint32_t muPastRawDataMax_ROIC1_Inner[6][MSPI_NUM];
static uint32_t muPastRawDataMax_ROIC0_Edge[6][MSPI_NUM];
static uint32_t muPastRawDataMax_ROIC1_Edge[6][MSPI_NUM];
#if (USED_MODULE_DEF == MODULE_DEF_S_1)
#define CHARGE_R_ROIC_COL_NUM			(7)
static uint32_t vulROICCol_TypeInfo[CHARGE_R_ROIC_COL_NUM] = {Charge_e, Charge_e, Charge_i, Charge_i, Charge_i, Charge_e, Charge_e};
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
#define CHARGE_R_ROIC_COL_NUM			(12)
static uint32_t vulROICCol_TypeInfo[CHARGE_R_ROIC_COL_NUM] = {Charge_e, Charge_e, Charge_i, Charge_i, Charge_i, Charge_i, Charge_i, Charge_i, Charge_i, Charge_i, Charge_e, Charge_e};
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */


extern SRIC_TypeDef sr;

typedef struct
{
	/*
	 * Charge Remove관련 Setting!!
	 */
	uint32_t sha_str; // CFGR_SHA_STR_sha_str
	uint32_t rstp_width; // CFGR_RSTP_WIDTH_rstp_width

	uint32_t vcr_str; // CFGR_VCR_STR_vcr_str;
	uint32_t vcr_ena; // CFGR_VCR_STR_vcr_ena;
	uint32_t vcr_hperiod; // CFGR_VCR_STR_vcr_hperiod;

	uint32_t vcr_p_num; // CFGR_VCR2_MD_vcr_p_num;
	uint32_t vcr2_md; // CFGR_VCR2_MD_vcr2_md;
	uint32_t vcr2_str_dly; // CFGR_VCR2_MD_vcr2_str_dly;

	uint32_t vcr2_phtcr_hiw; // CFGR_VCR2_PHTCR_vcr2_phtcr_hiw

	uint32_t phth0_width; // CFGR_PHTH0_WIDTH_phth0_width
	uint32_t phth1_width; // CFGR_PHTH1_WIDTH_phth1_width

	uint32_t itg_sha_run; // CFGR_SHA_RUN_itg_sha_run
	uint32_t sha_run; // CFGR_SHA_RUN_sha_run
	uint32_t rstp_dly1; // CFGR_RSTP_DLY1_rstp_dly1
	uint32_t rstp_dly2; // CFGR_RSTP_DLY1_rstp_dly2

	uint32_t rsti_dly1; // CFGR_RSTP_DLY2_rsti_dly1
	uint32_t rsti_dly2; // CFGR_RSTP_DLY2_rsti_dly2


} t_TestAFERegiCofig_t;

typedef struct
{
	uint32_t adc_bcon; // ADC Bais Control (0 : 12uA, 1: 16uA, 2:20uA, 3 : 24uA)
	uint32_t int_ref; // Integrator Reference Voltage (0:0.5Vm 1: 0.7V, 2: 0.9V, 3: 0.9V, 4: 1.1V)
	uint32_t sha_ref; // SHA Referen Voltage (0: 0.80V, 1: 0.85V, 2:0.90V, 3: 0.95V)
	uint32_t lv_ssu_bcon; // Low Voltage SSI BIAS(Integrator) Current Control
	// 000 : 2.5uA, 001 : 5uA, 101 : 7.5uA, 011 : 10uA,  100 :12.5uA, 101 : 15uA, 110 : 17.5uA, 111 : 20uA
	uint32_t lv_ssu_bcons; // Low Voltage SSI BIAS(SHA) Current Control(default : 3'b011)
	// 000 : 2.5uA, 001 : 5uA, 101 : 7.5uA, 011 : 10uA,  100 :12.5uA, 101 : 15uA, 110 : 17.5uA, 111 : 20uA
	uint32_t hv_ssu_bcon; // High Voltage Ssu BIAS (Preamp) Current Control
	// 000 : 5uA, 001 : 10uA, 101 : 15uA, 011 : 20uA,  100 : 25uA, 101 : 30uA, 110 : 35uA, 111 : 40uA
	uint32_t fg0_int_half; // SSU Integrator Cap (0:INT_GCx1, 1: INT_GCx1/2)
	uint32_t ssu_pre_gc_fgr0; // Pre Amp Feedback Cap (00:2.67pF, 01:4.45pF, 10:6.97pF, 11:8.01pF)
	uint32_t ssu_int_gc_fgr0; // Integrator Gain Select (00:0.414pF, 01:1.241pF, 10:2.177pF, 11:3.004pF)
	uint32_t chip0_tie0_cmux;
	uint32_t chip0_all_tied1_cmux;

} t_TestSSURegiConfig_t;

__IO t_TestAFERegiCofig_t tTestAFERegConfig = {
	.sha_str = _PARAM_SRIC_SHA_STR_sha_str,
	.rstp_width = _PARAM_SRIC_RSTP_WIDTH_rstp_width,
	.vcr_str = _PARAM_SRIC_VCR_STR_vcr_str,
	.vcr_ena = _PARAM_SRIC_VCR_STR_vcr_ena,
	.vcr_hperiod = _PARAM_SRIC_VCR_STR_vcr_hperiod,
	.vcr_p_num = _PARAM_SRIC_VCR2_MD_vcr_p_num,
	.vcr2_md = _PARAM_SRIC_VCR2_MD_vcr2_md,
	.vcr2_str_dly = _PARAM_SRIC_VCR2_MD_vcr2_str_dly,
	.vcr2_phtcr_hiw = _PARAM_SRIC_VCR2_PHTCR_vcr2_phtcr_hiw,
	.phth0_width = _PARAM_SRIC_PHTH0_WIDTH_phth0_width,
	.phth1_width = _PARAM_SRIC_PHTH1_WIDTH_phth1_width,
	.itg_sha_run = _PARAM_SRIC_SHA_RUN_cfgr_itg_sha_run,
	.sha_run = _PARAM_SRIC_SHA_RUN_cfgr_sha_run,
	.rstp_dly1 = _PARAM_SRIC_RSTP_DLY1_rstp_dly1,
	.rstp_dly2 = _PARAM_SRIC_RSTP_DLY1_rstp_dly2,
	.rsti_dly1 = _PARAM_SRIC_RSTP_DLY2_rsti_dly1,
	.rsti_dly2 = _PARAM_SRIC_RSTP_DLY2_rsti_dly2
};

__IO t_TestSSURegiConfig_t tTestSSURegiConfig = {
	.adc_bcon = _PARAM_SRIC_AIP_ADC_adc_bcon,
	.int_ref = _PARAM_SRIC_SSU_CTRL_int_ref,
	.sha_ref = _PARAM_SRIC_SSU_CTRL_sha_ref,
	.lv_ssu_bcon = _PARAM_SRIC_SSU_CTRL_lv_ssu_bcon,
	.lv_ssu_bcons = _PARAM_SRIC_SSU_CTRL_lv_ssu_bcons,
	.hv_ssu_bcon = _PARAM_SRIC_SSU_CTRL_hv_ssu_bcon,
	.fg0_int_half = _PARAM_SRIC_EDGE_CR_SEL_fg0_int_half,
	.ssu_pre_gc_fgr0 = _PARAM_SRIC_SSU_PRE_GC_ssu_pre_gc_fgr0,
	.ssu_int_gc_fgr0 = _PARAM_SRIC_SSU_PRE_GC_ssu_int_gc_fgr0,
	.chip0_tie0_cmux = _PARAM_SRIC_CHIP0_LEN_tie0_cmux,
	.chip0_all_tied1_cmux = _PARAM_SRIC_CHIP0_LEN_all_tied1_cmux
};

void app_test_operation_SRIC_Init(void)
{
	tTestOperParam.ulCRAutoCal_TargetValue = CHARGE_R_RAWDATA_TARGET_VAL;
}

void app_test_operation_MODULE_Reset(bool_t bIsOnlyCRValue)
{
	uint32_t ulSRICIdx, ulMuxSetIdx, ulSkipCount;
	tCRControlRegister_t tCRControlReg[MSPI_NUM];
	tCRSELControlReg_t tCRSELControlReg;

	memset((void*)&tCRControlReg[0], 0x00, sizeof(tCRControlRegister_t)*MSPI_NUM);
	memset((void*)&sr, 0x00, sizeof(SRIC_TypeDef));

	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
	tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_START;
#if USED_BIAS_ON_OFF_CTRL
	{
#if USED_DUMMY_PWM_DISABLE
		/*
		 * PWM On
		 */
		PWMDRV->ENA_PWM_0_b.T_0 = (0)
		| (0)		// dsss
		| (0 << 1)	// pre
		| (1 << 2)	// act
		| (0 << 3)	// pre_lfd_0 Not Used
		| (0 << 4)	// pre_lfd_1 Not Used
		| (0 << 5)	// act_lfd_0 Not Used
		| (1 << 6);	// act_lfd_1

		// PWM_DATA (LFD at Pen Data)
		PWMDRV->ENA_PWM_0_b.T_1 = (0)
		| (0)		// dsss
		| (0 << 1)	// pre
		| (1 << 2)	// act
		| (0 << 3)	// pre_lfd_0 Not Used
		| (0 << 4)	// pre_lfd_1 Not Used
		| (0 << 5)	// act_lfd_0 Not Used
		| (1 << 6);	// act_lfd_1
#endif /* USED_DUMMY_PWM_DISABLE */
#if USED_ECLK_SOURCE_TIMERCLK
		Hal_ECLK_TimerClkDiv(0);
#endif /* USED_ECLK_SOURCE_TIMERCLK */

		SW92501_Set_Register(AIP_ADC, 0x1D7F, ROIC_0);
		extern __IO uint32_t gulBiasOnOffCtrl_FrameCheckCnt;
		gulBiasOnOffCtrl_FrameCheckCnt = 0;
	}
#endif /* USED_BIAS_ON_OFF_CTRL */
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);

	MSPI_Set_TLPMODE();
//	SW92501_Run(DISABLE);
	sr.CFGR_SNSR_STR_b.sensing_run = 1;
	sr.CFGR_SNSR_STR_b.cont_sensing = 1;
	sr.CFGR_SNSR_STR_b.tg_rst = 1;
	sr.CFGR_SNSR_STR_b.sw_rst = 0;
	SW92501_Set_Register(SNSR_STR, sr.CFGR_SNSR_STR, ROIC_0);
	PWMDRV_Cmd(DISABLE);

	if(bIsOnlyCRValue == NO)
	{
		app_test_pwm_Set_PWM_Delay_Pulse(YES);
//		PWMDRV->PRE_1_b.PRE_DLY = PWM_us(tTestPWMRegiConfig.ulPWMInitDelay);
//		PWMDRV_FG_F_F0_ACT(PWM_KHz(tTestPWMRegiConfig.ulPWMFrequency + 2), (PWM_KHz(tTestPWMRegiConfig.ulPWMFrequency + 2)/2), (__num_pre_pwm + __num_set_pwm + __num_act_pwm), PWM_us(tTestPWMRegiConfig.ulPWMIntervalDelay), 2);		// 1 Mux 16EA
//		PWMDRV_FG_F_F1_ACT(PWM_KHz(tTestPWMRegiConfig.ulPWMFrequency + 2), (PWM_KHz(tTestPWMRegiConfig.ulPWMFrequency + 2)/2), (__num_set_pwm + __num_act_pwm), 0, 1);				// 1 Mux 16EA
//		PWMDRV_FG_F_F2_ACT(PWM_KHz(tTestPWMRegiConfig.ulPWMFrequency + 2), (PWM_KHz(tTestPWMRegiConfig.ulPWMFrequency + 2)/2), 0, 0, 3);				// 1 Mux 16EA
//		PWMDRV_FG_F_F3_ACT(PWM_KHz(tTestPWMRegiConfig.ulPWMFrequency + 2), (PWM_KHz(tTestPWMRegiConfig.ulPWMFrequency + 2)/2), 0, 0, 4);				// 1 Mux 16EA

		sr.CFGR_SHA_STR_b.sha_str = tTestAFERegConfig.sha_str;
		SW92501_Set_Register(SHA_STR, sr.CFGR_SHA_STR, ROIC_0);

		sr.CFGR_RSTP_WIDTH_b.rstp_width = tTestAFERegConfig.rstp_width;
		SW92501_Set_Register(RSTP_WIDTH, sr.CFGR_RSTP_WIDTH, ROIC_0);

		sr.CFGR_VCR_STR_b.vcr_str = tTestAFERegConfig.vcr_str;//CFGR_VCR_STR_vcr_str;
		sr.CFGR_VCR_STR_b.vcr_ena = tTestAFERegConfig.vcr_ena;//CFGR_VCR_STR_vcr_ena;
		sr.CFGR_VCR_STR_b.vcr_hperiod = tTestAFERegConfig.vcr_hperiod;//CFGR_VCR_STR_vcr_hperiod;
		SW92501_Set_Register(VCR_STR, sr.CFGR_VCR_STR, ROIC_0);

		sr.CFGR_VCR2_MD_b.vcr_p_num = tTestAFERegConfig.vcr_p_num;//CFGR_VCR2_MD_vcr_p_num;
		sr.CFGR_VCR2_MD_b.vcr2_md = tTestAFERegConfig.vcr2_md;//CFGR_VCR2_MD_vcr2_md;
		sr.CFGR_VCR2_MD_b.vcr2_str_dly = tTestAFERegConfig.vcr2_str_dly;//CFGR_VCR2_MD_vcr2_str_dly;
		SW92501_Set_Register(VCR2_MD, sr.CFGR_VCR2_MD, ROIC_0);

		sr.CFGR_VCR2_PHTCR_b.vcr2_phtcr_hiw = tTestAFERegConfig.vcr2_phtcr_hiw; //CFGR_VCR2_PHTCR_vcr2_phtcr_hiw;
		SW92501_Set_Register(VCR2_PHTCR, sr.CFGR_VCR2_PHTCR, ROIC_0);

		sr.CFGR_PHTH0_WIDTH_b.phth0_width = tTestAFERegConfig.phth0_width;
		SW92501_Set_Register(PHTH0_WIDTH, sr.CFGR_PHTH0_WIDTH, ROIC_0);

		sr.CFGR_PHTH1_WIDTH_b.phth1_width = tTestAFERegConfig.phth1_width;
		SW92501_Set_Register(PHTH1_WIDTH, sr.CFGR_PHTH1_WIDTH, ROIC_0);

		sr.CFGR_SHA_RUN_b.cfgr_itg_sha_run = tTestAFERegConfig.itg_sha_run;
		sr.CFGR_SHA_RUN_b.cfgr_sha_run = tTestAFERegConfig.sha_run;
		SW92501_Set_Register(SHA_RUN, sr.CFGR_SHA_RUN, ROIC_0);

		sr.CFGR_RSTP_DLY1_b.rstp_dly1 = tTestAFERegConfig.rstp_dly1;
		sr.CFGR_RSTP_DLY1_b.rstp_dly2 = tTestAFERegConfig.rstp_dly2;
		SW92501_Set_Register(RSTP_DLY1, sr.CFGR_RSTP_DLY1, ROIC_0);

		sr.CFGR_RSTP_DLY2_b.rsti_dly1 = tTestAFERegConfig.rsti_dly1;
		sr.CFGR_RSTP_DLY2_b.rsti_dly2 = tTestAFERegConfig.rsti_dly2;
		SW92501_Set_Register(RSTP_DLY2, sr.CFGR_RSTP_DLY2, ROIC_0);

		sr.CFGR_AIP_ADC_b.bgr_ena = _PARAM_SRIC_AIP_ADC_bgr_ena;
		sr.CFGR_AIP_ADC_b.bgr_ena_auto = _PARAM_SRIC_AIP_ADC_bgr_ena_auto;
		sr.CFGR_AIP_ADC_b.lv_ssu_bias_on = _PARAM_SRIC_AIP_ADC_lv_ssu_bias_on;
		sr.CFGR_AIP_ADC_b.hv_ssu_bias_on = _PARAM_SRIC_AIP_ADC_hv_ssu_bias_on;
		sr.CFGR_AIP_ADC_b.adc_on = _PARAM_SRIC_AIP_ADC_adc_on;
		sr.CFGR_AIP_ADC_b.sw_power_ena = _PARAM_SRIC_AIP_ADC_sw_power_ena;
		sr.CFGR_AIP_ADC_b.adc_bcon = tTestSSURegiConfig.adc_bcon;
		sr.CFGR_AIP_ADC_b.adc_freq = _PARAM_SRIC_AIP_ADC_adc_freq;
		sr.CFGR_AIP_ADC_b.adc_fast_clk = _PARAM_SRIC_AIP_ADC_adc_fast_clk;
		sr.CFGR_AIP_ADC_b.adc_wdiv = _PARAM_SRIC_AIP_ADC_adc_wdiv;
		sr.CFGR_AIP_ADC_b.adc_int_stc = _PARAM_SRIC_AIP_ADC_adc_int_stc;
		SW92501_Set_Register(AIP_ADC, sr.CFGR_AIP_ADC, ROIC_0);

		sr.CFGR_SSU_CTRL_b.int_ref = tTestSSURegiConfig.int_ref;
		sr.CFGR_SSU_CTRL_b.sha_ref = tTestSSURegiConfig.sha_ref;
		sr.CFGR_SSU_CTRL_b.lv_ssu_bcon = tTestSSURegiConfig.lv_ssu_bcon;
		sr.CFGR_SSU_CTRL_b.lv_ssu_bcons = tTestSSURegiConfig.lv_ssu_bcons;
		sr.CFGR_SSU_CTRL_b.hv_ssu_bcon = tTestSSURegiConfig.hv_ssu_bcon;
		SW92501_Set_Register(SSU_CTRL, sr.CFGR_SSU_CTRL, ROIC_0);

		sr.CFGR_SSU_PRE_GC_b.ssu_pre_gc_fgr0 = tTestSSURegiConfig.ssu_pre_gc_fgr0;
		sr.CFGR_SSU_PRE_GC_b.ssu_pre_gc_fgr1 = _PARAM_SRIC_SSU_PRE_GC_ssu_pre_gc_fgr1;
		sr.CFGR_SSU_PRE_GC_b.ssu_pre_gc_pen = _PARAM_SRIC_SSU_PRE_GC_ssu_pre_gc_pen;
		sr.CFGR_SSU_PRE_GC_b.ssu_pre_gc_data = _PARAM_SRIC_SSU_PRE_GC_ssu_pre_gc_data;
		sr.CFGR_SSU_PRE_GC_b.ssu_int_gc_fgr0 = tTestSSURegiConfig.ssu_int_gc_fgr0;
		sr.CFGR_SSU_PRE_GC_b.ssu_int_gc_fgr1 = _PARAM_SRIC_SSU_PRE_GC_ssu_int_gc_fgr1;
		sr.CFGR_SSU_PRE_GC_b.ssu_int_gc_pen = _PARAM_SRIC_SSU_PRE_GC_ssu_int_gc_pen;
		sr.CFGR_SSU_PRE_GC_b.ssu_int_gc_data = _PARAM_SRIC_SSU_PRE_GC_ssu_int_gc_data;
		SW92501_Set_Register(SSU_PRE_GC, sr.CFGR_SSU_PRE_GC, ROIC_0);

		sr.CFGR_CHIP0_LEN_b.chip0_len = _PARAM_SRIC_CHIP0_LEN_chip0_len;
		sr.CFGR_CHIP0_LEN_b.tie0_cmux = tTestSSURegiConfig.chip0_tie0_cmux;//__CFGR_CHIP0_LEN_tie0_cmux;
		sr.CFGR_CHIP0_LEN_b.tie1_cmux = _PARAM_SRIC_CHIP0_LEN_tie1_cmux;
		sr.CFGR_CHIP0_LEN_b.tie0_local_cmux = _PARAM_SRIC_CHIP0_LEN_tie0_local_cmux;
		sr.CFGR_CHIP0_LEN_b.tie1_local_cmux = _PARAM_SRIC_CHIP0_LEN_tie1_local_cmux;
		sr.CFGR_CHIP0_LEN_b.all_tied1_cmux = tTestSSURegiConfig.chip0_all_tied1_cmux;
		SW92501_Set_Register(CHIP0_LEN, sr.CFGR_CHIP0_LEN, ROIC_0);

		SW92501_Set_TSYNC_CFG();
	}

	/*
	 * inner
	 */
	for(ulMuxSetIdx = 0; ulMuxSetIdx < 6; ulMuxSetIdx+=2)
	{
		/*
		 * RO Setting
		 */
		for(ulSRICIdx = 0; ulSRICIdx < MSPI_NUM; ulSRICIdx++)
		{
//			tCRControlReg[ulSRICIdx].CFGR_SSU_CR = 0x0101;
			tCRControlReg[ulSRICIdx].CFGR_SSU_CR_b.ssu_cr_even_mux_e = muChargeRemoveRegVal_ROIC0_Inner[ulMuxSetIdx][ulSRICIdx] + ulCRApplyOffsetValue;
			tCRControlReg[ulSRICIdx].CFGR_SSU_CR_b.ssu_cr_odd_mux_e = muChargeRemoveRegVal_ROIC0_Inner[ulMuxSetIdx+1][ulSRICIdx] + ulCRApplyOffsetValue;
		}
		SW92501_Each_Set_Register(SSU_CR_I00 + ulMuxSetIdx, (uint16_t *)&tCRControlReg[0], ROIC_0);
//		MSPI_RegisterRead(R0(SSU_CR_I00 + ulMuxSetIdx), );
		/*
		 * R1 Setting
		 */
		for(ulSRICIdx = 0; ulSRICIdx < MSPI_NUM; ulSRICIdx++)
		{
//			tCRControlReg[ulSRICIdx].CFGR_SSU_CR = 0x0101;
			tCRControlReg[ulSRICIdx].CFGR_SSU_CR_b.ssu_cr_even_mux_e = muChargeRemoveRegVal_ROIC1_Inner[ulMuxSetIdx][ulSRICIdx] + ulCRApplyOffsetValue;
			tCRControlReg[ulSRICIdx].CFGR_SSU_CR_b.ssu_cr_odd_mux_e = muChargeRemoveRegVal_ROIC1_Inner[ulMuxSetIdx+1][ulSRICIdx] + ulCRApplyOffsetValue;
		}
		SW92501_Each_Set_Register(SSU_CR_I00 + ulMuxSetIdx, (uint16_t *)&tCRControlReg[0], ROIC_1);
	}

	/*
	 * Edge CR Sel
	 */
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.ssu_cr_left0 = _PARAM_SRIC_EDGE_CR_SEL_ssu_cr_left0;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.ssu_cr_left1 = _PARAM_SRIC_EDGE_CR_SEL_ssu_cr_left1;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.ssu_cr_right0 = _PARAM_SRIC_EDGE_CR_SEL_ssu_cr_right0;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.ssu_cr_right1 = _PARAM_SRIC_EDGE_CR_SEL_ssu_cr_right1;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.rep_cr_i = _PARAM_SRIC_EDGE_CR_SEL_rep_cr_i;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.rep_cr_e = _PARAM_SRIC_EDGE_CR_SEL_rep_cr_e;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.fg0_int_half = tTestSSURegiConfig.fg0_int_half;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.fg1_int_half = _PARAM_SRIC_EDGE_CR_SEL_fg1_int_half;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.pen_int_half = _PARAM_SRIC_EDGE_CR_SEL_pen_int_half;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.data_int_half = _PARAM_SRIC_EDGE_CR_SEL_data_int_half;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.ni_int_half = _PARAM_SRIC_EDGE_CR_SEL_ni_int_half;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.ssu_pre_gc_ni = _PARAM_SRIC_EDGE_CR_SEL_ssu_pre_gc_ni;
	tCRSELControlReg.CFGR_EDGE_CR_SEL_b.ssu_int_gc_ni = _PARAM_SRIC_EDGE_CR_SEL_ssu_int_gc_ni;

	SW92501_Set_Register(EDGE_CR_SEL, tCRSELControlReg.CFGR_EDGE_CR_SEL, ROIC_ALL);
//	for(ulSRICIdx = 0; ulSRICIdx < MSPI_NUM; ulSRICIdx++)
//	{
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_cr_left0 = muChargeRemoveSelRegVal_ROIC0[0][ulSRICIdx];
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_cr_left1 = muChargeRemoveSelRegVal_ROIC0[1][ulSRICIdx];
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_cr_right0 = muChargeRemoveSelRegVal_ROIC0[2][ulSRICIdx];
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_cr_right1 = muChargeRemoveSelRegVal_ROIC0[3][ulSRICIdx];
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.rep_cr_i = __rep_cr_i;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.rep_cr_e = __rep_cr_e;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.fg0_int_half = tTestSSURegiConfig.fg0_int_half;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.fg1_int_half = __fg1_int_half;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.pen_int_half = __pen_int_half;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.data_int_half = __data_int_half;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ni_int_half = __ni_int_half;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_pre_gc_ni = __ssu_pre_gc_ni;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_int_gc_ni = __ssu_int_gc_ni;
//	}
//	SW92501_Each_Set_Register(EDGE_CR_SEL, (uint16_t *)&tCRSELControlReg[0], ROIC_0);
//
//	for(ulSRICIdx = 0; ulSRICIdx < MSPI_NUM; ulSRICIdx++)
//	{
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_cr_left0 = muChargeRemoveSelRegVal_ROIC1[0][ulSRICIdx];
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_cr_left1 = muChargeRemoveSelRegVal_ROIC1[1][ulSRICIdx];
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_cr_right0 = muChargeRemoveSelRegVal_ROIC1[2][ulSRICIdx];
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_cr_right1 = muChargeRemoveSelRegVal_ROIC1[3][ulSRICIdx];
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.rep_cr_i = __rep_cr_i;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.rep_cr_e = __rep_cr_e;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.fg0_int_half = tTestSSURegiConfig.fg0_int_half;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.fg1_int_half = __fg1_int_half;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.pen_int_half = __pen_int_half;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.data_int_half = __data_int_half;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ni_int_half = __ni_int_half;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_pre_gc_ni = __ssu_pre_gc_ni;
//		tCRSELControlReg[ulSRICIdx].CFGR_EDGE_CR_SEL_b.ssu_int_gc_ni = __ssu_int_gc_ni;
//	}
//	SW92501_Each_Set_Register(EDGE_CR_SEL, (uint16_t *)&tCRSELControlReg[0], ROIC_1);

	/*
	 * Edge
	 */
	for(ulMuxSetIdx = 0; ulMuxSetIdx < 6; ulMuxSetIdx+=2)
	{
		/*
		 * RO Setting
		 */
		for(ulSRICIdx = 0; ulSRICIdx < MSPI_NUM; ulSRICIdx++)
		{
			tCRControlReg[ulSRICIdx].CFGR_SSU_CR_b.ssu_cr_even_mux_e = muChargeRemoveRegVal_ROIC0_Edge[ulMuxSetIdx][ulSRICIdx] + ulCRApplyOffsetValue;
			tCRControlReg[ulSRICIdx].CFGR_SSU_CR_b.ssu_cr_odd_mux_e = muChargeRemoveRegVal_ROIC0_Edge[ulMuxSetIdx+1][ulSRICIdx] + ulCRApplyOffsetValue;
		}
		SW92501_Each_Set_Register(SSU_CR_E00 + ulMuxSetIdx, (uint16_t *)&tCRControlReg[0], ROIC_0);
		/*
		 * R1 Setting
		 */
		for(ulSRICIdx = 0; ulSRICIdx < MSPI_NUM; ulSRICIdx++)
		{
			tCRControlReg[ulSRICIdx].CFGR_SSU_CR_b.ssu_cr_even_mux_e = muChargeRemoveRegVal_ROIC1_Edge[ulMuxSetIdx][ulSRICIdx] + ulCRApplyOffsetValue;
			tCRControlReg[ulSRICIdx].CFGR_SSU_CR_b.ssu_cr_odd_mux_e = muChargeRemoveRegVal_ROIC1_Edge[ulMuxSetIdx+1][ulSRICIdx] + ulCRApplyOffsetValue;
		}
		SW92501_Each_Set_Register(SSU_CR_E00 + ulMuxSetIdx, (uint16_t *)&tCRControlReg[0], ROIC_1);
	}

	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);



	PWMDRV_Cmd(ENABLE);
	sr.CFGR_SNSR_STR_b.sensing_run = 1;
	sr.CFGR_SNSR_STR_b.cont_sensing = 1;
	sr.CFGR_SNSR_STR_b.tg_rst = 0;
	sr.CFGR_SNSR_STR_b.sw_rst = 0;
	SW92501_Set_Register(SNSR_STR, sr.CFGR_SNSR_STR, ROIC_0);
	MSPI_Set_AITMODE(HAL_GetSensingMode());

#if USED_BIAS_ON_OFF_CTRL
	{
		extern __IO uint32_t gulBiasOnOffCtrl_FrameCheckCnt;
		gulBiasOnOffCtrl_FrameCheckCnt = 0;
	}
#endif /* USED_BIAS_ON_OFF_CTRL */

	MSPI->SPISTART = 0x3F;

	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);

	MSPI->SPISTART = 0x3F;

	for(ulSkipCount=0; ulSkipCount<6; ulSkipCount++)
	{
		module_wait_full_sample_done(); // 1Frame Skip하자!!
	}
	tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_FINISH;
}

void app_test_operation_SRIC_CR_AutoCalibration(void)
{
	uint32_t ulCalCompCount = 0;
	uint32_t ulAvrFrameCount = 0;
	uint32_t r, c;
	uint32_t ulROIC_Row_Idx = 0;
	uint32_t ulROIC_Col_Idx = 0;
	uint32_t ulROIC_Type_Idx = 0;
	uint32_t ulTempData;
	__IO eTestSubOpStatus_t eTestSubOperStatus;
	__IO int16_t tTestTargetValue = (int16_t)tTestOperParam.ulCRAutoCal_TargetValue;

	for(r  =0; r < 6; r++)
	{
		for(c = 0; c < MSPI_NUM; c++)
		{
			/*
			 * Charge Remove Register Value를 0부터 시작 해서 하나씩 올려 가면서 Target Value에 가장 근사치에 있는 갑들을 설정하도록 한다.
			 */
			muChargeRemoveRegVal_ROIC0_Inner[r][c] = 0;
			muChargeRemoveRegVal_ROIC1_Inner[r][c] = 0;
			muChargeRemoveRegVal_ROIC0_Edge[r][c] = 0;
			muChargeRemoveRegVal_ROIC1_Edge[r][c] = 0;

//			/*
//			 * Charge Remove Edge Sel Value값 설정.
//			 */
//			if(r < 4)
//			{
//				muChargeRemoveSelRegVal_ROIC0[r][c] = 1;
//				muChargeRemoveSelRegVal_ROIC1[r][c] = 1;
//			}

			muRawDataMax_ROIC0_Inner[r][c] = 1;
			muRawDataMax_ROIC1_Inner[r][c] = 1;
			muRawDataMax_ROIC0_Edge[r][c] = 1;
			muRawDataMax_ROIC1_Edge[r][c] = 1;
			muPastRawDataMax_ROIC0_Inner[r][c] = CHARGE_R_RAWDATA_MAX_VAL;
			muPastRawDataMax_ROIC1_Inner[r][c] = CHARGE_R_RAWDATA_MAX_VAL;
			muPastRawDataMax_ROIC0_Edge[r][c] = CHARGE_R_RAWDATA_MAX_VAL;
			muPastRawDataMax_ROIC1_Edge[r][c] = CHARGE_R_RAWDATA_MAX_VAL;
		}
	}

	app_test_operation_MODULE_Reset(YES);

	for(r = 0; r < ROW_MAX; r++)
	{
		for(c = 0; c < COL_MAX; c++)
		{
			HAL_WRITE_BASELINE_IMAGE(r, c, 0);
			HAL_WRITE_DELTA_IMAGE(r, c, 0);
		}
	}
	tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_START;

	eTestSubOperStatus = tTestOperParam.elTestSub_Status;
	while(eTestSubOperStatus == TEST_SUB_OPER_CR_AUTO_CALIBRATION)
	{
		eTestSubOperStatus = tTestOperParam.elTestSub_Status;
		if(module_wait_full_sample_done())
		{
			if(ulCalCompCount < CHARGE_R_TOTAL_COUNT_NUM)
			{
				/*
				 * RawData는 CHARGE_R_FRAME_AVR_NUM개수 만큼 취합 후 평균을 내서 계산한다.
				 */
				if(ulAvrFrameCount < CHARGE_R_RAWDATA_AVR_FRAME_NUM)
				{
					for(r=0; r<ROW_MAX; r++)
					{
						for(c=0; c<COL_MAX; c++)
						{
							ulTempData = HAL_READ_RAW_IMAGE(r, c);
							ulTempData += HAL_READ_BASELINE_IMAGE(r, c);
							HAL_WRITE_BASELINE_IMAGE(r, c, ulTempData);
						}
					}
					ulAvrFrameCount++;
				}

				if(ulAvrFrameCount == CHARGE_R_RAWDATA_AVR_FRAME_NUM)
				{
					ulAvrFrameCount = 0;
					/*
					 * 평균을 낸 RawData와 CHARGE_REMOVE_TARGET_VAL의 차이를 구한 후, 각 Range마다 가장 큰 값을 갖는 차이값을 저장 한다.
					 */
					for(r=0; r<ROW_MAX; r++)
					{
						for(c=0; c<COL_MAX; c++)
						{
							ulROIC_Row_Idx = r / CHARGE_R_ROIC_ROW_NUM;
#if USED_MUX_SENSING_REVERSE
							ulROIC_Row_Idx = 5 - ulROIC_Row_Idx;
#endif /* USED_MUX_SENSING_REVERSE */
							ulROIC_Col_Idx = c / CHARGE_R_ROIC_COL_NUM;
							ulROIC_Type_Idx = c % CHARGE_R_ROIC_COL_NUM;

							ulTempData = HAL_READ_BASELINE_IMAGE(r, c) / CHARGE_R_RAWDATA_AVR_FRAME_NUM;
							ulTempData = (uint16_t)ABS(((int16_t)ulTempData - tTestTargetValue));
							HAL_WRITE_BASELINE_IMAGE(r, c, 0);

							if(vulROICCol_TypeInfo[ulROIC_Type_Idx] == Charge_e)
							{
								if(ulROIC_Col_Idx % 2 == CHARGE_R_ROIC0)
								{
									if(muRawDataMax_ROIC0_Edge[ulROIC_Row_Idx][ulROIC_Col_Idx/2] < ulTempData)
									{
										muRawDataMax_ROIC0_Edge[ulROIC_Row_Idx][ulROIC_Col_Idx/2] = ulTempData;
									}
								}
								else
								{
									if(muRawDataMax_ROIC1_Edge[ulROIC_Row_Idx][ulROIC_Col_Idx/2] < ulTempData)
									{
										muRawDataMax_ROIC1_Edge[ulROIC_Row_Idx][ulROIC_Col_Idx/2] = ulTempData;
									}
								}
							}
							else
							{
								if(ulROIC_Col_Idx % 2 == CHARGE_R_ROIC0)
								{
									if(muRawDataMax_ROIC0_Inner[ulROIC_Row_Idx][ulROIC_Col_Idx/2] < ulTempData)
									{
										muRawDataMax_ROIC0_Inner[ulROIC_Row_Idx][ulROIC_Col_Idx/2] = ulTempData;
									}
								}
								else
								{
									if(muRawDataMax_ROIC1_Inner[ulROIC_Row_Idx][ulROIC_Col_Idx/2] < ulTempData)
									{
										muRawDataMax_ROIC1_Inner[ulROIC_Row_Idx][ulROIC_Col_Idx/2] = ulTempData;
									}
								}
							}
						}
					}

					for(r=0; r<6; r++)
					{
						for(c=0; c<MSPI_NUM; c++)
						{
							if(muPastRawDataMax_ROIC0_Inner[r][c] != CHARGE_R_RAWDATA_FINISH_VAL)
							{
								if(muRawDataMax_ROIC0_Inner[r][c] <= muPastRawDataMax_ROIC0_Inner[r][c])
								{
									muChargeRemoveRegVal_ROIC0_Inner[r][c]++;
									if(muChargeRemoveRegVal_ROIC0_Inner[r][c] > CHARGE_R_REG_MAX_VAL)
									{
										muChargeRemoveRegVal_ROIC0_Inner[r][c] = CHARGE_R_REG_MAX_VAL;
										ulCalCompCount++;
										muPastRawDataMax_ROIC0_Inner[r][c] = CHARGE_R_RAWDATA_FINISH_VAL;
									}
									else
									{
										muPastRawDataMax_ROIC0_Inner[r][c] = muRawDataMax_ROIC0_Inner[r][c];
									}
								}
								else
								{
									muChargeRemoveRegVal_ROIC0_Inner[r][c]--;
									ulCalCompCount++;
									muPastRawDataMax_ROIC0_Inner[r][c] = CHARGE_R_RAWDATA_FINISH_VAL;
								}
							}

							if(muPastRawDataMax_ROIC1_Inner[r][c] != CHARGE_R_RAWDATA_FINISH_VAL)
							{
								if(muRawDataMax_ROIC1_Inner[r][c] <= muPastRawDataMax_ROIC1_Inner[r][c])
								{
									muChargeRemoveRegVal_ROIC1_Inner[r][c]++;
									if(muChargeRemoveRegVal_ROIC1_Inner[r][c] > CHARGE_R_REG_MAX_VAL)
									{
										muChargeRemoveRegVal_ROIC1_Inner[r][c] = CHARGE_R_REG_MAX_VAL;
										ulCalCompCount++;
										muPastRawDataMax_ROIC1_Inner[r][c] = CHARGE_R_RAWDATA_FINISH_VAL;
									}
									else
									{
										muPastRawDataMax_ROIC1_Inner[r][c] = muRawDataMax_ROIC1_Inner[r][c];
									}
								}
								else
								{
									muChargeRemoveRegVal_ROIC1_Inner[r][c]--;
									ulCalCompCount++;
									muPastRawDataMax_ROIC1_Inner[r][c] = CHARGE_R_RAWDATA_FINISH_VAL;
								}
							}

							if(muPastRawDataMax_ROIC0_Edge[r][c] != CHARGE_R_RAWDATA_FINISH_VAL)
							{
								if(muRawDataMax_ROIC0_Edge[r][c] <= muPastRawDataMax_ROIC0_Edge[r][c])
								{
									muChargeRemoveRegVal_ROIC0_Edge[r][c]++;
									if(muChargeRemoveRegVal_ROIC0_Edge[r][c] > CHARGE_R_REG_MAX_VAL)
									{
										muChargeRemoveRegVal_ROIC0_Edge[r][c] = CHARGE_R_REG_MAX_VAL;
										ulCalCompCount++;
										muPastRawDataMax_ROIC0_Edge[r][c] = CHARGE_R_RAWDATA_FINISH_VAL;
									}
									else
									{
										muPastRawDataMax_ROIC0_Edge[r][c] = muRawDataMax_ROIC0_Edge[r][c];
									}
								}
								else
								{
									muChargeRemoveRegVal_ROIC0_Edge[r][c]--;
									ulCalCompCount++;
									muPastRawDataMax_ROIC0_Edge[r][c] = CHARGE_R_RAWDATA_FINISH_VAL;
								}
							}

							if(muPastRawDataMax_ROIC1_Edge[r][c] != CHARGE_R_RAWDATA_FINISH_VAL)
							{
								if(muRawDataMax_ROIC1_Edge[r][c] <= muPastRawDataMax_ROIC1_Edge[r][c])
								{
									muChargeRemoveRegVal_ROIC1_Edge[r][c]++;
									if(muChargeRemoveRegVal_ROIC1_Edge[r][c] > CHARGE_R_REG_MAX_VAL)
									{
										muChargeRemoveRegVal_ROIC1_Edge[r][c] = CHARGE_R_REG_MAX_VAL;
										ulCalCompCount++;
										muPastRawDataMax_ROIC1_Edge[r][c] = CHARGE_R_RAWDATA_FINISH_VAL;
									}
									else
									{
										muPastRawDataMax_ROIC1_Edge[r][c] = muRawDataMax_ROIC1_Edge[r][c];
									}
								}
								else
								{
									muChargeRemoveRegVal_ROIC1_Edge[r][c]--;
									ulCalCompCount++;
									muPastRawDataMax_ROIC1_Edge[r][c] = CHARGE_R_RAWDATA_FINISH_VAL;
								}
							}

							muRawDataMax_ROIC0_Inner[r][c] = 0;
							muRawDataMax_ROIC1_Inner[r][c] = 0;
							muRawDataMax_ROIC0_Edge[r][c] = 0;
							muRawDataMax_ROIC1_Edge[r][c] = 0;
						}
					}

					if(ulCalCompCount == CHARGE_R_TOTAL_COUNT_NUM)
					{
						for(r=0; r<6; r++)
						{
							for(c=0; c<MSPI_NUM; c++)
							{
								HAL_WRITE_DELTA_IMAGE(r, c, muChargeRemoveRegVal_ROIC0_Inner[r][c]);
								HAL_WRITE_DELTA_IMAGE(r+6, c, muChargeRemoveRegVal_ROIC1_Inner[r][c]);
								HAL_WRITE_DELTA_IMAGE(r+12, c, muChargeRemoveRegVal_ROIC0_Edge[r][c]);
								HAL_WRITE_DELTA_IMAGE(r+18, c, muChargeRemoveRegVal_ROIC1_Edge[r][c]);
							}
						}
					}

					app_test_operation_MODULE_Reset(YES);
				}
			}
			else
			{
				protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
				protocol_LogPaddedMatrix(LT_INTENSITY, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 82/*MAX Intensity*/);

			}
		}
	}

	tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_FINISH;
}
#endif /* USED_TEST_OPERATION_ENABLE */
