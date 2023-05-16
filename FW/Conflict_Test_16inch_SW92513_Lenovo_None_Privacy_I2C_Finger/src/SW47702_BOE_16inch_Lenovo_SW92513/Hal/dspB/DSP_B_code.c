/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : DSP_B_code.c
 * created on : 10. 05. 2019
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


#if (USED_PEN_MODE_OPERATION)

static const tAlgorithmCommonConf_t * thisCommonConf = NULL;
static const tAlgorithmModeConf_t * thisModeConf = NULL;
static const tModuleModeConf_t * ptModuleModeConf  = NULL;
#if USED_NOISE_HOPPING_FREQ
static tAppInfo_t * ptAppInfo = NULL;
#endif /* USED_NOISE_HOPPING_FREQ */
static tAlgorithmInfo_t * thisInfo = NULL;
static tPenInfo_t * thisPenInfo = NULL;

extern uint16_t currentRowStart;
extern __IO uint16_t sensingRowStart;
extern __IO uint16_t sensingRowStart_Tilt;
#if USED_ADAPTIVE_LOCAL_SENSING
extern __IO uint16_t sensingRoicStart;
#endif /* USED_ADAPTIVE_LOCAL_SENSING */
extern uint16_t currentColStart;
extern 	ePartialSensing_t g_RetVal;
extern eActivePenType_t gAlgoRawDataType;
extern uint16_t p_currentRowStart;
tRingMSInfo_t pTRingInfo;
uint8_t data_store_bit[7][8] = {0,};
extern uint32_t RawAddr, BaseAddr, BaseAddr_MuxSum, RawAddr_MuxSum;
#define BlockTrackingThdByLocalDelta 15

extern uint16_t * g_pLocalBaseImage;
extern int16_t * g_pFullHoverImage;
#if USED_NOISE_HOPPING_FREQ
	extern uint16_t * g_pLocalHop1BaseImage;
#endif /* USED_NOISE_HOPPING_FREQ */

void algorithm_local_init(void)
{
	thisCommonConf   = algorithm_GetCommonConfig();
	thisInfo         = algorithm_GetInfo();
	thisPenInfo		 = &thisInfo->tPenInfo;
	thisModeConf     = algorithm_GetModeConfig();
	ptModuleModeConf = module_GetModeConfig();
#if USED_NOISE_HOPPING_FREQ
	ptAppInfo		 = app_GetInfo();
#endif /* USED_NOISE_HOPPING_FREQ */

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN)
	g_pLocalBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR();
	#if USED_NOISE_HOPPING_FREQ
		g_pLocalHop1BaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
	#endif /* USED_NOISE_HOPPING_FREQ */
	g_pFullHoverImage = HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR();
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	g_pLocalBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
	g_pFullHoverImage = HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR();
#else
	g_pLocalBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
	g_pFullHoverImage = HAL_GET_LOCAL_SEARCH_IMAGE_PTR();	
#endif
	
	algorithm_local_baseline_init();
}

void algorithm_init_param_dsp_code(void)
{
	thisModeConf     = algorithm_GetModeConfig();
	ptModuleModeConf = module_GetModeConfig();

#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP)
	{
		g_pLocalBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR();
		g_pFullHoverImage = HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR();
	}
	else
	{
		g_pLocalBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
		g_pFullHoverImage = HAL_GET_LOCAL_SEARCH_IMAGE_PTR();
	}
#endif
}

#if USED_TOUCH_TUNING_PROCESS
extern int16_t sLFOffsetRow[ROW_MAX];
void alogorithm_local_linefilter_1(int mode)
{
	uint32_t r, c;
//#define LINE_FILTER_UPPER_LIMIT			((100)<<ptModuleModeConf->ucOvrShift) //((16)<<ptModuleModeConf->ucOvrShift)
//#define LINE_FILTER_LOWER_LIMIT			(-((100)<<ptModuleModeConf->ucOvrShift)) //(-((16)<<ptModuleModeConf->ucOvrShift))
//#define LINE_FILTER_BIG_UPPER_LIMIT		((250)<<ptModuleModeConf->ucOvrShift)
//#define LINE_FILTER_BIG_LOWER_LIMIT		(-((250)<<ptModuleModeConf->ucOvrShift))
//#define LINE_FILTER_COL_OFFSET			(2)
	
	int16_t LINE_FILTER_UPPER_LIMIT			= thisModeConf->SensingFilter.sLineFilterUpLimit<<ptModuleModeConf->ucLocalOvrShift; 
	int16_t LINE_FILTER_LOWER_LIMIT			= thisModeConf->SensingFilter.sLineFilterLowLimit<<ptModuleModeConf->ucLocalOvrShift;
	uint8_t LINE_FILTER_COL_OFFSET			= (thisModeConf->SensingFilter.ucLineFilterColOffset);
	
	int16_t lDiff;
	int16_t lDiffSum = 0;
	uint32_t lDiffSumCnt = 0;
	int32_t lLowTHD, lUpperTHD;
	int16_t sLFOffsetRow = 0;
    
    uint16_t * pBaseImage;
    
	{
		lUpperTHD = LINE_FILTER_UPPER_LIMIT;
		lLowTHD = LINE_FILTER_LOWER_LIMIT;
	}

	int Max_Val, Min_Val;
#if USED_TOUCH_TUNING_PROCESS
	int LineFilterRepeatTH = 0;
#else /* USED_TOUCH_TUNING_PROCESS */
	int LineFilterRepeatTH = thisModeConf->SensingFilter.ucLineFilterRepeatTH << ptModuleModeConf->ucLocalOvrShift;
#endif /* USED_TOUCH_TUNING_PROCESS */
	int row_end = PEN_COORD_ROW_MAX;	

	if(thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode && mode == LOCAL_SEARCH_MODE)
		row_end += PEN_COORD_ROW_MAX;
	else if(mode != LOCAL_RING_MODE)
	{
		if( thisModeConf->BaseLine.b2MUX_SUM_LocalMode == 1)
			row_end += PEN_COORD_ROW_MAX;
	}

    switch(gAlgoRawDataType)
	{
		case ACTIVEPEN_TYPE_LOCAL_MS:
		{
			pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
			break;
		}
		case ACTIVEPEN_TYPE_LOCAL_WACOM:
		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
			pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR();
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
			break;
		}
	}

	uint16_t read_raw_data;
	uint8_t BaseOffset = thisModeConf->BaseLine.ucPP_MUX_Select * PEN_COORD_ROW_MAX;
	for(r=0; r<row_end; r++)
	{
		lDiffSumCnt = 0;
		lDiffSum = 0;
		
		Max_Val = 0;
//		Avg_Val = 0;
		Min_Val = 32767;
		for(c = 0; c < COL_MAX; c+=LINE_FILTER_COL_OFFSET)
		{
			if(mode!=LOCAL_RING_MODE)
			{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
				read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+BaseOffset, c);
#else
				read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+BaseOffset, c);
#endif
				if(r<PEN_COORD_ROW_MAX)
					lDiff = (int16_t)((signed)read_raw_data - (signed)pBaseImage[((r+sensingRowStart)*COL_MAX) + c]);
				else
					lDiff = (int16_t)((signed)read_raw_data  - (signed)pBaseImage[((r-PEN_COORD_ROW_MAX+sensingRowStart)*COL_MAX) + c]);
			}
			else
			{
				if(g_RetVal == PARTIAL_PEN_COORD1)
					lDiff = (int16_t)(HAL_READ_LOCAL_RING_RAW_IMAGE(r, c) - HAL_READ_RING_BASELINE_IMAGE(r+sensingRowStart,c));
				else if(g_RetVal == PARTIAL_PEN_COORD3)
					lDiff = (int16_t)(HAL_READ_LOCAL_RING_RAW_IMAGE(r+PEN_COORD_ROW_MAX, c) - HAL_READ_RING_BASELINE_IMAGE(r+sensingRowStart_Tilt,c));
			}
			//pBaseImage += LINE_FILTER_COL_OFFSET;
			if(lDiff < lUpperTHD && lDiff > lLowTHD)
			{
				if(Max_Val < lDiff)Max_Val = lDiff;
				if(Min_Val > lDiff)Min_Val = lDiff;
				lDiffSum += lDiff;
				lDiffSumCnt++;
			}
		}
//		Avg_Val = lDiffSum / ((int16_t)lDiffSumCnt);

		if(Max_Val - Min_Val > LineFilterRepeatTH  && LineFilterRepeatTH > 0)
		{
			lDiffSumCnt = 0;
			lDiffSum = 0;

			for(c = 0; c < COL_MAX; c+=LINE_FILTER_COL_OFFSET)
			{
				if(mode!=LOCAL_RING_MODE)
				{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)			
					read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+BaseOffset, c);
#else
					read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+BaseOffset, c);
#endif
					if(r<PEN_COORD_ROW_MAX)
						lDiff = (int16_t)((signed)read_raw_data - (signed)pBaseImage[((r+sensingRowStart)*COL_MAX) + c]);
					else
						lDiff = (int16_t)((signed)read_raw_data - (signed)pBaseImage[((r-PEN_COORD_ROW_MAX+sensingRowStart)*COL_MAX) + c]);
				}
				else
				{
					if(g_RetVal == PARTIAL_PEN_COORD1)
						lDiff = (int16_t)(HAL_READ_LOCAL_RING_RAW_IMAGE(r, c) - HAL_READ_RING_BASELINE_IMAGE(r+sensingRowStart,c));
					else if(g_RetVal == PARTIAL_PEN_COORD3)
						lDiff = (int16_t)(HAL_READ_LOCAL_RING_RAW_IMAGE(r+PEN_COORD_ROW_MAX, c) - HAL_READ_RING_BASELINE_IMAGE(r+sensingRowStart_Tilt,c));
				}
				if(lDiff < lUpperTHD && lDiff > lLowTHD)
				{
					if(abs(Max_Val - lDiff) > abs(Min_Val - lDiff))
					{
						lDiffSum += lDiff;
						lDiffSumCnt++;
					}
				}
			}			
		}
		
		if(lDiffSumCnt > 3)
		{
			sLFOffsetRow = lDiffSum / ((int16_t)lDiffSumCnt);
			
			for(c = 0; c < COL_MAX; c++)
			{
				if(mode!=LOCAL_RING_MODE)
				{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)			
					read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+BaseOffset, c);
#else
					read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+BaseOffset, c);
#endif
					lDiff = (((int16_t)read_raw_data) - sLFOffsetRow);
					if(lDiff < 0)lDiff = 0;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)	
					HAL_WRITE_LOCAL_DATA_RAW_IMAGE_3(r+BaseOffset, c, (uint16_t)lDiff);
#else
					HAL_WRITE_LOCAL_RAW_IMAGE(r+BaseOffset, c, (uint16_t)lDiff);
#endif
				}
				else
				{
					if(g_RetVal == PARTIAL_PEN_COORD1)
					{
						lDiff = (((int16_t)HAL_READ_LOCAL_RING_RAW_IMAGE(r,c)) - sLFOffsetRow);
						if(lDiff < 0)lDiff = 0;
						HAL_WRITE_LOCAL_RING_RAW_IMAGE(r, c, (uint16_t)lDiff);
					}
					else if(g_RetVal == PARTIAL_PEN_COORD3)
					{
						lDiff = (((int16_t)HAL_READ_LOCAL_RING_RAW_IMAGE(r+PEN_COORD_ROW_MAX,c)) - sLFOffsetRow);
						if(lDiff < 0)lDiff = 0;
						HAL_WRITE_LOCAL_RING_RAW_IMAGE(r+PEN_COORD_ROW_MAX, c, (uint16_t)lDiff);
					}
				}
			}
		}
	}
}
#endif

#if 0
void alogorithm_local_linefilter(void)
{
	int r, c;	
//	int local_rs, local_cs; // NOTE : not used!!
	int local_rs;
	int i, j;
	int16_t d;
	int16_t SortBufCol[COL_MAX], TempBuf;
	uint8_t sort_cnt, sort_range;
//	uint16_t * ptBaseLine; // NOTE : not used!!
	int sub_offset;

//	local_rs = currentRowStart*4;
	local_rs = currentRowStart;
//	local_cs = currentColStart; // NOTE : not used!!
	
//	thisInfo->bBlockTracking = YES;	

	if( /*thisModeConf->tDeltaImage.bLFEnable*/1 )
	{	    
		if( /*thisModeConf->tDeltaImage.bLFColwise*/1 )
		{
			sort_cnt = (uint8_t)(((int)COL_MAX * 5)/100);			
			sort_range = COL_MAX/4 + COL_MAX%4;

			for( r = 0; r < 8; r++ )
			{
				for( c = 0; c < sort_range; c++ )
				{
					SortBufCol[c] = HAL_READ_LOCAL_RAW_IMAGE(r, (c*4)) - HAL_READ_LOCAL_BASELINE_IMAGE(r+local_rs, (c*4));				
				}
				
				for( i=0; i<=(sort_cnt); i++ )
				{
					for( j=(i+1); j<sort_range; j++ )
					{
						if( SortBufCol[i] > SortBufCol[j] )
						{
							TempBuf = SortBufCol[i];
							SortBufCol[i] = SortBufCol[j];
							SortBufCol[j] = TempBuf;
						}
					}
				}					
				sLFOffsetRow[r] = SortBufCol[sort_cnt];
			}	
			
			for( r = 0; r<PEN_COORD_ROW_MAX; r++ )
			{
				for( c=0; c<PEN_COORD_COL_MAX; c++ )
				{		
				    d = (signed)HAL_READ_LOCAL_RAW_IMAGE(r, c);
					if(c<2 || c>COL_MAX-3)
					{
						sub_offset = sLFOffsetRow[r]>>2;
						sub_offset = sLFOffsetRow[r] - sub_offset;
					}
					else
						sub_offset = sLFOffsetRow[r];
					
//					d = d - sLFOffsetRow[r];
					d = d - sub_offset;
					// NOTE : what's mean??????
//					if(d-HAL_READ_LOCAL_BASELINE_IMAGE(r, c) > 640 || d-HAL_READ_LOCAL_BASELINE_IMAGE(r, c) < -640)
//						d=d;
					HAL_WRITE_LOCAL_RAW_IMAGE(r, c, (unsigned)d);
				}				
			}	
		}
	}
}
#endif

//void algorithm_baseline_calculate_local_mux_range_Tilt(int r)
//{
//#define PEN_LOCAL_ROW_HALF_IDX				(PEN_COORD_ROW_MAX>>1)
////	int sub_r = r;

//	if(r <= PEN_LOCAL_ROW_HALF_IDX)
//	{
//		sensingRowStart_Tilt = 0;
//	}
//	else if(r >= (ROW_MAX-1) - PEN_LOCAL_ROW_HALF_IDX)
//	{
//		sensingRowStart_Tilt = ROW_MAX - PEN_COORD_ROW_MAX;
//	}
//	else
//	{
//		sensingRowStart_Tilt = r - PEN_LOCAL_ROW_HALF_IDX;
//	}
//}

#define COL_CAL_SIZE						(8)
#define COL_CAL_HALF						(COL_CAL_SIZE>>1)
#define PEN_LOCAL_ROW_HALF_IDX				(PEN_COORD_ROW_MAX>>1)
void algorithm_baseline_calculate_local_mux_range(int r, int c, bool_t mode)
{
	int RowStart;
	
	if(protocol_swip_GetLocalIdxFixedEn())
	{
		RowStart = protocol_swip_GetLocalIdx();
	}
	else if(r <= PEN_LOCAL_ROW_HALF_IDX)
	{
		RowStart = 0;
	}
	else if(r >= (ROW_MAX-1) - PEN_LOCAL_ROW_HALF_IDX)
	{
		RowStart = ROW_MAX - PEN_COORD_ROW_MAX;
	}
	else
	{
		RowStart = r - PEN_LOCAL_ROW_HALF_IDX;
	}

#if USED_ADAPTIVE_LOCAL_SENSING
	if(c < (ROIC_COL_SIZE + ROIC_COL_SIZE_HALF))
	{
		sensingRoicStart = 0;
	}
	else if(c >= (COL_MAX - ROIC_COL_SIZE - ROIC_COL_SIZE_HALF))
	{
		sensingRoicStart = ROIC_NUM - 2;
	}
	else
	{
		sensingRoicStart = (uint16_t)((c - ROIC_COL_SIZE_HALF) / 6);
	}
#endif /* USED_ADAPTIVE_LOCAL_SENSING */

	if(mode == 1)
	{
		sensingRowStart_Tilt = RowStart;
	}
	else
	{
		sensingRowStart = RowStart;
		if(c<COL_CAL_HALF)
		{
			thisPenInfo->ucCurrentColumnStart = 0;
			thisPenInfo->ucCurrentColumnEnd = COL_CAL_SIZE;
		}
		else if(c+COL_CAL_HALF >= COL_MAX)
		{
			thisPenInfo->ucCurrentColumnStart = COL_MAX - COL_CAL_SIZE - 1;
			thisPenInfo->ucCurrentColumnEnd = COL_MAX - 1;
		}
		else
		{
			thisPenInfo->ucCurrentColumnStart = c-COL_CAL_HALF;
			thisPenInfo->ucCurrentColumnEnd = c+COL_CAL_HALF;
		}
	}
}

#if 0
void algorithm_local_baseline_3by3Sum()
{
	int gr, gc;
	int gi, gj;
	int sum_val = 0;
	int wr, wc;
	int window_sum;
	int rcnt, ccnt;
	
	uint8_t window_ratio[3][3] = {
		{1,2,1},
		{2,4,2},
		{1,2,1}
	};
	
//	for(gr=max_pos.r-1; gr<=max_pos.r+1; gr++)
	for(gr=0; gr<PEN_COORD_ROW_MAX; gr++)
	{
//		for(gc=max_pos.c-1; gc<=max_pos.c+1; gc++)
		for(gc=0; gc<PEN_COORD_COL_MAX; gc++)
		{
			sum_val = 0;
			window_sum = 0;
			rcnt = 0;
			for(gi=gr-1; gi<=gr+1; gi++)
			{
				if(0 <= gi && gi < 8)
				{
					ccnt = 0;
					for(gj=gc-1; gj<=gc+1; gj++)
					{
						if(0 <= gj && gj < PEN_COORD_COL_MAX)
						{
							sum_val += (HAL_READ_LOCAL_DELTA_IMAGE(gi,gj) * window_ratio[rcnt][ccnt]);
							window_sum +=  window_ratio[rcnt][ccnt];
						}
						ccnt++;
					}
				}
				rcnt++;
			}
			sum_val = (sum_val*9)/16;
			HAL_WRITE_LOCAL_PENSUM_IMAGE(gr, gc,sum_val+HAL_READ_LOCAL_PENSUM_IMAGE(gr,gc));
		}
	}
}
#endif

int algorithm_calc_3by3LocalDeltaSum(tCell_t calc_pos)
{
	int r,c,r_add,c_add;
	int sum_val = 0;
	
	for(r=calc_pos.r-1; r<=calc_pos.r+1; r++)
	{
		for(c=calc_pos.c-1; c<=calc_pos.c+1; c++)
		{
			if(r==-1)r_add = 2;
			else if(r==PEN_COORD_ROW_MAX)r_add = -2;
			else r_add = 0;

			if(c==-1)c_add = 2;
			else if(c==COL_MAX)c_add = -2;
			else c_add = 0;
			
			sum_val += thisPenInfo->pTmpModeDeltaImg[(r+r_add+PAD_)*(COL_MAX+PAD_+PAD_)+(c+c_add+PAD_)];
		}
	}
	
	return sum_val;
}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)	
void algorithm_local_Ring_direc_delta_base_pos(void)
{
	int r, c;
	int delta;
	int start_r, end_r;
	int start_c, end_c;
 	
	int direc9sum[9] = {0,};
	int r_d = sensingRowStart_Tilt - sensingRowStart;
	int c_d = thisInfo->tDelta_local.tMaxCellPos.c - thisInfo->tLabel_local_dsp.tValidMaxPos.c;
	int center_r = thisInfo->tDelta_local.tMaxCellPos.r - r_d;
	int center_c = thisInfo->tDelta_local.tMaxCellPos.c - c_d;
	start_r = MAX(0,center_r - 3);
	end_r = MIN(PEN_COORD_ROW_MAX-1,center_r + 3);
	start_c = MAX(center_c - 3,0); 
	end_c = MIN(center_c + 3,COL_MAX-1);  
	for( r=start_r; r<=end_r; r++ )
	{
		int delta_r_pos = (r+PAD_)*(COL_MAX+PAD_+PAD_);
		for( c=start_c; c<=end_c; c++ )
		{	
			delta = thisPenInfo->pTmpModeDeltaImg[delta_r_pos+c+PAD_];
//			delta = HAL_READ_RING_DELTA_IMAGE(r,c);
			if(r <= center_r-1 && c <= center_c-1)direc9sum[0] += delta;
			if(r <= center_r-1 && c >= center_c-1 && c <= center_c+1)direc9sum[1] += delta;
			if(r <= center_r-1 && c >= center_c+1)direc9sum[2] += delta;
			if(r >= center_r-1 && r <= center_r+1 && c <= center_c-1)direc9sum[3] += delta;
			if(r >= center_r-1 && r <= center_r+1 && c >= center_c-1 && c <= thisInfo->tLabel_local_dsp.tValidMaxPos.c+1)direc9sum[4] += delta;
			if(r >= center_r-1 && r <= center_r+1 && c >= center_c+1)direc9sum[5] += delta;
			if(r >= center_r+1 && c <= center_c-1)direc9sum[6] += delta;
			if(r >= center_r+1 && c >= center_c-1 && c <= center_c+1)direc9sum[7] += delta;
			if(r >= center_r+1 && c >= center_c+1)direc9sum[8] += delta;
		}
	
	}			

	delta = 0;
	pTRingInfo.MaxDirecNum = 0;
	for( r=0; r<=8; r++ )
	{
		if(direc9sum[r] > delta)
		{
			delta = direc9sum[r];
			pTRingInfo.MaxDirecNum = r+1;
		}
	}
	
	pTRingInfo.tCoord.x = pTRingInfo.tCoord.y = 0;
	if(pTRingInfo.MaxDirecNum == 1)
	{
		pTRingInfo.tCoord.y = -((direc9sum[0]+direc9sum[2]) - (direc9sum[8]+direc9sum[7]));
		pTRingInfo.tCoord.x = -((direc9sum[0]+direc9sum[3]) - (direc9sum[8]+direc9sum[5]));
	}
	else 
	if(pTRingInfo.MaxDirecNum == 2)
	{
		pTRingInfo.tCoord.y = -((direc9sum[1]+MAX(direc9sum[0],direc9sum[2])) - (direc9sum[7]+MAX(direc9sum[6],direc9sum[8])));
		//pTRingInfo.tCoord.x = direc9sum[2] - direc9sum[0];			
	}
	else if(pTRingInfo.MaxDirecNum == 3)
	{
		pTRingInfo.tCoord.y = -((direc9sum[2]+direc9sum[1]) - (direc9sum[6]+direc9sum[7]));
		pTRingInfo.tCoord.x = (direc9sum[2]+direc9sum[5]) - (direc9sum[6]+direc9sum[3]);			
	}
	else if(pTRingInfo.MaxDirecNum == 4)
	{
		//pTRingInfo.tCoord.y = direc9sum[6] - direc9sum[0];
		pTRingInfo.tCoord.x = -abs((direc9sum[3]+MAX(direc9sum[0],direc9sum[6])) - (direc9sum[5]+MAX(direc9sum[2],direc9sum[8])));		
	}
//	else if(pTRingInfo.MaxDirecNum == 5)
//	{
//		pTRingInfo.tCoord.y = direc9sum[7] - direc9sum[1];
//		pTRingInfo.tCoord.x = direc9sum[5] - direc9sum[3];			
//	}
	else if(pTRingInfo.MaxDirecNum == 6)
	{
		//pTRingInfo.tCoord.y = (direc9sum[7]+MIN(direc9sum[6],direc9sum[8]) - (direc9sum[1]+MAX(direc9sum[0],direc9sum[2])));
		pTRingInfo.tCoord.x = ((direc9sum[5]+MAX(direc9sum[2],direc9sum[8])) - (direc9sum[3]+MAX(direc9sum[0],direc9sum[6])));		
	}
	else if(pTRingInfo.MaxDirecNum == 7)
	{
		pTRingInfo.tCoord.y = ((direc9sum[6]+direc9sum[7]) - (direc9sum[2]+direc9sum[1]));
		pTRingInfo.tCoord.x = -((direc9sum[6]+direc9sum[3]) - (direc9sum[2]+direc9sum[5]));			
	}			
	else if(pTRingInfo.MaxDirecNum == 8)
	{
		pTRingInfo.tCoord.y = ((direc9sum[7]+MAX(direc9sum[6],direc9sum[8])) - (direc9sum[1]+MAX(direc9sum[0],direc9sum[2])));
		//pTRingInfo.tCoord.x = direc9sum[8] - direc9sum[6];			
	}			
	else if(pTRingInfo.MaxDirecNum == 9)
	{
		pTRingInfo.tCoord.y = ((direc9sum[8]+direc9sum[7]) - (direc9sum[0]+direc9sum[1]));
		pTRingInfo.tCoord.x = ((direc9sum[8]+direc9sum[5]) - (direc9sum[0]+direc9sum[3]));			
	}		
}
#endif

#ifdef TILT_ON
#if 1//(USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
uint16_t p_sensingRowStart_Tilt;
int8_t sensingRowStart_Tilt_Offset = 0;
void algorithm_local_baseline_calculate_delta_Tilt(int mode)
//void algorithm_local_RingMS_delta_coordi(int mode)
{
	int r, r1, c , r_pos;
	int delta,delta2,delta_th;
	int start_r, end_r;
	int start_c, end_c;
	int local_rs_ring = sensingRowStart_Tilt;;
	uint16_t read_raw_data,base_raw_data;
	int sensingRowOffset = (sensingRowStart_Tilt - p_sensingRowStart_Tilt);
	int temp_r;
	int delta_r_pos;
	
	memset((void *)(&thisInfo->tDelta_local), 0x00, sizeof(tOrigDeltaInfo_t));
	thisInfo->tDelta_local.tValidRect.cs = COL_MAX - 1; thisInfo->tDelta_local.tValidRect.ce = 0;
	thisInfo->tDelta_local.tValidRect.rs = ROW_MAX - 1; thisInfo->tDelta_local.tValidRect.re = 0;
	
//	memset(&pTRingInfo,0,sizeof(tRingMSInfo_t));

	uint8_t col_search_offset;
	uint8_t row_idx_offset;
	uint8_t row_error_margin;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)	
	col_search_offset=0;
	row_idx_offset = PEN_COORD_ROW_MAX;
	row_error_margin = 1;
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	col_search_offset = 3;
	row_idx_offset = 0;
	row_error_margin = 2;
#else
	if(ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType){col_search_offset=0;row_idx_offset = PEN_COORD_ROW_MAX;row_error_margin = 1;}
	else {col_search_offset = 3;row_idx_offset = 0;row_error_margin = 2;}
#endif
	
	start_r = 0, start_c = MAX(0,thisPenInfo->ucCurrentColumnStart-col_search_offset);
	end_r = PEN_COORD_ROW_MAX-1, end_c = MIN(COL_MAX-1,thisPenInfo->ucCurrentColumnEnd+col_search_offset);

	thisPenInfo->ucCoordiRowStart = local_rs_ring;

	delta_th = thisModeConf->Label.usLocalSeedBase_Ring;
	
	uint8_t ucTmpLocalOvrShift_Ring = ptModuleModeConf->ucLocalOvrShift_Ring;
	

	if(thisPenInfo->bPenContact == NO && thisPenInfo->bPrevPenContact == NO && thisModeConf->PenTilt.cHoverOverShiftRingOffset != 0)
		ucTmpLocalOvrShift_Ring = ptModuleModeConf->ucLocalOvrShift_Ring+thisModeConf->PenTilt.cHoverOverShiftRingOffset;
	
	for( r1=start_r; r1<=end_r; r1++ )
	{
		if(sensingRowOffset >= 0) r = r1;
		else r = PEN_COORD_ROW_MAX - 1 - r1;
		temp_r = r + sensingRowOffset;
		r_pos = (r+local_rs_ring)*COL_MAX;
		delta_r_pos = (r+PAD_)*(COL_MAX+PAD_+PAD_);
		for( c=start_c; c<=end_c; c++ )
		{	
			read_raw_data = HAL_READ_LOCAL_RING_RAW_IMAGE(r+row_idx_offset,c);		

			base_raw_data = thisPenInfo->pTmpModeBaseImg[r_pos+c];//HAL_READ_RING_BASELINE_IMAGE(r+local_rs_ring,c);
			
			delta = (signed)base_raw_data - (signed)read_raw_data;
			
#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
			if(thisModeConf->PenTilt.b2MUX_SUM_RingMode)
			{
				read_raw_data = HAL_READ_LOCAL_RING_RAW_IMAGE(r+PEN_COORD_ROW_MAX,c);
				delta2 = (signed)base_raw_data - (signed)read_raw_data;
				delta+=delta2;
			}
#endif			
			delta>>=ucTmpLocalOvrShift_Ring;//ptModuleModeConf->ucLocalOvrShift_Ring;

#if (HoverDeltaMul_EN == YES)			
			if(thisPenInfo->bPenContact == NO && thisPenInfo->bPrevPenContact == NO && thisModeConf->PenTilt.ucHoverDeltaMul != 0)
				delta = delta*thisModeConf->PenTilt.ucHoverDeltaMul/10;
#endif
			
			if(delta < 0) delta = -delta;

#if (LocalNormalizeEn == YES)
			if(thisModeConf->BaseLine.ucLocalNormalizeMaxOffset != 0)
			{
				int NormalizeOffset = thisModeConf->BaseLine.ucLocalNormalizeMaxOffset * (r+local_rs_ring)/ROW_MAX-1;
				delta = delta * (100 - NormalizeOffset)/100;
			}
#endif
			
			if(thisModeConf->SensingFilter.ucRingDeltaIIR_Coef > 0 && thisInfo->tTiltInfo.sTilt_cnt > 1)
			{
				if(temp_r >= 0 && temp_r < PEN_COORD_ROW_MAX)
				{
					delta2 = HAL_READ_RING_DELTA_IMAGE(temp_r,c);
					delta = (delta*(255-thisModeConf->SensingFilter.ucRingDeltaIIR_Coef) + delta2*thisModeConf->SensingFilter.ucRingDeltaIIR_Coef)/255;
				}
			}
			
			if( delta > delta_th)
			{
				if( thisInfo->tDelta_local.tValidRect.cs > c )
					thisInfo->tDelta_local.tValidRect.cs = c;
				if( thisInfo->tDelta_local.tValidRect.ce < c )
					thisInfo->tDelta_local.tValidRect.ce = c;
				if( thisInfo->tDelta_local.tValidRect.rs > r )
					thisInfo->tDelta_local.tValidRect.rs = r;
				if( thisInfo->tDelta_local.tValidRect.re < r )
					thisInfo->tDelta_local.tValidRect.re = r;

				//thisInfo->tDelta_local.iGroupedCellCnt++;
			}
			
			if( thisInfo->tDelta_local.iMaxStrength < delta )
			{
				thisInfo->tDelta_local.iMaxStrength = delta;
				thisInfo->tDelta_local.tMaxCellPos.r = r;
				thisInfo->tDelta_local.tMaxCellPos.c = c;
			}
			thisPenInfo->pTmpModeDeltaImg[delta_r_pos+c+PAD_] = delta;
//			HAL_WRITE_RING_DELTA_IMAGE(r,c,delta);
		}
	}	

	pTRingInfo.s3x3Val = algorithm_calc_3by3LocalDeltaSum(thisInfo->tDelta_local.tMaxCellPos);
	
	p_sensingRowStart_Tilt = sensingRowStart_Tilt;
	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
	if(thisModeConf->PenTilt.bTiltRowIndexChange)
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	if((thisModeConf->PenTilt.bTiltRowIndexChange && ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType) || ACTIVEPEN_TYPE_LOCAL_WGP==gAlgoRawDataType)
#endif
	{
//		algorithm_baseline_calculate_local_mux_range_Tilt(thisInfo->tDelta_local.tMaxCellPos.r+local_rs_ring,0);
		algorithm_baseline_calculate_local_mux_range(thisInfo->tDelta_local.tMaxCellPos.r+local_rs_ring,thisInfo->tLabel_local_dsp.tValidMaxPos.c,1);
		if(sensingRowStart_Tilt - sensingRowStart < -row_error_margin)sensingRowStart_Tilt = sensingRowStart-row_error_margin;
		else if(sensingRowStart_Tilt - sensingRowStart > row_error_margin)sensingRowStart_Tilt = sensingRowStart+row_error_margin;
		sensingRowStart_Tilt_Offset = sensingRowStart_Tilt - sensingRowStart;
	}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
	if(!thisModeConf->PenTilt.bTiltRowIndexChange){sensingRowStart_Tilt = sensingRowStart;sensingRowStart_Tilt_Offset=0;}
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	if(!thisModeConf->PenTilt.bTiltRowIndexChange && ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType){sensingRowStart_Tilt = sensingRowStart;sensingRowStart_Tilt_Offset=0;}
#endif			

#if (TiltBasedRingDelta == YES || TiltDirecLimitFilter == YES)
  #if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)	
	if(ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType)
	#endif
	{
		uint8_t edge_flag = 0;
		edge_flag = algorithm_coord_IsEdgeArea_Cell(thisInfo->tDelta_local.tMaxCellPos.r+local_rs_ring,thisInfo->tDelta_local.tMaxCellPos.c,0);
		if(edge_flag == 0 && (
	#if (TiltBasedRingDelta == YES)
		thisModeConf->PenTilt.bTiltBasedRingDelta 
	#endif
	#if (TiltDirecLimitFilter == YES)	
		|| thisModeConf->PenTilt.bTiltDirecLimitFilter
	#endif
		))
		{
			start_r = 0; 
			end_r = PEN_COORD_ROW_MAX-1;  
			start_c = MAX(thisInfo->tLabel_local_dsp.tValidMaxPos.c-2,0); 
			end_c = MIN(thisInfo->tLabel_local_dsp.tValidMaxPos.c+2,COL_MAX-1);  	
			int direc9sum[9] = {0,};
			for( r=start_r; r<=end_r; r++ )
			{
				for( c=start_c; c<=end_c; c++ )
				{	
					delta = HAL_READ_RING_DELTA_IMAGE(r,c);
					if(r <= 2 && c <= thisInfo->tLabel_local_dsp.tValidMaxPos.c)direc9sum[0] += delta;
					if(r <= 2 && c >= thisInfo->tLabel_local_dsp.tValidMaxPos.c-1 && c <= thisInfo->tLabel_local_dsp.tValidMaxPos.c+1)direc9sum[1] += delta;
					if(r <= 2 && c >= thisInfo->tLabel_local_dsp.tValidMaxPos.c)direc9sum[2] += delta;
					if(r >= 1 && r <= 3 && c <= thisInfo->tLabel_local_dsp.tValidMaxPos.c)direc9sum[3] += delta;
					if(r >= 1 && r <= 3 && c >= thisInfo->tLabel_local_dsp.tValidMaxPos.c-1 && c <= thisInfo->tLabel_local_dsp.tValidMaxPos.c+1)direc9sum[4] += delta;
					if(r >= 1 && r <= 3 && c >= thisInfo->tLabel_local_dsp.tValidMaxPos.c)direc9sum[5] += delta;
					if(r >= 2 && c <= thisInfo->tLabel_local_dsp.tValidMaxPos.c)direc9sum[6] += delta;
					if(r >= 2 && c >= thisInfo->tLabel_local_dsp.tValidMaxPos.c-1 && c <= thisInfo->tLabel_local_dsp.tValidMaxPos.c+1)direc9sum[7] += delta;
					if(r >= 2 && c >= thisInfo->tLabel_local_dsp.tValidMaxPos.c)direc9sum[8] += delta;
				}
			
			}			

			delta = 0;
			pTRingInfo.MaxDirecNum = 0;
			for( r=0; r<=8; r++ )
			{
				if(direc9sum[r] > delta)
				{
					delta = direc9sum[r];
					pTRingInfo.MaxDirecNum = r+1;
				}
			}

		#if (TiltBasedRingDelta == YES)
			if(thisModeConf->PenTilt.bTiltBasedRingDelta)		
			{					
		//		if(pTRingInfo.MaxDirecNum == 1)
		//		{
		//			pTRingInfo.tCoord.y = -((direc9sum[1]+MIN(direc9sum[0],direc9sum[2])) - (direc9sum[7]+MAX(direc9sum[6],direc9sum[8])));
		//			pTRingInfo.tCoord.x = -((direc9sum[3]+MIN(direc9sum[0],direc9sum[6])) - (direc9sum[5]+MAX(direc9sum[2],direc9sum[8])));
		//		}
		//		else 
					if(pTRingInfo.MaxDirecNum == 2)
				{
					pTRingInfo.tCoord.y = -((direc9sum[1]+MIN(direc9sum[0],direc9sum[2])) - (direc9sum[7]+MAX(direc9sum[6],direc9sum[8])));
					//pTRingInfo.tCoord.x = direc9sum[2] - direc9sum[0];			
				}
		//		else if(pTRingInfo.MaxDirecNum == 3)
		//		{
		//			pTRingInfo.tCoord.y = -((direc9sum[1]+MIN(direc9sum[0],direc9sum[2])) - (direc9sum[7]+MAX(direc9sum[6],direc9sum[8])));
		//			pTRingInfo.tCoord.x = ((direc9sum[5]+MIN(direc9sum[2],direc9sum[8])) - (direc9sum[3]+MAX(direc9sum[0],direc9sum[6])));			
		//		}
				else if(pTRingInfo.MaxDirecNum == 4)
				{
					//pTRingInfo.tCoord.y = direc9sum[6] - direc9sum[0];
					pTRingInfo.tCoord.x = -abs((direc9sum[3]+MIN(direc9sum[0],direc9sum[6])) - (direc9sum[5]+MAX(direc9sum[2],direc9sum[8])));		
				}
				else if(pTRingInfo.MaxDirecNum == 5)
				{
					pTRingInfo.tCoord.y = direc9sum[7] - direc9sum[1];
					pTRingInfo.tCoord.x = direc9sum[5] - direc9sum[3];			
				}
				else if(pTRingInfo.MaxDirecNum == 6)
				{
					//pTRingInfo.tCoord.y = (direc9sum[7]+MIN(direc9sum[6],direc9sum[8]) - (direc9sum[1]+MAX(direc9sum[0],direc9sum[2])));
					pTRingInfo.tCoord.x = ((direc9sum[5]+MIN(direc9sum[2],direc9sum[8])) - (direc9sum[3]+MAX(direc9sum[0],direc9sum[6])));		
				}
		//		else if(MaxDirecNum == 7)
		//		{
		//			pTRingInfo.tCoord.y = ((direc9sum[7]+MIN(direc9sum[6],direc9sum[8])) - (direc9sum[1]+MAX(direc9sum[0],direc9sum[2])));
		//			pTRingInfo.tCoord.x = -((direc9sum[3]+MIN(direc9sum[0],direc9sum[6])) - (direc9sum[5]+MAX(direc9sum[2],direc9sum[8])));			
		//		}			
				else if(pTRingInfo.MaxDirecNum == 8)
				{
					pTRingInfo.tCoord.y = ((direc9sum[7]+MIN(direc9sum[6],direc9sum[8])) - (direc9sum[1]+MAX(direc9sum[0],direc9sum[2])));
					//pTRingInfo.tCoord.x = direc9sum[8] - direc9sum[6];			
				}			
		//		else if(MaxDirecNum == 9)
		//		{
		//			pTRingInfo.tCoord.y = ((direc9sum[7]+MIN(direc9sum[6],direc9sum[8])) - (direc9sum[1]+MAX(direc9sum[0],direc9sum[2])));
		//			pTRingInfo.tCoord.x = ((direc9sum[5]+MIN(direc9sum[2],direc9sum[8])) - (direc9sum[3]+MAX(direc9sum[0],direc9sum[6])));			
		//		}	
			}
		#endif
		}
	}
  #endif
#endif

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)	
	if(thisModeConf->PenTilt.ucRingDirecPosCoef > 0 
	#if (TiltDirecLimitFilter == YES)
	|| thisModeConf->PenTilt.bTiltDirecLimitFilter > 0 
	#endif
	|| thisModeConf->PenTilt.ucTipDirecShiftBasedRingDelta > 0)			
		algorithm_local_Ring_direc_delta_base_pos();
			
	if(thisInfo->tCoord_local_dsp.PenContactCnt > 1 && thisModeConf->PenTilt.ucRingTipDeltaSumCoef > 0 && pTRingInfo.s3x3Val > thisModeConf->PenTilt.ucRingTipDeltaSumTH)
	{
		int shift_r = 0; 
		int shift_c = 0;

		shift_r = thisInfo->tDelta_local.tMaxCellPos.r - thisInfo->tLabel_local_dsp.tValidMaxPos.r; 
		shift_c = thisInfo->tDelta_local.tMaxCellPos.c - thisInfo->tLabel_local_dsp.tValidMaxPos.c;
		
		int Coef = thisModeConf->PenTilt.ucRingTipDeltaSumCoef;

		for(r = MAX(0,thisInfo->tDelta_local.tMaxCellPos.r-2); r <= MIN(PEN_COORD_ROW_MAX-1,thisInfo->tDelta_local.tMaxCellPos.r+2); r++)
		{
			for(c = MAX(0,thisInfo->tDelta_local.tMaxCellPos.c-2); c <= MIN(COL_MAX-1,thisInfo->tDelta_local.tMaxCellPos.c+2); c++)				
			{
				if(r-shift_r >= 0 && r-shift_r <= PEN_COORD_ROW_MAX-1 && c-shift_c >= 0 && c-shift_c <= COL_MAX-1)
				{
					int Tip_D = HAL_READ_LOCAL_DELTA_IMAGE(r-shift_r,c-shift_c);
					int Ring_D = HAL_READ_RING_DELTA_IMAGE(r,c);
					if(r != thisInfo->tDelta_local.tMaxCellPos.r || thisInfo->tDelta_local.tMaxCellPos.c != c)Coef>>=1;
					Ring_D = Tip_D+Ring_D/Coef;
					HAL_WRITE_RING_DELTA_IMAGE(r,c,Ring_D);
				}
			}
		}
	}
#endif
}
#endif

#if (TiltDeltaLimit_EN == YES)
int max3x3, prev_max3x3;
#endif
void algorithm_Tilt_PreFilter(void)
{
#if (TiltDeltaLimit_EN == YES)
	static tXY_t prev_dist;
	static int prev_max;
#endif
	
#if (TiltDirecLimitFilter == YES)	
	if(thisModeConf->PenTilt.bTiltDirecLimitFilter == 1)
	{	
		if(pTRingInfo.MaxDirecNum == 1)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > 7500)thisInfo->tTiltInfo.HID_TILT_X=7500;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 4000)thisInfo->tTiltInfo.HID_TILT_X=4000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y > 7500)thisInfo->tTiltInfo.HID_TILT_Y=7500;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 4000)thisInfo->tTiltInfo.HID_TILT_Y=4000;
		}
		else if(pTRingInfo.MaxDirecNum == 2)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X=10000;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X=8000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y < 1000)thisInfo->tTiltInfo.HID_TILT_Y=1000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y > 8000)thisInfo->tTiltInfo.HID_TILT_Y=8000;
		}		
		else if(pTRingInfo.MaxDirecNum == 3)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X < 10500)thisInfo->tTiltInfo.HID_TILT_X=10500;
			else if(thisInfo->tTiltInfo.HID_TILT_X > 14000)thisInfo->tTiltInfo.HID_TILT_X=14000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y > 7500)thisInfo->tTiltInfo.HID_TILT_Y=7500;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 4000)thisInfo->tTiltInfo.HID_TILT_Y=4000;
		}	
		else if(pTRingInfo.MaxDirecNum == 4)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X < 1000)thisInfo->tTiltInfo.HID_TILT_X=1000;
			else if(thisInfo->tTiltInfo.HID_TILT_X > 8000)thisInfo->tTiltInfo.HID_TILT_X=8000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y=10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y=8000;
		}
		else if(pTRingInfo.MaxDirecNum == 5)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X=10000;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X=8000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y=10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y=8000;
		}
		else if(pTRingInfo.MaxDirecNum == 6)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X < 10000)thisInfo->tTiltInfo.HID_TILT_X=10500;
			else if(thisInfo->tTiltInfo.HID_TILT_X > 16000)thisInfo->tTiltInfo.HID_TILT_X=16000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y=10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y=8000;
		}
		else if(pTRingInfo.MaxDirecNum == 7)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > 7500)thisInfo->tTiltInfo.HID_TILT_X=7500;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 4000)thisInfo->tTiltInfo.HID_TILT_X=4000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y < 10500)thisInfo->tTiltInfo.HID_TILT_Y=10500;
			else if(thisInfo->tTiltInfo.HID_TILT_Y > 14000)thisInfo->tTiltInfo.HID_TILT_Y=14000;
		}
		else if(pTRingInfo.MaxDirecNum == 8)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X=10000;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X=8000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y < 10000)thisInfo->tTiltInfo.HID_TILT_Y=10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y > 16000)thisInfo->tTiltInfo.HID_TILT_Y=16000;
		}	
		else if(pTRingInfo.MaxDirecNum == 9)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X < 10500)thisInfo->tTiltInfo.HID_TILT_X=10500;
			else if(thisInfo->tTiltInfo.HID_TILT_X > 14000)thisInfo->tTiltInfo.HID_TILT_X=14000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y < 10500)thisInfo->tTiltInfo.HID_TILT_Y=10500;
			else if(thisInfo->tTiltInfo.HID_TILT_Y > 14000)thisInfo->tTiltInfo.HID_TILT_Y=14000;
		}
	}
#endif
#if (TiltDeltaLimit_EN == YES)
//#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz || CUSTOMER == MODEL_DEF_QHD_92407)
//#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT)
//	if(pTRingInfo.s3x3Val <= 60)
//#elif (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
//	if(pTRingInfo.s3x3Val <= 150)
//#else
//	//if(pTRingInfo.sValidMaxVal <= 30)
//	if(thisInfo->tDelta_local.iMaxStrength <= 30)
//#endif
//	{
//		if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
//		else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
//		
//		if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
//		else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
//	}	
//#endif
	
//	if(thisModeConf->PenTilt.ucTiltDeltaLimitFilter == 1)
//	{
////		if(pTRingInfo.sValidMaxVal <= 30)
//		if(thisInfo->tDelta_local.iMaxStrength <= 30)
//		{
//			if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
//			else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
//			
//			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
//			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
//		}
//	
//		if(thisInfo->tDelta_local.iMaxStrength > 30 && thisInfo->tDelta_local.iMaxStrength <= 50)
//		{
//			if(thisInfo->tTiltInfo.HID_TILT_X > 12000)thisInfo->tTiltInfo.HID_TILT_X = 12000;
//			else if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
//			else if(thisInfo->tTiltInfo.HID_TILT_X < 6000)thisInfo->tTiltInfo.HID_TILT_X = 6000;
//			else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
//			
//			if(thisInfo->tTiltInfo.HID_TILT_Y > 12000)thisInfo->tTiltInfo.HID_TILT_Y = 12000;
//			else if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
//			else if(thisInfo->tTiltInfo.HID_TILT_Y < 6000)thisInfo->tTiltInfo.HID_TILT_Y = 6000;
//			else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
//		}
//		else if(thisInfo->tDelta_local.iMaxStrength > 50 && thisInfo->tDelta_local.iMaxStrength <= 120)
//		{
//			if(thisInfo->tTiltInfo.HID_TILT_X > 14000)thisInfo->tTiltInfo.HID_TILT_X = 14000;
//			else if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 12000)thisInfo->tTiltInfo.HID_TILT_X = 12000;
//			else if(thisInfo->tTiltInfo.HID_TILT_X < 4000)thisInfo->tTiltInfo.HID_TILT_X = 4000;
//			else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 6000)thisInfo->tTiltInfo.HID_TILT_X = 6000;
//			
//			if(thisInfo->tTiltInfo.HID_TILT_Y > 14000)thisInfo->tTiltInfo.HID_TILT_Y = 14000;
//			else if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 12000)thisInfo->tTiltInfo.HID_TILT_Y = 12000;
//			else if(thisInfo->tTiltInfo.HID_TILT_Y < 4000)thisInfo->tTiltInfo.HID_TILT_Y = 4000;
//			else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 6000)thisInfo->tTiltInfo.HID_TILT_Y = 6000;
//		}
//		else if(thisInfo->tDelta_local.iMaxStrength > 200)
//		{
//			if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 15500)thisInfo->tTiltInfo.HID_TILT_X = 15500;
//			else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 2500)thisInfo->tTiltInfo.HID_TILT_X = 2500;
//			
//			if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 15500)thisInfo->tTiltInfo.HID_TILT_Y = 15500;
//			else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 2500)thisInfo->tTiltInfo.HID_TILT_Y = 2500;
//		}
//	}
//	else 
	if(thisModeConf->PenTilt.ucTiltDeltaLimitFilter == 2)
	{
		int dist_direction = 0, dist_diff = 0, min_dist = 0;
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
		int max_val = thisInfo->tDelta_local.iMaxStrength;//pTRingInfo.sValidMaxVal;
	#else
		int max_val = pTRingInfo.s3x3Val;
	#endif
		max3x3 = pTRingInfo.s3x3Val;
		
		tXY_t dist;
		
		dist.x = abs(thisInfo->tCoord_local_dsp.tOrgPos.tXY.x-thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x);
		dist.y = abs(thisInfo->tCoord_local_dsp.tOrgPos.tXY.y-thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y);

	#ifdef FirstTiltWaitReportMS
		if(thisInfo->tTiltInfo.sTilt_cnt > 2)
	#else	
		if(thisInfo->tTiltInfo.sTilt_cnt > 1)
	#endif
		{
			max_val = (8*prev_max + 2*max_val)/10;
			dist.x = (prev_dist.x + dist.x) >> 1;
			dist.y = (prev_dist.y + dist.y) >> 1;
			max3x3 = (8*prev_max3x3 + 2*max3x3)/10;
		}

	#if (UseLastContact3x3 == YES)		
		if(thisPenInfo->bUseUseLastContact3x3 == 1 && thisModeConf->PenTilt.usUseLastContact3x3Th > 0 /*&& thisInfo->tTiltInfo.sTilt_cnt == 2 */)
		{
			thisPenInfo->bUseUseLastContact3x3 = 0;
			if(pTRingInfo.sLastContact3x3Val != 0)
			{
				max3x3 = (8*pTRingInfo.sLastContact3x3Val + 2*max3x3)/10;
			}
		}
	#endif
		
		dist_diff = abs(dist.x - dist.y);
		
		if(dist.x > dist.y)
		{
			dist_direction = 1;
			min_dist = dist.y;
		}
		else if(dist.x < dist.y)
		{
			dist_direction = 2;
			min_dist = dist.x;
		}

	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
//		if(0)
//		{
//			if(max_val <= 50 && dist_diff < 100 && min_dist < 100)
//			{
//				if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
//				else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
//				
//				if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
//				else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
//			}
//			else if(max_val > 50 && max_val <= 90 && dist_diff > 200 && dist_diff < 400)
//			{
//				if(dist_direction == 1)
//				{
//					if(thisInfo->tTiltInfo.HID_TILT_X > 14500)thisInfo->tTiltInfo.HID_TILT_X = 14500;
//					else if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 12500)thisInfo->tTiltInfo.HID_TILT_X = 12500;
//					else if(thisInfo->tTiltInfo.HID_TILT_X < 3500)thisInfo->tTiltInfo.HID_TILT_X = 3500;
//					else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 5500)thisInfo->tTiltInfo.HID_TILT_X = 5500;
//					if(min_dist < 50)
//					{
//						if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
//						else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
//					}
//				}
//				else if(dist_direction == 2)
//				{
//					if(thisInfo->tTiltInfo.HID_TILT_Y > 14500)thisInfo->tTiltInfo.HID_TILT_Y = 14500;
//					else if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 12500)thisInfo->tTiltInfo.HID_TILT_Y = 12500;
//					else if(thisInfo->tTiltInfo.HID_TILT_Y < 3500)thisInfo->tTiltInfo.HID_TILT_Y = 3500;
//					else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 5500)thisInfo->tTiltInfo.HID_TILT_Y = 5500;
//					if(min_dist < 50)
//					{
//						if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
//						else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
//					}
//				}
//			}
//			else if(max_val > 110 && max_val < 150)
//			{			
//				if(dist_direction == 1)
//				{
//					if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 14500)thisInfo->tTiltInfo.HID_TILT_X = 14500;
//					else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 3500)thisInfo->tTiltInfo.HID_TILT_X = 3500;
//				}
//				else if(dist_direction == 2)
//				{
//					if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 14500)thisInfo->tTiltInfo.HID_TILT_Y = 14500;
//					else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 3500)thisInfo->tTiltInfo.HID_TILT_Y = 3500;
//				}
//			}
//			else if(max_val >= 150)
//			{
//				if(dist_direction == 1)
//				{
//					if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 15500)thisInfo->tTiltInfo.HID_TILT_X = 15500;
//					else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 2500)thisInfo->tTiltInfo.HID_TILT_X = 2500;
//				}
//				else if(dist_direction == 2)
//				{
//					if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 15500)thisInfo->tTiltInfo.HID_TILT_Y = 15500;
//					else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 2500)thisInfo->tTiltInfo.HID_TILT_Y = 2500;
//				}
//			}
//		}
//		else
		{
			if(max3x3 <= 300 && dist_diff < 100 && min_dist < 100)
			{
				if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
				else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
				
				if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
				else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
			}
			else if(max3x3 > 300 && max3x3 <= 400 && dist_diff > 200 && dist_diff < 400)
			{
				if(dist_direction == 1)
				{
					if(thisInfo->tTiltInfo.HID_TILT_X > 14500)thisInfo->tTiltInfo.HID_TILT_X = 14500;
					else if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 12500)thisInfo->tTiltInfo.HID_TILT_X = 12500;
					else if(thisInfo->tTiltInfo.HID_TILT_X < 3500)thisInfo->tTiltInfo.HID_TILT_X = 3500;
					else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 5500)thisInfo->tTiltInfo.HID_TILT_X = 5500;
					if(min_dist < 50)
					{
						if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
						else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
					}
				}
				else if(dist_direction == 2)
				{
					if(thisInfo->tTiltInfo.HID_TILT_Y > 14500)thisInfo->tTiltInfo.HID_TILT_Y = 14500;
					else if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 12500)thisInfo->tTiltInfo.HID_TILT_Y = 12500;
					else if(thisInfo->tTiltInfo.HID_TILT_Y < 3500)thisInfo->tTiltInfo.HID_TILT_Y = 3500;
					else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 5500)thisInfo->tTiltInfo.HID_TILT_Y = 5500;
					if(min_dist < 50)
					{
						if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
						else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
					}
				}
			}
			else if(max3x3 > 400 && max3x3 <= 550)
			{			
				if(dist_direction == 1)
				{
					if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 13500)thisInfo->tTiltInfo.HID_TILT_X = 13500;
					else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 4500)thisInfo->tTiltInfo.HID_TILT_X = 4500;
				}
				else if(dist_direction == 2)
				{
					if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 13500)thisInfo->tTiltInfo.HID_TILT_Y = 13500;
					else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 4500)thisInfo->tTiltInfo.HID_TILT_Y = 4500;
				}
			}
			else if(max3x3 >= 550 && max3x3 < 700)
			{			
				if(dist_direction == 1)
				{
					if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 14500)thisInfo->tTiltInfo.HID_TILT_X = 14500;
					else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 3500)thisInfo->tTiltInfo.HID_TILT_X = 3500;
				}
				else if(dist_direction == 2)
				{
					if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 14500)thisInfo->tTiltInfo.HID_TILT_Y = 14500;
					else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 3500)thisInfo->tTiltInfo.HID_TILT_Y = 3500;
				}
			}
			else if(max3x3 >= 700)
			{
				if(dist_direction == 1)
				{
					if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 15500)thisInfo->tTiltInfo.HID_TILT_X = 15500;
					else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 2500)thisInfo->tTiltInfo.HID_TILT_X = 2500;
				}
				else if(dist_direction == 2)
				{
					if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 15500)thisInfo->tTiltInfo.HID_TILT_Y = 15500;
					else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 2500)thisInfo->tTiltInfo.HID_TILT_Y = 2500;
				}
			}
		}
	#else
		if(max_val <= thisModeConf->PenTilt.usTiltDeltaLimit_10_TH && dist_diff < 100 && min_dist < 100 && thisModeConf->PenTilt.usTiltDeltaLimit_10_TH)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
		}
		
		#if (TiltDeltaLimit_ADD == YES)
		if(max_val > thisModeConf->PenTilt.usTiltDeltaLimit_40_TH && thisModeConf->PenTilt.usTiltDeltaLimit_40_TH)
		{
			if(dist_direction == 1)
			{
				if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 13000)thisInfo->tTiltInfo.HID_TILT_X = 13000+100;
				else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 5000)thisInfo->tTiltInfo.HID_TILT_X = 5000-100;
			}
			else if(dist_direction == 2)
			{
				if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 13000)thisInfo->tTiltInfo.HID_TILT_Y = 13000+100;
				else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 5000)thisInfo->tTiltInfo.HID_TILT_Y = 5000-100;
			}
		}
		
		if(max_val > thisModeConf->PenTilt.usTiltDeltaLimit_50_TH && thisModeConf->PenTilt.usTiltDeltaLimit_50_TH)
		{			
			if(dist_direction == 1)
			{
				if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 14000)thisInfo->tTiltInfo.HID_TILT_X = 14000+100; // +100 offset add : 5500 down case because of smoothing
				else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 4000)thisInfo->tTiltInfo.HID_TILT_X = 4000-100;
			}
			else if(dist_direction == 2)
			{
				if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 14000)thisInfo->tTiltInfo.HID_TILT_Y = 14000+100;
				else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 4000)thisInfo->tTiltInfo.HID_TILT_Y = 4000-100;
			}
			
			if(max_val <= thisModeConf->PenTilt.usTiltDeltaLimit_55_TH && thisModeConf->PenTilt.usTiltDeltaLimit_55_TH)
			{
				if(dist_direction == 1)
				{
					if(thisInfo->tTiltInfo.HID_TILT_X >= 14500)thisInfo->tTiltInfo.HID_TILT_X = 14500-100; // +100 offset add : 5500 down case because of smoothing
					else if(thisInfo->tTiltInfo.HID_TILT_X <= 3500)thisInfo->tTiltInfo.HID_TILT_X = 3500+100;
				}
				else if(dist_direction == 2)
				{
					if(thisInfo->tTiltInfo.HID_TILT_Y >= 14500)thisInfo->tTiltInfo.HID_TILT_Y = 14500-100;
					else if(thisInfo->tTiltInfo.HID_TILT_Y <= 3500)thisInfo->tTiltInfo.HID_TILT_Y = 3500+100;
				}				
			}
		}
		#endif
		
		if(max_val > thisModeConf->PenTilt.usTiltDeltaLimit_55_TH && thisModeConf->PenTilt.usTiltDeltaLimit_55_TH)
		{
			if(dist_direction == 1)
			{
				if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 14500)thisInfo->tTiltInfo.HID_TILT_X = 14500+100; // +100 offset add : 5500 down case because of smoothing
				else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 3500)thisInfo->tTiltInfo.HID_TILT_X = 3500-100;
			}
			else if(dist_direction == 2)
			{
				if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 14500)thisInfo->tTiltInfo.HID_TILT_Y = 14500+100;
				else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 3500)thisInfo->tTiltInfo.HID_TILT_Y = 3500-100;
			}
			
			if(max_val <= thisModeConf->PenTilt.usTiltDeltaLimit_60_TH && thisModeConf->PenTilt.usTiltDeltaLimit_60_TH)
			{
				if(dist_direction == 1)
				{
					if(thisInfo->tTiltInfo.HID_TILT_X >= 15000)thisInfo->tTiltInfo.HID_TILT_X = 15000-100; // +100 offset add : 5500 down case because of smoothing
					else if(thisInfo->tTiltInfo.HID_TILT_X <= 3000)thisInfo->tTiltInfo.HID_TILT_X = 3000+100;
				}
				else if(dist_direction == 2)
				{
					if(thisInfo->tTiltInfo.HID_TILT_Y >= 15000)thisInfo->tTiltInfo.HID_TILT_Y = 15000-100;
					else if(thisInfo->tTiltInfo.HID_TILT_Y <= 3000)thisInfo->tTiltInfo.HID_TILT_Y = 3000+100;
				}				
			}
		}
					
		if(max_val > thisModeConf->PenTilt.usTiltDeltaLimit_60_TH && thisModeConf->PenTilt.usTiltDeltaLimit_60_TH)
		{
			if(dist_direction == 1)
			{
				if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 15000)thisInfo->tTiltInfo.HID_TILT_X = 15000+100;
				else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 3000)thisInfo->tTiltInfo.HID_TILT_X = 3000-100;
			}
			else if(dist_direction == 2)
			{
				if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 15000)thisInfo->tTiltInfo.HID_TILT_Y = 15000+100;
				else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 3000)thisInfo->tTiltInfo.HID_TILT_Y = 3000-100;
			}
			
			if(max_val <= thisModeConf->PenTilt.usTiltDeltaLimit_65_TH && thisModeConf->PenTilt.usTiltDeltaLimit_65_TH)
			{
				if(dist_direction == 1)
				{
					if(thisInfo->tTiltInfo.HID_TILT_X >= 15500)thisInfo->tTiltInfo.HID_TILT_X = 15500-100; // +100 offset add : 5500 down case because of smoothing
					else if(thisInfo->tTiltInfo.HID_TILT_X <= 2500)thisInfo->tTiltInfo.HID_TILT_X = 2500+100;
				}
				else if(dist_direction == 2)
				{
					if(thisInfo->tTiltInfo.HID_TILT_Y >= 15500)thisInfo->tTiltInfo.HID_TILT_Y = 15500-100;
					else if(thisInfo->tTiltInfo.HID_TILT_Y <= 2500)thisInfo->tTiltInfo.HID_TILT_Y = 2500+100;
				}				
			}
		}
		
		if(max_val >= thisModeConf->PenTilt.usTiltDeltaLimit_65_TH && thisModeConf->PenTilt.usTiltDeltaLimit_65_TH)
		{
			if(dist_direction == 1)
			{
				if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 15500)thisInfo->tTiltInfo.HID_TILT_X = 15500+100;
				else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 2500)thisInfo->tTiltInfo.HID_TILT_X = 2500-100;
			}
			else if(dist_direction == 2)
			{
				if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 15500)thisInfo->tTiltInfo.HID_TILT_Y = 15500+100;
				else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 2500)thisInfo->tTiltInfo.HID_TILT_Y = 2500-100;
			}
		}
	#endif		
		prev_dist.x = dist.x; prev_dist.y = dist.y;
		prev_max = max_val;
		prev_max3x3 = max3x3;
	}
//	else if(thisModeConf->PenTilt.ucTiltDeltaLimitFilter > 2)
//	{
//		if(pTRingInfo.s3x3Val <= thisModeConf->PenTilt.ucTiltDeltaLimitFilter)
//		{
//			if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
//			else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
//			
//			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
//			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
//		}
//	}
#endif
	
#if (TiltMedianFilter == YES)	
	if(thisModeConf->PenTilt.bTiltMedianFilter == 1)
	{
		int i,j;	
		if(thisInfo->tTiltInfo.sTilt_cnt > 10)
		{
			int SortBuf[7] = {0,};
			int TempBuf;
			
			SortBuf[0] = thisInfo->tTiltInfo.HID_TILT_X;
			for( i = 1; i < 7 ; i++)SortBuf[i] = thisInfo->tTiltInfo.Median_PastTilt[i-1].x;
			for( i=0; i<=5; i++ )
			{
				for( j=(i+1); j<=6; j++ )
				{
					if( SortBuf[i] > SortBuf[j] )
					{
						TempBuf = SortBuf[i];
						SortBuf[i] = SortBuf[j];
						SortBuf[j] = TempBuf;
					}
				}
			}
			thisInfo->tTiltInfo.Median_PastTilt[0].x = thisInfo->tTiltInfo.HID_TILT_X;
			thisInfo->tTiltInfo.HID_TILT_X = SortBuf[3];
			
			SortBuf[0] = thisInfo->tTiltInfo.HID_TILT_Y;
			for( i = 1; i < 7 ; i++)SortBuf[i] = thisInfo->tTiltInfo.Median_PastTilt[i-1].y;
			for( i=0; i<=5; i++ )
			{
				for( j=(i+1); j<=6; j++ )
				{
					if( SortBuf[i] > SortBuf[j] )
					{
						TempBuf = SortBuf[i];
						SortBuf[i] = SortBuf[j];
						SortBuf[j] = TempBuf;
					}
				}
			}
			thisInfo->tTiltInfo.Median_PastTilt[0].y = thisInfo->tTiltInfo.HID_TILT_Y;
			thisInfo->tTiltInfo.HID_TILT_Y = SortBuf[3];		
		}
		
		if(thisInfo->tTiltInfo.sTilt_cnt > 1)
		{
			for( i = 1; i < 6 ; i++)
			{
				thisInfo->tTiltInfo.Median_PastTilt[i].x = thisInfo->tTiltInfo.Median_PastTilt[i-1].x;
				thisInfo->tTiltInfo.Median_PastTilt[i].y = thisInfo->tTiltInfo.Median_PastTilt[i-1].y;
			}
		}
		
		if(thisInfo->tTiltInfo.sTilt_cnt <= 10)
		{
			thisInfo->tTiltInfo.Median_PastTilt[0].x = thisInfo->tTiltInfo.HID_TILT_X;	
			thisInfo->tTiltInfo.Median_PastTilt[0].y = thisInfo->tTiltInfo.HID_TILT_Y;
		}
	}
#endif

#if (TiltChangeLimitFilter == YES)	
	if(thisModeConf->PenTilt.usTiltChangeLimitFilter > 0 && thisInfo->tTiltInfo.sTilt_cnt > 2)
	{
		if(abs(thisInfo->tTiltInfo.HID_TILT_X - thisInfo->tTiltInfo.Smooth_PastTilt.x) > thisModeConf->PenTilt.usTiltChangeLimitFilter)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > thisInfo->tTiltInfo.Smooth_PastTilt.x)
				thisInfo->tTiltInfo.HID_TILT_X = thisInfo->tTiltInfo.Smooth_PastTilt.x + thisModeConf->PenTilt.usTiltChangeLimitFilter;
			else
				thisInfo->tTiltInfo.HID_TILT_X = thisInfo->tTiltInfo.Smooth_PastTilt.x - thisModeConf->PenTilt.usTiltChangeLimitFilter;
		}
		
		if(abs(thisInfo->tTiltInfo.HID_TILT_Y - thisInfo->tTiltInfo.Smooth_PastTilt.y) > thisModeConf->PenTilt.usTiltChangeLimitFilter)
		{
			if(thisInfo->tTiltInfo.HID_TILT_Y > thisInfo->tTiltInfo.Smooth_PastTilt.y)
				thisInfo->tTiltInfo.HID_TILT_Y = thisInfo->tTiltInfo.Smooth_PastTilt.y + thisModeConf->PenTilt.usTiltChangeLimitFilter;
			else
				thisInfo->tTiltInfo.HID_TILT_Y = thisInfo->tTiltInfo.Smooth_PastTilt.y - thisModeConf->PenTilt.usTiltChangeLimitFilter;
		}
	}
#endif
}
#endif

#ifdef TiltAccuracyTest
int tilt_offset = 500, tilt_offset2 = 200;
int y_dist_th = 64;
int release_cnt = 0, release_cnt2 = 0, release_cnt_th = 100;
void algorithm_Tilt_PostFilter(void)
{
	if(thisInfo->tTiltInfo.HID_TILT_X > 10000 && thisInfo->tTiltInfo.HID_TILT_X <= (10000 + tilt_offset))
	{
		thisInfo->tTiltInfo.HID_TILT_X = 10000;
	}
	else if(thisInfo->tTiltInfo.HID_TILT_X >= (8000 - tilt_offset) && thisInfo->tTiltInfo.HID_TILT_X < 8000)
	{
		thisInfo->tTiltInfo.HID_TILT_X = 8000;
	}
	
	if(thisInfo->tTiltInfo.HID_TILT_Y > 10000 && thisInfo->tTiltInfo.HID_TILT_Y <= (10000 + tilt_offset))
	{
		thisInfo->tTiltInfo.HID_TILT_Y = 10000;
	}
	else if(thisInfo->tTiltInfo.HID_TILT_Y >= (8000 - tilt_offset) && thisInfo->tTiltInfo.HID_TILT_Y < 8000)
	{
		thisInfo->tTiltInfo.HID_TILT_Y = 8000;
	}
	
	if(thisInfo->tTiltInfo.HID_TILT_X > 14500 && thisInfo->tTiltInfo.HID_TILT_X <= (14500 + tilt_offset2))
	{
		thisInfo->tTiltInfo.HID_TILT_X = 14500;
	}
	else if(thisInfo->tTiltInfo.HID_TILT_X >= (12500 - tilt_offset2) && thisInfo->tTiltInfo.HID_TILT_X < 12500)
	{
		thisInfo->tTiltInfo.HID_TILT_X = 12500;
	}
	else if(thisInfo->tTiltInfo.HID_TILT_X > 5500 && thisInfo->tTiltInfo.HID_TILT_X <= (5500 + tilt_offset2))
	{
		thisInfo->tTiltInfo.HID_TILT_X = 5500;
	}
	else if(thisInfo->tTiltInfo.HID_TILT_X >= (3500 - tilt_offset2) && thisInfo->tTiltInfo.HID_TILT_X < 3500)
	{
		thisInfo->tTiltInfo.HID_TILT_X = 3500;
	}
	
	if(thisInfo->tTiltInfo.HID_TILT_Y > 14500 && thisInfo->tTiltInfo.HID_TILT_Y <= (14500 + tilt_offset2))
	{
		thisInfo->tTiltInfo.HID_TILT_Y = 14500;
	}
	else if(thisInfo->tTiltInfo.HID_TILT_Y >= (12500 - tilt_offset2) && thisInfo->tTiltInfo.HID_TILT_Y < 12500)
	{
		thisInfo->tTiltInfo.HID_TILT_Y = 12500;
	}
	if(thisInfo->tTiltInfo.HID_TILT_Y > 5500 && thisInfo->tTiltInfo.HID_TILT_Y <= (5500 + tilt_offset2))
	{
		thisInfo->tTiltInfo.HID_TILT_Y = 5500;
	}
	else if(thisInfo->tTiltInfo.HID_TILT_Y >= (3500 - tilt_offset2) && thisInfo->tTiltInfo.HID_TILT_Y < 3500)
	{
		thisInfo->tTiltInfo.HID_TILT_Y = 3500;
	}
	
	int y_dist = 0;
	if(thisInfo->tCoord_local_dsp.tPastPos[0].vusS > 0 && thisInfo->tCoord_local_dsp.tPastPos[1].vusS > 0)
		y_dist = abs(thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y - thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.y);
	

	if( ((thisInfo->tTiltInfo.HID_TILT_X > 3500 && thisInfo->tTiltInfo.HID_TILT_X < 5500) || (thisInfo->tTiltInfo.HID_TILT_X > 12500 && thisInfo->tTiltInfo.HID_TILT_X < 14500))
		&& (abs(thisInfo->tTiltInfo.HID_TILT_X - 9000) - abs(thisInfo->tTiltInfo.HID_TILT_Y - 9000) > 1000) )
	{
		if(y_dist >= y_dist_th)
		{
			release_cnt = release_cnt_th;
			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
		}
		else if(release_cnt-- > 0)
		{
			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
		}
	}
	else release_cnt = 0;
	
	if( ((thisInfo->tTiltInfo.HID_TILT_X > 8000 && thisInfo->tTiltInfo.HID_TILT_X < 10000))	&& (abs(thisInfo->tTiltInfo.HID_TILT_Y - 9000) < 2500) )
	{
		if(y_dist >= y_dist_th)
		{
			release_cnt2 = release_cnt_th;
			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
		}
		else if(release_cnt2-- > 0)
		{
			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
		}
	}
	else release_cnt2 = 0;
}
#endif

#if (HighDeltaTiltSmoothCoefChange == YES)
tXY_t PastTilt;
int tilt_count_x = 0, tilt_count_y = 0;
int tilt_direction_x = 0, tilt_direction_y = 0;
int tilt_frame_th = 50;
void algorithm_Tilt_RangeTestCheck(void)
{
	int diff;
	if(thisInfo->tTiltInfo.sTilt_cnt > 3)
	{
		diff = thisInfo->tTiltInfo.HID_TILT_X - PastTilt.x;
		if(tilt_direction_x > 0)
		{
			if(tilt_direction_x == 1)
			{
				if(diff > 0)
					tilt_count_x++;
				else if(diff < 0)
					tilt_count_x = 0;
			}
			else if(tilt_direction_x == 2)
			{
				if(diff < 0)
					tilt_count_x++;
				else if(diff > 0)
					tilt_count_x = 0;
			}
		}
		else
		{
			if(diff > 0)
			{
				tilt_direction_x = 1;
				tilt_count_x++;
			}
			else if(diff < 0)
			{
				tilt_direction_x = 2;
				tilt_count_x++;
			}
		}
		diff = thisInfo->tTiltInfo.HID_TILT_Y - PastTilt.y;
		if(tilt_direction_y > 0)
		{
			if(tilt_direction_y == 1)
			{
				if(diff > 0)
					tilt_count_y++;
				else if(diff < 0)
					tilt_count_y = 0;
			}
			else if(tilt_direction_y == 2)
			{
				if(diff < 0)
					tilt_count_y++;
				else if(diff > 0)
					tilt_count_y = 0;
			}
		}
		else
		{
			if(diff > 0)
			{
				tilt_direction_y = 1;
				tilt_count_x++;
			}
			else if(diff < 0)
			{
				tilt_direction_y = 2;
				tilt_count_y++;
			}
		}
	}
	else
	{
		tilt_count_x = 0; tilt_count_y = 0;
		tilt_direction_x = 0; tilt_direction_y = 0;
	}
	
	if((pTRingInfo.s3x3Val > thisModeConf->PenTilt.ucHighDelta_TiltSmooth_change_Th*10) &&(tilt_count_x > tilt_frame_th || tilt_count_y > tilt_frame_th))
	{
		if((thisPenInfo->bPenContact || thisPenInfo->bPrevPenContact))
		{
			thisInfo->tTiltInfo.SmoothingCoefChange = 1;
		}
	}
	
	PastTilt.x = thisInfo->tTiltInfo.HID_TILT_X;
	PastTilt.y = thisInfo->tTiltInfo.HID_TILT_Y;
}
#endif

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
void algorithm_Cal_MS_phase(int start_r,int end_r,int start_c,int end_c,int mode,int local_rs)
{
	int i, r, c,read_raw_data,delta;
#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN) 
	int min_delta_th = 0;
	
	if(mode == LOCAL_MODE)
		min_delta_th = thisModeConf->BaseLine.usMS_ContactTh_LocalMode;
	else
		min_delta_th = thisModeConf->BaseLine.usMS_ContactTh_HoverMode;
#endif
	
	uint8_t raw_idx = 0;
	uint8_t base_idx = 0;	
	uint8_t shift_idx = 0;
	uint8_t end_i = 2;

#if USED_NOISE_HOPPING_FREQ
	uint16_t * pBaseImage;

	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	{
		pBaseImage = g_pLocalBaseImage;
	}
	else
	{
		pBaseImage = g_pLocalHop1BaseImage;
	}
#else /* USED_NOISE_HOPPING_FREQ */
	uint16_t * pBaseImage = g_pLocalBaseImage;
#endif /* USED_NOISE_HOPPING_FREQ */


#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)   
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
#endif
	{		
		if(mode == LOCAL_SEARCH_MODE && !thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode)
		{
			end_i = 1; 
			if(thisModeConf->BaseLine.ucPP_MUX_Select)shift_idx = 1;
		}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) 
		for(i = 1; i < end_i; i++) 	
#else		
		for(i = 0; i < end_i; i++)
#endif
		{
			if(i == 1 || shift_idx == 1)
			{
				raw_idx = PEN_COORD_ROW_MAX;
				if(thisModeConf->BaseLine.bPen_2BASE)base_idx = ROW_MAX;
			}

#if (USED_DSPA_FUNC_FOR_PEN_LOCAL || USED_DSPA_FUNC_FOR_PEN_SEARCH)
			if((thisModeConf->BaseLine.bDspA_SearchMode_PenPhase && mode == LOCAL_SEARCH_MODE) || (thisModeConf->BaseLine.bDspA_LocalMode_PenPhase && mode != LOCAL_SEARCH_MODE))
			{
				thisInfo->tDelta_local.iMaxStrength = thisInfo->tDelta_local.iMinStrength = 0;
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) 
				uint32_t Src2Addr = (uint32_t)&LOCALDATARAW_3[0][0];
	#else
				uint32_t Src2Addr = (uint32_t)&LOCALRAWIMAGE[0][0];
	#endif
				uint32_t Src1Addr = (uint32_t)&LOCALBASELINE[currentRowStart][0];
				Src1Addr += ((base_idx*COL_MAX)<<1);
				Src2Addr += ((raw_idx*COL_MAX)<<1);
				
				DSPA_CalculateDelta_Process(
					Src1Addr, Src2Addr, 0, (uint32_t)&DSPATMPDELTA[0][0],  							//SRC1_ADDR, SRC2_ADDR, SRC3_ADDR, DST_DDR  
					0,SUBTRACTION, 0,0,1, 0,0,0, HALFWORD,HALFWORD,       							//CAL1_WithCoef,CAL2_MODE, SRC2_DIV,DST_DIV,GetValueEnable, Const_a,Const_b,Const_n, SRC2_DataType,DST_DataType
					500,-500,500,                      												//PosTH,NegTH,GroupTH 
					start_c,end_c, ((mode == LOCAL_SEARCH_MODE)?0:1), PEN_COORD_ROW_MAX, 0, 0, 2);	//cs,ce, LocalColumnEn, Row_Size, mux_sum,PadMode,OpMode
				
				thisPenInfo->s_search_max_delta[i] = thisInfo->tDelta_local.iMaxStrength;
				thisPenInfo->s_search_min_delta[i] = thisInfo->tDelta_local.iMinStrength;
			}
			else
#endif
			{
				for( r=start_r; r<end_r; r++ )
				{
					int r_pos = ((r+local_rs+base_idx)*COL_MAX);
					int raw_r_pos = (r+raw_idx)*COL_MAX;
					for( c=start_c; c<end_c; c++ )
					{
						read_raw_data = thisPenInfo->pTmpModeRawImg[raw_r_pos+c];
//#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) 
//						read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+raw_idx, c);
//#else
//						read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+raw_idx, c);
//#endif
						delta = (signed)pBaseImage[r_pos + c] - (signed)read_raw_data;
			
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
						if(delta > thisPenInfo->s_search_max_delta[i])
						{
							thisPenInfo->s_search_max_delta[i] = delta;
						}
						
						if(delta < thisPenInfo->s_search_min_delta[i])
						{
							thisPenInfo->s_search_min_delta[i] = delta;
						}
					}
				}
			}
			
			if(thisPenInfo->s_search_max_delta[i] < -thisPenInfo->s_search_min_delta[i] )
				thisPenInfo->bPen_phase[i] = 1;
#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN) 			
			if(g_RetVal != PARTIAL_PEN_COORD1)
			{
				if(thisPenInfo->s_search_max_delta[i] < -thisPenInfo->s_search_min_delta[i] && -thisPenInfo->s_search_min_delta[i] > min_delta_th)
				{
					thisPenInfo->bMS_Contact2bit[i] = 1;
				}
				else
				{
					thisPenInfo->bMS_Contact2bit[i] = 0;
				}
			}
#endif
		}

#if (UseLastContact3x3 == YES)		
		if(g_RetVal != PARTIAL_PEN_COORD1)
		{
			if(thisPenInfo->bMS_Contact2bit[0] == 0 && thisPenInfo->bMS_Contact2bit[1] == 0)
			{
				if(thisPenInfo->bPenContact)pTRingInfo.sLastContact3x3Val = pTRingInfo.s3x3Val;
			}
		}
#endif
		
#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN) 		
		if(thisModeConf->BaseLine.ucPP_MUX_Select && shift_idx == 0)
		{
			bool_t tmp_phase = thisPenInfo->bPen_phase[0];
			thisPenInfo->bPen_phase[0] = thisPenInfo->bPen_phase[1];
			thisPenInfo->bPen_phase[1] = tmp_phase;
		}
#endif		
#if (USED_DSPA_FUNC_FOR_PEN_LOCAL || USED_DSPA_FUNC_FOR_PEN_SEARCH)		
		thisInfo->tDelta_local.iMaxStrength = thisInfo->tDelta_local.iMinStrength = 0;
#endif
#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN) 	
	#if LOCAL_REBASE_ALGO_EN && (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)// || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)	
		if(g_RetVal == PARTIAL_PEN_COORD1)
		{
			for( r=start_r; r<end_r; r++ )for( c=start_c; c<end_c; c++ )
			{
				delta = (signed)HAL_READ_RECAL_BASELINE_IMAGE(r+currentRowStart,c) - (signed)HAL_READ_LOCAL_RAW_IMAGE(r,c);
				delta >>= ptModuleModeConf->ucLocalOvrShift;
				if( delta < thisModeConf->BaseLine.sAccumNegSumThd )
				{
					thisInfo->tDelta_local.iNegSum += delta - thisModeConf->BaseLine.sAccumNegSumThd;
				}				
			}
		}
	#endif
#endif		
	}
}
#endif

#ifdef CalculateDeltaLocalSearch_OPCODE
bool_t algorithm_local_baseline_calculate_delta_pre(int mode)
{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	thisPenInfo->bPen_phase[0] = thisPenInfo->bPen_phase[1] = 0;
	thisPenInfo->s_search_max_delta[0] = thisPenInfo->s_search_max_delta[1] = 0;
	thisPenInfo->s_search_min_delta[0] = thisPenInfo->s_search_min_delta[1] = 0;
	thisInfo->PenCalcDeltaSetVal.pen_touch_data = 0;
#endif
	
#if (ADAPTOR_NOISE_ALGO_EN)
	if(thisPenInfo->bAdaptorNoise == 1)
	{
		thisPenInfo->bAdaptorNoise = NO;
		memset(LOCALNOISEBUF2,0,sizeof(LOCALNOISEBUF2));
	}
	
	if(thisInfo->PenCalcDeltaSetVal.bAdaptorNoise_SearchMode)
	{
		if(thisInfo->bTouchExpect == NO)
		{
			thisInfo->PenCalcDeltaSetVal.bAdaptorNoise_SearchMode = NO;	
			memset(LOCALNOISEBUF2,0,sizeof(LOCALNOISEBUF2));
		}
	}
	thisInfo->PenCalcDeltaSetVal.tmp_AdaptorNoiseTH = thisModeConf->Noise.cAdaptorNoiseTH_SearchHover;
	thisInfo->PenCalcDeltaSetVal.tmp_AdaptorNoiseContiNum = thisModeConf->Noise.ucAdaptorNoiseContiNum_SearchHover;	
#endif
	
	thisInfo->PenCalcDeltaSetVal.local_rs = currentRowStart;
	thisInfo->PenCalcDeltaSetVal.local_cs = currentColStart;

	thisPenInfo->ucCoordiRowStart = thisInfo->PenCalcDeltaSetVal.local_rs;
	thisPenInfo->ucCoordiColumnStart = thisInfo->PenCalcDeltaSetVal.local_cs;

	thisInfo->PenCalcDeltaSetVal.start_r = 0, thisInfo->PenCalcDeltaSetVal.start_c = 0;
	thisInfo->PenCalcDeltaSetVal.end_r = PEN_COORD_ROW_MAX, thisInfo->PenCalcDeltaSetVal.end_c = COL_MAX;
	
	memset((void *)(&thisInfo->tDelta_local), 0x00, sizeof(tOrigDeltaInfo_t));
	thisInfo->tDelta_local.tValidRect.cs = COL_MAX - 1; thisInfo->tDelta_local.tValidRect.ce = 0;
	thisInfo->tDelta_local.tValidRect.rs = ROW_MAX - 1; thisInfo->tDelta_local.tValidRect.re = 0;

    thisInfo->PenCalcDeltaSetVal.MuxSum = 0;

	if(thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode == YES)
		thisInfo->PenCalcDeltaSetVal.MuxSum=1;
	
#ifdef FingerAreaLineFilter
	algorithm_noise_FingerAreaLineFilter(thisPenInfo->start_r,thisPenInfo->end_r,thisPenInfo->start_c,thisPenInfo->end_c,local_rs,MuxSum);
#endif

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	algorithm_Cal_MS_phase(thisInfo->PenCalcDeltaSetVal.start_r,thisInfo->PenCalcDeltaSetVal.end_r,thisInfo->PenCalcDeltaSetVal.start_c,thisInfo->PenCalcDeltaSetVal.end_c,mode,thisInfo->PenCalcDeltaSetVal.local_rs);
#endif 

	if(thisPenInfo->bPenContact)
		thisInfo->PenCalcDeltaSetVal.bContact = 1;

	thisInfo->PenCalcDeltaSetVal.delta_th = thisModeConf->Label.usLocalSeedBase;

	thisInfo->PenCalcDeltaSetVal.ucLocalOvrShift = (ptModuleModeConf->ucLocalOvrShift);

	thisInfo->PenCalcDeltaSetVal.tmpSearchNoiseRejectFrm = thisModeConf->Noise.ucSearchNoiseRejectFrm;
	
	thisInfo->PenCalcDeltaSetVal.raw_idx = 0;
	thisInfo->PenCalcDeltaSetVal.base_idx = 0;
	
	if(thisModeConf->BaseLine.ucPP_MUX_Select)
	{
		thisInfo->PenCalcDeltaSetVal.raw_idx = PEN_COORD_ROW_MAX;
		if(thisModeConf->BaseLine.bPen_2BASE)thisInfo->PenCalcDeltaSetVal.base_idx = ROW_MAX;
	}
	
	thisInfo->PenCalcDeltaSetVal.MuxSum_raw_idx = 0;
	thisInfo->PenCalcDeltaSetVal.MuxSum_base_idx = 0;
	if(thisInfo->PenCalcDeltaSetVal.MuxSum)
	{
		if(thisModeConf->BaseLine.ucPP_MUX_Select == 0)
		{
			thisInfo->PenCalcDeltaSetVal.MuxSum_raw_idx = PEN_COORD_ROW_MAX;
			if(thisModeConf->BaseLine.bPen_2BASE)thisInfo->PenCalcDeltaSetVal.MuxSum_base_idx = ROW_MAX;
		}
	}
	
	thisInfo->PenCalcDeltaSetVal.ucAdaptorNoise_CalDeltaRepeatSimbol = 1;
	
	thisInfo->PenCalcDeltaSetVal.col_max = COL_MAX;
	thisInfo->PenCalcDeltaSetVal.row_max = ROW_MAX;
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	thisInfo->PenCalcDeltaSetVal.zero_finger_rawdata_mask_num = ZERO_FINGER_RAWDATA_MASK_NUM;
#endif	
	thisInfo->PenCalcDeltaSetVal.g_RetVal = g_RetVal;
	thisInfo->PenCalcDeltaSetVal.gAlgoRawDataType = gAlgoRawDataType;	
	thisInfo->PenCalcDeltaSetVal.ucPen_th1 = thisModeConf->Label.ucLocalPenDetectTH1;
	thisInfo->PenCalcDeltaSetVal.ucPen_th2 = thisModeConf->Label.ucLocalPenDetectTH2;	
	thisInfo->PenCalcDeltaSetVal.ucSearchNoiseRejectTH = thisModeConf->Noise.ucSearchNoiseRejectTH;
	thisInfo->PenCalcDeltaSetVal.ucSearchNoiseRejectFrm = thisModeConf->Noise.ucSearchNoiseRejectFrm;
	thisInfo->PenCalcDeltaSetVal.bMS_phase = thisPenInfo->bPen_phase[0];
	thisInfo->PenCalcDeltaSetVal.bMS_Contact2bit[0] = thisPenInfo->bMS_Contact2bit[0];
	thisInfo->PenCalcDeltaSetVal.bMS_Contact2bit[1] = thisPenInfo->bMS_Contact2bit[1];
	thisInfo->PenCalcDeltaSetVal.LocalFingerArea.rs = thisPenInfo->LocalFingerArea.rs;
	thisInfo->PenCalcDeltaSetVal.LocalFingerArea.re = thisPenInfo->LocalFingerArea.re;
	thisInfo->PenCalcDeltaSetVal.LocalFingerArea.cs = thisPenInfo->LocalFingerArea.cs;
	thisInfo->PenCalcDeltaSetVal.LocalFingerArea.ce = thisPenInfo->LocalFingerArea.ce;
	thisInfo->PenCalcDeltaSetVal.ucPP_MUX_Select = thisModeConf->BaseLine.ucPP_MUX_Select;
	thisInfo->PenCalcDeltaSetVal.cFingerAreaPenDeltaDelete = thisModeConf->BaseLine.cFingerAreaPenDeltaDelete;
	thisInfo->PenCalcDeltaSetVal.cFingerAreaPenDeltaNoAcc = thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc;
	thisInfo->PenCalcDeltaSetVal.sAccumPosSumThd = thisModeConf->BaseLine.sAccumPosSumThd;
	thisInfo->PenCalcDeltaSetVal.sAccumNegSumThd = thisModeConf->BaseLine.sAccumNegSumThd;
	thisInfo->PenCalcDeltaSetVal.bBlockTrackingByLocalDelta = thisInfo->bBlockTrackingByLocalDelta;
    
	return 0;
}

bool_t algorithm_local_baseline_calculate_delta_post(int mode)
{
	int pen_sum_TData = 0;
//	uint8_t row_start = 0;
	
	thisInfo->bBlockTrackingByLocalDelta = thisInfo->PenCalcDeltaSetVal.bBlockTrackingByLocalDelta;
	
//    thisInfo->tDelta_local.sPrevMaxDelta2 = thisInfo->PenCalcDeltaSetVal.pen_touch_data;

    pen_sum_TData = algorithm_calc_3by3LocalDeltaSum(thisInfo->PenCalcDeltaSetVal.pen_pos);	// 3by3 sum
    
    if( (thisInfo->PenCalcDeltaSetVal.pen_touch_data > thisInfo->PenCalcDeltaSetVal.ucPen_th1 || pen_sum_TData > thisInfo->PenCalcDeltaSetVal.ucPen_th2))
    {		
        thisInfo->bTouchExpect_local = NO;
		thisPenInfo->bSearch_Mode_Flag = 0;
		hal_Info_SetPenDectionEnable(YES);
		
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_PEN_BEACON);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
    
//        #ifdef TILT_ON
//        row_start = thisInfo->PenCalcDeltaSetVal.pen_pos.r + thisInfo->PenCalcDeltaSetVal.local_rs;
//        algorithm_baseline_calculate_local_mux_range(row_start, thisInfo->PenCalcDeltaSetVal.pen_pos.c,0);
//        #else
        algorithm_baseline_calculate_local_mux_range(thisInfo->PenCalcDeltaSetVal.pen_pos.r+thisInfo->PenCalcDeltaSetVal.local_rs, thisInfo->PenCalcDeltaSetVal.pen_pos.c,0);
//        #endif
        
        thisInfo->PenCalcDeltaSetVal.ucAdaptorNoise_CalDeltaRepeatSimbol = 0;
    }
    else
    {
        thisInfo->bLocal_sensing = NO;
        thisInfo->bTouchExpect_local = NO;
#if ADAPTOR_NOISE_ALGO_EN
        if(thisModeConf->Noise.bPenPosSymbolRepeatCheck == 1 && gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisPenInfo->bAdaptorNoise) // MS PenLHB Noise By LocalFinger : 6 Symbol Repeat Check , hanch
        {
            thisInfo->PenCalcDeltaSetVal.ucAdaptorNoise_CalDeltaRepeatSimbol++;						
            if(thisInfo->PenCalcDeltaSetVal.ucAdaptorNoise_CalDeltaRepeatSimbol>6)
            {
                thisInfo->PenCalcDeltaSetVal.ucAdaptorNoise_CalDeltaRepeatSimbol = 0;
                thisPenInfo->bPosUpdateSkip = 1;
                thisPenInfo->bReportSkip = 1;
            }
        }
        else 
            thisInfo->PenCalcDeltaSetVal.ucAdaptorNoise_CalDeltaRepeatSimbol = 0;
#endif
    }
#if ADAPTOR_NOISE_ALGO_EN  
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisPenInfo->bAdaptorNoise)
	{
		if((abs(thisInfo->tDelta_local.tMaxCellPos.r - thisPenInfo->cPreMaxR) > 1 || abs(thisInfo->tDelta_local.tMaxCellPos.c - thisPenInfo->cPreMaxC) > 1))
		{
			thisPenInfo->bPosUpdateSkip = 1;
			thisPenInfo->bReportSkip = 1;
		}
	}
#endif	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
	{
	#if ADAPTOR_NOISE_ALGO_EN
		if(thisPenInfo->bAdaptorNoise==1)
		{
			thisPenInfo->ucTmpForcePenContact_NUM = 10;
		}		
	#endif		
		if(thisPenInfo->bAdaptorNoise == 0)
			thisPenInfo->ucTmpForcePenContact_NUM = thisModeConf->PenData.ucForcePenContact_NUM;
		
		if(g_RetVal != PARTIAL_PEN_COORD1)
		{	
			if(thisPenInfo->bMS_Contact2bit[0] == 1 && thisPenInfo->bMS_Contact2bit[1] == 1 &&(thisInfo->bLocal_sensing))
			{
				thisPenInfo->bPenContact = YES;
				thisInfo->ucContact_MS = thisPenInfo->ucTmpForcePenContact_NUM;
			}
			// slim pen contact loss issue when side button keeping drawing 
			else if(g_RetVal == PARTIAL_PEN_COORD2 && thisPenInfo->bPen_button[1] == 1 && thisPenInfo->bMS_Contact2bit[1] == 1 && thisInfo->bLocal_sensing)
			{
				thisPenInfo->bPenContact = YES;
			}
			// hanch
			else if(thisInfo->ucContact_MS > 0)
			{
				thisPenInfo->bPenContact = YES;
				thisInfo->ucContact_MS--;
			}
			else
			{
				thisInfo->ucContact_MS = 0;
				thisPenInfo->bPenContact = NO;
			}
			thisPenInfo->bPenContactConti = thisPenInfo->bPenContact;
		}
		else
			thisPenInfo->bPenContact = thisPenInfo->bPenContactConti;
	}
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)	
	#if AbnormalContactRemove_EN
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP)
	{
		if(thisModeConf->PenData.ucAbnormalContactRemovePressureTH1	> 0 && thisModeConf->PenData.ucAbnormalContactRemovePressureTH2 > 0)	
		{
			thisPenInfo->bEdgeAbnormalContact = 0;
			if(thisInfo->PenCalcDeltaSetVal.pen_pos.r == 0 || thisInfo->PenCalcDeltaSetVal.pen_pos.r == ROW_MAX-1 || thisInfo->PenCalcDeltaSetVal.pen_pos.c == 0 || thisInfo->PenCalcDeltaSetVal.pen_pos.c == COL_MAX-1)thisPenInfo->bEdgeAbnormalContact = 1;
			if( (thisPenInfo->bPenContact == YES) && thisPenInfo->bEdgeAbnormalContact == 1)
			{
				uint8_t ucDeltaSub1Th = thisModeConf->PenData.ucAbnormalContactRemoveDeltaTH1; //17;
				uint8_t ucDeltaSub2Th = thisModeConf->PenData.ucAbnormalContactRemoveDeltaTH2; //30;
			
				if(thisPenInfo->bPenOffChk == 1)
				{
					if(thisPenInfo->sPrevContactMaxDelta[0] - thisInfo->PenCalcDeltaSetVal.pen_touch_data > ucDeltaSub1Th)
						thisPenInfo->bPenContact = NO;
					else if(thisPenInfo->sPrevContactMaxDelta[1] - thisInfo->PenCalcDeltaSetVal.pen_touch_data > ucDeltaSub2Th)
						thisPenInfo->bPenContact = NO;
				}

				thisPenInfo->sPrevContactMaxDelta[1] = thisPenInfo->sPrevContactMaxDelta[0];
				thisPenInfo->sPrevContactMaxDelta[0] = thisInfo->PenCalcDeltaSetVal.pen_touch_data;
			}
			else
			{
				thisPenInfo->sPrevContactMaxDelta[1] = 0;
				thisPenInfo->sPrevContactMaxDelta[0] = 0;
			}
		}
	}
	#endif
#endif
	
	if(thisInfo->PenCalcDeltaSetVal.bContact && thisInfo->PenCalcDeltaSetVal.ucReleaseFrame < thisModeConf->Noise.ucHoverNoiseRejectFrm) thisInfo->PenCalcDeltaSetVal.ucReleaseFrame++;
	if(!thisInfo->bLocal_sensing || thisInfo->PenCalcDeltaSetVal.ucReleaseFrame == thisModeConf->Noise.ucHoverNoiseRejectFrm)
	{
		thisInfo->PenCalcDeltaSetVal.bContact = 0;
		thisInfo->PenCalcDeltaSetVal.ucReleaseFrame = 0;
	}
		
	return 0; 
}
#endif

#if (HighHoverDeltaIIR_En == YES)
int TmpPreDelta[PEN_COORD_ROW_MAX][COL_CAL_SIZE+1] = {0,};
#endif
bool_t algorithm_local_baseline_calculate_delta(int mode)
{
	int r, r1, c;
	int delta,delta_th,delta2;
	int start_r, end_r;
	int start_c, end_c;
	int local_rs, local_cs;
	int pen_touch_data = 0;
	uint16_t read_raw_data;
	tCell_t pen_pos;
	int pen_sum_TData = 0;
	static bool_t bContact = 0;
	static uint8_t ucReleaseFrame = 0;
	int sensingRowOffset = (currentRowStart - p_currentRowStart);
	int temp_r;
	static int PenDetectTH1_Offset = 0;
	static int PenDetectTH2_Offset = 0;
#if (CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP && CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
	int i,j;
#endif
#if (ADAPTOR_NOISE_ALGO_EN)
	static bool_t bAdaptorNoise_SearchMode = 0;
	uint8_t	ucAdaptorNoise_CalDeltaRepeatSimbol;
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)	
	static uint8_t ring_rs = 0;
	static uint8_t tip_rs = 0;
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	thisPenInfo->bPen_phase[0] = thisPenInfo->bPen_phase[1] = 0;
	thisPenInfo->s_search_max_delta[0] = thisPenInfo->s_search_max_delta[1] = 0;
	thisPenInfo->s_search_min_delta[0] = thisPenInfo->s_search_min_delta[1] = 0;
#endif

	uint8_t ucPen_th1 = thisModeConf->Label.ucLocalPenDetectTH1 - PenDetectTH1_Offset;
	uint8_t ucPen_th2 = thisModeConf->Label.ucLocalPenDetectTH2 - PenDetectTH2_Offset;

#if (CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP && CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
	uint8_t tmpSearchNoiseRejectFrm = thisModeConf->Noise.ucSearchNoiseRejectFrm;
#endif
	
#if (ADAPTOR_NOISE_ALGO_EN)
	if(thisPenInfo->bAdaptorNoise == 1)
	{
		if(thisInfo->bTouchExpect == NO || mode != LOCAL_MODE)
		{
			thisPenInfo->bAdaptorNoise = NO;
			memset(LOCALNOISEBUF2,0,sizeof(LOCALNOISEBUF2));

		}
	}
	
	if(bAdaptorNoise_SearchMode)
	{
		if(thisInfo->bTouchExpect == NO || mode == LOCAL_MODE)
		{
			bAdaptorNoise_SearchMode = NO;	
			memset(LOCALNOISEBUF2,0,sizeof(LOCALNOISEBUF2));
		}
	}
	
	int tmp_AdaptorNoiseTH, tmp_AdaptorNoiseContiNum;	
	if(mode == LOCAL_MODE)
	{
		tmp_AdaptorNoiseTH = thisModeConf->Noise.cAdaptorNoiseTH;
		tmp_AdaptorNoiseContiNum = thisModeConf->Noise.ucAdaptorNoiseContiNum;
	}
	else
	{
		tmp_AdaptorNoiseTH = thisModeConf->Noise.cAdaptorNoiseTH_SearchHover;
		tmp_AdaptorNoiseContiNum = thisModeConf->Noise.ucAdaptorNoiseContiNum_SearchHover;		
	}
	
	if(bAdaptorNoise_SearchMode != YES && gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
		tmpSearchNoiseRejectFrm = 0;
#endif
	
	local_rs = currentRowStart;
	local_cs = currentColStart;

	thisPenInfo->ucCoordiRowStart = local_rs;
	thisPenInfo->ucCoordiColumnStart = local_cs;

	start_r = 0, start_c = 0;
	end_r = PEN_COORD_ROW_MAX, end_c = COL_MAX;
	memset((void *)(&thisInfo->tDelta_local), 0x00, sizeof(tOrigDeltaInfo_t));
	thisInfo->tDelta_local.tValidRect.cs = COL_MAX - 1; thisInfo->tDelta_local.tValidRect.ce = 0;
	thisInfo->tDelta_local.tValidRect.rs = ROW_MAX - 1; thisInfo->tDelta_local.tValidRect.re = 0;

	if(mode != LOCAL_SEARCH_MODE)
	{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
		start_c = MAX(0,thisPenInfo->ucCurrentColumnStart-4);
		end_c = MIN(COL_MAX,thisPenInfo->ucCurrentColumnEnd+5);
	#else
		start_c = thisPenInfo->ucCurrentColumnStart;
		end_c = MIN(COL_MAX,thisPenInfo->ucCurrentColumnEnd+1);
	#endif
#else
		start_c = thisPenInfo->ucCurrentColumnStart;
		end_c = MIN(COL_MAX,thisPenInfo->ucCurrentColumnEnd+1);
#endif
	}
	
#if USED_ADAPTIVE_LOCAL_SENSING
	if(sensingRoicStart != ROIC_NUM)
	{
		start_c = 6*sensingRoicStart;
		end_c = start_c + 2*ROIC_COL_SIZE;
	}
#endif /* USED_ADAPTIVE_LOCAL_SENSING */

#if USED_NOISE_HOPPING_FREQ
	uint16_t * pBaseImage;

//	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	if(ptAppInfo->eCurrentSelectFreq == FREQ_MAIN)
	{
//		_gT(_GPIO_TP_INTR);
		pBaseImage = g_pLocalBaseImage;
	}
	else
	{
//		_gT(_GPIO_TP_INTR);
		pBaseImage = g_pLocalHop1BaseImage;
	}
#else /* USED_NOISE_HOPPING_FREQ */
	uint16_t * pBaseImage = g_pLocalBaseImage;
#endif /* USED_NOISE_HOPPING_FREQ */

#if (CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP && CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
	bool_t MuxSum = 0;
	if(mode == LOCAL_SEARCH_MODE)
	{
		//if(thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode == YES)
			MuxSum = thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode;
	}
	else
	{
		//if(thisModeConf->BaseLine.b2MUX_SUM_LocalMode == 1)
			MuxSum = thisModeConf->BaseLine.b2MUX_SUM_LocalMode;
	}
#endif
	
#ifdef FingerAreaLineFilter
	algorithm_noise_FingerAreaLineFilter(start_r,end_r,start_c,end_c,local_rs,MuxSum);
#endif

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
  #if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
	if(mode != LOCAL_SEARCH_MODE)
	#else
	if(mode != LOCAL_SEARCH_MODE && MuxSum)
	#endif
		algorithm_Cal_MS_phase(start_r,end_r,start_c,end_c,mode,local_rs);
  #else
	algorithm_Cal_MS_phase(start_r,end_r,start_c,end_c,mode,local_rs);
  #endif
#endif 

	if(thisPenInfo->bPenContact)
		bContact = 1;

	uint8_t ucLocalOvrShift;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN)
	#ifdef TILT_ON
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM && g_RetVal==PARTIAL_PEN_COORD2 && mode == LOCAL_MODE)
	{
		delta_th = thisModeConf->Label.usLocalSeedBase_Ring;
		ucLocalOvrShift = (ptModuleModeConf->ucLocalOvrShift_Ring);
	}
	else 
	#endif
#endif
	{
		delta_th = thisModeConf->Label.usLocalSeedBase;
		ucLocalOvrShift = (ptModuleModeConf->ucLocalOvrShift);
	}

#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
	if(thisInfo->tCoord_local_dsp.tPastPos[0].vusS > 0 && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < 1280)delta_th=50;
#endif

	uint8_t raw_idx = 0;
//#if ((CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP && CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP_86KHz) || \
//	(CUSTOMER != MODEL_DEF_UHD_98500_WGP_PEN) || (CUSTOMER != MODEL_DEF_UHD_98502_WGP_PEN))
#if (CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP && CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
	uint8_t MuxSum_raw_idx = 0;
	uint8_t base_idx = 0;
	
	if(thisModeConf->BaseLine.ucPP_MUX_Select)
	{
		raw_idx = PEN_COORD_ROW_MAX;
		if(thisModeConf->BaseLine.bPen_2BASE)
			base_idx = ROW_MAX;
	}
		
	uint8_t MuxSum_base_idx = 0;
	if(MuxSum)
	{
		if(thisModeConf->BaseLine.ucPP_MUX_Select == 0)
		{
			MuxSum_raw_idx = PEN_COORD_ROW_MAX;
			if(thisModeConf->BaseLine.bPen_2BASE)
				MuxSum_base_idx = ROW_MAX;
		}
	}
#endif
	
#if ADAPTOR_NOISE_ALGO_EN	
	ucAdaptorNoise_CalDeltaRepeatSimbol = 1;
	while(ucAdaptorNoise_CalDeltaRepeatSimbol>0)
#endif
	{	
#if (USED_DSPA_FUNC_FOR_PEN_LOCAL || USED_DSPA_FUNC_FOR_PEN_SEARCH)
		if((!thisModeConf->BaseLine.bDspA_LocalMode_CalculateDelta && mode != LOCAL_SEARCH_MODE) || (!thisModeConf->BaseLine.bDspA_SearchMode_CalculateDelta && mode == LOCAL_SEARCH_MODE))
#endif
		{
#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
			int base_idx_r_pos = 0;
			int MuxSum_base_idx_r_pos = ROW_MAX*COL_MAX;
#else
			int base_idx_r_pos = base_idx*COL_MAX;
			int MuxSum_base_idx_r_pos = MuxSum_base_idx*COL_MAX;
#endif
			for( r1=start_r; r1<end_r; r1++ )
			{
				if(sensingRowOffset >= 0) r = r1;
				else r = PEN_COORD_ROW_MAX - 1 - r1;
				temp_r = r + sensingRowOffset;
				int r_pos = ((r+local_rs)*COL_MAX);
				int raw_r_pos = (r+raw_idx)*COL_MAX;
#if (CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP && CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
				int MuxSum_raw_r_pos = (r+MuxSum_raw_idx)*COL_MAX;
#endif
				int delta_r_pos = (r+PAD_)*(COL_MAX+PAD_+PAD_);
				for( c=start_c; c<end_c; c++ )
				{
					read_raw_data = thisPenInfo->pTmpModeRawImg[raw_r_pos+c];

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL ==PEN_PROTOCOL_MSnWGP_PEN)
					if(thisPenInfo->bPen_phase[0] == 1)
					{
						delta = (signed)read_raw_data - (signed)pBaseImage[r_pos+base_idx_r_pos + c];
					}
					else
#endif
					{
						delta = (signed)pBaseImage[r_pos+base_idx_r_pos + c] - (signed)read_raw_data;
					}
					
#ifdef FingerAreaPenDeltaDelete					
					if(thisModeConf->BaseLine.cFingerAreaPenDeltaDelete != 0)
					{
						if(thisPenInfo->LocalFingerArea.rs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= r+local_rs
						&& thisPenInfo->LocalFingerArea.re + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= r+local_rs
						&& thisPenInfo->LocalFingerArea.cs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= c
						&& thisPenInfo->LocalFingerArea.ce + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= c)
						{						
							delta = 0;
						}
					}
#endif
		
#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
					read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+PEN_COORD_ROW_MAX, c);
					delta2 = (signed)pBaseImage[r_pos+MuxSum_base_idx_r_pos + c] - (signed)read_raw_data;
					if((thisPenInfo->bPen_phase[1]==1 && mode == LOCAL_MODE) || (delta2 < 0 && delta > 0 && mode == LOCAL_HOVER_MODE))
						delta2=-delta2;		
					
					delta += delta2;
//#elif (CUSTOMER == MODEL_DEF_UHD_98500_WGP_PEN || CUSTOMER == MODEL_DEF_UHD_98502_WGP_Pen)
//					read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+PEN_COORD_ROW_MAX, c);
//					delta2 = (signed)pBaseImage[r_pos+MuxSum_base_idx_r_pos + c] - (signed)read_raw_data;
//					if((thisPenInfo->bPen_phase[1]==1 && mode == LOCAL_MODE) || (delta2 < 0 && delta > 0 && mode == LOCAL_HOVER_MODE))
//						delta2=-delta2;

//					delta += delta2;
#else
					if(MuxSum)
					{
						read_raw_data = thisPenInfo->pTmpModeRawImg[MuxSum_raw_r_pos+c];
						
						delta2 = (signed)pBaseImage[r_pos+MuxSum_base_idx_r_pos + c] - (signed)read_raw_data;
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL ==PEN_PROTOCOL_MSnWGP_PEN)
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL ==PEN_PROTOCOL_MSnWGP_PEN)
						if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
		#endif
							if(thisPenInfo->bPen_phase[1]==1)
								delta2=-delta2;
	#endif 
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
						if((thisPenInfo->bPen_phase[1]==1 && mode == LOCAL_MODE) || (delta2 < 0 && delta > 0 && mode == LOCAL_HOVER_MODE))
							delta2=-delta2;	
	#endif
						delta += delta2;
					}
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
					else
					{
						if(thisModeConf->BaseLine.ucPP_MUX_Select && mode == LOCAL_MODE)
							if(delta<0)delta=-delta;
					}
	#endif
#endif

					delta >>= (ucLocalOvrShift);
#if (LocalNormalizeEn == YES)					
					if(thisModeConf->BaseLine.ucLocalNormalizeMaxOffset != 0)
					{
						int NormalizeOffset = thisModeConf->BaseLine.ucLocalNormalizeMaxOffset * (r+local_rs)/ROW_MAX-1;
						delta = delta * (100 - NormalizeOffset)/100;
					}
#endif
#if (ADAPTOR_NOISE_ALGO_EN)
					if( (mode == LOCAL_HOVER_MODE || mode == LOCAL_SEARCH_MODE) && 
						((gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisPenInfo->bMS_Contact2bit[0] == 0)
						|| gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM || gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP))
					{
						if(tmp_AdaptorNoiseTH != 0)
						{							
							int tmp_delta;
							if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
							{
								read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r, c);
								tmp_delta = (signed)pBaseImage[r_pos+base_idx_r_pos + c] - (signed)read_raw_data;
								tmp_delta >>= (ucLocalOvrShift);
							}
							else 
								tmp_delta = delta;
							
							if( tmp_delta < tmp_AdaptorNoiseTH && (gAlgoRawDataType != ACTIVEPEN_TYPE_LOCAL_MS || (gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && g_RetVal == PARTIAL_PEN_COORD1)) )
							{
	//							LOCALNOISEBUF2[r+local_rs][c] = tmp_AdaptorNoiseContiNum;
								for(i=MAX(0,r+local_rs-2);i<=MIN(ROW_MAX-1,r+local_rs+2);i++)for(j=MAX(0,c-2);j<=MIN(COL_MAX-1,c+2);j++)
									LOCALNOISEBUF2[i][j] = tmp_AdaptorNoiseContiNum;
							}
							else
							{
								if(LOCALNOISEBUF2[r+local_rs][c] > 0) LOCALNOISEBUF2[r+local_rs][c]--;
							}
							
							if(LOCALNOISEBUF2[r+local_rs][c] != 0)
							{
								delta = 0;
								bAdaptorNoise_SearchMode = YES;
							}			
						}						
					}
#endif

					if(mode == LOCAL_HOVER_MODE)
					{
						if(temp_r >= 0 && temp_r < PEN_COORD_ROW_MAX)
							delta2 = thisPenInfo->pTmpModeDeltaImg[(temp_r+PAD_)*(COL_MAX+PAD_+PAD_)+(c+PAD_)];//HAL_READ_LOCAL_DELTA_IMAGE(temp_r, c);
						else
							delta2 = 0;

						if(delta > thisModeConf->Noise.ucHoverNoiseRejectTH) // PenLHB_NoiseByLocalFinger Reject, hanch
						{
							if(LOCALNOISEBUF1[r+local_rs][c] < thisModeConf->Noise.ucHoverNoiseRejectFrm)
								LOCALNOISEBUF1[r+local_rs][c]++;
									
							delta = (delta2*(thisModeConf->Label.ucHoverOutCheckFrm-1) + delta*thisModeConf->Label.ucHoverOutCheckFrm + thisModeConf->Label.ucHoverOutOffset)/thisModeConf->Label.ucHoverOutCheckFrm;
						}
						else
							LOCALNOISEBUF1[r+local_rs][c] = 0;
						
#if (HighHoverDeltaIIR_En == YES)
						if(thisModeConf->SensingFilter.ucHighHoverDeltaIIR_Coef > 0)
						{
							TmpPreDelta[r][c-start_c] = delta2;
						}
#endif
						
						//PenLHB_NoiseByLocalFinger Reject, continue data check, hanch
						if(LOCALNOISEBUF1[r+local_rs][c] < thisModeConf->Noise.ucHoverNoiseRejectFrm && !bContact)
							delta = 0;
							
					}
					else if(mode == LOCAL_SEARCH_MODE)
					{					
						if(delta>0)
						{	
#ifdef FingerAreaPenDeltaNoAcc
							bool_t bNoAccFlag = 0;
							if(thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc != 0)
							{
								if(thisPenInfo->LocalFingerArea.rs - thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc <= r+local_rs
								&& thisPenInfo->LocalFingerArea.re + thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc >= r+local_rs
								&& thisPenInfo->LocalFingerArea.cs - thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc <= c
								&& thisPenInfo->LocalFingerArea.ce + thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc >= c)
									bNoAccFlag = 1;
							}
#endif

#if (CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP && CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
							if(tmpSearchNoiseRejectFrm > 0)
							{
								if(delta > thisModeConf->Noise.ucSearchNoiseRejectTH)
								{
									if(LOCALNOISEBUF1[r+local_rs][c] < tmpSearchNoiseRejectFrm)//thisModeConf->Noise.ucSearchNoiseRejectFrm)
										LOCALNOISEBUF1[r+local_rs][c]++;
								}
								else LOCALNOISEBUF1[r+local_rs][c] = 0;

#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
								if(((ulZeroFingerRawMaskInfo[r+local_rs][c/ZERO_FINGER_RAWDATA_MASK_NUM] >> (c%ZERO_FINGER_RAWDATA_MASK_NUM)) & 0x1) == 0)
#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
								{
									if(delta > ucPen_th1) 
									{
										if(LOCALNOISEBUF1[r+local_rs][c] < tmpSearchNoiseRejectFrm)//thisModeConf->Noise.ucSearchNoiseRejectFrm)
										{
											for(i=MAX(0,r+local_rs-2);i<=MIN(ROW_MAX-1,r+local_rs+2);i++)for(j=MAX(0,c-2);j<=MIN(COL_MAX-1,c+2);j++)
												LOCALNOISEBUF1[i][j] = thisModeConf->Noise.ucSearchNoiseRejectFrm-1;
										}
									}
								}
								
								if(LOCALNOISEBUF1[r+local_rs][c] < tmpSearchNoiseRejectFrm)//thisModeConf->Noise.ucSearchNoiseRejectFrm)
									delta = 0;
							}
#endif
#ifdef FingerAreaPenDeltaNoAcc
							if(bNoAccFlag==0)
#endif
							{
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
								if(((ulZeroFingerRawMaskInfo[r+local_rs][c/ZERO_FINGER_RAWDATA_MASK_NUM] >> (c%ZERO_FINGER_RAWDATA_MASK_NUM)) & 0x1) == 0)
#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */	
								{
									delta += g_pFullHoverImage[r_pos+c];
								}								
							}
						}
						
						g_pFullHoverImage[r_pos+c] = delta;		
					}
#if (ADAPTOR_NOISE_ALGO_EN)
					else if( mode == LOCAL_MODE && ((gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM 
	#ifdef TILT_ON
							&& g_RetVal != PARTIAL_PEN_COORD2
	#endif
							 ) || gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS || gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP))
					{		
						if(tmp_AdaptorNoiseTH != 0)
						{						
							int tmp_delta;
							if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
							{
								tmp_delta = (signed)HAL_READ_LOCAL_RAW_IMAGE(r+PEN_COORD_ROW_MAX, c) - (signed)pBaseImage[r_pos+base_idx_r_pos + c];
								tmp_delta >>= (ucLocalOvrShift);
							}					
							else 
								tmp_delta = delta;
							
							if( tmp_delta < tmp_AdaptorNoiseTH )
							{
								LOCALNOISEBUF2[r+local_rs][c] = tmp_AdaptorNoiseContiNum;
							}
							else
							{
								if(LOCALNOISEBUF2[r+local_rs][c] > 0) LOCALNOISEBUF2[r+local_rs][c]--;
							}
							
							if(LOCALNOISEBUF2[r+local_rs][c] != 0)
							{
								delta = 0;
								thisPenInfo->bAdaptorNoise = YES;
							}
						}
					}
#endif
					thisPenInfo->pTmpModeDeltaImg[delta_r_pos+c+PAD_] = delta;
//					HAL_WRITE_LOCAL_DELTA_IMAGE(r, c, delta);
							
					if( delta > 0 )
					{
#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)
//						if( delta > thisModeConf->BaseLine.sAccumPosSumThd )
//						{
//							thisInfo->tDelta_local.iPosCnt++;
//							thisInfo->tDelta_local.iPosSum += delta - thisModeConf->BaseLine.sAccumPosSumThd;
//						}
#endif			
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)		
						if( delta > delta_th && mode != LOCAL_SEARCH_MODE)		
#else						
						if( delta > delta_th)
#endif
						{
							if( thisInfo->tDelta_local.tValidRect.cs > c )
								thisInfo->tDelta_local.tValidRect.cs = c;
							if( thisInfo->tDelta_local.tValidRect.ce < c )
								thisInfo->tDelta_local.tValidRect.ce = c;
							if( thisInfo->tDelta_local.tValidRect.rs > r )
								thisInfo->tDelta_local.tValidRect.rs = r;
							if( thisInfo->tDelta_local.tValidRect.re < r )
								thisInfo->tDelta_local.tValidRect.re = r;

//							thisInfo->tDelta_local.iGroupedCellCnt++;
						}
						
						if( thisInfo->tDelta_local.iMaxStrength < delta )
						{
							thisInfo->tDelta_local.iMaxStrength = delta;
//							pen_touch_data = delta;
//							pen_pos.r = r;
//							pen_pos.c = c;
							thisInfo->tDelta_local.tMaxCellPos.r = r;
							thisInfo->tDelta_local.tMaxCellPos.c = c;
						}
					}
#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)
					else
					{
	#if LOCAL_REBASE_ALGO_EN
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)// || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
//			#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
//						if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP)
//			#endif
						{							
							if( delta < thisModeConf->BaseLine.sAccumNegSumThd )
							{
	//							thisInfo->tDelta_local.iNegCnt++;
								thisInfo->tDelta_local.iNegSum += delta - thisModeConf->BaseLine.sAccumNegSumThd;
							}
						}
		#endif
	#endif
						if( thisInfo->tDelta_local.iMinStrength > delta )
						{
							thisInfo->tDelta_local.iMinStrength = delta;
						}

					}
#endif
				}
			}
		}
#if (USED_DSPA_FUNC_FOR_PEN_LOCAL || USED_DSPA_FUNC_FOR_PEN_SEARCH)
		else
		{
	#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
			algorithm_local_mode_calculate_delta_loop_dspA(start_c, end_c, mode, 1);
	#else
			algorithm_local_mode_calculate_delta_loop_dspA(start_c, end_c, mode, MuxSum);
	#endif
			pen_touch_data = thisInfo->tDelta_local.iMaxStrength;
			pen_pos = thisInfo->tDelta_local.tMaxCellPos;
		}
#endif
		
		if(thisInfo->tDelta_local.iMaxStrength > BlockTrackingThdByLocalDelta || thisInfo->tDelta_local.iMinStrength < -BlockTrackingThdByLocalDelta)thisInfo->bBlockTrackingByLocalDelta = YES;
		
//		thisInfo->tDelta_local.sPrevMaxDelta2 = pen_touch_data;
		pen_touch_data = thisInfo->tDelta_local.iMaxStrength;
		pen_pos = thisInfo->tDelta_local.tMaxCellPos;
		pen_sum_TData = algorithm_calc_3by3LocalDeltaSum(pen_pos);	// 3by3 sum
		
		if( (pen_touch_data > ucPen_th1 || pen_sum_TData > ucPen_th2)
#ifdef TILT_ON
			|| (gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM && g_RetVal==PARTIAL_PEN_COORD2 && (pen_touch_data > thisModeConf->Label.ucLocalPenRingDetectTH1 || pen_sum_TData > thisModeConf->Label.ucLocalPenRingDetectTH2) && mode == LOCAL_MODE) 
#endif
		)
		{		
			if(mode != LOCAL_SEARCH_MODE)
			{
				thisInfo->bLocal_sensing = YES;
				thisInfo->bTouchExpect_local = YES;
			}
			else
				thisInfo->bTouchExpect_local = NO;

			if (mode == LOCAL_SEARCH_MODE)
			{
				thisPenInfo->bSearch_Mode_Flag = 0;
				hal_Info_SetPenDectionEnable(YES);
//				_gT(_GPIO_TP_INTR);
				
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
				hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_PEN_BEACON);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
				
				PenDetectTH1_Offset = thisModeConf->Label.ucLocalPenDetectTH1_Offset;
				PenDetectTH2_Offset = thisModeConf->Label.ucLocalPenDetectTH2_Offset;
			}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)			
	#ifdef TILT_ON
			uint8_t row_start = pen_pos.r + local_rs;
			if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM && mode == LOCAL_MODE){
				if(thisInfo->tTiltInfo.sTilt_cnt>1){
					if(g_RetVal==PARTIAL_PEN_COORD1)
					{
						if(-3 < pen_pos.r + local_rs - ring_rs && pen_pos.r + local_rs - ring_rs < 3)
							row_start = ring_rs;
					}
					else if(g_RetVal==PARTIAL_PEN_COORD2)
					{
						if(-3 < pen_pos.r + local_rs - tip_rs && pen_pos.r + local_rs - tip_rs < 3)
							row_start = tip_rs;
					}
				}
				
				if(g_RetVal==PARTIAL_PEN_COORD2)ring_rs = pen_pos.r + local_rs;
				else if(g_RetVal==PARTIAL_PEN_COORD1)tip_rs = pen_pos.r + local_rs;
			}

			algorithm_baseline_calculate_local_mux_range(row_start, pen_pos.c,0);
	#else
			algorithm_baseline_calculate_local_mux_range(pen_pos.r+local_rs, pen_pos.c,0);
	#endif
#else
			algorithm_baseline_calculate_local_mux_range(pen_pos.r+local_rs, pen_pos.c,0);
#endif
#if ADAPTOR_NOISE_ALGO_EN		
			ucAdaptorNoise_CalDeltaRepeatSimbol = 0;
#endif
		}
		else
		{
			thisInfo->bLocal_sensing = NO;
			thisInfo->bTouchExpect_local = NO;
			PenDetectTH1_Offset = 0;
			PenDetectTH2_Offset = 0;
			thisPenInfo->bPen_button_cnt[0] = thisPenInfo->bPen_button_cnt[1] = 0;
#if ADAPTOR_NOISE_ALGO_EN
			if(thisModeConf->Noise.bPenPosSymbolRepeatCheck == 1 && gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisPenInfo->bAdaptorNoise) // MS PenLHB Noise By LocalFinger : 6 Symbol Repeat Check , hanch
			{
				ucAdaptorNoise_CalDeltaRepeatSimbol++;						
				if(ucAdaptorNoise_CalDeltaRepeatSimbol>6)
				{
					ucAdaptorNoise_CalDeltaRepeatSimbol = 0;
					thisPenInfo->bPosUpdateSkip = 1;
					thisPenInfo->bReportSkip = 1;
				}
			}
			else 
				ucAdaptorNoise_CalDeltaRepeatSimbol = 0;
#endif
		}
	}
	
#if (WACOM_HOVER_TEST_DELTA_CHANGE == YES)
	if(thisInfo->bTouchExpect_local && mode == LOCAL_HOVER_MODE)
	{
		algorithm_coord_wacom_hover_test(local_rs);
	}
#endif
	
#if (HighHoverDeltaIIR_En == YES)
	if(thisModeConf->SensingFilter.ucHighHoverDeltaIIR_Coef > 0 && mode == LOCAL_HOVER_MODE)
	{
		int MaxDeltaTH = thisModeConf->PenDisBaseSmoothSetVal.uc_global_smooth_delta_condition_hover;
		if(0 == thisModeConf->PenDisBaseSmoothSetVal.uc_global_smooth_delta_condition_hover)MaxDeltaTH = 100;
		if(thisInfo->tDelta_local.iMaxStrength < MaxDeltaTH && thisInfo->tPenInfo.usPen_Coord_Cnt > 10)
		{
			for(r = start_r; r < end_r; r++)for(c = start_c; c< end_c; c++)
			{
				delta2 = TmpPreDelta[r][c-start_c];
				delta = HAL_READ_LOCAL_DELTA_IMAGE(r,c);
				delta = (delta*(255-thisModeConf->SensingFilter.ucHighHoverDeltaIIR_Coef) + delta2*thisModeConf->SensingFilter.ucHighHoverDeltaIIR_Coef)/255;
				HAL_WRITE_LOCAL_DELTA_IMAGE(r,c,delta);
			}
		}
	}
#endif
	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	#if ADAPTOR_NOISE_ALGO_EN
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisPenInfo->bAdaptorNoise)
	{
		if((abs(thisInfo->tDelta_local.tMaxCellPos.r - thisPenInfo->cPreMaxR) > 1 || abs(thisInfo->tDelta_local.tMaxCellPos.c - thisPenInfo->cPreMaxC) > 1))
		{
			thisPenInfo->bPosUpdateSkip = 1;
			thisPenInfo->bReportSkip = 1;
		}
	}
	#endif			
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
	{
	#if ADAPTOR_NOISE_ALGO_EN
		if(thisPenInfo->bAdaptorNoise==1)
		{
			thisPenInfo->ucTmpForcePenContact_NUM = 10;
		}
		else
	#endif	
			thisPenInfo->ucTmpForcePenContact_NUM = thisModeConf->PenData.ucForcePenContact_NUM;
		
		if(g_RetVal != PARTIAL_PEN_COORD1)
		{	
			if(thisPenInfo->bMS_Contact2bit[0] == 1 && thisPenInfo->bMS_Contact2bit[1] == 1 &&(thisInfo->bLocal_sensing))
			{
				thisPenInfo->bPenContact = YES;
				thisInfo->ucContact_MS = thisPenInfo->ucTmpForcePenContact_NUM;
			}
			// slim pen contact loss issue when side button keeping drawing 
			else if(g_RetVal == PARTIAL_PEN_COORD2 && thisPenInfo->bPen_button[1] == 1 && thisPenInfo->bMS_Contact2bit[1] == 1 && thisInfo->bLocal_sensing)
			{
				thisPenInfo->bPenContact = YES;
			}
			// hanch
			else if(thisInfo->ucContact_MS > 0)
			{
				thisPenInfo->bPenContact = YES;
				thisInfo->ucContact_MS--;
			}
			else
			{
				thisInfo->ucContact_MS = 0;
				thisPenInfo->bPenContact = NO;
			}
			thisPenInfo->bPenContactConti = thisPenInfo->bPenContact;
		}
		else
			thisPenInfo->bPenContact = thisPenInfo->bPenContactConti;
	}
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)	
	#if AbnormalContactRemove_EN
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP)
	{
		if(thisModeConf->PenData.ucAbnormalContactRemovePressureTH1	> 0 && thisModeConf->PenData.ucAbnormalContactRemovePressureTH2 > 0)	
		{
			thisPenInfo->bEdgeAbnormalContact = 0;
			if(pen_pos.r == 0 || pen_pos.r == ROW_MAX-1 || pen_pos.c == 0 || pen_pos.c == COL_MAX-1)thisPenInfo->bEdgeAbnormalContact = 1;
			if( (thisPenInfo->bPenContact == YES) && thisPenInfo->bEdgeAbnormalContact == 1)
			{
				uint8_t ucDeltaSub1Th = thisModeConf->PenData.ucAbnormalContactRemoveDeltaTH1; //17;
				uint8_t ucDeltaSub2Th = thisModeConf->PenData.ucAbnormalContactRemoveDeltaTH2; //30;
			
				if(thisPenInfo->bPenOffChk == 1)
				{
					if(thisPenInfo->sPrevContactMaxDelta[0] - pen_touch_data > ucDeltaSub1Th)
						thisPenInfo->bPenContact = NO;
					else if(thisPenInfo->sPrevContactMaxDelta[1] - pen_touch_data > ucDeltaSub2Th)
						thisPenInfo->bPenContact = NO;
				}

				thisPenInfo->sPrevContactMaxDelta[1] = thisPenInfo->sPrevContactMaxDelta[0];
				thisPenInfo->sPrevContactMaxDelta[0] = pen_touch_data;
			}
			else
			{
				thisPenInfo->sPrevContactMaxDelta[1] = 0;
				thisPenInfo->sPrevContactMaxDelta[0] = 0;
			}
		}
	}
	#endif
#endif
	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
  #ifdef TILT_ON
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && mode == LOCAL_SEARCH_MODE)// && thisModeConf->PenTilt.bRingBaseTracking)
	#endif
	{
		if((thisModeConf->PenTilt.ucMS_RingMode == 0 && g_RetVal == PARTIAL_PEN_COORD3) || (thisModeConf->PenTilt.ucMS_RingMode == 1 && g_RetVal == PARTIAL_PEN_COORD1) || (thisModeConf->PenTilt.ucMS_RingMode == 2 && (g_RetVal == PARTIAL_PEN_COORD1||g_RetVal == PARTIAL_PEN_COORD3)))
			algorithm_baseline_tracking_continuous_local_ring();//algorithm_local_RingMS_delta_coordi(mode);
	}
  #endif
  #if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && mode != LOCAL_SEARCH_MODE)  //MS_Pressure_Last_Bit, hanch
  #endif
	{
		if(g_RetVal == PARTIAL_PEN_COORD3)
		{
			int pendata_min = 0;
			int pendata_max = 0;
			for( r=start_r; r<end_r; r++ )
			{
				for( c=start_c; c<end_c; c++ )
				{
					read_raw_data = HAL_READ_LOCAL_RING_RAW_IMAGE(r,c);
					delta = (signed)read_raw_data - (signed) HAL_READ_RING_BASELINE_IMAGE(r + sensingRowStart_Tilt , c);	
					delta>>=ptModuleModeConf->ucLocalOvrShift_Ring;
					
					if(delta < pendata_min)
					{
						pendata_min = delta;
					}
					if(delta > pendata_max)
					{
						pendata_max = delta;
					}								
				}
			}
			
			pendata_min = -pendata_min;
			if ((pendata_min > pendata_max) && (pendata_min > thisModeConf->Label.usLocalSeedBase_Ring))
			{
				data_store_bit[1][6] = 0;
			}
			else if ((pendata_min <= pendata_max) && (pendata_max > thisModeConf->Label.usLocalSeedBase_Ring))
			{
				data_store_bit[1][6] = 1;
			}
			else
				data_store_bit[1][6] = 2;			
		}
	}
#endif

	if(mode!=LOCAL_MODE && bContact && ucReleaseFrame < thisModeConf->Noise.ucHoverNoiseRejectFrm) ucReleaseFrame++;
	if(!thisInfo->bLocal_sensing || ucReleaseFrame == thisModeConf->Noise.ucHoverNoiseRejectFrm)
	{
		bContact = 0;
		ucReleaseFrame = 0;
	}

	return 0; 
}

#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)
bool_t algorithm_local_data_baseline_calculate_delta(ePartialSensing_t RetVal)
{
//	static int16_t hover_base = 0;
	int r, c,i;
	int delta;
	int start_r, end_r;
	int start_c, end_c;
	int local_rs;
//	int pen_touch_data = 0;
	uint16_t read_raw_data;
	uint8_t raw_idx = 0;
	uint8_t base_idx = 0;
	int store_row = (RetVal - PARTIAL_PEN_DATA1);

//	thisInfo->bBlockTracking = NO;

	local_rs = currentRowStart;

	start_r = 0, start_c = thisPenInfo->ucCurrentColumnStart;
	end_r = PEN_COORD_ROW_MAX, end_c = thisPenInfo->ucCurrentColumnEnd; //end_c = local_cs+8;

	int16_t pendata_min[8] = { 0, };
	int16_t pendata_max[8] = { 0, };
		
	if(thisPenInfo->bSearch_Mode_Flag == 0)
	{
		for (i = 0; i < 6; i++)
		{
			raw_idx = PEN_COORD_ROW_MAX*i;
			if(thisModeConf->BaseLine.bPen_2BASE && i > 0)
				base_idx = ROW_MAX;
			for (r = start_r; r < end_r; r++)
			{							
				for (c = start_c; c <= end_c; c++)
				{					
					read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+raw_idx, c);
					delta = (signed)read_raw_data - (signed) HAL_READ_LOCAL_BASELINE_IMAGE(r + local_rs + base_idx, c);

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
			
					if(delta < pendata_min[i])
					{
						pendata_min[i] = delta;
					}
					if(delta > pendata_max[i])
					{
						pendata_max[i] = delta;
					}
				}
			}
		}
		
		for (c = 0; c < 6; c++)
		{
			pendata_min[c] = -pendata_min[c];
			if ((pendata_min[c] > pendata_max[c]) && (pendata_min[c] > thisModeConf->PenData.ucPenDataLocalTHD))
			{
				data_store_bit[store_row][c] = 0;
			}
			else if ((pendata_min[c] <= pendata_max[c]) && (pendata_max[c] > thisModeConf->PenData.ucPenDataLocalTHD))
			{
				data_store_bit[store_row][c] = 1;
			}
			else
				data_store_bit[store_row][c] = 2;
			
//			pendata_min[c] = 0;
//			pendata_max[c] = 0;
		}
	
		switch (RetVal)
		{
			case PARTIAL_PEN_DATA2:
			{
				data_store_bit[store_row][5] = data_store_bit[store_row][6]; //MS_Pressure_Last_Bit, hanch
				thisPenInfo->us_pendata_pressure = 0;
				for (r = 0; r < 6; r++)
				{
					if (data_store_bit[store_row][r] == 1)
						thisPenInfo->us_pendata_pressure += (1 << (5 - r));
				}
				thisPenInfo->us_pendata_pressure = (thisPenInfo->us_pendata_pressure * 4095) / 63;
				
			}
				break;

			case PARTIAL_PEN_DATA3:
			{
				if(thisPenInfo->bSearch_Mode_Flag == 0)
					thisPenInfo->bReportEraser = 1;
				
				if(data_store_bit[store_row][0] == 0 && data_store_bit[store_row][1] == 1)
					thisPenInfo->bPen_button[1] = 1;
				else
					thisPenInfo->bPen_button[1] = 0;
				
				if(data_store_bit[store_row][0] == 1 && data_store_bit[store_row][1] == 0)
					thisPenInfo->bPen_button[0] = 1;
				else
					thisPenInfo->bPen_button[0] = 0;
				
				//For Win10 Invert button test, high hover side button reject, hanch, 200811
				if(thisPenInfo->bPen_button[1] == 1 && pendata_min[0] + pendata_max[1] < thisModeConf->PenData.usPenDataHighHoverButtonRejectTHD)
				{
					thisPenInfo->bPen_button[1] = 0;
				}
			}
				break;

			default:
				break;
		}
	}
	
	memset(pendata_min,0,sizeof(pendata_min));
	memset(pendata_max,0,sizeof(pendata_max));

#if AbnormalContactRemove_EN	
	if(thisPenInfo->bAdaptorNoise)
	{
		thisPenInfo->bPen_button[0] = thisPenInfo->bPre_pen_button[0];
		thisPenInfo->bPen_button[1] = thisPenInfo->bPre_pen_button[1];
		thisPenInfo->us_pendata_pressure = thisPenInfo->us_pre_pendata_pressure;
	}
#endif	
	thisPenInfo->us_pre_pendata_pressure = thisPenInfo->us_pendata_pressure;
	thisPenInfo->bPre_pen_button[0] = thisPenInfo->bPen_button[0];
	thisPenInfo->bPre_pen_button[1] = thisPenInfo->bPen_button[1];

	return 0; 
}
#endif /* (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN) */

//#define WGP_PEN_DATA_LOCAL_THD			(60)
//#define WGP_PEN_DATA_HOVER_THD			(80)
#define WGP_PEN_DATA_1st_SYMBOL			(0)
#define WGP_PEN_DATA_2nd_SYMBOL			(1)
#define WGP_PEN_SYMBOL_IDX_NUM			(2)
#define WGP_PEN_SYMBOL_NUM_1LHB			(6)
#if USED_PEN_ID_GET_FUNCTION
/* 
 * Get Hash Contact status
 */
#define GETHASH_1stCTSYB_CONTACT_0_BIT		(0)
#define GETHASH_1stCTSYB_CONTACT_1_BIT		(1)
#define GETHASH_1stCTSYB_6BITIDHASH_0_BIT	(2)
#define GETHASH_1stCTSYB_6BITIDHASH_1_BIT	(3)
#define GETHASH_1stCTSYB_6BITIDHASH_2_BIT	(4)
#define GETHASH_1stCTSYB_6BITIDHASH_3_BIT	(5)
#define GETHASH_1stCTSYB_6BITIDHASH_4_BIT	(6)
#define GETHASH_1stCTSYB_6BITIDHASH_5_BIT	(7)
#define GETHASH_1stCTSYB_BT1_BIT			(8)
#define GETHASH_1stCTSYB_BT2_BIT			(9)
#define GETHASH_1stCTSYB_2BITCHECKSUM_0_BIT	(10)
#define GETHASH_1stCTSYB_2BITCHECKSUM_1_BIT	(11)

#define GETHASH_2ndCTSYB_SW1_BIT			(0)
#define GETHASH_2ndCTSYB_SW2_BIT			(1)
#define GETHASH_2ndCTSYB_PRESSURE_0_BIT		(2)
#define GETHASH_2ndCTSYB_PRESSURE_1_BIT		(3)
#define GETHASH_2ndCTSYB_PRESSURE_2_BIT		(4)
#define GETHASH_2ndCTSYB_PRESSURE_3_BIT		(5)
#define GETHASH_2ndCTSYB_PRESSURE_4_BIT		(6)
#define GETHASH_2ndCTSYB_PRESSURE_5_BIT		(7)
#define GETHASH_2ndCTSYB_PRESSURE_6_BIT		(8)
#define GETHASH_2ndCTSYB_PRESSURE_7_BIT		(9)
#define GETHASH_2ndCTSYB_2BITCHECKSUM_0_BIT	(10)
#define GETHASH_2ndCTSYB_2BITCHECKSUM_1_BIT	(11)
/* 
 * Get Hash Hover status
 */
#define GETHASH_1stHVSYB_HOVER_BIT			(0)
#define GETHASH_1stHVSYB_6BITIDHASH_0_BIT	(1)
#define GETHASH_1stHVSYB_6BITIDHASH_1_BIT	(2)
#define GETHASH_1stHVSYB_6BITIDHASH_2_BIT	(3)
#define GETHASH_1stHVSYB_BT1_BIT			(4)
#define GETHASH_1stHVSYB_1BITCHECKSUM_BIT	(5)

#define GETHASH_2ndHVSYB_HOVER_0_BIT		(0)
#define GETHASH_2ndHVSYB_6BITIDHASH_3_BIT	(1)
#define GETHASH_2ndHVSYB_6BITIDHASH_4_BIT	(2)
#define GETHASH_2ndHVSYB_6BITIDHASH_5_BIT	(3)
#define GETHASH_2ndHVSYB_BT2_BIT			(4)
#define GETHASH_2ndHVSYB_1BITCHECKSUM_BIT	(5)
/* 
 * Get ID Contact status
 */
#define PEN_ID_BUFFER_LAST_IDX				(4)

#define GETID_1stCTSYB_CONTACT_0_BIT		(0)
#define GETID_1stCTSYB_CONTACT_1_BIT		(1)
#define GETID_1stCTSYB_17BITIDBLOCKS_0_BIT	(2)
#define GETID_1stCTSYB_17BITIDBLOCKS_1_BIT	(3)
#define GETID_1stCTSYB_17BITIDBLOCKS_2_BIT	(4)
#define GETID_1stCTSYB_17BITIDBLOCKS_3_BIT	(5)
#define GETID_1stCTSYB_17BITIDBLOCKS_4_BIT	(6)
#define GETID_1stCTSYB_17BITIDBLOCKS_5_BIT	(7)
#define GETID_1stCTSYB_17BITIDBLOCKS_6_BIT	(8)
#define GETID_1stCTSYB_17BITIDBLOCKS_7_BIT	(9)
#define GETID_1stCTSYB_2BITCHECKSUM_0_BIT	(10)
#define GETID_1stCTSYB_2BITCHECKSUM_1_BIT	(11)

#define GETID_2ndCTSYB_0_BIT				(0)
#define GETID_2ndCTSYB_17BITIDBLOCKS_8_BIT	(1)
#define GETID_2ndCTSYB_17BITIDBLOCKS_9_BIT	(2)
#define GETID_2ndCTSYB_17BITIDBLOCKS_10_BIT	(3)
#define GETID_2ndCTSYB_17BITIDBLOCKS_11_BIT	(4)
#define GETID_2ndCTSYB_17BITIDBLOCKS_12_BIT	(5)
#define GETID_2ndCTSYB_17BITIDBLOCKS_13_BIT	(6)
#define GETID_2ndCTSYB_17BITIDBLOCKS_14_BIT	(7)
#define GETID_2ndCTSYB_17BITIDBLOCKS_15_BIT	(8)
#define GETID_2ndCTSYB_17BITIDBLOCKS_16_BIT	(9)
#define GETID_2ndCTSYB_2BITCHECKSUM_0_BIT	(10)
#define GETID_2ndCTSYB_2BITCHECKSUM_1_BIT	(11)
/* 
 * Get ID Hover status
 */
#define GETID_1stHVSYB_HOVER_0_BIT			(0)
#define GETID_1stHVSYB_HOVER_1_BIT			(1)
#define GETID_1stHVSYB_17BITIDBLOCKS_0_BIT	(2)
#define GETID_1stHVSYB_17BITIDBLOCKS_1_BIT	(3)
#define GETID_1stHVSYB_17BITIDBLOCKS_2_BIT	(4)
#define GETID_1stHVSYB_17BITIDBLOCKS_3_BIT	(5)
#define GETID_1stHVSYB_17BITIDBLOCKS_4_BIT	(6)
#define GETID_1stHVSYB_17BITIDBLOCKS_5_BIT	(7)
#define GETID_1stHVSYB_17BITIDBLOCKS_6_BIT	(8)
#define GETID_1stHVSYB_17BITIDBLOCKS_7_BIT	(9)
#define GETID_1stHVSYB_2BITCHECKSUM_0_BIT	(10)
#define GETID_1stHVSYB_2BITCHECKSUM_1_BIT	(11)

#define GETID_2ndHVSYB_0_BIT				(0)
#define GETID_2ndHVSYB_17BITIDBLOCKS_8_BIT	(1)
#define GETID_2ndHVSYB_17BITIDBLOCKS_9_BIT	(2)
#define GETID_2ndHVSYB_17BITIDBLOCKS_10_BIT	(3)
#define GETID_2ndHVSYB_17BITIDBLOCKS_11_BIT	(4)
#define GETID_2ndHVSYB_17BITIDBLOCKS_12_BIT	(5)
#define GETID_2ndHVSYB_17BITIDBLOCKS_13_BIT	(6)
#define GETID_2ndHVSYB_17BITIDBLOCKS_14_BIT	(7)
#define GETID_2ndHVSYB_17BITIDBLOCKS_15_BIT	(8)
#define GETID_2ndHVSYB_17BITIDBLOCKS_16_BIT	(9)
#define GETID_2ndHVSYB_2BITCHECKSUM_0_BIT	(10)
#define GETID_2ndHVSYB_2BITCHECKSUM_1_BIT	(11)
#endif /* USED_PEN_ID_GET_FUNCTION */

/* 
 * Get ABS Contact status
 */
#define GETABS_1stCTSYB_CONTACT_0_BIT		(0)
#define GETABS_1stCTSYB_CONTACT_1_BIT		(1)
#define GETABS_1stCTSYB_PRESSURE_0_BIT		(2)
#define GETABS_1stCTSYB_PRESSURE_1_BIT		(3)
#define GETABS_1stCTSYB_PRESSURE_2_BIT		(4)
#define GETABS_1stCTSYB_PRESSURE_3_BIT		(5)
#define GETABS_1stCTSYB_PRESSURE_4_BIT		(6)
#define GETABS_1stCTSYB_PRESSURE_5_BIT		(7)
#define GETABS_1stCTSYB_PRESSURE_6_BIT		(8)
#define GETABS_1stCTSYB_PRESSURE_7_BIT		(9)
#define GETABS_1stCTSYB_2BITCHECKSUM_0_BIT	(10)
#define GETABS_1stCTSYB_2BITCHECKSUM_1_BIT	(11)

#define GETABS_2ndCTSYB_SW1_BIT				(0)
#define GETABS_2ndCTSYB_SW2_BIT				(1)
#define GETABS_2ndCTSYB_PRESSURE_0_BIT		(2)
#define GETABS_2ndCTSYB_PRESSURE_1_BIT		(3)
#define GETABS_2ndCTSYB_PRESSURE_2_BIT		(4)
#define GETABS_2ndCTSYB_PRESSURE_3_BIT		(5)
#define GETABS_2ndCTSYB_PRESSURE_4_BIT		(6)
#define GETABS_2ndCTSYB_PRESSURE_5_BIT		(7)
#define GETABS_2ndCTSYB_PRESSURE_6_BIT		(8)
#define GETABS_2ndCTSYB_PRESSURE_7_BIT		(9)
#define GETABS_2ndCTSYB_0_BIT_2BITCHECKSUM	(10)
#define GETABS_2ndCTSYB_1_BIT_2BITCHECKSUM	(11)
/* 
 * Get ABS Hover status
 */
#define GETABS_1stHVSYB_HOVER_BIT			(0)
#define GETABS_1stHVSYB_6BITIDHASH_0_BIT	(1)
#define GETABS_1stHVSYB_6BITIDHASH_1_BIT	(2)
#define GETABS_1stHVSYB_6BITIDHASH_2_BIT	(3)
#define GETABS_1stHVSYB_SW1_BIT				(4)
#define GETABS_1stHVSYB_1BITCHECKSUM_BIT	(5)

#define GETABS_2ndHVSYB_HOVER_0_BIT			(0)
#define GETABS_2ndHVSYB_6BITIDHASH_3_BIT	(1)
#define GETABS_2ndHVSYB_6BITIDHASH_4_BIT	(2)
#define GETABS_2ndHVSYB_6BITIDHASH_5_BIT	(3)
#define GETABS_2ndHVSYB_SW2_BIT				(4)
#define GETABS_2ndHVSYB_1BITCHECKSUM_BIT	(5)

int8_t cHoverSymbolData[WGP_PEN_SYMBOL_IDX_NUM][WGP_PEN_SYMBOL_NUM_1LHB];
int8_t cContactSymbolData[WGP_PEN_SYMBOL_IDX_NUM][WGP_PEN_SYMBOL_NUM_1LHB<<1];
static uint16_t ulPenPressure_RogarithmicCVTTable[256] = {
	0,1,2,4,6,8,11,14,17,20,24,28,32,36,40,45,50,55,60,65,
	70,76,82,88,94,100,106,113,120,127,134,141,148,155,163,171,179,187,195,203,
	211,220,229,238,247,256,265,274,283,292,302,312,322,332,342,352,362,372,383,394,
	405,416,427,438,449,460,471,482,494,506,518,530,542,554,566,578,590,602,615,628,
	641,654,667,680,693,706,719,732,746,760,774,788,802,816,830,844,858,872,886,901,
	916,931,946,961,976,991,1006,1021,1036,1051,1066,1082,1098,1114,1130,1146,1162,1178,1194,1210,
	1226,1242,1258,1275,1292,1309,1326,1343,1360,1377,1394,1411,1428,1445,1462,1480,1498,1516,1534,1552,
	1570,1588,1606,1624,1642,1660,1678,1696,1715,1734,1753,1772,1791,1810,1829,1848,1867,1886,1905,1924,
	1943,1962,1982,2002,2022,2042,2061,2081,2101,2121,2141,2161,2181,2201,2221,2241,2262,2283,2304,2325,
	2346,2367,2388,2409,2430,2451,2472,2493,2514,2535,2557,2579,2601,2623,2645,2667,2689,2711,2733,2755,
	2777,2799,2821,2843,2865,2888,2911,2934,2957,2980,3003,3026,3049,3072,3095,3118,3141,3164,3187,3210,
	3233,3257,3281,3305,3329,3353,3377,3401,3425,3449,3473,3497,3521,3545,3569,3593,3617,3642,3667,3692,
	3717,3742,3767,3792,3817,3842,3867,3892,3917,3942,3967,3992,4017,4043,4069,4095

//	0,1,2,5,8,10,12,14,16,19,21,23,26,28,30,33,35,38,41,43,46,49,51,54,57,60,63,66,69,72,76,79,82,
//	85,89,92,96,99,103,107,111,115,118,122,126,131,135,139,143,148,152,157,161,166,171,176,181,186,191,196,201,207,212,218,223,229,
//	235,241,247,253,259,265,272,278,285,291,298,305,312,319,326,334,341,348,356,364,372,380,388,396,404,412,421,430,438,447,456,465,474,
//	484,493,503,513,522,532,542,553,563,574,584,595,606,617,628,639,651,662,674,686,698,710,722,735,747,760,773,786,799,813,826,840,854,
//	868,882,896,910,925,940,955,970,985,1000,1016,1032,1048,1064,1080,1096,1113,1130,1147,1164,1181,1199,1216,1234,1252,1270,1289,1307,1326,1345,1364,1383,1403,
//	1422,1442,1462,1482,1503,1524,1544,1565,1587,1608,1630,1651,1674,1696,1718,1741,1764,1787,1810,1833,1857,1881,1905,1929,1954,1979,2004,2029,2054,2080,2105,2132,2158,
//	2184,2211,2238,2265,2292,2320,2348,2376,2404,2433,2462,2491,2520,2549,2579,2609,2639,2670,2700,2731,2762,2794,2825,2857,2889,2922,2954,2987,3020,3054,3087,3121,3155,
//	3190,3224,3259,3294,3330,3366,3402,3438,3474,3511,3548,3585,3623,3661,3699,3737,3776,3815,3854,3893,3933,3973,4013,4054,4095,

//	0,1,1,1,1,1,1,1,1,1,1,2,2,3,3,4,4,5,5,6,7,7,8,9,10,11,12,13,14,16,17,18,20,
//	21,22,24,25,27,29,31,33,35,37,39,41,43,46,48,51,53,56,59,62,65,68,71,74,78,81,84,88,92,96,99,103,108,
//	112,116,120,125,130,134,139,144,149,154,160,165,171,176,182,188,194,200,206,212,219,226,232,239,246,253,261,268,275,283,291,299,307,
//	315,324,332,341,349,358,367,377,386,396,405,415,425,435,446,456,467,477,488,500,511,522,534,546,558,570,582,594,607,620,633,646,659,
//	673,686,700,714,729,743,758,772,787,803,818,834,849,865,881,898,914,931,948,965,982,1000,1018,1036,1054,1072,1091,1109,1128,1148,1167,1187,1207,
//	1227,1247,1267,1288,1309,1330,1352,1373,1395,1417,1440,1462,1485,1508,1531,1555,1578,1602,1627,1651,1676,1701,1726,1751,1777,1803,1829,1855,1882,1909,1936,1963,1991,
//	2019,2047,2076,2104,2133,2162,2192,2222,2252,2282,2312,2343,2374,2406,2437,2469,2501,2534,2567,2600,2633,2666,2700,2734,2769,2803,2838,2874,2909,2945,2981,3018,3054,
//	3092,3129,3166,3204,3243,3281,3320,3359,3398,3438,3478,3519,3559,3600,3642,3683,3725,3767,3810,3853,3896,3939,3983,4027,4095,

//	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,3,3,3,4,4,5,5,6,6,7,
//	7,8,8,9,10,11,12,13,14,15,16,17,19,20,21,23,24,26,28,29,31,33,35,37,39,41,43,46,48,51,53,56,58,
//	58,61,64,67,70,73,77,80,84,87,91,95,98,102,107,111,115,119,124,129,133,138,143,148,154,159,165,170,176,182,188,194,200,
//	213,220,227,234,241,248,256,263,271,279,287,295,304,312,321,330,339,348,357,367,376,386,396,406,417,427,438,449,460,472,483,495,507,
//	519,531,544,556,569,582,595,609,623,637,651,665,680,694,709,725,740,756,772,788,804,821,837,854,872,889,907,925,943,962,980,999,1019,
//	1038,1058,1078,1098,1119,1140,1161,1182,1204,1225,1248,1270,1293,1316,1339,1362,1386,1410,1435,1459,1484,1510,1535,1561,1587,1614,1641,1668,1695,1723,1751,1779,1808,
//	1837,1866,1896,1925,1956,1986,2017,2048,2080,2112,2144,2177,2210,2243,2277,2311,2345,2379,2415,2450,2486,2522,2558,2595,2632,2670,2708,2746,2785,2824,2863,2903,2943,
//	2984,3025,3066,3108,3150,3193,3236,3279,3323,3367,3412,3457,3502,3548,3594,3641,3688,3735,3783,3832,3880,3930,3979,4029,4095,

};

void algorithm_local_prePressureBit_clear()
{
	thisPenInfo->sPPressureOriBit[1] = 0;
	thisPenInfo->sPPressureOriBit[0] = 0;
}

void algorithm_local_hoverContact_classify(int16_t sPressureDataBit)
{
	uint8_t hover_flag = 0;
	uint8_t cOneFrameSubTh = thisModeConf->PenData.ucAbnormalContactRemovePressureTH1; //35;
	uint16_t sTwoFrameSubTh = thisModeConf->PenData.ucAbnormalContactRemovePressureTH2; //70;
	uint8_t prev_OffChk = 0;
	
	if((thisPenInfo->bPenContact == YES) && (thisPenInfo->bPenOffChk == YES))
		prev_OffChk = 1;
	
	thisPenInfo->bPenOffChk = NO;
	if(sPressureDataBit == 0)
	{
		thisPenInfo->bPenContact = NO;
		thisPenInfo->us_pendata_pressure = 1;
		thisPenInfo->us_pre_pendata_pressure = 1;
	}
	else if(sPressureDataBit != -1)
	{
		if((thisPenInfo->sPPressureOriBit[0] - sPressureDataBit > cOneFrameSubTh) && (thisPenInfo->sPPressureOriBit[0] != -1))
		{
			if(thisPenInfo->sPPressureOriBit[0] - sPressureDataBit > sTwoFrameSubTh)
				hover_flag = 2;
			else
				hover_flag = 1;
		}
		else if((thisPenInfo->sPPressureOriBit[1] - sPressureDataBit > sTwoFrameSubTh) && (thisPenInfo->sPPressureOriBit[1] != -1))
			hover_flag = 1;
	}
	
	if(hover_flag == 1)
	{
		thisPenInfo->bPenOffChk = YES;
		if(prev_OffChk == 1)
			hover_flag = 2;
	}
	
	if(hover_flag == 2)
	{
		thisPenInfo->bPenContact = NO;
		thisPenInfo->us_pendata_pressure = 1;
		thisPenInfo->us_pre_pendata_pressure = 1;
	}
	
	thisPenInfo->sPPressureOriBit[1] = thisPenInfo->sPPressureOriBit[0];
	thisPenInfo->sPPressureOriBit[0] = sPressureDataBit;
}

bool_t pre_contact_button[2] = {0,};
bool_t pre_hover_button[2] = {0,};
bool_t current_contact_button[2] = {0,};
bool_t current_hover_button[2] = {0,};
int32_t Pre_ID_MAX_Value = 0;

#if USED_PEN_ID_GET_FUNCTION
uint16_t pre_GetIDval = 0;
uint64_t uGetIDbuff[6] = {0,};
uint8_t Hashdone_flag = 0;
uint8_t uContactGetHASHval = 0;
uint8_t hash_buff[3] = {0,};
#endif /* USED_PEN_ID_GET_FUNCTION */

int16_t g_sPenData_Max[2][WGP_PEN_SYMBOL_NUM_1LHB<<1] = {0,};
//int16_t g_sPenData_1st_Max[WGP_PEN_SYMBOL_NUM_1LHB*2] = {0,};
//int16_t g_sPenData_2nd_Max[WGP_PEN_SYMBOL_NUM_1LHB*2] = {0,};

void algorithm_WGP_Pen_Data_Init(void)
{
	int r,c;

	thisPenInfo->us_pendata_pressure = 1;
	thisPenInfo->bPen_button[0] = 0;
	thisPenInfo->bPen_button[1] = 0;
	pre_contact_button[0] = 0;
	pre_contact_button[1] = 0;
	pre_hover_button[0] = 0;
	pre_hover_button[1] = 0;
	current_contact_button[0] = 0;
	current_contact_button[1] = 0;
	current_hover_button[0] = 0;
	current_hover_button[1] = 0;
	thisPenInfo->bPenContact = NO;
	thisPenInfo->bPrevPenContact = NO;
	for(r=0;r<2;r++)
	{
		for(c=0;c<6;c++)
		{
			cHoverSymbolData[r][c] = 0;
		}
	}

#if USED_PEN_ID_GET_FUNCTION
//	thisPenInfo->bHoverHashVal = 0;
	thisPenInfo->ucCurPenHashVal = 0;
	thisPenInfo->bHashnIDCompareDone = NO;
	thisPenInfo->bGetPenIDComplete = NO;
	thisPenInfo->bGetHashIDComplete = NO;
#endif /* USED_PEN_ID_GET_FUNCTION */
	memset((void *)&g_sPenData_Max[0][0], INT16_MIN, sizeof(g_sPenData_Max));
//	memset((void*)&g_sPenData_2nd_Max[0], INT16_MIN, sizeof(int16_t) * WGP_PEN_SYMBOL_NUM_1LHB*2);
//	memset((void*)&g_sPenData_1st_Max[0], INT16_MIN, sizeof(int16_t) * WGP_PEN_SYMBOL_NUM_1LHB*2);
	thisPenInfo->bPen_button_cnt[0] = 0;
	thisPenInfo->bPen_button_cnt[1] = 0;
	
	Pre_ID_MAX_Value = 0;
}

int16_t sPenData_Max[WGP_PEN_SYMBOL_NUM_1LHB];
static void algorithm_WGP_PenData_24bitStructure_SetSymbolBit(uint32_t ulPartNumber, uint32_t ulStartSymbolOffset, int mode)
{
	int32_t s;
#if	(DataAdaptiveContactTh_EN == YES)
	int adaptive_contact_th = thisModeConf->PenData.ucPenDataLocalTHD;

	if(thisModeConf->PenData.ucAdaptive_contact_th)
	{
		int max_s = 0;
		int	min_s = 0xffff;

		for(s = 0; s < WGP_PEN_SYMBOL_NUM_1LHB; s++)
		{
			if(max_s < sPenData_Max[s])
				max_s = sPenData_Max[s];

			if(min_s > sPenData_Max[s])
				min_s = sPenData_Max[s];
		}
		adaptive_contact_th = (max_s - min_s)/thisModeConf->PenData.ucAdaptive_contact_th;//(max_s - min_s)>>1;
	}
#endif

	for(s = 0; s < WGP_PEN_SYMBOL_NUM_1LHB; s++)
	{
		int choose_th;
#if	(DataAdaptiveContactTh_EN == YES)
		if(thisModeConf->PenData.ucAdaptive_contact_th)
		{
			if(s+ulStartSymbolOffset < 2)
				choose_th = adaptive_contact_th;
			else
				choose_th = thisModeConf->PenData.ucPenDataLocalTHD;
		}
		else
#endif
			choose_th = thisModeConf->PenData.ucPenDataLocalTHD;

		if(sPenData_Max[s] > choose_th)//thisModeConf->PenData.ucPenDataLocalTHD)
		{
			cContactSymbolData[ulPartNumber][s + ulStartSymbolOffset] = 0;
		}
		else
		{
			cContactSymbolData[ulPartNumber][s + ulStartSymbolOffset] = 1;
		}

		if((s+ulStartSymbolOffset==8||s+ulStartSymbolOffset==9) && g_sPenData_Max[ulPartNumber][s+ulStartSymbolOffset] > 0 && mode == LOCAL_HOVER_MODE)
		{
			g_sPenData_Max[ulPartNumber][s+ulStartSymbolOffset] = (thisModeConf->PenData.ucPenDataHighHoverButtonIIRcoef*g_sPenData_Max[ulPartNumber][s+ulStartSymbolOffset]+(255-thisModeConf->PenData.ucPenDataHighHoverButtonIIRcoef)*sPenData_Max[s])/255;
		}
		else
		{
			g_sPenData_Max[ulPartNumber][s+ulStartSymbolOffset] = sPenData_Max[s];
		}

		if((s + ulStartSymbolOffset) % 2 == 1)
		{
			if(thisModeConf->PenData.sPenDataHoverButtonTHD > 0 && 3 <= s + ulStartSymbolOffset && s + ulStartSymbolOffset <= 9)
			{
				choose_th = thisModeConf->PenData.sPenDataHoverButtonTHD;
			}
			else
			{
				choose_th = thisModeConf->PenData.ucPenDataHoverTHD;
			}

			if(g_sPenData_Max[ulPartNumber][s+ulStartSymbolOffset-1] + g_sPenData_Max[ulPartNumber][s+ulStartSymbolOffset] > choose_th)
			{
				cHoverSymbolData[ulPartNumber][(s + ulStartSymbolOffset)>>1] = 0;
			}
			else
			{
				cHoverSymbolData[ulPartNumber][(s + ulStartSymbolOffset)>>1] = 1;
			}
		}
	}
}

#if USED_PEN_ID_GET_FUNCTION
static bool_t algorithm_WGP_PenData_24bitStructure_HashIDParsing(bool_t bIsHover, uint32_t ulPartNumber)
{
	static bool_t bIsHoverGetHashID_1stSymbol = NO;
	bool_t bIsReg = NO;

	if(thisPenInfo->bHashnIDCompareDone == NO)
	{
		if(bIsHover)
		{
			if(ulPartNumber == WGP_PEN_DATA_1st_SYMBOL)
			{
				uContactGetHASHval = (uint8_t)(vBIT2((uint32_t)cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETHASH_1stHVSYB_6BITIDHASH_2_BIT]) |
												vBIT1((uint32_t)cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETHASH_1stHVSYB_6BITIDHASH_1_BIT]) |
												vBIT0((uint32_t)cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETHASH_1stHVSYB_6BITIDHASH_0_BIT]));
				bIsHoverGetHashID_1stSymbol = YES;
			}
			else
			{
				if(bIsHoverGetHashID_1stSymbol)
				{
					uContactGetHASHval = (uint8_t)(vBIT5((uint32_t)cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETHASH_2ndHVSYB_6BITIDHASH_5_BIT]) |
													vBIT4((uint32_t)cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETHASH_2ndHVSYB_6BITIDHASH_4_BIT]) |
													vBIT3((uint32_t)cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETHASH_2ndHVSYB_6BITIDHASH_3_BIT]) |
													uContactGetHASHval);
					thisPenInfo->ucCurPenHashVal = uContactGetHASHval;
					thisPenInfo->bGetHashIDComplete = YES;
					bIsHoverGetHashID_1stSymbol = NO;
				}
			}
		}
		else
		{
			uContactGetHASHval = (uint8_t)(vBIT5((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETHASH_1stCTSYB_6BITIDHASH_5_BIT]) |
											vBIT4((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETHASH_1stCTSYB_6BITIDHASH_4_BIT]) |
											vBIT3((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETHASH_1stCTSYB_6BITIDHASH_3_BIT]) |
											vBIT2((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETHASH_1stCTSYB_6BITIDHASH_2_BIT]) |
											vBIT1((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETHASH_1stCTSYB_6BITIDHASH_1_BIT]) |
											vBIT0((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETHASH_1stCTSYB_6BITIDHASH_0_BIT]));
			thisPenInfo->ucCurPenHashVal = uContactGetHASHval;
			bIsHoverGetHashID_1stSymbol = NO;
			thisPenInfo->bGetHashIDComplete = YES;
		}
	}

	return bIsReg;
}

static bool_t algorithm_WGP_PenData_24bitStructure_PenIDParsing(bool_t bIsHover, uint32_t ulPartNumber, uint32_t eBecaonType)
{
	bool_t bIsReg = NO;
	uint16_t usPenIDValue;
	uint32_t ulIDBuffIdx;

	ulIDBuffIdx = ((1-ulPartNumber) + ((eBecaonType - PWM_WGP_PEN_GETID_1st_BEACON)<<1));
//	_gT(_GPIO_TP_INTR);
	if(ulPartNumber == WGP_PEN_DATA_1st_SYMBOL)
	{
		usPenIDValue = (uint16_t)(vBIT7((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETID_1stCTSYB_17BITIDBLOCKS_7_BIT]) |
								   vBIT6((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETID_1stCTSYB_17BITIDBLOCKS_6_BIT]) |
								   vBIT5((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETID_1stCTSYB_17BITIDBLOCKS_5_BIT]) |
								   vBIT4((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETID_1stCTSYB_17BITIDBLOCKS_4_BIT]) |
								   vBIT3((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETID_1stCTSYB_17BITIDBLOCKS_3_BIT]) |
								   vBIT2((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETID_1stCTSYB_17BITIDBLOCKS_2_BIT]) |
								   vBIT1((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETID_1stCTSYB_17BITIDBLOCKS_1_BIT]) |
								   vBIT0((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETID_1stCTSYB_17BITIDBLOCKS_0_BIT]));
	}
	else
	{
		usPenIDValue = (uint16_t)(vBIT8((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETID_2ndCTSYB_17BITIDBLOCKS_16_BIT]) |
								   vBIT7((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETID_2ndCTSYB_17BITIDBLOCKS_15_BIT]) |
								   vBIT6((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETID_2ndCTSYB_17BITIDBLOCKS_14_BIT]) |
								   vBIT5((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETID_2ndCTSYB_17BITIDBLOCKS_13_BIT]) |
								   vBIT4((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETID_2ndCTSYB_17BITIDBLOCKS_12_BIT]) |
								   vBIT3((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETID_2ndCTSYB_17BITIDBLOCKS_11_BIT]) |
								   vBIT2((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETID_2ndCTSYB_17BITIDBLOCKS_10_BIT]) |
								   vBIT1((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETID_2ndCTSYB_17BITIDBLOCKS_9_BIT]) |
								   vBIT0((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETID_2ndCTSYB_17BITIDBLOCKS_8_BIT]));
	}

	uGetIDbuff[ulIDBuffIdx] = usPenIDValue;

	if(ulIDBuffIdx == PEN_ID_BUFFER_LAST_IDX)
	{
		thisPenInfo->bPenIDVal = (((uGetIDbuff[0] & 0x1FF) << 8) + (uGetIDbuff[1] & 0xFF) & 0x1FFFF) |
									   ((((uGetIDbuff[2] & 0x1FF) << 8) + (uGetIDbuff[3] & 0xFF) & 0x1FFFF) << 17) |
									   ((((uGetIDbuff[4] & 0x1FF) << 8) + (uGetIDbuff[5] & 0xFF) & 0x1FFFF) << 34);
		thisPenInfo->bGetPenIDComplete = YES;
	}

	return bIsReg;
}
#endif /* USED_PEN_ID_GET_FUNCTION */
static void algorithm_WGP_PenData_24bitStructure_PenPressureParsing(uint32_t ulPartNumber)
{
	uint16_t sCompressedPressureData = 0;

	thisPenInfo->us_pre2_pendata_pressure = thisPenInfo->us_pre_pendata_pressure;
	thisPenInfo->us_pre_pendata_pressure = thisPenInfo->us_pendata_pressure;	
	
	sCompressedPressureData = (uint16_t)(vBIT7((uint32_t)cContactSymbolData[ulPartNumber][GETABS_1stCTSYB_PRESSURE_7_BIT]) |
										 vBIT6((uint32_t)cContactSymbolData[ulPartNumber][GETABS_1stCTSYB_PRESSURE_6_BIT]) |
										 vBIT5((uint32_t)cContactSymbolData[ulPartNumber][GETABS_1stCTSYB_PRESSURE_5_BIT]) |
										 vBIT4((uint32_t)cContactSymbolData[ulPartNumber][GETABS_1stCTSYB_PRESSURE_4_BIT]) |
										 vBIT3((uint32_t)cContactSymbolData[ulPartNumber][GETABS_1stCTSYB_PRESSURE_3_BIT]) |
										 vBIT2((uint32_t)cContactSymbolData[ulPartNumber][GETABS_1stCTSYB_PRESSURE_2_BIT]) |
										 vBIT1((uint32_t)cContactSymbolData[ulPartNumber][GETABS_1stCTSYB_PRESSURE_1_BIT]) |
										 vBIT0((uint32_t)cContactSymbolData[ulPartNumber][GETABS_1stCTSYB_PRESSURE_0_BIT]));

	thisPenInfo->us_pendata_pressure = ulPenPressure_RogarithmicCVTTable[sCompressedPressureData];
}

static bool_t algorithm_WGP_PenData_24bitStructure_PenButtonParsing(bool_t bIsHover, uint32_t ulPartNumber)
{
	bool_t bIsReg = NO;

	if(bIsHover)
	{
		if(ulPartNumber == WGP_PEN_DATA_1st_SYMBOL)
		{
			/*
			 * SW1 Button
			 */
			current_hover_button[0] = cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stHVSYB_SW1_BIT];
		}
		else
		{
			/*
			 * SW2 Button
			 */
			current_hover_button[1] = cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndHVSYB_SW2_BIT];
		}
	}
	else
	{
		/*
		 * SW1 Button
		 */
		current_contact_button[0] = cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_SW1_BIT];
		/*
		 * SW2 Button
		 */
		current_contact_button[1] = cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_SW2_BIT];
	}

	return bIsReg;
}

static void algorithm_WGP_PenData_24bitStructure_PenButton_RejectCheck(uint32_t ulPartNumber, bool_t bIsButtonProcess)
{
	int32_t ID_MAX_Value = 0;
	bool_t hover_button_check_bit = 0;
	uint8_t ucPenDataHighHoverButtonReliableCnt;

	if(ulPartNumber == WGP_PEN_DATA_1st_SYMBOL)
	{
#if USED_WGP_AGIC_PEN
		hover_button_check_bit = 0;
#else
		hover_button_check_bit = 1;
#endif
		ucPenDataHighHoverButtonReliableCnt = thisModeConf->PenData.ucPenDataHighHoverButton1ReliableCnt;
	}
	else
	{
#if USED_WGP_AGIC_PEN
		hover_button_check_bit = 1;
#else
		hover_button_check_bit = 0;
#endif
		ucPenDataHighHoverButtonReliableCnt = thisModeConf->PenData.ucPenDataHighHoverButton2ReliableCnt;
	}

	if(thisModeConf->PenData.usPenDataHighHoverButtonRejectTHD > 0)
	{
		ID_MAX_Value = MAX(0,g_sPenData_Max[WGP_PEN_DATA_1st_SYMBOL][2])+MAX(0,g_sPenData_Max[WGP_PEN_DATA_1st_SYMBOL][3]);
		int tmp_value = MAX(0,g_sPenData_Max[WGP_PEN_DATA_1st_SYMBOL][4])+MAX(0,g_sPenData_Max[WGP_PEN_DATA_1st_SYMBOL][5]);
		if(ID_MAX_Value < tmp_value)
		{
			ID_MAX_Value = tmp_value;
		}
		tmp_value = MAX(0,g_sPenData_Max[WGP_PEN_DATA_1st_SYMBOL][6])+MAX(0,g_sPenData_Max[WGP_PEN_DATA_1st_SYMBOL][7]);
		if(ID_MAX_Value < tmp_value)
		{
			ID_MAX_Value = tmp_value;
		}
		tmp_value = MAX(0,g_sPenData_Max[WGP_PEN_DATA_2nd_SYMBOL][2])+MAX(0,g_sPenData_Max[WGP_PEN_DATA_2nd_SYMBOL][3]);
		if(ID_MAX_Value < tmp_value)
		{
			ID_MAX_Value = tmp_value;
		}
		tmp_value = MAX(0,g_sPenData_Max[WGP_PEN_DATA_2nd_SYMBOL][4])+MAX(0,g_sPenData_Max[WGP_PEN_DATA_2nd_SYMBOL][5]);
		if(ID_MAX_Value < tmp_value)
		{
			ID_MAX_Value = tmp_value;
		}
		tmp_value = MAX(0,g_sPenData_Max[WGP_PEN_DATA_2nd_SYMBOL][6])+MAX(0,g_sPenData_Max[WGP_PEN_DATA_2nd_SYMBOL][7]);
		if(ID_MAX_Value < tmp_value)
		{
			ID_MAX_Value = tmp_value;
		}

		if(Pre_ID_MAX_Value != 0)
		{
			ID_MAX_Value = (thisModeConf->PenData.ucPenDataHighHoverButtonIIRcoef*Pre_ID_MAX_Value+(255-thisModeConf->PenData.ucPenDataHighHoverButtonIIRcoef)*ID_MAX_Value)/255;
		}

		if(bIsButtonProcess && thisPenInfo->bPen_button[hover_button_check_bit] == 1)
		{
			if(ID_MAX_Value < thisModeConf->PenData.usPenDataHighHoverButtonRejectTHD)
			{
				tmp_value = (ID_MAX_Value>>1)-(int)thisModeConf->PenData.ucPenDataHighHoverButtonAdopThOffset;
				if((g_sPenData_Max[ulPartNumber][8] + g_sPenData_Max[ulPartNumber][9] > tmp_value && thisModeConf->PenData.ucPenDataHighHoverButtonAdopThOffset != 0) || thisModeConf->PenData.ucPenDataHighHoverButtonAdopThOffset == 0)
					thisPenInfo->bPen_button[hover_button_check_bit] = 0;

				if(thisPenInfo->bPen_button_cnt[hover_button_check_bit] < ucPenDataHighHoverButtonReliableCnt)
					thisPenInfo->bPen_button[hover_button_check_bit] = 0;
			}

			if(ucPenDataHighHoverButtonReliableCnt > 0)
			{
				if(thisPenInfo->bPen_button_cnt[hover_button_check_bit]++ > 250)
					thisPenInfo->bPen_button_cnt[hover_button_check_bit] = ucPenDataHighHoverButtonReliableCnt;
			}
		}

		Pre_ID_MAX_Value = ID_MAX_Value;
	}

	if(bIsButtonProcess)
	{
		if(thisPenInfo->bPenPostProcessFlag)
		{
			thisPenInfo->bPen_button[hover_button_check_bit] = 0;
		}
		pre_hover_button[hover_button_check_bit] = current_hover_button[hover_button_check_bit];
		pre_contact_button[hover_button_check_bit] = 0;
	}
}

void algorithm_WGP_PenData_24bitStructure_ForceContactPressureGen(void)
{
	int pressure_array[3] = {0,};
	int tmp_pres = pressure_array[0] = thisPenInfo->us_pendata_pressure;
	pressure_array[1] = thisPenInfo->us_pre_pendata_pressure;
	pressure_array[2] = thisPenInfo->us_pre2_pendata_pressure;
	
	for(int i = 0; i < 2; i++)
	{
		if(pressure_array[i] > 0 && (pressure_array[i] != pressure_array[i+1]))
		{
			tmp_pres = pressure_array[i] + (pressure_array[i] - pressure_array[i+1]);
			break;
		}
	}
	
	if(tmp_pres < 10)tmp_pres = 10;
	thisPenInfo->us_pendata_pressure = (uint16_t)tmp_pres;
	
	thisPenInfo->us_pre2_pendata_pressure = thisPenInfo->us_pre_pendata_pressure;
	thisPenInfo->us_pre_pendata_pressure = thisPenInfo->us_pendata_pressure;	
}

bool_t algorithm_local_data_baseline_calculate_delta_WGP_24bitStructure(ePartialSensing_t RetVal)
{
	uint8_t chkSum = 0;
	int16_t delta;
	int32_t r, c, s, ii,i,j;
	int32_t start_c, end_c;
	uint32_t ulStartSymbolOffset;
	static int8_t DataForcePenContact = 0;
	bool_t hover_button_check_bit = 0;
#ifdef FingerAreaPenDeltaDelete
	int32_t local_rs = currentRowStart;
#endif
	int mode = 0;

#if USED_PEN_ID_GET_FUNCTION
	uint32_t eCurrentULCMDType = hal_Info_GetCurrentWGPPenBeaconType();
#endif /* USED_PEN_ID_GET_FUNCTION */
	if(thisPenInfo->bPenContact == NO)
	{
		if(thisPenInfo->bPrevPenContact == NO)
			mode = LOCAL_HOVER_MODE;
	}

	start_c = thisPenInfo->ucCurrentColumnStart;
	end_c = thisPenInfo->ucCurrentColumnEnd;

	if(thisPenInfo->bSearch_Mode_Flag == 0)
	{
		memset((void*)&sPenData_Max[0], INT16_MIN, sizeof(int16_t) * WGP_PEN_SYMBOL_NUM_1LHB);

		for(s = 0; s < WGP_PEN_SYMBOL_NUM_1LHB; s++)
		{
			for(r = 0; r < PEN_COORD_ROW_MAX; r++)
			{
				for(c = start_c; c <= end_c; c++)
				{
					/*
					 * DBPSK "Ref Symbol - Data Symbol"
					 */
					if(thisModeConf->PenData.sPenDataHoverButtonTHD > 0 &&
							mode == LOCAL_HOVER_MODE &&
	#if IS_WGPUHDPEN_PROTOCOL_OPERATION
							(((RetVal == PARTIAL_PEN_COORD_DATA2 || RetVal == PARTIAL_PEN_COORD_DATA4) && s <= 3) || ((RetVal == PARTIAL_PEN_COORD_DATA1 || RetVal == PARTIAL_PEN_COORD_DATA3) && s >= 2)))
	#else /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
							(((RetVal == PARTIAL_PEN_DATA2 || RetVal == PARTIAL_PEN_DATA4) && s <= 3) || ((RetVal == PARTIAL_PEN_DATA1 || RetVal == PARTIAL_PEN_DATA3) && s >= 2)))
	#endif /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
					{
						delta = 0;
						for(i=MAX(0,r-1); i<=MIN(PEN_COORD_ROW_MAX-1,r+1); i++)
						{
							for(j=MAX(0,c-1); j<=MIN(COL_MAX-1,c+1); j++)
							{
								delta += (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(i + (PEN_COORD_ROW_MAX * (s+1)), j) - (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(i, j);
							}
						}
					}
					else
					{
						delta = (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r + (PEN_COORD_ROW_MAX * (s+1)), c) - (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c);
					}

	#ifdef FingerAreaPenDeltaDelete
					if(thisModeConf->BaseLine.cFingerAreaPenDeltaDelete != 0)
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

					if(delta > sPenData_Max[s])
					{
						sPenData_Max[s] = delta;
					}
				}
			}
		}

		ulStartSymbolOffset = 0;
		switch(RetVal)
		{
			/*
			 * 1st Data Symbol
			 */
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			case PARTIAL_PEN_COORD_DATA2:
#else
			case PARTIAL_PEN_DATA2:
#endif
			{
				ulStartSymbolOffset = WGP_PEN_SYMBOL_NUM_1LHB;
			} // @suppress("No break at end of case")
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			case PARTIAL_PEN_COORD_DATA1:
#else
			case PARTIAL_PEN_DATA1:
#endif
			{
				algorithm_WGP_PenData_24bitStructure_SetSymbolBit(WGP_PEN_DATA_1st_SYMBOL, ulStartSymbolOffset, mode);

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
				if(RetVal ==  PARTIAL_PEN_COORD_DATA2)
#else
				if(RetVal == PARTIAL_PEN_DATA2)
#endif
				{
#if USED_WGP_AGIC_PEN
					hover_button_check_bit = 0;
#else
					hover_button_check_bit = 1;
#endif
					/*
					 * Contact 2bit Check Sum
					 * Hober 1bit Check Sum
					 */
					if(cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_CONTACT_0_BIT] == 0 &&
						cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_CONTACT_1_BIT] == 0)
					{
						/*
						 * contact check sum
						 */
						for(ii=0; ii<10; ii++)
						{
							if(cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][ii] == 1)
								chkSum++;
						}

						/*
						 * check sum unmatched
						 * keep previous state
						 */
						if((cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_2BITCHECKSUM_1_BIT] == ((chkSum & 0x2) != 0)) &&
							(cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_2BITCHECKSUM_0_BIT] == ((chkSum & 0x1) != 0)))
						{
							/*
							 * Contact!!
							 */
							thisPenInfo->bPenContact = YES;
							DataForcePenContact = thisModeConf->PenData.ucForcePenContact_NUM;
							thisPenInfo->bPen_button_cnt[0] = thisPenInfo->bPen_button_cnt[1] = 0;

#if USED_PEN_ID_GET_FUNCTION
							switch(eCurrentULCMDType)
							{
								case PWM_WGP_PEN_GETABS_BEACON:
								{
									algorithm_WGP_PenData_24bitStructure_PenPressureParsing(WGP_PEN_DATA_1st_SYMBOL);
									break;
								}
								case PWM_WGP_PEN_GETHASH_BEACON:
								{
									algorithm_WGP_PenData_24bitStructure_HashIDParsing(NO, WGP_PEN_DATA_1st_SYMBOL);
//									algorithm_WGP_PenData_24bitStructure_PenBetteryParsing(NO, WGP_PEN_DATA_1st_SYMBOL);
									break;
								}
								case PWM_WGP_PEN_GETID_1st_BEACON:
								case PWM_WGP_PEN_GETID_2nd_BEACON:
								case PWM_WGP_PEN_GETID_3rd_BEACON:
								{
									algorithm_WGP_PenData_24bitStructure_PenIDParsing(NO, WGP_PEN_DATA_1st_SYMBOL, eCurrentULCMDType);
									break;
								}
							}
#else /* USED_PEN_ID_GET_FUNCTION */
							/*
							 * Pressure!!
							 */
							algorithm_WGP_PenData_24bitStructure_PenPressureParsing(WGP_PEN_DATA_1st_SYMBOL);
#endif /* USED_PEN_ID_GET_FUNCTION */

#if AbnormalContactRemove_EN
							if(thisModeConf->PenData.ucAbnormalContactRemovePressureTH1	> 0 && thisModeConf->PenData.ucAbnormalContactRemovePressureTH2 > 0 && thisPenInfo->bEdgeAbnormalContact)
								algorithm_local_hoverContact_classify(sCompressurePressureData);
#endif
							if(thisPenInfo->us_pendata_pressure == 0)
							{
								thisPenInfo->bPenContact = NO;
								if(DataForcePenContact > 0)
								{
									thisPenInfo->bForcePenContactFlag = 1;
									thisPenInfo->bPenContact = YES;
									DataForcePenContact--;
								}
							}
							else
							{
								thisPenInfo->bForcePenContactFlag = 0;
							}
						}
					}
					else if(DataForcePenContact > 0)
					{
						thisPenInfo->bPenContact = YES;
						thisPenInfo->bForcePenContactFlag = 1;
						DataForcePenContact--;
						thisPenInfo->bPen_button_cnt[0] = thisPenInfo->bPen_button_cnt[1] = 0;
					}
					else /*if(cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stHVSYB_HOVER_BIT] == 1)*/
					{
						/*
						 * Hover
						 */
						thisPenInfo->bForcePenContactFlag = 0;
						thisPenInfo->bPenContact = NO;
						thisPenInfo->us_pendata_pressure = 1;
						thisPenInfo->us_pre_pendata_pressure = 1;
						thisPenInfo->us_pre2_pendata_pressure = 1;
#if AbnormalContactRemove_EN
						algorithm_local_prePressureBit_clear();
#endif
						DataForcePenContact=0;
						/*
						 * Button 1
						 */
						chkSum = 0;
						for(ii=0; ii<5; ii++)
						{
							if(cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][ii] == 1)
								chkSum++;
						}

						if(chkSum%2 == cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stHVSYB_1BITCHECKSUM_BIT] &&
								cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stHVSYB_HOVER_BIT] == 1)
						{
#if USED_PEN_ID_GET_FUNCTION
							switch(eCurrentULCMDType)
							{
								case PWM_WGP_PEN_GETABS_BEACON:
								{
									algorithm_WGP_PenData_24bitStructure_HashIDParsing(YES, WGP_PEN_DATA_1st_SYMBOL);
									if(cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stHVSYB_SW1_BIT] == 1)
									{
										current_hover_button[hover_button_check_bit] = 1;
									}
									else
									{
										current_hover_button[hover_button_check_bit] = 0;
									}
//									current_hover_button[hover_button_check_bit] = cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stHVSYB_SW1_BIT];
//									algorithm_WGP_PenData_24bitStructure_PenButtonParsing(YES, WGP_PEN_DATA_1st_SYMBOL);
									break;
								}
								case PWM_WGP_PEN_GETHASH_BEACON:
								{
									algorithm_WGP_PenData_24bitStructure_HashIDParsing(YES, WGP_PEN_DATA_1st_SYMBOL);
//									algorithm_WGP_PenData_24bitStructure_PenBetteryParsing(YES, WGP_PEN_DATA_1st_SYMBOL);
									break;
								}
								case PWM_WGP_PEN_GETID_1st_BEACON:
								case PWM_WGP_PEN_GETID_2nd_BEACON:
								case PWM_WGP_PEN_GETID_3rd_BEACON:
								{
									algorithm_WGP_PenData_24bitStructure_PenIDParsing(YES, WGP_PEN_DATA_1st_SYMBOL, eCurrentULCMDType);
									break;
								}
							}
#else /* USED_PEN_ID_GET_FUNCTION */
//							algorithm_WGP_PenData_24bitStructure_PenButtonParsing(YES, WGP_PEN_DATA_1st_SYMBOL);

							current_hover_button[hover_button_check_bit] = cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stHVSYB_SW1_BIT];
#endif /* USED_PEN_ID_GET_FUNCTION */

							if((pre_hover_button[hover_button_check_bit] == 1 && current_hover_button[hover_button_check_bit] == 1) ||
								(pre_contact_button[hover_button_check_bit] == 1 && current_hover_button[hover_button_check_bit] == 1))
							{
								thisPenInfo->bPen_button[hover_button_check_bit] = 1;
							}
							else
							{
								thisPenInfo->bPen_button[hover_button_check_bit] = 0;
							}
						}

						algorithm_WGP_PenData_24bitStructure_PenButton_RejectCheck(WGP_PEN_DATA_1st_SYMBOL, YES);
					}
				}
				break;
			}
			/*
			 * 2nd Data Symbol
			 */
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			case PARTIAL_PEN_COORD_DATA4:
#else
			case PARTIAL_PEN_DATA4:
#endif
			{
				ulStartSymbolOffset = WGP_PEN_SYMBOL_NUM_1LHB;
			} // @suppress("No break at end of case")
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			case PARTIAL_PEN_COORD_DATA3:
#else
			case PARTIAL_PEN_DATA3:
#endif
			{
				algorithm_WGP_PenData_24bitStructure_SetSymbolBit(WGP_PEN_DATA_2nd_SYMBOL, ulStartSymbolOffset, mode);

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
				if(RetVal == PARTIAL_PEN_COORD_DATA4)
#else
				if(RetVal == PARTIAL_PEN_DATA4)
#endif
				{
#if USED_WGP_AGIC_PEN
						hover_button_check_bit = 1;
#else
						hover_button_check_bit = 0;
#endif
					if(thisPenInfo->bPenContact == YES)
					{
						/*
						 * contact check sum
						 */
						for(ii=0; ii<10; ii++)
						{
							if(cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][ii] == 1)
								chkSum++;
						}

						/*
						 * check sum unmatched
						 * keep previous state
						 */
						if((cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_1_BIT_2BITCHECKSUM] == ((chkSum & 0x2) != 0)) &&
							(cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_0_BIT_2BITCHECKSUM] == ((chkSum & 0x1) != 0)))
						{
#if USED_PEN_ID_GET_FUNCTION
							switch(eCurrentULCMDType)
							{
								case PWM_WGP_PEN_GETABS_BEACON:
								{
									algorithm_WGP_PenData_24bitStructure_PenButtonParsing(NO, WGP_PEN_DATA_2nd_SYMBOL);
									algorithm_WGP_PenData_24bitStructure_PenPressureParsing(WGP_PEN_DATA_2nd_SYMBOL);
									break;
								}
								case PWM_WGP_PEN_GETHASH_BEACON:
								{
									algorithm_WGP_PenData_24bitStructure_PenButtonParsing(NO, WGP_PEN_DATA_2nd_SYMBOL);
									algorithm_WGP_PenData_24bitStructure_PenPressureParsing(WGP_PEN_DATA_2nd_SYMBOL);
									break;
								}
								case PWM_WGP_PEN_GETID_1st_BEACON:
								case PWM_WGP_PEN_GETID_2nd_BEACON:
								case PWM_WGP_PEN_GETID_3rd_BEACON:
								{
									algorithm_WGP_PenData_24bitStructure_PenIDParsing(NO, WGP_PEN_DATA_2nd_SYMBOL, eCurrentULCMDType);
									break;
								}
							}
	#if AbnormalContactRemove_EN
							if(thisModeConf->PenData.ucAbnormalContactRemovePressureTH1	> 0 && thisModeConf->PenData.ucAbnormalContactRemovePressureTH2 > 0 && thisPenInfo->bEdgeAbnormalContact)
								algorithm_local_hoverContact_classify(sCompressurePressureData);
	#endif
#else /* USED_PEN_ID_GET_FUNCTION */
							/*
							 * Pressure!!
							 */
							algorithm_WGP_PenData_24bitStructure_PenPressureParsing(WGP_PEN_DATA_2nd_SYMBOL);
	#if AbnormalContactRemove_EN
							if(thisModeConf->PenData.ucAbnormalContactRemovePressureTH1	> 0 && thisModeConf->PenData.ucAbnormalContactRemovePressureTH2 > 0 && thisPenInfo->bEdgeAbnormalContact)
								algorithm_local_hoverContact_classify(sCompressurePressureData);
	#endif
							/*
							 * Button 1 and 2!!
							 */
//							algorithm_WGP_PenData_24bitStructure_PenButtonParsing(NO, WGP_PEN_DATA_2nd_SYMBOL);
							{
								current_contact_button[0] = cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_SW1_BIT];
							}
							{
//								current_contact_button[0] = cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_SW1_BIT];
							}

							{
								current_contact_button[1] = cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_SW2_BIT];
							}
							{
//								current_contact_button[1] = cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_SW2_BIT];
							}
//							if(cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_SW1_BIT] == 1 )
//							{
//								current_contact_button[0] = 1;
//							}
//							else
//							{
//								current_contact_button[0] = 0;
//							}
//
//							if(cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_SW2_BIT] == 1 )
//							{
//								current_contact_button[1] = 1;
//							}
//							else
//							{
//								current_contact_button[1] = 0;
//							}
#endif /* USED_PEN_ID_GET_FUNCTION */

							if((pre_contact_button[0] == 1 && current_contact_button[0] == 1) || (pre_hover_button[0] == 1 && current_contact_button[0] == 1))
							{
								thisPenInfo->bPen_button[0] = 1;
							}
							else
							{
								thisPenInfo->bPen_button[0] = 0;
							}

							if((pre_contact_button[1] == 1 && current_contact_button[1] == 1) || (pre_hover_button[1] == 1 && current_contact_button[1] == 1))
							{
								thisPenInfo->bPen_button[1] = 1;
							}
							else
							{
								thisPenInfo->bPen_button[1] = 0;
							}

							if(thisPenInfo->us_pendata_pressure == 0)
							{
								thisPenInfo->bPenContact = NO;
								if(DataForcePenContact > 0)
								{
									thisPenInfo->bForcePenContactFlag = 1;
									thisPenInfo->bPenContact = YES;
									DataForcePenContact--;
								}
							}
							else
							{
								thisPenInfo->bForcePenContactFlag = 0;
							}


							if(thisPenInfo->bForcePenContactFlag)
							{
								thisPenInfo->bPen_button[0] = pre_contact_button[0];
								thisPenInfo->bPen_button[0] = pre_contact_button[1];
							}

							if(thisPenInfo->bPenPostProcessFlag)
							{
								thisPenInfo->bPen_button[0] = thisPenInfo->bPen_button[1] = 0;
							}

							pre_contact_button[0] = current_contact_button[0];
							pre_contact_button[1] = current_contact_button[1];
							pre_hover_button[0] = 0;
							pre_hover_button[1] = 0;
						}

						thisPenInfo->bPen_button_cnt[0] = thisPenInfo->bPen_button_cnt[1] = 0;
					}
					else
					{
						/*
						 * Hover
						 */
						if(cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndHVSYB_HOVER_0_BIT] == 0)
						{
							thisPenInfo->bPenContact = YES;
							DataForcePenContact = thisModeConf->PenData.ucForcePenContact_NUM;
							algorithm_WGP_PenData_24bitStructure_ForceContactPressureGen();
							thisPenInfo->bPen_button_cnt[0] = thisPenInfo->bPen_button_cnt[1] = 0;
						}
						else if(DataForcePenContact > 0)
						{
							thisPenInfo->bForcePenContactFlag = 1;
							thisPenInfo->bPenContact = YES;
							DataForcePenContact--;
							thisPenInfo->bPen_button_cnt[0] = thisPenInfo->bPen_button_cnt[1] = 0;
						}
						else
						{
							thisPenInfo->bForcePenContactFlag = 0;
							thisPenInfo->bPenContact = NO;
							thisPenInfo->us_pendata_pressure = 1;
							thisPenInfo->us_pre_pendata_pressure = 1;
							thisPenInfo->us_pre2_pendata_pressure = 1;
#if AbnormalContactRemove_EN
							algorithm_local_prePressureBit_clear();
#endif
							DataForcePenContact = 0;
							/*
							 * Button 1
							 */
							chkSum = 0;
							for(ii=0; ii<5; ii++)
							{
								if(cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][ii] == 1)
									chkSum++;
							}

							if(chkSum%2 == cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndHVSYB_1BITCHECKSUM_BIT] &&
									cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndHVSYB_HOVER_0_BIT] == 1)
							{
#if USED_PEN_ID_GET_FUNCTION
								switch(eCurrentULCMDType)
								{
									case PWM_WGP_PEN_GETABS_BEACON:
									{
										algorithm_WGP_PenData_24bitStructure_HashIDParsing(YES, WGP_PEN_DATA_2nd_SYMBOL);
										algorithm_WGP_PenData_24bitStructure_PenButtonParsing(YES, WGP_PEN_DATA_2nd_SYMBOL);
										break;
									}
									case PWM_WGP_PEN_GETHASH_BEACON:
									{
										algorithm_WGP_PenData_24bitStructure_HashIDParsing(YES, WGP_PEN_DATA_2nd_SYMBOL);
//										algorithm_WGP_PenData_24bitStructure_PenBetteryParsing(YES, WGP_PEN_DATA_2nd_SYMBOL);
										break;
									}
									case PWM_WGP_PEN_GETID_1st_BEACON:
									case PWM_WGP_PEN_GETID_2nd_BEACON:
									case PWM_WGP_PEN_GETID_3rd_BEACON:
									{
										algorithm_WGP_PenData_24bitStructure_PenIDParsing(YES, WGP_PEN_DATA_2nd_SYMBOL, eCurrentULCMDType);
										break;
									}
								}
#else /* USED_PEN_ID_GET_FUNCTION */
//								algorithm_WGP_PenData_24bitStructure_PenButtonParsing(YES, WGP_PEN_DATA_2nd_SYMBOL);
								{
									current_hover_button[hover_button_check_bit] = cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndHVSYB_SW2_BIT];
								}
								{
//									current_hover_button[hover_button_check_bit] = cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndHVSYB_SW2_BIT];
								}
//								if(cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndHVSYB_SW2_BIT] == 1)
//								{
//									current_hover_button[hover_button_check_bit] = 1;
//								}
//								else
//								{
//									current_hover_button[hover_button_check_bit] = 0;
//								}
#endif /* USED_PEN_ID_GET_FUNCTION */

								if((pre_hover_button[hover_button_check_bit] == 1 && current_hover_button[hover_button_check_bit] == 1) ||
										(pre_contact_button[hover_button_check_bit] == 1 && current_hover_button[hover_button_check_bit] == 1))
								{
									thisPenInfo->bPen_button[hover_button_check_bit] = 1;
								}
								else
								{
									thisPenInfo->bPen_button[hover_button_check_bit] = 0;
								}
							}

							algorithm_WGP_PenData_24bitStructure_PenButton_RejectCheck(WGP_PEN_DATA_2nd_SYMBOL, YES);
						}
					}
				}
				break;
			}
		}
		
		if(thisPenInfo->bForcePenContactFlag == 1)algorithm_WGP_PenData_24bitStructure_ForceContactPressureGen();
			
	}
	else
	{
		memset((void*)&sPenData_Max[0], INT16_MIN, sizeof(int16_t) * WGP_PEN_SYMBOL_NUM_1LHB);

		for(s = 0; s < WGP_PEN_SYMBOL_NUM_1LHB; s++)
		{
#if IS_WGPUHDPEN_PROTOCOL_OPERATION
			if(((RetVal == PARTIAL_PEN_COORD_DATA2 || RetVal == PARTIAL_PEN_COORD_DATA4) && s<=3) || ((RetVal == PARTIAL_PEN_COORD_DATA1 || RetVal == PARTIAL_PEN_COORD_DATA3) && s>=2))
			{
				if(RetVal == PARTIAL_PEN_COORD_DATA2 || RetVal == PARTIAL_PEN_COORD_DATA4)ulStartSymbolOffset=WGP_PEN_SYMBOL_NUM_1LHB;
#else /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
			if(((RetVal == PARTIAL_PEN_DATA2 || RetVal == PARTIAL_PEN_DATA4) && s<=3) || ((RetVal == PARTIAL_PEN_DATA1 || RetVal == PARTIAL_PEN_DATA3) && s>=2))
			{
				if(RetVal == PARTIAL_PEN_DATA2 || RetVal == PARTIAL_PEN_DATA4)ulStartSymbolOffset=WGP_PEN_SYMBOL_NUM_1LHB;
#endif /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
				else ulStartSymbolOffset = 0;

				for(r = 0; r < PEN_COORD_ROW_MAX; r++)
				{
					for(c = start_c; c <= end_c; c++)
					{
						delta = 0;
						for(i=MAX(0,r-1);i<=MIN(PEN_COORD_ROW_MAX-1,r+1);i++)for(j=MAX(0,c-1);j<=MIN(COL_MAX-1,c+1);j++)
							delta += (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(i + (PEN_COORD_ROW_MAX * (s+1)), j) - (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(i, j);

						if(delta > sPenData_Max[s])
						{
							sPenData_Max[s] = delta;
						}
					}
				}
#if IS_WGPUHDPEN_PROTOCOL_OPERATION
				if(RetVal == PARTIAL_PEN_COORD_DATA2 || RetVal == PARTIAL_PEN_COORD_DATA1)
#else /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
				if(RetVal == PARTIAL_PEN_DATA2 || RetVal == PARTIAL_PEN_DATA1)
#endif /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
				{
					if((s+ulStartSymbolOffset==8||s+ulStartSymbolOffset==9) && g_sPenData_Max[WGP_PEN_DATA_1st_SYMBOL][s+ulStartSymbolOffset] != 0)
						g_sPenData_Max[WGP_PEN_DATA_1st_SYMBOL][s+ulStartSymbolOffset] = (thisModeConf->PenData.ucPenDataHighHoverButtonIIRcoef*g_sPenData_Max[WGP_PEN_DATA_1st_SYMBOL][s+ulStartSymbolOffset]+(255-thisModeConf->PenData.ucPenDataHighHoverButtonIIRcoef)*sPenData_Max[s])/255;
					else g_sPenData_Max[WGP_PEN_DATA_1st_SYMBOL][s+ulStartSymbolOffset] = sPenData_Max[s];
				}
				else
				{
					if((s+ulStartSymbolOffset==8||s+ulStartSymbolOffset==9) && g_sPenData_Max[WGP_PEN_DATA_2nd_SYMBOL][s+ulStartSymbolOffset] != 0)
						g_sPenData_Max[WGP_PEN_DATA_2nd_SYMBOL][s+ulStartSymbolOffset] = (thisModeConf->PenData.ucPenDataHighHoverButtonIIRcoef*g_sPenData_Max[WGP_PEN_DATA_2nd_SYMBOL][s+ulStartSymbolOffset]+(255-thisModeConf->PenData.ucPenDataHighHoverButtonIIRcoef)*sPenData_Max[s])/255;
					else g_sPenData_Max[WGP_PEN_DATA_2nd_SYMBOL][s+ulStartSymbolOffset] = sPenData_Max[s];
				}
			}
		}

		algorithm_WGP_PenData_24bitStructure_PenButton_RejectCheck(WGP_PEN_DATA_2nd_SYMBOL, NO);
	}

	return 0;
}

void algorithm_local_baseline_init(void)
{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
//	memset((void*)HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
//	memset((void*)HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
//	memset((void*)HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR(), 0x00, sizeof(FULLHOVERIMAGE_2));

	memset(LOCALBASELINE, 0, sizeof(LOCALBASELINE));
	memset((void*)HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), 0x00, sizeof(FULLHOVERIMAGE));
	memset((void*)HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR(), 0x00, sizeof(FULLHOVERIMAGE_2));
	memset((void*)HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
	memset(LOCALBASELINE, 0, sizeof(LOCALBASELINE));
	memset(LOCALBASELINE_2, 0, sizeof(LOCALBASELINE_2));
	memset((void*)HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), 0x00, sizeof(FULLHOVERIMAGE));
	memset((void*)HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR(), 0x00, sizeof(FULLHOVERIMAGE_2));
	memset((void*)HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
	memset((void*)HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_2_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
	#if LOCAL_REBASE_ALGO_EN && (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)// || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	memset(RECALBASELINE, 0, sizeof(RECALBASELINE));
	#endif
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	memset((void *)&ulZeroFingerRawMaskInfo[0][0], 0x00, sizeof(uint32_t)*(ROW_MAX * ZERO_FINGER_RAWDATA_MASK_COL_NUM));
#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
	memset(LOCALNOISEBUF1,0,sizeof(LOCALNOISEBUF1));
#if (ADAPTOR_NOISE_ALGO_EN)
	memset(LOCALNOISEBUF2,0,sizeof(LOCALNOISEBUF2));
#endif
}

void algorithm_data_local_process(ePartialSensing_t RetVal)
{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
	algorithm_local_data_baseline_calculate_delta_WGP_24bitStructure(RetVal);
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
	algorithm_local_data_baseline_calculate_delta(RetVal);
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
	eActivePenType_t ePenOpType = hal_Info_GetControlActivePenOPType();
	switch(ePenOpType)
	{
		case ACTIVEPEN_TYPE_LOCAL_MS:
		{
			algorithm_local_data_baseline_calculate_delta(RetVal);
			break;
		}
		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			algorithm_local_data_baseline_calculate_delta_WGP_24bitStructure(RetVal);
			break;
		}
	}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
}

void alogorithm_coord_modify_pos_local(tXY_t* old_pos,tXY_t* pos, int mode)
{
	int x, y;

	if( thisModeConf->Coord.bSwapXY )
	{
		x = pos->y;
		y = pos->x;
	}
	else
	{
		x = pos->x;
		y = pos->y;
	}

	if( thisModeConf->Coord.bFlipX )
		x = thisInfo->tCoord.iInternalXRes - x;

	/*
	 * Expand edge position.
	 *  - 내부 좌표로 먼저 expand합니다.
	 *  - 기존에 full sized edge 사용 시 외부좌표로 변환 후 3/2 point에서 expand했는데,
	 *  - 이제는 내부좌표 상태에서 expand하므로 offset인 1/2를 제외하고 unit distance부터 expand하도록 합니다.
	 */
//	if(1)
	{
		if (!thisModeConf->PenCoord.bDoNotExpandPos)
		{
			int ucLeftEdgeExpand_local, ucRightEdgeExpand_local, ucTopEdgeExpand_local, ucBottomEdgeExpand_local;
			{
				ucLeftEdgeExpand_local = thisModeConf->PenCoord.ucLeftEdgeExpand_local;
				ucRightEdgeExpand_local = thisModeConf->PenCoord.ucRightEdgeExpand_local;
				ucTopEdgeExpand_local = thisModeConf->PenCoord.ucTopEdgeExpand_local;
				ucBottomEdgeExpand_local = thisModeConf->PenCoord.ucBottomEdgeExpand_local;
			}
			
			int iXExpandStart = thisInfo->tCoord.iXExpandStart;
			int iYExpandStart = thisInfo->tCoord.iYExpandStart;
			
#if (PEN_EdgeExpandStartOffset_On == YES)
			iXExpandStart += thisModeConf->PenCoord.sXExpandStartOffset;
			iYExpandStart += thisModeConf->PenCoord.sYExpandStartOffset;
#endif			
			
#if (EdgeExpandLocalCornerOffsetAdd == YES)
			if(thisModeConf->PenCoord.usEdgeExpand_local_CornerSizeOffset)
			{
				tXY_t tmp_p;
				tmp_p.x = x;
				tmp_p.y = y;
				if(2 == algorithm_coord_IsEdgeArea(&tmp_p, thisModeConf->PenCoord.usEdgeExpand_local_CornerSizeOffset))
				{
					iXExpandStart += thisModeConf->PenCoord.usEdgeExpand_local_CornerSizeOffset;
					iYExpandStart += thisModeConf->PenCoord.usEdgeExpand_local_CornerSizeOffset;
					ucLeftEdgeExpand_local += thisModeConf->PenCoord.cLeftEdgeExpand_local_CornerOffset;
					ucRightEdgeExpand_local += thisModeConf->PenCoord.cRightEdgeExpand_local_CornerOffset;
					ucTopEdgeExpand_local += thisModeConf->PenCoord.cTopEdgeExpand_local_CornerOffset;
					ucBottomEdgeExpand_local += thisModeConf->PenCoord.cBottomEdgeExpand_local_CornerOffset;
				}
			}
#endif
			
			if (x < iXExpandStart)
				x = iXExpandStart + (((x - iXExpandStart) * (int32_t)ucLeftEdgeExpand_local) >> 6);
			else if (thisInfo->tCoord.iInternalXRes - x < iXExpandStart)
				x = thisInfo->tCoord.iInternalXRes - (iXExpandStart
									 + (((thisInfo->tCoord.iInternalXRes - x - iXExpandStart) * (int32_t)ucRightEdgeExpand_local) >> 6));

			if (y < (iYExpandStart))
				y = (iYExpandStart) + (((y - (iYExpandStart)) * (int32_t)ucTopEdgeExpand_local) >> 6);
			else if (thisInfo->tCoord.iInternalYRes - y < iYExpandStart)
				y = thisInfo->tCoord.iInternalYRes - (iYExpandStart
									 + (((thisInfo->tCoord.iInternalYRes - y - iYExpandStart) * (int32_t)ucBottomEdgeExpand_local) >> 6));
		}
	}

	/*
	 * Modify resolution domain.
	 */
	x = ( (x + thisInfo->tCoord.iXOffset ) * (thisCommonConf->iXResolution+thisModeConf->PenCoord.sPenGlobalCoordiXResolutionOffset) ) / (thisInfo->tCoord.iInternalXRes + 2*thisInfo->tCoord.iXOffset);
	x += thisModeConf->PenCoord.sPenGlobalCoordiOffsetX;
#if (PenGlobalCoordiY_2Region_Set == YES)
	if(y < thisModeConf->PenCoord.sPenGlobalCoordiY_2Region_boundary)
	{
		y = ( (y + thisInfo->tCoord.iYOffset ) * (thisCommonConf->iYResolution+thisModeConf->PenCoord.sPenGlobalCoordiYResolutionOffset) ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
		y += thisModeConf->PenCoord.sPenGlobalCoordiOffsetY;
	}
	else
	{
		y = ( (y + thisInfo->tCoord.iYOffset ) * (thisCommonConf->iYResolution+thisModeConf->PenCoord.sPenGlobalCoordiYResolutionOffset1) ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
		y += thisModeConf->PenCoord.sPenGlobalCoordiOffsetY1;
	}
#else
	y = ( (y + thisInfo->tCoord.iYOffset ) * (thisCommonConf->iYResolution+thisModeConf->PenCoord.sPenGlobalCoordiYResolutionOffset) ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
	y += thisModeConf->PenCoord.sPenGlobalCoordiOffsetY;
#endif

	/*
	 * Clipping.
	 */
	int iXResolutionForClipping = thisCommonConf->iXResolution - 1;
	int iYResolutionForClipping = thisCommonConf->iYResolution - 1;
//	if(iXResolutionForClipping > 32767)iXResolutionForClipping = 32767;
//	if(iYResolutionForClipping > 32767)iYResolutionForClipping = 32767;
	if(thisModeConf->PenCoord.bExpectClipping_Pen_On)
	{
		pos->x = x,	pos->y = y;
		if (x < (int)thisCommonConf->ucXClipping){
			x = (int)(thisCommonConf->ucXClipping);
//			if(old_pos != pos && pos->x != old_pos->x)
			if( (thisModeConf->PenCoord.bUseNewCippingCond_Pen && old_pos != pos && pos->x < (thisCommonConf->ucXClipping) && old_pos->x > (thisCommonConf->ucXClipping))
				|| (!thisModeConf->PenCoord.bUseNewCippingCond_Pen && old_pos != pos && pos->x != old_pos->x) )
				y = ( (x - old_pos->x)*(pos->y - old_pos->y) + ((pos->x - old_pos->x)>>1) ) / (pos->x - old_pos->x) + old_pos->y;
			pos->x = x,	pos->y = y;
		}
		else if (x > ((int)((iXResolutionForClipping) - thisCommonConf->ucXClipping))){
			x = (iXResolutionForClipping) - thisCommonConf->ucXClipping;
//			if(old_pos != pos && pos->x != old_pos->x)
			if( (thisModeConf->PenCoord.bUseNewCippingCond_Pen && old_pos != pos && pos->x > ((int)((iXResolutionForClipping) - (thisCommonConf->ucXClipping))) && old_pos->x < ((int)((iXResolutionForClipping) - (thisCommonConf->ucXClipping))))
				|| (!thisModeConf->PenCoord.bUseNewCippingCond_Pen && old_pos != pos && pos->x != old_pos->x) )
				y = ( (x - old_pos->x)*(pos->y - old_pos->y) + ((pos->x - old_pos->x)>>1) ) / (pos->x - old_pos->x) + old_pos->y;
			pos->x = x,	pos->y = y;
		}
		if (y < (int)(thisCommonConf->ucYClipping)){
			y = (int)thisCommonConf->ucYClipping;
//			if(old_pos != pos && pos->y != old_pos->y)
			if( (thisModeConf->PenCoord.bUseNewCippingCond_Pen && old_pos != pos && pos->y < (thisCommonConf->ucYClipping) && old_pos->y > (thisCommonConf->ucYClipping))
				|| (!thisModeConf->PenCoord.bUseNewCippingCond_Pen && old_pos != pos && pos->y != old_pos->y) )
				x = ( (y - old_pos->y)*(pos->x - old_pos->x) + ((pos->y - old_pos->y)>>1) ) / (pos->y - old_pos->y) + old_pos->x;
			pos->x = x,	pos->y = y;
		}
		else if (y > (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping)){
			y = (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping);
//			if(old_pos != pos && pos->y != old_pos->y)
			if( (thisModeConf->PenCoord.bUseNewCippingCond_Pen && old_pos != pos && pos->y > ((int)((iYResolutionForClipping) - (thisCommonConf->ucYClipping))) && old_pos->y < ((int)((iYResolutionForClipping) - (thisCommonConf->ucYClipping))))
				|| (!thisModeConf->PenCoord.bUseNewCippingCond_Pen && old_pos != pos && pos->y != old_pos->y) )
				x = ( (y - old_pos->y)*(pos->x - old_pos->x) + ((pos->y - old_pos->y)>>1) ) / (pos->y - old_pos->y) + old_pos->x;
			pos->x = x,	pos->y = y;
		}
	}
	else
	{
		if (x < (int)thisCommonConf->ucXClipping)
			x = (int)(thisCommonConf->ucXClipping);
		else if (x > ((int)((iXResolutionForClipping) - thisCommonConf->ucXClipping)))
			x = (iXResolutionForClipping) - thisCommonConf->ucXClipping;

		if (y < (int)(thisCommonConf->ucYClipping))
			y = (int)thisCommonConf->ucYClipping;
		else if (y > (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping))
			y = (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping);
		pos->x = x,	pos->y = y;
	}
	
	#if (PEN_REMOVE_EDGE_EN == YES)
	if(thisModeConf->PenCoord.bRemoveEdge && !algorithm_coord_IsEdgeArea(&thisInfo->tCoord_local_dsp.tFirstPos, 0))
	{
		tXY_t pastpos1;
		if(thisModeConf->PenCoord.bUsetRealPastSentPos1 == 0)
		{
			pastpos1.x = thisInfo->tCoord_local_dsp.tPastPos[1].tXY.x, pastpos1.y = thisInfo->tCoord_local_dsp.tPastPos[1].tXY.y;
			pastpos1.x = ( (pastpos1.x + thisInfo->tCoord.iXOffset) * (thisCommonConf->iXResolution+thisModeConf->PenCoord.sPenGlobalCoordiXResolutionOffset) ) / (thisInfo->tCoord.iInternalXRes + 2*thisInfo->tCoord.iXOffset);
			pastpos1.y = ( (pastpos1.y + thisInfo->tCoord.iYOffset) * (thisCommonConf->iYResolution+thisModeConf->PenCoord.sPenGlobalCoordiYResolutionOffset) ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
			pastpos1.x += thisModeConf->PenCoord.sPenGlobalCoordiOffsetX;
			pastpos1.y += thisModeConf->PenCoord.sPenGlobalCoordiOffsetY;
			if (pastpos1.x < (int)thisCommonConf->ucXClipping) pastpos1.x = (int)(thisCommonConf->ucXClipping);
			else if (pastpos1.x > ((int)((iXResolutionForClipping) - thisCommonConf->ucXClipping))) pastpos1.x = (iXResolutionForClipping) - thisCommonConf->ucXClipping;
			if (pastpos1.y < (int)(thisCommonConf->ucYClipping)) pastpos1.y = (int)thisCommonConf->ucYClipping;
			else if (pastpos1.y > (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping)) pastpos1.y = (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping);
		}
		else if(thisModeConf->PenCoord.bUsetRealPastSentPos1 == 1)
		{
			pastpos1.x = thisInfo->tCoord_local_dsp.tRealPastSentPos1.tXY.x;
			pastpos1.y = thisInfo->tCoord_local_dsp.tRealPastSentPos1.tXY.y;
		}
		
		if(/*thisInfo->tCoord_local_dsp.tPos.vusS <= thisInfo->tCoord_local_dsp.tPastPos[0].vusS && */thisInfo->tCoord_local_dsp.tPos.vusS && thisInfo->tCoord_local_dsp.tPastPos[0].vusS && thisInfo->tCoord_local_dsp.tPastPos[1].vusS)
		{
			if(old_pos->x == pos->x && ((pos->x <= (thisCommonConf->ucXClipping + thisModeConf->PenCoord.usEndCoordMargin) && pastpos1.x - old_pos->x > thisModeConf->PenCoord.usRemoveEdgeXdistThd)
				|| (pos->x >= (iXResolutionForClipping - thisCommonConf->ucXClipping - thisModeConf->PenCoord.usEndCoordMargin) && old_pos->x - pastpos1.x > thisModeConf->PenCoord.usRemoveEdgeXdistThd)))
			{
				thisInfo->tCoord_local_dsp.bRemoveEdge = 1;
			}
			if(old_pos->y == pos->y && ((pos->y <= (thisCommonConf->ucYClipping + thisModeConf->PenCoord.usEndCoordMargin) && pastpos1.y - old_pos->y > thisModeConf->PenCoord.usRemoveEdgeYdistThd)
				||  (pos->y >= (iYResolutionForClipping - thisCommonConf->ucYClipping - thisModeConf->PenCoord.usEndCoordMargin) && old_pos->y - pastpos1.y > thisModeConf->PenCoord.usRemoveEdgeYdistThd)))
			{
				thisInfo->tCoord_local_dsp.bRemoveEdge = 1;
			}
		}
		
		if(!(pos->x == old_pos->x || pos->y == old_pos->y))
		{
			thisInfo->tCoord_local_dsp.bRemoveEdge = 0;
		}
		
		if(thisInfo->tCoord_local_dsp.bRemoveEdge == 1)
		{
			pos->x = x = old_pos->x, pos->y = y = old_pos->y;
//			thisInfo->tCoord_local_dsp.tPos.vusS = 0;
		}
	}
	#endif
	
	pos->x = x;
	pos->y = y;
}

extern void protocol_hid_PushPenEvent(const uSWIPTouchItem_t* _kptItem); // NOTE : 헤더파일에 위치 잡고 없애자!!
//extern uint8_t	g_ConnectedDevice;
#if 0
void algorithm_PendPenEvent(void)
{
	int i;
	int distX, distY;

	tXY_t pos, old_pos;
	uint8_t ucMoveTHD;

	eSWIPPacketFormatId_t id = protocol_swip_GetPacketFormatId();

#define SET_POS(tItem, pos)  \
	do {    \
	(tItem).tItem00.ucXHigh = ((pos).x >> 8) & 0xFF;    \
	(tItem).tItem00.ucYHigh = ((pos).y >> 8) & 0xFF;    \
	(tItem).tItem00.ucXLow = (pos).x & 0xFF;    \
	(tItem).tItem00.ucYLow = (pos).y & 0xFF;    \
	} while(0)

	if(g_ConnectedDevice == I2C_CONNECT_PC)
	{
		protocol_swip_InitTouchEventBuffer();
		//    protocol_hid_InitPenEventBuffer();
	}
	
#if (SWIP_QUEUE_MODE)
	thisInfo->bQueueStart 	= 0;
	#if (SWIP_QUEUE_MODE == 2)
		thisInfo->bTouchOffFlag	= 0;
	#endif
#endif

#if USED_SHARP_SPECIFIC_PROTOCOL
	tTouchItemType_t touchItemType;
	memset(&touchItemType, 0, sizeof(tTouchItemType_t));
	/*
	 * TODO : finger mode를 기본으로 설정.
	 * algorithm을 거친 후 touch type에 따른 flag를 setting 해야 함.
	 */
	touchItemType.active_stylus_hover = YES;
	touchItemType.active_stylus = YES;
	touchItemType.passive_stylus = YES;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */

	for (i = 0; i < 1; i++)
	{
		old_pos = thisInfo->tCoord_local.tPastSentPos.tXY[i];
		alogorithm_coord_modify_pos_local(&old_pos,&old_pos);

		if (thisInfo->tCoord_local.tPos.vusS[i] > 0)
		{
			pos = thisInfo->tCoord_local.tPos.tXY[i];

			if(thisInfo->tCoord_local.tPastSentPos.vusS[i] > 0)
				alogorithm_coord_modify_pos_local(&old_pos,&pos);
			else
				alogorithm_coord_modify_pos_local(&pos,&pos);

			distX = pos.x - old_pos.x;
			distY = pos.y - old_pos.y;
			if (distY < 0)
			distY = -distY;
			if (distX < 0)
				distX = -distX;

			if (!thisInfo->tCoord_local.bFirstLongDistanceMoved[i])
				ucMoveTHD = 0;//thisModeConf->ucFirstMoveEventTHD;
			else
				ucMoveTHD = thisModeConf->ucMoveEventTHD;

			if (thisInfo->tCoord_local.tPastSentPos.vusS[i] == 0 || (distY >= ucMoveTHD) || (distX >= ucMoveTHD))
			{
				uSWIPTouchItem_t tItem;
#if USED_SHARP_SPECIFIC_PROTOCOL
				tItem.tItem00.tInfo.b4FingerID = i + 1;					// id
				tItem.tItem00.tInfo.b1Status = TOUCH_STATUS_PRESS;		// status
				tItem.tItem00.tInfo.b6Type = (touchItemType.finger << TOUCH_TYPE_FINGER) |
									  (touchItemType.glove << TOUCH_TYPE_GLOVE) |
									  (touchItemType.hover << TOUCH_TYPE_HOVER) |
									  (touchItemType.passive_stylus << TOUCH_TYPE_PASSIVE_STYLUS) |
									  (touchItemType.active_stylus << TOUCH_TYPE_ACTIVE_STYLUS) |
									  (touchItemType.active_stylus_hover << TOUCH_TYPE_ACTIVE_STYLUS_HOVER);
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.tInfo.bTouch = YES;
				tItem.tItem00.tInfo.bHover = NO;
				tItem.tItem00.tInfo.bScreen = YES;
				tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
				tItem.tItem00.tInfo.b4FingerID = i + 1;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.ucRowStart = currentRowStart;

			//	if(gSensingMode)
				{
					SET_POS(tItem, pos);
				}
				
				tItem.tItem00.ucWidth = thisInfo->tCoord_local.tPos.vusR[i];//thisInfo->tCoord_local.tPos.vusR[i];//MIN(thisInfo->tCoord_local.tPos.vusR[i], UINT8_MAX);

				if(id == 0)
				{
					tItem.tItem00.usStrength = thisInfo->tCoord_local.tPos.vusS[i];
				}
				protocol_swip_PushTouchEvent(&tItem);
				protocol_hid_PushPenEvent(&tItem);

				if (thisInfo->tCoord_local.tPastSentPos.vusS[i] > 0 && ((distY >= ucMoveTHD) || (distX >= ucMoveTHD)) ) //distance moved.
				{
					thisInfo->tCoord_local.bFirstLongDistanceMoved[i] = YES;
				}
				else //1st touch.
				{
					thisInfo->tCoord_local.bFirstLongDistanceMoved[i] = NO;
				}

				thisInfo->tCoord_local.tPastSentPos.tXY[i].x = thisInfo->tCoord_local.tPos.tXY[i].x;
				thisInfo->tCoord_local.tPastSentPos.tXY[i].y = thisInfo->tCoord_local.tPos.tXY[i].y;
				thisInfo->tCoord_local.tPastSentPos.vusS[i] = thisInfo->tCoord_local.tPos.vusS[i];
				thisInfo->tCoord_local.tPastSentPos.vusR[i] = thisInfo->tCoord_local.tPos.vusR[i];
			}
			else
			{
				uSWIPTouchItem_t tItem;
#if USED_SHARP_SPECIFIC_PROTOCOL
				tItem.tItem00.tInfo.b4FingerID = i + 1;					// id
				tItem.tItem00.tInfo.b1Status = TOUCH_STATUS_PRESS;		// status
				tItem.tItem00.tInfo.b6Type = (touchItemType.finger << TOUCH_TYPE_FINGER) |
									  (touchItemType.glove << TOUCH_TYPE_GLOVE) |
									  (touchItemType.hover << TOUCH_TYPE_HOVER) |
									  (touchItemType.passive_stylus << TOUCH_TYPE_PASSIVE_STYLUS) |
									  (touchItemType.active_stylus << TOUCH_TYPE_ACTIVE_STYLUS) |
									  (touchItemType.active_stylus_hover << TOUCH_TYPE_ACTIVE_STYLUS_HOVER);
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.tInfo.bTouch = YES;
				tItem.tItem00.tInfo.bHover = NO;
				tItem.tItem00.tInfo.bScreen = YES;
				tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.tInfo.b4FingerID = i + 1;
				tItem.tItem00.ucRowStart = currentRowStart;
				SET_POS(tItem, old_pos);
				tItem.tItem00.ucWidth = thisInfo->tCoord_local.tPos.vusR[i];//MIN(thisInfo->tCoord_local.tPos.vusR[i], UINT8_MAX);

				if(id == 0)
				{
					tItem.tItem00.usStrength = thisInfo->tCoord_local.tPos.vusS[i];
				}
				protocol_swip_PushTouchEvent(&tItem);
				protocol_hid_PushPenEvent(&tItem);
			}
		}
		else if (thisInfo->tCoord_local.tPastSentPos.vusS[i] > 0)
		{
			#if (SWIP_QUEUE_MODE == 2)
				thisInfo->bTouchOffFlag = 1;
			#endif
			
			uSWIPTouchItem_t tItem;
#if USED_SHARP_SPECIFIC_PROTOCOL
			tItem.tItem00.tInfo.b4FingerID = i + 1;					// id
			tItem.tItem00.tInfo.b1Status = TOUCH_STATUS_RELEASE;		// status
			tItem.tItem00.tInfo.b6Type = (touchItemType.finger << TOUCH_TYPE_FINGER) |
								  (touchItemType.glove << TOUCH_TYPE_GLOVE) |
								  (touchItemType.hover << TOUCH_TYPE_HOVER) |
								  (touchItemType.passive_stylus << TOUCH_TYPE_PASSIVE_STYLUS) |
								  (touchItemType.active_stylus << TOUCH_TYPE_ACTIVE_STYLUS) |
								  (touchItemType.active_stylus_hover << TOUCH_TYPE_ACTIVE_STYLUS_HOVER);
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
			tItem.tItem00.tInfo.bTouch = NO;
			tItem.tItem00.tInfo.bHover = NO;
			tItem.tItem00.tInfo.bScreen = YES;
			tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
			tItem.tItem00.tInfo.b4FingerID = i + 1;
			tItem.tItem00.ucRowStart = 0;
			SET_POS(tItem, old_pos);
			tItem.tItem00.ucWidth = 0;

			if(id == 0)
			{
				tItem.tItem00.usStrength = thisInfo->tCoord_local.tPos.vusS[i];
			}

			thisInfo->tCoord_local.bFirstLongDistanceMoved[i] = NO;

			protocol_swip_PushTouchEvent(&tItem);
			protocol_hid_PushPenEvent(&tItem);
		}
		thisInfo->tCoord_local.tPastSentPos.vusS[i] = thisInfo->tCoord_local.tPos.vusS[i];
	}
	
#if (SWIP_QUEUE_MODE)
	if(thisInfo->bQueueStart == 1){
	#if (SWIP_QUEUE_MODE == 2)
		if(thisInfo->QueueFront == thisInfo->QueueRear || thisInfo->bTouchOffFlag )
	#endif
		{
			thisInfo->QueueRear++;
			thisInfo->QueueRear = (thisInfo->QueueRear) % SWIP_QUEUE_SIZE;
		}
	}
#endif	

	//과거 정보 모두 업데이트.
	thisInfo->tCoord_local.tPastSentPos.sFinger_ = thisInfo->tCoord_local.tPos.sFinger_;
//	thisInfo->bWasPalm = thisInfo->bIsPalm;


	protocol_swip_SendPenEvent();
	//    protocol_hid_SendPenEvent();

#ifdef ADD_PEN
	SendPenData();
#endif

}
#endif

void algorithm_local_process(int mode, ePartialSensing_t Ret)
{
#ifdef CalculateDeltaLocalSearch_OPCODE
	algorithm_local_dsp_process(1, Ret, mode);	
#else
	if(thisModeConf->SensingFilter.ucLocalSearchModeLineFilter == 1)
	{
		algorithm_local_dsp_process(1, Ret, mode);
	}
	else
	{
	#if (USED_DSPA_FUNC_FOR_PEN_SEARCH)
		alogorithm_dspA_get_addr(LOCAL_SEARCH_MODE);
		if(thisModeConf->SensingFilter.ucLocalSearchModeLineFilter == 2)
			alogorithm_local_linefilter_dspA(thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode,LOCAL_SEARCH_MODE);
	#endif

		algorithm_local_baseline_calculate_delta(mode);	
	} 
#endif
}

void algorithm_hover_full_search(ePartialSensing_t Ret)
{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		if(thisPenInfo->bSearch_Mode_Flag == 1 && thisPenInfo->ucSensing_cont_cnt1 > 0)
		{
			thisPenInfo->ucSensing_cont_cnt1++;
			if(thisPenInfo->ucSensing_cont_cnt1 == thisModeConf->PenData.ucKeepProtocolNum)
			{
				thisPenInfo->ucSensing_cont_cnt1 = 0;
				currentRowStart = sensingRowStart = 0;
				hal_Info_SetPenDectionEnable(NO);
				hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_SEARCH_BEACON);
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
				hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_SETTABLE_BEACON);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) */
			}
		}
#endif
	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	#if (UseLastContact3x3 == YES)
	if(thisPenInfo->usSearch_Mode_Cnt < thisModeConf->PenTilt.usReleaseLastContact3x3Frm)
		thisPenInfo->usSearch_Mode_Cnt++;
	else
		pTRingInfo.sLastContact3x3Val = 0;
	#endif
	
	if(thisPenInfo->ucSearch_check_cnt == 0)
	{
		memset(HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), 0, sizeof(FULLHOVERIMAGE));
	}
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	if(thisPenInfo->ucSearch_check_cnt_2 == 0)
	{
		memset(HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR(), 0, sizeof(FULLHOVERIMAGE_2));
	}
#endif
	algorithm_local_process(LOCAL_SEARCH_MODE, Ret);

	if(thisPenInfo->bSearch_Mode_Flag == 1)
	{
		if(protocol_swip_GetLocalIdxFixedEn())
		{
			sensingRowStart = protocol_swip_GetLocalIdx();
		}
		else if(sensingRowStart >= MUX_MAX_ROW)
		{
			sensingRowStart = 0;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
			if(thisPenInfo->ucSearch_check_cnt++ >= thisModeConf->Label.ucHoverInCheckFrm)thisPenInfo->ucSearch_check_cnt=0;
#elif  (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN)
			if(thisPenInfo->ucSearch_check_cnt_2++ >= thisModeConf->Label.ucHoverInCheckFrm)thisPenInfo->ucSearch_check_cnt_2=0;
#else
			if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
			{
				if(thisPenInfo->ucSearch_check_cnt++ >= thisModeConf->Label.ucHoverInCheckFrm)thisPenInfo->ucSearch_check_cnt=0;
			}
			else 
			{
				if(thisPenInfo->ucSearch_check_cnt_2++ >= thisModeConf->Label.ucHoverInCheckFrm)thisPenInfo->ucSearch_check_cnt_2=0;
			}
#endif
		}
		else
		{
			sensingRowStart += PEN_COORD_ROW_MAX;
			if(sensingRowStart > MUX_MAX_ROW)
				sensingRowStart = MUX_MAX_ROW;
		}
	}

	thisPenInfo->ucHover_cnt = 0;
}

bool_t algorithm_mode_change_check(void)
{
	if(thisInfo->bTouchExpect_local == NO)
	{
#if (UseLastContact3x3 == YES)	
		if(thisPenInfo->bPenContact == NO && thisInfo->tCoord_local_dsp.cIsbefor == 0 && (thisModeConf->PenTilt.usUseLastContact3x3Th == 0))
		{
			memset(&thisInfo->tTiltInfo,0,sizeof(thisInfo->tTiltInfo));
			thisInfo->tTiltInfo.sTilt_cnt = 1;
			thisInfo->tTiltInfo.HID_TILT_X = thisInfo->tTiltInfo.Smooth_PastTilt.x = 9000;
			thisInfo->tTiltInfo.HID_TILT_Y = thisInfo->tTiltInfo.Smooth_PastTilt.y = 9000;
		}
#endif		
		if(thisPenInfo->ucSensing_cont_cnt < thisModeConf->PenData.ucSEN_CONT_CNT)
		{
			thisPenInfo->ucSensing_cont_cnt++;
		}
		else
		{
			thisPenInfo->ucHover_cnt = 0;
			thisPenInfo->ucSensing_cont_cnt  = 0;
			currentRowStart = sensingRowStart = 0;
#if USED_ADAPTIVE_LOCAL_SENSING
			sensingRoicStart = ROIC_NUM;
#endif /* USED_ADAPTIVE_LOCAL_SENSING */
			thisPenInfo->bSearch_Mode_Flag = 1;
			thisPenInfo->ucSearch_check_cnt = thisPenInfo->ucSearch_check_cnt_2 = 0;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
			thisPenInfo->ucSensing_cont_cnt1 = 1;
#else
			hal_Info_SetPenDectionEnable(NO);
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
			hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_SEARCH_BEACON);
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_SETTABLE_BEACON);
			algorithm_WGP_Pen_Data_Init();
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_SEARCH_BEACON);
			hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_SETTABLE_BEACON);
			algorithm_WGP_Pen_Data_Init();
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) */
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			memset(LOCALNOISEBUF1,0,sizeof(LOCALNOISEBUF1));
#endif
			memset(RINGDELTAIMAGE,0,sizeof(RINGDELTAIMAGE));
			return YES;
		}
	}
	else
	{
		thisPenInfo->ucSensing_cont_cnt = 0;
	}
	
	return NO;
}

void algorithm_hover_accum_move_1(void)
{
	uint16_t r1,end_r;
    int16_t *psrc;
    int16_t *psrc1;
 //   int sensingRowOffset = currentRowStart - p_currentRowStart;
 
	psrc = &LOCALDELTAIMAGE[0][0];
#if (PAD_ > 0)	
	psrc1 = &DSPATMPDELTA_PAD[0][0];	
#else
	psrc1 = &DSPATMPDELTA[0][0];	
#endif
	
	memcpy(psrc1,psrc,sizeof(LOCALDELTAIMAGE));
	memset(psrc,0,sizeof(LOCALDELTAIMAGE));
	
	r1 = abs(currentRowStart - p_currentRowStart);
	end_r =	PEN_COORD_ROW_MAX - r1;
	
	if(currentRowStart < p_currentRowStart)
	{
		psrc = &LOCALDELTAIMAGE[r1][0];	
	}
	else
	{
#if (PAD_ > 0)	
		psrc1 = &DSPATMPDELTA_PAD[r1][0];	
#else
		psrc1 = &DSPATMPDELTA[r1][0];	
#endif		
	}

#if (PAD_ > 0)
	memcpy(psrc,psrc1,sizeof(int16_t)*end_r*(COL_MAX+2*PAD_));
#else
	memcpy(psrc,psrc1,sizeof(int16_t)*end_r*COL_MAX);
#endif
}

void algorithm_hover_accum_move(void)
{
	int r, c;
	int start_r1, end_r1;
	int start_r2, end_r2;
	int p_current_row;
	
	if(p_currentRowStart > currentRowStart)
	{
		start_r1 = p_currentRowStart - currentRowStart;
		end_r1 = PEN_COORD_ROW_MAX;
		start_r2 = 0;
		end_r2 = start_r1;
		p_current_row = PEN_COORD_ROW_MAX - start_r1;
		
		for(r=end_r1-1; r>=start_r1; r--)
		{
			p_current_row--;
			for(c=0; c<PEN_COORD_COL_MAX; c++)
			{
				HAL_WRITE_LOCAL_DELTA_IMAGE(r,c,HAL_READ_LOCAL_DELTA_IMAGE(p_current_row,c));
//				LOCALNOISEBUF[r][c] = LOCALNOISEBUF[p_current_row][c];
			}
		}
	}
	else
	{
		start_r1 = 0;
		end_r1 = PEN_COORD_ROW_MAX - (currentRowStart - p_currentRowStart);
		start_r2 = end_r1;
		end_r2 = PEN_COORD_ROW_MAX;
		p_current_row = currentRowStart - p_currentRowStart;
		
		for(r=start_r1; r<end_r1; r++)
		{
			for(c=0; c<PEN_COORD_COL_MAX; c++)
			{
				HAL_WRITE_LOCAL_DELTA_IMAGE(r,c,HAL_READ_LOCAL_DELTA_IMAGE(p_current_row,c));
//				LOCALNOISEBUF[r][c] = LOCALNOISEBUF[p_current_row][c];
			}
			p_current_row++;
		}
	}
	
	for(r=start_r2; r<end_r2; r++)
	{
		for(c=0; c<PEN_COORD_COL_MAX; c++)
		{
			HAL_WRITE_LOCAL_DELTA_IMAGE(r,c,0);
//			LOCALNOISEBUF[r][c] = 0;
		}
	}
}

void algorithm_hover_accum_process(void)
{
//	algorithm_coord_initialise_local_pos_buffer();
	algorithm_coord_init_local_DSP();  
#if 1
//	thisInfo->tDelta_local.sPrevMaxDelta2 = 0;
	memset(LOCALDELTAIMAGE,0,sizeof(LOCALDELTAIMAGE));
//	memset(LOCALNOISEBUF,0,sizeof(LOCALNOISEBUF));
	memset(LOCALNOISEBUF1,0,sizeof(LOCALNOISEBUF1));
#else	
#endif
}

eActivePenType_t PreAlgoRawDataType;
void algorithm_param_change_check(void)		
{
//	static eActivePenType_t PreAlgoRawDataType = ACTIVEPEN_TYPE_LOCAL_MS;		//Default type
	
	if(PreAlgoRawDataType != gAlgoRawDataType)
	{
		//Change algorithm param
#if IS_MULTI_PROTOCOL_OPERATION
		if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
		{
			PARAM_SetMode(PARAM_MODE_NORMAL);
		}
		else /* WGP & Wacom */
		{
			PARAM_SetMode(PARAM_MODE_NORMAL_1);
		}
#endif
		PARAM_InitConfig();
		
		algorithm_init_param_dsp_code();
		algorithm_init_param_dsp();
		algorithm_init_param(); // MERGE_CHECK
#if USED_PEN_MODE_OPERATION
		module_init_param();
#endif
#if (USED_DSPA_FUNC_FOR_PEN_SEARCH || USED_DSPA_FUNC_FOR_PEN_LOCAL || USED_DSPA_FUNC_FOR_FINGER)
		algorithm_init_param_dspA();
	#if ((USED_DSPA_FUNC_FOR_PEN_SEARCH || USED_DSPA_FUNC_FOR_PEN_LOCAL) && USED_DSPA_FUNC_FOR_FINGER)
		app_normal_Init_param();
	#endif
#endif
	}
	
	PreAlgoRawDataType = gAlgoRawDataType;
}
#endif /* (USED_PEN_MODE_OPERATION) */
