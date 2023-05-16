/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : roic_ctrl_swl92407.h
 * created on : 5. 1. 2020
 * Author : bjlee
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

#ifndef _ROIC_CTRL_SWL92407_H_
#define _ROIC_CTRL_SWL92407_H_

typedef struct
{
	__IO	uint8_t		ADDR_CFGR_PRODUCT_ID;
	__IO	uint8_t		ADDR_CFGR_SNSR_STR;
	__IO	uint8_t		ADDR_CFGR_MD_GENERAL;
	__IO	uint8_t		ADDR_CFGR_AIP_ADC;
	__IO	uint8_t		ADDR_CFGR_SSU_CTRL;
	__IO	uint8_t		ADDR_CFGR_TSYNC_NUM0;
	__IO	uint8_t		ADDR_CFGR_TSYNC_NUM1;
	__IO	uint8_t		ADDR_CFGR_TSYNC_DMMY;
	__IO	uint8_t		ADDR_CFGR_PWM_NUM0;
	__IO	uint8_t		ADDR_CFGR_PWM_NUM1;
	__IO	uint8_t		ADDR_CFGR_CMUX_NORM;
	__IO	uint8_t		ADDR_CFGR_CHIP0_LEN;
	__IO	uint8_t		ADDR_CFGR_COL_NUM;
	__IO	uint8_t		ADDR_CFGR_SHA_STR;
	__IO	uint8_t		ADDR_CFGR_DIG_GAIN2;
	__IO	uint8_t		ADDR_CFGR_RSTP_WIDTH;
	__IO	uint8_t		ADDR_CFGR_VCR_STR;
	__IO	uint8_t		ADDR_CFGR_VCR2_MD;
	__IO	uint8_t		ADDR_CFGR_VCR2_PHTCR;
	__IO	uint8_t		ADDR_CFGR_PHTH0_WIDTH;
	__IO	uint8_t		ADDR_CFGR_PHTH1_WIDTH;
	__IO	uint8_t		ADDR_CFGR_TEST_OPT;
	__IO	uint8_t		ADDR_CFGR_SSU_ON;
	__IO	uint8_t		ADDR_CFGR_CMUX_NUM;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_I00;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_I04;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_I08;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_I12;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_I14;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_E00;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_E04;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_E08;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_E12;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_E14;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_PEN_I00;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_PEN_I04;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_PEN_I08;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_PEN_I12;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_PEN_I14;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_PEN_E00;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_PEN_E04;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_PEN_E08;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_PEN_E12;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_PEN_E14;
	__IO	uint8_t		ADDR_CFGR_SSU_INT_GC;
	__IO	uint8_t		ADDR_CFGR_EDGE_CR_SEL;
	__IO	uint8_t		ADDR_CFGR_SSU_PRE_GC;
	__IO	uint8_t		ADDR_CFGR_CMUX_REMAP0;
	__IO	uint8_t		ADDR_CFGR_CMUX_REMAP1;
	__IO	uint8_t		ADDR_CFGR_CMUX_REMAP2;
	__IO	uint8_t		ADDR_CFGR_TSYNC_NUM_PEN;
	__IO	uint8_t		ADDR_CFGR_TSYNC_DMMY_PEN;
	__IO	uint8_t		ADDR_CFGR_CMUX_NUM_PEN;
	__IO	uint8_t		ADDR_CFGR_PEN_CTRL;
	__IO	uint8_t		ADDR_CFGR_HALF_COPY;
	__IO	uint8_t		ADDR_CFGR_PEN0_TSYNC0;
	__IO	uint8_t		ADDR_CFGR_PEN0_TSYNC1;
	__IO	uint8_t		ADDR_CFGR_PEN0_TSYNC2;
	__IO	uint8_t		ADDR_CFGR_PEN_CTRL2;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_MN1_IE;
	__IO	uint8_t		ADDR_CFGR_SSU_CR_MN2_IE;
	__IO	uint8_t		ADDR_CFGR_PWM_NUM2;
	__IO	uint8_t		ADDR_CFGR_PWM_NUM3;
	__IO	uint8_t		ADDR_CFGR_PWM_NUM4;
	__IO	uint8_t		ADDR_CFGR_PWM_NUM5;
	__IO	uint8_t		ADDR_CFGR_PWM_NUM_NI;
	__IO	uint8_t		ADDR_CFGR_CMUX_NI1;
	__IO	uint8_t		ADDR_CFGR_CMUX_NI2;
	__IO	uint8_t		ADDR_CFGR_CMUX_NI3;
	__IO	uint8_t		ADDR_CFGR_CMUX_NI4;
	__IO	uint8_t		ADDR_CFGR_AFE_DUM;
	__IO	uint8_t		ADDR_CFGR_PSVB_PEN_TSYNC;
	__IO	uint8_t		ADDR_CFGR_PSVB_FGR_TSYNC;
	__IO	uint8_t		ADDR_CFGR_PEN_LHB_ABD;
	__IO	uint8_t		ADDR_CFGR_SSU_BCON1;
	__IO	uint8_t		ADDR_CFGR_SSU_BCON2;
	__IO	uint8_t		ADDR_CFGR_SSU_BCON3;
	__IO	uint8_t		ADDR_CFGR_SPIS_CFG;
	__IO	uint8_t		ADDR_CFGR_SSU_BCON4;
	__IO	uint8_t		ADDR_CFGR_ACLK_DIV2;
	__IO	uint8_t		ADDR_CFGR_ADIV2_TOG_PAT;
	__IO	uint8_t		ADDR_CFGR_PSVB_AFE;
	__IO	uint8_t		ADDR_CFGR_AIP_ENA;
	__IO	uint8_t		ADDR_CFGR_AIP_ENA2;
	__IO	uint8_t		ADDR_CFGR_PSVB_EV_TSYNC;
	__IO	uint8_t		ADDR_CFGR_PSVB_OD_TSYNC;
	__IO	uint8_t		ADDR_CFGR_AIP_ENA3;
	__IO	uint8_t		ADDR_CFGR_CMUX_MP1;
	__IO	uint8_t		ADDR_CFGR_CMUX_MP2;
	__IO	uint8_t		ADDR_CFGR_PWM_NUM6;
	__IO	uint8_t		ADDR_CFGR_PWM_NUM7;
	__IO	uint8_t		ADDR_CFGR_PWM_NUM8;
	__IO	uint8_t		ADDR_CFGR_MD_DIFF_CMUX;
	__IO	uint8_t		ADDR_CFGR_CMUX_MN1;
	__IO	uint8_t		ADDR_CFGR_CMUX_MN2;
	__IO	uint8_t		ADDR_CFGR_MD_IDLE;

} __PACKED tSW92407_RegAddrDef;

extern void SWL92407_Initialize(void);
extern void SWL92407_Reset(eSENSING_MODE_t eSensingMode);
extern bool_t SWL92407_RegisterInit(eSENSING_MODE_t eSensingMode);
extern void SWL92407_Run(uint8_t Enable);
#if USED_ADAPTIVE_LOCAL_SENSING
extern void SWL92407_SetRoicIndex(uint32_t ulIdx);
#endif /* USED_ADAPTIVE_LOCAL_SENSING */
extern void SWL92407_SetLocalIndex(uint32_t ulIdx);
extern void SWL92407_SetIdleOperationMode(void);
extern void SWL92407_SetActiveOperationMode(void);
extern void SWL92407_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode);


#endif /* _ROIC_CTRL_SW92407_H_ */
