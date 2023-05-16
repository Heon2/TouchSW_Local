/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : timer_tick.c
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

#include "hal_def.h"


#if USED_ENTER_IDLE_REAL_TIME_CHECK
volatile uint32_t ulTimerTickIdleCheckCount;
#endif /* USED_ENTER_IDLE_REAL_TIME_CHECK */
volatile uint32_t _timertick_high_rank_count_;
volatile uint32_t _timer_clock_;

void TimerTick_InterruptHandler(void)
{
	//56bit counter�� ����� ���� 32bitī��Ʈ ���� �߰�
	if (_timertick_high_rank_count_ == 0)
	{
		_timertick_high_rank_count_ = SYSTICK_MAX_HIGHT_RANK_COUNT;
	}
	else
	{
		--_timertick_high_rank_count_;
	}

#if USED_ENTER_IDLE_REAL_TIME_CHECK
	ulTimerTickIdleCheckCount++;
#endif /* USED_ENTER_IDLE_REAL_TIME_CHECK */

#if USED_QUEUECOMMONDATA_SEND_Timer_Tick
	#ifdef MODE_I2C
		QueueCommonData_I2C();
	#else
		QueueCommonData_USB();
	#endif
#else /* USED_QUEUECOMMONDATA_SEND_Timer_Tick */
	if(tHalIntrHandle.ulUSBSendData_TimerTick)
	{
	#ifdef MODE_I2C
		QueueCommonData_I2C();
	#else
		QueueCommonData_USB();
	#endif
	}
#endif /* USED_QUEUECOMMONDATA_SEND_Timer_Tick */
}

void TimerTick_Initialize(uint32_t clk)
{
	tTimerOpHandleInfo_t TimerOpHandleInfo;
	Fncp_Systick_IRQHandler = &TimerTick_InterruptHandler;
#define TIMER_NUM_0			(0)
	TimerOpHandleInfo.ulLoadBGCount = 0;
	TimerOpHandleInfo.ulLoadCount = SYSTICK_MAXCOUNT;
	TimerOpHandleInfo.ulTimerUnit = TIMER_NUM_0;
	_timer_clock_ = clk;
	TIMER_SetPeriodicMode(&TimerOpHandleInfo);
//	SysTick_Config(SYSTICK_MAXCOUNT);
	TIMER_StartTimer(TIMER_NUM_0);
}

void TimerTick_DeInitialize(void)
{
	TIMER_StopTimer(TIMER_NUM_0);
	Fncp_Systick_IRQHandler = NULL;
}


/**
  * @}
  */
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
 * @brief  ���� �ð�(systick count)���� ����� �ð�(systick count)�� ���Ѵ�.
 *
 * @param  uint64_t   start_tick	������ ������ Systick count. getLongSysTick()���� ��´�.
 * @return uint64_t				����� �ð�(systick count)
 *
 * systick�� ����� �Լ��� ���� 20us�����̰� 1000799917�ʱ��� ����ð� ���Ҽ� ����.
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
 * @brief  ���� �ð�(systick count)���� ����� �ð�(����ũ�μ�ũ)�� ���Ѵ�.
 *
 * @param  uint64_t   start_tick	������ ������ Systick count. getLongSysTick()���� ��´�.
 * @return uint64_t				����� �ð�(����ũ�� ��ũ)
 *
 * systick�� ����� �Լ��� ���� 20us�����̰� 1000799917�ʱ��� ����ð� ���Ҽ� ����.
 */
uint64_t getElapsedTime_us(uint64_t start_tick)
{
	return getUSfromTick(getElapsedLongSYSTICK(start_tick));
}
/**
 * @brief  ����ũ�μ�ũ ������ �����̸� �ش�.
 *
 * @param  uint32_t   time       �������� ����ũ�μ�ũ
 * @return none
 *
 * systick�� ����� ������ �Լ��� ���� 10us�����̰� 200�и����� ������ ������. 20�и� �ʰ��ϸ� ���ѷ����� ����.
 */
void delay_us_useSystick(uint32_t time)
{
	uint32_t start = getSysTick();
	do {
	} while (getUSfromTick(getElapsedSYSTICK(start))<time);
}
/**
 * @brief  �и���ũ ������ �����̸� �ش�.
 *
 * @param  uint32_t   time       �������� �ð�
 * @return none
 *
 * systick�� ����� ������ �Լ��� ���� 10us�����̰� 200�и����� ������ ������. 20�и� �ʰ��ϸ� ���ѷ����� ����.
 */
void delay_ms_useSystick(uint32_t time)
{
	uint32_t start = getSysTick();
	do {
	} while (getMSfromTick(getElapsedSYSTICK(start))<time);
}
/**
 * @brief  �и���ũ ������ �����̸� �ش�.
 *
 * @param  uint32_t   tick_count       �������� tick count
 * @return none
 *
 * systick�� ����� ������ �Լ��� 0x00FFFFFF���� ������ ������. �ʰ��ϸ� ���ѷ����� ����.
 */
void delay_systick(uint32_t tick_count)
{
	uint32_t start = getSysTick();
	do {
	} while (getElapsedSYSTICK(start)<tick_count);
}
/**
 * @brief  ����ũ�� ������ �����̸� �ش�.
 *
 * @param  uint32_t   time       �������� �ð�
 * @return none
 *
 * systick�� ����� ������ �Լ��� ���� 10us�����̰� 85899345�ʱ��� ������ ������.
 */

void delay_us(uint32_t time)
{
	int i,count,remainder,block;
	block = SYSTICK_MAXCOUNT / _timer_clock_ -10;
	count = time / block;//200ms������ ������
	remainder = time % block;//������ ������
	for (i=0; i<count; ++i)
	{
		delay_us_useSystick(block);
	}
	delay_us_useSystick(remainder);
}
/**
 * @brief  �и���ũ ������ �����̸� �ش�.
 *
 * @param  uint32_t   time       �������� �ð�
 * @return none
 *
 * systick�� ����� ������ �Լ��� ���� 10us�����̰� 85899345�ʱ��� ������ ������.
 */
void delay_ms(uint32_t time)
{
	delay_us(time * 1000);
//	int i, count, remainder, block;
//	block = SYSTICK_MAXCOUNT/(1000*_timer_clock_) -10;
//	count = time / block;//200ms������ ������
//	remainder = time % block;//������ ������
//	for (i=0;i<count;++i)
//	{
//		delay_ms_useSystick(block);
//	}
//	delay_ms_useSystick(remainder);
}

#if USED_ENTER_IDLE_REAL_TIME_CHECK
void TimerTick_ResetIdleModeCheckTime(void)
{
	ulTimerTickIdleCheckCount = 0;
}

uint32_t ulTimeSec;
uint32_t TimerTick_GetIdleModeCheckTimeSec(void)
{
//	uint32_t ulTimeSec;

	ulTimeSec = (ulTimerTickIdleCheckCount * SYSTICK_MAXCOUNT)/(_timer_clock_ * 1000 * 1000);

	return ulTimeSec;
}
#endif /* USED_ENTER_IDLE_REAL_TIME_CHECK */
