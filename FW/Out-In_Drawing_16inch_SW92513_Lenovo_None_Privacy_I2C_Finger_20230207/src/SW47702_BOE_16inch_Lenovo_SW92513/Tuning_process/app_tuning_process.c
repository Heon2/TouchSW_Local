/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  app_tuning_process.c
 * created on :  16. 01. 2020
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
#include "hal_def.h"
#include "param_def.h"
#include "module_def.h"
#include "app_tuning_process.h"

#include "param_def.h"

#if USED_TOUCH_TUNING_PROCESS
extern void alogorithm_linefilter(eSENSING_MODE_t eSensingMode);

extern eActivePenType_t gAlgoRawDataType;
extern uint16_t currentRowStart;
extern uint16_t sensingRowStart;
extern int TEST_LOCAL_STATE;
const static tAlgorithmModeConf_t * thisModeConf = NULL;

tParamPreMainSet_t * s_ptParamPreMainSetTmp;

__IO tTuningProcess_Ctrl_Info_t gtTuning_Ctrl_Type =
{
	.eTuningOperMode = TUNING_CTRL_TYPE_LOCAL_MODE,

	.bSRIC_INIT = NO,
	.ulCR_OFFSET = 0,

	.ulTuning_Ctrl_Type = TUNING_CTRL_TYPE_NORMAL,

	.ulAverageCheck_Count_THD = 100,
	.ulAverageCheck_Count = 0,
	.ulAverageCheck_Complete = NO,

	.ulGIPCheck_Average_Count_THD = 200,
	.ulGIPCheck_Average_Count = 0,
	.ulGIPCheck_Start = NO,
	.ulGIPCheck_Complete = NO,
	.ulGIPCheck_AllComplete = NO,

	.ulJitterCheck_Count_THD = 1000,
	.ulJitterCheck_Count = 0,
	.bJitterCheck_Complete = NO,

	.ulLocalDeltaJitterCheck_Count_THD = 300,
	.ulLocalDeltaJitterCheck_Count = 0,
	.bLocalDeltaJitterCheck_Complete = NO,

	.ulTuning_Ctrl_PenPosViewType = TUNING_CTRL_TYPE_PEN_POS_VIEW_All,
	.ulTuning_Ctrl_PenTiltViewType = TUNING_CTRL_TYPE_PEN_TILT_VIEW_All,
	.ulTuning_Ctrl_PenDataViewType = TUNING_CTRL_TYPE_PEN_DATA_VIEW_All,
};

__IO tTuningProcess_Ctrl_RawTune_t gtuning_ctrl_RawTune_Type =
{
	.ulVSync_TouchSync_Timing_Index = 0xFFFF,
	.ulVsync_and_Touch_Timing_Continuos_CheckCount = 0,
	.ulVsync_and_Touch_Timing_Continuos_Count = 0,
};

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
/*
 * 8 LHB
 */
uint32_t gvUlGIP_VSync_TouchSync_TimingCheckIndex[4] =
{
	2,4,6,0,
};
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
/*
 * 16 LHB
 */
uint32_t gvUlGIP_VSync_TouchSync_TimingCheckIndex[8] =
{
	2,4,6,8,10,12,14,0
};
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */

eTouchOperMainState_t app_tuning_process_main_oper_handler(void)
{
	eTouchOperMainState_t main_state = TOUCH_MAIN_OPERATION_TUNING_PROCESS;
	eTuningMainOperStatus_t eTUNING_Main_OperStatus;
	eProtocolMode_t currMode, prevMode = M_TOUCH_NORMAL;
	__IO eTuningCtrlType_t ulTuning_Ctrl_Type = TUNING_CTRL_TYPE_NORMAL;
	bool_t bLoop = YES;
	eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_ENTER;
	bool_t bIsOperStart = YES;
	eTuningCtrlLocalFullModeType_t eCurrentTuningOperMode = gtTuning_Ctrl_Type.eTuningOperMode;

	s_ptParamPreMainSetTmp = (tParamPreMainSet_t *)PARAM_GetPreMainSet();

	while(bLoop)
	{
		ulTuning_Ctrl_Type = (eTuningCtrlType_t)(s_ptParamPreMainSetTmp->tParamTuningConf.DataType);

		switch(eTUNING_Main_OperStatus)
		{
			case TUNING_MAIN_OPERATION_ENTER:
			{
				TEST_LOCAL_STATE = 0;
				GPIO_Initialize();
				module_Init_Signal();
				currMode = protocol_swip_GetMode();
				if(currMode == M_TOUCH_DFUP)
				{
					break;
				}
				module_start_delay();
				eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_SYSTEM_INIT;
				break;
			}
			case TUNING_MAIN_OPERATION_SYSTEM_INIT:
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
#endif /* (USED_PEN_MODE_OPERATION) */
				}
				SensingBufferInit();
				HAL_ConfigInit(NO);
				MODULE_Initialize();
//				HAL_Initialize(NO);

				thisModeConf = algorithm_GetModeConfig();;
				eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_SRIC_INIT;
				break;
			}
			case TUNING_MAIN_OPERATION_SRIC_INIT:
			{
				module_Start();
				eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_READY;
				break;
			}
			case TUNING_MAIN_OPERATION_READY:
			{
				bIsOperStart = YES;
				if(IS_FINGER_PEN_MODE(HAL_GetSensingMode()))
				{
					eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_LOCAL_REFERENCE_INIT;
				}
				else
				{
					eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_FULL_REFERENCE_INIT;
				}
				break;
			}
			case TUNING_MAIN_OPERATION_LOCAL_REFERENCE_INIT:
			{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
				hal_Info_SetPenTypeSwapCheckEnable(NO);

				algorithm_local_baseline_init();
				if(algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_MS) == NO)
				{
					sub_state = TOUCH_NORMAL_OPER_LOCAL_READY;
				}

				HAL_SetActivePenChagneType(ACTIVEPEN_CHANGE_LOCAL_WACOM);

				if(algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WAOM) == NO)
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
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
				hal_Info_SetPenTypeSwapCheckEnable(NO);

				algorithm_local_baseline_init();
				algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_MS);

				HAL_SetActivePenChagneType(ACTIVEPEN_CHANGE_LOCAL_WGP);

				algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WGP);
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
				algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_MS);
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN)
				hal_Info_SetPenTypeSwapCheckEnable(NO);
				algorithm_local_baseline_init();
				algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WACOM);
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
				hal_Info_SetPenTypeSwapCheckEnable(NO);
				algorithm_local_baseline_init();
				algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WGP);
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
				hal_Info_SetPenTypeSwapCheckEnable(NO);
				algorithm_local_baseline_init();
				algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WGP);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) */

				eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_LOCAL_READY;
				break;
			}
			case TUNING_MAIN_OPERATION_FULL_REFERENCE_INIT:
			{
				algorithm_baseline_tracking_initial();
				eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_FULL_READY;
				break;
			}
			case TUNING_MAIN_OPERATION_LOCAL_READY:
			{
				if(HAL_GetSensingChangeMode() == SM_CHANGE_COMPLETE)
				{
					eCurrentTuningOperMode = gtTuning_Ctrl_Type.eTuningOperMode;
					eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_LOCAL_DONE;
				}
				break;
			}
			case TUNING_MAIN_OPERATION_LOCAL_DONE:
			{
				ePartialSensing_t RetVal = module_wait_local_sample_done();

				if(bIsOperStart)
				{
					bIsOperStart = NO;
					switch(ulTuning_Ctrl_Type)
					{
						case TUNING_CTRL_TYPE_NORMAL:
						case TUNING_CTRL_TYPE_NORMAL_LINEFILTER:
						{
							break;
						}
						case TUNING_CTRL_TYPE_PEN_POS_MIN_MAX_JITTER_MEASURE:
						case TUNING_CTRL_TYPE_PEN_POS_LINEFILTER_MIN_MAX_JITTER_MEASURE:
						case TUNING_CTRL_TYPE_PEN_DATA_MIN_MAX_JITTER_MEASURE:
						case TUNING_CTRL_TYPE_PEN_DATA_LINEFILTER_MIN_MAX_JITTER_MEASURE:
						{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
							memset((void*)HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
							memset((void*)HAL_GET_RING_BASELINE_IMAGE_PTR(), 0xFFFF, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
							memset((void*)HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
							memset((void*)HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_2_PTR(), 0xFFFF, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
							break;
						}
						case TUNING_CTRL_TYPE_FINGER_JITTER_MEASURE:
						case TUNING_CTRL_TYPE_FINGER_LINEFILTER_JITTER_MEASURE:
						{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
							memset((void*)HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
							memset((void*)HAL_GET_RING_BASELINE_IMAGE_PTR(), 0xFFFF, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
							memset((void*)HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
							memset((void*)HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR(), 0xFFFF, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
							break;
						}
						case TUNING_CTRL_TYPE_PEN_POS_DELTA_JITTER_MEASURE:
						case TUNING_CTRL_TYPE_PEN_POS_DELTA_LINEFILTER_JITTER_MEASURE:
						{
							s_ptParamPreMainSetTmp->tParamTuningConf.LocalIndex = 0;
							memset((void*)HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), 0x00, sizeof(int16_t)*(ROW_MAX * COL_MAX));
							break;
						}
						case TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_AVERAGE:
						{
							memset((void*)HAL_GET_COMMON_IMAGE_PTR(), 0x00, sizeof(uint32_t)*(ROW_MAX * COL_MAX));
							memset((void*)HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
							break;
						}
						case TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_GIP_NOISE_SEARCH:
						{
							memset((void*)HAL_GET_COMMON_IMAGE_PTR(), 0x00, sizeof(uint32_t)*(ROW_MAX * COL_MAX));
							memset((void*)HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
							gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_Start_IDX = gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index;
							gtTuning_Ctrl_Type.ulGIPCheck_Start = NO;
							break;
						}
						case TUNING_CTRL_TYPE_FINGER_DELTA_JITTER_MEASURE:
						case TUNING_CTRL_TYPE_FINGER_DELTA_LINEFILTER_JITTER_MEASURE:
						{
							memset((void*)HAL_GET_LOCAL_FINGER_DELTA_IMAGE_PTR(), 0x00, sizeof(int16_t)*(ROW_MAX * COL_MAX));
							break;
						}
					}

					gtTuning_Ctrl_Type.ulAverageCheck_Count = 0;
					gtTuning_Ctrl_Type.ulAverageCheck_Complete = NO;

					gtTuning_Ctrl_Type.ulGIPCheck_Average_Count = 0;
					gtTuning_Ctrl_Type.ulGIPCheck_Complete = NO;
					gtTuning_Ctrl_Type.ulGIPCheck_AllComplete = NO;

					gtTuning_Ctrl_Type.ulJitterCheck_Count = 0;
					gtTuning_Ctrl_Type.bJitterCheck_Complete = NO;

					gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count = 0;
					gtTuning_Ctrl_Type.bLocalDeltaJitterCheck_Complete = NO;

					memset((void *)&gtuning_ctrl_RawTune_Type.ulGIPNoiseRowIndex_CheckBuf[0][0], 0x00, sizeof(int32_t)*(LHB_NUM * ROW_MAX));

					break;
				}

				switch(RetVal)
				{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
					case PARTIAL_PEN_COORD_DATA1:
					case PARTIAL_PEN_COORD_DATA2:
					case PARTIAL_PEN_COORD_DATA3:
					case PARTIAL_PEN_COORD_DATA4:
					{
						int r, c;
						currentRowStart = sensingRowStart;
						switch(ulTuning_Ctrl_Type)
						{
							case TUNING_CTRL_TYPE_NORMAL:
							case TUNING_CTRL_TYPE_NORMAL_LINEFILTER:
							{
								uint16_t * pBaseImage;
								uint16_t read_raw_data;
								int delta;
								pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();

								for(r=0; r<PEN_DATA_ROW_MAX_3; r++)
								{
									for(c=0; c<COL_MAX; c++)
									{
										read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c);
										delta = (signed)pBaseImage[(((r%PEN_COORD_ROW_MAX)+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
										if(delta < 0)
										{
											delta = -delta;
										}

#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
										if(((ulZeroFingerRawMaskInfo[r+currentRowStart][c/ZERO_FINGER_RAWDATA_MASK_NUM] >> (c%ZERO_FINGER_RAWDATA_MASK_NUM)) & 0x1) == 0)
#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
										{
											HAL_WRITE_LOCAL_SEARCH_IMAGE(r, c, delta);
										}
									}
								}
								break;
							}
							case TUNING_CTRL_TYPE_PEN_POS_MIN_MAX_JITTER_MEASURE:
							case TUNING_CTRL_TYPE_PEN_POS_LINEFILTER_MIN_MAX_JITTER_MEASURE:
							{
								uint16_t read_raw_data;
								int delta;

								for(r=0; r<PEN_DATA_ROW_MAX_3; r++)
								{
									for(c=0; c<COL_MAX; c++)
									{
										read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c);
										if(HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) < read_raw_data)
										{
											HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, read_raw_data); // Max Valu
										}

										if(HAL_READ_RING_BASELINE_IMAGE(r, c) > read_raw_data)
										{
											HAL_WRITE_RING_BASELINE_IMAGE(r, c, read_raw_data); // Min value
										}

										delta = (int)HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) - (int)HAL_READ_RING_BASELINE_IMAGE(r, c);

										HAL_WRITE_LOCAL_SEARCH_IMAGE(r, c, delta);
									}
								}

								break;
							}
							case TUNING_CTRL_TYPE_PEN_POS_DELTA_JITTER_MEASURE:
							case TUNING_CTRL_TYPE_PEN_POS_DELTA_LINEFILTER_JITTER_MEASURE:
							{
								uint16_t * pBaseImage;
								uint16_t read_raw_data;
								int delta;
								uint8_t BaseOffset = thisModeConf->BaseLine.ucPP_MUX_Select * PEN_COORD_ROW_MAX;

								if((gtTuning_Ctrl_Type.bLocalDeltaJitterCheck_Complete == NO) &&
									(gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count < gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count_THD))
								{
									gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count++;
									if(gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count > 4)
									{
										pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();

										if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_PEN_POS_DELTA_LINEFILTER_JITTER_MEASURE)
										{
											alogorithm_local_linefilter_1(LOCAL_MODE);
										}

										for(r=0; r<PEN_COORD_ROW_MAX; r++)
										{
											for(c=0; c<COL_MAX; c++)
											{
												read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+BaseOffset, c);
												delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
												if(delta < 0)
												{
													delta = -delta;
												}

#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
												if(((ulZeroFingerRawMaskInfo[r+currentRowStart][c/ZERO_FINGER_RAWDATA_MASK_NUM] >> (c%ZERO_FINGER_RAWDATA_MASK_NUM)) & 0x1) == 0)
#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
												{
													if(HAL_READ_LOCAL_SEARCH_IMAGE(r+currentRowStart, c) < delta)
													{
														HAL_WRITE_LOCAL_SEARCH_IMAGE(r+currentRowStart, c, delta);
													}
												}
											}
										}
									}
									else
									{
										currentRowStart = sensingRowStart;
									}
								}
								else
								{
									if(gtTuning_Ctrl_Type.bLocalDeltaJitterCheck_Complete == NO)
									{
										s_ptParamPreMainSetTmp->tParamTuningConf.LocalIndex++;
										if(s_ptParamPreMainSetTmp->tParamTuningConf.LocalIndex > (ROW_MAX - PEN_COORD_ROW_MAX))
										{
											s_ptParamPreMainSetTmp->tParamTuningConf.LocalIndex = 0;
											gtTuning_Ctrl_Type.bLocalDeltaJitterCheck_Complete = YES;
										}
										else
										{
											gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count = 0;
										}
									}
									else
									{
										if(gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count == 0)
										{
											bIsOperStart = YES;
										}
									}
								}
								break;
							}
						}

						protocol_LogMatrix(LT_PENPOS_INTENSITY, PEN_COORD_COL_MAX, HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), COL_MAX, PEN_DATA_ROW_MAX_3, 81/*MAX Intensity*/);
						protocol_LogMatrix(LT_PENPOS_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_3_PTR(), COL_MAX, PEN_DATA_ROW_MAX_3, 84/*MAX Intensity*/);
						break;
					}
//					case PARTIAL_TILT1:
//					case PARTIAL_TILT2:
//					{
//						switch(ulTuning_Ctrl_Type)
//						{
//							case TUNING_CTRL_TYPE_NORMAL:
//							case TUNING_CTRL_TYPE_NORMAL_LINEFILTER:
//							{
//								int r, c;
//								uint16_t * pBaseImage;
//								uint16_t read_raw_data;
//								int delta;
//								pBaseImage = HAL_GET_RING_BASELINE_IMAGE_PTR();
//
//								for(r=0; r<(PEN_COORD_ROW_MAX*2); r++)
//								{
//									for(c=0; c<COL_MAX; c++)
//									{
//										read_raw_data = HAL_READ_LOCAL_RING_RAW_IMAGE(r, c);
//										delta = (signed)pBaseImage[(((r%PEN_COORD_ROW_MAX)+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
//										if(delta < 0)
//										{
//											delta = -delta;
//										}
//
//										HAL_WRITE_LOCAL_SEARCH_IMAGE(r, c, delta);
//									}
//								}
//								break;
//							}
//							case TUNING_CTRL_TYPE_TILT_JITTER_MEASURE:
//							{
//								int r, c;
//								uint16_t read_raw_data;
//								int delta;
//
//								for(r=0; r<(PEN_COORD_ROW_MAX*2); r++)
//								{
//									for(c=0; c<COL_MAX; c++)
//									{
//										read_raw_data = HAL_READ_LOCAL_RING_RAW_IMAGE(r, c);
//										if(HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) < read_raw_data)
//										{
//											HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, read_raw_data); // Max Valu
//										}
//
//										if(HAL_READ_RING_BASELINE_IMAGE(r, c) > read_raw_data)
//										{
//											HAL_WRITE_RING_BASELINE_IMAGE(r, c, read_raw_data); // Min value
//										}
//
//										delta = (int)HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) - (int)HAL_READ_RING_BASELINE_IMAGE(r, c);
//
//										HAL_WRITE_LOCAL_SEARCH_IMAGE(r, c, delta);
//									}
//								}
//
//								break;
//							}
//						}
//						protocol_LogMatrix(LT_PENDATA_INTENSITY, PEN_COORD_COL_MAX, HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), COL_MAX, (PEN_COORD_ROW_MAX*2), 81/*MAX Intensity*/);
//						protocol_LogMatrix(LT_PENDATA_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_RING_RAW_IMAGE_PTR(), COL_MAX, (PEN_COORD_ROW_MAX*2), 84/*MAX Intensity*/);
//						break;
//					}
					case LOCAL_FINGER_LAST_LHB:
					{
						int r, c;
						switch(ulTuning_Ctrl_Type)
						{
							case TUNING_CTRL_TYPE_NORMAL:
							case TUNING_CTRL_TYPE_NORMAL_LINEFILTER:
							{
								int r, c;
								uint16_t * pBaseImage;
								uint16_t read_raw_data;
								int delta;
								if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_NORMAL_LINEFILTER)
								{
									alogorithm_linefilter(HAL_GetSensingMode());
								}

								pBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR();

								for(r=0; r<ROW_MAX; r++)
								{
									for(c=0; c<COL_MAX; c++)
									{
										read_raw_data = HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c);
										delta = (signed)read_raw_data - (signed)pBaseImage[(r*COL_MAX) + c];
										HAL_WRITE_LOCAL_FINGER_DELTA_IMAGE(r, c, delta);
									}
								}
								break;
							}
							case TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_GIP_NOISE_SEARCH:
							{
								uint32_t read_raw_data;
								uint32_t col_raw_sum_data;

								if(gtTuning_Ctrl_Type.ulGIPCheck_Start == NO)
								{
									if(gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_Start_IDX !=
										gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index)
									{
										gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX = gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index;
										gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_Start_IDX = gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX;
										gtTuning_Ctrl_Type.ulGIPCheck_Start = YES;
									}
								}
								else
								{
									if(gtTuning_Ctrl_Type.ulGIPCheck_AllComplete == NO)
									{
										if(gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX ==
											gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index)
										{
											if(gtTuning_Ctrl_Type.ulGIPCheck_Complete == NO &&
												gtTuning_Ctrl_Type.ulGIPCheck_Average_Count < gtTuning_Ctrl_Type.ulGIPCheck_Average_Count_THD)
											{
												gtTuning_Ctrl_Type.ulGIPCheck_Average_Count++;
												for(r=0; r<ROW_MAX; r++)
												{
													for(c=0; c<COL_MAX; c++)
													{
														read_raw_data = (uint32_t)HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c) + HAL_READ_COMMON_IMAGE(r, c);
														HAL_WRITE_COMMON_IMAGE(r, c, read_raw_data);
													}
												}
											}
											else
											{
												if(gtTuning_Ctrl_Type.ulGIPCheck_Complete == NO)
												{
													for(r=0; r<ROW_MAX; r++)
													{
														col_raw_sum_data = 0;
														for(c=0; c<COL_MAX; c++)
														{
															read_raw_data = HAL_READ_COMMON_IMAGE(r, c) / gtTuning_Ctrl_Type.ulGIPCheck_Average_Count;
															col_raw_sum_data += (uint32_t)read_raw_data;
														}

														col_raw_sum_data /= COL_MAX;
														HAL_WRITE_LOCAL_BASELINE_IMAGE(r, gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX, (uint16_t)col_raw_sum_data);
													}
												}
												else
												{
													memset((void*)HAL_GET_COMMON_IMAGE_PTR(), 0x00, sizeof(uint32_t)*(ROW_MAX * COL_MAX));
												}
												gtTuning_Ctrl_Type.ulGIPCheck_Complete = YES;
											}
										}
										else
										{
											gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX = gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index;

											if(gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_Start_IDX ==
												gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX)
											{
												gtTuning_Ctrl_Type.ulGIPCheck_AllComplete = YES;
											}
											else
											{
												gtTuning_Ctrl_Type.ulGIPCheck_Complete = NO;
												gtTuning_Ctrl_Type.ulGIPCheck_Average_Count = 0;
											}
										}
									}
									else
									{
										if(gtTuning_Ctrl_Type.ulGIPCheck_Average_Count == 0)
										{
											bIsOperStart = YES;
										}
									}
								}

								break;
							}
							case TUNING_CTRL_TYPE_FINGER_JITTER_MEASURE:
							case TUNING_CTRL_TYPE_FINGER_LINEFILTER_JITTER_MEASURE:
							{
								uint16_t read_raw_data;
								int delta;

								if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_FINGER_LINEFILTER_JITTER_MEASURE)
								{
									alogorithm_linefilter(HAL_GetSensingMode());
								}

								for(r=0; r<ROW_MAX; r++)
								{
									for(c=0; c<COL_MAX; c++)
									{
										read_raw_data = HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c);
										if(HAL_READ_LOCAL_BASELINE_IMAGE(r, c) < read_raw_data)
										{
											HAL_WRITE_LOCAL_BASELINE_IMAGE(r, c, read_raw_data); // Max Valu
										}

										if(HAL_READ_RING_BASELINE_IMAGE(r, c) > read_raw_data)
										{
											HAL_WRITE_RING_BASELINE_IMAGE(r, c, read_raw_data); // Min value
										}

										delta = (int)HAL_READ_LOCAL_BASELINE_IMAGE(r, c) - (int)HAL_READ_RING_BASELINE_IMAGE(r, c);

										HAL_WRITE_LOCAL_FINGER_DELTA_IMAGE(r, c, delta);
									}
								}
								break;
							}
							case TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_AVERAGE:
							{
								uint32_t read_raw_data;

								if((gtTuning_Ctrl_Type.ulAverageCheck_Complete == NO) &&
									(gtTuning_Ctrl_Type.ulAverageCheck_Count < gtTuning_Ctrl_Type.ulAverageCheck_Count_THD))
								{
									gtTuning_Ctrl_Type.ulAverageCheck_Count++;
									for(r=0; r<ROW_MAX; r++)
									{
										for(c=0; c<COL_MAX; c++)
										{
											read_raw_data = (uint32_t)HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c) + HAL_READ_COMMON_IMAGE(r, c);
											HAL_WRITE_COMMON_IMAGE(r, c, read_raw_data);
										}
									}
								}
								else
								{
									if(gtTuning_Ctrl_Type.ulAverageCheck_Complete == NO)
									{
										for(r=0; r<ROW_MAX; r++)
										{
											for(c=0; c<COL_MAX; c++)
											{
												read_raw_data = HAL_READ_COMMON_IMAGE(r, c) / gtTuning_Ctrl_Type.ulAverageCheck_Count;

												HAL_WRITE_LOCAL_BASELINE_IMAGE(r, c, (uint16_t)read_raw_data);
											}
										}
									}

									gtTuning_Ctrl_Type.ulAverageCheck_Complete = YES;
									if(gtTuning_Ctrl_Type.ulAverageCheck_Count == 0)
									{
										bIsOperStart = YES;
									}
								}

								break;
							}
						}

						if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_AVERAGE ||
							ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_GIP_NOISE_SEARCH)
						{
							protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
						}
						else
						{
							protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
						}

						protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_LOCAL_FINGER_DELTA_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);

						if(eCurrentTuningOperMode != gtTuning_Ctrl_Type.eTuningOperMode)
						{
							if(gtTuning_Ctrl_Type.eTuningOperMode == TUNING_CTRL_TYPE_FULL_MODE)
							{
								HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);
								eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_FULL_READY;
							}
						}

						break;
					}
	#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
					case PARTIAL_PEN_COORD1:
					case PARTIAL_PEN_COORD2:
					case PARTIAL_PEN_COORD3:
					case PARTIAL_PEN_COORD4:
					{
						int r, c;
						currentRowStart = sensingRowStart;
						switch(ulTuning_Ctrl_Type)
						{
							case TUNING_CTRL_TYPE_NORMAL:
							case TUNING_CTRL_TYPE_NORMAL_LINEFILTER:
							{
								uint16_t * pBaseImage;
								uint16_t read_raw_data;
								int delta;
								if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
								{
									pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();

									for(r=0; r<PEN_COORD_ROW_MAX; r++)
									{
										for(c=0; c<COL_MAX; c++)
										{
#if 0 // MPP Symbol Reveser Pulse Intensity Check!!
											read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+PEN_COORD_ROW_MAX, c);
											delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
											if(delta < 0)
											{
												delta = -delta;
												HAL_WRITE_LOCAL_DELTA_IMAGE(r+PEN_COORD_ROW_MAX, c, 0);
											}
											else
											{
												HAL_WRITE_LOCAL_DELTA_IMAGE(r+PEN_COORD_ROW_MAX, c, delta);
											}
											HAL_WRITE_LOCAL_DELTA_IMAGE(r, c, delta);
#else
											read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r, c);
											delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
											if(delta < 0)
											{
												delta = -delta;
											}
											HAL_WRITE_LOCAL_DELTA_IMAGE(r, c, delta);

											read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+PEN_COORD_ROW_MAX, c);
											delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
											if(delta < 0)
											{
												delta = -delta;
											}
											HAL_WRITE_LOCAL_DELTA_IMAGE(r+PEN_COORD_ROW_MAX, c, delta);
#endif
										}
									}
								}
								else
								{
									pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR();

									for(r=0; r<PEN_COORD_ROW_MAX; r++)
									{
										for(c=0; c<COL_MAX; c++)
										{
											read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r, c);
											delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
											HAL_WRITE_LOCAL_DELTA_IMAGE(r, c, delta);

											read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+PEN_COORD_ROW_MAX, c);
											delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
											HAL_WRITE_LOCAL_DELTA_IMAGE(r+PEN_COORD_ROW_MAX, c, delta);
										}
									}
								}

								break;
							}
							case TUNING_CTRL_TYPE_PEN_POS_MIN_MAX_JITTER_MEASURE:
							case TUNING_CTRL_TYPE_PEN_POS_LINEFILTER_MIN_MAX_JITTER_MEASURE:
							{
								uint16_t read_raw_data;
								int delta;

								if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_PEN_POS_LINEFILTER_MIN_MAX_JITTER_MEASURE)
								{
									alogorithm_local_linefilter_1(LOCAL_MODE);
								}

								if((gtTuning_Ctrl_Type.bJitterCheck_Complete == NO) &&
									(gtTuning_Ctrl_Type.ulJitterCheck_Count < gtTuning_Ctrl_Type.ulJitterCheck_Count_THD))
								{
									gtTuning_Ctrl_Type.ulJitterCheck_Count++;
									for(r=0; r<PEN_COORD_ROW_MAX*2; r++)
									{
										for(c=0; c<COL_MAX; c++)
										{
											read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r, c);

											if(HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) < read_raw_data)
											{
												HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, read_raw_data); // Max Valu
											}

											if(HAL_READ_LOCAL_FINGER_BASELINE_IMAGE_2(r, c) > read_raw_data)
											{
												HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE_2(r, c, read_raw_data); // Min value
											}

											delta = (int)HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) - (int)HAL_READ_LOCAL_FINGER_BASELINE_IMAGE_2(r, c);

											HAL_WRITE_LOCAL_DELTA_IMAGE(r, c, delta);
										}
									}
								}
								else
								{
									gtTuning_Ctrl_Type.bJitterCheck_Complete = YES;
									if(gtTuning_Ctrl_Type.ulJitterCheck_Count == 0)
									{
										bIsOperStart = YES;
									}
								}

								break;
							}
							case TUNING_CTRL_TYPE_PEN_POS_DELTA_JITTER_MEASURE:
							case TUNING_CTRL_TYPE_PEN_POS_DELTA_LINEFILTER_JITTER_MEASURE:
							{
								uint16_t * pBaseImage;
								uint16_t read_raw_data;
								int delta;
								uint8_t BaseOffset = thisModeConf->BaseLine.ucPP_MUX_Select * PEN_COORD_ROW_MAX;

								if((gtTuning_Ctrl_Type.bLocalDeltaJitterCheck_Complete == NO) &&
									(gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count < gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count_THD))
								{
									gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count++;
									if(gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count > 4)
									{
										if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
										{
											pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
										}
										else
										{
											pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR();
										}

										if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_PEN_POS_DELTA_LINEFILTER_JITTER_MEASURE)
										{
											alogorithm_local_linefilter_1(LOCAL_MODE);
										}

										for(r=0; r<PEN_COORD_ROW_MAX; r++)
										{
											for(c=0; c<COL_MAX; c++)
											{
												read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+BaseOffset, c);
												delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
												if(delta < 0)
												{
													delta = -delta;
												}

												if(HAL_READ_LOCAL_SEARCH_IMAGE(r+currentRowStart, c) < delta)
												{
													HAL_WRITE_LOCAL_SEARCH_IMAGE(r+currentRowStart, c, delta);
												}
											}
										}
									}
									else
									{
										currentRowStart = sensingRowStart;
									}
								}
								else
								{
									if(gtTuning_Ctrl_Type.bLocalDeltaJitterCheck_Complete == NO)
									{
										s_ptParamPreMainSetTmp->tParamTuningConf.LocalIndex++;
										if(s_ptParamPreMainSetTmp->tParamTuningConf.LocalIndex > (ROW_MAX - PEN_COORD_ROW_MAX))
										{
											s_ptParamPreMainSetTmp->tParamTuningConf.LocalIndex = 0;
											gtTuning_Ctrl_Type.bLocalDeltaJitterCheck_Complete = YES;
										}
										else
										{
											gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count = 0;
										}
									}
									else
									{
										if(gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count == 0)
										{
											bIsOperStart = YES;
										}
									}
								}

								break;
							}
						}

						if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_PEN_POS_DELTA_JITTER_MEASURE ||
							ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_PEN_POS_DELTA_LINEFILTER_JITTER_MEASURE)
						{
							protocol_LogMatrix(LT_PENPOS_INTENSITY, PEN_COORD_COL_MAX, HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);
						}
						else
						{
							protocol_LogPaddedMatrix(LT_PENPOS_INTENSITY, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DELTA_IMAGE_PTR(), COL_MAX, (PEN_COORD_ROW_MAX*2), 81/*MAX Intensity*/);
						}

						protocol_LogMatrix(LT_PENPOS_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_RAW_IMAGE_PTR(), COL_MAX, (PEN_COORD_ROW_MAX*2), 84/*MAX Intensity*/);
						break;
					}
					case PARTIAL_PEN_DATA1:
					case PARTIAL_PEN_DATA2:
					case PARTIAL_PEN_DATA3:
					case PARTIAL_PEN_DATA4:
					case PARTIAL_PEN_DATA5:
					{
						int r, c;
						currentRowStart = sensingRowStart;
						switch(ulTuning_Ctrl_Type)
						{
							case TUNING_CTRL_TYPE_NORMAL:
							case TUNING_CTRL_TYPE_NORMAL_LINEFILTER:
							{
								uint16_t * pBaseImage;
								uint16_t read_raw_data;
								int delta;
#if 1
								if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
								{
									pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();

									for(r=0; r<PEN_COORD_ROW_MAX; r++)
									{
										for(c=0; c<COL_MAX; c++)
										{
											read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r, c);
											delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r, c, delta);

											read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+PEN_COORD_ROW_MAX, c);
											delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r+PEN_COORD_ROW_MAX, c, delta);

											read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+(PEN_COORD_ROW_MAX*2), c);
											delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r+(PEN_COORD_ROW_MAX*2), c, delta);

											read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+(PEN_COORD_ROW_MAX*3), c);
											delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r+(PEN_COORD_ROW_MAX*3), c, delta);

											read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+(PEN_COORD_ROW_MAX*4), c);
											delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r+(PEN_COORD_ROW_MAX*4), c, delta);

											read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+(PEN_COORD_ROW_MAX*5), c);
											delta = (signed)pBaseImage[((r+currentRowStart)*COL_MAX) + c] - (signed)read_raw_data;
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r+(PEN_COORD_ROW_MAX*5), c, delta);
										}
									}
								}
								else if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM)
								{

								}
								else
#endif
									if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP)
								{
									for(r=0; r<PEN_COORD_ROW_MAX; r++)
									{
										for(c=0; c<COL_MAX; c++)
										{
											delta = (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+PEN_COORD_ROW_MAX, c) - (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c);
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r, c, delta);
											delta = (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+(PEN_COORD_ROW_MAX*2), c) - (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c);
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r+PEN_COORD_ROW_MAX, c, delta);
											delta = (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+(PEN_COORD_ROW_MAX*3), c) - (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c);
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r+(PEN_COORD_ROW_MAX*2), c, delta);
											delta = (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+(PEN_COORD_ROW_MAX*4), c) - (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c);
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r+(PEN_COORD_ROW_MAX*3), c, delta);
											delta = (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+(PEN_COORD_ROW_MAX*5), c) - (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c);
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r+(PEN_COORD_ROW_MAX*4), c, delta);
											delta = (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+(PEN_COORD_ROW_MAX*6), c) - (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c);
											HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r+(PEN_COORD_ROW_MAX*5), c, delta);
										}
									}
								}

								break;
							}
							case TUNING_CTRL_TYPE_PEN_DATA_MIN_MAX_JITTER_MEASURE:
							case TUNING_CTRL_TYPE_PEN_DATA_LINEFILTER_MIN_MAX_JITTER_MEASURE:
							{
								uint16_t read_raw_data;
								int delta;

								if((gtTuning_Ctrl_Type.bJitterCheck_Complete == NO) &&
									(gtTuning_Ctrl_Type.ulJitterCheck_Count < gtTuning_Ctrl_Type.ulJitterCheck_Count_THD))
								{
									gtTuning_Ctrl_Type.ulJitterCheck_Count++;
#if 1
									if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
									{
										for(r=0; r<PEN_DATA_ROW_MAX; r++)
										{
											for(c=0; c<COL_MAX; c++)
											{
												read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r, c);
												if(HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) < read_raw_data)
												{
													HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, read_raw_data); // Max Valu
												}

												if(HAL_READ_LOCAL_FINGER_BASELINE_IMAGE_2(r, c) > read_raw_data)
												{
													HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE_2(r, c, read_raw_data); // Min value
												}

												delta = (int)HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) - (int)HAL_READ_LOCAL_FINGER_BASELINE_IMAGE_2(r, c);
												HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r, c, delta);
											}
										}
									}
									else if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM)
									{

									}
									else
#endif
										if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP)
									{
										for(r=0; r<PEN_DATA_ROW_MAX_3; r++)
										{
											for(c=0; c<COL_MAX; c++)
											{
												read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c);
												if(HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) < read_raw_data)
												{
													HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, read_raw_data); // Max Valu
												}

												if(HAL_READ_LOCAL_FINGER_BASELINE_IMAGE_2(r, c) > read_raw_data)
												{
													HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE_2(r, c, read_raw_data); // Min value
												}

												delta = (int)HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) - (int)HAL_READ_LOCAL_FINGER_BASELINE_IMAGE_2(r, c);
												HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r, c, delta);
											}
										}
									}
								}
								else
								{
									gtTuning_Ctrl_Type.bJitterCheck_Complete = YES;
									if(gtTuning_Ctrl_Type.ulJitterCheck_Count == 0)
									{
										bIsOperStart = YES;
									}
								}

								break;
							}
						}

#if 1
						if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
						{
							protocol_LogMatrix(LT_PENDATA_INTENSITY, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_DELTA_IMAGE_PTR(), COL_MAX, PEN_DATA_ROW_MAX, 81/*MAX Intensity*/);
							protocol_LogMatrix(LT_PENDATA_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_PTR(), COL_MAX, PEN_DATA_ROW_MAX, 84/*MAX Intensity*/);
						}
						else if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM)
						{
							protocol_LogMatrix_unsigned(LT_PENDATA_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_2_PTR(), COL_MAX, PEN_DATA_ROW_MAX_2, 84/*MAX Intensity*/);
						}
						else
#endif
							if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP)
						{
							if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_PEN_DATA_MIN_MAX_JITTER_MEASURE ||
								ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_PEN_DATA_LINEFILTER_MIN_MAX_JITTER_MEASURE)
							{
								protocol_LogMatrix(LT_PENDATA_INTENSITY, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_DELTA_IMAGE_PTR(), COL_MAX, (PEN_DATA_ROW_MAX_3), 81/*MAX Intensity*/);
							}
							else
							{
								protocol_LogMatrix(LT_PENDATA_INTENSITY, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_DELTA_IMAGE_PTR(), COL_MAX, (PEN_DATA_ROW_MAX_3-PEN_COORD_ROW_MAX), 81/*MAX Intensity*/);
							}
							protocol_LogMatrix(LT_PENDATA_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_3_PTR(), COL_MAX, PEN_DATA_ROW_MAX_3, 84/*MAX Intensity*/);
						}
						break;
					}
					case LOCAL_FINGER_LAST_LHB:
					{
						int r, c;
						switch(ulTuning_Ctrl_Type)
						{
							case TUNING_CTRL_TYPE_NORMAL:
							case TUNING_CTRL_TYPE_NORMAL_LINEFILTER:
							{
								uint16_t * pBaseImage;
								uint16_t read_raw_data;
								int delta;

								if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_NORMAL_LINEFILTER)
								{
									alogorithm_linefilter(HAL_GetSensingMode());
								}

								if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
								{
									pBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR();
								}
								else
								{
									pBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_2_PTR();
								}

								for(r=0; r<ROW_MAX; r++)
								{
									for(c=0; c<COL_MAX; c++)
									{
										read_raw_data = HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c);
										delta = (signed)read_raw_data - (signed)pBaseImage[(r*COL_MAX) + c];
										HAL_WRITE_LOCAL_FINGER_DELTA_IMAGE(r, c, delta);
									}
								}
								break;
							}
							case TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_GIP_NOISE_SEARCH:
							{
								uint32_t read_raw_data;
								uint32_t col_raw_sum_data;

								if(gtTuning_Ctrl_Type.ulGIPCheck_Start == NO)
								{
									if(gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_Start_IDX !=
										gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index)
									{
										gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX = gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index;
										gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_Start_IDX = gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX;
										gtTuning_Ctrl_Type.ulGIPCheck_Start = YES;
									}
								}
								else
								{
									if(gtTuning_Ctrl_Type.ulGIPCheck_AllComplete == NO)
									{
										if(gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX ==
											gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index)
										{
											if(gtTuning_Ctrl_Type.ulGIPCheck_Complete == NO &&
												gtTuning_Ctrl_Type.ulGIPCheck_Average_Count < gtTuning_Ctrl_Type.ulGIPCheck_Average_Count_THD)
											{
												gtTuning_Ctrl_Type.ulGIPCheck_Average_Count++;
												for(r=0; r<ROW_MAX; r++)
												{
													for(c=0; c<COL_MAX; c++)
													{
														read_raw_data = (uint32_t)HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c) + HAL_READ_COMMON_IMAGE(r, c);
														HAL_WRITE_COMMON_IMAGE(r, c, read_raw_data);
													}
												}
											}
											else
											{
												if(gtTuning_Ctrl_Type.ulGIPCheck_Complete == NO)
												{
													for(r=0; r<ROW_MAX; r++)
													{
														col_raw_sum_data = 0;
														for(c=0; c<COL_MAX; c++)
														{
															read_raw_data = HAL_READ_COMMON_IMAGE(r, c) / gtTuning_Ctrl_Type.ulGIPCheck_Average_Count;
															col_raw_sum_data += (uint32_t)read_raw_data;
														}

														col_raw_sum_data /= COL_MAX;
														HAL_WRITE_LOCAL_BASELINE_IMAGE(r, gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX, (uint16_t)col_raw_sum_data);
													}
												}
												else
												{
													memset((void*)HAL_GET_COMMON_IMAGE_PTR(), 0x00, sizeof(uint32_t)*(ROW_MAX * COL_MAX));
												}
												gtTuning_Ctrl_Type.ulGIPCheck_Complete = YES;
											}
										}
										else
										{
											gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX = gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index;

											if(gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_Start_IDX ==
												gtTuning_Ctrl_Type.ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX)
											{
												gtTuning_Ctrl_Type.ulGIPCheck_AllComplete = YES;
											}
											else
											{
												gtTuning_Ctrl_Type.ulGIPCheck_Complete = NO;
												gtTuning_Ctrl_Type.ulGIPCheck_Average_Count = 0;
											}
										}
									}
									else
									{
										if(gtTuning_Ctrl_Type.ulGIPCheck_Average_Count == 0)
										{
											bIsOperStart = YES;
										}
									}
								}

								break;
							}
							case TUNING_CTRL_TYPE_FINGER_JITTER_MEASURE:
							case TUNING_CTRL_TYPE_FINGER_LINEFILTER_JITTER_MEASURE:
							{
								uint16_t read_raw_data;
								int delta;

								if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_FINGER_LINEFILTER_JITTER_MEASURE)
								{
									alogorithm_linefilter(HAL_GetSensingMode());
								}

								if((gtTuning_Ctrl_Type.bJitterCheck_Complete == NO) &&
									(gtTuning_Ctrl_Type.ulJitterCheck_Count < gtTuning_Ctrl_Type.ulJitterCheck_Count_THD))
								{
									gtTuning_Ctrl_Type.ulJitterCheck_Count++;
									for(r=0; r<ROW_MAX; r++)
									{
										for(c=0; c<COL_MAX; c++)
										{
											read_raw_data = HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c);
											if(HAL_READ_LOCAL_BASELINE_IMAGE(r, c) < read_raw_data)
											{
												HAL_WRITE_LOCAL_BASELINE_IMAGE(r, c, read_raw_data); // Max Valu
											}

											if(HAL_READ_LOCAL_BASELINE_IMAGE_2(r, c) > read_raw_data)
											{
												HAL_WRITE_LOCAL_BASELINE_IMAGE_2(r, c, read_raw_data); // Min value
											}

											delta = (int)HAL_READ_LOCAL_BASELINE_IMAGE(r, c) - (int)HAL_READ_LOCAL_BASELINE_IMAGE_2(r, c);

											HAL_WRITE_LOCAL_FINGER_DELTA_IMAGE(r, c, delta);
										}
									}
								}
								else
								{
									gtTuning_Ctrl_Type.bJitterCheck_Complete = YES;
									if(gtTuning_Ctrl_Type.ulJitterCheck_Count == 0)
									{
										bIsOperStart = YES;
									}
								}

								break;
							}
							case TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_AVERAGE:
							{
								uint32_t read_raw_data;

								if((gtTuning_Ctrl_Type.ulAverageCheck_Complete == NO) &&
									(gtTuning_Ctrl_Type.ulAverageCheck_Count < gtTuning_Ctrl_Type.ulAverageCheck_Count_THD))
								{
									gtTuning_Ctrl_Type.ulAverageCheck_Count++;
									for(r=0; r<ROW_MAX; r++)
									{
										for(c=0; c<COL_MAX; c++)
										{
											read_raw_data = (uint32_t)HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c) + HAL_READ_COMMON_IMAGE(r, c);
											HAL_WRITE_COMMON_IMAGE(r, c, read_raw_data);
										}
									}
								}
								else
								{
									if(gtTuning_Ctrl_Type.ulAverageCheck_Complete == NO)
									{
										for(r=0; r<ROW_MAX; r++)
										{
											for(c=0; c<COL_MAX; c++)
											{
												read_raw_data = HAL_READ_COMMON_IMAGE(r, c) / gtTuning_Ctrl_Type.ulAverageCheck_Count;

												HAL_WRITE_LOCAL_BASELINE_IMAGE(r, c, (uint16_t)read_raw_data);
											}
										}
									}

									gtTuning_Ctrl_Type.ulAverageCheck_Complete = YES;
									if(gtTuning_Ctrl_Type.ulAverageCheck_Count == 0)
									{
										bIsOperStart = YES;
									}
								}

								break;
							}
							case TUNING_CTRL_TYPE_FINGER_DELTA_JITTER_MEASURE:
							case TUNING_CTRL_TYPE_FINGER_DELTA_LINEFILTER_JITTER_MEASURE:
							{
								uint16_t * pBaseImage;
								uint16_t read_raw_data;
								int delta;

								if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_FINGER_DELTA_LINEFILTER_JITTER_MEASURE)
								{
									alogorithm_linefilter(HAL_GetSensingMode());
								}

								if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
								{
									pBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR();
								}
								else
								{
									pBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_2_PTR();
								}


								if((gtTuning_Ctrl_Type.bJitterCheck_Complete == NO) &&
									(gtTuning_Ctrl_Type.ulJitterCheck_Count < gtTuning_Ctrl_Type.ulJitterCheck_Count_THD))
								{
									gtTuning_Ctrl_Type.ulJitterCheck_Count++;
									for(r=0; r<ROW_MAX; r++)
									{
										for(c=0; c<COL_MAX; c++)
										{
											read_raw_data = HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c);
											delta = (signed)read_raw_data - (signed)pBaseImage[(r*COL_MAX) + c];
											if(delta < 0)
											{
												delta = -delta;
											}

											if(HAL_READ_LOCAL_FINGER_DELTA_IMAGE(r, c) < delta)
											{
												HAL_WRITE_LOCAL_FINGER_DELTA_IMAGE(r, c, delta);
											}
										}
									}
								}
								else
								{
									gtTuning_Ctrl_Type.bJitterCheck_Complete = YES;
									if(gtTuning_Ctrl_Type.ulJitterCheck_Count == 0)
									{
										bIsOperStart = YES;
									}
								}

								break;
							}
						}

						if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_AVERAGE ||
							ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_GIP_NOISE_SEARCH)
						{
							protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
						}
						else
						{
							protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
						}
						protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_LOCAL_FINGER_DELTA_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);

						if(eCurrentTuningOperMode != gtTuning_Ctrl_Type.eTuningOperMode)
						{
							if(gtTuning_Ctrl_Type.eTuningOperMode == TUNING_CTRL_TYPE_FULL_MODE)
							{
								HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);
								eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_FULL_READY;
							}
						}

						break;
					}
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
					case PARTIAL_MAX:
					{
						break;
					}
				}

				//if(ulTuning_Ctrl_Type != gtTuning_Ctrl_Type.ulTuning_Ctrl_Type)
				if(ulTuning_Ctrl_Type != (eTuningCtrlType_t)(s_ptParamPreMainSetTmp->tParamTuningConf.DataType))
				{
					gtTuning_Ctrl_Type.ulTuning_Ctrl_Type = (eTuningCtrlType_t)(s_ptParamPreMainSetTmp->tParamTuningConf.DataType);
					eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_READY;
				}
				else if(ulTuning_Ctrl_Type != gtTuning_Ctrl_Type.ulTuning_Ctrl_Type)
				{
					s_ptParamPreMainSetTmp->tParamTuningConf.DataType = (uint32_t)(gtTuning_Ctrl_Type.ulTuning_Ctrl_Type);
					eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_READY;
				}

				break;
			}
			case TUNING_MAIN_OPERATION_FULL_READY:
			{
				if(HAL_GetSensingChangeMode() == SM_CHANGE_COMPLETE)
				{
					eCurrentTuningOperMode = gtTuning_Ctrl_Type.eTuningOperMode;
					eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_FULL_DONE;
				}
				break;
			}
			case TUNING_MAIN_OPERATION_FULL_DONE:
			{
				int r, c;
				module_wait_full_sample_done();
				if(bIsOperStart)
				{
					bIsOperStart = NO;
					switch(ulTuning_Ctrl_Type)
					{
						case TUNING_CTRL_TYPE_NORMAL:
						case TUNING_CTRL_TYPE_NORMAL_LINEFILTER:
						{
							break;
						}
						case TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_AVERAGE:
						{
							memset((void*)HAL_GET_COMMON_IMAGE_PTR(), 0x00, sizeof(uint32_t)*(ROW_MAX * COL_MAX));
							memset((void*)HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
							break;
						}
						case TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_GIP_NOISE_SEARCH:
						{
							break;
						}
					}

					gtTuning_Ctrl_Type.ulAverageCheck_Count = 0;
					gtTuning_Ctrl_Type.ulAverageCheck_Complete = NO;

					gtTuning_Ctrl_Type.ulJitterCheck_Count = 0;
					gtTuning_Ctrl_Type.bJitterCheck_Complete = NO;

					gtTuning_Ctrl_Type.ulLocalDeltaJitterCheck_Count = 0;
					gtTuning_Ctrl_Type.bLocalDeltaJitterCheck_Complete = NO;

					memset((void *)&gtuning_ctrl_RawTune_Type.ulGIPNoiseRowIndex_CheckBuf[0][0], 0x00, sizeof(int32_t)*(LHB_NUM * ROW_MAX));

					break;
				}

				switch(ulTuning_Ctrl_Type)
				{
					case TUNING_CTRL_TYPE_NORMAL:
					case TUNING_CTRL_TYPE_NORMAL_LINEFILTER:
					{
						uint16_t * pBaseImage;
						uint16_t read_raw_data;
						int delta;

						if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_NORMAL_LINEFILTER)
						{
							alogorithm_linefilter(HAL_GetSensingMode());
						}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
						pBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR();
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
						if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
						{
							pBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR();
						}
						else
						{
							pBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_2_PTR();
						}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */

						for(r=0; r<ROW_MAX; r++)
						{
							for(c=0; c<COL_MAX; c++)
							{
								read_raw_data = HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c);
								delta = (signed)read_raw_data - (signed)pBaseImage[(r*COL_MAX) + c];
								HAL_WRITE_LOCAL_FINGER_DELTA_IMAGE(r, c, delta);
							}
						}
						break;
					}
					case TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_AVERAGE:
					{
						break;
					}
					case TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_GIP_NOISE_SEARCH:
					{
						break;
					}
				}

				if(ulTuning_Ctrl_Type == TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_AVERAGE)
				{
					protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
				}
				else
				{
					protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);
				}
				protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_LOCAL_FINGER_DELTA_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*MAX Intensity*/);

				if(eCurrentTuningOperMode != gtTuning_Ctrl_Type.eTuningOperMode)
				{
					if(gtTuning_Ctrl_Type.eTuningOperMode == TUNING_CTRL_TYPE_LOCAL_MODE)
					{
						HAL_SetSensingChangeMode(SM_CHAGNE_Full_To_Local_MODE);
						eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_LOCAL_READY;
					}
				}

				//if(ulTuning_Ctrl_Type != gtTuning_Ctrl_Type.ulTuning_Ctrl_Type)
				if(ulTuning_Ctrl_Type != (eTuningCtrlType_t)(s_ptParamPreMainSetTmp->tParamTuningConf.DataType))
				{
					gtTuning_Ctrl_Type.ulTuning_Ctrl_Type = (eTuningCtrlType_t)(s_ptParamPreMainSetTmp->tParamTuningConf.DataType);
					eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_READY;
				}
				else if(ulTuning_Ctrl_Type != gtTuning_Ctrl_Type.ulTuning_Ctrl_Type)
				{
					s_ptParamPreMainSetTmp->tParamTuningConf.DataType = (uint32_t)(gtTuning_Ctrl_Type.ulTuning_Ctrl_Type);
					eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_READY;
				}

				break;
			}
			case TUNING_MAIN_OPERATION_EXIT:
			{
				bLoop = NO;
				continue;
				/* no break */
			}
			default:
				break;
		}
		sensingRowStart = (uint16_t)(s_ptParamPreMainSetTmp->tParamTuningConf.LocalIndex);

		{
			__IO bool_t bISSRICInIt = gtTuning_Ctrl_Type.bSRIC_INIT;

			if(bISSRICInIt)
			{
				currMode = M_PARAMETER;
			}
			else
			{
				currMode = protocol_swip_GetMode();
			}

			if(currMode != prevMode)
			{
				switch( currMode )
				{
					case M_TOUCH_NORMAL:
					{
						protocol_swip_PendReadyStatus();
						break;
					}
					case M_PARAMETER:
					{
#ifdef MODE_WDT
						LONG_KICK_DOG();
#endif /* MODE_WDT */
						module_Stop(NO);

						eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_SYSTEM_INIT;
						break;
					}
					case M_TOUCH_DFUP:
					{
#ifdef MODE_WDT
						LONG_KICK_DOG();
#endif /* MODE_WDT */
						module_Stop(NO);
						eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_EXIT;
						break;
					}
					case M_WATCH_DOG_RESET:
					{
						eTUNING_Main_OperStatus = TUNING_MAIN_OPERATION_EXIT;
						main_state = TOUCH_MAIN_OPERATION_RESET;
						break;
					}
				}
			}

			if(bISSRICInIt)
			{
				gtTuning_Ctrl_Type.bSRIC_INIT = NO;
			}
			else
			{
				prevMode = currMode;
			}
		}

	}

	return main_state;
}
#endif /* USED_TOUCH_TUNING_PROCESS */
