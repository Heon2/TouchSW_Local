/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : boot_test.c
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


#define USED_TRIMCODE_WRITE_TEST		(FALSE)
#define USED_ONLY_TRIMCODE_CHECK		(FALSE) // SSCG Off시 Clk Sel도 같이 0으로 설정해야함!!
#define USED_HTOL_PROCESS				(TRUE)
#define USED_SSCG_EN_CONTROL_OFF		(TRUE)
#define USED_PLL_READY_RULE				(TRUE) // PLL 설정을 Rule을 지켜서 설정!!
#define USED_ECLK_PATH_SSCG_FOUT		(FALSE)


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

__BOOT void HTOL_SCRB_Initialize(void);

#if USED_HTOL_PROCESS
#define HTOL_MSPI_WRITE_ADDR	(0x300)
#define HTOL_MSPI_WRITE_DATA	(0xAAAA)
#define HTOL_MSPI_NUM			(6)
#define HTOL_WAIT_VSYNC_NUM		(10)
__IO uint32_t gVSyncInitStatus = 0;
__IO uint32_t gVSyncInterruptDone = 0;
uint16_t gMSPI_Read_Buffer[HTOL_MSPI_NUM];

__BOOT void HTOL_PWMDRV_Init(void);
#endif /* USED_HTOL_PROCESS */

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

#if USED_TRIMCODE_WRITE_TEST
static uint16_t CRC16Lut[] = {
	0x0000, 0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
	0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027, 0x0022,
	0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D, 0x8077, 0x0072,
	0x0050, 0x8055, 0x805F, 0x005A, 0x804B, 0x004E, 0x0044, 0x8041,
	0x80C3, 0x00C6, 0x00CC, 0x80C9, 0x00D8, 0x80DD, 0x80D7, 0x00D2,
	0x00F0, 0x80F5, 0x80FF, 0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1,
	0x00A0, 0x80A5, 0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1,
	0x8093, 0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
	0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197, 0x0192,
	0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE, 0x01A4, 0x81A1,
	0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB, 0x01FE, 0x01F4, 0x81F1,
	0x81D3, 0x01D6, 0x01DC, 0x81D9, 0x01C8, 0x81CD, 0x81C7, 0x01C2,
	0x0140, 0x8145, 0x814F, 0x014A, 0x815B, 0x015E, 0x0154, 0x8151,
	0x8173, 0x0176, 0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162,
	0x8123, 0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
	0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104, 0x8101,
	0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D, 0x8317, 0x0312,
	0x0330, 0x8335, 0x833F, 0x033A, 0x832B, 0x032E, 0x0324, 0x8321,
	0x0360, 0x8365, 0x836F, 0x036A, 0x837B, 0x037E, 0x0374, 0x8371,
	0x8353, 0x0356, 0x035C, 0x8359, 0x0348, 0x834D, 0x8347, 0x0342,
	0x03C0, 0x83C5, 0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1,
	0x83F3, 0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
	0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7, 0x03B2,
	0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E, 0x0384, 0x8381,
	0x0280, 0x8285, 0x828F, 0x028A, 0x829B, 0x029E, 0x0294, 0x8291,
	0x82B3, 0x02B6, 0x02BC, 0x82B9, 0x02A8, 0x82AD, 0x82A7, 0x02A2,
	0x82E3, 0x02E6, 0x02EC, 0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2,
	0x02D0, 0x82D5, 0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1,
	0x8243, 0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
	0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264, 0x8261,
	0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E, 0x0234, 0x8231,
	0x8213, 0x0216, 0x021C, 0x8219, 0x0208, 0x820D, 0x8207, 0x0202
};

uint16_t Crc16WordCalc(const uint16_t *DataIn, uint32_t DataLen, uint16_t InitVal)
{
	uint32_t i;
	uint16_t CRCSum;
	uint8_t tempData;

	CRCSum = InitVal;
	for (i = 0; i < DataLen; i += 2)
	{
		tempData = (uint8_t)((DataIn[i] >> 8) & 0xFF);
		CRCSum = (CRCSum << 8) ^ CRC16Lut[((CRCSum >> 8) & 0xFF) ^ tempData];

		tempData = (uint8_t)(DataIn[i] & 0xFF);
		CRCSum = (CRCSum << 8) ^ CRC16Lut[((CRCSum >> 8) & 0xFF) ^ tempData];
	}

	return CRCSum;
}

uint32_t GetCRCValue(const uint16_t * pFWBuf, uint32_t ulSize)
{
	uint32_t ulCRCValue;

	ulCRCValue = Crc16WordCalc((const uint16_t*)&pFWBuf[0], (ulSize>>1), 0) | (Crc16WordCalc((const uint16_t*)&pFWBuf[1], (ulSize>>1), 0) << 16);
	ulCRCValue = ulCRCValue ^ 0xFFFFFFFF;

	return ulCRCValue;
}
#endif /* USED_TRIMCODE_WRITE_TEST */

#if USED_HTOL_PROCESS
__BOOT void HTOL_PWMDRV_Init(void)
{
	/*
	 * V-Sync 설정
	 */
	GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 0x1; // V-Sync_IN
	GPIO->tGPIO_DIR_0._GPIO_VSYNC = 0x0; // input
	// Interrupt 설정
	PWMDRV->INTR_CFG_b.VSYNC_IN_EXT_IE = 1; // Enable
	PWMDRV->INTR_CFG_b.VSYNC_IN_EXT_IEV = 0; // Falling Edge

	/*
	 * T-Sync In 설정
	 */
	GPIO->tGPIO_AFIO_1._GPIO_TSYNC_IN = 0x1; // T-Sync_IN
	GPIO->tGPIO_DIR_0._GPIO_TSYNC_IN = 0x0; // input
	// Interrupt 설정
	PWMDRV->INTR_CFG_b.TSYNC_IN_EXT_IE = 0; // Disable

	/*
	 * T-Sync Out 설정
	 */
	GPIO->tGPIO_AFIO_2._GPIO_TSYNC_OUT = 1;	// T-Sync_OUT
	GPIO->tGPIO_P1_1._GPIO_TSYNC_OUT = 0x1;
	GPIO->tGPIO_P2_1._GPIO_TSYNC_OUT = 0x1;
	PWMDRV->VSWT_CFG_1_b.SEL_TSYNC_OUT = 0; // 0:Ext, 1:Internal, 2:FreeRunning, 3:x
	PWMDRV->GBL_b.SEL_EXT_TSYNC = 1;
	PWMDRV->INTR_CFG_b.TSYNC_OUT_EXT_IE = 1; // Enable
	PWMDRV->INTR_CFG_b.TSYNC_OUT_EXT_IEV = 0; // Falling Edge

	/*
	 * PWM 설정
	 */
	GPIO->tGPIO_AFIO_1._GPIO_PWM_SRIC = 1; // PWM_SRIC
	GPIO->tGPIO_P1_0._GPIO_PWM_SRIC = 0x1;
	GPIO->tGPIO_P2_0._GPIO_PWM_SRIC = 0x1;

#if USED_TEST_OPERATION_ENABLE
	GPIO->tGPIO_AFIO_1._GPIO_PWM_TPIC = 1; // PWM_TPIC (PWM_LFD)
	GPIO->tGPIO_P1_0._GPIO_PWM_TPIC = 0x1;
	GPIO->tGPIO_P2_0._GPIO_PWM_TPIC = 0x1;
#endif

	//FSM INTERRUPT
//	PWMDRV->INTR_CFG_b.FSM_ON_IE = 1; // Enable
//	PWMDRV->INTR_CFG_b.FSM_ON_IEV = 1;
	PWMDRV->INTR_CFG_b.FSM_ON_IE = 0; // Disable
	PWMDRV->VSYNC_FREQ_b.F0_TSYNC = 16; // LHB Setting

	PWMDRV->FW_CTRL_b.PEN_MODE = 0;
	PWMDRV->DSSS_CFG_b.beacon_en = 0;
	PWMDRV->DSSS_CFG_b.ping_en = 0;

	// WFE Enable
	PWMDRV->WFE_CFG_0_b.ENA = 0x3F;

	// PROG_DLY
	PWMDRV->PRLG_b.DLY_0 = 0;
	PWMDRV->PRLG_b.DLY_1 = 0;

	PWMDRV->PRE_0_b.TX_PRD		= 0;
	PWMDRV->PRE_0_b.TX_LOW		= 0;
	PWMDRV->PRE_1_b.TX_NUM		= 0;
	PWMDRV->PRE_1_b.PRE_DLY		= 0;
	PWMDRV->PRE_2_b.DSSS_DLY	= 0;

	// EPLG
	PWMDRV->EPLG_0_b.DLY_0_BEACON		= 0;//PWM_us(224);
	PWMDRV->EPLG_0_b.DLY_1 				= 0;
	PWMDRV->EPLG_1_b.DLY_0_PING_FG_F  	= 0;//PWM_us(184);
	PWMDRV->EPLG_1_b.DLY_0_PING_FG_L  	= 0;
	PWMDRV->EPLG_2_b.DLY_0_PING_PN_P  	= 0;
	PWMDRV->EPLG_2_b.DLY_0_PING_PN_D  	= 0;

	// Pre Tx, DSSS, Active Tx Configuration
	PWMDRV->GBL_b.ENA_PRTX_P0 = 0;
	PWMDRV->GBL_b.ENA_PRTX_D0 = 0;
	PWMDRV->GBL_b.ENA_DSSS_P  = 0;
	PWMDRV->GBL_b.ENA_DSSS_D  = 0;
	PWMDRV->GBL_b.ENA_PRTX_P1 = 1;
	PWMDRV->GBL_b.ENA_PRTX_D1 = 1;
	PWMDRV->GBL_b.ENA_ACTX_PD = 1;

	PWMDRV->ENA_PWM_0_b.T_0 =
	  (0)		// dsss
	| (0 << 1)	// pre
	| (1 << 2)	// act
	| (0 << 3)	// pre_lfd_0 Not Used
	| (0 << 4)	// pre_lfd_1 Not Used
	| (0 << 5)	// act_lfd_0 Not Used
	| (1 << 6);	// act_lfd_1

	PWMDRV->ENA_PWM_0_b.T_1 =
	  (0)		// dsss  mod
	| (0 << 1)	// pre
	| (1 << 2)	// act
	| (0 << 3)	// pre_lfd_0 Not Used
	| (0 << 4)	// pre_lfd_1 Not Used
	| (0 << 5)	// act_lfd_0 Not Used
	| (1 << 6);	// act_lfd_1

	PWMDRV->GBL_b.TSYNC_FREQ_EN_FG_F = 1;
	PWMDRV->FG_F_F0_ACT_0_b.TX_PRD   = PWM_Full_PRD_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz);//PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2);
	PWMDRV->FG_F_F0_ACT_0_b.TX_LOW   = PWM_Half_PRD_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz);//PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2;
	PWMDRV->FG_F_F0_ACT_1_b.TX_NUM   = 3 + 1 + 9;
	PWMDRV->FG_F_F0_ACT_1_b.DLY      = PWM_us(PWMDRV_DEF_FG_F_F0_ACT_DLY_usec);
	PWMDRV->FG_F_F0_ACT_2_b.LINE_NUM = 2;

	PWMDRV->FG_F_F1_ACT_0_b.TX_PRD   = PWM_Full_PRD_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz);//PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2);
	PWMDRV->FG_F_F1_ACT_0_b.TX_LOW   = PWM_Half_PRD_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz);//PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2;
	PWMDRV->FG_F_F1_ACT_1_b.TX_NUM   = 1 + 9;
	PWMDRV->FG_F_F1_ACT_1_b.DLY      = 0;
	PWMDRV->FG_F_F1_ACT_2_b.LINE_NUM = 1;

	PWMDRV->FG_F_F2_ACT_0_b.TX_PRD   = PWM_Full_PRD_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz);//PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2);
	PWMDRV->FG_F_F2_ACT_0_b.TX_LOW   = PWM_Half_PRD_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz);//PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2;
	PWMDRV->FG_F_F2_ACT_1_b.TX_NUM   = 0;
	PWMDRV->FG_F_F2_ACT_1_b.DLY      = 0;
	PWMDRV->FG_F_F2_ACT_2_b.LINE_NUM = 3;

	PWMDRV->FG_F_F3_ACT_0_b.TX_PRD   = PWM_Full_PRD_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz);//PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2);
	PWMDRV->FG_F_F3_ACT_0_b.TX_LOW   = PWM_Half_PRD_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz);//PWM_KHz(PWMDRV_DEF_FG_F_F0_ACT_PRD_KHz + 2)/2;
	PWMDRV->FG_F_F3_ACT_1_b.TX_NUM   = 0;
	PWMDRV->FG_F_F3_ACT_1_b.DLY      = 0;
	PWMDRV->FG_F_F3_ACT_2_b.LINE_NUM = 4;

	PWMDRV->FG_0_b.LHB_01 = 0x0;
	PWMDRV->FG_0_b.LHB_02 = 0x0;
	PWMDRV->FG_0_b.LHB_03 = 0x0;
	PWMDRV->FG_0_b.LHB_04 = 0x0;
	PWMDRV->FG_0_b.LHB_05 = 0x0;
	PWMDRV->FG_0_b.LHB_06 = 0x0;
	PWMDRV->FG_0_b.LHB_07 = 0x0;
	PWMDRV->FG_0_b.LHB_08 = 0x0;
	PWMDRV->FG_0_b.LHB_09 = 0x0;
	PWMDRV->FG_0_b.LHB_10 = 0x0;
	PWMDRV->FG_0_b.LHB_11 = 0x0;
	PWMDRV->FG_0_b.LHB_12 = 0x0;
	PWMDRV->FG_0_b.LHB_13 = 0x0;
	PWMDRV->FG_0_b.LHB_14 = 0x0;
	PWMDRV->FG_0_b.LHB_15 = 0x0;
	PWMDRV->FG_0_b.LHB_16 = 0x0;
	PWMDRV->FG_1_b.LHB_17 = 0x0;
	PWMDRV->FG_1_b.LHB_18 = 0x0;
	PWMDRV->FG_1_b.LHB_19 = 0x0;
	PWMDRV->FG_1_b.LHB_20 = 0x0;
	PWMDRV->FG_1_b.LHB_21 = 0x0;
	PWMDRV->FG_1_b.LHB_22 = 0x0;
	PWMDRV->FG_1_b.LHB_23 = 0x0;
	PWMDRV->FG_1_b.LHB_24 = 0x0;
	PWMDRV->FG_1_b.LHB_25 = 0x0;
	PWMDRV->FG_1_b.LHB_26 = 0x0;
	PWMDRV->FG_1_b.LHB_27 = 0x0;
	PWMDRV->FG_1_b.LHB_28 = 0x0;
	PWMDRV->FG_1_b.LHB_29 = 0x0;
	PWMDRV->FG_1_b.LHB_30 = 0x0;
	PWMDRV->FG_1_b.LHB_31 = 0x0;
	PWMDRV->FG_1_b.LHB_32 = 0x0;

	PWMDRV_ITConfig(ENABLE);
}
#endif /* USED_HTOL_PROCESS */

__BOOT int main(void)
{
	uint32_t ulIdx;
	tFlashTrimCodeInfo_t tTrimmingCode;
	tLGD_OSC_FC_t Local_LGD_OSC_FC;
	tLGD_LDO_FC_t Local_LGD_LDO_FC;
	tMAIN_BIAS_t Local_MAIN_BIAS;
#if USED_TRIMCODE_WRITE_TEST
	// Initialize!!
	SysTick_Initialize(TMCU_MAIN_NOTRIM_CLOCK_SPEED);
	SYSCFG_Initialize(SPI_SCLK_RATIO_PLL_OFF);
	protocol_init();
	tTrimmingCode.OSC_TRIM = 0x3B;//0xA;
	tTrimmingCode.LOSC_TRIM = 0x8;//0x8;
	tTrimmingCode.DLC_LL_TRIM = 0x3;//0x3;
	tTrimmingCode.DLC_HL_CTRL = 0x8;//0x8;
	tTrimmingCode.IREF_TRIM = 0x7;//0xF;
	tTrimmingCode.BOFF_TRIM = 0x3;//0x3;
	tTrimmingCode.DUMMY_[0] = 0;
	tTrimmingCode.DUMMY_[1] = 0;
	tTrimmingCode.DUMMY_[2] = 0;
	tTrimmingCode.DUMMY_[3] = 0;
	tTrimmingCode.DUMMY_[4] = 0;
	tTrimmingCode.DUMMY_[5] = 0;
	tTrimmingCode.DUMMY_[6] = 0;
	tTrimmingCode.DUMMY_[7] = 0;
	SYSCFG_Erase_Sector_Flash(0x0001E000);
	SYSCFG_Read_Status_SPI_Flash(1);

	tTrimmingCode.CRC = GetCRCValue((const uint16_t *)(&tTrimmingCode), SFLASH_TRIM_CODE_BYTE_SIZE - 4);

	SYSCFG_Write_SPI_Flash(SFLASH_TRIM_1_CODE_ADDR, (uint8_t*)&tTrimmingCode, SFLASH_TRIM_CODE_BYTE_SIZE);
	SYSCFG_Read_Status_SPI_Flash(1);
	SYSCFG_Write_SPI_Flash(SFLASH_TRIM_2_CODE_ADDR, (uint8_t*)&tTrimmingCode, SFLASH_TRIM_CODE_BYTE_SIZE);
	SYSCFG_Read_Status_SPI_Flash(1);

	while(1);
#endif /* USED_TRIMCODE_WRITE_TEST */
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
	HTOL_SCRB_Initialize();
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
		GPIO->tGPIO_DIR_1.tBit.GPB10 = 1;
		GPIO->tGPIO_DATA_1.tBit.GPB10 = 0;
		GPIO->tGPIO_DATA_1.tBit.GPB10 = 1;
		GPIO->tGPIO_DATA_1.tBit.GPB10 = 0;
		eBootOperMainState_t Status = Boot_ISP_FlashDownload();
		while(1)
		{
			if(Status == BOOT_OP_STATUS_BOOTCODE_UPDATE_DONE)
			{
				GPIO->tGPIO_DATA_1.tBit.GPB10 = 1;
			}
			else
			{
				GPIO->tGPIO_DATA_1.tBit.GPB10 = 0;
			}
		}
	}
	else
	{
		I2C_Initialize();
	}

#if USED_HTOL_PROCESS
	GPIO->tGPIO_DIR_1.tBit.GPB10 = 1;
	GPIO->tGPIO_DATA_1.tBit.GPB10 = 0;

	/*
	 * Input V-Sync Signal Check!!
	 */
	GPIO->tGPIO_AFIO_1._GPIO_VSYNC = 0x0; // VSYNC
	GPIO->tGPIO_DIR_0._GPIO_VSYNC = 0x0; // input
	for(ulIdx = 0; ulIdx < HTOL_WAIT_VSYNC_NUM; ulIdx++)
	{
		waitVsyncFalling();
	}

	/*
	 * E-Clock 설정
	 */
	GPIO->tGPIO_AFIO_1.tBit.GPA24 = 0x1;  // ECLK0
	GPIO->tGPIO_AFIO_1.tBit.GPA25 = 0x1;  // ECLK1
	GPIO->tGPIO_P1_0.tBit.GPA24 = 0x1;
	GPIO->tGPIO_P2_0.tBit.GPA24 = 0x1;
	GPIO->tGPIO_P1_0.tBit.GPA25 = 0x1;
	GPIO->tGPIO_P2_0.tBit.GPA25 = 0x1;

	tECLK_CFG_t tECLK_CFG;
	tECLK_CFG.ulBulk = SCRB->ECLK_CFG.ulBulk;
#if USED_ECLK_PATH_SSCG_FOUT
	tECLK_CFG.tBit.ECLK_SEL = 11;//2;
#else /* USED_ECLK_PATH_SSCG_FOUT */
	tECLK_CFG.tBit.ECLK_SEL = 2;
#endif /* USED_ECLK_PATH_SSCG_FOUT */
	tECLK_CFG.tBit.ECLK_DIV1 = 0;
	tECLK_CFG.tBit.ECLK_DIV2 = 0;
	tECLK_CFG.tBit.USBPHY_SEL = 0;
	tECLK_CFG.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->ECLK_CFG.ulBulk = tECLK_CFG.ulBulk;

//	SCRB->ECLK_CFG.ulBulk = ( SCB_VECTKEY
//	| 2         << 0
//	| 0         << 4
//	| 0		  << 7
//	| 0  << 9 );

	HTOL_PWMDRV_Init();

//	{
//		PWMDRV_Cmd(ENABLE);
//		PWMDRV->FW_CTRL_b.VSYNC_IN = 1;
//		while(1)
//		{
//		}
//	}

	/*
	 * MSPI 설정
	 */
	MSPI_Initialize();

	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0);
	MSPI_Set_TLPMODE();
//	MSPI_Set_AITMODE();
//	MSPI_ITConfig(ENABLE);

//	MSPI_Cmd(ENABLE);
	PWMDRV_Cmd(ENABLE);
	PWMDRV->FW_CTRL_b.VSYNC_IN = 1;

	for(ulIdx = 0; ulIdx < HTOL_MSPI_NUM; ulIdx++)
	{
		gMSPI_Read_Buffer[ulIdx] = 0;
	}

	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
	gVSyncInitStatus = 1;

	while(1)
	{
		if(gVSyncInterruptDone == 1)
		{
			uint32_t ulSameCount = 0;
			for(ulIdx = 0; ulIdx < HTOL_MSPI_NUM; ulIdx++)
			{
				if(gMSPI_Read_Buffer[ulIdx] == HTOL_MSPI_WRITE_DATA)
				{
					GPIO->tGPIO_DATA_1.tBit.GPB10 = 1;
					GPIO->tGPIO_DATA_1.tBit.GPB10 = 0;
					ulSameCount++;
				}
			}

			for(ulIdx = 0; ulIdx < HTOL_MSPI_NUM; ulIdx++)
			{
				gMSPI_Read_Buffer[ulIdx] = 0;
			}

			gVSyncInterruptDone = 0;
		}
	}
#endif /* USED_HTOL_PROCESS */
#if USED_ONLY_TRIMCODE_CHECK
	// 8. ECLK Configuration
	GPIO->tGPIO_AFIO_1.tBit.GPA24 = 0x1;  // ECLK0
	GPIO->tGPIO_AFIO_1.tBit.GPA25 = 0x1;  // ECLK1
	GPIO->tGPIO_P1_0.tBit.GPA24 = 0x1;
	GPIO->tGPIO_P2_0.tBit.GPA24 = 0x1;
	GPIO->tGPIO_P1_0.tBit.GPA25 = 0x1;
	GPIO->tGPIO_P2_0.tBit.GPA25 = 0x1;

	SCRB->ECLK_CFG.ulBulk = ( SCB_VECTKEY
	| 2         << 0
	| 0         << 4
	| 0		  << 7
	| 0  << 9 );

	while(1)
	{
		;
	}
#endif /* USED_ONLY_TRIMCODE_CHECK */
#if USED_GPIO_TEST_HANDSHAKE
	GPIO->tGPIO_DIR_1.tBit.GPB09 = 1;
#endif /* USED_GPIO_TEST_HANDSHAKE */

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

void PWMDRV_InterruptHandler(void)
{

}

__BOOT void PWMDRV_IRQHandler(void)
{
#if USED_HTOL_PROCESS
	if(PWMDRV->INTR_ST_b.MIS_VSYNC_IN_EXT != 0)
	{
		PWMDRV->INTR_CLR_b.VSYNC_IN_EXT = 0x1;

		if(gVSyncInitStatus == 1)
		{
			uint32_t iMspi;
			gVSyncInterruptDone = 1;

			for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
			{
				MSPI_BUF->SricBuffer[0][iMspi].Data = HTOL_MSPI_WRITE_DATA;
			}
//			MSPI_Set_TLPMODE();
			MSPI_RegisterRead(HTOL_MSPI_WRITE_ADDR, &gMSPI_Read_Buffer[0]);
//			MSPI_Set_AITMODE();
		}
	}

	if(PWMDRV->INTR_ST_b.MIS_TSYNC_OUT_EXT != 0)
	{
		PWMDRV->INTR_CLR_b.TSYNC_OUT_EXT = 0x1;
	}
#endif /* USED_HTOL_PROCESS */
}

//void MSPI_InterruptHandler(void)
//{
//	if ((MSPI->SPIMODE & 0x1) != 0)
//	{
//		if ((MSPI->SINTRMSSR & 0x40) != 0)
//		{
//			MSPI->SINTRMSCR = INTR_MEM_ENA;
//			MSPI->SINTRENCR = 0x1;
//			MSPI->SPISTART = 0x03f/*All SPIs Command*/;
//		}
//	}
//}

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

__BOOT void HTOL_SCRB_Initialize(void)
{
//	GPIO->tGPIO_DIR_1.tBit.GPB10 = 0x1;
//    GPIO->tGPIO_DATA_1.tBit.GPB10 = 1;
	tLGD_OSC_UC_t tLGD_OSC_UC;
	tLGD_OSC_UC.ulBulk = SCRB->LGD_OSC_UC.ulBulk;
	tLGD_OSC_UC.tBit.OSC_PDB_12M = 0; // 내부 클럭 사용시 USB가 동작을 하지 않는다. Default를 외부 클럭으로 설정
	tLGD_OSC_UC.tBit.OSC_PDB_40K = 0;
	tLGD_OSC_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->LGD_OSC_UC.ulBulk = tLGD_OSC_UC.ulBulk;

#ifdef MODE_I2C
	tCK_ENA_RUN0_t tCK_ENA_RUN0;
	tCK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
	tCK_ENA_RUN0.tBit.r_USB_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_WDT_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_TIM_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_LFDTX_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_TSPI_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_DSPA_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_DSPB_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM1_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM2_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM3_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_DMAC_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_I2C_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_FLITF_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_GPIO_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN0.ulBulk = tCK_ENA_RUN0.ulBulk;

	tCK_ENA_RUN1_t tCK_ENA_RUN1;
	tCK_ENA_RUN1.ulBulk = SCRB->CK_ENA_RUN1.ulBulk;
	tCK_ENA_RUN1.tBit.r_MSPI01_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI23_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI45_CLK_ENA = 1;
//	tCK_ENA_RUN1.tBit.r_SIF_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_SFL_CLK_ENA = 0;
	tCK_ENA_RUN1.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN1.ulBulk = tCK_ENA_RUN1.ulBulk;
#else /* MODE_I2C */
	tCK_ENA_RUN0_t tCK_ENA_RUN0;
	tCK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
	tCK_ENA_RUN0.tBit.r_USB_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_WDT_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_TIM_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_LFDTX_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_TSPI_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_DSPA_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_DSPB_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM1_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM2_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM3_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_DMAC_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_I2C_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_FLITF_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_GPIO_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN0.ulBulk = tCK_ENA_RUN0.ulBulk;

	tCK_ENA_RUN1_t tCK_ENA_RUN1;
	tCK_ENA_RUN1.ulBulk = SCRB->CK_ENA_RUN1.ulBulk;
	tCK_ENA_RUN1.tBit.r_MSPI01_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI23_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI45_CLK_ENA = 1;
//	tCK_ENA_RUN1.tBit.r_SIF_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_SFL_CLK_ENA = 0;
	tCK_ENA_RUN1.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN1.ulBulk = tCK_ENA_RUN1.ulBulk;
#endif /* MODE_I2C */

#if USED_PLL_READY_RULE
	tCLK_SRC_SEL_t tCLK_SRC_SEL;
	tCLK_SRC_SEL.ulBulk = SCRB->CLK_SRC_SEL.ulBulk;
	tCLK_SRC_SEL.tBit.CCLK_SEL = 0;
	tCLK_SRC_SEL.tBit.WDCLK_SEL = 2;
	tCLK_SRC_SEL.tBit.TIMCLK_SEL = 0;
#if USED_SSCG_EN_CONTROL_OFF
	tCLK_SRC_SEL.tBit.SSCGOUT_SEL = 0;
	tCLK_SRC_SEL.tBit.SSCGOUT2X_SEL = 0;
#else /* USED_SSCG_EN_CONTROL_OFF */
	tCLK_SRC_SEL.tBit.SSCGOUT_SEL = 1;
	tCLK_SRC_SEL.tBit.SSCGOUT2X_SEL = 1;
#endif /* USED_SSCG_EN_CONTROL_OFF */
	tCLK_SRC_SEL.tBit.TOUCHCLK_SEL = 0;
	tCLK_SRC_SEL.tBit.PLLOUT_SEL = 0;
	tCLK_SRC_SEL.tBit.SSCGIN_SEL = 0;
	tCLK_SRC_SEL.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CLK_SRC_SEL.ulBulk = tCLK_SRC_SEL.ulBulk;
#endif /* USED_PLL_READY_RULE */

	/*
	 * PLL 출력 구하는 공식
	 *                       Fref X (Feedback divider number)
	 * Fout = --------------------------------------------------------
	 *          (Reference divider number) X (Output divider number)
	 */
	tUMC_PLL_UC_t tUMC_PLL_UC;
	tUMC_PLL_UC.ulBulk = SCRB->UMC_PLL_UC.ulBulk;
#if USED_PLL_READY_RULE
	tUMC_PLL_UC.tBit.PLL_STBY_I = 1;
#else /* USED_PLL_READY_RULE */
	tUMC_PLL_UC.tBit.PLL_STBY_I = 0;
#endif /* USED_PLL_READY_RULE */
	tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
	tUMC_PLL_UC.tBit.FBDIV = 15;	// Feedback divider number = (FBDIV) : (5 ~ 50)
	tUMC_PLL_UC.tBit.OUTDIV = 1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	tUMC_PLL_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
//	GPIO->tGPIO_DATA_1.tBit.GPB10 = 0;
//	GPIO->tGPIO_DATA_1.tBit.GPB10 = 1;
	SCRB->UMC_PLL_UC.ulBulk = tUMC_PLL_UC.ulBulk;
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();

#ifdef MODE_I2C
	tUSB_PHY_FC_t tUSB_PHY_FC;
	tUSB_PHY_FC.ulBulk = SCRB->USB_PHY_FC.ulBulk;
	tUSB_PHY_FC.tBit.PLLALIV = 0;
	tUSB_PHY_FC.tBit.PONRST = 0;
	SCRB->USB_PHY_FC.ulBulk = tUSB_PHY_FC.ulBulk;
#else /* MODE_I2C */
	tUSB_PHY_FC_t tUSB_PHY_FC;
	tUSB_PHY_FC.ulBulk = SCRB->USB_PHY_FC.ulBulk;
	tUSB_PHY_FC.tBit.PONRST = 1;
	SCRB->USB_PHY_FC.ulBulk = tUSB_PHY_FC.ulBulk;
#endif /* MODE_I2C */

	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();

	tRST_CTRL_t tRST_CTRL;
	tRST_CTRL.ulBulk = SCRB->RST_CTRL.ulBulk;
	tRST_CTRL.tBit.USB_RSTN_CTRL = 0;
	tRST_CTRL.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->RST_CTRL.ulBulk = tRST_CTRL.ulBulk;

	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();

	tRST_CTRL.tBit.USB_RSTN_CTRL = 1;
	tRST_CTRL.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->RST_CTRL.ulBulk = tRST_CTRL.ulBulk;

#if USED_PLL_READY_RULE
	/*
	 * PLL Div를 변경 한 후.. 적어도50nsec이후에 PLL_STBY_I를 0으로 설정 해 주어야 한다.
	 */
	tUMC_PLL_UC.ulBulk = SCRB->UMC_PLL_UC.ulBulk;
	tUMC_PLL_UC.tBit.PLL_STBY_I = 0;
	tUMC_PLL_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->UMC_PLL_UC.ulBulk = tUMC_PLL_UC.ulBulk;
#endif /* USED_PLL_READY_RULE */

	while (SCRB->UMC_PLL_IS.tBit.PLL_LOCKED_O == 0)
	{
	};
//	GPIO->tGPIO_DATA_1.tBit.GPB10 = 0;
//	GPIO->tGPIO_DATA_1.tBit.GPB10 = 1;

	tCLK_DIV_t tCLK_DIV;
	tCLK_DIV.ulBulk = SCRB->CLK_DIV.ulBulk;
	tCLK_DIV.tBit.HCLK_DIV = 0;
	tCLK_DIV.tBit.PCLK_DIV = 1;
#if USED_ECLK_SOURCE_TIMERCLK

	tCLK_DIV.tBit.TIMCLK_DIV = 0; /*timer clk : 0(/1), 1(/2), ... 7(/128) */
#else /* USED_ECLK_SOURCE_TIMERCLK */
	tCLK_DIV.tBit.TIMCLK_DIV = 2; /*timer clk : 0(/1), 1(/2), ... 7(/128) */
#endif /* USED_ECLK_SOURCE_TIMERCLK */
	tCLK_DIV.tBit.WDTCLK_DIV = 3;
	tCLK_DIV.tBit.SSCGIN_DIV = 3;
	tCLK_DIV.tBit.TOUCHCLK_DIV = 0;
	tCLK_DIV.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CLK_DIV.ulBulk = tCLK_DIV.ulBulk;


#if (!USED_PLL_READY_RULE)
	tCLK_SRC_SEL_t tCLK_SRC_SEL;
#endif /* (!USED_PLL_READY_RULE) */
	tCLK_SRC_SEL.ulBulk = SCRB->CLK_SRC_SEL.ulBulk;
	tCLK_SRC_SEL.tBit.CCLK_SEL = 1;
	tCLK_SRC_SEL.tBit.WDCLK_SEL = 2;
	tCLK_SRC_SEL.tBit.TIMCLK_SEL = 0;
#if USED_SSCG_EN_CONTROL_OFF
	tCLK_SRC_SEL.tBit.SSCGOUT_SEL = 0;
	tCLK_SRC_SEL.tBit.SSCGOUT2X_SEL = 0;
#else /* USED_SSCG_EN_CONTROL_OFF */
	tCLK_SRC_SEL.tBit.SSCGOUT_SEL = 1;
	tCLK_SRC_SEL.tBit.SSCGOUT2X_SEL = 1;
#endif /* USED_SSCG_EN_CONTROL_OFF */
	tCLK_SRC_SEL.tBit.TOUCHCLK_SEL = 0;
	tCLK_SRC_SEL.tBit.PLLOUT_SEL = 0;
	tCLK_SRC_SEL.tBit.SSCGIN_SEL = 0;
	tCLK_SRC_SEL.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CLK_SRC_SEL.ulBulk = tCLK_SRC_SEL.ulBulk;


	tLGD_SSC_FC_t tLGD_SSC_FC;
	tLGD_SSC_FC.ulBulk = SCRB->LGD_SSC_FC.ulBulk;
	tLGD_SSC_FC.tBit.SSCG_MR = 0x7;
	tLGD_SSC_FC.tBit.SSCG_MF = 2;
//	tLGD_SSC_FC.tBit.SSCG_FRAC_EN = 0;
//	tLGD_SSC_FC.tBit.SSCG_ICP = 1;
//	tLGD_SSC_FC.tBit.SSCG_RSEL = 1;
//	tLGD_SSC_FC.tBit.SSCG_KVC = 1;
	tCLK_SRC_SEL.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->LGD_SSC_FC.ulBulk = tLGD_SSC_FC.ulBulk;

	tLGD_SSC_UC_t tLGD_SSC_UC;
	tLGD_SSC_UC.ulBulk = SCRB->LGD_SSC_UC.ulBulk;
	tLGD_SSC_UC.tBit.SSCG_PDB = 0;
	tLGD_SSC_UC.tBit.SSCG_EN = 0;//1;
	tLGD_SSC_UC.tBit.SSCG_INIT = 0;
	tLGD_SSC_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->LGD_SSC_UC.ulBulk = tLGD_SSC_UC.ulBulk;

//	tPMU_CONTROL_t tPMU_CONTROL;
//	tPMU_CONTROL.ulBulk = SCRB->PMU_CONTROL.ulBulk;
//	tPMU_CONTROL.tBit.DLY_SLP = 1;
//	tPMU_CONTROL.tBit.BYPASS_SLP = 1;
//	tPMU_CONTROL.tBit.PMUENABLE = SCB_VECTKEY_VALUE;
//	SCRB->PMU_CONTROL.ulBulk = tPMU_CONTROL.ulBulk;

	SCRB->STCALIB.tBit.NOREF = 0x0;  // 0:-, 1:NoRef
	SCRB->STCALIB.tBit.SYSTICK_SRC = 0x2;  // 0:FCLK/8, 1:40kHz, 2:12MHz, 3:-
}
