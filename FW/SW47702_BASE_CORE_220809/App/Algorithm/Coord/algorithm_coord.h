/*
 * algorithm_coord.h
 *
 *  Created on: 2015. 5. 11.
 *      Author: parkyj2
 */

#ifndef ALGORITHM_COORD_H_
#define ALGORITHM_COORD_H_

#define COORD_HISTORY_NUM		5

#define PAST_COORD_HISTORY_NUM	19

typedef struct
{
	uint16_t usDistThdMovingToStationary;
	uint16_t usDistThdStationaryToMoving;
	uint32_t lMoveSmoothingLevel;
#if (VECTOR_PREDICTION_EN == YES)
	uint8_t ucVectorPredictionCoef;
#endif
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES ||INTERPOLATION_VER3_En == YES)
	uint8_t	ucLocalFingerInterpolation_On;
	uint8_t	ucFullFingerInterpolation_On;
	int16_t sInterpolationWeight;
#endif
	uint8_t ucFirstMoveEventTHD;
	uint8_t ucMoveEventTHD;
	int16_t sFingerGlobalCoordiXResolutionOffset;
	int16_t sFingerGlobalCoordiYResolutionOffset;
	int16_t sFingerGlobalCoordiOffsetX;
	int16_t sFingerGlobalCoordiOffsetY;
#if (FingerGlobalCoordiY_2Region_Set == YES)
	int16_t sFingerGlobalCoordiY_2Region_boundary;
	int16_t sFingerGlobalCoordiYResolutionOffset1;
	int16_t sFingerGlobalCoordiOffsetY1;
#endif
#if (SMOOTH_PASTORG_INTER_EN == YES)
	uint8_t ucSmoothPastOrgInter;
#endif
	int16_t  cDisSmoothOffset;
	bool_t bFingerMeanSmoothing;
#if (USED_DRUM_ALGO == YES)
	uint16_t usDrumTestDist;
#endif
	uint8_t ucWinCertAssistance;
	uint8_t ucTouchCountMax;
	uint8_t ucMaxExtendFrameNum;
	uint16_t usFirstDrawingThd;
	uint8_t ucFirstDrawingCellCnt;
	bool_t bSwapXY;
	bool_t bFlipX;
} __PACKED tAlgorithmCoordConf_t;

typedef struct
{
	uint8_t  ucDynamicTrackingDistanceMode;
	uint8_t  ucFastDrawingMode;
	uint16_t usMoveDistanceThd;
	uint16_t usFirstMoveDistanceThd;
	uint32_t lLargeTouchOnThd;
	uint8_t	ucLargeTouchOnDebCnt;
	uint32_t lMediumTouchOnThd;
	uint8_t	ucMediumTouchOnDebCnt;
	uint32_t lSmallTouchOnThd;
	uint8_t	ucSmallTouchOnDebCnt;
	bool_t  bEdgeDebCntUp;
	int16_t sFirstTouchOnMaxCellVal;
	uint32_t lTouchOffThd;
	uint8_t  ucMultifingerFirstTouchThDownOffset;
	uint32_t usCenterMatchDistanceThd;
	int16_t sFirstTouchEnable1Touch;
	int16_t sFirstTouchEnable2Touch;
	int16_t sFirstTouchEnable3Touch;
	int16_t sFirstTouchEnable4Touch;
	int16_t sFirstTouchEnable5Touch;
	uint8_t ucDebCntInner;
	uint8_t ucDebCntEdge;
#if (MultiTouchDebCnt_En == YES)
	uint8_t ucMultiTouchDebCnt;
#endif
#if (ForcingContinue_ReleasePoint == YES)
	uint8_t ucForcingReleasePointCnt;
#endif
} __PACKED tAlgorithmCoordTrackingConf_t;

typedef struct
{
	bool_t  bExpectClipping_Finger_On;
	int8_t  cEdgeSmoothing_Finger_On;
#if (REMOVE_EDGE_EN == YES)
	bool_t	bRemoveEdge;
	uint16_t usRemoveEdgeXdistThd;
	uint16_t usRemoveEdgeYdistThd;
	bool_t  bUsetRealPastSentPos1;
	uint8_t  ucRemoveEdgeVer;
#endif
	uint16_t usPostProcessEdgeTH;
	uint8_t ucPostProcessDisTH;
	uint8_t ucPostProcessExpendDiv;
	int8_t cPostProcessEndMargin;
	bool_t bPostProcessInterpolationMode;
	uint16_t usOutInDrawEdgeTh;
	uint8_t ucOutInDrawDisTh;
	bool_t bUseNewCippingCond;
} __PACKED tAlgorithmCoordEdgeConf_t;

typedef struct
{
#if (MULTI_EDGE_COEF_EN == YES)
	bool_t bUseMultiEdgeCoef;
	uint16_t usSmallTouchMaxDeltaThd;
	uint8_t ucSmallTouchCellCntThd;
	uint8_t ucSmallTouchHeightThd;
	uint8_t ucSmallTouchWidthThd;
#endif
	uint8_t ucLeftEdgeExpand;
    uint8_t ucRightEdgeExpand;
    uint8_t ucTopEdgeExpand;
    uint8_t ucBottomEdgeExpand;	
#if (MULTI_EDGE_COEF_EN == YES)
	uint8_t ucLeftEdgeExpand_small;
    uint8_t ucRightEdgeExpand_small;
    uint8_t ucTopEdgeExpand_small;
    uint8_t ucBottomEdgeExpand_small;
	uint8_t ucLeftEdgeExpand_medium;
    uint8_t ucRightEdgeExpand_medium;
    uint8_t ucTopEdgeExpand_medium;
    uint8_t ucBottomEdgeExpand_medium;
#endif
	int16_t sXExpandStartOffset;
	int16_t sYExpandStartOffset;
	uint16_t usLabelEdgeExpandMode;
	uint16_t usLeftEdgeExpand_Offset;
	uint16_t usRightEdgeExpand_Offset;
	uint16_t usTopEdgeExpand_Offset;
	uint16_t usBottomEdgeExpand_Offset;
	uint16_t usLeftEdgeExpand_Scale;
	uint16_t usRightEdgeExpand_Scale;
	uint16_t usTopEdgeExpand_Scale;
	uint16_t usBottomEdgeExpand_Scale;
#if (BIG_FINGER_EDGE_EXPAND_ALGO_EN == YES)
	uint16_t usLeftEdgeExpand_MaxD;
	uint16_t usRightEdgeExpand_MaxD;
	uint16_t usTopEdgeExpand_MaxD;
	uint16_t usBottomEdgeExpand_MaxD;
	uint16_t usBigFingerEdgeExpandParam1;
	uint16_t usBigFingerEdgeExpandParam2;
	uint16_t usBigFingerEdgeExpandParam3;
#endif
#if (BIG_FINGER_EDGE_ACC_TEST_ALGO_EN == YES)
	uint8_t  ucEdgeReportDelayCnt;
	uint16_t usBigFingerEdgeTest_MoveEventTHD_X;
	uint16_t usBigFingerEdgeTest_MoveEventTHD_Y;
	uint16_t usBigFingerEdgeTestClippingTop		;	
	uint16_t usBigFingerEdgeTestClippingBottom	;	
	uint16_t usBigFingerEdgeTestClippingLeft	;	
	uint16_t usBigFingerEdgeTestClippingRight	;	
	bool_t   bFingerCornerTestClippingOn;
#endif
	bool_t bDoNotExpandPos;
} __PACKED tAlgorithmdEdgeExpandConf_t;

typedef struct
{
	uint8_t ucTipRangeExtend_On;
	bool_t  bExpectClipping_Pen_On;
	uint8_t	ucCompenCoefA;
	uint8_t	ucCompenCoefB;
	uint8_t	ucHoverCompenCoefA;
	uint8_t	ucHoverCompenCoefB;
	bool_t  bCompenEdgeOn;
	uint8_t ucPenPostProcessEdgeTH;
	uint8_t ucPenPostProcessDisTH;
	uint8_t ucPenPostProcessExpendDiv;
	int8_t  cPenPostProcessEndMargin;
	int8_t	cHoverSmoothOffset;
	bool_t  bFullFingerOn;
	int16_t sPenGlobalCoordiXResolutionOffset;
	int16_t sPenGlobalCoordiYResolutionOffset;
	int16_t sPenGlobalCoordiOffsetX;
	int16_t sPenGlobalCoordiOffsetY;
#if (PenGlobalCoordiY_2Region_Set == YES)
	int16_t sPenGlobalCoordiY_2Region_boundary;
	int16_t sPenGlobalCoordiYResolutionOffset1;
	int16_t sPenGlobalCoordiOffsetY1;				
#endif
#if (PEN_EdgeExpandStartOffset_On == YES)
	int16_t	sXExpandStartOffset;
	int16_t	sYExpandStartOffset;
#endif
	uint8_t ucLeftEdgeExpand_local;
	uint8_t ucRightEdgeExpand_local;
	uint8_t ucTopEdgeExpand_local;
	uint8_t ucBottomEdgeExpand_local;
#if (EdgeExpandLocalCornerOffsetAdd == YES)	
	uint16_t usEdgeExpand_local_CornerSizeOffset;
	int8_t cLeftEdgeExpand_local_CornerOffset;
	int8_t cRightEdgeExpand_local_CornerOffset;
	int8_t cTopEdgeExpand_local_CornerOffset;
	int8_t cBottomEdgeExpand_local_CornerOffset;
#endif	
	uint8_t uclatency_up_dis_condition;
	uint8_t uclatency_up_cnt_condition;
	int8_t  clatency_up_dis_offset;
	uint8_t ucideal_inter_dis;	
	uint8_t ucideal_inter_mv;
#if (IdealInterOnlyCorner == YES)
	uint16_t us_ideal_inter_only_corner;
#endif	
	uint8_t uc_connect_count;
	bool_t  bOrgCoordiReport;
	bool_t  bHoverContactReport;
	uint8_t ucMarkBoundaryNum;
#if (Pen_EdgeMarkBoundary == YES)
	uint8_t ucEdgeMarkBoundaryNum;
	uint8_t ucEdgeMarkBoundaryCell;
	uint8_t ucEdgeMarkBoundaryOff;
#endif
    uint8_t ucPenEdgeDebCnt;
	bool_t bDoNotExpandPos;
	uint16_t usLongDisPointExceptionTH;
	uint16_t usPannelOutSideHoverExceptionTH;
	uint16_t usPannelOutSideContactExceptionTH;
	uint8_t ucPannelOutSideHoverExceptionEdgeDis;	
	uint8_t ucPannelOutSideContactExceptionEdgeDis;	
	uint8_t ucPannelOutSideContactExceptionPreDis;
#if (HIGH_HOVER_JITTER_REDUCE == YES)	
	uint8_t	ucHighHoverJitterReduceDisTh;
	int16_t sHighHoverJitterReduceDisScale;
	uint8_t ucHighHoverJitterReduceSmoothOffset;
#endif
#if (OUT_IN_DRAWING == YES)
	uint16_t usOutInBoundTh;
	uint8_t  ucOutInDisTh;
#endif	
#if (WACOM_HOVER_TEST_DELTA_CHANGE == YES)
	uint8_t ucChangeSubTh;
	uint8_t ucChangeDiv;
#endif
#if (WACOM_HOVER_TEST_DELTA_CHANGE == YES)
	int8_t cWacomHoverSmoothOffset;
#endif
	bool_t bUseNewCippingCond_Pen;
#if (PEN_REMOVE_EDGE_EN == YES)
	bool_t bRemoveEdge;
	uint16_t usRemoveEdgeXdistThd;
	uint16_t usRemoveEdgeYdistThd;
	bool_t bUsetRealPastSentPos1;
	uint16_t usEndCoordMargin;
#endif
} __PACKED tAlgorithmPenCoordConf_t;

typedef struct
{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	uint8_t ucMS_RingMode;
#endif
	bool_t  bTiltCalOnlyContact;
	int8_t  cHoverOverShiftRingOffset;
#if (HoverDeltaMul_EN == YES)
	uint8_t ucHoverDeltaMul;
#endif
	uint8_t  bRingRangeExtend_On;
#if (RangeExtend_v2_En == YES)
	uint16_t usTiltSubMaxDelta;	
	uint16_t usTiltDivMin;		
	uint16_t usTiltDivMax;		
#endif	
	uint8_t	ucRingCompenCoefA;
	uint8_t	ucRingCompenCoefB;
#if (RingCoordSmooth_En == YES)	
	uint8_t ucRingCoordSmoothCoef;
#endif
	bool_t  bTiltCalUsingTipOrg;
	uint8_t ucCoordiShiftX_WithTilt;
	uint8_t ucCoordiShiftY_WithTilt;  
	uint8_t ucCoordiShiftEdgeOn;
	uint8_t ucCoordiShiftWithTilt_RingTH;
	uint8_t ucCoordiShiftWithTiltCompenTH;
#if (CoordiShiftWithTiltCompenTH_EdgeOn == YES)
	uint16_t usCoordiShiftWithTiltCompenTH_Edge;
#endif
	uint8_t ucTiltL;
#if (TiltAdjustEn == YES)
	uint8_t ucTiltAdjustEn;
#endif
#if (TiltChangeLimitFilter == YES)
	uint16_t usTiltChangeLimitFilter;
#endif
	uint8_t ucTiltSmoothingFilterCoef;
	uint8_t ucHalfCoefSmoothFrm;
	uint8_t ucHalfCoef;
#if (HighDeltaTiltSmoothCoefChange == YES)
	uint8_t ucHighDelta_TiltSmooth_change_Th;
	int8_t  cHighDelta_TiltSmooth_change_offset;
	int8_t  cHoverMode_TiltSmooth_change_offset;
#endif
#if	(TILT_AREA_FILTER == YES)
	uint16_t usTilt_Change_TH_Reverse;
	uint16_t usTilt_Change_TH_Right;
#endif
	bool_t  bRingCoordiReport;
	uint8_t ucRingMarkBoundaryNum;
#if (TiltBasedRingDelta == YES)
	bool_t  bTiltBasedRingDelta;
#endif
#if (TiltDirecLimitFilter == YES)
	bool_t  bTiltDirecLimitFilter;	
#endif
#if (TiltDeltaLimit_EN == YES)
	uint8_t ucTiltDeltaLimitFilter;		
	uint16_t usTiltDeltaLimit_10_TH;
	#if (TiltDeltaLimit_ADD == YES)
	uint16_t usTiltDeltaLimit_40_TH;
	uint16_t usTiltDeltaLimit_50_TH;
	#endif
	uint16_t usTiltDeltaLimit_55_TH;
	uint16_t usTiltDeltaLimit_60_TH;
	uint16_t usTiltDeltaLimit_65_TH;	
#endif
#if (TiltMedianFilter == YES)
	bool_t  bTiltMedianFilter;
#endif	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	bool_t  bRingBaseTracking;
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	bool_t  bTiltRowIndexChange;
#endif
#if IS_WGPUHDPEN_PROTOCOL_OPERATION
	uint8_t ucRingDirecPosCoef;
	uint8_t ucRingTipDeltaSumCoef;
	uint8_t ucRingTipDeltaSumTH;
	bool_t  b2MUX_SUM_RingMode;
	uint8_t ucTipDirecShiftBasedRingDelta;
#endif
#if (TiltArcSinLookUp_Num > 3)
	bool_t bArcSinLookUp_1;
#endif
#if (UseLastContact3x3 == YES)
	uint16_t usReleaseLastContact3x3Frm;
	uint16_t usUseLastContact3x3Th;
#endif
#if (CORNER_CoordiShift_WithTilt_ADD == YES)
	int8_t cCoordiShiftX_WithTilt_Corner_LT;
	int8_t cCoordiShiftY_WithTilt_Corner_LT;
	int8_t cCoordiShiftX_WithTilt_Corner_RT;
	int8_t cCoordiShiftY_WithTilt_Corner_RT;
	int8_t cCoordiShiftX_WithTilt_Corner_LB;
	int8_t cCoordiShiftY_WithTilt_Corner_LB;
	int8_t cCoordiShiftX_WithTilt_Corner_RB;
	int8_t cCoordiShiftY_WithTilt_Corner_RB;
	int16_t sCoordiShiftWithTiltEdgeAreaOffset;
#endif
} __PACKED tAlgorithmPenTiltConf_t;

typedef struct
{
	uint8_t ucAdaptive_contact_th;
	uint16_t ucPenDataLocalTHD;
	uint16_t  ucPenDataHoverTHD;
	int16_t  sPenDataHoverButtonTHD;
	uint16_t  usPenDataHighHoverButtonRejectTHD;
	uint8_t ucPenDataHighHoverButton1ReliableCnt;
	uint8_t ucPenDataHighHoverButton2ReliableCnt;
	uint8_t ucPenDataHighHoverButtonAdopThOffset;	
	uint8_t ucPenDataHighHoverButtonIIRcoef;
	uint8_t ucForcePenContact_NUM;
	uint8_t ucAbnormalContactRemoveDeltaTH1;
	uint8_t ucAbnormalContactRemoveDeltaTH2;
	uint8_t ucAbnormalContactRemovePressureTH1;
	uint8_t ucAbnormalContactRemovePressureTH2;
	uint8_t ucSEN_CONT_CNT;
	uint8_t ucKeepProtocolNum;

#if USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL
	bool_t bOrgPressureInterpolation;
	uint16_t ulPressureLevelIIR_Prev_Coef_THD; // 1~15
	uint32_t ulPressureChangeRatioTHD; // 0~100
	bool_t bUsedBrushFinishTip;
	bool_t bBrushFinishPressure1Report;
#endif /* USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL */
#if (PenContacctReliableCheck_ON == YES)
	uint8_t ucPenContactReliableCnt;
#endif
} __PACKED tAlgorithmPenDataConf_t;

typedef struct
{
	int16_t top_th;											//  0,  0,  0
	uint8_t top_mul;										//  2,  1,
	uint8_t top_SR;											//  3,
	int16_t bottom_th;										//  4,  2,  1
	uint8_t bottom_mul;										//  6,  3,
	uint8_t bottom_SR;										//  7,
	int16_t left_th;										//  8,  4,  2
	uint8_t left_mul;										// 10,  5,
	uint8_t left_SR;										// 11,
	int16_t right_th;										// 12,  6,  3
	uint8_t right_mul;										// 14,  7,
	uint8_t right_SR;										// 15,
	uint16_t top_hover_th;									// 16,  8,  4
	uint8_t top_hover_mul;									// 18,  9,
	uint8_t top_hover_SR;									// 19,
	uint16_t bottom_hover_th;								// 20, 10,  5
	uint8_t bottom_hover_mul;								// 22, 11,
	uint8_t bottom_hover_SR;								// 23,
	uint16_t left_hover_th;									// 24, 12,  6
	uint8_t left_hover_mul;									// 26, 13,
	uint8_t left_hover_SR;									// 27,
	uint16_t right_hover_th;								// 28, 14,  7
	uint8_t right_hover_mul;								// 30, 15,
	uint8_t right_hover_SR;									// 31,
	uint16_t top_ring_th;									// 32, 16, 8	
	uint8_t top_ring_mul;									// 34, 17, 
	uint8_t top_ring_SR;									// 35, 
	uint16_t bottom_ring_th;								// 36, 18, 9 
	uint8_t bottom_ring_mul;								// 38, 19, 
	uint8_t bottom_ring_SR;									// 39,
	uint16_t left_ring_th;									// 40, 20, 10 
	uint8_t left_ring_mul;									// 42, 21, 12
	uint8_t left_ring_SR;									// 43,
	uint16_t right_ring_th;									// 44, 22, 11 
	uint8_t right_ring_mul;									// 46, 23, 
	uint8_t right_ring_SR;									// 47,
	int8_t  chover_mul_button1_offset;
#if (Ring_EdgeEx_mul_HoverOffset == YES)
	int8_t left_ring_mul_HoverOffset;
	int8_t right_ring_mul_HoverOffset;
	int8_t top_ring_mul_HoverOffset;		
	int8_t bottom_ring_mul_HoverOffset;
#endif
} __attribute__ ((packed)) tAlgorithmEdgePenConf_t;	

typedef struct
{
	int8_t c_edge_smooth_offset_hover;						// 0, 0, 0
	int8_t c_edge_smooth_offset_contact;					// 1, 
	uint8_t uc_global_smooth_dis_condition_contact;			// 2, 1
	int8_t c_global_smooth_offset_contact;					// 3,
	uint16_t us_corner_smooth_delta_condition_hover;		// 4, 2, 1
	int8_t c_corner_smooth_offset_hover;					// 6, 3
	uint8_t uc_edge_smooth_dis_condition_contact; 			// 7,
	uint8_t uc_global_smooth_delta_condition_hover;			// 8, 4, 2
	uint8_t uc_global_smooth_dis_condition_hover;  			// 9
	int8_t  c_global_smooth_offset_hover;        			// 10, 5, 
	uint8_t uc_reserved;									// 11,
	uint16_t usEdge_Range;									// 12, 6, 3
#if (CornerSmoothContact == YES)
	uint16_t usCornerSmoothContact_CornerRange;				// 14, 7, 
	uint8_t  ucCornerSmoothContact_DisCondition;			// 15,			
	int8_t   cCornerSmoothContact_SmoothOffset;				// 16, 8	
#endif
} __attribute__ ((packed)) tAlgorithmDisBaseSmoothConf_t;	


typedef struct
{
	uint8_t th0;								//  0,  0,  0
	int8_t top_mul0;							//  1,
	uint8_t top_SR0;							//  2,  1,
	uint8_t top_mul1;							//  3,	
	uint8_t top_SR1;							//  4,	2,  0
	int8_t bottom_mul0;							//  5,		
	uint8_t bottom_SR0;							//  6,	3,	
	uint8_t bottom_mul1;						//  7,		
	uint8_t bottom_SR1;							//  8,	4,  2
	int8_t left_mul0;							//  9,	
	uint8_t left_SR0;							// 10,  5,
	uint8_t left_mul1;							// 11,
	uint8_t left_SR1;							// 12,	6,  3
	int8_t right_mul0;							// 13,	
	uint8_t right_SR0;							// 14,	7,
	uint8_t right_mul1;							// 15,	
	uint8_t right_SR1;							// 16,	8,  4
    uint8_t reserved;							// 31,			// 17,
	uint16_t top_max_sum;                       // 32, 16,  8   // 18,  9
	uint16_t bottom_max_sum;					// 34, 17		// 20, 10,  5
	uint16_t left_max_sum;						// 36, 18,  9	// 22, 11
	uint16_t right_max_sum;						// 38, 19		// 24, 12,  6
	uint16_t top_max_sum_corner;				// 40, 20, 10	// 26, 13
	uint16_t bottom_max_sum_corner;				// 42, 21		// 28, 14,  7
	uint16_t left_max_sum_corner;				// 44, 22, 11	// 30, 15
	uint16_t right_max_sum_corner;				// 46, 23		// 32, 16,  8
	uint16_t top_max_sum_hover;			    	// 48, 24, 12	// 34, 17
	uint16_t bottom_max_sum_hover;				// 50, 25		// 36, 18,  9
	uint16_t left_max_sum_hover;				// 52, 26, 13	// 38, 19
	uint16_t right_max_sum_hover;				// 54, 27		// 40, 20, 10
	uint8_t  max_sum_hover_div;					// 56, 28, 14	// 42, 21
#if (PEN_CORNER_EXPEND_ADD == YES)
	uint16_t top_max_sum_corner1;	
	uint16_t bottom_max_sum_corner1;	
	uint16_t left_max_sum_corner1;	
	uint16_t right_max_sum_corner1;	

	uint8_t max_sum_corner_TiltY_LT;
	uint8_t max_sum_corner_TiltY_RT;
	uint8_t max_sum_corner_TiltY_LB;
	uint8_t max_sum_corner_TiltY_RB;
	uint8_t max_sum_corner_TiltX_LT;
	uint8_t max_sum_corner_TiltX_RT;
	uint8_t max_sum_corner_TiltX_LB;
	uint8_t max_sum_corner_TiltX_RB;
#endif
#if (PEN_CORNER_EXPEND_ADD_1 == YES)	
	int8_t top_mul0_LeftCornerOffset;
	int8_t top_max_sum_LeftCornerOffset;
	int8_t top_mul0_RightCornerOffset;
	int8_t top_max_sum_RightCornerOffset;
	int8_t bottom_mul0_LeftCornerOffset;		
	int8_t bottom_max_sum_LeftCornerOffset;	
	int8_t bottom_mul0_RightCornerOffset;		
	int8_t bottom_max_sum_RightCornerOffset;
#endif
#if (PEN_Edge_UsePerMaxSum == YES)
	int8_t ucUsePerMaxSum;
	uint32_t ulExtStrengthInit;
#endif
}__attribute__ ((packed))tAlgorithmPenParaEdgeConf_t;	

typedef struct
{
	uint8_t th0;								//  0,  0,  0
	int8_t top_mul0;							//  1,
	uint8_t top_SR0;							//  2,  1,
	uint8_t top_mul1;							//  3,	
	uint8_t top_SR1;							//  4,	2,  0
	int8_t bottom_mul0;							//  5,		
	uint8_t bottom_SR0;							//  6,	3,	
	uint8_t bottom_mul1;						//  7,		
	uint8_t bottom_SR1;							//  8,	4,  2
	int8_t left_mul0;							//  9,	
	uint8_t left_SR0;							// 10,  5,
	uint8_t left_mul1;							// 11,
	uint8_t left_SR1;							// 12,	6,  3
	int8_t right_mul0;							// 13,	
	uint8_t right_SR0;							// 14,	7,
	uint8_t right_mul1;							// 15,	
	uint8_t right_SR1;							// 16,	8,  4
	uint8_t reserved;							// 31,			// 17,
	uint16_t top_max_sum;                       // 32, 16,  8   // 18,  9
	uint16_t bottom_max_sum;					// 34, 17		// 20, 10,  5
	uint16_t left_max_sum;						// 36, 18,  9	// 22, 11
	uint16_t right_max_sum;						// 38, 19		// 24, 12,  6
	uint16_t top_max_sum_corner;				// 40, 20, 10	// 26, 13
	uint16_t bottom_max_sum_corner;				// 42, 21		// 28, 14,  7
	uint16_t left_max_sum_corner;				// 44, 22, 11	// 30, 15
	uint16_t right_max_sum_corner;				// 46, 23		// 32, 16,  8
	uint16_t top_max_sum_hover;			    	// 48, 24, 12	// 34, 17
	uint16_t bottom_max_sum_hover;				// 50, 25		// 36, 18,  9
	uint16_t left_max_sum_hover;				// 52, 26, 13	// 38, 19
	uint16_t right_max_sum_hover;				// 54, 27		// 40, 20, 10
	uint8_t  max_sum_hover_div;					// 56, 28, 14	// 42, 21
	uint8_t PenInfo_ucHover_cnt;								// 43,			//thisInfo->tPenInfo.ucHover_cnt
	uint8_t Label_ucHoverOutCheckFrm;							// 44, 22		//thisModeConf->Label.ucHoverOutCheckFrm
	uint8_t TiltOn;												// 45,			//Tilt_On
	uint8_t ScreenRow_1;//										// 46, 23		//thisInfo->ucScreenRow-1
	uint8_t ScreenCol_1;//										// 47,			//thisInfo->ucScreenCol-1
	uint8_t PenPostProcessFlag;//								// 48, 24		//g_bPenPostProcessFlag
	uint8_t ForcePenContactFlag;//								// 49,			//ForcePenContactFlag
	uint8_t RetVal;												// 50, 25		//g_RetVal
	int8_t mul0;												// 51,
	uint8_t sr0;												// 52, 26
	uint8_t mul1;												// 53,
	uint8_t sr1;												// 54, 27
	int8_t mul0_LR;												// 55,
	uint8_t sr0_LR;												// 56, 28
	uint8_t mul1_LR;											// 57,
	uint8_t sr1_LR;												// 58, 29
	uint8_t reserved1;											// 59,
	uint16_t max_sum;											// 60, 30
	uint16_t max_sum_LR;										// 62,
	int16_t Ring_ExtStrength;									// 64,
	uint8_t RunTMHPenEdgeExpand;								// 66,
	int8_t search_r;											// 67,
	int8_t search_r1;											// 68,
	int8_t apply_r;												// 69,
	int8_t search_c;											// 70,
	int8_t search_c1;											// 71,
	int8_t apply_c;												// 72,
	int8_t OP_mode;												// 73,
    int16_t Reserved;                                           // 74, 37
    int32_t HID_TILT_X;                                         // 76, 38, 19
    int32_t HID_TILT_Y;                                         // 80, 40, 20
    int16_t HID_TILT_TH1;                                       // 84, 42, 21
    int16_t HID_TILT_TH2;                                       // 86, 43
	uint32_t ulExtStrengthAvg;									// 88, 44, 22
	int8_t ucUsePerMaxSum;										// 92, 46, 23
}__attribute__ ((packed))tAlgorithmPenEdgeExpand_t;	

typedef struct
{
	uint8_t ucPalmDetectionOn;
	uint16_t usPalmLevel;
#if (PalmFirstDetectionShift == YES)
	uint8_t ucPalmLevelShift;
#endif
	uint8_t ucPalm_PALM_CONNECT_DIST;
	uint8_t ucPalm_PALM_REGION_UPDATE_PERIOD;
	uint8_t ucPalm_TOUCHDOWNFRAMEMAX;
	uint8_t ucPalm_TOUCHDOWNSLOPETHRESHOLD;
	uint8_t ucPalm_IGNOREFRAMENUM;
	uint8_t ucPalm_KEEPPALMREGIONFRAME;
#if (PalmDrawingOn_En == YES)
	uint8_t ucPalmDrawingOn;
#endif
	bool_t bPalm_WholeTouchRemove;
#if (PENnPalm_PalmAreaMaintain_EN == YES)
	bool_t bPenPalmDetection;
	uint8_t ucPenPalm_PALM_CONNECT_DIST;
	uint8_t ucPenPalm_KEEPPALMREGIONFRAME;
	uint8_t ucPen_KEEPFRAME;
	uint8_t ucPalmRelaseFrame;
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */
#if (PalmCandidateTouchCut_EN == YES)
	uint16_t usPalmCandiStdTh;
	uint8_t ucPalmCandiShapeMatchingTh;
	uint8_t ucPalmCandiDeltaTh;
	uint8_t ucPalmCandiShapeMatchingLearning;
#endif
#if (PalmNonReleaseFingerTouchEn == YES)
	uint8_t ucPalmNonReleaseFingerTouchEn;
#endif
#if (PalmDeltaCheck_On == YES)
	uint8_t ucPalmDeltaCheck_SizeTh;
	uint8_t ucPalmDeltaTh;
	uint16_t usPalmStdTh;
#endif
} __PACKED tAlgorithmPalmConf_t;

typedef struct
{
	// Coord Buffer define
	tTempPos_t     tTempPos;
	tPos_t         tPos;
	tPredictPos_t  tFirstPos;
	tPredictPos_t  tPredictPos;
	tPredictPos_t  tAvgPos;
	tPastPos_t     tPastPos[5];
//	tPastPos_t     tOrgPosHist[COORD_HISTORY_NUM];
	tPos_t         tOrgPos;
	tPastPos_t     tOrgPastPos[5];
	tPastSentPos_t tPastSentPos;
	tPastSentPos_t tRealPastSentPos;
	tPastSentPos_t tRealPastSentPos1;

	int32_t slScaledMoveDistThd;
	uint8_t	ucIdMappedCnt[POSBUF_];

	int8_t cScreenDebCnt[POSBUF_];
	int8_t cScreenTouchOffDebCnt[POSBUF_];

	bool_t ucPostProcessRun[POSBUF_];	// 1 : First Coordinate, 2 : Last Coordinate

	int8_t cRemap[LOOSE_POSBUF_];
	int32_t lPrevDist[POSBUF_];
	bool_t bFirstLongDistanceMoved[POSBUF_];

	int iXOffset;
	int iYOffset;
	int iInternalXRes;
	int iInternalYRes;

	int iXExpandStart;
	int iYExpandStart;

	int iXEdgeStart;
	int iYEdgeStart;

	tKey_t tKey;
//	tKey_t tPastKey;
	tKey_t tPastSentKey;

//	int8_t cKeyDebCnt[MAX_KEY_];
//	int8_t cKeyTouchOffDebCnt[MAX_KEY_];
	
	bool_t bIsMoving[POSBUF_];
	int8_t cIsbefor[POSBUF_];
	tXY_t iStopPos[POSBUF_];
	uint16_t RealMaxDelta[LOOSE_POSBUF_];
	uint16_t PrevRealMaxDelta[LOOSE_POSBUF_];
	uint8_t VirtualEndCount[POSBUF_];
	uint8_t DrawingFlag[LOOSE_POSBUF_];
	uint8_t ucEdgeExpandCoef[LOOSE_POSBUF_];
#if (REMOVE_EDGE_EN == YES)
	bool_t bRemoveEdge[LOOSE_POSBUF_];
#endif
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
	bool_t bInterpolation_On;
#endif
} __PACKED tCoordInfo_t;

typedef struct
{
    int16_t rs;
    int16_t re;
    int16_t cs;
    int16_t ce;
} __PACKED tRect16_t;

typedef struct
{
    tXY_t       tXY;              				//  0,  0,  0
    uint16_t    vusS;            				//  8,  4,  2
    uint16_t    vusR;            				// 10,  5,
    tRect16_t   rect;           				// 12,  6,  3
    uint16_t    MaxDelta;         				// 20, 10,  5
    int16_t     reserved;						// 22, 11,
} __PACKED tPenPos_t;      		// 24, 12,  6

typedef struct
{
    tXY_t       tXY;             				//  0,  0,  0
    uint16_t    vusS;            				//  8,  4,  2
    uint16_t    vusR;            				// 10,  5,
} __PACKED tPenSimplePos_t;		// 12,  6,  3

typedef struct
{
	tPenPos_t       tPos;            			//  0,  0,  0
	tXY_t           tFirstPos;        			// 24, 12,  6
	tXY_t           tAvgPos;          			// 32, 16,  8
	tPenSimplePos_t tPastPos[2];				// 40, 20, 10
	tPenPos_t       tOrgPos;        			// 64, 32, 16 
	tPenSimplePos_t tOrgPastPos[2]; 			// 88, 44, 22
	tPenSimplePos_t tPastSentPos;    			// 112, 56, 28
	uint8_t         ucIdMappedCnt;   			// 124, 62, 31
	uint8_t         ucPostProcessRun;			// 125,
	uint8_t bFirstLongDistanceMoved; 			// 126, 63,
	uint8_t			ucReserved;					// 127,
	tPenSimplePos_t tPastPos2;					// 128, 64, 32
	tPenSimplePos_t tOrgPastPos2;				// 140, 70, 35
	int32_t 		PenContactCnt;				// 152, 76, 38
	int8_t 			cIsbefor;					// 156, 78, 39
	tPenSimplePos_t tRealPastSentPos;
#if (PEN_REMOVE_EDGE_EN == YES)
	tPenSimplePos_t tRealPastSentPos1;
	bool_t 			bRemoveEdge;
#endif
#if (PEN_Edge_UsePerMaxSum == YES)
	uint32_t ulExtStrengthArray[10];
	uint32_t ulExtStrengthAvg;
#endif
} __PACKED tPenCoordInfo_t;    	// 344, 172, 84	

typedef struct
{									//8bit  //32bit
	int32_t TILT_sx;						//0
	int32_t TILT_sy;						//1
	int32_t TILT_distance;					//2
	int32_t TILT_theta;						//3
	int32_t TILT_H;							//4
	int32_t HID_TILT_X;						//5
	int32_t HID_TILT_Y;						//6
	int32_t HID_TWIST;						//7
	int32_t HID_AZIMUTH;					//8
	int32_t HID_ALTITUDE;					//9
	int32_t PastAzimuth;					//10
	int32_t PastAltitude;					//11
	tXY_t	Smooth_PastTilt;				//12
	tXY_t	Area_PastTilt;					//14
	int8_t 	TiltUpDownST_x;			//64	//16
	int8_t 	TiltUpDownST_y;			//65
	tXY_t	Median_PastTilt[6];				
	int16_t	sTilt_cnt;	
	int16_t sRing_ExtStrength;
	int16_t sRingTipStrengthRatio;
#if (HighDeltaTiltSmoothCoefChange == YES)
	bool_t  SmoothingCoefChange;
#endif
	tXY_t   TipOrgPos;
#if (RingCoordSmooth_En == YES)
	tXY_t	PastOrgTiltPos;
	tPenSimplePos_t	PastOrgTipPos;
#endif
}__attribute__ ((packed))tHidTiltInfo_t;

#define COORD_INFO_SIZE    sizeof(tPenCoordInfo_t)
	
extern void algorithm_coord_init(void);
extern void algorithm_coord_init_param(void);
extern void algorithm_coord_initialise_pos_buffer(void);
extern void algorithm_coord_compensation(int mode);
extern void algorithm_coord_process(int mode);
extern void algorithm_coord_modify_pos(tXY_t* pos);
extern int32_t algorithm_coord_calc_distance(tXY_t pos1, tXY_t pos2);
extern int32_t algorithm_coord_calc_comp_distance(tXY_t pos1, tXY_t pos2, tXY_t comp);
extern void alogorithm_coord_modify_pos(tXY_t* old_pos,tXY_t* pos, int index);
extern void algorithm_coord_UpdatePosHistoryInfo(void);
extern void algorithm_coord_interpolation(uint8_t ver);
extern int8_t algorithm_coord_IsEdgeArea(tXY_t * pos, int offset);
extern void algorithm_coordi_compen_with_tilt(uint8_t Tilt_On, uint8_t mode);
extern tXY_t meanInterpolate(tXY_t *p, int start, int num);
extern void algorithm_coord_interpolation_v02(uint8_t ver);
extern void algorithm_width_height_calculation(int cl);
extern uint8_t algorithm_coord_IsEdgeArea_Cell(int8_t r, int8_t c, int8_t offset);
extern void algorithm_HighHoverJitterReduce(void);
extern void algorithm_coord_latency_cal_test_pen(void);
extern void algorithm_coord_latency_cal_test(void);
extern void algorithm_coord_PenCornerSmoothContact(void);
#if (WACOM_HOVER_TEST_DELTA_CHANGE == YES)
extern void algorithm_coord_wacom_hover_test(int local_rs);
#endif
#if (WACOM_HOVER_TEST_POINT_SMOOTH == YES)
extern void algorithm_coord_wacom_hover_test_smooth(uint8_t mode);
#endif
#endif /* ALGORITHM_COORD_H_ */
