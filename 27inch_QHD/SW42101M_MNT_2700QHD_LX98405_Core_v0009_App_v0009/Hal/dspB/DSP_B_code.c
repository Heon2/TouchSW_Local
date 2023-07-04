/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : DSP_B_code.c
 * created on : 17. 4. 2017
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
 * - Neither the  of SiW nor the names of its contributors may be used
 *   to endorse or pnameromote products derived from this software without
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


#if (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY))

static const tAlgorithmCommonConf_t * thisCommonConf = NULL;
static const tAlgorithmModeConf_t * thisModeConf = NULL;
static const tModuleModeConf_t * ptModuleModeConf  = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;

extern uint16_t currentRowStart;
extern volatile uint16_t sensingRowStart;

///
uint16_t dbgdsp_b_code[20] = {0,};
///

static void init_local_DSP(void); // NOTE : 외부에서 참조하는 함수가 아닌 경우.. extern말고 static으로 선언 후 사용하자!!

void algorithm_coord_init_local(void)
{
	int l;
	
	for( l=0; l<COORD_HISTORY_NUM; l++ )
	{
		memset((void *)&(thisInfo->tCoord_local.tOrgPosHist[l]), 0x00, sizeof(tPastPos_t) );
	}

	for( l=0; l<PAST_COORD_HISTORY_NUM; l++ ){
		tPastPosHist[l].x = -1;
		tPastPosHist[l].y = -1;
	}
	
	// local coord init
	thisInfo->tCoord_local.tPastPos[0].sFinger_    = 0;
	thisInfo->tCoord_local.tOrgPastPos[0].sFinger_ = 0;

	for(l=ptMemConf->iMaxTouch_; l--; )
	{
		thisInfo->tCoord_local.tPastPos[0].tXY[l].x    = -1;
		thisInfo->tCoord_local.tPastPos[0].tXY[l].y    = 0;
		thisInfo->tCoord_local.tPastPos[0].vusR[l]	   = 0;
		thisInfo->tCoord_local.tPastPos[0].vusS[l]	   = 0;

		thisInfo->tCoord_local.tPastPos[1].tXY[l].x    = -1;
		thisInfo->tCoord_local.tPastPos[1].tXY[l].y    = 0;
		thisInfo->tCoord_local.tPastPos[1].vusR[l]	   = 0;
		thisInfo->tCoord_local.tPastPos[1].vusS[l]	   = 0;
		
		thisInfo->tCoord_local.tPastPos[2].tXY[l].x    = -1;
		thisInfo->tCoord_local.tPastPos[2].tXY[l].y    = 0;
		thisInfo->tCoord_local.tPastPos[2].vusR[l]	   = 0;
		thisInfo->tCoord_local.tPastPos[2].vusS[l]	   = 0;

		thisInfo->tCoord_local.tOrgPastPos[0].tXY[l].x = 0;
		thisInfo->tCoord_local.tOrgPastPos[0].tXY[l].y = 0;
		thisInfo->tCoord_local.tOrgPastPos[0].vusR[l]  = 0;
		thisInfo->tCoord_local.tOrgPastPos[0].vusS[l]  = 0;

		thisInfo->tCoord_local.tOrgPastPos[1].tXY[l].x = 0;
		thisInfo->tCoord_local.tOrgPastPos[1].tXY[l].y = 0;
		thisInfo->tCoord_local.tOrgPastPos[1].vusR[l]  = 0;
		thisInfo->tCoord_local.tOrgPastPos[1].vusS[l]  = 0;
		
		thisInfo->tCoord_local.tOrgPastPos[2].tXY[l].x = 0;
		thisInfo->tCoord_local.tOrgPastPos[2].tXY[l].y = 0;
		thisInfo->tCoord_local.tOrgPastPos[2].vusR[l]  = 0;
		thisInfo->tCoord_local.tOrgPastPos[2].vusS[l]  = 0;

		thisInfo->tCoord_local.ucIdMappedCnt[l] = 0;
		thisInfo->tCoord_local.cScreenDebCnt[l] = 0;
		
		thisInfo->tCoord.cIsbefor[l] = 0;
	}

	thisInfo->tCoord_local.iXOffset = ( UNIT_DIST * ( 2*thisCommonConf->iXEdgeNum - thisCommonConf->iXEdgeDen) ) / (2*thisCommonConf->iXEdgeDen);
	thisInfo->tCoord_local.iYOffset = ( UNIT_DIST * (2*thisCommonConf->iYEdgeNum - thisCommonConf->iYEdgeDen) ) / (2*thisCommonConf->iYEdgeDen);

	thisInfo->tCoord_local.iXExpandStart = 1*UNIT_DIST;
	thisInfo->tCoord_local.iYExpandStart = 1*UNIT_DIST;

	thisInfo->tCoord_local.iXEdgeStart = 1*UNIT_DIST;
	thisInfo->tCoord_local.iYEdgeStart = 1*UNIT_DIST;

	if( ptMemConf->bSwapXY )
	{
		thisInfo->tCoord_local.iInternalXRes = (ptMemConf->iRow_ - 1) << POS_BOOST_SHIFT_;
		thisInfo->tCoord_local.iInternalYRes = (ptMemConf->iCol_ - 1) << POS_BOOST_SHIFT_;
	}
	else
	{
		thisInfo->tCoord_local.iInternalXRes = (ptMemConf->iCol_ - 1) << POS_BOOST_SHIFT_;
		thisInfo->tCoord_local.iInternalYRes = (ptMemConf->iRow_ - 1) << POS_BOOST_SHIFT_;
	}

	thisInfo->tCoord_local.slScaledMoveDistThd = (thisModeConf->Coord.usMoveDistanceThd << POS_BOOST_SHIFT_);
}

void algorithm_local_init(void)
{  

	thisCommonConf   = algorithm_GetCommonConfig();
	thisInfo         = algorithm_GetInfo();	
	thisModeConf     = algorithm_GetModeConfig();	
	ptModuleModeConf = module_GetModeConfig();

	algorithm_local_baseline_init();
	algorithm_coord_init_local();
}

void algorithm_coord_initialise_local_pos_buffer(void)
{
	int l;
	tCoordInfo_t *temp_coord;
	
	memset((void *)&(thisInfo->tCoord_local.tOrgPosHist[0]), 0x00, sizeof(tPastPos_t) );
	
	temp_coord = &thisInfo->tCoord_local;
	thisInfo->tDelta_local.iMaxStrength = 0;
	
	temp_coord->tTempPos.sFinger_ = 0;
	for( l=LOOSE_POSBUF_; l--; )
	{
		temp_coord->tTempPos.tXY[l].x = 0;
		temp_coord->tTempPos.tXY[l].y = 0;
		temp_coord->tTempPos.rect[l].cs = 0;
		temp_coord->tTempPos.rect[l].ce = 0;
		temp_coord->tTempPos.rect[l].rs = 0;
		temp_coord->tTempPos.rect[l].re = 0;
		temp_coord->tTempPos.vusR[l] = 0;
		temp_coord->tTempPos.vusS[l] = 0;
		temp_coord->tTempPos.MaxDelta[l] = (uint16_t)INT16_MIN; // NOTE : warning제거 초기값을 -로 설정해야 하는 이유가 있나????

		temp_coord->cRemap[l] = -1;
	}

	temp_coord->tPos.sFinger_ = 0;
	temp_coord->tOrgPos.sFinger_ = 0;
	for( l=POSBUF_; l--; )
	{
		temp_coord->tPos.tXY[l].x = -1;
		temp_coord->tPos.tXY[l].y = 0;
		temp_coord->tPos.rect[l].cs = 0;
		temp_coord->tPos.rect[l].ce = 0;
		temp_coord->tPos.rect[l].rs = 0;
		temp_coord->tPos.rect[l].re = 0;
		temp_coord->tPos.vusR[l] = 0;
		temp_coord->tPos.vusS[l] = 0;
		temp_coord->tPos.MaxDelta[l] = (uint16_t)INT16_MIN; // NOTE : warning제거 // NOTE : warning제거 초기값을 -로 설정해야 하는 이유가 있나????

		temp_coord->tOrgPos.tXY[l].x = 0;
		temp_coord->tOrgPos.tXY[l].y = 0;
		temp_coord->tOrgPos.rect[l].cs = 0;
		temp_coord->tOrgPos.rect[l].ce = 0;
		temp_coord->tOrgPos.rect[l].rs = 0;
		temp_coord->tOrgPos.rect[l].re = 0;
		temp_coord->tOrgPos.vusR[l] = 0;
		temp_coord->tOrgPos.vusS[l] = 0;

		temp_coord->ucPostProcessRun[l] = 0;
	}
}

extern uint16_t currentColStart;
extern int16_t sLFOffsetRow[ROW_MAX];

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
			sort_cnt = (uint8_t)(((int)thisInfo->ucScreenCol * 5)/100);			
			sort_range = thisInfo->ucScreenCol/4 + thisInfo->ucScreenCol%4;

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
			
			//protocol_LogVector(LT_DIAGNOSIS, 72, SortBufCol, 30/*Re-cal Count!!*/);			
			//protocol_LogVector(LT_DIAGNOSIS, 9, sLFOffsetRow, 31/*Re-cal Count!!*/);

			for( r = 0; r<PEN_COORD_ROW_MAX; r++ )
			{
				for( c=0; c<PEN_COORD_COL_MAX; c++ )
				{		
				    d = (signed)HAL_READ_LOCAL_RAW_IMAGE(r, c);
					if(c<2 || c>thisInfo->ucScreenCol-3)
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

//extern int32_t Tilt_sy; // NOTE : not used
void algorithm_baseline_calculate_local_mux_range(int r, int c)
{
	int sub_r = r;
	
//	if(currentRowStart == sensingRowStart)
	{
		//#if 0
		#ifdef TILT_ON		
		if(Tilt_sy<-150)
		//if(Tilt_sy<0)
		{
			if(sub_r - currentRowStart < 4)sub_r=currentRowStart-2;
			else if(sub_r - currentRowStart > 5)sub_r=currentRowStart+2;
			else sub_r=currentRowStart;	
		}
		else 
		if(Tilt_sy>150)
		{
			if(sub_r - currentRowStart < 2)sub_r=currentRowStart-2;
			else if(sub_r - currentRowStart > 3)sub_r=currentRowStart+2;
			else sub_r=currentRowStart;	
		}	
		else sub_r = (((sub_r+1)>>1)<<1)-MAX_MUX_HALF;
		#else
		sub_r = (((sub_r+1)>>1)<<1)-MAX_MUX_HALF;
		#endif
		
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
	else if(c+MAX_MUX_HALF > thisInfo->ucScreenCol)
	{
		thisInfo->tPenInfo.ucCurrentColumnStart = thisInfo->ucScreenCol - MAX_MUX_SIZE;
		thisInfo->tPenInfo.ucCurrentColumnEnd = thisInfo->ucScreenCol;
	}
	else
	{
		thisInfo->tPenInfo.ucCurrentColumnStart = c-MAX_MUX_HALF;
		thisInfo->tPenInfo.ucCurrentColumnEnd = c+MAX_MUX_HALF;
	}
}

int local_max_r = 0;
int local_max_delta = 0;
extern uint16_t p_currentRowStart;

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
			if(0 <= r && r < 8)
			{
				if(0 <= c && c < thisInfo->ucScreenCol)
				{
					sum_val += HAL_READ_LOCAL_DELTA_IMAGE(r,c);
				}
			}
		}
	}
	
	return sum_val;
}

#define RING_GPENTH1		30
#define RING_GPENTH2		60

#ifdef COVER_GLASS_USE
	#define GPENTH1		40
	#define GPENTH2		150
	int add_th = 250;
	int add_th1 = 60;
#else
	#define GPENTH1		30
	#define GPENTH2		120
	int add_th = 250;
	int add_th1 = 60;
#endif

__IO int gPen_th1 = GPENTH1, gPen_th2 = GPENTH2;

extern int check_frm;
extern volatile int gDCFullMode;
extern 	ePartialSensing_t g_RetVal;
uint8_t ring_rs = 0;
uint8_t row_start = 0;
uint8_t tip_rs = 0;
extern int Tilt_cnt;
bool_t algorithm_local_baseline_calculate_delta(int mode)
{
	int r, c;
	int delta,delta_th;
	int start_r, end_r;
	int start_c, end_c;
	int local_rs, local_cs;
	int pen_touch_data = 0;
	uint16_t read_raw_data;
	tCell_t pen_pos;
	int prev_max_state;
	int pen_sum_TData;
	
	dbgdsp_b_code[0]++;

	if(thisInfo->tDelta_local.sPrevMaxDelta2 < 30)
		prev_max_state = 1;
	else if(pen_touch_data <= 80)
		prev_max_state = 2;
	else
		prev_max_state = 0;
		
//	thisInfo->bBlockTracking = NO;

	local_rs = currentRowStart;
	local_cs = currentColStart;

	thisInfo->tPenInfo.ucCoordiRowStart = local_rs;
	thisInfo->tPenInfo.ucCoordiColumnStart = local_cs;

	start_r = 0, start_c = 0;
	end_r = 8, end_c = thisInfo->ucScreenCol;
	
	if(local_rs == MUX_MAX_ROW)
		end_r = 8;
	
	if(local_rs == 32 && mode == LOCAL_SEARCH_MODE)
		end_r = 7;

	memset((void *)(&thisInfo->tDelta_local), 0x00, sizeof(tOrigDeltaInfo_t));

	thisInfo->tDelta_local.tValidRect.cs = COL_MAX - 1;
	thisInfo->tDelta_local.tValidRect.ce = 0;
	thisInfo->tDelta_local.tValidRect.rs = ROW_MAX - 1;
	thisInfo->tDelta_local.tValidRect.re = 0;

	for( r=start_r; r<end_r; r++ )
	{
		for( c=start_c; c<end_c; c++ )
		{
			dbgdsp_b_code[1]++;
			read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r,c);
			delta = (signed)HAL_READ_LOCAL_BASELINE_IMAGE(r+local_rs,c) - (signed)read_raw_data;		// pen use
//			delta = (signed)read_raw_data - (signed)HAL_READ_LOCAL_BASELINE_IMAGE(r+local_rs,c);		// finger use


			delta >>= (ptModuleModeConf->ucLocalOvrShift);
			

// Hover mode 현재 진입하지 않음
//			if(mode == LOCAL_HOVER_MODE)
//			{
//				dbgdsp_b_code[2]++;
//				int delta2;
////				delta = HAL_READ_LOCAL_PENPRINT_IMAGE(r,c);
//				delta2 = HAL_READ_LOCAL_DELTA_IMAGE(r, c);
//
//				switch(prev_max_state)
//				{
////					case 1:
////						delta = (delta2*(check_frm-1) + delta*check_frm + 10)/check_frm;
////					break;
//
//					case 2:
//						delta = (delta2*(check_frm-1) + delta*check_frm - (delta2>>1))/check_frm;
//					break;
//
//					case 0:
//						delta = (delta2*(check_frm-1) + delta*check_frm)/check_frm;
//					break;
//
//					default:
//						delta = (delta2*(check_frm-1) + delta*check_frm)/check_frm;
//					break;
//				}
//			}
//			else if(mode == LOCAL_SEARCH_MODE)
//			{
//				dbgdsp_b_code[3]++;
//				delta += HAL_READ_LOCAL_SEARCH_IMAGE(r+local_rs, c);
//				HAL_WRITE_LOCAL_SEARCH_IMAGE(r+local_rs, c, delta);
//			}
/////////////////////////////////////
			
			HAL_WRITE_LOCAL_DELTA_IMAGE(r, c, delta);
			
			if( delta > 0 )
			{
				dbgdsp_b_code[4]++;
//				if( delta > thisModeConf->BaseLine.sBlockPosThd )
//				{
//					thisInfo->bBlockTracking = YES;
//				}

				if( delta > thisModeConf->BaseLine.sAccumPosSumThd )
				{
					thisInfo->tDelta_local.iPosCnt++;
					thisInfo->tDelta_local.iPosSum += delta - thisModeConf->BaseLine.sAccumPosSumThd;
				}

				#ifdef TILT_ON
				if(g_RetVal==PARTIAL_PEN_COORD2 && mode != LOCAL_HOVER_MODE)delta_th = 10;
				else 
				#endif
					delta_th = thisModeConf->Label.usLocalSeedBase;
					
				if( delta > delta_th)
				//if( delta > thisModeConf->Label.usLocalSeedBase )
				{
					dbgdsp_b_code[5]++;
					if( thisInfo->tDelta_local.tValidRect.cs > c )
						thisInfo->tDelta_local.tValidRect.cs = c;
					if( thisInfo->tDelta_local.tValidRect.ce < c )
						thisInfo->tDelta_local.tValidRect.ce = c;
					if( thisInfo->tDelta_local.tValidRect.rs > r )
						thisInfo->tDelta_local.tValidRect.rs = r;
					if( thisInfo->tDelta_local.tValidRect.re < r )
						thisInfo->tDelta_local.tValidRect.re = r;

					thisInfo->tDelta_local.iGroupedCellCnt++;
				}

				if( thisInfo->tDelta_local.iMaxStrength < delta )
				{
					dbgdsp_b_code[6]++;
					thisInfo->tDelta_local.iMaxStrength = delta;
					pen_touch_data = delta;
					pen_pos.r = r;
					pen_pos.c = c;
					thisInfo->tDelta_local.tMaxCellPos.r = r;
					thisInfo->tDelta_local.tMaxCellPos.c = c;
				}
			}
			else
			{
				dbgdsp_b_code[7]++;
//				if( delta < thisModeConf->BaseLine.sBlockNegThd )
//				{
//					thisInfo->bBlockTracking = YES;
//				}

				if( delta < thisModeConf->BaseLine.sAccumNegSumThd )
				{
					thisInfo->tDelta_local.iNegCnt++;
					thisInfo->tDelta_local.iNegSum += delta - thisModeConf->BaseLine.sAccumNegSumThd;
				}

				if( thisInfo->tDelta_local.iMinStrength > delta )
				{
					thisInfo->tDelta_local.iMinStrength = delta;
				}

			}
			HAL_WRITE_LOCAL_LABEL_IMAGE(r, c, 0);
		}
	}

//	thisInfo->bTouchExpect_local = (thisInfo->tDelta_local.iGroupedCellCnt > 0);
	

	local_max_r = pen_pos.r+local_rs;
	local_max_delta = pen_touch_data;
	thisInfo->tDelta_local.sPrevMaxDelta2 = pen_touch_data;

	pen_sum_TData = algorithm_calc_3by3LocalDeltaSum(pen_pos);	// 3by3 sum
	
	if (pen_touch_data > gPen_th1 || pen_sum_TData > gPen_th2)// && thisInfo->bTouchExpect_local)
#ifdef TILT_ON
			|| (g_RetVal==PARTIAL_PEN_COORD2 && (pen_touch_data > RING_GPENTH1 || pen_sum_TData > RING_GPENTH2))
#endif
	{
		dbgdsp_b_code[8]++;
		if(mode != LOCAL_SEARCH_MODE)
		{
			dbgdsp_b_code[9]++;
			thisInfo->bLocal_sensing = YES;
#ifdef DC_BASE
			#ifndef TILT_ON
			if(thisInfo->bTouchExpect_local == YES && thisInfo->tDelta_local.iGroupedCellCnt == 0)
			{
				gPen_th1 += add_th1;
				gPen_th2  += add_th;
			}
//			else if(thisInfo->bTouchExpect_local == NO)
//				gPen_th2 = GPENTH2-30;
			#endif
#endif
			thisInfo->bTouchExpect_local = (thisInfo->tDelta_local.iGroupedCellCnt > 0);
		}

#ifdef DC_BASE
		if(gDCFullMode != 2)		// local finger와 충동 방지
			gDCFullMode = 0;
#endif

		//#if 0
		#ifdef TILT_ON
		if(mode == LOCAL_MODE){
//			if(Tilt_cnt>1){
//				if(g_RetVal==PARTIAL_PEN_COORD1)row_start = ring_rs;
//				else 
				if(g_RetVal==PARTIAL_PEN_COORD2)row_start = tip_rs;
				else row_start = pen_pos.r + local_rs;
//			}
//			
//			if(g_RetVal==PARTIAL_PEN_COORD2)ring_rs = pen_pos.r + local_rs;
//			else 
			if(g_RetVal==PARTIAL_PEN_COORD1)tip_rs = pen_pos.r + local_rs;
		}
		else row_start = pen_pos.r + local_rs;
		
		algorithm_baseline_calculate_local_mux_range(row_start, pen_pos.c);
		#else
		algorithm_baseline_calculate_local_mux_range(pen_pos.r+local_rs, pen_pos.c);
		#endif
	}
	else
	{
		dbgdsp_b_code[10]++;
		#ifndef TILT_ON
		if(thisInfo->bTouchExpect_local == YES)
		{
			gPen_th1 += add_th1;
			gPen_th2  += add_th;
		}
		#endif
		thisInfo->bLocal_sensing = NO;
		thisInfo->bTouchExpect_local = NO;
	}
	
	#ifndef TILT_ON
	gPen_th1 = (gPen_th1 > GPENTH1) ? gPen_th1-10 : GPENTH1;
	if(gPen_th2 > GPENTH2)
		gPen_th2 = gPen_th2-10;
	else if(gPen_th2 < GPENTH2)
		gPen_th2 = gPen_th2+1;
	#endif

//	protocol_LogPaddedMatrix(LT_INTENSITY, 84, HAL_GET_LOCAL_DELTA_IMAGE_PTR(), COL_MAX, 8, 84/*MAX Intensity*/);

	return 0; //thisInfo->bBlockTracking;
}

extern uint16_t currentRowStart;

static void init_local_DSP(void)
{
	tDSPAOpHandleInfo_t tDSPAHandleInfo;

	tDSPAHandleInfo.ulPanelRowNum = 8;
	tDSPAHandleInfo.ulPanelColNum = COL_MAX;
	tDSPAHandleInfo.ulPanelDataNumIncludePad = ((8 + (PAD_<<1)) * (COL_MAX + (PAD_<<1)));
	tDSPAHandleInfo.ulRawDataBufAddr = (uint32_t)(&LocalSharedBuff.MatrixU16_PenBase[0][0]);
	tDSPAHandleInfo.ulBaselineBufAddr = (uint32_t)(&LocalSharedBuff.MatrixU16_PenCoordRawdata[0][0]);
	tDSPAHandleInfo.ulNomalizeBufAddr = NULL;
	tDSPAHandleInfo.ulIntensityBufAddr = (uint32_t)(&LocalSharedBuff.MatrixS16_PenDelta[0][0]);
	tDSPAHandleInfo.ulPadEn = (PAD_ > 0 ? ENABLE : DISABLE);
	tDSPAHandleInfo.ulPadSize = PAD_;
	tDSPAHandleInfo.ulPadData = 0;
	tDSPAHandleInfo.ulNormalizeEn = ENABLE;
	tDSPAHandleInfo.ulNormalizeShiftLevel = 6;
	tDSPAHandleInfo.ulIntensityBitShiftLevel = 5;
	tDSPAHandleInfo.ulPositiveThreshold = 10;
	tDSPAHandleInfo.lNegativeThreshold = -10;
	tDSPAHandleInfo.ulGroupThreshold = 10;

	DSPA_Initialize(&tDSPAHandleInfo);

//	int RowNum, ColNum, PadEn, PadSize;

	//********************************************************
	// Interrupt Enable 
	//********************************************************
//	NVIC_EnableIRQ (DSP_A_IRQn);    /* Interrupt Enable */
	
	
//	DSPA->HWACC_CTRL.tBit.Init = 0x1;
//	DSPA->RAW_ADDR  = (uint32_t)(&LocalSharedBuff.MatrixU16_PenBase[0][0]);//MatrixU16_PenBase[currentRowStart];//MatrixU16_3[currentRowStart]; //inverse input
//	DSPA->BASE_ADDR = (uint32_t)(&LocalSharedBuff.MatrixU16_PenCoordRawdata[0][0]);//MatrixU16_PenCoord;//inverse input
//	DSPA->NMLZ_ADDR = (uint32_t)(&LocalSharedBuff.MatrixU16_NormalizeCopy[currentRowStart][0]);
//	DSPA->DEST_ADDR = (uint32_t)(&LocalSharedBuff.MatrixS16_PenDelta[0][0]);//MatrixS16_PenDelta;
	
//	DSPA->NMLZ_CTRL.tBit.NmlzEn =1;
//	DSPA->NMLZ_CTRL.tBit.NmlzShift = 6;
//	DSPA->BIT_SHIFT.tBit.BitShift = 5;
//
//	// Padding
//	DSPA->PAD_CTRL.tBit.PadEn = 0x1;
//	DSPA->PAD_CTRL.tBit.PadSize = 0x1;
//	DSPA->PAD_CTRL.tBit.PadData = 0x0;
	
	//LIimit setting
//	DSPA->UPR_LIMIT.tBit.UpperLimit = 10;
//	DSPA->LWR_LIMIT.tBit.LowerLimit = (uint32_t)(-10); // NOTE : warning제거
//	DSPA->THRESHOLD.tBit.Threshold = 10;

	// Panel Size Setup
//	DSPA->SIZE_CTRL.tBit.RowNum = 8;
//	DSPA->SIZE_CTRL.tBit.ColNum =  COL_MAX;
//	RowNum =  DSPA->SIZE_CTRL.tBit.RowNum;
//	ColNum = DSPA->SIZE_CTRL.tBit.ColNum;
//
//	PadEn = DSPA->PAD_CTRL.tBit.PadEn;
//	PadSize = DSPA->PAD_CTRL.tBit.PadSize;
//	if((PadEn==0) | (PadSize == 0))
//	DSPA->SIZE_CTRL.tBit.DataLen = RowNum*ColNum;
//	else
//	DSPA->SIZE_CTRL.tBit.DataLen = (RowNum+2*PadSize)*(ColNum+2*PadSize);
//
//	// Interrupt
//	DSPA->ITRPT_CTRL.tBit.ItrptEn = 1;
	
}

#if 1
//extern __IO int  __IS_COMPLETE_DSPA__;

bool_t algorithm_local_baseline_calculate_delta_DSP(int mode)
{
//	int r, c; // NOTE : warning제거
	int local_rs, local_cs;
//	int pen_touch_data = 0;
//	int RowNum, ColNum, PadEn, PadSize; // NOTE : warning제거
	tDSPAOutPutInfo_t tDSPAOutPutInfo;
	
//	tCell_t pen_pos;
	tOrigDeltaInfo_t * temp_delta;
	
//	thisInfo->bBlockTracking = NO;	

	local_rs = currentRowStart;
	local_cs = thisInfo->tPenInfo.ucCurrentColumnStart;

	thisInfo->tPenInfo.ucCoordiRowStart = local_rs;
	thisInfo->tPenInfo.ucCoordiColumnStart = local_cs;

	temp_delta = &thisInfo->tDelta_local;

	memset((void *)temp_delta, 0x00, sizeof(tOrigDeltaInfo_t));
	
	init_local_DSP();
	DSPA_Start(YES, &tDSPAOutPutInfo);

//		__IS_COMPLETE_DSPA__=FALSE;
//	DSPA->HWACC_CTRL.tBit.SwStr = 0x1;
//	while(__IS_COMPLETE_DSPA__ == FALSE){	};
	
	
//	pen_touch_data = ptOutPutInfo->usPositiveMaxData;
//	pen_pos.r = ptOutPutInfo->ulPositiveMaxData_RowIdx;
//	pen_pos.c = ptOutPutInfo->ulPositiveMaxData_ColIdx;

	
 //======================= 	positive ============================
	
	temp_delta->iGroupedCellCnt = tDSPAOutPutInfo.ulTouchAreaCellNum;
	
//		if(temp_delta->iGroupedCellCnt)
//			thisInfo->bBlockTracking = YES;
		
	temp_delta->iPosCnt = tDSPAOutPutInfo.ulPositiveCellNum;
	temp_delta->iPosSum = tDSPAOutPutInfo.ulPositiveCellTotalSum;
	temp_delta->tValidRect.cs = tDSPAOutPutInfo.ulTouchAreaCol_sIdx;
	temp_delta->tValidRect.ce = tDSPAOutPutInfo.ulTouchAreaCol_eIdx;
	temp_delta->tValidRect.rs = tDSPAOutPutInfo.ulTouchAreaRow_sTdx;
	temp_delta->tValidRect.re = tDSPAOutPutInfo.ulTouchAreaRow_eIdx;
	temp_delta->iMaxStrength  = tDSPAOutPutInfo.usPositiveMaxData;
		

	//======================= 	negative =============================		
//	if(DSPA->M_MAX_VAL.tBit.MinusMaxVal<-12)
//	{
//		thisInfo->bBlockTracking = YES;
//	}

	temp_delta->iNegCnt = tDSPAOutPutInfo.ulNegativeCellNum;
	temp_delta->iNegSum = tDSPAOutPutInfo.lNegativeCellTotalSum;
	temp_delta->iMinStrength = tDSPAOutPutInfo.sNegativeMaxData;

//================================================================	

	thisInfo->bTouchExpect_local = (temp_delta->iGroupedCellCnt > 0);
	
	local_max_r = tDSPAOutPutInfo.ulPositiveMaxData_RowIdx + local_rs;
	local_max_delta = tDSPAOutPutInfo.usPositiveMaxData;
	
	if(tDSPAOutPutInfo.usPositiveMaxData > 20 && thisInfo->bTouchExpect_local)
	{
	    thisInfo->bLocal_sensing = YES;		

		algorithm_baseline_calculate_local_mux_range(tDSPAOutPutInfo.ulPositiveMaxData_RowIdx + local_rs, tDSPAOutPutInfo.ulPositiveMaxData_ColIdx);
	}
	else
	{
		thisInfo->bLocal_sensing = NO;
		thisInfo->bTouchExpect_local = NO;
	}

	return 0; //thisInfo->bBlockTracking;
}

#else
bool_t algorithm_local_baseline_calculate_delta_DSP(int mode)
{
	int r, c;
	int delta;
	int start_r, end_r;
	int start_c, end_c;
	int local_rs, local_cs;
	int pen_touch_data = 0;
	uint16_t read_raw_data;
	tCell_t pen_pos;

	
	tOrigDeltaInfo_t	*temp_delta;
	
//	thisInfo->bBlockTracking = NO;	

	local_rs = currentRowStart;
	local_cs = currentColStart;

	thisInfo->tPenInfo.ucCoordiRowStart = local_rs;
	thisInfo->tPenInfo.ucCoordiColumnStart = local_cs;

	start_r = 0, start_c = 0;
	end_r = 8, end_c = thisInfo->ucScreenCol;
	temp_delta = &thisInfo->tDelta_local;

	memset((void *)temp_delta, 0x00, sizeof(tOrigDeltaInfo_t));
	temp_delta->tValidRect.cs = COL_MAX - 1; temp_delta->tValidRect.ce = 0;
	temp_delta->tValidRect.rs = ROW_MAX - 1; temp_delta->tValidRect.re = 0;
	
	
	init_local_DSP();

	__IS_COMPLETE_DSPA__=FALSE;
	DSPA->HWACC_CTRL.tBit.SwStr = 0x1;
	while(__IS_COMPLETE_DSPA__ == FALSE){	};
	
	
//				pen_touch_data = DSPA->P_MAX_VAL.tBit.PlusMaxVal;
//				pen_pos.r = DSPA->P_MAX_POS.tBit.PlusMaxRow;
//				pen_pos.c = DSPA->P_MAX_POS.tBit.PlusMaxCol;

	
	for( r=start_r; r<8; r++ )
	{
		for( c=start_c; c<COL_MAX; c++ )
		{
			delta =(HAL_READ_LOCAL_DELTA_IMAGE(r, c));
			delta = -delta;
			
			HAL_WRITE_LOCAL_DELTA_IMAGE(r,c,delta);
			
				if( temp_delta->iMaxStrength < delta )
			{
//				temp_delta->iMaxStrength = delta;
				pen_touch_data = delta;
				pen_pos.r = r;
				pen_pos.c = c;
			}
			
	
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

				if( delta > thisModeConf->Label.usLocalSeedBase )
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
//					pen_touch_data = delta;
//					pen_pos.r = r;
//					pen_pos.c = c;
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
				}

			}
			HAL_WRITE_LOCAL_LABEL_IMAGE(r, c, 0);
			//HAL_WRITE_LOCAL_LABEL_LINKLIST_IMAGE(r, c, 0);			
		}
		
	}

	thisInfo->bTouchExpect_local = (temp_delta->iGroupedCellCnt > 0);
	
	local_max_r = pen_pos.r+local_rs;
	local_max_delta = pen_touch_data;
	
	if(pen_touch_data > 20 | thisInfo->bTouchExpect_local)
	{
	    thisInfo->bLocal_sensing = YES;		

		algorithm_baseline_calculate_local_mux_range(pen_pos.r+local_rs, pen_pos.c);
			
//		currentRowStart = sensingRowStart;
	}
	else
	{
		thisInfo->bLocal_sensing = NO;
		thisInfo->bTouchExpect_local = NO;
	}
	
//	protocol_LogPaddedMatrix(LT_INTENSITY, thisInfo->ucScreenCol, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, thisInfo->ucScreenRow, 81/*MAX Intensity*/);

	return 0; //thisInfo->bBlockTracking;
}
#endif

#define DETECT_TH		15
#define HOVER_TH		300
uint8_t data_store_bit[7][8] = {0,};
int16_t hover_data_store_bit[7] = {0,};
int16_t debug_hover_data_store_bit[7] = {0,};
extern uint16_t g_pendata_pressure;
extern uint8_t g_pen_button1;
extern uint8_t g_pen_button2;
uint8_t contact1 = 0;
uint8_t contact2 = 0;

typedef struct {
	int8_t data1_1;
	int8_t data1_2;
	int8_t data2_1;
	int8_t data2_2;
	int8_t data3_1;
	int8_t data3_2;
	int8_t data4_1;
	int8_t data4_2;
	int8_t data5_1;
	int8_t data5_2;
} stPenDataParse_t;

typedef struct {
	int8_t data1_Max;
	int8_t data1_Min;
	int8_t data2_Max;
	int8_t data2_Min;
	int8_t data3_Max;
	int8_t data3_Min;
	int8_t data4_Max;
	int8_t data4_Min;
	int8_t data5_Max;
	int8_t data5_Min;
} stPenDataVal;

stPenDataParse_t stPendataParse;

bool_t algorithm_local_data_baseline_calculate_delta(ePartialSensing_t RetVal)
{
	int r, c;
	int delta;
//	int start_r, end_r;
//	int start_c, end_c;
//	int local_rs, local_cs;
//	int local_rs;
//	int16_t read_raw_data;
	int16_t detectThd = 500;
//	int16_t stableRange_thd = 200;
//	uint8_t idx = 0;
//	uint32_t maxVal = 0;
//	int32_t minVal = 0;

	int16_t pendata_max_1mux[5] = { 0, };
	int16_t pendata_min_1mux[5] = { 0, };
	int16_t pendata_max_2mux[5] = { 0, };
	int16_t pendata_min_2mux[5] = { 0, };

	uint8_t penDataIdx = (RetVal - PARTIAL_PEN_DATA1);

//	local_rs = currentRowStart;
//	local_cs = thisInfo->tPenInfo.ucCurrentColumnStart;
//	start_r = 0;
//	start_c = local_cs;
//	end_r = PEN_DATA_ROW_MAX;

	// Calc penData delta
//	for(r = 0; r < 16; r++)
//	{
//		for( c = 0; c < COL_MAX; c++)
//		{
//			idx = r + local_rs ;
//			if( idx < 48 )
//			{
//				delta = HAL_READ_LOCAL_DATA_BASELINE_IMAGE(idx, c) - HAL_READ_LOCAL_DATA_RAW_IMAGE(r, c);
//				HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r, c, delta);
//			}
//			else
//			{
//				idx = idx - 8;
//				delta = HAL_READ_LOCAL_DATA_BASELINE_IMAGE(idx, c) - HAL_READ_LOCAL_DATA_RAW_IMAGE(r, c);
//				HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r, c, delta);
//			}
//		}
//	}

	// 각 LHB MUX의 min, max 값 저장
	for(r = 0; r < 16; r++)
	{
		for( c = 0; c < COL_MAX; c++)
		{
//			idx = r + local_rs;
//			if(idx > 48)
//			{
//				idx = idx - 8;
//			}

//			delta = HAL_READ_LOCAL_DATA_BASELINE_IMAGE(idx, c) - HAL_READ_LOCAL_DATA_RAW_IMAGE(r, c);//HAL_READ_LOCAL_DATA_DELTA_IMAGE(r, c);
			delta = HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r, c) - HAL_READ_LOCAL_DATA_RAW_IMAGE(r, c);//HAL_READ_LOCAL_DATA_DELTA_IMAGE(r, c);

			if( ( r % 2 ) == 0) // 1 mux
			{
				if( delta > pendata_max_1mux[penDataIdx]  )
				{
					pendata_max_1mux[penDataIdx] = delta;
				}

				if( delta < pendata_min_1mux[penDataIdx] )
				{
					pendata_min_1mux[penDataIdx] = delta;
				}
			}
			else                // 2 mux
			{
				if( delta > pendata_max_2mux[penDataIdx]  )
				{
					pendata_max_2mux[penDataIdx] = delta;
				}

				if( delta < pendata_min_2mux[penDataIdx] )
				{
					pendata_min_2mux[penDataIdx] = delta;
				}
			}
		}
	}


	switch( RetVal )
	{
		case PARTIAL_PEN_DATA1:
		{
			if(pendata_max_1mux[0] > detectThd )
			{
				stPendataParse.data1_1 = 1;
			}
			else if(pendata_max_1mux[0] < -detectThd)
			{
				stPendataParse.data1_1 = -1;
			}
			else
			{
				stPendataParse.data1_1 = 0;
			}

			if(pendata_max_2mux[0] > detectThd )
			{
				stPendataParse.data1_2 = 1;
			}
			else if(pendata_max_2mux[0] < -detectThd)
			{
				stPendataParse.data1_2 = -1;
			}
			else
			{
				stPendataParse.data1_2 = 0;
			}

		}
		break;
		case PARTIAL_PEN_DATA2:
		{
			if(pendata_max_1mux[1] > detectThd )
			{
				stPendataParse.data2_1 = 1;
			}
			else if(pendata_max_1mux[1] < -detectThd)
			{
				stPendataParse.data2_1 = -1;
			}
			else
			{
				stPendataParse.data2_1 = 0;
			}

			if(pendata_max_2mux[1] > detectThd )
			{
				stPendataParse.data2_2 = 1;
			}
			else if(pendata_max_2mux[1] < -detectThd)
			{
				stPendataParse.data2_2 = -1;
			}
			else
			{
				stPendataParse.data2_2 = 0;
			}
		}
		break;
		case PARTIAL_PEN_DATA3:
		{
			if(pendata_max_1mux[2] > detectThd )
			{
				stPendataParse.data3_1 = 1;
			}
			else if(pendata_max_1mux[2] < -detectThd)
			{
				stPendataParse.data3_1 = -1;
			}
			else
			{
				stPendataParse.data3_1 = 0;
			}

			if(pendata_max_2mux[2] > detectThd )
			{
				stPendataParse.data3_2 = 1;
			}
			else if(pendata_max_2mux[2] < -detectThd)
			{
				stPendataParse.data3_2 = -1;
			}
			else
			{
				stPendataParse.data3_2 = 0;
			}
		}
		break;
		case PARTIAL_PEN_DATA4:
		{
			if(pendata_max_1mux[3] > detectThd )
			{
				stPendataParse.data4_1 = 1;
			}
			else if(pendata_max_1mux[3] < -detectThd)
			{
				stPendataParse.data4_1 = -1;
			}
			else
			{
				stPendataParse.data4_1 = 0;
			}

			if(pendata_max_2mux[3] > detectThd )
			{
				stPendataParse.data4_2 = 1;
			}
			else if(pendata_max_2mux[3] < -detectThd)
			{
				stPendataParse.data4_2 = -1;
			}
			else
			{
				stPendataParse.data4_2 = 0;
			}
		}
		break;
		case PARTIAL_PEN_DATA5:
		{
			if(pendata_max_1mux[4] > detectThd )
			{
				stPendataParse.data5_1 = 1;
			}
			else if(pendata_max_1mux[4] < -detectThd)
			{
				stPendataParse.data5_1 = -1;
			}
			else
			{
				stPendataParse.data5_1 = 0;
			}

			if(pendata_max_2mux[4] > detectThd )
			{
				stPendataParse.data5_2 = 1;
			}
			else if(pendata_max_2mux[4] < -detectThd)
			{
				stPendataParse.data5_2 = -1;
			}
			else
			{
				stPendataParse.data5_2 = 0;
			}
		}
		break;
	}

	return 0; //thisInfo->bBlockTracking;
}
//bool_t algorithm_local_data_baseline_calculate_delta(ePartialSensing_t RetVal)
//{
//	static int16_t hover_base = 0;
//	int r, c;
//	int delta;
//	int start_r, end_r;
//	int start_c, end_c;
//	int local_rs, local_cs;
////	int pen_touch_data = 0;
//	uint16_t read_raw_data;
//
//	int store_row = (RetVal - PARTIAL_PEN_DATA1);
//
////	thisInfo->bBlockTracking = NO;
//
//	local_rs = (currentRowStart>>1);
//	local_cs = thisInfo->tPenInfo.ucCurrentColumnStart;
//
////	thisInfo->tPenInfo.ucCoordiRowStart = local_rs;
////	thisInfo->tPenInfo.ucCoordiColumnStart = local_cs;
//
//	start_r = 0, start_c = local_cs;
//	end_r = 8, end_c = thisInfo->tPenInfo.ucCurrentColumnEnd;//end_c = local_cs+8;
//
////	if(local_rs == MUX_MAX_ROW)
////		end_r = 7;
//
//	{
////		int16_t negSum_data[4] = {0,};
////		int16_t posSum_data[4] = {0,};
//		int16_t pendata_min[4] = {0,};
//		int16_t pendata_max[4] = {0,};
//
//		for( r=start_r; r<(end_r>>1); r++ )
//		{
//			for( c=start_c; c<end_c; c++ )
//			{
//				read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r,c);
//				delta = (signed)HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r+local_rs,c) - (signed)read_raw_data;		// pen use
////				if(delta < 0)	negSum_data[0] += delta;
////				if(delta > 0)	posSum_data[0] += delta;
//				if(delta < pendata_min[0])		pendata_min[0] = delta;
//				if(delta > pendata_max[0])		pendata_max[0] = delta;
//				hover_data_store_bit[store_row] += delta;
//
//				read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+8,c);
//				delta = (signed)HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r+local_rs,c) - (signed)read_raw_data;		// pen use
////				if(delta < 0)	negSum_data[1] += delta;
////				if(delta > 0)	posSum_data[1] += delta;
//				if(delta < pendata_min[1])		pendata_min[1] = delta;
//				if(delta > pendata_max[1])		pendata_max[1] = delta;
//				hover_data_store_bit[store_row] += delta;
//
//				read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+16,c);
//				delta = (signed)HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r+local_rs,c) - (signed)read_raw_data;		// pen use
////				if(delta < 0)	negSum_data[2] += delta;
////				if(delta > 0)	posSum_data[2] += delta;
//				if(delta < pendata_min[2])		pendata_min[2] = delta;
//				if(delta > pendata_max[2])		pendata_max[2] = delta;
//				hover_data_store_bit[store_row] += delta;
//
//				read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+24,c);
//				delta = (signed)HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r+local_rs,c) - (signed)read_raw_data;		// pen use
////				if(delta < 0)	negSum_data[3] += delta;
////				if(delta > 0)	posSum_data[3] += delta;
//				if(delta < pendata_min[3])		pendata_min[3] = delta;
//				if(delta > pendata_max[3])		pendata_max[3] = delta;
//				hover_data_store_bit[store_row] += delta;
//			}
//		}
//
//		for(c=0; c<4; c++)
//		{
////			if(negSum_data[c] < -DETECT_TH)
////				data_store_bit[store_row][c*2] = 1;
////			else if(posSum_data[c] > DETECT_TH)
////				data_store_bit[store_row][c*2] = 0;
////			else
////				data_store_bit[store_row][c*2] = 2;
//
////			if(pendata_min[c] < -DETECT_TH)
////				data_store_bit[store_row][c*2] = 1;
////			else if(pendata_max[c] > DETECT_TH)
////				data_store_bit[store_row][c*2] = 0;
////			else
////				data_store_bit[store_row][c*2] = 2;
//
//			pendata_min[c] = - pendata_min[c];
//			if((pendata_min[c] > pendata_max[c]) && (pendata_min[c] > DETECT_TH))
//				data_store_bit[store_row][c*2] = 1;
//			else if((pendata_min[c] <= pendata_max[c]) && (pendata_max[c] > DETECT_TH))
//				data_store_bit[store_row][c*2] = 0;
//			else
//				data_store_bit[store_row][c*2] = 2;
//
////			negSum_data[c] = 0;
////			posSum_data[c] = 0;
//			pendata_min[c] = 0;
//			pendata_max[c] = 0;
//		}
//	}
//
//	{
////		int16_t negSum_data[4] = {0,};
////		int16_t posSum_data[4] = {0,};
//		int16_t pendata_min[4] = {0,};
//		int16_t pendata_max[4] = {0,};
//
//		for( r=(end_r>>1); r<end_r; r++ )
//		{
//			for( c=start_c; c<end_c; c++ )
//			{
//				read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r,c);
//				delta = (signed)HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r+local_rs-(end_r>>1),c) - (signed)read_raw_data;		// pen use
////				if(delta < 0)	negSum_data[0] += delta;
////				if(delta > 0)	posSum_data[0] += delta;
//				if(delta < pendata_min[0])		pendata_min[0] = delta;
//				if(delta > pendata_max[0])		pendata_max[0] = delta;
//				hover_data_store_bit[store_row] += delta;
//
//				read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+8,c);
//				delta = (signed)HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r+local_rs-(end_r>>1),c) - (signed)read_raw_data;		// pen use
////				if(delta < 0)	negSum_data[1] += delta;
////				if(delta > 0)	posSum_data[1] += delta;
//				if(delta < pendata_min[1])		pendata_min[1] = delta;
//				if(delta > pendata_max[1])		pendata_max[1] = delta;
//				hover_data_store_bit[store_row] += delta;
//
//				read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+16,c);
//				delta = (signed)HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r+local_rs-(end_r>>1),c) - (signed)read_raw_data;		// pen use
////				if(delta < 0)	negSum_data[2] += delta;
////				if(delta > 0)	posSum_data[2] += delta;
//				if(delta < pendata_min[2])		pendata_min[2] = delta;
//				if(delta > pendata_max[2])		pendata_max[2] = delta;
//				hover_data_store_bit[store_row] += delta;
//
//				read_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r+24,c);
//				delta = (signed)HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r+local_rs-(end_r>>1),c) - (signed)read_raw_data;		// pen use
////				if(delta < 0)	negSum_data[3] += delta;
////				if(delta > 0)	posSum_data[3] += delta;
//				if(delta < pendata_min[3])		pendata_min[3] = delta;
//				if(delta > pendata_max[3])		pendata_max[3] = delta;
//				hover_data_store_bit[store_row] += delta;
//			}
//		}
//
//		for(c=0; c<4; c++)
//		{
////			if(negSum_data[c] < -DETECT_TH)
////				data_store_bit[store_row][c*2+1] = 1;
////			else if(posSum_data[c] > DETECT_TH)
////				data_store_bit[store_row][c*2+1] = 0;
////			else
////				data_store_bit[store_row][c*2+1] = 2;
//
////			if(pendata_min[c] < -DETECT_TH)
////				data_store_bit[store_row][c*2+1] = 1;
////			else if(pendata_max[c] > DETECT_TH)
////				data_store_bit[store_row][c*2+1] = 0;
////			else
////				data_store_bit[store_row][c*2+1] = 2;
//
//			pendata_min[c] = - pendata_min[c];
//			if((pendata_min[c] > pendata_max[c]) && (pendata_min[c] > DETECT_TH))
//				data_store_bit[store_row][c*2+1] = 1;
//			else if((pendata_min[c] <= pendata_max[c]) && (pendata_max[c] > DETECT_TH))
//				data_store_bit[store_row][c*2+1] = 0;
//			else
//				data_store_bit[store_row][c*2+1] = 2;
//
////			negSum_data[c] = 0;
////			posSum_data[c] = 0;
//			pendata_min[c] = 0;
//			pendata_max[c] = 0;
//		}
//	}
//
//	switch(RetVal)
//	{
//		case PARTIAL_PEN_DATA1:
//		{
//			if(data_store_bit[0][0] == 0 && data_store_bit[0][1] == 1)
//			{
//				contact1 = YES;
//				thisInfo->tPenInfo.bPenContact = YES;
//
//				if(data_store_bit[0][2] == 1 && data_store_bit[0][2] == data_store_bit[0][3] && data_store_bit[0][2] == 1-data_store_bit[0][6])
//					g_pen_button1 = 1;
//				else
//					g_pen_button1 = 0;
//
//				if(data_store_bit[0][4] == 1 && data_store_bit[0][4] == data_store_bit[0][5] && data_store_bit[0][4] == 1-data_store_bit[0][7])
//					g_pen_button2 = 1;
//				else
//					g_pen_button2 = 0;
//			}
//			else if(thisInfo->tCoord_local.cIsbefor[0] > 0)
//			{
//				thisInfo->tPenInfo.bPenContact = YES;
//			}
//			else
//			{
//				contact1 = NO;
////				if(contact2 == NO)
//					thisInfo->tPenInfo.bPenContact = NO;
//				g_pendata_pressure = 1;
////#if 0	// hover시 사용 x
////				if(data_store_bit[0][0] == data_store_bit[0][1])
////				{
////					g_pen_button1 = 0;
////					g_pen_button2 = 0;
////				}
////#endif
//			}
//		}
//		break;
//
//		case PARTIAL_PEN_DATA2:
//		case LOCAL_PEN_DATA6:
//		{
//			if(data_store_bit[store_row][0] == 0 && data_store_bit[store_row][1] == 1)
//			{
//				contact2 = YES;
//				thisInfo->tPenInfo.bPenContact = YES;
//				
////				if(data_store_bit[5][0] == 1)
////					g_pen_button2 = 1;
////				else
////					g_pen_button2 = 0;
//			}
//			else if(thisInfo->tCoord_local.cIsbefor[0] > 0)
//			{
//				thisInfo->tPenInfo.bPenContact = YES;
//			}
//			else if(data_store_bit[store_row][0] == data_store_bit[store_row][1])
//			{
//				contact2 = NO;
////				if(contact1 == NO)
//					thisInfo->tPenInfo.bPenContact = NO;
//				g_pendata_pressure = 1;
////#if 0	// hover시 사용 x
////				if(data_store_bit[5][0] == data_store_bit[5][1])
////				{
////					g_pen_button1 = 0;
////					g_pen_button2 = 0;
////				}
////#endif
//			}
//		}
//		break;
//
//		case PARTIAL_PEN_DATA3:
//		case LOCAL_PEN_DATA7:
//		{
//			uint16_t pen_data_presure;
//			uint16_t check_sum_data;
//			uint8_t andBitCnt;
//			uint8_t checkMSB;
//			uint8_t checkLSB;
//			uint8_t ori_CheckMSB;
//			uint8_t ori_CheckLSB;
//
//			int add_row = 0;
//
//			if(RetVal == LOCAL_PEN_DATA7)
//				add_row = 4;
//
//			pen_data_presure = (data_store_bit[1+add_row][2]*3 + data_store_bit[1+add_row][3])<<0;
//			pen_data_presure += ((data_store_bit[1+add_row][4]*3 + data_store_bit[1+add_row][5])<<3);
//			pen_data_presure += ((data_store_bit[1+add_row][6]*3 + data_store_bit[1+add_row][7])<<6);
//			pen_data_presure += ((data_store_bit[2+add_row][1]*3 + data_store_bit[2+add_row][2])<<9);
//
//			check_sum_data = (pen_data_presure<<1) + data_store_bit[2+add_row][3];
//
//			andBitCnt = 0;
//			for(r=0; r<13; r++)
//			{
//				if((check_sum_data >> r) & 0x1)
//					andBitCnt++;
//			}
//
//			andBitCnt = (~andBitCnt) & 0x3f;
//
//			checkMSB = (andBitCnt & 0x7);
//			checkLSB = ((andBitCnt >> 3) & 0x7);
//
//			ori_CheckMSB = data_store_bit[2+add_row][4]*3 + data_store_bit[2+add_row][5];
//			ori_CheckLSB = data_store_bit[2+add_row][6]*3 + data_store_bit[2+add_row][7];
//
//			if(checkMSB == ori_CheckMSB && checkLSB == ori_CheckLSB)
//				andBitCnt = 1;
//			else
//				andBitCnt = 0;
//
////			switch(RetVal)
////			{
////				case PARTIAL_PEN_DATA3:
////				{
////					if(andBitCnt == 1)
////						g_pendata_pressure = pen_data_presure;
////				}
////				break;
////
////				case LOCAL_PEN_DATA7:
////					if(andBitCnt == 1)
////						g_pendata_pressure = pen_data_presure;
////				break;
////
////				default:
////				break;
////			}
//
//			if(andBitCnt == 1 && thisInfo->tCoord_local.cIsbefor[0] == 0)
//				g_pendata_pressure = pen_data_presure;
//
//			if(RetVal == LOCAL_PEN_DATA7)
//			{
//				if(thisInfo->tPenInfo.bPenContact == NO)
//				{
////					hover_base = (hover_data_store_bit[3] + hover_data_store_bit[4]) >> 1;
//					hover_base = (hover_data_store_bit[1] + hover_data_store_bit[5] + hover_data_store_bit[2] + hover_data_store_bit[6] + 2) >> 2;
//
//					if(hover_data_store_bit[1]-hover_base < -HOVER_TH && hover_data_store_bit[5]-hover_base > HOVER_TH)
//						g_pen_button1 = 1;
//					else
//						g_pen_button1 = 0;
//
//					if(hover_data_store_bit[2]-hover_base < -HOVER_TH && hover_data_store_bit[6]-hover_base > HOVER_TH)
//						g_pen_button2 = 1;
//					else
//						g_pen_button2 = 0;
//				}
//
//				for(r=0; r<7; r++)
//				{
//					debug_hover_data_store_bit[r] = hover_data_store_bit[r];
//					hover_data_store_bit[r] = 0;
//				}
//			}
//		}
//		break;
//
//		default:
//		break;
//	}
//
////	if(thisInfo->tPenInfo.bPenContact == NO && hover_base != 0)
////	{
////		switch(RetVal)
////		{
////			case PARTIAL_PEN_DATA1:
////			case PARTIAL_PEN_DATA2:
////			case PARTIAL_PEN_DATA3:
////			case LOCAL_PEN_DATA6:
////			case LOCAL_PEN_DATA7:
////			{
////				if(hover_data_store_bit[store_row]-hover_base < -HOVER_TH || hover_data_store_bit[store_row]-hover_base > HOVER_TH)
////				{
////					thisInfo->bLocal_sensing = NO;
////				}
////			}
////			break;
////		}
////	}
//
//	if(RetVal == LOCAL_PEN_DATA7)
//	{
////		protocol_LogMatrix(LT_RAWDATA, 72, HAL_GET_LOCAL_DATA_RAW_IMAGE_PTR(), 72, 32, 84/*MAX Intensity*/);
//	}
//
//	return 0; //thisInfo->bBlockTracking;
//}

void algorithm_local_baseline_init(void)
{
//	int r, c;

	memset((void*)HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
	memset((void*)HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
	/*
	 * TODO : MSB/LSB Concept적용 시 변경 해야함!!
	 */
	memset((void*)HAL_GET_LOCAL_DATA_BASELINE_IMAGE_PTR(), 0x00, sizeof(uint16_t)*((PEN_DATA_ROW_MAX/2) * COL_MAX));
}

#if 1
bool_t algorithm_local_baseline_tracking_initial(void)
{
	int r, c;
	uint32_t ulRowEnd = 8;
	uint16_t temp_data = 0;
//	int temp_raw_data;
	ePartialSensing_t lDataIndex = PARTIAL_PEN_BEACON;
	bool_t local_base_return_flag = NO;

	sensingRowStart = 0;

	module_wait_Vsync_signal(LOCAL_MODE, thisModeConf->BaseLine.ucDiscardFrameNum);	

    while(YES)
    {
		lDataIndex = module_wait_local_sample_done();

		if(lDataIndex == PARTIAL_FINGER6)
		{
			break;
		}
	}

	while(YES)
	{
		lDataIndex = module_wait_local_sample_done();
		
		switch(lDataIndex)
		{
//			case PARTIAL_PEN_COORD1:
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
					for(c = 0; c < thisInfo->ucCol; c++)
					{
						temp_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r, c);
						temp_data = HAL_READ_LOCAL_BASELINE_IMAGE(r + sensingRowStart, c) + temp_raw_data;
						HAL_WRITE_LOCAL_BASELINE_IMAGE(r + sensingRowStart, c, temp_data);
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
				
				if(g_temp_sum > 1000)
				{
					local_base_return_flag = YES;
				}

			}
			break;
			
			case PARTIAL_PEN_DATA1:
			case PARTIAL_PEN_DATA2:
			case PARTIAL_PEN_DATA3:
			case PARTIAL_PEN_DATA4:
			case PARTIAL_PEN_DATA5:
			{
				int prev_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(0,0);
				int temp_raw_data;

				for( r = 0; r < (ulRowEnd); r++)
				{
					for( c = 0; c < thisInfo->ucCol; c++)
					{
						temp_raw_data = HAL_READ_LOCAL_DATA_RAW_IMAGE(r, c);
						temp_data = HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r+sensingRowStart,c)+ temp_raw_data;
						HAL_WRITE_LOCAL_DATA_BASELINE_IMAGE(r + sensingRowStart, c, temp_data);
					}
				}
			}
			break;

			case PARTIAL_FINGER5:
			{
				for (r = 0; r < ROW_MAX; r++)
				{
					for (c = 0; c < COL_MAX; c++)
					{
						temp_data = HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c) + HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c);
						HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, temp_data);
					}
				}
			}
			break;

			default:
			break;
		}		

		if(lDataIndex == PARTIAL_PEN_DATA5)
		{
			sensingRowStart += 8;

			if(sensingRowStart == 48)
			{
				sensingRowStart = 0;
				break;
			}
			else if(sensingRowStart == 40)
			{
//				re = 5;
				ulRowEnd = 8;
			}
		}

	}

	for(r = thisInfo->ucScreenRow; r--; )
	{
		for(c=thisInfo->ucScreenCol; c--; )
		{
			temp_data = HAL_READ_LOCAL_BASELINE_IMAGE(r, c);
			temp_data /= 4;
			HAL_WRITE_LOCAL_BASELINE_IMAGE(r, c, temp_data);

			temp_data = HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c);
			temp_data /= 5;
			HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, temp_data);
		}
	}

	for(r = (ulRowEnd*2); r--; )
	{
		for(c=thisInfo->ucScreenCol; c--; )
		{
			// TODO : SAPS에 맞게 변경
			temp_data = HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r, c);
			temp_data /= (5*5);
			HAL_WRITE_LOCAL_DATA_BASELINE_IMAGE(r, c, temp_data);
		}
	}
	
	return local_base_return_flag;
}

#else
void algorithm_local_baseline_tracking_initial(void)
{
	int i,j;
	int r, c, rs = 0;
	uint16_t temp_data;	
	ePartialSensing_t lDataIndex = PARTIAL_PEN_BEACON;	

	sensingRowStart = 0;

	module_wait_Vsync_signal(LOCAL_MODE, thisModeConf->BaseLine.ucDiscardFrameNum);

	while(YES)
	{       
		lDataIndex = module_wait_local_sample_done();
		
		switch(lDataIndex)
		{
			case PARTIAL_PEN_DATA1:
			case PARTIAL_PEN_DATA2:
			case PARTIAL_PEN_DATA3:
			case PARTIAL_PEN_DATA4:
			case PARTIAL_PEN_DATA5:
			case LOCAL_PEN_DATA6:
			case LOCAL_PEN_DATA7:
			{		
				for(r=0; r<8; r++)
				{
					for( c = 0; c < thisInfo->ucCol; c++)
					{
						temp_data = HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r,c) + HAL_READ_LOCAL_DATA_RAW_IMAGE(r,c); 
						HAL_WRITE_LOCAL_DATA_BASELINE_IMAGE(r+sensingRowStart, c, temp_data);
					}
				}
			}
			break;

			case PARTIAL_FINGER4:
			{					
				for (r = 0; r < ROW_MAX; r++)
				{
					for (c = 0; c < COL_MAX; c++)
					{		  
						temp_data = HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r,c) + HAL_READ_LOCAL_FINGER_RAW_IMAGE(r,c); 
						HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, temp_data);
					}
				}
			}
			break;

			default:
			break;
		}		
		
		if(lDataIndex == LOCAL_PEN_DATA7) sensingRowStart += 8;

		if(sensingRowStart == 40)
		{
			sensingRowStart = 0;
			break;
		}
	}

	for( r=thisInfo->ucScreenRow; r--; )
	{
		for( c=thisInfo->ucScreenCol; c--; )
		{
			temp_data = HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r,c);
			temp_data /= 7;
			HAL_WRITE_LOCAL_DATA_BASELINE_IMAGE(r, c, temp_data);

			temp_data = HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r,c);
			temp_data /= 4;
			HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, temp_data);
		}
	}

	protocol_LogMatrix(LT_REFERENCE, thisInfo->ucScreenCol, HAL_GET_LOCAL_DATA_BASELINE_IMAGE_PTR(), COL_MAX, thisInfo->ucScreenRow, 82/*MAX Intensity*/);
}
#endif

void algorithm_data_local_process(ePartialSensing_t RetVal)
{
	algorithm_local_data_baseline_calculate_delta(RetVal);		
}

void alogorithm_coord_modify_pos_local(tXY_t* pos)
{
	int x, y;
//	int ucXCompensationGain = 10;//24;// NOTE : warning제거

	if( ptMemConf->bSwapXY )
	{
		x = pos->y;
		y = pos->x;
	}
	else
	{
		x = pos->x;
		y = pos->y;
	}

	if( ptMemConf->bFlipX )
		x = thisInfo->tCoord.iInternalXRes - x;

	/*
	 * Expand edge position.
	 *  - 내부 좌표로 먼저 expand합니다.
	 *  - 기존에 full sized edge 사용 시 외부좌표로 변환 후 3/2 point에서 expand했는데,
	 *  - 이제는 내부좌표 상태에서 expand하므로 offset인 1/2를 제외하고 unit distance부터 expand하도록 합니다.
	 */
	if(1)
	{
		if (!thisInfo->bDoNotExpandPos)
		{
			if (x < thisInfo->tCoord.iXExpandStart)
				x = thisInfo->tCoord.iXExpandStart + (((x - thisInfo->tCoord.iXExpandStart) * (int32_t)thisCommonConf->ucLeftEdgeExpand_local) >> 6);
			else if (thisInfo->tCoord.iInternalXRes - x < thisInfo->tCoord.iXExpandStart)
				x = thisInfo->tCoord.iInternalXRes - (thisInfo->tCoord.iXExpandStart
									 + (((thisInfo->tCoord.iInternalXRes - x - thisInfo->tCoord.iXExpandStart) * (int32_t)thisCommonConf->ucRightEdgeExpand_local) >> 6));

			if (y < (thisInfo->tCoord.iYExpandStart))
				y = (thisInfo->tCoord.iYExpandStart) + (((y - (thisInfo->tCoord.iYExpandStart)) * (int32_t)thisCommonConf->ucTopEdgeExpand_local) >> 6);
			else if (thisInfo->tCoord.iInternalYRes - y < thisInfo->tCoord.iYExpandStart)
				y = thisInfo->tCoord.iInternalYRes - (thisInfo->tCoord.iYExpandStart
									 + (((thisInfo->tCoord.iInternalYRes - y - thisInfo->tCoord.iYExpandStart) * (int32_t)thisCommonConf->ucBottomEdgeExpand_local) >> 6));
		}
	}

	/*
	 * Modify resolution domain.
	 */
	x = ( (x + thisInfo->tCoord.iXOffset ) * thisCommonConf->iXResolution ) / (thisInfo->tCoord.iInternalXRes + 2*thisInfo->tCoord.iXOffset);
	x -= 96;//12;
	y = ( (y + thisInfo->tCoord.iYOffset ) * thisCommonConf->iYResolution ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);

	/*
	 * Coordinate Compensation
	 */
//	if( 1)
//	{
//		if(x < 114)
//					 x = x - (((x-0)*ucXCompensationGain)/114);
//		else if(x < 2048)
//					 x = x + (((x-114)*ucXCompensationGain)/1934 - ucXCompensationGain);
//		else if(x < 3982)
//					 x = x + (((x-2048)*ucXCompensationGain)/1934);
//		else
//					 x = x - (((x-3982)*ucXCompensationGain)/114 - ucXCompensationGain);
//	}
	
	/*
	 * Clipping.
	 */
	if (x < (int)thisCommonConf->ucXClipping)
		x = (int)(thisCommonConf->ucXClipping);
	else if (x > ((int)((/*thisCommonConf->iXResolution*/32768 - 1) - thisCommonConf->ucXClipping)))
		x = (/*thisCommonConf->iXResolution*/32768 - 1) - thisCommonConf->ucXClipping;

	if (y < (int)(thisCommonConf->ucYClipping))
		y = (int)thisCommonConf->ucYClipping;
	else if (y > (int)((thisCommonConf->iYResolution - 1) - thisCommonConf->ucYClipping))
		y = (int)((thisCommonConf->iYResolution - 1) - thisCommonConf->ucYClipping);
	
	pos->x = x;
	pos->y = y;
}



extern void protocol_hid_PushPenEvent(const uSWIPTouchItem_t* _kptItem); // NOTE : 헤더파일에 위치 잡고 없애자!!
extern uint8_t	g_ConnectedDevice;
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
		alogorithm_coord_modify_pos_local(&old_pos);

		if (thisInfo->tCoord_local.tPos.vusS[i] > 0)
		{
			pos = thisInfo->tCoord_local.tPos.tXY[i];

			alogorithm_coord_modify_pos_local(&pos);

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
	thisInfo->bWasPalm = thisInfo->bIsPalm;


	protocol_swip_SendPenEvent();
	//    protocol_hid_SendPenEvent();

#ifdef ADD_PEN
	SendPenData();
#endif

}

void algorithm_local_coord_UpdatePosHistoryInfo(void)
{
	int i;

	tCoordInfo_t 	*temp_coord;

	temp_coord = &thisInfo->tCoord_local;
	
	for( i=0; i<(COORD_HISTORY_NUM - 1); i++ )
	{
		temp_coord->tOrgPosHist[(COORD_HISTORY_NUM - 1) - i] = temp_coord->tOrgPosHist[(COORD_HISTORY_NUM - 1) - i - 1];
	}

	for( i=0; i<(PAST_COORD_HISTORY_NUM - 1); i++ )
		tPastPosHist[(PAST_COORD_HISTORY_NUM - 1) - i] = tPastPosHist[(PAST_COORD_HISTORY_NUM - 1) - i - 1];
		
	tPastPosHist[0] = temp_coord->tPastPos[2].tXY[0];
	
	temp_coord->tPastPos[2].sFinger_ 	    = temp_coord->tPastPos[1].sFinger_;
	temp_coord->tPastPos[1].sFinger_ 	    = temp_coord->tPastPos[0].sFinger_;
	temp_coord->tPastPos[0].sFinger_ 	    = temp_coord->tPos.sFinger_;

	temp_coord->tOrgPastPos[2].sFinger_ 	= temp_coord->tOrgPastPos[1].sFinger_;
	temp_coord->tOrgPastPos[1].sFinger_ 	= temp_coord->tOrgPastPos[0].sFinger_;
	temp_coord->tOrgPastPos[0].sFinger_ 	= temp_coord->tOrgPos.sFinger_;

	for( i=ptMemConf->iMaxTouch_; i--; )
	{
		temp_coord->tPastPos[2].tXY[i]         = temp_coord->tPastPos[1].tXY[i];
		temp_coord->tPastPos[2].vusR[i]        = temp_coord->tPastPos[1].vusR[i];
		temp_coord->tPastPos[2].vusS[i]        = temp_coord->tPastPos[1].vusS[i];
		
		temp_coord->tPastPos[1].tXY[i]         = temp_coord->tPastPos[0].tXY[i];
		temp_coord->tPastPos[1].vusR[i]        = temp_coord->tPastPos[0].vusR[i];
		temp_coord->tPastPos[1].vusS[i]        = temp_coord->tPastPos[0].vusS[i];

		if(temp_coord->ucPostProcessRun[i] == 1)
		{
			temp_coord->tPastPos[0].tXY[i] 	    = temp_coord->tFirstPos.tXY[i];
			temp_coord->tPastPos[0].vusR[i] 	    = temp_coord->tPos.vusR[i];
			temp_coord->tPastPos[0].vusS[i] 	    = temp_coord->tPos.vusS[i];
		}
		else
		{
			temp_coord->tPastPos[0].tXY[i] 	    = temp_coord->tPos.tXY[i];
			temp_coord->tPastPos[0].vusR[i] 	    = temp_coord->tPos.vusR[i];
			temp_coord->tPastPos[0].vusS[i] 	    = temp_coord->tPos.vusS[i];
		}
		
		temp_coord->tOrgPastPos[2].tXY[i]      = temp_coord->tOrgPastPos[1].tXY[i];
		temp_coord->tOrgPastPos[2].vusR[i]     = temp_coord->tOrgPastPos[1].vusR[i];
		temp_coord->tOrgPastPos[2].vusS[i]     = temp_coord->tOrgPastPos[1].vusS[i];

		temp_coord->tOrgPastPos[1].tXY[i]      = temp_coord->tOrgPastPos[0].tXY[i];
		temp_coord->tOrgPastPos[1].vusR[i]     = temp_coord->tOrgPastPos[0].vusR[i];
		temp_coord->tOrgPastPos[1].vusS[i]     = temp_coord->tOrgPastPos[0].vusS[i];

		temp_coord->tOrgPastPos[0].tXY[i] 	    = temp_coord->tOrgPos.tXY[i];
		temp_coord->tOrgPastPos[0].vusR[i] 	= temp_coord->tOrgPos.vusR[i];
		temp_coord->tOrgPastPos[0].vusS[i] 	= temp_coord->tOrgPos.vusS[i];
	}
}

extern __IO int check_cnt;
extern uint8_t sensing_cont_cnt;
void algorithm_hover_full_search(void)
{
	if(check_cnt == check_frm)
	{
		memset(HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), 0, HAL_GET_LOCAL_SEARCH_IMAGE_SIZE());
		check_cnt = 0;
	}
	
	algorithm_local_process(LOCAL_SEARCH_MODE);

	if(gDCFullMode == 1)
	{
		if(sensingRowStart == MUX_MAX_ROW)
		{
			sensingRowStart = 0;
		}
		else
		{
			sensingRowStart += 8;
			if(sensingRowStart > MUX_MAX_ROW)
				sensingRowStart = MUX_MAX_ROW;
		}

//		switch(sensingRowStart)
//		{
//			case 32:
//				sensingRowStart =  MUX_MAX_ROW;
//			break;
//
//			case MUX_MAX_ROW:
//				sensingRowStart = 0;
//				check_cnt++;
//			break;
//
//			default:
//				sensingRowStart += 8;
//			break;
//		}
	}

	thisInfo->tPenInfo.ucHover_cnt = 0;
}

extern bool_t bChangeSampling;
bool_t algorithm_mode_change_check(void)
{
	if(thisInfo->bLocal_sensing == NO)
	{
#ifdef DC_BASE
		if(gDCFullMode == 0)
#endif
		{
			if(sensing_cont_cnt < SEN_CONT_CNT)
				sensing_cont_cnt++;
			else 
			{
				thisInfo->tPenInfo.ucHover_cnt = 0;
				sensing_cont_cnt  = 0;
				
#ifdef DC_BASE
				if(gDCFullMode != 2)		// local finger와 충동 방지
					gDCFullMode = 1;
				
				check_cnt = 8;
				sensingRowStart = 0;
#else
				return YES;
#endif
			}
		}
	}
	else
		sensing_cont_cnt = 0;
	
	return NO;
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
		end_r1 = 8;
		start_r2 = 0;
		end_r2 = start_r1;
		p_current_row = 8 - start_r1;
		
		for(r=end_r1-1; r>=start_r1; r--)
		{
			p_current_row--;
			for(c=0; c<PEN_COORD_COL_MAX; c++)
			{
				HAL_WRITE_LOCAL_DELTA_IMAGE(r,c,HAL_READ_LOCAL_DELTA_IMAGE(p_current_row,c));
			}
		}
	}
	else
	{
		start_r1 = 0;
		end_r1 = 8 - (currentRowStart - p_currentRowStart);
		start_r2 = end_r1;
		end_r2 = 8;
		p_current_row = currentRowStart - p_currentRowStart;
		
		for(r=start_r1; r<end_r1; r++)
		{
			for(c=0; c<PEN_COORD_COL_MAX; c++)
			{
				HAL_WRITE_LOCAL_DELTA_IMAGE(r,c,HAL_READ_LOCAL_DELTA_IMAGE(p_current_row,c));
			}
			p_current_row++;
		}
	}
	
	for(r=start_r2; r<end_r2; r++)
	{
		for(c=0; c<PEN_COORD_COL_MAX; c++)
		{
			HAL_WRITE_LOCAL_DELTA_IMAGE(r,c,0);
		}
	}
}

void algorithm_hover_accum_process(void)
{
	algorithm_coord_initialise_local_pos_buffer();
	
	{
		int r, c;
		int delta;
		int start_r, end_r;
		int start_c, end_c;
		int local_rs;
		uint16_t read_raw_data;

		local_rs = currentRowStart;

		start_r = 0, start_c = 0;
		end_r = 8, end_c = thisInfo->ucScreenCol;
		
		if(local_rs == MUX_MAX_ROW)
			end_r = 7;

		for( r=start_r; r<end_r; r++ )
		{
			for( c=start_c; c<end_c; c++ )
			{

				read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r,c);
				delta = (signed)HAL_READ_LOCAL_BASELINE_IMAGE(r+local_rs,c) - (signed)read_raw_data;		// pen use
	//			delta = (signed)read_raw_data - (signed)HAL_READ_BASELINE_IMAGE(r+local_rs,c);		// finger use

				
//				delta >>= (1);
//				delta *= 2;
				delta = 0;
				
				HAL_WRITE_LOCAL_DELTA_IMAGE(r, c, delta);
				
				if(thisInfo->tDelta_local.iMaxStrength < delta)
					thisInfo->tDelta_local.iMaxStrength = delta;
			}
		}
		
		thisInfo->tDelta_local.sPrevMaxDelta2 = thisInfo->tDelta_local.iMaxStrength;
	}
}

void algorithm_hover_local_process()
{
	if(thisInfo->tPenInfo.ucHover_cnt == 0)
	{
		algorithm_hover_accum_process();
		thisInfo->tPenInfo.ucHover_cnt = 1;
	}
//	else
	{
		if(p_currentRowStart != currentRowStart)
			algorithm_hover_accum_move();

		algorithm_local_process(LOCAL_HOVER_MODE);
	}
}

void algorithm_local_process(int mode)
{
	algorithm_coord_initialise_local_pos_buffer();

//	alogorithm_local_linefilter();
//	protocol_LogMatrix(LT_RAWDATA, PEN_COORD_COL_MAX, HAL_GET_LOCAL_RAW_IMAGE_PTR(), PEN_COORD_COL_MAX, 8, 84/*MAX Intensity*/);
//	protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_LOCAL_DATA_RAW_IMAGE_PTR(), COL_MAX, 16, 81/*MAX Intensity*/);
//	protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_LOCAL_DATA_BASELINE_IMAGE_PTR(), COL_MAX, 23, 81/*MAX Intensity*/);

  	algorithm_local_baseline_calculate_delta(mode);
	
	if(mode == LOCAL_SEARCH_MODE)// && currentRowStart == MUX_MAX_ROW)
	{
//		if(currentRowStart == MUX_MAX_ROW)
//			protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_LOCAL_SEARCH_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);
		return;
	}

//	algorithm_local_baseline_calculate_delta_DSP(LOCAL_MODE);	

//	protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_LOCAL_DELTA_IMAGE_PTR(), COL_MAX, 8, 81/*MAX Intensity*/);
	
	algorithm_label_process(mode);

	algorithm_coord_process(mode);
	
	algorithm_PendPenEvent();
		
	algorithm_local_coord_UpdatePosHistoryInfo();	
}
#endif
