/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : systick.c
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

#include "hal_def.h"


volatile uint32_t _systick_high_rank_count_;
volatile uint32_t _core_clock_;


void SysTick_InterruptHandler(void)
{
	//56bit counter를 만들기 위해 32bit카운트 변수 추가
	if (_systick_high_rank_count_ == 0)
	{
		_systick_high_rank_count_ = SYSTICK_MAX_HIGHT_RANK_COUNT;
	}
	else
	{
		--_systick_high_rank_count_;
	}

	QueueCommonData_USB();
}

void SysTick_Initialize(uint32_t clk)
{
	Fncp_Systick_IRQHandler = &SysTick_InterruptHandler;

	SysTick_Config(SYSTICK_MAXCOUNT);
	_core_clock_ = clk;
}

void SysTick_DeInitialize(void)
{
	SysTick->CTRL = 0x0;
}


/**
  * @}
  */
//void config_systick(uint32_t clk)
//{
//	Fncp_Systick_IRQHandler = &SysTick_InterruptHandler;
//
//	SysTick_Config(SYSTICK_MAXCOUNT);
//	_core_clock_ = clk;
//}
uint32_t getElapsedSYSTICK2(uint32_t start,uint32_t end)
{
	int32_t elapsedTick;
	elapsedTick = start-end;
	if (elapsedTick < 0) elapsedTick += SYSTICK_MAXCOUNT;
	return elapsedTick;
}

uint32_t getElapsedSYSTICK(uint32_t start)
{
	int32_t elapsedTick;
	elapsedTick = start - getSysTick();
	if (elapsedTick < 0)
	{
		elapsedTick += SYSTICK_MAXCOUNT;
	}
	return elapsedTick;
}
/**
 * @brief  시작 시간(systick count)부터 경과된 시간(systick count)을 구한다.
 *
 * @param  uint64_t   start_tick	시잔한 시점의 Systick count. getLongSysTick()으로 얻는다.
 * @return uint64_t				경과된 시간(systick count)
 *
 * systick을 사용한 함수로 오차 20us정도이고 1000799917초까지 경과시간 구할수 있음.
 */
uint64_t getElapsedLongSYSTICK(uint64_t start)
{
	int64_t elapsedTick;
	elapsedTick = start-getLongSysTick();
	if (elapsedTick < 0)
	{
		elapsedTick = SYSTICK_MAX_LONG_COUNT + elapsedTick;
	}
	return elapsedTick;
}
/**
 * @brief  시작 시간(systick count)부터 경과된 시간(마이크로세크)을 구한다.
 *
 * @param  uint64_t   start_tick	시잔한 시점의 Systick count. getLongSysTick()으로 얻는다.
 * @return uint64_t				경과된 시간(마이크로 세크)
 *
 * systick을 사용한 함수로 오차 20us정도이고 1000799917초까지 경과시간 구할수 있음.
 */
uint64_t getElapsedTime_us(uint64_t start_tick)
{
	return getUSfromTick(getElapsedLongSYSTICK(start_tick));
}
/**
 * @brief  마이크로세크 단위의 딜레이를 준다.
 *
 * @param  uint32_t   time       딜레이할 마이크로세크
 * @return none
 *
 * systick을 사용한 딜레이 함수로 오차 10us정도이고 200밀리까지 딜레이 가능함. 20밀리 초과하면 무한루프에 빠짐.
 */
void delay_us_useSystick(uint32_t time)
{
	uint32_t start = getSysTick();
	do {
	} while (getUSfromTick(getElapsedSYSTICK(start))<time);
}
/**
 * @brief  밀리세크 단위의 딜레이를 준다.
 *
 * @param  uint32_t   time       딜레이할 시간
 * @return none
 *
 * systick을 사용한 딜레이 함수로 오차 10us정도이고 200밀리까지 딜레이 가능함. 20밀리 초과하면 무한루프에 빠짐.
 */
void delay_ms_useSystick(uint32_t time)
{
	uint32_t start = getSysTick();
	do {
	} while (getMSfromTick(getElapsedSYSTICK(start))<time);
}
/**
 * @brief  밀리세크 단위의 딜레이를 준다.
 *
 * @param  uint32_t   tick_count       딜레이할 tick count
 * @return none
 *
 * systick을 사용한 딜레이 함수로 0x00FFFFFF까지 딜레이 가능함. 초과하면 무한루프에 빠짐.
 */
void delay_systick(uint32_t tick_count)
{
	uint32_t start = getSysTick();
	do {
	} while (getElapsedSYSTICK(start)<tick_count);
}
/**
 * @brief  마이크로 단위의 딜레이를 준다.
 *
 * @param  uint32_t   time       딜레이할 시간
 * @return none
 *
 * systick을 사용한 딜레이 함수로 오차 10us정도이고 85899345초까지 딜레이 가능함.
 */

void delay_us(uint32_t time)
{
	int i,count,remainder,block;
	block = SYSTICK_MAXCOUNT / _core_clock_ -10;
	count = time / block;//200ms단위로 딜레이
	remainder = time % block;//나머지 딜레이
	for (i=0; i<count; ++i)
	{
		delay_us_useSystick(block);
	}
	delay_us_useSystick(remainder);
}
/**
 * @brief  밀리세크 단위의 딜레이를 준다.
 *
 * @param  uint32_t   time       딜레이할 시간
 * @return none
 *
 * systick을 사용한 딜레이 함수로 오차 10us정도이고 85899345초까지 딜레이 가능함.
 */
void delay_ms(uint32_t time)
{
	delay_us(time * 1000);
}
