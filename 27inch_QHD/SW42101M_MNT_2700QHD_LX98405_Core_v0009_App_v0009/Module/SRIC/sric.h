/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : sric.h
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

#ifndef SRIC_H_
#define SRIC_H_


#include "_sric.h"

//#include "LGD\parameter_sric.h"
//#if USED_FINGER_ONLY
//#include "SHARP\parameter_sric_finger.h"
//#else /* USED_FINGER_ONLY */
//#include "SHARP\parameter_sric_pen.h"
//#endif /* USED_FINGER_ONLY */

#define PEN_TSYNC_BEACON		(0)
#define PEN_TSYNC_NOTUSED		(0)
#define PEN_TSYNC_FINGER		(1)
#define PEN_TSYNC_POSITION		(2)
#define PEN_TSYNC_DATA			(3)

//#define SRIC_ACCESS_REG_NUM 	(50)

// SW92400 Register Table
//typedef enum
//{
//	CFGR_PRODUCT_ID,
//	CFGR_SNSR_STR,
//	CFGR_MD_GENERAL,
//	CFGR_AIP_ADC,
//	CFGR_SSU_CTRL,
//	CFGR_TSYNC_NUM0,
//	CFGR_TSYNC_NUM1,
//	CFGR_TSYNC_DMMY,
//	CFGR_PWM_NUM0,
//	CFGR_PWM_NUM1,
//	CFGR_CMUX_NORM,
//	CFGR_CHIP0_LEN,
//	CFGR_COL_NUM,
//	CFGR_OUTER,
//	CFGR_DIG_GAIN0,
//	CFGR_DIG_GAIN1,
//	CFGR_NIH_MIN0,
//	CFGR_NIH_MAX0,
//	CFGR_NIH_MIN1,
//	CFGR_NIH_MAX1,
//	CFGR_NIH_MIN2,
//	CFGR_NIH_MAX2,
//	CFGR_NIH_MIN3,
//	CFGR_NIH_MAX3,
//	CFGR_NIH_RDAT0,
//	CFGR_NIH_RDAT1,
//	CFGR_NIH_RDAT2,
//	CFGR_NIH_RDAT3,
//	CFGR_NIH_STD,
//	CFGR_SHA_STR,
//	CFGR_DIG_GAIN2,
//	CFGR_RSTP_WIDTH,
//	CFGR_VCR_STR,
//	CFGR_VCR2_MD,
//	CFGR_VCR2_PHTCR,
//	CFGR_PHTH0_WIDTH,
//	CFGR_PHTH1_WIDTH,
//	CFGR_TEST_OPT,
//	CFGR_SSU_ON,
//	CFGR_CMUX_NUM,
//	CFGR_SSU_CR_I00,
//	CFGR_SSU_CR_I04,
//	CFGR_SSU_CR_I08,
//	CFGR_SSU_CR_I12,
//	CFGR_SSU_CR_I14,
//	CFGR_SSU_CR_E00,
//	CFGR_SSU_CR_E04,
//	CFGR_SSU_CR_E08,
//	CFGR_SSU_CR_E12,
//	CFGR_SSU_CR_E14,
//	CFGR_DATA_CR_I00,
//	CFGR_DATA_CR_I08,
//	CFGR_DATA_CR_I16,
//	CFGR_DATA_CR_I24,
//	CFGR_DATA_CR_I32,
//	CFGR_DATA_CR_I40,
//	CFGR_DATA_CR_E00,
//	CFGR_DATA_CR_E08,
//	CFGR_DATA_CR_E16,
//	CFGR_DATA_CR_E24,
//	CFGR_DATA_CR_E32,
//	CFGR_DATA_CR_E40,
//	CFGR_EDGE_CR_SEL,
//	CFGR_SSU_GC,
//	CFGR_CMUX_REMAP0,
//	CFGR_CMUX_REMAP1,
//	CFGR_CMUX_REMAP2,
//	CFGR_TSYNC_NUM_PEN,
//	CFGR_TSYNC_DMMY_PEN,
//	CFGR_CMUX_NUM_PEN,
//	CFGR_PEN_CTRL,
//	CFGR_HALF_COPY,
//	CFGR_PEN0_TSYNC0,
//	CFGR_PEN0_TSYNC1,
//	CFGR_PEN0_TSYNC2,
//	CFGR_PEN0_TSYNC3,
//	CFGR_PEN1_TSYNC0,
//	CFGR_PEN1_TSYNC1,
//	CFGR_PEN1_TSYNC2,
//	CFGR_PEN1_TSYNC3,
//	CFGR_PWM_NUM2,
//	CFGR_PWM_NUM3,
//	CFGR_PWM_NUM4,
//	CFGR_PWM_NUM5,
//	CFGR_PWM_NUM_NI,
//	CFGR_CMUX_NI1,
//	CFGR_CMUX_NI2,
//	CFGR_CMUX_NI3,
//	CFGR_CMUX_NI4,
//	CFGR_AFE_DUM,
//	CFGR_RSVD0,
//	CFGR_RSVD1,
//	CFGR_MD_IDLE,
//	CFGR_MAX
//} eROIC_ID;

typedef enum {
	ROIC_0 		= 0,
	ROIC_1 		= 1,
	ROIC_ALL 	= 2,
	SM_ROIC_0 	= 3,
	SM_ROIC_1 	= 4,
	SM_ROIC_ALL = 5,
	DEFAULT 	= 6
} eROICSelect_t;

#define SRIC_CFGR_SSU_CR_REG_NUM		(5)
typedef enum {
	CR_REG_MUX00 = 0,
	CR_REG_MUX04 = 1,
	CR_REG_MUX08 = 2,
	CR_REG_MUX12 = 3,
	CR_REG_MUX14 = 4,
	CR_REG_MUX_LIMIT = SRIC_CFGR_SSU_CR_REG_NUM,

} eROIC_CR_REG_t;

#define SRIC_NUM_MAX								(6)
typedef enum {
	SRIC_IDX_0 = 0,
	SRIC_IDX_1 = 1,
	SRIC_IDX_2 = 2,
	SRIC_IDX_3 = 3,
	SRIC_IDX_4 = 4,
	SRIC_IDX_5 = 5,
	CR_REG_LIMIT = SRIC_NUM_MAX,

} eSRIUC_INDEX_t;

#define R0_str_Adr				(0x300)
#define R1_str_Adr				(0x400)
#define SM_R0_str_Adr			(0x1300)
#define SM_R1_str_Adr			(0x1400)

#define R0(Address)				((Address) + R0_str_Adr)
#define R1(Address)				((Address) + R1_str_Adr)
#define SM_R0(Address)			((Address) + SM_R0_str_Adr)
#define SM_R1(Address)			((Address) + SM_R1_str_Adr)

/*
 * SRIC Register Offset value
 */

// Table �궗�슜
//#define PRODUCT_ID		0x00
#define SNSR_STR		0x02
#define MD_GENERAL		0x04
#define AIP_ADC			0x06
#define SSU_CTRL		0x08
#define TSYNC_NUM0		0x0A
#define TSYNC_NUM1		0x0C
#define TSYNC_DMMY		0x0E
#define PWM_NUM0		0x10
#define PWM_NUM1		0x12
#define CMUX_NORM		0x14
#define CHIP0_LEN		0x16
#define COL_NUM			0x18
#define OUTER			0x1A
#define DIG_GAIN0		0x1C
#define DIG_GAIN1		0x1E
#define NIH_MIN0		0x20
#define NIH_MAX0		0x22
#define NIH_MIN1		0x24
#define NIH_MAX1		0x26
#define NIH_MIN2		0x28
#define NIH_MAX2		0x2A
#define NIH_MIN3		0x2C
#define NIH_MAX3		0x2E
#define NIH_RDAT0		0x30
#define NIH_RDAT1		0x32
#define NIH_RDAT2		0x34
#define NIH_RDAT3		0x36
#define NIH_STD			0x38
#define SHA_STR			0x3A
#define DIG_GAIN2		0x3C
#define RSTP_WIDTH		0x3E
#define VCR_STR			0x40
#define VCR2_MD			0x42
#define VCR2_PHTCR		0x44
#define PHTH0_WIDTH		0x46
#define PHTH1_WIDTH		0x48
#define TEST_OPT		0x4A
#define SSU_ON			0x4C
#define CMUX_NUM		0x4E
#define SSU_CR_I00		0x50
#define SSU_CR_I04		0x52
#define SSU_CR_I08		0x54
#define SSU_CR_I12		0x56
#define SSU_CR_I14		0x58
#define SSU_CR_E00		0x5A
#define SSU_CR_E04		0x5C
#define SSU_CR_E08		0x5E
#define SSU_CR_E12		0x60
#define SSU_CR_E14		0x62
#define DATA_CR_I00		0x64
#define DATA_CR_I08		0x66
#define DATA_CR_I16		0x68
#define DATA_CR_I24		0x6A
#define DATA_CR_I32		0x6C
#define DATA_CR_I40		0x6E
#define DATA_CR_E00		0x70
#define DATA_CR_E08		0x72
#define DATA_CR_E16		0x74
#define DATA_CR_E24		0x76
#define DATA_CR_E32		0x78
#define DATA_CR_E40		0x7A
#define EDGE_CR_SEL		0x7C
#define SSU_GC			0x7E
#define CMUX_REMAP0		0x80
#define CMUX_REMAP1		0x82
#define CMUX_REMAP2		0x84
#define TSYNC_NUM_PEN	0x86
#define TSYNC_DMMY_PEN	0x88
#define CMUX_NUM_PEN	0x8A
#define PEN_CTRL		0x8C
#define HALF_COPY		0x8E
#define PEN0_TSYNC0		0x90
#define PEN0_TSYNC1		0x92
#define PEN0_TSYNC2		0x94
#define PEN0_TSYNC3		0x96
#define PEN1_TSYNC0		0x98
#define PEN1_TSYNC1		0x9A
#define PEN1_TSYNC2		0x9C
#define PEN1_TSYNC3		0x9E
#define PWM_NUM2		0xA0
#define PWM_NUM3		0xA2
#define PWM_NUM4		0xA4
#define PWM_NUM5		0xA6
#define PWM_NUM_NI		0xA8
#define CMUX_NI1		0xAA
#define CMUX_NI2		0xAC
#define CMUX_NI3		0xAE
#define CMUX_NI4		0xB0
#define AFE_DUM			0xB2
#define RSVD0			0xB4
#define RSVD1			0xB6
#define MD_IDLE			0xFE


extern void SRIC_Initialize(void);
extern void SW92400_Reset(eSENSING_MODE_t eSensingMode);
extern bool_t SRIC_Init(eSENSING_MODE_t eSensingMode);
extern void SRIC_Run(void);
extern bool_t SW92400_Check(uint32_t addr, uint16_t inputval, eROICSelect_t sel);
extern void SW92400_Set_CMUXOFF(bool_t bIsEnable);
extern bool_t SW92400_Set_FreqConfig(eSENSING_MODE_t eSensingMode);

#if (CUSTOMER == MODEL_LGD_SW92400)
extern void SRIC_Set_Register(uint32_t addr, uint16_t val, eROICSelect_t sel);
#else /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
extern void SRIC_Set_Register(uint32_t addr, uint16_t *WriteBuf, eROICSelect_t sel);
#endif /* (CUSTOMER == MODEL_LGD_SW92400) */

extern uint16_t SW92400_Get_Register(uint8_t ch, uint32_t addr);
extern void SW92400_Each_Set_Register(uint32_t addr, uint16_t * pval, eROICSelect_t sel);
extern void SW92400_SetActiveIdleOperationMode(eSENSING_MODE_t eSensingMode);

extern void SRIC_Set_OS(uint16_t regAIP_ADC, uint16_t regTEST_OPT);

#endif /* SRIC_H_ */
