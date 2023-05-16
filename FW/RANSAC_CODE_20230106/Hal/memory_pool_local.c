/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : memory_pool_local.c
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


tLocalFrameBuf_t LocalSharedBuff;
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
uint32_t ulZeroFingerRawMaskInfo[ROW_MAX][ZERO_FINGER_RAWDATA_MASK_COL_NUM];
#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */

//#if 1//def COVER_GLASS_USE
uint8_t ArcSinLookUpTable[128]  =
{	
0,
1,2,2,3,4,5,6,7,7,8,
9,10,10,11,12,13,14,15,16,16,
17,17,18,19,20,21,22,23,24,25,
26,27,28,29,30,31,32,33,34,35,
36,37,38,38,39,40,41,42,43,44,
45,45,46,47,48,49,50,51,51,52,
53,54,56,57,58,60,61,62,64,65,
67,68,70,72,74,76,78,80,82,85,
87,90,92,95,97,100,102,105,107,109,
111,112,113,113,113,113,113,113,113,113,
113,113,113,113,113,113,113,113,113,113,
113,113,113,113,113,113,113,113,113,113,
113,113,113,113,113,113,113
};
//#else
uint8_t ArcSinLookUpTable_1[128] = {
0,
1,2,3,4,5,6,7,8,9,10,
12,13,14,15,17,18,19,20,21,22,
23,24,24,25,26,27,28,29,29,30,
31,32,33,34,35,35,36,37,38,38,
39,40,41,42,43,44,45,46,47,48,
49,50,51,53,54,55,56,58,59,60,
62,63,65,66,67,69,70,72,73,75,
77,79,80,82,84,86,87,89,91,93,
94,96,98,99,101,104,106,107,109,110,
110,111,113,115,117,117,117,117,117,117,
117,117,117,117,117,117,117,117,117,117,
117,117,117,117,117,117,117,117,117,117,
117,117,117,117,117,117,117
};
//#endif
uint8_t CosLookUpTable[118]  =
{
	100,
	100,100,100,100,100,100,100,100,100,100,
	99,99,99,99,99,99,99,98,98,98,
	98,98,97,97,97,97,96,96,96,96,
	95,95,95,94,94,94,93,93,92,92,
	92,91,91,90,90,90,89,89,88,88,
	87,87,86,86,85,85,84,84,83,83,
	82,81,81,80,80,79,78,78,77,76,
	76,75,75,74,73,72,72,71,70,70,
	69,68,67,67,66,65,64,64,63,62,
	61,61,60,59,58,57,57,56,55,54,
	53,52,51,51,50,49,48,47,46,45,
	44,44,43,42,41,40,39
};

uint16_t sucArcTanLookUpTable[101]=
{
0,
57,115,172,229,286,343,400,457,514,571,
628,684,741,797,853,909,965,1020,1076,1131,
1186,1241,1295,1350,1404,1457,1511,1564,1617,1670,
1722,1774,1826,1878,1929,1980,2030,2081,2131,2180,
2229,2278,2327,2375,2423,2470,2517,2564,2610,2657,
2702,2747,2792,2837,2881,2925,2968,3011,3054,3096,
3138,3180,3221,3262,3302,3342,3382,3422,3461,3499,
3537,3575,3613,3650,3687,3723,3760,3795,3831,3866,
3901,3935,3969,4003,4036,4070,4102,4135,4167,4199,
4230,4261,4292,4323,4353,4383,4413,4442,4471,4500
};
