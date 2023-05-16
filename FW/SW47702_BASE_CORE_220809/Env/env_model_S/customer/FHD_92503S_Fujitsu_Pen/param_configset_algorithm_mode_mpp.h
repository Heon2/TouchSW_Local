/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : param_configset_algorithm_mode_mpp.h
 * created on : 29. 12. 2020
 * Author : mhjang
 *
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright
 *	 notice, this list of conditions and the following disclaimer.
 *	 - Redistributions in binary form must reproduce the above copyright
 *	 notice, this list of conditions and the following disclaimer in the
 *	 documentation and/or other materials provided with the distribution.
 * - Neither the name of SiW nor the names of its contributors may be used
 *	 to endorse or promote products derived from this software without
 *	 specific prior written permission.
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

#ifndef _PARAM_CONFIGSET_ALGORITHM_MODE_MPP_H_
#define _PARAM_CONFIGSET_ALGORITHM_MODE_MPP_H_


#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_cNormalizeDelta						(0)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucDiscardFrameNum					(7)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucInitialFrameNum					(7)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_usIIRCoef							(90)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sBlockPosThd							(50)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sBlockNegThd							(-50)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sAccumPosSumThd						(10)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sAccumNegSumThd						(-10)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_BlockPosThd					(60)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_BlockNegThd					(-60)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_SeedThd						(80)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_PosTotalSumThd					(200)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sIdle_NegTotalSumThd					(-200)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_BlockPosThd				(80)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_BlockNegThd				(-80)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_PosTotalSumThd			(150)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sLocalIdle_NegTotalSumThd			(-150)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sS3_BlockPosThd						(60)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sS3_BlockNegThd						(-60)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sS3_PosTotalSumThd					(300)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_sS3_NegTotalSumThd					(-300)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_iRecalCond1_PosSum_Thd				(0)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_iRecalCond1_AccSum_Thd				(-1000)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_iRecalCond2_AccSum_Thd				(-200)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucRecalCond1_WaitCnt					(2)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucRecalCond2_WaitCnt					(0)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_bFullModeReBaseCheckOff				(0)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_bLocalModeReBaseCheckOff				(0)
#define	PARAMSET_NORMAL_MODE_ALGO_BaseLine_sFullLcoalChangeMinTh				(-30)
#define	PARAMSET_NORMAL_MODE_ALGO_BaseLine_cFullLcoalChangeMinThOffset			(-10)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_usMS_ContactTh_LocalMode				(150)
#define	PARAMSET_NORMAL_MODE_ALGO_BaseLine_usMS_ContactTh_HoverMode				(200)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_b2MUX_SUM_LocalSearchMode			(0)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_b2MUX_SUM_LocalMode					(NO)
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_bPen_2BASE							(1)
#else
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_bPen_2BASE							(0)
#endif
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_cFingerAreaPenDeltaDelete			(1)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_cFingerAreaPenDeltaNoAcc				(0)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_bFingerBaseTracking					(1)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_ucPP_MUX_Select						(1)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_bDspA_Finger_CalculateDelta			(1)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_bDspA_LocalMode_PenPhase				(0)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_bDspA_LocalMode_CalculateDelta		(0)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_bDspA_SearchMode_PenPhase			(0)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_bDspA_SearchMode_CalculateDelta		(0)
#define PARAMSET_NORMAL_MODE_ALGO_BaseLine_bFullFingerBaseTracking				(1)

#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_cLineFilter						(1)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterUpLimit              (100)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterLowLimit             (-100)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucLineFilterColOffset           (4)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucLineFilterRepeatTH			(0)//(20)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_cLineFilterMinTH				(-20)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucMinDeltaTh					(0)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_cLineFilter_Pen					(1)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucLocalSearchModeLineFilter		(1)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_bRingRawLineFilter	            (0)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterUpLimit_Pen			(10)	
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterLowLimit_Pen			(-10)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterUpLimit_Idle			(100)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sLineFilterLowLimit_Idle		(-100)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucRingDeltaIIR_Coef				(60) 
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_sFingerAreaLineFilterLimit		(0)
#define PARAMSET_NORMAL_MODE_ALGO_SensingFilter_ucFingerAreaLineFilterOffset	(0)

#define PARAMSET_NORMAL_MODE_ALGO_Label_usSeedBase								(20)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucSeedSlope								(5)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucLabelNoiseThd							(10)
#define PARAMSET_NORMAL_MODE_ALGO_Label_bExpand									(YES)
#define PARAMSET_NORMAL_MODE_ALGO_Label_bSplitSearchDirc_4_On					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Label_usSmallNodeCnt							(16)
#define PARAMSET_NORMAL_MODE_ALGO_Label_usMediumNodeCnt							(42)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucMergeSmallThdPer						(70)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucMergeMediumThdPer						(60)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucMergeSmallDiagThdPer					(70)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucMergeMediumDiagThdPer					(80)
#define PARAMSET_NORMAL_MODE_ALGO_Label_usLocalSeedBase							(15)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalSeedSlope						(0)
#define PARAMSET_NORMAL_MODE_ALGO_Label_usLocalSmallNodeCnt						(12)
#define PARAMSET_NORMAL_MODE_ALGO_Label_usLocalMediumNodeCnt					(32)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalMergeSmallThdPer					(85)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalMergeMediumThdPer				(70)
#define PARAMSET_NORMAL_MODE_ALGO_Label_usLocalSeedBase_Ring					(10)
#define	PARAMSET_NORMAL_MODE_ALGO_Label_ucRingSeedBase_Acoef					(0)
#define	PARAMSET_NORMAL_MODE_ALGO_Label_ucRingSeedBase_Fcoef					(120)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalPenDetectTH1						(40)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucLocalPenDetectTH2						(120)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucHoverInCheckFrm						(6)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucHoverOutCheckFrm						(6)
#define PARAMSET_NORMAL_MODE_ALGO_Label_ucHoverOutOffset						(0)
#define PARAMSET_NORMAL_MODE_ALGO_Label_usLabelPeakValleyDiffTh					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Label_usLabelPeakDiffTh						(0)
#define PARAMSET_NORMAL_MODE_ALGO_Label_usMergeLabelSizeTh						(0)

#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucDynamicTrackingDistanceMode			(2)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucFastDrawingMode						(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usMoveDistanceThd						(6)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usDistThdMovingToStationary				(32)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usDistThdStationaryToMoving				(64)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usFirstMoveDistanceThd					(10)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_lMoveSmoothingLevel						(8)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_lLargeTouchOnThd						(180)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucLargeTouchOnDebCnt					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_lMediumTouchOnThd						(120)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucMediumTouchOnDebCnt					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_lSmallTouchOnThd						(30)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmallTouchOnDebCnt					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_bEdgeDebCntUp							(1)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchOnMaxCellVal					(40)//(50)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_lTouchOffThd							(30)//(40)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucMultifingerFirstTouchThDownOffset		(10)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usCenterMatchDistanceThd				(13)
#if USED_ONLY_LOCAL_MODE
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucLocalFingerInterpolation_On			(1)
#else /* USED_ONLY_LOCAL_MODE */
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucLocalFingerInterpolation_On			(1)//(0)
#endif /* USED_ONLY_LOCAL_MODE */
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucFullFingerInterpolation_On			(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sInterpolationWeight					(128)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_bExpectClipping_Finger_On				(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_cEdgeSmoothing_Finger_On				(32)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucFirstMoveEventTHD						(5)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucMoveEventTHD							(20)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiXResolutionOffset	(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset	(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiOffsetX				(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sFingerGlobalCoordiOffsetY				(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_bUseMultiEdgeCoef						(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usSmallTouchMaxDeltaThd					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmallTouchCellCntThd					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmallTouchHeightThd					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmallTouchWidthThd					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucLeftEdgeExpand						(64 + 21)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucRightEdgeExpand						(64 + 21)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucTopEdgeExpand							(64 + 36)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucBottomEdgeExpand						(64 + 32)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucLeftEdgeExpand_small					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucRightEdgeExpand_small					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucTopEdgeExpand_small					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucBottomEdgeExpand_small				(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucLeftEdgeExpand_medium					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucRightEdgeExpand_medium				(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucTopEdgeExpand_medium					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucBottomEdgeExpand_medium				(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sXExpandStartOffset						(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sYExpandStartOffset						(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_bRemoveEdge								(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usRemoveEdgeXdistThd					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usRemoveEdgeYdistThd					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usLabelEdgeExpandMode					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usLeftEdgeExpand_Offset					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usRightEdgeExpand_Offset				(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usTopEdgeExpand_Offset					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usBottomEdgeExpand_Offset				(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usLeftEdgeExpand_Scale					(128)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usRightEdgeExpand_Scale					(128)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usTopEdgeExpand_Scale					(128)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usBottomEdgeExpand_Scale				(128)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usLeftEdgeExpand_MaxD					(600)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usRightEdgeExpand_MaxD					(600)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usTopEdgeExpand_MaxD					(600)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usBottomEdgeExpand_MaxD					(600)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeExpandParam1				(9000)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeExpandParam2				(70)//(80)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usBigFingerEdgeExpandParam3				(2000)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usPostProcessEdgeTH						(UNIT_DIST << 1)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucPostProcessDisTH						(UNIT_DIST >> 3)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucPostProcessExpendDiv					(1)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_cPostProcessEndMargin					(50)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_bPostProcessInterpolationMode			(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usOutInDrawEdgeTh						(256)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucOutInDrawDisTh						(64)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucSmoothPastOrgInter					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_cDisSmoothOffset						(-32)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_bFingerMeanSmoothing					(1)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_bUseNewCippingCond						(1)

#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucWinCertAssistance 					(0)		//0 : Off, 1 : LGD MNT 27", 2 : LGD Kiosk
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucTouchCountMax							(3)		//LGD MNT 27" : 3, LGD Kiosk 43",55" : 30
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucMaxExtendFrameNum						(10)	//LGD MNT 27" : 10, LGD Kiosk 43", 55" : 100
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable1Touch					(0)	    //Enable First touch
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable2Touch					(40)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable3Touch					(35)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable4Touch					(35)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_sFirstTouchEnable5Touch					(35)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucDebCntInner							(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucDebCntEdge			 				(0)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_usFirstDrawingThd		 				(128)
#define PARAMSET_NORMAL_MODE_ALGO_Coord_ucFirstDrawingCellCnt					(0)

#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucTipRangeExtend_On					(1)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_bExpectClipping_Pen_On				(YES)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucCompenCoefA						(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucCompenCoefB						(5)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucHoverCompenCoefA					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucHoverCompenCoefB					(5)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_bCompenEdgeOn						(NO)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenPostProcessEdgeTH				(9)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenPostProcessDisTH				(32)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenPostProcessExpendDiv			(1)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_cPenPostProcessEndMargin				(50)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_cHoverSmoothOffset					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_bFullFingerOn						(1)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiXResolutionOffset	(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiYResolutionOffset	(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiOffsetX				(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_sPenGlobalCoordiOffsetY				(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucLeftEdgeExpand_local				(90)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucRightEdgeExpand_local				(90)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucTopEdgeExpand_local				(72)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucBottomEdgeExpand_local				(72)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_uclatency_up_dis_condition			(0)//(120)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_uclatency_up_cnt_condition			(10)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_clatency_up_dis_offset				(30)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ideal_inter_dis						(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ideal_inter_mv						(2)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_uc_connect_count						(4)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucMarkBoundaryNum					(2)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_ucPenEdgeDebCnt                      (0)
#define PARAMSET_NORMAL_MODE_ALGO_PenCoord_usLongDisPointExceptionTH			(1024)

#define	PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucMS_RingMode							(2)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltCalOnlyContact					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_cHoverOverShiftRingOffset				(-1)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHoverDeltaMul						(0)//(20)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltCalUsingTipOrg					(1)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_bRingRangeExtend_On					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucRingCompenCoefA						(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucRingCompenCoefB                     (0)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftX_WithTilt				(8)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftY_WithTilt	            (8)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftEdgeOn                   (1)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftWithTilt_RingTH          (0)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucCoordiShiftWithTiltCompenTH         (200)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucTiltL                               (65)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTiltChangeLimitFilter               (0)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucTiltSmoothingFilterCoef             (31)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHalfCoefSmoothFrm					(3)//(2)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHalfCoef							(1)//(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucHighDelta_TiltSmooth_change_Th		(120)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_cHighDelta_TiltSmooth_change_offset	(-7)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTilt_Change_TH_Reverse				(500)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_usTilt_Change_TH_Right				(120)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucRingMarkBoundaryNum					(0)	
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltBasedRingDelta					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltDirecLimitFilter					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_ucTiltDeltaLimitFilter				(2)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltMedianFilter						(1)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_bRingBaseTracking						(1)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_bTiltRowIndexChange					(1)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_usReleaseLastContact3x3Frm			(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_usUseLastContact3x3Th					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenTilt_bArcSinLookUp_1						(1)

#define PARAMSET_NORMAL_MODE_ALGO_PenData_ucPenDataLocalTHD						(70)
#define PARAMSET_NORMAL_MODE_ALGO_PenData_ucPenDataHoverTHD						(80)
#define PARAMSET_NORMAL_MODE_ALGO_PenData_usPenDataHighHoverButtonRejectTHD		(700)
#define PARAMSET_NORMAL_MODE_ALGO_PenData_ucForcePenContact_NUM					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenData_ucSEN_CONT_CNT						(20)
#define PARAMSET_NORMAL_MODE_ALGO_PenData_ucKeepProtocolNum						(16)

#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_th							(-100)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_mul							(0)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_SR							(3)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_th						(-100)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_mul						(0)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_SR						(3)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_th							(-100)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_mul						(0)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_SR							(3)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_th						(-100)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_mul						(0)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_SR						(3)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_hover_th					(550)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_hover_mul					(31)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_hover_SR					(5)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_hover_th					(550)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_hover_mul				(31)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_hover_SR					(5)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_hover_th					(550)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_hover_mul					(33)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_hover_SR					(5)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_hover_th					(550)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_hover_mul					(32)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_hover_SR					(5)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_ring_th						(500)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_ring_mul					(2)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_top_ring_SR						(1)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_ring_th					(500)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_ring_mul					(3)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_bottom_ring_SR					(1)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_ring_th					(550)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_ring_mul					(2)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_left_ring_SR					(1)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_ring_th					(500)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_ring_mul					(2)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_right_ring_SR					(1)
#define PARAMSET_NORMAL_MODE_ALGO_EdgePenSetVal_chover_mul_button1_offset		(4)
 
#define PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_edge_smooth_offset_hover					(127)
#define PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_edge_smooth_offset_contact  				(16)
#define PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_dis_condition_contact		(32)
#define PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_global_smooth_offset_contact				(64)
#define PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_us_corner_smooth_delta_condition_hover		(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_corner_smooth_offset_hover				(127)
#define PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_edge_smooth_dis_condition_contact		(64)
#define PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_delta_condition_hover		(150)
#define PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_dis_condition_hover		(128)
#define PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_c_global_smooth_offset_hover				(-16)
#define PARAMSET_NORMAL_MODE_ALGO_PenDisBaseSmoothSetVal_usEdge_Range								(256)		

#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_th0							(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_mul0					(127)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_SR0						(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_mul1					(9)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_SR1						(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_mul0					(127)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_SR0					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_mul1					(9)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_SR1					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_mul0					(18)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_SR0					(5)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_mul1					(8)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_SR1					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_mul0					(18)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_SR0					(5)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_mul1					(8)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_SR1					(0)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_max_sum					(330)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_max_sum				(330)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_max_sum				(200)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_max_sum				(200)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_max_sum_corner			(210)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_max_sum_corner		(210)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_max_sum_corner			(115)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_max_sum_corner		(115)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_top_max_sum_hover			(2000)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_bottom_max_sum_hover		(2000)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_left_max_sum_hover			(1200)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_right_max_sum_hover			(1000)
#define PARAMSET_NORMAL_MODE_ALGO_PenParaEdgeSetVal_max_sum_hover_div			(4)

#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucNoiseDetectionMode					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucDiscardFrameNum						(5)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucCellCntThd							(1)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucHoppingThd							(17)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucNoiseThd								(7)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_usRawDataThd							(100)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_sDeltaDataThd							(-20)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucTouchOffCntThd						(10)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_bPenNoiseReductionOff					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucPenFingerSameLineNoiseSize			(5)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucHoverNoiseRejectTH					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucHoverNoiseRejectFrm					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucSearchNoiseRejectTH					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucSearchNoiseRejectFrm					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_cAdaptorNoiseTH							(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucAdaptorNoiseContiNum					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_cAdaptorNoiseTH_SearchHover				(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucAdaptorNoiseContiNum_SearchHover		(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_bPenPosSymbolRepeatCheck				(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucCPITestOn								(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucErrorFrameProcess						(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucNoiseStartThd							(0)
#define PARAMSET_NORMAL_MODE_ALGO_Noise_ucNoiseStartCntThd						(0)

#define PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalmDetectionOn						(2)
#define PARAMSET_NORMAL_MODE_ALGO_Palm_usPalmLevel								(25)
#define PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_PALM_CONNECT_DIST					(2)
#define PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_PALM_REGION_UPDATE_PERIOD			(10)
#define PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_TOUCHDOWNFRAMEMAX					(2)
#define PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_TOUCHDOWNSLOPETHRESHOLD			(50)
#define PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_IGNOREFRAMENUM					(0)
#define PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalm_KEEPPALMREGIONFRAME				(50)
#define PARAMSET_NORMAL_MODE_ALGO_Palm_ucPalmDrawingOn							(0)
#define PARAMSET_NORMAL_MODE_ALGO_Palm_bPalm_WholeTouchRemove					(NO)

#define PARAMSET_NORMAL_MODE_ALGO_ucOvrShift									(3)
#define PARAMSET_NORMAL_MODE_ALGO_ucIdleOvrShift								(2)
#define PARAMSET_NORMAL_MODE_ALGO_ucLocalOvrShift								(2)
#define PARAMSET_NORMAL_MODE_ALGO_ucLocalIdleOvrShift							(2)
#define PARAMSET_NORMAL_MODE_ALGO_ucLocalOvrShift_Ring							(0)


#endif /* _PARAM_CONFIGSET_ALGORITHM_MODE_MPP_H_ */
