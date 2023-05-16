/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : roic_ctrl_sw97500.c
 * created on : 20. 2. 2019
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
#include "roic_ctrl_sw97500.h"
#include "param_def.h"


#if (USED_ROIC_DEF == ROIC_SW97500)
#define SRIC_REGISTER_RW_CHECK			(NO)

#if (USED_RUNTIME_LOCAL_TUNE_RAWDATA || USED_RAWDATA_TUNE_CALIBRATION)
#define DEF_ROIC_NUM					(8)
typedef union
{
	struct
	{
		__IO uint32_t cr1_r1g1: 5;
		__IO uint32_t cr1_r1g2: 5;
		__IO uint32_t cr1_r1g3: 5;
		__IO uint32_t cr1_r2g1: 5;
		__IO uint32_t cr1_r2g2: 5;
		__IO uint32_t cr1_r2g3: 5;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tSW97500_ROIC_CR_MUX_t;
extern tParamPreMainSet_t * s_ptParamPreMainSet;
tModuleSRICCommonConf_t * g_ptSRICConfig;
tSW97500_ROIC_CR_MUX_t * g_pR0_CR_MUX_Tune;
tSW97500_ROIC_CR_MUX_t * g_pR1_CR_MUX_Tune;
#endif /* (USED_RUNTIME_LOCAL_TUNE_RAWDATA || USED_RAWDATA_TUNE_CALIBRATION) */

const tModuleSRICCommonConf_t * s_pktmoduleSRICCommonConf = NULL;

#if (SRIC_REGISTER_RW_CHECK || USED_SRIC_REG_INIT_RETRY)
#if SRIC_REGISTER_RW_CHECK
bool_t bGlobal_Reg;
#endif /* SRIC_REGISTER_RW_CHECK */
uint32_t ulReadBuf[MSPI_NUM];

typedef enum
{
	REG_RW_CHECK_TYPE_ALL,
	REG_RW_CHECK_TYPE_LEFT,
	REG_RW_CHECK_TYPE_RIGHT,
	REG_RW_CHECK_TYPE_SINGLE_SM0_R0,
	REG_RW_CHECK_TYPE_SINGLE_SM0_R1,
	REG_RW_CHECK_TYPE_SINGLE_SM1_R0,
	REG_RW_CHECK_TYPE_SINGLE_SM1_R1,
} elRegRWCheckType_t;

static bool_t SW97500_Register_Check(uint32_t Addr, uint32_t ulValue, uint32_t * pValue, elRegRWCheckType_t eRWCheckType)
{
	bool_t bReg = YES;
	uint32_t ulRWCheckNum;
	uint32_t ulOptionOrderIndex[4];
	uint32_t ulMSPI_Idx, ulOption_Idx;

	switch(eRWCheckType)
	{
		case REG_RW_CHECK_TYPE_ALL:
		{
			ulRWCheckNum = 4;
			ulOptionOrderIndex[0] = 0;
			ulOptionOrderIndex[1] = 1;
			ulOptionOrderIndex[2] = 2;
			ulOptionOrderIndex[3] = 3;
			break;
		}
		case REG_RW_CHECK_TYPE_LEFT:
		{
			ulRWCheckNum = 2;
			ulOptionOrderIndex[0] = 0;
			ulOptionOrderIndex[1] = 2;
			break;
		}
		case REG_RW_CHECK_TYPE_RIGHT:
		{
			ulRWCheckNum = 2;
			ulOptionOrderIndex[0] = 1;
			ulOptionOrderIndex[1] = 3;
			break;
		}
		case REG_RW_CHECK_TYPE_SINGLE_SM0_R0:
		{
			ulRWCheckNum = 1;
			ulOptionOrderIndex[0] = 0;
			break;
		}
		case REG_RW_CHECK_TYPE_SINGLE_SM0_R1:
		{
			ulRWCheckNum = 1;
			ulOptionOrderIndex[0] = 1;
			break;
		}
		case REG_RW_CHECK_TYPE_SINGLE_SM1_R0:
		{
			ulRWCheckNum = 1;
			ulOptionOrderIndex[0] = 2;
			break;
		}
		case REG_RW_CHECK_TYPE_SINGLE_SM1_R1:
		{
			ulRWCheckNum = 1;
			ulOptionOrderIndex[0] = 3;
			break;
		}
	}
	for(ulOption_Idx = 0; ulOption_Idx < ulRWCheckNum; ulOption_Idx++)
	{
		MSPI_RegisterRead(Addr, &ulReadBuf[0], (eROIC_Read_Option_t)(MSPI_READ_SM0_R0 + ulOptionOrderIndex[ulOption_Idx]));
		for(ulMSPI_Idx = 0; ulMSPI_Idx < MSPI_NUM; ulMSPI_Idx++)
		{
			if(pValue == NULL)
			{
				if(ulReadBuf[ulMSPI_Idx] != ulValue)
				{
					bReg = NO;
//					_gT(_GPIO_TP_INTR);
				}
			}
			else
			{
				if(ulReadBuf[ulMSPI_Idx] != pValue[ulMSPI_Idx*2 + ulOption_Idx])
				{
					bReg = NO;
//					_gT(_GPIO_TP_INTR);
				}
			}
		}
	}

	return bReg;
}
#endif /* (SRIC_REGISTER_RW_CHECK || USED_SRIC_REG_INIT_RETRY) */

static bool_t SW97500_Reg_CRTuneSetting(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
	bool_t bReg = YES;
	MSPI_RegisterShareModeMultiWrite((0x100 | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX1_1[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x104 | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX1_2[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x108 | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX2[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x10C | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX3[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x110 | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX4[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x114 | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX5[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x118 | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX6[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x11C | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX7[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x120 | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX8[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x124 | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX9[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x128 | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX10_1[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x12C | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX10_2[0].ulBulk);

	MSPI_RegisterShareModeMultiWrite((0x100 | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX1_1[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x104 | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX1_2[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x108 | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX2[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x10C | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX3[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x110 | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX4[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x114 | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX5[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x118 | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX6[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x11C | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX7[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x120 | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX8[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x124 | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX9[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x128 | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX10_1[0].ulBulk);
	MSPI_RegisterShareModeMultiWrite((0x12C | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX10_2[0].ulBulk);

	if(eMode == ROIC_REG_SET_CHAGNE_CR_TUNE)
	{
		MSPI_RegisterShareModeMultiWrite((0x130 | MSPI_ROIC_LEFT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR_M1_LTUNE[0].ulBulk);
		MSPI_RegisterShareModeMultiWrite((0x130 | MSPI_ROIC_RIGHT), (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR_M1_LTUNE[0].ulBulk);

		MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CR_GTUNE.ulBulk);
		MSPI_RegisterWrite((0x138 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_TUNE_LOWER.ulBulk);
		MSPI_RegisterWrite((0x13C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_TUNE_UPPER.ulBulk);
		MSPI_RegisterWrite((0x140 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_TUNE_GROUP.ulBulk);
	}

	return bReg;
}

#if SRIC_REGISTER_RW_CHECK
static bool_t SW97500_Reg_CRTuneSetting_RWCheck(eSENSING_MODE_t eSensingMode)
{
	bool_t bReg = YES;
	bReg = SW97500_Register_Check(0x100, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX1_1[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x104, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX1_2[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x108, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX2[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x10C, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX3[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x110, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX4[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x114, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX5[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x118, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX6[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x11C, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX7[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x120, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX8[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x124, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX9[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x128, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX10_1[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x12C, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR1_MUX10_2[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x100, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX1_1[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x104, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX1_2[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x108, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX2[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x10C, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX3[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x110, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX4[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x114, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX5[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x118, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX6[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x11C, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX7[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x120, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX8[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x124, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX9[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x128, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX10_1[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x12C, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR1_MUX10_2[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x130, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R0_CR_M1_LTUNE[0].ulBulk, REG_RW_CHECK_TYPE_LEFT);
	if(bReg) bReg = SW97500_Register_Check(0x130, 0, (uint32_t *)&s_pktmoduleSRICCommonConf->tParam_R1_CR_M1_LTUNE[0].ulBulk, REG_RW_CHECK_TYPE_RIGHT);
	if(bReg) bReg = SW97500_Register_Check(0x134, s_pktmoduleSRICCommonConf->tParam_CR_GTUNE.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	if(bReg) bReg = SW97500_Register_Check(0x138, s_pktmoduleSRICCommonConf->tParam_CFGR_TUNE_LOWER.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	if(bReg) bReg = SW97500_Register_Check(0x13C, s_pktmoduleSRICCommonConf->tParam_CFGR_TUNE_UPPER.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	if(bReg) bReg = SW97500_Register_Check(0x140, s_pktmoduleSRICCommonConf->tParam_CFGR_TUNE_GROUP.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);

	return bReg;
}
#endif /* SRIC_REGISTER_RW_CHECK */

#if USED_NOISE_HOPPING_FREQ
static void SW97500_Reg_AFESetting(eSENSING_MODE_t eSensingMode)
{
	if (IS_ACTIVE_MODE_FRQ_MAIN(eSensingMode))
	{
		MSPI_RegisterWrite((0x030 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PWM_PRD.ulBulk);
		MSPI_RegisterWrite((0x034 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_SMPL_CTL.ulBulk);
		MSPI_RegisterWrite((0x038 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_RSTP_NUM1.ulBulk);
		MSPI_RegisterWrite((0x03C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTCR_NUM1.ulBulk);
		MSPI_RegisterWrite((0x040 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTCR_NUM2.ulBulk);
		MSPI_RegisterWrite((0x044 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_NUM1.ulBulk);
		MSPI_RegisterWrite((0x048 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_EN_NUM1.ulBulk);
		MSPI_RegisterWrite((0x04C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_EN_NUM2.ulBulk);

		MSPI_RegisterWrite((0x050 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH0_NUM1.ulBulk);
		MSPI_RegisterWrite((0x054 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH1_NUM1.ulBulk);
		MSPI_RegisterWrite((0x058 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH_NUM2.ulBulk);
		MSPI_RegisterWrite((0x05C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHT_CTL.ulBulk);
		MSPI_RegisterWrite((0x060 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHT_NUM1.ulBulk);
	}
	else if (IS_ACTIVE_MODE_FRQ_HOP1(eSensingMode))
	{
		tSRIC_CFGR_PWM_PRD_t tParam_CFGR_PWM_PRD;
		tParam_CFGR_PWM_PRD.tBit.pwm_prd1 = 48;
		tParam_CFGR_PWM_PRD.tBit.pwm_prd2 = 48;
		MSPI_RegisterWrite((0x030 | MSPI_BROADCAST), tParam_CFGR_PWM_PRD.ulBulk);

		tSRIC_CFGR_PHTCR_NUM1_t tParam_CFGR_PHTCR_NUM1;
		tParam_CFGR_PHTCR_NUM1.tBit.phtcr_num1_1 = 42;
		tParam_CFGR_PHTCR_NUM1.tBit.phtcr_num1_2 = 42;
		MSPI_RegisterWrite((0x03C | MSPI_BROADCAST), tParam_CFGR_PHTCR_NUM1.ulBulk);

		tSRIC_CFGR_PHTCR_NUM2_t tParam_CFGR_PHTCR_NUM2;
		tParam_CFGR_PHTCR_NUM2.tBit.phtcr_num2_1 = 32;
		tParam_CFGR_PHTCR_NUM2.tBit.phtcr_num2_2 = 32;
		MSPI_RegisterWrite((0x040 | MSPI_BROADCAST), tParam_CFGR_PHTCR_NUM2.ulBulk);

		tSRIC_CFGR_VCR_NUM1_t tParam_CFGR_VCR_NUM1;
		tParam_CFGR_VCR_NUM1.tBit.vcr_num1_1 = 38;
		tParam_CFGR_VCR_NUM1.tBit.vcr_num1_2 = 38;
		MSPI_RegisterWrite((0x044 | MSPI_BROADCAST), tParam_CFGR_VCR_NUM1.ulBulk);

		tSRIC_CFGR_VCR_EN_NUM1_t tParam_CFGR_VCR_EN_NUM1;
		tParam_CFGR_VCR_EN_NUM1.tBit.vcr_en_num1_1 = 46;
		tParam_CFGR_VCR_EN_NUM1.tBit.vcr_en_num1_2 = 46;
		MSPI_RegisterWrite((0x048 | MSPI_BROADCAST), tParam_CFGR_VCR_EN_NUM1.ulBulk);

		tSRIC_CFGR_PHTH0_NUM1_t tParam_CFGR_PHTH0_NUM1;
		tParam_CFGR_PHTH0_NUM1.tBit.phth0_num1_1 = 10;
		tParam_CFGR_PHTH0_NUM1.tBit.phth0_num1_2 = 10;
		MSPI_RegisterWrite((0x050 | MSPI_BROADCAST), tParam_CFGR_PHTH0_NUM1.ulBulk);

		tSRIC_CFGR_PHTH1_NUM1_t tParam_CFGR_PHTH1_NUM1;
		tParam_CFGR_PHTH1_NUM1.tBit.phth1_num1_1 = 10;
		tParam_CFGR_PHTH1_NUM1.tBit.phth1_num1_2 = 10;
		MSPI_RegisterWrite((0x054 | MSPI_BROADCAST), tParam_CFGR_PHTH1_NUM1.ulBulk);

		tSRIC_CFGR_PHTH_NUM2_t tParam_CFGR_PHTH_NUM2;
		tParam_CFGR_PHTH_NUM2.tBit.phth0_num2 = 1;
		tParam_CFGR_PHTH_NUM2.tBit.phth1_num2 = 30;
		MSPI_RegisterWrite((0x058 | MSPI_BROADCAST), tParam_CFGR_PHTH_NUM2.ulBulk);

		tSRIC_CFGR_PHT_NUM1_t tParam_CFGR_PHT_NUM1;
		tParam_CFGR_PHT_NUM1.tBit.pht_num1 = 20;
		tParam_CFGR_PHT_NUM1.tBit.pht_num2 = 12;
		MSPI_RegisterWrite((0x060 | MSPI_BROADCAST), tParam_CFGR_PHT_NUM1.ulBulk);
	}
}

//#if (SRIC_REGISTER_RW_CHECK || USED_SRIC_REG_INIT_RETRY)
//static bool_t SW97500_Reg_AFESetting_RWCheck(eSENSING_MODE_t eSensingMode)
//{
//	bool_t bReg = YES;
//	if (IS_ACTIVE_MODE_FRQ_MAIN(eSensingMode))
//	{
//		bReg = SW97500_Register_Check(0x030, s_pktmoduleSRICCommonConf->tParam_CFGR_PWM_PRD.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x034, s_pktmoduleSRICCommonConf->tParam_CFGR_SMPL_CTL.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x038, s_pktmoduleSRICCommonConf->tParam_CFGR_RSTP_NUM1.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x03C, s_pktmoduleSRICCommonConf->tParam_CFGR_PHTCR_NUM1.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x040, s_pktmoduleSRICCommonConf->tParam_CFGR_PHTCR_NUM2.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x044, s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_NUM1.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x048, s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_EN_NUM1.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x04C, s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_EN_NUM2.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x050, s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH0_NUM1.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x054, s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH1_NUM1.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x058, s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH_NUM2.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x05C, s_pktmoduleSRICCommonConf->tParam_CFGR_PHT_CTL.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//		if(bReg) bReg = SW97500_Register_Check(0x060, s_pktmoduleSRICCommonConf->tParam_CFGR_PHT_NUM1.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
//	}
//
//	return bReg;
//}
//#endif /* (SRIC_REGISTER_RW_CHECK || USED_SRIC_REG_INIT_RETRY) */
#endif /* USED_NOISE_HOPPING_FREQ */

void SW97500_Initialize(void)
{
	s_pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
}

void SW97500_Reset(eSENSING_MODE_t eSensingMode)
{
	GPIO_Init(_GPIO_RSTN_SRIC,GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);

	delay_usec(100);

#if !USED_OPERATION_STAND_ALONE
	if(!IS_S3_MODE(eSensingMode))
	{
		while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 1);
		while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 0);
	}
	delay_usec(10);
#endif /* !USED_OPERATION_STAND_ALONE */
	GPIO_Set_DATA(_GPIO_RSTN_SRIC, GPIO_DATA_LOW);
	delay_usec(10);
	GPIO_Set_DATA(_GPIO_RSTN_SRIC, GPIO_DATA_HIGH);
	delay_usec(100);
}


tSRIC_CFGR_PRODUCT_ID_t tTestProductROICBuf[MSPI_NUM] = {0,};
bool_t SW97500_RegisterInit(eSENSING_MODE_t eSensingMode)
{
#if USED_SRIC_REG_INIT_RETRY
//	uint32_t ulMSPI_Idx;
	tSRIC_SPIS_CFG_t tSRIC_SPIS_CFG;
	MSPI_RegisterRead((uint32_t)(0x0000), (uint32_t *)&tTestProductROICBuf[0], MSPI_READ_SM0_R0);

	tSRIC_SPIS_CFG.ulBulk = s_pktmoduleSRICCommonConf->tParam_SPIS_CFG.ulBulk;
	tSRIC_SPIS_CFG.tBit.spis_irq_en = 0;
	MSPI_RegisterWrite((0x004 | MSPI_BROADCAST), tSRIC_SPIS_CFG.ulBulk);
	MSPI_RegisterWrite((0x004 | MSPI_ROIC_RIGHT | MSPI_NORMALMODE), s_pktmoduleSRICCommonConf->tParam_SPIS_CFG.ulBulk);

//	{
//		MSPI_RegisterRead(0x004, &ulReadBuf[0], MSPI_READ_SM0_R1); // (0x004 | MSPI_ROIC_RIGHT | MSPI_NORMALMODE)
//		for(ulMSPI_Idx = 0; ulMSPI_Idx < MSPI_NUM; ulMSPI_Idx++)
//		{
//			if(ulReadBuf[ulMSPI_Idx] != s_pktmoduleSRICCommonConf->tParam_SPIS_CFG.ulBulk)
//			{
//				return NO;
//			}
//		}
//
//		MSPI_RegisterRead(0x004, &ulReadBuf[0], MSPI_READ_SM1_R0);
//		for(ulMSPI_Idx = 0; ulMSPI_Idx < MSPI_NUM; ulMSPI_Idx++)
//		{
//			if(ulReadBuf[ulMSPI_Idx] != 0x00)
//			{
//				return NO;
//			}
//		}
//
//		MSPI_RegisterRead(0x004, &ulReadBuf[0], MSPI_READ_SM1_R1);
//		for(ulMSPI_Idx = 0; ulMSPI_Idx < MSPI_NUM; ulMSPI_Idx++)
//		{
//			if(ulReadBuf[ulMSPI_Idx] != 0x00)
//			{
//				return NO;
//			}
//		}
//	}

		MSPI_RegisterWrite((0x008 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_SPIS_ERROR_CLR.ulBulk);

		MSPI_RegisterWrite((0x01C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_CH_EN.ulBulk);
		if(SW97500_Register_Check(0x01C, s_pktmoduleSRICCommonConf->tParam_CFGR_CH_EN.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL) == NO)
		{
			return NO;
		}

		MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk);
		if(SW97500_Register_Check(0x020, s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL) == NO)
		{
			return NO;
		}

		MSPI_RegisterWrite((0x024 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_DIC_CFG.ulBulk);
		if(SW97500_Register_Check(0x024, s_pktmoduleSRICCommonConf->tParam_CFGR_DIC_CFG.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL) == NO)
		{
			return NO;
		}

	#if USED_NOISE_HOPPING_FREQ
		SW97500_Reg_AFESetting(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
//		if(SW97500_Reg_AFESetting_RWCheck(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE) == NO)
//		{
//			return NO;
//		}
	#else /* USED_NOISE_HOPPING_FREQ */
			MSPI_RegisterWrite((0x030 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PWM_PRD.ulBulk);
			MSPI_RegisterWrite((0x034 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_SMPL_CTL.ulBulk);
			MSPI_RegisterWrite((0x038 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_RSTP_NUM1.ulBulk);
			MSPI_RegisterWrite((0x03C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTCR_NUM1.ulBulk);
			MSPI_RegisterWrite((0x040 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTCR_NUM2.ulBulk);
			MSPI_RegisterWrite((0x044 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_NUM1.ulBulk);
			MSPI_RegisterWrite((0x048 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_EN_NUM1.ulBulk);
			MSPI_RegisterWrite((0x04C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_EN_NUM2.ulBulk);
			MSPI_RegisterWrite((0x050 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH0_NUM1.ulBulk);
			MSPI_RegisterWrite((0x054 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH1_NUM1.ulBulk);
			MSPI_RegisterWrite((0x058 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH_NUM2.ulBulk);
			MSPI_RegisterWrite((0x05C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHT_CTL.ulBulk);
			MSPI_RegisterWrite((0x060 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHT_NUM1.ulBulk);
	#endif /* USED_NOISE_HOPPING_FREQ */

		// PWM
		MSPI_RegisterWrite((0x028 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PWM_CTL.ulBulk);
		if(SW97500_Register_Check(0x028, s_pktmoduleSRICCommonConf->tParam_CFGR_PWM_CTL.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL) == NO)
		{
			return NO;
		}

		MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk);
		if(SW97500_Register_Check(0x020, s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL) == NO)
		{
			return NO;
		}

		MSPI_RegisterWrite((0x064 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_ADC_CTRL.ulBulk);
//		if(SW97500_Register_Check(0x064, s_pktmoduleSRICCommonConf->tParam_CFGR_ADC_CTRL.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL) == NO)
//		{
//			return NO;
//		}

		// Pad Off
		MSPI_RegisterWrite((0x06C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_TG_STUCK.ulBulk);

		MSPI_RegisterWrite((0x14C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_SSU_PW_CTRL.ulBulk);
//		if(SW97500_Register_Check(0x14C, s_pktmoduleSRICCommonConf->tParam_CFGR_SSU_PW_CTRL.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL) == NO)
//		{
//			return NO;
//		}

		MSPI_RegisterWrite((0x078 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_CFG_00.ulBulk);
//		if(SW97500_Register_Check(0x078, s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_CFG_00.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL) == NO)
//		{
//			return NO;
//		}

		MSPI_RegisterWrite((0x07C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_CFG_01.ulBulk);
//		if(SW97500_Register_Check(0x07C, s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_CFG_01.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL) == NO)
//		{
//			return NO;
//		}

		MSPI_RegisterWrite((0x144 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_SENSE_CTRL.ulBulk);

		SW97500_Reg_CRTuneSetting(ROIC_REG_SET_CHAGNE_CR_TUNE);

	return YES;

#else /* USED_SRIC_REG_INIT_RETRY */
	//	bool_t bReg = YES;
	#if SRIC_REGISTER_RW_CHECK
		uint32_t ulMSPI_Idx;
		bGlobal_Reg = YES;
	#endif
		tSRIC_SPIS_CFG_t tSRIC_SPIS_CFG;
		MSPI_RegisterRead((uint32_t)(0x0000), (uint32_t *)&tTestProductROICBuf[0], MSPI_READ_SM0_R0);

		tSRIC_SPIS_CFG.ulBulk = s_pktmoduleSRICCommonConf->tParam_SPIS_CFG.ulBulk;
		tSRIC_SPIS_CFG.tBit.spis_irq_en = 0;
		MSPI_RegisterWrite((0x004 | MSPI_BROADCAST), tSRIC_SPIS_CFG.ulBulk);
		MSPI_RegisterWrite((0x004 | MSPI_ROIC_RIGHT | MSPI_NORMALMODE), s_pktmoduleSRICCommonConf->tParam_SPIS_CFG.ulBulk);
	#if SRIC_REGISTER_RW_CHECK
		if(bGlobal_Reg)
		{
			MSPI_RegisterRead(0x004, &ulReadBuf[0], MSPI_READ_SM0_R0);
			for(ulMSPI_Idx = 0; ulMSPI_Idx < MSPI_NUM; ulMSPI_Idx++)
			{
				if(ulReadBuf[ulMSPI_Idx] != 0x00)
				{
					bGlobal_Reg = FALSE;
				}
			}
		}

		if(bGlobal_Reg)
		{
			MSPI_RegisterRead(0x004, &ulReadBuf[0], MSPI_READ_SM0_R1); // (0x004 | MSPI_ROIC_RIGHT | MSPI_NORMALMODE)
			for(ulMSPI_Idx = 0; ulMSPI_Idx < MSPI_NUM; ulMSPI_Idx++)
			{
				if(ulReadBuf[ulMSPI_Idx] != s_pktmoduleSRICCommonConf->tParam_SPIS_CFG.ulBulk)
				{
					bGlobal_Reg = FALSE;
				}
			}
		}

		if(bGlobal_Reg)
		{
			MSPI_RegisterRead(0x004, &ulReadBuf[0], MSPI_READ_SM1_R0);
			for(ulMSPI_Idx = 0; ulMSPI_Idx < MSPI_NUM; ulMSPI_Idx++)
			{
				if(ulReadBuf[ulMSPI_Idx] != 0x00)
				{
					bGlobal_Reg = FALSE;
				}
			}
		}

		if(bGlobal_Reg)
		{
			MSPI_RegisterRead(0x004, &ulReadBuf[0], MSPI_READ_SM1_R1);
			for(ulMSPI_Idx = 0; ulMSPI_Idx < MSPI_NUM; ulMSPI_Idx++)
			{
				if(ulReadBuf[ulMSPI_Idx] != 0x00)
				{
					bGlobal_Reg = FALSE;
				}
			}
		}
	#endif /* SRIC_REGISTER_RW_CHECK */

	//	tSRIC_SPIS_ERROR_CLR.tBit.pwm_fault_clr = 1;
	//	tSRIC_SPIS_ERROR_CLR.tBit.spi_chksum_clr = 1;
	//	tSRIC_SPIS_ERROR_CLR.tBit.tsync_fault_clr = 1;
	//	MSPI_RegisterWrite((0x008 | MSPI_BROADCAST), tSRIC_SPIS_ERROR_CLR.ulBulk);
		MSPI_RegisterWrite((0x008 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_SPIS_ERROR_CLR.ulBulk);

		MSPI_RegisterWrite((0x01C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_CH_EN.ulBulk);
	#if SRIC_REGISTER_RW_CHECK
		if(bGlobal_Reg) bGlobal_Reg = SW97500_Register_Check(0x01C, s_pktmoduleSRICCommonConf->tParam_CFGR_CH_EN.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	#endif /* SRIC_REGISTER_RW_CHECK */

		MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk);
	#if SRIC_REGISTER_RW_CHECK
		if(bGlobal_Reg) bGlobal_Reg = SW97500_Register_Check(0x020, s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	#endif /* SRIC_REGISTER_RW_CHECK */

		MSPI_RegisterWrite((0x024 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_DIC_CFG.ulBulk);
	#if SRIC_REGISTER_RW_CHECK
		if(bGlobal_Reg) bGlobal_Reg = SW97500_Register_Check(0x024, s_pktmoduleSRICCommonConf->tParam_CFGR_DIC_CFG.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	#endif /* SRIC_REGISTER_RW_CHECK */

	#if USED_NOISE_HOPPING_FREQ
		SW97500_Reg_AFESetting(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
	#if SRIC_REGISTER_RW_CHECK
		if(bGlobal_Reg) bGlobal_Reg = SW97500_Reg_AFESetting_RWCheck(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
	#endif /* SRIC_REGISTER_RW_CHECK */
	#else /* USED_NOISE_HOPPING_FREQ */
			MSPI_RegisterWrite((0x030 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PWM_PRD.ulBulk);
		#if SRIC_REGISTER_RW_CHECK
			SW97500_Register_Check(0x030, s_pktmoduleSRICCommonConf->tParam_CFGR_PWM_PRD.ulBulk);
			delay_msec(1);
		#endif /* SRIC_REGISTER_RW_CHECK */

			MSPI_RegisterWrite((0x034 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_SMPL_CTL.ulBulk);

			MSPI_RegisterWrite((0x038 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_RSTP_NUM1.ulBulk);
		#if SRIC_REGISTER_RW_CHECK
			SW97500_Register_Check(0x038, s_pktmoduleSRICCommonConf->tParam_CFGR_RSTP_NUM1.ulBulk);
			delay_msec(1);
		#endif /* SRIC_REGISTER_RW_CHECK */

			MSPI_RegisterWrite((0x03C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTCR_NUM1.ulBulk);
		#if SRIC_REGISTER_RW_CHECK
			SW97500_Register_Check(0x03C, s_pktmoduleSRICCommonConf->tParam_CFGR_PHTCR_NUM1.ulBulk);
			delay_msec(1);
		#endif /* SRIC_REGISTER_RW_CHECK */

			MSPI_RegisterWrite((0x040 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTCR_NUM2.ulBulk);
		#if SRIC_REGISTER_RW_CHECK
			SW97500_Register_Check(0x040, s_pktmoduleSRICCommonConf->tParam_CFGR_PHTCR_NUM2.ulBulk);
			delay_msec(1);
		#endif /* SRIC_REGISTER_RW_CHECK */

			MSPI_RegisterWrite((0x044 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_NUM1.ulBulk);
		#if SRIC_REGISTER_RW_CHECK
			SW97500_Register_Check(0x044, s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_NUM1.ulBulk);
			delay_msec(1);
		#endif /* SRIC_REGISTER_RW_CHECK */

			MSPI_RegisterWrite((0x048 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_EN_NUM1.ulBulk);
		#if SRIC_REGISTER_RW_CHECK
			SW97500_Register_Check(0x048, s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_EN_NUM1.ulBulk);
			delay_msec(1);
		#endif /* SRIC_REGISTER_RW_CHECK */

			MSPI_RegisterWrite((0x04C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_EN_NUM2.ulBulk);
		#if SRIC_REGISTER_RW_CHECK
			SW97500_Register_Check(0x04C, s_pktmoduleSRICCommonConf->tParam_CFGR_VCR_EN_NUM2.ulBulk);
			delay_msec(1);
		#endif /* SRIC_REGISTER_RW_CHECK */

			MSPI_RegisterWrite((0x050 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH0_NUM1.ulBulk);
		#if SRIC_REGISTER_RW_CHECK
			SW97500_Register_Check(0x050, s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH0_NUM1.ulBulk);
			delay_msec(1);
		#endif /* SRIC_REGISTER_RW_CHECK */

			MSPI_RegisterWrite((0x054 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH1_NUM1.ulBulk);
		#if SRIC_REGISTER_RW_CHECK
			SW97500_Register_Check(0x054, s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH1_NUM1.ulBulk);
			delay_msec(1);
		#endif /* SRIC_REGISTER_RW_CHECK */


			MSPI_RegisterWrite((0x058 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHTH_NUM2.ulBulk);

			MSPI_RegisterWrite((0x05C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHT_CTL.ulBulk);
		#if SRIC_REGISTER_RW_CHECK
			SW97500_Register_Check(0x05C, s_pktmoduleSRICCommonConf->tParam_CFGR_PHT_CTL.ulBulk);
			delay_msec(1);
		#endif /* SRIC_REGISTER_RW_CHECK */

			MSPI_RegisterWrite((0x060 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PHT_NUM1.ulBulk);
		#if SRIC_REGISTER_RW_CHECK
			SW97500_Register_Check(0x060, s_pktmoduleSRICCommonConf->tParam_CFGR_PHT_NUM1.ulBulk);
			delay_msec(1);
		#endif /* SRIC_REGISTER_RW_CHECK */
	#endif /* USED_NOISE_HOPPING_FREQ */

		// PWM
		MSPI_RegisterWrite((0x028 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_PWM_CTL.ulBulk);

	#if SRIC_REGISTER_RW_CHECK
		if(bGlobal_Reg) bGlobal_Reg = SW97500_Register_Check(0x028, s_pktmoduleSRICCommonConf->tParam_CFGR_PWM_CTL.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	#endif /* SRIC_REGISTER_RW_CHECK */

		MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk);
	#if SRIC_REGISTER_RW_CHECK
		if(bGlobal_Reg) bGlobal_Reg = SW97500_Register_Check(0x020, s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	#endif /* SRIC_REGISTER_RW_CHECK */

		MSPI_RegisterWrite((0x064 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_ADC_CTRL.ulBulk);
	#if SRIC_REGISTER_RW_CHECK
		if(bGlobal_Reg) bGlobal_Reg = SW97500_Register_Check(0x064, s_pktmoduleSRICCommonConf->tParam_CFGR_ADC_CTRL.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	#endif /* SRIC_REGISTER_RW_CHECK */

		// Pad Off
		MSPI_RegisterWrite((0x06C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_TG_STUCK.ulBulk);

		MSPI_RegisterWrite((0x14C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_SSU_PW_CTRL.ulBulk);
	#if SRIC_REGISTER_RW_CHECK
		if(bGlobal_Reg) bGlobal_Reg = SW97500_Register_Check(0x14C, s_pktmoduleSRICCommonConf->tParam_CFGR_SSU_PW_CTRL.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	#endif /* SRIC_REGISTER_RW_CHECK */

		MSPI_RegisterWrite((0x078 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_CFG_00.ulBulk);
	#if SRIC_REGISTER_RW_CHECK
		if(bGlobal_Reg) bGlobal_Reg = SW97500_Register_Check(0x078, s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_CFG_00.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	#endif /* SRIC_REGISTER_RW_CHECK */

		MSPI_RegisterWrite((0x07C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_CFG_01.ulBulk);
	#if SRIC_REGISTER_RW_CHECK
		if(bGlobal_Reg) bGlobal_Reg = SW97500_Register_Check(0x07C, s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_CFG_01.ulBulk, NULL, REG_RW_CHECK_TYPE_ALL);
	#endif /* SRIC_REGISTER_RW_CHECK */

		MSPI_RegisterWrite((0x144 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_SENSE_CTRL.ulBulk);

		SW97500_Reg_CRTuneSetting(ROIC_REG_SET_CHAGNE_CR_TUNE);

	#if SRIC_REGISTER_RW_CHECK
		return bGlobal_Reg;
	#else
		return YES;
	#endif
#endif /* USED_SRIC_REG_INIT_RETRY */
}

void SW97500_Run(uint8_t Enable)
{
	tSRIC_CFGR_TC_START_t tSRIC_CFGR_TC_START;
	tSRIC_CFGR_TC_START.ulBulk = 0;
	tSRIC_CFGR_TC_START.tBit.tc_start = Enable;
	tSRIC_CFGR_TC_START.tBit.scan_cont = Enable;
	MSPI_RegisterWrite((0x014 | MSPI_BROADCAST), tSRIC_CFGR_TC_START.ulBulk);
//	SW97500_Register_Check(0x014, tSRIC_CFGR_TC_START.ulBulk);
}

bool_t SW97500_SetS3OperationMode(void)
{
	bool_t bReg = YES;
	tSRIC_CFGR_DIC_CFG_t tSRIC_CFGR_DIC_CFG;
	uint32_t ulBuf[10];

	tSRIC_CFGR_MUX_EN_t tSRIC_CFGR_MUX_EN;
#if (USED_IDLE_NI_SENSING_MUX_NUM == 1)
	tSRIC_CFGR_MUX_EN.tBit.mux_bit_en = 0x3FF;
	tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 0;
	tSRIC_CFGR_MUX_EN.tBit.mux_num_tot = 0;
	tSRIC_CFGR_MUX_EN.tBit.mux_num_tsync = 0;
	tSRIC_CFGR_MUX_EN.tBit.m1_mux_en = 0;
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 2)
	tSRIC_CFGR_MUX_EN.tBit.mux_bit_en = 0x7FF;
	tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 0;
	tSRIC_CFGR_MUX_EN.tBit.mux_num_tot = 1;
	tSRIC_CFGR_MUX_EN.tBit.mux_num_tsync = 1;
	tSRIC_CFGR_MUX_EN.tBit.m1_mux_en = 1;
#endif /* (USED_IDLE_NI_SENSING_MUX_NUM == 1) */
	// IDLE SRIC Setting
	MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);

	tSRIC_CFGR_DIC_CFG.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_DIC_CFG.ulBulk;
	tSRIC_CFGR_DIC_CFG.tBit.sd_off = 1;
	tSRIC_CFGR_DIC_CFG.tBit.stuck_abd = 1;
	tSRIC_CFGR_DIC_CFG.tBit.cfgr_abd = 1;
	MSPI_RegisterWrite((0x024 | MSPI_BROADCAST), tSRIC_CFGR_DIC_CFG.ulBulk);
	MSPI_RegisterRead(0x024, &ulBuf[0], MSPI_READ_SM0_R0);

	tSRIC_CFGR_PWM_CTL_t SRIC_CFGR_PWM_CTL;
	SRIC_CFGR_PWM_CTL.tBit.pwm_num = PARAMSET_ROIC_CFGR_PWM_CTL_Idle_pwm_num;
	SRIC_CFGR_PWM_CTL.tBit.pwm_act_num = PARAMSET_ROIC_CFGR_PWM_CTL_Idle_pwm_act_num;
	SRIC_CFGR_PWM_CTL.tBit.pwm_smpl_num = PARAMSET_ROIC_CFGR_PWM_CTL_Idle_pwm_act_num;
	SRIC_CFGR_PWM_CTL.tBit.pwm_dum_num = PARAMSET_ROIC_CFGR_PWM_CTL_pwm_dum_num;
	MSPI_RegisterWrite((0x028 | MSPI_BROADCAST), SRIC_CFGR_PWM_CTL.ulBulk);

	// IDLE Mux Order
	tSRIC_CFGR_MUX_CFG_00_t tSRIC_CFGR_MUX_CFG_00;
#if (USED_IDLE_NI_SENSING_MUX_NUM == 1)
	tSRIC_CFGR_MUX_CFG_00.tBit.mux_00 = 0x0B;
	tSRIC_CFGR_MUX_CFG_00.tBit.mux_01 = 0x00;
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 2)
	tSRIC_CFGR_MUX_CFG_00.tBit.mux_00 = 0x0B;
	tSRIC_CFGR_MUX_CFG_00.tBit.mux_01 = 0x0C;
#endif /* (USED_IDLE_NI_SENSING_MUX_NUM == 1) */
	MSPI_RegisterWrite((0x078 | MSPI_BROADCAST), tSRIC_CFGR_MUX_CFG_00.ulBulk);

	// IDLE Gain
	tSRIC_CFGR_SENSE_CTRL_t tSRIC_CFGR_SENSE_CTRL;
#if (USED_IDLE_NI_SENSING_MUX_NUM == 1)
	tSRIC_CFGR_SENSE_CTRL.tBit.adc_bcon = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.adc_stc_insel = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_ref = 2;
	tSRIC_CFGR_SENSE_CTRL.tBit.sha_ref = 2;
	tSRIC_CFGR_SENSE_CTRL.tBit.lv_ssu_bcon = CFGR_SENSE_CTRL_lv_ssu_bcon;
	tSRIC_CFGR_SENSE_CTRL.tBit.lv_ssu_bcons = CFGR_SENSE_CTRL_lv_ssu_bcons;
	tSRIC_CFGR_SENSE_CTRL.tBit.hv_ssu_bcon = CFGR_SENSE_CTRL_hv_ssu_bcon;
	tSRIC_CFGR_SENSE_CTRL.tBit.integ_half = CFGR_SENSE_CTRL_integ_half;
	tSRIC_CFGR_SENSE_CTRL.tBit.pre_gc = CFGR_SENSE_CTRL_pre_gc;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_gc = 5;
	tSRIC_CFGR_SENSE_CTRL.tBit.powsel = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.pre_bs_lp = CFGR_SENSE_CTRL_pre_bs_lp;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_bs_lp = CFGR_SENSE_CTRL_int_bs_lp;
	tSRIC_CFGR_SENSE_CTRL.tBit.sha_bs_lp = CFGR_SENSE_CTRL_sha_bs_lp;
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 2)
	tSRIC_CFGR_SENSE_CTRL.tBit.adc_bcon = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.adc_stc_insel = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_ref = 2;
	tSRIC_CFGR_SENSE_CTRL.tBit.sha_ref = 2;
	tSRIC_CFGR_SENSE_CTRL.tBit.lv_ssu_bcon = CFGR_SENSE_CTRL_lv_ssu_bcon;
	tSRIC_CFGR_SENSE_CTRL.tBit.lv_ssu_bcons = CFGR_SENSE_CTRL_lv_ssu_bcons;
	tSRIC_CFGR_SENSE_CTRL.tBit.hv_ssu_bcon = 2;//CFGR_SENSE_CTRL_hv_ssu_bcon;
	tSRIC_CFGR_SENSE_CTRL.tBit.integ_half = CFGR_SENSE_CTRL_integ_half;
	tSRIC_CFGR_SENSE_CTRL.tBit.pre_gc = CFGR_SENSE_CTRL_pre_gc;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_gc = 5;
	tSRIC_CFGR_SENSE_CTRL.tBit.powsel = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.pre_bs_lp = 1;//CFGR_SENSE_CTRL_pre_bs_lp;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_bs_lp = 1;//CFGR_SENSE_CTRL_int_bs_lp;
	tSRIC_CFGR_SENSE_CTRL.tBit.sha_bs_lp = 1;//CFGR_SENSE_CTRL_sha_bs_lp;
#endif /* (USED_IDLE_NI_SENSING_MUX_NUM == 1) */
	MSPI_RegisterWrite((0x144 | MSPI_BROADCAST), tSRIC_CFGR_SENSE_CTRL.ulBulk);

	// IDLE GTUNE
	tSRIC_CR_GTUNE_t tSRIC_CR_GTUNE;
	// IDLE TUNE GROUP
	tSRIC_CFGR_TUNE_GROUP_t tSRIC_CFGR_TUNE_GROUP;
	tSRIC_CR_M1_LTUNE_t tSRIC_CR_M1_LTUNE;
#if (USED_IDLE_NI_SENSING_MUX_NUM == 1)
	tSRIC_CR_GTUNE.tBit.cr_gtune = 5;

	tSRIC_CFGR_TUNE_GROUP.tBit.cr_rg2_sel = 2;
	tSRIC_CFGR_TUNE_GROUP.tBit.cr_rg3_sel = 28;
	tSRIC_CFGR_TUNE_GROUP.tBit.cr_m1_g2_sel = 14;
	tSRIC_CFGR_TUNE_GROUP.tBit.cr_m1_g3_sel = 16;

	tSRIC_CR_M1_LTUNE.tBit.cr_m1o_rg1 = 2;//20;
	tSRIC_CR_M1_LTUNE.tBit.cr_m1o_rg2 = 2;//20;
	tSRIC_CR_M1_LTUNE.tBit.cr_m1o_rg3 = 2;//20;
	tSRIC_CR_M1_LTUNE.tBit.cr_m1e_rg1 = 2;//28;
	tSRIC_CR_M1_LTUNE.tBit.cr_m1e_rg2 = 2;//28;
	tSRIC_CR_M1_LTUNE.tBit.cr_m1e_rg3 = 2;//28;
#elif (USED_IDLE_NI_SENSING_MUX_NUM == 2)
	tSRIC_CR_GTUNE.tBit.cr_gtune = 2;
#endif /* (USED_IDLE_NI_SENSING_MUX_NUM == 1) */
	MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), tSRIC_CR_GTUNE.ulBulk);

	return bReg;
}

void SW97500_SetIdleOperationMode(void)
{
	// IDLE SRIC Setting
	tSRIC_CFGR_MUX_EN_t tSRIC_CFGR_MUX_EN;
	tSRIC_CFGR_MUX_EN.tBit.mux_bit_en = 0x7FF;
	tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 0;
	tSRIC_CFGR_MUX_EN.tBit.mux_num_tot = 1;
	tSRIC_CFGR_MUX_EN.tBit.mux_num_tsync = 1;
	tSRIC_CFGR_MUX_EN.tBit.m1_mux_en = 1;
	MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);
	
	// IDLE CR TUNE
	tSRIC_CFGR_MUX_CFG_00_t tSRIC_CFGR_MUX_CFG_00;
	tSRIC_CFGR_MUX_CFG_00.tBit.mux_00 = 0x0B;
	tSRIC_CFGR_MUX_CFG_00.tBit.mux_01 = 0x0C;
	MSPI_RegisterWrite((0x078 | MSPI_BROADCAST), tSRIC_CFGR_MUX_CFG_00.ulBulk);

	// IDLE Gain
	tSRIC_CFGR_SENSE_CTRL_t tSRIC_CFGR_SENSE_CTRL;
	tSRIC_CFGR_SENSE_CTRL.tBit.adc_bcon = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.adc_stc_insel = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_ref = 2;
	tSRIC_CFGR_SENSE_CTRL.tBit.sha_ref = 2;
	tSRIC_CFGR_SENSE_CTRL.tBit.lv_ssu_bcon = CFGR_SENSE_CTRL_lv_ssu_bcon;
	tSRIC_CFGR_SENSE_CTRL.tBit.lv_ssu_bcons = CFGR_SENSE_CTRL_lv_ssu_bcons;
	tSRIC_CFGR_SENSE_CTRL.tBit.hv_ssu_bcon = CFGR_SENSE_CTRL_hv_ssu_bcon;
	tSRIC_CFGR_SENSE_CTRL.tBit.integ_half = CFGR_SENSE_CTRL_integ_half;
	tSRIC_CFGR_SENSE_CTRL.tBit.pre_gc = CFGR_SENSE_CTRL_pre_gc;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_gc = 5;
	tSRIC_CFGR_SENSE_CTRL.tBit.powsel = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.pre_bs_lp = CFGR_SENSE_CTRL_pre_bs_lp;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_bs_lp = CFGR_SENSE_CTRL_int_bs_lp;
	tSRIC_CFGR_SENSE_CTRL.tBit.sha_bs_lp = CFGR_SENSE_CTRL_sha_bs_lp;
	MSPI_RegisterWrite((0x144 | MSPI_BROADCAST), tSRIC_CFGR_SENSE_CTRL.ulBulk);

	// IDLE GTUNE
	tSRIC_CR_GTUNE_t tSRIC_CR_GTUNE;
	tSRIC_CR_GTUNE.tBit.cr_gtune = 2;
	MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), tSRIC_CR_GTUNE.ulBulk);
}

void SW97500_SetActiveOperationMode(void)
{
	tSRIC_CFGR_DIC_CFG_t tSRIC_CFGR_DIC_CFG;

	MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk);
	MSPI_RegisterWrite((0x024 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_DIC_CFG.ulBulk);
	MSPI_RegisterWrite((0x078 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_CFG_00.ulBulk);
	
	// ACTIVE Gain
	tSRIC_CFGR_SENSE_CTRL_t tSRIC_CFGR_SENSE_CTRL;
	tSRIC_CFGR_SENSE_CTRL.tBit.adc_bcon = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.adc_stc_insel = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_ref = 2;
	tSRIC_CFGR_SENSE_CTRL.tBit.sha_ref = 2;
	tSRIC_CFGR_SENSE_CTRL.tBit.lv_ssu_bcon = CFGR_SENSE_CTRL_lv_ssu_bcon;
	tSRIC_CFGR_SENSE_CTRL.tBit.lv_ssu_bcons = CFGR_SENSE_CTRL_lv_ssu_bcons;
	tSRIC_CFGR_SENSE_CTRL.tBit.hv_ssu_bcon = CFGR_SENSE_CTRL_hv_ssu_bcon;
	tSRIC_CFGR_SENSE_CTRL.tBit.integ_half = CFGR_SENSE_CTRL_integ_half;
	tSRIC_CFGR_SENSE_CTRL.tBit.pre_gc = CFGR_SENSE_CTRL_pre_gc;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_gc = 7;
	tSRIC_CFGR_SENSE_CTRL.tBit.powsel = 0;
	tSRIC_CFGR_SENSE_CTRL.tBit.pre_bs_lp = CFGR_SENSE_CTRL_pre_bs_lp;
	tSRIC_CFGR_SENSE_CTRL.tBit.int_bs_lp = CFGR_SENSE_CTRL_int_bs_lp;
	tSRIC_CFGR_SENSE_CTRL.tBit.sha_bs_lp = CFGR_SENSE_CTRL_sha_bs_lp;
	MSPI_RegisterWrite((0x144 | MSPI_BROADCAST), tSRIC_CFGR_SENSE_CTRL.ulBulk);
	
	tSRIC_CFGR_DIC_CFG.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_DIC_CFG.ulBulk;
	tSRIC_CFGR_DIC_CFG.tBit.sd_off = 0;
	tSRIC_CFGR_DIC_CFG.tBit.stuck_abd = 0;
	tSRIC_CFGR_DIC_CFG.tBit.cfgr_abd = 0;
	MSPI_RegisterWrite((0x024 | MSPI_BROADCAST), tSRIC_CFGR_DIC_CFG.ulBulk);

	// ACTIVE GTUNE
	tSRIC_CR_GTUNE_t tSRIC_CR_GTUNE;
	tSRIC_CR_GTUNE.tBit.cr_gtune = 0;
	MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), tSRIC_CR_GTUNE.ulBulk);
}

void SW97500_SetDiagTestOperationMode(eDIAG_TEST_CHANGE_MODE_t TestMode)
{
	tSRIC_CFGR_DIC_CFG_t tSRIC_CFGR_DIC_CFG;
	tSRIC_CFGR_MUX_EN_t tSRIC_CFGR_MUX_EN;
	tSRIC_CR_GTUNE_t tSRIC_CR_GTUNE;
	tSRIC_CFGR_TUNE_LOWER_t tCFGR_TUNE_LOWER;
	tSRIC_CFGR_TUNE_GROUP_t tSRIC_CFGR_TUNE_GROUP;
	tSRIC_CFGR_TUNE_UPPER_t tSRIC_CFGR_TUNE_UPPER;
	tSRIC_SPIS_CFG_t tSRIC_SPIS_CFG;
	tSRIC_CFGR_TG_STUCK_t tSRIC_CFGR_TG_STUCK;
	tSRIC_CFGR_SENSE_CTRL_t tSRIC_CFGR_SENSE_CTRL;

	switch(TestMode)
	{
		case DIAG_CHANGE_SHORT1_TEST_STEP1:
			tSRIC_CFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk;
			tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 5;
			MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP2:
			tSRIC_CFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk;
			tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 4;
			MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP3:
			tSRIC_CFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk;
			tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 3;
			MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP4:
			tSRIC_CFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk;
			tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 2;
			MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP5:
			tSRIC_CFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk;
			tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 1;
			MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);
			break;

		case DIAG_CHANGE_SHORT1_TEST_STEP6:	// <<<<
			tSRIC_CFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk;
			tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 5;
			MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);
			tSRIC_CR_GTUNE.tBit.cr_gtune = 3;
			MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), tSRIC_CR_GTUNE.ulBulk);
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP7:	// <<<<
			tSRIC_CFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk;
			tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 4;
			MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);
			tSRIC_CR_GTUNE.tBit.cr_gtune = 3;
			MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), tSRIC_CR_GTUNE.ulBulk);
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP8:	// <<<<
			tSRIC_CFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk;
			tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 3;
			MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);
			tSRIC_CR_GTUNE.tBit.cr_gtune = 3;
			MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), tSRIC_CR_GTUNE.ulBulk);
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP9:	// <<<<
			tSRIC_CFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk;
			tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 2;
			MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);
			tSRIC_CR_GTUNE.tBit.cr_gtune = 3;
			MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), tSRIC_CR_GTUNE.ulBulk);
			break;
		case DIAG_CHANGE_SHORT1_TEST_STEP10:	// <<<<
			tSRIC_CFGR_MUX_EN.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk;
			tSRIC_CFGR_MUX_EN.tBit.mux_int_en = 1;
			MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), tSRIC_CFGR_MUX_EN.ulBulk);
			tSRIC_CR_GTUNE.tBit.cr_gtune = 3;
			MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), tSRIC_CR_GTUNE.ulBulk);
			break;

		case DIAG_CHANGE_SHORT1_TEST_RECOVERY:
			MSPI_RegisterWrite((0x020 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_MUX_EN.ulBulk);
			MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CR_GTUNE.ulBulk);
			break;

		case DIAG_CHANGE_SHORT2_TEST_STEP1:	// All Node CR OFF
			tSRIC_CFGR_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_TG_STUCK.ulBulk;
			tSRIC_CFGR_TG_STUCK.tBit.stuck_vcr_odd_en = 1; // 1 : Low Stuck, 3 : High Stuck
			tSRIC_CFGR_TG_STUCK.tBit.stuck_vcr_even_en = 1;
			MSPI_RegisterWrite((0x06C | MSPI_BROADCAST), tSRIC_CFGR_TG_STUCK.ulBulk);

			tSRIC_CFGR_SENSE_CTRL.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_SENSE_CTRL.ulBulk;
			tSRIC_CFGR_SENSE_CTRL.tBit.integ_half = 0;
			MSPI_RegisterWrite((0x144 | MSPI_BROADCAST), tSRIC_CFGR_SENSE_CTRL.ulBulk);
			break;
		case DIAG_CHANGE_SHORT2_TEST_STEP2:	// 1st Frame // Even Node CR OFF
			tSRIC_CFGR_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_TG_STUCK.ulBulk;
			tSRIC_CFGR_TG_STUCK.tBit.stuck_vcr_odd_en = 3;
			tSRIC_CFGR_TG_STUCK.tBit.stuck_vcr_even_en = 1;
			MSPI_RegisterWrite((0x06C | MSPI_ROIC_RIGHT ), tSRIC_CFGR_TG_STUCK.ulBulk);
			MSPI_RegisterWrite((0x06C | MSPI_ROIC_RIGHT | MSPI_SHAREMODE), tSRIC_CFGR_TG_STUCK.ulBulk);
			tSRIC_CFGR_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_TG_STUCK.ulBulk;
			tSRIC_CFGR_TG_STUCK.tBit.stuck_vcr_odd_en = 1;
			tSRIC_CFGR_TG_STUCK.tBit.stuck_vcr_even_en = 3;
			MSPI_RegisterWrite((0x06C | MSPI_ROIC_LEFT ), tSRIC_CFGR_TG_STUCK.ulBulk);
			MSPI_RegisterWrite((0x06C | MSPI_ROIC_LEFT | MSPI_SHAREMODE), tSRIC_CFGR_TG_STUCK.ulBulk);

			tSRIC_CR_GTUNE.tBit.cr_gtune = 3;
			MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), tSRIC_CR_GTUNE.ulBulk);

			tSRIC_CFGR_SENSE_CTRL.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_SENSE_CTRL.ulBulk;
			tSRIC_CFGR_SENSE_CTRL.tBit.integ_half = 0;
			MSPI_RegisterWrite((0x144 | MSPI_BROADCAST), tSRIC_CFGR_SENSE_CTRL.ulBulk);
			break;
		case DIAG_CHANGE_SHORT2_TEST_STEP3:	// 2nd Frame // Odd Node CR OFF
			tSRIC_CFGR_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_TG_STUCK.ulBulk;
			tSRIC_CFGR_TG_STUCK.tBit.stuck_vcr_odd_en = 1;
			tSRIC_CFGR_TG_STUCK.tBit.stuck_vcr_even_en = 3;
			MSPI_RegisterWrite((0x06C | MSPI_ROIC_RIGHT ), tSRIC_CFGR_TG_STUCK.ulBulk);
			MSPI_RegisterWrite((0x06C | MSPI_ROIC_RIGHT | MSPI_SHAREMODE), tSRIC_CFGR_TG_STUCK.ulBulk);
			tSRIC_CFGR_TG_STUCK.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_TG_STUCK.ulBulk;
			tSRIC_CFGR_TG_STUCK.tBit.stuck_vcr_odd_en = 3;
			tSRIC_CFGR_TG_STUCK.tBit.stuck_vcr_even_en = 1;
			MSPI_RegisterWrite((0x06C | MSPI_ROIC_LEFT ), tSRIC_CFGR_TG_STUCK.ulBulk);
			MSPI_RegisterWrite((0x06C | MSPI_ROIC_LEFT | MSPI_SHAREMODE), tSRIC_CFGR_TG_STUCK.ulBulk);

			tSRIC_CR_GTUNE.tBit.cr_gtune = 3;
			MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), tSRIC_CR_GTUNE.ulBulk);

			tSRIC_CFGR_SENSE_CTRL.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_SENSE_CTRL.ulBulk;
			tSRIC_CFGR_SENSE_CTRL.tBit.integ_half = 0;
			MSPI_RegisterWrite((0x144 | MSPI_BROADCAST), tSRIC_CFGR_SENSE_CTRL.ulBulk);
			break;
		case DIAG_CHANGE_SHORT2_TEST_RECOVERY:
			MSPI_RegisterWrite((0x06C | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_TG_STUCK.ulBulk);
			MSPI_RegisterWrite((0x134 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CR_GTUNE.ulBulk);
			MSPI_RegisterWrite((0x144 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_SENSE_CTRL.ulBulk);
			break;

		case DIAG_CHANGE_OPEN_TEST_STEP1:
#if USED_PWM_GATE_CONTROL
			PWMDRV->PWM_MUX_CR.tBit.finger_en = 0;
			PWMDRV->PWM_MUX_CR.tBit.finger_dmy_en = 0;
#endif /* USED_PWM_GATE_CONTROL */
			tSRIC_CFGR_DIC_CFG.ulBulk = s_pktmoduleSRICCommonConf->tParam_CFGR_DIC_CFG.ulBulk;
			tSRIC_CFGR_DIC_CFG.tBit.sd_float = 1;
			MSPI_RegisterWrite((0x024 | MSPI_BROADCAST), tSRIC_CFGR_DIC_CFG.ulBulk);
			break;
		case DIAG_CHANGE_OPEN_TEST_RECOVERY:
#if USED_PWM_GATE_CONTROL
			PWMDRV->PWM_MUX_CR.ulBulk = hal_pwmdrv_GetControlConfig()->tCP_PWM_MUX_CR.ulBulk;
#endif /* USED_PWM_GATE_CONTROL */
			MSPI_RegisterWrite((0x024 | MSPI_BROADCAST), s_pktmoduleSRICCommonConf->tParam_CFGR_DIC_CFG.ulBulk);
			break;
		default:
			break;
	}
}

void SW97500_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
	switch(eMode)
	{
		case ROIC_REG_SET_CHANGE_MUX_REMAP:
		{
			break;
		}
		case ROIC_REG_SET_CHAGNE_CR_TUNE:
		case ROIC_REG_SET_CHAGNE_LOCAL_CR_TUNE:
		{
			SW97500_Reg_CRTuneSetting(eMode);
			break;
		}
		case ROIC_REG_SET_CHAGNE_WacomPen_Local_Setting:
		{
			break;
		}
		case ROIC_REG_SET_CHAGNE_WacomPen_Full_Setting:
		{
			break;
		}
		case ROIC_REG_SET_CHAGNE_MSPen_Local_Setting:
		{
			break;
		}
		case ROIC_REG_SET_CHAGNE_MSPen_Full_Setting:
		{
			break;
		}
//		case ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_ACTIVE:
//		{
//			break;
//		}
//		case ROIC_REG_SET_CHANGE_FINGER_PEN_FULL:
//		{
//			break;
//		}
#if USED_NOISE_HOPPING_FREQ
		case ROIC_REG_SET_FreHopp_CHANGE_Main_Freq:
		{
			SW97500_Reg_AFESetting(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
			break;
		}
		case ROIC_REG_SET_FreHopp_CHANGE_Hopp1_Freq:
		{
			SW97500_Reg_AFESetting(SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE);
			break;
		}
#endif /* USED_NOISE_HOPPING_FREQ */
	}
}

#if USED_RUNTIME_LOCAL_TUNE_RAWDATA
//#define DEF_ROIC_NUM					(8)
#define DEF_LOCAL_TAGET_VALUE				(1900)
#define DEF_LOCAL_CR_1STEP_VALUE			(160)
#define DEF_LOCAL_TUNE_ROW_LINE_NUM			(2) /* Top/Bottom Edge Line */
#define DEF_LOCAL_TUNE_ROW_ROIC_NUM			(8*2) /* SRIC 8 * 2(R0 & R1) */
#define DEF_LOCAL_TUNE_ROW_CR_GROUP_NUM		(3) /* G1, G2, G3 */

#define DEF_LOCAL_TUNE_COL_LINE_NUM			(2) /* Left/Right Edge Line */
#define DEF_LOCAL_TUNE_COL_CR_GROUP_NUM		(3) /* R1, R2, R3 (only Top & Bottom) */
#define DEF_LOCAL_TUNE_COL_CR_IDX_NUM		(14) /* 1st & Last Mux(Top, Middle, Bottom) */

uint32_t RawValue_Row_Line_Sum[DEF_LOCAL_TUNE_ROW_LINE_NUM][DEF_LOCAL_TUNE_ROW_ROIC_NUM][DEF_LOCAL_TUNE_ROW_CR_GROUP_NUM];
uint8_t RawValue_Row_Line_Cnt[DEF_LOCAL_TUNE_ROW_LINE_NUM][DEF_LOCAL_TUNE_ROW_ROIC_NUM][DEF_LOCAL_TUNE_ROW_CR_GROUP_NUM];
uint32_t RawValue_Col_Line_Sum[DEF_LOCAL_TUNE_COL_LINE_NUM][DEF_LOCAL_TUNE_COL_CR_IDX_NUM];
uint8_t RawValue_Col_Line_Cnt[DEF_LOCAL_TUNE_COL_LINE_NUM][DEF_LOCAL_TUNE_COL_CR_IDX_NUM];

uint8_t ulCRIndex[ROW_MAX] = {
	/*9 Mux*/11,12,12,12,13,
	/*8 Mux*/9,9,9,9,9,
	/*7 Mux*/8,8,8,8,8,
	/*6 Mux*/7,7,7,7,7,
	/*5 Mux*/6,6,6,6,6,
	/*4 Mux*/5,5,5,5,5,
	/*3 Mux*/4,4,4,4,4,
	/*2 Mux*/3,3,3,3,3,
	/*1 Mux*/0,1,1,1,2,
};

uint8_t ucColLineCRMSPIIdx[DEF_LOCAL_TUNE_COL_LINE_NUM][2] = {
	{7, 0 /*SRIC R0, R1*/} /*Left*/,
	{0, 1 /*SRIC R0, R1*/} /*Right*/
};

uint8_t ucColLineCRRegIdx[DEF_LOCAL_TUNE_COL_CR_IDX_NUM] = {
	0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 11
};

uint8_t ucRowLineCRRegIdx[DEF_LOCAL_TUNE_ROW_LINE_NUM][2] = {
	{10, 1/*r1, r2, r3 Index*/}/* Top */,
	{1, 3/*r1, r2, r3 Index*/}/* Bottom */
};

uint8_t ulMSPIIndex[COL_MAX] = {
	/*SRIC_0*/ /*R0*/7, 7, 7, 7, 7, /*R1*/15, 15, 15, 15, 15,
	/*SRIC_1*/ /*R0*/6, 6, 6, 6, 6, /*R1*/14, 14, 14, 14, 14,
	/*SRIC_2*/ /*R0*/5, 5, 5, 5, 5, /*R1*/13, 13, 13, 13, 13,
	/*SRIC_3*/ /*R0*/4, 4, 4, 4, 4, /*R1*/12, 12, 12, 12, 12,
	/*SRIC_4*/ /*R0*/3, 3, 3, 3, 3, /*R1*/11, 11, 11, 11, 11,
	/*SRIC_5*/ /*R0*/2, 2, 2, 2, 2, /*R1*/10, 10, 10, 10, 10,
	/*SRIC_6*/ /*R0*/1, 1, 1, 1, 1, /*R1*/9, 9, 9, 9, 9,
	/*SRIC_7*/ /*R0*/0, 0, 0, 0, 0, /*R1*/8, 8, 8, 8, 8,
};

uint8_t ulROIC_gNum[COL_MAX] = {
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
};

void SW97500_RawDataLocalRuntimeCalibration(void)
{
	bool_t bIsCRRegChange = NO;
	uint32_t r, c, g;
	uint32_t ulRealMSPI_Idx;
	uint16_t temp_data;
	int16_t temp_diff;
	int16_t sCRAdjustValue;
	tSW97500_ROIC_CR_MUX_t *  pCR_MUX_Tune;
	uint32_t ulCRRegTempBulk, ulCRRegAdustBulk;
#ifdef MODE_WDT
	KICK_DOG();
#endif /* MODE_WDT */
#if USED_ONLY_LOCAL_MODE
	while(YES)
	{
		lDataIndex = module_wait_local_sample_done();

		if(lDataIndex == LOCAL_FINGER_LAST_LHB)
		{
			break;
		}
	}
#else /* USED_ONLY_LOCAL_MODE */
	module_wait_full_sample_done();
#endif /* USED_ONLY_LOCAL_MODE */
	g_ptSRICConfig = (tModuleSRICCommonConf_t *)&(s_ptParamPreMainSet->tParamCommonConf.tModule.tSRIC_Conf);
	g_pR0_CR_MUX_Tune = (tSW97500_ROIC_CR_MUX_t *)&g_ptSRICConfig->tParam_R0_CR1_MUX1_1[0].ulBulk;
	g_pR1_CR_MUX_Tune = (tSW97500_ROIC_CR_MUX_t *)&g_ptSRICConfig->tParam_R1_CR1_MUX1_1[0].ulBulk;

	memset((void*)(&RawValue_Row_Line_Sum[0][0][0]), 0, sizeof(uint32_t)*DEF_LOCAL_TUNE_ROW_LINE_NUM*DEF_LOCAL_TUNE_ROW_ROIC_NUM*DEF_LOCAL_TUNE_ROW_CR_GROUP_NUM);
	memset((void*)(&RawValue_Row_Line_Cnt[0][0][0]), 0, sizeof(uint8_t)*DEF_LOCAL_TUNE_ROW_LINE_NUM*DEF_LOCAL_TUNE_ROW_ROIC_NUM*DEF_LOCAL_TUNE_ROW_CR_GROUP_NUM);
	memset((void*)(&RawValue_Col_Line_Sum[0][0]), 0, sizeof(uint32_t)*DEF_LOCAL_TUNE_COL_LINE_NUM*DEF_LOCAL_TUNE_COL_CR_IDX_NUM);
	memset((void*)(&RawValue_Col_Line_Cnt[0][0]), 0, sizeof(uint8_t)*DEF_LOCAL_TUNE_COL_LINE_NUM*DEF_LOCAL_TUNE_COL_CR_IDX_NUM);


	for( r=ROW_MAX; r--; )
	{
		for( c=COL_MAX; c--; )
		{
			temp_data = HAL_READ_RAW_IMAGE(r, c);
			if(r == 0)
			{
				RawValue_Row_Line_Sum[0][ulMSPIIndex[c]][ulROIC_gNum[c]] += temp_data;
				RawValue_Row_Line_Cnt[0][ulMSPIIndex[c]][ulROIC_gNum[c]]++;
			}
			else if(r ==  ROW_MAX - 1)
			{
				RawValue_Row_Line_Sum[1][ulMSPIIndex[c]][ulROIC_gNum[c]] += temp_data;
				RawValue_Row_Line_Cnt[1][ulMSPIIndex[c]][ulROIC_gNum[c]]++;
			}
			else
			{
				if(c == 0)
				{
					RawValue_Col_Line_Sum[0][ulCRIndex[r]] += temp_data;
					RawValue_Col_Line_Cnt[0][ulCRIndex[r]]++;
				}
				else if(c == COL_MAX - 1)
				{
					RawValue_Col_Line_Sum[1][ulCRIndex[r]] += temp_data;
					RawValue_Col_Line_Cnt[1][ulCRIndex[r]]++;
				}
			}
		}
	}

	/*
	 * Top & Bottom Edge
	 */
#if 1
	for(r = 0; r < DEF_LOCAL_TUNE_ROW_LINE_NUM; r++)
	{
		for(c = 0; c < DEF_LOCAL_TUNE_ROW_ROIC_NUM; c++)
		{
			for(g = 0; g < DEF_LOCAL_TUNE_ROW_CR_GROUP_NUM; g++)
			{
				temp_data = RawValue_Row_Line_Sum[r][c][g];
				temp_data /= RawValue_Row_Line_Cnt[r][c][g];
				temp_diff = (int16_t)temp_data - (int16_t)DEF_LOCAL_TAGET_VALUE;
				sCRAdjustValue = temp_diff / DEF_LOCAL_CR_1STEP_VALUE;
				if(sCRAdjustValue != 0)
				{
					bIsCRRegChange = YES;
					if(c < DEF_ROIC_NUM)
					{
						ulRealMSPI_Idx = c;
						pCR_MUX_Tune = g_pR0_CR_MUX_Tune; /* R0 */
					}
					else
					{
						ulRealMSPI_Idx = c - DEF_ROIC_NUM;
						pCR_MUX_Tune = g_pR1_CR_MUX_Tune; /* R1 */
					}

					uint32_t ulShiftLevel;

					switch(ucRowLineCRRegIdx[r][1])
					{
						case 1: /* R1 */
						case 3: /* R3 */
						{
							ulShiftLevel = g*5;
//							switch(g)
//							{
//								case 0:
//								{
//									pCR_MUX_Tune[ulRealMSPI_Idx + (ucRowLineCRRegIdx[r][0] * DEF_ROIC_NUM)].tBit.cr1_r1g1  += sCRAdjustValue;
//									break;
//								}
//								case 1:
//								{
//									pCR_MUX_Tune[ulRealMSPI_Idx + (ucRowLineCRRegIdx[r][0] * DEF_ROIC_NUM)].tBit.cr1_r1g2 += sCRAdjustValue;
//									break;
//								}
//								case 2:
//								{
//									pCR_MUX_Tune[ulRealMSPI_Idx + (ucRowLineCRRegIdx[r][0] * DEF_ROIC_NUM)].tBit.cr1_r1g3 += sCRAdjustValue;
//									break;
//								}
//							}
							break;
						}
						case 2: /* R2 */
						{
							ulShiftLevel = (g*5) + 15;
//							switch(g)
//							{
//								case 0:
//								{
//									pCR_MUX_Tune[ulRealMSPI_Idx + (ucRowLineCRRegIdx[r][0] * DEF_ROIC_NUM)].tBit.cr1_r2g1 += sCRAdjustValue;
//									break;
//								}
//								case 1:
//								{
//									pCR_MUX_Tune[ulRealMSPI_Idx + (ucRowLineCRRegIdx[r][0] * DEF_ROIC_NUM)].tBit.cr1_r2g2 += sCRAdjustValue;
//									break;
//								}
//								case 2:
//								{
//									pCR_MUX_Tune[ulRealMSPI_Idx + (ucRowLineCRRegIdx[r][0] * DEF_ROIC_NUM)].tBit.cr1_r2g3 += sCRAdjustValue;
//									break;
//								}
//							}
							break;
						}
					}


					ulCRRegTempBulk = pCR_MUX_Tune[ulRealMSPI_Idx + (ucRowLineCRRegIdx[r][0] * DEF_ROIC_NUM)].ulBulk;
					ulCRRegAdustBulk = (ulCRRegTempBulk >> ulShiftLevel) & 0x1F;

					if(sCRAdjustValue > 0)
					{
						ulCRRegAdustBulk += sCRAdjustValue;
						if(ulCRRegAdustBulk > 31)
						{
							ulCRRegAdustBulk = 31;
						}
					}
					else
					{
						if((int16_t)ulCRRegAdustBulk + sCRAdjustValue > 0)
						{
							ulCRRegAdustBulk = (uint32_t)((int16_t)ulCRRegAdustBulk + sCRAdjustValue);
						}
						else
						{
							ulCRRegAdustBulk = 0;
						}
					}

					ulCRRegTempBulk &= (~(0x1F<<ulShiftLevel));
					ulCRRegTempBulk |= (ulCRRegAdustBulk<<ulShiftLevel);
					pCR_MUX_Tune[ulRealMSPI_Idx + (ucRowLineCRRegIdx[r][0] * DEF_ROIC_NUM)].ulBulk = ulCRRegTempBulk;
				}
			}
		}
	}
#endif
	/*
	 * Left Right Edge
	 */
#if 1
	for(c = 0; c < DEF_LOCAL_TUNE_COL_LINE_NUM; c++)
	{
		for(r = 0; r < DEF_LOCAL_TUNE_COL_CR_IDX_NUM; r++)
		{
			temp_data = RawValue_Col_Line_Sum[c][r];
			temp_data /= RawValue_Col_Line_Cnt[c][r];
			if(temp_data > 0)
			{
				temp_diff = (int16_t)temp_data - (int16_t)DEF_LOCAL_TAGET_VALUE;
				sCRAdjustValue = temp_diff / DEF_LOCAL_CR_1STEP_VALUE;
			}
			else
			{
				sCRAdjustValue = 0;
			}

			if(sCRAdjustValue != 0)
			{
				bIsCRRegChange = YES;

				if(ucColLineCRMSPIIdx[c][1] == 0)
				{
					pCR_MUX_Tune = g_pR0_CR_MUX_Tune; /* R0 */
				}
				else
				{
					pCR_MUX_Tune = g_pR1_CR_MUX_Tune; /* R1 */
				}

				int16_t sRegValue;

				switch(r)
				{
					case 0:case 2:case 3:case 4:case 5:case 6:case 7:
					case 8:case 9:case 10:case 11:case 13:
					{
						sRegValue = pCR_MUX_Tune[ucColLineCRMSPIIdx[c][0] + (ucColLineCRRegIdx[r]*DEF_ROIC_NUM)].tBit.cr1_r1g1;
						if(sCRAdjustValue > 0)
						{
							sRegValue += sCRAdjustValue;
							if(sRegValue > 31)
							{
								sRegValue = 31;
							}
						}
						else
						{
							if(sRegValue + sCRAdjustValue > 0)
							{
								sRegValue += sCRAdjustValue;
							}
							else
							{
								sRegValue = 0;
							}
						}
						pCR_MUX_Tune[ucColLineCRMSPIIdx[c][0] + (ucColLineCRRegIdx[r]*DEF_ROIC_NUM)].tBit.cr1_r1g1 = sRegValue;

						break;
					}
					case 1:case 12:
					{
						sRegValue = pCR_MUX_Tune[ucColLineCRMSPIIdx[c][0] + (ucColLineCRRegIdx[r]*DEF_ROIC_NUM)].tBit.cr1_r2g1;
						if(sCRAdjustValue > 0)
						{
							sRegValue += sCRAdjustValue;
							if(sRegValue > 31)
							{
								sRegValue = 31;
							}
						}
						else
						{
							if(sRegValue + sCRAdjustValue > 0)
							{
								sRegValue += sCRAdjustValue;
							}
							else
							{
								sRegValue = 0;
							}
						}
						pCR_MUX_Tune[ucColLineCRMSPIIdx[c][0] + (ucColLineCRRegIdx[r]*DEF_ROIC_NUM)].tBit.cr1_r2g1 = sRegValue;
						break;
					}
				}
			}
		}
	}
#endif

	if(bIsCRRegChange)
	{
		HAL_SetROICRegSetChangeMode(ROIC_REG_SET_CHAGNE_LOCAL_CR_TUNE);
#ifdef MODE_WDT
		KICK_DOG();
#endif /* MODE_WDT */
#if USED_ONLY_LOCAL_MODE
		while(YES)
		{
			lDataIndex = module_wait_local_sample_done();

			if(lDataIndex == LOCAL_OP_LAST_LHB)
			{
				break;
			}
		}
#else /* USED_ONLY_LOCAL_MODE */
		module_wait_full_sample_done();
#endif /* USED_ONLY_LOCAL_MODE */
	}
}
#endif /* USED_RUNTIME_LOCAL_TUNE_RAWDATA */

#if USED_RAWDATA_TUNE_CALIBRATION
//#define DEF_ROIC_LOCAL_CR_TUNE_REG_NUM	(13)
#define DEF_ROIC_MUX_CR_GROUP_MAX_NUM	(14)
#define DEF_ROIC_COL_CR_GROUP_MAX_NUM	(3)
//#define DEF_ROIC_NUM					(8)

#define DEF_ROIC_MUX_CR_GROUP_USED_NUM	(13)
#define DEF_ROIC_COL_CR_GROUP_USED_NUM	(3)
#define DEF_ROIC_CR_MAX_CHECK_VALUE		(31)

uint32_t RawValue_sum_R0[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];
uint32_t RawValue_sum_R1[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];
uint8_t RawSumCnt_R0[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];
uint8_t RawSumCnt_R1[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];

uint16_t RawValue_R0[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];
uint16_t RawValue_R1[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];

uint8_t AutoCalfinish_R0[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];
uint8_t AutoCalfinish_R1[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];



uint8_t ucROIC_RegIdx_DubleCheck[DEF_ROIC_MUX_CR_GROUP_MAX_NUM] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
};
uint8_t ucROIC_CRRegIdx[DEF_ROIC_MUX_CR_GROUP_MAX_NUM] = {
	10, 10, 11, 8, 7, 6, 5, 4, 3, 2, 0, 0, 1,
};
uint8_t ucROIC_RowBufIdx[DEF_ROIC_MUX_CR_GROUP_MAX_NUM] = {
	11, 12, 13, 9, 8, 7, 6, 5, 4, 3, 0, 1, 2,
};

uint8_t ulCRIndex[ROW_MAX] = {
	/*9 Mux*/11,12,12,12,13,
	/*8 Mux*/9,9,9,9,9,
	/*7 Mux*/8,8,8,8,8,
	/*6 Mux*/7,7,7,7,7,
	/*5 Mux*/6,6,6,6,6,
	/*4 Mux*/5,5,5,5,5,
	/*3 Mux*/4,4,4,4,4,
	/*2 Mux*/3,3,3,3,3,
	/*1 Mux*/0,1,1,1,2,
};

uint8_t ulMSPIIndex[COL_MAX] = {
	/*SRIC_0*/ /*R0*/7, 7, 7, 7, 7, /*R1*/15, 15, 15, 15, 15,
	/*SRIC_1*/ /*R0*/6, 6, 6, 6, 6, /*R1*/14, 14, 14, 14, 14,
	/*SRIC_2*/ /*R0*/5, 5, 5, 5, 5, /*R1*/13, 13, 13, 13, 13,
	/*SRIC_3*/ /*R0*/4, 4, 4, 4, 4, /*R1*/12, 12, 12, 12, 12,
	/*SRIC_4*/ /*R0*/3, 3, 3, 3, 3, /*R1*/11, 11, 11, 11, 11,
	/*SRIC_5*/ /*R0*/2, 2, 2, 2, 2, /*R1*/10, 10, 10, 10, 10,
	/*SRIC_6*/ /*R0*/1, 1, 1, 1, 1, /*R1*/9, 9, 9, 9, 9,
	/*SRIC_7*/ /*R0*/0, 0, 0, 0, 0, /*R1*/8, 8, 8, 8, 8,
};

uint8_t ulROIC_gNum[COL_MAX] = {
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
	/* Group Idx */ /*R0*/0, 1, 1, 1, 2, /*R1*/2, 1, 1, 1, 0,
};

//uint32_t Change_CR_Value = 0;

//typedef union
//{
//	struct
//	{
//		__IO uint32_t cr1_r1g1: 5;
//		__IO uint32_t cr1_r1g2: 5;
//		__IO uint32_t cr1_r1g3: 5;
//		__IO uint32_t cr1_r2g1: 5;
//		__IO uint32_t cr1_r2g2: 5;
//		__IO uint32_t cr1_r2g3: 5;
//	}__PACKED tBit;
//	__IO uint32_t ulBulk;
//}__PACKED tSW97500_ROIC_CR_MUX_t;

typedef struct
{
	bool_t bISAllFinish;
	bool_t bIsAutoCalFinish;
	int32_t lCalChangeRemainCnt_R0;
	int32_t lCalChangeRemainCnt_R1;
	uint32_t ulTestFrameNum;
	uint32_t ulTestCountNum;

	uint16_t usTemp_RawData;
	uint32_t Change_CR_Value;

} tSW98500_CR_Auto_Cal_Info_t;

tSW98500_CR_Auto_Cal_Info_t tAutoCalInfo;

//extern tParamPreMainSet_t * s_ptParamPreMainSet;
//tModuleSRICCommonConf_t * g_ptSRICConfig;

//tSW97500_ROIC_CR_MUX_t * g_pR0_CR_MUX_Tune;
//tSW97500_ROIC_CR_MUX_t * g_pR1_CR_MUX_Tune;
//bool_t bISAllFinish = NO;
//uint16_t usTemp_RawData;

#define AUTO_CAL_AVERAGE_FRAME_NUM			(100)
void SW97500_RawDataCalibration(void)
{
	bool_t bIsLoop = YES;
	uint32_t r, c, g, framenum;
	uint32_t ulReal_Col;
	uint32_t ulROIC_Reg_r_Idx;
	uint32_t ulROIC_Reg_Idx;
	uint32_t temp_data;
	int16_t sPosTempDiff;
	int16_t sNegTempDiff;
	bool_t bIsCRMaxValueCheckFlg;
#if USED_ONLY_LOCAL_MODE
	ePartialSensing_t lDataIndex = PARTIAL_PEN_BEACON;
#endif /* USED_ONLY_LOCAL_MODE */

	g_ptSRICConfig = (tModuleSRICCommonConf_t *)&(s_ptParamPreMainSet->tParamCommonConf.tModule.tSRIC_Conf);
	g_pR0_CR_MUX_Tune = (tSW97500_ROIC_CR_MUX_t *)&g_ptSRICConfig->tParam_R0_CR1_MUX1_1[0].ulBulk;
	g_pR1_CR_MUX_Tune = (tSW97500_ROIC_CR_MUX_t *)&g_ptSRICConfig->tParam_R1_CR1_MUX1_1[0].ulBulk;

	memset((void*)(&tAutoCalInfo), 0, sizeof(tSW98500_CR_Auto_Cal_Info_t));
	memset((void*)(&AutoCalfinish_R0[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_MUX_CR_GROUP_MAX_NUM*DEF_ROIC_NUM*DEF_ROIC_COL_CR_GROUP_MAX_NUM);
	memset((void*)(&AutoCalfinish_R1[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_MUX_CR_GROUP_MAX_NUM*DEF_ROIC_NUM*DEF_ROIC_COL_CR_GROUP_MAX_NUM);
	tAutoCalInfo.lCalChangeRemainCnt_R0 = DEF_ROIC_MUX_CR_GROUP_USED_NUM*DEF_ROIC_NUM*DEF_ROIC_COL_CR_GROUP_MAX_NUM;
	tAutoCalInfo.lCalChangeRemainCnt_R1 = DEF_ROIC_MUX_CR_GROUP_USED_NUM*DEF_ROIC_NUM*DEF_ROIC_COL_CR_GROUP_MAX_NUM;

    tHalIntrHandle.ulLocalIndexChangeStart = 1;
#if (USED_ONLY_LOCAL_MODE == NO)
	if(IS_FINGER_PEN_MODE(HAL_GetSensingMode()))
	{
		HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);
	}
#endif /* (USED_ONLY_LOCAL_MODE == NO) */

#if (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO)
//	memset((void*)(&g_pR0_CR_MUX_Tune[0]), 0, sizeof(uint32_t)*DEF_ROIC_LOCAL_CR_TUNE_REG_NUM*DEF_ROIC_NUM);
//	memset((void*)(&g_pR0_CR_MUX_Tune[0]), 0, sizeof(uint32_t)*DEF_ROIC_LOCAL_CR_TUNE_REG_NUM*DEF_ROIC_NUM);

#if USED_ONLY_LOCAL_MODE
	framenum = 0;
	while(1)
	{
		lDataIndex = module_wait_local_sample_done();
		if(lDataIndex == LOCAL_OP_LAST_LHB)
		{
			framenum++;
			if(framenum == 10)
			{
				break;
			}
		}
	}
#else /* USED_ONLY_LOCAL_MODE */
    for( framenum=0; framenum<100; framenum++ )
    {
#ifdef MODE_WDT
		KICK_DOG();
#endif /* MODE_WDT */
    	module_wait_full_sample_done();
    }
#endif /* USED_ONLY_LOCAL_MODE */

#endif /* (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO) */

	while(bIsLoop)
	{
#ifdef MODE_WDT
		KICK_DOG();
#endif /* MODE_WDT */

#if USED_ONLY_LOCAL_MODE
	    while(YES)
	    {
			lDataIndex = module_wait_local_sample_done();

			if(lDataIndex == LOCAL_FINGER_LAST_LHB)
			{
				break;
			}
		}
#else /* USED_ONLY_LOCAL_MODE */
		module_wait_full_sample_done();
#endif /* USED_ONLY_LOCAL_MODE */

		protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);
		protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);

#if (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO)
		if(tAutoCalInfo.bIsAutoCalFinish == NO)
		{
			tAutoCalInfo.ulTestCountNum++;
			/*
			 * RawData Sum
			 */
			memset((void*)(HAL_GET_COMMON_IMAGE_PTR()), 0, sizeof(uint32_t)*COL_MAX*ROW_MAX);

			tAutoCalInfo.ulTestFrameNum = 0;
			for(framenum = 0; framenum < AUTO_CAL_AVERAGE_FRAME_NUM; framenum++)
			{
				tAutoCalInfo.ulTestFrameNum++;
#ifdef MODE_WDT
				KICK_DOG();
#endif /* MODE_WDT */
#if USED_ONLY_LOCAL_MODE
			    while(YES)
			    {
					lDataIndex = module_wait_local_sample_done();

					if(lDataIndex == LOCAL_FINGER_LAST_LHB)
					{
						break;
					}
				}
#else /* USED_ONLY_LOCAL_MODE */
				module_wait_full_sample_done();
#endif /* USED_ONLY_LOCAL_MODE */
				for( r=ROW_MAX; r--; )
				{
					for( c=COL_MAX; c--; )
					{
						temp_data = HAL_READ_COMMON_IMAGE(r, c) + (uint32_t)HAL_READ_RAW_IMAGE(r, c);
						HAL_WRITE_COMMON_IMAGE(r, c, temp_data);
					}
				}
			}

			for( r=ROW_MAX; r--; )
			{
				for( c=COL_MAX; c--; )
				{
					temp_data = HAL_READ_COMMON_IMAGE(r, c) / tAutoCalInfo.ulTestFrameNum;
					HAL_WRITE_COMMON_IMAGE(r, c, temp_data);
				}
			}

			memset((void*)(&RawValue_sum_R0[0][0][0]), 0, sizeof(uint32_t)*DEF_ROIC_MUX_CR_GROUP_MAX_NUM*DEF_ROIC_NUM*DEF_ROIC_COL_CR_GROUP_MAX_NUM);
			memset((void*)(&RawValue_sum_R1[0][0][0]), 0, sizeof(uint32_t)*DEF_ROIC_MUX_CR_GROUP_MAX_NUM*DEF_ROIC_NUM*DEF_ROIC_COL_CR_GROUP_MAX_NUM);

			memset((void*)(&RawSumCnt_R0[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_MUX_CR_GROUP_MAX_NUM*DEF_ROIC_NUM*DEF_ROIC_COL_CR_GROUP_MAX_NUM);
			memset((void*)(&RawSumCnt_R1[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_MUX_CR_GROUP_MAX_NUM*DEF_ROIC_NUM*DEF_ROIC_COL_CR_GROUP_MAX_NUM);

			for( r=ROW_MAX; r--; )
			{
				for( c=COL_MAX; c--; )
				{
					temp_data = HAL_READ_COMMON_IMAGE(r, c);
					{
						if(ulMSPIIndex[c] < DEF_ROIC_NUM)
						{
							RawValue_sum_R0[ulCRIndex[r]][ulMSPIIndex[c]][ulROIC_gNum[c]] += temp_data;
							RawSumCnt_R0[ulCRIndex[r]][ulMSPIIndex[c]][ulROIC_gNum[c]]++;
						}
						else
						{
							RawValue_sum_R1[ulCRIndex[r]][ulMSPIIndex[c]-DEF_ROIC_NUM][ulROIC_gNum[c]] += temp_data;
							RawSumCnt_R1[ulCRIndex[r]][ulMSPIIndex[c]-DEF_ROIC_NUM][ulROIC_gNum[c]]++;
						}
					}
				}
			}

			for( r=DEF_ROIC_MUX_CR_GROUP_USED_NUM; r--; )
			{
				for( c=DEF_ROIC_NUM; c--; )
				{
					for(g=DEF_ROIC_COL_CR_GROUP_USED_NUM; g--; )
					{
						ulROIC_Reg_r_Idx = ucROIC_RegIdx_DubleCheck[r];
						ulROIC_Reg_Idx = ucROIC_CRRegIdx[r];

						if(AutoCalfinish_R0[ucROIC_RowBufIdx[r]][c][g] == 0)
						{
							tAutoCalInfo.usTemp_RawData = (uint16_t)(RawValue_sum_R0[ucROIC_RowBufIdx[r]][c][g]/RawSumCnt_R0[ucROIC_RowBufIdx[r]][c][g]);

							bIsCRMaxValueCheckFlg = NO;
							if(RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL < tAutoCalInfo.usTemp_RawData)
							{
								switch(g)
								{
									case 0:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}
										}
										else
										{
											if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}
										}
										break;
									}
									case 1:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}
										}
										else
										{
											if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}
										}
										break;
									}
									case 2:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}

										}
										else
										{
											if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}
										}
										break;
									}
								}
							}
							else
							{
								bIsCRMaxValueCheckFlg = YES;
							}

							if(bIsCRMaxValueCheckFlg == YES)
							{
								sNegTempDiff = RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL - (int16_t)tAutoCalInfo.usTemp_RawData;
								sPosTempDiff = (int16_t)RawValue_R0[ucROIC_RowBufIdx[r]][c][g] - RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL;
								if(sPosTempDiff < sNegTempDiff)
								{
									switch(g)
									{
										case 0:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1 -= 1;
												}
											}
											else
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1 -= 1;
												}
											}
											break;
										}
										case 1:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2 -= 1;
												}
											}
											else
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2 -= 1;
												}
											}
											break;
										}
										case 2:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3 -= 1;
												}
											}
											else
											{
												if(g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3 > 0)
												{
													g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3 -= 1;
												}
											}
											break;
										}
									}
								}
								AutoCalfinish_R0[ucROIC_RowBufIdx[r]][c][g] = 1;
								tAutoCalInfo.lCalChangeRemainCnt_R0--;
							}

							RawValue_R0[ucROIC_RowBufIdx[r]][c][g] = tAutoCalInfo.usTemp_RawData;
						}

						if(AutoCalfinish_R1[ucROIC_RowBufIdx[r]][c][g] == 0)
						{
							tAutoCalInfo.usTemp_RawData = (uint16_t)(RawValue_sum_R1[ucROIC_RowBufIdx[r]][c][g]/RawSumCnt_R1[ucROIC_RowBufIdx[r]][c][g]);

							bIsCRMaxValueCheckFlg = NO;
							if(RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL < tAutoCalInfo.usTemp_RawData)
							{
								switch(g)
								{
									case 0:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}
										}
										else
										{
											if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}
										}
										break;
									}
									case 1:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}
										}
										else
										{
											if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}
										}
										break;
									}
									case 2:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}
										}
										else
										{
											if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3 < DEF_ROIC_CR_MAX_CHECK_VALUE)
											{
												g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3 += 1;
											}
											else
											{
												bIsCRMaxValueCheckFlg = YES;
											}
										}
										break;
									}
								}
							}
							else
							{
								bIsCRMaxValueCheckFlg = YES;
							}

							if(bIsCRMaxValueCheckFlg == YES)
							{
								sNegTempDiff = RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL - tAutoCalInfo.usTemp_RawData;
								sPosTempDiff = RawValue_R1[ucROIC_RowBufIdx[r]][c][g] - RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL;
								if(sPosTempDiff < sNegTempDiff)
								{
									switch(g)
									{
										case 0:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1 -= 1;
												}
											}
											else
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1 -= 1;
												}
											}
											break;
										}
										case 1:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2 -= 1;
												}
											}
											else
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2 -= 1;
												}
											}
											break;
										}
										case 2:
										{
											if(ulROIC_Reg_r_Idx == 0)
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3 -= 1;
												}
											}
											else
											{
												if(g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3 > 0)
												{
													g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3 -= 1;
												}
											}
											break;
										}
									}
								}
								AutoCalfinish_R1[ucROIC_RowBufIdx[r]][c][g] = 1;
								tAutoCalInfo.lCalChangeRemainCnt_R1--;
							}

							RawValue_R1[ucROIC_RowBufIdx[r]][c][g] = tAutoCalInfo.usTemp_RawData;
						}
					}
				}
			}

			tAutoCalInfo.bISAllFinish = YES;

//			uint32_t gR_, gC_, gG;


			for( r=DEF_ROIC_MUX_CR_GROUP_USED_NUM; r--; )
			{
				for( c=DEF_ROIC_NUM; c--; )
				{
					for(g=DEF_ROIC_COL_CR_GROUP_USED_NUM; g--; )
					{
						if(AutoCalfinish_R0[ucROIC_RowBufIdx[r]][c][g] == 0)
						{
							tAutoCalInfo.bISAllFinish = NO;
						}
						if(AutoCalfinish_R1[ucROIC_RowBufIdx[r]][c][g] == 0)
						{
							tAutoCalInfo.bISAllFinish = NO;
						}
					}
				}
			}

//			for( gR_=DEF_ROIC_MUX_CR_GROUP_USED_NUM; gR_--; )
//			{
//				for( gC_=DEF_ROIC_NUM; gC_--; )
//				{
//					for(gG=DEF_ROIC_COL_CR_GROUP_USED_NUM; gG--; )
//					{
//						if(AutoCalfinish_R0[ucROIC_RowBufIdx[gR_]][gC_][gG] == 0)
//						{
//							tAutoCalInfo.bISAllFinish = NO;
//						}
//						if(AutoCalfinish_R1[ucROIC_RowBufIdx[gR_]][gC_][gG] == 0)
//						{
//							tAutoCalInfo.bISAllFinish = NO;
//						}
//					}
//				}
//			}

			if(tAutoCalInfo.bISAllFinish)
			{
				tAutoCalInfo.bIsAutoCalFinish = YES;

				for(r=0; r<DEF_ROIC_MUX_CR_GROUP_USED_NUM; r++)
				{
					ulROIC_Reg_r_Idx = ucROIC_RegIdx_DubleCheck[r];
					ulROIC_Reg_Idx = ucROIC_CRRegIdx[r];
					ulReal_Col = 0;
					for(c=0; c<DEF_ROIC_NUM; c++)
					{
						if(ulROIC_Reg_r_Idx == 0)
						{
							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r], ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r] + DEF_ROIC_MUX_CR_GROUP_MAX_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;

							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r], ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r] + DEF_ROIC_MUX_CR_GROUP_MAX_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;

							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r], ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r] + DEF_ROIC_MUX_CR_GROUP_MAX_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;
						}
						else
						{
							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r], ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r] + DEF_ROIC_MUX_CR_GROUP_MAX_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;

							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r], ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r] + DEF_ROIC_MUX_CR_GROUP_MAX_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;

							sPosTempDiff = g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r], ulReal_Col, sPosTempDiff);
							sPosTempDiff = g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3;
							HAL_WRITE_DELTA_IMAGE(ucROIC_RowBufIdx[r] + DEF_ROIC_MUX_CR_GROUP_MAX_NUM, ulReal_Col, sPosTempDiff);
							ulReal_Col++;
						}
					}
				}
			}
			else
			{
				tAutoCalInfo.Change_CR_Value = 1;
			}

			if(tAutoCalInfo.Change_CR_Value)
			{
				tAutoCalInfo.Change_CR_Value = 0;
				HAL_SetROICRegSetChangeMode(ROIC_REG_SET_CHAGNE_CR_TUNE);
#if USED_ONLY_LOCAL_MODE
			    while(YES)
			    {
					lDataIndex = module_wait_local_sample_done();

					if(lDataIndex == LOCAL_OP_LAST_LHB)
					{
						break;
					}
				}
#else /* USED_ONLY_LOCAL_MODE */
				module_wait_full_sample_done();
#endif /* USED_ONLY_LOCAL_MODE */
			}
#if USED_ONLY_LOCAL_MODE
		    while(YES)
		    {
				lDataIndex = module_wait_local_sample_done();

				if(lDataIndex == LOCAL_OP_LAST_LHB)
				{
					break;
				}
			}
#else /* USED_ONLY_LOCAL_MODE */
			module_wait_full_sample_done();
#endif /* USED_ONLY_LOCAL_MODE */
		}
#elif (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_MANUAL)
		if(Change_CR_Value)
		{
			Change_CR_Value = 0;
			HAL_SetROICRegSetChangeMode(ROIC_REG_SET_CHAGNE_CR_TUNE);
			module_wait_full_sample_done();
		}
#endif /* (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO) */

		if(protocol_swip_GetMode() == M_TOUCH_DFUP)
		{
			break;
		}
	}
}
#endif /* USED_RAWDATA_TUNE_CALIBRATION */

#endif /* (USED_ROIC_DEF == ROIC_SW97500) */

