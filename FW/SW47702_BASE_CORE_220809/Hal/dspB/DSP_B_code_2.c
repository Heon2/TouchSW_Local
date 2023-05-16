/******************************************************************************************************
 * Copyright (c) 2022 - 2050 LX Semicon LIMITED
 *
 * file : DSP_B_code_2.c
 * created on : 24. 03. 2022
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

#include "app_def.h"
#include "hal_def.h"
#include "module_def.h"
#include "protocol_def.h"
#include "param_def.h"
#include "DSP_B_code_2.h"


#if (USED_PEN_MODE_OPERATION)
#if (USED_MPP_Pen_Protocol_Process_Change== YES)
static const tAlgorithmModeConf_t * thisModeConf = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;
static tPenInfo_t * thisPenInfo = NULL;

extern uint16_t currentRowStart;
extern uint16_t * g_pLocalBaseImage;


void DSP_B_code_2_Init(void)
{
	thisInfo = algorithm_GetInfo();
	thisPenInfo = &thisInfo->tPenInfo;
	thisModeConf = algorithm_GetModeConfig();
}

tMPP25DataStructInfo_t tMPP25DataStructInfo;
tMPP25PenInfo_t tMPP25PenInfo;

#define DEF_MPP25_LOCAL_DATA_MAX_NUM			(8)
#define DEF_MPP25_SYMBOL_1LS_MAX_NUM			(6)
int16_t vsMPP25DataSymbolDelta[DEF_MPP25_LOCAL_DATA_MAX_NUM][DEF_MPP25_SYMBOL_1LS_MAX_NUM] = {0,};
uint8_t vucMPP25DataSymbolValue[DEF_MPP25_LOCAL_DATA_MAX_NUM][DEF_MPP25_SYMBOL_1LS_MAX_NUM] = {0,};

#define DEF_MPP25_LOCAL_DATA_1stLHB				(0)
#define DEF_MPP25_LOCAL_DATA_2ndLHB				(1)
#define DEF_MPP25_LOCAL_DATA_3rdLHB				(2)
#define DEF_MPP25_LOCAL_DATA_4thLHB				(3)
#define DEF_MPP25_LOCAL_DATA_5thLHB				(4)
#define DEF_MPP25_LOCAL_DATA_6thLHB				(5)
#define DEF_MPP25_LOCAL_DATA_7thLHB				(6)
#define DEF_MPP25_LOCAL_DATA_8thLHB				(7)

#define DEF_MPP25_1st_SYMBOL					(0)
#define DEF_MPP25_2nd_SYMBOL					(1)
#define DEF_MPP25_3rd_SYMBOL					(2)
#define DEF_MPP25_4th_SYMBOL					(3)
#define DEF_MPP25_5th_SYMBOL					(4)
#define DEF_MPP25_6th_SYMBOL					(5)

bool_t algorithm_local_data_baseline_calculate_delta_MPP25_Structure(ePartialSensing_t RetVal)
{
	uint32_t ulSymbolIdx;
	uint32_t ulLocalDataIdx;
	uint32_t r, c;
	int16_t delta, deltaSum;
	uint32_t start_r, end_r;
	uint32_t start_c, end_c;
	uint32_t local_rs;

	uint16_t * pDataRawImage;
	uint16_t * pDataBaseRawImage;

	uint32_t ulDataValue;

	local_rs = currentRowStart;

	start_r = 0, start_c = thisPenInfo->ucCurrentColumnStart;
	end_r = PEN_COORD_ROW_MAX, end_c = thisPenInfo->ucCurrentColumnEnd;
	
	uint8_t ucPenDataLocalTHD = thisModeConf->PenData.ucPenDataLocalTHD;
	uint16_t min_delta_th = thisModeConf->BaseLine.usMS_ContactTh_HoverMode;
	
	if(thisPenInfo->bPenContact == YES || thisPenInfo->bPrevPenContact == YES)
		min_delta_th = thisModeConf->BaseLine.usMS_ContactTh_LocalMode;

	thisPenInfo->bPen_phase[0] = thisPenInfo->bPen_phase[1] = 0;
	thisPenInfo->bMS_Contact2bit[0] = thisPenInfo->bMS_Contact2bit[1] = 0;

	switch(RetVal)
	{
	case PARTIAL_PEN_COORD_DATA1:
		ulLocalDataIdx = DEF_MPP25_LOCAL_DATA_1stLHB;
		break;
	case PARTIAL_PEN_DATA1:
		ulLocalDataIdx = DEF_MPP25_LOCAL_DATA_2ndLHB;
		break;
	case PARTIAL_PEN_DATA2:
		ulLocalDataIdx = DEF_MPP25_LOCAL_DATA_3rdLHB;
		break;
	case PARTIAL_PEN_DATA3:
		ulLocalDataIdx = DEF_MPP25_LOCAL_DATA_4thLHB;
		break;
	case PARTIAL_PEN_COORD_DATA2:
		ulLocalDataIdx = DEF_MPP25_LOCAL_DATA_5thLHB;
		break;
	case PARTIAL_PEN_DATA4:
		ulLocalDataIdx = DEF_MPP25_LOCAL_DATA_6thLHB;
		break;
	case PARTIAL_PEN_COORD_DATA3:
		ulLocalDataIdx = DEF_MPP25_LOCAL_DATA_7thLHB;
		break;
	case PARTIAL_PEN_COORD_DATA4:
		ulLocalDataIdx = DEF_MPP25_LOCAL_DATA_8thLHB;
		break;
	}

	if(thisPenInfo->bSearch_Mode_Flag == 0)
	{
		ulDataValue = 0;
		for (ulSymbolIdx = 0; ulSymbolIdx < DEF_MPP25_SYMBOL_1LS_MAX_NUM; ulSymbolIdx++)
		{
			thisPenInfo->s_search_min_delta[0] = thisPenInfo->s_search_max_delta[0] = 0;
			pDataRawImage = HAL_GET_LOCAL_DATA_RAW_IMAGE_PTR();
			pDataRawImage += (ulSymbolIdx * (PEN_COORD_ROW_MAX * COL_MAX));
			pDataBaseRawImage = g_pLocalBaseImage;

			if(ulLocalDataIdx == DEF_MPP25_LOCAL_DATA_1stLHB ||
				ulLocalDataIdx == DEF_MPP25_LOCAL_DATA_5thLHB ||
				ulLocalDataIdx == DEF_MPP25_LOCAL_DATA_7thLHB ||
				ulLocalDataIdx == DEF_MPP25_LOCAL_DATA_8thLHB)
			{
				if(ulSymbolIdx == DEF_MPP25_1st_SYMBOL) // Pen Pos 1st Symbol
				{
					pDataRawImage = HAL_GET_LOCAL_RAW_IMAGE_PTR();
					ucPenDataLocalTHD = 0;
				}
				else if(ulSymbolIdx == DEF_MPP25_2nd_SYMBOL) // Pen Pos 2nd Symbol
				{
					pDataRawImage = HAL_GET_LOCAL_RAW_IMAGE_PTR();
					pDataRawImage += (PEN_COORD_ROW_MAX * COL_MAX);
					ucPenDataLocalTHD = 0;
				}

				if(ulLocalDataIdx == DEF_MPP25_LOCAL_DATA_1stLHB ||
					ulLocalDataIdx == DEF_MPP25_LOCAL_DATA_7thLHB)
				{
					if(ulSymbolIdx == DEF_MPP25_5th_SYMBOL) // Ring 1st Symbol
					{
						pDataRawImage = HAL_GET_LOCAL_RING_RAW_IMAGE_PTR();
						pDataBaseRawImage = HAL_GET_RING_BASELINE_IMAGE_2_PTR();
					}
					else if(ulSymbolIdx == DEF_MPP25_6th_SYMBOL) // Ring 2nd Symbol
					{
						pDataRawImage = HAL_GET_LOCAL_RING_RAW_IMAGE_PTR();
						pDataRawImage += (PEN_COORD_ROW_MAX * COL_MAX);
						pDataBaseRawImage = HAL_GET_RING_BASELINE_IMAGE_PTR();
					}
				}
			}

//#if (!(IS_WGPUHDPEN_PROTOCOL_OPERATION && USED_NOISE_HOPPING_FREQ))
//			if(thisModeConf->BaseLine.bPen_2BASE && ulSymbolIdx > 0)
//				base_idx = ROW_MAX;
//#endif /* (!(IS_WGPUHDPEN_PROTOCOL_OPERATION && USED_NOISE_HOPPING_FREQ)) */
			deltaSum = 0;
			for (r = start_r; r < end_r; r++)
			{
				for (c = start_c; c <= end_c; c++)
				{
					delta = (int16_t)pDataBaseRawImage[((r + local_rs) * COL_MAX) + c] - (int16_t)pDataRawImage[(r * COL_MAX) + c];
#ifdef FingerAreaPenDeltaDelete						
					if(thisModeConf->BaseLine.cFingerAreaPenDeltaDelete != 0)// && thisInfo->tDelta.iMaxStrength > thisModeConf->Label.usSeedBase)
					{
//						if(LOCALFINGERAREA[r+local_rs][c] > 0)
						if(thisPenInfo->LocalFingerArea.rs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= r+local_rs
						&& thisPenInfo->LocalFingerArea.re + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= r+local_rs
						&& thisPenInfo->LocalFingerArea.cs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= c
						&& thisPenInfo->LocalFingerArea.ce + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= c)
						{						
							delta = 0;
						}
					}
#endif
#if (LocalNormalizeEn == YES)						
					if(thisModeConf->BaseLine.ucLocalNormalizeMaxOffset != 0)
					{
						int NormalizeOffset = thisModeConf->BaseLine.ucLocalNormalizeMaxOffset * (r+local_rs)/ROW_MAX-1;
						delta = delta * (100 - NormalizeOffset)/100;
					}
#endif	
					if(ABS(delta) > ucPenDataLocalTHD)
					{
						deltaSum += delta;
					}
					
					if(delta > thisPenInfo->s_search_max_delta[0])
					{
						thisPenInfo->s_search_max_delta[0] = delta;
					}
						
					if(delta < thisPenInfo->s_search_min_delta[0])
					{
						thisPenInfo->s_search_min_delta[0] = delta;
					}
				}
			}
			
			if(	ulLocalDataIdx == DEF_MPP25_LOCAL_DATA_5thLHB ||
				ulLocalDataIdx == DEF_MPP25_LOCAL_DATA_7thLHB ||
				ulLocalDataIdx == DEF_MPP25_LOCAL_DATA_8thLHB)
			{
				if(ulSymbolIdx == DEF_MPP25_1st_SYMBOL || ulSymbolIdx == DEF_MPP25_2nd_SYMBOL)
				{
					if(thisPenInfo->s_search_max_delta[0] < -thisPenInfo->s_search_min_delta[0])
						deltaSum = thisPenInfo->s_search_min_delta[0];
					else deltaSum = thisPenInfo->s_search_max_delta[0];
				}
			}
			
			vsMPP25DataSymbolDelta[ulLocalDataIdx][ulSymbolIdx] = deltaSum;

			if(deltaSum > 0)
			{
				/*
				 * The pulse Phase of PWM and Pen Downlink is the same.
				 */
				vucMPP25DataSymbolValue[ulLocalDataIdx][ulSymbolIdx] = 0;
			}
			else
			{
				/*
				 * The pulse Phase of PWM and Pen Downlink is the different.
				 */
				vucMPP25DataSymbolValue[ulLocalDataIdx][ulSymbolIdx] = 1;
				ulDataValue |= (BIT(((DEF_MPP25_SYMBOL_1LS_MAX_NUM-1)-ulSymbolIdx)));
			}
		}

		switch(ulLocalDataIdx)
		{
			case DEF_MPP25_LOCAL_DATA_1stLHB:
			{
				tMPP25DataStructInfo.e1stLS.Byte = ulDataValue;
				tMPP25PenInfo.ePenAware = (ePenAware_t)tMPP25DataStructInfo.e1stLS.tBit.Aware;
				tMPP25PenInfo.ePenRing = (ePenRing_t)tMPP25DataStructInfo.e1stLS.tBit.Ring;
				tMPP25PenInfo.ePenNumber = (ePenNumber_t)tMPP25DataStructInfo.e1stLS.tBit.PenNumber;
				thisPenInfo->bPen_phase[0] = vucMPP25DataSymbolValue[ulLocalDataIdx][0];
				thisPenInfo->bPen_phase[1] = vucMPP25DataSymbolValue[ulLocalDataIdx][1];
				break;
			}
			case DEF_MPP25_LOCAL_DATA_2ndLHB:
			{
				tMPP25DataStructInfo.e2ndLS.Byte = ulDataValue;
				if(tMPP25DataStructInfo.e2ndLS.Byte)
				tMPP25PenInfo.ePenDataHeader = (ePenDataHeader_t)tMPP25DataStructInfo.e2ndLS.Byte;
				switch(tMPP25PenInfo.ePenDataHeader)
				{
					case MPP25_MessageType_Norm_Pen_Status:
					{
						tMPP25PenInfo.eFormat = MPP25_NORM_Format;
						break;
					}
					case MPP25_MessageType_FULL_ID_First:
					case MPP25_MessageType_FULL_ID_Continue:
					case MPP25_MessageType_FULL_Preference:
					{
						tMPP25PenInfo.eFormat = MPP25_FULL_Format;
						break;
					}
					default:
					{
						tMPP25PenInfo.eFormat = MPP25_NC_Format;
						tMPP25PenInfo.ePenDataHeader = MPP25_MessageType_Reserved;
						break;
					}
				}

				break;
			}
			case DEF_MPP25_LOCAL_DATA_3rdLHB:
			{
				tMPP25DataStructInfo.e3rdLS.Byte = ulDataValue;
				
				uint32_t ulPenPressure = ((0x1F & tMPP25DataStructInfo.e3rdLS.tBit.Pressure)<<1) |
											(0x01 & tMPP25DataStructInfo.e7thLS.tFullBit.Pressure);
				ulPenPressure = (ulPenPressure * 4095) / 63;
				
				thisPenInfo->us_pendata_pressure = tMPP25PenInfo.ulPressure = ulPenPressure;

				break;
			}
			case DEF_MPP25_LOCAL_DATA_4thLHB:
			{
				tMPP25DataStructInfo.e4thLS.Byte = ulDataValue;
				break;
			}
			case DEF_MPP25_LOCAL_DATA_5thLHB:
			{
				tMPP25DataStructInfo.e5thLS.Byte = ulDataValue;
				tMPP25PenInfo.ePenHI = (ePenHI_t)tMPP25DataStructInfo.e5thLS.tFullBit.HI;

				if(tMPP25PenInfo.ePenHI == MPP25_Ink)
				{

				}
				else
				{

				}
				
				thisPenInfo->bPen_phase[0] = vucMPP25DataSymbolValue[ulLocalDataIdx][0];
				thisPenInfo->bPen_phase[1] = vucMPP25DataSymbolValue[ulLocalDataIdx][1];
				if(-vsMPP25DataSymbolDelta[ulLocalDataIdx][0] > min_delta_th)thisPenInfo->bMS_Contact2bit[0] = 1;
				if(-vsMPP25DataSymbolDelta[ulLocalDataIdx][1] > min_delta_th)thisPenInfo->bMS_Contact2bit[1] = 1;
				break;
			}
			case DEF_MPP25_LOCAL_DATA_6thLHB:
			{
				tMPP25DataStructInfo.e6thLS.Byte = ulDataValue;
				break;
			}
			case DEF_MPP25_LOCAL_DATA_7thLHB:
			{
				uint32_t ulPenPressure = 0;
				tMPP25DataStructInfo.e7thLS.Byte = ulDataValue;
				tMPP25PenInfo.ePenHI = (ePenHI_t)tMPP25DataStructInfo.e7thLS.tFullBit.HI;

				if(tMPP25PenInfo.eFormat == MPP25_FULL_Format)
				{
#if 0
					ulPenPressure = ((0x1F & tMPP25DataStructInfo.e3rdLS.tBit.Pressure)<<2) |
									(0x01 & tMPP25DataStructInfo.e7thLS.tFullBit.Pressure);
					if(tMPP25DataStructInfo.e3rdLS.tBit.Pressure != 0)
					{
						ulPenPressure |= BIT(1);
					}
					ulPenPressure = (ulPenPressure * 4095) / 127;
#else					
//					ulPenPressure = ((0x1F & tMPP25DataStructInfo.e3rdLS.tBit.Pressure)<<1) |
//									(0x01 & tMPP25DataStructInfo.e7thLS.tFullBit.Pressure);
//					ulPenPressure = (ulPenPressure * 4095) / 63;
#endif
				}
				else if(tMPP25PenInfo.eFormat == MPP25_NORM_Format)
				{
					ulPenPressure = ((0x1F & tMPP25DataStructInfo.e3rdLS.tBit.Pressure)<<7) |
									((0xF & tMPP25DataStructInfo.e4thLS.tNormBit.Pressure)<<3) |
									(0x07 & tMPP25DataStructInfo.e7thLS.tNormBit.Pressure);
				}

//				thisPenInfo->us_pendata_pressure = tMPP25PenInfo.ulPressure = ulPenPressure;
				thisPenInfo->bPen_phase[0] = vucMPP25DataSymbolValue[ulLocalDataIdx][0];
				thisPenInfo->bPen_phase[1] = vucMPP25DataSymbolValue[ulLocalDataIdx][1];
				if(-vsMPP25DataSymbolDelta[ulLocalDataIdx][0] > min_delta_th)thisPenInfo->bMS_Contact2bit[0] = 1;
				if(-vsMPP25DataSymbolDelta[ulLocalDataIdx][1] > min_delta_th)thisPenInfo->bMS_Contact2bit[1] = 1;
				break;
			}
			case DEF_MPP25_LOCAL_DATA_8thLHB:
			{
				tMPP25DataStructInfo.e8thLS.Byte = ulDataValue;
				tMPP25PenInfo.ePenHI = (ePenHI_t)tMPP25DataStructInfo.e8thLS.tFullBit.HI;

				tMPP25DataInfo_t tMPP25DataValue;
				if(tMPP25PenInfo.eFormat == MPP25_FULL_Format)
				{
					tMPP25DataValue.word = ((0x1F & tMPP25DataStructInfo.e4thLS.tFullBit.Data) << 13) |
											((0x7 & tMPP25DataStructInfo.e5thLS.tFullBit.Data) << 10) |
											((0x1F & tMPP25DataStructInfo.e6thLS.tFullBit.Data) << 5) |
											((0x3 & tMPP25DataStructInfo.e7thLS.tFullBit.Data) << 3) |
											((0x7 & tMPP25DataStructInfo.e8thLS.tFullBit.Data));
					tMPP25PenInfo.ePenButton = (ePenButton_t)tMPP25DataValue.tFullFormat.tBit.FastButtons;

					if(tMPP25PenInfo.ePenDataHeader == MPP25_MessageType_FULL_ID_First)
					{
						tMPP25PenInfo.ulPenID = 0;
						tMPP25PenInfo.ulPenID = (tMPP25DataValue.tFullFormat.tBit.PenID) << 20;
					}
					else if(tMPP25PenInfo.ePenDataHeader == MPP25_MessageType_FULL_ID_Continue)
					{
						if(tMPP25PenInfo.ePenDataPrevHeader == MPP25_MessageType_FULL_ID_First)
						{
							tMPP25PenInfo.ulPenID |= ((tMPP25DataValue.tFullFormat.tBit.PenID) << 8);
						}
						else
						{
							tMPP25PenInfo.ulPenID |= ((tMPP25DataValue.tFullFormat.tBit_2.PenID));
							tMPP25PenInfo.ulPrevPenID = tMPP25PenInfo.ulPenID;
						}
					}
					
					if(thisPenInfo->bSearch_Mode_Flag == 0)
						thisPenInfo->bReportEraser = 1;
					
					if(tMPP25PenInfo.ePenButton == 1)thisPenInfo->bPen_button[1] = 1;
					else if(tMPP25PenInfo.ePenButton == 2)thisPenInfo->bPen_button[0] = 1;
					else
					{
						thisPenInfo->bPen_button[1] = thisPenInfo->bPen_button[0] = 0;
					}
				}
				else if(tMPP25PenInfo.eFormat == MPP25_NORM_Format)
				{
					tMPP25DataValue.word = ((0x1 & tMPP25DataStructInfo.e4thLS.tNormBit.Data) << 11) |
											((0x7 & tMPP25DataStructInfo.e5thLS.tNormBit.Data) << 8) |
											((0x1F & tMPP25DataStructInfo.e6thLS.tNormBit.Data) << 3) |
											((0x7 & tMPP25DataStructInfo.e8thLS.tNormBit.Data));
				}

				tMPP25PenInfo.ePenDataPrevHeader = tMPP25PenInfo.ePenDataHeader;

				thisPenInfo->bPen_phase[0] = vucMPP25DataSymbolValue[ulLocalDataIdx][0];
				thisPenInfo->bPen_phase[1] = vucMPP25DataSymbolValue[ulLocalDataIdx][1];
				if(-vsMPP25DataSymbolDelta[ulLocalDataIdx][0] > min_delta_th)thisPenInfo->bMS_Contact2bit[0] = 1;
				if(-vsMPP25DataSymbolDelta[ulLocalDataIdx][1] > min_delta_th)thisPenInfo->bMS_Contact2bit[1] = 1;
				
				break;
			}
		}
	}

//	memset(pendata_min,0,sizeof(pendata_min));
//	memset(pendata_max,0,sizeof(pendata_max));

#if AbnormalContactRemove_EN
	if(thisPenInfo->bAdaptorNoise)
	{
		thisPenInfo->bPen_button[0] = thisPenInfo->bPre_pen_button[0];
		thisPenInfo->bPen_button[1] = thisPenInfo->bPre_pen_button[1];
		thisPenInfo->us_pendata_pressure = thisPenInfo->us_pre_pendata_pressure;
	}
#endif
//	thisPenInfo->us_pre_pendata_pressure = thisPenInfo->us_pendata_pressure;
//	thisPenInfo->bPre_pen_button[0] = thisPenInfo->bPen_button[0];
//	thisPenInfo->bPre_pen_button[1] = thisPenInfo->bPen_button[1];

	return 0;
}
#endif /* (USED_MPP_Pen_Protocol_Process_Change== YES) */
#endif /* (USED_PEN_MODE_OPERATION) */
