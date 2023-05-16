/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  algorithm_noise.c
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


#if USED_NOISE_HOPPING_FREQ
static const tAlgorithmModeConf_t * thisModeConf = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;
static tAppInfo_t * ptAppInfo = NULL;

int add_hopping_thd = 0;
int DiffIIR = 0,RealDiffIIR = 0, RealDiffNoiseCnt = 0;

//extern uint8_t HoppingInitFlag;

void algorithm_noise_init(void)
{
	thisModeConf = algorithm_GetModeConfig();
	thisInfo = algorithm_GetInfo();
	ptAppInfo = app_GetInfo();
}

void algorithm_noise_initialize(void)
{
	thisInfo->tNoise.ucInitFCnt = 0;
	thisInfo->tNoise.ucFCnt = 0;
	thisInfo->tNoise.ucBCnt = 0;
	thisInfo->tNoise.bDetectStart = NO;
	thisInfo->tNoise.ucPrevFinger = 0;
	thisInfo->tNoise.ulSumMaxDiff = 0;
	thisInfo->tNoise.ucTouchOffCnt = 0;
	thisInfo->tNoise.NoiseFlag = 0;

	memset((void *)&thisInfo->tNoise.usMaxValBuf, 0x00, sizeof(thisInfo->tNoise.usMaxValBuf));
	memset((void *)&thisInfo->tNoise.ucTouchNumBuf, 0, sizeof(thisInfo->tNoise.ucTouchNumBuf));
	thisInfo->tNoise.ucNoiseFrameCnt = 0;
}

bool_t test_bHoppingFlag = FALSE;
#if (NOISE_DETECTION_VER1_EN == YES)
void algorithm_noise_detection(void)
{
//	int16_t  i, r, c; // NOTE : not used
	int16_t i;
	int16_t MaxCellNum = INT16_MIN;
	uint8_t CurrFinger = 0;
	uint8_t CurrHoppingMode = ptAppInfo->eSelectFreq;//custom_GetHoppingFreq();
	uint16_t CurrMaxVal = 0;
	uint16_t AvgMaxDiff = 0;
	uint16_t LabelNum = 0;
//	bool_t   bHoppingFlag = 0; // NOTE : not used

	// Need Filtering
	if( CurrHoppingMode == thisInfo->tNoise.ucPrevHoppingMode )
	{
		if( thisInfo->bTouchExpect )//&& thisInfo->bRecalFlag == NO )
		{
			if( thisInfo->tNoise.ucInitFCnt >= thisModeConf->Noise.ucDiscardFrameNum )
			{
				for( i=MAX_TOUCH_; i--; )
				{
					if( MaxCellNum < thisInfo->tLabel.usValidCellCnt[i] )
					{
						MaxCellNum = thisInfo->tLabel.usValidCellCnt[i];
					}
				}

				if( MaxCellNum >= thisModeConf->Noise.ucCellCntThd )
				{
					CurrFinger = thisInfo->tLabel.ucValidNum;

					if(CurrFinger==2)
						thisInfo->tNoise.uc2FingerCnt++;
					else
						thisInfo->tNoise.uc2FingerCnt=0;

					if( CurrFinger == thisInfo->tNoise.ucPrevFinger )
					{
						CurrMaxVal = thisInfo->tDelta.iMaxStrength;
						if( thisInfo->tNoise.ucInitFCnt != thisModeConf->Noise.ucDiscardFrameNum)
						{
							int16_t Diff;

							Diff = (CurrMaxVal - thisInfo->tNoise.usPrevMaxVal);

							thisInfo->tNoise.ulSumMaxDiff -= thisInfo->tNoise.usMaxValBuf[thisInfo->tNoise.ucBCnt];

							if( Diff < 0 )
							{
								Diff = -Diff;
							}

							thisInfo->tNoise.usMaxValBuf[thisInfo->tNoise.ucBCnt] = Diff;
							thisInfo->tNoise.ulSumMaxDiff += Diff;
							
							thisInfo->tNoise.ucBCnt++;
							if( thisInfo->tNoise.ucBCnt == (NOISE_DETECTION_FRAME_NUM-1) )
							{
								thisInfo->tNoise.ucBCnt = 0;
							}
						}

						thisInfo->tNoise.ucFCnt++;

						if( thisInfo->tNoise.ucFCnt == (NOISE_DETECTION_FRAME_NUM) )
						{
							thisInfo->tNoise.ucFCnt = 0;
							thisInfo->tNoise.bDetectStart = 1;
						}

						if( thisInfo->tNoise.bDetectStart )
						{
							AvgMaxDiff = thisInfo->tNoise.ulSumMaxDiff / (NOISE_DETECTION_FRAME_NUM-1);
						}
					}
				}
			}
			thisInfo->tNoise.ucPrevFinger = thisInfo->tLabel.ucValidNum;
			thisInfo->tNoise.usPrevMaxVal = thisInfo->tDelta.iMaxStrength;

			if( thisInfo->tNoise.ucInitFCnt < NOISE_DETECTION_FRAME_NUM )
			{
				thisInfo->tNoise.ucInitFCnt++;
			}
			thisInfo->tNoise.ucTouchOffCnt = 0;
		}
		else // bExpect
		{
			algorithm_noise_initialize();
		}
	}
	else // Frequency Change
	{
		algorithm_noise_initialize();
	}
	thisInfo->tNoise.ucPrevHoppingMode = CurrHoppingMode;
   
	if(thisInfo->tNoise.ucNoiseFrameCnt >= 100)
	{
		thisInfo->tNoise.ucNoiseFrameCnt = 0;
	}
	else
	{      
		thisInfo->tNoise.ucNoiseFrameCnt++;
	}

	
	for( i=0; i<MAX_TOUCH_; i++)
	{
		if( thisInfo->tCoord.tPos.vusS[i] > 0 )
		{
			LabelNum++;
		}
	}

	if((thisInfo->tDelta.iGroupedCellCnt > 0 && LabelNum > 0) || (thisInfo->tDelta.iGroupedCellCnt > 0 && thisInfo->tDelta.iMaxStrength > 20))
	{
		thisInfo->tNoise.ucNoiseFrameCnt = 0;
		thisInfo->tNoise.ucSetHoppingReady = NO;
	}


	if((thisInfo->tDelta.iGroupedCellCnt > 0 && thisInfo->tNoise.ucSetHoppingReady == NO) && thisInfo->tNoise.ucNoiseFrameCnt > 20)
	{		
		if(LabelNum < 1)
		{
			thisInfo->tNoise.ucNoiseFrameCnt = 0;
			thisInfo->tNoise.ucSetHoppingReady = YES;
		}
		else
		{
          thisInfo->tNoise.ucSetHoppingReady = NO;
		}
	}

	if((thisInfo->tNoise.ucSetHoppingReady && thisInfo->tNoise.ucNoiseFrameCnt == 5) && LabelNum < 1)
	{
//		bHoppingFlag = YES; // NOTE : not used
		thisInfo->tNoise.ucSetHoppingReady = NO;
		thisInfo->tNoise.ucNoiseFrameCnt = 0;
	}

	if( thisInfo->tNoise.NoiseFlag > 0 )
	{
		//thisInfo->tNoise.NoiseFlag = 0;
		AvgMaxDiff = thisModeConf->Noise.ucHoppingThd + 1;
	}
	
	if(AvgMaxDiff > thisModeConf->Noise.ucHoppingThd)
	{
		AvgMaxDiff = thisModeConf->Noise.ucHoppingThd;
		thisInfo->tNoise.NoiseFlag = 0;
	}
}
#endif
uint8_t FreqChangeDelay = 0, CheckHoppingReliability = 0, HoppingThdCnt = 0;
void algorithm_noise_detection_v2(eSENSING_MODE_t eSensingMode)
{
	int16_t i,cl;
	uint8_t CurrFinger = 0;
	uint8_t CurrHoppingMode = ptAppInfo->eSelectFreq;
	uint16_t CurrMaxVal = 0, CurrRealMaxVal = 0;
	int16_t Diff,RealDiff,DiffCnt;
	int dist = 0;
//#if USED_NORMAL_NI_SENSING
//	uint16_t CurrMaxVal_NI = 0;
//	uint16_t AvgMaxDiff_NI = 0;
//#endif /* USED_NORMAL_NI_SENSING */
	tCoordInfo_t 	*temp_coord;

	temp_coord = &thisInfo->tCoord;

//	if(HoppingInitFlag){			//For Idle mode
//		HoppingInitFlag = NO;
//		add_hopping_thd = 0;
//	}

	//If stay at hopping frequency for a long time, Go back to main frequency
	if(CurrHoppingMode == FREQ_HOPP1)
	{
		if(thisInfo->bTouchExpect)
			thisInfo->ulHoppMainRollbackCheckCount = 0;

		if(thisInfo->ulHoppMainRollbackCheckCount > thisInfo->ulHoppMainRollbackFrameCntTHD)
		{
			thisInfo->ulHoppMainRollbackCheckCount = 0;
			ptAppInfo->eNoiseStatus = NOISE_FREQ_HOPPING;
			RealDiffIIR = 0;
			RealDiffNoiseCnt = 0;
			return;
		}

		if(IS_FINGER_PEN_MODE(eSensingMode))
		{
			thisInfo->ulHoppMainRollbackCheckCount += 2;
		}
		else
		{
			thisInfo->ulHoppMainRollbackCheckCount++;
		}
	}
	else{
		thisInfo->ulHoppMainRollbackCheckCount = 0;
	}
	
	if(CurrHoppingMode == thisInfo->tNoise.ucPrevHoppingMode)
	{
		if(CheckHoppingReliability)
		{
			if(!thisInfo->bTouchExpect){
				ptAppInfo->eNoiseStatus = NOISE_FREQ_HOPPING;		//Go back to previous state
			}
			CheckHoppingReliability = NO;
		}
		
		if(FreqChangeDelay){
			FreqChangeDelay--;
			
		}
		else{
			CurrFinger = thisInfo->tLabel.ucValidNum;
			if(thisInfo->bTouchExpect)
			{
				if(CurrFinger == thisInfo->tNoise.ucPrevFinger)
				{
					for (cl = 0; cl < MAX_TOUCH_; cl++){
						if(temp_coord->tPos.vusS[cl] > 0){
							if( temp_coord->bIsMoving[cl] == YES || temp_coord->ucIdMappedCnt[cl] >= thisModeConf->Noise.ucDiscardFrameNum )	//IsMoving
							{
								CurrMaxVal = (thisInfo->tCoord.tPos.vusS[cl]+thisInfo->tCoord.RealMaxDelta[cl])>>2;
								if(CurrRealMaxVal < CurrMaxVal){
									CurrRealMaxVal = CurrMaxVal;
									if(temp_coord->tOrgPastPos[0].vusS[cl] > 0){
										dist = algorithm_coord_calc_distance(temp_coord->tOrgPastPos[0].tXY[cl],temp_coord->tPos.tXY[cl]);
									}
									else{
										dist = 0;
									}							
								}
							}
						}//END touch ID loop
					}
					
					RealDiff = 0;
					DiffCnt = 0;
					if(CurrRealMaxVal > 0){
						if(thisModeConf->Noise.ucNoiseDetectMaxType == 1)
							CurrRealMaxVal = thisInfo->tDelta.iMaxStrength;
						for(i=0;i<NOISE_DETECTION_FRAME_NUM;i++){
							if(thisInfo->tNoise.usMaxValBuf[i] > 0 && thisInfo->tNoise.ucTouchNumBuf[i] == CurrFinger){
								Diff = abs(CurrRealMaxVal - thisInfo->tNoise.usMaxValBuf[i]);
								RealDiff += Diff;
								DiffCnt++;
							}
						}
						if(DiffCnt) RealDiff /= DiffCnt;
						
						RealDiff = RealDiff - (dist>>(POS_BOOST_SHIFT_-3));
						if(RealDiff < 0 ) RealDiff = 0;
						RealDiffIIR = ((RealDiff + RealDiffIIR*3)>>2);
						
						thisInfo->tNoise.usMaxValBuf[thisInfo->tNoise.ucNoiseFrameCnt] = CurrRealMaxVal;
						thisInfo->tNoise.ucTouchNumBuf[thisInfo->tNoise.ucNoiseFrameCnt] = CurrFinger;
						if(thisInfo->tNoise.ucNoiseFrameCnt < NOISE_DETECTION_FRAME_NUM-1)	thisInfo->tNoise.ucNoiseFrameCnt++;
						else																thisInfo->tNoise.ucNoiseFrameCnt = 0;
					}			
					if(RealDiffIIR < 10 && add_hopping_thd)
						HoppingThdCnt++;
					else
						HoppingThdCnt = 0;
					if(HoppingThdCnt > 10){
						add_hopping_thd--;
						HoppingThdCnt = 0;
					}
				}
//				else{	//if(CurrFinger != thisInfo->tNoise.ucPrevFinger)
//					algorithm_noise_initialize();	
//				}
			}
			else 
			{
				if(!thisModeConf->Noise.bInitAddHoppingThd)
				{
					if(add_hopping_thd)
						HoppingThdCnt++;
					else
						HoppingThdCnt = 0;
					if(HoppingThdCnt > 100){
						add_hopping_thd--;
						HoppingThdCnt = 0;
					}		
				}		
				else
				{
					add_hopping_thd = 0;
				}
				algorithm_noise_initialize();

				RealDiffIIR = 0;
				RealDiffNoiseCnt = 0;
			}
		}
	}// Frequency Change
	else
	{
//		thisInfo->tNoise.ucSetHoppingReady = NO;
		FreqChangeDelay = 10;
		algorithm_noise_initialize();
	}

	thisInfo->tNoise.ucPrevFinger = thisInfo->tLabel.ucValidNum;
//	thisInfo->tNoise.usPrevMaxVal = thisInfo->tDelta.iMaxStrength;
	thisInfo->tNoise.ucPrevHoppingMode = CurrHoppingMode;
	
	if( (RealDiffIIR > thisModeConf->Noise.ucHoppingThd + add_hopping_thd && 
		((RealDiffNoiseCnt > thisModeConf->Noise.ucNoiseStartCntThd && thisModeConf->Noise.ucNoiseStartCntThd) || !thisModeConf->Noise.ucNoiseStartCntThd)) )
	{
//		dbgbuf[3]++;
//		if(add_hopping_thd < RealDiffIIR - thisModeConf->Noise.ucHoppingThd)
//			add_hopping_thd = RealDiffIIR - thisModeConf->Noise.ucHoppingThd;
		add_hopping_thd += 15;
		if(add_hopping_thd > thisModeConf->Noise.ucHoppingThd)
			add_hopping_thd = thisModeConf->Noise.ucHoppingThd;

		ptAppInfo->eNoiseStatus = NOISE_FREQ_HOPPING;
		if(thisInfo->bTouchExpect)
			CheckHoppingReliability = YES;

		RealDiffIIR = 0;
		RealDiffNoiseCnt = 0;
	}
	
	if(thisModeConf->Noise.ucNoiseStartThd)
	{
		if(RealDiffIIR > thisModeConf->Noise.ucNoiseStartThd)
		{
			if(RealDiffNoiseCnt < 1800) RealDiffNoiseCnt++;
		}
		else if(RealDiffNoiseCnt > 0)
		{
			RealDiffNoiseCnt--;
		}
	}

//	dbgbuf[0] = ptAppInfo->eSelectFreq;
//	dbgbuf[1] = RealDiffIIR;
//	dbgbuf[2] = add_hopping_thd;
//	dbgbuf[3] = CurrRealMaxVal;
//	dbgbuf[4] = HoppingRollBackCnt;
//
//	dbgbuf[8] = thisInfo->tCoord.tPos.vusS[0];
//	dbgbuf[9] = thisInfo->tCoord.RealMaxDelta[0];
}

bool_t algorithm_noise_detect(void)
{
	if(ptAppInfo->eNoiseStatus == NOISE_FREQ_HOPPING)
	{
		ptAppInfo->eHoppingStatus = FREQ_HOPPING_CHANGED;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool_t algorithm_Check_FreqHopping(void)
{
	bool_t bRet = NO;

#if USE_FORCE_FREQ_HOPPING
	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	{
		ptAppInfo->eHoppingStatus = FREQ_HOPPING_CHANGED;
		bRet = YES;
	}
	return bRet;
#endif /* USE_FORCE_FREQ_HOPPING */
	if (ptAppInfo->eNoiseStatus == NOISE_FREQ_HOPPING)
	{
		ptAppInfo->eNoiseStatus = NOISE_NONE;
		ptAppInfo->eHoppingStatus = FREQ_HOPPING_CHANGED;
		ptAppInfo->ucHoppFrameCnt = 0;
//		usHoppingStatus = FREQ_HOPPING_CHANGED;
#if USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE
		ptAppInfo->bIsHoppFreqBaseUpdateContinueCheckStart = NO;
		ptAppInfo->bIsNormalReadyIdleCheckCountMaintain = NO;
		ptAppInfo->ulHoppFreqBaseUpdateFrameCheckCnt = 0;
		ptAppInfo->ulHoppFreqBaseUpdateContinueCheckCnt = 0;
#endif /* USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE */
		bRet = YES;
	}
#if USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE
	else
	{
		if(HAL_GetHoppBaselineContinueEnControl())
		{
			if(thisInfo->bTouchExpect
#if USED_PEN_MODE_OPERATION
				|| IS_FINGER_PEN_SEARCH_MODE(HAL_GetSensingMode()) || hal_Info_GetPenDectionEnable()
#endif
			)
			{
				ptAppInfo->ulHoppFreqBaseUpdateFrameCheckCnt = 0;
				ptAppInfo->ulHoppFreqBaseUpdateContinueCheckCnt = 0;

				if(ptAppInfo->eSelectFreq != FREQ_MAIN && ptAppInfo->bIsHoppFreqBaseUpdateContinueCheckStart == YES)
				{
					ptAppInfo->ulHoppFreqBaseUpdateContinueCheckCnt = 0;
					ptAppInfo->bIsHoppFreqBaseUpdateContinueCheckStart = NO;
					ptAppInfo->bIsNormalReadyIdleCheckCountMaintain = YES;
					ptAppInfo->eHoppingStatus = FREQ_HOPPING_CHANGED;
					ptAppInfo->ucHoppFrameCnt = 0;
					bRet = YES;
				}
			}
			else
			{
				if(ptAppInfo->eSelectFreq == FREQ_MAIN)
				{
					ptAppInfo->ulHoppFreqBaseUpdateFrameCheckCnt++;
					if(ptAppInfo->ulHoppFreqBaseUpdateFrameCheckCnt > DEF_FREQ_HOPPING_BASELINE_UPDATE_CHECK_CNT_THD)
					{
						ptAppInfo->ulHoppFreqBaseUpdateFrameCheckCnt = 0;
						ptAppInfo->bIsHoppFreqBaseUpdateContinueCheckStart = YES;
						ptAppInfo->bIsNormalReadyIdleCheckCountMaintain = YES;
						ptAppInfo->eHoppingStatus = FREQ_HOPPING_CHANGED;
						ptAppInfo->ucHoppFrameCnt = 0;
						bRet = YES;
					}
				}
				else
				{
					if(ptAppInfo->bIsHoppFreqBaseUpdateContinueCheckStart == YES)
					{
						ptAppInfo->ulHoppFreqBaseUpdateContinueCheckCnt++;
						if(ptAppInfo->ulHoppFreqBaseUpdateContinueCheckCnt > DEF_FREQ_HOPPING_BASELINE_UPDATE_CONTI_CNT_THD)
						{
							ptAppInfo->ulHoppFreqBaseUpdateContinueCheckCnt = 0;
							ptAppInfo->bIsHoppFreqBaseUpdateContinueCheckStart = NO;
							ptAppInfo->bIsNormalReadyIdleCheckCountMaintain = YES;
							ptAppInfo->eHoppingStatus = FREQ_HOPPING_CHANGED;
							ptAppInfo->ucHoppFrameCnt = 0;
							bRet = YES;
						}
					}
				}
			}
		}
		else
		{
			ptAppInfo->ulHoppFreqBaseUpdateContinueCheckCnt = 0;
			ptAppInfo->bIsHoppFreqBaseUpdateContinueCheckStart = NO;
			if(ptAppInfo->eSelectFreq != FREQ_MAIN)
			{
				ptAppInfo->bIsNormalReadyIdleCheckCountMaintain = YES;
				ptAppInfo->eHoppingStatus = FREQ_HOPPING_CHANGED;
				ptAppInfo->ucHoppFrameCnt = 0;
				bRet = YES;
			}
		}
	}
#endif /* USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE */

	return bRet;
}

#if USE_FREQ_HOPPIG_DEBUG
void algorithm_Set_FreqHopp(eNoiseStatus_t _NoiseStatus)
{
	ptAppInfo->eNoiseStatus = _NoiseStatus;
}
#endif

#ifdef FingerAreaLineFilter
extern ePartialSensing_t g_RetVal;
extern eActivePenType_t gAlgoRawDataType;
extern uint16_t * g_pLocalBaseImage;
extern uint16_t * g_pLocalHop1BaseImage;
void algorithm_noise_FingerAreaLineFilter(int start_r, int end_r, int start_c, int end_c, int local_rs, bool_t MuxSum)
{
	if(thisModeConf->SensingFilter.sFingerAreaLineFilterLimit > 0)
	{
		int d_sum,d_cnt,d_sum1,d_cnt1;
		int i,j,r,c,read_raw_data,delta;
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

		
//		if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
//		{
//			pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
//		}
//		else
//		{
//#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
//			pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
//#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
//			pBaseImage = HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR();
//#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
//		}
				
		
		if(MuxSum == 1)j = 2;	
		else
		{
			if(g_RetVal != PARTIAL_PEN_COORD1 && gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)j = 2;
			else j = 1;
		}
		
		for(i = 0; i < 2; i++)
		{			
			for( r=start_r; r<end_r; r++ )
			{
				int r_pos = ((r+local_rs)*COL_MAX);
				d_sum = d_cnt = d_sum1 = d_cnt1 =0;
				for( c=start_c; c<end_c; c++ )
				{
//					if(LOCALFINGERAREA1[r+local_rs][c] == 1)
					if(thisInfo->tPenInfo.LocalFingerArea.rs - thisModeConf->SensingFilter.ucFingerAreaLineFilterOffset <= r+local_rs
					&& thisInfo->tPenInfo.LocalFingerArea.re + thisModeConf->SensingFilter.ucFingerAreaLineFilterOffset >= r+local_rs
					&& thisInfo->tPenInfo.LocalFingerArea.cs - thisModeConf->SensingFilter.ucFingerAreaLineFilterOffset <= c
					&& thisInfo->tPenInfo.LocalFingerArea.ce + thisModeConf->SensingFilter.ucFingerAreaLineFilterOffset >= c)
					{
						read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+i*PEN_COORD_ROW_MAX, c);
						delta = (signed)pBaseImage[r_pos + c] - (signed)read_raw_data;	
						if(delta > thisModeConf->SensingFilter.sFingerAreaLineFilterLimit)
						{
							d_sum += delta;
							d_cnt++;
						}
						
						if(delta < -thisModeConf->SensingFilter.sFingerAreaLineFilterLimit)
						{
							d_sum1 += delta;
							d_cnt1++;								
						}
					}
				}
				
				if(d_cnt > 1)
				{
					d_sum/=d_cnt;
				}

				if(d_cnt1 > 1)
				{
					d_sum1/=d_cnt1;
				}			
				
				if(d_cnt > 1 || d_cnt1 > 1)
				{
					for( c=start_c; c<end_c; c++ )
					{	
//						if(LOCALFINGERAREA1[r+local_rs][c] == 1)
						if(thisInfo->tPenInfo.LocalFingerArea.rs - thisModeConf->SensingFilter.ucFingerAreaLineFilterOffset <= r+local_rs
						&& thisInfo->tPenInfo.LocalFingerArea.re + thisModeConf->SensingFilter.ucFingerAreaLineFilterOffset >= r+local_rs
						&& thisInfo->tPenInfo.LocalFingerArea.cs - thisModeConf->SensingFilter.ucFingerAreaLineFilterOffset <= c
						&& thisInfo->tPenInfo.LocalFingerArea.ce + thisModeConf->SensingFilter.ucFingerAreaLineFilterOffset >= c)
						{					
							if(d_cnt > 1)
							{
								read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+i*PEN_COORD_ROW_MAX, c);
								delta = (signed)pBaseImage[r_pos + c] - (signed)read_raw_data;	
								if(delta >  thisModeConf->SensingFilter.sFingerAreaLineFilterLimit)
								{
									read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+i*PEN_COORD_ROW_MAX, c) - d_sum;
									if(read_raw_data < 0)read_raw_data = 0;
									HAL_WRITE_LOCAL_RAW_IMAGE(r+i*PEN_COORD_ROW_MAX, c, read_raw_data);
								}
							}

							if(d_cnt1 > 1)
							{
								read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+i*PEN_COORD_ROW_MAX, c);
								delta = (signed)pBaseImage[r_pos + c] - (signed)read_raw_data;	
								if(delta < -thisModeConf->SensingFilter.sFingerAreaLineFilterLimit)
								{
									read_raw_data = HAL_READ_LOCAL_RAW_IMAGE(r+i*PEN_COORD_ROW_MAX, c) + d_sum1;
									if(read_raw_data < 0)read_raw_data = 0;
									HAL_WRITE_LOCAL_RAW_IMAGE(r+i*PEN_COORD_ROW_MAX, c, read_raw_data);
								}
							}
						}
					}	
				}				
			}
		}
	}
}
#endif

void algorithm_noise_process(eSENSING_MODE_t eSensingMode)
{
#if (NOISE_DETECTION_VER1_EN == YES)
	if(thisModeConf->Noise.ucNoiseDetectionMode == 1)
		algorithm_noise_detection();
	else
#endif		
	if(thisModeConf->Noise.ucNoiseDetectionMode == 2)
		algorithm_noise_detection_v2(eSensingMode);
}

#endif /* USED_NOISE_HOPPING_FREQ */

