/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _DSPB.h
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


#ifndef __DSPB_H_
#define __DSPB_H_


/* ================================================================================ */
/* ================                      TDSP(DSPB)                ================ */
/* ================================================================================ */

typedef union
{
    struct {
        unsigned    DIV:                       16;
        unsigned    DIVS:                      16;
    } tBit;
    __IO uint32_t w;
} t_CYCLE_DIV;

typedef union
{
    struct {
        unsigned    MUL:                       16;
        unsigned    MULS:                      16;
    } tBit;
    __IO uint32_t w;
} t_CYCLE_MUL;

typedef union
{
    struct {
        unsigned    INT_STAT_CLR:              1;
        unsigned    RESERVED:                  3;
        unsigned    INT_MASK:                  1;
        unsigned    reserved:                  27;
    } tBit;
    __IO uint32_t w;
} t_INTERRUPT;

typedef union
{
    struct {
        unsigned    DEBUG_MODE:                2;
        unsigned    RESERVED:                  2;
        unsigned    DEBUG_RUN:                 1;
        unsigned    DEBUG_STEP:                1;
        unsigned    reserved:                  26;
    } tBit;
    __IO uint32_t w;
} t_DEBUG_CON;

typedef union
{
    struct {
        unsigned    DEBUG_INST_LSB_PC:         16;
        unsigned    DEBUG_INST_MSB:            16;
    } tBit;
    __IO uint32_t w;
} t_DEBUG_INST;

typedef union
{
    struct {
        unsigned    BREAK0_DONE:               1;
        unsigned    BREAK1_DONE:               1;
        unsigned    BREAK2_DONE:               1;
        unsigned    BREAK3_DONE:               1;
        unsigned    SDMA0_STAT:                1;
        unsigned    SDMA1_STAT:                1;
        unsigned    SDMA2_STAT:                1;
        unsigned    SDMA3_STAT:                1;
        unsigned    WDMA_STAT:                 1;
        unsigned    RDMAS_STAT:                1;
        unsigned    RESERVED:                  2;
        unsigned    CACHE_STAT:                3;
        unsigned    reserved:                  17;
    } tBit;
    __IO uint32_t w;
} t_DEBUG_STAT;


typedef union
{
    struct {
        unsigned    INST0_LSB_BREAK0:          16;
        unsigned    INST0_MSB:                 16;
    } tBit;
    __IO uint32_t w;
} t_DEBUG_BREAK0;


typedef union
{
    struct {
        unsigned    INST1_LSB_BREAK1:          16;
        unsigned    INST1_MSB:                 16;
    } tBit;
    __IO uint32_t w;
} t_DEBUG_BREAK1;


typedef union
{
    struct {
        unsigned    INST2_LSB_BREAK2:          16;
        unsigned    INST2_MSB:                 16;
    } tBit;
    __IO uint32_t w;
} t_DEBUG_BREAK2;


typedef union
{
    struct {
        unsigned    INST3_LSB_BREAK3:          16;
        unsigned    INST3_MSB:                 16;
    } tBit;
    __IO uint32_t w;
} t_DEBUG_BREAK3;

typedef union
{
    struct {
        unsigned    XSIZE0:                    8;
        unsigned    XSIZE1:                    8;
        unsigned    XSIZE2:                    8;
        unsigned    XSIZE3:                    8;
    } tBit;
    __IO uint32_t w;
} t_DMA_XSIZE;

typedef union
{
    struct {
        unsigned    YSIZE0:                    8;
        unsigned    YSIZE1:                    8;
        unsigned    YSIZE2:                    8;
        unsigned    YSIZE3:                    8;
    } tBit;
    __IO uint32_t w;
} t_DMA_YSIZE;


typedef struct
{																	 //Index
    __IO uint32_t                    TDSP_REGA0;                     //0x0000
    __IO uint32_t                    TDSP_REGA1;                     //0x0001
    __IO uint32_t                    TDSP_REGA2;                     //0x0002
    __IO uint32_t                    TDSP_REGA3;                     //0x0003
    __IO uint32_t                    TDSP_REGA4;                     //0x0004
    __IO uint32_t                    TDSP_REGA5;                     //0x0005
    __IO uint32_t                    TDSP_REGA6;                     //0x0006
    __IO uint32_t                    TDSP_REGA7;                     //0x0007
    __IO uint32_t                    TDSP_REGB0;                     //0x0008
    __IO uint32_t                    TDSP_REGB1;                     //0x0009
    __IO uint32_t                    TDSP_REGB2;                     //0x000A
    __IO uint32_t                    TDSP_REGB3;                     //0x000B
    __IO uint32_t                    TDSP_REGB4;                     //0x000C
    __IO uint32_t                    TDSP_REGB5;                     //0x000D
    __IO uint32_t                    TDSP_REGB6;                     //0x000E
    __IO uint32_t                    TDSP_REGB7;                     //0x000F
    __IO uint32_t                    TDSP_REGC0;                     //0x0010
    __IO uint32_t                    TDSP_REGC1;                     //0x0011
    __IO uint32_t                    TDSP_REGC2;                     //0x0012
    __IO uint32_t                    TDSP_REGC3;                     //0x0013
    __IO uint32_t                    TDSP_REGC4;                     //0x0014
    __IO uint32_t                    TDSP_REGC5;                     //0x0015
    __IO uint32_t                    TDSP_REGC6;                     //0x0016
    __IO uint32_t                    TDSP_REGC7;                     //0x0017
    __IO uint32_t                    TDSP_RESERVED00;                //0x0018
    __IO uint32_t                    TDSP_RESERVED01;                //0x0019
    __IO uint32_t                    TDSP_RESERVED02;                //0x001A
    __IO uint32_t                    TDSP_RESERVED03;                //0x001B
    __IO uint32_t                    TDSP_RESERVED04;                //0x001C
    __IO uint32_t                    TDSP_RESERVED05;                //0x001D
    __IO uint32_t                    TDSP_RESERVED06;                //0x001E
    __IO uint32_t                    TDSP_RESERVED07;                //0x001F
    __I  uint32_t                    TDSP_MEM0;                      //0x0020
    __IO uint32_t                    TDSP_RESERVED08;                //0x0021
    __IO uint32_t                    TDSP_RESERVED09;                //0x0022
    __IO uint32_t                    TDSP_RESERVED10;                //0x0023
    __I  uint32_t                    TDSP_STATUS;                    //0x0024
    __IO uint32_t                    TDSP_RESERVED11;                //0x0025
    __IO uint32_t                    TDSP_RESERVED12;                //0x0026
    __IO uint32_t                    TDSP_RESERVED13;                //0x0027
    __IO uint32_t                    TDSP_RESERVED14;                //0x0028
    __IO uint32_t                    TDSP_RESERVED15;                //0x0029
    __IO uint32_t                    TDSP_RESERVED16;                //0x002A
    __IO uint32_t                    TDSP_RESERVED17;                //0x002B
    __IO uint32_t                    TDSP_RESERVED18;                //0x002C
    __IO uint32_t                    TDSP_RESERVED19;                //0x002D
    __IO uint32_t                    TDSP_RESERVED20;                //0x002E
    __IO uint32_t                    TDSP_RESERVED21;                //0x002F
    __IO uint32_t                    TDSP_RESERVED22;                //0x0030
    __IO uint32_t                    TDSP_RESERVED23;                //0x0031
    __IO uint32_t                    TDSP_RESERVED24;                //0x0032
    __IO uint32_t                    TDSP_RESERVED25;                //0x0033
    __IO uint32_t                    TDSP_RESERVED26;                //0x0034
    __IO uint32_t                    TDSP_RESERVED27;                //0x0035
    __IO uint32_t                    TDSP_RESERVED28;                //0x0036
    __IO uint32_t                    TDSP_RESERVED29;                //0x0037
    __IO uint32_t                    TDSP_RESERVED30;                //0x0038
    __IO uint32_t                    TDSP_RESERVED31;                //0x0039
    __IO uint32_t                    TDSP_RESERVED32;                //0x003A
    __IO uint32_t                    TDSP_RESERVED33;                //0x003B
    __IO uint32_t                    TDSP_RESERVED34;                //0x003C
    __IO uint32_t                    TDSP_RESERVED35;                //0x003D
    __IO uint32_t                    TDSP_RESERVED36;                //0x003E
    __IO uint32_t                    TDSP_RESERVED37;                //0x003F
    __IO uint32_t                    TDSP_PC;                        //0x0040
    __I  uint32_t                    TDSP_LINK0;                     //0x0041
    __I  uint32_t                    TDSP_LINK1;                     //0x0042
    __I  uint32_t                    TDSP_LINK2;                     //0x0043
    __I  uint32_t                    TDSP_LINK3;                     //0x0044
    __I  uint32_t                    TDSP_LINK4;                     //0x0045
    __I  uint32_t                    TDSP_LCNT0;                     //0x0046
    __I  uint32_t                    TDSP_LCNT1;                     //0x0047
    __I  uint32_t                    TDSP_LCNT2;                     //0x0048
    __I  uint32_t                    TDSP_BUSY;                      //0x0049
    __IO uint32_t                    TDSP_BASEADD;                   //0x004A
    __IO uint32_t                    TDSP_BURST;                     //0x004B
    __IO t_CYCLE_DIV           	     TDSP_CYCLE_DIV;                 //0x004C
    __IO t_CYCLE_MUL           		 TDSP_CYCLE_MUL;                 //0x004D
    __O  t_INTERRUPT           		 TDSP_INTERRUPT;                 //0x004E
    __IO t_DEBUG_CON           		 TDSP_DEBUG_CON;                 //0x004F
    __I  t_DEBUG_INST           	 TDSP_DEBUG_INST;                //0x0050
    __I  t_DEBUG_STAT           	 TDSP_DEBUG_STAT;                //0x0051
    __IO t_DEBUG_BREAK0    			 TDSP_DEBUG_BREAK0;              //0x0052
    __IO t_DEBUG_BREAK1    			 TDSP_DEBUG_BREAK1;              //0x0053
    __IO t_DEBUG_BREAK2    			 TDSP_DEBUG_BREAK2;              //0x0054
    __IO t_DEBUG_BREAK3    			 TDSP_DEBUG_BREAK3;              //0x0055
    __IO uint32_t                    TDSP_RESERVED38;                //0x0056
    __IO uint32_t                    TDSP_RESERVED39;                //0x0057
    __IO uint32_t                    TDSP_RESERVED40;                //0x0058
    __IO uint32_t                    TDSP_RESERVED41;                //0x0059
    __IO uint32_t                    TDSP_RESERVED42;                //0x005A
    __IO uint32_t                    TDSP_RESERVED43;                //0x005B
    __IO uint32_t                    TDSP_RESERVED44;                //0x005C
    __IO uint32_t                    TDSP_RESERVED45;                //0x005D
    __IO uint32_t                    TDSP_RESERVED46;                //0x005E
    __IO uint32_t                    TDSP_RESERVED47;                //0x005F
    __IO uint32_t                    TDSP_CACHE_DATA0;               //0x0060
    __IO uint32_t                    TDSP_CACHE_DATA1;               //0x0061
    __IO uint32_t                    TDSP_CACHE_DATA2;               //0x0062
    __IO uint32_t                    TDSP_CACHE_DATA3;               //0x0063
    __IO uint32_t                    TDSP_CACHE_DATA4;               //0x0064
    __IO uint32_t                    TDSP_CACHE_DATA5;               //0x0065
    __IO uint32_t                    TDSP_CACHE_DATA6;               //0x0066
    __IO uint32_t                    TDSP_CACHE_DATA7;               //0x0067
    __IO uint32_t                    TDSP_CACHE_DATA8;               //0x0068
    __IO uint32_t                    TDSP_CACHE_DATA9;               //0x0069
    __IO uint32_t                    TDSP_CACHE_DATA10;              //0x006A
    __IO uint32_t                    TDSP_CACHE_DATA11;              //0x006B
    __IO uint32_t                    TDSP_CACHE_DATA12;              //0x006C
    __IO uint32_t                    TDSP_CACHE_DATA13;              //0x006D
    __IO uint32_t                    TDSP_CACHE_DATA14;              //0x006E
    __IO uint32_t                    TDSP_CACHE_DATA15;              //0x006F
    __IO uint32_t                    TDSP_CACHE_DATA16;              //0x0070
    __IO uint32_t                    TDSP_CACHE_DATA17;              //0x0071
    __IO uint32_t                    TDSP_CACHE_DATA18;              //0x0072
    __IO uint32_t                    TDSP_CACHE_DATA19;              //0x0073
    __IO uint32_t                    TDSP_CACHE_DATA20;              //0x0074
    __IO uint32_t                    TDSP_CACHE_DATA21;              //0x0075
    __IO uint32_t                    TDSP_CACHE_DATA22;              //0x0076
    __IO uint32_t                    TDSP_CACHE_DATA23;              //0x0077
    __IO uint32_t                    TDSP_CACHE_DATA24;              //0x0078
    __IO uint32_t                    TDSP_CACHE_DATA25;              //0x0079
    __IO uint32_t                    TDSP_CACHE_DATA26;              //0x007A
    __IO uint32_t                    TDSP_CACHE_DATA27;              //0x007B
    __IO uint32_t                    TDSP_CACHE_DATA28;              //0x007C
    __IO uint32_t                    TDSP_CACHE_DATA29;              //0x007D
    __IO uint32_t                    TDSP_CACHE_DATA30;              //0x007E
    __IO uint32_t                    TDSP_CACHE_DATA31;              //0x007F
    __IO t_DMA_XSIZE            	 TDSP_DMA_XSIZE;				 //0x0080
    __IO t_DMA_YSIZE            	 TDSP_DMA_YSIZE;                 //0x0081
    __IO uint32_t                    TDSP_DMA_ADD;                  //0x0082
} tDSPB_CtrlReg_t;


#endif /* __DSPB_H_ */
