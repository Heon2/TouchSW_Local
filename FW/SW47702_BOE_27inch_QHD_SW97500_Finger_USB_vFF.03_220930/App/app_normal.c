/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_normal.c
 * created on : 14. 5. 2019
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

#include "core_def.h"
#include "param_def.h"
#include "hal_def.h"

#if USED_NOISE_HOPPING_FREQ
static const tAppCommonConf_t * thisCommonConf = NULL;
#endif

#if USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK
static tAlgorithmInfo_t * sptAlgorithmInfo = NULL;
#endif /* USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK */

static tAlgorithmInfo_t * thisInfo = NULL;
extern eActivePenType_t gAlgoRawDataType;

#if USE_FREQ_HOPPIG_DEBUG
bool_t bHoppingFreq;
#endif

#if USED_S3_WAKEUP_DEBUGING
uint32_t ulTestS3RawDataRead = YES;
#endif

#if USED_PEN_MODE_OPERATION
static const tAlgorithmModeConf_t * thisModeConf = NULL;
void app_normal_Init_param(void)
{
	thisModeConf = algorithm_GetModeConfig();
}
#endif

void app_normal_Init(void)
{
#if USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK
	sptAlgorithmInfo = algorithm_GetInfo();
#endif /* USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK */

#if USED_NOISE_HOPPING_FREQ
	thisCommonConf   = app_GetCommonConfig();
#endif
	thisInfo         = algorithm_GetInfo();
#if USED_PEN_MODE_OPERATION
	app_normal_Init_param();
#endif
}

extern uint16_t currentRowStart;
extern __IO uint16_t sensingRowStart;
uint16_t currentColStart = 0;
extern uint16_t p_currentRowStart;
uint8_t diff_rs_cnt = 0;
extern __IO uint16_t sensingRowStart_Tilt;
int TEST_LOCAL_STATE = 0;
eSENSING_FREQ_t CurrFreq;

//extern __IO uint8_t custom_tool;

eTouchOperMainState_t app_normal_oper_handler(void)
{
	eTouchOperMainState_t main_state;
	eNormalOperSubState_t sub_state;
	bool_t bLoop = YES;
	eProtocolMode_t currMode, prevMode = M_TOUCH_NORMAL;
	app_normal_Init();
#if USED_PEN_MODE_OPERATION
	Interrupt_Init();
#endif /* USED_PEN_MODE_OPERATION */

	main_state = TOUCH_MAIN_OPERATION_NORMAL;
	sub_state = TOUCH_NORMAL_OPER_ENTER;
	thisInfo->bDiagMode = NO;

    while(bLoop)
    {
    	switch(sub_state)
    	{
			case TOUCH_NORMAL_OPER_ENTER:
			{
				TEST_LOCAL_STATE = 0;
#if USED_S3_MODE_FUNCTION
				/*
				 * Enter S3 Mode, If LCD On Signal is low for a set period of time.
				 */
				if(module_Init_Signal() == NO)
				{
					protocol_swip_SetMode(M_TOUCH_LPWG);
					break;
				}
				module_start_delay();
#else /* USED_S3_MODE_FUNCTION */

	#if USED_SMT_OP_MODE
				if(module_Check_SMT_Mode())
				{
					module_Enter_SMT_Mode();
					sub_state = TOUCH_NORMAL_SMT_MODE;
					break;
				}
	#endif /* USED_SMT_OP_MODE */
				GPIO_Initialize();

	#if USED_MNT_S3_MODE_FUNCTION
				if(module_Init_Signal())
				{
					HAL_SetSensingMode(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
				}
				else
				{
					HAL_SetSensingMode(SM_S3_ACTIVE_MODE);
					sub_state = TOUCH_NORMAL_OPER_RESET_SYSTEM;
					break;
				}

				currMode = protocol_swip_GetMode();
				if(currMode == M_TOUCH_DFUP)
				{
					break;
				}

				module_start_delay();
	#else
				module_Init_Signal();
				currMode = protocol_swip_GetMode();
				if(currMode == M_TOUCH_DFUP || currMode == M_WATCH_DOG_RESET)
				{
					break;
				}
				module_start_delay();
	#endif
#endif /* USED_S3_MODE_FUNCTION */
			}
			/* no break */
			case TOUCH_NORMAL_OPER_RESET_SYSTEM:
			{
				if(PARAM_GetMode() != PARAM_MODE_NORMAL)
				{
					PARAM_SetMode(PARAM_MODE_NORMAL);
					PARAM_InitConfig();
					algorithm_init();
#if (USED_PEN_MODE_OPERATION)
					algorithm_local_init(); //code
					algorithm_init_local(); //DSP
	#if (USED_DSPA_FUNC_FOR_PEN_SEARCH || USED_DSPA_FUNC_FOR_PEN_LOCAL || USED_DSPA_FUNC_FOR_FINGER)
					algorithm_init_dspA();
	#endif
#else
	#if (USED_DSPA_FUNC_FOR_FINGER)
					algorithm_init_dspA();
	#endif					
#endif /* (USED_PEN_MODE_OPERATION) */
				}
				SensingBufferInit();
			}
			/* no break */
			case TOUCH_NORMAL_OPER_RESET_HAL:
			{
#ifdef MODE_WDT
				module_Watch_Enable();
#endif /* MODE_WDT */
#if USED_MNT_S3_MODE_FUNCTION
				if(IS_S3_MODE(HAL_GetSensingMode()))
				{
					HAL_ConfigInit(YES);
				}
				else
#endif /* USED_MNT_S3_MODE_FUNCTION */
				{
					HAL_ConfigInit(NO);
				}
				MODULE_Initialize();
			}
			/* no break */
			case TOUCH_NORMAL_OPER_RESET_MODULE:
			{
#if DISABLE_TOUCH_INITIALIZATION
				GPIO_Set_Mode(_GPIO_TSYNC_IN, GPIO_MODE_FUNC_0);
				GPIO_Set_Mode(_GPIO_TSYNC_OUT, GPIO_MODE_FUNC_0);
				GPIO_Set_DS(_GPIO_TSYNC_OUT, GPIO_DRIVE_STR_20mA);

				while(1)
				{
#ifdef MODE_WDT
				KICK_DOG();
#endif /* MODE_WDT */
				medium_delay(3000);

					if (protocol_swip_GetMode() == M_TOUCH_DFUP)
					{
						break;
					}
				}
#else
				if(!module_Start())
				{
					sub_state = TOUCH_NORMAL_OPER_ENTER;
					break;
				}

#if USED_RAWDATA_TUNE_CALIBRATION
				sub_state = TOUCH_NORMAL_OPER_NORMAL_RAWDATA_CALIBRATION;
#else /* USED_RAWDATA_TUNE_CALIBRATION */
#if USED_MNT_S3_MODE_FUNCTION
				if(IS_S3_MODE(HAL_GetSensingMode()))
				{
					sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE_S3;
				}
				else
#endif /* USED_MNT_S3_MODE_FUNCTION */
				{
#if USED_PEN_MODE_OPERATION
					sub_state = TOUCH_NORMAL_OPER_READY_REFERENCE_PEN;
#else /* USED_PEN_MODE_OPERATION */
					sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE;
#endif /* USED_PEN_MODE_OPERATION */

#if USED_RUNTIME_LOCAL_TUNE_RAWDATA
					SRIC_RawDataLocalRuntimeCalibration();
#endif /* USED_RUNTIME_LOCAL_TUNE_RAWDATA */
				}
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#endif /* DISABLE_TOUCH_INITIALIZATION */
				break;
			}

#if USED_SMT_OP_MODE
			case TOUCH_NORMAL_SMT_MODE:
			{
				if(module_Check_SMT_Mode() == NO)
				{
					module_Exit_SMT_Mode();
					sub_state = TOUCH_NORMAL_OPER_ENTER;
					break;
				}
				module_SignalOut_SMT_Mode();
				break;
			}
#endif /* USED_SMT_OP_MODE */

			case TOUCH_NORMAL_OPER_RESET_REFERENCE:
			{
#if USED_NOISE_HOPPING_FREQ
				if (thisCommonConf->bUseFreqHopp)
				{
					module_Switch_Freq(thisCommonConf->HoppFreq1);
					algorithm_baseline_tracking_initial();

					module_Switch_Freq(thisCommonConf->MainFreq);
				}
				algorithm_baseline_tracking_initial();
#else
//				if(module_Switch_Freq(thisCommonConf->MainFreq))
				{
					algorithm_baseline_tracking_initial();
				}
#endif
				thisInfo->bLineFilterRepeatCheck = 0;

#if USED_PEN_MODE_OPERATION
				sub_state = TOUCH_NORMAL_OPER_READY_REFERENCE_PEN;
#else /* USED_PEN_MODE_OPERATION */
				sub_state = TOUCH_NORMAL_OPER_NORMAL_READY;
#endif /* USED_PEN_MODE_OPERATION */
				break;
			}

#if USED_IDLE_MODE_CONTROL
			case TOUCH_NORMAL_OPER_RESET_REFERENCE_IDLE:
			{
				algorithm_baseline_tracking_initial_idle(NO);
				sub_state = TOUCH_NORMAL_OPER_IDLE;
				break;
			}
#endif /* USED_IDLE_MODE_CONTROL */

#if USED_MNT_S3_MODE_FUNCTION
			case TOUCH_NORMAL_OPER_RESET_REFERENCE_S3:
			{
				algorithm_baseline_tracking_initial_S3(NO);
				sub_state = TOUCH_NORMAL_OPER_S3_READY;
				break;
			}
#endif /* USED_MNT_S3_MODE_FUNCTION */

#if (USED_PEN_MODE_OPERATION)
			case TOUCH_NORMAL_OPER_READY_REFERENCE_PEN:
			{
				if(tHalIntrHandle.ulTSyncInRisingCnt == (LHB_NUM-1))
				{
					sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE_PEN;
				}
				break;
			}
			
			case TOUCH_NORMAL_OPER_RESET_REFERENCE_PEN:
			{
#ifdef MODE_WDT				
				KICK_DOG();
#endif /* MODE_WDT */
				thisInfo->bLineFilterRepeatCheck = 0;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
				hal_Info_SetPenTypeSwapCheckEnable(NO);

				algorithm_local_baseline_init();
				if(algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_MS) == NO)
				{
					sub_state = TOUCH_NORMAL_OPER_LOCAL_READY;
				}

				HAL_SetActivePenChagneType(ACTIVEPEN_CHANGE_LOCAL_WGP);

				if(algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WGP) == NO)
				{
					sub_state = TOUCH_NORMAL_OPER_LOCAL_READY;
				}
//
				HAL_SetActivePenChagneType(ACTIVEPEN_CHANGE_LOCAL_MS);

				{
					uint16_t ulSkipCnt = 0;
				    while(ulSkipCnt < 2)
				    {
				    	ePartialSensing_t lDataIndex = module_wait_local_sample_done();

				    	if(lDataIndex == PARTIAL_MAX)
				    	{
				    		break;
				    	}

						if(lDataIndex == LOCAL_OP_LAST_LHB)
						{
							ulSkipCnt++;
						}
					}
				}
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
				hal_Info_SetPenTypeSwapCheckEnable(NO);
				algorithm_local_baseline_init();
				if(algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_MS) == NO)
				{
					sub_state = TOUCH_NORMAL_OPER_LOCAL_READY;
				}
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
				hal_Info_SetPenTypeSwapCheckEnable(NO);
				algorithm_local_baseline_init();
	#if USED_NOISE_HOPPING_FREQ
				if(thisCommonConf->bUseFreqHopp)
				{
					module_Switch_Freq(thisCommonConf->HoppFreq1);
					if(algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WGP) == NO)
					{
						module_Switch_Freq(thisCommonConf->MainFreq);
						if(algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WGP) == NO)
						{
							sub_state = TOUCH_NORMAL_OPER_LOCAL_READY;
						}
					}
				}
				else
				{
					if(algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WGP) == NO)
					{
						sub_state = TOUCH_NORMAL_OPER_LOCAL_READY;
					}
				}
	#else /* USED_NOISE_HOPPING_FREQ */
				if(algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WGP) == NO)
				{
					sub_state = TOUCH_NORMAL_OPER_LOCAL_READY;
				}
	#endif /* USED_NOISE_HOPPING_FREQ */
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
				hal_Info_SetPenTypeSwapCheckEnable(NO);
				algorithm_local_baseline_init();
				if(algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WGP) == NO)
				{
					sub_state = TOUCH_NORMAL_OPER_LOCAL_READY;
				}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) */
				break;
			}

#if USED_LOCAL_IDLE_MODE_CONTROL
			case TOUCH_NORMAL_OPER_READY_REFERENCE_PEN_IDLE:
			{
				sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE_PEN_IDLE;
				break;
			}
			case TOUCH_NORMAL_OPER_RESET_REFERENCE_PEN_IDLE:
			{
				algorithm_baseline_tracking_initial_local_idle(NO);
				sub_state = TOUCH_NORMAL_OPER_LOCAL_IDLE;
				break;
			}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */

#endif /* (USED_PEN_MODE_OPERATION) */
			case TOUCH_NORMAL_OPER_NORMAL_READY:
			{
#if USED_IDLE_MODE_CONTROL
	#if USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE
				tAppInfo_t * ptAppInfo = app_GetInfo();
				if(ptAppInfo->bIsNormalReadyIdleCheckCountMaintain)
				{
					ptAppInfo->bIsNormalReadyIdleCheckCountMaintain = NO;
		#if (!USED_ENTER_IDLE_REAL_TIME_CHECK)
					thisInfo->ulIdleModeEnterCheckCount += DEF_FREQ_HOPPING_BASELINE_UPDATE_CONTI_CNT_THD;
		#endif /* (!USED_ENTER_IDLE_REAL_TIME_CHECK) */
				}
				else
				{
					thisInfo->ulIdleModeEnterCheckCount = 0;
				}
	#else /* USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE */
				thisInfo->ulIdleModeEnterCheckCount = 0;
	#endif /* USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE */
#endif /* USED_IDLE_MODE_CONTROL */
				sub_state = TOUCH_NORMAL_OPER_NORMAL;
#if USED_ECLK_ON_OFF_CONTROL
				HAL_SetECLKOnOffControl(YES);
#endif /* USED_ECLK_ON_OFF_CONTROL */
#if (!USED_PEN_MODE_OPERATION)
	#if USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE
				HAL_SetHoppBaselineContinueEnControl(YES);
	#endif /* USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE */
#endif /* (!USED_PEN_MODE_OPERATION) */
				break;
			}
			case TOUCH_NORMAL_OPER_NORMAL:
			{
#ifdef MODE_WDT
				KICK_DOG();
#endif /* MODE_WDT */
				if(!module_wait_full_sample_done())
				{
					module_Stop(YES);
					sub_state = TOUCH_NORMAL_OPER_ENTER;
					break;
				}

				if(algorithm_process(FULL_MODE) == NO)
				{
#if USED_PEN_MODE_OPERATION
					/*
					 * Change the Pen Mode!!
					 */
					sub_state = TOUCH_NORMAL_OPER_READY_REFERENCE_PEN;

					sensingRowStart = 0;
					HAL_SetSensingChangeMode(SM_CHAGNE_Full_To_Local_MODE);
#else /* USED_PEN_MODE_OPERATION */
					sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE;
#endif /* USED_PEN_MODE_OPERATION */
					TEST_LOCAL_STATE = 0;
					break;
				}

#if (USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK || USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml)
	#if USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK && USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml
				if(sptAlgorithmInfo->bIsESDRecovery || tHalIntrHandle.bIsROICReg_ESDRecovery)
	#elif USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK
				if(sptAlgorithmInfo->bIsESDRecovery)
	#elif USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml
				if(tHalIntrHandle.bIsROICReg_ESDRecovery)
	#endif
				{
					// Must Wadtch Dog Reset Enable
					while(1);
				}
#endif /* (USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK || USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml) */

//				if(abnormal_rawdata_temp(NO))
//				{
//					SensingBufferInit();
//					sub_state = TOUCH_NORMAL_OPER_ENTER;
//					TEST_LOCAL_STATE = 0;
//					break;
//				}

//				algorithm_noise_param_apply();

#if USED_NOISE_HOPPING_FREQ
#if USE_FREQ_HOPPIG_DEBUG
				if (bHoppingFreq)
				{
					bHoppingFreq = NO;
					algorithm_Set_FreqHopp(NOISE_FREQ_HOPPING);
				}
#endif
				if (algorithm_Check_FreqHopping())
				{
					sub_state = TOUCH_NORMAL_OPER_SWITCH_FREQ;
					break;
				}
#endif

#if USED_IDLE_MODE_CONTROL
				if(algorithm_CheckFingerIdleModeControl())
				{
					sub_state = TOUCH_NORMAL_OPER_IDLE_READY;
					break;
				}
#endif /* USED_IDLE_MODE_CONTROL */

#if USED_PEN_MODE_OPERATION
				if(algorithm_CheckFingerPenModeControl())
				{
					sub_state = TOUCH_NORMAL_OPER_LOCAL_READY;
					break;
				}
#endif /* USED_PEN_MODE_OPERATION */

				break;
			}
#if USED_IDLE_MODE_CONTROL
			case TOUCH_NORMAL_OPER_IDLE_READY:
			{
				thisInfo->ulIdleModeEnterCheckCount = 0;
//				tHalIntrHandle.ulInitFirstFrame = 0;
#if USED_ECLK_ON_OFF_CONTROL
				HAL_SetECLKOnOffControl(YES);
#endif /* USED_ECLK_ON_OFF_CONTROL */
#if USED_REFERENCE_INIT_IDLE_MODE_ENTER
				sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE_IDLE;
#else /* USED_REFERENCE_INIT_IDLE_MODE_ENTER */
				sub_state = TOUCH_NORMAL_OPER_IDLE;
#endif /* USED_REFERENCE_INIT_IDLE_MODE_ENTER */
				break;
			}
			case TOUCH_NORMAL_OPER_IDLE:
			{
#ifdef MODE_WDT
				KICK_DOG();
#endif /* MODE_WDT */

				if(!module_wait_NI_sample_done())
				{
					module_Stop(YES);
					sub_state = TOUCH_NORMAL_OPER_ENTER;
					break;
				}

				if(algorithm_process_Idle() == NO)
				{
					SensingBufferInit();
					sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE_IDLE;
					break;
				}

				if(algorithm_CheckFingerIdleModeControl())
				{
					sub_state = TOUCH_NORMAL_OPER_NORMAL_READY;
					break;
				}
				break;
			}
#endif /* USED_IDLE_MODE_CONTROL */

#if USED_MNT_S3_MODE_FUNCTION
			case TOUCH_NORMAL_OPER_S3_READY:
			{
#if USED_ECLK_ON_OFF_CONTROL
				HAL_SetECLKOnOffControl(YES);
#endif /* USED_ECLK_ON_OFF_CONTROL */
				sub_state = TOUCH_NORMAL_OPER_S3;
				break;
			}
			case TOUCH_NORMAL_OPER_S3:
			{
#ifdef MODE_WDT
				KICK_DOG();
#endif /* MODE_WDT */
				if(!module_wait_S3_sample_done())
				{
#if USED_S3_PGAMMA_SW_I2C_CTRL
//					_gT(_GPIO_TP_INTR);
					module_S3_PGAMMA_I2C_SW_Enable();
//					_gT(_GPIO_TP_INTR);
#endif /* USED_S3_PGAMMA_SW_I2C_CTRL */
					HAL_Set_S3_VDD_OddEven_Ctrl(NO);

#if USED_ECLK_ON_OFF_CONTROL
					HAL_SetECLKOnOffControl(NO);
#endif /* USED_ECLK_ON_OFF_CONTROL */
#if USED_TPIC_MUXEN_ON_OFF_CONTROL
					HAL_SetTPICMuxEnControl(NO, NO);
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
#if USED_TOUCH_REPORT_ON_OFF_CONTROL
					HAL_SetTouchReportEnControl(NO);
#endif /* USED_TOUCH_REPORT_ON_OFF_CONTROL */
					GPIO_Init(_GPIO_TSYNC_OUT, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);

					tPWM_INTR_CFG_t tPWM_INTR_CFG[4] =
					{
						{VSYNC_IN_IRQn, VSYNC_IN_IRQn_Priority, DISABLE},
						{TSYNC_IN_IRQn, TSYNC_IN_IRQn_Priority, DISABLE},
						{TSYNC_OUT_IRQn, TSYNC_OUT_IRQn_Priority, DISABLE},
						{PWMDRV_IRQn, PWMDRV_IRQn_Priority, DISABLE}
					};
					PWMDRV_ITConfig((tPWM_INTR_CFG_t *)&tPWM_INTR_CFG[0], 4);

					NVIC_DisableIRQ(GPIOA_IRQn);
					NVIC_DisableIRQ(GPIOM_IRQn);
					MSPI_ITConfig(DISABLE);
					MSPI_Cmd(DISABLE);
//					PWMDRV->PWMGEN_CR0.tBit.pwm_gen_enable = DISABLE;
					PWMDRV_Cmd(DISABLE);

					PARAM_SetMode(PARAM_MODE_NONE);

					sub_state = TOUCH_NORMAL_OPER_ENTER;
					thisInfo->tS3DeltaInfo.bIsSendResumeSignal = NO;
#if USED_S3_WAKEUP_DEBUGING
					ulTestS3RawDataRead = YES;
#endif
//					_gT(_GPIO_TP_INTR);
					break;
				}

				if(algorithm_process_S3() == NO)	//
				{
					SensingBufferInit();
					sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE_S3;
					break;
				}
				break;
			}
#endif /* USED_MNT_S3_MODE_FUNCTION */

#if USED_NOISE_HOPPING_FREQ
			case TOUCH_NORMAL_OPER_SWITCH_FREQ:
	#if (USED_PEN_MODE_OPERATION)
			case TOUCH_NORMAL_OPER_LOCAL_SWITCH_FREQ:
	#endif /* USED_PEN_MODE_OPERATION */
			{
				tAppInfo_t * ptAppInfo = app_GetInfo();
				
	#if USED_ECLK_ON_OFF_CONTROL
				HAL_SetECLKOnOffControl(NO);
	#endif /* USED_ECLK_ON_OFF_CONTROL */

				if (ptAppInfo->eSelectFreq == FREQ_MAIN)
				{
					module_Switch_Freq(thisCommonConf->HoppFreq1);

	#if USED_PEN_MODE_OPERATION
					if(sub_state == TOUCH_NORMAL_OPER_LOCAL_SWITCH_FREQ)
					{
						sub_state = TOUCH_NORMAL_OPER_LOCAL;
					}
					else
	#endif /* USED_PEN_MODE_OPERATION */
					{
						sub_state = TOUCH_NORMAL_OPER_NORMAL_READY;
					}
				}
				else if (ptAppInfo->eSelectFreq == FREQ_HOPP1)
				{
					module_Switch_Freq(thisCommonConf->MainFreq);

	#if USED_PEN_MODE_OPERATION
					if(sub_state == TOUCH_NORMAL_OPER_LOCAL_SWITCH_FREQ)
					{
						sub_state = TOUCH_NORMAL_OPER_LOCAL;
					}
					else
	#endif /* USED_PEN_MODE_OPERATION */
					{
						sub_state = TOUCH_NORMAL_OPER_NORMAL_READY;
					}
				}
				else
				{
					sub_state = TOUCH_NORMAL_OPER_RESET_MODULE;
				}
				break;
			}
#endif /* USED_NOISE_HOPPING_FREQ */

#if (USED_PEN_MODE_OPERATION)
			case TOUCH_NORMAL_OPER_LOCAL_READY:
			{
				sensingRowStart_Tilt = sensingRowStart;
				currentRowStart = sensingRowStart;
				p_currentRowStart = currentRowStart;
				currentColStart = thisInfo->tPenInfo.ucCurrentColumnStart;

				thisInfo->tPenInfo.us_pendata_pressure = 1;
				thisInfo->tPenInfo.ucSensing_cont_cnt = 0;
				
				thisInfo->tPenInfo.ucSearch_check_cnt = thisInfo->tPenInfo.ucSearch_check_cnt_2 = 0;

				if(tHalIntrHandle.ulTSyncInRisingCnt == (LHB_NUM-1)
#if USED_TP_RST_OPERATION
					|| (IS_GPIO_PIN(_GPIO_TP_RST) == 0x0)
#endif /* #if USED_TP_RST_OPERATION */
					)
				{
					TEST_LOCAL_STATE = 1;

					sub_state = TOUCH_NORMAL_OPER_LOCAL;
					thisInfo->tPenInfo.ucSensing_cont_cnt1 = 0;
#if USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE
					HAL_SetHoppBaselineContinueEnControl(YES);
#endif /* USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE */
				}
				break;
			}

			case TOUCH_NORMAL_OPER_LOCAL:
			{
#ifdef MODE_WDT
				KICK_DOG();
#endif /* MODE_WDT */
#if ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN))
				hal_Info_SetPenTypeSwapCheckEnable(YES);
#endif /* ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)) */
				ePartialSensing_t RetVal = module_wait_local_sample_done();
				bool_t dsp_a_finger_op_change = 0;
				switch(RetVal)
				{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
					case PARTIAL_PEN_COORD_DATA1:		// 1st Pen RAWDATA Check
					case PARTIAL_PEN_COORD_DATA2:		// 2nd Pen RAWDATA Check
					case PARTIAL_PEN_COORD_DATA3:		// 3rd Pen RAWDATA Check
					case PARTIAL_PEN_COORD_DATA4:		// 4th Pen RAWDATA Check
	#if USED_WGP_PEN_UHD_16LHB_OPERATION
					case PARTIAL_PEN_COORD_DATA5:		// 5th Pen RAWDATA Check
					case PARTIAL_PEN_COORD_DATA6:		// 6th Pen RAWDATA Check
					case PARTIAL_PEN_COORD_DATA7:		// 7th Pen RAWDATA Check
					case PARTIAL_PEN_COORD_DATA8:		// 8th Pen RAWDATA Check
	#endif /* USED_WGP_PEN_UHD_16LHB_OPERATION */
					{
#if LOCAL_REBASE_ALGO_EN
						algorithm_check_recal_pen();
#endif
						
#if ((USED_DSPA_FUNC_FOR_PEN_SEARCH || USED_DSPA_FUNC_FOR_PEN_LOCAL) && USED_DSPA_FUNC_FOR_FINGER)
						if( (thisModeConf->BaseLine.bDspA_LocalMode_PenPhase || thisModeConf->BaseLine.bDspA_LocalMode_CalculateDelta || thisModeConf->SensingFilter.cLineFilter_Pen == 2 ||
							 thisModeConf->BaseLine.bDspA_SearchMode_PenPhase || thisModeConf->BaseLine.bDspA_SearchMode_CalculateDelta || thisModeConf->SensingFilter.ucLocalSearchModeLineFilter == 2)
						 && (thisModeConf->BaseLine.bDspA_Finger_CalculateDelta || thisModeConf->SensingFilter.cLineFilter > 2) )
						{
							dsp_a_finger_op_change = 1;
	#if USED_WGP_PEN_UHD_16LHB_OPERATION
							if( PARTIAL_PEN_COORD_DATA7 == RetVal )
	#else /* USED_WGP_PEN_UHD_16LHB_OPERATION */
							if( PARTIAL_PEN_COORD_DATA4 == RetVal )
	#endif /* USED_WGP_PEN_UHD_16LHB_OPERATION */
							{
								if(algorithm_process(LOCAL_FINGER_MODE) == NO)
								{
									thisInfo->bIsRecalCondLocal = YES;
								}
							}
						}
#endif
						protocol_LogMatrix(LT_PENPOS_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_3_PTR(), COL_MAX, PEN_DATA_ROW_MAX_3, 84 /*MAX Intensity*/);
						if(thisInfo->tPenInfo.bSearch_Mode_Flag == 0)
						{
							protocol_LogPaddedMatrix(LT_PENPOS_INTENSITY, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DELTA_IMAGE_PTR(), COL_MAX, PEN_COORD_ROW_MAX, 84/*MAX Intensity*/);
						}
						else
						{
							protocol_LogMatrix(LT_PENPOS_INTENSITY, COL_MAX, HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
						}
#if defined(TILT_ON)
						protocol_LogMatrix(LT_NI_RAW, PEN_COORD_COL_MAX, HAL_GET_LOCAL_RING_RAW_IMAGE_PTR(), COL_MAX, PEN_COORD_ROW_MAX+PEN_COORD_ROW_MAX, 84/*MAX Intensity*/);
						protocol_LogPaddedMatrix(LT_NI_INT, PEN_COORD_COL_MAX, HAL_GET_RING_DELTA_IMAGE_PTR(), COL_MAX, PEN_COORD_ROW_MAX, 84/*MAX Intensity*/);
#endif
						break;
					}
#else /* USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN */
					case PARTIAL_PEN_COORD1:
					case PARTIAL_PEN_COORD2:
					case PARTIAL_PEN_COORD3:
					case PARTIAL_PEN_COORD4:
					{
#if LOCAL_REBASE_ALGO_EN
						algorithm_check_recal_pen();
#endif
						
#if ((USED_DSPA_FUNC_FOR_PEN_SEARCH || USED_DSPA_FUNC_FOR_PEN_LOCAL) && USED_DSPA_FUNC_FOR_FINGER)
						if( (thisModeConf->BaseLine.bDspA_LocalMode_PenPhase || thisModeConf->BaseLine.bDspA_LocalMode_CalculateDelta || thisModeConf->SensingFilter.cLineFilter_Pen == 2 ||
							 thisModeConf->BaseLine.bDspA_SearchMode_PenPhase || thisModeConf->BaseLine.bDspA_SearchMode_CalculateDelta || thisModeConf->SensingFilter.ucLocalSearchModeLineFilter == 2) 
						 && (thisModeConf->BaseLine.bDspA_Finger_CalculateDelta || thisModeConf->SensingFilter.cLineFilter > 2) )
						{
							dsp_a_finger_op_change = 1;
							if( (PARTIAL_PEN_COORD4 == RetVal && gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP) || 
								(PARTIAL_PEN_COORD1 == RetVal && gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)  ||
								(PARTIAL_PEN_COORD2 == RetVal && gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM) ) 
							{
								if(algorithm_process(LOCAL_FINGER_MODE) == NO)
								{
									thisInfo->bIsRecalCondLocal = YES;
								}
							}
						}
#endif						
						protocol_LogMatrix(LT_PENPOS_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_RAW_IMAGE_PTR(), COL_MAX, (PEN_COORD_ROW_MAX*2), 84/*MAX Intensity*/);

						if (thisInfo->tPenInfo.bSearch_Mode_Flag == 0)
						{
//							protocol_LogPaddedMatrix(LT_PENPOS_INTENSITY, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DELTA_IMAGE_PTR(), COL_MAX, PEN_COORD_ROW_MAX, 84/*MAX Intensity*/);
							protocol_LogLocalPaddedMatrix(LT_PENPOS_INTENSITY, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DELTA_IMAGE_PTR(), COL_MAX, PEN_COORD_ROW_MAX, 84/*MAX Intensity*/, currentRowStart);
						}
						else
						{
	#if IS_MULTI_PROTOCOL_OPERATION
							if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
								protocol_LogMatrix(LT_PENPOS_INTENSITY, COL_MAX, HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
							else
								protocol_LogMatrix(LT_PENPOS_INTENSITY, COL_MAX, HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
	#else
							#if IS_MSPEN_PROTOCOL_OPERATION
								protocol_LogMatrix(LT_PENPOS_INTENSITY, COL_MAX, HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
							#else
								protocol_LogMatrix(LT_PENPOS_INTENSITY, COL_MAX, HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
							#endif
	#endif
						}

#if defined(TILT_ON)
						protocol_LogMatrix(LT_NI_RAW, PEN_COORD_COL_MAX, HAL_GET_LOCAL_RING_RAW_IMAGE_PTR(), COL_MAX, (PEN_COORD_ROW_MAX+PEN_COORD_ROW_MAX), 84/*MAX Intensity*/);
						protocol_LogPaddedMatrix(LT_NI_INT, PEN_COORD_COL_MAX, HAL_GET_RING_DELTA_IMAGE_PTR(), COL_MAX, PEN_COORD_ROW_MAX, 84/*MAX Intensity*/);
#endif
						break;
					}
					case PARTIAL_PEN_DATA1:
					case PARTIAL_PEN_DATA2:
					case PARTIAL_PEN_DATA3:
					case PARTIAL_PEN_DATA4:
					case PARTIAL_PEN_DATA5:
					{
						// _gT(_GPIO_TP_INTR);	//use only test
	#if IS_MULTI_PROTOCOL_OPERATION
						if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
							protocol_LogMatrix(LT_PENDATA_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_PTR(), COL_MAX, PEN_DATA_ROW_MAX, 84/*MAX Intensity*/);
						else if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM)
							protocol_LogMatrix_unsigned(LT_PENDATA_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_2_PTR(), COL_MAX, PEN_DATA_ROW_MAX_2, 84/*MAX Intensity*/);
						else
							protocol_LogMatrix(LT_PENDATA_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_3_PTR(), COL_MAX, PEN_DATA_ROW_MAX_3, 84/*MAX Intensity*/);
	#else
		#if IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION
						protocol_LogMatrix(LT_PENDATA_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_3_PTR(), COL_MAX, PEN_DATA_ROW_MAX_3, 84/*MAX Intensity*/);
		#elif IS_MSPEN_PROTOCOL_OPERATION
						protocol_LogMatrix(LT_PENDATA_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_PTR(), COL_MAX, PEN_DATA_ROW_MAX, 84/*MAX Intensity*/);
		#elif IS_WACOMPEN_PROTOCOL_OPERATION
						protocol_LogMatrix_unsigned(LT_PENDATA_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_2_PTR(), COL_MAX, PEN_DATA_ROW_MAX_2, 84/*MAX Intensity*/);
		#endif
	#endif
						break;
					}
#endif /* USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN */
					case LOCAL_FINGER_LAST_LHB:
					{
						if(dsp_a_finger_op_change == 0)
						{
							if(algorithm_process(LOCAL_FINGER_MODE) == NO)
							{
								thisInfo->bIsRecalCondLocal = YES;
							}
						}

						if(thisInfo->bIsRecalCondLocal && !thisModeConf->BaseLine.bLocalModeReBaseCheckOff)
						{
							thisInfo->bIsRecalCondLocal = NO;
							sub_state = TOUCH_NORMAL_OPER_READY_REFERENCE_PEN;
							TEST_LOCAL_STATE = 0;
							break;
						}

#if USED_NOISE_HOPPING_FREQ
	#if USE_FREQ_HOPPIG_DEBUG
						if (bHoppingFreq)
						{
							bHoppingFreq = NO;
							algorithm_Set_FreqHopp(NOISE_FREQ_HOPPING);
						}
	#endif
						if (algorithm_Check_FreqHopping())
						{
							sub_state = TOUCH_NORMAL_OPER_LOCAL_SWITCH_FREQ;
							break;
						}
#endif
						if(algorithm_CheckFingerPenModeControl())
						{
							sub_state = TOUCH_NORMAL_OPER_NORMAL_READY;
							break;
						}
#if  USED_LOCAL_IDLE_MODE_CONTROL
						else if(algorithm_CheckLocalPenIdleModeControl())
						{
							sub_state = TOUCH_NORMAL_OPER_LOCAL_IDLE_READY;
							break;
						}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */

						break;
					}
					case PARTIAL_MAX:
					{
						module_Stop(YES);
						sub_state = TOUCH_NORMAL_OPER_ENTER;
						break;
					}
					default:
						break;
				}
				break;
			}

#if USED_LOCAL_IDLE_MODE_CONTROL
			case TOUCH_NORMAL_OPER_LOCAL_IDLE_READY:
			{
#if USED_ECLK_ON_OFF_CONTROL
				HAL_SetECLKOnOffControl(YES);
#endif /* USED_ECLK_ON_OFF_CONTROL */
//#if USED_TPIC_MUXEN_ON_OFF_CONTROL
//				HAL_SetTPICMuxEnControl(NO, NO);
//#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
//#if USED_TOUCH_REPORT_ON_OFF_CONTROL
//				HAL_SetTouchReportEnControl(NO);
//#endif /* USED_TOUCH_REPORT_ON_OFF_CONTROL */
				sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE_PEN_IDLE;

				break;
			}

			case TOUCH_NORMAL_OPER_LOCAL_IDLE:
			{
#ifdef MODE_WDT
				KICK_DOG();
#endif /* MODE_WDT */
				if(!module_wait_NI_sample_done())
				{
					module_Stop(YES);
					sub_state = TOUCH_NORMAL_OPER_ENTER;
					break;
				}

				if(algorithm_process_LocalIdle() == NO)
				{
					sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE_PEN_IDLE;
					break;
				}

				if(algorithm_CheckLocalPenIdleModeControl())
				{
					sub_state = TOUCH_NORMAL_OPER_LOCAL_READY;
				}
				break;
			}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */

#endif /* (USED_PEN_MODE_OPERATION) */
#if USED_RAWDATA_TUNE_CALIBRATION
			case TOUCH_NORMAL_OPER_NORMAL_RAWDATA_CALIBRATION:
			{
	#if USED_RAWDATA_HOPP_FRQ_CALIBRATION
				module_Switch_Freq(thisCommonConf->HoppFreq1);
	#endif
				SRIC_RawDataCalibration();
#if USED_PEN_MODE_OPERATION
				sub_state = TOUCH_NORMAL_OPER_READY_REFERENCE_PEN;
#else /* USED_PEN_MODE_OPERATION */
				sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE;
#endif /* USED_PEN_MODE_OPERATION */
				break;
			}
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
			case TOUCH_NORMAL_OPER_EXIT:
			{
				bLoop = NO;
				continue;
				/* no break */
			}
    	}

		currMode = protocol_swip_GetMode();
		if(currMode != prevMode)
		{
			switch( currMode )
			{
				case M_TOUCH_NORMAL:
				{
					protocol_swip_PendReadyStatus();

					break;
				}
				case M_TOUCH_DIAG:
				{
					eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();
					sub_state = TOUCH_NORMAL_OPER_EXIT;
					main_state = TOUCH_MAIN_OPERATION_DIAG;
					
#if USED_ECLK_ON_OFF_CONTROL
					HAL_SetECLKOnOffControl(NO);
#endif /* USED_ECLK_ON_OFF_CONTROL */
#if USED_TPIC_MUXEN_ON_OFF_CONTROL
					HAL_SetTPICMuxEnControl(NO, NO);
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
#if USED_TPIC_PENEN_ON_OFF_CONTROL
					HAL_SetTPICPenEnControl(NO);
#endif /* USED_TPIC_PENEN_ON_OFF_CONTROL */
#if USED_TOUCH_REPORT_ON_OFF_CONTROL
					HAL_SetTouchReportEnControl(NO);
#endif /* USED_TOUCH_REPORT_ON_OFF_CONTROL */

#if USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE
					HAL_SetHoppBaselineContinueEnControl(NO);
#endif /* USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE */

					if(IS_IDLE_MODE(eSensingMode))
					{
#if USED_PEN_MODE_OPERATION
						HAL_SetSensingChangeMode(SM_CHANGE_LocalIdle_To_Full_MODE);
#else /* USED_PEN_MODE_OPERATION */
						HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_MODE);
#endif /* USED_PEN_MODE_OPERATION */
					}
					else
					{
#if USED_NOISE_HOPPING_FREQ
						if(IS_ACTIVE_MODE_FRQ_MAIN(eSensingMode) == NO)
						{
							module_Switch_Freq(thisCommonConf->MainFreq);
	#if USED_PEN_MODE_OPERATION
							if(IS_FINGER_PEN_MODE(eSensingMode))
							{
								while (YES)
								{
									if(module_wait_local_sample_done() == LOCAL_OP_LAST_LHB)
										break;
								}
//								module_wait_full_sample_done();
								HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);
							}
	#endif /* USED_PEN_MODE_OPERATION */
						}
						else
#endif /* USED_NOISE_HOPPING_FREQ */
						{
#if USED_PEN_MODE_OPERATION
							if(IS_FINGER_PEN_MODE(eSensingMode))
							{
								HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);
							}
#endif /* USED_PEN_MODE_OPERATION */
						}
					}

					/*
					 * Wait Mode Change!!
					 */
					module_wait_full_sample_done();
#ifdef MODE_WDT
					module_Watch_Disable();
#endif /* MODE_WDT */

					break;
				}
				case M_TOUCH_DFUP:
				case M_PARAMETER:
				{
#ifdef MODE_WDT
					LONG_KICK_DOG();
#endif /* MODE_WDT */

//					while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 0);
//					while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 1);
//					while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 0);
					module_Stop(NO);

					if(currMode == M_PARAMETER)
					{
						sub_state = TOUCH_NORMAL_OPER_RESET_SYSTEM;
					}
					else if(currMode == M_TOUCH_DFUP)
					{
						sub_state = TOUCH_NORMAL_OPER_EXIT;
						main_state = TOUCH_MAIN_OPERATION_DFUP;
					}
					break;
				}
				case M_WATCH_DOG_RESET:
				{
					module_Stop(NO);
					sub_state = TOUCH_NORMAL_OPER_EXIT;
					main_state = TOUCH_MAIN_OPERATION_RESET;
					break;
				}
			}
		}

		prevMode = currMode;
    }

    return main_state;
}

