/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  algorithm_baseline.c
 * created on :  17. 4. 2017
 * Author :  mhjang
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

#include "core_def.h"
#include "param_def.h"
#include "wdgt.h"
//#include "DSP_B.h" // NOTE : algorithm_baseline_calculate_local_mux_range 함수를 여기서 참조하고 있음


#define BASELINE_TRACKING_RESOLUTION 		(100)

const static tModuleModeConf_t * ptModuleModeConf = NULL;
const static tAlgorithmModeConf_t * thisModeConf = NULL;
//static const tAlgorithmCommonConf_t * thisCommonConf = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;
#if USED_NOISE_HOPPING_FREQ
static tAppInfo_t * ptAppInfo = NULL;
#endif
extern __IO uint16_t sensingRowStart;
extern uint16_t currentRowStart ;
extern eActivePenType_t gAlgoRawDataType;
extern uint16_t * g_pLocalBaseImage;
uint16_t * g_pFingerBaseImage;
#define FingerNonSumThOnPenAreaForReBase	20

void algorithm_baseline_init(void)
{
	algorithm_baseline_init_param();
	thisInfo = algorithm_GetInfo();
#if USED_NOISE_HOPPING_FREQ
	ptAppInfo = app_GetInfo();
#endif
	algorithm_baseline_init_FingerPoint();	
	memset(DELTAIMAGE,0,sizeof(DELTAIMAGE));
}

void algorithm_baseline_init_param(void)
{
	thisModeConf  = algorithm_GetModeConfig();
	ptModuleModeConf = module_GetModeConfig();
}

void algorithm_baseline_init_FingerPoint(void)
{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
	g_pFingerBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_2_PTR();
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || PEN_PROTOCOL_WGP_UHD_PEN)
	g_pFingerBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR();
#else	
	if(hal_Info_GetControlActivePenRawDataType() == ACTIVEPEN_TYPE_LOCAL_WGP)
	{
		g_pFingerBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_2_PTR();
	}
	else
	{
		g_pFingerBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR();
	}
#endif
}

#ifdef SHORT_COMPENSATION
uint8_t short_cnt;
tCell_t short_pos[SHORT_NUM] = {0, };
#endif
void algorithm_baseline_tracking_initial(void)
{
	uint32_t ulFrameNum, ulIdx;
	uint32_t ulFullIdxNum;
#ifdef SHORT_COMPENSATION
    int diff;
    uint16_t raw_diff_thd = 500;
#endif
    uint16_t temp_data, raw_val = 500;
#ifdef SHORT_COMPENSATION
	uint32_t raw_avg = 0;
	short_cnt = 0;
	memset(short_pos, 0, sizeof(short_pos));
#endif
	uint16_t * pRawImage;
	uint16_t * pInitRawImage;
	uint16_t * pBaseImage;
	uint16_t * pInitBaseImage;
	
    for (ulFrameNum = 0; ulFrameNum < thisModeConf->BaseLine.ucDiscardFrameNum; ulFrameNum++)
	{
		module_wait_full_sample_done();
	}

#ifdef MODE_WDT				
	KICK_DOG();
#endif

	pInitRawImage = pRawImage = HAL_GET_RAW_IMAGE_PTR();
#if USED_NOISE_HOPPING_FREQ
	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	{
		pInitBaseImage = pBaseImage = g_pFingerBaseImage;
	}
	else
	{
		pInitBaseImage = pBaseImage = (uint16_t *)HAL_GET_HOPP1_BASELINE_IMAGE_PTR() ;
	}
//	pInitBaseImage = pBaseImage = HAL_GET_FREQ_BASELINE_PTR(ptAppInfo->eSelectFreq);
#else /* USED_NOISE_HOPPING_FREQ */
	pInitBaseImage = pBaseImage = g_pFingerBaseImage;//pBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
#endif /* USED_NOISE_HOPPING_FREQ */
	memset((void*)pBaseImage, 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
	ulFullIdxNum = ROW_MAX * COL_MAX;

    for(ulFrameNum = thisModeConf->BaseLine.ucInitialFrameNum; ulFrameNum--; )
    {
		module_wait_full_sample_done();
		pRawImage = pInitRawImage;
		pBaseImage = pInitBaseImage;
		for(ulIdx = ulFullIdxNum; ulIdx--; )
		{
			raw_val = *(pRawImage++);
			temp_data = *(pBaseImage) + raw_val;
			*(pBaseImage++) = temp_data;
#ifdef SHORT_COMPENSATION
			raw_avg += raw_val;
#endif
		}

#ifdef MODE_WDT				
		KICK_DOG();
#endif
    }

#ifdef SHORT_COMPENSATION
	raw_avg /= (ROW_MAX*COL_MAX*thisModeConf->BaseLine.ucInitialFrameNum);
#endif

	pBaseImage = pInitBaseImage;
	for(ulIdx = ulFullIdxNum; ulIdx--; )
	{
		temp_data = (*pBaseImage);
		temp_data /= thisModeConf->BaseLine.ucInitialFrameNum;
		(*pBaseImage++) = temp_data;
#ifdef SHORT_COMPENSATION
		diff = raw_avg - temp_data;
		if( diff > raw_diff_thd && short_cnt < SHORT_NUM )
		{
			short_pos[short_cnt].c = c;
			short_pos[short_cnt].r = r;
			short_cnt++;
		}
#endif
	}

#ifdef MODE_WDT				
	KICK_DOG();
#endif
}

//#define BASELINE_TRACKING_LOCAL_INDEX_OFFSET_NUM			(5)

bool_t algorithm_baseline_tracking_initial_local(uint8_t OP_TYPE)
{
	int r, c , r_pos;
//	uint32_t ulRowEnd = PEN_COORD_ROW_MAX;
	int ulRowEnd = PEN_COORD_ROW_MAX;
	uint16_t temp_data = 0;
	ePartialSensing_t lDataIndex = PARTIAL_PEN_BEACON;
	bool_t local_base_return_flag = NO;
    int finger_div = ((ROW_MAX + (PEN_COORD_ROW_MAX - 1)) / PEN_COORD_ROW_MAX);
//	uint16_t * pPenBaseImage;
//	uint16_t * pFingerBaseImage;

//	if(OP_TYPE == ACTIVEPEN_TYPE_LOCAL_MS)
//	{
//		pPenBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
//		pFingerBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR();
//	}
//	else
//	{
//#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
//		pPenBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
//		pFingerBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR();
//#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
//		pPenBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR();
//		pFingerBaseImage = HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_2_PTR();
//#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
//	}
	
	sensingRowStart = 0;

	module_wait_Vsync_signal(LOCAL_MODE, thisModeConf->BaseLine.ucDiscardFrameNum);

	uint16_t * pPenBaseImage = g_pLocalBaseImage;
	uint16_t * pFingerBaseImage = g_pFingerBaseImage;
	
    while(YES)
    {
		lDataIndex = module_wait_local_sample_done();

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		if((lDataIndex == LOCAL_OP_LAST_LHB && OP_TYPE == ACTIVEPEN_TYPE_LOCAL_MS) || (lDataIndex == LOCAL_OP_2_LAST_LHB && OP_TYPE == ACTIVEPEN_TYPE_LOCAL_WGP))
#else
		if(lDataIndex == LOCAL_OP_LAST_LHB || lDataIndex == PARTIAL_MAX)
#endif
		{
			break;
		}
	}

    tHalIntrHandle.ulLocalIndexChangeStart = 1;

	uint8_t BaseOffset = thisModeConf->BaseLine.ucPP_MUX_Select * PEN_COORD_ROW_MAX;
	if(thisModeConf->BaseLine.bPen_2BASE == 1 && thisModeConf->BaseLine.ucPP_MUX_Select > 0)
		BaseOffset -= PEN_COORD_ROW_MAX;
	
	while(YES)
	{
		lDataIndex = module_wait_local_sample_done();

		switch(lDataIndex)
		{
			case PARTIAL_PEN_COORD1:
			case PARTIAL_PEN_COORD2:
			case PARTIAL_PEN_COORD3:
			case PARTIAL_PEN_COORD4:
			{
				int temp_raw_data;

#if USED_PANEL_HV60x34_SIZE
				if(sensingRowStart == 30)
				{
					ulRowEnd = PEN_COORD_ROW_MAX-1;
				}
#endif /* USED_PANEL_HV60x34_SIZE */
				for(r = 0; r < ulRowEnd; r++)
				{
					r_pos = (r+sensingRowStart)*COL_MAX;
					for(c = 0; c < COL_MAX; c++)
					{
						temp_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+BaseOffset, c);
						temp_data = pPenBaseImage[r_pos+c] + temp_raw_data; //HAL_READ_LOCAL_BASELINE_IMAGE(r + sensingRowStart, c) + temp_raw_data;
						pPenBaseImage[r_pos+c] = temp_data; //HAL_WRITE_LOCAL_BASELINE_IMAGE(r + sensingRowStart, c, temp_data);
						
						if(thisModeConf->BaseLine.bPen_2BASE == 1)
						{
							temp_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+BaseOffset+PEN_COORD_ROW_MAX, c);
							temp_data = pPenBaseImage[(r+sensingRowStart+ROW_MAX)*COL_MAX+c] + temp_raw_data; //HAL_READ_LOCAL_BASELINE_IMAGE(r + sensingRowStart + ROW_MAX, c) + temp_raw_data;
							pPenBaseImage[(r+sensingRowStart+ROW_MAX)*COL_MAX+c] = temp_data; //HAL_WRITE_LOCAL_BASELINE_IMAGE(r + sensingRowStart + ROW_MAX, c, temp_data);		
						}

#if ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)) && defined(TILT_ON)
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
						if(OP_TYPE == ACTIVEPEN_TYPE_LOCAL_MS)
	#endif
						{
	//						if(lDataIndex == PARTIAL_PEN_COORD1)// || lDataIndex == PARTIAL_PEN_COORD3)
	//						{
	//							temp_raw_data = HAL_READ_LOCAL_RING_RAW_IMAGE(r+PEN_COORD_ROW_MAX, c);
	//							temp_data = HAL_READ_RING_BASELINE_IMAGE(r + sensingRowStart + ROW_MAX, c) + temp_raw_data;
	//							HAL_WRITE_RING_BASELINE_IMAGE(r + sensingRowStart + ROW_MAX, c, temp_data);
	//						}
						
							if(/*lDataIndex == PARTIAL_PEN_COORD1 ||*/ lDataIndex == PARTIAL_PEN_COORD3)
							{
								temp_raw_data = HAL_READ_LOCAL_RING_RAW_IMAGE(r+PEN_COORD_ROW_MAX, c);
								temp_data = HAL_READ_RING_BASELINE_IMAGE(r + sensingRowStart, c) + temp_raw_data;
								HAL_WRITE_RING_BASELINE_IMAGE(r + sensingRowStart, c, temp_data);
							}
							
	#if LOCAL_REBASE_ALGO_EN && (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
							if(lDataIndex == PARTIAL_PEN_COORD1)
							{							
								temp_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r,c);
								temp_data = HAL_READ_RECAL_BASELINE_IMAGE(r+ sensingRowStart,c) + temp_raw_data;
								HAL_WRITE_RECAL_BASELINE_IMAGE(r+ sensingRowStart, c, temp_data);								
							}
	#endif
						}
#endif
						/*
						 * TODD_1st : 아래 상수값 parameter로 빼자!!
						 */
//						if(sub_data < 0)
//						{
//							sub_data = -sub_data;
//						}
//						if(sub_data > 200)
//						{
//							g_temp_sum += sub_data;
//						}
//
//						prev_raw_data = temp_raw_data;
					}
				}

//				if(g_temp_sum > 1000)
//				{
//					local_base_return_flag = YES;
//				}
				break;
			}
			
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)			
			case PARTIAL_PEN_COORD_DATA1:
			case PARTIAL_PEN_COORD_DATA2:
			case PARTIAL_PEN_COORD_DATA3:
			case PARTIAL_PEN_COORD_DATA4:
			{
				int temp_raw_data;
				for(r = 0; r < ulRowEnd; r++)
				{
					for(c = 0; c < COL_MAX; c++)
					{
						temp_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+BaseOffset, c);
						temp_data = HAL_READ_LOCAL_BASELINE_IMAGE(r + sensingRowStart, c) + temp_raw_data;
						HAL_WRITE_LOCAL_BASELINE_IMAGE(r + sensingRowStart, c, temp_data);
						if(thisModeConf->BaseLine.bPen_2BASE == 1)
						{
							temp_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+BaseOffset+PEN_COORD_ROW_MAX, c);
							temp_data = HAL_READ_LOCAL_BASELINE_IMAGE(r + sensingRowStart + ROW_MAX, c) + temp_raw_data;
							HAL_WRITE_LOCAL_BASELINE_IMAGE(r + sensingRowStart + ROW_MAX, c, temp_data);		
						}							
					}
				}
				break;
			}
//			case PARTIAL_TILT1:
//			{
//				int temp_raw_data;
//				for(r = 0; r < ulRowEnd; r++)
//				{
//					for(c = 0; c < COL_MAX; c++)
//					{
//						temp_raw_data = HAL_READ_LOCAL_RING_RAW_IMAGE(r, c);
//						temp_data = HAL_READ_RING_BASELINE_IMAGE(r + sensingRowStart, c) + temp_raw_data;
//						HAL_WRITE_RING_BASELINE_IMAGE(r + sensingRowStart, c, temp_data);
//					}
//				}
//				break;
//			}
#endif /* USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN */			
			case LOCAL_FINGER_LAST_LHB:
			{
				int temp_raw_data;
				for (r = 0; r < ROW_MAX; r++)
				{
					r_pos = r*COL_MAX;
					for (c = 0; c < COL_MAX; c++)
					{
						temp_raw_data = HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c);
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
						if(temp_raw_data == 0)
						{
							ulZeroFingerRawMaskInfo[r][c/ZERO_FINGER_RAWDATA_MASK_NUM] |= (0x1<<(c%ZERO_FINGER_RAWDATA_MASK_NUM));
						}
#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
						temp_data = pFingerBaseImage[r_pos+c] + temp_raw_data; //HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) + temp_raw_data;
						pFingerBaseImage[r_pos+c] = temp_data; //HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, temp_data);
					}
				}
				break;
			}
			case PARTIAL_PEN_DATA1:
			case PARTIAL_PEN_DATA2:
			case PARTIAL_PEN_DATA3:
			case PARTIAL_PEN_DATA4:
			case PARTIAL_MAX:
			default:
				break;
		}

		if(lDataIndex == PARTIAL_PEN_COORD4 || lDataIndex == PARTIAL_PEN_COORD_DATA4)
		{
			sensingRowStart += PEN_COORD_ROW_MAX;
			if(sensingRowStart >= ROW_MAX)
			{
				ulRowEnd = PEN_COORD_ROW_MAX;
				sensingRowStart = 0;
			}
			else if((ROW_MAX - sensingRowStart) < PEN_COORD_ROW_MAX)
			{
				ulRowEnd = (ROW_MAX - sensingRowStart);
			}
		}
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		if(((lDataIndex == LOCAL_OP_LAST_LHB && OP_TYPE == ACTIVEPEN_TYPE_LOCAL_MS) || (lDataIndex == LOCAL_OP_2_LAST_LHB && OP_TYPE == ACTIVEPEN_TYPE_LOCAL_WGP)) && sensingRowStart == 0)
#else
		if((lDataIndex == LOCAL_OP_LAST_LHB && sensingRowStart == 0) || lDataIndex == PARTIAL_MAX)
#endif
		{
			break;
		}
	}

	for(r = ROW_MAX; r--; )
	{
		r_pos = r*COL_MAX;
		for(c=COL_MAX; c--; )
		{
			temp_data = pPenBaseImage[r_pos+c]; //HAL_READ_LOCAL_BASELINE_IMAGE(r, c);
			temp_data /= 4;
			pPenBaseImage[r_pos+c] = temp_data; //HAL_WRITE_LOCAL_BASELINE_IMAGE(r, c, temp_data);

			if(thisModeConf->BaseLine.bPen_2BASE == 1)
			{
				temp_data = pPenBaseImage[(r+ROW_MAX)*COL_MAX+c]; //HAL_READ_LOCAL_BASELINE_IMAGE(r+ROW_MAX, c);
				temp_data /= 4;
				pPenBaseImage[(r+ROW_MAX)*COL_MAX+c] = temp_data; //HAL_WRITE_LOCAL_BASELINE_IMAGE(r+ROW_MAX, c, temp_data);
			}

#if 0//((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)) && defined(TILT_ON)
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			if(OP_TYPE == ACTIVEPEN_TYPE_LOCAL_MS)
	#endif
			{
				temp_data = HAL_READ_RING_BASELINE_IMAGE(r, c);
//				temp_data /= 2;
				HAL_WRITE_RING_BASELINE_IMAGE(r, c, temp_data);
			}
#endif			
			temp_data = pFingerBaseImage[r_pos+c]; //HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c);			
			temp_data /= finger_div;
			pFingerBaseImage[r_pos+c] = temp_data; //HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, temp_data);
		}
	}

	return local_base_return_flag;
}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
bool_t algorithm_baseline_2_tracking_initial_local(void)
{
	int r, c;
	uint32_t ulRowEnd = PEN_COORD_ROW_MAX;
	uint16_t temp_data = 0;
	ePartialSensing_t lDataIndex = PARTIAL_PEN_BEACON;
	bool_t local_base_return_flag = NO;
    int finger_div = ((ROW_MAX + (PEN_COORD_ROW_MAX - 1)) / PEN_COORD_ROW_MAX);

	sensingRowStart = 0;

	module_wait_Vsync_signal(LOCAL_MODE, thisModeConf->BaseLine.ucDiscardFrameNum);

    while(YES)
    {
		lDataIndex = module_wait_local_sample_done();

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		if(lDataIndex == LOCAL_OP_2_LAST_LHB)
#else
		if(lDataIndex == LOCAL_OP_LAST_LHB || lDataIndex == PARTIAL_MAX)
#endif
		{
			break;
		}
	}

    tHalIntrHandle.ulLocalIndexChangeStart = 1;

	uint8_t BaseOffset = thisModeConf->BaseLine.ucPP_MUX_Select * PEN_COORD_ROW_MAX;
	
	while(YES)
	{
		lDataIndex = module_wait_local_sample_done();

		switch(lDataIndex)
		{
			case PARTIAL_PEN_COORD1:
			case PARTIAL_PEN_COORD2:
			case PARTIAL_PEN_COORD3:
			case PARTIAL_PEN_COORD4:
			{
				int prev_raw_data = HAL_READ_LOCAL_RAW_IMAGE(0, 0);
				int temp_raw_data;
				int sub_data;
				int g_temp_sum = 0;

				for(r = 0; r < ulRowEnd; r++)
				{
					for(c = 0; c < COL_MAX; c++)
					{
						temp_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+BaseOffset, c);
						temp_data = HAL_READ_LOCAL_BASELINE_IMAGE_2(r + sensingRowStart, c) + temp_raw_data;
						HAL_WRITE_LOCAL_BASELINE_IMAGE_2(r + sensingRowStart, c, temp_data);
						sub_data = (prev_raw_data - temp_raw_data);

						/*
						 * TODD_1st : 아래 상수값 parameter로 빼자!!
						 */
						if(sub_data < 0)
						{
							sub_data = -sub_data;
						}
						if(sub_data > 200)
						{
							g_temp_sum += sub_data;
						}

						prev_raw_data = temp_raw_data;
					}
				}

//				if(g_temp_sum > 1000)
//				{
//					local_base_return_flag = YES;
//				}
				break;
			}
			case LOCAL_FINGER_LAST_LHB:
			{
				for (r = 0; r < ROW_MAX; r++)
				{
					for (c = 0; c < COL_MAX; c++)
					{
						temp_data = HAL_READ_LOCAL_FINGER_BASELINE_IMAGE_2(r, c) + HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c);
						HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE_2(r, c, temp_data);
					}
				}
				break;
			}
			case PARTIAL_PEN_DATA1:
			case PARTIAL_PEN_DATA2:
			case PARTIAL_PEN_DATA3:
			case PARTIAL_PEN_DATA4:
			case PARTIAL_MAX:
			default:
				break;
		}

		if(lDataIndex == PARTIAL_PEN_COORD4)
		{
			sensingRowStart += PEN_COORD_ROW_MAX;
			if(sensingRowStart >= ROW_MAX)
			{
				sensingRowStart = 0;
			}
			else if((ROW_MAX - sensingRowStart) < PEN_COORD_ROW_MAX)
			{
				ulRowEnd = (ROW_MAX - sensingRowStart);
			}
		}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		if(lDataIndex == LOCAL_OP_2_LAST_LHB && sensingRowStart == 0)
		{
			break;
		}
#else
		if((lDataIndex == LOCAL_OP_LAST_LHB && sensingRowStart == 0) || lDataIndex == PARTIAL_MAX)
		{
			break;
		}
#endif
	}

	for(r = ROW_MAX; r--; )
	{
		for(c=COL_MAX; c--; )
		{
			temp_data = HAL_READ_LOCAL_BASELINE_IMAGE_2(r, c);
			temp_data /= 4;
			HAL_WRITE_LOCAL_BASELINE_IMAGE_2(r, c, temp_data);

			temp_data = HAL_READ_LOCAL_FINGER_BASELINE_IMAGE_2(r, c);
			temp_data /= finger_div;
			HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE_2(r, c, temp_data);
		}
	}

	return local_base_return_flag;
}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */

extern int16_t sLFOffsetRow[ROW_MAX];
extern int16_t sLFOffsetCol[COL_MAX];
void algorithm_baseline_tracking_continuous(uint8_t mode)
{
	uint32_t ulIdx;
	uint32_t ulFullIdxNum;
	int prev_baseline, curr_baseline, curr_rawdata, alpha;
	static bool_t traking_en = 0;
	eActivePenType_t eLocalFingerOPType = hal_Info_GetControlLocalFingerOPType();
	uint16_t * pRawImage = HAL_GET_RAW_IMAGE_PTR();
#if USED_NOISE_HOPPING_FREQ
	uint16_t * pBaseImage;
	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	{
		pBaseImage = g_pFingerBaseImage;
	}
	else
	{
		pBaseImage = (uint16_t *)HAL_GET_HOPP1_BASELINE_IMAGE_PTR() ;
	}
//	uint16_t * pBaseImage = HAL_GET_FREQ_BASELINE_PTR(ptAppInfo->eSelectFreq);
#else /* USED_NOISE_HOPPING_FREQ */
	uint16_t * pBaseImage = g_pFingerBaseImage;
#endif /* USED_NOISE_HOPPING_FREQ */
	
    if(thisInfo->bIsPalm == 0 && thisInfo->bBlockTracking == NO)
	{
		if( (mode == FULL_MODE && thisInfo->bLocal_sensing == NO) || 
		(mode == LOCAL_FINGER_MODE && hal_Info_GetPenDectionEnable() == NO && thisInfo->bBlockTrackingByLocalDelta == NO && 
		(eLocalFingerOPType != ACTIVEPEN_TYPE_LOCAL_MS || (eLocalFingerOPType == ACTIVEPEN_TYPE_LOCAL_MS && traking_en))) )
		{
			alpha = thisModeConf->BaseLine.usIIRCoef;

			//pRawImage = HAL_GET_RAW_IMAGE_PTR();
			//pBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
			ulFullIdxNum = ROW_MAX * COL_MAX;
			for(ulIdx = 0; ulIdx < ulFullIdxNum; ulIdx++)
			{
				curr_rawdata = (*(pRawImage++));
	#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
				if(curr_rawdata > 0)
	#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
				{
					curr_rawdata += (sLFOffsetRow[ulIdx / COL_MAX] + sLFOffsetCol[ulIdx % COL_MAX]);
					prev_baseline = *(pBaseImage);
					curr_baseline = (alpha * prev_baseline + (BASELINE_TRACKING_RESOLUTION-alpha) * curr_rawdata)/BASELINE_TRACKING_RESOLUTION;
					*(pBaseImage++) = (uint16_t)curr_baseline;
				}
			}
		}
	}
	
	if(traking_en==0 && eLocalFingerOPType == ACTIVEPEN_TYPE_LOCAL_MS)traking_en=1;
	
	thisInfo->bBlockTrackingByLocalDelta = NO;  
}

extern uint16_t sensingRowStart_Tilt;
void algorithm_baseline_tracking_continuous_local_ring(void)
{
	int r,c,read_raw_data;
	if(thisModeConf->PenTilt.bRingBaseTracking)
	{		
		for( r=0; r<PEN_COORD_ROW_MAX; r++ )
		{
			for( c=0; c<COL_MAX; c++ )
			{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)	
				read_raw_data = HAL_READ_LOCAL_RING_RAW_IMAGE(r,c);
#else
				read_raw_data = HAL_READ_LOCAL_RING_RAW_IMAGE(r+PEN_COORD_ROW_MAX,c);
#endif
				HAL_WRITE_RING_BASELINE_IMAGE(r+sensingRowStart_Tilt,c,(HAL_READ_RING_BASELINE_IMAGE(r+sensingRowStart_Tilt,c) + read_raw_data)>>1);
			}
		}
	}
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)		
	if(sensingRowStart_Tilt >= MUX_MAX_ROW)
	{
		sensingRowStart_Tilt = 0;
	}
	else
	{
		sensingRowStart_Tilt += PEN_COORD_ROW_MAX;
		if(sensingRowStart_Tilt > MUX_MAX_ROW)
			sensingRowStart_Tilt = MUX_MAX_ROW;
	}
#endif
}

bool_t abnormal_rawdata_temp(bool_t SET)
{
	static uint32_t dataCnt = 0;
	uint32_t ldataCnt = 0;

	if(SET)
	{
		dataCnt++;
	}
	else
	{
		ldataCnt = dataCnt;
		dataCnt = 0;

		if(ldataCnt > 10)
		{
			return TRUE;
		}
	}

	return FALSE;
}

bool_t abnormal_rawdata_detection_for_hopping(bool_t SET)
{
	static uint32_t AbnormalCnt  = 0;
	uint32_t lAbnormalCnt = 0;

	if( SET )
	{
		AbnormalCnt++;
	}
	else
	{
		lAbnormalCnt = AbnormalCnt;
		AbnormalCnt = 0;

		if(lAbnormalCnt > 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}


//extern uint16_t currentRowStart ;
//extern uint16_t sensingRowStart;
//extern uint16_t p_currentRowStart;

void algorithm_baseline_calculate_mux_range(int r, int c)
{
#if 1
#define COL_CAL_SIZE						(8)
#define COL_CAL_HALF						(COL_CAL_SIZE>>1)
#define PEN_LOCAL_ROW_HALF_IDX				(PEN_COORD_ROW_MAX>>1)
//	int sub_r = r;

	if(r <= PEN_LOCAL_ROW_HALF_IDX)
	{
		sensingRowStart = 0;
	}
	else if(r >= (ROW_MAX-1) - PEN_LOCAL_ROW_HALF_IDX)
	{
		sensingRowStart = ROW_MAX - PEN_COORD_ROW_MAX;
	}
	else
	{
		sensingRowStart = r - PEN_LOCAL_ROW_HALF_IDX;
	}

//	currentRowStart = sensingRowStart;
	if(c<COL_CAL_HALF)
	{
		thisInfo->tPenInfo.ucCurrentColumnStart = 0;
		thisInfo->tPenInfo.ucCurrentColumnEnd = COL_CAL_SIZE;
	}
	else if(c+COL_CAL_HALF >= COL_MAX)
	{
		thisInfo->tPenInfo.ucCurrentColumnStart = COL_MAX - COL_CAL_SIZE - 1;
		thisInfo->tPenInfo.ucCurrentColumnEnd = COL_MAX - 1;
	}
	else
	{
		thisInfo->tPenInfo.ucCurrentColumnStart = c-COL_CAL_HALF;
		thisInfo->tPenInfo.ucCurrentColumnEnd = c+COL_CAL_HALF;
	}
#else
	int sub_r = r;
	
	if(currentRowStart == sensingRowStart)
	{
		sub_r = sub_r-MAX_MUX_HALF;
		
		if(sub_r < 0)
			sensingRowStart = 0;
		else if(sub_r >= MUX_MAX_ROW)
			sensingRowStart = MUX_MAX_ROW;
		else
			sensingRowStart = sub_r;
	}

	if(c<MAX_MUX_HALF)
	{
		thisInfo->tPenInfo.ucCurrentColumnStart = 0;
		thisInfo->tPenInfo.ucCurrentColumnEnd = MAX_MUX_SIZE;
	}
	else if(c+MAX_MUX_HALF > COL_MAX)
	{
		thisInfo->tPenInfo.ucCurrentColumnStart = COL_MAX - MAX_MUX_SIZE;
		thisInfo->tPenInfo.ucCurrentColumnEnd = COL_MAX;
	}
	else
	{
		thisInfo->tPenInfo.ucCurrentColumnStart = c-MAX_MUX_HALF;
		thisInfo->tPenInfo.ucCurrentColumnEnd = c+MAX_MUX_HALF;
	}
#endif
}

bool_t algorithm_baseline_calculate_delta(int mode)
{
	int r, c;
	int delta;	
//	int local_rs;
//	int pen_touch_data = 0;
	uint16_t read_raw_data;
//	tCell_t pen_pos;
//	int pen_touch_data2 = 0;
	tOrigDeltaInfo_t * temp_delta;
	uint16_t * pBaseImage;
	tAppInfo_t * ptAppInfo = app_GetInfo();
	
	//Adaptive SeedBase LYB_200819
	uint16_t AdaptiveSeedBase = 0;
	
#if CPI_TEST_EN
	uint16_t AbnormalRawCnt = 0;	
	uint32_t RawPartSum[COL_MAX/5+1] = {0};
	uint16_t RawPartSumCnt[COL_MAX/5+1] = {0};
	uint16_t AbnormalDeltaCntInMux[COL_MAX/5+1] = {0};
	int DeltaEdgeCntInMux = 0;
	uint8_t PhoneNoiseConditionCnt = 0;
#endif
#if LGD_ERROR_FRAME_PROCESS_EN
	int EvenDelta = 0, OddDelta = 0;
#endif
	thisInfo->bBlockTracking = NO;
//	local_rs = 0;
	temp_delta = &thisInfo->tDelta;

	memset((void *)temp_delta, 0x00, sizeof(tOrigDeltaInfo_t));
	temp_delta->tValidRect.cs = COL_MAX - 1; temp_delta->tValidRect.ce = 0;
	temp_delta->tValidRect.rs = ROW_MAX - 1; temp_delta->tValidRect.re = 0;
#if USED_NOISE_HOPPING_FREQ
	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	{
		pBaseImage = g_pFingerBaseImage;
	}
	else
	{
		pBaseImage = (uint16_t *)HAL_GET_HOPP1_BASELINE_IMAGE_PTR() ;
	}
//	pBaseImage = HAL_GET_FREQ_BASELINE_PTR(ptAppInfo->eSelectFreq);
#else /* USED_NOISE_HOPPING_FREQ */
	pBaseImage = g_pFingerBaseImage;//HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
#endif /* USED_NOISE_HOPPING_FREQ */
	
	temp_delta->iPosCnt = 0;
	temp_delta->iNegCnt = 0;


#if LOCAL_REBASE_ALGO_EN && (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)// || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)	
	tRect_t FingerNonSumOnPenArea;
	bool_t bNonSumFlag = 0;
	FingerNonSumOnPenArea.cs = COL_MAX-1; FingerNonSumOnPenArea.ce = 0;
	FingerNonSumOnPenArea.rs = ROW_MAX-1; FingerNonSumOnPenArea.re = 0;
	if(thisInfo->tDelta_local.iMaxStrength > FingerNonSumThOnPenAreaForReBase
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	&& hal_Info_GetControlLocalFingerOPType() == ACTIVEPEN_TYPE_LOCAL_MS
	#endif
	)
	{
		FingerNonSumOnPenArea.cs = MAX(0,thisInfo->tDelta_local.tMaxCellPos.c-3);
		FingerNonSumOnPenArea.ce = MIN(COL_MAX-1,thisInfo->tDelta_local.tMaxCellPos.c+3);
		FingerNonSumOnPenArea.rs = MAX(0,thisInfo->tDelta_local.tMaxCellPos.r+currentRowStart-3);
		FingerNonSumOnPenArea.re = MIN(ROW_MAX-1,thisInfo->tDelta_local.tMaxCellPos.r+currentRowStart+3);
		bNonSumFlag = 1;
	}
#endif
	
#if (USED_DSPA_FUNC_FOR_FINGER && USED_DSPA_FUNC_FOR_FINGER_CAL_DELTA)
	if(!thisModeConf->BaseLine.bDspA_Finger_CalculateDelta)
#endif
	{
		
#if ADAPTIVE_SEEDBASE
		//Adaptive SeedBase LYB_200819
		if(thisInfo->bIsPalm)	AdaptiveSeedBase = (thisModeConf->Label.usSeedBase>>1);
		else					AdaptiveSeedBase = thisModeConf->Label.usSeedBase;
#else
		AdaptiveSeedBase = thisModeConf->Label.usSeedBase;
#endif
		
		for( r=0; r<ROW_MAX; r++ )
		{
#if LGD_ERROR_FRAME_PROCESS_EN
			if(thisModeConf->Noise.ucErrorFrameProcess == 2){
				EvenDelta = 0, OddDelta = 0;
			}
#endif
			for( c=0; c<COL_MAX; c++ )
			{
				read_raw_data = HAL_READ_RAW_IMAGE(r, c);
				
#if CPI_TEST_EN
				if(thisModeConf->Noise.ucCPITestOn){
					RawPartSum[c/5] += read_raw_data;
					RawPartSumCnt[c/5]++;
					if(read_raw_data <= 0)	AbnormalRawCnt++;
				}
#endif
				
				delta = (signed)read_raw_data - (signed)(*(pBaseImage++));

				if(mode == FULL_MODE)
				{							
					if(read_raw_data < MINRAWDATA_MARGIN)
					{
						abnormal_rawdata_temp(TRUE);
					}
#if USED_NOISE_HOPPING_FREQ
					if( read_raw_data < thisModeConf->Noise.usRawDataThd )
					{
						if( HAL_READ_DELTA_IMAGE(r,c) < thisModeConf->Noise.sDeltaDataThd )
						{
							abnormal_rawdata_detection_for_hopping(TRUE);
						}
					}

#endif /* USED_NOISE_HOPPING_FREQ */
				}
				
#if NORMALIZE_DELTA_EN
				//Normalize Active 190612 limyb
				if(thisModeConf->BaseLine.cNormalizeDelta != 0 && delta > (AdaptiveSeedBase>>1))
				{
	//				int left_top = 1;
	//				int right_bottom = 128;
					int nDelta = delta;
					
	//				nDelta = nDelta * (2*ROW_MAX + r) * (2*COL_MAX + c) / (ROW_MAX * COL_MAX);
//					delta = nDelta * ( ((ROW_MAX-thisModeConf->BaseLine.cNormalizeDelta)<<1) - r) / (ROW_MAX-thisModeConf->BaseLine.cNormalizeDelta);
					delta = nDelta * (ROW_MAX + ((ROW_MAX - r)>>2)) / ROW_MAX;
				}
#endif
				
				delta >>= ptModuleModeConf->ucOvrShift;
				HAL_WRITE_DELTA_IMAGE(r, c, delta);
				
#if LGD_ERROR_FRAME_PROCESS_EN
				//LGD Kiosk error data rejection
				if(thisModeConf->Noise.ucErrorFrameProcess == 2)
				{
					if(c%2 == 0)	EvenDelta += delta;
					else			OddDelta += delta;
				}
#endif
				
				//Mux baundary
#if CPI_TEST_EN
				if(thisModeConf->Noise.ucCPITestOn){
					if(c != 0 && c < COL_MAX-1)
					{
						if(c%5 == 0){
							if( abs(delta) > 10 && abs(delta - HAL_READ_DELTA_IMAGE(r,c-1)) > (abs(delta - HAL_READ_DELTA_IMAGE(r,c+1))<<1) )
								DeltaEdgeCntInMux++;
						}
					}
				
					if(c%5 == 0)	PhoneNoiseConditionCnt = 0;
					if(delta < -100)	PhoneNoiseConditionCnt++;
					if(PhoneNoiseConditionCnt == 5)	AbnormalDeltaCntInMux[c/5] += 200;
				}
#endif
				
				if( delta > 0 )
				{	
					if( delta > thisModeConf->BaseLine.sAccumPosSumThd )
					{
#if CPI_TEST_EN
						if(thisModeConf->Noise.ucCPITestOn){
							if(delta > 511)	AbnormalDeltaCntInMux[c/5] += 200;
						}
#endif
#if LOCAL_REBASE_ALGO_EN && (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)// || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)							
						if((FingerNonSumOnPenArea.cs > c || FingerNonSumOnPenArea.ce < c || FingerNonSumOnPenArea.rs > r || FingerNonSumOnPenArea.re < r) && bNonSumFlag)
#endif
						{
							temp_delta->iPosCnt++;
							temp_delta->iPosSum += delta - thisModeConf->BaseLine.sAccumPosSumThd;
						}
					}

//					if( delta > thisModeConf->Label.usSeedBase )
					if( delta > AdaptiveSeedBase )
					{
						if( temp_delta->tValidRect.cs > c )
							temp_delta->tValidRect.cs = c;
						if( temp_delta->tValidRect.ce < c )
							temp_delta->tValidRect.ce = c;
						if( temp_delta->tValidRect.rs > r )
							temp_delta->tValidRect.rs = r;
						if( temp_delta->tValidRect.re < r )
							temp_delta->tValidRect.re = r;

						temp_delta->iGroupedCellCnt++;
					}

					if( temp_delta->iMaxStrength < delta )
					{
						temp_delta->iMaxStrength = delta;
					}
				}
				else
				{
					if( delta < thisModeConf->BaseLine.sAccumNegSumThd )
					{
#if CPI_TEST_EN
						if(thisModeConf->Noise.ucCPITestOn){
							AbnormalDeltaCntInMux[c/5]+=5;
							if(delta < -300)	AbnormalDeltaCntInMux[c/5] += 200;
						}
#endif
#if LOCAL_REBASE_ALGO_EN && (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)// || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)				
						if((FingerNonSumOnPenArea.cs > c || FingerNonSumOnPenArea.ce < c || FingerNonSumOnPenArea.rs > r || FingerNonSumOnPenArea.re < r) && bNonSumFlag)
#endif
						{						
							temp_delta->iNegCnt++;
							temp_delta->iNegSum += delta - thisModeConf->BaseLine.sAccumNegSumThd;
						}
					}


					if( temp_delta->iMinStrength > delta )
					{
						temp_delta->iMinStrength = delta;
						temp_delta->tMinCellPos.r = r;
						temp_delta->tMinCellPos.c = c;
	//					pen_touch_data = -delta;
//						pen_pos.r = r;
//						pen_pos.c = c;
					}
				}
			}
#if LGD_ERROR_FRAME_PROCESS_EN
			//LGD Kiosk error data rejection
			if(thisModeConf->Noise.ucErrorFrameProcess == 2)
			{
				if(COL_MAX>1)
				{
					EvenDelta /= ( (COL_MAX+1)>>1);
					OddDelta /= (COL_MAX>>1);
					if(abs(EvenDelta - OddDelta) > 5)
					{
						for( c=0; c<COL_MAX; c++ ){
							delta = HAL_READ_DELTA_IMAGE(r,c);
							if(c%2 == 0)
								delta = (delta - EvenDelta < 0) ? 0 : delta - EvenDelta;
							else
								delta = (delta - OddDelta < 0) ? 0 : delta - OddDelta;
							HAL_WRITE_DELTA_IMAGE(r,c,delta);
						}
						
					}
				}
			}
#endif
			
		}
		
		thisInfo->bTouchExpect = (temp_delta->iGroupedCellCnt > 0);
	}
#if (USED_DSPA_FUNC_FOR_FINGER && USED_DSPA_FUNC_FOR_FINGER_CAL_DELTA)
	else
	{
		algorithm_baseline_calculate_delta_dspA(mode);
	#if LOCAL_REBASE_ALGO_EN
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)// || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		if(bNonSumFlag)
		{
			for(r = FingerNonSumOnPenArea.rs; r <= FingerNonSumOnPenArea.re; r++)for(c = FingerNonSumOnPenArea.cs; c <= FingerNonSumOnPenArea.ce; c++)
			{
				delta = HAL_READ_DELTA_IMAGE(r,c);
				if(delta > thisModeConf->BaseLine.sAccumPosSumThd)
				{
					temp_delta->iPosCnt--;
					temp_delta->iPosSum -= (delta - thisModeConf->BaseLine.sAccumPosSumThd);				
				}
				else if( delta < thisModeConf->BaseLine.sAccumNegSumThd )
				{						
					temp_delta->iNegCnt--;
					temp_delta->iNegSum -= (delta - thisModeConf->BaseLine.sAccumNegSumThd);
				}
			}
		}
		#endif
	#endif
	}
#endif	

	if(thisInfo->bTouchExpect && !thisInfo->bLineFilterRepeatCheck)thisInfo->bLineFilterRepeatCheck = 1;

#if CPI_TEST_EN
	//LGD Phone noise
	if(thisModeConf->Noise.ucCPITestOn)
	{
		if(!thisInfo->WinCertMode && thisInfo->tCoord.cScreenDebCnt[0]<COORD_HISTORY_NUM){
			for(idx=0;idx<COL_MAX/5;idx++){
				if(RawPartSumCnt[idx] != 0)
					RawPartSum[idx] /= RawPartSumCnt[idx];
				if(idx>0){
					if(abs(RawPartSum[idx] - RawPartSum[idx-1])>1000)
						AbnormalRawCnt = RawPartSumCnt[idx];
				}
				
				if(AbnormalDeltaCntInMux[idx] > 50 || DeltaEdgeCntInMux > (ROW_MAX>>1) )
					thisInfo->UnstableStateFrm = 400;
		//		if(AbnormalDeltaCntInMux[idx] >= 200)
		//			thisInfo->UnstableStateFrm = 400;
			}
			
			if(thisInfo->UnstableStateFrm && wdt_init)
			{
				KICK_DOG();
				Hal_WDT_DeInit();
			}
			
			if(AbnormalRawCnt >= 5){
				memset(DELTAIMAGE,0,sizeof(DELTAIMAGE));
				GoToThisState = TOUCH_NORMAL_OPER_RESET_HAL;
				thisInfo->UnstableStateFrm = 0;
			}
			
			{
				static uint16_t AbnormalFrmCnt = 0;
				static uint8_t ResetDelayCount = 0;

				if(thisInfo->UnstableStateFrm){
					memset(DELTAIMAGE,0,sizeof(DELTAIMAGE));
					if(ResetDelayCount++ > 10){
						GoToThisState = TOUCH_NORMAL_OPER_RESET_HAL;
					}	
				}
				if(GoToThisState == TOUCH_NORMAL_OPER_RESET_HAL)
				{
					thisInfo->UnstableStateFrm = 0;
					AbnormalFrmCnt = 0;
					ResetDelayCount = 0;
				}
			}
		}
	}
#endif
	
	if(  temp_delta->iMaxStrength > thisModeConf->BaseLine.sBlockPosThd )
	{
		thisInfo->bBlockTracking = YES;
	}
	
	if( temp_delta->iMinStrength < thisModeConf->BaseLine.sBlockNegThd )
	{
		thisInfo->bBlockTracking = YES;
	}
	
#if USED_PEN_MODE_OPERATION
	if(mode == FULL_MODE)
	{
		if(thisInfo->sLFingerMinVal < -30 && 
			((thisInfo->tLFingerMinCell.r-1 <= temp_delta->tMinCellPos.r && temp_delta->tMinCellPos.r <= thisInfo->tLFingerMinCell.r+1) && 
			(thisInfo->tLFingerMinCell.c-1 <= temp_delta->tMinCellPos.c && temp_delta->tMinCellPos.c <= thisInfo->tLFingerMinCell.c+1)))
			temp_delta->iMinStrength = /*pen_touch_data =*/ 0;
		
	//	if(pen_touch_data > 30 || pen_touch_data2 < -70)
	//	{
	//		thisInfo->bLocal_sensing = YES;
	////		hal_Info_SetPenDectionEnable(YES);
	//		algorithm_baseline_calculate_mux_range(pen_pos.r+local_rs, pen_pos.c);
	//	}
	}
	else
	{
		thisInfo->sLFingerMinVal = temp_delta->iMinStrength;
		thisInfo->tLFingerMinCell = temp_delta->tMinCellPos;		
	}
#endif /* USED_PEN_MODE_OPERATION */

	return thisInfo->bBlockTracking;
}

#if 0
bool_t algorithm_baseline_calculate_delta_localFinger(int mode)
{
	int r, c;
	int delta;	
	uint16_t read_raw_data;
	tCell_t pen_pos;
	tOrigDeltaInfo_t	*temp_delta;
//	uint16_t * pRawImage;
	uint16_t * pBaseImage;
	
	thisInfo->bBlockTracking = NO;

	temp_delta = &thisInfo->tDelta;

	memset((void *)temp_delta, 0x00, sizeof(tOrigDeltaInfo_t));
	temp_delta->tValidRect.cs = COL_MAX - 1; temp_delta->tValidRect.ce = 0;
	temp_delta->tValidRect.rs = ROW_MAX - 1; temp_delta->tValidRect.re = 0;

	pBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);

	for( r=0; r<ROW_MAX; r++ )
	{
		for( c=0; c<COL_MAX; c++ )
		{
			read_raw_data = HAL_READ_LOCAL_FINGER_RAW_IMAGE(r,c);
			delta = (signed)read_raw_data - (signed)pBaseImage[(r*COL_MAX) + c];

//			if(/*HAL_READ_RAW_IMAGE(r,c) > MAXRAWDATA_MARGIN || */read_raw_data < MINRAWDATA_MARGIN)
//			{
//                abnormal_rawdata_temp(TRUE);
//			}

			delta >>= ptModuleModeConf->ucOvrShift;
			HAL_WRITE_LOCAL_FINGER_DELTA_IMAGE(r, c, delta);

			if( delta > 0 )
			{
//				if( delta > thisModeConf->BaseLine.sBlockPosThd )
//				{
//					thisInfo->bBlockTracking = YES;
//				}

				if( delta > thisModeConf->BaseLine.sAccumPosSumThd )
				{
					temp_delta->iPosCnt++;
					temp_delta->iPosSum += delta - thisModeConf->BaseLine.sAccumPosSumThd;
				}

				if( delta > thisModeConf->Label.usSeedBase )
				{
					if( temp_delta->tValidRect.cs > c )
						temp_delta->tValidRect.cs = c;
					if( temp_delta->tValidRect.ce < c )
						temp_delta->tValidRect.ce = c;
					if( temp_delta->tValidRect.rs > r )
						temp_delta->tValidRect.rs = r;
					if( temp_delta->tValidRect.re < r )
						temp_delta->tValidRect.re = r;

					temp_delta->iGroupedCellCnt++;
				}

				if( temp_delta->iMaxStrength < delta )
				{
					temp_delta->iMaxStrength = delta;
				}
			}
			else
			{
//				if( delta < thisModeConf->BaseLine.sBlockNegThd )
//				{
//					thisInfo->bBlockTracking = YES;
//				}

				if( delta < thisModeConf->BaseLine.sAccumNegSumThd )
				{
					temp_delta->iNegCnt++;
					temp_delta->iNegSum += delta - thisModeConf->BaseLine.sAccumNegSumThd;
				}

				if( temp_delta->iMinStrength > delta )
				{
					temp_delta->iMinStrength = delta;

//					pen_touch_data = -delta;
					pen_pos.r = r;
					pen_pos.c = c;
				}
			}
		}
	}

	if(  temp_delta->iMaxStrength > thisModeConf->BaseLine.sBlockPosThd )
	{
		thisInfo->bBlockTracking = YES;
	}
	
	if( temp_delta->iMinStrength < thisModeConf->BaseLine.sBlockNegThd )
	{
		thisInfo->bBlockTracking = YES;
	}
	
	thisInfo->sLFingerMinVal = temp_delta->iMinStrength;
	thisInfo->tLFingerMinCell = pen_pos;
	
	thisInfo->bTouchExpect = (temp_delta->iGroupedCellCnt >0);

	return thisInfo->bBlockTracking;
}
#endif

#if USED_IDLE_MODE_CONTROL
void algorithm_baseline_tracking_initial_idle(bool_t bIsSkip)
{
	uint32_t ulFrameNum, ulIdx;
	uint32_t ulNiIdxNum;
	uint32_t ulSkipFrameNum;
#ifdef SHORT_COMPENSATION
    int diff;
    uint16_t raw_diff_thd = 500;
#endif
    uint16_t temp_data, raw_val = 500;
#ifdef SHORT_COMPENSATION
	uint32_t raw_avg = 0;
	uint32_t raw_avg_Ni_1 = 0,  raw_avg_Ni_2 = 0;
	short_cnt = 0;
	memset(short_pos, 0, sizeof(short_pos));
#endif
	uint16_t * pNiRawImage;
	uint16_t * pNiInitRawImage;
	uint16_t * pNiBaseImage;
	uint16_t * pNiInitBaseImage;

	if(bIsSkip)
	{
		ulSkipFrameNum = thisModeConf->BaseLine.ucDiscardFrameNum;
	}
	else
	{
		ulSkipFrameNum = 1;
	}

    for(ulFrameNum=0; ulFrameNum<ulSkipFrameNum; ulFrameNum++)
    {
    	module_wait_NI_sample_done();
    }

#ifdef MODE_WDT
	KICK_DOG();
#endif

	pNiInitRawImage = pNiRawImage = HAL_NI_GET_RAW_IMAGE_PTR();
	pNiInitBaseImage = pNiBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);
    memset((void*)pNiBaseImage, 0x00, sizeof(uint16_t)*(NI_ROW_MAX * COL_MAX));
    ulNiIdxNum = NI_ROW_MAX * COL_MAX;

    for(ulFrameNum = thisModeConf->BaseLine.ucInitialFrameNum; ulFrameNum--; )
    {
    	module_wait_NI_sample_done();

		pNiRawImage = pNiInitRawImage;
		pNiBaseImage = pNiInitBaseImage;
		for(ulIdx = ulNiIdxNum; ulIdx--; )
		{
			raw_val = *(pNiRawImage++);
			temp_data = *(pNiBaseImage) + raw_val;
			*(pNiBaseImage++) = temp_data;
#ifdef SHORT_COMPENSATION
			raw_avg_Ni_1 += raw_val;
#endif
		}

#ifdef MODE_WDT
		KICK_DOG();
#endif
    }

#ifdef SHORT_COMPENSATION
	raw_avg /= (ROW_MAX*COL_MAX*thisModeConf->BaseLine.ucInitialFrameNum);
	raw_avg_Ni_1 /= (NI_ROW_MAX*COL_MAX*thisModeConf->BaseLine.ucInitialFrameNum);
	raw_avg_Ni_2 /= (NI_ROW_MAX*COL_MAX*thisModeConf->BaseLine.ucInitialFrameNum);
#endif

	pNiBaseImage = pNiInitBaseImage;
	for(ulIdx = ulNiIdxNum; ulIdx--; )
	{
		temp_data = (*pNiBaseImage);
		temp_data /= thisModeConf->BaseLine.ucInitialFrameNum;
		(*pNiBaseImage++) = temp_data;
#ifdef SHORT_COMPENSATION
		diff = raw_avg_Ni_1 - temp_data;
		if( diff > raw_diff_thd && short_cnt < SHORT_NUM )
		{
			short_pos[short_cnt].c = c;
			short_pos[short_cnt].r = r;
			short_cnt++;
		}
#endif
	}

#ifdef MODE_WDT
	KICK_DOG();
#endif
}

void algorithm_baseline_tracking_continuous_idle(void)
{
	uint32_t ulIdx;
	uint32_t ulIdleIdxNum;
	uint16_t * pIdleRawImage;
	uint16_t * pIdleBaseImage;
	int prev_baseline, curr_baseline, curr_rawdata, alpha;

    if(thisInfo->bBlockTracking == NO)
    {
    	ulIdleIdxNum = COL_MAX * NI_ROW_MAX;
		alpha = thisModeConf->BaseLine.usIIRCoef;

		pIdleRawImage = HAL_NI_GET_RAW_IMAGE_PTR();
		pIdleBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);
		for(ulIdx = 0; ulIdx < ulIdleIdxNum; ulIdx++)
		{
			curr_rawdata = (*(pIdleRawImage++)) + sLFOffsetRow[ulIdx / COL_MAX];
			prev_baseline = (*pIdleBaseImage);
			curr_baseline = (alpha * prev_baseline + (BASELINE_TRACKING_RESOLUTION-alpha) * curr_rawdata)/BASELINE_TRACKING_RESOLUTION;
			*(pIdleBaseImage++) = (uint16_t)curr_baseline;
		}
    }
}

void algorithm_baseline_calculate_delta_idle(void)
{
	uint32_t r, c;
	int16_t delta;
	uint16_t read_raw_data;
	uint16_t * pIdleBaseImage;
	tIdleDeltaInfo_t * ptTempIdleDeltaInfo;

	thisInfo->bBlockTracking = NO;
	thisInfo->bTouchExpect = NO;

	ptTempIdleDeltaInfo = &thisInfo->tIdleDeltaInfo;

	ptTempIdleDeltaInfo->sMaxStrength = -4096;
	ptTempIdleDeltaInfo->sMinStrength = 4096;

	pIdleBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);
	for(r=0; r<NI_ROW_MAX; r++)
	{
		for(c=0; c<COL_MAX; c++)
		{
			read_raw_data = HAL_NI_READ_RAW_IMAGE(r, c);
			delta = (int16_t)read_raw_data - (int16_t)(*(pIdleBaseImage++));
			delta >>= ptModuleModeConf->ucIdleOvrShift;

			HAL_NI_WRITE_DELTA_IMAGE(r, c, delta);

			if(ptTempIdleDeltaInfo->sMaxStrength < delta)
			{
				ptTempIdleDeltaInfo->sMaxStrength = delta;
				ptTempIdleDeltaInfo->ulMaxNodeColIndex = c;
			}

			if(ptTempIdleDeltaInfo->sMinStrength > delta)
			{
				ptTempIdleDeltaInfo->sMinStrength = delta;
				ptTempIdleDeltaInfo->ulMinNodeColIndex = c;
			}
		}
	}

	if(ptTempIdleDeltaInfo->sMaxStrength > thisModeConf->BaseLine.sIdle_BlockPosThd ||
		ptTempIdleDeltaInfo->sMinStrength < thisModeConf->BaseLine.sIdle_BlockNegThd)
	{
		uint32_t ulCheckNodeColIdx;
		if(ABS(ptTempIdleDeltaInfo->sMaxStrength) > ABS(ptTempIdleDeltaInfo->sMinStrength))
		{
			ulCheckNodeColIdx = ptTempIdleDeltaInfo->ulMaxNodeColIndex;
		}
		else
		{
			ulCheckNodeColIdx = ptTempIdleDeltaInfo->ulMinNodeColIndex;
		}
		ptTempIdleDeltaInfo->sColumStrengthTotalSum = 0;

		for(r=0; r<NI_ROW_MAX; r++)
		{
			ptTempIdleDeltaInfo->sColumStrengthTotalSum += HAL_NI_READ_DELTA_IMAGE(r, ulCheckNodeColIdx);
		}

		if(ptTempIdleDeltaInfo->sColumStrengthTotalSum > thisModeConf->BaseLine.sIdle_PosTotalSumThd ||
			ptTempIdleDeltaInfo->sColumStrengthTotalSum < thisModeConf->BaseLine.sIdle_NegTotalSumThd)
		{
			ptTempIdleDeltaInfo->sPrevMaxStrength = ptTempIdleDeltaInfo->sMaxStrength;
			ptTempIdleDeltaInfo->sPrevMinStrength = ptTempIdleDeltaInfo->sMinStrength;

#if !USED_ONLY_IDLE_MODE
			thisInfo->bTouchExpect = YES;
#endif /* !USED_ONLY_IDLE_MODE */
		}

		thisInfo->bBlockTracking = YES;
	}
}
#endif /* USED_IDLE_MODE_CONTROL */

#if USED_LOCAL_IDLE_MODE_CONTROL
void algorithm_baseline_tracking_initial_local_idle(bool_t bIsSkip)
{
	uint32_t ulFrameNum, ulIdx;
	uint32_t ulNiIdxNum;
	uint32_t ulSkipFrameNum;
#ifdef SHORT_COMPENSATION
    int diff;
    uint16_t raw_diff_thd = 500;
#endif
    uint16_t temp_data, raw_val = 500;
#ifdef SHORT_COMPENSATION
	uint32_t raw_avg = 0;
	uint32_t raw_avg_Ni_1 = 0,  raw_avg_Ni_2 = 0;
	short_cnt = 0;
	memset(short_pos, 0, sizeof(short_pos));
#endif
	uint16_t * pNiRawImage;
	uint16_t * pNiInitRawImage;
	uint16_t * pNiBaseImage;
	uint16_t * pNiInitBaseImage;

	if(bIsSkip)
	{
		ulSkipFrameNum = thisModeConf->BaseLine.ucDiscardFrameNum;
	}
	else
	{
		ulSkipFrameNum = 1;
	}

    for(ulFrameNum=0; ulFrameNum<ulSkipFrameNum; ulFrameNum++)
    {
    	module_wait_NI_sample_done();
    }

#ifdef MODE_WDT
	KICK_DOG();
#endif

	pNiInitRawImage = pNiRawImage = HAL_NI_GET_RAW_IMAGE_PTR();
	pNiInitBaseImage = pNiBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);
    memset((void*)pNiBaseImage, 0x00, sizeof(uint16_t)*(NI_ROW_MAX * COL_MAX));
    ulNiIdxNum = NI_ROW_MAX * COL_MAX;

    for(ulFrameNum = thisModeConf->BaseLine.ucInitialFrameNum; ulFrameNum--; )
    {
    	module_wait_NI_sample_done();

		pNiRawImage = pNiInitRawImage;
		pNiBaseImage = pNiInitBaseImage;
		for(ulIdx = ulNiIdxNum; ulIdx--; )
		{
			raw_val = *(pNiRawImage++);
			temp_data = *(pNiBaseImage) + raw_val;
			*(pNiBaseImage++) = temp_data;
#ifdef SHORT_COMPENSATION
			raw_avg_Ni_1 += raw_val;
#endif
		}

#ifdef MODE_WDT
		KICK_DOG();
#endif
    }

#ifdef SHORT_COMPENSATION
	raw_avg /= (ROW_MAX*COL_MAX*thisModeConf->BaseLine.ucInitialFrameNum);
	raw_avg_Ni_1 /= (NI_ROW_MAX*COL_MAX*thisModeConf->BaseLine.ucInitialFrameNum);
	raw_avg_Ni_2 /= (NI_ROW_MAX*COL_MAX*thisModeConf->BaseLine.ucInitialFrameNum);
#endif

	pNiBaseImage = pNiInitBaseImage;
	for(ulIdx = ulNiIdxNum; ulIdx--; )
	{
		temp_data = (*pNiBaseImage);
		temp_data /= thisModeConf->BaseLine.ucInitialFrameNum;
		(*pNiBaseImage++) = temp_data;
#ifdef SHORT_COMPENSATION
		diff = raw_avg_Ni_1 - temp_data;
		if( diff > raw_diff_thd && short_cnt < SHORT_NUM )
		{
			short_pos[short_cnt].c = c;
			short_pos[short_cnt].r = r;
			short_cnt++;
		}
#endif
	}

#ifdef MODE_WDT
	KICK_DOG();
#endif
}

void algorithm_baseline_tracking_continuous_local_idle(void)
{
	uint32_t ulIdx;
	uint32_t ulLocalIdleIdxNum;
	uint16_t * pLocalIdleRawImage;
	uint16_t * pLocalIdleBaseImage;
	int prev_baseline, curr_baseline, curr_rawdata, alpha;

    if(thisInfo->bBlockTracking == NO)
    {
    	ulLocalIdleIdxNum = COL_MAX * NI_ROW_MAX;
		alpha = thisModeConf->BaseLine.usIIRCoef;

		pLocalIdleRawImage = HAL_NI_GET_RAW_IMAGE_PTR();
		pLocalIdleBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);
		for(ulIdx = 0; ulIdx < ulLocalIdleIdxNum; ulIdx++)
		{
			curr_rawdata = (*(pLocalIdleRawImage++)) + sLFOffsetRow[ulIdx / COL_MAX];
			prev_baseline = (*pLocalIdleBaseImage);
			curr_baseline = (alpha * prev_baseline + (BASELINE_TRACKING_RESOLUTION-alpha) * curr_rawdata)/BASELINE_TRACKING_RESOLUTION;
			*(pLocalIdleBaseImage++) = (uint16_t)curr_baseline;
		}
    }
}

#if (USED_MODULE_DEF == MODULE_DEF_L_1)
void algorithm_baseline_calculate_delta_local_idle(void)
{
	int r, c;
	int delta;
	uint16_t read_raw_data;
	tOrigDeltaInfo_t * pTemp_delta;
	uint16_t * pIdleBaseImage;

	thisInfo->bBlockTracking = NO;
	thisInfo->bTouchExpect = NO;

	pTemp_delta = &thisInfo->tDelta;
	memset((void *)pTemp_delta, 0x00, sizeof(tOrigDeltaInfo_t));
	pIdleBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);

	for(r=0; r<NI_ROW_MAX; r++)
	{
		for(c=0; c<COL_MAX; c++)
		{
			read_raw_data = HAL_NI_READ_RAW_IMAGE(r, c);
			delta = (signed)read_raw_data - (signed)(*(pIdleBaseImage++));
			delta >>= ptModuleModeConf->ucIdleOvrShift;

			HAL_NI_WRITE_DELTA_IMAGE(r, c, delta);

			if(delta > 0)
			{
				if(pTemp_delta->iMaxStrength < delta)
				{
					pTemp_delta->iMaxStrength = delta;
				}
			}
			else
			{
				if(pTemp_delta->iMinStrength > delta)
				{
					pTemp_delta->iMinStrength = delta;
				}
			}
		}
	}

	if(pTemp_delta->iMaxStrength > 50 ||
	   pTemp_delta->iMinStrength < -30)
	{
#if !USED_ONLY_IDLE_MODE
		thisInfo->bTouchExpect = YES;
#endif /* !USED_ONLY_IDLE_MODE */
		thisInfo->bBlockTracking = YES;
	}
}
#else /* (USED_MODULE_DEF == MODULE_DEF_L_1) */

void algorithm_baseline_calculate_delta_local_idle(void)
{
	uint32_t r, c;
	uint32_t ulCheckNodeColIdx;
	int16_t delta, delta2, delta_sum;
	uint16_t read_raw_data;
	uint16_t * pIdleBaseImage;
	uint16_t * pIdleBaseImage_2;
	tLocalIdleDeltaInfo_t * ptTempLocalIdleDeltaInfo;

	thisInfo->bBlockTracking = NO;
	thisInfo->bTouchExpect = NO;

	ptTempLocalIdleDeltaInfo = &thisInfo->tLocalIdleDeltaInfo;

	ptTempLocalIdleDeltaInfo->sMaxStrength = -4096;
	ptTempLocalIdleDeltaInfo->sMinStrength = 4096;
#if USED_LOCAL_IDLE_PEN_OTHER_CONTROL
	ptTempLocalIdleDeltaInfo->sPenMaxStrength = -4096;
	ptTempLocalIdleDeltaInfo->sPenMinStrength = 4096;
#endif /* USED_LOCAL_IDLE_PEN_OTHER_CONTROL */

	/*
	 * Step 1 : Finger Intensity Check!!
	 */
	pIdleBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
	for(r=0; r<LOCAL_FINGER_1MUX_ROW_NUM; r++)
	{
		for(c=0; c<COL_MAX; c++)
		{
			read_raw_data = HAL_NI_READ_RAW_IMAGE(r, c);
			delta = (int16_t)read_raw_data - (int16_t)(*(pIdleBaseImage++));
			delta >>= ptModuleModeConf->ucIdleOvrShift;

			HAL_NI_WRITE_DELTA_IMAGE(r, c, delta);

			if(ptTempLocalIdleDeltaInfo->sMaxStrength < delta)
			{
				ptTempLocalIdleDeltaInfo->sMaxStrength = delta;
				ptTempLocalIdleDeltaInfo->ulMaxNodeColIndex = c;
			}

			if(ptTempLocalIdleDeltaInfo->sMinStrength > delta)
			{
				ptTempLocalIdleDeltaInfo->sMinStrength = delta;
				ptTempLocalIdleDeltaInfo->ulMinNodeColIndex = c;
			}
		}
	}

	if(ptTempLocalIdleDeltaInfo->sMaxStrength > thisModeConf->BaseLine.sIdle_BlockPosThd ||
			ptTempLocalIdleDeltaInfo->sMinStrength < thisModeConf->BaseLine.sIdle_BlockNegThd)
	{
		if(ABS(ptTempLocalIdleDeltaInfo->sMaxStrength) > ABS(ptTempLocalIdleDeltaInfo->sMinStrength))
		{
			ulCheckNodeColIdx = ptTempLocalIdleDeltaInfo->ulMaxNodeColIndex;
		}
		else
		{
			ulCheckNodeColIdx = ptTempLocalIdleDeltaInfo->ulMinNodeColIndex;
		}
		ptTempLocalIdleDeltaInfo->sColumStrengthTotalSum = 0;

		for(r=0; r<NI_ROW_MAX; r++)
		{
			ptTempLocalIdleDeltaInfo->sColumStrengthTotalSum += HAL_NI_READ_DELTA_IMAGE(r, ulCheckNodeColIdx);
		}

		if(ptTempLocalIdleDeltaInfo->sColumStrengthTotalSum > thisModeConf->BaseLine.sIdle_PosTotalSumThd ||
				ptTempLocalIdleDeltaInfo->sColumStrengthTotalSum < thisModeConf->BaseLine.sIdle_NegTotalSumThd)
		{
			ptTempLocalIdleDeltaInfo->sPrevMaxStrength = ptTempLocalIdleDeltaInfo->sMaxStrength;
			ptTempLocalIdleDeltaInfo->sPrevMinStrength = ptTempLocalIdleDeltaInfo->sMinStrength;

#if !USED_ONLY_LOCAL_IDLE_MODE
			thisInfo->bTouchExpect = YES;
#endif /* !USED_ONLY_LOCAL_IDLE_MODE */
		}

		thisInfo->bBlockTracking = YES;
	}

#if USED_LOCAL_IDLE_PEN_OTHER_CONTROL
	/*
	 * Step 2 : Pen Intensity Check!!
	 */
	if(thisInfo->bTouchExpect == NO)
	{
		pIdleBaseImage_2 = pIdleBaseImage + (PEN_COORD_ROW_MAX * COL_MAX);
		for(r=LOCAL_FINGER_1MUX_ROW_NUM; r<(LOCAL_FINGER_1MUX_ROW_NUM+PEN_COORD_ROW_MAX); r++)
		{
			for(c=0; c<COL_MAX; c++)
			{
				read_raw_data = HAL_NI_READ_RAW_IMAGE(r, c);
				delta = (signed)(*(pIdleBaseImage++)) - (signed)read_raw_data;
				delta >>= ptModuleModeConf->ucLocalIdleOvrShift;

				read_raw_data = HAL_NI_READ_RAW_IMAGE(r+PEN_COORD_ROW_MAX, c);
				delta2 = (signed)(*(pIdleBaseImage_2++)) - (signed)read_raw_data;
				delta2 >>= ptModuleModeConf->ucLocalIdleOvrShift;

				delta += delta2;

				delta_sum = delta / 2;

				HAL_NI_WRITE_DELTA_IMAGE(r, c, delta_sum);

				if(ptTempLocalIdleDeltaInfo->sPenMaxStrength < delta_sum)
				{
					ptTempLocalIdleDeltaInfo->sPenMaxStrength = delta_sum;
					ptTempLocalIdleDeltaInfo->ulPenMaxNodeColIndex = c;
				}

				if(ptTempLocalIdleDeltaInfo->sPenMinStrength > delta_sum)
				{
					ptTempLocalIdleDeltaInfo->sPenMinStrength = delta_sum;
					ptTempLocalIdleDeltaInfo->ulPenMinNodeColIndex = c;
				}
			}
		}

		if(ptTempLocalIdleDeltaInfo->sPenMaxStrength > thisModeConf->BaseLine.sLocalIdle_BlockPosThd ||
				ptTempLocalIdleDeltaInfo->sPenMinStrength < thisModeConf->BaseLine.sLocalIdle_BlockNegThd)
		{
			if(ABS(ptTempLocalIdleDeltaInfo->sPenMaxStrength) > ABS(ptTempLocalIdleDeltaInfo->sPenMinStrength))
			{
				ulCheckNodeColIdx = ptTempLocalIdleDeltaInfo->ulPenMaxNodeColIndex;
			}
			else
			{
				ulCheckNodeColIdx = ptTempLocalIdleDeltaInfo->ulPenMinNodeColIndex;
			}
			ptTempLocalIdleDeltaInfo->sPenColumStrengthTotalSum = 0;

			for(r=LOCAL_FINGER_1MUX_ROW_NUM; r<(LOCAL_FINGER_1MUX_ROW_NUM+PEN_COORD_ROW_MAX); r++)
			{
				ptTempLocalIdleDeltaInfo->sPenColumStrengthTotalSum += HAL_NI_READ_DELTA_IMAGE(r, ulCheckNodeColIdx);
			}

			if(ptTempLocalIdleDeltaInfo->sPenColumStrengthTotalSum > thisModeConf->BaseLine.sLocalIdle_PosTotalSumThd ||
					ptTempLocalIdleDeltaInfo->sPenColumStrengthTotalSum < thisModeConf->BaseLine.sLocalIdle_NegTotalSumThd)
			{
				ptTempLocalIdleDeltaInfo->sPenPrevMaxStrength = ptTempLocalIdleDeltaInfo->sPenMaxStrength;
				ptTempLocalIdleDeltaInfo->sPenPrevMinStrength = ptTempLocalIdleDeltaInfo->sPenMinStrength;

	#if !USED_ONLY_LOCAL_IDLE_MODE
				thisInfo->bTouchExpect = YES;
	#endif /* !USED_ONLY_LOCAL_IDLE_MODE */
			}

			thisInfo->bBlockTracking = YES;
		}
	}
#endif /* USED_LOCAL_IDLE_PEN_OTHER_CONTROL */
}
#endif /* (USED_MODULE_DEF == MODULE_DEF_L_1) */

#endif /* USED_LOCAL_IDLE_MODE_CONTROL */

#if USED_MNT_S3_MODE_FUNCTION
void algorithm_baseline_tracking_initial_S3(bool_t bIsSkip)
{
	uint32_t ulFrameNum, ulIdx;
	uint32_t ulNiIdxNum;
	uint32_t ulSkipFrameNum;
#ifdef SHORT_COMPENSATION
    int diff;
    uint16_t raw_diff_thd = 500;
#endif
    uint16_t temp_data, raw_val = 500;
#ifdef SHORT_COMPENSATION
	uint32_t raw_avg = 0;
	uint32_t raw_avg_Ni_1 = 0,  raw_avg_Ni_2 = 0;
	short_cnt = 0;
	memset(short_pos, 0, sizeof(short_pos));
#endif
	uint16_t * pNiRawImage;
	uint16_t * pNiInitRawImage;
	uint16_t * pNiBaseImage;
	uint16_t * pNiInitBaseImage;

	if(bIsSkip)
	{
		ulSkipFrameNum = thisModeConf->BaseLine.ucDiscardFrameNum;
	}
	else
	{
		ulSkipFrameNum = 3;
	}

    for(ulFrameNum=0; ulFrameNum<ulSkipFrameNum; ulFrameNum++)
    {
    	module_wait_S3_sample_done();
    }

#ifdef MODE_WDT
	KICK_DOG();
#endif

	pNiInitRawImage = pNiRawImage = HAL_NI_GET_RAW_IMAGE_PTR();
	pNiInitBaseImage = pNiBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);
    memset((void*)pNiBaseImage, 0x00, sizeof(uint16_t)*(NI_ROW_MAX * COL_MAX));
    ulNiIdxNum = NI_ROW_MAX * COL_MAX;

    for(ulFrameNum = thisModeConf->BaseLine.ucInitialFrameNum; ulFrameNum--; )
    {
    	module_wait_S3_sample_done();

		pNiRawImage = pNiInitRawImage;
		pNiBaseImage = pNiInitBaseImage;
		for(ulIdx = ulNiIdxNum; ulIdx--; )
		{
			raw_val = *(pNiRawImage++);
			temp_data = *(pNiBaseImage) + raw_val;
			*(pNiBaseImage++) = temp_data;
#ifdef SHORT_COMPENSATION
			raw_avg_Ni_1 += raw_val;
#endif
		}

#ifdef MODE_WDT
		KICK_DOG();
#endif
    }

#ifdef SHORT_COMPENSATION
	raw_avg /= (ROW_MAX*COL_MAX*thisModeConf->BaseLine.ucInitialFrameNum);
	raw_avg_Ni_1 /= (NI_ROW_MAX*COL_MAX*thisModeConf->BaseLine.ucInitialFrameNum);
	raw_avg_Ni_2 /= (NI_ROW_MAX*COL_MAX*thisModeConf->BaseLine.ucInitialFrameNum);
#endif

	pNiBaseImage = pNiInitBaseImage;
	for(ulIdx = ulNiIdxNum; ulIdx--; )
	{
		temp_data = (*pNiBaseImage);
		temp_data /= thisModeConf->BaseLine.ucInitialFrameNum;
		(*pNiBaseImage++) = temp_data;
#ifdef SHORT_COMPENSATION
		diff = raw_avg_Ni_1 - temp_data;
		if( diff > raw_diff_thd && short_cnt < SHORT_NUM )
		{
			short_pos[short_cnt].c = c;
			short_pos[short_cnt].r = r;
			short_cnt++;
		}
#endif
	}

#ifdef MODE_WDT
	KICK_DOG();
#endif
}

void algorithm_baseline_tracking_continuous_S3(void)
{
	uint32_t ulIdx;
	uint32_t ulS3IdxNum;
	uint16_t * pS3RawImage;
	uint16_t * pS3BaseImage;
	int prev_baseline, curr_baseline, curr_rawdata, alpha;

    if(thisInfo->bBlockTracking == NO)
    {
    	ulS3IdxNum = COL_MAX * NI_ROW_MAX;
		alpha = thisModeConf->BaseLine.usIIRCoef;

		pS3RawImage = HAL_NI_GET_RAW_IMAGE_PTR();
		pS3BaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);
		for(ulIdx = 0; ulIdx < ulS3IdxNum; ulIdx++)
		{
			curr_rawdata = (*(pS3RawImage++)) + sLFOffsetRow[ulIdx / COL_MAX];
			prev_baseline = (*pS3BaseImage);
			curr_baseline = (alpha * prev_baseline + (BASELINE_TRACKING_RESOLUTION-alpha) * curr_rawdata)/BASELINE_TRACKING_RESOLUTION;
			*(pS3BaseImage++) = (uint16_t)curr_baseline;
		}
    }
}

void algorithm_baseline_calculate_delta_S3(void)
{
	uint32_t r, c;
	int16_t delta;
	uint16_t read_raw_data;
	uint16_t * pS3BaseImage;
	tS3DeltaInfo_t * ptTempS3DeltaInfo;

	thisInfo->bBlockTracking = NO;
	thisInfo->bTouchExpect = NO;

	ptTempS3DeltaInfo = &thisInfo->tS3DeltaInfo;

	ptTempS3DeltaInfo->sMaxStrength = -4096;
	ptTempS3DeltaInfo->sMinStrength = 4096;

	pS3BaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);
	for(r=0; r<NI_ROW_MAX; r++)
	{
		for(c=0; c<COL_MAX; c++)
		{
			read_raw_data = HAL_NI_READ_RAW_IMAGE(r, c);
			delta = (int16_t)read_raw_data - (int16_t)(*(pS3BaseImage++));
			delta >>= ptModuleModeConf->ucIdleOvrShift;

			HAL_NI_WRITE_DELTA_IMAGE(r, c, delta);

			if(ptTempS3DeltaInfo->sMaxStrength < delta)
			{
				ptTempS3DeltaInfo->sMaxStrength = delta;
				ptTempS3DeltaInfo->ulMaxNodeColIndex = c;
			}

			if(ptTempS3DeltaInfo->sMinStrength > delta)
			{
				ptTempS3DeltaInfo->sMinStrength = delta;
				ptTempS3DeltaInfo->ulMinNodeColIndex = c;
			}
		}
	}

	if(ptTempS3DeltaInfo->sMaxStrength > thisModeConf->BaseLine.sS3_BlockPosThd ||
		ptTempS3DeltaInfo->sMinStrength < thisModeConf->BaseLine.sS3_BlockNegThd)
	{
		uint32_t ulCheckNodeColIdx;
		if(ABS(ptTempS3DeltaInfo->sMaxStrength) > ABS(ptTempS3DeltaInfo->sMinStrength))
		{
			ulCheckNodeColIdx = ptTempS3DeltaInfo->ulMaxNodeColIndex;
		}
		else
		{
			ulCheckNodeColIdx = ptTempS3DeltaInfo->ulMinNodeColIndex;
		}
		ptTempS3DeltaInfo->sColumStrengthTotalSum = 0;
		for(r=0; r<NI_ROW_MAX; r++)
		{
			ptTempS3DeltaInfo->sColumStrengthTotalSum += HAL_NI_READ_DELTA_IMAGE(r, ulCheckNodeColIdx);
		}

		if(ptTempS3DeltaInfo->sColumStrengthTotalSum > thisModeConf->BaseLine.sS3_PosTotalSumThd ||
			ptTempS3DeltaInfo->sColumStrengthTotalSum < thisModeConf->BaseLine.sS3_NegTotalSumThd)
		{
			ptTempS3DeltaInfo->sPrevMaxStrength = ptTempS3DeltaInfo->sMaxStrength;
			ptTempS3DeltaInfo->sPrevMinStrength = ptTempS3DeltaInfo->sMinStrength;

//			if((ptTempS3DeltaInfo->sPrevMaxStrength > 500 || ptTempS3DeltaInfo->sColumStrengthTotalSum < -500) &&
//				(ptTempS3DeltaInfo->sColumStrengthTotalSum > 2500 || ptTempS3DeltaInfo->sColumStrengthTotalSum < -2500))
//			{
//
//			}
//			else
			{
#if (!USED_ONLY_S3_MODE)
				thisInfo->bTouchExpect = YES;
#endif /* (!USED_ONLY_S3_MODE) */
			}
		}

		thisInfo->bBlockTracking = YES;
	}

#if USED_ONLY_IDLE_MODE
	thisInfo->bTouchExpect = NO;
	thisInfo->bBlockTracking = NO;
#endif /* USED_ONLY_IDLE_MODE */
}
#endif /* USED_MNT_S3_MODE_FUNCTION */
