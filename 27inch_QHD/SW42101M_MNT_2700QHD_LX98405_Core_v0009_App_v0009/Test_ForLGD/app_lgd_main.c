/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  app_lgd_main.c
 * created on :  10. 10. 2018
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
#include "param_def.h"
#include "Mspi.h"
#include "DSP_B.h"
#include "wdgt.h"
#include "gpio.h"
#include "pwmdrv.h"
#include "app_lgd_main.h"
#ifdef _USE_APP_LGD_LIB_
#include "sric_lib_param.h"
#include "pwm_lib_param.h"
#endif /* _USE_APP_LGD_LIB_ */


uint32_t ulTestFlowReset = 0;
__IO uint16_t ulLibrary_Version = LGD_TEST_LIBRARY_VERSION;


//#ifdef _USE_APP_LGD_LIB_
__IO tLGDTestOperationParam_t tLGDTestOperParam;

eTouchOperMainState_t app_lgd_test_main_oper_handler(void)
{
	if(ulLibrary_Version != LGD_TEST_LIBRARY_VERSION)
	{
		return TOUCH_MAIN_OPERATION_LGD_TEST;
	}

	eTouchOperMainState_t main_state = TOUCH_MAIN_OPERATION_NORMAL;

	eLGDTestMainOperStatus_t eLGDTest_Main_OperStatus;
	eLGDTestSubOperStatus_t eLGDTest_Sub_OperStatus;
	bool_t bLoop = YES;
	eLGDTest_Main_OperStatus = LGDTEST_MAIN_OPERATION_ENTER;
	tLGDTestOperParam.thisInfo = algorithm_GetInfo();
	tLGDTestOperParam.ptAppInfo = app_GetInfo();

	while(bLoop)
	{
		switch(eLGDTest_Main_OperStatus)
		{
			case LGDTEST_MAIN_OPERATION_ENTER:
			{
//				module_Init_Signal();
				module_start_delay();
				eLGDTest_Main_OperStatus = LGDTEST_MAIN_OPERATION_SYSTEM_INIT;
				break;
			}
			case LGDTEST_MAIN_OPERATION_SYSTEM_INIT:
			{
				if(PARAM_GetMode() != PARAM_MODE_NORMAL)
				{
					PARAM_SetMode(PARAM_MODE_NORMAL);
					PARAM_InitConfig();
					algorithm_init();
#if (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY))
					algorithm_local_init(); //code
//					algorithm_init_local(); //DSP
#endif /* (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY)) */
				}
				MODULE_Initialize();
				HAL_Initialize(NO);
				eLGDTest_Main_OperStatus = LGDTEST_MAIN_OPERATION_SRIC_INIT;
				break;
			}
			case LGDTEST_MAIN_OPERATION_SRIC_INIT:
			{
				module_Start();
				eLGDTest_Main_OperStatus = LGDTEST_MAIN_OPERATION_READY;
				break;
			}
			case LGDTEST_MAIN_OPERATION_READY:
			{
#if USED_PEN_MODE_OPERATION
#else /* USED_PEN_MODE_OPERATION */
				eLGDTest_Sub_OperStatus = LGDTEST_SUB_OPER_FINGERONLY;
				tLGDTestOperParam.elTestSub_Status = LGDTEST_SUB_OPER_FINGERONLY;
				eLGDTest_Main_OperStatus = LGDTEST_MAIN_OPERATION_DONE;
#endif /* USED_PEN_MODE_OPERATION */
			}
			/* no break */
			case LGDTEST_MAIN_OPERATION_DONE:
			{
				switch(eLGDTest_Sub_OperStatus)
				{
#if USED_PEN_MODE_OPERATION
					case LGDTEST_SUB_OPER_FINGERONLY:
					{
						if(!module_wait_full_sample_done())
						{
							eLGDTest_Main_OperStatus = LGDTEST_MAIN_OPERATION_ENTER;
						}
						protocol_LogMatrix(LT_RAWDATA, tLGDTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tLGDTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
						break;
					}
					case LGDTEST_SUB_OPER_PEN_DETECTION:
					{
						if(!module_wait_full_sample_done())
						{
							eLGDTest_Main_OperStatus = LGDTEST_MAIN_OPERATION_ENTER;
						}
	//						protocol_LogMatrix(LT_RAWDATA, tLGDTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tLGDTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
	//						protocol_LogMatrix(LT_PENPOS_RAWDATA, tLGDTestOperParam.thisInfo->ucScreenCol, HAL_GET_LOCAL_RAW_IMAGE_PTR(), COL_MAX, tLGDTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
						break;
					}
					case LGDTEST_SUB_OPER_LOCAL_PEN:
					{
						module_wait_local_sample_done();
	//						protocol_LogMatrix(LT_RAWDATA, tLGDTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tLGDTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
	//						protocol_LogMatrix(LT_PENPOS_RAWDATA, tLGDTestOperParam.thisInfo->ucScreenCol, HAL_GET_LOCAL_RAW_IMAGE_PTR(), COL_MAX, 10, 84/*Raw Data*/);
	//						protocol_LogMatrix(LT_PENDATA_RAWDATA, tLGDTestOperParam.thisInfo->ucScreenCol, HAL_GET_LOCAL_DATA_RAW_IMAGE_PTR(), COL_MAX, 40, 84/*Raw Data*/);
						break;
					}
#else /* USED_PEN_MODE_OPERATION */
					case LGDTEST_SUB_OPER_FINGERONLY:
					{
						if(!module_wait_full_sample_done())
						{
							eLGDTest_Main_OperStatus = LGDTEST_MAIN_OPERATION_ENTER;
						}
						protocol_LogMatrix(LT_RAWDATA, tLGDTestOperParam.thisInfo->ucScreenCol, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, tLGDTestOperParam.thisInfo->ucScreenRow, 84/*Raw Data*/);
						break;
					}
#endif /* USED_PEN_MODE_OPERATION */
					case LGDTEST_SUB_OPER_NONE:
					default:
					{
						break;
					}
				}
				eLGDTest_Sub_OperStatus = tLGDTestOperParam.elTestSub_Status;

				if(ulTestFlowReset == 1)
				{
					ulTestFlowReset = 0;
					eLGDTest_Main_OperStatus = LGDTEST_MAIN_OPERATION_SRIC_INIT;
				}

				break;
			}
			case LGDTEST_MAIN_OPERATION_EXIT:
			default:
				break;
		}
	}

	return main_state;
}
//#endif /* _USE_APP_LGD_LIB_ */
