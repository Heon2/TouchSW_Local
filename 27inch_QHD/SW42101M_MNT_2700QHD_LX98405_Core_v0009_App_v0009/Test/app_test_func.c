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
#define JITTER_TEST_START_COUNT_							(10)
#define JITTER_TEST_NUM_									(1000)
#define TEST_BASELINE_INIT_FRAME_NUM						(10)
#define TEST_RAWDATA_AVR_VIEW_FRAME_NUM						(30)
#define TEST_NOISE_MEASURE_BASELINE_INIT_FRAME_NUM			(300)
#define TEST_NOISE_MEASURE_SIGNALnNOISE_CAL_FRAME_NUM		(300)


#define APP_TEST_OVERSHIFT_LEVEL	(2)
extern int16_t sLFOffsetRow[ROW_MAX];
static void app_test_operation_Function_LineFilter(void)
{
	uint32_t r, c;
#if (USED_MODULE_DEF == MODULE_DEF_S_1)
#define LINE_FILTER_UPPER_LIMIT		((16)<<APP_TEST_OVERSHIFT_LEVEL)
#define LINE_FILTER_LOWER_LIMIT		(-((16)<<APP_TEST_OVERSHIFT_LEVEL))
#define LINE_FILTER_BIG_UPPER_LIMIT		((45)<<APP_TEST_OVERSHIFT_LEVEL)
#define LINE_FILTER_BIG_LOWER_LIMIT		(-((45)<<APP_TEST_OVERSHIFT_LEVEL))
#elif (USED_MODULE_DEF == MODULE_DEF_B_1)
#define LINE_FILTER_UPPER_LIMIT		((30)<<APP_TEST_OVERSHIFT_LEVEL)
#define LINE_FILTER_LOWER_LIMIT		(-((30)<<APP_TEST_OVERSHIFT_LEVEL))
//	uint32_t uvldo_row[] = {15, 27};
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	int16_t lDiff;
	int16_t lDiffSum = 0;
	uint32_t lDiffSumCnt = 0;
	int32_t lLowTHD, lUpperTHD;

	for(r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++)
	{
		lDiffSumCnt = 0;
		lDiffSum = 0;
		lUpperTHD = LINE_FILTER_UPPER_LIMIT;
		lLowTHD = LINE_FILTER_LOWER_LIMIT;

		for(c = 0; c < tTestOperParam.thisInfo->ucScreenCol; c+=2)
		{
			lDiff = (int16_t)(HAL_READ_RAW_IMAGE(r, c) - HAL_READ_BASELINE_IMAGE(r, c));
			if(lDiff < lUpperTHD && lDiff > lLowTHD)
			{
				lDiffSum += lDiff;
				lDiffSumCnt++;
			}
		}

		if(lDiffSumCnt > 3)
		{
			sLFOffsetRow[r] = lDiffSum / ((int16_t)lDiffSumCnt);

			for(c = 0; c < tTestOperParam.thisInfo->ucScreenCol; c++)
			{
				lDiff = (((int16_t)HAL_READ_RAW_IMAGE(r, c)) - sLFOffsetRow[r]);
				HAL_WRITE_RAW_IMAGE(r, c, (uint16_t)lDiff);
			}
		}
	}
}

static void app_test_operation_Function_BaseLineInit(void)
{
	int i;
	int r, c;
	uint32_t temp_data, raw_val;
	__IO uint32_t ulBaselineInitFrameNum;
	ulBaselineInitFrameNum = tTestOperParam.ulBaseLineInitFrameNum;

	 // TODO : memset�� ������.. ���� 0���� �ʱ�ȭ ��Ű�°� ������ Check����!!
	for(r = tTestOperParam.thisInfo->ucRow; r--; )
	{
		for(c = tTestOperParam.thisInfo->ucCol; c--; )
		{
			HAL_WRITE_COMMON_IMAGE(r, c, 0x000);
		}
	}

	for(i = ulBaselineInitFrameNum; i--; )
	{
		module_wait_full_sample_done();

		for(r = tTestOperParam.thisInfo->ucRow; r--; )
		{
			for(c = tTestOperParam.thisInfo->ucCol; c--; )
			{
				raw_val = (uint32_t)HAL_READ_RAW_IMAGE(r, c);
				temp_data = HAL_READ_COMMON_IMAGE(r, c) + raw_val;
				HAL_WRITE_COMMON_IMAGE(r, c, temp_data);
			}
		}
	}


	for(r=tTestOperParam.thisInfo->ucScreenRow; r--; )
	{
		for(c=tTestOperParam.thisInfo->ucScreenCol; c--; )
		{
			temp_data = HAL_READ_COMMON_IMAGE(r, c);
			temp_data /= ulBaselineInitFrameNum;
			HAL_WRITE_BASELINE_IMAGE(r, c, (uint16_t)temp_data);
			HAL_WRITE_COMMON_IMAGE(r, c, 0);
		}
	}
}

void app_test_operation_Function_Init(void)
{
	tTestOperParam.ulJitterTestNum = JITTER_TEST_NUM_;
	tTestOperParam.bIsLinefilter = NO;
	tTestOperParam.ulRawDataViewAvrFrameNum = TEST_RAWDATA_AVR_VIEW_FRAME_NUM;
	tTestOperParam.ulBaseLineInitFrameNum = TEST_BASELINE_INIT_FRAME_NUM;
	tTestOperParam.ulSignalnNoiseMeasureBaselineFrameNum = TEST_NOISE_MEASURE_BASELINE_INIT_FRAME_NUM;
	tTestOperParam.ulSignalnNoiseMeasureSignalnNoiseFrameNum = TEST_NOISE_MEASURE_SIGNALnNOISE_CAL_FRAME_NUM;

	tTestOperParam.ptAppInfo->eSelectFreq = FREQ_MAIN;
	tTestOperParam.bIsBaseJitter_Positive_view = YES;
}

void app_test_operation_jitter(void)
{
	uint32_t r, c;
	uint16_t ulRawData;
	int16_t sJitter;
	uint32_t ulJitterTestCount;
	__IO bool_t bIsLineFilter;
	__IO uint32_t ulJitterTestNum;
	__IO eTestSubOpStatus_t eTestSubOperStatus;

	ulJitterTestCount = 0;
	ulJitterTestNum = tTestOperParam.ulJitterTestNum;
	bIsLineFilter = tTestOperParam.bIsLinefilter;
	eTestSubOperStatus = tTestOperParam.elTestSub_Status;

	if(bIsLineFilter)
	{
		app_test_operation_Function_BaseLineInit();
	}

	tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_START;
	while(ulJitterTestCount < JITTER_TEST_START_COUNT_ + ulJitterTestNum + 10)
	{
		if(module_wait_full_sample_done())
		{
			memset(sLFOffsetRow, 0, sizeof(sLFOffsetRow));
			if(bIsLineFilter)
			{
				app_test_operation_Function_LineFilter();
			}

			ulJitterTestCount++;

			if(ulJitterTestCount == 1)
			{
				for(r=0; r<ROW_MAX; r++)
				{
					for(c=0; c<COL_MAX; c++)
					{
						HAL_WRITE_COMMON_IMAGE(r, c, 0);
						HAL_WRITE_HOPP_BASELINE_IMAGE(r, c, 4095);
						HAL_WRITE_DELTA_IMAGE(r, c, 0);
					}
				}
			}
			else
			{
				if(ulJitterTestCount > JITTER_TEST_START_COUNT_)
				{
					if(ulJitterTestCount < JITTER_TEST_START_COUNT_ + ulJitterTestNum)
					{
						for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
						{
							for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
							{
								ulRawData = HAL_READ_RAW_IMAGE(r, c);
								if(HAL_READ_COMMON_IMAGE(r, c) < ulRawData)
								{
									HAL_WRITE_COMMON_IMAGE(r, c, ulRawData);
								}

								if(HAL_READ_HOPP_BASELINE_IMAGE(r, c) > ulRawData)
								{
									HAL_WRITE_HOPP_BASELINE_IMAGE(r, c, ulRawData);
								}
							}
						}
					}
					else if(ulJitterTestCount == JITTER_TEST_START_COUNT_ + ulJitterTestNum)
					{
						for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
						{
							for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
							{
								sJitter = (int16_t)(((uint16_t)HAL_READ_COMMON_IMAGE(r, c)) - HAL_READ_HOPP_BASELINE_IMAGE(r, c));
								HAL_WRITE_DELTA_IMAGE(r, c, sJitter);
							}
						}
					}
				}
			}
		}
	}

	tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_FINISH;
	while(eTestSubOperStatus == TEST_SUB_OPER_JITTER_CALC)
	{
		eTestSubOperStatus = tTestOperParam.elTestSub_Status;
		if(module_wait_full_sample_done())
		{
			protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
			protocol_LogPaddedMatrix(LT_INTENSITY, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 82/*MAX Intensity*/);
		}
	}
}

void app_test_operation_base_jitter(void)
{
	uint32_t r, c;
	uint16_t ulRawData;
	int16_t sJitter;
	uint32_t ulJitterTestCount;
	__IO bool_t bIsLineFilter;
	__IO uint32_t ulJitterTestNum;
	__IO eTestSubOpStatus_t eTestSubOperStatus;

	ulJitterTestCount = 0;
	ulJitterTestNum = tTestOperParam.ulJitterTestNum;
	bIsLineFilter = tTestOperParam.bIsLinefilter;
	eTestSubOperStatus = tTestOperParam.elTestSub_Status;

	app_test_operation_Function_BaseLineInit();

	tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_START;
	while(ulJitterTestCount < JITTER_TEST_START_COUNT_ + ulJitterTestNum + 10)
	{
		if(module_wait_full_sample_done())
		{
			memset(sLFOffsetRow, 0, sizeof(sLFOffsetRow));
			if(bIsLineFilter)
			{
				app_test_operation_Function_LineFilter();
			}

			ulJitterTestCount++;

			if(ulJitterTestCount == 1)
			{
				for(r=0; r<ROW_MAX; r++)
				{
					for(c=0; c<COL_MAX; c++)
					{
						HAL_WRITE_COMMON_IMAGE(r, c, 0);
						HAL_WRITE_HOPP_BASELINE_IMAGE(r, c, 0);
						HAL_WRITE_DELTA_IMAGE(r, c, 0);
					}
				}
			}
			else
			{
				if(ulJitterTestCount > JITTER_TEST_START_COUNT_)
				{
					if(ulJitterTestCount < JITTER_TEST_START_COUNT_ + ulJitterTestNum)
					{
						for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
						{
							for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
							{
								ulRawData = HAL_READ_RAW_IMAGE(r, c);
								sJitter = (int16_t)ulRawData - (int16_t)HAL_READ_BASELINE_IMAGE(r, c);

								if(sJitter > 0)
								{
									if(HAL_READ_HOPP_BASELINE_IMAGE(r, c) < (uint16_t)sJitter)
									{
										HAL_WRITE_HOPP_BASELINE_IMAGE(r, c, (uint16_t)sJitter);
									}
								}
								else
								{
									sJitter = ABS(sJitter);
									if(HAL_READ_DELTA_IMAGE(r, c) < sJitter)
									{
										HAL_WRITE_DELTA_IMAGE(r, c, sJitter);
									}
								}
							}
						}
					}
					else if(ulJitterTestCount == JITTER_TEST_START_COUNT_ + ulJitterTestNum)
					{
						for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
						{
							for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
							{
								ulRawData = (uint16_t)((int16_t)HAL_READ_HOPP_BASELINE_IMAGE(r, c) + HAL_READ_DELTA_IMAGE(r, c));
								HAL_WRITE_COMMON_IMAGE(r, c, ulRawData);
							}
						}
					}
				}
			}
		}
	}

	tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_FINISH;
	while(eTestSubOperStatus == TEST_SUB_OPER_BASE_JITTER_CALC)
	{
		eTestSubOperStatus = tTestOperParam.elTestSub_Status;
		if(module_wait_full_sample_done())
		{
			for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
			{
				for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
				{
					ulRawData = (uint16_t)HAL_READ_COMMON_IMAGE(r, c);
					HAL_WRITE_RAW_IMAGE(r, c, ulRawData);
				}
			}

			protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
			if(tTestOperParam.bIsBaseJitter_Positive_view)
			{
				protocol_LogMatrix(LT_INTENSITY, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_HOPP_BASELINE_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 82/*MAX Intensity*/);
			}
			else
			{
				protocol_LogPaddedMatrix(LT_INTENSITY, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 82/*MAX Intensity*/);
			}
		}
	}
}

#define TEST_SIGNAL_NOISE_SAVE_NUM		(18)

tSignalNoiseSaveBuf tSignalNoiseBuf[TEST_SIGNAL_NOISE_SAVE_NUM];

void app_test_operation_SignalnNoise_Measure(void)
{
	__IO bool_t bIsLineFilter;
	__IO uint32_t ulSignalnNoiseMeasureTestNum;
	__IO eTestSubOpStatus_t eTestSubOperStatus;
	__IO uint32_t ulBaselineInitFrameNum_Backup;
	__IO eSignalnNoiseMesureStatus_t eSnNMeasureStatus;
	__IO uint32_t ulMeasureIndex;
	uint32_t r, c;
	uint32_t ulRawData;
	int16_t sSignal, sNoise;
	uint32_t ulNoiseSum;
	uint32_t ulCount;
	uint32_t ulMaxPoint_r, ulMaxPoint_c;
	int32_t ulMaxSignal;

	bIsLineFilter = tTestOperParam.bIsLinefilter;
	eTestSubOperStatus = tTestOperParam.elTestSub_Status;

	ulSignalnNoiseMeasureTestNum = tTestOperParam.ulSignalnNoiseMeasureSignalnNoiseFrameNum;
	ulBaselineInitFrameNum_Backup = tTestOperParam.ulBaseLineInitFrameNum;
	tTestOperParam.ulBaseLineInitFrameNum = tTestOperParam.ulSignalnNoiseMeasureBaselineFrameNum;
	eSnNMeasureStatus = TEST_SnN_STATUS_MEASURE_START;
	tTestOperParam.eSnNMeasure_Status = TEST_SnN_STATUS_MEASURE_START;

	memset((void *)&tSignalNoiseBuf[0], 0, sizeof(tSignalNoiseSaveBuf)*TEST_SIGNAL_NOISE_SAVE_NUM);
	tTestOperParam.ulSignalnNoiseMeasureIndex = 0;

	while(eTestSubOperStatus == TEST_SUB_OPER_SIGNALnNOISE_MEASURE)
	{
		switch(eSnNMeasureStatus)
		{
			case TEST_SnN_STATUS_MEASURE_START:
			{
				app_test_operation_Function_BaseLineInit();
				eSnNMeasureStatus = TEST_SnN_STATUS_CHANGE_READY;
				tTestOperParam.eSnNMeasure_Status = TEST_SnN_STATUS_CHANGE_READY;

				for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
				{
					for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
					{
						HAL_WRITE_DELTA_IMAGE(r, c, 0);
						HAL_WRITE_HOPP_BASELINE_IMAGE(r, c, 0);
						HAL_WRITE_COMMON_IMAGE(r, c, 0);
					}
				}
				break;
			}
			case TEST_SnN_STATUS_CHANGE_READY:
			{
				while(eSnNMeasureStatus == TEST_SnN_STATUS_CHANGE_READY)
				{
					eSnNMeasureStatus = tTestOperParam.eSnNMeasure_Status;
					ulMeasureIndex = tTestOperParam.ulSignalnNoiseMeasureIndex;
					module_wait_full_sample_done();
//					protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
					protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_BASELINE_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
					protocol_LogPaddedMatrix(LT_INTENSITY, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 82/*MAX Intensity*/);
				}
				break;
			}
			case TEST_SnN_STATUS_ONLY_SIGNAL_MEASURE:
			case TEST_SnN_STATUS_SIGNAL_MEASURE:
			{
				ulCount = 0;
				while(eSnNMeasureStatus == TEST_SnN_STATUS_SIGNAL_MEASURE || eSnNMeasureStatus == TEST_SnN_STATUS_ONLY_SIGNAL_MEASURE)
				{
					if(module_wait_full_sample_done())
					{
						if(ulCount < ulSignalnNoiseMeasureTestNum)
						{
							ulCount++;

							if(bIsLineFilter)
							{
								app_test_operation_Function_LineFilter();
							}

							for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
							{
								for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
								{
									ulRawData = (uint32_t)HAL_READ_RAW_IMAGE(r, c);
									ulRawData = ulRawData + HAL_READ_COMMON_IMAGE(r, c);
									HAL_WRITE_COMMON_IMAGE(r, c, ulRawData);
								}
							}

							if(ulCount == ulSignalnNoiseMeasureTestNum)
							{
								ulMaxSignal = 0;
								tSignalNoiseBuf[ulMeasureIndex].ulStrength = 0;
								tSignalNoiseBuf[ulMeasureIndex].ulIndex_r = 0;
								tSignalNoiseBuf[ulMeasureIndex].ulIndex_c = 0;

								for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
								{
									for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
									{
										ulRawData = HAL_READ_COMMON_IMAGE(r, c) / ulSignalnNoiseMeasureTestNum;
										sSignal = (int16_t)ulRawData - (int16_t)HAL_READ_BASELINE_IMAGE(r, c);
										if(ulMaxSignal < sSignal)
										{
											ulMaxSignal = sSignal;
											ulMaxPoint_r = r;
											ulMaxPoint_c = c;
										}
										HAL_WRITE_COMMON_IMAGE(r, c, 0);
										HAL_WRITE_DELTA_IMAGE(r, c, sSignal);
									}
								}

								tSignalNoiseBuf[ulMeasureIndex].ulStrength = (uint16_t)ulMaxSignal;
								tSignalNoiseBuf[ulMeasureIndex].ulIndex_r = (uint16_t)ulMaxPoint_r;
								tSignalNoiseBuf[ulMeasureIndex].ulIndex_c = (uint16_t)ulMaxPoint_c;
							}
						}
						else
						{
							if(eSnNMeasureStatus == TEST_SnN_STATUS_ONLY_SIGNAL_MEASURE)
							{
								eSnNMeasureStatus = tTestOperParam.eSnNMeasure_Status;
								protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
	//							protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_BASELINE_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
								protocol_LogPaddedMatrix(LT_INTENSITY, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 82/*MAX Intensity*/);
							}
							else
							{
								eSnNMeasureStatus = TEST_SnN_STATUS_NOISE_MEASURE;
								tTestOperParam.eSnNMeasure_Status = TEST_SnN_STATUS_NOISE_MEASURE;
							}
						}
					}
				}
				break;
			}
			case TEST_SnN_STATUS_NOISE_MEASURE:
			{
				ulCount = 0;
				app_test_operation_Function_BaseLineInit();

				while(eSnNMeasureStatus == TEST_SnN_STATUS_NOISE_MEASURE)
				{
					if(module_wait_full_sample_done())
					{
						ulCount++;

						if(bIsLineFilter)
						{
							app_test_operation_Function_LineFilter();
						}

						for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
						{
							for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
							{
								ulRawData = (uint32_t)HAL_READ_RAW_IMAGE(r, c);
								sNoise = (int16_t)ulRawData - (int16_t)HAL_READ_BASELINE_IMAGE(r, c);

								ulNoiseSum = (uint32_t)(sNoise * sNoise) + HAL_READ_COMMON_IMAGE(r, c);
								HAL_WRITE_COMMON_IMAGE(r, c, ulNoiseSum);
							}
						}

						if(ulCount >= ulSignalnNoiseMeasureTestNum)
						{
							eSnNMeasureStatus = TEST_SnN_STATUS_MEASURE_DONE;
							tTestOperParam.eSnNMeasure_Status = TEST_SnN_STATUS_MEASURE_DONE;

							for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
							{
								for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
								{
									ulNoiseSum = HAL_READ_COMMON_IMAGE(r, c);
									ulNoiseSum /= ulSignalnNoiseMeasureTestNum;
									HAL_WRITE_COMMON_IMAGE(r, c, ulNoiseSum);
								}
							}

							if(ulNoiseSum > UINT16_MAX)
							{
								ulNoiseSum = UINT16_MAX;
							}
							tSignalNoiseBuf[ulMeasureIndex].ulNoise = (uint16_t)HAL_READ_COMMON_IMAGE(tSignalNoiseBuf[ulMeasureIndex].ulIndex_r, tSignalNoiseBuf[ulMeasureIndex].ulIndex_c);
						}
					}
				}
				break;
			}
			case TEST_SnN_STATUS_MEASURE_DONE:
			{
				while(eSnNMeasureStatus == TEST_SnN_STATUS_MEASURE_DONE)
				{
					eSnNMeasureStatus = tTestOperParam.eSnNMeasure_Status;
					if(module_wait_full_sample_done())
					{
						protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
					}
				}
				break;
			}
			case TEST_SnN_STATUS_MEASURE_EXIT:
			{
				eTestSubOperStatus = tTestOperParam.elTestSub_Status;
				break;
			}
		}
	}

	tTestOperParam.ulBaseLineInitFrameNum = ulBaselineInitFrameNum_Backup;
}

void app_test_operation_NFrame_Average_RawDataView(void)
{
	uint32_t r, c;
	uint32_t ulRawData;
	__IO uint32_t ulAvrFrameNum, ulAvrFrameCount;
	__IO bool_t bIsLineFilter;
	__IO eTestSubOpStatus_t eTestSubOperStatus;

	ulAvrFrameNum = tTestOperParam.ulRawDataViewAvrFrameNum;
	eTestSubOperStatus = tTestOperParam.elTestSub_Status;

	for(r=0; r<ROW_MAX; r++)
	{
		for(c=0; c<COL_MAX; c++)
		{
			HAL_WRITE_COMMON_IMAGE(r, c, 0);
		}
	}

	tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_FINISH;
	while(eTestSubOperStatus == TEST_SUB_OPER_N_FRAME_AVR_RAWDATA_VIEW)
	{
		eTestSubOperStatus = tTestOperParam.elTestSub_Status;
		if(module_wait_full_sample_done())
		{
			ulAvrFrameCount++;
			if(ulAvrFrameCount < ulAvrFrameNum)
			{
				for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
				{
					for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
					{
						ulRawData = ((uint32_t)HAL_READ_RAW_IMAGE(r, c)) + HAL_READ_COMMON_IMAGE(r, c);
						HAL_WRITE_COMMON_IMAGE(r, c, ulRawData);
					}
				}
			}
			else
			{
				ulAvrFrameCount = 0;
				for( r=0; r<tTestOperParam.thisInfo->ucScreenRow; r++ )
				{
					for( c=0; c<tTestOperParam.thisInfo->ucScreenCol; c++ )
					{
						ulRawData = ((uint32_t)HAL_READ_RAW_IMAGE(r, c)) + HAL_READ_COMMON_IMAGE(r, c);

						ulRawData = ulRawData / ulAvrFrameNum;
						HAL_WRITE_RAW_IMAGE(r, c, (uint16_t)ulRawData);
						HAL_WRITE_COMMON_IMAGE(r, c, 0);
					}
				}
				protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
			}
		}
	}
}

void app_test_operation_IntensityView(void)
{
	__IO eTestSubOpStatus_t eTestSubOperStatus;
	__IO bool_t bIsLineFilter;
	bIsLineFilter = tTestOperParam.bIsLinefilter;

	eTestSubOperStatus = tTestOperParam.elTestSub_Status;
	app_test_operation_Function_BaseLineInit();

	while(eTestSubOperStatus == TEST_SUB_OPER_INTENSITY_VIEW)
	{
		eTestSubOperStatus = tTestOperParam.elTestSub_Status;
		if(module_wait_full_sample_done())
		{
			memset(sLFOffsetRow, 0, sizeof(sLFOffsetRow));
			if(bIsLineFilter)
			{
				app_test_operation_Function_LineFilter();
			}
			protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
//			protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_BASELINE_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
			algorithm_baseline_calculate_delta(FULL_MODE);
			protocol_LogPaddedMatrix(LT_INTENSITY, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 81/*MAX Intensity*/);
		}
	}
}

void app_test_operation_TSYNC_OUT_Generation(void)
{
	__IO eTestSubOpStatus_t eTestSubOperStatus;
	__IO bool_t bIsLineFilter;
	bIsLineFilter = tTestOperParam.bIsLinefilter;

	eTestSubOperStatus = tTestOperParam.elTestSub_Status;
	app_test_pwm_TSync_out_Generation_Init();

	app_test_operation_Function_BaseLineInit();

	while(eTestSubOperStatus == TEST_SUB_OPER_TSYNC_OUT_GENERATION)
	{
		eTestSubOperStatus = tTestOperParam.elTestSub_Status;
		if(module_wait_full_sample_done())
		{
			memset(sLFOffsetRow, 0, sizeof(sLFOffsetRow));
			if(bIsLineFilter)
			{
				app_test_operation_Function_LineFilter();
			}
			protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
//			protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_BASELINE_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
			algorithm_baseline_calculate_delta(FULL_MODE);
			protocol_LogPaddedMatrix(LT_INTENSITY, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 81/*MAX Intensity*/);
		}
	}

	app_test_pwm_TSync_out_Generation_DeInit();

}
#endif /* USED_TEST_OPERATION_ENABLE */
