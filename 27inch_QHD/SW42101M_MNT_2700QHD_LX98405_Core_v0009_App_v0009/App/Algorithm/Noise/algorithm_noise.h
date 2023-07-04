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
	uint8_t  	ucNoiseDetectionMode;
	uint8_t  	ucDiscardFrameNum;
	uint8_t  	ucCellCntThd;
	uint8_t  	ucHoppingThd;
	uint16_t 	usRawDataThd;
	int16_t  	sDeltaDataThd;
	uint8_t 	ucErrorFrameProcess;
	uint8_t 	ucHoppingMoveDistanceThd;
	uint8_t 	ucNoiseDetectMaxType;
	bool_t 		bInitAddHoppingThd;
	uint8_t 	ucNoiseStartThd;
	uint8_t 	ucNoiseStartCntThd;
} __PACKED tAlgorithmNoiseConf_t;

typedef struct
{
	uint8_t  ucInitFCnt;
	uint8_t  ucFCnt;
	uint8_t  ucBCnt;
	uint8_t  ucPrevFinger;
	uint8_t  ucPrevHoppingMode;
	uint16_t usPrevMaxVal;
	uint32_t ulSumMaxDiff;
	uint16_t usMaxValBuf[NOISE_DETECTION_FRAME_NUM];
	uint8_t  ucTouchNumBuf[NOISE_DETECTION_FRAME_NUM];
	uint8_t  ucNoiseFrameCnt;	
	bool_t   ucSetHoppingReady;
	uint8_t  ucDebug;
	uint8_t  NoiseFlag;
	uint16_t usPrevMaxVal_NI;
	uint16_t niMaxStrength;
	uint32_t ulSumMaxDiff_NI;
	uint16_t usMaxValBuf_NI[NOISE_DETECTION_FRAME_NUM];
	bool_t 	 bDetectStart;
	uint8_t  ucTouchOffCnt;
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
extern void algorithm_noise_process(eSENSING_MODE_t eSensingMode);
extern bool_t algorithm_noise_detect(void);
extern bool_t algorithm_Check_FreqHopping(void);

#endif /* __ALGORITHM_NOISE_H__ */
