/* Copyright (c) 2009 - 2016 SiliconWorks LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of SiW nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/

/*------------  Header Include -------------------------------------------------*/
#include "hal_def.h"
#include "module_def.h"
//#include "Misc.h"

// SW42101 VBS 관련 Timer는  보완필요

void TIMER_InterruptHandler(void)
{
	HW_REG(TIMER->Timer0_EOI_SR); // interrupt clear
	TIMER->Timer0_CR_b.Timer0_En = 0; // Disable timer 0 for LoadCount setting
	
#if (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405)
	if(GPIO->tGPIO_DATA_1._GPIO_SLEEP_RST == 0x0)
	{
		GPIO->tGPIO_DATA_1._GPIO_SLEEP_RST = 0x1;
		return;
	}
#endif /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */

#if USED_LPWG_MODE_CONTROL
	PWMDRV->FW_CTRL_b.VSYNC_IN = 1;
	GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT = 0x1;
	GPIO->tGPIO_DATA_1._GPIO_TSYNC_OUT = 0x0;
	
#if USED_TPIC_MUXEN_ON_OFF_CONTROL
	if(HAL_GetTPICMuxEnControl())
	{
		GPIO->tGPIO_DATA_1._GPIO_TPIC_MUX_EN = 1;
	}
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */	
	
	HAL_Timer_Set_Count_us(TIM_Channel_0, 50000);
	HAL_Timer_Enable(TIM_Channel_0, ENABLE);
#endif /* USED_LPWG_MODE_CONTROL */	
}

void TIM_DeInit(TIM_Channel TIMx_Chanel)
{
	if(TIMx_Chanel == TIM_Channel_0) 
	{ 
		TIMER->Timer0_CR_b.Timer0_En = ENABLE;
		TIMER->Timer0_CR_b.Timer0_En = DISABLE;
	}
	else if(TIMx_Chanel == TIM_Channel_1)
	{
		TIMER->Timer1_CR_b.Timer1_En = ENABLE;
		TIMER->Timer1_CR_b.Timer1_En = DISABLE;
	}
	else if(TIMx_Chanel == TIM_Channel_2)
	{
		TIMER->Timer2_CR_b.Timer2_En = ENABLE;
		TIMER->Timer2_CR_b.Timer2_En = DISABLE;
	}
	else if(TIMx_Chanel == TIM_Channel_3)
	{
		TIMER->Timer3_CR_b.Timer3_En = ENABLE;
		TIMER->Timer3_CR_b.Timer3_En = DISABLE;
	}
	else if(TIMx_Chanel == TIM_Channel_4)
	{
		TIMER->Timer4_CR_b.Timer4_En = ENABLE;
		TIMER->Timer4_CR_b.Timer4_En = DISABLE;		
	}
	else if(TIMx_Chanel == TIM_Channel_5)
	{
		TIMER->Timer5_CR_b.Timer5_En = ENABLE;                           
		TIMER->Timer5_CR_b.Timer5_En = DISABLE;
	}
	else if(TIMx_Chanel == TIM_Channel_6)
	{
		TIMER->Timer6_CR_b.Timer6_En = ENABLE;
		TIMER->Timer6_CR_b.Timer6_En = DISABLE;
	}
	else if(TIMx_Chanel == TIM_Channel_7)
	{
		TIMER->Timer7_CR_b.Timer7_En = ENABLE;
		TIMER->Timer7_CR_b.Timer7_En = DISABLE;
	}	
}

void TIM_TimeBaseInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct)
{
	if(TIM_TimeBaseInitStruct->TIM_Channel == TIM_Channel_0)
	{
		TIMER->Timer0_CR_b.Timer0_Mode = TIM_TimeBaseInitStruct->TIM_Mode;
		TIMER->Timer0_CR_b.Timer0_InterruptMask = TIM_TimeBaseInitStruct->TIM_Int_Mask;
		TIMER->Timer0_LoadCount_R_b.Timer0_LoadCount = TIM_TimeBaseInitStruct->TIM_Count;
	}
	else if(TIM_TimeBaseInitStruct->TIM_Channel == TIM_Channel_1)
	{
		TIMER->Timer1_CR_b.Timer1_Mode |= TIM_TimeBaseInitStruct->TIM_Mode;
		TIMER->Timer1_CR_b.Timer1_InterruptMask |= TIM_TimeBaseInitStruct->TIM_Int_Mask;
		TIMER->Timer1_LoadCount_CR |= TIM_TimeBaseInitStruct->TIM_Count;
	}
	else if(TIM_TimeBaseInitStruct->TIM_Channel == TIM_Channel_2)
	{
		TIMER->Timer2_CR_b.Timer2_Mode |= TIM_TimeBaseInitStruct->TIM_Mode;
		TIMER->Timer2_CR_b.Timer2_InterruptMask |= TIM_TimeBaseInitStruct->TIM_Int_Mask;
		TIMER->Timer2_LoadCount_CR |= TIM_TimeBaseInitStruct->TIM_Count;
	}
	else if(TIM_TimeBaseInitStruct->TIM_Channel == TIM_Channel_3)
	{
		TIMER->Timer3_CR_b.Timer3_Mode |= TIM_TimeBaseInitStruct->TIM_Mode;
		TIMER->Timer3_CR_b.Timer3_InterruptMask |= TIM_TimeBaseInitStruct->TIM_Int_Mask;
		TIMER->Timer3_LoadCount_CR |= TIM_TimeBaseInitStruct->TIM_Count;
	}
	else if(TIM_TimeBaseInitStruct->TIM_Channel == TIM_Channel_4)
	{
		TIMER->Timer4_CR_b.Timer4_Mode |= TIM_TimeBaseInitStruct->TIM_Mode;
		TIMER->Timer4_CR_b.Timer4_InterruptMask |= TIM_TimeBaseInitStruct->TIM_Int_Mask;
		TIMER->Timer4_LoadCount_CR |= TIM_TimeBaseInitStruct->TIM_Count;
	}
	else if(TIM_TimeBaseInitStruct->TIM_Channel == TIM_Channel_5)
	{
		TIMER->Timer5_CR_b.Timer5_Mode |= TIM_TimeBaseInitStruct->TIM_Mode;	
		TIMER->Timer5_CR_b.Timer5_InterruptMask |= TIM_TimeBaseInitStruct->TIM_Int_Mask;
		TIMER->Timer5_LoadCount_CR |= TIM_TimeBaseInitStruct->TIM_Count;
	}
	else if(TIM_TimeBaseInitStruct->TIM_Channel == TIM_Channel_6)
	{
		TIMER->Timer6_CR_b.Timer6_Mode |= TIM_TimeBaseInitStruct->TIM_Mode;	
		TIMER->Timer6_CR_b.Timer6_InterruptMask |= TIM_TimeBaseInitStruct->TIM_Int_Mask;
		TIMER->Timer6_LoadCount_CR |= TIM_TimeBaseInitStruct->TIM_Count;
	}
	else if(TIM_TimeBaseInitStruct->TIM_Channel == TIM_Channel_7)
	{
		TIMER->Timer7_CR_b.Timer7_Mode |= TIM_TimeBaseInitStruct->TIM_Mode;	
		TIMER->Timer7_CR_b.Timer7_InterruptMask |= TIM_TimeBaseInitStruct->TIM_Int_Mask;
		TIMER->Timer7_LoadCount_CR |= TIM_TimeBaseInitStruct->TIM_Count;
	}
}

void TIM_ITConfig(TIM_Channel TIMx_Chanel, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
		if(TIMx_Chanel == TIM_Channel_0) { TIMER->Timer0_CR_b.Timer0_InterruptMask &= TIM_INT_Not_Mask; }
		else if(TIMx_Chanel == TIM_Channel_1) { TIMER->Timer1_CR_b.Timer1_InterruptMask &= TIM_INT_Not_Mask; }
		else if(TIMx_Chanel == TIM_Channel_2) { TIMER->Timer2_CR_b.Timer2_InterruptMask &= TIM_INT_Not_Mask; }
		else if(TIMx_Chanel == TIM_Channel_3) { TIMER->Timer3_CR_b.Timer3_InterruptMask &= TIM_INT_Not_Mask; }
		else if(TIMx_Chanel == TIM_Channel_4) { TIMER->Timer4_CR_b.Timer4_InterruptMask &= TIM_INT_Not_Mask; }
		else if(TIMx_Chanel == TIM_Channel_5) { TIMER->Timer5_CR_b.Timer5_InterruptMask &= TIM_INT_Not_Mask; }
		else if(TIMx_Chanel == TIM_Channel_6) { TIMER->Timer6_CR_b.Timer6_InterruptMask &= TIM_INT_Not_Mask; }
		else if(TIMx_Chanel == TIM_Channel_7) { TIMER->Timer7_CR_b.Timer7_InterruptMask &= TIM_INT_Not_Mask; }		
    }
	else
	{
		if(TIMx_Chanel == TIM_Channel_0) { TIMER->Timer0_CR_b.Timer0_InterruptMask |= TIM_INT_Mask; }
		else if(TIMx_Chanel == TIM_Channel_1) { TIMER->Timer1_CR_b.Timer1_InterruptMask |= TIM_INT_Mask; }
		else if(TIMx_Chanel == TIM_Channel_2) { TIMER->Timer2_CR_b.Timer2_InterruptMask |= TIM_INT_Mask; }
		else if(TIMx_Chanel == TIM_Channel_3) { TIMER->Timer3_CR_b.Timer3_InterruptMask |= TIM_INT_Mask; }
		else if(TIMx_Chanel == TIM_Channel_4) { TIMER->Timer4_CR_b.Timer4_InterruptMask |= TIM_INT_Mask; }
		else if(TIMx_Chanel == TIM_Channel_5) { TIMER->Timer5_CR_b.Timer5_InterruptMask |= TIM_INT_Mask; }
		else if(TIMx_Chanel == TIM_Channel_6) { TIMER->Timer6_CR_b.Timer6_InterruptMask |= TIM_INT_Mask; }
		else if(TIMx_Chanel == TIM_Channel_7) { TIMER->Timer7_CR_b.Timer7_InterruptMask |= TIM_INT_Mask; }		
	}
}


void TIM_GetITStatus(TIM_Channel TIMx_Chanel)
{
	if (TIMx_Chanel == TIM_Channel_0)
		TIMER->Timer0_Int_SR_b.Timer0_Int;
	else if (TIMx_Chanel == TIM_Channel_1)
		TIMER->Timer1_Int_SR_b.Timer1_Int;
	else if (TIMx_Chanel == TIM_Channel_2)
		TIMER->Timer2_Int_SR_b.Timer2_Int;
	else if (TIMx_Chanel == TIM_Channel_3)
		TIMER->Timer3_Int_SR_b.Timer3_Int;
	else if (TIMx_Chanel == TIM_Channel_4)
		TIMER->Timer4_Int_SR_b.Timer4_Int;
	else if (TIMx_Chanel == TIM_Channel_5)
		TIMER->Timer5_Int_SR_b.Timer5_Int;
	else if (TIMx_Chanel == TIM_Channel_6)
		TIMER->Timer6_Int_SR_b.Timer6_Int;
	else if (TIMx_Chanel == TIM_Channel_7)
		TIMER->Timer7_Int_SR_b.Timer7_Int;
}

uint32_t TIM_EOIStatus(void)
{
	return TIMER->Timers_EOI_SR;

#if 0
	if(TIMx_Chanel == TIM_Channel_0) { return pTIM->Timer0_EOI_SR; }
	else if(TIMx_Chanel == TIM_Channel_1) { return pTIM->Timer1_EOI_SR; }
	else if(TIMx_Chanel == TIM_Channel_2) { return pTIM->Timer2_EOI_SR; }
	else if(TIMx_Chanel == TIM_Channel_3) { return pTIM->Timer3_EOI_SR; }
	else if(TIMx_Chanel == TIM_Channel_4) { return pTIM->Timer4_EOI_SR; }
	else if(TIMx_Chanel == TIM_Channel_5) { return pTIM->Timer5_EOI_SR; }
	else if(TIMx_Chanel == TIM_Channel_6) { return pTIM->Timer6_EOI_SR; }
	else if(TIMx_Chanel == TIM_Channel_7) { return pTIM->Timer7_EOI_SR; }	
#endif
	
}

void TIM_Cmd(TIM_Channel TIMx_Chanel, FunctionalState NewState)
{
	if (NewState != DISABLE)
	{
		if (TIMx_Chanel == TIM_Channel_0)
			TIMER->Timer0_CR_b.Timer0_En = ENABLE;
		else if (TIMx_Chanel == TIM_Channel_1)
			TIMER->Timer1_CR_b.Timer1_En = ENABLE;
		else if (TIMx_Chanel == TIM_Channel_2)
			TIMER->Timer2_CR_b.Timer2_En = ENABLE;
		else if (TIMx_Chanel == TIM_Channel_3)
			TIMER->Timer3_CR_b.Timer3_En = ENABLE;
		else if (TIMx_Chanel == TIM_Channel_4)
			TIMER->Timer4_CR_b.Timer4_En = ENABLE;
		else if (TIMx_Chanel == TIM_Channel_5)
			TIMER->Timer5_CR_b.Timer5_En = ENABLE;
		else if (TIMx_Chanel == TIM_Channel_6)
			TIMER->Timer6_CR_b.Timer6_En = ENABLE;
		else if (TIMx_Chanel == TIM_Channel_7)
			TIMER->Timer7_CR_b.Timer7_En = ENABLE;
	}
	else
	{
		if (TIMx_Chanel == TIM_Channel_0)
			TIMER->Timer0_CR_b.Timer0_En &= DISABLE;
		else if (TIMx_Chanel == TIM_Channel_1)
			TIMER->Timer1_CR_b.Timer1_En &= DISABLE;
		else if (TIMx_Chanel == TIM_Channel_2)
			TIMER->Timer2_CR_b.Timer2_En &= DISABLE;
		else if (TIMx_Chanel == TIM_Channel_3)
			TIMER->Timer3_CR_b.Timer3_En &= DISABLE;
		else if (TIMx_Chanel == TIM_Channel_4)
			TIMER->Timer4_CR_b.Timer4_En &= DISABLE;
		else if (TIMx_Chanel == TIM_Channel_5)
			TIMER->Timer5_CR_b.Timer5_En &= DISABLE;
		else if (TIMx_Chanel == TIM_Channel_6)
			TIMER->Timer6_CR_b.Timer6_En &= DISABLE;
		else if (TIMx_Chanel == TIM_Channel_7)
			TIMER->Timer7_CR_b.Timer7_En &= DISABLE;
	}
}

void TIM_GetCounter(TIM_Channel TIMx_Chanel)
{	
	if (TIMx_Chanel == TIM_Channel_0)
		(TIMER->Timer0_CurrentValue_SR);
	else if (TIMx_Chanel == TIM_Channel_1)
		(TIMER->Timer1_CurrentValue_SR);
	else if (TIMx_Chanel == TIM_Channel_2)
		(TIMER->Timer2_CurrentValue_SR);
	else if (TIMx_Chanel == TIM_Channel_3)
		(TIMER->Timer3_CurrentValue_SR);
	else if (TIMx_Chanel == TIM_Channel_4)
		(TIMER->Timer4_CurrentValue_SR);
	else if (TIMx_Chanel == TIM_Channel_5)
		(TIMER->Timer5_CurrentValue_SR);
	else if (TIMx_Chanel == TIM_Channel_6)
		(TIMER->Timer6_CurrentValue_SR);
	else if (TIMx_Chanel == TIM_Channel_7)
		(TIMER->Timer7_CurrentValue_SR);
}

void TIM_SetCounter(TIM_Channel TIMx_Chanel, uint32_t Cnt)
{
	if (TIMx_Chanel == TIM_Channel_0)
		TIMER->Timer0_LoadCount_CR = Cnt;
	else if (TIMx_Chanel == TIM_Channel_1)
		TIMER->Timer1_LoadCount_CR = Cnt;
	else if (TIMx_Chanel == TIM_Channel_2)
		TIMER->Timer2_LoadCount_CR = Cnt;
	else if (TIMx_Chanel == TIM_Channel_3)
		TIMER->Timer3_LoadCount_CR = Cnt;
	else if (TIMx_Chanel == TIM_Channel_4)
		TIMER->Timer4_LoadCount_CR = Cnt;
	else if (TIMx_Chanel == TIM_Channel_5)
		TIMER->Timer5_LoadCount_CR = Cnt;
	else if (TIMx_Chanel == TIM_Channel_6)
		TIMER->Timer6_LoadCount_CR = Cnt;
	else if (TIMx_Chanel == TIM_Channel_7)
		TIMER->Timer7_LoadCount_CR = Cnt;
}


void HAL_Timer_Init(void)
{
	// 12Mhz(TIMCLK) / 4 DIV = 3Mhz = 0.333us	
	// 1 Step Count = 333ns(0.333us)
	// ex) Count val: 3 code => 1us, 3000 code => 1ms, 300003 code => 100ms, 3000030 code => 1s
	Fncp_TIMER_IRQHandler = &TIMER_InterruptHandler;
	
	TIM_TimeBaseInitTypeDef TIM_Init;

	TIM_Init.TIM_Channel = TIM_Channel_0;
	TIM_Init.TIM_Count = 90000;	//30ms 
	TIM_Init.TIM_Mode = TIM_Mode_Count;
	TIM_Init.TIM_Int_Mask = TIM_INT_Mask_DISABLE;
	TIM_TimeBaseInit(&TIM_Init);

	NVIC_EnableIRQ (TIMER_IRQn);
	NVIC_SetPriority(TIMER_IRQn, TIMER_IRQn_Priority);
	
}

void HAL_Timer_Enable(TIM_Channel TIMx_Chanel, FunctionalState En)
{
	if (TIMx_Chanel == TIM_Channel_0)
		TIMER->Timer0_CR_b.Timer0_En = En;
	else if (TIMx_Chanel == TIM_Channel_1)
		TIMER->Timer1_CR_b.Timer1_En = En;
	else if (TIMx_Chanel == TIM_Channel_2)
		TIMER->Timer2_CR_b.Timer2_En = En;
	else if (TIMx_Chanel == TIM_Channel_3)
		TIMER->Timer3_CR_b.Timer3_En = En;
	else if (TIMx_Chanel == TIM_Channel_4)
		TIMER->Timer4_CR_b.Timer4_En = En;
	else if (TIMx_Chanel == TIM_Channel_5)
		TIMER->Timer5_CR_b.Timer5_En = En;
	else if (TIMx_Chanel == TIM_Channel_6)
		TIMER->Timer6_CR_b.Timer6_En = En;
	else if (TIMx_Chanel == TIM_Channel_7)
		TIMER->Timer7_CR_b.Timer7_En = En;
}

void HAL_Timer_Set_Count_us(TIM_Channel TIMx_Chanel, uint32_t Count)
{
	if (TIMx_Chanel == TIM_Channel_0)
		TIMER->Timer0_LoadCount_CR = 3*Count;
	else if (TIMx_Chanel == TIM_Channel_1)
		TIMER->Timer1_LoadCount_CR = 3*Count;
	else if (TIMx_Chanel == TIM_Channel_2)
		TIMER->Timer2_LoadCount_CR = 3*Count;
	else if (TIMx_Chanel == TIM_Channel_3)
		TIMER->Timer3_LoadCount_CR = 3*Count;
	else if (TIMx_Chanel == TIM_Channel_4)
		TIMER->Timer4_LoadCount_CR = 3*Count;
	else if (TIMx_Chanel == TIM_Channel_5)
		TIMER->Timer5_LoadCount_CR = 3*Count;
	else if (TIMx_Chanel == TIM_Channel_6)
		TIMER->Timer6_LoadCount_CR = 3*Count;
	else if (TIMx_Chanel == TIM_Channel_7)
		TIMER->Timer7_LoadCount_CR = 3*Count;
}

void HAL_Timer_Clear(void)
{
	TIM_DeInit(TIM_Channel_0);
}

void HAL_Timer_Start(void)
{
	TIM_Cmd(TIM_Channel_0, ENABLE);
}

void HAL_Timer_Get_Counter(void)
{
	TIM_GetCounter(TIM_Channel_0);
}

void HAL_Observe_Timer_Init(TIM_Channel TIMx_Chanel)
{
	// 12Mhz(TIMCLK) / 4 DIV = 3Mhz = 0.333us	
	// 1 Step Count = 333ns(0.333us)
	// ex) Count val: 3 code => 1us, 3000 code => 1ms, 300003 code => 100ms, 3000030 code => 1s
	
	TIM_TimeBaseInitTypeDef TIM_Init;

	TIM_Init.TIM_Channel = TIMx_Chanel;
	TIM_Init.TIM_Mode = TIM_Mode_Run;
	TIM_Init.TIM_Int_Mask = TIM_INT_Mask_EN;

	NVIC_EnableIRQ (TIMER_IRQn);
	NVIC_SetPriority(TIMER_IRQn, 0);	

	TIM_TimeBaseInit(&TIM_Init);
}

void HAL_Observe_Timer_Clear(TIM_Channel TIMx_Chanel)
{
	TIM_DeInit(TIMx_Chanel);
}

uint32_t HAL_Observe_Timer_Disable(TIM_Channel TIMx_Chanel)
{
#if 0
	TIM_GetCounter(TIMx_Chanel);
	TIM_Cmd(TIMx_Chanel, DISABLE);

	return (TIM_MAX_CNT_VAL - retval);
#endif
	return 0;
}

void HAL_Observe_Timer_Start(TIM_Channel TIMx_Chanel)
{
	TIM_Cmd(TIMx_Chanel, ENABLE);
}
