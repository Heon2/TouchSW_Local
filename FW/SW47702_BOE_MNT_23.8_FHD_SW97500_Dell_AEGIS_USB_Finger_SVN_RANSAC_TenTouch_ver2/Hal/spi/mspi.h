/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : mspi.h
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

#ifndef _MSPI_H_
#define _MSPI_H_


//----------------------------------------------------------------------------------------------
// MSPI Macro
//----------------------------------------------------------------------------------------------
#define SPI_DISABLE						(0)
#define SPI_ENABLE						(1)

#define SPI_DUALMODE_DISABLE			(0)
#define SPI_DUALMODE_ENABLE				(1)

#define SPI_BITLEN_HALF_WORD			(0)	// txbit_len, rxbit_len : 10~16 bit len
#define SPI_BITLEN_WORD					(1) // txbit_len, rxbit_len : 20~32 bit len

#define SPI_RX_SINGLE_MODE				(0)
#define SPI_RX_DUAL_MODE				(1)

#define SPI_RX_DUAL_BIT_ORDER_MOSI_MISO	(0)
#define SPI_RX_DUAL_BIT_ORDER_MISO_MOSI	(1)

#define SPI_DATA_ORDER_MSB_FIRST		(0)
#define SPI_DATA_ORDER_LSB_FIRST		(1)

#define SPI_CHECK_SUM_DISABLE			(0)
#define SPI_CHECK_SUM_ENABLE			(1)

#define SPI_CH_SEL_0					(1)
#define SPI_CH_SEL_1					(2)
#define SPI_CH_SEL_2					(4)
#define SPI_CH_SEL_3					(8)

/*
 * Speed of SSCG CLK is 2 divided by Source of SSCG Clock.
 * SSCG Clock Source is PLL(96M) or System(x12M)
 * SPI Clock Speed (N+1) divided SSCG CLK
 */
#define SPI_SCLK_SPEED_1_DIV			(0)
#define SPI_SCLK_SPEED_2_DIV			(1)
#define SPI_SCLK_SPEED_3_DIV			(2)
#define SPI_SCLK_SPEED_4_DIV			(3)
#define SPI_SCLK_SPEED_5_DIV			(4)
#define SPI_SCLK_SPEED_6_DIV			(5)
#define SPI_SCLK_SPEED_7_DIV			(6)
#define SPI_SCLK_SPEED_8_DIV			(7)
#define SPI_SCLK_SPEED_9_DIV			(8)
#define SPI_SCLK_SPEED_10_DIV			(9)
#define SPI_SCLK_SPEED_11_DIV			(10)
#define SPI_SCLK_SPEED_12_DIV			(11)

#define SPI_MODE_TLPMODE				(0)
#define SPI_MODE_AITMODE				(1)

#define SPI_MODE_SHAREMODE				(1)
#define SPI_MODE_SINGLEMODE				(0)

/* ================================================================================ */
/* ================           MSPI Interrupt Flag Define           ================ */
/* ================================================================================ */
/*
 * MUX Interrupt Flag
 */
#define IS_SPI_MUX_DONE_INTR_FLAG(a)			((a) & BIT0)
/*
 * FRAME Interrupt Flag
 */
#define IS_SPI_FRAME_DONE_INTR_FLAG(a)			((a) & BIT1)
/*
 * ROIC MISO Interrupt Flag
 */
#define IS_SPI_ALL_ROIC_INTR_FLAG(a)			((a) & (0x3FC))
#define IS_SPI_0_ROIC_INTR_FLAG(a)				((a) & BIT2)
#define IS_SPI_1_ROIC_INTR_Flag(a)				((a) & BIT3)
#define IS_SPI_2_ROIC_INTR_Flag(a)				((a) & BIT4)
#define IS_SPI_3_ROIC_INTR_Flag(a)				((a) & BIT5)
#define IS_SPI_4_ROIC_INTR_Flag(a)				((a) & BIT6)
#define IS_SPI_5_ROIC_INTR_Flag(a)				((a) & BIT7)
#define IS_SPI_6_ROIC_INTR_Flag(a)				((a) & BIT8)
#define IS_SPI_7_ROIC_INTR_Flag(a)				((a) & BIT9)
/*
 * Cehck Sum Error Interrupt Flag
 */
#define IS_SPI_ALL_CHECKSUM_ERROR_INTR_FLAG(a)	((a) & (0x3FC00))
#define IS_SPI_0_CHECKSUM_ERROR_INTR_Flag(a)	((a) & BIT10)
#define IS_SPI_1_CHECKSUM_ERROR_INTR_Flag(a)	((a) & BIT11)
#define IS_SPI_2_CHECKSUM_ERROR_INTR_Flag(a)	((a) & BIT12)
#define IS_SPI_3_CHECKSUM_ERROR_INTR_Flag(a)	((a) & BIT13)
#define IS_SPI_4_CHECKSUM_ERROR_INTR_Flag(a)	((a) & BIT14)
#define IS_SPI_5_CHECKSUM_ERROR_INTR_Flag(a)	((a) & BIT15)
#define IS_SPI_6_CHECKSUM_ERROR_INTR_Flag(a)	((a) & BIT16)
#define IS_SPI_7_CHECKSUM_ERROR_INTR_Flag(a)	((a) & BIT17)
/*
 * MISO ZERO Interrupt Flag
 */
#define IS_SPI_ALL_MISOZERO_INTR_FLAG(a)		((a) & (0x3FC0000))
#define IS_SPI_0_MISOZERO_INTR_Flag(a)			((a) & BIT18)
#define IS_SPI_1_MISOZERO_INTR_Flag(a)			((a) & BIT19)
#define IS_SPI_2_MISOZERO_INTR_Flag(a)			((a) & BIT20)
#define IS_SPI_3_MISOZERO_INTR_Flag(a)			((a) & BIT21)
#define IS_SPI_4_MISOZERO_INTR_Flag(a)			((a) & BIT22)
#define IS_SPI_5_MISOZERO_INTR_Flag(a)			((a) & BIT23)
#define IS_SPI_6_MISOZERO_INTR_Flag(a)			((a) & BIT24)
#define IS_SPI_7_MISOZERO_INTR_Flag(a)			((a) & BIT25)

/* ================================================================================ */
/* ================           MSPI Interrupt Mask Define           ================ */
/* ================================================================================ */
/*
 * ROIC MISO Interrupt Mask
 */
#define SPI_ALL_ROIC_INTR_ENABLE_MASK(a)			((a) |= (0x3FC))//((a) = (a) | (0x3FC))
#define SPI_0_ROIC_INTR_ENABLE_MASK(a)				((a) |= BIT2)
#define SPI_1_ROIC_INTR_ENABLE_MASK(a)				((a) |= BIT3)
#define SPI_2_ROIC_INTR_ENABLE_MASK(a)				((a) |= BIT4)
#define SPI_3_ROIC_INTR_ENABLE_MASK(a)				((a) |= BIT5)
#define SPI_4_ROIC_INTR_ENABLE_MASK(a)				((a) |= BIT6)
#define SPI_5_ROIC_INTR_ENABLE_MASK(a)				((a) |= BIT7)
#define SPI_6_ROIC_INTR_ENABLE_MASK(a)				((a) |= BIT8)
#define SPI_7_ROIC_INTR_ENABLE_MASK(a)				((a) |= BIT9)

#define SPI_ALL_ROIC_INTR_DISABLE_MASK(a)			((a) &= (~(0x3FC)))
#define SPI_0_ROIC_INTR_DISABLE_MASK(a)				((a) &= (~BIT2))
#define SPI_1_ROIC_INTR_DISABLE_MASK(a)				((a) &= (~BIT3))
#define SPI_2_ROIC_INTR_DISABLE_MASK(a)				((a) &= (~BIT4))
#define SPI_3_ROIC_INTR_DISABLE_MASK(a)				((a) &= (~BIT5))
#define SPI_4_ROIC_INTR_DISABLE_MASK(a)				((a) &= (~BIT6))
#define SPI_5_ROIC_INTR_DISABLE_MASK(a)				((a) &= (~BIT7))
#define SPI_6_ROIC_INTR_DISABLE_MASK(a)				((a) &= (~BIT8))
#define SPI_7_ROIC_INTR_DISABLE_MASK(a)				((a) &= (~BIT9))
/*
 * Cehck Sum Error Interrupt Mask
 */
#define SPI_ALL_CHECKSUM_ERROR_INTR_ENABLE_MASK(a)	((a) |= (0x3FC00))
#define SPI_0_CHECKSUM_ERROR_INTR_ENABLE_MASK(a)	((a) |= BIT10)
#define SPI_1_CHECKSUM_ERROR_INTR_ENABLE_MASK(a)	((a) |= BIT11)
#define SPI_2_CHECKSUM_ERROR_INTR_ENABLE_MASK(a)	((a) |= BIT12)
#define SPI_3_CHECKSUM_ERROR_INTR_ENABLE_MASK(a)	((a) |= BIT13)
#define SPI_4_CHECKSUM_ERROR_INTR_ENABLE_MASK(a)	((a) |= BIT14)
#define SPI_5_CHECKSUM_ERROR_INTR_ENABLE_MASK(a)	((a) |= BIT15)
#define SPI_6_CHECKSUM_ERROR_INTR_ENABLE_MASK(a)	((a) |= BIT16)
#define SPI_7_CHECKSUM_ERROR_INTR_ENABLE_MASK(a)	((a) |= BIT17)

#define SPI_ALL_CHECKSUM_ERROR_INTR_DISABLE_MASK(a)	((a) &= (~(0x3FC00)))
#define SPI_0_CHECKSUM_ERROR_INTR_DISABLE_MASK(a)	((a) &= (~BIT10))
#define SPI_1_CHECKSUM_ERROR_INTR_DISABLE_MASK(a)	((a) &= (~BIT11))
#define SPI_2_CHECKSUM_ERROR_INTR_DISABLE_MASK(a)	((a) &= (~BIT12))
#define SPI_3_CHECKSUM_ERROR_INTR_DISABLE_MASK(a)	((a) &= (~BIT13))
#define SPI_4_CHECKSUM_ERROR_INTR_DISABLE_MASK(a)	((a) &= (~BIT14))
#define SPI_5_CHECKSUM_ERROR_INTR_DISABLE_MASK(a)	((a) &= (~BIT15))
#define SPI_6_CHECKSUM_ERROR_INTR_DISABLE_MASK(a)	((a) &= (~BIT16))
#define SPI_7_CHECKSUM_ERROR_INTR_DISABLE_MASK(a)	((a) &= (~BIT17))
/*
 * MISO ZERO Interrupt Mask
 */
#define SPI_ALL_MISOZERO_INTR_ENABLE_MASK(a)		((a) |= (0x3FC0000))
#define SPI_0_MISOZERO_INTR_ENABLE_MASK(a)			((a) |= BIT18)
#define SPI_1_MISOZERO_INTR_ENABLE_MASK(a)			((a) |= BIT19)
#define SPI_2_MISOZERO_INTR_ENABLE_MASK(a)			((a) |= BIT20)
#define SPI_3_MISOZERO_INTR_ENABLE_MASK(a)			((a) |= BIT21)
#define SPI_4_MISOZERO_INTR_ENABLE_MASK(a)			((a) |= BIT22)
#define SPI_5_MISOZERO_INTR_ENABLE_MASK(a)			((a) |= BIT23)
#define SPI_6_MISOZERO_INTR_ENABLE_MASK(a)			((a) |= BIT24)
#define SPI_7_MISOZERO_INTR_ENABLE_MASK(a)			((a) |= BIT25)

#define SPI_ALL_MISOZERO_INTR_DISABLE_MASK(a)		((a) &= (~(0x3FC)))
#define SPI_0_MISOZERO_INTR_DISABLE_MASK(a)			((a) &= (~BIT18))
#define SPI_1_MISOZERO_INTR_DISABLE_MASK(a)			((a) &= (~BIT19))
#define SPI_2_MISOZERO_INTR_DISABLE_MASK(a)			((a) &= (~BIT20))
#define SPI_3_MISOZERO_INTR_DISABLE_MASK(a)			((a) &= (~BIT21))
#define SPI_4_MISOZERO_INTR_DISABLE_MASK(a)			((a) &= (~BIT22))
#define SPI_5_MISOZERO_INTR_DISABLE_MASK(a)			((a) &= (~BIT23))
#define SPI_6_MISOZERO_INTR_DISABLE_MASK(a)			((a) &= (~BIT24))
#define SPI_7_MISOZERO_INTR_DISABLE_MASK(a)			((a) &= (~BIT25))








#define SPI_SYSTEM_CLOCK							((uint32_t)20000000)
#define MSPI_MEM_INDEX(ADDR)                        ((((uint32_t)ADDR) - BASE_RAW_SRAM)>>2)

#define INTR_MEM_ENA            					BIT6
#define INTR_AIT_WLV_ENA        					BIT8

#define SPI_nSS_Auto                                ENABLE
#define SPI_nSS_ExternalTrigger                     DISABLE

#define SPI_nSS_Ext_Disable                         ENABLE
#define SPI_nSS_Ext_Enable                          DISABLE

#define TX_FIFO_IT                              	0x00000001
#define RX_FIFO_IT                              	0x00000002
#define RX_FIFO_OVERUN_IT                       	0x00000004

#define SPISR_BUSY                              	0x00000001
#define SPISR_TxFifoEmpty                       	0x00000002
#define SPISR_TxFifoNotFull                     	0x00000004
#define SPISR_TxFifoUnderWaterlevel             	0x00000008
#define SPISR_RxFifoEmpty                       	0x00000020
#define SPISR_RxFifoNotFull                     	0x00000040
#define SPISR_RxFifoUnderWaterlevel             	0x00000080
#define SPISR_RxOverRun                         	0x00000100

#define SCLK_IS_PCLK_DIV2							(NO)
#define SCLK_IS_PCLK_DIV4							(NO)
#define SCLK_IS_PCLK_DIV6							(YES)
#define SCLK_IS_PCLK_DIV8							(NO)

#define HCLKCOMMEND_DIV2        (0x13)
#define HCLKCOMMEND_DIV3        (0x13)
#define HCLKCOMMEND_DIV4        (0x43)
#define HCLKCOMMEND_DIV6        (0x63)
#define HCLKCOMMEND_DIV8        (0x83)

#define PCLKEND_DIV2            (0x2212)
#define PCLKEND_DIV3            (0x3323)
#define PCLKEND_DIV4            (0x4434)
#define PCLKEND_DIV6            (0x4656)
#define PCLKEND_DIV8            (0x6878)

#define MSPI0_SEL               (BIT(0)|BIT(8))
#define MSPI1_SEL               (BIT(1)|BIT(9))
#define MSPI2_SEL               (BIT(2)|BIT(10))
#define MSPI3_SEL               (BIT(3)|BIT(11))
#define MSPI4_SEL               (BIT(4)|BIT(12))
#define MSPI5_SEL               (BIT(5)|BIT(13))

#define MSPI_RX_EN_0			(BIT(8))
#define MSPI_RX_EN_1			(BIT(9))
#define MSPI_RX_EN_2			(BIT(10))
#define MSPI_RX_EN_3			(BIT(11))
#define MSPI_RX_EN_4			(BIT(12))
#define MSPI_RX_EN_5			(BIT(13))


// Command
#define MSPI_READ               BIT15
#define MSPI_WRITE              (0)

#define MSPI_SINGLE             BIT14
#define MSPI_BURST              (0)

#define MSPI_BROADCAST          BIT13		// Write only

#define MSPI_SHAREMODE          BIT12
#define MSPI_NORMALMODE         (0)

#define MSPI_ROIC_RIGHT         BIT11
#define MSPI_ROIC_LEFT          (0)

#define MSPI_RAWDATA   			BIT10
#define MSPI_CFGR	          	(0)

#define MSPI_AFE	   			BIT8
#define MSPI_DFE	          	(0)

#define MSPI_12BITMODE			BIT13
#define MSPI_16BITMODE			0

#define IDX_SEND                (0)
#define IDX_READ                (1)

typedef enum {

	MSPI_READ_NONE,
	MSPI_READ_SM0_R0,
	MSPI_READ_SM0_R1,
	MSPI_READ_SM1_R0,
	MSPI_READ_SM1_R1,

} eROIC_Read_Option_t;


extern void MSPI_Initialize(void);
extern void MSPI_ITConfig(FunctionalState NewState);
extern void MSPI_Cmd(FunctionalState NewState);
extern void MSPI_IntCLR(void);
extern void MSPI_Set_BUFSIZE_FingerPenMode(int index);
extern void MSPI_GPIO_Init(void);

extern void MSPI_Set_TLPMODE(void);
extern void MSPI_Set_AITMODE(eSENSING_MODE_t eSensingMode);
extern void MSPI_RegisterWrite(uint32_t Addr, uint32_t value);
extern void MSPI_RegisterRead(uint32_t Addr, uint32_t * ReadBuf, eROIC_Read_Option_t eOption);
extern void MSPI_RegisterMultiWrite(uint32_t Addr, uint32_t * value);
#if (USED_ROIC_DEF == ROIC_SW97500)
extern void MSPI_RegisterShareModeMultiWrite(uint32_t Addr, uint32_t * value);
void MSPI_RegisterShareModeSingleWrite(uint32_t Addr, uint32_t value, uint8_t ch);
void MSPI_RegisterSingleWrite(uint32_t Addr, uint32_t * value, uint8_t ch);

#endif /* (USED_ROIC_DEF == ROIC_SW97500) */

#if (USED_ROIC_DEF == ROIC_SW92502)
extern void MSPI_Set_ReadCommand(uint32_t ulNexLHBMode, uint32_t ulCurrentLHBIdx);
#endif /* (USED_ROIC_DEF == ROIC_SW92502) */


#endif /* _MSPI_H_ */
