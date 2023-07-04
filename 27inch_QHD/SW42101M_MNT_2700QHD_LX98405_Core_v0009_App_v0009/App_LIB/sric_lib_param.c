/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : sric_lib_param.c
 * created on : 18. 10. 2018
 * Author : mhjang
 *
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright
 *	 notice, this list of conditions and the following disclaimer.
 *	 - Redistributions in binary form must reproduce the above copyright
 *	 notice, this list of conditions and the following disclaimer in the
 *	 documentation and/or other materials provided with the distribution.
 * - Neither the name of SiW nor the names of its contributors may be used
 *	 to endorse or promote products derived from this software without
 *	 specific prior written permission.
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


#include "sric_lib_param.h"

SRIC_REG g_ROIC_Reg_Val[] =
{
		//ADDR  RO_Val  R1_Val
		{ 0x00, 0x2390, 0x2390 },         // [ 00 ] CFGR_PRODUCT_ID
		{ 0x02, 0x0000, 0x0000 },         // [ 01 ] CFGR_SNSR_STR
		{ 0x04, 0x4F61, 0x4F61 },         // [ 02 ] CFGR_MD_GENERAL
		{ 0x06, 0x0D3F, 0x0D3F },         // [ 03 ] CFGR_AIP_ADC
		{ 0x08, 0x111A, 0x111A },         // [ 04 ] CFGR_SSU_CTRL
		{ 0x0A, 0x0601, 0x0601 },         // [ 05 ] CFGR_TSYNC_NUM0
		{ 0x0C, 0x0601, 0x0601 },         // [ 06 ] CFGR_TSYNC_NUM1
		{ 0x0E, 0x0000, 0x0000 },         // [ 07 ] CFGR_TSYNC_DMMY
		{ 0x10, 0x0104, 0x0104 },         // [ 08 ] CFGR_PWM_NUM0
		{ 0x12, 0x0A14, 0x0A14 },         // [ 09 ] CFGR_PWM_NUM1
		{ 0x14, 0x9D20, 0x9D20 },         // [ 10 ] CFGR_CMUX_NORM		<-------------  Total 10 mux(72*40)
		{ 0x16, 0x0030, 0x0030 },         // [ 11 ] CFGR_CHIP0_LEN		<------------- AFE 48°³(72*40)
		{ 0x18, 0x6650, 0x6650 },         // [ 12 ] CFGR_COL_NUM		<------------- get LGD
		{ 0x1A, 0x4003, 0x4003 },         // [ 13 ] CFGR_OUTER
		{ 0x1C, 0x4040, 0x4040 },         // [ 14 ] CFGR_DIG_GAIN0
		{ 0x1E, 0x0040, 0x0040 },         // [ 15 ] CFGR_DIG_GAIN1
		{ 0x20, 0x03E8, 0x03E8 },         // [ 16 ] CFGR_NIH_MIN0
		{ 0x22, 0x044C, 0x044C },         // [ 17 ] CFGR_NIH_MAX0
		{ 0x24, 0x07D0, 0x07D0 },         // [ 18 ] CFGR_NIH_MIN1
		{ 0x26, 0x0834, 0x0834 },         // [ 19 ] CFGR_NIH_MAX1
		{ 0x28, 0x0BB8, 0x0BB8 },         // [ 20 ] CFGR_NIH_MIN2
		{ 0x2A, 0x0C1C, 0x0C1C },         // [ 21 ] CFGR_NIH_MAX2
		{ 0x2C, 0x0FA0, 0x0FA0 },         // [ 22 ] CFGR_NIH_MIN3
		{ 0x2E, 0x0FFF, 0x0FFF },         // [ 23 ] CFGR_NIH_MAX3
		{ 0x30, 0x0000, 0x0000 },         // [ 24 ] CFGR_NIH_RDAT0
		{ 0x32, 0x0000, 0x0000 },         // [ 25 ] CFGR_NIH_RDAT1
		{ 0x34, 0x0000, 0x0000 },         // [ 26 ] CFGR_NIH_RDAT2
		{ 0x36, 0x0000, 0x0000 },         // [ 27 ] CFGR_NIH_RDAT3
		{ 0x38, 0x2040, 0x2040 },         // [ 28 ] CFGR_NIH_STD
		{ 0x3A, 0x000F, 0x000F },         // [ 29 ] CFGR_SHA_STR
		{ 0x3C, 0x4040, 0x4040 },         // [ 30 ] CFGR_DIG_GAIN2
		{ 0x3E, 0x0002, 0x0002 },         // [ 31 ] CFGR_RSTP_WIDTH
		{ 0x40, 0x0680, 0x0680 },         // [ 32 ] CFGR_VCR_STR
		{ 0x42, 0x0014, 0x0014 },         // [ 33 ] CFGR_VCR2_MD
		{ 0x44, 0x000A, 0x000A },         // [ 34 ] CFGR_VCR2_PHTCR
		{ 0x46, 0x0001, 0x0001 },         // [ 35 ] CFGR_PHTH0_WIDTH
		{ 0x48, 0x0004, 0x0004 },         // [ 36 ] CFGR_PHTH1_WIDTH
		{ 0x4A, 0x00F0, 0x00F0 },         // [ 37 ] CFGR_TEST_OPT
		{ 0x4C, 0xFFFF, 0xFFFF },         // [ 38 ] CFGR_SSU_ON
		{ 0x4E, 0x2322, 0x2322 },         // [ 39 ] CFGR_CMUX_NUM
		{ 0x50, 0x2424, 0x2424 },         // [ 40 ] CFGR_SSU_CR_I00
		{ 0x52, 0x2524, 0x2524 },         // [ 41 ] CFGR_SSU_CR_I04
		{ 0x54, 0x2626, 0x2626 },         // [ 42 ] CFGR_SSU_CR_I08
		{ 0x56, 0x3434, 0x3434 },         // [ 43 ] CFGR_SSU_CR_I12
		{ 0x58, 0x3434, 0x3434 },         // [ 44 ] CFGR_SSU_CR_I14
		{ 0x5A, 0x2424, 0x2424 },         // [ 45 ] CFGR_SSU_CR_E00
		{ 0x5C, 0x2524, 0x2524 },         // [ 46 ] CFGR_SSU_CR_E04
		{ 0x5E, 0x2626, 0x2626 },         // [ 47 ] CFGR_SSU_CR_E08
		{ 0x60, 0x3434, 0x3434 },         // [ 48 ] CFGR_SSU_CR_E12
		{ 0x62, 0x3434, 0x3434 },         // [ 49 ] CFGR_SSU_CR_E14
		{ 0x64, 0x2424, 0x2424 },         // [ 50 ] CFGR_DATA_CR_I00
		{ 0x66, 0x2424, 0x2424 },         // [ 51 ] CFGR_DATA_CR_I08
		{ 0x68, 0x2424, 0x2424 },         // [ 52 ] CFGR_DATA_CR_I16
		{ 0x6A, 0x2424, 0x2424 },         // [ 53 ] CFGR_DATA_CR_I24
		{ 0x6C, 0x2424, 0x2424 },         // [ 54 ] CFGR_DATA_CR_I32
		{ 0x6E, 0x2424, 0x2424 },         // [ 55 ] CFGR_DATA_CR_I40
		{ 0x70, 0x2424, 0x2424 },         // [ 56 ] CFGR_DATA_CR_E00
		{ 0x72, 0x2424, 0x2424 },         // [ 57 ] CFGR_DATA_CR_E08
		{ 0x74, 0x2424, 0x2424 },         // [ 58 ] CFGR_DATA_CR_E16
		{ 0x76, 0x2424, 0x2424 },         // [ 59 ] CFGR_DATA_CR_E24
		{ 0x78, 0x2424, 0x2424 },         // [ 60 ] CFGR_DATA_CR_E32
		{ 0x7A, 0x2424, 0x2424 },         // [ 61 ] CFGR_DATA_CR_E40
		{ 0x7C, 0xF000, 0xF000 },         // [ 62 ] CFGR_EDGE_CR_SEL
		{ 0x7E, 0xABAB, 0xABAB },         // [ 63 ] CFGR_SSU_GC
		{ 0x80, 0x4321, 0x4321 },         // [ 64 ] CFGR_CMUX_REMAP0
		{ 0x82, 0x8765, 0x8765 },         // [ 65 ] CFGR_CMUX_REMAP1
		{ 0x84, 0xCBA9, 0xCBA9 },         // [ 66 ] CFGR_CMUX_REMAP2
		{ 0x86, 0x0F01, 0x0F01 },         // [ 67 ] CFGR_TSYNC_NUM_PEN
		{ 0x88, 0x0000, 0x0000 },         // [ 68 ] CFGR_TSYNC_DMMY_PEN
		{ 0x8A, 0x1E22, 0x1E22 },         // [ 69 ] CFGR_CMUX_NUM_PEN
		{ 0x8C, 0x0000, 0x0000 },         // [ 70 ] CFGR_PEN_CTRL
		{ 0x8E, 0x8944, 0x8944 },         // [ 71 ] CFGR_HALF_COPY
		{ 0x90, 0x9F9E, 0x9F9E },         // [ 72 ] CFGR_PEN0_TSYNC0
		{ 0x92, 0x1F9F, 0x1F9F },         // [ 73 ] CFGR_PEN0_TSYNC1
		{ 0x94, 0x0000, 0x0000 },         // [ 74 ] CFGR_PEN0_TSYNC2
		{ 0x96, 0x0000, 0x0000 },         // [ 75 ] CFGR_PEN0_TSYNC3
		{ 0x98, 0xBFBE, 0xBFBE },         // [ 76 ] CFGR_PEN1_TSYNC0
		{ 0x9A, 0x2FBF, 0x2FBF },         // [ 77 ] CFGR_PEN1_TSYNC1
		{ 0x9C, 0x0000, 0x0000 },         // [ 78 ] CFGR_PEN1_TSYNC2
		{ 0x9E, 0x0000, 0x0000 },         // [ 79 ] CFGR_PEN1_TSYNC3
		{ 0xA0, 0x0A14, 0x0A14 },         // [ 80 ] CFGR_PWM_NUM2
		{ 0xA2, 0x1428, 0x1428 },         // [ 81 ] CFGR_PWM_NUM3
		{ 0xA4, 0x0A28, 0x0A28 },         // [ 82 ] CFGR_PWM_NUM4
		{ 0xA6, 0x0841, 0x0841 },         // [ 83 ] CFGR_PWM_NUM5
		{ 0xA8, 0x1114, 0x1114 },         // [ 84 ] CFGR_PWM_NUM_NI
		{ 0xAA, 0x000F, 0x000F },         // [ 85 ] CFGR_CMUX_NI1
		{ 0xAC, 0x00F0, 0x00F0 },         // [ 86 ] CFGR_CMUX_NI2
		{ 0xAE, 0x0300, 0x0300 },         // [ 87 ] CFGR_CMUX_NI3
		{ 0xB0, 0x0000, 0x0000 },         // [ 88 ] CFGR_CMUX_NI4
		{ 0xB2, 0x0800, 0x0800 },         // [ 89 ] CFGR_AFE_DUM // 0x0800 -> 0x0900 Idle even/mux
		{ 0xB4, 0x0000, 0x0000 },         // [ 90 ] CFGR_RSVD0
		{ 0xB6, 0xFFFF, 0xFFFF },         // [ 91 ] CFGR_RSVD1
		{ 0xFE, 0x0000, 0x0000 },         // [ 92 ] CFGR_MD_IDLE

};
