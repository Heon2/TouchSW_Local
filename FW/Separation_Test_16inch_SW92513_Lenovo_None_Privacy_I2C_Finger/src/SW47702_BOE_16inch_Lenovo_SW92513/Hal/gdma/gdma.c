/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : gdma.c
 * created on : 05. 9. 2018
 * Author : kimjw
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
#include "module_def.h"


void GDMA_InterruptHandler(void)
{
#
    NVIC_ClearPendingIRQ(GDMA_IRQn);

	if( SCRB->SYS_INT_ST.tBit.crc_error_int) {
//		GDMA->GDMA_CLR.tBit.xxx = 1;
//		GDMA->GDMA_CLR. = 1;	//	ToDo: modify

		static uint32_t is_debug_reported = 0;

		if( !is_debug_reported ) {
			// TO_BE_DEFINED //debug_report(DBG_CRC_ERR, 0, 0);
		}
	}
	else if( SCRB->SYS_INT_ST.tBit.int_gdma ) {
//		GDMA->GDMA_CLR.tBit.xxx = 1;
//		GDMA->GDMA_CLR = 1;		//	ToDo: modify
	}

}

void GDMA_Initialize(void)
{
	Fncp_GDMA_IRQHandler = &GDMA_InterruptHandler;

	NVIC_ClearPendingIRQ(GDMA_IRQn);
	NVIC_SetPriority(GDMA_IRQn, GDMA_IRQn_Priority);
	NVIC_EnableIRQ(GDMA_IRQn);
}

void GDMA_DeInitialize(void)
{
	GDMA->GDMA_CTRL.tBit.Int_En = 0;

	NVIC_DisableIRQ(GDMA_IRQn);
	NVIC_ClearPendingIRQ(GDMA_IRQn);
	Fncp_GDMA_IRQHandler = NULL;
}

void gdma_transfer( uint32_t dest_addr, uint32_t src_addr, uint32_t size_mul_of_4, uint32_t is_wait, uint32_t is_intr )
{
    while( GDMA->GDMA_SR.tBit.busy )
		;

    GDMA->GDMA_CTRL.tBit.gdma_enable   = 1;				// GDMA operation Enable // SHOULD set this bit before others
    GDMA->GDMA_CTRL.tBit.readonly_en   = 0;
    GDMA->GDMA_CTRL.tBit.crc_mode 	  = 0x0;			// normal mode

    GDMA->GDMA_DADDR.w              = dest_addr;
    GDMA->GDMA_SADDR.w              = src_addr;
    GDMA->GDMA_CTRL.tBit.TrSize        = size_mul_of_4;	// GDMA Transfor Size(support only word size)
    GDMA->GDMA_CTRL.tBit.Int_En        = is_intr;		// GDMA Interrupt Enable

    while( GDMA->GDMA_SR.tBit.busy )
		;

    GDMA->GDMA_START                = 1;

    if ( !is_wait )
        return;

    while( GDMA->GDMA_SR.tBit.busy )
        ;
}

uint32_t gdma_crc_test( uint32_t base_addr, uint32_t size_mul_of_4 )
{
    while( GDMA->GDMA_SR.tBit.busy )
		;

    GDMA->GDMA_CTRL.tBit.gdma_enable 	= 1;
    GDMA->GDMA_CTRL.tBit.readonly_en 	= 1;
	GDMA->GDMA_CTRL.tBit.crc_mode 	  	= 0x0;			// normal mode

    GDMA->GDMA_SADDR.w 				= base_addr;
    GDMA->GDMA_CTRL.tBit.TrSize 			= size_mul_of_4;
    GDMA->GDMA_CTRL.tBit.Int_En 			= 0;
	GDMA->GDMA_CTRL.tBit.error_check_mode = 0;			//0: CRC, 1:CheckSum

    while( GDMA->GDMA_SR.tBit.busy )
		;

    GDMA->GDMA_START 					= 1;

    while( GDMA->GDMA_SR.tBit.busy )
		;

    return ( (GDMA->CRC_PASS & 0x01) == 0x01 ); // Pass CRC check block is in flash trans controller
}

void gdma_crc_err_check(uint32_t base_addr, uint32_t size_mul_of_4, uint32_t mode, uint32_t area_sel)
{
	GDMA->GDMA_CTRL.tBit.gdma_enable = 1;
	GDMA->GDMA_CTRL.tBit.readonly_en = 1;

	// mode
	// 2b'0x: CRC_MODE_NORMAL 	(0x0)
	// 2b'10: CRC_MODE_INIT		(0x2)
	// 2b'11: CRC_MODE_COMPARE	(0x3)
	GDMA->GDMA_CTRL.tBit.crc_mode 		= mode;

	// user area selection, 0~7
	GDMA->GDMA_CTRL.tBit.crc_area_sel 	= area_sel;

	GDMA->GDMA_SADDR.w = base_addr;
	GDMA->GDMA_CTRL.tBit.TrSize 			= size_mul_of_4;
	if(mode == CRC_MODE_COMPARE) {
		GDMA->GDMA_CTRL.tBit.Int_En 				= 1;
		GDMA->GDMA_CTRL.tBit.crc_error_int_en 	= 1;
	}

	while( GDMA->GDMA_SR.tBit.busy )
		;

    GDMA->GDMA_START 					= 1;

	if(mode == CRC_MODE_INIT) {
	    while( GDMA->GDMA_SR.tBit.busy )
			;
	}
}

uint32_t is_gdma_busy( void )
{
    return GDMA->GDMA_SR.tBit.busy;
}
