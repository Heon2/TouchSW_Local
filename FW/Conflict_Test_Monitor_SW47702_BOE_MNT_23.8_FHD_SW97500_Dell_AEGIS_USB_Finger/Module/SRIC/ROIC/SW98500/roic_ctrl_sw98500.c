/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : roic_ctrl_SW98500.c
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
#include "roic_ctrl_SW98500.h"
#include "param_def.h"


#if (USED_ROIC_DEF == ROIC_SW98500)

const tModuleSRICCommonConf_t * s_pktmoduleSRICCommonConf = NULL;

#if USED_ROIC_REGISTER_READ_WRITE_CHECK
uint32_t ulTryCount[6] = {0,};
uint32_t ulFailCount[6] = {0,};
//typedef union {
//	struct
//	{
//		__IO uint32_t cr1_rg1 : 5;
//		__IO uint32_t cr1_rg2 : 5;
//		__IO uint32_t cr1_rg3 : 5;
//	} __PACKED tBit;
//	__IO uint32_t ulBulk;
//} __PACKED tR0_CR1_MUX3_t;
uint32_t R0_CR1_MUX3_ReadBuf[6];

static void SW98500_Reg_Ensurechecking(void)
{
	uint32_t ulMSPIIdx;
	while(1)
	{
		MSPI_RegisterMultiWrite((uint32_t)(0x010C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX3[0].ulBulk);
		memset((void*)&R0_CR1_MUX3_ReadBuf[0], 0x00, (sizeof(uint32_t)*6));
		MSPI_RegisterRead((uint32_t)(0x010C), (uint32_t *)&R0_CR1_MUX3_ReadBuf[0], MSPI_READ_SM0_R0);

		for(ulMSPIIdx=0; ulMSPIIdx<6; ulMSPIIdx++)
		{
			ulTryCount[ulMSPIIdx]++;
			if(s_pktmoduleSRICCommonConf->R0_CR1_MUX3[ulMSPIIdx].ulBulk != R0_CR1_MUX3_ReadBuf[ulMSPIIdx])
			{
				ulFailCount[ulMSPIIdx]++;
			}
		}
		delay_msec(1);
	}
}
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */

static void SW98500_Reg_CRTuneSetting(void)
{
	 MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0108), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX2[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x010C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX3[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0110), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX4[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0114), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX5[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0118), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX6[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x011C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX7[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0120), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX8[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0124), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX9[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0128), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x012C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2[0].ulBulk);

	 MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0134), s_pktmoduleSRICCommonConf->R0_CFGR_TUNE_GROUP.ulBulk);

	 MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0188), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX2[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x018C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX3[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0190), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX4[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0194), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX5[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x0198), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX6[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x019C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX7[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x01A0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX8[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x01A4), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX9[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x01A8), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1[0].ulBulk);
	 MSPI_RegisterMultiWrite((uint32_t)(0x01AC), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2[0].ulBulk);

	 MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01B4), s_pktmoduleSRICCommonConf->R1_CFGR_TUNE_GROUP.ulBulk);

	 MSPI_RegisterWrite((uint32_t)(0x01C4), s_pktmoduleSRICCommonConf->CFGR_TUNE_LOWER.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01C8), s_pktmoduleSRICCommonConf->CFGR_TUNE_UPPER.ulBulk);
}

static void SW98500_Reg_LHBSetting(uint32_t ulType)
{
	 MSPI_RegisterWrite((uint32_t)(0x00A0), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG00[ulType].ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00A4), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG01[ulType].ulBulk);
}

void SW98500_Initialize(void)
{
	s_pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
}

void SW98500_Reset(eSENSING_MODE_t eSensingMode)
{
	GPIO_Init(_GPIO_RSTN_SRIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
	delay_usec(100);

#if !USED_OPERATION_STAND_ALONE
	if(!IS_S3_MODE(eSensingMode))
	{
		while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 1);
		while(IS_GPIO_PIN(_GPIO_TSYNC_IN) == 0);
	}
	delay_usec(10);
#endif /* !USED_OPERATION_STAND_ALONE */
	_gOut(_GPIO_RSTN_SRIC, GPIO_DATA_LOW);
	delay_usec(10);
	_gOut(_GPIO_RSTN_SRIC, GPIO_DATA_HIGH);
	delay_usec(100);
}

#define ROIC_REG_NUM		(196)

bool_t SW98500_RegisterInit(eSENSING_MODE_t eSensingMode)
{
	bool_t bReg = YES;
//	uint32_t ulIdx;
	uint32_t ulBuf[6];
//	uint16_t * pRegVal;

//	while(1)
//	{
//		MSPI_RegisterWrite((uint32_t)(0x0090), s_pktmoduleSRICCommonConf->CFGR_MUX_F_STUCK_VAL.ulBulk);
//		delay_msec(10);
//	}

//	MSPI_RegisterRead(0x400, &ulBuf[0], MSPI_READ_SM0_R0);

//	pRegVal = (uint32_t *)s_pktmoduleSRICCommonConf;
//
//	for (ulIdx = 0; ulIdx < ROIC_REG_NUM; ulIdx++)
//	{
//		MSPI_RegisterWrite((uint32_t)((ulIdx<<1) + 0x400), pRegVal[ulIdx]);
//	}
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
	SW98500_Reg_Ensurechecking();
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */


	MSPI_RegisterWrite((uint32_t)(0x01D0), s_pktmoduleSRICCommonConf->SYS_DUMMY0.ulBulk);
	MSPI_RegisterRead(0x01D0, &ulBuf[0], MSPI_READ_SM0_R0);
	MSPI_RegisterRead(0, &ulBuf[0], MSPI_READ_SM0_R0);


//	MSPI_RegisterWrite((uint32_t)(0x0000), s_pktmoduleSRICCommonConf->CFGR_PRODUCT_ID.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0004), s_pktmoduleSRICCommonConf->SPIS_CFG.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0008), s_pktmoduleSRICCommonConf->SPIS_ERROR_CLR.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x000C), s_pktmoduleSRICCommonConf->SPIS_ERROR_ST.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0010), s_pktmoduleSRICCommonConf->SPIS_PAD_CTL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0014), s_pktmoduleSRICCommonConf->CFGR_SYS_CFG.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0018), s_pktmoduleSRICCommonConf->CFGR_TC_START.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x001C), s_pktmoduleSRICCommonConf->CFGR_TC_STOP.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0020), s_pktmoduleSRICCommonConf->CFGR_R0_CH_EN.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0024), s_pktmoduleSRICCommonConf->CFGR_R1_CH_EN.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0028), s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x002C), s_pktmoduleSRICCommonConf->CFGR_MUX_DLY.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0030), s_pktmoduleSRICCommonConf->CFGR_DIC_CFG.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->CFGR_PWM_CTL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0038), s_pktmoduleSRICCommonConf->CFGR_PWM_POS_CTL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x003C), s_pktmoduleSRICCommonConf->CFGR_PWM_DAT_CTL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0040), s_pktmoduleSRICCommonConf->ND_CTRL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0044), s_pktmoduleSRICCommonConf->CFGR_PWM_PRD.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->CFGR_SMPL_CTL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x004C), s_pktmoduleSRICCommonConf->CFGR_RSTP_NUM1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0050), s_pktmoduleSRICCommonConf->CFGR_PHTCR_NUM1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0054), s_pktmoduleSRICCommonConf->CFGR_PHTCR_NUM2.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0058), s_pktmoduleSRICCommonConf->CFGR_VCR_NUM1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x005C), s_pktmoduleSRICCommonConf->CFGR_RSTI_NUM1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0060), s_pktmoduleSRICCommonConf->CFGR_RSTI_NUM2.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0064), s_pktmoduleSRICCommonConf->CFGR_PHTH0_NUM1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0068), s_pktmoduleSRICCommonConf->CFGR_PHTH1_NUM1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x006C), s_pktmoduleSRICCommonConf->CFGR_PHTH_NUM2.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0070), s_pktmoduleSRICCommonConf->CFGR_PHT_CTL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0074), s_pktmoduleSRICCommonConf->CFGR_PHT_NUM1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0078), s_pktmoduleSRICCommonConf->CFGR_ADC_CTRL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x007C), s_pktmoduleSRICCommonConf->CFGR_VCOMR_OPT.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0080), s_pktmoduleSRICCommonConf->CFGR_BUF_OPT.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0084), s_pktmoduleSRICCommonConf->CFGR_TG_STUCK.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0088), s_pktmoduleSRICCommonConf->CFGR_ADC_IN.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x008C), s_pktmoduleSRICCommonConf->CFGR_MUX_S_STUCK_VAL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0090), s_pktmoduleSRICCommonConf->CFGR_MUX_F_STUCK_VAL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0094), s_pktmoduleSRICCommonConf->CFGR_MUX_CFG_00.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0098), s_pktmoduleSRICCommonConf->CFGR_MUX_CFG_01.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x009C), s_pktmoduleSRICCommonConf->RCOM_LHB_CFG.ulBulk);

	if(IS_FINGER_PEN_MODE(eSensingMode))
	{
		SW98500_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);
	}
	else
	{
		SW98500_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
	}
//	 MSPI_RegisterWrite((uint32_t)(0x00A0), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG00.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x00A4), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG01.ulBulk);

	 MSPI_RegisterWrite((uint32_t)(0x00A8), s_pktmoduleSRICCommonConf->CFGR_FG_LHB_CFG.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00AC), s_pktmoduleSRICCommonConf->CFGR_PP_LHB_CFG.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00B0), s_pktmoduleSRICCommonConf->CFGR_PD_LHB_CFG.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00B4), s_pktmoduleSRICCommonConf->CFGR_MUX_FCTL_NUM.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00B8), s_pktmoduleSRICCommonConf->CFGR_UPLINK_MUX0.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00BC), s_pktmoduleSRICCommonConf->CFGR_UPLINK_MUX1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00C0), s_pktmoduleSRICCommonConf->CFGR_ND_PHTCR.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00C4), s_pktmoduleSRICCommonConf->CFGR_ND_PWM.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00C8), s_pktmoduleSRICCommonConf->CFGR_ND_PHTH.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00DC), s_pktmoduleSRICCommonConf->CFGR_LHB_MUX_CTRL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00E0), s_pktmoduleSRICCommonConf->CFGR_PING_MUX_CTRL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00E4), s_pktmoduleSRICCommonConf->CFGR_PRE_DRV_CTRL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00F0), s_pktmoduleSRICCommonConf->SD_PWRCR1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00F4), s_pktmoduleSRICCommonConf->SD_PWRCR2.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00F8), s_pktmoduleSRICCommonConf->SD_PWRCR3.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00FC), s_pktmoduleSRICCommonConf->SD_PWRCR4.ulBulk);

//	 MSPI_RegisterWrite((uint32_t)(0x0100), s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0104), s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0108), s_pktmoduleSRICCommonConf->R0_CR1_MUX2.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x010C), s_pktmoduleSRICCommonConf->R0_CR1_MUX3.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0110), s_pktmoduleSRICCommonConf->R0_CR1_MUX4.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0114), s_pktmoduleSRICCommonConf->R0_CR1_MUX5.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0118), s_pktmoduleSRICCommonConf->R0_CR1_MUX6.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x011C), s_pktmoduleSRICCommonConf->R0_CR1_MUX7.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0120), s_pktmoduleSRICCommonConf->R0_CR1_MUX8.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0124), s_pktmoduleSRICCommonConf->R0_CR1_MUX9.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0128), s_pktmoduleSRICCommonConf->R0_CR1_MUX10_1.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x012C), s_pktmoduleSRICCommonConf->R0_CR1_MUX10_2.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0130), s_pktmoduleSRICCommonConf->R0_CR_GTUNE.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0134), s_pktmoduleSRICCommonConf->R0_CFGR_TUNE_GROUP.ulBulk);


	 MSPI_RegisterWrite((uint32_t)(0x0140), s_pktmoduleSRICCommonConf->CFGR_R0_RAW_CTRL1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0144), s_pktmoduleSRICCommonConf->CFGR_R0_RAW_CTRL2.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x0148), s_pktmoduleSRICCommonConf->CFGR_R1_RAW_CTRL1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x014C), s_pktmoduleSRICCommonConf->CFGR_R1_RAW_CTRL2.ulBulk);


//	 MSPI_RegisterWrite((uint32_t)(0x0180), s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0184), s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0188), s_pktmoduleSRICCommonConf->R1_CR1_MUX2.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x018C), s_pktmoduleSRICCommonConf->R1_CR1_MUX3.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0190), s_pktmoduleSRICCommonConf->R1_CR1_MUX4.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0194), s_pktmoduleSRICCommonConf->R1_CR1_MUX5.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x0198), s_pktmoduleSRICCommonConf->R1_CR1_MUX6.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x019C), s_pktmoduleSRICCommonConf->R1_CR1_MUX7.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x01A0), s_pktmoduleSRICCommonConf->R1_CR1_MUX8.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x01A4), s_pktmoduleSRICCommonConf->R1_CR1_MUX9.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x01A8), s_pktmoduleSRICCommonConf->R1_CR1_MUX10_1.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x01AC), s_pktmoduleSRICCommonConf->R1_CR1_MUX10_2.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x01B0), s_pktmoduleSRICCommonConf->R1_CR_GTUNE.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x01B4), s_pktmoduleSRICCommonConf->R1_CFGR_TUNE_GROUP.ulBulk);

	 SW98500_Reg_CRTuneSetting();
	 MSPI_RegisterWrite((uint32_t)(0x01B8), s_pktmoduleSRICCommonConf->CFGR_SENSE_CTRL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01BC), s_pktmoduleSRICCommonConf->CFGR_COMP_ADC_CTRL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01C0), s_pktmoduleSRICCommonConf->CFGR_SSU_PW_CTRL.ulBulk);

//	 MSPI_RegisterWrite((uint32_t)(0x01C4), s_pktmoduleSRICCommonConf->CFGR_TUNE_LOWER.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x01C8), s_pktmoduleSRICCommonConf->CFGR_TUNE_UPPER.ulBulk);

	 MSPI_RegisterWrite((uint32_t)(0x01CC), s_pktmoduleSRICCommonConf->TAFE_REV_SIG.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x01D0), s_pktmoduleSRICCommonConf->SYS_DUMMY0.ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x01D4), s_pktmoduleSRICCommonConf->SYS_DUMMY1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01D8), s_pktmoduleSRICCommonConf->CFGR_COMP_CTRL.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01DC), s_pktmoduleSRICCommonConf->CFGR_COMP_CTRL2.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01E0), s_pktmoduleSRICCommonConf->CFGR_COMP_RSTI_NUM.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01E4), s_pktmoduleSRICCommonConf->CFGR_COMP_WINDOW_1.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01E8), s_pktmoduleSRICCommonConf->CFGR_COMP_WINDOW_2.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01EC), s_pktmoduleSRICCommonConf->COMP_STATUS.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01F0), s_pktmoduleSRICCommonConf->CFGR_SENSE_CTRL_2.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x01F4), s_pktmoduleSRICCommonConf->CFGR_MON_CTRL.ulBulk);


// Control
//	MSPI_RegisterWrite((uint32_t)(0x00A0), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG00.ulBulk);
//	MSPI_RegisterWrite((uint32_t)(0x00FC), s_pktmoduleSRICCommonConf->SD_PWRCR4.ulBulk);	
//	MSPI_RegisterWrite((uint32_t)(0x0010), s_pktmoduleSRICCommonConf->SPIS_PAD_CTL.ulBulk);

	// MSPI_RegisterRead(0, &ulBuf[0], MSPI_READ_SM0_R0);

    MSPI_RegisterRead(0, &ulBuf[0], MSPI_READ_SM0_R0);

    return bReg;
}

void SW98500_Run(uint8_t Enable)
{
	tCFGR_TC_START_t tCFGR_TC_START;
	tCFGR_SYS_CFG_t tCFGR_SYS_CFG;
	tCFGR_TC_START.ulBulk = 0;
	tCFGR_TC_START.tBit.tc_start = Enable;
	MSPI_RegisterWrite((uint32_t)(0x018), tCFGR_TC_START.ulBulk);

	tCFGR_SYS_CFG.ulBulk = s_pktmoduleSRICCommonConf->CFGR_SYS_CFG.ulBulk;
	tCFGR_SYS_CFG.tBit.tg_reset = 1;
	MSPI_RegisterWrite((uint32_t)(0x0014), tCFGR_SYS_CFG.ulBulk);
	tCFGR_SYS_CFG.tBit.tg_reset = 0;
	MSPI_RegisterWrite((uint32_t)(0x0014), tCFGR_SYS_CFG.ulBulk);
}

#ifdef TILT_ON
extern __IO uint16_t sensingRowStart_Tilt;
extern int8_t sensingRowStart_Tilt_Offset;
#endif /* TILT_ON */
void SW98500_SetLocalIndex(uint32_t ulIdx)
{
 	uint32_t ulLocalIndex;
 	uint32_t ulMSPIIndex;
	tCFGR_PP_LHB_CFG_t tCHFG_PP_LHB_CFG;
	tCFGR_PD_LHB_CFG_t tCHFG_PD_LHB_CFG;

 	ulLocalIndex = (uint32_t)((ulIdx)&(0xFFFF));
 	ulMSPIIndex = (uint32_t)((ulIdx)>>16);

	tHalIntrHandle.ulLocalSensingDoneRowIdx = ulLocalIndex;
	tCHFG_PD_LHB_CFG.ulBulk = s_pktmoduleSRICCommonConf->CFGR_PD_LHB_CFG.ulBulk;
	tCHFG_PD_LHB_CFG.tBit.pd_mux_cfg0 = ulLocalIndex;
	MSPI_RegisterWrite((uint32_t)(0x00B0), tCHFG_PD_LHB_CFG.ulBulk);

#ifdef TILT_ON
 	if(ulMSPIIndex == 0)
 	{
 		tCHFG_PP_LHB_CFG.ulBulk = s_pktmoduleSRICCommonConf->CFGR_PP_LHB_CFG.ulBulk;
 		tCHFG_PP_LHB_CFG.tBit.pp_mux_cfg0 = sensingRowStart_Tilt;
 		tCHFG_PP_LHB_CFG.tBit.pp_mux_cfg1 = sensingRowStart_Tilt;
 		MSPI_RegisterWrite((uint32_t)(0x00AC), tCHFG_PP_LHB_CFG.ulBulk);
		tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt = MAX(0,MIN(ROW_MAX-PEN_COORD_ROW_MAX,(int)(ulLocalIndex + sensingRowStart_Tilt_Offset)));
 		//tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt;
 	}
#endif /* TILT_ON */
}

void SW98500_SetIdleOperationMode(void)
{
//	if((PARAMSET_PWMDRV_TSYNC_IDLE_BITMASK & 0x1) && 0x1)
//	{
//		tCFGR_PEN_POS1_t tCFGR_PEN_POS1;
//		tCFGR_PEN_POS1.ulBulk = s_pktmoduleSRICCommonConf->CFGR_PEN_POS1.ulBulk;
//		tCFGR_PEN_POS1.tBit.lhb_type = 1; // Finger2
//		MSPI_RegisterWrite(0x406, tCFGR_PEN_POS1.ulBulk);
//	}
//
////	tCFGR_LHB_CFG1_t tCFGR_LHB_CFG1;
////	tCFGR_LHB_CFG1.ulBulk = s_pktmoduleSRICCommonConf->CFGR_LHB_CFG1.ulBulk;
////	tCFGR_LHB_CFG1.tBit.md2_lhb_mux = 1;
////	MSPI_RegisterWrite(0x49E, tCFGR_LHB_CFG1.ulBulk);
//
//	tCFGR_LHB_CFG2_t tCFGR_LHB_CFG2;
//	tCFGR_LHB_CFG2.ulBulk = s_pktmoduleSRICCommonConf->CFGR_LHB_CFG2.ulBulk;
//	tCFGR_LHB_CFG2.tBit.end_mux_num = 1;
//	MSPI_RegisterWrite(0x4A0, tCFGR_LHB_CFG2.ulBulk);
	
//	uint16_t tCFGR_MD2_MUX_SEL1;
//	tCFGR_MD2_MUX_SEL1 = 0x0FFF;
//	MSPI_RegisterWrite(0x484, tCFGR_MD2_MUX_SEL1);
}

void SW98500_SetActiveOperationMode(void)
{
//	if((PARAMSET_PWMDRV_TSYNC_ACTIVE_BITMASK & 0x1) && 0x1)
//	{
//		tCFGR_PEN_POS1_t tCFGR_PEN_POS1;
//		tCFGR_PEN_POS1.ulBulk = s_pktmoduleSRICCommonConf->CFGR_PEN_POS1.ulBulk;
//		tCFGR_PEN_POS1.tBit.lhb_type = 0; // Finger2
//		MSPI_RegisterWrite(0x406, tCFGR_PEN_POS1.ulBulk);
//	}
//
//	tCFGR_LHB_CFG2_t tCFGR_LHB_CFG2;
//	tCFGR_LHB_CFG2.ulBulk = s_pktmoduleSRICCommonConf->CFGR_LHB_CFG2.ulBulk;
//	tCFGR_LHB_CFG2.tBit.end_mux_num = 0xC;
//	MSPI_RegisterWrite(0x4A0, tCFGR_LHB_CFG2.ulBulk);
}

//void SW98500_SetFingerPenFullModeChange(bool_t bIsFullMode)
//{
//	if(bIsFullMode)
//	{
//		SW98500_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
//	}
//	else
//	{
//		SW98500_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);
//	}
//}

#if (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL)
tR0_CR_GTUNE_t R0_Idle_CR_GTUNE[6] =
{
	[0] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_0_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_0_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_0_R0_CR_GTUNE_PenData_Global_Tune,
	},
	[1] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_1_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_1_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_1_R0_CR_GTUNE_PenData_Global_Tune,
	},
	[2] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_2_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_2_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_2_R0_CR_GTUNE_PenData_Global_Tune,
	},
	[3] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_3_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_3_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_3_R0_CR_GTUNE_PenData_Global_Tune,
	},
	[4] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_4_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_4_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_4_R0_CR_GTUNE_PenData_Global_Tune,
	},
	[5] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_5_R0_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_5_R0_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_5_R0_CR_GTUNE_PenData_Global_Tune,
	},
};

tR1_CR_GTUNE_t R1_Idle_CR_GTUNE[6] =
{
	[0] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_0_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_0_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_0_R1_CR_GTUNE_PenData_Global_Tune,
	},
	[1] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_1_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_1_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_1_R1_CR_GTUNE_PenData_Global_Tune,
	},
	[2] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_2_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_2_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_2_R1_CR_GTUNE_PenData_Global_Tune,
	},
	[3] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_3_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_3_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_3_R1_CR_GTUNE_PenData_Global_Tune,
	},
	[4] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_4_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_4_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_4_R1_CR_GTUNE_PenData_Global_Tune,
	},
	[5] = {
		.tBit.cr_fg_gtune = PARAMSET_IDLE_ROIC_5_R1_CR_GTUNE_Finger_Global_Tune,
		.tBit.cr_pn_gtune = PARAMSET_IDLE_ROIC_5_R1_CR_GTUNE_PenPos_Global_Tune,
		.tBit.cr_pd_gtune = PARAMSET_IDLE_ROIC_5_R1_CR_GTUNE_PenData_Global_Tune,
	},
};

tR0_CR1_MUX1_1_t R0_Idle_CR1_MUX1_1[6] =
{
	[0] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Middle_Line_g3,
	},
	[1] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Middle_Line_g3,
	},
	[2] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Middle_Line_g3,
	},
	[3] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Middle_Line_g3,
	},
	[4] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Middle_Line_g3,
	},
	[5] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Middle_Line_g3,
	},
};
tR0_CR1_MUX1_2_t R0_Idle_CR1_MUX1_2[6] =
{
	[0] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_0_R0_1stMux_Bottom_Line_g3,
	},
	[1] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_1_R0_1stMux_Bottom_Line_g3,
	},
	[2] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_2_R0_1stMux_Bottom_Line_g3,
	},
	[3] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_3_R0_1stMux_Bottom_Line_g3,
	},
	[4] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_4_R0_1stMux_Bottom_Line_g3,
	},
	[5] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_5_R0_1stMux_Bottom_Line_g3,
	},
};
tR1_CR1_MUX1_1_t R1_Idle_CR1_MUX1_1[6] =
{
	[0] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Middle_Line_g3,
	},
	[1] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Middle_Line_g3,
	},
	[2] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Middle_Line_g3,
	},
	[3] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Middle_Line_g3,
	},
	[4] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Middle_Line_g3,
	},
	[5] = {
		.tBit.cr1_r1g1 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Top_Line_g1,
		.tBit.cr1_r1g2 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Top_Line_g2,
		.tBit.cr1_r1g3 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Top_Line_g3,
		.tBit.cr1_r2g1 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Middle_Line_g1,
		.tBit.cr1_r2g2 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Middle_Line_g2,
		.tBit.cr1_r2g3 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Middle_Line_g3,
	},
};
tR1_CR1_MUX1_2_t R1_Idle_CR1_MUX1_2[6] =
{
	[0] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_0_R1_1stMux_Bottom_Line_g3,
	},
	[1] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_1_R1_1stMux_Bottom_Line_g3,
	},
	[2] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_2_R1_1stMux_Bottom_Line_g3,
	},
	[3] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_3_R1_1stMux_Bottom_Line_g3,
	},
	[4] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_4_R1_1stMux_Bottom_Line_g3,
	},
	[5] = {
		.tBit.cr1_r3g1 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Bottom_Line_g1,
		.tBit.cr1_r3g2 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Bottom_Line_g2,
		.tBit.cr1_r3g3 = PARAMSET_IDLE_ROIC_5_R1_1stMux_Bottom_Line_g3,
	},
};

tCFGR_PWM_CTL_t CFGR_Idle_PWM_CTL =
{
	.tBit.pwm_pdrv_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_pdrv_num,
	.tBit.pwm_act_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_act_num,
	.tBit.pwm_mgap_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_mgap_num,
	.tBit.pwm_dum_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_dum_num,
	.tBit.pwm_set_num = PARAMSET_ROIC_PWM_IDLE_CTL_pwm_set_num,
};

tCFGR_MUX_CFG_00_t CFGR_Idle_MUX_CFG_00 =
{
	.tBit.MUX_00 = 0xE, // 0xD : Odd (CR 3Mux), 0xE : Even, 0xF : All
	.tBit.MUX_01 = 0xE,
	.tBit.MUX_02 = 0,
	.tBit.MUX_03 = 0,
	.tBit.MUX_04 = 0,
	.tBit.MUX_05 = 0,
	.tBit.MUX_06 = 0,
	.tBit.MUX_07 = 0,
};

tCFGR_MUX_EN_t CFGR_Idle_MUX_EN =
{
	.tBit.mux_int_en = 0,
	.tBit.mux_num_tot = 1,
};

tCFGR_FG_LHB_CFG_t CFGR_Idle_FG_LHB_CFG =
{
	.tBit.lhbmuxnum = 1,
};

//tCFGR_PEN_MUX_BIT_EN_t CFGR_PEN_IDLE_MUX_BIT_EN =
//{
//	.tBit.mux_beacon_bit_en = PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_beacon_bit_en,
//	.tBit.mux_pen_pos_bit_en = PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_pen_pos_bit_en,
//	.tBit.mux_pen_dat_bit_en = PARAMSET_ROIC_IDLE_PEN_MUX_BIT_EN_mux_pen_dat_bit_en,
//};
#endif /* (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL) */

void SW98500_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
	switch(eMode)
	{
		case ROIC_REG_SET_CHANGE_MUX_REMAP:
		{
			break;
		}
		case ROIC_REG_SET_CHAGNE_CR_TUNE:
		{
			SW98500_Reg_CRTuneSetting();
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
		case ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_ACTIVE:
		{
			SW98500_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);

#if (USED_LOCAL_IDLE_MODE_CONTROL)
			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);

//			MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[0].ulBulk);

			MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->CFGR_PWM_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0094), s_pktmoduleSRICCommonConf->CFGR_MUX_CFG_00.ulBulk);

			MSPI_RegisterWrite((uint32_t)(0x0028), s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x00A8), s_pktmoduleSRICCommonConf->CFGR_FG_LHB_CFG.ulBulk);
//			MSPI_RegisterWrite((uint32_t)(0x00EC), CFGR_PEN_IDLE_MUX_BIT_EN.ulBulk);
#endif /* (USED_LOCAL_IDLE_MODE_CONTROL) */
			break;
		}
#if (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL)
		case ROIC_REG_SET_CHANGE_FINGER_PEN_FULL_IDLE:
		case ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_IDLE:
		{
			SW98500_Reg_LHBSetting(PWM_LOCAL_PEN_IDLE_MODE);

			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&R0_Idle_CR_GTUNE[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&R1_Idle_CR_GTUNE[0].ulBulk);

//			MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&R0_Idle_CR1_MUX1_1[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&R0_Idle_CR1_MUX1_2[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&R1_Idle_CR1_MUX1_1[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&R1_Idle_CR1_MUX1_2[0].ulBulk);

			MSPI_RegisterWrite((uint32_t)(0x0034), CFGR_Idle_PWM_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0094), CFGR_Idle_MUX_CFG_00.ulBulk);

			MSPI_RegisterWrite((uint32_t)(0x0028), CFGR_Idle_MUX_EN.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x00A8), CFGR_Idle_FG_LHB_CFG.ulBulk);
//			MSPI_RegisterWrite((uint32_t)(0x00EC), CFGR_PEN_IDLE_MUX_BIT_EN.ulBulk);
			break;
		}
#endif /* (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL) */
		case ROIC_REG_SET_CHANGE_FINGER_PEN_FULL:
		{
			SW98500_Reg_LHBSetting(PWM_FULL_FINGER_MODE);
#if (USED_IDLE_MODE_CONTROL)
			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);

//			MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[0].ulBulk);
//			MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[0].ulBulk);

			MSPI_RegisterWrite((uint32_t)(0x0028), s_pktmoduleSRICCommonConf->CFGR_MUX_EN.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x00A8), s_pktmoduleSRICCommonConf->CFGR_FG_LHB_CFG.ulBulk);

			MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->CFGR_PWM_CTL.ulBulk);
//			MSPI_RegisterWrite((uint32_t)(0x00EC), CFGR_PEN_IDLE_MUX_BIT_EN.ulBulk);
#endif /* (USED_IDLE_MODE_CONTROL) */
			break;
		}
	}
}

#if USED_RAWDATA_TUNE_CALIBRATION
#define DEF_ROIC_LOCAL_CR_TUNE_REG_NUM	(12)
#define DEF_ROIC_MUX_CR_GROUP_MAX_NUM	(14)
#define DEF_ROIC_COL_CR_GROUP_MAX_NUM	(3)
#define DEF_ROIC_NUM				(6)//(MSPI_NUM)

#define DEF_ROIC_MUX_CR_GROUP_USED_NUM	(10)
#define DEF_ROIC_COL_CR_GROUP_USED_NUM	(3)

bool_t bIsAutoCalFinish = NO;
uint32_t ulTestFrameNum = 0;
uint32_t ulTestCountNum = 0;

uint32_t RawValue_sum_R0[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];
uint32_t RawValue_sum_R1[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];
uint8_t RawSumCnt_R0[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];
uint8_t RawSumCnt_R1[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];

uint16_t RawValue_R0[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];
uint16_t RawValue_R1[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];

uint8_t AutoCalfinish_R0[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];
uint8_t AutoCalfinish_R1[DEF_ROIC_MUX_CR_GROUP_MAX_NUM][DEF_ROIC_NUM][DEF_ROIC_COL_CR_GROUP_MAX_NUM];



uint8_t ucROIC_RegIdx_DubleCheck[DEF_ROIC_MUX_CR_GROUP_MAX_NUM] = {
	0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
};
uint8_t ucROIC_CRRegIdx[DEF_ROIC_MUX_CR_GROUP_MAX_NUM] = {
	0, 0, 1, 2, 3, 4, 5, 10, 10, 11
};
uint8_t ucROIC_RowBufIdx[DEF_ROIC_MUX_CR_GROUP_MAX_NUM] = {
	0, 1, 2, 3, 4, 5, 6, 11, 12, 13
};


uint8_t ulCRIndex[ROW_MAX] = {
	/*1 Mux*/0,1,2,2,2,2,2,2,2,
	/*2 Mux*/3,3,3,3,3,3,3,3,3,
	/*3 Mux*/4,4,4,4,4,4,4,4,4,
	/*4 Mux*/5,5,5,5,5,5,5,5,5,
	/*5 Mux*/6,6,6,6,6,6,6,6,6,
	/*6 Mux*/11,12,13,
};

#if RAWDATA_TUNE_RO_R1_SWAP
uint8_t ulMSPIIndex[COL_MAX] = {
	/*SRIC_0*/	/*R1*/6,	6,	6,	6,	6,	6,	6,    /*R0*/0,	0,	0,	0,	0,	0,	0,
	/*SRIC_1*/	/*R1*/7,	7,	7,	7,	7,	7,	7,    /*R0*/1,	1,	1,	1,	1,	1,	1,
	/*SRIC_2*/	/*R1*/8,	8,	8,	8,	8,	8,	8,    /*R0*/2,	2,	2,	2,	2,	2,	2,
	/*SRIC_3*/	/*R1*/9,	9,	9,	9,	9,	9,	9,    /*R0*/3,	3,	3,	3,	3,	3,	3,
	/*SRIC_4*/	/*R1*/10,	10,	10,	10,	10,	10,	10,   /*R0*/4,	4,	4,	4,	4,	4,	4,
	/*SRIC_5*/	/*R1*/11,	11,	11,	11,	11,	11,	11,   /*R0*/5,	5,	5,	5,	5,	5,	5,
};

#else /* RAWDATA_TUNE_RO_R1_SWAP */
uint8_t ulMSPIIndex[COL_MAX] = {
	/*SRIC_0*/ /*R0*/0,	0,	0,	0,	0,	0,	0,	/*R1*/6,	6,	6,	6,	6,	6,	6,
	/*SRIC_1*/ /*R0*/1,	1,	1,	1,	1,	1,	1,	/*R1*/7,	7,	7,	7,	7,	7,	7,
	/*SRIC_2*/ /*R0*/2,	2,	2,	2,	2,	2,	2,	/*R1*/8,	8,	8,	8,	8,	8,	8,
	/*SRIC_3*/ /*R0*/3,	3,	3,	3,	3,	3,	3,	/*R1*/9,	9,	9,	9,	9,	9,	9,
	/*SRIC_4*/ /*R0*/4,	4,	4,	4,	4,	4,	4,	/*R1*/10,	10,	10,	10,	10,	10,	10,
	/*SRIC_5*/ /*R0*/5,	5,	5,	5,	5,	5,	5,	/*R1*/11,	11,	11,	11,	11,	11,	11,
};

#endif /* RAWDATA_TUNE_RO_R1_SWAP */
uint8_t ulROIC_gNum[COL_MAX] = {
	/* Group Idx */ /*R0*/0,	1,	2,	2,	2,	1,	0,	/*R1*/0,	1,	2,	2,	2,	1,	0,
	/* Group Idx */ /*R0*/0,	1,	2,	2,	2,	1,	0,	/*R1*/0,	1,	2,	2,	2,	1,	0,
	/* Group Idx */ /*R0*/0,	1,	2,	2,	2,	1,	0,	/*R1*/0,	1,	2,	2,	2,	1,	0,
	/* Group Idx */ /*R0*/0,	1,	2,	2,	2,	1,	0,	/*R1*/0,	1,	2,	2,	2,	1,	0,
	/* Group Idx */ /*R0*/0,	1,	2,	2,	2,	1,	0,	/*R1*/0,	1,	2,	2,	2,	1,	0,
	/* Group Idx */ /*R0*/0,	1,	2,	2,	2,	1,	0,	/*R1*/0,	1,	2,	2,	2,	1,	0,
};

uint32_t Change_CR_Value = 0;
uint32_t auto_Cal_Start = 0;

uint32_t auto_Cal_MiddleStart = 0;

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
}__PACKED tSW98500_ROIC_CR_MUX_t;

extern tParamPreMainSet_t * s_ptParamPreMainSet;
tModuleSRICCommonConf_t * g_ptSRICConfig;

tSW98500_ROIC_CR_MUX_t * g_pR0_CR_MUX_Tune;
tSW98500_ROIC_CR_MUX_t * g_pR1_CR_MUX_Tune;
bool_t bISAllFinish = NO;
uint16_t usTemp_RawData;

#define AUTO_CAL_AVERAGE_FRAME_NUM			(100)
void SW98500_RawDataCalibration(void)
{
	bool_t bIsLoop = YES;
	uint32_t r, c, g, framenum;
	uint32_t ulReal_Col;
	uint32_t ulROIC_Reg_r_Idx;
	uint32_t ulROIC_Reg_Idx;
	uint32_t temp_data;
	int16_t sPosTempDiff;
	int16_t sNegTempDiff;
#if USED_ONLY_LOCAL_MODE
	ePartialSensing_t lDataIndex = PARTIAL_PEN_BEACON;
#endif /* USED_ONLY_LOCAL_MODE */

	g_ptSRICConfig = (tModuleSRICCommonConf_t *)&(s_ptParamPreMainSet->tParamCommonConf.tModule.tSRIC_Conf);
	g_pR0_CR_MUX_Tune = (tSW98500_ROIC_CR_MUX_t *)&g_ptSRICConfig->R0_CR1_MUX1_1[0].ulBulk;
	g_pR1_CR_MUX_Tune = (tSW98500_ROIC_CR_MUX_t *)&g_ptSRICConfig->R1_CR1_MUX1_1[0].ulBulk;

	memset((void*)(&AutoCalfinish_R0[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_MUX_CR_GROUP_MAX_NUM*DEF_ROIC_NUM*DEF_ROIC_COL_CR_GROUP_MAX_NUM);
	memset((void*)(&AutoCalfinish_R1[0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_MUX_CR_GROUP_MAX_NUM*DEF_ROIC_NUM*DEF_ROIC_COL_CR_GROUP_MAX_NUM);

    tHalIntrHandle.ulLocalIndexChangeStart = 1;
#if (USED_ONLY_LOCAL_MODE == NO)
	if(IS_FINGER_PEN_MODE(HAL_GetSensingMode()))
	{
		HAL_SetSensingChangeMode(SM_CHANGE_FINGER_PEN_SEARCH_MODE);
	}
#endif /* (USED_ONLY_LOCAL_MODE == NO) */

#if (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO)
	memset((void*)(&g_pR0_CR_MUX_Tune[0]), 0, sizeof(uint32_t)*DEF_ROIC_LOCAL_CR_TUNE_REG_NUM*DEF_ROIC_NUM);
	memset((void*)(&g_pR0_CR_MUX_Tune[0]), 0, sizeof(uint32_t)*DEF_ROIC_LOCAL_CR_TUNE_REG_NUM*DEF_ROIC_NUM);

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

		protocol_LogMatrix(LT_RAWDATA, 84, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);
		protocol_LogPaddedMatrix(LT_INTENSITY, 84, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);

#if (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO)
		if(bIsAutoCalFinish == NO)
		{
			ulTestCountNum++;
			/*
			 * RawData Sum
			 */
			memset((void*)(HAL_GET_COMMON_IMAGE_PTR()), 0, sizeof(uint32_t)*COL_MAX*ROW_MAX);

			ulTestFrameNum = 0;
			for(framenum = 0; framenum < AUTO_CAL_AVERAGE_FRAME_NUM; framenum++)
			{
				ulTestFrameNum++;
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
					temp_data = HAL_READ_COMMON_IMAGE(r, c) / ulTestFrameNum;
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
							usTemp_RawData = (uint16_t)(RawValue_sum_R0[ucROIC_RowBufIdx[r]][c][g]/RawSumCnt_R0[ucROIC_RowBufIdx[r]][c][g]);

							if(RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL < usTemp_RawData)
							{
								switch(g)
								{
									case 0:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1 += 1;
										}
										else
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1 += 1;
										}
										break;
									}
									case 1:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2 += 1;
										}
										else
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2 += 1;
										}
										break;
									}
									case 2:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3 += 1;
										}
										else
										{
											g_pR0_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3 += 1;
										}
										break;
									}
								}
							}
							else
							{
								sNegTempDiff = RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL - (int16_t)usTemp_RawData;
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
							}

							RawValue_R0[ucROIC_RowBufIdx[r]][c][g] = usTemp_RawData;
						}

						if(AutoCalfinish_R1[ucROIC_RowBufIdx[r]][c][g] == 0)
						{
							usTemp_RawData = (uint16_t)(RawValue_sum_R1[ucROIC_RowBufIdx[r]][c][g]/RawSumCnt_R1[ucROIC_RowBufIdx[r]][c][g]);
							if(RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL < usTemp_RawData)
							{
								switch(g)
								{
									case 0:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g1 += 1;
										}
										else
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g1 += 1;
										}
										break;
									}
									case 1:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g2 += 1;
										}
										else
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g2 += 1;
										}
										break;
									}
									case 2:
									{
										if(ulROIC_Reg_r_Idx == 0)
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r1g3 += 1;
										}
										else
										{
											g_pR1_CR_MUX_Tune[c + (ulROIC_Reg_Idx * DEF_ROIC_NUM)].tBit.cr1_r2g3 += 1;
										}
										break;
									}
								}
							}
							else
							{
								sNegTempDiff = RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL - usTemp_RawData;
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
							}

							RawValue_R1[ucROIC_RowBufIdx[r]][c][g] = usTemp_RawData;
						}
					}
				}
			}

			bISAllFinish = YES;
			for( r=DEF_ROIC_MUX_CR_GROUP_USED_NUM; r--; )
			{
				for( c=DEF_ROIC_NUM; c--; )
				{
					for(g=DEF_ROIC_COL_CR_GROUP_USED_NUM; g--; )
					{
						if(AutoCalfinish_R0[ucROIC_RowBufIdx[r]][c][g] == 0)
						{
							bISAllFinish = NO;
						}
						if(AutoCalfinish_R1[ucROIC_RowBufIdx[r]][c][g] == 0)
						{
							bISAllFinish = NO;
						}
					}
				}
			}

			if(bISAllFinish)
			{
				bIsAutoCalFinish = YES;

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
				Change_CR_Value = 1;
			}

			if(Change_CR_Value)
			{
				Change_CR_Value = 0;
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


#endif /* (USED_ROIC_DEF == ROIC_SW98500) */
