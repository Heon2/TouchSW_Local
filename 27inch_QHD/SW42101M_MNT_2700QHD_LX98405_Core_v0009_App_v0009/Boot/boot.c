/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : boot.c
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
#include "protocol.h"
#include "boot.h"
#include "boot_dump_app.h"


typedef void (*ptAPP_LOAD_AND_RUN_t)(unsigned int, unsigned int, unsigned int);

__BOOT eBootOperMainState_t Boot_AppCodeDumpAndRun(void)
{
	eBootOperMainState_t eRegMainState = BOOT_OP_STATUS_ERROR_APPCODE_DUMP_ERROR;

	_____TEST_GPB09_HandShake(1, 10);
	/*
	 * App Code 80K를 사용하기 위해 아래의 과정을 거친다.
	 * Step 1 : Flash에 있는 Application Code를 Code SRAM에 Dump수행 하는 Function을 Code SRAM 마지막 512Byte영역에 복사 후 실행
	 * Step 2 : Code SRAM에서 마지막 512Byte를 제외한 전 영역에 Application Code를 Dump 후 Application Reset-Handler호출
	 */
	uint32_t func_size = (uint32_t)Boot_AppCodeLoadAndRun_End - (uint32_t)Boot_AppCodeLoadAndRun;
	uint32_t sram_addr = CODE_SRAM_TOTAL_BYTE_SIZE - CODE_SRAM_APP_RESERV_BYTE_SIZE;
	Boot_ByteCopy((uint8_t*)sram_addr, (uint8_t*)((uint32_t)Boot_AppCodeLoadAndRun-1), func_size);
	_____TEST_GPB09_HandShake(2, 10);

	ptAPP_LOAD_AND_RUN_t pFncAppCodeDumpAndRun = (ptAPP_LOAD_AND_RUN_t)(sram_addr+1);
	pFncAppCodeDumpAndRun(CODE_SRAM_APP_START_BASE_ADDR, SFLASH_APP_START_BASE_ADDR, (CODE_SRAM_APP_WORD_SIZE-CODE_SRAM_APP_RESERV_WORD_SIZE));

	return eRegMainState;
}

__BOOT eBootOperMainState_t Boot_ISP_FlashDownload(void)
{
	eBootOperMainState_t eRegMainState = BOOT_OP_STATUS_ERROR_BOOTCODE_ERROR;
	uint32_t code_crc_result, flash_crc_result;
	uint32_t ulCodeRecordCRCValue, ulFlashRecordCRCValue;
	uint32_t ulMagicCode;
	/*
	 * Code SRAM에 있는 Boot Code의 CRC유효성 체크
	 */
	code_crc_result = SYSCFG_Check_gdma_crc_for_sram(CODE_SRAM_BOOT_START_BASE_ADDR, CODE_SRAM_BOOT_WORD_SIZE, 0); // code sram crc
	if(code_crc_result)
	{
		_____TEST_GPB09_HandShake(2, 1);
		ulCodeRecordCRCValue = ((uint32_t *)CODE_SRAM_BOOT_CRC_CODE_ADDR)[0];
		ulFlashRecordCRCValue = SYSCFG_SPI_BOOT_crc_code_read();
		ulMagicCode = SYSCFG_SPI_magic_code_read();
		flash_crc_result = SYSCFG_Check_dma_crc_for_sflash(SFLASH_BOOT_START_BASE_ADDR, CODE_SRAM_BOOT_WORD_SIZE, 0); // flash crc

		/*
		 * 다음의 경우 Boot Code를 Flash에 Write해 준다.
		 * 1. Flash에 있는 Boot Code의 CRC계산값과 기록값이 틀릴경우
		 * 2. Code SRAM에 있는 Boot Code의 CRC값과 Flash에 있는 Boot Code의 CRC값이 다를 경우
		 * 3. Flash에 있는 Magic Code값이 다를 경우
		 */
		if((flash_crc_result == FALSE) || (ulCodeRecordCRCValue != ulFlashRecordCRCValue) || (ulMagicCode != SFLASH_MAGIC_CODE))
		{
			_____TEST_GPB09_HandShake(3, 1);
			/*
			 * Boot Code를 Flash에 Write할 때는 magic Code를 Erase후 전 영역을 Erase해 준다. 이때, Trimming Code는 Erase해 주면 안되기 때문에 Sector단위로 Erase를 해 주어야 한다.
			 */
			SYSCFG_SPI_magic_code_erase();
			SYSCFG_SPI_boot_code_erase();
			SYSCFG_SPI_app_config_code_erase();
			SYSCFG_DMA_mem_to_flash_transfer(SFLASH_BOOT_START_BASE_ADDR, CODE_SRAM_BOOT_START_BASE_ADDR, CODE_SRAM_BOOT_WORD_SIZE, 1, 0);

			/*
			 * Flash에 새로 Write한 Boot Code의 CRC체크 하여 Flash에 잘 기록이 되었는지 체크 한다.
			 */
			if(SYSCFG_Check_dma_crc_for_sflash(SFLASH_BOOT_START_BASE_ADDR, CODE_SRAM_BOOT_WORD_SIZE, 0)) // flash crc
			{
				_____TEST_GPB09_HandShake(4, 1);
				/*
				 * Flash에 정상 적으로 Boot Code가 Write되었다 판단 되었을 때 Magic Code를 Write해 준 다음 정상 적으로 Write되었는지 Flash에 기록된 값을 Check한다.
				 */
				SYSCFG_SPI_magic_code_write();
				ulMagicCode = SYSCFG_SPI_magic_code_read();
				if(ulMagicCode == SFLASH_MAGIC_CODE)
				{
					_____TEST_GPB09_HandShake(5, 1);
					eRegMainState = BOOT_OP_STATUS_BOOTCODE_UPDATE_DONE;
				}
				else
				{
					eRegMainState = BOOT_OP_STATUS_ERROR_MAGICCODE_UPDATE_FAIL;
				}
			}
			else
			{
				eRegMainState = BOOT_OP_STATUS_ERROR_BOOTCODE_UPDATE_FAIL;
			}
		}
		else
		{
			eRegMainState = BOOT_OP_STATUS_BOOTCODE_DONOT_UPDATE;
		}
	}

	return eRegMainState;
}

__BOOT bool_t EnsureTrimmingCodeFlashIntegrity(tFlashTrimCodeInfo_t * tTrimmingCode)
{
	bool_t bReg = FALSE;
	uint32_t ulTrimCodeAddr = SFLASH_TRIM_1_CODE_ADDR;
	/*
	 * Trimming Code 유효성 체크
	 * Trim Code는 2Set가 Flash에 기록 되어 있다 그렇기 때문에 첫 번째 Trim Code가 유효하지 않다면, 두 번째 Trim Code를 체크한다
	 * 두 번째 Trim Code도 유효하지 않다면... Default값으로 실행 시키도록 한다.
	 */
	if(SYSCFG_Check_dma_crc_for_sflash(ulTrimCodeAddr, SFLASH_TRIM_CODE_WORD_SIZE, 0) == FALSE)
	{
		ulTrimCodeAddr = SFLASH_TRIM_2_CODE_ADDR;
		if(SYSCFG_Check_dma_crc_for_sflash(ulTrimCodeAddr, SFLASH_TRIM_CODE_WORD_SIZE, 0) == FALSE)
		{
			ulTrimCodeAddr = SFLASH_TRIM_CODE_FAIL;
		}
	}

	if(ulTrimCodeAddr != SFLASH_TRIM_CODE_FAIL)
	{
		SYSCFG_SPI_trim_code_read(ulTrimCodeAddr, tTrimmingCode);
		bReg = TRUE;
	}

	return bReg;
}

__BOOT eBootOperMainState_t EnsureBootCodeFlashIntegrity(void)
{
	eBootOperMainState_t eRegMainState = BOOT_OP_STATUS_APPCODE_CHECK;

	/*
	 * NOTE : ISP모드로 Booting이 되지 않았을 때, CodeSRam의 Bootcode CRC는 Check하지 않는다.
	 * ISP모드로 부팅을 하지 않았다면.. H/W에서 Magic Code Check후 Flash에 있는 Bootloader CRC Check후 Code SRAM에 Loading을 한 것이 때문에
	 * 굳이 여기서 또 더블 Check할 필요는 없다.
	 */
	if(I2C->I2C_GLB_SR.tBit.IspMode)
	{
		_____TEST_GPB09_HandShake(1, 1);
		eRegMainState = Boot_ISP_FlashDownload();
	}

	return eRegMainState;
}

__BOOT eBootOperMainState_t EnsureAppCodeFlashIntegrity(void)
{
	eBootOperMainState_t eRegMainState = BOOT_OP_STATUS_APPCODE_UPDATE;

	if(SYSCFG_Check_dma_crc_for_sflash(SFLASH_APP_START_BASE_ADDR, CODE_SRAM_APP_WORD_SIZE - CODE_SRAM_APP_RESERV_WORD_SIZE, 0))
	{
		_____TEST_GPB09_HandShake(4, 30);
		if(SYSCFG_Check_dma_crc_for_sflash(SFLASH_CONFIG_START_BASE_ADDR, SFLASH_CONFIG_WORD_SIZE, 0)) // Configuration flash crc
		{
			eRegMainState = BOOT_OP_STATUS_APPCODE_DUMP_AND_RUN;
		}
	}
	_____TEST_GPB09_HandShake(3, 30);
	return eRegMainState;
}

__BOOT int main(void)
{
	eBootOperMainState_t eBootMainState = BOOT_OP_STATUS_ENTRY;

	while(eBootMainState < BOOT_OP_STATUS_BOOTCODE_UPDATE_DONE)
	{
		switch(eBootMainState)
		{
			case BOOT_OP_STATUS_ENTRY:
			{
				tFlashTrimCodeInfo_t tTrimmingCode;
				tLGD_OSC_FC_t Local_LGD_OSC_FC;
				tLGD_LDO_FC_t Local_LGD_LDO_FC;
				tMAIN_BIAS_t Local_MAIN_BIAS;
				SysTick_Initialize(TMCU_MAIN_NOTRIM_CLOCK_SPEED);
				SYSCFG_Initialize(SPI_SCLK_RATIO_PLL_OFF);
				/*
				 * Flash에 있는 Trim Code를 유효성 검사 후 System Register에 Setting해 준다.
				 */
				if(EnsureTrimmingCodeFlashIntegrity(&tTrimmingCode))
				{
					Local_LGD_OSC_FC.ulBulk = SCRB->LGD_OSC_FC.ulBulk;
					Local_LGD_OSC_FC.tBit.OSC_TRIM = tTrimmingCode.OSC_TRIM;
					Local_LGD_OSC_FC.tBit.LOSC_TRIM = tTrimmingCode.LOSC_TRIM;
					Local_LGD_OSC_FC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
					SCRB->LGD_OSC_FC.ulBulk = Local_LGD_OSC_FC.ulBulk;

					Local_LGD_LDO_FC.ulBulk = SCRB->LGD_LDO_FC.ulBulk;
					Local_LGD_LDO_FC.tBit.DLC_LL_TRIM = tTrimmingCode.DLC_LL_TRIM;
					Local_LGD_LDO_FC.tBit.DLC_HL_CTRL = tTrimmingCode.DLC_HL_CTRL;
					Local_LGD_LDO_FC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
					SCRB->LGD_LDO_FC.ulBulk = Local_LGD_LDO_FC.ulBulk;

					Local_MAIN_BIAS.ulBulk = SCRB->MAIN_BIAS.ulBulk;
					Local_MAIN_BIAS.tBit.IREF_TRIM = tTrimmingCode.IREF_TRIM;
					Local_MAIN_BIAS.tBit.BOFF_TRIM = tTrimmingCode.BOFF_TRIM;
					Local_MAIN_BIAS.tBit._VECTKEY = SCB_VECTKEY_VALUE;
					SCRB->MAIN_BIAS.ulBulk = Local_MAIN_BIAS.ulBulk;
				}
				SCRB_Initialize();
				SysTick_Initialize(TMCU_MAIN_TRIM_CLOCK_SPEED);
				SYSCFG_Initialize(SPI_SCLK_RATIO_PLL_ON);
				// Initialize!!
				protocol_init();
				/*
				 * NOTE : ISP모드로 부팅 시 IAP I2C Slave를 Disable시킨다.
				 * ISP모드로 구동 된 후, F/W에서 I2C를 활성화 시킬 경우
				 * ISP Mode I2C Slave동작과 IAP Mode I2C Slave가 동시에 동작을 하게 된다.
				 * 만약 HOST에서 ISP I2C Slave를 통해 통신을 시도 할 때, IAP I2C Slave가 반응하여 오인식을 하고 의도치 않은 동작이 이루어 지게 되는 Case방지
				 */
				if(I2C->I2C_GLB_SR.tBit.IspMode)
				{
					I2C_DeInitialize();
				}
				else
				{
					I2C_Initialize();
				}
#if USED_GPIO_TEST_HANDSHAKE
				GPIO->tGPIO_DIR_1.tBit.GPB09 = 1;
#endif /* USED_GPIO_TEST_HANDSHAKE */

				eBootMainState = BOOT_OP_STATUS_BOOTCODE_CHECK;
				break;
			}
			case BOOT_OP_STATUS_BOOTCODE_CHECK:
			{
				eBootMainState = EnsureBootCodeFlashIntegrity();
				break;
			}
			case BOOT_OP_STATUS_APPCODE_CHECK:
			{
#if 0 /* Flash Erase */
				SYSCFG_Erase_Chip_Flash();
				while(1)
				{
					_____TEST_GPB09_HandShake(1, (1*1000));
				}
#endif
				eBootMainState = EnsureAppCodeFlashIntegrity();
				break;
			}
			case BOOT_OP_STATUS_APPCODE_UPDATE:
			{
				eBootMainState = Boot_IAP_DownloadHandler();
				break;
			}
			case BOOT_OP_STATUS_TOTALCODE_UPDATE_DONE:
			case BOOT_OP_STATUS_APPCODE_UPDATE_DONE:
			{
				/*
				 * Watch-dog Reset으로 S/W Reset!!
				 */
#if USED_GPIO_TEST_HANDSHAKE
				uint32_t ulErrorClk;
				ulErrorClk = (uint32_t)(eBootMainState);
				while(1)
				{
					_____TEST_GPB09_HandShake(1, (ulErrorClk*1000));
				}
#else /* USED_GPIO_TEST_HANDSHAKE */
#ifdef MODE_WDT
				module_Watch_Enable();
#endif /* MODE_WDT */
				while(1);
#endif /* USED_GPIO_TEST_HANDSHAKE */
				// break;
			}
			/* no break */
			case BOOT_OP_STATUS_APPCODE_DUMP_AND_RUN:
			{
				eBootMainState = Boot_AppCodeDumpAndRun();
				break;
			}
			case BOOT_OP_STATUS_BOOTCODE_UPDATE_DONE:
			case BOOT_OP_STATUS_BOOTCODE_DONOT_UPDATE:
			case BOOT_OP_STATUS_ERROR_BOOTCODE_ERROR:
			case BOOT_OP_STATUS_ERROR_BOOTCODE_UPDATE_FAIL:
			case BOOT_OP_STATUS_ERROR_MAGICCODE_UPDATE_FAIL:
			case BOOT_OP_STATUS_ERROR_APPCODE_ERROR:
			case BOOT_OP_STATUS_ERROR_APPCODE_DUMP_ERROR:
			case BOOT_OP_STATUS_ERROR_APPCODE_UPDATE_FAIL:
			case BOOT_OP_STATUS_ERROR_TOTALCODE_UPDATE_FAIL:
			default:
				break;
		}
	}

#if USED_GPIO_TEST_HANDSHAKE
	{
		uint32_t ulErrorClk;
		ulErrorClk = (uint32_t)(eBootMainState);
		SYSCFG->SYS2EXT_SYS = eBootMainState;
		while(1)
		{
			_____TEST_GPB09_HandShake(1, (ulErrorClk*1000));
		}
	}
#else /* USED_GPIO_TEST_HANDSHAKE */
	while(1);
#endif /* USED_GPIO_TEST_HANDSHAKE */
}

__BOOT void PendSV_Handler(void)
{
	if(Fncp_PendSV_IRQHandler)
	{
		Fncp_PendSV_IRQHandler();
	}
}

__BOOT void SysTick_Handler(void)
{
	if(Fncp_Systick_IRQHandler)
	{
		Fncp_Systick_IRQHandler();
	}
}

__BOOT void I2C_IRQHandler(void)
{
	if(Fncp_I2C_IRQHandler)
	{
		Fncp_I2C_IRQHandler();
	}
}

__BOOT void WDT_IRQHandler(void)
{
	if(Fncp_WDT_IRQHandler)
	{
		Fncp_WDT_IRQHandler();
	}
}

__BOOT void EXTI0_IRQHandler(void)
{
	if(Fncp_EXTI0_IRQHandler)
	{
		Fncp_EXTI0_IRQHandler();
	}
}

__BOOT void EXTI1_IRQHandler(void)
{
	if(Fncp_EXTI1_IRQHandler)
	{
		Fncp_EXTI1_IRQHandler();
	}
}

__BOOT void TIMER_IRQHandler(void)
{
	if(Fncp_TIMER_IRQHandler)
	{
		Fncp_TIMER_IRQHandler();
	}
}

__BOOT void TSPI_IRQHandler(void)
{
	if(Fncp_TSPI_IRQHandler)
	{
		Fncp_TSPI_IRQHandler();
	}
}

__BOOT void USB_IRQHandler(void)
{
	if(Fncp_USB_IRQHandler)
	{
		Fncp_USB_IRQHandler();
	}
}

__BOOT void PWMDRV_IRQHandler(void)
{
	if(Fncp_PWMDRV_IRQHandler)
	{
		Fncp_PWMDRV_IRQHandler();
	}
}

__BOOT void MSPI_IRQHandler(void)
{
	if(Fncp_MSPI_IRQHandler)
	{
		Fncp_MSPI_IRQHandler();
	}
}

__BOOT void GPDMA_IRQHandler(void)
{
	if(Fncp_GPDMA_IRQHandler)
	{
		Fncp_GPDMA_IRQHandler();
	}
}

__BOOT void DSP_A_IRQHandler(void)
{
	if(Fncp_DSP_A_IRQHandler)
	{
		Fncp_DSP_A_IRQHandler();
	}
}

__BOOT void DSP_B_IRQHandler(void)
{
	if(Fncp_DSP_B_IRQHandler)
	{
		Fncp_DSP_B_IRQHandler();
	}
}

__BOOT void PLL_IRQHandler(void)
{
	if(Fncp_PLL_IRQHandler)
	{
		Fncp_PLL_IRQHandler();
	}
}

__BOOT void FLITF_IRQHandler(void)
{
	if(Fncp_FLITF_IRQHandler)
	{
		Fncp_FLITF_IRQHandler();
	}
}
