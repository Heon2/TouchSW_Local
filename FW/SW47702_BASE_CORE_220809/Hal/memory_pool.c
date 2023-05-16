/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : memory_pool.c
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

#include "env_def.h"
#include "memory_pool.h"


tFullFrameBuf_t FullSharedBuff;
//tLocalFrameBuf_t LocalSharedBuff;

//int16_t  MatrixS16_fullHover[ROW_MAX][COL_MAX];
//int16_t  MatrixS16_fullHover_2[ROW_MAX][COL_MAX];
//#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
//uint32_t ulZeroFingerRawMaskInfo[ROW_MAX][ZERO_FINGER_RAWDATA_MASK_COL_NUM];
//#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
int32_t DspA_LF_ArrayS32_1[8];
int32_t DspA_LF_ArrayS32_2[8];
int32_t DspA_LF_ArrayS32_3[8];
int16_t DspA_TmpDelta[PEN_COORD_ROW_MAX+PEN_COORD_ROW_MAX][COL_MAX];
int16_t DspA_TmpDelta_Pad[PEN_COORD_ROW_MAX+2*PAD_][COL_MAX+2*PAD_];

int32_t DspA_LF_ArrayS32_2_Finger[8];
int32_t DspA_LF_ArrayS32_3_Finger[8];
int16_t DspA_TmpDelta_Finger[ROW_MAX][COL_MAX];

//tMemConf_t* ptMemConf  = &(tMemConf_t) {
//	.iRow_ = ROW_MAX,
//	.iCol_ = COL_MAX,
//};

//uint32_t* pulMallocPointer ;
volatile uint8_t* pucBuf ;
//volatile MSPI_Buffer_TypeDef*  SBuf;

#if (CUSTOMER == MODEL_DEF_FHD_92504_Sony_Oliver_WGP_Pen)
uint32_t shape_array_table[15][15] = 
{ 
{11	,27	,27	,12	,6	,5	,4	,3	,2	,2	,1	,2	,1	,1	,1},
{28	,73	,71	,33	,11	,7	,5	,3	,2	,1	,1	,1	,1	,1	,1},
{28	,70	,69	,39	,15	,8	,5	,3	,2	,1	,1	,1	,1	,1	,1},
{13	,32	,36	,24	,11	,6	,4	,3	,2	,1	,1	,1	,1	,1	,1},
{6	,12	,15	,12	,6	,4	,3	,2	,2	,1	,1	,1	,1	,1	,1},
{4	,6	,8	,6	,4	,3	,2	,2	,1	,1	,1	,1	,1	,1	,1},
{3	,4	,4	,3	,2	,2	,2	,1	,1	,1	,1	,1	,1	,1	,1},
{2	,2	,2	,2	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1},
{1	,2	,2	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1},
{1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1},
{2	,1	,2	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1},
{1	,1	,2	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1},
{1	,2	,2	,2	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1},
{1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,1	,0	,0},
{1	,1	,1	,1	,1	,1	,1	,1	,1	,0	,0	,0	,0	,0	,0},
};
#else
uint32_t shape_array_table[15][15] = 
{ 
{8	,28	,29	,11	,3	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0},
{26	,81	,86	,40	,6	,2	,1	,0	,0	,0	,0	,0	,0	,0	,0},
{28	,86	,90	,46	,8	,2	,1	,0	,0	,0	,0	,0	,0	,0	,0},
{12	,41	,48	,23	,6	,2	,1	,0	,0	,0	,0	,0	,0	,0	,0},
{4	,9	,11	,7	,4	,2	,1	,0	,0	,0	,0	,0	,0	,0	,0},
{2	,3	,3	,3	,2	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0},
{1	,1	,1	,1	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0},
{0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0},
{0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0},
{0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0},
{0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0},
{0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0},
{0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0},
{0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0},
{0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0},
};
#endif
