/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : memory_pool.h
 * created on : 17. 4. 2017
 * Author : mhjang
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

#ifndef _MEMORY_POOL_H_
#define _MEMORY_POOL_H_


/********************************************************************************************/
/*                                 Local Shared Memory union                                */
/********************************************************************************************/
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
extern uint32_t ulZeroFingerRawMaskInfo[ROW_MAX][ZERO_FINGER_RAWDATA_MASK_COL_NUM];
#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */

typedef union
{
	uint16_t MatrixU16_PenDataRawdata		[PEN_DATA_ROW_MAX][COL_MAX]; // MS MPP 2.5
	uint8_t MatrixU8_PenDataRawdata_2		[PEN_DATA_ROW_MAX_2][COL_MAX]; // Wacom AIT
	uint16_t MatrixU16_PenDataRawdata_3		[PEN_DATA_ROW_MAX_3][COL_MAX]; // Wacom WGP
} tLocalPenDataFrameBuf_t;


typedef struct
{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	uint16_t MatrixU16_PenCoordRawdata		[PEN_COORD_ROW_MAX][COL_MAX];
	uint16_t MatrixU16_PenRingRawdata		[PEN_COORD_ROW_MAX*2][COL_MAX];
	uint16_t MatrixU16_PenBase				[ROW_MAX*2][COL_MAX];
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
	uint16_t MatrixU16_PenCoordRawdata		[PEN_COORD_ROW_MAX*2][COL_MAX];
	uint16_t MatrixU16_PenRingRawdata		[PEN_COORD_ROW_MAX*2][COL_MAX];
	#if (USED_ROIC_DEF == ROIC_SW92503B && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
		uint16_t MatrixU16_PenBase				[ROW_MAX*2][COL_MAX];
	#else
		uint16_t MatrixU16_PenBase				[ROW_MAX][COL_MAX];
	#endif
	uint16_t MatrixU16_PenBase_2			[ROW_MAX][COL_MAX];
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */

#if USED_TOUCH_TUNING_PROCESS
	int16_t  MatrixS16_PenDelta				[PEN_COORD_ROW_MAX*2 + 2*PAD_][COL_MAX + 2*PAD_];
#else /* USED_TOUCH_TUNING_PROCESS */
	int16_t  MatrixS16_PenDelta				[PEN_COORD_ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
#endif /* USED_TOUCH_TUNING_PROCESS */

	int16_t  MatrixS16_PenRingDelta			[PEN_COORD_ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	uint16_t MatrixU16_PenDataRawdata_3		[PEN_DATA_ROW_MAX_3][COL_MAX]; // Wacom WGP UHD
	int16_t  MatrixS16_fullHover[1][1];
	int16_t  MatrixS16_fullHover_2[ROW_MAX][COL_MAX];
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
	/*
	 * TODO : MSB/LSB Concept적용 시 변경 해야함!!
	 */
	tLocalPenDataFrameBuf_t					tPenData;
	int16_t  MatrixS16_fullHover[ROW_MAX][COL_MAX];
	#if (USED_ROIC_DEF == ROIC_SW92503B && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
	int16_t  MatrixS16_fullHover_2[1][1];
	#else
	int16_t  MatrixS16_fullHover_2[ROW_MAX][COL_MAX];
	#endif
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
	uint16_t MatrixU16_RingBase				[ROW_MAX][COL_MAX];
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	#if (RingBase2Off == NO)
	uint16_t MatrixU16_RingBase_2			[ROW_MAX][COL_MAX];
	#endif
#endif
#if LOCAL_REBASE_ALGO_EN
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)// || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	uint16_t MatrixU16_ReCalBase			[ROW_MAX][COL_MAX];
	#endif
#endif
//	uint16_t MatrixU8_PenDataRawdata		[PEN_DATA_ROW_MAX][COL_MAX];
//	uint8_t MatrixU8_PenDataRawdata_2		[PEN_DATA_ROW_MAX_2][COL_MAX];
//	uint16_t MatrixU8_PenDataBase			[PEN_DATA_ROW_MAX][COL_MAX];
//	int16_t MatrixS16_PenDataDelta			[PEN_DATA_ROW_MAX_2][COL_MAX];
//	uint8_t MatrixU8_PenDataRawdata			[PEN_DATA_ROW_MAX][COL_MAX;
//	uint8_t MatrixU8_PenDataBase			[(ROW_MAX+1)>>1][COL_MAX];

	uint8_t  MatrixU08_PenLabel				[PEN_COORD_ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
//	uint8_t  MatrixU08_PenNoise				[PEN_COORD_ROW_MAX][COL_MAX];
	uint8_t  MatrixU08_PenNoise1			[ROW_MAX][COL_MAX];
#if ADAPTOR_NOISE_ALGO_EN
	uint8_t  MatrixU08_PenNoise2			[ROW_MAX][COL_MAX];
#endif
} tLocalFrameBuf_t;

/********************************************************************************************/
/*                                 Full Shared Memory union                                 */
/********************************************************************************************/
//typedef union
//{
//	uint16_t MatrixU16_FullfingerRaw  	 	[ROW_MAX][COL_MAX];
//} tFullSharedBuf_t;

typedef struct
{
	uint16_t MatrixU16_FullfingerRaw  	 	[ROW_MAX][COL_MAX];
#if USED_ESD_RECOVERY_SENSING_WITHOUT_MODULATION
	uint16_t MatrixU16_ESDFullfingerRaw		[FINGER_ESD_SCAN_ROW_MAX_NUM][COL_MAX];
	uint16_t MatrixU16_ESDFullfingerBase	[FINGER_ESD_SCAN_ROW_MAX_NUM][COL_MAX];
	#if USED_NOISE_HOPPING_FREQ
		uint16_t MatrixU16_ESDFullfingerBase_HOPP1	[FINGER_ESD_SCAN_ROW_MAX_NUM][COL_MAX];
	#endif /* USED_NOISE_HOPPING_FREQ */
	int16_t  MatrixS16_ESDFingerDelta   		[FINGER_ESD_SCAN_ROW_MAX_NUM][COL_MAX];
#endif

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	uint16_t MatrixU16_FullfingerBase		[ROW_MAX][COL_MAX];
	uint16_t MatrixU16_FullfingerBase_2		[ROW_MAX][COL_MAX];
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
	uint16_t MatrixU16_FullfingerBase		[ROW_MAX][COL_MAX];
	uint16_t MatrixU16_FullfingerBase_2		[ROW_MAX][COL_MAX];
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */

#if USED_NOISE_HOPPING_FREQ
	uint16_t MatrixU16_FullfingerBase_HOPP1	[ROW_MAX][COL_MAX];
	uint16_t MatrixU16_FullfingerBase_HOPP2	[ROW_MAX][COL_MAX];
#endif /* USED_NOISE_HOPPING_FREQ */

#if (USED_RAWDATA_TUNE_CALIBRATION || USED_TOUCH_TUNING_PROCESS)
	uint32_t MatrixU32_1             		[ROW_MAX][COL_MAX];
#else /* (USED_RAWDATA_TUNE_CALIBRATION || USED_TOUCH_TUNING_PROCESS) */
	uint32_t MatrixU32_1             		[ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
#endif /* (USED_RAWDATA_TUNE_CALIBRATION || USED_TOUCH_TUNING_PROCESS) */
	int16_t  MatrixS16_FingerDelta   		[ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
	uint8_t  MatrixU08_FullModeLabel 		[ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)
	#if USED_TOUCH_TUNING_PROCESS
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
			int16_t MatrixS16_PenDataDelta			[PEN_DATA_ROW_MAX_2][COL_MAX];
		#else /*(USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)*/
			int16_t MatrixS16_PenDataDelta			[PEN_DATA_ROW_MAX_3][COL_MAX];
		#endif /*(USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)*/
	#endif /* USED_TOUCH_TUNING_PROCESS */
#endif /* (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN) */
	//int16_t  MatrixS16_fullHover[ROW_MAX][COL_MAX];
//	int16_t  MatrixS16_fullHover_2[ROW_MAX][COL_MAX];
//	uint8_t  MatrixU08_PenNoise1			[ROW_MAX][COL_MAX];
//	uint16_t MatrixU16_NoiseIndexRawData 	[NI_ROW_MAX][COL_MAX];
	int16_t MatrixS16_NoiseIndexDelta		[NI_ROW_MAX][COL_MAX];
	uint16_t MatrixU16_NoiseIndexBase		[NI_ROW_MAX][COL_MAX];
//	uint16_t MatrixU16_NoiseIndexBase_HOPP1	[NI_ROW_MAX][COL_MAX];
//	uint16_t MatrixU16_NoiseIndexBase_HOPP2	[NI_ROW_MAX][COL_MAX];

} tFullFrameBuf_t;


/********************************************************************************************/
/*                                  Extern Buffer                                           */
/********************************************************************************************/
//Local Buffer
#define LOCALRAWIMAGE					LocalSharedBuff.MatrixU16_PenCoordRawdata
#define LOCALRINGRAWIMAGE				LocalSharedBuff.MatrixU16_PenRingRawdata
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
#define LOCALDATARAW_3					LocalSharedBuff.MatrixU16_PenDataRawdata_3 // WGP UHD Pen Data
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
#define LOCALDATARAW					LocalSharedBuff.tPenData.MatrixU16_PenDataRawdata // MS Pen Data
#define LOCALDATARAW_2					LocalSharedBuff.tPenData.MatrixU8_PenDataRawdata_2 // Wacom Pen Data
#define LOCALDATARAW_3					LocalSharedBuff.tPenData.MatrixU16_PenDataRawdata_3 // WGP Pen Data
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */

#define LOCALBASELINE					LocalSharedBuff.MatrixU16_PenBase
#define LOCALBASELINE_2					LocalSharedBuff.MatrixU16_PenBase_2

#define RINGBASELINE					LocalSharedBuff.MatrixU16_RingBase
#define RINGBASELINE_2					LocalSharedBuff.MatrixU16_RingBase_2
#define RINGDELTAIMAGE					LocalSharedBuff.MatrixS16_PenRingDelta

#define RECALBASELINE					LocalSharedBuff.MatrixU16_ReCalBase

#define LOCALDELTAIMAGE					LocalSharedBuff.MatrixS16_PenDelta
#define LOCALDATADELTAIMAGE				FullSharedBuff.MatrixS16_PenDataDelta
#define LOCALLABELIMAGE					LocalSharedBuff.MatrixU08_PenLabel
#define LOCALDATABASELINE				LocalSharedBuff.MatrixU8_PenDataBase
#define LOCALNOISEBUF1					LocalSharedBuff.MatrixU08_PenNoise1
//#define LOCALNOISEBUF1					FullSharedBuff.MatrixU08_PenNoise1
#define LOCALNOISEBUF2					LocalSharedBuff.MatrixU08_PenNoise2
//#define LOCALFINGERAREA					LocalSharedBuff.MatrixB_LocalFingerArea
//#define LOCALFINGERAREA1				LocalSharedBuff.MatrixB_LocalFingerArea1

//Full Finger Buffer
#define COMMONIMAGE						FullSharedBuff.MatrixU32_1
#define RAWIMAGE						FullSharedBuff.MatrixU16_FullfingerRaw
#define RAWIMAGETEST					FullSharedBuff.MatrixU16_FullfingerTEST	// <<< TEST
#define BASELINEIMAGE					FullSharedBuff.MatrixU16_FullfingerBase
#define BASELINEIMAGE_2					FullSharedBuff.MatrixU16_FullfingerBase_2
#define BASELINEIMAGE_HOPP1				FullSharedBuff.MatrixU16_FullfingerBase_HOPP1
#define BASELINEIMAGE_HOPP2				FullSharedBuff.MatrixU16_FullfingerBase_HOPP2
#define DELTAIMAGE						FullSharedBuff.MatrixS16_FingerDelta
#define LABELIMAGE						FullSharedBuff.MatrixU08_FullModeLabel

#define ESDRAWIMAGE						FullSharedBuff.MatrixU16_ESDFullfingerRaw
#define ESDBASELINEIMAGE				FullSharedBuff.MatrixU16_ESDFullfingerBase
#define ESDBASELINEIMAGE_HOPP1			FullSharedBuff.MatrixU16_ESDFullfingerBase_HOPP1
#define ESDDELTAIMAGE					FullSharedBuff.MatrixS16_ESDFingerDelta

#define LOCALFINGERRAWIMAGE				FullSharedBuff.MatrixU16_FullfingerRaw
#define LOCALFINGERDELTAIMAGE			FullSharedBuff.MatrixS16_FingerDelta
#define LOCALFINGERBASELINEIMAGE  		FullSharedBuff.MatrixU16_FullfingerBase
#define LOCALFINGERBASELINEIMAGE_2 		FullSharedBuff.MatrixU16_FullfingerBase_2

#define NI_RAWIMAGE						FullSharedBuff.MatrixU16_FullfingerRaw
#define NI_DELTAIMAGE   				FullSharedBuff.MatrixS16_NoiseIndexDelta
#define NI_BASELINEIMAGE				FullSharedBuff.MatrixU16_NoiseIndexBase
#define NI_BASELINEIMAGE_HOPP1			FullSharedBuff.MatrixU16_NoiseIndexBase_HOPP1
#define NI_BASELINEIMAGE_HOPP2			FullSharedBuff.MatrixU16_NoiseIndexBase_HOPP2

/********************************************************************************************/
/*                                  Extern Buffer                                           */
/********************************************************************************************/
extern tLocalFrameBuf_t LocalSharedBuff;
extern tFullFrameBuf_t FullSharedBuff;

extern int32_t DspA_LF_ArrayS32_1[8];
extern int32_t DspA_LF_ArrayS32_2[8];
extern int32_t DspA_LF_ArrayS32_3[8];
extern int16_t DspA_TmpDelta[PEN_COORD_ROW_MAX+PEN_COORD_ROW_MAX][COL_MAX];
extern int16_t DspA_TmpDelta_Pad[PEN_COORD_ROW_MAX+2*PAD_][COL_MAX+2*PAD_];

#define LINEFILTERBUFST1	        DspA_LF_ArrayS32_1
#define LINEFILTERBUFST2	        DspA_LF_ArrayS32_2
#define LINEFILTERBUFST3	        DspA_LF_ArrayS32_3
#define DSPATMPDELTA				DspA_TmpDelta
#define DSPATMPDELTA_PAD			DspA_TmpDelta_Pad

extern int32_t DspA_LF_ArrayS32_2_Finger[8];
extern int32_t DspA_LF_ArrayS32_3_Finger[8];
extern int16_t DspA_TmpDelta_Finger[ROW_MAX][COL_MAX];

#define LINEFILTERBUFST2_Finger	        DspA_LF_ArrayS32_2_Finger
#define LINEFILTERBUFST3_Finger	        DspA_LF_ArrayS32_3_Finger
#define DSPATMPDELTA_Finger				DspA_TmpDelta_Finger
/********************************************************************************************/
/*                                        TEMP                                              */
/********************************************************************************************/
#define FULLHOVERIMAGE		LocalSharedBuff.MatrixS16_fullHover
#define FULLHOVERIMAGE_2	LocalSharedBuff.MatrixS16_fullHover_2

extern uint8_t ArcSinLookUpTable[128];
extern uint8_t ArcSinLookUpTable_1[128];
extern uint8_t ArcSinLookUpTable_2[128];
extern uint8_t ArcSinLookUpTable_3[128];
extern uint8_t CosLookUpTable[118];
extern uint16_t CosLookUpTable_2[136];
extern uint16_t sucArcTanLookUpTable[101];
extern uint8_t sxMLookUpTable[256];
extern uint8_t sxPLookUpTable[256];
extern uint8_t syMLookUpTable[256];
extern uint8_t syPLookUpTable[256];
extern uint32_t shape_array_table[15][15];
/********************************************************************************************/
/*                              Local Pen Coordinate Buffer                                 */
/********************************************************************************************/
#define HAL_WRITE_LOCAL_RAW_IMAGE(r, c, data)			LOCALRAWIMAGE[r][c] = data
#define HAL_READ_LOCAL_RAW_IMAGE(r, c)					LOCALRAWIMAGE[r][c]
#define HAL_GET_LOCAL_RAW_IMAGE_PTR()        			(uint16_t *)LOCALRAWIMAGE
#define HAL_GET_LOCAL_RAW_IMAGE_SIZE()       			(sizeof(uint16_t)*PEN_COORD_ROW_MAX*2*COL_MAX)

#define HAL_WRITE_LOCAL_RING_RAW_IMAGE(r, c, data)		LOCALRINGRAWIMAGE[r][c] = data
#define HAL_READ_LOCAL_RING_RAW_IMAGE(r, c)				LOCALRINGRAWIMAGE[r][c]
#define HAL_GET_LOCAL_RING_RAW_IMAGE_PTR()        		(uint16_t *)LOCALRINGRAWIMAGE

#define HAL_WRITE_RING_DELTA_IMAGE(r, c, data)			RINGDELTAIMAGE[r + PAD_][c + PAD_]  = data
#define HAL_READ_RING_DELTA_IMAGE(r, c)					RINGDELTAIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_RING_DELTA_IMAGE_PTR()        			(int16_t *)RINGDELTAIMAGE

#define HAL_WRITE_RING_BASELINE_IMAGE(r, c, data)		RINGBASELINE[r][c] = data
#define HAL_READ_RING_BASELINE_IMAGE(r, c)				RINGBASELINE[r][c]
#define HAL_GET_RING_BASELINE_IMAGE_PTR()				(uint16_t *)RINGBASELINE

#define HAL_WRITE_RING_BASELINE_IMAGE_2(r, c, data)		RINGBASELINE_2[r][c] = data
#define HAL_READ_RING_BASELINE_IMAGE_2(r, c)			RINGBASELINE_2[r][c]
#define HAL_GET_RING_BASELINE_IMAGE_2_PTR()				(uint16_t *)RINGBASELINE_2

#define HAL_WRITE_RECAL_BASELINE_IMAGE(r, c, data)		RECALBASELINE[r][c] = data
#define HAL_READ_RECAL_BASELINE_IMAGE(r, c)				RECALBASELINE[r][c]
#define HAL_GET_RECAL_BASELINE_IMAGE_PTR()				(uint16_t *)RECALBASELINE

#define HAL_WRITE_LOCAL_BASELINE_IMAGE(r, c, data)		LOCALBASELINE[r][c] = data
#define HAL_READ_LOCAL_BASELINE_IMAGE(r, c)				LOCALBASELINE[r][c]
#define HAL_GET_LOCAL_BASELINE_IMAGE_PTR()				(uint16_t *)LOCALBASELINE

#define HAL_WRITE_LOCAL_BASELINE_IMAGE_2(r, c, data)	LOCALBASELINE_2[r][c] = data
#define HAL_READ_LOCAL_BASELINE_IMAGE_2(r, c)			LOCALBASELINE_2[r][c]
#define HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR()			(uint16_t *)LOCALBASELINE_2

#define HAL_WRITE_LOCAL_DELTA_IMAGE(r, c, data)			LOCALDELTAIMAGE[r + PAD_][c + PAD_] = data
#define HAL_READ_LOCAL_DELTA_IMAGE(r, c)				LOCALDELTAIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_LOCAL_DELTA_IMAGE_PTR()					(int16_t *)LOCALDELTAIMAGE
#define HAL_GET_LOCAL_DELTA_IMAGE_SIZE()       			(sizeof(int16_t)*(PEN_COORD_ROW_MAX+2*PAD_)*(COL_MAX+2*PAD_))

	
#define HAL_WRITE_LOCAL_DATA_DELTA_IMAGE(r, c, data)	LOCALDATADELTAIMAGE[r][c] = data
#define HAL_READ_LOCAL_DATA_DELTA_IMAGE(r, c)			LOCALDATADELTAIMAGE[r][c]
#define HAL_GET_LOCAL_DATA_DELTA_IMAGE_PTR()			(int16_t *)LOCALDATADELTAIMAGE
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
#define HAL_GET_LOCAL_DATA_DELTA_IMAGE_SIZE()       	(sizeof(int16_t)*(PEN_DATA_ROW_MAX_2)*(COL_MAX))
#else /*(USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)*/
#define HAL_GET_LOCAL_DATA_DELTA_IMAGE_SIZE()       	(sizeof(int16_t)*(PEN_DATA_ROW_MAX_3)*(COL_MAX))
#endif /*(USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)*/

#define HAL_WRITE_LOCAL_SEARCH_IMAGE(r, c, data)		FULLHOVERIMAGE[r][c] = data
#define HAL_READ_LOCAL_SEARCH_IMAGE(r, c)				FULLHOVERIMAGE[r][c]
#define HAL_GET_LOCAL_SEARCH_IMAGE_PTR()				(int16_t *)FULLHOVERIMAGE
#define HAL_GET_LOCAL_SEARCH_IMAGE_SIZE()       		(sizeof(uint16_t)*(ROW_MAX)*(COL_MAX))
	
#define HAL_WRITE_LOCAL_SEARCH_IMAGE_2(r, c, data)		FULLHOVERIMAGE_2[r][c] = data
#define HAL_READ_LOCAL_SEARCH_IMAGE_2(r, c)				FULLHOVERIMAGE_2[r][c]
#define HAL_GET_LOCAL_SEARCH_IMAGE_2_PTR()				(int16_t *)FULLHOVERIMAGE_2
#define HAL_GET_LOCAL_SEARCH_IMAGE_2_SIZE()       		(sizeof(uint16_t)*(ROW_MAX)*(COL_MAX))

/********************************************************************************************/
/*                          		   Local Data Buffer.                        		            */
/********************************************************************************************/
#define HAL_WRITE_LOCAL_DATA_RAW_IMAGE(r, c, data)			LOCALDATARAW[r][c] = data
#define HAL_READ_LOCAL_DATA_RAW_IMAGE(r, c)					LOCALDATARAW[r][c]
#define HAL_GET_LOCAL_DATA_RAW_IMAGE_PTR()					(uint16_t *)LOCALDATARAW
#define HAL_GET_LOCAL_DATA_RAW_IMAGE_SIZE()       			(sizeof(uint16_t)*PEN_DATA_ROW_MAX*COL_MAX)

#define HAL_WRITE_LOCAL_DATA_RAW_IMAGE_2(r, c, data)		LOCALDATARAW_2[r][c] = data
#define HAL_READ_LOCAL_DATA_RAW_IMAGE_2(r, c)				LOCALDATARAW_2[r][c]
#define HAL_GET_LOCAL_DATA_RAW_IMAGE_2_PTR()				(uint8_t *)LOCALDATARAW_2
#define HAL_GET_LOCAL_DATA_RAW_IMAGE_2_SIZE()       		(sizeof(uint8_t)*PEN_DATA_ROW_MAX_2*COL_MAX)

#define HAL_WRITE_LOCAL_DATA_RAW_IMAGE_3(r, c, data)		LOCALDATARAW_3[r][c] = data
#define HAL_READ_LOCAL_DATA_RAW_IMAGE_3(r, c)				LOCALDATARAW_3[r][c]
#define HAL_GET_LOCAL_DATA_RAW_IMAGE_3_PTR()				(uint16_t *)LOCALDATARAW_3
#define HAL_GET_LOCAL_DATA_RAW_IMAGE_3_SIZE()       		(sizeof(uint16_t)*PEN_DATA_ROW_MAX_3*COL_MAX)


#define HAL_WRITE_LOCAL_DATA_BASELINE_IMAGE(r, c, data)		LOCALDATABASELINE[r][c] = data
#define HAL_READ_LOCAL_DATA_BASELINE_IMAGE(r, c)			LOCALDATABASELINE[r][c]
#define HAL_GET_LOCAL_DATA_BASELINE_IMAGE_PTR()         	(uint16_t *)LOCALDATABASELINE

/********************************************************************************************/
/*                          		   Local Finger Buffer.                      		            */
/********************************************************************************************/
#define HAL_WRITE_LOCAL_FINGER_RAW_IMAGE(r, c, data)		LOCALFINGERRAWIMAGE[r][c] = data
#define HAL_READ_LOCAL_FINGER_RAW_IMAGE(r, c)				LOCALFINGERRAWIMAGE[r][c]
#define HAL_GET_LOCAL_FINGER_RAW_IMAGE_PTR()				(uint16_t *)LOCALFINGERRAWIMAGE

#define HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE(r, c, data)	LOCALFINGERBASELINEIMAGE[r][c] = data
#define HAL_READ_LOCAL_FINGER_BASELINE_IMAGE(r, c)			LOCALFINGERBASELINEIMAGE[r][c]
#define HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_PTR()			(uint16_t *)LOCALFINGERBASELINEIMAGE

#define HAL_WRITE_LOCAL_FINGER_BASELINE_IMAGE_2(r, c, data)	LOCALFINGERBASELINEIMAGE_2[r][c] = data
#define HAL_READ_LOCAL_FINGER_BASELINE_IMAGE_2(r, c)		LOCALFINGERBASELINEIMAGE_2[r][c]
#define HAL_GET_LOCAL_FINGER_BASELINE_IMAGE_2_PTR()			(uint16_t *)LOCALFINGERBASELINEIMAGE_2

#define HAL_WRITE_LOCAL_FINGER_DELTA_IMAGE(r, c, data)		LOCALFINGERDELTAIMAGE[r + PAD_][c + PAD_] = data
#define HAL_READ_LOCAL_FINGER_DELTA_IMAGE(r, c)				LOCALFINGERDELTAIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_LOCAL_FINGER_DELTA_IMAGE_PTR()				(int16_t *)LOCALFINGERDELTAIMAGE

/********************************************************************************************/
/*                          		   Local etc.                                           */
/********************************************************************************************/
#define HAL_WRITE_LOCAL_LABEL_IMAGE(r, c, data)				LOCALLABELIMAGE[r + PAD_][c + PAD_] = data
#define HAL_READ_LOCAL_LABEL_IMAGE(r, c)					LOCALLABELIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_LOCAL_LABEL_IMAGE_PTR()						(uint8_t *)LOCALLABELIMAGE
#define HAL_GET_LOCAL_LABEL_IMAGE_SIZE()					(sizeof(int16_t)*(PEN_COORD_ROW_MAX+2*PAD_)*(COL_MAX+2*PAD_))


/********************************************************************************************/
/*                          		   FULL Sensing                                         */
/********************************************************************************************/
#define HAL_WRITE_RAW_IMAGE(r, c, data)					RAWIMAGE[r][c] = data
#define HAL_WRITE_RAW_IMAGE_TEST(r, c, data)			RAWIMAGETEST[r][c] = data		// <<< TEST
#define HAL_READ_RAW_IMAGE(r, c)						RAWIMAGE[r][c]
#define HAL_GET_RAW_IMAGE_PTR()            				(uint16_t *)RAWIMAGE
#define HAL_GET_RAW_IMAGE_TEST_PTR()       				(uint16_t *)RAWIMAGETEST			// <<< TEST
#define HAL_GET_RAW_IMAGE_SIZE()           				(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_ESD_RAW_IMAGE(r, c, data)				ESDRAWIMAGE[r][c] = data
#define HAL_READ_ESD_RAW_IMAGE(r, c)					ESDRAWIMAGE[r][c]
#define HAL_GET_ESD_RAW_IMAGE_PTR()            			(uint16_t *)ESDRAWIMAGE
#define HAL_GET_ESD_RAW_IMAGE_SIZE()           			(sizeof(uint16_t)*FINGER_ESD_SCAN_ROW_MAX_NUM*COL_MAX)

#define HAL_WRITE_COMMON_IMAGE(r, c, data)				COMMONIMAGE[r][c] = data
#define HAL_READ_COMMON_IMAGE(r, c)						COMMONIMAGE[r][c]
#define HAL_GET_COMMON_IMAGE_PTR()            			(uint32_t *)COMMONIMAGE
#define HAL_GET_COMMON_IMAGE_SIZE()           			(sizeof(uint32_t)*ROW_MAX*COL_MAX)
	
//#define HAL_WRITE_ABS_IMAGE(r, c, data)					BASELINEIMAGE[r][c] = data
//#define HAL_READ_ABS_IMAGE(r, c)						BASELINEIMAGE[r][c]
//#define HAL_GET_ABS_IMAGE_PTR()            				(uint16_t *)BASELINEIMAGE
//#define HAL_GET_ABS_IMAGE_SIZE()           				(sizeof(uint16_t)*ROW_MAX*COL_MAX)
//
//#define HAL_WRITE_DC_ABS_IMAGE(r, c, data)				BASELINEIMAGE[r][c] = data
//#define HAL_READ_DC_ABS_IMAGE(r, c)						BASELINEIMAGE[r][c]
//#define HAL_GET_DC_ABS_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE
//#define HAL_GET_DC_ABS_IMAGE_SIZE()           			(sizeof(uint16_t)*ROW_MAX*COL_MAX)
//
//#define HAL_WRITE_OPEN_1_IMAGE(r, c, data)				BASELINEIMAGE[r][c] = data
//#define HAL_READ_OPEN_1_IMAGE(r, c)						BASELINEIMAGE[r][c]
//#define HAL_GET_OPEN_1_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE
//#define HAL_GET_OPEN_1_IMAGE_SIZE()           			sizeof(uint16_t)*ROW_MAX*COL_MAX)
//
//#define HAL_WRITE_OPEN_2_IMAGE(r, c, data)				BASELINEIMAGE_HOPP[r][c] = data
//#define HAL_READ_OPEN_2_IMAGE(r, c)						BASELINEIMAGE_HOPP[r][c]
//#define HAL_GET_OPEN_2_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE_HOPP
//#define HAL_GET_OPEN_2_IMAGE_SIZE()           			sizeof(uint16_t)*ROW_MAX*COL_MAX)
//
//#define HAL_WRITE_SHORT_IMAGE(r, c, data)				BASELINEIMAGE[r][c] = data
//#define HAL_READ_SHORT_IMAGE(r, c)						BASELINEIMAGE[r][c]
//#define HAL_GET_SHORT_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE
//#define HAL_GET_SHORT_IMAGE_SIZE()           			sizeof(uint16_t)*ROW_MAX*COL_MAX)
//
//#define HAL_WRITE_SHORT_2_IMAGE(r, c, data)				BASELINEIMAGE_2[r][c] = data
//#define HAL_READ_SHORT_2_IMAGE(r, c)					BASELINEIMAGE_2[r][c]
//#define HAL_GET_SHORT_2_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE_2
//#define HAL_GET_SHORT_2_IMAGE_SIZE()           			sizeof(uint16_t)*ROW_MAX*COL_MAX)
//
//#define HAL_WRITE_JITTER_IMAGE(r, c, data)				DELTAIMAGE[r][c] = data
//#define HAL_READ_JITTER_IMAGE(r, c)						DELTAIMAGE[r][c]
//#define HAL_GET_JITTER_IMAGE_PTR()            			(int16_t *)DELTAIMAGE
//#define HAL_GET_JITTER_IMAGE_SIZE()						(sizeof(int16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_BASELINE_IMAGE(r, c, data)			BASELINEIMAGE[r][c] = data
#define HAL_READ_BASELINE_IMAGE(r, c)					BASELINEIMAGE[r][c]
#define HAL_GET_BASELINE_IMAGE_PTR()            		(uint16_t *)BASELINEIMAGE
#define HAL_GET_BASELINE_IMAGE_SIZE()           		(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_HOPP1_BASELINE_IMAGE(r, c, data)		BASELINEIMAGE_HOPP1[r][c] = data
#define HAL_READ_HOPP1_BASELINE_IMAGE(r, c)				BASELINEIMAGE_HOPP1[r][c]
#define HAL_GET_HOPP1_BASELINE_IMAGE_PTR()				(uint16_t *)BASELINEIMAGE_HOPP1
#define HAL_GET_HOPP1_BASELINE_IMAGE_SIZE()				(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_ESD_BASELINE_IMAGE(r, c, data)			ESDBASELINEIMAGE[r][c] = data
#define HAL_READ_ESD_BASELINE_IMAGE(r, c)					ESDBASELINEIMAGE[r][c]
#define HAL_GET_ESD_BASELINE_IMAGE_PTR()            		(uint16_t *)ESDBASELINEIMAGE
#define HAL_GET_ESD_BASELINE_IMAGE_SIZE()           		(sizeof(uint16_t)*FINGER_ESD_SCAN_ROW_MAX_NUM*COL_MAX)

#define HAL_WRITE_HOPP1_ESD_BASELINE_IMAGE(r, c, data)		ESDBASELINEIMAGE_HOPP1[r][c] = data
#define HAL_READ_HOPP1_ESD_BASELINE_IMAGE(r, c)				ESDBASELINEIMAGE_HOPP1[r][c]
#define HAL_GET_HOPP1_ESD_BASELINE_IMAGE_PTR()				(uint16_t *)ESDBASELINEIMAGE_HOPP1
#define HAL_GET_HOPP1_ESD_BASELINE_IMAGE_SIZE()				(sizeof(uint16_t)*FINGER_ESD_SCAN_ROW_MAX_NUM*COL_MAX)

#define HAL_WRITE_HOPP2_BASELINE_IMAGE(r, c, data)		BASELINEIMAGE_HOPP2[r][c] = data
#define HAL_READ_HOPP2_BASELINE_IMAGE(r, c)				BASELINEIMAGE_HOPP2[r][c]
#define HAL_GET_HOPP2_BASELINE_IMAGE_PTR()				(uint16_t *)BASELINEIMAGE_HOPP2
#define HAL_GET_HOPP2_BASELINE_IMAGE_SIZE()				(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_DELTA_IMAGE(r, c, data)				DELTAIMAGE[r + PAD_][c + PAD_] = data
#define HAL_READ_DELTA_IMAGE(r, c)						DELTAIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_DELTA_IMAGE_PTR()               		(int16_t *)DELTAIMAGE
#define HAL_GET_DELTA_IMAGE_SIZE()              		(sizeof(int16_t)*(ROW_MAX+2*PAD_)*(COL_MAX+2*PAD_))

#define HAL_WRITE_ESD_DELTA_IMAGE(r, c, data)				ESDDELTAIMAGE[r][c] = data
#define HAL_READ_ESD_DELTA_IMAGE(r, c)						ESDDELTAIMAGE[r][c]
#define HAL_GET_ESD_DELTA_IMAGE_PTR()               		(int16_t *)ESDDELTAIMAGE
#define HAL_GET_ESD_DELTA_IMAGE_SIZE()              		(sizeof(int16_t)*(FINGER_ESD_SCAN_ROW_MAX_NUM)*(COL_MAX))

#define HAL_WRITE_LABEL_IMAGE(r, c, data)				LABELIMAGE[r + PAD_][c + PAD_] = data
#define HAL_READ_LABEL_IMAGE(r, c)						LABELIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_LABEL_IMAGE_PTR()              	 		(uint8_t *)LABELIMAGE
#define HAL_GET_LABEL_IMAGE_SIZE()              		(sizeof(uint8_t)*(ROW_MAX+2*PAD_)*(COL_MAX+2*PAD_))

#define HAL_WRITE_LABEL_LINKLIST_IMAGE(r, c, data)		COMMONIMAGE[r + PAD_][c + PAD_] = data
#define HAL_READ_LABEL_LINKLIST_IMAGE(r, c)				COMMONIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_LABEL_LINKLIST_IMAGE_PTR()          	(uint32_t *)COMMONIMAGE
#define HAL_GET_LABEL_LINKLIST_IMAGE_SIZE()         	(sizeof(uint32_t)*(ROW_MAX+2*PAD_)*(COL_MAX+2*PAD_))

#define HAL_GET_LABEL_LINKLIST_NODE_PTR(r, c)			((uint32_t *)&COMMONIMAGE[r + PAD_][c + PAD_])

#define HAL_WRITE_CONFLICT_LABEL_IMAGE(r, c, data)		COMMONIMAGE[r + PAD_][c + PAD_] = data
#define HAL_READ_CONFLICT_LABEL_IMAGE(r, c)				COMMONIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_CONFLICT_LABEL_IMAGE_PTR()          	(uint32_t *)COMMONIMAGE
#define HAL_GET_CONFLICT_LABEL_IMAGE_SIZE()         	(sizeof(uint32_t)*(ROW_MAX+2*PAD_)*(COL_MAX+2*PAD_))

// use in Diagnostic Mode
#define HAL_WRITE_ACCUM_RAW_IMAGE(r, c, data)			COMMONIMAGE[r][c] = data
#define HAL_READ_ACCUM_RAW_IMAGE(r, c)					COMMONIMAGE[r][c]
#define HAL_GET_ACCUM_RAW_IMAGE_PTR()           		(uint32_t *)COMMONIMAGE
#define HAL_GET_ACCUM_RAW_IMAGE_SIZE()          		(sizeof(uint32_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_MIN_RAW_IMAGE(r, c, data)				BASELINEIMAGE[r][c] = data
#define HAL_READ_MIN_RAW_IMAGE(r, c)					BASELINEIMAGE[r][c]
#define HAL_GET_MIN_RAW_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE
#define HAL_GET_MIN_RAW_IMAGE_SIZE()           			(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_BASELINE_2_IMAGE(r, c, data)			BASELINEIMAGE_2[r][c] = data
#define HAL_READ_BASELINE_2_IMAGE(r, c)					BASELINEIMAGE_2[r][c]
#define HAL_GET_BASELINE_2_IMAGE_PTR()            		(uint16_t *)BASELINEIMAGE_2
#define HAL_GET_BASELINE_2_IMAGE_SIZE()           		(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_FHOVER_IMAGE(r, c, data)				FULLHOVERIMAGE[r + PAD_][c + PAD_] = data
#define HAL_READ_FHOVER_IMAGE(r, c)						FULLHOVERIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_FHOVER_IMAGE_PTR()            			(int16_t *)FULLHOVERIMAGE


/********************************************************************************************/
/*                          		   Noise Index Data Buffer.                              			    */
/********************************************************************************************/

#define HAL_NI_WRITE_RAW_IMAGE(r, c, data)				NI_RAWIMAGE[r][c] = data
#define HAL_NI_READ_RAW_IMAGE(r, c)						NI_RAWIMAGE[r][c]
#define HAL_NI_GET_RAW_IMAGE_PTR()						(uint16_t *)NI_RAWIMAGE
#define HAL_NI_GET_RAW_IMAGE_SIZE()						(sizeof(uint16_t)*NI_ROW_MAX*COL_MAX)

#define HAL_NI_WRITE_DELTA_IMAGE(r, c, data)			NI_DELTAIMAGE[r][c] = data
#define HAL_NI_READ_DELTA_IMAGE(r, c)					NI_DELTAIMAGE[r][c]
#define HAL_NI_GET_DELTA_IMAGE_PTR()               		(int16_t *)NI_DELTAIMAGE
#define HAL_NI_GET_DELTA_IMAGE_SIZE()              		(sizeof(int16_t)*(NI_ROW_MAX)*(COL_MAX))

#define HAL_NI_WRITE_BASELINE_IMAGE(r, c, data)			NI_BASELINEIMAGE[r][c] = data
#define HAL_NI_READ_BASELINE_IMAGE(r, c)				NI_BASELINEIMAGE[r][c]
#define HAL_NI_GET_BASELINE_IMAGE_PTR()					(uint16_t *)NI_BASELINEIMAGE
#define HAL_NI_GET_BASELINE_IMAGE_SIZE()           		(sizeof(uint16_t)*NI_ROW_MAX*COL_MAX)

#define HAL_NI_WRITE_HOP1_BASELINE_IMAGE(r, c, data)	NI_BASELINEIMAGE_HOPP1[r][c] = data
#define HAL_NI_READ_HOP1_BASELINE_IMAGE(r, c)			NI_BASELINEIMAGE_HOPP1[r][c]
#define HAL_NI_GET_HOP1_BASELINE_IMAGE_PTR()			(uint16_t *)NI_BASELINEIMAGE_HOPP1
#define HAL_NI_GET_HOP1_BASELINE_IMAGE_SIZE()           (sizeof(uint16_t)*NI_ROW_MAX*COL_MAX)

#define HAL_NI_WRITE_HOP2_BASELINE_IMAGE(r, c, data)	NI_BASELINEIMAGE_HOPP2[r][c] = data
#define HAL_NI_READ_HOP2_BASELINE_IMAGE(r, c)			NI_BASELINEIMAGE_HOPP2[r][c]
#define HAL_NI_GET_HOP2_BASELINE_IMAGE_PTR()			(uint16_t *)NI_BASELINEIMAGE_HOPP2
#define HAL_NI_GET_HOP2_BASELINE_IMAGE_SIZE()           (sizeof(uint16_t)*NI_ROW_MAX*COL_MAX)

/********************************************************************************************/
/*                          		   Diagnostic Sensing                                         */
/********************************************************************************************/

//#define HAL_WRITE_ABS_DIFF_IMAGE(r, c, data)			BASELINEIMAGE[r][c] = data
//#define HAL_READ_ABS_DIFF_IMAGE(r, c)					BASELINEIMAGE[r][c]
//#define HAL_GET_ABS_DIFF_IMAGE_PTR()            		(uint16_t *)BASELINEIMAGE
//#define HAL_GET_ABS_DIFF_IMAGE_SIZE()           		sizeof(uint16_t)*ROW_MAX*COL_MAX)

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	#define HAL_WRITE_ABS_IMAGE(r, c, data)					BASELINEIMAGE_2[r][c] = data
	#define HAL_READ_ABS_IMAGE(r, c)						BASELINEIMAGE_2[r][c]
	#define HAL_GET_ABS_IMAGE_PTR()            				(uint16_t *)BASELINEIMAGE_2
	#define HAL_GET_ABS_IMAGE_SIZE()           				(sizeof(uint16_t)*ROW_MAX*COL_MAX)

	#define HAL_WRITE_DC_ABS_IMAGE(r, c, data)				BASELINEIMAGE_2[r][c] = data
	#define HAL_READ_DC_ABS_IMAGE(r, c)						BASELINEIMAGE_2[r][c]
	#define HAL_GET_DC_ABS_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE_2
	#define HAL_GET_DC_ABS_IMAGE_SIZE()           			(sizeof(uint16_t)*ROW_MAX*COL_MAX)
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
	#define HAL_WRITE_ABS_IMAGE(r, c, data)					BASELINEIMAGE[r][c] = data
	#define HAL_READ_ABS_IMAGE(r, c)						BASELINEIMAGE[r][c]
	#define HAL_GET_ABS_IMAGE_PTR()            				(uint16_t *)BASELINEIMAGE
	#define HAL_GET_ABS_IMAGE_SIZE()           				(sizeof(uint16_t)*ROW_MAX*COL_MAX)

	#define HAL_WRITE_DC_ABS_IMAGE(r, c, data)				BASELINEIMAGE[r][c] = data
	#define HAL_READ_DC_ABS_IMAGE(r, c)						BASELINEIMAGE[r][c]
	#define HAL_GET_DC_ABS_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE
	#define HAL_GET_DC_ABS_IMAGE_SIZE()           			(sizeof(uint16_t)*ROW_MAX*COL_MAX)
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */

#define HAL_WRITE_DC_ABS_JITTER_IMAGE(r, c, data)		BASELINEIMAGE_2[r][c] = data
#define HAL_READ_DC_ABS_JITTER_IMAGE(r, c)				BASELINEIMAGE_2[r][c]
#define HAL_GET_DC_ABS_JITTER_IMAGE_PTR()            	(int16_t *)BASELINEIMAGE_2
#define HAL_GET_DC_ABS_JITTER_IMAGE_SIZE()           	(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_OPEN_1_IMAGE(r, c, data)				BASELINEIMAGE[r][c] = data
#define HAL_READ_OPEN_1_IMAGE(r, c)						BASELINEIMAGE[r][c]
#define HAL_GET_OPEN_1_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE
#define HAL_GET_OPEN_1_IMAGE_SIZE()           			sizeof(uint16_t)*ROW_MAX*COL_MAX)

//#define HAL_WRITE_OPEN_2_IMAGE(r, c, data)				BASELINEIMAGE_HOPP1[r][c] = data
//#define HAL_READ_OPEN_2_IMAGE(r, c)						BASELINEIMAGE_HOPP1[r][c]
//#define HAL_GET_OPEN_2_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE_HOPP1
//#define HAL_GET_OPEN_2_IMAGE_SIZE()           			sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_SHORT_IMAGE(r, c, data)				BASELINEIMAGE[r][c] = data
#define HAL_READ_SHORT_IMAGE(r, c)						BASELINEIMAGE[r][c]
#define HAL_GET_SHORT_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE
#define HAL_GET_SHORT_IMAGE_SIZE()           			sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_SHORT_2_IMAGE(r, c, data)				BASELINEIMAGE_2[r][c] = data
#define HAL_READ_SHORT_2_IMAGE(r, c)					BASELINEIMAGE_2[r][c]
#define HAL_GET_SHORT_2_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE_2
#define HAL_GET_SHORT_2_IMAGE_SIZE()           			sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_JITTER_IMAGE(r, c, data)				DELTAIMAGE[r][c] = data
#define HAL_READ_JITTER_IMAGE(r, c)						DELTAIMAGE[r][c]
#define HAL_GET_JITTER_IMAGE_PTR()            			(int16_t *)DELTAIMAGE
#define HAL_GET_JITTER_IMAGE_SIZE()						(sizeof(int16_t)*ROW_MAX*COL_MAX)

#endif /* _MEMORY_POOL_H_ */
