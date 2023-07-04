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

////////////////////////LBJ_CHECK//////////////////////////
//#define DSP_SMOOTH_GRADIENT	1   		//Gradient 湲곕컲 smoothing �� �쟻�슜�떆 怨≪꽑 �븘湲곌컧 �쑀吏�, 吏곸꽑 smoothing 媛뺥솕
//#define RATE_UP_EN 1		    		//Pen Frame Rate Up Sampling 240 -> 360Hz �� �쟻�슜 �떆 怨≪꽑 �븘湲곌컧 諛� 諛섏쓳�냽�룄(latancy) 媛쒖꽑
//#define TILT_ON 1		    			//Tilt �젙蹂� 怨꾩궛/�쟾�넚 �� �쟻�슜 �떆 PARTIAL_PEN_COORD2 scan �뿉�꽌�뒗 �삁痢≪쥖�몴

#ifdef TILT_ON
#define DSP_SMOOTH_PASTPOS	1 
#define TILT_SMOOTHING	1
#define TILT_AREA_FILTER	1
#define Pen2ReportMethod	1 //0 : All Original, 1 : Pen2 Prediction, 2 : Smoothing of Pen2 prediction, 3 : Pen2 Skip (180hz) 
#else
#ifndef COVER_GLASS_USE
#define DSP_SMOOTH_PASTPOS	1 			//original or past 醫뚰몴�뿉 ���븳 moving averaging �꽑�깮 �� �쟻�슜 �떆 past 醫뚰몴
#endif
#endif

#define PenFingerSameLineNoiseException 1
////////////////////////LBJ_CHECK//////////////////////////

typedef struct
{
	uint16_t usDistThdMovingToStationary;
	uint16_t usDistThdStationaryToMoving;
	uint32_t lMoveSmoothingLevel;
#if (VECTOR_PREDICTION_EN == YES)
	uint8_t ucVectorPredictionCoef;
#endif
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES ||INTERPOLATION_VER3_En == YES)
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
	uint8_t ucWinCertModeDebCnt;
	uint8_t ucWinCertModeVectorPredictionCoef;
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
#if (PalmCandidateTouchCut_EN == YES)
	uint16_t usPalmCandiStdTh;
	uint8_t ucPalmCandiShapeMatchingTh;
	uint8_t ucPalmCandiDeltaTh;
	uint8_t ucPalmCandiShapeMatchingLearning;
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
	tXY_t tPastPosHist[23];						// 152, 76, 38
} __PACKED tPenCoordInfo_t;    	// 344, 172, 84	

typedef struct
{
	uint16_t top_th;							//  0,  0,  0
	uint8_t top_mul;							//  2,  1,
	uint8_t top_SR;								//  3,
	uint16_t bottom_th;							//  4,  2,  1
	uint8_t bottom_mul;							//  6,  3,
	uint8_t bottom_SR;							//  7,
	uint16_t left_th;							//  8,  4,  2
	uint8_t left_mul;							// 10,  5,
	uint8_t left_SR;							// 11,
	uint16_t right_th;							// 12,  6,  3
	uint8_t right_mul;							// 14,  7,
	uint8_t right_SR;							// 15,
	uint16_t top_hover_th;						// 16,  8,  4
	uint8_t top_hover_mul;						// 18,  9,
	uint8_t top_hover_SR;						// 19,
	uint16_t bottom_hover_th;					// 20, 10,  5
	uint8_t bottom_hover_mul;					// 22, 11,
	uint8_t bottom_hover_SR;					// 23,
	uint16_t left_hover_th;						// 24, 12,  6
	uint8_t left_hover_mul;						// 26, 13,
	uint8_t left_hover_SR;						// 27,
	uint16_t right_hover_th;					// 28, 14,  7
	uint8_t right_hover_mul;					// 30, 15,
	uint8_t right_hover_SR;						// 31,
	uint8_t side_mul_val;						// 32, 16,  8
	uint8_t edge_mul_val;						// 33
	int8_t odd_set_mul_val;						// 34, 17
	int8_t even_set_mul_val;					// 35
	uint8_t hover_side_mul_val;					// 36, 18,  9
} __PACKED tEdgePen_t;			// 37

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
}__attribute__ ((packed))tHidTiltInfo_t;

typedef struct
{
	uint8_t th0;								
	int8_t top_mul0;							
	uint8_t top_SR0;									
	uint8_t top_size_th;						
	uint8_t top_apply_th;						
	int8_t bottom_mul0;							
	uint8_t bottom_SR0;							
	uint8_t bottom_size_th;						
	uint8_t bottom_apply_th;					
	int8_t left_mul0;							
	uint8_t left_SR0;							
	uint8_t left_size_th;						
	uint8_t left_apply_th;						
	int8_t right_mul0;							
	uint8_t right_SR0;							
	uint8_t right_size_th;						
	uint8_t right_apply_th;							
	uint16_t top_max_sum;
	uint16_t bottom_max_sum;
	uint16_t left_max_sum;
	uint16_t right_max_sum;
	uint16_t top_max_sum_corner;
	uint16_t bottom_max_sum_corner;
	uint16_t left_max_sum_corner;
	uint16_t right_max_sum_corner;
	uint16_t top_max_sum_Big;
	uint16_t bottom_max_sum_Big;
	uint16_t left_max_sum_Big;
	uint16_t right_max_sum_Big;
	uint8_t  corner_size_th;
}__attribute__ ((packed))tAlgorithmParaEdgeConf_t;		

extern tXY_t tPastPosHist[PAST_COORD_HISTORY_NUM];					 

#define COORD_INFO_SIZE    sizeof(tPenCoordInfo_t)
	
extern void algorithm_coord_init(void);
extern void algorithm_coord_init_param(void);
extern void algorithm_coord_initialise_pos_buffer(void);
//extern void algorithm_coord_compensation(int mode);
extern void algorithm_coord_process(int mode);
extern void algorithm_coord_modify_pos(tXY_t* pos);
extern int32_t algorithm_coord_calc_distance(tXY_t pos1, tXY_t pos2);
extern int32_t algorithm_coord_calc_comp_distance(tXY_t pos1, tXY_t pos2, tXY_t comp);
extern void alogorithm_coord_modify_pos(tXY_t* old_pos,tXY_t* pos, int index);
extern void algorithm_coord_UpdatePosHistoryInfo(void);
extern void algorithm_coord_interpolation(uint8_t ver);
extern void algorithm_coord_interpolation_v02(uint8_t ver);

#endif /* ALGORITHM_COORD_H_ */
