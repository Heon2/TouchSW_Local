/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  app_test.c
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
__IO tTestOperationParam_t tTestOperParam;

eTouchOperMainState_t app_test_main_oper_handler(void)
{
	eTouchOperMainState_t main_state = TOUCH_MAIN_OPERATION_NORMAL;

	eTestMainOperStatus_t eTestMainOperStatus;
	eTestSubOpStatus_t eTestSubOperStatus;
	bool_t bLoop = YES;
	eTestMainOperStatus = TEST_MAIN_OPERATION_ENTER;
	tTestOperParam.thisInfo = algorithm_GetInfo();
	tTestOperParam.ptAppInfo = app_GetInfo();

	while(bLoop)
	{
		switch(eTestMainOperStatus)
		{
			case TEST_MAIN_OPERATION_ENTER:
			{
				app_test_operation_Function_Init();
				app_test_operation_SRIC_Init();
//				module_Init_Signal();
				module_start_delay();
				eTestMainOperStatus = TEST_MAIN_OPERATION_SYSTEM_INIT;
				break;
			}
			case TEST_MAIN_OPERATION_SYSTEM_INIT:
			{
				if( PARAM_GetMode() != PARAM_MODE_NORMAL )
				{
					PARAM_SetMode(PARAM_MODE_NORMAL);
					PARAM_InitConfig();
					algorithm_init();
#if (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY))
					algorithm_local_init(); //code
					algorithm_init_local(); //DSP
#endif /* (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY)) */
				}
				MODULE_Initialize();
				HAL_Initialize(NO);
				eTestMainOperStatus = TEST_MAIN_OPERATION_SRIC_INIT;
				break;
			}
			case TEST_MAIN_OPERATION_SRIC_INIT:
			{
				module_Start();
				eTestMainOperStatus = TEST_MAIN_OPERATION_READY;
				break;
			}
			case TEST_MAIN_OPERATION_READY:
			{
				eTestSubOperStatus = TEST_SUB_OPER_NONE;
				tTestOperParam.elTestSub_Status = TEST_SUB_OPER_NONE;
				tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_NONE;
				eTestMainOperStatus = TEST_MAIN_OPERATION_DONE;
			}
			/* no break */
			case TEST_MAIN_OPERATION_DONE:
			{
				if(!module_wait_full_sample_done())
				{
					eTestMainOperStatus = TEST_MAIN_OPERATION_ENTER;
				}

				switch(eTestSubOperStatus)
				{
					case TEST_SUB_OPER_MODULE_SET:
					{
						tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_READY;
						app_test_operation_MODULE_Reset(NO);
						eTestMainOperStatus = TEST_MAIN_OPERATION_READY;
						break;
					}
					case TEST_SUB_OPER_CR_AUTO_CALIBRATION:
					{
						tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_READY;
						app_test_operation_SRIC_CR_AutoCalibration();
						eTestMainOperStatus = TEST_MAIN_OPERATION_READY;
						break;
					}
					case TEST_SUB_OPER_JITTER_CALC:
					{
						tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_READY;
						app_test_operation_jitter();
						eTestMainOperStatus = TEST_MAIN_OPERATION_READY;
						break;
					}
					case TEST_SUB_OPER_BASE_JITTER_CALC:
					{
						tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_READY;
						app_test_operation_base_jitter();
						eTestMainOperStatus = TEST_MAIN_OPERATION_READY;
						break;
					}
					case TEST_SUB_OPER_SIGNALnNOISE_MEASURE:
					{
						tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_READY;
						app_test_operation_SignalnNoise_Measure();
						break;
					}
					case TEST_SUB_OPER_N_FRAME_AVR_RAWDATA_VIEW:
					{
						tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_READY;
						app_test_operation_NFrame_Average_RawDataView();
						eTestMainOperStatus = TEST_MAIN_OPERATION_READY;
						break;
					}
					case TEST_SUB_OPER_INTENSITY_VIEW:
					{
						tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_READY;
						app_test_operation_IntensityView();
						eTestMainOperStatus = TEST_MAIN_OPERATION_READY;
						break;
					}
//					case TEST_SUB_OPER_TSYNC_OUT_GENERATION:
//					{
//						tTestOperParam.elTestItemFlow_Status = TEST_ITEM_FLOW_READY;
//						app_test_operation_TSYNC_OUT_Generation();
//						eTestMainOperStatus = TEST_MAIN_OPERATION_READY;
//						break;
//					}
					case TEST_SUB_OPER_NONE:
					default:
					{
						protocol_LogMatrix(LT_RAWDATA, tTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
						eTestSubOperStatus = tTestOperParam.elTestSub_Status;
						break;
					}
				}

				break;
			}
			case TEST_MAIN_OPERATION_EXIT:
			default:
				break;
		}
	}

	return main_state;
}
#endif /* USED_TEST_OPERATION_ENABLE */
