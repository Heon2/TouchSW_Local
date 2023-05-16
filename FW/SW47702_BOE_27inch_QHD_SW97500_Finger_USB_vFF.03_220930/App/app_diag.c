/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_diag.c
 * created on : 03. 01. 2018
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
#if !DIAG_OFF
#include "core_def.h"
#include "param_def.h"
#include "crc.h"
#include "hal_def.h"


static tAlgorithmInfo_t * sptAlgorithmInfo  = NULL;
__IO uint32_t fw_crc_value;
#if USED_PEN_MODE_OPERATION
extern __IO uint16_t currentRowStart;
extern __IO uint16_t sensingRowStart;
extern int TEST_LOCAL_STATE;
#endif /* USED_PEN_MODE_OPERATION */
extern uint16_t* g_pFingerBaseImage;

extern void alogorithm_linefilter_2(void);

void app_diag_Init(void)
{
	sptAlgorithmInfo = algorithm_GetInfo();
}

#ifdef DEBUG
void
__error__(char *pcFilename, unsigned long ulLine)
{
}
#endif

__IO uint32_t ulFrame1Count;
__IO uint32_t ulFrame2Count;
eTouchOperMainState_t app_diag_oper_handler(void)
{
	eTouchOperMainState_t main_state;
	eDiagOperSubState_t sub_state; // NOTE : enumerated another type
	bool_t bLoop = YES;
	int i;
	uint8_t r, c;
	uint16_t deltaData;
	uint32_t ulTempData;
	int16_t sDiff = 0;
#if USED_PEN_MODE_OPERATION
	TEST_LOCAL_STATE = 0;
#endif /* USED_PEN_MODE_OPERATION */

	app_diag_Init();
	
	sub_state = TOUCH_DIAG_OPER_ENTER;
	sptAlgorithmInfo->bDiagMode = YES;
 
    while(bLoop)
    {
    	switch(sub_state)
    	{
			case TOUCH_DIAG_OPER_ENTER:
			{
				sub_state = TOUCH_DIAG_OPER_WAIT;
				break;
			}
			case TOUCH_DIAG_OPER_WAIT:
			{
				protocol_swip_PendReadyStatus();
				sub_state = TOUCH_DIAG_OPER_NORMAL;
				break;
			}
			case TOUCH_DIAG_OPER_NORMAL:
			{
				const tModuleCommonConf_t * lptModuleCommonConf = module_GetCommonConfig();
				const tAlgorithmModeConf_t * lptAlgorithmConf = algorithm_GetModeConfig();

				switch(protocol_swip_GetTestType())
				{
					case CTT_ABS:
					{
						for(r = 0; r < ROW_MAX; r++)
						{
							for(c = 0; c < COL_MAX; c++)
							{
								HAL_WRITE_ABS_IMAGE(r, c, 0);
								HAL_WRITE_COMMON_IMAGE(r, c, 0);
							}
						}

						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}

						// ABS
						ulFrame1Count = protocol_swip_GetABSAvrCount();
						if(ulFrame1Count == 0)
						{
							ulFrame1Count = 20;     // Default value
						}

						for(i=0; i<ulFrame1Count; i++)
						{
							module_wait_full_sample_done();

							alogorithm_linefilter_2();

							for(r = ROW_MAX; r--; )
							{
								for(c = COL_MAX; c--; )
								{
									ulTempData = HAL_READ_COMMON_IMAGE(r, c);
									HAL_WRITE_COMMON_IMAGE(r, c, (ulTempData + (uint32_t)HAL_READ_RAW_IMAGE(r,c)));
								}
							}
						}

						for(r = ROW_MAX; r--; )
						{
							for(c = COL_MAX; c--; )
							{
								HAL_WRITE_ABS_IMAGE(r, c, (uint16_t)(HAL_READ_COMMON_IMAGE(r, c)/ulFrame1Count));
							}
						}
						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = COL_MAX,
							.ucRow_ = ROW_MAX,
							.ucBufferCol_ = COL_MAX,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint16_t)
						};

						protocol_swip_PendTestResult(tTestDataFmt, (const void *)HAL_GET_ABS_IMAGE_PTR());

						break;
					}
#if USED_PEN_MODE_OPERATION
					case CTT_DC_ABS:
					{
//						uint16_t read_raw_data;
						uint32_t ulRowEnd = PEN_COORD_ROW_MAX;
						uint8_t BaseOffset = lptAlgorithmConf->BaseLine.ucPP_MUX_Select * PEN_COORD_ROW_MAX;

						for (r = 0; r < ROW_MAX; r++)
						{
							for (c = 0; c < COL_MAX; c++)
							{
								HAL_WRITE_DC_ABS_IMAGE(r, c, 0);
								HAL_WRITE_COMMON_IMAGE(r, c, 0);
							}
						}

						eSENSING_CHANGE_MODE_t _mode = HAL_GetSensingChangeMode();
						ePartialSensing_t RetVal = PARTIAL_PEN_BEACON;
						sensingRowStart = 0;
						HAL_SetSensingChangeMode(SM_CHAGNE_Full_To_Local_MODE);
						while (YES)
						{
							RetVal = module_wait_local_sample_done();
							if (RetVal == LOCAL_OP_LAST_LHB)
								break;
						}

						module_wait_Vsync_signal(LOCAL_MODE, lptAlgorithmConf->BaseLine.ucDiscardFrameNum);

						// module_wait_Vsync_signal(LOCAL_MODE, lptAlgorithmConf->BaseLine.ucDiscardFrameNum);
						// while (YES)
						// {
						// 	RetVal = module_wait_local_sample_done();
						// 	if(RetVal == LOCAL_OP_LAST_LHB)
						// 		break;
						// }
						// ulFrame1Count = protocol_swip_GetDCABSCount();
						// if(ulFrame1Count == 0)
						// {
							ulFrame1Count = 10;     // Default value
						// }

						for (i = 0; i < ulFrame1Count; i++)
						{
							while (YES)
							{
								RetVal = module_wait_local_sample_done();
								switch (RetVal)
								{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
									case PARTIAL_PEN_COORD_DATA1:
									case PARTIAL_PEN_COORD_DATA2:
									case PARTIAL_PEN_COORD_DATA3:
									case PARTIAL_PEN_COORD_DATA4:
									{
										currentRowStart = sensingRowStart;
										for (r = 0; r < ulRowEnd; r++)
										{
											for (c = 0; c < COL_MAX; c++)
											{
												ulTempData = HAL_READ_COMMON_IMAGE(r + currentRowStart, c);
												HAL_WRITE_COMMON_IMAGE(r + currentRowStart, c, (ulTempData + (uint32_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r + BaseOffset, c)));
											}
										}
										sensingRowStart += PEN_COORD_ROW_MAX;
										break;
									}
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
									case PARTIAL_PEN_COORD1:
									case PARTIAL_PEN_COORD2:
									case PARTIAL_PEN_COORD3:
									case PARTIAL_PEN_COORD4:
									{
										currentRowStart = sensingRowStart;
										for (r = 0; r < ulRowEnd; r++)
										{
											for (c = 0; c < COL_MAX; c++)
											{
												ulTempData = HAL_READ_COMMON_IMAGE(r + currentRowStart, c);
												HAL_WRITE_COMMON_IMAGE(r + currentRowStart, c, (ulTempData + (uint32_t)HAL_READ_LOCAL_RAW_IMAGE(r + BaseOffset, c)));
												// read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r + BaseOffset, c);
												// HAL_WRITE_DC_ABS_IMAGE(r + currentRowStart, c, read_raw_data);
											}
										}
										sensingRowStart += PEN_COORD_ROW_MAX;
										break;
									}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
									default:
										break;
								}
								
//								if (sensingRowStart > (ROW_MAX - PEN_COORD_ROW_MAX))
//								{
//									sensingRowStart = 0;
//									break;
//								}

								if(sensingRowStart >= ROW_MAX)
								{
									ulRowEnd = PEN_COORD_ROW_MAX;
									sensingRowStart = 0;
									break;
								}
								else if((ROW_MAX - sensingRowStart) < PEN_COORD_ROW_MAX)
								{
									ulRowEnd = (ROW_MAX - sensingRowStart);
								}
							}
						}

						for (r = 0; r < ROW_MAX; r++)
						{
							for (c = 0; c < COL_MAX; c++)
							{
								HAL_WRITE_DC_ABS_IMAGE(r, c, (uint16_t)(HAL_READ_COMMON_IMAGE(r, c)/ulFrame1Count));
							}
						}

						HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);	// Return Change Finger Mode

						// HAL_SetDiagTestSensingChangeMode(DIAG_CHANGE_SHORT2_TEST_GET_NORMAL);
						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = COL_MAX,
							.ucRow_ = ROW_MAX,
							.ucBufferCol_ = COL_MAX,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint16_t)
						};

						protocol_swip_PendTestResult( tTestDataFmt, (const void *)HAL_GET_DC_ABS_IMAGE_PTR());
						break;
					}
#endif /* USED_PEN_MODE_OPERATION */
					case CTT_OPEN:
					{
						for(r=0; r<ROW_MAX; r++)
						{
							for(c=0; c<COL_MAX; c++)
							{
								HAL_WRITE_OPEN_1_IMAGE(r, c, 0);
							}
						}

						HAL_SetDiagTestSensingChangeMode((eDIAG_TEST_CHANGE_MODE_t)(DIAG_CHANGE_OPEN_TEST_STEP1));

						for(i=0; i<lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}

						module_wait_full_sample_done();

						for(r=ROW_MAX; r--; )
						{
							for(c=COL_MAX; c--; )
							{
								HAL_WRITE_OPEN_1_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
							}
						}

						HAL_SetDiagTestSensingChangeMode(DIAG_CHANGE_OPEN_TEST_RECOVERY);

						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = COL_MAX,
							.ucRow_ = ROW_MAX,
							.ucBufferCol_ = COL_MAX,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint16_t)
						};

						protocol_swip_PendTestResult(tTestDataFmt, (const void *)HAL_GET_OPEN_1_IMAGE_PTR());

						break;
					}
					case CTT_SHORT_1:
					{
						uint8_t j = 0;
#if IS_ROIC_DEF_SW97500
						int16_t sDiff = 0;

						for (r = 0; r < ROW_MAX; r++)
						{
							for (c = 0; c < COL_MAX; c++)
							{
								HAL_WRITE_SHORT_IMAGE(r, c, 0);
							}
						}

						for (i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}

						module_wait_full_sample_done();

//						// STEP 1 ~ 5
//						for (j = 0; j < 5; j++)
//						{
//							HAL_SetDiagTestSensingChangeMode((eDIAG_TEST_CHANGE_MODE_t)(DIAG_CHANGE_SHORT1_TEST_STEP1 + j));
//
//							for (i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
//							{
//								module_wait_full_sample_done();
//							}
//
//							module_wait_full_sample_done();
//
//							for (r = ROW_MAX; r--;)
//							{
//								if (r % 5 == j)
//								{
//									for (c = COL_MAX; c--;)
//									{
//#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)
//										HAL_WRITE_BASELINE_2_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
//#endif
//									}
//								}
//							}
//						}

						// STEP 6 ~ 10
						for (j = 0; j < 5; j++)
						{
							HAL_SetDiagTestSensingChangeMode((eDIAG_TEST_CHANGE_MODE_t)(DIAG_CHANGE_SHORT1_TEST_STEP6 + j));

							for (i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
							{
								module_wait_full_sample_done();
							}

							module_wait_full_sample_done();

							for (r = ROW_MAX; r--;)
							{
								if (r % 5 == j)
								{
									for (c = COL_MAX; c--;)
									{
										sDiff = (int16_t)HAL_READ_RAW_IMAGE(r, c);
										HAL_WRITE_SHORT_IMAGE(r, c, (uint16_t)(4095 - sDiff));
									}
								}
							}
						}
#elif IS_ROIC_DEF_SW92513
						uint32_t ulRealRowIdx;
						for (r = 0; r < ROW_MAX; r++)
						{
							for (c = 0; c < COL_MAX; c++)
							{
								HAL_WRITE_SHORT_IMAGE(r, c, 0);
							}
						}

						for (i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}

						module_wait_full_sample_done();

						// Number of STEP is Mux Num.
						for (j = 0; j < FINGER_MUX_NUM; j++)
						{
							HAL_SetDiagTestSensingChangeMode((eDIAG_TEST_CHANGE_MODE_t)(DIAG_CHANGE_SHORT1_TEST_STEP1 + j));

							for (i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
							{
								module_wait_full_sample_done();
							}

							module_wait_full_sample_done();

							ulRealRowIdx = j * LOCAL_FINGER_1MUX_ROW_NUM;

							for (r = LOCAL_FINGER_1MUX_ROW_NUM; r--;)
							{
								for (c = COL_MAX; c--;)
								{
									if(ulRealRowIdx < ROW_MAX)
									{
										sDiff = (int16_t)HAL_READ_RAW_IMAGE((ulRealRowIdx + r), c);
										sDiff = 4095 - sDiff;
										if(sDiff < 0)
											sDiff = 0;
										HAL_WRITE_SHORT_IMAGE((ulRealRowIdx + r), c, sDiff);
									}
								}
							}
						}
#else /* IS_ROIC_DEF_SW97500 */
						for (r = 0; r < ROW_MAX; r++)
						{
							for (c = 0; c < COL_MAX; c++)
							{
								HAL_WRITE_SHORT_IMAGE(r, c, 0);
							}
						}

						for (i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}

						module_wait_full_sample_done();

						// STEP 1 ~ 5
						for (j = 0; j < 5; j++)
						{
							HAL_SetDiagTestSensingChangeMode((eDIAG_TEST_CHANGE_MODE_t)(DIAG_CHANGE_SHORT1_TEST_STEP1 + j));

							for (i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
							{
								module_wait_full_sample_done();
							}

							module_wait_full_sample_done();

							for (r = ROW_MAX; r--;)
							{
								if (r % 5 == j)
								{
									for (c = COL_MAX; c--;)
									{
										HAL_WRITE_SHORT_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
									}
								}
							}
						}
#endif /* IS_ROIC_DEF_SW97500 */

						HAL_SetDiagTestSensingChangeMode(DIAG_CHANGE_SHORT1_TEST_RECOVERY);

						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = COL_MAX,
							.ucRow_ = ROW_MAX,
							.ucBufferCol_ = COL_MAX,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint16_t)
						};
						protocol_swip_PendTestResult(tTestDataFmt, (const void *)HAL_GET_SHORT_IMAGE_PTR());
						break;
					}
					case CTT_SHORT_2:
					{
						for(r=0; r<ROW_MAX; r++)
						{
							for(c=0; c<COL_MAX; c++)
							{
								HAL_WRITE_SHORT_IMAGE(r, c, 0);
							}
						}

						for (i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}
						module_wait_full_sample_done();

#if (IS_ROIC_DEF_SW97500 || IS_ROIC_DEF_SW92509 || IS_ROIC_DEF_SW92510 || IS_ROIC_DEF_SW92508 || IS_ROIC_DEF_SW92512 || IS_ROIC_DEF_SW92511)
						HAL_SetDiagTestSensingChangeMode(DIAG_CHANGE_SHORT2_TEST_STEP1);

						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}
						module_wait_full_sample_done();

						for(r = ROW_MAX; r--;)
						{
							for(c = COL_MAX; c--;)
							{
								HAL_WRITE_SHORT_2_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
							}
						}
						HAL_SetDiagTestSensingChangeMode(DIAG_CHANGE_SHORT2_TEST_STEP2);

						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}
						module_wait_full_sample_done();

						for(r = ROW_MAX; r--;)
						{
							for(c = COL_MAX; c--;)
							{
								if(c % 2 == 0)
								{
									sDiff = (int16_t)HAL_READ_RAW_IMAGE(r, c);
									HAL_WRITE_SHORT_IMAGE(r, c, (uint16_t)sDiff);
								}
							}
						}

						HAL_SetDiagTestSensingChangeMode(DIAG_CHANGE_SHORT2_TEST_STEP3);

						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}
						module_wait_full_sample_done();

						for(r = ROW_MAX; r--;)
						{
							for(c = COL_MAX; c--;)
							{
								if(c % 2 == 1)
								{
									sDiff = (int16_t)HAL_READ_RAW_IMAGE(r, c);
									HAL_WRITE_SHORT_IMAGE(r, c, (uint16_t)sDiff);
								}
							}
						}

						for(r = ROW_MAX; r--;)
						{
							for(c = COL_MAX; c--;)
							{
								sDiff = (int16_t)HAL_READ_SHORT_2_IMAGE(r, c) - (int16_t)HAL_READ_SHORT_IMAGE(r, c);
								if(sDiff < 0)
								{
									sDiff = 0;
								}
								HAL_WRITE_SHORT_IMAGE(r, c, (uint16_t)(4095 - sDiff));
							}
						}
#elif IS_ROIC_DEF_SW92513
						HAL_SetDiagTestSensingChangeMode(DIAG_CHANGE_SHORT2_TEST_STEP1);
						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}
						module_wait_full_sample_done();

#define CH_PER_MUX		(5)

						for(r = ROW_MAX; r--;)
						{
							for(c = COL_MAX; c--;)
							{
								sDiff = (int16_t)HAL_READ_RAW_IMAGE(r, c);
								sDiff = 4095 - sDiff;
								if(sDiff < 0)
									sDiff = 0;

								if (r % 10 < CH_PER_MUX)
								{
									if (r%2 == c%2)
										HAL_WRITE_SHORT_IMAGE(r, c, (uint16_t)sDiff);
								}
								else
								{
									if (r%2 != c%2)
										HAL_WRITE_SHORT_IMAGE(r, c, (uint16_t)sDiff);
								}
							}
						}

						HAL_SetDiagTestSensingChangeMode(DIAG_CHANGE_SHORT2_TEST_STEP2);
						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}
						module_wait_full_sample_done();

						for(r = ROW_MAX; r--;)
						{
							for(c = COL_MAX; c--;)
							{
								sDiff = (int16_t)HAL_READ_RAW_IMAGE(r, c);
								sDiff = 4095 - sDiff;
								if(sDiff < 0)
									sDiff = 0;

								if (r % 10 < CH_PER_MUX)
								{
									if (r%2 != c%2)
										HAL_WRITE_SHORT_IMAGE(r, c, (uint16_t)sDiff);
								}
								else
								{
									if (r%2 == c%2)
										HAL_WRITE_SHORT_IMAGE(r, c, (uint16_t)sDiff);
								}
							}
						}
#else /* IS_ROIC_DEF_SW97500 */
	#if 1
						HAL_SetDiagTestSensingChangeMode((eDIAG_TEST_CHANGE_MODE_t)(DIAG_CHANGE_SHORT2_TEST_STEP1));

						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}
						module_wait_full_sample_done();

						for(r=ROW_MAX; r--; )
						{
							for(c=COL_MAX; c--; )
							{
								sDiff = (int16_t)HAL_READ_RAW_IMAGE(r, c);

								// SRIC 1~2
								if (c < 6)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 6)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 7)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c >= 8 && c <= 19)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								 else if (c >= 22 && c <= 27)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
  								// SRIC 3~4
								if (c >= 28 && c <= 33)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 34)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 35)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c >= 36 && c <= 47)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								 else if (c >= 50 && c <= 55)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								// SRIC 5~6
								if (c >= 56 && c <= 61)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 62)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 63)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c >= 64 && c <= 75)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								 else if (c >= 78 && c <= 83)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
							}
						}
	#endif
	#if 1
						HAL_SetDiagTestSensingChangeMode((eDIAG_TEST_CHANGE_MODE_t)(DIAG_CHANGE_SHORT2_TEST_STEP2));

						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}
						module_wait_full_sample_done();

						for(r=ROW_MAX; r--; )
						{
							for(c=COL_MAX; c--; )
							{
								sDiff = (int16_t)HAL_READ_RAW_IMAGE(r, c);
								// SRIC 1~2
								if (c < 6)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 6)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 7)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c >= 8 && c <= 19)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 20)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 21)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								 else if (c >= 22 && c <= 27)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								// SRIC 3~4
								if (c >= 28 && c <= 33)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 34)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 35)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c >= 36 && c <= 47)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 48)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 49)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								 else if (c >= 50 && c <= 55)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								// SRIC 5~6
								if (c >= 56 && c <= 61)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 62)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 63)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c >= 64 && c <= 75)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 76)
								{
									if (c % 2 == ODD) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								else if (c == 77)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
								 else if (c >= 78 && c <= 83)
								{
									if (c % 2 == EVEN) HAL_WRITE_SHORT_IMAGE(r, c, sDiff);
								}
							}
						}
	#endif

	#if 1
						HAL_SetDiagTestSensingChangeMode((eDIAG_TEST_CHANGE_MODE_t)(DIAG_CHANGE_SHORT2_TEST_STEP3));


						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}
						module_wait_full_sample_done();

						for(r=ROW_MAX; r--; )
						{
							for(c=COL_MAX; c--; )
							{
								// SRIC 1~2
								if (c == 6 || c == 20 || c == 34 || c == 48 || c == 62 || c == 76)
								{
									sDiff = (int16_t)HAL_READ_RAW_IMAGE(r, c);
									HAL_WRITE_SHORT_IMAGE(r, c, (uint16_t)sDiff);
								}
							}
						}
	#endif
	#if 1
						HAL_SetDiagTestSensingChangeMode((eDIAG_TEST_CHANGE_MODE_t)(DIAG_CHANGE_SHORT2_TEST_STEP4));


						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}
						module_wait_full_sample_done();

						for(r=ROW_MAX; r--; )
						{
							for(c=COL_MAX; c--; )
							{
								// SRIC 1~2
								if (c == 7 || c == 21 || c == 35 || c == 49 || c == 63 || c == 77)
								{
									sDiff = (int16_t)HAL_READ_RAW_IMAGE(r, c);
									HAL_WRITE_SHORT_IMAGE(r, c, (uint16_t)sDiff);
								}
							}
						}
	#endif
#endif /* IS_ROIC_DEF_SW97500 */

						HAL_SetDiagTestSensingChangeMode(DIAG_CHANGE_SHORT2_TEST_RECOVERY);

						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = COL_MAX,
							.ucRow_ = ROW_MAX,
							.ucBufferCol_ = COL_MAX,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint16_t)
						};

						protocol_swip_PendTestResult(tTestDataFmt, (const void *)HAL_GET_SHORT_IMAGE_PTR());
						break;
					}

#if 0//USED_PEN_MODE_OPERATION
					case CTT_DC_ABS_JITTER:
					{
						uint16_t *pBaseImage;
						uint16_t read_raw_data;
						int delta;
						int ulRowEnd = PEN_COORD_ROW_MAX;
						const tModuleModeConf_t * kptModuleModeConf = NULL;
						kptModuleModeConf = module_GetModeConfig();
						uint8_t BaseOffset = lptAlgorithmConf->BaseLine.ucPP_MUX_Select * PEN_COORD_ROW_MAX;
						eActivePenType_t eActivePenRawDataType = hal_Info_GetControlActivePenRawDataType();

						for (r = 0; r < ROW_MAX; r++)
						{
							for (c = 0; c < COL_MAX; c++)
							{
								HAL_WRITE_DC_ABS_JITTER_IMAGE(r, c, 0);
							}
						}

						eSENSING_CHANGE_MODE_t _mode = HAL_GetSensingChangeMode();
						ePartialSensing_t RetVal = PARTIAL_PEN_BEACON;
						sensingRowStart = 0;
						HAL_SetSensingChangeMode(SM_CHAGNE_Full_To_Local_MODE);
						while (YES)
						{
							RetVal = module_wait_local_sample_done();
							if (RetVal == LOCAL_OP_LAST_LHB)
								break;
						}

						module_wait_Vsync_signal(LOCAL_MODE, lptAlgorithmConf->BaseLine.ucDiscardFrameNum);

						// ulFrame2Count = protocol_swip_GetJitterCheckCount();

						// if(ulFrame2Count == 0)
						// {
							ulFrame2Count = 15;     // Default value
						// }

						hal_Info_SetPenTypeSwapCheckEnable(NO);
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
						algorithm_local_baseline_init();
						algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_MS);
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
						algorithm_local_baseline_init();
						algorithm_baseline_tracking_initial_local(ACTIVEPEN_TYPE_LOCAL_WGP)
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) */

						pBaseImage = g_pLocalBaseImage;

						for (i = 0; i < ulFrame2Count; i++)
						{
							while (YES)
							{
								RetVal = module_wait_local_sample_done();
								// alogorithm_local_linefilter_1(LOCAL_MODE);
								switch (RetVal)
								{
									case PARTIAL_PEN_COORD1:
									case PARTIAL_PEN_COORD2:
									case PARTIAL_PEN_COORD3:
									case PARTIAL_PEN_COORD4:
									{
										currentRowStart = sensingRowStart;
										for (r = 0; r < ulRowEnd; r++)
										{
											for (c = 0; c < COL_MAX; c++)
											{
												read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r + BaseOffset, c);
												delta = (signed)pBaseImage[((r + currentRowStart) * COL_MAX) + c] - (signed)read_raw_data;
												if (delta < 0)
												{
													delta = -delta;
												}

												delta >>= kptModuleModeConf->ucLocalOvrShift;

												if (HAL_READ_DC_ABS_JITTER_IMAGE(r + currentRowStart, c) < delta)
												{
													HAL_WRITE_DC_ABS_JITTER_IMAGE(r + currentRowStart, c, delta);
												}
											}
										}

										break;
									}
									default:
										break;
								}

								if(RetVal == PARTIAL_PEN_COORD4)
								{
									sensingRowStart += 4;
									if(sensingRowStart >= ROW_MAX)
									{
										ulRowEnd = PEN_COORD_ROW_MAX;
										sensingRowStart = 0;
									}
									else if((ROW_MAX - sensingRowStart) < PEN_COORD_ROW_MAX)
									{
										ulRowEnd = (ROW_MAX - sensingRowStart);
									}
								}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
								if(((RetVal == LOCAL_OP_LAST_LHB && OP_TYPE == ACTIVEPEN_TYPE_LOCAL_MS) || (lDataIndex == LOCAL_OP_2_LAST_LHB && OP_TYPE == ACTIVEPEN_TYPE_LOCAL_WGP)) && sensingRowStart == 0)
#else
								if((RetVal == LOCAL_OP_LAST_LHB && sensingRowStart == 0) || RetVal == PARTIAL_MAX)
#endif
								{
									break;
								}
							}
						}

						HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);	// Return Change Finger Mode

						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = COL_MAX,
							.ucRow_ = ROW_MAX,
							.ucBufferCol_ = COL_MAX,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint16_t)
						};

						protocol_swip_PendTestResult( tTestDataFmt, (const void *)HAL_GET_DC_ABS_JITTER_IMAGE_PTR());
						break;
					}
#endif /* USED_PEN_MODE_OPERATION */					
					case CTT_JITTER:
					{
						// _gT(_GPIO_TP_INTR);
//						eSENSING_MODE_t eSensingMode;
						uint16_t * pBaselineImage;
//						uint32_t * pCommonImage;

//						eSensingMode = HAL_GetSensingMode();

						const tModuleModeConf_t * kptModuleModeConf = NULL;
						kptModuleModeConf = module_GetModeConfig();

						for (r = 0; r < ROW_MAX; r++)
						{
							for (c = 0; c < COL_MAX; c++)
							{
								HAL_WRITE_COMMON_IMAGE(r, c, 0);
								HAL_WRITE_JITTER_IMAGE(r, c, INT16_MIN);
							}
						}

						pBaselineImage = g_pFingerBaseImage;//HAL_GetBaseImagePointer(eSensingMode, BASELINE_TYPE_FULL);

						memset((void *)pBaselineImage, 0x00, (uint16_t)ROW_MAX*COL_MAX);

						for (i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}

						// Jitter
						// ulFrame1Count = protocol_swip_GetJitterAvrCount();
						// if(ulFrame1Count == 0)
						// {
						ulFrame1Count = 50; // Default value
											// }

						for (i = 0; i < ulFrame1Count; i++)
						{
							module_wait_full_sample_done();

							for (r = ROW_MAX; r--;)
							{
								for (c = COL_MAX; c--;)
								{
									ulTempData = HAL_READ_COMMON_IMAGE(r, c);
									HAL_WRITE_COMMON_IMAGE(r, c, (ulTempData + (uint32_t)HAL_READ_RAW_IMAGE(r, c)));
								}
							}
						}

						for (r = ROW_MAX; r--;)
						{
							for (c = COL_MAX; c--;)
							{
								g_pFingerBaseImage[c+(r*COL_MAX)] = (uint16_t)(HAL_READ_COMMON_IMAGE(r, c) / ulFrame1Count);
//#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)
//								HAL_WRITE_BASELINE_2_IMAGE(r, c, (uint16_t)(HAL_READ_COMMON_IMAGE(r, c) / ulFrame1Count));
//#endif
							}
						}

//						pCommonImage = HAL_GET_COMMON_IMAGE_PTR();
//						for(r = 0; r < ROW_MAX * COL_MAX; r++)
//						{
//							(*pBaselineImage++) = (uint16_t)((*pCommonImage++) / ulFrame1Count);
//						}

						// ulFrame2Count = protocol_swip_GetJitterCheckCount();
						// if(ulFrame2Count == 0)
						// {
						ulFrame2Count = 50; // Default value
											// }

						for (i = 0; i < ulFrame2Count; i++)
						{
							module_wait_full_sample_done();

							alogorithm_linefilter_2();
//							alogorithm_linefilter(HAL_GetSensingMode());

							for (r = ROW_MAX; r--;)
							{
								for (c = COL_MAX; c--;)
								{
									deltaData = (uint16_t)ABS(HAL_READ_RAW_IMAGE(r, c) - g_pFingerBaseImage[c+(r*COL_MAX)]);
									deltaData >>= kptModuleModeConf->ucOvrShift;
									if (deltaData > HAL_READ_JITTER_IMAGE(r, c))
									{
										HAL_WRITE_JITTER_IMAGE(r, c, deltaData);
									}
								}
							}
						}

						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = COL_MAX,
							.ucRow_ = ROW_MAX,
							.ucBufferCol_ = COL_MAX + 2*PAD_,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint16_t)
						};

						// _gT(_GPIO_TP_INTR);
						// _gT(_GPIO_TP_INTR);
						protocol_swip_PendTestResult( tTestDataFmt, (const void *)HAL_GET_JITTER_IMAGE_PTR());
						break;
					}
					case CTT_CRC_CHECK:
					{
						fw_crc_value = 0xFFFFFFFF;//GetCRCValue((const uint16_t *)(CODE_SRAM_APP_START_BASE_ADDR), CODE_SRAM_APP_BYTE_SIZE - CODE_SRAM_APP_RESERV_BYTE_SIZE - SFLASH_CRC_CODE_BYTE_SIZE);
						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = 1,
							.ucRow_ = 1,
							.ucBufferCol_ = 1,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint32_t)
						};
						protocol_swip_PendTestResult( tTestDataFmt, (const void *)((uint32_t *)&fw_crc_value));
						break;
					}
#if (USED_MODULE_DEF == MODULE_DEF_S_1)
					case CTT_TP_INFO_WRITE:
					{
//						protocol_swip_SetTestType(CTT_NONE);
						protocol_swip_PendReadyStatus();
						protocol_swip_PendReadyStatus();

						while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 0);
						while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 1);
						while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 0);
						while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 1);
						while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 0);

						module_Stop(NO);

						FLITF_TPInspectionInfoCodeFlashWrite(protocol_swip_GetPTInspectionSetBufPrt());

						protocol_swip_PendReadyStatus();
						break;
					}
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
				} /* switch(protocol_swip_GetTestType()) */

//				module_Stop();
//				test_state = CTT_NONE; // NOTE : not used!!

				break;
			}
			case TOUCH_DIAG_OPER_EXIT:
			{
				module_Stop(NO);

				protocol_swip_PendReadyStatus();

				bLoop = NO;
				continue;
				/* no break */
			}
    	}

    	switch( protocol_swip_GetMode() )
    	{
			case M_TOUCH_NORMAL:
			{
				sub_state = TOUCH_DIAG_OPER_EXIT;
				main_state = TOUCH_MAIN_OPERATION_NORMAL;
				break;
			}
			case M_WATCH_DOG_RESET:
			{
				sub_state = TOUCH_DIAG_OPER_EXIT;
				main_state = TOUCH_MAIN_OPERATION_RESET;
				break;
			}
    	}
    }

    return main_state;
}
#endif
