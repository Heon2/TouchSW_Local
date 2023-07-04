/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : pwmdrv.c
 * created on : 17. 4. 2017
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

#include "hal_def.h"
#include "module_def.h"
#ifdef _USE_APP_LGD_LIB_
#include "pwm_lib_param.h"
#endif /* _USE_APP_LGD_LIB_ */


//extern __IO uint32_t gulTsyncBothEdgeCnt;
extern __IO int PenCoordIdx;
static const tHalPwmdrvCommonConf_t * s_pktHalPwmdrvCommonConf = NULL;

#if USED_ESD_RECOVERY_CODE
uint8_t FSM_ON_FLAG 	= NO;
uint8_t MUX_COUNT_ERROR = NO;
#endif /* USED_ESD_RECOVERY_CODE */

#if (USED_LPWG_MODE_CONTROL || USED_ESD_RECOVERY_CODE)
#define SKIP_TSYNC_NUM	5
uint8_t SkipTsyncCnt;
uint8_t AbnormalTsyncCheckEn = NO;
uint64_t TsyncHighTime;
#endif /* (USED_LPWG_MODE_CONTROL || USED_ESD_RECOVERY_CODE) */		

#if USED_FRAME_SKIP_IDLE_MODE_CONTROL
uint8_t SkipFrameCnt = 0;
#endif /* USED_FRAME_SKIP_IDLE_MODE_CONTROL */

#if ABNORMAL_TSYNC_FALLING_TIME_CHECK
uint64_t TsyncFallingStartTime, TsyncRisingStartTime;
uint64_t TsyncLowTime;
bool_t abnormalTsyncLowTime = NO;

#endif

uint64_t StartTime, StartTime2;
uint64_t ScanTime, ScanTime2;
uint64_t VsynPeriod;
extern uint8_t RESET_FLAG;
volatile uint8_t FLAG_30Hz=3;
volatile uint8_t IDLE_FLAG=0;
void SRIC_Run(void);
void SRIC_Stop(void);
void PWMDRV_InterruptHandler_FullScan(void)
{
	if(PWMDRV->INTR_ST_b.MIS_TSYNC_IN_EXT != 0)
	{
		PWMDRV->INTR_CLR_b.TSYNC_IN_EXT = 0x1;

//		tHalIntrHandle.ulTSyncInBothEdgeCnt++;
//		if(tHalIntrHandle.ulTSyncInBothEdgeCnt % 2 == 1)
		if(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0)
		{
//			GPIO->tGPIO_DATA_1.tBit.GPA33 = 1; // SWV
//			GPIO->tGPIO_DATA_1.tBit.GPA33 = 0;

#if (USED_LPWG_MODE_CONTROL || USED_ESD_RECOVERY_CODE)
			if(AbnormalTsyncCheckEn)
			{
				ScanTime = (uint64_t)getLongSysTick();
				if(StartTime > ScanTime)
				{
					TsyncHighTime = (StartTime-ScanTime)/(TMCU_MAIN_TRIM_CLOCK_SPEED*1000);
					if(TsyncHighTime < 10/*13ms(60Hz)-2ms-1ms*/ || TsyncHighTime > 28/*26ms(30Hz)+2ms*/)
					{
						//Reset mspi mux count
						MSPI->SPISTART = 0x3F;
					}
				}
			}
			else
			{
				if(SkipTsyncCnt < SKIP_TSYNC_NUM) 
				{
					SkipTsyncCnt++;
				}
				else
				{
					SkipTsyncCnt = 0;
					AbnormalTsyncCheckEn = YES;
				}
			}
#endif /* (USED_LPWG_MODE_CONTROL || USED_ESD_RECOVERY_CODE) */		
			
#if USED_IDLE_MODE_CONTROL
//			if(IDLE_FLAG)
//			{
//				if(FLAG_30Hz==1)
//				{
//					//s_pktHalPwmdrvCommonConf->tPWMDRV_ENA_PWM[ePWM_PARAM_FINGER].tBit.ACT_ENA_T0 = 0;
//					PWMDRV->ENA_PWM_0 = 0;	//t0 sric tx, t1 tpic

//					FLAG_30Hz=0;
//				}
//				else if(FLAG_30Hz==0)
//				{
//					FLAG_30Hz=1;
//					PWMDRV->ENA_PWM_0 = 0x00002306;
//				}
//			}

			if(IDLE_FLAG==IDLE_OPER)	// sric control
			{
				if(FLAG_30Hz==1)
				{
					//s_pktHalPwmdrvCommonConf->tPWMDRV_ENA_PWM[ePWM_PARAM_FINGER].tBit.ACT_ENA_T0 = 0;
					PWMDRV->ENA_PWM_0 = 0;	//t0 sric tx, t1 tpic
					FLAG_30Hz=0;
				}
				else if(FLAG_30Hz==0)
				{
					PWMDRV->ENA_PWM_0 = 0x00002306;
					FLAG_30Hz=1;
				}
			}
#endif /* USED_IDLE_MODE_CONTROL */
			/*
			 * T-Sync Falling
			 */
			tHalIntrHandle.ulTSyncInFallingCnt++;

#if ABNORMAL_TSYNC_FALLING_TIME_CHECK
			TsyncFallingStartTime = (uint64_t)getLongSysTick();

//			if(TsyncRisingStartTime > TsyncFallingStartTime)
//			{
//				TsyncLowTime = (TsyncRisingStartTime-TsyncFallingStartTime)/(TMCU_MAIN_TRIM_CLOCK_SPEED*1000);
//				if(TsyncLowTime < 10/*13ms(60Hz)-2ms-1ms*/ || TsyncLowTime > 28/*26ms(30Hz)+2ms*/)
//				{
//					//Reset mspi mux count
//					MSPI->SPISTART = 0x3F;
//				}
//			}
#endif

#if USED_TPIC_MUXEN_ON_OFF_CONTROL
			if(HAL_GetTPICMuxEnControl())
			{
#if USED_FRAME_SKIP_IDLE_MODE_CONTROL
				if(SkipFrameCnt == 0)
				{
					GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 1;
				}
#else /* USED_FRAME_SKIP_IDLE_MODE_CONTROL */
				GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 1;
#endif /* USED_FRAME_SKIP_IDLE_MODE_CONTROL */
			}
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
		}
		else
		{	
//			GPIO->tGPIO_DATA_1.tBit.GPA33 = 1; // SWV
//			GPIO->tGPIO_DATA_1.tBit.GPA33 = 0;
//			GPIO->tGPIO_DATA_1.tBit.GPA33 = 1; // SWV
//			GPIO->tGPIO_DATA_1.tBit.GPA33 = 0;

#if (USED_LPWG_MODE_CONTROL || USED_ESD_RECOVERY_CODE)
			StartTime = (uint64_t)getLongSysTick();
#endif /* (USED_LPWG_MODE_CONTROL || USED_ESD_RECOVERY_CODE) */			
			
#if USED_FRAME_SKIP_IDLE_MODE_CONTROL
			if(IS_IDLE_MODE(HAL_GetSensingMode()))
			{
				if(SkipFrameCnt == 0)
				{
					SkipFrameCnt++;
					PWMDRV_Cmd(DISABLE);
				}
				else if(SkipFrameCnt < SKIP_FRAME_NUM_ON_IDLE_MODE)
				{
					SkipFrameCnt++;
				}
				else
				{
					SkipFrameCnt = 0;
					PWMDRV_Cmd(ENABLE);
				}
			}
			else
			{
				if(SkipFrameCnt != 0)
				{
					SkipFrameCnt = 0;
					PWMDRV_Cmd(ENABLE);
				}
			}
#endif /* USED_FRAME_SKIP_IDLE_MODE_CONTROL */
			
#if USED_IDLE_MODE_CONTROL
			if(IDLE_FLAG==IDLE_READY)
			{
				IDLE_FLAG = IDLE_OPER;
			}
			else if(IDLE_FLAG==IDLE_OPER)
			{
				if(FLAG_30Hz==0)
				{
					MSPI_Set_TLPMODE();
					SRIC_Run();
					MSPI_Set_AITMODE(HAL_GetSensingMode());
					MSPI_ITConfig(ENABLE);
					MSPI_Cmd(ENABLE);
					//IDLE_FLAG = 2;
				}
			}
			else if(IDLE_FLAG==IDLE_END)
			{
				MSPI_Set_TLPMODE();
				SRIC_Run();
				MSPI_Set_AITMODE(HAL_GetSensingMode());
				MSPI_ITConfig(ENABLE);
				MSPI_Cmd(ENABLE);
				IDLE_FLAG = NORMAL_OPER;
			}
#endif /* USED_IDLE_MODE_CONTROL */
			
			/*
			 * T-Sync Rising
			 */
			tHalIntrHandle.ulTSyncInRisingCnt++;

#if ABNORMAL_TSYNC_FALLING_TIME_CHECK
			TsyncRisingStartTime = (uint64_t)getLongSysTick();

			if(TsyncRisingStartTime < TsyncFallingStartTime)
			{
//				TsyncLowTime = (TsyncFallingStartTime-TsyncRisingStartTime);
				TsyncLowTime = (TsyncFallingStartTime-TsyncRisingStartTime)/(TMCU_MAIN_TRIM_CLOCK_SPEED*1000);  // msec
				TsyncLowTime = (TsyncFallingStartTime-TsyncRisingStartTime)/(TMCU_MAIN_TRIM_CLOCK_SPEED);  // usec
				if(TsyncLowTime < 3500)  // Tsync In Low 3.5ms check...
				{
					abnormalTsyncLowTime = YES;
					//Reset mspi mux count
					MSPI->SPISTART = 0x3F;
				}
				else
				{
					abnormalTsyncLowTime = NO;
				}
			}
#endif

#if (USED_TPIC_MUXEN_ON_OFF_CONTROL && USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM == NO)
			if(HAL_GetTPICMuxEnControl())
            {
    			GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 0;
            }
#endif /* (USED_TPIC_MUXEN_ON_OFF_CONTROL && USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM == NO) */
		}
	}
	
	if(PWMDRV->INTR_ST_b.MIS_VSYNC_IN_EXT != 0)
	{
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 1; // SWV
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 0;
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 1; // SWV
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 0;
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 1; // SWV
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 0;

#if USED_ESD_RECOVERY_CODE
		if(AbnormalTsyncCheckEn)
		{
			ScanTime2 = (uint64_t)getLongSysTick();
			if(StartTime2 > ScanTime2)
			{
				VsynPeriod = (StartTime2-ScanTime2)/(TMCU_MAIN_TRIM_CLOCK_SPEED*1000);
				if(VsynPeriod < 12/*16.6ms(60Hz)-2.5ms-1ms*/ || VsynPeriod > 36/*33.3ms(30Hz)+2.5ms*/)
				{
					if(GPIO->tGPIO_DATA_1._GPIO_LCD_ON == 0x1)
					{
						//Reset mspi mux count
						MSPI->SPISTART = 0x3F;
					}
				}
			}
		}
		StartTime2 = (uint64_t)getLongSysTick();
#endif /* USED_ESD_RECOVERY_CODE */ 
		
		PWMDRV->INTR_CLR_b.VSYNC_IN_EXT = 0x1;
		tHalIntrHandle.ulVSyncFlag = 1;

		tHalIntrHandle.ulTSyncInBothEdgeCnt = 0;
		tHalIntrHandle.ulTSyncInFallingCnt = 0;
		tHalIntrHandle.ulTSyncInRisingCnt = 0;

		if(tHalIntrHandle.ulInitFirstFrame < 20)
		{
			tHalIntrHandle.ulInitFirstFrame++;
		}

		if(HAL_CheckSensningModeChange(HAL_GetSensingChangeMode()))
		{
			HAL_SetSensingChangeMode(SM_CHANGE_COMPLETE);
		}
#if USED_ESD_RECOVERY_CODE
		if(MUX_COUNT_ERROR == YES)
		{
			MSPI->SPISTART = 0x3F;
		}
		FSM_ON_FLAG 	= NO;
		MUX_COUNT_ERROR = NO;
#endif /* USED_ESD_RECOVERY_CODE */
	}

	if(PWMDRV->INTR_ST_b.MIS_FSM_ON != 0)
	{		
		PWMDRV->INTR_CLR_b.FSM_ON = 0x1;

//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 1; // SWV
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 0;
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 1; // SWV
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 0;
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 1; // SWV
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 0;
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 1; // SWV
//		GPIO->tGPIO_DATA_1.tBit.GPA33 = 0;

#if USED_TPIC_MUXEN_ON_OFF_CONTROL 
#if USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM
		if(HAL_GetTPICMuxEnControl())
        {
			GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 0;
        }
#elif USED_LPWG_MODE_CONTROL
		if(IS_LPWG_MODE(HAL_GetSensingMode()))
		{
			if(HAL_GetTPICMuxEnControl())
            {
    			GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 0;
            }
		}
#endif /* USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM */
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
		
#if USED_ECLK_ON_OFF_CONTROL
		if(HAL_GetECLKOnOffControl())
		{
			HAL_ECLK_Off();
		}
#endif /* USED_ECLK_ON_OFF_CONTROL */

#if USED_ESD_RECOVERY_CODE
		FSM_ON_FLAG = YES;
#endif /* USED_ESD_RECOVERY_CODE */
	}
#ifdef MODE_I2C
	QueueCommonData_I2C();
#else
//	QueueCommonData_USB();
#endif
}

void PWMDRV_InterruptHandler_PartialScan(void)
{

#ifdef MODE_I2C
	QueueCommonData_I2C();
#else
	QueueCommonData_USB();
#endif
}

void PWMDRV_InterruptHandler_LPWG(void)
{
	if(PWMDRV->INTR_ST_b.MIS_FSM_ON != 0)
	{
		PWMDRV->INTR_CLR_b.FSM_ON = 0x1;
	}

//	if(PWMDRV->INTR_ST_b.MIS_VSYNC_IN_EXT != 0)
//	{
//		PWMDRV->INTR_CLR_b.VSYNC_IN_EXT = 0x1;
////#if (USED_OPERATION_STAND_ALONE_DISPLAY_ON)
//		gTSyncInFallingCnt = 0;
//		gulTsyncBothEdgeCnt = 0;
////#endif /* (USED_OPERATION_STAND_ALONE_DISPLAY_ON) */
//
//		if(HAL_CheckSensningModeChange(HAL_GetSensingChangeMode()))
//		{
//			HAL_SetSensingChangeMode(SM_CHANGE_COMPLETE);
//		}
//	}

	if(PWMDRV->INTR_ST_b.MIS_TSYNC_OUT_EXT != 0)
	{
		PWMDRV->INTR_CLR_b.TSYNC_OUT_EXT = 0x1;
	}

#ifdef MODE_I2C
	QueueCommonData_I2C();
#else
	QueueCommonData_USB();
#endif
}

#if USED_OPERATION_STAND_ALONE
void PWMDRV_InterruptHandler_FullScan_Standalone(void)
{

}

void PWMDRV_InterruptHandler_PartialScan_Standalone(void)
{

}
#endif /* USED_OPERATION_STAND_ALONE */

void PWMDRV_Initialize(void)
{
	s_pktHalPwmdrvCommonConf = hal_pwmdrv_GetCommonConfig();
}

void PWMDRV_Init(eSENSING_MODE_t eSensingMode)
{
	if(IS_FINGER_PEN_MODE(eSensingMode))
	{
		Fncp_PWMDRV_IRQHandler = &PWMDRV_InterruptHandler_PartialScan;
	}
	else if(IS_S3_MODE(eSensingMode))
	{
		Fncp_PWMDRV_IRQHandler = &PWMDRV_InterruptHandler_LPWG;
	}
	else
	{
		Fncp_PWMDRV_IRQHandler = &PWMDRV_InterruptHandler_FullScan;
	}

	PWMDRV_GPIO_Init(eSensingMode);

	PWMDRV->VSWT_CFG_1_b.SEL_TSYNC_OUT = s_pktHalPwmdrvCommonConf->ucSelTsyncOut;
	PWMDRV->GBL = s_pktHalPwmdrvCommonConf->tPWMDRV_GBL.ulBulk;
#if USED_LPWG_MODE_CONTROL
	if(IS_LPWG_MODE(HAL_GetSensingMode()))
	{		
		PWMDRV->GBL_b.SEL_EXT_VSYNC = 0;	// 0:Internal 1:External
		PWMDRV->GBL_b.SEL_EXT_TSYNC = 0;	// 0:Internal 1:External
		PWMDRV->GBL_b.SEL_FR_TSYNC	= 1;	// 0:F/W   1:Free Running
	}
#endif /* USED_LPWG_MODE_CONTROL */
	PWMDRV->IN_CTRL = s_pktHalPwmdrvCommonConf->tPWMDRV_IN_CTRL.ulBulk;
	PWMDRV->INTR_CFG = s_pktHalPwmdrvCommonConf->tPWMDRV_INTR_CFG.ulBulk;
	PWMDRV->VSYNC_FREQ_b.F0_TSYNC = TSYNC_LHB;
	PWMDRV->FG_0 = s_pktHalPwmdrvCommonConf->tPWMDRV_FG_0.ulBulk;
	PWMDRV->FG_1 = s_pktHalPwmdrvCommonConf->tPWMDRV_FG_1.ulBulk;
	PWMDRV->PN_0 = s_pktHalPwmdrvCommonConf->tPWMDRV_PN_0.ulBulk;
	PWMDRV->PN_1 = s_pktHalPwmdrvCommonConf->tPWMDRV_PN_1.ulBulk;
	PWMDRV->EPLG_0 = s_pktHalPwmdrvCommonConf->tPWMDRV_EPLG_0.ulBulk;
	PWMDRV->EPLG_1 = s_pktHalPwmdrvCommonConf->tPWMDRV_EPLG_1.ulBulk;
	PWMDRV->EPLG_2 = s_pktHalPwmdrvCommonConf->tPWMDRV_EPLG_2.ulBulk;
	PWMDRV->PRLG = s_pktHalPwmdrvCommonConf->tPWMDRV_PRLG.ulBulk;
	PWMDRV->PRE_0 = s_pktHalPwmdrvCommonConf->tPWMDRV_PRE_0.ulBulk;
	PWMDRV->PRE_1 = s_pktHalPwmdrvCommonConf->tPWMDRV_PRE_1.ulBulk;
	PWMDRV->PRE_2 = s_pktHalPwmdrvCommonConf->tPWMDRV_PRE_2.ulBulk;

#ifdef _USE_APP_LGD_LIB_
	PWMDRV_PRE(PWM_Full_PRD_KHz(g_tPWMDRV_lib_reg.usPwmFreq), PWM_Half_PRD_KHz(g_tPWMDRV_lib_reg.usPwmFreq), g_tPWMDRV_lib_reg.ucPwmPreNum, g_tPWMDRV_lib_reg.usFullFingerPWMPreDly, s_pktHalPwmdrvCommonConf->tPWMDRV_PRE_2.tBit.DSSS_DLY);
	PWMDRV_SectionEnable(eSensingMode);

	PWMDRV_FG_F_F0_ACT(PWM_Full_PRD_KHz(g_tPWMDRV_lib_reg.usPwmFreq), PWM_Half_PRD_KHz(g_tPWMDRV_lib_reg.usPwmFreq),
			(g_tPWMDRV_lib_reg.ucPwmSetNum + g_tPWMDRV_lib_reg.ucPwmFingerActNum), g_tPWMDRV_lib_reg.usFullFingerPWMIntervalDly, g_tPWMDRV_lib_reg.ucPwmTotalMuxNum);

	PWMDRV_FG_F_F1_ACT(PWM_Full_PRD_KHz(g_tPWMDRV_lib_reg.usPwmFreq), PWM_Half_PRD_KHz(g_tPWMDRV_lib_reg.usPwmFreq),
			(g_tPWMDRV_lib_reg.ucPwmSetNum + g_tPWMDRV_lib_reg.ucPwmFingerActNum), g_tPWMDRV_lib_reg.usFullFingerPWMIntervalDly, g_tPWMDRV_lib_reg.ucPwm1stMuxStart);
//			(1+24), PWM_us(50), 12);

	PWMDRV_FG_F_F2_ACT(PWM_Full_PRD_KHz(g_tPWMDRV_lib_reg.usPwmFreq), PWM_Half_PRD_KHz(g_tPWMDRV_lib_reg.usPwmFreq),
			(g_tPWMDRV_lib_reg.ucPwmSetNum + g_tPWMDRV_lib_reg.ucPwmFingerActNum), g_tPWMDRV_lib_reg.usFullFingerPWMIntervalDly, g_tPWMDRV_lib_reg.ucPwm2ndMuxStart);
//			(1+24), PWM_us(50), 13);

	PWMDRV_FG_F_F3_ACT(PWM_Full_PRD_KHz(g_tPWMDRV_lib_reg.usNIPwmFreq), PWM_Half_PRD_KHz(g_tPWMDRV_lib_reg.usNIPwmFreq),
			(g_tPWMDRV_lib_reg.ucPwmSetNum + g_tPWMDRV_lib_reg.ucNIPwmFingerActNum), g_tPWMDRV_lib_reg.usFullFingerPWMIntervalDly, g_tPWMDRV_lib_reg.ucPwm3rdMuxStart);
#else /* _USE_APP_LGD_LIB_ */
	PWMDRV_PRE(PWM_Full_PRD_KHz(s_pktHalPwmdrvCommonConf->usPwmFreq),
			PWM_Half_PRD_KHz(s_pktHalPwmdrvCommonConf->usPwmFreq),
			s_pktHalPwmdrvCommonConf->ucPwmPreNum,
			s_pktHalPwmdrvCommonConf->tPWMDRV_PRE_1.tBit.PRE_DLY,
			s_pktHalPwmdrvCommonConf->tPWMDRV_PRE_2.tBit.DSSS_DLY);
	PWMDRV_SectionEnable(eSensingMode);
	PWMDRV_Set_Pulse_Config(eSensingMode);
#endif /* _USE_APP_LGD_LIB_ */

	PWMDRV->FW_CTRL_b.PEN_MODE = 0;
	PWMDRV->ENA_PWM_0 = s_pktHalPwmdrvCommonConf->tPWMDRV_ENA_PWM[ePWM_PARAM_FINGER].ulBulk;
	PWMDRV->DSSS_CFG_b.beacon_en = 0;
	PWMDRV->DSSS_CFG_b.beacon_en = 0;
	PWMDRV->DSSS_CFG_b.ping_en = 0;
	PWMDRV->WFE_CFG_0_b.ENA = 0x3F;

	PWMDRV_ITConfig(ENABLE);
}

void PWMDRV_GPIO_Init(eSENSING_MODE_t eSensingMode)
{
	// I/O COnfiguration
#if USED_OPERATION_STAND_ALONE
	GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 0; // VSYNC
	GPIO->tGPIO_DIR_0._GPIO_VSYNC = 0;  // input
//	GPIO->tGPIO_PD_0._GPIO_VSYNC = 1;  // Pull Down

	GPIO->tGPIO_AFIO_1._GPIO_TSYNC_IN = 0; // TSYNCN_IN
	GPIO->tGPIO_DIR_0._GPIO_TSYNC_IN = 0;  // input
//	GPIO->tGPIO_PD_0._GPIO_TSYNC_IN = 1;  // Pull Down
#else /* USED_OPERATION_STAND_ALONE */
	if(IS_S3_MODE(eSensingMode))
	{
		GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 0; // VSYNC
		GPIO->tGPIO_DIR_0._GPIO_VSYNC = 0;  // input

		GPIO->tGPIO_AFIO_1._GPIO_TSYNC_IN = 0; // TSYNCN_IN
		GPIO->tGPIO_DIR_0._GPIO_TSYNC_IN = 0;  // input
	}
	else
	{
#if USED_NEW_TCON_BOARD
		GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 0; // VSYNC
		GPIO->tGPIO_DIR_0._GPIO_VSYNC = 0;  // input
#else /* USED_NEW_TCON_BOARD */
		GPIO->tGPIO_DIR_0._GPIO_VSYNC  = 0x0;	// input
		GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 0x1;	// VSYNC
#endif /* USED_NEW_TCON_BOARD */
		GPIO->tGPIO_DIR_0._GPIO_TSYNC_IN  = 0x0;	// input
		GPIO->tGPIO_AFIO_1._GPIO_TSYNC_IN = 0x1;	// TSYNC_IN
	}
#endif /* USED_OPERATION_STAND_ALONE */

	GPIO->tGPIO_AFIO_1._GPIO_PWM_SRIC = 1; // PWM_TX
	GPIO->tGPIO_AFIO_1._GPIO_PWM_GATE = 1; // ADD (Must Enable) PWM_TPIC --> PWM_GATE
#if USED_TEST_OPERATION_ENABLE
	GPIO->tGPIO_AFIO_1._GPIO_PWM_TPIC = 1; // PWM_DATA (PWM_LFD)
#endif
	GPIO->tGPIO_P1_0._GPIO_PWM_SRIC = 0x1;
	GPIO->tGPIO_P2_0._GPIO_PWM_SRIC = 0x1;
#if USED_TEST_OPERATION_ENABLE
	GPIO->tGPIO_P1_0._GPIO_PWM_TPIC = 0x1;
	GPIO->tGPIO_P2_0._GPIO_PWM_TPIC = 0x1;
#endif
#if USED_LPWG_MODE_CONTROL
	if(IS_LPWG_MODE(HAL_GetSensingMode()))
	{				
		GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT = 0x0;
		GPIO->tGPIO_DIR_1._GPIO_TSYNC_OUT  = 0x1;
		GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 0x0;
	}
	else
	{
		GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 1;	// TSYNCN_OUT
		GPIO->tGPIO_P1_1._GPIO_TSYNC_OUT = 0x1;
		GPIO->tGPIO_P2_1._GPIO_TSYNC_OUT = 0x1;
	}
#else /* USED_LPWG_MODE_CONTROL */
	GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 1;	// TSYNCN_OUT
	GPIO->tGPIO_P1_1._GPIO_TSYNC_OUT = 0x1;
	GPIO->tGPIO_P2_1._GPIO_TSYNC_OUT = 0x1;
	
	// Temp - choigs
//	PWMDRV->GBL_b.SEL_EXT_VSYNC = 1; 			// 0:Internal 1:External
//	PWMDRV->GBL_b.SEL_EXT_TSYNC = 1;
//	PWMDRV->GBL_b.SEL_FR_TSYNC	= 0;
//	PWMDRV->VSWT_CFG_1_b.SEL_TSYNC_OUT = 0; // 0:Ext, 1:Internal, 2:FreeRunning, 3:x

	
	
#endif /* USED_LPWG_MODE_CONTROL */
	
	GPIO->tGPIO_AFIO_2._GPIO_DEBUG_B5 = 0;
	GPIO->tGPIO_DIR_1._GPIO_DEBUG_B5 = 1;  // output
	GPIO->tGPIO_DATA_1._GPIO_DEBUG_B5 = 0;
}

void PWMDRV_PRE(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t PRE_DLY, uint16_t DSSS_DLY)
{
	PWMDRV->PRE_0_b.TX_PRD		= TX_PRD;
	PWMDRV->PRE_0_b.TX_LOW		= TX_LOW;
	PWMDRV->PRE_1_b.TX_NUM		= TX_NUM;
	PWMDRV->PRE_1_b.PRE_DLY		= PRE_DLY;
	PWMDRV->PRE_2_b.DSSS_DLY	= DSSS_DLY;
}


void PWMDRV_FG_F_F0_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM)
{
	PWMDRV->FG_F_F0_ACT_0_b.TX_PRD   = TX_PRD;
	PWMDRV->FG_F_F0_ACT_0_b.TX_LOW   = TX_LOW;
	PWMDRV->FG_F_F0_ACT_1_b.TX_NUM   = TX_NUM;
	PWMDRV->FG_F_F0_ACT_1_b.DLY      = DLY;
	PWMDRV->FG_F_F0_ACT_2_b.LINE_NUM = LINE_NUM;
}

void PWMDRV_FG_F_F1_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM)
{
	PWMDRV->FG_F_F1_ACT_0_b.TX_PRD   = TX_PRD;
	PWMDRV->FG_F_F1_ACT_0_b.TX_LOW   = TX_LOW;
	PWMDRV->FG_F_F1_ACT_1_b.TX_NUM   = TX_NUM;
	PWMDRV->FG_F_F1_ACT_1_b.DLY      = DLY;
	PWMDRV->FG_F_F1_ACT_2_b.LINE_NUM = LINE_NUM;
}

void PWMDRV_FG_F_F2_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM)
{
	PWMDRV->FG_F_F2_ACT_0_b.TX_PRD   = TX_PRD;
	PWMDRV->FG_F_F2_ACT_0_b.TX_LOW   = TX_LOW;
	PWMDRV->FG_F_F2_ACT_1_b.TX_NUM   = TX_NUM;
	PWMDRV->FG_F_F2_ACT_1_b.DLY      = DLY;
	PWMDRV->FG_F_F2_ACT_2_b.LINE_NUM = LINE_NUM;
}

void PWMDRV_FG_F_F3_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM)
{
	PWMDRV->FG_F_F3_ACT_0_b.TX_PRD   = TX_PRD;
	PWMDRV->FG_F_F3_ACT_0_b.TX_LOW   = TX_LOW;
	PWMDRV->FG_F_F3_ACT_1_b.TX_NUM   = TX_NUM;
	PWMDRV->FG_F_F3_ACT_1_b.DLY      = DLY;
	PWMDRV->FG_F_F3_ACT_2_b.LINE_NUM = LINE_NUM;
}

void PWMDRV_FG_L_F0_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM)
{
	PWMDRV->FG_L_F0_ACT_0_b.TX_PRD   = TX_PRD;
	PWMDRV->FG_L_F0_ACT_0_b.TX_LOW   = TX_LOW;
	PWMDRV->FG_L_F0_ACT_1_b.TX_NUM   = TX_NUM;
	PWMDRV->FG_L_F0_ACT_1_b.DLY      = DLY;
	PWMDRV->FG_L_F0_ACT_2_b.LINE_NUM = LINE_NUM;
}

void PWMDRV_PN_P_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM)
{
	PWMDRV->PN_P_ACT_0_b.TX_PRD   = TX_PRD;
	PWMDRV->PN_P_ACT_0_b.TX_LOW   = TX_LOW;
	PWMDRV->PN_P_ACT_1_b.TX_NUM   = TX_NUM;
	PWMDRV->PN_P_ACT_1_b.DLY      = DLY;
	PWMDRV->PN_P_ACT_2_b.LINE_NUM = LINE_NUM;
}

void PWMDRV_PN_D_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM)
{
	PWMDRV->PN_D_ACT_0_b.TX_PRD   = TX_PRD;
	PWMDRV->PN_D_ACT_0_b.TX_LOW   = TX_LOW;
	PWMDRV->PN_D_ACT_1_b.TX_NUM   = TX_NUM;
	PWMDRV->PN_D_ACT_1_b.DLY      = DLY;
	PWMDRV->PN_D_ACT_2_b.LINE_NUM = LINE_NUM;
}

/************************************************************/


void PWMDRV_Cmd(FunctionalState NewState)
{
	PWMDRV->GBL_b.PWMDRV_ENA = NewState;
}

void PWMDRV_ITConfig(FunctionalState NewState)
{
	NVIC_ClearPendingIRQ(PWMDRV_IRQn);
	NVIC_SetPriority(PWMDRV_IRQn, PWMDRV_IRQn_Priority);

	if(NewState != DISABLE)
	{
		NVIC_EnableIRQ(PWMDRV_IRQn);
	}
	else
	{
		NVIC_DisableIRQ(PWMDRV_IRQn);
	}
#if (USED_LPWG_MODE_CONTROL || USED_ESD_RECOVERY_CODE)
	AbnormalTsyncCheckEn = NO;
#endif /* (USED_LPWG_MODE_CONTROL || USED_ESD_RECOVERY_CODE) */	
}

void PWMDRV_SectionEnable(eSENSING_MODE_t mode)
{
	if(IS_FINGER_PEN_MODE(mode))
	{
		PWMDRV->ENA_PWM_0 = s_pktHalPwmdrvCommonConf->tPWMDRV_ENA_PWM[ePWM_PARAM_PEN].ulBulk;
	}
	else
	{
		PWMDRV->ENA_PWM_0 = s_pktHalPwmdrvCommonConf->tPWMDRV_ENA_PWM[ePWM_PARAM_FINGER].ulBulk;
	}
}

void PWMDRV_Set_DSSS(void)
{
	uint32_t beacon_table = s_pktHalPwmdrvCommonConf->ulBeaconTable;

	PWMDRV->DSSS_INFO_1_b.BEACON_D0 = PWMDRV_DSSS_CODE_P;
	PWMDRV->DSSS_INFO_1_b.BEACON_D1 = PWMDRV_DSSS_CODE_P;
    PWMDRV->DSSS_INFO_1_b.BEACON_D2 = beacon_table & 0x0F;
	PWMDRV->DSSS_INFO_1_b.BEACON_D3 = (beacon_table >> 4) & 0x0F;
	PWMDRV->DSSS_INFO_1_b.BEACON_D4 = (beacon_table >> 8) & 0x0F;
    PWMDRV->DSSS_INFO_1_b.BEACON_D5 = 0x0d;
}

void PWMDRV_Set_VSWT(void)
{
	PWMDRV->VSWT_CFG_1_b.DLY_SEL_PWM_PRE = 0;
	PWMDRV->VSWT_CFG_1_b.DLY_SEL_PWM_ACT = 0;
	PWMDRV->VSWT_CFG_0_b.SEL_1_pwm_tx = 2;
	PWMDRV->VSWT_CFG_1_b.DLY_ENA_PWM_TX = 1;
	PWMDRV->DLY_PWM_CFG_0_b.TX = 1;
}

void PWMDRV_Set_Pulse_Config(eSENSING_MODE_t eSensingMode)
{
	if(IS_ACTIVE_MODE(eSensingMode))
	{
		uint8_t ucActNum;
		uint16_t ulNormalFreq;
		uint16_t ulPWMIntervalDly;
		
		if(IS_ACTIVE_MODE_FRQ_MAIN(eSensingMode))
		{
			ulNormalFreq = s_pktHalPwmdrvCommonConf->usPwmFreq;
			ucActNum = s_pktHalPwmdrvCommonConf->ucPwmFingerActNum;
			ulPWMIntervalDly = s_pktHalPwmdrvCommonConf->usFullFingerPWMIntervalDly;
		}
		else if(IS_ACTIVE_MODE_FRQ_HOP1(eSensingMode))
		{
			ulNormalFreq = s_pktHalPwmdrvCommonConf->usPwmNiFreq1;
			ucActNum = s_pktHalPwmdrvCommonConf->ucPwmNiActNum;
			ulPWMIntervalDly = s_pktHalPwmdrvCommonConf->usFullFingerPWMIntervalDly << 1;
		}

		PWMDRV_PRE(PWM_Full_PRD_KHz(ulNormalFreq),
				PWM_Half_PRD_KHz(ulNormalFreq),
				s_pktHalPwmdrvCommonConf->ucPwmPreNum,
				s_pktHalPwmdrvCommonConf->tPWMDRV_PRE_1.tBit.PRE_DLY,
				s_pktHalPwmdrvCommonConf->tPWMDRV_PRE_2.tBit.DSSS_DLY);

		PWMDRV_FG_F_F0_ACT(PWM_Full_PRD_KHz(ulNormalFreq),
				PWM_Half_PRD_KHz(ulNormalFreq),
				(s_pktHalPwmdrvCommonConf->ucPwmSetNum + ucActNum),
				ulPWMIntervalDly,
				s_pktHalPwmdrvCommonConf->ucPwmFinger1LHBMuxNum);
	}
	else
	{
		PWMDRV_PRE(97, 48, s_pktHalPwmdrvCommonConf->ucPwmPreNum, s_pktHalPwmdrvCommonConf->tPWMDRV_PRE_1.tBit.PRE_DLY, s_pktHalPwmdrvCommonConf->tPWMDRV_PRE_2.tBit.DSSS_DLY);

		PWMDRV_FG_F_F0_ACT(97, 48, (s_pktHalPwmdrvCommonConf->ucPwmSetNum + s_pktHalPwmdrvCommonConf->ucPwmNiActNum), s_pktHalPwmdrvCommonConf->usFullFingerPWMIntervalDly, s_pktHalPwmdrvCommonConf
									->ucPwmNi1LHBMuxNum);
	}
}

void PWMDRV_Set_Mode(eSENSING_MODE_t mode)
{
	if(IS_FINGER_PEN_MODE(mode))
	{
		Fncp_PWMDRV_IRQHandler = &PWMDRV_InterruptHandler_PartialScan;
		PWMDRV->FW_CTRL_b.PEN_MODE = 1;
		PWMDRV->DSSS_CFG_b.beacon_en = 1;
#if USED_WACOM_PEN
		PWMDRV->DSSS_CFG_b.ping_en = 1;
#else
		PWMDRV->DSSS_CFG_b.ping_en = 0;
#endif
	}
	else
	{
		Fncp_PWMDRV_IRQHandler = &PWMDRV_InterruptHandler_FullScan;
		PWMDRV->FW_CTRL_b.PEN_MODE = 0;
		if(IS_FINGER_PEN_SEARCH_MODE(mode))
		{
			PWMDRV->DSSS_CFG_b.beacon_en = 1;
		}
		else
		{
			PWMDRV->DSSS_CFG_b.beacon_en = 0;
		}
		PWMDRV->DSSS_CFG_b.ping_en = 0;
	}
}
