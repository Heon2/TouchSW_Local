/******************************************************************************************************
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
//	SCRB->SYS_RST_CTL.tBit.sys_rst = 0;
	while (1);
}

void MemManage_Handler(void)
{
//	SCRB->SYS_RST_CTL.tBit.sys_rst = 0;
	while (1);
}

void BusFault_Handler(void)
{
//	SCRB->SYS_RST_CTL.tBit.sys_rst = 0;
	while (1);
}

void UsageFault_Handler(void)
{
//	SCRB->SYS_RST_CTL.tBit.sys_rst = 0;
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
#ifdef TILT_ON
extern int8_t sensingRowStart_Tilt_Offset;
#endif
void PendSV_InterruptHandler(void)
{
#if IS_MULTI_PROTOCOL_OPERATION
	eActivePenType_t eActivePenOpType = hal_Info_GetControlActivePenOPType();
#endif /* IS_MULTI_PROTOCOL_OPERATION */
	eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();

	// _gT(_GPIO_TP_INTR);

	switch (eSensingMode)
	{
#if USED_PEN_MODE_OPERATION
		case SM_FINGER_PEN_ACTIVE_FRQ_MAIN_MODE:
		case SM_FINGER_PEN_ACTIVE_FRQ_HOP1_MODE:
		case SM_FINGER_PEN_ACTIVE_FRQ_HOP2_MODE:
		{
//			tAlgorithmInfo_t *ptAlgorithmInfo = algorithm_GetInfo();
			tPenInfo_t *ptPenInfo = &sptAlgorithmInfo->tPenInfo;
			volatile ePartialSensing_t RetVal = PARTIAL_PEN_BEACON;
			RetVal = tHalIntrHandle.eLocalSensingType;

			hal_set_LocalType_flag(RetVal);

			if(TEST_LOCAL_STATE == 1)
			{
				switch(RetVal)
				{
	#if IS_WGPUHDPEN_PROTOCOL_OPERATION
					case PARTIAL_PEN_COORD_DATA1:
					case PARTIAL_PEN_COORD_DATA2:
					case PARTIAL_PEN_COORD_DATA3:
					case PARTIAL_PEN_COORD_DATA4:
		#if USED_WGP_PEN_UHD_16LHB_OPERATION
					case PARTIAL_PEN_COORD_DATA5:
					case PARTIAL_PEN_COORD_DATA6:
					case PARTIAL_PEN_COORD_DATA7:
					case PARTIAL_PEN_COORD_DATA8:
		#endif /* USED_WGP_PEN_UHD_16LHB_OPERATION */
					{
						module_read_local_penposition_pendata_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
		#if 1
						if(ptPenInfo->bSearch_Mode_Flag == 0)
						{
			#if USED_WGP_PEN_UHD_16LHB_OPERATION
							{
								ePartialSensing_t eTempRetVal = RetVal;
								if(eTempRetVal > PARTIAL_PEN_COORD_DATA4)
								{
									eTempRetVal -= 4;
								}
								algorithm_data_local_process(eTempRetVal);
							}
			#else /* USED_WGP_PEN_UHD_16LHB_OPERATION */
							algorithm_data_local_process(RetVal);
			#endif /* USED_WGP_PEN_UHD_16LHB_OPERATION */

							if(ptPenInfo->usPen_Coord_Cnt==0)
							{
			#if USED_PEN_ID_GET_FUNCTION
								hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETHASH_BEACON);
			#else /* USED_PEN_ID_GET_FUNCTION */
								hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETABS_BEACON);
			#endif /* USED_PEN_ID_GET_FUNCTION */

			#ifdef OUT_IN_DRAWING
								ptPenInfo->PrePos.x = 0;
								ptPenInfo->PrePos.y = 0;
			#endif
								algorithm_coord_init_local_DSP();
								sptAlgorithmInfo->tCoord_local_dsp.PenContactCnt = 0;
								sensingRowStart_Tilt = sensingRowStart;
								sptAlgorithmInfo->tTiltInfo.sTilt_cnt = 1;
								sptAlgorithmInfo->tTiltInfo.HID_TILT_X = sptAlgorithmInfo->tTiltInfo.Smooth_PastTilt.x = 9000;
								sptAlgorithmInfo->tTiltInfo.HID_TILT_Y = sptAlgorithmInfo->tTiltInfo.Smooth_PastTilt.y = 9000;
			#if (TiltMedianFilter == YES)
								for(uint8_t i = 1; i < 6 ; i++)
								{
									sptAlgorithmInfo->tTiltInfo.Median_PastTilt[i].x = 9000;
									sptAlgorithmInfo->tTiltInfo.Median_PastTilt[i].y = 9000;
								}
			#endif
							}

							if(ptPenInfo->bPenContact == YES || ptPenInfo->bPrevPenContact == YES)
							{
								algorithm_local_dsp_process(1, RetVal, LOCAL_MODE);
							}
							else
							{
								algorithm_local_dsp_process(1, RetVal, LOCAL_HOVER_MODE);
							}
								
							if(ptPenInfo->usPen_Coord_Cnt++ > 32760)
							{
								ptPenInfo->usPen_Coord_Cnt = 10;
							}
						}
						else
						{
							algorithm_hover_full_search(RetVal);

							ptPenInfo->usPen_Coord_Cnt = 0;
							ptPenInfo->bPenContact = NO;
							ptPenInfo->bReportEraser = 0;
			#ifdef TILT_ON
							sensingRowStart_Tilt_Offset = 0;
			#endif
						}

			#if USED_PEN_ID_GET_FUNCTION
						if(RetVal == PARTIAL_PEN_COORD_DATA2 || RetVal == PARTIAL_PEN_COORD_DATA6)
						{
							if(ptPenInfo->bGetHashIDComplete == NO)
							{
//									if (ptPenInfo->bPenContact == YES || ptPenInfo->bPrevPenContact == YES)
//									{
//										hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETHASH_BEACON);
//									}
								ptPenInfo->bHashnIDCompareDone = NO;
							}
							else
							{
								if(ptPenInfo->bHashnIDCompareDone == NO)
								{
									if(ptPenInfo->ucPrevPenHashVal == ptPenInfo->ucCurPenHashVal)
									{
										hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETABS_BEACON);
										ptPenInfo->bGetPenIDComplete = YES;
										ptPenInfo->bHashnIDCompareDone = YES;
									}
									else
									{
										if(ptPenInfo->bPenContact == YES || ptPenInfo->bPrevPenContact == YES)
										{
											ptPenInfo->bGetPenIDComplete = NO;
											ptPenInfo->ucPrevPenHashVal = ptPenInfo->ucCurPenHashVal;
											ptPenInfo->bHashnIDCompareDone = YES;
											hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETID_1st_BEACON);
										}
									}
								}
								else if(ptPenInfo->bGetPenIDComplete == NO)
								{
									uint32_t currentBeacontype = hal_Info_GetCurrentWGPPenBeaconType();
									if (currentBeacontype == PWM_WGP_PEN_GETID_1st_BEACON)
									{
										hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETID_2nd_BEACON);
									}
									else if (currentBeacontype == PWM_WGP_PEN_GETID_2nd_BEACON)
									{
										hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETID_3rd_BEACON);
									}
									else if (currentBeacontype == PWM_WGP_PEN_GETID_3rd_BEACON)
									{
										hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETABS_BEACON);
									}
								}
							}
						}
			#endif /* USED_PEN_ID_GET_FUNCTION */


		#endif
						break;
					}
	#else /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
		#if USED_MPP_Pen_Protocol_Process_Change
			#ifdef PEN_POS1_DAT1_Replacement
					case PARTIAL_PEN_DATA1:
			#else
					case PARTIAL_PEN_COORD_DATA1:
			#endif
					case PARTIAL_PEN_COORD_DATA2:
					case PARTIAL_PEN_COORD_DATA3:
					case PARTIAL_PEN_COORD_DATA4:
					{
						// _gOut(_GPIO_TP_INTR, GPIO_DATA_LOW);
//						module_read_local_penposition_sample_data(RetVal);
						module_read_local_penposition_pendata_sample_data(RetVal);
						// _gOut(_GPIO_TP_INTR, GPIO_DATA_HIGH);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);

						algorithm_data_local_process(RetVal);

			#if (1 && !USED_LOCAL_INDEX_SETTING_TEST)
						if(ptPenInfo->bSearch_Mode_Flag == 0)
						{
							if(ptPenInfo->usPen_Coord_Cnt == 0)
							{
								ptPenInfo->usSearch_Mode_Cnt = 0;

				#if IS_MULTI_PROTOCOL_OPERATION
								if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_MS)
				#endif /* IS_MULTI_PROTOCOL_OPERATION */
				#if (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION)
								{
									hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_PEN_BEACON);
								}
				#endif /* (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) */
				#if IS_MULTI_PROTOCOL_OPERATION
								else if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WGP)
				#endif /* IS_MULTI_PROTOCOL_OPERATION */
				#if (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION)
								{
					#if USED_PEN_ID_GET_FUNCTION
									hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETHASH_BEACON);
					#else /* USED_PEN_ID_GET_FUNCTION */
									hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETABS_BEACON);
					#endif /* USED_PEN_ID_GET_FUNCTION */
								}
				#endif  /* (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) */
								
				#ifdef OUT_IN_DRAWING
								ptPenInfo->PrePos.x = 0;
								ptPenInfo->PrePos.y = 0;
				#endif
								algorithm_coord_init_local_DSP();
								sptAlgorithmInfo->tCoord_local_dsp.PenContactCnt = 0;
								sensingRowStart_Tilt = sensingRowStart;
				#if (TiltMedianFilter == YES)
								for(uint8_t i = 1; i < 6 ; i++)
								{
									sptAlgorithmInfo->tTiltInfo.Median_PastTilt[i].x = 9000;
									sptAlgorithmInfo->tTiltInfo.Median_PastTilt[i].y = 9000;
								}
				#endif
							}

							if(ptPenInfo->bPenContact == YES || ptPenInfo->bPrevPenContact == YES)
							{
								algorithm_local_dsp_process(1, RetVal, LOCAL_MODE);
							}
							else
							{
								algorithm_local_dsp_process(1, RetVal, LOCAL_HOVER_MODE);
							}
							if(ptPenInfo->usPen_Coord_Cnt++ > 32760)
							{
								ptPenInfo->usPen_Coord_Cnt = 10;
							}
						}
						else
						{
							algorithm_hover_full_search(RetVal);

							sensingRowStart_Tilt = sensingRowStart;
							ptPenInfo->usPen_Coord_Cnt = 0;
							ptPenInfo->bPenContact = NO;
							ptPenInfo->bReportEraser = 0;
				#ifdef TILT_ON
							sensingRowStart_Tilt_Offset = 0;
				#endif
						}
			#endif
						break;
					}
		#else /* USED_MPP_Pen_Protocol_Process_Change */
			#ifdef PEN_POS1_DAT1_Replacement
					case PARTIAL_PEN_DATA1:
			#else
					case PARTIAL_PEN_COORD1:
			#endif
					case PARTIAL_PEN_COORD2:
					case PARTIAL_PEN_COORD3:
					case PARTIAL_PEN_COORD4:
					{
						// _gOut(_GPIO_TP_INTR, GPIO_DATA_LOW);
						module_read_local_penposition_sample_data(RetVal);
						// _gOut(_GPIO_TP_INTR, GPIO_DATA_HIGH);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
			#if (1 && !USED_LOCAL_INDEX_SETTING_TEST)
						if(ptPenInfo->bSearch_Mode_Flag == 0)
						{
							if(ptPenInfo->usPen_Coord_Cnt == 0)
							{
								ptPenInfo->usSearch_Mode_Cnt = 0;

				#if IS_MULTI_PROTOCOL_OPERATION
								if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_MS)
				#endif /* IS_MULTI_PROTOCOL_OPERATION */
				#if (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION)
								{
									hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_PEN_BEACON);
								}
				#endif /* (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) */
				#if IS_MULTI_PROTOCOL_OPERATION
								else if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WGP)
				#endif /* IS_MULTI_PROTOCOL_OPERATION */
				#if (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION)
								{
					#if USED_PEN_ID_GET_FUNCTION
									hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETHASH_BEACON);
					#else /* USED_PEN_ID_GET_FUNCTION */
									hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETABS_BEACON);
					#endif /* USED_PEN_ID_GET_FUNCTION */
								}
				#endif  /* (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) */

				#ifdef OUT_IN_DRAWING
								ptPenInfo->PrePos.x = 0;
								ptPenInfo->PrePos.y = 0;
				#endif
								algorithm_coord_init_local_DSP();
								sptAlgorithmInfo->tCoord_local_dsp.PenContactCnt = 0;
								sensingRowStart_Tilt = sensingRowStart;
				#if (TiltMedianFilter == YES)
								for(uint8_t i = 1; i < 6 ; i++)
								{
									sptAlgorithmInfo->tTiltInfo.Median_PastTilt[i].x = 9000;
									sptAlgorithmInfo->tTiltInfo.Median_PastTilt[i].y = 9000;
								}
				#endif
							}

							if(ptPenInfo->bPenContact == YES || ptPenInfo->bPrevPenContact == YES)
							{
								algorithm_local_dsp_process(1, RetVal, LOCAL_MODE);
							}
							else
							{
								algorithm_local_dsp_process(1, RetVal, LOCAL_HOVER_MODE);
							}
							if(ptPenInfo->usPen_Coord_Cnt++ > 32760)
							{
								ptPenInfo->usPen_Coord_Cnt = 10;
							}
						}
						else
						{
							algorithm_hover_full_search(RetVal);

							sensingRowStart_Tilt = sensingRowStart;
							ptPenInfo->usPen_Coord_Cnt = 0;
							ptPenInfo->bPenContact = NO;
							ptPenInfo->bReportEraser = 0;
				#ifdef TILT_ON
							sensingRowStart_Tilt_Offset = 0;
				#endif
						}
			#endif
						break;
					}
		#endif /* USED_MPP_Pen_Protocol_Process_Change */
		#ifndef PEN_POS1_DAT1_Replacement
					case PARTIAL_PEN_DATA1:
		#endif
					case PARTIAL_PEN_DATA2:
					case PARTIAL_PEN_DATA3:
					case PARTIAL_PEN_DATA4:
					case PARTIAL_PEN_DATA5:
					{
		#if USED_MPP_Pen_Protocol_Process_Change
						module_read_local_penposition_pendata_sample_data(RetVal);
		#else /* USED_MPP_Pen_Protocol_Process_Change */
						module_read_local_pendata_sample_data(RetVal);
		#endif /* USED_MPP_Pen_Protocol_Process_Change */
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);

						algorithm_data_local_process(RetVal);

		#if IS_MULTI_PROTOCOL_OPERATION
						if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_MS)
		#endif /* IS_MULTI_PROTOCOL_OPERATION */
		#if (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION)
						{
							if(RetVal == PARTIAL_PEN_DATA3 ||
								RetVal == PARTIAL_PEN_DATA4)
							{
								p_currentRowStart = currentRowStart;
								currentRowStart = sensingRowStart;
								currentColStart = ptPenInfo->ucCurrentColumnStart;
							}
						}
		#endif /* (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) */
		#if IS_MULTI_PROTOCOL_OPERATION
						else if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WGP)
		#endif /* IS_MULTI_PROTOCOL_OPERATION */
		#if (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION)
						{
			#if USED_PEN_ID_GET_FUNCTION
							if(RetVal == PARTIAL_PEN_DATA2)
							{
								if(ptPenInfo->bGetHashIDComplete == NO)
								{
//									if (ptPenInfo->bPenContact == YES || ptPenInfo->bPrevPenContact == YES)
//									{
//										hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETHASH_BEACON);
//									}
									ptPenInfo->bHashnIDCompareDone = NO;
								}
								else
								{
									if(ptPenInfo->bHashnIDCompareDone == NO)
									{
										if(ptPenInfo->ucPrevPenHashVal == ptPenInfo->ucCurPenHashVal)
										{
											hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETABS_BEACON);
											ptPenInfo->bGetPenIDComplete = YES;
											ptPenInfo->bHashnIDCompareDone = YES;
										}
										else
										{
											if(ptPenInfo->bPenContact == YES || ptPenInfo->bPrevPenContact == YES)
											{
												ptPenInfo->bGetPenIDComplete = NO;
												ptPenInfo->ucPrevPenHashVal = ptPenInfo->ucCurPenHashVal;
												ptPenInfo->bHashnIDCompareDone = YES;
												hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETID_1st_BEACON);
											}
										}
									}
									else if(ptPenInfo->bGetPenIDComplete == NO)
									{
										uint32_t currentBeacontype = hal_Info_GetCurrentWGPPenBeaconType();
										if (currentBeacontype == PWM_WGP_PEN_GETID_1st_BEACON)
										{
											hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETID_2nd_BEACON);
										}
										else if (currentBeacontype == PWM_WGP_PEN_GETID_2nd_BEACON)
										{
											hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETID_3rd_BEACON);
										}
										else if (currentBeacontype == PWM_WGP_PEN_GETID_3rd_BEACON)
										{
											hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETABS_BEACON);
										}
									}
								}
							}
			#endif /* #if USED_PEN_ID_GET_FUNCTION */

							if(RetVal == PARTIAL_PEN_DATA4)
							{
								p_currentRowStart = currentRowStart;
								currentRowStart = sensingRowStart;
								currentColStart = ptPenInfo->ucCurrentColumnStart;
							}
						}
		#endif  /* (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) */
						break;
					}
	#endif /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
					case PARTIAL_FINGER1:
					case PARTIAL_FINGER2:
					case PARTIAL_FINGER3:
					case PARTIAL_FINGER4:
					case PARTIAL_FINGER5:
					{
						module_read_local_finger_sample_data(RetVal);
	#if IS_MULTI_PROTOCOL_OPERATION
						if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_MS)
	#endif /* IS_MULTI_PROTOCOL_OPERATION */
	#if (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION)
						{
#if ((CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_MPP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_SPLIT_MPP) || (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_WGP_Pen) || (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_MPP_Pen))
							if(RetVal == PARTIAL_FINGER2 ||
								RetVal == PARTIAL_FINGER4)
#else /* (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) */
							if(RetVal == PARTIAL_FINGER1 ||
								RetVal == PARTIAL_FINGER3)
#endif /* (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) */
							{
								p_currentRowStart = currentRowStart;
								currentRowStart = sensingRowStart;
								currentColStart = ptPenInfo->ucCurrentColumnStart;
							}
						}
	#endif /* (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) */
	#if IS_MULTI_PROTOCOL_OPERATION
						else if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WGP)
	#endif /* IS_MULTI_PROTOCOL_OPERATION */
	#if (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION)
						{
		#if IS_WGPUHDPEN_PROTOCOL_OPERATION
			#if USED_WGP_PEN_UHD_16LHB_OPERATION
							if(RetVal == PARTIAL_FINGER1 ||
								RetVal == PARTIAL_FINGER2 ||
								RetVal == PARTIAL_FINGER3 ||
								RetVal == PARTIAL_FINGER4)
			#else /* USED_WGP_PEN_UHD_16LHB_OPERATION */
							if(RetVal == PARTIAL_FINGER1 ||
								RetVal == PARTIAL_FINGER2)
			#endif /* USED_WGP_PEN_UHD_16LHB_OPERATION */
		#else /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
			#if ((CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_MPP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_SPLIT_MPP) || (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_WGP_Pen) || (CUSTOMER == MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_WGP_Pen) || (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_MPP_Pen))
							if(RetVal == PARTIAL_FINGER2)
			#else /* (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) */
							if(RetVal == PARTIAL_FINGER1)
			#endif /* (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) */
		#endif /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
							{
								p_currentRowStart = currentRowStart;
								currentRowStart = sensingRowStart;
								currentColStart = ptPenInfo->ucCurrentColumnStart;
							}
						}
	#endif  /* (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) */

						if (RetVal == LOCAL_FINGER_LAST_LHB)
						{
							hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						}
						break;
					}
	#if (IS_WGPPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION)
					case PARTIAL_TILT1:
					case PARTIAL_TILT2:
					{
						module_read_local_pentilt_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
		#ifdef TILT_ON
			#if IS_NOT_WGPUHDPEN_PROTOCOL_OPERATION
						if (ptPenInfo->bSearch_Mode_Flag == 0)
						{
							algorithm_local_dsp_process(1, RetVal, LOCAL_TILT_MODE);
						}
			#else /* IS_NOT_WGPUHDPEN_PROTOCOL_OPERATION */
				#if (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_UHD_PEN)
						if (ptPenInfo->bSearch_Mode_Flag == 0)
						{
							algorithm_local_dsp_process(1, RetVal, LOCAL_TILT_MODE);
						}
						else 
				#endif
						if (ptPenInfo->bSearch_Mode_Flag == 1)
							algorithm_baseline_tracking_continuous_local_ring();
			#endif /* IS_NOT_WGPUHDPEN_PROTOCOL_OPERATION */
		#else
						sensingRowStart_Tilt = sensingRowStart;
		#endif
		#if IS_MULTI_PROTOCOL_OPERATION
						if(eActivePenOpType == ACTIVEPEN_TYPE_LOCAL_WGP)
		#endif /* IS_MULTI_PROTOCOL_OPERATION */
		#if (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION)
						{
							p_currentRowStart = currentRowStart;
							currentRowStart = sensingRowStart;
							currentColStart = ptPenInfo->ucCurrentColumnStart;
						}
		#endif /* (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) */
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
	#if (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION)
					case PARTIAL_TILT1:
					case PARTIAL_TILT2:
					{
						module_read_local_pentilt_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						break;
					}
	#endif /* (IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) */
	#if IS_WGPUHDPEN_PROTOCOL_OPERATION
					case PARTIAL_PEN_COORD_DATA1:
					case PARTIAL_PEN_COORD_DATA2:
					case PARTIAL_PEN_COORD_DATA3:
					case PARTIAL_PEN_COORD_DATA4:
		#if USED_WGP_PEN_UHD_16LHB_OPERATION
					case PARTIAL_PEN_COORD_DATA5:
					case PARTIAL_PEN_COORD_DATA6:
					case PARTIAL_PEN_COORD_DATA7:
					case PARTIAL_PEN_COORD_DATA8:
		#endif /* USED_WGP_PEN_UHD_16LHB_OPERATION */
					{
						module_read_local_penposition_pendata_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						break;
					}
	#else /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
		#if USED_MPP_Pen_Protocol_Process_Change
					case PARTIAL_PEN_COORD_DATA1:
					case PARTIAL_PEN_COORD_DATA2:
					case PARTIAL_PEN_COORD_DATA3:
					case PARTIAL_PEN_COORD_DATA4:
					case PARTIAL_PEN_DATA1:
					case PARTIAL_PEN_DATA2:
					case PARTIAL_PEN_DATA3:
					case PARTIAL_PEN_DATA4:
					case PARTIAL_PEN_DATA5:
					{
						module_read_local_penposition_pendata_sample_data(RetVal);
						hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
						break;
					}
		#else /* USED_MPP_Pen_Protocol_Process_Change */
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
		#endif /* USED_MPP_Pen_Protocol_Process_Change */
	#endif /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
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
