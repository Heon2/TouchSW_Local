/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _sric_p.h
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

#ifndef __SRIC_P_H_
#define __SRIC_P_H_

#if (CUSTOMER == MODEL_LGD_SW92400)
typedef struct
{
	__IO uint16_t		CFGR_MD_IDLE;//CFGR_PRODUCT_ID;
	__IO uint16_t		CFGR_SNSR_STR;//CFGR_SNSR_STR;
	__IO uint16_t		CFGR_MD_GENERAL;//CFGR_MD_GENERAL;
	__IO uint16_t		CFGR_AIP_ADC;//CFGR_AIP_ADC;
	__IO uint16_t		CFGR_SSU_CTRL;//CFGR_SSU_CTRL;
	__IO uint16_t		CFGR_CH01_CR;//CFGR_TSYNC_NUM0;
	__IO uint16_t		CFGR_CH23_CR;//CFGR_TSYNC_NUM1;
	__IO uint16_t		CFGR_CH45_CR;//CFGR_TSYNC_DMMY;
	__IO uint16_t		CFGR_CH67_CR;//CFGR_PWM_NUM0;
	__IO uint16_t		CFGR_CH89_CR;//CFGR_PWM_NUM1;
	__IO uint16_t		CFGR_CH0_EDG_CR;//CFGR_CMUX_NORM;
	__IO uint16_t		CFGR_CH1_EDG_CR;//CFGR_CHIP0_LEN;
	__IO uint16_t		CFGR_CH2_EDG_CR;//CFGR_COL_NUM;
	__IO uint16_t		CFGR_CH3_EDG_CR;//CFGR_OUTER;
	__IO uint16_t		CFGR_CH4_EDG_CR;//CFGR_DIG_GAIN0;
	__IO uint16_t		CFGR_CH5_EDG_CR;//CFGR_DIG_GAIN1;
	__IO uint16_t		CFGR_CH6_EDG_CR;//CFGR_NIH_MIN0;
	__IO uint16_t		CFGR_CH7_EDG_CR;//CFGR_NIH_MAX0;
	__IO uint16_t		CFGR_CH8_EDG_CR;//CFGR_NIH_MIN1;
	__IO uint16_t		CFGR_CH9_EDG_CR;//CFGR_NIH_MAX1;
	__IO uint16_t		CFGR_TSYNC_NUM0;//CFGR_NIH_MIN2;
	__IO uint16_t		CFGR_TSYNC_NUM1;//CFGR_NIH_MAX2;
	__IO uint16_t		CFGR_TSYNC_DMMY;//CFGR_NIH_MIN3;
	__IO uint16_t		CFGR_PWM_NUM0;//CFGR_NIH_MAX3;
	__IO uint16_t		CFGR_PWM_NUM1;//CFGR_NIH_RDAT0;
	__IO uint16_t		CFGR_CMUX_NORM;//CFGR_NIH_RDAT1;
	__IO uint16_t		CFGR_CMUX_NOISE;//CFGR_NIH_RDAT2;
	__IO uint16_t		CFGR_COL_NUM;//CFGR_NIH_RDAT3;
	__IO uint16_t		CFGR_OUTER;//CFGR_NIH_STD;
	__IO uint16_t		CFGR_DIG_GAIN0;//CFGR_SHA_STR;
	__IO uint16_t		CFGR_DIG_GAIN1;//CFGR_DIG_GAIN2;
	__IO uint16_t		CFGR_NIH_MIN0;//CFGR_RSTP_WIDTH;
	__IO uint16_t		CFGR_NIH_MAX0;//CFGR_VCR_STR;
	__IO uint16_t		CFGR_NIH_MIN1;//CFGR_VCR2_MD;
	__IO uint16_t		CFGR_NIH_MAX1;//CFGR_VCR2_PHTCR;
	__IO uint16_t		CFGR_NIH_MIN2;//CFGR_PHTH0_WIDTH;
	__IO uint16_t		CFGR_NIH_MAX2;//CFGR_PHTH1_WIDTH;
	__IO uint16_t		CFGR_NIH_MIN3;//CFGR_TEST_OPT;
	__IO uint16_t		CFGR_NIH_MAX3;//CFGR_SSU_ON;
	__IO uint16_t		CFGR_NIH_RDAT0;//CFGR_CMUX_NUM;
	__IO uint16_t		CFGR_NIH_RDAT1;//CFGR_SSU_CR_I00;
	__IO uint16_t		CFGR_NIH_RDAT2;//CFGR_SSU_CR_I04;
	__IO uint16_t		CFGR_NIH_RDAT3;//CFGR_SSU_CR_I08;
	__IO uint16_t		CFGR_NIH_STD;//CFGR_SSU_CR_I12;
	__IO uint16_t		CFGR_SHA_STR;//CFGR_SSU_CR_I14;
	__IO uint16_t		CFGR_DIG_GAIN2;//CFGR_SSU_CR_E00;
	__IO uint16_t		CFGR_PHTH0_WIDTH;//CFGR_SSU_CR_E04;
	__IO uint16_t		CFGR_PHT_SEL;//CFGR_SSU_CR_E08;
	__IO uint16_t		CFGR_RSTP_WIDTH;//CFGR_SSU_CR_E12;
	__IO uint16_t		CFGR_VCR_STR;//CFGR_SSU_CR_E14;
	__IO uint16_t		CFGR_VCR_CTRL;//CFGR_DATA_CR_I00;
	__IO uint16_t		CFGR_VCR_MD2;//CFGR_DATA_CR_I08;
	__IO uint16_t		CFGR_CHIP0_LEN;//CFGR_DATA_CR_I16;
	__IO uint16_t		CFGR_TEST_OPT;//CFGR_DATA_CR_I24;
	__IO uint16_t		CFGR_DAC_IN;//CFGR_DATA_CR_I32;
	__IO uint16_t		CFGR_DAC_CNT;//CFGR_DATA_CR_I40;
	__IO uint16_t		CFGR_RSVD0;//CFGR_DATA_CR_E00;
	__IO uint16_t		CFGR_RSVD1;//CFGR_DATA_CR_E08;
	__IO uint16_t		CFGR_RSVD2;//CFGR_DATA_CR_E16;
	__IO uint16_t		CFGR_RSVD3;//CFGR_DATA_CR_E24;
} __PACKED tROIC_RegDef;
#else /* (CUSTOMER == MODEL_LGD_SW92400) */
typedef struct
{
	__IO uint16_t		SRIC_CFGR_00H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_02H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_04H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_06H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_08H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_0AH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_0CH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_0EH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_10H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_12H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_14H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_16H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_18H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_1AH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_1CH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_1EH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_20H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_22H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_24H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_26H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_28H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_2AH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_2CH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_2EH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_30H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_32H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_34H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_36H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_38H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_3AH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_3CH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_3EH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_40H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_42H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_44H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_46H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_48H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_4AH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_4CH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_4EH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_50H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_52H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_54H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_56H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_58H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_5AH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_5CH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_5EH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_60H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_62H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_64H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_66H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_68H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_6AH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_6CH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_6EH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_70H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_72H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_74H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_76H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_78H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_7AH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_7CH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_7EH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_80H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_82H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_84H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_86H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_88H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_8AH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_8CH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_8EH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_90H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_92H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_94H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_96H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_98H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_9AH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_9CH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_9EH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_A0H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_A2H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_A4H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_A6H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_A8H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_AAH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_ACH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_AEH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_B0H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_B2H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_B4H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_B6H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_B8H[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_BAH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_BCH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_FAH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_FCH[MSPI_NUM];
	__IO uint16_t		SRIC_CFGR_FEH[MSPI_NUM];
} __PACKED tROIC_RegDef;
#endif /* (CUSTOMER == MODEL_LGD_SW92400) */

#endif /* __SRIC_P_H_ */
