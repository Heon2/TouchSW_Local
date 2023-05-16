/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : param_configset_algorithm_mode_wgp.h
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

#ifndef _PARAM_CONFIGSET_ALGORITHM_MODE_WGP_H_
#define _PARAM_CONFIGSET_ALGORITHM_MODE_WGP_H_


#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_cNormalizeDelta					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_ucDiscardFrameNum					(7)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_ucInitialFrameNum					(7)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_usIIRCoef							(90)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sBlockPosThd						(10)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sBlockNegThd						(-24)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sAccumPosSumThd					(10)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sAccumNegSumThd					(-10)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_BlockPosThd					(15)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_BlockNegThd					(-20)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_SeedThd						(30)//(40)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_PosTotalSumThd				(120)//(160)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sIdle_NegTotalSumThd				(-120)//(-160)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_BlockPosThd				(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_BlockNegThd				(-80)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_PosTotalSumThd			(150)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sLocalIdle_NegTotalSumThd			(-150)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sS3_BlockPosThd					(60)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sS3_BlockNegThd					(-60)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sS3_PosTotalSumThd					(300)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sS3_NegTotalSumThd					(-300)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_iRecalCond1_PosSum_Thd				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_iRecalCond1_AccSum_Thd				(-500)//(-1000)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_iRecalCond2_AccSum_Thd				(-100)//(-200)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_ucRecalCond1_WaitCnt				(2)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_ucRecalCond2_WaitCnt				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bFullModeReBaseCheckOff			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bLocalModeReBaseCheckOff			(0)
#define	PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_sFullLcoalChangeMinTh				(-30)
#define	PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_cFullLcoalChangeMinThOffset		(-10)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_usMS_ContactTh_LocalMode			(150)
#define	PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_usMS_ContactTh_HoverMode			(300)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_b2MUX_SUM_LocalSearchMode			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_b2MUX_SUM_LocalMode				(NO)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bPen_2BASE							(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_cFingerAreaPenDeltaDelete			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_cFingerAreaPenDeltaNoAcc			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bFingerBaseTracking				(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_ucPP_MUX_Select					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bDspA_Finger_CalculateDelta		(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bDspA_LocalMode_PenPhase			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bDspA_LocalMode_CalculateDelta		(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bDspA_SearchMode_PenPhase			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bDspA_SearchMode_CalculateDelta	(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_BaseLine_bFullFingerBaseTracking			(1)

#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_cLineFilter					(2)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterUpLimit			(100)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterLowLimit           (-100)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucLineFilterColOffset         (4)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucLineFilterRepeatTH          (0)//(20)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_cLineFilterMinTH				(-20)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucMinDeltaTh					(10)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_cLineFilter_Pen				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucLocalSearchModeLineFilter   (0)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_bRingRawLineFilter            (1)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterUpLimit_Pen		(10)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterLowLimit_Pen		(-10)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterUpLimit_Idle		(100)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sLineFilterLowLimit_Idle		(-100)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucRingDeltaIIR_Coef			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_sFingerAreaLineFilterLimit	(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_SensingFilter_ucFingerAreaLineFilterOffset	(0)

#define PARAMSET_NORMAL_MODE_1_ALGO_Label_usSeedBase							(20)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucSeedSlope							(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLabelNoiseThd						(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_bExpand								(YES)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_bSplitSearchDirc_4_On					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_usSmallNodeCnt						(16)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_usMediumNodeCnt						(42)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucMergeSmallThdPer					(70)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucMergeMediumThdPer					(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucMergeSmallDiagThdPer				(70)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucMergeMediumDiagThdPer				(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_usLocalSeedBase						(30)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalSeedSlope						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_usLocalSmallNodeCnt					(12)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_usLocalMediumNodeCnt					(32)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalMergeSmallThdPer				(85)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalMergeMediumThdPer				(70)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_usLocalSeedBase_Ring					(10)
#define	PARAMSET_NORMAL_MODE_1_ALGO_Label_ucRingSeedBase_Acoef					(20)
#define	PARAMSET_NORMAL_MODE_1_ALGO_Label_ucRingSeedBase_Fcoef					(250)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalPenDetectTH1					(40)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalPenDetectTH2					(120)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalPenDetectTH1_Offset			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucLocalPenDetectTH2_Offset			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucHoverInCheckFrm						(9)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucHoverOutCheckFrm					(10)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_ucHoverOutOffset						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_usLabelPeakValleyDiffTh				(10)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_usLabelPeakDiffTh						(40)
#define PARAMSET_NORMAL_MODE_1_ALGO_Label_usMergeLabelSizeTh					(30)

#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucDynamicTrackingDistanceMode			(0)//(2)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFastDrawingMode						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usMoveDistanceThd						(7)//(15)//(3)// For 15 : Display Frame Rate 20Hz
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usDistThdMovingToStationary			(32)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usDistThdStationaryToMoving			(64)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usFirstMoveDistanceThd				(7)//(10)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_lMoveSmoothingLevel					(8)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucVectorPredictionCoef				(0) // 50 ~ 150
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_lLargeTouchOnThd						(180)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLargeTouchOnDebCnt					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_lMediumTouchOnThd						(120)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMediumTouchOnDebCnt					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_lSmallTouchOnThd						(30)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchOnDebCnt					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_bEdgeDebCntUp							(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchOnMaxCellVal				(40)//(30)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_lTouchOffThd							(30)//(20)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMultifingerFirstTouchThDownOffset	(20)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usCenterMatchDistanceThd				(13)
#if USED_ONLY_LOCAL_MODE
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLocalFingerInterpolation_On			(1)
#else /* USED_ONLY_LOCAL_MODE */
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLocalFingerInterpolation_On			(0)
#endif /* USED_ONLY_LOCAL_MODE */
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFullFingerInterpolation_On			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sInterpolationWeight					(128)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_bExpectClipping_Finger_On				(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_cEdgeSmoothing_Finger_On				(32)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFirstMoveEventTHD					(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMoveEventTHD						(20)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiXResolutionOffset	(64)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiYResolutionOffset	(128)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetX			(-32)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFingerGlobalCoordiOffsetY			(-64)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_bUseMultiEdgeCoef						(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usSmallTouchMaxDeltaThd				(100)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchCellCntThd				(15)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchHeightThd					(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmallTouchWidthThd					(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLeftEdgeExpand						(100)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRightEdgeExpand						(100)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTopEdgeExpand						(110)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucBottomEdgeExpand					(115)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLeftEdgeExpand_small				(70)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRightEdgeExpand_small				(70)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTopEdgeExpand_small					(68)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucBottomEdgeExpand_small				(72)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucLeftEdgeExpand_medium				(75)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRightEdgeExpand_medium				(75)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTopEdgeExpand_medium				(70)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucBottomEdgeExpand_medium				(75)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sXExpandStartOffset					(256)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sYExpandStartOffset					(256)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_bRemoveEdge							(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRemoveEdgeXdistThd					(50)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRemoveEdgeYdistThd					(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_bUsetRealPastSentPos1					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucRemoveEdgeVer						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLabelEdgeExpandMode					(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLeftEdgeExpand_Offset				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRightEdgeExpand_Offset              (0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usTopEdgeExpand_Offset                (0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBottomEdgeExpand_Offset             (0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLeftEdgeExpand_Scale                (128)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRightEdgeExpand_Scale               (128)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usTopEdgeExpand_Scale                 (128)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBottomEdgeExpand_Scale              (128)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usLeftEdgeExpand_MaxD					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usRightEdgeExpand_MaxD				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usTopEdgeExpand_MaxD					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBottomEdgeExpand_MaxD				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam1			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam2			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeExpandParam3			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucEdgeReportDelayCnt					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTest_MoveEventTHD_X	(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTest_MoveEventTHD_Y	(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingTop		(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingBottom		(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingLeft		(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usBigFingerEdgeTestClippingRight		(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_bFingerCornerTestClippingOn			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usPostProcessEdgeTH					(UNIT_DIST << 1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucPostProcessDisTH					(UNIT_DIST >> 3)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucPostProcessExpendDiv				(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_cPostProcessEndMargin					(50)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_bPostProcessInterpolationMode			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usOutInDrawEdgeTh						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucOutInDrawDisTh						(64)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucSmoothPastOrgInter					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_cDisSmoothOffset						(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_bFingerMeanSmoothing					(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucWinCertAssistance 					(0)		//0 : Off, 1 : LGD MNT 27", 2 : LGD Kiosk
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucTouchCountMax						(3)		//LGD MNT 27" : 3, LGD Kiosk 43",55" : 30
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucMaxExtendFrameNum					(10)	//LGD MNT 27" : 10, LGD Kiosk 43", 55" : 100
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable1Touch				(0)		//Enable First touch
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable2Touch				(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable3Touch				(75)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable4Touch				(70)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_sFirstTouchEnable5Touch				(60)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucDebCntInner							(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucDebCntEdge			 				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_usFirstDrawingThd		 				(128)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_ucFirstDrawingCellCnt					(10)
#define PARAMSET_NORMAL_MODE_1_ALGO_Coord_bUseNewCippingCond					(1)

#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucTipRangeExtend_On				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bExpectClipping_Pen_On				(YES)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucCompenCoefA						(4)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucCompenCoefB						(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucHoverCompenCoefA					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucHoverCompenCoefB					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bCompenEdgeOn						(NO)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPenPostProcessEdgeTH				(9)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPenPostProcessDisTH				(20)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPenPostProcessExpendDiv			(2)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_cPenPostProcessEndMargin			(50)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_cHoverSmoothOffset					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bFullFingerOn						(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sPenGlobalCoordiXResolutionOffset	(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sPenGlobalCoordiYResolutionOffset	(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sPenGlobalCoordiOffsetX			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sPenGlobalCoordiOffsetY			(-10)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucLeftEdgeExpand_local				(64+20)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucRightEdgeExpand_local			(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucTopEdgeExpand_local				(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucBottomEdgeExpand_local			(64+10)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_uclatency_up_dis_condition			(120)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_uclatency_up_cnt_condition			(10)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_clatency_up_dis_offset				(30)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ideal_inter_dis					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ideal_inter_mv						(2)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_uc_connect_count					(5)//(15)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucMarkBoundaryNum					(2)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPenEdgeDebCnt                    (0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usLongDisPointExceptionTH			(2048)//(1024)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usPannelOutSideHoverExceptionTH	(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usPannelOutSideContactExceptionTH	(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPannelOutSideHoverExceptionEdgeDis	(64)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPannelOutSideContactExceptionEdgeDis	(64)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucPannelOutSideContactExceptionPreDis	(10)
#if (OUT_IN_DRAWING == YES)
	#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usOutInBoundTh	(1024)
	#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucOutInDisTh	(16)
#endif
#if (HIGH_HOVER_JITTER_REDUCE == YES)
	#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_sHighHoverJitterReduceDisScale			(200)
	#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_ucHighHoverJitterReduceSmoothOffset	(100)
#endif
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bUseNewCippingCond_Pen				(0)		// If you use Remove Edge, bUseNewCippingCond_Pen = 1
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bRemoveEdge						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usRemoveEdgeXdistThd				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usRemoveEdgeYdistThd				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_bUsetRealPastSentPos1				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenCoord_usEndCoordMargin					(0)

//#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucMS_RingMode						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltCalOnlyContact					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cHoverOverShiftRingOffset			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucHoverDeltaMul						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bRingRangeExtend_On					(YES)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingCompenCoefA					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingCompenCoefB                   (0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltCalUsingTipOrg					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftX_WithTilt				(10)//(7)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftY_WithTilt	            (10)//(9)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftEdgeOn                 (2)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftWithTilt_RingTH        (17)//(20)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucCoordiShiftWithTiltCompenTH       (250)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTiltL                             (84)//(82)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltChangeLimitFilter				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTiltSmoothingFilterCoef           (30)
#define	PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucHalfCoefSmoothFrm					(3)//(10)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucHalfCoef							(1)//(16)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucHighDelta_TiltSmooth_change_Th	(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cHighDelta_TiltSmooth_change_offset	(-4)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTilt_Change_TH_Reverse			(300)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTilt_Change_TH_Right				(120)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bRingCoordiReport					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingMarkBoundaryNum				(0)//(2)	
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltBasedRingDelta					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltDirecLimitFilter				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTiltDeltaLimitFilter				(0)//(170)//(180)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_10_TH				(0)//(200)//(170)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_55_TH				(650)//(500)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_60_TH				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usTiltDeltaLimit_65_TH				(900)//(800)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltMedianFilter					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bRingBaseTracking					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bTiltRowIndexChange					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingDirecPosCoef					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingTipDeltaSumCoef				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucRingTipDeltaSumTH					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_b2MUX_SUM_RingMode					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_ucTipDirecShiftBasedRingDelta		(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_bArcSinLookUp_1						(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usReleaseLastContact3x3Frm			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_usUseLastContact3x3Th				(0)
#if (CORNER_CoordiShift_WithTilt_ADD == YES)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_LT	(-2)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_LT	(-2)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_RT	(-2)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_RT	(-2)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_LB	(-3)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_LB	(-1)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftX_WithTilt_Corner_RB	(-2)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenTilt_cCoordiShiftY_WithTilt_Corner_RB	(-2)
#endif

#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAdaptive_contact_th				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataLocalTHD					(150)//(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataHoverTHD					(150)//(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_sPenDataHoverButtonTHD				(150)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_usPenDataHighHoverButtonRejectTHD	(180)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataHighHoverButton1ReliableCnt (0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataHighHoverButton2ReliableCnt (0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataHighHoverButtonAdopThOffset (0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucPenDataHighHoverButtonIIRcoef		(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucForcePenContact_NUM				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemoveDeltaTH1		(0)//(17)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemoveDeltaTH2		(0)//(30)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemovePressureTH1	(0)//(35)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucAbnormalContactRemovePressureTH2	(0)//(70)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucSEN_CONT_CNT						(10)//(20)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ucKeepProtocolNum					(16)
#if USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL
	#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ulPressureLevelIIRPrevCoefTHD		(8) // 1~15 Set
	#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_ulPressureChangeRatioTHD			(55) // 0~100 Max 100
	#define PARAMSET_NORMAL_MODE_1_ALGO_PenData_bUsedBrushFinishTip					(YES)
#endif /* USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL */

#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_th						(-100)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_mul						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_SR						(3)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_th						(-100)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_mul					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_SR						(3)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_th						(-100)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_mul						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_SR						(3)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_th						(-100)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_mul						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_SR						(3)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_hover_th					(550)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_hover_mul					(33)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_hover_SR					(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_hover_th				(550)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_hover_mul				(33)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_hover_SR				(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_hover_th					(550)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_hover_mul				(33)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_hover_SR					(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_hover_th				(550)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_hover_mul				(33)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_hover_SR				(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_ring_th					(500)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_ring_mul					(4)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_top_ring_SR					(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_ring_th				(500)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_ring_mul				(4)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_bottom_ring_SR				(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_ring_th					(500)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_ring_mul					(4)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_left_ring_SR					(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_ring_th					(500)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_ring_mul				(4)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_right_ring_SR					(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_EdgePenSetVal_chover_mul_button1_offset		(0)

#define PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_c_edge_smooth_offset_hover				(127)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_c_edge_smooth_offset_contact  			(32)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_dis_condition_contact	(32)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_c_global_smooth_offset_contact			(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_us_corner_smooth_delta_condition_hover	(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_c_corner_smooth_offset_hover				(127)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_uc_edge_smooth_dis_condition_contact		(128)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_delta_condition_hover	(200)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_uc_global_smooth_dis_condition_hover		(255)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_c_global_smooth_offset_hover				(-32)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenDisBaseSmoothSetVal_usEdge_Range								(256)

#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_th0						(6)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_mul0					(28)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_SR0					(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_mul1					(12)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_SR1					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_mul0				(26)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_SR0				(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_mul1				(15)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_SR1				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_mul0					(27)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_SR0					(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_mul1					(12)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_SR1					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_mul0				(30)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_SR0					(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_mul1				(12)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_SR1					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_max_sum				(370)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_max_sum			(400)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_max_sum				(350)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_max_sum				(400)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_max_sum_corner		(140)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_max_sum_corner		(150)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_max_sum_corner		(140)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_max_sum_corner		(180)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_max_sum_hover			(2000)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_max_sum_hover		(2000)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_max_sum_hover		(1800)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_max_sum_hover		(1800)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_max_sum_hover_div			(4)
#if (PEN_CORNER_EXPEND_ADD == YES)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_top_max_sum_corner1		(80)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_bottom_max_sum_corner1    (80)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_left_max_sum_corner1      (140)
#define PARAMSET_NORMAL_MODE_1_ALGO_PenParaEdgeSetVal_right_max_sum_corner1     (140)
#endif

#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucNoiseDetectionMode					(2)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucDiscardFrameNum						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucCellCntThd							(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucHoppingThd							(50)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucNoiseThd							(7)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_usRawDataThd							(100)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_sDeltaDataThd							(-20)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucTouchOffCntThd						(20)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_bPenNoiseReductionOff					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucPenFingerSameLineNoiseSize			(3)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucHoverNoiseRejectTH					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucHoverNoiseRejectFrm					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucSearchNoiseRejectTH					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucSearchNoiseRejectFrm				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_cAdaptorNoiseTH						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucAdaptorNoiseContiNum				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_cAdaptorNoiseTH_SearchHover			(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucAdaptorNoiseContiNum_SearchHover	(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_bPenPosSymbolRepeatCheck				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucCPITestOn							(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucErrorFrameProcess					(0)
#define	PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucHoppingMoveDistanceThd				(4)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucNoiseDetectMaxType					(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_bInitAddHoppingThd					(1)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_bHoppingConnectPenContact				(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucNoiseStartThd						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Noise_ucNoiseStartCntThd					(0)

#define PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmDetectionOn						(2)
#define PARAMSET_NORMAL_MODE_1_ALGO_Palm_usPalmLevel							(55)//(33)
#define PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_PALM_CONNECT_DIST				(5)
#define PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_PALM_REGION_UPDATE_PERIOD		(10)
#define PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_TOUCHDOWNFRAMEMAX				(2)
#define PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_TOUCHDOWNSLOPETHRESHOLD			(50)
#define PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_IGNOREFRAMENUM					(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalm_KEEPPALMREGIONFRAME				(50)
#define PARAMSET_NORMAL_MODE_1_ALGO_Palm_ucPalmDrawingOn						(0)
#define PARAMSET_NORMAL_MODE_1_ALGO_Palm_bPalm_WholeTouchRemove					(NO)

#define PARAMSET_NORMAL_MODE_1_ALGO_ucOvrShift									(3)
#define PARAMSET_NORMAL_MODE_1_ALGO_ucIdleOvrShift								(3)
#define PARAMSET_NORMAL_MODE_1_ALGO_ucLocalOvrShift								(3)
#define PARAMSET_NORMAL_MODE_1_ALGO_ucLocalIdleOvrShift							(2)
#define PARAMSET_NORMAL_MODE_1_ALGO_ucLocalOvrShift_Ring						(2)


#endif /* _PARAM_CONFIGSET_ALGORITHM_MODE_WGP_H_ */
