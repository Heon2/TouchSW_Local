/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : timer_tick.h
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

#ifndef _SYSTICK_H_
#define _SYSTICK_H_



#ifdef __cplusplus
extern "C" {
#endif
	
/**
  * @}
  */
#define SYSTIC_TYPE							uint64_t

#if 1
	#if 1 // 12M기준 대략(1.365msec마다 Interrupt발생)
		#define SYSTICK_MASK						(0x00003FFF)
		#define SYSTICK_MAXCOUNT					(0x00003FFF+1)
		#define SYSTICK_MAX_HIGHT_RANK_COUNT		(0xFFFFFFFF)
		#define SYSTICK_MAX_LONG_COUNT				(SYSTICK_MASK + SYSTICK_MAX_HIGHT_RANK_COUNT)//(0xFFFFFFFFFFFFFF)
		#define getSysTick()            			((TIMER->TIMER_VALUE[0])&SYSTICK_MASK)
		#define getLongSysTick()            		(((uint64_t)_timertick_high_rank_count_<<14)|(uint64_t)((TIMER->TIMER_VALUE[0])&SYSTICK_MASK))
		#define getUSfromTick(tick)					(tick/(_timer_clock_))
		#define getMSfromTick(tick)					(tick/(1000*_timer_clock_-1))
		#define getElapsedUS(start)					getUSfromTick(getElapsedLongSYSTICK(start))
	#else // 96M 기준
		#define SYSTICK_MASK						(0x0001FFFF)
		#define SYSTICK_MAXCOUNT					(0x0001FFFF+1)
		#define SYSTICK_MAX_HIGHT_RANK_COUNT		(0xFFFFFFFF)
		#define SYSTICK_MAX_LONG_COUNT				(SYSTICK_MASK + SYSTICK_MAX_HIGHT_RANK_COUNT)//(0xFFFFFFFFFFFFFF)
		#define getSysTick()            			((SysTick->VAL)&SYSTICK_MASK)
		#define getLongSysTick()            		(((uint64_t)_timertick_high_rank_count_<<17)|(uint64_t)((SysTick->VAL)&SYSTICK_MASK))
		#define getUSfromTick(tick)					(tick/(_timer_clock_))
		#define getMSfromTick(tick)					(tick/(1000*_timer_clock_-1))
		#define getElapsedUS(start)					getUSfromTick(getElapsedLongSYSTICK(start))
	#endif
#else
	#define SYSTICK_MASK						(0x00FFFFFF)
	#define SYSTICK_MAXCOUNT					(0x00FFFFFF+1)
	#define SYSTICK_MAX_HIGHT_RANK_COUNT		(0xFFFFFFFF)
	#define SYSTICK_MAX_LONG_COUNT				(0xFFFFFFFFFFFFFF)
	#define getSysTick()            			((SysTick->VAL)&SYSTICK_MASK)
	#define getLongSysTick()            		(((uint64_t)_timertick_high_rank_count_<<24)|(uint64_t)((SysTick->VAL)&SYSTICK_MASK))
	#define getUSfromTick(tick)					(tick/(_timer_clock_))
	#define getMSfromTick(tick)					(tick/(1000*_timer_clock_-1))
	#define getElapsedUS(start)					getUSfromTick(getElapsedLongSYSTICK(start))
#endif

#define delay_usec(t)		delay_us(t)
#define delay_msec(t)		delay_us((t)*1000)

volatile extern uint32_t _timertick_high_rank_count_;
volatile extern uint32_t _timer_clock_;

void TimerTick_Initialize(uint32_t clk);
void TimerTick_DeInitialize(void);
uint32_t getElapsedSYSTICK2(uint32_t start,uint32_t end);
uint32_t getElapsedSYSTICK(uint32_t start);
uint64_t getElapsedLongSYSTICK(uint64_t start);
uint64_t getElapsedTime_us(uint64_t start_tick);
void delay_us_useSystick(uint32_t time);
void delay_ms_useSystick(uint32_t time);
void delay_systick(uint32_t tick_count);
void delay_us(uint32_t time);
void delay_ms(uint32_t time);

#ifdef __cplusplus
}
#endif


#endif /* _SYSTICK_H_ */
