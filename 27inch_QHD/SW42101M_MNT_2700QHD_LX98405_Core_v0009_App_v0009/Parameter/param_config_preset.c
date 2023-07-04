/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  param_config_sric.h
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

#include "hal_def.h"
#include "param_def.h"

#if (CUSTOMER == MODEL_LGD_SW97400B)
#include "sw97400b_register.h"
#endif /* (CUSTOMER == MODEL_LGD_SW97400B) */


const tParamPreMainSet_t ktParamPresetMainConf =
{
	.tParamCommonConf =
	{
		.tApp =
		{
			.ucFrameRate = 60,
			.ucIdleFrameRate = 60,
			.bUsedIdleModeCtrl = YES,
#if USED_ONLY_IDLE_MODE
			.ucIdleModeEnterSec = 1,
#else /* USED_ONLY_IDLE_MODE */
			.ucIdleModeEnterSec = 30,
#endif /* USED_ONLY_IDLE_MODE */
#if USED_NOISE_HOPPING_FREQ
			.HoppMainRollbackSec = 10,
#endif /* USED_NOISE_HOPPING_FREQ */
			.bUseFreqHopp = YES,

#if (USED_130K_MAINFREQ)
			.MainFreq = _FREQ_130k_,
			.HoppFreq1 = _FREQ_110k_,
			.HoppFreq2 = _FREQ_UNKNOWN_,
#else /* USED_130K_MAINFREQ */
			.MainFreq = _FREQ_110k_,
			.HoppFreq1 = _FREQ_130k_,
			.HoppFreq2 = _FREQ_UNKNOWN_,
#endif /* USED_130K_MAINFREQ */
		},
		.tAlgorithm =
		{
			.ucMaxTouch_ = MAX_TOUCH_,
			.ucLabelSearchDir = 8,
#if defined(SUPPORT_ANDROID)
			.iXResolution = 1920 + 12,
			.iYResolution = 1080,
#else
//			.iXResolution = 32768 + 192,
			.iXResolution = 32768,// + 400,
			.iYResolution = 32768,
#endif
			.iXEdgeNum = 1,
			.iXEdgeDen = 1,
			.iYEdgeNum = 1,
			.iYEdgeDen = 1,

			.ucLeftEdgeExpand_local = 64,
			.ucRightEdgeExpand_local = 64,
			.ucTopEdgeExpand_local = 64,
			.ucBottomEdgeExpand_local = 64,
				
			.ucXClipping = 1,
			.ucYClipping = 1,
			.ucClippingLeft	   = 0,//PARAMSET_CM_ALGO_ucClippingLeft,
			.ucClippingRight   = 0,//PARAMSET_CM_ALGO_ucClippingRight,
			.ucClippingTop	   = 0,//PARAMSET_CM_ALGO_ucClippingTop,
			.ucClippingBottom  = 0,//PARAMSET_CM_ALGO_ucClippingBottom,
			.usPanelXSizeInDmm = 2000,
			.usPanelYSizeInDmm = 2000,
			.tEdgePenSetVal =
			{
				.top_th = 15,
				.top_mul = 9,
				.top_SR = 2,
				.bottom_th = 25,
				.bottom_mul = 9,
				.bottom_SR = 2,
				.left_th = 15,
				.left_mul = 2,
				.left_SR = 0,
				.right_th = 25,
				.right_mul = 7,
				.right_SR = 2,
				.top_hover_th = 400,
				.top_hover_mul = 5,
				.top_hover_SR = 2,
				.bottom_hover_th = 400,
				.bottom_hover_mul = 5,
				.bottom_hover_SR = 2,
				.left_hover_th = 1100,
				.left_hover_mul = 17,
				.left_hover_SR = 4,
				.right_hover_th = 1100,
				.right_hover_mul = 17,
				.right_hover_SR = 4,
				.side_mul_val = 8,
				.edge_mul_val = 3,
				.odd_set_mul_val = 1,
				.even_set_mul_val = -1,
				.hover_side_mul_val = 10,
			},
		},
		.tProtocol =
		{
			.ePacketFormatId = PF_NORMAL,
		},
		.tHal =
		{
			.tMSPI_Conf =
			{
				.tParam_SCR =
				{
					.tBit.BITLEN = bitLen16,
					.tBit.DOUTEN = mosiOutEn,
					.tBit.CPHA = CphaIs0,
					.tBit.CPOL = CpolIs0,
					.tBit.MSTR = spiMstMode,
					.tBit.DORD = MsbFirst,
					.tBit.SPE = spiEna,
					.tBit.LBM = 0,
					.tBit.SSOSEL = 0,
					.tBit.SSOEXT = 1,
					.tBit.CKMAXRATE = 0,
					.tBit.CKMAXPRE = 0,
					.tBit.SWPRST = 0,
					.tBit.SWHRST = 0,
				},
				.tParam_SPIENA =
				{
					.tBit.spiTxEna0 = 1,
					.tBit.spiRxEna0 = 1,

					.tBit.spiTxEna1 = 0,
					.tBit.spiRxEna1 = 0,

					.tBit.spiTxEna2 = 0,
					.tBit.spiRxEna2 = 0,

					.tBit.spiTxEna3 = 1,
					.tBit.spiRxEna3 = 1,

					.tBit.spiTxEna4 = 1,
					.tBit.spiRxEna4 = 1,

					.tBit.spiTxEna5 = 1,
					.tBit.spiRxEna5 = 1,
				},
			},
			.tPWMDRV_Conf =
			{
				.usPwmFreq = 91,//94, // choigs
				.ucPwmPreNum = 2, // 2
				.ucPwmSetNum = 1,
				.ucPwmFingerActNum = 10,
				.ucPwmFinger1LHBMuxNum = 10,

				.usPwmNiFreq1 = 131,
				.ucPwmNiActNum = 13,
				.ucPwmNi1LHBMuxNum = USED_IDLE_NI_SENSING_MUX_NUM,

				.usFullFingerPWMIntervalDly = PWM_us(250),//(55)
				.usPenPositionPWMIntervalDly = 0,
				.usPenDataPWMIntervalDly = 0,
				.usPenFingerPWMIntervalDly = 0,

				.usLpwgActivePWMIntervalDly = 0,//PWM_us(50),
				.usLpwgIdlePWMIntervalDly = 0,//PWM_us(5),

				.tPWMDRV_GBL =
				{
					.tBit.PWMDRV_ENA = 0,
					.tBit.VSYNC_EDGE = 0,
					.tBit.TSYNC_EDGE = 0,
#if ( USED_OPERATION_STAND_ALONE_DISPLAY_ON || USED_OPERATION_STAND_ALONE)
					.tBit.SEL_EXT_VSYNC = 0,
#else
					.tBit.SEL_EXT_VSYNC = 1,
#endif
#if ( USED_OPERATION_STAND_ALONE_DISPLAY_ON || USED_OPERATION_STAND_ALONE)
					.tBit.SEL_EXT_TSYNC = 0,
#else
					.tBit.SEL_EXT_TSYNC = 1,
#endif
#if ( USED_OPERATION_STAND_ALONE_DISPLAY_ON || USED_OPERATION_STAND_ALONE)
					.tBit.SEL_FR_TSYNC = 1,
#else
					.tBit.SEL_FR_TSYNC = 0,
#endif
					.tBit.UPDATE_VSYNC = 1,
					.tBit.UPDATE_TSYNC = 1,
					.tBit.UPDATE_DBG = 0,
					.tBit.VSYNC_FREQ_EN = 1,
#if USED_NORMAL_NI_SENSING
					.tBit.TSYNC_FREQ_EN_FG_F = 1,
#else /* USED_NORMAL_NI_SENSING */
					.tBit.TSYNC_FREQ_EN_FG_F = 0,
#endif /* USED_NORMAL_NI_SENSING */
					.tBit.DSSS_FREQ = 0x0A,
					.tBit.ENA_PRTX_P0 = 1,
					.tBit.ENA_PRTX_D0 = 1,
					.tBit.ENA_DSSS_P = 0,
					.tBit.ENA_DSSS_D = 0,
					.tBit.ENA_PRTX_P1 = 0,
					.tBit.ENA_PRTX_D1 = 0,
					.tBit.ENA_ACTX_PD = 1,
					.tBit.ENA_ECLK_AUTO = 0,
					.tBit.VSYNC_NUM = 0x02,
					.tBit.VSYNC_BP = 1,
				},
				.tPWMDRV_INTR_CFG =
				{
					.tBit.HI_ABOVE_NUM = 3,
					.tBit.LO_BELOW_NUM = 3,
					/* FSM */
					.tBit.FSM_ON_IBE = INTR_CFG_SINGLE_EDGE,
					.tBit.FSM_ON_IEV = INTR_CFG_FALLING_EDGE,
#if (USED_LPWG_MODE_CONTROL || USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM)
					.tBit.FSM_ON_IE = INTR_CFG_ENABLE,
#else /* (USED_LPWG_MODE_CONTROL || USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM) */
					.tBit.FSM_ON_IE = INTR_CFG_DISABLE,
#endif /* (USED_LPWG_MODE_CONTROL || USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM) */
					/* VSYNC IN */
					.tBit.VSYNC_IN_EXT_IBE = INTR_CFG_SINGLE_EDGE,
					.tBit.VSYNC_IN_EXT_IEV = INTR_CFG_RISING_EDGE,
#if ( USED_OPERATION_STAND_ALONE)
					.tBit.VSYNC_IN_EXT_IE = INTR_CFG_DISABLE,
#else
					.tBit.VSYNC_IN_EXT_IE = INTR_CFG_ENABLE,
#endif
					/* TSYNC IN */
					.tBit.TSYNC_IN_EXT_IBE = INTR_CFG_BOTH_EDGE,
					.tBit.TSYNC_IN_EXT_IEV = INTR_CFG_FALLING_EDGE,
#if ( USED_OPERATION_STAND_ALONE)
					.tBit.TSYNC_IN_EXT_IE = INTR_CFG_DISABLE,
#else
					.tBit.TSYNC_IN_EXT_IE = INTR_CFG_ENABLE,
#endif
					/* TSYNC OUT */
					.tBit.TSYNC_OUT_EXT_IBE = INTR_CFG_SINGLE_EDGE,
					.tBit.TSYNC_OUT_EXT_IEV = INTR_CFG_FALLING_EDGE,
#if (USED_OPERATION_STAND_ALONE)
					.tBit.TSYNC_OUT_EXT_IE = INTR_CFG_ENABLE,
#else /* (USED_OPERATION_STAND_ALONE) */
					.tBit.TSYNC_OUT_EXT_IE = INTR_CFG_DISABLE,
#endif /* (USED_OPERATION_STAND_ALONE) */
					/* TSYNC FR */
					.tBit.TSYNC_FR_IBE = INTR_CFG_SINGLE_EDGE,
					.tBit.TSYNC_FR_IEV = INTR_CFG_RISING_EDGE,
					.tBit.TSYNC_FR_IE = INTR_CFG_DISABLE,

					/* TSYNC MNT */
					.tBit.TSYNC_MNT_IBE = INTR_CFG_SINGLE_EDGE,
					.tBit.TSYNC_MNT_IEV = INTR_CFG_RISING_EDGE,
					.tBit.TSYNC_MNT_IE = INTR_CFG_DISABLE,
				},
				/*
				 * # Beacon Table Value
				 *
				 * - normal : 0x022D
				 * - tilt : 0x062D
				 *
				 * */
				.ulBeaconTable = 0x022d,
#if (USED_OPERATION_STAND_ALONE_DISPLAY_ON)
				.ucSelTsyncOut = 1, // 0:Ext, 1:Internal, 2:FreeRunning, 3:x
#else /* (USED_OPERATION_STAND_ALONE_DISPLAY_ON) */
				.ucSelTsyncOut = 0, // 0:Ext, 1:Internal, 2:FreeRunning, 3:x
#endif /* (USED_OPERATION_STAND_ALONE_DISPLAY_ON) */
				.tPWMDRV_PRE_0 =
				{
					.tBit.TX_PRD = 0,
					.tBit.TX_LOW = 0,
				},
				.tPWMDRV_PRE_1 =
				{
					.tBit.TX_NUM = 0,
					.tBit.PRE_DLY = 0,
				},
				.tPWMDRV_PRE_2 =
				{
					.tBit.DSSS_DLY = 72,
				},
				.tPWMDRV_EPLG_2 =
				{
					.tBit.DLY_0_PING_PN_P = 0,
					.tBit.DLY_0_PING_PN_D = 0,
				},
				.tPWMDRV_PRLG =
				{
					.tBit.DLY_0 = PWM_us(20),
					.tBit.DLY_1 = 0,
				},
				.tPWMDRV_FG_0 =
				{
					.tBit.LHB_01 = PWM_FINGER,
					.tBit.LHB_02 = PWM_FINGER,
					.tBit.LHB_03 = PWM_FINGER,
					.tBit.LHB_04 = PWM_FINGER,
					.tBit.LHB_05 = PWM_FINGER,
					.tBit.LHB_06 = PWM_FINGER,
					.tBit.LHB_07 = PWM_FINGER,
					.tBit.LHB_08 = PWM_FINGER,
					.tBit.LHB_09 = PWM_FINGER,
					.tBit.LHB_10 = PWM_FINGER,
					.tBit.LHB_11 = PWM_FINGER,
					.tBit.LHB_12 = PWM_FINGER,
					.tBit.LHB_13 = PWM_FINGER,
					.tBit.LHB_14 = PWM_FINGER,
					.tBit.LHB_15 = PWM_FINGER,
					.tBit.LHB_16 = PWM_FINGER,
				},
				.tPWMDRV_FG_1 =
				{
					.tBit.LHB_17 = PWM_FINGER,
					.tBit.LHB_18 = PWM_FINGER,
					.tBit.LHB_19 = PWM_FINGER,
					.tBit.LHB_20 = PWM_FINGER,
					.tBit.LHB_21 = PWM_FINGER,
					.tBit.LHB_22 = PWM_FINGER,
					.tBit.LHB_23 = PWM_FINGER,
					.tBit.LHB_24 = PWM_FINGER,
					.tBit.LHB_25 = PWM_FINGER,
					.tBit.LHB_26 = PWM_FINGER,
					.tBit.LHB_27 = PWM_FINGER,
					.tBit.LHB_28 = PWM_FINGER,
					.tBit.LHB_29 = PWM_FINGER,
					.tBit.LHB_30 = PWM_FINGER,
					.tBit.LHB_31 = PWM_FINGER,
					.tBit.LHB_32 = PWM_FINGER,
				},
				.tPWMDRV_PN_0 =
				{
					.tBit.LHB_01 = PWM_BEACON,
					.tBit.LHB_02 = PWM_PEN_POSITON,
					.tBit.LHB_03 = PWM_PEN_DATA,
					.tBit.LHB_04 = PWM_FINGER,
					.tBit.LHB_05 = PWM_PEN_POSITON,
					.tBit.LHB_06 = PWM_PEN_DATA,
					.tBit.LHB_07 = PWM_PEN_DATA,
					.tBit.LHB_08 = PWM_FINGER,
					.tBit.LHB_09 = PWM_PEN_POSITON,
					.tBit.LHB_10 = PWM_FINGER,
					.tBit.LHB_11 = PWM_FINGER,
					.tBit.LHB_12 = PWM_FINGER,
					.tBit.LHB_13 = PWM_PEN_POSITON,
					.tBit.LHB_14 = PWM_PEN_DATA,
					.tBit.LHB_15 = PWM_PEN_DATA,
					.tBit.LHB_16 = PWM_FINGER,
				},
				.tPWMDRV_PN_1 =
				{
					.tBit.LHB_17 = PWM_FINGER,
					.tBit.LHB_18 = PWM_FINGER,
					.tBit.LHB_19 = PWM_FINGER,
					.tBit.LHB_20 = PWM_FINGER,
					.tBit.LHB_21 = PWM_FINGER,
					.tBit.LHB_22 = PWM_FINGER,
					.tBit.LHB_23 = PWM_FINGER,
					.tBit.LHB_24 = PWM_FINGER,
					.tBit.LHB_25 = PWM_FINGER,
					.tBit.LHB_26 = PWM_FINGER,
					.tBit.LHB_27 = PWM_FINGER,
					.tBit.LHB_28 = PWM_FINGER,
					.tBit.LHB_29 = PWM_FINGER,
					.tBit.LHB_30 = PWM_FINGER,
					.tBit.LHB_31 = PWM_FINGER,
					.tBit.LHB_32 = PWM_FINGER,
				},
				.tPWMDRV_IN_CTRL =
				{
					 .tBit.TSYNC_MNT_ENA = 0,
					 .tBit.TSYNC_MNT_CLR = 0,
					 .tBit.FR_SEL_POINT = 0,
					 .tBit.FR_TSYNC_PRD = PWM_us(600),//(1031 * 12)
					 .tBit.FR_TSYNC_NUM = TSYNC_LHB,
					 .tBit.SYNC_AUTO_CLR = 1,
					 .tBit.SEL_ECLK_AUTO = 0,
					 .tBit.ENA_VSYNC_INIT = 0,
					 .tBit.ENA_TSYNC_INIT = 0,
					 .tBit.TSYNC_FREQ_EN_FG_L = 0,
				},
				.tPWMDRV_ENA_PWM =
				{
					[ePWM_PARAM_FINGER] =
					{
						/* PWM_SRIC */
						.tBit.DSSS_ENA_T0 = 0,
						.tBit.PRE_ENA_T0 = 1,//0,
						.tBit.ACT_ENA_T0 = 1,
						.tBit.LFD_TX_ACT_ENA_T0 = 0,
						/* PWM_TPIC */
						.tBit.DSSS_ENA_T1 = 0,//1,
						.tBit.PRE_ENA_T1 = 1,
						.tBit.ACT_ENA_T1 = 1,
						.tBit.LFD_TX_ACT_ENA_T1 = 1,
						.tBit.T_2 = 0,
					},

					[ePWM_PARAM_PEN] =
					{
						/* PWM_SRIC */
						.tBit.DSSS_ENA_T0 = 0,
						.tBit.PRE_ENA_T0 = 1,
						.tBit.ACT_ENA_T0 = 1,
						.tBit.LFD_TX_ACT_ENA_T0 = 1,
						/* PWM_TPIC */
						.tBit.DSSS_ENA_T1 = 1,
						.tBit.PRE_ENA_T1 = 1,
						.tBit.ACT_ENA_T1 = 1,
						.tBit.LFD_TX_ACT_ENA_T1 = 1,
						.tBit.T_2 = 0,
					},
				},
			},
			.tI2C_Conf =
			{
				.ucDeviceAddr = I2C_SLAVE_ADDR,
			},
		},
		.tModule =
		{
			.bIsSwapXY_ = NO,
			.bIsFlipX_ = NO,
			.ucTxLessCol_ = 0,
			.ucTxLessRow_ = 0,
			.ucScreenCol_ = COL_MAX,
			.ucScreenRow_ = ROW_MAX,

//			.tSRIC_Conf =
//			{
//#if (CUSTOMER == MODEL_LGD_SW92400)
//				.R0_RegVal_Active =
//				{
//					.CFGR_MD_IDLE       = 0x0010,
//					.CFGR_SNSR_STR      = 0x0000,
//					.CFGR_MD_GENERAL    = 0xAA92,
//					.CFGR_AIP_ADC       = 0x357F,
//#if (USED_130K_MAINFREQ)
//					.CFGR_SSU_CTRL      = 0x9367,//0x9357
//					.CFGR_CH01_CR       = 0x08A2,
//					.CFGR_CH23_CR       = 0x08A2,
//					.CFGR_CH45_CR       = 0x08A2,
//					.CFGR_CH67_CR       = 0x08A2,
//					.CFGR_CH89_CR       = 0x08A2,
//					.CFGR_CH0_EDG_CR    = 0x08A2,
//					.CFGR_CH1_EDG_CR    = 0x08A2,
//					.CFGR_CH2_EDG_CR    = 0x08A2,
//					.CFGR_CH3_EDG_CR    = 0x08A2,
//					.CFGR_CH4_EDG_CR    = 0x08A2,
//					.CFGR_CH5_EDG_CR    = 0x08A2,
//					.CFGR_CH6_EDG_CR    = 0x08A2,
//					.CFGR_CH7_EDG_CR    = 0x08A2,
//					.CFGR_CH8_EDG_CR    = 0x08A2,
//					.CFGR_CH9_EDG_CR    = 0x08A2,
//					.CFGR_TSYNC_NUM0    = 0x0700,
//					.CFGR_TSYNC_NUM1    = 0x0700,
//					.CFGR_TSYNC_DMMY    = 0x0000,
//					.CFGR_PWM_NUM0      = 0x0105,
//					.CFGR_PWM_NUM1      = 0x0810,//0x070E
//#else
//					.CFGR_SSU_CTRL      = 0x9367,//0x9357
//					.CFGR_CH01_CR       = 0x030C,
//					.CFGR_CH23_CR       = 0x030C,
//					.CFGR_CH45_CR       = 0x030C,
//					.CFGR_CH67_CR       = 0x030C,
//					.CFGR_CH89_CR       = 0x030C,
//					.CFGR_CH0_EDG_CR    = 0x030C,
//					.CFGR_CH1_EDG_CR    = 0x030C,
//					.CFGR_CH2_EDG_CR    = 0x030C,
//					.CFGR_CH3_EDG_CR    = 0x030C,
//					.CFGR_CH4_EDG_CR    = 0x030C,
//					.CFGR_CH5_EDG_CR    = 0x030C,
//					.CFGR_CH6_EDG_CR    = 0x030C,
//					.CFGR_CH7_EDG_CR    = 0x030C,
//					.CFGR_CH8_EDG_CR    = 0x030C,
//					.CFGR_CH9_EDG_CR    = 0x030C,
//					.CFGR_TSYNC_NUM0    = 0x0700,
//					.CFGR_TSYNC_NUM1    = 0x0700,
//					.CFGR_TSYNC_DMMY    = 0x0000,
//					.CFGR_PWM_NUM0      = 0x0105,
//					.CFGR_PWM_NUM1      = 0x060C,//0x070E
//#endif /* USED_130K_MAINFREQ */
//					.CFGR_CMUX_NORM     = 0xB100,
//					.CFGR_CMUX_NOISE    = 0x014A,
//					.CFGR_COL_NUM       = 0x5540,
//					.CFGR_OUTER         = 0x4000,
//					.CFGR_DIG_GAIN0     = 0x4040,
//					.CFGR_DIG_GAIN1     = 0x4040,
//					.CFGR_NIH_MIN0      = 0x03E8,
//					.CFGR_NIH_MAX0      = 0x044C,
//					.CFGR_NIH_MIN1      = 0x07D0,
//					.CFGR_NIH_MAX1      = 0x0834,
//					.CFGR_NIH_MIN2      = 0x0BB8,
//					.CFGR_NIH_MAX2      = 0x0C1C,
//					.CFGR_NIH_MIN3      = 0x0FA0,
//					.CFGR_NIH_MAX3      = 0x0FFF,
//					.CFGR_NIH_RDAT0     = 0x0000,
//					.CFGR_NIH_RDAT1     = 0x0000,
//					.CFGR_NIH_RDAT2     = 0x0000,
//					.CFGR_NIH_RDAT3     = 0x0000,
//					.CFGR_NIH_STD       = 0x2040,
//					.CFGR_SHA_STR       = 0x0011,
//					.CFGR_DIG_GAIN2     = 0x4040,
//					.CFGR_PHTH0_WIDTH   = 0x0001,
//					.CFGR_PHT_SEL       = 0x0011,
//					.CFGR_RSTP_WIDTH    = 0x0002,
//					.CFGR_VCR_STR       = 0x0680,
//					.CFGR_VCR_CTRL      = 0x0024,
//					.CFGR_VCR_MD2       = 0x0F08,
//					.CFGR_CHIP0_LEN     = 0x0032,
//					.CFGR_TEST_OPT      = 0x0000,
//					.CFGR_DAC_IN        = 0x0000,
//					.CFGR_DAC_CNT       = 0x0190,
//					.CFGR_RSVD0         = 0x0000,
//					.CFGR_RSVD1         = 0x0000,
//					.CFGR_RSVD2         = 0xFFFF,
//					.CFGR_RSVD3         = 0xFFFF,
//				},
//				.R1_RegVal_Active =
//				{
//					.CFGR_MD_IDLE       = 0x0010,
//					.CFGR_SNSR_STR      = 0x0000,
//					.CFGR_MD_GENERAL    = 0xAA92,
//					.CFGR_AIP_ADC       = 0x357F,
//					.CFGR_SSU_CTRL      = 0x9357,
//					.CFGR_CH01_CR       = 0x030C,
//					.CFGR_CH23_CR       = 0x030C,
//					.CFGR_CH45_CR       = 0x030C,
//					.CFGR_CH67_CR       = 0x030C,
//					.CFGR_CH89_CR       = 0x030C,
//					.CFGR_CH0_EDG_CR    = 0x030C,
//					.CFGR_CH1_EDG_CR    = 0x030C,
//					.CFGR_CH2_EDG_CR    = 0x030C,
//					.CFGR_CH3_EDG_CR    = 0x030C,
//					.CFGR_CH4_EDG_CR    = 0x030C,
//					.CFGR_CH5_EDG_CR    = 0x030C,
//					.CFGR_CH6_EDG_CR    = 0x030C,
//					.CFGR_CH7_EDG_CR    = 0x030C,
//					.CFGR_CH8_EDG_CR    = 0x030C,
//					.CFGR_CH9_EDG_CR    = 0x030C,
//					.CFGR_TSYNC_NUM0    = 0x0700,
//					.CFGR_TSYNC_NUM1    = 0x0700,
//					.CFGR_TSYNC_DMMY    = 0x0000,
//					.CFGR_PWM_NUM0      = 0x0105,
//					.CFGR_PWM_NUM1      = 0x060C,//0x070E
//					.CFGR_CMUX_NORM     = 0xB100,
//					.CFGR_CMUX_NOISE    = 0x014A,
//					.CFGR_COL_NUM       = 0x5540,
//					.CFGR_OUTER         = 0x4000,
//					.CFGR_DIG_GAIN0     = 0x4040,
//					.CFGR_DIG_GAIN1     = 0x4040,
//					.CFGR_NIH_MIN0      = 0x03E8,
//					.CFGR_NIH_MAX0      = 0x044C,
//					.CFGR_NIH_MIN1      = 0x07D0,
//					.CFGR_NIH_MAX1      = 0x0834,
//					.CFGR_NIH_MIN2      = 0x0BB8,
//					.CFGR_NIH_MAX2      = 0x0C1C,
//					.CFGR_NIH_MIN3      = 0x0FA0,
//					.CFGR_NIH_MAX3      = 0x0FFF,
//					.CFGR_NIH_RDAT0     = 0x0000,
//					.CFGR_NIH_RDAT1     = 0x0000,
//					.CFGR_NIH_RDAT2     = 0x0000,
//					.CFGR_NIH_RDAT3     = 0x0000,
//					.CFGR_NIH_STD       = 0x2040,
//					.CFGR_SHA_STR       = 0x0011,
//					.CFGR_DIG_GAIN2     = 0x4040,
//					.CFGR_PHTH0_WIDTH   = 0x0001,
//					.CFGR_PHT_SEL       = 0x0011,
//					.CFGR_RSTP_WIDTH    = 0x0002,
//					.CFGR_VCR_STR       = 0x0680,
//					.CFGR_VCR_CTRL      = 0x0024,
//					.CFGR_VCR_MD2       = 0x0F08,
//					.CFGR_CHIP0_LEN     = 0x0032,
//					.CFGR_TEST_OPT      = 0x0000,
//					.CFGR_DAC_IN        = 0x0000,
//					.CFGR_DAC_CNT       = 0x0190,
//					.CFGR_RSVD0         = 0x0000,
//					.CFGR_RSVD1         = 0x0000,
//					.CFGR_RSVD2         = 0xFFFF,
//					.CFGR_RSVD3         = 0xFFFF,
//				},
//#elif (CUSTOMER == MODEL_LGD_SW97400B)
//				SW97400B_REGISTER_VALUE_ACTIVE
//#if USED_LPWG_MODE_CONTROL
//				SW97400B_REGISTER_VALUE_LPWG
//#endif /* USED_LPWG_MODE_CONTROL */
//#else /* (CUSTOMER == MODEL_LGD_LX98405) */
////				LX98405_REGISTER_VALUE_ACTIVE
//#if USED_LPWG_MODE_CONTROL
//				SW97400B_REGISTER_VALUE_LPWG
//#endif /* USED_LPWG_MODE_CONTROL */
//#endif /* (CUSTOMER == MODEL_LGD_SW92400) */
//			}
		}
	},
	.vtParamModeConf =
	{
		[PARAM_MODE_NORMAL] =
		{
			.tAlgorithm =
			{
				.BaseLine =
				{
					.cNormalizeDelta = YES,
					.bDSP_A = YES,
					.ucDiscardFrameNum = 7,
					.ucInitialFrameNum = 5,
					.usIIRCoef = 96,
					.sBlockPosThd = 20,
					.sBlockNegThd = -20,
					.sAccumPosSumThd = 20,
					.sAccumNegSumThd = -20,
					.sIdle_BlockPosThd = 					60,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_BlockPosThd,
					.sIdle_BlockNegThd = 					-60,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_BlockNegThd,
					.sIdle_SeedThd = 						80,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_SeedThd,
					.sIdle_PosTotalSumThd = 				200,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_PosTotalSumThd,
					.sIdle_NegTotalSumThd = 				-200,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_NegTotalSumThd,
					.iRecalCond1_PosSum_Thd = 0,
					.iRecalCond1_AccSum_Thd = -1000,
					.iRecalCond2_AccSum_Thd = -200,
					.ucRecalCond1_WaitCnt = 2,
					.ucRecalCond2_WaitCnt = 0,
					.bFingerBaseTracking		= 			1,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bFingerBaseTracking,
					.bFullFingerBaseTracking			=	1,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bFullFingerBaseTracking,
				},
				.SensingFilter =
				{
					.ucLineFilter = 4,						//0: OFF, 1: horizontal, 2: vertical 3: both
					.sLineFilterUpLimit = 50,
					.sLineFilterLowLimit = -50,
					.ucLineFilterColOffset = 2,			// When Use AVG DSP_A Linefilter for Pen
					.ucMinDeltaTh = 						0,//PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucMinDeltaTh,
					.sLineFilterUpLimit_Idle =				100,//PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterUpLimit_Idle,
					.sLineFilterLowLimit_Idle =				-100,//PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterLowLimit_Idle,
					.ucFilterMaxRow = 3,
					.ucFilterMaxCol = 7,
					.ucFilterLocalRow = 1,
					.ucFilterLocalCol = 2,
					.ucFilterLocal_Min_Thd = 10,
					.ucFilterLocal_Max_Thd = 20,
				},
				.Label =
				{
#if USED_WINDOW_10_QE_BOE
					.usSeedBase = 40,//95,//90,
					.ucSeedSlope = 3,
					.ucLabelNoiseThd = 5,
					.bExpand = YES,
					.bSplitSearchDirc_4_On = YES,
					.usSmallNodeCnt = 16,//12,
					.usMediumNodeCnt = 42,//32,
					.ucMergeSmallThdPer = 95,//90,//80, //85,
					.ucMergeMediumThdPer = 85,//80,//70,//70,//70,
					.ucMergeSmallDiagThdPer = 95,//90,//70,//70,
					.ucMergeMediumDiagThdPer = 85,//80,//80,//80,//80,
#else /* USED_WINDOW_10_QE_BOE */
					.usSeedBase = 15,//80,
					.ucSeedSlope = 3,
					.ucLabelNoiseThd = 5,
					.bExpand = YES,
					.bSplitSearchDirc_4_On = YES,
					.usSmallNodeCnt = 12,
					.usMediumNodeCnt = 40,
					.ucMergeSmallThdPer = 50,//50,
					.ucMergeMediumThdPer = 60,//85,
					.ucMergeSmallDiagThdPer = 70,
					.ucMergeMediumDiagThdPer = 90,
#endif /* USED_WINDOW_10_QE_BOE */
					.usLocalSeedBase = 20,
					.ucLocalSeedSlope = 0,
					.usLocalSmallNodeCnt = 12,
					.usLocalMediumNodeCnt = 32,
					.ucLocalMergeSmallThdPer = 85,
					.ucLocalMergeMediumThdPer = 70,
#if USED_NOISE_HOPPING_FREQ
					.usLabelPeakValleyDiffTh	= 0,
					.usLabelPeakDiffTh			= 0,
					.usMergeLabelSizeTh			= 0,
#endif /* USED_NOISE_HOPPING_FREQ */
				},
				.Coord =
				{
					.usDistThdMovingToStationary = 32,
					.usDistThdStationaryToMoving = 140,
#if USED_ONLY_BOE_TEST_EQU
					.lMoveSmoothingLevel = 13,//13,//9,
#else /* USED_ONLY_BOE_TEST_EQU */
					.lMoveSmoothingLevel = 8,
#endif /* USED_ONLY_BOE_TEST_EQU */
#if (VECTOR_PREDICTION_EN == YES)
					.ucVectorPredictionCoef =				100,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucVectorPredictionCoef,
#endif
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
					.ucFullFingerInterpolation_On = 		3,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFullFingerInterpolation_On,
					.sInterpolationWeight		=			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sInterpolationWeight,					// For Win10Cer Reporting rate test & Duplicate packets error of Jitter test, HanCH
#endif
					.ucFirstMoveEventTHD = 5,
					.ucMoveEventTHD = 20,
					.sFingerGlobalCoordiXResolutionOffset = 0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiXResolutionOffset,
					.sFingerGlobalCoordiYResolutionOffset = 0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset,
					.sFingerGlobalCoordiOffsetX =        	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetX,
					.sFingerGlobalCoordiOffsetY =        	-10,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetY,
#if (FingerGlobalCoordiY_2Region_Set == YES)
					.sFingerGlobalCoordiY_2Region_boundary = 	PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiY_2Region_boundary,
					.sFingerGlobalCoordiYResolutionOffset1 =	PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset1,
					.sFingerGlobalCoordiOffsetY1 =				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetY1,					
#endif
#if (SMOOTH_PASTORG_INTER_EN == YES)
					.ucSmoothPastOrgInter =					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmoothPastOrgInter,
#endif
					.cDisSmoothOffset =						1,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_cDisSmoothOffset,
					.bFingerMeanSmoothing =					1,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bFingerMeanSmoothing,				
					.ucWinCertAssistance = 5,		//0 : Off, 1 : LGD MNT 27", 2 : LGD Kiosk //kwhan
					.ucWinCertModeDebCnt = 1,
					.ucWinCertModeVectorPredictionCoef = 200,
					.ucTouchCountMax = 3,			//LGD MNT 27" : 3, LGD Kiosk 43",55" : 30
					.ucMaxExtendFrameNum = 10,		//LGD MNT 27" : 10, LGD Kiosk 43", 55" : 100
					.usFirstDrawingThd			 = 128,
					.ucFirstDrawingCellCnt   = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFirstDrawingCellCnt,
#if (USED_DRUM_ALGO == YES)
					.usDrumTestDist =	500,//250,					//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usDrumTestDist,
#endif
				},
				.CoordTracking =
				{
					.ucDynamicTrackingDistanceMode = 1,		// 0: OFF, 1: LGD MNT 27", 2: LGD Kiosk 43",55"
					.ucFastDrawingMode = YES,
					.usMoveDistanceThd = 20,//50,//10,//4, //2,
					.usFirstMoveDistanceThd = 20,//50,//10, //3,
					.lLargeTouchOnThd = 180,
					.ucLargeTouchOnDebCnt = 0,
					.lMediumTouchOnThd = 120,
					.ucMediumTouchOnDebCnt = 0,
					.lSmallTouchOnThd = 90,
					.ucSmallTouchOnDebCnt = 0,
					.bEdgeDebCntUp = 						0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bEdgeDebCntUp,
					.sFirstTouchOnMaxCellVal = 40,
					.lTouchOffThd = 28,
					.ucMultifingerFirstTouchThDownOffset =	10,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMultifingerFirstTouchThDownOffset,
					.usCenterMatchDistanceThd = 13,//13,
					.sFirstTouchEnable1Touch = 30,	//Enable First touch
					.sFirstTouchEnable2Touch = 22,
					.sFirstTouchEnable3Touch = 19,
					.sFirstTouchEnable4Touch = 17,
					.sFirstTouchEnable5Touch = 17,
					.ucDebCntInner			 = 0,
					.ucDebCntEdge			 = 1,
				},
				.CoordEdge =
				{
					.bExpectClipping_Finger_On = 			1,
					.cEdgeSmoothing_Finger_On = 			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_cEdgeSmoothing_Finger_On,
#if (REMOVE_EDGE_EN == YES)
					.bRemoveEdge = 							0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bRemoveEdge,
					.usRemoveEdgeXdistThd =					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRemoveEdgeXdistThd,
					.usRemoveEdgeYdistThd =					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRemoveEdgeYdistThd,
					.bUsetRealPastSentPos1 = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_bUsetRealPastSentPos1,
					.ucRemoveEdgeVer = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRemoveEdgeVer,					// 0: Old, 1: New
#endif
					.usPostProcessEdgeTH = 		UNIT_DIST << 1,
					.ucPostProcessDisTH =		48,					
					.ucPostProcessExpendDiv =	1,					
					.cPostProcessEndMargin =	50,					
					.bPostProcessInterpolationMode		=   0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bPostProcessInterpolationMode,
					.usOutInDrawEdgeTh = 					256,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usOutInDrawEdgeTh,
					.ucOutInDrawDisTh = 					64,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucOutInDrawDisTh,
					.bUseNewCippingCond = 					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bUseNewCippingCond,
				},
				.EdgeExpand =
				{
		#if (MULTI_EDGE_COEF_EN == YES)
					.bUseMultiEdgeCoef =					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bUseMultiEdgeCoef,
					.usSmallTouchMaxDeltaThd = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usSmallTouchMaxDeltaThd,
					.ucSmallTouchCellCntThd = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchCellCntThd,
					.ucSmallTouchHeightThd = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchHeightThd,
					.ucSmallTouchWidthThd = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchWidthThd,
		#endif
#if USED_WINDOW_10_QE_BOE
					.ucLeftEdgeExpand = 64 + 10,
					.ucRightEdgeExpand = 64 + 8,
					.ucTopEdgeExpand = 64+10,//64 + 36,
					.ucBottomEdgeExpand = 64+8,//64 + 32,
#else /* USED_WINDOW_10_QE_BOE */
					.ucLeftEdgeExpand = 64 + 30,
					.ucRightEdgeExpand = 64 + 30,
#if USED_ONLY_BOE_TEST_EQU
					.ucTopEdgeExpand = 64+5,//64 + 36,
					.ucBottomEdgeExpand = 64+4,//64 + 32,
#else /* USED_ONLY_BOE_TEST_EQU */
					.ucTopEdgeExpand = 64 + 22,
					.ucBottomEdgeExpand = 64 + 27,
#endif /* USED_ONLY_BOE_TEST_EQU */
#endif/* USED_WINDOW_10_QE_BOE */
		#if (MULTI_EDGE_COEF_EN == YES)
					.ucLeftEdgeExpand_small = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLeftEdgeExpand_small,
					.ucRightEdgeExpand_small = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRightEdgeExpand_small,
					.ucTopEdgeExpand_small = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTopEdgeExpand_small,
					.ucBottomEdgeExpand_small = 			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucBottomEdgeExpand_small,
					.ucLeftEdgeExpand_medium = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLeftEdgeExpand_medium,
					.ucRightEdgeExpand_medium = 			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRightEdgeExpand_medium,
					.ucTopEdgeExpand_medium = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTopEdgeExpand_medium,
					.ucBottomEdgeExpand_medium = 			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucBottomEdgeExpand_medium,
		#endif
					.sXExpandStartOffset = 					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sXExpandStartOffset,
					.sYExpandStartOffset = 					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sYExpandStartOffset,
					.usLabelEdgeExpandMode = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLabelEdgeExpandMode,				//0: max_d = 100, 1: max_d = ulStrength (MAX), else: max_d = usLabelEdgeExpandMode
					.usLeftEdgeExpand_Offset = 0,
					.usRightEdgeExpand_Offset = 0,
					.usTopEdgeExpand_Offset = 0,
					.usBottomEdgeExpand_Offset = 0,
					.usLeftEdgeExpand_Scale =	30,	//300,//128,
					.usRightEdgeExpand_Scale = 	30,	//300,
					.usTopEdgeExpand_Scale = 	5,	//300,
					.usBottomEdgeExpand_Scale = 5,//300,	//128,
		#if (BIG_FINGER_EDGE_EXPAND_ALGO_EN == YES)
					.usLeftEdgeExpand_MaxD		=			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLeftEdgeExpand_MaxD,				//For Win10Cer 16Phi & 7Phi Edge Test
					.usRightEdgeExpand_MaxD     =			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRightEdgeExpand_MaxD,
					.usTopEdgeExpand_MaxD       =			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usTopEdgeExpand_MaxD,
					.usBottomEdgeExpand_MaxD    =			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBottomEdgeExpand_MaxD,
					.usBigFingerEdgeExpandParam1	=		0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam1,
					.usBigFingerEdgeExpandParam2	=		0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam2,
					.usBigFingerEdgeExpandParam3	=		0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam3,
		#endif
		#if (BIG_FINGER_EDGE_ACC_TEST_ALGO_EN == YES)
					.ucEdgeReportDelayCnt			=		0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucEdgeReportDelayCnt,//10,
					.usBigFingerEdgeTest_MoveEventTHD_X	=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTest_MoveEventTHD_X,
					.usBigFingerEdgeTest_MoveEventTHD_Y	=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTest_MoveEventTHD_Y,
					.usBigFingerEdgeTestClippingTop		=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingTop,
					.usBigFingerEdgeTestClippingBottom	=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingBottom,
					.usBigFingerEdgeTestClippingLeft	=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingLeft,
					.usBigFingerEdgeTestClippingRight	=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingRight,
					.bFingerCornerTestClippingOn		=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bFingerCornerTestClippingOn,
		#endif
					.bDoNotExpandPos					=	0,
				},
				.ParaEdgeSetVal =
				{
					.th0 							= 		2	,
					.top_mul0 						= 		26  ,
					.top_SR0 						= 		5   ,
					.top_size_th					= 		16  ,
					.top_apply_th					= 		255   ,
					.bottom_mul0					= 		27  ,
					.bottom_SR0						= 		5   ,
					.bottom_size_th 				= 		16  ,
					.bottom_apply_th				= 		255,
					.left_mul0						= 		26  ,
					.left_SR0						= 		5   ,
					.left_size_th 					= 		16  ,
					.left_apply_th					= 		255  ,
					.right_mul0						= 		27  ,
					.right_SR0						= 		5   ,
					.right_size_th 					= 		16  ,
					.right_apply_th					= 		255	,
					.top_max_sum 					= 		230,
					.bottom_max_sum 				= 		200,
					.left_max_sum 					= 		190,
					.right_max_sum 					= 		190,
					.top_max_sum_corner 			= 		85,
					.bottom_max_sum_corner			= 		85,
					.left_max_sum_corner 			= 		100,
					.right_max_sum_corner 			= 		100,
					.top_max_sum_Big 				= 		1500,
					.bottom_max_sum_Big 			= 		1500,
					.left_max_sum_Big 				= 		1500,
					.right_max_sum_Big 				= 		1500,
					.corner_size_th					=		9	,
				},            
				.Palm =
				{
					.ucPalmDetectionOn = 					2,  //0 : off, 1 : Version 1, 2 : Version 2
					.usPalmLevel = 							20,  
#if (PalmFirstDetectionShift == YES)
					.ucPalmLevelShift = 				PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmLevelShift,
#endif
					.ucPalm_PALM_CONNECT_DIST = 			5,  
					.ucPalm_PALM_REGION_UPDATE_PERIOD =		10,  
					.ucPalm_TOUCHDOWNFRAMEMAX = 			0,  
					.ucPalm_TOUCHDOWNSLOPETHRESHOLD = 		200,  
					.ucPalm_IGNOREFRAMENUM = 				0,  
					.ucPalm_KEEPPALMREGIONFRAME = 			50,
#if (PalmDrawingOn_En == YES)
					.ucPalmDrawingOn = 						NO,
#endif  
					.bPalm_WholeTouchRemove = 				NO,  
#if (PalmCandidateTouchCut_EN == YES)
					.usPalmCandiStdTh 					=	PARAMSET_NORMAL_MODE_1_ALGO_Palm_usPalmCandiStdTh,
					.ucPalmCandiShapeMatchingTh			=	PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmCandiShapeMatchingTh,	
					.ucPalmCandiDeltaTh					=	PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmCandiDeltaTh,
#endif
				},				
#if (USED_NOISE_HOPPING_FREQ || LGD_ERROR_FRAME_PROCESS_EN)
				.Noise =
				{
					.ucNoiseDetectionMode = 2,
					.ucDiscardFrameNum = 2,
					.ucCellCntThd = 1,
					.ucHoppingThd = 30,
					.usRawDataThd = 100,			//abnormal rawdata threshold
					.sDeltaDataThd = -20,			//abnormal delta threshold
					.ucErrorFrameProcess = 2,		//0 : OFF, 1 : LGD MNT 27", 2 : LGD Kiosk 43"55"
					.ucHoppingMoveDistanceThd = 4,
					.ucNoiseDetectMaxType = 0,
					.bInitAddHoppingThd = 0,
					.ucNoiseStartThd = 0,
					.ucNoiseStartCntThd = 0,
				},
#endif /* (USED_NOISE_HOPPING_FREQ || LGD_ERROR_FRAME_PROCESS_EN) */
				.usIdleTouchThd = 60,
			},
			.tModule =
			{
				.ucOvrShift = 4,//5,//3,//2,
				.ucIdleOvrShift = 5,
				.ucLocalOvrShift = 2,
			},
		}, /* PARAM_MODE_NORMAL */
		[PARAM_MODE_NOISE] =
		{
			.tAlgorithm =
			{
				.BaseLine =
				{
					.cNormalizeDelta = YES,
					.bDSP_A = YES,
					.ucDiscardFrameNum = 5,
					.ucInitialFrameNum = 5,
					.usIIRCoef = 40,
					.sBlockPosThd = 20,
					.sBlockNegThd = -24,
					.sAccumPosSumThd = 12,
					.sAccumNegSumThd = -12,
					.sIdle_BlockPosThd = 					60,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_BlockPosThd,
					.sIdle_BlockNegThd = 					-60,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_BlockNegThd,
					.sIdle_SeedThd = 						80,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_SeedThd,
					.sIdle_PosTotalSumThd = 				200,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_PosTotalSumThd,
					.sIdle_NegTotalSumThd = 				-200,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_NegTotalSumThd,
					.iRecalCond1_PosSum_Thd = 0,
					.iRecalCond1_AccSum_Thd = -1000,
					.iRecalCond2_AccSum_Thd = -200,
					.ucRecalCond1_WaitCnt = 2,
					.ucRecalCond2_WaitCnt = 0,
					.bFingerBaseTracking		= 			1,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bFingerBaseTracking,
					.bFullFingerBaseTracking			=	1,//PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bFullFingerBaseTracking,
				},
				.SensingFilter =
				{
					.ucLineFilter = 1,
					.sLineFilterUpLimit = 50,
					.sLineFilterLowLimit = -50,
					.ucLineFilterColOffset = 2,			// When Use AVG DSP_A Linefilter for Pen
					.ucMinDeltaTh = 						0,//PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucMinDeltaTh,
					.sLineFilterUpLimit_Idle =				100,//PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterUpLimit_Idle,
					.sLineFilterLowLimit_Idle =				-100,//PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterLowLimit_Idle,
					.ucFilterMaxRow = 3,
					.ucFilterMaxCol = 7,
					.ucFilterLocalRow = 1,
					.ucFilterLocalCol = 2,
					.ucFilterLocal_Min_Thd = 10,
					.ucFilterLocal_Max_Thd = 20,
				},
				.Label =
				{
#if USED_WINDOW_10_QE_BOE
					.usSeedBase = 40,//95,//90,
					.ucSeedSlope = 3,
					.ucLabelNoiseThd = 5,
					.bExpand = YES,
					.bSplitSearchDirc_4_On = YES,
					.usSmallNodeCnt = 16,//12,
					.usMediumNodeCnt = 42,//32,
					.ucMergeSmallThdPer = 95,//90,//80, //85,
					.ucMergeMediumThdPer = 85,//80,//70,//70,//70,
					.ucMergeSmallDiagThdPer = 95,//90,//70,//70,
					.ucMergeMediumDiagThdPer = 85,//80,//80,//80,//80,
#else /* USED_WINDOW_10_QE_BOE */
					.usSeedBase = 15,//80,
					.ucSeedSlope = 3,
					.ucLabelNoiseThd = 5,
					.bExpand = YES,
					.bSplitSearchDirc_4_On = YES,
					.usSmallNodeCnt = 10,
					.usMediumNodeCnt = 40,
					.ucMergeSmallThdPer = 50,//88,
					.ucMergeMediumThdPer = 85,//95,
					.ucMergeSmallDiagThdPer = 70,
					.ucMergeMediumDiagThdPer = 90,
#endif /* USED_WINDOW_10_QE_BOE */
					.usLocalSeedBase = 20,
					.ucLocalSeedSlope = 0,
					.usLocalSmallNodeCnt = 12,
					.usLocalMediumNodeCnt = 32,
					.ucLocalMergeSmallThdPer = 85,
					.ucLocalMergeMediumThdPer = 70,
#if USED_NOISE_HOPPING_FREQ
					.usLabelPeakValleyDiffTh	= 0,
					.usLabelPeakDiffTh			= 0,
					.usMergeLabelSizeTh			= 0,
#endif /* USED_NOISE_HOPPING_FREQ */
				},
				.Coord =
				{
					.usDistThdMovingToStationary = 32,
					.usDistThdStationaryToMoving = 100,
#if USED_ONLY_BOE_TEST_EQU
					.lMoveSmoothingLevel = 13,//13,//9,
#else /* USED_ONLY_BOE_TEST_EQU */
					.lMoveSmoothingLevel = 7,
#endif /* USED_ONLY_BOE_TEST_EQU */
#if (VECTOR_PREDICTION_EN == YES)
					.ucVectorPredictionCoef =				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucVectorPredictionCoef,
#endif
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
					.ucFullFingerInterpolation_On = 		3,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFullFingerInterpolation_On,
					.sInterpolationWeight		=			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sInterpolationWeight,					// For Win10Cer Reporting rate test & Duplicate packets error of Jitter test, HanCH
#endif
					.ucFirstMoveEventTHD = 5,
					.ucMoveEventTHD = 20,
					.sFingerGlobalCoordiXResolutionOffset = 0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiXResolutionOffset,
					.sFingerGlobalCoordiYResolutionOffset = 0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset,
					.sFingerGlobalCoordiOffsetX =        	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetX,
					.sFingerGlobalCoordiOffsetY =        	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetY,
#if (FingerGlobalCoordiY_2Region_Set == YES)
					.sFingerGlobalCoordiY_2Region_boundary = 	PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiY_2Region_boundary,
					.sFingerGlobalCoordiYResolutionOffset1 =	PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset1,
					.sFingerGlobalCoordiOffsetY1 =				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetY1,					
#endif
#if (SMOOTH_PASTORG_INTER_EN == YES)
					.ucSmoothPastOrgInter =					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmoothPastOrgInter,
#endif
					.cDisSmoothOffset =						1,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_cDisSmoothOffset,
					.bFingerMeanSmoothing =					1,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bFingerMeanSmoothing,				
					.ucWinCertAssistance = 5,
					.ucWinCertModeDebCnt = 1,
					.ucWinCertModeVectorPredictionCoef = 200,
					.ucTouchCountMax = 3,			//LGD MNT 27" : 3, LGD Kiosk 43",55" : 30
					.ucMaxExtendFrameNum = 10,		//LGD MNT 27" : 10, LGD Kiosk 43", 55" : 100
					.usFirstDrawingThd			 = 100,
					.ucFirstDrawingCellCnt   = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFirstDrawingCellCnt,
#if (USED_DRUM_ALGO == YES)
					.usDrumTestDist =	250,					//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usDrumTestDist,
#endif
				},
				.EdgeExpand =
				{
		#if (MULTI_EDGE_COEF_EN == YES)
					.bUseMultiEdgeCoef =					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bUseMultiEdgeCoef,
					.usSmallTouchMaxDeltaThd = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usSmallTouchMaxDeltaThd,
					.ucSmallTouchCellCntThd = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchCellCntThd,
					.ucSmallTouchHeightThd = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchHeightThd,
					.ucSmallTouchWidthThd = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchWidthThd,
		#endif
#if USED_WINDOW_10_QE_BOE
					.ucLeftEdgeExpand = 64 + 10,
					.ucRightEdgeExpand = 64 + 8,
					.ucTopEdgeExpand = 64+10,//64 + 36,
					.ucBottomEdgeExpand = 64+8,//64 + 32,
#else /* USED_WINDOW_10_QE_BOE */
					.ucLeftEdgeExpand = 64 + 0,
					.ucRightEdgeExpand = 64 + 0,
#if USED_ONLY_BOE_TEST_EQU
					.ucTopEdgeExpand = 64+5,//64 + 36,
					.ucBottomEdgeExpand = 64+4,//64 + 32,
#else /* USED_ONLY_BOE_TEST_EQU */
					.ucTopEdgeExpand = 64 + 0,
					.ucBottomEdgeExpand = 64 + 0,
#endif /* USED_ONLY_BOE_TEST_EQU */
#endif/* USED_WINDOW_10_QE_BOE */
		#if (MULTI_EDGE_COEF_EN == YES)
					.ucLeftEdgeExpand_small = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLeftEdgeExpand_small,
					.ucRightEdgeExpand_small = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRightEdgeExpand_small,
					.ucTopEdgeExpand_small = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTopEdgeExpand_small,
					.ucBottomEdgeExpand_small = 			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucBottomEdgeExpand_small,
					.ucLeftEdgeExpand_medium = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLeftEdgeExpand_medium,
					.ucRightEdgeExpand_medium = 			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRightEdgeExpand_medium,
					.ucTopEdgeExpand_medium = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTopEdgeExpand_medium,
					.ucBottomEdgeExpand_medium = 			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucBottomEdgeExpand_medium,
		#endif
					.sXExpandStartOffset = 					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sXExpandStartOffset,
					.sYExpandStartOffset = 					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_sYExpandStartOffset,
					.usLabelEdgeExpandMode = 				0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLabelEdgeExpandMode,				//0: max_d = 100, 1: max_d = ulStrength (MAX), else: max_d = usLabelEdgeExpandMode
					.usLeftEdgeExpand_Offset = 0,
					.usRightEdgeExpand_Offset = 0,
					.usTopEdgeExpand_Offset = 0,
					.usBottomEdgeExpand_Offset = 0,
					.usLeftEdgeExpand_Scale =	0,	//300,//128,
					.usRightEdgeExpand_Scale = 	0,	//300,
					.usTopEdgeExpand_Scale = 	0,	//300,
					.usBottomEdgeExpand_Scale = 0,//300,	//128,
		#if (BIG_FINGER_EDGE_EXPAND_ALGO_EN == YES)
					.usLeftEdgeExpand_MaxD		=			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLeftEdgeExpand_MaxD,				//For Win10Cer 16Phi & 7Phi Edge Test
					.usRightEdgeExpand_MaxD     =			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRightEdgeExpand_MaxD,
					.usTopEdgeExpand_MaxD       =			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usTopEdgeExpand_MaxD,
					.usBottomEdgeExpand_MaxD    =			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBottomEdgeExpand_MaxD,
					.usBigFingerEdgeExpandParam1	=		0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam1,
					.usBigFingerEdgeExpandParam2	=		0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam2,
					.usBigFingerEdgeExpandParam3	=		0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam3,
		#endif
		#if (BIG_FINGER_EDGE_ACC_TEST_ALGO_EN == YES)
					.ucEdgeReportDelayCnt			=		0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucEdgeReportDelayCnt,//10,
					.usBigFingerEdgeTest_MoveEventTHD_X	=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTest_MoveEventTHD_X,
					.usBigFingerEdgeTest_MoveEventTHD_Y	=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTest_MoveEventTHD_Y,
					.usBigFingerEdgeTestClippingTop		=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingTop,
					.usBigFingerEdgeTestClippingBottom	=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingBottom,
					.usBigFingerEdgeTestClippingLeft	=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingLeft,
					.usBigFingerEdgeTestClippingRight	=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingRight,
					.bFingerCornerTestClippingOn		=	0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bFingerCornerTestClippingOn,
		#endif
				},
				.CoordTracking =
				{
					.ucDynamicTrackingDistanceMode = 1,
					.ucFastDrawingMode = YES,
					.usMoveDistanceThd = 20,//50,//10,//4, //2,
					.usFirstMoveDistanceThd = 20,//50,//10, //3,
					.lLargeTouchOnThd = 180,
					.ucLargeTouchOnDebCnt = 0,
					.lMediumTouchOnThd = 120,
					.ucMediumTouchOnDebCnt = 0,
					.lSmallTouchOnThd = 90,
					.ucSmallTouchOnDebCnt = 0,
					.bEdgeDebCntUp = 						0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bEdgeDebCntUp,
					.sFirstTouchOnMaxCellVal = 40,
					.lTouchOffThd = 28,
					.ucMultifingerFirstTouchThDownOffset =	10,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMultifingerFirstTouchThDownOffset,
					.usCenterMatchDistanceThd = 13,
					.sFirstTouchEnable1Touch = 90,
					.sFirstTouchEnable2Touch = 80,
					.sFirstTouchEnable3Touch = 75,
					.sFirstTouchEnable4Touch = 70,
					.sFirstTouchEnable5Touch = 60,
					.ucDebCntInner			 = 0,
					.ucDebCntEdge			 = 1,
				},
				.CoordEdge =
				{
					.bExpectClipping_Finger_On = 			0,
					.cEdgeSmoothing_Finger_On = 			0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_cEdgeSmoothing_Finger_On,
#if (REMOVE_EDGE_EN == YES)
					.bRemoveEdge = 							0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bRemoveEdge,
					.usRemoveEdgeXdistThd =					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRemoveEdgeXdistThd,
					.usRemoveEdgeYdistThd =					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRemoveEdgeYdistThd,
					.bUsetRealPastSentPos1 = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_bUsetRealPastSentPos1,
					.ucRemoveEdgeVer = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRemoveEdgeVer,					// 0: Old, 1: New
#endif
					.usPostProcessEdgeTH = 		UNIT_DIST << 1,
					.ucPostProcessDisTH =		48,					
					.ucPostProcessExpendDiv =	1,					
					.cPostProcessEndMargin =	50,		
					.bPostProcessInterpolationMode		=   0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bPostProcessInterpolationMode,
					.usOutInDrawEdgeTh = 					256,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_usOutInDrawEdgeTh,
					.ucOutInDrawDisTh = 					64,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucOutInDrawDisTh,
					.bUseNewCippingCond = 					0,//PARAMSET_NORMAL_MODE_1_ALGO_Coord_bUseNewCippingCond,
				},
				.ParaEdgeSetVal =
				{
					.th0 							= 		2	,
					.top_mul0 						= 		26  ,
					.top_SR0 						= 		5   ,
					.top_size_th					= 		16  ,
					.top_apply_th					= 		255   ,
					.bottom_mul0					= 		27  ,
					.bottom_SR0						= 		5   ,
					.bottom_size_th 				= 		16  ,
					.bottom_apply_th				= 		255,
					.left_mul0						= 		26  ,
					.left_SR0						= 		5   ,
					.left_size_th 					= 		16  ,
					.left_apply_th					= 		255  ,
					.right_mul0						= 		27  ,
					.right_SR0						= 		5   ,
					.right_size_th 					= 		16  ,
					.right_apply_th					= 		255	,
					.top_max_sum 					= 		230,
					.bottom_max_sum 				= 		200,
					.left_max_sum 					= 		190,
					.right_max_sum 					= 		190,
					.top_max_sum_corner 			= 		85,
					.bottom_max_sum_corner			= 		85,
					.left_max_sum_corner 			= 		100,
					.right_max_sum_corner 			= 		100,
					.top_max_sum_Big 				= 		1500,
					.bottom_max_sum_Big 			= 		1500,
					.left_max_sum_Big 				= 		1500,
					.right_max_sum_Big 				= 		1500,
					.corner_size_th					=		9	,
				},      
				.Palm =
				{
					.ucPalmDetectionOn = 					2,  //0 : off, 1 : Version 1, 2 : Version 2
					.usPalmLevel = 							20,  
#if (PalmFirstDetectionShift == YES)
					.ucPalmLevelShift = 				PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmLevelShift,
#endif
					.ucPalm_PALM_CONNECT_DIST = 			5,  
					.ucPalm_PALM_REGION_UPDATE_PERIOD =		10,  
					.ucPalm_TOUCHDOWNFRAMEMAX = 			0,  
					.ucPalm_TOUCHDOWNSLOPETHRESHOLD = 		200,  
					.ucPalm_IGNOREFRAMENUM = 				0,  
					.ucPalm_KEEPPALMREGIONFRAME = 			50,  
#if (PalmDrawingOn_En == YES)
					.ucPalmDrawingOn = 						NO,
#endif  
					.bPalm_WholeTouchRemove = 				NO,  
#if (PalmCandidateTouchCut_EN == YES)
					.usPalmCandiStdTh 					=	PARAMSET_NORMAL_MODE_1_ALGO_Palm_usPalmCandiStdTh,
					.ucPalmCandiShapeMatchingTh			=	PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmCandiShapeMatchingTh,	
					.ucPalmCandiDeltaTh					=	PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmCandiDeltaTh,
#endif
				},				
#if (USED_NOISE_HOPPING_FREQ || LGD_ERROR_FRAME_PROCESS_EN)
				.Noise =
				{
					.ucNoiseDetectionMode = 2,
					.ucDiscardFrameNum = 2,
					.ucCellCntThd = 1,
					.ucHoppingThd = 30,
					.usRawDataThd = 100,			//abnormal rawdata threshold
					.sDeltaDataThd = -20,			//abnormal delta threshold
					.ucErrorFrameProcess = 2,		//0 : OFF, 1 : LGD MNT 27", 2 : LGD Kiosk 43"55"
					.ucHoppingMoveDistanceThd = 4,
					.ucNoiseDetectMaxType = 0,
					.bInitAddHoppingThd = 0,
					.ucNoiseStartThd = 0,
					.ucNoiseStartCntThd = 0,
				},
#endif /* (USED_NOISE_HOPPING_FREQ || LGD_ERROR_FRAME_PROCESS_EN) */
				.usIdleTouchThd = 60,
			},
			.tModule =
			{
				.ucOvrShift = 4,//3,//2,
				.ucIdleOvrShift = 1,
				.ucLocalOvrShift = 2,
			},
		}, /* PARAM_MODE_NOISE */

	}
};
