/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_main.c
 * created on : 23. 4. 2018
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
#include "app_def.h"
#include "module_def.h"

volatile uint32_t ulSW47701_StartSync = NO;

#ifdef _USE_WITH_BOOT_
#else /* _USE_WITH_BOOT_ */
tPWMDRV_CtrlReg_t * PWMDRV_ = 0;
tGPIO_CtrlReg_t * GPIO_ = 0;
tSCRB_CtrlReg_t * SCRB_ = 0;
tMSPI_CtrlReg_t * MSPI_ = 0;
tWDT_CtrlReg_t * WDT_ = 0;
tTIMER_CtrlReg_t * TIMER_ = 0;
volatile MSPI_Buffer_TypeDef * MSPIBUF_ = 0;
tI2C_CtrlReg_t * I2CS_ = 0;
#endif /* _USE_WITH_BOOT_ */

int main(void)
{
#if (CUSTOMER == MODEL_DEF_FHD_92513_LENOVO || CUSTOMER == MODEL_DEF_FHD_92513_LENOVO_NON_PRIVACY)
	tI2C_DEV_ADDR_t tI2C_DEV_ADDR;
	tI2C_DEV_ADDR.ulBulk = DBGSERIAL->I2C_DEV_ADDR.ulBulk;
	tI2C_DEV_ADDR.tBit.i2c_dev_addr2 = 0x28;
	DBGSERIAL->I2C_DEV_ADDR.ulBulk = tI2C_DEV_ADDR.ulBulk;
#endif /* (CUSTOMER == MODEL_DEF_FHD_92513_LENOVO || CUSTOMER == MODEL_DEF_FHD_92513_LENOVO_NON_PRIVACY) */

//#if ((USED_MODULE_DEF == MODULE_DEF_B_1) || \
//		(USED_MODULE_DEF == MODULE_DEF_S_1) || \
//		(USED_MODULE_DEF == MODULE_DEF_INX_1) || \
//		(USED_MODULE_DEF == MODULE_DEF_A_1))
//	#if (USED_MODULE_DEF == MODULE_DEF_S_1)
		#if USED_TP_LCD_ON_OPERATION
			if(module_Check_LcdOn() == NO)
			{
				while(1)
				{
					if(IS_GPIO_PIN(_GPIO_LCD_ON) == 0x1)
					{
						break;
					}
				}
			}
		#endif /* USED_TP_LCD_ON_OPERATION */

//		#if (USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S01 || USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S02)
//			GPIO_Init(_GPIO_TSYNC_TMIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
//		#endif /* (USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S01 || USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S02) */
//		GPIO_Init(_GPIO_MUX_EN_TPIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
//		#if USED_TPIC_PENEN_ON_OFF_CONTROL
//		GPIO_Init(_GPIO_PEN_EN_GPIO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
//		#endif
//	#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
////		GPIO_Init(_GPIO_TSYNC_TMIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
////		GPIO_Init(_GPIO_MUX_EN_TPIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
////		#if USED_S3_VDD_OE_INPUT_OUTPUT_CTRL
////	//		module_Set_S3_VDD_OddEven_Ctrl(NO);
////			GPIO_Init(_GPIO_VDDO_EVEN_CTRL, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
////		#endif /* USED_S3_VDD_OE_INPUT_OUTPUT_CTRL */
////		#if USED_S3_PGAMMA_SW_I2C_CTRL
////			GPIO_Init(_GPIO_PGMA_SCL, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
////			GPIO_Init(_GPIO_PGMA_SDL, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
////		#endif /* USED_S3_PGAMMA_SW_I2C_CTRL */
//	#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
//#endif /* ((USED_MODULE_DEF == MODULE_DEF_B_1) || (USED_MODULE_DEF == MODULE_DEF_S_1) || (USED_MODULE_DEF == MODULE_DEF_INX_1) || (USED_MODULE_DEF == MODULE_DEF_A_1)) */
	initBoardGPIO();

#ifndef _USE_WITH_BOOT_
	GPIO_Init(_GPIO_TSYNC_OUT, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
	PWMDRV_ = PWMDRV;
	GPIO_ = GPIO;
	SCRB_ = SCRB;
	MSPI_ = MSPI;
	WDT_  = WDT;
	MSPIBUF_ = MSPI_BUF;
	I2CS_ = I2C_2;
	TIMER_ = TIMER;

	GPIO_Init(_GPIO_TP_INTR, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);

	#if USED_START_TIME_OUT_CHECK
		medium_delay(USED_START_TIME_OUT_COUNT);
	#else /* USED_START_TIME_OUT_CHECK */

		while(ulSW47701_StartSync == NO)
		{
			_gT(_GPIO_TP_INTR);
		}
	#endif /* USED_START_TIME_OUT_CHECK */
#endif /* _USE_WITH_BOOT_ */

	app_MainProc();
}

/*
 * NOTE : Caution!!
 * The below IRQ Functions should not be changed address by the build option.
 * We must used O0 option.
 */
#pragma O0

__APP void PendSV_Handler(void)
{
	if(Fncp_PendSV_IRQHandler)
	{
		Fncp_PendSV_IRQHandler();
	}
}

__APP void WDGT_IRQHandler(void)
{
	if(Fncp_WDGT_IRQHandler)
	{
		Fncp_WDGT_IRQHandler();
	}
}

__APP void TIMER_IRQHandler(void)
{
	if(Fncp_TIMER_IRQHandler)
	{
		Fncp_TIMER_IRQHandler();
	}
}

__APP void DBG_I2C_IRQHandler(void)
{
	if(Fncp_DBG_I2C_IRQHandler)
	{
		Fncp_DBG_I2C_IRQHandler();
	}
}

__APP void FLITF_IRQHandler(void)
{
	if(Fncp_FLITF_IRQHandler)
	{
		Fncp_FLITF_IRQHandler();
	}
}

__APP void DBG_SPI_IRQHandler(void)
{
	if(Fncp_DBG_SPI_IRQHandler)
	{
		Fncp_DBG_SPI_IRQHandler();
	}
}

__APP void AB_ACC_IRQHandler(void)
{
	if(Fncp_AB_ACC_IRQHandler)
	{
		Fncp_AB_ACC_IRQHandler();
	}
}

__APP void GDMA_IRQHandler(void)
{
	if(Fncp_GDMA_IRQHandler)
	{
		Fncp_GDMA_IRQHandler();
	}
}

__APP void USER_IRQHandler(void)
{
	if(Fncp_USER_IRQHandler)
	{
		Fncp_USER_IRQHandler();
	}
}

__APP void GPIOA_IRQHandler(void)
{
	if(Fncp_GPIOA_IRQHandler)
	{
		Fncp_GPIOA_IRQHandler();
	}
}

__APP void GPIOM_IRQHandler(void)
{
	if(Fncp_GPIOM_IRQHandler)
	{
		Fncp_GPIOM_IRQHandler();
	}
}

__APP void VSYNC_IN_IRQHandler(void)
{
	if(Fncp_VSYNC_IN_IRQHandler)
	{
		Fncp_VSYNC_IN_IRQHandler();
	}
}

__APP void TSYNC_IN_IRQHandler(void)
{
	if(Fncp_TSYNC_IN_IRQHandler)
	{
		Fncp_TSYNC_IN_IRQHandler();
	}
}

__APP void TSYNC_OUT_IRQHandler(void)
{
	if(Fncp_TSYNC_OUT_IRQHandler)
	{
		Fncp_TSYNC_OUT_IRQHandler();
	}
}

__APP void PWM_IRQHandler(void)
{
	if(Fncp_PWMDRV_IRQHandler)
	{
		Fncp_PWMDRV_IRQHandler();
	}
}

__APP void DSP_A_IRQHandler(void)
{
	if(Fncp_DSP_A_IRQHandler)
	{
		Fncp_DSP_A_IRQHandler();
	}
}

__APP void DSP_B_IRQHandler(void)
{
	if(Fncp_DSP_B_IRQHandler)
	{
		Fncp_DSP_B_IRQHandler();
	}
}

__APP void USB_IRQHandler(void)
{
	if(Fncp_USB_IRQHandler)
	{
		Fncp_USB_IRQHandler();
	}
}

__APP void EXTInterface_IRQHandler(void)
{
	if(Fncp_MSPI_IRQHandler)
	{
		Fncp_MSPI_IRQHandler();
	}
	if(Fncp_TLVDS_IRQHandler)
	{
		Fncp_TLVDS_IRQHandler();
	}
}

__APP void I2C_MST_IRQHandler(void)
{
	if(Fncp_I2C_MST_IRQHandler)
	{
		Fncp_I2C_MST_IRQHandler();
	}
}

__APP void I2C_MST_Sleep_IRQHandler(void)
{
	if(Fncp_I2C_MST_Sleep_IRQHandler)
	{
		Fncp_I2C_MST_Sleep_IRQHandler();
	}
}

__APP void I2C_MST_Wakeup_IRQHandler(void)
{
	if(Fncp_I2C_MST_Wakeup_IRQHandler)
	{
		Fncp_I2C_MST_Wakeup_IRQHandler();
	}
}

__APP void I2C_SLV_IRQHandler(void)
{
	if(Fncp_I2C_SLV_IRQHandler)
	{
		Fncp_I2C_SLV_IRQHandler();
	}
}

__APP void I2C_SLV_Sleep_IRQHandler(void)
{
	if(Fncp_I2C_SLV_Sleep_IRQHandler)
	{
		Fncp_I2C_SLV_Sleep_IRQHandler();
	}
}

__APP void I2C_SLV_Wakeup_IRQHandler(void)
{
	if(Fncp_I2C_SLV_Wakeup_IRQHandler)
	{
		Fncp_I2C_SLV_Wakeup_IRQHandler();
	}
}

