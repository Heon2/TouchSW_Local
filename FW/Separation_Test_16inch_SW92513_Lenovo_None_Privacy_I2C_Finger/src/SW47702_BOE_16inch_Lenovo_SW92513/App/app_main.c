/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_main.c
 * created on : 14. 5. 2019
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
#include "timer_tick.h"
#include "gpio.h"


int app_MainProc(void)
{
	eTouchOperMainState_t main_state;
#if USED_TOUCH_TUNING_PROCESS
	main_state = TOUCH_MAIN_OPERATION_TUNING_PROCESS;
#else /* USED_TOUCH_TUNING_PROCESS */
	main_state = TOUCH_MAIN_OPERATION_NORMAL;
#endif /* USED_TOUCH_TUNING_PROCESS */

	module_HW_Init();
	PARAM_Initialize();
	HAL_Initialize();

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
				main_state = app_normal_oper_handler();
				break;
			}
#if !DIAG_OFF
			case TOUCH_MAIN_OPERATION_DIAG:
			{
				main_state = app_diag_oper_handler();
				break;
			}
#endif
			case TOUCH_MAIN_OPERATION_DFUP:
			{
				main_state = app_dfup_oper_handler();
				break;
			}
#if USED_TOUCH_TUNING_PROCESS
			case TOUCH_MAIN_OPERATION_TUNING_PROCESS:
			{
				main_state = app_tuning_process_main_oper_handler();
				break;
			}
#endif /* USED_TOUCH_TUNING_PROCESS */
			case TOUCH_MAIN_OPERATION_RESET:
			{
				Hal_WDT_ForceReset();
			}
			/* no break */
			default:
				break;
	    }
    }

//    return 0; // NOTE : app_MainProc()리턴 값을 갖을 필요가 없음!!
}
