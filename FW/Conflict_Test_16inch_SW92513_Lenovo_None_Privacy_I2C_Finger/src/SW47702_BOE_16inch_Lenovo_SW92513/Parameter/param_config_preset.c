/******************************************************************************************************
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

#include "param_def.h"
#include "hal_def.h"


const tParamPreMainSet_t ktParamPresetMainConf =
{
#if USED_TOUCH_TUNING_PROCESS
	.tParamTuningConf = 
	{
		.DataType = 0,
		.LocalIndex = 0,
	},
#endif /* USED_TOUCH_TUNING_PROCESS */
	.tParamCommonConf =
	{
		.tApp =
		{
			.ucFrameRate = PARAMSET_CM_APP_ucFrameRate,
			.ucIdleFrameRate = PARAMSET_CM_APP_ucIdleFrameRate,

			.bUsedIdleModeCtrl = PARAMSET_CM_APP_bUsedIdleModeCtrl,
			.ucIdleModeEnterSec = PARAMSET_CM_APP_ucIdleModeEnterSec,
			.ucPenLocalModeEnterSec = PARAMSET_CM_APP_ucPenLocalModeEnterSec,
			.HoppMainRollbackSec = PARAMSET_CM_APP_HoppMainRollbackSec,

			.bUseFreqHopp = PARAMSET_CM_APP_bUseFreqHopp,
			.MainFreq = PARAMSET_CM_APP_MainFreq,
			.HoppFreq1 = PARAMSET_CM_APP_HoppFreq1,
			.HoppFreq2 = PARAMSET_CM_APP_HoppFreq2,

			.ucPenLocalModeChangeFrameCntTHD = 2,//4,
			.ucPenFullModeChangeFrameCntTHD = 4,//2,
		},
		.tAlgorithm =
		{
//			.ucMaxTouch_ = PARAMSET_CM_ALGO_ucMaxTouch_,
//			.ucLabelSearchDir = PARAMSET_CM_ALGO_ucLabelSearchDir,
			.iXResolution = PARAMSET_CM_ALGO_iXResolution,
			.iYResolution = PARAMSET_CM_ALGO_iYResolution,
			
			.iXEdgeNum = PARAMSET_CM_ALGO_iXEdgeNum,
			.iXEdgeDen = PARAMSET_CM_ALGO_iXEdgeDen,
			.iYEdgeNum = PARAMSET_CM_ALGO_iYEdgeNum,
			.iYEdgeDen = PARAMSET_CM_ALGO_iYEdgeDen,
			
			.ucXClipping = PARAMSET_CM_ALGO_ucXClipping,
			.ucYClipping = PARAMSET_CM_ALGO_ucYClipping,
			.ucClippingLeft	   = PARAMSET_CM_ALGO_ucClippingLeft,
			.ucClippingRight   = PARAMSET_CM_ALGO_ucClippingRight,
			.ucClippingTop	   = PARAMSET_CM_ALGO_ucClippingTop,
			.ucClippingBottom  = PARAMSET_CM_ALGO_ucClippingBottom,
			.usPanelXSizeInDmm = PARAMSET_CM_ALGO_usPanelXSizeInDmm,
			.usPanelYSizeInDmm = PARAMSET_CM_ALGO_usPanelYSizeInDmm,
		},
		.tProtocol =
		{
			.ePacketFormatId = PF_NORMAL,
		},
		.tHal =
		{
			.tMSPI_Conf =
			{
				.tMSPIControlConf =
				{
#if IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION
	#if IS_MULTI_PROTOCOL_OPERATION
					[ACTIVEPEN_TYPE_LOCAL_MS] =
					{
	#endif
						.MSPI_LHBCountNum = PARAMSET_MSPI_ControlConf_Local_MS_LHBCount,
						.MSPI_BUF_Panel_ColNum = PARAMSET_MSPI_ControlConf_Local_MS_Buf_Panel_ColNum,
						.ePenPartialIndex =
						{
							PARAMSET_MSPI_ControlConf_Local_MS_1LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_2LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_3LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_4LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_5LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_6LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_7LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_8LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_9LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_10LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_11LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_12LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_13LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_14LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_15LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_MS_16LHB_Pen
						},
						.tMspiFingerMuxScanOrder =
						{
							.ucLocalFingerMUXScanOrderIDX =
							{
								[0] = /* Finger 1st LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_4Mux,
								},
								[1] = /* Finger 2nd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_4Mux,
								},
								[2] = /* Finger 3rd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_4Mux,
								},
								[3] = /* Finger 4th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_4thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_4thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_4thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_4thLHB_4Mux,
								},
								[4] = /* Finger 5th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_5thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_5thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_5thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_5thLHB_4Mux,
								},
								[5] = /* Finger 6th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_6thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_6thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_6thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_6thLHB_4Mux,
								},
							},
							.ucFullFingerMUXScanOrderIDX =
							{
								[0] = /* Finger 1st LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_4Mux,
								},
								[1] = /* Finger 2nd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_4Mux,
								},
								[2] = /* Finger 3rd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_4Mux,
								},
								[3] = /* Finger 4th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_4thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_4thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_4thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_4thLHB_4Mux,
								},
								[4] = /* Finger 5th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_5thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_5thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_5thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_5thLHB_4Mux,
								},
								[5] = /* Finger 6th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_6thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_6thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_6thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_6thLHB_4Mux,
								},
							},
						},
	#if IS_MULTI_PROTOCOL_OPERATION
					},
	#endif
#endif /* IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION */

#if IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION
	#if IS_MULTI_PROTOCOL_OPERATION
					[ACTIVEPEN_TYPE_LOCAL_WGP] =
					{
	#endif
						.MSPI_LHBCountNum = PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_LHBCount,
						.MSPI_BUF_Panel_ColNum = PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_Buf_Panel_ColNum,
						.ePenPartialIndex =
						{
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_1LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_2LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_3LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_4LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_5LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_6LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_7LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_8LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_9LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_10LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_11LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_12LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_13LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_14LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_15LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_16LHB_Pen
						},
						.tMspiFingerMuxScanOrder =
						{
							.ucLocalFingerMUXScanOrderIDX =
							{
								[0] = /* Finger 1st LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_4Mux,
								},
								[1] = /* Finger 2nd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_4Mux,
								},
								[2] = /* Finger 3rd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_4Mux,
								},
								[3] = /* Finger 4th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_4thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_4thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_4thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_4thLHB_4Mux,
								},
								[4] = /* Finger 5th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_5thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_5thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_5thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_5thLHB_4Mux,
								},
								[5] = /* Finger 6th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_6thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_6thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_6thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_6thLHB_4Mux,
								},
							},
							.ucFullFingerMUXScanOrderIDX =
							{
								[0] = /* Finger 1st LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_4Mux,
								},
								[1] = /* Finger 2nd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_4Mux,
								},
								[2] = /* Finger 3rd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_4Mux,
								},
								[3] = /* Finger 4th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_4thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_4thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_4thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_4thLHB_4Mux,
								},
								[4] = /* Finger 5th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_5thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_5thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_5thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_5thLHB_4Mux,
								},
								[5] = /* Finger 6th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_6thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_6thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_6thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_6thLHB_4Mux,
								},
							},
						},
	#if IS_MULTI_PROTOCOL_OPERATION
					},
	#endif
#endif /* IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION */
				},
				.tParam_SPIENA =
				{
					.tBit.spiTxEna0 = PARAMSET_MSPI_ENA_spi_TX_Ena0,
					.tBit.spiTxEna1 = PARAMSET_MSPI_ENA_spi_TX_Ena1,
					.tBit.spiTxEna2 = PARAMSET_MSPI_ENA_spi_TX_Ena2,
					.tBit.spiTxEna3 = PARAMSET_MSPI_ENA_spi_TX_Ena3,
					.tBit.spiTxEna4 = PARAMSET_MSPI_ENA_spi_TX_Ena4,
					.tBit.spiTxEna5 = PARAMSET_MSPI_ENA_spi_TX_Ena5,
					.tBit.spiTxEna6 = PARAMSET_MSPI_ENA_spi_TX_Ena6,
					.tBit.spiTxEna7 = PARAMSET_MSPI_ENA_spi_TX_Ena7,

					.tBit.spiRxEna0 = PARAMSET_MSPI_ENA_spi_RX_Ena0,
					.tBit.spiRxEna1 = PARAMSET_MSPI_ENA_spi_RX_Ena1,
					.tBit.spiRxEna2 = PARAMSET_MSPI_ENA_spi_RX_Ena2,
					.tBit.spiRxEna3 = PARAMSET_MSPI_ENA_spi_RX_Ena3,
					.tBit.spiRxEna4 = PARAMSET_MSPI_ENA_spi_RX_Ena4,
					.tBit.spiRxEna5 = PARAMSET_MSPI_ENA_spi_RX_Ena5,
					.tBit.spiRxEna6 = PARAMSET_MSPI_ENA_spi_RX_Ena6,
					.tBit.spiRxEna7 = PARAMSET_MSPI_ENA_spi_RX_Ena7,

					.tBit.spiTRxEna0 = PARAMSET_MSPI_ENA_spi_TRX_Ena0,
					.tBit.spiTRxEna1 = PARAMSET_MSPI_ENA_spi_TRX_Ena1,
					.tBit.spiTRxEna2 = PARAMSET_MSPI_ENA_spi_TRX_Ena2,
					.tBit.spiTRxEna3 = PARAMSET_MSPI_ENA_spi_TRX_Ena3,
					.tBit.spiTRxEna4 = PARAMSET_MSPI_ENA_spi_TRX_Ena4,
					.tBit.spiTRxEna5 = PARAMSET_MSPI_ENA_spi_TRX_Ena5,
					.tBit.spiTRxEna6 = PARAMSET_MSPI_ENA_spi_TRX_Ena6,
					.tBit.spiTRxEna7 = PARAMSET_MSPI_ENA_spi_TRX_Ena7,
				},
				.tParam_SPISCR =
				{
					.tBit.BITLEN = SPI_BITLEN_HALF_WORD,
					.tBit.DUALACC = SPI_RX_SINGLE_MODE,
					.tBit.DUALBITORD = SPI_RX_DUAL_BIT_ORDER_MOSI_MISO,
					.tBit.TXDORD = SPI_DATA_ORDER_MSB_FIRST,
					.tBit.RXDORD = SPI_DATA_ORDER_MSB_FIRST,
					.tBit.TXCHKSUM_EN = SPI_CHECK_SUM_DISABLE,
					.tBit.RXCHKSUM_EN = SPI_CHECK_SUM_DISABLE,
					.tBit.RXPOS = 0x1,
					.tBit.SCLKDIV = SPI_SCLK_SPEED_3_DIV,
					.tBit.MISO_ZERO_CHK_EN = DISABLE,
				},
			},
			.tPWMDRV_Conf =
			{
				.tPwmControlConf =
				{
#if IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION
	#if IS_MULTI_PROTOCOL_OPERATION
					[ACTIVEPEN_TYPE_LOCAL_MS] =
					{
	#endif
						.tCP_PWMGEN_CR0 =
						{
							.tBit.pwm_gen_enable = DISABLE,
							.tBit.kiosk_mode = 0,
							.tBit.tfd_mode = PWM_TSD_MODE,
							.tBit.continuos_en = PWM_CONTINUOS_MODE,
							.tBit.frame_rate = PWM_FRAME_RATE_DIV_1,
							.tBit.chip_length0 = 30,
							.tBit.chip_length1 = 30,
							.tBit.frame_intr_sel = PWM_FRINTR_LAST_MUX,
							.tBit.pen_mode = PWM_LOCAL_PEN_MODE,
							.tBit.offclk_ctrl_tpic = PWM_OFFCLK_IGNORE,
							.tBit.offclk_ctrl_sric = PWM_OFFCLK_IGNORE,
							.tBit.offclk_ctrl_mux = PWM_OFFCLK_IGNORE,
							.tBit.offclk_ctrl_vgh = PWM_OFFCLK_IGNORE,
							.tBit.offclk_ctrl_gma = PWM_OFFCLK_IGNORE,
							.tBit.offclk_ctrl_en = DISABLE,
							.tBit.pwm_sric_output_en = ENABLE,
							.tBit.pwm_tpic_output_en = ENABLE,
							.tBit.pwm_mux_output_en = DISABLE,
							.tBit.pwm_vgh_output_en = DISABLE,
							.tBit.pwm_gma_output_en = DISABLE,
						},
						.tCP_PWMGEN_CR1 =
						{
							.tBit.fstart_en = PARAMSET_PWMDRV_MPP_PWMGEN_CR1_fstart_en,
							.tBit.skip_num = PARAMSET_PWMDRV_MPP_PWMGEN_CR1_skip_num,
							.tBit.beacon_data_num = PARAMSET_PWMDRV_MPP_PWMGEN_CR1_beacon_data_num,
							.tBit.sric_dummy_num = PARAMSET_PWMDRV_MPP_PWMGEN_CR1_sric_dummy_num,
							.tBit.tpic_dummy_num = PARAMSET_PWMDRV_MPP_PWMGEN_CR1_tpic_dummy_num,
							.tBit.dummy_gap_en = PARAMSET_PWMDRV_MPP_PWMGEN_CR1_dummy_gap_en,
							.tBit.pgap_en = PARAMSET_PWMDRV_MPP_PWMGEN_CR1_pgap_en,
							.tBit.pen_s_pwmnum = PARAMSET_PWMDRV_MPP_PWMGEN_CR1_pen_s_pwmnum,
						},
						.tCP_PWMGEN_CR2 =
						{
							.tBit.pen_d_pwmnum = PARAMSET_PWMDRV_MPP_PWMGEN_CR2_pen_d_pwmnum,
							.tBit.finger_pwmnum = PARAMSET_PWMDRV_MPP_PWMGEN_CR2_finger_pwmnum,
							.tBit.nm_num = PARAMSET_PWMDRV_MPP_PWMGEN_CR2_nm_num,
							.tBit.total_mux_num = PARAMSET_PWMDRV_MPP_PWMGEN_CR2_total_mux_num,
						},
						.tCP_SET_TX_CR =
						{
							.tBit.set_tx_en = 0,
							.tBit.set_tx_num = 0,
						},
						.tCP_TSYNC_CR =
						{
							.tBit.tsync_num = (LHB_NUM - 1),
							.tBit.tsync_end_loc = 0,
							.tBit.tsync_dglitch_len = 0,
#if USED_OPERATION_STAND_ALONE
							.tBit.tsynct_in_sel = PWM_TSYNC_SRIC_INTR_INTERNAL,
							.tBit.tsynct_in_inv = 0,
							.tBit.tsynct_out_inv = 0,
							.tBit.tsync_sric_in_sel = PWM_TSYNC_SRIC_INTR_INTERNAL,
							.tBit.tsync_sric_out_sel = PWM_TSYNC_SRIC_INTR_EXTERNAL,
							.tBit.tsync_sric_in_inv = 0,
							.tBit.tsync_sric_out_inv = 0,
							.tBit.tsynct2_in_sel = PWM_TSYNC_INTR_EXTERNAL,
							.tBit.tsynct2_in_inv = 0,
							.tBit.tsynct_kiosk_in_sel = PWM_TSYNC_KIOSK_INTR_INTERNAL,
							.tBit.tsync_sric_redge_sel = 0,
							.tBit.tsync_sric_fedge_sel = 0,
#else /* USED_OPERATION_STAND_ALONE */
							.tBit.tsynct_in_sel = PWM_TSYNC_INTR_EXTERNAL,
							.tBit.tsynct_in_inv = 1,
							.tBit.tsynct_out_inv = 0,
							.tBit.tsync_sric_in_sel = PWM_TSYNC_SRIC_INTR_EXTERNAL,
							.tBit.tsync_sric_out_sel = PWM_TSYNC_SRIC_INTR_EXTERNAL,
							.tBit.tsync_sric_in_inv = 0,
							.tBit.tsync_sric_out_inv = 1,
							.tBit.tsynct2_in_sel = PWM_TSYNC_INTR_EXTERNAL,
							.tBit.tsynct2_in_inv = 0,
							.tBit.tsynct_kiosk_in_sel = PWM_TSYNC_KIOSK_INTR_INTERNAL,
							.tBit.tsync_sric_redge_sel = 0,
							.tBit.tsync_sric_fedge_sel = 0,
#endif
						},
						.tCP_TSYNC_D2_CR =
						{
							.tBit.beacon_en = ENABLE,//ISABLE,
							.tBit.pen_s_en = ENABLE,
							.tBit.pen_d_en = ENABLE,
							.tBit.finger_en = ENABLE,
							.tBit.nm_en = DISABLE,
							.tBit.none_en = ENABLE,//DISABLE,
							.tBit.st_pnt = 1,//3,
							.tBit.end_pnt = 1,//596,
							.tBit.kiosk_sgap_end = 0,
							.tBit.kiosk_pwm_end = 0,
							.tBit.kiosk_tch_time_end = 0,
						},
						.tCP_DLY_CNT1 =
						{
							.tBit.sgap_prd = PARAMSET_PWMDRV_MPP_DLY_CNT1_sgap_prd,
							.tBit.ping_prd = PARAMSET_PWMDRV_MPP_DLY_CNT1_ping_prd,
						},
						.tCP_DLY_CNT2 =
						{
							.tBit.mgap_prd_f = PARAMSET_PWMDRV_MPP_DLY_CNT2_mgap_prd_f,
							.tBit.mgap_prd_p_s = PARAMSET_PWMDRV_MPP_DLY_CNT2_mgap_prd_p_s,
							.tBit.mgap_prd_p_d = PARAMSET_PWMDRV_MPP_DLY_CNT2_mgap_prd_p_d,
						},
						.tCP_DLY_CNT3 =
						{
							.tBit.egap_prd = PWM_nsec(1950),
							.tBit.dgap_prd = 0,
							.tBit.offclk_dly = 0,
						},
						.tCP_TSYNC_TPIC_CR =
						{
							.tBit.beacon_en = ENABLE,
							.tBit.pen_s_en = DISABLE,
							.tBit.pen_d_en = DISABLE,
							.tBit.finger_en = ENABLE,
							.tBit.nm_en = DISABLE,
							.tBit.none_en = DISABLE,
							.tBit.pen_s_ping_en = ENABLE,
							.tBit.pen_d_ping_en = ENABLE,
							.tBit.finger_ping_en = DISABLE,
							.tBit.pen_s_pwm_en = DISABLE,
							.tBit.pen_d_pwm_en = DISABLE,
							.tBit.finger_pwm_en = ENABLE,
							.tBit.ping_only_en = ENABLE,
							.tBit.delay = 0,
							.tBit.kiosk_tch_time_end_off = 0,
						},
						.tCP_PWM_DLY1 =
						{
							.tBit.pwm_sric_f = PARAMSET_PWMDRV_MPP_PWM_DLY1_pwm_sric_f,
							.tBit.pwm_tpic_f = PARAMSET_PWMDRV_MPP_PWM_DLY1_pwm_tpic_f,
							.tBit.pwm_mux_f = PARAMSET_PWMDRV_MPP_PWM_DLY1_pwm_mux_f,
						},
						.tCP_DSSS_INFO0 =
						{
							.tBit.ping_finger = 0x10,
							.tBit.ping_pen_pos = 0x10,
							.tBit.ping_pen_dat = 0x10,
						},
						.tCP_DSSS_INFO1 =
						{
							[PWM_FULL_FINGER_MODE] =
							{
								.tBit.beacon_cfg0 = 0x10,
								.tBit.beacon_cfg1 = 0x00,
								.tBit.beacon_cfg2 = 0x01,
								.tBit.beacon_cfg3 = 0x02,
								.tBit.beacon_cfg4 = 0x03,
								.tBit.beacon_cfg5 = 0x04,
							},
							[PWM_LOCAL_PEN_MODE] =
							{
								.tBit.beacon_cfg0 = 0x10, // Preamble 1, 0
								.tBit.beacon_cfg1 = 0x00, // Gap, Preamble 2
								.tBit.beacon_cfg2 = 0x01,
								.tBit.beacon_cfg3 = 0x02,
								.tBit.beacon_cfg4 = 0x03,
								.tBit.beacon_cfg5 = 0x04,
							},
						},
						.tCP_DSSS_INFO2 =
						{
							[PWM_FULL_FINGER_MODE] =
							{
								.tBit.beacon_cfg6 = 0x05,
								.tBit.beacon_cfg7 = 0x00,
								.tBit.beacon_cfg8 = 0x00,
								.tBit.beacon_cfg9 = 0x00,
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
							},
							[PWM_LOCAL_PEN_MODE] =
							{
								.tBit.beacon_cfg6 = 0x05,
								.tBit.beacon_cfg7 = 0x00,
								.tBit.beacon_cfg8 = 0x00,
								.tBit.beacon_cfg9 = 0x00,
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
							},
						},
						.tCP_DSSS_CODE_Value =
						{
							[PWM_MPP_PEN_1st_SEARCH_BEACON] = /* 1st Beacon */
							{
								.tCP_DSSS_CODE_P_0 = 0x67C6EA12, // Preamble 1
								.tCP_DSSS_CODE_P_1 = 0x983915EC, // Preamble 0
								.tCP_DSSS_CODE_0_0 = 0x00000000, // Preamble Gap
								.tCP_DSSS_CODE_0_1 = 0x983915EC, // Preamble 2

								.tCP_DSSS_CODE_1_0 = 0x985A8EF8,
								.tCP_DSSS_CODE_1_1 = 0x7106CF4A,

								.tCP_DSSS_CODE_2_0 = 0x7C985A8E,
								.tCP_DSSS_CODE_2_1 = 0x5A8EF930,

								.tCP_DSSS_CODE_3_0 = 0x985A8EF8,
								.tCP_DSSS_CODE_3_1 = 0xA57106CE,

								.tCP_DSSS_CODE_4_0 = 0x8EF930B4,
								.tCP_DSSS_CODE_4_1 = 0x67A57106,

								.tCP_DSSS_CODE_5_0 = 0x8EF930B4,
								.tCP_DSSS_CODE_5_1 = 0xA57106CE,

								.tCP_DSSS_CODE_6_0 = 0x00000000,
								.tCP_DSSS_CODE_6_1 = 0x00000000,

								.tCP_DSSS_CODE_7_0 = 0x00000000,
								.tCP_DSSS_CODE_7_1 = 0x00000000,
							},
							[PWM_MPP_PEN_1st_PEN_BEACON] = /* 2nd Beacon */
							{
								.tCP_DSSS_CODE_P_0 = 0x67C6EA12, // Preamble 1
								.tCP_DSSS_CODE_P_1 = 0x983915EC, // Preamble 0
								.tCP_DSSS_CODE_0_0 = 0x00000000, // Preamble Gap
								.tCP_DSSS_CODE_0_1 = 0x983915EC, // Preamble 2

								.tCP_DSSS_CODE_1_0 = 0x985A8EF8,
								.tCP_DSSS_CODE_1_1 = 0x7106CF4A,

								.tCP_DSSS_CODE_2_0 = 0x5A8EF930, // 1 Pen Active
								.tCP_DSSS_CODE_2_1 = 0x5A8EF930,

								.tCP_DSSS_CODE_3_0 = 0x985A8EF8,
								.tCP_DSSS_CODE_3_1 = 0xA57106CE,

								.tCP_DSSS_CODE_4_0 = 0x985A8EF8,
								.tCP_DSSS_CODE_4_1 = 0x8EF930B4,

								.tCP_DSSS_CODE_5_0 = 0x8EF930B4,
								.tCP_DSSS_CODE_5_1 = 0x7C985A8E,

								.tCP_DSSS_CODE_6_0 = 0x00000000,
								.tCP_DSSS_CODE_6_1 = 0x00000000,

								.tCP_DSSS_CODE_7_0 = 0x00000000,
								.tCP_DSSS_CODE_7_1 = 0x00000000,
							},
							[PWM_MPP_PEN_2nd_BEACON] = /* 2nd Beacon */
							{
								.tCP_DSSS_CODE_P_0 = 0x67C6EA12, // Preamble 1
								.tCP_DSSS_CODE_P_1 = 0x983915EC, // Preamble 0
								.tCP_DSSS_CODE_0_0 = 0x00000000, // Preamble Gap
								.tCP_DSSS_CODE_0_1 = 0x983915EC, // Preamble 2

								.tCP_DSSS_CODE_1_0 = 0x7C985A8E,
								.tCP_DSSS_CODE_1_1 = 0x5A8EF930,

								.tCP_DSSS_CODE_2_0 = 0xA57106CE,
								.tCP_DSSS_CODE_2_1 = 0x7C985A8E,

								.tCP_DSSS_CODE_3_0 = 0x7106CF4A,
								.tCP_DSSS_CODE_3_1 = 0x67A57106,

								.tCP_DSSS_CODE_4_0 = 0x7C985A8E,
								.tCP_DSSS_CODE_4_1 = 0xA57106CE,

								.tCP_DSSS_CODE_5_0 = 0x985A8EF8,
								.tCP_DSSS_CODE_5_1 = 0x985A8EF8,

								.tCP_DSSS_CODE_6_0 = 0x00000000,
								.tCP_DSSS_CODE_6_1 = 0x00000000,

								.tCP_DSSS_CODE_7_0 = 0x00000000,
								.tCP_DSSS_CODE_7_1 = 0x00000000,
							},
						},
						.tCP_PWM_TPIC_CR =
						{
							.tBit.beacon_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_beacon_en,
							.tBit.pen_s_ping_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_pen_s_ping_en,
							.tBit.pen_d_ping_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_pen_d_ping_en,
							.tBit.finger_ping_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_finger_ping_en,
							.tBit.pen_s_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_pen_s_en,
							.tBit.pen_d_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_pen_d_en,
							.tBit.finger_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_finger_en,
							.tBit.pen_s_dmy_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_pen_s_dmy_en,
							.tBit.pen_d_dmy_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_pen_d_dmy_en,
							.tBit.finger_dmy_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_finger_dmy_en,
							.tBit.pen_s_set_tx_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_pen_s_set_tx_en,
							.tBit.pen_d_set_tx_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_pen_d_set_tx_en,
							.tBit.finger_set_tx_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_finger_set_tx_en,
							.tBit.nm_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_nm_en,
							.tBit.inv_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_inv_en,
							.tBit.ping_only_en = PARAMSET_PWMDRV_MPP_PWM_TPIC_CR_ping_only_en,
						},
						.tCP_PWM_SRIC_CR =
						{
							.tBit.beacon_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_beacon_en,
							.tBit.pen_s_ping_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_pen_s_ping_en,
							.tBit.pen_d_ping_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_pen_d_ping_en,
							.tBit.finger_ping_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_finger_ping_en,
							.tBit.pen_s_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_pen_s_en,
							.tBit.pen_d_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_pen_d_en,
							.tBit.finger_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_finger_en,
							.tBit.pen_s_dmy_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_pen_s_dmy_en,
							.tBit.pen_d_dmy_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_pen_d_dmy_en,
							.tBit.finger_dmy_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_finger_dmy_en,
							.tBit.pen_s_set_tx_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_pen_s_set_tx_en,
							.tBit.pen_d_set_tx_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_pen_d_set_tx_en,
							.tBit.finger_set_tx_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_finger_set_tx_en,
							.tBit.nm_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_nm_en,
							.tBit.inv_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_inv_en,
							.tBit.pwm_2x_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_pwm_2x_en,
							.tBit.pen_s_tsync_d2_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_pen_s_tsync_d2_en,
							.tBit.pen_d_tsync_d2_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_pen_d_tsync_d2_en,
							.tBit.finger_tsync_d2_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_finger_tsync_d2_en,
							.tBit.ping_only_en = PARAMSET_PWMDRV_MPP_PWM_SRIC_CR_ping_only_en,
						},
						.tCP_PWM_MUX_CR =
						{
							.tBit.beacon_en = DISABLE,
							.tBit.pen_s_ping_en = DISABLE,
							.tBit.pen_d_ping_en = DISABLE,
							.tBit.finger_ping_en = DISABLE,
							.tBit.pen_s_en = DISABLE,
							.tBit.pen_d_en = DISABLE,
							.tBit.finger_en = DISABLE,
							.tBit.pen_s_dmy_en = DISABLE,
							.tBit.pen_d_dmy_en = DISABLE,
							.tBit.finger_dmy_en = DISABLE,
							.tBit.pen_s_set_tx_en = DISABLE,
							.tBit.pen_d_set_tx_en = DISABLE,
							.tBit.finger_set_tx_en = DISABLE,
							.tBit.nm_en = DISABLE,
							.tBit.inv_en = DISABLE,
							.tBit.ping_only_en = DISABLE,
						},
						.tCP_DMY_FREQ = PARAMSET_PWMDRV_MPP_DMY_FREQ,//137,//PWM_Full_KHz(87)/2,
						.tCP_FREQ_CR1 =
						{
							.tBit.pen_d = 275,//PWM_Full_KHz(87),
							.tBit.pen_s = 275,//PWM_Full_KHz(87),
							.tBit.finger = 275,//PWM_Full_KHz(87),
						},
						.tCP_FREQ_CR2 =
						{
							.tBit.freq_beacon = PARAMSET_PWMDRV_MPP_Beacon_FREQ,
						},
						.tCP_LHB_CONFIG11 =
						{
							.tBit.lhb1 = PARAMSET_PWMDRV_MPP_FULL_LHB_1,
							.tBit.lhb2 = PARAMSET_PWMDRV_MPP_FULL_LHB_2,
							.tBit.lhb3 = PARAMSET_PWMDRV_MPP_FULL_LHB_3,
							.tBit.lhb4 = PARAMSET_PWMDRV_MPP_FULL_LHB_4,
							.tBit.lhb5 = PARAMSET_PWMDRV_MPP_FULL_LHB_5,
							.tBit.lhb6 = PARAMSET_PWMDRV_MPP_FULL_LHB_6,
							.tBit.lhb7 = PARAMSET_PWMDRV_MPP_FULL_LHB_7,
							.tBit.lhb8 = PARAMSET_PWMDRV_MPP_FULL_LHB_8,
							.tBit.lhb9 = PARAMSET_PWMDRV_MPP_FULL_LHB_9,
							.tBit.lhb10 = PARAMSET_PWMDRV_MPP_FULL_LHB_10,
						},
						.tCP_LHB_CONFIG12 =
						{
							.tBit.lhb11 = PARAMSET_PWMDRV_MPP_FULL_LHB_11,
							.tBit.lhb12 = PARAMSET_PWMDRV_MPP_FULL_LHB_12,
							.tBit.lhb13 = PARAMSET_PWMDRV_MPP_FULL_LHB_13,
							.tBit.lhb14 = PARAMSET_PWMDRV_MPP_FULL_LHB_14,
							.tBit.lhb15 = PARAMSET_PWMDRV_MPP_FULL_LHB_15,
							.tBit.lhb16 = PARAMSET_PWMDRV_MPP_FULL_LHB_16,
							.tBit.lhb17 = PARAMSET_PWMDRV_MPP_FULL_LHB_17,
							.tBit.lhb18 = PARAMSET_PWMDRV_MPP_FULL_LHB_18,
							.tBit.lhb19 = PARAMSET_PWMDRV_MPP_FULL_LHB_19,
							.tBit.lhb20 = PARAMSET_PWMDRV_MPP_FULL_LHB_20,
						},
						.tCP_LHB_CONFIG13 =
						{
							.tBit.lhb21 = PARAMSET_PWMDRV_MPP_FULL_LHB_21,
							.tBit.lhb22 = PARAMSET_PWMDRV_MPP_FULL_LHB_22,
							.tBit.lhb23 = PARAMSET_PWMDRV_MPP_FULL_LHB_23,
							.tBit.lhb24 = PARAMSET_PWMDRV_MPP_FULL_LHB_24,
							.tBit.lhb25 = PARAMSET_PWMDRV_MPP_FULL_LHB_25,
							.tBit.lhb26 = PARAMSET_PWMDRV_MPP_FULL_LHB_26,
							.tBit.lhb27 = PARAMSET_PWMDRV_MPP_FULL_LHB_27,
							.tBit.lhb28 = PARAMSET_PWMDRV_MPP_FULL_LHB_28,
							.tBit.lhb29 = PARAMSET_PWMDRV_MPP_FULL_LHB_29,
							.tBit.lhb30 = PARAMSET_PWMDRV_MPP_FULL_LHB_30,
						},
						.tCP_LHB_CONFIG14 =
						{
							.tBit.lhb31 = PARAMSET_PWMDRV_MPP_FULL_LHB_31,
							.tBit.lhb32 = PARAMSET_PWMDRV_MPP_FULL_LHB_32,
						},
						.tCP_LHB_CONFIG21 =
						{
							.tBit.lhb1 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_1,
							.tBit.lhb2 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_2,
							.tBit.lhb3 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_3,
							.tBit.lhb4 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_4,
							.tBit.lhb5 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_5,
							.tBit.lhb6 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_6,
							.tBit.lhb7 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_7,
							.tBit.lhb8 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_8,
							.tBit.lhb9 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_9,
							.tBit.lhb10 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_10,
						},
						.tCP_LHB_CONFIG22 =
						{
							.tBit.lhb11 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_11,
							.tBit.lhb12 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_12,
							.tBit.lhb13 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_13,
							.tBit.lhb14 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_14,
							.tBit.lhb15 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_15,
							.tBit.lhb16 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_16,
							.tBit.lhb17 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_17,
							.tBit.lhb18 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_18,
							.tBit.lhb19 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_19,
							.tBit.lhb20 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_20,
						},
						.tCP_LHB_CONFIG23 =
						{
							.tBit.lhb21 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_21,
							.tBit.lhb22 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_22,
							.tBit.lhb23 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_23,
							.tBit.lhb24 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_24,
							.tBit.lhb25 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_25,
							.tBit.lhb26 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_26,
							.tBit.lhb27 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_27,
							.tBit.lhb28 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_28,
							.tBit.lhb29 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_29,
							.tBit.lhb30 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_30,
						},
						.tCP_LHB_CONFIG24 =
						{
							.tBit.lhb31 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_31,
							.tBit.lhb32 = PARAMSET_PWMDRV_MPP_LOCAL_LHB_32,
						},
						.tCP_PING_CR =
						{
							.tBit.beacon = DISABLE,
							.tBit.pen_s = DISABLE,
							.tBit.pen_d = DISABLE,
							.tBit.finger = DISABLE,
							.tBit.nm = DISABLE,
							.tBit.none = DISABLE,
							.tBit.ping_only = DISABLE,
						},
						.tCP_SYNC_GEN_CR =
						{
							.tBit.sync_gen_en = DISABLE,
							.tBit.vsync_stuck_en = DISABLE,
							.tBit.vsync_stuck_level = 0,
							.tBit.tsynct_stuck_en = DISABLE,
							.tBit.tsynct_stuck_level = 0,
							.tBit.tsyncd_stuck_en = DISABLE,
							.tBit.tsyncd_stuck_level = 0,
						},
						/*
						 * PWM Clock Default (DIV /128)
						 */
						.tCP_TE_RDY_CNT = 50,
						.tCP_TE_TCH_V_FPCH = 2,//2,
						.tCP_TE_TCH_V_HIGH = 2,//2,
						.tCP_TE_TCH_FPCH = 2,//1,
						.tCP_TE_TCH_T_HIGH = 94,//153,
						.tCP_TE_TCH_D_HIGH = 92,//13,
						.tCP_TE_TCH_LOW = 96,//133,
						.tCP_TE_TCH_BPCH = 3,
						.tCP_TE_TCH_PD_LOW = 4,
						.tCP_TG_DUM1 = 0,
						.tCP_TG_DUM2 = 0,
						.tCP_TG_DUM3 = 0,
						.tCP_TG_DUM4 = 0,
						.tCP_TG_DUM5 =
						{
							.tBit.tsync_tpic_out_bypass_enb = PARAMSET_PWMDRV_MPP_TG_DUM5_tsync_tpic_out_bypass_enb,
							.tBit.tsync_sric_out_bypass_enb = 0,
							.tBit.tsync_sric_lhb_ping_en = 0,
							.tBit.sync_gen_fr_done_mask_en = 0,
							.tBit.disp_off_beacon_only = 1,
						},
						.tCP_DISP_OFF_CR =
						{
							.tBit.stuck_en = DISABLE,
							.tBit.stuck_value = 0,
							.tBit.disp_off_fpnt = PWM_nsec(59600),
							.tBit.inv_en = 0,
						},
						.tCP_PWM_CR1 =
						{
							.tBit.pen_s_h_pnt = PARAMSET_PWMDRV_MPP_PWM_CR1_pen_s_h_pnt,
							.tBit.pen_d_h_pnt = PARAMSET_PWMDRV_MPP_PWM_CR1_pen_d_h_pnt,
						},
						.tCP_PWM_CR2 =
						{
							.tBit.finger_h_pnt = PARAMSET_PWMDRV_MPP_PWM_CR2_finger_h_pnt,
							.tBit.dmy_h_pnt = PARAMSET_PWMDRV_MPP_PWM_CR2_dmy_h_pnt,
						},
						.tCP_VSYNC_CR =
						{
							.tBit.vsync_in_inv = 0,
							.tBit.vsync_in_sel = PWM_VSYNC_INTR_INTERNAL,
							.tBit.vsync_locate = 9,
							.tBit.rising_pnt = 0,
							.tBit.falling_pnt = 0,
							.tBit.vsync_kiosk_in_sel = 0,
							.tBit.gst_in_inv = 0,
						},
						.tCP_MUX_CR =
						{
							.tBit.pen_s = PARAMSET_PWMDRV_MPP_MUX_CR_pen_s,
							.tBit.pen_d = PARAMSET_PWMDRV_MPP_MUX_CR_pen_d,
							.tBit.finger = PARAMSET_PWMDRV_MPP_MUX_CR_finger,
							.tBit.nm = PARAMSET_PWMDRV_MPP_MUX_CR_nm,
						},
						.tCP_PWM_TPIC_ST_CR =
						{
							.tBit.beacon_stuck = 0,
							.tBit.pen_s_ping_stuck = 0,
							.tBit.pen_d_ping_stuck = 0,
							.tBit.finger_ping_stuck = 0,
							.tBit.pen_s_stuck = 0,
							.tBit.pen_d_stuck = 0,
							.tBit.finger_stuck = 0,
							.tBit.pen_s_dmy_stuck = 0,
							.tBit.pen_d_dmy_stuck = 0,
							.tBit.finger_dmy_stuck = 0,
							.tBit.pen_s_set_tx_stuck = 0,
							.tBit.pen_d_set_tx_stuck = 0,
							.tBit.finger_set_tx_stuck = 0,
							.tBit.nm_stuck = 0,
						},
						.tCP_PWM_SRIC_ST_CR =
						{
							.tBit.beacon_stuck = 0,
							.tBit.pen_s_ping_stuck = 0,
							.tBit.pen_d_ping_stuck = 0,
							.tBit.finger_ping_stuck = 0,
							.tBit.pen_s_stuck = 0,
							.tBit.pen_d_stuck = 0,
							.tBit.finger_stuck = 0,
							.tBit.pen_s_dmy_stuck = 0,
							.tBit.pen_d_dmy_stuck = 0,
							.tBit.finger_dmy_stuck = 0,
							.tBit.pen_s_set_tx_stuck = 0,
							.tBit.pen_d_set_tx_stuck = 0,
							.tBit.finger_set_tx_stuck = 0,
							.tBit.nm_stuck = 0,
						},
						.tCP_PWM_MUX_ST_CR =
						{
							.tBit.beacon_stuck = 0,
							.tBit.pen_s_ping_stuck = 0,
							.tBit.pen_d_ping_stuck = 0,
							.tBit.finger_ping_stuck = 0,
							.tBit.pen_s_stuck = 0,
							.tBit.pen_d_stuck = 0,
							.tBit.finger_stuck = 0,
							.tBit.pen_s_dmy_stuck = 0,
							.tBit.pen_d_dmy_stuck = 0,
							.tBit.finger_dmy_stuck = 0,
							.tBit.pen_s_set_tx_stuck = 0,
							.tBit.pen_d_set_tx_stuck = 0,
							.tBit.finger_set_tx_stuck = 0,
							.tBit.nm_stuck = 0,
						},
						.tCP_NM_FREQ =
						{
							.tBit.freq_nm1 = 199,
							.tBit.freq_nm2 = 299,
							.tBit.freq_nm3 = 499,
						},
						.tCP_PWM_DLY2 =
						{
							.tBit.pwm_vgh_f = 0,
							.tBit.pwm_gma_f = 0,
						},
						.tCP_DLY_CNT4 =
						{
							.tBit.bgap_prd = PARAMSET_PWMDRV_MPP_DLY_CNT4_bgap_prd,
							.tBit.bc_egap_prd = PARAMSET_PWMDRV_MPP_DLY_CNT4_bc_egap_prd,
						},
						.tCP_KIOSK_VSYNC_TIMER = 0,
						.tCP_PWM_DLY3 =
						{
							.tBit.pwm_sric_p = 0,
							.tBit.pwm_tpic_p = 0,//PWM_nsec(1050),
							.tBit.pwm_mux_p = 0,//PWM_nsec(1050),
						},
						.tCP_PWM_DLY4 =
						{
							.tBit.pwm_vgh_p = 0,//PWM_nsec(1050),
							.tBit.pwm_gma_p = 0,//PWM_nsec(1050),
						},
	#if IS_MULTI_PROTOCOL_OPERATION
					},
	#endif
#endif /* IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION */
#if IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION
	#if IS_MULTI_PROTOCOL_OPERATION
					[ACTIVEPEN_TYPE_LOCAL_WGP] =
					{
	#endif
						.tCP_PWMGEN_CR0 =
						{
							.tBit.pwm_gen_enable = DISABLE,
							.tBit.kiosk_mode = 0,
							.tBit.tfd_mode = PWM_TSD_MODE,
							.tBit.continuos_en = PWM_CONTINUOS_MODE,
							.tBit.frame_rate = PWM_FRAME_RATE_DIV_1,
							.tBit.chip_length0 = PARAMSET_PWMDRV_WGP_PWMGEN_CR0_chip_length0,
							.tBit.chip_length1 = PARAMSET_PWMDRV_WGP_PWMGEN_CR0_chip_length1,
							.tBit.frame_intr_sel = PWM_FRINTR_LAST_MUX,
							.tBit.pen_mode = PWM_LOCAL_PEN_MODE,
							.tBit.offclk_ctrl_tpic = PWM_OFFCLK_IGNORE,
							.tBit.offclk_ctrl_sric = PWM_OFFCLK_IGNORE,
							.tBit.offclk_ctrl_mux = PWM_OFFCLK_IGNORE,
							.tBit.offclk_ctrl_vgh = PWM_OFFCLK_IGNORE,
							.tBit.offclk_ctrl_gma = PWM_OFFCLK_IGNORE,
							.tBit.offclk_ctrl_en = DISABLE,
							.tBit.pwm_sric_output_en = ENABLE,
							.tBit.pwm_tpic_output_en = ENABLE,
#if USED_PWM_GATE_CONTROL
							.tBit.pwm_mux_output_en = ENABLE,
#else
							.tBit.pwm_mux_output_en = DISABLE,
#endif
							.tBit.pwm_vgh_output_en = DISABLE,
							.tBit.pwm_gma_output_en = DISABLE,
						},
						.tCP_PWMGEN_CR1 =
						{
							.tBit.fstart_en = PARAMSET_PWMDRV_WGP_PWMGEN_CR1_fstart_en,
							.tBit.skip_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR1_skip_num,
							.tBit.beacon_data_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR1_beacon_data_num,
							.tBit.sric_dummy_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR1_sric_dummy_num,
							.tBit.tpic_dummy_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR1_tpic_dummy_num,
							.tBit.dummy_gap_en = PARAMSET_PWMDRV_WGP_PWMGEN_CR1_dummy_gap_en,
							.tBit.pgap_en = PARAMSET_PWMDRV_WGP_PWMGEN_CR1_pgap_en,
							.tBit.pen_s_pwmnum = PARAMSET_PWMDRV_WGP_PWMGEN_CR1_pen_s_pwmnum,
						},
						.tCP_PWMGEN_CR2 =
						{
							.tBit.pen_d_pwmnum = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_pen_d_pwmnum,//31,//36,
							.tBit.finger_pwmnum = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_finger_pwmnum,
							.tBit.nm_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_nm_num,
							.tBit.total_mux_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_total_mux_num,
						},
						.tCP_SET_TX_CR =
						{
							.tBit.set_tx_en = 0,
							.tBit.set_tx_num = 0,
						},
						.tCP_TSYNC_CR =
						{
							.tBit.tsync_num = (LHB_NUM - 1),
							.tBit.tsync_end_loc = 0,
							.tBit.tsync_dglitch_len = 0,
#if USED_OPERATION_STAND_ALONE
							.tBit.tsynct_in_sel = PWM_TSYNC_SRIC_INTR_INTERNAL,
							.tBit.tsynct_in_inv = 0,
							.tBit.tsynct_out_inv = 0,
							.tBit.tsync_sric_in_sel = PWM_TSYNC_SRIC_INTR_INTERNAL,
							.tBit.tsync_sric_out_sel = PWM_TSYNC_SRIC_INTR_EXTERNAL,
							.tBit.tsync_sric_in_inv = 0,
							.tBit.tsync_sric_out_inv = 0,
							.tBit.tsynct2_in_sel = PWM_TSYNC_INTR_EXTERNAL,
							.tBit.tsynct2_in_inv = 0,
							.tBit.tsynct_kiosk_in_sel = PWM_TSYNC_KIOSK_INTR_INTERNAL,
							.tBit.tsync_sric_redge_sel = 0,
							.tBit.tsync_sric_fedge_sel = 0,
#else /* USED_OPERATION_STAND_ALONE */
							.tBit.tsynct_in_sel = PWM_TSYNC_INTR_EXTERNAL,
							.tBit.tsynct_in_inv = 1,
							.tBit.tsynct_out_inv = 0,
							.tBit.tsync_sric_in_sel = PWM_TSYNC_SRIC_INTR_EXTERNAL,
							.tBit.tsync_sric_out_sel = PWM_TSYNC_SRIC_INTR_EXTERNAL,
							.tBit.tsync_sric_in_inv = 0,
							.tBit.tsync_sric_out_inv = 1,
							.tBit.tsynct2_in_sel = PWM_TSYNC_INTR_EXTERNAL,
							.tBit.tsynct2_in_inv = 0,
							.tBit.tsynct_kiosk_in_sel = PWM_TSYNC_KIOSK_INTR_INTERNAL,
							.tBit.tsync_sric_redge_sel = 0,
							.tBit.tsync_sric_fedge_sel = 0,
#endif
						},
						.tCP_TSYNC_D2_CR =
						{
							.tBit.beacon_en = ENABLE,//ISABLE,
							.tBit.pen_s_en = ENABLE,
							.tBit.pen_d_en = ENABLE,
							.tBit.finger_en = ENABLE,
							.tBit.nm_en = DISABLE,
							.tBit.none_en = ENABLE,
							.tBit.st_pnt = 1,//3,
							.tBit.end_pnt = 1,//596,
							.tBit.kiosk_sgap_end = 0,
							.tBit.kiosk_pwm_end = 0,
							.tBit.kiosk_tch_time_end = 0,
						},
						.tCP_DLY_CNT1 =
						{
							.tBit.sgap_prd = PARAMSET_PWMDRV_WGP_DLY_CNT1_sgap_prd,
							.tBit.ping_prd = PARAMSET_PWMDRV_WGP_DLY_CNT1_ping_prd,
						},
						.tCP_DLY_CNT2 =
						{
							.tBit.mgap_prd_f = PARAMSET_PWMDRV_WGP_DLY_CNT2_mgap_prd_f,
							.tBit.mgap_prd_p_s = PARAMSET_PWMDRV_WGP_DLY_CNT2_mgap_prd_p_s,
							.tBit.mgap_prd_p_d = PARAMSET_PWMDRV_WGP_DLY_CNT2_mgap_prd_p_d,
						},
						.tCP_DLY_CNT3 =
						{
							.tBit.egap_prd = PWM_nsec(1950),
							.tBit.dgap_prd = 0,//PWM_nsec(13194),
							.tBit.offclk_dly = 0,//(PWM_nsec(1100)-1),
						},
						.tCP_TSYNC_TPIC_CR =
						{
							.tBit.beacon_en = ENABLE,
							.tBit.pen_s_en = DISABLE,
							.tBit.pen_d_en = DISABLE,
							.tBit.finger_en = ENABLE,
							.tBit.nm_en = DISABLE,
							.tBit.none_en = DISABLE,
							.tBit.pen_s_ping_en = ENABLE,
							.tBit.pen_d_ping_en = ENABLE,
							.tBit.finger_ping_en = DISABLE,
							.tBit.pen_s_pwm_en = DISABLE,
							.tBit.pen_d_pwm_en = DISABLE,
							.tBit.finger_pwm_en = ENABLE,
							.tBit.ping_only_en = ENABLE,
							.tBit.delay = 0,
							.tBit.kiosk_tch_time_end_off = 0,
						},
						.tCP_PWM_DLY1 =
						{
							.tBit.pwm_sric_f = PARAMSET_PWMDRV_WGP_PWM_DLY1_pwm_sric_f,
							.tBit.pwm_tpic_f = PARAMSET_PWMDRV_WGP_PWM_DLY1_pwm_tpic_f,
							.tBit.pwm_mux_f = PARAMSET_PWMDRV_WGP_PWM_DLY1_pwm_mux_f,//PWM_nsec(1950),
						},
						.tCP_DSSS_INFO0 =
						{
							.tBit.ping_finger = 0x10,
							.tBit.ping_pen_pos = 0x10,
							.tBit.ping_pen_dat = 0x10,
						},
						.tCP_DSSS_INFO1 =
						{
#if USED_DUMMY_LHB_MODULATION
								[PWM_FULL_FINGER_MODE] = // Set Table
								{
									.tBit.beacon_cfg0 = 0x00,
									.tBit.beacon_cfg1 = 0x01,
									.tBit.beacon_cfg2 = 0x00,	// Preamble
									.tBit.beacon_cfg3 = 0x00,	// Preamble
									.tBit.beacon_cfg4 = 0x00,	// Data #1 E
									.tBit.beacon_cfg5 = 0x00,	// Data #2 8
								},
								[PWM_LOCAL_PEN_MODE] = // Get ABS
								{
									.tBit.beacon_cfg0 = 0x00,
									.tBit.beacon_cfg1 = 0x01,
									.tBit.beacon_cfg2 = 0x00,	// Preamble
									.tBit.beacon_cfg3 = 0x00,	// Preamble
									.tBit.beacon_cfg4 = 0x00,	// Data #1 2
									.tBit.beacon_cfg5 = 0x00,	// Data #2 6
								},
#elif USED_WGP_AGIC_PEN
							[PWM_FULL_FINGER_MODE] = // Set Table
							{
								.tBit.beacon_cfg0 = 0x07,
								.tBit.beacon_cfg1 = 0x07,
								.tBit.beacon_cfg2 = 0x10,	// Preamble
								.tBit.beacon_cfg3 = 0x10,	// Preamble
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
								.tBit.beacon_cfg4 = 0x02,	// Data #1 6
								.tBit.beacon_cfg5 = 0x05,	// Data #2 9
	#else
								.tBit.beacon_cfg4 = 0x06,	// Data #1 E
								.tBit.beacon_cfg5 = 0x05,	// Data #2 8
	#endif
							},
							[PWM_LOCAL_PEN_MODE] = // Get ABS
							{
								.tBit.beacon_cfg0 = 0x07,
								.tBit.beacon_cfg1 = 0x07,
								.tBit.beacon_cfg2 = 0x10,	// Preamble
								.tBit.beacon_cfg3 = 0x10,	// Preamble
								.tBit.beacon_cfg4 = 0x01,	// Data #1 2
								.tBit.beacon_cfg5 = 0x02,	// Data #2 6
							},
#else /* USED_WGP_AGIC_PEN */
							[PWM_FULL_FINGER_MODE] = // Set Table
							{
								.tBit.beacon_cfg0 = 0x07,
								.tBit.beacon_cfg1 = 0x07,
								.tBit.beacon_cfg2 = 0x07,
								.tBit.beacon_cfg3 = 0x07,
								.tBit.beacon_cfg4 = 0x10,	// Preamble
								.tBit.beacon_cfg5 = 0x10,	// Preamble
							},
							[PWM_LOCAL_PEN_MODE] = // Get ABS
							{
								.tBit.beacon_cfg0 = 0x07,
								.tBit.beacon_cfg1 = 0x07,
								.tBit.beacon_cfg2 = 0x07,
								.tBit.beacon_cfg3 = 0x07,
								.tBit.beacon_cfg4 = 0x10,	// Preamble
								.tBit.beacon_cfg5 = 0x10,	// Preamble
							},
#endif /* USED_WGP_AGIC_PEN */
						},
						.tCP_DSSS_INFO2 =
						{
#if USED_DUMMY_LHB_MODULATION
							[PWM_FULL_FINGER_MODE] = // Set Table
							{
								.tBit.beacon_cfg6 = 0x00,	// Data #1 E
								.tBit.beacon_cfg7 = 0x00,	// Data #2 8
								.tBit.beacon_cfg8 = 0x00,	// Data #3 6
								.tBit.beacon_cfg9 = 0x00,	// CRC B
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
							},
							[PWM_LOCAL_PEN_MODE] = // Get ABS
							{
								.tBit.beacon_cfg6 = 0x00,	// Data #1 2
								.tBit.beacon_cfg7 = 0x00,	// Data #2 6
								.tBit.beacon_cfg8 = 0x00,	// Data #3 0
								.tBit.beacon_cfg9 = 0x00,	// CRC B
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
							},
#elif USED_WGP_AGIC_PEN
							[PWM_FULL_FINGER_MODE] = // Set Table
							{
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
		#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
								.tBit.beacon_cfg6 = 0x04,	// Data #3 7
								.tBit.beacon_cfg7 = 0x06,	// CRC 1
		#else
								.tBit.beacon_cfg6 = 0x02,	// Data #3 6
								.tBit.beacon_cfg7 =0x01,	// CRC 2
		#endif
	#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
								.tBit.beacon_cfg6 = 0x02,	// Data #3 6
								.tBit.beacon_cfg7 = 0x03,	// CRC B
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
								.tBit.beacon_cfg8 = 0x00,
								.tBit.beacon_cfg9 = 0x00,
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
							},
							[PWM_LOCAL_PEN_MODE] = // Get ABS
							{
								.tBit.beacon_cfg6 = 0x00,	// Data #3 0
								.tBit.beacon_cfg7 = 0x03,	// CRC B
								.tBit.beacon_cfg8 = 0x00,
								.tBit.beacon_cfg9 = 0x00,
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
							},
#else /* USED_WGP_AGIC_PEN */
							[PWM_FULL_FINGER_MODE] = // Set Table
							{
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
								.tBit.beacon_cfg6 = 0x02,	// Data #1 6
								.tBit.beacon_cfg7 = 0x05,	// Data #2 9
		#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
								.tBit.beacon_cfg8 = 0x04,	// Data #3 7
								.tBit.beacon_cfg9 = 0x06,	// CRC 1
		#else
								.tBit.beacon_cfg8 = 0x02,	// Data #3 6
								.tBit.beacon_cfg9 = 0x01,	// CRC 2
		#endif
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
	#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
								.tBit.beacon_cfg6 = 0x06,	// Data #1 E
								.tBit.beacon_cfg7 = 0x05,	// Data #2 8
								.tBit.beacon_cfg8 = 0x02,	// Data #3 6
								.tBit.beacon_cfg9 = 0x03,	// CRC B
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
							},
							[PWM_LOCAL_PEN_MODE] = // Get ABS
							{
								.tBit.beacon_cfg6 = 0x01,	// Data #1 2
								.tBit.beacon_cfg7 = 0x02,	// Data #2 6
								.tBit.beacon_cfg8 = 0x00,	// Data #3 0
								.tBit.beacon_cfg9 = 0x03,	// CRC B
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
							},
#endif /* USED_WGP_AGIC_PEN */
						},
						.tCP_DSSS_CODE_Value =
						{
#if USED_DUMMY_LHB_MODULATION
								[PWM_WGP_PEN_SETTABLE_BEACON] =
								{
									.tCP_DSSS_CODE_P_0 = 0x00000000,		// P : LSB
									.tCP_DSSS_CODE_P_1 = 0xAAAAAAAA,		// P : MSB
									.tCP_DSSS_CODE_0_0 = 0x00000000,		// 0 : LSB
									.tCP_DSSS_CODE_0_1 = 0xAAAAAAAA,		// 0 : MSB
									.tCP_DSSS_CODE_1_0 = 0x00000000,		// 2 : LSB
									.tCP_DSSS_CODE_1_1 = 0xAAAAAAA0,		// 2 : MSB
									.tCP_DSSS_CODE_2_0 = 0x00000000,		// 6 : LSB
									.tCP_DSSS_CODE_2_1 = 0xAAAAAAAA,		// 6 : MSB
									.tCP_DSSS_CODE_3_0 = 0x00000000,		// B : LSB
									.tCP_DSSS_CODE_3_1 = 0xAAAAAAAA,		// B : MSB

									.tCP_DSSS_CODE_4_0 = 0x00000000,		// C : LSB
									.tCP_DSSS_CODE_4_1 = 0xAAAAAAAA,		// C : MSB
									.tCP_DSSS_CODE_5_0 = 0x00000000,		// 8 : LSB
									.tCP_DSSS_CODE_5_1 = 0xAAAAAAAA,		// 8 : MSB
									.tCP_DSSS_CODE_6_0 = 0x00000000,		// E : LSB
									.tCP_DSSS_CODE_6_1 = 0xAAAAAAAA,		// E : MSB
									.tCP_DSSS_CODE_7_0 = 0x00000000,		// GAP
									.tCP_DSSS_CODE_7_1 = 0xAAAAAAAA,		// GAP
								},
#else
								[PWM_WGP_PEN_SETTABLE_BEACON] =
								{
									.tCP_DSSS_CODE_P_0 = 0xA965A000,		// P : LSB
									.tCP_DSSS_CODE_P_1 = 0x95666000,		// P : MSB
									.tCP_DSSS_CODE_0_0 = 0x9AA59000,		// 0 : LSB
									.tCP_DSSS_CODE_0_1 = 0x9A559000,		// 0 : MSB
									.tCP_DSSS_CODE_1_0 = 0x5599A000,		// 2 : LSB
									.tCP_DSSS_CODE_1_1 = 0xA965A000,		// 2 : MSB
									.tCP_DSSS_CODE_2_0 = 0xA5599000,		// 6 : LSB
									.tCP_DSSS_CODE_2_1 = 0xAA965000,		// 6 : MSB
									.tCP_DSSS_CODE_3_0 = 0xA6655000,		// B : LSB
									.tCP_DSSS_CODE_3_1 = 0x69A5A000,		// B : MSB

	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
									.tCP_DSSS_CODE_4_0 = 0x5A559000,		// 7 : LSB
									.tCP_DSSS_CODE_4_1 = 0xA6A96000,		// 7 : MSB
									.tCP_DSSS_CODE_5_0 = 0x6655A000,		// 9 : LSB
									.tCP_DSSS_CODE_5_1 = 0x5A5AA000,		// 9 : MSB
									.tCP_DSSS_CODE_6_0 = 0x99AA5000,		// 1 : LSB
									.tCP_DSSS_CODE_6_1 = 0xA5A55000,		// 1 : MSB
	#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
									.tCP_DSSS_CODE_4_0 = 0x69A5A000,		// C : LSB
									.tCP_DSSS_CODE_4_1 = 0x69995000,		// C : MSB
									.tCP_DSSS_CODE_5_0 = 0x655A6000,		// 8 : LSB
									.tCP_DSSS_CODE_5_1 = 0x65AA6000,		// 8 : MSB
									.tCP_DSSS_CODE_6_0 = 0x5AA66000,		// E : LSB
									.tCP_DSSS_CODE_6_1 = 0x5569A000,		// E : MSB
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
									.tCP_DSSS_CODE_7_0 = 0x00000000,		// GAP
									.tCP_DSSS_CODE_7_1 = 0x00000000,		// GAP
								},
#endif
						},
						.tCP_PWM_TPIC_CR =
						{
							.tBit.beacon_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_beacon_en,
							.tBit.pen_s_ping_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_s_ping_en,
							.tBit.pen_d_ping_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_d_ping_en,
							.tBit.finger_ping_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_finger_ping_en,
							.tBit.pen_s_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_s_en,
							.tBit.pen_d_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_d_en,
							.tBit.finger_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_finger_en,
							.tBit.pen_s_dmy_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_s_dmy_en,
							.tBit.pen_d_dmy_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_d_dmy_en,
							.tBit.finger_dmy_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_finger_dmy_en,
							.tBit.pen_s_set_tx_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_s_set_tx_en,
							.tBit.pen_d_set_tx_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_pen_d_set_tx_en,
							.tBit.finger_set_tx_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_finger_set_tx_en,
							.tBit.nm_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_nm_en,
							.tBit.inv_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_inv_en,
							.tBit.ping_only_en = PARAMSET_PWMDRV_WGP_PWM_TPIC_CR_ping_only_en,
						},
						.tCP_PWM_SRIC_CR =
						{
							.tBit.beacon_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_beacon_en,
							.tBit.pen_s_ping_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_s_ping_en,
							.tBit.pen_d_ping_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_d_ping_en,
							.tBit.finger_ping_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_finger_ping_en,
							.tBit.pen_s_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_s_en,
							.tBit.pen_d_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_d_en,
							.tBit.finger_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_finger_en,
							.tBit.pen_s_dmy_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_s_dmy_en,
							.tBit.pen_d_dmy_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_d_dmy_en,
							.tBit.finger_dmy_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_finger_dmy_en,
							.tBit.pen_s_set_tx_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_s_set_tx_en,
							.tBit.pen_d_set_tx_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_d_set_tx_en,
							.tBit.finger_set_tx_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_finger_set_tx_en,
							.tBit.nm_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_nm_en,
							.tBit.inv_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_inv_en,
							.tBit.pwm_2x_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pwm_2x_en,
							.tBit.pen_s_tsync_d2_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_s_tsync_d2_en,
							.tBit.pen_d_tsync_d2_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_pen_d_tsync_d2_en,
							.tBit.finger_tsync_d2_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_finger_tsync_d2_en,
							.tBit.ping_only_en = PARAMSET_PWMDRV_WGP_PWM_SRIC_CR_ping_only_en,
						},
						.tCP_PWM_MUX_CR =
						{
							.tBit.beacon_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_beacon_en,
							.tBit.pen_s_ping_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_s_ping_en,
							.tBit.pen_d_ping_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_d_ping_en,
							.tBit.finger_ping_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_finger_ping_en,
							.tBit.pen_s_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_s_en,
							.tBit.pen_d_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_d_en,
							.tBit.finger_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_finger_en,
							.tBit.pen_s_dmy_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_s_dmy_en,
							.tBit.pen_d_dmy_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_d_dmy_en,
							.tBit.finger_dmy_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_finger_dmy_en,
							.tBit.pen_s_set_tx_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_s_set_tx_en,
							.tBit.pen_d_set_tx_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_pen_d_set_tx_en,
							.tBit.finger_set_tx_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_finger_set_tx_en,
							.tBit.nm_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_nm_en,
							.tBit.inv_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_inv_en,
							.tBit.ping_only_en = PARAMSET_PWMDRV_WGP_PWM_MUX_CR_ping_only_en,
						},
						.tCP_DMY_FREQ = PARAMSET_PWMDRV_WGP_DMY_FREQ,
						.tCP_FREQ_CR1 =
						{
							.tBit.pen_d = PARAMSET_PWMDRV_WGP_PEN_DAT_FREQ,//PWM_Full_KHz(114),
							.tBit.pen_s = PARAMSET_PWMDRV_WGP_PEN_POS_FREQ,//PWM_Full_KHz(114),
							.tBit.finger = PARAMSET_PWMDRV_WGP_FINGER_FREQ,//PWM_Full_KHz(114),
						},
						.tCP_FREQ_CR2 =
						{
							.tBit.freq_beacon = PARAMSET_PWMDRV_WGP_Beacon_FREQ,
						},
						.tCP_LHB_CONFIG11 =
						{
							.tBit.lhb1 = PARAMSET_PWMDRV_WGP_FULL_LHB_1,
							.tBit.lhb2 = PARAMSET_PWMDRV_WGP_FULL_LHB_2,
							.tBit.lhb3 = PARAMSET_PWMDRV_WGP_FULL_LHB_3,
							.tBit.lhb4 = PARAMSET_PWMDRV_WGP_FULL_LHB_4,
							.tBit.lhb5 = PARAMSET_PWMDRV_WGP_FULL_LHB_5,
							.tBit.lhb6 = PARAMSET_PWMDRV_WGP_FULL_LHB_6,
							.tBit.lhb7 = PARAMSET_PWMDRV_WGP_FULL_LHB_7,
							.tBit.lhb8 = PARAMSET_PWMDRV_WGP_FULL_LHB_8,
							.tBit.lhb9 = PARAMSET_PWMDRV_WGP_FULL_LHB_9,
							.tBit.lhb10 = PARAMSET_PWMDRV_WGP_FULL_LHB_10,
						},
						.tCP_LHB_CONFIG12 =
						{
							.tBit.lhb11 = PARAMSET_PWMDRV_WGP_FULL_LHB_11,
							.tBit.lhb12 = PARAMSET_PWMDRV_WGP_FULL_LHB_12,
							.tBit.lhb13 = PARAMSET_PWMDRV_WGP_FULL_LHB_13,
							.tBit.lhb14 = PARAMSET_PWMDRV_WGP_FULL_LHB_14,
							.tBit.lhb15 = PARAMSET_PWMDRV_WGP_FULL_LHB_15,
							.tBit.lhb16 = PARAMSET_PWMDRV_WGP_FULL_LHB_16,
							.tBit.lhb17 = PARAMSET_PWMDRV_WGP_FULL_LHB_17,
							.tBit.lhb18 = PARAMSET_PWMDRV_WGP_FULL_LHB_18,
							.tBit.lhb19 = PARAMSET_PWMDRV_WGP_FULL_LHB_19,
							.tBit.lhb20 = PARAMSET_PWMDRV_WGP_FULL_LHB_20,
						},
						.tCP_LHB_CONFIG13 =
						{
							.tBit.lhb21 = PARAMSET_PWMDRV_WGP_FULL_LHB_21,
							.tBit.lhb22 = PARAMSET_PWMDRV_WGP_FULL_LHB_22,
							.tBit.lhb23 = PARAMSET_PWMDRV_WGP_FULL_LHB_23,
							.tBit.lhb24 = PARAMSET_PWMDRV_WGP_FULL_LHB_24,
							.tBit.lhb25 = PARAMSET_PWMDRV_WGP_FULL_LHB_25,
							.tBit.lhb26 = PARAMSET_PWMDRV_WGP_FULL_LHB_26,
							.tBit.lhb27 = PARAMSET_PWMDRV_WGP_FULL_LHB_27,
							.tBit.lhb28 = PARAMSET_PWMDRV_WGP_FULL_LHB_28,
							.tBit.lhb29 = PARAMSET_PWMDRV_WGP_FULL_LHB_29,
							.tBit.lhb30 = PARAMSET_PWMDRV_WGP_FULL_LHB_30,
						},
						.tCP_LHB_CONFIG14 =
						{
							.tBit.lhb31 = PARAMSET_PWMDRV_WGP_FULL_LHB_31,
							.tBit.lhb32 = PARAMSET_PWMDRV_WGP_FULL_LHB_32,
						},
						.tCP_LHB_CONFIG21 =
						{
							.tBit.lhb1 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_1,
							.tBit.lhb2 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_2,
							.tBit.lhb3 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_3,
							.tBit.lhb4 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_4,
							.tBit.lhb5 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_5,
							.tBit.lhb6 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_6,
							.tBit.lhb7 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_7,
							.tBit.lhb8 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_8,
							.tBit.lhb9 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_9,
							.tBit.lhb10 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_10,
						},
						.tCP_LHB_CONFIG22 =
						{
							.tBit.lhb11 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_11,
							.tBit.lhb12 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_12,
							.tBit.lhb13 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_13,
							.tBit.lhb14 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_14,
							.tBit.lhb15 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_15,
							.tBit.lhb16 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_16,
							.tBit.lhb17 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_17,
							.tBit.lhb18 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_18,
							.tBit.lhb19 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_19,
							.tBit.lhb20 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_20,
						},
						.tCP_LHB_CONFIG23 =
						{
							.tBit.lhb21 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_21,
							.tBit.lhb22 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_22,
							.tBit.lhb23 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_23,
							.tBit.lhb24 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_24,
							.tBit.lhb25 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_25,
							.tBit.lhb26 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_26,
							.tBit.lhb27 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_27,
							.tBit.lhb28 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_28,
							.tBit.lhb29 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_29,
							.tBit.lhb30 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_30,
						},
						.tCP_LHB_CONFIG24 =
						{
							.tBit.lhb31 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_31,
							.tBit.lhb32 = PARAMSET_PWMDRV_WGP_LOCAL_LHB_32,
						},
						.tCP_PING_CR =
						{
							.tBit.beacon = DISABLE,
							.tBit.pen_s = DISABLE,
							.tBit.pen_d = DISABLE,
							.tBit.finger = DISABLE,
							.tBit.nm = DISABLE,
							.tBit.none = DISABLE,
							.tBit.ping_only = DISABLE,
						},
						.tCP_SYNC_GEN_CR =
						{
							.tBit.sync_gen_en = DISABLE,
							.tBit.vsync_stuck_en = DISABLE,
							.tBit.vsync_stuck_level = 0,
							.tBit.tsynct_stuck_en = DISABLE,
							.tBit.tsynct_stuck_level = 0,
							.tBit.tsyncd_stuck_en = DISABLE,
							.tBit.tsyncd_stuck_level = 0,
						},
						/*
						 * PWM Clock Default (DIV /128)
						 */
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
						.tCP_TE_RDY_CNT = 50,
						.tCP_TE_TCH_V_FPCH = 2,//2,
						.tCP_TE_TCH_V_HIGH = 2,//2,
						.tCP_TE_TCH_FPCH = 2,//1,
						.tCP_TE_TCH_T_HIGH = 230,//94,//153,
						.tCP_TE_TCH_D_HIGH = 92,//13,
						.tCP_TE_TCH_LOW = 96,//133,
						.tCP_TE_TCH_BPCH = 230,
						.tCP_TE_TCH_PD_LOW = 200,
						.tCP_TG_DUM1 = 0,
						.tCP_TG_DUM2 = 0,
						.tCP_TG_DUM3 = 0,
						.tCP_TG_DUM4 = 0,
						.tCP_TG_DUM5 =
						{
							.tBit.tsync_tpic_out_bypass_enb = PARAMSET_PWMDRV_WGP_TG_DUM5_tsync_tpic_out_bypass_enb,
#if USED_OPERATION_STAND_ALONE
							.tBit.tsync_sric_out_bypass_enb = 1, //0:Bypass, 1:Internal Timing
#else
							.tBit.tsync_sric_out_bypass_enb = 0, //0:Bypass, 1:Internal Timing
#endif
							.tBit.tsync_sric_lhb_ping_en = 0,
							.tBit.sync_gen_fr_done_mask_en = 0,
							.tBit.disp_off_beacon_only = 0,
						},
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
						.tCP_TE_RDY_CNT = 50,
						.tCP_TE_TCH_V_FPCH = 2,
						.tCP_TE_TCH_V_HIGH = 2,
						.tCP_TE_TCH_FPCH = 2,
#if (LHB_NUM == 10)
						.tCP_TE_TCH_T_HIGH = 170,//94,
#else
						.tCP_TE_TCH_T_HIGH = 94,
#endif
						.tCP_TE_TCH_D_HIGH = 92,
						.tCP_TE_TCH_LOW = 96,
						.tCP_TE_TCH_BPCH = 3,
						.tCP_TE_TCH_PD_LOW = 4,
						.tCP_TG_DUM1 = 0,
						.tCP_TG_DUM2 = 0,
						.tCP_TG_DUM3 = 0,
						.tCP_TG_DUM4 = 0,
						.tCP_TG_DUM5 =
						{
							.tBit.tsync_tpic_out_bypass_enb = PARAMSET_PWMDRV_WGP_TG_DUM5_tsync_tpic_out_bypass_enb,
#if USED_OPERATION_STAND_ALONE
							.tBit.tsync_sric_out_bypass_enb = 1, //0:Bypass, 1:Internal Timing
#else
							.tBit.tsync_sric_out_bypass_enb = 0, //0:Bypass, 1:Internal Timing
#endif
							.tBit.tsync_sric_lhb_ping_en = 0,
							.tBit.sync_gen_fr_done_mask_en = 0,
							.tBit.disp_off_beacon_only = 0,
						},
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */						
						.tCP_DISP_OFF_CR =
						{
							.tBit.stuck_en = DISABLE,
							.tBit.stuck_value = 0,
							.tBit.disp_off_fpnt = PWM_nsec(59600),
							.tBit.inv_en = 0,
						},
						.tCP_PWM_CR1 =
						{
							.tBit.pen_s_h_pnt = PARAMSET_PWMDRV_WGP_PWM_CR2_pen_s_h_pnt,//PWM_Half_KHz(114)+1,
							.tBit.pen_d_h_pnt = PARAMSET_PWMDRV_WGP_PWM_CR2_pen_d_h_pnt,//PWM_Half_KHz(114)+1,
						},
						.tCP_PWM_CR2 =
						{
							.tBit.finger_h_pnt = PARAMSET_PWMDRV_WGP_PWM_CR2_finger_h_pnt,
							.tBit.dmy_h_pnt = PARAMSET_PWMDRV_WGP_PWM_CR2_dmy_h_pnt,
						},
						.tCP_VSYNC_CR =
						{
							.tBit.vsync_in_inv = 0,
							.tBit.vsync_in_sel = PWM_VSYNC_INTR_INTERNAL,
							.tBit.vsync_locate = 9,
							.tBit.rising_pnt = 0,
							.tBit.falling_pnt = 0,
							.tBit.vsync_kiosk_in_sel = 0,
							.tBit.gst_in_inv = 0,
						},
						.tCP_MUX_CR =
						{
							.tBit.pen_s = PARAMSET_PWMDRV_WGP_MUX_CR_pen_s,
							.tBit.pen_d = PARAMSET_PWMDRV_WGP_MUX_CR_pen_d,
							.tBit.finger = PARAMSET_PWMDRV_WGP_MUX_CR_finger,
							.tBit.nm = 0,
						},
						.tCP_PWM_TPIC_ST_CR =
						{
							.tBit.beacon_stuck = 0,
							.tBit.pen_s_ping_stuck = 0,
							.tBit.pen_d_ping_stuck = 0,
							.tBit.finger_ping_stuck = 0,
							.tBit.pen_s_stuck = 0,
							.tBit.pen_d_stuck = 0,
							.tBit.finger_stuck = 0,
							.tBit.pen_s_dmy_stuck = 0,
							.tBit.pen_d_dmy_stuck = 0,
							.tBit.finger_dmy_stuck = 0,
							.tBit.pen_s_set_tx_stuck = 0,
							.tBit.pen_d_set_tx_stuck = 0,
							.tBit.finger_set_tx_stuck = 0,
							.tBit.nm_stuck = 0,
						},
						.tCP_PWM_SRIC_ST_CR =
						{
							.tBit.beacon_stuck = 0,
							.tBit.pen_s_ping_stuck = 0,
							.tBit.pen_d_ping_stuck = 0,
							.tBit.finger_ping_stuck = 0,
							.tBit.pen_s_stuck = 0,
							.tBit.pen_d_stuck = 0,
							.tBit.finger_stuck = 0,
							.tBit.pen_s_dmy_stuck = 0,
							.tBit.pen_d_dmy_stuck = 0,
							.tBit.finger_dmy_stuck = 0,
							.tBit.pen_s_set_tx_stuck = 0,
							.tBit.pen_d_set_tx_stuck = 0,
							.tBit.finger_set_tx_stuck = 0,
							.tBit.nm_stuck = 0,
						},
						.tCP_PWM_MUX_ST_CR =
						{
							.tBit.beacon_stuck = 0,
							.tBit.pen_s_ping_stuck = 0,
							.tBit.pen_d_ping_stuck = 0,
							.tBit.finger_ping_stuck = 0,
							.tBit.pen_s_stuck = 0,
							.tBit.pen_d_stuck = 0,
							.tBit.finger_stuck = 0,
							.tBit.pen_s_dmy_stuck = 0,
							.tBit.pen_d_dmy_stuck = 0,
							.tBit.finger_dmy_stuck = 0,
							.tBit.pen_s_set_tx_stuck = 0,
							.tBit.pen_d_set_tx_stuck = 0,
							.tBit.finger_set_tx_stuck = 0,
							.tBit.nm_stuck = 0,
						},
						.tCP_NM_FREQ =
						{
							.tBit.freq_nm1 = 199,
							.tBit.freq_nm2 = 299,
							.tBit.freq_nm3 = 499,
						},
						.tCP_PWM_DLY2 =
						{
							.tBit.pwm_vgh_f = 0,
							.tBit.pwm_gma_f = 0,
						},
						.tCP_DLY_CNT4 =
						{
							.tBit.bgap_prd = PARAMSET_PWMDRV_WGP_DLY_CNT4_bgap_prd,//1940+12-360-720,//1950 PWM_nsec(1050),
							.tBit.bc_egap_prd = 0,
						},
						.tCP_KIOSK_VSYNC_TIMER = 0,
						.tCP_PWM_DLY3 =
						{
							.tBit.pwm_sric_p = 0,
							.tBit.pwm_tpic_p = 0,//PWM_nsec(1050),
							.tBit.pwm_mux_p = 0,//PWM_nsec(1050),
						},
						.tCP_PWM_DLY4 =
						{
							.tBit.pwm_vgh_p = 0,//PWM_nsec(1050),
							.tBit.pwm_gma_p = 0,//PWM_nsec(1050),
						},
	#if IS_MULTI_PROTOCOL_OPERATION
					},
	#endif
#endif /* IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION */
				},
				.tCP_ECLK_CR =
				{
					 .tBit.eclk_en = DISABLE,
					 .tBit.eclk0_inv_en = DISABLE,
					 .tBit.eclk1_inv_en = DISABLE,
					 .tBit.eclk_div_en = ENABLE,
					 .tBit.div_num = 0,
					 .tBit.eclk_force_on = PWM_ECLK_TSYNC_ON_OFF,//PWM_ECLK_ALWAYS_ON,//PWM_ECLK_TSYNC_ON_OFF,//PWM_ECLK_ALWAYS_ON,
					 .tBit.eclk_en_src0 = 0,
					 .tBit.eclk_en_src1 = 1,
					 .tBit.eclk_en_pnt = 0,
				},
			},
		},
		.tModule =
		{
			.tSRIC_Conf =
			{
				SRIC_Conf_Set
			},
		},
	},

	.vtParamModeConf =
	{
#if IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION
	#if IS_MULTI_PROTOCOL_OPERATION
		[PARAM_MODE_NORMAL] = // MS Pen Protocol
		{
	#endif /* IS_MULTI_PROTOCOL_OPERATION */
			.tAlgorithm =
			{
				.BaseLine =
				{
					.cNormalizeDelta   =					PARAMSET_NORMAL_MODE_ALGO_BaseLine_cNormalizeDelta,
					.ucDiscardFrameNum = 					PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucDiscardFrameNum,
					.ucInitialFrameNum = 					PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucInitialFrameNum,
					.usIIRCoef = 							PARAMSET_NORMAL_MODE_ALGO_BaseLine_usIIRCoef,
					.sBlockPosThd = 						PARAMSET_NORMAL_MODE_ALGO_BaseLine_sBlockPosThd,
					.sBlockNegThd = 						PARAMSET_NORMAL_MODE_ALGO_BaseLine_sBlockNegThd,
					.sAccumPosSumThd = 						PARAMSET_NORMAL_MODE_ALGO_BaseLine_sAccumPosSumThd,
					.sAccumNegSumThd = 						PARAMSET_NORMAL_MODE_ALGO_BaseLine_sAccumNegSumThd,
					.sIdle_BlockPosThd = 					PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_BlockPosThd,
					.sIdle_BlockNegThd = 					PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_BlockNegThd,
					.sIdle_SeedThd = 						PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_SeedThd,
					.sIdle_PosTotalSumThd = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_PosTotalSumThd,
					.sIdle_NegTotalSumThd = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_NegTotalSumThd,
					.sLocalIdle_BlockPosThd = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_BlockPosThd,
					.sLocalIdle_BlockNegThd = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_BlockNegThd,
					.sLocalIdle_PosTotalSumThd = 			PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_PosTotalSumThd,
					.sLocalIdle_NegTotalSumThd = 			PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_NegTotalSumThd,
	#if USED_LOCAL_PEN_HOVER_IDLE_TO_ACTIVE
					.ucLocalIdlePenHoverCheckFrameThd = 	PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucLocalIdlePenHoverCheckFrameThd,
	#endif /* USED_LOCAL_PEN_HOVER_IDLE_TO_ACTIVE */
					.sS3_BlockPosThd = 						PARAMSET_NORMAL_MODE_ALGO_BaseLine_sS3_BlockPosThd,
					.sS3_BlockNegThd = 						PARAMSET_NORMAL_MODE_ALGO_BaseLine_sS3_BlockNegThd,
					.sS3_PosTotalSumThd = 					PARAMSET_NORMAL_MODE_ALGO_BaseLine_sS3_PosTotalSumThd,
					.sS3_NegTotalSumThd = 					PARAMSET_NORMAL_MODE_ALGO_BaseLine_sS3_NegTotalSumThd,
					.iRecalCond1_PosSum_Thd = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_iRecalCond1_PosSum_Thd,
					.iRecalCond1_AccSum_Thd = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_iRecalCond1_AccSum_Thd,
					.iRecalCond2_AccSum_Thd = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_iRecalCond2_AccSum_Thd,
					.ucRecalCond1_WaitCnt = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucRecalCond1_WaitCnt,
					.ucRecalCond2_WaitCnt = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucRecalCond2_WaitCnt,
					.bFullModeReBaseCheckOff	=			PARAMSET_NORMAL_MODE_ALGO_BaseLine_bFullModeReBaseCheckOff,
					.bLocalModeReBaseCheckOff	=			PARAMSET_NORMAL_MODE_ALGO_BaseLine_bLocalModeReBaseCheckOff,
					.sFullLcoalChangeMinTh = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_sFullLcoalChangeMinTh,
					.cFullLcoalChangeMinThOffset = 			PARAMSET_NORMAL_MODE_ALGO_BaseLine_cFullLcoalChangeMinThOffset,
					.usMS_ContactTh_LocalMode	= 			PARAMSET_NORMAL_MODE_ALGO_BaseLine_usMS_ContactTh_LocalMode,
					.usMS_ContactTh_HoverMode	= 			PARAMSET_NORMAL_MODE_ALGO_BaseLine_usMS_ContactTh_HoverMode,
					.b2MUX_SUM_LocalSearchMode	 = 			PARAMSET_NORMAL_MODE_ALGO_BaseLine_b2MUX_SUM_LocalSearchMode,
					.b2MUX_SUM_LocalMode			=	 	PARAMSET_NORMAL_MODE_ALGO_BaseLine_b2MUX_SUM_LocalMode,
	#if USED_TOUCH_TUNING_PROCESS
					.bPen_2BASE				= 				0,
	#else /* USED_TOUCH_TUNING_PROCESS */
					.bPen_2BASE				= 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_bPen_2BASE,
	#endif /* USED_TOUCH_TUNING_PROCESS */
					.cFingerAreaPenDeltaDelete	=			PARAMSET_NORMAL_MODE_ALGO_BaseLine_cFingerAreaPenDeltaDelete,
					.cFingerAreaPenDeltaNoAcc	=			PARAMSET_NORMAL_MODE_ALGO_BaseLine_cFingerAreaPenDeltaNoAcc,
					.bFingerBaseTracking		= 			PARAMSET_NORMAL_MODE_ALGO_BaseLine_bFingerBaseTracking,
					.ucPP_MUX_Select			=			PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucPP_MUX_Select,
					.bDspA_Finger_CalculateDelta		= 	PARAMSET_NORMAL_MODE_ALGO_BaseLine_bDspA_Finger_CalculateDelta,
					.bDspA_LocalMode_PenPhase			= 	PARAMSET_NORMAL_MODE_ALGO_BaseLine_bDspA_LocalMode_PenPhase,
					.bDspA_LocalMode_CalculateDelta		= 	PARAMSET_NORMAL_MODE_ALGO_BaseLine_bDspA_LocalMode_CalculateDelta,
					.bDspA_SearchMode_PenPhase			= 	PARAMSET_NORMAL_MODE_ALGO_BaseLine_bDspA_SearchMode_PenPhase,
					.bDspA_SearchMode_CalculateDelta	= 	PARAMSET_NORMAL_MODE_ALGO_BaseLine_bDspA_SearchMode_CalculateDelta,
					.bFullFingerBaseTracking			=	PARAMSET_NORMAL_MODE_ALGO_BaseLine_bFullFingerBaseTracking,
		#if (LocalNormalizeEn == YES)
					.ucLocalNormalizeMaxOffset			=	PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucLocalNormalizeMaxOffset,
		#endif
				},
				.SensingFilter =
				{
					.cLineFilter = 							PARAMSET_NORMAL_MODE_ALGO_SensingFilter_cLineFilter,						// 0 : off, 1 : AVG SW, 2 : Fourth Min SW, 3 : AVG DSP_A
					.sLineFilterUpLimit = 					PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterUpLimit,
					.sLineFilterLowLimit = 					PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterLowLimit,
					.ucLineFilterColOffset = 				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucLineFilterColOffset,
					.ucLineFilterRepeatTH = 				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucLineFilterRepeatTH,
					.cLineFilterMinTH = 					PARAMSET_NORMAL_MODE_ALGO_SensingFilter_cLineFilterMinTH,
					.ucMinDeltaTh = 						PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucMinDeltaTh,
					.cLineFilter_Pen = 						PARAMSET_NORMAL_MODE_ALGO_SensingFilter_cLineFilter_Pen,                  // 0 : off, 1 : AVG SW, 2 : Fourth Min SW, 3 : AVG DSP_A
					.ucLocalSearchModeLineFilter=			PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucLocalSearchModeLineFilter,      // 0 : off, 1 : AVG SW, 2 : Fourth Min SW, 3 : AVG DSP_A
					.bRingRawLineFilter		= 				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_bRingRawLineFilter,
					.sLineFilterUpLimit_Pen = 				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterUpLimit_Pen,			// When Use AVG DSP_A Linefilter for Pen
					.sLineFilterLowLimit_Pen = 				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterLowLimit_Pen,			// When Use AVG DSP_A Linefilter for Pen
					.sLineFilterUpLimit_Idle =				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterUpLimit_Idle,
					.sLineFilterLowLimit_Idle =				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterLowLimit_Idle,
					.ucRingDeltaIIR_Coef			= 		PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucRingDeltaIIR_Coef,
					.sFingerAreaLineFilterLimit			=	PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sFingerAreaLineFilterLimit,
					.ucFingerAreaLineFilterOffset		=	PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucFingerAreaLineFilterOffset,
		#if (HighHoverDeltaIIR_En == YES)
					.ucHighHoverDeltaIIR_Coef			=	PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucHighHoverDeltaIIR_Coef,
		#endif
				},
				.Label =
				{
					.usSeedBase = 							PARAMSET_NORMAL_MODE_ALGO_Label_usSeedBase,//80,
					.ucSeedSlope = 							PARAMSET_NORMAL_MODE_ALGO_Label_ucSeedSlope,//3,
					.ucLabelNoiseThd =						PARAMSET_NORMAL_MODE_ALGO_Label_ucLabelNoiseThd,
					.bExpand = 								PARAMSET_NORMAL_MODE_ALGO_Label_bExpand,
					.bSplitSearchDirc_4_On				=	PARAMSET_NORMAL_MODE_ALGO_Label_bSplitSearchDirc_4_On,
					.usSmallNodeCnt = 						PARAMSET_NORMAL_MODE_ALGO_Label_usSmallNodeCnt,//15,
					.usMediumNodeCnt = 						PARAMSET_NORMAL_MODE_ALGO_Label_usMediumNodeCnt,//32,
					.ucMergeSmallThdPer = 					PARAMSET_NORMAL_MODE_ALGO_Label_ucMergeSmallThdPer,
					.ucMergeMediumThdPer = 					PARAMSET_NORMAL_MODE_ALGO_Label_ucMergeMediumThdPer,//90,
					.ucMergeSmallDiagThdPer = 				PARAMSET_NORMAL_MODE_ALGO_Label_ucMergeSmallDiagThdPer,//80,
					.ucMergeMediumDiagThdPer = 				PARAMSET_NORMAL_MODE_ALGO_Label_ucMergeMediumDiagThdPer,//90,
					.usLocalSeedBase = 						PARAMSET_NORMAL_MODE_ALGO_Label_usLocalSeedBase,
					.ucLocalSeedSlope = 					PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalSeedSlope,
					.usLocalSmallNodeCnt = 					PARAMSET_NORMAL_MODE_ALGO_Label_usLocalSmallNodeCnt,
					.usLocalMediumNodeCnt = 				PARAMSET_NORMAL_MODE_ALGO_Label_usLocalMediumNodeCnt,
					.ucLocalMergeSmallThdPer = 				PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalMergeSmallThdPer,
					.ucLocalMergeMediumThdPer = 			PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalMergeMediumThdPer,
					.usLocalSeedBase_Ring = 				PARAMSET_NORMAL_MODE_ALGO_Label_usLocalSeedBase_Ring,
					.ucRingSeedBase_Acoef				=	PARAMSET_NORMAL_MODE_ALGO_Label_ucRingSeedBase_Acoef,
					.ucRingSeedBase_Fcoef				=	PARAMSET_NORMAL_MODE_ALGO_Label_ucRingSeedBase_Fcoef,
					.ucLocalPenDetectTH1 = 					PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalPenDetectTH1,//90,//40,
					.ucLocalPenDetectTH2 = 					PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalPenDetectTH2, //220,//120,
					.ucLocalPenDetectTH1_Offset			=	PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalPenDetectTH1_Offset,
					.ucLocalPenDetectTH2_Offset			=	PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalPenDetectTH2_Offset,
					.ucHoverInCheckFrm = 					PARAMSET_NORMAL_MODE_ALGO_Label_ucHoverInCheckFrm,//2,
					.ucHoverOutCheckFrm = 					PARAMSET_NORMAL_MODE_ALGO_Label_ucHoverOutCheckFrm,//2,
					.ucHoverOutOffset = 					PARAMSET_NORMAL_MODE_ALGO_Label_ucHoverOutOffset,
					.usLabelPeakValleyDiffTh 			=   PARAMSET_NORMAL_MODE_ALGO_Label_usLabelPeakValleyDiffTh,
					.usLabelPeakDiffTh 					=   PARAMSET_NORMAL_MODE_ALGO_Label_usLabelPeakDiffTh,
					.usMergeLabelSizeTh 				=   PARAMSET_NORMAL_MODE_ALGO_Label_usMergeLabelSizeTh,
				},
				.Coord =
				{
					.usDistThdMovingToStationary = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usDistThdMovingToStationary,
					.usDistThdStationaryToMoving = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usDistThdStationaryToMoving,
					.lMoveSmoothingLevel = 					PARAMSET_NORMAL_MODE_ALGO_Coord_lMoveSmoothingLevel,
		#if (VECTOR_PREDICTION_EN == YES)
					.ucVectorPredictionCoef =				PARAMSET_NORMAL_MODE_ALGO_Coord_ucVectorPredictionCoef,
		#endif
		#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES)
					.ucLocalFingerInterpolation_On = 		PARAMSET_NORMAL_MODE_ALGO_Coord_ucLocalFingerInterpolation_On,
					.ucFullFingerInterpolation_On = 		PARAMSET_NORMAL_MODE_ALGO_Coord_ucFullFingerInterpolation_On,
					.sInterpolationWeight		=			PARAMSET_NORMAL_MODE_ALGO_Coord_sInterpolationWeight,					// For Win10Cer Reporting rate test & Duplicate packets error of Jitter test, HanCH
		#endif
					.ucFirstMoveEventTHD = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucFirstMoveEventTHD,
					.ucMoveEventTHD = 						PARAMSET_NORMAL_MODE_ALGO_Coord_ucMoveEventTHD,
					.sFingerGlobalCoordiXResolutionOffset = PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiXResolutionOffset,
					.sFingerGlobalCoordiYResolutionOffset = PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset,
					.sFingerGlobalCoordiOffsetX =        	PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiOffsetX,
					.sFingerGlobalCoordiOffsetY =        	PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiOffsetY,
		#if (FingerGlobalCoordiY_2Region_Set == YES)
					.sFingerGlobalCoordiY_2Region_boundary = 	PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiY_2Region_boundary,
					.sFingerGlobalCoordiYResolutionOffset1 =	PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset1,
					.sFingerGlobalCoordiOffsetY1 =				PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiOffsetY1,					
		#endif
		#if (SMOOTH_PASTORG_INTER_EN == YES)
					.ucSmoothPastOrgInter =					PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmoothPastOrgInter,
		#endif
					.cDisSmoothOffset =						PARAMSET_NORMAL_MODE_ALGO_Coord_cDisSmoothOffset,
					.bFingerMeanSmoothing =					PARAMSET_NORMAL_MODE_ALGO_Coord_bFingerMeanSmoothing,
					.ucWinCertAssistance = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucWinCertAssistance, 					//0 : Off, 1 : LGD MNT 27", 2 : LGD Kiosk
					.ucTouchCountMax = 						PARAMSET_NORMAL_MODE_ALGO_Coord_ucTouchCountMax, 						//LGD MNT 27" : 3, LGD Kiosk 43",55" : 30
					.ucMaxExtendFrameNum = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucMaxExtendFrameNum, 					//LGD MNT 27" : 10, LGD Kiosk 43", 55" : 100
					.usFirstDrawingThd		 = 				PARAMSET_NORMAL_MODE_ALGO_Coord_usFirstDrawingThd,
					.ucFirstDrawingCellCnt   = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucFirstDrawingCellCnt,
				},
				.CoordTracking =
				{
					.ucDynamicTrackingDistanceMode = 		PARAMSET_NORMAL_MODE_ALGO_Coord_ucDynamicTrackingDistanceMode,
					.ucFastDrawingMode = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucFastDrawingMode,
					.usMoveDistanceThd = 					PARAMSET_NORMAL_MODE_ALGO_Coord_usMoveDistanceThd,
					.usFirstMoveDistanceThd = 				PARAMSET_NORMAL_MODE_ALGO_Coord_usFirstMoveDistanceThd,
					.lLargeTouchOnThd = 					PARAMSET_NORMAL_MODE_ALGO_Coord_lLargeTouchOnThd,
					.ucLargeTouchOnDebCnt = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucLargeTouchOnDebCnt,
					.lMediumTouchOnThd = 					PARAMSET_NORMAL_MODE_ALGO_Coord_lMediumTouchOnThd,
					.ucMediumTouchOnDebCnt = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucMediumTouchOnDebCnt,
					.lSmallTouchOnThd = 					PARAMSET_NORMAL_MODE_ALGO_Coord_lSmallTouchOnThd,
					.ucSmallTouchOnDebCnt = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmallTouchOnDebCnt,
					.bEdgeDebCntUp = 						PARAMSET_NORMAL_MODE_ALGO_Coord_bEdgeDebCntUp,
					.sFirstTouchOnMaxCellVal = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchOnMaxCellVal,
					.lTouchOffThd = 						PARAMSET_NORMAL_MODE_ALGO_Coord_lTouchOffThd,
					.ucMultifingerFirstTouchThDownOffset =	PARAMSET_NORMAL_MODE_ALGO_Coord_ucMultifingerFirstTouchThDownOffset,
					.usCenterMatchDistanceThd = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usCenterMatchDistanceThd,
					.sFirstTouchEnable1Touch = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable1Touch, 				//Enable First touch
					.sFirstTouchEnable2Touch = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable2Touch,
					.sFirstTouchEnable3Touch = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable3Touch,
					.sFirstTouchEnable4Touch = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable4Touch,
					.sFirstTouchEnable5Touch = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable5Touch,
					.ucDebCntInner			 = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucDebCntInner,
					.ucDebCntEdge			 = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucDebCntEdge,
				},
				.CoordEdge =
				{
					.bExpectClipping_Finger_On = 			PARAMSET_NORMAL_MODE_ALGO_Coord_bExpectClipping_Finger_On,
					.cEdgeSmoothing_Finger_On = 			PARAMSET_NORMAL_MODE_ALGO_Coord_cEdgeSmoothing_Finger_On,
		#if (REMOVE_EDGE_EN == YES)
					.bRemoveEdge = 							PARAMSET_NORMAL_MODE_ALGO_Coord_bRemoveEdge,
					.usRemoveEdgeXdistThd =					PARAMSET_NORMAL_MODE_ALGO_Coord_usRemoveEdgeXdistThd,
					.usRemoveEdgeYdistThd =					PARAMSET_NORMAL_MODE_ALGO_Coord_usRemoveEdgeYdistThd,
		#endif
					.usPostProcessEdgeTH = 					PARAMSET_NORMAL_MODE_ALGO_Coord_usPostProcessEdgeTH,
					.ucPostProcessDisTH =					PARAMSET_NORMAL_MODE_ALGO_Coord_ucPostProcessDisTH,
					.ucPostProcessExpendDiv =				PARAMSET_NORMAL_MODE_ALGO_Coord_ucPostProcessExpendDiv,
					.cPostProcessEndMargin =				PARAMSET_NORMAL_MODE_ALGO_Coord_cPostProcessEndMargin,
					.bPostProcessInterpolationMode		=   PARAMSET_NORMAL_MODE_ALGO_Coord_bPostProcessInterpolationMode,
					.usOutInDrawEdgeTh = 					PARAMSET_NORMAL_MODE_ALGO_Coord_usOutInDrawEdgeTh,
					.ucOutInDrawDisTh = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucOutInDrawDisTh,
					.bUseNewCippingCond = 					PARAMSET_NORMAL_MODE_ALGO_Coord_bUseNewCippingCond,
				},
				.EdgeExpand =
				{
		#if (MULTI_EDGE_COEF_EN == YES)
					.bUseMultiEdgeCoef =					PARAMSET_NORMAL_MODE_ALGO_Coord_bUseMultiEdgeCoef,
					.usSmallTouchMaxDeltaThd = 				PARAMSET_NORMAL_MODE_ALGO_Coord_usSmallTouchMaxDeltaThd,
					.ucSmallTouchCellCntThd = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmallTouchCellCntThd,
					.ucSmallTouchHeightThd = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmallTouchHeightThd,
					.ucSmallTouchWidthThd = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmallTouchWidthThd,
		#endif
					.ucLeftEdgeExpand = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucLeftEdgeExpand,
					.ucRightEdgeExpand = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucRightEdgeExpand,
					.ucTopEdgeExpand = 						PARAMSET_NORMAL_MODE_ALGO_Coord_ucTopEdgeExpand,
					.ucBottomEdgeExpand = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucBottomEdgeExpand,
		#if (MULTI_EDGE_COEF_EN == YES)
					.ucLeftEdgeExpand_small = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucLeftEdgeExpand_small,
					.ucRightEdgeExpand_small = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucRightEdgeExpand_small,
					.ucTopEdgeExpand_small = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucTopEdgeExpand_small,
					.ucBottomEdgeExpand_small = 			PARAMSET_NORMAL_MODE_ALGO_Coord_ucBottomEdgeExpand_small,
					.ucLeftEdgeExpand_medium = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucLeftEdgeExpand_medium,
					.ucRightEdgeExpand_medium = 			PARAMSET_NORMAL_MODE_ALGO_Coord_ucRightEdgeExpand_medium,
					.ucTopEdgeExpand_medium = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucTopEdgeExpand_medium,
					.ucBottomEdgeExpand_medium = 			PARAMSET_NORMAL_MODE_ALGO_Coord_ucBottomEdgeExpand_medium,
		#endif
					.sXExpandStartOffset = 					PARAMSET_NORMAL_MODE_ALGO_Coord_sXExpandStartOffset,
					.sYExpandStartOffset = 					PARAMSET_NORMAL_MODE_ALGO_Coord_sYExpandStartOffset,
					.usLabelEdgeExpandMode = 				PARAMSET_NORMAL_MODE_ALGO_Coord_usLabelEdgeExpandMode,					//0: max_d = 100, 1: max_d = ulStrength (MAX), else: max_d = usLabelEdgeExpandMode
					.usLeftEdgeExpand_Offset   = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usLeftEdgeExpand_Offset,				//EdgeExpandFinger
					.usRightEdgeExpand_Offset  = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usRightEdgeExpand_Offset,
					.usTopEdgeExpand_Offset    = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usTopEdgeExpand_Offset,
					.usBottomEdgeExpand_Offset = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usBottomEdgeExpand_Offset,
					.usLeftEdgeExpand_Scale    = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usLeftEdgeExpand_Scale,
					.usRightEdgeExpand_Scale   = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usRightEdgeExpand_Scale,
					.usTopEdgeExpand_Scale     = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usTopEdgeExpand_Scale,
					.usBottomEdgeExpand_Scale  = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usBottomEdgeExpand_Scale,
		#if (BIG_FINGER_EDGE_EXPAND_ALGO_EN == YES)
					.usLeftEdgeExpand_MaxD		=			PARAMSET_NORMAL_MODE_ALGO_Coord_usLeftEdgeExpand_MaxD,					//For Win10Cer 16Phi & 7Phi Edge Test
					.usRightEdgeExpand_MaxD     =			PARAMSET_NORMAL_MODE_ALGO_Coord_usRightEdgeExpand_MaxD,
					.usTopEdgeExpand_MaxD       =			PARAMSET_NORMAL_MODE_ALGO_Coord_usTopEdgeExpand_MaxD,
					.usBottomEdgeExpand_MaxD    =			PARAMSET_NORMAL_MODE_ALGO_Coord_usBottomEdgeExpand_MaxD,
					.usBigFingerEdgeExpandParam1	=		PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeExpandParam1,
					.usBigFingerEdgeExpandParam2	=		PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeExpandParam2,
					.usBigFingerEdgeExpandParam3	=		PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeExpandParam3,
		#endif
		#if (BIG_FINGER_EDGE_ACC_TEST_ALGO_EN == YES)
					.ucEdgeReportDelayCnt			=		PARAMSET_NORMAL_MODE_ALGO_Coord_ucEdgeReportDelayCnt,//10,
					.usBigFingerEdgeTest_MoveEventTHD_X	=	PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeTest_MoveEventTHD_X,
					.usBigFingerEdgeTest_MoveEventTHD_Y	=	PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeTest_MoveEventTHD_Y,
					.usBigFingerEdgeTestClippingTop		=	PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeTestClippingTop,
					.usBigFingerEdgeTestClippingBottom	=	PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeTestClippingBottom,
					.usBigFingerEdgeTestClippingLeft	=	PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeTestClippingLeft,
					.usBigFingerEdgeTestClippingRight	=	PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeTestClippingRight,
					.bFingerCornerTestClippingOn		=	PARAMSET_NORMAL_MODE_ALGO_Coord_bFingerCornerTestClippingOn,
		#endif
				},
				.PenCoord =
				{
					.ucTipRangeExtend_On = 					PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucTipRangeExtend_On,
					.bExpectClipping_Pen_On = 				PARAMSET_NORMAL_MODE_ALGO_PenCoord_bExpectClipping_Pen_On,
					.ucCompenCoefA = 						PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucCompenCoefA,
					.ucCompenCoefB = 						PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucCompenCoefB,
					.ucHoverCompenCoefA = 					PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucHoverCompenCoefA,
					.ucHoverCompenCoefB	=					PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucHoverCompenCoefB,
					.bCompenEdgeOn =						PARAMSET_NORMAL_MODE_ALGO_PenCoord_bCompenEdgeOn,
					.ucPenPostProcessEdgeTH = 				PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenPostProcessEdgeTH,
					.ucPenPostProcessDisTH = 				PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenPostProcessDisTH,
					.ucPenPostProcessExpendDiv = 			PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenPostProcessExpendDiv,
					.cPenPostProcessEndMargin			=	PARAMSET_NORMAL_MODE_ALGO_PenCoord_cPenPostProcessEndMargin,
					.cHoverSmoothOffset	= 					PARAMSET_NORMAL_MODE_ALGO_PenCoord_cHoverSmoothOffset,
					.bFullFingerOn = 						PARAMSET_NORMAL_MODE_ALGO_PenCoord_bFullFingerOn,
					.sPenGlobalCoordiXResolutionOffset = 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiXResolutionOffset,
					.sPenGlobalCoordiYResolutionOffset = 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiYResolutionOffset,
					.sPenGlobalCoordiOffsetX = 			 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiOffsetX,
					.sPenGlobalCoordiOffsetY = 			 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiOffsetY,
		#if (PEN_EdgeExpandStartOffset_On == YES)
					.sXExpandStartOffset				=	PARAMSET_NORMAL_MODE_ALGO_PenCoord_sXExpandStartOffset,
					.sYExpandStartOffset				=	PARAMSET_NORMAL_MODE_ALGO_PenCoord_sYExpandStartOffset,
		#endif
					.ucLeftEdgeExpand_local = 				PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucLeftEdgeExpand_local,
					.ucRightEdgeExpand_local = 				PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucRightEdgeExpand_local,
					.ucTopEdgeExpand_local = 				PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucTopEdgeExpand_local,
					.ucBottomEdgeExpand_local = 			PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucBottomEdgeExpand_local,
					.uclatency_up_dis_condition			= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_uclatency_up_dis_condition,  // off : 0
					.uclatency_up_cnt_condition			= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_uclatency_up_cnt_condition,  // range : 0 ~ 255
					.clatency_up_dis_offset				=	PARAMSET_NORMAL_MODE_ALGO_PenCoord_clatency_up_dis_offset,
					.ucideal_inter_dis					= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_ideal_inter_dis,	// range : 0 ~ 255
					.ucideal_inter_mv					= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_ideal_inter_mv,	// range : 0 ~ 255
					.uc_connect_count					= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_uc_connect_count,
					.ucMarkBoundaryNum					= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucMarkBoundaryNum,
					.ucPenEdgeDebCnt                    =   PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenEdgeDebCnt,
					.usLongDisPointExceptionTH			= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_usLongDisPointExceptionTH,
					.usPannelOutSideHoverExceptionTH	=	PARAMSET_NORMAL_MODE_ALGO_PenCoord_usPannelOutSideHoverExceptionTH,			//PannelOutSideHoverException On & Thd , 210304 HanCH
					.usPannelOutSideContactExceptionTH	=	PARAMSET_NORMAL_MODE_ALGO_PenCoord_usPannelOutSideContactExceptionTH,			//PannelOutSideContactException On & Thd , 210304 HanCH
					.ucPannelOutSideHoverExceptionEdgeDis	=	PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPannelOutSideHoverExceptionEdgeDis,	//Edge Distance for PannelOutSideHoverException , 210304 HanCH
					.ucPannelOutSideContactExceptionEdgeDis	=   PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPannelOutSideContactExceptionEdgeDis,//Edge Distance for PannelOutSideContactException , 210304 HanCH
					.ucPannelOutSideContactExceptionPreDis	=   PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPannelOutSideContactExceptionPreDis,	//Past & Current Pos Distance for PannelOutSideContactException	, 210304 HanCH
		#if (OUT_IN_DRAWING == YES)
					.usOutInBoundTh							= PARAMSET_NORMAL_MODE_ALGO_PenCoord_usOutInBoundTh,
					.ucOutInDisTh							= PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucOutInDisTh,
		#endif
		#if (HIGH_HOVER_JITTER_REDUCE == YES)
					.sHighHoverJitterReduceDisScale			= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_sHighHoverJitterReduceDisScale,
					.ucHighHoverJitterReduceSmoothOffset	= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucHighHoverJitterReduceSmoothOffset,
		#endif
					.bUseNewCippingCond_Pen					= PARAMSET_NORMAL_MODE_ALGO_PenCoord_bUseNewCippingCond_Pen,
		#if (PEN_REMOVE_EDGE_EN == YES)
					.bRemoveEdge							= PARAMSET_NORMAL_MODE_ALGO_PenCoord_bRemoveEdge,
					.usRemoveEdgeXdistThd					= PARAMSET_NORMAL_MODE_ALGO_PenCoord_usRemoveEdgeXdistThd,
					.usRemoveEdgeYdistThd					= PARAMSET_NORMAL_MODE_ALGO_PenCoord_usRemoveEdgeYdistThd,
					.bUsetRealPastSentPos1					= PARAMSET_NORMAL_MODE_ALGO_PenCoord_bUsetRealPastSentPos1,
					.usEndCoordMargin						= PARAMSET_NORMAL_MODE_ALGO_PenCoord_usEndCoordMargin,
		#endif
				},
				.PenTilt =
				{
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
					.ucMS_RingMode						=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucMS_RingMode,	//	0 : LS10(PARTIAL_PEN_COORD3) Simbol6 Tilt Process(60Hz), 1 : LS2(PARTIAL_PEN_COORD1) Simbol6 Tilt Process(60Hz), 2 : LS10&LS2 Simbol6 Tilt Process(120Hz), 201222,HanCH
		#endif			
					.bTiltCalOnlyContact				=  	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltCalOnlyContact,
					.cHoverOverShiftRingOffset			=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_cHoverOverShiftRingOffset,
		#if (HoverDeltaMul_EN == YES)
					.ucHoverDeltaMul					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHoverDeltaMul,					
		#endif
					.bRingRangeExtend_On 				= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bRingRangeExtend_On,
		#if (RangeExtend_v2_En == YES)
					.usTiltSubMaxDelta					= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTiltSubMaxDelta,
					.usTiltDivMin						= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTiltDivMin,
					.usTiltDivMax						= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTiltDivMax,
		#endif
					.ucRingCompenCoefA 					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucRingCompenCoefA,
					.ucRingCompenCoefB 					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucRingCompenCoefB,
		#if (RingCoordSmooth_En == YES)
					.ucRingCoordSmoothCoef				= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucRingCoordSmoothCoef,
		#endif
					.bTiltCalUsingTipOrg				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltCalUsingTipOrg,
					.ucCoordiShiftX_WithTilt  			=   PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftX_WithTilt,		// 0 : Shift Off
					.ucCoordiShiftY_WithTilt  			=   PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftY_WithTilt,
					.ucCoordiShiftEdgeOn				= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftEdgeOn,  	// 0 : Edge Off , 1 : Center Same Coef , 2 : Coef Up
					.ucCoordiShiftWithTilt_RingTH		=   PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftWithTilt_RingTH,
					.ucCoordiShiftWithTiltCompenTH		= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftWithTiltCompenTH,
					.ucTiltL							= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucTiltL,
		#if (TiltChangeLimitFilter == YES)
					.usTiltChangeLimitFilter			= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTiltChangeLimitFilter,
		#endif
					.ucTiltSmoothingFilterCoef			= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucTiltSmoothingFilterCoef, //Max : 32
					.ucHalfCoefSmoothFrm				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHalfCoefSmoothFrm,
					.ucHalfCoef							= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHalfCoef,
		#if (HighDeltaTiltSmoothCoefChange == YES)
					.ucHighDelta_TiltSmooth_change_Th	= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHighDelta_TiltSmooth_change_Th,
					.cHighDelta_TiltSmooth_change_offset=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_cHighDelta_TiltSmooth_change_offset,
		#endif
		#if (TILT_AREA_FILTER == YES)
					.usTilt_Change_TH_Reverse			=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTilt_Change_TH_Reverse,
					.usTilt_Change_TH_Right				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTilt_Change_TH_Right,
		#endif
					.bRingCoordiReport					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bRingCoordiReport,
					.ucRingMarkBoundaryNum				= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucRingMarkBoundaryNum,
		#if (TiltBasedRingDelta == YES)
					.bTiltBasedRingDelta				= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltBasedRingDelta,
		#endif
		#if (TiltDirecLimitFilter == YES)	
					.bTiltDirecLimitFilter				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltDirecLimitFilter,
		#endif
		#if (TiltDeltaLimit_EN == YES)
					.ucTiltDeltaLimitFilter				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucTiltDeltaLimitFilter,
					.usTiltDeltaLimit_10_TH				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTiltDeltaLimit_10_TH,
					.usTiltDeltaLimit_55_TH				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTiltDeltaLimit_55_TH,
					.usTiltDeltaLimit_60_TH				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTiltDeltaLimit_60_TH,
					.usTiltDeltaLimit_65_TH				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTiltDeltaLimit_65_TH,
		#endif
		#if (TiltMedianFilter == YES)
					.bTiltMedianFilter					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltMedianFilter,
		#endif
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
					.bRingBaseTracking					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bRingBaseTracking,
		#endif
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
					.bTiltRowIndexChange				= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltRowIndexChange,
		#endif
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)	
					.ucRingDirecPosCoef					=   PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucRingDirecPosCoef,
					.ucRingTipDeltaSumCoef				= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucRingTipDeltaSumCoef,
					.ucRingTipDeltaSumTH				= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucRingTipDeltaSumTH,
					.b2MUX_SUM_RingMode					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_b2MUX_SUM_RingMode,
					.ucTipDirecShiftBasedRingDelta		=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucTipDirecShiftBasedRingDelta,
		#endif
		#if (TiltArcSinLookUp_Num > 3)
					.bArcSinLookUp_1					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bArcSinLookUp_1,
		#endif
		#if (UseLastContact3x3 == YES)
					.usReleaseLastContact3x3Frm 		=   PARAMSET_NORMAL_MODE_ALGO_PenTilt_usReleaseLastContact3x3Frm,
					.usUseLastContact3x3Th				=   PARAMSET_NORMAL_MODE_ALGO_PenTilt_usUseLastContact3x3Th,
		#endif
		#if (CORNER_CoordiShift_WithTilt_ADD == YES)
					.cCoordiShiftX_WithTilt_Corner_LT  = PARAMSET_NORMAL_MODE_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_LT,
					.cCoordiShiftY_WithTilt_Corner_LT  = PARAMSET_NORMAL_MODE_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_LT,
					.cCoordiShiftX_WithTilt_Corner_RT  = PARAMSET_NORMAL_MODE_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_RT,
					.cCoordiShiftY_WithTilt_Corner_RT  = PARAMSET_NORMAL_MODE_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_RT,
					.cCoordiShiftX_WithTilt_Corner_LB  = PARAMSET_NORMAL_MODE_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_LB,
					.cCoordiShiftY_WithTilt_Corner_LB  = PARAMSET_NORMAL_MODE_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_LB,
					.cCoordiShiftX_WithTilt_Corner_RB  = PARAMSET_NORMAL_MODE_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_RB,
					.cCoordiShiftY_WithTilt_Corner_RB  = PARAMSET_NORMAL_MODE_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_RB,
		#endif
				},
				.PenData =
				{
					.ucAdaptive_contact_th = 				PARAMSET_NORMAL_MODE_ALGO_PenData_ucAdaptive_contact_th,
					.ucPenDataLocalTHD = 					PARAMSET_NORMAL_MODE_ALGO_PenData_ucPenDataLocalTHD,
					.ucPenDataHoverTHD = 					PARAMSET_NORMAL_MODE_ALGO_PenData_ucPenDataHoverTHD,
					.sPenDataHoverButtonTHD				=	PARAMSET_NORMAL_MODE_ALGO_PenData_sPenDataHoverButtonTHD,					//Button & ID Data 3x3 sum ON & Button Thd , 210304 HanCH
					.usPenDataHighHoverButtonRejectTHD = 	PARAMSET_NORMAL_MODE_ALGO_PenData_usPenDataHighHoverButtonRejectTHD,
					.ucPenDataHighHoverButton1ReliableCnt = PARAMSET_NORMAL_MODE_ALGO_PenData_ucPenDataHighHoverButton1ReliableCnt,	//Button1 Continue Count Check On & Count in HighHoverButtonRejectTHD , 210304 HanCH
					.ucPenDataHighHoverButton2ReliableCnt = PARAMSET_NORMAL_MODE_ALGO_PenData_ucPenDataHighHoverButton2ReliableCnt,	//Button2 Continue Count Check On & Count in HighHoverButtonRejectTHD , 210304 HanCH
					.ucPenDataHighHoverButtonAdopThOffset =	PARAMSET_NORMAL_MODE_ALGO_PenData_ucPenDataHighHoverButtonAdopThOffset,	//Button Adoptive Th On & Offset in HighHoverButtonRejectTHD , 210304 HanCH
					.ucPenDataHighHoverButtonIIRcoef	  = PARAMSET_NORMAL_MODE_ALGO_PenData_ucPenDataHighHoverButtonIIRcoef,		//Button & ID Data IIR On & Coef , 210304 HanCH
					.ucForcePenContact_NUM = 				PARAMSET_NORMAL_MODE_ALGO_PenData_ucForcePenContact_NUM,
					.ucAbnormalContactRemoveDeltaTH1 = 		PARAMSET_NORMAL_MODE_ALGO_PenData_ucAbnormalContactRemoveDeltaTH1,
					.ucAbnormalContactRemoveDeltaTH2 = 	    PARAMSET_NORMAL_MODE_ALGO_PenData_ucAbnormalContactRemoveDeltaTH2,
					.ucAbnormalContactRemovePressureTH1 =   PARAMSET_NORMAL_MODE_ALGO_PenData_ucAbnormalContactRemovePressureTH1,
					.ucAbnormalContactRemovePressureTH2 =   PARAMSET_NORMAL_MODE_ALGO_PenData_ucAbnormalContactRemovePressureTH2,
					.ucSEN_CONT_CNT						=	PARAMSET_NORMAL_MODE_ALGO_PenData_ucSEN_CONT_CNT,
					.ucKeepProtocolNum =					PARAMSET_NORMAL_MODE_ALGO_PenData_ucKeepProtocolNum,
				},
				.EdgePenSetVal =
				{
					.top_th = 								PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_th,//0,
					.top_mul = 								PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_mul,
					.top_SR = 								PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_SR,
					.bottom_th = 							PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_th,//0,
					.bottom_mul = 							PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_mul,
					.bottom_SR = 							PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_SR,
					.left_th = 								PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_th,//0,
					.left_mul = 							PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_mul,
					.left_SR = 								PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_SR,
					.right_th = 							PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_th,//0,
					.right_mul = 							PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_mul,
					.right_SR = 							PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_SR,
					.top_hover_th = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_hover_th,//580,
					.top_hover_mul = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_hover_mul,//19,
					.top_hover_SR = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_hover_SR,//4,
					.bottom_hover_th = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_hover_th,//580,
					.bottom_hover_mul = 					PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_hover_mul,//24,//19,
					.bottom_hover_SR = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_hover_SR,//4,
					.left_hover_th =						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_hover_th,//620,
					.left_hover_mul =						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_hover_mul,//19,
					.left_hover_SR = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_hover_SR,//4,
					.right_hover_th = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_hover_th,//620,
					.right_hover_mul = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_hover_mul,//19,
					.right_hover_SR = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_hover_SR,//4,
					.top_ring_th = 							PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_ring_th,
					.top_ring_mul = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_ring_mul,
					.top_ring_SR = 							PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_ring_SR,
					.bottom_ring_th = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_ring_th,//600,
					.bottom_ring_mul = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_ring_mul,
					.bottom_ring_SR = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_ring_SR,
					.left_ring_th = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_ring_th,//600,
					.left_ring_mul = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_ring_mul,
					.left_ring_SR = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_ring_SR,
					.right_ring_th = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_ring_th,//600,
					.right_ring_mul = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_ring_mul,
					.right_ring_SR = 						PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_ring_SR,
					.chover_mul_button1_offset			=	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_chover_mul_button1_offset,
				},
				.PenDisBaseSmoothSetVal =
				{
					.c_edge_smooth_offset_hover			= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_edge_smooth_offset_hover,				// range : -127 ~ 126, off : 127
					.c_edge_smooth_offset_contact  		= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_edge_smooth_offset_contact,  			// range : -127 ~ 126, off : 127
					.uc_global_smooth_dis_condition_contact=PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_dis_condition_contact,	// range : 1 ~ 255, off : 0
					.c_global_smooth_offset_contact  	= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_global_smooth_offset_contact,			// range : -127 ~ 127,
					.us_corner_smooth_delta_condition_hover=PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_us_corner_smooth_delta_condition_hover,  // range : 1 ~ 65535, off : 0
					.c_corner_smooth_offset_hover		= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_corner_smooth_offset_hover,			// range : -127 ~ 127
					.uc_edge_smooth_dis_condition_contact= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_edge_smooth_dis_condition_contact,	// range : 1 ~ 255
					.uc_global_smooth_delta_condition_hover=PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_delta_condition_hover,	// range : 1 ~ 255, off : 0
					.uc_global_smooth_dis_condition_hover= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_dis_condition_hover,	// range : 0 ~ 255
					.c_global_smooth_offset_hover		= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_global_smooth_offset_hover,			// range : -127 ~ 127
					.usEdge_Range						=	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_usEdge_Range,
				},
				.PenParaEdgeSetVal =
				{
					.th0 							= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_th0,			// mul1 off 255 set
					.top_mul0 						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_mul0,		// mul0 off 127 set
					.top_SR0 						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_SR0, 		// mul0 off 0 	set
					.top_mul1						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_mul1,
					.top_SR1						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_SR1,
					.bottom_mul0					= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_mul0,
					.bottom_SR0						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_SR0,
					.bottom_mul1					= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_mul1,
					.bottom_SR1						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_SR1,
					.left_mul0						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_mul0,
					.left_SR0						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_SR0,
					.left_mul1						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_mul1,
					.left_SR1						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_SR1,
					.right_mul0						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_mul0,
					.right_SR0						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_SR0,
					.right_mul1						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_mul1,
					.right_SR1						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_SR1,
					.top_max_sum 					= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_max_sum,
					.bottom_max_sum 				= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_max_sum,
					.left_max_sum 					= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_max_sum,
					.right_max_sum 					= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_max_sum,
					.top_max_sum_corner 			= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_max_sum_corner,
					.bottom_max_sum_corner			= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_max_sum_corner,
					.left_max_sum_corner 			= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_max_sum_corner,
					.right_max_sum_corner 			= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_max_sum_corner,
					.top_max_sum_hover 				= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_max_sum_hover,
					.bottom_max_sum_hover 			= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_max_sum_hover,
					.left_max_sum_hover 			= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_max_sum_hover,
					.right_max_sum_hover 			= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_max_sum_hover,
					.max_sum_hover_div 				= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_max_sum_hover_div,
		#if (PEN_CORNER_EXPEND_ADD == YES)	// For use, DeltaBaseNewEdgeCompen_SW must be set	
					.top_max_sum_corner1 			= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_max_sum_corner1,
					.bottom_max_sum_corner1			= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_max_sum_corner1,
					.left_max_sum_corner1 			= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_max_sum_corner1,
					.right_max_sum_corner1 			= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_max_sum_corner1,
					.max_sum_corner_TiltY_LT		=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltY_LT,
					.max_sum_corner_TiltY_RT		=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltY_RT,
					.max_sum_corner_TiltY_LB		=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltY_LB,
					.max_sum_corner_TiltY_RB		=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltY_RB,
					.max_sum_corner_TiltX_LT		=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltX_LT,
					.max_sum_corner_TiltX_RT		=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltX_RT,
					.max_sum_corner_TiltX_LB		=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltX_LB,
					.max_sum_corner_TiltX_RB		=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltX_RB,
		#endif
		#if (PEN_CORNER_EXPEND_ADD_1 == YES) // For use, DeltaBaseNewEdgeCompen_SW must be set	
					.top_mul0_LeftCornerOffset		=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_mul0_LeftCornerOffset,
					.top_max_sum_LeftCornerOffset	=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_max_sum_LeftCornerOffset,
					.top_mul0_RightCornerOffset		=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_mul0_RightCornerOffset,
					.top_max_sum_RightCornerOffset	=		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_max_sum_RightCornerOffset,
					.bottom_mul0_LeftCornerOffset		=	PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_mul0_LeftCornerOffset,
					.bottom_max_sum_LeftCornerOffset	=	PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_max_sum_LeftCornerOffset,
					.bottom_mul0_RightCornerOffset		=	PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_mul0_RightCornerOffset,
					.bottom_max_sum_RightCornerOffset	=	PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_max_sum_RightCornerOffset,
		#endif
		#if (PEN_Edge_UsePerMaxSum == YES)
					.ucUsePerMaxSum						=   PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_ucUsePerMaxSum,
					.ulExtStrengthInit					=	PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_ulExtStrengthInit,
		#endif

				},
				.Noise =
				{
					.ucNoiseDetectionMode = 				PARAMSET_NORMAL_MODE_ALGO_Noise_ucNoiseDetectionMode,		//0: OFF, 1 : previous 2 : LGD MNT 27"
					.ucDiscardFrameNum = 					PARAMSET_NORMAL_MODE_ALGO_Noise_ucDiscardFrameNum,
					.ucCellCntThd = 						PARAMSET_NORMAL_MODE_ALGO_Noise_ucCellCntThd,
					.ucHoppingThd = 						PARAMSET_NORMAL_MODE_ALGO_Noise_ucHoppingThd,
					.ucNoiseThd = 							PARAMSET_NORMAL_MODE_ALGO_Noise_ucNoiseThd,
					.usRawDataThd = 						PARAMSET_NORMAL_MODE_ALGO_Noise_usRawDataThd,
					.sDeltaDataThd = 						PARAMSET_NORMAL_MODE_ALGO_Noise_sDeltaDataThd,
					.ucTouchOffCntThd = 					PARAMSET_NORMAL_MODE_ALGO_Noise_ucTouchOffCntThd,
					.bPenNoiseReductionOff				=   PARAMSET_NORMAL_MODE_ALGO_Noise_bPenNoiseReductionOff,
					.ucPenFingerSameLineNoiseSize = 		PARAMSET_NORMAL_MODE_ALGO_Noise_ucPenFingerSameLineNoiseSize,
					.ucHoverNoiseRejectTH			=		PARAMSET_NORMAL_MODE_ALGO_Noise_ucHoverNoiseRejectTH,
					.ucHoverNoiseRejectFrm		=			PARAMSET_NORMAL_MODE_ALGO_Noise_ucHoverNoiseRejectFrm,
					.ucSearchNoiseRejectTH			=		PARAMSET_NORMAL_MODE_ALGO_Noise_ucSearchNoiseRejectTH,
					.ucSearchNoiseRejectFrm			=		PARAMSET_NORMAL_MODE_ALGO_Noise_ucSearchNoiseRejectFrm,
					.cAdaptorNoiseTH = 						PARAMSET_NORMAL_MODE_ALGO_Noise_cAdaptorNoiseTH,
					.ucAdaptorNoiseContiNum = 				PARAMSET_NORMAL_MODE_ALGO_Noise_ucAdaptorNoiseContiNum,
					.cAdaptorNoiseTH_SearchHover = 			PARAMSET_NORMAL_MODE_ALGO_Noise_cAdaptorNoiseTH_SearchHover,
					.ucAdaptorNoiseContiNum_SearchHover = 	PARAMSET_NORMAL_MODE_ALGO_Noise_ucAdaptorNoiseContiNum_SearchHover,
					.bPenPosSymbolRepeatCheck		=       PARAMSET_NORMAL_MODE_ALGO_Noise_bPenPosSymbolRepeatCheck,
					.ucCPITestOn = 							PARAMSET_NORMAL_MODE_ALGO_Noise_ucCPITestOn,
					.ucErrorFrameProcess = 					PARAMSET_NORMAL_MODE_ALGO_Noise_ucErrorFrameProcess,
					.ucHoppingMoveDistanceThd = 			PARAMSET_NORMAL_MODE_ALGO_Noise_ucHoppingMoveDistanceThd,
					.ucNoiseDetectMaxType = 				PARAMSET_NORMAL_MODE_ALGO_Noise_ucNoiseDetectMaxType,
					.bInitAddHoppingThd = 					PARAMSET_NORMAL_MODE_ALGO_Noise_bInitAddHoppingThd,
					.bHoppingConnectPenContact = 			PARAMSET_NORMAL_MODE_ALGO_Noise_bHoppingConnectPenContact,
					.ucNoiseStartThd = 						PARAMSET_NORMAL_MODE_ALGO_Noise_ucNoiseStartThd,
					.ucNoiseStartCntThd = 					PARAMSET_NORMAL_MODE_ALGO_Noise_ucNoiseStartCntThd,
				},
				.Palm =
				{
					.ucPalmDetectionOn = 					PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalmDetectionOn,		//0 : off, 1 : Version 1, 2 : Version 2, 3 : 1, 2 Adpative
					.usPalmLevel = 							PARAMSET_NORMAL_MODE_ALGO_Palm_usPalmLevel,//20,//12,
#if (PalmFirstDetectionShift == YES)
					.ucPalmLevelShift = 				PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalmLevelShift,
#endif
					.ucPalm_PALM_CONNECT_DIST = 			PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_PALM_CONNECT_DIST,
					.ucPalm_PALM_REGION_UPDATE_PERIOD =		PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_PALM_REGION_UPDATE_PERIOD,
					.ucPalm_TOUCHDOWNFRAMEMAX = 			PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_TOUCHDOWNFRAMEMAX,
					.ucPalm_TOUCHDOWNSLOPETHRESHOLD = 		PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_TOUCHDOWNSLOPETHRESHOLD,
					.ucPalm_IGNOREFRAMENUM = 				PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_IGNOREFRAMENUM,
					.ucPalm_KEEPPALMREGIONFRAME = 			PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_KEEPPALMREGIONFRAME,
#if (PalmDrawingOn_En == YES)
					.ucPalmDrawingOn = 						PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalmDrawingOn,
#endif
					.bPalm_WholeTouchRemove = 				PARAMSET_NORMAL_MODE_ALGO_Palm_bPalm_WholeTouchRemove,
#if (PENnPalm_PalmAreaMaintain_EN == YES)
					.bPenPalmDetection =					PARAMSET_NORMAL_MODE_ALGO_Palm_bPalm_bPenPalmDetection,
					.ucPenPalm_PALM_CONNECT_DIST = 			PARAMSET_NORMAL_MODE_ALGO_Palm_ucPenPalm_PALM_CONNECT_DIST,
					.ucPenPalm_KEEPPALMREGIONFRAME = 		PARAMSET_NORMAL_MODE_ALGO_Palm_ucPenPalm_KEEPPALMREGIONFRAME,
					.ucPen_KEEPFRAME = 						PARAMSET_NORMAL_MODE_ALGO_Palm_ucPen_KEEPFRAME,
					.ucPalmRelaseFrame =					PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalmRelaseFrame,
//					.ucFirstPalmSizeThd = 					PARAMSET_NORMAL_MODE_ALGO_Palm_ucFirstPalmSizeThd,
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */	
#if (PalmCandidateTouchCut_EN == YES)
					.usPalmCandiStdTh 					=	PARAMSET_NORMAL_MODE_ALGO_Palm_usPalmCandiStdTh,
					.ucPalmCandiShapeMatchingTh			=	PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalmCandiShapeMatchingTh,	
					.ucPalmCandiDeltaTh					=	PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalmCandiDeltaTh,
#endif					
				},
			},
			.tModule =
			{
				.ucOvrShift = 								PARAMSET_NORMAL_MODE_ALGO_ucOvrShift,//3,
				.ucIdleOvrShift = 							PARAMSET_NORMAL_MODE_ALGO_ucIdleOvrShift,//1,
				.ucLocalOvrShift = 							PARAMSET_NORMAL_MODE_ALGO_ucLocalOvrShift,//3,
				.ucLocalIdleOvrShift = 						PARAMSET_NORMAL_MODE_ALGO_ucLocalIdleOvrShift,//2,
				.ucLocalOvrShift_Ring = 					PARAMSET_NORMAL_MODE_ALGO_ucLocalOvrShift_Ring,//2,
			},
	#if IS_MULTI_PROTOCOL_OPERATION
		},
	#endif
#endif /* IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION */
#if IS_WGPPEN_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION
	#if IS_MULTI_PROTOCOL_OPERATION
		[PARAM_MODE_NORMAL_1] = // WGP Pen Protocol
		{
	#endif /* IS_MULTI_PROTOCOL_OPERATION */
			.tAlgorithm =
			{
				.BaseLine =
				{
					.cNormalizeDelta   =					PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_cNormalizeDelta,
					.ucDiscardFrameNum = 					PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_ucDiscardFrameNum,
					.ucInitialFrameNum = 					PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_ucInitialFrameNum,
					.usIIRCoef = 							PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_usIIRCoef,
					.sBlockPosThd = 						PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sBlockPosThd,
					.sBlockNegThd = 						PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sBlockNegThd,
					.sAccumPosSumThd = 						PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sAccumPosSumThd,
					.sAccumNegSumThd = 						PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sAccumNegSumThd,
					.sIdle_BlockPosThd = 					PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_BlockPosThd,
					.sIdle_BlockNegThd = 					PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_BlockNegThd,
					.sIdle_SeedThd = 						PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_SeedThd,
					.sIdle_PosTotalSumThd = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_PosTotalSumThd,
					.sIdle_NegTotalSumThd = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_NegTotalSumThd,
					.sLocalIdle_BlockPosThd = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_BlockPosThd,
					.sLocalIdle_BlockNegThd = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_BlockNegThd,
					.sLocalIdle_PosTotalSumThd = 			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_PosTotalSumThd,
					.sLocalIdle_NegTotalSumThd = 			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_NegTotalSumThd,
	#if USED_LOCAL_PEN_HOVER_IDLE_TO_ACTIVE
					.ucLocalIdlePenHoverCheckFrameThd = 	PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucLocalIdlePenHoverCheckFrameThd,
	#endif /* USED_LOCAL_PEN_HOVER_IDLE_TO_ACTIVE */

					.sS3_BlockPosThd = 						PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sS3_BlockPosThd,
					.sS3_BlockNegThd = 						PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sS3_BlockNegThd,
					.sS3_PosTotalSumThd = 					PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sS3_PosTotalSumThd,
					.sS3_NegTotalSumThd = 					PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sS3_NegTotalSumThd,
					.iRecalCond1_PosSum_Thd = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_iRecalCond1_PosSum_Thd,
					.iRecalCond1_AccSum_Thd = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_iRecalCond1_AccSum_Thd,
					.iRecalCond2_AccSum_Thd = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_iRecalCond2_AccSum_Thd,
					.ucRecalCond1_WaitCnt = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_ucRecalCond1_WaitCnt,
					.ucRecalCond2_WaitCnt = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_ucRecalCond2_WaitCnt,
					.bFullModeReBaseCheckOff	=			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bFullModeReBaseCheckOff,
					.bLocalModeReBaseCheckOff	=			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bLocalModeReBaseCheckOff,
					.sFullLcoalChangeMinTh = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sFullLcoalChangeMinTh,
					.cFullLcoalChangeMinThOffset = 			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_cFullLcoalChangeMinThOffset,
					.usMS_ContactTh_LocalMode	= 			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_usMS_ContactTh_LocalMode,
					.usMS_ContactTh_HoverMode	= 			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_usMS_ContactTh_HoverMode,
					.b2MUX_SUM_LocalSearchMode	 = 			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_b2MUX_SUM_LocalSearchMode,
					.b2MUX_SUM_LocalMode			=	 	PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_b2MUX_SUM_LocalMode,
	#if USED_TOUCH_TUNING_PROCESS
					.bPen_2BASE				= 				0,
	#else /* USED_TOUCH_TUNING_PROCESS */
					.bPen_2BASE				= 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bPen_2BASE,
	#endif /* USED_TOUCH_TUNING_PROCESS */
					.cFingerAreaPenDeltaDelete	=			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_cFingerAreaPenDeltaDelete,
					.cFingerAreaPenDeltaNoAcc	=			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_cFingerAreaPenDeltaNoAcc,
					.bFingerBaseTracking		= 			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bFingerBaseTracking,
					.ucPP_MUX_Select			=			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_ucPP_MUX_Select,
					.bDspA_Finger_CalculateDelta		= 	PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bDspA_Finger_CalculateDelta,
					.bDspA_LocalMode_PenPhase			= 	PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bDspA_LocalMode_PenPhase,
					.bDspA_LocalMode_CalculateDelta		= 	PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bDspA_LocalMode_CalculateDelta,
					.bDspA_SearchMode_PenPhase			= 	PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bDspA_SearchMode_PenPhase,
					.bDspA_SearchMode_CalculateDelta	= 	PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bDspA_SearchMode_CalculateDelta,
					.bFullFingerBaseTracking			=	PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bFullFingerBaseTracking,
				},
				.SensingFilter =
				{
					.cLineFilter = 							PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_cLineFilter,						// 0 : off, 1 : AVG SW, 2 : Fourth Min SW, 3 : AVG DSP_A
					.sLineFilterUpLimit = 					PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterUpLimit,
					.sLineFilterLowLimit = 					PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterLowLimit,
					.ucLineFilterColOffset = 				PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucLineFilterColOffset,
					.ucLineFilterRepeatTH = 				PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucLineFilterRepeatTH,
					.cLineFilterMinTH = 					PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_cLineFilterMinTH,
					.ucMinDeltaTh = 						PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucMinDeltaTh,
					.cLineFilter_Pen = 						PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_cLineFilter_Pen,                  // 0 : off, 1 : AVG SW, 2 : Fourth Min SW, 3 : AVG DSP_A
					.ucLocalSearchModeLineFilter=			PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucLocalSearchModeLineFilter,      // 0 : off, 1 : AVG SW, 2 : Fourth Min SW, 3 : AVG DSP_A
					.bRingRawLineFilter		= 				PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_bRingRawLineFilter,
					.sLineFilterUpLimit_Pen = 				PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterUpLimit_Pen,			// When Use AVG DSP_A Linefilter for Pen
					.sLineFilterLowLimit_Pen = 				PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterLowLimit_Pen,			// When Use AVG DSP_A Linefilter for Pen
					.sLineFilterUpLimit_Idle =				PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterUpLimit_Idle,
					.sLineFilterLowLimit_Idle =				PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterLowLimit_Idle,
					.ucRingDeltaIIR_Coef			= 		PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucRingDeltaIIR_Coef,
					.sFingerAreaLineFilterLimit			=	PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sFingerAreaLineFilterLimit,
					.ucFingerAreaLineFilterOffset		=	PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucFingerAreaLineFilterOffset,
		#if (HighHoverDeltaIIR_En == YES)
					.ucHighHoverDeltaIIR_Coef			=	PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucHighHoverDeltaIIR_Coef,
		#endif
				},
				.Label =
				{
					.usSeedBase = 							PARAMSET_NORMAL_MODE_1_ALGO_Label_usSeedBase,//80,
					.ucSeedSlope = 							PARAMSET_NORMAL_MODE_1_ALGO_Label_ucSeedSlope,//3,
					.ucLabelNoiseThd =						PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLabelNoiseThd,
					.bExpand = 								PARAMSET_NORMAL_MODE_1_ALGO_Label_bExpand,
					.bSplitSearchDirc_4_On				=	PARAMSET_NORMAL_MODE_1_ALGO_Label_bSplitSearchDirc_4_On,
					.usSmallNodeCnt = 						PARAMSET_NORMAL_MODE_1_ALGO_Label_usSmallNodeCnt,//15,
					.usMediumNodeCnt = 						PARAMSET_NORMAL_MODE_1_ALGO_Label_usMediumNodeCnt,//32,
					.ucMergeSmallThdPer = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_ucMergeSmallThdPer,
					.ucMergeMediumThdPer = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_ucMergeMediumThdPer,//90,
					.ucMergeSmallDiagThdPer = 				PARAMSET_NORMAL_MODE_1_ALGO_Label_ucMergeSmallDiagThdPer,//80,
					.ucMergeMediumDiagThdPer = 				PARAMSET_NORMAL_MODE_1_ALGO_Label_ucMergeMediumDiagThdPer,//90,
					.usLocalSeedBase = 						PARAMSET_NORMAL_MODE_1_ALGO_Label_usLocalSeedBase,
					.ucLocalSeedSlope = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalSeedSlope,
					.usLocalSmallNodeCnt = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_usLocalSmallNodeCnt,
					.usLocalMediumNodeCnt = 				PARAMSET_NORMAL_MODE_1_ALGO_Label_usLocalMediumNodeCnt,
					.ucLocalMergeSmallThdPer = 				PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalMergeSmallThdPer,
					.ucLocalMergeMediumThdPer = 			PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalMergeMediumThdPer,
					.usLocalSeedBase_Ring = 				PARAMSET_NORMAL_MODE_1_ALGO_Label_usLocalSeedBase_Ring,
					.ucRingSeedBase_Acoef				=	PARAMSET_NORMAL_MODE_1_ALGO_Label_ucRingSeedBase_Acoef,
					.ucRingSeedBase_Fcoef				=	PARAMSET_NORMAL_MODE_1_ALGO_Label_ucRingSeedBase_Fcoef,
					.ucLocalPenDetectTH1 = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalPenDetectTH1,//90,//40,
					.ucLocalPenDetectTH2 = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalPenDetectTH2, //220,//120,
					.ucLocalPenDetectTH1_Offset			=	PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalPenDetectTH1_Offset,
					.ucLocalPenDetectTH2_Offset			=	PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalPenDetectTH2_Offset,
					.ucHoverInCheckFrm = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_ucHoverInCheckFrm,//2,
					.ucHoverOutCheckFrm = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_ucHoverOutCheckFrm,//2,
					.ucHoverOutOffset = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_ucHoverOutOffset,
					.usLabelPeakValleyDiffTh 			=   PARAMSET_NORMAL_MODE_1_ALGO_Label_usLabelPeakValleyDiffTh,
					.usLabelPeakDiffTh 					=   PARAMSET_NORMAL_MODE_1_ALGO_Label_usLabelPeakDiffTh,
					.usMergeLabelSizeTh 				=   PARAMSET_NORMAL_MODE_1_ALGO_Label_usMergeLabelSizeTh,
				},
				.Coord =
				{
					.usDistThdMovingToStationary = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usDistThdMovingToStationary,
					.usDistThdStationaryToMoving = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usDistThdStationaryToMoving,
					.lMoveSmoothingLevel = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_lMoveSmoothingLevel,
		#if (VECTOR_PREDICTION_EN == YES)
					.ucVectorPredictionCoef =				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucVectorPredictionCoef,
		#endif
		#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES)
					.ucLocalFingerInterpolation_On = 		PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLocalFingerInterpolation_On,
					.ucFullFingerInterpolation_On = 		PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFullFingerInterpolation_On,
					.sInterpolationWeight		=			PARAMSET_NORMAL_MODE_1_ALGO_Coord_sInterpolationWeight,					// For Win10Cer Reporting rate test & Duplicate packets error of Jitter test, HanCH
		#endif
					.ucFirstMoveEventTHD = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFirstMoveEventTHD,
					.ucMoveEventTHD = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMoveEventTHD,
					.sFingerGlobalCoordiXResolutionOffset = PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiXResolutionOffset,
					.sFingerGlobalCoordiYResolutionOffset = PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset,
					.sFingerGlobalCoordiOffsetX =        	PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetX,
					.sFingerGlobalCoordiOffsetY =        	PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetY,
		#if (FingerGlobalCoordiY_2Region_Set == YES)
					.sFingerGlobalCoordiY_2Region_boundary = 	PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiY_2Region_boundary,
					.sFingerGlobalCoordiYResolutionOffset1 =	PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset1,
					.sFingerGlobalCoordiOffsetY1 =				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetY1,					
		#endif
		#if (SMOOTH_PASTORG_INTER_EN == YES)
					.ucSmoothPastOrgInter =					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmoothPastOrgInter,
		#endif
					.cDisSmoothOffset =						PARAMSET_NORMAL_MODE_1_ALGO_Coord_cDisSmoothOffset,
					.bFingerMeanSmoothing =					PARAMSET_NORMAL_MODE_1_ALGO_Coord_bFingerMeanSmoothing,
					.ucWinCertAssistance = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucWinCertAssistance, 					//0 : Off, 1 : LGD MNT 27", 2 : LGD Kiosk
					.ucTouchCountMax = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTouchCountMax, 						//LGD MNT 27" : 3, LGD Kiosk 43",55" : 30
					.ucMaxExtendFrameNum = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMaxExtendFrameNum, 					//LGD MNT 27" : 10, LGD Kiosk 43", 55" : 100
					.usFirstDrawingThd		 = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_usFirstDrawingThd,
					.ucFirstDrawingCellCnt   = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFirstDrawingCellCnt,
				},
				.CoordTracking =
				{
					.ucDynamicTrackingDistanceMode = 		PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucDynamicTrackingDistanceMode,
					.ucFastDrawingMode = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFastDrawingMode,
					.usMoveDistanceThd = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_usMoveDistanceThd,
					.usFirstMoveDistanceThd = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_usFirstMoveDistanceThd,
					.lLargeTouchOnThd = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_lLargeTouchOnThd,
					.ucLargeTouchOnDebCnt = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLargeTouchOnDebCnt,
					.lMediumTouchOnThd = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_lMediumTouchOnThd,
					.ucMediumTouchOnDebCnt = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMediumTouchOnDebCnt,
					.lSmallTouchOnThd = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_lSmallTouchOnThd,
					.ucSmallTouchOnDebCnt = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchOnDebCnt,
					.bEdgeDebCntUp = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_bEdgeDebCntUp,
					.sFirstTouchOnMaxCellVal = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchOnMaxCellVal,
					.lTouchOffThd = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_lTouchOffThd,
					.ucMultifingerFirstTouchThDownOffset =	PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMultifingerFirstTouchThDownOffset,
					.usCenterMatchDistanceThd = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usCenterMatchDistanceThd,
					.sFirstTouchEnable1Touch = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable1Touch, 				//Enable First touch
					.sFirstTouchEnable2Touch = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable2Touch,
					.sFirstTouchEnable3Touch = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable3Touch,
					.sFirstTouchEnable4Touch = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable4Touch,
					.sFirstTouchEnable5Touch = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable5Touch,
					.ucDebCntInner			 = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucDebCntInner,
					.ucDebCntEdge			 = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucDebCntEdge,
				},
				.CoordEdge =
				{
					.bExpectClipping_Finger_On = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_bExpectClipping_Finger_On,
					.cEdgeSmoothing_Finger_On = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_cEdgeSmoothing_Finger_On,
		#if (REMOVE_EDGE_EN == YES)
					.bRemoveEdge = 							PARAMSET_NORMAL_MODE_1_ALGO_Coord_bRemoveEdge,
					.usRemoveEdgeXdistThd =					PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRemoveEdgeXdistThd,
					.usRemoveEdgeYdistThd =					PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRemoveEdgeYdistThd,
		#endif
					.usPostProcessEdgeTH = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_usPostProcessEdgeTH,
					.ucPostProcessDisTH =					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucPostProcessDisTH,
					.ucPostProcessExpendDiv =				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucPostProcessExpendDiv,
					.cPostProcessEndMargin =				PARAMSET_NORMAL_MODE_1_ALGO_Coord_cPostProcessEndMargin,
					.bPostProcessInterpolationMode		=   PARAMSET_NORMAL_MODE_1_ALGO_Coord_bPostProcessInterpolationMode,
					.usOutInDrawEdgeTh = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_usOutInDrawEdgeTh,
					.ucOutInDrawDisTh = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucOutInDrawDisTh,
					.bUseNewCippingCond = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_bUseNewCippingCond,
				},
				.EdgeExpand =
				{
		#if (MULTI_EDGE_COEF_EN == YES)
					.bUseMultiEdgeCoef =					PARAMSET_NORMAL_MODE_1_ALGO_Coord_bUseMultiEdgeCoef,
					.usSmallTouchMaxDeltaThd = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_usSmallTouchMaxDeltaThd,
					.ucSmallTouchCellCntThd = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchCellCntThd,
					.ucSmallTouchHeightThd = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchHeightThd,
					.ucSmallTouchWidthThd = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchWidthThd,
		#endif
					.ucLeftEdgeExpand = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLeftEdgeExpand,
					.ucRightEdgeExpand = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRightEdgeExpand,
					.ucTopEdgeExpand = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTopEdgeExpand,
					.ucBottomEdgeExpand = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucBottomEdgeExpand,
		#if (MULTI_EDGE_COEF_EN == YES)
					.ucLeftEdgeExpand_small = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLeftEdgeExpand_small,
					.ucRightEdgeExpand_small = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRightEdgeExpand_small,
					.ucTopEdgeExpand_small = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTopEdgeExpand_small,
					.ucBottomEdgeExpand_small = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucBottomEdgeExpand_small,
					.ucLeftEdgeExpand_medium = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLeftEdgeExpand_medium,
					.ucRightEdgeExpand_medium = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRightEdgeExpand_medium,
					.ucTopEdgeExpand_medium = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTopEdgeExpand_medium,
					.ucBottomEdgeExpand_medium = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucBottomEdgeExpand_medium,
		#endif
					.sXExpandStartOffset = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_sXExpandStartOffset,
					.sYExpandStartOffset = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_sYExpandStartOffset,
					.usLabelEdgeExpandMode = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLabelEdgeExpandMode,				//0: max_d = 100, 1: max_d = ulStrength (MAX), else: max_d = usLabelEdgeExpandMode
					.usLeftEdgeExpand_Offset   = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLeftEdgeExpand_Offset,				//EdgeExpandFinger
					.usRightEdgeExpand_Offset  = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRightEdgeExpand_Offset,
					.usTopEdgeExpand_Offset    = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usTopEdgeExpand_Offset,
					.usBottomEdgeExpand_Offset = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBottomEdgeExpand_Offset,
					.usLeftEdgeExpand_Scale    = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLeftEdgeExpand_Scale,
					.usRightEdgeExpand_Scale   = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRightEdgeExpand_Scale,
					.usTopEdgeExpand_Scale     = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usTopEdgeExpand_Scale,
					.usBottomEdgeExpand_Scale  = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBottomEdgeExpand_Scale,
		#if (BIG_FINGER_EDGE_EXPAND_ALGO_EN == YES)
					.usLeftEdgeExpand_MaxD		=			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLeftEdgeExpand_MaxD,				//For Win10Cer 16Phi & 7Phi Edge Test
					.usRightEdgeExpand_MaxD     =			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRightEdgeExpand_MaxD,
					.usTopEdgeExpand_MaxD       =			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usTopEdgeExpand_MaxD,
					.usBottomEdgeExpand_MaxD    =			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBottomEdgeExpand_MaxD,
					.usBigFingerEdgeExpandParam1	=		PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam1,
					.usBigFingerEdgeExpandParam2	=		PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam2,
					.usBigFingerEdgeExpandParam3	=		PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam3,
		#endif
		#if (BIG_FINGER_EDGE_ACC_TEST_ALGO_EN == YES)
					.ucEdgeReportDelayCnt			=		PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucEdgeReportDelayCnt,//10,
					.usBigFingerEdgeTest_MoveEventTHD_X	=	PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTest_MoveEventTHD_X,
					.usBigFingerEdgeTest_MoveEventTHD_Y	=	PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTest_MoveEventTHD_Y,
					.usBigFingerEdgeTestClippingTop		=	PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingTop,
					.usBigFingerEdgeTestClippingBottom	=	PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingBottom,
					.usBigFingerEdgeTestClippingLeft	=	PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingLeft,
					.usBigFingerEdgeTestClippingRight	=	PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingRight,
					.bFingerCornerTestClippingOn		=	PARAMSET_NORMAL_MODE_1_ALGO_Coord_bFingerCornerTestClippingOn,
		#endif
				},
				.PenCoord =
				{
					.ucTipRangeExtend_On = 					PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucTipRangeExtend_On,
					.bExpectClipping_Pen_On = 				PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bExpectClipping_Pen_On,
					.ucCompenCoefA = 						PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucCompenCoefA,
					.ucCompenCoefB = 						PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucCompenCoefB,
					.ucHoverCompenCoefA = 					PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucHoverCompenCoefA,
					.ucHoverCompenCoefB	=					PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucHoverCompenCoefB,
					.bCompenEdgeOn =						PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bCompenEdgeOn,
					.ucPenPostProcessEdgeTH = 				PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPenPostProcessEdgeTH,
					.ucPenPostProcessDisTH = 				PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPenPostProcessDisTH,
					.ucPenPostProcessExpendDiv = 			PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPenPostProcessExpendDiv,
					.cPenPostProcessEndMargin			=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_cPenPostProcessEndMargin,
					.cHoverSmoothOffset	= 					PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_cHoverSmoothOffset,
					.bFullFingerOn = 						PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bFullFingerOn,
					.sPenGlobalCoordiXResolutionOffset = 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sPenGlobalCoordiXResolutionOffset,
					.sPenGlobalCoordiYResolutionOffset = 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sPenGlobalCoordiYResolutionOffset,
					.sPenGlobalCoordiOffsetX = 			 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sPenGlobalCoordiOffsetX,
					.sPenGlobalCoordiOffsetY = 			 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sPenGlobalCoordiOffsetY,
		#if (PenGlobalCoordiY_2Region_Set == YES)
					.sPenGlobalCoordiY_2Region_boundary	= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sPenGlobalCoordiY_2Region_boundary,
					.sPenGlobalCoordiYResolutionOffset1 =	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sPenGlobalCoordiYResolutionOffset1,
					.sPenGlobalCoordiOffsetY1 =				PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sPenGlobalCoordiOffsetY1,					
		#endif
		#if (PEN_EdgeExpandStartOffset_On == YES)
					.sXExpandStartOffset				=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sXExpandStartOffset,
					.sYExpandStartOffset				=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sYExpandStartOffset,
		#endif
					.ucLeftEdgeExpand_local = 				PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucLeftEdgeExpand_local,
					.ucRightEdgeExpand_local = 				PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucRightEdgeExpand_local,
					.ucTopEdgeExpand_local = 				PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucTopEdgeExpand_local,
					.ucBottomEdgeExpand_local = 			PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucBottomEdgeExpand_local,
		#if (EdgeExpandLocalCornerOffsetAdd == YES)	
					.usEdgeExpand_local_CornerSizeOffset=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usEdgeExpand_local_CornerSizeOffset,
					.cLeftEdgeExpand_local_CornerOffset=   PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_cLeftEdgeExpand_local_CornerOffset,
					.cRightEdgeExpand_local_CornerOffset=  PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_cRightEdgeExpand_local_CornerOffset,
					.cTopEdgeExpand_local_CornerOffset	=   PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_cTopEdgeExpand_local_CornerOffset,
					.cBottomEdgeExpand_local_CornerOffset= PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_cBottomEdgeExpand_local_CornerOffset,
		#endif
					.uclatency_up_dis_condition			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_uclatency_up_dis_condition,  // off : 0
					.uclatency_up_cnt_condition			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_uclatency_up_cnt_condition,  // range : 0 ~ 255
					.clatency_up_dis_offset				=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_clatency_up_dis_offset,
					.ucideal_inter_dis					= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ideal_inter_dis,	// range : 0 ~ 255
					.ucideal_inter_mv					= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ideal_inter_mv,	// range : 0 ~ 255
		#if (IdealInterOnlyCorner == YES)
					.us_ideal_inter_only_corner			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_us_ideal_inter_only_corner,
		#endif	
					.uc_connect_count					= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_uc_connect_count,
					.ucMarkBoundaryNum					= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucMarkBoundaryNum,
		#if (Pen_EdgeMarkBoundary == YES)
					.ucEdgeMarkBoundaryNum				=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucEdgeMarkBoundaryNum,
					.ucEdgeMarkBoundaryCell				=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucEdgeMarkBoundaryCell,
					.ucEdgeMarkBoundaryOff				=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucEdgeMarkBoundaryOff,
		#endif
					.ucPenEdgeDebCnt                    =   PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPenEdgeDebCnt,
					.usLongDisPointExceptionTH			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usLongDisPointExceptionTH,
					.usPannelOutSideHoverExceptionTH	=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usPannelOutSideHoverExceptionTH,			//PannelOutSideHoverException On & Thd , 210304 HanCH
					.usPannelOutSideContactExceptionTH	=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usPannelOutSideContactExceptionTH,			//PannelOutSideContactException On & Thd , 210304 HanCH
					.ucPannelOutSideHoverExceptionEdgeDis	=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPannelOutSideHoverExceptionEdgeDis,	//Edge Distance for PannelOutSideHoverException , 210304 HanCH
					.ucPannelOutSideContactExceptionEdgeDis	=   PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPannelOutSideContactExceptionEdgeDis,//Edge Distance for PannelOutSideContactException , 210304 HanCH
					.ucPannelOutSideContactExceptionPreDis	=   PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPannelOutSideContactExceptionPreDis,	//Past & Current Pos Distance for PannelOutSideContactException	, 210304 HanCH
		#if (OUT_IN_DRAWING == YES)
					.usOutInBoundTh							= PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usOutInBoundTh,
					.ucOutInDisTh							= PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucOutInDisTh,
		#endif
		#if (HIGH_HOVER_JITTER_REDUCE == YES)
					.sHighHoverJitterReduceDisScale			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sHighHoverJitterReduceDisScale,
					.ucHighHoverJitterReduceSmoothOffset	= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucHighHoverJitterReduceSmoothOffset,
		#endif
		#if (WACOM_HOVER_TEST_DELTA_CHANGE == YES)
					.ucChangeSubTh							=  PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucChangeSubTh,
		#endif
					.bUseNewCippingCond_Pen					= PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bUseNewCippingCond_Pen,
		#if (PEN_REMOVE_EDGE_EN == YES)
					.bRemoveEdge							= PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bRemoveEdge,
					.usRemoveEdgeXdistThd					= PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usRemoveEdgeXdistThd,
					.usRemoveEdgeYdistThd					= PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usRemoveEdgeYdistThd,
					.bUsetRealPastSentPos1					= PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bUsetRealPastSentPos1,
					.usEndCoordMargin						= PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usEndCoordMargin,
		#endif
					
				},
				.PenTilt =
				{
					.bTiltCalOnlyContact				=  	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltCalOnlyContact,
					.cHoverOverShiftRingOffset			=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cHoverOverShiftRingOffset,
		#if (HoverDeltaMul_EN == YES)
					.ucHoverDeltaMul					=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucHoverDeltaMul,
		#endif
					.bRingRangeExtend_On 				= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bRingRangeExtend_On,
		#if (RangeExtend_v2_En == YES)
					.usTiltSubMaxDelta					= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltSubMaxDelta,
					.usTiltDivMin						= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDivMin,
					.usTiltDivMax						= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDivMax,
		#endif
					.ucRingCompenCoefA 					=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingCompenCoefA,
					.ucRingCompenCoefB 					=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingCompenCoefB,
		#if (RingCoordSmooth_En == YES)
					.ucRingCoordSmoothCoef				= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingCoordSmoothCoef,
		#endif
					.bTiltCalUsingTipOrg				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltCalUsingTipOrg,
					.ucCoordiShiftX_WithTilt  			=   PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftX_WithTilt,		// 0 : Shift Off
					.ucCoordiShiftY_WithTilt  			=   PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftY_WithTilt,
					.ucCoordiShiftEdgeOn				= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftEdgeOn,  	// 0 : Edge Off , 1 : Center Same Coef , 2 : Coef Up
					.ucCoordiShiftWithTilt_RingTH		=   PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftWithTilt_RingTH,
					.ucCoordiShiftWithTiltCompenTH		= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftWithTiltCompenTH,
		#if (CoordiShiftWithTiltCompenTH_EdgeOn == YES)
					.usCoordiShiftWithTiltCompenTH_Edge	=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usCoordiShiftWithTiltCompenTH_Edge,
		#endif
					.ucTiltL							= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTiltL,
		#if (TiltAdjustEn == YES)
					.ucTiltAdjustEn						=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTiltAdjustEn,
		#endif
		#if (TiltChangeLimitFilter == YES)
					.usTiltChangeLimitFilter			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltChangeLimitFilter,
		#endif
					.ucTiltSmoothingFilterCoef			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTiltSmoothingFilterCoef, //Max : 32
					.ucHalfCoefSmoothFrm				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucHalfCoefSmoothFrm,
					.ucHalfCoef							= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucHalfCoef,
		#if (HighDeltaTiltSmoothCoefChange == YES)
					.ucHighDelta_TiltSmooth_change_Th	= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucHighDelta_TiltSmooth_change_Th,
					.cHighDelta_TiltSmooth_change_offset=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cHighDelta_TiltSmooth_change_offset,
		#endif
		#if	(TILT_AREA_FILTER == YES)
					.usTilt_Change_TH_Reverse			=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTilt_Change_TH_Reverse,
					.usTilt_Change_TH_Right				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTilt_Change_TH_Right,
		#endif
					.bRingCoordiReport					=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bRingCoordiReport,
					.ucRingMarkBoundaryNum				= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingMarkBoundaryNum,				
		#if (TiltBasedRingDelta == YES)
					.bTiltBasedRingDelta				= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltBasedRingDelta,
		#endif
		#if (TiltDirecLimitFilter == YES)
					.bTiltDirecLimitFilter				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltDirecLimitFilter,
		#endif
		#if (TiltDeltaLimit_EN == YES)
					.ucTiltDeltaLimitFilter				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTiltDeltaLimitFilter,
					.usTiltDeltaLimit_10_TH				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_10_TH,
			#if (TiltDeltaLimit_ADD == YES)
					.usTiltDeltaLimit_40_TH				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_40_TH,
					.usTiltDeltaLimit_50_TH				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_50_TH,
			#endif
					.usTiltDeltaLimit_55_TH				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_55_TH,
					.usTiltDeltaLimit_60_TH				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_60_TH,
					.usTiltDeltaLimit_65_TH				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_65_TH,
		#endif
		#if (TiltMedianFilter == YES)
					.bTiltMedianFilter					=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltMedianFilter,
		#endif
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
					.bRingBaseTracking					=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bRingBaseTracking,
		#endif
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
					.bTiltRowIndexChange				= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltRowIndexChange,
		#endif
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)	
					.ucRingDirecPosCoef					=   PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingDirecPosCoef,
					.ucRingTipDeltaSumCoef				= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingTipDeltaSumCoef,
					.ucRingTipDeltaSumTH				= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingTipDeltaSumTH,
					.b2MUX_SUM_RingMode					=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_b2MUX_SUM_RingMode,
					.ucTipDirecShiftBasedRingDelta		=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTipDirecShiftBasedRingDelta,
		#endif
		#if (TiltArcSinLookUp_Num > 3)
					.bArcSinLookUp_1					=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bArcSinLookUp_1,
		#endif
		#if (UseLastContact3x3 == YES)
					.usReleaseLastContact3x3Frm 		=   PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usReleaseLastContact3x3Frm,
					.usUseLastContact3x3Th				=   PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usUseLastContact3x3Th,
		#endif
		#if (CORNER_CoordiShift_WithTilt_ADD == YES)
					.cCoordiShiftX_WithTilt_Corner_LT  = PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_LT,
					.cCoordiShiftY_WithTilt_Corner_LT  = PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_LT,
					.cCoordiShiftX_WithTilt_Corner_RT  = PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_RT,
					.cCoordiShiftY_WithTilt_Corner_RT  = PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_RT,
					.cCoordiShiftX_WithTilt_Corner_LB  = PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_LB,
					.cCoordiShiftY_WithTilt_Corner_LB  = PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_LB,
					.cCoordiShiftX_WithTilt_Corner_RB  = PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_RB,
					.cCoordiShiftY_WithTilt_Corner_RB  = PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_RB,
					.sCoordiShiftWithTiltEdgeAreaOffset	= PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_sCoordiShiftWithTiltEdgeAreaOffset,
		#endif
				},
				.PenData =
				{
					.ucAdaptive_contact_th = 				PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAdaptive_contact_th,
					.ucPenDataLocalTHD = 					PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataLocalTHD,
					.ucPenDataHoverTHD = 					PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataHoverTHD,
					.sPenDataHoverButtonTHD				=	PARAMSET_NORMAL_MODE_1_ALGO_PenData_sPenDataHoverButtonTHD,					//Button & ID Data 3x3 sum ON & Button Thd , 210304 HanCH
					.usPenDataHighHoverButtonRejectTHD = 	PARAMSET_NORMAL_MODE_1_ALGO_PenData_usPenDataHighHoverButtonRejectTHD,
					.ucPenDataHighHoverButton1ReliableCnt = PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataHighHoverButton1ReliableCnt,	//Button1 Continue Count Check On & Count in HighHoverButtonRejectTHD , 210304 HanCH
					.ucPenDataHighHoverButton2ReliableCnt = PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataHighHoverButton2ReliableCnt,	//Button2 Continue Count Check On & Count in HighHoverButtonRejectTHD , 210304 HanCH
					.ucPenDataHighHoverButtonAdopThOffset =	PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataHighHoverButtonAdopThOffset,	//Button Adoptive Th On & Offset in HighHoverButtonRejectTHD , 210304 HanCH
					.ucPenDataHighHoverButtonIIRcoef	  = PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataHighHoverButtonIIRcoef,		//Button & ID Data IIR On & Coef , 210304 HanCH
					.ucForcePenContact_NUM = 				PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucForcePenContact_NUM,
					.ucAbnormalContactRemoveDeltaTH1 = 		PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemoveDeltaTH1,
					.ucAbnormalContactRemoveDeltaTH2 = 	    PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemoveDeltaTH2,
					.ucAbnormalContactRemovePressureTH1 =   PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemovePressureTH1,
					.ucAbnormalContactRemovePressureTH2 =   PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemovePressureTH2,
					.ucSEN_CONT_CNT						=	PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucSEN_CONT_CNT,
					.ucKeepProtocolNum =					PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucKeepProtocolNum,
#if USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL
					.bOrgPressureInterpolation			=	PARAMSET_NORMAL_MODE_1_ALGO_PenData_bOrgPressureInterpolation,
					.ulPressureLevelIIR_Prev_Coef_THD 	= 	PARAMSET_NORMAL_MODE_1_ALGO_PenData_ulPressureLevelIIRPrevCoefTHD,//8,//4, // 1~15 Set
					.ulPressureChangeRatioTHD			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenData_ulPressureChangeRatioTHD,//55,//60, // 0~100 Max 100
					.bUsedBrushFinishTip				= 	PARAMSET_NORMAL_MODE_1_ALGO_PenData_bUsedBrushFinishTip,//1,
					.bBrushFinishPressure1Report		=	PARAMSET_NORMAL_MODE_1_ALGO_PenData_bBrushFinishPressure1Report,
#endif /* USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL */
				},
				.EdgePenSetVal =
				{
					.top_th = 								PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_th,//0,
					.top_mul = 								PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_mul,
					.top_SR = 								PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_SR,
					.bottom_th = 							PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_th,//0,
					.bottom_mul = 							PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_mul,
					.bottom_SR = 							PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_SR,
					.left_th = 								PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_th,//0,
					.left_mul = 							PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_mul,
					.left_SR = 								PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_SR,
					.right_th = 							PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_th,//0,
					.right_mul = 							PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_mul,
					.right_SR = 							PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_SR,
					.top_hover_th = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_hover_th,//580,
					.top_hover_mul = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_hover_mul,//19,
					.top_hover_SR = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_hover_SR,//4,
					.bottom_hover_th = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_hover_th,//580,
					.bottom_hover_mul = 					PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_hover_mul,//24,//19,
					.bottom_hover_SR = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_hover_SR,//4,
					.left_hover_th =						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_hover_th,//620,
					.left_hover_mul =						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_hover_mul,//19,
					.left_hover_SR = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_hover_SR,//4,
					.right_hover_th = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_hover_th,//620,
					.right_hover_mul = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_hover_mul,//19,
					.right_hover_SR = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_hover_SR,//4,
					.top_ring_th = 							PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_ring_th,
					.top_ring_mul = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_ring_mul,
					.top_ring_SR = 							PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_ring_SR,
					.bottom_ring_th = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_ring_th,//600,
					.bottom_ring_mul = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_ring_mul,
					.bottom_ring_SR = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_ring_SR,
					.left_ring_th = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_ring_th,//600,
					.left_ring_mul = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_ring_mul,
					.left_ring_SR = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_ring_SR,
					.right_ring_th = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_ring_th,//600,
					.right_ring_mul = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_ring_mul,
					.right_ring_SR = 						PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_ring_SR,
					.chover_mul_button1_offset			=	PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_chover_mul_button1_offset,
		#if (Ring_EdgeEx_mul_HoverOffset == YES)
					.left_ring_mul_HoverOffset			= 	PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_ring_mul_HoverOffset,
					.right_ring_mul_HoverOffset			= 	PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_ring_mul_HoverOffset,
					.top_ring_mul_HoverOffset			= 	PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_ring_mul_HoverOffset,	
					.bottom_ring_mul_HoverOffset		= 	PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_ring_mul_HoverOffset,
		#endif
				},
				.PenDisBaseSmoothSetVal =
				{
					.c_edge_smooth_offset_hover			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_c_edge_smooth_offset_hover,				// range : -127 ~ 126, off : 127
					.c_edge_smooth_offset_contact  		= 	PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_c_edge_smooth_offset_contact,  			// range : -127 ~ 126, off : 127
					.uc_global_smooth_dis_condition_contact=PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_dis_condition_contact,	// range : 1 ~ 255, off : 0
					.c_global_smooth_offset_contact  	= 	PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_c_global_smooth_offset_contact,			// range : -127 ~ 127,
					.us_corner_smooth_delta_condition_hover=PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_us_corner_smooth_delta_condition_hover,  // range : 1 ~ 65535, off : 0
					.c_corner_smooth_offset_hover		= 	PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_c_corner_smooth_offset_hover,			// range : -127 ~ 127
					.uc_edge_smooth_dis_condition_contact= 	PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_uc_edge_smooth_dis_condition_contact,	// range : 1 ~ 255
					.uc_global_smooth_delta_condition_hover=PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_delta_condition_hover,	// range : 1 ~ 255, off : 0
					.uc_global_smooth_dis_condition_hover= 	PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_dis_condition_hover,	// range : 0 ~ 255
					.c_global_smooth_offset_hover		= 	PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_c_global_smooth_offset_hover,			// range : -127 ~ 127
					.usEdge_Range						=	PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_usEdge_Range,
#if (CornerSmoothContact == YES)
					.usCornerSmoothContact_CornerRange  =	PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_usCornerSmoothContact_CornerRange,
					.ucCornerSmoothContact_DisCondition =   PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_ucCornerSmoothContact_DisCondition,
					.cCornerSmoothContact_SmoothOffset  =	PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_cCornerSmoothContact_SmoothOffset,
#endif
				},
				.PenParaEdgeSetVal =
				{
					.th0 							= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_th0,			// mul1 off 255 set
					.top_mul0 						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_mul0,		// mul0 off 127 set
					.top_SR0 						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_SR0, 		// mul0 off 0 	set
					.top_mul1						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_mul1,
					.top_SR1						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_SR1,
					.bottom_mul0					= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_mul0,
					.bottom_SR0						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_SR0,
					.bottom_mul1					= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_mul1,
					.bottom_SR1						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_SR1,
					.left_mul0						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_mul0,
					.left_SR0						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_SR0,
					.left_mul1						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_mul1,
					.left_SR1						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_SR1,
					.right_mul0						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_mul0,
					.right_SR0						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_SR0,
					.right_mul1						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_mul1,
					.right_SR1						= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_SR1,
					.top_max_sum 					= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_max_sum,
					.bottom_max_sum 				= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_max_sum,
					.left_max_sum 					= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_max_sum,
					.right_max_sum 					= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_max_sum,
					.top_max_sum_corner 			= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_max_sum_corner,
					.bottom_max_sum_corner			= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_max_sum_corner,
					.left_max_sum_corner 			= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_max_sum_corner,
					.right_max_sum_corner 			= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_max_sum_corner,
					.top_max_sum_hover 				= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_max_sum_hover,
					.bottom_max_sum_hover 			= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_max_sum_hover,
					.left_max_sum_hover 			= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_max_sum_hover,
					.right_max_sum_hover 			= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_max_sum_hover,
					.max_sum_hover_div 				= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_max_sum_hover_div,
		#if (PEN_CORNER_EXPEND_ADD == YES)		//For use, DeltaBaseNewEdgeCompen_SW must be set	
					.top_max_sum_corner1 			= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_max_sum_corner1,
					.bottom_max_sum_corner1			= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_max_sum_corner1,
					.left_max_sum_corner1 			= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_max_sum_corner1,
					.right_max_sum_corner1 			= 		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_max_sum_corner1,
					.max_sum_corner_TiltY_LT		=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltY_LT,
					.max_sum_corner_TiltY_RT		=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltY_RT,
					.max_sum_corner_TiltY_LB		=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltY_LB,
					.max_sum_corner_TiltY_RB		=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltY_RB,
					.max_sum_corner_TiltX_LT		=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltX_LT,
					.max_sum_corner_TiltX_RT		=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltX_RT,
					.max_sum_corner_TiltX_LB		=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltX_LB,
					.max_sum_corner_TiltX_RB		=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_max_sum_corner_TiltX_RB,	
		#endif
		#if (PEN_CORNER_EXPEND_ADD_1 == YES)	//For use, DeltaBaseNewEdgeCompen_SW must be set	
					.top_mul0_LeftCornerOffset		=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_mul0_LeftCornerOffset,
					.top_max_sum_LeftCornerOffset	=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_max_sum_LeftCornerOffset,
					.top_mul0_RightCornerOffset		=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_mul0_RightCornerOffset,
					.top_max_sum_RightCornerOffset	=		PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_max_sum_RightCornerOffset,
					.bottom_mul0_LeftCornerOffset		=	PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_mul0_LeftCornerOffset,
					.bottom_max_sum_LeftCornerOffset	=	PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_max_sum_LeftCornerOffset,	
					.bottom_mul0_RightCornerOffset		=	PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_mul0_RightCornerOffset,
					.bottom_max_sum_RightCornerOffset	=	PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_max_sum_RightCornerOffset,						
		#endif
		#if (PEN_Edge_UsePerMaxSum == YES)
					.ucUsePerMaxSum						=   PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_ucUsePerMaxSum,
					.ulExtStrengthInit					=	PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_ulExtStrengthInit,
		#endif
				},
				.Noise =
				{
					.ucNoiseDetectionMode = 				PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucNoiseDetectionMode,		//0: OFF, 1 : previous 2 : LGD MNT 27"
					.ucDiscardFrameNum = 					PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucDiscardFrameNum,
					.ucCellCntThd = 						PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucCellCntThd,
					.ucHoppingThd = 						PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucHoppingThd,
					.ucNoiseThd = 							PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucNoiseThd,
					.usRawDataThd = 						PARAMSET_NORMAL_MODE_1_ALGO_Noise_usRawDataThd,
					.sDeltaDataThd = 						PARAMSET_NORMAL_MODE_1_ALGO_Noise_sDeltaDataThd,
					.ucTouchOffCntThd = 					PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucTouchOffCntThd,
					.bPenNoiseReductionOff				=   PARAMSET_NORMAL_MODE_1_ALGO_Noise_bPenNoiseReductionOff,
					.ucPenFingerSameLineNoiseSize = 		PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucPenFingerSameLineNoiseSize,
					.ucHoverNoiseRejectTH			=		PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucHoverNoiseRejectTH,
					.ucHoverNoiseRejectFrm		=			PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucHoverNoiseRejectFrm,
					.ucSearchNoiseRejectTH			=		PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucSearchNoiseRejectTH,
					.ucSearchNoiseRejectFrm			=		PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucSearchNoiseRejectFrm,
					.cAdaptorNoiseTH = 						PARAMSET_NORMAL_MODE_1_ALGO_Noise_cAdaptorNoiseTH,
					.ucAdaptorNoiseContiNum = 				PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucAdaptorNoiseContiNum,
					.cAdaptorNoiseTH_SearchHover = 			PARAMSET_NORMAL_MODE_1_ALGO_Noise_cAdaptorNoiseTH_SearchHover,
					.ucAdaptorNoiseContiNum_SearchHover = 	PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucAdaptorNoiseContiNum_SearchHover,
					.bPenPosSymbolRepeatCheck		=       PARAMSET_NORMAL_MODE_1_ALGO_Noise_bPenPosSymbolRepeatCheck,
					.ucCPITestOn = 							PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucCPITestOn,
					.ucErrorFrameProcess = 					PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucErrorFrameProcess,
					.ucHoppingMoveDistanceThd = 			PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucHoppingMoveDistanceThd,
					.ucNoiseDetectMaxType = 				PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucNoiseDetectMaxType,
					.bInitAddHoppingThd = 					PARAMSET_NORMAL_MODE_1_ALGO_Noise_bInitAddHoppingThd,
					.bHoppingConnectPenContact = 			PARAMSET_NORMAL_MODE_1_ALGO_Noise_bHoppingConnectPenContact,
					.ucNoiseStartThd = 						PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucNoiseStartThd,
					.ucNoiseStartCntThd = 					PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucNoiseStartCntThd,
				},
				.Palm =
				{
					.ucPalmDetectionOn = 					PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmDetectionOn,		//0 : off, 1 : Version 1, 2 : Version 2, 3 : 1, 2 Adpative
					.usPalmLevel = 							PARAMSET_NORMAL_MODE_1_ALGO_Palm_usPalmLevel,//20,//12,
#if (PalmFirstDetectionShift == YES)
					.ucPalmLevelShift = 				PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmLevelShift,
#endif
					.ucPalm_PALM_CONNECT_DIST = 			PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_PALM_CONNECT_DIST,
					.ucPalm_PALM_REGION_UPDATE_PERIOD =		PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_PALM_REGION_UPDATE_PERIOD,
					.ucPalm_TOUCHDOWNFRAMEMAX = 			PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_TOUCHDOWNFRAMEMAX,
					.ucPalm_TOUCHDOWNSLOPETHRESHOLD = 		PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_TOUCHDOWNSLOPETHRESHOLD,
					.ucPalm_IGNOREFRAMENUM = 				PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_IGNOREFRAMENUM,
					.ucPalm_KEEPPALMREGIONFRAME = 			PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_KEEPPALMREGIONFRAME,
#if (PalmDrawingOn_En == YES)
					.ucPalmDrawingOn = 						PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmDrawingOn,
#endif
					.bPalm_WholeTouchRemove = 				PARAMSET_NORMAL_MODE_1_ALGO_Palm_bPalm_WholeTouchRemove,
#if (PENnPalm_PalmAreaMaintain_EN == YES)
					.bPenPalmDetection =					PARAMSET_NORMAL_MODE_1_ALGO_Palm_bPalm_bPenPalmDetection,
					.ucPenPalm_PALM_CONNECT_DIST = 			PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPenPalm_PALM_CONNECT_DIST,
					.ucPenPalm_KEEPPALMREGIONFRAME = 		PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPenPalm_KEEPPALMREGIONFRAME,
					.ucPen_KEEPFRAME = 						PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPen_KEEPFRAME,
					.ucPalmRelaseFrame =					PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmRelaseFrame,
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */					
#if (PalmCandidateTouchCut_EN == YES)
					.usPalmCandiStdTh 					=	PARAMSET_NORMAL_MODE_1_ALGO_Palm_usPalmCandiStdTh,
					.ucPalmCandiShapeMatchingTh			=	PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmCandiShapeMatchingTh,	
					.ucPalmCandiDeltaTh					=	PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmCandiDeltaTh,
#endif
				},
			},
			.tModule =
			{
				.ucOvrShift = 								PARAMSET_NORMAL_MODE_1_ALGO_ucOvrShift,//3,
				.ucIdleOvrShift = 							PARAMSET_NORMAL_MODE_1_ALGO_ucIdleOvrShift,//1,
				.ucLocalOvrShift = 							PARAMSET_NORMAL_MODE_1_ALGO_ucLocalOvrShift,//3,
				.ucLocalIdleOvrShift = 						PARAMSET_NORMAL_MODE_1_ALGO_ucLocalIdleOvrShift,//2,
				.ucLocalOvrShift_Ring = 					PARAMSET_NORMAL_MODE_1_ALGO_ucLocalOvrShift_Ring,//2,
			},	
	#if IS_MULTI_PROTOCOL_OPERATION
		},	
	#endif /* IS_MULTI_PROTOCOL_OPERATION */
#endif /* IS_WGPPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION */
	}
};
