/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  algorithm_coord.c
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
#include "DSP_B.h" // NOTE : algorithm_coord_init_local 함수를 참조하고 있음

int PanningTestModeCnt = 0;
#define PANNING_TEST_MODE_CNT_MAX 100

static const tAlgorithmCommonConf_t * thisCommonConf = NULL;
static const tAlgorithmModeConf_t * thisModeConf = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;
#if USED_NOISE_HOPPING_FREQ
static tAppInfo_t * ptAppInfo = NULL;
#endif /* USED_NOISE_HOPPING_FREQ */
//static const tModuleCommonConf_t * _ptModuleCommonConf = NULL;
//uint8_t DrawingFlag[LOOSE_POSBUF_] = {0};
int16_t AddDistTh = 0;
uint8_t FirstTouchEnable[LOOSE_POSBUF_] = {0};
extern bool_t algorithm_nearby_rect(tRect_t RectA, tRect_t RectB, uint8_t dist_th);
extern tRect_t algorithm_merge_rect(tRect_t RectA, tRect_t RectB);
extern bool_t algorithm_nearby_rect_point(tRect_t RectA, tXY_t PointA, uint8_t dist_th);
extern tRect_t algorithm_merge_rect_point(tRect_t RectA, tXY_t PointA);
extern tRect_t PalmRect[POSBUF_];
extern uint8_t PalmRegionNum, PalmRectEnable[POSBUF_];
extern void algorithm_PendTouchEvent(void);
extern int RealDiffIIR;
extern uint8_t DoReportOrgPos;
uint8_t fixed_touchnum = 0;
//int dbg_coord[30] = {0};
//int panning_cnt = 0;
tXY_t tPastPosHist[PAST_COORD_HISTORY_NUM] = {0,};
#if (VECTOR_PREDICTION_EN == YES)
uint8_t ProjectionEnable[LOOSE_POSBUF_] = {0};
#endif

#if (USED_DRUM_ALGO == YES)
uint8_t DrumStep[LOOSE_POSBUF_] = {0};
#endif /*USED_DRUM_ALGO*/

#if USED_SPLIT_MERGE_RELIABILITY
int8_t  SeparationReliability[LOOSE_POSBUF_] = {0};
#endif /*USED_SPLIT_MERGE_RELIABILITY*/

void algorithm_coord_init(void)
{
	int l;

	thisCommonConf = algorithm_GetCommonConfig();
	thisModeConf   = algorithm_GetModeConfig();
	thisInfo       = algorithm_GetInfo();
#if USED_NOISE_HOPPING_FREQ
	ptAppInfo      = app_GetInfo();
#endif /* USED_NOISE_HOPPING_FREQ */
//	_ptModuleCommonConf = module_GetCommonConfig();

	thisInfo->tCoord.tPastPos[0].sFinger_    = 0;
	thisInfo->tCoord.tOrgPastPos[0].sFinger_ = 0;

	for(l=MAX_TOUCH_; l--; )
	{
		thisInfo->tCoord.tPastPos[0].tXY[l].x    = 0;
		thisInfo->tCoord.tPastPos[0].tXY[l].y    = 0;
		thisInfo->tCoord.tPastPos[0].vusR[l]     = 0;
		thisInfo->tCoord.tPastPos[0].vusS[l]     = 0;

		thisInfo->tCoord.tPastPos[1].tXY[l].x    = 0;
		thisInfo->tCoord.tPastPos[1].tXY[l].y    = 0;
		thisInfo->tCoord.tPastPos[1].vusR[l]     = 0;
		thisInfo->tCoord.tPastPos[1].vusS[l]     = 0;
		
		thisInfo->tCoord.tPastPos[2].tXY[l].x    = 0;
		thisInfo->tCoord.tPastPos[2].tXY[l].y    = 0;
		thisInfo->tCoord.tPastPos[2].vusR[l]     = 0;
		thisInfo->tCoord.tPastPos[2].vusS[l]     = 0;

		thisInfo->tCoord.tPastPos[3].tXY[l].x    = 0;
		thisInfo->tCoord.tPastPos[3].tXY[l].y    = 0;
		thisInfo->tCoord.tPastPos[3].vusR[l]     = 0;
		thisInfo->tCoord.tPastPos[3].vusS[l]     = 0;
		
		thisInfo->tCoord.tPastPos[4].tXY[l].x    = 0;
		thisInfo->tCoord.tPastPos[4].tXY[l].y    = 0;
		thisInfo->tCoord.tPastPos[4].vusR[l]     = 0;
		thisInfo->tCoord.tPastPos[4].vusS[l]     = 0;
		
		thisInfo->tCoord.tOrgPastPos[0].tXY[l].x = 0;
		thisInfo->tCoord.tOrgPastPos[0].tXY[l].y = 0;
		thisInfo->tCoord.tOrgPastPos[0].vusR[l]  = 0;
		thisInfo->tCoord.tOrgPastPos[0].vusS[l]  = 0;

		thisInfo->tCoord.tOrgPastPos[1].tXY[l].x = 0;
		thisInfo->tCoord.tOrgPastPos[1].tXY[l].y = 0;
		thisInfo->tCoord.tOrgPastPos[1].vusR[l]  = 0;
		thisInfo->tCoord.tOrgPastPos[1].vusS[l]  = 0;
		
		thisInfo->tCoord.tOrgPastPos[2].tXY[l].x = 0;
		thisInfo->tCoord.tOrgPastPos[2].tXY[l].y = 0;
		thisInfo->tCoord.tOrgPastPos[2].vusR[l]  = 0;
		thisInfo->tCoord.tOrgPastPos[2].vusS[l]  = 0;

		thisInfo->tCoord.tOrgPastPos[3].tXY[l].x = 0;
		thisInfo->tCoord.tOrgPastPos[3].tXY[l].y = 0;
		thisInfo->tCoord.tOrgPastPos[3].vusR[l]  = 0;
		thisInfo->tCoord.tOrgPastPos[3].vusS[l]  = 0;
		
		thisInfo->tCoord.tOrgPastPos[4].tXY[l].x = 0;
		thisInfo->tCoord.tOrgPastPos[4].tXY[l].y = 0;
		thisInfo->tCoord.tOrgPastPos[4].vusR[l]  = 0;
		thisInfo->tCoord.tOrgPastPos[4].vusS[l]  = 0;
		
		thisInfo->tCoord.ucIdMappedCnt[l] = 0;
		thisInfo->tCoord.cScreenDebCnt[l] = 0;
		
		thisInfo->tCoord.cIsbefor[l] = 0;
	}

    thisInfo->tCoord.iXOffset = ( UNIT_DIST * (2*thisCommonConf->iXEdgeNum - thisCommonConf->iXEdgeDen) ) / (2*thisCommonConf->iXEdgeDen);
    thisInfo->tCoord.iYOffset = ( UNIT_DIST * (2*thisCommonConf->iYEdgeNum - thisCommonConf->iYEdgeDen) ) / (2*thisCommonConf->iYEdgeDen);
	
#if USED_WINDOW_10_QE_BOE
    thisInfo->tCoord.iXExpandStart = 1200;
#if USED_ONLY_BOE_TEST_EQU
    /*
     * TODO : 중대형에서 UNIT_DIST사용에 대한 문제점 수정해야함.
     * UNIT DIST가 맞지 않음 (1<<8) 256은 내부 Scale이 한 블럭당 256으로 할 경우 이지만
     * 중대형의 경우 고정된 32768의 내부 Resolution을 사용 하고 있기 때문에 UNIT_DIST를 고정해서 사용하는 Concept은 맞지 않다.
     */

    /*
     * BOE의 경우 Y노드 개수가 40개 이기 때문에 한 Unit Dist는 819가 된다. Expand Start지점을 1400으로 한건 대략 (1Unit+2/3Unit)을 확장 시키기 위함이다.
     */
    thisInfo->tCoord.iYExpandStart = 1400;//1*UNIT_DIST;
#else /* USED_ONLY_BOE_TEST_EQU */
    thisInfo->tCoord.iYExpandStart = 1*UNIT_DIST;
#endif /* USED_ONLY_BOE_TEST_EQU */
#else /* USED_WINDOW_10_QE_BOE */
    thisInfo->tCoord.iXExpandStart = 1*UNIT_DIST;//(1<<(POS_BOOST_SHIFT_-3));		//1*UNIT_DIST;
#if USED_ONLY_BOE_TEST_EQU
    /*
     * TODO : 중대형에서 UNIT_DIST사용에 대한 문제점 수정해야함.
     * UNIT DIST가 맞지 않음 (1<<8) 256은 내부 Scale이 한 블럭당 256으로 할 경우 이지만
     * 중대형의 경우 고정된 32768의 내부 Resolution을 사용 하고 있기 때문에 UNIT_DIST를 고정해서 사용하는 Concept은 맞지 않다.
     */

    /*
     * BOE의 경우 Y노드 개수가 40개 이기 때문에 한 Unit Dist는 819가 된다. Expand Start지점을 1400으로 한건 대략 (1Unit+2/3Unit)을 확장 시키기 위함이다.
     */
    thisInfo->tCoord.iYExpandStart = 1400;//1*UNIT_DIST;
#else /* USED_ONLY_BOE_TEST_EQU */
    thisInfo->tCoord.iYExpandStart = 1*UNIT_DIST; //(1<<(POS_BOOST_SHIFT_));
#endif /* USED_ONLY_BOE_TEST_EQU */
#endif /* USED_WINDOW_10_QE_BOE */

    thisInfo->tCoord.iXEdgeStart = 1*UNIT_DIST;
	thisInfo->tCoord.iYEdgeStart = 1*UNIT_DIST;

    if( thisModeConf->Coord.bSwapXY )
	{
    	thisInfo->tCoord.iInternalXRes = (ROW_MAX - 1) << POS_BOOST_SHIFT_;
    	thisInfo->tCoord.iInternalYRes = (COL_MAX - 1) << POS_BOOST_SHIFT_;
	}
	else
	{
		thisInfo->tCoord.iInternalXRes = (COL_MAX - 1) << POS_BOOST_SHIFT_;
		thisInfo->tCoord.iInternalYRes = (ROW_MAX - 1) << POS_BOOST_SHIFT_;
	}

	thisInfo->tCoord.slScaledMoveDistThd = (thisModeConf->CoordTracking.usMoveDistanceThd << POS_BOOST_SHIFT_);

}

void algorithm_coord_init_param(void)
{
	thisModeConf   = algorithm_GetModeConfig();
//	thisInfo->tCoord.slScaledMoveDistThd = (thisModeConf->CoordTracking.usMoveDistanceThd << POS_BOOST_SHIFT_);
}

void algorithm_coord_initialise_pos_buffer(void)
{
	int l;
	tCoordInfo_t *temp_coord;
	
//	memset((void *)&(thisInfo->tCoord.tOrgPosHist[0]), 0x00, sizeof(tPastPos_t) );

	temp_coord = &thisInfo->tCoord;		
	thisInfo->tDelta.iMaxStrength = 0;

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
		if(temp_coord->tPos.vusR[l] == 0)
		{
			temp_coord->ucEdgeExpandCoef[l] = 0;
#if (REMOVE_EDGE_EN == YES)
			temp_coord->bRemoveEdge[l] = 0;
#endif
		}
		
		temp_coord->tPos.tXY[l].x = 0;
		temp_coord->tPos.tXY[l].y = 0;
		temp_coord->tPos.rect[l].cs = 0;
		temp_coord->tPos.rect[l].ce = 0;
		temp_coord->tPos.rect[l].rs = 0;
		temp_coord->tPos.rect[l].re = 0;
		temp_coord->tPos.vusR[l] = 0;
		temp_coord->tPos.vusS[l] = 0;
		temp_coord->tPos.MaxDelta[l] = (uint16_t)INT16_MIN; // NOTE : warning제거 초기값을 -로 설정해야 하는 이유가 있나????

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

uint16_t WrongSeparationCnt = 0;
uint8_t TouchNumHisto[POSBUF_] = {0};
uint8_t FixTouchNum = 0;
uint8_t PrevMaxTouchNum = 0;
uint8_t gReleaseCnt[POSBUF_] = {0,}; //for win cert4
void algorithm_coord_calc_pos(int mode)
{
	int l,i,cl,pl,match_cl,match_pl;
	int r,c,_d;
	uint32_t ulStrength = 0;
	uint8_t PrevFinger_ = 0;
	int MaxDist = 0, dist = 0, MinDist = 0;
	
	uint8_t MaxTouchNum = 0;

	tLabelInfo_t	*temp_label;
	tCoordInfo_t 	*temp_coord;

	if(mode != FULL_MODE)
	{
		temp_coord = &thisInfo->tCoord_local;
		temp_label = &thisInfo->tLabel_local;
	}
	else
	{
		temp_coord = &thisInfo->tCoord;
		temp_label = &thisInfo->tLabel;
	}

	for(l=temp_label->ucNum;l--;)
	{
		if( temp_label->tTable[l].ulStrength )
		{
			temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_].x  = (temp_label->tTable[l].tCoord.x << POS_BOOST_SHIFT_)/(signed)temp_label->tTable[l].ulExtStrength;
			temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_].y  = (temp_label->tTable[l].tCoord.y << POS_BOOST_SHIFT_)/(signed)temp_label->tTable[l].ulExtStrength;
		
			//MaxDelta Compensation
			{
				int16_t coef_x=0,coef_y=0;
				
				coef_x = (temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_].x%UNIT_DIST);
				coef_y = (temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_].y%UNIT_DIST);
				if(coef_x > (UNIT_DIST>>1) )
					coef_x = UNIT_DIST - coef_x;
				if(coef_y > (UNIT_DIST>>1) )
					coef_y = UNIT_DIST - coef_y;
				
				temp_coord->RealMaxDelta[temp_coord->tTempPos.sFinger_] = (uint16_t)(temp_label->tTable[l].sMaxCellVal 
																			+ (((int)(temp_label->tTable[l].sMaxCellVal) * (coef_x+coef_y) )>>(POS_BOOST_SHIFT_+1)) );
			}
			
			temp_coord->tTempPos.vusR[temp_coord->tTempPos.sFinger_]   = temp_label->tTable[l].usCellNum;
			temp_coord->tTempPos.vusS[temp_coord->tTempPos.sFinger_]   = temp_label->tTable[l].ulStrength;
			temp_coord->tTempPos.rect[temp_coord->tTempPos.sFinger_]   = temp_label->tTable[l].tRect;
			temp_coord->tTempPos.MaxDelta[temp_coord->tTempPos.sFinger_] = temp_label->tTable[l].sMaxCellVal;
#if (PalmCandidateTouchCut_EN == YES)
			temp_coord->tTempPos.MaxPos[temp_coord->tTempPos.sFinger_].c = temp_label->tTable[l].tMaxCell.c;
			temp_coord->tTempPos.MaxPos[temp_coord->tTempPos.sFinger_].r = temp_label->tTable[l].tMaxCell.r;
#endif /* (PalmCandidateTouchCut_EN == YES) */

			temp_coord->cRemap[temp_coord->tTempPos.sFinger_] = temp_coord->tTempPos.sFinger_;

			temp_coord->tTempPos.sFinger_++;
		}
	}
	
#if (PalmDrawingOn_En == YES)
	if(thisModeConf->Palm.ucPalmDrawingOn && thisInfo->bIsPalm){
		int pl;
		int r,c;
		for(pl=0;pl<PalmRegionNum;pl++)
		{
			if(PalmRectEnable[pl])
			{
				int X=0,Y=0,delta = 0, MaxDelta = 0;
				int32_t StrengthSum = 0;
				for(r=PalmRect[pl].rs;r<=PalmRect[pl].re;r++)
				for(c=PalmRect[pl].cs;c<=PalmRect[pl].ce;c++)
				{
					delta = (HAL_READ_DELTA_IMAGE(r,c)>>3);
					if(delta > 1)
					{
						X += delta * c;
						Y += delta * r;
						StrengthSum += delta;
						if(MaxDelta < delta)	MaxDelta = delta;
					}
				}
				X = (X << POS_BOOST_SHIFT_)/StrengthSum;
				Y = (Y << POS_BOOST_SHIFT_)/StrengthSum;
		
				temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_].x = X;//((X + (((PalmRect[pl].cs + PalmRect[pl].ce)<<POS_BOOST_SHIFT_)>>1))>>1);
				temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_].y = Y;//((Y + (((PalmRect[pl].rs + PalmRect[pl].re)<<POS_BOOST_SHIFT_)>>1))>>1);
				
				temp_coord->tTempPos.vusR[temp_coord->tTempPos.sFinger_]   = thisInfo->tDelta.iPosCnt;
				temp_coord->tTempPos.vusS[temp_coord->tTempPos.sFinger_]   = StrengthSum;//thisInfo->tDelta.iPosSum;
				temp_coord->tTempPos.rect[temp_coord->tTempPos.sFinger_]   = PalmRect[pl];
				temp_coord->tTempPos.MaxDelta[temp_coord->tTempPos.sFinger_] = MaxDelta;//thisInfo->tDelta.iMaxStrength;
				


				temp_coord->cRemap[temp_coord->tTempPos.sFinger_] = temp_coord->tTempPos.sFinger_;
				
				temp_coord->tTempPos.sFinger_++;
			}
		}
		return;
	}
#endif
#if WinCertAssistance_En	
	
	if(thisModeConf->Coord.ucWinCertAssistance == 1)
	{
		if(temp_coord->tTempPos.sFinger_ == 0 || temp_coord->tTempPos.sFinger_ > 5){
			WrongSeparationCnt = 0;
			memset(TouchNumHisto,0,sizeof(TouchNumHisto));
			FixTouchNum = 0;
		}
		else{
			int i,MaxNumCnt = 0;
			//Counting touchnum
			if(FixTouchNum == 0){
				for(i=0;i<POSBUF_;i++)
				{
					if(i == temp_coord->tTempPos.sFinger_-1){
							TouchNumHisto[i]++;
					}
					else if(TouchNumHisto[i]>0)
						TouchNumHisto[i]--;

					if(TouchNumHisto[i] >thisModeConf->Coord.ucTouchCountMax){
						TouchNumHisto[i] = thisModeConf->Coord.ucTouchCountMax;
						FixTouchNum = i+1;
					}
					if(TouchNumHisto[i] > MaxNumCnt)
					{
						MaxNumCnt = TouchNumHisto[i];
						MaxTouchNum = i+1;
					}
				}
			}
			else{
				MaxTouchNum = FixTouchNum;
			}
		}
		
		if(temp_coord->tTempPos.sFinger_ > 1)
		{
			int cl,pl;
			uint8_t connected = 0;
			MinDist = (thisModeConf->CoordTracking.usCenterMatchDistanceThd<<POS_BOOST_SHIFT_);
			for(cl=0;cl<temp_coord->tTempPos.sFinger_;cl++){
				connected = NO;
				for(pl=0;pl<temp_coord->tTempPos.sFinger_;pl++){
					if(cl == pl)	continue;
					if(MinDist > algorithm_coord_calc_distance(temp_coord->tTempPos.tXY[cl],temp_coord->tTempPos.tXY[pl])){
						connected = YES;
						break;
					}
				}
				if(connected == NO)
				{
					WrongSeparationCnt = 0;
					memset(TouchNumHisto,0,sizeof(TouchNumHisto));
					FixTouchNum = 0;
					break;
				}
			}
		}
		
		if(FixTouchNum && temp_coord->tTempPos.sFinger_ > 0 && FixTouchNum != temp_coord->tTempPos.sFinger_)
		{
			tXY_t Vector;
//			uint8_t VectorCnt = 0;
			
			if(WrongSeparationCnt++ < thisModeConf->Coord.ucMaxExtendFrameNum)
			{
				//search vector
				Vector.x = 0, Vector.y = 0;
				match_cl = -1, match_pl = -1;
				MinDist = (7<<POS_BOOST_SHIFT_);
				for(cl=0;cl<temp_coord->tTempPos.sFinger_;cl++){
					if(temp_coord->tTempPos.vusR[cl]!=0){
		//				if(algorithm_nearby_rect_point(BigLabelRect[i], temp_coord->tTempPos.tXY[cl], 3))	//Margin 3
						{
	//						MinDist = (10<<POS_BOOST_SHIFT_);
	//						match_pl = -1;
							for(pl=0;pl<MAX_TOUCH_;pl++){
								if(temp_coord->tOrgPastPos[0].vusR[pl]!=0){
									
									tXY_t Pred;
									if(temp_coord->tPastPos[2].vusR[pl]>0){
			//							Pred.x = (temp_coord->tPastPos[0].tXY[pl].x<<1) - temp_coord->tPastPos[2].tXY[pl].x;
			//							Pred.y = (temp_coord->tPastPos[0].tXY[pl].y<<1) - temp_coord->tPastPos[2].tXY[pl].y;
										Pred.x = temp_coord->tOrgPastPos[0].tXY[pl].x + (temp_coord->tPastPos[0].tXY[pl].x - temp_coord->tPastPos[2].tXY[pl].x);
										Pred.y = temp_coord->tOrgPastPos[0].tXY[pl].y + (temp_coord->tPastPos[0].tXY[pl].y - temp_coord->tPastPos[2].tXY[pl].y);
									}
									else{
										Pred = temp_coord->tOrgPastPos[0].tXY[pl];
									}
									dist = algorithm_coord_calc_distance(Pred,temp_coord->tTempPos.tXY[cl]);
									if(dist < MinDist)
									{
										MinDist = dist;
										match_pl = pl;
										match_cl = cl;
									}
								}
							}
						}
					}
				}
				if(match_pl != -1 && match_cl != -1)
				{
//					Vector.x += temp_coord->tTempPos.tXY[match_cl].x - temp_coord->tOrgPastPos[0].tXY[match_pl].x;
//					Vector.y += temp_coord->tTempPos.tXY[match_cl].y - temp_coord->tOrgPastPos[0].tXY[match_pl].y;
					
					Vector.x = 0, Vector.y = 0;
					if(temp_coord->tPastPos[0].vusR[match_pl]>0 && temp_coord->tPastPos[2].vusR[match_pl]>0){
						Vector.x = ((temp_coord->tPastPos[0].tXY[match_pl].x - temp_coord->tPastPos[2].tXY[match_pl].x)>>1);
						Vector.y = ((temp_coord->tPastPos[0].tXY[match_pl].y - temp_coord->tPastPos[2].tXY[match_pl].y)>>1);
					}
					
					for(i=0;i<POSBUF_;i++){
						temp_coord->tTempPos.vusR[i]   = 0;
						temp_coord->tTempPos.vusS[i]   = 0;
					}
					temp_coord->tTempPos.sFinger_ = 0;
					for(pl=0;pl<MAX_TOUCH_;pl++){
						if(temp_coord->tOrgPastPos[0].vusR[pl]!=0 ){	//&& temp_coord->DrawingFlag[pl] == YES){
							
							temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].tXY[pl];
							temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_].x += Vector.x;
							temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_].y += Vector.y;

							temp_coord->tTempPos.vusR[temp_coord->tTempPos.sFinger_]   = temp_coord->tOrgPastPos[0].vusR[pl];
							temp_coord->tTempPos.vusS[temp_coord->tTempPos.sFinger_]   = temp_coord->tOrgPastPos[0].vusS[pl];
			//				temp_coord->tTempPos.rect[temp_coord->tTempPos.sFinger_]   = 
							temp_coord->RealMaxDelta[temp_coord->tTempPos.sFinger_] = 0; 
							temp_coord->cRemap[temp_coord->tTempPos.sFinger_] = temp_coord->tTempPos.sFinger_;
							temp_coord->tTempPos.sFinger_++;
						}
					}
				}
				
			}
			else{
				WrongSeparationCnt = 0;
				memset(TouchNumHisto,0,sizeof(TouchNumHisto));
		//		PrevMaxTouchNum = 0;
				FixTouchNum = 0;
			}
		}
		else{
			WrongSeparationCnt = 0;
		}
		
//		if(temp_coord->tTempPos.sFinger_ > 1)
//		{
//			int cl,pl;
//			for(cl=0;cl<temp_coord->tTempPos.sFinger_;cl++){
//				for(pl=0;pl<temp_coord->tTempPos.sFinger_;pl++){
//					if(cl == pl)	continue;
//					if(abs(temp_coord->tTempPos.tXY[cl].x - temp_coord->tTempPos.tXY[pl].x)+abs(temp_coord->tTempPos.tXY[cl].y - temp_coord->tTempPos.tXY[pl].y) < (3<<POS_BOOST_SHIFT_) ){
//						temp_label->LabelSplitCnt++;
//						break;
//					}
//					
//				}
//			}
//		}

//		if(temp_label->LabelSplitCnt)
//			temp_label->LabelSplitFrmCnt++;
//		else if(temp_label->LabelSplitFrmCnt)
//			temp_label->LabelSplitFrmCnt--;
	}
	else if(thisModeConf->Coord.ucWinCertAssistance == 2)
	{
		if(temp_coord->tTempPos.sFinger_ == 0){
			WrongSeparationCnt = 0;
			memset(TouchNumHisto,0,sizeof(TouchNumHisto));
			PrevMaxTouchNum = 0;
	//		temp_label->LabelNearbyFrmCnt = 0;
		}
		else{
			int i,MaxNumCnt = 0;
			//Counting touchnum
			for(i=0;i<POSBUF_;i++)
			{
				if(i == temp_coord->tTempPos.sFinger_-1)
					TouchNumHisto[i]++;
				else if(TouchNumHisto[i]>0)
					TouchNumHisto[i]--;
				if(TouchNumHisto[i] >thisModeConf->Coord.ucTouchCountMax){
					TouchNumHisto[i] = thisModeConf->Coord.ucTouchCountMax;
				}
				if(TouchNumHisto[i] > MaxNumCnt)
				{
					MaxNumCnt = TouchNumHisto[i];
					MaxTouchNum = i+1;
				}
			}
		}
		
//		temp_label->LabelNearbyCnt = 0;
		if(temp_coord->tTempPos.sFinger_ > 1)
		{
			int cl,pl;
//			uint8_t SplitFlag = 0;
			for(cl=0;cl<temp_coord->tTempPos.sFinger_;cl++){
				for(pl=0;pl<temp_coord->tTempPos.sFinger_;pl++){
					if(cl == pl)	continue;
	//				dist = abs(temp_coord->tTempPos.tXY[cl].x - temp_coord->tTempPos.tXY[pl].x)+abs(temp_coord->tTempPos.tXY[cl].y - temp_coord->tTempPos.tXY[pl].y);
					dist = algorithm_coord_calc_distance(temp_coord->tTempPos.tXY[cl], temp_coord->tTempPos.tXY[pl]);
					if(dist < (4<<POS_BOOST_SHIFT_) ){
//						SplitFlag = YES;
					}
					if(MaxDist < dist)
						MaxDist = dist;
				}
			}
//			if(SplitFlag)	temp_label->LabelNearbyCnt++;
		}
		
		if( temp_coord->tPastPos[0].sFinger_ > 1 && temp_coord->tTempPos.sFinger_ && MaxDist < (6<<POS_BOOST_SHIFT_) && temp_label->LabelSplitFrmCnt)
		{
			if(MaxTouchNum == PrevMaxTouchNum && TouchNumHisto[MaxTouchNum-1] > (thisModeConf->Coord.ucTouchCountMax>>1)){
				if(temp_coord->tPastPos[0].sFinger_ !=  temp_coord->tTempPos.sFinger_)
				{
					tXY_t Vector[2];
					uint16_t cnt[2];
					
					if(temp_label->LabelSplitCnt)
					{
						Vector[1].x = 0, Vector[1].y = 0, cnt[1] = 0;
						for(i=0;i<temp_coord->tPastPos[0].sFinger_;i++){
							if(temp_coord->tPastPos[0].vusR[i]!=0){
								Vector[1].x += temp_coord->tOrgPastPos[0].tXY[i].x;
								Vector[1].y += temp_coord->tOrgPastPos[0].tXY[i].y;
								cnt[1]++;
							}
						}
						if(cnt[1]){
							Vector[1].x /= cnt[1];
							Vector[1].y /= cnt[1];
						}
						
						Vector[0].x = 0, Vector[0].y = 0, cnt[0] = 0;
						for(i=0;i<temp_coord->tTempPos.sFinger_;i++){
							Vector[0].x += temp_coord->tTempPos.tXY[i].x;
							Vector[0].y += temp_coord->tTempPos.tXY[i].y;
							cnt[0]++;
						}
						if(cnt[0]){
							Vector[0].x /= cnt[0];
							Vector[0].y /= cnt[0];
						}
						if(cnt[0] && cnt[1])
						{
							Vector[0].x -= Vector[1].x;
							Vector[0].y -= Vector[1].y;
						}
						else{
							Vector[0].x = 0;
							Vector[0].y = 0;
						}
					}
					else{
						Vector[0].x = 0;
						Vector[0].y = 0;
					}
					
					
					if(WrongSeparationCnt++ < thisModeConf->Coord.ucMaxExtendFrameNum)
					{
						for(i=0;i<POSBUF_;i++){
							temp_coord->tTempPos.vusR[i]   = 0;
							temp_coord->tTempPos.vusS[i]   = 0;
						}
						for(i=0;i<temp_coord->tPastPos[0].sFinger_;i++){
							if(temp_coord->tPastPos[0].vusR[i]!=0){
				//				temp_coord->tTempPos.tXY[i] = temp_coord->tOrgPastPos[0].tXY[i];
	//							temp_coord->tTempPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x;
	//							temp_coord->tTempPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y;
	//							temp_coord->tTempPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + (temp_coord->tTempPos.tXY[0].x - temp_coord->tOrgPastPos[0].tXY[i].x);
	//							temp_coord->tTempPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + (temp_coord->tTempPos.tXY[0].y - temp_coord->tOrgPastPos[0].tXY[i].y);
								temp_coord->tTempPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + Vector[0].x;
								temp_coord->tTempPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + Vector[0].y;

								
				//				temp_coord->tTempPos.tXY[i].x = (temp_coord->tOrgPastPos[0].tXY[i].x<<1) - temp_coord->tOrgPastPos[1].tXY[i].x;
				//				temp_coord->tTempPos.tXY[i].y = (temp_coord->tOrgPastPos[0].tXY[i].y<<1) - temp_coord->tOrgPastPos[1].tXY[i].y;
								
								temp_coord->tTempPos.vusR[i]   = 1;//temp_coord->tPastPos[0].vusR[0];
								temp_coord->tTempPos.vusS[i]   = 1;//temp_coord->tPastPos[0].vusS[0];
								temp_coord->cRemap[i] = i;
							}
						}
						temp_coord->tTempPos.sFinger_ = temp_coord->tPastPos[0].sFinger_;
					}
					else
						WrongSeparationCnt = 0;
				}
				else
				{
					if(WrongSeparationCnt)	WrongSeparationCnt--;
					
				}
			}
		}
		PrevMaxTouchNum = MaxTouchNum;
		
	}
	else if(thisModeConf->Coord.ucWinCertAssistance == 3)
	{
		int curr_touch_num = 0, prev_touch_num = 0;
		static uint32_t maintain_touchnum_cnt = 0;
		static uint8_t fixed_touchnum = 0;
//		static tPredictPos_t prev_org_pos;
//		int i,j;
		//                   tCoordInfo_t *temp_coord;
		#define TOUCH_FIX_FRM_NUM 10

		curr_touch_num = temp_coord->tTempPos.sFinger_;
		prev_touch_num = temp_coord->tPastPos[0].sFinger_;

		if(curr_touch_num > 1 && curr_touch_num == prev_touch_num && fixed_touchnum==0){     //multi touch && maintain touch num
			maintain_touchnum_cnt++;
			if(maintain_touchnum_cnt > thisModeConf->Coord.ucTouchCountMax)//TOUCH_FIX_FRM_NUM)
				fixed_touchnum = prev_touch_num;
		}
		else if(curr_touch_num == 0){
			maintain_touchnum_cnt = 0;
			fixed_touchnum = 0;
		}

		if(fixed_touchnum == 0 && curr_touch_num != prev_touch_num)     //fixe??ei¿½i¿½i¿½i¿½ i??i?? i?i¿½i¿½ii¿½i¿½? ei¿½Æⓒi¿½i??ei¿½Æ￠i¿½ ei¿½i¿½i¿½i¿½i??ei¿½I￠i¿½ ii¿½i¿½?ei¿½i¿½i¿½i¿½ii¿½a¡±
			maintain_touchnum_cnt = 0;

		if(fixed_touchnum > 1 && curr_touch_num < prev_touch_num)
		{
			int i,j,pre_x,pre_y;
			uint8_t flag = 0;
			for(i=0;i<temp_coord->tPastPos[0].sFinger_;i++){
				flag = NO;
				pre_x = temp_coord->tPastPos[0].tXY[i].x;
				pre_y = temp_coord->tPastPos[0].tXY[i].y;
				for(j=0;j<temp_coord->tTempPos.sFinger_;j++){
					if(abs(pre_x - temp_coord->tTempPos.tXY[j].x) + abs(pre_y - temp_coord->tTempPos.tXY[j].y) < ((4+((TOUCH_FIX_FRM_NUM-maintain_touchnum_cnt)>>1))<<POS_BOOST_SHIFT_) ){
						flag = YES;	//i??i?i¿½i¿½ ii¿½i¿½?e??i??i?? i?i¿½i¿½i?i¿½i¿½i?i¿½i¿½ e?i¿½i¿½ei¿½i¿½i¿½i¿½i?i¿½i¿½ i??i?i¿½i¿½
						break;
					}
				}
				if(flag == NO)	break;	//i??i?i¿½i¿½ ii¿½i¿½?e??i??i?? i?i¿½i¿½i?i¿½i¿½i?i¿½i¿½ e?i¿½i¿½ei¿½i¿½i¿½i¿½i?i¿½i¿½ i?i¿½i¿½e?i¿½i¿½ i?i¿½i¿½i?? ii¿½i¿½?e??i?? e?i¿½i¿½ei¿½i¿½i¿½i¿½
			}
			
			if(flag == YES)
			{
				

				////////////////////////////////////////////
				
				for(i=0;i<temp_coord->tPastPos[0].sFinger_;i++)
				{
					temp_coord->tTempPos.tXY[i] = temp_coord->tPastPos[0].tXY[i];
//					temp_coord->tTempPos.tXY[i].x = temp_coord->tPastPos[0].tXY[i].x + ((curr_x - pre_x)>>1);		//TEST_CODE_190410
//					temp_coord->tTempPos.tXY[i].y = temp_coord->tPastPos[0].tXY[i].y + ((curr_y - pre_y)>>1);

					temp_coord->tTempPos.vusR[i]   = temp_coord->tPastPos[0].vusR[i];
					temp_coord->tTempPos.vusS[i]   = temp_coord->tPastPos[0].vusS[i];
				//  temp_coord->tTempPos.rect[i]   = temp_label->tTable[l].tRect;
				//  temp_coord->tTempPos.MaxDelta[i] = temp_label->tTable[l].sMaxCellVal;
				//  temp_coord->cRemap[i] = temp_coord->tTempPos.sFinger_;
				}
				temp_coord->tTempPos.sFinger_ = temp_coord->tPastPos[0].sFinger_;

				maintain_touchnum_cnt--;
				if(maintain_touchnum_cnt == 0)   fixed_touchnum = 0;
			}
		}
				 
	}
	else if(thisModeConf->Coord.ucWinCertAssistance == 4)
	{
		int i,j,dist;
		tCoordInfo_t 	*temp_coord = &thisInfo->tCoord;
		uint8_t match_flag[POSBUF_] = {0,};

		int PreFingerNum = 0;
		for(i = 0; i < POSBUF_; i++)if(temp_coord->tPastPos[0].vusS[i] > 0)PreFingerNum++;

		if(temp_coord->tTempPos.sFinger_ + 1 == PreFingerNum && temp_coord->tTempPos.sFinger_ > 0)
		{
			bool_t match_skip = 0;
			for(i = 0; i < temp_coord->tTempPos.sFinger_; i++)
			{
				int min_dist = 32767;
				int min_idx = -1;
				//for(j = 0; j < temp_coord->tOrgPastPos[0].sFinger_; j++)
				for (j = 0; j < POSBUF_; j++)
				{
					#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
					if( (temp_coord->tPastPos[0].vusS[j] && temp_coord->tOrgPastPos[1].vusS[j] && !thisInfo->tCoord.bInterpolation_On)
					|| (temp_coord->tPastPos[0].vusS[j] && temp_coord->tOrgPastPos[2].vusS[j] && thisInfo->tCoord.bInterpolation_On) )
					#else
					if(temp_coord->tPastPos[0].vusS[j] && temp_coord->tOrgPastPos[1].vusS[j])
					#endif
					{
						tXY_t pred_pos;
					#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
						if(thisInfo->tCoord.bInterpolation_On)
						{
							pred_pos.x = (temp_coord->tOrgPastPos[0].tXY[j].x << 1) - temp_coord->tOrgPastPos[2].tXY[j].x;
							pred_pos.y = (temp_coord->tOrgPastPos[0].tXY[j].y << 1) - temp_coord->tOrgPastPos[2].tXY[j].y;							
						}
						else
					#endif
						{
							pred_pos.x = (temp_coord->tOrgPastPos[0].tXY[j].x << 1) - temp_coord->tOrgPastPos[1].tXY[j].x;
							pred_pos.y = (temp_coord->tOrgPastPos[0].tXY[j].y << 1) - temp_coord->tOrgPastPos[1].tXY[j].y;
						}
						dist = algorithm_coord_calc_distance(temp_coord->tTempPos.tXY[i], pred_pos);
						if(min_dist > dist)
						{
							min_dist = dist;
							min_idx = j;
						}
					}
				}

				if(min_idx != -1 && min_dist < (UNIT_DIST<<1))
					match_flag[min_idx] = 1;
				else
				{
					match_skip = 1;
					break;
				}
			}

			if(match_skip==0)
			{
				//for(j = 0; j < temp_coord->tOrgPastPos[0].sFinger_; j++)
				for (j = 0; j < POSBUF_; j++)
				{
					if(temp_coord->tPastPos[0].vusS[j] && match_flag[j] == 0 && gReleaseCnt[j] < thisModeConf->Coord.ucMaxExtendFrameNum)
					{
						gReleaseCnt[j]++;
						temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].tXY[j];
						temp_coord->tTempPos.vusR[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].vusR[j];
						temp_coord->tTempPos.vusS[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].vusS[j];
						temp_coord->cRemap[temp_coord->tTempPos.sFinger_] = temp_coord->tTempPos.sFinger_;
						temp_coord->tTempPos.sFinger_++;
					}
					else gReleaseCnt[j] = 0;
				}
			}
//			else memset(gReleaseCnt,0,sizeof(gReleaseCnt));
		}
		else memset(gReleaseCnt,0,sizeof(gReleaseCnt));
	}
#endif
}
uint8_t PrevFinger = 0;
int VirtualCoordFrmCnt = 0;
int TestModeCnt = 0;
#define WINCERTMAXDISTANCE 13
#define VIRTUALCOORDFRMMAX 50
#define TESTMODETIMELIMIT  40
#define TESTMODEDELTAMAX	110
void algorithm_coord_drawing_assistance(int mode)
{
	int l,i,j,pl;
//	int r,c,_d;
//	uint32_t ulStrength = 0;
	tXY_t CoordAry[5], CoordTmp, PrevVector, CurrVector, ProjectionPoint;
	uint8_t ColMinLabelIdx=0,  ColMaxLabelIdx=0,  RowMinLabelIdx=0,  RowMaxLabelIdx=0;
	int ColMin=INT32_MAX, ColMax=0, RowMin=INT32_MAX, RowMax=0, Width=0, Height=0;
	int idx,JitterSum=0;
	uint8_t ModifyFlag = 0;
	tRect_t DeltaRect;

//	tLabelInfo_t	*temp_label;
	tCoordInfo_t 	*temp_coord;

	{
		temp_coord = &thisInfo->tCoord;
//		temp_label = &thisInfo->tLabel;
	}
	DeltaRect = thisInfo->tDelta.tValidRect;
	
	if(PrevFinger > 0 && temp_coord->tTempPos.sFinger_ == 0){
		if(thisInfo->WinCertMode >= 1)
			thisInfo->WinCertMode = 1;
		else
			thisInfo->WinCertMode = 0;	//0 : ready, 1 : detecting, -1 : normal touch, 2 : test mode
		thisInfo->DrawingDirection = 0;
		thisInfo->WinCertTrackingDist = 0;
//		thisInfo->TouchNumCnt = 0;
		thisInfo->TouchFrmCnt = 0;
		TestModeCnt = 0;
		PanningTestModeCnt = 0;
	}

	//detect win cert state
	if(temp_coord->tTempPos.sFinger_ > 2 && temp_coord->tTempPos.sFinger_ <= 5 && thisInfo->TouchFrmCnt < TESTMODETIMELIMIT )
	{	
		memcpy(CoordAry, temp_coord->tTempPos.tXY, sizeof(CoordAry));
		for(l = temp_coord->tTempPos.sFinger_; l--;)
		{
			if(temp_coord->tTempPos.tXY[l].x < ColMin)	ColMin = temp_coord->tTempPos.tXY[l].x, ColMinLabelIdx = l;
			if(temp_coord->tTempPos.tXY[l].x > ColMax)	ColMax = temp_coord->tTempPos.tXY[l].x, ColMaxLabelIdx = l;
			if(temp_coord->tTempPos.tXY[l].y < RowMin)	RowMin = temp_coord->tTempPos.tXY[l].y, RowMinLabelIdx = l;
			if(temp_coord->tTempPos.tXY[l].y > RowMax)	RowMax = temp_coord->tTempPos.tXY[l].y, RowMaxLabelIdx = l;
			
		}
		if(thisInfo->WinCertMode >= 0)
		{
			Width = abs(temp_coord->tTempPos.tXY[ColMaxLabelIdx].x - temp_coord->tTempPos.tXY[ColMinLabelIdx].x);
			Height = abs(temp_coord->tTempPos.tXY[RowMaxLabelIdx].y - temp_coord->tTempPos.tXY[RowMinLabelIdx].y);
			
			if(Width > Height){
				CoordTmp = CoordAry[ColMinLabelIdx];
				CoordAry[ColMinLabelIdx] = CoordAry[0];
				CoordAry[0] = CoordTmp;
				
				CoordTmp = CoordAry[ColMaxLabelIdx];
				CoordAry[ColMaxLabelIdx] = CoordAry[1];
				CoordAry[1] = CoordTmp;
				
	//			for(idx=1; idx<temp_coord->tTempPos.sFinger_;idx++){
	//				if(CoordAry[idx].x == CoordAry[0].x)
	//					JitterSum += CoordAry[idx].y - CoordAry[0].y;
	//				else
	//					JitterSum += abs(Height - (abs(CoordAry[idx].y - CoordAry[0].y) * Width / abs(CoordAry[idx].x - CoordAry[0].x)));
	//			}
	//			TotalRect = algorithm_merge_rect(temp_coord->tTempPos.rect[ColMinLabelIdx], temp_coord->tTempPos.rect[ColMaxLabelIdx]);
			}
			else{
				CoordTmp = CoordAry[RowMinLabelIdx];
				CoordAry[RowMinLabelIdx] = CoordAry[0];
				CoordAry[0] = CoordTmp;
				
				CoordTmp = CoordAry[RowMaxLabelIdx];
				CoordAry[RowMaxLabelIdx] = CoordAry[1];
				CoordAry[1] = CoordTmp;
				
	//			for(idx=1; idx<temp_coord->tTempPos.sFinger_;idx++){
	//				if(CoordAry[idx].y == CoordAry[0].y)
	//					JitterSum += abs(CoordAry[idx].x - CoordAry[0].x);
	//				else
	//					JitterSum += abs(Width - (abs(CoordAry[idx].x - CoordAry[0].x) * Height / abs(CoordAry[idx].y - CoordAry[0].y)));
	//			}
	//			TotalRect = algorithm_merge_rect(temp_coord->tTempPos.rect[RowMinLabelIdx], temp_coord->tTempPos.rect[RowMaxLabelIdx]);
			}
			JitterSum = 0;
			PrevVector.x = CoordAry[1].x - CoordAry[0].x;
			PrevVector.y = CoordAry[1].y - CoordAry[0].y;
			for(idx = 2 ; idx < temp_coord->tTempPos.sFinger_; idx++)
			{
				CurrVector.x = CoordAry[idx].x - CoordAry[0].x;
				CurrVector.y = CoordAry[idx].y - CoordAry[0].y;
				
				ProjectionPoint.x = CoordAry[0].x + (int)(PrevVector.x * (int64_t)(PrevVector.x*CurrVector.x + PrevVector.y*CurrVector.y) / (PrevVector.x*PrevVector.x+PrevVector.y*PrevVector.y));
				ProjectionPoint.y = CoordAry[0].y + (int)(PrevVector.y * (int64_t)(PrevVector.x*CurrVector.x + PrevVector.y*CurrVector.y) / (PrevVector.x*PrevVector.x+PrevVector.y*PrevVector.y));

				JitterSum += algorithm_coord_calc_distance(ProjectionPoint, CoordAry[idx]);
			}

			if(JitterSum < 200)
			{
				if(thisInfo->DrawingDirection == 0)
				{
					thisInfo->DrawingVector.x = 0;
					thisInfo->DrawingVector.y = 0;
				}
				if(Width > (Height<<4))				//Horizontal
					thisInfo->DrawingDirection = 1;
				else if(Height > (Width<<4))		//Vertical
					thisInfo->DrawingDirection = 2;
				else
					thisInfo->DrawingDirection = 3;		//Diagonal
				
				if(thisInfo->WinCertMode == 0)
					thisInfo->WinCertMode = 1;
				
				if(thisInfo->TouchFrmCnt < TESTMODETIMELIMIT)
					thisInfo->TouchFrmCnt++;
				
				if(thisInfo->TouchFrmCnt == TESTMODETIMELIMIT && thisInfo->WinCertMode < 2)
					thisInfo->WinCertMode  = 2;
			}
			else{
				if(JitterSum > 400)
					thisInfo->TouchFrmCnt = -1;
				else
					thisInfo->TouchFrmCnt--;
			}

			if(thisInfo->DrawingDirection == 2 && (Width > 90 || DeltaRect.ce - DeltaRect.cs > 1)){
				thisInfo->TouchFrmCnt = -1;
			}
		}
	}
	if(temp_coord->tTempPos.sFinger_ > 5 && thisInfo->TouchFrmCnt < TESTMODETIMELIMIT )
	{
		thisInfo->TouchFrmCnt--;
	}
	if(thisInfo->TouchFrmCnt < 0){
		thisInfo->TouchFrmCnt = TESTMODETIMELIMIT;
		thisInfo->DrawingDirection = 0;
		thisInfo->WinCertMode = -1;
	}
	
#if 1	
	if(thisInfo->DrawingDirection == 2 && temp_coord->tTempPos.sFinger_ != 5)
	{
		tXY_t Center;
		
		int Dist = 0, MaxDist = 0, MinDist = 0, BetDist = 480;
		int8_t ThumbIdx = 0,TempIdx = 0;
		uint16_t BitFlag = 0;
		
		if(DeltaRect.re - DeltaRect.rs + 1 >= 9 && DeltaRect.re - DeltaRect.rs + 1 <= WINCERTMAXDISTANCE &&temp_coord->tTempPos.sFinger_>2)
		{
			
			Center.y = 0;
			for(i=0;i<temp_coord->tTempPos.sFinger_;i++){
				if(Center.y < temp_coord->tTempPos.tXY[i].y){
					Center.y = temp_coord->tTempPos.tXY[i].y;
					ThumbIdx = i;
				}
			}

			Center.x = 0, Center.y = 0;
			for(i=0;i<temp_coord->tTempPos.sFinger_;i++){
				if(i != ThumbIdx){
					Center.x += temp_coord->tTempPos.tXY[i].x;
					Center.y += temp_coord->tTempPos.tXY[i].y;
				}
			}
			Center.x /= (temp_coord->tTempPos.sFinger_-1);
			Center.y /= (temp_coord->tTempPos.sFinger_-1);

			if(PrevFinger == 5)
			{
//				if(temp_coord->tTempPos.sFinger_ != 5)
				{
					//Delete other coordinate
					for(i=1;i<POSBUF_;i++){
						temp_coord->tTempPos.vusR[i]   = 0;
						temp_coord->tTempPos.vusS[i]   = 0;
					}
					//Virtual Coordinate
					temp_coord->tTempPos.sFinger_ = 0;
					for(i=0;i<POSBUF_;i++)
					{
						if(temp_coord->tOrgPastPos[0].vusR[i] > 0)
						{
							temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].tXY[i];
							temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_].x = Center.x;
							temp_coord->tTempPos.vusR[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].vusR[i];
							temp_coord->tTempPos.vusS[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].vusS[i];
							temp_coord->cRemap[temp_coord->tTempPos.sFinger_] = temp_coord->tTempPos.sFinger_;
							temp_coord->tTempPos.sFinger_++;
						}
					}
				}
			}
			else
			{
				if(thisInfo->TouchFrmCnt < TESTMODETIMELIMIT)
				{
					for(i=0;i<POSBUF_;i++){
						temp_coord->tTempPos.vusR[i]   = 0;
						temp_coord->tTempPos.vusS[i]   = 0;
					}
					temp_coord->tTempPos.sFinger_ = 0;
					for(pl=0;pl<POSBUF_;pl++)
					{
						if(temp_coord->tOrgPastPos[0].vusS[pl] > 0)
						{
							temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].tXY[pl];
							temp_coord->tTempPos.vusR[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].vusR[pl];
							temp_coord->tTempPos.vusS[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].vusS[pl];
							temp_coord->cRemap[temp_coord->tTempPos.sFinger_] = temp_coord->tTempPos.sFinger_;
							temp_coord->tTempPos.sFinger_++;				
						}
					}
				}
				else{
					//Thumb coordinate
					temp_coord->tTempPos.tXY[0] = temp_coord->tTempPos.tXY[ThumbIdx];
					temp_coord->tTempPos.vusR[0] = temp_coord->tTempPos.vusR[ThumbIdx];
					temp_coord->tTempPos.vusS[0] = temp_coord->tTempPos.vusS[ThumbIdx];
					temp_coord->cRemap[0] = 0;
					
					//Delete other coordinate
					for(i=1;i<POSBUF_;i++){
						temp_coord->tTempPos.vusR[i]   = 0;
						temp_coord->tTempPos.vusS[i]   = 0;
					}
					
					//Virtual Coordinate
					for(i=1;i<5;i++)
					{
						temp_coord->tTempPos.tXY[i].x = Center.x;
	//					temp_coord->tTempPos.tXY[i].y = Center.y - (BetDist + (BetDist>>1)) + (BetDist*(i-1));
						temp_coord->tTempPos.vusR[i] = temp_coord->tTempPos.vusR[0];
						temp_coord->tTempPos.vusS[i] = temp_coord->tTempPos.vusS[0];
						temp_coord->cRemap[i] = i;
					}
					temp_coord->tTempPos.tXY[1].y = temp_coord->tTempPos.tXY[0].y - 936;
					temp_coord->tTempPos.tXY[2].y = temp_coord->tTempPos.tXY[0].y - 1447;
					temp_coord->tTempPos.tXY[3].y = temp_coord->tTempPos.tXY[0].y - 1958;
					temp_coord->tTempPos.tXY[4].y = temp_coord->tTempPos.tXY[0].y - 2469;
					temp_coord->tTempPos.sFinger_ = 5;
					
					thisInfo->WinCertMode = 3;
				}
			}
		}
		else{
			for(i=0;i<POSBUF_;i++){
				temp_coord->tTempPos.vusR[i]   = 0;
				temp_coord->tTempPos.vusS[i]   = 0;
			}
			temp_coord->tTempPos.sFinger_ = 0;
			for(pl=0;pl<POSBUF_;pl++)
			{
				if(temp_coord->tOrgPastPos[0].vusS[pl] > 0)
				{
					temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].tXY[pl];
					temp_coord->tTempPos.vusR[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].vusR[pl];
					temp_coord->tTempPos.vusS[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].vusS[pl];
					temp_coord->cRemap[temp_coord->tTempPos.sFinger_] = temp_coord->tTempPos.sFinger_;
					temp_coord->tTempPos.sFinger_++;				
				}
			}
		}
	}	
	else if(thisInfo->DrawingDirection == 3)
	{
		if(PrevFinger == 5 && temp_coord->tTempPos.sFinger_ > 1 && temp_coord->tTempPos.sFinger_ < 5 && VirtualCoordFrmCnt < VIRTUALCOORDFRMMAX)
		{
			for(i=0;i<POSBUF_;i++){
				temp_coord->tTempPos.vusR[i]   = 0;
				temp_coord->tTempPos.vusS[i]   = 0;
			}
			temp_coord->tTempPos.sFinger_ = 0;
			for(pl=0;pl<POSBUF_;pl++)
			{
				if(temp_coord->tOrgPastPos[0].vusS[pl] > 0)
				{
					temp_coord->tTempPos.tXY[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].tXY[pl];
					temp_coord->tTempPos.vusR[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].vusR[pl];
					temp_coord->tTempPos.vusS[temp_coord->tTempPos.sFinger_] = temp_coord->tOrgPastPos[0].vusS[pl];
					temp_coord->cRemap[temp_coord->tTempPos.sFinger_] = temp_coord->tTempPos.sFinger_;
					temp_coord->tTempPos.sFinger_++;
				}					
			}
			VirtualCoordFrmCnt++;
		}
		else{
			VirtualCoordFrmCnt = 0;
		}
		
	}
	else{
		VirtualCoordFrmCnt = 0;
	}
	
	if(thisInfo->DrawingDirection >= 2 && temp_coord->tTempPos.sFinger_ == 5)
	{
		tXY_t WinCert5Pos[5];
		
		uint8_t IdxMap[5], tmp;
		
		memcpy(CoordAry, temp_coord->tTempPos.tXY, sizeof(CoordAry));
		
		for(i=0;i<5;i++)
			IdxMap[i] = i;
		
		for(i=0;i<4;i++)
		for(j=i+1;j<5;j++)
		{
			if(CoordAry[i].y > CoordAry[j].y)
			{
				CoordTmp = CoordAry[j];
				CoordAry[j] = CoordAry[i];
				CoordAry[i] = CoordTmp;
				
				tmp = IdxMap[j];
				IdxMap[j] = IdxMap[i];
				IdxMap[i] = tmp;
			}
		}
		if(thisInfo->DrawingDirection == 2)
		{
			WinCert5Pos[4].y = CoordAry[4].y;
			WinCert5Pos[3].y = CoordAry[4].y - 936 - 40;
			WinCert5Pos[2].y = CoordAry[4].y - 1447 - 30;
			WinCert5Pos[1].y = CoordAry[4].y - 1958 + 10;
			WinCert5Pos[0].y = CoordAry[4].y - 2469;
			ModifyFlag = YES;
			for(i=0;i<4;i++){
				if(abs(WinCert5Pos[i].y - CoordAry[i].y) > 150)
					ModifyFlag = NO;
			}
			if(ModifyFlag)
			{
				for(i=0;i<4;i++)
				{
	//				temp_coord->tTempPos.tXY[IdxMap[i]].y = ((temp_coord->tTempPos.tXY[IdxMap[i]].y + WinCert5Pos[i])>>1);
					temp_coord->tTempPos.tXY[IdxMap[i]].y = WinCert5Pos[i].y;
				}
				
			}
			else
			{
				WinCert5Pos[4].y = CoordAry[4].y;
				WinCert5Pos[3].y = WinCert5Pos[4].y - 621;
				WinCert5Pos[2].y = WinCert5Pos[3].y - 621;
				WinCert5Pos[1].y = WinCert5Pos[2].y - 621;
				WinCert5Pos[0].y = WinCert5Pos[1].y - 621;
				
				ModifyFlag = YES;
				for(i=0;i<4;i++){
					if(abs(WinCert5Pos[i].y - CoordAry[i].y) > 150)
						ModifyFlag = NO;
				}
				if(ModifyFlag)
				{
					for(i=0;i<4;i++)
					{
		//				temp_coord->tTempPos.tXY[IdxMap[i]].y = ((temp_coord->tTempPos.tXY[IdxMap[i]].y + WinCert5Pos[i])>>1);
						temp_coord->tTempPos.tXY[IdxMap[i]].y = WinCert5Pos[i].y;
					}
				}
			
			}
		}
		else
		{
			WinCert5Pos[4] = CoordAry[4];
			WinCert5Pos[0] = CoordAry[0];
			WinCert5Pos[2].x = ((WinCert5Pos[4].x + WinCert5Pos[0].x+1)>>1);
			WinCert5Pos[2].y = ((WinCert5Pos[4].y + WinCert5Pos[0].y+1)>>1);
			WinCert5Pos[1].x = ((WinCert5Pos[2].x + WinCert5Pos[0].x+1)>>1);
			WinCert5Pos[1].y = ((WinCert5Pos[2].y + WinCert5Pos[0].y+1)>>1);
			WinCert5Pos[3].x = ((WinCert5Pos[4].x + WinCert5Pos[2].x+1)>>1);
			WinCert5Pos[3].y = ((WinCert5Pos[4].y + WinCert5Pos[2].y+1)>>1);
			
			ModifyFlag = YES;
			for(i=1;i<4;i++){
				if(algorithm_coord_calc_distance(WinCert5Pos[i],CoordAry[i]) > 150)
					ModifyFlag = NO;
			}

			if(ModifyFlag)
			{
				for(i=1;i<4;i++)
				{
					temp_coord->tTempPos.tXY[IdxMap[i]].x = ((temp_coord->tTempPos.tXY[IdxMap[i]].x + WinCert5Pos[i].x+1)>>1);
					temp_coord->tTempPos.tXY[IdxMap[i]].y = ((temp_coord->tTempPos.tXY[IdxMap[i]].y + WinCert5Pos[i].y+1)>>1);
				//	temp_coord->tTempPos.tXY[IdxMap[i]] = WinCert5Pos[i];
				}
				
			}
		}
	}
	
#endif	

	PrevFinger = temp_coord->tTempPos.sFinger_;
}

#if (REMOVE_EDGE_EN == YES)
int8_t algorithm_coord_EdgeDirection(int8_t r, int8_t c, int offset)
{
	int8_t cRet = 0;

	if( c <= (0 + offset) )					cRet = 1;	
	else if( c >= (COL_MAX - 1 - offset) )	cRet = 2;
	
	if( r <= (0 + offset) )					cRet += 10;
	else if( r >= (ROW_MAX - 1 - offset) )	cRet += 20;

	return cRet;
}
#endif

int8_t algorithm_coord_IsEdgeArea(tXY_t * pos, int offset)
{
	int8_t cRet = 0;

	if( (pos->x < thisInfo->tCoord.iXEdgeStart + offset) || ((thisInfo->tCoord.iInternalXRes - pos->x) < thisInfo->tCoord.iXEdgeStart + offset) )
	{
		if( ( pos->y < thisInfo->tCoord.iYEdgeStart + offset ) || ((thisInfo->tCoord.iInternalYRes - pos->y) < thisInfo->tCoord.iYEdgeStart + offset) )
		{
			cRet = 2;
		}
		else
		{
			cRet = 1;
		}
	}
	else if( (pos->y < thisInfo->tCoord.iYEdgeStart + offset) || ((thisInfo->tCoord.iInternalYRes - pos->y) < thisInfo->tCoord.iYEdgeStart + offset) )
	{
		cRet = 1;
	}

	return cRet;
}

int8_t algorithm_coord_EdgeAreaDist(tXY_t * pos)
{
	int8_t cRet = 0;

//	if( (pos->x < thisInfo->tCoord.iXEdgeStart) || ((thisInfo->tCoord.iInternalXRes - pos->x) < thisInfo->tCoord.iXEdgeStart) )
//	{
////		if( ( pos->y < thisInfo->tCoord.iYEdgeStart ) || ((thisInfo->tCoord.iInternalYRes - pos->y) < thisInfo->tCoord.iYEdgeStart) )
////		{
//			cRet = 1;//2;
////		}
////		else
////		{
////			cRet = 1;
////		}
//	}
//	else if( (pos->y < thisInfo->tCoord.iYEdgeStart) || ((thisInfo->tCoord.iInternalYRes - pos->y) < thisInfo->tCoord.iYEdgeStart) )
//	{
//		cRet = 1;
//	}
	
	if(pos->x < thisInfo->tCoord.iXEdgeStart)
	{
		cRet = (thisInfo->tCoord.iXEdgeStart - pos->x)>>2;
	}
	else if((thisInfo->tCoord.iInternalXRes - pos->x) < thisInfo->tCoord.iXEdgeStart)
	{
		cRet = (thisInfo->tCoord.iXEdgeStart - (thisInfo->tCoord.iInternalXRes - pos->x))>>2;
	}
	else if(pos->y < thisInfo->tCoord.iYEdgeStart)
	{
		cRet = (thisInfo->tCoord.iYEdgeStart - pos->y)>>2;
	}
	else if((thisInfo->tCoord.iInternalYRes - pos->y) < thisInfo->tCoord.iYEdgeStart)
	{
		cRet = (thisInfo->tCoord.iYEdgeStart - (thisInfo->tCoord.iInternalYRes - pos->y))>>2;
	}
	

	return cRet;
}

uint8_t algorithm_coord_IsEdgeArea_Cell(int8_t r, int8_t c, int8_t offset)
{
	uint8_t bRet = 0;

	if( (r <= 0 + offset) || (r >= ROW_MAX-1-offset) )
	{
		if((c <= 0 + offset) || (c >= COL_MAX-1-offset))bRet = 2;
		else bRet = 1;
	}
	else if((c <= 0 + offset) || (c >= COL_MAX-1-offset))bRet = 1;
	
	return bRet;
}

extern ePartialSensing_t g_RetVal;
void algorithm_coord_tracking_pos(int mode)
{
    uint8_t pl, cl; // Index of Previous Label, Current Label
//    int32_t iDist, iDist2, iMinDist; // NOTE : not used
    int32_t iDist, iMinDist;
//    int match; // NOTE : not used
    int8_t cReorderRemap[LOOSE_POSBUF_];
    uint32_t ulPrematchedDist[LOOSE_POSBUF_];
    int32_t lDistanceMap[LOOSE_POSBUF_][LOOSE_POSBUF_];
//    tXY_t pred_pos, avg_pos, curr_pos; // NOTE : not used
    tXY_t pred_pos;
    tXY_t curr_pos_sum;
    tXY_t prev_pos_sum;
    tXY_t comp_pos;
    int match_cl, match_pl;
    int iDistanceThd;
    tXY_t pos_max, pos_min;
    bool_t bCompFlag;
#if (PalmCandidateTouchCut_EN == YES)
	static uint16_t usPalmCandiShapeMatchingLearningCnt = 0;
#endif
	
	tCoordInfo_t 	*temp_coord;
	
#if !defined(FINGER_ONLY)
	static int sPMode = 0;

	if(mode != FULL_MODE)
	{
		temp_coord = &thisInfo->tCoord_local;
		if(sPMode != mode){
			algorithm_coord_init_local();
			memset(tPastPosHist,-1,sizeof(tPastPosHist));
		}
	}
	else
		temp_coord = &thisInfo->tCoord;
	
	sPMode = mode;
#else /* !defined(FINGER_ONLY) */
	temp_coord = &thisInfo->tCoord;
#endif /* !defined(FINGER_ONLY) */

    temp_coord->tPos.sFinger_ = MIN(temp_coord->tTempPos.sFinger_, MAX_TOUCH_);

    memset(&cReorderRemap, -1, sizeof(cReorderRemap));
    memset(&ulPrematchedDist, UINT8_MAX, sizeof(ulPrematchedDist));

#if 1
	if( temp_coord->tPos.sFinger_ > 1 && temp_coord->tPastPos[0].sFinger_ == temp_coord->tPos.sFinger_ )
	{
		curr_pos_sum.x = 0;
		curr_pos_sum.y = 0;
		prev_pos_sum.x = 0;
		prev_pos_sum.y = 0;
		pos_min.x = INT32_MAX;
		pos_max.x = 0;
		pos_min.y = INT32_MAX;
		pos_max.y = 0;

		for( cl = 0; cl < temp_coord->tTempPos.sFinger_; cl++ )
		{
			if( temp_coord->tTempPos.vusR[cl] != 0 )
			{
				curr_pos_sum.x += temp_coord->tTempPos.tXY[cl].x;
				curr_pos_sum.y += temp_coord->tTempPos.tXY[cl].y;

				if( pos_min.x > temp_coord->tTempPos.tXY[cl].x )
					pos_min.x = temp_coord->tTempPos.tXY[cl].x;
				if( pos_max.x < temp_coord->tTempPos.tXY[cl].x )
					pos_max.x = temp_coord->tTempPos.tXY[cl].x;
				if( pos_min.y > temp_coord->tTempPos.tXY[cl].y )
					pos_min.y = temp_coord->tTempPos.tXY[cl].y;
				if( pos_max.y < temp_coord->tTempPos.tXY[cl].y )
					pos_max.y = temp_coord->tTempPos.tXY[cl].y;
			}
		}

		for( pl = 0; pl < MAX_TOUCH_; pl++ )
		{
			if( temp_coord->tPastPos[0].vusR[pl] != 0 )
			{
				prev_pos_sum.x += temp_coord->tOrgPastPos[0].tXY[pl].x;
				prev_pos_sum.y += temp_coord->tOrgPastPos[0].tXY[pl].y;
			}
		}
		comp_pos.x = curr_pos_sum.x - prev_pos_sum.x;
		comp_pos.y = curr_pos_sum.y - prev_pos_sum.y;
		comp_pos.x = comp_pos.x / temp_coord->tPos.sFinger_;
		comp_pos.y = comp_pos.y / temp_coord->tPos.sFinger_;

		if( (pos_max.x - pos_min.x) < (thisModeConf->CoordTracking.usCenterMatchDistanceThd << POS_BOOST_SHIFT_)
  		 && (pos_max.y - pos_min.y) < (thisModeConf->CoordTracking.usCenterMatchDistanceThd << POS_BOOST_SHIFT_) )
		{
			bCompFlag = 1;
		}
		else
		{
			bCompFlag = 0;
		}
	}
	else
	{
		bCompFlag = 0;
	}

	for (pl = 0; pl < LOOSE_POSBUF_; pl++)
		for (cl = 0; cl < LOOSE_POSBUF_; cl++)
			lDistanceMap[pl][cl] = INT32_MAX;

    for (pl = 0; pl < MAX_TOUCH_; pl++)
	{
		if (temp_coord->tPastPos[0].vusR[pl] != 0)
		{
			for (cl = 0; cl < temp_coord->tTempPos.sFinger_; cl++)
			{
				if (temp_coord->tTempPos.vusR[cl]) //For unmatched fingers,
				{
					uint16_t Check_vusR = 0;
					tXY_t UsePastPos;
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
					if(temp_coord->bInterpolation_On)
					{
						Check_vusR = temp_coord->tPastPos[2].vusR[pl];
						UsePastPos = temp_coord->tOrgPastPos[2].tXY[pl];
					}
					else
#endif
					{
						Check_vusR = temp_coord->tPastPos[1].vusR[pl];
						UsePastPos = temp_coord->tOrgPastPos[1].tXY[pl];
					}
					
					if( Check_vusR )
					{
						pred_pos.x = (temp_coord->tOrgPastPos[0].tXY[pl].x << 1) - UsePastPos.x;
						pred_pos.y = (temp_coord->tOrgPastPos[0].tXY[pl].y << 1) - UsePastPos.y;
					}
					else
					{
						pred_pos.x = temp_coord->tOrgPastPos[0].tXY[pl].x;
						pred_pos.y = temp_coord->tOrgPastPos[0].tXY[pl].y;
					}
					
					Check_vusR = 0;
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
					if(temp_coord->bInterpolation_On)
						Check_vusR = temp_coord->tPastPos[4].vusR[pl];
					else
#endif
						Check_vusR = temp_coord->tPastPos[2].vusR[pl];
					
					if( Check_vusR )
					{
						int sPred_x, sPred_y;
						int fPred_x, fPred_y;
						int sub_x1, sub_y1, sub_x2, sub_y2;
						tXY_t pred_pos2;
					
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
						if(temp_coord->bInterpolation_On)
						{
							fPred_x = temp_coord->tOrgPastPos[4].tXY[pl].x - temp_coord->tOrgPastPos[2].tXY[pl].x;
							fPred_y = temp_coord->tOrgPastPos[4].tXY[pl].y - temp_coord->tOrgPastPos[2].tXY[pl].y;
							sPred_x = temp_coord->tOrgPastPos[2].tXY[pl].x - temp_coord->tOrgPastPos[0].tXY[pl].x;
							sPred_y = temp_coord->tOrgPastPos[2].tXY[pl].y - temp_coord->tOrgPastPos[0].tXY[pl].y;
						}
						else
#endif
						{
							fPred_x = temp_coord->tOrgPastPos[2].tXY[pl].x - temp_coord->tOrgPastPos[1].tXY[pl].x;
							fPred_y = temp_coord->tOrgPastPos[2].tXY[pl].y - temp_coord->tOrgPastPos[1].tXY[pl].y;
							sPred_x = temp_coord->tOrgPastPos[1].tXY[pl].x - temp_coord->tOrgPastPos[0].tXY[pl].x;
							sPred_y = temp_coord->tOrgPastPos[1].tXY[pl].y - temp_coord->tOrgPastPos[0].tXY[pl].y;
						}
						
						pred_pos2.x = temp_coord->tOrgPastPos[0].tXY[pl].x - (sPred_x + sPred_x - fPred_x);
						pred_pos2.y = temp_coord->tOrgPastPos[0].tXY[pl].y - (sPred_y + sPred_y - fPred_y);
						
						sub_x1 = pred_pos.x - temp_coord->tTempPos.tXY[cl].x;
						sub_y1 = pred_pos.y - temp_coord->tTempPos.tXY[cl].y;
						if(sub_x1 < 0)	sub_x1 = -sub_x1;
						if(sub_y1 < 0)	sub_y1 = -sub_y1;
						
						sub_x2 = pred_pos2.x - temp_coord->tTempPos.tXY[cl].x;
						sub_y2 = pred_pos2.y - temp_coord->tTempPos.tXY[cl].y;
						if(sub_x2 < 0)	sub_x2 = -sub_x2;
						if(sub_y2 < 0)	sub_y2 = -sub_y2;
						
						sub_x1 += sub_y1;
						sub_x2 += sub_y2;
						
						if(sub_x2 < sub_x1)
							pred_pos = pred_pos2;
					}

					if( bCompFlag )
					{
						iDist = algorithm_coord_calc_comp_distance(temp_coord->tTempPos.tXY[cl], temp_coord->tOrgPastPos[0].tXY[pl], comp_pos);
					}
					else
					{
						iDist = algorithm_coord_calc_distance(temp_coord->tTempPos.tXY[cl], pred_pos);
					}
					lDistanceMap[pl][cl] = iDist;
				}
			}
		}
	}

    do
	{
    	match_cl = -1;
    	match_pl = -1;

		iMinDist = INT32_MAX;

		for(pl = 0; pl < MAX_TOUCH_; pl++)
		{
			if (temp_coord->tPastPos[0].vusR[pl] != 0)
			{
				for(cl = 0; cl < temp_coord->tTempPos.sFinger_; cl++)
				{
					if (temp_coord->tTempPos.vusR[cl]) //For unmatched fingers,
					{
						iDist = lDistanceMap[pl][cl];
						if(iDist == -1) continue;

						if(iDist < iMinDist)
						{
							iMinDist = iDist;
							match_cl = cl;
							match_pl = pl;
						}
					}
				}
			}
		}

		if( bCompFlag )
		{
			uint16_t Check_vusR = 0;
			tXY_t UsePastPos;
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
			if(temp_coord->bInterpolation_On)
			{
				Check_vusR = temp_coord->tPastPos[2].vusR[match_pl];
				UsePastPos = temp_coord->tOrgPastPos[2].tXY[match_pl];
			}
			else
#endif
			{
				Check_vusR = temp_coord->tPastPos[1].vusR[match_pl];
				UsePastPos = temp_coord->tOrgPastPos[1].tXY[match_pl];
			}

			if( Check_vusR )
			{
				pred_pos.x = (temp_coord->tOrgPastPos[0].tXY[match_pl].x << 1) - UsePastPos.x;
				pred_pos.y = (temp_coord->tOrgPastPos[0].tXY[match_pl].y << 1) - UsePastPos.y;
			}
			else
			{
				pred_pos.x = temp_coord->tOrgPastPos[0].tXY[match_pl].x;
				pred_pos.y = temp_coord->tOrgPastPos[0].tXY[match_pl].y;
			}
			
			Check_vusR = 0;
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
			if(temp_coord->bInterpolation_On)
				Check_vusR = temp_coord->tPastPos[4].vusR[match_pl];
			else
#endif
				Check_vusR = temp_coord->tPastPos[2].vusR[match_pl];

			if( Check_vusR )
			{
				int sPred_x, sPred_y;
				int fPred_x, fPred_y;
				int sub_x1, sub_y1, sub_x2, sub_y2;
				tXY_t pred_pos2;
				
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
				if(temp_coord->bInterpolation_On)
				{					
					fPred_x = temp_coord->tOrgPastPos[4].tXY[match_pl].x - temp_coord->tOrgPastPos[2].tXY[match_pl].x;
					fPred_y = temp_coord->tOrgPastPos[4].tXY[match_pl].y - temp_coord->tOrgPastPos[2].tXY[match_pl].y;
					sPred_x = temp_coord->tOrgPastPos[2].tXY[match_pl].x - temp_coord->tOrgPastPos[0].tXY[match_pl].x;
					sPred_y = temp_coord->tOrgPastPos[2].tXY[match_pl].y - temp_coord->tOrgPastPos[0].tXY[match_pl].y;
				}
				else
#endif
				{
					fPred_x = temp_coord->tOrgPastPos[2].tXY[match_pl].x - temp_coord->tOrgPastPos[1].tXY[match_pl].x;
					fPred_y = temp_coord->tOrgPastPos[2].tXY[match_pl].y - temp_coord->tOrgPastPos[1].tXY[match_pl].y;
					sPred_x = temp_coord->tOrgPastPos[1].tXY[match_pl].x - temp_coord->tOrgPastPos[0].tXY[match_pl].x;
					sPred_y = temp_coord->tOrgPastPos[1].tXY[match_pl].y - temp_coord->tOrgPastPos[0].tXY[match_pl].y;
				}
				
				pred_pos2.x = temp_coord->tOrgPastPos[0].tXY[match_pl].x - (sPred_x + sPred_x - fPred_x);
				pred_pos2.y = temp_coord->tOrgPastPos[0].tXY[match_pl].y - (sPred_y + sPred_y - fPred_y);
				
				sub_x1 = pred_pos.x - temp_coord->tTempPos.tXY[match_cl].x;
				sub_y1 = pred_pos.y - temp_coord->tTempPos.tXY[match_cl].y;
				if(sub_x1 < 0)	sub_x1 = -sub_x1;
				if(sub_y1 < 0)	sub_y1 = -sub_y1;
				
				sub_x2 = pred_pos2.x - temp_coord->tTempPos.tXY[match_cl].x;
				sub_y2 = pred_pos2.y - temp_coord->tTempPos.tXY[match_cl].y;
				if(sub_x2 < 0)	sub_x2 = -sub_x2;
				if(sub_y2 < 0)	sub_y2 = -sub_y2;
				
				sub_x1 += sub_y1;
				sub_x2 += sub_y2;
				
				if(sub_x2 < sub_x1)
					pred_pos = pred_pos2;
			}
			
			iMinDist = algorithm_coord_calc_distance(temp_coord->tTempPos.tXY[match_cl], pred_pos);
		}

		//Set tracking distance
		{
			uint8_t FirstMoveFrameNum = 0;
			if(thisModeConf->CoordTracking.ucFastDrawingMode)
				FirstMoveFrameNum = 2;
			else
				FirstMoveFrameNum = 1;
	//		if (temp_coord->bIsMoving[match_pl] == NO)		//In tracking
			if (temp_coord->ucIdMappedCnt[match_pl] <= FirstMoveFrameNum)
			{
				iDistanceThd = (thisModeConf->CoordTracking.usFirstMoveDistanceThd << POS_BOOST_SHIFT_);
			}
			else
			{
				//Dynamic tracking distance
				if(thisModeConf->CoordTracking.ucDynamicTrackingDistanceMode == 1)
				{
//					if(thisInfo->WinCertMode){
//						thisInfo->WinCertTrackingDist = MAX(thisInfo->WinCertTrackingDist, (temp_coord->lPrevDist[match_pl]<<3));
//						iDistanceThd = MAX( (1<<(POS_BOOST_SHIFT_-1)), thisInfo->WinCertTrackingDist );
//					}
//					else
					{
						if(algorithm_coord_IsEdgeArea(&temp_coord->iStopPos[match_pl],0)>0)
							iDistanceThd = MAX( (3<<(POS_BOOST_SHIFT_)), (temp_coord->lPrevDist[match_pl]<<2) );
						else
							iDistanceThd = MAX( (1<<(POS_BOOST_SHIFT_))+(1<<(POS_BOOST_SHIFT_-1)), (temp_coord->lPrevDist[match_pl]<<2) );
						
		//				if(temp_coord->ucIdMappedCnt[match_pl] >= 4)
		//					iDistanceThd = (thisModeConf->CoordTracking.usMoveDistanceThd << POS_BOOST_SHIFT_);
					}
				}
				else if(thisModeConf->CoordTracking.ucDynamicTrackingDistanceMode == 2)
				{
					iDistanceThd = MAX( ((temp_coord->ucIdMappedCnt[match_pl]+1)<<(POS_BOOST_SHIFT_)), (temp_coord->lPrevDist[match_pl]<<2) );
				}
				else
				{	
					iDistanceThd = temp_coord->slScaledMoveDistThd;
					if (temp_coord->lPrevDist[match_pl] > temp_coord->slScaledMoveDistThd)
						iDistanceThd += (temp_coord->lPrevDist[match_pl] * 2);
				}
			}
#if USED_NOISE_HOPPING_FREQ
//			if(ptAppInfo->eHoppingStatus == FREQ_HOPPING_CHANGED)
			if(ptAppInfo->ucHoppFrameCnt)
			{
//				iDistanceThd <<= 2;
				iDistanceThd = (thisModeConf->Noise.ucHoppingMoveDistanceThd << POS_BOOST_SHIFT_);
				if (temp_coord->lPrevDist[match_pl] > iDistanceThd)
						iDistanceThd += (temp_coord->lPrevDist[match_pl] * 2);
				
				iDistanceThd = MAX( (iDistanceThd), (temp_coord->lPrevDist[match_pl]<<2) );
				ptAppInfo->ucHoppFrameCnt = 0;
			}
#endif /* USED_NOISE_HOPPING_FREQ */
		}


		if(mode == FULL_MODE)
		{
			if(iMinDist > iDistanceThd)
			{
				match_cl = -1;
				match_pl = -1;
			}
#if USED_NOISE_HOPPING_FREQ
			else if(ptAppInfo->eHoppingStatus == FREQ_HOPPING_CHANGED)
			{
				ptAppInfo->eHoppingStatus = FREQ_HOPPING_NONE;
			}
#endif /* USED_NOISE_HOPPING_FREQ */
#if (USED_DRUM_ALGO == YES)
			///////////drum in tracking starts here
			if(thisModeConf->Coord.usDrumTestDist)
			{
				if(DrumStep[match_pl] == 1)
				{
					int InnerProduct = 0, S1=0, S2=0,CosSeta = 0;
					tXY_t P[3];
					tXY_t V1,V2;

					P[0] = temp_coord->tTempPos.tXY[match_cl];
//					P[1] = temp_coord->tOrgPosHist[1].tXY[match_pl];
//					P[2] = temp_coord->tOrgPosHist[3].tXY[match_pl];
					P[1] = temp_coord->tOrgPastPos[0].tXY[match_pl];
					P[2] = temp_coord->tOrgPastPos[2].tXY[match_pl];
					V1.x = P[0].x - P[1].x;
					V1.y = P[0].y - P[1].y;
					V2.x = P[1].x - P[2].x;
					V2.y = P[1].y - P[2].y;
					S1 = algorithm_coord_calc_distance(P[0], P[1]);
					S2 = algorithm_coord_calc_distance(P[1], P[2]);
					InnerProduct = V1.x*V2.x + V1.y*V2.y;
					CosSeta = InnerProduct * (thisModeConf->Coord.usDrumTestDist>>1) / (S1*S2);
					if(CosSeta < 0)	CosSeta = 0;
					if(CosSeta > (thisModeConf->Coord.usDrumTestDist>>1))	CosSeta = (thisModeConf->Coord.usDrumTestDist>>1);
					
//					if( (InnerProduct<<1) < S1*S2 || S1 < (thisModeConf->Coord.usDrumTestDist) )
//					if(S1 < (thisModeConf->Coord.usDrumTestDist>>1)  )
					if( S1 < (thisModeConf->Coord.usDrumTestDist - CosSeta) )
					{
						int cnt;
						

						cnt = 0;
						for(cl = 0; cl < temp_coord->tTempPos.sFinger_; cl++)
							if(lDistanceMap[match_pl][cl] < (thisModeConf->CoordTracking.usMoveDistanceThd << POS_BOOST_SHIFT_))
								cnt++;
						
						if(cnt == 1)
						{
							lDistanceMap[match_pl][match_cl] = -1;
							continue;
						}
					}
					DrumStep[match_pl] = 2;
				}
			}
//////////////////drum in tracking ends here
#endif/* USED_DRUM_ALGO */
		}
		if(match_cl != -1)
		{
			for(pl = 0; pl < MAX_TOUCH_; pl++)
				lDistanceMap[pl][match_cl] = -1;

			for(cl = 0; cl < temp_coord->tTempPos.sFinger_; cl++)
				lDistanceMap[match_pl][cl] = -1;

            //if (match_cl != -1) // If the most near finger is found,
            {
				ulPrematchedDist[match_cl] = iMinDist;
				cReorderRemap[match_cl] = match_pl;
            }
		}

	} while(match_cl != -1);

#else
    //cReorderRemap 추출. Current Group Index --> Real Group Index(과거 히스토리와 맞도록).
    for (pl = 0; pl < MAX_TOUCH_; pl++)
    {
        if (temp_coord->tPastPos[0].vusR[pl] != 0)
        {
            //Increase minimum displacement according to prev-distance.
			iMinDist = (temp_coord->lPrevDist[pl])*2 + temp_coord->slScaledMoveDistThd;

            match = -1;
            // Find the previous point to match the current point
            for (cl = 0; cl < temp_coord->tTempPos.sFinger_; cl++)
            {
                if (temp_coord->tTempPos.vusR[cl]) //For unmatched fingers,
                {
                	uint16_t Check_vusR = 0;
					tXY_t UsePastPos;
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES)
					if(temp_coord->bInterpolation_On)
					{
						Check_vusR = temp_coord->tPastPos[2].vusR[pl];
						UsePastPos = temp_coord->tOrgPastPos[2].tXY[pl];
					}
					else
#endif
					{
						Check_vusR = temp_coord->tPastPos[1].vusR[pl];
						UsePastPos = temp_coord->tOrgPastPos[1].tXY[pl];
					}
					
                	if( Check_vusR )
                	{
                		if(temp_coord->ucIdMappedCnt[cl] >= 2)
                		{
                			avg_pos.x = (temp_coord->tTempPos.tXY[cl].x + temp_coord->tOrgPastPos[0].tXY[pl].x + UsePastPos.x)/3;
							avg_pos.y = (temp_coord->tTempPos.tXY[cl].y + temp_coord->tOrgPastPos[0].tXY[pl].y + UsePastPos.y)/3;
							pred_pos.x = (avg_pos.x << 1) - temp_coord->tOrgAvgPos.tXY[pl].x;
							pred_pos.y = (avg_pos.y << 1) - temp_coord->tOrgAvgPos.tXY[pl].y;
                		}
                		else
                		{
                			avg_pos.x = (temp_coord->tTempPos.tXY[cl].x + temp_coord->tOrgPastPos[0].tXY[pl].x)/2;
							avg_pos.y = (temp_coord->tTempPos.tXY[cl].y + temp_coord->tOrgPastPos[0].tXY[pl].y)/2;
                		}

						pred_pos.x = (avg_pos.x << 1) - temp_coord->tOrgAvgPos.tXY[pl].x;
						pred_pos.y = (avg_pos.y << 1) - temp_coord->tOrgAvgPos.tXY[pl].y;
                	}
                	else
                	{
                		pred_pos.x = temp_coord->tOrgPastPos[0].tXY[pl].x;
                		pred_pos.y = temp_coord->tOrgPastPos[0].tXY[pl].y;
                	}

                    iDist = algorithm_coord_calc_distance(temp_coord->tTempPos.tXY[cl], pred_pos);

                    if (iDist < iMinDist)
                    {
                        iMinDist = iDist;
                        match = cl;
                    }
                }
            }

            if (match != -1) // If the most near finger is found,
            {
                //이전 매치 된 정보가 있다면, 기존 거리가 이번 매치된 거리보다 큰 경우,
                if ((cReorderRemap[match] != -1) && ulPrematchedDist[match] > (uint32_t)iMinDist)
                {
                    ulPrematchedDist[match] = iMinDist;
                    cReorderRemap[match] = pl;
                }
                //이전 매치된 정보가 없는 경우.
                else if (cReorderRemap[match] == -1)
                {
                    ulPrematchedDist[match] = iMinDist;
                    cReorderRemap[match] = pl;
                }
            }
        }
    }
#endif

    //TODO: 빈 슬랏에 대해서 iReorderRemap을 조작해 주고, iReorderRemap에 따라서 reordering 한 루프에서 실행하도록 바꾸자.
    for (cl = 0; cl < temp_coord->tTempPos.sFinger_; cl++)
    {
        //Remap이 존재하는 경우에만,
        if (cReorderRemap[cl] != -1)
        {
            pl = cReorderRemap[cl];
            temp_coord->tPos.tXY[pl]  = temp_coord->tTempPos.tXY[cl];
            temp_coord->tPos.vusR[pl] = temp_coord->tTempPos.vusR[cl];
            temp_coord->tPos.vusS[pl] = temp_coord->tTempPos.vusS[cl];
            temp_coord->tPos.rect[pl] = temp_coord->tTempPos.rect[cl];
            temp_coord->tPos.MaxDelta[pl] = temp_coord->tTempPos.MaxDelta[cl];
#if (PalmCandidateTouchCut_EN == YES)
			temp_coord->tPos.MaxPos[pl].c = temp_coord->tTempPos.MaxPos[cl].c;
			temp_coord->tPos.MaxPos[pl].r = temp_coord->tTempPos.MaxPos[cl].r;
#endif /* (PalmCandidateTouchCut_EN == YES) */
			
			temp_coord->RealMaxDelta[pl] = temp_coord->RealMaxDelta[cl];

			temp_coord->lPrevDist[pl] = algorithm_coord_calc_distance(temp_coord->tOrgPastPos[0].tXY[pl], temp_coord->tPos.tXY[pl]);
        }
    }

    /*
     * 빈 슬랏에 새로운 finger 넣어주기.
     */
    for (cl = 0; cl < temp_coord->tTempPos.sFinger_; cl++)
    {
        // For unmatched current points
        if (cReorderRemap[cl] == -1 && temp_coord->tTempPos.vusR[cl])
        {
            for (pl = 0; pl < MAX_TOUCH_; pl++)
            {
                // For an empty and new slot
                if (temp_coord->tPastPos[0].vusR[pl] == 0 && temp_coord->tPos.vusR[pl] == 0)
                {
                    cReorderRemap[cl] = pl;
                    temp_coord->tPos.tXY[pl]      = temp_coord->tTempPos.tXY[cl];
                    temp_coord->tPos.vusR[pl]     = temp_coord->tTempPos.vusR[cl];
                    temp_coord->tPos.vusS[pl]     = temp_coord->tTempPos.vusS[cl];
                    temp_coord->tPos.rect[pl]     = temp_coord->tTempPos.rect[cl];
                    temp_coord->tPos.MaxDelta[pl]  = temp_coord->tTempPos.MaxDelta[cl];
#if (PalmCandidateTouchCut_EN == YES)
					temp_coord->tPos.MaxPos[pl].c = temp_coord->tTempPos.MaxPos[cl].c;
					temp_coord->tPos.MaxPos[pl].r = temp_coord->tTempPos.MaxPos[cl].r;
#endif /* (PalmCandidateTouchCut_EN == YES) */
					
					temp_coord->RealMaxDelta[pl] = temp_coord->RealMaxDelta[cl];

                    temp_coord->lPrevDist[pl]     = 0;
                    break;
                }
            }
        }
    }

    //Remap matrix 관리. Group matrix와 실제 좌표 그룹 인덱스와의 매칭을 위해서.
    for (cl = 0; cl < LOOSE_POSBUF_; cl++)
    {
        pl = cReorderRemap[cl];
        if (pl < MAX_TOUCH_)
        	temp_coord->cRemap[pl] = cl;
//        else
//            //maxtouch 보다 더 많은 group index에 대해서는,
//        	temp_coord->cRemap[cl] = -1;
    }

	temp_coord->tOrgPos.sFinger_ = temp_coord->tPos.sFinger_; 
    for( cl=MAX_TOUCH_; cl--; )
	{
//		temp_coord->tOrgPosHist[0].tXY[cl]  = temp_coord->tPos.tXY[cl];
//		temp_coord->tOrgPosHist[0].vusS[cl] = temp_coord->tPos.vusS[cl];
//		temp_coord->tOrgPosHist[0].vusR[cl] = temp_coord->tPos.vusR[cl];
		
		temp_coord->tOrgPos.tXY[cl]  = temp_coord->tPos.tXY[cl];
		temp_coord->tOrgPos.vusS[cl] = temp_coord->tPos.vusS[cl];
		temp_coord->tOrgPos.vusR[cl] = temp_coord->tPos.vusR[cl];
		temp_coord->tOrgPos.rect[cl] = temp_coord->tPos.rect[cl];

		if( temp_coord->tPos.vusR[cl] )
		{
			if(temp_coord->ucIdMappedCnt[cl] < COORD_HISTORY_NUM)
			{
				temp_coord->ucIdMappedCnt[cl]++;
			}

			if( temp_coord->ucIdMappedCnt[cl] == 1 )
			{
				if(mode == FULL_MODE)
				{
					pl = thisInfo->tCoord.cRemap[cl];
#if USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE
					if((thisInfo->tLabel.tTable[pl].ulStrength*100)/thisInfo->tLabel.tTable[pl].ulExtStrength < 70 && !algorithm_coord_IsEdgeArea(&thisInfo->tCoord.tPos.tXY[cl], 0))//77)
#else /* USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE */
					if((thisInfo->tLabel.tTable[pl].ulStrength*100)/thisInfo->tLabel.tTable[pl].ulExtStrength < 70)//77)
#endif /* USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE */
					{
//						thisInfo->tCoord.ucIdMappedCnt[cl] = 0;
//						thisInfo->tCoord.tPos.vusR[cl] = 0;
						thisInfo->tCoord.tPos.vusS[cl] = 0;
//						continue;
					}
				}
				temp_coord->tFirstPos.tXY[cl] = temp_coord->tPos.tXY[cl];
				temp_coord->DrawingFlag[cl] = NO;
				FirstTouchEnable[cl] = NO;
#if (VECTOR_PREDICTION_EN == YES)
				ProjectionEnable[cl] = NO;
#endif
#if (USED_DRUM_ALGO == YES)
				DrumStep[cl] = 0;
#endif /*USED_DRUM_ALGO*/
				temp_coord->iStopPos[cl] = temp_coord->tPos.tXY[cl];
			}
			
			//Phone Noise
			if(thisInfo->PhoneNoiseFrmCnt)
				temp_coord->tPos.vusS[cl] = 0;
			if(thisInfo->PhoneNoiseDebEnable){
				if(temp_coord->tPastPos[0].vusS[cl] == 0 && temp_coord->ucIdMappedCnt[cl] <= 2)
					temp_coord->tPos.vusS[cl] = 0;
			}
			
			if(thisModeConf->CoordTracking.sFirstTouchEnable1Touch > 0)
			{
				if(FirstTouchEnable[cl] == NO){
					int16_t FirstTouchThreshold = 0;

					if(thisInfo->bIsPalm)					FirstTouchThreshold = thisModeConf->CoordTracking.sFirstTouchEnable5Touch;
					else if(temp_coord->tPos.sFinger_ == 1)	FirstTouchThreshold = thisModeConf->CoordTracking.sFirstTouchEnable1Touch;
					else if(temp_coord->tPos.sFinger_ == 2)	FirstTouchThreshold = thisModeConf->CoordTracking.sFirstTouchEnable2Touch;
					else if(temp_coord->tPos.sFinger_ == 3)	FirstTouchThreshold = thisModeConf->CoordTracking.sFirstTouchEnable3Touch;
					else if(temp_coord->tPos.sFinger_ == 4)	FirstTouchThreshold = thisModeConf->CoordTracking.sFirstTouchEnable4Touch;
					else 									FirstTouchThreshold = thisModeConf->CoordTracking.sFirstTouchEnable5Touch;

					if(temp_coord->tPos.MaxDelta[cl] >= FirstTouchThreshold){
						FirstTouchEnable[cl] = YES;
						temp_coord->iStopPos[cl] = temp_coord->tPos.tXY[cl];
					}
				}

				if(FirstTouchEnable[cl] == NO)
					temp_coord->tPos.vusS[cl] = NO;
			
				if(temp_coord->tPos.vusS[cl])
				{
					if(temp_coord->cScreenDebCnt[cl] < COORD_HISTORY_NUM){
						temp_coord->cScreenDebCnt[cl]++;
//						if(thisModeConf->Coord.ucWinCertAssistance == 1){
//							if(thisInfo->tLabel.LabelSplitCnt)
//								temp_coord->tPos.vusS[cl] = 0;
//						}
					}
				}
				
				if(temp_coord->tPastPos[0].vusS[cl] == 0)
				{
					if(algorithm_coord_IsEdgeArea(&temp_coord->iStopPos[cl],0)>0){
						if(temp_coord->cScreenDebCnt[cl] <= thisModeConf->CoordTracking.ucDebCntEdge)
							temp_coord->tPos.vusS[cl] = 0;
					}
					else{
						if(temp_coord->cScreenDebCnt[cl] <= thisModeConf->CoordTracking.ucDebCntInner)
							temp_coord->tPos.vusS[cl] = 0;
						if(thisModeConf->Coord.ucWinCertAssistance == 5 && thisInfo->WinCertMode > 0){
							if(temp_coord->cScreenDebCnt[cl] <= thisModeConf->Coord.ucWinCertModeDebCnt)
								temp_coord->tPos.vusS[cl] = 0;
						}
					}
#if USED_RF_NOISE_RECOVERY_CODE
					if(thisInfo->usDebounceFrmaeCnt > 0)
					{
						temp_coord->tPos.vusS[cl] = 0;
					}
#endif /* USED_RF_NOISE_RECOVERY_CODE */
				}
			}
			else 
			{
				if( temp_coord->tPastPos[0].vusS[cl] )
				{
					int lTouchOffThd = thisModeConf->CoordTracking.lTouchOffThd;
				
					if(temp_coord->cScreenDebCnt[cl] < COORD_HISTORY_NUM)
					{
						temp_coord->cScreenDebCnt[cl]++;
					}
				
					if( thisModeConf->CoordTracking.ucMultifingerFirstTouchThDownOffset > 0 && (temp_coord->tPos.sFinger_ > 5 || thisInfo->bIsPalm == YES) ) lTouchOffThd -= ((thisModeConf->CoordTracking.ucMultifingerFirstTouchThDownOffset)>>1);
				
					if( temp_coord->tPos.vusS[cl] < lTouchOffThd )
					{
						temp_coord->tPos.vusS[cl] = 0;
						temp_coord->cScreenDebCnt[cl] = 0;
					}
				}
				else
				{
					int sFirstTouchOnMaxCellVal = thisModeConf->CoordTracking.sFirstTouchOnMaxCellVal;

					if( thisModeConf->CoordTracking.ucMultifingerFirstTouchThDownOffset > 0 && (temp_coord->tPos.sFinger_ > 5 || thisInfo->bIsPalm == YES) ) sFirstTouchOnMaxCellVal -= thisModeConf->CoordTracking.ucMultifingerFirstTouchThDownOffset;//10;
					
					if( temp_coord->tPos.vusS[cl] >= thisModeConf->CoordTracking.lSmallTouchOnThd && temp_coord->tPos.vusR[cl] > 0 )
					{
						int iDebCnt     = 0;
						int iDebCntPlus = 0;//(int)algorithm_coord_IsEdgeArea(&temp_coord->tFirstPos.tXY[cl]);
						
#if USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE
						if(thisModeConf->CoordTracking.bEdgeDebCntUp > 0 && thisInfo->bIsIdleToActive == NO)
#else /* USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE */
						if(thisModeConf->CoordTracking.bEdgeDebCntUp > 0)
#endif /* USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE */
						{
							iDebCntPlus = (int)algorithm_coord_IsEdgeArea(&temp_coord->tFirstPos.tXY[cl] , 0);
						}
						
//						if(thisModeConf->CoordTracking.ucDebCntEdge > 0 && algorithm_coord_IsEdgeArea(&temp_coord->tFirstPos.tXY[cl] , 0))
//							iDebCntPlus = thisModeConf->CoordTracking.ucDebCntEdge;
						
						if(temp_coord->cScreenDebCnt[cl] < COORD_HISTORY_NUM)
						{
							temp_coord->cScreenDebCnt[cl]++;
						}

						if( temp_coord->tPos.MaxDelta[cl] > sFirstTouchOnMaxCellVal )
						{
							if( temp_coord->tPos.vusS[cl] >= thisModeConf->CoordTracking.lLargeTouchOnThd )
							{
	//							iDebCnt = (iDebCntPlus > 0) ? iDebCntPlus : thisModeConf->CoordTracking.ucLargeTouchOnDebCnt;
								iDebCnt = iDebCntPlus + thisModeConf->CoordTracking.ucLargeTouchOnDebCnt;
							}
							else if( temp_coord->tPos.vusS[cl] >= thisModeConf->CoordTracking.lMediumTouchOnThd )
							{
	//							iDebCnt = (iDebCntPlus > 0) ? iDebCntPlus : thisModeConf->CoordTracking.ucMediumTouchOnDebCnt;
								iDebCnt = iDebCntPlus + thisModeConf->CoordTracking.ucMediumTouchOnDebCnt;
							}
							else if( temp_coord->tPos.vusS[cl] >= thisModeConf->CoordTracking.lSmallTouchOnThd )
							{
	//							iDebCnt = (iDebCntPlus > 0) ? iDebCntPlus : thisModeConf->CoordTracking.ucSmallTouchOnDebCnt;
								iDebCnt = iDebCntPlus + thisModeConf->CoordTracking.ucSmallTouchOnDebCnt;
							}

							if( temp_coord->cScreenDebCnt[cl] > iDebCnt )
							{

							}
							else
							{
								temp_coord->tPos.vusS[cl] = 0;
							}
#if (PalmCandidateTouchCut_EN == YES)
							// Do not report touch, if location of 1st touch max and 2nd touch max are diagonal and touch size is big.
//							if(thisModeConf->Palm.ucFirstPalmSizeThd && temp_coord->tPos.vusS[cl] && temp_coord->cScreenDebCnt[cl] < COORD_HISTORY_NUM)
//							{
//								if(!thisModeConf->Palm.ucPalmDrawingOn && !thisModeConf->Coord.ucWinCertAssistance)
//								{
//									int i, r_idx, c_idx, delta;
//									int second_max = -1, max2_r = -1, max2_c = -1;
//									tCell_t search_direc[8] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
//									for(i = 0; i < 9; i++)
//									{
//										r_idx = search_direc[i].r + thisInfo->tCoord.tPos.MaxPos[cl].r;
//										if(r_idx < 0) r_idx = 0;
//										else if(r_idx > ROW_MAX - 1) r_idx = ROW_MAX - 1;
//										c_idx = search_direc[i].c + thisInfo->tCoord.tPos.MaxPos[cl].c;
//										if(c_idx < 0) c_idx = 0;
//										else if(c_idx > COL_MAX - 1) c_idx = COL_MAX - 1;
//										
//										delta = HAL_READ_DELTA_IMAGE(r_idx, c_idx);
//										if(second_max < delta)
//										{
//											second_max = delta;
//											max2_c = c_idx;
//											max2_r = r_idx;
//										}
//									}
//									
//									if((second_max >= thisModeConf->Label.usSeedBase) && (temp_coord->tPos.MaxPos[cl].c != max2_c && temp_coord->tPos.MaxPos[cl].r != max2_r) &&
//										((temp_coord->tPos.rect[cl].ce - temp_coord->tPos.rect[cl].cs + 1) * (temp_coord->tPos.rect[cl].re - temp_coord->tPos.rect[cl].rs + 1) > thisModeConf->Palm.ucFirstPalmSizeThd))
//									{
//										temp_coord->tPos.vusS[cl] = 0;
//									}
//								}
//							}

							if((thisModeConf->Palm.usPalmCandiStdTh || thisModeConf->Palm.ucPalmCandiShapeMatchingTh) && temp_coord->cScreenDebCnt[cl] < COORD_HISTORY_NUM)
							{
								int r,c,i,delta,r1,c1;
								tRect_t low_level_rect = temp_coord->tPos.rect[cl];
	
								uint8_t idx,idx_1,idx_2;
								idx = HAL_READ_LABEL_IMAGE(temp_coord->tPos.MaxPos[cl].r,temp_coord->tPos.MaxPos[cl].c);
								delta = 0;
								bool_t stop_flag = 0;
								for(i = 1; i <= 4; i++)
								{
									for(r = MAX(0,temp_coord->tPos.rect[cl].rs-i); r <= MIN(ROW_MAX-1,temp_coord->tPos.rect[cl].re+i); r++)
									{
										for(c = MAX(0,temp_coord->tPos.rect[cl].cs-i); c <= MIN(COL_MAX-1,temp_coord->tPos.rect[cl].ce+i); c++)
										{
											if((r > low_level_rect.re || r < low_level_rect.rs) || (c > low_level_rect.ce || c < low_level_rect.cs))
											{
												idx_1 = HAL_READ_LABEL_IMAGE(r,c);
												if(idx != idx_1 && idx_1 > 0 && idx_1 != LABEL_BOUNDARY_MARKER && idx_1 != LABEL_CONFLICT_MARKER)
												{
													stop_flag = 1;
													break;
												}
												else if(idx_1 == LABEL_BOUNDARY_MARKER)
												{
													for(r1 = MAX(0,r-1);r1 <= MIN(ROW_MAX-1,r+1);r1++)
													{
														for(c1 = MAX(0,c-1);c1 <= MIN(COL_MAX-1,c+1);c1++)
														{
															idx_2 = HAL_READ_LABEL_IMAGE(r1,c1);
															if(idx != idx_2 && idx_2 > 0 && idx_2 != LABEL_BOUNDARY_MARKER && idx_2 != LABEL_CONFLICT_MARKER && ((r1 > low_level_rect.re || r1 < low_level_rect.rs) || (c1 > low_level_rect.ce || c1 < low_level_rect.cs)))
															{
																stop_flag = 1;
																break;
															}
														}
													}
												}
												
												if(HAL_READ_DELTA_IMAGE(r, c) > thisModeConf->Palm.ucPalmCandiDeltaTh)
													delta = 1;
											}
										}
										
										if(stop_flag == 1)
										{
											break;
										}
									}
										
									if(stop_flag == 0 && delta == 0)stop_flag = 1;
									
									if(stop_flag == 0)
									{
										for(r = MAX(0,temp_coord->tPos.rect[cl].rs-i); r <= MIN(ROW_MAX-1,temp_coord->tPos.rect[cl].re+i); r++)
											for(c = MAX(0,temp_coord->tPos.rect[cl].cs-i); c <= MIN(COL_MAX-1,temp_coord->tPos.rect[cl].ce+i); c++)
										{
											idx_1 = HAL_READ_LABEL_IMAGE(r,c);
											if((0 == idx_1 || idx_1 == LABEL_BOUNDARY_MARKER || idx_1 == LABEL_CONFLICT_MARKER)&& ((r > low_level_rect.re || r < low_level_rect.rs) || (c > low_level_rect.ce || c < low_level_rect.cs)))
											{
												delta = HAL_READ_DELTA_IMAGE(r, c);
												if(delta > thisModeConf->Palm.ucPalmCandiDeltaTh)
												{
													if(low_level_rect.re < r)low_level_rect.re = r;
													if(low_level_rect.rs > r)low_level_rect.rs = r;
													if(low_level_rect.ce < c)low_level_rect.ce = c;
													if(low_level_rect.cs > c)low_level_rect.cs = c;
												}
											}
										}
									}
									else 
									{
										break;
									}
								}
								
								if(low_level_rect.re > low_level_rect.rs+14)low_level_rect.re = low_level_rect.rs+14;
								if(low_level_rect.ce > low_level_rect.cs+14)low_level_rect.ce = low_level_rect.cs+14;
						
//								for(r = MAX(0,low_level_rect.rs-2); r <= MIN(ROW_MAX-1,low_level_rect.re+2); r++)
//									for(c = MAX(0,low_level_rect.cs-2); c <= MIN(COL_MAX-1,low_level_rect.ce+2); c++)
//								{
//									delta = MAX(0,HAL_READ_DELTA_IMAGE(r, c));
//									HAL_WRITE_HOPP2_BASELINE_IMAGE(r-MAX(0,low_level_rect.rs-0),c-MAX(0,low_level_rect.cs-0) + ((temp_coord->cScreenDebCnt[cl]-1)*20),delta);
//									HAL_WRITE_HOPP2_BASELINE_IMAGE(r-MAX(0,low_level_rect.rs-0)+25,c-MAX(0,low_level_rect.cs-0) + ((temp_coord->cScreenDebCnt[cl]-1)*20),HAL_READ_LABEL_IMAGE(r,c));
//								}
								
								uint16_t shape_array_tmp[15][15];
								memset(shape_array_tmp,0,sizeof(shape_array_tmp));
								int cnt_ = 0;
								int sum_ = 0;
								for(r = low_level_rect.rs; r <= low_level_rect.re; r++)
									for(c = low_level_rect.cs; c <= low_level_rect.ce; c++)
								{
									idx_1 = HAL_READ_LABEL_IMAGE(r,c);
									if(idx == idx_1 ||  0 == idx_1 || idx_1 == LABEL_BOUNDARY_MARKER || idx_1 == LABEL_CONFLICT_MARKER)
									{
										delta = MAX(0,HAL_READ_DELTA_IMAGE(r, c));									
										delta = delta*100/temp_coord->tPos.MaxDelta[cl];
										shape_array_tmp[r-low_level_rect.rs][c-low_level_rect.cs] = delta;
//										HAL_WRITE_HOPP2_BASELINE_IMAGE(r-low_level_rect.rs+13,c-low_level_rect.cs + ((temp_coord->cScreenDebCnt[cl]-1)*20),shape_array_tmp[r-low_level_rect.rs][c-low_level_rect.cs]);
										sum_ += (delta);
										cnt_++;
									}
								}			
								
								sum_ /= cnt_;
								uint64_t std = 0;
								for(r = low_level_rect.rs; r <= low_level_rect.re; r++)
									for(c = low_level_rect.cs; c <= low_level_rect.ce; c++)
								{
									delta = shape_array_tmp[r-low_level_rect.rs][c-low_level_rect.cs];							
									std += (((delta) - sum_) * ((delta) - sum_));
								}
								std /= cnt_;
								int size = (low_level_rect.re - low_level_rect.rs + 1) * (low_level_rect.ce - low_level_rect.cs + 1);
//								dbg_coord[2+temp_coord->cScreenDebCnt[cl]-1] = std;
//								dbg_coord[8+temp_coord->cScreenDebCnt[cl]-1] = std*10/size;
//								
//								HAL_WRITE_HOPP2_BASELINE_IMAGE(10,15 + ((temp_coord->cScreenDebCnt[cl]-1)*20),dbg_coord[2+temp_coord->cScreenDebCnt[cl]-1]);
//								HAL_WRITE_HOPP2_BASELINE_IMAGE(10,16 + ((temp_coord->cScreenDebCnt[cl]-1)*20),size);
//								HAL_WRITE_HOPP2_BASELINE_IMAGE(10,17 + ((temp_coord->cScreenDebCnt[cl]-1)*20),dbg_coord[8+temp_coord->cScreenDebCnt[cl]-1]);
								
								if(std*10/size < thisModeConf->Palm.usPalmCandiStdTh)temp_coord->tPos.vusS[cl] = 0;
										
								if(temp_coord->tPos.vusS[cl] > 0 && thisModeConf->Palm.ucPalmCandiShapeMatchingTh)
								{
//									int tmp_re = low_level_rect.re;
//									int tmp_ce = low_level_rect.ce;
									low_level_rect.re = MIN(ROW_MAX-1,low_level_rect.rs+14);
									low_level_rect.ce = MIN(COL_MAX-1,low_level_rect.cs+14);
								
									for(r = low_level_rect.rs; r <= low_level_rect.re; r++)
										for(c = low_level_rect.cs; c <= low_level_rect.ce; c++)
									{
										idx_1 = HAL_READ_LABEL_IMAGE(r,c);
										if(idx == idx_1 ||  0 == idx_1 || idx_1 == LABEL_BOUNDARY_MARKER || idx_1 == LABEL_CONFLICT_MARKER)
										{
											delta = MAX(0,HAL_READ_DELTA_IMAGE(r, c));								
											delta = delta*100/temp_coord->tPos.MaxDelta[cl];
											shape_array_tmp[r-low_level_rect.rs][c-low_level_rect.cs] = delta;
										}
										else shape_array_tmp[r-low_level_rect.rs][c-low_level_rect.cs] = 0;
										
										//HAL_WRITE_HOPP2_BASELINE_IMAGE(r-low_level_rect.rs+25,c-low_level_rect.cs + ((temp_coord->cScreenDebCnt[cl]-1)*20),shape_array_tmp[r-low_level_rect.rs][c-low_level_rect.cs]);
									}
									
									sum_ = 0;
									for(r = low_level_rect.rs; r <= low_level_rect.re; r++)for(c = low_level_rect.cs; c <= low_level_rect.ce; c++)
									{			
										sum_ += (ABS((int)shape_array_tmp[r-low_level_rect.rs][c-low_level_rect.cs] - (int)shape_array_table[r-low_level_rect.rs][c-low_level_rect.cs]));
									}
									
									sum_ = sum_*10/((low_level_rect.re-low_level_rect.rs+1)*(low_level_rect.ce-low_level_rect.cs+1));
//									dbg_coord[14+temp_coord->cScreenDebCnt[cl]-1] = sum_;
//									HAL_WRITE_HOPP2_BASELINE_IMAGE(10,18 + ((temp_coord->cScreenDebCnt[cl]-1)*20),dbg_coord[14+temp_coord->cScreenDebCnt[cl]-1]);
									
									if(sum_ > thisModeConf->Palm.ucPalmCandiShapeMatchingTh && thisModeConf->Palm.ucPalmCandiShapeMatchingLearning == 0) 
									{
										temp_coord->tPos.vusS[cl] = 0;
//										dbg_coord[20]++;
									}
										
									if(thisModeConf->Palm.ucPalmCandiShapeMatchingLearning == 1)
									{
										if(usPalmCandiShapeMatchingLearningCnt==0)memset(shape_array_table,0,sizeof(shape_array_table));
										for(r = 0; r < 15; r++)for(c = 0; c < 15; c++)
										{
											shape_array_table[r][c] = (shape_array_table[r][c] + shape_array_tmp[r][c]);
//											HAL_WRITE_HOPP1_BASELINE_IMAGE(r,c,shape_array_table[r][c]);
										}
										usPalmCandiShapeMatchingLearningCnt++;
									}
									else if(thisModeConf->Palm.ucPalmCandiShapeMatchingLearning == 2 && usPalmCandiShapeMatchingLearningCnt > 0)
									{
										for(r = 0; r < 15; r++)for(c = 0; c < 15; c++)
										{
											shape_array_table[r][c] = shape_array_table[r][c]/usPalmCandiShapeMatchingLearningCnt;	
//											HAL_WRITE_HOPP1_BASELINE_IMAGE(r,c,shape_array_table[r][c]);
										}			
										usPalmCandiShapeMatchingLearningCnt = 0;								
									}	
								}									
							}
#endif /* (PalmCandidateTouchCut_EN == YES) */							
						}
						else
						{
							temp_coord->tPos.vusS[cl] = 0;
							temp_coord->cScreenDebCnt[cl] = 0;
						}
					}
					else
					{
						temp_coord->tPos.vusS[cl] = 0;
						temp_coord->cScreenDebCnt[cl] = 0;
					}
				}
			}
			
			temp_coord->cIsbefor[cl] = 0;
		}
		else
		{
//			if(temp_coord->tPastPos[0].vusR[cl] > 0 && mode == LOCAL_MODE)
//			{
//				if(((temp_coord->cIsbefor[cl] < 1 /*&& g_RetVal == PARTIAL_PEN_COORD1*/) || (temp_coord->cIsbefor[cl] < 4 && temp_coord->cIsbefor[cl] > 0))&& temp_coord->ucIdMappedCnt[cl] > 3)
////				if(temp_coord->cIsbefor[cl] < 1 && temp_coord->ucIdMappedCnt[cl] > 3)
//				{
//					thisInfo->bLocal_sensing = YES;

//					temp_coord->tPos.vusR[cl] = temp_coord->tPastPos[0].vusR[cl];
//					temp_coord->tPos.vusS[cl] = temp_coord->tPastPos[0].vusS[cl];
//					temp_coord->tPos.tXY[cl] = temp_coord->tOrgPastPos[0].tXY[cl];
//					temp_coord->cIsbefor[cl]++;
//					
//					temp_coord->tOrgPosHist[0].tXY[cl]  = temp_coord->tPos.tXY[cl];
//					temp_coord->tOrgPosHist[0].vusS[cl] = temp_coord->tPos.vusS[cl];
//					temp_coord->tOrgPosHist[0].vusR[cl] = temp_coord->tPos.vusR[cl];
//					
//					temp_coord->tOrgPos.tXY[cl]  = temp_coord->tPos.tXY[cl];
//					temp_coord->tOrgPos.vusS[cl] = temp_coord->tPos.vusS[cl];
//					temp_coord->tOrgPos.vusR[cl] = temp_coord->tPos.vusR[cl];
//				}
//				else
//				{
//					temp_coord->ucIdMappedCnt[cl] = 0;
//					temp_coord->cScreenDebCnt[cl] = 0;
//					temp_coord->cIsbefor[cl] = 0;
//				}
//			}
//			else
			{
				temp_coord->ucIdMappedCnt[cl] = 0;
				temp_coord->cScreenDebCnt[cl] = 0;
				temp_coord->cIsbefor[cl] = 0;
			}
		}
	}
}

tXY_t meanInterpolate(tXY_t *p, int start, int num)
{
	int i;
	int sum_x, sum_y;
	tXY_t result;

	sum_x = sum_y = 0;

	for( i=start; i<start+num; i++)
	{
		sum_x += p[i].x;
		sum_y += p[i].y;
	}

	result.x = sum_x / num;
	result.y = sum_y / num;

	return result;
}

void algorithm_coord_smoothing_pos(int mode)
{
	int i;
	int prev_curr_dist;
//	tXY_t curr_pos;  // NOTE : not used
//	tXY_t prev_pos;
//	tXY_t avg_pos, pred_pos;

	tCoordInfo_t 	*temp_coord;

	temp_coord = &thisInfo->tCoord;

	for( i=MAX_TOUCH_; i--; )
	{
		if( temp_coord->tPos.vusR[i] > 0 )
		{
			tXY_t coord_array[7];

			if(thisModeConf->Coord.bFingerMeanSmoothing)
			{
#if (SMOOTH_PASTORG_INTER_EN == YES)
				if(thisModeConf->Coord.ucSmoothPastOrgInter > 0 && thisModeConf->Coord.ucSmoothPastOrgInter <= 4 && temp_coord->tOrgPastPos[0].vusS[i]>0 && temp_coord->tOrgPastPos[1].vusS[i]>0 && temp_coord->tOrgPastPos[2].vusS[i]>0 && temp_coord->cScreenDebCnt[i] >= 5)
				{
					coord_array[0] = temp_coord->tOrgPos.tXY[i];
					coord_array[1] = temp_coord->tPastPos[0].tXY[i];
					coord_array[2] = temp_coord->tPastPos[1].tXY[i];
					coord_array[3] = temp_coord->tPastPos[2].tXY[i];
					coord_array[4] = temp_coord->tOrgPastPos[0].tXY[i];	
					coord_array[5] = temp_coord->tOrgPastPos[1].tXY[i];	
					coord_array[6] = temp_coord->tOrgPastPos[2].tXY[i];	
				
					temp_coord->tPos.tXY[i] = meanInterpolate(coord_array, 0,thisModeConf->Coord.ucSmoothPastOrgInter+3);
				}
				else if( temp_coord->tPastPos[2].vusS[i] > 0 && temp_coord->tPastPos[1].vusS[i] > 0 && temp_coord->tPastPos[0].vusS[i] > 0 && temp_coord->tPos.vusS[i] > 0 )
				{					
					coord_array[0].x = (temp_coord->tOrgPastPos[2].tXY[i].x + temp_coord->tOrgPastPos[1].tXY[i].x) / 2;
					coord_array[1].x = (temp_coord->tOrgPastPos[2].tXY[i].x + temp_coord->tOrgPastPos[1].tXY[i].x + temp_coord->tOrgPastPos[0].tXY[i].x) / 3;
					coord_array[2].x = (temp_coord->tOrgPastPos[2].tXY[i].x + temp_coord->tOrgPastPos[1].tXY[i].x + temp_coord->tOrgPastPos[0].tXY[i].x + temp_coord->tOrgPos.tXY[i].x) / 4;
					coord_array[3].x = (temp_coord->tOrgPastPos[1].tXY[i].x + temp_coord->tOrgPastPos[0].tXY[i].x + temp_coord->tOrgPos.tXY[i].x) / 3;
					coord_array[4].x = (temp_coord->tOrgPastPos[0].tXY[i].x + temp_coord->tOrgPos.tXY[i].x) / 2;

					coord_array[0].y = (temp_coord->tOrgPastPos[2].tXY[i].y + temp_coord->tOrgPastPos[1].tXY[i].y) / 2;
					coord_array[1].y = (temp_coord->tOrgPastPos[2].tXY[i].y + temp_coord->tOrgPastPos[1].tXY[i].y + temp_coord->tOrgPastPos[0].tXY[i].y) / 3;
					coord_array[2].y = (temp_coord->tOrgPastPos[2].tXY[i].y + temp_coord->tOrgPastPos[1].tXY[i].y + temp_coord->tOrgPastPos[0].tXY[i].y + temp_coord->tOrgPos.tXY[i].y) / 4;
					coord_array[3].y = (temp_coord->tOrgPastPos[1].tXY[i].y + temp_coord->tOrgPastPos[0].tXY[i].y + temp_coord->tOrgPos.tXY[i].y) / 3;
					coord_array[4].y = (temp_coord->tOrgPastPos[0].tXY[i].y + temp_coord->tOrgPos.tXY[i].y) / 2 ;

					temp_coord->tPos.tXY[i] = meanInterpolate(coord_array, 0,5);	
				}
				else if(temp_coord->tPastPos[1].vusS[i] > 0 && temp_coord->tPastPos[0].vusS[i] > 0 && temp_coord->tPos.vusS[i] > 0)
				{
					temp_coord->tPos.tXY[i].x = (temp_coord->tOrgPastPos[1].tXY[i].x + temp_coord->tOrgPastPos[0].tXY[i].x + temp_coord->tOrgPos.tXY[i].x)/3;
					temp_coord->tPos.tXY[i].y = (temp_coord->tOrgPastPos[1].tXY[i].y + temp_coord->tOrgPastPos[0].tXY[i].y + temp_coord->tOrgPos.tXY[i].y)/3;
				}
				else
#endif					
				if(temp_coord->tPastPos[0].vusS[i] > 0 && temp_coord->tPos.vusS[i] > 0)
				{
					temp_coord->tPos.tXY[i].x = (temp_coord->tOrgPastPos[0].tXY[i].x + temp_coord->tOrgPos.tXY[i].x)/2;
					temp_coord->tPos.tXY[i].y = (temp_coord->tOrgPastPos[0].tXY[i].y + temp_coord->tOrgPos.tXY[i].y)/2;
				}
//				temp_coord->tPos.tXY[i] = temp_coord->tOrgPos.tXY[i];

			}

			if( temp_coord->tPastPos[0].vusS[i] > 0 )
			{
				if(thisModeConf->Coord.cDisSmoothOffset != 0)
				{
					prev_curr_dist = algorithm_coord_calc_distance(temp_coord->tPastPos[0].tXY[i], temp_coord->tPos.tXY[i]);

					prev_curr_dist += thisModeConf->Coord.cDisSmoothOffset;
					
					if(prev_curr_dist < 10)
						prev_curr_dist = 10;
					
					if(prev_curr_dist > _BV(thisModeConf->Coord.lMoveSmoothingLevel))
						prev_curr_dist = _BV(thisModeConf->Coord.lMoveSmoothingLevel);
					
#if (VECTOR_PREDICTION_EN == YES)
					if(thisModeConf->Coord.ucVectorPredictionCoef > 0)
					{
						uint16_t dist_th1 = 0, dist_th2 = 0, dist = 0;
						tXY_t ProjectionVector, PrevVector, CurrVector, PredPos;
						int InnerProduct,PrevScalar,CurrScalar,CosSeta;
						tXY_t OriginPoint,VectorA,VectorB;
						tXY_t tPastPos = {0, 0};
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
						if(temp_coord->bInterpolation_On)
						{
							tPastPos.x = temp_coord->tPastPos[4].tXY[i].x;
							tPastPos.y = temp_coord->tPastPos[4].tXY[i].y;
						}
						else
#endif
						{
							tPastPos.x = temp_coord->tPastPos[2].tXY[i].x;
							tPastPos.y = temp_coord->tPastPos[2].tXY[i].y;
						}

						ProjectionVector.x = 0, ProjectionVector.y = 0;
						PredPos = temp_coord->tPastPos[0].tXY[i];
						
						//Prediction based on projection
						if(
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
							(temp_coord->bInterpolation_On && temp_coord->tPastPos[4].vusR[i] > 0) || (!temp_coord->bInterpolation_On && temp_coord->tPastPos[2].vusR[i] > 0)
#else
							(temp_coord->tPastPos[2].vusR[i] > 0)
#endif
						)
						{
							if(ProjectionEnable[i] == NO && algorithm_coord_calc_distance(temp_coord->tPos.tXY[i],tPastPos) > thisModeConf->Coord.usDistThdStationaryToMoving
								&& algorithm_coord_calc_distance(temp_coord->iStopPos[i],temp_coord->tPastPos[0].tXY[i]) > (thisModeConf->Coord.usDistThdStationaryToMoving<<1))
								ProjectionEnable[i] = YES;
							else if(ProjectionEnable[i] == YES && algorithm_coord_calc_distance(temp_coord->tPos.tXY[i],tPastPos) < thisModeConf->Coord.usDistThdMovingToStationary)
								ProjectionEnable[i] = NO;
						}
//						if(temp_coord->tPastPos[4].vusR[i] > 0 && algorithm_coord_calc_distance(temp_coord->tPos.tXY[i],temp_coord->tPastPos[4].tXY[i]) > thisModeConf->Coord.usDistThdStationaryToMoving)
//							ProjectionEnable[i] = YES;
//						else
//							ProjectionEnable[i] = NO;
//						if( temp_coord->tPastPos[4].vusS[i] > 0 && temp_coord->DrawingFlag[i] )	//&& prev_curr_dist < (2<<POS_BOOST_SHIFT_))
						if(ProjectionEnable[i] == YES)
						{
							uint8_t Coef;
//							tXY_t AccelPred;
//							PrevVector.x = (temp_coord->tPastPos[0].tXY[i].x - temp_coord->tPastPos[2].tXY[i].x)*3;
//							PrevVector.y = (temp_coord->tPastPos[0].tXY[i].y - temp_coord->tPastPos[2].tXY[i].y)*3;
							
							PrevVector.x = temp_coord->tPastPos[0].tXY[i].x - tPastPos.x;
							PrevVector.y = temp_coord->tPastPos[0].tXY[i].y - tPastPos.y;
							CurrVector.x = temp_coord->tPos.tXY[i].x - tPastPos.x;
							CurrVector.y = temp_coord->tPos.tXY[i].y - tPastPos.y;

							ProjectionVector.x = (int)(PrevVector.x * (int64_t)(PrevVector.x*CurrVector.x + PrevVector.y*CurrVector.y) / (PrevVector.x*PrevVector.x+PrevVector.y*PrevVector.y));
							ProjectionVector.y = (int)(PrevVector.y * (int64_t)(PrevVector.x*CurrVector.x + PrevVector.y*CurrVector.y) / (PrevVector.x*PrevVector.x+PrevVector.y*PrevVector.y));
						
							PredPos.x = tPastPos.x + ProjectionVector.x;
							PredPos.y = tPastPos.y + ProjectionVector.y;
							

							//////calculate inner product
//							OriginPoint.x = OriginPoint.y = 0;
//							VectorA.x = PredPos.x - temp_coord->tPastPos[0].tXY[i].x;
//							VectorA.y = PredPos.y - temp_coord->tPastPos[0].tXY[i].y;
//							VectorB.x = temp_coord->tPos.tXY[i].x - temp_coord->tPastPos[0].tXY[i].x;
//							VectorB.y = temp_coord->tPos.tXY[i].y - temp_coord->tPastPos[0].tXY[i].y;
//							
//							InnerProduct = ((VectorA.x * VectorB.x + VectorA.y * VectorB.y)<<7);
//							CosSeta = InnerProduct / (algorithm_coord_calc_distance(OriginPoint,VectorA) * algorithm_coord_calc_distance(OriginPoint,VectorB));

							dist = algorithm_coord_calc_distance(temp_coord->tPos.tXY[i],PredPos);

							if(thisModeConf->Coord.ucWinCertAssistance == 5 &&  thisInfo->DrawingDirection > 0)
								Coef = thisModeConf->Coord.ucWinCertModeVectorPredictionCoef;
							else
								Coef = thisModeConf->Coord.ucVectorPredictionCoef;
							if(dist < 10)	dist = 0;
							else if(dist > Coef)	dist = Coef;
							
							
							
							//TEST_CODE
//							if(thisInfo->DrawingDirection ){
//								temp_coord->tPos.tXY[i] = PredPos;
//							}
//							else
							{
								temp_coord->tPos.tXY[i].x = ((Coef - dist) * PredPos.x + dist * temp_coord->tPos.tXY[i].x + (Coef>>1)) / Coef;
								temp_coord->tPos.tXY[i].y = ((Coef - dist) * PredPos.y + dist * temp_coord->tPos.tXY[i].y + (Coef>>1)) / Coef;			
//							temp_coord->tPos.tXY[i].x = ((PredPos.x + temp_coord->tPos.tXY[i].x + 1)>>1);
//							temp_coord->tPos.tXY[i].y = ((PredPos.y + temp_coord->tPos.tXY[i].y + 1)>>1);
							}
							
							
							if(temp_coord->DrawingFlag[i] && algorithm_coord_IsEdgeArea(&temp_coord->tPos.tXY[i], 0)){
								temp_coord->tPos.tXY[i].x = ((PredPos.x + temp_coord->tPos.tXY[i].x + 1)>>1);
								temp_coord->tPos.tXY[i].y = ((PredPos.y + temp_coord->tPos.tXY[i].y + 1)>>1);
							}

						}
//						if(prev_curr_dist > (1<<POS_BOOST_SHIFT_)){
//							temp_coord->tPos.tXY[i].x = ((temp_coord->tPos.tXY[i].x + temp_coord->tOrgPos.tXY[i].x)>>1);
//							temp_coord->tPos.tXY[i].y = ((temp_coord->tPos.tXY[i].y + temp_coord->tOrgPos.tXY[i].y)>>1);
//						}
						//Win11 panning latency
//						if(temp_coord->tPos.sFinger_ == 1 && prev_curr_dist > (1<<(POS_BOOST_SHIFT_-1)))
//						{
//							PrevVector.x = temp_coord->tPos.tXY[i].x - temp_coord->tPastPos[0].tXY[i].x;
//							PrevVector.y = temp_coord->tPos.tXY[i].y - temp_coord->tPastPos[0].tXY[i].y;
//							CurrVector.x = temp_coord->tOrgPos.tXY[i].x - temp_coord->tPastPos[0].tXY[i].x;
//							CurrVector.y = temp_coord->tOrgPos.tXY[i].y - temp_coord->tPastPos[0].tXY[i].y;
//							
//							ProjectionVector.x = (int)(PrevVector.x * (int64_t)(PrevVector.x*CurrVector.x + PrevVector.y*CurrVector.y) / (PrevVector.x*PrevVector.x+PrevVector.y*PrevVector.y));
//							ProjectionVector.y = (int)(PrevVector.y * (int64_t)(PrevVector.x*CurrVector.x + PrevVector.y*CurrVector.y) / (PrevVector.x*PrevVector.x+PrevVector.y*PrevVector.y));
//						
//							temp_coord->tPos.tXY[i].x = temp_coord->tPastPos[0].tXY[i].x + ProjectionVector.x;
//							temp_coord->tPos.tXY[i].y = temp_coord->tPastPos[0].tXY[i].y + ProjectionVector.y;
//							
//						}
					}
#endif

					temp_coord->tPos.tXY[i].x = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * temp_coord->tPastPos[0].tXY[i].x + prev_curr_dist * temp_coord->tPos.tXY[i].x + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
					temp_coord->tPos.tXY[i].y = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * temp_coord->tPastPos[0].tXY[i].y + prev_curr_dist * temp_coord->tPos.tXY[i].y + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
				
					if(thisModeConf->Coord.ucWinCertAssistance == 5 )
					{
						if(temp_coord->tPos.sFinger_ == 1 && temp_coord->tPastPos[2].vusS[i])
						{
							int InnerProduct,S1,S2;
							tXY_t ProjectionVector, PrevVector, CurrVector, PredPos, P[3],V1,V2;

							P[0] = temp_coord->tPos.tXY[i];
							P[1] = temp_coord->tPastPos[0].tXY[i];
							P[2] = temp_coord->tPastPos[2].tXY[i];
							
							V1.x = P[0].x - P[1].x;
							V1.y = P[0].y - P[1].y;
							V2.x = P[1].x - P[2].x;
							V2.y = P[1].y - P[2].y;
							S1 = algorithm_coord_calc_distance(P[0], P[1]);
							S2 = algorithm_coord_calc_distance(P[1], P[2]);
							InnerProduct = ((V1.x*V2.x + V1.y*V2.y)<<POS_BOOST_SHIFT_) / (S1*S2);
							
							S1 = algorithm_coord_calc_distance(temp_coord->tOrgPos.tXY[i],temp_coord->tOrgPastPos[0].tXY[i]);
							
							if(30 < S1 && S1 < 900 && abs(InnerProduct - (1<<POS_BOOST_SHIFT_)) < 80)
							{
								if(PanningTestModeCnt < PANNING_TEST_MODE_CNT_MAX)
									PanningTestModeCnt++;
							}
							else
								PanningTestModeCnt = 0;
							if(PanningTestModeCnt >= PANNING_TEST_MODE_CNT_MAX && PanningTestModeCnt < (PANNING_TEST_MODE_CNT_MAX<<1)){
								if(algorithm_coord_calc_distance(temp_coord->tPos.tXY[i],temp_coord->iStopPos[i]) < (1<<POS_BOOST_SHIFT_))
									PanningTestModeCnt++;
							}
							if(PanningTestModeCnt > PANNING_TEST_MODE_CNT_MAX+3)
							{
								temp_coord->tPos.tXY[i] = temp_coord->tOrgPos.tXY[i];
//								temp_coord->tPos.tXY[i].x =( (temp_coord->tPos.tXY[i].x + temp_coord->tOrgPos.tXY[i].x + 1)>>1 );
//								temp_coord->tPos.tXY[i].y =( (temp_coord->tPos.tXY[i].y + temp_coord->tOrgPos.tXY[i].y + 1)>>1 );
							}
						}
					}
					
					if(thisModeConf->Coord.ucWinCertAssistance == 5 && temp_coord->tTempPos.sFinger_ == 5)
					{
						if(thisInfo->DrawingDirection == 2){
							temp_coord->tPos.tXY[i].y = (((temp_coord->tPastPos[0].tXY[i].y * 7) + temp_coord->tPos.tXY[i].y + 4)>>3);
						}
						else if(thisInfo->DrawingDirection == 3){
							temp_coord->tPos.tXY[i].x = (((temp_coord->tPastPos[0].tXY[i].x * 7) + temp_coord->tPos.tXY[i].x + 4)>>3);
							temp_coord->tPos.tXY[i].y = (((temp_coord->tPastPos[0].tXY[i].y * 7) + temp_coord->tPos.tXY[i].y + 4)>>3);
						}
					}
					
					if(thisModeConf->Coord.ucWinCertAssistance == 1 && temp_coord->tPos.sFinger_ <= 2)
					{
						int dist_th1 = 0;
						if(algorithm_coord_IsEdgeArea(&temp_coord->tPastPos[0].tXY[i],0)){
							dist_th1 = (1<<(POS_BOOST_SHIFT_));
						}
						else{
							dist_th1 = (1<<(POS_BOOST_SHIFT_-2));
						}
						
						if(prev_curr_dist > dist_th1){
							temp_coord->tPos.tXY[i].x = ((temp_coord->tPos.tXY[i].x + temp_coord->tOrgPos.tXY[i].x*3)>>2);
							temp_coord->tPos.tXY[i].y = ((temp_coord->tPos.tXY[i].y + temp_coord->tOrgPos.tXY[i].y*3)>>2);
						}
						
						if( temp_coord->tPastPos[2].vusS[i] > 0 && temp_coord->RealMaxDelta[i] > 0)
						{
							temp_coord->tPos.tXY[i].x = ((temp_coord->tPos.tXY[i].x*3 + ((temp_coord->tPastPos[0].tXY[i].x<<1) - temp_coord->tPastPos[2].tXY[i].x))>>2);
							temp_coord->tPos.tXY[i].y = ((temp_coord->tPos.tXY[i].y*3 + ((temp_coord->tPastPos[0].tXY[i].y<<1) - temp_coord->tPastPos[2].tXY[i].y))>>2);
						}
					}
				}
			}
			else{
				temp_coord->bIsMoving[i] = NO;
			}
			
			//Remove point touch jitter
			if(temp_coord->tPos.vusS[i] > 0)
			{
				int dist_th = 0;
				if(thisModeConf->Coord.usFirstDrawingThd > 0 && temp_coord->tPos.vusR[i] > thisModeConf->Coord.ucFirstDrawingCellCnt)
				{
#if (USED_DRUM_ALGO == YES)
					if(thisModeConf->Coord.usDrumTestDist != 0)
					{
						if(DrumStep[i] == 0)
						{
							if(temp_coord->tOrgPos.vusR[i] > 0 && temp_coord->tOrgPastPos[0].vusR[i] > 0)
							{
								if(thisModeConf->Coord.usDrumTestDist < algorithm_coord_calc_distance(temp_coord->tOrgPos.tXY[i],temp_coord->tOrgPastPos[0].tXY[i]))
								{
									DrumStep[i] = 1;
									temp_coord->tPos.tXY[i] = temp_coord->tPastPos[0].tXY[i];
//								VirtualBufferEnable[i] = YES;
//								VirtualTouch[i] = temp_coord->tOrgPos.tXY[i];
//								temp_coord->tOrgPos.tXY[i] = temp_coord->tOrgPastPos[0].tXY[i];
								}
								else if((thisModeConf->Coord.usDrumTestDist<<3) < algorithm_coord_calc_distance(temp_coord->tPos.tXY[i],temp_coord->iStopPos[i]))
								{
									DrumStep[i] = 2;
								}
							}
						}
					}
#endif /*USED_DRUM_ALGO*/

					if(temp_coord->tPastPos[0].vusS[i] > 0)
					{
						int dist;
						if(temp_coord->DrawingFlag[i] == NO)
						{
							if(thisModeConf->Coord.ucWinCertAssistance == 5 && thisInfo->DrawingDirection > 0)
							{
								if(thisInfo->DrawingVector.x == 0 && thisInfo->DrawingVector.y == 0)
								{
									if(thisInfo->DrawingDirection == 1){
										dist =  ((abs(temp_coord->iStopPos[i].y - temp_coord->tOrgPos.tXY[i].y))<<2);
										dist += ((abs(temp_coord->iStopPos[i].x - temp_coord->tOrgPos.tXY[i].x))>>4);
									}
									else if(thisInfo->DrawingDirection == 2){
										dist =  ((abs(temp_coord->iStopPos[i].x - temp_coord->tOrgPos.tXY[i].x))<<2);
										dist += ((abs(temp_coord->iStopPos[i].y - temp_coord->tOrgPos.tXY[i].y))>>4);
									}
									else
										dist = algorithm_coord_calc_distance(temp_coord->iStopPos[i],temp_coord->tOrgPos.tXY[i]);
								}
								else
								{
									tXY_t PrevVector, CurrVector,ZeroPoint;
									int InnerProduct;
								
									ZeroPoint.x = 0, ZeroPoint.y = 0;
									PrevVector = thisInfo->DrawingVector;
									CurrVector.x = temp_coord->tOrgPos.tXY[i].x - temp_coord->iStopPos[i].x;
									CurrVector.y = temp_coord->tOrgPos.tXY[i].y - temp_coord->iStopPos[i].y;
									
									dist = (PrevVector.x*CurrVector.x + PrevVector.y*CurrVector.y) / algorithm_coord_calc_distance(ZeroPoint,PrevVector);
									if(dist > 0)
										dist <<= 2;
									else
										dist = -dist;
								}
							}
							else
								dist = algorithm_coord_calc_distance(temp_coord->iStopPos[i],temp_coord->tOrgPos.tXY[i]);
							
							
	//						if(algorithm_coord_IsEdgeArea(&temp_coord->iStopPos[i])>0)
	//							dist_th = (1<<POS_BOOST_SHIFT_);
	//						else
								dist_th = thisModeConf->Coord.usFirstDrawingThd;
							
							if(algorithm_coord_IsEdgeArea(&temp_coord->tPastPos[0].tXY[i],0)>0)
								dist_th <<= 1;
	//						dist_th += AddDistTh;
							
							if( dist < dist_th )
							{
								temp_coord->tPos.tXY[i] =temp_coord->iStopPos[i];
	//							temp_coord->tPos.tXY[i].x = ((temp_coord->tFirstPos.tXY[i].x*7 + temp_coord->tPos.tXY[i].x)>>3);
	//							temp_coord->tPos.tXY[i].y = ((temp_coord->tFirstPos.tXY[i].y*7 + temp_coord->tPos.tXY[i].y)>>3);
							}
							else{
								temp_coord->DrawingFlag[i] = 5;
								temp_coord->tPos.tXY[i].x = ((temp_coord->tPastPos[0].tXY[i].x + temp_coord->tPos.tXY[i].x)>>1);
								temp_coord->tPos.tXY[i].y = ((temp_coord->tPastPos[0].tXY[i].y + temp_coord->tPos.tXY[i].y)>>1);
							}
						}
						else if(thisModeConf->Coord.ucWinCertAssistance == 5 && temp_coord->tPastPos[4].vusS[i] > 0 && thisInfo->DrawingDirection > 0)
						{
							dist_th = (thisModeConf->Coord.usFirstDrawingThd>>2);
							if( algorithm_coord_calc_distance(temp_coord->tPastPos[4].tXY[i],temp_coord->tPos.tXY[i]) < dist_th )
								temp_coord->DrawingFlag[i]--;
							else{	//Save test mode vector
								tXY_t ZeroPoint;
								ZeroPoint.x = 0, ZeroPoint.y = 0;
								if( algorithm_coord_calc_distance(ZeroPoint,thisInfo->DrawingVector) < 
									algorithm_coord_calc_distance(temp_coord->tPastPos[4].tXY[i],temp_coord->tPos.tXY[i]) ){
									thisInfo->DrawingVector.x = temp_coord->tPos.tXY[i].x - temp_coord->tPastPos[4].tXY[i].x;
									thisInfo->DrawingVector.y = temp_coord->tPos.tXY[i].y - temp_coord->tPastPos[4].tXY[i].y;
								}
								
							}
							if(temp_coord->DrawingFlag[i] == 0)
							{
								temp_coord->iStopPos[i] = temp_coord->tPos.tXY[i];
							}
						}
						if(thisInfo->WinCertMode == 1)
						{
							if(temp_coord->DrawingFlag[i] && algorithm_coord_calc_distance(temp_coord->iStopPos[i],temp_coord->tOrgPos.tXY[i]) > (dist_th<<2)){
								thisInfo->DrawingDirection = 0;
								thisInfo->WinCertMode = 0;
							}
							
						}
					}
					else{		//temp_coord->tPastPos[0].vusS[i] == 0
						if(thisInfo->WinCertMode == 1 && temp_coord->tTempPos.sFinger_ == 1 && algorithm_coord_IsEdgeArea(&temp_coord->tPos.tXY[i],0))
						{
							thisInfo->DrawingDirection = 0;
							thisInfo->WinCertMode = 0;
						}
						
					}
				}
				else
				{
					temp_coord->DrawingFlag[i] = YES;
				}
			}
			
			// Finger Edge Smoothing
			if(thisModeConf->CoordEdge.cEdgeSmoothing_Finger_On > 0)
			{
				int MoveSmoothingLevel = thisModeConf->Coord.lMoveSmoothingLevel;
				if(temp_coord->tPos.tXY[i].x < (1<<(POS_BOOST_SHIFT_)) || temp_coord->tPos.tXY[i].y > thisInfo->tCoord.iInternalYRes-(1<<(POS_BOOST_SHIFT_))
					|| temp_coord->tPos.tXY[i].x > thisInfo->tCoord.iInternalXRes-(1<<(POS_BOOST_SHIFT_)) || temp_coord->tPos.tXY[i].y < (1<<(POS_BOOST_SHIFT_)))
				{
					prev_curr_dist = abs(temp_coord->tPastPos[0].tXY[i].x - temp_coord->tPos.tXY[i].x);
					prev_curr_dist += thisModeConf->CoordEdge.cEdgeSmoothing_Finger_On;					
					if(prev_curr_dist < 10) prev_curr_dist = 10;					
					if(prev_curr_dist > _BV(MoveSmoothingLevel)) prev_curr_dist = _BV(MoveSmoothingLevel);

					temp_coord->tPos.tXY[i].x = ((_BV(MoveSmoothingLevel) - prev_curr_dist) * temp_coord->tPastPos[0].tXY[i].x + prev_curr_dist * temp_coord->tPos.tXY[i].x + _BV(MoveSmoothingLevel-1)) >> MoveSmoothingLevel;
					
					prev_curr_dist = abs(temp_coord->tPastPos[0].tXY[i].y - temp_coord->tPos.tXY[i].y);
					prev_curr_dist += thisModeConf->CoordEdge.cEdgeSmoothing_Finger_On;					
					if(prev_curr_dist < 10) prev_curr_dist = 10;					
					if(prev_curr_dist > _BV(MoveSmoothingLevel)) prev_curr_dist = _BV(MoveSmoothingLevel);


					temp_coord->tPos.tXY[i].y = ((_BV(MoveSmoothingLevel) - prev_curr_dist) * temp_coord->tPastPos[0].tXY[i].y + prev_curr_dist * temp_coord->tPos.tXY[i].y + _BV(MoveSmoothingLevel-1)) >> MoveSmoothingLevel;				
				}
			}				
		}
		else{
			if(thisModeConf->Coord.usFirstDrawingThd > 0 && temp_coord->tPastPos[0].vusR[i] > 0)
			{
				if(temp_coord->DrawingFlag[i]){
						AddDistTh-=10;
					if( AddDistTh < -32 )
						AddDistTh = -32;
				}
				else{
						AddDistTh+=10;
					if( AddDistTh > (1<<(POS_BOOST_SHIFT_-1)) )
						AddDistTh = (1<<(POS_BOOST_SHIFT_-1));
				}
				
			}
			
			temp_coord->bIsMoving[i] = NO;
			temp_coord->DrawingFlag[i] = NO;
		}
		
	}
}

void algorithm_coord_OutInDrawing(void)
{
	int i;
	tXY_t	temp_pos, temp_pos2;
	int bound_th = thisModeConf->CoordEdge.usOutInDrawEdgeTh;
	int dis_th = thisModeConf->CoordEdge.ucOutInDrawDisTh;
	int PostProcess[MAX_TOUCH_] = {0, };
	
	tCoordInfo_t 	*temp_coord;

	temp_coord = &thisInfo->tCoord;

	for( i=MAX_TOUCH_; i--; )
	{
		if( temp_coord->tPos.vusS[i] > 0 && temp_coord->tPastPos[0].vusS[i] == 0 )
		{
			if( (temp_coord->tFirstPos.tXY[i].x < thisModeConf->CoordEdge.usOutInDrawEdgeTh) || ((thisInfo->tCoord.iInternalXRes - temp_coord->tFirstPos.tXY[i].x) < thisModeConf->CoordEdge.usOutInDrawEdgeTh)
			|| (temp_coord->tFirstPos.tXY[i].y < thisModeConf->CoordEdge.usOutInDrawEdgeTh) || ((thisInfo->tCoord.iInternalYRes - temp_coord->tFirstPos.tXY[i].y) < thisModeConf->CoordEdge.usOutInDrawEdgeTh) )
			{
				if(temp_coord->tFirstPos.tXY[i].x == temp_coord->tOrgPos.tXY[i].x && temp_coord->tFirstPos.tXY[i].y == temp_coord->tOrgPos.tXY[i].y)
				{
					temp_coord->tPos.vusS[i] = 0;
					break;
				}
			}
			
			if(temp_coord->tFirstPos.tXY[i].x < bound_th)
			{
				temp_pos2.x = temp_coord->tOrgPos.tXY[i].x-temp_coord->tFirstPos.tXY[i].x;
				if(temp_pos2.x > dis_th)
				{
					PostProcess[i] = 1;
					temp_pos2.y = temp_coord->tOrgPos.tXY[i].y - temp_coord->tFirstPos.tXY[i].y;
					temp_pos.x = temp_coord->tFirstPos.tXY[i].x;
					temp_pos.y = (temp_pos.x*temp_pos2.y)/temp_pos2.x;
					temp_coord->tPos.tXY[i].x = -UNIT_DIST;
					temp_coord->tPos.tXY[i].y = temp_coord->tFirstPos.tXY[i].y - temp_pos.y;
				}
			}
			else if(temp_coord->tFirstPos.tXY[i].x > thisInfo->tCoord.iInternalXRes - bound_th)
			{
				temp_pos2.x = temp_coord->tFirstPos.tXY[i].x-temp_coord->tOrgPos.tXY[i].x;
				if(temp_pos2.x > dis_th)
				{
					PostProcess[i] = 1;
					temp_pos2.y = temp_coord->tOrgPos.tXY[i].y - temp_coord->tFirstPos.tXY[i].y;
					temp_pos.x = thisInfo->tCoord.iInternalXRes - temp_coord->tFirstPos.tXY[i].x;
					temp_pos.y = (temp_pos.x*temp_pos2.y)/temp_pos2.x;
					temp_coord->tPos.tXY[i].x = thisInfo->tCoord.iInternalXRes + UNIT_DIST;
					temp_coord->tPos.tXY[i].y = temp_coord->tFirstPos.tXY[i].y - temp_pos.y;
				}
			}	
			
			if(temp_coord->tFirstPos.tXY[i].y > thisInfo->tCoord.iInternalYRes - bound_th)
			{
				if(PostProcess[i] == 0 || ((temp_coord->tPos.tXY[i].x == -UNIT_DIST || temp_coord->tPos.tXY[i].x == (thisInfo->tCoord.iInternalXRes + UNIT_DIST)) && temp_coord->tPos.tXY[i].y > (thisInfo->tCoord.iInternalYRes + UNIT_DIST)))
				{
					temp_pos2.x = temp_coord->tOrgPos.tXY[i].x-temp_coord->tFirstPos.tXY[i].x;
					temp_pos2.y = temp_coord->tFirstPos.tXY[i].y-temp_coord->tOrgPos.tXY[i].y;
					if(temp_pos2.y > dis_th)
					{
						PostProcess[i] = 1;
						temp_pos.y = thisInfo->tCoord.iInternalYRes - temp_coord->tFirstPos.tXY[i].y;
						temp_pos.x = (temp_pos2.x*temp_pos.y)/temp_pos2.y;
						temp_coord->tPos.tXY[i].x = temp_coord->tFirstPos.tXY[i].x - temp_pos.x;
						temp_coord->tPos.tXY[i].y = thisInfo->tCoord.iInternalYRes + UNIT_DIST;
					}
				}
			}	

			else if(temp_coord->tFirstPos.tXY[i].y < bound_th)
			{
				if(PostProcess[i] == 0 || ((temp_coord->tPos.tXY[i].x == -UNIT_DIST || temp_coord->tPos.tXY[i].x == (thisInfo->tCoord.iInternalXRes + UNIT_DIST)) && temp_coord->tPos.tXY[i].y < -UNIT_DIST))
				{
					PostProcess[i] = 1;
					temp_pos2.x = temp_coord->tOrgPos.tXY[i].x - temp_coord->tFirstPos.tXY[i].x;
					temp_pos2.y = temp_coord->tOrgPos.tXY[i].y - temp_coord->tFirstPos.tXY[i].y;
					if(temp_pos2.y > dis_th)
					{
						temp_pos.y = temp_coord->tFirstPos.tXY[i].y;
						temp_pos.x = (temp_pos2.x*temp_pos.y)/temp_pos2.y;
						temp_coord->tPos.tXY[i].x = temp_coord->tFirstPos.tXY[i].x - temp_pos.x;
						temp_coord->tPos.tXY[i].y = -UNIT_DIST;
					}
				}
			}
			
			if(PostProcess[i] == 1)
			{
				temp_coord->tFirstPos.tXY[i] = temp_coord->tOrgPos.tXY[i];
			}
		}
	}
}
void algorithm_coord_PostProcess(int mode)
{
	int i;
	tXY_t	temp_pos;

	tCoordInfo_t 	*temp_coord;

	if(mode != FULL_MODE)
		temp_coord = &thisInfo->tCoord_local;
	else
		temp_coord = &thisInfo->tCoord;

	for( i=MAX_TOUCH_; i--; )
	{
		if( temp_coord->tPos.vusS[i] > 0 && temp_coord->tPastPos[0].vusS[i] == 0 )
		{
			if( temp_coord->cScreenDebCnt[i] > 2 )
			{
				if( algorithm_coord_IsEdgeArea(&temp_coord->tFirstPos.tXY[i], 0) > 0 )
				{
					int dist;

					dist = algorithm_coord_calc_distance(temp_coord->tFirstPos.tXY[i], temp_coord->tOrgPos.tXY[i]);

					if( dist > _BV(6) )
					{
						temp_coord->ucPostProcessRun[i] = 1;
						temp_pos = temp_coord->tPos.tXY[i];
						temp_coord->tPos.tXY[i] = temp_coord->tFirstPos.tXY[i];
						temp_coord->tFirstPos.tXY[i] = temp_pos;
					}
				}
			}
		}

		if(thisModeConf->CoordEdge.usPostProcessEdgeTH > 0)
		{
			if(temp_coord->tOrgPos.vusS[i] == 0 && temp_coord->tOrgPastPos[1].vusS[i] > 0 && temp_coord->tOrgPastPos[0].vusS[i] > 0 && temp_coord->tOrgPastPos[2].vusS[i] > 0) 
			{
				int ExpandTH = thisModeConf->CoordEdge.usPostProcessEdgeTH;
				uint8_t x_edge_f = 0;
				uint8_t y_edge_f = 0;
				
				if(temp_coord->tOrgPastPos[0].tXY[i].x < ExpandTH)x_edge_f = 1;
				else if(thisInfo->tCoord.iInternalXRes - temp_coord->tOrgPastPos[0].tXY[i].x < ExpandTH)x_edge_f = 2;
				
				if(temp_coord->tOrgPastPos[0].tXY[i].y < ExpandTH)y_edge_f = 1;
				else if(thisInfo->tCoord.iInternalYRes - temp_coord->tOrgPastPos[0].tXY[i].y < ExpandTH)y_edge_f = 2;
				
				if(x_edge_f || y_edge_f)
				{
					int dist_y[3] = {0,};			
					int dist_x[3] = {0,};      
				
					dist_y[0] = temp_coord->tPastPos[0].tXY[i].y - temp_coord->tPastPos[1].tXY[i].y;			
					dist_x[0] = temp_coord->tPastPos[0].tXY[i].x - temp_coord->tPastPos[1].tXY[i].x;				

					dist_y[1] = temp_coord->tPastPos[0].tXY[i].y - temp_coord->tPastPos[2].tXY[i].y;
					dist_x[1] = temp_coord->tPastPos[0].tXY[i].x - temp_coord->tPastPos[2].tXY[i].x;		
				
					dist_y[2] = temp_coord->tPastPos[1].tXY[i].y - temp_coord->tPastPos[2].tXY[i].y;
					dist_x[2] = temp_coord->tPastPos[1].tXY[i].x - temp_coord->tPastPos[2].tXY[i].x;	
					
					if( (dist_x[0] < -thisModeConf->CoordEdge.ucPostProcessDisTH && dist_x[1] < -thisModeConf->CoordEdge.ucPostProcessDisTH && dist_x[2] < -thisModeConf->CoordEdge.ucPostProcessDisTH && x_edge_f == 1)
					|| (dist_x[0] > thisModeConf->CoordEdge.ucPostProcessDisTH   && dist_x[1] > thisModeConf->CoordEdge.ucPostProcessDisTH && dist_x[2] > thisModeConf->CoordEdge.ucPostProcessDisTH &&x_edge_f == 2)
					|| (dist_y[0] < -thisModeConf->CoordEdge.ucPostProcessDisTH  && dist_y[1] < -thisModeConf->CoordEdge.ucPostProcessDisTH && dist_y[2] < -thisModeConf->CoordEdge.ucPostProcessDisTH && y_edge_f == 1)
					|| (dist_y[0] > thisModeConf->CoordEdge.ucPostProcessDisTH   && dist_y[2] > thisModeConf->CoordEdge.ucPostProcessDisTH && dist_y[2] > thisModeConf->CoordEdge.ucPostProcessDisTH && y_edge_f == 2) )
					{
						temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + dist_x[0]/thisModeConf->CoordEdge.ucPostProcessExpendDiv;
						temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + dist_y[0]/thisModeConf->CoordEdge.ucPostProcessExpendDiv;
						
						uint8_t max_idx = 0;
						if(x_edge_f == 1 && temp_coord->tPos.tXY[i].x > -thisModeConf->CoordEdge.cPostProcessEndMargin)
						{
							temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + MIN(dist_x[0],MIN(dist_x[1], dist_x[2]));
							
							if(abs(dist_y[0]) >= abs(dist_y[1]) && abs(dist_y[0]) >= abs(dist_y[2]))max_idx = 0;
							else if(abs(dist_y[1]) >= abs(dist_y[0]) && abs(dist_y[1]) >= abs(dist_y[2]))max_idx = 1;
							else if(abs(dist_y[2]) >= abs(dist_y[0]) && abs(dist_y[2]) >= abs(dist_y[1]))max_idx = 2;
							
							temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + dist_y[max_idx];
						}
						else if(x_edge_f == 2 && temp_coord->tPos.tXY[i].x < thisInfo->tCoord.iInternalXRes + thisModeConf->CoordEdge.cPostProcessEndMargin)
						{
							temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + MAX(dist_x[0],MAX(dist_x[1], dist_x[2]));
																	
							if(abs(dist_y[0]) >= abs(dist_y[1]) && abs(dist_y[0]) >= abs(dist_y[2]))max_idx = 0;
							else if(abs(dist_y[1]) >= abs(dist_y[0]) && abs(dist_y[1]) >= abs(dist_y[2]))max_idx = 1;
							else if(abs(dist_y[2]) >= abs(dist_y[0]) && abs(dist_y[2]) >= abs(dist_y[1]))max_idx = 2;
							
							temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + dist_y[max_idx];
						}
						
						max_idx = 0;
						if(y_edge_f == 1 && temp_coord->tPos.tXY[i].y > -thisModeConf->CoordEdge.cPostProcessEndMargin)
						{
							temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + MIN(dist_y[0],MIN(dist_y[1], dist_y[2]));
																	
							if(abs(dist_x[0]) >= abs(dist_x[1]) && abs(dist_x[0]) >= abs(dist_x[2]))max_idx = 0;
							else if(abs(dist_x[1]) >= abs(dist_x[0]) && abs(dist_x[1]) >= abs(dist_x[2]))max_idx = 1;
							else if(abs(dist_x[2]) >= abs(dist_x[0]) && abs(dist_x[2]) >= abs(dist_x[1]))max_idx = 2;
							
							temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + dist_x[max_idx];
						}
						else if(y_edge_f == 2 && temp_coord->tPos.tXY[i].y < thisInfo->tCoord.iInternalYRes + thisModeConf->CoordEdge.cPostProcessEndMargin)
						{
							temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + MAX(dist_y[0],MAX(dist_y[1], dist_y[2]));
							
							if(abs(dist_x[0]) >= abs(dist_x[1]) && abs(dist_x[0]) >= abs(dist_x[2]))max_idx = 0;
							else if(abs(dist_x[1]) >= abs(dist_x[0]) && abs(dist_x[1]) >= abs(dist_x[2]))max_idx = 1;
							else if(abs(dist_x[2]) >= abs(dist_x[0]) && abs(dist_x[2]) >= abs(dist_x[1]))max_idx = 2;
							
							temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + dist_x[max_idx];
						}
							
						temp_coord->tPos.vusS[i]  =  temp_coord->tOrgPastPos[0].vusS[i];
						temp_coord->tPos.vusR[i]  =  temp_coord->tOrgPastPos[0].vusR[i];						
					}
				}
			}
		}
	}
}

void algorithm_coord_PostProcess_1(void)
{
	int i;
	tXY_t	temp_pos;

	tCoordInfo_t 	*temp_coord;

	temp_coord = &thisInfo->tCoord;

	for( i=MAX_TOUCH_; i--; )
	{
		if(!thisModeConf->CoordEdge.bPostProcessInterpolationMode)
		{
			if( temp_coord->tPos.vusS[i] > 0 && temp_coord->tPastPos[0].vusS[i] == 0 )
			{
				if( temp_coord->cScreenDebCnt[i] > 2 )
				{
					if( algorithm_coord_IsEdgeArea(&temp_coord->tFirstPos.tXY[i], 0) > 0 )
					{
						int dist;

						dist = algorithm_coord_calc_distance(temp_coord->tFirstPos.tXY[i], temp_coord->tOrgPos.tXY[i]);

						if( dist > _BV(6) )
						{
							temp_coord->ucPostProcessRun[i] = 1;
							temp_pos = temp_coord->tPos.tXY[i];
							temp_coord->tPos.tXY[i] = temp_coord->tFirstPos.tXY[i];
							temp_coord->tFirstPos.tXY[i] = temp_pos;
						}
					}
				}
			}
		}

		if(thisModeConf->CoordEdge.usPostProcessEdgeTH > 0)
		{
			if( ((temp_coord->tOrgPos.vusS[i] == 0 && temp_coord->tPastPos[2].vusS[i] > 0 && temp_coord->tPastPos[0].vusS[i] > 0 && temp_coord->tPastPos[4].vusS[i] > 0) && thisModeConf->CoordEdge.bPostProcessInterpolationMode)
			|| ((temp_coord->tOrgPos.vusS[i] == 0 && temp_coord->tPastPos[1].vusS[i] > 0 && temp_coord->tPastPos[0].vusS[i] > 0 && temp_coord->tPastPos[2].vusS[i] > 0) && !thisModeConf->CoordEdge.bPostProcessInterpolationMode) )
			{
				tXY_t pos;
				pos = temp_coord->tPastPos[0].tXY[i];				
				pos.x = ( (pos.x + thisInfo->tCoord.iXOffset ) * (thisCommonConf->iXResolution+thisModeConf->Coord.sFingerGlobalCoordiXResolutionOffset) ) / (thisInfo->tCoord.iInternalXRes + 2*thisInfo->tCoord.iXOffset);
				pos.y = ( (pos.y + thisInfo->tCoord.iYOffset ) * (thisCommonConf->iYResolution+thisModeConf->Coord.sFingerGlobalCoordiYResolutionOffset) ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
				pos.x += thisModeConf->Coord.sFingerGlobalCoordiOffsetX;
				pos.y += thisModeConf->Coord.sFingerGlobalCoordiOffsetY;	
				
				if( (pos.x < 5 || pos.x > 32762 || pos.y < 5 || pos.y > 32762) && thisModeConf->CoordEdge.cPostProcessEndMargin == 0)
				{
				}
				else
				{				
					int ExpandTH = thisModeConf->CoordEdge.usPostProcessEdgeTH;
					uint8_t x_edge_f = 0;
					uint8_t y_edge_f = 0;
					
					if(temp_coord->tOrgPastPos[0].tXY[i].x < ExpandTH)x_edge_f = 1;
					else if(thisInfo->tCoord.iInternalXRes - temp_coord->tOrgPastPos[0].tXY[i].x < ExpandTH)x_edge_f = 2;
					
					if(temp_coord->tOrgPastPos[0].tXY[i].y < ExpandTH)y_edge_f = 1;
					else if(thisInfo->tCoord.iInternalYRes - temp_coord->tOrgPastPos[0].tXY[i].y < ExpandTH)y_edge_f = 2;
					
					if(x_edge_f || y_edge_f)
					{
						int dist_y[3] = {0,};			
						int dist_x[3] = {0,};      
						
						tXY_t temp_dist1 = temp_coord->tPastPos[0].tXY[i], temp_dist2, temp_dist3;
						if(thisModeConf->CoordEdge.bPostProcessInterpolationMode)
						{
							temp_dist2 = temp_coord->tPastPos[2].tXY[i];
							temp_dist3 = temp_coord->tPastPos[4].tXY[i];
						}
						else
						{
							temp_dist2 = temp_coord->tPastPos[1].tXY[i];
							temp_dist3 = temp_coord->tPastPos[2].tXY[i];
						}
					
						dist_y[0] = temp_dist1.y - temp_dist2.y;
						dist_x[0] = temp_dist1.x - temp_dist2.x;

						dist_y[1] = temp_dist1.y - temp_dist3.y;
						dist_x[1] = temp_dist1.x - temp_dist3.x;
					
						dist_y[2] = temp_dist2.y - temp_dist3.y;
						dist_x[2] = temp_dist2.x - temp_dist3.x;
						
						if( (dist_x[0] < -thisModeConf->CoordEdge.ucPostProcessDisTH && dist_x[1] < -thisModeConf->CoordEdge.ucPostProcessDisTH && dist_x[2] < -thisModeConf->CoordEdge.ucPostProcessDisTH && x_edge_f == 1)
						|| (dist_x[0] > thisModeConf->CoordEdge.ucPostProcessDisTH   && dist_x[1] > thisModeConf->CoordEdge.ucPostProcessDisTH && dist_x[2] > thisModeConf->CoordEdge.ucPostProcessDisTH &&x_edge_f == 2)
						|| (dist_y[0] < -thisModeConf->CoordEdge.ucPostProcessDisTH  && dist_y[1] < -thisModeConf->CoordEdge.ucPostProcessDisTH && dist_y[2] < -thisModeConf->CoordEdge.ucPostProcessDisTH && y_edge_f == 1)
						|| (dist_y[0] > thisModeConf->CoordEdge.ucPostProcessDisTH   && dist_y[2] > thisModeConf->CoordEdge.ucPostProcessDisTH && dist_y[2] > thisModeConf->CoordEdge.ucPostProcessDisTH && y_edge_f == 2) )
						{
							temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + dist_x[0]/thisModeConf->CoordEdge.ucPostProcessExpendDiv;
							temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + dist_y[0]/thisModeConf->CoordEdge.ucPostProcessExpendDiv;
							
							uint8_t max_idx = 0;
							if(x_edge_f == 1 && temp_coord->tPos.tXY[i].x > -thisModeConf->CoordEdge.cPostProcessEndMargin)
							{
								temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + MIN(dist_x[0],MIN(dist_x[1], dist_x[2]));
							}
							else if(x_edge_f == 2 && temp_coord->tPos.tXY[i].x < thisInfo->tCoord.iInternalXRes + thisModeConf->CoordEdge.cPostProcessEndMargin)
							{
								temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + MAX(dist_x[0],MAX(dist_x[1], dist_x[2]));																		
							}
							
							if((x_edge_f == 1 || x_edge_f == 2) && y_edge_f == 0)
							{
								if(abs(dist_y[0]) >= abs(dist_y[1]) && abs(dist_y[0]) >= abs(dist_y[2]))max_idx = 0;
								else if(abs(dist_y[1]) >= abs(dist_y[0]) && abs(dist_y[1]) >= abs(dist_y[2]))max_idx = 1;
								else if(abs(dist_y[2]) >= abs(dist_y[0]) && abs(dist_y[2]) >= abs(dist_y[1]))max_idx = 2;
								
								temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + dist_y[max_idx];								
							}
							
							max_idx = 0;
							if(y_edge_f == 1 && temp_coord->tPos.tXY[i].y > -thisModeConf->CoordEdge.cPostProcessEndMargin)
							{
								temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + MIN(dist_y[0],MIN(dist_y[1], dist_y[2]));
							}
							else if(y_edge_f == 2 && temp_coord->tPos.tXY[i].y < thisInfo->tCoord.iInternalYRes + thisModeConf->CoordEdge.cPostProcessEndMargin)
							{
								temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + MAX(dist_y[0],MAX(dist_y[1], dist_y[2]));
							}

							if((y_edge_f == 1 || y_edge_f == 2) && x_edge_f == 0)
							{		
								if(abs(dist_x[0]) >= abs(dist_x[1]) && abs(dist_x[0]) >= abs(dist_x[2]))max_idx = 0;
								else if(abs(dist_x[1]) >= abs(dist_x[0]) && abs(dist_x[1]) >= abs(dist_x[2]))max_idx = 1;
								else if(abs(dist_x[2]) >= abs(dist_x[0]) && abs(dist_x[2]) >= abs(dist_x[1]))max_idx = 2;
								
								temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + dist_x[max_idx];								
							}
								
							temp_coord->tPos.vusS[i]  =  temp_coord->tOrgPastPos[0].vusS[i];
							temp_coord->tPos.vusR[i]  =  temp_coord->tOrgPastPos[0].vusR[i];	
							
						}   
					}
				}
			}
		}
	}
}

void algorithm_coord_UpdatePosHistoryInfo(void)
{
	int i;

	tCoordInfo_t 	*temp_coord;

	temp_coord = &thisInfo->tCoord;
	
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)	
	if(temp_coord->bInterpolation_On)
	{
		temp_coord->tPastPos[4].sFinger_ 	    = temp_coord->tPastPos[3].sFinger_;
		temp_coord->tPastPos[3].sFinger_ 	    = temp_coord->tPastPos[2].sFinger_;
		
		temp_coord->tOrgPastPos[4].sFinger_ 	= temp_coord->tOrgPastPos[3].sFinger_;
		temp_coord->tOrgPastPos[3].sFinger_ 	= temp_coord->tOrgPastPos[2].sFinger_;
	}
#endif

	temp_coord->tPastPos[2].sFinger_ 	    = temp_coord->tPastPos[1].sFinger_;
	temp_coord->tPastPos[1].sFinger_ 	    = temp_coord->tPastPos[0].sFinger_;
	temp_coord->tPastPos[0].sFinger_ 	    = temp_coord->tPos.sFinger_;

	temp_coord->tOrgPastPos[2].sFinger_ 	= temp_coord->tOrgPastPos[1].sFinger_;
	temp_coord->tOrgPastPos[1].sFinger_ 	= temp_coord->tOrgPastPos[0].sFinger_;
	temp_coord->tOrgPastPos[0].sFinger_ 	= temp_coord->tOrgPos.sFinger_;

	for( i=MAX_TOUCH_; i--; )
	{
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
		if(temp_coord->bInterpolation_On)
		{
			temp_coord->tPastPos[4].tXY[i]         = temp_coord->tPastPos[3].tXY[i];
			temp_coord->tPastPos[4].vusR[i]        = temp_coord->tPastPos[3].vusR[i];
			temp_coord->tPastPos[4].vusS[i]        = temp_coord->tPastPos[3].vusS[i];
			
			temp_coord->tPastPos[3].tXY[i]         = temp_coord->tPastPos[2].tXY[i];
			temp_coord->tPastPos[3].vusR[i]        = temp_coord->tPastPos[2].vusR[i];
			temp_coord->tPastPos[3].vusS[i]        = temp_coord->tPastPos[2].vusS[i];
			
			temp_coord->tOrgPastPos[4].tXY[i]      = temp_coord->tOrgPastPos[3].tXY[i];
			temp_coord->tOrgPastPos[4].vusR[i]     = temp_coord->tOrgPastPos[3].vusR[i];
			temp_coord->tOrgPastPos[4].vusS[i]     = temp_coord->tOrgPastPos[3].vusS[i];
			
			temp_coord->tOrgPastPos[3].tXY[i]      = temp_coord->tOrgPastPos[2].tXY[i];
			temp_coord->tOrgPastPos[3].vusR[i]     = temp_coord->tOrgPastPos[2].vusR[i];
			temp_coord->tOrgPastPos[3].vusS[i]     = temp_coord->tOrgPastPos[2].vusS[i];
		}
#endif
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

int32_t algorithm_coord_calc_distance(tXY_t pos1, tXY_t pos2)
{
	int32_t dist;

	dist = (pos1.x - pos2.x)*(pos1.x - pos2.x) + (pos1.y - pos2.y)*(pos1.y - pos2.y);

    dist = algorithm_calc_sqrt(dist);

	return dist;
}

int32_t algorithm_coord_calc_comp_distance(tXY_t pos1, tXY_t pos2, tXY_t comp)
{
	int32_t dist;

	dist = (pos1.x - pos2.x - comp.x)*(pos1.x - pos2.x - comp.x) + (pos1.y - pos2.y - comp.y)*(pos1.y - pos2.y - comp.y);

    dist = algorithm_calc_sqrt(dist);

	return dist;
}

void algorithm_width_height_calculation(int cl)
{
	tCoordInfo_t 	*temp_coord;
	tRect_t *temp_rect;
	int iWidth, iHeight;
	
	temp_coord = &thisInfo->tCoord;
	temp_rect = &temp_coord->tPos.rect[cl];
	
	iWidth  = ((temp_rect->ce - temp_rect->cs + 1) * thisCommonConf->iXResolution + (COL_MAX>>1)) / COL_MAX;
	iHeight = ((temp_rect->re - temp_rect->rs + 1) * thisCommonConf->iYResolution + (ROW_MAX>>1)) / ROW_MAX;
	temp_coord->tPos.vusW[cl] = (iWidth < 0 ? 0 : iWidth);
	temp_coord->tPos.vusH[cl] = (iHeight < 0 ? 0 : iHeight);
	
	return;
}

#define ExpectClipping_Finger_Margin	200
void alogorithm_coord_modify_pos(tXY_t* old_pos,tXY_t* pos, int index)
{
	int x, y;
#if (MULTI_EDGE_COEF_EN == YES)
	bool_t bIsEdge;
#endif
	uint8_t ucLeftEdgeExpand = thisModeConf->EdgeExpand.ucLeftEdgeExpand, ucRightEdgeExpand = thisModeConf->EdgeExpand.ucRightEdgeExpand;
	uint8_t ucTopEdgeExpand = thisModeConf->EdgeExpand.ucTopEdgeExpand, ucBottomEdgeExpand = thisModeConf->EdgeExpand.ucBottomEdgeExpand;
//	int ucXCompensationGain = 10;//24; // NOTE : not used

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
//	if( 1)
	{
		if (!thisModeConf->EdgeExpand.bDoNotExpandPos)
		{
		#if (MULTI_EDGE_COEF_EN == YES)
			if(thisModeConf->EdgeExpand.bUseMultiEdgeCoef)
			{
				bIsEdge = algorithm_coord_IsEdgeArea(&thisInfo->tCoord.tPos.tXY[index], thisModeConf->EdgeExpand.sXExpandStartOffset);
				if(bIsEdge == 0)
				{
					if(thisInfo->tCoord.ucEdgeExpandCoef[index] == 0)
					{
						if(
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
							((thisInfo->tCoord.bInterpolation_On && thisInfo->tCoord.tPastPos[2].vusS[index] > 0) || (!thisInfo->tCoord.bInterpolation_On && thisInfo->tCoord.tPastPos[1].vusS[index] > 0))
#else
							(thisInfo->tCoord.tPastPos[1].vusS[index] > 0)
#endif
							&& thisInfo->tCoord.tPastPos[0].vusS[index] > 0 && thisInfo->tCoord.tPos.vusS[index] > 0 && thisInfo->tCoord.tPos.MaxDelta[index] > thisModeConf->EdgeExpand.usSmallTouchMaxDeltaThd
							&& thisInfo->tCoord.tPos.vusR[index] < thisModeConf->EdgeExpand.ucSmallTouchCellCntThd && (thisInfo->tCoord.tPos.rect[index].re - thisInfo->tCoord.tPos.rect[index].rs + 1) < thisModeConf->EdgeExpand.ucSmallTouchHeightThd
							&& (thisInfo->tCoord.tPos.rect[index].ce - thisInfo->tCoord.tPos.rect[index].cs + 1) < thisModeConf->EdgeExpand.ucSmallTouchWidthThd )
						{
							thisInfo->tCoord.ucEdgeExpandCoef[index] = 1;
						}
					}
				}
				else
				{
					if(thisInfo->tCoord.tPastPos[0].vusS[index] == 0 && thisInfo->tCoord.tPos.vusS[index] > 0)
					{
						thisInfo->tCoord.ucEdgeExpandCoef[index] = 2;
					}
				}
			}
			
			if(thisInfo->tCoord.ucEdgeExpandCoef[index] == 1)
			{
				ucLeftEdgeExpand = thisModeConf->EdgeExpand.ucLeftEdgeExpand_small;
				ucRightEdgeExpand = thisModeConf->EdgeExpand.ucRightEdgeExpand_small;
				ucTopEdgeExpand = thisModeConf->EdgeExpand.ucTopEdgeExpand_small;
				ucBottomEdgeExpand = thisModeConf->EdgeExpand.ucBottomEdgeExpand_small;
			}
			else if(thisInfo->tCoord.ucEdgeExpandCoef[index] == 2)
			{
				ucLeftEdgeExpand = thisModeConf->EdgeExpand.ucLeftEdgeExpand_medium;
				ucRightEdgeExpand = thisModeConf->EdgeExpand.ucRightEdgeExpand_medium;
				ucTopEdgeExpand = thisModeConf->EdgeExpand.ucTopEdgeExpand_medium;
				ucBottomEdgeExpand = thisModeConf->EdgeExpand.ucBottomEdgeExpand_medium;
			}
		#endif			
			int iXExpandStart = thisInfo->tCoord.iXExpandStart + thisModeConf->EdgeExpand.sXExpandStartOffset;
			int iYExpandStart = thisInfo->tCoord.iYExpandStart + thisModeConf->EdgeExpand.sYExpandStartOffset;
			
			if(thisInfo->WinCertMode < 1)
			{
				if (x < iXExpandStart)
					x = iXExpandStart + (((x - iXExpandStart) * (int32_t)ucLeftEdgeExpand) >> 6);
				else if (thisInfo->tCoord.iInternalXRes - x < iXExpandStart)
					x = thisInfo->tCoord.iInternalXRes - (iXExpandStart
										 + (((thisInfo->tCoord.iInternalXRes - x - iXExpandStart) * (int32_t)ucRightEdgeExpand) >> 6));

				if (y < iYExpandStart)
					y = iYExpandStart + (((y - iYExpandStart) * (int32_t)ucTopEdgeExpand) >> 6);
				else if (thisInfo->tCoord.iInternalYRes - y < iYExpandStart)
					y = thisInfo->tCoord.iInternalYRes - (iYExpandStart
										 + (((thisInfo->tCoord.iInternalYRes - y - iYExpandStart) * (int32_t)ucBottomEdgeExpand) >> 6));
			}
		}
	}

	/*
	 * Modify resolution domain.
	 */
	x = ( (x + thisInfo->tCoord.iXOffset ) * (thisCommonConf->iXResolution+thisModeConf->Coord.sFingerGlobalCoordiXResolutionOffset) ) / (thisInfo->tCoord.iInternalXRes + 2*thisInfo->tCoord.iXOffset);
	x += thisModeConf->Coord.sFingerGlobalCoordiOffsetX;
#if (FingerGlobalCoordiY_2Region_Set == YES)
	if(y < thisModeConf->Coord.sFingerGlobalCoordiY_2Region_boundary)
	{
		y = ( (y + thisInfo->tCoord.iYOffset ) * (thisCommonConf->iYResolution+thisModeConf->Coord.sFingerGlobalCoordiYResolutionOffset) ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
		y += thisModeConf->Coord.sFingerGlobalCoordiOffsetY;
	}
	else
	{
		y = ( (y + thisInfo->tCoord.iYOffset ) * (thisCommonConf->iYResolution+thisModeConf->Coord.sFingerGlobalCoordiYResolutionOffset1) ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
		y += thisModeConf->Coord.sFingerGlobalCoordiOffsetY1;
	}
#else
	y = ( (y + thisInfo->tCoord.iYOffset ) * (thisCommonConf->iYResolution+thisModeConf->Coord.sFingerGlobalCoordiYResolutionOffset) ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
	y += thisModeConf->Coord.sFingerGlobalCoordiOffsetY;
#endif
	/*
	 * Clipping.
	 */
	int iXResolutionForClipping = thisCommonConf->iXResolution - 1;
	int iYResolutionForClipping = thisCommonConf->iYResolution - 1;
//	if(iXResolutionForClipping > 32767)iXResolutionForClipping = 32767;
//	if(iYResolutionForClipping > 32767)iYResolutionForClipping = 32767;
	if(thisModeConf->CoordEdge.bExpectClipping_Finger_On)
	{
		pos->x = x,	pos->y = y;
		if (x < (int)thisCommonConf->ucClippingLeft){	//LEFT
			x = (int)(thisCommonConf->ucClippingLeft);
			if( (thisModeConf->CoordEdge.bUseNewCippingCond && old_pos != pos && pos->x < (thisCommonConf->ucClippingLeft) && old_pos->x > (thisCommonConf->ucClippingLeft))
				|| (!thisModeConf->CoordEdge.bUseNewCippingCond && old_pos != pos && pos->x != old_pos->x && old_pos->x > ExpectClipping_Finger_Margin) )
				y = ( (x - old_pos->x)*(pos->y - old_pos->y) + ((pos->x - old_pos->x)>>1) ) / (pos->x - old_pos->x) + old_pos->y;
			pos->x = x,	pos->y = y;
		}
		else if (x > ((int)((iXResolutionForClipping) - thisCommonConf->ucClippingRight))){	//RIGHT
			x = (iXResolutionForClipping) - thisCommonConf->ucClippingRight;
			if( (thisModeConf->CoordEdge.bUseNewCippingCond && old_pos != pos && pos->x > ((int)((iXResolutionForClipping) - (thisCommonConf->ucClippingRight))) && old_pos->x < ((int)((iXResolutionForClipping) - (thisCommonConf->ucClippingRight))))
				|| (!thisModeConf->CoordEdge.bUseNewCippingCond && old_pos != pos && pos->x != old_pos->x && old_pos->x < ((int)((iXResolutionForClipping) - ExpectClipping_Finger_Margin))) )
				y = ( (x - old_pos->x)*(pos->y - old_pos->y) + ((pos->x - old_pos->x)>>1) ) / (pos->x - old_pos->x) + old_pos->y;
			pos->x = x,	pos->y = y;
		}
		if (y < (int)(thisCommonConf->ucClippingTop)){	//UP
			y = (int)thisCommonConf->ucClippingTop;
			if( (thisModeConf->CoordEdge.bUseNewCippingCond && old_pos != pos && pos->y < (thisCommonConf->ucClippingTop) && old_pos->y > (thisCommonConf->ucClippingTop))
				|| (!thisModeConf->CoordEdge.bUseNewCippingCond && old_pos != pos && pos->y != old_pos->y && old_pos->y > ExpectClipping_Finger_Margin) )
				x = ( (y - old_pos->y)*(pos->x - old_pos->x) + ((pos->y - old_pos->y)>>1) ) / (pos->y - old_pos->y) + old_pos->x;
			pos->x = x,	pos->y = y;
		}
		else if (y > (int)((iYResolutionForClipping) - thisCommonConf->ucClippingBottom)){	//DOWN
			y = (int)((iYResolutionForClipping) - thisCommonConf->ucClippingBottom);
			if( (thisModeConf->CoordEdge.bUseNewCippingCond && old_pos != pos && pos->y > ((int)((iYResolutionForClipping) - (thisCommonConf->ucClippingBottom))) && old_pos->y < ((int)((iYResolutionForClipping) - (thisCommonConf->ucClippingBottom))))
				|| (!thisModeConf->CoordEdge.bUseNewCippingCond && old_pos != pos && pos->y != old_pos->y && old_pos->y < ((int)((iYResolutionForClipping) - ExpectClipping_Finger_Margin))) )
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

	#if (REMOVE_EDGE_EN == YES)
	if(thisModeConf->CoordEdge.bRemoveEdge && !algorithm_coord_IsEdgeArea(&thisInfo->tCoord.tFirstPos.tXY[index] , 0))
	{
		tXY_t pastpos1;
		
		if(thisModeConf->CoordEdge.bUsetRealPastSentPos1 == 0)
		{
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
			if(thisInfo->tCoord.bInterpolation_On)
				pastpos1.x = thisInfo->tCoord.tPastPos[2].tXY[index].x, pastpos1.y = thisInfo->tCoord.tPastPos[2].tXY[index].y;
			else
#endif
			pastpos1.x = thisInfo->tCoord.tPastPos[1].tXY[index].x, pastpos1.y = thisInfo->tCoord.tPastPos[1].tXY[index].y;
		
			pastpos1.x = ( (pastpos1.x + thisInfo->tCoord.iXOffset ) * (thisCommonConf->iXResolution+thisModeConf->Coord.sFingerGlobalCoordiXResolutionOffset) ) / (thisInfo->tCoord.iInternalXRes + 2*thisInfo->tCoord.iXOffset);
			pastpos1.y = ( (pastpos1.y + thisInfo->tCoord.iYOffset ) * (thisCommonConf->iYResolution+thisModeConf->Coord.sFingerGlobalCoordiYResolutionOffset) ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
			pastpos1.x += thisModeConf->Coord.sFingerGlobalCoordiOffsetX;
			pastpos1.y += thisModeConf->Coord.sFingerGlobalCoordiOffsetY;
			if (pastpos1.x < (int)thisCommonConf->ucXClipping) pastpos1.x = (int)(thisCommonConf->ucXClipping);
			else if (pastpos1.x > ((int)((iXResolutionForClipping) - thisCommonConf->ucXClipping))) pastpos1.x = (iXResolutionForClipping) - thisCommonConf->ucXClipping;
			if (pastpos1.y < (int)(thisCommonConf->ucYClipping)) pastpos1.y = (int)thisCommonConf->ucYClipping;
			else if (pastpos1.y > (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping)) pastpos1.y = (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping);
		}
		else if(thisModeConf->CoordEdge.bUsetRealPastSentPos1 == 1)
		{
			pastpos1.x = thisInfo->tCoord.tRealPastSentPos1.tXY[index].x;
			pastpos1.y = thisInfo->tCoord.tRealPastSentPos1.tXY[index].y;
		}
		
		if(thisModeConf->CoordEdge.ucRemoveEdgeVer == 0)
		{
			if(thisInfo->tCoord.bRemoveEdge[index] == 1)
			{
				thisInfo->tCoord.tPos.vusS[index] = 0;
			}
			else if(thisInfo->tCoord.tPos.vusS[index] <= thisInfo->tCoord.tPastPos[0].vusS[index] && thisInfo->tCoord.tPos.vusS[index] && thisInfo->tCoord.tPastPos[0].vusS[index] && thisInfo->tCoord.tPastPos[1].vusS[index])
			{
				if(old_pos->x == pos->x && ((pos->x == thisCommonConf->ucXClipping && pastpos1.x - old_pos->x > thisModeConf->CoordEdge.usRemoveEdgeXdistThd)
					|| (pos->x == (iXResolutionForClipping - thisCommonConf->ucXClipping) && old_pos->x - pastpos1.x > thisModeConf->CoordEdge.usRemoveEdgeXdistThd)))
				{
					thisInfo->tCoord.bRemoveEdge[index] = 1;
					thisInfo->tCoord.tPos.vusS[index] = 0;
				}
				if(old_pos->y == pos->y && ((pos->y == thisCommonConf->ucYClipping && pastpos1.y - old_pos->y > thisModeConf->CoordEdge.usRemoveEdgeYdistThd)
					||  (pos->y == (iYResolutionForClipping - thisCommonConf->ucYClipping) && old_pos->y - pastpos1.y > thisModeConf->CoordEdge.usRemoveEdgeYdistThd)))
				{
					thisInfo->tCoord.bRemoveEdge[index] = 1;
					thisInfo->tCoord.tPos.vusS[index] = 0;
				}
			}
		}
		else if(thisModeConf->CoordEdge.ucRemoveEdgeVer == 1)
		{
			if(algorithm_coord_IsEdgeArea(&thisInfo->tCoord.tPos.tXY[index] , 0))
			{
				uint8_t EdgeDirX = algorithm_coord_EdgeDirection(thisInfo->tCoord.tPos.MaxPos[index].r, thisInfo->tCoord.tPos.MaxPos[index].c, 1);
				uint8_t EdgeDirY = EdgeDirX / 10;
				
				if(thisInfo->tCoord.tPos.vusS[index] <= thisInfo->tCoord.tPastPos[0].vusS[index] && thisInfo->tCoord.tPos.vusS[index] && thisInfo->tCoord.tPastPos[0].vusS[index] && thisInfo->tCoord.tPastPos[1].vusS[index])
				{
					if((old_pos->x == pos->x && pos->x == (thisCommonConf->ucXClipping) && pastpos1.x - old_pos->x > thisModeConf->CoordEdge.usRemoveEdgeXdistThd)
						|| (old_pos->x == pos->x && pos->x == (iXResolutionForClipping - thisCommonConf->ucXClipping) && old_pos->x - pastpos1.x > thisModeConf->CoordEdge.usRemoveEdgeXdistThd))
					{
						thisInfo->tCoord.bRemoveEdge[index] = 1;
					}
					if((old_pos->y == pos->y && pos->y == (thisCommonConf->ucYClipping) && pastpos1.y - old_pos->y > thisModeConf->CoordEdge.usRemoveEdgeYdistThd)
						||  (old_pos->y == pos->y && pos->y == (iYResolutionForClipping - thisCommonConf->ucYClipping) && old_pos->y - pastpos1.y > thisModeConf->CoordEdge.usRemoveEdgeYdistThd))
					{
						thisInfo->tCoord.bRemoveEdge[index] = 1;
					}
				}
				
				if( ((EdgeDirX % 10) == 1 && old_pos->x <= pos->x && pos->x > (thisCommonConf->ucXClipping)) ||
					((EdgeDirX % 10) == 2 && old_pos->x >= pos->x && pos->x < (iXResolutionForClipping - thisCommonConf->ucXClipping)) ||
					((EdgeDirY % 10) == 1 && old_pos->y <= pos->y && pos->y > (thisCommonConf->ucYClipping)) ||
					((EdgeDirY % 10) == 2 && old_pos->y >= pos->y && pos->y < (iYResolutionForClipping - thisCommonConf->ucYClipping))
				)
				{
					thisInfo->tCoord.bRemoveEdge[index] = 0;
				}
				
				if(thisInfo->tCoord.bRemoveEdge[index] == 1)
				{
					pos->x = x = old_pos->x, pos->y = y = old_pos->y;
				}
			}
			else
			{
				thisInfo->tCoord.bRemoveEdge[index] = 0;
			}
		}
	}
	#endif
	
	pos->x = x;
	pos->y = y;
}

#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
void algorithm_coord_interpolation(uint8_t ver)
{	
	for (int l = 0; l < MAX_TOUCH_; l++)
	{
		if( thisInfo->tCoord.tOrgPastPos[0].vusS[l] )
		{
#if (INTERPOLATION_VER1_En == YES)
			if(ver == 1)
			{
				thisInfo->tCoord.tPos.tXY[l].x = (thisInfo->tCoord.tPastPos[0].tXY[l].x + thisInfo->tCoord.tOrgPastPos[0].tXY[l].x) >> 1;
				thisInfo->tCoord.tPos.tXY[l].y = (thisInfo->tCoord.tPastPos[0].tXY[l].y + thisInfo->tCoord.tOrgPastPos[0].tXY[l].y) >> 1;
			}
#endif
			//thisInfo->tCoord.tPos.tXY[l].x = thisInfo->tCoord.tOrgPos.tXY[l].x = (thisInfo->tCoord.tOrgPastPos[0].tXY[l].x<<1) - thisInfo->tCoord.tOrgPastPos[1].tXY[l].x;
			//thisInfo->tCoord.tPos.tXY[l].y = thisInfo->tCoord.tOrgPos.tXY[l].y = (thisInfo->tCoord.tOrgPastPos[0].tXY[l].y<<1) - thisInfo->tCoord.tOrgPastPos[1].tXY[l].y;
			int iDist = algorithm_coord_calc_distance(thisInfo->tCoord.tPos.tXY[l], thisInfo->tCoord.tPastPos[0].tXY[l]);
			if(iDist>(thisModeConf->CoordTracking.usMoveDistanceThd << POS_BOOST_SHIFT_))
			{
				thisInfo->tCoord.tPastPos[4].vusS[l] = thisInfo->tCoord.tPastPos[3].vusS[l] = thisInfo->tCoord.tPastPos[2].vusS[l] = thisInfo->tCoord.tPastPos[1].vusS[l] = thisInfo->tCoord.tPastPos[0].vusS[l] = thisInfo->tCoord.tPos.vusS[l] = 0;
				thisInfo->tCoord.tPastPos[4].vusR[l] = thisInfo->tCoord.tPastPos[3].vusR[l] = thisInfo->tCoord.tPastPos[2].vusR[l] = thisInfo->tCoord.tPastPos[1].vusR[l] = thisInfo->tCoord.tPastPos[0].vusR[l] = thisInfo->tCoord.tPos.vusR[l] = 0;
			}
#if (INTERPOLATION_VER1_En == YES)
			else
			{
				if(ver == 1)
				{
					iDist += thisModeConf->Coord.sInterpolationWeight;
					if(iDist < 10)
						iDist = 10;
					
					if(iDist > _BV(thisModeConf->Coord.lMoveSmoothingLevel))
						iDist = _BV(thisModeConf->Coord.lMoveSmoothingLevel);

					thisInfo->tCoord.tPos.tXY[l].x = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - iDist) * thisInfo->tCoord.tPastPos[0].tXY[l].x + iDist * thisInfo->tCoord.tPos.tXY[l].x + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
					thisInfo->tCoord.tPos.tXY[l].y = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - iDist) * thisInfo->tCoord.tPastPos[0].tXY[l].y + iDist * thisInfo->tCoord.tPos.tXY[l].y + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
				}
			}
#endif
		}
		else
		{
			thisInfo->tCoord.tPastPos[4].vusS[l] = thisInfo->tCoord.tPastPos[3].vusS[l] = thisInfo->tCoord.tPastPos[2].vusS[l] = thisInfo->tCoord.tPastPos[1].vusS[l] = thisInfo->tCoord.tPastPos[0].vusS[l] = thisInfo->tCoord.tPos.vusS[l] = 0;
			thisInfo->tCoord.tPastPos[4].vusR[l] = thisInfo->tCoord.tPastPos[3].vusR[l] = thisInfo->tCoord.tPastPos[2].vusR[l] = thisInfo->tCoord.tPastPos[1].vusR[l] = thisInfo->tCoord.tPastPos[0].vusR[l] = thisInfo->tCoord.tPos.vusR[l] = 0;
		}
	}
}
#endif
#if (INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
void algorithm_coord_interpolation_v02(uint8_t ver)
{
	int P1,P2;
	for (int l = 0; l < MAX_TOUCH_; l++)
	{
		thisInfo->tCoord.tTempPos.vusR[l] = thisInfo->tCoord.tPos.vusR[l];
		thisInfo->tCoord.tTempPos.vusS[l] = thisInfo->tCoord.tPos.vusS[l];
		if( thisInfo->tCoord.tPastPos[0].vusS[l] && thisInfo->tCoord.tPos.vusS[l] )
		{
			thisInfo->tCoord.tTempPos.tXY[l] = thisInfo->tCoord.tPos.tXY[l];
			if(ver == 3 && thisInfo->tCoord.tPastPos[2].vusS[l]>0 && thisInfo->tCoord.DrawingFlag[l])
			{//Bezier curve
				P1 = algorithm_coord_calc_distance(thisInfo->tCoord.tPos.tXY[l],thisInfo->tCoord.tPastPos[0].tXY[l]);
				P2 = algorithm_coord_calc_distance(thisInfo->tCoord.tPastPos[2].tXY[l],thisInfo->tCoord.tPastPos[0].tXY[l]);
				if( (P1<<1) > P2 && (P2<<1) > P1)
				{
					thisInfo->tCoord.tPos.tXY[l].x = ((3*(thisInfo->tCoord.tPos.tXY[l].x + (thisInfo->tCoord.tPastPos[0].tXY[l].x<<1)) - thisInfo->tCoord.tPastPos[2].tXY[l].x)>>3);
					thisInfo->tCoord.tPos.tXY[l].y = ((3*(thisInfo->tCoord.tPos.tXY[l].y + (thisInfo->tCoord.tPastPos[0].tXY[l].y<<1)) - thisInfo->tCoord.tPastPos[2].tXY[l].y)>>3);
				}
				else
				{
					thisInfo->tCoord.tPos.tXY[l].x = ((thisInfo->tCoord.tPos.tXY[l].x + thisInfo->tCoord.tPastPos[0].tXY[l].x)>>1);
					thisInfo->tCoord.tPos.tXY[l].y = ((thisInfo->tCoord.tPos.tXY[l].y + thisInfo->tCoord.tPastPos[0].tXY[l].y)>>1);
				}
				
//				thisInfo->tCoord.tPos.tXY[l].x = ((3*(thisInfo->tCoord.tPos.tXY[l].x + (thisInfo->tCoord.tPastPos[0].tXY[l].x<<1)) - thisInfo->tCoord.tPastPos[2].tXY[l].x)>>3);
//				thisInfo->tCoord.tPos.tXY[l].y = ((3*(thisInfo->tCoord.tPos.tXY[l].y + (thisInfo->tCoord.tPastPos[0].tXY[l].y<<1)) - thisInfo->tCoord.tPastPos[2].tXY[l].y)>>3);
			}
			else if(thisInfo->tCoord.tOrgPos.vusS[l]>0)
			{
				thisInfo->tCoord.tPos.tXY[l].x = ((thisInfo->tCoord.tPos.tXY[l].x + thisInfo->tCoord.tPastPos[0].tXY[l].x)>>1) + (thisInfo->tCoord.tPos.tXY[l].x-thisInfo->tCoord.tPastPos[0].tXY[l].x)/2*thisModeConf->Coord.sInterpolationWeight/255;
				thisInfo->tCoord.tPos.tXY[l].y = ((thisInfo->tCoord.tPos.tXY[l].y + thisInfo->tCoord.tPastPos[0].tXY[l].y)>>1) + (thisInfo->tCoord.tPos.tXY[l].y-thisInfo->tCoord.tPastPos[0].tXY[l].y)/2*thisModeConf->Coord.sInterpolationWeight/255;
			}
		}
		else if(thisInfo->tCoord.tPastPos[0].vusS[l] == 0 && thisInfo->tCoord.tPos.vusS[l])
		{
			thisInfo->tCoord.tTempPos.tXY[l] = thisInfo->tCoord.tPos.tXY[l];			
		}
		else
		{
			thisInfo->tCoord.tPos.vusR[l] = 0;
			thisInfo->tCoord.tPos.vusS[l] = 0;
		}
	}
	
	algorithm_PendTouchEvent();
	algorithm_coord_UpdatePosHistoryInfo();
	
	for (int l = 0; l < MAX_TOUCH_; l++)
	{
		thisInfo->tCoord.tPos.vusR[l] = thisInfo->tCoord.tTempPos.vusR[l];
		thisInfo->tCoord.tPos.vusS[l] = thisInfo->tCoord.tTempPos.vusS[l];
		if( thisInfo->tCoord.tPastPos[0].vusS[l] && thisInfo->tCoord.tPos.vusS[l] )
		{
			thisInfo->tCoord.tPos.tXY[l] = thisInfo->tCoord.tTempPos.tXY[l];
		}
	}

}
#endif
#if BIG_FINGER_EDGE_EXPAND_ALGO_EN
bool_t bContiFlag[4] = {0,};
int sum_r,sum_c;
int sum_TB,sum_LR,sum_Cr,Cr_size;
#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN
bool_t bBigFingerEdgeTestFlag[4] = {0,};
bool_t bBigFingerEdgeTestEn[4] = {0,};
extern uint8_t ucBigFingerEdgeTest_MoveEventTHD_Change;
extern bool_t bReportDelayFlag;
extern bool_t bReportDelayFlag;
extern uint8_t ucReportDelayCnt;
#endif
void algorithm_coord_EdgeExpand_BigFinger(void)
{
	int l, c, r, apply_r, apply_c, MaxSumTB = 0, MaxSumLR = 0;
	int32_t _d,_d1,_d2;
	uint32_t TmpExtStrength = 0;
	uint16_t TmpBigFingerEdgeExpandParam2_LR,TmpBigFingerEdgeExpandParam2_TB;
	tLabelInfo_t	*temp_label = &thisInfo->tLabel;	
#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN	
	int TB_d2 = 0, LR_d2=0;
#endif
	
	for(l=temp_label->ucNum;l--;)
	{
		if( temp_label->tTable[l].ulStrength )
		{
			if(bContiFlag[0] && temp_label->tTable[l].tMaxCell.r > 1)bContiFlag[0]=0;
			if(temp_label->tTable[l].tMaxCell.r <= 1 || bContiFlag[0]){
				sum_r = 0;
				for(c=temp_label->tTable[l].tRect.cs; c<=temp_label->tTable[l].tRect.ce; c++)
					sum_r += HAL_READ_DELTA_IMAGE(3, c);
				
				if(sum_r < 100)
				{
					apply_r = -1;
					MaxSumTB = thisModeConf->EdgeExpand.usTopEdgeExpand_MaxD;				
					bContiFlag[0] = 1;
				}
			}

			if(temp_label->tTable[l].tMaxCell.r < ROW_MAX-2 && bContiFlag[1])bContiFlag[1]=0;
			if(temp_label->tTable[l].tMaxCell.r >= ROW_MAX-2 || bContiFlag[1]){
				sum_r = 0;
				for(c=temp_label->tTable[l].tRect.cs; c<=temp_label->tTable[l].tRect.ce; c++)
					sum_r += HAL_READ_DELTA_IMAGE(ROW_MAX-4, c);
				
				if(sum_r < 100)
				{
					apply_r = ROW_MAX;
					MaxSumTB = thisModeConf->EdgeExpand.usBottomEdgeExpand_MaxD;				
					bContiFlag[1] = 1;
				}
			}
			
			if(temp_label->tTable[l].tMaxCell.c > 1 && bContiFlag[2])bContiFlag[2]=0;
			if(temp_label->tTable[l].tMaxCell.c <= 1 || bContiFlag[2]){
				sum_c = 0;
				for(r=temp_label->tTable[l].tRect.rs; r<=temp_label->tTable[l].tRect.re; r++)
					sum_c += HAL_READ_DELTA_IMAGE(r, 3);
				
				if(sum_c < 100)
				{
					apply_c = -1;
					MaxSumLR = thisModeConf->EdgeExpand.usLeftEdgeExpand_MaxD;				
					bContiFlag[2] = 1;
				}
			}
			
			if(temp_label->tTable[l].tMaxCell.c < COL_MAX-2 && bContiFlag[3])bContiFlag[3]=0;
			if(temp_label->tTable[l].tMaxCell.c >= COL_MAX-2 || bContiFlag[3]){
				sum_c = 0;
				for(r=temp_label->tTable[l].tRect.rs; r<=temp_label->tTable[l].tRect.re; r++)
					sum_c += HAL_READ_DELTA_IMAGE(r, COL_MAX-4);
				
				if(sum_c < 100)
				{
					apply_c = COL_MAX;
					MaxSumLR = thisModeConf->EdgeExpand.usRightEdgeExpand_MaxD;				
					bContiFlag[3] = 1;
				}
			}
			
			if(MaxSumTB && !MaxSumLR)
			{
				if(temp_label->tTable[l].tMaxCell.c <= 2){MaxSumLR = thisModeConf->EdgeExpand.usLeftEdgeExpand_MaxD;apply_c=-1;}
				else if(temp_label->tTable[l].tMaxCell.c >= COL_MAX-3){MaxSumLR = thisModeConf->EdgeExpand.usRightEdgeExpand_MaxD;apply_c=COL_MAX;}
			}
			else if(!MaxSumTB && MaxSumLR)
			{
				if(temp_label->tTable[l].tMaxCell.r <= 2){MaxSumTB = thisModeConf->EdgeExpand.usTopEdgeExpand_MaxD;apply_r=-1;}
				else if(temp_label->tTable[l].tMaxCell.r >= ROW_MAX-3){MaxSumTB = thisModeConf->EdgeExpand.usBottomEdgeExpand_MaxD;apply_r=ROW_MAX;}				
			}
			
			if(MaxSumTB || MaxSumLR)
			{
				TmpExtStrength = temp_label->tTable[l].ulExtStrength;
				TmpBigFingerEdgeExpandParam2_TB = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2;
				TmpBigFingerEdgeExpandParam2_LR = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2;
				if(MaxSumTB && MaxSumLR)
				{
					if(apply_r == -1)
					{
						if(apply_c == -1)
						{
							sum_TB = HAL_READ_DELTA_IMAGE(0,3);
							sum_TB += HAL_READ_DELTA_IMAGE(0,4);
							sum_TB += HAL_READ_DELTA_IMAGE(1,3);
							sum_TB += HAL_READ_DELTA_IMAGE(1,4);
							sum_LR = HAL_READ_DELTA_IMAGE(3,0);
							sum_LR += HAL_READ_DELTA_IMAGE(3,1);
							sum_LR += HAL_READ_DELTA_IMAGE(4,0);
							sum_LR += HAL_READ_DELTA_IMAGE(4,1);
							
//							sum_Cr = 0;
//							Cr_size = 0;
//							for(c = 0; c<=3; c++)
//							{
//								_d = HAL_READ_DELTA_IMAGE(0,c);
//								sum_Cr += _d;
//								if(_d > 50+dbg_coord[26])Cr_size++;
//							}
//							for(r = 1; r<=3; r++)
//							{
//								_d = HAL_READ_DELTA_IMAGE(r,0);
//								sum_Cr += _d;
//								if(_d > 50+dbg_coord[26])Cr_size++;
//							}														
						}
						else
						{
							sum_TB = HAL_READ_DELTA_IMAGE(0,COL_MAX-5);
							sum_TB += HAL_READ_DELTA_IMAGE(0,COL_MAX-4);
							sum_TB += HAL_READ_DELTA_IMAGE(1,COL_MAX-5);
							sum_TB += HAL_READ_DELTA_IMAGE(1,COL_MAX-4);
							sum_LR = HAL_READ_DELTA_IMAGE(3,COL_MAX-2);
							sum_LR += HAL_READ_DELTA_IMAGE(3,COL_MAX-1);
							sum_LR += HAL_READ_DELTA_IMAGE(4,COL_MAX-2);
							sum_LR += HAL_READ_DELTA_IMAGE(4,COL_MAX-1);
							
//							sum_Cr = 0;
//							Cr_size = 0;
//							for(c = 1; c<=4; c++)
//							{
//								_d = HAL_READ_DELTA_IMAGE(0,COL_MAX-c);
//								sum_Cr += _d;
//								if(_d > 50+dbg_coord[26])Cr_size++;
//							}
//							for(r = 1; r<=3; r++)
//							{
//								_d = HAL_READ_DELTA_IMAGE(r,COL_MAX-1);
//								sum_Cr += _d;
//								if(_d > 50+dbg_coord[26])Cr_size++;
//							}
						}
					}
					else
					{
						if(apply_c == -1)
						{
							sum_TB = HAL_READ_DELTA_IMAGE(ROW_MAX-2,3);
							sum_TB += HAL_READ_DELTA_IMAGE(ROW_MAX-2,4);
							sum_TB += HAL_READ_DELTA_IMAGE(ROW_MAX-1,3);
							sum_TB += HAL_READ_DELTA_IMAGE(ROW_MAX-1,4);
							sum_LR = HAL_READ_DELTA_IMAGE(ROW_MAX-5,0);
							sum_LR += HAL_READ_DELTA_IMAGE(ROW_MAX-5,1);
							sum_LR += HAL_READ_DELTA_IMAGE(ROW_MAX-4,0);
							sum_LR += HAL_READ_DELTA_IMAGE(ROW_MAX-4,1);
							
//							sum_Cr = 0;
//							Cr_size = 0;
//							for(c = 0; c<=3; c++)
//							{
//								_d = HAL_READ_DELTA_IMAGE(ROW_MAX-1,c);
//								sum_Cr += _d;
//								if(_d > 50+dbg_coord[26])Cr_size++;
//							}
//							for(r = 2; r<=4; r++)
//							{
//								_d = HAL_READ_DELTA_IMAGE(ROW_MAX-r,0);
//								sum_Cr += _d;
//								if(_d > 50+dbg_coord[26])Cr_size++;
//							}
						}
						else
						{
							sum_TB = HAL_READ_DELTA_IMAGE(ROW_MAX-2,COL_MAX-5);
							sum_TB += HAL_READ_DELTA_IMAGE(ROW_MAX-2,COL_MAX-4);
							sum_TB += HAL_READ_DELTA_IMAGE(ROW_MAX-1,COL_MAX-5);
							sum_TB += HAL_READ_DELTA_IMAGE(ROW_MAX-1,COL_MAX-4);
							sum_LR = HAL_READ_DELTA_IMAGE(ROW_MAX-5,COL_MAX-2);
							sum_LR += HAL_READ_DELTA_IMAGE(ROW_MAX-5,COL_MAX-1);
							sum_LR += HAL_READ_DELTA_IMAGE(ROW_MAX-4,COL_MAX-2);
							sum_LR += HAL_READ_DELTA_IMAGE(ROW_MAX-4,COL_MAX-1);
							
//							sum_Cr = 0;
//							Cr_size = 0;
//							sum_Cr = 0;
//							Cr_size = 0;
//							for(c = 1; c<=4; c++)
//							{
//								_d = HAL_READ_DELTA_IMAGE(ROW_MAX-1,COL_MAX-c);
//								sum_Cr += _d;
//								if(_d > 50+dbg_coord[26])Cr_size++;
//							}
//							for(r = 2; r<=4; r++)
//							{
//								_d = HAL_READ_DELTA_IMAGE(ROW_MAX-r,COL_MAX-1);
//								sum_Cr += _d;
//								if(_d > 50+dbg_coord[26])Cr_size++;
//							}
						}
					}

					//if(sum_Cr > 500+dbg_coord[27] && Cr_size >= 5+dbg_coord[28])
					{
						if(abs(sum_TB - sum_LR) < 60 || ((temp_label->tValidRect[l].re - temp_label->tValidRect[l].rs <= 2) && (temp_label->tValidRect[l].ce - temp_label->tValidRect[l].cs <= 2)))  
						{
							if(apply_r == -1)
							{
								if(apply_c == -1)
								{
									TmpBigFingerEdgeExpandParam2_LR = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(62);
									TmpBigFingerEdgeExpandParam2_TB = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(62);
								}
								else
								{
									TmpBigFingerEdgeExpandParam2_LR = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(62);
									TmpBigFingerEdgeExpandParam2_TB = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(62);	
								}								
							}
							else
							{
								if(apply_c == -1)
								{
									TmpBigFingerEdgeExpandParam2_LR = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(62);
									TmpBigFingerEdgeExpandParam2_TB = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(62);
								}
								else
								{
									TmpBigFingerEdgeExpandParam2_LR = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(62);
									TmpBigFingerEdgeExpandParam2_TB = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(62);	
								}
							}
						}
						else
						{
							if(sum_LR > sum_TB)
							{
								TmpBigFingerEdgeExpandParam2_LR = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(30);
								TmpBigFingerEdgeExpandParam2_TB = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(10);
							}
							else 
							{
								TmpBigFingerEdgeExpandParam2_TB = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(30);
								TmpBigFingerEdgeExpandParam2_LR = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam2-(10);
							}	
						}
					}
//					else
//					{
//						MaxSumTB = MaxSumLR = 0;
//					}
				}
			}
			
			if(MaxSumTB > 0)
			{
				_d =_d1 =_d2 = 0;
				_d = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam1-temp_label->tTable[l].sMaxCellVal;
				_d = _d*_d;
				_d1 = (temp_label->usValidCellCnt[l]*TmpExtStrength*(temp_label->tTable[l].tRect.ce-temp_label->tTable[l].tRect.cs))/TmpBigFingerEdgeExpandParam2_TB;				
				_d1 = _d1*_d1;
				if(_d1 > 0)
				{
					_d = _d/_d1;
					_d1 = MAX(0,(int)(thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam3-TmpExtStrength));
					_d2 = MaxSumTB  - _d;// + _d1;
				}
					
				if(_d2<0)_d2=0;
				temp_label->tTable[l].tCoord.x	+= (float)temp_label->tTable[l].tCoord.x / TmpExtStrength * _d2;
				temp_label->tTable[l].tCoord.y	+= apply_r *_d2;
				temp_label->tTable[l].ulExtStrength += _d2;				

#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN				
				TB_d2 = _d2;
				if(_d2>100)
				{
					if(bReportDelayFlag && _d2>300)
					{
						bReportDelayFlag = 0;
						ucReportDelayCnt = 0;
					}
					
					if(l == 0 && temp_label->ucNum == 1 && algorithm_coord_IsEdgeArea(&thisInfo->tCoord.tFirstPos.tXY[0],128))						
					{
						if(apply_r == -1)
						{
							if(thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop && !bBigFingerEdgeTestEn[0])	
							{
								bBigFingerEdgeTestFlag[0] = 1;
								bBigFingerEdgeTestEn[0] = 1;
							}
						}
						else
						{
							if(thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom && !bBigFingerEdgeTestEn[1])
							{								
								bBigFingerEdgeTestFlag[1] = 1;
								bBigFingerEdgeTestEn[1] = 1;
							}
						}
						
						if(thisModeConf->EdgeExpand.usBigFingerEdgeTest_MoveEventTHD_Y)
							ucBigFingerEdgeTest_MoveEventTHD_Change = 1;
						
						if(ucBigFingerEdgeTest_MoveEventTHD_Change == 1 && _d2>120)
							ucBigFingerEdgeTest_MoveEventTHD_Change = 2;
					}
				}
#endif
			}
			
			if(MaxSumLR > 0)
			{	
				_d =_d1 =_d2 = 0;
				_d = thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam1-temp_label->tTable[l].sMaxCellVal;
				_d = _d*_d;
				_d1 = (temp_label->usValidCellCnt[l]*TmpExtStrength*(temp_label->tTable[l].tRect.re-temp_label->tTable[l].tRect.rs))/TmpBigFingerEdgeExpandParam2_LR;				
				_d1  = _d1*_d1;	
				if(_d1 > 0)
				{					
					_d = _d/_d1;
					_d1 = MAX(0,(int)(thisModeConf->EdgeExpand.usBigFingerEdgeExpandParam3-TmpExtStrength));
					_d2 = MaxSumLR  - _d;// + _d1;
				}
				
				if(_d2<0)_d2=0;					
				temp_label->tTable[l].tCoord.x	+= apply_c * _d2;
				temp_label->tTable[l].tCoord.y	+= (float)temp_label->tTable[l].tCoord.y / TmpExtStrength *_d2;
				temp_label->tTable[l].ulExtStrength += _d2;

#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN					
				LR_d2 = _d2;
				if(_d2>100)
				{
					if(bReportDelayFlag && _d2>300)
					{
						bReportDelayFlag = 0;
						ucReportDelayCnt = 0;
					}
					
					if(l == 0 && temp_label->ucNum == 1 && algorithm_coord_IsEdgeArea(&thisInfo->tCoord.tFirstPos.tXY[0],128))
					{							
						if(apply_c == -1)
						{
							if(thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft && !bBigFingerEdgeTestEn[2])	
							{
								bBigFingerEdgeTestFlag[2] = 1;
								bBigFingerEdgeTestEn[2] = 1;
							}
						}
						else
						{
							if(thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight && !bBigFingerEdgeTestEn[3])
							{								
								bBigFingerEdgeTestFlag[3] = 1;
								bBigFingerEdgeTestEn[3] = 1;
							}
						}
						
						if(thisModeConf->EdgeExpand.usBigFingerEdgeTest_MoveEventTHD_X)
							ucBigFingerEdgeTest_MoveEventTHD_Change = 1;
						
						if(ucBigFingerEdgeTest_MoveEventTHD_Change == 1 && _d2>120)
							ucBigFingerEdgeTest_MoveEventTHD_Change = 2;											
					}
				}
#endif
			}
			
#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN			
			if(ucBigFingerEdgeTest_MoveEventTHD_Change==2 && LR_d2<100 && TB_d2<100)
				ucBigFingerEdgeTest_MoveEventTHD_Change = 3;
#endif
		}	
	}
	
	if(temp_label->ucValidNum == 0)
	{
		bContiFlag[0] = bContiFlag[1] = bContiFlag[2] = bContiFlag[3] = 0;
	}
}
#endif

int max_d = 100;
void algorithm_label_EdgeExpand_Finger(int mode)
{
    uint8_t rLabel_val;
	int l, c, r, apply_r, apply_c, search_r = -1, search_c = -1, search_c1,search_r1, tmp, edge_sum = 0;
	uint16_t offset_r = 0, offset_c = 0, scale_r = 0, scale_c = 0;
	int32_t _d,_d1,_d2;	
	tLabelInfo_t	*temp_label;
	
	if(thisInfo->WinCertMode > 0)
		return;
	
	if(mode != FULL_MODE)
	{
		temp_label = &thisInfo->tLabel_local;
	}
	else
	{
		temp_label = &thisInfo->tLabel;
	}

	for(l=temp_label->ucNum;l--;)
	{
		if( temp_label->tTable[l].ulStrength )
		{
			search_r = -1, search_c = -1;
			if(temp_label->tTable[l].tMaxCell.r <= 1){
				search_r = 0, search_r1 = 1, apply_r = -1;
				offset_r = thisModeConf->EdgeExpand.usTopEdgeExpand_Offset;
				scale_r  = thisModeConf->EdgeExpand.usTopEdgeExpand_Scale;
			}

			if(temp_label->tTable[l].tMaxCell.r >= ROW_MAX-2){
				search_r = ROW_MAX-1, search_r1 = ROW_MAX-2, apply_r = ROW_MAX;
				offset_r = thisModeConf->EdgeExpand.usBottomEdgeExpand_Offset;
				scale_r	 = thisModeConf->EdgeExpand.usBottomEdgeExpand_Scale;
			}

			if(temp_label->tTable[l].tMaxCell.c <= 1){
				search_c = 0, search_c1 = 1, apply_c = -1;
				offset_c = thisModeConf->EdgeExpand.usLeftEdgeExpand_Offset;
				scale_c  = thisModeConf->EdgeExpand.usLeftEdgeExpand_Scale;
			}

			if(temp_label->tTable[l].tMaxCell.c >= COL_MAX-2){
				search_c = COL_MAX-1, search_c1 = COL_MAX-2, apply_c = COL_MAX;
				offset_c = thisModeConf->EdgeExpand.usRightEdgeExpand_Offset;
				scale_c  = thisModeConf->EdgeExpand.usRightEdgeExpand_Scale;
			}
			
			if(thisModeConf->EdgeExpand.usLabelEdgeExpandMode == 1)
			{
				if(search_r == -1 && search_c == -1)
				{
					if(max_d < temp_label->tTable[l].ulStrength)
					{
						max_d = temp_label->tTable[l].ulStrength;
					}
				}
				else if(max_d == 0)
				{
					max_d = temp_label->tTable[l].ulStrength + 100;
				}
			}
			
			if(search_r != -1)													//Top, bottom edge
			{
				_d =_d1 =_d2 = 0;
				
				if(!(offset_r==0 && scale_r==0))
				{
					edge_sum = 0;
					for(c = temp_label->tTable[l].tRect.cs; c <= temp_label->tTable[l].tRect.ce; c++)
					{
						if(HAL_READ_LABEL_IMAGE(search_r, c) == l+1){
							edge_sum += HAL_READ_DELTA_IMAGE(search_r, c);
						}
					}
					
#if USED_ALGORITHM_FOR_MNT				
					IsDrawing = NO;
					for(pl=0;pl<ptMemConf->iMaxTouch_;pl++)
					{
						if(temp_coord->DrawingFlag[pl] && temp_coord->tOrgPastPos[0].vusS[pl]>0)
						{
							if(algorithm_coord_calc_distance(temp_pos, temp_coord->tOrgPastPos[0].tXY[pl]) < (2<<POS_BOOST_SHIFT_))
								IsDrawing = YES;
						}
					}
#endif /* USED_ALGORITHM_FOR_MNT */	
							
					for(c = temp_label->tTable[l].tRect.cs; c <= temp_label->tTable[l].tRect.ce; c++)	//Column
					{
						rLabel_val = HAL_READ_LABEL_IMAGE(search_r, c);
						
						if(rLabel_val == l+1)
						{
							_d2 = 0;
							
							if(mode == LOCAL_FINGER_MODE)
							{
								_d = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(search_r, c);
								_d1 = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(search_r1, c);
							}
							else
							{
								_d = HAL_READ_DELTA_IMAGE(search_r, c);
								_d1 = HAL_READ_DELTA_IMAGE(search_r1, c);
							}
							
							if(_d1 < 0)	_d1 = 0;
							if(max_d < _d + _d1)	max_d = _d + _d1;
							
							if(_d > _d1)
							{
								tmp = max_d - (_d + _d1);
								if(tmp < 0)	tmp = 0;
								
#if USED_ALGORITHM_FOR_MNT				
								if(IsDrawing)	tmp<<=3;
#endif /* USED_ALGORITHM_FOR_MNT */	
								
								_d2 = tmp * _d * (_d - _d1) / (edge_sum * (_d + _d1));
								_d2 = ((_d2 * scale_r)>>7) - offset_r;
							}
							
							temp_label->tTable[l].tCoord.x	+= c * _d2;
							temp_label->tTable[l].tCoord.y	+= apply_r * _d2;
							temp_label->tTable[l].ulExtStrength += _d2;
						}
					}
				}
			}
			
			if(search_c != -1)													//Left, right edge
			{
				_d =_d1 =_d2 = 0;
				
				if(!(offset_c==0 && scale_c==0))
				{
					edge_sum = 0;
					for(r = temp_label->tTable[l].tRect.rs; r <= temp_label->tTable[l].tRect.re; r++)
					{
						if(HAL_READ_LABEL_IMAGE(r, search_c) == l+1){
							edge_sum += HAL_READ_DELTA_IMAGE(r, search_c);
						}
					}
					
#if USED_ALGORITHM_FOR_MNT			
					IsDrawing = NO;
					for(pl=0;pl<ptMemConf->iMaxTouch_;pl++)
					{
						if(temp_coord->DrawingFlag[pl] && temp_coord->tOrgPastPos[0].vusS[pl]>0)
						{
							if(algorithm_coord_calc_distance(temp_pos, temp_coord->tOrgPastPos[0].tXY[pl]) < (2<<POS_BOOST_SHIFT_))
								IsDrawing = YES;
						}
					}	
#endif /* USED_ALGORITHM_FOR_MNT */	
					
					for(r = temp_label->tTable[l].tRect.rs; r <= temp_label->tTable[l].tRect.re; r++)	//Row
					{
						rLabel_val = HAL_READ_LABEL_IMAGE(r, search_c);
						
						if(rLabel_val == l+1)
						{
							_d2 = 0;
							
							if(mode == LOCAL_FINGER_MODE)
							{
								_d = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(r, search_c);
								_d1 = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(r, search_c1);
							}
							else
							{
								_d = HAL_READ_DELTA_IMAGE(r, search_c);
								_d1 = HAL_READ_DELTA_IMAGE(r, search_c1);
							}
							
							if(_d1 < 0)	_d1 = 0;
							if(max_d < _d + _d1)	max_d = _d + _d1;
							
							if(_d > _d1)
							{
								tmp = max_d - (_d + _d1);
								if(tmp < 0)	tmp = 0;
								
#if USED_ALGORITHM_FOR_MNT			
								if(IsDrawing)	tmp<<=3;
#endif /* USED_ALGORITHM_FOR_MNT */	
								
								_d2 = tmp * _d * (_d - _d1) / (edge_sum * (_d + _d1));
								_d2 = ((_d2 * scale_c)>>7) - offset_c;
							}

							temp_label->tTable[l].tCoord.x	+= apply_c * _d2;
							temp_label->tTable[l].tCoord.y	+= r *_d2;
							temp_label->tTable[l].ulExtStrength += _d2;
						}
					}
				}
			}
		}	
	}
	
	if(temp_label->ucValidNum == 0)
	{
		if(thisModeConf->EdgeExpand.usLabelEdgeExpandMode == 0)
			max_d = 100;
		else if(thisModeConf->EdgeExpand.usLabelEdgeExpandMode == 1)
			max_d = 0;
		else
			max_d = thisModeConf->EdgeExpand.usLabelEdgeExpandMode;
	}
}

#if (FINGER_Latency_Test_ByFW == YES)
int g_speed,g_Latency;
int pre_speed[50] = {0,};
int pre_Latency[50] = {0,};
void algorithm_coord_latency_cal_test(void)
{
	tCoordInfo_t 	*temp_coord;
	int dist,i,speed,Latency;
	temp_coord = &thisInfo->tCoord;
//	int taget_speed = 200; // ex: 200 = 200mm/s
	
	if(temp_coord->tOrgPos.vusS[0] > 0 && temp_coord->tOrgPastPos[0].vusS[0] > 0 && temp_coord->tOrgPastPos[1].vusS[0] > 0 && temp_coord->tOrgPastPos[2].vusS[0] > 0)
	{
		speed = 0;
		dist = algorithm_coord_calc_distance(temp_coord->tOrgPos.tXY[0],temp_coord->tOrgPastPos[0].tXY[0]);
		dist = MIN(FPITCH_X*1000,FPITCH_Y*1000) * dist/UNIT_DIST;
		speed = (int)((double)dist/(double)8.34);
		
		dist = algorithm_coord_calc_distance(temp_coord->tOrgPastPos[0].tXY[0],temp_coord->tOrgPastPos[1].tXY[0]);
		dist = MIN(FPITCH_X*1000,FPITCH_Y*1000) * dist/UNIT_DIST;
		speed += (int)((double)dist/(double)8.34);
		
		dist = algorithm_coord_calc_distance(temp_coord->tOrgPastPos[1].tXY[0],temp_coord->tOrgPastPos[2].tXY[0]);
		dist = MIN(FPITCH_X*1000,FPITCH_Y*1000) * dist/UNIT_DIST;
		speed += (int)((double)dist/(double)8.34);;
		
		speed /= 3;
		
		for(i = 0; i< 49; i++)pre_speed[i+1] = pre_speed[i];
		pre_speed[0] = speed;
		speed = 0;
		for(i = 0; i< 50; i++)speed += pre_speed[i];
		g_speed = speed/50;		
		
		//if(taget_speed-20<=speed && speed<=taget_speed+20)
		{
			dist = algorithm_coord_calc_distance(temp_coord->tOrgPos.tXY[0],temp_coord->tPos.tXY[0]);
			dist = MIN(FPITCH_X*1000,FPITCH_Y*1000) * dist/UNIT_DIST;
			Latency = dist*100/g_speed + 833; // ex : 2000 = 20.00 ms
			
			for(i = 0; i< 49; i++)pre_Latency[i+1] = pre_Latency[i];
			pre_Latency[0] = Latency;
			Latency = 0;
			for(i = 0; i< 50; i++)Latency += pre_Latency[i];
			g_Latency = Latency/50;	
		}
	}
}
#endif

void algorithm_coord_process(int mode)
{
	//Edge_Expand_Finger LYB_190109
	algorithm_label_EdgeExpand_Finger(mode);

#if BIG_FINGER_EDGE_EXPAND_ALGO_EN
	algorithm_coord_EdgeExpand_BigFinger(); 
#endif
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Algorithm Coord. Calculation
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	algorithm_coord_calc_pos(mode);

#if WinCertAssistance_En	
	if(thisModeConf->Coord.ucWinCertAssistance == 5)
		algorithm_coord_drawing_assistance(mode);
#endif
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Algorithm Coord. Tracking
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    algorithm_coord_tracking_pos(mode);
	
    algorithm_coord_smoothing_pos(mode);
	
	if(thisModeConf->CoordEdge.usOutInDrawEdgeTh)
		algorithm_coord_OutInDrawing();
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Algorithm Coord. Post-Procssing
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	if(thisModeConf->CoordEdge.cPostProcessEndMargin == 0)
//		algorithm_coord_PostProcess(mode);
//	else
		algorithm_coord_PostProcess_1();
}
