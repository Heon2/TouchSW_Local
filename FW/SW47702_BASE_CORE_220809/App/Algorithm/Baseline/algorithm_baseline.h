/*
 * algorithm_baseline.h
 *
 *  Created on: 2015. 5. 6.
 *      Author: parkyj2
 */

#ifndef __ALGORITHM_BASELINE_H__
#define __ALGORITHM_BASELINE_H__

typedef struct
{
	int8_t  cNormalizeDelta;
	uint8_t ucDiscardFrameNum;
	uint8_t ucInitialFrameNum;
    uint16_t usIIRCoef;
    int16_t  sBlockPosThd;
    int16_t  sBlockNegThd;
    int16_t  sAccumPosSumThd;
    int16_t  sAccumNegSumThd;
    int16_t  sIdle_BlockPosThd;
    int16_t  sIdle_BlockNegThd;
    int16_t  sIdle_SeedThd;
    int16_t  sIdle_PosTotalSumThd;
    int16_t  sIdle_NegTotalSumThd;
    int16_t  sLocalIdle_BlockPosThd;
    int16_t  sLocalIdle_BlockNegThd;
    int16_t  sLocalIdle_PosTotalSumThd;
    int16_t  sLocalIdle_NegTotalSumThd;
#if USED_LOCAL_PEN_HOVER_IDLE_TO_ACTIVE
    uint8_t  ucLocalIdlePenHoverCheckFrameThd;
#endif /* USED_LOCAL_PEN_HOVER_IDLE_TO_ACTIVE */
    int16_t  sS3_BlockPosThd;
    int16_t  sS3_BlockNegThd;
    int16_t  sS3_PosTotalSumThd;
    int16_t  sS3_NegTotalSumThd;
    int32_t  iRecalCond1_PosSum_Thd;
    int32_t  iRecalCond1_AccSum_Thd;
    int32_t  iRecalCond2_AccSum_Thd;
    uint8_t  ucRecalCond1_WaitCnt;
    uint8_t  ucRecalCond2_WaitCnt;
	bool_t   bFullModeReBaseCheckOff;
	bool_t   bLocalModeReBaseCheckOff;	
	int16_t  sFullLcoalChangeMinTh;
	int8_t   cFullLcoalChangeMinThOffset;
	int16_t  usMS_ContactTh_LocalMode;
	int16_t  usMS_ContactTh_HoverMode;
	bool_t	 b2MUX_SUM_LocalSearchMode;
	bool_t	 b2MUX_SUM_LocalMode;
	bool_t   bPen_2BASE;
	int8_t   cFingerAreaPenDeltaDelete;	
	int8_t   cFingerAreaPenDeltaNoAcc	;	
	bool_t   bFingerBaseTracking;
	uint8_t	 ucPP_MUX_Select;
	bool_t   bDspA_Finger_CalculateDelta;
	bool_t   bDspA_LocalMode_PenPhase;
	bool_t   bDspA_LocalMode_CalculateDelta;
	bool_t   bDspA_SearchMode_PenPhase;
	bool_t   bDspA_SearchMode_CalculateDelta;
	bool_t	 bFullFingerBaseTracking;
	uint8_t  ucLocalNormalizeMaxOffset;
#if (NORMALIZE_DELTA2_EN == YES)
	uint8_t	 ucFingerNormalizeMaxOffset;
#endif
#if USED_DSPA_FUNC_FOR_FINGER_NORMALIZE
	uint8_t ucFingerNormalizeDspA_En;
#endif	
} __PACKED tAlgorithmBaseLineConf_t;

typedef struct
{
	uint8_t  cLineFilter;
	int16_t  sLineFilterUpLimit;
	int16_t  sLineFilterLowLimit;
	uint8_t	 ucLineFilterColOffset;	
	uint8_t  ucLineFilterRepeatTH;
	int8_t   cLineFilterMinTH;
	uint8_t  ucMinDeltaTh;
	int8_t   cLineFilter_Pen;
	uint8_t  ucLocalSearchModeLineFilter;
	bool_t   bRingRawLineFilter;
	int16_t	 sLineFilterUpLimit_Pen;
	int16_t	 sLineFilterLowLimit_Pen;
	int16_t  sLineFilterUpLimit_Idle;
	int16_t  sLineFilterLowLimit_Idle;
	uint8_t  ucRingDeltaIIR_Coef;
    int16_t  sFingerAreaLineFilterLimit;
    uint8_t  ucFingerAreaLineFilterOffset;
#if (HighHoverDeltaIIR_En == YES)
	uint8_t ucHighHoverDeltaIIR_Coef;
#endif
#if FINGER_LF_VERTICAL_EN
	uint8_t  ucLineFilterV;
#endif
#if (ContactDeltaIIR_En == YES)
	uint8_t ucContactDeltaIIR_Coef;
#endif
} __PACKED tAlgorithmSensingFilterConf_t;

typedef struct
{
	tRect_t     tValidRect;            			//  0, 0, 0
    uint32_t    iGroupedCellCnt;       			//  4, 2, 1
    int32_t     iMaxStrength;          			//  8, 4, 2
    uint8_t     ucCoordiRowStart;      			// 12, 6, 3
    uint8_t     ucCoordiColumnStart;  	 		// 13
    uint16_t    usPenCalRangeThr;        		// 14, 7
    uint8_t     ucRowCellMax;           		// 16, 8, 4
    uint8_t     ucColumnCellMax;      	 		// 17
    uint8_t     ucCurrentColumnStart;   		// 18, 9
    uint8_t     ucCurrentColumnEnd;    		 	// 19
	
    int iPosCnt;								// 20,10, 5
    int iPosSum;								// 24,12, 6
    int iNegCnt;								// 28,14, 7
    int iNegSum;								// 32,16, 8

    int iMinStrength;							// 36,18, 9
    tCell_t tMaxCellPos;						// 40,20,10
	tCell_t tMinCellPos;						// 42,21,
	
//	int16_t sPrevMaxDelta2;						// 44,22,11
} __PACKED tOrigDeltaInfo_t;

#if USED_IDLE_MODE_CONTROL
typedef struct
{
	uint32_t ulMaxNodeColIndex;
	uint32_t ulMaxNodeRowIndex;
	uint32_t ulMinNodeColIndex;
	uint32_t ulMinNodeRowIndex;
	int16_t sMaxStrength;
	int16_t sMinStrength;

	int16_t sPrevMaxStrength;
	int16_t sPrevMinStrength;

	int16_t sColumStrengthTotalSum;

	bool_t bIsSendResumeSignal;

} __PACKED tIdleDeltaInfo_t;
#endif /* #if USED_IDLE_MODE_CONTROL */

#if USED_LOCAL_IDLE_MODE_CONTROL
typedef struct
{
	uint32_t ulMaxNodeColIndex;
	uint32_t ulMaxNodeRowIndex;
	uint32_t ulMinNodeColIndex;
	uint32_t ulMinNodeRowIndex;
	int16_t sMaxStrength;
	int16_t sMinStrength;

	int16_t sPrevMaxStrength;
	int16_t sPrevMinStrength;

	int16_t sColumStrengthTotalSum;

#if USED_LOCAL_IDLE_PEN_OTHER_CONTROL
	uint32_t ulPenMaxNodeColIndex;
	uint32_t ulPenMaxNodeRowIndex;
	uint32_t ulPenMinNodeColIndex;
	uint32_t ulPenMinNodeRowIndex;
	int16_t sPenMaxStrength;
	int16_t sPenMinStrength;

	int16_t sPenPrevMaxStrength;
	int16_t sPenPrevMinStrength;

	int16_t sPenColumStrengthTotalSum;
	#if USED_LOCAL_PEN_HOVER_IDLE_TO_ACTIVE
		uint32_t ulPenHoverIdleCheckFrameCnt;
	#endif /* USED_LOCAL_PEN_HOVER_IDLE_TO_ACTIVE */
#endif /* USED_LOCAL_IDLE_PEN_OTHER_CONTROL */
//	bool_t bIsSendResumeSignal;

} __PACKED tLocalIdleDeltaInfo_t;
#endif /* #if USED_LOCAL_IDLE_MODE_CONTROL */

#if USED_MNT_S3_MODE_FUNCTION
typedef struct
{
	uint32_t ulMaxNodeColIndex;
	uint32_t ulMinNodeColIndex;
	int16_t sMaxStrength;
	int16_t sMinStrength;

	int16_t sPrevMaxStrength;
	int16_t sPrevMinStrength;

	int16_t sColumStrengthTotalSum;

	bool_t bIsSendResumeSignal;

} __PACKED tS3DeltaInfo_t;
#endif /* USED_MNT_S3_MODE_FUNCTION */

typedef struct
{
	int16_t start_r;								//  0,  0,  0
    int16_t end_r;									//  2,  1,
    int16_t start_c;								//  4,  2,  1
    int16_t end_c;									//  6,  3,
	uint16_t local_rs;								//  8,  4,	2
	uint16_t local_cs;								// 10,  5,
	uint8_t tip_rs;									// 12,  6,	3
	uint8_t ring_rs;								// 13,
    uint8_t raw_idx;								// 14,  7,
    uint8_t base_idx;								// 15,
    uint8_t MuxSum_raw_idx;							// 16,  8,	4
    uint8_t MuxSum_base_idx;						// 17,
	bool_t MuxSum;									// 18,  9,
	uint8_t ucLocalOvrShift;						// 19,
	tCell_t pen_pos;								// 20, 10,  5
    int16_t pen_touch_data;							// 22, 11,
    uint16_t delta_th;								// 24, 12,  6
	int16_t min_delta_th;							// 26, 13
	bool_t bContact;								// 28, 14,  7
    uint8_t ucReleaseFrame;							// 29,
    bool_t bAdaptorNoise_SearchMode;				// 30, 15
    uint8_t ucAdaptorNoise_CalDeltaRepeatSimbol;	// 31,
    int16_t tmp_AdaptorNoiseTH;						// 32, 16,  8
    int16_t tmp_AdaptorNoiseContiNum;				// 34, 17,
    uint8_t tmpSearchNoiseRejectFrm;				// 36, 18,  9
	uint8_t ucSearchNoiseRejectTH;					// 37,
	uint8_t ucSearchNoiseRejectFrm;					// 38, 19
	uint8_t ucPen_th1;								// 39,
	uint8_t ucPen_th2;								// 40, 20, 10
	bool_t bMS_phase;								// 41,
	bool_t bMS_Contact2bit[2];						// 42, 21
	tRect_t LocalFingerArea;						// 44, 22, 11
	uint8_t ucPP_MUX_Select;						// 48, 24, 12
	int8_t cFingerAreaPenDeltaDelete;				// 49,
	int8_t cFingerAreaPenDeltaNoAcc;				// 50, 25
	int8_t sAccumPosSumThd;							// 51,
	int8_t sAccumNegSumThd;							// 52, 26, 13
	bool_t bBlockTrackingByLocalDelta;				// 53,
	uint16_t col_max;								// 54, 27
	uint16_t row_max;								// 56, 28, 14
	uint16_t zero_finger_rawdata_mask_num;			// 58, 29	
	uint32_t g_RetVal;								// 60, 30, 15
	uint32_t gAlgoRawDataType;						// 64, 32, 16
} __PACKED tAlgorithmPenCalcDeltaConf_t;

extern void algorithm_baseline_init(void);
extern void algorithm_baseline_init_param(void);
extern void algorithm_baseline_init_FingerPoint(void);
extern void algorithm_baseline_tracking_initial(void);
#if USED_PEN_MODE_OPERATION
extern bool_t algorithm_baseline_tracking_initial_local(uint8_t OP_TYPE);
//extern bool_t algorithm_baseline_2_tracking_initial_local(void);
#endif /* USED_PEN_MODE_OPERATION */
extern void algorithm_baseline_tracking_continuous(uint8_t mode);
//extern void algorithm_baseline_tracking_continuous_local_finger(void);
extern bool_t algorithm_baseline_calculate_delta(int mode);
//extern bool_t algorithm_baseline_calculate_delta_localFinger(int mode);
//extern bool_t algorithm_baseline_calculate_delta_DSP(int mode);
//extern void algorithm_baseline_extract_max_delta(void); //NOTE : warning제거!!
extern bool_t algorithm_local_baseline_calculate_delta(int mode);
extern bool_t algorithm_local_baseline_calculate_delta_pre(int mode);
extern bool_t algorithm_local_baseline_calculate_delta_post(int mode);
extern bool_t algorithm_local_baseline_calculate_delta_local_search(int mode);
extern bool_t abnormal_rawdata_temp(bool_t SET);
extern bool_t abnormal_rawdata_detection_for_hopping(bool_t SET); //NOTE : warning제거!!
extern void algorithm_baseline_calculate_mux_range(int r, int c);

#if USED_IDLE_MODE_CONTROL
extern void algorithm_baseline_tracking_initial_idle(bool_t bIsSkip);
extern void algorithm_baseline_tracking_continuous_idle(void);
extern void algorithm_baseline_calculate_delta_idle(void);
#endif /* USED_IDLE_MODE_CONTROL */

#if USED_LOCAL_IDLE_MODE_CONTROL
extern void algorithm_baseline_tracking_initial_local_idle(bool_t bIsSkip);
extern void algorithm_baseline_tracking_continuous_local_idle(void);
extern void algorithm_baseline_calculate_delta_local_idle(void);
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */

#if USED_MNT_S3_MODE_FUNCTION
extern void algorithm_baseline_tracking_initial_S3(bool_t bIsSkip);
extern void algorithm_baseline_tracking_continuous_S3(void);
extern void algorithm_baseline_calculate_delta_S3(void);
#endif /* USED_MNT_S3_MODE_FUNCTION */

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
extern void algorithm_baseline_tracking_continuous_local_ring(void);
#endif
#endif /* __ALGORITHM_BASELINE_H__ */
