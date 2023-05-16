/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : hal_types.h
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

#ifndef _HAL_TYPES_H_
#define _HAL_TYPES_H_


typedef enum
{
	/*
	 * Sub Sensing Mode
	 */
	SM_CHECK_ACTIVE = 0x1,
	SM_CHECK_ACTIVE_FRQ_MAIN = 0x2, // Main Frequency
	SM_CHECK_ACTIVE_FRQ_HOP1 = 0x4, // Hopping 1 Frequency
	SM_CHECK_ACTIVE_FRQ_HOP2 = 0x8, // Hopping 2 Frequency
	SM_CHECK_IDLE = 0x100,

	/*
	 * Main Sensing Mode
	 */
	SM_CHECK_S3_MODE = 0x800,
	SM_S3_ACTIVE_MODE = (SM_CHECK_ACTIVE | SM_CHECK_S3_MODE),
	SM_S3_IDLE_MODE = (SM_CHECK_IDLE | SM_CHECK_S3_MODE),

	SM_CHECK_FINGER_ONLY_MODE = 0x1000,
	SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE = (SM_CHECK_ACTIVE | SM_CHECK_ACTIVE_FRQ_MAIN | SM_CHECK_FINGER_ONLY_MODE),
	SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE = (SM_CHECK_ACTIVE | SM_CHECK_ACTIVE_FRQ_HOP1 | SM_CHECK_FINGER_ONLY_MODE),
	SM_FINGER_ONLY_ACTIVE_FRQ_HOP2_MODE = (SM_CHECK_ACTIVE | SM_CHECK_ACTIVE_FRQ_HOP2 | SM_CHECK_FINGER_ONLY_MODE),
	SM_FINGER_ONLY_IDLE_MODE = (SM_CHECK_IDLE | SM_CHECK_FINGER_ONLY_MODE),

	SM_CHECK_FINGER_PEN_SEARCH_MODE = 0x2000,
	SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_MAIN_MODE = (SM_CHECK_ACTIVE | SM_CHECK_ACTIVE_FRQ_MAIN | SM_CHECK_FINGER_PEN_SEARCH_MODE),
	SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_HOP1_MODE = (SM_CHECK_ACTIVE | SM_CHECK_ACTIVE_FRQ_HOP1 | SM_CHECK_FINGER_PEN_SEARCH_MODE),
	SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_HOP2_MODE = (SM_CHECK_ACTIVE | SM_CHECK_ACTIVE_FRQ_HOP2 | SM_CHECK_FINGER_PEN_SEARCH_MODE),

	SM_CHECK_FINGER_PEN_MODE = 0x4000,
	SM_FINGER_PEN_ACTIVE_MODE = (SM_CHECK_ACTIVE | SM_CHECK_FINGER_PEN_MODE),
	SM_FINGER_PEN_IDLE_MODE = (SM_CHECK_IDLE | SM_CHECK_FINGER_PEN_MODE),

	SM_SENSING_MODE_LIMIT = 0xFFFF

} eSENSING_MODE_t;

typedef enum
{
	SM_CHANGE_COMPLETE,
	SM_CHANGE_IDLE_MODE,
	SM_CHANGE_ACTIVE_MODE,
	SM_CHANGE_ACTIVE_FRQ_MAIN_MODE,
	SM_CHANGE_ACTIVE_FRQ_HOP1_MODE,
	SM_CHANGE_ACTIVE_FRQ_HOP2_MODE,
//	SM_CHANGE_S3_MODE,
	SM_CHANGE_FINGER_ONLY_MODE,
	SM_CHANGE_FINGER_PEN_SEARCH_MODE,
	SM_CHANGE_FINGER_PEN_MODE,

	/*
	 * ROIC Reg Change
	 */
	SM_CHANGE_DIAG_TEST,
	SM_CHANGE_ROIC_REG_VAL,

	SM_CHANGE_SENSING_MODE_LIMIT = 0xFF

} eSENSING_CHANGE_MODE_t;

#define IS_S3_MODE(m)						(m & SM_CHECK_S3_MODE)					/* All Mode */
#define IS_FINGER_ONLY_MODE(m)				(m & SM_CHECK_FINGER_ONLY_MODE)			/* All Mode */
#define IS_FINGER_PEN_SEARCH_MODE(m)		(m & SM_CHECK_FINGER_PEN_SEARCH_MODE)	/* All Mode */
#define IS_FINGER_PEN_MODE(m)				(m & SM_CHECK_FINGER_PEN_MODE)			/* Partial Mode */

#define IS_ACTIVE_MODE(m)					(m & SM_CHECK_ACTIVE)
#define IS_ACTIVE_MODE_FRQ_MAIN(m)			(m & SM_CHECK_ACTIVE_FRQ_MAIN)
#define IS_ACTIVE_MODE_FRQ_HOP1(m)			(m & SM_CHECK_ACTIVE_FRQ_HOP1)
#define IS_ACTIVE_MODE_FRQ_HOP2(m)			(m & SM_CHECK_ACTIVE_FRQ_HOP2)
#define IS_IDLE_MODE(m)						(m & SM_CHECK_IDLE)

/*
 * Finger Scan Mux Index Define
 */
#define FINGER_SCAN_MUX_1		(0)
#define FINGER_SCAN_MUX_2		(1)
#define FINGER_SCAN_MUX_3		(2)
#define FINGER_SCAN_MUX_4		(3)
#define FINGER_SCAN_MUX_5		(4)
#define FINGER_SCAN_MUX_6		(5)
#define FINGER_SCAN_MUX_7		(6)
#define FINGER_SCAN_MUX_8		(7)
#define FINGER_SCAN_MUX_9		(8)
#define FINGER_SCAN_MUX_10		(9)
#define FINGER_SCAN_MUX_11		(10)
#define FINGER_SCAN_MUX_12		(11)
#define DONOT_SCAN				(0)

typedef enum
{
	MSPI_OP_MODE_EVERY_MUX,
	MSPI_OP_MODE_EVERY_FRAME,

} eMSPIOperationMode_t;

typedef enum
{
	BASELINE_TYPE_FULL,
	BASELINE_TYPE_NI

} eBaseImageType_t;

typedef enum
{
	DIAG_CHANGE_OPEN_TEST_STEP1,
	DIAG_CHANGE_OPEN_TEST_STEP2,
	DIAG_CHANGE_OPEN_TEST_STEP3,
	DIAG_CHANGE_OPEN_TEST_STEP4,
	DIAG_CHANGE_OPEN_TEST_STEP5,
	DIAG_CHANGE_OPEN_TEST_STEP6,
	DIAG_CHANGE_OPEN_TEST_STEP7,
	DIAG_CHANGE_OPEN_TEST_STEP8,
	DIAG_CHANGE_OPEN_TEST_STEP9,
	DIAG_CHANGE_OPEN_TEST_RECOVERY,
	DIAG_CHANGE_SHORT1_TEST_STEP1,
	DIAG_CHANGE_SHORT1_TEST_STEP2,
	DIAG_CHANGE_SHORT1_TEST_STEP3,
	DIAG_CHANGE_SHORT1_TEST_STEP4,
	DIAG_CHANGE_SHORT1_TEST_STEP5,
	DIAG_CHANGE_SHORT1_TEST_STEP6,
	DIAG_CHANGE_SHORT1_TEST_STEP7,
	DIAG_CHANGE_SHORT1_TEST_STEP8,
	DIAG_CHANGE_SHORT1_TEST_STEP9,
	DIAG_CHANGE_SHORT1_TEST_STEP10,
	DIAG_CHANGE_SHORT1_TEST_STEP11,
	DIAG_CHANGE_SHORT1_TEST_STEP12,
	DIAG_CHANGE_SHORT1_TEST_RECOVERY,
	DIAG_CHANGE_SHORT2_TEST_STEP1,
	DIAG_CHANGE_SHORT2_TEST_STEP2,
	DIAG_CHANGE_SHORT2_TEST_STEP3,
	DIAG_CHANGE_SHORT2_TEST_STEP4,
	DIAG_CHANGE_SHORT2_TEST_STEP5,
	DIAG_CHANGE_SHORT2_TEST_STEP6,
	DIAG_CHANGE_SHORT2_TEST_STEP7,
	DIAG_CHANGE_SHORT2_TEST_STEP8,
	DIAG_CHANGE_SHORT2_TEST_RECOVERY,
//	DIAG_CHANGE_SHORT2_TEST_GET_NORMAL,

	DIAG_CHANGE_SENSING_MODE_LIMIT = 0xFF

} eDIAG_TEST_CHANGE_MODE_t;

typedef enum {
	ACTIVEPEN_TYPE_LOCAL_MS = 0,
	ACTIVEPEN_TYPE_LOCAL_WACOM = 1,
	ACTIVEPEN_TYPE_LOCAL_WGP = 2,
	// Add here~~
	ACTIVEPEN_TYPE_NUM,
	ACTIVEPEN_TYPE_MAX = 0xFF,

} eActivePenType_t;


typedef enum {
	ACTIVEPEN_CHANGE_LOCAL_MS = 0,
	ACTIVEPEN_CHANGE_LOCAL_WACOM = 1,
	ACTIVEPEN_CHANGE_LOCAL_WGP = 2,
	ACTIVEPEN_CHANGE_DONE,
	ACTIVEPEN_CHANGE_MAX = 0xFF,

} eActivePenChangeType_t;

typedef enum
{
	ROIC_REG_SET_CHANGE_MUX_REMAP,
	ROIC_REG_SET_CHAGNE_CR_TUNE,
	ROIC_REG_SET_CHAGNE_LOCAL_CR_TUNE,

	ROIC_REG_SET_CHAGNE_WacomPen_Local_Setting,
	ROIC_REG_SET_CHAGNE_WacomPen_Full_Setting,
	ROIC_REG_SET_CHAGNE_WGPPen_Local_Setting,
	ROIC_REG_SET_CHAGNE_WGPPen_Full_Setting,
	ROIC_REG_SET_CHAGNE_MSPen_Local_Setting,
	ROIC_REG_SET_CHAGNE_MSPen_Full_Setting,

	ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_ACTIVE,
	ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_IDLE,
	ROIC_REG_SET_CHANGE_FINGER_PEN_FULL,
	ROIC_REG_SET_CHANGE_FINGER_PEN_FULL_IDLE,

#if USED_NOISE_HOPPING_FREQ
	ROIC_REG_SET_CHANGE_FREQ_MAIN_FINGER_PEN_FULL,
	ROIC_REG_SET_CHANGE_FREQ_HOPP1_FINGER_PEN_FULL,
#endif

	ROIC_REG_SET_CHANGE_LIMIT = 0xFF,

} eROIC_REG_SET_CHANGE_MODE_t;

#if USED_MNT_S3_MODE_FUNCTION
typedef enum
{
	TSYNC_OUT_STATUS_NONE,
	TSYNC_OUT_STATUS_RISING,
	TSYNC_OUT_STATUS_FALLING,

} eTSYNC_OUT_INTR_STATUS_t;
#endif /* USED_MNT_S3_MODE_FUNCTION */

typedef struct
{
	/*
	 * MSPI
	 */
	__IO uint32_t ulMSPIPenModeIntrCnt;
	__IO uint32_t ulMSPIDone;
	__IO uint32_t ulLocalIndexChangeStart;
	__IO uint32_t ulLocalSensingDoneRowIdx;
	__IO uint32_t ulLocalSensingDoneRowIdx_Tilt;
	__IO ePartialSensing_t eLocalSensingType;

	/*
	 * PWM
	 */
	__IO uint32_t ulVSyncFlag;
	__IO uint32_t ulTSyncInFallingCnt;
	__IO uint32_t ulTSyncInRisingCnt;
#if USED_PWM_PULSE_END_FLAG_CHECK
	__IO uint32_t ulPWM_Pulse_End_Flag;
#endif /* USED_PWM_PULSE_END_FLAG_CHECK */

	/*
	 * Timer
	 */

	/*
	 * GPIO
	 */

	/*
	 * Frame
	 */
	__IO uint32_t ulInitFirstFrame;

	/*
	 * USB
	 */
	__IO bool_t ulUSBSendData_TimerTick;

} tHalInterruptHandle_t;



#endif /* _HAL_TYPES_H_ */
