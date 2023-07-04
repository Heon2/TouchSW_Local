/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : tspi.h
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

#ifndef _TSPI_H_
#define _TSPI_H_


//#define SPI_SYSTEM_CLOCK							    ((uint32_t)20000000)

#define SPI_DataBit_8bit							    0x00
#define SPI_DataBit_10bit							    0x01
#define SPI_DataBit_12bit							    0x02
#define SPI_DataBit_16bit							    0x03

#define SPI_MOSI_Enable                         	    ENABLE
#define SPI_MOSI_Disable                        	    DISABLE

#define LeadingEdge_Setup_TrailingEdge_Sample		    ENABLE
#define LeadingEdge_Sample_TrailingEdge_Setup		    DISABLE

#define LeadingEdge_Falling_TrailingEdge_Rising		    ENABLE
#define LeadingEdge_Rising_TrailingEdge_Falling		    DISABLE

#define SPI_Master									    ENABLE
#define SPI_Slave									    DISABLE

#define SPI_LSB										    ENABLE
#define SPI_MSB										    DISABLE

#define SPI_LOOP_BACK_Enable						    ENABLE
#define SPI_LOOP_BACK_Disable						    DISABLE

#define TX_FIFO_IT                              	    0x00000001
#define RX_FIFO_IT                              	    0x00000002
#define RX_FIFO_OVERUN_IT                       	    0x00000004

#define SPI_TX_DMA_Enable                               BIT12
#define SPI_RX_DMA_Enable                               BIT13
#define SPI_TX_DMA_Disable                              0x00000003
#define SPI_RX_DMA_Disable                              0x00000004

#define SPI_DMA_SIZE                                	64
#define SPI_IT_ENABLE
#define SPI_DMA_ENABLE

#define SPISR_BUSY                                      0x00000001
#define SPISR_TxFifoEmpty                               0x00000002
#define SPISR_TxFifoNotFull                             0x00000004
#define SPISR_TxFifoOverWaterlevel                      0x00000008
#define SPISR_TxFifoOverflow                            0x00000010
#define SPISR_TxFifoUnderrun                            0x00000020
        
#define SPISR_RxFifoNotEmpty                            0x00000040
#define SPISR_RxFifoFull                                0x00000080
#define SPISR_RxFifoOverWaterlevel                      0x00000100
#define SPISR_RxFifoOverflow                            0x00000200
#define SPISR_RxFifoUnderrun                            0x00000400
        
#define SPIINTERRUPT_TXFIFO                             0x00000001
#define SPIINTERRUPT_RXFIFO                             0x00000002
#define SPIINTERRUPT_TXUNDERRUN                         0x00000004
#define SPIINTERRUPT_RXUNDERRUN                         0x00000008
#define SPIINTERRUPT_TXOVERRUN                          0x00000010
#define SPIINTERRUPT_RXOVERRUN                          0x00000020
        
#define SPI_TXFIFO_CLEAR                                0x00000001
#define SPI_RXFIFO_CLEAR                                0x00000002
        
#define PIN_TSPI_SLV_SSN                                GPIO_Pin_4
#define PIN_TSPI_SLV_SCLK                               GPIO_Pin_5
#define PIN_TSPI_SLV_MOSI                               GPIO_Pin_6
#define PIN_TSPI_SLV_MISO                               GPIO_Pin_7

typedef struct
{
    volatile int bRunning;
    volatile int bIsSlotData;
    volatile int bSampleDone;
} tTSPI_status_t;

extern tTSPI_status_t MSPI_Status;
extern tTSPI_status_t TSPI_Status;

extern void init_tspi(void);

extern void TSPI_MasterDataSend(uint16_t data);
extern uint16_t TSPI_ReceiveData(void);

extern void TSPI_MasterBufferSendBytes(volatile uint8_t* buffer, uint8_t Sz);
extern void TSPI_MasterBufferReadBytes(volatile uint8_t* buffer, uint8_t Sz);
extern void TSPI_MasterBufferRead2Bytes(volatile uint16_t* buffer, uint8_t Sz);
extern void TSPI_DmaChannelInit(uint8_t Mode, volatile uint16_t* pDMAbuffer, uint16_t DMAbufferSize);



// SPICR Reg Typedef
typedef union
{
    uint32_t pReg;
    struct
    {
        uint32_t BITLEN:2;                  // Bit Length                               2    00:8bit, 01:10Bit, 02:12Bit, 03:16Bit
        uint32_t DOUTEN:1;                  // Data Out Enable                          3    1:MOSI Enable, 0:Disable
        uint32_t CPHA:1;                    // Clock Phase                              4    1:Leading Edge - Setup, Trailing Edge - Sample,   0: Leading Edge - Sample, Trailing Edge - Setup
        uint32_t CPOL:1;                    // Clock Polarity                           5    1:Leading Edge - Falling, Trailing Edge - Rising,   0:Leading Edge - Rising, Trailing Edge - Falling
        uint32_t MSTR:1;                    // Mster/Slave Select                       6    1:Master, 0:Slave
        uint32_t DORD:1;                    // Data Order                               7    1:LSB First, 0:MSB First (Default)
        uint32_t SPE:1;                     // SPI Enable                               8
        uint32_t LBM:1;                     // LooP Back Mode                           9    1:LOOP_BACK_MODE, 0:Normal Operation
        uint32_t SSOSEL:1;                  // SSO Select                               10   1:External Control SSO Signal, 0:Auto Generation SSO SPI Slave Select
        uint32_t SSOEXT:1;                  // Master SSO Signal Register Setting       11   1:Master Slave Select Disable, 0:Master Slave Select Enable
        uint32_t NOT_USED1:5;               // Not Used                                 12     Not Used
        uint32_t SPR:3;                     // SPI Baud Rate Select Bit                 17   SPI SCLK Frequency Control at Master Mode
        uint32_t NOT_USED2:1;               // Not Used                                 20     Not Used
        uint32_t SPPR:3;                    // SPI Baud Rate Pre-selection Bits         21   SPI SCLK Frequency Control at Master Mode
        uint32_t NOT_USED3:9;               // Not Used                                 24     Not Used
    } Reg;
} TSPI_SPICR_TypeDef;

// SPIDR Reg Typedef
typedef union
{
	uint32_t pReg;
	struct{
		// TX
		uint32_t DR 		:16;		// Data Register,				1	Transmit /Receive FIFO
		uint32_t NOT_USED   :16;        // Not Used                    24     Not Used
	}Reg;
} TSPI_SPIDR_TypeDef;    
    
// SPISR Reg Typedef
typedef union
{
	uint32_t pReg;
	struct{
		// TX
		uint32_t BUSY		:1;		// Busy Flag,				1	1:transmitting and/or receiving or FIFO empty
		uint32_t TFE		:1;		// Tx FIFO Empty Status		2	1:Tx FIFO empty, 0:Tx FIFO not empty
		uint32_t TNF		:1;		// Tx FIFO Full Status		3	1:Tx FIFO is not full, 0:Tx FIFO is full
		uint32_t TWMLF		:1;		// Tx FIFO Water L. Full	4	1:Tx FIFO >= Tx Water Level,   0:Tx FIFO < Tx Water Level
		uint32_t TFOF		:1;		// Tx FIFO Over Flow Status	5	1:Tx FIFO is Overflow,	0:Tx FIFO is not OverFlow
		uint32_t TFUR		:1;		// Tx FIFO Under Run		6	1:Tx FIFO is UnderRun	0:Tx FIFO is not UnderRun

		// RX
		uint32_t RNE		:1;		// Rx FIFO Empty Status		6	1:Rx FIFO empty, 0:Rx FIFO not empty
		uint32_t RFF		:1;		// Rx FIFO Full Status		7	1:Rx FIFO is full, 0:Rx FIFO is not full
		uint32_t RWMLF		:1;		// Rx FIFO Water L. Full	8	1:Rx FIFO >= Rx Water Level,	0:Rx FIFO < Rx Water Level
		uint32_t RFOF		:1;		// Rx FIFO Over Flow Status	9	1:Rx FIFO is OverFlow	0: Rx FIFO is not OverFlow
		uint32_t RFUR		:1;		// Rx FIFO Under Run		10	1:Rx FIFO is UnderRun	0: Rx FIFO is not UnderRun
		uint32_t NOT_USED	:22;	//							32  
	}Reg;
} TSPI_SPISR_TypeDef;

// SPIFIFOCR Reg Typedef
typedef union
{
	uint32_t pReg;
	struct{
		uint32_t TXFCLR		:1;		// Tx FIFO CLR,					1	1:Clear (Autoclear), 2:Normal OP
		uint32_t RXFCLR		:1;		// Rx FIFO CLR,					2   1:Clear (Autoclear), 2:Normal OP
		uint32_t TXFWML		:5;		// Tx FIFO Water Mark Level,	7
		uint32_t RXFWML		:5;		// RX FIFO Water Mark Level,	12
		uint32_t DMATE		:1;		// DMA Tx Enable,				13
		uint32_t DMARE		:1;		// DMA Rx Enable,				14
		uint32_t TXFECLR	:1;		// TX FIFO Error Clear,			15
		uint32_t RXFECLR	:1;		// RX FIFO Error Clear,			16
		uint32_t NOT_USED	:16;	//								32
	}Reg;
} TSPI_SPIFIFOCR_TypeDef;

// SPIINTRSR Reg Typedef
typedef union
{
	uint32_t pReg;
	struct{
		uint32_t TXIS		  :1;		// Tx FIFO Interrupt State,				    1
		uint32_t RXIS		  :1;		// Rx FIFO Interrupt State,				    2
    uint32_t TXURIS		:1;		// TX FIFO UnderRun Interrupt State,	    3
    uint32_t RXURIS		:1;		// RX FIFO UnderRun Interrupt State,	    4
		uint32_t TORIS		:1;		// TX FIFO Receive Overrun Interrupt State, 5
    uint32_t RORIS		:1;		// RX FIFO Receive Overrun Interrupt State, 6
		uint32_t NOT_USED	:26;	//	    									
	}Reg;
} TSPI_SPIINTRSR_TypeDef;

// SPIINTRENCR Reg Typedef -> SPIINTRENCR Reg Typedef
typedef union
{
	uint32_t pReg;
	struct{
		uint32_t TXIE		:1;		// Tx FIFO Interrupt Enable,			        1
		uint32_t RXIE		:1;		// Rx FIFO Interrupt Enable,			        2
		uint32_t TXURIE		:1;		// Tx FIFO UnderRun Interrupt Enable,	        3
		uint32_t RXURIE		:1;		// Rx FIFO UnderRun Interrupt Enable,	        4
		uint32_t TORIE		:1;		// Tx FIFO Receive OverRun Interrupt Enable,	5
		uint32_t RORIE		:1;		// Rx FIFO Receive OverRun Interrupt Enable,	6
		uint32_t NOT_USED	:26;	//											
	}Reg;
} TSPI_SPIINTRENCR_TypeDef; 

// SPIINTRCLR Reg Typedef -> SPIINTRCLR Reg Typedef
typedef union
{
	uint32_t pReg;
	struct{
		uint32_t ICLR		:1;		// SPI Interrupt Clear  			        1
		uint32_t NOT_USED	:31;	//											
	}Reg;
} TSPI_SPIINTRCLR_TypeDef; 

// SPIMISC Reg Typedef -> SPIMISC Reg Typedef
typedef union
{
	uint32_t pReg;
	struct{
		uint32_t SPIMISC		:1;		// SPI MISC Register  			        1
		uint32_t NOT_USED	    :31;	//											
	}Reg;
} TSPI_SPIMISC_TypeDef; 

// SPIINTRMSCR Reg Typedef
typedef union
{
	uint32_t pReg;
	struct
	{
		uint32_t TXI:1;                     // Tx FIFO Interrupt Enable,          1
		uint32_t RXI:1;                     // Rx FIFO Interrupt Enable,          2
		uint32_t RORI:1;                    // Rx OverRun Interrupt Enable        3
		uint32_t NOT_USED:29;               //                                    32
	} Reg;
} TSPI_INTMSCR_TypeDef;


typedef struct
{
	uint32_t	SPI_DataBit;
	uint32_t	SPI_DataOut;
	uint32_t	SPI_CPhase;
	uint32_t	SPI_CPolority;
	uint32_t	SPI_Mode;
	uint32_t	SPI_FirstBitOrder;
	uint32_t	SPI_LPBack;
	uint32_t	SPI_BaudRate;
	uint32_t	SPI_TxWaterLevel;
	uint32_t	SPI_RxWaterLevel;
} TSPI_InitTypeDef;


#endif /* _TSPI_H_ */
