/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_dfup.h
 * created on : 14. 5. 2019
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
#include "param_def.h"
#include "Mspi.h"
#include "DSP_B.h"


static void app_dfup_CopyBootCodeToSram(void)
{
	memset( (void*)CODE_SRAM_START_ADDR, 0x00, FLASH_BOOTLOADER_BYTE_SIZE );

	while(GDMA->GDMA_SR.tBit.busy);

	GDMA->GDMA_SADDR.tBit.saddr = FLASH_BOOTLOADER_START_ADDR;
	GDMA->GDMA_DADDR.tBit.daddr = CODE_SRAM_START_ADDR;
	GDMA->GDMA_CTRL.tBit.TrSize = FLASH_BOOTLOADER_WORD_SIZE;
	GDMA->GDMA_CTRL.tBit.gdma_enable = 1;
	GDMA->GDMA_CTRL.tBit.readonly_en = 0;
	GDMA->GDMA_START = 1;

	while(GDMA->GDMA_SR.tBit.busy);
}

eTouchOperMainState_t app_dfup_oper_handler(void)
{
	eTouchOperMainState_t eRegMainState = TOUCH_MAIN_OPERATION_RESET;

	SCRB->PWM_INT_CTRL.tBit.int_en_tsyncout = 0;	//	T-sync out IRQ disable

	while(!protocol_swip_GetDFUP_Ready());

#ifndef MODE_I2C
	SCRB_USB_Reset();
#endif /* MODE_I2C */
	app_dfup_CopyBootCodeToSram();
	SCRB_Remap_And_Reset(1);

	return eRegMainState;
}
