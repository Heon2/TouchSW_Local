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
__IO uint32_t gMspiCounterPen = 0;
__IO uint32_t isFirstFrame = 1;

//#if USED_IDLE_MODE_CONTROL
//__IO eOP_CONTROL_MODE_t gOperationIntrHandle;
//#endif /* USED_IDLE_MODE_CONTROL */

uint16_t p_currentRowStart = 			0;
__IO uint16_t sensingRowStart = 		0;
uint16_t currentRowStart = 	 			0;

//__IO uint32_t gVSyncCnt = 0;
//__IO uint32_t gulTsyncBothEdgeCnt = 0;
//__IO uint32_t gIdleCnt = 0;
__IO uint32_t nextTSync = 0;

__IO uint32_t pFreqHoppingAndModeTest = 0;

uint16_t dbg_interrupt[20] = { 0, };

extern int PenCoordIdx;

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

#if (!defined(FINGER_ONLY) || USED_PEN_MODE_OPERATION)
extern int TEST_LOCAL_STATE;
extern uint16_t currentColStart;
extern volatile int gDCFullMode;

static tAlgorithmInfo_t * sptAlgorithmInfo  = NULL;

#endif /* (!defined(FINGER_ONLY) || USED_PEN_MODE_OPERATION) */

#if USED_PEN_MODE_OPERATION
void Interrupt_Init(void)
{
    sptAlgorithmInfo = algorithm_GetInfo();
}
#endif /* USED_PEN_MODE_OPERATION */

#if (!USED_FINGER_ONLY)
extern void algorithm_coord_init_local_DSP(void);
#ifdef TILT_ON
extern int					HID_TILT_X ;
extern int					HID_TILT_Y;
#endif /* TILT_ON */
extern bool ReportSkip;
#endif /* (!USED_FINGER_ONLY) */

int Pen_Coord_Cnt = 0;
void PendSV_InterruptHandler(void)
{
	dbg_interrupt[0]++;
	eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();
#if USED_PEN_MODE_OPERATION
	switch(eSensingMode)
	{
		case SM_FINGER_PEN_ACTIVE_MODE:
		case SM_FINGER_PEN_IDLE_MODE:
		case SM_FINGER_PEN_HOVER_ACTIVE_MODE:
		case SM_FINGER_PEN_HOVER_IDLE_MODE:
		{
			dbg_interrupt[1]++;
			ePartialSensing_t RetVal = PARTIAL_PEN_BEACON;
			tAlgorithmInfo_t * ptAlgorithmInfo = algorithm_GetInfo();  // NOTE : Global Variable로 선언하여 Hal쪽에서 Initialize하면 사용 할 수 있도록 변경하자!! IRQ각 Hal쪽으로 위치 이동!!

			RetVal = module_read_local_sample_data();

			hal_set_LocalType_flag(RetVal);

			if(TEST_LOCAL_STATE == 1)
			{
				switch(RetVal)
				{
//					case PARTIAL_PEN_COORD1:
					case PARTIAL_PEN_COORD2:
					case PARTIAL_PEN_COORD3:
					case PARTIAL_PEN_COORD4:
					{
						dbg_interrupt[2]++;
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
//						algorithm_local_dsp_process(1,RetVal, LOCAL_MODE);
//						algorithm_hover_full_search();

						/*
						if (gDCFullMode == 0) // local hover & local
						{
							if (Pen_Coord_Cnt == 0)
							{
								algorithm_coord_init_local_DSP();
							}

							algorithm_local_dsp_process(1, RetVal, LOCAL_MODE);

							if (Pen_Coord_Cnt++ > 32760)
								Pen_Coord_Cnt = 10;
						}
						*/
#if 1
							if(gDCFullMode == 0) // local hover & local
							{
								sptAlgorithmInfo->tPenInfo.bPenContact = 1;

								dbg_interrupt[3]++;
								if(Pen_Coord_Cnt == 0)
								{
									dbg_interrupt[4]++;
									algorithm_coord_init_local_DSP();
								}

								algorithm_local_dsp_process(1,RetVal, LOCAL_MODE);

//								if(sptAlgorithmInfo->tPenInfo.bPenContact == YES || sptAlgorithmInfo->tPenInfo.bPrevPenContact == YES)
//								{
//									dbg_interrupt[18]++;
//									algorithm_local_dsp_process(1,RetVal, LOCAL_MODE);
//								}
//								else
//								{
//									dbg_interrupt[19]++;
//									algorithm_local_dsp_process(1,RetVal, LOCAL_HOVER_MODE);
//								}

								if(Pen_Coord_Cnt++>32760)
									Pen_Coord_Cnt = 10;
							}
							else
							{
								sptAlgorithmInfo->tPenInfo.bPenContact = 0;
								dbg_interrupt[5]++;
//								g_RetVal = RetVal;
									algorithm_hover_full_search();

								Pen_Coord_Cnt = 0;
							}
#endif
					}
					break;
					case PARTIAL_PEN_DATA1:
					case PARTIAL_PEN_DATA2:
					case PARTIAL_PEN_DATA3:
					case PARTIAL_PEN_DATA4:
					case PARTIAL_PEN_DATA5:
					{
						dbg_interrupt[6]++;
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						// TODO : Data Parser Function
//						algorithm_data_local_process(RetVal);

						switch(RetVal)
						{
							case PARTIAL_PEN_DATA1:
							case PARTIAL_PEN_DATA4:
							{
								p_currentRowStart = currentRowStart;
								currentRowStart = sensingRowStart;
								currentColStart = sptAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
							}
							break;
						}
					}
					break;
					case PARTIAL_FINGER6:
					{
						dbg_interrupt[7]++;
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
					}
					break;
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
				switch(RetVal)
				{
		//			case PARTIAL_PEN_COORD1:
					case PARTIAL_PEN_COORD2:
					case PARTIAL_PEN_COORD3:
					case PARTIAL_PEN_COORD4:
					case PARTIAL_PEN_DATA1:
					case PARTIAL_PEN_DATA2:
					case PARTIAL_PEN_DATA3:
					case PARTIAL_PEN_DATA4:
					case PARTIAL_PEN_DATA5:
					case PARTIAL_FINGER1:
					case PARTIAL_FINGER2:
					case PARTIAL_FINGER3:
					case PARTIAL_FINGER4:
					case PARTIAL_FINGER5:
					case PARTIAL_FINGER6:
					{
						dbg_interrupt[8]++;
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
					}
					break;

					default:
					break;
				}
			}

			break;
		}
		case SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE:
		case SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE:
		case SM_FINGER_ONLY_ACTIVE_FRQ_HOP2_MODE:
		case SM_FINGER_ONLY_IDLE_MODE:
		case SM_FINGER_PEN_SEARCH_ACTIVE_MODE:
		case SM_FINGER_PEN_SEARCH_IDLE_MODE:
		{
			dbg_interrupt[9]++;
			break;
		}
	}

#else /* USED_PEN_MODE_OPERATION */

	switch(eSensingMode)
	{
		case SM_FINGER_PEN_ACTIVE_MODE:
		case SM_FINGER_PEN_IDLE_MODE:
		case SM_FINGER_PEN_HOVER_ACTIVE_MODE:
		case SM_FINGER_PEN_HOVER_IDLE_MODE:
		{
			break;
		}
		case SM_S3_ACTIVE_MODE:
		case SM_S3_IDLE_MODE:
		{
			break;
		}
		case SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE:
		case SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE:
		case SM_FINGER_ONLY_ACTIVE_FRQ_HOP2_MODE:
		case SM_FINGER_ONLY_IDLE_MODE:
		{
			break;
		}
		default:
		{
			break;
		}
	}
#endif /* USED_PEN_MODE_OPERATION */

//	int sensingMode = getSensingMode();
//	tAlgorithmInfo_t * ptAlgorithmInfo = algorithm_GetInfo();  // NOTE : Global Variable로 선언하여 Hal쪽에서 Initialize하면 사용 할 수 있도록 변경하자!! IRQ각 Hal쪽으로 위치 이동!!
//
//	if((sensingMode) ==	SM_FINGER_MODE)
//	{
//		if (gFrameCnt == NI_FRAME)
//		{
//			module_read_full_NI_sample_data();
//		}
//	}
#if (!USED_FINGER_ONLY)
	else
	{
		RetVal = module_read_local_sample_data();

		hal_set_LocalType_flag(RetVal);

		if(TEST_LOCAL_STATE == 1)
		{
			switch(RetVal)
			{
			case PARTIAL_PEN_COORD1:
			case PARTIAL_PEN_COORD2:
			case PARTIAL_PEN_COORD3:
			case PARTIAL_PEN_COORD4:
				{
					hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
#ifdef DC_BASE
					if(gDCFullMode == 0)
#endif
					{
						if(Pen_Coord_Cnt==0){
					#ifdef TILT_ON
							algorithm_coord_init_local_DSP(); 
							HID_TILT_X = 0;
							HID_TILT_Y = 0;
							ReportSkip = 0;
							if(RetVal==PARTIAL_PEN_COORD2 && sptAlgorithmInfo->tPenInfo.bPenContact == YES)ReportSkip=1;
					#endif
						}
						if(Pen_Coord_Cnt++>32760)Pen_Coord_Cnt=10;
						
						if(ptAlgorithmInfo->tPenInfo.bPenContact == YES || ptAlgorithmInfo->tPenInfo.bPrevPenContact == YES)
						algorithm_local_dsp_process(1,RetVal, LOCAL_MODE);
						else
						algorithm_local_dsp_process(1,RetVal, LOCAL_HOVER_MODE);
					}
#ifdef DC_BASE
					else
					{
						if(ptAlgorithmInfo->bDiagMode == NO)
						algorithm_hover_full_search();
						
						Pen_Coord_Cnt = 0;
					}
#endif
				}
				break;

			case PARTIAL_PEN_DATA1:
			case PARTIAL_PEN_DATA2:
			case PARTIAL_PEN_DATA3:
				//				case PARTIAL_PEN_DATA4:
				//				case PARTIAL_PEN_DATA5:
			case LOCAL_PEN_DATA6:
			case LOCAL_PEN_DATA7:
				{
					//					hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
					
					algorithm_data_local_process(RetVal);
					switch(RetVal)
					{
					case PARTIAL_PEN_DATA1:
					case PARTIAL_PEN_DATA3:
						//						case PARTIAL_PEN_DATA5:
					case LOCAL_PEN_DATA7:
						{
							p_currentRowStart = currentRowStart;
							currentRowStart = sensingRowStart;
							currentColStart = ptAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
						}
						break;

					default:
						break;
					}
				}
				break;
				
			case PARTIAL_FINGER3:
				{
					p_currentRowStart = currentRowStart;
					currentRowStart = sensingRowStart;
					currentColStart = ptAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
				}
				break;

			case PARTIAL_FINGER4:
				{
					hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
				}
				break;

			case PARTIAL_MAX:
				{
					while(1);
				}
				/* no break */

			default:
				break;
			}
		}
		else
		{
			switch(RetVal)
			{
			case PARTIAL_PEN_COORD1:
			case PARTIAL_PEN_COORD2:
			case PARTIAL_PEN_COORD3:
			case PARTIAL_PEN_COORD4:
			case PARTIAL_PEN_DATA1:
			case PARTIAL_PEN_DATA2:
			case PARTIAL_PEN_DATA3:
				//					case PARTIAL_PEN_DATA4:
				//					case PARTIAL_PEN_DATA5:
			case LOCAL_PEN_DATA6:
			case LOCAL_PEN_DATA7:
			case PARTIAL_FINGER3:
			case PARTIAL_FINGER4:
				{
					hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
				}
				break;

			default:
				break;
			}
		}
	}
#endif /* (!USED_FINGER_ONLY) */
}

void hal_PendSVHandlerInitialize(void)
{
	/*
	* NOTE : PendSV_IRQn를 Enable시키지 않고.. 왜 priority만 설정하고 있지?
	*/
	Fncp_PendSV_IRQHandler = &PendSV_InterruptHandler;
	NVIC_SetPriority(PendSV_IRQn, PendSV_IRQn_Priority);
}

void SensingBufferInit(void)
{
	//	usRegAddr	= 0; // NOTE : I2C와 USB IRQ함수에서 Address를 받을 때 각각 static으로 선언후 사용.. 여기서는 불필요!!
	//	i2c_sent_byte	= 0; // NOTE : I2C와 USB IRQ함수에서 Address를 받을 때 각각 static으로 선언후 사용.. 여기서는 불필요!!
	//	i2c_received_byte	= 0; // NOTE : I2C와 USB IRQ함수에서 Address를 받을 때 각각 static으로 선언후 사용.. 여기서는 불필요!!

	gMspiCounterPen =			0;
	isFirstFrame =				1;
//	gDoneMSPI =					0;
//	gSensingMode =				0;
//	gFrameCnt =					0;

	p_currentRowStart =			0;
	sensingRowStart =			0;
	currentRowStart =			0;

	nextTSync =					0;
	PenCoordIdx =				0;

	pFreqHoppingAndModeTest =	0;


	tHalIntrHandle.ulMSPIIntrCnt = 0;
	tHalIntrHandle.ulInitFirstFrame = 0;
	tHalIntrHandle.ulVSyncFlag = 0;
	tHalIntrHandle.ulTSyncInFallingCnt = 0;

#ifdef MODE_WDT				
	Hal_WDT_DeInit();
#endif /* MODE_WDT */
	
#if USED_ECLK_ON_OFF_CONTROL
	HAL_SetECLKOnOffControl(NO);
#endif /* USED_ECLK_ON_OFF_CONTROL */
}
