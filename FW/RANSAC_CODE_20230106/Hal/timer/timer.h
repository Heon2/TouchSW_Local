/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : timer.h
 * created on : 10. 05. 2019
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

#ifndef _TIMER_H_
#define _TIMER_H_


typedef struct
{
	uint32_t ulTimerUnit;
	uint32_t ulLoadCount;
	uint32_t ulLoadBGCount;

} tTimerOpHandleInfo_t;

#define TIMER_OPMODE_FREERUNNING			(0)
#define TIMER_OPMODE_PERIODIC				(1)
#define TIMER_OPMODE_ONESHOT				(2)

#define OPERATION_TIMER_UNITNUM				(8)
#define TIMER_1UNIT							(0)
#define TIMER_2UNIT							(1)
#define TIMER_3UNIT							(2)
#define TIMER_4UNIT							(3)

#define TIMER_MAX_VALUE						(0xFFFFFFFF)

#define TIMER_WRAPPING_MODE					(0)
#define TIMER_ONE_SHOT_MODE					(1)

#define TIMER_SIZE_16BIT					(0)
#define TIMER_SIZE_32BIT					(1)

#define TIMER_CLOCK_DIV_1					(0)
#define TIMER_CLOCK_DIV_16					(1)
#define TIMER_CLOCK_DIV_256					(2)
#define TIMER_CLOCK_DIV_NOTUSED				(3)

#define TIMER_INTR_ENABLE					(1)
#define TIMER_INTR_DISABLE					(0)

#define TIMER_FREE_RUNNING_MODE				(0)
#define TIMER_PERIODIC_MODE					(1)

#define TIMER_ENABLE						(1)
#define TIMER_DISABLE						(0)

#define TIMER_USED_SYSTEM_CLOCK				(0)
#define TIMER_USED_TIM_CLOCK				(1)

#define TIMER_TIM_CLOCK_MHZ					(3)
#define TIMER_usec(a)						(TIMER_TIM_CLOCK_MHZ*(a))
#define TIMER_msec(a)						(TIMER_TIM_CLOCK_MHZ*(a)*1000)


extern void TIMER_Initialize(void);
extern void TIMER_DeInitialize(void);
extern void TIMER_SetFreeRunningMode(tTimerOpHandleInfo_t * ptTimerHandle);
extern void TIMER_SetPeriodicMode(tTimerOpHandleInfo_t * ptTimerHandle);
extern void TIMER_SetOneShotMode(tTimerOpHandleInfo_t * ptTimerHandle);
extern void TIMER_StartTimer(uint32_t Unit);
extern void TIMER_StopTimer(uint32_t Unit);
extern uint32_t TIMER_GetLoadCount(uint32_t Unit);
extern void TIMER_WaitForIrq(uint32_t Unit);

extern void medium_delay(uint32_t c);

#endif /* _TIMER_H_ */
