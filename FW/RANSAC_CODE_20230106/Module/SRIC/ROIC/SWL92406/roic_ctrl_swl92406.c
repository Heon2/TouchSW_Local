/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : roic_ctrl_swl92406.c
 * created on : 13. 5. 2019
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
#include "roic_ctrl_swl92406.h"


#if (USED_ROIC_DEF == ROIC_SWL92406)

const tModuleSRICCommonConf_t * s_pktmoduleSRICCommonConf = NULL;

//uint32_t ulMSPI_Idx, ulOption_Idx;
//uint32_t ulReadBuf[MSPI_NUM];
//uint32_t ulOptionOrderIndex[4] = {0,1,2,3};
//static bool_t SWL92406_Register_Check(uint32_t Addr, uint32_t ulValue)
//{
//	bool_t bReg = TRUE;
//
////	for(ulOption_Idx = 0; ulOption_Idx < 4; ulOption_Idx++)
////	{
////		MSPI_RegisterRead(Addr, &ulReadBuf[0], (eROIC_Read_Option_t)(MSPI_READ_SM0_R0 + ulOptionOrderIndex[ulOption_Idx]));
////		for(ulMSPI_Idx = 0; ulMSPI_Idx < MSPI_NUM; ulMSPI_Idx++)
////		{
////			if(ulReadBuf[ulMSPI_Idx] != ulValue)
////			{
////				bReg = FALSE;
////			}
////		}
////	}
//
//	return bReg;
//}

void SWL92406_Initialize(void)
{
	s_pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
}

void SWL92406_Reset(eSENSING_MODE_t eSensingMode)
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

#define SRIC_REGISTER_RW_CHECK			(NO)
bool_t SWL92406_RegisterInit(eSENSING_MODE_t eSensingMode)
{
	bool_t bReg = YES;
	uint32_t ulIdx;
	const tSW92406_CFG_t * pData;

	pData = &s_pktmoduleSRICCommonConf->value[0];

	for(ulIdx = 0; ulIdx < SRIC_REG_INIT_VALUE_NUM; ulIdx++)
	{
#if USED_ROIC_TURNOFF_TSYNCN_HIGH

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN)
		if(ulIdx == 3)
		{
			MSPI_RegisterWrite(pData[ulIdx].ulADDR, 0x9D3F);
		}
		else if(ulIdx == 74)
		{
			MSPI_RegisterWrite(pData[ulIdx].ulADDR, 0xF3FE);
		}
		else if(ulIdx == 84)
		{
			MSPI_RegisterWrite(pData[ulIdx].ulADDR, 0x0000);
		}
		else
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)

		if(ulIdx == 3)
		{
			MSPI_RegisterWrite(pData[ulIdx].ulADDR, 0x9D3F);
		}
		else if(ulIdx == 74)
		{
			MSPI_RegisterWrite(pData[ulIdx].ulADDR, 0xBE7E);
		}
		else if(ulIdx == 84)
		{
			MSPI_RegisterWrite(pData[ulIdx].ulADDR, 0x0000);
		}
#if USED_MSPEN_LINEDIM_WORKAROUND
		else if(ulIdx == 92)
		{
			MSPI_RegisterWrite(pData[ulIdx].ulADDR, 0x0000);
		}
		else if(ulIdx == 94)
		{
			MSPI_RegisterWrite(pData[ulIdx].ulADDR, 0x1000);
		}
		else
#else /* USED_MSPEN_LINEDIM_WORKAROUND */
		else
#endif /* USED_MSPEN_LINEDIM_WORKAROUND */
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN) */

		MSPI_RegisterWrite(pData[ulIdx].ulADDR, pData[ulIdx].ulR0Value);
#else /* USED_ROIC_TURNOFF_TSYNCN_HIGH */
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
#if USED_MSPEN_LINEDIM_WORKAROUND
		if(ulIdx == 92)
		{
			MSPI_RegisterWrite(pData[ulIdx].ulADDR, 0x0000);
		}
		else if(ulIdx == 94)
		{
			MSPI_RegisterWrite(pData[ulIdx].ulADDR, 0x1000);
		}
		else
#endif /* USED_MSPEN_LINEDIM_WORKAROUND */
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) */
		MSPI_RegisterWrite(pData[ulIdx].ulADDR, pData[ulIdx].ulR0Value);
#endif /* USED_ROIC_TURNOFF_TSYNCN_HIGH */
	}

	return bReg;
}

void SWL92406_Run(uint8_t Enable)
{
	MSPI_RegisterWrite(0x302, 0x0003);
}

void SWL92406_SetLocalIndex(uint32_t ulIdx)
{
	const tSW92406_CFG_t * pData;
	pData = &s_pktmoduleSRICCommonConf->value[0];

	tHalIntrHandle.ulLocalSensingDoneRowIdx = ulIdx;
	switch(hal_Info_GetControlActivePenSettingType())
	{
		case ACTIVEPEN_TYPE_LOCAL_MS:
		{ // 0xEA, 0xEC
			MSPI_RegisterWrite(pData[86].ulADDR, (uint16_t)(((ulIdx & 0xFF)<<8) | (ulIdx & 0xFF)));
			MSPI_RegisterWrite(pData[87].ulADDR, (uint16_t)(ulIdx & 0xFF));
			break;
		}
		case ACTIVEPEN_TYPE_LOCAL_WACOM:
		{
			//	MUX_A : CFGR_PEN_CTRL[5:0] (Addr : 0x038C)
			//	MUX_B : CFGR_PEN_CTRL2[5:0] (Addr : 0x0396)
			MSPI_RegisterWrite(pData[58].ulADDR, (uint16_t)(pData[58].ulR0Value | (ulIdx & 0x3F)));
			MSPI_RegisterWrite(pData[63].ulADDR, (uint16_t)(pData[63].ulR0Value | (ulIdx & 0x3F)));
			break;
		}
	}
}

void SWL92406_SetIdleOperationMode(void)
{
}

void SWL92406_SetActiveOperationMode(void)
{
}


#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
#define SRIC_REG_RUNTIME_COFIG_VALUE_NUM	(19)//(23) //(19)
tSW92406_FullLocal_CFG_t tSW92406_ActivePen_Runtime_Change_Reg[SRIC_REG_RUNTIME_COFIG_VALUE_NUM] =
{
#if 0
	{	0x0308	,	0x310A	,	0x333A	},	/* [04]	CFGR_SSU_CTRL	*/ \
	{	0x0310	,	0x0104	,	0x010F	},	/* [08]	CFGR_PWM_NUM0	*/ \
	{	0x034A	,	0x8000	,	0x0000	},	/* [26]	CFGR_TEST_OPT	*/ \
	{	0x034E	,	0x3322	,	0x2222	},	/* [28]	CFGR_CMUX_NUM	*/ \
	{	0x0350	,	0x7711	,	0x3322	},	/* [29]	CFGR_SSU_CR_I00	*/ \
	{	0x037A	,	0x2252	,	0x20DA	},	/* [49]	CFGR_SSU_INT_GC	*/ \
	{	0x037E	,	0x2492	,	0x2532	},	/* [51]	CFGR_SSU_GC	*/ \
	{	0x038A	,	0x2020	,	0x1A1A	},	/* [57]	CFGR_CMUX_NUM_PEN	*/ \
	{	0x038E	,	0x8844	,	0x8944	},	/* [59]	CFGR_HALF_COPY	*/ \
	{	0x0390	,	0x0AAA	,	0x9F9E	},	/* [60]	CFGR_PEN0_TSYNC0	*/ \
	{	0x0392	,	0x1256	,	0x1F81	},	/* [61]	CFGR_PEN0_TSYNC1	*/ \
	{	0x03A0	,	0x050C	,	0x070E	},	/* [64]	CFGR_PWM_NUM2	*/ \
	{	0x03A2	,	0x0505	,	0x0A10	},	/* [65]	CFGR_PWM_NUM3	*/ \
	{	0x03A4	,	0x1212	,	0x0514	},	/* [66]	CFGR_PWM_NUM4	*/ \
	{	0x03A8	,	0x010A	,	0x810E	},	/* [68]	CFGR_PWM_NUM_NI	*/ \
	{	0x03B4	,	0xBE7E	,	0xF3FE	},	/* [74]	CFGR_PSVB_PEN_TSYNC	*/ \
	{	0x03C4	,	0x09E0	,	0xAED1	},	/* [82]	CFGR_ACLK_DIV2	*/ \
	{	0x03F6	,	0x0000	,	0x03FF	},	/* [92]	CFGR_CMUX_MN1	*/ \
	{	0x03FE	,	0x1000	,	0x0000	},	/* [94]	CFGR_MD_IDLE	*/ \

#else
	{	0x0308	,	0x310A	,	0x310A	,	0x333A	,	0x333A	},	/* [04]	CFGR_SSU_CTRL	*/
//		{	0x030A	,	0x0501	,	0x0502	,	0x0501	,	0x0502	},	/* [05]	CFGR_TSYNC_NUM0	*/
//		{	0x030C	,	0x0501	,	0x0704	,	0x0501	,	0x0704	},	/* [06]	CFGR_TSYNC_NUM1	*/
//		{	0x030E	,	0x0000	,	0x0002	,	0x0000	,	0x0002	},	/* [07]	CFGR_TSYNC_DMMY	*/
	{	0x0310	,	0x0104	,	0x0104	,	0x010F	,	0x0704	},	/* [08]	CFGR_PWM_NUM0	*/
//		{	0x0314	,	0xA0E0	,	0x9CE0	,	0xA0E0	,	0x9CE0	},	/* [10]	CFGR_CMUX_NORM	*/
	{	0x034A	,	0x8000	,	0x8000	,	0x0000	,	0x0000	},	/* [26]	CFGR_TEST_OPT	*/
	{	0x034E	,	0x3322	,	0x3322	,	0x2222	,	0x2222	},	/* [28]	CFGR_CMUX_NUM	*/
	{	0x0350	,	0x7711	,	0x7711	,	0x3322	,	0x3322	},	/* [29]	CFGR_SSU_CR_I00	*/
	{	0x037A	,	0x2252	,	0x2252	,	0x20DA	,	0x20DA	},	/* [49]	CFGR_SSU_INT_GC	*/
	{	0x037E	,	0x2492	,	0x2492	,	0x2532	,	0x2532	},	/* [51]	CFGR_SSU_GC	*/
	{	0x038A	,	0x2020	,	0x2020	,	0x1A1A	,	0x1A1A	},	/* [57]	CFGR_CMUX_NUM_PEN	*/
	{	0x038E	,	0x8844	,	0x8844	,	0x8944	,	0x8944	},	/* [59]	CFGR_HALF_COPY	*/
	{	0x0390	,	0x0AAA	,	0x0AAA	,	0x9F9E	,	0x9F9E	},	/* [60]	CFGR_PEN0_TSYNC0	*/
	{	0x0392	,	0x1256	,	0x1256	,	0x1F81	,	0x1F81	},	/* [61]	CFGR_PEN0_TSYNC1	*/
	{	0x03A0	,	0x050C	,	0x050C	,	0x070E	,	0x070E	},	/* [64]	CFGR_PWM_NUM2	*/
	{	0x03A2	,	0x0505	,	0x0505	,	0x0A10	,	0x0A10	},	/* [65]	CFGR_PWM_NUM3	*/
	{	0x03A4	,	0x1212	,	0x1212	,	0x0514	,	0x0514	},	/* [66]	CFGR_PWM_NUM4	*/
	{	0x03A8	,	0x010A	,	0x010A	,	0x810E	,	0x810E	},	/* [68]	CFGR_PWM_NUM_NI	*/
	{	0x03B4	,	0xBE7E	,	0xBE7E	,	0xF3FE	,	0xF3FE	},	/* [74]	CFGR_PSVB_PEN_TSYNC	*/
	{	0x03C4	,	0x09E0	,	0x09E0	,	0xAED1	,	0xAED1	},	/* [82]	CFGR_ACLK_DIV2	*/
	{	0x03F6	,	0x0000	,	0x03FF	,	0x03FF	,	0x03FF	},	/* [92]	CFGR_CMUX_MN1	*/
	{	0x03FE	,	0x1000	,	0x2000	,	0x0000	,	0x0000	},	/* [94]	CFGR_MD_IDLE	*/
#endif
};
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) */

void SWL92406_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode)
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

#endif /* (USED_ROIC_DEF == ROIC_SWL92406) */

