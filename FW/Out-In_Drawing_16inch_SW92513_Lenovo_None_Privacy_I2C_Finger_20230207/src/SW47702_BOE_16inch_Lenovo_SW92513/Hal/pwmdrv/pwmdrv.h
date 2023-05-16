/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : pwmdrv.h
 * created on : 10. 05. 2019
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

#ifndef _PWMDRV_H_
#define _PWMDRV_H_


#define PWM_TSD_MODE					(0)
#define PWM_TFD_MODE					(1)

#define PWM_ONE_SHOT_MODE				(0)
#define PWM_CONTINUOS_MODE				(1)

#define PWM_FRAME_RATE_DIV_1			(0)
#define PWM_FRAME_RATE_DIV_2			(1)
#define PWM_FRAME_RATE_DIV_3			(2)
#define PWM_FRAME_RATE_DIV_4			(3)

#define PWM_FRINTR_LAST_TSYNC_R_EDGE	(0)
#define PWM_FRINTR_LAST_MUX				(1)

#define PWM_FULL_FINGER_MODE			(0)
#define PWM_LOCAL_PEN_MODE				(1)
#define PWM_LOCAL_PEN_IDLE_MODE			(2) // PWM Register Is Not!! only Used Check!!
#define PWM_FULL_FINGER_IDLE_MODE		(2) // PWM Register Is Not!! only Used Check!!

#define PWM_OFFCLK_IGNORE				(0)
#define PWM_OFFCLK_EVASION				(1)

#define PWM_1FRAME_IN_1VSYNC			(0) //60Hz
#define PWM_2FRAME_IN_1VSYNC			(1) //120Hz

#define PWM_VSYNC_INTR_EXTERNAL			(0)
#define PWM_VSYNC_INTR_INTERNAL			(1)

#define PWM_TSYNC_INTR_EXTERNAL			(0)
#define PWM_TSYNC_INTR_INTERNAL			(1)

#define PWM_TSYNC_SRIC_INTR_EXTERNAL	(0)
#define PWM_TSYNC_SRIC_INTR_INTERNAL	(1)

#define PWM_TSYNC_KIOSK_INTR_INTERNAL	(0)
#define PWM_TSYNC_KIOSK_INTR_INTERNAL_TSYNC	(1)

#define PWM_ECLK_TSYNC_ON_OFF			(0)
#define PWM_ECLK_ALWAYS_ON				(1)

#define PWM_INTR_DISABLE				(0)
#define PWM_INTR_RISING					(1)
#define PWM_INTR_FALLING				(2)
#define PWM_INTR_BOTH					(3)

#define PWM_TSYNC_IN_T					(0)
#define PWM_TSYNC_IN_D					(1)

#define PWM_LHB_CONFIG_BEACON			(0)
#define PWM_LHB_CONFIG_PEN_POS			(1)
#define PWM_LHB_CONFIG_PEN_TILT			(1)
#define PWM_LHB_CONFIG_PEN_DATA			(2)
#define PWM_LHB_CONFIG_PEN_POS_DATA		(2)
#define PWM_LHB_CONFIG_PEN_DETECTION	(1)
#define PWM_LHB_CONFIG_FINGER			(3)
#define PWM_LHB_CONFIG_NOISE			(4)
#define PWM_LHB_CONFIG_PING_ONLY		(6)
#define PWM_LHB_CONFIG_NONE				(5)
#define PWM_LHB_CONFIG_ESD_SCAN			(1)  // Same Pen Pos

#define TSYNC_LHB						(16)

#define PWM_INTR_ENABLE					(1)
#define PWM_INTR_DISABLE				(0)

#define PWM_INTR_RISING_EDGE			(1)
#define PWM_INTR_FALLING_EDGE			(2)
#define PWM_INTR_BOTH_EDGE				(3)

#define PWM_TYNCIN_INT_SOURCE_TSYNC_T	(0)
#define PWM_TYNCIN_INT_SOURCE_TSYNC_D	(1)

#define PWM_LHB_BEACON_NUM				(3)
#define PWM_PEN_COMMON_BEACON			(0)

#define PWM_MPP_PEN_1st_SEARCH_BEACON	(0)
#define PWM_MPP_PEN_1st_PEN_BEACON		(1)
#define PWM_MPP_PEN_2nd_BEACON			(2)

#define PWM_AIT_PEN_DEFAULT_BEACON		(0)

#define PWM_WGP_PEN_SETTABLE_BEACON		(0)
#define PWM_WGP_PEN_GETABS_BEACON		(1)
#define PWM_WGP_PEN_GETHASH_BEACON		(2)
#define PWM_WGP_PEN_GETID_1st_BEACON	(3)
#define PWM_WGP_PEN_GETID_2nd_BEACON	(4)
#define PWM_WGP_PEN_GETID_3rd_BEACON	(5)
#if USED_NOISE_HOPPING_FREQ
#define PWM_WGP_PEN_HOPP_SETTABLE_BEACON (6)
#endif
#define PWM_WGP_PEN_BEACON_CHANGE_DONE	(0xFF)


/*
 * PWM Clock Macro
 * used system clock divided into pwm-div-num
 */
#define PWM_CLOCK_MHz				(24)
#define PWM_usec(val)				((val) == 0 ? 0 : ((val) * PWM_CLOCK_MHz))
#define PWM_nsec(val)				((val) == 0 ? 0 : (((val) * PWM_CLOCK_MHz)/1000)-1)
#define PWM_Full_KHz(val)			(((PWM_CLOCK_MHz*1000)/(val))-1)
#define PWM_Half_KHz(val)			(((PWM_Full_KHz(val))/2))
#define PWM_Full_Hz(val)			(((PWM_CLOCK_MHz*1000000)/(val))-1)
#define PWM_Half_Hz(val)			(((PWM_Full_Hz(val))/2))

/*
 * TSync Clock Macro
 * Used System Clock
 */
#define TSYNC_CLOCK_MHz				(12)
#define TSYNC_usec(val)				((val) == 0 ? 0 : ((val) * PWM_CLOCK_MHz))
#define TSYNC_nsec(val)				((val) == 0 ? 0 : (((val) * PWM_CLOCK_MHz)/1000)-1)
#define TSYNC_Full_KHz(val)			(((PWM_CLOCK_MHz*1000)/(val))-1)
#define TSYNC_Half_KHz(val)			(((PWM_Full_KHz(val))/2))
#define TSYNC_Full_Hz(val)			(((PWM_CLOCK_MHz*1000000)/(val))-1)
#define TSYNC_Half_Hz(val)			(((PWM_Full_Hz(val))/2))

#if USED_BEACON_SET_ADJUST
// A[4:0] WGP Table list
typedef enum
{
	lst0 = 0,
	lst1,
	lst2,
	lst3,
	lst4,
	lst5,
	lst6,
	lst7,
	lst8,
	lst9,
	lst10,
	lst11,
	lst12,
	lst13,
	lst14,
	lst15,
	lst16,
	lst17,
	lst18,
} eWGPtablelist_t;

// B[2:0] means frequency setting
typedef enum
{
	freq399k = 0,
	freq285k,
	freq228k,
	freq199k,
	freq170k,
	freq142k,
	freq114k,
	freq86k,
} eDLFreqtable_t;
#endif /* USED_BEACON_SET_ADJUST */

typedef struct
{
	IRQn_Type PWM_IRQ_TYPE;
	uint32_t ulIRQ_Priority;
	FunctionalState newState;

} tPWM_INTR_CFG_t;

/************************************************************/
extern void PWMDRV_Init(eSENSING_MODE_t _eSensingMode);
extern void PWMDRV_RegisterInit(eSENSING_MODE_t _eSensingMode, bool_t bIsInit);
extern void PWMDRV_LocalLHBSetting(eSENSING_MODE_t _eSensingMode);
#if USED_FULLSCAN_SWITCH_IDLE_TO_ACTIVE
extern void PWMDRV_FullScanIdleModeSetting(void);
#endif /* USED_FULLSCAN_SWITCH_IDLE_TO_ACTIVE */
extern void PWMDRV_GPIO_Init(eSENSING_MODE_t _eSensingMode);
extern void PWMDRV_Cmd(FunctionalState _NewState);
extern void PWMDRV_ITConfig(tPWM_INTR_CFG_t * pIntrCfg, uint32_t ulNum);

/************************************************************/
#if USED_PEN_MODE_OPERATION || USED_DUMMY_LHB_MODULATION
extern void PWMDRV_Set_DSSS_CODE(uint32_t ulIdx);
extern void PWMDRV_Set_DSSS_INFO(uint32_t ulIdx);
#if USED_BEACON_SET_ADJUST
extern void PWM_Set_UL_CMD(uint32_t cmd);
uint8_t UL_CRC(uint8_t d1, uint8_t d2, uint8_t d3);
extern uint64_t PWMDRV_Get_Chip(uint8_t val);
extern void PWMDRV_Set_DSSS_CODE_WGP(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t crc);
#endif /* USED_BEACON_SET_ADJUST */

#endif /* USED_PEN_MODE_OPERATION */

#endif /* _PWMDRV_H_ */
