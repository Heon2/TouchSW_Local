/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : boot_dump_app.c
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
#include "boot_dump_app.h"


void Boot_ByteCopy(unsigned char* p_dest_addr, unsigned char* p_src_addr, unsigned int dump_byte_size)
{
	while(dump_byte_size--)
	{
		*p_dest_addr++ = *p_src_addr++;
	}
}

#pragma O0
void Boot_AppCodeLoadAndRun(unsigned int dest_addr, unsigned int src_addr, unsigned int dump_word_size)
{
	// Flash -> CodeSRAM
    while (SYSCFG->FLASH_TRANS_STATUS.tBit.flash_trans_busy);

	SYSCFG->FLASH_TRANS_FSTART_ADDR = src_addr;
	SYSCFG->FLASH_TRANS_MSTART_ADDR = dest_addr;
	SYSCFG->FLASH_TRANS_CFG.tBit.flash_trans_size = dump_word_size;
	SYSCFG->FLASH_TRANS_CFG.tBit.flash_trans_int_en = 0;
	SYSCFG->FLASH_TRANS_CFG.tBit.flash_trans_wr = 0;
	SYSCFG->FLASH_TRANS_CFG.tBit.flash_page_size = 6;
	SYSCFG->FLASH_TRANS_CFG.tBit.SPI_M_CLOCK_SEL = 0;
	SYSCFG->FLASH_TRANS_CTRL.tBit.flash_trans_start = 1;

    while (SYSCFG->FLASH_TRANS_STATUS.tBit.flash_trans_busy);
	
	// CRC Check of CodeSRAM
    while(SYSCFG->GDMA_SR.tBit.busy);

    SYSCFG->GDMA_CTRL.tBit.gdma_enable = 1;
    SYSCFG->GDMA_SADDR.ulBulk = dest_addr;
    SYSCFG->GDMA_CTRL.tBit.TrSize = dump_word_size;
    SYSCFG->GDMA_CTRL.tBit.Int_En = 0;
    SYSCFG->GDMA_CTRL.tBit.readonly_en = 1;
    SYSCFG->GDMA_START = 1;

    while(SYSCFG->GDMA_SR.tBit.busy);

    if((SYSCFG->FLASH_CRC_PASS & 0x01) != 0x01)
    {
        return;
    }
	
	// Jump to ResetHandler
typedef void (*_RESET_VECTOR)(void);
	volatile uint32_t* p_reset_vector = (volatile uint32_t*)0x4;
	((_RESET_VECTOR)p_reset_vector[0])();
	
	while(1);
}

void Boot_AppCodeLoadAndRun_End(void)
{
}
