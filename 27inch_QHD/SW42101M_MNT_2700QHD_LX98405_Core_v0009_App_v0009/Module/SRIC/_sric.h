/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _sric.h
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

#ifndef __SRIC_H_
#define __SRIC_H_


#include "_sric_param.h"

// LGD VBS SRIC SW92400 Register
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
} SRIC_TypeDef;

#endif /* __SRIC_H_ */
