/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_normal.c
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

#include "core_def.h"
#include "param_def.h"
#include "hal_def.h"

static tAlgorithmInfo_t * sptAlgorithmInfo = NULL;
#if USED_NOISE_HOPPING_FREQ
static const tAppCommonConf_t * thisCommonConf = NULL;
#endif /* USED_NOISE_HOPPING_FREQ */

extern uint8_t SRIC_reset_flag;
uint8_t GoToThisState = 0;

//volatile bool_t usbConnected = NO;

bool_t wakeupSignalEn = NO;
bool_t abnormalUSBOperating = NO;
int frameCntForUSBAbnormal = 0;

#if ABNORMAL_TSYNC_FALLING_TIME_CHECK
extern bool_t abnormalTsyncLowTime;

#endif

void app_normal_Init(void)
{
	sptAlgorithmInfo = algorithm_GetInfo();
#if USED_NOISE_HOPPING_FREQ
	thisCommonConf   = app_GetCommonConfig();
#endif /* USED_NOISE_HOPPING_FREQ */
}
extern uint16_t currentRowStart;
extern uint16_t sensingRowStart;
uint16_t currentColStart = 0;
extern uint16_t p_currentRowStart;
uint8_t diff_rs_cnt = 0;

extern uint8_t DoReportOrgPos;

int TEST_LOCAL_STATE = 0;

bool_t bChangeSampling = NO;

int check_frm = 8;
__IO int check_cnt = 8;

uint8_t sensing_cont_cnt = 1;

//extern 	ePartialSensing_t g_RetVal; // NOTE : not used
uint16_t g_pendata_pressure = 0;
//extern __IO int DSP_B_Index; // NOTE : not used

volatile int gDCFullMode = 1;

//extern int local_max_r; // NOTE : not used

extern __IO uint8_t custom_tool;
extern uint8_t RESET_FLAG;
extern volatile uint8_t IDLE_FLAG;
extern volatile uint8_t HOPP_FLAG;
extern volatile uint8_t FLAG_30Hz;
volatile uint8_t FLAG_mode=110;
//void initECLK(void);
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

	sub_state = TOUCH_NORMAL_OPER_ENTER;
	sptAlgorithmInfo->bDiagMode = NO;
	
#if USED_LPWG_MODE_CONTROL
	HAL_Initialize(NO);
	if(module_Check_LcdOn(NO) == NO)
	{
		HAL_SetSensingMode(SM_FINGER_ONLY_LPWG_MODE);
	}
#endif /* USED_LPWG_MODE_CONTROL */	

    while(bLoop)
    {
		custom_tool = 0;
		if(hal_get_SubState_flag() != TOUCH_NORMAL_OPER_NONCHANGE)
		{
			sub_state = hal_get_SubState_flag();
			hal_clear_SubState_flag();
			hal_clear_irq_flag(IRQ_ID_LOCAL_SAMPLE);
		}

    	switch(sub_state)
    	{
			case TOUCH_NORMAL_OPER_ENTER:
			{
#ifdef MODE_WDT				
				Hal_WDT_DeInit();
#endif /* MODE_WDT */
				
#if USED_RF_NOISE_RECOVERY_CODE
				sptAlgorithmInfo->usAbnormalDeltaFrameCnt2 = 0;
#endif /* USED_RF_NOISE_RECOVERY_CODE */
				
#if (USED_LPWG_MODE_CONTROL && CUSTOMER == MODEL_LGD_SW97400B)
				if(HAL_GetSensingChangeMode() == SM_CHANGE_LPWG_MODE)
				{
					HAL_SetSensingMode(SM_FINGER_ONLY_LPWG_MODE);
				}
				else if(HAL_GetSensingChangeMode() == SM_CHANGE_ACTIVE_FRQ_MAIN_MODE)
				{
					HAL_SetSensingMode(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
				}
				HAL_SetSensingChangeMode(SM_CHANGE_COMPLETE);
#endif /* (USED_LPWG_MODE_CONTROL && CUSTOMER == MODEL_LGD_SW97400B) */				
				TEST_LOCAL_STATE = 0;
				
#ifdef MODE_SMT
				if(module_Defense_Recovery())
				{
					module_Smt_Mode_Enter();
					sub_state = TOUCH_NORMAL_SMT_MODE;
					break;
				}
#endif /* MODE_SMT */		
				
				if(protocol_swip_GetMode() == M_TOUCH_DFUP)
				{
					break;
				}
				else
				{
					module_start_delay();
				}
			}
			/* no break */
			case TOUCH_NORMAL_OPER_RESET_SYSTEM:
			{
				if(PARAM_GetMode() != PARAM_MODE_NORMAL)
				{
					PARAM_SetMode(PARAM_MODE_NORMAL);
					PARAM_InitConfig();
					algorithm_init();
#if (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY))
					algorithm_local_init(); //code
					algorithm_init_local(); //DSP
#endif /* (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY)) */
				}
			}
			/* no break */
			case TOUCH_NORMAL_OPER_RESET_HAL:
			{
#ifdef MODE_WDT
				module_Watch_Enable();
#endif /* MODE_WDT */		
				MODULE_Initialize();
				HAL_Initialize(NO);
			}
			/* no break */
			case TOUCH_NORMAL_OPER_RESET_MODULE:
			{
				if(!module_Start())
				{
					sub_state = TOUCH_NORMAL_OPER_ENTER;
					break;
				}
				if(IS_FINGER_PEN_MODE(HAL_GetSensingMode()))
				{
					sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE_PEN;
				}
				else
				{
					sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE;
				}
				break;
			}

#ifdef MODE_SMT
			case TOUCH_NORMAL_SMT_MODE:
			{
				if(!module_Defense_Recovery())
				{
					module_Init_LcdOn();
					sub_state = TOUCH_NORMAL_OPER_RESET_SYSTEM;
				}
				else
				{
					module_Tsync1_SignalBypass();
				}
				break;
			}
#endif /* MODE_SMT */

			case TOUCH_NORMAL_OPER_RESET_REFERENCE:
			{
#if USED_NOISE_HOPPING_FREQ
#if (USED_LPWG_MODE_CONTROL && CUSTOMER == MODEL_LGD_SW97400B)
				if(IS_LPWG_MODE(HAL_GetSensingMode()))
				{
					algorithm_baseline_tracking_initial();
				}
				else
#endif /* (USED_LPWG_MODE_CONTROL && CUSTOMER == MODEL_LGD_SW97400B) */		
				{
					if(module_Switch_Freq(thisCommonConf->HoppFreq1))
					{
						HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_HOP1_MODE);
						algorithm_baseline_tracking_initial();
					}
					if(module_Switch_Freq(thisCommonConf->MainFreq))
					{
						HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_MAIN_MODE);
						algorithm_baseline_tracking_initial();
					}
				}
#else /* USED_NOISE_HOPPING_FREQ */
				algorithm_baseline_tracking_initial();
#endif /* USED_NOISE_HOPPING_FREQ */

				sptAlgorithmInfo->bLineFilterRepeatCheck = 0;

				if(IS_FINGER_ONLY_MODE(HAL_GetSensingMode()))
				{
					sub_state = TOUCH_NORMAL_OPER_NORMAL_READY;
				}
				else
				{
					sub_state = TOUCH_NORMAL_OPER_READY_REFERENCE_PEN;
				}
				break;
			}

#if USED_IDLE_MODE_CONTROL
			case TOUCH_NORMAL_OPER_RESET_REFERENCE_IDLE:
			{
				algorithm_baseline_tracking_initial();
				//algorithm_baseline_tracking_initial_idle(NO);
				sub_state = TOUCH_NORMAL_OPER_IDLE;
				break;
			}
#endif /* USED_IDLE_MODE_CONTROL */

			case TOUCH_NORMAL_OPER_NORMAL_READY:
			{
				tHalIntrHandle.ulInitFirstFrame = 0;

#if USED_ECLK_ON_OFF_CONTROL
				HAL_SetECLKOnOffControl(YES);
#endif /* USED_ECLK_ON_OFF_CONTROL */
	
#if (USED_IDLE_MODE_CONTROL || USED_FRAME_SKIP_IDLE_MODE_CONTROL)				
				sptAlgorithmInfo->ulIdleModeEnterCheckCount = 0;
#endif /* (USED_IDLE_MODE_CONTROL || USED_FRAME_SKIP_IDLE_MODE_CONTROL) */
				
				sub_state = TOUCH_NORMAL_OPER_NORMAL;				
				break;
			}

			case TOUCH_NORMAL_OPER_NORMAL:
			{	
#ifdef MODE_WDT				
				KICK_DOG();
#endif /* MODE_WDT */
				if(RESET_FLAG == 1)
				{
#if USED_ESD_RECOVERY_CODE
					while(1); //WDT Reset
#else /* USED_ESD_RECOVERY_CODE */
					RESET_FLAG = 0;
					sub_state = TOUCH_NORMAL_OPER_RESET_MODULE;
#endif /* USED_ESD_RECOVERY_CODE */
					break;
				}
				
				if(!module_wait_full_sample_done())
				{
					sub_state = TOUCH_NORMAL_OPER_ENTER;
					break;
				}
				
				//Interpolation_LYB
				if(DoReportOrgPos){
					algorithm_PendTouchEvent();
					algorithm_coord_UpdatePosHistoryInfo();
					DoReportOrgPos = NO;
				}
				
#if USED_ESD_RECOVERY_CODE
				if(algorithm_check_abnormal_rawdata())
				{
					while(1); //WDT Reset
				}
#endif /* USED_ESD_RECOVERY_CODE */ 
				
#if LGD_ERROR_FRAME_PROCESS_EN
				if(LGD_error_frame_process())	break;
#endif

				protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*Raw Data*/);

#if USED_NORMAL_NI_SENSING
				if(algorithm_process_ni() == NO)
				{
					sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE;
					break;
				}
#endif /* USED_NORMAL_NI_SENSING */

//				usbConnected = mUsbCfgST();

				if (wakeupSignalEn)
				{
					if (frameCntForUSBAbnormal++ > 2)
					{
						wakeupSignalEn = NO;
						frameCntForUSBAbnormal = 0;
						abnormalUSBOperating = YES;
					}
				}
				else
				{
					frameCntForUSBAbnormal = 0;
					abnormalUSBOperating = NO;
				}

#if 1
				if(algorithm_process(FULL_MODE) == NO)
				{
#if USED_ESD_RECOVERY_CODE
					while(1); //WDT Reset
#else /* USED_ESD_RECOVERY_CODE */
					sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE;
#endif /* USED_ESD_RECOVERY_CODE */
					break;
				}
#endif
				//Phone Noise
				if(SRIC_reset_flag)
				{
#if USED_ESD_RECOVERY_CODE
					while(1); //WDT Reset
#else /* USED_ESD_RECOVERY_CODE */
					SRIC_reset_flag = NO;
					sub_state = TOUCH_NORMAL_OPER_RESET_MODULE;
#endif /* USED_ESD_RECOVERY_CODE */
				}

#if ABNORMAL_TSYNC_FALLING_TIME_CHECK
				if(abnormalTsyncLowTime)
				{
					abnormalTsyncLowTime = NO;
					abnormal_rawdata_temp(NO);  // abnormal raw data count init...

					SensingBufferInit();
					sub_state = TOUCH_NORMAL_OPER_ENTER;
					TEST_LOCAL_STATE = 0;

					break;
				}
				else
				{
					if (abnormal_rawdata_temp(NO))
					{
#if USED_ESD_RECOVERY_CODE
						while(1); //WDT Reset
#else /* USED_ESD_RECOVERY_CODE */
						SensingBufferInit();
						sub_state = TOUCH_NORMAL_OPER_ENTER;
						TEST_LOCAL_STATE = 0;
#endif /* USED_ESD_RECOVERY_CODE */

						break;
					}
				}
#else
				if(abnormal_rawdata_temp(NO))
				{
#if USED_ESD_RECOVERY_CODE
					while(1); //WDT Reset
#else /* USED_ESD_RECOVERY_CODE */
					SensingBufferInit();
					sub_state = TOUCH_NORMAL_OPER_ENTER;
					TEST_LOCAL_STATE = 0;
#endif /* USED_ESD_RECOVERY_CODE */
					break;
				}
#endif

#if USED_RF_NOISE_RECOVERY_CODE
				if(algorithm_check_abnormal_deltadata())
				{
					while(1); //WDT Reset
				}

//				if (GPIO->tGPIO_DATA_1._GPIO_VUSB18 == 0x1)
//				{
//					if (CheckRemoteWakeup() == 0  && (CheckUsbConfig() != 1) && (CheckHIDReady() != 1))
//					{
//						while(1); //WDT Reset
//					}
//				}
#endif /* USED_RF_NOISE_RECOVERY_CODE */	
				
#if USED_NOISE_HOPPING_FREQ
				if (algorithm_Check_FreqHopping())
				{
#if (USED_LPWG_MODE_CONTROL && CUSTOMER == MODEL_LGD_SW97400B)
					if(IS_LPWG_MODE(HAL_GetSensingMode())) break;
#endif /* (USED_LPWG_MODE_CONTROL && CUSTOMER == MODEL_LGD_SW97400B) */		
					sub_state = TOUCH_NORMAL_OPER_SWITCH_FREQ;
					break;
				}
#endif /* USED_NOISE_HOPPING_FREQ */

#if USED_IDLE_MODE_CONTROL
				if(algorithm_CheckFingerIdleModeControl())
				{
					if(FLAG_mode == 130)
						sub_state = TOUCH_NORMAL_OPER_SWITCH_FREQ;
					else
						sub_state = TOUCH_NORMAL_OPER_IDLE_READY;
					break;
				}
#endif /* USED_IDLE_MODE_CONTROL */
				
#if USED_FRAME_SKIP_IDLE_MODE_CONTROL
				if(algorithm_CheckFingerIdleModeControl())
				{					
#if (USED_LPWG_MODE_CONTROL && CUSTOMER == MODEL_LGD_SW97400B)
					if(IS_LPWG_MODE(HAL_GetSensingMode())) break;
#endif /* (USED_LPWG_MODE_CONTROL && CUSTOMER == MODEL_LGD_SW97400B) */		
					if(HAL_GetSensingChangeMode() == SM_CHANGE_IDLE_MODE)
					{
						HAL_SetSensingMode(SM_FINGER_ONLY_IDLE_MODE);
					}
					else if(HAL_GetSensingChangeMode() == SM_CHANGE_ACTIVE_FRQ_MAIN_MODE)
					{
						HAL_SetSensingMode(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
					}
					HAL_SetSensingChangeMode(SM_CHANGE_COMPLETE);

					sub_state = TOUCH_NORMAL_OPER_NORMAL_READY;

					break;
				}
#endif /* USED_FRAME_SKIP_IDLE_MODE_CONTROL */			
				break;
			}
#if USED_IDLE_MODE_CONTROL
			case TOUCH_NORMAL_OPER_IDLE_READY:
			{
				//HAL_SetSensingChangeMode(SM_CHANGE_IDLE_MODE);
				if(IDLE_FLAG==NORMAL_OPER)
				{
					IDLE_FLAG = IDLE_READY;
					FLAG_30Hz = 1;
				}
				sptAlgorithmInfo->ulIdleModeEnterCheckCount = 0;
				tHalIntrHandle.ulInitFirstFrame = 0;
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
				if(RESET_FLAG == 1)
                {	
					RESET_FLAG = 0;
					IDLE_FLAG = IDLE_END;
					FLAG_30Hz = 3;
					sub_state = TOUCH_NORMAL_OPER_RESET_MODULE;
					break;
                }	
				if(IDLE_FLAG==IDLE_OPER)
				{
					if(!module_wait_full_sample_done())
					//if(!module_wait_NI_sample_done())
					{
						sub_state = TOUCH_NORMAL_OPER_ENTER;
						break;
					}
					//protocol_LogMatrix(LT_RAWDATA, sptAlgorithmInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, sptAlgorithmInfo->ucScreenRow, 84/*Raw Data*/);

					if(algorithm_process_Idle() == NO)
					{
						SensingBufferInit();
						sub_state = TOUCH_NORMAL_OPER_RESET_MODULE;//TOUCH_NORMAL_OPER_NORMAL_READY;
						break;
					}
	
					if(algorithm_CheckFingerIdleModeControl()||protocol_swip_GetMode()==M_TOUCH_DIAG)
					{
						IDLE_FLAG = IDLE_END;
						FLAG_30Hz = 3;
						SensingBufferInit();
						sub_state = TOUCH_NORMAL_OPER_NORMAL_READY;//TOUCH_NORMAL_OPER_RESET_MODULE;
						HAL_SetSensingMode(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
						break;
					}
				}
				break;
			}
#endif /* USED_IDLE_MODE_CONTROL */
#if USED_NOISE_HOPPING_FREQ
			case TOUCH_NORMAL_OPER_SWITCH_FREQ:
			{
				eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();
				eSENSING_FREQ_t _Freq;
				
				if(IS_ACTIVE_MODE_FRQ_MAIN(eSensingMode))
				{
					_Freq = thisCommonConf->HoppFreq1;
				}
				else if(IS_ACTIVE_MODE_FRQ_HOP1(eSensingMode))
				{
					_Freq = thisCommonConf->MainFreq;
				}
				
#if USED_ECLK_ON_OFF_CONTROL
				HAL_SetECLKOnOffControl(NO);
#endif /* USED_ECLK_ON_OFF_CONTROL */

				if(module_Switch_Freq(_Freq))
				{
					if(_Freq == thisCommonConf->HoppFreq1)
					{
						HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_HOP1_MODE);
						sub_state = TOUCH_NORMAL_OPER_NORMAL_READY;
					}
					else if(_Freq == thisCommonConf->MainFreq)
					{
						HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_MAIN_MODE);
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

			case TOUCH_NORMAL_OPER_EXIT:
			{
#ifdef MODE_WDT				
				Hal_WDT_DeInit();
#endif /* MODE_WDT */
				module_Stop(); // NOTE : �Լ� ���������� ����!!
				
				bLoop = NO;
				continue;
				/* no break */
			}
    	}

		if( protocol_swip_GetRecalibrate() == YES)
		{
			protocol_LogCode(LT_DIAGNOSIS, (4)/*System is Entered!*/);

			sub_state = TOUCH_NORMAL_OPER_RESET_REFERENCE;

			protocol_swip_SetRecalibrate(NO);
		}

		if( protocol_swip_GetReadModuleConfigStatus() == YES )
		{
//			module_Stop();

			sub_state = TOUCH_NORMAL_OPER_RESET_MODULE;

			protocol_swip_SetReadModuleConfigStatus(NO);
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
					HAL_SetTPICMuxEnControl(NO);
					GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 1;
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
//					if(IS_FINGER_PEN_MODE(eSensingMode))
//					{
//						HAL_SetSensingChangeMode(SM_CHANGE_FINGER_PEN_SEARCH_MODE);
//					}
//					else
//					{
//						if(IS_IDLE_MODE(eSensingMode))
//						{
//							HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_MAIN_MODE);
//						}
//						else
//						{
//							if(!IS_ACTIVE_MODE_FRQ_MAIN(eSensingMode))
//							{
//								HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_FRQ_MAIN_MODE);
//							}
//						}
//					}
					/*
					 * Wait Mode Change!!
					 */
//					module_wait_full_sample_done();

					break;
				}
				case M_TOUCH_DFUP:
				{
					sub_state = TOUCH_NORMAL_OPER_EXIT;
					main_state = TOUCH_MAIN_OPERATION_DFUP;

					// TSYNCN_OUT High
					GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT = 0x01;
					GPIO->tGPIO_DIR_1._GPIO_TSYNC_OUT = 0x1;  // OUTPUT
					GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 0x0;
					PWMDRV_ITConfig(DISABLE);
					NVIC_DisableIRQ(EXTI0_IRQn);
					NVIC_DisableIRQ(EXTI1_IRQn);
					MSPI_ITConfig(DISABLE);
					MSPI_Cmd(DISABLE);
					PWMDRV_Cmd(DISABLE);

					break;
				}
				case M_PARAMETER:
				{
//					F_GPB11();
#if USED_ECLK_ON_OFF_CONTROL
					HAL_SetECLKOnOffControl(NO);
#endif /* USED_ECLK_ON_OFF_CONTROL */
#if USED_TPIC_MUXEN_ON_OFF_CONTROL
					HAL_SetTPICMuxEnControl(NO);
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
					GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT = 0x01;
					GPIO->tGPIO_DIR_1._GPIO_TSYNC_OUT = 0x1;  // OUTPUT
					GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 0x0;
					PWMDRV_ITConfig(DISABLE);
					NVIC_DisableIRQ(EXTI0_IRQn);
					NVIC_DisableIRQ(EXTI1_IRQn);
					MSPI_ITConfig(DISABLE);
					MSPI_Cmd(DISABLE);
					PWMDRV_Cmd(DISABLE);

					PARAM_SetMode(PARAM_MODE_NONE);
					sub_state = TOUCH_NORMAL_OPER_RESET_SYSTEM;
					break;
				}
				case M_TOUCH_LPWG:
				{
					sub_state = TOUCH_NORMAL_OPER_EXIT;
					main_state = TOUCH_MAIN_OPERATION_LPWG;
					break;
				}
			}
		}

		prevMode = currMode;	
    }

    return main_state;
}

