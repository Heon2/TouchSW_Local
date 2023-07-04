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
	int8_t cNormalizeDelta;
	bool_t bDSP_A;
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

    int32_t  iRecalCond1_PosSum_Thd;
    int32_t  iRecalCond1_AccSum_Thd;
    int32_t  iRecalCond2_AccSum_Thd;
    uint8_t  ucRecalCond1_WaitCnt;
    uint8_t  ucRecalCond2_WaitCnt;	
	bool_t   bFingerBaseTracking;
	bool_t	 bFullFingerBaseTracking;
} __PACKED tAlgorithmBaseLineConf_t;

typedef struct
{
	uint8_t  ucLineFilter;
	int16_t  sLineFilterUpLimit;
	int16_t  sLineFilterLowLimit;
	uint8_t  ucLineFilterColOffset;
	uint8_t  ucMinDeltaTh;
	int16_t  sLineFilterUpLimit_Idle;
	int16_t  sLineFilterLowLimit_Idle;
    uint8_t  ucFilterMaxRow;
    uint8_t  ucFilterMaxCol;
    uint8_t  ucFilterLocalRow;
    uint8_t  ucFilterLocalCol;

    uint8_t  ucFilterLocal_Min_Thd;
    uint8_t  ucFilterLocal_Max_Thd;
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
    uint8_t     ucCurrentColumnEnd;    		  // 19
	
    int iPosCnt;
    int iPosSum;
    int iNegCnt;
    int iNegSum;

    int iMinStrength;
    tCell_t tMaxCellPos;						// 40,20,10
	tCell_t tMinCellPos;						// 42,21,
	
	int16_t sPrevMaxDelta2;
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

extern void algorithm_baseline_init(void);
extern void algorithm_baseline_init_param(void);
extern void algorithm_baseline_init_FingerPoint(void);
extern void algorithm_baseline_tracking_initial(void);
#if (USED_IDLE_MODE_CONTROL && !USED_NORMAL_NI_SENSING)
extern void algorithm_baseline_tracking_initial_idle(bool_t bIsSkip);
#endif /* (USED_IDLE_MODE_CONTROL && !USED_NORMAL_NI_SENSING) */
extern void algorithm_baseline_tracking_continuous(uint8_t mode);
#if USED_IDLE_MODE_CONTROL
extern void algorithm_baseline_tracking_continuous_idle(void);
#endif /* USED_IDLE_MODE_CONTROL */
extern void algorithm_baseline_tracking_continuous_local_finger(void);
extern bool_t algorithm_baseline_calculate_delta(int mode);
extern bool_t algorithm_baseline_calculate_delta_localFinger(int mode);
#if USED_NORMAL_NI_SENSING
extern void algorithm_baseline_calculate_delta_ni(void);
#endif /* USED_NORMAL_NI_SENSING */
#if USED_IDLE_MODE_CONTROL
extern void algorithm_baseline_calculate_delta_idle(void);
#endif /* USED_IDLE_MODE_CONTROL */
//extern bool_t algorithm_baseline_calculate_delta_DSP(int mode);
//extern void algorithm_baseline_extract_max_delta(void); //NOTE : warning����!!
extern bool_t algorithm_local_baseline_calculate_delta(int mode);
extern bool_t abnormal_rawdata_temp(bool_t SET);
extern bool_t abnormal_rawdata_detection_for_hopping(bool_t SET); //NOTE : warning����!!
extern void algorithm_baseline_calculate_mux_range(int r, int c);

#endif /* __ALGORITHM_BASELINE_H__ */
