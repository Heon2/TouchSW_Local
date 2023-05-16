/******************************************************************************************************
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
#define USED_TRIMCODE_UPDATE_SECURITY_FUNC				(NO)
 
#define USED_ROIC_DEF									(ROIC_SW98500)

#define SHARP_NBPC_PIN_TYPE_S00							(1)
#define SHARP_NBPC_PIN_TYPE_S01							(2)

#define USED_PCB_PINMAP									(SHARP_NBPC_PIN_TYPE_S01)

#define USED_BEACON_SET_ADJUST							(YES)

/*
 * Support Pen Protocol
 */
//#define PEN_PROTOCOL_MS_PEN
//#define PEN_PROTOCOL_WACOM_PEN
//#define PEN_PROTOCOL_MSnWACOM_PEN
//#define PEN_PROTOCOL_WGP_PEN
//#define PEN_PROTOCOL_MSnWGP_PEN
//#define PEN_PROTOCOL_WGP_UHD_PEN
#define USED_PEN_PROTOCOL								(PEN_PROTOCOL_WGP_UHD_PEN)
#define USED_WGP_AGIC_PEN								(YES)

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	#define DEF_PEN_LOCAL_INDEX_SET_BIT_MASK_MSPen				(0x0150)
	#define DEF_PEN_LOCAL_INDEX_SET_BIT_MASK_AITPen				(0x0288)
	#define DEF_PEN_LOCAL_INDEX_SET_BIT_MASK_WGPPen				(0x0444)
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
		#if USED_ROIC_DEF == ROIC_SW92510
			#define DEF_PEN_LOCAL_INDEX_SET_BIT_MASK_Active		(0x0647)
			#define DEF_PEN_LOCAL_INDEX_SET_BIT_MASK_Idle		(0x0048)
		#else
			#define DEF_PEN_LOCAL_INDEX_SET_BIT_MASK_Active		(0x0445)
			#define DEF_PEN_LOCAL_INDEX_SET_BIT_MASK_Idle		(0x0048)
		#endif
	#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
		#define DEF_PEN_LOCAL_INDEX_SET_BIT_MASK_Active			(0x0054)
		#define DEF_PEN_LOCAL_INDEX_SET_BIT_MASK_Idle			(0x0054)
	#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
		#define DEF_PEN_LOCAL_INDEX_SET_BIT_MASK_Active			(0x0151)
		#define DEF_PEN_LOCAL_INDEX_SET_BIT_MASK_Idle			(0x0048)
	#endif
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */

#define USED_SPI_NBIT_TRANSMODE							(YES)
#define SPI_TRANSFER_BIT_NUM							(11)

#define USED_TOUCH_TUNING_PROCESS						(NO)
#if USED_TOUCH_TUNING_PROCESS
#define FINGER_LF_VER1_EN								(YES)
#endif
#define USED_DO_NOT_TOUCH_ONLY_DISPLAY					(NO)
#define USED_DO_NOT_TOUCH_REPORT						(NO)
#define USED_DO_NOT_FINGER_TOUCH_REPORT					(NO)
#define USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS		(NO)
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
#define ZERO_FINGER_RAWDATA_MASK_NUM					(32)
#define ZERO_FINGER_RAWDATA_MASK_COL_NUM				(3) // (ROW MAX / 32) + ((ROW_MAX % 32) > 0 ? 1 : 0)
#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
#define USED_FINGER_DYNAMIC_MUX_SCAN_ORDER				(NO)
#define USED_PEN_DATA_AFE_GAIN_OTHER_SET				(NO)
#if USED_PEN_DATA_AFE_GAIN_OTHER_SET
	#define DEF_PEN_LOCAL_DATA_GAIN_SET_BIT_MASK_Idle			(0x0829)
#endif /* USED_PEN_DATA_AFE_GAIN_OTHER_SET */

#define USED_ONLY_LOCAL_MODE							(YES)
#define USED_ONLY_FULL_MODE								(NO)
#define USED_ONLY_IDLE_MODE								(NO)
#define USED_ONLY_LOCAL_IDLE_MODE						(NO)
#define USED_ONLY_S3_MODE								(NO)
#define USED_IDLE_FINGER_EVEN_ODD						(NO)

#define USED_SMT_OP_MODE								(NO)
#define USED_IDLE_MODE_CONTROL							(NO)
#define USED_IDLE_NI_SENSING_MUX_NUM					(2)
#define USED_REFERENCE_INIT_IDLE_MODE_ENTER				(YES & USED_IDLE_MODE_CONTROL)
#define USED_LOCAL_IDLE_MODE_CONTROL					(NO)
#define USED_LOCAL_IDLE_PEN_OTHER_CONTROL				(NO && USED_LOCAL_IDLE_MODE_CONTROL)

#define USED_NOISE_HOPPING_FREQ								(NO)
#define USE_FREQ_HOPPIG_DEBUG								(NO && USED_NOISE_HOPPING_FREQ)
#define USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE				(YES && USED_NOISE_HOPPING_FREQ)
#define HOPP_BASELINE_CONTI_ON_OFF_CONTROL_START_CNT_THD	(20)
#define DEF_FREQ_HOPPING_BASELINE_UPDATE_CHECK_CNT_THD		(100)
#define DEF_FREQ_HOPPING_BASELINE_UPDATE_CONTI_CNT_THD		(10)

#define USED_START_TIME_OUT_CHECK						(YES)
#define USED_START_TIME_OUT_COUNT						(100)

#define USED_TSYNC2_INPUT_FROM_TCON						(NO)

#define USED_TPIC_MUXEN_ON_OFF_CONTROL					(YES)
#define USED_TPIC_MUXEN_2_ON_OFF_CONTROL				(NO)
#define USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM				(YES)
#define TPIC_MUXEN_ON_OFF_CONTROL_START_CNT_THD			(20)
#define USED_TPIC_MUXEN_ON_OFF_CONTROL_DISABLE_DATAREAD	(YES & USED_TPIC_MUXEN_ON_OFF_CONTROL)

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	#define DEF_TPIC_MUX_EN_SET_BIT_MASK_MSPen				(0x0000)
	#define DEF_TPIC_MUX_EN_SET_BIT_MASK_WGPPen				(0x0000)
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
		#if USED_ROIC_DEF == ROIC_SW92510 // Finger Only
			#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Full		(0x03BD)
			#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Local		(0x03BD)
			#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Idle		(0x0001)
		#else // WGP Pen
			#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Full		(0xC1C3)
			#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Local		(0xFFE7)
			#if USED_LOCAL_IDLE_30Hz
				#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Idle		(0x18002)
			#else
				#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Idle		(0x8003)
			#endif
		#endif
	#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
		#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Full		(0x0057)
		#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Local		(0x00FF)
		#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Idle		(0x0000)
	#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
		#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Full		(0x7FF7)
		#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Local		(0xE6FF)
		#define DEF_TPIC_MUX_EN_SET_BIT_MASK_Idle		(0x0000)
	#endif
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */

#define USED_GPIO_UPLINK_LEVEL_CONTROL					(NO)
#if USED_GPIO_UPLINK_LEVEL_CONTROL
	#define DEF_UPLINK_HW_CONTROL							(1)
	#define DEF_UPLINK_SW_CONTROL							(2)
	#define DEF_UPLINK_CONTROL_OPERATION					(DEF_UPLINK_SW_CONTROL)
#endif /* USED_GPIO_UPLINK_LEVEL_CONTROL */

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	#define DEF_UPLINK_CTRL_SET_BIT_MASK_MSPen				(0x0202)
	#define DEF_UPLINK_CTRL_SET_BIT_MASK_WGPPen				(0x0002)
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
		#define DEF_UPLINK_CTRL_SET_BIT_MASK_WGPPen		(0x0002)
	#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
		#define DEF_UPLINK_CTRL_SET_BIT_MASK_MSPen		(0x0202)
	#endif
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */

#define USED_TPIC_PENEN_ON_OFF_CONTROL					(NO)
#define USED_TPIC_PENEN_OFF_TIMING_LAST_PWM				(YES)
#define TPIC_PENEN_ON_OFF_CONTROL_START_CNT_THD			(20)
#define USED_TPIC_PENEN_ON_OFF_CONTROL_DISABLE_DATAREAD	(YES & USED_TPIC_MUXEN_ON_OFF_CONTROL)

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	#define DEF_TPIC_PEN_EN_SET_BIT_MASK_MSPen				(0x0000)
	#define DEF_TPIC_PEN_EN_SET_BIT_MASK_AITPen				(0x0000)
	#define DEF_TPIC_PEN_EN_SET_BIT_MASK_WGPPen				(0x0000)
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
		#if USED_ROIC_DEF == ROIC_SW92510
			#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Full		(0x0647)
			#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Local		(0xE5E7)
			#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Idle		(0x0048)
		#else
			#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Full		(0x0647)
			#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Local		(0xE5E7)
			#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Idle		(0x0048)
		#endif
	#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
		#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Full		(0x0000)
		#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Local		(0x0000)
		#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Idle		(0x0000)
	#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
		#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Full		(0x0000)
		#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Local		(0x0000)
		#define DEF_TPIC_PEN_EN_SET_BIT_MASK_Idle		(0x0000)
	#endif
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN) */

#define USED_ROIC_REGISTER_READ_WRITE_CHECK				(NO)
#define ECLK_ACTIVE_ECLK_DRIVING_STRENGTH						(GPIO_DRIVE_STR_4mA)
#define USED_ECLK_ON_OFF_CONTROL						(NO)
#define ECLK_ON_OFF_CONTROL_START_CNT_THD				(20)
#define USED_ECLK_FRQ_ADJUST_CONTROL					(YES & USED_ECLK_ON_OFF_CONTROL)
#define ECLK_FRQ_ADJUST_DISPLAY_DIV						(3)
#define USED_ECLK_ON_OFF_CONTROL_DISABLE_DATAREAD		(YES & USED_ECLK_ON_OFF_CONTROL)
#define ECLK_NEED_DURING_MSPI_OPERATION					(NO & USED_ECLK_ON_OFF_CONTROL)

#define USED_TOUCH_REPORT_ON_OFF_CONTROL					(YES)
#define TOUCH_REPORT_ON_OFF_CONTROL_START_CNT_THD			(20)
#define USED_TOUCH_REPORT_ON_OFF_CONTROL_DISABLE_DATAREAD	(YES & USED_TOUCH_REPORT_ON_OFF_CONTROL)

#define USED_FORCE_S3_MODE_OPER							(NO)
#define USED_GPIO_TEST_HANDSHAKE						(NO)

#define PWMDRV_USED_FREQUENCY						(PWMDRV_FREQUENCY_114K)
#define PLL_OUT_CLOCK_SPEED							(PLL_OUT_CLOCK_90MHz)

#define USED_OPERATION_STAND_ALONE					(NO)
#define USED_OPERATION_STAND_ALONE_DISPLAY_ON		(NO)

#define USED_SHARP_SPECIFIC_PROTOCOL				(NO)

#define USED_PEN_MODE_OPERATION						(YES)
#define USED_INIT_PEN_MODE							(YES && USED_PEN_MODE_OPERATION)
#define USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL			(NO && USED_PEN_MODE_OPERATION)
#define USED_PEN_ID_GET_FUNCTION					(NO && USED_PEN_MODE_OPERATION)

#define USED_S3_MODE_FUNCTION						(NO && (!USED_PEN_MODE_OPERATION))
#define USED_LPWG_MCU_SLEEP							(NO && (!USED_PEN_MODE_OPERATION))
#define USED_S3_ALL_MUX_SHORT						(NO)

#define USED_PWM_GATE_CONTROL						(NO)
#define USED_TP_RST_OPERATION						(NO)
#define USED_TP_LCD_ON_OPERATION					(YES && (USED_OPERATION_STAND_ALONE == NO))
#define USED_TP_RSTnLCDON_DOUBLE_OPERATION			(USED_TP_RST_OPERATION && USED_TP_LCD_ON_OPERATION)

#define USED_I2C_STOP_STATE_CHECK					(YES)

/*******************************************************************
 * Custom Specific Define
 *******************************************************************/
#define USED_TOUCH_WGP_PREDRV_MUX_SENSING				(YES)/*Pend Data*/

#define USED_MODULATION_5V_DRIVING						(NO)

#define USED_RAWDATA_TUNE_CALIBRATION					(NO)
#if USED_RAWDATA_TUNE_CALIBRATION
	#define DEF_RAWDATA_TUNE_TYPE_AUTO						(1)
	#define DEF_RAWDATA_TUNE_TYPE_MANUAL					(2)
	#define RAWDATA_TUNE_CALIBRATION_TYPE					(DEF_RAWDATA_TUNE_TYPE_AUTO)
	#define RAWDATA_TUNE_RO_R1_SWAP							(YES)
	#if (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO)
		#define RAWDATA_TUNE_AUTO_CALIBRATION_TARGET_VAL		(1900)
	#endif /* (RAWDATA_TUNE_CALIBRATION_TYPE == DEF_RAWDATA_TUNE_TYPE_AUTO) */
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#define USED_ROIC_AFE_LP_OPTION							(YES)
#define USED_ECLK_1WAY_CONNECTION						(NO)
#define USED_Souryu_Board								(NO)

/*******************************************************************
 * MSB 8bit is Binary Type
 *******************************************************************/
#if 0
	#define APP_VERSION									(0xFF0B)
#else
	#define APP_VERSION									(0x0005)
#endif
#define CONFIG_VERSION								(0x0001)
#define I2C_ADDRESS									(0x09)
#define HID_DESCRIPTOR_ADDRESS						(0x0020)
#define UNIQUE_APP_PID 								(0x3301)

#define I2C_X_RESOLUTION							(32768)
#define I2C_Y_RESOLUTION							(32768)

// 13.3"
// X, Y Physical Maximum
#define X_PHYSICAL_MAX								(28800)	// (28.800 cm)
#define Y_PHYSICAL_MAX								(18000)	// (18.000 cm)

//#define MODE_WDT				// WDT Mode Apply

//#define DC_BASE
//#define MODE_I2C

/* The Pen Intensity and Rawdata is broken when viewing using a tool.
 * The Intensity and RawData is 2-Bytes, but I2C communication is 1-byte.
 * Pen data and I2C Logging is async.
 * If the data is updated immediately after sending the MSB using the I2C.
 * LSB Data is sending update data. So, tool Is display Broken data
 * If this define is applied, I2C is processed by 2bytes  */
#define USED_I2C_READ_DATA_UNIT_2BYTE		(YES & USED_PEN_MODE_OPERATION)

#define ADD_TOUCH
#if USED_PEN_MODE_OPERATION
	#define ADD_PEN
#endif /* USED_PEN_MODE_OPERATION */

#define ADD_CUSTOM
#define USB_SELECTIVE_SUSPEND
//#define I2C_SELECTIVE_SUSPEND

/*******************************************************************************************
 *                       Algorithm Setting
 *******************************************************************************************/
#if USED_PEN_MODE_OPERATION
#define TILT_ON 1		    			//Tilt Enable : PARTIAL_PEN_COORD2 Ring scan

#ifdef TILT_ON
#define TILT_OPCODE	1
//#define DSP_SMOOTH_PASTPOS	1 
#define TILT_SMOOTHING	1
//#define TILT_EDGE_FILTER	1
#define TILT_AREA_FILTER	1
//#define Pen2ReportMethod	2 //0 : All Original, 1 : Pen2 Prediction, 2 : Smoothing of Pen2 prediction, 3 : Pen2 Skip (180hz) 
//#define FirstTiltWaitReport 1    //Report skip until correct tilt value
#endif

//#define PenFingerSameLineNoiseException 1
//#define LongDisPointException	1
#define LocalFingerNoiseRemove 1				 //Local Finger Point remove near by pen point 
#define OrgPastPosInterpolation_OPCODE 3 		 //Org Pos Num 0:off, Max 3 
//#define SW_RATE_UP_EN					1		 // 1:300hz, 2:360hz, 3:420hz
//#define CalculateDeltaLocalSearch_OPCODE	1
#define ADAPTOR_NOISE_ALGO_EN			(NO)
#define AbnormalContactRemove_EN		(NO)
#define LOCAL_REBASE_ALGO_EN			(NO)	//	Local Mode Re-Baseline Algorithm On, HanCH
#define USED_DSPA_FUNC_FOR_PEN_SEARCH	(NO)	//	Local Pen Search Mode Phase & Delta Calculation On, HanCH
#define USED_DSPA_FUNC_FOR_PEN_LOCAL	(NO)	//	Local Pen Hover&Contact Mode Phase & Delta Calculation On, HanCH
#endif /* #if USED_PEN_MODE_OPERATION */

#define USED_DSPA_FUNC_FOR_FINGER			(YES)	//	Finger Mode DAP_A On, HanCH
#if USED_DSPA_FUNC_FOR_FINGER
#define USED_DSPA_FUNC_FOR_FINGER_LF		(NO)	//	Finger Mode DAP_A LineFilter On, HanCH
#define USED_DSPA_FUNC_FOR_FINGER_CAL_DELTA	(YES)	//	Finger Mode DAP_A Delta Calculation On, HanCH
#endif
#define FINGER_LF_VER2_EN				(NO)
#define PALM_VER1_EN					(NO)
#define WinCertAssistance_En			(NO)
#define CPI_TEST_EN						(NO)
#define LGD_ERROR_FRAME_PROCESS_EN		(NO)
#define NORMALIZE_DELTA_EN				(NO)
#define ADAPTIVE_SEEDBASE				(NO)
#define DIAG_OFF						(NO)
#define FAST_LF_EN						(NO)	//SW LineFilter Fast Process On //It must be NO, when DSP_A Finger Cal Delta define&parameter On, 201217 HanCH
#define LABEL_FAST_EN					(NO)	//label_SearchValidArea Fast Process On	1 : Delta Calculation&Labeling 1st Stage merge Off, 2 : Delta Calculation&Labeling 1st Stage merge On//It must be NO, when DSP_A Finger Cal Delta define&parameter On, 201217 HanCH
#if LABEL_FAST_EN
#define	ROW_IN_ARRAY 	8
#define COL_IN_ARRAY	8
#define ARRAY_ROW		(ROW_MAX/ROW_IN_ARRAY+1)
#define ARRAY_COL		(COL_MAX/COL_IN_ARRAY+1)
#endif
#define FAST_SPLIT						(NO)	//Label Split Fast Process On
/*******************************************************************************************
 *                       Operation Mode Setting
 *******************************************************************************************/
#if USED_LOCAL_IDLE_MODE_CONTROL
	#if USED_LOCAL_IDLE_30Hz
		#define LOCAL_IDLE_LHB_NUM					(16)
	#else /* USED_LOCAL_IDLE_30Hz */
		#define LOCAL_IDLE_LHB_NUM					(8)
	#endif /* USED_LOCAL_IDLE_30Hz */
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */

#define LHB_NUM								(8)

#define MAX_TOUCH_                      	(10)
#define MAX_KEY_                        	(4)
#define PAD_                            	(1)

#define ROW_MAX								(48)
#define COL_MAX								(84)
#define FPITCH_X							(3.430) //(?)
#define FPITCH_Y							(3.750) //(?)

#define LOCAL_FINGER_1MUX_ROW_NUM			(9)
#define LOCAL_FINGER_1LHB_SCAN_MUX_NUM		(3)
#if USED_IDLE_FINGER_EVEN_ODD
	#define LOCAL_IDLE_FINGER_ROW_NUM			(LOCAL_FINGER_1MUX_ROW_NUM<<1)
#else
	#define LOCAL_IDLE_FINGER_ROW_NUM			(LOCAL_FINGER_1MUX_ROW_NUM)
#endif
#define NI_ROW_MAX							(USED_IDLE_NI_SENSING_MUX_NUM * LOCAL_FINGER_1MUX_ROW_NUM)

#define PEN_COORD_ROW_MAX					(9)
#define PEN_COORD_COL_MAX					(COL_MAX)
#define PEN_DATA_ROW_MAX					(PEN_COORD_ROW_MAX*6) // MS MPP Pen Data
#define PEN_DATA_ROW_MAX_2					(PEN_COORD_ROW_MAX*8) // Wacom AIT Pen Data
#define PEN_DATA_ROW_MAX_3					(PEN_COORD_ROW_MAX*7) // Wacom WGP Pen Data

#define MUX_RANGE_SIZE	    				(2)
#define MAX_MUX_SIZE						(PEN_COORD_ROW_MAX)
#define MAX_MUX_HALF						(MAX_MUX_SIZE>>1)
#define MUX_MAX_ROW							(ROW_MAX - MAX_MUX_SIZE)


/***************************************************************************************************************************************
 * platform_env.h
 ***************************************************************************************************************************************/
//#define _USE_NOISE_INDEX_
#define _DV_SAMPLE_

#define MSPI_START_VAL					(uint32_t)(BIT7|BIT6|BIT4|BIT3|BIT1|BIT0)

#define SPI_DMY_LEN     				(2)
#define SRIC_PROTOCOL_RESET_COUNT   	(7)
#define READ_ALIGNED_BUF    			(0x0000)

#define ROIC_ALIGNED_COL_LEN  			(14)
#define ROIC_ALIGNED_ROW_LEN  			(9)
#if USED_SPI_NBIT_TRANSMODE
#define ROIC_ALIGNED_LOCAL_PEN_ROW_LEN  (9)
#else /* USED_SPI_NBIT_TRANSMODE */
#define ROIC_ALIGNED_LOCAL_PEN_ROW_LEN  (5)
#endif /* USED_SPI_NBIT_TRANSMODE */

#define MSPI_NUM                		(6)
#define SRIC_NUM                		(6)

#define SM_NUM                  		(1)

#if USED_SPI_NBIT_TRANSMODE
	#define MSPI_ROW_MAX_MUX				(8)
#else /* USED_SPI_NBIT_TRANSMODE */
	#define MSPI_ROW_MAX_MUX				(6)
#endif /* USED_SPI_NBIT_TRANSMODE */
#define FINGER_MUX_NUM              	(6)
#define FINGER_IDLE_NI_MUX_NUM          (USED_IDLE_NI_SENSING_MUX_NUM)

#define MSPI_MSPEN_ALIGNED_COL_LEN  				(14)
#define MSPI_MSPEN_ALIGNED_ROW_LEN  				(9)

#define MSPI_WACOMPEN_ALIGNED_COL_LEN  				(14)
#define MSPI_WACOMPEN_ALIGNED_ROW_LEN  				(9)

#define MSPI_WGPPEN_ALIGNED_COL_LEN  				(14)
#define MSPI_WGPPEN_ALIGNED_ROW_LEN  				(9)
#if USED_SPI_NBIT_TRANSMODE
#define MSPI_WGPPEN_ALIGNED_DUMMY					(0)
#else /* USED_SPI_NBIT_TRANSMODE */
#define MSPI_WGPPEN_ALIGNED_DUMMY					(2)
#endif /* USED_SPI_NBIT_TRANSMODE */


#define SZ_MSPIBUF_REGISTER     			(SPI_DMY_LEN + 1)
#define SZ_MSPIBUF_MUXDATA      			(SPI_DMY_LEN + (ROIC_ALIGNED_COL_LEN * ROIC_ALIGNED_ROW_LEN))
#define SZ_MSPIBUF_LOCAL_PEN_MUXDATA		(SPI_DMY_LEN + (ROIC_ALIGNED_COL_LEN * ROIC_ALIGNED_LOCAL_PEN_ROW_LEN))
#define SZ_MSPIBUF_FINGER_FULL_FRAME		(SZ_MSPIBUF_MUXDATA * FINGER_MUX_NUM)
#define SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME   (SZ_MSPIBUF_MUXDATA * FINGER_IDLE_NI_MUX_NUM)

#define LOCAL_FINGER_LAST_LHB			(PARTIAL_FINGER2)

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
#define LOCAL_OP_LAST_LHB				(PARTIAL_PEN_DATA4)
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
#define LOCAL_OP_LAST_LHB				(PARTIAL_PEN_COORD_DATA4)
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
#define LOCAL_OP_LAST_LHB				(PARTIAL_FINGER3)
#endif

#endif /* _INFORMATION_H_ */
