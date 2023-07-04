/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : gpio.c
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


#if USED_FRAME_SKIP_IDLE_MODE_CONTROL
extern uint8_t SkipFrameCnt;
#endif /* USED_FRAME_SKIP_IDLE_MODE_CONTROL */

void EXTI0_InterruptHandler(void)
{
#if USED_TSYNC2_INPUT_CONTROL
	if(GPIO->tGPIO_EXTI0_MIS._GPIO_TSYNC2_IN == 1)
	{
		GPIO->tGPIO_EXTI0_INTC._GPIO_TSYNC2_IN = 1;

		if(GPIO->tGPIO_DATA_1._GPIO_TSYNC2_IN == 1)
		{
#if 0//USED_ECLK_ON_OFF_CONTROL
			if(HAL_GetECLKOnOffControl())
			{
				HAL_ECLK_Off();
			}
#endif /* USED_ECLK_ON_OFF_CONTROL */

#if USED_MCU_IDLE_LOW_PWR_CONTROL
			// Touch Time
			if(IS_IDLE_MODE(HAL_GetSensingMode()))
			{
				Hal_Exit_MCU_Sleep();
			}
#endif /* USED_MCU_IDLE_LOW_PWR_CONTROL */
		}
		else
		{
#if USED_FRAME_SKIP_IDLE_MODE_CONTROL
			if (IS_IDLE_MODE(HAL_GetSensingMode()))
			{
				if(SkipFrameCnt == 0)
				{
#if USED_ECLK_ON_OFF_CONTROL
					if(HAL_GetECLKOnOffControl())
					{
						HAL_ECLK_On();
					}
#endif /* USED_ECLK_ON_OFF_CONTROL */
				}
				else
				{
#if 0//USED_ECLK_ON_OFF_CONTROL
					if(HAL_GetECLKOnOffControl())
					{
						HAL_ECLK_On();
					}
#endif /* USED_ECLK_ON_OFF_CONTROL */
				}
			}
			else
			{
//				if(SkipFrameCnt != 0)
				{
#if USED_ECLK_ON_OFF_CONTROL
					if(HAL_GetECLKOnOffControl())
					{
						HAL_ECLK_On();
					}
#endif /* USED_ECLK_ON_OFF_CONTROL */
				}
			}
#else
#if USED_ECLK_ON_OFF_CONTROL
			if(HAL_GetECLKOnOffControl())
			{
				HAL_ECLK_On();
			}
#endif /* USED_ECLK_ON_OFF_CONTROL */
#endif /* USED_FRAME_SKIP_IDLE_MODE_CONTROL */

#if USED_MCU_IDLE_LOW_PWR_CONTROL
			// Display Time
			if(IS_IDLE_MODE(HAL_GetSensingMode()))
			{
				Hal_Enter_MCU_Sleep();
			}
#endif /* USED_MCU_IDLE_LOW_PWR_CONTROL */
		}
	}
#endif /* USED_TSYNC2_INPUT_CONTROL */
}

void EXTI1_InterruptHandler(void)
{
}

tGPIO_CtrlReg_t * _DebugGPIO;
void GPIO_Initialize(void)
{
	_DebugGPIO = GPIO;
	Fncp_EXTI0_IRQHandler = &EXTI0_InterruptHandler;
	Fncp_EXTI1_IRQHandler = &EXTI1_InterruptHandler;
}

void init_EXITs(EXIT_Typedef* EXIT_InitStruct)
{
    uint64_t currentPin = EXIT_InitStruct->GPIO_Pin;
    uint32_t iPos;
    
    for ( iPos = 0 ; iPos < 50 ; iPos++)
    {
        if ( ( (currentPin>>iPos) & BIT0 ) != 0 ) 
        {
            if (iPos < 26){
				if (EXIT_InitStruct->LevelDetection == TRUE){
					SET_BIT( GPIO->tGPIO_EXTI0_IS.ulBulk, (BIT0 << iPos));
				}else{
					CLEAR_BIT( GPIO->tGPIO_EXTI0_IS.ulBulk, (BIT0 << iPos));
				}
				
				if (EXIT_InitStruct->BothEdge == TRUE){
					SET_BIT( GPIO->tGPIO_EXTI0_IBE.ulBulk, (BIT0 << iPos));
				}else{
					CLEAR_BIT( GPIO->tGPIO_EXTI0_IBE.ulBulk, (BIT0 << iPos));
				}
				
				if (EXIT_InitStruct->PositivePolarity == TRUE){
					SET_BIT( GPIO->tGPIO_EXTI0_IEV.ulBulk, (BIT0 << iPos));
				}else{
					CLEAR_BIT( GPIO->tGPIO_EXTI0_IEV.ulBulk, (BIT0 << iPos));
				}
				if (EXIT_InitStruct->EnableInterrupt == TRUE){
					SET_BIT( GPIO->tGPIO_EXTI0_IEV.ulBulk, (BIT0 << iPos));
				}else{
					CLEAR_BIT( GPIO->tGPIO_EXTI0_IEV.ulBulk, (BIT0 << iPos));
				}
			}else{
				if (EXIT_InitStruct->LevelDetection == TRUE){
					SET_BIT( GPIO->tGPIO_EXTI1_IS.ulBulk, (BIT0 << (iPos-26)));
				}else{
					CLEAR_BIT( GPIO->tGPIO_EXTI1_IS.ulBulk, (BIT0 << (iPos-26)));
				}
				
				if (EXIT_InitStruct->BothEdge == TRUE){
					SET_BIT( GPIO->tGPIO_EXTI1_IBE.ulBulk, (BIT0 << (iPos-26)));
				}else{
					CLEAR_BIT( GPIO->tGPIO_EXTI1_IBE.ulBulk, (BIT0 << (iPos-26)));
				}
				
				if (EXIT_InitStruct->PositivePolarity == TRUE){
					SET_BIT( GPIO->tGPIO_EXTI1_IEV.ulBulk, (BIT0 << (iPos-26)));
				}else{
					CLEAR_BIT( GPIO->tGPIO_EXTI1_IEV.ulBulk, (BIT0 << (iPos-26)));
				}
				if (EXIT_InitStruct->EnableInterrupt == TRUE){
					SET_BIT( GPIO->tGPIO_EXTI1_IEV.ulBulk, (BIT0 << (iPos-26)));
				}else{
					CLEAR_BIT( GPIO->tGPIO_EXTI1_IEV.ulBulk, (BIT0 << (iPos-26)));
				}
			}
        }
    }
}

void init_EXIT(EnumGPIO pin, uint8_t LevelDetection, uint8_t BothEdge, uint8_t PositivePolarity, uint8_t EnableInterrupt)
{
	if (pin < 12){
		if (LevelDetection == LEVEL_DETECTION_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI0_IS.ulBulk, (BIT0 << pin));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI0_IS.ulBulk, (BIT0 << pin));
		}
		
		if (BothEdge == BOTH_EDGE_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI0_IBE.ulBulk, (BIT0 << pin));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI0_IBE.ulBulk, (BIT0 << pin));
		}
		
		if (PositivePolarity == POSITIVE_HIGH_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI0_IEV.ulBulk, (BIT0 << pin));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI0_IEV.ulBulk, (BIT0 << pin));
		}
		if (EnableInterrupt == ENABLE_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI0_IE.ulBulk, (BIT0 << pin));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI0_IE.ulBulk, (BIT0 << pin));
		}
	}else if (pin < 24){
		if (LevelDetection == LEVEL_DETECTION_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI1_IS.ulBulk, (BIT0 << pin));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI1_IS.ulBulk, (BIT0 << pin));
		}
		
		if (BothEdge == BOTH_EDGE_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI1_IBE.ulBulk, (BIT0 << pin));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI1_IBE.ulBulk, (BIT0 << pin));
		}
		
		if (PositivePolarity == POSITIVE_HIGH_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI1_IEV.ulBulk, (BIT0 << pin));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI1_IEV.ulBulk, (BIT0 << pin));
		}
		if (EnableInterrupt == ENABLE_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI1_IE.ulBulk, (BIT0 << pin));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI1_IE.ulBulk, (BIT0 << pin));
		}
	}else if (pin < 38){
		if (LevelDetection == LEVEL_DETECTION_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI0_IS.ulBulk, (BIT0 << (pin-12)));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI0_IS.ulBulk, (BIT0 << (pin-12)));
		}
		
		if (BothEdge == BOTH_EDGE_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI0_IBE.ulBulk, (BIT0 << (pin-12)));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI0_IBE.ulBulk, (BIT0 << (pin-12)));
		}
		
		if (PositivePolarity == POSITIVE_HIGH_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI0_IEV.ulBulk, (BIT0 << (pin-12)));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI0_IEV.ulBulk, (BIT0 << (pin-12)));
		}
		if (EnableInterrupt == ENABLE_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI0_IE.ulBulk, (BIT0 << (pin-12)));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI0_IE.ulBulk, (BIT0 << (pin-12)));
		}
	}else if (pin < 50){
		if (LevelDetection == LEVEL_DETECTION_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI1_IS.ulBulk, (BIT0 << (pin-12)));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI1_IS.ulBulk, (BIT0 << (pin-12)));
		}
		
		if (BothEdge == BOTH_EDGE_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI0_IBE.ulBulk, (BIT1 << (pin-12)));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI0_IBE.ulBulk, (BIT1 << (pin-12)));
		}
		
		if (PositivePolarity == POSITIVE_HIGH_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI0_IEV.ulBulk, (BIT1 << (pin-12)));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI0_IEV.ulBulk, (BIT1 << (pin-12)));
		}
		if (EnableInterrupt == ENABLE_GPIO){
			SET_BIT( GPIO->tGPIO_EXTI0_IE.ulBulk, (BIT1 << (pin-12)));
		}else{
			CLEAR_BIT( GPIO->tGPIO_EXTI0_IE.ulBulk, (BIT1 << (pin-12)));
		}
	}
}

void writeBitToGPIO(EnumGPIO pin, EnumBit val)
{
 	if(pin  < 32)
 	{
 	   if (val == HIGH)
            SET_BIT(GPIO->tGPIO_DATA_0.ulBulk, BIT0 << pin);
        else
            CLEAR_BIT(GPIO->tGPIO_DATA_0.ulBulk, BIT0 << pin);
 	}
 	else
 	{
 		if (val == HIGH)
            SET_BIT(GPIO->tGPIO_DATA_1.ulBulk, BIT0 << (pin-32));
        else
            CLEAR_BIT(GPIO->tGPIO_DATA_1.ulBulk, BIT0 << (pin-32));
 	}
}

void initGPIOs(GPIO_InitTypeDef* GPIO_InitStruct)
{
    uint64_t currentPin = GPIO_InitStruct->GPIO_Pin;
    uint32_t iPos;

	for ( iPos = 0 ; iPos < 50 ; iPos++)
	{
		if ( ( (currentPin>>iPos) & BIT0 ) != 0 ) 
		{
			// AFIO_SEL [GPIO_SELx]
			if (iPos < 16)
			{
				CLEAR_BIT(GPIO->tGPIO_AFIO_0.ulBulk, (BIT1|BIT0) << iPos*2);
				SET_BIT(GPIO->tGPIO_AFIO_0.ulBulk , GPIO_InitStruct->GPIO_Mode << iPos*2);
			}
			else if(iPos < 32)
			{
				CLEAR_BIT(GPIO->tGPIO_AFIO_1.ulBulk, (BIT1|BIT0) << (iPos-16)*2);
				SET_BIT(GPIO->tGPIO_AFIO_1.ulBulk , GPIO_InitStruct->GPIO_Mode << (iPos-16)*2);
			}else if(iPos < 48){
				CLEAR_BIT(GPIO->tGPIO_AFIO_2.ulBulk, (BIT1|BIT0) << (iPos-32)*2);
				SET_BIT(GPIO->tGPIO_AFIO_2.ulBulk , GPIO_InitStruct->GPIO_Mode << (iPos-32)*2);
			}else{
				CLEAR_BIT(GPIO->tGPIO_AFIO_3.ulBulk, (BIT1|BIT0) << (iPos-48)*2);
				SET_BIT(GPIO->tGPIO_AFIO_3.ulBulk , GPIO_InitStruct->GPIO_Mode << (iPos-48)*2);
			}
			// IO Direction, Input Output [GPIO_DIRx]
			if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode0_GPIO)
			{
				if (GPIO_InitStruct->GPIO_Config == Input){
					if (iPos < 32){
						CLEAR_BIT(GPIO->tGPIO_DIR_0.ulBulk, BIT0 << iPos);
					}else{
						CLEAR_BIT(GPIO->tGPIO_DIR_1.ulBulk, BIT0 << (iPos-32));
					}
				}else {
					if (iPos < 32){
						SET_BIT(GPIO->tGPIO_DIR_0.ulBulk, BIT0 << iPos);
					}else{
						SET_BIT(GPIO->tGPIO_DIR_1.ulBulk, BIT0 << (iPos-32));
					}
				}
			}
			// Pull-Up Control [GPIO_PUPx]            
			if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode0_GPIO)
			{
				if (GPIO_InitStruct->GPIO_Config == PullupIn){
					if (iPos < 32){
						SET_BIT(GPIO->tGPIO_PU_0.ulBulk, BIT0 << iPos);
					}else{
						SET_BIT(GPIO->tGPIO_PU_1.ulBulk, BIT0 << (iPos-32));
					}
				}else{
					if (iPos < 32){
						CLEAR_BIT(GPIO->tGPIO_PU_0.ulBulk, BIT0 << iPos);
					}else{
						CLEAR_BIT(GPIO->tGPIO_PU_1.ulBulk, BIT0 << (iPos-32));
					}
				}
			}
		}
	}
}

void initGPIO(EnumGPIO pin, GpModeValue_TypeDef GPIO_Mode, GpIoconValue_TypeDef GPIO_Config)
{
	// AFIO_SEL [GPIO_SELx]
	if (pin < 16)
	{
		CLEAR_BIT(GPIO->tGPIO_AFIO_0.ulBulk, (BIT1|BIT0) << pin*2);
		SET_BIT(GPIO->tGPIO_AFIO_0.ulBulk , GPIO_Mode << pin*2);
	}
	else if(pin < 32)
	{
		CLEAR_BIT(GPIO->tGPIO_AFIO_1.ulBulk, (BIT1|BIT0) << (pin-16)*2);
		SET_BIT(GPIO->tGPIO_AFIO_1.ulBulk , GPIO_Mode << (pin-16)*2);
	}else if(pin < 48){
		CLEAR_BIT(GPIO->tGPIO_AFIO_2.ulBulk, (BIT1|BIT0) << (pin-32)*2);
		SET_BIT(GPIO->tGPIO_AFIO_2.ulBulk , GPIO_Mode << (pin-32)*2);
	}else{
		CLEAR_BIT(GPIO->tGPIO_AFIO_3.ulBulk, (BIT1|BIT0) << (pin-48)*2);
		SET_BIT(GPIO->tGPIO_AFIO_3.ulBulk , GPIO_Mode << (pin-48)*2);
	}
	// IO Direction, Input Output [GPIO_DIRx]
	if (GPIO_Mode == GPIO_Mode0_GPIO)
	{
		if ((GPIO_Config == Input)|(GPIO_Config == PullupIn)){
			if (pin < 32){
				CLEAR_BIT(GPIO->tGPIO_DIR_0.ulBulk, BIT0 << pin);
			}else{
				CLEAR_BIT(GPIO->tGPIO_DIR_1.ulBulk, BIT0 << (pin-32));
			}
		}else {
			if (pin < 32){
				SET_BIT(GPIO->tGPIO_DIR_0.ulBulk, BIT0 << pin);
			}else{
				SET_BIT(GPIO->tGPIO_DIR_1.ulBulk, BIT0 << (pin-32));
			}
		}
	}
	// Pull-Up Control [GPIO_PUPx]            
	if (GPIO_Mode == GPIO_Mode0_GPIO)
	{
		if (GPIO_Config == PullupIn){
			if (pin < 32){
				SET_BIT(GPIO->tGPIO_PU_0.ulBulk, BIT0 << pin);
			}else{
				SET_BIT(GPIO->tGPIO_PU_1.ulBulk, BIT0 << (pin-32));
			}
		}else{
			if (pin < 32){
				CLEAR_BIT(GPIO->tGPIO_PU_0.ulBulk, BIT0 << pin);
			}else{
				CLEAR_BIT(GPIO->tGPIO_PU_1.ulBulk, BIT0 << (pin-32));
			}
		}
	}
}

/*
 * 이 밑에다 Function선언 하지 말자!!
 */
#if USED_GPIO_TEST_HANDSHAKE
#pragma O0

void _____TEST_GPB09_HandShake(uint32_t ulNum, uint32_t ulusecDelay)
{
	uint32_t i;
	for(i = 0; i < ulNum; i++)
	{
		GPIO->tGPIO_DATA_1.tBit.GPB09 = 1;
		delay_usec(ulusecDelay);
		GPIO->tGPIO_DATA_1.tBit.GPB09 = 0;
		delay_usec(ulusecDelay);
	}
}
#endif /* USED_GPIO_TEST_HANDSHAKE */
