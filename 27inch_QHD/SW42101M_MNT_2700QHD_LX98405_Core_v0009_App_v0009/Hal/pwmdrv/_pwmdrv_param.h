/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : mspi_.h
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

#ifndef __PWMDRV_PARAM_H_
#define __PWMDRV_PARAM_H_

/*
 * defines
 *
 * */

typedef enum {
	ePWM_PARAM_FINGER = 0,
	ePWM_PARAM_PEN = 1,
	ePWM_PARAM_MAX,

} ePwmParamOpMode;

/*
 * typedef
 *
 * */
typedef union
{
    struct
	{
      __IO uint32_t  HI_ABOVE_NUM       :  6;
      __IO uint32_t  LO_BELOW_NUM       :  6;
      __IO uint32_t  FSM_ON_IBE         :  1;
      __IO uint32_t  FSM_ON_IEV         :  1;
      __IO uint32_t  FSM_ON_IE          :  1;
      __IO uint32_t  VSYNC_IN_EXT_IBE   :  1;
      __IO uint32_t  VSYNC_IN_EXT_IEV   :  1;
      __IO uint32_t  VSYNC_IN_EXT_IE    :  1;
      __IO uint32_t  TSYNC_IN_EXT_IBE   :  1;
      __IO uint32_t  TSYNC_IN_EXT_IEV   :  1;
      __IO uint32_t  TSYNC_IN_EXT_IE    :  1;
      __IO uint32_t  TSYNC_OUT_EXT_IBE  :  1;
      __IO uint32_t  TSYNC_OUT_EXT_IEV  :  1;
      __IO uint32_t  TSYNC_OUT_EXT_IE   :  1;
      __IO uint32_t  TSYNC_FR_IBE       :  1;
      __IO uint32_t  TSYNC_FR_IEV       :  1;
      __IO uint32_t  TSYNC_FR_IE        :  1;
      __IO uint32_t  TSYNC_MNT_IBE      :  1;
      __IO uint32_t  TSYNC_MNT_IEV      :  1;
      __IO uint32_t  TSYNC_MNT_IE       :  1;
      __IO uint32_t  RESERVED       	:  2;
    } __PACKED tBit;

    __IO uint32_t ulBulk;

} __PACKED tPWMDRV_INTR_CFG_t;

typedef union
{
    struct {
      __IO uint32_t  BEACON_D0    :  5;
      __IO uint32_t  BEACON_D1    :  5;
      __IO uint32_t  BEACON_D2    :  5;
      __IO uint32_t  BEACON_D3    :  5;
      __IO uint32_t  BEACON_D4    :  5;
      __IO uint32_t  BEACON_D5    :  5;
    } __PACKED tBit;

    __IO uint32_t  ulBulk;

} __PACKED tPWMDRV_DSSS_INFO_1_t;


typedef union
{
	struct {
		__IO uint32_t  DLY_0 :  16;
		__IO uint32_t  DLY_1 :  16;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_PRLG_t;

typedef union
{
	struct {
	      __IO uint32_t  TX_PRD :  16;
	      __IO uint32_t  TX_LOW :  16;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_PRE_0_t;


typedef union
{
	struct {
	      __IO uint32_t  TX_NUM  :  10;
	      __IO uint32_t  PRE_DLY :  16;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_PRE_1_t;


typedef union
{
	struct {
	      __IO uint32_t  DSSS_DLY :  8;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_PRE_2_t;

typedef union
{
	struct {
	      __IO uint32_t  DLY_0_BEACON :  16;
	      __IO uint32_t  DLY_1        :  16;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_EPLG_0_t;

typedef union
{
	struct {
	      __IO uint32_t  DLY_0_PING_FG_F  :  16;
	      __IO uint32_t  DLY_0_PING_FG_L  :  16;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_EPLG_1_t;


typedef union
{
	struct {
	      __IO uint32_t  DLY_0_PING_PN_P  :  16;
	      __IO uint32_t  DLY_0_PING_PN_D  :  16;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_EPLG_2_t;


typedef union
{
	struct {
	      __IO uint32_t  LHB_01     :  2;   /*!<                   */
	      __IO uint32_t  LHB_02     :  2;   /*!<                   */
	      __IO uint32_t  LHB_03     :  2;   /*!<                   */
	      __IO uint32_t  LHB_04     :  2;   /*!<                   */
	      __IO uint32_t  LHB_05     :  2;   /*!<                   */
	      __IO uint32_t  LHB_06     :  2;   /*!<                   */
	      __IO uint32_t  LHB_07     :  2;   /*!<                   */
	      __IO uint32_t  LHB_08     :  2;   /*!<                   */
	      __IO uint32_t  LHB_09     :  2;   /*!<                   */
	      __IO uint32_t  LHB_10     :  2;   /*!<                   */
	      __IO uint32_t  LHB_11     :  2;   /*!<                   */
	      __IO uint32_t  LHB_12     :  2;   /*!<                   */
	      __IO uint32_t  LHB_13     :  2;   /*!<                   */
	      __IO uint32_t  LHB_14     :  2;   /*!<                   */
	      __IO uint32_t  LHB_15     :  2;   /*!<                   */
	      __IO uint32_t  LHB_16     :  2;   /*!<                   */
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_FG_0_t;

typedef union
{
	struct {
	      __IO uint32_t  LHB_17     :  2;
	      __IO uint32_t  LHB_18     :  2;
	      __IO uint32_t  LHB_19     :  2;
	      __IO uint32_t  LHB_20     :  2;
	      __IO uint32_t  LHB_21     :  2;
	      __IO uint32_t  LHB_22     :  2;
	      __IO uint32_t  LHB_23     :  2;
	      __IO uint32_t  LHB_24     :  2;
	      __IO uint32_t  LHB_25     :  2;
	      __IO uint32_t  LHB_26     :  2;
	      __IO uint32_t  LHB_27     :  2;
	      __IO uint32_t  LHB_28     :  2;
	      __IO uint32_t  LHB_29     :  2;
	      __IO uint32_t  LHB_30     :  2;
	      __IO uint32_t  LHB_31     :  2;
	      __IO uint32_t  LHB_32     :  2;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_FG_1_t;


typedef union
{
	struct {
	      __IO uint32_t  LHB_01     :  2;
	      __IO uint32_t  LHB_02     :  2;
	      __IO uint32_t  LHB_03     :  2;
	      __IO uint32_t  LHB_04     :  2;
	      __IO uint32_t  LHB_05     :  2;
	      __IO uint32_t  LHB_06     :  2;
	      __IO uint32_t  LHB_07     :  2;
	      __IO uint32_t  LHB_08     :  2;
	      __IO uint32_t  LHB_09     :  2;
	      __IO uint32_t  LHB_10     :  2;
	      __IO uint32_t  LHB_11     :  2;
	      __IO uint32_t  LHB_12     :  2;
	      __IO uint32_t  LHB_13     :  2;
	      __IO uint32_t  LHB_14     :  2;
	      __IO uint32_t  LHB_15     :  2;
	      __IO uint32_t  LHB_16     :  2;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_PN_0_t;

typedef union
{
	struct {
	      __IO uint32_t  LHB_17     :  2;
	      __IO uint32_t  LHB_18     :  2;
	      __IO uint32_t  LHB_19     :  2;
	      __IO uint32_t  LHB_20     :  2;
	      __IO uint32_t  LHB_21     :  2;
	      __IO uint32_t  LHB_22     :  2;
	      __IO uint32_t  LHB_23     :  2;
	      __IO uint32_t  LHB_24     :  2;
	      __IO uint32_t  LHB_25     :  2;
	      __IO uint32_t  LHB_26     :  2;
	      __IO uint32_t  LHB_27     :  2;
	      __IO uint32_t  LHB_28     :  2;
	      __IO uint32_t  LHB_29     :  2;
	      __IO uint32_t  LHB_30     :  2;
	      __IO uint32_t  LHB_31     :  2;
	      __IO uint32_t  LHB_32     :  2;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_PN_1_t;

typedef union
{
	struct {
	      __IO uint32_t  TSYNC_MNT_ENA      :  1;
	      __IO uint32_t  TSYNC_MNT_CLR      :  1;
	      __IO uint32_t  FR_SEL_POINT       :  2;
	      __IO uint32_t  FR_TSYNC_PRD       :  16;
	      __IO uint32_t  FR_TSYNC_NUM       :  6;
	      __IO uint32_t  SYNC_AUTO_CLR      :  1;
	      __IO uint32_t  SEL_ECLK_AUTO      :  1;
	      __IO uint32_t  ENA_VSYNC_INIT     :  1;
	      __IO uint32_t  ENA_TSYNC_INIT     :  1;
	      __IO uint32_t  TSYNC_FREQ_EN_FG_L :  1;

	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_IN_CTRL_t;

typedef union
{
	struct {
	      __IO uint32_t  PWMDRV_ENA         :  1;
	      __IO uint32_t  VSYNC_EDGE         :  1;
	      __IO uint32_t  TSYNC_EDGE         :  1;
	      __IO uint32_t  SEL_EXT_VSYNC      :  1;
	      __IO uint32_t  SEL_EXT_TSYNC      :  1;
	      __IO uint32_t  SEL_FR_TSYNC       :  1;
	      __IO uint32_t  UPDATE_VSYNC       :  1;
	      __IO uint32_t  UPDATE_TSYNC       :  1;
	      __IO uint32_t  UPDATE_DBG         :  1;
	      __IO uint32_t  VSYNC_FREQ_EN      :  1;
	      __IO uint32_t  TSYNC_FREQ_EN_FG_F :  1;
	      __IO uint32_t  DSSS_FREQ          :  6;
	      __IO uint32_t  ENA_PRTX_P0        :  1;
	      __IO uint32_t  ENA_PRTX_D0        :  1;
	      __IO uint32_t  ENA_DSSS_P         :  1;
	      __IO uint32_t  ENA_DSSS_D         :  1;
	      __IO uint32_t  ENA_PRTX_P1        :  1;
	      __IO uint32_t  ENA_PRTX_D1        :  1;
	      __IO uint32_t  ENA_ACTX_PD        :  1;
	      __IO uint32_t  ENA_ECLK_AUTO      :  1;
	      __IO uint32_t  VSYNC_NUM          :  6;
	      __IO uint32_t  VSYNC_BP           :  1;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_GBL_t;

typedef union
{
	struct {
		__IO uint32_t  DSSS_ENA_T0         :  1;
		__IO uint32_t  PRE_ENA_T0          :  1;
		__IO uint32_t  ACT_ENA_T0          :  1;
		__IO uint32_t  RESERVED0_T0		   :  1;
		__IO uint32_t  RESERVED1_T0		   :  1;
		__IO uint32_t  RESERVED2_T0		   :  1;
		__IO uint32_t  LFD_TX_ACT_ENA_T0   :  1;
		__IO uint32_t  DSSS_ENA_T1         :  1;
		__IO uint32_t  PRE_ENA_T1          :  1;
		__IO uint32_t  ACT_ENA_T1          :  1;
		__IO uint32_t  RESERVED0_T1		   :  1;
		__IO uint32_t  RESERVED1_T1		   :  1;
		__IO uint32_t  RESERVED2_T1		   :  1;
		__IO uint32_t  LFD_TX_ACT_ENA_T1   :  1;
		__IO uint32_t  T_2 				   :  7;
	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_ENA_PWM_t;
/*
 *
 * Sample structure
typedef union
{
	struct {

	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_PRE_2_t;
*/
#endif /* __PWMDRV_PARAM_H_ */
