/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  app_tuning_process.h
 * created on :  16. 01. 2020
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

#ifndef _APP_TUNING_PROCESS_H_
#define _APP_TUNING_PROCESS_H_


typedef enum
{
	TUNING_MAIN_OPERATION_ENTER = 0,
	TUNING_MAIN_OPERATION_SYSTEM_INIT = 1,

	TUNING_MAIN_OPERATION_SRIC_INIT = 2,
	TUNING_MAIN_OPERATION_READY = 3,

	TUNING_MAIN_OPERATION_FULL_REFERENCE_INIT = 4,
	TUNING_MAIN_OPERATION_LOCAL_REFERENCE_INIT = 5,

	TUNING_MAIN_OPERATION_LOCAL_READY = 6,
	TUNING_MAIN_OPERATION_LOCAL_DONE = 7,

	TUNING_MAIN_OPERATION_FULL_READY = 8,
	TUNING_MAIN_OPERATION_FULL_DONE = 9,

	TUNING_MAIN_OPERATION_EXIT = 255,

} eTuningMainOperStatus_t;

typedef enum
{
	TUNING_CTRL_TYPE_NORMAL = 0,
	TUNING_CTRL_TYPE_NORMAL_LINEFILTER = 1,

	TUNING_CTRL_TYPE_PEN_POS_MIN_MAX_JITTER_MEASURE = 2,
	TUNING_CTRL_TYPE_PEN_POS_LINEFILTER_MIN_MAX_JITTER_MEASURE = 3,

	TUNING_CTRL_TYPE_FINGER_JITTER_MEASURE = 4,
	TUNING_CTRL_TYPE_FINGER_LINEFILTER_JITTER_MEASURE = 5,

	TUNING_CTRL_TYPE_TILT_JITTER_MEASURE = 6,
	TUNING_CTRL_TYPE_TILT_LINEFILTER_JITTER_MEASURE = 7,

	TUNING_CTRL_TYPE_PEN_DATA_MIN_MAX_JITTER_MEASURE = 8,
	TUNING_CTRL_TYPE_PEN_DATA_LINEFILTER_MIN_MAX_JITTER_MEASURE = 9,

	TUNING_CTRL_TYPE_PEN_POS_DELTA_JITTER_MEASURE = 10,
	TUNING_CTRL_TYPE_PEN_POS_DELTA_LINEFILTER_JITTER_MEASURE = 11,

	TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_AVERAGE = 12,

	TUNING_CTRL_TYPE_NORMAL_FINGER_RAWDATA_GIP_NOISE_SEARCH = 13,

	TUNING_CTRL_TYPE_FINGER_DELTA_JITTER_MEASURE = 14,
	TUNING_CTRL_TYPE_FINGER_DELTA_LINEFILTER_JITTER_MEASURE = 15,

	TUNING_CTRL_TYPE_LIMIT = 255,

} eTuningCtrlType_t;

typedef enum
{
	TUNING_CTRL_TYPE_PEN_POS_VIEW_All = 0,
	TUNING_CTRL_TYPE_PEN_POS_VIEW_1 = 1,
	TUNING_CTRL_TYPE_PEN_POS_VIEW_2 = 2,
	TUNING_CTRL_TYPE_PEN_POS_VIEW_3 = 3,
	TUNING_CTRL_TYPE_PEN_POS_VIEW_4 = 4,

	TUNING_CTRL_TYPE_PEN_POS_NONE_VIEW_1 = 5,
	TUNING_CTRL_TYPE_PEN_POS_NONE_VIEW_2 = 6,
	TUNING_CTRL_TYPE_PEN_POS_NONE_VIEW_3 = 7,
	TUNING_CTRL_TYPE_PEN_POS_NONE_VIEW_4 = 8,

	TUNING_CTRL_TYPE_PEN_POS_NONE_VIEW_1_2 = 9,
	TUNING_CTRL_TYPE_PEN_POS_NONE_VIEW_3_4 = 10,

	TUNING_CTRL_TYPE_PEN_POS_VIEW_LIMIT = 255,

} eTuningCtrlPenPosViewType_t;

typedef enum
{
	TUNING_CTRL_TYPE_PEN_TILT_VIEW_All = 0,
	TUNING_CTRL_TYPE_PEN_TILT_VIEW_1 = 1,
	TUNING_CTRL_TYPE_PEN_TILT_VIEW_2 = 2,
	TUNING_CTRL_TYPE_PEN_TILT_VIEW_3 = 3,
	TUNING_CTRL_TYPE_PEN_TILT_VIEW_4 = 4,

	TUNING_CTRL_TYPE_PEN_TILT_VIEW_LIMIT = 255,

} eTuningCtrlPenTiltViewType_t;

typedef enum
{
	TUNING_CTRL_TYPE_PEN_DATA_VIEW_All = 0,
	TUNING_CTRL_TYPE_PEN_DATA_VIEW_1 = 1,
	TUNING_CTRL_TYPE_PEN_DATA_VIEW_2 = 2,
	TUNING_CTRL_TYPE_PEN_DATA_VIEW_3 = 3,
	TUNING_CTRL_TYPE_PEN_DATA_VIEW_4 = 4,

	TUNING_CTRL_TYPE_PEN_DATA_VIEW_LIMIT = 255,

} eTuningCtrlPenDataViewType_t;

typedef enum
{
	TUNING_CTRL_TYPE_LOCAL_MODE = 0,
	TUNING_CTRL_TYPE_FULL_MODE = 1,

} eTuningCtrlLocalFullModeType_t;

typedef struct
{
	__IO eTuningCtrlLocalFullModeType_t eTuningOperMode;

	__IO bool_t bSRIC_INIT;

	__IO int32_t ulCR_OFFSET;

	__IO eTuningCtrlType_t ulTuning_Ctrl_Type;

	__IO uint32_t ulAverageCheck_Count_THD;
	__IO uint32_t ulAverageCheck_Count;
	__IO bool_t ulAverageCheck_Complete;

	__IO uint32_t ulGIPCheck_Average_Count_THD;
	__IO uint32_t ulGIPCheck_Average_Count;
	__IO uint32_t ulGIPCheck_VSync_TouchSync_Timing_Sweep_Start_IDX;
	__IO uint32_t ulGIPCheck_VSync_TouchSync_Timing_Sweep_IDX;
	__IO uint32_t ulGIPCheck_Start;
	__IO uint32_t ulGIPCheck_Complete;
	__IO uint32_t ulGIPCheck_AllComplete;

	__IO uint32_t ulJitterCheck_Count_THD;
	__IO uint32_t ulJitterCheck_Count;
	__IO bool_t bJitterCheck_Complete;

	__IO uint32_t ulLocalDeltaJitterCheck_Count_THD;
	__IO uint32_t ulLocalDeltaJitterCheck_Count;
	__IO bool_t bLocalDeltaJitterCheck_Complete;

	__IO eTuningCtrlPenPosViewType_t ulTuning_Ctrl_PenPosViewType;
	__IO eTuningCtrlPenTiltViewType_t ulTuning_Ctrl_PenTiltViewType;
	__IO eTuningCtrlPenDataViewType_t ulTuning_Ctrl_PenDataViewType;

} tTuningProcess_Ctrl_Info_t;

typedef struct
{
	__IO uint32_t ulVSync_TouchSync_Timing_Index;
	__IO uint32_t ulVsync_and_Touch_Timing_Continuos_CheckCount;
	__IO uint32_t ulVsync_and_Touch_Timing_Continuos_Count;
	__IO int32_t ulGIPNoiseRowIndex_CheckBuf[LHB_NUM][ROW_MAX];

	__IO uint8_t ulFingerMuxOrderMappingByLHB[LHB_NUM][FINGER_MUX_NUM];

} tTuningProcess_Ctrl_RawTune_t;

extern __IO tTuningProcess_Ctrl_Info_t gtTuning_Ctrl_Type;
extern __IO tTuningProcess_Ctrl_RawTune_t gtuning_ctrl_RawTune_Type;

#endif /* _APP_TUNING_PROCESS_H_ */
