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

			.ucPenLocalModeChangeFrameCntTHD = 4,
			.ucPenFullModeChangeFrameCntTHD = 2,
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
					[ACTIVEPEN_TYPE_LOCAL_MS] =
					{
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
					},
					[ACTIVEPEN_TYPE_LOCAL_WACOM] =
					{
						.MSPI_LHBCountNum = PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_LHBCount,
						.MSPI_BUF_Panel_ColNum = PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_Buf_Panel_ColNum,
						.ePenPartialIndex =
						{
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_1LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_2LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_3LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_4LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_5LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_6LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_7LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_8LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_9LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_10LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_11LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_12LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_13LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_14LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_15LHB_Pen
							PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_16LHB_Pen
						},
						.tMspiFingerMuxScanOrder =
						{
							.ucLocalFingerMUXScanOrderIDX =
							{
								[0] = /* Finger 1st LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_1stLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_1stLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_1stLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_1stLHB_4Mux,
								},
								[1] = /* Finger 2nd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_2ndLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_2ndLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_2ndLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_2ndLHB_4Mux,
								},
								[2] = /* Finger 3rd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_3rdLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_3rdLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_3rdLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_3rdLHB_4Mux,
								},
								[3] = /* Finger 4th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_4thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_4thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_4thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_4thLHB_4Mux,
								},
								[4] = /* Finger 5th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_5thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_5thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_5thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_5thLHB_4Mux,
								},
								[5] = /* Finger 6th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_6thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_6thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_6thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_6thLHB_4Mux,
								},
							},
							.ucFullFingerMUXScanOrderIDX =
							{
								[0] = /* Finger 1st LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_1stLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_1stLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_1stLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_1stLHB_4Mux,
								},
								[1] = /* Finger 2nd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_2ndLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_2ndLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_2ndLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_2ndLHB_4Mux,
								},
								[2] = /* Finger 3rd LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_3rdLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_3rdLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_3rdLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_3rdLHB_4Mux,
								},
								[3] = /* Finger 4th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_4thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_4thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_4thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_4thLHB_4Mux,
								},
								[4] = /* Finger 5th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_5thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_5thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_5thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_5thLHB_4Mux,
								},
								[5] = /* Finger 6th LHB */
								{
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_6thLHB_1Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_6thLHB_2Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_6thLHB_3Mux,
									PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_6thLHB_4Mux,
								},
							},
						},
					},
					[ACTIVEPEN_TYPE_LOCAL_WGP] =
					{
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
					},
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
					[ACTIVEPEN_TYPE_LOCAL_MS] =
					{
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
							.tBit.mgap_prd_f = 0,
							.tBit.mgap_prd_p_s = 0,
							.tBit.mgap_prd_p_d = 0,
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
							.tBit.pwm_sric_f = 0,
							.tBit.pwm_tpic_f = 0,
							.tBit.pwm_mux_f = 0,
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
							.tBit.freq_beacon = PWM_Half_KHz(500),
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
					},
					[ACTIVEPEN_TYPE_LOCAL_WACOM] =
					{
						.tCP_PWMGEN_CR0 =
						{
							.tBit.pwm_gen_enable = DISABLE,
							.tBit.kiosk_mode = 0,
							.tBit.tfd_mode = PWM_TSD_MODE,
							.tBit.continuos_en = PWM_CONTINUOS_MODE,
							.tBit.frame_rate = PWM_FRAME_RATE_DIV_1,
							.tBit.chip_length0 = 19,
							.tBit.chip_length1 = 19,
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
							.tBit.fstart_en = PARAMSET_PWMDRV_AIT_PWMGEN_CR1_fstart_en,
							.tBit.skip_num = PARAMSET_PWMDRV_AIT_PWMGEN_CR1_skip_num,
							.tBit.beacon_data_num = PARAMSET_PWMDRV_AIT_PWMGEN_CR1_beacon_data_num,
							.tBit.sric_dummy_num = PARAMSET_PWMDRV_AIT_PWMGEN_CR1_sric_dummy_num,
							.tBit.tpic_dummy_num = PARAMSET_PWMDRV_AIT_PWMGEN_CR1_tpic_dummy_num,
							.tBit.dummy_gap_en = PARAMSET_PWMDRV_AIT_PWMGEN_CR1_dummy_gap_en,
							.tBit.pgap_en = PARAMSET_PWMDRV_AIT_PWMGEN_CR1_pgap_en,
							.tBit.pen_s_pwmnum = PARAMSET_PWMDRV_AIT_PWMGEN_CR1_pen_s_pwmnum,
						},
						.tCP_PWMGEN_CR2 =
						{
							.tBit.pen_d_pwmnum = PARAMSET_PWMDRV_AIT_PWMGEN_CR2_pen_d_pwmnum,
							.tBit.finger_pwmnum = PARAMSET_PWMDRV_AIT_PWMGEN_CR2_finger_pwmnum,
							.tBit.nm_num = PARAMSET_PWMDRV_AIT_PWMGEN_CR2_nm_num,
							.tBit.total_mux_num = PARAMSET_PWMDRV_AIT_PWMGEN_CR2_total_mux_num,
						},
						.tCP_SET_TX_CR =
						{
							.tBit.set_tx_en = 0,
							.tBit.set_tx_num = 1,
						},
						.tCP_TSYNC_CR =
						{
							.tBit.tsync_num = (LHB_NUM - 1),
							.tBit.tsync_end_loc = 0,
							.tBit.tsync_dglitch_len = 0,
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
						},
						.tCP_TSYNC_D2_CR =
						{
							.tBit.beacon_en = ENABLE,//ISABLE,
							.tBit.pen_s_en = ENABLE,
							.tBit.pen_d_en = ENABLE,
							.tBit.finger_en = ENABLE,
							.tBit.nm_en = DISABLE,
							.tBit.none_en = DISABLE,
							.tBit.st_pnt = 1,//3,
							.tBit.end_pnt = 1,//596,
							.tBit.kiosk_sgap_end = 0,
							.tBit.kiosk_pwm_end = 0,
							.tBit.kiosk_tch_time_end = 0,
						},
						.tCP_DLY_CNT1 =
						{
							.tBit.sgap_prd = PARAMSET_PWMDRV_AIT_DLY_CNT1_sgap_prd,
							.tBit.ping_prd = PARAMSET_PWMDRV_AIT_DLY_CNT1_ping_prd,
						},
						.tCP_DLY_CNT2 =
						{
							.tBit.mgap_prd_f = 0,
							.tBit.mgap_prd_p_s = 122,
							.tBit.mgap_prd_p_d = 0,
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
							.tBit.pen_s_en = ENABLE,
							.tBit.pen_d_en = ENABLE,
							.tBit.finger_en = DISABLE,
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
							.tBit.pwm_sric_f = 0,//PWM_nsec(1950),
							.tBit.pwm_tpic_f = 0,//PWM_nsec(1950),
							.tBit.pwm_mux_f = 0,//PWM_nsec(1950),
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
								.tBit.beacon_cfg1 = 0x10,
								.tBit.beacon_cfg2 = 0x01,
								.tBit.beacon_cfg3 = 0x00,
								.tBit.beacon_cfg4 = 0x01,
								.tBit.beacon_cfg5 = 0x05,
							},
							[PWM_LOCAL_PEN_MODE] =
							{
								.tBit.beacon_cfg0 = 0x10,
								.tBit.beacon_cfg1 = 0x10,
								.tBit.beacon_cfg2 = 0x01,
								.tBit.beacon_cfg3 = 0x00,
							#ifdef TILT_ON
								.tBit.beacon_cfg4 = 0x07,
								.tBit.beacon_cfg5 = 0x0f,
							#else
								.tBit.beacon_cfg4 = 0x03,
								.tBit.beacon_cfg5 = 0x03,
							#endif
							},
						},
						.tCP_DSSS_INFO2 =
						{
							[PWM_FULL_FINGER_MODE] =
							{
								.tBit.beacon_cfg6 = 0x00,
								.tBit.beacon_cfg7 = 0x00,
								.tBit.beacon_cfg8 = 0x00,
								.tBit.beacon_cfg9 = 0x00,
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
							},
							[PWM_LOCAL_PEN_MODE] =
							{
								.tBit.beacon_cfg6 = 0x00,
								.tBit.beacon_cfg7 = 0x00,
								.tBit.beacon_cfg8 = 0x00,
								.tBit.beacon_cfg9 = 0x00,
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
							},
						},
						.tCP_DSSS_CODE_Value =
						{
							[PWM_AIT_PEN_DEFAULT_BEACON] = /* 1st Beacon */
							{
								.tCP_DSSS_CODE_P_0 = 0xA965A000,
								.tCP_DSSS_CODE_P_1 = 0x95666000,
								.tCP_DSSS_CODE_0_0 = 0x9AA59000,
								.tCP_DSSS_CODE_0_1 = 0x9A559000,
								.tCP_DSSS_CODE_1_0 = 0x99AA5000,
								.tCP_DSSS_CODE_1_1 = 0xA5A55000,
								.tCP_DSSS_CODE_2_0 = 0x5599A000,
								.tCP_DSSS_CODE_2_1 = 0xA965A000,
								.tCP_DSSS_CODE_3_0 = 0x599AA000,
								.tCP_DSSS_CODE_3_1 = 0x965A5000,
								.tCP_DSSS_CODE_4_0 = 0x965A5000,
								.tCP_DSSS_CODE_4_1 = 0x9666A000,
								.tCP_DSSS_CODE_5_0 = 0x65A55000,
								.tCP_DSSS_CODE_5_1 = 0xA66A9000,
								.tCP_DSSS_CODE_6_0 = 0xA5599000,
								.tCP_DSSS_CODE_6_1 = 0xAA965000,
								.tCP_DSSS_CODE_7_0 = 0x5A559000,
								.tCP_DSSS_CODE_7_1 = 0xA6A96000,
							},
//							[PWM_2ndBEACON] = /* 2nd Beacon */
//							{
//								.tCP_DSSS_CODE_P_0 = 0xA965A000,
//								.tCP_DSSS_CODE_P_1 = 0x95666000,
//								.tCP_DSSS_CODE_0_0 = 0x9AA59000,
//								.tCP_DSSS_CODE_0_1 = 0x9A559000,
//								.tCP_DSSS_CODE_1_0 = 0x99AA5000,
//								.tCP_DSSS_CODE_1_1 = 0xA5A55000,
//								.tCP_DSSS_CODE_2_0 = 0x5599A000,
//								.tCP_DSSS_CODE_2_1 = 0xA965A000,
//								.tCP_DSSS_CODE_3_0 = 0x599AA000,
//								.tCP_DSSS_CODE_3_1 = 0x965A5000,
//								.tCP_DSSS_CODE_4_0 = 0x965A5000,
//								.tCP_DSSS_CODE_4_1 = 0x9666A000,
//								.tCP_DSSS_CODE_5_0 = 0x65A55000,
//								.tCP_DSSS_CODE_5_1 = 0xA66A9000,
//								.tCP_DSSS_CODE_6_0 = 0xA5599000,
//								.tCP_DSSS_CODE_6_1 = 0xAA965000,
//								.tCP_DSSS_CODE_7_0 = 0x5A559000,
//								.tCP_DSSS_CODE_7_1 = 0xA6A96000,
//							},
						},
						.tCP_PWM_TPIC_CR =
						{
							.tBit.beacon_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_beacon_en,
							.tBit.pen_s_ping_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_pen_s_ping_en,
							.tBit.pen_d_ping_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_pen_d_ping_en,
							.tBit.finger_ping_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_finger_ping_en,
							.tBit.pen_s_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_pen_s_en,
							.tBit.pen_d_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_pen_d_en,
							.tBit.finger_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_finger_en,
							.tBit.pen_s_dmy_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_pen_s_dmy_en,
							.tBit.pen_d_dmy_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_pen_d_dmy_en,
							.tBit.finger_dmy_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_finger_dmy_en,
							.tBit.pen_s_set_tx_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_pen_s_set_tx_en,
							.tBit.pen_d_set_tx_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_pen_d_set_tx_en,
							.tBit.finger_set_tx_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_finger_set_tx_en,
							.tBit.nm_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_nm_en,
							.tBit.inv_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_inv_en,
							.tBit.ping_only_en = PARAMSET_PWMDRV_AIT_PWM_TPIC_CR_ping_only_en,
						},
						.tCP_PWM_SRIC_CR =
						{
							.tBit.beacon_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_beacon_en,
							.tBit.pen_s_ping_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_pen_s_ping_en,
							.tBit.pen_d_ping_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_pen_d_ping_en,
							.tBit.finger_ping_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_finger_ping_en,
							.tBit.pen_s_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_pen_s_en,
							.tBit.pen_d_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_pen_d_en,
							.tBit.finger_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_finger_en,
							.tBit.pen_s_dmy_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_pen_s_dmy_en,
							.tBit.pen_d_dmy_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_pen_d_dmy_en,
							.tBit.finger_dmy_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_finger_dmy_en,
							.tBit.pen_s_set_tx_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_pen_s_set_tx_en,
							.tBit.pen_d_set_tx_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_pen_d_set_tx_en,
							.tBit.finger_set_tx_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_finger_set_tx_en,
							.tBit.nm_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_nm_en,
							.tBit.inv_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_inv_en,
							.tBit.pwm_2x_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_pwm_2x_en,
							.tBit.pen_s_tsync_d2_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_pen_s_tsync_d2_en,
							.tBit.pen_d_tsync_d2_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_pen_d_tsync_d2_en,
							.tBit.finger_tsync_d2_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_finger_tsync_d2_en,
							.tBit.ping_only_en = PARAMSET_PWMDRV_AIT_PWM_SRIC_CR_ping_only_en,
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
						.tCP_DMY_FREQ = PARAMSET_PWMDRV_AIT_DMY_FREQ,
						.tCP_FREQ_CR1 =
						{
							.tBit.pen_d = PWM_Full_KHz(111),
							.tBit.pen_s = PWM_Full_KHz(111),
							.tBit.finger = PWM_Full_KHz(111),
						},
						.tCP_FREQ_CR2 =
						{
							.tBit.freq_beacon = PWM_Half_KHz(500),
						},
						.tCP_LHB_CONFIG11 =
						{
							.tBit.lhb1 = PARAMSET_PWMDRV_AIT_FULL_LHB_1,
							.tBit.lhb2 = PARAMSET_PWMDRV_AIT_FULL_LHB_2,
							.tBit.lhb3 = PARAMSET_PWMDRV_AIT_FULL_LHB_3,
							.tBit.lhb4 = PARAMSET_PWMDRV_AIT_FULL_LHB_4,
							.tBit.lhb5 = PARAMSET_PWMDRV_AIT_FULL_LHB_5,
							.tBit.lhb6 = PARAMSET_PWMDRV_AIT_FULL_LHB_6,
							.tBit.lhb7 = PARAMSET_PWMDRV_AIT_FULL_LHB_7,
							.tBit.lhb8 = PARAMSET_PWMDRV_AIT_FULL_LHB_8,
							.tBit.lhb9 = PARAMSET_PWMDRV_AIT_FULL_LHB_9,
							.tBit.lhb10 = PARAMSET_PWMDRV_AIT_FULL_LHB_10,
						},
						.tCP_LHB_CONFIG12 =
						{
							.tBit.lhb11 = PARAMSET_PWMDRV_AIT_FULL_LHB_11,
							.tBit.lhb12 = PARAMSET_PWMDRV_AIT_FULL_LHB_12,
							.tBit.lhb13 = PARAMSET_PWMDRV_AIT_FULL_LHB_13,
							.tBit.lhb14 = PARAMSET_PWMDRV_AIT_FULL_LHB_14,
							.tBit.lhb15 = PARAMSET_PWMDRV_AIT_FULL_LHB_15,
							.tBit.lhb16 = PARAMSET_PWMDRV_AIT_FULL_LHB_16,
							.tBit.lhb17 = PARAMSET_PWMDRV_AIT_FULL_LHB_17,
							.tBit.lhb18 = PARAMSET_PWMDRV_AIT_FULL_LHB_18,
							.tBit.lhb19 = PARAMSET_PWMDRV_AIT_FULL_LHB_19,
							.tBit.lhb20 = PARAMSET_PWMDRV_AIT_FULL_LHB_20,
						},
						.tCP_LHB_CONFIG13 =
						{
							.tBit.lhb21 = PARAMSET_PWMDRV_AIT_FULL_LHB_21,
							.tBit.lhb22 = PARAMSET_PWMDRV_AIT_FULL_LHB_22,
							.tBit.lhb23 = PARAMSET_PWMDRV_AIT_FULL_LHB_23,
							.tBit.lhb24 = PARAMSET_PWMDRV_AIT_FULL_LHB_24,
							.tBit.lhb25 = PARAMSET_PWMDRV_AIT_FULL_LHB_25,
							.tBit.lhb26 = PARAMSET_PWMDRV_AIT_FULL_LHB_26,
							.tBit.lhb27 = PARAMSET_PWMDRV_AIT_FULL_LHB_27,
							.tBit.lhb28 = PARAMSET_PWMDRV_AIT_FULL_LHB_28,
							.tBit.lhb29 = PARAMSET_PWMDRV_AIT_FULL_LHB_29,
							.tBit.lhb30 = PARAMSET_PWMDRV_AIT_FULL_LHB_30,
						},
						.tCP_LHB_CONFIG14 =
						{
							.tBit.lhb31 = PARAMSET_PWMDRV_AIT_FULL_LHB_31,
							.tBit.lhb32 = PARAMSET_PWMDRV_AIT_FULL_LHB_32,
						},
						.tCP_LHB_CONFIG21 =
						{
							.tBit.lhb1 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_1,
							.tBit.lhb2 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_2,
							.tBit.lhb3 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_3,
							.tBit.lhb4 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_4,
							.tBit.lhb5 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_5,
							.tBit.lhb6 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_6,
							.tBit.lhb7 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_7,
							.tBit.lhb8 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_8,
							.tBit.lhb9 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_9,
							.tBit.lhb10 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_10,
						},
						.tCP_LHB_CONFIG22 =
						{
							.tBit.lhb11 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_11,
							.tBit.lhb12 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_12,
							.tBit.lhb13 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_13,
							.tBit.lhb14 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_14,
							.tBit.lhb15 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_15,
							.tBit.lhb16 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_16,
							.tBit.lhb17 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_17,
							.tBit.lhb18 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_18,
							.tBit.lhb19 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_19,
							.tBit.lhb20 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_20,
						},
						.tCP_LHB_CONFIG23 =
						{
							.tBit.lhb21 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_21,
							.tBit.lhb22 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_22,
							.tBit.lhb23 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_23,
							.tBit.lhb24 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_24,
							.tBit.lhb25 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_25,
							.tBit.lhb26 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_26,
							.tBit.lhb27 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_27,
							.tBit.lhb28 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_28,
							.tBit.lhb29 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_29,
							.tBit.lhb30 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_30,
						},
						.tCP_LHB_CONFIG24 =
						{
							.tBit.lhb31 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_31,
							.tBit.lhb32 = PARAMSET_PWMDRV_AIT_LOCAL_LHB_32,
						},
						.tCP_PING_CR =
						{
							.tBit.beacon = DISABLE,
							.tBit.pen_s = ENABLE,
							.tBit.pen_d = ENABLE,
							.tBit.finger = ENABLE,
							.tBit.nm = DISABLE,
							.tBit.none = ENABLE,
							.tBit.ping_only = ENABLE,
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
							.tBit.tsync_tpic_out_bypass_enb = PARAMSET_PWMDRV_AIT_TG_DUM5_tsync_tpic_out_bypass_enb,
							.tBit.tsync_sric_out_bypass_enb = 0,
							.tBit.tsync_sric_lhb_ping_en = 0,
							.tBit.sync_gen_fr_done_mask_en = 0,
							.tBit.disp_off_beacon_only = 0,
						},
						.tCP_DISP_OFF_CR =
						{
							.tBit.stuck_en = DISABLE,
							.tBit.stuck_value = 0,
							.tBit.disp_off_fpnt = PWM_nsec(44000),
							.tBit.inv_en = 0,
						},
						.tCP_PWM_CR1 =
						{
							.tBit.pen_s_h_pnt = PWM_Half_KHz(111)+1,
							.tBit.pen_d_h_pnt = PWM_Half_KHz(111)+1,
						},
						.tCP_PWM_CR2 =
						{
							.tBit.finger_h_pnt = PARAMSET_PWMDRV_AIT_PWM_CR2_finger_h_pnt,
							.tBit.dmy_h_pnt = PARAMSET_PWMDRV_AIT_PWM_CR2_dmy_h_pnt,
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
							.tBit.pen_s = PARAMSET_PWMDRV_AIT_MUX_CR_pen_s,
							.tBit.pen_d = PARAMSET_PWMDRV_AIT_MUX_CR_pen_d,
							.tBit.finger = PARAMSET_PWMDRV_AIT_MUX_CR_finger,
							.tBit.nm = PARAMSET_PWMDRV_AIT_MUX_CR_nm,
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
							.tBit.bgap_prd = PARAMSET_PWMDRV_AIT_DLY_CNT4_bgap_prd,
							.tBit.bc_egap_prd = PARAMSET_PWMDRV_AIT_DLY_CNT4_bc_egap_prd,
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
					},
					[ACTIVEPEN_TYPE_LOCAL_WGP] =
					{
						.tCP_PWMGEN_CR0 =
						{
							.tBit.pwm_gen_enable = DISABLE,
							.tBit.kiosk_mode = 0,
							.tBit.tfd_mode = PWM_TSD_MODE,
							.tBit.continuos_en = PWM_CONTINUOS_MODE,
							.tBit.frame_rate = PWM_FRAME_RATE_DIV_1,
							.tBit.chip_length0 = 19,
							.tBit.chip_length1 = 19,
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
							.tBit.tsync_num = (LHB_NUM - 1), // 15LHB
							.tBit.tsync_end_loc = 0,
							.tBit.tsync_dglitch_len = 0,
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
#if USED_WGP_AGIC_PEN
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
		#if USED_WGP_16LHB_ACTIVEPEN
								.tBit.beacon_cfg4 = 0x06,	// Data #1 E
								.tBit.beacon_cfg5 = 0x05,	// Data #2 8
		#else
								.tBit.beacon_cfg4 = 0x02,	// Data #1 6
								.tBit.beacon_cfg5 = 0x05,	// Data #2 8
		#endif
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
#if USED_WGP_AGIC_PEN
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
		#if USED_WGP_16LHB_ACTIVEPEN
								.tBit.beacon_cfg6 = 0x02,	// Data #3 6
								.tBit.beacon_cfg7 = 0x03,	// CRC B
		#else /* USED_WGP_16LHB_ACTIVEPEN */
								.tBit.beacon_cfg6 = 0x02,	// Data #3 6
								.tBit.beacon_cfg7 = 0x04,	// CRC C
		#endif /* USED_WGP_16LHB_ACTIVEPEN */
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
		#if USED_WGP_16LHB_ACTIVEPEN
								.tBit.beacon_cfg6 = 0x06,	// Data #1 E
								.tBit.beacon_cfg7 = 0x05,	// Data #2 8
								.tBit.beacon_cfg8 = 0x02,	// Data #3 6
								.tBit.beacon_cfg9 = 0x03,	// CRC B
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
		#else /* USED_WGP_16LHB_ACTIVEPEN */
								.tBit.beacon_cfg6 = 0x02,	// Data #1 6
								.tBit.beacon_cfg7 = 0x05,	// Data #2 8
								.tBit.beacon_cfg8 = 0x02,	// Data #3 6
								.tBit.beacon_cfg9 = 0x04,	// CRC C
								.tBit.beacon_cfg10 = 0x00,
								.tBit.beacon_cfg11 = 0x00,
		#endif /* USED_WGP_16LHB_ACTIVEPEN */
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
							[PWM_WGP_PEN_GETABS_BEACON] =
							{
								.tCP_DSSS_CODE_P_0 = 0xA965A000,
								.tCP_DSSS_CODE_P_1 = 0x95666000,
								.tCP_DSSS_CODE_0_0 = 0x9AA59000,
								.tCP_DSSS_CODE_0_1 = 0x9A559000,
								.tCP_DSSS_CODE_1_0 = 0x99AA5000,
								.tCP_DSSS_CODE_1_1 = 0xA5A55000,
								.tCP_DSSS_CODE_2_0 = 0x5599A000,
								.tCP_DSSS_CODE_2_1 = 0xA965A000,
								.tCP_DSSS_CODE_3_0 = 0x599AA000,
								.tCP_DSSS_CODE_3_1 = 0x965A5000,
								.tCP_DSSS_CODE_4_0 = 0x965A5000,
								.tCP_DSSS_CODE_4_1 = 0x9666A000,
								.tCP_DSSS_CODE_5_0 = 0x65A55000,
								.tCP_DSSS_CODE_5_1 = 0xA66A9000,
								.tCP_DSSS_CODE_6_0 = 0xA5599000,
								.tCP_DSSS_CODE_6_1 = 0xAA965000,
								.tCP_DSSS_CODE_7_0 = 0x5A559000,
								.tCP_DSSS_CODE_7_1 = 0xA6A96000,
							},
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
							.tBit.freq_beacon = PWM_Half_KHz(500),
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
							.tBit.tsync_sric_out_bypass_enb = 0,
							.tBit.tsync_sric_lhb_ping_en = 0,
							.tBit.sync_gen_fr_done_mask_en = 0,
							.tBit.disp_off_beacon_only = 0,
						},
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
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
							.tBit.tsync_tpic_out_bypass_enb = PARAMSET_PWMDRV_WGP_TG_DUM5_tsync_tpic_out_bypass_enb,
							.tBit.tsync_sric_out_bypass_enb = 0, //0:Bypass, 1:Internal Timing
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
							.tBit.nm = PARAMSET_PWMDRV_WGP_MUX_CR_nm,
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
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
							.tBit.bgap_prd = 1948,//1940,
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
	#if USED_WGP_16LHB_ACTIVEPEN
							.tBit.bgap_prd = 1940+12-360-720,//1950 PWM_nsec(1050),
	#else /* USED_WGP_16LHB_ACTIVEPEN */
							.tBit.bgap_prd = 1940+12-360,//1950 PWM_nsec(1050),
	#endif /* USED_WGP_16LHB_ACTIVEPEN */
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
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
					}
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
//			.tI2C_Conf =
//			{
//				.ucDeviceAddr = I2C_SLAVE_ADDR,
//			},
		},
		.tModule =
		{
//			.bIsSwapXY_ = NO,
//          .bIsFlipX_ = NO,
//			.ucTxLessCol_ = 0,
//			.ucTxLessRow_ = 0,
//#if (USED_MODULE_DEF == MODULE_DEF_L_1 && USED_PANEL_HV60x34_SIZE)
//			.ucScreenCol_ = 60,//72,//84,
//			.ucScreenRow_ = 34,//40,//45,//48,
//			.fPitchX = 4.896,
//			.fPitchY = 4.86,
//#else /* (USED_MODULE_DEF == MODULE_DEF_L_1 && USED_PANEL_HV60x34_SIZE) */
//			.ucScreenCol_ = COL_MAX,
//			.ucScreenRow_ = ROW_MAX,
//			.fPitchX = FPITCH_X,
//			.fPitchY = FPITCH_Y,
//#endif /* (USED_MODULE_DEF == MODULE_DEF_L_1 && USED_PANEL_HV60x34_SIZE) */
			.tSRIC_Conf =
			{
				SRIC_Conf_Set
			},
		},
	},

	.vtParamModeConf =
	{
		[PARAM_MODE_NORMAL] = // MS Pen
		{
			.tAlgorithm =
			{
				.BaseLine =
				{
					.cNormalizeDelta   =					PARAMSET_NORMAL_MODE_ALGO_BaseLine_cNormalizeDelta,
					.ucDiscardFrameNum = 					PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucDiscardFrameNum,
					.ucInitialFrameNum =					PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucInitialFrameNum,
					.usIIRCoef = 							PARAMSET_NORMAL_MODE_ALGO_BaseLine_usIIRCoef,  									// MAX : BASELINE_TRACKING_RESOLUTION
					.sBlockPosThd = 						PARAMSET_NORMAL_MODE_ALGO_BaseLine_sBlockPosThd,
					.sBlockNegThd = 						PARAMSET_NORMAL_MODE_ALGO_BaseLine_sBlockNegThd,
					.sAccumPosSumThd = 						PARAMSET_NORMAL_MODE_ALGO_BaseLine_sAccumPosSumThd,
					.sAccumNegSumThd = 						PARAMSET_NORMAL_MODE_ALGO_BaseLine_sAccumNegSumThd,
				    .sIdle_BlockPosThd = 					PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_BlockPosThd,
				    .sIdle_BlockNegThd = 					PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_BlockNegThd,
				    .sIdle_PosTotalSumThd = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_PosTotalSumThd,
				    .sIdle_NegTotalSumThd = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_NegTotalSumThd,
				    .sLocalIdle_BlockPosThd = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_BlockPosThd,
				    .sLocalIdle_BlockNegThd = 				PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_BlockNegThd,
				    .sLocalIdle_PosTotalSumThd = 			PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_PosTotalSumThd,
				    .sLocalIdle_NegTotalSumThd = 			PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_NegTotalSumThd,
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
					.b2MUX_SUM_LocalMode		=	 		PARAMSET_NORMAL_MODE_ALGO_BaseLine_b2MUX_SUM_LocalMode,
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
				},
				.SensingFilter =
				{
					.cLineFilter = 							PARAMSET_NORMAL_MODE_ALGO_SensingFilter_cLineFilter,					// 0 : off, 1 : AVG SW, 2 : Fourth Min SW, 3 : AVG DSP_A
					.sLineFilterUpLimit = 					PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterUpLimit,
					.sLineFilterLowLimit = 					PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterLowLimit,
					.ucLineFilterColOffset = 				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucLineFilterColOffset,
					.ucLineFilterRepeatTH = 				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucLineFilterRepeatTH,
					.cLineFilterMinTH = 					PARAMSET_NORMAL_MODE_ALGO_SensingFilter_cLineFilterMinTH,				
					.cLineFilter_Pen = 						PARAMSET_NORMAL_MODE_ALGO_SensingFilter_cLineFilter_Pen,				// 0 : off, 1 : AVG SW, 2 : Fourth Min SW, 3 : AVG DSP_A
					.ucLocalSearchModeLineFilter=			PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucLocalSearchModeLineFilter,	// 0 : off, 1 : AVG SW, 2 : Fourth Min SW, 3 : AVG DSP_A
					.bRingRawLineFilter		= 				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_bRingRawLineFilter,
					.sLineFilterUpLimit_Pen = 				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterUpLimit_Pen,			// When Use AVG DSP_A Linefilter for Pen             
					.sLineFilterLowLimit_Pen = 				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterLowLimit_Pen,		// When Use AVG DSP_A Linefilter for Pen
					.sLineFilterUpLimit_Idle =				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterUpLimit_Idle,
					.sLineFilterLowLimit_Idle =				PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterLowLimit_Idle,
					.ucRingDeltaIIR_Coef				=	PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucRingDeltaIIR_Coef,
					.sFingerAreaLineFilterLimit			=	PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sFingerAreaLineFilterLimit,							 // 0 : off #define FingerAreaLineFilte 
					.ucFingerAreaLineFilterOffset		=	PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucFingerAreaLineFilterOffset,						 // #define FingerAreaLineFilte
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
					.ucMergeSmallThdPer =					PARAMSET_NORMAL_MODE_ALGO_Label_ucMergeSmallThdPer,
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
					.ucHoverInCheckFrm = 					PARAMSET_NORMAL_MODE_ALGO_Label_ucHoverInCheckFrm,//2,
					.ucHoverOutCheckFrm = 					PARAMSET_NORMAL_MODE_ALGO_Label_ucHoverOutCheckFrm,//2,
					.ucHoverOutOffset = 					PARAMSET_NORMAL_MODE_ALGO_Label_ucHoverOutOffset,
					.usLabelPeakValleyDiffTh 			=   PARAMSET_NORMAL_MODE_ALGO_Label_usLabelPeakValleyDiffTh,
					.usLabelPeakDiffTh 					=   PARAMSET_NORMAL_MODE_ALGO_Label_usLabelPeakDiffTh,
					.usMergeLabelSizeTh 				=   PARAMSET_NORMAL_MODE_ALGO_Label_usMergeLabelSizeTh,
				},
				.Coord =
				{
					.ucDynamicTrackingDistanceMode = 		PARAMSET_NORMAL_MODE_ALGO_Coord_ucDynamicTrackingDistanceMode,
					.ucFastDrawingMode = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucFastDrawingMode,
					.usMoveDistanceThd = 					PARAMSET_NORMAL_MODE_ALGO_Coord_usMoveDistanceThd,//3, //2,
					.usDistThdMovingToStationary = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usDistThdMovingToStationary,
					.usDistThdStationaryToMoving = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usDistThdStationaryToMoving,
					.usFirstMoveDistanceThd = 				PARAMSET_NORMAL_MODE_ALGO_Coord_usFirstMoveDistanceThd,
					.lMoveSmoothingLevel = 					PARAMSET_NORMAL_MODE_ALGO_Coord_lMoveSmoothingLevel,//9,
					.ucVectorPredictionCoef = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucVectorPredictionCoef,
					.usDrumTestDist = 						PARAMSET_NORMAL_MODE_ALGO_Coord_usDrumTestDist,
					.lLargeTouchOnThd = 					PARAMSET_NORMAL_MODE_ALGO_Coord_lLargeTouchOnThd,
					.ucLargeTouchOnDebCnt = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucLargeTouchOnDebCnt,
					.lMediumTouchOnThd = 					PARAMSET_NORMAL_MODE_ALGO_Coord_lMediumTouchOnThd,
					.ucMediumTouchOnDebCnt =				PARAMSET_NORMAL_MODE_ALGO_Coord_ucMediumTouchOnDebCnt,
					.lSmallTouchOnThd = 					PARAMSET_NORMAL_MODE_ALGO_Coord_lSmallTouchOnThd,//40,
					.ucSmallTouchOnDebCnt = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmallTouchOnDebCnt,
					.bEdgeDebCntUp =						PARAMSET_NORMAL_MODE_ALGO_Coord_bEdgeDebCntUp,
					.sFirstTouchOnMaxCellVal = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchOnMaxCellVal,//40,
					.lTouchOffThd = 						PARAMSET_NORMAL_MODE_ALGO_Coord_lTouchOffThd,//22,//28,
					.ucMultifingerFirstTouchThDownOffset =	PARAMSET_NORMAL_MODE_ALGO_Coord_ucMultifingerFirstTouchThDownOffset,
					.usCenterMatchDistanceThd = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usCenterMatchDistanceThd,
					.ucLocalFingerInterpolation_On = 		PARAMSET_NORMAL_MODE_ALGO_Coord_ucLocalFingerInterpolation_On,
					.ucFullFingerInterpolation_On =			PARAMSET_NORMAL_MODE_ALGO_Coord_ucFullFingerInterpolation_On,
					.sInterpolationWeight			=		PARAMSET_NORMAL_MODE_ALGO_Coord_sInterpolationWeight,					// For Win10Cer Reporting rate test & Duplicate packets error of Jitter test, HanCH
					.ucExpectClipping_Finger_On = 			PARAMSET_NORMAL_MODE_ALGO_Coord_ucExpectClipping_Finger_On,
					.cEdgeSmoothing_Finger_On =				PARAMSET_NORMAL_MODE_ALGO_Coord_cEdgeSmoothing_Finger_On,
					.ucFirstMoveEventTHD = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucFirstMoveEventTHD,
					.ucMoveEventTHD = 						PARAMSET_NORMAL_MODE_ALGO_Coord_ucMoveEventTHD,
					.sFingerGlobalCoordiXResolutionOffset = PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiXResolutionOffset,
					.sFingerGlobalCoordiYResolutionOffset = PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset,
					.sFingerGlobalCoordiOffsetX =        	PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiOffsetX,
					.sFingerGlobalCoordiOffsetY =        	PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiOffsetY,
					.ucLeftEdgeExpand =						PARAMSET_NORMAL_MODE_ALGO_Coord_ucLeftEdgeExpand,
					.ucRightEdgeExpand = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucRightEdgeExpand,
					.ucTopEdgeExpand = 						PARAMSET_NORMAL_MODE_ALGO_Coord_ucTopEdgeExpand,
					.ucBottomEdgeExpand = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucBottomEdgeExpand,
					.usLeftEdgeExpand_Offset   = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usLeftEdgeExpand_Offset,				//EdgeExpandFinger
					.usRightEdgeExpand_Offset  = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usRightEdgeExpand_Offset,
					.usTopEdgeExpand_Offset    = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usTopEdgeExpand_Offset,
					.usBottomEdgeExpand_Offset = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usBottomEdgeExpand_Offset,
					.usLeftEdgeExpand_Scale    = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usLeftEdgeExpand_Scale,
					.usRightEdgeExpand_Scale   = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usRightEdgeExpand_Scale,
					.usTopEdgeExpand_Scale     = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usTopEdgeExpand_Scale,
					.usBottomEdgeExpand_Scale  = 			PARAMSET_NORMAL_MODE_ALGO_Coord_usBottomEdgeExpand_Scale,
#if (CUSTOMER == MODEL_DEF_FHD_92503B)
					.usLeftEdgeExpand_MaxD		=			PARAMSET_NORMAL_MODE_ALGO_Coord_usLeftEdgeExpand_MaxD,					//For Win10Cer 16Phi & 7Phi Edge Test
					.usRightEdgeExpand_MaxD     =			PARAMSET_NORMAL_MODE_ALGO_Coord_usRightEdgeExpand_MaxD,
					.usTopEdgeExpand_MaxD       =			PARAMSET_NORMAL_MODE_ALGO_Coord_usTopEdgeExpand_MaxD,
					.usBottomEdgeExpand_MaxD    =			PARAMSET_NORMAL_MODE_ALGO_Coord_usBottomEdgeExpand_MaxD,					
					.usBigFingerEdgeExpandParam1	=		PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeExpandParam1,
					.usBigFingerEdgeExpandParam2	=		PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeExpandParam2,
					.usBigFingerEdgeExpandParam3	=		PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeExpandParam3,
					.ucEdgeReportDelayCnt			=		3,//10,
					.usBigFingerEdgeTest_MoveEventTHD_X	=	196,
					.usBigFingerEdgeTest_MoveEventTHD_Y	=	365,				
					.usBigFingerEdgeTestClippingTop		=	580,
					.usBigFingerEdgeTestClippingBottom	=	580,
					.usBigFingerEdgeTestClippingLeft	=	320,
					.usBigFingerEdgeTestClippingRight	=	320,
					.bFingerCornerTestClippingOn		=	1,
#endif
					.usPostProcessEdgeTH = 					PARAMSET_NORMAL_MODE_ALGO_Coord_usPostProcessEdgeTH,
					.ucPostProcessDisTH =					PARAMSET_NORMAL_MODE_ALGO_Coord_ucPostProcessDisTH,
					.ucPostProcessExpendDiv =				PARAMSET_NORMAL_MODE_ALGO_Coord_ucPostProcessExpendDiv,
					.cPostProcessEndMargin =				PARAMSET_NORMAL_MODE_ALGO_Coord_cPostProcessEndMargin,
					.bPostProcessInterpolationMode		=   PARAMSET_NORMAL_MODE_ALGO_Coord_bPostProcessInterpolationMode,
					.usOutInDrawEdgeTh = 					PARAMSET_NORMAL_MODE_ALGO_Coord_usOutInDrawEdgeTh,
					.ucOutInDrawDisTh = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucOutInDrawDisTh,
					.ucSmoothPastOrgInter =					PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmoothPastOrgInter,
					.cDisSmoothOffset =						PARAMSET_NORMAL_MODE_ALGO_Coord_cDisSmoothOffset,
					.bFingerMeanSmoothing =					PARAMSET_NORMAL_MODE_ALGO_Coord_bFingerMeanSmoothing,
					
					.ucWinCertAssistance = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucWinCertAssistance,	//1,		//0 : Off, 1 : LGD MNT 27", 2 : LGD Kiosk
					.ucTouchCountMax = 						PARAMSET_NORMAL_MODE_ALGO_Coord_ucTouchCountMax,	//3,			//LGD MNT 27" : 3, LGD Kiosk 43",55" : 30
					.ucMaxExtendFrameNum = 					PARAMSET_NORMAL_MODE_ALGO_Coord_ucMaxExtendFrameNum,	//10,		//LGD MNT 27" : 10, LGD Kiosk 43", 55" : 100
					.sFirstTouchEnable1Touch = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable1Touch,	//90,	//Enable First touch
					.sFirstTouchEnable2Touch = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable2Touch,	//80,
					.sFirstTouchEnable3Touch = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable3Touch,	//75,
					.sFirstTouchEnable4Touch = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable4Touch,	//70,
					.sFirstTouchEnable5Touch = 				PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable5Touch,	//60,
					.ucDebCntInner			 = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucDebCntInner,	//0,
					.ucDebCntEdge			 = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucDebCntEdge,	//1,
					.usFirstDrawingThd		 = 				PARAMSET_NORMAL_MODE_ALGO_Coord_usFirstDrawingThd,	//128,
					.ucFirstDrawingCellCnt   = 				PARAMSET_NORMAL_MODE_ALGO_Coord_ucFirstDrawingCellCnt,
					.bSwapXY				 =				PARAMSET_NORMAL_MODE_ALGO_Coord_bSwapXY,
					.bFlipX					 =				PARAMSET_NORMAL_MODE_ALGO_Coord_bFlipX,
					.bDoNotExpandPos		 =				PARAMSET_NORMAL_MODE_ALGO_Coord_bDoNotExpandPos,
				},
				.PenCoord =
				{
					.ucTipRangeExtend_On = 					PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucTipRangeExtend_On,
					.bExpectClipping_Pen_On = 				PARAMSET_NORMAL_MODE_ALGO_PenCoord_bExpectClipping_Pen_On,
					.ucCompenCoefA =						PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucCompenCoefA,
					.ucCompenCoefB =						PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucCompenCoefB,
					.ucHoverCompenCoefA = 					PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucHoverCompenCoefA,
					.ucHoverCompenCoefB	=					PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucHoverCompenCoefB,
					.bCompenEdgeOn =						PARAMSET_NORMAL_MODE_ALGO_PenCoord_bCompenEdgeOn,
					.ucPenPostProcessEdgeTH = 				PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenPostProcessEdgeTH,
					.ucPenPostProcessDisTH = 				PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenPostProcessDisTH,
					.ucPenPostProcessExpendDiv = 			PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenPostProcessExpendDiv,
					.cHoverSmoothOffset	= 					PARAMSET_NORMAL_MODE_ALGO_PenCoord_cHoverSmoothOffset,
					.bFullFingerOn = 						PARAMSET_NORMAL_MODE_ALGO_PenCoord_bFullFingerOn,
					.sPenGlobalCoordiXResolutionOffset = 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiXResolutionOffset,
					.sPenGlobalCoordiYResolutionOffset = 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiYResolutionOffset,
					.sPenGlobalCoordiOffsetX = 			 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiOffsetX,
					.sPenGlobalCoordiOffsetY = 			 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiOffsetY,
					.ucLeftEdgeExpand_local =				PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucLeftEdgeExpand_local,
					.ucRightEdgeExpand_local = 				PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucRightEdgeExpand_local,
					.ucTopEdgeExpand_local = 				PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucTopEdgeExpand_local,
					.ucBottomEdgeExpand_local = 			PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucBottomEdgeExpand_local,
					.uclatency_up_dis_condition			= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_uclatency_up_dis_condition,  // off : 0
					.uclatency_up_cnt_condition			= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_uclatency_up_cnt_condition,  // range : 0 ~ 255
					.clatency_up_dis_offset				=	PARAMSET_NORMAL_MODE_ALGO_PenCoord_clatency_up_dis_offset,                                                       
					.ucideal_inter_dis					= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_ideal_inter_dis,				// range : 0 ~ 255
					.ucideal_inter_mv					= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_ideal_inter_mv,				// range : 0 ~ 255
					.uc_connect_count					=   PARAMSET_NORMAL_MODE_ALGO_PenCoord_uc_connect_count,
					.ucMarkBoundaryNum					= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucMarkBoundaryNum,
                    .ucPenEdgeDebCnt                    =   PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenEdgeDebCnt,
					.usLongDisPointExceptionTH			= 	PARAMSET_NORMAL_MODE_ALGO_PenCoord_usLongDisPointExceptionTH,
				},
				.PenTilt =
				{
					.bTiltCalOnlyContact				=  	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltCalOnlyContact,
					.cHoverOverShiftRingOffset			=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_cHoverOverShiftRingOffset,
					.ucHoverDeltaMul					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHoverDeltaMul,
					.bTiltCalUsingTipOrg				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltCalUsingTipOrg,
					.ucCoordiShiftX_WithTilt  =    			PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftX_WithTilt,		// 0 : Shift Off
					.ucCoordiShiftY_WithTilt  =    			PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftY_WithTilt,	
					.ucCoordiShiftEdgeOn		= 			PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftEdgeOn,  	// 0 : Edge Off , 1 : Center Same Coef , 2 : Coef Up
					.ucCoordiShiftWithTilt_RingTH		=   PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftWithTilt_RingTH,
					.ucCoordiShiftWithTiltCompenTH		= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftWithTiltCompenTH,
					.ucTiltL					= 			PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucTiltL,
					.usTiltChangeLimitFilter			= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTiltChangeLimitFilter,
					.ucTiltSmoothingFilterCoef		= 		PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucTiltSmoothingFilterCoef, //Max : 32
					.ucHalfCoefSmoothFrm				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHalfCoefSmoothFrm,
					.ucHalfCoef							= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHalfCoef,
					.ucHighDelta_TiltSmooth_change_Th	= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHighDelta_TiltSmooth_change_Th,
					.cHighDelta_TiltSmooth_change_offset=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_cHighDelta_TiltSmooth_change_offset,
					.usTilt_Change_TH_Reverse			=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTilt_Change_TH_Reverse,
					.usTilt_Change_TH_Right				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTilt_Change_TH_Right,
					.bTiltBasedRingDelta				= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltBasedRingDelta,
					.bTiltDirecLimitFilter				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltDirecLimitFilter,
					.ucTiltDeltaLimitFilter				=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucTiltDeltaLimitFilter,
					.bTiltMedianFilter					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltMedianFilter,
					.bRingBaseTracking					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bRingBaseTracking,
					.bTiltRowIndexChange				= 	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltRowIndexChange,
					.usReleaseLastContact3x3Frm 		=   PARAMSET_NORMAL_MODE_ALGO_PenTilt_usReleaseLastContact3x3Frm,
					.usUseLastContact3x3Th				=   PARAMSET_NORMAL_MODE_ALGO_PenTilt_usUseLastContact3x3Th,
					.bArcSinLookUp_1					=	PARAMSET_NORMAL_MODE_ALGO_PenTilt_bArcSinLookUp_1,
				},
				.PenData = 
				{
					.ucPenDataLocalTHD = 					PARAMSET_NORMAL_MODE_ALGO_PenData_ucPenDataLocalTHD,
					.ucPenDataHoverTHD = 					PARAMSET_NORMAL_MODE_ALGO_PenData_ucPenDataHoverTHD,
					.usPenDataHighHoverButtonRejectTHD = 	PARAMSET_NORMAL_MODE_ALGO_PenData_usPenDataHighHoverButtonRejectTHD,
					.ucForcePenContact_NUM = 				PARAMSET_NORMAL_MODE_ALGO_PenData_ucForcePenContact_NUM,
					.ucSEN_CONT_CNT						=	PARAMSET_NORMAL_MODE_ALGO_PenData_ucSEN_CONT_CNT,
					.ucKeepProtocolNum =					PARAMSET_NORMAL_MODE_ALGO_PenData_ucKeepProtocolNum,
				},
				.EdgePenSetVal =
				{
					.top_th 							= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_th,//0,
					.top_mul 							= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_mul,
					.top_SR 							= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_SR,
					.bottom_th 							=	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_th,//0,
					.bottom_mul 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_mul,
					.bottom_SR 							= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_SR,
					.left_th 							= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_th,//0,
					.left_mul 							= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_mul,
					.left_SR 							= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_SR,
					.right_th 							= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_th,//0,
					.right_mul 							= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_mul,
					.right_SR 							= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_SR,
					.top_hover_th 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_hover_th,//580,
					.top_hover_mul						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_hover_mul,//19,
					.top_hover_SR 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_hover_SR,//4,
					.bottom_hover_th					= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_hover_th,//580,
					.bottom_hover_mul 					= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_hover_mul,//24,//19,
					.bottom_hover_SR 					= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_hover_SR,//4,
					.left_hover_th 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_hover_th,//620,
					.left_hover_mul 					= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_hover_mul,//19,
					.left_hover_SR 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_hover_SR,//4,
					.right_hover_th 					= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_hover_th,//620,
					.right_hover_mul 					= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_hover_mul,//19,
					.right_hover_SR 					= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_hover_SR,//4,
					.top_ring_th 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_ring_th,
					.top_ring_mul 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_ring_mul,
					.top_ring_SR 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_ring_SR,
					.bottom_ring_th 					= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_ring_th,//600,
					.bottom_ring_mul 					= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_ring_mul,
					.bottom_ring_SR 					= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_ring_SR,
					.left_ring_th 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_ring_th,//600,
					.left_ring_mul 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_ring_mul,
					.left_ring_SR 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_ring_SR,
					.right_ring_th 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_ring_th,//600,
					.right_ring_mul 					= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_ring_mul,
					.right_ring_SR 						= 	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_ring_SR,                        
					.chover_mul_button1_offset			=	PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_chover_mul_button1_offset,
				},	
				.PenDisBaseSmoothSetVal =
				{
					.c_edge_smooth_offset_hover			= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_edge_smooth_offset_hover,				// range : -127 ~ 126, off : 127
					.c_edge_smooth_offset_contact  		= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_edge_smooth_offset_contact,  			// range : -127 ~ 126, off : 127
					.uc_global_smooth_dis_condition_contact=PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_dis_condition_contact,	// range : 1 ~ 255, off : 0
					.c_global_smooth_offset_contact  	= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_global_smooth_offset_contact,			// range : -127 ~ 127,
					.us_corner_smooth_delta_condition_hover=PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_us_corner_smooth_delta_condition_hover,  	// range : 1 ~ 65535, off : 0
					.c_corner_smooth_offset_hover		= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_corner_smooth_offset_hover,				// range : -127 ~ 127
					.uc_edge_smooth_dis_condition_contact= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_edge_smooth_dis_condition_contact,		// range : 1 ~ 255
					.uc_global_smooth_delta_condition_hover=PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_delta_condition_hover,	// range : 1 ~ 255, off : 0
					.uc_global_smooth_dis_condition_hover= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_dis_condition_hover,		// range : 0 ~ 255
					.c_global_smooth_offset_hover		= 	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_global_smooth_offset_hover,				// range : -127 ~ 127
					.usEdge_Range						=	PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_usEdge_Range,
				},
				.PenParaEdgeSetVal =
				{
					.th0 							= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_th0,				// mul1 off 255 set
					.top_mul0						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_mul0,           // mul0 off 127 set
					.top_SR0						= 		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_SR0,            // mul0 off 0 	set
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
					.top_max_sum  = 				  		PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_max_sum,
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
				},
				.Noise =
				{
					.ucNoiseDetectionMode = 				PARAMSET_NORMAL_MODE_ALGO_Noise_ucNoiseDetectionMode,		//0: OFF, 1 : previous 2 : LGD MNT 27"
					.ucDiscardFrameNum = 					PARAMSET_NORMAL_MODE_ALGO_Noise_ucDiscardFrameNum,
					.ucCellCntThd = 						PARAMSET_NORMAL_MODE_ALGO_Noise_ucCellCntThd,
					.ucHoppingThd = 						PARAMSET_NORMAL_MODE_ALGO_Noise_ucHoppingThd,
					.ucNoiseThd = 							PARAMSET_NORMAL_MODE_ALGO_Noise_ucNoiseThd,
					.usRawDataThd =							PARAMSET_NORMAL_MODE_ALGO_Noise_usRawDataThd,
					.sDeltaDataThd = 						PARAMSET_NORMAL_MODE_ALGO_Noise_sDeltaDataThd,
					.ucTouchOffCntThd = 					PARAMSET_NORMAL_MODE_ALGO_Noise_ucTouchOffCntThd,
					.bPenNoiseReductionOff				= 	PARAMSET_NORMAL_MODE_ALGO_Noise_bPenNoiseReductionOff,
					.ucPenFingerSameLineNoiseSize =			PARAMSET_NORMAL_MODE_ALGO_Noise_ucPenFingerSameLineNoiseSize,
					.ucHoverNoiseRejectTH			=		PARAMSET_NORMAL_MODE_ALGO_Noise_ucHoverNoiseRejectTH,
					.ucHoverNoiseRejectFrm		=			PARAMSET_NORMAL_MODE_ALGO_Noise_ucHoverNoiseRejectFrm,
					.ucSearchNoiseRejectTH			=		PARAMSET_NORMAL_MODE_ALGO_Noise_ucSearchNoiseRejectTH,
					.ucSearchNoiseRejectFrm		=			PARAMSET_NORMAL_MODE_ALGO_Noise_ucSearchNoiseRejectFrm,
					.cAdaptorNoiseTH = 						PARAMSET_NORMAL_MODE_ALGO_Noise_cAdaptorNoiseTH,
					.ucAdaptorNoiseContiNum = 				PARAMSET_NORMAL_MODE_ALGO_Noise_ucAdaptorNoiseContiNum,
					.cAdaptorNoiseTH_SearchHover = 			PARAMSET_NORMAL_MODE_ALGO_Noise_cAdaptorNoiseTH_SearchHover,
					.ucAdaptorNoiseContiNum_SearchHover = 	PARAMSET_NORMAL_MODE_ALGO_Noise_ucAdaptorNoiseContiNum_SearchHover,
					.bPenPosSymbolRepeatCheck = 			PARAMSET_NORMAL_MODE_ALGO_Noise_bPenPosSymbolRepeatCheck,
					.ucCPITestOn = 							PARAMSET_NORMAL_MODE_ALGO_Noise_ucCPITestOn,
					.ucErrorFrameProcess = 					PARAMSET_NORMAL_MODE_ALGO_Noise_ucErrorFrameProcess,
				},				
				.Palm =
				{
					.ucPalmDetectionOn = 					PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalmDetectionOn,		//0 : off, 1 : Version 1, 2 : Version 2, 3 : 1, 2 Adpative
					.usPalmLevel = 							PARAMSET_NORMAL_MODE_ALGO_Palm_usPalmLevel,//20,//12,
					.ucPalm_PALM_CONNECT_DIST = 			PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_PALM_CONNECT_DIST, 
					.ucPalm_PALM_REGION_UPDATE_PERIOD = 	PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_PALM_REGION_UPDATE_PERIOD,
					.ucPalm_TOUCHDOWNFRAMEMAX = 			PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_TOUCHDOWNFRAMEMAX,
					.ucPalm_TOUCHDOWNSLOPETHRESHOLD = 		PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_TOUCHDOWNSLOPETHRESHOLD,
					.ucPalm_IGNOREFRAMENUM = 				PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_IGNOREFRAMENUM,
					.ucPalm_KEEPPALMREGIONFRAME = 			PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_KEEPPALMREGIONFRAME,
					.ucPalmDrawingOn = 						PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalmDrawingOn,
					.bPalm_WholeTouchRemove = 				PARAMSET_NORMAL_MODE_ALGO_Palm_bPalm_WholeTouchRemove,
				},
			},
			.tModule =
			{
				.ucOvrShift = 								PARAMSET_NORMAL_MODE_ALGO_ucOvrShift,//3,
				.ucIdleOvrShift = 							PARAMSET_NORMAL_MODE_ALGO_ucIdleOvrShift,//1,
				.ucLocalOvrShift = 							PARAMSET_NORMAL_MODE_ALGO_ucLocalOvrShift,//2,
				.ucLocalIdleOvrShift = 						PARAMSET_NORMAL_MODE_ALGO_ucLocalIdleOvrShift,//2,
				.ucLocalOvrShift_Ring = 					PARAMSET_NORMAL_MODE_ALGO_ucLocalOvrShift_Ring,//0,
			},
		}, /* PARAM_MODE_NORMAL */
		[PARAM_MODE_NORMAL_1] = // Wacom Pen
		{
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
				    .sIdle_PosTotalSumThd = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_PosTotalSumThd,
				    .sIdle_NegTotalSumThd = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_NegTotalSumThd,
				    .sLocalIdle_BlockPosThd = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_BlockPosThd,
				    .sLocalIdle_BlockNegThd = 				PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_BlockNegThd,
				    .sLocalIdle_PosTotalSumThd = 			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_PosTotalSumThd,
				    .sLocalIdle_NegTotalSumThd = 			PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_NegTotalSumThd,
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
				},                                                               
				.SensingFilter =                                                 
				{                                                               
					.cLineFilter = 							PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_cLineFilter,						// 0 : off, 1 : AVG SW, 2 : Fourth Min SW, 3 : AVG DSP_A
					.sLineFilterUpLimit = 					PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterUpLimit,               
					.sLineFilterLowLimit = 					PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterLowLimit,              
					.ucLineFilterColOffset = 				PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucLineFilterColOffset,            
					.ucLineFilterRepeatTH = 				PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucLineFilterRepeatTH,             
					.cLineFilterMinTH = 					PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_cLineFilterMinTH,                 
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
					.ucLocalPenRingDetectTH1 = 				30,
					.ucLocalPenRingDetectTH2 = 				60,
					.ucHoverInCheckFrm = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_ucHoverInCheckFrm,//2,
					.ucHoverOutCheckFrm = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_ucHoverOutCheckFrm,//2,
					.ucHoverOutOffset = 					PARAMSET_NORMAL_MODE_1_ALGO_Label_ucHoverOutOffset,
					.usLabelPeakValleyDiffTh 			=   PARAMSET_NORMAL_MODE_1_ALGO_Label_usLabelPeakValleyDiffTh,
					.usLabelPeakDiffTh 					=   PARAMSET_NORMAL_MODE_1_ALGO_Label_usLabelPeakDiffTh,
					.usMergeLabelSizeTh 				=   PARAMSET_NORMAL_MODE_1_ALGO_Label_usMergeLabelSizeTh,
				},
				.Coord =
				{
					.ucDynamicTrackingDistanceMode = 		PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucDynamicTrackingDistanceMode,
					.ucFastDrawingMode = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFastDrawingMode,
					.usMoveDistanceThd = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_usMoveDistanceThd,//3, //2,
					.usDistThdMovingToStationary = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usDistThdMovingToStationary,
					.usDistThdStationaryToMoving = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usDistThdStationaryToMoving,
					.usFirstMoveDistanceThd = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_usFirstMoveDistanceThd,
					.lMoveSmoothingLevel = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_lMoveSmoothingLevel,//9,
					.ucVectorPredictionCoef = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucVectorPredictionCoef,
					.usDrumTestDist = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_usDrumTestDist,
					.lLargeTouchOnThd = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_lLargeTouchOnThd,
					.ucLargeTouchOnDebCnt = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLargeTouchOnDebCnt,
					.lMediumTouchOnThd = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_lMediumTouchOnThd,
					.ucMediumTouchOnDebCnt = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMediumTouchOnDebCnt,
					.lSmallTouchOnThd = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_lSmallTouchOnThd,//40,
					.ucSmallTouchOnDebCnt = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchOnDebCnt,
					.bEdgeDebCntUp = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_bEdgeDebCntUp,
					.sFirstTouchOnMaxCellVal = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchOnMaxCellVal,//40,
					.lTouchOffThd = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_lTouchOffThd,//22,//28,
					.ucMultifingerFirstTouchThDownOffset =	PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMultifingerFirstTouchThDownOffset,
					.usCenterMatchDistanceThd = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usCenterMatchDistanceThd,
					.ucLocalFingerInterpolation_On = 		PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLocalFingerInterpolation_On,
					.ucFullFingerInterpolation_On = 		PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFullFingerInterpolation_On,
					.sInterpolationWeight		=			PARAMSET_NORMAL_MODE_1_ALGO_Coord_sInterpolationWeight,					// For Win10Cer Reporting rate test & Duplicate packets error of Jitter test, HanCH
					.ucExpectClipping_Finger_On = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucExpectClipping_Finger_On,
					.cEdgeSmoothing_Finger_On = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_cEdgeSmoothing_Finger_On,
					.ucFirstMoveEventTHD = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFirstMoveEventTHD,
					.ucMoveEventTHD = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMoveEventTHD,
					.sFingerGlobalCoordiXResolutionOffset = PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiXResolutionOffset,
					.sFingerGlobalCoordiYResolutionOffset = PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset,
					.sFingerGlobalCoordiOffsetX =        	PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetX,
					.sFingerGlobalCoordiOffsetY =        	PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetY,
					.ucLeftEdgeExpand = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLeftEdgeExpand,
					.ucRightEdgeExpand = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRightEdgeExpand,
					.ucTopEdgeExpand = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTopEdgeExpand,
					.ucBottomEdgeExpand = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucBottomEdgeExpand,
					.usLeftEdgeExpand_Offset   = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLeftEdgeExpand_Offset,				//EdgeExpandFinger
					.usRightEdgeExpand_Offset  = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRightEdgeExpand_Offset,
					.usTopEdgeExpand_Offset    = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usTopEdgeExpand_Offset,
					.usBottomEdgeExpand_Offset = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBottomEdgeExpand_Offset,
					.usLeftEdgeExpand_Scale    = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLeftEdgeExpand_Scale,
					.usRightEdgeExpand_Scale   = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRightEdgeExpand_Scale,
					.usTopEdgeExpand_Scale     = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usTopEdgeExpand_Scale,
					.usBottomEdgeExpand_Scale  = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBottomEdgeExpand_Scale,
					.usLeftEdgeExpand_MaxD		=			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLeftEdgeExpand_MaxD,				//For Win10Cer 16Phi & 7Phi Edge Test
					.usRightEdgeExpand_MaxD     =			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRightEdgeExpand_MaxD,
					.usTopEdgeExpand_MaxD       =			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usTopEdgeExpand_MaxD,
					.usBottomEdgeExpand_MaxD    =			PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBottomEdgeExpand_MaxD,		
//					.usBigFingerEdgeExpandParam1	=		PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam1,
//					.usBigFingerEdgeExpandParam2	=		PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam2,
//					.usBigFingerEdgeExpandParam3	=		PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam3,
					.usPostProcessEdgeTH = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_usPostProcessEdgeTH,
					.ucPostProcessDisTH =					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucPostProcessDisTH,
					.ucPostProcessExpendDiv =				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucPostProcessExpendDiv,
					.cPostProcessEndMargin =				PARAMSET_NORMAL_MODE_1_ALGO_Coord_cPostProcessEndMargin,
					.bPostProcessInterpolationMode		=   PARAMSET_NORMAL_MODE_1_ALGO_Coord_bPostProcessInterpolationMode,
					.usOutInDrawEdgeTh = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_usOutInDrawEdgeTh,
					.ucOutInDrawDisTh = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucOutInDrawDisTh,
					.ucSmoothPastOrgInter =					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmoothPastOrgInter,
					.cDisSmoothOffset =						PARAMSET_NORMAL_MODE_1_ALGO_Coord_cDisSmoothOffset,
					.bFingerMeanSmoothing =					PARAMSET_NORMAL_MODE_1_ALGO_Coord_bFingerMeanSmoothing,					
					.ucWinCertAssistance = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucWinCertAssistance,	//1,		//0 : Off, 1 : LGD MNT 27", 2 : LGD Kiosk
					.bWinCertDrawingAssistanceOn	=		PARAMSET_NORMAL_MODE_1_ALGO_Coord_bWinCertDrawingAssistanceOn,
					.ucTouchCountMax = 						PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTouchCountMax,	//3,			//LGD MNT 27" : 3, LGD Kiosk 43",55" : 30
					.ucMaxExtendFrameNum = 					PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMaxExtendFrameNum,	//10,		//LGD MNT 27" : 10, LGD Kiosk 43", 55" : 100
					.sFirstTouchEnable1Touch = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable1Touch,	//90,	//Enable First touch
					.sFirstTouchEnable2Touch = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable2Touch,	//80,
					.sFirstTouchEnable3Touch = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable3Touch,	//75,
					.sFirstTouchEnable4Touch = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable4Touch,	//70,
					.sFirstTouchEnable5Touch = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable5Touch,	//60,
					.ucDebCntInner			 = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucDebCntInner,	//0,
					.ucDebCntEdge			 = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucDebCntEdge,	//1,
					.usFirstDrawingThd		 = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_usFirstDrawingThd,	//128,
					.ucFirstDrawingCellCnt   = 				PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFirstDrawingCellCnt,	
					.bSwapXY				 =				PARAMSET_NORMAL_MODE_1_ALGO_Coord_bSwapXY,
					.bFlipX					 =				PARAMSET_NORMAL_MODE_1_ALGO_Coord_bFlipX,
					.bDoNotExpandPos		 =				PARAMSET_NORMAL_MODE_1_ALGO_Coord_bDoNotExpandPos,
					.ucMultiTouchPendPosDebCnt = 			PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMultiTouchPendPosDebCnt,
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
					.ucLeftEdgeExpand_local = 				PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucLeftEdgeExpand_local,
					.ucRightEdgeExpand_local = 				PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucRightEdgeExpand_local,
					.ucTopEdgeExpand_local = 				PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucTopEdgeExpand_local,
					.ucBottomEdgeExpand_local = 			PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucBottomEdgeExpand_local,
					.uclatency_up_dis_condition			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_uclatency_up_dis_condition,  // off : 0
					.uclatency_up_cnt_condition			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_uclatency_up_cnt_condition,  // range : 0 ~ 255
					.clatency_up_dis_offset				=	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_clatency_up_dis_offset,
					.ucideal_inter_dis					= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ideal_inter_dis,	// range : 0 ~ 255
					.ucideal_inter_mv					= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ideal_inter_mv,	// range : 0 ~ 255
					.uc_connect_count					= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_uc_connect_count,
					.ucMarkBoundaryNum					= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucMarkBoundaryNum,
                    .ucPenEdgeDebCnt                    =   PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPenEdgeDebCnt,
					.usLongDisPointExceptionTH			= 	PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usLongDisPointExceptionTH,
				},
				.PenTilt =
				{
					.cHoverOverShiftRingOffset			=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cHoverOverShiftRingOffset,
					.bRingRangeExtend_On = 					PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bRingRangeExtend_On,
					.ucRingCompenCoefA =					PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingCompenCoefA,
					.ucRingCompenCoefB =					PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingCompenCoefB,
					.ucCoordiShiftX_WithTilt  =    			PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftX_WithTilt,		// 0 : Shift Off
					.ucCoordiShiftY_WithTilt  =    			PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftY_WithTilt,	
					.ucCoordiShiftEdgeOn		= 			PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftEdgeOn,  	// 0 : Edge Off , 1 : Center Same Coef , 2 : Coef Up
					.ucCoordiShiftWithTilt_RingTH		=   PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftWithTilt_RingTH,
					.ucCoordiShiftWithTiltCompenTH		= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftWithTiltCompenTH,
					.ucTiltL					= 			PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTiltL,
					.ucTiltSmoothingFilterCoef		= 		PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTiltSmoothingFilterCoef, //Max : 32
					.ucHalfCoefSmoothFrm				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucHalfCoefSmoothFrm,
					.ucHalfCoef							= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucHalfCoef,
					.ucHighDelta_TiltSmooth_change_Th	= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucHighDelta_TiltSmooth_change_Th,
					.cHighDelta_TiltSmooth_change_offset=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cHighDelta_TiltSmooth_change_offset,
					.usTilt_Change_TH_Reverse			=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTilt_Change_TH_Reverse,
					.usTilt_Change_TH_Right				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTilt_Change_TH_Right,
					.ucRingMarkBoundaryNum				= 	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingMarkBoundaryNum,
					.ucTiltDeltaLimitFilter				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTiltDeltaLimitFilter,
					.usTiltDeltaLimit_10_TH				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_10_TH,
					.usTiltDeltaLimit_55_TH				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_55_TH,
					.usTiltDeltaLimit_65_TH				=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_65_TH,
#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT)
					.ucRingDirecPosCoef					=   15,
					.ucRingTipDeltaSumCoef				= 	6,
					.ucRingTipDeltaSumTH				= 	200,
					.bTiltMedianFilter					=	1,
#elif (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
	#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
					.ucRingDirecPosCoef					=   8,//15,
	#else
					.ucRingDirecPosCoef					=   0,//10,//15,
	#endif
					.ucRingTipDeltaSumCoef				= 	0,//3,
					.ucRingTipDeltaSumTH				= 	0,//130,
					.bTiltMedianFilter					=	0,//1,	
					.bTiltDirecLimitFilter				=	0,		
					.b2MUX_SUM_RingMode					=	1,	
					.ucTipDirecShiftBasedRingDelta		=	0,//5,		
					.bRingBaseTracking					=	1,		
#endif				
					.bArcSinLookUp_1					=	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bArcSinLookUp_1,
				},
				.PenData =
				{
					.ucPenDataLocalTHD = 					PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataLocalTHD,
					.ucPenDataHoverTHD = 					PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataHoverTHD,
					.usPenDataHighHoverButtonRejectTHD = 	PARAMSET_NORMAL_MODE_1_ALGO_PenData_usPenDataHighHoverButtonRejectTHD,
					.ucForcePenContact_NUM = 				PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucForcePenContact_NUM,
					.ucAbnormalContactRemoveDeltaTH1 = 		PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemoveDeltaTH1,
					.ucAbnormalContactRemoveDeltaTH2 = 	    PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemoveDeltaTH2,
					.ucAbnormalContactRemovePressureTH1 =   PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemovePressureTH1,
					.ucAbnormalContactRemovePressureTH2 =   PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemovePressureTH2,	
					.ucSEN_CONT_CNT						=	PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucSEN_CONT_CNT,
					.ucKeepProtocolNum =					PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucKeepProtocolNum,
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
				},
				.Palm =
				{
					.ucPalmDetectionOn = 					PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmDetectionOn,		//0 : off, 1 : Version 1, 2 : Version 2, 3 : 1, 2 Adpative
					.usPalmLevel = 							PARAMSET_NORMAL_MODE_1_ALGO_Palm_usPalmLevel,//20,//12,
					.ucPalm_PALM_CONNECT_DIST = 			PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_PALM_CONNECT_DIST, 
					.ucPalm_PALM_REGION_UPDATE_PERIOD =		PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_PALM_REGION_UPDATE_PERIOD,
					.ucPalm_TOUCHDOWNFRAMEMAX = 			PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_TOUCHDOWNFRAMEMAX,
					.ucPalm_TOUCHDOWNSLOPETHRESHOLD = 		PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_TOUCHDOWNSLOPETHRESHOLD,
					.ucPalm_IGNOREFRAMENUM = 				PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_IGNOREFRAMENUM,
					.ucPalm_KEEPPALMREGIONFRAME = 			PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_KEEPPALMREGIONFRAME,
					.ucPalmDrawingOn = 						PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmDrawingOn,
					.bPalm_WholeTouchRemove = 				PARAMSET_NORMAL_MODE_1_ALGO_Palm_bPalm_WholeTouchRemove,
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
		}, /* PARAM_MODE_NORMAL_1 */
	}
};
