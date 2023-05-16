/*
 * algorithm_noise.h
 *
 *  Created on: 2015. 6. 17.
 *      Author: parkyj2
 */

#ifndef __ALGORITHM_NOISE_H__
#define __ALGORITHM_NOISE_H__

typedef struct
{
	uint8_t  ucNoiseDetectionMode;
	uint8_t  ucDiscardFrameNum;
	uint8_t  ucCellCntThd;
	uint8_t  ucHoppingThd;
	uint8_t  ucNoiseThd;
	uint16_t usRawDataThd;
	int16_t  sDeltaDataThd;
	uint16_t ucTouchOffCntThd;
	uint8_t	 ConflictThd;
	uint16_t Abn2LabelThd;
	uint8_t  ucNiHoppingThd;
	bool_t   bPenNoiseReductionOff;
	uint8_t  ucPenFingerSameLineNoiseSize;
	uint8_t  ucHoverNoiseRejectTH;
	uint8_t  ucHoverNoiseRejectFrm;
	uint8_t  ucSearchNoiseRejectTH;
	uint8_t  ucSearchNoiseRejectFrm;
	int8_t  cAdaptorNoiseTH;
	uint8_t ucAdaptorNoiseContiNum;
	int8_t  cAdaptorNoiseTH_SearchHover;
	uint8_t ucAdaptorNoiseContiNum_SearchHover;
	bool_t 	bPenPosSymbolRepeatCheck;
	uint8_t ucCPITestOn;
	uint8_t ucErrorFrameProcess;
	uint8_t ucHoppingMoveDistanceThd;
} __PACKED tAlgorithmNoiseConf_t;

typedef struct
{
	uint8_t  ucInitFCnt;
	uint8_t  ucFCnt;
	uint8_t  ucBCnt;
	uint16_t uc2FingerCnt;
	bool_t 	 bDetectStart;
	uint8_t  ucPrevFinger;
	uint8_t  ucPrevHoppingMode;
	uint16_t usPrevMaxVal;
	uint32_t ulSumMaxDiff;
	uint16_t usMaxValBuf[NOISE_DETECTION_FRAME_NUM];
	uint8_t  ucTouchNumBuf[NOISE_DETECTION_FRAME_NUM];
	uint8_t  ucNoiseFrameCnt;	
	bool_t   ucSetHoppingReady;
	uint8_t  ucTouchOffCnt;
	uint8_t  ucDebug;
	uint8_t 	NoiseFlag;
	uint16_t usPrevMaxVal_NI;
	uint16_t niMaxStrength;
	uint32_t ulSumMaxDiff_NI;
	uint16_t usMaxValBuf_NI[NOISE_DETECTION_FRAME_NUM];
} __PACKED tNoiseInfo_t;

typedef enum
{
    NOISE_NONE,
    NOISE_FREQ_HOPPING,
    NOISE_PARAM_RESETTING
} __PACKED eNoiseStatus_t;

typedef enum {
	FREQ_UNKNOWN = 0,
	FREQ_MAIN    = 1,
	FREQ_HOPP1	 = 2,
	FREQ_HOPP2	 = 3,
} __PACKED eSelectFREQ;

//typedef enum
//{
//    ALGORITHM_NORMAL = 0,
//    ALGORITHM_NOISE,
//    ALGORITHM_LIMIT
//} __PACKED eChangeAlgorithmMode_t;

typedef enum
{
    FREQ_HOPPING_NONE,
    FREQ_HOPPING_CHANGED
} __PACKED eHoppingStatus_t;

extern void algorithm_noise_init(void);
extern void algorithm_noise_process(void);
extern bool_t algorithm_noise_detect(void);
extern bool_t algorithm_Check_FreqHopping(void);
#if USE_FREQ_HOPPIG_DEBUG
extern void algorithm_Set_FreqHopp(eNoiseStatus_t _NoiseStatus);
#endif
#ifdef FingerAreaLineFilter
void algorithm_noise_FingerAreaLineFilter(int start_r, int end_r, int start_c, int end_c, int local_rs, bool_t MuxSum);
#endif

#endif /* __ALGORITHM_NOISE_H__ */
