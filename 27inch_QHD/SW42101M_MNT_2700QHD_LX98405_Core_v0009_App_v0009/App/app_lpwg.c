/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_s3.c
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


static const tAppCommonConf_t * thisCommonConf = NULL;

void app_lpwg_Init(void)
{
//	sptAlgorithmInfo = algorithm_GetInfo();
	thisCommonConf   = app_GetCommonConfig();
}

eTouchOperMainState_t app_lpwg_oper_handler(void)
{
	eTouchOperMainState_t eMain_State;
	eLpwgOperSubState_t eSub_State;
	bool_t bLoop = YES;
	eProtocolMode_t currMode, prevMode = M_TOUCH_LPWG;

	app_lpwg_Init();

	eSub_State = TOUCH_LPWG_OPER_ENTER;

	while(bLoop)
	{
		switch(eSub_State)
		{
			case TOUCH_LPWG_OPER_ENTER:
			{
				/*
				 * LCD On Signal이 일정 시간 안에 High로 올라가면.. Normal모드로 진입 한다.
				 */
				if(module_Init_Signal())
				{
					protocol_swip_SetMode(M_TOUCH_NORMAL);
					break;
				}
				protocol_swip_SetMode(M_TOUCH_LPWG);
			}
			/* no break */
			case TOUCH_LPWG_OPER_RESET_SYSTEM:
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
			case TOUCH_LPWG_OPER_RESET_HAL:
			{
#ifdef MODE_WDT
				module_Watch_Enable();
#endif /* MODE_WDT */
				MODULE_Initialize();
				HAL_Initialize(YES);
			}
			/* no break */
			case TOUCH_LPWG_OPER_RESET_MODULE:
			{
				if(!module_Start()) // TODO : return값이 무조건 TRUE이다.. 무조건 아래 루틴을 타게 되네...
				{
					eSub_State = TOUCH_LPWG_OPER_ENTER;
					break;
				}
				eSub_State = TOUCH_LPWG_OPER_RESET_REFERENCE;

				break;
			}
			case TOUCH_LPWG_OPER_RESET_REFERENCE:
			{
				if(module_Switch_Freq(thisCommonConf->MainFreq))
				{
					algorithm_baseline_tracking_initial();
				}
				eSub_State = TOUCH_LPWG_OPER_NORMAL;
				break;
			}
//			case TOUCH_LPWG_OPER_NORMAL_READY:
//			{
//				break;
//			}
			case TOUCH_LPWG_OPER_NORMAL:
			{
				if(!module_wait_full_sample_done())
				{
					eSub_State = TOUCH_LPWG_OPER_ENTER;
					break;
				}

				if(algorithm_process() == NO)
				{
					eSub_State = TOUCH_LPWG_OPER_RESET_REFERENCE;
					break;
				}

//				algorithm_CheckFingerIdleModeControl();

				break;
			}
			case TOUCH_LPWG_OPER_EXIT:
			{
#if USED_LPWG_MCU_SLEEP
				tCK_ENA_RUN0_t tCK_ENA_RUN0;
				tCK_ENA_RUN1_t tCK_ENA_RUN1;
				tCK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
				tCK_ENA_RUN0.tBit.r_I2C_CLK_ENA = 1;
				tCK_ENA_RUN0.tBit.r_FLITF_CLK_ENA = 1;
				tCK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
				SCRB->CK_ENA_RUN0.ulBulk = tCK_ENA_RUN0.ulBulk;

				tCK_ENA_RUN1.ulBulk = SCRB->CK_ENA_RUN1.ulBulk;
				tCK_ENA_RUN1.tBit.r_MSPI01_CLK_ENA = 1;
				tCK_ENA_RUN1.tBit.r_MSPI23_CLK_ENA = 1;
				tCK_ENA_RUN1.tBit.r_MSPI45_CLK_ENA = 1;
				tCK_ENA_RUN1.tBit.r_SIF_CLK_ENA = 1;
				tCK_ENA_RUN1.tBit.r_SFL_CLK_ENA = 1;
				tCK_ENA_RUN1.tBit._VECTKEY = SCB_VECTKEY_VALUE;
				SCRB->CK_ENA_RUN1.ulBulk = tCK_ENA_RUN1.ulBulk;

				SysTick_Initialize(TMCU_MAIN_TRIM_CLOCK_SPEED);
#endif /* USED_LPWG_MCU_SLEEP */

#ifdef MODE_WDT
				Hal_WDT_DeInit();
#endif /* MODE_WDT */
				module_Stop(); // NOTE : 함수 구현내용이 없음!!
				bLoop = NO;
				continue;
//				break;
			}
		} /* switch(eSub_State) */

		if( protocol_swip_GetRecalibrate() == YES)
		{
			eSub_State = TOUCH_LPWG_OPER_RESET_REFERENCE;

			protocol_swip_SetRecalibrate(NO);
		}

		currMode = protocol_swip_GetMode();
		if(currMode != prevMode)
		{
			switch( currMode )
			{
				case M_TOUCH_NORMAL:
				{
					eSub_State = TOUCH_LPWG_OPER_EXIT;
					eMain_State = TOUCH_MAIN_OPERATION_NORMAL;
					break;
				}
				case M_TOUCH_DFUP:
				{
					eSub_State = TOUCH_LPWG_OPER_EXIT;
					eMain_State = TOUCH_MAIN_OPERATION_DFUP;
					break;
				}
			}
		}

	} /* while(bLoop) */

    return eMain_State;
}

