/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : interrupt.c
 * created on : 17. 4. 2017
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


/**********************************************************
* MSPI Interrupt IRQ Hanler!!
**********************************************************/
//#if USED_IDLE_MODE_CONTROL
//__IO eOP_CONTROL_MODE_t gOperationIntrHandle;
//#endif /* USED_IDLE_MODE_CONTROL */

uint16_t p_currentRowStart = 			0;
__IO uint16_t sensingRowStart = 		0;
uint16_t currentRowStart = 	 			0;
__IO uint16_t sensingRowStart_Tilt;
//__IO uint32_t gVSyncCnt = 0;
//__IO uint32_t gulTsyncBothEdgeCnt = 0;
//__IO uint32_t gIdleCnt = 0;
__IO uint32_t pFreqHoppingAndModeTest = 0;

//uint16_t dbg_interrupt[20] = { 0, };

//extern int PenCoordIdx;

#if 1
void HardFault_Handler(void)
{
	while (1);
}
#else
volatile unsigned int  sram_array[20];

#define probing_state sram_array[16]
#define hf_expected   sram_array[17]

void HF_Handler_main(unsigned int * hf_args)
{
	/* Increment stacked PC */
	hf_args[6] = hf_args[6] + 2;    
	return;
}

__asm void HardFault_Handler(void)
{
	MOVS    r0, #4;
	MOV     r1, lr;
	TST     r0, r1;
	BEQ     stacking_used_MSP;
	MRS     r0, psp ; first parameter - stacking was using PSP;
	LDR     r1,=__cpp(HF_Handler_main);
	BX      r1;
	stacking_used_MSP;
	MRS     r0, msp ; first parameter - stacking was using MSP;
	LDR     r1,=__cpp(HF_Handler_main);
	BX      r1;
}
#endif

#if (USED_PEN_MODE_OPERATION)
extern int TEST_LOCAL_STATE;
extern uint16_t currentColStart;

static tAlgorithmInfo_t * sptAlgorithmInfo  = NULL;
void Interrupt_Init(void)
{
    sptAlgorithmInfo = algorithm_GetInfo();
}
#endif /* (USED_PEN_MODE_OPERATION) */

//extern uint8_t DebugPenRawView;
extern int8_t sensingRowStart_Tilt_Offset;
void PendSV_InterruptHandler(void)
{
	eActivePenType_t eActivePenOpType = hal_Info_GetControlActivePenOPType();
	eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();

	// _gT(_GPIO_TP_INTR);

	switch (eSensingMode)
	{
#if USED_PEN_MODE_OPERATION
		case SM_FINGER_PEN_ACTIVE_MODE:
		{
			tAlgorithmInfo_t * ptAlgorithmInfo = algorithm_GetInfo();  // NOTE : Global Variable占쏙옙 占쏙옙占쏙옙占싹울옙 Hal占십울옙占쏙옙 Initialize占싹몌옙 占쏙옙占� 占쏙옙 占쏙옙 占쌍듸옙占쏙옙 占쏙옙占쏙옙占쏙옙占쏙옙!! IRQ占쏙옙 Hal占쏙옙占쏙옙占쏙옙 占쏙옙치 占싱듸옙!!
			volatile ePartialSensing_t RetVal = PARTIAL_PEN_BEACON;
			RetVal = tHalIntrHandle.eLocalSensingType;

			hal_set_LocalType_flag(RetVal);

			if(TEST_LOCAL_STATE == 1)
			{
				switch (RetVal)
				{
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
					case PARTIAL_PEN_COORD_DATA1:
					case PARTIAL_PEN_COORD_DATA2:
					case PARTIAL_PEN_COORD_DATA3:
					case PARTIAL_PEN_COORD_DATA4:
					{
						module_read_local_penposition_pendata_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						
						if(sptAlgorithmInfo->tPenInfo.bSearch_Mode_Flag == 0)
						{
							algorithm_data_local_process(RetVal);

							if(sptAlgorithmInfo->tPenInfo.usPen_Coord_Cnt==0)
							{
								if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_MS)
								{
									hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_PEN_BEACON);
								}
								else if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WGP)
								{
									hal_Info_SetWGPPenBeaconType(PWM_WGP_PEN_GETABS_BEACON);
								}
								#ifdef OUT_IN_DRAWING
								sptAlgorithmInfo->tPenInfo.PrePos.x = 0;
								sptAlgorithmInfo->tPenInfo.PrePos.y = 0;
								#endif
								algorithm_coord_init_local_DSP();
								sptAlgorithmInfo->tCoord_local_dsp.PenContactCnt = 0;
								sensingRowStart_Tilt = sensingRowStart;
								sptAlgorithmInfo->tTiltInfo.sTilt_cnt = 1;
								sptAlgorithmInfo->tTiltInfo.HID_TILT_X = sptAlgorithmInfo->tTiltInfo.Smooth_PastTilt.x = 9000;
								sptAlgorithmInfo->tTiltInfo.HID_TILT_Y = sptAlgorithmInfo->tTiltInfo.Smooth_PastTilt.y = 9000;
							}

							if(sptAlgorithmInfo->tPenInfo.bPenContact == YES || sptAlgorithmInfo->tPenInfo.bPrevPenContact == YES)
							{
								algorithm_local_dsp_process(1, RetVal, LOCAL_MODE);
							}
							else
							{
								algorithm_local_dsp_process(1, RetVal, LOCAL_HOVER_MODE);
							}
								
							if(sptAlgorithmInfo->tPenInfo.usPen_Coord_Cnt++>32760)
								sptAlgorithmInfo->tPenInfo.usPen_Coord_Cnt = 10;
						}
						else
						{
							algorithm_hover_full_search(RetVal);

							sptAlgorithmInfo->tPenInfo.usPen_Coord_Cnt = 0;
							sptAlgorithmInfo->tPenInfo.bPenContact = NO;
							sptAlgorithmInfo->tPenInfo.bReportEraser = 0;
						}
						break;
					}
	#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
					case PARTIAL_PEN_COORD1:
					case PARTIAL_PEN_COORD2:
					case PARTIAL_PEN_COORD3:
					case PARTIAL_PEN_COORD4:
					{
						// _gOut(_GPIO_TP_INTR, GPIO_DATA_LOW);
						module_read_local_penposition_sample_data(RetVal);
						// _gOut(_GPIO_TP_INTR, GPIO_DATA_HIGH);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
		#if 1
						if (sptAlgorithmInfo->tPenInfo.bSearch_Mode_Flag == 0)
						{
							if(sptAlgorithmInfo->tPenInfo.usPen_Coord_Cnt==0)
							{
								sptAlgorithmInfo->tPenInfo.usSearch_Mode_Cnt = 0;
								if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_MS)
								{
									hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_PEN_BEACON);
								}
								else if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WGP)
								{
									hal_Info_SetWGPPenBeaconType(PWM_WGP_PEN_GETABS_BEACON);
								}
								
								#ifdef OUT_IN_DRAWING
								sptAlgorithmInfo->tPenInfo.PrePos.x = 0;
								sptAlgorithmInfo->tPenInfo.PrePos.y = 0;
								#endif
								algorithm_coord_init_local_DSP();
								sptAlgorithmInfo->tCoord_local_dsp.PenContactCnt = 0;
								sensingRowStart_Tilt = sensingRowStart;
								for(uint8_t i = 1; i < 6 ; i++){sptAlgorithmInfo->tTiltInfo.Median_PastTilt[i].x = 9000;sptAlgorithmInfo->tTiltInfo.Median_PastTilt[i].y = 9000;}
							}

							if(sptAlgorithmInfo->tPenInfo.bPenContact == YES || sptAlgorithmInfo->tPenInfo.bPrevPenContact == YES)
							{
								algorithm_local_dsp_process(1, RetVal, LOCAL_MODE);
							}
							else
							{
								algorithm_local_dsp_process(1, RetVal, LOCAL_HOVER_MODE);
							}
							if(sptAlgorithmInfo->tPenInfo.usPen_Coord_Cnt++>32760)
								sptAlgorithmInfo->tPenInfo.usPen_Coord_Cnt = 10;
						}
						else
						{
							algorithm_hover_full_search(RetVal);

							sensingRowStart_Tilt = sensingRowStart;
							sptAlgorithmInfo->tPenInfo.usPen_Coord_Cnt = 0;
							sptAlgorithmInfo->tPenInfo.bPenContact = NO;
							sptAlgorithmInfo->tPenInfo.bReportEraser = 0;
							sensingRowStart_Tilt_Offset = 0;
						}
		#endif
						break;
					}
					case PARTIAL_PEN_DATA1:
					case PARTIAL_PEN_DATA2:
					case PARTIAL_PEN_DATA3:
					case PARTIAL_PEN_DATA4:
					case PARTIAL_PEN_DATA5:
					{
						module_read_local_pendata_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);

						algorithm_data_local_process(RetVal);

						/*
						 * For Tilt at WACOM AIT Protocol!!
						 */
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
						if(RetVal == PARTIAL_PEN_DATA3 && sptAlgorithmInfo->tPenInfo.bDSP_SendDataEn == 1
								&& eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WACOM)
						{
							SendPenData();
							sptAlgorithmInfo->tPenInfo.bDSP_SendDataEn = 0;
						}
		#endif
						if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_MS)
						{
							if(RetVal == PARTIAL_PEN_DATA3 ||
								RetVal == PARTIAL_PEN_DATA4)
							{
								p_currentRowStart = currentRowStart;
								currentRowStart = sensingRowStart;
								currentColStart = sptAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
							}
						}

						if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WGP)
						{
							if(RetVal == PARTIAL_PEN_DATA4)
							{
								p_currentRowStart = currentRowStart;
								currentRowStart = sensingRowStart;
								currentColStart = sptAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
							}
						}
						break;
					}
	#endif /* (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN) */
					case PARTIAL_FINGER1:
					case PARTIAL_FINGER2:
					case PARTIAL_FINGER3:
					case PARTIAL_FINGER4:
					case PARTIAL_FINGER5:
					{
						module_read_local_finger_sample_data(RetVal);
						if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_MS)
						{	
#if (USED_MODULE_DEF == MODULE_DEF_L_1)
	#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
							if(RetVal == PARTIAL_FINGER3 ||
								RetVal == PARTIAL_FINGER5)
	#else /* (CUSTOMER == MODEL_DEF_QHD_92407) */
							if(RetVal == PARTIAL_FINGER3 ||
								RetVal == PARTIAL_FINGER4)
	#endif /* (CUSTOMER == MODEL_DEF_QHD_92407) */
#else /* (USED_MODULE_DEF == MODULE_DEF_L_1) */
							if(RetVal == PARTIAL_FINGER1 ||
								RetVal == PARTIAL_FINGER3)
#endif /* (USED_MODULE_DEF == MODULE_DEF_L_1) */
							{
								p_currentRowStart = currentRowStart;
								currentRowStart = sensingRowStart;
								currentColStart = sptAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
							}
						}
						else if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WACOM)
						{
#if	(CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP) // TODO!! Check!!
							if(PARTIAL_FINGER3 != RetVal)
#endif
							{
								p_currentRowStart = currentRowStart;
								currentRowStart = sensingRowStart;
								currentColStart = sptAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
							}
						}
						else if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WGP)
						{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
							if(RetVal == PARTIAL_FINGER1 ||
								RetVal == PARTIAL_FINGER2)
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
							if(RetVal == PARTIAL_FINGER1)
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
							{
								p_currentRowStart = currentRowStart;
								currentRowStart = sensingRowStart;
								currentColStart = sptAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
							}
						}

						if (RetVal == LOCAL_FINGER_LAST_LHB)
						{
							// _gT(_GPIO_TP_INTR);
//							if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_MS)
//							{
							// _gT(_GPIO_TP_INTR);
//							}
							hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						}
						break;
					}
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
					case PARTIAL_TILT1:
					case PARTIAL_TILT2:
					{
						module_read_local_pentilt_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
		#ifdef TILT_ON
			#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)
						if (sptAlgorithmInfo->tPenInfo.bSearch_Mode_Flag == 0)
							algorithm_local_dsp_process(1, RetVal, LOCAL_TILT_MODE);
			#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
						if (sptAlgorithmInfo->tPenInfo.bSearch_Mode_Flag == 1)
							algorithm_baseline_tracking_continuous_local_ring();
			#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
		#else
						sensingRowStart_Tilt = sensingRowStart;
		#endif
						if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WGP)
						{
							p_currentRowStart = currentRowStart;
							currentRowStart = sensingRowStart;
							currentColStart = sptAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
						}
						break;
					}
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
					case PARTIAL_MAX:
					{
						while(1);
					}

					default:
					break;
				}
			}
			else
			{
				switch (RetVal)
				{
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
					case PARTIAL_TILT1:
					case PARTIAL_TILT2:
					{
						module_read_local_pentilt_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						break;
					}
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
					case PARTIAL_PEN_COORD_DATA1:
					case PARTIAL_PEN_COORD_DATA2:
					case PARTIAL_PEN_COORD_DATA3:
					case PARTIAL_PEN_COORD_DATA4:
					{
						module_read_local_penposition_pendata_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						break;
					}
	#else /* USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
					case PARTIAL_PEN_COORD1:
					case PARTIAL_PEN_COORD2:
					case PARTIAL_PEN_COORD3:
					case PARTIAL_PEN_COORD4:
					{
						module_read_local_penposition_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						break;
					}
					case PARTIAL_PEN_DATA1:
					case PARTIAL_PEN_DATA2:
					case PARTIAL_PEN_DATA3:
					case PARTIAL_PEN_DATA4:
					case PARTIAL_PEN_DATA5:
					{
						module_read_local_pendata_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						break;
					}
	#endif /* USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
					case PARTIAL_FINGER1:
					case PARTIAL_FINGER2:
					case PARTIAL_FINGER3:
					case PARTIAL_FINGER4:
					case PARTIAL_FINGER5:
					{
						module_read_local_finger_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						break;
					}
					default:
						break;
				}
			}
			break;
		}
#endif /* USED_PEN_MODE_OPERATION */
		case SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE:
		case SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE:
		case SM_FINGER_ONLY_ACTIVE_FRQ_HOP2_MODE:
		case SM_FINGER_ONLY_IDLE_MODE:
		case SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_MAIN_MODE:
		case SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_HOP1_MODE:
		case SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_HOP2_MODE:
//		case SM_FINGER_PEN_SEARCH_IDLE_MODE:
		{
			break;
		}
	}
}

void HAL_PendSVHandlerInitialize(void)
{
	/*
	* NOTE : PendSV_IRQn를 Enable시키지 않고.. 왜 priority만 설정하고 있지?
	*/
	Fncp_PendSV_IRQHandler = &PendSV_InterruptHandler;
	NVIC_SetPriority(PendSV_IRQn, PendSV_IRQn_Priority);
}

void SensingBufferInit(void)
{
	p_currentRowStart =			0;
	sensingRowStart =			0;
	currentRowStart =			0;
	sensingRowStart_Tilt = 		0;

	pFreqHoppingAndModeTest =	0;
#if USED_ECLK_ON_OFF_CONTROL
	HAL_SetECLKOnOffControl(NO);
#endif /* USED_ECLK_ON_OFF_CONTROL */
	tHalIntrHandle.ulMSPIPenModeIntrCnt = 0;
	tHalIntrHandle.ulInitFirstFrame = 1;
	tHalIntrHandle.ulVSyncFlag = 0;
	tHalIntrHandle.ulTSyncInFallingCnt = 0;
	tHalIntrHandle.ulTSyncInRisingCnt = 0;
	tHalIntrHandle.ulLocalIndexChangeStart = 0;
#if USED_PWM_PULSE_END_FLAG_CHECK
	tHalIntrHandle.ulPWM_Pulse_End_Flag = NO;
#endif /* USED_PWM_PULSE_END_FLAG_CHECK */
}
