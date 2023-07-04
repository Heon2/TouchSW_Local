/****************************************************************************************************//**
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

typedef struct
{
	uint16_t MatrixU16_PenCoordRawdata		[PEN_COORD_ROW_MAX][COL_MAX];
	uint16_t MatrixU16_PenBase				[ROW_MAX][COL_MAX];
	int16_t  MatrixS16_PenDelta				[PEN_COORD_ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
	/*
	 * TODO : MSB/LSB Concept
	 */
	uint16_t MatrixU8_PenDataRawdata		[PEN_DATA_ROW_MAX/2][COL_MAX];
	uint16_t MatrixU8_PenDataBase			[PEN_DATA_ROW_MAX/2][COL_MAX];
//	uint8_t MatrixU8_PenDataRawdata		[PEN_DATA_ROW_MAX][COL_MAX;
//	uint8_t MatrixU8_PenDataBase			[(ROW_MAX+1)>>1][COL_MAX];

	uint8_t  MatrixU08_PenLabel				[PEN_COORD_ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
} tLocalFrameBuf_t;

/********************************************************************************************/
/*                                 Full Shared Memory union                                 */
/********************************************************************************************/
typedef union
{
	uint16_t MatrixU16_FullfingerRaw  	 	[ROW_MAX][COL_MAX];
} tFullSharedBuf_t;

typedef struct
{
	uint16_t MatrixU16_FullfingerBase		[ROW_MAX][COL_MAX];
	uint16_t MatrixU16_FullfingerBase_HOPP1	[ROW_MAX][COL_MAX];
	uint16_t MatrixU16_FullfingerBase_HOPP2	[ROW_MAX][COL_MAX];
	uint32_t MatrixU32_1             		[ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
	union {
		int16_t  MatrixS16_FingerDelta   		[ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
		int16_t  MatrixS16_FingerDelta_NoPad   	[ROW_MAX][COL_MAX];
	};

	uint8_t  MatrixU08_FullModeLabel 		[ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];

	uint16_t MatrixU16_NoiseIndexRawData 	[NI_ROW_MAX][COL_MAX];
	uint16_t MatrixU16_NoiseIndexDelta		[NI_ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
	uint16_t MatrixU16_NoiseIndexBase		[NI_ROW_MAX][COL_MAX];
	uint16_t MatrixU16_NoiseIndexBase_HOPP1	[NI_ROW_MAX][COL_MAX];
	uint16_t MatrixU16_NoiseIndexBase_HOPP2	[NI_ROW_MAX][COL_MAX];

	tFullSharedBuf_t FULLBUF;
} tFullFrameBuf_t;

/********************************************************************************************/
/*                                  Extern Buffer                                           */
/********************************************************************************************/
//Local Buffer
#define LOCALRAWIMAGE					LocalSharedBuff.MatrixU16_PenCoordRawdata
#define LOCALDATARAW					LocalSharedBuff.MatrixU8_PenDataRawdata
#define LOCALBASELINE					LocalSharedBuff.MatrixU16_PenBase
#define LOCALDELTAIMAGE					LocalSharedBuff.MatrixS16_PenDelta
#define LOCALLABELIMAGE					LocalSharedBuff.MatrixU08_PenLabel
#define LOCALDATABASELINE				LocalSharedBuff.MatrixU8_PenDataBase

//Full Finger Buffer
#define COMMONIMAGE						FullSharedBuff.MatrixU32_1
#define RAWIMAGE						FullSharedBuff.FULLBUF.MatrixU16_FullfingerRaw
#define BASELINEIMAGE					FullSharedBuff.MatrixU16_FullfingerBase
#define BASELINEIMAGE_HOPP1				FullSharedBuff.MatrixU16_FullfingerBase_HOPP1
#define BASELINEIMAGE_HOPP2				FullSharedBuff.MatrixU16_FullfingerBase_HOPP2
#define DELTAIMAGE						FullSharedBuff.MatrixS16_FingerDelta
#define DELTAIMAGE_NOPAD				FullSharedBuff.MatrixS16_FingerDelta_NoPad



#define LABELIMAGE						FullSharedBuff.MatrixU08_FullModeLabel

#define LOCALFINGERRAWIMAGE				FullSharedBuff.FULLBUF.MatrixU16_FullfingerRaw
#define LOCALFINGERDELTAIMAGE			FullSharedBuff.MatrixS16_FingerDelta
#define LOCALFINGERBASELINEIMAGE  		FullSharedBuff.MatrixU16_FullfingerBase

#define NI_RAWIMAGE						FullSharedBuff.MatrixU16_NoiseIndexRawData
#define NI_DELTAIMAGE   				FullSharedBuff.MatrixU16_NoiseIndexDelta
#define NI_BASELINEIMAGE				FullSharedBuff.MatrixU16_NoiseIndexBase
#define NI_BASELINEIMAGE_HOPP1			FullSharedBuff.MatrixU16_NoiseIndexBase_HOPP1
#define NI_BASELINEIMAGE_HOPP2			FullSharedBuff.MatrixU16_NoiseIndexBase_HOPP2

/********************************************************************************************/
/*                                  Extern Buffer                                           */
/********************************************************************************************/
extern tLocalFrameBuf_t LocalSharedBuff;
extern tFullFrameBuf_t FullSharedBuff;

/********************************************************************************************/
/*                                        TEMP                                              */
/********************************************************************************************/
extern int16_t  MatrixS16_fullHover[ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
#define FULLHOVERIMAGE	MatrixS16_fullHover

/********************************************************************************************/
/*                              Local Pen Coordinate Buffer                                 */
/********************************************************************************************/
#define HAL_WRITE_LOCAL_RAW_IMAGE(r, c, data)			LOCALRAWIMAGE[r][c] = data
#define HAL_READ_LOCAL_RAW_IMAGE(r, c)					LOCALRAWIMAGE[r][c]
#define HAL_GET_LOCAL_RAW_IMAGE_PTR()        			(uint16_t *)LOCALRAWIMAGE
#define HAL_GET_LOCAL_RAW_IMAGE_SIZE()       			(sizeof(uint16_t)*PEN_COORD_ROW_MAX*COL_MAX)

#define HAL_WRITE_LOCAL_BASELINE_IMAGE(r, c, data)		LOCALBASELINE[r][c] = data
#define HAL_READ_LOCAL_BASELINE_IMAGE(r, c)				LOCALBASELINE[r][c]
#define HAL_GET_LOCAL_BASELINE_IMAGE_PTR()				(uint16_t *)LOCALBASELINE

#define HAL_WRITE_LOCAL_DELTA_IMAGE(r, c, data)			LOCALDELTAIMAGE[r + PAD_][c + PAD_] = data
#define HAL_READ_LOCAL_DELTA_IMAGE(r, c)				LOCALDELTAIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_LOCAL_DELTA_IMAGE_PTR()					(int16_t *)LOCALDELTAIMAGE
#define HAL_GET_LOCAL_DELTA_IMAGE_SIZE()       			(sizeof(int16_t)*(PEN_COORD_ROW_MAX+2*PAD_)*(COL_MAX+2*PAD_))

#define HAL_WRITE_LOCAL_SEARCH_IMAGE(r, c, data)		FULLHOVERIMAGE[r + PAD_][c + PAD_] = data
#define HAL_READ_LOCAL_SEARCH_IMAGE(r, c)				FULLHOVERIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_LOCAL_SEARCH_IMAGE_PTR()				(int16_t *)FULLHOVERIMAGE
#define HAL_GET_LOCAL_SEARCH_IMAGE_SIZE()       		(sizeof(uint16_t)*(ROW_MAX+2*PAD_)*(COL_MAX+2*PAD_))

/********************************************************************************************/
/*                          		   Local Data Buffer.                        		            */
/********************************************************************************************/
#define HAL_WRITE_LOCAL_DATA_RAW_IMAGE(r, c, data)			LOCALDATARAW[r][c] = data
#define HAL_READ_LOCAL_DATA_RAW_IMAGE(r, c)					LOCALDATARAW[r][c]
#define HAL_GET_LOCAL_DATA_RAW_IMAGE_PTR()					(uint16_t *)LOCALDATARAW
#define HAL_GET_LOCAL_DATA_RAW_IMAGE_SIZE()       			(sizeof(uint8_t)*PEN_DATA_ROW_MAX*COL_MAX)

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
#define HAL_READ_RAW_IMAGE(r, c)						RAWIMAGE[r][c]
#define HAL_GET_RAW_IMAGE_PTR()            				(uint16_t *)RAWIMAGE
#define HAL_GET_RAW_IMAGE_SIZE()           				(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_COMMON_IMAGE(r, c, data)				COMMONIMAGE[r][c] = data
#define HAL_READ_COMMON_IMAGE(r, c)						COMMONIMAGE[r][c]
#define HAL_GET_COMMON_IMAGE_PTR()            			(uint32_t **)COMMONIMAGE
#define HAL_GET_COMMON_IMAGE_SIZE()           			(sizeof(uint32_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_BASELINE_IMAGE(r, c, data)			BASELINEIMAGE[r][c] = data
#define HAL_READ_BASELINE_IMAGE(r, c)					BASELINEIMAGE[r][c]
#define HAL_GET_BASELINE_IMAGE_PTR()            		(uint16_t *)BASELINEIMAGE
#define HAL_GET_BASELINE_IMAGE_SIZE()           		(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_HOPP1_BASELINE_IMAGE(r, c, data)		BASELINEIMAGE_HOPP1[r][c] = data
#define HAL_READ_HOPP1_BASELINE_IMAGE(r, c)				BASELINEIMAGE_HOPP1[r][c]
#define HAL_GET_HOPP1_BASELINE_IMAGE_PTR()				(uint16_t *)BASELINEIMAGE_HOPP1
#define HAL_GET_HOPP1_BASELINE_IMAGE_SIZE()				(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_HOPP2_BASELINE_IMAGE(r, c, data)		BASELINEIMAGE_HOPP2[r][c] = data
#define HAL_READ_HOPP2_BASELINE_IMAGE(r, c)				BASELINEIMAGE_HOPP2[r][c]
#define HAL_GET_HOPP2_BASELINE_IMAGE_PTR()				(uint16_t *)BASELINEIMAGE_HOPP2
#define HAL_GET_HOPP2_BASELINE_IMAGE_SIZE()				(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_DELTA_IMAGE(r, c, data)				DELTAIMAGE[r + PAD_][c + PAD_] = data
#define HAL_READ_DELTA_IMAGE(r, c)						DELTAIMAGE[r + PAD_][c + PAD_]
#define HAL_GET_DELTA_IMAGE_PTR()               		(int16_t *)DELTAIMAGE
#define HAL_GET_DELTA_IMAGE_SIZE()              		(sizeof(int16_t)*(ROW_MAX+2*PAD_)*(COL_MAX+2*PAD_))

#define HAL_WRITE_DELTA_NOPAD_IMAGE(r, c, data)			DELTAIMAGE_NOPAD[r][c] = data
#define HAL_READ_DELTA_NOPAD_IMAGE(r, c)				DELTAIMAGE_NOPAD[r][c]
#define HAL_GET_DELTA_NOPAD_IMAGE_PTR()               	(int16_t *)DELTAIMAGE_NOPAD
#define HAL_GET_DELTA_NOPAD_IMAGE_SIZE()              	(sizeof(int16_t)*(ROW_MAX)*(COL_MAX))

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

#define HAL_NI_WRITE_DELTA_IMAGE(r, c, data)			NI_DELTAIMAGE[r + PAD_][c + PAD_] = data
#define HAL_NI_READ_DELTA_IMAGE(r, c)					NI_DELTAIMAGE[r + PAD_][c + PAD_]
#define HAL_NI_GET_DELTA_IMAGE_PTR()               		(int16_t *)NI_DELTAIMAGE
#define HAL_NI_GET_DELTA_IMAGE_SIZE()              		(sizeof(int16_t)*(NI_ROW_MAX+2*PAD_)*(COL_MAX+2*PAD_))

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

#define HAL_WRITE_ABS_DIFF_IMAGE(r, c, data)			BASELINEIMAGE[r][c] = data
#define HAL_READ_ABS_DIFF_IMAGE(r, c)					BASELINEIMAGE[r][c]
#define HAL_GET_ABS_DIFF_IMAGE_PTR()            		(uint16_t *)BASELINEIMAGE
#define HAL_GET_ABS_DIFF_IMAGE_SIZE()           		sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_ABS_IMAGE(r, c, data)					BASELINEIMAGE[r][c] = data
#define HAL_READ_ABS_IMAGE(r, c)						BASELINEIMAGE[r][c]
#define HAL_GET_ABS_IMAGE_PTR()            				(uint16_t *)BASELINEIMAGE
#define HAL_GET_ABS_IMAGE_SIZE()           				(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_DC_ABS_IMAGE(r, c, data)				BASELINEIMAGE[r][c] = data
#define HAL_READ_DC_ABS_IMAGE(r, c)						BASELINEIMAGE[r][c]
#define HAL_GET_DC_ABS_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE
#define HAL_GET_DC_ABS_IMAGE_SIZE()           			(sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_OS_IMAGE(r, c, data)					BASELINEIMAGE[r][c] = data
#define HAL_READ_OS_IMAGE(r, c)							BASELINEIMAGE[r][c]
#define HAL_GET_OS_IMAGE_PTR()            				(uint16_t *)BASELINEIMAGE
#define HAL_GET_OS_IMAGE_SIZE()           				(sizeof(uint16_t)*ROW_MAX*COL_MAX)

//#define HAL_WRITE_OPEN_1_IMAGE(r, c, data)			BASELINEIMAGE[r][c] = data
//#define HAL_READ_OPEN_1_IMAGE(r, c)					BASELINEIMAGE[r][c]
//#define HAL_GET_OPEN_1_IMAGE_PTR()            		(uint16_t *)BASELINEIMAGE
//#define HAL_GET_OPEN_1_IMAGE_SIZE()           		sizeof(uint16_t)*ROW_MAX*COL_MAX)
//
//#define HAL_WRITE_OPEN_2_IMAGE(r, c, data)			BASELINEIMAGE_HOPP1[r][c] = data
//#define HAL_READ_OPEN_2_IMAGE(r, c)					BASELINEIMAGE_HOPP1[r][c]
//#define HAL_GET_OPEN_2_IMAGE_PTR()            		(uint16_t *)BASELINEIMAGE_HOPP1
//#define HAL_GET_OPEN_2_IMAGE_SIZE()           		sizeof(uint16_t)*ROW_MAX*COL_MAX)
//
//#define HAL_WRITE_SHORT_IMAGE(r, c, data)				BASELINEIMAGE[r][c] = data
//#define HAL_READ_SHORT_IMAGE(r, c)					BASELINEIMAGE[r][c]
//#define HAL_GET_SHORT_IMAGE_PTR()            			(uint16_t *)BASELINEIMAGE
//#define HAL_GET_SHORT_IMAGE_SIZE()           			sizeof(uint16_t)*ROW_MAX*COL_MAX)

#define HAL_WRITE_JITTER_IMAGE(r, c, data)				DELTAIMAGE_NOPAD[r][c] = data
#define HAL_READ_JITTER_IMAGE(r, c)						DELTAIMAGE_NOPAD[r][c]
#define HAL_GET_JITTER_IMAGE_PTR()            			(int16_t *)DELTAIMAGE_NOPAD
#define HAL_GET_JITTER_IMAGE_SIZE()						(sizeof(int16_t)*(ROW_MAX)*(COL_MAX))


#endif /* _MEMORY_POOL_H_ */
