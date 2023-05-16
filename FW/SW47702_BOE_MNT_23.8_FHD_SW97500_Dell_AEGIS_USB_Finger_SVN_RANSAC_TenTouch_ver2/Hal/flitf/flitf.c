/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : flitf.c
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


/*------------  Header Include -------------------------------------------------*/
#include "hal_def.h"
#include "protocol_def.h"
#include "module_def.h"
#include "crc.h"


static uint32_t CalcIntegrity(uint32_t _Addr, uint8_t _Size)
{
	int i;
	uint32_t ulCheckSum = 0;
	unsigned *Data = (unsigned *)_Addr;

	for (i=0; i<_Size; i++)
	{
		ulCheckSum += *Data++;
	}

	return ulCheckSum;
}

uint32_t vulTrimInfoAddr[EFLASH_TRIMCODE_SECTION_NUM] =
{
	EFLASH_ANALOG_TRIM_1_PT_ADDR, EFLASH_ANALOG_TRIM_2_PT_ADDR,
};

static bool_t CheckFTIntegrity(void)
{
	uint32_t ulIdx, ulAddr;
	tFlashFTTrimCodeInfo_t * ptFlashFTTrimCodeInfo;

	for(ulIdx = 0; ulIdx < EFLASH_TRIMCODE_SECTION_NUM; ulIdx++)
	{
		ulAddr = vulTrimInfoAddr[ulIdx] + EFLASH_FT_SECTION_BYTE_OFFSET;
		ptFlashFTTrimCodeInfo = (tFlashFTTrimCodeInfo_t*)(ulAddr);

		if(ptFlashFTTrimCodeInfo->CHIP_ID_ECC == EFLASH_FT_CHIP_ID_CODE &&
			CalcIntegrity(ulAddr, EFLASH_ANALOG_TRIM_FT_INFO_WORD_SIZE) == 0)
		{
			return YES;
		}
	}

	return NO;
}

static uint32_t CheckPTIntegrity(void)
{
	uint32_t ulIdx, ulAddr;
	tFlashPTTrimCodeInfo_t * pFlashPTTrimCodeInfo;

	for(ulIdx = 0; ulIdx < EFLASH_TRIMCODE_SECTION_NUM; ulIdx++)
	{
		ulAddr = vulTrimInfoAddr[ulIdx];
		pFlashPTTrimCodeInfo = (tFlashPTTrimCodeInfo_t*)(ulAddr);

		if(pFlashPTTrimCodeInfo->ulMagicCode == EFLASH_PT_MAGIC_CODE &&
			CalcIntegrity(ulAddr, EFLASH_ANALOG_TRIM_PT_INFO_WORD_SIZE) == 0)
		{
			return ulAddr;
		}
	}

	return 0;
}

uint32_t FLITF_Calc32bitCheckSum(uint32_t * pCheckSumBuf, uint32_t ulWordSize)
{
//	uint32_t * pCheckSumBuf = (uint32_t *)&pSimpleBootFlashCtrlInfo->tFlashBootInterfaceInfo;
	uint32_t ulIdx;
	uint32_t ulChecksum = 0;
	for(ulIdx = 0; ulIdx < ulWordSize; ulIdx++)
	{
		ulChecksum += pCheckSumBuf[ulIdx];
	}
	ulChecksum = (~ulChecksum) + 1;

	return ulChecksum;
}

bool_t FLITF_CheckTrimInfoSectionIntegrity(tFlashPTTrimCodeInfo_t * ptTrimmingCode)
{
	uint32_t ulPTTrimAddr;
	tFlashPTTrimCodeInfo_t * pFlashPTTrimCodeInfo;
	bool_t bPTCheckSumFail, bFTCheckSumFail;

	bPTCheckSumFail = YES;
	bFTCheckSumFail = YES;

	ulPTTrimAddr = CheckPTIntegrity();
	if (ulPTTrimAddr)
	{
		bPTCheckSumFail = NO;
		pFlashPTTrimCodeInfo = (tFlashPTTrimCodeInfo_t*)(ulPTTrimAddr);

		if(CheckFTIntegrity())
		{
			bFTCheckSumFail = NO;
			memcpy(ptTrimmingCode, pFlashPTTrimCodeInfo, sizeof(tFlashPTTrimCodeInfo_t));
		}
	}

	return !(bPTCheckSumFail || bFTCheckSumFail);
}

bool_t FLITF_EnsureBootInterfaceCodeFlashIntegrity(void)
{
	uint32_t ulIdx;
	tFlashBootInterfaceInfo_t * ptFlashBootInterfaceInfo;
	uint32_t ulAddr = EFLASH_VID_PID_I2CSLV_1_ADDR;

	for(ulIdx = 0; ulIdx < EFLASH_BOOT_INFO_SECTION_NUM; ulIdx++)
	{
		ptFlashBootInterfaceInfo = (tFlashBootInterfaceInfo_t*)(ulAddr);

		if(ptFlashBootInterfaceInfo->BOOT_INFO_WRITE_EN_CODE == EFLASH_BOOT_INFO_WRITE_EN_CODE &&
			CalcIntegrity(ulAddr, EFLASH_VID_PID_I2CSLV_WORD_SIZE) == 0)
		{
			if(ptFlashBootInterfaceInfo->tDeviceId.BOOT_VID == UNIQUE_VID &&
				ptFlashBootInterfaceInfo->tDeviceId.BOOT_PID == UNIQUE_BOOT_PID &&
				ptFlashBootInterfaceInfo->tDeviceInfo.BOOT_I2C_SLV_ADDR == I2C_ADDRESS)
			{
				return YES;
			}
		}

		ulAddr = EFLASH_VID_PID_I2CSLV_2_ADDR;
	}

	return NO;
}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
void FLITF_TPInspectionInfoCodeFlashRead(uint8_t * _pBuf)
{
	tSWIPPTInspectionInfo_t * pFlashPTInspectionInfo = (tSWIPPTInspectionInfo_t*)EFLASH_PTINSPECTION_INFO_ADDR;
	if(CalcIntegrity(EFLASH_PTINSPECTION_INFO_ADDR, EFLASH_PTINSPECTION_INFO_WORD_SIZE) == 0)
	{
		memcpy((void *)_pBuf, (void *)pFlashPTInspectionInfo, sizeof(tSWIPPTInspectionInfo_t));
//		_gT(_GPIO_TP_INTR);
//		_gT(_GPIO_TP_INTR);
	}
	else
	{
		memcpy((void *)_pBuf, (void *)pFlashPTInspectionInfo, sizeof(tSWIPPTInspectionInfo_t));
//		_gT(_GPIO_TP_INTR);
	}
}

void FLITF_TPInspectionInfoCodeFlashWrite(uint8_t * _pBuf)
{
	tSimpleBootFlashCtrlInfo_t * pSimpleBootFlashCtrlInfo = (tSimpleBootFlashCtrlInfo_t *)SRAM_SIMPLE_BOOT_CTRL_INFO_ADDR;
	memcpy((void*)&pSimpleBootFlashCtrlInfo->tFlashPTInspectionInfo, (void *)_pBuf, sizeof(tSimpleBootFlashCtrlInfo_t));

	pSimpleBootFlashCtrlInfo->ulFlashUpdateType = SIMPLE_BOOT_FLASH_UPDATE_PT_INFO_WRITE;

	pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim1.R_OSC12M_VTRIM = SCRB->SYS_ANA_TRIM.tBit.R_OSC12M_VTRIM;
	pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim1.R_OSC12M_ITRIM = SCRB->SYS_ANA_TRIM.tBit.R_OSC12M_ITRIM;
	pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim2.R_LDO_TRIM = SCRB->SYS_ANA_TRIM.tBit.R_LDO_TRIM;
	pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_VBGR_CTL = SCRB->SYS_ANA_TRIM.tBit.R_MAIN_VBGR_CTL;
	pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_IREF_TRIM = SCRB->SYS_ANA_TRIM.tBit.R_MAIN_IREF_TRIM;
	pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_VREF_TRIM = SCRB->SYS_ANA_TRIM.tBit.R_MAIN_VREF_TRIM;

	FLITF_FlashInformationRegionWriteOperation();
}
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

void FLITF_FlashInformationRegionWriteOperation(void)
{
//	SCRB->PWM_INT_CTRL.tBit.int_en_tsyncout = 0;	//	T-sync out IRQ disable
#ifndef MODE_I2C
	SCRB_USB_Reset();
#endif /* MODE_I2C */

	memset( (void*)CODE_SRAM_START_ADDR, 0x00, CODE_SRAM_BYTE_SIZE );

	while(GDMA->GDMA_SR.tBit.busy);

	GDMA->GDMA_SADDR.tBit.saddr = FLASH_SIMPLE_BOOT_START_ADDR;
	GDMA->GDMA_DADDR.tBit.daddr = CODE_SRAM_START_ADDR;
	GDMA->GDMA_CTRL.tBit.TrSize = FLASH_SIMPLE_BOOT_WORD_SIZE;
	GDMA->GDMA_CTRL.tBit.gdma_enable = 1;
	GDMA->GDMA_CTRL.tBit.readonly_en = 0;
	GDMA->GDMA_START = 1;

	while(GDMA->GDMA_SR.tBit.busy);

	SCRB_Remap_And_Reset(1);
}
