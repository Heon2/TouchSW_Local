/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : roic_ctrl_swl92407.c
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

#include "hal_def.h"
#include "module_def.h"
#include "roic_ctrl_swl92407.h"


#if (USED_ROIC_DEF == ROIC_SWL92407)

const tModuleSRICCommonConf_t * s_pktmoduleSRICCommonConf = NULL;


tSW92407_RegAddrDef tSW92407RegAddr = {
	.ADDR_CFGR_PRODUCT_ID		=	0x00,
	.ADDR_CFGR_SNSR_STR			=	0x02,
	.ADDR_CFGR_MD_GENERAL		=	0x04,
	.ADDR_CFGR_AIP_ADC			=	0x06,
	.ADDR_CFGR_SSU_CTRL			=	0x08,
	.ADDR_CFGR_TSYNC_NUM0		=	0x0A,
	.ADDR_CFGR_TSYNC_NUM1		=	0x0C,
	.ADDR_CFGR_TSYNC_DMMY		=	0x0E,
	.ADDR_CFGR_PWM_NUM0			=	0x10,
	.ADDR_CFGR_PWM_NUM1			=	0x12,
	.ADDR_CFGR_CMUX_NORM		=	0x14,
	.ADDR_CFGR_CHIP0_LEN		=	0x16,
	.ADDR_CFGR_COL_NUM			=	0x18,
	.ADDR_CFGR_SHA_STR			=	0x3A,
	.ADDR_CFGR_DIG_GAIN2		=	0x3C,
	.ADDR_CFGR_RSTP_WIDTH		=	0x3E,
	.ADDR_CFGR_VCR_STR			=	0x40,
	.ADDR_CFGR_VCR2_MD			=	0x42,
	.ADDR_CFGR_VCR2_PHTCR		=	0x44,
	.ADDR_CFGR_PHTH0_WIDTH		=	0x46,
	.ADDR_CFGR_PHTH1_WIDTH		=	0x48,
	.ADDR_CFGR_TEST_OPT			=	0x4A,
	.ADDR_CFGR_SSU_ON			=	0x4C,
	.ADDR_CFGR_CMUX_NUM			=	0x4E,
	.ADDR_CFGR_SSU_CR_I00		=	0x50,
	.ADDR_CFGR_SSU_CR_I04		=	0x52,
	.ADDR_CFGR_SSU_CR_I08		=	0x54,
	.ADDR_CFGR_SSU_CR_I12		=	0x56,
	.ADDR_CFGR_SSU_CR_I14		=	0x58,
	.ADDR_CFGR_SSU_CR_E00		=	0x5A,
	.ADDR_CFGR_SSU_CR_E04		=	0x5C,
	.ADDR_CFGR_SSU_CR_E08		=	0x5E,
	.ADDR_CFGR_SSU_CR_E12		=	0x60,
	.ADDR_CFGR_SSU_CR_E14		=	0x62,
	.ADDR_CFGR_SSU_CR_PEN_I00	=	0x64,
	.ADDR_CFGR_SSU_CR_PEN_I04	=	0x66,
	.ADDR_CFGR_SSU_CR_PEN_I08	=	0x68,
	.ADDR_CFGR_SSU_CR_PEN_I12	=	0x6A,
	.ADDR_CFGR_SSU_CR_PEN_I14	=	0x6C,
	.ADDR_CFGR_SSU_CR_PEN_E00	=	0x6E,
	.ADDR_CFGR_SSU_CR_PEN_E04	=	0x70,
	.ADDR_CFGR_SSU_CR_PEN_E08	=	0x72,
	.ADDR_CFGR_SSU_CR_PEN_E12	=	0x74,
	.ADDR_CFGR_SSU_CR_PEN_E14	=	0x76,
	.ADDR_CFGR_SSU_INT_GC		=	0x7A,
	.ADDR_CFGR_EDGE_CR_SEL		=	0x7C,
	.ADDR_CFGR_SSU_PRE_GC		=	0x7E,
	.ADDR_CFGR_CMUX_REMAP0		=	0x80,
	.ADDR_CFGR_CMUX_REMAP1		=	0x82,
	.ADDR_CFGR_CMUX_REMAP2		=	0x84,
	.ADDR_CFGR_TSYNC_NUM_PEN	=	0x86,
	.ADDR_CFGR_TSYNC_DMMY_PEN	=	0x88,
	.ADDR_CFGR_CMUX_NUM_PEN		=	0x8A,
	.ADDR_CFGR_PEN_CTRL			=	0x8C,
	.ADDR_CFGR_HALF_COPY		=	0x8E,
	.ADDR_CFGR_PEN0_TSYNC0		=	0x90,
	.ADDR_CFGR_PEN0_TSYNC1		=	0x92,
	.ADDR_CFGR_PEN0_TSYNC2		=	0x94,
	.ADDR_CFGR_PEN_CTRL2		=	0x96,
	.ADDR_CFGR_SSU_CR_MN1_IE	=	0x98,
	.ADDR_CFGR_SSU_CR_MN2_IE	=	0x9A,
	.ADDR_CFGR_PWM_NUM2			=	0xA0,
	.ADDR_CFGR_PWM_NUM3			=	0xA2,
	.ADDR_CFGR_PWM_NUM4			=	0xA4,
	.ADDR_CFGR_PWM_NUM5			=	0xA6,
	.ADDR_CFGR_PWM_NUM_NI		=	0xA8,
	.ADDR_CFGR_CMUX_NI1			=	0xAA,
	.ADDR_CFGR_CMUX_NI2			=	0xAC,
	.ADDR_CFGR_CMUX_NI3			=	0xAE,
	.ADDR_CFGR_CMUX_NI4			=	0xB0,
	.ADDR_CFGR_AFE_DUM			=	0xB2,
	.ADDR_CFGR_PSVB_PEN_TSYNC	=	0xB4,
	.ADDR_CFGR_PSVB_FGR_TSYNC	=	0xB6,
	.ADDR_CFGR_PEN_LHB_ABD		=	0xB8,
	.ADDR_CFGR_SSU_BCON1		=	0xBA,
	.ADDR_CFGR_SSU_BCON2		=	0xBC,
	.ADDR_CFGR_SSU_BCON3		=	0xBE,
	.ADDR_CFGR_SPIS_CFG			=	0xC0,
	.ADDR_CFGR_SSU_BCON4		=	0xC2,
	.ADDR_CFGR_ACLK_DIV2		=	0xC4,
	.ADDR_CFGR_ADIV2_TOG_PAT	=	0xC6,
	.ADDR_CFGR_PSVB_AFE			=	0xC8,
	.ADDR_CFGR_AIP_ENA			=	0xCA,
	.ADDR_CFGR_AIP_ENA2			=	0xCC,
	.ADDR_CFGR_PSVB_EV_TSYNC	=	0xCE,
	.ADDR_CFGR_PSVB_OD_TSYNC	=	0xD0,
	.ADDR_CFGR_AIP_ENA3			=	0xD2,
	.ADDR_CFGR_CMUX_MP1			=	0xEA,
	.ADDR_CFGR_CMUX_MP2			=	0xEC,
	.ADDR_CFGR_PWM_NUM6			=	0xEE,
	.ADDR_CFGR_PWM_NUM7			=	0xF0,
	.ADDR_CFGR_PWM_NUM8			=	0xF2,
	.ADDR_CFGR_MD_DIFF_CMUX		=	0xF4,
	.ADDR_CFGR_CMUX_MN1			=	0xF6,
	.ADDR_CFGR_CMUX_MN2			=	0xF8,
	.ADDR_CFGR_MD_IDLE			=	0xFE,
};

void SWL92407_Initialize(void)
{
	s_pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
}

void SWL92407_Reset(eSENSING_MODE_t eSensingMode)
{
	uint32_t i;

	GPIO_Init(_GPIO_MSPI_0_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_1_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_2_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_3_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_4_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	GPIO_Init(_GPIO_MSPI_5_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

	GPIO_Init(_GPIO_MSPI_0_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_NONE);
	GPIO_Init(_GPIO_MSPI_1_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_NONE);
	GPIO_Init(_GPIO_MSPI_2_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_NONE);
	GPIO_Init(_GPIO_MSPI_3_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_NONE);
	GPIO_Init(_GPIO_MSPI_4_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_NONE);
	GPIO_Init(_GPIO_MSPI_5_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_NONE);

	delay_usec(100);

	_gOut(_GPIO_MSPI_0_CSN, GPIO_DATA_HIGH);
	_gOut(_GPIO_MSPI_1_CSN, GPIO_DATA_HIGH);
	_gOut(_GPIO_MSPI_2_CSN, GPIO_DATA_HIGH);
	_gOut(_GPIO_MSPI_3_CSN, GPIO_DATA_HIGH);
	_gOut(_GPIO_MSPI_4_CSN, GPIO_DATA_HIGH);
	_gOut(_GPIO_MSPI_5_CSN, GPIO_DATA_HIGH);

	_gOut(_GPIO_MSPI_0_MOSI, GPIO_DATA_LOW);
	_gOut(_GPIO_MSPI_1_MOSI, GPIO_DATA_LOW);
	_gOut(_GPIO_MSPI_2_MOSI, GPIO_DATA_LOW);
	_gOut(_GPIO_MSPI_3_MOSI, GPIO_DATA_LOW);
	_gOut(_GPIO_MSPI_4_MOSI, GPIO_DATA_LOW);
	_gOut(_GPIO_MSPI_5_MOSI, GPIO_DATA_LOW);

	delay_usec(100);

	for(i=0; i<SRIC_PROTOCOL_RESET_COUNT; i++)
	{		
		_gOut(_GPIO_MSPI_0_MOSI, GPIO_DATA_HIGH);
		_gOut(_GPIO_MSPI_1_MOSI, GPIO_DATA_HIGH);
		_gOut(_GPIO_MSPI_2_MOSI, GPIO_DATA_HIGH);
		_gOut(_GPIO_MSPI_3_MOSI, GPIO_DATA_HIGH);
		_gOut(_GPIO_MSPI_4_MOSI, GPIO_DATA_HIGH);
		_gOut(_GPIO_MSPI_5_MOSI, GPIO_DATA_HIGH);

		delay_usec(10);

		_gOut(_GPIO_MSPI_0_MOSI, GPIO_DATA_LOW);
		_gOut(_GPIO_MSPI_1_MOSI, GPIO_DATA_LOW);
		_gOut(_GPIO_MSPI_2_MOSI, GPIO_DATA_LOW);
		_gOut(_GPIO_MSPI_3_MOSI, GPIO_DATA_LOW);
		_gOut(_GPIO_MSPI_4_MOSI, GPIO_DATA_LOW);
		_gOut(_GPIO_MSPI_5_MOSI, GPIO_DATA_LOW);

		delay_usec(10);
	}

	_gOut(_GPIO_MSPI_0_CSN, GPIO_DATA_LOW);
	_gOut(_GPIO_MSPI_1_CSN, GPIO_DATA_LOW);
	_gOut(_GPIO_MSPI_2_CSN, GPIO_DATA_LOW);
	_gOut(_GPIO_MSPI_3_CSN, GPIO_DATA_LOW);
	_gOut(_GPIO_MSPI_4_CSN, GPIO_DATA_LOW);
	_gOut(_GPIO_MSPI_5_CSN, GPIO_DATA_LOW);		

	delay_usec(100);
}

bool_t SWL92407_RegisterInit(eSENSING_MODE_t eSensingMode)
{
	bool_t bReg = YES;
	uint32_t ulIdx;
	uint32_t ulRegIdx;
	
	uint8_t		* pRegAddr;
	uint16_t 	* pRegVal;
	pRegVal 	= (uint16_t *) 	&s_pktmoduleSRICCommonConf->RegVal;
	pRegAddr 	= (uint8_t *)	&tSW92407RegAddr.ADDR_CFGR_PRODUCT_ID;

	for(ulRegIdx = 1; ulRegIdx <= SRIC_REG_INIT_VALUE_NUM; ulRegIdx++)
	{
		ulIdx = 2 * ulRegIdx;
		MSPI_RegisterWrite( 0x300 + pRegAddr[ulRegIdx], pRegVal[ulIdx]  );
		MSPI_RegisterWrite( 0x400 + pRegAddr[ulRegIdx], pRegVal[ulIdx+1]);
	}

	return bReg;
}

void SWL92407_Run(uint8_t Enable)
{
	MSPI_RegisterWrite(0x302, 0x0003);
}

#if USED_ADAPTIVE_LOCAL_SENSING
void SWL92407_SetRoicIndex(uint32_t ulIdx)
{
	uint32_t	ulRoic0Idx, ulRoic1Idx;
	

	switch(hal_Info_GetControlActivePenSettingType())
	{
		case ACTIVEPEN_TYPE_LOCAL_MS:
		{
			if(ulIdx == ROIC_NUM)
			{
				MSPI_RegisterWrite( 0x0300 + ADDR_PEN_LHB_ABD, ROIC_PEN_LHB_ABD_OFF );
				MSPI_RegisterWrite( 0x0400 + ADDR_PEN_LHB_ABD, ROIC_PEN_LHB_ABD_OFF );
			}
			else
			{
				ulRoic0Idx = BIT(((ulIdx+1)>>1));
				ulRoic1Idx = BIT((ulIdx>>1));
				MSPI_RegisterWrite( 0x0300 + ADDR_PEN_LHB_ABD, (BIT(16) | ulRoic0Idx) );
				MSPI_RegisterWrite( 0x0400 + ADDR_PEN_LHB_ABD, (BIT(16) | ulRoic1Idx) );
			}
			break;
		}
		case ACTIVEPEN_TYPE_LOCAL_WACOM:
		{
			break;
		}
	}
}
#endif /* USED_ADAPTIVE_LOCAL_SENSING */

void SWL92407_SetLocalIndex(uint32_t ulIdx)
{
	uint16_t 	* pRegVal;
	uint8_t 	* pRegAddr;

	pRegVal 	= (uint16_t *) 	&s_pktmoduleSRICCommonConf->RegVal;
	pRegAddr 	= (uint8_t  *)	&tSW92407RegAddr.ADDR_CFGR_PRODUCT_ID;
	
	tHalIntrHandle.ulLocalSensingDoneRowIdx = ulIdx;

	switch(hal_Info_GetControlActivePenSettingType())
	{
		case ACTIVEPEN_TYPE_LOCAL_MS:
		{ // 0xEA, 0xEC
			MSPI_RegisterWrite( 0x0300 + pRegAddr[87], (uint16_t)(((ulIdx & 0xFF)<<8) | (ulIdx & 0xFF)) );
			MSPI_RegisterWrite( 0x0300 + pRegAddr[88], (uint16_t)  (ulIdx & 0xFF) );
			break;
		}
		case ACTIVEPEN_TYPE_LOCAL_WACOM:
		{
			//	MUX_A : CFGR_PEN_CTRL[5:0] (Addr : 0x038C)
			//	MUX_B : CFGR_PEN_CTRL2[5:0] (Addr : 0x0396)
			MSPI_RegisterWrite( 0x0300 + pRegAddr[53], (uint16_t)(pRegVal[2*53] | (ulIdx & 0x3F)) );
			MSPI_RegisterWrite( 0x0300 + pRegAddr[58], (uint16_t)(pRegVal[2*58] | (ulIdx & 0x3F)) );
			break;
		}
	}
}

void SWL92407_SetIdleOperationMode(void)
{
}

void SWL92407_SetActiveOperationMode(void)
{
}


#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
#define SRIC_REG_RUNTIME_COFIG_VALUE_NUM	(18)
tSW92407_FullLocal_CFG_t tSW92407_ActivePen_Runtime_Change_Reg[SRIC_REG_RUNTIME_COFIG_VALUE_NUM] =

	{	0x0308	,	0x310A	,	0x310A	,	0x333A	,	0x333A	},	/* [04]	CFGR_SSU_CTRL	*/
	{	0x0310	,	0x0104	,	0x0104	,	0x010F	,	0x010F	},	/* [08]	CFGR_PWM_NUM0	*/
	{	0x034A	,	0x8000	,	0x8000	,	0x0000	,	0x0000	},	/* [26]	CFGR_TEST_OPT	*/
	{	0x034E	,	0x3322	,	0x3322	,	0x2222	,	0x2222	},	/* [28]	CFGR_CMUX_NUM	*/
	{	0x0350	,	0x7711	,	0x7711	,	0x3322	,	0x3322	},	/* [29]	CFGR_SSU_CR_I00	*/
	{	0x037A	,	0x2252	,	0x2252	,	0x20DA	,	0x20DA	},	/* [49]	CFGR_SSU_INT_GC	*/
	{	0x037E	,	0x2492	,	0x2492	,	0x2532	,	0x2532	},	/* [51]	CFGR_SSU_GC	*/
	{	0x038A	,	0x2222	,	0x2222	,	0x1C1C	,	0x1C1C	},	/* [57]	CFGR_CMUX_NUM_PEN	*/
	{	0x038E	,	0x8844	,	0x8844	,	0x8944	,	0x8944	},	/* [59]	CFGR_HALF_COPY	*/
	{	0x0390	,	0x0AAA	,	0x0AAA	,	0x9F9E	,	0x9F9E	},	/* [60]	CFGR_PEN0_TSYNC0	*/
	{	0x0392	,	0x1656	,	0x1656	,	0x1F91	,	0x1F91	},	/* [61]	CFGR_PEN0_TSYNC1	*/
	{	0x03A0	,	0x050C	,	0x050C	,	0x070E	,	0x070E	},	/* [64]	CFGR_PWM_NUM2	*/
	{	0x03A2	,	0x0505	,	0x0505	,	0x0A14	,	0x0A14	},	/* [65]	CFGR_PWM_NUM3	*/
	{	0x03A4	,	0x1212	,	0x1212	,	0x8514	,	0x8514	},	/* [66]	CFGR_PWM_NUM4	*/
	{	0x03A8	,	0x0A0A	,	0x0A0A	,	0x0E0E	,	0x0E0E	},	/* [68]	CFGR_PWM_NUM_NI	*/
	{	0x03B4	,	0xBE7E	,	0xBE7E	,	0xF3FE	,	0xF3FE	},	/* [74]	CFGR_PSVB_PEN_TSYNC	*/
	{	0x03C4	,	0x09E0	,	0x09E0	,	0xAED1	,	0xAED1	},	/* [82]	CFGR_ACLK_DIV2	*/
//	{	0x03F6	,	0x0000	,	0x03FF	,	0x03FF	,	0x03FF	},	/* [92]	CFGR_CMUX_MN1	*/
	{	0x03FE	,	0x2000	,	0x2000	,	0x0000	,	0x0000	},	/* [94]	CFGR_MD_IDLE	*/

};
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) */

void SWL92407_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	uint32_t ulIdx;
#endif
	
	switch(eMode)
	{
		case ROIC_REG_SET_CHAGNE_WacomPen_Local_Setting:
		{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
			for(ulIdx=0; ulIdx<SRIC_REG_RUNTIME_COFIG_VALUE_NUM; ulIdx++)
			{
				MSPI_RegisterWrite(tSW92406_ActivePen_Runtime_Change_Reg[ulIdx].ulADDR, tSW92406_ActivePen_Runtime_Change_Reg[ulIdx].ulWacomLocalValue);
			}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) */
			break;
		}
		case ROIC_REG_SET_CHAGNE_WacomPen_Full_Setting:
		{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
			for(ulIdx=0; ulIdx<SRIC_REG_RUNTIME_COFIG_VALUE_NUM; ulIdx++)
			{
				MSPI_RegisterWrite(tSW92406_ActivePen_Runtime_Change_Reg[ulIdx].ulADDR, tSW92406_ActivePen_Runtime_Change_Reg[ulIdx].ulWacomFullValue);
			}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) */
			break;
		}
		case ROIC_REG_SET_CHAGNE_MSPen_Local_Setting:
		{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
			for(ulIdx=0; ulIdx<SRIC_REG_RUNTIME_COFIG_VALUE_NUM; ulIdx++)
			{
				MSPI_RegisterWrite(tSW92406_ActivePen_Runtime_Change_Reg[ulIdx].ulADDR, tSW92406_ActivePen_Runtime_Change_Reg[ulIdx].ulMSLocalValue);
			}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) */
			break;
		}
		case ROIC_REG_SET_CHAGNE_MSPen_Full_Setting:
		{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
			for(ulIdx=0; ulIdx<SRIC_REG_RUNTIME_COFIG_VALUE_NUM; ulIdx++)
			{
				MSPI_RegisterWrite(tSW92406_ActivePen_Runtime_Change_Reg[ulIdx].ulADDR, tSW92406_ActivePen_Runtime_Change_Reg[ulIdx].ulMSFullValue);
			}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) */
			break;
		}
	}
}

#endif /* (USED_ROIC_DEF == ROIC_SWL92407) */

