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
#include "roic_ctrl_SW98502.h"
#include "param_def.h"


#if (USED_ROIC_DEF == ROIC_SW98502)

const tModuleSRICCommonConf_t * s_pktmoduleSRICCommonConf = NULL;

static void SW98502_Reg_CRTuneSetting(void)
{
	MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX1_1[0].ulBulk);  // R/W
	MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX1_2[0].ulBulk);  // R/W
	MSPI_RegisterMultiWrite((uint32_t)(0x0108), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX2_1[0].ulBulk);  // R/W
	MSPI_RegisterMultiWrite((uint32_t)(0x010C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX2_2[0].ulBulk);  // R/W
	MSPI_RegisterMultiWrite((uint32_t)(0x0110), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX3_1[0].ulBulk);  // R/W
	MSPI_RegisterMultiWrite((uint32_t)(0x0114), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX3_2[0].ulBulk);  // R/W
	MSPI_RegisterMultiWrite((uint32_t)(0x0118), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX4_1[0].ulBulk);  // R/W
	MSPI_RegisterMultiWrite((uint32_t)(0x011C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX4_2[0].ulBulk);  // R/W
	MSPI_RegisterMultiWrite((uint32_t)(0x0120), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX5_1[0].ulBulk);  // R/W
	MSPI_RegisterMultiWrite((uint32_t)(0x0124), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX5_2[0].ulBulk);  // R/W
	MSPI_RegisterMultiWrite((uint32_t)(0x0128), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX6_1[0].ulBulk);  // R/W
	MSPI_RegisterMultiWrite((uint32_t)(0x012C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_MUX6_2[0].ulBulk);  // R/W

	MSPI_RegisterMultiWrite((uint32_t)(0x0134), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX1_1[0].ulBulk);  // R/W
    MSPI_RegisterMultiWrite((uint32_t)(0x0138), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX1_2[0].ulBulk);  // R/W
    MSPI_RegisterMultiWrite((uint32_t)(0x013C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX2_1[0].ulBulk);  // R/W
    MSPI_RegisterMultiWrite((uint32_t)(0x0140), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX2_2[0].ulBulk);  // R/W
    MSPI_RegisterMultiWrite((uint32_t)(0x0144), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX3_1[0].ulBulk);  // R/W
    MSPI_RegisterMultiWrite((uint32_t)(0x0148), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX3_2[0].ulBulk);  // R/W
    MSPI_RegisterMultiWrite((uint32_t)(0x014C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX4_1[0].ulBulk);  // R/W
    MSPI_RegisterMultiWrite((uint32_t)(0x0150), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX4_2[0].ulBulk);  // R/W
    MSPI_RegisterMultiWrite((uint32_t)(0x0154), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX5_1[0].ulBulk);  // R/W
    MSPI_RegisterMultiWrite((uint32_t)(0x0158), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX5_2[0].ulBulk);  // R/W
    MSPI_RegisterMultiWrite((uint32_t)(0x015C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX6_1[0].ulBulk);  // R/W
    MSPI_RegisterMultiWrite((uint32_t)(0x0160), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_MUX6_2[0].ulBulk);  // R/W

    MSPI_RegisterMultiWrite((uint32_t)(0x016C), (uint32_t *)&s_pktmoduleSRICCommonConf->R_CR_GTUNE[0].ulBulk);  // R/W

	MSPI_RegisterWrite((uint32_t)(0x0180), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0184), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0188), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX3.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x018C), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX4.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0190), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX5.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0194), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX6.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0198), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX1.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x019C), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX2.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x01A0), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX3.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x01A4), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX4.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x01A8), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX5.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x01AC), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX6.ulBulk);  // R/W
    MSPI_RegisterWrite((uint32_t)(0x01B0), s_pktmoduleSRICCommonConf->R_TUNE_GROUP_COL.ulBulk);  // R/W
}

static void SW98502_Reg_LHBSetting(uint32_t ulType)
{
//	 MSPI_RegisterWrite((uint32_t)(0x00A0), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG00[ulType].ulBulk);
//	 MSPI_RegisterWrite((uint32_t)(0x00A4), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG01[ulType].ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00C4), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG00.ulBulk);
	 MSPI_RegisterWrite((uint32_t)(0x00C8), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG01.ulBulk);
}

void SW98502_Initialize(void)
{
	s_pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
}

void SW98502_Reset(eSENSING_MODE_t eSensingMode)
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

#if USED_ROIC_REGISTER_READ_WRITE_CHECK
tModuleSRICCommonConf_t ulTestRegReadCheckBuf;
uint32_t ulTestReadBuf[6];
bool_t bIsTestReadFali = NO;
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
bool_t SW98502_RegisterInit(eSENSING_MODE_t eSensingMode)
{
	bool_t bReg = YES;

#if USED_ROIC_REGISTER_READ_WRITE_CHECK
	uint32_t ulIdx;
	memset((void*)&ulTestRegReadCheckBuf, 0x00, sizeof(tModuleSRICCommonConf_t));
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */

#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    MSPI_RegisterRead((uint32_t)(0x0000), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */

//    MSPI_RegisterWrite((uint32_t)(0x0000), s_pktmoduleSRICCommonConf->PRODUCT_ID.ulBulk               );  // R
    MSPI_RegisterWrite((uint32_t)(0x0004), s_pktmoduleSRICCommonConf->SPIS_CFG.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0004), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SPIS_CFG.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SPIS_CFG.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0008), s_pktmoduleSRICCommonConf->SPIS_ERROR_CLR.ulBulk           );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x000C), s_pktmoduleSRICCommonConf->SPIS_ERROR_ST.ulBulk            );  // R
    MSPI_RegisterWrite((uint32_t)(0x0010), s_pktmoduleSRICCommonConf->SPIS_PAD_CTL.ulBulk             );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0010), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SPIS_PAD_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SPIS_PAD_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0014), s_pktmoduleSRICCommonConf->SYS_CFG.ulBulk                  );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0014), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SYS_CFG.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SYS_CFG.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0018), s_pktmoduleSRICCommonConf->TC_START.ulBulk                 );  // R/W
    MSPI_RegisterWrite((uint32_t)(0x001C), s_pktmoduleSRICCommonConf->R0_CH_EN.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x001C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->R0_CH_EN.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.R0_CH_EN.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0020), s_pktmoduleSRICCommonConf->R1_CH_EN.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0020), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->R1_CH_EN.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.R1_CH_EN.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0024), s_pktmoduleSRICCommonConf->CH_NUM.ulBulk                   );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0024), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->CH_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.CH_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0028), s_pktmoduleSRICCommonConf->MUX_CTL.ulBulk                  );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0028), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->MUX_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.MUX_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x002C), s_pktmoduleSRICCommonConf->MUX_DLY_0.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x002C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->MUX_DLY_0.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.MUX_DLY_0.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0030), s_pktmoduleSRICCommonConf->MUX_DLY_1.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0030), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->MUX_DLY_1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.MUX_DLY_1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->MUX_DLY_2.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0034), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->MUX_DLY_2.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.MUX_DLY_2.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0038), s_pktmoduleSRICCommonConf->SDIC_CFG.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0038), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SDIC_CFG.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SDIC_CFG.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x003C), s_pktmoduleSRICCommonConf->PWM_FIG_CTL.ulBulk              );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x003C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PWM_FIG_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PWM_FIG_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0040), s_pktmoduleSRICCommonConf->PWM_POS_CTL.ulBulk              );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0040), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PWM_POS_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PWM_POS_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0044), s_pktmoduleSRICCommonConf->PWM_DAT_CTL.ulBulk              );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0044), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PWM_DAT_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PWM_DAT_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->PWM_ND_CTL.ulBulk               );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0048), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PWM_ND_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PWM_ND_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x004C), s_pktmoduleSRICCommonConf->PWM_PRD.ulBulk                  );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x004C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PWM_PRD.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PWM_PRD.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0050), s_pktmoduleSRICCommonConf->SMPL_CTL.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0050), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SMPL_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SMPL_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0054), s_pktmoduleSRICCommonConf->RSTP_RISE_NUM.ulBulk            );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0054), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->RSTP_RISE_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.RSTP_RISE_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0058), s_pktmoduleSRICCommonConf->RSTP_FALL_NUM1.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0058), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->RSTP_FALL_NUM1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.RSTP_FALL_NUM1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x005C), s_pktmoduleSRICCommonConf->RSTP_FALL_NUM2.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x005C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->RSTP_FALL_NUM2.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.RSTP_FALL_NUM2.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
//    MSPI_RegisterWrite((uint32_t)(0x0060), s_pktmoduleSRICCommonConf->PHTCR_RISE_NUM.ulBulk           );  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0060), s_pktmoduleSRICCommonConf->PHTCR_RISE_NUM.ulBulk           );  // R/W	
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0060), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHTCR_RISE_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHTCR_RISE_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0064), s_pktmoduleSRICCommonConf->PHTCR_FALL_NUM.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0064), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHTCR_FALL_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHTCR_FALL_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0068), s_pktmoduleSRICCommonConf->VCR_NUM.ulBulk                  );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0068), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->VCR_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.VCR_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x006C), s_pktmoduleSRICCommonConf->RSTI_RISE_NUM.ulBulk            );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x006C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->RSTI_RISE_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.RSTI_RISE_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0070), s_pktmoduleSRICCommonConf->RSTI_FALL_NUM1.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0070), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->RSTI_FALL_NUM1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.RSTI_FALL_NUM1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0074), s_pktmoduleSRICCommonConf->RSTI_FALL_NUM2.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0074), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->RSTI_FALL_NUM2.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.RSTI_FALL_NUM2.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0078), s_pktmoduleSRICCommonConf->PHTH0_RISE_NUM.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0078), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHTH0_RISE_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHTH0_RISE_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x007C), s_pktmoduleSRICCommonConf->PHTH0_FALL_NUM.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x007C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHTH0_FALL_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHTH0_FALL_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0080), s_pktmoduleSRICCommonConf->PHTH1_RISE_NUM.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0080), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHTH1_RISE_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHTH1_RISE_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0084), s_pktmoduleSRICCommonConf->PHTH1_FALL_NUM.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0084), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHTH1_FALL_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHTH1_FALL_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0088), s_pktmoduleSRICCommonConf->PHT_CTL.ulBulk                  );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0088), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHT_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHT_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x008C), s_pktmoduleSRICCommonConf->PHT_RISE_NUM.ulBulk             );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x008C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHT_RISE_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHT_RISE_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0090), s_pktmoduleSRICCommonConf->PHT_FALL_NUM.ulBulk             );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0090), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHT_FALL_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHT_FALL_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0094), s_pktmoduleSRICCommonConf->ADC_CTL1.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0094), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->ADC_CTL1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.ADC_CTL1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0098), s_pktmoduleSRICCommonConf->ADC_CTL2.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0098), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->ADC_CTL2.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.ADC_CTL2.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x009C), s_pktmoduleSRICCommonConf->ADC_CTL3.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x009C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->ADC_CTL3.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.ADC_CTL3.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00A0), s_pktmoduleSRICCommonConf->VCOMR_OPT.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00A0), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->VCOMR_OPT.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.VCOMR_OPT.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00A4), s_pktmoduleSRICCommonConf->BUF_OPT.ulBulk                  );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00A4), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->BUF_OPT.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.BUF_OPT.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00A8), s_pktmoduleSRICCommonConf->TG_STUCK.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00A8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->TG_STUCK.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.TG_STUCK.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
//    MSPI_RegisterRead((uint32_t)(0x00A8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    MSPI_RegisterWrite((uint32_t)(0x00AC), s_pktmoduleSRICCommonConf->ADC_IN.ulBulk                   );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00AC), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->ADC_IN.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.ADC_IN.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00B0), s_pktmoduleSRICCommonConf->MUX_S_STUCK_VAL.ulBulk          );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00B0), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->MUX_S_STUCK_VAL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.MUX_S_STUCK_VAL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00B4), s_pktmoduleSRICCommonConf->MUX_F_STUCK_VAL.ulBulk          );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00B4), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->MUX_F_STUCK_VAL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.MUX_F_STUCK_VAL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00B8), s_pktmoduleSRICCommonConf->FIG_MUX_CFG_00.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00B8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->FIG_MUX_CFG_00.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.FIG_MUX_CFG_00.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00BC), s_pktmoduleSRICCommonConf->FIG_MUX_CFG_01.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00BC), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->FIG_MUX_CFG_01.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.FIG_MUX_CFG_01.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00C0), s_pktmoduleSRICCommonConf->RCOM_LHB_CFG.ulBulk             );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00C0), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->RCOM_LHB_CFG.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.RCOM_LHB_CFG.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00C4), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG00.ulBulk          );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00C4), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG00.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.DEFA_LHB_MCFG00.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00C8), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG01.ulBulk          );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00C8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG01.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.DEFA_LHB_MCFG01.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00CC), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG02.ulBulk          );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00CC), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG02.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.DEFA_LHB_MCFG02.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00D0), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG03.ulBulk          );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00D0), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG03.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.DEFA_LHB_MCFG03.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00D4), s_pktmoduleSRICCommonConf->LHB_MUX_NUM.ulBulk              );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00D4), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->LHB_MUX_NUM.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.LHB_MUX_NUM.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00D8), s_pktmoduleSRICCommonConf->PEN_POS1_LHB_CFG.ulBulk         );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00D8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PEN_POS1_LHB_CFG.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PEN_POS1_LHB_CFG.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00DC), s_pktmoduleSRICCommonConf->PEN_POS2_LHB_CFG.ulBulk         );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00DC), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PEN_POS2_LHB_CFG.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PEN_POS2_LHB_CFG.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00E0), s_pktmoduleSRICCommonConf->PEN_DAT1_LHB_CFG.ulBulk         );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00E0), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PEN_DAT1_LHB_CFG.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PEN_DAT1_LHB_CFG.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00E4), s_pktmoduleSRICCommonConf->PEN_DAT2_LHB_CFG.ulBulk         );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00E4), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PEN_DAT2_LHB_CFG.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PEN_DAT2_LHB_CFG.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00E8), s_pktmoduleSRICCommonConf->MUX_FCTL_NUM1.ulBulk            );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00E8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->MUX_FCTL_NUM1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.MUX_FCTL_NUM1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00EC), s_pktmoduleSRICCommonConf->MUX_FCTL_NUM2.ulBulk            );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00EC), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->MUX_FCTL_NUM2.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.MUX_FCTL_NUM2.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00F0), s_pktmoduleSRICCommonConf->UPLINK_MUX.ulBulk               );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00F0), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->UPLINK_MUX.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.UPLINK_MUX.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00F4), s_pktmoduleSRICCommonConf->LHB_MUX_CTL.ulBulk              );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00F4), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->LHB_MUX_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.LHB_MUX_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00F8), s_pktmoduleSRICCommonConf->PING_MUX_CTL.ulBulk             );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00F8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PING_MUX_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PING_MUX_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x00FC), s_pktmoduleSRICCommonConf->PRE_DRV_CTL.ulBulk              );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x00FC), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PRE_DRV_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PRE_DRV_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */

    SW98502_Reg_CRTuneSetting();
//    MSPI_RegisterWrite((uint32_t)(0x0100), s_pktmoduleSRICCommonConf->R0_CR_MUX1_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0104), s_pktmoduleSRICCommonConf->R0_CR_MUX1_2.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0108), s_pktmoduleSRICCommonConf->R0_CR_MUX2_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x010C), s_pktmoduleSRICCommonConf->R0_CR_MUX2_2.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0110), s_pktmoduleSRICCommonConf->R0_CR_MUX3_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0114), s_pktmoduleSRICCommonConf->R0_CR_MUX3_2.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0118), s_pktmoduleSRICCommonConf->R0_CR_MUX4_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x011C), s_pktmoduleSRICCommonConf->R0_CR_MUX4_2.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0120), s_pktmoduleSRICCommonConf->R0_CR_MUX5_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0124), s_pktmoduleSRICCommonConf->R0_CR_MUX5_2.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0128), s_pktmoduleSRICCommonConf->R0_CR_MUX6_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x012C), s_pktmoduleSRICCommonConf->R0_CR_MUX6_2.ulBulk             );  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0130), s_pktmoduleSRICCommonConf->R0_CR_M1.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0130), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->R0_CR_M1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.R0_CR_M1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
//    MSPI_RegisterWrite((uint32_t)(0x0134), s_pktmoduleSRICCommonConf->R1_CR_MUX1_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0138), s_pktmoduleSRICCommonConf->R1_CR_MUX1_2.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x013C), s_pktmoduleSRICCommonConf->R1_CR_MUX2_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0140), s_pktmoduleSRICCommonConf->R1_CR_MUX2_2.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0144), s_pktmoduleSRICCommonConf->R1_CR_MUX3_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0148), s_pktmoduleSRICCommonConf->R1_CR_MUX3_2.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x014C), s_pktmoduleSRICCommonConf->R1_CR_MUX4_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0150), s_pktmoduleSRICCommonConf->R1_CR_MUX4_2.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0154), s_pktmoduleSRICCommonConf->R1_CR_MUX5_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0158), s_pktmoduleSRICCommonConf->R1_CR_MUX5_2.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x015C), s_pktmoduleSRICCommonConf->R1_CR_MUX6_1.ulBulk             );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0160), s_pktmoduleSRICCommonConf->R1_CR_MUX6_2.ulBulk             );  // R/W
    MSPI_RegisterWrite((uint32_t)(0x0164), s_pktmoduleSRICCommonConf->R1_CR_M1.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0164), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->R1_CR_M1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.R1_CR_M1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0168), s_pktmoduleSRICCommonConf->R_CR_ND.ulBulk                  );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0168), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->R_CR_ND.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.R_CR_ND.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
//    MSPI_RegisterWrite((uint32_t)(0x016C), s_pktmoduleSRICCommonConf->R_CR_GTUNE.ulBulk               );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0170), s_pktmoduleSRICCommonConf->RESERVED_1.ulBulk               );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0174), s_pktmoduleSRICCommonConf->RESERVED_2.ulBulk               );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0178), s_pktmoduleSRICCommonConf->RESERVED_3.ulBulk               );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x017C), s_pktmoduleSRICCommonConf->RESERVED_4.ulBulk               );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0180), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX1.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0184), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX2.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0188), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX3.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x018C), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX4.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0190), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX5.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0194), s_pktmoduleSRICCommonConf->R0_TUNE_ROW_MUX6.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x0198), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX1.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x019C), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX2.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x01A0), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX3.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x01A4), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX4.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x01A8), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX5.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x01AC), s_pktmoduleSRICCommonConf->R1_TUNE_ROW_MUX6.ulBulk         );  // R/W
//    MSPI_RegisterWrite((uint32_t)(0x01B0), s_pktmoduleSRICCommonConf->R_TUNE_GROUP_COL.ulBulk         );  // R/W

    MSPI_RegisterWrite((uint32_t)(0x01B4), s_pktmoduleSRICCommonConf->SD_PWRCR1.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01B4), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SD_PWRCR1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SD_PWRCR1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01B8), s_pktmoduleSRICCommonConf->SD_PWRCR2.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01B8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SD_PWRCR2.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SD_PWRCR2.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01BC), s_pktmoduleSRICCommonConf->SD_PWRCR3.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01BC), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SD_PWRCR3.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SD_PWRCR3.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01C0), s_pktmoduleSRICCommonConf->SD_PWRCR4.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01C0), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SD_PWRCR4.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SD_PWRCR4.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01C4), s_pktmoduleSRICCommonConf->SD_PWRCR5.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01C4), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SD_PWRCR5.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SD_PWRCR5.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01C8), s_pktmoduleSRICCommonConf->SD_PWRCR6.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01C8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SD_PWRCR6.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SD_PWRCR6.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01CC), s_pktmoduleSRICCommonConf->SD_PWRCR7.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01CC), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SD_PWRCR7.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SD_PWRCR7.ulBulk = 0xFFFFFFFF;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01D0), s_pktmoduleSRICCommonConf->AFE_SENSE_CTL1.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01D0), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->AFE_SENSE_CTL1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.AFE_SENSE_CTL1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01D4), s_pktmoduleSRICCommonConf->AFE_SENSE_CTL2.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01D4), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->AFE_SENSE_CTL2.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.AFE_SENSE_CTL2.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01D8), s_pktmoduleSRICCommonConf->AFE_SENSE_CTL3.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01D8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->AFE_SENSE_CTL3.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.AFE_SENSE_CTL3.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01DC), s_pktmoduleSRICCommonConf->PHD_SENSE_CTL1.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01DC), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHD_SENSE_CTL1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHD_SENSE_CTL1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01E0), s_pktmoduleSRICCommonConf->PHD_SENSE_CTL2.ulBulk           );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01E0), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHD_SENSE_CTL2.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHD_SENSE_CTL2.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01E4), s_pktmoduleSRICCommonConf->ADC_SENSE_CTL.ulBulk            );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01E4), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->ADC_SENSE_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.ADC_SENSE_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01E8), s_pktmoduleSRICCommonConf->PDB_CTL.ulBulk                  );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01E8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PDB_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PDB_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
 //   MSPI_RegisterRead((uint32_t)(0x01E8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    MSPI_RegisterWrite((uint32_t)(0x01EC), s_pktmoduleSRICCommonConf->PDB_PHD_CTL.ulBulk              );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01EC), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PDB_PHD_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PDB_PHD_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01F0), s_pktmoduleSRICCommonConf->ADC_IN_SHIFT_CTL1.ulBulk        );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01F0), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->ADC_IN_SHIFT_CTL1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.ADC_IN_SHIFT_CTL1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01F4), s_pktmoduleSRICCommonConf->ADC_IN_SHIFT_CTL2.ulBulk        );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01F4), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->ADC_IN_SHIFT_CTL2.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.ADC_IN_SHIFT_CTL2.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01F8), s_pktmoduleSRICCommonConf->R_RESERVE.ulBulk                );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01F8), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->R_RESERVE.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.R_RESERVE.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x01FC), s_pktmoduleSRICCommonConf->SYS_DUMMY0.ulBulk               );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x01FC), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SYS_DUMMY0.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SYS_DUMMY0.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0200), s_pktmoduleSRICCommonConf->SYS_DUMMY1.ulBulk               );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0200), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->SYS_DUMMY1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.SYS_DUMMY1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0204), s_pktmoduleSRICCommonConf->TEST_MUX_CTL.ulBulk             );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0204), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->TEST_MUX_CTL.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.TEST_MUX_CTL.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0208), s_pktmoduleSRICCommonConf->PHD_CTL1.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0208), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHD_CTL1.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHD_CTL1.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x020C), s_pktmoduleSRICCommonConf->PHD_CTL2.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x020C), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHD_CTL2.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHD_CTL2.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
    MSPI_RegisterWrite((uint32_t)(0x0210), s_pktmoduleSRICCommonConf->PHD_CTL3.ulBulk                 );  // R/W
#if USED_ROIC_REGISTER_READ_WRITE_CHECK
    memset((void*)&ulTestReadBuf[0], 0x00, (sizeof(uint32_t)*6));
    MSPI_RegisterRead((uint32_t)(0x0210), (uint32_t *)&ulTestReadBuf[0], MSPI_READ_SM0_R0);
    for(ulIdx = 0; ulIdx < MSPI_NUM; ulIdx++)
    {
    	if(s_pktmoduleSRICCommonConf->PHD_CTL3.ulBulk != ulTestReadBuf[ulIdx])
    	{
    		ulTestRegReadCheckBuf.PHD_CTL3.ulBulk = 0xFFFFFFFF;
    		bIsTestReadFali = YES;
    	}
    }
#endif /* USED_ROIC_REGISTER_READ_WRITE_CHECK */
 //   MSPI_RegisterWrite((uint32_t)(0x0214), s_pktmoduleSRICCommonConf->PHD_CTL4.ulBulk                 );  // R/W
 //   MSPI_RegisterWrite((uint32_t)(0x0218), s_pktmoduleSRICCommonConf->PHD_ST1.ulBulk                  );  // R
 //   MSPI_RegisterWrite((uint32_t)(0x021C), s_pktmoduleSRICCommonConf->PHD_ST2.ulBulk                  );  // R
 //   MSPI_RegisterWrite((uint32_t)(0x0220), s_pktmoduleSRICCommonConf->PHD_ST3 .ulBulk                 );  // R
 //   MSPI_RegisterWrite((uint32_t)(0x0224), s_pktmoduleSRICCommonConf->MON_R0_ADCDO.ulBulk             );  // R
 //   MSPI_RegisterWrite((uint32_t)(0x0228), s_pktmoduleSRICCommonConf->MON_R1_ADCDO.ulBulk             );  // R
 //   MSPI_RegisterWrite((uint32_t)(0x07F4), s_pktmoduleSRICCommonConf->MON_CAL_DELAY.ulBulk            );  // R
 //   MSPI_RegisterWrite((uint32_t)(0x07F8), s_pktmoduleSRICCommonConf->MON_EDGE_SIGN_R0.ulBulk         );  // R
 //   MSPI_RegisterWrite((uint32_t)(0x07FC), s_pktmoduleSRICCommonConf->MON_EDGE_SIGN_R1.ulBulk         );  // R

    return bReg;
}

void SW98502_Run(uint8_t Enable)
{
	tTC_START_t tCFGR_TC_START;
	tSYS_CFG_t tCFGR_SYS_CFG;
	tCFGR_TC_START.ulBulk = 0;
	tCFGR_TC_START.tBit.tc_start = Enable;
	MSPI_RegisterWrite((uint32_t)(0x018), tCFGR_TC_START.ulBulk);

	tCFGR_SYS_CFG.ulBulk = s_pktmoduleSRICCommonConf->SYS_CFG.ulBulk;
	tCFGR_SYS_CFG.tBit.tg_reset = 1;
	MSPI_RegisterWrite((uint32_t)(0x0014), tCFGR_SYS_CFG.ulBulk);
	tCFGR_SYS_CFG.tBit.tg_reset = 0;
	MSPI_RegisterWrite((uint32_t)(0x0014), tCFGR_SYS_CFG.ulBulk);
}

#ifdef TILT_ON
extern __IO uint16_t sensingRowStart_Tilt;
extern int8_t sensingRowStart_Tilt_Offset;
#endif /* TILT_ON */
void SW98502_SetLocalIndex(uint32_t ulIdx)
{
 	uint32_t ulLocalIndex;
 	uint32_t ulMSPIIndex;
 	tPEN_POS1_LHB_CFG_t tCHFG_PP_LHB_CFG;
 	tPEN_DAT1_LHB_CFG_t tCHFG_PD_LHB_CFG;

 	ulLocalIndex = (uint32_t)((ulIdx)&(0xFFFF));
 	ulMSPIIndex = (uint32_t)((ulIdx)>>16);

	tHalIntrHandle.ulLocalSensingDoneRowIdx = ulLocalIndex;
	tCHFG_PD_LHB_CFG.ulBulk = s_pktmoduleSRICCommonConf->PEN_DAT1_LHB_CFG.ulBulk;
	tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg0 = ulLocalIndex;
	tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg1 = ulLocalIndex;
	tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg2 = ulLocalIndex;
	tCHFG_PD_LHB_CFG.tBit.pen_dat1_mux_cfg3 = ulLocalIndex;
	MSPI_RegisterWrite((uint32_t)(0x00E0), tCHFG_PD_LHB_CFG.ulBulk);

#ifdef TILT_ON
 	if(ulMSPIIndex == 0)
 	{
		tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt = MAX(0,MIN(ROW_MAX-PEN_COORD_ROW_MAX,(int)(ulLocalIndex + sensingRowStart_Tilt_Offset)));
 		tCHFG_PP_LHB_CFG.ulBulk = s_pktmoduleSRICCommonConf->PEN_POS1_LHB_CFG.ulBulk;
 		tCHFG_PP_LHB_CFG.tBit.pen_pos1_mux_cfg0 = sensingRowStart_Tilt;
 		tCHFG_PP_LHB_CFG.tBit.pen_pos1_mux_cfg1 = sensingRowStart_Tilt;
 		MSPI_RegisterWrite((uint32_t)(0x00D8), tCHFG_PP_LHB_CFG.ulBulk);
		//tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt = MAX(0,MIN(ROW_MAX-PEN_COORD_ROW_MAX,(int)(ulLocalIndex + sensingRowStart_Tilt_Offset)));
 		//tHalIntrHandle.ulLocalSensingDoneRowIdx_Tilt = sensingRowStart_Tilt;
 	}
#endif /* TILT_ON */
}

void SW98502_SetIdleOperationMode(void)
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

void SW98502_SetActiveOperationMode(void)
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

void SW98502_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
	switch(eMode)
	{
		case ROIC_REG_SET_CHANGE_MUX_REMAP:
		{
			break;
		}
		case ROIC_REG_SET_CHAGNE_CR_TUNE:
		{
			SW98502_Reg_CRTuneSetting();
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
#if USED_PEN_MODE_OPERATION
		case ROIC_REG_SET_CHANGE_Full_To_Local:
		{
			SW98502_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);

			break;
		}
		case ROIC_REG_SET_CHANGE_Local_To_Full:
		{
			SW98502_Reg_LHBSetting(PWM_FULL_FINGER_MODE);

			break;
		}
#endif /* USED_PEN_MODE_OPERATION */
#if USED_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_Full_To_FullIdle:
		{
			SW98502_Reg_LHBSetting(PWM_FULL_FINGER_IDLE_MODE);

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
#endif /* USED_IDLE_MODE_CONTROL */
#if USED_LOCAL_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_Local_To_LocalIdle:
		{
			SW98502_Reg_LHBSetting(PWM_LOCAL_PEN_IDLE_MODE);

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
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
#if USED_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_FullIdle_To_Full:
		{
			SW98502_Reg_LHBSetting(PWM_FULL_FINGER_MODE);

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
			break;
		}
#endif /* USED_IDLE_MODE_CONTROL */
#if USED_LOCAL_IDLE_MODE_CONTROL
		case ROIC_REG_SET_CHANGE_LocalIdle_To_Local:
		{
			SW98502_Reg_LHBSetting(PWM_LOCAL_PEN_MODE);

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
			break;
		}
		case ROIC_REG_SET_CHANGE_LocalIdle_To_Full:
		{
			SW98502_Reg_LHBSetting(PWM_FULL_FINGER_MODE);

			MSPI_RegisterMultiWrite((uint32_t)(0x0130), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x01B0), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE[0].ulBulk);

			MSPI_RegisterMultiWrite((uint32_t)(0x0100), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_1[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0104), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR1_MUX1_2[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0180), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_1[0].ulBulk);
			MSPI_RegisterMultiWrite((uint32_t)(0x0184), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR1_MUX1_2[0].ulBulk);

			MSPI_RegisterWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->CFGR_PWM_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x0038), s_pktmoduleSRICCommonConf->CFGR_PWM_POS_CTL.ulBulk);
			MSPI_RegisterWrite((uint32_t)(0x00EC), s_pktmoduleSRICCommonConf->CFGR_PEN_MUX_BIT_EN.ulBulk);

			break;
		}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
#if USED_NOISE_HOPPING_FREQ
		case ROIC_REG_SET_FreHopp_CHANGE_Main_Freq:
		{
			break;
		}
		case ROIC_REG_SET_FreHopp_CHANGE_Hopp1_Freq:
		{
			break;
		}
#endif /* USED_NOISE_HOPPING_FREQ */
	}
}

#if USED_RAWDATA_TUNE_CALIBRATION
#define DEF_ROIC_MAX_NUM				(6)//(MSPI_NUM)
#define DEF_MUX_MAX_NUM					(6)//(MSPI_NUM)
#define DEF_ROW_CR_GROUP_NUM			(3)//(MSPI_NUM)
#define DEF_COL_CR_GROUP_NUM			(3)//(MSPI_NUM)
#define DEF_LINE_MAX_NUM_1_MUX			(9)
#define DEF_CR_REG_MAX_NUM				(2 * DEF_MUX_MAX_NUM)

#define DEF_USED_ROIC_NUM				(6)
#define DEF_USED_MUX_NUM				(6)
#define DEF_USED_LINE_NUM_1_MUX			(9)

bool_t bIsAutoCalFinish = NO;
uint32_t ulTestFrameNum = 0;
uint32_t ulTestCountNum = 0;

uint32_t RawValue_Sum_R0[DEF_ROIC_MAX_NUM][DEF_MUX_MAX_NUM][DEF_ROW_CR_GROUP_NUM][DEF_COL_CR_GROUP_NUM];
uint32_t RawValue_Sum_R1[DEF_ROIC_MAX_NUM][DEF_MUX_MAX_NUM][DEF_ROW_CR_GROUP_NUM][DEF_COL_CR_GROUP_NUM];
uint8_t RawSumCnt_R0[DEF_ROIC_MAX_NUM][DEF_MUX_MAX_NUM][DEF_ROW_CR_GROUP_NUM][DEF_COL_CR_GROUP_NUM];
uint8_t RawSumCnt_R1[DEF_ROIC_MAX_NUM][DEF_MUX_MAX_NUM][DEF_ROW_CR_GROUP_NUM][DEF_COL_CR_GROUP_NUM];
uint8_t AutoCalfinish_R0[DEF_ROIC_MAX_NUM][DEF_MUX_MAX_NUM][DEF_ROW_CR_GROUP_NUM][DEF_COL_CR_GROUP_NUM];
uint8_t AutoCalfinish_R1[DEF_ROIC_MAX_NUM][DEF_MUX_MAX_NUM][DEF_ROW_CR_GROUP_NUM][DEF_COL_CR_GROUP_NUM];
uint16_t PastRawValueR0[DEF_ROIC_MAX_NUM][DEF_MUX_MAX_NUM][DEF_ROW_CR_GROUP_NUM][DEF_COL_CR_GROUP_NUM];
uint16_t PastRawValueR1[DEF_ROIC_MAX_NUM][DEF_MUX_MAX_NUM][DEF_ROW_CR_GROUP_NUM][DEF_COL_CR_GROUP_NUM];


uint32_t ulCR_Reg_Row_MuxIdx[ROW_MAX] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0,	/* 1Mux */
	1, 1, 1, 1, 1, 1, 1, 1, 1,	/* 2Mux */
	2, 2, 2, 2, 2, 2, 2, 2, 2,	/* 3Mux */
	3, 3, 3, 3, 3, 3, 3, 3, 3,	/* 4Mux */
	4, 4, 4, 4, 4, 4, 4, 4, 4,	/* 5Mux */
	5, 5, 5						/* 6Mux */
};

uint32_t ulCR_Reg_Row_GroupIdx[ROW_MAX] = {
	0, 1, 1, 1, 1, 1, 1, 1, 2,	/* 1Mux */
	0, 1, 1, 1, 1, 1, 1, 1, 2,	/* 2Mux */
	0, 1, 1, 1, 1, 1, 1, 1, 2,	/* 3Mux */
	0, 1, 1, 1, 1, 1, 1, 1, 2,	/* 4Mux */
	0, 1, 1, 1, 1, 1, 1, 1, 2,	/* 5Mux */
	0, 1, 2						/* 6Mux */
};

uint32_t ulCR_Reg_Col_GroupIdx[COL_MAX] = {
	0, 1, 1, 1, 1, 1, 2,	/* SRIC 1 R0 */
	2, 1, 1, 1, 1, 1, 0,	/* SRIC 1 R1 */
	0, 1, 1, 1, 1, 1, 2,	/* SRIC 2 R0 */
	2, 1, 1, 1, 1, 1, 0,	/* SRIC 2 R1 */
	0, 1, 1, 1, 1, 1, 2,	/* SRIC 3 R0 */
	2, 1, 1, 1, 1, 1, 0,	/* SRIC 3 R1 */
	0, 1, 1, 1, 1, 1, 2,	/* SRIC 4 R0 */
	2, 1, 1, 1, 1, 1, 0,	/* SRIC 4 R1 */
	0, 1, 1, 1, 1, 1, 2,	/* SRIC 5 R0 */
	2, 1, 1, 1, 1, 1, 0,	/* SRIC 5 R1 */
	0, 1, 1, 1, 1, 1, 2,	/* SRIC 6 R0 */
	2, 1, 1, 1, 1, 1, 0,	/* SRIC 6 R1 */
};

#if RAWDATA_TUNE_RO_R1_SWAP
uint32_t ulMSPIIndex[COL_MAX] = {
	/*SRIC_0*/	/*R1*/6,	6,	6,	6,	6,	6,	6,    /*R0*/0,	0,	0,	0,	0,	0,	0,
	/*SRIC_1*/	/*R1*/7,	7,	7,	7,	7,	7,	7,    /*R0*/1,	1,	1,	1,	1,	1,	1,
	/*SRIC_2*/	/*R1*/8,	8,	8,	8,	8,	8,	8,    /*R0*/2,	2,	2,	2,	2,	2,	2,
	/*SRIC_3*/	/*R1*/9,	9,	9,	9,	9,	9,	9,    /*R0*/3,	3,	3,	3,	3,	3,	3,
	/*SRIC_4*/	/*R1*/10,	10,	10,	10,	10,	10,	10,   /*R0*/4,	4,	4,	4,	4,	4,	4,
	/*SRIC_5*/	/*R1*/11,	11,	11,	11,	11,	11,	11,   /*R0*/5,	5,	5,	5,	5,	5,	5,
};

#else /* RAWDATA_TUNE_RO_R1_SWAP */
uint32_t ulMSPIIndex[COL_MAX] = {
	/*SRIC_0*/ /*R0*/0,	0,	0,	0,	0,	0,	0,	/*R1*/6,	6,	6,	6,	6,	6,	6,
	/*SRIC_1*/ /*R0*/1,	1,	1,	1,	1,	1,	1,	/*R1*/7,	7,	7,	7,	7,	7,	7,
	/*SRIC_2*/ /*R0*/2,	2,	2,	2,	2,	2,	2,	/*R1*/8,	8,	8,	8,	8,	8,	8,
	/*SRIC_3*/ /*R0*/3,	3,	3,	3,	3,	3,	3,	/*R1*/9,	9,	9,	9,	9,	9,	9,
	/*SRIC_4*/ /*R0*/4,	4,	4,	4,	4,	4,	4,	/*R1*/10,	10,	10,	10,	10,	10,	10,
	/*SRIC_5*/ /*R0*/5,	5,	5,	5,	5,	5,	5,	/*R1*/11,	11,	11,	11,	11,	11,	11,
};

#endif /* RAWDATA_TUNE_RO_R1_SWAP */

uint32_t Change_CR_Value = 0;
uint32_t auto_Cal_Start = 0;

typedef union
{
	union
	{
		struct
		{
			__IO uint32_t cr1_r1g1: 5;
			__IO uint32_t cr1_r1g2: 5;
			__IO uint32_t cr1_r1g3: 5;
			__IO uint32_t cr1_r2g1: 5;
			__IO uint32_t cr1_r2g2: 5;
			__IO uint32_t cr1_r2g3: 5;
		}__PACKED t1;

		struct
		{
			__IO uint32_t cr1_r3g1: 5;
			__IO uint32_t cr1_r3g2: 5;
			__IO uint32_t cr1_r3g3: 5;
		}__PACKED t2;
	}__PACKED tBit;
	__IO uint32_t ulBulk;
}__PACKED tSW98502_ROIC_CR_MUX_t;

extern tParamPreMainSet_t * s_ptParamPreMainSet;
tModuleSRICCommonConf_t * g_ptSRICConfig;

tSW98502_ROIC_CR_MUX_t * g_pR0_CR_MUX_Tune;
tSW98502_ROIC_CR_MUX_t * g_pR1_CR_MUX_Tune;
bool_t bISAllFinish = NO;

#define AUTO_CAL_AVERAGE_FRAME_NUM			(100)
void SW98502_RawDataCalibration(void)
{
	bool_t bIsLoop = YES;
	uint32_t r, c, framenum;
	uint32_t ulROICIdx;
	uint32_t ulMuxIdx;
	uint32_t ulRowGroupIdx;
	uint32_t ulColGroupIdx;
	uint32_t ulCRTuneRegIdx;

	uint32_t temp_data;
	uint16_t usTempRawData;
	int16_t sPosTempDiff;
	int16_t sNegTempDiff;
	int16_t temp_regValue;
#if USED_ONLY_LOCAL_MODE
	ePartialSensing_t lDataIndex = PARTIAL_PEN_BEACON;
#endif /* USED_ONLY_LOCAL_MODE */

	g_ptSRICConfig = (tModuleSRICCommonConf_t *)&(s_ptParamPreMainSet->tParamCommonConf.tModule.tSRIC_Conf);
	g_pR0_CR_MUX_Tune = (tSW98502_ROIC_CR_MUX_t *)&g_ptSRICConfig->R0_CR_MUX1_1[0].ulBulk;
	g_pR1_CR_MUX_Tune = (tSW98502_ROIC_CR_MUX_t *)&g_ptSRICConfig->R1_CR_MUX1_1[0].ulBulk;

	memset((void*)(&AutoCalfinish_R0[0][0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_MAX_NUM*DEF_MUX_MAX_NUM*DEF_ROW_CR_GROUP_NUM*DEF_COL_CR_GROUP_NUM);
	memset((void*)(&AutoCalfinish_R1[0][0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_MAX_NUM*DEF_MUX_MAX_NUM*DEF_ROW_CR_GROUP_NUM*DEF_COL_CR_GROUP_NUM);

    tHalIntrHandle.ulLocalIndexChangeStart = 1;
#if (USED_ONLY_LOCAL_MODE == NO)
	if(IS_FINGER_PEN_MODE(HAL_GetSensingMode()))
	{
		HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);
	}
#endif /* (USED_ONLY_LOCAL_MODE == NO) */

#if (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO)
	memset((void*)(&g_pR0_CR_MUX_Tune[0]), 0, sizeof(uint32_t)*DEF_CR_REG_MAX_NUM);
	memset((void*)(&g_pR1_CR_MUX_Tune[0]), 0, sizeof(uint32_t)*DEF_CR_REG_MAX_NUM);

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

#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE)
	    while(YES)
	    {
			lDataIndex = module_wait_local_sample_done();

			if(lDataIndex == LOCAL_FINGER_LAST_LHB)
			{
				break;
			}
		}
#else /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
		module_wait_full_sample_done();
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */

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
#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE)
			    while(YES)
			    {
					lDataIndex = module_wait_local_sample_done();

					if(lDataIndex == LOCAL_FINGER_LAST_LHB)
					{
						break;
					}
				}
#else /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
				module_wait_full_sample_done();
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
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

			memset((void*)(&RawValue_Sum_R0[0][0][0][0]), 0, sizeof(uint32_t)*DEF_ROIC_MAX_NUM*DEF_MUX_MAX_NUM*DEF_ROW_CR_GROUP_NUM*DEF_COL_CR_GROUP_NUM);
			memset((void*)(&RawValue_Sum_R1[0][0][0][0]), 0, sizeof(uint32_t)*DEF_ROIC_MAX_NUM*DEF_MUX_MAX_NUM*DEF_ROW_CR_GROUP_NUM*DEF_COL_CR_GROUP_NUM);

			memset((void*)(&RawSumCnt_R0[0][0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_MAX_NUM*DEF_MUX_MAX_NUM*DEF_ROW_CR_GROUP_NUM*DEF_COL_CR_GROUP_NUM);
			memset((void*)(&RawSumCnt_R1[0][0][0][0]), 0, sizeof(uint8_t)*DEF_ROIC_MAX_NUM*DEF_MUX_MAX_NUM*DEF_ROW_CR_GROUP_NUM*DEF_COL_CR_GROUP_NUM);

			for(r = 0; r < ROW_MAX; r++)
			{
				ulMuxIdx = r/DEF_USED_LINE_NUM_1_MUX;
				for(c = 0; c < COL_MAX; c++)
				{
					temp_data = HAL_READ_COMMON_IMAGE(r, c);
					{
						if(ulMSPIIndex[c] < DEF_USED_ROIC_NUM)
						{
							RawValue_Sum_R0[ulMSPIIndex[c]][ulMuxIdx][ulCR_Reg_Row_GroupIdx[r]][ulCR_Reg_Col_GroupIdx[c]] += temp_data;
							RawSumCnt_R0[ulMSPIIndex[c]][ulMuxIdx][ulCR_Reg_Row_GroupIdx[r]][ulCR_Reg_Col_GroupIdx[c]]++;
						}
						else
						{
							RawValue_Sum_R1[ulMSPIIndex[c]-DEF_ROIC_MAX_NUM][ulMuxIdx][ulCR_Reg_Row_GroupIdx[r]][ulCR_Reg_Col_GroupIdx[c]] += temp_data;
							RawSumCnt_R1[ulMSPIIndex[c]-DEF_ROIC_MAX_NUM][ulMuxIdx][ulCR_Reg_Row_GroupIdx[r]][ulCR_Reg_Col_GroupIdx[c]]++;
						}
					}
				}
			}

			for(ulROICIdx = 0; ulROICIdx < DEF_USED_ROIC_NUM; ulROICIdx++)
			{
				for(ulMuxIdx = 0; ulMuxIdx < DEF_USED_MUX_NUM; ulMuxIdx++)
				{
					for(ulRowGroupIdx = 0; ulRowGroupIdx < DEF_ROW_CR_GROUP_NUM; ulRowGroupIdx++)
					{
						for(ulColGroupIdx = 0; ulColGroupIdx < DEF_COL_CR_GROUP_NUM; ulColGroupIdx++)
						{
							/*
							 * R0 CR Tune
							 */
							if(AutoCalfinish_R0[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx] == 0)
							{
								usTempRawData = (uint16_t)(RawValue_Sum_R0[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx]/RawSumCnt_R0[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx]);
								ulCRTuneRegIdx = ulROICIdx + (ulMuxIdx * DEF_ROIC_MAX_NUM * 2) + ((ulRowGroupIdx / 2) * DEF_ROIC_MAX_NUM);
								if(usTempRawData > RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL)
								{
									switch(ulRowGroupIdx)
									{
										case 0: // R1
										{
											switch(ulColGroupIdx)
											{
												case 0: // G1
												{
													g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g1++;
													break;
												}
												case 1: // G2
												{
													g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g2++;
													break;
												}
												case 2: // G3
												{
													g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g3++;
													break;
												}
											}
											break;
										}
										case 1: // R2
										{
											switch(ulColGroupIdx)
											{
												case 0: // G1
												{
													g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g1++;
													break;
												}
												case 1: // G2
												{
													g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g2++;
													break;
												}
												case 2: // G3
												{
													g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g3++;
													break;
												}
											}
											break;
										}
										case 2: // R3
										{
											switch(ulColGroupIdx)
											{
												case 0: // G1
												{
													g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g1++;
													break;
												}
												case 1: // G2
												{
													g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g2++;
													break;
												}
												case 2: // G3
												{
													g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g3++;
													break;
												}
											}
											break;
										}
									}
								}
								else
								{
									sNegTempDiff = RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL - (int16_t)usTempRawData;
									sPosTempDiff = (int16_t)PastRawValueR0[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx] - RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL;
									if(sPosTempDiff < sNegTempDiff)
									{
										switch(ulRowGroupIdx)
										{
											case 0: // R1
											{
												switch(ulColGroupIdx)
												{
													case 0: // G1
													{
														g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g1--;
														break;
													}
													case 1: // G2
													{
														g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g2--;
														break;
													}
													case 2: // G3
													{
														g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g3--;
														break;
													}
												}
												break;
											}
											case 1: // R2
											{
												switch(ulColGroupIdx)
												{
													case 0: // G1
													{
														g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g1--;
														break;
													}
													case 1: // G2
													{
														g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g2--;
														break;
													}
													case 2: // G3
													{
														g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g3--;
														break;
													}
												}
												break;
											}
											case 2: // R3
											{
												switch(ulColGroupIdx)
												{
													case 0: // G1
													{
														g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g1--;
														break;
													}
													case 1: // G2
													{
														g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g2--;
														break;
													}
													case 2: // G3
													{
														g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g3--;
														break;
													}
												}
												break;
											}
										}
									}

									AutoCalfinish_R0[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx] = 1;
								}

								PastRawValueR0[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx] = usTempRawData;
							}

							/*
							 * R1 CR Tune
							 */
							if(AutoCalfinish_R1[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx] == 0)
							{
								usTempRawData = (uint16_t)(RawValue_Sum_R1[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx]/RawSumCnt_R1[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx]);
								ulCRTuneRegIdx = ulROICIdx + (ulMuxIdx * DEF_ROIC_MAX_NUM * 2) + ((ulRowGroupIdx / 2) * DEF_ROIC_MAX_NUM);
								if(usTempRawData > RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL)
								{
									switch(ulRowGroupIdx)
									{
										case 0: // R1
										{
											switch(ulColGroupIdx)
											{
												case 0: // G1
												{
													g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g1++;
													break;
												}
												case 1: // G2
												{
													g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g2++;
													break;
												}
												case 2: // G3
												{
													g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g3++;
													break;
												}
											}
											break;
										}
										case 1: // R2
										{
											switch(ulColGroupIdx)
											{
												case 0: // G1
												{
													g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g1++;
													break;
												}
												case 1: // G2
												{
													g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g2++;
													break;
												}
												case 2: // G3
												{
													g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g3++;
													break;
												}
											}
											break;
										}
										case 2: // R3
										{
											switch(ulColGroupIdx)
											{
												case 0: // G1
												{
													g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g1++;
													break;
												}
												case 1: // G2
												{
													g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g2++;
													break;
												}
												case 2: // G3
												{
													g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g3++;
													break;
												}
											}
											break;
										}
									}
								}
								else
								{
									sNegTempDiff = RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL - (int16_t)usTempRawData;
									sPosTempDiff = (int16_t)PastRawValueR1[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx] - RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL;
									if(sPosTempDiff < sNegTempDiff)
									{
										switch(ulRowGroupIdx)
										{
											case 0: // R1
											{
												switch(ulColGroupIdx)
												{
													case 0: // G1
													{
														g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g1--;
														break;
													}
													case 1: // G2
													{
														g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g2--;
														break;
													}
													case 2: // G3
													{
														g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g3--;
														break;
													}
												}
												break;
											}
											case 1: // R2
											{
												switch(ulColGroupIdx)
												{
													case 0: // G1
													{
														g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g1--;
														break;
													}
													case 1: // G2
													{
														g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g2--;
														break;
													}
													case 2: // G3
													{
														g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g3--;
														break;
													}
												}
												break;
											}
											case 2: // R3
											{
												switch(ulColGroupIdx)
												{
													case 0: // G1
													{
														g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g1--;
														break;
													}
													case 1: // G2
													{
														g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g2--;
														break;
													}
													case 2: // G3
													{
														g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t2.cr1_r3g3--;
														break;
													}
												}
												break;
											}
										}
									}

									AutoCalfinish_R1[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx] = 1;
								}

								PastRawValueR1[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx] = usTempRawData;
							}
						}
					}
				}
			}

			bISAllFinish = YES;
			for(ulROICIdx = 0; ulROICIdx < DEF_USED_ROIC_NUM; ulROICIdx++)
			{
				for(ulMuxIdx = 0; ulMuxIdx < DEF_USED_MUX_NUM; ulMuxIdx++)
				{
					for(ulRowGroupIdx = 0; ulRowGroupIdx < DEF_ROW_CR_GROUP_NUM; ulRowGroupIdx++)
					{
						for(ulColGroupIdx = 0; ulColGroupIdx < DEF_COL_CR_GROUP_NUM; ulColGroupIdx++)
						{
							if(AutoCalfinish_R0[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx] == 0)
							{
								bISAllFinish = NO;
							}
							if(AutoCalfinish_R1[ulROICIdx][ulMuxIdx][ulRowGroupIdx][ulColGroupIdx] == 0)
							{
								bISAllFinish = NO;
							}
						}
					}
				}
			}

			if(bISAllFinish)
			{
				bIsAutoCalFinish = YES;


				for(ulROICIdx = 0; ulROICIdx < DEF_USED_ROIC_NUM; ulROICIdx++)
				{
					for(ulMuxIdx = 0; ulMuxIdx < DEF_USED_MUX_NUM; ulMuxIdx++)
					{
						ulCRTuneRegIdx = ulROICIdx + (ulMuxIdx * DEF_ROIC_MAX_NUM * 2);
						r = ulMuxIdx*DEF_ROW_CR_GROUP_NUM;
						c = ulROICIdx*DEF_COL_CR_GROUP_NUM;
						temp_regValue = (int16_t)g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g1;
						HAL_WRITE_DELTA_IMAGE(r, c, temp_regValue);
						temp_regValue = (int16_t)g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g2;
						HAL_WRITE_DELTA_IMAGE(r, c+1, temp_regValue);
						temp_regValue = (int16_t)g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g3;
						HAL_WRITE_DELTA_IMAGE(r, c+2, temp_regValue);

						temp_regValue = (int16_t)g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g1;
						HAL_WRITE_DELTA_IMAGE(r+1, c, temp_regValue);
						temp_regValue = (int16_t)g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g2;
						HAL_WRITE_DELTA_IMAGE(r+1, c+1, temp_regValue);
						temp_regValue = (int16_t)g_pR0_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g3;
						HAL_WRITE_DELTA_IMAGE(r+1, c+2, temp_regValue);

						temp_regValue = (int16_t)g_pR0_CR_MUX_Tune[ulCRTuneRegIdx+DEF_ROIC_MAX_NUM].tBit.t2.cr1_r3g1;
						HAL_WRITE_DELTA_IMAGE(r+2, c, temp_regValue);
						temp_regValue = (int16_t)g_pR0_CR_MUX_Tune[ulCRTuneRegIdx+DEF_ROIC_MAX_NUM].tBit.t2.cr1_r3g2;
						HAL_WRITE_DELTA_IMAGE(r+2, c+1, temp_regValue);
						temp_regValue = (int16_t)g_pR0_CR_MUX_Tune[ulCRTuneRegIdx+DEF_ROIC_MAX_NUM].tBit.t2.cr1_r3g3;
						HAL_WRITE_DELTA_IMAGE(r+2, c+2, temp_regValue);

						r += (DEF_USED_MUX_NUM * DEF_ROW_CR_GROUP_NUM);
						temp_regValue = (int16_t)g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g1;
						HAL_WRITE_DELTA_IMAGE(r, c, temp_regValue);
						temp_regValue = (int16_t)g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g2;
						HAL_WRITE_DELTA_IMAGE(r, c+1, temp_regValue);
						temp_regValue = (int16_t)g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r1g3;
						HAL_WRITE_DELTA_IMAGE(r, c+2, temp_regValue);

						temp_regValue = (int16_t)g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g1;
						HAL_WRITE_DELTA_IMAGE(r+1, c, temp_regValue);
						temp_regValue = (int16_t)g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g2;
						HAL_WRITE_DELTA_IMAGE(r+1, c+1, temp_regValue);
						temp_regValue = (int16_t)g_pR1_CR_MUX_Tune[ulCRTuneRegIdx].tBit.t1.cr1_r2g3;
						HAL_WRITE_DELTA_IMAGE(r+1, c+2, temp_regValue);

						temp_regValue = (int16_t)g_pR1_CR_MUX_Tune[ulCRTuneRegIdx+DEF_ROIC_MAX_NUM].tBit.t2.cr1_r3g1;
						HAL_WRITE_DELTA_IMAGE(r+2, c, temp_regValue);
						temp_regValue = (int16_t)g_pR1_CR_MUX_Tune[ulCRTuneRegIdx+DEF_ROIC_MAX_NUM].tBit.t2.cr1_r3g2;
						HAL_WRITE_DELTA_IMAGE(r+2, c+1, temp_regValue);
						temp_regValue = (int16_t)g_pR1_CR_MUX_Tune[ulCRTuneRegIdx+DEF_ROIC_MAX_NUM].tBit.t2.cr1_r3g3;
						HAL_WRITE_DELTA_IMAGE(r+2, c+2, temp_regValue);
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
#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE)
			    while(YES)
			    {
					lDataIndex = module_wait_local_sample_done();

					if(lDataIndex == LOCAL_OP_LAST_LHB)
					{
						break;
					}
				}
#else /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
				module_wait_full_sample_done();
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
			}
#if (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE)
		    while(YES)
		    {
				lDataIndex = module_wait_local_sample_done();

				if(lDataIndex == LOCAL_OP_LAST_LHB)
				{
					break;
				}
			}
#else /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
			module_wait_full_sample_done();
#endif /* (USED_PEN_MODE_OPERATION && USED_ONLY_LOCAL_MODE) */
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


#endif /* (USED_ROIC_DEF == ROIC_SW98502) */
