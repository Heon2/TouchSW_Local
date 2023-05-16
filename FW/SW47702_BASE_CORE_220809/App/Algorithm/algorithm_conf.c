/******************************************************************************************************
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

#include "algorithm_def.h"


static const tAlgorithmCommonConf_t * s_kptAlgorithmCommonConf = NULL;
static const tAlgorithmModeConf_t * s_kptAlgorithmModeConf = NULL;
#ifdef _USE_WITH_BOOT_
static tAlgorithmInfo_t * s_ptAlgorithmInfo = &(tAlgorithmInfo_t)
#else
tAlgorithmInfo_t * s_ptAlgorithmInfo = &(tAlgorithmInfo_t)
#endif
{
	// baseline tracking
    .bBlockTracking = NO,
    .bIsRecalCond = NO,
	.bIsRecalCond2 = NO,
	.iRecalCondCnt = 0,
	.iRecalCond2Cnt = 0,
	.bIsRecalCondLocal = NO,

	.bIsPalm = NO,
#if (PENnPalm_PalmAreaMaintain_EN == YES)
	.bWasPalm_AtLeastOnce = NO,
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */
	.bIsHover = YES,
	.bIsGloveTouch = NO,
	.bTouchChecked = NO,
#if USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE
	.bIsIdleToActive = NO,
#endif /* USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE */

    /*
     * Local Sensing Setting
     */
    .bLocal_sensing = NO,

    .tPenInfo.ucCurrentColumnStart = 0,
    .tPenInfo.ucCurrentColumnEnd = 8,

	.tPenInfo.ucHover_cnt = 0,
	.tPenInfo.bPenContact = NO,
	.tPenInfo.bPrevPenContact = NO,
	.tPenInfo.bPenOffChk = NO,

//	.tPenInfo.bSearch_Mode_Flag = 1,

	.tPenInfo.cPreMaxR		 =-1,
	.tPenInfo.cPreMaxC       =-1,
	.tPenInfo.cRing_PreMaxR  =-1,
	.tPenInfo.cRing_PreMaxC  =-1,
#ifdef CalculateDeltaLocalSearch_OPCODE   
	.PenCalcDeltaSetVal.tip_rs = 0,
	.PenCalcDeltaSetVal.ring_rs = 0,
    .PenCalcDeltaSetVal.bContact = 0,
    .PenCalcDeltaSetVal.ucReleaseFrame = 0,
    .PenCalcDeltaSetVal.bAdaptorNoise_SearchMode = 0,
#endif
	.bDiagMode = NO,

	.sLFingerMinVal = 0,

#if (SWIP_QUEUE_MODE)
	.QueueRear = 0,
	.QueueFront = 0,
	.bQueueStart = NO,
	.bTouchOffFlag = NO,
#endif

#if USED_IDLE_TO_ACTIVE_FRAME_DELAY_CHECK
	.ulIdleToActiveFrameCntTHD = DEF_IDLE_TO_ACTIVE_FRAME_DELAY_NUM,
	.ulIdleToActiveCheckCount = 0,
#endif

	.DrawingDirection = 0,
	.WinCertMode = NO,
	.TouchNumCnt = NO,

#if USED_ESD_RECOVERY_RESET_TOUCH_AT_FIRST_FRAME
	.bIsESDGhostRecoveryATFirstFrame_Check = NO,
	.ulESDGhostRecoveryATFirstFrame_Check_Count = 0,
	.ulESDGhostRecoveryATFirstFrame_TouchExpect_Count = 0,
#endif /* USED_ESD_RECOVERY_RESET_TOUCH_AT_FIRST_FRAME */
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
