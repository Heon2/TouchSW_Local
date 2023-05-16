/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _gdma.h
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

#ifndef __DMA_H_
#define __DMA_H_


typedef union
{
    struct {
        unsigned    lfsr_clear:                1;
        unsigned    free_running_en:           1;
        unsigned    lfsr_en:                   1;
        unsigned    reserved:                  29;
    } tBit;
    __IO uint32_t w;
} tLFSRCTRL_t;

typedef union
{
    struct {
        unsigned    saddr:                     32;
    } tBit;
    __IO uint32_t w;
} tGDMA_SADDR_t;

typedef union
{
    struct {
        unsigned    daddr:                     32;
    } tBit;
    __IO uint32_t w;
} tGDMA_DADDR_t;

typedef union
{
    struct {
        unsigned    TrSize:                    16;
        unsigned    Int_En:                    1;
        unsigned    arbcnt:                    2;
        unsigned    readonly_en:               1;
        unsigned    gdma_enable:               1;
        unsigned    lfsr_mode:                 1;
        unsigned    writeonly_en:              1;
        unsigned    error_check_mode:          1;
        unsigned    crc_area_sel:              3;
        unsigned    crc_mode:                  2;
        unsigned    crc_error_int_en:          1;
        unsigned    event_en:                  1;
        unsigned    reserved:                  1;
    } tBit;
    __IO uint32_t w;
} tGDMA_CTRL_t;

typedef union
{
    struct {
        unsigned    lfsr_pass_clr:			   1;
        unsigned    int_gdma_clr:			   1;
        unsigned    event_gdma_clr:			   1;
        unsigned    crc_err_int_clr:		   1;
        unsigned    reserved:                  28;
    } tBit;
    __O uint32_t w;
} tGDMA_CLR_t;

typedef union
{
    struct {
        unsigned    status:                    3;
        unsigned    busy:                      1;
        unsigned    lfsr_pass:                 1;
        unsigned    reserved:                  27;
    } tBit;
    __I uint32_t w;
} tGDMA_SR_t;


typedef struct
{
	////////////////////////     LFSR     ////////////////////////////////////
    __IO uint32_t                    LFSRSEED;                       //0x00C0
    __IO tLFSRCTRL_t                 LFSRCTRL;                       //0x00C1
    __I  uint32_t                    LFSR_DATA;                      //0x00C2

    ////////////////////////     GDMA     ////////////////////////////////////
    __IO tGDMA_SADDR_t               GDMA_SADDR;                     //0x00C3
    __IO tGDMA_DADDR_t               GDMA_DADDR;                     //0x00C4
    __IO tGDMA_CTRL_t                GDMA_CTRL;                      //0x00C5
    __O  uint32_t                    GDMA_START;                     //0x00C6
    __O  tGDMA_CLR_t                 GDMA_CLR;                       //0x00C7
    __I  tGDMA_SR_t                  GDMA_SR;                        //0x00C8
    __IO uint32_t                    GDMA_COMPARE_VALID_BIT;         //0x00C9
    __I  uint32_t                    CRC_RESULT;                     //0x00CA
    __I  uint32_t                    CRC_PASS;                       //0x00CB
    __IO uint32_t                    SYS_DUMMY4;                     //0x00CC
    __IO uint32_t                    SYS_DUMMY5;                     //0x00CD

    ////////////////////////     CRC      ////////////////////////////////////
    __I  uint32_t                    CRC_MEMO0;                      //0x00CE
    __I  uint32_t                    CRC_MEMO1;                      //0x00CF
    __I  uint32_t                    CRC_MEMO2;                      //0x00D0
    __I  uint32_t                    CRC_MEMO3;                      //0x00D1
    __I  uint32_t                    CRC_MEMO4;                      //0x00D2
    __I  uint32_t                    CRC_MEMO5;                      //0x00D3
    __I  uint32_t                    CRC_MEMO6;                      //0x00D4
    __I  uint32_t                    CRC_MEMO7;                      //0x00D5
    __I  uint32_t                    CRC_ERROR_STATUS;               //0x00D6
    __IO uint32_t                    GDMA_FIXED_DATA;                //0x00D7
} tGDMA_CtrlReg_t ;


#endif /* __DMA_H_ */
