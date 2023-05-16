/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : DSPA.h
 * created on : 14. 5. 2019
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


//#define _DEF_TEST_MODE_EN_                      0
//#define _DEF_TEST_MODE_NODE_POS_                2

enum{
	LINE_FILTER_HOR = 0,
	LINE_FILTER_VER
};

enum
{
    WITHOUTCOEF = 0,
    WITHCOEF
};

enum
{
    ADDER = 0,
    SUBTRACTION,
    MULTIPLY,
    RESERVED,
    REMAP,
    LINEFILTER_ST1,
    LINEFILTER_ST2,
    LINECELLCOUNT,
};

enum
{
    BYTE = 0,
    HALFWORD,
    WORD,
};

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
    uint32_t ulPositiveCellNum;
    uint32_t ulPositiveCellTotalSum;
    uint16_t usPositiveMaxData;
    uint32_t ulPositiveMaxData_RowIdx;
    uint32_t ulPositiveMaxData_ColIdx;

    uint32_t ulNegativeCellNum;
    int32_t lNegativeCellTotalSum;
    int16_t sNegativeMaxData;
    uint32_t ulNegativeMaxData_RowIdx;
    uint32_t ulNegativeMaxData_ColIdx;

    uint32_t ulTouchAreaRow_sIdx;
    uint32_t ulTouchAreaRow_eIdx;
    uint32_t ulTouchAreaCol_sIdx;
    uint32_t ulTouchAreaCol_eIdx;
    uint32_t ulTouchAreaCellNum;
} tDSPAOutPutInfo_t;

extern void DSP_A_InterruptHandler(void);
extern void DSPA_Initialize(void);
extern void DSPA_Start(bool_t bIsWait);
extern void DSPA_WaitForIrq(tDSPAOutPutInfo_t * ptOutPutInfo);
extern void DSPA_WaitOK(void);
extern void algorithm_init_dspA(void);
extern void alogorithm_linefilter_dspA(uint32_t RAW_ADDR,uint32_t BASE_ADDR, uint32_t TmpDeltaAddr, uint32_t LF_BUF2_ADDR , uint32_t LF_BUF3_ADDR,uint8_t row_max, int32_t PosTHD,int32_t NegTHD, bool_t mode);
extern void algorithm_init_param_dspA(void);
extern void algorithm_baseline_calculate_delta_dspA(int mode);
extern void alogorithm_local_linefilter_dspA(bool_t MuxSum, uint8_t mode);
extern void algorithm_local_mode_calculate_delta_loop_dspA(uint8_t cs, uint8_t ce, uint8_t mode, bool_t MuxSum);
extern void alogorithm_dspA_get_addr(uint8_t mode);
extern void DSPA_CalculateDelta_Process(
uint32_t SRC1_ADDR,
uint32_t SRC2_ADDR,
uint32_t SRC3_ADDR,
uint32_t DST_ADDR,
uint8_t CAL1_WithCoef,
uint8_t CAL2_MODE,
uint8_t SRC2_DIV,
uint8_t DST_DIV,
uint8_t GetValueEnable,
uint16_t Const_a,
uint16_t Const_b,
uint8_t Const_n, 
uint8_t SRC2_DataType,
uint8_t DST_DataType,
int32_t PosTH, 
int32_t NegTH, 
int32_t GroupTH, 
uint8_t cs,
uint8_t ce,
bool_t LocalColumnEn,
uint8_t Row_Size, 
bool_t mux_sum,		
bool_t PadMode,		
uint8_t OpMode		 // 0 : Pen , 1 : Finger, 2 : Phase, 3 : LineFilter
);
#endif /* _DSPA_H_ */
