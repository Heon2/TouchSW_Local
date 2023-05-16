/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_simple_boot.c
 * created on : 04. 05.2020
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

#include "app_simple_hal.h"
#include "app_simple_boot.h"
#include "gpio.h"

void SimpleBoot_JumpToAppAndRun(void)
{
#define EX_INTR_NUM		(28)//(38)
	int i;
	uint32_t* AppVectorTableAddr =(uint32_t*)(FLASH_APP_START_ADDR);

	// Disable interrupts
	__disable_irq();

	for (i=EX_INTR_NUM; i--;)
		NVIC->ICER[i] = 0xFFFFFFFF ;

	for (i=EX_INTR_NUM; i--;)
		NVIC->ICPR[i] = 0xFFFFFFFF ;

	// Barriers
	__DSB();
	__ISB();

	// Initialize user application's stack pointer
	__set_MSP( AppVectorTableAddr[0]);

	// Change the vector table
	SCB->VTOR = ((uint32_t)AppVectorTableAddr & SCB_VTOR_TBLOFF_Msk);

	// Barriers
	__DSB();
	__ISB();

	// Enable interrupts
	__enable_irq();

	// Load stack & PC
	void (*pFct)(void) = NULL;
	pFct = (void (*)(void))(*(uint32_t *)((uint32_t)AppVectorTableAddr + 4));	// Point on __main address located in the second word in vector table
	pFct();
}

int main(void)
{
	eSimpleBootOperMainState_t eSimpleBootMainState = SIMPLE_BOOT_OP_STATUS_ENTRY;
	tSimpleBootFlashCtrlInfo_t * pSimpleBootFlashCtrlInfo = (tSimpleBootFlashCtrlInfo_t *)SRAM_SIMPLE_BOOT_CTRL_INFO_ADDR;

	while(YES)
	{
		switch(eSimpleBootMainState)
		{
			case SIMPLE_BOOT_OP_STATUS_ENTRY:
			{
//				GPIO_Init(_GPIO_TP_INTR,GPIO_MODE_FUNC_3,GPIO_DIR_OUTPUT,GPIO_DATA_NONE);
//				_gT(_GPIO_TP_INTR);

				SimpleHal_Initialize(pSimpleBootFlashCtrlInfo);

				if(SCRB->BUS_REMAP_ST)
				{
					eSimpleBootMainState = SIMPLE_BOOT_OP_STATUS_FLASH_UPDATE;
				}
				else
				{
					eSimpleBootMainState = SIMPLE_BOOT_OP_STATUS_JUMP_TO_APP_AND_RUN;
				}
				break;
			}
			case SIMPLE_BOOT_OP_STATUS_FLASH_UPDATE:
			{
				uint32_t ulAddr[2];
				uint32_t ulBufWordSize[2], ulIdx;
				uint32_t ulSectionNum = 0;
				uint32_t * pBuf[2];
				switch(pSimpleBootFlashCtrlInfo->ulFlashUpdateType)
				{
					case SIMPLE_BOOT_FLASH_UPDATE_HOST_INTERFACE:
					{
						ulAddr[0] = EFLASH_VID_PID_I2CSLV_1_ADDR;
						ulBufWordSize[0] = EFLASH_VID_PID_I2CSLV_WORD_SIZE;
						pBuf[0] = (uint32_t *)&pSimpleBootFlashCtrlInfo->tFlashBootInterfaceInfo;
						ulAddr[1] = EFLASH_VID_PID_I2CSLV_2_ADDR;
						ulBufWordSize[1] = EFLASH_VID_PID_I2CSLV_WORD_SIZE;
						pBuf[1] = (uint32_t *)&pSimpleBootFlashCtrlInfo->tFlashBootInterfaceInfo;

						ulSectionNum = EFLASH_BOOT_INFO_SECTION_NUM;
						break;
					}
					case SIMPLE_BOOT_FLASH_UPDATE_PT_INFO_WRITE:
					{
						ulAddr[0] = EFLASH_PTINSPECTION_INFO_ADDR;
						ulBufWordSize[0] = EFLASH_PTINSPECTION_INFO_WORD_SIZE;
						pBuf[0] = (uint32_t *)&pSimpleBootFlashCtrlInfo->tFlashPTInspectionInfo;
						ulSectionNum = EFLASH_PTINSPECTION_INFO_SECTION_NUM;
						break;
					}
					case SIMPLE_BOOT_FLASH_UPDATE_TRIM_CODE_WRITE:
					{
						ulAddr[0] = EFLASH_ANALOG_TRIM_1_PT_ADDR;
						ulBufWordSize[0] = EFLASH_ANALOG_TRIM_PT_INFO_WORD_SIZE;
						pBuf[0] = (uint32_t *)&pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo;
						ulAddr[1] = EFLASH_ANALOG_TRIM_1_PT_ADDR + EFLASH_FT_SECTION_BYTE_OFFSET;
						ulBufWordSize[1] = EFLASH_ANALOG_TRIM_FT_INFO_WORD_SIZE;
						pBuf[1] = (uint32_t *)&pSimpleBootFlashCtrlInfo->tFlashFTTrimCodeInfo;
						ulSectionNum = EFLASH_TRIMCODE_SECTION_NUM;
					}
				}

//				{
//					uint32_t * ulFlashBuf = (uint32_t *)EFLASH_VID_PID_I2CSLV_1_ADDR;
//					SCRB->SYS_DUMMY0 = ulFlashBuf[0];
//					SCRB->SYS_DUMMY1 = ulFlashBuf[1];
//					TIMER->SYS_DUMMY2 = ulFlashBuf[2];
//					TIMER->SYS_DUMMY3 = ulFlashBuf[3];
//
//					while(1)
//					{
//						SimplHal_medium_delay(500);
//						_gOut(_GPIO_TP_INTR, GPIO_DATA_LOW);
//						SimplHal_medium_delay(2000);
//						_gOut(_GPIO_TP_INTR, GPIO_DATA_HIGH);
//					}
//				}

				if(ulSectionNum > 0)
				{
					SimplHal_FLASH_Program_Init();

					SimplHal_FLASH_DisableWriteProtection();

					for(ulIdx = 0; ulIdx < ulSectionNum; ulIdx++)
					{
						SimplHal_FLASH_Erase_Page(ulAddr[ulIdx]);
						SimplHal_FLASH_Program_Page(ulAddr[ulIdx], pBuf[ulIdx], ulBufWordSize[ulIdx]);
					}

					SimplHal_FLASH_InitializeRegister();						//	Initialize register

					SimplHal_FLASH_POR_Reset();							//	After execute POR reset, SPP values are applied to SFR

					SimplHal_FLASH_Program_UnInit();
				}

				eSimpleBootMainState = SIMPLE_BOOT_OP_STATUS_JUMP_TO_APP_AND_RUN;
				break;
			}
			case SIMPLE_BOOT_OP_STATUS_JUMP_TO_APP_AND_RUN:
			{
//				_gOut(_GPIO_TP_INTR, GPIO_DATA_LOW);
				WDT->WDOG_CONTROL.tBit.wdt_rst_en = 1;
				WDT->WDOG_RSTCTRL.tBit.watchdog_reset_en = 1;
				WDT->WDOG_LOAD = 0xF;
				while(1);
//				{
//					SimplHal_medium_delay(2000);
//					_gOut(_GPIO_TP_INTR, GPIO_DATA_LOW);
//					SimplHal_medium_delay(2000);
//					_gOut(_GPIO_TP_INTR, GPIO_DATA_HIGH);
//				}
//				break;
			}
			/* no break */
			default:
				break;
		}
	}
}

//void PendSV_Handler(void)
//{
//	if(Fncp_PendSV_IRQHandler)
//	{
//		Fncp_PendSV_IRQHandler();
//	}
//}

//void WDGT_IRQHandler(void)
//{
//	if(Fncp_WDGT_IRQHandler)
//	{
//		Fncp_WDGT_IRQHandler();
//	}
//}

//void TIMER_IRQHandler(void)
//{
//	if(Fncp_TIMER_IRQHandler)
//	{
//		Fncp_TIMER_IRQHandler();
//	}
//}

//void DBG_I2C_IRQHandler(void)
//{
//	if(Fncp_DBG_I2C_IRQHandler)
//	{
//		Fncp_DBG_I2C_IRQHandler();
//	}
//}

//void DBG_SPI_IRQHandler(void)
//{
//	if(Fncp_DBG_SPI_IRQHandler)
//	{
//		Fncp_DBG_SPI_IRQHandler();
//	}
//}

//void AB_ACC_IRQHandler(void)
//{
//	if(Fncp_AB_ACC_IRQHandler)
//	{
//		Fncp_AB_ACC_IRQHandler();
//	}
//}

//void GDMA_IRQHandler(void)
//{
//	if(Fncp_GDMA_IRQHandler)
//	{
//		Fncp_GDMA_IRQHandler();
//	}
//}

//void USER_IRQHandler(void)
//{
//	if(Fncp_USER_IRQHandler)
//	{
//		Fncp_USER_IRQHandler();
//	}
//}

//void GPIOA_IRQHandler(void)
//{
//	if(Fncp_GPIOA_IRQHandler)
//	{
//		Fncp_GPIOA_IRQHandler();
//	}
//}

//void GPIOM_IRQHandler(void)
//{
//	if(Fncp_GPIOM_IRQHandler)
//	{
//		Fncp_GPIOM_IRQHandler();
//	}
//}

//void VSYNC_IN_IRQHandler(void)
//{
//	if(Fncp_VSYNC_IN_IRQHandler)
//	{
//		Fncp_VSYNC_IN_IRQHandler();
//	}
//}

//void TSYNC_IN_IRQHandler(void)
//{
//	if(Fncp_TSYNC_IN_IRQHandler)
//	{
//		Fncp_TSYNC_IN_IRQHandler();
//	}
//}

//void TSYNC_OUT_IRQHandler(void)
//{
//	if(Fncp_TSYNC_OUT_IRQHandler)
//	{
//		Fncp_TSYNC_OUT_IRQHandler();
//	}
//}

//void PWMDRV_IRQHandler(void)
//{
//	if(Fncp_PWMDRV_IRQHandler)
//	{
//		Fncp_PWMDRV_IRQHandler();
//	}
//}

//void DSP_A_IRQHandler(void)
//{
//	if(Fncp_DSP_A_IRQHandler)
//	{
//		Fncp_DSP_A_IRQHandler();
//	}
//}

//void DSP_B_IRQHandler(void)
//{
//	if(Fncp_DSP_B_IRQHandler)
//	{
//		Fncp_DSP_B_IRQHandler();
//	}
//}

//void USB_IRQHandler(void)
//{
//	if(Fncp_USB_IRQHandler)
//	{
//		Fncp_USB_IRQHandler();
//	}
//}

//void EXTInterface_IRQHandler(void)
//{
//	if(Fncp_TLVDS_IRQHandler)
//	{
//		Fncp_TLVDS_IRQHandler();
//	}
//	if(Fncp_MSPI_IRQHandler)
//	{
//		Fncp_MSPI_IRQHandler();
//	}
//}

//void I2C_MST_IRQHandler(void)
//{
//	if(Fncp_I2C_MST_IRQHandler)
//	{
//		Fncp_I2C_MST_IRQHandler();
//	}
//}

//void I2C_MST_Sleep_IRQHandler(void)
//{
//	if(Fncp_I2C_MST_Sleep_IRQHandler)
//	{
//		Fncp_I2C_MST_Sleep_IRQHandler();
//	}
//}

//void I2C_MST_Wakeup_IRQHandler(void)
//{
//	if(Fncp_I2C_MST_Wakeup_IRQHandler)
//	{
//		Fncp_I2C_MST_Wakeup_IRQHandler();
//	}
//}

//void I2C_SLV_IRQHandler(void)
//{
//	if(Fncp_I2C_SLV_IRQHandler)
//	{
//		Fncp_I2C_SLV_IRQHandler();
//	}
//}

//void I2C_SLV_Sleep_IRQHandler(void)
//{
//	if(Fncp_I2C_SLV_Sleep_IRQHandler)
//	{
//		Fncp_I2C_SLV_Sleep_IRQHandler();
//	}
//}

//void I2C_SLV_Wakeup_IRQHandler(void)
//{
//	if(Fncp_I2C_SLV_Wakeup_IRQHandler)
//	{
//		Fncp_I2C_SLV_Wakeup_IRQHandler();
//	}
//}

