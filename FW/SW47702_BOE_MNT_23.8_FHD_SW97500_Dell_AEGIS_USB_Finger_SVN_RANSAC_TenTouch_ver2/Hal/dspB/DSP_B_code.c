/****************************************************************************************************//**
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

#include "hal_def.h"
#include "module_def.h"
#include "protocol_def.h"
#include "param_def.h"


#if (USED_PEN_MODE_OPERATION)

static const tAlgorithmCommonConf_t * thisCommonConf = NULL;
static const tAlgorithmModeConf_t * thisModeConf = NULL;
static const tModuleModeConf_t * ptModuleModeConf  = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;

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
//int dbg_dspB_code[2] = {0,};

//static void init_local_DSP(void); // NOTE : 외부에서 참조하는 함수가 아닌 경우.. extern말고 static으로 선언 후 사용하자!!
extern uint16_t * g_pLocalBaseImage;
extern int16_t * g_pFullHoverImage;

void algorithm_local_init(void)
{

	thisCommonConf   = algorithm_GetCommonConfig();
	thisInfo         = algorithm_GetInfo();	
	thisModeConf     = algorithm_GetModeConfig();	
	ptModuleModeConf = module_GetModeConfig();

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN)
	g_pLocalBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR();
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
	
	if(r <= PEN_LOCAL_ROW_HALF_IDX)
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
	int r,c;
	int sum_val = 0;
	
	for(r=calc_pos.r-1; r<=calc_pos.r+1; r++)
	{
		for(c=calc_pos.c-1; c<=calc_pos.c+1; c++)
		{
			if(0 <= r && r < PEN_COORD_ROW_MAX)
			{
				if(0 <= c && c < COL_MAX)
				{
					sum_val += thisInfo->tPenInfo.pTmpModeDeltaImg[(r+PAD_)*(COL_MAX+PAD_+PAD_)+(c+PAD_)];
//					if(mode == 1)
//						sum_val += HAL_READ_RING_DELTA_IMAGE(r,c);
//					else
//						sum_val += HAL_READ_LOCAL_DELTA_IMAGE(r,c);
				}
			}
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
			delta = thisInfo->tPenInfo.pTmpModeDeltaImg[delta_r_pos+c+PAD_];
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
	
	start_r = 0, start_c = MAX(0,thisInfo->tPenInfo.ucCurrentColumnStart-col_search_offset);
	end_r = PEN_COORD_ROW_MAX-1, end_c = MIN(COL_MAX-1,thisInfo->tPenInfo.ucCurrentColumnEnd+col_search_offset);

	thisInfo->tPenInfo.ucCoordiRowStart = local_rs_ring;

	delta_th = thisModeConf->Label.usLocalSeedBase_Ring;
	
	uint8_t ucTmpLocalOvrShift_Ring = ptModuleModeConf->ucLocalOvrShift_Ring;
	

	if(thisInfo->tPenInfo.bPenContact == NO && thisInfo->tPenInfo.bPrevPenContact == NO && thisModeConf->PenTilt.cHoverOverShiftRingOffset != 0)
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

			base_raw_data = thisInfo->tPenInfo.pTmpModeBaseImg[r_pos+c];//HAL_READ_RING_BASELINE_IMAGE(r+local_rs_ring,c);
			
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
			
			if(thisInfo->tPenInfo.bPenContact == NO && thisInfo->tPenInfo.bPrevPenContact == NO && thisModeConf->PenTilt.ucHoverDeltaMul != 0)
				delta = delta*thisModeConf->PenTilt.ucHoverDeltaMul/10;
			
			if(delta < 0) delta = -delta;

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
			thisInfo->tPenInfo.pTmpModeDeltaImg[delta_r_pos+c+PAD_] = delta;
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

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)	
	if(ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType)
#endif
	{
		uint8_t edge_flag = 0;
		edge_flag = algorithm_coord_IsEdgeArea_Cell(thisInfo->tDelta_local.tMaxCellPos.r+local_rs_ring,thisInfo->tDelta_local.tMaxCellPos.c,0);
		if(edge_flag == 0 && (thisModeConf->PenTilt.bTiltBasedRingDelta || thisModeConf->PenTilt.bTiltDirecLimitFilter))
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
		}
	}
#endif

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)	
	if(thisModeConf->PenTilt.ucRingDirecPosCoef > 0 || thisModeConf->PenTilt.bTiltDirecLimitFilter > 0 || thisModeConf->PenTilt.ucTipDirecShiftBasedRingDelta > 0)			
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

int max3x3, prev_max3x3;
void algorithm_Tilt_PreFilter(void)
{
	static tXY_t prev_dist;
	static int prev_max;
	
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
	
	if(thisModeConf->PenTilt.ucTiltDeltaLimitFilter == 1)
	{
//		if(pTRingInfo.sValidMaxVal <= 30)
		if(thisInfo->tDelta_local.iMaxStrength <= 30)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
		}
	
		if(thisInfo->tDelta_local.iMaxStrength > 30 && thisInfo->tDelta_local.iMaxStrength <= 50)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > 12000)thisInfo->tTiltInfo.HID_TILT_X = 12000;
			else if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 6000)thisInfo->tTiltInfo.HID_TILT_X = 6000;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y > 12000)thisInfo->tTiltInfo.HID_TILT_Y = 12000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 6000)thisInfo->tTiltInfo.HID_TILT_Y = 6000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
		}
		else if(thisInfo->tDelta_local.iMaxStrength > 50 && thisInfo->tDelta_local.iMaxStrength <= 120)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > 14000)thisInfo->tTiltInfo.HID_TILT_X = 14000;
			else if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 12000)thisInfo->tTiltInfo.HID_TILT_X = 12000;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 4000)thisInfo->tTiltInfo.HID_TILT_X = 4000;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 6000)thisInfo->tTiltInfo.HID_TILT_X = 6000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y > 14000)thisInfo->tTiltInfo.HID_TILT_Y = 14000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 12000)thisInfo->tTiltInfo.HID_TILT_Y = 12000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 4000)thisInfo->tTiltInfo.HID_TILT_Y = 4000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 6000)thisInfo->tTiltInfo.HID_TILT_Y = 6000;
		}
		else if(thisInfo->tDelta_local.iMaxStrength > 200)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > 9000 && thisInfo->tTiltInfo.HID_TILT_X < 15500)thisInfo->tTiltInfo.HID_TILT_X = 15500;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 9000 && thisInfo->tTiltInfo.HID_TILT_X > 2500)thisInfo->tTiltInfo.HID_TILT_X = 2500;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y > 9000 && thisInfo->tTiltInfo.HID_TILT_Y < 15500)thisInfo->tTiltInfo.HID_TILT_Y = 15500;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 9000 && thisInfo->tTiltInfo.HID_TILT_Y > 2500)thisInfo->tTiltInfo.HID_TILT_Y = 2500;
		}
	}
	else if(thisModeConf->PenTilt.ucTiltDeltaLimitFilter == 2)
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
		
		if(thisInfo->tPenInfo.bUseUseLastContact3x3 == 1 && thisModeConf->PenTilt.usUseLastContact3x3Th > 0 /*&& thisInfo->tTiltInfo.sTilt_cnt == 2 */)
		{
			thisInfo->tPenInfo.bUseUseLastContact3x3 = 0;
			if(pTRingInfo.sLastContact3x3Val != 0)
			{
				max3x3 = (8*pTRingInfo.sLastContact3x3Val + 2*max3x3)/10;
			}
		}
		
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
		if(0)
		{
			if(max_val <= 50 && dist_diff < 100 && min_dist < 100)
			{
				if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
				else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
				
				if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
				else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
			}
			else if(max_val > 50 && max_val <= 90 && dist_diff > 200 && dist_diff < 400)
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
			else if(max_val > 110 && max_val < 150)
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
			else if(max_val >= 150)
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
		else
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
		else if(max_val > thisModeConf->PenTilt.usTiltDeltaLimit_55_TH && max_val < thisModeConf->PenTilt.usTiltDeltaLimit_65_TH && thisModeConf->PenTilt.usTiltDeltaLimit_55_TH)
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
		else if(max_val >= thisModeConf->PenTilt.usTiltDeltaLimit_65_TH && thisModeConf->PenTilt.usTiltDeltaLimit_65_TH)
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
#endif		
		prev_dist.x = dist.x; prev_dist.y = dist.y;
		prev_max = max_val;
		prev_max3x3 = max3x3;
	}
	else if(thisModeConf->PenTilt.ucTiltDeltaLimitFilter > 2)
	{
		if(pTRingInfo.s3x3Val <= thisModeConf->PenTilt.ucTiltDeltaLimitFilter)
		{
			if(thisInfo->tTiltInfo.HID_TILT_X > 10000)thisInfo->tTiltInfo.HID_TILT_X = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_X < 8000)thisInfo->tTiltInfo.HID_TILT_X = 8000;
			
			if(thisInfo->tTiltInfo.HID_TILT_Y > 10000)thisInfo->tTiltInfo.HID_TILT_Y = 10000;
			else if(thisInfo->tTiltInfo.HID_TILT_Y < 8000)thisInfo->tTiltInfo.HID_TILT_Y = 8000;
		}
	}

//#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
//	if(thisInfo->tDelta_local.iMaxStrength > thisModeConf->PenTilt.ucHighDelta_TiltSmooth_change_Th && thisModeConf->PenTilt.ucHighDelta_TiltSmooth_change_Th)
//#else
//	if(pTRingInfo.s3x3Val > thisModeConf->PenTilt.ucHighDelta_TiltSmooth_change_Th*10 && thisModeConf->PenTilt.ucHighDelta_TiltSmooth_change_Th)
//#endif
//	{
//		if(thisInfo->tTiltInfo.sTilt_cnt >= 10 && (thisInfo->tPenInfo.bPenContact || thisInfo->tPenInfo.bPrevPenContact))
//			thisInfo->tTiltInfo.SmoothingCoefChange = 1;
//	}
	
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
		if((thisInfo->tPenInfo.bPenContact || thisInfo->tPenInfo.bPrevPenContact))
		{
			thisInfo->tTiltInfo.SmoothingCoefChange = 1;
		}
	}
	
	PastTilt.x = thisInfo->tTiltInfo.HID_TILT_X;
	PastTilt.y = thisInfo->tTiltInfo.HID_TILT_Y;
}
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
				
				thisInfo->tPenInfo.s_search_max_delta[i] = thisInfo->tDelta_local.iMaxStrength;					
				thisInfo->tPenInfo.s_search_min_delta[i] = thisInfo->tDelta_local.iMinStrength;				
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
						read_raw_data = thisInfo->tPenInfo.pTmpModeRawImg[raw_r_pos+c];
//#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) 
//						read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+raw_idx, c);
//#else
//						read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+raw_idx, c);
//#endif
						delta = (signed)g_pLocalBaseImage[r_pos + c] - (signed)read_raw_data;
			
#ifdef FingerAreaPenDeltaDelete
						if(thisModeConf->BaseLine.cFingerAreaPenDeltaDelete != 0)// && thisInfo->tDelta.iMaxStrength > thisModeConf->Label.usSeedBase)
						{
	//						if(LOCALFINGERAREA[r+local_rs][c] > 0)
							if(thisInfo->tPenInfo.LocalFingerArea.rs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= r+local_rs
							&& thisInfo->tPenInfo.LocalFingerArea.re + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= r+local_rs
							&& thisInfo->tPenInfo.LocalFingerArea.cs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= c
							&& thisInfo->tPenInfo.LocalFingerArea.ce + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= c)
							{						
								delta = 0;
							}
						}	
#endif
						if(delta > thisInfo->tPenInfo.s_search_max_delta[i])
						{
							thisInfo->tPenInfo.s_search_max_delta[i] = delta;
						}
						
						if(delta < thisInfo->tPenInfo.s_search_min_delta[i])
						{
							thisInfo->tPenInfo.s_search_min_delta[i] = delta;
						}
					}
				}
			}
			
			if(thisInfo->tPenInfo.s_search_max_delta[i] < -thisInfo->tPenInfo.s_search_min_delta[i] )
				thisInfo->tPenInfo.bPen_phase[i] = 1;
#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN) 			
			if(g_RetVal != PARTIAL_PEN_COORD1)
			{
				if(thisInfo->tPenInfo.s_search_max_delta[i] < -thisInfo->tPenInfo.s_search_min_delta[i] && -thisInfo->tPenInfo.s_search_min_delta[i] > min_delta_th)
				{
					thisInfo->tPenInfo.bMS_Contact2bit[i] = 1;
				}
				else
				{
					thisInfo->tPenInfo.bMS_Contact2bit[i] = 0;
				}
			}
#endif
		}
		
		if(g_RetVal != PARTIAL_PEN_COORD1)
		{
			if(thisInfo->tPenInfo.bMS_Contact2bit[0] == 0 && thisInfo->tPenInfo.bMS_Contact2bit[1] == 0)
			{
				if(thisInfo->tPenInfo.bPenContact)pTRingInfo.sLastContact3x3Val = pTRingInfo.s3x3Val;
			}
		}
		
#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN) 		
		if(thisModeConf->BaseLine.ucPP_MUX_Select && shift_idx == 0)
		{
			bool_t tmp_phase = thisInfo->tPenInfo.bPen_phase[0];
			thisInfo->tPenInfo.bPen_phase[0] = thisInfo->tPenInfo.bPen_phase[1];
			thisInfo->tPenInfo.bPen_phase[1] = tmp_phase;
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
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	#if (USED_ROIC_DEF == ROIC_SWL92406)	
	thisInfo->PenCalcDeltaSetVal.min_delta_th = thisModeConf->BaseLine.usMS_ContactTh_HoverMode;
	#endif
#endif
	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	thisInfo->tPenInfo.bPen_phase[0] = thisInfo->tPenInfo.bPen_phase[1] = 0;
	thisInfo->tPenInfo.s_search_max_delta[0] = thisInfo->tPenInfo.s_search_max_delta[1] = 0;
	thisInfo->tPenInfo.s_search_min_delta[0] = thisInfo->tPenInfo.s_search_min_delta[1] = 0;
	thisInfo->PenCalcDeltaSetVal.pen_touch_data = 0;
#endif
	
#if (ADAPTOR_NOISE_ALGO_EN)
	if(thisInfo->tPenInfo.bAdaptorNoise == 1)
	{
		thisInfo->tPenInfo.bAdaptorNoise = NO;	
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

	thisInfo->tPenInfo.ucCoordiRowStart = thisInfo->PenCalcDeltaSetVal.local_rs;
	thisInfo->tPenInfo.ucCoordiColumnStart = thisInfo->PenCalcDeltaSetVal.local_cs;

	thisInfo->PenCalcDeltaSetVal.start_r = 0, thisInfo->PenCalcDeltaSetVal.start_c = 0;
	thisInfo->PenCalcDeltaSetVal.end_r = PEN_COORD_ROW_MAX, thisInfo->PenCalcDeltaSetVal.end_c = COL_MAX;
	
	memset((void *)(&thisInfo->tDelta_local), 0x00, sizeof(tOrigDeltaInfo_t));
	thisInfo->tDelta_local.tValidRect.cs = COL_MAX - 1; thisInfo->tDelta_local.tValidRect.ce = 0;
	thisInfo->tDelta_local.tValidRect.rs = ROW_MAX - 1; thisInfo->tDelta_local.tValidRect.re = 0;

    thisInfo->PenCalcDeltaSetVal.MuxSum = 0;

	if(thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode == YES)
		thisInfo->PenCalcDeltaSetVal.MuxSum=1;
	
#ifdef FingerAreaLineFilter
	algorithm_noise_FingerAreaLineFilter(thisInfo->tPenInfo.start_r,thisInfo->tPenInfo.end_r,thisInfo->tPenInfo.start_c,thisInfo->tPenInfo.end_c,local_rs,MuxSum);
#endif

#if (USED_ROIC_DEF != ROIC_SWL92406)
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	algorithm_Cal_MS_phase(thisInfo->PenCalcDeltaSetVal.start_r,thisInfo->PenCalcDeltaSetVal.end_r,thisInfo->PenCalcDeltaSetVal.start_c,thisInfo->PenCalcDeltaSetVal.end_c,mode,thisInfo->PenCalcDeltaSetVal.local_rs);
	#endif 
#endif 

	if(thisInfo->tPenInfo.bPenContact)
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
	thisInfo->PenCalcDeltaSetVal.bMS_phase = thisInfo->tPenInfo.bPen_phase[0];
	thisInfo->PenCalcDeltaSetVal.bMS_Contact2bit[0] = thisInfo->tPenInfo.bMS_Contact2bit[0];
	thisInfo->PenCalcDeltaSetVal.bMS_Contact2bit[1] = thisInfo->tPenInfo.bMS_Contact2bit[1];
	thisInfo->PenCalcDeltaSetVal.LocalFingerArea.rs = thisInfo->tPenInfo.LocalFingerArea.rs;
	thisInfo->PenCalcDeltaSetVal.LocalFingerArea.re = thisInfo->tPenInfo.LocalFingerArea.re;
	thisInfo->PenCalcDeltaSetVal.LocalFingerArea.cs = thisInfo->tPenInfo.LocalFingerArea.cs;
	thisInfo->PenCalcDeltaSetVal.LocalFingerArea.ce = thisInfo->tPenInfo.LocalFingerArea.ce;
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
		thisInfo->tPenInfo.bSearch_Mode_Flag = 0;
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
        if(thisModeConf->Noise.bPenPosSymbolRepeatCheck == 1 && gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisInfo->tPenInfo.bAdaptorNoise) // MS PenLHB Noise By LocalFinger : 6 Symbol Repeat Check , hanch
        {
            thisInfo->PenCalcDeltaSetVal.ucAdaptorNoise_CalDeltaRepeatSimbol++;						
            if(thisInfo->PenCalcDeltaSetVal.ucAdaptorNoise_CalDeltaRepeatSimbol>6)
            {
                thisInfo->PenCalcDeltaSetVal.ucAdaptorNoise_CalDeltaRepeatSimbol = 0;
                thisInfo->tPenInfo.bPosUpdateSkip = 1;
                thisInfo->tPenInfo.bReportSkip = 1;
            }
        }
        else 
            thisInfo->PenCalcDeltaSetVal.ucAdaptorNoise_CalDeltaRepeatSimbol = 0;
#endif
    }
#if ADAPTOR_NOISE_ALGO_EN  
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisInfo->tPenInfo.bAdaptorNoise)
	{
		if((abs(thisInfo->tDelta_local.tMaxCellPos.r - thisInfo->tPenInfo.cPreMaxR) > 1 || abs(thisInfo->tDelta_local.tMaxCellPos.c - thisInfo->tPenInfo.cPreMaxC) > 1))
		{
			thisInfo->tPenInfo.bPosUpdateSkip = 1;
			thisInfo->tPenInfo.bReportSkip = 1;
		}
	}
#endif	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
	{
	#if ADAPTOR_NOISE_ALGO_EN
		if(thisInfo->tPenInfo.bAdaptorNoise==1)
		{
			thisInfo->tPenInfo.ucTmpForcePenContact_NUM = 10;
		}		
	#endif		
		if(thisInfo->tPenInfo.bAdaptorNoise == 0)
			thisInfo->tPenInfo.ucTmpForcePenContact_NUM = thisModeConf->PenData.ucForcePenContact_NUM;
		
		if(g_RetVal != PARTIAL_PEN_COORD1)
		{	
			if(thisInfo->tPenInfo.bMS_Contact2bit[0] == 1 && thisInfo->tPenInfo.bMS_Contact2bit[1] == 1 &&(thisInfo->bLocal_sensing))
			{
				thisInfo->tPenInfo.bPenContact = YES;
				thisInfo->ucContact_MS = thisInfo->tPenInfo.ucTmpForcePenContact_NUM;
			}
			// slim pen contact loss issue when side button keeping drawing 
			else if(g_RetVal == PARTIAL_PEN_COORD2 && thisInfo->tPenInfo.bPen_button[1] == 1 && thisInfo->tPenInfo.bMS_Contact2bit[1] == 1 && thisInfo->bLocal_sensing)
			{
				thisInfo->tPenInfo.bPenContact = YES;
			}
			// hanch
			else if(thisInfo->ucContact_MS > 0)
			{
				thisInfo->tPenInfo.bPenContact = YES;
				thisInfo->ucContact_MS--;
			}
			else
			{
				thisInfo->ucContact_MS = 0;
				thisInfo->tPenInfo.bPenContact = NO;
			}
			thisInfo->tPenInfo.bPenContactConti = thisInfo->tPenInfo.bPenContact;
		}
		else
			thisInfo->tPenInfo.bPenContact = thisInfo->tPenInfo.bPenContactConti;
	}
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)	
	#if AbnormalContactRemove_EN
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP)
	{
		if(thisModeConf->PenData.ucAbnormalContactRemovePressureTH1	> 0 && thisModeConf->PenData.ucAbnormalContactRemovePressureTH2 > 0)	
		{
			thisInfo->tPenInfo.bEdgeAbnormalContact = 0;
			if(thisInfo->PenCalcDeltaSetVal.pen_pos.r == 0 || thisInfo->PenCalcDeltaSetVal.pen_pos.r == ROW_MAX-1 || thisInfo->PenCalcDeltaSetVal.pen_pos.c == 0 || thisInfo->PenCalcDeltaSetVal.pen_pos.c == COL_MAX-1)thisInfo->tPenInfo.bEdgeAbnormalContact = 1;
			if( (thisInfo->tPenInfo.bPenContact == YES) && thisInfo->tPenInfo.bEdgeAbnormalContact == 1)
			{
				uint8_t ucDeltaSub1Th = thisModeConf->PenData.ucAbnormalContactRemoveDeltaTH1; //17;
				uint8_t ucDeltaSub2Th = thisModeConf->PenData.ucAbnormalContactRemoveDeltaTH2; //30;
			
				if(thisInfo->tPenInfo.bPenOffChk == 1)
				{
					if(thisInfo->tPenInfo.sPrevContactMaxDelta[0] - thisInfo->PenCalcDeltaSetVal.pen_touch_data > ucDeltaSub1Th)
						thisInfo->tPenInfo.bPenContact = NO;
					else if(thisInfo->tPenInfo.sPrevContactMaxDelta[1] - thisInfo->PenCalcDeltaSetVal.pen_touch_data > ucDeltaSub2Th)
						thisInfo->tPenInfo.bPenContact = NO;
				}

				thisInfo->tPenInfo.sPrevContactMaxDelta[1] = thisInfo->tPenInfo.sPrevContactMaxDelta[0];
				thisInfo->tPenInfo.sPrevContactMaxDelta[0] = thisInfo->PenCalcDeltaSetVal.pen_touch_data;
			}
			else
			{
				thisInfo->tPenInfo.sPrevContactMaxDelta[1] = 0;
				thisInfo->tPenInfo.sPrevContactMaxDelta[0] = 0;
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
	thisInfo->tPenInfo.bPen_phase[0] = thisInfo->tPenInfo.bPen_phase[1] = 0;
	thisInfo->tPenInfo.s_search_max_delta[0] = thisInfo->tPenInfo.s_search_max_delta[1] = 0;
	thisInfo->tPenInfo.s_search_min_delta[0] = thisInfo->tPenInfo.s_search_min_delta[1] = 0;
#endif

	uint8_t ucPen_th1 = thisModeConf->Label.ucLocalPenDetectTH1;
	uint8_t ucPen_th2 = thisModeConf->Label.ucLocalPenDetectTH2;

#if (CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP && CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
	uint8_t tmpSearchNoiseRejectFrm = thisModeConf->Noise.ucSearchNoiseRejectFrm;
#endif
	
#if (ADAPTOR_NOISE_ALGO_EN)
	if(thisInfo->tPenInfo.bAdaptorNoise == 1)
	{
		if(thisInfo->bTouchExpect == NO || mode != LOCAL_MODE)
		{
			thisInfo->tPenInfo.bAdaptorNoise = NO;	
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

	thisInfo->tPenInfo.ucCoordiRowStart = local_rs;
	thisInfo->tPenInfo.ucCoordiColumnStart = local_cs;

	start_r = 0, start_c = 0;
	end_r = PEN_COORD_ROW_MAX, end_c = COL_MAX;
#if USED_PANEL_HV60x34_SIZE
	if(local_rs == 30)end_r = PEN_COORD_ROW_MAX-1;
#endif	
	memset((void *)(&thisInfo->tDelta_local), 0x00, sizeof(tOrigDeltaInfo_t));
	thisInfo->tDelta_local.tValidRect.cs = COL_MAX - 1; thisInfo->tDelta_local.tValidRect.ce = 0;
	thisInfo->tDelta_local.tValidRect.rs = ROW_MAX - 1; thisInfo->tDelta_local.tValidRect.re = 0;

	if(mode != LOCAL_SEARCH_MODE)
	{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
		start_c = MAX(0,thisInfo->tPenInfo.ucCurrentColumnStart-4);
		end_c = MIN(COL_MAX,thisInfo->tPenInfo.ucCurrentColumnEnd+5);
#else
		start_c = thisInfo->tPenInfo.ucCurrentColumnStart;
		end_c = MIN(COL_MAX,thisInfo->tPenInfo.ucCurrentColumnEnd+1);
#endif
	}
	
#if USED_ADAPTIVE_LOCAL_SENSING
	if(sensingRoicStart != ROIC_NUM)
	{
		start_c = 6*sensingRoicStart;
		end_c = start_c + 2*ROIC_COL_SIZE;
	}
#endif /* USED_ADAPTIVE_LOCAL_SENSING */

	uint16_t * pBaseImage = g_pLocalBaseImage;

#if (CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP && CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
	bool_t MuxSum = 0;
	if(mode == LOCAL_SEARCH_MODE)
	{
		//if(thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode == YES)
			MuxSum=thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode;
	}
	else
	{
		//if(thisModeConf->BaseLine.b2MUX_SUM_LocalMode == 1)
			MuxSum=thisModeConf->BaseLine.b2MUX_SUM_LocalMode;
	}
#endif
	
#ifdef FingerAreaLineFilter
	algorithm_noise_FingerAreaLineFilter(start_r,end_r,start_c,end_c,local_rs,MuxSum);
#endif

#if (USED_ROIC_DEF != ROIC_SWL92406)
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	if(mode != LOCAL_SEARCH_MODE)
		algorithm_Cal_MS_phase(start_r,end_r,start_c,end_c,mode,local_rs);
	#else
	algorithm_Cal_MS_phase(start_r,end_r,start_c,end_c,mode,local_rs);
	#endif
#endif 
#endif 

	if(thisInfo->tPenInfo.bPenContact)
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
#if (CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP && CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
	uint8_t MuxSum_raw_idx = 0;
	uint8_t base_idx = 0;
	
	if(thisModeConf->BaseLine.ucPP_MUX_Select)
	{
		raw_idx = PEN_COORD_ROW_MAX;
		if(thisModeConf->BaseLine.bPen_2BASE)base_idx = ROW_MAX;
	}
		
	uint8_t MuxSum_base_idx = 0;
	if(MuxSum)
	{
		if(thisModeConf->BaseLine.ucPP_MUX_Select == 0)
		{
			MuxSum_raw_idx = PEN_COORD_ROW_MAX;
			if(thisModeConf->BaseLine.bPen_2BASE)MuxSum_base_idx = ROW_MAX;
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
#if !(USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
				int MuxSum_raw_r_pos = (r+MuxSum_raw_idx)*COL_MAX;
#endif
				int delta_r_pos = (r+PAD_)*(COL_MAX+PAD_+PAD_);
				for( c=start_c; c<end_c; c++ )
				{
					read_raw_data = thisInfo->tPenInfo.pTmpModeRawImg[raw_r_pos+c];

#if (USED_ROIC_DEF != ROIC_SWL92406)
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL ==PEN_PROTOCOL_MSnWGP_PEN)
					if(thisInfo->tPenInfo.bPen_phase[0] == 1)
					{
						delta = (signed)read_raw_data - (signed)pBaseImage[r_pos+base_idx_r_pos + c];
					}
					else
	#endif
#endif
					{
						delta = (signed)pBaseImage[r_pos+base_idx_r_pos + c] - (signed)read_raw_data;
					}
					
#ifdef FingerAreaPenDeltaDelete					
					if(thisModeConf->BaseLine.cFingerAreaPenDeltaDelete != 0)
					{
						if(thisInfo->tPenInfo.LocalFingerArea.rs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= r+local_rs
						&& thisInfo->tPenInfo.LocalFingerArea.re + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= r+local_rs
						&& thisInfo->tPenInfo.LocalFingerArea.cs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= c
						&& thisInfo->tPenInfo.LocalFingerArea.ce + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= c)
						{						
							delta = 0;
						}
					}
#endif
		
#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
					read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r+PEN_COORD_ROW_MAX, c);
					delta2 = (signed)pBaseImage[r_pos+MuxSum_base_idx_r_pos + c] - (signed)read_raw_data;
					if((thisInfo->tPenInfo.bPen_phase[1]==1 && mode == LOCAL_MODE) || (delta2 < 0 && delta > 0 && mode == LOCAL_HOVER_MODE))
						delta2=-delta2;		
					
					delta += delta2;
#else
					if(MuxSum)
					{
						read_raw_data = thisInfo->tPenInfo.pTmpModeRawImg[MuxSum_raw_r_pos+c];
						
						delta2 = (signed)pBaseImage[r_pos+MuxSum_base_idx_r_pos + c] - (signed)read_raw_data;
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL ==PEN_PROTOCOL_MSnWGP_PEN)
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL ==PEN_PROTOCOL_MSnWGP_PEN)
						if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
		#endif
							if(thisInfo->tPenInfo.bPen_phase[1]==1)
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

#if (ADAPTOR_NOISE_ALGO_EN)
					if( (mode == LOCAL_HOVER_MODE || mode == LOCAL_SEARCH_MODE) && 
						((gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisInfo->tPenInfo.bMS_Contact2bit[0] == 0)
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
							delta2 = thisInfo->tPenInfo.pTmpModeDeltaImg[(temp_r+PAD_)*(COL_MAX+PAD_+PAD_)+(c+PAD_)];//HAL_READ_LOCAL_DELTA_IMAGE(temp_r, c);
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
								if(thisInfo->tPenInfo.LocalFingerArea.rs - thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc <= r+local_rs
								&& thisInfo->tPenInfo.LocalFingerArea.re + thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc >= r+local_rs
								&& thisInfo->tPenInfo.LocalFingerArea.cs - thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc <= c
								&& thisInfo->tPenInfo.LocalFingerArea.ce + thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc >= c)
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
								thisInfo->tPenInfo.bAdaptorNoise = YES;
							}
						}
					}
#endif
					thisInfo->tPenInfo.pTmpModeDeltaImg[delta_r_pos+c+PAD_] = delta;
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
				thisInfo->tPenInfo.bSearch_Mode_Flag = 0;
				hal_Info_SetPenDectionEnable(YES);
				
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
				hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_PEN_BEACON);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
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
#if ADAPTOR_NOISE_ALGO_EN
			if(thisModeConf->Noise.bPenPosSymbolRepeatCheck == 1 && gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisInfo->tPenInfo.bAdaptorNoise) // MS PenLHB Noise By LocalFinger : 6 Symbol Repeat Check , hanch
			{
				ucAdaptorNoise_CalDeltaRepeatSimbol++;						
				if(ucAdaptorNoise_CalDeltaRepeatSimbol>6)
				{
					ucAdaptorNoise_CalDeltaRepeatSimbol = 0;
					thisInfo->tPenInfo.bPosUpdateSkip = 1;
					thisInfo->tPenInfo.bReportSkip = 1;
				}
			}
			else 
				ucAdaptorNoise_CalDeltaRepeatSimbol = 0;
#endif
		}
	}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	#if ADAPTOR_NOISE_ALGO_EN
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisInfo->tPenInfo.bAdaptorNoise)
	{
		if((abs(thisInfo->tDelta_local.tMaxCellPos.r - thisInfo->tPenInfo.cPreMaxR) > 1 || abs(thisInfo->tDelta_local.tMaxCellPos.c - thisInfo->tPenInfo.cPreMaxC) > 1))
		{
			thisInfo->tPenInfo.bPosUpdateSkip = 1;
			thisInfo->tPenInfo.bReportSkip = 1;
		}
	}
	#endif			
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
	{
	#if ADAPTOR_NOISE_ALGO_EN
		if(thisInfo->tPenInfo.bAdaptorNoise==1)
		{
			thisInfo->tPenInfo.ucTmpForcePenContact_NUM = 10;
		}
		else
	#endif	
			thisInfo->tPenInfo.ucTmpForcePenContact_NUM = thisModeConf->PenData.ucForcePenContact_NUM;
		
		if(g_RetVal != PARTIAL_PEN_COORD1)
		{	
			if(thisInfo->tPenInfo.bMS_Contact2bit[0] == 1 && thisInfo->tPenInfo.bMS_Contact2bit[1] == 1 &&(thisInfo->bLocal_sensing))
			{
				thisInfo->tPenInfo.bPenContact = YES;
				thisInfo->ucContact_MS = thisInfo->tPenInfo.ucTmpForcePenContact_NUM;
			}
			// slim pen contact loss issue when side button keeping drawing 
			else if(g_RetVal == PARTIAL_PEN_COORD2 && thisInfo->tPenInfo.bPen_button[1] == 1 && thisInfo->tPenInfo.bMS_Contact2bit[1] == 1 && thisInfo->bLocal_sensing)
			{
				thisInfo->tPenInfo.bPenContact = YES;
			}
			// hanch
			else if(thisInfo->ucContact_MS > 0)
			{
				thisInfo->tPenInfo.bPenContact = YES;
				thisInfo->ucContact_MS--;
			}
			else
			{
				thisInfo->ucContact_MS = 0;
				thisInfo->tPenInfo.bPenContact = NO;
			}
			thisInfo->tPenInfo.bPenContactConti = thisInfo->tPenInfo.bPenContact;
		}
		else
			thisInfo->tPenInfo.bPenContact = thisInfo->tPenInfo.bPenContactConti;
	}
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)	
	#if AbnormalContactRemove_EN
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP)
	{
		if(thisModeConf->PenData.ucAbnormalContactRemovePressureTH1	> 0 && thisModeConf->PenData.ucAbnormalContactRemovePressureTH2 > 0)	
		{
			thisInfo->tPenInfo.bEdgeAbnormalContact = 0;
			if(pen_pos.r == 0 || pen_pos.r == ROW_MAX-1 || pen_pos.c == 0 || pen_pos.c == COL_MAX-1)thisInfo->tPenInfo.bEdgeAbnormalContact = 1;
			if( (thisInfo->tPenInfo.bPenContact == YES) && thisInfo->tPenInfo.bEdgeAbnormalContact == 1)
			{
				uint8_t ucDeltaSub1Th = thisModeConf->PenData.ucAbnormalContactRemoveDeltaTH1; //17;
				uint8_t ucDeltaSub2Th = thisModeConf->PenData.ucAbnormalContactRemoveDeltaTH2; //30;
			
				if(thisInfo->tPenInfo.bPenOffChk == 1)
				{
					if(thisInfo->tPenInfo.sPrevContactMaxDelta[0] - pen_touch_data > ucDeltaSub1Th)
						thisInfo->tPenInfo.bPenContact = NO;
					else if(thisInfo->tPenInfo.sPrevContactMaxDelta[1] - pen_touch_data > ucDeltaSub2Th)
						thisInfo->tPenInfo.bPenContact = NO;
				}

				thisInfo->tPenInfo.sPrevContactMaxDelta[1] = thisInfo->tPenInfo.sPrevContactMaxDelta[0];
				thisInfo->tPenInfo.sPrevContactMaxDelta[0] = pen_touch_data;
			}
			else
			{
				thisInfo->tPenInfo.sPrevContactMaxDelta[1] = 0;
				thisInfo->tPenInfo.sPrevContactMaxDelta[0] = 0;
			}
		}
	}
	#endif
#endif
	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	#ifdef TILT_ON
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && mode == LOCAL_SEARCH_MODE)// && thisModeConf->PenTilt.bRingBaseTracking)
	{
		if(/*g_RetVal == PARTIAL_PEN_COORD1 ||*/ g_RetVal == PARTIAL_PEN_COORD3)
			algorithm_baseline_tracking_continuous_local_ring();//algorithm_local_RingMS_delta_coordi(mode);
	}
	#endif
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && mode != LOCAL_SEARCH_MODE)  //MS_Pressure_Last_Bit, hanch
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

	start_r = 0, start_c = thisInfo->tPenInfo.ucCurrentColumnStart;
	end_r = PEN_COORD_ROW_MAX, end_c = thisInfo->tPenInfo.ucCurrentColumnEnd; //end_c = local_cs+8;

	int16_t pendata_min[8] = { 0, };
	int16_t pendata_max[8] = { 0, };
		
	if(thisInfo->tPenInfo.bSearch_Mode_Flag == 0)
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
						if(thisInfo->tPenInfo.LocalFingerArea.rs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= r+local_rs
						&& thisInfo->tPenInfo.LocalFingerArea.re + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= r+local_rs
						&& thisInfo->tPenInfo.LocalFingerArea.cs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= c
						&& thisInfo->tPenInfo.LocalFingerArea.ce + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= c)
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
				thisInfo->tPenInfo.us_pendata_pressure = 0;
				for (r = 0; r < 6; r++)
				{
					if (data_store_bit[store_row][r] == 1)
						thisInfo->tPenInfo.us_pendata_pressure += (1 << (5 - r));
				}
				thisInfo->tPenInfo.us_pendata_pressure = (thisInfo->tPenInfo.us_pendata_pressure * 4095) / 63;
				
			}
				break;

			case PARTIAL_PEN_DATA3:
			{
				if(thisInfo->tPenInfo.bSearch_Mode_Flag == 0)
					thisInfo->tPenInfo.bReportEraser = 1;
				
				if(data_store_bit[store_row][0] == 0 && data_store_bit[store_row][1] == 1)
					thisInfo->tPenInfo.bPen_button[1] = 1;
				else
					thisInfo->tPenInfo.bPen_button[1] = 0;
				
				if(data_store_bit[store_row][0] == 1 && data_store_bit[store_row][1] == 0)
					thisInfo->tPenInfo.bPen_button[0] = 1;
				else
					thisInfo->tPenInfo.bPen_button[0] = 0;
				
				//For Win10 Invert button test, high hover side button reject, hanch, 200811
				if(thisInfo->tPenInfo.bPen_button[1] == 1 && pendata_min[0] + pendata_max[1] < thisModeConf->PenData.usPenDataHighHoverButtonRejectTHD)
				{
					thisInfo->tPenInfo.bPen_button[1] = 0;
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
	if(thisInfo->tPenInfo.bAdaptorNoise)
	{
		thisInfo->tPenInfo.bPen_button[0] = thisInfo->tPenInfo.bPre_pen_button[0];
		thisInfo->tPenInfo.bPen_button[1] = thisInfo->tPenInfo.bPre_pen_button[1];
		thisInfo->tPenInfo.us_pendata_pressure = thisInfo->tPenInfo.us_pre_pendata_pressure;
	}
#endif	
	thisInfo->tPenInfo.us_pre_pendata_pressure = thisInfo->tPenInfo.us_pendata_pressure;
	thisInfo->tPenInfo.bPre_pen_button[0] = thisInfo->tPenInfo.bPen_button[0];
	thisInfo->tPenInfo.bPre_pen_button[1] = thisInfo->tPenInfo.bPen_button[1];

	return 0; 
}
#endif /* (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN) */
#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)
extern int HID_PEN_X;
extern int HID_PEN_Y;
bool_t algorithm_local_data_baseline_calculate_delta_WACOM(uint32_t ulIRQType, uint32_t ulSensingRowStart)
{
	static int16_t hover_base = 0;
	int i, r, c;
	int delta;
	int start_r, end_r;
	int start_c, end_c;
	int local_rs, local_cs;
	uint16_t read_raw_data;
    int PenDataLocalTHD = thisModeConf->PenData.ucPenDataLocalTHD;
	static int16_t hover_data_store_bit[7] = {0,};
	static bool_t contact1 = 0;
	static bool_t contact2 = 0;
	static int8_t DataForcePenContact = 0;

//	bool_t line_on = 0;
//	int line_max[4];

	int store_row = (ulIRQType - PARTIAL_PEN_DATA1);
//	int store_row = (RetVal - PARTIAL_PEN_DATA1);

	local_rs = currentRowStart;
//	local_rs = (currentRowStart>>1);
	local_cs = thisInfo->tPenInfo.ucCurrentColumnStart;

	start_r = 0, start_c = local_cs;
	end_r = PEN_COORD_ROW_MAX, end_c = thisInfo->tPenInfo.ucCurrentColumnEnd + 1; //end_c = local_cs+8;

	int16_t pendata_min[8] = { 0, };
	int16_t pendata_max[8] = { 0, };
#if ADAPTOR_NOISE_ALGO_EN
	tCell_t pendata_min_pos[8] = { 0, };
	tCell_t pendata_max_pos[8] = { 0, };
	static uint8_t prev_contactNoise = 1;
	tCell_t pendata_select_pos[8] = { 0, };
	uint8_t pendata_select_cnt[8] = { 0, };
	int pendata_nonpassive_num = 0;
#endif

	{
		for(r = start_r; r < end_r; r++)
		{
			for(c = start_c; c < end_c; c++)
			{
				if((LOCALNOISEBUF1[r+local_rs][c] <  thisModeConf->Noise.ucHoverNoiseRejectFrm && thisInfo->tPenInfo.bPenContact == NO) && thisInfo->tPenInfo.ucHover_cnt >=  thisModeConf->Noise.ucHoverNoiseRejectFrm)
					continue;
				
				for(i = 0; i < 8; i++)
				{
					{
						read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE_2(r+PEN_COORD_ROW_MAX*i, c);

						delta = 128 - (signed)read_raw_data;
					}

#ifdef FingerAreaPenDeltaDelete					
					if(thisModeConf->BaseLine.cFingerAreaPenDeltaDelete != 0)
					{
//						if(LOCALFINGERAREA[r+local_rs][c] > 0)
						if(thisInfo->tPenInfo.LocalFingerArea.rs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= r+local_rs
						&& thisInfo->tPenInfo.LocalFingerArea.re + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= r+local_rs
						&& thisInfo->tPenInfo.LocalFingerArea.cs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= c
						&& thisInfo->tPenInfo.LocalFingerArea.ce + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= c)
						{						
							delta = 0;
						}
					}
#endif
					
					if(delta < pendata_min[i])
					{
#if ADAPTOR_NOISE_ALGO_EN
						pendata_min_pos[i].r = r;
						pendata_min_pos[i].c = c;
#endif
						pendata_min[i] = delta;
					}
					if(delta > pendata_max[i])
					{
#if ADAPTOR_NOISE_ALGO_EN
						pendata_max_pos[i].r = r;
						pendata_max_pos[i].c = c;
#endif
						pendata_max[i] = delta;
					}
					hover_data_store_bit[store_row] += delta;
				}
			}
		}
	}

	{
		for(c = 0; c < 8; c++)
		{
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
            if( (c < 2 && store_row < 4 && store_row != 2) && (HID_PEN_X > 0 && HID_PEN_X < 32767 && HID_PEN_Y > 0 && HID_PEN_Y < 32767) )
                PenDataLocalTHD = (thisModeConf->PenData.ucPenDataLocalTHD >> 1);
            else
                PenDataLocalTHD = thisModeConf->PenData.ucPenDataLocalTHD;
#endif
			pendata_min[c] = -pendata_min[c];
			if((pendata_min[c] > pendata_max[c]) && (pendata_min[c] > PenDataLocalTHD))
			{
				data_store_bit[store_row][c] = 1;
#if ADAPTOR_NOISE_ALGO_EN
				pendata_nonpassive_num++;
				pendata_select_pos[c] = pendata_min_pos[c];
#endif
			}
			else if((pendata_min[c] <= pendata_max[c]) && (pendata_max[c] > PenDataLocalTHD))
			{
				data_store_bit[store_row][c] = 0;
#if ADAPTOR_NOISE_ALGO_EN
				pendata_nonpassive_num++;
				pendata_select_pos[c] = pendata_max_pos[c];
#endif
			}
			else
				data_store_bit[store_row][c] = 2;

			pendata_min[c] = 0;
			pendata_max[c] = 0;
		}

#if ADAPTOR_NOISE_ALGO_EN
		if(thisInfo->tPenInfo.bAdaptorNoise)
		{
			int i, j;
			int max_pos_data = 0;
			int max_pos_index = 0;

			for(i=0; i<8; i++)
			{
				for(j=i+1; j<8; j++)
				{
					if(pendata_select_pos[i].r == pendata_select_pos[j].r && pendata_select_pos[i].c == pendata_select_pos[j].c)
					{
						pendata_select_cnt[i]++;
						pendata_select_cnt[j]++;
					}
				}
			}

			for(i=0; i<8; i++)
			{
				if(pendata_select_cnt[i] > max_pos_data)
				{
					max_pos_data = pendata_select_cnt[i];
					max_pos_index = i;
				}
			}

			if(max_pos_data != (pendata_nonpassive_num-1))
			{
				for(i=0; i<8; i++)
				{
					if(pendata_select_pos[i].r != pendata_select_pos[max_pos_index].r)
					{
						read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(pendata_select_pos[max_pos_index].r+i*PEN_COORD_ROW_MAX,pendata_select_pos[max_pos_index].c);
						delta = 128 - (signed)read_raw_data;		// pen use

						if(delta > thisModeConf->PenData.ucPenDataLocalTHD)
						data_store_bit[store_row][i] = 0;
						else if(delta < -thisModeConf->PenData.ucPenDataLocalTHD)
						data_store_bit[store_row][i] = 1;
						else
						data_store_bit[store_row][i] = 2;
					}
				}
			}

			if((data_store_bit[store_row][0] != data_store_bit[store_row][1] || data_store_bit[store_row][0] != data_store_bit[store_row][2] || data_store_bit[store_row][0] != data_store_bit[store_row][3])
					&& contact1 == YES)
			{
				switch(ulIRQType)
				{
					case PARTIAL_PEN_DATA1:
					case PARTIAL_PEN_DATA2:
//					case PARTIAL_PEN_DATA6:
					{
						if((data_store_bit[store_row][0] != 0 || data_store_bit[store_row][1] != 1))
						{
							data_store_bit[store_row][0] = 0;
							data_store_bit[store_row][1] = 1;
//						data_store_bit[store_row][2] = 0;
//						data_store_bit[store_row][3] = 0;
//						data_store_bit[store_row][4] = 0;
//						data_store_bit[store_row][5] = 0;
//						data_store_bit[store_row][6] = 0;
//						data_store_bit[store_row][7] = 0;
						}
					}
					break;
				}

				prev_contactNoise = 2;
			}
			else
			{
				if(contact1 == YES && prev_contactNoise > 0)
				{
					switch(ulIRQType)
					{
						case PARTIAL_PEN_DATA1:
						case PARTIAL_PEN_DATA2:
//						case PARTIAL_PEN_DATA6:
						{
							data_store_bit[store_row][0] = 0;
							data_store_bit[store_row][1] = 1;
//						data_store_bit[store_row][2] = 0;
//						data_store_bit[store_row][3] = 0;
//						data_store_bit[store_row][4] = 0;
//						data_store_bit[store_row][5] = 0;
//						data_store_bit[store_row][6] = 0;
//						data_store_bit[store_row][7] = 0;
						}
						break;
					}
					prev_contactNoise--;
				}
			}
		}
#endif

		switch(ulIRQType)
		{
			case PARTIAL_PEN_DATA1:
			{
				if((((data_store_bit[0][0] == 0 && data_store_bit[0][1] == 1 && data_store_bit[0][2] == data_store_bit[0][3] && data_store_bit[0][2] == 1 - data_store_bit[0][6])
						|| (contact1 == YES && data_store_bit[0][0] == 0 && data_store_bit[0][1] == 1))))
				{
					thisInfo->tPenInfo.bPenContact = YES;
					DataForcePenContact = thisModeConf->PenData.ucForcePenContact_NUM;
					//if(dbg3[2] != 1)
					{
						if(data_store_bit[0][2] == 1 && data_store_bit[0][2] == data_store_bit[0][3] && data_store_bit[0][2] == 1 - data_store_bit[0][6])
							thisInfo->tPenInfo.bPen_button[0] = 1;
						else
							thisInfo->tPenInfo.bPen_button[0] = 0;

						if(data_store_bit[0][4] == 1 && data_store_bit[0][4] == data_store_bit[0][5] && data_store_bit[0][4] == 1 - data_store_bit[0][7])
							thisInfo->tPenInfo.bPen_button[1] = 1;
						else
							thisInfo->tPenInfo.bPen_button[1] = 0;
					}
				}
				else if(thisInfo->tCoord_local_dsp.cIsbefor > 0)
				{
					thisInfo->tPenInfo.bPenContact = YES;
					DataForcePenContact = thisModeConf->PenData.ucForcePenContact_NUM;
				}
//				else if(DataForcePenContact > 0)
//				{
//					thisInfo->tPenInfo.bPenContact = YES;
//					DataForcePenContact--;
//				}
				else
				{
//				contact1 = NO;
//				if(contact2 == NO)
					{
						thisInfo->tPenInfo.bPenContact = NO;
						thisInfo->tPenInfo.us_pendata_pressure = 1;
						DataForcePenContact = 0;
//						thisInfo->tPenInfo.bPen_button1 = 0;
//						thisInfo->tPenInfo.bPen_button2 = 0;
					}
//#if 0
//				if(data_store_bit[0][0] == data_store_bit[0][1])
//				{
//					thisInfo->tPenInfo.bPen_button1 = 0;
//					thisInfo->tPenInfo.bPen_button2 = 0;
//				}
//#endif
				}
			}
				break;

			case PARTIAL_PEN_DATA2:
			case PARTIAL_PEN_DATA4:
			{
				if(data_store_bit[store_row][0] == 0 && data_store_bit[store_row][1] == 1)
				{
					contact2 = YES;
					thisInfo->tPenInfo.bPenContact = YES;
//					DataForcePenContact=thisModeConf->bForcePenContact_NUM_Wacom;
				}
				else if(thisInfo->tCoord_local_dsp.cIsbefor > 0)
				{
					contact2 = YES;
					thisInfo->tPenInfo.bPenContact = YES;
				}
				else if(DataForcePenContact > 0)// && ulIRQType == PARTIAL_PEN_DATA2)
				{
					contact2 = YES;
					thisInfo->tPenInfo.bPenContact = YES;
					DataForcePenContact--;
				}
				else if(data_store_bit[store_row][0] == data_store_bit[store_row][1])
				{
					{
						contact2 = NO;
						thisInfo->tPenInfo.bPenContact = NO;
						thisInfo->tPenInfo.us_pendata_pressure = 1;
						DataForcePenContact = 0;
//						thisInfo->tPenInfo.bPen_button1 = 0;
//						thisInfo->tPenInfo.bPen_button2 = 0;
					}
				}
			}
				break;

			case PARTIAL_PEN_DATA3:
			case PARTIAL_PEN_DATA5:
			{
				uint16_t pen_data_presure;
				uint16_t check_sum_data;
				uint8_t andBitCnt;
				uint8_t checkMSB;
				uint8_t checkLSB;
				uint8_t ori_CheckMSB;
				uint8_t ori_CheckLSB;

				int add_row = 0;

				if(ulIRQType == PARTIAL_PEN_DATA5)
					add_row = 2;

				pen_data_presure = (data_store_bit[1 + add_row][2] * 3 + data_store_bit[1 + add_row][3]) << 0;
				pen_data_presure += ((data_store_bit[1 + add_row][4] * 3 + data_store_bit[1 + add_row][5]) << 3);
				pen_data_presure += ((data_store_bit[1 + add_row][6] * 3 + data_store_bit[1 + add_row][7]) << 6);
				pen_data_presure += ((data_store_bit[2 + add_row][1] * 3 + data_store_bit[2 + add_row][2]) << 9);
				check_sum_data = (pen_data_presure << 1) + data_store_bit[2 + add_row][3];

				andBitCnt = 0;
				for(r = 0; r < 13; r++)
				{
					if((check_sum_data >> r) & 0x1)
						andBitCnt++;
				}

				andBitCnt = (~andBitCnt) & 0x3f;

				checkMSB = (andBitCnt & 0x7);
				checkLSB = ((andBitCnt >> 3) & 0x7);

				ori_CheckMSB = data_store_bit[2 + add_row][4] * 3 + data_store_bit[2 + add_row][5];
				ori_CheckLSB = data_store_bit[2 + add_row][6] * 3 + data_store_bit[2 + add_row][7];

				if(checkMSB == ori_CheckMSB && checkLSB == ori_CheckLSB)
					andBitCnt = 1;
				else
					andBitCnt = 0;

				//dbg2[5] = andBitCnt;

#if USED_WACOMPEN_DATA_WORKAROUND
				{
					if(pen_data_presure != 0)
					{
						if(pen_data_presure > 4095)
							pen_data_presure = 4095;
						thisInfo->tPenInfo.us_pendata_pressure = pen_data_presure;
						//g_pendata_pressure = (g_pre_pendata_pressure+g_pendata_pressure)>>1;
					}

					if(contact2 == YES)
						thisInfo->tPenInfo.bPenContact = YES;
					else if(thisInfo->tCoord_local.cIsbefor[0] > 0)
					{
						contact2 = YES;
						thisInfo->tPenInfo.bPenContact = YES;
					}
					else
					{
						contact2 = NO;
						thisInfo->tPenInfo.bPenContact = NO;
						thisInfo->tPenInfo.bPen_button[0] = 0;
						thisInfo->tPenInfo.bPen_button[1] = 0;
						thisInfo->tPenInfo.us_pendata_pressure = 1;
						DataForcePenContact = 0;
					}
				}
#else /* USED_WACOMPEN_DATA_WORKAROUND */
				if((andBitCnt == 1 && thisInfo->tCoord_local_dsp.cIsbefor == 0))				// || dbg3[2] == 1 )
				{
					if(pen_data_presure != 0)
					{
						if(pen_data_presure > 4095)
							pen_data_presure = 4095;
						thisInfo->tPenInfo.us_pendata_pressure = pen_data_presure;
						//g_pendata_pressure = (g_pre_pendata_pressure+g_pendata_pressure)>>1;
					}

					if(contact2 == YES)
						thisInfo->tPenInfo.bPenContact = YES;
					else if(thisInfo->tCoord_local_dsp.cIsbefor > 0)
					{
						contact2 = YES;
						thisInfo->tPenInfo.bPenContact = YES;
					}
					else
					{
						contact2 = NO;
						thisInfo->tPenInfo.bPenContact = NO;
						thisInfo->tPenInfo.bPen_button[0] = 0;
						thisInfo->tPenInfo.bPen_button[1] = 0;
						thisInfo->tPenInfo.us_pendata_pressure = 1;
						DataForcePenContact = 0;
					}
				}
				else
				{
					contact2 = NO;
					if(contact1 == NO)
					{
						thisInfo->tPenInfo.bPenContact = NO;
						DataForcePenContact = 0;
					}

					if(thisInfo->tCoord_local_dsp.cIsbefor > 0)
					{
						thisInfo->tPenInfo.bPenContact = YES;
					}
				}
#endif  /* USED_WACOMPEN_DATA_WORKAROUND */

				if(ulIRQType == PARTIAL_PEN_DATA5)
				{
					if(thisInfo->tPenInfo.bPenContact == NO)
					{
//					hover_base = (hover_data_store_bit[3] + hover_data_store_bit[4]) >> 1;
						hover_base = (hover_data_store_bit[1] + hover_data_store_bit[3] + hover_data_store_bit[2] + hover_data_store_bit[4] + 2) >> 2;

						if(hover_data_store_bit[1] - hover_base < -thisModeConf->PenData.ucPenDataHoverTHD && hover_data_store_bit[3] - hover_base > thisModeConf->PenData.ucPenDataHoverTHD)
							thisInfo->tPenInfo.bPen_button[0] = 1;
						else
							thisInfo->tPenInfo.bPen_button[0] = 0;

						if(hover_data_store_bit[2] - hover_base < -thisModeConf->PenData.ucPenDataHoverTHD && hover_data_store_bit[4] - hover_base > thisModeConf->PenData.ucPenDataHoverTHD)
							thisInfo->tPenInfo.bPen_button[1] = 1;
						else
							thisInfo->tPenInfo.bPen_button[1] = 0;

						thisInfo->tPenInfo.us_pendata_pressure = 1;
						thisInfo->tPenInfo.us_pre_pendata_pressure = 1;
					}

					for(r = 0; r < 7; r++)
					{
						hover_data_store_bit[r] = 0;
					}
				}
			}
				break;

			default:
				break;
		}

		if(thisInfo->tPenInfo.bPenContact == YES)
		{
			contact1 = YES;
			thisInfo->tPenInfo.us_pre_pendata_pressure = thisInfo->tPenInfo.us_pendata_pressure;
		}
		else
			contact1 = NO;
	}

	return 0; //thisInfo->bBlockTracking;
}
#endif /* (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN) */


//#define WGP_PEN_DATA_LOCAL_THD			(60)
//#define WGP_PEN_DATA_HOVER_THD			(80)
#define WGP_PEN_DATA_1st_SYMBOL			(0)
#define WGP_PEN_DATA_2nd_SYMBOL			(1)
#define WGP_PEN_SYMBOL_IDX_NUM			(2)
#define WGP_PEN_SYMBOL_NUM_1LHB			(6)

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
int8_t cContactSymbolData[WGP_PEN_SYMBOL_IDX_NUM][WGP_PEN_SYMBOL_NUM_1LHB*2];
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
};

void algorithm_local_prePressureBit_clear()
{
	thisInfo->tPenInfo.sPPressureOriBit[1] = 0;
	thisInfo->tPenInfo.sPPressureOriBit[0] = 0;
}

void algorithm_local_hoverContact_classify(int16_t sPressureDataBit)
{
	uint8_t hover_flag = 0;
	uint8_t cOneFrameSubTh = thisModeConf->PenData.ucAbnormalContactRemovePressureTH1; //35;
	uint16_t sTwoFrameSubTh = thisModeConf->PenData.ucAbnormalContactRemovePressureTH2; //70;
	uint8_t prev_OffChk = 0;
	
	if((thisInfo->tPenInfo.bPenContact == YES) && (thisInfo->tPenInfo.bPenOffChk == YES))
		prev_OffChk = 1;
	
	thisInfo->tPenInfo.bPenOffChk = NO;
	if(sPressureDataBit == 0)
	{
		thisInfo->tPenInfo.bPenContact = NO;
		thisInfo->tPenInfo.us_pendata_pressure = 1;
		thisInfo->tPenInfo.us_pre_pendata_pressure = 1;
	}
	else if(sPressureDataBit != -1)
	{
		if((thisInfo->tPenInfo.sPPressureOriBit[0] - sPressureDataBit > cOneFrameSubTh) && (thisInfo->tPenInfo.sPPressureOriBit[0] != -1))
		{
			if(thisInfo->tPenInfo.sPPressureOriBit[0] - sPressureDataBit > sTwoFrameSubTh)
				hover_flag = 2;
			else
				hover_flag = 1;
		}
		else if((thisInfo->tPenInfo.sPPressureOriBit[1] - sPressureDataBit > sTwoFrameSubTh) && (thisInfo->tPenInfo.sPPressureOriBit[1] != -1))
			hover_flag = 1;
	}
	
	if(hover_flag == 1)
	{
		thisInfo->tPenInfo.bPenOffChk = YES;
		if(prev_OffChk == 1)
			hover_flag = 2;
	}
	
	if(hover_flag == 2)
	{
		thisInfo->tPenInfo.bPenContact = NO;
		thisInfo->tPenInfo.us_pendata_pressure = 1;
		thisInfo->tPenInfo.us_pre_pendata_pressure = 1;
	}
	
	thisInfo->tPenInfo.sPPressureOriBit[1] = thisInfo->tPenInfo.sPPressureOriBit[0];
	thisInfo->tPenInfo.sPPressureOriBit[0] = sPressureDataBit;
}

int16_t g_sPenData_1st_Max[WGP_PEN_SYMBOL_NUM_1LHB*2] = {0,};
int16_t g_sPenData_2nd_Max[WGP_PEN_SYMBOL_NUM_1LHB*2] = {0,};
bool_t algorithm_local_data_baseline_calculate_delta_WGP_24bitStructure(ePartialSensing_t RetVal)
{
//	uint8_t data_reset = 0;
	uint8_t chkSum = 0;
	int16_t delta;
	int16_t sCompressurePressureData = -1;
	int16_t sPenData_Max[WGP_PEN_SYMBOL_NUM_1LHB];
	int32_t r, c, s, ii;
	int32_t start_c, end_c;
	uint32_t ulStartSymbolOffset;
	static bool_t pre_contact_button[2] = {0,};
	static bool_t pre_hover_button[2] = {0,};
	static bool_t current_contact_button[2] = {0,};
	static bool_t current_hover_button[2] = {0,};
	static int8_t DataForcePenContact = 0;
	int32_t ID_MAX_Value = 0;
	bool_t hover_button_check_bit = 0;
#ifdef FingerAreaPenDeltaDelete	
	int32_t local_rs = currentRowStart;
#endif	
	
	start_c = thisInfo->tPenInfo.ucCurrentColumnStart;
	end_c = thisInfo->tPenInfo.ucCurrentColumnEnd;

	if(thisInfo->tPenInfo.bSearch_Mode_Flag == 0)
	{
		memset((void*)&sPenData_Max[0], INT16_MIN, sizeof(int16_t) * WGP_PEN_SYMBOL_NUM_1LHB);

		for(s = 0; s < WGP_PEN_SYMBOL_NUM_1LHB; s++)
		{
			for(r = 0; r < PEN_COORD_ROW_MAX; r++)
			{
				for(c = start_c; c < end_c; c++)
				{
					/*
					 * DBPSK "Ref Symbol - Data Symbol"
					 */
					delta = (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r + (PEN_COORD_ROW_MAX * (s+1)), c) - (int16_t)HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c);

#ifdef FingerAreaPenDeltaDelete
					if(thisModeConf->BaseLine.cFingerAreaPenDeltaDelete != 0)
					{
//						if(LOCALFINGERAREA[r+local_rs][c] > 0)
						if(thisInfo->tPenInfo.LocalFingerArea.rs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= r+local_rs
						&& thisInfo->tPenInfo.LocalFingerArea.re + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= r+local_rs
						&& thisInfo->tPenInfo.LocalFingerArea.cs - thisModeConf->BaseLine.cFingerAreaPenDeltaDelete <= c
						&& thisInfo->tPenInfo.LocalFingerArea.ce + thisModeConf->BaseLine.cFingerAreaPenDeltaDelete >= c)
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
			}
			/* no break */
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			case PARTIAL_PEN_COORD_DATA1:
#else
			case PARTIAL_PEN_DATA1:
#endif
			{
#if (USED_MODULE_DEF != MODULE_DEF_B_1)
				int max_s = 0;
				int	min_s = 0xffff;
				int adaptive_contact_th = thisModeConf->PenData.ucPenDataLocalTHD;
				
				for(s = 0; s < WGP_PEN_SYMBOL_NUM_1LHB; s++)
				{
					if(max_s < sPenData_Max[s])
						max_s = sPenData_Max[s];
					
					if(min_s > sPenData_Max[s])
						min_s = sPenData_Max[s];
				}
				adaptive_contact_th = (max_s - min_s)>>1;
#endif				
				for(s = 0; s < WGP_PEN_SYMBOL_NUM_1LHB; s++)
				{
					int choose_th;
#if (USED_MODULE_DEF != MODULE_DEF_B_1)//1//(USED_MODULE_DEF == MODULE_DEF_S_1)					
					if(s+ulStartSymbolOffset < 2)
						choose_th = adaptive_contact_th;
					else
						choose_th = thisModeConf->PenData.ucPenDataLocalTHD;
#else
					choose_th = thisModeConf->PenData.ucPenDataLocalTHD;
#endif
//					if(thisInfo->tPenInfo.bPenContact == NO)
//					g_sPenData_1st_Max[s+ulStartSymbolOffset] = (g_sPenData_1st_Max[s+ulStartSymbolOffset] + sPenData_Max[s])>>1;
					g_sPenData_1st_Max[s+ulStartSymbolOffset] = sPenData_Max[s];
					if(sPenData_Max[s] > choose_th)//thisModeConf->PenData.ucPenDataLocalTHD)
					{
						cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][s + ulStartSymbolOffset] = 0;
					}
					else
					{
						cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][s + ulStartSymbolOffset] = 1;
					}

					if((s + ulStartSymbolOffset) % 2 == 1)
					{
						//if(sPenData_Max[s-1] + sPenData_Max[s] > thisModeConf->ucPenDataHoverTHD)
						if(g_sPenData_1st_Max[s+ulStartSymbolOffset-1] + g_sPenData_1st_Max[s+ulStartSymbolOffset] > thisModeConf->PenData.ucPenDataHoverTHD)
						{
							cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][(s + ulStartSymbolOffset)>>1] = 0;
						}
						else
						{
							cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][(s + ulStartSymbolOffset)>>1] = 1;
						}
					}
				}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
				if(RetVal ==  PARTIAL_PEN_COORD_DATA2)
#else
				if(RetVal == PARTIAL_PEN_DATA2)
#endif
				{
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
							thisInfo->tPenInfo.bPenContact = YES;
							DataForcePenContact = thisModeConf->PenData.ucForcePenContact_NUM;
							/*
							 * Pressure!!
							 */
							sCompressurePressureData = (uint16_t)(vBIT7((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_PRESSURE_7_BIT]) |
									 vBIT6((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_PRESSURE_6_BIT]) |
									 vBIT5((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_PRESSURE_5_BIT]) |
									 vBIT4((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_PRESSURE_4_BIT]) |
									 vBIT3((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_PRESSURE_3_BIT]) |
									 vBIT2((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_PRESSURE_2_BIT]) |
									 vBIT1((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_PRESSURE_1_BIT]) |
									 vBIT0((uint32_t)cContactSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stCTSYB_PRESSURE_0_BIT]));
							 thisInfo->tPenInfo.us_pendata_pressure = ulPenPressure_RogarithmicCVTTable[sCompressurePressureData];
							
#if AbnormalContactRemove_EN							
							if(thisModeConf->PenData.ucAbnormalContactRemovePressureTH1	> 0 && thisModeConf->PenData.ucAbnormalContactRemovePressureTH2 > 0 && thisInfo->tPenInfo.bEdgeAbnormalContact)				
								algorithm_local_hoverContact_classify(sCompressurePressureData);
#endif							
							if(thisInfo->tPenInfo.us_pendata_pressure == 0)
							{
								thisInfo->tPenInfo.bPenContact = NO;
								if(DataForcePenContact > 0)
								{
									thisInfo->tPenInfo.bForcePenContactFlag = 1;
									thisInfo->tPenInfo.bPenContact = YES;
									thisInfo->tPenInfo.us_pendata_pressure = 500;
									DataForcePenContact--;
								}
							}
							else
							{
								thisInfo->tPenInfo.bForcePenContactFlag = 0;
							}	
						}
					}
					else if(DataForcePenContact > 0)
					{
						thisInfo->tPenInfo.bPenContact = YES;
						thisInfo->tPenInfo.bForcePenContactFlag = 1;
						DataForcePenContact--;
					}
					else /*if(cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stHVSYB_HOVER_BIT] == 1)*/
					{
						/*
						 * Hover
						 */
						thisInfo->tPenInfo.bForcePenContactFlag = 0;
						thisInfo->tPenInfo.bPenContact = NO;
						thisInfo->tPenInfo.us_pendata_pressure = 1;
						thisInfo->tPenInfo.us_pre_pendata_pressure = 1;
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

#if USED_WGP_AGIC_PEN
						hover_button_check_bit = 0;
#else
						hover_button_check_bit = 1;
#endif
						
						if(chkSum%2 == cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stHVSYB_1BITCHECKSUM_BIT] && cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stHVSYB_HOVER_BIT] == 1)
						{
							if(cHoverSymbolData[WGP_PEN_DATA_1st_SYMBOL][GETABS_1stHVSYB_SW1_BIT] == 1)current_hover_button[hover_button_check_bit] = 1;
							else current_hover_button[hover_button_check_bit] = 0;
							
							if((pre_hover_button[hover_button_check_bit] == 1 && current_hover_button[hover_button_check_bit] ==1) || (pre_contact_button[hover_button_check_bit] == 1 && current_hover_button[hover_button_check_bit] == 1))
								thisInfo->tPenInfo.bPen_button[hover_button_check_bit] = 1;
							else thisInfo->tPenInfo.bPen_button[hover_button_check_bit] = 0;
						}
						//else g_pen_button2 = 0;
							
						if(thisModeConf->PenData.usPenDataHighHoverButtonRejectTHD > 0)// && edge_f)
						{

							ID_MAX_Value = g_sPenData_1st_Max[2]+g_sPenData_1st_Max[3];
							if(ID_MAX_Value < g_sPenData_1st_Max[4]+g_sPenData_1st_Max[5])
								ID_MAX_Value = g_sPenData_1st_Max[4]+g_sPenData_1st_Max[5];
							if(ID_MAX_Value < g_sPenData_1st_Max[6]+g_sPenData_1st_Max[7])
								ID_MAX_Value = g_sPenData_1st_Max[6]+g_sPenData_1st_Max[7];
	
							if(ID_MAX_Value < g_sPenData_2nd_Max[2]+g_sPenData_2nd_Max[3])
								ID_MAX_Value = g_sPenData_2nd_Max[2]+g_sPenData_2nd_Max[3];							
							if(ID_MAX_Value < g_sPenData_2nd_Max[4]+g_sPenData_2nd_Max[5])
								ID_MAX_Value = g_sPenData_2nd_Max[4]+g_sPenData_2nd_Max[5];
							if(ID_MAX_Value < g_sPenData_2nd_Max[6]+g_sPenData_2nd_Max[7])
								ID_MAX_Value = g_sPenData_2nd_Max[6]+g_sPenData_2nd_Max[7];

							if(ID_MAX_Value < thisModeConf->PenData.usPenDataHighHoverButtonRejectTHD)thisInfo->tPenInfo.bPen_button[hover_button_check_bit] = 0;
						}					

						if(thisInfo->tPenInfo.bPenPostProcessFlag)thisInfo->tPenInfo.bPen_button[hover_button_check_bit] = 0;
						pre_hover_button[hover_button_check_bit] = current_hover_button[hover_button_check_bit];
						pre_contact_button[hover_button_check_bit] = 0;
	
						/*
						 * ID Hash
						 */
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
			}
			/* no break */
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			case PARTIAL_PEN_COORD_DATA3:
#else
			case PARTIAL_PEN_DATA3:
#endif
			{
#if (USED_MODULE_DEF != MODULE_DEF_B_1)
				int max_s = 0;
				int	min_s = 0xffff;
				int adaptive_contact_th = thisModeConf->PenData.ucPenDataLocalTHD;
				
				for(s = 0; s < WGP_PEN_SYMBOL_NUM_1LHB; s++)
				{
					if(max_s < sPenData_Max[s])
						max_s = sPenData_Max[s];
					
					if(min_s > sPenData_Max[s])
						min_s = sPenData_Max[s];
				}
				
				adaptive_contact_th = (max_s - min_s)>>1;
#endif				
				for(s = 0; s < WGP_PEN_SYMBOL_NUM_1LHB; s++)
				{
					int choose_th;
#if (USED_MODULE_DEF != MODULE_DEF_B_1)//1//(USED_MODULE_DEF == MODULE_DEF_S_1)
					if(s+ulStartSymbolOffset < 2)
						choose_th = adaptive_contact_th;
					else
						choose_th = thisModeConf->PenData.ucPenDataLocalTHD;
#else
					choose_th = thisModeConf->PenData.ucPenDataLocalTHD;
#endif
					g_sPenData_2nd_Max[s+ulStartSymbolOffset] = sPenData_Max[s];
					if(sPenData_Max[s] >  choose_th)//thisModeConf->PenData.ucPenDataLocalTHD)
					{
						cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][s + ulStartSymbolOffset] = 0;
					}
					else
					{
						cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][s + ulStartSymbolOffset] = 1;
					}

					if((s + ulStartSymbolOffset) % 2 == 1)
					{
						//if(sPenData_Max[s-1] + sPenData_Max[s] > thisModeConf->ucPenDataHoverTHD)
						if(g_sPenData_2nd_Max[s+ulStartSymbolOffset-1] + g_sPenData_2nd_Max[s+ulStartSymbolOffset] > thisModeConf->PenData.ucPenDataHoverTHD)
						{
							cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][(s + ulStartSymbolOffset)>>1] = 0;
						}
						else
						{
							cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][(s + ulStartSymbolOffset)>>1] = 1;
						}
					}
				}
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
				if(RetVal == PARTIAL_PEN_COORD_DATA4)
#else
				if(RetVal == PARTIAL_PEN_DATA4)
#endif
				{
					if(thisInfo->tPenInfo.bPenContact == YES)
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
							/*
							 * Pressure!!
							 */
							sCompressurePressureData = (uint16_t)(vBIT7((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_PRESSURE_7_BIT]) |
									 vBIT6((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_PRESSURE_6_BIT]) |
									 vBIT5((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_PRESSURE_5_BIT]) |
									 vBIT4((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_PRESSURE_4_BIT]) |
									 vBIT3((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_PRESSURE_3_BIT]) |
									 vBIT2((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_PRESSURE_2_BIT]) |
									 vBIT1((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_PRESSURE_1_BIT]) |
									 vBIT0((uint32_t)cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_PRESSURE_0_BIT]));
							thisInfo->tPenInfo.us_pendata_pressure = ulPenPressure_RogarithmicCVTTable[sCompressurePressureData];
#if AbnormalContactRemove_EN						
							if(thisModeConf->PenData.ucAbnormalContactRemovePressureTH1	> 0 && thisModeConf->PenData.ucAbnormalContactRemovePressureTH2 > 0 && thisInfo->tPenInfo.bEdgeAbnormalContact)
								algorithm_local_hoverContact_classify(sCompressurePressureData);
#endif							
							/*
							 * Button 1 and 2!!
							 */
							if(cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_SW1_BIT] == 1 )
							{
								current_contact_button[0] = 1; 
							}
							else
							{
								current_contact_button[0] = 0; 
							}

							if(cContactSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndCTSYB_SW2_BIT] == 1 )
							{
								current_contact_button[1] = 1; 
							}
							else
							{
								current_contact_button[1] = 0; 
							}
							
							if((pre_contact_button[0] == 1 && current_contact_button[0] == 1) || (pre_hover_button[0] == 1 && current_contact_button[0] == 1))
							{
								thisInfo->tPenInfo.bPen_button[0] = 1;
							}
							else thisInfo->tPenInfo.bPen_button[0] = 0;
							
							if((pre_contact_button[1] == 1 && current_contact_button[1] == 1) || (pre_hover_button[1] == 1 && current_contact_button[1] == 1))
							{
								thisInfo->tPenInfo.bPen_button[1] = 1;
							}
							else thisInfo->tPenInfo.bPen_button[1] = 0;
							
							if(thisInfo->tPenInfo.us_pendata_pressure == 0)
							{
								thisInfo->tPenInfo.bPenContact = NO; 
								if(DataForcePenContact > 0)
								{
									thisInfo->tPenInfo.bForcePenContactFlag = 1;
									thisInfo->tPenInfo.bPenContact = YES;
									thisInfo->tPenInfo.us_pendata_pressure = 500;
									DataForcePenContact--;
								}
							}
							else
							{
								thisInfo->tPenInfo.bForcePenContactFlag = 0;
							}
			
							
							if(thisInfo->tPenInfo.bForcePenContactFlag)
							{
								thisInfo->tPenInfo.bPen_button[0] = pre_contact_button[0];
								thisInfo->tPenInfo.bPen_button[0] = pre_contact_button[1];
							}
							
							if(thisInfo->tPenInfo.bPenPostProcessFlag)thisInfo->tPenInfo.bPen_button[0] = thisInfo->tPenInfo.bPen_button[1] = 0;
							
							pre_contact_button[0] = current_contact_button[0];
							pre_contact_button[1] = current_contact_button[1];
							pre_hover_button[0] = 0;
							pre_hover_button[1] = 0;
						}
//						else if(chkSum == 10)
//							data_reset = 1;
					}
					else
					{
						if(cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndHVSYB_HOVER_0_BIT] == 0)
						{
							thisInfo->tPenInfo.bPenContact = YES;
							DataForcePenContact = thisModeConf->PenData.ucForcePenContact_NUM;
							thisInfo->tPenInfo.us_pendata_pressure = 500;
						}
						else if(DataForcePenContact > 0)
						{
							thisInfo->tPenInfo.bForcePenContactFlag = 1;
							thisInfo->tPenInfo.bPenContact = YES;
							thisInfo->tPenInfo.us_pendata_pressure = 500;
							DataForcePenContact--;
						}
						else
						{
							thisInfo->tPenInfo.bForcePenContactFlag = 0;
							thisInfo->tPenInfo.bPenContact = NO;
							thisInfo->tPenInfo.us_pendata_pressure = 1;
							thisInfo->tPenInfo.us_pre_pendata_pressure = 1;
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

#if USED_WGP_AGIC_PEN
						hover_button_check_bit = 1;
#else
						hover_button_check_bit = 0;
#endif
							
							if(chkSum%2 == cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndHVSYB_1BITCHECKSUM_BIT] && cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndHVSYB_HOVER_0_BIT] == 1)
							{
								if(cHoverSymbolData[WGP_PEN_DATA_2nd_SYMBOL][GETABS_2ndHVSYB_SW2_BIT] == 1)current_hover_button[hover_button_check_bit] = 1;
								else current_hover_button[hover_button_check_bit] = 0;
								
								if((pre_hover_button[hover_button_check_bit] == 1 && current_hover_button[hover_button_check_bit] == 1) || (pre_contact_button[hover_button_check_bit] == 1 && current_hover_button[hover_button_check_bit] == 1))
									thisInfo->tPenInfo.bPen_button[hover_button_check_bit] = 1;
								else thisInfo->tPenInfo.bPen_button[hover_button_check_bit] = 0;
							}
							//else thisInfo->tPenInfo.bPen_button1 = 0;
						
							if(thisModeConf->PenData.usPenDataHighHoverButtonRejectTHD > 0)// && edge_f)
							{
								ID_MAX_Value = g_sPenData_1st_Max[2]+g_sPenData_1st_Max[3];
								if(ID_MAX_Value < g_sPenData_1st_Max[4]+g_sPenData_1st_Max[5])
									ID_MAX_Value = g_sPenData_1st_Max[4]+g_sPenData_1st_Max[5];
								if(ID_MAX_Value < g_sPenData_1st_Max[6]+g_sPenData_1st_Max[7])
									ID_MAX_Value = g_sPenData_1st_Max[6]+g_sPenData_1st_Max[7];
		
								if(ID_MAX_Value < g_sPenData_2nd_Max[2]+g_sPenData_2nd_Max[3])
									ID_MAX_Value = g_sPenData_2nd_Max[2]+g_sPenData_2nd_Max[3];							
								if(ID_MAX_Value < g_sPenData_2nd_Max[4]+g_sPenData_2nd_Max[5])
									ID_MAX_Value = g_sPenData_2nd_Max[4]+g_sPenData_2nd_Max[5];
								if(ID_MAX_Value < g_sPenData_2nd_Max[6]+g_sPenData_2nd_Max[7])
									ID_MAX_Value = g_sPenData_2nd_Max[6]+g_sPenData_2nd_Max[7];
							
								if(ID_MAX_Value < thisModeConf->PenData.usPenDataHighHoverButtonRejectTHD)thisInfo->tPenInfo.bPen_button[hover_button_check_bit] = 0;
							}
							
							if(thisInfo->tPenInfo.bPenPostProcessFlag)thisInfo->tPenInfo.bPen_button[hover_button_check_bit] = 0;
							pre_hover_button[hover_button_check_bit] = current_hover_button[hover_button_check_bit];
							pre_contact_button[hover_button_check_bit] = 0;
						}
					}
				}
				break;
			}
		}
		
//		thisInfo->tPenInfo.bPre_pen_button1 = gthisInfo->tPenInfo.bPen_button1;
//		thisInfo->tPenInfo.bPre_pen_button2 = thisInfo->tPenInfo.bPen_button2;
		
//		 if(data_reset == 1)
//		 {
//		 	thisInfo->tPenInfo.us_pendata_pressure = 1;
//		 	thisInfo->tPenInfo.bPen_button1 = 0;
//		 	thisInfo->tPenInfo.bPen_button2 = 0;
//		 	thisInfo->tPenInfo.bPenContact = NO;
//		 	thisInfo->tPenInfo.bPrevPenContact = NO;
//		 }

	}
	else
	{
		thisInfo->tPenInfo.us_pendata_pressure = 1;
		thisInfo->tPenInfo.bPen_button[0] = 0;
		thisInfo->tPenInfo.bPen_button[1] = 0;
		pre_contact_button[0] = 0;
		pre_contact_button[1] = 0;
		pre_hover_button[0] = 0;
		pre_hover_button[1] = 0;
		current_contact_button[0] = 0;
		current_contact_button[1] = 0;
		current_hover_button[0] = 0;
		current_hover_button[1] = 0;
		thisInfo->tPenInfo.bPenContact = NO;
		thisInfo->tPenInfo.bPrevPenContact = NO;
		for(r=0;r<2;r++)for(c=0;c<6;c++)
			cHoverSymbolData[r][c] = 0;
		memset((void*)&g_sPenData_2nd_Max[0], INT16_MIN, sizeof(int16_t) * WGP_PEN_SYMBOL_NUM_1LHB*2);
		memset((void*)&g_sPenData_1st_Max[0], INT16_MIN, sizeof(int16_t) * WGP_PEN_SYMBOL_NUM_1LHB*2);
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
//	memset((void*)HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
//	memset((void*)HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
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
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN)	
	algorithm_local_data_baseline_calculate_delta_WACOM(RetVal, sensingRowStart);
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
	eActivePenType_t ePenOpType = hal_Info_GetControlActivePenOPType();
	switch(ePenOpType)
	{
		case ACTIVEPEN_TYPE_LOCAL_MS:
		{
			algorithm_local_data_baseline_calculate_delta(RetVal);
			break;
		}
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)	
		case ACTIVEPEN_TYPE_LOCAL_WACOM:
		{
			algorithm_local_data_baseline_calculate_delta_WACOM(RetVal, sensingRowStart);
			break;
		}
	#else
		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			algorithm_local_data_baseline_calculate_delta_WGP_24bitStructure(RetVal);
			break;
		}
	#endif
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
			
			if (x < thisInfo->tCoord.iXExpandStart)
				x = thisInfo->tCoord.iXExpandStart + (((x - thisInfo->tCoord.iXExpandStart) * (int32_t)ucLeftEdgeExpand_local) >> 6);
			else if (thisInfo->tCoord.iInternalXRes - x < thisInfo->tCoord.iXExpandStart)
				x = thisInfo->tCoord.iInternalXRes - (thisInfo->tCoord.iXExpandStart
									 + (((thisInfo->tCoord.iInternalXRes - x - thisInfo->tCoord.iXExpandStart) * (int32_t)ucRightEdgeExpand_local) >> 6));

			if (y < (thisInfo->tCoord.iYExpandStart))
				y = (thisInfo->tCoord.iYExpandStart) + (((y - (thisInfo->tCoord.iYExpandStart)) * (int32_t)ucTopEdgeExpand_local) >> 6);
			else if (thisInfo->tCoord.iInternalYRes - y < thisInfo->tCoord.iYExpandStart)
				y = thisInfo->tCoord.iInternalYRes - (thisInfo->tCoord.iYExpandStart
									 + (((thisInfo->tCoord.iInternalYRes - y - thisInfo->tCoord.iYExpandStart) * (int32_t)ucBottomEdgeExpand_local) >> 6));
		}
	}

	/*
	 * Modify resolution domain.
	 */
	x = ( (x + thisInfo->tCoord.iXOffset ) * (thisCommonConf->iXResolution+thisModeConf->PenCoord.sPenGlobalCoordiXResolutionOffset) ) / (thisInfo->tCoord.iInternalXRes + 2*thisInfo->tCoord.iXOffset);
	y = ( (y + thisInfo->tCoord.iYOffset ) * (thisCommonConf->iYResolution+thisModeConf->PenCoord.sPenGlobalCoordiYResolutionOffset) ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
	x += thisModeConf->PenCoord.sPenGlobalCoordiOffsetX;
	y += thisModeConf->PenCoord.sPenGlobalCoordiOffsetY;
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
			if(old_pos != pos && pos->x != old_pos->x)
				y = ( (x - old_pos->x)*(pos->y - old_pos->y) + ((pos->x - old_pos->x)>>1) ) / (pos->x - old_pos->x) + old_pos->y;
		}
		else if (x > ((int)((iXResolutionForClipping) - thisCommonConf->ucXClipping))){
			x = (iXResolutionForClipping) - thisCommonConf->ucXClipping;
			if(old_pos != pos && pos->x != old_pos->x)
				y = ( (x - old_pos->x)*(pos->y - old_pos->y) + ((pos->x - old_pos->x)>>1) ) / (pos->x - old_pos->x) + old_pos->y;
		}
		if (y < (int)(thisCommonConf->ucYClipping)){
			y = (int)thisCommonConf->ucYClipping;
			if(old_pos != pos && pos->y != old_pos->y)
				x = ( (y - old_pos->y)*(pos->x - old_pos->x) + ((pos->y - old_pos->y)>>1) ) / (pos->y - old_pos->y) + old_pos->x;
		}
		else if (y > (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping)){
			y = (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping);
			if(old_pos != pos && pos->y != old_pos->y)
				x = ( (y - old_pos->y)*(pos->x - old_pos->x) + ((pos->y - old_pos->y)>>1) ) / (pos->y - old_pos->y) + old_pos->x;
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
	}
	
	pos->x = x;
	pos->y = y;
}

extern void protocol_hid_PushPenEvent(const uSWIPTouchItem_t* _kptItem); // NOTE : 헤더파일에 위치 잡고 없애자!!
extern uint8_t	g_ConnectedDevice;
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
		if(thisInfo->tPenInfo.bSearch_Mode_Flag == 1 && thisInfo->tPenInfo.ucSensing_cont_cnt1 > 0)
		{
			thisInfo->tPenInfo.ucSensing_cont_cnt1++;
			if(thisInfo->tPenInfo.ucSensing_cont_cnt1 == thisModeConf->PenData.ucKeepProtocolNum)
			{
				thisInfo->tPenInfo.ucSensing_cont_cnt1 = 0;
				currentRowStart = sensingRowStart = 0;
				hal_Info_SetPenDectionEnable(NO);
				hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_SEARCH_BEACON);
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
				hal_Info_SetWGPPenBeaconType(PWM_WGP_PEN_SETTABLE_BEACON);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) */
			}
		}
#endif
	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	if(thisInfo->tPenInfo.usSearch_Mode_Cnt < thisModeConf->PenTilt.usReleaseLastContact3x3Frm)
		thisInfo->tPenInfo.usSearch_Mode_Cnt++;
	else
		pTRingInfo.sLastContact3x3Val = 0;
	
	if(thisInfo->tPenInfo.ucSearch_check_cnt == 0)
	{
		memset(HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), 0, sizeof(FULLHOVERIMAGE));
	}
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	if(thisInfo->tPenInfo.ucSearch_check_cnt_2 == 0)
	{
		memset(HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR(), 0, sizeof(FULLHOVERIMAGE_2));
	}
#endif	
	algorithm_local_process(LOCAL_SEARCH_MODE, Ret);

	if(thisInfo->tPenInfo.bSearch_Mode_Flag == 1)
	{
		if(sensingRowStart >= MUX_MAX_ROW)
		{
			sensingRowStart = 0;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
			if(thisInfo->tPenInfo.ucSearch_check_cnt++ >= thisModeConf->Label.ucHoverInCheckFrm)thisInfo->tPenInfo.ucSearch_check_cnt=0;
#elif  (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN)
			if(thisInfo->tPenInfo.ucSearch_check_cnt_2++ >= thisModeConf->Label.ucHoverInCheckFrm)thisInfo->tPenInfo.ucSearch_check_cnt_2=0;
#else
			if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
			{
				if(thisInfo->tPenInfo.ucSearch_check_cnt++ >= thisModeConf->Label.ucHoverInCheckFrm)thisInfo->tPenInfo.ucSearch_check_cnt=0;
			}
			else 
			{
				if(thisInfo->tPenInfo.ucSearch_check_cnt_2++ >= thisModeConf->Label.ucHoverInCheckFrm)thisInfo->tPenInfo.ucSearch_check_cnt_2=0;
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

	thisInfo->tPenInfo.ucHover_cnt = 0;
}

bool_t algorithm_mode_change_check(void)
{
	if(thisInfo->bTouchExpect_local == NO)
	{
		if(thisInfo->tPenInfo.bPenContact == NO && thisInfo->tCoord_local_dsp.cIsbefor == 0 && (thisModeConf->PenTilt.usUseLastContact3x3Th == 0))
		{
			memset(&thisInfo->tTiltInfo,0,sizeof(thisInfo->tTiltInfo));
			thisInfo->tTiltInfo.sTilt_cnt = 1;
			thisInfo->tTiltInfo.HID_TILT_X = thisInfo->tTiltInfo.Smooth_PastTilt.x = 9000;
			thisInfo->tTiltInfo.HID_TILT_Y = thisInfo->tTiltInfo.Smooth_PastTilt.y = 9000;
		}
		
		if(thisInfo->tPenInfo.ucSensing_cont_cnt < thisModeConf->PenData.ucSEN_CONT_CNT)
			thisInfo->tPenInfo.ucSensing_cont_cnt++;
		else 
		{
			thisInfo->tPenInfo.ucHover_cnt = 0;
			thisInfo->tPenInfo.ucSensing_cont_cnt  = 0;				
			currentRowStart = sensingRowStart = 0;
#if USED_ADAPTIVE_LOCAL_SENSING
			sensingRoicStart = ROIC_NUM;
#endif /* USED_ADAPTIVE_LOCAL_SENSING */
			thisInfo->tPenInfo.bSearch_Mode_Flag = 1;
			thisInfo->tPenInfo.ucSearch_check_cnt = thisInfo->tPenInfo.ucSearch_check_cnt_2 = 0;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
			thisInfo->tPenInfo.ucSensing_cont_cnt1 = 1;
#else
			hal_Info_SetPenDectionEnable(NO);
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
			hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_SEARCH_BEACON);
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			hal_Info_SetWGPPenBeaconType(PWM_WGP_PEN_SETTABLE_BEACON);
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_SEARCH_BEACON);
			hal_Info_SetWGPPenBeaconType(PWM_WGP_PEN_SETTABLE_BEACON);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) */
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			memset(LOCALNOISEBUF1,0,sizeof(LOCALNOISEBUF1));
#endif
			memset(RINGDELTAIMAGE,0,sizeof(RINGDELTAIMAGE));
			return YES;
		}
	}
	else
		thisInfo->tPenInfo.ucSensing_cont_cnt = 0;
	
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
		if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
		{
			PARAM_SetMode(PARAM_MODE_NORMAL);
		}
		else /* WGP & Wacom */
		{
			PARAM_SetMode(PARAM_MODE_NORMAL_1);
		}
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
