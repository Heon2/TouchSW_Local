/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : DSP_B.c
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
#include "module_def.h"
#include "protocol_def.h"


#if (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY))

static const tAlgorithmCommonConf_t * thisCommonConf = NULL;
static const tAlgorithmModeConf_t * thisModeConf = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;


extern uint16_t currentRowStart;
extern uint16_t p_currentRowStart;
//extern volatile uint16_t sensingRowStart;
extern ePartialSensing_t g_RetVal;

//extern int HID_TILT_X ;
//extern int HID_TILT_Y ;
//extern int HID_TWIST ;
//extern int HID_AZIMUTH;
//extern int HID_ALTITUDE;
#endif /* (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY)) */


//__IO int  TEST_Flag_DSP_B = TRUE;
__IO static uint32_t g_ulDSPBIRQHandle;
__IO int  DSP_B_Index = 1;

void DSP_B_InterruptHandler(void)
{
#if (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY))
	tAlgorithmInfo_t * ptAlgorithmInfo; // NOTE : Global Variable�슖�댙�삕 �뜝�럡�맖�뜝�럥�꽘�뜝�럥由��뜝�럥�뿰 Hal嶺뚯옕�윪�굢�맮�삕�땻占� Initialize�뜝�럥由�嶺뚮〕�삕 �뜝�럡�뀬�뜝�럩�뮔 �뜝�럥留� �뜝�럥�빢 �뜝�럩肉녑뜝�럥利꿨슖�댙�삕 �솻洹⑥삕�뇦猿뗰옙�뇡占썲뜝�럩�겱!! IRQ�뤆�룊�삕 Hal嶺뚯옕�윪占쎈さ�슖�댙�삕 �뜝�럩留꾤뇖�궪�삕 �뜝�럩逾졾뜝�럥吏�!!
	Clear_DSP_B_Intr();
	ptAlgorithmInfo = algorithm_GetInfo();
//	__IS_COMPLETE_DSPB__ = TRUE;

	if(DSP_B_Index < PEN_UPDATE_POST_INFO)
	{
		DSP_B_Index++;

		if(ptAlgorithmInfo->tPenInfo.bPenContact == YES)
			algorithm_local_dsp_process(DSP_B_Index,PARTIAL_PEN_BEACON, LOCAL_MODE);
		else
			algorithm_local_dsp_process(DSP_B_Index,PARTIAL_PEN_BEACON, LOCAL_HOVER_MODE);
	}
#else /* (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY)) */
	Clear_DSP_B_Intr();
#endif /* (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY)) */

	g_ulDSPBIRQHandle = TRUE;
}

void init_DSP_B(void)
{
	Fncp_DSP_B_IRQHandler = &DSP_B_InterruptHandler;
	//********************************************************
	// Interrupt Enable 
	//********************************************************
	REG_TDSP2_INTERRUPT = (1<<4) | (1<<0); 		// Disable Interrupt Mask | Clear Interrupt
	
	NVIC_EnableIRQ (DSP_B_IRQn);    /* Interrupt Enable */	
	NVIC_SetPriority(DSP_B_IRQn, DSP_B_IRQn_Priority);
}

void Clear_DSP_B_Intr(void)
{
	REG_TDSP2_INTERRUPT |= (1<<0); // Clear Interrupt
}

#if (USED_PEN_MODE_OPERATION || !defined(FINGER_ONLY))
#if 0
void algorithm_local_baseline_init(void)
{
	int r, c, rs = 0;

    for( r=thisInfo->ucRow; r--; )
	{
		for( c=thisInfo->ucCol; c--; )
		{
			HAL_WRITE_LOCAL_DATA_BASELINE_IMAGE(r, c, 0x000);
		}
	}
}
#endif
void algorithm_baseline_init_local(void)
{
	int r, c;

	for(r=-PAD_; r<thisInfo->ucRow+PAD_; r++ )
	{
		for(c=-PAD_; c<thisInfo->ucCol+PAD_; c++ )
		{
			HAL_WRITE_DELTA_IMAGE(r, c, 0);
		}
	}
}

void algorithm_label_init_local(void)
{
	int r, c;

	for( r=-PAD_; r<thisInfo->ucScreenRow + PAD_; r++ )
	{
		for( c=-PAD_; c<thisInfo->ucScreenCol + PAD_; c++ )
		{
			HAL_WRITE_LABEL_IMAGE(r, c, 0);
			HAL_WRITE_LABEL_LINKLIST_IMAGE(r, c, 0);
		}
	}
}
#if 0
void algorithm_coord_init_local(void)
{
	int l;

	// local coord init
	thisInfo->tCoord_local.tPastPos[0].sFinger_    = 0;
	thisInfo->tCoord_local.tOrgPastPos[0].sFinger_ = 0;

	for(l=ptMemLocalConf->iMaxTouch_; l--; )
	{
		thisInfo->tCoord_local.tPastPos[0].tXY[l].x    = 0;
		thisInfo->tCoord_local.tPastPos[0].tXY[l].y    = 0;
		thisInfo->tCoord_local.tPastPos[0].vusR[l]	   = 0;
		thisInfo->tCoord_local.tPastPos[0].vusS[l]	   = 0;

		thisInfo->tCoord_local.tPastPos[1].tXY[l].x    = 0;
		thisInfo->tCoord_local.tPastPos[1].tXY[l].y    = 0;
		thisInfo->tCoord_local.tPastPos[1].vusR[l]	   = 0;
		thisInfo->tCoord_local.tPastPos[1].vusS[l]	   = 0;

		thisInfo->tCoord_local.tPastPos[2].tXY[l].x    = 0;
		thisInfo->tCoord_local.tPastPos[2].tXY[l].y    = 0;
		thisInfo->tCoord_local.tPastPos[2].vusR[l]	   = 0;
		thisInfo->tCoord_local.tPastPos[2].vusS[l]	   = 0;

		thisInfo->tCoord_local.tOrgPastPos[0].tXY[l].x = 0;
		thisInfo->tCoord_local.tOrgPastPos[0].tXY[l].y = 0;
		thisInfo->tCoord_local.tOrgPastPos[0].vusR[l]  = 0;
		thisInfo->tCoord_local.tOrgPastPos[0].vusS[l]  = 0;

		thisInfo->tCoord_local.tOrgPastPos[1].tXY[l].x = 0;
		thisInfo->tCoord_local.tOrgPastPos[1].tXY[l].y = 0;
		thisInfo->tCoord_local.tOrgPastPos[1].vusR[l]  = 0;
		thisInfo->tCoord_local.tOrgPastPos[1].vusS[l]  = 0;

		thisInfo->tCoord_local.tOrgPastPos[2].tXY[l].x = 0;
		thisInfo->tCoord_local.tOrgPastPos[2].tXY[l].y = 0;
		thisInfo->tCoord_local.tOrgPastPos[2].vusR[l]  = 0;
		thisInfo->tCoord_local.tOrgPastPos[2].vusS[l]  = 0;

		thisInfo->tCoord_local.ucIdMappedCnt[l] = 0;
		thisInfo->tCoord_local.cScreenDebCnt[l] = 0;
	}

	thisInfo->tCoord_local.iXOffset = ( UNIT_DIST * ( 2*thisCommonConf->iXEdgeNum - thisCommonConf->iXEdgeDen) ) / (2*thisCommonConf->iXEdgeDen);
	thisInfo->tCoord_local.iYOffset = ( UNIT_DIST * (2*thisCommonConf->iYEdgeNum - thisCommonConf->iYEdgeDen) ) / (2*thisCommonConf->iYEdgeDen);

	thisInfo->tCoord_local.iXExpandStart = 1*UNIT_DIST;
	thisInfo->tCoord_local.iYExpandStart = 1*UNIT_DIST;

	thisInfo->tCoord_local.iXEdgeStart = 1*UNIT_DIST;
	thisInfo->tCoord_local.iYEdgeStart = 1*UNIT_DIST;

	if( ptMemLocalConf->bSwapXY )
	{
		thisInfo->tCoord_local.iInternalXRes = (ptMemLocalConf->iRow_ - 1) << POS_BOOST_SHIFT_;
		thisInfo->tCoord_local.iInternalYRes = (ptMemLocalConf->iCol_ - 1) << POS_BOOST_SHIFT_;
	}
	else
	{
		thisInfo->tCoord_local.iInternalXRes = (ptMemLocalConf->iCol_ - 1) << POS_BOOST_SHIFT_;
		thisInfo->tCoord_local.iInternalYRes = (ptMemLocalConf->iRow_ - 1) << POS_BOOST_SHIFT_;
	}

	thisInfo->tCoord_local.slScaledMoveDistThd = (thisModeConf->Coord.usMoveDistanceThd << POS_BOOST_SHIFT_);

}
#endif


void algorithm_coord_init_local_DSP(void)
{
	// local coord init
	memset(thisInfo->tCoord_local_dsp.tPastPosHist,-1,sizeof(thisInfo->tCoord_local_dsp.tPastPosHist));

	thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x   = -1;
	thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y   = 0;
	thisInfo->tCoord_local_dsp.tPastPos[0].vusR     = 0;
	thisInfo->tCoord_local_dsp.tPastPos[0].vusS     = 0;

	thisInfo->tCoord_local_dsp.tPastPos[1].tXY.x   = -1;
	thisInfo->tCoord_local_dsp.tPastPos[1].tXY.y   = 0;
	thisInfo->tCoord_local_dsp.tPastPos[1].vusR     = 0;
	thisInfo->tCoord_local_dsp.tPastPos[1].vusS     = 0;

	thisInfo->tCoord_local_dsp.tPastPos2.tXY.x     = -1;
	thisInfo->tCoord_local_dsp.tPastPos2.tXY.y     = 0;
	thisInfo->tCoord_local_dsp.tPastPos2.vusR       = 0;
	thisInfo->tCoord_local_dsp.tPastPos2.vusS       = 0;

	thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x = 0;
	thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y = 0;
	thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusR  = 0;
	thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS  = 0;

	thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.x = 0;
	thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.y = 0;
	thisInfo->tCoord_local_dsp.tOrgPastPos[1].vusR  = 0;
	thisInfo->tCoord_local_dsp.tOrgPastPos[1].vusS  = 0;

	thisInfo->tCoord_local_dsp.tOrgPastPos2.tXY.x = 0;
	thisInfo->tCoord_local_dsp.tOrgPastPos2.tXY.y = 0;
	thisInfo->tCoord_local_dsp.tOrgPastPos2.vusR  = 0;
	thisInfo->tCoord_local_dsp.tOrgPastPos2.vusS  = 0;

	thisInfo->tCoord_local_dsp.ucIdMappedCnt = 0;
}

void algorithm_init_local(void)
{
	const tModuleCommonConf_t * _ptModuleCommonConf = NULL;
	_ptModuleCommonConf = module_GetCommonConfig();	


//	ptModuleModeConf = module_GetModeConfig();// NOTE : warning�뜝�럩�젷濾곌쒀�삕
//	ptAppInfo        = app_GetInfo();	// NOTE : warning�뜝�럩�젷濾곌쒀�삕
	thisCommonConf   = algorithm_GetCommonConfig();	
	thisModeConf     = algorithm_GetModeConfig();
	thisInfo         = algorithm_GetInfo();	

	thisInfo->ucTxLessCol = _ptModuleCommonConf->ucTxLessCol_;
	thisInfo->ucTxLessRow = _ptModuleCommonConf->ucTxLessRow_;

	thisInfo->ucScreenCol = _ptModuleCommonConf->ucScreenCol_;
	thisInfo->ucScreenRow = _ptModuleCommonConf->ucScreenRow_;

	thisInfo->ucCol = thisInfo->ucScreenCol + thisInfo->ucTxLessCol;
	thisInfo->ucRow = thisInfo->ucScreenRow + thisInfo->ucTxLessRow;

	algorithm_baseline_init_local();
	algorithm_label_init_local();
	algorithm_coord_init_local_DSP();
	
	algorithm_local_baseline_init();
}


//extern volatile uint32_t bIrqDone_Tdsp;			// Declared in handler.c
//extern int16_t	eq_tbl[(MAX_LABEL+1)*4];

/********************************************************************************
  @brief    Line Filter OPCODE
  */
#if 1
#ifdef SRAM_OPCODE
int opcode_linefilter[] = 
#else
int opcode_linefilter[] = 
#endif
{
    // Input : A0, A1
		SDMA0(REGA0, 0, DMA_SIZE0),                                                    	//      ; A0 : pRawImg
    SDMA1(REGA1, 0, DMA_SIZE3),                                                    	//      ; A1 : pBaseImg
	
		SLOOP0(0, 0, LOOP_LT, LOOP_REGC0),                                              //      ; Row loop -> 0:Row
		MOV(CNT0, REGB0),                                                      					//      ; B0 = CNT0, B0: Raw Row Idx
		ADD(REGB0, REGA2, REGB1),                                                       //      ; B1 = CNT0 + A2 : nCurrRowStart, B1 : Base Row Idx
		MOV(REGA4, REGB4),                                                      				//      ; B4 = A4 : FIRST_MIN = INT16_MAX
		MOV(REGA4, REGB5),                                                      				//      ; B5 = A4 : SECOND_MIN = INT16_MAX
		MOV(REGA4, REGB6),                                                      				//      ; B6 = A4 : THIRD_MIN = INT16_MAX
		MOV(REGA4, REGB7),                                                      				//      ; B7 = A4 : FOURTH_MIN = INT16_MAX
		
		SLOOP1(0, 0, LOOP_LT, LOOP_REGC1),                                              //      ; Col loop -> 0:Col/4
		MUL(CNT1, REGA5, REGB2),                                                      	//      ; B2 = CNT1 * REGA5 : SmpNum, B2: Raw Col Idx
		ADD(REGB2, REGA3, REGB3),                                                       //      ; B3 = REGB2 + A3 : nCurrColStart, B3 : Base Col Idx
    SRW0(REGB2, REGB0, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                //      ; CH0FLT00 = pRawImg(REGB2, REGB0)
		SRW1(REGB3, REGB1, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                //      ; CH1FLT = pBaseImg(REGB3, REGB1)
		SUBS(CH0FLT00, CH1FLT, REGC7),																									//			; C7 = pRawImg - pBaseImg : Delta
		CMPS(REGB4, REGC7),                                                      				//      ; cmps(FIRST_MIN, Delta)
		BRC(LINE_CNT(6), DOWN, LES),                                                    //      ; FIRST_MIN <= Delta  -> JP00
		MOV(REGB6, REGB7),                                                     				  //      ; FOURTH_MIN = THIRD_MIN
		MOV(REGB5, REGB6),                                                      				//      ; THIRD_MIN = SECOND_MIN
		MOV(REGB4, REGB5),                                                      				//      ; SECOND_MIN = FIRST_MIN
		MOV(REGC7, REGB4),                                                       				//      ; FIRST_MIN = Delta
		BRC(LINE_CNT(15), DOWN, AL),                                                    //      ; Always              -> JP03
		CMPS(REGB5, REGC7),                                                      				// JP00 ; cmps(SECOND_MIN, Delta)
		BRC(LINE_CNT(5), DOWN, LES),                                                    //      ; SECOND_MIN <= Delta -> JP01
		MOV(REGB6, REGB7),                                                     				  //      ; FOURTH_MIN = THIRD_MIN
		MOV(REGB5, REGB6),                                                      				//      ; THIRD_MIN = SECOND_MIN
		MOV(REGC7, REGB5),                                                      				//      ; SECOND_MIN = Delta
		BRC(LINE_CNT(9), DOWN, AL),                                                     //      ; Always              -> JP03
		CMPS(REGB6, REGC7),                                                      				// JP01 ; cmps(THIRD_MIN, Delta)
		BRC(LINE_CNT(4), DOWN, LES),                                                    //      ; THIRD_MIN <= Delta  -> JP02
		MOV(REGB6, REGB7),                                                     				  //      ; FOURTH_MIN = THIRD_MIN
		MOV(REGC7, REGB6),                                                      				//      ; THIRD_MIN = Delta
		BRC(LINE_CNT(4), DOWN, AL),                                                     //      ; Always              -> JP03
		CMPS(REGB7, REGC7),                                                      				// JP02 ; cmps(FOURTH_MIN, Delta)
		BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; FOURTH_MIN <= Delta -> JP03
		MOV(REGC7, REGB7),                                                     				  //      ; FOURTH_MIN = Delta
		ELOOP1(),                                                                       // JP03 ;
		
		SLOOP1(0, 0, LOOP_LT, LOOP_REGC2),                                              //      ; Col loop -> 0:Col
		MOV(CNT1, REGB2),                                                      					//      ; B2 = CNT1, B2: Raw Col Idx
		SRW0(REGB2, REGB0, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                //      ; CH0FLT00 = pRawImg(REGB2, REGB0)
		SUBS(CH0FLT00, REGB7, REGC7),																										//			; C7 = pRawImg - FOURTH_MIN
		MOV(REGC7, CH0FLT00),                                                           // 			; CH0FLT00 = REGC7
		SRW0(REGB2, REGB0, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_16BIT),    		        //      ; CH0FLT00 WRITE
		ELOOP1(),                                                                       //
		
		ELOOP0(),                                                                       //
    
    END()                                                                         	//      ; end
};
#endif

/********************************************************************************
  @brief    Pen calculate delta
  */
#ifdef SRAM_OPCODE
int opcode_pendelta[] = 
#else
int opcode_pendelta[] = 
#endif
{
    // input A0~B3, loop_cnt C0~C1
    RDMAC0(REGA0, DT_UNSIGNED, 0, BS_4BURST, DM_16BIT),                             //      ; A0 : raw img
    SDMA0(REGB3, 0, DMA_SIZE0),                                                     //      ; B3 : pPenDeltaInfo
    SDMA1(REGA1, 0, DMA_SIZE3),                                                     //      ; A1 : base img
    SDMA2(REGA2, 0, DMA_SIZE0),                                                     //      ; A2 : normalize img
    SDMA3(REGA3, 0, DMA_SIZE2),                                                     //      ; A3 : delta img
    
    MUL(REGA4, REGB1, REGC6),                                                       //      ; C6 = A4*B1, A4 : nCurrRowStart, B1 : ucMuxRowSize
    MOV(REGA5, REGC7),                                                              //      ; C7 = A5, A5 : nCurrColStart
    SRW0(CONST_VAL(0), REGC0, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; rs = C0, C0 : nHeight
    SRW0(CONST_VAL(1), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; re = 0
    SRW0(CONST_VAL(2), REGC1, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; cs = C1, C1 : nWidth
    SRW0(CONST_VAL(3), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; ce = 0
    MOV(CONST_VAL(0), REGC4),                                                       //      ; C4 = 0
    
    SLOOP0(0, 0, LOOP_LT, LOOP_REGC0),                                              //      ; row loop
    ADD(CNT0, REGB2, REGB4),                                                        //      ; B4 = CNT0 + B2, B2 : ucPadSize
    ADD(CNT0, REGC6, REGC5),                                                        //      ; C5 = CNT0 + C6
    SLOOP1(0, 0, LOOP_LT, LOOP_REGC1),                                              //      ; column loop
    
    ADD(CNT1, REGC7, REGB5),                                                        //      ; B5 = CNT1 + C7
    SRW1(REGB5, REGC5, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                //      ; CH1FLT = base_img(CNT1, CNT0)
    SUB(CH1FLT, MEM00, REGC3),                                                      //      ; C3 = CH1FLT - MEM00, MEM00 : raw img
    CMP(REGA6, CONST_VAL(0)),                                                       //      ; cmp(A6, 0), A6 : bNormalize
    BRC(LINE_CNT(4), DOWN, EQ),                                                     //      ; CH3FLT == 0           -> JP01
    SRW2(CNT1, CNT0, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),                   //      ; CH2FLT = normalize_img(CNT1, CNT0)
    MULS(REGC3, CH2FLT, REGC3),                                                     //      ; C3 = C3 x CH2FLT
    SRLS(REGC3, CONST_VAL(6), REGC3),                                               //      ; C3 = C3 >> 6
    SRLS(REGC3, REGA7, REGC3),                                                      // JP01 ; C3 = C3 >> A7, A7 : ucOvrShift
    MOV(REGC3, CH3FLT),                                                             //      ; CH3FLT = C3, C3 : delta
    ADD(CNT1, REGB2, REGB5),                                                        //      ; B5 = CNT1 + B2, B2 : ucPadSize
    SRW3(REGB5, REGB4, FT_1X1, WRITE, PS_REG, DT_SIGNED, DT_16BIT),                 //      ; CH3FLT WRITE
    CMPS(REGC3, REGB0),                                                             //      ; cmps(C3, B0), B0 : usSeedBase
    BRC(LINE_CNT(25), DOWN, LES),                                                   //      ; C3 <= B0           -> JP02
    SRW0(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH0FLT00 READ  : rs
    CMP(CH0FLT00, CNT0),                                                            //      ; cmp(rs, CNT0)
    BRC(LINE_CNT(2), DOWN, LE),                                                     //      ; rs <= CNT0            -> JP03
    SRW0(CONST_VAL(0), CNT0, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),          //      ; rs = CNT0
    SRW0(CONST_VAL(1), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   // JP03 ; CH0FLT00 READ  : re
    CMP(CH0FLT00, CNT0),                                                            //      ; cmp(re, CNT0)
    BRC(LINE_CNT(2), DOWN, GE),                                                     //      ; re >= CNT0            -> JP04
    SRW0(CONST_VAL(1), CNT0, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),          //      ; re = CNT0
    SRW0(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   // JP04 ; CH0FLT00 READ  : cs
    CMP(CH0FLT00, CNT1),                                                            //      ; cmp(cs, CNT1)
    BRC(LINE_CNT(2), DOWN, LE),                                                     //      ; cs <= CNT1            -> JP05
    SRW0(CONST_VAL(2), CNT1, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),          //      ; cs = CNT1
    SRW0(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   // JP05 ; CH0FLT00 READ  : ce
    CMP(CH0FLT00, CNT1),                                                            //      ; cmp(ce, CNT1)
    BRC(LINE_CNT(2), DOWN, GE),                                                     //      ; ce >= CNT1            -> JP06
    SRW0(CONST_VAL(3), CNT1, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),          //      ; ce = CNT1
    SRW0(CONST_VAL(1), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),  // JP06 ; CH0FLT00 READ  : iGroupedCellCnt
    ADD(CH0FLT00, CONST_VAL(1), CH0FLT00),                                          //      ; CH0FLT00 = CH0FLT00 + 1
    SRW0(CONST_VAL(1), CONST_VAL(0), FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_32BIT), //      ; CH0FLT00 WRITE
    CMP(REGC4, REGC3),                                                              //      ; cmp(C4, C3)
    BRC(LINE_CNT(4), DOWN, GE),                                                     //      ; C4 >= C3              -> JP02
    MOV(REGC3, REGC4),                                                              //      ; C4 = C3
    MOV(CNT0, REGB6),                                                               //      ; B6 = CNT0
    MOV(CNT1, REGB7),                                                               //      ; B7 = CNT1
    
    ELOOP1(),                                                                       // JP02 ;
    ELOOP0(),
    SRW0(CONST_VAL(2), REGC4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),        //      ; CH0FLT00 WRITE : iMaxStrength

    SRW0(CONST_VAL(7), CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),  //      ; CH0FLT00 READ  : usPenCalRangeThr
    MOV(CONST_VAL(0), REGB2),                                                       //      ; B2 = 0
    CMP(REGC4, CH0FLT00),                                                           //      ; cmp(C4, CH0FLT00)
    BRC(LINE_CNT(41), DOWN, LE),                                                    //      ; C4 <= CH0FLT00        -> JP07
    MOV(CONST_VAL(1), REGB2),                                                       //      ; B2 = 1
    SRW0(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),  //      ; CH0FLT00 READ  : ucRowCellMax
    ADD(REGB6, REGC6, REGB6),                                                       //      ; B6 = B6 + C6
    ADD(REGB7, REGC7, REGB7),                                                       //      ; B7 = B7 + C7
    DIV(REGB6, REGB1, REGB4),                                                       //      ; B4 = B6 / B1, B4 : mux_row_cen
    SRL(REGB1, CONST_VAL(1), REGB5),                                                //      ; B5 = B1 >> 1, B5 : mux_row_half
    DIV(CH0FLT00, REGB1, REGC3),                                                    //      ; C3 = CH0FLT00 / B1
    SUB(REGC3, CONST_VAL(1), REGC3),                                                //      ; C3 = C3 - 1, C3 : max_mux_val
    SRW0(CONST_VAL(17), CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),  //      ; CH0FLT00 READ  : ucColumnCellMax
    ADD(REGB4, CONST_VAL(1), REGC4),                                                //      ; C4 = B4 + 1
    MUL(REGC4, REGB1, REGC5),                                                       //      ; C5 = C4 x B1
    SUB(REGC5, REGB6, REGC5),                                                       //      ; C5 = C5 - B6
    CMP(REGC5, REGB5),                                                              //      ; cmp(C5, B5)
    BRC(LINE_CNT(8), DOWN, GT),                                                     //      ; C5 > B5       -> JP08
    CMP(REGB4, REGC3),                                                              //      ; cmp(B4, C3)
    BRC(LINE_CNT(3), DOWN, GE),                                                     //      ; B4 >= C3      -> JP09
    MOV(REGC4, REGA7),                                                              //      ; A7 = C4, A7 : currentRowEnd
    BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; -> JP10
    MOV(REGC3, REGA7),                                                              // JP09 ; A7 = C3
    SUB(REGA7, CONST_VAL(1), REGA6),                                                // JP10 ; A6 = A7 - 1, A6 : currentRowStart
    BRC(LINE_CNT(7), DOWN, AL),                                                     //      ; -> JP11
    CMP(REGB4, CONST_VAL(0)),                                                       // JP08 ; cmp(B4, 0)
    BRC(LINE_CNT(3), DOWN, LE),                                                     //      ; B4 <= 0       -> JP12
    SUB(REGB4, CONST_VAL(1), REGA6),                                                //      ; A6 = B4 - 1
    BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; -> JP13
    MOV(CONST_VAL(0), REGA6),                                                       // JP12 ; A6 = 0
    ADD(REGA6, CONST_VAL(1), REGA7),                                                // JP13 ; A7 = A6 + 1
    
    SLL(REGB1, CONST_VAL(1), REGC2),                                                // JP11 ; C2 = B1<<1
    ADD(REGB7, REGB1, REGC5),                                                       //      ; C5 = B7 + B1
    CMP(REGB7, REGB1),                                                              //      ; cmp(B7, B1)
    BRC(LINE_CNT(4), DOWN, GE),                                                     //      ; B7 >= B1      -> JP14
    MOV(CONST_VAL(0), REGA4),                                                       //      ; A4 = 0, A4 : ucCurrentColumnStart
    MOV(REGC2, REGA5),                                                              //      ; A5 = C2, A5 : ucCurrentColumnEnd
    BRC(LINE_CNT(8), DOWN, AL),                                                     //      ; -> JP07
    CMP(REGC5, REGC1),                                                              // JP14 ; cmp(C5, C1)
    BRC(LINE_CNT(4), DOWN, LE),                                                     //      ; C5 <= C1      -> JP15
    SUB(REGC1, REGC2, REGA4),                                                       //      ; A4 = C1 - C2
    MOV(REGC1, REGA5),                                                              //      ; A5 = C1
    BRC(LINE_CNT(3), DOWN, AL),                                                     //      ; -> JP07
    SUB(REGB7, REGB1, REGA4),                                                       // JP15 ; A4 = B7 - B1
    MOV(REGC5, REGA5),                                                              //      ; A5 = C5
    
    END()                                                                           // JP07 ; end
};

/********************************************************************************
  @brief    Compensation for AKS OPCODE
  */
#ifdef SRAM_OPCODE
int opcode_labelproc[] = 
#else
int opcode_labelproc[] = 
#endif
#if 0
{
    // input A0~B1, loop_cnt C0~C1
    SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : Delta
    SDMA1(REGA1, 0, DMA_SIZE2),                                                     //      ; A1 : map
    SDMA2(REGA2, 0, DMA_SIZE1),                                                     //      ; A2 : label info
    SDMA3(REGA2, 0, DMA_SIZE1),                                                     //      ; 
    
    SRW2(CONST_VAL(2), REGA5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; rs = A5, A5 : row end
    SRW3(CONST_VAL(3), REGA4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; re = A4, A4 : row start
    SRW2(CONST_VAL(4), REGA7, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; cs = A7, A7 : column end
    SRW3(CONST_VAL(5), REGA6, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; ce = A6, A6 : column start
    SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; usValidCellCnt = 0
    SRW3(CONST_VAL(4), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; sValidMaxVal = 0
    
    SLOOP0(0, 0, LOOP_LE, LOOP_REGC0),                                              //      ; row loop
    ADD(CNT0, REGB1, REGA6),                                                        //      ; A6 = CNT0 + B1, B1 : ucPadSize
    SLOOP1(0, 0, LOOP_LE, LOOP_REGC1),                                              //      ; column loop
    ADD(CNT1, REGB1, REGA7),                                                        //      ; A7 = CNT1 + B1, B1 : ucPadSize
    
    SRW0(REGA7, REGA6, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),                  //      ; CH0FLT00 = delta(REGA7, REGA6)
    CMPS(CH0FLT00, REGA3),                                                          //      ; cmps(delta, thresthold), A3 : threshold
    BRC(LINE_CNT(41), DOWN, LTS),                                                   //      ; delta < threshold     -> JP01
    MOV(CONST_VAL(1), CH1FLT),                                                      //      ; CH1FLT = 1, 1 : label_num
    SRW1(REGA7, REGA6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),                //      ; CH1FLT WRITE
    SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),  //      ; CH2FLT READ  : tCoord.x
    SRW3(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),  //      ; CH3FLT READ  : tCoord.y
    MUL(CNT1, CH0FLT00, REGB5),                                                     //      ; B5 = CNT1 x CH0FLT00
    ADD(CH2FLT, REGB5, REGB5),                                                      //      ; B5 = CH2FLT + B5
    SRW2(CONST_VAL(3), REGB5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),        //      ; CH2FLT WRITE
    MUL(CNT0, CH0FLT00, REGB4),                                                     //      ; B4 = CNT0 x CH0FLT00
    ADD(CH3FLT, REGB4, REGB4),                                                      //      ; B4 = CH3FLT + B4
    SRW3(CONST_VAL(4), REGB4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),        //      ; CH3FLT WRITE
    SRW2(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),  //      ; CH2FLT READ  : ulStrength
    SRW3(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),  //      ; CH3FLT READ  : ulExtStrength
    ADD(CH2FLT, CH0FLT00, REGB5),                                                   //      ; B5 = CH2FLT + CH0FLT00
    SRW2(CONST_VAL(5), REGB5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),        //      ; CH2FLT WRITE
    SRW3(CONST_VAL(6), REGB5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),        //      ; CH3FLT WRITE
    SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH2FLT READ  : rs
    SRW3(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH3FLT READ  : re
    CMP(CH2FLT, CNT0),                                                              //      ; cmp(rs, CNT0)
    BRC(LINE_CNT(2), DOWN, LE),                                                     //      ; rs <= CNT0            -> JP02
    SRW2(CONST_VAL(2), CNT0, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),          //      ; rs = CNT0
    CMP(CH3FLT, CNT0),                                                              // JP02 ; cmp(re, CNT0)
    BRC(LINE_CNT(2), DOWN, GE),                                                     //      ; re >= CNT0            -> JP03
    SRW3(CONST_VAL(3), CNT0, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),          //      ; re = CNT0
    SRW2(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   // JP03 ; CH2FLT READ  : cs
    SRW3(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH3FLT READ  : ce
    CMP(CH2FLT, CNT1),                                                              //      ; cmp(cs, CNT1)
    BRC(LINE_CNT(2), DOWN, LE),                                                     //      ; cs <= CNT1            -> JP04
    SRW2(CONST_VAL(4), CNT1, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),          //      ; cs = CNT1
    CMP(CH3FLT, CNT1),                                                              // JP04 ; cmp(ce, CNT1)
    BRC(LINE_CNT(2), DOWN, GE),                                                     //      ; ce >= CNT1            -> JP05
    SRW3(CONST_VAL(5), CNT1, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),          //      ; ce = CNT1
    SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP05 ; CH2FLT READ  : usValidCellCnt
    SRW3(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH3FLT READ  : sValidMaxVal
    ADD(CH2FLT, CONST_VAL(1), CH2FLT),                                              //      ; CH2FLT = CH2FLT + 1
    SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_16BIT), //      ; CH2FLT WRITE
    CMPS(CH3FLT, CH0FLT00),                                                         //      ; cmps(sValidMaxVal, delta)
    BRC(LINE_CNT(4), DOWN, GES),                                                    //      ; sValidMaxVal >= delta -> JP01
    SRW3(CONST_VAL(4), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),       //      ; sValidMaxVal = delta
    SRW2(CONST_VAL(10), CNT0, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; cell r = CNT0
    SRW3(CONST_VAL(11), CNT1, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; cell c = CNT1
    
    ELOOP1(),                                                                       // JP01 ;
    ELOOP0(),
    END()
};
#else
{
    // input A0~B1, loop_cnt C0~C1
    SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : Delta
    SDMA1(REGA1, 0, DMA_SIZE2),                                                     //      ; A1 : map
    SDMA2(REGA2, 0, DMA_SIZE1),                                                     //      ; A2 : label info
    SDMA3(REGA2, 0, DMA_SIZE1),                                                     //      ; 
    
    MOV(CONST_VAL(0), REGB3),                                                       //      ; B3 = 0, B3 : tCoord.x
    MOV(CONST_VAL(0), REGB4),                                                       //      ; B4 = 0, B4 : tCoord.y
    MOV(CONST_VAL(0), REGB5),                                                       //      ; B5 = 0, B5 : ulStrength
    MOV(CONST_VAL(0), REGC3),                                                       //      ; C3 = 0, C3 : usValidCellCnt
    MOV(CONST_VAL(0), REGC4),                                                       //      ; C4 = 0, C4 : sValidMaxVal
    
    SLOOP0(0, 0, LOOP_LE, LOOP_REGC0),                                              //      ; row loop
    ADD(CNT0, REGB1, REGB6),                                                        //      ; B6 = CNT0 + B1, B1 : ucPadSize
    SLOOP1(0, 0, LOOP_LE, LOOP_REGC1),                                              //      ; column loop
    ADD(CNT1, REGB1, REGB7),                                                        //      ; B7 = CNT1 + B1, B1 : ucPadSize
    
    SRW0(REGB7, REGB6, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),                  //      ; CH0FLT00 = delta(REGB7, REGB6)
    CMPS(CH0FLT00, REGA3),                                                          //      ; cmps(delta, thresthold), A3 : threshold
    BRC(LINE_CNT(26), DOWN, LTS),                                                   //      ; delta < threshold     -> JP01
    MOV(CONST_VAL(1), CH1FLT),                                                      //      ; CH1FLT = 1, 1 : label_num
    SRW1(REGB7, REGB6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),                //      ; CH1FLT WRITE
    MULS(CNT1, CH0FLT00, REGB2),                                                    //      ; B2 = CNT1 x CH0FLT00
    ADDS(REGB3, REGB2, REGB3),                                                      //      ; B3 = B3 + B2
    MULS(CNT0, CH0FLT00, REGB2),                                                    //      ; B2 = CNT0 x CH0FLT00
    ADDS(REGB4, REGB2, REGB4),                                                      //      ; B4 = B4 + B2
    ADD(REGB5, CH0FLT00, REGB5),                                                    //      ; B5 = B5 + CH0FLT00
    CMP(REGA4, CNT0),                                                               //      ; cmp(A4, CNT0), A4 : rs
    BRC(LINE_CNT(2), DOWN, LE),                                                     //      ; rs <= CNT0            -> JP02
    MOV(CNT0, REGA4),                                                               //      ; rs = CNT0
    CMP(REGA5, CNT0),                                                               // JP02 ; cmp(A5, CNT0), A5 : re
    BRC(LINE_CNT(2), DOWN, GE),                                                     //      ; re >= CNT0            -> JP03
    MOV(CNT0, REGA5),                                                               //      ; re = CNT0
    CMP(REGA6, CNT1),                                                               // JP03 ; cmp(A6, CNT1), A6 : cs
    BRC(LINE_CNT(2), DOWN, LE),                                                     //      ; cs <= CNT1            -> JP04
    MOV(CNT1, REGA6),                                                               //      ; cs = CNT1
    CMP(REGA7, CNT1),                                                               // JP04 ; cmp(A7, CNT1), A7 : ce
    BRC(LINE_CNT(2), DOWN, GE),                                                     //      ; ce >= CNT1            -> JP05
    MOV(CNT1, REGA7),                                                               //      ; ce = CNT1
    ADD(REGC3, CONST_VAL(1), REGC3),                                                // JP05 ; C3 = C3 + 1
    CMPS(REGC4, CH0FLT00),                                                          //      ; cmps(sValidMaxVal, delta)
    BRC(LINE_CNT(4), DOWN, GES),                                                    //      ; sValidMaxVal >= delta -> JP01
    MOV(CH0FLT00, REGC4),                                                           //      ; sValidMaxVal = delta
    MOV(CNT0, REGC5),                                                               //      ; C5 = CNT0, C5 : tValidMaxPos.r
    MOV(CNT1, REGC6),                                                               //      ; C6 = CNT1, C6 : tValidMaxPos.c
    
    ELOOP1(),                                                                       // JP01 ;
    ELOOP0(),
    
    SRW2(CONST_VAL(2), REGA4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH2FLT WRITE : rs
    SRW3(CONST_VAL(3), REGA5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH3FLT WRITE : re
    SRW2(CONST_VAL(4), REGA6, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH2FLT WRITE : cs
    SRW3(CONST_VAL(5), REGA7, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH3FLT WRITE : ce
    SRW2(CONST_VAL(3), REGC3, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH2FLT WRITE : usValidCellCnt
    SRW2(CONST_VAL(4), REGC4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),          //      ; CH2FLT WRITE : sValidMaxVal
    SRW3(CONST_VAL(11), REGC5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),        //      ; CH3FLT WRITE : tValidMaxPos.r		// tCell_t : c, r
    SRW2(CONST_VAL(10), REGC6, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),        //      ; CH2FLT WRITE : tValidMaxPos.c
    SRW3(CONST_VAL(3), REGB3, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH3FLT WRITE : tCoord.x
    SRW2(CONST_VAL(4), REGB4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH2FLT WRITE : tCoord.y
    SRW3(CONST_VAL(5), REGB5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),        //      ; CH3FLT WRITE : ulStrength
    SRW2(CONST_VAL(6), REGB5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),        //      ; CH2FLT WRITE : ulExtStrength
    
    END()
};
#endif

#if 0
int opcode_labelproc[] = 
{
	RDMAC0(REGA0, DT_SIGNED, 0, BS_1BURST, DM_16BIT),                   //0x2A000049, 
    SDMA0(REGA1, 0, 0),                                                 //0x2C010000,
    SDMA1(REGA2, 0, 0),                                                 //0x2D020000,
    MOV(CONST_VAL(1), REGC3),                                           //0x0E810013,
    
    SLOOP0(0, 0, 0, 0),                                                 //0x20000000,
    SLOOP1(0, 0, 0, 1),                                                 //0x22000001,

    MOV(MEM00, REGA4),                                                  //0x0E200004,
	CMPS(REGA4, REGC5),                                                 //0x180415FF,
    BRC(0xA4, DOWN, LES),                                               //0x2700A409,
    SRW0(CNT1, CNT0, FT_3X3, READ, 0, DT_UNSIGNED, DT_8BIT),            //0x30222180,
    _MAX(CH0FLT00, CH0FLT01, REGB0),                                     //0x1C303108,
    _MAX(CH0FLT03, CH0FLT06, REGB1),                                     //0x1C333609,
    _MAX(REGB0, REGB1, REGB2),                                           //0x1C08090A,
    CMP(REGB2, CONST_VAL(0)),                                           //0x0F0A80FF,
    BRC(0x74, DOWN, EQ),                                                //0x27007401,
    CMP(CH0FLT00, CONST_VAL(0)),                                        //0x0F3080FF,
    BRC(0x0C, DOWN, EQ),                                                //0x27000C01,
    MOV(CH0FLT00, REGB3),                                               //0x0E30000B,
    BRC(0x8, DOWN, AL),                                                 //0x27000800,
    MOV(CONST_VAL(127), REGB3),                                         //0x0EFF000B,
    CMP(CH0FLT01, CONST_VAL(0)),                                        //0x0F3180FF,
    BRC(0x0C, DOWN, EQ),                                                //0x27000C01,
    MOV(CH0FLT01, REGB4),                                               //0x0E31000C,
    BRC(0x08, DOWN, AL),                                                //0x27000800,
    MOV(CONST_VAL(127), REGB4),                                         //0x0EFF000C,
    CMP(CH0FLT03, CONST_VAL(0)),                                        //0x0F3380FF,
    BRC(0x0C, DOWN, EQ),                                                //0x27000C01,
    MOV(CH0FLT03, REGB5),                                               //0x0E33000D,
    BRC(0x08, DOWN, AL),                                                //0x27000800,
    MOV(CONST_VAL(127), REGB5),                                         //0x0EFF000D,
    CMP(CH0FLT06, CONST_VAL(0)),                                        //0x0F3680FF,
    BRC(0x0C, DOWN, EQ),                                                //0x27000C01,
    MOV(CH0FLT06, REGB6),                                               //0x0E36000E,
    BRC(0x08, DOWN, AL),                                                //0x27000800,
    MOV(CONST_VAL(127), REGB6),                                         //0x0EFF000E,
    _MIN(REGB3, REGB4, REGB4),                                           //0x1B0B0C0C,
    _MIN(REGB5, REGB6, REGB5),                                           //0x1B0D0E0D,
    _MIN(REGB4, REGB5, REGB6),                                           //0x1B0C0D0E,
    CMP(REGB6, REGB2),                                                  //0x0F0E0AFF,
    BRC(0x20, DOWN, EQ),                                                //0x27002001,
    MOV(REGB6, CH0FLT00),                                               //0x0E0E0030,
    SRW1(REGB2, REGB6, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),    //0x310A0E48,
    BRC(0x20, DOWN, AL),                                                //0x27002000,
    MOV(REGC3, CH0FLT00),                                               //0x0E130030,
    SRW1(REGC3, REGC3, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),    //0x31131348,
    ADD(REGC3, CONST_VAL(1), REGC3),                                    //0x01138113,
    BRC(0x10, DOWN, AL),                                                //0x27001000,
    MOV(REGB2, CH0FLT00),                                               //0x0E0A0030,
    BRC(0x08, DOWN, AL),                                                //0x27000800,
    MOV(CONST_VAL(0), CH0FLT00),                                        //0x0E800030,
    SRW0(CNT1, CNT0, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),      //0x30222108,
    ELOOP1(),                                                           //0x23000000,
    ELOOP0(),                                                           //0x21000000,

    CMP(REGC3, CONST_VAL(1)),                                           //0x0F1381FF,
    BRC(0xD0, DOWN, LE),                                                //0x2700D005,
    SUB(REGC3, CONST_VAL(1), REGC4),                                    //0x03138114,
    SUB(REGC3, CONST_VAL(1), REGC3),                                    //0x03138113,
    SRW1(REGC3, REGA0, FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),     //0x31130040,
    CMP(REGC3, CH1FLT),                                                 //0x0F1339FF,
    BRC(0x1C, DOWN, EQ),                                                //0x27001C01,
    MOV(CH1FLT, REGB0),                                                 //0x0E390008,
    SRW1(REGB0, REGA0, FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),     //0x31080040,
    CMP(REGB0, CH1FLT),                                                 //0x0F0839FF,
    BRC(0x0C, UP, NE),                                                  //0x27000C12,
    MOV(CH1FLT, REGB0),                                                 //0x0E390008,
    SRW1(REGC3, REGB0, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),    //0x31130848,
    CMP(REGC3, CONST_VAL(1)),                                           //0x0F1381FF,
    BRC(0x2C, UP, GT),                                                  //0x27002C14,
    MOV(CONST_VAL(1), REGB0),                                           //0x0E810008,
    MOV(CONST_VAL(1), REGB1),                                           //0x0E810009,
    SRW1(REGC3, REGA0, FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),     //0x31130040,
    CMP(CH1FLT, REGB0),                                                 //0x0F3908FF,
    BRC(0x10, DOWN, LT),                                                //0x27001006,
    BRC(0x1C, DOWN, GT),                                                //0x27001C04,
    SRW1(REGC3, REGB1, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),    //0x31130948,
    BRC(0x20, DOWN, AL),                                                //0x27002000,
    SRW1(CH1FLT, REGA0, FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),    //0x31390040,
    MOV(CH1FLT, REGB2),                                                 //0x0E39000A,
    SRW1(REGC3, REGB2, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),    //0x31130A48,
    BRC(0x10, DOWN, AL),                                                //0x27001000,
    ADD(REGB1, CONST_VAL(1), REGB1),                                    //0x01098109,
    MOV(CH1FLT, REGB0),                                                 //0x0E390008,
    SRW1(REGC3, REGB1, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),    //0x31130948,
    ADD(REGC3, CONST_VAL(1), REGC3),                                    //0x01138113,
    CMP(REGC3, REGC4),                                                  //0x0F1314FF,
    BRC(0x3C, UP, LE),                                                  //0x27003C15,
    CMP(REGB1, CONST_VAL(15)),                                          //0x0F098FFF,
    BRC(0x08, DOWN, LE),                                                //0x27000805,
    MOV(CONST_VAL(15), REGB1),                                          //0x0E8F0009,

    RDMAC0(REGA1, DT_UNSIGNED, 0, BS_4BURST, DM_8BIT),                  //0x2A01000A,
    WDMAC0(REGA1, DT_UNSIGNED, 0, BS_4BURST, DM_8BIT),                  //0x2B01000A,     // 0x2B01000B, 4bit->8bit
    
    SLOOP0(0, 0, 0, 0),                                                 //0x20000000,
    SLOOP1(0, 0, 0, 1),                                                 //0x22000001,
    MOV(MEM00, REGB0),                                                  //0x0E200008,
    CMP(REGB0, CONST_VAL(0)),                                           //0x0F0880FF,
    BRC(0x18, DOWN, EQ),                                                //0x27001801,
    SRW1(REGB0, REGA0, FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),     //0x31080040,
    CMP(CH1FLT, CONST_VAL(15)),                                         //0x0F398FFF,
    BRC(0x0C, DOWN, GT),                                                //0x27000C04,
    MOV(CH1FLT, MEM00),                                                 //0x0E390020,
    BRC(0x08, DOWN, AL),                                                //0x27000800,
    MOV(CONST_VAL(0), MEM00),                                           //0x0E800020,
    ELOOP1(),                                                           //0x23000000,
    ELOOP0(),                                                           //0x21000000,

    CLR(CLR_WDMA0),                                                     //0x38000002,
    BRC(0x08, DOWN, AL),                                                //0x27000800,
    MOV(CONST_VAL(0), REGB1),                                           //0x0E800009,
    END()                                                               //0x37000000
};
#endif

/********************************************************************************
  @brief    markboundary OPCODE
  */
#ifdef SRAM_OPCODE
int opcode_markboundary[] = 
#else
int opcode_markboundary[] = 
#endif
#if 1
{
    SDMA0(REGA0,0,DMA_SIZE2),                                                       //      ; REGA0 : Label Buffer 
    SDMA1(REGA1,0,DMA_SIZE2),                                                       //      ; REGA1 : Delta Buffer
    SDMA2(REGA2,0,DMA_SIZE1),                                                       //      ; REGA2 : tTable Buffer
    SDMA3(REGA2,0,DMA_SIZE1),                                                       //      ; REGA2 : tTable Buffer
	
    SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH2FLT READ : rs
    SRW3(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH3FLT READ : re
    MOV(CH2FLT, REGA4),                                                             //      ; A4 = CH2FLT, A4 : rs
    MOV(CH3FLT, REGA5),                                                             //      ; A5 = CH3FLT, A5 : re
    SRW2(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH2FLT READ : rs
    SRW3(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH3FLT READ : re
    MOV(CH2FLT, REGA6),                                                             //      ; A6 = CH2FLT, A6 : cs
    MOV(CH3FLT, REGA7),                                                             //      ; A7 = CH3FLT, A7 : ce
	
    SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    // 		; CH2FLT READ : tCoord.x
    SRW3(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH3FLT READ : tCoord.y
    MOV(CH2FLT, REGB3),                                                             //      ; B3 = CH2FLT, B3 : tCoord.x
    MOV(CH3FLT, REGB4),                                                             //      ; B4 = CH3FLT, B4 : tCoord.y
    SRW2(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),  //      ; CH2FLT READ : ulStrength
    SRW3(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),  //      ; CH3FLT READ : ulExtStrength
    MOV(CH2FLT, REGB5),                                                             //      ; B5 = CH2FLT, B5 : ulStrength
    MOV(CH3FLT, REGC4),                                                             //      ; C4 = CH3FLT, C4 : ulExtStrength
    SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH2FLT READ : usValidCellCnt
    MOV(CH2FLT, REGC5),                                                             //      ; C5 = 0, C5 : usValidCellCnt

    SLOOP0(0, 0, LOOP_LE, LOOP_REGC0),                                              //      ; row loop
    ADD(CNT0, REGB1, REGB6),                                                        //      ; B6 = CNT0 + B1, B1 : ucPadSize
    SLOOP1(0, 0, LOOP_LE, LOOP_REGC1),                                              //      ; column loop
    ADD(CNT1, REGB1, REGB7),                                                        //      ; B7 = CNT1 + B1, B1 : ucPadSize
    
    SRW0(REGB7, REGB6, FT_3X3, READ, PS_REG, DT_UNSIGNED, DT_8BIT),                 //      ; CH0FLT = label(REGB7, REGB6)
    CMP(CH0FLT04, CONST_VAL(0)),                                                    //      ; cmp(rLable_val, 0)
    BRC(LINE_CNT(49), DOWN, NE),                                                    //      ; if(rLabel_val != 0) -> JP00
    CMP(CH0FLT01, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT01, 1)
    BRC(LINE_CNT(18), DOWN, EQ),                                                    //      ; if(CH0FLT01 == 1) -> JP01
    CMP(CH0FLT03, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT03, 1)
    BRC(LINE_CNT(16), DOWN, EQ),                                                    //      ; if(CH0FLT03 == 1) -> JP01
    CMP(CH0FLT05, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT05, 1)
    BRC(LINE_CNT(14), DOWN, EQ),                                                    //      ; if(CH0FLT05 == 1) -> JP01
    CMP(CH0FLT07, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT07, 1)
    BRC(LINE_CNT(12), DOWN, EQ),                                                    //      ; if(CH0FLT07 == 1) -> JP01
	
    CMP(REGA3, CONST_VAL(1)),							                            //	    ; cmp(REGA3, 1)
    BRC(LINE_CNT(39), DOWN, NE),						                            //	    ; if(REGA3 != 1) -> JP00
    CMP(CH0FLT00, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT00, 1)
    BRC(LINE_CNT(8), DOWN, EQ),                                                     //      ; if(CH0FLT00 == 1) -> JP01
    CMP(CH0FLT02, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT02, 1)
    BRC(LINE_CNT(6), DOWN, EQ),                                                     //      ; if(CH0FLT02 == 1) -> JP01
    CMP(CH0FLT06, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT06, 1)
    BRC(LINE_CNT(4), DOWN, EQ),                                                     //      ; if(CH0FLT06 == 1) -> JP01
    CMP(CH0FLT08, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT08, 1)
    BRC(LINE_CNT(2), DOWN, EQ),                                                     //      ; if(CH0FLT08 == 1) -> JP01
    BRC(LINE_CNT(30), DOWN, AL),                                        	        //      ;                   -> JP00

    SRW1(REGB7, REGB6, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),                  // JP01 ; CH1FLT = Delta(REGB7, REGB6)
	CMPS(CH1FLT, CONST_VAL(0)),	                                                    //      ; cmps(delta, 0)
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; if(delta < 0) 	-> JP06
	MOV(CH1FLT, REGB0),                                                             //      ; B0 = delta
    BRC(LINE_CNT(2), DOWN, AL),                                        	        	//      ;                   -> JP07
	MOV(CONST_VAL(0), REGB0),                                                       // JP06 ; B0 = 0
    MULS(CNT1, REGB0, REGB2),                                                      	// JP07 ; REGB2 = tCellPos.c * delta
    ADDS(REGB3, REGB2, REGB3),							                            //	    ; REGB3 = REGB3 + REGB2;
    MULS(CNT0, REGB0, REGB2),                                                      	//      ; REGB2 = tCellPos.r * delta
    ADDS(REGB4, REGB2, REGB4),							                            //	    ; REGB4 = REGB4 + REGB2;
    ADD(REGC4, REGB0, REGC4),                                                      	//      ; REGC4 = REGC4 + delta;
	
    CMP(REGC2, CONST_VAL(1)),                                                       //      ; CMP(Boundary, 1)
    BRC(LINE_CNT(15), DOWN, EQ),                                                    //      ; if(Boundary == 1) -> JP02
    ADD(REGB5, REGB0, REGB5),							                           	//	    ; REGB5 = REGB5 + delta;
    ADD(REGC5, CONST_VAL(1), REGC5),                                                //      ; REGC5 = REGC5 + 1
    CMP(REGA4, CNT0),                                                               //      ; cmp(A4, CNT0), A4 : rs
    BRC(LINE_CNT(2), DOWN, LE),                                                     //      ; rs <= CNT0            -> JP03
    MOV(CNT0, REGA4),                                                               //      ; rs = CNT0
    CMP(REGA5, CNT0),                                                               // JP03 ; cmp(A5, CNT0), A5 : re
    BRC(LINE_CNT(2), DOWN, GE),                                                     //      ; re >= CNT0            -> JP04
    MOV(CNT0, REGA5),                                                               //      ; re = CNT0
    CMP(REGA6, CNT1),                                                               // JP04 ; cmp(A6, CNT1), A6 : cs
    BRC(LINE_CNT(2), DOWN, LE),                                                     //      ; cs <= CNT1            -> JP05
    MOV(CNT1, REGA6),                                                               //      ; cs = CNT1
    CMP(REGA7, CNT1),                                                               // JP05 ; cmp(A7, CNT1), A7 : ce
    BRC(LINE_CNT(2), DOWN, GE),                                                     //      ; ce >= CNT1            -> JP02
    MOV(CNT1, REGA7),                                                               //      ; ce = CNT1
    
    MOV(REGC3, CH0FLT00),                                                           // JP02 ; CH0FLT00 = LABEL_BOUNDARY_MARKER
    SRW0(REGB7, REGB6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),                //      ; label(REGB7, REGB6) = LABEL_BOUNDARY_MARKER
    ELOOP1(),                                                                       // JP00
    ELOOP0(),                                                                       //
    
    SRW2(CONST_VAL(2), REGA4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH2FLT WRITE : rs
    SRW3(CONST_VAL(3), REGA5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH3FLT WRITE : re
    SRW2(CONST_VAL(4), REGA6, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH2FLT WRITE : cs
    SRW3(CONST_VAL(5), REGA7, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH3FLT WRITE : ce
    SRW2(CONST_VAL(3), REGC5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH2FLT WRITE : usValidCellCnt
    SRW3(CONST_VAL(3), REGB3, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH3FLT WRITE : tCoord.x
    SRW2(CONST_VAL(4), REGB4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH2FLT WRITE : tCoord.y
    SRW3(CONST_VAL(5), REGB5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),        //      ; CH3FLT WRITE : ulStrength
    SRW2(CONST_VAL(6), REGC4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),        //      ; CH2FLT WRITE : ulExtStrength
 
    SLOOP0(0, 0, LOOP_LE, LOOP_REGC0),                                              //      ; row loop
    ADD(CNT0, REGB1, REGB6),                                                        //      ; B6 = CNT0 + B1, B1 : ucPadSize
    SLOOP1(0, 0, LOOP_LE, LOOP_REGC1),                                              //      ; column loop
    ADD(CNT1, REGB1, REGB7),                                                        //      ; B7 = CNT1 + B1, B1 : ucPadSize
	
	SRW0(REGB7, REGB6, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),                 //      ; CH0FLT = label(REGB7, REGB6)
	CMP(CH0FLT00, REGC3),                                                    		//      ; cmp(CH0FLT00, LABEL_BOUNDARY_MARKER)
	BRC(LINE_CNT(3), DOWN, NE),                                                    	//      ; if(CH0FLT00 != LABEL_BOUNDARY_MARKER) -> JP00
	MOV(CONST_VAL(1), CH0FLT00),                                                    // 	    ; CH0FLT00 = 1
	SRW0(REGB7, REGB6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT), 				//      ; label(REGB7, REGB6) = 1
	
    ELOOP1(),                                                                       // JP00
    ELOOP0(),                                                                       //
	
    END()
};
#else
{
    SDMA0(REGA0,0,DMA_SIZE2),                                                       //      ; REGA0 : Label Buffer 
    SDMA1(REGA1,0,DMA_SIZE2),                                                       //      ; REGA1 : Delta Buffer
    SDMA2(REGA2,0,DMA_SIZE1),                                                       //      ; REGA2 : tTable Buffer
    SDMA3(REGA2,0,DMA_SIZE1),                                                       //      ; REGA2 : tTable Buffer
    
    SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH2FLT READ : rs
    SRW3(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH3FLT READ : re
    MOV(CH2FLT, REGA4),                                                             //      ; A4 = CH2FLT, A4 : rs
    MOV(CH3FLT, REGA5),                                                             //      ; A5 = CH3FLT, A5 : re
    SRW2(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH2FLT READ : rs
    SRW3(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH3FLT READ : re
    MOV(CH2FLT, REGA6),                                                             //      ; A6 = CH2FLT, A6 : cs
    MOV(CH3FLT, REGA7),                                                             //      ; A7 = CH3FLT, A7 : ce
    SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH2FLT READ : tCoord.x
    SRW3(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH3FLT READ : tCoord.y
    MOV(CH2FLT, REGB3),                                                             //      ; B3 = CH2FLT, B3 : tCoord.x
    MOV(CH3FLT, REGB4),                                                             //      ; B4 = CH3FLT, B4 : tCoord.y
    SRW2(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),  //      ; CH2FLT READ : ulStrength
    SRW3(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),  //      ; CH3FLT READ : ulExtStrength
    MOV(CH2FLT, REGB5),                                                             //      ; B5 = CH2FLT, B5 : ulStrength
    MOV(CH3FLT, REGC4),                                                             //      ; C4 = CH3FLT, C4 : ulExtStrength
    SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH2FLT READ : usValidCellCnt
    MOV(CH2FLT, REGC5),                                                             //      ; C5 = 0, C5 : usValidCellCnt

    SLOOP0(0, 0, LOOP_LE, LOOP_REGC0),                                              //      ; row loop
    ADD(CNT0, REGB1, REGB6),                                                        //      ; B6 = CNT0 + B1, B1 : ucPadSize
    SLOOP1(0, 0, LOOP_LE, LOOP_REGC1),                                              //      ; column loop
    ADD(CNT1, REGB1, REGB7),                                                        //      ; B7 = CNT1 + B1, B1 : ucPadSize
    
    SRW0(REGB7, REGB6, FT_3X3, READ, PS_REG, DT_UNSIGNED, DT_8BIT),                 //      ; CH0FLT = label(REGB7, REGB6)
    CMP(CH0FLT04, CONST_VAL(0)),                                                    //      ; cmp(rLable_val, 0)
    BRC(LINE_CNT(44), DOWN, NE),                                                    //      ; if(rLabel_val != 0) -> JP00
    CMP(CH0FLT01, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT01, 1)
    BRC(LINE_CNT(18), DOWN, EQ),                                                    //      ; if(CH0FLT01 == 1) -> JP01
    CMP(CH0FLT03, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT03, 1)
    BRC(LINE_CNT(16), DOWN, EQ),                                                    //      ; if(CH0FLT03 == 1) -> JP01
    CMP(CH0FLT05, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT05, 1)
    BRC(LINE_CNT(14), DOWN, EQ),                                                    //      ; if(CH0FLT05 == 1) -> JP01
    CMP(CH0FLT07, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT07, 1)
    BRC(LINE_CNT(12), DOWN, EQ),                                                    //      ; if(CH0FLT07 == 1) -> JP01
	
    CMP(REGA3, CONST_VAL(1)),							                            //	    ; cmp(REGA3, 1)
    BRC(LINE_CNT(34), DOWN, NE),						                            //	    ; if(REGA3 != 1) -> JP00
    CMP(CH0FLT00, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT00, 1)
    BRC(LINE_CNT(8), DOWN, EQ),                                                     //      ; if(CH0FLT00 == 1) -> JP01
    CMP(CH0FLT02, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT02, 1)
    BRC(LINE_CNT(6), DOWN, EQ),                                                     //      ; if(CH0FLT02 == 1) -> JP01
    CMP(CH0FLT06, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT06, 1)
    BRC(LINE_CNT(4), DOWN, EQ),                                                     //      ; if(CH0FLT06 == 1) -> JP01
    CMP(CH0FLT08, CONST_VAL(1)),                                                    //      ; cmp(CH0FLT08, 1)
    BRC(LINE_CNT(2), DOWN, EQ),                                                     //      ; if(CH0FLT08 == 1) -> JP01
    BRC(LINE_CNT(25), DOWN, AL),                                        	        //      ;                   -> JP00

    SRW1(REGB7, REGB6, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),                  // JP01 ; CH1FLT = Delta(REGB7, REGB6)
    MULS(CNT1, CH1FLT, REGB2),                                                      //      ; REGB2 = tCellPos.c * delta
    ADDS(REGB3, REGB2, REGB3),							                            //	    ; REGB3 = REGB3 + REGB2;
    MULS(CNT0, CH1FLT, REGB2),                                                      //      ; REGB2 = tCellPos.r * delta
    ADDS(REGB4, REGB2, REGB4),							                            //	    ; REGB4 = REGB4 + REGB2;
    ADD(REGC4, CH1FLT, REGC4),                                                      //      ; REGC4 = CH1FLT + REGC4;
    
    CMP(REGC2, CONST_VAL(1)),                                                       //      ; CMP(Boundary, 1)
    BRC(LINE_CNT(15), DOWN, EQ),                                                    //      ; if(Boundary == 1) -> JP02
    ADD(REGB5, CH1FLT, REGB5),							                            //	    ; REGB5 = REGB5 + CH1FLT;
    ADD(REGC5, CONST_VAL(1), REGC5),                                                //      ; REGC5 = REGC5 + 1
    CMP(REGA4, CNT0),                                                               //      ; cmp(A4, CNT0), A4 : rs
    BRC(LINE_CNT(2), DOWN, LE),                                                     //      ; rs <= CNT0            -> JP03
    MOV(CNT0, REGA4),                                                               //      ; rs = CNT0
    CMP(REGA5, CNT0),                                                               // JP03 ; cmp(A5, CNT0), A5 : re
    BRC(LINE_CNT(2), DOWN, GE),                                                     //      ; re >= CNT0            -> JP04
    MOV(CNT0, REGA5),                                                               //      ; re = CNT0
    CMP(REGA6, CNT1),                                                               // JP04 ; cmp(A6, CNT1), A6 : cs
    BRC(LINE_CNT(2), DOWN, LE),                                                     //      ; cs <= CNT1            -> JP05
    MOV(CNT1, REGA6),                                                               //      ; cs = CNT1
    CMP(REGA7, CNT1),                                                               // JP05 ; cmp(A7, CNT1), A7 : ce
    BRC(LINE_CNT(2), DOWN, GE),                                                     //      ; ce >= CNT1            -> JP02
    MOV(CNT1, REGA7),                                                               //      ; ce = CNT1
    
    MOV(REGC3, CH0FLT00),                                                           // JP02 ; CH0FLT00 = LABEL_BOUNDARY_MARKER
    SRW0(REGB7, REGB6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),                //      ; label(REGB7, REGB6) = LABEL_BOUNDARY_MARKER
    ELOOP1(),                                                                       // JP00
    ELOOP0(),                                                                       //
    
//    SRW2(CONST_VAL(2), REGA4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH2FLT WRITE : rs
//    SRW3(CONST_VAL(3), REGA5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH3FLT WRITE : re
//    SRW2(CONST_VAL(4), REGA6, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH2FLT WRITE : cs
//    SRW3(CONST_VAL(5), REGA7, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),         //      ; CH3FLT WRITE : ce
    SRW2(CONST_VAL(3), REGC5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH2FLT WRITE : usValidCellCnt
    SRW3(CONST_VAL(3), REGB3, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH3FLT WRITE : tCoord.x
    SRW2(CONST_VAL(4), REGB4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH2FLT WRITE : tCoord.y
    SRW3(CONST_VAL(5), REGB5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),        //      ; CH3FLT WRITE : ulStrength
    SRW2(CONST_VAL(6), REGC4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),        //      ; CH2FLT WRITE : ulExtStrength
    
    END()
};
#endif

/********************************************************************************
  @brief    Coordinate OPCODE
  */
#ifdef SRAM_OPCODE
int opcode_coordproc[] = 
#else
int opcode_coordproc[] = 
#endif
{
    // Input : A0~A6, C0~C3, Internal variables : B0~B7, Coordinate Info : A7, B6~B7, C4~C7
    // REGA7: ucIdMappedCnt, REGB6: tPastPos[0].tXY.x, REGB7: tPastPos[0].tXY.y, 
    // REGC4: tPos.vusS, REGC5: tPos.vusR, REGC6: tPos.tXY.x, REGC7: tPos.tXY.y,
    SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
    SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA2(REGA1, 0, DMA_SIZE1),                                                     //      ; A1 : label info
    SDMA3(REGA1, 0, DMA_SIZE1),                                                     //      ; 
	
	SUBS(CONST_VAL(0), CONST_VAL(1), REGC6),										//		; REGC6 = 0 - 1
    
    SRW2(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),  //      ; CH2FLT READ : ulStrength
    MOV(CH2FLT, REGC4),                                                             //      ; REGC4 = tPos.vusS
    CMP(REGC4, CONST_VAL(0)),                                                       //      ; cmp(ulStrength, 0)
    BRC(LINE_CNT(138), DOWN, LE),                                                   //      ; ulStrength <= 0                            -> JP00	// line connect use o
//    BRC(LINE_CNT(173), DOWN, LE),                                                   //      ; ulStrength <= 0                            -> JP04	// line connect use x
    
    // Calculate Position
    SRW0(CONST_VAL(36), CH2FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH0FLT WRITE : tOrgPos.vusS = ulStrength
    SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH2FLT READ  : tCoord.x
    SRW3(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),  //      ; CH3FLT READ  : ulExtStrength
    SLLS(CH2FLT, REGA2, REGB0),                                                     //      ; REGB0 = tCoord.x << POS_BOOST_SHIFT_
    DIVS(REGB0, CH3FLT, REGC6),                                                     //      ; REGC6 = REGB0 / ulExtStrength : tPos.tXY.x
    SRW0(CONST_VAL(16), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.x = tPos.tXY.x
    SRW2(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH2FLT READ  : tCoord.y
    SLLS(CH2FLT, REGA2, REGB0),                                                     //      ; REGB0 = tCoord.y << POS_BOOST_SHIFT_
    DIVS(REGB0, CH3FLT, REGB0),                                                     //      ; REGB0 = REGB0 / ulExtStrength
    SLL(REGA6, REGA2, REGB1),                                                       //      ; REGB1 = ucCoordiRowStart << POS_BOOST_SHIFT_
    ADDS(REGB0, REGB1, REGC7),                                                      //      ; REGC7 = tPos.tXY.y + REGB1 : tPos.tXY.y
    SRW0(CONST_VAL(17), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.y = tPos.tXY.y
    SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),     //      ; CH2FLT READ  : tValidRect.rs
    SRW3(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),     //      ; CH3FLT READ  : tValidRect.re
    SRW0(CONST_VAL(6), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),         //      ; CH0FLT WRITE : rect.rs = tValidRect.rs
    SRW1(CONST_VAL(7), CH3FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),         //      ; CH1FLT WRITE : rect.re = tValidRect.re
    SRW2(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),     //      ; CH2FLT READ  : tValidRect.cs
    SRW3(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),     //      ; CH3FLT READ  : tValidRect.ce
    SRW0(CONST_VAL(8), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),         //      ; CH0FLT WRITE : rect.cs = tValidRect.cs
    SRW1(CONST_VAL(9), CH3FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),         //      ; CH1FLT WRITE : rect.ce = tValidRect.ce
    SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH2FLT READ  : usValidCellCnt
    SRW3(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT),    //      ; CH3FLT READ  : sValidMaxVal
    MOV(CH2FLT, REGC5),                                                             //      ; REGC5 = tPos.vusR
    SRW0(CONST_VAL(37), CH2FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH0FLT WRITE : tOrgPos.vusR = usValidCellCnt
    SRW1(CONST_VAL(10), CH3FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH1FLT WRITE : MaxDelta = sValidMaxVal
	
	// Calculate Edge
    SDMA2(REGC3, 0, DMA_SIZE2),                                                     //      ; C3 : pen edge
    SDMA3(REGC3, 0, DMA_SIZE2),                                                     //      ;
	CMP(REGC2, CONST_VAL(LOCAL_MODE)),                                              //      ; cmp(mode, LOCAL_MODE)	: REGC2 = mode
	BRC(LINE_CNT(48), DOWN, NE),													//      ; mode != LOCAL_MODE                      	-> JP28
	SRW2(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH2FLT READ  : tEdgePenSetVal.left_th
	CMPS(REGC6, CH2FLT),                                              				//      ; cmps(x, tEdgePenSetVal.left_th)
	BRC(LINE_CNT(10), DOWN, GES),													//      ; x >= tEdgePenSetVal.left_th              	-> JP29
	SRW3(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH3FLT READ  : tEdgePenSetVal.left_mul
	MOV(CH2FLT, REGB0),                                                           	//      ; REGB0 = EdgePenSetVal.left_th
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH2FLT READ  : tEdgePenSetVal.left_SR
	SUBS(REGB0, REGC6, REGB2),                                               		//      ; REGB2 = EdgePenSetVal.left_th - x
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.left_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.left_SR
	SUBS(REGB0, REGB2, REGC6),                                               		//      ; x = EdgePenSetVal.left_th - REGB2
    SRW0(CONST_VAL(16), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.x = x
	BRC(LINE_CNT(12), DOWN, AL),                                                   	//      ; Always        							-> JP30
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP29 ; CH2FLT READ  : tEdgePenSetVal.right_th
	SUBS(REGC0, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalXRes - tEdgePenSetVal.right_th
	CMPS(REGC6, REGB0),                                              				//      ; cmps(x, REGB0)
	BRC(LINE_CNT(8), DOWN, LES),													//      ; x <= REGB0              					-> JP30
	SRW3(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH3FLT READ  : tEdgePenSetVal.right_mul
	SRW2(CONST_VAL(15), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH2FLT READ  : tEdgePenSetVal.right_SR
	SUBS(REGC6, REGB0, REGB2),                                               		//      ; REGB2 = x - REGB0
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.right_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.right_SR
	ADDS(REGB0, REGB2, REGC6),                                               		//      ; x = REGB0 + REGB2
    SRW0(CONST_VAL(16), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.x = x
	SRW2(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP30 ; CH2FLT READ  : tEdgePenSetVal.top_th
	CMPS(REGC7, CH2FLT),                                              				//      ; cmps(y, tEdgePenSetVal.top_th)
	BRC(LINE_CNT(10), DOWN, GES),													//      ; y >= tEdgePenSetVal.top_th              	-> JP31
	SRW3(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH3FLT READ  : tEdgePenSetVal.top_mul
	MOV(CH2FLT, REGB0),                                                           	//      ; REGB0 = EdgePenSetVal.top_th
	SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   //      ; CH2FLT READ  : tEdgePenSetVal.top_SR
	SUBS(REGB0, REGC7, REGB2),                                               		//      ; REGB2 = EdgePenSetVal.top_th - y
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.top_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.top_SR
	SUBS(REGB0, REGB2, REGC7),                                               		//      ; y = EdgePenSetVal.top_th - REGB2
    SRW0(CONST_VAL(17), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.y = y
	BRC(LINE_CNT(61), DOWN, AL),                                                   	//      ; Always        							-> JP32
	SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP31 ; CH2FLT READ  : tEdgePenSetVal.bottom_th
	SUBS(REGC1, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalYRes - tEdgePenSetVal.bottom_th
	CMPS(REGC7, REGB0),                                              				//      ; cmps(y, REGB0)
	BRC(LINE_CNT(57), DOWN, LES),													//      ; y <= REGB0              					-> JP32
	SRW3(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  	//      ; CH3FLT READ  : tEdgePenSetVal.bottom_mul
	SRW2(CONST_VAL(7), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  	//      ; CH2FLT READ  : tEdgePenSetVal.bottom_SR
	SUBS(REGC7, REGB0, REGB2),                                               		//      ; REGB2 = y - REGB0
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.bottom_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.bottom_SR
	ADDS(REGB0, REGB2, REGC7),                                               		//      ; y = REGB0 + REGB2
    SRW0(CONST_VAL(17), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.y = y
	BRC(LINE_CNT(49), DOWN, AL),                                                   	//      ; Always        							-> JP32
	CMP(REGC2, CONST_VAL(LOCAL_HOVER_MODE)),                                        // JP28 ; cmp(mode, LOCAL_HOVER_MODE)
	BRC(LINE_CNT(47), DOWN, NE),													//      ; mode != LOCAL_HOVER_MODE               	-> JP32
	SRW2(CONST_VAL(12), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH2FLT READ  : tEdgePenSetVal.left_hover_th
	CMPS(REGC6, CH2FLT),                                              				//      ; cmps(x, tEdgePenSetVal.left_hover_th)
	BRC(LINE_CNT(10), DOWN, GES),													//      ; x >= tEdgePenSetVal.left_hover_th        	-> JP33
	SRW3(CONST_VAL(26), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH3FLT READ  : tEdgePenSetVal.left_hover_mul
	MOV(CH2FLT, REGB0),                                                           	//      ; REGB0 = EdgePenSetVal.left_hover_th
	SRW2(CONST_VAL(27), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH2FLT READ  : tEdgePenSetVal.left_hover_SR
	SUBS(REGB0, REGC6, REGB2),                                               		//      ; REGB2 = EdgePenSetVal.left_hover_th - x
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.left_hover_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.left_hover_SR
	SUBS(REGB0, REGB2, REGC6),                                               		//      ; x = EdgePenSetVal.left_hover_th - REGB2
    SRW0(CONST_VAL(16), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.x = x
	BRC(LINE_CNT(12), DOWN, AL),                                                   	//      ; Always        							-> JP34
	SRW2(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP33 ; CH2FLT READ  : tEdgePenSetVal.right_hover_th
	SUBS(REGC0, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalXRes - tEdgePenSetVal.right_hover_th
	CMPS(REGC6, REGB0),                                              				//      ; cmps(x, REGB0)
	BRC(LINE_CNT(8), DOWN, LES),													//      ; x <= REGB0              					-> JP34
	SRW3(CONST_VAL(30), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH3FLT READ  : tEdgePenSetVal.right_hover_mul
	SRW2(CONST_VAL(31), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH2FLT READ  : tEdgePenSetVal.right_hover_SR
	SUBS(REGC6, REGB0, REGB2),                                               		//      ; REGB2 = x - REGB0
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.right_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.right_SR
	ADDS(REGB0, REGB2, REGC6),                                               		//      ; x = REGB0 + REGB2
    SRW0(CONST_VAL(16), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.x = x
	SRW2(CONST_VAL(8), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP34 ; CH2FLT READ  : tEdgePenSetVal.top_hover_th
	CMPS(REGC7, CH2FLT),                                              				//      ; cmps(y, tEdgePenSetVal.top_hover_th)
	BRC(LINE_CNT(10), DOWN, GES),													//      ; y >= tEdgePenSetVal.top_hover_th              	-> JP35
	SRW3(CONST_VAL(18), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH3FLT READ  : tEdgePenSetVal.top_hover_mul
	MOV(CH2FLT, REGB0),                                                           	//      ; REGB0 = EdgePenSetVal.top_hover_th
	SRW2(CONST_VAL(19), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH2FLT READ  : tEdgePenSetVal.top_hover_SR
	SUBS(REGB0, REGC7, REGB2),                                               		//      ; REGB2 = EdgePenSetVal.top_hover_th - y
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.top_hover_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.top_hover_SR
	SUBS(REGB0, REGB2, REGC7),                                               		//      ; y = EdgePenSetVal.top_hover_th - REGB2
    SRW0(CONST_VAL(17), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.y = y
	BRC(LINE_CNT(12), DOWN, AL),                                                   	//      ; Always        							-> JP32
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // JP35 ; CH2FLT READ  : tEdgePenSetVal.bottom_hover_th
	SUBS(REGC1, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalYRes - tEdgePenSetVal.bottom_hover_th
	CMPS(REGC7, REGB0),                                              				//      ; cmps(y, REGB0)
	BRC(LINE_CNT(8), DOWN, LES),													//      ; y <= REGB0              					-> JP32
	SRW3(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	//      ; CH3FLT READ  : tEdgePenSetVal.bottom_hover_mul
	SRW2(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	//      ; CH2FLT READ  : tEdgePenSetVal.bottom_hover_SR
	SUBS(REGC7, REGB0, REGB2),                                               		//      ; REGB2 = y - REGB0
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.bottom_hover_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.bottom_hover_SR
	ADDS(REGB0, REGB2, REGC7),                                               		//      ; y = REGB0 + REGB2
    SRW0(CONST_VAL(17), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.y = y

    // Mapped Count
    SDMA2(REGA0, 0, DMA_SIZE2),                                                     // JP32 ; A0 : coord info
    SDMA3(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SRW0(CONST_VAL(124), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), //      ; CH0FLT READ : ucIdMappedCnt
    MOV(CH0FLT00, REGA7),                                                           //      ; REGA7 = ucIdMappedCnt
    CMP(REGA7, REGA3),                                                              //      ; cmp(ucIdMappedCnt, COORD_HISTORY_NUM)
    BRC(LINE_CNT(2), DOWN, GE),                                                     //      ; ucIdMappedCnt >= COORD_HISTORY_NUM         -> JP01
    ADD(REGA7, CONST_VAL(1), REGA7),                                                //      ; REGA7 = ucIdMappedCnt + 1
    CMP(REGA7, CONST_VAL(1)),                                                       // JP01 ; cmp(ucIdMappedCnt, 1)
    BRC(LINE_CNT(3), DOWN, NE),                                                     //      ; ucIdMappedCnt != 1                         -> JP02
    SRW2(CONST_VAL(6), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH2FLT WRITE : tFirstPos.x = tPos.tXY.x
    SRW3(CONST_VAL(7), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH3FLT WRITE : tFirstPos.y = tPos.tXY.y
	MOV(CONST_VAL(0), REGB6),                                                       // JP02 ; cIsbefor = 0
	BRC(LINE_CNT(39), DOWN, AL),                                                    //      ; Always			                         -> JP03
	
	// Line connect
	SDMA2(REGA0, 0, DMA_SIZE2),                                                     // JP00 ; A0 : coord info
    SDMA3(REGA0, 0, DMA_SIZE2),                                                     //      ;
	SRW0(CONST_VAL(124), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), // 		; CH0FLT READ : ucIdMappedCnt
	SRW1(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // 		; CH1FLT READ : tPastPos[0].vusR
    MOV(CH0FLT00, REGA7),                                                           //      ; REGA7 = ucIdMappedCnt
	CMP(CH1FLT, CONST_VAL(0)),                                             			// 	 	; cmp(tPastPos[0].vusR, 0)
	BRC(LINE_CNT(29), DOWN, LE),													//      ; tPastPos[0].vusR <= 0                      -> JP04
	CMP(REGC2, CONST_VAL(LOCAL_MODE)),                                              // 		; cmp(mode, LOCAL_MODE)	: REGC2 = mode
	BRC(LINE_CNT(27), DOWN, NE),													//      ; mode != LOCAL_MODE                    	 -> JP04
	CMP(REGA7, CONST_VAL(3)),                                             			// 		; cmp(ucIdMappedCnt, 3)
	BRC(LINE_CNT(25), DOWN, LE),													//      ; ucIdMappedCnt <= 3                    	 -> JP04
	CMPS(REGB6, CONST_VAL(1)),                                             			// 		; cmps(cIsbefor, 1)
	BRC(LINE_CNT(4), DOWN, GES),													//      ; cIsbefor >= 1                    	 		 -> JP05
	BRC(LINE_CNT(7), DOWN, AL),                                                     //      ; Always			                         -> JP06	// LHB check x
//	CMP(REGB7, CONST_VAL(PARTIAL_PEN_COORD1)),                                        // 		; cmp(g_RetVal, PARTIAL_PEN_COORD1)						// LHB check o
	BRC(LINE_CNT(2), DOWN, NE),														//      ; g_RetVal != PARTIAL_PEN_COORD1               -> JP05
	BRC(LINE_CNT(5), DOWN, AL),                                                     //      ; Always			                         -> JP06
	CMPS(REGB6, REGA4),                                             				// JP05 ; cmps(cIsbefor, REGA4) : A4 = connect_count
	BRC(LINE_CNT(18), DOWN, GES),													//      ; cIsbefor >= connect_count        	 		 -> JP04
	CMPS(REGB6, CONST_VAL(0)),                                             			// 		; cmps(cIsbefor, 0)
	BRC(LINE_CNT(16), DOWN, LES),													//      ; cIsbefor <= 0                    	 		 -> JP04
	
	MOV(CONST_VAL(1), REGB5),                                                       // JP06 ; bLocal_sensing = 1
	SRW0(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tOrgPastPos[0].tXY.x
    SRW1(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.y
    SRW2(CONST_VAL(24), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH2FLT READ : tPastPos[0].vusS
    SRW3(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH3FLT READ : tPastPos[0].vusR
    MOV(CH0FLT00, REGC6),                                                           //      ; REGC6 = tOrgPastPos[0].tXY.x
    MOV(CH1FLT, REGC7),                                                           	//      ; REGC7 = tOrgPastPos[0].tXY.y
    MOV(CH2FLT, REGC4),                                                           	//      ; REGC4 = tPastPos[0].vusS
    MOV(CH3FLT, REGC5),                                                           	//      ; REGC5 = tPastPos[0].vusR
	
    SRW2(CONST_VAL(16), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      	//      ; CH2FLT WRITE : tOrgPos.tXY.x = tPos.tXY.x
    SRW3(CONST_VAL(17), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        	//      ; CH3FLT WRITE : tOrgPos.tXY.y = tPos.tXY.y
    SRW2(CONST_VAL(36), REGC4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    	//      ; CH2FLT WRITE : tOrgPos.vusS = tPos.vusS
    SRW3(CONST_VAL(37), REGC5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      	//      ; CH3FLT WRITE : tOrgPos.vusR = tPos.vusR	
	ADDS(REGB6, CONST_VAL(1), REGB6),                                               // 		; cIsbefor = cIsbefor + 1
	BRC(LINE_CNT(4), DOWN, AL),                                                     //      ; Always			                         -> JP03
	
	MOV(CONST_VAL(0), REGA7),                                                       // JP04 ; REGA7 = 0 : ucIdMappedCnt
	MOV(CONST_VAL(0), REGB6),                                                       //		; cIsbefor = 0
    MOV(CONST_VAL(0), REGC5),                                                       //      ; REGC5 = 0	  : C5 = tPos.vusR
	
    // Write
    SRW0(CONST_VAL(124), REGA7, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),       // JP03 ; CH0FLT WRITE : ucIdMappedCnt = REGA7
    SRW1(CONST_VAL(0), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH1FLT WRITE : tPos.tXY.x = REGC6
    SRW2(CONST_VAL(1), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH2FLT WRITE : tPos.tXY.y = REGC7
    SRW3(CONST_VAL(4), REGC4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH3FLT WRITE : tPos.vusS = REGC4
    SRW0(CONST_VAL(5), REGC5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH0FLT WRITE : tPos.vusR = REGC5
	
    END()                                                                           // JP07 ; 0x37000000
};

/********************************************************************************
  @brief    Smoothing OPCODE
  */
#ifdef SRAM_OPCODE
int opcode_smoothing[] = 
#else
int opcode_smoothing[] = 
#endif
#if 0
//#ifndef DSP_SMOOTH_GRADIENT
{
    // Input : A0~A6, C0~C3, Internal variables : B0~B7, Coordinate Info : A7, B6~B7, C4~C7
    // REGA7: ucIdMappedCnt, REGB6: tPastPos[0].tXY.x, REGB7: tPastPos[0].tXY.y, 
    // REGC4: tPos.vusS, REGC5: tPos.vusR, REGC6: tPos.tXY.x, REGC7: tPos.tXY.y,
    SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
    SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA2(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA3(REGA0, 0, DMA_SIZE2),                                                     //      ; 
	
	SRW0(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH0FLT READ : tPos.vusS 
	MOV(CH0FLT00, REGC4),                                                      		//      ; REGC4 = tPos.vusS
	
    CMP(REGC4, CONST_VAL(0)),                                                       //      ; cmp(tPos.vusS, 0)
    BRC(LINE_CNT(73), DOWN, LE),                                                    //      ; tPos.vusS <= 0                             -> JP00
    
	SRW1(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH1FLT READ : tPos.vusR 
	MOV(CH1FLT, REGC5),                                                      		//      ; REGC5 = tPos.vusR
	SRW2(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH2FLT READ : tPos.tXY.x 
	MOV(CH2FLT, REGC6),                                                      		//      ; REGC6 = tPos.tXY.x
    SRW3(CONST_VAL(1), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH3FLT READ : tPos.tXY.y 
	MOV(CH3FLT, REGC7),                                                      		//      ; REGC7 = tPos.tXY.y
    SRW0(CONST_VAL(124), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), //      ; CH0FLT READ : ucIdMappedCnt
    MOV(CH0FLT00, REGA7),                                                           //      ; REGA7 = ucIdMappedCnt
    
    // Smoothing
	SRW0(CONST_VAL(24), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // 		; CH0FLT READ : tPastPos[0].vusS
	CMP(CH0FLT00, CONST_VAL(0)),                                                    //      ; cmp(tPastPos[0].vusS, 0)
    BRC(LINE_CNT(63), DOWN, LE),                                                   //      ; tPastPos[0].vusS <= 0        				-> JP01
	SRW1(CONST_VAL(30), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // 		; CH1FLT READ : tPastPos[1].vusS
	CMP(CH1FLT, CONST_VAL(0)),                                                   	//      ; cmp(tPastPos[1].vusS, 0)
    BRC(LINE_CNT(52), DOWN, LE),                                                   //      ; tPastPos[1].vusS <= 0        				-> JP02
	SRW2(CONST_VAL(68), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // 		; CH2FLT READ : tPastPos[2].vusS
	CMP(CH2FLT, CONST_VAL(0)),                                                  	//      ; cmp(tPastPos[2].vusS, 0)
    BRC(LINE_CNT(38), DOWN, LE),                                                   //      ; tPastPos[2].vusS <= 0        				-> JP03

#ifndef COVER_GLASS_USE
	SRW0(CONST_VAL(32), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[2].tXY.x
	SRW1(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[1].tXY.x
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.x
#else
	SRW0(CONST_VAL(35), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[2].tXY.x
	SRW1(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[1].tXY.x
	SRW2(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.x
#endif
	ADDS(CH0FLT00, CH1FLT, REGB0),                                              	//      ; REGB0 = tPastPos[2].tXY.x + tPastPos[1].tXY.x
	ADDS(REGB0, CH2FLT, REGB1),                                              		//      ; REGB1 = REGB0 + tPastPos[0].tXY.x
	ADDS(REGB1, REGC6, REGB2),                                              		//      ; REGB2 = REGB1 + tPos.tXY.x
	ADDS(CH2FLT, REGC6, REGB4),                                              		//      ; REGB4 = tPastPos[0].tXY.x + tPos.tXY.x
	ADDS(REGB4, CH1FLT, REGB3),                                              		//      ; REGB3 = REGB4 + tPastPos[1].tXY.x
	DIVS(REGB0, CONST_VAL(2), REGB0),                                              	//      ; REGB0 = REGB0 / 2
	DIVS(REGB1, CONST_VAL(3), REGB1),                                              	//      ; REGB1 = REGB1 / 3
	DIVS(REGB2, CONST_VAL(4), REGB2),                                              	//      ; REGB2 = REGB2 / 4
	DIVS(REGB3, CONST_VAL(3), REGB3),                                              	//      ; REGB3 = REGB3 / 3
	DIVS(REGB4, CONST_VAL(2), REGB4),                                              	//      ; REGB4 = REGB4 / 2
	ADDS(REGB0, REGB1, REGB7),                                              		//      ; REGB7 = REGB0 + REGB1
	ADDS(REGB7, REGB2, REGB7),                                              		//      ; REGB7 = REGB7 + REGB2
	ADDS(REGB7, REGB3, REGB7),                                              		//      ; REGB7 = REGB7 + REGB3
	ADDS(REGB7, REGB4, REGB7),                                              		//      ; REGB7 = REGB7 + REGB4
	DIVS(REGB7, CONST_VAL(5), REGC6),                                               //      ; REGC6 = REGB7 / 5 : tPos.tXY.x
#ifndef COVER_GLASS_USE
	SRW0(CONST_VAL(33), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[2].tXY.y
	SRW1(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[1].tXY.y
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
#else
	SRW0(CONST_VAL(36), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[2].tXY.y
	SRW1(CONST_VAL(26), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[1].tXY.y
	SRW2(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
#endif
	ADDS(CH0FLT00, CH1FLT, REGB0),                                              	//      ; REGB0 = tPastPos[2].tXY.y + tPastPos[1].tXY.y
	ADDS(REGB0, CH2FLT, REGB1),                                              		//      ; REGB1 = REGB0 + tPastPos[0].tXY.y
	ADDS(REGB1, REGC7, REGB2),                                              		//      ; REGB2 = REGB1 + tPos.tXY.y
	ADDS(CH2FLT, REGC7, REGB4),                                              		//      ; REGB4 = tPastPos[0].tXY.x + tPos.tXY.y
	ADDS(REGB4, CH1FLT, REGB3),                                              		//      ; REGB3 = REGB4 + tPastPos[1].tXY.y
	DIVS(REGB0, CONST_VAL(2), REGB0),                                              	//      ; REGB0 = REGB0 / 2
	DIVS(REGB1, CONST_VAL(3), REGB1),                                              	//      ; REGB1 = REGB1 / 3
	DIVS(REGB2, CONST_VAL(4), REGB2),                                              	//      ; REGB2 = REGB2 / 4
	DIVS(REGB3, CONST_VAL(3), REGB3),                                              	//      ; REGB3 = REGB3 / 3
	DIVS(REGB4, CONST_VAL(2), REGB4),                                              	//      ; REGB4 = REGB4 / 2
	ADDS(REGB0, REGB1, REGB7),                                              		//      ; REGB7 = REGB0 + REGB1
	ADDS(REGB7, REGB2, REGB7),                                              		//      ; REGB7 = REGB7 + REGB2
	ADDS(REGB7, REGB3, REGB7),                                              		//      ; REGB7 = REGB7 + REGB3
	ADDS(REGB7, REGB4, REGB7),                                              		//      ; REGB7 = REGB7 + REGB4
	DIVS(REGB7, CONST_VAL(5), REGC7),                                              	//      ; REGC7 = REGB7 / 5 : tPos.tXY.y
	BRC(LINE_CNT(20), DOWN, AL),                                                    //      ; Always                                     -> JP01
#ifndef COVER_GLASS_USE
	SRW1(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP03 ; CH1FLT READ : tPastPos[1].tXY.x
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.x
#else
	SRW1(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP03 ; CH1FLT READ : tPastPos[1].tXY.x
	SRW2(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.x
#endif
	ADDS(CH1FLT, CH2FLT, REGB7),                                              		//      ; REGB7 = tPastPos[1].tXY.x + tPastPos[0].tXY.x
	ADDS(REGB7, REGC6, REGB7),                                              		//      ; REGB7 = REGB7 + tPos.tXY.x
	DIVS(REGB7, CONST_VAL(3), REGC6),                                              	//      ; REGC6 = REGB7 / 3 : tPos.tXY.x
#ifndef COVER_GLASS_USE
	SRW1(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[1].tXY.y
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
#else
	SRW1(CONST_VAL(26), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[1].tXY.y
	SRW2(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
#endif
	ADDS(CH1FLT, CH2FLT, REGB7),                                              		//      ; REGB7 = tPastPos[1].tXY.y + tPastPos[0].tXY.y
	ADDS(REGB7, REGC7, REGB7),                                              		//      ; REGB7 = REGB7 + tPos.tXY.y
	DIVS(REGB7, CONST_VAL(3), REGC7),                                              	//      ; REGC6 = REGB7 / 3 : tPos.tXY.y
	BRC(LINE_CNT(9), DOWN, AL),                                                     //      ; Always                                     -> JP01
#ifndef COVER_GLASS_USE
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP02	; CH2FLT READ : tPastPos[0].tXY.x
#else
	SRW2(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP02	; CH2FLT READ : tPastPos[0].tXY.x
#endif
	ADDS(CH2FLT, REGC6, REGB7),                                              		//      ; REGB7 = tPastPos[0].tXY.x + tPos.tXY.x
	DIVS(REGB7, CONST_VAL(2), REGC6),                                              	//      ; REGC6 = REGB7 / 2 : tPos.tXY.x
#ifndef COVER_GLASS_USE
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
#else
	SRW2(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
#endif
	ADDS(CH2FLT, REGC7, REGB7),                                              		//      ; REGB7 = tPastPos[0].tXY.y + tPos.tXY.y
	DIVS(REGB7, CONST_VAL(2), REGC7),                                              	//      ; REGC7 = REGB7 / 2 : tPos.tXY.y	
    BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always                                     -> JP01		
    MOV(CONST_VAL(0), REGA7),                                                       // JP00 ; REGA7 = 0 : ucIdMappedCnt
    
	// check hover mode smoothing
	CMP(REGC2, CONST_VAL(LOCAL_HOVER_MODE)), 										// JP01 ; cmp(REGC2, LOCAL_HOVER_MODE)	// REGC2 = mode
	BRC(LINE_CNT(38), DOWN, NE),                                                    //      ; mode != LOCAL_HOVER_MODE    					-> JP25
	SRW0(CONST_VAL(24), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tPastPos[0].vusS
	CMP(CH0FLT00, CONST_VAL(0)),                                                    //      ; cmp(tPastPos[0].vusS, 0)
    BRC(LINE_CNT(35), DOWN, LE),                                                   	//      ; tPastPos[0].vusS <= 0        					-> JP25
	SRW0(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[0].tXY.x
	SRW1(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tOrgPos.tXY.x
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
	SRW3(CONST_VAL(17), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH3FLT READ : tOrgPos.tXY.y
	SUBS(CH0FLT00, CH1FLT, REGB1),                                                  //      ; REGB1 = pos1.x - pos2.x (tPastPos[0].tXY.x - tOrgPos.tXY.x)
    MULS(REGB1, REGB1, REGB1),                                                      //      ; REGB1 = REGB1 * REGB1
    SUBS(CH2FLT, CH3FLT, REGB2),                                                    //      ; REGB2 = pos1.y - pos2.y (tPastPos[0].tXY.y - tOrgPos.tXY.y)
    MULS(REGB2, REGB2, REGB2),                                                      //      ; REGB2 = REGB2 * REGB2
    ADDS(REGB1, REGB2, REGB1),                                                      //      ; REGB1 = REGB1 + REGB2 : dist
    MOV(CONST_VAL(1), REGB2),                                                       //      ; REGB2 = 1 : x
    SLOOP0(1, 15, LOOP_LE, LOOP_SOURCE),                                            //      ; loop 1:15
    DIVS(REGB1, REGB2, REGB3),                                                      //      ; REGB3 = REGB1 / REGB2
    ADDS(REGB2, REGB3, REGB3),                                                      //      ; REGB3 = REGB2 + REGB3
    SRLS(REGB3, CONST_VAL(1), REGB2),                                               //      ; REGB2 = REGB3 >> 1
    ELOOP0(),                                                                       //      ; loop end
	SRLS(REGB2, CONST_VAL(3), REGB0),                                               //      ; REGB0 = REGB2 >> 3
	CMP(REGB0, CONST_VAL(10)),                                                      // 		; cmp(prev_curr_dist>>3, 10)
    BRC(LINE_CNT(2), DOWN, GT),                                                    	//      ; (prev_curr_dist>>3) > 10 						-> JP27
	MOV(CONST_VAL(10), REGB0),                                               		//      ; REGB0 = 10
	CMPS(REGB0, REGA4),                                                             // JP27 ; cmps(prev_curr_dist, (1<<lMoveSmoothingLevel))
    BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; prev_curr_dist <= (1<<lMoveSmoothingLevel)	-> JP26
    MOV(REGA4, REGB0),                                                              //      ; REGB0 = (1<<lMoveSmoothingLevel)
    SUBS(REGA4, REGB0, REGB1),                                                      // JP26 ; REGB1 = (1<<lMoveSmoothingLevel) - prev_curr_dist
	SRL(REGA4, CONST_VAL(1), REGB4),                                                //      ; REGB4 = (1<<lMoveSmoothingLevel) >> 1
    MULS(REGB1, CH0FLT00, REGB2),                                                   //      ; REGB2 = REGB1 * tPastPos[0].tXY.x
    MULS(REGB0, CH1FLT, REGB3),                                                     //      ; REGB3 = prev_curr_dist * tOrgPos.tXY.x
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC6),                                                      //      ; REGC6 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.x
    MULS(REGB1, CH2FLT, REGB2),                                                     //      ; REGB2 = REGB1 * tPastPos[0].tXY.y
    MULS(REGB0, CH3FLT, REGB3),                                                     //      ; REGB3 = prev_curr_dist * tOrgPos.tXY.y
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC7),                                                      //      ; REGC7 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.y
	
    // Write
    SRW1(CONST_VAL(0), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          // JP25 ; CH1FLT WRITE : tPos.tXY.x = REGC6
    SRW2(CONST_VAL(1), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH2FLT WRITE : tPos.tXY.y = REGC7
    SRW3(CONST_VAL(4), REGC4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH3FLT WRITE : tPos.vusS = REGC4
    SRW0(CONST_VAL(5), REGC5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH0FLT WRITE : tPos.vusR = REGC5
   
    SRW1(CONST_VAL(38), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      	//      ; tPastPosHist[0].x = tPos.tXY.x
    SRW2(CONST_VAL(39), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        	//      ; tPastPosHist[0].y = tPos.tXY.y 
	
    END()                                                                           //      ; 0x37000000
};
#else		
{																			
    // Input : A0~A6, C0~C3, Internal variables : B0~B7, Coordinate Info : A7, B6~B7, C4~C7
    // REGA7: ucIdMappedCnt, REGB6: tPastPos[0].tXY.x, REGB7: tPastPos[0].tXY.y, 
    // REGC4: tPos.vusS, REGC5: tPos.vusR, REGC6: tPos.tXY.x, REGC7: tPos.tXY.y,
    SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
    SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA2(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA3(REGA0, 0, DMA_SIZE2),                                                     //      ; 
	
	SRW0(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH0FLT READ : tPos.vusS 
	MOV(CH0FLT00, REGC4),                                                      		//      ; REGC4 = tPos.vusS
	
    CMP(REGC4, CONST_VAL(0)),                                                       //      ; cmp(tPos.vusS, 0)
    BRC(LINE_CNT(228), DOWN, LE),                                                    //      ; tPos.vusS <= 0                             -> JP00
    
	SRW1(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH1FLT READ : tPos.vusR 
	MOV(CH1FLT, REGC5),                                                      		//      ; REGC5 = tPos.vusR
	SRW2(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH2FLT READ : tPos.tXY.x 
	MOV(CH2FLT, REGC6),                                                      		//      ; REGC6 = tPos.tXY.x
    SRW3(CONST_VAL(1), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH3FLT READ : tPos.tXY.y 
	MOV(CH3FLT, REGC7),                                                      		//      ; REGC7 = tPos.tXY.y
    SRW0(CONST_VAL(124), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), //      ; CH0FLT READ : ucIdMappedCnt
    MOV(CH0FLT00, REGA7),                                                           //      ; REGA7 = ucIdMappedCnt
    
    // Smoothing
	SRW0(CONST_VAL(24), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // JP02 ; CH0FLT READ : tPastPos[0].vusS
	CMP(CH0FLT00, CONST_VAL(0)),                                                    //      ; cmp(tPastPos[0].vusS, 0)
    BRC(LINE_CNT(218), DOWN, LE),                                                   //      ; tPastPos[0].vusS <= 0        				-> JP03
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
#ifndef DSP_SMOOTH_GRADIENT
	BRC(LINE_CNT(155), DOWN, AL),                                                   //      ; Always        							-> JP10	
#else
    SRW2(CONST_VAL(38), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      	//      ; tPastPosHist[0].x = tPos.tXY.x
#endif
    SRW3(CONST_VAL(39), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        	//      ; tPastPosHist[0].y = tPos.tXY.y
	MOV(CONST_VAL(0), REGB0),														//      ; REGB0 = 0
	MOV(CONST_VAL(0), REGB1),														//      ; REGB1 = 0
	SLOOP0(1, 23, LOOP_LE, LOOP_SOURCE),  											//      ; loop 1:23
	ADDS(REGB0, CONST_VAL(38), REGB2),												//      ; REGB2 = REGB0 + 38
	SRW0(REGB2, CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),			//		; CH0FLT READ : tPastPosHist[REGB0/2].x
	SUBS(CONST_VAL(0),CONST_VAL(1),REGB3),											//      ; REGB3 = -1
	CMPS(CH0FLT00, REGB3),                                                   		//      ; cmp(tPastPosHist[REGB0/2].x, -1)
	BRC(LINE_CNT(2), DOWN, EQ),                                                     //      ; tPastPosHist[REGB0/2].x == -1        				-> JP09
	ADDS(REGB1, CONST_VAL(1), REGB1),												//		; REGB1 = REGB1 + 1
	ADDS(REGB0, CONST_VAL(2), REGB0),												// JP09 ; REGB0 = REGB0 + 2
	ELOOP0(),		
	MOV(CONST_VAL(0), REGB7),														//		; REGB7(G_F) = 0; 	
	CMP(REGB1, CONST_VAL(5)),                                                   	//      ; cmp(REGB1, 5)
	BRC(LINE_CNT(93), DOWN, LT),                                                    //      ; REGB1 < 5        				-> JP20		
	SDMA3(REGB6, 0, DMA_SIZE2),                                                     //      ; B6 : Gradient	
	SUBS(REGB1, CONST_VAL(1), REGB1),												//      ; REGB1 = REGB1 - 1
	MOV(REGB1, REGC0),																// 		; REGC0 = 0 << 8 | REGB1
	ADDS(REGB1, CONST_VAL(1), REGB1),												//      ; REGB1 = REGB1 + 1	
	MOV(CONST_VAL(0), REGB5),														//		; B5 = 0; 
	SLOOP0(0, 0, LOOP_LT, REGC0),  													//      ; loop 0:REGB1-2	
	ADDS(CNT0, CONST_VAL(1), REGB0),												//      ; REGB0 = CNT0 + 1
	SLL(REGB0,CONST_VAL(8),REGB0),													//		; REGB0 = REGB0 << 8
	OR(REGB0,REGB1,REGC1),															// 		; REGC1 = REGB0 | REGB1
	MOV(CONST_VAL(0), REGB4),														//		; REGB4 = 0;
	SLOOP1(0, 0, LOOP_LT, REGC1),  													//      ; loop REGB0:REGB1-1
	CMP(REGB4,CONST_VAL(1)),														//		; cmp(REGB4,1)
	BRC(LINE_CNT(50), DOWN, EQ),													//		; REGB4 == 1    			-> JP13
	MULS(CNT0,CONST_VAL(2),REGB0),													// 		; REGB0 = CNT0*2
	ADDS(REGB0, CONST_VAL(38), REGB0),												//      ; REGB0 = REGB0 + 38	
	SRW0(REGB0, CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 			// 		; CH0FLT READ : tPastPosHist[CNT0].x
	MULS(CNT1,CONST_VAL(2),REGB2),													// 		; REGB2 = CNT1*2
	ADDS(REGB2, CONST_VAL(38), REGB2),												//      ; REGB2 = REGB2 + 38
	SRW2(REGB2, CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 			// 		; CH2FLT READ : tPastPosHist[CNT1].x
	SUBS(CH0FLT00,CH2FLT,REGB3),													//      ; REGB3 = CH0FLT-CH2FLT : dist_x = tPastPosHist[CNT0].x - tPastPosHist[CNT1].x
	ADDS(REGB0, CONST_VAL(1), REGB0),												//      ; REGB0 = REGB0 + 1
	SRW1(REGB0, CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 			// 		; CH1FLT READ : tPastPosHist[CNT0].y
	ADDS(REGB2, CONST_VAL(1), REGB2),												//      ; REGB2 = REGB2 + 1
	SRW0(REGB2, CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 			// 		; CH0FLT READ : tPastPosHist[CNT1].y
	SUBS(CH1FLT,CH0FLT00,REGB2),													// 	    ; REGB2 = CH1FLT-CH0FLT : dist_y = tPastPosHist[CNT0].Y - tPastPosHist[CNT1].Y
	MOV(REGB3, REGB0),                                                              //      ; REGB0 = REGB3
	CMPS(REGB0,CONST_VAL(0)), 														//      ; cmp(REGB0, 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                     //      ; REGB0 >= 0    -> JP11
	SUBS(CONST_VAL(0),REGB0,REGB0),													//      ; REGB0 = -REGB0
	CMPS(REGB2,CONST_VAL(0)), 														// JP11 ; cmp(REGB2, 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                     //      ; REGB2 >= 0    -> JP12
	SUBS(CONST_VAL(0),REGB2,REGB2),													//      ; REGB2 = -REGB2
	_MAX(REGB2,REGB0,REGB3),															// JP12 ; REGB3 = max(REGB0,REGB2)
	CMP(REGB3,CONST_VAL(48)), 														//      ; cmp(REGB3, 48)
	BRC(LINE_CNT(28), DOWN, LT),                                                    //      ; REGB3 < 48    				-> JP13	
	DIV(REGA4,CONST_VAL(2),REGB3),                                                   // 		; REGB3 = REGA4/2 : (1<<thisModeConf->Coord.lMoveSmoothingLevel)/2;
	CMP(REGB2,CONST_VAL(0)), 														//      ; cmp(REGB2, 0)
	BRC(LINE_CNT(16), DOWN, EQ),                                                    //      ; REGB2 == 0    				-> JP14
	CMP(REGB0,CONST_VAL(0)), 														//      ; cmp(REGB0, 0)
	BRC(LINE_CNT(16), DOWN, EQ),                                                    //      ; REGB0 == 0    				-> JP15
	CMP(REGB0,REGB2), 																//      ; cmp(REGB0, REGB2)
	BRC(LINE_CNT(16), DOWN, EQ),                                                    //      ; REGB0 == REGB2    			 -> JP17	
	CMP(REGB0,REGB2),																//		; cmp(REGB0, REGB2)
	BRC(LINE_CNT(4), DOWN, LT),														//		; REGB0 < REGB2								-> JP22	
	MUL(REGB2,REGB3,REGB2),															// 		; REGB2 = REGB2 * REGB3 : (1<<thisModeConf->Coord.lMoveSmoothingLevel)/2;
	DIV(REGB2,REGB0,REGB2),															//		; REGB2 = REGB2 / REGB0 : (min_dist_value*(1<<thisModeConf->Coord.lMoveSmoothingLevel)/2)/max_dist_value	
	BRC(LINE_CNT(12), DOWN, AL),                                                    //      ; always       				 	-> JP16
	MUL(REGB0,REGB3,REGB0),															// JP22 ; REGB0 = REGB0 * REGB3 : (1<<thisModeConf->Coord.lMoveSmoothingLevel)/2;
	DIV(REGB0,REGB2,REGB0),															//		; REGB0 = REGB0 / REGB2 : (min_dist_value*(1<<thisModeConf->Coord.lMoveSmoothingLevel)/2)/max_dist_value	
	MOV(REGB0, REGB2), 
	SUBS(REGB3, REGB2, REGB2),														//      ; REGB2 = REGB3 - REGB2
	ADDS(REGB3, REGB2, REGB2),														//      ; REGB2 = REGB3 + REGB2
	BRC(LINE_CNT(6), DOWN, AL),                                                     //      ; always									-> JP16
	MOV(CONST_VAL(0), REGB2),                                                       // JP14 ; REGB2 = 0 : Gradient[REGB5] = 0;
	BRC(LINE_CNT(4), DOWN, AL),                                                     //      ;									 -> JP16
	MOV(REGA4, REGB2),                                                       		// JP15 ; REGB2 = REGA4 : Gradient[REGB5] = (1<<thisModeConf->Coord.lMoveSmoothingLevel);
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ;									 -> JP16
	DIV(REGA4,CONST_VAL(2),REGB2),                                                   // JP17 ; REGB2 = REGA4/2 : Gradient[REGB5] = (1<<thisModeConf->Coord.lMoveSmoothingLevel)/2;
	SRW3(REGB5, REGB2, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT), 				// JP16	; Gradient[REGB5] = REGB2;
	ADD(REGB5, CONST_VAL(1), REGB5),												//      ; REGB5 = REGB5 + 1	
	SUB(CNT1, CONST_VAL(1), CNT0),													//      ; CNT0 = CNT1 - 1	
	MOV(CONST_VAL(1), REGB4),														//		; REGB4 = 1;
	ELOOP1(), 																		// JP13
	ELOOP0(),	
	MOV(CONST_VAL(0), REGB7),														//      ; REGB7 = 0 : Gradient sub avg (G_F)	
	CMP(REGB5,CONST_VAL(3)),
	BRC(LINE_CNT(24), DOWN, LT),                                                    //      ; REGB5 < 3    			 -> JP18
	SDMA2(REGB6, 0, DMA_SIZE2),                                                     //      ; B6 : Gradient		
	SUB(REGB5,CONST_VAL(1), REGB1),													// 		; REGB1 = REGB5-1
	MOV(REGB1, REGC0),																// 		; REGC0 = REGB1
	MOV(CONST_VAL(0), REGB3),														//      ; REGB3 = 0	: Gradient sub cnt
	SLOOP0(0, 0, LOOP_LT, REGC0),  													//      ; loop 0:REGB5-2
	ADDS(CNT0, CONST_VAL(1), REGB0),												//      ; REGB0 = CNT0 + 1
	SLL(REGB0,CONST_VAL(8),REGB0),													//		; REGB0 = REGB0 << 8
	OR(REGB0,REGB5,REGC1),															// 		; REGC1 = REGB0 | REGB1
	SLOOP1(0, 0, LOOP_LT, REGC1),  													//      ; loop REGB0:REGB5-1
	SRW2(CNT0, CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT), 			// 		; CH2FLT READ : Gradient[CNT0]
	SRW3(CNT1, CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT), 			// 		; CH3FLT READ : Gradient[CNT1]
	SUB(CH2FLT,CH3FLT,REGB0),														//		; REGB0 = CH2FLT - CH3FLT
	CMPS(REGB0,CONST_VAL(0)), 														// 		; cmp(REGB0, 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; REGB0 >= 0    			-> JP19
	SUBS(CONST_VAL(0),REGB0,REGB0),													// 		; REGB0 = -REGB0
	ADDS(REGB7,REGB0,REGB7),														// JP19 ; REGB7 = REGB7 + REGB0
	ADDS(REGB3, CONST_VAL(1), REGB3),												//      ; REGB3 = REGB3 + 1
	ELOOP1(),																		
	ELOOP0(),	
	DIV(REGB7,REGB3,REGB7),															//      ; REGB7 = REGB7/REGB3	
	CMP(REGB7, REGA4),                                                              // 		; cmps(Gradient_sub_avg, (1<<lMoveSmoothingLevel))
    BRC(LINE_CNT(2), DOWN, LE),                                                     // 		; Gradient_sub_avg <= (1<<lMoveSmoothingLevel) -> JP18 
    MOV(REGA4, REGB7),                                                              //      ; REGB7 = (1<<lMoveSmoothingLevel)	
	SDMA2(REGA0, 0, DMA_SIZE2),                                                     // JP18	;
	SDMA3(REGA0, 0, DMA_SIZE2),                                                     // 		;
	SRW0(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP20	; CH0FLT READ : tPastPos[0].tXY.x
	SRW1(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[0].tXY.y
	SRW2(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tOrgPos.tXY.x
	SRW3(CONST_VAL(17), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH3FLT READ : tOrgPos.tXY.y
	SUBS(CH0FLT00, CH2FLT, REGB1),                                                   //      ; REGB1 = pos1.x - pos2.x (tPastPos[0].tXY.x - tOrgPos.tXY.x)
    SUBS(CH1FLT, CH3FLT, REGB0),                                                     // 		; REGB0 = pos1.y - pos2.y (tPastPos[0].tXY.y - tOrgPos.tXY.y)		
	MULS(REGB1, REGB1, REGB1),                                                      //      ; REGB1 = REGB1 * REGB1
    MULS(REGB0, REGB0, REGB0),                                                      //      ; REGB0 = REGB0 * REGB0
    ADDS(REGB1, REGB0, REGB1),                                                      //      ; REGB1 = REGB0 + REGB1 : dist
    MOV(CONST_VAL(1), REGB3),                                                       //      ; REGB3 = 1 : x
    SLOOP0(1, 15, LOOP_LE, LOOP_SOURCE),                                            //      ; loop 1:15
    DIVS(REGB1, REGB3, REGB4),                                                      //      ; REGB4 = REGB1 / REGB3
    ADDS(REGB3, REGB4, REGB4),                                                      //      ; REGB4 = REGB3 + REGB4
    SRLS(REGB4, CONST_VAL(1), REGB3),                                               //      ; REGB3 = REGB4 >> 1
    ELOOP0(),                                                                       //      ; loop end		
	CMPS(REGB3, REGA4),                                                             // 		; cmps(prev_curr_dist_x, (1<<lMoveSmoothingLevel))
    BRC(LINE_CNT(2), DOWN, LES),                                                    // 		; prev_curr_dist_x <= (1<<lMoveSmoothingLevel) 			-> JP23
    MOV(REGA4, REGB3),                                                              //      ; REGB3 = (1<<lMoveSmoothingLevel)	
	SRLS(REGA4,CONST_VAL(1),REGB0),													// JP23 ; REGB0=REGA4/2
	CMP(REGB3, REGB0),                                                             // 		; cmps(prev_curr_dist_x, (1<<lMoveSmoothingLevel)/2)
	BRC(LINE_CNT(14), DOWN, LT),                                                    // 		; prev_curr_dist_x < (1<<lMoveSmoothingLevel)/2 		-> JP24		
	DIV(REGB3,CONST_VAL(2),REGB3),                                               	//      ; REGB3 = REGB3/2
	DIV(REGB7,CONST_VAL(2),REGB7),                                               	//      ; REGB7 = REGB7/2	
	ADD(REGB3,REGB7,REGB3),															//		; REGB3 = REGB3+REGB7
    SUBS(REGA4, REGB3, REGB1),                                                      // 		; REGB1 = (1<<lMoveSmoothingLevel) - prev_curr_dist
    MULS(REGB1, CH0FLT00, REGB2),                                                   //      ; REGB2 = REGB1 * tPastPos[0].tXY.x
    MULS(REGB3, CH2FLT, REGB4),                                                      //      ; REGB4 = prev_curr_dist * tPos.tXY.x
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REG2 + REGB4
    SRLS(REGB2, REGA5, REGC6),                                                      //      ; REGC6 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.x
    MULS(REGB1, CH1FLT, REGB2),                                                     //      ; REGB2 = REGB1 * tPastPos[0].tXY.y
    MULS(REGB3, CH3FLT, REGB4),                                                      //      ; REGB4 = prev_curr_dist * tPos.tXY.y
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REG2 + REGB4
    SRLS(REGB2, REGA5, REGC7),                                                      //      ; REGC7 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.y	
	BRC(LINE_CNT(14), DOWN, AL),													//		; ALWAYS 												-> JP10	
	SUBS(REGB3,REGB7,REGB3),														// JP24	; REGB3 = REGB3-REGB7	
	CMPS(REGB3,CONST_VAL(0)), 														// 		; cmp(REGB3, 0)
	BRC(LINE_CNT(2), DOWN, GT),                                                     //      ; REGB0 >	 0    										-> JP21
	BRC(LINE_CNT(10), DOWN, AL),													//		; ALWAYS 												-> JP10	
    SUBS(REGA4, REGB3, REGB1),                                                      // JP21	; REGB1 = (1<<lMoveSmoothingLevel) - prev_curr_dist
    MULS(REGB1, CH2FLT, REGB2),                                                   	//      ; REGB2 = REGB1 * tPastPos[0].tXY.x
    MULS(REGB3, CH0FLT00, REGB4),                                                   //      ; REGB4 = prev_curr_dist * tPos.tXY.x
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REG2 + REGB4
    SRLS(REGB2, REGA5, REGC6),                                                      //      ; REGC6 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.x
    MULS(REGB1, CH3FLT, REGB2),                                                    	//      ; REGB2 = REGB1 * tPastPos[0].tXY.y
    MULS(REGB3, CH1FLT, REGB4),                                                     //      ; REGB4 = prev_curr_dist * tPos.tXY.y
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REG2 + REGB4
    SRLS(REGB2, REGA5, REGC7),                                                      //      ; REGC7 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.y			
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	SRW1(CONST_VAL(30), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // JP10	; CH1FLT READ : tPastPos[1].vusS
	CMP(CH1FLT, CONST_VAL(0)),                                                   	//      ; cmp(tPastPos[1].vusS, 0)
	BRC(LINE_CNT(52), DOWN, LE),                                                    //      ; tPastPos[1].vusS <= 0        				-> JP04
	SRW2(CONST_VAL(68), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // 		; CH2FLT READ : tPastPos[2].vusS
	CMP(CH2FLT, CONST_VAL(0)),                                                  	//      ; cmp(tPastPos[2].vusS, 0)
	BRC(LINE_CNT(38), DOWN, LE),                                                    //      ; tPastPos[2].vusS <= 0        				-> JP05
#ifdef DSP_SMOOTH_PASTPOS
	SRW0(CONST_VAL(32), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[2].tXY.x
	SRW1(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[1].tXY.x
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.x
#else
	SRW0(CONST_VAL(35), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tOrgPastPos[2].tXY.x
	SRW1(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tOrgPastPos[1].tXY.x
	SRW2(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tOrgPastPos[0].tXY.x
#endif
	ADDS(CH0FLT00, CH1FLT, REGB0),                                              	//      ; REGB0 = tPastPos[2].tXY.x + tPastPos[1].tXY.x
	ADDS(REGB0, CH2FLT, REGB1),                                              		//      ; REGB1 = REGB0 + tPastPos[0].tXY.x
	ADDS(REGB1, REGC6, REGB2),                                              		//      ; REGB2 = REGB1 + tPos.tXY.x
	ADDS(CH2FLT, REGC6, REGB4),                                              		//      ; REGB4 = tPastPos[0].tXY.x + tPos.tXY.x
	ADDS(REGB4, CH1FLT, REGB3),                                              		//      ; REGB3 = REGB4 + tPastPos[1].tXY.x
	DIVS(REGB0, CONST_VAL(2), REGB0),                                              	//      ; REGB0 = REGB0 / 2
	DIVS(REGB1, CONST_VAL(3), REGB1),                                              	//      ; REGB1 = REGB1 / 3
	DIVS(REGB2, CONST_VAL(4), REGB2),                                              	//      ; REGB2 = REGB2 / 4
	DIVS(REGB3, CONST_VAL(3), REGB3),                                              	//      ; REGB3 = REGB3 / 3
	DIVS(REGB4, CONST_VAL(2), REGB4),                                              	//      ; REGB4 = REGB4 / 2
	ADDS(REGB0, REGB1, REGB7),                                              		//      ; REGB7 = REGB0 + REGB1
	ADDS(REGB7, REGB2, REGB7),                                              		//      ; REGB7 = REGB7 + REGB2
	ADDS(REGB7, REGB3, REGB7),                                              		//      ; REGB7 = REGB7 + REGB3
	ADDS(REGB7, REGB4, REGB7),                                              		//      ; REGB7 = REGB7 + REGB4
	DIVS(REGB7, CONST_VAL(5), REGC6),                                               //      ; REGC6 = REGB7 / 5 : tPos.tXY.x	
#ifdef DSP_SMOOTH_PASTPOS
	SRW0(CONST_VAL(33), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[2].tXY.y
	SRW1(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[1].tXY.y
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
#else
	SRW0(CONST_VAL(36), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tOrgPastPos[2].tXY.y
	SRW1(CONST_VAL(26), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tOrgPastPos[1].tXY.y
	SRW2(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tOrgPastPos[0].tXY.y
#endif
	ADDS(CH0FLT00, CH1FLT, REGB0),                                              	//      ; REGB0 = tPastPos[2].tXY.y + tPastPos[1].tXY.y
	ADDS(REGB0, CH2FLT, REGB1),                                              		//      ; REGB1 = REGB0 + tPastPos[0].tXY.y
	ADDS(REGB1, REGC7, REGB2),                                              		//      ; REGB2 = REGB1 + tPos.tXY.y
	ADDS(CH2FLT, REGC7, REGB4),                                              		//      ; REGB4 = tPastPos[0].tXY.x + tPos.tXY.y
	ADDS(REGB4, CH1FLT, REGB3),                                              		//      ; REGB3 = REGB4 + tPastPos[1].tXY.y
	DIVS(REGB0, CONST_VAL(2), REGB0),                                              	//      ; REGB0 = REGB0 / 2
	DIVS(REGB1, CONST_VAL(3), REGB1),                                              	//      ; REGB1 = REGB1 / 3
	DIVS(REGB2, CONST_VAL(4), REGB2),                                              	//      ; REGB2 = REGB2 / 4
	DIVS(REGB3, CONST_VAL(3), REGB3),                                              	//      ; REGB3 = REGB3 / 3
	DIVS(REGB4, CONST_VAL(2), REGB4),                                              	//      ; REGB4 = REGB4 / 2
	ADDS(REGB0, REGB1, REGB7),                                              		//      ; REGB7 = REGB0 + REGB1
	ADDS(REGB7, REGB2, REGB7),                                              		//      ; REGB7 = REGB7 + REGB2
	ADDS(REGB7, REGB3, REGB7),                                              		//      ; REGB7 = REGB7 + REGB3
	ADDS(REGB7, REGB4, REGB7),                                              		//      ; REGB7 = REGB7 + REGB4
	DIVS(REGB7, CONST_VAL(5), REGC7),                                              	//      ; REGC7 = REGB7 / 5 : tPos.tXY.y
	BRC(LINE_CNT(20), DOWN, AL),                                                    //      ; Always                                     -> JP03
#ifdef DSP_SMOOTH_PASTPOS
	SRW1(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP05 ; CH1FLT READ : tPastPos[1].tXY.x
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.x
#else
	SRW1(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP05 ; CH1FLT READ : tOrgPastPos[1].tXY.x
	SRW2(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tOrgPastPos[0].tXY.x
#endif
	ADDS(CH1FLT, CH2FLT, REGB7),                                              		//      ; REGB7 = tPastPos[1].tXY.x + tPastPos[0].tXY.x
	ADDS(REGB7, REGC6, REGB7),                                              		//      ; REGB7 = REGB7 + tPos.tXY.x
	DIVS(REGB7, CONST_VAL(3), REGC6),                                              	//      ; REGC6 = REGB7 / 3 : tPos.tXY.x
#ifdef DSP_SMOOTH_PASTPOS
	SRW1(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[1].tXY.y
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
#else
	SRW1(CONST_VAL(26), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tOrgPastPos[1].tXY.y
	SRW2(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tOrgPastPos[0].tXY.y
#endif
	ADDS(CH1FLT, CH2FLT, REGB7),                                              		//      ; REGB7 = tPastPos[1].tXY.y + tPastPos[0].tXY.y
	ADDS(REGB7, REGC7, REGB7),                                              		//      ; REGB7 = REGB7 + tPos.tXY.y
	DIVS(REGB7, CONST_VAL(3), REGC7),                                              	//      ; REGC6 = REGB7 / 3 : tPos.tXY.y
	BRC(LINE_CNT(9), DOWN, AL),                                                     //      ; Always                                     -> JP03
#ifdef DSP_SMOOTH_PASTPOS
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP04	; CH2FLT READ : tPastPos[0].tXY.x
#else
	SRW2(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP04	; CH2FLT READ : tOrgPastPos[0].tXY.x
#endif
	ADDS(CH2FLT, REGC6, REGB7),                                              		//      ; REGB7 = tPastPos[0].tXY.x + tPos.tXY.x
	DIVS(REGB7, CONST_VAL(2), REGC6),                                              	//      ; REGC6 = REGB7 / 2 : tPos.tXY.x
#ifdef DSP_SMOOTH_PASTPOS
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
#else
	SRW2(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tOrgPastPos[0].tXY.y
#endif
	ADDS(CH2FLT, REGC7, REGB7),                                              		//      ; REGB7 = tPastPos[0].tXY.y + tPos.tXY.y
	DIVS(REGB7, CONST_VAL(2), REGC7),                                              	//      ; REGC7 = REGB7 / 2 : tPos.tXY.y	
    BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always                                     -> JP03	
    MOV(CONST_VAL(0), REGA7),                                                       // JP00 ; REGA7 = 0 : ucIdMappedCnt
    
	// check hover mode smoothing
	CMP(REGC2, CONST_VAL(LOCAL_HOVER_MODE)), 										// JP03 ; cmp(REGC2, LOCAL_HOVER_MODE)	// REGC2 = mode
	BRC(LINE_CNT(38), DOWN, NE),                                                    //      ; mode != LOCAL_HOVER_MODE    					-> JP25
	SRW0(CONST_VAL(24), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tPastPos[0].vusS
	CMP(CH0FLT00, CONST_VAL(0)),                                                    //      ; cmp(tPastPos[0].vusS, 0)
    BRC(LINE_CNT(35), DOWN, LE),                                                   	//      ; tPastPos[0].vusS <= 0        					-> JP25
	SRW0(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[0].tXY.x
	SRW1(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tOrgPos.tXY.x
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
	SRW3(CONST_VAL(17), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH3FLT READ : tOrgPos.tXY.y
	SUBS(CH0FLT00, CH1FLT, REGB1),                                                  //      ; REGB1 = pos1.x - pos2.x (tPastPos[0].tXY.x - tOrgPos.tXY.x)
    MULS(REGB1, REGB1, REGB1),                                                      //      ; REGB1 = REGB1 * REGB1
    SUBS(CH2FLT, CH3FLT, REGB2),                                                    //      ; REGB2 = pos1.y - pos2.y (tPastPos[0].tXY.y - tOrgPos.tXY.y)
    MULS(REGB2, REGB2, REGB2),                                                      //      ; REGB2 = REGB2 * REGB2
    ADDS(REGB1, REGB2, REGB1),                                                      //      ; REGB1 = REGB1 + REGB2 : dist
    MOV(CONST_VAL(1), REGB2),                                                       //      ; REGB2 = 1 : x
    SLOOP0(1, 15, LOOP_LE, LOOP_SOURCE),                                            //      ; loop 1:15
    DIVS(REGB1, REGB2, REGB3),                                                      //      ; REGB3 = REGB1 / REGB2
    ADDS(REGB2, REGB3, REGB3),                                                      //      ; REGB3 = REGB2 + REGB3
    SRLS(REGB3, CONST_VAL(1), REGB2),                                               //      ; REGB2 = REGB3 >> 1
    ELOOP0(),                                                                       //      ; loop end
	SRLS(REGB2, CONST_VAL(3), REGB0),                                               //      ; REGB0 = REGB2 >> 3
	CMP(REGB0, CONST_VAL(10)),                                                      // 		; cmp(prev_curr_dist>>3, 10)
    BRC(LINE_CNT(2), DOWN, GT),                                                    	//      ; (prev_curr_dist>>3) > 10 						-> JP27
	MOV(CONST_VAL(10), REGB0),                                               		//      ; REGB0 = 10
	CMPS(REGB0, REGA4),                                                             // JP27 ; cmps(prev_curr_dist, (1<<lMoveSmoothingLevel))
    BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; prev_curr_dist <= (1<<lMoveSmoothingLevel)	-> JP26
    MOV(REGA4, REGB0),                                                              //      ; REGB0 = (1<<lMoveSmoothingLevel)
    SUBS(REGA4, REGB0, REGB1),                                                      // JP26 ; REGB1 = (1<<lMoveSmoothingLevel) - prev_curr_dist
	SRL(REGA4, CONST_VAL(1), REGB4),                                                //      ; REGB4 = (1<<lMoveSmoothingLevel) >> 1
    MULS(REGB1, CH0FLT00, REGB2),                                                   //      ; REGB2 = REGB1 * tPastPos[0].tXY.x
    MULS(REGB0, CH1FLT, REGB3),                                                     //      ; REGB3 = prev_curr_dist * tOrgPos.tXY.x
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC6),                                                      //      ; REGC6 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.x
    MULS(REGB1, CH2FLT, REGB2),                                                     //      ; REGB2 = REGB1 * tPastPos[0].tXY.y
    MULS(REGB0, CH3FLT, REGB3),                                                     //      ; REGB3 = prev_curr_dist * tOrgPos.tXY.y
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC7),                                                      //      ; REGC7 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.y
	
    // Write
    SRW1(CONST_VAL(0), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          // JP25 ; CH1FLT WRITE : tPos.tXY.x = REGC6
    SRW2(CONST_VAL(1), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH2FLT WRITE : tPos.tXY.y = REGC7
    SRW3(CONST_VAL(4), REGC4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH3FLT WRITE : tPos.vusS = REGC4
    SRW0(CONST_VAL(5), REGC5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH0FLT WRITE : tPos.vusR = REGC5
   
    SRW1(CONST_VAL(38), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      	//      ; tPastPosHist[0].x = tPos.tXY.x
    SRW2(CONST_VAL(39), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        	//      ; tPastPosHist[0].y = tPos.tXY.y 
	
    END()   
};
#endif

#ifdef SRAM_OPCODE
int opcode_coordpost[] = 
#else
int opcode_coordpost[] = 
#endif
{
	SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
	SDMA2(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
	SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ;
	SDMA3(REGA0, 0, DMA_SIZE2),

	SRW0(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH0FLT READ : tPos.vusS 
	SRW1(CONST_VAL(24), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tPastPos[0].vusS
	SRW2(CONST_VAL(54), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH2FLT READ : tOrgPastPos[1].vusS
	SRW1(CONST_VAL(8), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),	//      ; CH1FLT WRITE : tAvgPos.x = 0
	CMP(REGA5, CONST_VAL(0)),															
	BRC(LINE_CNT(50), DOWN, EQ),                                                    //      ; REGA5 == 0                      -> JP03
	CMP(CH1FLT, CONST_VAL(0)),                                                      //      ; cmp(tPastPos[0].vusS, 0)
	BRC(LINE_CNT(48), DOWN, LE),                                                    //      ; tPastPos[0].vusS <= 0                      -> JP03
	CMP(CH2FLT, CONST_VAL(0)),                                                      //      ; cmp(tOrgPastPos[1].vusS, 0)
	BRC(LINE_CNT(46), DOWN, LE),                                                    //      ; tOrgPastPos[1].vusS <= 0                   -> JP03  
	SRW0(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH0FLT READ : tOrgPastPos[0].tXY.x
	SRW1(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.y
	CMPS(CH0FLT00, REGA1),                                                          //      ; cmps(tOrgPastPos[0].tXY.x, ExpandTH)
	BRC(LINE_CNT(10), DOWN, LTS),                                                   //      ; tOrgPastPos[0].tXY.x < ExpandTH                  -> JP08
	SUBS(REGA3, CH0FLT00, REGB1),                                                   //      ; REGB1 = iInternalXRes - tOrgPastPos[0].tXY.x        
	CMPS(REGB1, REGA1),                                                             //      ; cmps(REGB1, iXExpandStart)
	BRC(LINE_CNT(7), DOWN, LTS),                                                    //      ; REGB1 < ExpandTH                                           -> JP08
	CMPS(CH1FLT, REGA1),                                                            //      ; cmps(tOrgPastPos[0].tXY.y, ExpandTH)
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; tOrgPastPos[0].tXY.y < ExpandTH       -> JP08
	SUBS(REGA4, CH1FLT, REGB1),                                                     //      ; REGB1 = iInternalYRes - tOrgPastPos[0].tXY.y
	CMPS(REGB1, REGA1),                                                             //      ; cmps(REGB1, ExpandTH)
	BRC(LINE_CNT(2), DOWN, LTS),                                                    //      ; REGB1 < iYExpandStart                      -> JP08  
	BRC(LINE_CNT(33), DOWN, AL),                                                    //      ; Always                                     -> JP03   
	//BRC(LINE_CNT(21), DOWN, AL), 
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP08 ; CH2FLT READ : tPastPos[0].tXY.x
	SRW3(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH3FLT READ : tPastPos[1].tXY.x             
	SUBS(CH2FLT, CH3FLT, REGB0),                                                    //      ; REGB0 = CH2FLT - CH3FLT
	CMPS(REGB0,CONST_VAL(0)),                                                       //      ; cmp(REGB0, 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; REGB0 >= 0                                -> JP22
	SUBS(CONST_VAL(0),REGB0,REGB0),                                                 //      ; REGB0 = -REGB0          
	DIV(REGB0,CONST_VAL(4),REGB2),                                                  // JP22 ; REGB2 = REGB0/4
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tPastPos[0].tXY.y
	SRW3(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH3FLT READ : tPastPos[1].tXY.y  
	SUBS(CH2FLT, CH3FLT, REGB3),                                                    //      ; REGB3 = CH2FLT - CH3FLT
	CMPS(REGB3,CONST_VAL(0)),                                                       //      ; cmp(REGB3, 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; REGB3 >= 0                                -> JP24
	SUBS(CONST_VAL(0),REGB3,REGB3),                                                 //      ; REGB3 = -REGB3
	CMPS(REGB0,REGA2),                                                              // JP24 ; cmp(REGB0, REGA2)
	BRC(LINE_CNT(4), DOWN, GES),                                                    //      ; REGB0 >= REGA2               				-> JP23  
	CMPS(REGB3,REGA2),                                                              //      ; cmp(REGB3, REGA2)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; REGB3 >= REGA2                			-> JP23  
	BRC(LINE_CNT(15), DOWN, AL),                                                    //      ; Always                                     -> JP03
	ADDS(CH0FLT00,REGB2,CH0FLT00),                                                  // JP23 ; CH0FLT00 += REGB2
	DIV(REGB3,CONST_VAL(4),REGB3),                                                  //  	; REGB3 = REGB3/4
	ADDS(CH1FLT,REGB3,CH1FLT),                                                      //      ; CH1FLT += REGB3
	MOV(CH0FLT00, REGC6),                                                           //      ; REGC6 = tOrgPastPos[0].tXY.x : tPos.tXY.x
	MOV(CH1FLT, REGC7),                                                             //      ; REGC7 = tOrgPastPos[0].tXY.y : tPos.tXY.y
	SRW2(CONST_VAL(48), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH2FLT READ : tOrgPastPos[0].vusS
	SRW3(CONST_VAL(49), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH3FLT READ : tOrgPastPos[0].vusR
	MOV(CH2FLT, REGC4),                                                             //      ; REGC4 = tOrgPastPos[0].vusS : tPos.vusS
	MOV(CH3FLT, REGC5),                                                             //      ; REGC5 = tOrgPastPos[0].vusR : tPos.vusR
	SRW1(CONST_VAL(0), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH1FLT WRITE : tPos.tXY.x = REGC6
	SRW2(CONST_VAL(1), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH2FLT WRITE : tPos.tXY.y = REGC7
	SRW3(CONST_VAL(4), REGC4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH3FLT WRITE : tPos.vusS = REGC4
	SRW0(CONST_VAL(5), REGC5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH0FLT WRITE : tPos.vusR = REGC5                    
	SRW1(CONST_VAL(8), CONST_VAL(1), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT WRITE : tAvgPos.x = REGC4
	END()                                                                           // JP03 ; 0x37000000
};


/********************************************************************************
  @brief    Coordinate Initialization OPCODE
  */
#ifdef SRAM_OPCODE
int opcode_coordinit[] = 
#else
int opcode_coordinit[] = 
#endif
{
    // Input : A0, A1
    SDMA0(REGA1, 0, DMA_SIZE0),                                                     //      ; A1 : pen delta info

    SRW0(CONST_VAL(2), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT), //      ; CH0FLT WRITE : iMaxStrength = 0
    
    SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
    SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA2(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA3(REGA0, 0, DMA_SIZE2),                                                     //      ;
    
    SRW0(CONST_VAL(0), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH0FLT WRITE : tPos.tXY.x = 0
    SRW1(CONST_VAL(1), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT WRITE : tPos.tXY.y = 0
    SRW2(CONST_VAL(4), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH2FLT WRITE : tPos.vusS = 0
    SRW3(CONST_VAL(5), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH3FLT WRITE : tPos.vusR = 0
    SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),   //      ; CH2FLT WRITE : tPos.rect.rs = 0
    SRW3(CONST_VAL(7), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),   //      ; CH3FLT WRITE : tPos.rect.re = 0
    SRW0(CONST_VAL(8), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),   //      ; CH0FLT WRITE : tPos.rect.cs = 0
    SRW1(CONST_VAL(9), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),   //      ; CH1FLT WRITE : tPos.rect.ce = 0
    
    SRW0(CONST_VAL(16), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  //      ; CH0FLT WRITE : tOrgPos.tXY.x = 0
    SRW1(CONST_VAL(17), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  //      ; CH1FLT WRITE : tOrgPos.tXY.y = 0
    SRW2(CONST_VAL(36), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),//      ; CH2FLT WRITE : tOrgPos.vusS = 0
    SRW3(CONST_VAL(37), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),//      ; CH3FLT WRITE : tOrgPos.vusR = 0
    SRW2(CONST_VAL(38), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),  //      ; CH2FLT WRITE : tOrgPos.rect.rs = 0
    SRW3(CONST_VAL(39), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),  //      ; CH3FLT WRITE : tOrgPos.rect.re = 0
    SRW0(CONST_VAL(40), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),  //      ; CH0FLT WRITE : tOrgPos.rect.cs = 0
    SRW1(CONST_VAL(41), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),  //      ; CH1FLT WRITE : tOrgPos.rect.ce = 0
    
    SRW0(CONST_VAL(10), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),//      ; CH0FLT WRITE : tPos.MaxDelta = 0
    SRW1(CONST_VAL(42), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),//      ; CH1FLT WRITE : tOrgPos.MaxDelta = 0
    SRW2(CONST_VAL(125), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),//      ; CH2FLT WRITE : ucPostProcessRun = 0
    
    END()                                                                           //      ; 0x37000000
};

/********************************************************************************
  @brief    Udpate History OPCODE
  */
#ifdef SRAM_OPCODE
int opcode_updateproc[] = 
#else
int opcode_updateproc[] = 
#endif
#if 0
{
    // Input : A0,
    SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
    SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA2(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA3(REGA0, 0, DMA_SIZE2),                                                     //      ;
    
	SRW0(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH0FLT READ : tPastPos[1].tXY.x
    SRW1(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPos[1].tXY.y
    SRW2(CONST_VAL(32), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPos[2].tXY.x = tPastPos[1].tXY.x
    SRW3(CONST_VAL(33), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPos[2].tXY.y = tPastPos[1].tXY.y
    SRW0(CONST_VAL(30), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tPastPos[1].vusS
    SRW1(CONST_VAL(31), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tPastPos[1].vusR
    SRW2(CONST_VAL(68), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tPastPos[2].vusS = tPastPos[1].vusS
    SRW3(CONST_VAL(69), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tPastPos[2].vusR = tPastPos[1].vusR
	
	SRW0(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH0FLT READ : tPastPos[0].tXY.x
    SRW1(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPos[0].tXY.y
    SRW2(CONST_VAL(13), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPos[1].tXY.x = tPastPos[0].tXY.x
    SRW3(CONST_VAL(14), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPos[1].tXY.y = tPastPos[0].tXY.y
    SRW0(CONST_VAL(24), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tPastPos[0].vusS
    SRW1(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tPastPos[0].vusR
    SRW2(CONST_VAL(30), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tPastPos[1].vusS = tPastPos[0].vusS
    SRW3(CONST_VAL(31), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tPastPos[1].vusR = tPastPos[0].vusR  
	
    SRW0(CONST_VAL(125), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), //      ; CH0FLT READ : ucPostProcessRun
    CMP(CH0FLT00, CONST_VAL(1)),                                                    //      ; cmp(ucPostProcessRun, 1)
    BRC(LINE_CNT(10), DOWN, NE),                                                    //      ; ucPostProcessRun != 1                      -> JP01
    SRW0(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH0FLT READ : tFirstPos.x
    SRW1(CONST_VAL(7), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH1FLT READ : tFirstPos.y
    SRW2(CONST_VAL(10), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPos[0].tXY.x = tFirstPos.x
    SRW3(CONST_VAL(11), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPos[0].tXY.y = tFirstPos.y    
    SRW0(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH0FLT READ : tPos.vusS
    SRW1(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH1FLT READ : tPos.vusR
    SRW2(CONST_VAL(24), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tPastPos[0].vusS = tPos.vusS
    SRW3(CONST_VAL(25), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tPastPos[0].vusR = tPos.vusR
    BRC(LINE_CNT(9), DOWN, AL),                                                     //      ; Always                                     -> JP02
    SRW0(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    // JP01 ; CH0FLT READ : tPos.tXY.x
    SRW1(CONST_VAL(1), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH1FLT READ : tPos.tXY.y
    SRW2(CONST_VAL(10), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPos[0].tXY.x = tPos.tXY.x
    SRW3(CONST_VAL(11), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPos[0].tXY.y = tPos.tXY.y    
    SRW0(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH0FLT READ : tPos.vusS
    SRW1(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH1FLT READ : tPos.vusR
    SRW2(CONST_VAL(24), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tPastPos[0].vusS = tPos.vusS
    SRW3(CONST_VAL(25), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tPastPos[0].vusR = tPos.vusR   
	 
	SRW0(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP02 ; CH0FLT READ : tOrgPastPos[1].tXY.x
    SRW1(CONST_VAL(26), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[1].tXY.y
    SRW2(CONST_VAL(35), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tOrgPastPos[2].tXY.x = tOrgPastPos[1].tXY.x
    SRW3(CONST_VAL(36), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tOrgPastPos[2].tXY.y = tOrgPastPos[1].tXY.y    
    SRW0(CONST_VAL(54), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tOrgPastPos[1].vusS
    SRW1(CONST_VAL(55), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tOrgPastPos[1].vusR
    SRW2(CONST_VAL(74), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tOrgPastPos[2].vusS = tOrgPastPos[1].vusS
    SRW3(CONST_VAL(75), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tOrgPastPos[2].vusR = tOrgPastPos[1].vusR
	 
    SRW0(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tOrgPastPos[0].tXY.x
    SRW1(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.y
    SRW2(CONST_VAL(25), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tOrgPastPos[1].tXY.x = tOrgPastPos[0].tXY.x
    SRW3(CONST_VAL(26), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tOrgPastPos[1].tXY.y = tOrgPastPos[0].tXY.y    
    SRW0(CONST_VAL(48), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tOrgPastPos[0].vusS
    SRW1(CONST_VAL(49), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tOrgPastPos[0].vusR
    SRW2(CONST_VAL(54), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tOrgPastPos[1].vusS = tOrgPastPos[0].vusS
    SRW3(CONST_VAL(55), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tOrgPastPos[1].vusR = tOrgPastPos[0].vusR
    
    SRW0(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tOrgPos.tXY.x
    SRW1(CONST_VAL(17), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPos.tXY.y
    SRW2(CONST_VAL(22), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tOrgPastPos[0].tXY.x = tOrgPos.tXY.x
    SRW3(CONST_VAL(23), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tOrgPastPos[0].tXY.y = tOrgPos.tXY.y    
    SRW0(CONST_VAL(36), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tOrgPos.vusS
    SRW1(CONST_VAL(37), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tOrgPos.vusR
    SRW2(CONST_VAL(48), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tOrgPastPos[0].vusS = tOrgPos.vusS
    SRW3(CONST_VAL(49), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tOrgPastPos[0].vusR = tOrgPos.vusR
    
    END()                                                                           //      ; 0x37000000
};
#else
{
    // Input : A0,
    SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
    SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA2(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA3(REGA0, 0, DMA_SIZE2),                                                     //      ;
 
//	SRW0(CONST_VAL(32), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos2.tXY.x
//    SRW1(CONST_VAL(33), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPos2.tXY.y
//    SRW2(CONST_VAL(38), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPosHist[0].x = tPastPos2.tXY.x
//    SRW3(CONST_VAL(39), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPosHist[0].y = tPastPos2.tXY.y 
	
	SRW0(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH0FLT READ : tPastPos[1].tXY.x
    SRW1(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPos[1].tXY.y
    SRW2(CONST_VAL(32), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPos2.tXY.x = tPastPos[1].tXY.x
    SRW3(CONST_VAL(33), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPos2.tXY.y = tPastPos[1].tXY.y
    SRW0(CONST_VAL(30), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tPastPos[1].vusS
    SRW1(CONST_VAL(31), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tPastPos[1].vusR
    SRW2(CONST_VAL(68), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tPastPos2.vusS = tPastPos[1].vusS
    SRW3(CONST_VAL(69), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tPastPos2.vusR = tPastPos[1].vusR
	
	SRW0(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH0FLT READ : tPastPos[0].tXY.x
    SRW1(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPos[0].tXY.y
    SRW2(CONST_VAL(13), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPos[1].tXY.x = tPastPos[0].tXY.x
    SRW3(CONST_VAL(14), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPos[1].tXY.y = tPastPos[0].tXY.y
    SRW0(CONST_VAL(24), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tPastPos[0].vusS
    SRW1(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tPastPos[0].vusR
    SRW2(CONST_VAL(30), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tPastPos[1].vusS = tPastPos[0].vusS
    SRW3(CONST_VAL(31), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tPastPos[1].vusR = tPastPos[0].vusR  
	
    SRW0(CONST_VAL(125), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), //      ; CH0FLT READ : ucPostProcessRun
    CMP(CH0FLT00, CONST_VAL(1)),                                                    //      ; cmp(ucPostProcessRun, 1)
    BRC(LINE_CNT(10), DOWN, NE),                                                    //      ; ucPostProcessRun != 1                      -> JP01
    SRW0(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH0FLT READ : tFirstPos.x
    SRW1(CONST_VAL(7), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH1FLT READ : tFirstPos.y
    SRW2(CONST_VAL(10), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPos[0].tXY.x = tFirstPos.x
    SRW3(CONST_VAL(11), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPos[0].tXY.y = tFirstPos.y    
    SRW0(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH0FLT READ : tPos.vusS
    SRW1(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH1FLT READ : tPos.vusR
    SRW2(CONST_VAL(24), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tPastPos[0].vusS = tPos.vusS
    SRW3(CONST_VAL(25), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tPastPos[0].vusR = tPos.vusR
    BRC(LINE_CNT(9), DOWN, AL),                                                     //      ; Always                                     -> JP02
    SRW0(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    // JP01 ; CH0FLT READ : tPos.tXY.x
    SRW1(CONST_VAL(1), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH1FLT READ : tPos.tXY.y
    SRW2(CONST_VAL(10), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPos[0].tXY.x = tPos.tXY.x
    SRW3(CONST_VAL(11), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPos[0].tXY.y = tPos.tXY.y    
    SRW0(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH0FLT READ : tPos.vusS
    SRW1(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH1FLT READ : tPos.vusR
    SRW2(CONST_VAL(24), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tPastPos[0].vusS = tPos.vusS
    SRW3(CONST_VAL(25), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tPastPos[0].vusR = tPos.vusR   
	 
	SRW0(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP02 ; CH0FLT READ : tOrgPastPos[1].tXY.x
    SRW1(CONST_VAL(26), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[1].tXY.y
    SRW2(CONST_VAL(35), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tOrgPastPos[2].tXY.x = tOrgPastPos[1].tXY.x
    SRW3(CONST_VAL(36), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tOrgPastPos[2].tXY.y = tOrgPastPos[1].tXY.y    
    SRW0(CONST_VAL(54), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tOrgPastPos[1].vusS
    SRW1(CONST_VAL(55), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tOrgPastPos[1].vusR
    SRW2(CONST_VAL(74), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tOrgPastPos[2].vusS = tOrgPastPos[1].vusS
    SRW3(CONST_VAL(75), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tOrgPastPos[2].vusR = tOrgPastPos[1].vusR
	 
    SRW0(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tOrgPastPos[0].tXY.x
    SRW1(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.y
    SRW2(CONST_VAL(25), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tOrgPastPos[1].tXY.x = tOrgPastPos[0].tXY.x
    SRW3(CONST_VAL(26), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tOrgPastPos[1].tXY.y = tOrgPastPos[0].tXY.y    
    SRW0(CONST_VAL(48), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tOrgPastPos[0].vusS
    SRW1(CONST_VAL(49), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tOrgPastPos[0].vusR
    SRW2(CONST_VAL(54), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tOrgPastPos[1].vusS = tOrgPastPos[0].vusS
    SRW3(CONST_VAL(55), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tOrgPastPos[1].vusR = tOrgPastPos[0].vusR
    
    SRW0(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tOrgPos.tXY.x
    SRW1(CONST_VAL(17), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPos.tXY.y
    SRW2(CONST_VAL(22), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tOrgPastPos[0].tXY.x = tOrgPos.tXY.x
    SRW3(CONST_VAL(23), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tOrgPastPos[0].tXY.y = tOrgPos.tXY.y    
    SRW0(CONST_VAL(36), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tOrgPos.vusS
    SRW1(CONST_VAL(37), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tOrgPos.vusR
    SRW2(CONST_VAL(48), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tOrgPastPos[0].vusS = tOrgPos.vusS
    SRW3(CONST_VAL(49), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tOrgPastPos[0].vusR = tOrgPos.vusR

//	SRW0(CONST_VAL(82), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPosHist[22].x
//    SRW1(CONST_VAL(83), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPosHist[22].y
//    SRW2(CONST_VAL(84), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPosHist[23].x = tPastPosHist[22].x
//    SRW3(CONST_VAL(85), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPosHist[23].y = tPastPosHist[22].y 
	
	SRW0(CONST_VAL(80), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPosHist[21].x
    SRW1(CONST_VAL(81), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPosHist[21].y
    SRW2(CONST_VAL(82), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPosHist[22].x = tPastPosHist[21].x
    SRW3(CONST_VAL(83), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPosHist[22].y = tPastPosHist[21].y 
	
	SRW0(CONST_VAL(78), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPosHist[20].x
    SRW1(CONST_VAL(79), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPosHist[20].y
    SRW2(CONST_VAL(80), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPosHist[21].x = tPastPosHist[20].x
    SRW3(CONST_VAL(81), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPosHist[21].y = tPastPosHist[20].y 
	
	SRW0(CONST_VAL(76), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPosHist[19].x
    SRW1(CONST_VAL(77), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPosHist[19].y
    SRW2(CONST_VAL(78), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPosHist[20].x = tPastPosHist[19].x
    SRW3(CONST_VAL(79), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPosHist[20].y = tPastPosHist[19].y    
	
	SRW0(CONST_VAL(74), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPosHist[18].x
    SRW1(CONST_VAL(75), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPosHist[18].y
    SRW2(CONST_VAL(76), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPosHist[19].x = tPastPosHist[18].x
    SRW3(CONST_VAL(77), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPosHist[19].y = tPastPosHist[18].y     
	
	SRW0(CONST_VAL(72), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(73), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(74), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(75), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ;  

	SRW0(CONST_VAL(70), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(71), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(72), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(73), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ;  

	SRW0(CONST_VAL(68), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(69), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(70), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(71), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ;  
 
	SRW0(CONST_VAL(66), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(67), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(68), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(69), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ;  

	SRW0(CONST_VAL(64), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(65), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(66), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(67), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ;  

	SRW0(CONST_VAL(62), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(63), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(64), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(65), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ;  

	SRW0(CONST_VAL(60), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(61), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(62), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(63), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ;  

	SRW0(CONST_VAL(58), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(59), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(60), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(61), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ;  
 
	SRW0(CONST_VAL(56), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(57), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(58), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(59), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ;  

	SRW0(CONST_VAL(54), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(55), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(56), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(57), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ;  

	SRW0(CONST_VAL(52), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(53), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(54), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(55), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; 

	SRW0(CONST_VAL(50), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(51), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(52), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(53), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; 

	SRW0(CONST_VAL(48), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(49), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(50), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(51), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; 
 
	SRW0(CONST_VAL(46), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(47), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(48), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(49), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; 
                   
	SRW0(CONST_VAL(44), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(45), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(46), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(47), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; 
                   
	SRW0(CONST_VAL(42), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(43), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(44), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(45), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; 
                   
	SRW0(CONST_VAL(40), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; 
    SRW1(CONST_VAL(41), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; 
    SRW2(CONST_VAL(42), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; 
    SRW3(CONST_VAL(43), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; 

	SRW0(CONST_VAL(38), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPosHist[0].x
    SRW1(CONST_VAL(39), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPosHist[0].y
    SRW2(CONST_VAL(40), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),      //      ; CH2FLT WRITE : tPastPosHist[1].x = tPastPosHist[0].x
    SRW3(CONST_VAL(41), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),        //      ; CH3FLT WRITE : tPastPosHist[1].y = tPastPosHist[0].y 
	
    END()                                                                           //      ; 0x37000000
};
#endif

/********************************************************************************
  @brief    Label Edge Expand OPCODE
  */
#ifdef SRAM_OPCODE
int opcode_labeledgeexpand[] = 
#else
int opcode_labeledgeexpand[] = 
#endif
{
    // input A0~B6, loop_cnt C0~C1, interrupt A4~A6, B6
    SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : Delta
    SDMA1(REGA2, 0, DMA_SIZE1),                                                     //      ; A2 : label info
    SDMA2(REGA2, 0, DMA_SIZE1),                                                     //      ;
    SDMA3(REGA3, 0, DMA_SIZE2),                                                     //      ; A3 : EdgePen
    
	SRW1(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),	//      ; CH1FLT READ : ulStrength
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),	//      ; CH2FLT READ : ulExtStrength
	CMP(REGB6, CONST_VAL(LOCAL_HOVER_MODE)),                                        //      ; cmp(REGB6, LOCAL_HOVER_MODE), B6 : mode
	BRC(LINE_CNT(3), DOWN, NE),                                                   	//      ; mode != LOCAL_HOVER_MODE		-> JP12
	SRW3(CONST_VAL(36), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//      ; CH3FLT READ : hover_side_mul_val
	BRC(LINE_CNT(2), DOWN, AL),                                                    	//      ; Always              			-> JP13
	SRW3(CONST_VAL(32), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	// JP12 ; CH3FLT READ : side_mul_val
	
	SUBS(CONST_VAL(0), CONST_VAL(1), REGC2),                                        // JP13 ; REGC2 = 0 - 1, C2 : -1
	MOV(REGC2, REGC3),                                        						//      ; REGC3 = -1, C3 : search_r
	MOV(REGC2, REGC5),                                        						//      ; REGC5 = -1, C5 : search_c
	
	CMP(REGA4, CONST_VAL(1)),                                                     	//      ; cmp(REGA4, 1), A4 : check_r = MaxCell.r + ucCoordiRowStart
	BRC(LINE_CNT(4), DOWN, GT),                                                   	//      ; check_r > 1     				-> JP00
	MOV(CONST_VAL(1), REGC3),                                                      	//      ; REGC3 = 1, C3 : search_r	// code = 0
	MOV(REGC2, REGC4),                                        						//      ; REGC4 = -1, C4 : apply_r
	BRC(LINE_CNT(5), DOWN, AL),                                                    	//      ; Always              			-> JP01
	CMP(REGA4, REGA6),                                                     			// JP00 ; cmp(REGA4, REGA6), A6 : thisInfo->ucScreenRow-2
	BRC(LINE_CNT(3), DOWN, LT),                                                   	//      ; check_r < REGA6     			-> JP01
//	MOV(REGB5, REGC3),                                                      		//      ; REGC3 = REGB5, B5 : thisInfo->ucScreenRow-MUX_MAX_ROW-1
	ADD(REGB5, CONST_VAL(1), REGC3),                                        		//      ; REGC3 = REGB5 + 1, B5 : thisInfo->ucScreenRow-MUX_MAX_ROW-1
	ADD(REGB5, CONST_VAL(1), REGC4),                                        		//      ; REGC4 = REGB5 + 1
	
	CMP(REGA5, CONST_VAL(1)),                                                     	// JP01 ; cmp(REGA5, 1), A5 : check_c = MaxCell.c
	BRC(LINE_CNT(4), DOWN, GT),                                                   	//      ; check_c > 1     				-> JP02
	MOV(CONST_VAL(1), REGC5),                                                      	//      ; REGC5 = 1, C5 : search_c	// code = 0
	MOV(REGC2, REGC6),                                        						//      ; REGC6 = -1, C6 : apply_c
	BRC(LINE_CNT(5), DOWN, AL),                                                    	//      ; Always              			-> JP03
	CMP(REGA5, REGA7),                                                     			// JP02 ; cmp(REGA5, REGA7), A7 : thisInfo->ucScreenCol-2
	BRC(LINE_CNT(3), DOWN, LT),                                                   	//      ; check_c < REGA7     			-> JP03
	ADD(REGA7, CONST_VAL(2), REGC5),                                                //      ; REGC5 = REGA7 + 2	// code = thisInfo->ucScreenCol-1
	MOV(REGC5, REGC6),                                                      		//      ; REGC6 = REGC5
	
	MUL(CH1FLT, REGB0, REGB6),                                                   	// JP03 ; REGB6 = ulStrength * 256, B0 : 256
    SDMA1(REGA1, 0, DMA_SIZE2),                                                     //      ; A1 : map
	DIV(REGB6, CH2FLT, REGB6),                                                   	//      ; REGB6 = REGB6 / ulExtStrength
	SUB(REGB0, REGB6, REGB6),                                                   	//      ; REGB6 = 256 - REGB6, B6 : edge_ratio
	MUL(REGB6, CH3FLT, REGB7),                                                   	//      ; REGB7 = edge_ratio * side_mul_val, B7 : sum_val
	CMPS(REGC3, REGC2),                                                     		//      ; cmps(search_r, -1)
	BRC(LINE_CNT(35), DOWN, EQ),                                                   	//      ; search_r == -1     			-> JP04
	CMPS(REGC5, REGC2),                                                     		//      ; cmps(search_c, -1)
	BRC(LINE_CNT(4), DOWN, EQ),                                                   	//      ; search_c == -1     			-> JP05
	SRW3(CONST_VAL(33), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//      ; CH3FLT READ : edge_mul_val
	MUL(REGB6, CH3FLT, REGC7),                                                   	//      ; REGC7 = edge_ratio * edge_mul_val
	ADD(REGB7, REGC7, REGB7),                                                   	//      ; REGB7 = sum_val + REGC7
	
	DIV(REGB2, CH2FLT, REGA4),                                                   	// JP05 ; REGA4 = REGB2 / ulExtStrength, B2 : tCoord.x
	MUL(REGA4, REGB0, REGA4),                                                   	//      ; REGA4 = REGA4 * 256, A4 : check_val
	MUL(REGB2, REGB0, REGC7),                                                   	//      ; REGC7 = tCoord.x * 256
	DIV(REGC7, CH2FLT, REGC7),                                                   	//      ; REGC7 = REGC7 / ulExtStrength
	SUB(REGC7, REGA4, REGA4),														//		; REGA4 = REGC7 - check_val
	ADD(CONST_VAL(96), CONST_VAL(96), REGA5),										//		; REGA5 = 192
	CMP(REGA4, REGA5),                                                     			//      ; cmp(check_val, 192)
	BRC(LINE_CNT(3), DOWN, GE),                                                   	//      ; check_val >= 192     			-> JP06
	CMP(CONST_VAL(64), REGA4),                                                     	//      ; cmp(64, check_val)
	BRC(LINE_CNT(3), DOWN, LT),                                                   	//      ; 64 < check_val     			-> JP07
	SRW3(CONST_VAL(34), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),	// JP06 ; CH3FLT READ : odd_set_mul_val
	BRC(LINE_CNT(2), DOWN, AL),                                                    	//      ; Always              			-> JP08
	SRW3(CONST_VAL(35), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),	// JP07 ; CH3FLT READ : even_set_mul_val
	MUL(REGB6, CH3FLT, REGA6),                                                   	// JP08 ; REGA6 = edge_ratio * set_mul_val
	ADD(REGA6, REGB7, REGA6),														//		; REGA6 = REGA6 + sum_val, REGA6 : apply_val
	
	SLOOP1(0, 0, LOOP_LE, LOOP_REGC1),                                              //      ; column loop
    ADD(CNT1, REGB1, REGA7),                                                        //      ; REGA7 = CNT1 + REGB1, B1 : ucPadSize, A7 : c
    SRW1(REGA7, REGC3, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),                 //      ; CH1FLT = map(search_r, c)
	CMP(CH1FLT, CONST_VAL(0)),                                                     	//      ; cmp(CH1FLT, 0)
	BRC(LINE_CNT(9), DOWN, EQ),                                                   	//      ; check_val == 0     			-> JP09
	SRW0(REGA7, REGC3, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),                  //      ; CH0FLT00 = delta(search_r, c)
	MULS(CH0FLT00, REGA6, REGA4),                                                   //      ; REGA4 = CH0FLT00 * apply_val, A4 : _d
	DIVS(REGA4, REGB0, REGA4),                                                   	//      ; REGA4 = REGA4 / 256
	MULS(CNT1, REGA4, REGC7),                                                   	//      ; REGC7 = CNT1 * _d
	ADDS(REGB2, REGC7, REGB2),                                                   	//      ; REGB2 = tCoord.x + REGC7
	MULS(REGC4, REGA4, REGC7),                                                   	//      ; REGC7 = apply_r * _d
	ADDS(REGB3, REGC7, REGB3),                                                   	//      ; REGB3 = tCoord.y + REGC7, B3 : tCoord.y
	ADDS(REGB4, REGA4, REGB4),                                                   	//      ; REGB4 = ulExtStrength + _d, B4 : ulExtStrength
    ELOOP1(),                                                                       // JP09 ;
	
	CMPS(REGC5, REGC2),                                                     		// JP04 ; cmps(search_c, -1)
	BRC(LINE_CNT(15), DOWN, EQ),                                                   	//      ; search_c == -1     			-> JP10
	SLOOP0(0, 0, LOOP_LE, LOOP_REGC0),                                              //      ; row loop
    ADD(CNT0, REGB1, REGA7),                                                        //      ; REGA7 = CNT0 + REGB1, B1 : ucPadSize, A7 : r
    SRW1(REGC5, REGA7, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),                 //      ; CH1FLT = map(r, search_c)
	CMP(CH1FLT, CONST_VAL(0)),                                                     	//      ; cmp(CH1FLT, 0)
	BRC(LINE_CNT(9), DOWN, EQ),                                                   	//      ; check_val == 0     			-> JP11
	SRW0(REGC5, REGA7, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),                  //      ; CH0FLT00 = delta(r, search_c)
	MULS(CH0FLT00, REGB7, REGA4),                                                   //      ; REGA4 = CH0FLT00 * sum_val, A4 : _d
	DIVS(REGA4, REGB0, REGA4),                                                   	//      ; REGA4 = REGA4 / 256
	MULS(REGC6, REGA4, REGC7),                                                   	//      ; REGC7 = apply_c * _d
	ADDS(REGB2, REGC7, REGB2),                                                   	//      ; REGB2 = tCoord.x + REGC7
	MULS(CNT0, REGA4, REGC7),                                                   	//      ; REGC7 = CNT0 * _d
	ADDS(REGB3, REGC7, REGB3),                                                   	//      ; REGB3 = tCoord.y + REGC7
	ADDS(REGB4, REGA4, REGB4),                                                   	//      ; REGB4 = ulExtStrength + _d
    ELOOP0(),                                                                       // JP11 ;
    
    SDMA0(REGA2, 0, DMA_SIZE1),                                                     // JP10 ;
    SDMA1(REGA2, 0, DMA_SIZE1),                                                     //      ;
	SRW2(CONST_VAL(6), REGB4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),		//      ; REGB4 WRITE : ulExtStrength
	SRW0(CONST_VAL(3), REGB2, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//      ; REGB2 WRITE : tCoord.x
	SRW1(CONST_VAL(4), REGB3, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//      ; REGB3 WRITE : tCoord.y
	
    END()                                                                           //      ; 0x37000000
};

/********************************************************************************
  @brief    Pen Sleep OPCODE
  */
#ifdef SRAM_OPCODE
int opcode_penSleep[] = 
#else
int opcode_penSleep[] = 
#endif
{
    // Input : C0
	
	MOV(CONST_VAL(0), REGA0),                                                       //      ; REGA0 = 0
	SLOOP0(0, 0, LOOP_LE, LOOP_REGC0),                                              //      ; row loop
	ADD(REGA0, CONST_VAL(1), REGA0),                                                //      ; REGA0 = REGA0 + 1
	MUL(REGA0, CONST_VAL(2), REGA0),                                                //      ; REGA0 = REGA0 * 2
	ADD(REGA0, CONST_VAL(1), REGA0),                                                //      ; REGA0 = REGA0 + 1
	MUL(REGA0, CONST_VAL(2), REGA0),                                                //      ; REGA0 = REGA0 * 2
	ADD(REGA0, CONST_VAL(1), REGA0),                                                //      ; REGA0 = REGA0 + 1
	MUL(REGA0, CONST_VAL(2), REGA0),                                                //      ; REGA0 = REGA0 * 2
	ADD(REGA0, CONST_VAL(1), REGA0),                                                //      ; REGA0 = REGA0 + 1
	MUL(REGA0, CONST_VAL(2), REGA0),                                                //      ; REGA0 = REGA0 * 2
	ADD(REGA0, CONST_VAL(1), REGA0),                                                //      ; REGA0 = REGA0 + 1
	MUL(REGA0, CONST_VAL(2), REGA0),                                                //      ; REGA0 = REGA0 * 2
	ADD(REGA0, CONST_VAL(1), REGA0),                                                //      ; REGA0 = REGA0 + 1
	MUL(REGA0, CONST_VAL(2), REGA0),                                                //      ; REGA0 = REGA0 * 2
	ADD(REGA0, CONST_VAL(1), REGA0),                                                //      ; REGA0 = REGA0 + 1
	MUL(REGA0, CONST_VAL(2), REGA0),                                                //      ; REGA0 = REGA0 * 2
	ELOOP0(),                                                                       //      ;
	
    END()                                                                           //      ; 0x37000000
};


void TMH_COMPLETE_Method(void)
{
#if 0
    while((REG_TDSP2_BUSY & 0x01));
#endif
}


extern uint16_t currentRowStart;
//extern int currentRowEnd;
/********************************************************************************
  @brief    Pen Line Filter
  @return   None
  */
#if 1
void TMH_PenLineFilter (
		uint16_t        *pRawImg,       /**< input raw data buffer pointer */
    uint16_t        *pBaseImg,      /**< input base data buffer pointer */
		int             nWidth,         /**< width */
    int             nHeight,        /**< height */
		uint8_t					ucSmpNum				/**< Sampling Number */)
{
	DSP_CON->TDSP_CACHE_BASE = (uint32_t)opcode_linefilter>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pRawImg>>16;
	
	DSP_CON->TDSP_REGC0 = (uint32_t)nHeight;
	DSP_CON->TDSP_REGC1 = (uint32_t)(nWidth/ucSmpNum);
	DSP_CON->TDSP_REGC2 = (uint32_t)nWidth;
	DSP_CON->TDSP_REGA0 = ((uint32_t)pRawImg) & 0xFFFF; // NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA1 = ((uint32_t)pBaseImg) & 0xFFFF; // NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA2 = (uint32_t)currentRowStart;
	DSP_CON->TDSP_REGA3 = (uint32_t)0; 														// Column Start
	DSP_CON->TDSP_REGA4 = (uint32_t)INT16_MAX;
	DSP_CON->TDSP_REGA5 = (uint32_t)ucSmpNum;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_linefilter) & 0xFFFF; // opcode_linefilter;		// start // NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	
	TMH_COMPLETE_Method();

}
#endif

/********************************************************************************
  @brief    Pen calculate delta process
  @return   None
  */
#if 1
void TMH_PenCalDelta (
    uint16_t        *pRawImg,       /**< input raw data buffer pointer */
    uint16_t        *pBaseImg,      /**< input base data buffer pointer */
    uint8_t         *pNormalTbl,    /**< input normalize look-up table data buffer pointer */
    int16_t         *pDeltaImg,     /**< output delta data buffer pointer */
    tOrigDeltaInfo_t *pPenDeltaInfo, /**< output pen delta info buffer pointer */
    int             nCurrRowStart,  /**< start current row */
    int             nCurrColStart,  /**< start current column */
    int             nWidth,         /**< width */
    int             nHeight,        /**< height */
    bool_t            bNormalize,     /**< normalize flag */
    uint8_t         ucOvrShift,     /**< delta OvrShift */
    uint16_t        usSeedBase,     /**< label seed base threshold */
    uint8_t         ucMuxRowSize,   /**< mux row size */
    uint8_t         ucPadSize       /**< pad size */
)
{
	REG_TDSP2_C0 = (uint32_t)nHeight;
	REG_TDSP2_C1 = (uint32_t)nWidth;
	REG_TDSP2_A0 = (uint32_t)pRawImg;
	REG_TDSP2_A1 = (uint32_t)pBaseImg;
	REG_TDSP2_A2 = (uint32_t)pNormalTbl;
	REG_TDSP2_A3 = (uint32_t)pDeltaImg;
	REG_TDSP2_A4 = (uint32_t)nCurrRowStart;
	REG_TDSP2_A5 = (uint32_t)nCurrColStart;
	REG_TDSP2_A6 = (uint32_t)bNormalize;
	REG_TDSP2_A7 = (uint32_t)ucOvrShift;
	REG_TDSP2_B0 = (uint32_t)usSeedBase;
	REG_TDSP2_B1 = (uint32_t)ucMuxRowSize;
	REG_TDSP2_B2 = (uint32_t)ucPadSize;
	REG_TDSP2_B3 = (uint32_t)pPenDeltaInfo;
	REG_TDSP2_PC = (uint32_t)opcode_pendelta;        // start

	TMH_COMPLETE_Method();
    
    if(REG_TDSP2_B2 != 0)
    {
        currentRowStart = REG_TDSP2_A6;
//        currentRowEnd = REG_TDSP2_A7;
        pPenDeltaInfo->ucCurrentColumnStart = REG_TDSP2_A4;
        pPenDeltaInfo->ucCurrentColumnEnd = REG_TDSP2_A5;
    }
}
#endif

/********************************************************************************
  @brief    Pen Labeling Function
  @return   None
  */
#if 1
void TMH_PenLabeling (
    int16_t             *pSrc,          /**< input data buffer pointer */
    uint8_t           *pMap,          /**< output map data buffer pointer */
    tPenLabelInfo_t *pTLabelInfo,   /**< output label info buffer pointer */
    int             nLabelInfoSize, /**< label info size */
    int             nStart_r,       /**< start row */
    int             nEnd_r,         /**< end row */
    int             nStart_c,       /**< start column */
    int             nEnd_c,         /**< end column */
    int             nThreshold,     /**< threshold */
    uint8_t         ucPadSize       /**< pad size */
)
{
	DSP_CON->TDSP_CACHE_BASE = (uint32_t)opcode_labelproc>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pSrc>>16;
	
	DSP_CON->TDSP_REGC0 = (uint32_t)((nStart_r<<8) | nEnd_r);   // row loop
	DSP_CON->TDSP_REGC1 = (uint32_t)((nStart_c<<8) | nEnd_c);   // column loop
	DSP_CON->TDSP_REGA0 = ((uint32_t)pSrc) & 0xFFFF;		               		 // binary addr. // NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA1 = ((uint32_t)pMap) & 0xFFFF; 				        // label result addr.// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA2 = ((uint32_t)pTLabelInfo) & 0xFFFF; 				// label info addr. // NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA3 = (uint32_t)nThreshold;
	DSP_CON->TDSP_REGA4 = (uint32_t)nEnd_r;
	DSP_CON->TDSP_REGA5 = (uint32_t)nStart_r;
	DSP_CON->TDSP_REGA6 = (uint32_t)nEnd_c;
	DSP_CON->TDSP_REGA7 = (uint32_t)nStart_c;
	DSP_CON->TDSP_REGB1 = (uint32_t)ucPadSize;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_labelproc) & 0xFFFF; //opcode_label;		// start // NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?

	TMH_COMPLETE_Method();

}
#endif

/********************************************************************************
  @brief    Mark Boundary process
  @return   None
  */
void TMH_MarkBoundary (
    uint8_t        *pLabel,         //< input Label buffer pointer 
    int16_t        *pDelta,         //< input Delta buffer pointer
    int32_t         nStart_r,       //< start row 
    int32_t         nEnd_r,         //< end row 
    int32_t         nStart_c,       //< start column 
    int32_t         nEnd_c,         //< end column 
    int32_t         nTable_num,     //< 4data or 8data
    tPenLabelInfo_t *tTable,        //< Output tTable Structure pointer
    int32_t         Boundary,
    uint8_t	    ucPad_size
)
{
	DSP_CON->TDSP_CACHE_BASE = (uint32_t)opcode_markboundary>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pLabel>>16;
	
    DSP_CON->TDSP_REGC0 = (uint32_t)((nStart_r<<8) | nEnd_r);   // row loop
    DSP_CON->TDSP_REGC1 = (uint32_t)((nStart_c<<8) | nEnd_c);   // column loop
    DSP_CON->TDSP_REGA0 = ((uint32_t)pLabel) & 0xFFFF;		        // label addr.// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
    DSP_CON->TDSP_REGA1 = ((uint32_t)pDelta) & 0xFFFF; 			// delta addr.// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
    DSP_CON->TDSP_REGA2 = ((uint32_t)tTable) & 0xFFFF;                     // tTable addr// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
    DSP_CON->TDSP_REGA3 = (uint32_t)nTable_num;                 // 
//    DSP_CON->TDSP_REGA4 = (uint32_t)nStart_r;
//    DSP_CON->TDSP_REGA5 = (uint32_t)nEnd_r;
//    DSP_CON->TDSP_REGA6 = (uint32_t)nStart_c;
//    DSP_CON->TDSP_REGA7 = (uint32_t)nEnd_c;
    DSP_CON->TDSP_REGB1 = (uint32_t)ucPad_size;
    DSP_CON->TDSP_REGC2 = (uint32_t)Boundary;                   // 
    DSP_CON->TDSP_REGC3 = (uint32_t)LABEL_BOUNDARY_MARKER;      // Marker Value
    DSP_CON->TDSP_PC = ((uint32_t)opcode_markboundary) & 0xFFFF;        //opcode_markboundary// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?

	TMH_COMPLETE_Method();
}

/********************************************************************************
  @brief    Pen Coordinate Function
  @return   None
  */
#if 1
void TMH_PenCoordinate (
    tPenCoordInfo_t *pTCoordInfo,   /**< output coord info buffer pointer */
    tPenLabelInfo_t *pTLabelInfo,  	/**< input label info buffer pointer */
	tEdgePen_t 		*pTEdgePen,
	int mode
)
{
	DSP_CON->TDSP_CACHE_BASE = (uint32_t)opcode_coordproc>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = ((uint32_t)pTCoordInfo) & 0xFFFF;		            				// coord info addr.// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA1 = ((uint32_t)pTLabelInfo) & 0xFFFF; 				   					// label info addr.// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA2 = (uint32_t)POS_BOOST_SHIFT_;
	DSP_CON->TDSP_REGA3 = (uint32_t)COORD_HISTORY_NUM;
//	DSP_CON->TDSP_REGA4 = (uint32_t)(1<<thisModeConf->Coord.lMoveSmoothingLevel);
	DSP_CON->TDSP_REGA4 = (uint32_t)4;												// connect_count
	DSP_CON->TDSP_REGA5 = (uint32_t)(thisModeConf->Coord.lMoveSmoothingLevel);
	DSP_CON->TDSP_REGA6 = (uint32_t)thisInfo->tPenInfo.ucCoordiRowStart;            // ucCoordiRowStart
	DSP_CON->TDSP_REGB5 = (uint8_t)thisInfo->bLocal_sensing;
	DSP_CON->TDSP_REGB6 = (int8_t)thisInfo->tCoord_local.cIsbefor[0];
	DSP_CON->TDSP_REGB7 = (uint32_t)g_RetVal;
	DSP_CON->TDSP_REGC0 = (uint32_t)thisInfo->tCoord.iInternalXRes;  				// iInternalXRes
	DSP_CON->TDSP_REGC1 = (uint32_t)thisInfo->tCoord.iInternalYRes;  				// iInternalYRes
//	DSP_CON->TDSP_REGC2 = (uint32_t)thisInfo->tCoord.iXExpandStart;
//	DSP_CON->TDSP_REGC3 = (uint32_t)thisInfo->tCoord.iYExpandStart;
	DSP_CON->TDSP_REGC3 = (uint32_t)pTEdgePen;
	DSP_CON->TDSP_REGC2 = (uint32_t)mode;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_coordproc) & 0xFFFF; // opcode_coord;		// start// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?

	TMH_COMPLETE_Method();

}
#endif

/********************************************************************************
  @brief    Pen Smoothing Function
  @return   None
  */
#if 1
void TMH_PenSmoothing (
    tPenCoordInfo_t *pTCoordInfo,   /**< output coord info buffer pointer */
	int mode
)
{
	DSP_CON->TDSP_CACHE_BASE = (uint32_t)opcode_coordproc>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = ((uint32_t)pTCoordInfo) & 0xFFFF; // label info addr. // NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA2 = (uint32_t)POS_BOOST_SHIFT_;
	DSP_CON->TDSP_REGA3 = (uint32_t)COORD_HISTORY_NUM;
	DSP_CON->TDSP_REGA4 = (uint32_t)(1<<thisModeConf->Coord.lMoveSmoothingLevel);
	DSP_CON->TDSP_REGA5 = (uint32_t)(thisModeConf->Coord.lMoveSmoothingLevel);
	DSP_CON->TDSP_REGA6 = (uint32_t)thisInfo->tPenInfo.ucCoordiRowStart;                 // ucCoordiRowStart
	DSP_CON->TDSP_REGB6 = ((uint32_t)Gradient) & 0xFFFF;// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGC0 = (uint32_t)thisInfo->tCoord.iInternalXRes;  	// iInternalXRes
	DSP_CON->TDSP_REGC1 = (uint32_t)thisInfo->tCoord.iInternalYRes;  	// iInternalYRes
//	DSP_CON->TDSP_REGC2 = (uint32_t)thisInfo->tCoord.iXExpandStart;
//	DSP_CON->TDSP_REGC3 = (uint32_t)thisInfo->tCoord.iYExpandStart;
	DSP_CON->TDSP_REGC2 = (uint32_t)mode;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_smoothing) & 0xFFFF; // opcode_coord;		// start// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?

	TMH_COMPLETE_Method();

}
#endif

void TMH_PenCoord_PostProcess (
    tPenCoordInfo_t *pTCoordInfo   /**< output coord info buffer pointer */
)
{
	DSP_CON->TDSP_CACHE_BASE = (uint32_t)opcode_coordpost>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = ((uint32_t)pTCoordInfo) & 0xFFFF; // coord info addr. // NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA1 = (uint32_t)(1<<(POS_BOOST_SHIFT_));
	DSP_CON->TDSP_REGA2 = (uint32_t)(1<<(POS_BOOST_SHIFT_-5));
	DSP_CON->TDSP_REGA3 = (uint32_t)thisInfo->tCoord.iInternalXRes;  	// iInternalXRes
	DSP_CON->TDSP_REGA4 = (uint32_t)thisInfo->tCoord.iInternalYRes;  	// iInternalYRes
	DSP_CON->TDSP_REGA5 = (uint32_t)thisInfo->tCoord_local_dsp.tAvgPos.y; 	
	DSP_CON->TDSP_PC = ((uint32_t)opcode_coordpost) & 0xFFFF; // opcode_coord;		// start // NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?

	TMH_COMPLETE_Method();

}

/********************************************************************************
  @brief    Pen Coordinate Buffer Initialize Function
  @return   None
  */
void TMH_PenCoordInitialize(tPenCoordInfo_t *pTCoordInfo, tOrigDeltaInfo_t *pPenDeltaInfo)
{	
	DSP_CON->TDSP_CACHE_BASE = (uint32_t)opcode_coordinit>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = ((uint32_t)pTCoordInfo) & 0xFFFF; // coord info addr.// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA1 = ((uint32_t)pPenDeltaInfo) & 0xFFFF; // pen delta info addr. // NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_PC = ((uint32_t)opcode_coordinit) & 0xFFFF; // opcode_update;		// start// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
    
	TMH_COMPLETE_Method();
}

/********************************************************************************
  @brief    Pen Coordinate Info Update Function
  @return   None
  */
void TMH_PenUpdatePostHistoryInfo(tPenCoordInfo_t *pTCoordInfo)
{
	DSP_CON->TDSP_CACHE_BASE = (uint32_t)opcode_updateproc>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = ((uint32_t)pTCoordInfo) & 0xFFFF; // coord info addr.// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_PC = ((uint32_t)opcode_updateproc) & 0xFFFF; // opcode_update;		// start// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
    
	TMH_COMPLETE_Method();
}

/********************************************************************************
  @brief    Pen Labeling Edge Expand
  @return   None
  */
void TMH_PenLabelEdgeExpand(
    int16_t        	*pSrc,          //< input data buffer pointer */
    uint8_t         *pMap,          //< input map data buffer pointer */
    tPenLabelInfo_t *pTLabelInfo,   //< output label info buffer pointer */
	tEdgePen_t 		*pTEdgePen,		//< input pen edge info pointer */
    int32_t         nStart_r,       //< start row 
    int32_t         nEnd_r,         //< end row 
    int32_t         nStart_c,       //< start column 
    int32_t         nEnd_c,         //< end column 
    uint8_t         ucPadSize,      //< pad size
	int				mode			//< mode
)
{
	DSP_CON->TDSP_CACHE_BASE = (uint32_t)opcode_labeledgeexpand>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pSrc>>16;
	
	DSP_CON->TDSP_REGC0 = (uint32_t)((nStart_r<<8) | nEnd_r);   // row loop
	DSP_CON->TDSP_REGC1 = (uint32_t)((nStart_c<<8) | nEnd_c);   // column loop
	DSP_CON->TDSP_REGA0 = ((uint32_t)pSrc) & 0xFFFF;		               	// binary addr.// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA1 = ((uint32_t)pMap) & 0xFFFF; 				        // label result addr.// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA2 = ((uint32_t)pTLabelInfo) & 0xFFFF; 				// label info addr.// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?
	DSP_CON->TDSP_REGA3 = (uint32_t)pTEdgePen;
	DSP_CON->TDSP_REGA4 = (uint32_t)(pTLabelInfo->tValidMaxPos.r + thisInfo->tPenInfo.ucCoordiRowStart);
	DSP_CON->TDSP_REGA5 = (uint32_t)pTLabelInfo->tValidMaxPos.c;
	DSP_CON->TDSP_REGA6 = (uint32_t)thisInfo->ucScreenRow-2;
	DSP_CON->TDSP_REGA7 = (uint32_t)thisInfo->ucScreenCol-2;
	DSP_CON->TDSP_REGB0 = (uint32_t)256;
	DSP_CON->TDSP_REGB1 = (uint32_t)ucPadSize;
	DSP_CON->TDSP_REGB2 = (uint32_t)pTLabelInfo->tCoord.x;
	DSP_CON->TDSP_REGB3 = (uint32_t)pTLabelInfo->tCoord.y;
	DSP_CON->TDSP_REGB4 = (uint32_t)pTLabelInfo->ulExtStrength;
	DSP_CON->TDSP_REGB5 = (uint32_t)thisInfo->ucScreenRow-MUX_MAX_ROW-1;
	DSP_CON->TDSP_REGB6 = (uint32_t)mode;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_labeledgeexpand) & 0xFFFF;        //opcode_label;		// start// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?

	TMH_COMPLETE_Method();

}


/********************************************************************************
  @brief    Pen Sleep Function
  @return   None
  */

void TMH_PenSleep (
	int iIterationNum	/**< iteration number */
)
{
	DSP_CON->TDSP_CACHE_BASE = (uint32_t)opcode_penSleep>>16;
	
	DSP_CON->TDSP_REGC0 = (uint32_t)iIterationNum;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_penSleep) & 0xFFFF; // opcode_coord;		// start// NOTE : Address�몴占� 占쎄퐬占쎌젟 占쎈뻻 LSB筌랃옙 占쎄퐫占쎈선占쎈튊 占쎈릭占쎈뮉 占쎌뵠占쎌�占쎈뮉?

	TMH_COMPLETE_Method();

}

extern int HID_status[];
extern int HID_x[];
extern int HID_y[];

uint32_t TEST_PenX = 0;
uint32_t TEST_PenY = 0;

#if 0
void algorithm_PendPenEventforDSP(void)
{
	int distX, distY;
	tXY_t pos, old_pos;
	uint8_t ucMoveTHD;

	eSWIPPacketFormatId_t id = protocol_swip_GetPacketFormatId();

	if (thisInfo->tCoord_local_dsp.tPos.vusS > 0)
	{
		pos = thisInfo->tCoord_local_dsp.tPos.tXY;
		alogorithm_coord_modify_pos_local(&pos);

		TEST_PenX = pos.x;
		TEST_PenY = pos.y;
	}
}
#else
extern void protocol_hid_PushPenEvent(const uSWIPTouchItem_t* _kptItem);
extern uint8_t	g_ConnectedDevice;
void algorithm_PendPenEventforDSP(void)
{
    int i;
    int distX, distY;

    tXY_t pos, old_pos;
    uint8_t ucMoveTHD;
	
	memset(HID_status,0,1);
	memset(HID_x,0,1);
	memset(HID_y,0,1);
	
    eSWIPPacketFormatId_t id = protocol_swip_GetPacketFormatId();
#define SET_POS(tItem, pos)  \
    do {    \
    	(tItem).tItem00.ucXHigh = ((pos).x >> 8) & 0xFF;    \
        (tItem).tItem00.ucYHigh = ((pos).y >> 8) & 0xFF;    \
        (tItem).tItem00.ucXLow = (pos).x & 0xFF;    \
        (tItem).tItem00.ucYLow = (pos).y & 0xFF;    \
    } while(0)


	if(g_ConnectedDevice == I2C_CONNECT_PC)
	{
		protocol_swip_InitTouchEventBuffer();
	//    protocol_hid_InitPenEventBuffer();
	}
	
#if (SWIP_QUEUE_MODE)
	thisInfo->bQueueStart 	= 0;
	#if (SWIP_QUEUE_MODE == 2)
		thisInfo->bTouchOffFlag	= 0;
	#endif
#endif

#if USED_SHARP_SPECIFIC_PROTOCOL
	tTouchItemType_t touchItemType;
	memset(&touchItemType, 0, sizeof(tTouchItemType_t));
	/*
	 * TODO : finger mode�몴占� 疫꿸퀡�궚占쎌몵嚥∽옙 占쎄퐬占쎌젟.
	 * algorithm占쎌뱽 椰꾧퀣�뒊 占쎌뜎 touch type占쎈퓠 占쎈뎡�몴占� flag�몴占� setting 占쎈퉸占쎈튊 占쎈맙.
	 */
	touchItemType.active_stylus_hover = YES;
	touchItemType.active_stylus = YES;
	touchItemType.passive_stylus = YES;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */

    for (i = 0; i < 1; i++)
    {
        old_pos = thisInfo->tCoord_local_dsp.tPastSentPos.tXY;
        alogorithm_coord_modify_pos_local(&old_pos);

        if (thisInfo->tCoord_local_dsp.tPos.vusS > 0)
        {
        	pos = thisInfo->tCoord_local_dsp.tPos.tXY;

            alogorithm_coord_modify_pos_local(&pos);

            distX = pos.x - old_pos.x;
            distY = pos.y - old_pos.y;
            if (distY < 0)
                distY = -distY;
            if (distX < 0)
                distX = -distX;

            if (!thisInfo->tCoord_local_dsp.bFirstLongDistanceMoved)
                ucMoveTHD = 0;//thisModeConf->ucFirstMoveEventTHD;
            else
                ucMoveTHD = thisModeConf->ucMoveEventTHD;

            if (thisInfo->tCoord_local_dsp.tPastSentPos.vusS == 0 || (distY >= ucMoveTHD) || (distX >= ucMoveTHD))
            {
            	uSWIPTouchItem_t tItem;

#if USED_SHARP_SPECIFIC_PROTOCOL
				tItem.tItem00.tInfo.b4FingerID = i + 1;					// id
				tItem.tItem00.tInfo.b1Status = TOUCH_STATUS_PRESS;		// status
				tItem.tItem00.tInfo.b6Type = (touchItemType.finger << TOUCH_TYPE_FINGER) |
									  (touchItemType.glove << TOUCH_TYPE_GLOVE) |
									  (touchItemType.hover << TOUCH_TYPE_HOVER) |
									  (touchItemType.passive_stylus << TOUCH_TYPE_PASSIVE_STYLUS) |
									  (touchItemType.active_stylus << TOUCH_TYPE_ACTIVE_STYLUS) |
									  (touchItemType.active_stylus_hover << TOUCH_TYPE_ACTIVE_STYLUS_HOVER);
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.tInfo.bTouch = YES;
				tItem.tItem00.tInfo.bHover = NO;
				tItem.tItem00.tInfo.bScreen = YES;
				tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
				tItem.tItem00.tInfo.b4FingerID = i + 1;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.ucRowStart = currentRowStart;
//				if(gSensingMode) // Finger 筌뤴뫀諭뜹첎占� 占쎈툡占쎈빜 占쎈르.. Pen 筌뤴뫀諭� 占쎌뵬 野껋럩�뒭筌랃옙 Setting占쎈┷占쎄퐬..
//					SET_POS(tItem, pos);
				if(IS_FINGER_PEN_MODE(HAL_GetSensingMode()))
				{
					SET_POS(tItem, pos);
				}

                tItem.tItem00.ucWidth = thisInfo->tCoord_local_dsp.tPos.vusR;//MIN(thisInfo->tCoord_local_dsp.tPos.vusR, UINT8_MAX);

				if(id == 0)
                {
                    tItem.tItem00.usStrength = thisInfo->tCoord_local_dsp.tPos.vusS;
                }
                protocol_swip_PushTouchEvent(&tItem);
                protocol_hid_PushPenEvent(&tItem);

                if (thisInfo->tCoord_local_dsp.tPastSentPos.vusS > 0 && ((distY >= ucMoveTHD) || (distX >= ucMoveTHD)) ) //distance moved.
                {
                	thisInfo->tCoord_local_dsp.bFirstLongDistanceMoved = YES;
                }
                else //1st touch.
                {
                	thisInfo->tCoord_local_dsp.bFirstLongDistanceMoved = NO;
                }

                thisInfo->tCoord_local_dsp.tPastSentPos.tXY.x = thisInfo->tCoord_local_dsp.tPos.tXY.x;
                thisInfo->tCoord_local_dsp.tPastSentPos.tXY.y = thisInfo->tCoord_local_dsp.tPos.tXY.y;
                thisInfo->tCoord_local_dsp.tPastSentPos.vusS = thisInfo->tCoord_local_dsp.tPos.vusS;
                thisInfo->tCoord_local_dsp.tPastSentPos.vusR = thisInfo->tCoord_local_dsp.tPos.vusR;
            }
            else
            {
            	uSWIPTouchItem_t tItem;

#if USED_SHARP_SPECIFIC_PROTOCOL
				tItem.tItem00.tInfo.b4FingerID = i + 1;					// id
				tItem.tItem00.tInfo.b1Status = TOUCH_STATUS_PRESS;		// status
				tItem.tItem00.tInfo.b6Type = (touchItemType.finger << TOUCH_TYPE_FINGER) |
									  (touchItemType.glove << TOUCH_TYPE_GLOVE) |
									  (touchItemType.hover << TOUCH_TYPE_HOVER) |
									  (touchItemType.passive_stylus << TOUCH_TYPE_PASSIVE_STYLUS) |
									  (touchItemType.active_stylus << TOUCH_TYPE_ACTIVE_STYLUS) |
									  (touchItemType.active_stylus_hover << TOUCH_TYPE_ACTIVE_STYLUS_HOVER);
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.tInfo.bTouch = YES;
				tItem.tItem00.tInfo.bHover = NO;
				tItem.tItem00.tInfo.bScreen = YES;
				tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
				tItem.tItem00.tInfo.b4FingerID = i + 1;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.ucRowStart = currentRowStart;
				SET_POS(tItem, old_pos);
				tItem.tItem00.ucWidth = thisInfo->tCoord_local_dsp.tPos.vusR;//MIN(thisInfo->tCoord_local_dsp.tPos.vusR, UINT8_MAX);
				
				if(id == 0)
				{
					tItem.tItem00.usStrength = thisInfo->tCoord_local_dsp.tPos.vusS;
				}
				protocol_swip_PushTouchEvent(&tItem);
				protocol_hid_PushPenEvent(&tItem);
            }
        }
        else if (thisInfo->tCoord_local_dsp.tPastSentPos.vusS > 0)
        {
			#if (SWIP_QUEUE_MODE == 2)
				thisInfo->bTouchOffFlag = 1;
			#endif
			
        	uSWIPTouchItem_t tItem;
#if USED_SHARP_SPECIFIC_PROTOCOL
			tItem.tItem00.tInfo.b4FingerID = i + 1;					// id
			tItem.tItem00.tInfo.b1Status = TOUCH_STATUS_RELEASE;		// status
			tItem.tItem00.tInfo.b6Type = (touchItemType.finger << TOUCH_TYPE_FINGER) |
								  (touchItemType.glove << TOUCH_TYPE_GLOVE) |
								  (touchItemType.hover << TOUCH_TYPE_HOVER) |
								  (touchItemType.passive_stylus << TOUCH_TYPE_PASSIVE_STYLUS) |
								  (touchItemType.active_stylus << TOUCH_TYPE_ACTIVE_STYLUS) |
								  (touchItemType.active_stylus_hover << TOUCH_TYPE_ACTIVE_STYLUS_HOVER);
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
			tItem.tItem00.tInfo.bTouch = NO;
			tItem.tItem00.tInfo.bHover = NO;
			tItem.tItem00.tInfo.bScreen = YES;
			tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
			tItem.tItem00.tInfo.b4FingerID = i + 1;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
			tItem.tItem00.ucRowStart = 0;
            SET_POS(tItem, old_pos);
            tItem.tItem00.ucWidth = 0;

			if(id == 0)
            {
                tItem.tItem00.usStrength = thisInfo->tCoord_local_dsp.tPos.vusS;
            }

            thisInfo->tCoord_local_dsp.bFirstLongDistanceMoved = NO;

            protocol_swip_PushTouchEvent(&tItem);
            protocol_hid_PushPenEvent(&tItem);
        }
        thisInfo->tCoord_local_dsp.tPastSentPos.vusS = thisInfo->tCoord_local_dsp.tPos.vusS;
    }

#if 0
    if (thisInfo->tCoord_local.tKey.cSingleKeyIdx != -1)
    {
        if (thisInfo->tCoord_local.tKey.cSingleKeyIdx != thisInfo->tCoord_local.tPastSentKey.cSingleKeyIdx)
        {
            if (thisInfo->tCoord_local.tPastSentKey.cSingleKeyIdx != -1)
            {
            	uSWIPTouchItem_t tItem = {0,};
                tItem.tItem00.tInfo.bTouch = NO;
                tItem.tItem00.tInfo.bHover = NO;
                tItem.tItem00.tInfo.bScreen = NO;
                tItem.tItem00.tInfo.bPalm = NO;
                tItem.tItem00.tInfo.b4FingerID = thisInfo->tCoord_local.tPastSentKey.cSingleKeyIdx + 1;
                protocol_swip_PushTouchEvent(&tItem);
//                protocol_hid_PushPenEvent(&tItem);
            }
            {
            	uSWIPTouchItem_t tItem = {0,};
                tItem.tItem00.tInfo.bTouch = YES;
                tItem.tItem00.tInfo.bHover = NO;
                tItem.tItem00.tInfo.bScreen = NO;
                tItem.tItem00.tInfo.bPalm = NO;
                tItem.tItem00.tInfo.b4FingerID = thisInfo->tCoord_local.tKey.cSingleKeyIdx + 1;
                if(id == 0)
                {
//                    tItem.tItem00.usStrength = thisInfo->tCoord_local.tKey.vusS[thisInfo->tCoord_local.tKey.cSingleKeyIdx];
                }
                //protocol_swip_PushTouchEvent(&tItem);
                //protocol_hid_PushPenEvent(&tItem);
            }
        }
    }
    else if (thisInfo->tCoord_local.tPastSentKey.cSingleKeyIdx != -1)
    {
    	uSWIPTouchItem_t tItem = {0,};
        tItem.tItem00.tInfo.bTouch = NO;
        tItem.tItem00.tInfo.bHover = NO;
        tItem.tItem00.tInfo.bScreen = NO;
        tItem.tItem00.tInfo.bPalm = NO;
        tItem.tItem00.tInfo.b4FingerID = thisInfo->tCoord_local.tPastSentKey.cSingleKeyIdx + 1;
        protocol_swip_PushTouchEvent(&tItem);
       // protocol_hid_PushPenEvent(&tItem);
    }
#endif
		

#if (SWIP_QUEUE_MODE)
	if(thisInfo->bQueueStart == 1){
	#if (SWIP_QUEUE_MODE == 2)
		if(thisInfo->QueueFront == thisInfo->QueueRear || thisInfo->bTouchOffFlag )
	#endif
		{
			thisInfo->QueueRear++;
			thisInfo->QueueRear = (thisInfo->QueueRear) % SWIP_QUEUE_SIZE;
		}
	}
#endif	
	
//    thisInfo->tCoord_local.tPastSentPos.sFinger_ = thisInfo->tCoord_local.tPos.sFinger_;
    thisInfo->bWasPalm = thisInfo->bIsPalm;

//    thisInfo->tCoord_local.tPastSentKey = thisInfo->tCoord_local.tKey;
//    thisInfo->bTouchChecked = (thisInfo->tCoord_local.tPastSentPos.sFinger_ || thisInfo->tCoord_local.tPastSentKey.sKey_);

    protocol_swip_SendPenEvent();
//    protocol_hid_SendPenEvent();
		
#ifdef ADD_PEN
				SendPenData();
#endif

}
#endif

#ifdef RATE_UP_EN
extern uint8_t	g_ConnectedDevice;
void algorithm_PendPenEventforDSP_1(void)
{
    int i;
    int distX, distY;

    tXY_t pos, old_pos;
    uint8_t ucMoveTHD;
	
	memset(HID_status,0,1);
	memset(HID_x,0,1);
	memset(HID_y,0,1);

    eSWIPPacketFormatId_t id = protocol_swip_GetPacketFormatId();
#define SET_POS(tItem, pos)  \
    do {    \
    	(tItem).tItem00.ucXHigh = ((pos).x >> 8) & 0xFF;    \
        (tItem).tItem00.ucYHigh = ((pos).y >> 8) & 0xFF;    \
        (tItem).tItem00.ucXLow = (pos).x & 0xFF;    \
        (tItem).tItem00.ucYLow = (pos).y & 0xFF;    \
    } while(0)


	if(g_ConnectedDevice == I2C_CONNECT_PC)
	{
		protocol_swip_InitTouchEventBuffer();
	//    protocol_hid_InitPenEventBuffer();
	}
	
#if (SWIP_QUEUE_MODE)
	thisInfo->bQueueStart 	= 0;
	#if (SWIP_QUEUE_MODE == 2)
		thisInfo->bTouchOffFlag	= 0;
	#endif
#endif

    for (i = 0; i < 1; i++)
    {
        old_pos = thisInfo->tCoord_local_dsp.tPastSentPos.tXY;
        alogorithm_coord_modify_pos_local(&old_pos);

        if (thisInfo->tCoord_local_dsp.tPos.vusS > 0)
        {
        	pos = thisInfo->tCoord_local_dsp.tPos.tXY;

            alogorithm_coord_modify_pos_local(&pos);

            distX = pos.x - old_pos.x;
            distY = pos.y - old_pos.y;
            if (distY < 0)
                distY = -distY;
            if (distX < 0)
                distX = -distX;

            if (!thisInfo->tCoord_local_dsp.bFirstLongDistanceMoved)
                ucMoveTHD = 0;//thisModeConf->ucFirstMoveEventTHD;
            else
                ucMoveTHD = thisModeConf->ucMoveEventTHD;

            if (thisInfo->tCoord_local_dsp.tPastSentPos.vusS == 0 || (distY >= ucMoveTHD) || (distX >= ucMoveTHD))
            {
            	uSWIPTouchItem_t tItem;
                tItem.tItem00.tInfo.bTouch = YES;
                tItem.tItem00.tInfo.bHover = NO;
                tItem.tItem00.tInfo.bScreen = YES;
                tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
                tItem.tItem00.tInfo.b4FingerID = i + 1;//idx + 5;
								tItem.tItem00.ucRowStart = currentRowStart;
							if(gSensingMode)
								
                SET_POS(tItem, pos);
                tItem.tItem00.ucWidth = thisInfo->tCoord_local_dsp.tPos.vusR;//MIN(thisInfo->tCoord_local_dsp.tPos.vusR, UINT8_MAX);

				if(id == 0)
                {
                    tItem.tItem00.usStrength = thisInfo->tCoord_local_dsp.tPos.vusS;
                }
                protocol_swip_PushTouchEvent(&tItem);
                protocol_hid_PushPenEvent(&tItem);

                if (thisInfo->tCoord_local_dsp.tPastSentPos.vusS > 0 && ((distY >= ucMoveTHD) || (distX >= ucMoveTHD)) ) //distance moved.
                {
                	thisInfo->tCoord_local_dsp.bFirstLongDistanceMoved = YES;
                }
                else //1st touch.
                {
                	thisInfo->tCoord_local_dsp.bFirstLongDistanceMoved = NO;
                }

                thisInfo->tCoord_local_dsp.tPastSentPos.tXY.x = thisInfo->tCoord_local_dsp.tPos.tXY.x;
                thisInfo->tCoord_local_dsp.tPastSentPos.tXY.y = thisInfo->tCoord_local_dsp.tPos.tXY.y;
                thisInfo->tCoord_local_dsp.tPastSentPos.vusS = thisInfo->tCoord_local_dsp.tPos.vusS;
                thisInfo->tCoord_local_dsp.tPastSentPos.vusR = thisInfo->tCoord_local_dsp.tPos.vusR;
            }
            else
            {
            	uSWIPTouchItem_t tItem;
				tItem.tItem00.tInfo.bTouch = YES;
				tItem.tItem00.tInfo.bHover = NO;
				tItem.tItem00.tInfo.bScreen = YES;
				tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
				tItem.tItem00.tInfo.b4FingerID = i + 1;//idx + 5;
				tItem.tItem00.ucRowStart = currentRowStart;
				SET_POS(tItem, old_pos);
				tItem.tItem00.ucWidth = thisInfo->tCoord_local_dsp.tPos.vusR;//MIN(thisInfo->tCoord_local_dsp.tPos.vusR, UINT8_MAX);
				
				if(id == 0)
				{
					tItem.tItem00.usStrength = thisInfo->tCoord_local_dsp.tPos.vusS;
				}
				protocol_swip_PushTouchEvent(&tItem);
				protocol_hid_PushPenEvent(&tItem);
            }
        }
        else if (thisInfo->tCoord_local_dsp.tPastSentPos.vusS > 0)
        {
			#if (SWIP_QUEUE_MODE == 2)
				thisInfo->bTouchOffFlag = 1;
			#endif
			
        	uSWIPTouchItem_t tItem;
            tItem.tItem00.tInfo.bTouch = NO;
            tItem.tItem00.tInfo.bHover = NO;
            tItem.tItem00.tInfo.bScreen = YES;
            tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
            tItem.tItem00.tInfo.b4FingerID = i + 1;//idx + 5;
						tItem.tItem00.ucRowStart = 0;
            SET_POS(tItem, old_pos);
            tItem.tItem00.ucWidth = 0;

			if(id == 0)
            {
                tItem.tItem00.usStrength = thisInfo->tCoord_local_dsp.tPos.vusS;
            }

            thisInfo->tCoord_local_dsp.bFirstLongDistanceMoved = NO;

            protocol_swip_PushTouchEvent(&tItem);
            protocol_hid_PushPenEvent(&tItem);
        }
        thisInfo->tCoord_local_dsp.tPastSentPos.vusS = thisInfo->tCoord_local_dsp.tPos.vusS;
    }

#if (SWIP_QUEUE_MODE)
	if(thisInfo->bQueueStart == 1){
	#if (SWIP_QUEUE_MODE == 2)
		if(thisInfo->QueueFront == thisInfo->QueueRear || thisInfo->bTouchOffFlag )
	#endif
		{
			thisInfo->QueueRear++;
			thisInfo->QueueRear = (thisInfo->QueueRear) % SWIP_QUEUE_SIZE;
		}
	}
#endif	
	
//    thisInfo->tCoord_local.tPastSentPos.sFinger_ = thisInfo->tCoord_local.tPos.sFinger_;
    thisInfo->bWasPalm = thisInfo->bIsPalm;

//    thisInfo->tCoord_local.tPastSentKey = thisInfo->tCoord_local.tKey;
//    thisInfo->bTouchChecked = (thisInfo->tCoord_local.tPastSentPos.sFinger_ || thisInfo->tCoord_local.tPastSentKey.sKey_);

    protocol_swip_SendPenEvent();
//    protocol_hid_SendPenEvent();
		
#ifdef ADD_PEN
				SendPenData();
#endif

}
#endif

//extern __IO int  TEST_Flag_DSP_B;

void DSPB_WaitForIrq(void)
{
	while(g_ulDSPBIRQHandle == FALSE)
	{
		__WFI();
	}
}

#if 1
//extern int gDCFullMode;
//extern __IO int check_cnt;
//extern __IO int  DSP_B_Index;
ePartialSensing_t g_RetVal = PARTIAL_PEN_BEACON;
//extern uint8_t sensing_cont_cnt;
extern uint16_t g_pendata_pressure;
int32_t Tilt_sy = 0;
int PastTilt_x = 0;
int PastTilt_y = 0;
int32_t PastTilt_x1 = 0;
int32_t PastTilt_y1 = 0;
int Tilt_cnt = 0;
int8_t TiltUpDownST_X = 0;
int8_t TiltUpDownST_Y = 0;
bool_t UpDownChangeCheck = 0;
tXY_t Pen2PastPos[3] = {0,};
#ifdef TILT_ON
extern int16_t  MatrixS16_Tilt4Delta					[ROW_MAX][COL_MAX ];
#endif
bool_t ReportSkip = 0;
#define Tilt_Change_TH 500
int dbg[2] = {0,};

#ifdef TILT_ON
void algorithm_Tilt_Calculaion(void)
{
	static bool TiltUpFlag = 0;
	
	if(g_RetVal==PARTIAL_PEN_COORD2 && thisInfo->tPenInfo.bPenContact==YES)
	{
		int32_t sx = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x-thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x;
		Tilt_sy = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y-thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y;
		
		sx = sx * 1.375;
		Tilt_sy = Tilt_sy * 1.434;
		
		int32_t dist = ((sx*sx)+(Tilt_sy*Tilt_sy));
		dist = algorithm_calc_sqrt(dist);
		
		int8_t theta = dist/7;

		theta = ArcSinLookUpTable[(int8_t)theta];
		
		int H = 700 * ((double)CosLookUpTable[(int8_t)theta]/100);
		
		HID_TILT_X = algorithm_calc_angle_inter_2points(-sx,H);// - 9000;
		HID_TILT_Y = algorithm_calc_angle_inter_2points(-Tilt_sy,H);// - 9000;
		HID_AZIMUTH = algorithm_calc_angle_inter_2points(sx,Tilt_sy);
		HID_TWIST =  HID_AZIMUTH;//dist;//theta;
		HID_ALTITUDE = H;
		
		#ifdef TILT_SMOOTHING
		if(Tilt_cnt==1 || Tilt_cnt==2){
			HID_TILT_X = (PastTilt_x1 + HID_TILT_X + 1)>>1;
			HID_TILT_Y = (PastTilt_y1 + HID_TILT_Y + 1)>>1;
		}
		else if(Tilt_cnt>2){
//			HID_TILT_X = ((PastTilt_x1<<1) + PastTilt_x1 + HID_TILT_X + 2)>>2;
//			HID_TILT_Y = ((PastTilt_y1<<1) + PastTilt_y1 + HID_TILT_Y + 2)>>2;
			HID_TILT_X = ((PastTilt_x1<<3) - PastTilt_x1 + HID_TILT_X + 4)>>3;
			HID_TILT_Y = ((PastTilt_y1<<3) - PastTilt_y1 + HID_TILT_Y + 4)>>3;
//			HID_TILT_X = ((PastTilt_x1<<4) - PastTilt_x1 + HID_TILT_X + 8)>>4;
//			HID_TILT_Y = ((PastTilt_y1<<4) - PastTilt_y1 + HID_TILT_Y + 8)>>4;
//			HID_TILT_X = ((PastTilt_x1<<5) - PastTilt_x1 + HID_TILT_X + 16)>>5;
//			HID_TILT_Y = ((PastTilt_y1<<5) - PastTilt_y1 + HID_TILT_Y + 16)>>5;
//			int coef = 230;
//			HID_TILT_X = ((PastTilt_x1*coef) + (256-coef)*HID_TILT_X)>>8;
//			HID_TILT_Y = ((PastTilt_y1*coef) + (256-coef)*HID_TILT_Y)>>8;
		}
						
		PastTilt_x1 = HID_TILT_X; PastTilt_y1 = HID_TILT_Y;
		#endif
		
		#ifdef TILT_AREA_FILTER
		if(Tilt_cnt>0){
			int Tilt_SUB = HID_TILT_X - PastTilt_x;					
			if(Tilt_SUB > 0)TiltUpFlag = 1;
			else TiltUpFlag = 0;
			
			UpDownChangeCheck = 0;
			if(TiltUpDownST_X == 0)
			{
				PastTilt_x = HID_TILT_X;
				TiltUpDownST_X = 2;
			}	
			else if(TiltUpDownST_X==1)
			{
				if(TiltUpFlag==1)
				//if(Tilt_SUB>-50)
				{
					PastTilt_x=HID_TILT_X;
					UpDownChangeCheck=0;
				}
				else{
					//PenUpDownST_X = 2;
					UpDownChangeCheck = 1;		
				}
			}
			else if(TiltUpDownST_X==3)
			{
				if(TiltUpFlag==0)
				//if(Tilt_SUB<50)
				{
					PastTilt_x=HID_TILT_X;
					UpDownChangeCheck=0;
				}
				else {
					//PenUpDownST_X = 2;
					UpDownChangeCheck = 1;
				}							
			}					
			
			if(UpDownChangeCheck == 1 || TiltUpDownST_X == 2)
			{
				if(-Tilt_Change_TH<=Tilt_SUB && Tilt_SUB<=Tilt_Change_TH)HID_TILT_X=PastTilt_x;
				else if(Tilt_Change_TH<Tilt_SUB)
				{
					PastTilt_x=HID_TILT_X;
					TiltUpDownST_X = 1;
				}
				else if(-Tilt_Change_TH>Tilt_SUB)
				{
					PastTilt_x=HID_TILT_X;
					TiltUpDownST_X = 3;
				}
			}
			
			Tilt_SUB = HID_TILT_Y - PastTilt_y;
			if(Tilt_SUB > 0)TiltUpFlag = 1;
			else TiltUpFlag = 0;
			
			UpDownChangeCheck = 0;
			if(TiltUpDownST_Y == 0)
			{
				PastTilt_y = HID_TILT_Y;
				TiltUpDownST_Y = 2;
			}	
			else if(TiltUpDownST_Y==1)
			{
				if(TiltUpFlag==1)
				//if(Tilt_SUB>-50)
				{
					PastTilt_y=HID_TILT_Y;
					UpDownChangeCheck=0;
				}
				else{
					//TiltUpDownST_Y = 2;
					UpDownChangeCheck = 1;	
				}							
			}
			else if(TiltUpDownST_Y==3)
			{
				if(TiltUpFlag==0)
				//if(Tilt_SUB<50)
				{
					PastTilt_y=HID_TILT_Y;
					UpDownChangeCheck=0;
				}
				else{
					//TiltUpDownST_Y = 2;
					UpDownChangeCheck = 1;	
				}							
			}
			
			if(UpDownChangeCheck == 1 || TiltUpDownST_Y == 2)
			{
				if(-Tilt_Change_TH<=Tilt_SUB && Tilt_SUB<=Tilt_Change_TH)HID_TILT_Y=PastTilt_y;
				else if(-Tilt_Change_TH>Tilt_SUB)
				{
					PastTilt_y=HID_TILT_Y;
					TiltUpDownST_Y = 3;
				}
				else if(Tilt_Change_TH<Tilt_SUB)
				{
					PastTilt_y=HID_TILT_Y;
					TiltUpDownST_Y = 1;
				}
			}
		}
		else{
			PastTilt_x = HID_TILT_X;
			PastTilt_y = HID_TILT_Y;
		}	
		#endif
		
		#if (Pen2ReportMethod == 1)
		if(thisInfo->tCoord_local_dsp.tPastPos[1].vusS>0){
			thisInfo->tCoord_local_dsp.tPos.tXY.x = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x + (thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x - thisInfo->tCoord_local_dsp.tPastPos[1].tXY.x);
			thisInfo->tCoord_local_dsp.tPos.tXY.y = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y + (thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y - thisInfo->tCoord_local_dsp.tPastPos[1].tXY.y);
		}
		else
		{
			thisInfo->tCoord_local_dsp.tPos.tXY.x = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x;
			thisInfo->tCoord_local_dsp.tPos.tXY.y = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y;
		}
		thisInfo->tCoord_local_dsp.tPos.vusS = thisInfo->tCoord_local_dsp.tPastPos[0].vusS;
		#endif
		
		#if (Pen2ReportMethod == 1 || Pen2ReportMethod == 2 || Pen2ReportMethod == 3)
		if(thisInfo->tCoord_local_dsp.tOrgPastPos[1].vusS>0){
			thisInfo->tCoord_local_dsp.tOrgPos.tXY.x = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x + (thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x - thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.x);
			thisInfo->tCoord_local_dsp.tOrgPos.tXY.y = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y + (thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y - thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.y);
		}
		else
		{
			thisInfo->tCoord_local_dsp.tOrgPos.tXY.x = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x;
			thisInfo->tCoord_local_dsp.tOrgPos.tXY.y = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y;
		}
		thisInfo->tCoord_local_dsp.tOrgPos.vusS = thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS;
		#endif
		
		#if (Pen2ReportMethod == 3)
		ReportSkip = 1;
		thisInfo->tCoord_local_dsp.tPos.vusS = thisInfo->tCoord_local_dsp.tPastPos[0].vusS;
		thisInfo->tCoord_local_dsp.tOrgPastPos2.tXY.x = thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.x;
		thisInfo->tCoord_local_dsp.tOrgPastPos2.tXY.y = thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.y;
		thisInfo->tCoord_local_dsp.tOrgPastPos2.vusS = thisInfo->tCoord_local_dsp.tOrgPastPos[1].vusS;
		thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.x = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x;
		thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.y = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y;
		thisInfo->tCoord_local_dsp.tOrgPastPos[1].vusS = thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS;
		thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x;
		thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y;
		thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS = thisInfo->tCoord_local_dsp.tOrgPos.vusS;
		thisInfo->tCoord_local_dsp.tPastPos2.vusS = thisInfo->tCoord_local_dsp.tPastPos[1].vusS;
		thisInfo->tCoord_local_dsp.tPastPos[1].vusS = thisInfo->tCoord_local_dsp.tPastPos[0].vusS;
		thisInfo->tCoord_local_dsp.tPastPos[0].vusS = thisInfo->tCoord_local_dsp.tPos.vusS;
		#endif
		if(Tilt_cnt++ > 32765)Tilt_cnt = 10;
		//dbg[0] = currentRowStart;
	}
	else 
	{
		//dbg[1] = currentRowStart;
	}
	#if (Pen2ReportMethod == 0)
	thisInfo->tCoord_local_dsp.tPos.tXY.x = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x;
	thisInfo->tCoord_local_dsp.tPos.tXY.y = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y;
	#endif
}
#endif //TILT_ON end
				
void Call_DSP_B_Func(int index, int mode)
{
	int rs, re, cs, ce;
	static int sPMode = 0;
//	static int RateUpFlag = 0; // NOTE : warning�뜝�럩�젷濾곌쒀�삕
//	static bool smoothing_skip = 0; //Edge fast drawing 占쎈쐻占쎈윥筌묕옙 (edge 占쎌쐺獄�占쏙옙�땾占쎈쐩域밟뫁�굲占쎄덩占쎈㎜占쎌굲占쎈빝�뜝占� 占쎈쐻占쎈윥占쎌쓥占쎈쐻占쎈윪獄�占� 占쎈쐻占쎈윥�뤃�뼹�쐻占쎈윥獒뺧옙 占쎈눇�뙼�뿫�쑋�뜝�럥裕�) 占쎈쐻占쎈윞占쎈쭡占쎈쐻占쎈윪�얠±�쐻占쎈윞筌띾�ｋ쐻占쎈윪野껉막�쐻占쎈윞筌랃옙 占쎈쨬占쎈즵獒뺣돀�빝�뜝占� //hanch
	static int32_t PreMaxR = -1;
	static int32_t PreMaxC = -1;
	static uint16_t us_pendata_pressure = 0;
	static bool_t temp_PenContact;

	switch(index)
	{
		case PEN_COORD_INIT :
		{
			if(thisInfo->tPenInfo.bPrevPenContact == YES && thisInfo->tPenInfo.bPenContact == NO)
				g_pendata_pressure = us_pendata_pressure;
			
			temp_PenContact = thisInfo->tPenInfo.bPenContact;
			if(sPMode != mode && mode == LOCAL_MODE){
				#ifndef TILT_ON
				algorithm_coord_init_local_DSP();    
				#endif
//				RateUpFlag = 0; // NOTE : warning�뜝�럩�젷濾곌쒀�삕
				Tilt_cnt=0;
				PastTilt_x=0;
				PastTilt_y=0;
				PastTilt_x1=0;
				PastTilt_y1=0;
				Pen2PastPos[0].x = 0;
				Pen2PastPos[0].y = 0;
				Pen2PastPos[1].x = 0;
				Pen2PastPos[1].y = 0;
				Pen2PastPos[2].x = 0;
				Pen2PastPos[2].y = 0;
				Tilt_sy = 0;
				TiltUpDownST_X = 0;
				TiltUpDownST_Y = 0;
				UpDownChangeCheck = 0;
			}
			
			#ifdef RATE_UP_EN
			if(RateUpFlag>10 && RateUpFlag%2 == 0 && mode==LOCAL_MODE && thisInfo->tPenInfo.bPenContact>0 && thisInfo->bTouchExpect_local>0 && thisInfo->tCoord_local_dsp.tPos.vusS>0 && thisInfo->tCoord_local_dsp.tPastPos[0].vusS>0 && thisInfo->tCoord_local_dsp.tPastPos[1].vusS>0){
				tPastPosHist[0].x = thisInfo->tCoord_local_dsp.tPos.tXY.x = thisInfo->tCoord_local_dsp.tPos.tXY.x + (thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x-thisInfo->tCoord_local_dsp.tPastPos[1].tXY.x);
				tPastPosHist[0].y = thisInfo->tCoord_local_dsp.tPos.tXY.y = thisInfo->tCoord_local_dsp.tPos.tXY.y + (thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y-thisInfo->tCoord_local_dsp.tPastPos[1].tXY.y);
				algorithm_PendPenEventforDSP_1();
				TMH_PenUpdatePostHistoryInfo(&thisInfo->tCoord_local_dsp);
			}
			#endif
			
			DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE0);
			DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE0, 84);
			DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE0);
			DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE0, 8);//40

			DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE2);
			DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE2, (84+2));
			DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE2);
			DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE2, (8+2));

			DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE3);
			DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE3, (84));
			DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE3);
			DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE3, (45));

			DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE1);
			DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE1, LABEL_INFO_SIZE);
			DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE1);
			DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE1, LOOSE_POSBUF_);

			thisInfo->tCoord_local_dsp.tAvgPos.x = 0;
			thisInfo->tCoord_local_dsp.tAvgPos.y = 0;
			TMH_PenCoordInitialize(&thisInfo->tCoord_local_dsp, &thisInfo->tDelta_local);
			DSP_B_Index++;		// line filter 占쎈쐻占쎈윪占쎌졆占쎈쐻占쎈윪占쎈눞
		}
		break;

		case PEN_LINE_FILTER:
		{
//			thisInfo->bBlockTracking = YES;
			TMH_PenLineFilter(HAL_GET_LOCAL_RAW_IMAGE_PTR(), HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), thisInfo->ucScreenCol, 8, 4);
//			protocol_LogMatrix(LT_RAWDATA, 72, HAL_GET_LOCAL_RAW_IMAGE_PTR(), 84, 8, 84/*MAX Intensity*/);
		}
		break;

		case PEN_LABELING:
		{
			uint16_t usLabelThd;
			
//			if(mode == LOCAL_MODE || thisInfo->tPenInfo.ucHover_cnt != 0)
			{
				if(mode == LOCAL_HOVER_MODE)
				{
					if(thisInfo->tPenInfo.ucHover_cnt == 0)
					{
						algorithm_hover_accum_process();
						thisInfo->tPenInfo.ucHover_cnt = 1;
					}
					
					if(p_currentRowStart != currentRowStart)
						algorithm_hover_accum_move();
				}
				else
					thisInfo->tPenInfo.ucHover_cnt = 0;
				
//				algorithm_local_baseline_calculate_delta_DSP(mode);
				algorithm_local_baseline_calculate_delta(mode);
				
				#ifdef TILT_ON
				for(rs=0;rs<8;rs++)for(cs=0;cs<84;cs++)MatrixS16_Tilt4Delta[(g_RetVal-1)*8+rs][cs]=LocalSharedBuff.MatrixS16_PenDelta[rs+1][cs+1];
				#endif

//				protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_LOCAL_DELTA_IMAGE_PTR(), COL_MAX, 8, 81/*MAX Intensity*/);

				thisInfo->tLabel_local_dsp.tCoord.x = 0;
				thisInfo->tLabel_local_dsp.tCoord.y = 0;
				thisInfo->tLabel_local_dsp.ulStrength = 0;
				thisInfo->tLabel_local_dsp.ulExtStrength = 0;
				thisInfo->tLabel_local_dsp.usValidCellCnt = 0;
				thisInfo->tLabel_local_dsp.sValidMaxVal = 0;

				//memset(LOCALLABELIMAGE, 0, sizeof(LOCALLABELIMAGE));
				
				if( thisInfo->bTouchExpect_local )
				{
					#ifdef PenFingerSameLineNoiseException
					if(
					#ifdef TILT_ON
					g_RetVal!=PARTIAL_PEN_COORD2 &&
					#endif
					mode != LOCAL_HOVER_MODE && thisInfo->tDelta_local.tValidRect.ce - thisInfo->tDelta_local.tValidRect.cs > 3)
					{
						if((PreMaxC-thisInfo->tDelta_local.tMaxCellPos.c>3||PreMaxC-thisInfo->tDelta_local.tMaxCellPos.c<-3) && (PreMaxR!=-1 || PreMaxC!=-1))
						{
							thisInfo->tDelta_local.tValidRect.rs = PreMaxR;
							thisInfo->tDelta_local.tValidRect.re = PreMaxR;
							thisInfo->tDelta_local.tValidRect.cs = PreMaxC;
							thisInfo->tDelta_local.tValidRect.ce = PreMaxC;
						}
						else
						{
							thisInfo->tDelta_local.tValidRect.rs = thisInfo->tDelta_local.tMaxCellPos.r;
							thisInfo->tDelta_local.tValidRect.re = thisInfo->tDelta_local.tMaxCellPos.r;
							thisInfo->tDelta_local.tValidRect.cs = thisInfo->tDelta_local.tMaxCellPos.c;
							thisInfo->tDelta_local.tValidRect.ce = thisInfo->tDelta_local.tMaxCellPos.c;
						}
						
						if(thisInfo->tDelta_local.tValidRect.cs != 0)
							thisInfo->tPenInfo.ucCurrentColumnStart = thisInfo->tDelta_local.tValidRect.cs - 1;
						else
							thisInfo->tPenInfo.ucCurrentColumnStart = 0;
						
						if(thisInfo->tDelta_local.tValidRect.ce != thisInfo->ucScreenCol - 1)
							thisInfo->tPenInfo.ucCurrentColumnEnd = thisInfo->tDelta_local.tValidRect.ce + 2;
						else
							thisInfo->tPenInfo.ucCurrentColumnEnd = thisInfo->ucScreenCol;
					}
					#endif
					
					#ifdef TILT_ON
					if(g_RetVal==PARTIAL_PEN_COORD2 && mode != LOCAL_HOVER_MODE)usLabelThd  = 10;
					else
					#endif	
					usLabelThd  = thisModeConf->Label.usLocalSeedBase;
					usLabelThd += ((thisInfo->tDelta_local.iMaxStrength - thisModeConf->Label.usLocalSeedBase) * thisModeConf->Label.ucLocalSeedSlope)>>6;
					
					TMH_PenLabeling(HAL_GET_LOCAL_DELTA_IMAGE_PTR(), HAL_GET_LOCAL_LABEL_IMAGE_PTR(), &thisInfo->tLabel_local_dsp, LABEL_INFO_SIZE, thisInfo->tDelta_local.tValidRect.rs
					, thisInfo->tDelta_local.tValidRect.re, thisInfo->tDelta_local.tValidRect.cs, thisInfo->tDelta_local.tValidRect.ce, usLabelThd, PAD_);
				}
				else
				{
		#ifdef PenFingerSameLineNoiseException
					PreMaxR = -1;
					PreMaxC = -1;
		#endif /* PenFingerSameLineNoiseException */
					DSP_B_Index = PEN_COORDINATE;

					DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE2);
					DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE2, COORD_INFO_SIZE);
					DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE2);
					DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE2, LOOSE_POSBUF_);


					TMH_PenCoordinate(&thisInfo->tCoord_local_dsp, &thisInfo->tLabel_local_dsp, (tEdgePen_t *)&thisCommonConf->tEdgePenSetVal, mode);
				}
			}
//			else
//			{
//				algorithm_hover_accum_process();
//				thisInfo->tPenInfo.ucHover_cnt = 1;
//			}
		}
		break;

		case DSP_MARKBOUNDARY1:
		{	
			if( thisInfo->bTouchExpect_local )
			{
			
				#ifdef PenFingerSameLineNoiseException
				#ifdef TILT_ON
				if(g_RetVal!=PARTIAL_PEN_COORD2)
				#endif
				{
					PreMaxR = thisInfo->tLabel_local_dsp.tValidMaxPos.r;
					PreMaxC = thisInfo->tLabel_local_dsp.tValidMaxPos.c;
				}
				#endif
				
				cs = thisInfo->tLabel_local_dsp.tValidRect.cs; ce = thisInfo->tLabel_local_dsp.tValidRect.ce;
				rs = thisInfo->tLabel_local_dsp.tValidRect.rs; re = thisInfo->tLabel_local_dsp.tValidRect.re;
				
				if( cs > 0 )
					cs--;
				if( ce < (thisInfo->ucScreenCol - 1) )
					ce++;
				if( rs > 0 )
					rs--;
				if( re < (MAX_MUX_SIZE - 1) )
					re++;
				TMH_MarkBoundary(HAL_GET_LOCAL_LABEL_IMAGE_PTR(), HAL_GET_LOCAL_DELTA_IMAGE_PTR(), rs, re, cs, ce, 0, &thisInfo->tLabel_local_dsp, 0, PAD_);
			}
			
			#ifdef TILT_ON
			if(g_RetVal==PARTIAL_PEN_COORD2 && thisInfo->tPenInfo.bPenContact==YES)
				DSP_B_Index++;
			#endif
		}
		break;
		
		case DSP_MARKBOUNDARY2:
		{
			if( thisInfo->bTouchExpect_local )
			{
				cs = thisInfo->tLabel_local_dsp.tValidRect.cs; ce = thisInfo->tLabel_local_dsp.tValidRect.ce;
				rs = thisInfo->tLabel_local_dsp.tValidRect.rs; re = thisInfo->tLabel_local_dsp.tValidRect.re;
				if( cs > 0 )
					cs--;
				if( ce < (thisInfo->ucScreenCol - 1) )
					ce++;
				if( rs > 0 )
					rs--;
				if( re < (MAX_MUX_SIZE - 1) )
					re++;
				TMH_MarkBoundary(HAL_GET_LOCAL_LABEL_IMAGE_PTR(), HAL_GET_LOCAL_DELTA_IMAGE_PTR(), rs, re, cs, ce, 0, &thisInfo->tLabel_local_dsp, 1, PAD_);
			}
		}
		break;
		
		case PEN_LABEL_EDGE_EXPAND:
		{
			cs = thisInfo->tLabel_local_dsp.tValidRect.cs; ce = thisInfo->tLabel_local_dsp.tValidRect.ce;
			rs = thisInfo->tLabel_local_dsp.tValidRect.rs; re = thisInfo->tLabel_local_dsp.tValidRect.re;
			if( cs > 0 )
				cs--;
			if( ce < (thisInfo->ucScreenCol - 1) )
				ce++;
			if( rs > 0 )
				rs--;
			if( re < (MAX_MUX_SIZE - 1) )
				re++;
				
			TMH_PenLabelEdgeExpand(HAL_GET_LOCAL_DELTA_IMAGE_PTR(), HAL_GET_LOCAL_LABEL_IMAGE_PTR(), &thisInfo->tLabel_local_dsp, (tEdgePen_t *)&thisCommonConf->tEdgePenSetVal, rs, re, cs, ce, PAD_, mode);
		}
		break;

		case PEN_COORDINATE:
		{	
			DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE2);
			DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE2, COORD_INFO_SIZE);
			DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE2);
			DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE2, LOOSE_POSBUF_);

			TMH_PenCoordinate(&thisInfo->tCoord_local_dsp, &thisInfo->tLabel_local_dsp, (tEdgePen_t *)&thisCommonConf->tEdgePenSetVal, mode);
			
			#if (TILT_ON==1 && Pen2ReportMethod != 2)
			if(g_RetVal==PARTIAL_PEN_COORD2 && thisInfo->tPenInfo.bPenContact==YES)DSP_B_Index++;
			#endif
		}
		break;
		
		case PEN_SMOOTHING:
		{
			#if (TILT_ON && Pen2ReportMethod == 2)
			if(g_RetVal==PARTIAL_PEN_COORD2 && thisInfo->tPenInfo.bPenContact==YES){
				if(thisInfo->tCoord_local_dsp.tPastPos[1].vusS>0){
					thisInfo->tCoord_local_dsp.tPos.tXY.x = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x + (thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x - thisInfo->tCoord_local_dsp.tPastPos[1].tXY.x);
					thisInfo->tCoord_local_dsp.tPos.tXY.y = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y + (thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y - thisInfo->tCoord_local_dsp.tPastPos[1].tXY.y);
				}
				else
				{
					thisInfo->tCoord_local_dsp.tPos.tXY.x = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x;
					thisInfo->tCoord_local_dsp.tPos.tXY.y = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y;
				}	
			}
			#endif
					
			thisInfo->tCoord_local.cIsbefor[0] = (int8_t)DSP_CON->TDSP_REGB6;	// 占쎈쎗占쎈즵�몭�쓧�궘占쎌뵛占쎌굲�뜝�럥六� 占쎈쐻占쎈윪�얠±�쐻占쎈윪占쎌벁占쎈쐻占쎈윥占쎈군 TMH_PenCoordinate占쎈쨬占쎈즸占쎌굲 占쎈쐻占쎈윪�굢�뀘�쐻占쎈윥占쎄퐨占쎈쐻占쎈윥占쎈뭾占쎈쐻占쎈윥筌랃옙
			thisInfo->bLocal_sensing = (uint8_t)DSP_CON->TDSP_REGB5;			// 占쎈쎗占쎈즵�몭�쓧�궘占쎌뵛占쎌굲�뜝�럥六� 占쎈쐻占쎈윪�얠±�쐻占쎈윪占쎌벁占쎈쐻占쎈윥占쎈군 TMH_PenCoordinate占쎈쨬占쎈즸占쎌굲 占쎈쐻占쎈윪�굢�뀘�쐻占쎈윥占쎄퐨占쎈쐻占쎈윥占쎈뭾占쎈쐻占쎈윥筌랃옙
			
//#ifndef COVER_GLASS_USE
//			algorithm_coord_compensation(mode);
//#endif
			
			TMH_PenSmoothing(&thisInfo->tCoord_local_dsp, mode);
//			DSP_B_Index++;		// post process skip
		}
		break;

		case PEN_POST_PROCESS:
		{	
			thisInfo->tCoord_local_dsp.tAvgPos.x = 0;
			thisInfo->tCoord_local_dsp.tAvgPos.y = 0;
			if(thisInfo->tCoord_local_dsp.tPos.vusS == 0 || (thisInfo->tPenInfo.bPenContact==NO && thisInfo->tPenInfo.bPrevPenContact==YES))
			{
				thisInfo->tCoord_local_dsp.tAvgPos.y = 1;
			}
			TMH_PenCoord_PostProcess(&thisInfo->tCoord_local_dsp);
		}
		
		break;

		case PEN_UPDATE_POST_INFO:
		{
			if(hal_get_overlap_pen() == 0)
			{
				#ifdef RATE_UP_EN
				if(mode==LOCAL_MODE&&thisInfo->bTouchExpect_local>0&&thisInfo->tCoord_local_dsp.tPos.vusS>0&&thisInfo->tPenInfo.bPenContact&& thisInfo->tCoord_local_dsp.tPastPos[0].vusS>0 && thisInfo->tCoord_local_dsp.tPastPos[1].vusS>0)
					RateUpFlag++;
				else RateUpFlag = 0;
				#endif

				#ifdef TILT_ON
				algorithm_Tilt_Calculaion();
				#endif
				
				if(mode == LOCAL_MODE && thisInfo->tCoord_local_dsp.tAvgPos.x>0){
					thisInfo->tCoord_local.cIsbefor[0] = 0;
					thisInfo->bLocal_sensing = YES;
					if(thisInfo->tPenInfo.bPrevPenContact == YES)
						thisInfo->tPenInfo.bPenContact = YES;
//					RateUpFlag = 0; // NOTE : warning�뜝�럩�젷濾곌쒀�삕
				}
				
			#ifdef TILT_ON
				if(!ReportSkip)
				{
					algorithm_PendPenEventforDSP();
					TMH_PenUpdatePostHistoryInfo(&thisInfo->tCoord_local_dsp);
				}
				else ReportSkip = 0;
			#else
				algorithm_PendPenEventforDSP();
				TMH_PenUpdatePostHistoryInfo(&thisInfo->tCoord_local_dsp);
			#endif
				
				if(algorithm_mode_change_check())
				{
					hal_set_SubState_flag(TOUCH_NORMAL_OPER_NORMAL_READY);
					hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
				}

				DSP_B_Index++;		// check app_normal
				sPMode = mode;
				thisInfo->tPenInfo.bPenContact = temp_PenContact;

				if(thisInfo->tPenInfo.bPrevPenContact == YES && thisInfo->tPenInfo.bPenContact == NO)
					g_pendata_pressure = 1;
								
				thisInfo->tPenInfo.bPrevPenContact = thisInfo->tPenInfo.bPenContact;
				us_pendata_pressure = g_pendata_pressure;
			}
			else
			{
				DSP_B_Index--;		// wait finger pend
				TMH_PenSleep(90);//90);	// max 254
			}
		}
		break;

		default:
		break;
	}
}

//ePartialSensing_t g_RetVal = PARTIAL_PEN_BEACON;
int gLmode;
void algorithm_local_dsp_process(int index, ePartialSensing_t RetVal, int mode)
{
	if(index == 1)
	{
		g_RetVal = RetVal;
		gLmode = mode;
	}
	
   DSP_B_Index = index;
   Call_DSP_B_Func(index, gLmode);
}

#else
void algorithm_local_dsp_process(void)
{
#if 1
	int rs, re, cs, ce;

	DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE0);
	DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE0, 72);
	DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE0);
	DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE0, 8);//40
	
	DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE2);
	DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE2, (72+2));
	DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE2);
	DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE2, (8+2));
	
	DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE3);
	DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE3, (72));
	DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE3);
	DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE3, (40));
	
	DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE1);
	DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE1, LABEL_INFO_SIZE);
	DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE1);
	DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE1, LOOSE_POSBUF_);

	TMH_PenCoordInitialize(&thisInfo->tCoord_local_dsp, &thisInfo->tDelta_local);	
	
//	thisInfo->bBlockTracking = YES;
	TMH_PenLineFilter(HAL_GET_LOCAL_RAW_IMAGE_PTR(), HAL_GET_LOCAL_BASELINE_IMAGE_PTR(), thisInfo->ucScreenCol, 8, 4);

	
	protocol_LogMatrix(LT_RAWDATA, 72, HAL_GET_LOCAL_RAW_IMAGE_PTR(), 72, 9, 84/*MAX Intensity*/);

	algorithm_local_baseline_calculate_delta(LOCAL_MODE);	
	
	// Copy
	thisInfoCode = algorithm_GetInfo();
	thisInfo->bTouchExpect_local = thisInfoCode->bTouchExpect_local;
	thisInfo->tDelta_local.tValidRect.rs = thisInfoCode->tDelta_local.tValidRect.rs;
	thisInfo->tDelta_local.tValidRect.re = thisInfoCode->tDelta_local.tValidRect.re;
	thisInfo->tDelta_local.tValidRect.cs = thisInfoCode->tDelta_local.tValidRect.cs;
	thisInfo->tDelta_local.tValidRect.ce = thisInfoCode->tDelta_local.tValidRect.ce;
	thisInfo->tPenInfo.ucCoordiRowStart = thisInfoCode->tPenInfo.ucCoordiRowStart;
	thisInfo->tCoord.iInternalXRes = thisInfoCode->tCoord.iInternalXRes;
	thisInfo->tCoord.iInternalYRes = thisInfoCode->tCoord.iInternalYRes;
	thisInfo->tCoord.iXExpandStart = thisInfoCode->tCoord.iXExpandStart;
	thisInfo->tCoord.iYExpandStart = thisInfoCode->tCoord.iYExpandStart;

	protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_LOCAL_DELTA_IMAGE_PTR(), COL_MAX, 8, 81/*MAX Intensity*/);	

	thisInfo->tLabel_local_dsp.tCoord.x = 0;
	thisInfo->tLabel_local_dsp.tCoord.y = 0;
	thisInfo->tLabel_local_dsp.ulStrength = 0;
	thisInfo->tLabel_local_dsp.ulExtStrength = 0;
	thisInfo->tLabel_local_dsp.usValidCellCnt = 0;
	thisInfo->tLabel_local_dsp.sValidMaxVal = 0;
	
	memset(LOCALLABELIMAGE, 0, sizeof(LOCALLABELIMAGE));
	
	if( thisInfo->bTouchExpect_local )
	{
		TMH_PenLabeling(HAL_GET_LOCAL_DELTA_IMAGE_PTR(), HAL_GET_LOCAL_LABEL_IMAGE_PTR(), &thisInfo->tLabel_local_dsp, LABEL_INFO_SIZE, thisInfo->tDelta_local.tValidRect.rs, thisInfo->tDelta_local.tValidRect.re, thisInfo->tDelta_local.tValidRect.cs, thisInfo->tDelta_local.tValidRect.ce, thisModeConf->Label.usSeedBase, PAD_);

		cs = thisInfo->tLabel_local_dsp.tValidRect.cs; ce = thisInfo->tLabel_local_dsp.tValidRect.ce;
		rs = thisInfo->tLabel_local_dsp.tValidRect.rs; re = thisInfo->tLabel_local_dsp.tValidRect.re;
		if( cs > 0 )
			cs--;
		if( ce < (thisInfo->ucScreenCol - 1) )
			ce++;
		if( rs > 0 )
			rs--;
		if( re < (thisInfo->ucScreenRow - 1) )
			re++;
		TMH_MarkBoundary(HAL_GET_LOCAL_LABEL_IMAGE_PTR(), HAL_GET_LOCAL_DELTA_IMAGE_PTR(), rs, re, cs, ce, 0, &thisInfo->tLabel_local_dsp, 1, PAD_);
	}

	DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE2);
	DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE2, COORD_INFO_SIZE);
	DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE2);
	DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE2, LOOSE_POSBUF_);

	TMH_PenCoordinate(&thisInfo->tCoord_local_dsp, &thisInfo->tLabel_local_dsp, (tEdgePen_t *)&thisCommonConf->tEdgePenSetVal, LOCAL_MODE);

	algorithm_PendPenEventforDSP();

	TMH_PenUpdatePostHistoryInfo(&thisInfo->tCoord_local_dsp);

#endif
}
#endif
#endif	// !defined(FINGER_ONLY)
