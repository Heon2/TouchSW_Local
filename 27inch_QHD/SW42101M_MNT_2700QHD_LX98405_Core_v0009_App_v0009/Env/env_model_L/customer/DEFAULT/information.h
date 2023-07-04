/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  information.h
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

#ifndef _INFORMATION_H_
#define _INFORMATION_H_


/********************************************************************************
 *                              Customer : DEFAULT                              *
 ********************************************************************************/
#define CORE_VERSION				(0x0009)
#define APP_VERSION					(0x0009)
#define PARA_VERSION				(0x0000)
#define I2C_ADDRESS					(0x28)		// (LG : 0x34, Lenovo : 0x20)
#define HID_DESCRIPTOR_ADDRESS		(0x0020)	// (LG ��Ʈ�� 0x0000, Lenovo ��Ʈ�� 0x0020)
#define UNIQUE_APP_PID 				(0xD101)	// (LGD 27.0" MNT)

#if USED_MOBILE_I2C_PROTOCOL
#define I2C_X_RESOLUTION			(1920)
#define I2C_Y_RESOLUTION			(1080)

#else /* USED_MOBILE_I2C_PROTOCOL */
#define I2C_X_RESOLUTION			(32768)
#define I2C_Y_RESOLUTION			(32768)
#endif /* USED_MOBILE_I2C_PROTOCOL */

#define MODE_WDT				// WDT Mode Apply

#if !defined(USE_BOOTLOADER_CODE)
//#define DC_BASE
#if USED_FINGER_ONLY
#define FINGER_ONLY
#endif /* USED_FINGER_ONLY */
//#define MODE_I2C
#define ADD_TOUCH
//#define ADD_PEN
#endif /* USE_BOOTLOADER_CODE */

#define ADD_CUSTOM
#define USB_SELECTIVE_SUSPEND
//#define I2C_SELECTIVE_SUSPEND

#define ABNORMAL_RAWDATA_CNT_THD					(10)
#define ABNORMAL_RAWDATA_FRAME_THD					(5)
#define USED_ESD_RECOVERY_CODE						(NO)

#define DEBOUNCE_FRAME_NUM							(10)
#define ABNORMAL_DELTA_PLUS_THD					    (300)
#define ABNORMAL_DELTA_PLUS_CNT_THD					(3)
#define ABNORMAL_DELTA_MINUS_THD				    (-30)
#define ABNORMAL_DELTA_FRAME_THD       			    (100)
#define ABNORMAL_DELTA_THD_FOR_RECAL				(20)
#define ABNORMAL_DELTA_CHECK_FRAME_NUM				(2)
#define USED_RF_NOISE_RECOVERY_CODE					(NO)

#define ABNORMAL_TSYNC_FALLING_TIME_CHECK		(YES)

#define USED_SPLIT_MERGE_RELIABILITY 				(NO)
#define USED_DRUM_ALGO 								(NO)
#define VECTOR_PREDICTION_EN						(NO)
#define FAST_SPLIT									(NO)
#define BIG_FINGER_EDGE_EXPAND_ALGO_EN				(NO)
#define WinCertAssistance_En						(NO)
#define ADAPTIVE_SEEDBASE							(NO)
#define LABEL_FAST_EN								(NO)
#define SMOOTH_PASTORG_INTER_EN						(NO)
#define USED_ALGORITHM_FOR_MNT						(NO)
#define MULTI_EDGE_COEF_EN							(NO)
#define BIG_FINGER_EDGE_ACC_TEST_ALGO_EN 			(NO)
#define USED_DO_NOT_FINGER_TOUCH_REPORT				(NO)
#define PEN_FINGER_1TOUCH_REPORT					(NO)
#define FINGER_LF_VER1_EN							(NO)
#define FINGER_LF_VER2_EN							(NO)
#define FINGER_LF_VER4_EN							(NO)
#define PalmCandidateTouchCut_EN					(NO)
#define PalmDrawingOn_En							(NO)
#define USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE		(NO)
#define FINGER_Latency_Test_ByFW					(NO)
#define CPI_TEST_EN									(NO)
#define PHONE_NOISE_CNT_MAX							(5)
#define PHONE_NOISE_RESET_CNT_MAX					(300)
#define NORMALIZE_DELTA_EN							(YES)
#define ID_MAPPING_CHANGE							(NO)
#define REMOVE_EDGE_EN								(NO)
#define FAST_LF_EN									(NO)
#define USED_NOISE_HOPPING_FREQ						(NO)
#define PALM_VER1_EN								(NO)
#define FingerGlobalCoordiY_2Region_Set				(NO)
#endif /* _INFORMATION_H_ */
