/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : roic_ctrl_sw92502.c
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
#include "roic_ctrl_sw92502.h"


#if (USED_ROIC_DEF == ROIC_SW92502)

const tModuleSRICCommonConf_t * s_pktmoduleSRICCommonConf = NULL;


void SW92502_Initialize(void)
{
	s_pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
}

void SW92502_Reset(eSENSING_MODE_t eSensingMode)
{
	GPIO->tGPIO_AFIO_2._GPIO_RSTN_SRIC = 0x0;
	GPIO->tGPIO_DIR_1._GPIO_RSTN_SRIC = 0x1;

	GPIO->tGPIO_DATA_1._GPIO_RSTN_SRIC = 0x1;
	delay_usec(100);

#if !USED_OPERATION_STAND_ALONE
	if(!IS_S3_MODE(eSensingMode))
	{
		while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 1);
		while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0);
	}
	delay_usec(10);
#endif /* !USED_OPERATION_STAND_ALONE */
	GPIO->tGPIO_DATA_1._GPIO_RSTN_SRIC = 0x0;
	delay_usec(10);
	GPIO->tGPIO_DATA_1._GPIO_RSTN_SRIC = 0x1;
	delay_usec(100);
}

#define ROIC_REG_NUM		(196)

bool_t SW92502_RegisterInit(eSENSING_MODE_t eSensingMode)
{
	bool_t bReg = YES;
	uint32_t ulIdx;
	uint32_t ulBuf[6];
	uint16_t * pRegVal;

	MSPI_RegisterRead(0x400, &ulBuf[0], MSPI_READ_SM0_R0);

	pRegVal = (uint16_t *)s_pktmoduleSRICCommonConf;

	for (ulIdx = 0; ulIdx < ROIC_REG_NUM; ulIdx++)
	{
		MSPI_RegisterWrite((uint32_t)((ulIdx<<1) + 0x400), pRegVal[ulIdx]);
	}

	return bReg;
}

void SW92502_Run(uint8_t Enable)
{
	tCFGR_SYS_CFG_t tCFGR_SYS_CFG;
	tCFGR_SYS_CFG.ulBulk = 0;
	tCFGR_SYS_CFG.tBit.scan_start = Enable;
	tCFGR_SYS_CFG.tBit.tg_clk_on = Enable;
	MSPI_RegisterWrite(0x404, tCFGR_SYS_CFG.ulBulk);
}

void SW92502_SetIdleOperationMode(void)
{
	if((PARAMSET_PWMDRV_TSYNC_IDLE_BITMASK & 0x1) && 0x1)
	{
		tCFGR_PEN_POS1_t tCFGR_PEN_POS1;
		tCFGR_PEN_POS1.ulBulk = s_pktmoduleSRICCommonConf->CFGR_PEN_POS1.ulBulk;
		tCFGR_PEN_POS1.tBit.lhb_type = 1; // Finger2
		MSPI_RegisterWrite(0x406, tCFGR_PEN_POS1.ulBulk);
	}

//	tCFGR_LHB_CFG1_t tCFGR_LHB_CFG1;
//	tCFGR_LHB_CFG1.ulBulk = s_pktmoduleSRICCommonConf->CFGR_LHB_CFG1.ulBulk;
//	tCFGR_LHB_CFG1.tBit.md2_lhb_mux = 1;
//	MSPI_RegisterWrite(0x49E, tCFGR_LHB_CFG1.ulBulk);

	tCFGR_LHB_CFG2_t tCFGR_LHB_CFG2;
	tCFGR_LHB_CFG2.ulBulk = s_pktmoduleSRICCommonConf->CFGR_LHB_CFG2.ulBulk;
	tCFGR_LHB_CFG2.tBit.end_mux_num = 1;
	MSPI_RegisterWrite(0x4A0, tCFGR_LHB_CFG2.ulBulk);
	
//	uint16_t tCFGR_MD2_MUX_SEL1;
//	tCFGR_MD2_MUX_SEL1 = 0x0FFF;
//	MSPI_RegisterWrite(0x484, tCFGR_MD2_MUX_SEL1);
}

void SW92502_SetActiveOperationMode(void)
{
	if((PARAMSET_PWMDRV_TSYNC_ACTIVE_BITMASK & 0x1) && 0x1)
	{
		tCFGR_PEN_POS1_t tCFGR_PEN_POS1;
		tCFGR_PEN_POS1.ulBulk = s_pktmoduleSRICCommonConf->CFGR_PEN_POS1.ulBulk;
		tCFGR_PEN_POS1.tBit.lhb_type = 0; // Finger2
		MSPI_RegisterWrite(0x406, tCFGR_PEN_POS1.ulBulk);
	}

	tCFGR_LHB_CFG2_t tCFGR_LHB_CFG2;
	tCFGR_LHB_CFG2.ulBulk = s_pktmoduleSRICCommonConf->CFGR_LHB_CFG2.ulBulk;
	tCFGR_LHB_CFG2.tBit.end_mux_num = 0xC;
	MSPI_RegisterWrite(0x4A0, tCFGR_LHB_CFG2.ulBulk);
}

#endif /* (USED_ROIC_DEF == ROIC_SW92502) */
