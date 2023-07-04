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
	 * App Code 80K�� ����ϱ� ���� �Ʒ��� ������ ��ģ��.
	 * Step 1 : Flash�� �ִ� Application Code�� Code SRAM�� Dump���� �ϴ� Function�� Code SRAM ������ 512Byte������ ���� �� ����
	 * Step 2 : Code SRAM���� ������ 512Byte�� ������ �� ������ Application Code�� Dump �� Application Reset-Handlerȣ��
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
	 * Code SRAM�� �ִ� Boot Code�� CRC��ȿ�� üũ
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
		 * ������ ��� Boot Code�� Flash�� Write�� �ش�.
		 * 1. Flash�� �ִ� Boot Code�� CRC��갪�� ��ϰ��� Ʋ�����
		 * 2. Code SRAM�� �ִ� Boot Code�� CRC���� Flash�� �ִ� Boot Code�� CRC���� �ٸ� ���
		 * 3. Flash�� �ִ� Magic Code���� �ٸ� ���
		 */
		if((flash_crc_result == FALSE) || (ulCodeRecordCRCValue != ulFlashRecordCRCValue) || (ulMagicCode != SFLASH_MAGIC_CODE))
		{
			_____TEST_GPB09_HandShake(3, 1);
			/*
			 * Boot Code�� Flash�� Write�� ���� magic Code�� Erase�� �� ������ Erase�� �ش�. �̶�, Trimming Code�� Erase�� �ָ� �ȵǱ� ������ Sector������ Erase�� �� �־�� �Ѵ�.
			 */
			SYSCFG_SPI_magic_code_erase();
			SYSCFG_SPI_boot_code_erase();
			SYSCFG_SPI_app_config_code_erase();
			SYSCFG_DMA_mem_to_flash_transfer(SFLASH_BOOT_START_BASE_ADDR, CODE_SRAM_BOOT_START_BASE_ADDR, CODE_SRAM_BOOT_WORD_SIZE, 1, 0);

			/*
			 * Flash�� ���� Write�� Boot Code�� CRCüũ �Ͽ� Flash�� �� ����� �Ǿ����� üũ �Ѵ�.
			 */
			if(SYSCFG_Check_dma_crc_for_sflash(SFLASH_BOOT_START_BASE_ADDR, CODE_SRAM_BOOT_WORD_SIZE, 0)) // flash crc
			{
				_____TEST_GPB09_HandShake(4, 1);
				/*
				 * Flash�� ���� ������ Boot Code�� Write�Ǿ��� �Ǵ� �Ǿ��� �� Magic Code�� Write�� �� ���� ���� ������ Write�Ǿ����� Flash�� ��ϵ� ���� Check�Ѵ�.
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
	 * Trimming Code ��ȿ�� üũ
	 * Trim Code�� 2Set�� Flash�� ��� �Ǿ� �ִ� �׷��� ������ ù ��° Trim Code�� ��ȿ���� �ʴٸ�, �� ��° Trim Code�� üũ�Ѵ�
	 * �� ��° Trim Code�� ��ȿ���� �ʴٸ�... Default������ ���� ��Ű���� �Ѵ�.
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
	 * NOTE : ISP���� Booting�� ���� �ʾ��� ��, CodeSRam�� Bootcode CRC�� Check���� �ʴ´�.
	 * ISP���� ������ ���� �ʾҴٸ�.. H/W���� Magic Code Check�� Flash�� �ִ� Bootloader CRC Check�� Code SRAM�� Loading�� �� ���� ������
	 * ���� ���⼭ �� ���� Check�� �ʿ�� ����.
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
				 * Flash�� �ִ� Trim Code�� ��ȿ�� �˻� �� System Register�� Setting�� �ش�.
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
				 * NOTE : ISP���� ���� �� IAP I2C Slave�� Disable��Ų��.
				 * ISP���� ���� �� ��, F/W���� I2C�� Ȱ��ȭ ��ų ���
				 * ISP Mode I2C Slave���۰� IAP Mode I2C Slave�� ���ÿ� ������ �ϰ� �ȴ�.
				 * ���� HOST���� ISP I2C Slave�� ���� ����� �õ� �� ��, IAP I2C Slave�� �����Ͽ� ���ν��� �ϰ� �ǵ�ġ ���� ������ �̷�� ���� �Ǵ� Case����
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
				 * Watch-dog Reset���� S/W Reset!!
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
