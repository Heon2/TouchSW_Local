/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : sric.c
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
#include "sric_lib_param.h"
#include "pwm_lib_param.h"
#endif /* _USE_APP_LGD_LIB_ */


#ifndef _USE_APP_LGD_LIB_
typedef struct // __sric_reg
{
	uint16_t ROIC_addr:		16;
	uint16_t ROIC0_val:		16;
	uint16_t ROIC1_val:		16;
} __PACKED SRIC_REG;
#endif /* _USE_APP_LGD_LIB_ */


#ifdef _USE_APP_LGD_LIB_
__WEAK SRIC_REG g_ROIC_Reg_Val[] = {
#else /* _USE_APP_LGD_LIB_ */
SRIC_REG g_ROIC_Reg_Val[] = {
#endif /* _USE_APP_LGD_LIB_ */


#if 0
		{ 0x00, 0x2390, 0x2390 },         // [ 00 ] CFGR_PRODUCT_ID
		{ 0x02, 0x0000, 0x0000 },         // [ 01 ] CFGR_SNSR_STR
#if USED_NORMAL_NI_SENSING
#if (USED_IDLE_NI_SENSING_MUX_NUM == 3)
		{ 0x04, 0x4761, 0x4761 },         // [ 02 ] CFGR_MD_GENERAL // Normal 0x4F61 -> 0x4361
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 2)
		{ 0x04, 0x4761, 0x4361 },         // [ 02 ] CFGR_MD_GENERAL // Normal 0x4F61 -> 0x4361
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 1)
		{ 0x04, 0x4761, 0x4161 },         // [ 02 ] CFGR_MD_GENERAL // Normal 0x4F61 -> 0x4361
#endif /* (USED_IDLE_NI_SENSING_MUX_NUM == 3) */
#else /* USED_NORMAL_NI_SENSING */
		{ 0x04, 0x4061, 0x4061 },         // [ 02 ] CFGR_MD_GENERAL // Normal 0x4061 -> 0x4361
#endif /* USED_NORMAL_NI_SENSING */
		{ 0x06, 0x0D3F, 0x0D3F },         // [ 03 ] CFGR_AIP_ADC
#if USED_AFE_BIAS_CURRENT_DOWN
		{ 0x08, 0x001A, 0x001A },         // [ 04 ] CFGR_SSU_CTRL (Preamp(5uA), Integrator(2.5uA), SHA(5uA))
#else /* USED_AFE_BIAS_CURRENT_DOWN */
		{ 0x08, 0x111A, 0x111A },         // [ 04 ] CFGR_SSU_CTRL
#endif /* USED_AFE_BIAS_CURRENT_DOWN */
		{ 0x0A, 0x0601, 0x0601 },         // [ 05 ] CFGR_TSYNC_NUM0
		{ 0x0C, 0x0601, 0x0601 },         // [ 06 ] CFGR_TSYNC_NUM1
		{ 0x0E, 0x0000, 0x0000 },         // [ 07 ] CFGR_TSYNC_DMMY
		{ 0x10, 0x0104, 0x0104 },         // [ 08 ] CFGR_PWM_NUM0
		{ 0x12, 0x0A14, 0x0A14 },         // [ 09 ] CFGR_PWM_NUM1
		{ 0x14, 0x9D20, 0x9D20 },         // [ 10 ] CFGR_CMUX_NORM		<-------------  Total 10 mux(72*40)
		{ 0x16, 0x0030, 0x0030 },         // [ 11 ] CFGR_CHIP0_LEN		<------------- AFE 48개(72*40)
//		{ 0x18, 0x6661, 0x6650 },         // [ 12 ] CFGR_COL_NUM		<------------- Non DRD ALIGNED 12
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
		{ 0x50, 0x1C1C, 0x1C1C },         // [ 40 ] CFGR_SSU_CR_I00     <-------------
		{ 0x52, 0x1E1D, 0x1E1D },         // [ 41 ] CFGR_SSU_CR_I04		<-------------
		{ 0x54, 0x1F1F, 0x1F1F },         // [ 42 ] CFGR_SSU_CR_I08		<-------------

//		{ 0x50, 0x2A2A, 0x2A2A },         // [ 40 ] CFGR_SSU_CR_I00     <-------------
//		{ 0x52, 0x2A2A, 0x2A2A },         // [ 41 ] CFGR_SSU_CR_I04		<-------------
//		{ 0x54, 0x2A2A, 0x2A2A },         // [ 42 ] CFGR_SSU_CR_I08		<-------------

#if (USED_IDLE_NI_SENSING_MUX_NUM == 3)
		{ 0x56, 0x3434, 0x3434 },         // [ 43 ] CFGR_SSU_CR_I12
		{ 0x58, 0x3434, 0x3434 },         // [ 44 ] CFGR_SSU_CR_I14
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 2)
		{ 0x56, 0x3434, 0x3434 },         // [ 43 ] CFGR_SSU_CR_I12
		{ 0x58, 0x3434, 0x3434 },         // [ 44 ] CFGR_SSU_CR_I14
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 1)
		{ 0x56, 0x3434, 0x3434 },         // [ 43 ] CFGR_SSU_CR_I12
		{ 0x58, 0x3434, 0x3434 },         // [ 44 ] CFGR_SSU_CR_I14
#endif /* (USED_IDLE_NI_SENSING_MUX_NUM == 3) */
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
//		{ 0xA8, 0x0A14, 0x0A14 },         // [ 84 ] CFGR_PWM_NUM_NI
		{ 0xA8, 0x1114, 0x1114 },         // [ 84 ] CFGR_PWM_NUM_NI
#if (USED_IDLE_NI_SENSING_MUX_NUM == 3)
		{ 0xAA, 0x000F, 0x000F },         // [ 85 ] CFGR_CMUX_NI1
		{ 0xAC, 0x00F0, 0x00F0 },         // [ 86 ] CFGR_CMUX_NI2
		{ 0xAE, 0x0300, 0x0300 },         // [ 87 ] CFGR_CMUX_NI3
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 2)
		{ 0xAA, 0x000F, 0x000F },         // [ 85 ] CFGR_CMUX_NI1
		{ 0xAC, 0x03F0, 0x03F0 },         // [ 86 ] CFGR_CMUX_NI2
		{ 0xAE, 0x0000, 0x0000 },         // [ 87 ] CFGR_CMUX_NI3
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 1)
		{ 0xAA, 0x03FF, 0x03FF },         // [ 85 ] CFGR_CMUX_NI1
		{ 0xAC, 0x0000, 0x0000 },         // [ 86 ] CFGR_CMUX_NI2
		{ 0xAE, 0x0000, 0x0000 },         // [ 87 ] CFGR_CMUX_NI3
#endif /* (USED_IDLE_NI_SENSING_MUX_NUM == 3) */
		{ 0xB0, 0x0000, 0x0000 },         // [ 88 ] CFGR_CMUX_NI4
		{ 0xB2, 0x0800, 0x0800 },         // [ 89 ] CFGR_AFE_DUM // 0x0800 -> 0x0900 Idle even/mux
//		{ 0xB2, 0x0000, 0x0000 },         // [ 89 ] CFGR_AFE_DUM // 0x0000 -> 0x0100 Idle even/mux
		{ 0xB4, 0x0000, 0x0000 },         // [ 90 ] CFGR_RSVD0
		{ 0xB6, 0xFFFF, 0xFFFF },         // [ 91 ] CFGR_RSVD1
		{ 0xFE, 0x0000, 0x0000 },         // [ 92 ] CFGR_MD_IDLE
#else
		{ 0x000, 0x0010, 0x0010 },			// [ 00 ] CFGR_MD_IDLE
		{ 0x002, 0x0000, 0x0000 },          // [ 01 ] CFGR_SNSR_STR
		{ 0x004, 0xAA92, 0xAA92 },          // [ 02 ] CFGR_MD_GENERAL
		{ 0x006, 0x357F, 0x357F },          // [ 03 ] CFGR_AIP_ADC		<<  1:0x35C3, 2:0x35C5, 3:0x35C9, 4:0x35D1, 5:0x35E1
//		{ 0x006, 0x35E1, 0x35E1 },
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
		{ 0x06A, 0x0000, 0x0000 },          // [ 53 ] CFGR_TEST_OPT		<<		0x0010
//		{ 0x06A, 0x0010, 0x0010 },
		{ 0x06C, 0x0000, 0x0000 },          // [ 54 ] CFGR_DAC_IN
		{ 0x06E, 0x0190, 0x0190 },          // [ 55 ] CFGR_DAC_CNT
		{ 0x070, 0x0000, 0x0000 },          // [ 56 ] CFGR_RSVD0
		{ 0x072, 0x0000, 0x0000 },          // [ 57 ] CFGR_RSVD1
		{ 0x074, 0xFFFF, 0xFFFF },          // [ 58 ] CFGR_RSVD2
		{ 0x076, 0xFFFF, 0xFFFF },          // [ 59 ] CFGR_RSVD3


//		{ 0x0000, 0x0010, 0x0010 },
//		{ 0x0002, 0x0000, 0x0000 },
//		{ 0x0004, 0xAA92, 0xAA92 },
//		{ 0x0006, 0x357F, 0x357F },
//		{ 0x0008, 0x93D7, 0x93D7 },
//		{ 0x000A, 0x0CD5, 0x0CD5 },
//		{ 0x000C, 0x0B34, 0x0B34 },
//		{ 0x000E, 0x0724, 0x0724 },
//		{ 0x0010, 0x0314, 0x0314 },
//		{ 0x0012, 0x044C, 0x044C },
//		{ 0x0014, 0x0EFB, 0x0EFB },
//		{ 0x0016, 0x0CF3, 0x0CF3 },
//		{ 0x0018, 0x0D34, 0x0D34 },
//		{ 0x001A, 0x0B2C, 0x0B2C },
//		{ 0x001C, 0x0924, 0x0924 },
//		{ 0x001E, 0x071C, 0x071C },
//		{ 0x0020, 0x0514, 0x0514 },
//		{ 0x0022, 0x030C, 0x030C },
//		{ 0x0024, 0x0EBA, 0x0EBA },
//		{ 0x0026, 0x0965, 0x0965 },
//		{ 0x0028, 0x0700, 0x0700 },
//		{ 0x002A, 0x0700, 0x0700 },
//		{ 0x002C, 0x0000, 0x0000 },
//		{ 0x002E, 0x0105, 0x0105 },
//		{ 0x0030, 0x070E, 0x070E },
//		{ 0x0032, 0xB100, 0xB100 },
//		{ 0x0034, 0x014A, 0x014A },
//		{ 0x0036, 0x5540, 0x5540 },
//		{ 0x0038, 0x401A, 0x401A },
//		{ 0x003A, 0x4040, 0x4040 },
//		{ 0x003C, 0x4040, 0x4040 },
//		{ 0x003E, 0x03E8, 0x03E8 },
//		{ 0x0040, 0x044C, 0x044C },
//		{ 0x0042, 0x07D0, 0x07D0 },
//		{ 0x0044, 0x0834, 0x0834 },
//		{ 0x0046, 0x0BB8, 0x0BB8 },
//		{ 0x0048, 0x0C1C, 0x0C1C },
//		{ 0x004A, 0x0FA0, 0x0FA0 },
//		{ 0x004C, 0x0FFF, 0x0FFF },
//		{ 0x004E, 0x0000, 0x0000 },
//		{ 0x0050, 0x0000, 0x0000 },
//		{ 0x0052, 0x0000, 0x0000 },
//		{ 0x0054, 0x0000, 0x0000 },
//		{ 0x0056, 0x2040, 0x2040 },
//		{ 0x0058, 0x0019, 0x0019 },
//		{ 0x005A, 0x4040, 0x4040 },
//		{ 0x005C, 0x0001, 0x0001 },
//		{ 0x005E, 0x0011, 0x0011 },
//		{ 0x0060, 0x0002, 0x0002 },
//		{ 0x0062, 0x0680, 0x0680 },
//		{ 0x0064, 0x0024, 0x0024 },
//		{ 0x0066, 0x0506, 0x0506 },
//		{ 0x0068, 0x0032, 0x0032 },
//		{ 0x006A, 0x0000, 0x0000 },
//		{ 0x006C, 0x0000, 0x0000 },
//		{ 0x000A, 0x069A, 0x069A },
//		{ 0x000C, 0x069A, 0x069A },
//		{ 0x000E, 0x069A, 0x069A },
//		{ 0x0010, 0x069A, 0x069A },
//		{ 0x0012, 0x069A, 0x069A },
//		{ 0x0014, 0x069A, 0x069A },
//		{ 0x0016, 0x069A, 0x069A },
//		{ 0x0018, 0x069A, 0x069A },
//		{ 0x001A, 0x069A, 0x069A },
//		{ 0x001C, 0x069A, 0x069A },
//		{ 0x001E, 0x069A, 0x069A },
//		{ 0x0020, 0x069A, 0x069A },
//		{ 0x0022, 0x069A, 0x069A },
//		{ 0x0024, 0x069A, 0x069A },
//		{ 0x0026, 0x069A, 0x069A },
//		{ 0x0024, 0x069A, 0x069A },
//		{ 0x0022, 0x071A, 0x071A },
//		{ 0x0020, 0x051A, 0x051A },
//		{ 0x001E, 0x031A, 0x031A },
//		{ 0x001C, 0x031A, 0x031A },
//		{ 0x001A, 0x011A, 0x011A },
//		{ 0x0018, 0x011A, 0x011A },
//		{ 0x0016, 0x0E9A, 0x0E9A },
//		{ 0x0014, 0x0C9A, 0x0C9A },
//		{ 0x0024, 0x0A9A, 0x0A9A },
//		{ 0x0022, 0x069A, 0x069A },
//		{ 0x0020, 0x069A, 0x069A },
//		{ 0x001E, 0x069A, 0x069A },
//		{ 0x001C, 0x069A, 0x069A },
//		{ 0x001A, 0x069A, 0x069A },
//		{ 0x0018, 0x069A, 0x069A },
//		{ 0x0016, 0x069A, 0x069A },
//		{ 0x0014, 0x069A, 0x069A },
//		{ 0x005A, 0x069A, 0x069A },




#endif
};


#if USED_SRIC_REG_MSPI_CHECK
uint16_t ulTestBuffer_R0_[6] = {0,};
uint16_t ulTestBuffer_R1_[6] = {0,};
#endif /* USED_SRIC_REG_MSPI_CHECK */

//static const tModuleSRICCommonConf_t * s_pktmoduleSRICCommonConf = NULL;
//uint16_t R0_Read_Buf[6] = { 0, };
//uint16_t R1_Read_Buf[6] = { 0, };

SRIC_REG * pSRIC_REG = NULL;
//uint16_t r0_rxbuf[(sizeof(tROIC_RegDef) / 2)] = {0,};
//SRIC_TypeDef r0_rxbuf;

void SW92400_Set_CFGR(eSENSING_MODE_t eSensingMode)
{
//	SW92400_Set_Register(CFGR_AIP_ADC, s_pktmoduleSRICCommonConf->tParam_AIP_ADC.ulBulk, ROIC_0);
//	SW92400_Set_Register(SSU_CTRL, s_pktmoduleSRICCommonConf->tParam_SSU_CTRL.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(CMUX_NORM, s_pktmoduleSRICCommonConf->tParam_CMUX_NORM.ulBulk, ROIC_0);
//	SW92400_Set_Register(CMUX_NUM_PEN, s_pktmoduleSRICCommonConf->tParam_CMUX_NUM_PEN.ulBulk, ROIC_0);
//
//	SW92400_Set_Register(CHIP0_LEN, s_pktmoduleSRICCommonConf->tParam_CHIP0_LEN.ulBulk, ROIC_0);
//
//	SW92400_Set_Register(COL_NUM, s_pktmoduleSRICCommonConf->tParam_COL_NUM.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(OUTER, s_pktmoduleSRICCommonConf->tParam_OUTER.ulBulk, ROIC_ALL);

//	SW92400_Set_Register(DIG_GAIN0, R_DIG_GAIN0, ROIC_0);
//	SW92400_Set_Register(DIG_GAIN1, R_DIG_GAIN1, ROIC_0);
//	SW92400_Set_Register(DIG_GAIN2, R_DIG_GAIN2, ROIC_0);
//	SW92400_Set_Register(NIH_MIN0, R_NIH_MIN0, ROIC_0);
//	SW92400_Set_Register(NIH_MAX0, R_NIH_MAX0, ROIC_0);
//	SW92400_Set_Register(NIH_MIN1, R_NIH_MIN1, ROIC_0);
//	SW92400_Set_Register(NIH_MAX1, R_NIH_MAX1, ROIC_0);
//	SW92400_Set_Register(NIH_MIN2, R_NIH_MIN2, ROIC_0);
//	SW92400_Set_Register(NIH_MAX2, R_NIH_MAX2, ROIC_0);
//	SW92400_Set_Register(NIH_MIN3, R_NIH_MIN3, ROIC_0);
//	SW92400_Set_Register(NIH_MAX3, R_NIH_MAX3, ROIC_0);



//	SW92400_Set_Register(NIH_STD, s_pktmoduleSRICCommonConf->tParam_NIH_STD.ulBulk, ROIC_0);
//	SW92400_Set_Register(SHA_STR, s_pktmoduleSRICCommonConf->tParam_SHA_STR.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(RSTP_WIDTH, s_pktmoduleSRICCommonConf->tParam_RSTP_WIDTH.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(VCR_STR, s_pktmoduleSRICCommonConf->tParam_VCR_STR.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(VCR2_MD, s_pktmoduleSRICCommonConf->tParam_VCR2_MD.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(VCR2_PHTCR, s_pktmoduleSRICCommonConf->tParam_VCR2_PHTCR.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(PHTH0_WIDTH, s_pktmoduleSRICCommonConf->tParam_PHTH0_WIDTH.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(PHTH1_WIDTH, s_pktmoduleSRICCommonConf->tParam_PHTH1_WIDTH.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(SHA_RUN, s_pktmoduleSRICCommonConf->tParam_SHA_RUN.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(RSTP_DLY1, s_pktmoduleSRICCommonConf->tParam_RSTP_DLY1.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(RSTP_DLY2, s_pktmoduleSRICCommonConf->tParam_RSTP_DLY2.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(TEST_OPT, s_pktmoduleSRICCommonConf->tParam_TEST_OPT.ulBulk, ROIC_0);

//	SW92400_Set_Register(LV_SSU_ON, s_pktmoduleSRICCommonConf->tParam_LV_SSU_ON.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(HV_SSU_ON, s_pktmoduleSRICCommonConf->tParam_HV_SSU_ON.ulBulk, ROIC_ALL);

//	SW92400_Set_Register(SSU_PRE_GC, s_pktmoduleSRICCommonConf->tParam_SSU_PRE_GC.ulBulk, ROIC_ALL);
//	SW92400_Set_Register(CMUX_REMAP0, s_pktmoduleSRICCommonConf->tParam_CMUX_REMAP0.ulBulk, ROIC_0);
//	SW92400_Set_Register(CMUX_REMAP1, s_pktmoduleSRICCommonConf->tParam_CMUX_REMAP1.ulBulk, ROIC_0);
//	SW92400_Set_Register(CMUX_REMAP2, s_pktmoduleSRICCommonConf->tParam_CMUX_REMAP2.ulBulk, ROIC_0);
//
//	SW92400_Set_Register(PWM_NUM_NI, s_pktmoduleSRICCommonConf->tParam_PWM_NUM_NI.ulBulk, ROIC_0);
//	SW92400_Set_Register(CMUX_NI1, s_pktmoduleSRICCommonConf->tParam_CMUX_NI1.ulBulk, ROIC_0);
//	SW92400_Set_Register(CMUX_NI2, s_pktmoduleSRICCommonConf->tParam_CMUX_NI2.ulBulk, ROIC_0);
//	SW92400_Set_Register(CMUX_NI3, s_pktmoduleSRICCommonConf->tParam_CMUX_NI3.ulBulk, ROIC_0);
//	SW92400_Set_Register(CMUX_NI4, s_pktmoduleSRICCommonConf->tParam_CMUX_NI4.ulBulk, ROIC_0);
//	SW92400_Set_Register(AFE_DUM, s_pktmoduleSRICCommonConf->tParam_AFE_DUM.ulBulk, ROIC_0);

//#if !USED_OPERATION_STAND_ALONE
//	{
//		tSRIC_CFGR_MD_IDLE_t tParam_MD_IDLE;
//		tParam_MD_IDLE.ulBulk = s_pktmoduleSRICCommonConf->tParam_MD_IDLE.ulBulk;
//		if(IS_S3_MODE(eSensingMode))
//		{
//			tParam_MD_IDLE.tBit.sdic_lcd_off = 1;
//		}
////		SW92400_Set_Register(MD_IDLE, tParam_MD_IDLE.ulBulk, ROIC_0);
//	}

//#endif /* !USED_OPERATION_STAND_ALONE */
//	SW92400_Set_LocalPenSensingStatusCTRL(0, 0);
//	SW92400_Set_Register(PEN_CTRL, R_PEN_CTRL, ROIC_0);
//	SW92400_Set_Register(HALF_COPY, s_pktmoduleSRICCommonConf->tParam_HALF_COPY.ulBulk, ROIC_0);
}

void SRIC_Initialize(void)
{
//	s_pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
}

void SW92400_Reset(eSENSING_MODE_t eSensingMode)
{
	uint16_t i;

	//Init Pins
	initGPIO(PIN_MSPI_SSN_0, GPIO_Mode0_GPIO, Output);
	initGPIO(PIN_MSPI_SSN_1, GPIO_Mode0_GPIO, Output);
	initGPIO(PIN_MSPI_SSN_2, GPIO_Mode0_GPIO, Output);
	initGPIO(PIN_MSPI_SSN_3, GPIO_Mode0_GPIO, Output);
	initGPIO(PIN_MSPI_SSN_4, GPIO_Mode0_GPIO, Output);
	initGPIO(PIN_MSPI_SSN_5, GPIO_Mode0_GPIO, Output);

	initGPIO(PIN_MSPI_MOSI_0, GPIO_Mode0_GPIO, Output);
	initGPIO(PIN_MSPI_MOSI_1, GPIO_Mode0_GPIO, Output);
	initGPIO(PIN_MSPI_MOSI_2, GPIO_Mode0_GPIO, Output);
	initGPIO(PIN_MSPI_MOSI_3, GPIO_Mode0_GPIO, Output);
	initGPIO(PIN_MSPI_MOSI_4, GPIO_Mode0_GPIO, Output);
	initGPIO(PIN_MSPI_MOSI_5, GPIO_Mode0_GPIO, Output);

	//Pin State
	writeBitToGPIO( PIN_MSPI_SSN_0, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_1, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_2, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_3, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_4, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_5, LOW);

	delay_us(100);
	writeBitToGPIO( PIN_MSPI_SSN_0, HIGH);
	writeBitToGPIO( PIN_MSPI_SSN_1, HIGH);
	writeBitToGPIO( PIN_MSPI_SSN_2, HIGH);
	writeBitToGPIO( PIN_MSPI_SSN_3, HIGH);
	writeBitToGPIO( PIN_MSPI_SSN_4, HIGH);
	writeBitToGPIO( PIN_MSPI_SSN_5, HIGH);

	writeBitToGPIO( PIN_MSPI_MOSI_0, LOW);
	writeBitToGPIO( PIN_MSPI_MOSI_1, LOW);
	writeBitToGPIO( PIN_MSPI_MOSI_2, LOW);
	writeBitToGPIO( PIN_MSPI_MOSI_3, LOW);
	writeBitToGPIO( PIN_MSPI_MOSI_4, LOW);
	writeBitToGPIO( PIN_MSPI_MOSI_5, LOW);
	delay_us(100);

	for (i = 0; i < SRIC_PROTOCOL_RESET_COUNT; i++)
	{
		writeBitToGPIO( PIN_MSPI_MOSI_0, HIGH);
		writeBitToGPIO( PIN_MSPI_MOSI_1, HIGH);
		writeBitToGPIO( PIN_MSPI_MOSI_2, HIGH);
		writeBitToGPIO( PIN_MSPI_MOSI_3, HIGH);
		writeBitToGPIO( PIN_MSPI_MOSI_4, HIGH);
		writeBitToGPIO( PIN_MSPI_MOSI_5, HIGH);
		delay_us(10);
		writeBitToGPIO( PIN_MSPI_MOSI_0, LOW);
		writeBitToGPIO( PIN_MSPI_MOSI_1, LOW);
		writeBitToGPIO( PIN_MSPI_MOSI_2, LOW);
		writeBitToGPIO( PIN_MSPI_MOSI_3, LOW);
		writeBitToGPIO( PIN_MSPI_MOSI_4, LOW);
		writeBitToGPIO( PIN_MSPI_MOSI_5, LOW);
		delay_us(10);
	}
	writeBitToGPIO( PIN_MSPI_SSN_0, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_1, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_2, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_3, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_4, LOW);
	writeBitToGPIO( PIN_MSPI_SSN_5, LOW);

	delay_us(100);
}

uint16_t databuf[6] = {0,};

bool_t SW92400_Hopp110_Init(void)
{
	int i, k;
	uint16_t * pR0_Reg;
	uint16_t * pR1_Reg;
	int chkcnt = 3;
//	pR0_Reg = (uint16_t *) &s_pktmoduleSRICCommonConf->R0_RegVal_Active;
//	pR1_Reg = (uint16_t *) &s_pktmoduleSRICCommonConf->R1_RegVal_Active;

	for (i = 5; i < 25/*iRegCntMax*/; ++i)
	{
		// R0 Register Validate Check (3Cycle)
		//for (k = 0; k < chkcnt; ++k)
		{
//			SW92400_Set_Register(i * 2, pR0_Reg[i], ROIC_0);	//LBJ_CHECK : Need to develop hopping algorithm
		}

	}
	//SW92400_Set_Register(24 * 2, pR0_Reg[i], ROIC_0);
	
	//while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x0);
	//while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x1);
	for (i = 5; i < 25/*iRegCntMax*/; ++i)
	//for (i = 0; i < 56/*iRegCntMax*/; ++i)
	{
		// R0 Register Validate Check (3Cycle)
		//for (k = 0; k < chkcnt; ++k)
		{
			if (SW92400_Check(i * 2, pR0_Reg[i], ROIC_ALL) == FALSE)
			{
		//		if(k == 2)
					return FALSE;
			}
			else
			{
				//break;
			}
		}
	}
	//delay_us(1000);
	
	return TRUE;
}

void SRIC_Run(void)
{
	  MSPI_RegisterAllSricWrite((uint32_t)(0x0020),   0x1      );  // tc_start
}

void SRIC_Stop(void)
{
	  MSPI_RegisterAllSricWrite((uint32_t)(0x0020),  0x0       );  //  tc_stop
}





uint16_t SW92400_Get_Register(uint8_t ch, uint32_t addr)
{
	uint16_t retbuf[6] = {0,};

//	MSPI_RegisterRead(addr, retbuf);
	return (retbuf[ch]);
}

bool_t SW92400_Check(uint32_t addr, uint16_t inputval, eROICSelect_t sel)
{
	int i;

	uint16_t buf[MSPI_NUM] = {0,};

	if (sel == ROIC_0)
	{
	//	MSPI_RegisterRead(R0(addr), buf);
	}
	else if (sel == ROIC_1)
	{
	//	MSPI_RegisterRead(R1(addr), buf);
	}
	else if (sel == ROIC_ALL)
	{
	//	MSPI_RegisterRead(R0(addr), buf);
	//	MSPI_RegisterRead(R1(addr), buf);
	}
	else if (sel == DEFAULT)
	{
	}

	for (i = 0; i < MSPI_NUM; ++i)
	{
		if (inputval != buf[i])
			return FALSE;
	}

	return TRUE;
}

void SW92400_Each_Set_Register(uint32_t addr, uint16_t * pval, eROICSelect_t sel)
{
	if (sel == ROIC_0)
	{
//		MSPI_EachRegisterWrite(R0(addr), pval);
	}
	else if (sel == ROIC_1)
	{
	//	MSPI_EachRegisterWrite(R1(addr), pval);
	}
	else if (sel == ROIC_ALL)
	{
//		MSPI_EachRegisterWrite(R0(addr), pval);
	//	MSPI_EachRegisterWrite(R1(addr), pval);
	}
	else if (sel == SM_ROIC_0)
	{
	//	MSPI_EachRegisterWrite(SM_R0(addr), pval);
	}
	else if (sel == SM_ROIC_1)
	{
//		MSPI_EachRegisterWrite(SM_R1(addr), pval);
	}
	else if (sel == SM_ROIC_ALL)
	{
//		MSPI_EachRegisterWrite(SM_R0(addr), pval);
//		MSPI_EachRegisterWrite(SM_R1(addr), pval);
	}
	else if (sel == DEFAULT)
	{
	}
}


/*
 * Open Short Test..
 */
void SRIC_Set_OS(uint16_t regAIP_ADC, uint16_t regTEST_OPT)
{
#if (CUSTOMER == MODEL_LGD_SW92400)
/*	Normal Frame
 *  0x036A 0x0000
 *	0x0306 0x357F
 *
 *	1 Frame
 *	0x036A 0x0010
 *	0x0306 0x35C3
 *
 *	2 Frame
 *	0x036A 0x0010
 *	0x0306 0x35C5
 *
 *	3 Frame
 *	0x036A 0x0010
 *	0x0306 0x35C9
 *
 *	4 Frame
 *	0x036A 0x0010
 *	0x0306 0x35D1
 *
 *	5 Frame
 *	0x036A 0x0010
 *	0x0306 0x35E1
 *
 */
//	MSPI_RegisterWrite(R0(0x06), regAIP_ADC);	// CFGR_AIP_ADC
//	MSPI_RegisterWrite(R0(0x6A), regTEST_OPT);	// CFGR_TEST_OPT
#else /* if(CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
//	MSPI_RegisterWrite(R0(0x06), regAIP_ADC);	// CFGR_AIP_ADC
//	MSPI_RegisterWrite(R0(0x4A), regTEST_OPT);	// CFGR_TEST_OPT
#endif /* (CUSTOMER == MODEL_LGD_SW92400) */
}

/*
 * C-Mux OFF는 main frequency에서만..
 */
void SW92400_Set_CMUXOFF(bool_t bIsEnable)
{
//	if (bIsEnable)
//	{
//		SW92400_Set_Register(g_ROIC_Reg_Val[11].ROIC_addr, 0x0138, ROIC_0);
//		SW92400_Set_Register(g_ROIC_Reg_Val[32].ROIC_addr, 0x0600, ROIC_0);
//		SW92400_Set_Register(g_ROIC_Reg_Val[63].ROIC_addr, 0xABA8, ROIC_0);
//	}
//	else
//	{
//		SW92400_Set_Register(g_ROIC_Reg_Val[11].ROIC_addr, g_ROIC_Reg_Val[11].ROIC0_val, ROIC_0);
//		SW92400_Set_Register(g_ROIC_Reg_Val[32].ROIC_addr, g_ROIC_Reg_Val[32].ROIC0_val, ROIC_0);
//		SW92400_Set_Register(g_ROIC_Reg_Val[63].ROIC_addr, g_ROIC_Reg_Val[63].ROIC0_val, ROIC_0);
//	}
}
//
//void SW92400_Set_FreqConfig(eSENSING_MODE_t eSensingMode)
extern volatile uint8_t HOPP_FLAG;
bool_t SW92400_Set_FreqConfig(eSENSING_MODE_t eSensingMode)
{
	if(IS_ACTIVE_MODE(eSensingMode))
	{
		if(IS_ACTIVE_MODE_FRQ_MAIN(eSensingMode))
		{
			//delay_us(10000);
			//SW92400_Reset(eSensingMode);
			//delay_ms(100);
			//MSPI_Reset();
			//MSPI_Initialize();
			//MSPI_Set_TLPMODE();
			//SRIC_Stop();
			if(HOPP_FLAG == TRUE)
					HOPP_FLAG = FALSE;
			//while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x0);
			//while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x1);
			//SRIC_Stop();
			if(SW92400_Hopp110_Init()==FALSE)
				return FALSE;
			//SRIC_Init(eSensingMode);
			SRIC_Run();
			MSPI_Set_AITMODE(eSensingMode);
			MSPI_ITConfig(ENABLE);
			MSPI_Cmd(ENABLE);

		}
		else if(IS_ACTIVE_MODE_FRQ_HOP1(eSensingMode))
		{
			//delay_us(5000);
			//delay_ms(10);
			//SW92400_Reset(eSensingMode);
			//delay_ms(100);
			//delay_us(10000);
			//MSPI_Reset();
			//MSPI_Initialize();
			//MSPI_Set_TLPMODE();
			if(HOPP_FLAG == TRUE)
					HOPP_FLAG = FALSE;
			//while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x0);
			//while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x1);
			//SRIC_Stop();
			// if(SW92400_Hopp130_Init()==FALSE	//LBJ_CHECK : Need to change SRIC_Init function...
				return FALSE;
			//SW92400_Hopp1_Init();
			SRIC_Run();
			MSPI_Set_AITMODE(eSensingMode);
			MSPI_ITConfig(ENABLE);
			MSPI_Cmd(ENABLE);

		}
		else if(IS_ACTIVE_MODE_FRQ_HOP2(eSensingMode))
		{
		}
	}
//	else
//	{
//		SW92400_Set_Register(g_ROIC_Reg_Val[63].ROIC_addr, g_ROIC_Reg_Val[63].ROIC0_val, ROIC_0);
//	}
	return TRUE;
}

void SW92400_SetActiveIdleOperationMode(eSENSING_MODE_t eSensingMode)
{
//	MSPI_Set_TLPMODE();
//
//	SW92400_Set_FreqConfig(eSensingMode);
//	if(IS_ACTIVE_MODE(eSensingMode))
//	{
//#if (!USED_NORMAL_NI_SENSING)
//		SW92400_Set_Register(g_ROIC_Reg_Val[02].ROIC_addr, g_ROIC_Reg_Val[02].ROIC0_val, ROIC_0);
//#endif /* (!USED_NORMAL_NI_SENSING) */
//		SW92400_Set_Register(g_ROIC_Reg_Val[89].ROIC_addr, g_ROIC_Reg_Val[89].ROIC0_val, ROIC_0);
//	}
//	else
//	{
//#if (!USED_NORMAL_NI_SENSING)
//#if (USED_IDLE_NI_SENSING_MUX_NUM == 3)
//		SW92400_Set_Register(g_ROIC_Reg_Val[02].ROIC_addr, 0x4761, ROIC_0);
//#elif (USED_IDLE_NI_SENSING_MUX_NUM == 2)
//		SW92400_Set_Register(g_ROIC_Reg_Val[02].ROIC_addr, 0x4361, ROIC_0);
//#elif (USED_IDLE_NI_SENSING_MUX_NUM == 1)
//		SW92400_Set_Register(g_ROIC_Reg_Val[02].ROIC_addr, 0x4161, ROIC_0);
//#endif /* (USED_IDLE_NI_SENSING_MUX_NUM == 3) */
//#endif /* (!USED_NORMAL_NI_SENSING) */
//		SW92400_Set_Register(g_ROIC_Reg_Val[89].ROIC_addr, 0x0900, ROIC_0);
//	}
//
//	MSPI_Set_AITMODE(eSensingMode);
//	MSPI->SPISTART = 0x3F;
}

#if (CUSTOMER == MODEL_LGD_LX98405)
#define MAX_CHECK_NUM (3)
bool_t SRIC_Init(eSENSING_MODE_t eSensingMode)
{
	LX98405_RegisterInit(eSensingMode);

	// Open Short test...
//	LX98405_OpenShort_SourceGnd_Setting();
//
//	LX98405_OpenShort_Local_Global_Tune();
//
//	LX98405_OpenShort_Mux_Low_En(2);

	// Even/Odd Short test...
//	LX98405_EvenOdd_Short_Setting(1);  // Even Short...
//
//	LX98405_Short_Local_Global_Tune();



	delay_us(1000);
	return TRUE;
}
#else
bool_t SRIC_Init(eSENSING_MODE_t eSensingMode)
{
	int i, k;
	uint16_t * pR0_Reg;
	uint16_t * pR1_Reg;
	
#if USED_LPWG_MODE_CONTROL
	if(IS_LPWG_MODE(eSensingMode))
	{
		pR0_Reg = (uint16_t *) &s_pktmoduleSRICCommonConf->R0_RegVal_LPWG;
		pR1_Reg = (uint16_t *) &s_pktmoduleSRICCommonConf->R1_RegVal_LPWG;
	}
	else
	{
		pR0_Reg = (uint16_t *) &s_pktmoduleSRICCommonConf->R0_RegVal_Active;
		pR1_Reg = (uint16_t *) &s_pktmoduleSRICCommonConf->R1_RegVal_Active;
	}
#else /* USED_LPWG_MODE_CONTROL */
	pR0_Reg = (uint16_t *) &s_pktmoduleSRICCommonConf->R0_RegVal_Active;
	pR1_Reg = (uint16_t *) &s_pktmoduleSRICCommonConf->R1_RegVal_Active;
#endif /* USED_LPWG_MODE_CONTROL */

	int CheckCntMax = 3;
#if (CUSTOMER == MODEL_LGD_SW92400)
	int iRegCntMax = 56;
#else /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
	int iRegCntMax = 95;
#endif /* (CUSTOMER == MODEL_LGD_SW92400) */

	
#if (CUSTOMER == MODEL_LGD_SW92400)
	for (i = 0; i < iRegCntMax; ++i)
	{
		SRIC_Set_Register(i * 2, pR0_Reg[i], ROIC_0);
	}
#else /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
	for (i = 0; i < iRegCntMax; ++i)
	{
		SRIC_Set_Register(i * 2, pR0_Reg, ROIC_0);
		SRIC_Set_Register(i * 2, pR1_Reg, ROIC_1);
		pR0_Reg += MSPI_NUM;
		pR1_Reg += MSPI_NUM;
	}
	SRIC_Set_Register(0xFA, pR0_Reg, ROIC_0);
	SRIC_Set_Register(0xFA, pR1_Reg, ROIC_1);
	pR0_Reg += MSPI_NUM;
	pR1_Reg += MSPI_NUM;
	SRIC_Set_Register(0xFC, pR0_Reg, ROIC_0);
	SRIC_Set_Register(0xFC, pR1_Reg, ROIC_1);
	pR0_Reg += MSPI_NUM;
	pR1_Reg += MSPI_NUM;
	SRIC_Set_Register(0xFE, pR0_Reg, ROIC_0);
	SRIC_Set_Register(0xFE, pR1_Reg, ROIC_1);
#endif /* (CUSTOMER == MODEL_LGD_SW92400) */

	//LBJ_CHECK : Need to develop function to check SRIC register
//	for (i = 0; i < iRegCntMax; ++i)
//	{
//		for (k = 0; k < CheckCntMax; ++k)
//		{
//			if (SW92400_Check(i * 2, pR0_Reg[i], ROIC_ALL) == FALSE)
//			{
//				if(k == 2) return FALSE;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}

//#if (CUSTOMER == MODEL_LGD_SW97400B)
//	for (k = 0; k < CheckCntMax; ++k)
//	{
//		if (SW92400_Check(0xFA, pR0_Reg[iRegCntMax], ROIC_ALL) == FALSE)
//		{
//			if(k == 2) return FALSE;
//		}
//		else
//		{
//			break;
//		}
//	}
//	for (k = 0; k < CheckCntMax; ++k)
//	{
//		if (SW92400_Check(0xFC, pR0_Reg[iRegCntMax+1], ROIC_ALL) == FALSE)
//		{
//			if(k == 2) return FALSE;
//		}
//		else
//		{
//			break;
//		}
//	}
//	for (k = 0; k < CheckCntMax; ++k)
//	{
//		if (SW92400_Check(0xFE, pR0_Reg[iRegCntMax+2], ROIC_ALL) == FALSE)
//		{
//			if(k == 2) return FALSE;
//		}
//		else
//		{
//			break;
//		}
//	}
//#endif /* (CUSTOMER == MODEL_LGD_SW97400B) */

	delay_us(1000);
	return TRUE;
}
#endif

#if (CUSTOMER == MODEL_LGD_SW92400)
void SRIC_Set_Register(uint32_t addr, uint16_t val, eROICSelect_t sel)
{
	if (sel == ROIC_0)
	{
		MSPI_RegisterWrite(R0(addr), val);
		//MSPI_RegisterWrite(SM_R0(addr), val);
	}
	else if (sel == ROIC_1)
	{
		MSPI_RegisterWrite(R1(addr), val);
		MSPI_RegisterWrite(SM_R1(addr), val);
	}
	else if (sel == ROIC_ALL)
	{
		MSPI_RegisterWrite(R0(addr), val);
		MSPI_RegisterWrite(R1(addr), val);
	}
	else if (sel == DEFAULT)
	{
	}
}
#else /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
void SRIC_Set_Register(uint32_t addr, uint16_t *WriteBuf, eROICSelect_t sel)
{
	if (sel == ROIC_0)
	{
	//	MSPI_RegisterWriteBuf(R0(addr), WriteBuf);
	}
	else if (sel == ROIC_1)
	{
//		MSPI_RegisterWriteBuf(R1(addr), WriteBuf);
	}
	else if (sel == ROIC_ALL)
	{
	//	MSPI_RegisterWriteBuf(R0(addr), WriteBuf);
//		MSPI_RegisterWriteBuf(R1(addr), WriteBuf);
	}
	else if (sel == DEFAULT)
	{
	}
}
#endif /* (CUSTOMER == MODEL_LGD_SW92400) */
