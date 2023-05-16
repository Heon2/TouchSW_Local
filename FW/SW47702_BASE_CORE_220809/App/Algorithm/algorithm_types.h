/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : algorithm_types.h
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


#ifndef _ALGORITHM_TYPES_H_
#define _ALGORITHM_TYPES_H_

#define POS_BOOST_SHIFT_                (8)
#define UNIT_DIST                       _BV(POS_BOOST_SHIFT_)

//#define MAX_CONTACT_THD                 10

typedef struct
{
    int32_t x;
    int32_t y;
} __PACKED tXY_t;

typedef struct
{
    uint8_t sFinger_;
    tXY_t tXY[LOOSE_POSBUF_];
    uint16_t vusS[LOOSE_POSBUF_];
    uint16_t vusR[LOOSE_POSBUF_];
    tRect_t rect[LOOSE_POSBUF_];
    uint16_t MaxDelta[LOOSE_POSBUF_];
#if (PENnPalm_PalmAreaMaintain_EN == YES || PalmCandidateTouchCut_EN == YES)
	tCell_t MaxPos[POSBUF_];
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */	
} __PACKED tTempPos_t;

typedef struct
{
    uint8_t sFinger_;
    tXY_t tXY[POSBUF_];
    uint16_t vusS[POSBUF_];
    uint16_t vusR[POSBUF_];
} __PACKED tPastPos_t;

typedef struct
{
    uint8_t sFinger_;
    tXY_t tXY[POSBUF_];
    uint16_t vusS[POSBUF_];
    uint16_t vusR[POSBUF_];
	uint16_t vusW[POSBUF_];
    uint16_t vusH[POSBUF_];
} __PACKED tPastSentPos_t;

typedef struct
{
    uint8_t sFinger_;
    tXY_t tXY[POSBUF_];
} __PACKED tPredictPos_t;

typedef struct
{
    uint8_t sFinger_;
    tXY_t tXY[POSBUF_];
    uint16_t vusS[POSBUF_];
    uint16_t vusR[POSBUF_];
    tRect_t rect[POSBUF_];
    uint16_t MaxDelta[POSBUF_];
#if (PENnPalm_PalmAreaMaintain_EN == YES || PalmCandidateTouchCut_EN == YES || REMOVE_EDGE_EN == YES)
	tCell_t MaxPos[POSBUF_];
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */	
	uint16_t vusW[POSBUF_];
    uint16_t vusH[POSBUF_];
	
		uint32_t uiDistance_All[POSBUF_];
//		uint32_t uiDistance_P2P[POSBUF_];
} __PACKED tPos_t;

typedef struct
{
    uint8_t sKey_;
    int8_t cSingleKeyIdx;
    uint16_t vusS[MAX_KEY_];
} __PACKED tKey_t;

#endif /* __ALGORITHM_TYPES_H__ */
