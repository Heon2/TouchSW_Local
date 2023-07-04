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

#include "hal_def.h"
#include "app_def.h"
#include "protocol_def.h"
#include "hal_def.h"
#include "module_def.h"
#if USED_NEW_CONFIG_PARAMETER
#include "param_def.h"
#else /* USED_NEW_CONFIG_PARAMETER */
#include "custom_def.h"
#endif /* USED_NEW_CONFIG_PARAMETER */
#include "protocol_def.h"


#if USED_TEST_OPERATION_ENABLE

typedef struct
{
	uint32_t ulPWMFrequency;
	uint32_t ulPWMInitDelay;
	uint32_t ulPWMIntervalDelay;
	uint32_t ulPWMEndDelay;
	uint32_t ulInternalTSyncPeriodClock;
	uint32_t ulInternalTSyncLHBNum;

} t_TestPWMRegiConfig_t;

#define TEST_PWM_HDMI_X_TSYNC_PRIOD_TIME		((1030*12)+4)
#define TEST_PWM_HDMI_O_TSYNC_PRIOD_TIME		(1021*12)
#define TEST_PWM_TSYNC_PRIOD_TIME	TEST_PWM_HDMI_O_TSYNC_PRIOD_TIME


__IO t_TestPWMRegiConfig_t tTestPWMRegiConfig = {
	.ulPWMFrequency = PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz,
	.ulPWMInitDelay = PWMDRV_DEF_PRE_1_PRE_DLY,
	.ulPWMIntervalDelay = PWMDRV_DEF_FG_F_F0_ACT_DLY_usec,
	.ulPWMEndDelay = PWMDRV_DEF_FG_F_F1_END_DLY_usec,
	.ulInternalTSyncPeriodClock = TEST_PWM_TSYNC_PRIOD_TIME,
	.ulInternalTSyncLHBNum = 16
};

__IO uint32_t gtestTSyncInRisingCnt = 0;
__IO uint32_t gtestTSyncInFallingCnt = 0;
__IO uint32_t gtestTSuncInBothCnt = 0;

void app_test_pwm_InterruptHandler(void)
{
	if(PWMDRV->INTR_ST_b.MIS_FSM_ON != 0)
	{
		PWMDRV->INTR_CLR_b.FSM_ON = 0x1;
	}

	if(PWMDRV->INTR_ST_b.MIS_VSYNC_IN_EXT != 0)
	{
		PWMDRV->INTR_CLR_b.VSYNC_IN_EXT = 0x1;
		gtestTSyncInRisingCnt = 0;
		gtestTSyncInFallingCnt = 0;
		gtestTSuncInBothCnt = 0;
	}

	if(PWMDRV->INTR_ST_b.MIS_TSYNC_IN_EXT != 0)
	{
		PWMDRV->INTR_CLR_b.TSYNC_IN_EXT = 0x1;
		gtestTSuncInBothCnt++;
		if(gtestTSuncInBothCnt % 2 == 1)
		{
			gtestTSyncInFallingCnt++;
			if(gtestTSyncInFallingCnt == 1)
			{
				// T-Sync Out Generation!!
				PWMDRV->FW_CTRL_b.VSYNC_IN = 1;
			}
		}
		else
		{
			gtestTSyncInRisingCnt++;
		}
	}
}

void app_test_pwm_Set_TSync_LHBnPeriod(bool_t bIsInit)
{
	if(!bIsInit)
	{
		while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
		while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
	}
	PWMDRV->IN_CTRL_b.FR_TSYNC_PRD = tTestPWMRegiConfig.ulInternalTSyncPeriodClock;//us_to_cnt_at_12MHz(tTestPWMRegiConfig.ulInternalTSyncPeriod);
	PWMDRV->IN_CTRL_b.FR_TSYNC_NUM = tTestPWMRegiConfig.ulInternalTSyncLHBNum;
}

void app_test_pwm_Set_PWM_Delay_Pulse(bool_t bIsInit)
{
//	if(!bIsInit)
//	{
//		while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
//		while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
//	}
//
//	PWMDRV->PRE_1_b.PRE_DLY = PWM_us(tTestPWMRegiConfig.ulPWMInitDelay);
//	PWMDRV->GBL_b.TSYNC_FREQ_EN_FG_F = 1;
//	PWMDRV_FG_F_F0_ACT(PWM_Full_PRD_KHz(tTestPWMRegiConfig.ulPWMFrequency), PWM_Half_PRD_KHz(tTestPWMRegiConfig.ulPWMFrequency), (__num_pre_pwm + __num_set_pwm + __num_act_pwm), PWM_us(tTestPWMRegiConfig.ulPWMIntervalDelay), 2);		// 1 Mux 16EA
//	PWMDRV_FG_F_F1_ACT(PWM_Full_PRD_KHz(tTestPWMRegiConfig.ulPWMFrequency), PWM_Half_PRD_KHz(tTestPWMRegiConfig.ulPWMFrequency), (__num_set_pwm + __num_act_pwm), PWM_us(tTestPWMRegiConfig.ulPWMEndDelay), 1);				// 1 Mux 16EA
//	PWMDRV_FG_F_F2_ACT(PWM_Full_PRD_KHz(tTestPWMRegiConfig.ulPWMFrequency), PWM_Half_PRD_KHz(tTestPWMRegiConfig.ulPWMFrequency), 0, 0, 3);				// 1 Mux 16EA
//	PWMDRV_FG_F_F3_ACT(PWM_Full_PRD_KHz(tTestPWMRegiConfig.ulPWMFrequency), PWM_Half_PRD_KHz(tTestPWMRegiConfig.ulPWMFrequency), 0, 0, 4);				// 1 Mux 16EA
}

void (*Fncp_PWMDRV_IRQHandler_Backup)(void);
void app_test_pwm_TSync_out_Generation_Init(void)
{
	/*
	 * V-Sync Wait
	 */
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
//	MSPI_Set_TLPMODE();
//	sr.CFGR_SNSR_STR_b.sensing_run = 1;
//	sr.CFGR_SNSR_STR_b.cont_sensing = 1;
//	sr.CFGR_SNSR_STR_b.tg_rst = 1;
//	sr.CFGR_SNSR_STR_b.sw_rst = 0;
//	SW92501_Set_Register(SNSR_STR, sr.CFGR_SNSR_STR, ROIC_0);

	PWMDRV_Cmd(DISABLE);
	PWMDRV_ITConfig(DISABLE);

	Fncp_PWMDRV_IRQHandler_Backup = Fncp_PWMDRV_IRQHandler;
	Fncp_PWMDRV_IRQHandler = &app_test_pwm_InterruptHandler;

	GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 1; // VSYNC
//	GPIO->tGPIO_DIR_0._GPIO_VSYNC = 0;  // input
	GPIO->tGPIO_AFIO_1._GPIO_TSYNC_IN = 1; // TSYNCN_IN
//	GPIO->tGPIO_DIR_0._GPIO_TSYNC_IN = 0;  // input

	GPIO->tGPIO_AFIO_1._GPIO_PWM_SRIC = 1; // PWM_SRIC
	GPIO->tGPIO_P1_0._GPIO_PWM_SRIC = 0x1;
	GPIO->tGPIO_P2_0._GPIO_PWM_SRIC = 0x1;

	GPIO->tGPIO_AFIO_1._GPIO_PWM_TPIC = 1; // PWM_TPIC (PWM_LFD)
	GPIO->tGPIO_P1_0._GPIO_PWM_TPIC = 0x1;
	GPIO->tGPIO_P2_0._GPIO_PWM_TPIC = 0x1;

	GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 1;	// TSYNCN_OUT
	GPIO->tGPIO_P1_1._GPIO_TSYNC_OUT = 0x1;
	GPIO->tGPIO_P2_1._GPIO_TSYNC_OUT = 0x1;

	/*
	 * T-Sync Generation
	 */
	//TSYNC INTERNAL MODE
	PWMDRV->GBL_b.SEL_EXT_VSYNC = 0; 			// 0:Internal 1:External
	PWMDRV->GBL_b.SEL_EXT_TSYNC = 0; 			// 0:Internal 1:External
	PWMDRV->GBL_b.SEL_FR_TSYNC	= 1; 			// 0:F/W   1:Free Running
	PWMDRV->VSWT_CFG_1_b.SEL_TSYNC_OUT = 1;		// 0:Ext, 1:Internal, 2:FreeRunning, 3:x

	app_test_pwm_Set_TSync_LHBnPeriod(YES);

	//VSYNC_IN INTERRUPT
	PWMDRV->INTR_CFG_b.VSYNC_IN_EXT_IE = INTR_CFG_ENABLE;
	PWMDRV->INTR_CFG_b.VSYNC_IN_EXT_IEV = INTR_CFG_RISING_EDGE;

	//TSYNC_IN INTERRUPT
	PWMDRV->INTR_CFG_b.TSYNC_IN_EXT_IE = INTR_CFG_ENABLE;
	PWMDRV->INTR_CFG_b.TSYNC_IN_EXT_IBE = INTR_CFG_BOTH_EDGE;
	PWMDRV->INTR_CFG_b.TSYNC_IN_EXT_IEV = INTR_CFG_RISING_EDGE;

	//TSYNC_OUT INTERRUPT
	PWMDRV->INTR_CFG_b.TSYNC_OUT_EXT_IE = INTR_CFG_DISABLE;
//	PWMDRV->INTR_CFG_b.TSYNC_OUT_EXT_IBE = INTR_CFG_BOTH_EDGE;
	PWMDRV->INTR_CFG_b.TSYNC_OUT_EXT_IEV = INTR_CFG_RISING_EDGE;

	//FSM_ON INTERRUPT
	PWMDRV->INTR_CFG_b.FSM_ON_IE = INTR_CFG_ENABLE;
	PWMDRV->INTR_CFG_b.FSM_ON_IEV = 1;

	PWMDRV->FW_CTRL_b.PEN_MODE = PWMDRV_DEF_FW_CTRL_PEN_MODE;
	PWMDRV->DSSS_CFG_b.beacon_en = 1;//PWMDRV_DEF_DSSS_CFG_BEACON_EN;
	PWMDRV->DSSS_CFG_b.ping_en = PWMDRV_DEF_DSSS_CFG_PING_EN;

	// WFE Enable
	PWMDRV->WFE_CFG_0_b.ENA = 0x3F;

	// PRE TX : Not Used in Pen Mode
	PWMDRV->PRE_0_b.TX_PRD		= 0;
	PWMDRV->PRE_0_b.TX_LOW		= 0;
	PWMDRV->PRE_1_b.TX_NUM		= 0;
//	PWMDRV->PRE_1_b.PRE_DLY		= PWM_us(PWMDRV_DEF_PRE_1_PRE_DLY);
	PWMDRV->PRE_2_b.DSSS_DLY	= us_to_cnt_at_12MHz(PWMDRV_DEF_PRE_2_DSSS_DLY_12MCNT);


	// EPLG
	PWMDRV->EPLG_0_b.DLY_0_BEACON		= 0;//PWM_us(224);
	PWMDRV->EPLG_0_b.DLY_1 				= 0;
	PWMDRV->EPLG_1_b.DLY_0_PING_FG_F  	= 0;//PWM_us(184);
	PWMDRV->EPLG_1_b.DLY_0_PING_FG_L  	= 0;
	PWMDRV->EPLG_2_b.DLY_0_PING_PN_P  	= 0;
	PWMDRV->EPLG_2_b.DLY_0_PING_PN_D  	= 0;

	// Pre Tx, DSSS, Active Tx Configuration
	PWMDRV->GBL_b.ENA_PRTX_P0 = PWMDRV_DEF_GBL_ENA_PRTX_P0;
	PWMDRV->GBL_b.ENA_PRTX_D0 = PWMDRV_DEF_GBL_ENA_PRTX_D0;
	PWMDRV->GBL_b.ENA_DSSS_P  = PWMDRV_DEF_GBL_ENA_DSSS_P;
	PWMDRV->GBL_b.ENA_DSSS_D  = PWMDRV_DEF_GBL_ENA_DSSS_D;
	PWMDRV->GBL_b.ENA_PRTX_P1 = PWMDRV_DEF_GBL_ENA_PRTX_P1;
	PWMDRV->GBL_b.ENA_PRTX_D1 = PWMDRV_DEF_GBL_ENA_PRTX_D1;
	PWMDRV->GBL_b.ENA_ACTX_PD = PWMDRV_DEF_GBL_ENA_ACTX_PD;

	// For SRIC
	PWMDRV->ENA_PWM_0_b.T_0 =
	  (PWMDRV_DEF_ENA_PWM_0_T_0_DSSS)		// dsss
	| (PWMDRV_DEF_ENA_PWM_0_T_0_PRE << 1)	// pre
#if USED_ONLY_BEACON
	| (0 << 2)	// act
#else /* USED_ONLY_BEACON */
	| (PWMDRV_DEF_ENA_PWM_0_T_0_ACT << 2)	// act
#endif /* USED_ONLY_BEACON */
	| (PWMDRV_DEF_ENA_PWM_0_T_0_PRE_LFD_0 << 3)	// pre_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_0_PRE_LFD_1 << 4)	// pre_lfd_1 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_0_ACT_LFD_0 << 5)	// act_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_0_ACT_LFD_1 << 6);	// act_lfd_1


	// PWM_DATA (LFD at Pen Data)
	// For TPIC
	PWMDRV->ENA_PWM_0_b.T_1 =
#if USED_ONLY_BEACON
	  (1)		// dsss  mod
	| (0 << 1)	// pre
	| (0 << 2)	// act
	| (PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_0 << 3)	// pre_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_1 << 4)	// pre_lfd_1 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_0 << 5)	// act_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_1 << 6);	// act_lfd_1
#else /* USED_ONLY_BEACON */
	  (PWMDRV_DEF_ENA_PWM_0_T_1_DSSS)		// dsss  mod
	| (PWMDRV_DEF_ENA_PWM_0_T_1_PRE << 1)	// pre
	| (PWMDRV_DEF_ENA_PWM_0_T_1_ACT << 2)	// act
	| (PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_0 << 3)	// pre_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_1 << 4)	// pre_lfd_1 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_0 << 5)	// act_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_1 << 6);	// act_lfd_1
#endif /* USED_ONLY_BEACON */


	app_test_pwm_Set_PWM_Delay_Pulse(YES);

//	PWMDRV->GBL_b.TSYNC_FREQ_EN_FG_F = 1;
//	PWMDRV_FG_F_F0_ACT(PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2), (PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2), (__num_pre_pwm + __num_set_pwm + __num_act_pwm), PWM_us(PWMDRV_DEF_FG_F_F0_ACT_DLY_usec), 2);		// 1 Mux 16EA
//	PWMDRV_FG_F_F1_ACT(PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2), (PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2), (__num_set_pwm + __num_act_pwm), PWM_us(PWMDRV_DEF_FG_F_F1_END_DLY_usec), 1);				// 1 Mux 16EA
//	PWMDRV_FG_F_F2_ACT(PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2), (PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2), 0, 0, 3);				// 1 Mux 16EA
//	PWMDRV_FG_F_F3_ACT(PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2), (PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2), 0, 0, 4);				// 1 Mux 16EA

//	PWMDRV_Set_Finger_LHB();

	PWMDRV_ITConfig(ENABLE);


	/*
	 * V-Sync Wait
	 */
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
	PWMDRV_Cmd(ENABLE);
}

void app_test_pwm_TSync_out_Generation_DeInit(void)
{
	/*
	 * V-Sync Wait
	 */
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
//	MSPI_Set_TLPMODE();
//	sr.CFGR_SNSR_STR_b.sensing_run = 1;
//	sr.CFGR_SNSR_STR_b.cont_sensing = 1;
//	sr.CFGR_SNSR_STR_b.tg_rst = 1;
//	sr.CFGR_SNSR_STR_b.sw_rst = 0;
//	SW92501_Set_Register(SNSR_STR, sr.CFGR_SNSR_STR, ROIC_0);

	PWMDRV_Cmd(DISABLE);
	PWMDRV_ITConfig(DISABLE);

	Fncp_PWMDRV_IRQHandler = Fncp_PWMDRV_IRQHandler_Backup;
	Fncp_PWMDRV_IRQHandler_Backup = NULL;

	GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 1; // VSYNC
	GPIO->tGPIO_AFIO_1._GPIO_TSYNC_IN = 1; // TSYNCN_IN

	GPIO->tGPIO_AFIO_1._GPIO_PWM_SRIC = 1; // PWM_SRIC
	GPIO->tGPIO_P1_0._GPIO_PWM_SRIC = 0x1;
	GPIO->tGPIO_P2_0._GPIO_PWM_SRIC = 0x1;

	GPIO->tGPIO_AFIO_1._GPIO_PWM_TPIC = 1; // PWM_TPIC (PWM_LFD)
	GPIO->tGPIO_P1_0._GPIO_PWM_TPIC = 0x1;
	GPIO->tGPIO_P2_0._GPIO_PWM_TPIC = 0x1;

	GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 1;	// TSYNCN_OUT
	GPIO->tGPIO_P1_1._GPIO_TSYNC_OUT = 0x1;
	GPIO->tGPIO_P2_1._GPIO_TSYNC_OUT = 0x1;

	/*
	 * TSYNC EXTERNAL MODE
	 */
	PWMDRV->GBL_b.SEL_EXT_VSYNC = 1; 			// 0:Internal 1:External
	PWMDRV->GBL_b.SEL_EXT_TSYNC = 1;
	PWMDRV->GBL_b.SEL_FR_TSYNC	= 0;
	PWMDRV->VSWT_CFG_1_b.SEL_TSYNC_OUT = 0; // 0:Ext, 1:Internal, 2:FreeRunning, 3:x

	//VSYNC INTERRUPT
	PWMDRV->INTR_CFG_b.VSYNC_IN_EXT_IE = INTR_CFG_ENABLE;
	PWMDRV->INTR_CFG_b.VSYNC_IN_EXT_IEV = INTR_CFG_RISING_EDGE;

	//TSYNC INTERRUPT
	PWMDRV->INTR_CFG_b.TSYNC_IN_EXT_IE = INTR_CFG_ENABLE;

	PWMDRV->INTR_CFG_b.TSYNC_IN_EXT_IBE = INTR_CFG_SINGLE_EDGE;
	PWMDRV->INTR_CFG_b.TSYNC_IN_EXT_IEV = INTR_CFG_RISING_EDGE;

	//TSYNC_OUT INTERRUPT
	PWMDRV->INTR_CFG_b.TSYNC_OUT_EXT_IE =  INTR_CFG_DISABLE;

	//FSM INTERRUPT
	PWMDRV->INTR_CFG_b.FSM_ON_IE = INTR_CFG_DISABLE;

	//Total 16 LHBs
	PWMDRV->VSYNC_FREQ_b.F0_TSYNC = TSYNC_LHB;

	PWMDRV->FW_CTRL_b.PEN_MODE = PWMDRV_DEF_FW_CTRL_PEN_MODE;
	PWMDRV->DSSS_CFG_b.beacon_en = 1;//PWMDRV_DEF_DSSS_CFG_BEACON_EN;
	PWMDRV->DSSS_CFG_b.ping_en = PWMDRV_DEF_DSSS_CFG_PING_EN;

	// WFE Enable
	PWMDRV->WFE_CFG_0_b.ENA = 0x3F;

	// PROG_DLY
	PWMDRV->PRLG_b.DLY_0 = 0;//PWM_us(100);
	PWMDRV->PRLG_b.DLY_1 = 0;//us_to_cnt_at_12MHz(20); // 20us

	// PRE TX : Not Used in Pen Mode
	PWMDRV->PRE_0_b.TX_PRD		= 0;
	PWMDRV->PRE_0_b.TX_LOW		= 0;
	PWMDRV->PRE_1_b.TX_NUM		= 0;
//	PWMDRV->PRE_1_b.PRE_DLY		= PWM_us(PWMDRV_DEF_PRE_1_PRE_DLY);
	PWMDRV->PRE_2_b.DSSS_DLY	= us_to_cnt_at_12MHz(PWMDRV_DEF_PRE_2_DSSS_DLY_12MCNT);


	// EPLG
	PWMDRV->EPLG_0_b.DLY_0_BEACON		= 0;//PWM_us(224);
	PWMDRV->EPLG_0_b.DLY_1 				= 0;
	PWMDRV->EPLG_1_b.DLY_0_PING_FG_F  	= 0;//PWM_us(184);
	PWMDRV->EPLG_1_b.DLY_0_PING_FG_L  	= 0;
	PWMDRV->EPLG_2_b.DLY_0_PING_PN_P  	= 0;
	PWMDRV->EPLG_2_b.DLY_0_PING_PN_D  	= 0;

	// Pre Tx, DSSS, Active Tx Configuration
	PWMDRV->GBL_b.ENA_PRTX_P0 = PWMDRV_DEF_GBL_ENA_PRTX_P0;
	PWMDRV->GBL_b.ENA_PRTX_D0 = PWMDRV_DEF_GBL_ENA_PRTX_D0;
	PWMDRV->GBL_b.ENA_DSSS_P  = PWMDRV_DEF_GBL_ENA_DSSS_P;
	PWMDRV->GBL_b.ENA_DSSS_D  = PWMDRV_DEF_GBL_ENA_DSSS_D;
	PWMDRV->GBL_b.ENA_PRTX_P1 = PWMDRV_DEF_GBL_ENA_PRTX_P1;
	PWMDRV->GBL_b.ENA_PRTX_D1 = PWMDRV_DEF_GBL_ENA_PRTX_D1;
	PWMDRV->GBL_b.ENA_ACTX_PD = PWMDRV_DEF_GBL_ENA_ACTX_PD;

	// For SRIC
	PWMDRV->ENA_PWM_0_b.T_0 =
	  (PWMDRV_DEF_ENA_PWM_0_T_0_DSSS)		// dsss
	| (PWMDRV_DEF_ENA_PWM_0_T_0_PRE << 1)	// pre
#if USED_ONLY_BEACON
	| (0 << 2)	// act
#else /* USED_ONLY_BEACON */
	| (PWMDRV_DEF_ENA_PWM_0_T_0_ACT << 2)	// act
#endif /* USED_ONLY_BEACON */
	| (PWMDRV_DEF_ENA_PWM_0_T_0_PRE_LFD_0 << 3)	// pre_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_0_PRE_LFD_1 << 4)	// pre_lfd_1 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_0_ACT_LFD_0 << 5)	// act_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_0_ACT_LFD_1 << 6);	// act_lfd_1


	// PWM_DATA (LFD at Pen Data)
	// For TPIC
	PWMDRV->ENA_PWM_0_b.T_1 =
#if USED_ONLY_BEACON
	  (1)		// dsss  mod
	| (0 << 1)	// pre
	| (0 << 2)	// act
	| (PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_0 << 3)	// pre_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_1 << 4)	// pre_lfd_1 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_0 << 5)	// act_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_1 << 6);	// act_lfd_1
#else /* USED_ONLY_BEACON */
	  (PWMDRV_DEF_ENA_PWM_0_T_1_DSSS)		// dsss  mod
	| (PWMDRV_DEF_ENA_PWM_0_T_1_PRE << 1)	// pre
	| (PWMDRV_DEF_ENA_PWM_0_T_1_ACT << 2)	// act
	| (PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_0 << 3)	// pre_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_PRE_LFD_1 << 4)	// pre_lfd_1 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_0 << 5)	// act_lfd_0 Not Used
	| (PWMDRV_DEF_ENA_PWM_0_T_1_ACT_LFD_1 << 6);	// act_lfd_1
#endif /* USED_ONLY_BEACON */

	app_test_pwm_Set_PWM_Delay_Pulse(YES);
//	PWMDRV->GBL_b.TSYNC_FREQ_EN_FG_F = 1;
//	PWMDRV_FG_F_F0_ACT(PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2), (PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2), (__num_pre_pwm + __num_set_pwm + __num_act_pwm), PWM_us(PWMDRV_DEF_FG_F_F0_ACT_DLY_usec), 2);		// 1 Mux 16EA
//	PWMDRV_FG_F_F1_ACT(PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2), (PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2), (__num_set_pwm + __num_act_pwm), 0, 1);				// 1 Mux 16EA
//	PWMDRV_FG_F_F2_ACT(PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2), (PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2), 0, 0, 3);				// 1 Mux 16EA
//	PWMDRV_FG_F_F3_ACT(PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2), (PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2), 0, 0, 4);				// 1 Mux 16EA

//	PWMDRV_Set_Finger_LHB();

	PWMDRV_ITConfig(ENABLE);

	/*
	 * V-Sync Wait
	 */
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
	PWMDRV_Cmd(ENABLE);
}
#endif /* USED_TEST_OPERATION_ENABLE */
