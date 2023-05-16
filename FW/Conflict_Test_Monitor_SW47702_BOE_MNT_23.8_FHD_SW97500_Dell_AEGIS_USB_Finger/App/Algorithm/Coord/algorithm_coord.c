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


static const tAlgorithmCommonConf_t * thisCommonConf = NULL;
static const tAlgorithmModeConf_t * thisModeConf = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;
#if USED_NOISE_HOPPING_FREQ
static tAppInfo_t * ptAppInfo = NULL;
#endif
//static const tModuleCommonConf_t * _ptModuleCommonConf = NULL;
int16_t Gradient[22] = {0,};
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
uint8_t ProjectionEnable[LOOSE_POSBUF_] = {0};
uint8_t DrumStep[LOOSE_POSBUF_] = {0};

void algorithm_coord_init(void)
{
	int l;

	thisCommonConf = algorithm_GetCommonConfig();
	thisModeConf   = algorithm_GetModeConfig();
	thisInfo       = algorithm_GetInfo();
#if USED_NOISE_HOPPING_FREQ
	ptAppInfo      = app_GetInfo();
#endif
//	_ptModuleCommonConf = module_GetCommonConfig();
//	algorithm_coord_init_param();

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

    thisInfo->tCoord.iXExpandStart = 1*UNIT_DIST;
    thisInfo->tCoord.iYExpandStart = 1*UNIT_DIST;

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

	thisInfo->tCoord.slScaledMoveDistThd = (thisModeConf->Coord.usMoveDistanceThd << POS_BOOST_SHIFT_);

}

void algorithm_coord_init_param(void)
{
	thisModeConf   = algorithm_GetModeConfig();
//	thisInfo->tCoord.slScaledMoveDistThd = (thisModeConf->Coord.usMoveDistanceThd << POS_BOOST_SHIFT_);
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
uint8_t gReleaseCnt[POSBUF_] = {0,};
void algorithm_coord_calc_pos(int mode)
{
	int l,pl;
	int r,c;

	tLabelInfo_t	*temp_label;
	tCoordInfo_t 	*temp_coord;

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
																			+ (((int)(temp_label->tTable[l].sMaxCellVal) * (coef_x+coef_y) )>>(POS_BOOST_SHIFT_+3)) );
			}
			
			temp_coord->tTempPos.vusR[temp_coord->tTempPos.sFinger_]   = temp_label->tTable[l].usCellNum;
			temp_coord->tTempPos.vusS[temp_coord->tTempPos.sFinger_]   = temp_label->tTable[l].ulStrength;
			temp_coord->tTempPos.rect[temp_coord->tTempPos.sFinger_]   = temp_label->tTable[l].tRect;
			temp_coord->tTempPos.MaxDelta[temp_coord->tTempPos.sFinger_] = temp_label->tTable[l].sMaxCellVal;

			temp_coord->cRemap[temp_coord->tTempPos.sFinger_] = temp_coord->tTempPos.sFinger_;

			temp_coord->tTempPos.sFinger_++;
		}
	}
	
	if(thisModeConf->Palm.ucPalmDrawingOn && thisInfo->bIsPalm){
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
				
				//TEST_CODE
//				HAL_WRITE_DELTA_IMAGE(0,temp_coord->tTempPos.sFinger_,temp_coord->tTempPos.rect[temp_coord->tTempPos.sFinger_].cs);
//				HAL_WRITE_DELTA_IMAGE(1,temp_coord->tTempPos.sFinger_,temp_coord->tTempPos.rect[temp_coord->tTempPos.sFinger_].ce);
//				HAL_WRITE_DELTA_IMAGE(2,temp_coord->tTempPos.sFinger_,temp_coord->tTempPos.rect[temp_coord->tTempPos.sFinger_].rs);
//				HAL_WRITE_DELTA_IMAGE(3,temp_coord->tTempPos.sFinger_,temp_coord->tTempPos.rect[temp_coord->tTempPos.sFinger_].re);

				temp_coord->cRemap[temp_coord->tTempPos.sFinger_] = temp_coord->tTempPos.sFinger_;
				
				temp_coord->tTempPos.sFinger_++;
			}
		}
		return;
	}

#if WinCertAssistance_En	
	int i,cl,match_cl,match_pl;
//	int _d;
//	uint32_t ulStrength = 0;
//	uint8_t PrevFinger_ = 0;
	int MaxDist = 0, dist = 0, MinDist = 0;
	uint8_t MaxTouchNum = 0;
	
	if(thisModeConf->Coord.ucWinCertAssistance)
	{
		if(temp_coord->tTempPos.sFinger_ > 1)
		{
			int cl,pl;
			for(cl=0;cl<temp_coord->tTempPos.sFinger_;cl++){
				for(pl=0;pl<temp_coord->tTempPos.sFinger_;pl++){
					if(cl == pl)	continue;
					if(abs(temp_coord->tTempPos.tXY[cl].x - temp_coord->tTempPos.tXY[pl].x)+abs(temp_coord->tTempPos.tXY[cl].y - temp_coord->tTempPos.tXY[pl].y) < (3<<POS_BOOST_SHIFT_) ){
						temp_label->LabelSplitCnt++;
						break;
					}
					
				}
			}
		}

		if(temp_label->LabelSplitCnt)
			temp_label->LabelSplitFrmCnt++;
		else if(temp_label->LabelSplitFrmCnt)
			temp_label->LabelSplitFrmCnt--;
		
	}
	
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
			MinDist = (thisModeConf->Coord.usCenterMatchDistanceThd<<POS_BOOST_SHIFT_);
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
				
				//TEST_CODE_190410
//				pre_x = 0, pre_y = 0;
//				for(i=0;i<temp_coord->tPastPos[0].sFinger_;i++){
//					pre_x += temp_coord->tPastPos[0].tXY[i].x;
//					pre_y += temp_coord->tPastPos[0].tXY[i].y;
//				}
//				if(temp_coord->tPastPos[0].sFinger_){
//					pre_x /= temp_coord->tPastPos[0].sFinger_;
//					pre_y /= temp_coord->tPastPos[0].sFinger_;
//				}
//				
//				curr_x = 0, curr_y = 0;
//				for(j=0;j<temp_coord->tTempPos.sFinger_;j++){
//					curr_x += temp_coord->tTempPos.tXY[j].x;
//					curr_y += temp_coord->tTempPos.tXY[j].y;
//				}
//				if(temp_coord->tTempPos.sFinger_){
//					curr_x /= temp_coord->tTempPos.sFinger_;
//					curr_y /= temp_coord->tTempPos.sFinger_;
//				}
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
					if( (temp_coord->tPastPos[0].vusS[j] && temp_coord->tOrgPastPos[1].vusS[j] && !thisModeConf->Coord.ucFullFingerInterpolation_On)
					|| (temp_coord->tPastPos[0].vusS[j] && temp_coord->tOrgPastPos[2].vusS[j] && thisModeConf->Coord.ucFullFingerInterpolation_On) )
					{
						tXY_t pred_pos;
						if(!thisModeConf->Coord.ucFullFingerInterpolation_On)
						{
							pred_pos.x = (temp_coord->tOrgPastPos[0].tXY[j].x << 1) - temp_coord->tOrgPastPos[1].tXY[j].x;
							pred_pos.y = (temp_coord->tOrgPastPos[0].tXY[j].y << 1) - temp_coord->tOrgPastPos[1].tXY[j].y;
						}
						else
						{
							pred_pos.x = (temp_coord->tOrgPastPos[0].tXY[j].x << 1) - temp_coord->tOrgPastPos[2].tXY[j].x;
							pred_pos.y = (temp_coord->tOrgPastPos[0].tXY[j].y << 1) - temp_coord->tOrgPastPos[2].tXY[j].y;
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
void algorithm_coord_drawing_assistance(int mode)
{
	int l,i,j;
//	int r,c,_d;
//	uint32_t ulStrength = 0;
	tXY_t CoordAry[5], CoordTmp;//, PredCoord[5],ProjectionVector;
	uint8_t ColMinLabelIdx=0,  ColMaxLabelIdx=0,  RowMinLabelIdx=0,  RowMaxLabelIdx=0;
	int ColMin=INT32_MAX, ColMax=0, RowMin=INT32_MAX, RowMax=0, Width=0, Height=0;
	int idx,JitterSum=0;

//	tLabelInfo_t	*temp_label;
	tCoordInfo_t 	*temp_coord;

	{
		temp_coord = &thisInfo->tCoord;
//		temp_label = &thisInfo->tLabel;
	}
	
	if(temp_coord->tTempPos.sFinger_ == 0){
		thisInfo->WinCertMode = 0;
		thisInfo->DrawingDirection = 0;
		thisInfo->WinCertTrackingDist = 0;
		thisInfo->TouchNumCnt = 0;
	}
	else if(temp_coord->tTempPos.sFinger_ == temp_coord->tOrgPastPos[0].sFinger_)
		thisInfo->TouchNumCnt++;
	else
		thisInfo->TouchNumCnt = 0;
	
	//detect win cert state
//	if( temp_coord->tTempPos.sFinger_ == 5 && thisInfo->WinCertMode == 0 &&
//	   (thisInfo->tDelta.tValidRect.re - thisInfo->tDelta.tValidRect.rs + 1) < (thisModeConf->Coord.usCenterMatchDistanceThd << 1) && (thisInfo->tDelta.tValidRect.ce - thisInfo->tDelta.tValidRect.cs + 1) < (thisModeConf->Coord.usCenterMatchDistanceThd << 1) )
	if(temp_coord->tTempPos.sFinger_ > 1 && temp_coord->tTempPos.sFinger_ <= 5 && thisInfo->WinCertMode == 0)
	{	
		memcpy(CoordAry, temp_coord->tTempPos.tXY, sizeof(CoordAry));
		for(l = temp_coord->tTempPos.sFinger_; l--;)
		{
			if(temp_coord->tTempPos.tXY[l].x < ColMin)	ColMin = temp_coord->tTempPos.tXY[l].x, ColMinLabelIdx = l;
			if(temp_coord->tTempPos.tXY[l].x > ColMax)	ColMax = temp_coord->tTempPos.tXY[l].x, ColMaxLabelIdx = l;
			if(temp_coord->tTempPos.tXY[l].y < RowMin)	RowMin = temp_coord->tTempPos.tXY[l].y, RowMinLabelIdx = l;
			if(temp_coord->tTempPos.tXY[l].y > RowMax)	RowMax = temp_coord->tTempPos.tXY[l].y, RowMaxLabelIdx = l;
			
		}
		Width = abs(temp_coord->tTempPos.tXY[ColMaxLabelIdx].x - temp_coord->tTempPos.tXY[ColMinLabelIdx].x);
		Height = abs(temp_coord->tTempPos.tXY[RowMaxLabelIdx].y - temp_coord->tTempPos.tXY[RowMinLabelIdx].y);
		
		if(Width > Height){
			CoordTmp = CoordAry[ColMinLabelIdx];
			CoordAry[ColMinLabelIdx] = CoordAry[0];
			CoordAry[0] = CoordTmp;
			
			CoordTmp = CoordAry[ColMaxLabelIdx];
			CoordAry[ColMaxLabelIdx] = CoordAry[1];
			CoordAry[1] = CoordTmp;
			
			for(idx=1; idx<temp_coord->tTempPos.sFinger_;idx++){
				if(CoordAry[idx].x == CoordAry[0].x)
					JitterSum += CoordAry[idx].y - CoordAry[0].y;
				else
					JitterSum += abs(Height - (abs(CoordAry[idx].y - CoordAry[0].y) * Width / abs(CoordAry[idx].x - CoordAry[0].x)));
			}
//			TotalRect = algorithm_merge_rect(temp_coord->tTempPos.rect[ColMinLabelIdx], temp_coord->tTempPos.rect[ColMaxLabelIdx]);
		}
		else{
			CoordTmp = CoordAry[RowMinLabelIdx];
			CoordAry[RowMinLabelIdx] = CoordAry[0];
			CoordAry[0] = CoordTmp;
			
			CoordTmp = CoordAry[RowMaxLabelIdx];
			CoordAry[RowMaxLabelIdx] = CoordAry[1];
			CoordAry[1] = CoordTmp;
			
			for(idx=1; idx<temp_coord->tTempPos.sFinger_;idx++){
				if(CoordAry[idx].y == CoordAry[0].y)
					JitterSum += abs(CoordAry[idx].x - CoordAry[0].x);
				else
					JitterSum += abs(Width - (abs(CoordAry[idx].x - CoordAry[0].x) * Height / abs(CoordAry[idx].y - CoordAry[0].y)));
			}
//			TotalRect = algorithm_merge_rect(temp_coord->tTempPos.rect[RowMinLabelIdx], temp_coord->tTempPos.rect[RowMaxLabelIdx]);
		}
		
		if(JitterSum < 500)
		{
			if( temp_coord->tTempPos.sFinger_ == 5 && thisInfo->WinCertMode == 0 &&
				(thisInfo->tDelta.tValidRect.re - thisInfo->tDelta.tValidRect.rs + 1) < (thisModeConf->Coord.usCenterMatchDistanceThd << 1) && 
				(thisInfo->tDelta.tValidRect.ce - thisInfo->tDelta.tValidRect.cs + 1) < (thisModeConf->Coord.usCenterMatchDistanceThd << 1) )
					thisInfo->WinCertMode = YES;

			if(Width > (Height<<4))				//Horizontal
				thisInfo->DrawingDirection = 1;
			else if(Height > (Width<<4))		//Vertical
				thisInfo->DrawingDirection = 2;
			else
				thisInfo->DrawingDirection = 3;		//Diagonal
		}
	}
	
	if( (thisInfo->tDelta.tValidRect.re - thisInfo->tDelta.tValidRect.rs + 1) >= (thisModeConf->Coord.usCenterMatchDistanceThd +5) ||
		(thisInfo->tDelta.tValidRect.ce - thisInfo->tDelta.tValidRect.cs + 1) >= (thisModeConf->Coord.usCenterMatchDistanceThd +5) )
	{
		thisInfo->WinCertMode = 0;
		thisInfo->DrawingDirection = 0;
	}
	
	if(thisInfo->WinCertMode && temp_coord->tTempPos.sFinger_)
	{
		if(temp_coord->tTempPos.sFinger_ != 5)
		{
			tXY_t Center[2];
			int dist_min = INT32_MAX,tmp;
			//int min_cl, min_pl;
			
			Center[0].x = 0, Center[0].y = 0;
			for(i=0;i<temp_coord->tTempPos.sFinger_;i++){
				Center[0].x += temp_coord->tTempPos.tXY[i].x;
				Center[0].y += temp_coord->tTempPos.tXY[i].y;
			}
			Center[0].x /= temp_coord->tTempPos.sFinger_;
			Center[0].y /= temp_coord->tTempPos.sFinger_;
			
			Center[1].x = 0, Center[1].y = 0;
			for(i=0;i<5;i++){
				Center[1].x +=  temp_coord->tOrgPastPos[0].tXY[i].x;
				Center[1].y +=  temp_coord->tOrgPastPos[0].tXY[i].y;
			}
			Center[1].x /= 5;
			Center[1].y /= 5;
			
			for(i=0;i<temp_coord->tTempPos.sFinger_;i++){
				for(j=0;j<5;j++){
					tmp = algorithm_coord_calc_distance(temp_coord->tTempPos.tXY[i],temp_coord->tOrgPastPos[0].tXY[j]);
					if(tmp < dist_min){
						dist_min = tmp;
//						min_cl = i;
//						min_pl = j;
					}
					
				}
			}
					
			for(i=0;i<POSBUF_;i++){
				temp_coord->tTempPos.vusR[i]   = 0;
				temp_coord->tTempPos.vusS[i]   = 0;
			}
			for(i=0;i<temp_coord->tOrgPastPos[0].sFinger_;i++){
				if(temp_coord->tOrgPastPos[0].vusR[i]>0){
					temp_coord->tTempPos.tXY[i] = temp_coord->tOrgPastPos[0].tXY[i];
	//					temp_coord->tTempPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + ((temp_coord->tTempPos.tXY[i].x - temp_coord->tOrgPastPos[0].tXY[j].x)>>2);
	//					temp_coord->tTempPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + ((temp_coord->tTempPos.tXY[i].y - temp_coord->tOrgPastPos[0].tXY[j].y)>>2);
					
					temp_coord->tTempPos.vusR[i]   = temp_coord->tOrgPastPos[0].vusR[i];
					temp_coord->tTempPos.vusS[i]   = temp_coord->tOrgPastPos[0].vusS[i];
					temp_coord->cRemap[i] = i;
					temp_coord->tTempPos.sFinger_ = temp_coord->tOrgPastPos[0].sFinger_;
				}
			}
		}
	}	
}
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

	tCoordInfo_t 	*temp_coord;
	
	temp_coord = &thisInfo->tCoord;

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

		if( (pos_max.x - pos_min.x) < (thisModeConf->Coord.usCenterMatchDistanceThd << POS_BOOST_SHIFT_)
  		 && (pos_max.y - pos_min.y) < (thisModeConf->Coord.usCenterMatchDistanceThd << POS_BOOST_SHIFT_) )
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
					if(temp_coord->bInterpolation_On)
					{
						Check_vusR = temp_coord->tPastPos[2].vusR[pl];
						UsePastPos = temp_coord->tOrgPastPos[2].tXY[pl];
					}
					else
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
					if(temp_coord->bInterpolation_On)
						Check_vusR = temp_coord->tPastPos[4].vusR[pl];
					else
						Check_vusR = temp_coord->tPastPos[2].vusR[pl];
					
					if( Check_vusR )
					{
						int sPred_x, sPred_y;
						int fPred_x, fPred_y;
						int sub_x1, sub_y1, sub_x2, sub_y2;
						tXY_t pred_pos2;
					
						if(temp_coord->bInterpolation_On)
						{
							fPred_x = temp_coord->tOrgPastPos[4].tXY[pl].x - temp_coord->tOrgPastPos[2].tXY[pl].x;
							fPred_y = temp_coord->tOrgPastPos[4].tXY[pl].y - temp_coord->tOrgPastPos[2].tXY[pl].y;
							sPred_x = temp_coord->tOrgPastPos[2].tXY[pl].x - temp_coord->tOrgPastPos[0].tXY[pl].x;
							sPred_y = temp_coord->tOrgPastPos[2].tXY[pl].y - temp_coord->tOrgPastPos[0].tXY[pl].y;
						}
						else
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
			if(temp_coord->bInterpolation_On)
			{
				Check_vusR = temp_coord->tPastPos[2].vusR[match_pl];
				UsePastPos = temp_coord->tOrgPastPos[2].tXY[match_pl];
			}
			else
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
			if(temp_coord->bInterpolation_On)
				Check_vusR = temp_coord->tPastPos[4].vusR[match_pl];
			else
				Check_vusR = temp_coord->tPastPos[2].vusR[match_pl];

			if( Check_vusR )
			{
				int sPred_x, sPred_y;
				int fPred_x, fPred_y;
				int sub_x1, sub_y1, sub_x2, sub_y2;
				tXY_t pred_pos2;
				
				if(temp_coord->bInterpolation_On)
				{					
					fPred_x = temp_coord->tOrgPastPos[4].tXY[match_pl].x - temp_coord->tOrgPastPos[2].tXY[match_pl].x;
					fPred_y = temp_coord->tOrgPastPos[4].tXY[match_pl].y - temp_coord->tOrgPastPos[2].tXY[match_pl].y;
					sPred_x = temp_coord->tOrgPastPos[2].tXY[match_pl].x - temp_coord->tOrgPastPos[0].tXY[match_pl].x;
					sPred_y = temp_coord->tOrgPastPos[2].tXY[match_pl].y - temp_coord->tOrgPastPos[0].tXY[match_pl].y;
				}
				else
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

#if 0
		if (temp_coord->ucIdMappedCnt[match_pl] == 1)
		{
			iDistanceThd = (thisModeConf->Coord.usFirstMoveDistanceThd << POS_BOOST_SHIFT_);
		}
		else
		{
			iDistanceThd = temp_coord->slScaledMoveDistThd;
			if (temp_coord->lPrevDist[match_pl] > temp_coord->slScaledMoveDistThd)
				iDistanceThd += (temp_coord->lPrevDist[match_pl] * 2);
		}
#endif		
		
		//Set tracking distance
		{
			uint8_t FirstMoveFrameNum = 0;
			if(thisModeConf->Coord.ucFastDrawingMode)
				FirstMoveFrameNum = 2;
			else
				FirstMoveFrameNum = 1;
	//		if (temp_coord->bIsMoving[match_pl] == NO)		//In tracking
			if (temp_coord->ucIdMappedCnt[match_pl] <= FirstMoveFrameNum)
			{
				iDistanceThd = (thisModeConf->Coord.usFirstMoveDistanceThd << POS_BOOST_SHIFT_);
			}
			else
			{
				//Dynamic tracking distance
				if(thisModeConf->Coord.ucDynamicTrackingDistanceMode == 1)
				{
					if(thisInfo->WinCertMode){
						thisInfo->WinCertTrackingDist = MAX(thisInfo->WinCertTrackingDist, (temp_coord->lPrevDist[match_pl]<<3));
						iDistanceThd = MAX( (1<<(POS_BOOST_SHIFT_-1)), thisInfo->WinCertTrackingDist );
					}
					else{
						if(algorithm_coord_IsEdgeArea(&temp_coord->iStopPos[match_pl],0)>0)
							iDistanceThd = MAX( (3<<(POS_BOOST_SHIFT_)), (temp_coord->lPrevDist[match_pl]<<2) );
						else
							iDistanceThd = MAX( (1<<(POS_BOOST_SHIFT_))+(1<<(POS_BOOST_SHIFT_-1)), (temp_coord->lPrevDist[match_pl]<<2) );
						
		//				if(temp_coord->ucIdMappedCnt[match_pl] >= 4)
		//					iDistanceThd = (thisModeConf->Coord.usMoveDistanceThd << POS_BOOST_SHIFT_);
					}
				}
				else if(thisModeConf->Coord.ucDynamicTrackingDistanceMode == 2)
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
					
//					if( (InnerProduct<<1) < S1*S2 || S1 < (thisModeConf->Coord.usDrumTestDist - CosSeta) )
					if( S1 < (thisModeConf->Coord.usDrumTestDist - CosSeta) )
//					if(S1 < (thisModeConf->Coord.usDrumTestDist>>1)  )
					{
//						match_cl = -1;
//						match_pl = -1;
						for(pl = 0; pl < MAX_TOUCH_; pl++)
							lDistanceMap[pl][match_cl] = -1;

						for(cl = 0; cl < temp_coord->tTempPos.sFinger_; cl++)
							lDistanceMap[match_pl][cl] = -1;
						continue;
						
					}
					DrumStep[match_pl] = 2;
				}
			}
		}
//////////////////drum in tracking ends here
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
					if(temp_coord->bInterpolation_On)
					{
						Check_vusR = temp_coord->tPastPos[2].vusR[pl];
						UsePastPos = temp_coord->tOrgPastPos[2].tXY[pl];
					}
					else
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
//				if(mode == FULL_MODE)
//				{
//					pl = thisInfo->tCoord.cRemap[cl];
//					if((thisInfo->tLabel.tTable[pl].ulStrength*100)/thisInfo->tLabel.tTable[pl].ulExtStrength < 70)//77)
//					{
////						thisInfo->tCoord.ucIdMappedCnt[cl] = 0;
////						thisInfo->tCoord.tPos.vusR[cl] = 0;
//						thisInfo->tCoord.tPos.vusS[cl] = 0;
////						continue;
//					}
//				}
				temp_coord->tFirstPos.tXY[cl] = temp_coord->tPos.tXY[cl];
				temp_coord->DrawingFlag[cl] = NO;
				FirstTouchEnable[cl] = NO;
				ProjectionEnable[cl] = NO;
				temp_coord->iStopPos[cl] = temp_coord->tPos.tXY[cl];
				DrumStep[cl] = 0;
			}
			
			if(thisModeConf->Coord.sFirstTouchEnable1Touch > 0)
			{
				if(FirstTouchEnable[cl] == NO){
					int16_t FirstTouchThreshold = 0;

					if(thisInfo->bIsPalm)					FirstTouchThreshold = thisModeConf->Coord.sFirstTouchEnable5Touch;
					else if(temp_coord->tPos.sFinger_ == 1)	FirstTouchThreshold = thisModeConf->Coord.sFirstTouchEnable1Touch;
					else if(temp_coord->tPos.sFinger_ == 2)	FirstTouchThreshold = thisModeConf->Coord.sFirstTouchEnable2Touch;
					else if(temp_coord->tPos.sFinger_ == 3)	FirstTouchThreshold = thisModeConf->Coord.sFirstTouchEnable3Touch;
					else if(temp_coord->tPos.sFinger_ == 4)	FirstTouchThreshold = thisModeConf->Coord.sFirstTouchEnable4Touch;
					else 									FirstTouchThreshold = thisModeConf->Coord.sFirstTouchEnable5Touch;

					if(temp_coord->tPos.vusS[cl] >= FirstTouchThreshold){
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
				
				if(algorithm_coord_IsEdgeArea(&temp_coord->iStopPos[cl],0)>0){
					if(temp_coord->cScreenDebCnt[cl] <= thisModeConf->Coord.ucDebCntEdge)
						temp_coord->tPos.vusS[cl] = 0;
				}
				else{
					if(temp_coord->cScreenDebCnt[cl] <= thisModeConf->Coord.ucDebCntInner)
						temp_coord->tPos.vusS[cl] = 0;
				}
			}
			else 
			{
				if( temp_coord->tPastPos[0].vusS[cl] )
				{
					int lTouchOffThd = thisModeConf->Coord.lTouchOffThd;
				
					if(temp_coord->cScreenDebCnt[cl] < COORD_HISTORY_NUM)
					{
						temp_coord->cScreenDebCnt[cl]++;
					}
				
					if( thisModeConf->Coord.ucMultifingerFirstTouchThDownOffset > 0 && (temp_coord->tPos.sFinger_ > 5 || thisInfo->bIsPalm == YES) ) lTouchOffThd -= ((thisModeConf->Coord.ucMultifingerFirstTouchThDownOffset)>>1);
				
					if( temp_coord->tPos.vusS[cl] < lTouchOffThd )
					{
						temp_coord->tPos.vusS[cl] = 0;
						temp_coord->cScreenDebCnt[cl] = 0;
					}
				}
				else
				{
					int sFirstTouchOnMaxCellVal = thisModeConf->Coord.sFirstTouchOnMaxCellVal;

					if( thisModeConf->Coord.ucMultifingerFirstTouchThDownOffset > 0 && (temp_coord->tPos.sFinger_ > 5 || thisInfo->bIsPalm == YES) ) sFirstTouchOnMaxCellVal -= thisModeConf->Coord.ucMultifingerFirstTouchThDownOffset;//10;
					
					if( temp_coord->tPos.vusS[cl] >= thisModeConf->Coord.lSmallTouchOnThd && temp_coord->tPos.vusR[cl] > 0 )
					{
						int iDebCnt     = 0;
						int iDebCntPlus = 0;//(int)algorithm_coord_IsEdgeArea(&temp_coord->tFirstPos.tXY[cl]);
						
						if(thisModeConf->Coord.bEdgeDebCntUp > 0)
							iDebCntPlus = (int)algorithm_coord_IsEdgeArea(&temp_coord->tFirstPos.tXY[cl] , 0);
						
//						if(thisModeConf->Coord.ucDebCntEdge > 0 && algorithm_coord_IsEdgeArea(&temp_coord->tFirstPos.tXY[cl] , 0))
//							iDebCntPlus = thisModeConf->Coord.ucDebCntEdge;
						
						if(temp_coord->cScreenDebCnt[cl] < COORD_HISTORY_NUM)
						{
							temp_coord->cScreenDebCnt[cl]++;
						}

						if( temp_coord->tPos.MaxDelta[cl] > sFirstTouchOnMaxCellVal )
						{
							if( temp_coord->tPos.vusS[cl] >= thisModeConf->Coord.lLargeTouchOnThd )
							{
	//							iDebCnt = (iDebCntPlus > 0) ? iDebCntPlus : thisModeConf->Coord.ucLargeTouchOnDebCnt;
								iDebCnt = iDebCntPlus + thisModeConf->Coord.ucLargeTouchOnDebCnt;
							}
							else if( temp_coord->tPos.vusS[cl] >= thisModeConf->Coord.lMediumTouchOnThd )
							{
	//							iDebCnt = (iDebCntPlus > 0) ? iDebCntPlus : thisModeConf->Coord.ucMediumTouchOnDebCnt;
								iDebCnt = iDebCntPlus + thisModeConf->Coord.ucMediumTouchOnDebCnt;
							}
							else if( temp_coord->tPos.vusS[cl] >= thisModeConf->Coord.lSmallTouchOnThd )
							{
	//							iDebCnt = (iDebCntPlus > 0) ? iDebCntPlus : thisModeConf->Coord.ucSmallTouchOnDebCnt;
								iDebCnt = iDebCntPlus + thisModeConf->Coord.ucSmallTouchOnDebCnt;
							}

							if( temp_coord->cScreenDebCnt[cl] > iDebCnt )
							{

							}
							else
							{
								temp_coord->tPos.vusS[cl] = 0;
							}
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
				else
				{
//					if( temp_coord->tPastPos[2].vusS[i] > 0 && temp_coord->tPastPos[1].vusS[i] > 0 && temp_coord->tPastPos[0].vusS[i] > 0 && temp_coord->tPos.vusS[i] > 0 )
//					{					
//						coord_array[0].x = (temp_coord->tOrgPastPos[2].tXY[i].x + temp_coord->tOrgPastPos[1].tXY[i].x) / 2;
//						coord_array[1].x = (temp_coord->tOrgPastPos[2].tXY[i].x + temp_coord->tOrgPastPos[1].tXY[i].x + temp_coord->tOrgPastPos[0].tXY[i].x) / 3;
//						coord_array[2].x = (temp_coord->tOrgPastPos[2].tXY[i].x + temp_coord->tOrgPastPos[1].tXY[i].x + temp_coord->tOrgPastPos[0].tXY[i].x + temp_coord->tOrgPos.tXY[i].x) / 4;
//						coord_array[3].x = (temp_coord->tOrgPastPos[1].tXY[i].x + temp_coord->tOrgPastPos[0].tXY[i].x + temp_coord->tOrgPos.tXY[i].x) / 3;
//						coord_array[4].x = (temp_coord->tOrgPastPos[0].tXY[i].x + temp_coord->tOrgPos.tXY[i].x) / 2;

//						coord_array[0].y = (temp_coord->tOrgPastPos[2].tXY[i].y + temp_coord->tOrgPastPos[1].tXY[i].y) / 2;
//						coord_array[1].y = (temp_coord->tOrgPastPos[2].tXY[i].y + temp_coord->tOrgPastPos[1].tXY[i].y + temp_coord->tOrgPastPos[0].tXY[i].y) / 3;
//						coord_array[2].y = (temp_coord->tOrgPastPos[2].tXY[i].y + temp_coord->tOrgPastPos[1].tXY[i].y + temp_coord->tOrgPastPos[0].tXY[i].y + temp_coord->tOrgPos.tXY[i].y) / 4;
//						coord_array[3].y = (temp_coord->tOrgPastPos[1].tXY[i].y + temp_coord->tOrgPastPos[0].tXY[i].y + temp_coord->tOrgPos.tXY[i].y) / 3;
//						coord_array[4].y = (temp_coord->tOrgPastPos[0].tXY[i].y + temp_coord->tOrgPos.tXY[i].y) / 2 ;

//						temp_coord->tPos.tXY[i] = meanInterpolate(coord_array, 0,5);	
//					}
//					else if(temp_coord->tPastPos[1].vusS[i] > 0 && temp_coord->tPastPos[0].vusS[i] > 0 && temp_coord->tPos.vusS[i] > 0)
//					{
//						temp_coord->tPos.tXY[i].x = (temp_coord->tOrgPastPos[1].tXY[i].x + temp_coord->tOrgPastPos[0].tXY[i].x + temp_coord->tOrgPos.tXY[i].x)/3;
//						temp_coord->tPos.tXY[i].y = (temp_coord->tOrgPastPos[1].tXY[i].y + temp_coord->tOrgPastPos[0].tXY[i].y + temp_coord->tOrgPos.tXY[i].y)/3;
//					}
//					else if(temp_coord->tPastPos[0].vusS[i] > 0 && temp_coord->tPos.vusS[i] > 0)
//					{
//						temp_coord->tPos.tXY[i].x = (temp_coord->tOrgPastPos[0].tXY[i].x + temp_coord->tOrgPos.tXY[i].x)/2;
//						temp_coord->tPos.tXY[i].y = (temp_coord->tOrgPastPos[0].tXY[i].y + temp_coord->tOrgPos.tXY[i].y)/2;
//					}

					if(temp_coord->tPastPos[0].vusS[i] > 0 && temp_coord->tPos.vusS[i] > 0)
					{
						temp_coord->tPos.tXY[i].x = (temp_coord->tOrgPastPos[0].tXY[i].x + temp_coord->tOrgPos.tXY[i].x)/2;
						temp_coord->tPos.tXY[i].y = (temp_coord->tOrgPastPos[0].tXY[i].y + temp_coord->tOrgPos.tXY[i].y)/2;
					}
				}
			}

			if( temp_coord->tPastPos[0].vusS[i] > 0 )
			{
				if(thisModeConf->Coord.cDisSmoothOffset != 0)
				{
					uint16_t /*dist_th1 = 0, dist_th2 = 0,*/ dist = 0;
					tXY_t ProjectionVector, PrevVector, CurrVector, PredPos;

					ProjectionVector.x = 0, ProjectionVector.y = 0;
					PredPos = temp_coord->tPastPos[0].tXY[i];
					
					prev_curr_dist = algorithm_coord_calc_distance(temp_coord->tPastPos[0].tXY[i], temp_coord->tPos.tXY[i]);

					prev_curr_dist += thisModeConf->Coord.cDisSmoothOffset;
					
					if(thisInfo->WinCertMode)
						prev_curr_dist >>= 3;
					
					if(prev_curr_dist < 10)
						prev_curr_dist = 10;
					
					if(prev_curr_dist > _BV(thisModeConf->Coord.lMoveSmoothingLevel))
						prev_curr_dist = _BV(thisModeConf->Coord.lMoveSmoothingLevel);
							
					//Prediction based on projection
					if(thisModeConf->Coord.ucVectorPredictionCoef)
					{
						if(temp_coord->tPastPos[4].vusR[i] > 0){
							if(ProjectionEnable[i] == NO && 
								algorithm_coord_calc_distance(temp_coord->tPos.tXY[i],temp_coord->tPastPos[4].tXY[i]) > thisModeConf->Coord.usDistThdStationaryToMoving &&
								algorithm_coord_calc_distance(temp_coord->tPastPos[2].tXY[i],temp_coord->tPastPos[4].tXY[i]) > (thisModeConf->Coord.usDistThdStationaryToMoving>>1))
								ProjectionEnable[i] = YES;
							else if(ProjectionEnable[i] == YES && algorithm_coord_calc_distance(temp_coord->tPos.tXY[i],temp_coord->tPastPos[4].tXY[i]) < thisModeConf->Coord.usDistThdMovingToStationary)
								ProjectionEnable[i] = NO;
						}			
						if(ProjectionEnable[i] == YES)
						{
							PrevVector.x = temp_coord->tPastPos[0].tXY[i].x - temp_coord->tPastPos[4].tXY[i].x;
							PrevVector.y = temp_coord->tPastPos[0].tXY[i].y - temp_coord->tPastPos[4].tXY[i].y;
							CurrVector.x = temp_coord->tPos.tXY[i].x - temp_coord->tPastPos[4].tXY[i].x;
							CurrVector.y = temp_coord->tPos.tXY[i].y - temp_coord->tPastPos[4].tXY[i].y;
						
							ProjectionVector.x = (int)(PrevVector.x * (int64_t)(PrevVector.x*CurrVector.x + PrevVector.y*CurrVector.y) / (PrevVector.x*PrevVector.x+PrevVector.y*PrevVector.y));
							ProjectionVector.y = (int)(PrevVector.y * (int64_t)(PrevVector.x*CurrVector.x + PrevVector.y*CurrVector.y) / (PrevVector.x*PrevVector.x+PrevVector.y*PrevVector.y));
						
							PredPos.x = temp_coord->tPastPos[4].tXY[i].x + ProjectionVector.x;
							PredPos.y = temp_coord->tPastPos[4].tXY[i].y + ProjectionVector.y;

							dist = algorithm_coord_calc_distance(temp_coord->tPos.tXY[i],PredPos);
							if(dist < 10)	dist = 0;
							else if(dist > thisModeConf->Coord.ucVectorPredictionCoef)	dist = thisModeConf->Coord.ucVectorPredictionCoef;
							
							temp_coord->tPos.tXY[i].x = ((thisModeConf->Coord.ucVectorPredictionCoef - dist) * PredPos.x + dist * temp_coord->tPos.tXY[i].x + (thisModeConf->Coord.ucVectorPredictionCoef>>1)) / thisModeConf->Coord.ucVectorPredictionCoef;
							temp_coord->tPos.tXY[i].y = ((thisModeConf->Coord.ucVectorPredictionCoef - dist) * PredPos.y + dist * temp_coord->tPos.tXY[i].y + (thisModeConf->Coord.ucVectorPredictionCoef>>1)) / thisModeConf->Coord.ucVectorPredictionCoef;			
							if( temp_coord->tPastPos[2].vusS[i] > 0)
							{
								temp_coord->tPos.tXY[i].x = ((((temp_coord->tPastPos[0].tXY[i].x<<1) - temp_coord->tPastPos[2].tXY[i].x) + temp_coord->tPos.tXY[i].x)>>1);
								temp_coord->tPos.tXY[i].y = ((((temp_coord->tPastPos[0].tXY[i].y<<1) - temp_coord->tPastPos[2].tXY[i].y) + temp_coord->tPos.tXY[i].y)>>1);
							}
						}
						else if(prev_curr_dist > (1<<POS_BOOST_SHIFT_)){
							temp_coord->tPos.tXY[i].x = ((temp_coord->tPos.tXY[i].x + temp_coord->tOrgPos.tXY[i].x)>>1);
							temp_coord->tPos.tXY[i].y = ((temp_coord->tPos.tXY[i].y + temp_coord->tOrgPos.tXY[i].y)>>1);
						}
					}
					temp_coord->tPos.tXY[i].x = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * temp_coord->tPastPos[0].tXY[i].x + prev_curr_dist * temp_coord->tPos.tXY[i].x + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
					temp_coord->tPos.tXY[i].y = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * temp_coord->tPastPos[0].tXY[i].y + prev_curr_dist * temp_coord->tPos.tXY[i].y + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
				
					//heon
					temp_coord->tPos.tXY[i] = temp_coord->tOrgPos.tXY[i];
				}
				
				if(temp_coord->tPos.vusS[i] > 0)
				{
					if(thisModeConf->Coord.usDrumTestDist > 0)
					{
						if(DrumStep[i] == 0)
						{
							if(temp_coord->tOrgPos.vusR[i] > 0 && temp_coord->tOrgPastPos[0].vusR[i] > 0){
								if(thisModeConf->Coord.usDrumTestDist < algorithm_coord_calc_distance(temp_coord->tOrgPos.tXY[i],temp_coord->tOrgPastPos[0].tXY[i]))
								{
									DrumStep[i] = 1;
//									DrumCoordBuf[i] = temp_coord->tPos.tXY[i];
									temp_coord->tPos.tXY[i] = temp_coord->tPastPos[0].tXY[i];
								}
								else if((thisModeConf->Coord.usDrumTestDist) < algorithm_coord_calc_distance(temp_coord->tOrgPos.tXY[i],temp_coord->iStopPos[i]))
								{
									DrumStep[i] = 3;
								}	
							}
						}
						
						
					}
					
					if(thisModeConf->Coord.usFirstDrawingThd > 0 && temp_coord->tPos.vusR[i] > thisModeConf->Coord.ucFirstDrawingCellCnt)
					{
						if(temp_coord->DrawingFlag[i] == NO)
						{
							int dist_th = 0;
							
	//						if(algorithm_coord_IsEdgeArea(&temp_coord->iStopPos[i])>0)
	//							dist_th = (1<<POS_BOOST_SHIFT_);
	//						else
								dist_th = thisModeConf->Coord.usFirstDrawingThd;
							
							if(algorithm_coord_IsEdgeArea(&temp_coord->iStopPos[i],0)>0)
								dist_th += AddDistTh;
							
							if( algorithm_coord_calc_distance(temp_coord->iStopPos[i],temp_coord->tPos.tXY[i]) < dist_th )
							{
								temp_coord->tPos.tXY[i] =temp_coord->iStopPos[i];
	//							temp_coord->tPos.tXY[i].x = ((temp_coord->tFirstPos.tXY[i].x*7 + temp_coord->tPos.tXY[i].x)>>3);
	//							temp_coord->tPos.tXY[i].y = ((temp_coord->tFirstPos.tXY[i].y*7 + temp_coord->tPos.tXY[i].y)>>3);
							}
							else{
								temp_coord->DrawingFlag[i] = YES;
								temp_coord->tPos.tXY[i].x = ((temp_coord->iStopPos[i].x + temp_coord->tPos.tXY[i].x)>>1);
								temp_coord->tPos.tXY[i].y = ((temp_coord->iStopPos[i].y + temp_coord->tPos.tXY[i].y)>>1);
							}
						}
					}
					else
					{
						temp_coord->DrawingFlag[i] = YES;
					}
				}
			
				// Finger Edge Smoothing
				if(thisModeConf->Coord.cEdgeSmoothing_Finger_On > 0)
				{
					int MoveSmoothingLevel = thisModeConf->Coord.lMoveSmoothingLevel;
					if(temp_coord->tPos.tXY[i].x < (1<<(POS_BOOST_SHIFT_)) || temp_coord->tPos.tXY[i].y > thisInfo->tCoord.iInternalYRes-(1<<(POS_BOOST_SHIFT_))
						|| temp_coord->tPos.tXY[i].x > thisInfo->tCoord.iInternalXRes-(1<<(POS_BOOST_SHIFT_)) || temp_coord->tPos.tXY[i].y < (1<<(POS_BOOST_SHIFT_)))
					{
						prev_curr_dist = abs(temp_coord->tPastPos[0].tXY[i].x - temp_coord->tPos.tXY[i].x);
						prev_curr_dist += thisModeConf->Coord.cEdgeSmoothing_Finger_On;					
						if(prev_curr_dist < 10) prev_curr_dist = 10;					
						if(prev_curr_dist > _BV(MoveSmoothingLevel)) prev_curr_dist = _BV(MoveSmoothingLevel);

						temp_coord->tPos.tXY[i].x = ((_BV(MoveSmoothingLevel) - prev_curr_dist) * temp_coord->tPastPos[0].tXY[i].x + prev_curr_dist * temp_coord->tPos.tXY[i].x + _BV(MoveSmoothingLevel-1)) >> MoveSmoothingLevel;
						
						prev_curr_dist = abs(temp_coord->tPastPos[0].tXY[i].y - temp_coord->tPos.tXY[i].y);
						prev_curr_dist += thisModeConf->Coord.cEdgeSmoothing_Finger_On;					
						if(prev_curr_dist < 10) prev_curr_dist = 10;					
						if(prev_curr_dist > _BV(MoveSmoothingLevel)) prev_curr_dist = _BV(MoveSmoothingLevel);


						temp_coord->tPos.tXY[i].y = ((_BV(MoveSmoothingLevel) - prev_curr_dist) * temp_coord->tPastPos[0].tXY[i].y + prev_curr_dist * temp_coord->tPos.tXY[i].y + _BV(MoveSmoothingLevel-1)) >> MoveSmoothingLevel;				
					}
				}				
			}
		}
	}
}

void algorithm_coord_OutInDrawing(void)
{
	int i;
	tXY_t	temp_pos, temp_pos2;
	int bound_th = thisModeConf->Coord.usOutInDrawEdgeTh;
	int dis_th = thisModeConf->Coord.ucOutInDrawDisTh;
	int PostProcess[MAX_TOUCH_] = {0, };
	
	tCoordInfo_t 	*temp_coord;

	temp_coord = &thisInfo->tCoord;

	for( i=MAX_TOUCH_; i--; )
	{
		if( temp_coord->tPos.vusS[i] > 0 && temp_coord->tPastPos[0].vusS[i] == 0 )
		{
			if( (temp_coord->tFirstPos.tXY[i].x < thisModeConf->Coord.usOutInDrawEdgeTh) || ((thisInfo->tCoord.iInternalXRes - temp_coord->tFirstPos.tXY[i].x) < thisModeConf->Coord.usOutInDrawEdgeTh)
			|| (temp_coord->tFirstPos.tXY[i].y < thisModeConf->Coord.usOutInDrawEdgeTh) || ((thisInfo->tCoord.iInternalYRes - temp_coord->tFirstPos.tXY[i].y) < thisModeConf->Coord.usOutInDrawEdgeTh) )
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

		if(thisModeConf->Coord.usPostProcessEdgeTH > 0)
		{
			if(temp_coord->tOrgPos.vusS[i] == 0 && temp_coord->tOrgPastPos[1].vusS[i] > 0 && temp_coord->tOrgPastPos[0].vusS[i] > 0 && temp_coord->tOrgPastPos[2].vusS[i] > 0) 
			{
				int ExpandTH = thisModeConf->Coord.usPostProcessEdgeTH;
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
					
					if( (dist_x[0] < -thisModeConf->Coord.ucPostProcessDisTH && dist_x[1] < -thisModeConf->Coord.ucPostProcessDisTH && dist_x[2] < -thisModeConf->Coord.ucPostProcessDisTH && x_edge_f == 1)
					|| (dist_x[0] > thisModeConf->Coord.ucPostProcessDisTH   && dist_x[1] > thisModeConf->Coord.ucPostProcessDisTH && dist_x[2] > thisModeConf->Coord.ucPostProcessDisTH &&x_edge_f == 2)
					|| (dist_y[0] < -thisModeConf->Coord.ucPostProcessDisTH  && dist_y[1] < -thisModeConf->Coord.ucPostProcessDisTH && dist_y[2] < -thisModeConf->Coord.ucPostProcessDisTH && y_edge_f == 1)
					|| (dist_y[0] > thisModeConf->Coord.ucPostProcessDisTH   && dist_y[2] > thisModeConf->Coord.ucPostProcessDisTH && dist_y[2] > thisModeConf->Coord.ucPostProcessDisTH && y_edge_f == 2) )
					{
						temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + dist_x[0]/thisModeConf->Coord.ucPostProcessExpendDiv;
						temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + dist_y[0]/thisModeConf->Coord.ucPostProcessExpendDiv;
						
						uint8_t max_idx = 0;
						if(x_edge_f == 1 && temp_coord->tPos.tXY[i].x > -thisModeConf->Coord.cPostProcessEndMargin)
						{
							temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + MIN(dist_x[0],MIN(dist_x[1], dist_x[2]));
							
							if(abs(dist_y[0]) >= abs(dist_y[1]) && abs(dist_y[0]) >= abs(dist_y[2]))max_idx = 0;
							else if(abs(dist_y[1]) >= abs(dist_y[0]) && abs(dist_y[1]) >= abs(dist_y[2]))max_idx = 1;
							else if(abs(dist_y[2]) >= abs(dist_y[0]) && abs(dist_y[2]) >= abs(dist_y[1]))max_idx = 2;
							
							temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + dist_y[max_idx];
						}
						else if(x_edge_f == 2 && temp_coord->tPos.tXY[i].x < thisInfo->tCoord.iInternalXRes + thisModeConf->Coord.cPostProcessEndMargin)
						{
							temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + MAX(dist_x[0],MAX(dist_x[1], dist_x[2]));
																	
							if(abs(dist_y[0]) >= abs(dist_y[1]) && abs(dist_y[0]) >= abs(dist_y[2]))max_idx = 0;
							else if(abs(dist_y[1]) >= abs(dist_y[0]) && abs(dist_y[1]) >= abs(dist_y[2]))max_idx = 1;
							else if(abs(dist_y[2]) >= abs(dist_y[0]) && abs(dist_y[2]) >= abs(dist_y[1]))max_idx = 2;
							
							temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + dist_y[max_idx];
						}
						
						max_idx = 0;
						if(y_edge_f == 1 && temp_coord->tPos.tXY[i].y > -thisModeConf->Coord.cPostProcessEndMargin)
						{
							temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + MIN(dist_y[0],MIN(dist_y[1], dist_y[2]));
																	
							if(abs(dist_x[0]) >= abs(dist_x[1]) && abs(dist_x[0]) >= abs(dist_x[2]))max_idx = 0;
							else if(abs(dist_x[1]) >= abs(dist_x[0]) && abs(dist_x[1]) >= abs(dist_x[2]))max_idx = 1;
							else if(abs(dist_x[2]) >= abs(dist_x[0]) && abs(dist_x[2]) >= abs(dist_x[1]))max_idx = 2;
							
							temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + dist_x[max_idx];
						}
						else if(y_edge_f == 2 && temp_coord->tPos.tXY[i].y < thisInfo->tCoord.iInternalYRes + thisModeConf->Coord.cPostProcessEndMargin)
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
		if(!thisModeConf->Coord.bPostProcessInterpolationMode)
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

		if(thisModeConf->Coord.usPostProcessEdgeTH > 0)
		{
			if( ((temp_coord->tOrgPos.vusS[i] == 0 && temp_coord->tOrgPastPos[2].vusS[i] > 0 && temp_coord->tOrgPastPos[0].vusS[i] > 0 && temp_coord->tOrgPastPos[4].vusS[i] > 0) && thisModeConf->Coord.bPostProcessInterpolationMode)
			|| ((temp_coord->tOrgPos.vusS[i] == 0 && temp_coord->tOrgPastPos[1].vusS[i] > 0 && temp_coord->tOrgPastPos[0].vusS[i] > 0 && temp_coord->tOrgPastPos[2].vusS[i] > 0) && !thisModeConf->Coord.bPostProcessInterpolationMode) )
			{
				tXY_t pos;
				pos = temp_coord->tPastPos[0].tXY[i];				
				pos.x = ( (pos.x + thisInfo->tCoord.iXOffset ) * thisCommonConf->iXResolution ) / (thisInfo->tCoord.iInternalXRes + 2*thisInfo->tCoord.iXOffset);
				pos.y = ( (pos.y + thisInfo->tCoord.iYOffset ) * thisCommonConf->iYResolution ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
				
				if( (pos.x < 5 || pos.x > 32762 || pos.y < 5 || pos.y > 32762) && thisModeConf->Coord.cPostProcessEndMargin == 0)
				{
				}
				else
				{				
					int ExpandTH = thisModeConf->Coord.usPostProcessEdgeTH;
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
						if(thisModeConf->Coord.bPostProcessInterpolationMode)
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
						
						if( (dist_x[0] < -thisModeConf->Coord.ucPostProcessDisTH && dist_x[1] < -thisModeConf->Coord.ucPostProcessDisTH && dist_x[2] < -thisModeConf->Coord.ucPostProcessDisTH && x_edge_f == 1)
						|| (dist_x[0] > thisModeConf->Coord.ucPostProcessDisTH   && dist_x[1] > thisModeConf->Coord.ucPostProcessDisTH && dist_x[2] > thisModeConf->Coord.ucPostProcessDisTH &&x_edge_f == 2)
						|| (dist_y[0] < -thisModeConf->Coord.ucPostProcessDisTH  && dist_y[1] < -thisModeConf->Coord.ucPostProcessDisTH && dist_y[2] < -thisModeConf->Coord.ucPostProcessDisTH && y_edge_f == 1)
						|| (dist_y[0] > thisModeConf->Coord.ucPostProcessDisTH   && dist_y[2] > thisModeConf->Coord.ucPostProcessDisTH && dist_y[2] > thisModeConf->Coord.ucPostProcessDisTH && y_edge_f == 2) )
						{
							if(thisModeConf->Coord.ucExpectClipping_Finger_On < 2)
							{
								temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + dist_x[0]/thisModeConf->Coord.ucPostProcessExpendDiv;
								temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + dist_y[0]/thisModeConf->Coord.ucPostProcessExpendDiv;
								
								uint8_t max_idx = 0;
								if(x_edge_f == 1 && temp_coord->tPos.tXY[i].x > -thisModeConf->Coord.cPostProcessEndMargin)
								{
									temp_coord->tPos.tXY[i].x = temp_coord->tOrgPastPos[0].tXY[i].x + MIN(dist_x[0],MIN(dist_x[1], dist_x[2]));
								}
								else if(x_edge_f == 2 && temp_coord->tPos.tXY[i].x < thisInfo->tCoord.iInternalXRes + thisModeConf->Coord.cPostProcessEndMargin)
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
								if(y_edge_f == 1 && temp_coord->tPos.tXY[i].y > -thisModeConf->Coord.cPostProcessEndMargin)
								{
									temp_coord->tPos.tXY[i].y = temp_coord->tOrgPastPos[0].tXY[i].y + MIN(dist_y[0],MIN(dist_y[1], dist_y[2]));
								}
								else if(y_edge_f == 2 && temp_coord->tPos.tXY[i].y < thisInfo->tCoord.iInternalYRes + thisModeConf->Coord.cPostProcessEndMargin)
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
							}
							else
							{
								temp_coord->tPos.tXY[i].x = temp_coord->tPastPos[0].tXY[i].x + (temp_coord->tPastPos[0].tXY[i].x - temp_coord->tPastPos[2].tXY[i].x);
								temp_coord->tPos.tXY[i].y = temp_coord->tPastPos[0].tXY[i].y + (temp_coord->tPastPos[0].tXY[i].y - temp_coord->tPastPos[2].tXY[i].y);
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

#ifdef PenPostProcess_SW
extern int HID_PEN_X;
extern int HID_PEN_Y;
void algorithm_coord_PostProcess_Local(void)
{
	
	tPenCoordInfo_t 	*temp_coord;

	temp_coord = &thisInfo->tCoord_local_dsp;

	if(HID_PEN_X < 5 || HID_PEN_X > 32762 || HID_PEN_Y < 5 || HID_PEN_Y > 32762)
	{

	}
	else
	{
		uint8_t x_edge_f = 0;
		uint8_t y_edge_f = 0;

		int ExpandTH = 1<<thisModeConf->PenCoord.ucPenPostProcessEdgeTH;
		
		if(temp_coord->tOrgPastPos[1].vusS > 0 && temp_coord->tOrgPastPos[0].vusS > 0 && temp_coord->tOrgPastPos2.vusS > 0)
		{
			if(temp_coord->tOrgPastPos[0].tXY.x < ExpandTH
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
                && temp_coord->tFirstPos.x > (1<<POS_BOOST_SHIFT_)
#endif
            )
            {
                x_edge_f = 1;
            }
			else if((thisInfo->tCoord.iInternalXRes - temp_coord->tOrgPastPos[0].tXY.x) < ExpandTH
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
                && (thisInfo->tCoord.iInternalXRes - temp_coord->tFirstPos.x) > (1<<POS_BOOST_SHIFT_)
#endif
            )
            {
                x_edge_f = 2;
            }
			if(temp_coord->tOrgPastPos[0].tXY.y < ExpandTH
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
                && temp_coord->tFirstPos.y > (1<<POS_BOOST_SHIFT_)
#endif
            )
            {
                y_edge_f = 1;
            }
			else if((thisInfo->tCoord.iInternalYRes - temp_coord->tOrgPastPos[0].tXY.y) < ExpandTH
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
                && (thisInfo->tCoord.iInternalYRes - temp_coord->tFirstPos.y) > (1<<POS_BOOST_SHIFT_)
#endif
            )
            {
                y_edge_f = 2;
            }
		}     
		
		if(x_edge_f || y_edge_f)
		{
			int dist_y[3] = {0,};			
			int dist_x[3] = {0,};      
		
			dist_y[0] = temp_coord->tPastPos[0].tXY.y - temp_coord->tPastPos[1].tXY.y;			
			dist_x[0] = temp_coord->tPastPos[0].tXY.x - temp_coord->tPastPos[1].tXY.x;				

			dist_y[1] = temp_coord->tPastPos[0].tXY.y - temp_coord->tPastPos2.tXY.y;
			dist_x[1] = temp_coord->tPastPos[0].tXY.x - temp_coord->tPastPos2.tXY.x;		
		
			dist_y[2] = temp_coord->tPastPos[1].tXY.y - temp_coord->tPastPos2.tXY.y;
			dist_x[2] = temp_coord->tPastPos[1].tXY.x - temp_coord->tPastPos2.tXY.x;

			if( (dist_x[0] < -thisModeConf->PenCoord.ucPenPostProcessDisTH && dist_x[1] < -thisModeConf->PenCoord.ucPenPostProcessDisTH && dist_x[2] < -thisModeConf->PenCoord.ucPenPostProcessDisTH && x_edge_f == 1)
			|| (dist_x[0] > thisModeConf->PenCoord.ucPenPostProcessDisTH && dist_x[1] > thisModeConf->PenCoord.ucPenPostProcessDisTH && dist_x[2] > thisModeConf->PenCoord.ucPenPostProcessDisTH &&x_edge_f == 2)
			|| (dist_y[0] < -thisModeConf->PenCoord.ucPenPostProcessDisTH && dist_y[1] < -thisModeConf->PenCoord.ucPenPostProcessDisTH && dist_y[2] < -thisModeConf->PenCoord.ucPenPostProcessDisTH && y_edge_f == 1)
			|| (dist_y[0] > thisModeConf->PenCoord.ucPenPostProcessDisTH && dist_y[2] > thisModeConf->PenCoord.ucPenPostProcessDisTH && dist_y[2] > thisModeConf->PenCoord.ucPenPostProcessDisTH && y_edge_f == 2) )
			{
				temp_coord->tPos.tXY.x = temp_coord->tOrgPastPos[0].tXY.x + dist_x[0]/thisModeConf->PenCoord.ucPenPostProcessExpendDiv;
				temp_coord->tPos.tXY.y = temp_coord->tOrgPastPos[0].tXY.y + dist_y[0]/thisModeConf->PenCoord.ucPenPostProcessExpendDiv;

				uint8_t max_idx = 0;
				if(x_edge_f == 1 && temp_coord->tPos.tXY.x > -thisModeConf->PenCoord.cPenPostProcessEndMargin)
				{
					temp_coord->tPos.tXY.x = temp_coord->tOrgPastPos[0].tXY.x + MIN(dist_x[0],MIN(dist_x[1], dist_x[2]));
					
					if(abs(dist_y[0]) >= abs(dist_y[1]) && abs(dist_y[0]) >= abs(dist_y[2]))max_idx = 0;
					else if(abs(dist_y[1]) >= abs(dist_y[0]) && abs(dist_y[1]) >= abs(dist_y[2]))max_idx = 1;
					else if(abs(dist_y[2]) >= abs(dist_y[0]) && abs(dist_y[2]) >= abs(dist_y[1]))max_idx = 2;
					
					temp_coord->tPos.tXY.y = temp_coord->tOrgPastPos[0].tXY.y + dist_y[max_idx];
				}
				else if(x_edge_f == 2 && temp_coord->tPos.tXY.x < thisInfo->tCoord.iInternalXRes + thisModeConf->PenCoord.cPenPostProcessEndMargin)
				{
					temp_coord->tPos.tXY.x = temp_coord->tOrgPastPos[0].tXY.x + MAX(dist_x[0],MAX(dist_x[1], dist_x[2]));
															
					if(abs(dist_y[0]) >= abs(dist_y[1]) && abs(dist_y[0]) >= abs(dist_y[2]))max_idx = 0;
					else if(abs(dist_y[1]) >= abs(dist_y[0]) && abs(dist_y[1]) >= abs(dist_y[2]))max_idx = 1;
					else if(abs(dist_y[2]) >= abs(dist_y[0]) && abs(dist_y[2]) >= abs(dist_y[1]))max_idx = 2;
					
					temp_coord->tPos.tXY.y = temp_coord->tOrgPastPos[0].tXY.y + dist_y[max_idx];
				}
				
				max_idx = 0;
				if(y_edge_f == 1 && temp_coord->tPos.tXY.y > -thisModeConf->PenCoord.cPenPostProcessEndMargin)
				{
					temp_coord->tPos.tXY.y = temp_coord->tOrgPastPos[0].tXY.y + MIN(dist_y[0],MIN(dist_y[1], dist_y[2]));
															
					if(abs(dist_x[0]) >= abs(dist_x[1]) && abs(dist_x[0]) >= abs(dist_x[2]))max_idx = 0;
					else if(abs(dist_x[1]) >= abs(dist_x[0]) && abs(dist_x[1]) >= abs(dist_x[2]))max_idx = 1;
					else if(abs(dist_x[2]) >= abs(dist_x[0]) && abs(dist_x[2]) >= abs(dist_x[1]))max_idx = 2;
					
					temp_coord->tPos.tXY.x = temp_coord->tOrgPastPos[0].tXY.x + dist_x[max_idx];
				}
				else if(y_edge_f == 2 && temp_coord->tPos.tXY.y < thisInfo->tCoord.iInternalYRes + thisModeConf->PenCoord.cPenPostProcessEndMargin)
				{
					temp_coord->tPos.tXY.y = temp_coord->tOrgPastPos[0].tXY.y + MAX(dist_y[0],MAX(dist_y[1], dist_y[2]));
					
					if(abs(dist_x[0]) >= abs(dist_x[1]) && abs(dist_x[0]) >= abs(dist_x[2]))max_idx = 0;
					else if(abs(dist_x[1]) >= abs(dist_x[0]) && abs(dist_x[1]) >= abs(dist_x[2]))max_idx = 1;
					else if(abs(dist_x[2]) >= abs(dist_x[0]) && abs(dist_x[2]) >= abs(dist_x[1]))max_idx = 2;
					
					temp_coord->tPos.tXY.x = temp_coord->tOrgPastPos[0].tXY.x + dist_x[max_idx];
				}
					
				temp_coord->tPos.vusS  =  temp_coord->tOrgPastPos[0].vusS;
				temp_coord->tPos.vusR  =  temp_coord->tOrgPastPos[0].vusR;

				thisInfo->tCoord_local_dsp.tAvgPos.x = 1;
			}
		}	
	}
}
#endif

void algorithm_coord_UpdatePosHistoryInfo(void)
{
	int i;

	tCoordInfo_t 	*temp_coord;

	temp_coord = &thisInfo->tCoord;
	
	if(temp_coord->bInterpolation_On)
	{
		temp_coord->tPastPos[4].sFinger_ 	    = temp_coord->tPastPos[3].sFinger_;
		temp_coord->tPastPos[3].sFinger_ 	    = temp_coord->tPastPos[2].sFinger_;
		
		temp_coord->tOrgPastPos[4].sFinger_ 	= temp_coord->tOrgPastPos[3].sFinger_;
		temp_coord->tOrgPastPos[3].sFinger_ 	= temp_coord->tOrgPastPos[2].sFinger_;
	}

	temp_coord->tPastPos[2].sFinger_ 	    = temp_coord->tPastPos[1].sFinger_;
	temp_coord->tPastPos[1].sFinger_ 	    = temp_coord->tPastPos[0].sFinger_;
	temp_coord->tPastPos[0].sFinger_ 	    = temp_coord->tPos.sFinger_;

	temp_coord->tOrgPastPos[2].sFinger_ 	= temp_coord->tOrgPastPos[1].sFinger_;
	temp_coord->tOrgPastPos[1].sFinger_ 	= temp_coord->tOrgPastPos[0].sFinger_;
	temp_coord->tOrgPastPos[0].sFinger_ 	= temp_coord->tOrgPos.sFinger_;

	for( i=MAX_TOUCH_; i--; )
	{
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
void alogorithm_coord_modify_pos(tXY_t* old_pos,tXY_t* pos)
{
	int x, y; 
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
		if (!thisModeConf->Coord.bDoNotExpandPos)
		{
			if (x < thisInfo->tCoord.iXExpandStart)
				x = thisInfo->tCoord.iXExpandStart + (((x - thisInfo->tCoord.iXExpandStart) * (int32_t)thisModeConf->Coord.ucLeftEdgeExpand) >> 6);
			else if (thisInfo->tCoord.iInternalXRes - x < thisInfo->tCoord.iXExpandStart)
				x = thisInfo->tCoord.iInternalXRes - (thisInfo->tCoord.iXExpandStart
									 + (((thisInfo->tCoord.iInternalXRes - x - thisInfo->tCoord.iXExpandStart) * (int32_t)thisModeConf->Coord.ucRightEdgeExpand) >> 6));

			if (y < thisInfo->tCoord.iYExpandStart)
				y = thisInfo->tCoord.iYExpandStart + (((y - thisInfo->tCoord.iYExpandStart) * (int32_t)thisModeConf->Coord.ucTopEdgeExpand) >> 6);
			else if (thisInfo->tCoord.iInternalYRes - y < thisInfo->tCoord.iYExpandStart)
				y = thisInfo->tCoord.iInternalYRes - (thisInfo->tCoord.iYExpandStart
									 + (((thisInfo->tCoord.iInternalYRes - y - thisInfo->tCoord.iYExpandStart) * (int32_t)thisModeConf->Coord.ucBottomEdgeExpand) >> 6));
		}
	}

	/*
	 * Modify resolution domain.
	 */
	x = ( (x + thisInfo->tCoord.iXOffset ) * (thisCommonConf->iXResolution+thisModeConf->Coord.sFingerGlobalCoordiXResolutionOffset) ) / (thisInfo->tCoord.iInternalXRes + 2*thisInfo->tCoord.iXOffset);
	y = ( (y + thisInfo->tCoord.iYOffset ) * (thisCommonConf->iYResolution+thisModeConf->Coord.sFingerGlobalCoordiYResolutionOffset) ) / (thisInfo->tCoord.iInternalYRes + 2*thisInfo->tCoord.iYOffset);
	x += thisModeConf->Coord.sFingerGlobalCoordiOffsetX;
	y += thisModeConf->Coord.sFingerGlobalCoordiOffsetY;
	/*
	 * Clipping.
	 */
	int iXResolutionForClipping = thisCommonConf->iXResolution - 1;
	int iYResolutionForClipping = thisCommonConf->iYResolution - 1;
//	if(iXResolutionForClipping > 32767)iXResolutionForClipping = 32767;
//	if(iYResolutionForClipping > 32767)iYResolutionForClipping = 32767;
	if(thisModeConf->Coord.ucExpectClipping_Finger_On)
	{
		pos->x = x,	pos->y = y;
		if (x < (int)thisCommonConf->ucXClipping){	//LEFT
			x = (int)(thisCommonConf->ucXClipping);
			if( old_pos != pos && pos->x < (thisCommonConf->ucXClipping) && old_pos->x > (thisCommonConf->ucXClipping) )
				y = ( (x - old_pos->x)*(pos->y - old_pos->y) + ((pos->x - old_pos->x)>>1) ) / (pos->x - old_pos->x) + old_pos->y;
			pos->x = x,	pos->y = y;
		}
		else if (x > ((int)((iXResolutionForClipping) - thisCommonConf->ucXClipping))){	//RIGHT
			x = (iXResolutionForClipping) - thisCommonConf->ucXClipping;
			if( old_pos != pos && pos->x > ((int)((iXResolutionForClipping) - (thisCommonConf->ucXClipping))) && old_pos->x < ((int)((iXResolutionForClipping) - (thisCommonConf->ucXClipping)))  )
				y = ( (x - old_pos->x)*(pos->y - old_pos->y) + ((pos->x - old_pos->x)>>1) ) / (pos->x - old_pos->x) + old_pos->y;
			pos->x = x,	pos->y = y;
		}
		if (y < (int)(thisCommonConf->ucYClipping)){	//UP
			y = (int)thisCommonConf->ucYClipping;
			if( old_pos != pos && pos->y < (thisCommonConf->ucYClipping) && old_pos->y > (thisCommonConf->ucYClipping) )
				x = ( (y - old_pos->y)*(pos->x - old_pos->x) + ((pos->y - old_pos->y)>>1) ) / (pos->y - old_pos->y) + old_pos->x;
			pos->x = x,	pos->y = y;
		}
		else if (y > (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping)){	//DOWN
			y = (int)((iYResolutionForClipping) - thisCommonConf->ucYClipping);
			if( old_pos != pos && pos->y > ((int)((iYResolutionForClipping) - (thisCommonConf->ucYClipping))) && old_pos->y < ((int)((iYResolutionForClipping) - (thisCommonConf->ucYClipping))) )
				x = ( (y - old_pos->y)*(pos->x - old_pos->x) + ((pos->y - old_pos->y)>>1) ) / (pos->y - old_pos->y) + old_pos->x;
			pos->x = x,	pos->y = y;
		}
	}
//	else
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

void algorithm_coord_compensation(int mode)
{
	if(mode == FULL_MODE)
		return;

	int coefA,coefB;

	if(mode == LOCAL_MODE)
	{
		coefA = thisModeConf->PenCoord.ucCompenCoefA;
		coefB = thisModeConf->PenCoord.ucCompenCoefB;
	}
	else if(mode == LOCAL_RING_MODE)
	{
		coefA = thisModeConf->PenTilt.ucRingCompenCoefA;
		coefB = thisModeConf->PenTilt.ucRingCompenCoefB;
	}
	else if(mode == LOCAL_HOVER_MODE)
	{
		coefA = thisModeConf->PenCoord.ucHoverCompenCoefA;
		coefB = thisModeConf->PenCoord.ucHoverCompenCoefB;	
	}	
	
	if(coefA > 0)
	{
		if( thisInfo->tCoord_local_dsp.tPos.vusR > 0 )
		{
			tXY_t TmpPos;
			TmpPos.x = thisInfo->tCoord_local_dsp.tPos.tXY.x + (UNIT_DIST>>1);
			TmpPos.y = thisInfo->tCoord_local_dsp.tPos.tXY.y + (UNIT_DIST>>1);
//			int x = thisInfo->tCoord_local_dsp.tPos.tXY.x + (UNIT_DIST>>1);
//			int y = thisInfo->tCoord_local_dsp.tPos.tXY.y + (UNIT_DIST>>1);
			
			// Compensation		
			int XResol = UNIT_DIST;
			int YResol = UNIT_DIST;

			bool_t Op_Flag = 0;
#if USED_PANEL_HV60x34_SIZE			
			if(gAlgoRawDataType == ACTIVEPEN_TYPE_MS)
			{
				coefA -= 5;
			}
#endif			
			if(thisModeConf->PenCoord.bCompenEdgeOn)Op_Flag = 1;
			else 
			{
				if(!algorithm_coord_IsEdgeArea(&TmpPos,0))Op_Flag = 1;
//				if(TmpPos.x > (1<<POS_BOOST_SHIFT_) && TmpPos.x < ((COL_MAX-1)<<POS_BOOST_SHIFT_))Op_Flag = 1;
			}
			
			if(Op_Flag == 1)
			{
				int OneCellPos = TmpPos.x - (((int)TmpPos.x/(XResol))*(XResol));
				uint8_t Mm = (XResol)/FPITCH_X;
				int OneCellMm = OneCellPos * (1/FPITCH_X);
				if(OneCellPos < (XResol)*0.25) TmpPos.x -= (OneCellMm)*coefA/coefB;
				else if((XResol)*0.25 <= OneCellPos && OneCellPos < (XResol)*0.75) TmpPos.x += (OneCellMm - Mm/2)*coefA/coefB;
				else TmpPos.x += (-OneCellMm+Mm)*coefA/coefB;
//			}

//			Op_Flag = 0;
//			if(thisModeConf->PenCoord.bCompenEdgeOn)Op_Flag = 1;
//			else 
//			{
//				if(TmpPos.y > (1<<POS_BOOST_SHIFT_) && TmpPos.y < ((ROW_MAX -1)<<POS_BOOST_SHIFT_))Op_Flag = 1;
//			}
			
//			if(Op_Flag == 1)
//			{
				OneCellPos = TmpPos.y - (((int)TmpPos.y/(YResol))*(YResol));
				Mm = (YResol)/FPITCH_Y;  
				OneCellMm = OneCellPos * (1/FPITCH_Y);
				
				if(OneCellPos < (YResol)*0.25)TmpPos.y -= (OneCellMm)*coefA/coefB;
				else if((YResol)*0.25 <= OneCellPos && OneCellPos < (YResol)*0.75)TmpPos.y += (OneCellMm - Mm/2)*coefA/coefB;
				else TmpPos.y += (-OneCellMm+Mm)*coefA/coefB;
			}
			
			thisInfo->tCoord_local_dsp.tPos.tXY.x = TmpPos.x - (UNIT_DIST>>1);
			thisInfo->tCoord_local_dsp.tPos.tXY.y = TmpPos.y - (UNIT_DIST>>1);
			thisInfo->tCoord_local_dsp.tOrgPos.tXY.x = thisInfo->tCoord_local_dsp.tPos.tXY.x;
			thisInfo->tCoord_local_dsp.tOrgPos.tXY.y = thisInfo->tCoord_local_dsp.tPos.tXY.y;
		}
	}
}

void algorithm_coord_interpolation(uint8_t ver)
{	
	for (int l = 0; l < MAX_TOUCH_; l++)
	{
		if( thisInfo->tCoord.tOrgPastPos[0].vusS[l] )
		{
			if(ver == 1)
			{
				thisInfo->tCoord.tPos.tXY[l].x = (thisInfo->tCoord.tPastPos[0].tXY[l].x + thisInfo->tCoord.tOrgPastPos[0].tXY[l].x) >> 1;
				thisInfo->tCoord.tPos.tXY[l].y = (thisInfo->tCoord.tPastPos[0].tXY[l].y + thisInfo->tCoord.tOrgPastPos[0].tXY[l].y) >> 1;
			}
			//thisInfo->tCoord.tPos.tXY[l].x = thisInfo->tCoord.tOrgPos.tXY[l].x = (thisInfo->tCoord.tOrgPastPos[0].tXY[l].x<<1) - thisInfo->tCoord.tOrgPastPos[1].tXY[l].x;
			//thisInfo->tCoord.tPos.tXY[l].y = thisInfo->tCoord.tOrgPos.tXY[l].y = (thisInfo->tCoord.tOrgPastPos[0].tXY[l].y<<1) - thisInfo->tCoord.tOrgPastPos[1].tXY[l].y;
			int iDist = algorithm_coord_calc_distance(thisInfo->tCoord.tPos.tXY[l], thisInfo->tCoord.tPastPos[0].tXY[l]);
			if(iDist>(thisModeConf->Coord.usMoveDistanceThd << POS_BOOST_SHIFT_))
			{
				thisInfo->tCoord.tPastPos[4].vusS[l] = thisInfo->tCoord.tPastPos[3].vusS[l] = thisInfo->tCoord.tPastPos[2].vusS[l] = thisInfo->tCoord.tPastPos[1].vusS[l] = thisInfo->tCoord.tPastPos[0].vusS[l] = thisInfo->tCoord.tPos.vusS[l] = 0;
				thisInfo->tCoord.tPastPos[4].vusR[l] = thisInfo->tCoord.tPastPos[3].vusR[l] = thisInfo->tCoord.tPastPos[2].vusR[l] = thisInfo->tCoord.tPastPos[1].vusR[l] = thisInfo->tCoord.tPastPos[0].vusR[l] = thisInfo->tCoord.tPos.vusR[l] = 0;
			}
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
		}
		else
		{
			thisInfo->tCoord.tPastPos[4].vusS[l] = thisInfo->tCoord.tPastPos[3].vusS[l] = thisInfo->tCoord.tPastPos[2].vusS[l] = thisInfo->tCoord.tPastPos[1].vusS[l] = thisInfo->tCoord.tPastPos[0].vusS[l] = thisInfo->tCoord.tPos.vusS[l] = 0;
			thisInfo->tCoord.tPastPos[4].vusR[l] = thisInfo->tCoord.tPastPos[3].vusR[l] = thisInfo->tCoord.tPastPos[2].vusR[l] = thisInfo->tCoord.tPastPos[1].vusR[l] = thisInfo->tCoord.tPastPos[0].vusR[l] = thisInfo->tCoord.tPos.vusR[l] = 0;
		}
	}
}

void algorithm_coord_interpolation_v02(uint8_t Ver)
{	
	tXY_t /*PredPos, ControlPos,*/BezierPos,AvgPos;
	int P1,P2,coef = 1;
	for (int l = 0; l < MAX_TOUCH_; l++)
	{
		thisInfo->tCoord.tTempPos.vusR[l] = thisInfo->tCoord.tPos.vusR[l];
		thisInfo->tCoord.tTempPos.vusS[l] = thisInfo->tCoord.tPos.vusS[l];
		thisInfo->tCoord.tTempPos.tXY[l] = thisInfo->tCoord.tPos.tXY[l];
		if( thisInfo->tCoord.tPastPos[0].vusR[l] && thisInfo->tCoord.tPos.vusR[l] )
		{
			if(Ver >= 3 && thisInfo->tCoord.tPastPos[2].vusS[l]>0 && thisInfo->tCoord.DrawingFlag[l] )
			{
				P1 = algorithm_coord_calc_distance(thisInfo->tCoord.tPos.tXY[l],thisInfo->tCoord.tPastPos[0].tXY[l]);
				P2 = algorithm_coord_calc_distance(thisInfo->tCoord.tPastPos[2].tXY[l],thisInfo->tCoord.tPastPos[0].tXY[l]);

				P1 += coef;
				P2 += coef;

				BezierPos.x = ((3*(thisInfo->tCoord.tPos.tXY[l].x + (thisInfo->tCoord.tPastPos[0].tXY[l].x<<1)) - thisInfo->tCoord.tPastPos[2].tXY[l].x)>>3);
				BezierPos.y = ((3*(thisInfo->tCoord.tPos.tXY[l].y + (thisInfo->tCoord.tPastPos[0].tXY[l].y<<1)) - thisInfo->tCoord.tPastPos[2].tXY[l].y)>>3);
				
				AvgPos.x = ((thisInfo->tCoord.tPos.tXY[l].x + thisInfo->tCoord.tPastPos[0].tXY[l].x)>>1);
				AvgPos.y = ((thisInfo->tCoord.tPos.tXY[l].y + thisInfo->tCoord.tPastPos[0].tXY[l].y)>>1);
				
				thisInfo->tCoord.tPos.tXY[l].x = (AvgPos.x * abs(P1-P2) + BezierPos.x * (P1+P2 - abs(P1-P2)) ) / (P1 + P2);
				thisInfo->tCoord.tPos.tXY[l].y = (AvgPos.y * abs(P1-P2) + BezierPos.y * (P1+P2 - abs(P1-P2)) ) / (P1 + P2);
			}
			else 
			{
				thisInfo->tCoord.tPos.tXY[l].x = ((thisInfo->tCoord.tPos.tXY[l].x + thisInfo->tCoord.tPastPos[0].tXY[l].x)>>1);
				thisInfo->tCoord.tPos.tXY[l].y = ((thisInfo->tCoord.tPos.tXY[l].y + thisInfo->tCoord.tPastPos[0].tXY[l].y)>>1);
			}
		}
	}
	
	algorithm_PendTouchEvent();
	algorithm_coord_UpdatePosHistoryInfo();
	
	for (int l = 0; l < MAX_TOUCH_; l++)
	{
		thisInfo->tCoord.tPos.vusR[l] = thisInfo->tCoord.tTempPos.vusR[l];
		thisInfo->tCoord.tPos.vusS[l] = thisInfo->tCoord.tTempPos.vusS[l];
		thisInfo->tCoord.tPos.tXY[l] = thisInfo->tCoord.tTempPos.tXY[l];
	}
	if(Ver == 4)
	{
		algorithm_PendTouchEvent();
		algorithm_coord_UpdatePosHistoryInfo();
	}
}



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
					MaxSumTB = thisModeConf->Coord.usTopEdgeExpand_MaxD;				
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
					MaxSumTB = thisModeConf->Coord.usBottomEdgeExpand_MaxD;				
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
					MaxSumLR = thisModeConf->Coord.usLeftEdgeExpand_MaxD;				
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
					MaxSumLR = thisModeConf->Coord.usRightEdgeExpand_MaxD;				
					bContiFlag[3] = 1;
				}
			}
			
			if(MaxSumTB && !MaxSumLR)
			{
				if(temp_label->tTable[l].tMaxCell.c <= 2){MaxSumLR = thisModeConf->Coord.usLeftEdgeExpand_MaxD;apply_c=-1;}
				else if(temp_label->tTable[l].tMaxCell.c >= COL_MAX-3){MaxSumLR = thisModeConf->Coord.usRightEdgeExpand_MaxD;apply_c=COL_MAX;}
			}
			else if(!MaxSumTB && MaxSumLR)
			{
				if(temp_label->tTable[l].tMaxCell.r <= 2){MaxSumTB = thisModeConf->Coord.usTopEdgeExpand_MaxD;apply_r=-1;}
				else if(temp_label->tTable[l].tMaxCell.r >= ROW_MAX-3){MaxSumTB = thisModeConf->Coord.usBottomEdgeExpand_MaxD;apply_r=ROW_MAX;}				
			}
			
			if(MaxSumTB || MaxSumLR)
			{
				TmpExtStrength = temp_label->tTable[l].ulExtStrength;
				TmpBigFingerEdgeExpandParam2_TB = thisModeConf->Coord.usBigFingerEdgeExpandParam2;
				TmpBigFingerEdgeExpandParam2_LR = thisModeConf->Coord.usBigFingerEdgeExpandParam2;
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
									TmpBigFingerEdgeExpandParam2_LR = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(62);
									TmpBigFingerEdgeExpandParam2_TB = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(62);
								}
								else
								{
									TmpBigFingerEdgeExpandParam2_LR = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(62);
									TmpBigFingerEdgeExpandParam2_TB = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(62);	
								}								
							}
							else
							{
								if(apply_c == -1)
								{
									TmpBigFingerEdgeExpandParam2_LR = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(62);
									TmpBigFingerEdgeExpandParam2_TB = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(62);
								}
								else
								{
									TmpBigFingerEdgeExpandParam2_LR = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(62);
									TmpBigFingerEdgeExpandParam2_TB = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(62);	
								}
							}
						}
						else
						{
							if(sum_LR > sum_TB)
							{
								TmpBigFingerEdgeExpandParam2_LR = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(30);
								TmpBigFingerEdgeExpandParam2_TB = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(10);
							}
							else 
							{
								TmpBigFingerEdgeExpandParam2_TB = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(30);
								TmpBigFingerEdgeExpandParam2_LR = thisModeConf->Coord.usBigFingerEdgeExpandParam2-(10);
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
				_d = thisModeConf->Coord.usBigFingerEdgeExpandParam1-temp_label->tTable[l].sMaxCellVal;
				_d = _d*_d;
				_d1 = (temp_label->usValidCellCnt[l]*TmpExtStrength*(temp_label->tTable[l].tRect.ce-temp_label->tTable[l].tRect.cs))/TmpBigFingerEdgeExpandParam2_TB;				
				_d1 = _d1*_d1;
				if(_d1 > 0)
				{
					_d = _d/_d1;
					_d1 = MAX(0,(int)(thisModeConf->Coord.usBigFingerEdgeExpandParam3-TmpExtStrength));
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
							if(thisModeConf->Coord.usBigFingerEdgeTestClippingTop && !bBigFingerEdgeTestEn[0])	
							{
								bBigFingerEdgeTestFlag[0] = 1;
								bBigFingerEdgeTestEn[0] = 1;
							}
						}
						else
						{
							if(thisModeConf->Coord.usBigFingerEdgeTestClippingBottom && !bBigFingerEdgeTestEn[1])
							{								
								bBigFingerEdgeTestFlag[1] = 1;
								bBigFingerEdgeTestEn[1] = 1;
							}
						}
						
						if(thisModeConf->Coord.usBigFingerEdgeTest_MoveEventTHD_Y)
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
				_d = thisModeConf->Coord.usBigFingerEdgeExpandParam1-temp_label->tTable[l].sMaxCellVal;
				_d = _d*_d;
				_d1 = (temp_label->usValidCellCnt[l]*TmpExtStrength*(temp_label->tTable[l].tRect.re-temp_label->tTable[l].tRect.rs))/TmpBigFingerEdgeExpandParam2_LR;				
				_d1  = _d1*_d1;	
				if(_d1 > 0)
				{					
					_d = _d/_d1;
					_d1 = MAX(0,(int)(thisModeConf->Coord.usBigFingerEdgeExpandParam3-TmpExtStrength));
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
							if(thisModeConf->Coord.usBigFingerEdgeTestClippingLeft && !bBigFingerEdgeTestEn[2])	
							{
								bBigFingerEdgeTestFlag[2] = 1;
								bBigFingerEdgeTestEn[2] = 1;
							}
						}
						else
						{
							if(thisModeConf->Coord.usBigFingerEdgeTestClippingRight && !bBigFingerEdgeTestEn[3])
							{								
								bBigFingerEdgeTestFlag[3] = 1;
								bBigFingerEdgeTestEn[3] = 1;
							}
						}
						
						if(thisModeConf->Coord.usBigFingerEdgeTest_MoveEventTHD_X)
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
	tLabelInfo_t	*temp_label = &thisInfo->tLabel;
	
	for(l=temp_label->ucNum;l--;)
	{
		if( temp_label->tTable[l].ulStrength )
		{
			search_r = -1, search_c = -1;
			if(temp_label->tTable[l].tMaxCell.r <= 1){
				search_r = 0, search_r1 = 1, apply_r = -1;
				offset_r = thisModeConf->Coord.usTopEdgeExpand_Offset;
				scale_r  = thisModeConf->Coord.usTopEdgeExpand_Scale;
			}

			if(temp_label->tTable[l].tMaxCell.r >= ROW_MAX-2){
				search_r = ROW_MAX-1, search_r1 = ROW_MAX-2, apply_r = ROW_MAX;
				offset_r = thisModeConf->Coord.usBottomEdgeExpand_Offset;
				scale_r	 = thisModeConf->Coord.usBottomEdgeExpand_Scale;
			}

			if(temp_label->tTable[l].tMaxCell.c <= 1){
				search_c = 0, search_c1 = 1, apply_c = -1;
				offset_c = thisModeConf->Coord.usLeftEdgeExpand_Offset;
				scale_c  = thisModeConf->Coord.usLeftEdgeExpand_Scale;
			}

			if(temp_label->tTable[l].tMaxCell.c >= COL_MAX-2){
				search_c = COL_MAX-1, search_c1 = COL_MAX-2, apply_c = COL_MAX;
				offset_c = thisModeConf->Coord.usRightEdgeExpand_Offset;
				scale_c  = thisModeConf->Coord.usRightEdgeExpand_Scale;
			}
			
			if(search_r != -1)													//Top, bottom edge
			{
				_d =_d1 =_d2 = 0;
				
				if(!(offset_r==0 && scale_r==0))
				{
					edge_sum = 0;
					for(c = temp_label->tValidRect[l].cs; c <= temp_label->tValidRect[l].ce; c++)
					{
						if(HAL_READ_LABEL_IMAGE(search_r, c) == l+1){
							edge_sum += HAL_READ_DELTA_IMAGE(search_r, c);
						}
					}
					
					for(c = temp_label->tValidRect[l].cs; c <= temp_label->tValidRect[l].ce; c++)	//Column
					{
						rLabel_val = HAL_READ_LABEL_IMAGE(search_r, c);
						
						if(rLabel_val == l+1)
						{
							_d2 = 0;
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
					for(r = temp_label->tValidRect[l].rs; r <= temp_label->tValidRect[l].re; r++)
					{
						if(HAL_READ_LABEL_IMAGE(r, search_c) != 0){
							edge_sum += HAL_READ_DELTA_IMAGE(r, search_c);
						}
					}
					
					for(r = temp_label->tValidRect[l].rs; r <= temp_label->tValidRect[l].re; r++)	//Row
					{
						rLabel_val = HAL_READ_LABEL_IMAGE(r, search_c);
						
						if(rLabel_val == l+1)
						{
							_d2 = 0;
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
		max_d = 100;
	}
}

#ifdef TILT_ON
extern tRingMSInfo_t pTRingInfo;
void algorithm_coordi_compen_with_tilt(uint8_t Tilt_On, uint8_t mode)
{
	int coef_x,coef_y,cs;
	bool_t Shift_En = 1;
	bool_t Edge_F = 0;
	int compen_thresh_value = thisModeConf->PenTilt.ucCoordiShiftWithTiltCompenTH*10;
	
	if( ( (Tilt_On==1 && mode == LOCAL_MODE) || (Tilt_On==2 && thisInfo->tPenInfo.bPen_button[0] == 0) || (Tilt_On==3 /*&& mode == LOCAL_MODE*/)) && thisInfo->tTiltInfo.sTilt_cnt > 1 )
	{
	#ifdef SW_RATE_UP_EN
		if(thisInfo->tPenInfo.bRateUpFlag == 0)				
	#endif
		{
			if(algorithm_coord_IsEdgeArea(&thisInfo->tCoord_local_dsp.tOrgPos.tXY, 0))
			{
				if(thisModeConf->PenTilt.ucCoordiShiftEdgeOn > 0)
				{
					if(thisModeConf->PenTilt.ucCoordiShiftEdgeOn > 1)Edge_F=1;
				}
				else Shift_En = 0;
			}
			
			if(Shift_En == 1)
			{	
//				if(Tilt_On == 1 || Tilt_On==3)
				{
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)// || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)  				
					coef_x = coef_y = 30;
					if(thisInfo->tTiltInfo.sTilt_cnt < 18 
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
					&& Tilt_On == 1 
		/*#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
					&& Tilt_On == 3 */
		#endif
					)	
					{
						coef_x -= (thisInfo->tTiltInfo.sTilt_cnt - 2);
						coef_y -= (thisInfo->tTiltInfo.sTilt_cnt - 2);
					}
					else	
	#endif
					{
						coef_x = thisModeConf->PenTilt.ucCoordiShiftX_WithTilt; //15
						coef_y = thisModeConf->PenTilt.ucCoordiShiftY_WithTilt;
					}
					
					if(Edge_F)
					{
						int dis,min_dis = 32767;
						dis = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x - 0;
						if(dis < min_dis)min_dis = dis;
						dis = thisInfo->tCoord.iInternalXRes - thisInfo->tCoord_local_dsp.tOrgPos.tXY.x;
						if(dis < min_dis)min_dis = dis;
						dis = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y - 0;
						if(dis < min_dis)min_dis = dis;
						dis = thisInfo->tCoord.iInternalYRes - thisInfo->tCoord_local_dsp.tOrgPos.tXY.y;
						if(dis < min_dis)min_dis = dis;
						
						coef_x += (UNIT_DIST - min_dis)/8;
						coef_y += (UNIT_DIST - min_dis)/8;
					}
				}
//				else if(Tilt_On == 2)
//				{
////					compen_thresh_value = 100;
//					//if(mode == LOCAL_MODE)
//					{
////						coef_x = 30;
////						if(thisInfo->tTiltInfo.sTilt_cnt < 25)	
////						{
////							coef_x -= (thisInfo->tTiltInfo.sTilt_cnt - 2);
////							coef_y -= (thisInfo->tTiltInfo.sTilt_cnt - 2);
////						}
////						else
//						{
//							coef_x = thisModeConf->PenTilt.ucCoordiShiftX_WithTilt; //8;
//							coef_y = thisModeConf->PenTilt.ucCoordiShiftY_WithTilt;
//						}
//					}
//					//else coef_x = coef_y = 12;
//					
//					if(Edge_F)
//					{
//						int dis,min_dis = 32767;
//						dis = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x - 0;
//						if(dis < min_dis)min_dis = dis;
//						dis = thisInfo->tCoord.iInternalXRes - thisInfo->tCoord_local_dsp.tOrgPos.tXY.x;
//						if(dis < min_dis)min_dis = dis;
//						dis = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y - 0;
//						if(dis < min_dis)min_dis = dis;
//						dis = thisInfo->tCoord.iInternalYRes - thisInfo->tCoord_local_dsp.tOrgPos.tXY.y;
//						if(dis < min_dis)min_dis = dis;
//						
//						coef_x += (UNIT_DIST - min_dis)/8;
//						coef_y += (UNIT_DIST - min_dis)/8;
//					}
//				}

/*
 * TODO : *10 Code Common하게 적용!!!
 */
//	#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT)	
				if(thisInfo->tCoord_local_dsp.tAvgPos.x == 0 && pTRingInfo.s3x3Val > thisModeConf->PenTilt.ucCoordiShiftWithTilt_RingTH*10)
//	#else
//				if(thisInfo->tCoord_local_dsp.tAvgPos.x == 0 && thisInfo->tTiltInfo.sRing_ExtStrength > thisModeConf->PenTilt.ucCoordiShiftWithTilt_RingTH*10)
//	#endif
				{
	//				if(thisInfo->tTiltInfo.HID_TILT_X<6500 || thisInfo->tTiltInfo.HID_TILT_X>11500)
					if(thisInfo->tTiltInfo.HID_TILT_X<(9000-compen_thresh_value) || thisInfo->tTiltInfo.HID_TILT_X>(9000+compen_thresh_value))
					{
						cs = ((thisInfo->tTiltInfo.HID_TILT_X - 9000)/10)/coef_x;
						thisInfo->tCoord_local_dsp.tPos.tXY.x -= cs;
						thisInfo->tCoord_local_dsp.tOrgPos.tXY.x = thisInfo->tCoord_local_dsp.tPos.tXY.x;
					}
					
	//						if(Tilt_On == 2)
	//							ce = 3;
	//				if(thisInfo->tTiltInfo.HID_TILT_Y<6500 || thisInfo->tTiltInfo.HID_TILT_Y>11500)
					if(thisInfo->tTiltInfo.HID_TILT_Y<(9000-compen_thresh_value) || thisInfo->tTiltInfo.HID_TILT_Y>(9000+compen_thresh_value))
					{
						cs = ((thisInfo->tTiltInfo.HID_TILT_Y - 9000)/10)/coef_y;
						thisInfo->tCoord_local_dsp.tPos.tXY.y -= cs;
						thisInfo->tCoord_local_dsp.tOrgPos.tXY.y = thisInfo->tCoord_local_dsp.tPos.tXY.y;
					}
				}
			}
	#if (OrgPastPosInterpolation_OPCODE>0)
			if(Tilt_On == 1 && g_RetVal==PARTIAL_PEN_COORD3 && thisInfo->tCoord_local_dsp.tOrgPastPos[1].vusS > 0 && thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS > 0 && thisInfo->tCoord_local_dsp.tOrgPos.vusS > 0)
			{
				thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x = (thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.x + thisInfo->tCoord_local_dsp.tOrgPos.tXY.x)>>1;
				thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y = (thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.y + thisInfo->tCoord_local_dsp.tOrgPos.tXY.y)>>1;
			}
	#endif
		}
	}
//	else if(Tilt_On == 2)
//	{
//		thisInfo->tPenInfo.bReportSkip = 1;
//	}
	
//	if(Tilt_On == 2 && mode == LOCAL_HOVER_MODE)
//	{
//		thisInfo->tTiltInfo.HID_TILT_X = 9000;
//		thisInfo->tTiltInfo.HID_TILT_Y = 9000;
//	}
}
#endif /* #ifdef TILT_ON */

#if 0
int speed,Latency;
void algorithm_coord_latency_cal_test_pen(void)
{
	tPenCoordInfo_t 	*temp_coord;
	int dist;
	temp_coord = &thisInfo->tCoord_local_dsp;
	
	if(temp_coord->tOrgPos.vusS > 0 && temp_coord->tOrgPastPos[0].vusS > 0 && temp_coord->tOrgPastPos[1].vusS > 0 && temp_coord->tOrgPastPos2.vusS > 0)
	{
		speed = 0;
		dist = algorithm_coord_calc_distance(temp_coord->tOrgPos.tXY,temp_coord->tOrgPastPos[0].tXY);
		dist = 3500 * dist/256;
		speed = dist/4;
		
		dist = algorithm_coord_calc_distance(temp_coord->tOrgPastPos[0].tXY,temp_coord->tOrgPastPos[1].tXY);
		dist = 3500 * dist/256;
		speed += dist/4;
		
		dist = algorithm_coord_calc_distance(temp_coord->tOrgPastPos[1].tXY,temp_coord->tOrgPastPos2.tXY);
		dist = 3500 * dist/256;
		speed += dist/4;
		
		speed /= 3;
		
		dist = algorithm_coord_calc_distance(temp_coord->tOrgPos.tXY,temp_coord->tPos.tXY);
		dist = 3500 * dist/256;
		Latency = dist*100/speed;
	}
}

void algorithm_coord_latency_cal_test(void)
{
	tCoordInfo_t 	*temp_coord;
	int dist;
	temp_coord = &thisInfo->tCoord;
	
	if(temp_coord->tOrgPos.vusS[0] > 0 && temp_coord->tOrgPastPos[0].vusS[0] > 0 && temp_coord->tOrgPastPos[1].vusS[0] > 0 && temp_coord->tOrgPastPos[2].vusS[0] > 0)
	{
		speed = 0;
		dist = algorithm_coord_calc_distance(temp_coord->tOrgPos.tXY[0],temp_coord->tOrgPastPos[0].tXY[0]);
		dist = 3500 * dist/256;
		speed = dist/8;
		
		dist = algorithm_coord_calc_distance(temp_coord->tOrgPastPos[0].tXY[0],temp_coord->tOrgPastPos[1].tXY[0]);
		dist = 3500 * dist/256;
		speed += dist/8;
		
		dist = algorithm_coord_calc_distance(temp_coord->tOrgPastPos[1].tXY[0],temp_coord->tOrgPastPos[2].tXY[0]);
		dist = 3500 * dist/256;
		speed += dist/8;
		
		speed /= 3;
		
		dist = algorithm_coord_calc_distance(temp_coord->tOrgPos.tXY[0],temp_coord->tPos.tXY[0]);
		dist = 3500 * dist/256;
		Latency = dist*100/speed;
	}
}
#endif

#if 0//(USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
int OneCellPosX;
int OneCellPosY;
void algorithm_coordi_compen_by_incline(uint8_t mode)
{
	int i;
	int srart_i = MAX(0,thisInfo->tLabel_local_dsp.tValidMaxPos.c - 2);
	int end_i = MIN(COL_MAX,thisInfo->tLabel_local_dsp.tValidMaxPos.c + 2);
	int max_r = thisInfo->tLabel_local_dsp.tValidMaxPos.r;
	int max_c = thisInfo->tLabel_local_dsp.tValidMaxPos.c;
	int top_sum = 0;
	int bottom_sum = 0;
	
	if(1 < max_r && max_r < 4)
	{
		for(i = srart_i; i <= end_i; i++)
		{
			if(max_r == 2)
			{
				top_sum += HAL_READ_LOCAL_DELTA_IMAGE(max_r-2,i);
				bottom_sum += HAL_READ_LOCAL_DELTA_IMAGE(max_r+2,i);
			}
			else if(max_r == 1)
			{
				top_sum += HAL_READ_LOCAL_DELTA_IMAGE(max_r-1,i)/2;
				bottom_sum += HAL_READ_LOCAL_DELTA_IMAGE(max_r+2,i);
			}
			else if(max_r == 3)
			{
				top_sum += HAL_READ_LOCAL_DELTA_IMAGE(max_r-2,i);
				bottom_sum += HAL_READ_LOCAL_DELTA_IMAGE(max_r+1,i)/2;
			}
		}
	}

	srart_i = 0;
	end_i = 5;
	int left_sum = 0;
	int right_sum = 0;
	
	if(1< max_c && max_c < COL_MAX-2)
	{
		for(i = srart_i; i <= end_i; i++)
		{
			left_sum += HAL_READ_LOCAL_DELTA_IMAGE(i,max_c-2);
			right_sum += HAL_READ_LOCAL_DELTA_IMAGE(i,max_c+2);
		}
	}
	
	dbg_coord[0] = top_sum;
	dbg_coord[1] = bottom_sum;
	dbg_coord[2] = left_sum;
	dbg_coord[3] = right_sum;
	
	int coef_x = (right_sum - left_sum) * dbg_coord[4];
	int coef_y = (bottom_sum - top_sum) * dbg_coord[4];
	
	coef_x/=100;
	coef_y/=100;
	
	int x = thisInfo->tCoord_local_dsp.tPos.tXY.x; // + (UNIT_DIST>>1);
	int y = thisInfo->tCoord_local_dsp.tPos.tXY.y; //+ (UNIT_DIST>>1);
	int XResol = UNIT_DIST;
	int YResol = UNIT_DIST;	
	OneCellPosX = x - (((int)x/(XResol))*(XResol));
	OneCellPosY = y - (((int)y/(YResol))*(YResol));

	if(dbg_coord[7]	> 1)
	{
		dbg_coord[5] = abs(OneCellPosX - XResol*0.5) * dbg_coord[7];
		dbg_coord[5] /= 100;
		coef_x = coef_x - dbg_coord[5];
		
		dbg_coord[6] = abs(OneCellPosY - YResol*0.5) * dbg_coord[7];
		dbg_coord[6] /= 100;	
		coef_y = coef_y - dbg_coord[6];
	}
	else if(dbg_coord[7] == 1)
	{		
		if(OneCellPosX < XResol*0.25 || OneCellPosX > XResol*0.75)
		{
			coef_x = coef_x - dbg_coord[5];
		}

		if(OneCellPosY < YResol*0.25 || OneCellPosY > YResol*0.75)
		{
			coef_y = coef_y - dbg_coord[6];
		}
	}
	else if(dbg_coord[7] == 0)
	{		
		if(OneCellPosX > XResol*0.25 && OneCellPosX < XResol*0.75)
		{
			coef_x = coef_x + dbg_coord[5];
		}

		if(OneCellPosY > YResol*0.25 && OneCellPosY < YResol*0.75)
		{
			coef_y = coef_y + dbg_coord[6];
		}
	}
	
	thisInfo->tCoord_local_dsp.tPos.tXY.x -= coef_x;
	thisInfo->tCoord_local_dsp.tOrgPos.tXY.x = thisInfo->tCoord_local_dsp.tPos.tXY.x;
	
	thisInfo->tCoord_local_dsp.tPos.tXY.y -= coef_y;
	thisInfo->tCoord_local_dsp.tOrgPos.tXY.y = thisInfo->tCoord_local_dsp.tPos.tXY.y;
}
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */

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
	if(thisModeConf->Coord.bWinCertDrawingAssistanceOn)
		algorithm_coord_drawing_assistance(mode);
#endif
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Algorithm Coord. Tracking
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    algorithm_coord_tracking_pos(mode);
		
//#ifndef COVER_GLASS_USE
//	algorithm_coord_compensation(mode);
//#endif
	
    algorithm_coord_smoothing_pos(mode);
	
	if(thisModeConf->Coord.usOutInDrawEdgeTh)
		algorithm_coord_OutInDrawing();
	
//	algorithm_coord_latency_cal_test();
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Algorithm Coord. Post-Procssing
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	if(thisModeConf->Coord.cPostProcessEndMargin == 0)
//		algorithm_coord_PostProcess(mode);
//	else
		algorithm_coord_PostProcess_1();
#if ConflictLinearity	
	for( int id = 1; id<MAX_TOUCH_; id++){
		thisInfo->tCoord.tPos.vusS[id] = 0;
	}
#endif
}
