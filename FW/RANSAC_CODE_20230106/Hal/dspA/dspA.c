/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : DSPA.c
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

#include "app_def.h"
#include "hal_def.h"
#include "module_def.h"


tDSPAOutPutInfo_t tDSPAOutPutInfo;
//tDSPAOutPutInfo_t tCodeOutPutInfo;
extern __IO uint16_t sensingRowStart;
static tAlgorithmInfo_t * thisInfo = NULL;
static const tModuleModeConf_t * ptModuleModeConf  = NULL;
static const tAlgorithmModeConf_t * thisModeConf = NULL;
extern eActivePenType_t gAlgoRawDataType;
extern uint16_t currentRowStart;
uint8_t raw_idx,base_idx,raw_idx_MuxSum,base_idx_MuxSum;
uint32_t RawAddr, BaseAddr, BaseAddr_MuxSum, RawAddr_MuxSum;
extern 	ePartialSensing_t g_RetVal;

//int dbg_dspA[3]={0,0,0};
uint16_t * g_pLocalBaseImage;
int16_t * g_pFullHoverImage;
extern uint16_t * g_pFingerBaseImage;

void algorithm_init_dspA(void)
{
	ptModuleModeConf = module_GetModeConfig();
	thisModeConf     = algorithm_GetModeConfig();
	thisInfo         = algorithm_GetInfo();
	memset(LINEFILTERBUFST1, 0, sizeof(LINEFILTERBUFST1));
	
//#if ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN))
//	BaseAddr_Finger = (uint32_t)&BASELINEIMAGE[0][0];
//#else 
//	BaseAddr_Finger = (uint32_t)&BASELINEIMAGE_2[0][0];
//#endif 
}

void algorithm_init_param_dspA(void)
{
	thisModeConf     = algorithm_GetModeConfig();
	ptModuleModeConf = module_GetModeConfig();
//#if (USED_DSPA_FUNC_FOR_PEN_LOCAL || USED_DSPA_FUNC_FOR_PEN_SEARCH || USED_DSPA_FUNC_FOR_FINGER)
//#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)
//	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
//	{
//		BaseAddr_Finger = (uint32_t)&BASELINEIMAGE[0][0];
//	}
//	else
//	{
//		BaseAddr_Finger = (uint32_t)&BASELINEIMAGE_2[0][0];
//	}
//#endif
//#endif
}

void DSP_A_InterruptHandler(void)
{
    NVIC_ClearPendingIRQ(DSP_A_IRQn);

    if( DSPA->dspa_status.tBit.int_op_end_sts )
    {
    	hal_set_irq_flag(IRQ_ID_DSPA);
        DSPA->dspa_int_clr.tBit.int_op_end_clr = 0x1; // Interrupt Clear
    }
}

void DSPA_Initialize(void)
{
	Fncp_DSP_A_IRQHandler = DSP_A_InterruptHandler;

	NVIC_SetPriority(DSP_A_IRQn, DSP_A_IRQn_Priority);
    NVIC_EnableIRQ(DSP_A_IRQn);

    DSPA->dspa_int_en.tBit.int_op_end = 0x1; // Interrupt Enable
    DSPA->dspa_int_en.tBit.int_tmode = 0x0; // Interrupt Enable
}

int LoopCntDspA = 0;
void DSPA_WaitForIrq(tDSPAOutPutInfo_t * ptOutPutInfo)
{
//	uint32_t ulMinValue;
//	uint32_t ulMaxValue;
	LoopCntDspA = 0;
	while(YES)
	{
	    if(hal_get_irq_flag(IRQ_ID_DSPA))
	    {
	    	hal_clear_irq_flag(IRQ_ID_DSPA);
			LoopCntDspA = 0;
			if(DSPA->dspa_cal_ctrl.tBit.get_val_en)
			{
				ptOutPutInfo->ulPositiveCellNum = (DSPA->dspa_gen_reg0.w  >>  0) & 0xffff;
				ptOutPutInfo->usPositiveMaxData = (DSPA->dspa_gen_reg0.w  >> 16) & 0xffff;
				ptOutPutInfo->ulPositiveCellTotalSum = (int32_t)(DSPA->dspa_gen_reg1.w );
				ptOutPutInfo->ulPositiveMaxData_ColIdx = (DSPA->dspa_gen_reg2.w  >>  0) & 0xff;
				ptOutPutInfo->ulPositiveMaxData_RowIdx = (DSPA->dspa_gen_reg2.w  >>  8) & 0xff;
				ptOutPutInfo->ulNegativeMaxData_ColIdx = (DSPA->dspa_gen_reg2.w  >> 16) & 0xff;
				ptOutPutInfo->ulNegativeMaxData_RowIdx = (DSPA->dspa_gen_reg2.w  >> 24) & 0xff;

				ptOutPutInfo->ulNegativeCellNum = (DSPA->dspa_gen_reg3.w  >>  0) & 0xffff;
				ptOutPutInfo->sNegativeMaxData = (DSPA->dspa_gen_reg3.w  >> 16) & 0xffff;
				ptOutPutInfo->lNegativeCellTotalSum = (int32_t)DSPA->dspa_gen_reg4.w;

				ptOutPutInfo->ulTouchAreaCol_sIdx = (DSPA->dspa_gen_reg5.w  >>  0) & 0xff;
				ptOutPutInfo->ulTouchAreaCol_eIdx = (DSPA->dspa_gen_reg5.w  >>  8) & 0xff;
				ptOutPutInfo->ulTouchAreaRow_sIdx = (DSPA->dspa_gen_reg5.w  >> 16) & 0xff;
				ptOutPutInfo->ulTouchAreaRow_eIdx = (DSPA->dspa_gen_reg5.w  >> 24) & 0xff;
			}
	    	break;
	    }
		
		if(++LoopCntDspA > 32000)
		{
			hal_clear_irq_flag(IRQ_ID_DSPA);
			break;
		}
	}
}

void DSPA_ParamSet(
        uint8_t     cal1_mode,
        uint8_t     cal2_mode,
        uint8_t     src2_div_en,
        uint8_t     dst_div_en,
        uint8_t     get_value_en,
        uint16_t    const_a,
        uint16_t    const_b,
        uint8_t     const_n,
        uint8_t     x_size,
        uint8_t     y_size,
        uint16_t    total_node_size,
        uint8_t     src2_dtype,
        uint8_t     dst_dtype,
        uint32_t    src1_addr,
        uint32_t    src2_addr,
        uint32_t    src3_addr,
        uint32_t    dst_addr,
        int32_t     thd1,
        int32_t     thd2,
        int32_t     thd3,
        int32_t     thd4,
        int32_t     thd5,
        uint8_t     filter_dir
)
{
    DSPA->dspa_init                    = 1;

    if (filter_dir == LINE_FILTER_HOR)
        DSPA->dspa_mode.tBit.sens_dir          = 0;
    else if(filter_dir == LINE_FILTER_VER)
        DSPA->dspa_mode.tBit.sens_dir          = 1;

    DSPA->dspa_mode.tBit.cal1_mode         = cal1_mode;
    DSPA->dspa_mode.tBit.cal2_mode         = cal2_mode;

    DSPA->dspa_cal_ctrl.tBit.src2_div_en   = src2_div_en;
    DSPA->dspa_cal_ctrl.tBit.dst_div_en    = dst_div_en;
    DSPA->dspa_cal_ctrl.tBit.get_val_en    = get_value_en;

    DSPA->dspa_cal_const.tBit.const_a      = const_a;
    DSPA->dspa_cal_const.tBit.const_b      = const_b;
    DSPA->dspa_cal_const.tBit.const_n      = const_n;

    DSPA->dspa_size_cfg.tBit.xsize         = x_size;
    DSPA->dspa_size_cfg.tBit.ysize         = y_size;
    DSPA->dspa_size_cfg.tBit.datalen       = total_node_size;

    DSPA->dspa_dsize.tBit.src2_dsize       = src2_dtype;
    DSPA->dspa_dsize.tBit.dst_dsize        = dst_dtype;
    DSPA->dspa_dsize.tBit.tot_xsize        = x_size;

    DSPA->dspa_src1_addr                 = src1_addr;
    DSPA->dspa_src2_addr                 = src2_addr;
    DSPA->dspa_src3_addr                 = src3_addr;
    DSPA->dspa_dst_addr                  = dst_addr;

    DSPA->dspa_lf_uppth                  = thd1;
    DSPA->dspa_lf_lowth                  = (uint32_t)thd2;
    DSPA->dspa_lcnt_uppth                = thd3;
    DSPA->dspa_lcnt_lowth                = (uint32_t)thd4;
    DSPA->dspa_param_th                  = thd5;

    if ( src2_div_en == 1 )
    {
        if( cal2_mode == LINECELLCOUNT )
        {
            DSPA->dspa_gen_reg0.w  = (1 << 24) | (1 << 16) | (1 << 8) | 1;
            DSPA->dspa_gen_reg1.w  = (1 << 24) | (1 << 16) | (1 << 8) | 1;
        }
        else    // Linfilter Step 1,2,3
        {
            if (filter_dir == LINE_FILTER_HOR)
            {
                DSPA->dspa_gen_reg0.w  = (COL_MAX << 0)
                                         | (COL_MAX << 8)
                                         | (COL_MAX << 16)
                                         | (COL_MAX << 24);
                DSPA->dspa_gen_reg1.w  = (COL_MAX << 0)
                                         | (COL_MAX << 8)
                                         | (COL_MAX << 16)
                                         | (COL_MAX << 24);
            }
            else
            {
                DSPA->dspa_gen_reg0.w  = (1 << 0)
                                         | (1 << 8)
                                         | (1 << 16)
                                         | (1 << 24);
                DSPA->dspa_gen_reg1.w  = (1 << 0)
                                         | (1 << 8)
                                         | (1 << 16)
                                         | (1 << 24);
            }
        }
    }

//    if( _DEF_TEST_MODE_EN_ )
//    {
//        DSPA->dspa_tmode_cfg.tBit.tmode_brk_en =  1;
//        DSPA->dspa_tmode_cfg.tBit.tmode_brk_pos = _DEF_TEST_MODE_NODE_POS_;
//    }
}

void DSPA_Start(bool_t bIsWait)
{
	if(hal_get_irq_flag(IRQ_ID_DSPA) == 0)
	{
		DSPA->dspa_start = 1;
		if(bIsWait)
		{
			DSPA_WaitForIrq(&tDSPAOutPutInfo);
		}
	}
}

void DSPA_WaitOK(void)
{
	DSPA_WaitForIrq(&tDSPAOutPutInfo);
}

int32_t Calc_LineFilter_Value(int32_t sum, int16_t cnt)
{
    int32_t avg;
    
    if(cnt != 0)
        avg = sum / cnt;
    else
        avg = 0;
    
    return avg;
}

void DSPA_CalculateDelta_Process(
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
)
{
	uint32_t Src1_Addr, Src2_Addr;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL ==PEN_PROTOCOL_MSnWGP_PEN)
	if((gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisInfo->tPenInfo.bPen_phase[mux_sum] == 1) && OpMode == 0)
	{
		Src1_Addr = SRC2_ADDR;
		Src2_Addr = SRC1_ADDR;
	}
	else
#endif
	{
		Src1_Addr = SRC1_ADDR;
		Src2_Addr = SRC2_ADDR;
	}

	uint8_t col_size,row_size,end_r;
	uint8_t start_r = 0;
	uint8_t ColMaxOffset = 0;
	uint8_t start_c = cs;
	
	if(LocalColumnEn)
	{
		col_size = ce-start_c;
		row_size = 1;
		end_r = Row_Size;
	}
	else
	{
		start_c = 0;
		col_size = COL_MAX;
		row_size = Row_Size;
		end_r = 1;
	}
	
#if PAD_ > 0	
	if(PadMode == 1)
	{
		if(LocalColumnEn)
		{
			col_size = ce-start_c;
			row_size = 1;
			start_r = PAD_;
			end_r = Row_Size+PAD_;
			ColMaxOffset = 2*PAD_;
		}
		else
		{
			start_c = 0;
			col_size = COL_MAX+2*PAD_;
			row_size = Row_Size+2*PAD_;
			end_r = 1;
		}
	}
#endif
		
	for(int r = start_r; r<end_r; r++)
	{
		DSPA_ParamSet
		(
			CAL1_WithCoef,                         // CAL1 : With/Without Coef
			CAL2_MODE,                        // CAL2 :
			SRC2_DIV,                         // SRC2_DIV
			DST_DIV,                            // DST_DIV
			GetValueEnable,                         // Get Value Enable
			Const_a,                            // Const_a
			Const_b,                            // Const_b
			Const_n,                            // Const_n
			col_size,       // Node COL Size
			row_size,       // Node ROW Size
			col_size*row_size,  // Node Total Size
			SRC2_DataType,                           // SRC2 DataType
			DST_DataType,                           // DST DataType
			Src1_Addr+(((r)*(COL_MAX+ColMaxOffset)+start_c)<<1),//LOCALRAWIMAGE,                 // SRC1 Address
			Src2_Addr+(((r)*(COL_MAX+ColMaxOffset)+start_c)<<1),//LOCALBASELINE,                // SRC2 Address
			SRC3_ADDR,                                  		// SRC3 Address
			DST_ADDR+(((r)*(COL_MAX+ColMaxOffset)+start_c)<<1),               // DST Address
			PosTH, //thisModeConf->Label.usLocalSeedBase,   //thisModeConf->BaseLine.sBlockPosThd,         // Positive ���� Thd
			NegTH,       // Negative ���� Thd
			500,        // Upper Line Count Thd
			-500,       // Lower Line Count Thd
			GroupTH, //thisModeConf->Label.usLocalSeedBase,                    // TGroup Thd (Label Seed)
			LINE_FILTER_HOR
		);
	
		DSPA_Start(1);
		
		if(GetValueEnable)
		{
			if(LocalColumnEn)
			{
				if(OpMode == 0)
				{
					if(thisInfo->tDelta_local.iMaxStrength < tDSPAOutPutInfo.usPositiveMaxData)
					{
						thisInfo->tDelta_local.iMaxStrength = tDSPAOutPutInfo.usPositiveMaxData;
						thisInfo->tDelta_local.tMaxCellPos.r = r;
						thisInfo->tDelta_local.tMaxCellPos.c = tDSPAOutPutInfo.ulPositiveMaxData_ColIdx+start_c;
					}
					
					if(thisInfo->tDelta_local.iMinStrength > tDSPAOutPutInfo.sNegativeMaxData)
						thisInfo->tDelta_local.iMinStrength = tDSPAOutPutInfo.sNegativeMaxData;
					
					if( thisInfo->tDelta_local.tValidRect.cs > tDSPAOutPutInfo.ulTouchAreaCol_sIdx+start_c )
						thisInfo->tDelta_local.tValidRect.cs = tDSPAOutPutInfo.ulTouchAreaCol_sIdx+start_c;
					if( thisInfo->tDelta_local.tValidRect.ce < tDSPAOutPutInfo.ulTouchAreaCol_eIdx+start_c )
						thisInfo->tDelta_local.tValidRect.ce = tDSPAOutPutInfo.ulTouchAreaCol_eIdx+start_c;
					if(tDSPAOutPutInfo.ulPositiveCellNum > 0)
					{
						if( thisInfo->tDelta_local.tValidRect.rs > r )
							thisInfo->tDelta_local.tValidRect.rs = r;
						if( thisInfo->tDelta_local.tValidRect.re < r )
							thisInfo->tDelta_local.tValidRect.re = r;
					}
				}
				else if(OpMode == 2)
				{
					if(thisInfo->tDelta_local.iMaxStrength < tDSPAOutPutInfo.usPositiveMaxData)
						thisInfo->tDelta_local.iMaxStrength = tDSPAOutPutInfo.usPositiveMaxData;
					
					if(thisInfo->tDelta_local.iMinStrength > tDSPAOutPutInfo.sNegativeMaxData)
						thisInfo->tDelta_local.iMinStrength = tDSPAOutPutInfo.sNegativeMaxData;					
				}
			}
			else
			{
				if(OpMode == 1)
				{
					thisInfo->tDelta.iMaxStrength = tDSPAOutPutInfo.usPositiveMaxData;
					thisInfo->tDelta.tValidRect.rs = tDSPAOutPutInfo.ulTouchAreaRow_sIdx;
					thisInfo->tDelta.tValidRect.re = tDSPAOutPutInfo.ulTouchAreaRow_eIdx;
					thisInfo->tDelta.tValidRect.cs = tDSPAOutPutInfo.ulTouchAreaCol_sIdx;
					thisInfo->tDelta.tValidRect.ce = tDSPAOutPutInfo.ulTouchAreaCol_eIdx;
					thisInfo->tDelta.tMaxCellPos.r = tDSPAOutPutInfo.ulPositiveMaxData_RowIdx;
					thisInfo->tDelta.tMaxCellPos.c = tDSPAOutPutInfo.ulPositiveMaxData_ColIdx;
					thisInfo->tDelta.iPosSum = tDSPAOutPutInfo.ulPositiveCellTotalSum;
					thisInfo->tDelta.iPosCnt = tDSPAOutPutInfo.ulPositiveCellNum;
					thisInfo->tDelta.tMinCellPos.r = tDSPAOutPutInfo.ulNegativeMaxData_RowIdx;
					thisInfo->tDelta.tMinCellPos.c = tDSPAOutPutInfo.ulNegativeMaxData_ColIdx;
					thisInfo->tDelta.iNegCnt = tDSPAOutPutInfo.ulNegativeCellNum;
					thisInfo->tDelta.iMinStrength = tDSPAOutPutInfo.sNegativeMaxData;
					thisInfo->tDelta.iNegSum = tDSPAOutPutInfo.lNegativeCellTotalSum;
				}
				else
				{
					if(OpMode == 0)
					{
						thisInfo->tDelta_local.iMaxStrength = tDSPAOutPutInfo.usPositiveMaxData;
						thisInfo->tDelta_local.iMinStrength = tDSPAOutPutInfo.sNegativeMaxData;
						thisInfo->tDelta_local.tMaxCellPos.r = tDSPAOutPutInfo.ulPositiveMaxData_RowIdx;
						thisInfo->tDelta_local.tMaxCellPos.c = tDSPAOutPutInfo.ulPositiveMaxData_ColIdx;
						thisInfo->tDelta_local.tValidRect.cs = tDSPAOutPutInfo.ulTouchAreaCol_sIdx;
						thisInfo->tDelta_local.tValidRect.ce = tDSPAOutPutInfo.ulTouchAreaCol_eIdx;
						thisInfo->tDelta_local.tValidRect.rs = tDSPAOutPutInfo.ulTouchAreaRow_sIdx;
						thisInfo->tDelta_local.tValidRect.re = tDSPAOutPutInfo.ulTouchAreaRow_eIdx;
						thisInfo->tDelta_local.iNegSum = tDSPAOutPutInfo.lNegativeCellTotalSum;
					}
					else if(OpMode == 2)
					{
						thisInfo->tDelta_local.iMaxStrength = tDSPAOutPutInfo.usPositiveMaxData;
						thisInfo->tDelta_local.iMinStrength = tDSPAOutPutInfo.sNegativeMaxData;					
					}
				}
			}
		}
	}
	
#if PAD_ > 0	
	if(PadMode == 1)
	{	
		thisInfo->tDelta_local.tMaxCellPos.r -= PAD_;
		thisInfo->tDelta_local.tValidRect.rs -= PAD_;
		thisInfo->tDelta_local.tValidRect.re -= PAD_;
		thisInfo->tDelta_local.tMaxCellPos.c -= PAD_;
		thisInfo->tDelta_local.tValidRect.cs -= PAD_;
		thisInfo->tDelta_local.tValidRect.ce -= PAD_;	
	}
#endif
}

void DSPA_LineFilter_2nd_Stage(uint32_t TmpDeltaAddr, uint32_t LF_BUF2_ADDR , uint32_t LF_BUF3_ADDR, uint32_t RowIdx,uint8_t RowSize, int32_t PosTHD,int32_t NegTHD)
{  	
	int32_t *pLF_BUF2 = (int32_t *)LF_BUF2_ADDR;
	int32_t *pLF_BUF3 = (int32_t *)LF_BUF3_ADDR;

	memset(pLF_BUF2, 0, 8*sizeof(int32_t));	
	memset(pLF_BUF3, 0, 8*sizeof(int32_t));

	DSPA_CalculateDelta_Process(
		TmpDeltaAddr+RowIdx, LF_BUF2_ADDR, (uint32_t)&LINEFILTERBUFST1[0], LF_BUF2_ADDR,	//SRC1_ADDR, SRC2_ADDR, SRC3_ADDR, DST_DDR  
		0,LINEFILTER_ST2, 1,1,0, 0,0,0, WORD,WORD,   										//CAL1_WithCoef,CAL2_MODE, SRC2_DIV,DST_DIV,GetValueEnable, Const_a,Const_b,Const_n, SRC2_DataType,DST_DataType
		PosTHD,NegTHD,500,                     												//PosTH,NegTH,GroupTH 
		0,COL_MAX, 0, RowSize, 0,0,3);      												//cs,ce, LocalColumnEn, Row_Size, mux_sum, PadMode, OpMode
		
	pLF_BUF3[0] = Calc_LineFilter_Value(pLF_BUF2[0],DSPA->dspa_gen_reg2.Linefilter.n_cnt0);
	pLF_BUF3[1] = Calc_LineFilter_Value(pLF_BUF2[1],DSPA->dspa_gen_reg2.Linefilter.n_cnt1);
	pLF_BUF3[2] = Calc_LineFilter_Value(pLF_BUF2[2],DSPA->dspa_gen_reg3.Linefilter.n_cnt2);
	pLF_BUF3[3] = Calc_LineFilter_Value(pLF_BUF2[3],DSPA->dspa_gen_reg3.Linefilter.n_cnt3);
	pLF_BUF3[4] = Calc_LineFilter_Value(pLF_BUF2[4],DSPA->dspa_gen_reg4.Linefilter.n_cnt4);
	pLF_BUF3[5] = Calc_LineFilter_Value(pLF_BUF2[5],DSPA->dspa_gen_reg4.Linefilter.n_cnt5);
	pLF_BUF3[6] = Calc_LineFilter_Value(pLF_BUF2[6],DSPA->dspa_gen_reg5.Linefilter.n_cnt6);
	pLF_BUF3[7] = Calc_LineFilter_Value(pLF_BUF2[7],DSPA->dspa_gen_reg5.Linefilter.n_cnt7);
}

extern int16_t sLFOffsetRow[ROW_MAX];
void alogorithm_linefilter_dspA(uint32_t RAW_ADDR,uint32_t BASE_ADDR, uint32_t TmpDeltaAddr, uint32_t LF_BUF2_ADDR , uint32_t LF_BUF3_ADDR, uint8_t row_max, int32_t PosTHD,int32_t NegTHD, bool_t mode)
{	
	DSPA_CalculateDelta_Process(
		RAW_ADDR, BASE_ADDR, 0, TmpDeltaAddr,				//SRC1_ADDR, SRC2_ADDR, SRC3_ADDR, DST_DDR  	
		0, SUBTRACTION, 0,0,0, 0,0,0, HALFWORD,HALFWORD,	//CAL1_WithCoef,CAL2_MODE, SRC2_DIV,DST_DIV,GetValueEnable, Const_a,Const_b,Const_n, SRC2_DataType,DST_DataType
		500,-500,500,                      					//PosTH,NegTH,GroupTH 
		0,COL_MAX, 0, row_max, 0, 0, 3);      				//cs,ce, LocalColumnEn, Row_Size, mux_sum, PadMode, OpMode	
	
	int i,j,row_size;
	for(i=0; i<row_max; i+=8)
	{
		uint32_t AddrOffset = (i*COL_MAX)<<1;
		if(i > row_max-8)row_size = row_max-i;
		else row_size = 8;
		
		DSPA_LineFilter_2nd_Stage(TmpDeltaAddr,LF_BUF2_ADDR,LF_BUF3_ADDR,((i*COL_MAX)<<1),row_size,PosTHD,NegTHD);

		DSPA_CalculateDelta_Process(
			RAW_ADDR+AddrOffset, LF_BUF3_ADDR, 0, RAW_ADDR+AddrOffset, 	//SRC1_ADDR, SRC2_ADDR, SRC3_ADDR, DST_DDR  
			0, SUBTRACTION, 1,0,0, 0,0,0, WORD,HALFWORD,          		//CAL1_WithCoef,CAL2_MODE, SRC2_DIV,DST_DIV,GetValueEnable, Const_a,Const_b,Const_n, SRC2_DataType,DST_DataType
			500,-500,500,                      							//PosTH,NegTH,GroupTH 
			0,COL_MAX, 0, row_size, 0, 0, 3);      						//cs,ce, LocalColumnEn, Row_Size, mux_sum, PadMode, OpMode
		
		if(mode == 0)
			for(j=0;j<row_size;j++)
				sLFOffsetRow[i+j] = LINEFILTERBUFST3_Finger[j];
	}
}

void algorithm_delta_padding(uint8_t mode)
{
    uint16_t r,end_r;
    int16_t *psrc;
    int16_t *pdst;
    uint32_t MemTransSize;
    
    MemTransSize = COL_MAX*sizeof(int16_t);
   
	if(mode == LOCAL_HOVER_MODE)
	{
		psrc = &DSPATMPDELTA[0][0];
		pdst = &DSPATMPDELTA_PAD[0][0];	
		end_r = PEN_COORD_ROW_MAX;		
	}
	else if(mode == LOCAL_MODE)
	{
		psrc = &DSPATMPDELTA[0][0];
		pdst = &LOCALDELTAIMAGE[0][0];	
		end_r = PEN_COORD_ROW_MAX;		
	}
	else
	{
		psrc = &DSPATMPDELTA_Finger[0][0];
		pdst = HAL_GET_DELTA_IMAGE_PTR();
		end_r = ROW_MAX;
	}

	pdst += (COL_MAX + 2*PAD_+PAD_);

	for( r=0; r<end_r; r++ )
	{
		memcpy(pdst, psrc, MemTransSize);

		psrc += COL_MAX;
		pdst += (COL_MAX + 2*PAD_);
	}
}

void alogorithm_dspA_get_addr(uint8_t mode)
{
	raw_idx = base_idx = 0;
	if(thisModeConf->BaseLine.ucPP_MUX_Select)
	{
		raw_idx = PEN_COORD_ROW_MAX;
		if(thisModeConf->BaseLine.bPen_2BASE)base_idx = ROW_MAX;
	}

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	RawAddr = (uint32_t)&LOCALDATARAW_3[0][0]+((raw_idx*COL_MAX)<<1);	
#else
	RawAddr = (uint32_t)&LOCALRAWIMAGE[0][0]+((raw_idx*COL_MAX)<<1);
#endif
	BaseAddr = (uint32_t)(&g_pLocalBaseImage[0])+(((currentRowStart+base_idx)*COL_MAX)<<1);	
	
	if( (thisModeConf->BaseLine.b2MUX_SUM_LocalMode == YES && mode!=LOCAL_SEARCH_MODE) || (thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode == YES && mode==LOCAL_SEARCH_MODE) )
	{
		raw_idx_MuxSum = base_idx_MuxSum = 0;
		if(thisModeConf->BaseLine.ucPP_MUX_Select == 0)
		{
			raw_idx_MuxSum = PEN_COORD_ROW_MAX;
			if(thisModeConf->BaseLine.bPen_2BASE)base_idx_MuxSum = ROW_MAX;
		}
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
		RawAddr_MuxSum = (uint32_t)&LOCALDATARAW_3[0][0]+((raw_idx_MuxSum*COL_MAX)<<1);	
#else		
		RawAddr_MuxSum = (uint32_t)&LOCALRAWIMAGE[0][0]+((raw_idx_MuxSum*COL_MAX)<<1);
#endif
		BaseAddr_MuxSum = (uint32_t)(&g_pLocalBaseImage[0])+(((currentRowStart+base_idx_MuxSum)*COL_MAX)<<1);
	}
}

void alogorithm_local_linefilter_dspA(bool_t MuxSum, uint8_t mode)
{	
	alogorithm_linefilter_dspA(RawAddr,BaseAddr,(uint32_t)&DSPATMPDELTA[0][0],(uint32_t)&LINEFILTERBUFST2[0],(uint32_t)&LINEFILTERBUFST3[0],PEN_COORD_ROW_MAX,
	(uint32_t)(thisModeConf->SensingFilter.sLineFilterUpLimit_Pen<<ptModuleModeConf->ucLocalOvrShift),(uint32_t)(thisModeConf->SensingFilter.sLineFilterLowLimit_Pen<<ptModuleModeConf->ucLocalOvrShift),1);
	if(MuxSum)
		alogorithm_linefilter_dspA(RawAddr_MuxSum,BaseAddr_MuxSum,(uint32_t)&DSPATMPDELTA[0][0],(uint32_t)&LINEFILTERBUFST2[0],(uint32_t)&LINEFILTERBUFST3[0],PEN_COORD_ROW_MAX,
		(uint32_t)(thisModeConf->SensingFilter.sLineFilterUpLimit_Pen<<ptModuleModeConf->ucLocalOvrShift),(uint32_t)(thisModeConf->SensingFilter.sLineFilterLowLimit_Pen<<ptModuleModeConf->ucLocalOvrShift),1);
}

void algorithm_local_mode_calculate_delta_loop_dspA(uint8_t cs, uint8_t ce, uint8_t mode, bool_t MuxSum)
{
	uint32_t Dst_Addr;
	bool_t get_val_1st=0,get_val_2nd=0,LocalCol=1;
	
	if(mode == LOCAL_SEARCH_MODE)
	{
		Dst_Addr = (uint32_t)&LOCALDELTAIMAGE[0][0];
		LocalCol = 0;
	}
	else if(mode == LOCAL_HOVER_MODE)
	{
		Dst_Addr = (uint32_t)&DSPATMPDELTA[0][0];
	}
	else if(mode == LOCAL_MODE)	
	{
		get_val_1st = !MuxSum;
		get_val_2nd = 1;
#if (PAD_ > 0)	
		Dst_Addr = (uint32_t)&DSPATMPDELTA[0][0];		
#else
		Dst_Addr = (uint32_t)&LOCALDELTAIMAGE[0][0];
#endif	
	}	

	DSPA_CalculateDelta_Process(
		BaseAddr, RawAddr, 0, Dst_Addr,																		//SRC1_ADDR, SRC2_ADDR, SRC3_ADDR, DST_DDR  
		WITHCOEF,SUBTRACTION, 0,0,get_val_1st, 1,1,(ptModuleModeConf->ucLocalOvrShift), HALFWORD,HALFWORD,  //CAL1_WithCoef,CAL2_MODE, SRC2_DIV,DST_DIV,GetValueEnable, Const_a,Const_b,Const_n, SRC2_DataType,DST_DataType
		(int32_t)thisModeConf->Label.usLocalSeedBase,-500,(int32_t)thisModeConf->Label.usLocalSeedBase,     //PosTH,NegTH,GroupTH 
		cs,ce, LocalCol, PEN_COORD_ROW_MAX, 0, 0, 0);                                                  		//cs,ce, LocalColumnEn, Row_Size, mux_sum, PadMode, OpMode
			
	if(MuxSum)
	{
		DSPA_CalculateDelta_Process(
			BaseAddr_MuxSum, RawAddr_MuxSum, 0, (uint32_t)&DSPATMPDELTA[PEN_COORD_ROW_MAX][0],					//SRC1_ADDR, SRC2_ADDR, SRC3_ADDR, DST_DDR  
			WITHCOEF,SUBTRACTION, 0,0,0, 1,1,(ptModuleModeConf->ucLocalOvrShift), HALFWORD,HALFWORD,         	//CAL1_WithCoef,CAL2_MODE, SRC2_DIV,DST_DIV,GetValueEnable, Const_a,Const_b,Const_n, SRC2_DataType,DST_DataType
			(int32_t)thisModeConf->Label.usLocalSeedBase,-500,(int32_t)thisModeConf->Label.usLocalSeedBase,     //PosTH,NegTH,GroupTH 
			cs,ce, LocalCol, PEN_COORD_ROW_MAX,MuxSum, 0, 0);                                                   //cs,ce, LocalColumnEn, Row_Size, mux_sum, PadMode, OpMode
		
		DSPA_CalculateDelta_Process(
			Dst_Addr, (uint32_t)&DSPATMPDELTA[PEN_COORD_ROW_MAX][0], 0, Dst_Addr, 								//SRC1_ADDR, SRC2_ADDR, SRC3_ADDR, DST_DDR  
			0,ADDER, 0,0,get_val_2nd, 0,0,0, HALFWORD,HALFWORD,                                             	//CAL1_WithCoef,CAL2_MODE, SRC2_DIV,DST_DIV,GetValueEnable, Const_a,Const_b,Const_n, SRC2_DataType,DST_DataType
			(int32_t)thisModeConf->Label.usLocalSeedBase,-500,(int32_t)thisModeConf->Label.usLocalSeedBase,     //PosTH,NegTH,GroupTH 
			cs,ce, LocalCol, PEN_COORD_ROW_MAX, 0, 0, 0);                                                       //cs,ce, LocalColumnEn, Row_Size, mux_sum, PadMode, OpMode
	}

	if(mode == LOCAL_SEARCH_MODE)
	{
		//Pen_Detection_Acc_Process
		DSPA_CalculateDelta_Process(
			(uint32_t)(&g_pFullHoverImage[currentRowStart*COL_MAX]), (uint32_t)&LOCALDELTAIMAGE[0][0], 0, (uint32_t)(&g_pFullHoverImage[currentRowStart*COL_MAX]),	//SRC1_ADDR, SRC2_ADDR, SRC3_ADDR, DST_DDR  
			0,ADDER, 0,0,1, 0,0,0, HALFWORD,HALFWORD,                                                                                                           //CAL1_WithCoef,CAL2_MODE, SRC2_DIV,DST_DIV,GetValueEnable, Const_a,Const_b,Const_n, SRC2_DataType,DST_DataType
			(int32_t)thisModeConf->Label.usLocalSeedBase,thisModeConf->BaseLine.sAccumNegSumThd,(int32_t)thisModeConf->Label.usLocalSeedBase,                                              		//PosTH,NegTH,GroupTH 
			cs,ce, LocalCol, PEN_COORD_ROW_MAX, 0, 0, 0);                                                                                                    	//cs,ce, LocalColumnEn, Row_Size, mux_sum, PadMode, OpMode
	}	
#if (PAD_ > 0)
	else
		algorithm_delta_padding(mode);
#endif
	
	if(mode == LOCAL_HOVER_MODE)
	{
		uint16_t hover_weight = 0;
		if(thisModeConf->Label.ucHoverOutCheckFrm < 6)
			hover_weight = thisModeConf->Label.ucHoverOutCheckFrm/2;
		else if(thisModeConf->Label.ucHoverOutCheckFrm < 8)
			hover_weight = 2;
		else if(thisModeConf->Label.ucHoverOutCheckFrm < 16)
			hover_weight = 3;
		else 
			hover_weight = 4;

#if (PAD_ > 0)		
		DSPA_CalculateDelta_Process(
			(uint32_t)&DSPATMPDELTA_PAD[0][0], (uint32_t)&LOCALDELTAIMAGE[0][0], 0, (uint32_t)&LOCALDELTAIMAGE[0][0], 	//SRC1_ADDR, SRC2_ADDR, SRC3_ADDR, DST_DDR  
			1,ADDER, 0,0,1, 1<<hover_weight,(1<<hover_weight)-1,(uint8_t)hover_weight, HALFWORD,HALFWORD,         		//CAL1_WithCoef,CAL2_MODE, SRC2_DIV,DST_DIV,GetValueEnable, Const_a,Const_b,Const_n, SRC2_DataType,DST_DataType
			(int32_t)thisModeConf->Label.usLocalSeedBase,-500,(int32_t)thisModeConf->Label.usLocalSeedBase,       		//PosTH,NegTH,GroupTH 
			cs+PAD_,ce+PAD_, LocalCol, PEN_COORD_ROW_MAX, 0, 1, 0);                                                  	//cs,ce, LocalColumnEn, Row_Size, mux_sum, PadMode, OpMode
#else
		DSPA_CalculateDelta_Process(
			(uint32_t)&DSPATMPDELTA[0][0], (uint32_t)&LOCALDELTAIMAGE[0][0], 0, (uint32_t)&LOCALDELTAIMAGE[0][0], 		//SRC1_ADDR, SRC2_ADDR, SRC3_ADDR, DST_DDR  
			1,ADDER, 0,0,1, 1<<hover_weight,(1<<hover_weight)-1,(uint8_t)hover_weight, HALFWORD,HALFWORD,         	 	//CAL1_WithCoef,CAL2_MODE, SRC2_DIV,DST_DIV,GetValueEnable, Const_a,Const_b,Const_n, SRC2_DataType,DST_DataType
			(int32_t)thisModeConf->Label.usLocalSeedBase,-500,(int32_t)thisModeConf->Label.usLocalSeedBase,       		//PosTH,NegTH,GroupTH 
			cs,ce, LocalCol, PEN_COORD_ROW_MAX, 0, 0, 0);                                                             	//cs,ce, LocalColumnEn, Row_Size, mux_sum, PadMode, OpMode
#endif
	}
}

void algorithm_baseline_calculate_delta_dspA(int mode)
{
	uint16_t * pBaseImage;
	uint32_t Dst_Addr;
#if (PAD_ > 0)	
	Dst_Addr = (uint32_t)&DSPATMPDELTA_Finger[0][0];
//	memset(DSPATMPDELTA_Finger,0,sizeof(DSPATMPDELTA_Finger));
#else
	Dst_Addr = (uint32_t)&DELTAIMAGE[0][0];
#endif

#if USED_NOISE_HOPPING_FREQ
	tAppInfo_t * pAppInfo = app_GetInfo();
	if(pAppInfo->eSelectFreq == FREQ_MAIN)
	{
		pBaseImage = g_pFingerBaseImage;
	}
	else
	{
		pBaseImage = (uint16_t *)HAL_GET_HOPP1_BASELINE_IMAGE_PTR() ;
	}
#else /* USED_NOISE_HOPPING_FREQ */
	pBaseImage = g_pFingerBaseImage;//HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
#endif /* USED_NOISE_HOPPING_FREQ */

	DSPA_CalculateDelta_Process(
		(uint32_t)&RAWIMAGE[0][0], (uint32_t)(&pBaseImage[0]), 0,Dst_Addr,																					//SRC1_ADDR, SRC2_ADDR, SRC3_ADDR, DST_DDR
		WITHCOEF,SUBTRACTION, 0,0,1, 1,1,ptModuleModeConf->ucOvrShift, HALFWORD,HALFWORD,														//CAL1_WithCoef,CAL2_MODE, SRC2_DIV,DST_DIV,GetValueEnable, Const_a,Const_b,Const_n, SRC2_DataType,DST_DataType
		(int32_t)thisModeConf->BaseLine.sAccumPosSumThd,(int32_t)thisModeConf->BaseLine.sAccumNegSumThd,(int32_t)thisModeConf->Label.usSeedBase, 	//PosTH,NegTH,GroupTH 
		0,COL_MAX, 0, ROW_MAX, 0, 0, 1);																										//cs,ce, LocalColumnEn, Row_Size, mux_sum, PadMode, OpMode
	
	if(  thisInfo->tDelta.iMaxStrength > thisModeConf->Label.usSeedBase)
	{
		thisInfo->bTouchExpect = YES;
	}
	else thisInfo->bTouchExpect = NO;

	
#if (PAD_ > 0)
	algorithm_delta_padding(mode);
#endif
}
