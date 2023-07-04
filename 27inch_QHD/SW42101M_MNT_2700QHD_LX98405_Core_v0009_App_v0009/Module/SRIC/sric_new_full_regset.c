/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : sric_new_full_regset.c
 * created on : 17. 4. 2017
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

#include "hal_def.h"
#include "module_def.h"


#ifdef _USE_APP_LGD_LIB_
__WEAK SRIC_REG g_ROIC_Reg_Val[] = {
#else /* _USE_APP_LGD_LIB_ */
SRIC_REG g_ROIC_Reg_Val[] =
{
#endif /* _USE_APP_LGD_LIB_ */
	{ 0x000, 0x0010, 0x0010 },			// [ 00 ] CFGR_MD_IDLE
	{ 0x002, 0x0000, 0x0000 },          // [ 01 ] CFGR_SNSR_STR
	{ 0x004, 0xAA92, 0xAA92 },          // [ 02 ] CFGR_MD_GENERAL
	{ 0x006, 0x357F, 0x357F },          // [ 03 ] CFGR_AIP_ADC
	{ 0x008, 0x9357, 0x9357 },          // [ 04 ] CFGR_SSU_CTRL
	{ 0x00A, 0x030C, 0x030C },          // [ 05 ] CFGR_CH01_CR
	{ 0x00C, 0x030C, 0x030C },          // [ 06 ] CFGR_CH23_CR
	{ 0x00E, 0x030C, 0x030C },          // [ 07 ] CFGR_CH45_CR
	{ 0x010, 0x030C, 0x030C },          // [ 08 ] CFGR_CH67_CR
	{ 0x012, 0x030C, 0x030C },          // [ 09 ] CFGR_CH89_CR
	{ 0x014, 0x030C, 0x030C },          // [ 10 ] CFGR_CH0_EDG_CR
	{ 0x016, 0x030C, 0x030C },          // [ 11 ] CFGR_CH1_EDG_CR
	{ 0x018, 0x030C, 0x030C },          // [ 12 ] CFGR_CH2_EDG_CR
	{ 0x01A, 0x030C, 0x030C },          // [ 13 ] CFGR_CH3_EDG_CR
	{ 0x01C, 0x030C, 0x030C },          // [ 14 ] CFGR_CH4_EDG_CR
	{ 0x01E, 0x030C, 0x030C },          // [ 15 ] CFGR_CH5_EDG_CR
	{ 0x020, 0x030C, 0x030C },          // [ 16 ] CFGR_CH6_EDG_CR
	{ 0x022, 0x030C, 0x030C },          // [ 17 ] CFGR_CH7_EDG_CR
	{ 0x024, 0x030C, 0x030C },          // [ 18 ] CFGR_CH8_EDG_CR
	{ 0x026, 0x030C, 0x030C },          // [ 19 ] CFGR_CH9_EDG_CR
	{ 0x028, 0x0700, 0x0700 },          // [ 20 ] CFGR_TSYNC_NUM0
	{ 0x02A, 0x0700, 0x0700 },          // [ 21 ] CFGR_TSYNC_NUM1
	{ 0x02C, 0x0000, 0x0000 },          // [ 22 ] CFGR_TSYNC_DMMY
	{ 0x02E, 0x0105, 0x0105 },          // [ 23 ] CFGR_PWM_NUM0
	{ 0x030, 0x070E, 0x070E },          // [ 24 ] CFGR_PWM_NUM1
	{ 0x032, 0xB100, 0xB100 },          // [ 25 ] CFGR_CMUX_NORM
	{ 0x034, 0x014A, 0x014A },          // [ 26 ] CFGR_CMUX_NOISE
	{ 0x036, 0x5540, 0x5540 },          // [ 27 ] CFGR_COL_NUM
	{ 0x038, 0x4000, 0x4000 },          // [ 28 ] CFGR_OUTER
	{ 0x03A, 0x4040, 0x4040 },          // [ 29 ] CFGR_DIG_GAIN0
	{ 0x03C, 0x4040, 0x4040 },          // [ 30 ] CFGR_DIG_GAIN1
	{ 0x03E, 0x03E8, 0x03E8 },          // [ 31 ] CFGR_NIH_MIN0
	{ 0x040, 0x044C, 0x044C },          // [ 32 ] CFGR_NIH_MAX0
	{ 0x042, 0x07D0, 0x07D0 },          // [ 33 ] CFGR_NIH_MIN1
	{ 0x044, 0x0834, 0x0834 },          // [ 34 ] CFGR_NIH_MAX1
	{ 0x046, 0x0BB8, 0x0BB8 },          // [ 35 ] CFGR_NIH_MIN2
	{ 0x048, 0x0C1C, 0x0C1C },          // [ 36 ] CFGR_NIH_MAX2
	{ 0x04A, 0x0FA0, 0x0FA0 },          // [ 37 ] CFGR_NIH_MIN3
	{ 0x04C, 0x0FFF, 0x0FFF },          // [ 38 ] CFGR_NIH_MAX3
	{ 0x04E, 0x0000, 0x0000 },          // [ 39 ] CFGR_NIH_RDAT0
	{ 0x050, 0x0000, 0x0000 },          // [ 40 ] CFGR_NIH_RDAT1
	{ 0x052, 0x0000, 0x0000 },          // [ 41 ] CFGR_NIH_RDAT2
	{ 0x054, 0x0000, 0x0000 },          // [ 42 ] CFGR_NIH_RDAT3
	{ 0x056, 0x2040, 0x2040 },          // [ 43 ] CFGR_NIH_STD
	{ 0x058, 0x0011, 0x0011 },          // [ 44 ] CFGR_SHA_STR
	{ 0x05A, 0x4040, 0x4040 },          // [ 45 ] CFGR_DIG_GAIN2
	{ 0x05C, 0x0001, 0x0001 },          // [ 46 ] CFGR_PHTH0_WIDTH
	{ 0x05E, 0x0011, 0x0011 },          // [ 47 ] CFGR_PHT_SEL
	{ 0x060, 0x0002, 0x0002 },          // [ 48 ] CFGR_RSTP_WIDTH
	{ 0x062, 0x0680, 0x0680 },          // [ 49 ] CFGR_VCR_STR
	{ 0x064, 0x0024, 0x0024 },          // [ 50 ] CFGR_VCR_CTRL
	{ 0x066, 0x0F08, 0x0F08 },          // [ 51 ] CFGR_VCR_MD2
	{ 0x068, 0x0032, 0x0032 },          // [ 52 ] CFGR_CHIP0_LEN
	{ 0x06A, 0x0000, 0x0000 },          // [ 53 ] CFGR_TEST_OPT
	{ 0x06C, 0x0000, 0x0000 },          // [ 54 ] CFGR_DAC_IN
	{ 0x06E, 0x0190, 0x0190 },          // [ 55 ] CFGR_DAC_CNT
	{ 0x070, 0x0000, 0x0000 },          // [ 56 ] CFGR_RSVD0
	{ 0x072, 0x0000, 0x0000 },          // [ 57 ] CFGR_RSVD1
	{ 0x074, 0xFFFF, 0xFFFF },          // [ 58 ] CFGR_RSVD2
	{ 0x076, 0xFFFF, 0xFFFF },          // [ 59 ] CFGR_RSVD3
};
