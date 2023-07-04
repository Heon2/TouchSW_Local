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
	uint8_t ucMaxTouch_;
	uint8_t ucLabelSearchDir;
    int iXResolution;
    int iYResolution;
    int iXEdgeNum;
    int iXEdgeDen;
    int iYEdgeNum;
    int iYEdgeDen;
    uint8_t ucLeftEdgeExpand_local;
    uint8_t ucRightEdgeExpand_local;
    uint8_t ucTopEdgeExpand_local;
    uint8_t ucBottomEdgeExpand_local;
	
    uint8_t ucXClipping;
    uint8_t ucYClipping;
	uint8_t ucClippingLeft;
	uint8_t ucClippingRight;
	uint8_t ucClippingTop;
	uint8_t ucClippingBottom;
    uint16_t usPanelXSizeInDmm;
    uint16_t usPanelYSizeInDmm;
	
    __ALIGNED4 tEdgePen_t tEdgePenSetVal;

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
	__attribute__ ((aligned(4)))tAlgorithmParaEdgeConf_t ParaEdgeSetVal;
	
#if (USED_NOISE_HOPPING_FREQ || LGD_ERROR_FRAME_PROCESS_EN)
	tAlgorithmNoiseConf_t Noise;
#endif /* (USED_NOISE_HOPPING_FREQ || LGD_ERROR_FRAME_PROCESS_EN) */

	tAlgorithmPalmConf_t Palm;

//	uint8_t ucValidRadiusRatio;
//	int iValidStrengthRatio;

	uint16_t usIdleTouchThd;
} __PACKED tAlgorithmModeConf_t;

typedef struct
{
	uint8_t ucCoordiRowStart;
	uint8_t ucCoordiColumnStart;
	uint8_t ucCurrentColumnStart;
	uint8_t ucCurrentColumnEnd;

	uint8_t ucHover_cnt;
	bool_t bPenContact;
	bool_t bPrevPenContact;
} __PACKED tPenInfo_t;

typedef struct
{
//	uint8_t ucCol;
//	uint8_t ucRow;
//
//	uint8_t ucTxLessCol;
//	uint8_t ucTxLessRow;
//
//	uint8_t ucScreenCol;
//	uint8_t ucScreenRow;

	// baseline tracking
	bool_t bBlockTracking;

    bool_t bIsRecalCond;
    bool_t bIsRecalCond2;
    int iRecalCondCnt;
    int iRecalCond2Cnt;

#if USED_ESD_RECOVERY_CODE
	uint16_t usAbnormalRawdataNodeCnt;		// Count node that raw data is 4095
	uint16_t usAbnormalRawdataNodeNum;		// Number of node that raw data is 4095
	uint16_t usAbnormalRawdataFrameCnt1;	// Check node that raw data is 4095
	uint16_t usAbnormalRawdataFrameCnt2;	// Check node that raw data is less than MINRAWDATA_MARGIN
#endif /* USED_ESD_RECOVERY_CODE */ 

#if USED_RF_NOISE_RECOVERY_CODE
	uint16_t usDebounceFrmaeCnt;			// Count frame for debounce touch
	uint16_t usAbnormalDeltaNodeCnt;		// Count node that delta data is greater than ABNORMAL_DELTA_PLUS_CNT_THD 
	uint16_t usAbnormalDeltaFrameCnt1;		// Check node that delta data is greater than ABNORMAL_DELTA_PLUS_CNT_THD or less than ABNORMAL_DELTA_MINUS_CNT_THD
	uint16_t usAbnormalDeltaFrameCnt2;		// Check node that delta data is greater than ABNORMAL_DELTA_THD_FOR_RECAL
#endif /* USED_RF_NOISE_RECOVERY_CODE */

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
		
    tLabelInfo_t tLabel_local;
    tCoordInfo_t tCoord_local;

#if USED_NOISE_HOPPING_FREQ
    tNoiseInfo_t tNoise;
	int UnstableStateFrm;
#endif /* USED_NOISE_HOPPING_FREQ */

    bool_t bIsPalm;
    bool_t bWasPalm;
    bool_t bIsHover;
    bool_t bIsGloveTouch;

    bool_t bTouchExpect;
    bool_t bTouchChecked;

    /*
     * Local Sensing Setting
     */

    bool_t bTouchExpect_local;	
    bool_t bLocal_sensing;
	
	tPenInfo_t tPenInfo;
	
	bool_t bDiagMode;
	
	int16_t sLFingerMinVal;
	tCell_t tLFingerMinCell;

#if (SWIP_QUEUE_MODE)
	uint8_t QueueRear;
	uint8_t QueueFront;
	bool_t bQueueStart;
	__IO bool_t bTouchOffFlag;
#endif

#if (USED_IDLE_MODE_CONTROL || USED_FRAME_SKIP_IDLE_MODE_CONTROL)
	uint32_t ulIdleModeEnterFrameCntTHD;
	uint32_t ulIdleModeEnterCheckCount;
#endif /* (USED_IDLE_MODE_CONTROL || USED_FRAME_SKIP_IDLE_MODE_CONTROL) */

#if USED_NOISE_HOPPING_FREQ
	uint32_t ulHopFrqIdleModeFrameCntTHD;
	uint32_t ulHoppMainRollbackCheckCount;
	uint32_t ulHoppMainRollbackFrameCntTHD;
#endif /* USED_NOISE_HOPPING_FREQ */

	int8_t WinCertMode;
	uint8_t DrawingDirection;
	tXY_t DrawingVector;
	uint16_t WinCertTrackingDist;
//	uint16_t TouchNumCnt;
	int16_t TouchFrmCnt;
	
	bool_t bNewVersionPalm;	
	bool_t bLineFilterRepeatCheck;
	
	uint16_t PhoneNoiseFrmCnt;
	uint8_t PhoneNoiseDebEnable;

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
