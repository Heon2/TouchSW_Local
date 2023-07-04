/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  app_test_main.h
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


#ifndef _APP_TEST_MAIN_H_
#define _APP_TEST_MAIN_H_

typedef enum
{
	TEST_MAIN_OPERATION_ENTER = 0,
	TEST_MAIN_OPERATION_SYSTEM_INIT = 1,
	TEST_MAIN_OPERATION_SRIC_INIT = 2,
	TEST_MAIN_OPERATION_READY = 4,
	TEST_MAIN_OPERATION_DONE = 5,
	TEST_MAIN_OPERATION_EXIT = 255,

} eTestMainOperStatus_t;

typedef enum
{
	TEST_SUB_OPER_NONE = 0,
	TEST_SUB_OPER_MODULE_SET = 1,
	TEST_SUB_OPER_CR_AUTO_CALIBRATION = 2,

	TEST_SUB_OPER_JITTER_CALC = 3,
	TEST_SUB_OPER_BASE_JITTER_CALC = 4,
	TEST_SUB_OPER_SIGNALnNOISE_MEASURE	= 5,

	TEST_SUB_OPER_N_FRAME_AVR_RAWDATA_VIEW = 10,
	TEST_SUB_OPER_INTENSITY_VIEW = 11,

	TEST_SUB_OPER_TSYNC_OUT_GENERATION = 12,
	TEST_SUB_OPER_LIMIT = 255

} eTestSubOpStatus_t;

typedef enum
{
	TEST_ITEM_FLOW_NONE = 0,
	TEST_ITEM_FLOW_READY = 1,
	TEST_ITEM_FLOW_START = 2,
	TEST_ITEM_FLOW_FINISH = 3,
	TEST_ITEM_FLOW_LIMIT = 255

} eTestItemFlowStatus_t;

typedef enum
{
	TEST_SnN_STATUS_MEASURE_START = 0,
	TEST_SnN_STATUS_CHANGE_READY = 1,
	TEST_SnN_STATUS_ONLY_SIGNAL_MEASURE = 2,
	TEST_SnN_STATUS_SIGNAL_MEASURE = 3,
	TEST_SnN_STATUS_NOISE_MEASURE = 4,
	TEST_SnN_STATUS_MEASURE_DONE = 5,
	TEST_SnN_STATUS_MEASURE_EXIT = 10,
	TEST_SnN_STATUS_LIMIT = 255

} eSignalnNoiseMesureStatus_t;


typedef struct
{
	eTestSubOpStatus_t elTestSub_Status;
	eTestItemFlowStatus_t elTestItemFlow_Status;
	eSignalnNoiseMesureStatus_t eSnNMeasure_Status;
	uint32_t ulCRAutoCal_TargetValue;

	bool_t bIsLinefilter;
	uint32_t ulBaseLineInitFrameNum;

	uint32_t ulSignalnNoiseMeasureBaselineFrameNum;
	uint32_t ulSignalnNoiseMeasureSignalnNoiseFrameNum;
	uint32_t ulSignalnNoiseMeasureIndex;

	uint32_t ulJitterTestNum;
	bool_t bIsBaseJitter_Positive_view;

	uint32_t ulRawDataViewAvrFrameNum;

	tAlgorithmInfo_t* thisInfo;
	tAppInfo_t* ptAppInfo;

} tTestOperationParam_t;

typedef struct
{
	uint16_t ulStrength;
	uint16_t ulNoise;
	uint16_t ulIndex_r;
	uint16_t ulIndex_c;

} tSignalNoiseSaveBuf;

extern __IO tTestOperationParam_t tTestOperParam;


extern void app_test_operation_Function_Init(void);
extern void app_test_operation_SRIC_Init(void);
/*
 * Test Item
 */
extern void app_test_operation_jitter(void);
extern void app_test_operation_base_jitter(void);
extern void app_test_operation_SignalnNoise_Measure(void);

extern void app_test_operation_NFrame_Average_RawDataView(void);
extern void app_test_operation_IntensityView(void);

extern void app_test_operation_TSYNC_OUT_Generation(void);

/*
 * Module Control Test
 */
extern void app_test_operation_MODULE_Reset(bool_t bIsOnlyCRValue);
extern void app_test_operation_SRIC_CR_AutoCalibration(void);

/*
 * PWM Control Test
 */
extern void app_test_pwm_Set_TSync_LHBnPeriod(bool_t bIsInit);
extern void app_test_pwm_Set_PWM_Delay_Pulse(bool_t bIsInit);
extern void app_test_pwm_TSync_out_Generation_Init(void);
extern void app_test_pwm_TSync_out_Generation_DeInit(void);

#endif /* _APP_TEST_MAIN_H_ */
