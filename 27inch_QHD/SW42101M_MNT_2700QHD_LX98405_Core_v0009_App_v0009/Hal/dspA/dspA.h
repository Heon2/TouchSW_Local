/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : DSPA.h
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

#ifndef _DSPA_H_
#define _DSPA_H_


typedef struct
{
	uint32_t ulPanelRowNum;
	uint32_t ulPanelColNum;
	uint32_t ulPanelDataNumIncludePad;
	uint32_t ulRawDataBufAddr;
	uint32_t ulBaselineBufAddr;
	uint32_t ulNomalizeBufAddr;
	uint32_t ulIntensityBufAddr;

	uint32_t ulPadEn;
	uint32_t ulPadSize;
	uint32_t ulPadData;

	uint32_t ulNormalizeEn;
	uint32_t ulNormalizeShiftLevel;
	uint32_t ulIntensityBitShiftLevel;

	uint32_t ulPositiveThreshold;
	int32_t lNegativeThreshold;
	uint32_t ulGroupThreshold;

} tDSPAOpHandleInfo_t;

typedef struct
{
	uint32_t ulPositiveCellNum; // +������ ������ Cell����
	uint32_t ulPositiveCellTotalSum; // +������ ������ Cell�� Data��
	uint16_t usPositiveMaxData; // +���� �� Max��
	uint32_t ulPositiveMaxData_RowIdx; // +���� �� Max�� Row��ġ
	uint32_t ulPositiveMaxData_ColIdx; // +���� �� Max�� Column��ġ

	uint32_t ulNegativeCellNum; // -������ ������ Cell����
	int32_t lNegativeCellTotalSum; // -������ ������ Cell Data�� ��
	int16_t sNegativeMaxData; // -���� �� Max��
	uint32_t ulNegativeMaxData_RowIdx; // -���� �� Max�� Row��ġ
	uint32_t ulNegativeMaxData_ColIdx; // -���� �� Max�� Column��ġ

	uint32_t ulTouchAreaRow_sTdx; // Touch������ ������ Group�� Min Row��ġ
	uint32_t ulTouchAreaRow_eIdx; // Touch������ ������ Group�� Max Row��ġ
	uint32_t ulTouchAreaCol_sIdx; // Touch������ ������ Group�� Min Column��ġ
	uint32_t ulTouchAreaCol_eIdx; // Touch������ ������ Group�� Max Column��ġ
	uint32_t ulTouchAreaCellNum; // Touch������ ������ ������ Cell����

} tDSPAOutPutInfo_t;

extern void DSPA_Initialize(tDSPAOpHandleInfo_t * ptHandle);
extern void DSPA_Start(uint32_t bIsWaitIrq, tDSPAOutPutInfo_t * ptOutPutInfo);
extern void DSPA_WaitForIrq(tDSPAOutPutInfo_t * ptOutPutInfo);

#endif /* _DSPA_H_ */
