/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : DSPA.c
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

#include "hal_def.h"


__IO static uint32_t g_ulDSPAIRQHandle;


void DSP_A_InterruptHandler(void)
{
	if(DSPA->ITRPT_CTRL.tBit.ItrptFlag)
	{
		g_ulDSPAIRQHandle = 1;
		DSPA->ITRPT_CTRL.tBit.ItrptFlag = 0x0; // Interrupt Clear
	}
}

void DSPA_Initialize(tDSPAOpHandleInfo_t * ptHandle)
{
	Fncp_DSP_A_IRQHandler = &DSP_A_InterruptHandler;

	NVIC_ClearPendingIRQ(DSP_A_IRQn);
	NVIC_SetPriority(DSP_A_IRQn, DSP_A_IRQn_Priority);
	NVIC_EnableIRQ(DSP_A_IRQn);

	DSPA->ITRPT_CTRL.tBit.ItrptEn = ENABLE;
	DSPA->SIZE_CTRL.tBit.RowNum = ptHandle->ulPanelRowNum;
	DSPA->SIZE_CTRL.tBit.ColNum = ptHandle->ulPanelColNum;
	DSPA->SIZE_CTRL.tBit.DataLen = ptHandle->ulPanelDataNumIncludePad;
	DSPA->RAW_ADDR = ptHandle->ulRawDataBufAddr;
	DSPA->BASE_ADDR = ptHandle->ulBaselineBufAddr;
	DSPA->NMLZ_ADDR = ptHandle->ulNomalizeBufAddr;
	DSPA->DEST_ADDR = ptHandle->ulIntensityBufAddr;
	DSPA->PAD_CTRL.tBit.PadEn = ptHandle->ulPadEn;
	DSPA->PAD_CTRL.tBit.PadSize = ptHandle->ulPadSize;
	DSPA->PAD_CTRL.tBit.PadData = ptHandle->ulPadData;
	DSPA->NMLZ_CTRL.tBit.NmlzEn = ptHandle->ulNormalizeEn;
	DSPA->NMLZ_CTRL.tBit.NmlzShift = ptHandle->ulNormalizeShiftLevel;
	DSPA->BIT_SHIFT.tBit.BitShift = ptHandle->ulIntensityBitShiftLevel;
	DSPA->UPR_LIMIT.tBit.UpperLimit = ptHandle->ulPositiveThreshold;
	DSPA->LWR_LIMIT.tBit.LowerLimit = (uint32_t)ptHandle->lNegativeThreshold;
	DSPA->THRESHOLD.tBit.Threshold = ptHandle->ulGroupThreshold;
}

void DSPA_Start(uint32_t bIsWaitIrq, tDSPAOutPutInfo_t * ptOutPutInfo)
{
	g_ulDSPAIRQHandle = 0;
	DSPA->HWACC_CTRL.tBit.Init = 1;
	DSPA->HWACC_CTRL.tBit.SwStr = 1;
	if(bIsWaitIrq)
	{
		DSPA_WaitForIrq(ptOutPutInfo);
	}
}

void DSPA_WaitForIrq(tDSPAOutPutInfo_t * ptOutPutInfo)
{
	while(g_ulDSPAIRQHandle == 0)
	{
		__WFI();
	}
	ptOutPutInfo->ulPositiveCellNum = DSPA->P_CELL_NUM.tBit.PlusCellNum; // +감도가 생성된 Cell개수
	ptOutPutInfo->ulPositiveCellTotalSum = DSPA->P_CELL_SUM; // +감도가 생성된 Cell의 Data합
	ptOutPutInfo->usPositiveMaxData = DSPA->P_MAX_VAL.tBit.PlusMaxVal; // +감도 중 Max값
	ptOutPutInfo->ulPositiveMaxData_RowIdx = DSPA->P_MAX_POS.tBit.PlusMaxRow; // +감도 중 Max값 Row위치
	ptOutPutInfo->ulPositiveMaxData_ColIdx = DSPA->P_MAX_POS.tBit.PlusMaxCol; // +감도 중 Max값 Column위치
	ptOutPutInfo->ulNegativeCellNum = DSPA->M_CELL_NUM.tBit.MinusCellNum; // -감도가 생성된 Cell개수
	ptOutPutInfo->lNegativeCellTotalSum = (int32_t)DSPA->M_CELL_SUM; // -감도가 생성된 Cell Data의 합
	ptOutPutInfo->sNegativeMaxData = DSPA->M_MAX_VAL.tBit.MinusMaxVal; // -감도 중 Max값
	ptOutPutInfo->ulNegativeMaxData_RowIdx = DSPA->M_MAX_POS.tBit.MinusMaxRow; // -감도 중 Max값 Row위치
	ptOutPutInfo->ulNegativeMaxData_ColIdx = DSPA->M_MAX_POS.tBit.MinusMaxCol; // -감도 중 Max값 Column위치
	ptOutPutInfo->ulTouchAreaCol_sIdx = DSPA->T_GROUP.tBit.TouchMinCol; // Touch감도가 생성된 Group의 Min Column위치
	ptOutPutInfo->ulTouchAreaCol_eIdx = DSPA->T_GROUP.tBit.TouchMaxCol; // Touch감도가 생성된 Group의 Max Column위치
	ptOutPutInfo->ulTouchAreaRow_sTdx = DSPA->T_GROUP.tBit.TouchMinRow; // Touch감도가 생성된 Group의 Min Row위치
	ptOutPutInfo->ulTouchAreaRow_eIdx = DSPA->T_GROUP.tBit.TouchMaxRow; // Touch감도가 생성된 Group의 Max Row위치
	ptOutPutInfo->ulTouchAreaCellNum = DSPA->T_CELL_NUM.tBit.TouchCellNum; // Touch감도가 생성된 영역의 Cell개수

	g_ulDSPAIRQHandle = 0;
}
