/*
 * algorithm_conf.h
 *
 *  Created on: 2015. 3. 19.
 *      Author: parkyj2
 */

#ifndef __ALGORITHM_CONF_H__
#define __ALGORITHM_CONF_H__

/*
 * Types
 */
typedef struct
{
//	uint8_t ucMaxTouch_;
//	uint8_t ucLabelSearchDir;
    int iXResolution;
    int iYResolution;
	
    int iXEdgeNum;
    int iXEdgeDen;
    int iYEdgeNum;
    int iYEdgeDen;
	
    uint8_t ucXClipping;
    uint8_t ucYClipping;
	uint8_t ucClippingLeft;
	uint8_t ucClippingRight;
	uint8_t ucClippingTop;
	uint8_t ucClippingBottom;
    uint16_t usPanelXSizeInDmm;
    uint16_t usPanelYSizeInDmm;
	
} __PACKED tAlgorithmCommonConf_t;


typedef struct
{
	tAlgorithmBaseLineConf_t 									BaseLine;	
	tAlgorithmSensingFilterConf_t								SensingFilter;
	tAlgorithmLabelConf_t 										Label;
	tAlgorithmCoordConf_t 										Coord;
	tAlgorithmCoordTrackingConf_t 								CoordTracking;
	tAlgorithmCoordEdgeConf_t 									CoordEdge;
	tAlgorithmdEdgeExpandConf_t 								EdgeExpand;
	tAlgorithmPenCoordConf_t									PenCoord;
	tAlgorithmPenTiltConf_t										PenTilt;
	tAlgorithmPenDataConf_t 									PenData;
	__attribute__ ((aligned(4)))tAlgorithmEdgePenConf_t 		EdgePenSetVal;
	__attribute__ ((aligned(4)))tAlgorithmDisBaseSmoothConf_t	PenDisBaseSmoothSetVal;
	__attribute__ ((aligned(4)))tAlgorithmPenParaEdgeConf_t 	PenParaEdgeSetVal;
	tAlgorithmNoiseConf_t 										Noise;
	tAlgorithmPalmConf_t 										Palm;
	
} __PACKED tAlgorithmModeConf_t;

typedef struct
{
	uint8_t ucCoordiRowStart;
	uint8_t ucCoordiColumnStart;
	uint8_t ucCurrentColumnStart;
	uint8_t ucCurrentColumnEnd;
	uint8_t ucHover_cnt;
	bool_t bPenOffChk;
	bool_t bPenContact;
	bool_t bPrevPenContact;
	int16_t sPrevContactMaxDelta[2];
	tRect_t LocalFingerArea;	
	bool_t bMS_phase;
	int16_t s_search_max_delta[2];
	int16_t s_search_min_delta[2];
	bool_t bMS_Contact2bit[2];
	uint8_t ucTmpForcePenContact_NUM;
	bool_t bPenContactConti;
	bool_t bAdaptorNoise;
	bool_t bReportSkip;
	bool_t bPosUpdateSkip;
	bool_t bSearch_Mode_Flag;
	int8_t cPreMaxR;
	int8_t cPreMaxC;
	int8_t cRing_PreMaxR;
	int8_t cRing_PreMaxC;
	bool_t bEdgeAbnormalContact;
	uint8_t ucSearch_check_cnt;
	uint8_t ucSearch_check_cnt_2;
	uint8_t ucSensing_cont_cnt;
	uint8_t ucSensing_cont_cnt1;	
	uint16_t us_pendata_pressure;
	uint16_t us_pre_pendata_pressure;
	uint16_t us_pre2_pendata_pressure;
	bool_t bPen_button[2];
	bool_t bPre_pen_button[2];
	uint8_t bPen_button_cnt[2];
	bool_t bPenPostProcessFlag;
	bool_t bForcePenContactFlag;
	tXY_t ideal_inter_tmp_pos;
	tXY_t pre_store_pos;
	uint8_t uc_pre_store_cnt;
	bool_t bIdeal_inter_tmp_change;
	tXY_t PrePos;
	uint16_t usPen_Coord_Cnt;
	bool_t bDSP_SendDataEn;
	uint8_t ucEdgeOutInDelayReport;
	bool_t bRateUpFlag;
	uint8_t ucDspB_Lmode;
	uint8_t ucDSP_B_Index;
	int16_t sPPressureOriBit[2];
	bool_t bPen_phase[2];
	uint16_t *pTmpModeRawImg;
	uint16_t *pTmpModeBaseImg;
	int16_t *pTmpModeDeltaImg;
	uint16_t usTmpModeRowStart;
	bool_t bReportEraser;
	uint16_t usSearch_Mode_Cnt;
#if (UseLastContact3x3 == YES)	
	bool_t bUseUseLastContact3x3;
#endif
#if USED_PEN_ID_GET_FUNCTION
	uint8_t ucCurPenHashVal;
	uint8_t ucPrevPenHashVal;
	uint64_t bPenIDVal;
	bool_t bHashnIDCompareDone;
	bool_t bGetHashIDComplete;
	bool_t bGetPenIDComplete;
#endif /* USED_PEN_ID_GET_FUNCTION */
} __PACKED tPenInfo_t;

typedef struct
{
//	uint8_t ucCol;
//	uint8_t ucRow;

//	uint8_t ucTxLessCol;
//	uint8_t ucTxLessRow;

//	uint8_t ucScreenCol;
//	uint8_t ucScreenRow;

	// baseline tracking
	bool_t bBlockTracking;
	bool_t bBlockTrackingByLocalDelta;

    bool_t bIsRecalCond;
    bool_t bIsRecalCond2;
    int iRecalCondCnt;
    int iRecalCond2Cnt;
	bool_t bIsRecalCondLocal;
//    bool_t bDropStatus;
//    bool_t bRecalFlag;

//    bool_t bDoNotExpandPos;

    // feature info of delta Orig. Image
    tOrigDeltaInfo_t tDelta;
    // Label Variable List
    tLabelInfo_t tLabel;

    tCoordInfo_t tCoord;

    __ALIGNED4 tOrigDeltaInfo_t tDelta_local;
    __ALIGNED4 tPenLabelInfo_t tLabel_local_dsp;
    __ALIGNED4 tPenCoordInfo_t tCoord_local_dsp;

#if USED_IDLE_MODE_CONTROL
    __ALIGNED4 tIdleDeltaInfo_t tIdleDeltaInfo;
#endif /* #if USED_IDLE_MODE_CONTROL */
#if USED_LOCAL_IDLE_MODE_CONTROL
    __ALIGNED4 tLocalIdleDeltaInfo_t tLocalIdleDeltaInfo;
#endif /* #if USED_LOCAL_IDLE_MODE_CONTROL */
#if USED_MNT_S3_MODE_FUNCTION
    __ALIGNED4 tS3DeltaInfo_t tS3DeltaInfo;
#endif /* USED_MNT_S3_MODE_FUNCTION */

#if USED_NOISE_HOPPING_FREQ
    tNoiseInfo_t tNoise;
#endif /* USED_NOISE_HOPPING_FREQ */

    bool_t bIsPalm;
//    bool_t bWasPalm;
    bool_t bIsHover;
    bool_t bIsGloveTouch;

    bool_t bTouchExpect;
    bool_t bTouchChecked;
	
#if USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE
	bool_t bIsIdleToActive;
#endif /* USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE */

    /*
     * Local Sensing Setting
     */

    bool_t bTouchExpect_local;	
    bool_t bLocal_sensing;
	
	tPenInfo_t tPenInfo;
	
	bool_t bDiagMode;
	
	int16_t sLFingerMinVal;
	tCell_t tLFingerMinCell;
	int16_t sFullLcoalChangeMinTh;

#if (SWIP_QUEUE_MODE)
	uint8_t QueueRear;
	uint8_t QueueFront;
	bool_t bQueueStart;
	__IO bool_t bTouchOffFlag;
#endif
#if USED_NOISE_HOPPING_FREQ
	uint32_t ulHopFrqIdleModeFrameCntTHD;
	uint32_t ulHoppMainRollbackFrameCntTHD;
	uint32_t ulHoppMainRollbackCheckCount;
#endif /* USED_NOISE_HOPPING_FREQ */
#if USED_IDLE_MODE_CONTROL
	uint32_t ulIdleModeEnterFrameCntTHD;
	uint32_t ulIdleModeEnterCheckCount;
#endif /* USED_IDLE_MODE_CONTROL */
#if USED_PEN_MODE_OPERATION
	uint32_t uPenLocalModeEnterFrameCntTHD;
	uint32_t ulPenLocalModeEnterCheckCount;
#endif /* USED_PEN_MODE_OPERATION */

	uint32_t ulPenLocalModeChangeFrameCntTHD;
	uint32_t ulPenLocalModeChangeCheckCount;
	uint32_t ulPenFullModeChangeFrameCntTHD;
	uint32_t ulPenFullModeChangeCheckCount;

#if USED_LOCAL_IDLE_MODE_CONTROL
	uint32_t ulPenLocalIdleModeEnterFrameCntTHD;
	uint32_t ulPenLocalIdleModeEnterCheckCount;
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */

	uint8_t ucContact_MS;
	
    __attribute__ ((aligned(4))) tAlgorithmEdgePenConf_t tEdgePenSetVal;
	__attribute__ ((aligned(4)))tAlgorithmDisBaseSmoothConf_t PenDisBaseSmoothSetVal;
	__attribute__ ((aligned(4)))tAlgorithmPenEdgeExpand_t PenEdgeExpandSetVal;
	__attribute__ ((aligned(4)))tHidTiltInfo_t tTiltInfo;
#ifdef CalculateDeltaLocalSearch_OPCODE
	__attribute__ ((aligned(4)))tAlgorithmPenCalcDeltaConf_t PenCalcDeltaSetVal;
#endif
	
	uint8_t WinCertMode;
	uint8_t DrawingDirection;
	uint16_t WinCertTrackingDist;
	uint16_t TouchNumCnt;
	
	bool_t bNewVersionPalm;	
	bool_t bLineFilterRepeatCheck;

#if USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK
	bool_t bIsESDRecovery;
#endif /* USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK */

} tAlgorithmInfo_t;

/*
 * Default Methods
 */
extern void algorithm_SetCommonConfig(const tAlgorithmCommonConf_t * _p);
extern const tAlgorithmCommonConf_t *algorithm_GetCommonConfig(void);
extern void algorithm_SetModeConfig(const tAlgorithmModeConf_t * _p);
extern const tAlgorithmModeConf_t *algorithm_GetModeConfig(void);
extern tAlgorithmInfo_t *algorithm_GetInfo(void);

#endif /* __ALGORITHM_CONF_H__ */
