/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : param_configset_algorithm_common.h
 * created on : 29. 12. 2020
 * Author : mhjang
 *
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright
 *	 notice, this list of conditions and the following disclaimer.
 *	 - Redistributions in binary form must reproduce the above copyright
 *	 notice, this list of conditions and the following disclaimer in the
 *	 documentation and/or other materials provided with the distribution.
 * - Neither the name of SiW nor the names of its contributors may be used
 *	 to endorse or promote products derived from this software without
 *	 specific prior written permission.
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

#ifndef _PARAM_CONFIGSET_ALGORITHM_COMMON_H_
#define _PARAM_CONFIGSET_ALGORITHM_COMMON_H_


#define PARAMSET_CM_APP_ucFrameRate													(120)
#define PARAMSET_CM_APP_ucIdleFrameRate												(60)
#define PARAMSET_CM_APP_bUsedIdleModeCtrl											(YES)
#define PARAMSET_CM_APP_ucIdleModeEnterSec											(30)
#define PARAMSET_CM_APP_ucPenLocalModeEnterSec										(3)
#define PARAMSET_CM_APP_HoppMainRollbackSec											(30)

#define PARAMSET_CM_APP_bUseFreqHopp												(NO)
#define PARAMSET_CM_APP_MainFreq													(_FREQ_114k_)
#define PARAMSET_CM_APP_HoppFreq1													(_FREQ_86k_)
#define PARAMSET_CM_APP_HoppFreq2													(_FREQ_UNKNOWN_)

//#define PARAMSET_CM_ALGO_ucMaxTouch_												(MAX_TOUCH_)
//#define PARAMSET_CM_ALGO_ucLabelSearchDir											(8)
#define PARAMSET_CM_ALGO_iXResolution												(32768)
#define PARAMSET_CM_ALGO_iYResolution												(32768)

#define PARAMSET_CM_ALGO_iXEdgeNum													(1)
#define PARAMSET_CM_ALGO_iXEdgeDen													(1)
#define PARAMSET_CM_ALGO_iYEdgeNum													(1)
#define PARAMSET_CM_ALGO_iYEdgeDen													(1)

#define PARAMSET_CM_ALGO_ucXClipping												(0)
#define PARAMSET_CM_ALGO_ucYClipping												(0)
#define PARAMSET_CM_ALGO_ucClippingLeft												(0)
#define PARAMSET_CM_ALGO_ucClippingRight											(0)
#define PARAMSET_CM_ALGO_ucClippingTop												(0)
#define PARAMSET_CM_ALGO_ucClippingBottom											(0)
#define PARAMSET_CM_ALGO_usPanelXSizeInDmm											(2000)
#define PARAMSET_CM_ALGO_usPanelYSizeInDmm											(2000)

#endif /* _PARAM_CONFIGSET_ALGORITHM_COMMON_H_ */
