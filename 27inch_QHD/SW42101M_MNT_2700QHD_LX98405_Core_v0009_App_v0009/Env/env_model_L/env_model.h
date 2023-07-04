/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  env_model.h
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

#ifndef _ENV_MODEL_H_
#define _ENV_MODEL_H_

/*
 * Library Define
 */
#define LGD_TEST_LIBRARY_VERSION			(0x0001)
#define USED_PEN_MODE_OPERATION				(NO)
#define USED_INIT_PEN_MODE					(NO && USED_PEN_MODE_OPERATION)
#define USED_POOR_PANEL_COLLINE_DISABLE     (NO)
#define USED_130K_MAINFREQ					(NO) // if define USED_130K_MAINFREQ, USED_IDLE_MODE_CONTROL off.
#define USED_ONLY_IDLE_MODE					(NO)
#define USED_SW92400_OLD_SRIC_PROTOCOL		(YES)


#define USED_MNT_USB_CUSTOM_PROTOCOL		(NO)


#if 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(0)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(0)

#define ECLK_DRIVING_STRENGTH_0		(0)
#define ECLK_DRIVING_STRENGTH_1		(0)
#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(1)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(0)

#define ECLK_DRIVING_STRENGTH_0		(0)
#define ECLK_DRIVING_STRENGTH_1		(0)
#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(0)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(1)

#define ECLK_DRIVING_STRENGTH_0		(0)
#define ECLK_DRIVING_STRENGTH_1		(0)
#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(1)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(1)

#define ECLK_DRIVING_STRENGTH_0		(0)
#define ECLK_DRIVING_STRENGTH_1		(0)





#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(0)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(0)

#define ECLK_DRIVING_STRENGTH_0		(1)
#define ECLK_DRIVING_STRENGTH_1		(0)
#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(1)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(0)

#define ECLK_DRIVING_STRENGTH_0		(1)
#define ECLK_DRIVING_STRENGTH_1		(0)
#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(0)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(1)

#define ECLK_DRIVING_STRENGTH_0		(1)
#define ECLK_DRIVING_STRENGTH_1		(0)
#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(1)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(1)

#define ECLK_DRIVING_STRENGTH_0		(1)
#define ECLK_DRIVING_STRENGTH_1		(0)





#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(0)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(0)

#define ECLK_DRIVING_STRENGTH_0		(0)
#define ECLK_DRIVING_STRENGTH_1		(1)
#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(1)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(0)

#define ECLK_DRIVING_STRENGTH_0		(0)
#define ECLK_DRIVING_STRENGTH_1		(1)
#elif 1

// LX98405 Settting --> Must!! - ECLK Driving Strength - 1
#define MSPI_DRIVING_STRANGTH_CSN_0			(1)
#define MSPI_DRIVING_STRANGTH_CSN_1			(1)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(1)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(1)//0//1
#define MSPI_DRIVING_STRANGTH_MOSI_0		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(1)//0//1

#define ECLK_DRIVING_STRENGTH_0		(1)
#define ECLK_DRIVING_STRENGTH_1		(1)
#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(1)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(1)

#define ECLK_DRIVING_STRENGTH_0		(0)
#define ECLK_DRIVING_STRENGTH_1		(1)





#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(0)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(0)

#define ECLK_DRIVING_STRENGTH_0		(1)
#define ECLK_DRIVING_STRENGTH_1		(1)
#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(1)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(0)

#define ECLK_DRIVING_STRENGTH_0		(1)
#define ECLK_DRIVING_STRENGTH_1		(1)
#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(0)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(0)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(1)

#define ECLK_DRIVING_STRENGTH_0		(1)
#define ECLK_DRIVING_STRENGTH_1		(1)
#elif 0
#define MSPI_DRIVING_STRANGTH_CSN_0			(0)
#define MSPI_DRIVING_STRANGTH_CSN_1			(0)
#define MSPI_DRIVING_STRANGTH_SCLK_0		(1)
#define MSPI_DRIVING_STRANGTH_SCLK_1		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_0		(1)
#define MSPI_DRIVING_STRANGTH_MOSI_1		(1)

#define ECLK_DRIVING_STRENGTH_0		(1)
#define ECLK_DRIVING_STRENGTH_1		(1)

#endif







#define UNIQUE_VID 						(0x1FD2)

#define USED_NEW_TCON_BOARD				(NO)
#define USED_FINGER_ONLY				(YES)
#define USED_SRIC_CHANNEL_PAD_OFF		(NO)
#define USED_FORCE_S3_MODE_OPER			(NO)

#if defined(USE_BOOTLOADER_CODE)
#define USED_GPIO_TEST_HANDSHAKE		(NO)
#else /* USE_BOOTLOADER_CODE */
#define USED_GPIO_TEST_HANDSHAKE		(NO)
#endif /* USE_BOOTLOADER_CODE */

#if defined(USE_BOOTLOADER_8KB)
	#define FW_SIZE			(120*1024)
#elif defined(USE_BOOTLOADER_16KB)
	#define FW_SIZE			(112*1024)
	#define FW_CRC_SIZE		(108*1024)
#else
	#define FW_SIZE			(128*1024)
#endif

#define USED_IDLE_MODE_CONTROL						(NO)
#define USED_IDLE_NI_SENSING_MUX_NUM				(1)
#define USED_TSYNC2_INPUT_CONTROL					(YES)
//#define USED_ECLK_SOURCE_TIMERCLK					(NO)
#define USED_ECLK_ON_OFF_CONTROL					(YES)
#define ECLK_ON_OFF_CONTROL_START_CNT_THD			(10)
#define USED_ECLK_ON_OFF_CONTROL_DISABLE_DATAREAD	(YES & USED_ECLK_ON_OFF_CONTROL)
#define USED_NORMAL_NI_SENSING						(NO)
#define USED_AFE_BIAS_CURRENT_DOWN					(NO)
#define USED_MCU_IDLE_LOW_PWR_CONTROL				(NO)
#define USED_PLL_LOCKED_DEFENSE_CODE				(YES)
#define USED_REFERENCE_INIT_IDLE_MODE_ENTER			(YES)
#define USED_LAST_MUX_NODELAY						(NO)

//#if (CUSTOMER == MODEL_LGD_SW97400B)
#define INTERPOLATION_VER1_En								(NO)
#define INTERPOLATION_VER2_En								(NO)
#define INTERPOLATION_VER3_En								(NO)
#define SKIP_FRAME_NUM_ON_IDLE_MODE							(1)
#define USED_FRAME_SKIP_IDLE_MODE_CONTROL					(YES)
#define USED_LPWG_MODE_CONTROL								(NO)//(YES)
#define LGD_ERROR_FRAME_PROCESS_EN							(NO)
#define USED_TPIC_MUXEN_ON_OFF_CONTROL						(YES)
#define USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM					(YES & USED_TPIC_MUXEN_ON_OFF_CONTROL)
#define TPIC_MUXEN_ON_OFF_CONTROL_START_CNT_THD				(10)
#define USED_TPIC_MUXEN_ON_OFF_CONTROL_DISABLE_DATAREAD		(YES & USED_TPIC_MUXEN_ON_OFF_CONTROL)

#define MODE_SMT
#define REPORT_INTERPOLATION

#define PWMDRV_USED_FREQUENCY						(PWMDRV_FREQUENCY_91K)
#define PLL_OUT_CLOCK_SPEED							(PLL_OUT_CLOCK_90MHz)
#define BIAS_ON_OFF_CTRL_INIT_FRAME_NUM				(5)
#define USED_DUMMY_PWM_DISABLE						(NO)
#define USED_OPERATION_STAND_ALONE					(NO)
#define USED_OPERATION_STAND_ALONE_DISPLAY_ON		(NO)
#define USED_AFE_SRIC_SSU_CONTROL					(NO) // <<<<<
#define PMIC_MUXEN_CONTROL_CASE_1					(1)
#define PMIC_MUXEN_CONTROL_CASE_2					(2)
#define PMIC_MUXEN_CONTROL_CASE						(PMIC_MUXEN_CONTROL_CASE_1)

#define USED_SHARP_SPECIFIC_PROTOCOL				(NO)
#define USED_MOBILE_I2C_PROTOCOL					(NO)

#define USED_TEST_OPERATION_ENABLE					(NO)

#define USED_S3_MODE_FUNCTION						(NO && (!USED_PEN_MODE_OPERATION))
#define USED_LPWG_MCU_SLEEP							(NO && (!USED_PEN_MODE_OPERATION))
#define USED_S3_ALL_MUX_SHORT						(NO)
/*
 * �ӽ� define
 */
#define USED_ONLY_BOE_TEST_EQU						(NO)
#define USED_WINDOW_10_QE_BOE						(NO)
#define USED_SPEED_MESURE							(NO)
#define USED_NEW_CONFIG_PARAMETER					(YES)
#define USED_SRIC_RTC_VAL							(YES)  // RTC : Run Time Config

#define SWIP_QUEUE_MODE 				(2)
#define SWIP_QUEUE_SIZE 				(7)
//#define SHORT_COMPENSATION 			(1)
#define SHORT_NUM 						(10)


/* Define for Model Customer Dependency */
#define MODEL_LGD_SW92400				(1)
#define MODEL_LGD_SW97400B				(2)
#define MODEL_LGD_LX98405				(3)

#define CUSTOMER   						(MODEL_LGD_LX98405)

#include "../env_model_L/customer/DEFAULT/information.h"


#define ACCESS_MATRIX(_p, _col_, _r, _c)    (*((_p)+(_col_)*(_r)+(_c)))
#define POW(a)                              (a)
#define SQRT(a)								algorithm_calc_sqrt(POW(a))

#define SECTION_NAME_LEN_               	(8)
#define CUSTOM_INFO_                    	(10)
#define CUSTOM_PATH_NAME_LEN_           	(32)
#define PUBLIC_PATH_NAME_LEN_           	(32)

#define MAX_TOUCH_                      	(10)
#define MAX_KEY_                        	(4)
#define PAD_                            	(1)

#define ROW_MAX								(48)
#define COL_MAX								(96)
//#define NI_FRAME_NUM						(2)
#define NI_ROW_MAX							(USED_IDLE_NI_SENSING_MUX_NUM*4) // (12)

#define PEN_COORD_ROW_MAX					(5)//(8)
#define PEN_COORD_COL_MAX					(80)//(84)
#define PEN_DATA_ROW_MAX					(PEN_COORD_ROW_MAX*4)

#define MUX_RANGE_SIZE	    				(2)
#define MAX_MUX_SIZE						(10)//(8)
#define MAX_MUX_HALF						(MAX_MUX_SIZE>>1)
#define MUX_MAX_ROW							(((ROW_MAX - MAX_MUX_SIZE + 1)>>1)<<1)


/***************************************************************************************************************************************
 * platform_env.h
 ***************************************************************************************************************************************/
#define _DV_SAMPLE_

#define SPI_DMY_LEN     				(2)  // ADDR + CMD LX98405
#define SRIC_PROTOCOL_RESET_COUNT   	(7)
#define READ_ALIGNED_BUF    			(0x0800) // 0800

#define R0_ALIGNED_COL_LEN  			(12)
#define R0_ALIGNED_ROW_LEN  			(5)
#define R0_COL_LEN          			(6)
#define R1_COL_LEN          			(6)
#define R0_ROW_LEN          			(5)
#define R1_ROW_LEN          			(5)
#define SM_COL_LEN          			(12)

#define MSPI_NUM                		(4)
#define SRIC_NUM                		(4)

#define SM_NUM                  		(1)

#define FINGER_MUX_NUM              	(10)
#define FINGER_SENSING_MUX_NUM_1LHB		(9)
#define FINGER_NI_MUX_NUM           	(3)
#define FINGER_IDLE_NI_MUX_NUM          (USED_IDLE_NI_SENSING_MUX_NUM)
#define FINGER_FULLFRAME_TSYNC_NUM		(FINGER_MUX_NUM / FINGER_MUX_NUM_1LHB)
#if USED_NORMAL_NI_SENSING
#define FINGER_FULL_FRAME_MUX_NUM		(FINGER_MUX_NUM + FINGER_NI_MUX_NUM)
#else /* USED_NORMAL_NI_SENSING */
#define FINGER_FULL_FRAME_MUX_NUM		(FINGER_MUX_NUM)
#endif /* USED_NORMAL_NI_SENSING */
#define MSPI_ROW_MAX_MUX				(10)//(16)

#define FINGERPEN_MUX_NUM           	(4)

// choigs
#define SZ_MSPIBUF_REGISTER     			(SPI_DMY_LEN + 2)  // LX98405
//#define SZ_MSPIBUF_MUXDATA      			(SPI_DMY_LEN + ((R0_ALIGNED_COL_LEN * R0_ROW_LEN)*2))
#define SZ_MSPIBUF_MUXDATA      			(SPI_DMY_LEN + (R0_ALIGNED_COL_LEN * R0_ROW_LEN)*2)

#define SZ_MSPIBUF_FINGER_FULL_FRAME    	(SZ_MSPIBUF_MUXDATA * FINGER_FULL_FRAME_MUX_NUM)
#define SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME   (SZ_MSPIBUF_MUXDATA * FINGER_IDLE_NI_MUX_NUM)
#define SZ_MSPIBUF_FINGERPEN_FRAME      	(SZ_MSPIBUF_MUXDATA * FINGERPEN_MUX_NUM)

#define PIN_MSPI_SSN_0					(PIN_GPA00)
#define PIN_MSPI_SCLK_0					(PIN_GPA01)
#define PIN_MSPI_MOSI_0					(PIN_GPA02)
#define PIN_MSPI_MISO_0					(PIN_GPA03)
#define PIN_MSPI_SSN_1					(PIN_GPA04)
#define PIN_MSPI_SCLK_1					(PIN_GPA05)
#define PIN_MSPI_MOSI_1					(PIN_GPA06)
#define PIN_MSPI_MISO_1					(PIN_GPA07)
#define PIN_MSPI_SSN_2					(PIN_GPA08)
#define PIN_MSPI_SCLK_2					(PIN_GPA09)
#define PIN_MSPI_MOSI_2					(PIN_GPA10)
#define PIN_MSPI_MISO_2					(PIN_GPA11)
#define PIN_MSPI_SSN_3					(PIN_GPA12)
#define PIN_MSPI_SCLK_3					(PIN_GPA13)
#define PIN_MSPI_MOSI_3					(PIN_GPA14)
#define PIN_MSPI_MISO_3					(PIN_GPA15)
#define PIN_MSPI_SSN_4					(PIN_GPA16)
#define PIN_MSPI_SCLK_4					(PIN_GPA17)
#define PIN_MSPI_MOSI_4					(PIN_GPA18)
#define PIN_MSPI_MISO_4					(PIN_GPA19)
#define PIN_MSPI_SSN_5					(PIN_GPA20)
#define PIN_MSPI_SCLK_5					(PIN_GPA21)
#define PIN_MSPI_MOSI_5					(PIN_GPA22)
#define PIN_MSPI_MISO_5					(PIN_GPA23)


#define VSYNC_HIGH             			(GPIO->tGPIO_DATA_0.tBit.GPA26)
#define TSYNC_HIGH             			(GPIO->tGPIO_DATA_0.tBit.GPA27)


#endif /* _ENV_MODEL_H_ */
