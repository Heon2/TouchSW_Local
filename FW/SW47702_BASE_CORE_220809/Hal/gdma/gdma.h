/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : gdma.h
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

#ifndef _DMA_H_
#define _DMA_H_


#define CRC_MODE_NORMAL				(0)
#define CRC_MODE_INIT				(2)
#define CRC_MODE_COMPARE			(3)

extern uint32_t bdma_transfer(uint32_t dest_addr, uint32_t src_addr, uint32_t size_mul_of_4, uint32_t is_intr, uint32_t bst_en, uint32_t bst_num);
extern void gdma_transfer( uint32_t dest_addr, uint32_t src_addr, uint32_t size_mul_of_4, uint32_t is_wait, uint32_t is_intr );
extern uint32_t gdma_crc_test( uint32_t base_addr, uint32_t size_mul_of_4 );
extern void gdma_crc_err_check(uint32_t base_addr, uint32_t size_mul_of_4, uint32_t mode, uint32_t area_sel);
extern uint32_t is_gdma_busy( void );

void GDMA_Initialize(void);
void GDMA_DeInitialize(void);


#endif /* _DMA_H_ */
