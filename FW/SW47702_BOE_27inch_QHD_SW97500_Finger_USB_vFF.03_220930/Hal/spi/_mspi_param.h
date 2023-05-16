/******************************************************************************************************
 * Copyright (c) 2019 - 2025 SiliconWorks LIMITED
 *
 * file : _mspi_param.h
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

#ifndef __MSPI_PARAM_H_
#define __MSPI_PARAM_H_


typedef union
{
    struct {
        unsigned	spiTxEna0:					1;
        unsigned	spiTxEna1:					1;
        unsigned	spiTxEna2:					1;
        unsigned	spiTxEna3:					1;
        unsigned	spiTxEna4:					1;
        unsigned	spiTxEna5:					1;
        unsigned	spiTxEna6:					1;
        unsigned	spiTxEna7:					1;
        unsigned	spiRxEna0:					1;
        unsigned	spiRxEna1:					1;
        unsigned	spiRxEna2:					1;
        unsigned	spiRxEna3:					1;
        unsigned	spiRxEna4:					1;
        unsigned	spiRxEna5:					1;
        unsigned	spiRxEna6:					1;
        unsigned	spiRxEna7:					1;
        unsigned	spiTRxEna0:					1;
        unsigned	spiTRxEna1:					1;
        unsigned	spiTRxEna2:					1;
        unsigned	spiTRxEna3:					1;
        unsigned	spiTRxEna4:					1;
        unsigned	spiTRxEna5:					1;
        unsigned	spiTRxEna6:					1;
        unsigned	spiTRxEna7:					1;
        unsigned	reserved:					8;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPIENA_t;

typedef union
{
    struct {
        unsigned	BITLEN:						1;
        unsigned	DUALACC:					1;
        unsigned	DUALBITORD:					1;
        unsigned	TXDORD:						1;
        unsigned	RXDORD:						1;
        unsigned	TXCHKSUM_EN:				1;
        unsigned	RXCHKSUM_EN:				1;
        unsigned	RXPOS:						4;
        unsigned	SCLKDIV:					4;
        unsigned	MISO_ZERO_CHK_EN:			1;
        unsigned	reserved:					16;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPISCR_t;

typedef union
{
    struct {
        unsigned	txdata_len:					8;
        unsigned	rxdata_len:                 8;
        unsigned	txbit_len:                  5;
        unsigned	rxbit_len:                  5;
        unsigned	reserved:					6;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPIDATALEN_t;

typedef union
{
    struct {
        unsigned	int_mux_flag:				1;
        unsigned	int_frame_flag:             1;
        unsigned	int_roic_flag:              8;
        unsigned	int_chksum_flag:            8;
        unsigned	int_misozero_flag:          8;
        unsigned	reserved:					6;
    } __PACKED tBit;
    __I uint32_t ulBulk;
} __PACKED tCP_SINTRFLAG_t;

typedef union
{
    struct {
        unsigned	int_mux_en:					1;
        unsigned	int_frame_en:               1;
        unsigned	int_roic_en:                1;
        unsigned	int_chksum_en:              1;
        unsigned	int_misozero_en:            1;
        unsigned	reserved:					27;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SINTRMSCR_t;

typedef union
{
    struct {
        unsigned	int_roic_mask:				8;
        unsigned	int_misozero_mask:          8;
        unsigned	int_chksum_mask:            8;
        unsigned	reserved:					8;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SINTRMASK_t;

typedef union
{
    struct {
        unsigned	int_mux_clr:				1;
        unsigned	int_frame_clr:              1;
        unsigned	int_roic_clr:               1;
        unsigned	int_chksum_clr:             1;
        unsigned	int_misozero_clr:           1;
        unsigned	reserved:					27;
    } __PACKED tBit;
    __O uint32_t ulBulk;
} __PACKED tCP_SINTRENCLR_t;

typedef union
{
    struct {
        unsigned	spitrsize0:					8;
        unsigned	spitrsize1:					8;
        unsigned	spitrsize2:					8;
        unsigned	spitrsize3:					8;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPITRSIZE0_t;

typedef union
{
    struct {
        unsigned	spitrsize4:					8;
        unsigned	spitrsize5:					8;
        unsigned	spitrsize6:					8;
        unsigned	spitrsize7:					8;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPITRSIZE1_t;

typedef union
{
    struct {
        unsigned	PreShftLen:					8;
        unsigned	TmpIdleLen:                 8;
        unsigned	PostShftLen:                8;
        unsigned	txbufnum:                   5;
        unsigned	reserved:					3;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPISTATELEN_t;

typedef union
{
    struct {
        unsigned	aitmode:					1;
        unsigned	sharemode:                  1;
        unsigned	reserved:					30;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPIMODE_t;

typedef union
{
    struct {
        unsigned	spi0_active:				1;
        unsigned	spi1_active:				1;
        unsigned	spi2_active:				1;
        unsigned	spi3_active:				1;
        unsigned	spi4_active:				1;
        unsigned	spi5_active:				1;
        unsigned	spi6_active:				1;
        unsigned	spi7_active:				1;
        unsigned	reserved:					24;
    } __PACKED tBit;
    __I uint32_t ulBulk;
} __PACKED tCP_SPISR_t;

typedef union
{
    struct {
        unsigned	spiStart0:					1;
        unsigned	spiStart1:					1;
        unsigned	spiStart2:					1;
        unsigned	spiStart3:					1;
        unsigned	spiStart4:					1;
        unsigned	spiStart5:					1;
        unsigned	spiStart6:					1;
        unsigned	spiStart7:					1;
        unsigned	reserved:					24;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPISTART_t;

typedef union
{
    struct {
        unsigned	spiStrtWAd0:				13;
        unsigned	reserved0:                  3;
        unsigned	spiStrtWAd1:                13;
        unsigned	reserved:					3;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPISTRTWAD01_t;

typedef union
{
    struct {
        unsigned	spiStrtWAd2:				13;
        unsigned	reserved1:                  3;
        unsigned	spiStrtWAd3:                13;
        unsigned	reserved:					3;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPISTRTWAD23_t;

typedef union
{
    struct {
        unsigned	spiStrtWAd4:				13;
        unsigned	reserved2:                  3;
        unsigned	spiStrtWAd5:                13;
        unsigned	reserved:					3;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPISTRTWAD45_t;

typedef union
{
    struct {
        unsigned	spiStrtWAd6:				13;
        unsigned	reserved3:                  3;
        unsigned	spiStrtWAd7:                13;
        unsigned	reserved:					3;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPISTRTWAD67_t;

typedef union
{
    struct
	{
        unsigned	spiStrtRAd0:				13;
        unsigned	reserved4:                  3;
        unsigned	spiStrtRAd1:                13;
        unsigned	reserved:					3;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPISTRTRAD01_t;

typedef union
{
    struct {
        unsigned	spiStrtRAd2:				13;
        unsigned	reserved5:                  3;
        unsigned	spiStrtRAd3:                13;
        unsigned	reserved:					3;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPISTRTRAD23_t;

typedef union
{
    struct {
        unsigned	spiStrtRAd4:				13;
        unsigned	reserved6:                  3;
        unsigned	spiStrtRAd5:                13;
        unsigned	reserved:					3;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPISTRTRAD45_t;

typedef union
{
    struct {
        unsigned	spiStrtRAd6:				13;
        unsigned	reserved7:                  3;
        unsigned	spiStrtRAd7:                13;
        unsigned	reserved:					3;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SPISTRTRAD67_t;

typedef union
{
    struct {
        unsigned	share_num:					3;
        unsigned	txaddr_mul:                 13;
        unsigned	reserved:					16;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_MSPI_SHM_CTRL_t;

typedef union
{
    struct {
        unsigned	reserved0:					1;
        unsigned	findex0:                    7;
        unsigned	reserved1:                  1;
        unsigned	findex1:                    7;
        unsigned	reserved2:                  1;
        unsigned	findex2:                    7;
        unsigned	reserved3:                  1;
        unsigned	findex3:                    7;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_MSPI_FINDEX0_t;

typedef union
{
    struct {
        unsigned	reserved4:					1;
        unsigned	findex4:                    7;
        unsigned	reserved5:                  1;
        unsigned	findex5:                    7;
        unsigned	reserved6:                  1;
        unsigned	findex6:                    7;
        unsigned	reserved7:                  1;
        unsigned	findex7:                    7;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_MSPI_FINDEX1_t;


#endif /* __MSPI_PARAM_H_ */
