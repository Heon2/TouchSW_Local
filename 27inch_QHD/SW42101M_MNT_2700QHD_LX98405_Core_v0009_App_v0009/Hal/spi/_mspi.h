/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _mspi.h
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

#ifndef __MSPI_H_
#define __MSPI_H_


#include "mspi_.h"


typedef union
{
	struct
	{
		__IO uint32_t BITLEN			:2;			  // Bit Length 							  2    00:8bit, 01:10Bit, 02:12Bit, 03:16Bit
		__IO uint32_t DOUTEN			:1;			  // Data Out Enable						  3    1:MOSI Enable, 0:Disable
		__IO uint32_t CPHA				:1;			  // Clock Phase							  4    1:Leading Edge - Setup, Trailing Edge - Sample,	 0: Leading Edge - Sample, Trailing Edge - Setup
		__IO uint32_t CPOL				:1;			  // Clock Polarity 						  5    1:Leading Edge - Falling, Trailing Edge - Rising,   0:Leading Edge - Rising, Trailing Edge - Falling
		__IO uint32_t MSTR				:1;			  // Mster/Slave Select 					  6    1:Master, 0:Slave
		__IO uint32_t DORD              :1;			  // Data Order 							  7    1:LSB First, 0:MSB First (Default)
		__IO uint32_t SPE				:1;			  // SPI Enable 							  8
		__IO uint32_t LBM				:1;			  // LooP Back Mode 						  9    1:LOOP_BACK_MODE, 0:Normal Operation
		__IO uint32_t SSOSEL			:1;			  // SSO Select 							  10   1:External Control SSO Signal, 0:Auto Generation SSO SPI Slave Select
		__IO uint32_t SSOEXT			:1;			  // Master SSO Signal Register Setting 	  11   1:Master Slave Select Disable, 0:Master Slave Select Enable
		__I uint32_t RESERVED0			:5;		  	  // Not Used
		__IO uint32_t CKMAXRATE			:3;			  // Not Used
		__I uint32_t RESERVED1			:1; 		  // Not Used
		__IO uint32_t CKMAXPRE			:3;			  // Not Used
		__I uint32_t RESERVED2			:1; 		  // Not Used
		__IO uint32_t SWPRST			:1;			  // APB CLK domain block reset						1:Reset, 0,Release
		__IO uint32_t SWHRST			:1;			  // AHB CLK domain block reset						1:Reset, 0,Release
		__I uint32_t RESERVED3			:6; 		  // Not Used
	} __PACKED tBit;

	__IO uint32_t ulBulk;				  /// 0x0000 | SPI Control register 					  | 0x00000002

} __PACKED tMSPI_SCR_t;


typedef union
{
	struct
	{
		__IO uint32_t spiTxEna0			:1;
		__IO uint32_t spiTxEna1			:1;
		__IO uint32_t spiTxEna2			:1;
		__IO uint32_t spiTxEna3			:1;
		__IO uint32_t spiTxEna4			:1;
		__IO uint32_t spiTxEna5         :1;
		__I uint32_t RESERVED0			:2;
		__IO uint32_t spiRxEna0			:1;
		__IO uint32_t spiRxEna1			:1;
		__IO uint32_t spiRxEna2			:1;
		__IO uint32_t spiRxEna3			:1;
		__IO uint32_t spiRxEna4			:1;
		__IO uint32_t spiRxEna5			:1;
		__I uint32_t RESERVED1			:18;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tMSPI_SPIENA_t;


typedef struct
{
	union {

		__IO uint32_t SCR;				  /// 0x0000 | SPI Control register 					  | 0x00000002

		struct {
			__IO uint32_t BITLEN			:2;			  // Bit Length 							  2    00:8bit, 01:10Bit, 02:12Bit, 03:16Bit
			__IO uint32_t DOUTEN			:1;			  // Data Out Enable						  3    1:MOSI Enable, 0:Disable
			__IO uint32_t CPHA				:1;			  // Clock Phase							  4    1:Leading Edge - Setup, Trailing Edge - Sample,	 0: Leading Edge - Sample, Trailing Edge - Setup
			__IO uint32_t CPOL				:1;			  // Clock Polarity 						  5    1:Leading Edge - Falling, Trailing Edge - Rising,   0:Leading Edge - Rising, Trailing Edge - Falling
			__IO uint32_t MSTR				:1;			  // Mster/Slave Select 					  6    1:Master, 0:Slave
			__IO uint32_t DORD              :1;			  // Data Order 							  7    1:LSB First, 0:MSB First (Default)
			__IO uint32_t SPE				:1;			  // SPI Enable 							  8
			__IO uint32_t LBM				:1;			  // LooP Back Mode 						  9    1:LOOP_BACK_MODE, 0:Normal Operation
			__IO uint32_t SSOSEL			:1;			  // SSO Select 							  10   1:External Control SSO Signal, 0:Auto Generation SSO SPI Slave Select
			__IO uint32_t SSOEXT			:1;			  // Master SSO Signal Register Setting 	  11   1:Master Slave Select Disable, 0:Master Slave Select Enable
			__I uint32_t RESERVED0			:5;		  	  // Not Used
			__IO uint32_t CKMAXRATE			:3;			  // Not Used
			__I uint32_t RESERVED1			:1; 		  // Not Used
			__IO uint32_t CKMAXPRE			:3;			  // Not Used
			__I uint32_t RESERVED2			:1; 		  // Not Used
			__IO uint32_t SWPRST			:1;			  // APB CLK domain block reset						1:Reset, 0,Release
			__IO uint32_t SWHRST			:1;			  // AHB CLK domain block reset						1:Reset, 0,Release
			__I uint32_t RESERVED3			:6; 		  // Not Used
		} SCR_b;								   /*!< BitSize 		  */
	};

	__IO uint32_t SDR0;                 /// 0x0004 | SPI0 FIFO Access register                  | 0x00000000
	__IO uint32_t SSR0;                 /// 0x0008 | SPI0 Status register                       | 0x00000000
	__IO uint32_t SFIFOCR;              /// 0x000C | FIFO Control register                      | 0x00000000
	__IO uint32_t SINTRSR;              /// 0x0010 | Interrupt Status register                  | 0x30001080
	__IO uint32_t SINTRMSSR;            /// 0x0014 | Interrupt Masked Status register           | 0x00000000

	union {

		__IO uint32_t SINTRMSCR;			  /// 0x0018 | Interrupt Mask Control register			  | 0x00000000

		struct {
			__IO uint32_t Not_Used				:6;
			__IO uint32_t IntrMemMSCR 			:1;
			__IO uint32_t IntrAitWlvMSCR 		:1;
			__IO uint32_t IntrAitWlvMSCR1		:1;
			__IO uint32_t IntrAitWlvMSCR2		:1;
			__IO uint32_t IntrAitWlvMSCR3		:1;
		} SINTRMSCR_b;								   /*!< BitSize 		  */
	};

	__IO uint32_t SINTRENCR;            /// 0x001C | Interrupt Clear register                   | 0x30000000



	__IO uint32_t SFIFORXPTR;           /// 0x0020 | RX FIFO Pointer status register            | 0x00000000
	__IO uint32_t SFIFORXDIFFPTR;       /// 0x0024 | RX FIFO Pointer difference status register | 0x00000000
	__IO uint32_t SFIFOTXPTR;           /// 0x0028 | TX FIFO Pointer status register            | 0x00000000
	__IO uint32_t SFIFOTXDIFFPTR;       /// 0x002C | TX FIFO Pointer difference status register | 0x00000000
	__IO uint32_t SDATACNTTXRX;         /// 0x0030 | TX RX COUNTER status register              | 0x00000000
	__IO uint32_t Reserved1;            /// 0x0034 | Reserved 1                                 | 0x00000000
	__IO uint32_t Reserved2;            /// 0x0038 | Reserved 2                                 | 0x00000000
	__IO uint32_t Reserved3;            /// 0x003C | Reserved 3                                 | 0x00000000
	__IO uint32_t Reserved4;            /// 0x0040 | Reserved 4                                 | 0x00000000

	__IO uint32_t SMISC;                /// 0x0044 | Miscellaneous register                     | 0x00000000

	__IO uint32_t Reserved5;            /// 0x0048 | Reserved 5                                 | 0x00000000
	__IO uint32_t Reserved6;            /// 0x004C | Reserved 6                                 | 0x00000000

	__IO uint32_t Reserved7;            /// 0x0050 | Reserved 7                                 | 0x00000000
	__IO uint32_t Reserved8;            /// 0x0054 | Reserved 8                                 | 0x00000000
	__IO uint32_t Reserved9;            /// 0x0058 | Reserved 9                                 | 0x00000000
	__IO uint32_t Reserved10;           /// 0x005C | Reserved 10                                | 0x00000000
	__IO uint32_t Reserved11;           /// 0x0060 | Reserved 11                                | 0x00000000
	__IO uint32_t Reserved12;           /// 0x0064 | Reserved 12                                | 0x00000000
	__IO uint32_t Reserved13;           /// 0x0068 | Reserved 13                                | 0x00000000
	__IO uint32_t Reserved14;           /// 0x006C | Reserved 14                                | 0x00000000
	__IO uint32_t Reserved15;           /// 0x0070 | Reserved 15                                | 0x00000000
	__IO uint32_t Reserved16;           /// 0x0074 | Reserved 16                                | 0x00000000
	__IO uint32_t Reserved17;           /// 0x0078 | Reserved 17                                | 0x00000000
	__IO uint32_t Reserved18;           /// 0x007C | Reserved 18                                | 0x00000000
	__IO uint32_t Reserved19;           /// 0x0080 | Reserved 19                                | 0x00000030
	__IO uint32_t SDR1;                 /// 0x0084 | SPI1 FIFO Access register                  | 0x00000030
	__IO uint32_t SDR2;                 /// 0x0088 | SPI2 FIFO Access register                  | 0x00000030
	__IO uint32_t SDR3;                 /// 0x008C | SPI3 FIFO Access register                  | 0x00000030
	__IO uint32_t SDR4;                 /// 0x0090 | SPI4 FIFO Access register                  | 0x00000030
	__IO uint32_t SDR5;                 /// 0x0094 | SPI5 FIFO Access register                  | 0x00000010
	__IO uint32_t SSR1;                 /// 0x0098 | SPI1 Status register                       | 0x00000010
	__IO uint32_t SSR2;                 /// 0x009C | SPI2 Status register                       | 0x00000010
	__IO uint32_t SSR3;                 /// 0x00A0 | SPI3 Status register                       | 0x00000010
	__IO uint32_t SSR4;                 /// 0x00A4 | SPI4 Status register                       | 0x00000010
	__IO uint32_t SSR5;                 /// 0x00A8 | SPI5 Status register                       | 0x00000020

	__IO uint32_t SPIENA;               /// 0x00AC | SPI0~5 TX RX Enable register               | 0x00000020

	__IO uint32_t SPITRSZE0;            /// 0x00B0 | SPI0 Transfer Size register                | 0x00000020
	__IO uint32_t SPITRSZE1;            /// 0x00B4 | SPI1 Transfer Size register                | 0x00000020
	__IO uint32_t SPITRSZE2;            /// 0x00B8 | SPI2 Transfer Size register                | 0x00000020
	__IO uint32_t SPITRSZE3;            /// 0x00BC | SPI3 Transfer Size register                | 0x00000018
	__IO uint32_t SPITRSZE4;            /// 0x00C0 | SPI4 Transfer Size register                | 0x00000018
	__IO uint32_t SPITRSZE5;            /// 0x00C4 | SPI5 Transfer Size register                | 0x00000018
	__IO uint32_t SPIINTSEL;            /// 0x00C8 | SPI Interrupt Selection register           | 0x00040000

	union {

		__IO uint32_t SPISTATELEN;		  /// 0x00CC | SPI TIMING LENGTH register				  | 0x0000F000

		struct {
			__IO uint32_t PreShftLen			:8;
			__IO uint32_t TmpIdleLen 			:8;
			__IO uint32_t PostShftLen 			:8;
			__IO uint32_t SnglIdleLen 			:4;
			__IO uint32_t AitIdleLen			:4;
		} SPISTATELEN_b;								   /*!< BitSize 		  */
	};


	union {

		__IO uint32_t SPIMODE;			  /// 0x00D0 | SPI Operation Mode register				  | 0x00000300

		struct {
			__IO uint32_t AitTlpMode			:1;
			__IO uint32_t SramFifoMode 			:1;
			__IO uint32_t HwSwMode 				:1;
			__IO uint32_t BrstSnglMode 			:1;
			__IO uint32_t SramDebugMode			:1;
			__IO uint32_t SramWrOpt				:1;
			__IO uint32_t reserved 				:2;
			__IO uint32_t TrsPerRd 				:2;
			__IO uint32_t TrsPerWr 				:2;
			__IO uint32_t PwfeSel				:3;
			__IO uint32_t CommPwfeSel			:1;
			__IO uint32_t Protocol 				:4;
			__IO uint32_t RdHlfWrdMsbFrst		:1;
			__IO uint32_t WrHlfWrdMsbFrst		:1;
		} SPIMODE_b;								   /*!< BitSize 		  */
	};




	__IO uint32_t SPISTART;             /// 0x00D4 | SPI Start Command register                 | 0x00000018

	__IO uint32_t SPISTRTWAD01;         /// 0x00D8 | SPI0 SPI1 Memory Write Start Address       | 0x00000018
	__IO uint32_t SPISTRTWAD23;         /// 0x00DC | SPI2 SPI3 Memory Write Start Address       | 0x00000002
	__IO uint32_t SPISTRTWAD45;         /// 0x00E0 | SPI4 SPI5 Memory Write Start Address       | 0x00000005

	__IO uint32_t SPISTRTRAD01;         /// 0x00E4 | SPI0 SPI1 Memory Read  Start Address       | 0x00000018
	__IO uint32_t SPISTRTRAD23;         /// 0x00E8 | SPI2 SPI3 Memory Read  Start Address       | 0x00000002
	__IO uint32_t SPISTRTRAD45;         /// 0x00EC | SPI4 SPI5 Memory Read  Start Address       | 0x00000005


	__IO uint32_t TSPRXLINESALL;        /// 0x00F0 | TSP Total RX LINES Divided by 2            | 0x0000000F
	__IO uint32_t SPIRXLINES01;         /// 0x00F4 | SPI0 SPI1 Allocated RX TOUCH LINES         | 0x00000000
	__IO uint32_t SPIRXLINES23;         /// 0x00F8 | SPI2 SPI3 Allocated RX TOUCH LINES         | 0x207F1FFF
	__IO uint32_t SPIRXLINES45;         /// 0x00FC | SPI4 SPI5 Allocated RX TOUCH LINES         | 0x55AA55AA

	union {

		__IO uint32_t SPIPCLKEND; 		  /// 0x00FF | SPI PCLK END parameter for DIV2/3/4/6/8	  | 0x55AA55AA

		struct {
			__IO uint32_t spiPclkEnd			:4;
			__IO uint32_t spiPclkCnt	 		:4;
			__IO uint32_t spiPclkDiv 			:4;
			__IO uint32_t spiPclkEnd2 			:4;
		} SPIPCLKEND_b;								   /*!< BitSize 		  */
	};


	__IO uint32_t SPITSYNCSZE0;         /// 0x0100 | SPI0 Transfer Size per 1 Tsync frame       | 0x000000FF
	__IO uint32_t SPITSYNCSZE1;         /// 0x0104 | SPI1 Transfer Size per 1 Tsync frame       | 0x000000FF
	__IO uint32_t SPITSYNCSZE2;         /// 0x0108 | SPI2 Transfer Size per 1 Tsync frame       | 0x000000FF
	__IO uint32_t SPITSYNCSZE3;         /// 0x010C | SPI3 Transfer Size per 1 Tsync frame       | 0x000000FF
	__IO uint32_t SPITSYNCSZE4;         /// 0x0120 | SPI4 Transfer Size per 1 Tsync frame       | 0x000000FF
	__IO uint32_t SPITSYNCSZE5;         /// 0x0124 | SPI5 Transfer Size per 1 Tsync frame       | 0x000000FF
	__IO uint32_t SPIHCLKCOMMEND;       /// 0x0128 | SPI Ready Singal sampling position         | 0x000000FF
	__IO uint32_t SPIAITTSYNCDONECLR;   /// 0x0128 | SPI TSYNC Done Status Clear Command        | 0x000000FF

	__IO uint32_t SPISTATESR0;          /// 0x0128 | SPI0 Status Register                       | 0x000000FF
	__IO uint32_t SPITSYNCCNTSR0;       /// 0x0128 | SPI0 Tsync Couter Monitoring               | 0x000000FF
	__IO uint32_t SPISUBFRCNTSR0;       /// 0x0128 | SPI0 Sub frame Counter Monitoring          | 0x000000FF
	__IO uint32_t SPISTATESR1;          /// 0x0128 | SPI1 Status Register                       | 0x000000FF
	__IO uint32_t SPITSYNCCNTSR1;       /// 0x0128 | SPI1 Tsync Couter Monitoring               | 0x000000FF
	__IO uint32_t SPISUBFRCNTSR1;       /// 0x0128 | SPI1 Sub frame Counter Monitoring          | 0x000000FF
	__IO uint32_t SPISTATESR2;          /// 0x0128 | SPI2 Status Register                       | 0x000000FF
	__IO uint32_t SPITSYNCCNTSR2;       /// 0x0128 | SPI2 Tsync Couter Monitoring               | 0x000000FF
	__IO uint32_t SPISUBFRCNTSR2;       /// 0x0128 | SPI2 Sub frame Counter Monitoring          | 0x000000FF
	__IO uint32_t SPISTATESR3;          /// 0x0128 | SPI3 Status Register                       | 0x000000FF
	__IO uint32_t SPITSYNCCNTSR3;       /// 0x0128 | SPI3 Tsync Couter Monitoring               | 0x000000FF
	__IO uint32_t SPISUBFRCNTSR3;       /// 0x0128 | SPI3 Sub frame Counter Monitoring          | 0x000000FF
	__IO uint32_t SPISTATESR4;          /// 0x0128 | SPI4 Status Register                       | 0x000000FF
	__IO uint32_t SPITSYNCCNTSR4;       /// 0x0128 | SPI4 Tsync Couter Monitoring               | 0x000000FF
	__IO uint32_t SPISUBFRCNTSR4;       /// 0x0128 | SPI4 Sub frame Counter Monitoring          | 0x000000FF
	__IO uint32_t SPISTATESR5;          /// 0x0128 | SPI5 Status Register                       | 0x000000FF
	__IO uint32_t SPITSYNCCNTSR5;       /// 0x0128 | SPI5 Tsync Couter Monitoring               | 0x000000FF
	__IO uint32_t SPISUBFRCNTSR5;       /// 0x0128 | SPI5 Sub frame Counter Monitoring          | 0x000000FF

	__IO uint32_t SPIAITWLVCR;          /// 0x0128 | SPI AIT Waterlevel Interrupt Control       | 0x000000FF
	__IO uint32_t SPIAITWLV;            /// 0x0128 | SPI AIT Waterlevel Value                   | 0x000000FF
	
	__IO uint32_t SPIAITDMYDEL;         /// 0x0128 | SPI AIT Dummy Delete  Mode                 | 0x000000FF

	__IO uint32_t SPIGFCR0;             /// 0x0128 | SPI0 GlitchFilter Control                  | 0x000000FF
	__IO uint32_t SPIGFENA0;            /// 0x0128 | SPI0 GlitchFilter Bit Enable               | 0x000000FF
	__IO uint32_t SPIGFCR1;             /// 0x0128 | SPI1 GlitchFilter Control                  | 0x000000FF
	__IO uint32_t SPIGFENA1;            /// 0x0128 | SPI1 GlitchFilter Bit Enable               | 0x000000FF
	__IO uint32_t SPIGFCR2;             /// 0x0128 | SPI2 GlitchFilter Control                  | 0x000000FF
	__IO uint32_t SPIGFENA2;            /// 0x0128 | SPI2 GlitchFilter Bit Enable               | 0x000000FF
	__IO uint32_t SPIGFCR3;             /// 0x0128 | SPI3 GlitchFilter Control                  | 0x000000FF
	__IO uint32_t SPIGFENA3;            /// 0x0128 | SPI3 GlitchFilter Bit Enable               | 0x000000FF
	__IO uint32_t SPIGFCR4;             /// 0x0128 | SPI4 GlitchFilter Control                  | 0x000000FF
	__IO uint32_t SPIGFENA4;            /// 0x0128 | SPI4 GlitchFilter Bit Enable               | 0x000000FF
	__IO uint32_t SPIGFCR5;             /// 0x0128 | SPI5 GlitchFilter Control                  | 0x000000FF
	__IO uint32_t SPIGFENA5;            /// 0x0128 | SPI5 GlitchFilter Bit Enable               | 0x000000FF

	__IO uint32_t SPIPENCR0;            /// 0x0128 | SPI Pen Control0                           | 0x000000FF
	__IO uint32_t SPIPENCR1;            /// 0x0128 | SPI Pen Control1                           | 0x000000FF

	__IO uint32_t SPIAITWLV1;           /// 0x0128 | SPI AIT Waterlevel1 Value                  | 0x000000FF
	__IO uint32_t SPIAITWLV2;           /// 0x0128 | SPI AIT Waterlevel2 Value                  | 0x000000FF
	__IO uint32_t SPIAITWLV3;           /// 0x0128 | SPI AIT Waterlevel3 Value                  | 0x000000FF


} MSPI_TypeDef ;


#endif /* __MSPI_H_ */
