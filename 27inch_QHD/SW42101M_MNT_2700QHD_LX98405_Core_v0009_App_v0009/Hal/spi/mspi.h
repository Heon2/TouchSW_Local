/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : mspi.h
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

#ifndef _MSPI_H_
#define _MSPI_H_


#if USED_FINGER_ONLY
#include "LGD\parameter_mspi_finger.h"
#else /* USED_FINGER_ONLY */
#include "LGD\parameter_mspi_pen.h"
#endif /* USED_FINGER_ONLY */


//----------------------------------------------------------------------------------------------
// MSPI Macro
//----------------------------------------------------------------------------------------------
#define SPI_SYSTEM_CLOCK							((uint32_t)20000000)
#define MSPI_MEM_INDEX(ADDR)                        ((((uint32_t)ADDR) - BASE_MSPI_SRAM)>>2)
#define MSPI_MEM_MSB(ADDR)                        (((((uint32_t)ADDR) - BASE_MSPI_SRAM)>>2))<<16
#define MSPI_MEM_LSB(ADDR)                        ((((uint32_t)ADDR) - BASE_MSPI_SRAM)>>2)

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

#define MSPI_READ               BIT15
#define MSPI_WRITE              (0)
#define MSPI_SINGLE             BIT14
#define MSPI_BURST              (0)

#define IDX_SEND                (0)
#define IDX_READ                (1)

#define MSPI0					(0)
#define MSPI1					(1)
#define MSPI2					(2)
#define MSPI3					(3)
#define MSPI4					(4)
#define MSPI5					(5)

// LX98405 New
typedef enum {

	MSPI_READ_NONE,
	MSPI_READ_SM0,
	MSPI_READ_SM1,

} eROIC_Read_Option_t;



typedef enum {
	LOCAL_0TH_POSITION=0,
	LOCAL_2ND_POSITION=2,
	LOCAL_4TH_POSITION=4,
	LOCAL_6TH_POSITION=6,
	LOCAL_8TH_POSITION=8,
	LOCAL_10TH_POSITION=10,
	LOCAL_12TH_POSITION=12,
	LOCAL_14TH_POSITION=14,
	LOCAL_16TH_POSITION=16,
	LOCAL_18TH_POSITION=18,
	LOCAL_20TH_POSITION=20,
	LOCAL_22ND_POSITION=22,
	LOCAL_24TH_POSITION=24,
	LOCAL_26TH_POSITION=26,
	LOCAL_28TH_POSITION=28,
	LOCAL_30TH_POSITION=30,
	LOCAL_32ND_POSITION=32,
	LOCAL_34TH_POSITION=34,
	LOCAL_36TH_POSITION=36,
	LOCAL_38TH_POSITION=38,
	LOCAL_40TH_POSITION=40
} enum_LOCAL_SENGSING_POSITION;


void MSPI_Initialize(void);
void MSPI_Reset(void);
void MSPI_Set_TLPMODE(void);
void MSPI_Set_AITMODE(eSENSING_MODE_t eSensingMode);
void MSPI_Set_GLF(int divisor) ;
void MSPI_Set_CLK(int divisor);
void MSPI_ITConfig(FunctionalState NewState);
void MSPI_Cmd(FunctionalState NewState);
void MSPI_IntCLR(void);


// LX98405 New ----------------------------------------------------------------------------
void MSPI_RegisterRead( uint32_t Addr, volatile uint32_t *ReadBuf,eROIC_Read_Option_t eOption);
void MSPI_RegisterAllSricWrite (uint32_t Addr, uint32_t value);
void MSPI_RegisterWrite( uint32_t Addr, uint32_t value,eROIC_Read_Option_t eOption);

#if (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405)
void MSPI_RegisterWriteBuf( uint32_t Addr, uint32_t *WriteBuf,eROIC_Read_Option_t eOption);
#endif /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
void MSPI_EachRegisterWrite( uint32_t Addr, uint32_t * pvalue, eROIC_Read_Option_t eOption);

//----------------------------------------------------------------------------------------



void MSPI_CommandWrite( uint32_t write_control, uint32_t pen_mode, uint16_t local_position);

void MSPI_Set_BUFSIZE_FingerPenMode(int index);
#if (!USED_FINGER_ONLY)
void MSPI_Set_BUFSIZE_FingerMode(int index);
#endif /* (!USED_FINGER_ONLY) */
void MSPI_Set_BUFAddress_FingerMode(int index);


void MSPI_Single_Write(uint8_t ch, uint16_t Addr, uint16_t value);
uint16_t MSPI_Single_Read(uint8_t ch, uint16_t Addr);




/*******************************************************************/
void MSPI_Set_FingerMode(void);
void MSPI_GPIO_Init(void);


#endif /* _MSPI_H_ */
