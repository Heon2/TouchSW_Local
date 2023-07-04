/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _tspi.h
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

#ifndef __TSPI_H_
#define __TSPI_H_


typedef struct {
                                        /// Offset | Description                                | ResetValue
    __IO uint32_t SCR;                  /// 0x0000 | SPI Control register                       | 0x00000002
    __IO uint32_t SDR;                  /// 0x0004 | SPI  FIFO Access register                  | 0x00000000
    __IO uint32_t SSR;                  /// 0x0008 | SPI  Status register                       | 0x00000000
    __IO uint32_t SFIFOCR;              /// 0x000C | FIFO Control register                      | 0x00000000
    __IO uint32_t SINTRSR;              /// 0x0010 | Interrupt Status register                  | 0x30001080
    __IO uint32_t SINTRMSSR;            /// 0x0014 | Interrupt Masked Status register           | 0x00000000
    __IO uint32_t SINTRMSCR;            /// 0x0018 | Interrupt Mask Control register            | 0x00000000
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
    __IO uint32_t SINTLCTRL;            /// 0x0048 | Intel Control register                     | 0x00000000
    __IO uint32_t SBDWSTRT;             /// 0x004C | Intel Bulk Data Window Start register      | 0x00000000
    __IO uint32_t SINTLSTS;             /// 0x0050 | Intel Sensing Status register              | 0x00000000
    __IO uint32_t SINTLFRCH;            /// 0x0054 | Intel Frame Characteristic register        | 0x00000000
    __IO uint32_t SINTLERR;             /// 0x0058 | Intel Error register                       | 0x00000000
    __IO uint32_t SINTLID;              /// 0x005C | Intel Id register                          | 0x00000000
    __IO uint32_t SINTLDATSZ;           /// 0x0060 | Intel Data Size register                   | 0x00000000
    __IO uint32_t SINTLCAP;             /// 0x0064 | Intel Capabilities register                | 0x00000000
    __IO uint32_t SINTLCFG;             /// 0x0068 | Intel Configuration register               | 0x00000000
    __IO uint32_t SINTLCMD;             /// 0x006C | Intel Command register                     | 0x00000000
    __IO uint32_t SINTLPWRMG;           /// 0x0070 | Intel Power Management                     | 0x00000000
    __IO uint32_t SINTLVNDID;           /// 0x0074 | Intel Vendor HW ID register                | 0x00000000
    __IO uint32_t SINTLHWREV;           /// 0x0078 | Intel HW Revision ID register              | 0x00000000
    __IO uint32_t SINTLFWREV;           /// 0x007C | Intel FW Revision ID register              | 0x00000000
    __IO uint32_t SINTLCMPREV;          /// 0x0080 | Intel Compatibility Revision register      | 0x00000000
    __IO uint32_t Reserved19;           /// 0x0080 | Reserved 19                                | 0x00000030
    __IO uint32_t Reserved20;           /// 0x0084 | Reserved 20                                | 0x00000030
    __IO uint32_t Reserved21;           /// 0x0088 | Reserved 21                                | 0x00000030
    __IO uint32_t Reserved22;           /// 0x008C | Reserved 22                                | 0x00000030
    __IO uint32_t Reserved23;           /// 0x0090 | Reserved 23                                | 0x00000030
    __IO uint32_t Reserved24;           /// 0x0094 | Reserved 24                                | 0x00000010
    __IO uint32_t Reserved25;           /// 0x0098 | Reserved 25                                | 0x00000010
    __IO uint32_t Reserved26;           /// 0x009C | Reserved 26                                | 0x00000010
    __IO uint32_t Reserved27;           /// 0x00A0 | Reserved 27                                | 0x00000010
    __IO uint32_t Reserved28;           /// 0x00A4 | Reserved 28                                | 0x00000010
    __IO uint32_t Reserved29;           /// 0x00A8 | Reserved 29                                | 0x00000020
    __IO uint32_t Reserved30;           /// 0x00AC | Reserved 30                                | 0x00000020
    __IO uint32_t Reserved31;           /// 0x00B0 | Reserved 31                                | 0x00000020
    __IO uint32_t Reserved32;           /// 0x00B4 | Reserved 32                                | 0x00000020
    __IO uint32_t Reserved33;           /// 0x00B8 | Reserved 33                                | 0x00000020
    __IO uint32_t Reserved34;           /// 0x00BC | Reserved 34                                | 0x00000018
    __IO uint32_t Reserved35;           /// 0x00C0 | Reserved 35                                | 0x00000018
    __IO uint32_t Reserved36;           /// 0x00C4 | Reserved 36                                | 0x00000018
    __IO uint32_t Reserved37;           /// 0x00C8 | Reserved 37                                | 0x00040000
    __IO uint32_t Reserved38;           /// 0x00CC | Reserved 38                                | 0x0000F000
    __IO uint32_t Reserved39;           /// 0x00D0 | Reserved 39                                | 0x00000300
    __IO uint32_t Reserved40;           /// 0x00D4 | Reserved 40                                | 0x00000018
    __IO uint32_t Reserved41;           /// 0x00D8 | Reserved 41                                | 0x00000018
    __IO uint32_t Reserved42;           /// 0x00DC | Reserved 42                                | 0x00000002
    __IO uint32_t Reserved43;           /// 0x00E0 | Reserved 43                                | 0x00000005
    __IO uint32_t Reserved44;           /// 0x00E4 | Reserved 44                                | 0x0000000F
    __IO uint32_t Reserved45;           /// 0x00E8 | Reserved 45                                | 0x00000000
    __IO uint32_t Reserved46;           /// 0x00EC | Reserved 46                                | 0x207F1FFF
    __IO uint32_t Reserved47;           /// 0x00F0 | Reserved 47                                | 0x55AA55AA
    __IO uint32_t Reserved48;           /// 0x00F4 | Reserved 48                                | 0x55AA55AA
    __IO uint32_t Reserved49;           /// 0x00F8 | Reserved 49                                | 0x000000FF

} TSPI_TypeDef ;


#endif /* __TSPI_H_ */

