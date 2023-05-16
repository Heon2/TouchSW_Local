/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_types.h
 * created on : 14. 5. 2019
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

#ifndef _APP_TYPES_H_
#define _APP_TYPES_H_


typedef enum
{
	TOUCH_MAIN_OPERATION_ENTER = 0,
	TOUCH_MAIN_OPERATION_NORMAL,
	TOUCH_MAIN_OPERATION_DIAG,
	TOUCH_MAIN_OPERATION_DFUP,
	TOUCH_MAIN_OPERATION_RESET,
	TOUCH_MAIN_OPERATION_EXIT,
	TOUCH_MAIN_OPERATION_TUNING_PROCESS = 0xFF,

} eTouchOperMainState_t;

typedef enum
{
	TOUCH_NORMAL_OPER_NONCHANGE = 0,
	TOUCH_NORMAL_OPER_ENTER,
#if USED_SMT_OP_MODE
	TOUCH_NORMAL_SMT_MODE,
#endif /* USED_SMT_OP_MODE */
	TOUCH_NORMAL_OPER_RESET_SYSTEM,
	TOUCH_NORMAL_OPER_RESET_HAL,
	TOUCH_NORMAL_OPER_RESET_MODULE,

	TOUCH_NORMAL_OPER_RESET_REFERENCE,
	TOUCH_NORMAL_OPER_RESET_REFERENCE_IDLE,
	TOUCH_NORMAL_OPER_RESET_REFERENCE_FREQ1,
	TOUCH_NORMAL_OPER_RESET_REFERENCE_S3,

	TOUCH_NORMAL_OPER_READY_REFERENCE_PEN,
	TOUCH_NORMAL_OPER_RESET_REFERENCE_PEN,

	TOUCH_NORMAL_OPER_READY_REFERENCE_PEN_IDLE,
	TOUCH_NORMAL_OPER_RESET_REFERENCE_PEN_IDLE,

	TOUCH_NORMAL_OPER_NORMAL_READY,
	TOUCH_NORMAL_OPER_NORMAL,

	TOUCH_NORMAL_OPER_IDLE_READY,
	TOUCH_NORMAL_OPER_IDLE,

	TOUCH_NORMAL_OPER_S3_READY,
	TOUCH_NORMAL_OPER_S3,

	TOUCH_NORMAL_OPER_SWITCH_FREQ,
	TOUCH_NORMAL_OPER_LOCAL_SWITCH_FREQ,
//	TOUCH_NORMAL_OPER_NORMAL_FREQ1_READY,
//	TOUCH_NORMAL_OPER_NORMAL_FREQ1,

	TOUCH_NORMAL_OPER_LOCAL_READY,
	TOUCH_NORMAL_OPER_LOCAL,

	TOUCH_NORMAL_OPER_LOCAL_IDLE_READY,
	TOUCH_NORMAL_OPER_LOCAL_IDLE,

#if USED_RAWDATA_TUNE_CALIBRATION
	TOUCH_NORMAL_OPER_NORMAL_RAWDATA_CALIBRATION,
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
	TOUCH_NORMAL_OPER_EXIT,
} eNormalOperSubState_t;

typedef enum
{
	TOUCH_NOISE_OPER_ENTER = 0,
	TOUCH_NOISE_OPER_RESET_SYSTEM,
	TOUCH_NOISE_OPER_RESET_HAL,
	TOUCH_NOISE_OPER_RESET_MODULE,
	TOUCH_NOISE_OPER_WAIT_FOR_MODULE_START,
	TOUCH_NOISE_OPER_RESET_REFERENCE,
	TOUCH_NOISE_OPER_NORMAL,
	TOUCH_NOISE_OPER_EXIT,
} eNoiseOperSubState_t;

typedef enum
{
	TOUCH_LPWG_OPER_NONCHANGE = 0,
	TOUCH_LPWG_OPER_ENTER,
	TOUCH_LPWG_OPER_RESET_SYSTEM,
	TOUCH_LPWG_OPER_RESET_HAL,
	TOUCH_LPWG_OPER_RESET_MODULE,
	TOUCH_LPWG_OPER_RESET_REFERENCE,
	TOUCH_LPWG_OPER_NORMAL_READY,
	TOUCH_LPWG_OPER_NORMAL,
	TOUCH_LPWG_OPER_EXIT,
} eLpwgOperSubState_t;

typedef enum
{
	TOUCH_DFUP_OPER_ENTER = 0,
	TOUCH_DFUP_OPER_INITIALISE,
	TOUCH_DFUP_OPER_RESET_REFERENCE,
	TOUCH_DFUP_OPER_NORMAL,
	TOUCH_DFUP_OPER_EXIT,
} eDfupOperSubState_t;

typedef enum
{
	TOUCH_DIAG_OPER_ENTER = 0,
	TOUCH_DIAG_OPER_INITIALISE,
	TOUCH_DIAG_OPER_RESET_REFERENCE,
	TOUCH_DIAG_OPER_NORMAL,
	TOUCH_DIAG_OPER_WAIT,
	TOUCH_DIAG_OPER_EXIT,
} eDiagOperSubState_t;


#endif /* _APP_TYPES_H_ */
