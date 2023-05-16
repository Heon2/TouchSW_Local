/****************************************************************************************************//**
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
#if USED_VCF_SYNC_CONTROL
		if(IS_GPIO_PIN(_GPIO_PRIVACY_EN) == GPIO_DATA_HIGH)
		{
			HAL_SetPrivacyEnControl(YES);
		}
		else
		{
			HAL_SetPrivacyEnControl(NO);
			GPIO_Set_DATA(_GPIO_VCF_SYNC, GPIO_DATA_LOW);
			GPIO_Set_DATA(_GPIO_DISCHG_SYNC, GPIO_DATA_LOW);
		}
#endif /* USED_VCF_SYNC_CONTROL */
		
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
#if USED_VCF_SYNC_CONTROL
	GPIO_Set_INT(_GPIO_PRIVACY_EN, GPIO_INTEN_ENABLE, GPIO_INTTYPE_BOTH_EDGE);
#endif /* USED_VCF_SYNC_CONTROL */
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
	switch (GPIOx)
	{
		case GPIO_M00:
			GPIO->GPIOM_FUNC.tBit.GPIOM00 = mode;
			break;
		case GPIO_M01:
			GPIO->GPIOM_FUNC.tBit.GPIOM01 = mode;
			break;
		case GPIO_M02:
			GPIO->GPIOM_FUNC.tBit.GPIOM02 = mode;
			break;
		case GPIO_M03:
			GPIO->GPIOM_FUNC.tBit.GPIOM03 = mode;
			break;
		case GPIO_M04:
			GPIO->GPIOM_FUNC.tBit.GPIOM04 = mode;
			break;
		case GPIO_M05:
			GPIO->GPIOM_FUNC.tBit.GPIOM05 = mode;
			break;
		case GPIO_M06:
			GPIO->GPIOM_FUNC.tBit.GPIOM06 = mode;
			break;
		case GPIO_M07:
			GPIO->GPIOM_FUNC.tBit.GPIOM07 = mode;
			break;
		case GPIO_M08:
			GPIO->GPIOM_FUNC.tBit.GPIOM08 = mode;
			break;
		case GPIO_M09:
			GPIO->GPIOM_FUNC.tBit.GPIOM09 = mode;
			break;
		case GPIO_M10:
			GPIO->GPIOM_FUNC.tBit.GPIOM10 = mode;
			break;
		case GPIO_A00:
			GPIO->GPIOALL_FUNC.tBit.GPIOA00 = mode;
			break;
		case GPIO_A01:
			GPIO->GPIOALL_FUNC.tBit.GPIOA01 = mode;
			break;
		case GPIO_A02:
			GPIO->GPIOALL_FUNC.tBit.GPIOA02 = mode;
			break;
		case GPIO_A03:
			GPIO->GPIOALL_FUNC.tBit.GPIOA03 = mode;
			break;
		case GPIO_A04:
			GPIO->GPIOALL_FUNC.tBit.GPIOA04 = mode;
			break;
		case GPIO_A05:
			GPIO->GPIOALL_FUNC.tBit.GPIOA05 = mode;
			break;
		case GPIO_A06:
			GPIO->GPIOALL_FUNC.tBit.GPIOA06 = mode;
			break;
		case GPIO_A07:
			GPIO->GPIOALL_FUNC.tBit.GPIOA07 = mode;
			break;
		case GPIO_A08:
			GPIO->GPIOALL_FUNC.tBit.GPIOA08 = mode;
			break;
		case GPIO_A09:
			GPIO->GPIOALL_FUNC.tBit.GPIOA09 = mode;
			break;
		case GPIO_A10:
			GPIO->GPIOALL_FUNC.tBit.GPIOA10 = mode;
			break;
		case GPIO_A11:
			GPIO->GPIOALL_FUNC.tBit.GPIOA11 = mode;
			break;
		case GPIO_A12:
			GPIO->GPIOALL_FUNC.tBit.GPIOA12 = mode;
			break;
		case GPIO_A13:
			GPIO->GPIOALL_FUNC.tBit.GPIOA13 = mode;
			break;
		case GPIO_A14:
			GPIO->GPIOALL_FUNC.tBit.GPIOA14 = mode;
			break;
		case GPIO_A15:
			GPIO->GPIOALL_FUNC.tBit.GPIOA15 = mode;
			break;
		case GPIO_A16:
			GPIO->GPIOALH_FUNC.tBit.GPIOA16 = mode;
			break;
		case GPIO_A17:
			GPIO->GPIOALH_FUNC.tBit.GPIOA17 = mode;
			break;
		case GPIO_A18:
			GPIO->GPIOALH_FUNC.tBit.GPIOA18 = mode;
			break;
		case GPIO_A19:
			GPIO->GPIOALH_FUNC.tBit.GPIOA19 = mode;
			break;
		case GPIO_A20:
			GPIO->GPIOALH_FUNC.tBit.GPIOA20 = mode;
			break;
		case GPIO_A21:
			GPIO->GPIOALH_FUNC.tBit.GPIOA21 = mode;
			break;
		case GPIO_A22:
			GPIO->GPIOALH_FUNC.tBit.GPIOA22 = mode;
			break;
		case GPIO_A23:
			GPIO->GPIOALH_FUNC.tBit.GPIOA23 = mode;
			break;
		case GPIO_A24:
			GPIO->GPIOALH_FUNC.tBit.GPIOA24 = mode;
			break;
		case GPIO_A25:
			GPIO->GPIOALH_FUNC.tBit.GPIOA25 = mode;
			break;
		case GPIO_A26:
			GPIO->GPIOALH_FUNC.tBit.GPIOA26 = mode;
			break;
		case GPIO_A27:
			GPIO->GPIOALH_FUNC.tBit.GPIOA27 = mode;
			break;
		case GPIO_A28:
			GPIO->GPIOALH_FUNC.tBit.GPIOA28 = mode;
			break;
		case GPIO_A29:
			GPIO->GPIOALH_FUNC.tBit.GPIOA29 = mode;
			break;
		case GPIO_A30:
			GPIO->GPIOALH_FUNC.tBit.GPIOA30 = mode;
			break;
		case GPIO_A31:
			GPIO->GPIOALH_FUNC.tBit.GPIOA31 = mode;
			break;
		case GPIO_A32:
			GPIO->GPIOAH_FUNC.tBit.GPIOA32 = mode;
			break;
		case GPIO_A33:
			GPIO->GPIOAH_FUNC.tBit.GPIOA33 = mode;
			break;
		case GPIO_A34:
			GPIO->GPIOAH_FUNC.tBit.GPIOA34 = mode;
			break;
		case GPIO_A35:
			GPIO->GPIOAH_FUNC.tBit.GPIOA35 = mode;
			break;
		case GPIO_A36:
			GPIO->GPIOAH_FUNC.tBit.GPIOA36 = mode;
			break;
		case GPIO_A37:
			GPIO->GPIOAH_FUNC.tBit.GPIOA37 = mode;
			break;
		case GPIO_A38:
			GPIO->GPIOAH_FUNC.tBit.GPIOA38 = mode;
			break;
		case GPIO_A39:
			GPIO->GPIOAH_FUNC.tBit.GPIOA39 = mode;
			break;
		case GPIO_A40:
			GPIO->GPIOAH_FUNC.tBit.GPIOA40 = mode;
			break;
		case GPIO_A41:
			GPIO->GPIOAH_FUNC.tBit.GPIOA41 = mode;
			break;
		case GPIO_A42:
			GPIO->GPIOAH_FUNC.tBit.GPIOA42 = mode;
			break;
		case GPIO_A43:
			GPIO->GPIOAH_FUNC.tBit.GPIOA43 = mode;
			break;
		case GPIO_A44:
			GPIO->GPIOAH_FUNC.tBit.GPIOA44 = mode;
			break;
		case GPIO_A45:
			GPIO->GPIOAH_FUNC.tBit.GPIOA45 = mode;
			break;

		default:
			break;
	}
}

void GPIO_Set_Dir(GPIOPin_TypeDef GPIOx, GPIODIR_TypeDef dir)
{
	switch (GPIOx)
	{
		case GPIO_M00:
			GPIO->GPIOM_OEN.tBit.GPIOM00 = dir;
			break;
		case GPIO_M01:
			GPIO->GPIOM_OEN.tBit.GPIOM01 = dir;
			break;
		case GPIO_M02:
			GPIO->GPIOM_OEN.tBit.GPIOM02 = dir;
			break;
		case GPIO_M03:
			GPIO->GPIOM_OEN.tBit.GPIOM03 = dir;
			break;
		case GPIO_M04:
			GPIO->GPIOM_OEN.tBit.GPIOM04 = dir;
			break;
		case GPIO_M05:
			GPIO->GPIOM_OEN.tBit.GPIOM05 = dir;
			break;
		case GPIO_M06:
			GPIO->GPIOM_OEN.tBit.GPIOM06 = dir;
			break;
		case GPIO_M07:
			GPIO->GPIOM_OEN.tBit.GPIOM07 = dir;
			break;
		case GPIO_M08:
			GPIO->GPIOM_OEN.tBit.GPIOM08 = dir;
			break;
		case GPIO_M09:
			GPIO->GPIOM_OEN.tBit.GPIOM09 = dir;
			break;
		case GPIO_M10:
			GPIO->GPIOM_OEN.tBit.GPIOM10 = dir;
			break;

		case GPIO_A00:
			GPIO->GPIOAL_OEN.tBit.GPIOA00 = dir;
			break;
		case GPIO_A01:
			GPIO->GPIOAL_OEN.tBit.GPIOA01 = dir;
			break;
		case GPIO_A02:
			GPIO->GPIOAL_OEN.tBit.GPIOA02 = dir;
			break;
		case GPIO_A03:
			GPIO->GPIOAL_OEN.tBit.GPIOA03 = dir;
			break;
		case GPIO_A04:
			GPIO->GPIOAL_OEN.tBit.GPIOA04 = dir;
			break;
		case GPIO_A05:
			GPIO->GPIOAL_OEN.tBit.GPIOA05 = dir;
			break;
		case GPIO_A06:
			GPIO->GPIOAL_OEN.tBit.GPIOA06 = dir;
			break;
		case GPIO_A07:
			GPIO->GPIOAL_OEN.tBit.GPIOA07 = dir;
			break;
		case GPIO_A08:
			GPIO->GPIOAL_OEN.tBit.GPIOA08 = dir;
			break;
		case GPIO_A09:
			GPIO->GPIOAL_OEN.tBit.GPIOA09 = dir;
			break;
		case GPIO_A10:
			GPIO->GPIOAL_OEN.tBit.GPIOA10 = dir;
			break;
		case GPIO_A11:
			GPIO->GPIOAL_OEN.tBit.GPIOA11 = dir;
			break;
		case GPIO_A12:
			GPIO->GPIOAL_OEN.tBit.GPIOA12 = dir;
			break;
		case GPIO_A13:
			GPIO->GPIOAL_OEN.tBit.GPIOA13 = dir;
			break;
		case GPIO_A14:
			GPIO->GPIOAL_OEN.tBit.GPIOA14 = dir;
			break;
		case GPIO_A15:
			GPIO->GPIOAL_OEN.tBit.GPIOA15 = dir;
			break;
		case GPIO_A16:
			GPIO->GPIOAL_OEN.tBit.GPIOA16 = dir;
			break;
		case GPIO_A17:
			GPIO->GPIOAL_OEN.tBit.GPIOA17 = dir;
			break;
		case GPIO_A18:
			GPIO->GPIOAL_OEN.tBit.GPIOA18 = dir;
			break;
		case GPIO_A19:
			GPIO->GPIOAL_OEN.tBit.GPIOA19 = dir;
			break;
		case GPIO_A20:
			GPIO->GPIOAL_OEN.tBit.GPIOA20 = dir;
			break;
		case GPIO_A21:
			GPIO->GPIOAL_OEN.tBit.GPIOA21 = dir;
			break;
		case GPIO_A22:
			GPIO->GPIOAL_OEN.tBit.GPIOA22 = dir;
			break;
		case GPIO_A23:
			GPIO->GPIOAL_OEN.tBit.GPIOA23 = dir;
			break;
		case GPIO_A24:
			GPIO->GPIOAL_OEN.tBit.GPIOA24 = dir;
			break;
		case GPIO_A25:
			GPIO->GPIOAL_OEN.tBit.GPIOA25 = dir;
			break;
		case GPIO_A26:
			GPIO->GPIOAL_OEN.tBit.GPIOA26 = dir;
			break;
		case GPIO_A27:
			GPIO->GPIOAL_OEN.tBit.GPIOA27 = dir;
			break;
		case GPIO_A28:
			GPIO->GPIOAL_OEN.tBit.GPIOA28 = dir;
			break;
		case GPIO_A29:
			GPIO->GPIOAL_OEN.tBit.GPIOA29 = dir;
			break;
		case GPIO_A30:
			GPIO->GPIOAL_OEN.tBit.GPIOA30 = dir;
			break;
		case GPIO_A31:
			GPIO->GPIOAL_OEN.tBit.GPIOA31 = dir;
			break;

		case GPIO_A32:
			GPIO->GPIOAH_OEN.tBit.GPIOA32 = dir;
			break;
		case GPIO_A33:
			GPIO->GPIOAH_OEN.tBit.GPIOA33 = dir;
			break;
		case GPIO_A34:
			GPIO->GPIOAH_OEN.tBit.GPIOA34 = dir;
			break;
		case GPIO_A35:
			GPIO->GPIOAH_OEN.tBit.GPIOA35 = dir;
			break;
		case GPIO_A36:
			GPIO->GPIOAH_OEN.tBit.GPIOA36 = dir;
			break;
		case GPIO_A37:
			GPIO->GPIOAH_OEN.tBit.GPIOA37 = dir;
			break;
		case GPIO_A38:
			GPIO->GPIOAH_OEN.tBit.GPIOA38 = dir;
			break;
		case GPIO_A39:
			GPIO->GPIOAH_OEN.tBit.GPIOA39 = dir;
			break;
		case GPIO_A40:
			GPIO->GPIOAH_OEN.tBit.GPIOA40 = dir;
			break;
		case GPIO_A41:
			GPIO->GPIOAH_OEN.tBit.GPIOA41 = dir;
			break;
		case GPIO_A42:
			GPIO->GPIOAH_OEN.tBit.GPIOA42 = dir;
			break;
		case GPIO_A43:
			GPIO->GPIOAH_OEN.tBit.GPIOA43 = dir;
			break;
		case GPIO_A44:
			GPIO->GPIOAH_OEN.tBit.GPIOA44 = dir;
			break;
		case GPIO_A45:
			GPIO->GPIOAH_OEN.tBit.GPIOA45 = dir;
			break;

		default:
			break;
	}

}

void GPIO_Set_DATA(GPIOPin_TypeDef GPIOx, GPIODATA_TypeDef data)
{
	switch (GPIOx)
	{
		case GPIO_M00:
			GPIO->GPIOM_OUT.tBit.GPIOM00 = data;
			break;
		case GPIO_M01:
			GPIO->GPIOM_OUT.tBit.GPIOM01 = data;
			break;
		case GPIO_M02:
			GPIO->GPIOM_OUT.tBit.GPIOM02 = data;
			break;
		case GPIO_M03:
			GPIO->GPIOM_OUT.tBit.GPIOM03 = data;
			break;
		case GPIO_M04:
			GPIO->GPIOM_OUT.tBit.GPIOM04 = data;
			break;
		case GPIO_M05:
			GPIO->GPIOM_OUT.tBit.GPIOM05 = data;
			break;
		case GPIO_M06:
			GPIO->GPIOM_OUT.tBit.GPIOM06 = data;
			break;
		case GPIO_M07:
			GPIO->GPIOM_OUT.tBit.GPIOM07 = data;
			break;
		case GPIO_M08:
			GPIO->GPIOM_OUT.tBit.GPIOM08 = data;
			break;
		case GPIO_M09:
			GPIO->GPIOM_OUT.tBit.GPIOM09 = data;
			break;
		case GPIO_M10:
			GPIO->GPIOM_OUT.tBit.GPIOM10 = data;
			break;

		case GPIO_A00:
			GPIO->GPIOAL_OUT.tBit.GPIOA00 = data;
			break;
		case GPIO_A01:
			GPIO->GPIOAL_OUT.tBit.GPIOA01 = data;
			break;
		case GPIO_A02:
			GPIO->GPIOAL_OUT.tBit.GPIOA02 = data;
			break;
		case GPIO_A03:
			GPIO->GPIOAL_OUT.tBit.GPIOA03 = data;
			break;
		case GPIO_A04:
			GPIO->GPIOAL_OUT.tBit.GPIOA04 = data;
			break;
		case GPIO_A05:
			GPIO->GPIOAL_OUT.tBit.GPIOA05 = data;
			break;
		case GPIO_A06:
			GPIO->GPIOAL_OUT.tBit.GPIOA06 = data;
			break;
		case GPIO_A07:
			GPIO->GPIOAL_OUT.tBit.GPIOA07 = data;
			break;
		case GPIO_A08:
			GPIO->GPIOAL_OUT.tBit.GPIOA08 = data;
			break;
		case GPIO_A09:
			GPIO->GPIOAL_OUT.tBit.GPIOA09 = data;
			break;
		case GPIO_A10:
			GPIO->GPIOAL_OUT.tBit.GPIOA10 = data;
			break;
		case GPIO_A11:
			GPIO->GPIOAL_OUT.tBit.GPIOA11 = data;
			break;
		case GPIO_A12:
			GPIO->GPIOAL_OUT.tBit.GPIOA12 = data;
			break;
		case GPIO_A13:
			GPIO->GPIOAL_OUT.tBit.GPIOA13 = data;
			break;
		case GPIO_A14:
			GPIO->GPIOAL_OUT.tBit.GPIOA14 = data;
			break;
		case GPIO_A15:
			GPIO->GPIOAL_OUT.tBit.GPIOA15 = data;
			break;
		case GPIO_A16:
			GPIO->GPIOAL_OUT.tBit.GPIOA16 = data;
			break;
		case GPIO_A17:
			GPIO->GPIOAL_OUT.tBit.GPIOA17 = data;
			break;
		case GPIO_A18:
			GPIO->GPIOAL_OUT.tBit.GPIOA18 = data;
			break;
		case GPIO_A19:
			GPIO->GPIOAL_OUT.tBit.GPIOA19 = data;
			break;
		case GPIO_A20:
			GPIO->GPIOAL_OUT.tBit.GPIOA20 = data;
			break;
		case GPIO_A21:
			GPIO->GPIOAL_OUT.tBit.GPIOA21 = data;
			break;
		case GPIO_A22:
			GPIO->GPIOAL_OUT.tBit.GPIOA22 = data;
			break;
		case GPIO_A23:
			GPIO->GPIOAL_OUT.tBit.GPIOA23 = data;
			break;
		case GPIO_A24:
			GPIO->GPIOAL_OUT.tBit.GPIOA24 = data;
			break;
		case GPIO_A25:
			GPIO->GPIOAL_OUT.tBit.GPIOA25 = data;
			break;
		case GPIO_A26:
			GPIO->GPIOAL_OUT.tBit.GPIOA26 = data;
			break;
		case GPIO_A27:
			GPIO->GPIOAL_OUT.tBit.GPIOA27 = data;
			break;
		case GPIO_A28:
			GPIO->GPIOAL_OUT.tBit.GPIOA28 = data;
			break;
		case GPIO_A29:
			GPIO->GPIOAL_OUT.tBit.GPIOA29 = data;
			break;
		case GPIO_A30:
			GPIO->GPIOAL_OUT.tBit.GPIOA30 = data;
			break;
		case GPIO_A31:
			GPIO->GPIOAL_OUT.tBit.GPIOA31 = data;
			break;

		case GPIO_A32:
			GPIO->GPIOAH_OUT.tBit.GPIOA32 = data;
			break;
		case GPIO_A33:
			GPIO->GPIOAH_OUT.tBit.GPIOA33 = data;
			break;
		case GPIO_A34:
			GPIO->GPIOAH_OUT.tBit.GPIOA34 = data;
			break;
		case GPIO_A35:
			GPIO->GPIOAH_OUT.tBit.GPIOA35 = data;
			break;
		case GPIO_A36:
			GPIO->GPIOAH_OUT.tBit.GPIOA36 = data;
			break;
		case GPIO_A37:
			GPIO->GPIOAH_OUT.tBit.GPIOA37 = data;
			break;
		case GPIO_A38:
			GPIO->GPIOAH_OUT.tBit.GPIOA38 = data;
			break;
		case GPIO_A39:
			GPIO->GPIOAH_OUT.tBit.GPIOA39 = data;
			break;
		case GPIO_A40:
			GPIO->GPIOAH_OUT.tBit.GPIOA40 = data;
			break;
		case GPIO_A41:
			GPIO->GPIOAH_OUT.tBit.GPIOA41 = data;
			break;
		case GPIO_A42:
			GPIO->GPIOAH_OUT.tBit.GPIOA42 = data;
			break;
		case GPIO_A43:
			GPIO->GPIOAH_OUT.tBit.GPIOA43 = data;
			break;
		case GPIO_A44:
			GPIO->GPIOAH_OUT.tBit.GPIOA44 = data;
			break;
		case GPIO_A45:
			GPIO->GPIOAH_OUT.tBit.GPIOA45 = data;
			break;

		default:
			break;
	}

}

void GPIO_Set_PE(GPIOPin_TypeDef GPIOx, GPIOPE_TypeDef pe)
{
	switch (GPIOx)
	{
		case GPIO_M00:
			GPIO->GPIOM_PE.tBit.GPIOM00 = pe;
			break;
		case GPIO_M01:
			GPIO->GPIOM_PE.tBit.GPIOM01 = pe;
			break;
		case GPIO_M02:
			GPIO->GPIOM_PE.tBit.GPIOM02 = pe;
			break;
		case GPIO_M03:
			GPIO->GPIOM_PE.tBit.GPIOM03 = pe;
			break;
		case GPIO_M04:
			GPIO->GPIOM_PE.tBit.GPIOM04 = pe;
			break;
		case GPIO_M05:
			GPIO->GPIOM_PE.tBit.GPIOM05 = pe;
			break;
		case GPIO_M06:
			GPIO->GPIOM_PE.tBit.GPIOM06 = pe;
			break;
		case GPIO_M07:
			GPIO->GPIOM_PE.tBit.GPIOM07 = pe;
			break;
		case GPIO_M08:
			GPIO->GPIOM_PE.tBit.GPIOM08 = pe;
			break;
		case GPIO_M09:
			GPIO->GPIOM_PE.tBit.GPIOM09 = pe;
			break;
		case GPIO_M10:
			GPIO->GPIOM_PE.tBit.GPIOM10 = pe;
			break;

		case GPIO_A00:
			GPIO->GPIOALL_PE.tBit.GPIOA00 = pe;
			break;
		case GPIO_A01:
			GPIO->GPIOALL_PE.tBit.GPIOA01 = pe;
			break;
		case GPIO_A02:
			GPIO->GPIOALL_PE.tBit.GPIOA02 = pe;
			break;
		case GPIO_A03:
			GPIO->GPIOALL_PE.tBit.GPIOA03 = pe;
			break;
		case GPIO_A04:
			GPIO->GPIOALL_PE.tBit.GPIOA04 = pe;
			break;
		case GPIO_A05:
			GPIO->GPIOALL_PE.tBit.GPIOA05 = pe;
			break;
		case GPIO_A06:
			GPIO->GPIOALL_PE.tBit.GPIOA06 = pe;
			break;
		case GPIO_A07:
			GPIO->GPIOALL_PE.tBit.GPIOA07 = pe;
			break;
		case GPIO_A08:
			GPIO->GPIOALL_PE.tBit.GPIOA08 = pe;
			break;
		case GPIO_A09:
			GPIO->GPIOALL_PE.tBit.GPIOA09 = pe;
			break;
		case GPIO_A10:
			GPIO->GPIOALL_PE.tBit.GPIOA10 = pe;
			break;
		case GPIO_A11:
			GPIO->GPIOALL_PE.tBit.GPIOA11 = pe;
			break;
		case GPIO_A12:
			GPIO->GPIOALL_PE.tBit.GPIOA12 = pe;
			break;
		case GPIO_A13:
			GPIO->GPIOALL_PE.tBit.GPIOA13 = pe;
			break;
		case GPIO_A14:
			GPIO->GPIOALL_PE.tBit.GPIOA14 = pe;
			break;
		case GPIO_A15:
			GPIO->GPIOALL_PE.tBit.GPIOA15 = pe;
			break;

		case GPIO_A16:
			GPIO->GPIOALH_PE.tBit.GPIOA16 = pe;
			break;
		case GPIO_A17:
			GPIO->GPIOALH_PE.tBit.GPIOA17 = pe;
			break;
		case GPIO_A18:
			GPIO->GPIOALH_PE.tBit.GPIOA18 = pe;
			break;
		case GPIO_A19:
			GPIO->GPIOALH_PE.tBit.GPIOA19 = pe;
			break;
		case GPIO_A20:
			GPIO->GPIOALH_PE.tBit.GPIOA20 = pe;
			break;
		case GPIO_A21:
			GPIO->GPIOALH_PE.tBit.GPIOA21 = pe;
			break;
		case GPIO_A22:
			GPIO->GPIOALH_PE.tBit.GPIOA22 = pe;
			break;
		case GPIO_A23:
			GPIO->GPIOALH_PE.tBit.GPIOA23 = pe;
			break;
		case GPIO_A24:
			GPIO->GPIOALH_PE.tBit.GPIOA24 = pe;
			break;
		case GPIO_A25:
			GPIO->GPIOALH_PE.tBit.GPIOA25 = pe;
			break;
		case GPIO_A26:
			GPIO->GPIOALH_PE.tBit.GPIOA26 = pe;
			break;
		case GPIO_A27:
			GPIO->GPIOALH_PE.tBit.GPIOA27 = pe;
			break;
		case GPIO_A28:
			GPIO->GPIOALH_PE.tBit.GPIOA28 = pe;
			break;
		case GPIO_A29:
			GPIO->GPIOALH_PE.tBit.GPIOA29 = pe;
			break;
		case GPIO_A30:
			GPIO->GPIOALH_PE.tBit.GPIOA30 = pe;
			break;
		case GPIO_A31:
			GPIO->GPIOALH_PE.tBit.GPIOA31 = pe;
			break;

		case GPIO_A32:
			GPIO->GPIOAH_PE.tBit.GPIOA32 = pe;
			break;
		case GPIO_A33:
			GPIO->GPIOAH_PE.tBit.GPIOA33 = pe;
			break;
		case GPIO_A34:
			GPIO->GPIOAH_PE.tBit.GPIOA34 = pe;
			break;
		case GPIO_A35:
			GPIO->GPIOAH_PE.tBit.GPIOA35 = pe;
			break;
		case GPIO_A36:
			GPIO->GPIOAH_PE.tBit.GPIOA36 = pe;
			break;
		case GPIO_A37:
			GPIO->GPIOAH_PE.tBit.GPIOA37 = pe;
			break;
		case GPIO_A38:
			GPIO->GPIOAH_PE.tBit.GPIOA38 = pe;
			break;
		case GPIO_A39:
			GPIO->GPIOAH_PE.tBit.GPIOA39 = pe;
			break;
		case GPIO_A40:
			GPIO->GPIOAH_PE.tBit.GPIOA40 = pe;
			break;
		case GPIO_A41:
			GPIO->GPIOAH_PE.tBit.GPIOA41 = pe;
			break;
		case GPIO_A42:
			GPIO->GPIOAH_PE.tBit.GPIOA42 = pe;
			break;
		case GPIO_A43:
			GPIO->GPIOAH_PE.tBit.GPIOA43 = pe;
			break;
		case GPIO_A44:
			GPIO->GPIOAH_PE.tBit.GPIOA44 = pe;
			break;
		case GPIO_A45:
			GPIO->GPIOAH_PE.tBit.GPIOA45 = pe;
			break;

		default:
			break;
	}

}

void GPIO_Set_DS(GPIOPin_TypeDef GPIOx, GPIODS_TypeDef ds)
{
	switch (GPIOx)
	{
		case GPIO_M00:
			GPIO->GPIOM_DS.tBit.GPIOM00 = ds;
			break;
		case GPIO_M01:
			GPIO->GPIOM_DS.tBit.GPIOM01 = ds;
			break;
		case GPIO_M02:
			GPIO->GPIOM_DS.tBit.GPIOM02 = ds;
			break;
		case GPIO_M03:
			GPIO->GPIOM_DS.tBit.GPIOM03 = ds;
			break;
		case GPIO_M04:
			GPIO->GPIOM_DS.tBit.GPIOM04 = ds;
			break;
		case GPIO_M05:
			GPIO->GPIOM_DS.tBit.GPIOM05 = ds;
			break;
		case GPIO_M06:
			GPIO->GPIOM_DS.tBit.GPIOM06 = ds;
			break;
		case GPIO_M07:
			GPIO->GPIOM_DS.tBit.GPIOM07 = ds;
			break;
		case GPIO_M08:
			GPIO->GPIOM_DS.tBit.GPIOM08 = ds;
			break;
		case GPIO_M09:
			GPIO->GPIOM_DS.tBit.GPIOM09 = ds;
			break;
		case GPIO_M10:
			GPIO->GPIOM_DS.tBit.GPIOM10 = ds;
			break;

		case GPIO_A00:
			GPIO->GPIOALL_DS.tBit.GPIOA00 = ds;
			break;
		case GPIO_A01:
			GPIO->GPIOALL_DS.tBit.GPIOA01 = ds;
			break;
		case GPIO_A02:
			GPIO->GPIOALL_DS.tBit.GPIOA02 = ds;
			break;
		case GPIO_A03:
			GPIO->GPIOALL_DS.tBit.GPIOA03 = ds;
			break;
		case GPIO_A04:
			GPIO->GPIOALL_DS.tBit.GPIOA04 = ds;
			break;
		case GPIO_A05:
			GPIO->GPIOALL_DS.tBit.GPIOA05 = ds;
			break;
		case GPIO_A06:
			GPIO->GPIOALL_DS.tBit.GPIOA06 = ds;
			break;
		case GPIO_A07:
			GPIO->GPIOALL_DS.tBit.GPIOA07 = ds;
			break;
		case GPIO_A08:
			GPIO->GPIOALL_DS.tBit.GPIOA08 = ds;
			break;
		case GPIO_A09:
			GPIO->GPIOALL_DS.tBit.GPIOA09 = ds;
			break;
		case GPIO_A10:
			GPIO->GPIOALL_DS.tBit.GPIOA10 = ds;
			break;
		case GPIO_A11:
			GPIO->GPIOALL_DS.tBit.GPIOA11 = ds;
			break;
		case GPIO_A12:
			GPIO->GPIOALL_DS.tBit.GPIOA12 = ds;
			break;
		case GPIO_A13:
			GPIO->GPIOALL_DS.tBit.GPIOA13 = ds;
			break;
		case GPIO_A14:
			GPIO->GPIOALL_DS.tBit.GPIOA14 = ds;
			break;
		case GPIO_A15:
			GPIO->GPIOALL_DS.tBit.GPIOA15 = ds;
			break;

		case GPIO_A16:
			GPIO->GPIOALH_DS.tBit.GPIOA16 = ds;
			break;
		case GPIO_A17:
			GPIO->GPIOALH_DS.tBit.GPIOA17 = ds;
			break;
		case GPIO_A18:
			GPIO->GPIOALH_DS.tBit.GPIOA18 = ds;
			break;
		case GPIO_A19:
			GPIO->GPIOALH_DS.tBit.GPIOA19 = ds;
			break;
		case GPIO_A20:
			GPIO->GPIOALH_DS.tBit.GPIOA20 = ds;
			break;
		case GPIO_A21:
			GPIO->GPIOALH_DS.tBit.GPIOA21 = ds;
			break;
		case GPIO_A22:
			GPIO->GPIOALH_DS.tBit.GPIOA22 = ds;
			break;
		case GPIO_A23:
			GPIO->GPIOALH_DS.tBit.GPIOA23 = ds;
			break;
		case GPIO_A24:
			GPIO->GPIOALH_DS.tBit.GPIOA24 = ds;
			break;
		case GPIO_A25:
			GPIO->GPIOALH_DS.tBit.GPIOA25 = ds;
			break;
		case GPIO_A26:
			GPIO->GPIOALH_DS.tBit.GPIOA26 = ds;
			break;
		case GPIO_A27:
			GPIO->GPIOALH_DS.tBit.GPIOA27 = ds;
			break;
		case GPIO_A28:
			GPIO->GPIOALH_DS.tBit.GPIOA28 = ds;
			break;
		case GPIO_A29:
			GPIO->GPIOALH_DS.tBit.GPIOA29 = ds;
			break;
		case GPIO_A30:
			GPIO->GPIOALH_DS.tBit.GPIOA30 = ds;
			break;
		case GPIO_A31:
			GPIO->GPIOALH_DS.tBit.GPIOA31 = ds;
			break;

		case GPIO_A32:
			GPIO->GPIOAH_DS.tBit.GPIOA32 = ds;
			break;
		case GPIO_A33:
			GPIO->GPIOAH_DS.tBit.GPIOA33 = ds;
			break;
		case GPIO_A34:
			GPIO->GPIOAH_DS.tBit.GPIOA34 = ds;
			break;
		case GPIO_A35:
			GPIO->GPIOAH_DS.tBit.GPIOA35 = ds;
			break;
		case GPIO_A36:
			GPIO->GPIOAH_DS.tBit.GPIOA36 = ds;
			break;
		case GPIO_A37:
			GPIO->GPIOAH_DS.tBit.GPIOA37 = ds;
			break;
		case GPIO_A38:
			GPIO->GPIOAH_DS.tBit.GPIOA38 = ds;
			break;
		case GPIO_A39:
			GPIO->GPIOAH_DS.tBit.GPIOA39 = ds;
			break;
		case GPIO_A40:
			GPIO->GPIOAH_DS.tBit.GPIOA40 = ds;
			break;
		case GPIO_A41:
			GPIO->GPIOAH_DS.tBit.GPIOA41 = ds;
			break;
		case GPIO_A42:
			GPIO->GPIOAH_DS.tBit.GPIOA42 = ds;
			break;
		case GPIO_A43:
			GPIO->GPIOAH_DS.tBit.GPIOA43 = ds;
			break;
		case GPIO_A44:
			GPIO->GPIOAH_DS.tBit.GPIOA44 = ds;
			break;
		case GPIO_A45:
			GPIO->GPIOAH_DS.tBit.GPIOA45 = ds;
			break;

		default:
			break;
	}
}

bool_t GPIO_Get_IN(GPIOPin_TypeDef GPIOx)
{
	bool_t retval;

	switch (GPIOx)
	{
		case GPIO_M00:
			retval = GPIO->GPIOM_IN.tBit.GPIOM00;
			break;
		case GPIO_M01:
			retval = GPIO->GPIOM_IN.tBit.GPIOM01;
			break;
		case GPIO_M02:
			retval = GPIO->GPIOM_IN.tBit.GPIOM02;
			break;
		case GPIO_M03:
			retval = GPIO->GPIOM_IN.tBit.GPIOM03;
			break;
		case GPIO_M04:
			retval = GPIO->GPIOM_IN.tBit.GPIOM04;
			break;
		case GPIO_M05:
			retval = GPIO->GPIOM_IN.tBit.GPIOM05;
			break;
		case GPIO_M06:
			retval = GPIO->GPIOM_IN.tBit.GPIOM06;
			break;
		case GPIO_M07:
			retval = GPIO->GPIOM_IN.tBit.GPIOM07;
			break;
		case GPIO_M08:
			retval = GPIO->GPIOM_IN.tBit.GPIOM08;
			break;
		case GPIO_M09:
			retval = GPIO->GPIOM_IN.tBit.GPIOM09;
			break;
		case GPIO_M10:
			retval = GPIO->GPIOM_IN.tBit.GPIOM10;
			break;

		case GPIO_A00:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA00;
			break;
		case GPIO_A01:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA01;
			break;
		case GPIO_A02:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA02;
			break;
		case GPIO_A03:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA03;
			break;
		case GPIO_A04:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA04;
			break;
		case GPIO_A05:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA05;
			break;
		case GPIO_A06:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA06;
			break;
		case GPIO_A07:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA07;
			break;
		case GPIO_A08:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA08;
			break;
		case GPIO_A09:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA09;
			break;
		case GPIO_A10:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA10;
			break;
		case GPIO_A11:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA11;
			break;
		case GPIO_A12:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA12;
			break;
		case GPIO_A13:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA13;
			break;
		case GPIO_A14:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA14;
			break;
		case GPIO_A15:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA15;
			break;
		case GPIO_A16:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA16;
			break;
		case GPIO_A17:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA17;
			break;
		case GPIO_A18:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA18;
			break;
		case GPIO_A19:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA19;
			break;
		case GPIO_A20:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA20;
			break;
		case GPIO_A21:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA21;
			break;
		case GPIO_A22:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA22;
			break;
		case GPIO_A23:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA23;
			break;
		case GPIO_A24:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA24;
			break;
		case GPIO_A25:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA25;
			break;
		case GPIO_A26:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA26;
			break;
		case GPIO_A27:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA27;
			break;
		case GPIO_A28:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA28;
			break;
		case GPIO_A29:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA29;
			break;
		case GPIO_A30:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA30;
			break;
		case GPIO_A31:
			retval = GPIO->GPIOAL_IN.tBit.GPIOA31;
			break;

		case GPIO_A32:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA32;
			break;
		case GPIO_A33:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA33;
			break;
		case GPIO_A34:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA34;
			break;
		case GPIO_A35:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA35;
			break;
		case GPIO_A36:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA36;
			break;
		case GPIO_A37:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA37;
			break;
		case GPIO_A38:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA38;
			break;
		case GPIO_A39:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA39;
			break;
		case GPIO_A40:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA40;
			break;
		case GPIO_A41:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA41;
			break;
		case GPIO_A42:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA42;
			break;
		case GPIO_A43:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA43;
			break;
		case GPIO_A44:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA44;
			break;
		case GPIO_A45:
			retval = GPIO->GPIOAH_IN.tBit.GPIOA45;
			break;

		default:
			break;
	}

	return retval;
}

bool_t GPIO_Get_OUT(GPIOPin_TypeDef GPIOx)	/* Used only output mode */
{
	bool_t retval;

	switch (GPIOx)
	{
		case GPIO_M00:
			retval = GPIO->GPIOM_OUT.tBit.GPIOM00;
			break;
		case GPIO_M01:
			retval = GPIO->GPIOM_OUT.tBit.GPIOM01;
			break;
		case GPIO_M02:
			retval = GPIO->GPIOM_OUT.tBit.GPIOM02;
			break;
		case GPIO_M03:
			retval = GPIO->GPIOM_OUT.tBit.GPIOM03;
			break;
		case GPIO_M04:
			retval = GPIO->GPIOM_OUT.tBit.GPIOM04;
			break;
		case GPIO_M05:
			retval = GPIO->GPIOM_OUT.tBit.GPIOM05;
			break;
		case GPIO_M06:
			retval = GPIO->GPIOM_OUT.tBit.GPIOM06;
			break;
		case GPIO_M07:
			retval = GPIO->GPIOM_OUT.tBit.GPIOM07;
			break;
		case GPIO_M08:
			retval = GPIO->GPIOM_OUT.tBit.GPIOM08;
			break;
		case GPIO_M09:
			retval = GPIO->GPIOM_OUT.tBit.GPIOM09;
			break;
		case GPIO_M10:
			retval = GPIO->GPIOM_OUT.tBit.GPIOM10;
			break;

		case GPIO_A00:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA00;
			break;
		case GPIO_A01:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA01;
			break;
		case GPIO_A02:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA02;
			break;
		case GPIO_A03:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA03;
			break;
		case GPIO_A04:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA04;
			break;
		case GPIO_A05:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA05;
			break;
		case GPIO_A06:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA06;
			break;
		case GPIO_A07:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA07;
			break;
		case GPIO_A08:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA08;
			break;
		case GPIO_A09:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA09;
			break;
		case GPIO_A10:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA10;
			break;
		case GPIO_A11:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA11;
			break;
		case GPIO_A12:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA12;
			break;
		case GPIO_A13:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA13;
			break;
		case GPIO_A14:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA14;
			break;
		case GPIO_A15:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA15;
			break;
		case GPIO_A16:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA16;
			break;
		case GPIO_A17:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA17;
			break;
		case GPIO_A18:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA18;
			break;
		case GPIO_A19:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA19;
			break;
		case GPIO_A20:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA20;
			break;
		case GPIO_A21:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA21;
			break;
		case GPIO_A22:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA22;
			break;
		case GPIO_A23:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA23;
			break;
		case GPIO_A24:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA24;
			break;
		case GPIO_A25:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA25;
			break;
		case GPIO_A26:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA26;
			break;
		case GPIO_A27:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA27;
			break;
		case GPIO_A28:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA28;
			break;
		case GPIO_A29:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA29;
			break;
		case GPIO_A30:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA30;
			break;
		case GPIO_A31:
			retval = GPIO->GPIOAL_OUT.tBit.GPIOA31;
			break;

		case GPIO_A32:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA32;
			break;
		case GPIO_A33:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA33;
			break;
		case GPIO_A34:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA34;
			break;
		case GPIO_A35:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA35;
			break;
		case GPIO_A36:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA36;
			break;
		case GPIO_A37:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA37;
			break;
		case GPIO_A38:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA38;
			break;
		case GPIO_A39:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA39;
			break;
		case GPIO_A40:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA40;
			break;
		case GPIO_A41:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA41;
			break;
		case GPIO_A42:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA42;
			break;
		case GPIO_A43:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA43;
			break;
		case GPIO_A44:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA44;
			break;
		case GPIO_A45:
			retval = GPIO->GPIOAH_OUT.tBit.GPIOA45;
			break;

		default:
			break;
	}

	return retval;
}

void GPIO_Set_INT(GPIOPin_TypeDef GPIOx, GPIOINTEN_TypeDef En, GPIOINTType_TypeDef type)
{
	switch (GPIOx)
	{
		case GPIO_M00:
			GPIO->GPIOM_INTTYPE.tBit.GPIOM00 = type;
			break;
		case GPIO_M01:
			GPIO->GPIOM_INTTYPE.tBit.GPIOM01 = type;
			break;
		case GPIO_M02:
			GPIO->GPIOM_INTTYPE.tBit.GPIOM02 = type;
			break;
		case GPIO_M03:
			GPIO->GPIOM_INTTYPE.tBit.GPIOM03 = type;
			break;
		case GPIO_M04:
			GPIO->GPIOM_INTTYPE.tBit.GPIOM04 = type;
			break;
		case GPIO_M05:
			GPIO->GPIOM_INTTYPE.tBit.GPIOM05 = type;
			break;
		case GPIO_M06:
			GPIO->GPIOM_INTTYPE.tBit.GPIOM06 = type;
			break;
		case GPIO_M07:
			GPIO->GPIOM_INTTYPE.tBit.GPIOM07 = type;
			break;
		case GPIO_M08:
			GPIO->GPIOM_INTTYPE.tBit.GPIOM08 = type;
			break;
		case GPIO_M09:
			GPIO->GPIOM_INTTYPE.tBit.GPIOM09 = type;
			break;
		case GPIO_M10:
			GPIO->GPIOM_INTTYPE.tBit.GPIOM10 = type;
			break;

		case GPIO_A00:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA00 = type;
			break;
		case GPIO_A01:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA01 = type;
			break;
		case GPIO_A02:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA02 = type;
			break;
		case GPIO_A03:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA03 = type;
			break;
		case GPIO_A04:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA04 = type;
			break;
		case GPIO_A05:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA05 = type;
			break;
		case GPIO_A06:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA06 = type;
			break;
		case GPIO_A07:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA07 = type;
			break;
		case GPIO_A08:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA08 = type;
			break;
		case GPIO_A09:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA09 = type;
			break;
		case GPIO_A10:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA10 = type;
			break;
		case GPIO_A11:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA11 = type;
			break;
		case GPIO_A12:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA12 = type;
			break;
		case GPIO_A13:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA13 = type;
			break;
		case GPIO_A14:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA14 = type;
			break;
		case GPIO_A15:
			GPIO->GPIOALL_INTTYPE.tBit.GPIOA15 = type;
			break;

		case GPIO_A16:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA16 = type;
			break;
		case GPIO_A17:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA17 = type;
			break;
		case GPIO_A18:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA18 = type;
			break;
		case GPIO_A19:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA19 = type;
			break;
		case GPIO_A20:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA20 = type;
			break;
		case GPIO_A21:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA21 = type;
			break;
		case GPIO_A22:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA22 = type;
			break;
		case GPIO_A23:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA23 = type;
			break;
		case GPIO_A24:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA24 = type;
			break;
		case GPIO_A25:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA25 = type;
			break;
		case GPIO_A26:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA26 = type;
			break;
		case GPIO_A27:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA27 = type;
			break;
		case GPIO_A28:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA28 = type;
			break;
		case GPIO_A29:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA29 = type;
			break;
		case GPIO_A30:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA30 = type;
			break;
		case GPIO_A31:
			GPIO->GPIOALH_INTTYPE.tBit.GPIOA31 = type;
			break;

		case GPIO_A32:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA32 = type;
			break;
		case GPIO_A33:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA33 = type;
			break;
		case GPIO_A34:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA34 = type;
			break;
		case GPIO_A35:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA35 = type;
			break;
		case GPIO_A36:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA36 = type;
			break;
		case GPIO_A37:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA37 = type;
			break;
		case GPIO_A38:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA38 = type;
			break;
		case GPIO_A39:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA39 = type;
			break;
		case GPIO_A40:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA40 = type;
			break;
		case GPIO_A41:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA41 = type;
			break;
		case GPIO_A42:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA42 = type;
			break;
		case GPIO_A43:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA43 = type;
			break;
		case GPIO_A44:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA44 = type;
			break;
		case GPIO_A45:
			GPIO->GPIOAH_INTTYPE.tBit.GPIOA45 = type;
			break;

		default:
			break;
	}

	if(En == GPIO_INTEN_ENABLE)
	{
		if(GPIOx <= GPIO_M10)
		{
			GPIO->GPIO_INTEN.tBit.GPIOM = GPIO_INTEN_ENABLE;
			NVIC_ClearPendingIRQ(GPIOM_IRQn);
			NVIC_SetPriority(GPIOM_IRQn, GPIOM_IRQn_Priority);
			NVIC_EnableIRQ(GPIOM_IRQn);
		}
		else
		{
			GPIO->GPIO_INTEN.tBit.GPIOA = GPIO_INTEN_ENABLE;
			NVIC_ClearPendingIRQ(GPIOA_IRQn);
			NVIC_SetPriority(GPIOA_IRQn, GPIOA_IRQn_Priority);
			NVIC_EnableIRQ(GPIOA_IRQn);
		}
	}
	else
	{
		if(GPIOx <= GPIO_M10)
		{
			GPIO->GPIO_INTEN.tBit.GPIOM = GPIO_INTEN_DISABLE;
			NVIC_ClearPendingIRQ(GPIOM_IRQn);
			NVIC_SetPriority(GPIOM_IRQn, GPIOM_IRQn_Priority);
			NVIC_DisableIRQ(GPIOM_IRQn);
		}
		else
		{
			GPIO->GPIO_INTEN.tBit.GPIOA = GPIO_INTEN_DISABLE;
			NVIC_ClearPendingIRQ(GPIOA_IRQn);
			NVIC_SetPriority(GPIOA_IRQn, GPIOA_IRQn_Priority);
			NVIC_DisableIRQ(GPIOA_IRQn);
		}
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
