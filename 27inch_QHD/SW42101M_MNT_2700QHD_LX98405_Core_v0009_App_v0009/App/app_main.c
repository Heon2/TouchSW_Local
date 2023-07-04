/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_main.c
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
#include "systick.h"
#include "gpio.h"

int app_MainProc(void)
{
	eTouchOperMainState_t main_state;
#ifdef _USE_APP_LGD_LIB_
	main_state = TOUCH_MAIN_OPERATION_LGD_TEST;
#else /* _USE_APP_LGD_LIB_ */
#if USED_TEST_OPERATION_ENABLE
	main_state = TOUCH_MAIN_OPERATION_TEST;
#else /* USED_TEST_OPERATION_ENABLE */ // TOUCH_MAIN_OPERATION_LPWG
	main_state = TOUCH_MAIN_OPERATION_NORMAL;//TOUCH_MAIN_OPERATION_NORMAL;
#endif /* USED_TEST_OPERATION_ENABLE */
#endif /* _USE_APP_LGD_LIB_ */

	// SRIC Init control
	GPIO->tGPIO_AFIO_1._GPIO_RSTN_0 = 0;
	GPIO->tGPIO_DATA_0._GPIO_RSTN_0 = 0;
	GPIO->tGPIO_DIR_0._GPIO_RSTN_0 = 1;

	GPIO->tGPIO_AFIO_1._GPIO_RSTN_1 = 0;
	GPIO->tGPIO_DATA_0._GPIO_RSTN_1 = 0;
	GPIO->tGPIO_DIR_0._GPIO_RSTN_1 = 1;
	initECLK();
	
	//module_Check_LcdOn(YES);
	module_HW_Init();
	PARAM_Initialize();
//	PARAM_InitConfig();

#if USED_GPIO_TEST_HANDSHAKE
	GPIO->tGPIO_DIR_1.tBit.GPB09 = 1;
#endif /* USED_GPIO_TEST_HANDSHAKE */
	_____TEST_GPB09_HandShake(2, 100);

    while(YES)
    {
    	switch(main_state)
	    {
			case TOUCH_MAIN_OPERATION_NORMAL:
			{
#ifndef _USE_APP_LGD_LIB_
				main_state = app_normal_oper_handler();
#endif /* _USE_APP_LGD_LIB_ */
				break;
			}
			case TOUCH_MAIN_OPERATION_NOISE:
			{
				//main_state = app_noise_oper_handler();
				break;
			}
			case TOUCH_MAIN_OPERATION_LPWG:
			{
//				main_state = app_lpwg_oper_handler();
				break;
			}
			case TOUCH_MAIN_OPERATION_DIAG:
			{
#ifndef _USE_APP_LGD_LIB_
				main_state = app_diag_oper_handler();
#endif /* _USE_APP_LGD_LIB_ */
				break;
			}
			case TOUCH_MAIN_OPERATION_DFUP:
			{
#ifndef _USE_APP_LGD_LIB_
				main_state = app_dfup_oper_handler();
#endif /* _USE_APP_LGD_LIB_ */
				break;
			}
#if USED_TEST_OPERATION_ENABLE
			case TOUCH_MAIN_OPERATION_TEST:
			{
				main_state = app_test_main_oper_handler();
				break;
			}
#endif /* USED_TEST_OPERATION_ENABLE */
#ifdef _USE_APP_LGD_LIB_
			case TOUCH_MAIN_OPERATION_LGD_TEST:
			{
				main_state = app_lgd_test_main_oper_handler();
				break;
			}
#endif /* _USE_APP_LGD_LIB_ */
			case TOUCH_MAIN_OPERATION_RESET:
			{
#ifdef MODE_WDT
				module_Watch_Enable();
				while(1);
#else /* MODE_WDT */
				while(1)
				{
					_____TEST_GPB09_HandShake(1, 14000);
				}
#endif /* MODE_WDT */
			}
			/* no break */
			default:
				break;
	    }
    }

//    return 0; // NOTE : app_MainProc()리턴 값을 갖을 필요가 없음!!
}
