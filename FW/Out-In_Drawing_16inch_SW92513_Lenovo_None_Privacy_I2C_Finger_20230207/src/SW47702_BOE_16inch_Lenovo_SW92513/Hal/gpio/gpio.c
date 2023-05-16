/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : gpio.c
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

void GPIOA_InterruptHandler(void)
{
	if (GPIO->GPIO_INTEN.tBit.GPIOA == 1)
	{
#if USED_TSYNC2_INPUT_FROM_TCON
		if(IS_GPIO_PIN(_GPIO_TSYNC_2_IN) == GPIO_DATA_LOW)
		{
	#if USED_ECLK_ON_OFF_CONTROL
			if(HAL_GetECLKOnOffControl())
			{
				HAL_ECLK_On();
			}
	#endif /* #if USED_ECLK_ON_OFF_CONTROL */

	#if USED_TPIC_MUXEN_ON_OFF_CONTROL
			eActivePenType_t ePenType = hal_Info_GetControlActivePenOPType();
			eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();

			switch(ePenType)
			{
				case ACTIVEPEN_TYPE_LOCAL_MS:
				{
					if(HAL_GetTPICMuxEnControl())
					{
						if(IS_FINGER_PEN_MODE(eSensingMode))
						{
							if(IS_ACTIVE_MODE(eSensingMode))
							{
								if (tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 2 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 3 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 4 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 5 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 6 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 9 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 13)
								{
									GPIO_Set_DATA(_GPIO_MUX_EN_TPIC, GPIO_DATA_HIGH);
								}

								if (tHalIntrHandle.ulTSyncInFallingCnt == 0 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 8 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 10 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 11 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 12 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 14 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 15)
								{
									GPIO_Set_DATA(_GPIO_MUX_EN_TPIC, GPIO_DATA_HIGH);
		#if USED_TPIC_MUXEN_2_ON_OFF_CONTROL
									GPIO_Set_DATA(_GPIO_MUX_EN2_TPIC, GPIO_DATA_HIGH);
		#endif /* USED_TPIC_MUXEN_2_ON_OFF_CONTROL */
								}
							}
							else
							{
								if (tHalIntrHandle.ulTSyncInFallingCnt == 0 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 1)
								{
									GPIO_Set_DATA(_GPIO_MUX_EN_TPIC, GPIO_DATA_HIGH);
		#if USED_TPIC_MUXEN_2_ON_OFF_CONTROL
									GPIO_Set_DATA(_GPIO_MUX_EN2_TPIC, GPIO_DATA_HIGH);
		#endif /* USED_TPIC_MUXEN_2_ON_OFF_CONTROL */
								}
							}
						}
						else /* Full Mode */
						{
							/*
							 * Not Implementation
							 */
						}
					}
					break;
				}
				case ACTIVEPEN_TYPE_LOCAL_WACOM:
				{
					/*
					 * Not Implementation
					 */
					break;
				}
				case ACTIVEPEN_TYPE_LOCAL_WGP:
				{
					/*
					 * Not Implementation
					 */
					break;
				}
			}
	#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
		}
#endif /* USED_TSYNC2_INPUT_FROM_TCON */
		GPIO->GPIO_INTCLEAR.tBit.GPIOA = 1;
	}
}

void GPIOM_InterruptHandler(void)
{
	if (GPIO->GPIO_INTEN.tBit.GPIOM == 1)
	{
#if USED_S3_SIGNAL_OUTPUT_CTRL_IN_S3POWER_INTR
		if(IS_GPIO_PIN(_GPIO_S3_POWER_IN) == GPIO_DATA_HIGH)
		{
			GPIO_Set_DATA(_GPIO_S3_SIGNAL_OUT, GPIO_DATA_LOW);
		}
		else
		{
			GPIO_Set_DATA(_GPIO_S3_SIGNAL_OUT, GPIO_DATA_HIGH);
		}
#endif /* USED_S3_SIGNAL_OUTPUT_CTRL_IN_S3POWER_INTR */

#if USED_TOUCH_SLEEP_CTRL_BY_HOST
		if(IS_GPIO_PIN(_GPIO_SLEEP_EN) == GPIO_DATA_HIGH)
		{
			tHalIntrHandle.ulTouchSleepGPIOIntr_Flag = YES;
		}
		else
		{
			tHalIntrHandle.ulTouchSleepGPIOIntr_Flag = YES;
		}
#endif /* USED_TOUCH_SLEEP_CTRL_BY_HOST */

		GPIO->GPIO_INTCLEAR.tBit.GPIOM = 1;
	}
}

void GPIO_Initialize(void)
{
	Fncp_GPIOA_IRQHandler = &GPIOA_InterruptHandler;
	Fncp_GPIOM_IRQHandler = &GPIOM_InterruptHandler;
#if USED_TSYNC2_INPUT_FROM_TCON
	GPIO_Set_INT(_GPIO_TSYNC_2_IN, GPIO_INTEN_ENABLE, GPIO_INTTYPE_FALLING_EDGE);
#endif /* USED_TSYNC2_INPUT_FROM_TCON */
}

void GPIO_Init(GPIOPin_TypeDef GPIOx, GPIOFunc_TypeDef mode, GPIODIR_TypeDef dir, GPIODATA_TypeDef data)
{
	if (mode != GPIO_MODE_FUNC_NONE)
		GPIO_Set_Mode(GPIOx, mode); // Set funtion mode
	if (dir != GPIO_DIR_NONE)
		GPIO_Set_Dir(GPIOx, dir); // Set direction (IN/OUT)
	if (data != GPIO_DATA_NONE)
		GPIO_Set_DATA(GPIOx, data); // Set status (LOW/HIGH)
}

void GPIO_Set_Mode(GPIOPin_TypeDef GPIOx, GPIOFunc_TypeDef mode)
{
	uint32_t ulShiftIdx;
	switch (GPIOx)
	{
		case GPIO_M00: case GPIO_M01: case GPIO_M02: case GPIO_M03:
		case GPIO_M04: case GPIO_M05: case GPIO_M06: case GPIO_M07:
		case GPIO_M08: case GPIO_M09: case GPIO_M10:
		{
			ulShiftIdx = GPIOx<<1;
			GPIO->GPIOM_FUNC.w = (GPIO->GPIOM_FUNC.w & ~(0x3 << ulShiftIdx)) | ((0x3&mode) << ulShiftIdx);
			break;
		}
		case GPIO_A00: case GPIO_A01: case GPIO_A02: case GPIO_A03:
		case GPIO_A04: case GPIO_A05: case GPIO_A06: case GPIO_A07:
		case GPIO_A08: case GPIO_A09: case GPIO_A10: case GPIO_A11:
		case GPIO_A12: case GPIO_A13: case GPIO_A14: case GPIO_A15:
		{
			ulShiftIdx = (GPIOx-GPIO_A00)<<1;
			GPIO->GPIOALL_FUNC.w = (GPIO->GPIOALL_FUNC.w & ~(0x3 << ulShiftIdx)) | ((0x3&mode) << ulShiftIdx);
			break;
		}
		case GPIO_A16: case GPIO_A17: case GPIO_A18: case GPIO_A19:
		case GPIO_A20: case GPIO_A21: case GPIO_A22: case GPIO_A23:
		case GPIO_A24: case GPIO_A25: case GPIO_A26: case GPIO_A27:
		case GPIO_A28: case GPIO_A29: case GPIO_A30: case GPIO_A31:
		{
			ulShiftIdx = (GPIOx-GPIO_A16)<<1;
			GPIO->GPIOALH_FUNC.w = (GPIO->GPIOALH_FUNC.w & ~(0x3 << ulShiftIdx)) | ((0x3&mode) << ulShiftIdx);
			break;
		}
		case GPIO_A32: case GPIO_A33: case GPIO_A34: case GPIO_A35:
		case GPIO_A36: case GPIO_A37: case GPIO_A38: case GPIO_A39:
		case GPIO_A40: case GPIO_A41: case GPIO_A42: case GPIO_A43:
		case GPIO_A44: case GPIO_A45:
		{
			ulShiftIdx = (GPIOx-GPIO_A32)<<1;
			GPIO->GPIOAH_FUNC.w = (GPIO->GPIOAH_FUNC.w & ~(0x3 << ulShiftIdx)) | ((0x3&mode) << ulShiftIdx);
			break;
		}
		default:
			break;
	}
}

void GPIO_Set_Dir(GPIOPin_TypeDef GPIOx, GPIODIR_TypeDef dir)
{
	uint32_t ulShiftIdx;
	switch (GPIOx)
	{
		case GPIO_M00: case GPIO_M01: case GPIO_M02: case GPIO_M03:
		case GPIO_M04: case GPIO_M05: case GPIO_M06: case GPIO_M07:
		case GPIO_M08: case GPIO_M09: case GPIO_M10:
		{
			ulShiftIdx = GPIOx;
			GPIO->GPIOM_OEN.w = (GPIO->GPIOM_OEN.w & ~(0x1 << ulShiftIdx)) | ((0x1 & dir) << ulShiftIdx);
			break;
		}
		case GPIO_A00: case GPIO_A01: case GPIO_A02: case GPIO_A03:
		case GPIO_A04: case GPIO_A05: case GPIO_A06: case GPIO_A07:
		case GPIO_A08: case GPIO_A09: case GPIO_A10: case GPIO_A11:
		case GPIO_A12: case GPIO_A13: case GPIO_A14: case GPIO_A15:
		case GPIO_A16: case GPIO_A17: case GPIO_A18: case GPIO_A19:
		case GPIO_A20: case GPIO_A21: case GPIO_A22: case GPIO_A23:
		case GPIO_A24: case GPIO_A25: case GPIO_A26: case GPIO_A27:
		case GPIO_A28: case GPIO_A29: case GPIO_A30: case GPIO_A31:
		{
			ulShiftIdx = GPIOx - GPIO_A00;
			GPIO->GPIOAL_OEN.w = (GPIO->GPIOAL_OEN.w & ~(0x1 << ulShiftIdx)) | ((0x1 & dir) << ulShiftIdx);
			break;
		}
		case GPIO_A32: case GPIO_A33: case GPIO_A34: case GPIO_A35:
		case GPIO_A36: case GPIO_A37: case GPIO_A38: case GPIO_A39:
		case GPIO_A40: case GPIO_A41: case GPIO_A42: case GPIO_A43:
		case GPIO_A44: case GPIO_A45:
		{
			ulShiftIdx = GPIOx - GPIO_A32;
			GPIO->GPIOAH_OEN.w = (GPIO->GPIOAH_OEN.w & ~(0x1 << ulShiftIdx)) | ((0x1 & dir) << ulShiftIdx);
			break;
		}
		default:
			break;
	}

}

void GPIO_Set_DATA(GPIOPin_TypeDef GPIOx, GPIODATA_TypeDef data)
{
	uint32_t ulShiftIdx;
	switch (GPIOx)
	{
		case GPIO_M00: case GPIO_M01: case GPIO_M02: case GPIO_M03:
		case GPIO_M04: case GPIO_M05: case GPIO_M06: case GPIO_M07:
		case GPIO_M08: case GPIO_M09: case GPIO_M10:
			ulShiftIdx = GPIOx;
			GPIO->GPIOM_OUT.w = (GPIO->GPIOM_OUT.w & ~(0x1 << ulShiftIdx)) | ((0x1 & data) << ulShiftIdx);
			break;
		case GPIO_A00: case GPIO_A01: case GPIO_A02: case GPIO_A03:
		case GPIO_A04: case GPIO_A05: case GPIO_A06: case GPIO_A07:
		case GPIO_A08: case GPIO_A09: case GPIO_A10: case GPIO_A11:
		case GPIO_A12: case GPIO_A13: case GPIO_A14: case GPIO_A15:
		case GPIO_A16: case GPIO_A17: case GPIO_A18: case GPIO_A19:
		case GPIO_A20: case GPIO_A21: case GPIO_A22: case GPIO_A23:
		case GPIO_A24: case GPIO_A25: case GPIO_A26: case GPIO_A27:
		case GPIO_A28: case GPIO_A29: case GPIO_A30: case GPIO_A31:
			ulShiftIdx = GPIOx - GPIO_A00;
			GPIO->GPIOAL_OUT.w = (GPIO->GPIOAL_OUT.w & ~(0x1 << ulShiftIdx)) | ((0x1 & data) << ulShiftIdx);
			break;
		case GPIO_A32: case GPIO_A33: case GPIO_A34: case GPIO_A35:
		case GPIO_A36: case GPIO_A37: case GPIO_A38: case GPIO_A39:
		case GPIO_A40: case GPIO_A41: case GPIO_A42: case GPIO_A43:
		case GPIO_A44: case GPIO_A45:
			ulShiftIdx = GPIOx - GPIO_A32;
			GPIO->GPIOAH_OUT.w = (GPIO->GPIOAH_OUT.w & ~(0x1 << ulShiftIdx)) | ((0x1 & data) << ulShiftIdx);
			break;

		default:
			break;
	}

}

void GPIO_Set_PE(GPIOPin_TypeDef GPIOx, GPIOPE_TypeDef pe)
{
	uint32_t ulShiftIdx;
	switch (GPIOx)
	{
		case GPIO_M00: case GPIO_M01: case GPIO_M02: case GPIO_M03:
		case GPIO_M04: case GPIO_M05: case GPIO_M06: case GPIO_M07:
		case GPIO_M08: case GPIO_M09: case GPIO_M10:
		{
			ulShiftIdx = GPIOx<<1;
			GPIO->GPIOM_PE.w = (GPIO->GPIOM_PE.w & ~(0x3 << ulShiftIdx)) | ((0x3&pe) << ulShiftIdx);
			break;
		}
		case GPIO_A00: case GPIO_A01: case GPIO_A02: case GPIO_A03:
		case GPIO_A04: case GPIO_A05: case GPIO_A06: case GPIO_A07:
		case GPIO_A08: case GPIO_A09: case GPIO_A10: case GPIO_A11:
		case GPIO_A12: case GPIO_A13: case GPIO_A14: case GPIO_A15:
		{
			ulShiftIdx = (GPIOx-GPIO_A00)<<1;
			GPIO->GPIOALL_PE.w = (GPIO->GPIOALL_PE.w & ~(0x3 << ulShiftIdx)) | ((0x3&pe) << ulShiftIdx);
			break;
		}
		case GPIO_A16: case GPIO_A17: case GPIO_A18: case GPIO_A19:
		case GPIO_A20: case GPIO_A21: case GPIO_A22: case GPIO_A23:
		case GPIO_A24: case GPIO_A25: case GPIO_A26: case GPIO_A27:
		case GPIO_A28: case GPIO_A29: case GPIO_A30: case GPIO_A31:
		{
			ulShiftIdx = (GPIOx-GPIO_A16)<<1;
			GPIO->GPIOALH_PE.w = (GPIO->GPIOALH_PE.w & ~(0x3 << ulShiftIdx)) | ((0x3&pe) << ulShiftIdx);
			break;
		}
		case GPIO_A32: case GPIO_A33: case GPIO_A34: case GPIO_A35:
		case GPIO_A36: case GPIO_A37: case GPIO_A38: case GPIO_A39:
		case GPIO_A40: case GPIO_A41: case GPIO_A42: case GPIO_A43:
		case GPIO_A44: case GPIO_A45:
		{
			ulShiftIdx = (GPIOx-GPIO_A32)<<1;
			GPIO->GPIOAH_PE.w = (GPIO->GPIOAH_PE.w & ~(0x3 << ulShiftIdx)) | ((0x3&pe) << ulShiftIdx);
			break;
		}
		default:
			break;
	}
}

void GPIO_Set_DS(GPIOPin_TypeDef GPIOx, GPIODS_TypeDef ds)
{
	uint32_t ulShiftIdx;
	switch (GPIOx)
	{
		case GPIO_M00: case GPIO_M01: case GPIO_M02: case GPIO_M03:
		case GPIO_M04: case GPIO_M05: case GPIO_M06: case GPIO_M07:
		case GPIO_M08: case GPIO_M09: case GPIO_M10:
		{
			ulShiftIdx = GPIOx<<1;
			GPIO->GPIOM_DS.w = (GPIO->GPIOM_DS.w & ~(0x3 << ulShiftIdx)) | ((0x3&ds) << ulShiftIdx);
			break;
		}
		case GPIO_A00: case GPIO_A01: case GPIO_A02: case GPIO_A03:
		case GPIO_A04: case GPIO_A05: case GPIO_A06: case GPIO_A07:
		case GPIO_A08: case GPIO_A09: case GPIO_A10: case GPIO_A11:
		case GPIO_A12: case GPIO_A13: case GPIO_A14: case GPIO_A15:
		{
			ulShiftIdx = (GPIOx-GPIO_A00)<<1;
			GPIO->GPIOALL_DS.w = (GPIO->GPIOALL_DS.w & ~(0x3 << ulShiftIdx)) | ((0x3&ds) << ulShiftIdx);
			break;
		}
		case GPIO_A16: case GPIO_A17: case GPIO_A18: case GPIO_A19:
		case GPIO_A20: case GPIO_A21: case GPIO_A22: case GPIO_A23:
		case GPIO_A24: case GPIO_A25: case GPIO_A26: case GPIO_A27:
		case GPIO_A28: case GPIO_A29: case GPIO_A30: case GPIO_A31:
		{
			ulShiftIdx = (GPIOx-GPIO_A16)<<1;
			GPIO->GPIOALH_DS.w = (GPIO->GPIOALH_DS.w & ~(0x3 << ulShiftIdx)) | ((0x3&ds) << ulShiftIdx);
			break;
		}
		case GPIO_A32: case GPIO_A33: case GPIO_A34: case GPIO_A35:
		case GPIO_A36: case GPIO_A37: case GPIO_A38: case GPIO_A39:
		case GPIO_A40: case GPIO_A41: case GPIO_A42: case GPIO_A43:
		case GPIO_A44: case GPIO_A45:
		{
			ulShiftIdx = (GPIOx-GPIO_A32)<<1;
			GPIO->GPIOAH_DS.w = (GPIO->GPIOAH_DS.w & ~(0x3 << ulShiftIdx)) | ((0x3&ds) << ulShiftIdx);
			break;
		}
		default:
			break;
	}
}

bool_t GPIO_Get_IN(GPIOPin_TypeDef GPIOx)
{
	bool_t retval;
	uint32_t ulShiftIdx;

	switch (GPIOx)
	{
		case GPIO_M00: case GPIO_M01: case GPIO_M02: case GPIO_M03:
		case GPIO_M04: case GPIO_M05: case GPIO_M06: case GPIO_M07:
		case GPIO_M08: case GPIO_M09: case GPIO_M10:
		{
			ulShiftIdx = GPIOx;
			retval = (GPIO->GPIOM_IN.w >> ulShiftIdx) & 0x1;
			break;
		}
		case GPIO_A00: case GPIO_A01: case GPIO_A02: case GPIO_A03:
		case GPIO_A04: case GPIO_A05: case GPIO_A06: case GPIO_A07:
		case GPIO_A08: case GPIO_A09: case GPIO_A10: case GPIO_A11:
		case GPIO_A12: case GPIO_A13: case GPIO_A14: case GPIO_A15:
		case GPIO_A16: case GPIO_A17: case GPIO_A18: case GPIO_A19:
		case GPIO_A20: case GPIO_A21: case GPIO_A22: case GPIO_A23:
		case GPIO_A24: case GPIO_A25: case GPIO_A26: case GPIO_A27:
		case GPIO_A28: case GPIO_A29: case GPIO_A30: case GPIO_A31:
		{
			ulShiftIdx = GPIOx - GPIO_A00;
			retval = (GPIO->GPIOAL_IN.w >> ulShiftIdx) & 0x1;
			break;
		}
		case GPIO_A32: case GPIO_A33: case GPIO_A34: case GPIO_A35:
		case GPIO_A36: case GPIO_A37: case GPIO_A38: case GPIO_A39:
		case GPIO_A40: case GPIO_A41: case GPIO_A42: case GPIO_A43:
		case GPIO_A44: case GPIO_A45:
		{
			ulShiftIdx = GPIOx - GPIO_A32;
			retval = (GPIO->GPIOAH_IN.w >> ulShiftIdx) & 0x1;
			break;
		}
		default:
			break;
	}

	return retval;
}

bool_t GPIO_Get_OUT(GPIOPin_TypeDef GPIOx)	/* Used only output mode */
{
	bool_t retval;
	uint32_t ulShiftIdx;

	switch (GPIOx)
	{
		case GPIO_M00: case GPIO_M01: case GPIO_M02: case GPIO_M03:
		case GPIO_M04: case GPIO_M05: case GPIO_M06: case GPIO_M07:
		case GPIO_M08: case GPIO_M09: case GPIO_M10:
		{
			ulShiftIdx = GPIOx;
			retval = (GPIO->GPIOM_OUT.w >> ulShiftIdx) & 0x1;
			break;
		}
		case GPIO_A00: case GPIO_A01: case GPIO_A02: case GPIO_A03:
		case GPIO_A04: case GPIO_A05: case GPIO_A06: case GPIO_A07:
		case GPIO_A08: case GPIO_A09: case GPIO_A10: case GPIO_A11:
		case GPIO_A12: case GPIO_A13: case GPIO_A14: case GPIO_A15:
		case GPIO_A16: case GPIO_A17: case GPIO_A18: case GPIO_A19:
		case GPIO_A20: case GPIO_A21: case GPIO_A22: case GPIO_A23:
		case GPIO_A24: case GPIO_A25: case GPIO_A26: case GPIO_A27:
		case GPIO_A28: case GPIO_A29: case GPIO_A30: case GPIO_A31:
		{
			ulShiftIdx = GPIOx - GPIO_A00;
			retval = (GPIO->GPIOAL_OUT.w >> ulShiftIdx) & 0x1;
			break;
		}
		case GPIO_A32: case GPIO_A33: case GPIO_A34: case GPIO_A35:
		case GPIO_A36: case GPIO_A37: case GPIO_A38: case GPIO_A39:
		case GPIO_A40: case GPIO_A41: case GPIO_A42: case GPIO_A43:
		case GPIO_A44: case GPIO_A45:
		{
			ulShiftIdx = GPIOx - GPIO_A32;
			retval = (GPIO->GPIOAH_OUT.w >> ulShiftIdx) & 0x1;
			break;
		}
		default:
			break;
	}

	return retval;
}

void GPIO_Set_INT(GPIOPin_TypeDef GPIOx, GPIOINTEN_TypeDef En, GPIOINTType_TypeDef type)
{
	uint32_t ulShiftIdx;
	IRQn_Type eIRQ_Type;
	switch (GPIOx)
	{
		case GPIO_M00: case GPIO_M01: case GPIO_M02: case GPIO_M03:
		case GPIO_M04: case GPIO_M05: case GPIO_M06: case GPIO_M07:
		case GPIO_M08: case GPIO_M09: case GPIO_M10:
		{
			ulShiftIdx = GPIOx<<1;
			GPIO->GPIOM_INTTYPE.w = (GPIO->GPIOM_INTTYPE.w & ~(0x3 << ulShiftIdx)) | ((0x3&type) << ulShiftIdx);
			break;
		}
		case GPIO_A00: case GPIO_A01: case GPIO_A02: case GPIO_A03:
		case GPIO_A04: case GPIO_A05: case GPIO_A06: case GPIO_A07:
		case GPIO_A08: case GPIO_A09: case GPIO_A10: case GPIO_A11:
		case GPIO_A12: case GPIO_A13: case GPIO_A14: case GPIO_A15:
		{
			ulShiftIdx = (GPIOx - GPIO_A00)<<1;
			GPIO->GPIOALL_INTTYPE.w = (GPIO->GPIOALL_INTTYPE.w & ~(0x3 << ulShiftIdx)) | ((0x3&type) << ulShiftIdx);
			break;
		}
		case GPIO_A16: case GPIO_A17: case GPIO_A18: case GPIO_A19:
		case GPIO_A20: case GPIO_A21: case GPIO_A22: case GPIO_A23:
		case GPIO_A24: case GPIO_A25: case GPIO_A26: case GPIO_A27:
		case GPIO_A28: case GPIO_A29: case GPIO_A30: case GPIO_A31:
		{
			ulShiftIdx = (GPIOx - GPIO_A16)<<1;
			GPIO->GPIOALH_INTTYPE.w = (GPIO->GPIOALH_INTTYPE.w & ~(0x3 << ulShiftIdx)) | ((0x3&type) << ulShiftIdx);
			break;
		}
		case GPIO_A32: case GPIO_A33: case GPIO_A34: case GPIO_A35:
		case GPIO_A36: case GPIO_A37: case GPIO_A38: case GPIO_A39:
		case GPIO_A40: case GPIO_A41: case GPIO_A42: case GPIO_A43:
		case GPIO_A44: case GPIO_A45:
		{
			ulShiftIdx = (GPIOx - GPIO_A32)<<1;
			GPIO->GPIOAH_INTTYPE.w = (GPIO->GPIOAH_INTTYPE.w & ~(0x3 << ulShiftIdx)) | ((0x3&type) << ulShiftIdx);
			break;
		}
		default:
			break;
	}

	if(GPIOx <= GPIO_M10)
	{
		eIRQ_Type = GPIOM_IRQn;
		ulShiftIdx = 0;
	}
	else
	{
		eIRQ_Type = GPIOA_IRQn;
		ulShiftIdx = 1;
	}

	GPIO->GPIO_INTEN.w = (GPIO->GPIO_INTEN.w & ~(0x1 << ulShiftIdx)) | ((0x1 & En) << ulShiftIdx);
	NVIC_ClearPendingIRQ(eIRQ_Type);
	NVIC_SetPriority(eIRQ_Type, GPIOM_IRQn_Priority);
	if(En == GPIO_INTEN_ENABLE)
	{
		NVIC_EnableIRQ(eIRQ_Type);
	}
	else
	{
		GPIO->GPIO_INTEN.tBit.GPIOM = GPIO_INTEN_DISABLE;
		NVIC_DisableIRQ(eIRQ_Type);
	}
}

void GPIO_Toggle(GPIOPin_TypeDef GPIOx)
{
	GPIO_Set_DATA(GPIOx, (GPIODATA_TypeDef)!GPIO_Get_OUT(GPIOx));
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
