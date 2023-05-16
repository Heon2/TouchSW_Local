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
	uint8_t  ucDynamicTrackingDistanceMode;
	uint8_t  ucFastDrawingMode;
	uint16_t usMoveDistanceThd;
	uint16_t usDistThdMovingToStationary;
	uint16_t usDistThdStationaryToMoving;
	uint16_t usFirstMoveDistanceThd;
	uint32_t lMoveSmoothingLevel;
	uint8_t	 ucVectorPredictionCoef;
	uint16_t usDrumTestDist;
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
	uint8_t	ucLocalFingerInterpolation_On;
	uint8_t	ucFullFingerInterpolation_On;
	int16_t sInterpolationWeight;
	bool_t  ucExpectClipping_Finger_On;
	int8_t  cEdgeSmoothing_Finger_On;	
	uint8_t ucFirstMoveEventTHD;
	uint8_t ucMoveEventTHD;
	int16_t sFingerGlobalCoordiXResolutionOffset;
	int16_t sFingerGlobalCoordiYResolutionOffset;
	int16_t sFingerGlobalCoordiOffsetX;
	int16_t sFingerGlobalCoordiOffsetY;
	uint8_t ucLeftEdgeExpand;
    uint8_t ucRightEdgeExpand;
    uint8_t ucTopEdgeExpand;
    uint8_t ucBottomEdgeExpand;	
	uint16_t usLeftEdgeExpand_Offset;
	uint16_t usRightEdgeExpand_Offset;
	uint16_t usTopEdgeExpand_Offset;
	uint16_t usBottomEdgeExpand_Offset;
	uint16_t usLeftEdgeExpand_Scale;
	uint16_t usRightEdgeExpand_Scale;
	uint16_t usTopEdgeExpand_Scale;
	uint16_t usBottomEdgeExpand_Scale;
	uint16_t usLeftEdgeExpand_MaxD;
	uint16_t usRightEdgeExpand_MaxD;
	uint16_t usTopEdgeExpand_MaxD;
	uint16_t usBottomEdgeExpand_MaxD;
	uint16_t usBigFingerEdgeExpandParam1;
	uint16_t usBigFingerEdgeExpandParam2;
	uint16_t usBigFingerEdgeExpandParam3;
	uint8_t  ucEdgeReportDelayCnt;
	uint16_t usBigFingerEdgeTest_MoveEventTHD_X;
	uint16_t usBigFingerEdgeTest_MoveEventTHD_Y;
	uint16_t usBigFingerEdgeTestClippingTop		;	
	uint16_t usBigFingerEdgeTestClippingBottom	;	
	uint16_t usBigFingerEdgeTestClippingLeft	;	
	uint16_t usBigFingerEdgeTestClippingRight	;	
	bool_t   bFingerCornerTestClippingOn;
	uint16_t usPostProcessEdgeTH;
	uint8_t ucPostProcessDisTH;
	uint8_t ucPostProcessExpendDiv;
	int8_t cPostProcessEndMargin;
	bool_t bPostProcessInterpolationMode;
	uint16_t usOutInDrawEdgeTh;
	uint8_t ucOutInDrawDisTh;
	uint8_t ucSmoothPastOrgInter;
	int16_t  cDisSmoothOffset;
	bool_t bFingerMeanSmoothing;
	
	uint8_t ucWinCertAssistance;
	bool_t  bWinCertDrawingAssistanceOn;
	uint8_t ucTouchCountMax;			
	uint8_t ucMaxExtendFrameNum;
	int16_t sFirstTouchEnable1Touch;
	int16_t sFirstTouchEnable2Touch;
	int16_t sFirstTouchEnable3Touch;
	int16_t sFirstTouchEnable4Touch;
	int16_t sFirstTouchEnable5Touch;
	uint8_t ucDebCntInner;
	uint8_t ucDebCntEdge;
	uint16_t usFirstDrawingThd;
	uint8_t ucFirstDrawingCellCnt;
	bool_t bSwapXY;
	bool_t bFlipX;
	bool_t bDoNotExpandPos;
	
	uint8_t ucMultiTouchPendPosDebCnt;
} __PACKED tAlgorithmCoordConf_t;

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
	uint8_t ucLeftEdgeExpand_local;
	uint8_t ucRightEdgeExpand_local;
	uint8_t ucTopEdgeExpand_local;
	uint8_t ucBottomEdgeExpand_local;
	uint8_t uclatency_up_dis_condition;
	uint8_t uclatency_up_cnt_condition;
	int8_t  clatency_up_dis_offset;
	uint8_t ucideal_inter_dis;	
	uint8_t ucideal_inter_mv;	
	uint8_t uc_connect_count;
	bool_t  bOrgCoordiReport;
	bool_t  bHoverContactReport;
	uint8_t ucMarkBoundaryNum;
    uint8_t ucPenEdgeDebCnt;
	bool_t bDoNotExpandPos;
	uint16_t usLongDisPointExceptionTH;
} __PACKED tAlgorithmPenCoordConf_t;

typedef struct
{
	bool_t  bTiltCalOnlyContact;
	int8_t  cHoverOverShiftRingOffset;
	uint8_t ucHoverDeltaMul;
	bool_t  bRingRangeExtend_On;
	uint8_t	ucRingCompenCoefA;
	uint8_t	ucRingCompenCoefB;
	bool_t  bTiltCalUsingTipOrg;
	uint8_t ucCoordiShiftX_WithTilt;
	uint8_t ucCoordiShiftY_WithTilt;  
	uint8_t ucCoordiShiftEdgeOn;
	uint8_t ucCoordiShiftWithTilt_RingTH;
	uint8_t ucCoordiShiftWithTiltCompenTH;
	uint8_t ucTiltL;
	uint16_t usTiltChangeLimitFilter;
	uint8_t ucTiltSmoothingFilterCoef;
	uint8_t ucHalfCoefSmoothFrm;
	uint8_t ucHalfCoef;
	uint8_t ucHighDelta_TiltSmooth_change_Th;
	int8_t  cHighDelta_TiltSmooth_change_offset;
	uint16_t usTilt_Change_TH_Reverse;
	uint16_t usTilt_Change_TH_Right;
	bool_t  bRingCoordiReport;
	uint8_t ucRingMarkBoundaryNum;
	uint8_t ucRingDirecPosCoef;
	bool_t  bTiltBasedRingDelta;	
	bool_t  bTiltDirecLimitFilter;	
	uint8_t ucTiltDeltaLimitFilter;	
	uint16_t usTiltDeltaLimit_10_TH;
	uint16_t usTiltDeltaLimit_55_TH;
	uint16_t usTiltDeltaLimit_65_TH;	
	bool_t  bTiltMedianFilter;	
	bool_t  bRingBaseTracking;
	bool_t  bTiltRowIndexChange;
	uint8_t ucRingTipDeltaSumCoef;
	uint8_t ucRingTipDeltaSumTH;
	bool_t  b2MUX_SUM_RingMode;
	uint8_t ucTipDirecShiftBasedRingDelta;
	bool_t bArcSinLookUp_1;
	uint16_t usReleaseLastContact3x3Frm;
	uint16_t usUseLastContact3x3Th;
} __PACKED tAlgorithmPenTiltConf_t;

typedef struct
{
	uint8_t ucPenDataLocalTHD;
	uint8_t  ucPenDataHoverTHD;
//	uint16_t  usPenDataHighContactButtonRejectTHD;
	uint16_t  usPenDataHighHoverButtonRejectTHD;
//	int16_t sHighHoverButtonRejectEdgeDisOffset;
	uint8_t ucForcePenContact_NUM;
	uint8_t ucAbnormalContactRemoveDeltaTH1;
	uint8_t ucAbnormalContactRemoveDeltaTH2;
	uint8_t ucAbnormalContactRemovePressureTH1;
	uint8_t ucAbnormalContactRemovePressureTH2;
	uint8_t ucSEN_CONT_CNT;
	uint8_t ucKeepProtocolNum;
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
}__attribute__ ((packed))tAlgorithmPenEdgeExpand_t;	

typedef struct
{
	uint8_t ucPalmDetectionOn;
	uint16_t usPalmLevel;
	uint8_t ucPalm_PALM_CONNECT_DIST;
	uint8_t ucPalm_PALM_REGION_UPDATE_PERIOD;
	uint8_t ucPalm_TOUCHDOWNFRAMEMAX;
	uint8_t ucPalm_TOUCHDOWNSLOPETHRESHOLD;
	uint8_t ucPalm_IGNOREFRAMENUM;
	uint8_t ucPalm_KEEPPALMREGIONFRAME;
	uint8_t ucPalmDrawingOn;
	bool_t bPalm_WholeTouchRemove;
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
	
	bool_t bInterpolation_On;
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
	int8_t 			cIsbefor;
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
	bool_t  SmoothingCoefChange;
	tXY_t   TipOrgPos;
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
extern void alogorithm_coord_modify_pos(tXY_t* old_pos,tXY_t* pos);
extern void algorithm_coord_UpdatePosHistoryInfo(void);
extern void algorithm_coord_interpolation(uint8_t ver);
extern int8_t algorithm_coord_IsEdgeArea(tXY_t * pos, int offset);
extern void algorithm_coordi_compen_with_tilt(uint8_t Tilt_On, uint8_t mode);
extern tXY_t meanInterpolate(tXY_t *p, int start, int num);
extern void algorithm_coord_interpolation_v02(uint8_t);
extern void algorithm_width_height_calculation(int cl);
extern uint8_t algorithm_coord_IsEdgeArea_Cell(int8_t r, int8_t c, int8_t offset);
#endif /* ALGORITHM_COORD_H_ */
