/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  algorithm_conf.c
 * created on :  17. 4. 2017
 * Author :  mhjang
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

#include "hal_def.h"
#include "algorithm_def.h"


static const tAlgorithmCommonConf_t * s_kptAlgorithmCommonConf = NULL;
static const tAlgorithmModeConf_t * s_kptAlgorithmModeConf = NULL;
static tAlgorithmInfo_t * s_ptAlgorithmInfo = &(tAlgorithmInfo_t)
{
#ifdef _USE_APP_LGD_LIB_
	0,
#else /* _USE_APP_LGD_LIB_ */
//	.ucCol = COL_MAX,
//	.ucRow = ROW_MAX,
//
//	.ucTxLessCol = 0,
//	.ucTxLessRow = 0,
//
//	.ucScreenCol = COL_MAX,
//	.ucScreenRow = ROW_MAX,

	// baseline tracking
    .bBlockTracking = NO,
    .bIsRecalCond = NO,
	.bIsRecalCond2 = NO,
	.iRecalCondCnt = 0,
	.iRecalCond2Cnt = 0,
//	.bDropStatus = NO,
//	.bRecalFlag = NO,

//	.bDoNotExpandPos = NO,

#if USED_ESD_RECOVERY_CODE
	.usAbnormalRawdataNodeCnt = 0,
	.usAbnormalRawdataNodeNum = 0,
	.usAbnormalRawdataFrameCnt1 = 0,
	.usAbnormalRawdataFrameCnt2 = 0,
#endif /* USED_ESD_RECOVERY_CODE */ 

#if USED_RF_NOISE_RECOVERY_CODE
	.usDebounceFrmaeCnt = 0,
	.usAbnormalDeltaNodeCnt = 0,
	.usAbnormalDeltaFrameCnt1 = 0,
	.usAbnormalDeltaFrameCnt2 = 0,
#endif /* USED_RF_NOISE_RECOVERY_CODE */

	.bIsPalm = NO,
	.bWasPalm = NO,
	.bIsHover = YES,
	.bIsGloveTouch = NO,
	.bTouchChecked = NO,

    /*
     * Local Sensing Setting
     */
    .bLocal_sensing = NO,

    .tPenInfo.ucCurrentColumnStart = 0,
    .tPenInfo.ucCurrentColumnEnd = 8,

	.tPenInfo.ucHover_cnt = 0,
	.tPenInfo.bPenContact = NO,
	.tPenInfo.bPrevPenContact = NO,

	.bDiagMode = NO,

	.sLFingerMinVal = 0,

#if (SWIP_QUEUE_MODE)
	.QueueRear = 0,
	.QueueFront = 0,
	.bQueueStart = NO,
	.bTouchOffFlag = NO,
#endif
#endif /* _USE_APP_LGD_LIB_ */

	.DrawingDirection = 0,
	.WinCertMode = 0,
//	.TouchNumCnt = NO,
	
#if USED_NOISE_HOPPING_FREQ	
	.UnstableStateFrm = 0,
#endif /* USED_NOISE_HOPPING_FREQ */
//	.TestModeOn = 0,

	.PhoneNoiseFrmCnt = 0,
	.PhoneNoiseDebEnable = 0,
};

void algorithm_SetCommonConfig(const tAlgorithmCommonConf_t * _p)
{
	s_kptAlgorithmCommonConf = _p;
}

const tAlgorithmCommonConf_t *algorithm_GetCommonConfig(void)
{
    return s_kptAlgorithmCommonConf;
}

void algorithm_SetModeConfig(const tAlgorithmModeConf_t * _p)
{
	s_kptAlgorithmModeConf = _p;
}

const tAlgorithmModeConf_t *algorithm_GetModeConfig(void)
{
    return s_kptAlgorithmModeConf;
}

tAlgorithmInfo_t *algorithm_GetInfo(void)
{
    return s_ptAlgorithmInfo;
}
