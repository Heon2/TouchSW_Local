/******************************************************************************************************
 * Copyright (c) 2019 - 2025 SiliconWorks LIMITED
 *
 * file : _mspi.h
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

#ifndef __MSPI_H_
#define __MSPI_H_


#include "_mspi_param.h"
/* ================================================================================ */
/* ================                      MSPI                      ================ */
/* ================================================================================ */
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
    } tBit;
    __IO uint32_t ulBulk;
} tSPIENA_t;

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
    } tBit;
    __IO uint32_t ulBulk;
} tSPISCR_t;

typedef union
{
    struct {
        unsigned	txdata_len:					8;
        unsigned	rxdata_len:                 8;
        unsigned	txbitlen:                  5;
        unsigned	rxbitlen:                  5;
        unsigned	reserved:					6;
    } tBit;
    __IO uint32_t ulBulk;
} tSPIDATALEN_t;

typedef union
{
    struct {
        unsigned	intmux_flag:				1;
        unsigned	intframe_flag:             1;
        unsigned	introic_flag:              8;
        unsigned	intchksum_flag:            8;
        unsigned	intmisozero_flag:          8;
        unsigned	reserved:					6;
    } tBit;
    __I uint32_t ulBulk;
} tSINTRFLAG_t;

typedef union
{
    struct {
        unsigned	intmux_en:					1;
        unsigned	intframe_en:               1;
        unsigned	introic_en:                1;
        unsigned	intchksum_en:              1;
        unsigned	intmisozero_en:            1;
        unsigned	reserved:					27;
    } tBit;
    __IO uint32_t ulBulk;
} tSINTRMSCR_t;

typedef union
{
    struct {
        unsigned	introic_mask:				8;
        unsigned	intmisozero_mask:          8;
        unsigned	intchksum_mask:            8;
        unsigned	reserved:					8;
    } tBit;
    __IO uint32_t ulBulk;
} tSINTRMASK_t;

typedef union
{
    struct {
        unsigned	intmux_clr:				1;
        unsigned	intframe_clr:              1;
        unsigned	introic_clr:               1;
        unsigned	intchksum_clr:             1;
        unsigned	intmisozero_clr:           1;
        unsigned	reserved:					27;
    } tBit;
    __O uint32_t ulBulk;
} tSINTRENCLR_t;

typedef union
{
    struct {
        unsigned	spitrsize0:					8;
        unsigned	spitrsize1:					8;
        unsigned	spitrsize2:					8;
        unsigned	spitrsize3:					8;
    } tBit;
    __IO uint32_t ulBulk;
} tSPITRSIZE0_t;

typedef union
{
    struct {
        unsigned	spitrsize4:					8;
        unsigned	spitrsize5:					8;
        unsigned	spitrsize6:					8;
        unsigned	spitrsize7:					8;
    } tBit;
    __IO uint32_t ulBulk;
} tSPITRSIZE1_t;

typedef union
{
    struct {
        unsigned	PreShftLen:					8;
        unsigned	TmpIdleLen:                 8;
        unsigned	PostShftLen:                8;
        unsigned	txbufnum:                   5;
        unsigned	reserved:					3;
    } tBit;
    __IO uint32_t ulBulk;
} tSPISTATELEN_t;

typedef union
{
    struct {
        unsigned	aitmode:					1;
        unsigned	sharemode:                  1;
        unsigned	reserved:					30;
    } tBit;
    __IO uint32_t ulBulk;
} tSPIMODE_t;

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
    } tBit;
    __I uint32_t ulBulk;
} tSPISR_t;

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
    } tBit;
    __IO uint32_t ulBulk;
} tSPISTART_t;

typedef union
{
    struct {
        unsigned	spiStrtWAd0:				13;
        unsigned	reserved0:                  3;
        unsigned	spiStrtWAd1:                13;
        unsigned	reserved:					3;
    } tBit;
    __IO uint32_t ulBulk;
} tSPISTRTWAD01_t;

typedef union
{
    struct {
        unsigned	spiStrtWAd2:				13;
        unsigned	reserved1:                  3;
        unsigned	spiStrtWAd3:                13;
        unsigned	reserved:					3;
    } tBit;
    __IO uint32_t ulBulk;
} tSPISTRTWAD23_t;

typedef union
{
    struct {
        unsigned	spiStrtWAd4:				13;
        unsigned	reserved2:                  3;
        unsigned	spiStrtWAd5:                13;
        unsigned	reserved:					3;
    } tBit;
    __IO uint32_t ulBulk;
} tSPISTRTWAD45_t;

typedef union
{
    struct {
        unsigned	spiStrtWAd6:				13;
        unsigned	reserved3:                  3;
        unsigned	spiStrtWAd7:                13;
        unsigned	reserved:					3;
    } tBit;
    __IO uint32_t ulBulk;
} tSPISTRTWAD67_t;

typedef union
{
    struct
	{
        unsigned	spiStrtRAd0:				13;
        unsigned	reserved4:                  3;
        unsigned	spiStrtRAd1:                13;
        unsigned	reserved:					3;
    } tBit;
    __IO uint32_t ulBulk;
} tSPISTRTRAD01_t;

typedef union
{
    struct {
        unsigned	spiStrtRAd2:				13;
        unsigned	reserved5:                  3;
        unsigned	spiStrtRAd3:                13;
        unsigned	reserved:					3;
    } tBit;
    __IO uint32_t ulBulk;
} tSPISTRTRAD23_t;

typedef union
{
    struct {
        unsigned	spiStrtRAd4:				13;
        unsigned	reserved6:                  3;
        unsigned	spiStrtRAd5:                13;
        unsigned	reserved:					3;
    } tBit;
    __IO uint32_t ulBulk;
} tSPISTRTRAD45_t;

typedef union
{
    struct {
        unsigned	spiStrtRAd6:				13;
        unsigned	reserved7:                  3;
        unsigned	spiStrtRAd7:                13;
        unsigned	reserved:					3;
    } tBit;
    __IO uint32_t ulBulk;
} tSPISTRTRAD67_t;

typedef union
{
    struct {
        unsigned	share_num:					3;
        unsigned	txaddr_mul:                 13;
        unsigned	reserved:					16;
    } tBit;
    __IO uint32_t ulBulk;
} tMSPI_SHM_CTRL_t;

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
    } tBit;
    __IO uint32_t ulBulk;
} tMSPI_FINDEX0_t;

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
    } tBit;
    __IO uint32_t ulBulk;
} tMSPI_FINDEX1_t;

typedef struct
{
	__IO tSPIENA_t				tSPIENA;
	__IO tSPISCR_t				tSPISCR;
	__IO tSPIDATALEN_t			tSPIDATALEN;
	__I  uint32_t				RESERVED0;
	__I  tSINTRFLAG_t			tSINTRFLAG;
	__IO tSINTRMSCR_t			tSINTRMSCR;
	__IO tSINTRMASK_t			tSINTRMASK;
	__O  tSINTRENCLR_t			tSINTRENCLR;
	__IO tSPITRSIZE0_t			tSPITRSIZE0;
	__IO tSPITRSIZE1_t			tSPITRSIZE1;
	__IO uint32_t				SPIAITSTART; // RX Buffer Address Index Clear
	__IO uint32_t				SPIMUXNUM;
	__IO tSPISTATELEN_t			tSPISTATELEN;
	__IO tSPIMODE_t				tSPIMODE;
	__I  tSPISR_t				tSPISR;
	__IO uint32_t				MSPI_WFE_ENA;
	__IO uint32_t				MSPI_SMPL_DLY;
	__IO tSPISTART_t			tSPISTART;
	__IO tSPISTRTWAD01_t		tSPISTRTWAD01;
	__IO tSPISTRTWAD23_t		tSPISTRTWAD23;
	__IO tSPISTRTWAD45_t		tSPISTRTWAD45;
	__IO tSPISTRTWAD67_t		tSPISTRTWAD67;
	__IO tSPISTRTRAD01_t		tSPISTRTRAD01;
	__IO tSPISTRTRAD23_t		tSPISTRTRAD23;
	__IO tSPISTRTRAD45_t		tSPISTRTRAD45;
	__IO tSPISTRTRAD67_t		tSPISTRTRAD67;
	__IO uint32_t				SPI_SHARE_TERM;
	__IO tMSPI_SHM_CTRL_t		tMSPI_SHM_CTRL;
	__IO tMSPI_FINDEX0_t		tMSPI_FINDEX0;
	__IO tMSPI_FINDEX1_t		tMSPI_FINDEX1;
	__I uint32_t				RESERVED1;
	__I uint32_t				RESERVED2;
	__I uint32_t				RESERVED3;
	__I uint32_t				RESERVED4;
	__I uint32_t				RESERVED5;
	__I uint32_t				RESERVED6;
	__I uint32_t				RESERVED7;
	__I uint32_t				RESERVED8;

} tMSPI_CtrlReg_t;


#endif /* __MSPI_H_ */
