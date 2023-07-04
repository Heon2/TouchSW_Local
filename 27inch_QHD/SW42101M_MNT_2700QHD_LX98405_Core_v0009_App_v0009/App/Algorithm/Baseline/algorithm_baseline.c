/******************************************************************************************************
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
//#include "DSP_B.h" // NOTE : algorithm_baseline_calculate_local_mux_range �Լ��� ���⼭ �����ϰ� ����


#define BASELINE_TRACKING_RESOLUTION 		(100)
const static tModuleModeConf_t * ptModuleModeConf = NULL;
const static tAlgorithmModeConf_t * thisModeConf = NULL;
//static const tAlgorithmCommonConf_t * thisCommonConf = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;
uint16_t * g_pFingerBaseImage;

uint8_t SRIC_reset_flag = NO;

#if USED_NOISE_HOPPING_FREQ
static tAppInfo_t * ptAppInfo = NULL;
uint16_t * g_pFingerHop1BaseImage;
#endif /* USED_NOISE_HOPPING_FREQ */

extern __IO bool_t wdt_init;
void algorithm_baseline_init(void)
{
	algorithm_baseline_init_param();
	thisInfo = algorithm_GetInfo();
#if USED_NOISE_HOPPING_FREQ
	ptAppInfo = app_GetInfo();
#endif /* USED_NOISE_HOPPING_FREQ */
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
	g_pFingerBaseImage = HAL_GET_BASELINE_IMAGE_PTR();
#if USED_NOISE_HOPPING_FREQ
	g_pFingerHop1BaseImage = HAL_GET_HOPP1_BASELINE_IMAGE_PTR();
#endif /* USED_NOISE_HOPPING_FREQ */
}
#ifdef SHORT_COMPENSATION
uint8_t short_cnt;
tCell_t short_pos[SHORT_NUM] = {0, };
#endif
void algorithm_baseline_tracking_initial(void)
{
	uint32_t ulFrameNum, ulIdx;
	uint32_t ulFullIdxNum;
#if USED_NORMAL_NI_SENSING
	uint32_t ulNiIdxNum;
#endif /* USED_NORMAL_NI_SENSING */
    uint16_t temp_data, raw_val = 500;
#ifdef SHORT_COMPENSATION
    int diff;
	uint32_t raw_avg = 0;
    uint16_t raw_diff_thd = 500;
	short_cnt = 0;
	memset(short_pos, 0, sizeof(short_pos));
#endif
	uint16_t * pRawImage;
	uint16_t * pInitRawImage;
	uint16_t * pBaseImage;
	uint16_t * pInitBaseImage;
#if USED_NORMAL_NI_SENSING
	uint16_t * pNiRawImage;
	uint16_t * pNiInitRawImage;
	uint16_t * pNiBaseImage;
	uint16_t * pNiInitBaseImage;
#endif /* USED_NORMAL_NI_SENSING */
	
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
		pInitBaseImage = pBaseImage = g_pFingerHop1BaseImage ;
	}
//	pInitBaseImage = pBaseImage = HAL_GET_FREQ_BASELINE_PTR(ptAppInfo->eSelectFreq);
#else /* USED_NOISE_HOPPING_FREQ */
	pInitBaseImage = pBaseImage = g_pFingerBaseImage;//pBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
#endif /* USED_NOISE_HOPPING_FREQ */
	memset((void*)pBaseImage, 0x00, sizeof(uint16_t)*(ROW_MAX * COL_MAX));
	ulFullIdxNum = ROW_MAX * COL_MAX;
#if USED_NORMAL_NI_SENSING
	pNiInitRawImage = pNiRawImage = HAL_NI_GET_RAW_IMAGE_PTR();
	pNiInitBaseImage = pNiBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);
    memset((void*)pNiBaseImage, 0x00, sizeof(uint16_t)*(NI_ROW_MAX * COL_MAX));
    ulNiIdxNum = NI_ROW_MAX * thisInfo->ucCol;
#endif /* USED_NORMAL_NI_SENSING */

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

#if USED_NORMAL_NI_SENSING
		pNiRawImage = pNiInitRawImage;
		pNiBaseImage = pNiInitBaseImage;
		for(ulIdx = ulNiIdxNum; ulIdx--; )
		{
			raw_val = *(pNiRawImage++);
			temp_data = *(pNiBaseImage) + raw_val;
			*(pNiBaseImage++) = temp_data;
		}
#endif /* USED_NORMAL_NI_SENSING */

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

#if USED_NORMAL_NI_SENSING
	pNiBaseImage = pNiInitBaseImage;
	for(ulIdx = ulNiIdxNum; ulIdx--; )
	{
		temp_data = (*pNiBaseImage);
		temp_data /= thisModeConf->BaseLine.ucInitialFrameNum;
		(*pNiBaseImage++) = temp_data;
	}
#endif /* USED_NORMAL_NI_SENSING */

#ifdef MODE_WDT				
	KICK_DOG();
#endif
}

extern int16_t sLFOffsetRow[ROW_MAX];
extern int16_t sLFOffsetCol[COL_MAX];
void algorithm_baseline_tracking_continuous(uint8_t mode)
{
	uint32_t ulIdx;
	uint32_t ulFullIdxNum;
	int prev_baseline, curr_baseline, curr_rawdata, alpha;
	static bool_t traking_en = 0;
#if USED_NORMAL_NI_SENSING
	uint32_t ulNiIdxNum;
	uint16_t * pNiRawImage;
	uint16_t * pNiBaseImage;
#endif /* USED_NORMAL_NI_SENSING */
	uint16_t * pRawImage = HAL_GET_RAW_IMAGE_PTR();
#if USED_NOISE_HOPPING_FREQ
	uint16_t * pBaseImage;
	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	{
		pBaseImage = g_pFingerBaseImage;
	}
	else
	{
		pBaseImage = g_pFingerHop1BaseImage;
	}
//	uint16_t * pBaseImage = HAL_GET_FREQ_BASELINE_PTR(ptAppInfo->eSelectFreq);
#else /* USED_NOISE_HOPPING_FREQ */
	uint16_t * pBaseImage = g_pFingerBaseImage;
#endif /* USED_NOISE_HOPPING_FREQ */
    if(thisInfo->bIsPalm == 0 && thisInfo->bBlockTracking == NO)
	{
		if(mode == FULL_MODE && thisInfo->bLocal_sensing == NO)
		{
			alpha = thisModeConf->BaseLine.usIIRCoef;

			//pRawImage = HAL_GET_RAW_IMAGE_PTR();
			//pBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
			ulFullIdxNum = ROW_MAX * COL_MAX;
			for(ulIdx = 0; ulIdx < ulFullIdxNum; ulIdx++)
			{
				curr_rawdata = (*(pRawImage++));
#if !FAST_LF_EN	
				curr_rawdata += (sLFOffsetRow[ulIdx / COL_MAX] + sLFOffsetCol[ulIdx % COL_MAX]);
#endif
				prev_baseline = *(pBaseImage);
				curr_baseline = (alpha * prev_baseline + (BASELINE_TRACKING_RESOLUTION-alpha) * curr_rawdata)/BASELINE_TRACKING_RESOLUTION;
				*(pBaseImage++) = (uint16_t)curr_baseline;
			}
				
#if USED_NORMAL_NI_SENSING
	    	pNiRawImage = HAL_NI_GET_RAW_IMAGE_PTR();
	    	pNiBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);
	    	ulNiIdxNum = NI_ROW_MAX * thisInfo->ucScreenCol;
	    	for(ulIdx = ulNiIdxNum; ulIdx--; )
	    	{
	    		prev_baseline = *(pNiBaseImage);
	    		curr_rawdata = *(pNiRawImage++);
	    		curr_baseline = (alpha * prev_baseline + (BASELINE_TRACKING_RESOLUTION-alpha) * curr_rawdata)/BASELINE_TRACKING_RESOLUTION;
	    		*(pNiBaseImage++) = (uint16_t)curr_baseline;
	    	}
#endif /* USED_NORMAL_NI_SENSING */
		}
    }
}



void algorithm_baseline_tracking_continuous_local_finger(void)
{
	int r, c;
	int prev_baseline, curr_baseline, curr_rawdata, alpha;

    if( thisInfo->bBlockTracking == NO)
    {
		alpha = (100 - thisModeConf->BaseLine.usIIRCoef)*120/120;//ptAppInfo->iFrameRate;
		alpha = (100 - alpha);

    	for( r=0; r<ROW_MAX; r++ )
		{
			for( c=0; c<COL_MAX; c++ )
			{
				prev_baseline = HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r,c);
				curr_rawdata = HAL_READ_LOCAL_FINGER_RAW_IMAGE(r,c)+sLFOffsetRow[r];
				
				curr_baseline = (alpha * prev_baseline + (BASELINE_TRACKING_RESOLUTION-alpha) * curr_rawdata)/BASELINE_TRACKING_RESOLUTION;

				HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, (uint16_t)curr_baseline);
			}
		}

//    	protocol_LogMatrix(LT_REFERENCE, thisInfo->ucScreenCol, HAL_GET_BASELINE_IMAGE_PTR(), COL_MAX, thisInfo->ucScreenRow, 80/*MAX Intensity*/);
    }
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

		if(ldataCnt > 5)
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

//void algorithm_baseline_calculate_mux_range(int r, int c)
//{
//	int sub_r = r;
//	
//	if(currentRowStart == sensingRowStart)
//	{
//		sub_r = (((sub_r+1)>>1)<<1)-MAX_MUX_HALF;
//		
//		if(sub_r < 0)
//			sensingRowStart = 0;
//		else if(sub_r >= MUX_MAX_ROW)
//			sensingRowStart = MUX_MAX_ROW;
//		else
//			sensingRowStart = sub_r;
//	}

//	if(c<MAX_MUX_HALF)
//	{
//		thisInfo->tPenInfo.ucCurrentColumnStart = 0;
//		thisInfo->tPenInfo.ucCurrentColumnEnd = MAX_MUX_SIZE;
//	}
//	else if(c+MAX_MUX_HALF > COL_MAX)
//	{
//		thisInfo->tPenInfo.ucCurrentColumnStart = COL_MAX - MAX_MUX_SIZE;
//		thisInfo->tPenInfo.ucCurrentColumnEnd = COL_MAX;
//	}
//	else
//	{
//		thisInfo->tPenInfo.ucCurrentColumnStart = c-MAX_MUX_HALF;
//		thisInfo->tPenInfo.ucCurrentColumnEnd = c+MAX_MUX_HALF;
//	}
//}

int full_hover_cnt = 0;
tCell_t max_cell_pos;
int max_cell_data;

#if (LABEL_FAST_EN == 2)
extern uint8_t g_ucEqTbl[LOOSE_POSBUF_];
extern uint8_t g_label_num;
#endif
bool_t algorithm_baseline_calculate_delta(int mode)
{
	int r, c,idx;
	int delta;	
//	int local_rs;
//	int pen_touch_data = 0;
	uint16_t read_raw_data;
//	tCell_t pen_pos;
//	int pen_touch_data2 = 0;
	tOrigDeltaInfo_t * temp_delta;
	uint16_t * pBaseImage;
	tAppInfo_t * ptAppInfo = app_GetInfo();
	
//	uint16_t AbnormalDeltaCntBuf[8] = {0}, AbnormalRegionCnt = 0;
	
	//Adaptive SeedBase LYB_200819
	uint16_t AdaptiveSeedBase = 0;

#if USED_RF_NOISE_RECOVERY_CODE
	thisInfo->usAbnormalDeltaNodeCnt = 0;
#endif /* USED_RF_NOISE_RECOVERY_CODE */	

#if USED_NOISE_HOPPING_FREQ
	uint8_t DeltaDivider;
	if(IS_ACTIVE_MODE_FRQ_MAIN(HAL_GetSensingMode()))	DeltaDivider = 1<<ptModuleModeConf->ucOvrShift;
	else												DeltaDivider = ((1<<ptModuleModeConf->ucOvrShift) + (1<<(ptModuleModeConf->ucOvrShift-1)))>>1;
#endif /* USED_NOISE_HOPPING_FREQ */	

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
		pBaseImage = g_pFingerHop1BaseImage;
	}
//	pBaseImage = HAL_GET_FREQ_BASELINE_PTR(ptAppInfo->eSelectFreq);
#else /* USED_NOISE_HOPPING_FREQ */
	pBaseImage = g_pFingerBaseImage;//HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
#endif /* USED_NOISE_HOPPING_FREQ */
	
	temp_delta->iPosCnt = 0;
	temp_delta->iNegCnt = 0;

#if (LABEL_FAST_EN)	
	memset(thisInfo->tLabel.ucLabel_Check,0,sizeof(thisInfo->tLabel.ucLabel_Check));
	#if (LABEL_FAST_EN == 2)
	memset(LABELIMAGE,0,sizeof(LABELIMAGE));
	g_label_num = 0;
	memset((void *)g_ucEqTbl, 0x00, sizeof(uint8_t)*LOOSE_POSBUF_);
	uint8_t u_val, l_val, ul_val, ur_val, max_val1, max_val2, max_val3, min_val1, min_val2, min_val3, map_val, remap_index;
	#endif
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
//			memset(AbnormalDeltaCntBuf,0,sizeof(AbnormalDeltaCntBuf));
			for( c=0; c<COL_MAX; c++ )
			{
#if FAST_LF_EN
				read_raw_data = HAL_READ_RAW_IMAGE(r,c) - sLFOffsetRow[r];
#else
				read_raw_data = HAL_READ_RAW_IMAGE(r, c);
#endif
				
#if CPI_TEST_EN
				if(thisModeConf->Noise.ucCPITestOn){
					RawPartSum[c/5] += read_raw_data;
					RawPartSumCnt[c/5]++;
					if(read_raw_data <= 0)	AbnormalRawCnt++;
				}
#endif
				
				delta = (signed)read_raw_data - (signed)(*(pBaseImage++));
#if 0
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
#endif
#if NORMALIZE_DELTA_EN
				//Normalize Active 190612 limyb
				if(thisModeConf->BaseLine.cNormalizeDelta != 0 && delta > (AdaptiveSeedBase>>1))
				{
	//				int left_top = 1;
	//				int right_bottom = 128;
					int nDelta = delta;
					
	//				nDelta = nDelta * (2*ROW_MAX + r) * (2*COL_MAX + c) / (ROW_MAX * COL_MAX);
	//				delta = nDelta * ( ((ROW_MAX-thisModeConf->BaseLine.cNormalizeDelta)<<1) - r) / (ROW_MAX-thisModeConf->BaseLine.cNormalizeDelta);
					delta = nDelta * (ROW_MAX + ((ROW_MAX - r)>>2)) / ROW_MAX;
				}
#endif
				
#if USED_NOISE_HOPPING_FREQ
				delta /= DeltaDivider;
#else /* USED_NOISE_HOPPING_FREQ */
				delta >>= ptModuleModeConf->ucOvrShift;
#endif /* USED_NOISE_HOPPING_FREQ */
				HAL_WRITE_DELTA_IMAGE(r, c, delta);
				
#if USED_RF_NOISE_RECOVERY_CODE
				if(delta >= ABNORMAL_DELTA_PLUS_THD)
				{
					thisInfo->usAbnormalDeltaNodeCnt++;
				}
#endif /* USED_RF_NOISE_RECOVERY_CODE */				
				
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
						{
							temp_delta->iPosCnt++;
							temp_delta->iPosSum += delta - thisModeConf->BaseLine.sAccumPosSumThd;
//							AbnormalDeltaCntBuf[c/10]++;
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
#if LABEL_FAST_EN
						int idx_r = r/ROW_IN_ARRAY;
						int idx_c = c/COL_IN_ARRAY;
						if(thisInfo->tLabel.ucLabel_Check[idx_r][idx_c]==0)thisInfo->tLabel.ucLabel_Check[idx_r][idx_c] = 1;
#if (LABEL_FAST_EN == 2)
	#if (PAD_ == 0)
						if(r == 0)
						{
							u_val  = 0;
							ul_val = 0;
							ur_val = 0;
						}
						else
						{
							u_val  = HAL_READ_LABEL_IMAGE(r-1, c  );
							if(c == 0)
								ul_val = 0;
							else 
								ul_val = HAL_READ_LABEL_IMAGE(r-1, c-1);
							
							if(c == COL_MAX-1)
								ur_val = 0;
							else 
								ur_val = HAL_READ_LABEL_IMAGE(r-1, c+1);
						}
						
						if(c == 0)
							l_val  = 0;
						else
							l_val  = HAL_READ_LABEL_IMAGE(r  , c-1);
	#else
						u_val  = HAL_READ_LABEL_IMAGE(r-1, c  );
						ul_val = HAL_READ_LABEL_IMAGE(r-1, c-1);
						ur_val = HAL_READ_LABEL_IMAGE(r-1, c+1);
						l_val  = HAL_READ_LABEL_IMAGE(r  , c-1);
	#endif
						max_val1 = MAX(ul_val, l_val);
						max_val2 = MAX(u_val, ur_val);
						max_val3 = MAX(max_val1, max_val2);

						if (max_val3 != 0)
						{
							if (u_val == 0)  u_val  = 127;
							if (l_val == 0)  l_val  = 127;
							if (ul_val == 0) ul_val = 127;
							if (ur_val == 0) ur_val = 127;

							min_val1 = MIN(u_val, l_val);
							min_val2 = MIN(ul_val, ur_val);
							min_val3 = MIN(min_val1, min_val2);

							if (min_val3 != max_val3)
							{
								map_val = min_val3;
								//*(thisInfo->ucEqTbl+max_val3) = min_val3;

								if(u_val != 127)
								{
									remap_index = u_val;
									while(remap_index != g_ucEqTbl[remap_index])
									{
										remap_index = g_ucEqTbl[remap_index];
										if(min_val3 < remap_index)
											g_ucEqTbl[remap_index] = min_val3;
									}

									if( g_ucEqTbl[u_val] > min_val3 )
										g_ucEqTbl[u_val] = min_val3;
								}
								if(l_val != 127)
								{
									remap_index = l_val;
									while(remap_index != g_ucEqTbl[remap_index])
									{
										remap_index = g_ucEqTbl[remap_index];
										if(min_val3 < remap_index)
											g_ucEqTbl[remap_index] = min_val3;
									}

									if( g_ucEqTbl[l_val] > min_val3 )
										g_ucEqTbl[l_val] = min_val3;
								}
								if(ul_val != 127)
								{
									remap_index = ul_val;
									while(remap_index != g_ucEqTbl[remap_index])
									{
										remap_index = g_ucEqTbl[remap_index];
										if(min_val3 < remap_index)
											g_ucEqTbl[remap_index] = min_val3;
									}

									if( g_ucEqTbl[ul_val] > min_val3 )
										g_ucEqTbl[ul_val] = min_val3;
								}
								if(ur_val != 127)
								{
									remap_index = ur_val;
									while(remap_index != g_ucEqTbl[remap_index])
									{
										remap_index = g_ucEqTbl[remap_index];
										if(min_val3 < remap_index)
											g_ucEqTbl[remap_index] = min_val3;
									}

									if( g_ucEqTbl[ur_val] > min_val3 )
										g_ucEqTbl[ur_val] = min_val3;
								}
							}
							else
							{
								map_val = max_val3;
							}
						}
						else
						{
							if( g_label_num < LOOSE_POSBUF_ )
							{
								g_label_num++;
							}

							map_val = g_label_num;
							g_ucEqTbl[g_label_num] = g_label_num;
						}
						
						HAL_WRITE_LABEL_IMAGE(r, c, map_val);
	#endif
#endif
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
						{						
							temp_delta->iNegCnt++;
							temp_delta->iNegSum += delta - thisModeConf->BaseLine.sAccumNegSumThd;
//							AbnormalDeltaCntBuf[c/10]++;
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
			//Phone Noise
//			for(c = 1 ; c < 7; c++)
//				if(AbnormalDeltaCntBuf[c-1] == 0 && AbnormalDeltaCntBuf[c] == 10 && AbnormalDeltaCntBuf[c+1] == 0)
//					AbnormalRegionCnt++;
			
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

#if USED_RF_NOISE_RECOVERY_CODE
		if(thisInfo->usAbnormalDeltaNodeCnt >= ABNORMAL_DELTA_PLUS_CNT_THD || temp_delta->iMinStrength <= ABNORMAL_DELTA_MINUS_THD)
		{
			thisInfo->usAbnormalDeltaFrameCnt1++;
			thisInfo->usDebounceFrmaeCnt = DEBOUNCE_FRAME_NUM;
		}
		else
		{
			thisInfo->usAbnormalDeltaFrameCnt1 = 0;
			if(thisInfo->usDebounceFrmaeCnt > 0)
			{
				thisInfo->usDebounceFrmaeCnt--;
			}
		}
#endif /* USED_RF_NOISE_RECOVERY_CODE */			
		
		#if 0
		//Phone noise
		if(thisInfo->PhoneNoiseFrmCnt < PHONE_NOISE_RESET_CNT_MAX)
		{
			if(temp_delta->iNegCnt >= 2 && AbnormalRegionCnt >= 2)
				thisInfo->PhoneNoiseFrmCnt++;
			else if(temp_delta->iNegCnt == 0 && temp_delta->iPosCnt == 0)
				thisInfo->PhoneNoiseFrmCnt = 0;
			
			if(temp_delta->iNegCnt >= 2)
				thisInfo->PhoneNoiseDebEnable = YES;
			else
				thisInfo->PhoneNoiseDebEnable = NO;
			
		}
		else if(thisInfo->PhoneNoiseFrmCnt == PHONE_NOISE_RESET_CNT_MAX){
			thisInfo->PhoneNoiseFrmCnt = 1;
			SRIC_reset_flag = YES;
		}
		#endif
		thisInfo->bTouchExpect = (temp_delta->iGroupedCellCnt > 0);
	}

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
	
	if(temp_delta->iMaxStrength > thisModeConf->BaseLine.sBlockPosThd)
	{
		thisInfo->bBlockTracking = YES;
	}
	
	if(temp_delta->iMinStrength < thisModeConf->BaseLine.sBlockNegThd)
	{
		thisInfo->bBlockTracking = YES;
	}
	
	return thisInfo->bBlockTracking;
}

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
#if (USED_IDLE_MODE_CONTROL && !USED_NORMAL_NI_SENSING)
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
#endif /* (USED_IDLE_MODE_CONTROL && !USED_NORMAL_NI_SENSING) */

#if USED_IDLE_MODE_CONTROL
void algorithm_baseline_tracking_continuous_idle(void)
{
	uint32_t ulIdx;
	uint32_t ulIdleIdxNum;
	uint16_t * pIdleRawImage;
	uint16_t * pIdleBaseImage;
	int prev_baseline, curr_baseline, curr_rawdata, alpha;

    if(thisInfo->bBlockTracking == NO && thisInfo->bLocal_sensing == NO)
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
				ptTempIdleDeltaInfo->ulMaxNodeRowIndex = r;
			}

			if(ptTempIdleDeltaInfo->sMinStrength > delta)
			{
				ptTempIdleDeltaInfo->sMinStrength = delta;
				ptTempIdleDeltaInfo->ulMinNodeColIndex = c;
				ptTempIdleDeltaInfo->ulMinNodeRowIndex = r;
			}
		}
	}

	if(ptTempIdleDeltaInfo->sMaxStrength > thisModeConf->BaseLine.sIdle_BlockPosThd ||
		ptTempIdleDeltaInfo->sMinStrength < thisModeConf->BaseLine.sIdle_BlockNegThd)
	{
		uint32_t ulCheckNodeColIdx;
		uint32_t ulCheckNodeRowIdx;
		uint32_t ulTotalPosSumTHD;
		uint32_t ulTotalNegSumTHD;
		uint32_t ulCheckNodeSeed;
		if(ABS(ptTempIdleDeltaInfo->sMaxStrength) > ABS(ptTempIdleDeltaInfo->sMinStrength))
		{
			ulCheckNodeColIdx = ptTempIdleDeltaInfo->ulMaxNodeColIndex;
			ulCheckNodeRowIdx = ptTempIdleDeltaInfo->ulMaxNodeRowIndex;
			ulCheckNodeSeed = ABS(ptTempIdleDeltaInfo->sMaxStrength);
		}
		else
		{
			ulCheckNodeColIdx = ptTempIdleDeltaInfo->ulMinNodeColIndex;
			ulCheckNodeRowIdx = ptTempIdleDeltaInfo->ulMinNodeRowIndex;
			ulCheckNodeSeed = ABS(ptTempIdleDeltaInfo->sMinStrength);
		}
		ptTempIdleDeltaInfo->sColumStrengthTotalSum = 0;

#if USED_AFE_BIAS_CURRENT_DOWN
		if(ulCheckNodeSeed > (thisModeConf->BaseLine.sIdle_SeedThd>>1))
#else /* USED_AFE_BIAS_CURRENT_DOWN */
		if(ulCheckNodeSeed > thisModeConf->BaseLine.sIdle_SeedThd)
#endif /* USED_AFE_BIAS_CURRENT_DOWN */
		{
			if(ulCheckNodeColIdx < COL_MAX-1)
			{
				ptTempIdleDeltaInfo->sColumStrengthTotalSum += HAL_NI_READ_DELTA_IMAGE(ulCheckNodeRowIdx, ulCheckNodeColIdx+1);
			}

			if(ulCheckNodeColIdx > 0)
			{
				ptTempIdleDeltaInfo->sColumStrengthTotalSum += HAL_NI_READ_DELTA_IMAGE(ulCheckNodeRowIdx, ulCheckNodeColIdx-1);
			}

			for(r=0; r<NI_ROW_MAX; r++)
			{
				ptTempIdleDeltaInfo->sColumStrengthTotalSum += HAL_NI_READ_DELTA_IMAGE(r, ulCheckNodeColIdx);
			}

			// Corner Intensity Check!!
			if((ulCheckNodeColIdx == 0 || ulCheckNodeColIdx == COL_MAX-1) && (ulCheckNodeRowIdx == 0 || ulCheckNodeRowIdx == NI_ROW_MAX - 1))
			{
				ulTotalPosSumTHD = thisModeConf->BaseLine.sIdle_PosTotalSumThd >> 2;
				ulTotalNegSumTHD = thisModeConf->BaseLine.sIdle_NegTotalSumThd >> 2;
			}
			else
			{
				ulTotalPosSumTHD = thisModeConf->BaseLine.sIdle_PosTotalSumThd;
				ulTotalNegSumTHD = thisModeConf->BaseLine.sIdle_NegTotalSumThd;
			}

			if(ptTempIdleDeltaInfo->sColumStrengthTotalSum > ulTotalPosSumTHD ||
				ptTempIdleDeltaInfo->sColumStrengthTotalSum < ulTotalNegSumTHD)
			{
				ptTempIdleDeltaInfo->sPrevMaxStrength = ptTempIdleDeltaInfo->sMaxStrength;
				ptTempIdleDeltaInfo->sPrevMinStrength = ptTempIdleDeltaInfo->sMinStrength;

	#if !USED_ONLY_IDLE_MODE
				thisInfo->bTouchExpect = YES;
	#endif /* !USED_ONLY_IDLE_MODE */
			}
		}

		thisInfo->bBlockTracking = YES;
	}
}
#endif /* USED_IDLE_MODE_CONTROL */

#if USED_NORMAL_NI_SENSING
void algorithm_baseline_calculate_delta_ni(void)
{
	int r, c;
	int delta;
	uint16_t read_raw_data;
	uint16_t * pNiBaseImage;

	pNiBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);
	for(r = 0 ; r < NI_ROW_MAX ; ++r)
	{
		for(c = 0 ; c < COL_MAX ; ++c)
		{
			read_raw_data = HAL_NI_READ_RAW_IMAGE(r, c);
			delta = (signed)read_raw_data - (signed)(*(pNiBaseImage++));
			delta >>= ptModuleModeConf->ucOvrShift;
			HAL_NI_WRITE_DELTA_IMAGE(r, c, delta);
		}
	}
}
#endif /* USED_NORMAL_NI_SENSING */

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
