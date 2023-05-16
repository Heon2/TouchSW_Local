/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : DSP_B.c
 * created on : 10. 05. 2019
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
#include "protocol_def.h"


#if (USED_PEN_MODE_OPERATION)

static const tAlgorithmCommonConf_t * thisCommonConf = NULL;
static const tAlgorithmModeConf_t * thisModeConf = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;
//static const tModuleCommonConf_t * _ptModuleCommonConf = NULL;
#if USED_NOISE_HOPPING_FREQ
	static tAppInfo_t * ptAppInfo = NULL;
#endif /* USED_NOISE_HOPPING_FREQ */

eActivePenType_t gAlgoRawDataType;
extern uint16_t currentRowStart;
extern uint16_t p_currentRowStart;
extern ePartialSensing_t g_RetVal;
extern int HID_PEN_X;
extern int HID_PEN_Y;
extern uint32_t RawAddr, BaseAddr, BaseAddr_MuxSum, RawAddr_MuxSum;
extern uint16_t * g_pLocalBaseImage;
#if USED_NOISE_HOPPING_FREQ
	extern uint16_t * g_pLocalHop1BaseImage;
#endif /* USED_NOISE_HOPPING_FREQ */
extern int16_t * g_pFullHoverImage;

#ifdef ADD_PEN
// Pen ScanTime
extern uint32_t 	g_ScanTime_Pen;
#else
uint32_t 	g_ScanTime_Pen;
#endif
//int dbg_dspB[4]={0,};
extern __IO uint16_t sensingRowStart_Tilt;

#endif /* (USED_PEN_MODE_OPERATION) */

#if USED_ADAPTIVE_LOCAL_SENSING
extern __IO uint16_t sensingRoicStart;
#endif /* USED_ADAPTIVE_LOCAL_SENSING */

//__IO int  TEST_Flag_DSP_B = TRUE;
__IO static uint32_t g_ulDSPBIRQHandle;

void DSP_B_InterruptHandler(void)
{
#if (USED_PEN_MODE_OPERATION)
	Clear_DSP_B_Intr();

	if(thisInfo->tPenInfo.ucDSP_B_Index < PEN_UPDATE_POST_INFO)
	{
		thisInfo->tPenInfo.ucDSP_B_Index++;
		algorithm_local_dsp_process(thisInfo->tPenInfo.ucDSP_B_Index,PARTIAL_PEN_BEACON, thisInfo->tPenInfo.ucDspB_Lmode);
	}

#ifdef TILT_ON
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN && CUSTOMER != MODEL_DEF_QHD_92512_Dell_WGP_UHD_PEN)	
	if(g_RetVal==PARTIAL_PEN_COORD_DATA3 && thisInfo->tPenInfo.ucDSP_B_Index == PEN_UPDATE_POST_INFO+1)
	{
		algorithm_local_dsp_process(1, PARTIAL_TILT1, LOCAL_TILT_MODE);
	}
	#endif
	
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)	
	if(((thisModeConf->PenTilt.ucMS_RingMode == 0 && g_RetVal == PARTIAL_PEN_COORD3) || (thisModeConf->PenTilt.ucMS_RingMode == 1 && g_RetVal == PARTIAL_PEN_COORD1) || (thisModeConf->PenTilt.ucMS_RingMode == 2 && (g_RetVal == PARTIAL_PEN_COORD1||g_RetVal == PARTIAL_PEN_COORD3))) && thisInfo->tPenInfo.ucDSP_B_Index == PEN_UPDATE_POST_INFO+1)
	//if(g_RetVal == PARTIAL_PEN_COORD1 && thisInfo->tPenInfo.ucDSP_B_Index == PEN_UPDATE_POST_INFO+1)
	{
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		if(ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType)
		#endif
		algorithm_local_dsp_process(1, g_RetVal, LOCAL_TILT_MODE);
	}
	#endif			
#endif
	
#else /* (USED_PEN_MODE_OPERATION */
	Clear_DSP_B_Intr();
#endif /* (USED_PEN_MODE_OPERATION */

	g_ulDSPBIRQHandle = TRUE;
}

void init_DSP_B(void)
{
	Fncp_DSP_B_IRQHandler = &DSP_B_InterruptHandler;
	//********************************************************
	// Interrupt Enable 
	//********************************************************
//	REG_TDSP2_INTERRUPT = (1<<4) | (1<<0); 		// Disable Interrupt Mask | Clear Interrupt
	
	NVIC_EnableIRQ (DSP_B_IRQn);    /* Interrupt Enable */	
	NVIC_SetPriority(DSP_B_IRQn, DSP_B_IRQn_Priority);
}

void Clear_DSP_B_Intr(void)
{
	REG_TDSP2_INTERRUPT |= (1<<0); // Clear Interrupt
}

#if (USED_PEN_MODE_OPERATION)

void algorithm_coord_init_local_DSP(void)
{
	// local coord init
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
	thisInfo->tCoord_local_dsp.cIsbefor = 0;
    
    thisInfo->tCoord_local_dsp.tFirstPos.x = -1;
    thisInfo->tCoord_local_dsp.tFirstPos.y = 0;
}

void algorithm_init_local(void)
{
//	_ptModuleCommonConf = module_GetCommonConfig();
//	ptModuleModeConf = module_GetModeConfig();
//	ptAppInfo        = app_GetInfo();
	thisCommonConf   = algorithm_GetCommonConfig();	
	thisModeConf     = algorithm_GetModeConfig();
	thisInfo         = algorithm_GetInfo();
#if USED_NOISE_HOPPING_FREQ
	ptAppInfo		 = app_GetInfo();
#endif /* USED_NOISE_HOPPING_FREQ */

//	thisInfo->ucTxLessCol = _ptModuleCommonConf->ucTxLessCol_;
//	thisInfo->ucTxLessRow = _ptModuleCommonConf->ucTxLessRow_;

//	thisInfo->ucScreenCol = _ptModuleCommonConf->ucScreenCol_;
//	thisInfo->ucScreenCol = _ptModuleCommonConf->ucScreenRow_;

//	thisInfo->ucCol = COL_MAX + thisInfo->ucTxLessCol;
//	thisInfo->ucRow = ROW_MAX + thisInfo->ucTxLessRow;

	memset(LOCALDELTAIMAGE, 0, sizeof(LOCALDELTAIMAGE));

	algorithm_coord_init_local_DSP();
}

void algorithm_init_param_dsp(void)
{
//	thisCommonConf   = algorithm_GetCommonConfig();
	thisModeConf     = algorithm_GetModeConfig();
//	thisInfo         = algorithm_GetInfo();
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
//		MOV(CNT0, REGB0),                                                      					//      ; B0 = CNT0, B0: Raw Row Idx
//		ADD(REGB0, REGA2, REGB1),                                                       		//      ; B1 = CNT0 + A2 : nCurrRowStart, B1 : Base Row Idx
		ADD(CNT0, REGA6, REGB0),                                                      	//      ; B0 = CNT0 + A6, A6 : Row Start Idx, B0: Raw Row Idx
		ADD(CNT0, REGA2, REGB1),                                                        //      ; B1 = CNT0 + A2 : nCurrRowStart, B1 : Base Row Idx
		MOV(REGA4, REGB4),                                                      				//      ; B4 = A4 : FIRST_MIN = INT16_MAX
		MOV(REGA4, REGB5),                                                      				//      ; B5 = A4 : SECOND_MIN = INT16_MAX
		MOV(REGA4, REGB6),                                                      				//      ; B6 = A4 : THIRD_MIN = INT16_MAX
		MOV(REGA4, REGB7),                                                      				//      ; B7 = A4 : FOURTH_MIN = INT16_MAX
		
		SLOOP1(0, 0, LOOP_LT, LOOP_REGC1),                                              //      ; Col loop -> 0:Col/4
		MUL(CNT1, REGA5, REGB2),                                                      	//      ; B2 = CNT1 * REGA5 : SmpNum, B2: Raw Col Idx
		ADD(REGB2, REGA3, REGB3),                                                       //      ; B3 = REGB2 + A3 : nCurrColStart, B3 : Base Col Idx
    SRW0(REGB2, REGB0, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                	//      ; CH0FLT00 = pRawImg(REGB2, REGB0)
		SRW1(REGB3, REGB1, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                //      ; CH1FLT = pBaseImg(REGB3, REGB1)
		SUBS(CH0FLT00, CH1FLT, REGC7),																									//			; C7 = pRawImg - pBaseImg : Delta
		CMPS(REGB4, REGC7),                                                      		//      ; cmps(FIRST_MIN, Delta)
		BRC(LINE_CNT(6), DOWN, LES),                                                    //      ; FIRST_MIN <= Delta  -> JP00
		MOV(REGB6, REGB7),                                                     			//      ; FOURTH_MIN = THIRD_MIN
		MOV(REGB5, REGB6),                                                      		//      ; THIRD_MIN = SECOND_MIN
		MOV(REGB4, REGB5),                                                      		//      ; SECOND_MIN = FIRST_MIN
		MOV(REGC7, REGB4),                                                       		//      ; FIRST_MIN = Delta
		BRC(LINE_CNT(15), DOWN, AL),                                                    //      ; Always              -> JP03
		CMPS(REGB5, REGC7),                                                      				// JP00 ; cmps(SECOND_MIN, Delta)
		BRC(LINE_CNT(5), DOWN, LES),                                                    //      ; SECOND_MIN <= Delta -> JP01
		MOV(REGB6, REGB7),                                                     			//      ; FOURTH_MIN = THIRD_MIN
		MOV(REGB5, REGB6),                                                      		//      ; THIRD_MIN = SECOND_MIN
		MOV(REGC7, REGB5),                                                      		//      ; SECOND_MIN = Delta
		BRC(LINE_CNT(9), DOWN, AL),                                                     //      ; Always              -> JP03
		CMPS(REGB6, REGC7),                                                      		// JP01 ; cmps(THIRD_MIN, Delta)
		BRC(LINE_CNT(4), DOWN, LES),                                                    //      ; THIRD_MIN <= Delta  -> JP02
		MOV(REGB6, REGB7),                                                     			//      ; FOURTH_MIN = THIRD_MIN
		MOV(REGC7, REGB6),                                                      		//      ; THIRD_MIN = Delta
		BRC(LINE_CNT(4), DOWN, AL),                                                     //      ; Always              -> JP03
		CMPS(REGB7, REGC7),                                                      		// JP02 ; cmps(FOURTH_MIN, Delta)
		BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; FOURTH_MIN <= Delta -> JP03
		MOV(REGC7, REGB7),                                                     			//      ; FOURTH_MIN = Delta
		ELOOP1(),                                                                       // JP03 ;
		
		SLOOP1(0, 0, LOOP_LT, LOOP_REGC2),                                              //      ; Col loop -> 0:Col
		MOV(CNT1, REGB2),                                                      			//      ; B2 = CNT1, B2: Raw Col Idx
		SRW0(REGB2, REGB0, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                //      ; CH0FLT00 = pRawImg(REGB2, REGB0)
		SUBS(CH0FLT00, REGB7, REGC7),													//			; C7 = pRawImg - FOURTH_MIN
		CMPS(REGC7,CONST_VAL(0)),
		BRC(LINE_CNT(2), DOWN, GES),
		MOV(CONST_VAL(0), REGC7),
		MOV(REGC7, CH0FLT00),                                                           		// 		; CH0FLT00 = REGC7
		SRW0(REGB2, REGB0, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_16BIT),    		        	//      ; CH0FLT00 WRITE
		ELOOP1(),                                                                       		//
		
		ELOOP0(),                                                                       //
    
    END()                                                                         	//      ; end
};
#endif

/********************************************************************************
  @brief    Pen calculate delta
  */
#ifdef CalculateDeltaLocalSearch_OPCODE
#ifdef SRAM_OPCODE
int opcode_pendelta[] = 
#else
int opcode_pendelta[] = 
#endif
{
	CMPS(REGB4, CONST_VAL(LOCAL_SEARCH_MODE)),                                      //      ; cmps(mode, LOCAL_SEARCH_MODE)
#ifdef FingerAreaPenDeltaDelete
	#ifdef FingerAreaPenDeltaNoAcc
		#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
			#ifdef TILT_ON
			BRC(LINE_CNT(350), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#else
			BRC(LINE_CNT(337), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#endif
		#else // #if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
			#ifdef TILT_ON
			BRC(LINE_CNT(330), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#else
			BRC(LINE_CNT(317), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#endif
		#endif // #if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	#else // #ifdef FingerAreaPenDeltaNoAcc
		#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
			#ifdef TILT_ON
			BRC(LINE_CNT(329), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#else
			BRC(LINE_CNT(316), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#endif
		#else // #if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
			#ifdef TILT_ON
			BRC(LINE_CNT(309), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#else
			BRC(LINE_CNT(296), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#endif
		#endif // #if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	#endif	
#else // #ifdef FingerAreaPenDeltaDelete
	#ifdef FingerAreaPenDeltaNoAcc
		#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
			#ifdef TILT_ON
			BRC(LINE_CNT(329), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#else
			BRC(LINE_CNT(316), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#endif
		#else // #if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
			#ifdef TILT_ON
			BRC(LINE_CNT(309), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#else
			BRC(LINE_CNT(296), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#endif
		#endif // #if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	#else
		#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
			#ifdef TILT_ON
			BRC(LINE_CNT(308), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#else
			BRC(LINE_CNT(295), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#endif
		#else // #if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
			#ifdef TILT_ON
			BRC(LINE_CNT(288), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#else
			BRC(LINE_CNT(275), DOWN, NE),											//      ; mode != LOCAL_SEARCH_MODE              								-> JP00
			#endif
		#endif // #if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	#endif	// #ifdef FingerAreaPenDeltaNoAcc
#endif // #ifdef FingerAreaPenDeltaDelete
	
	SDMA0(REGB2,0,DMA_SIZE3),                                                       //      ; REGB2 : thisInfo->PenCalcDeltaSetVal 
	SDMA1(REGA0,0,DMA_SIZE3),                                                       //      ; REGA0 : Raw Buffer
	
	SLOOP0(0, 0, LOOP_LT, LOOP_REGC0),                                              // 		; row loop	for(r=start_r; r<end_r; r++)
	SLOOP1(0, 0, LOOP_LT, LOOP_REGC1),                                              // 		; col loop	for(c=start_c; c<end_c; c++)
	
    SDMA2(REGA1,0,DMA_SIZE3),                                                       //      ; REGA1 : Baseline Buffer
	SRW0(CONST_VAL(14), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	//      ; CH0FLT00 READ : raw_idx
	ADDS(CNT0, CH0FLT00, REGB4),													//		; B4 = r + raw_idx
	SRW0(CONST_VAL(4), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), 	//      ; CH0FLT00 READ : local_rs
	ADDS(CNT0, CH0FLT00, REGB7),													//		; B7 = r + local_rs
	SRW0(CONST_VAL(15), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	//      ; CH0FLT00 READ : base_idx
	ADDS(REGB7, CH0FLT00, REGB5),													//		; B5 = r + local_rs + base_idx
	SRW1(CNT1, REGB4, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                 //      ; CH1FLT = raw(c, r + raw_idx)
	SRW2(CNT1, REGB5, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                 //      ; CH2FLT = base(c, r + local_rs + base_idx)
	SRW0(CONST_VAL(41), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	//      ; CH0FLT00 READ : bMS_phase
	CMPS(CH0FLT00, CONST_VAL(1)),                                      				//      ; cmps(bMS_phase, 1)
	BRC(LINE_CNT(3), DOWN, NE),														//      ; bMS_phase != 1              											-> JP03
	SUBS(CH1FLT, CH2FLT, REGB6),													//		; B6 = raw - base ; delta
	BRC(LINE_CNT(2), DOWN, AL),														//      ; Always              													-> JP04
	SUBS(CH2FLT, CH1FLT, REGB6),													// JP03 ; B6 = base - raw ; delta
	
#ifdef FingerAreaPenDeltaDelete
	SRW0(CONST_VAL(49), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	// JP04 ; CH0FLT00 READ : cFingerAreaPenDeltaDelete
	MOV(CH0FLT00, REGB4),															//		; B4 = cFingerAreaPenDeltaDelete
	CMPS(REGB4, CONST_VAL(0)),                                      				//      ; cmps(cFingerAreaPenDeltaDelete, 0)
	BRC(LINE_CNT(18), DOWN, EQ),													//      ; cFingerAreaPenDeltaDelete == 0              							-> JP05
	SRW0(CONST_VAL(44), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	//		; CH0FLT00 READ : LocalFingerArea.rs
	SUBS(CH0FLT00, REGB4, REGB5),													//		; B5 = LocalFingerArea.rs - cFingerAreaPenDeltaDelete
	CMPS(REGB5, REGB7),                                      						//      ; cmps(LocalFingerArea.rs - cFingerAreaPenDeltaDelete, r + local_rs)
	BRC(LINE_CNT(14), DOWN, GTS),													//      ; LocalFingerArea.rs - cFingerAreaPenDeltaDelete > r + local_rs        	-> JP05
	SRW0(CONST_VAL(45), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	//		; CH0FLT00 READ : LocalFingerArea.re
	ADDS(CH0FLT00, REGB4, REGB5),													//		; B5 = LocalFingerArea.re + cFingerAreaPenDeltaDelete
	CMPS(REGB5, REGB7),                                      						//      ; cmps(LocalFingerArea.re + cFingerAreaPenDeltaDelete, r + local_rs)
	BRC(LINE_CNT(10), DOWN, LTS),													//      ; LocalFingerArea.re + cFingerAreaPenDeltaDelete < r + local_rs        	-> JP05
	SRW0(CONST_VAL(46), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	//		; CH0FLT00 READ : LocalFingerArea.cs
	SUBS(CH0FLT00, REGB4, REGB5),													//		; B5 = LocalFingerArea.cs - cFingerAreaPenDeltaDelete
	CMPS(REGB5, CNT1),                                      						//      ; cmps(LocalFingerArea.cs - cFingerAreaPenDeltaDelete, c)
	BRC(LINE_CNT(6), DOWN, GTS),													//      ; LocalFingerArea.cs - cFingerAreaPenDeltaDelete > c        			-> JP05
	SRW0(CONST_VAL(47), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	//		; CH0FLT00 READ : LocalFingerArea.ce
	ADDS(CH0FLT00, REGB4, REGB5),													//		; B5 = LocalFingerArea.ce + cFingerAreaPenDeltaDelete
	CMPS(REGB5, CNT1),                                      						//      ; cmps(LocalFingerArea.ce + cFingerAreaPenDeltaDelete, c)
	BRC(LINE_CNT(2), DOWN, LTS),													//      ; LocalFingerArea.ce + cFingerAreaPenDeltaDelete < c        			-> JP05
	MOV(CONST_VAL(0), REGB6),														//		; delta = 0
#endif
	SRW0(CONST_VAL(18), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	// JP05 ; CH0FLT00 READ : MuxSum
	CMPS(CH0FLT00, CONST_VAL(1)),                                      				//      ; cmps(MuxSum, 1)
	BRC(LINE_CNT(14), DOWN, NE),													//      ; MuxSum != 1              												-> JP06
	SRW0(CONST_VAL(16), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	//      ; CH0FLT00 READ : MuxSum_raw_idx
	ADDS(CNT0, CH0FLT00, REGB4),													//		; B4 = r + MuxSum_raw_idx	
	SRW0(CONST_VAL(17), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	//      ; CH0FLT00 READ : MuxSum_base_idx
	ADDS(REGB7, CH0FLT00, REGB5),													//		; B5 = r + local_rs + MuxSum_base_idx	
	SRW1(CNT1, REGB4, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                 //      ; CH1FLT = raw(c, r + MuxSum_raw_idx)
	SRW2(CNT1, REGB5, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                 //      ; CH2FLT = base(c, r + local_rs + MuxSum_base_idx)
	SUBS(CH2FLT, CH1FLT, REGC6),													// 		; C6 = base - raw ; delta2
	CMPS(REGC7, CONST_VAL(ACTIVEPEN_TYPE_LOCAL_MS)),                         	    //      ; cmps(gAlgoRawDataType, ACTIVEPEN_TYPE_LOCAL_MS)
	BRC(LINE_CNT(4), DOWN, NE),														//      ; gAlgoRawDataType != ACTIVEPEN_TYPE_LOCAL_MS              				-> JP07
	CMPS(REGC6, CONST_VAL(0)),                             							//      ; cmps(delta2, 0)
	BRC(LINE_CNT(2), DOWN, GES),													//      ; delta2 >= 0              												-> JP07
	SUBS(CONST_VAL(0), REGC6, REGC6),												// 		; delta2 = 0 - delta2
	ADDS(REGB6, REGC6, REGB6),														// JP07 ; delta = delta + delta2
	
	SRW0(CONST_VAL(19), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	// JP06 ; CH0FLT00 READ : ucLocalOvrShift
	SRLS(REGB6, CH0FLT00, REGB6),                                              		//      ; delta = delta >> ucLocalOvrShift
	
	CMPS(REGB6, CONST_VAL(15)),                                      				//      ; cmps(delta, 15)
	BRC(LINE_CNT(4), DOWN, GTS),													//      ; delta > 15              												-> JP08
	SUBS(CONST_VAL(0), CONST_VAL(15), REGB4),										// 		; -15 = 0 - 15
	CMPS(REGB6, REGB4),                                      						//      ; cmps(delta, -15)
	BRC(LINE_CNT(2), DOWN, GES), 													//      ; delta >= -15              											-> JP09
	SRW0(CONST_VAL(53), CONST_VAL(1), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),	// JP08 ; CH0FLT00 WRITE : bBlockTrackingByLocalDelta = 1

	CMPS(REGC7, CONST_VAL(ACTIVEPEN_TYPE_LOCAL_WACOM)),                        		// JP09 ; cmps(gAlgoRawDataType, ACTIVEPEN_TYPE_LOCAL_WACOM)
	BRC(LINE_CNT(8), DOWN, EQ),														//      ; gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM              			-> JP10
	CMPS(REGC7, CONST_VAL(ACTIVEPEN_TYPE_LOCAL_WGP)),                          		//      ; cmps(gAlgoRawDataType, ACTIVEPEN_TYPE_LOCAL_WGP)
	BRC(LINE_CNT(6), DOWN, EQ),														//      ; gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP              			-> JP10
	CMPS(REGC7, CONST_VAL(ACTIVEPEN_TYPE_LOCAL_MS)),                          		//      ; cmps(gAlgoRawDataType, ACTIVEPEN_TYPE_LOCAL_MS)
	BRC(LINE_CNT(73), DOWN, NE),													//      ; gAlgoRawDataType != ACTIVEPEN_TYPE_LOCAL_MS              				-> JP11
	SRW0(CONST_VAL(42), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	// 		; CH0FLT00 READ : bMS_Contact2bit[0]
	CMPS(CH0FLT00, CONST_VAL(0)),                        							//      ; cmps(bMS_Contact2bit[0], 0)
	BRC(LINE_CNT(70), DOWN, NE),													//      ; bMS_Contact2bit[0] != 0              									-> JP11
	SRW0(CONST_VAL(16), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT), 	// JP10 ; CH0FLT00 READ : tmp_AdaptorNoiseTH
	MOV(CH0FLT00, REGC6),															//		; C6 = tmp_AdaptorNoiseTH
	CMPS(REGC6, CONST_VAL(0)),                        								//      ; cmps(tmp_AdaptorNoiseTH, 0)
	BRC(LINE_CNT(66), DOWN, EQ),													//      ; tmp_AdaptorNoiseTH == 0              									-> JP11
	
	SDMA3(REGA7,0,DMA_SIZE3),                                                       //      ; REGA7 : LOCALNOISEBUF2
	CMPS(REGC7, CONST_VAL(ACTIVEPEN_TYPE_LOCAL_MS)),                          		//      ; cmps(gAlgoRawDataType, ACTIVEPEN_TYPE_LOCAL_MS)
	BRC(LINE_CNT(7), DOWN, NE),														//      ; gAlgoRawDataType != ACTIVEPEN_TYPE_LOCAL_MS              				-> JP12
	SRW1(CNT1, CNT0, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                  //      ; CH1FLT = raw(c, r)
	SRW2(CNT1, REGB7, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                 //      ; CH2FLT = base(c, r + local_rs)
	SUBS(CH2FLT, CH1FLT, REGB5),													// 		; B5 = base - raw ; temp_delta
	SRW0(CONST_VAL(19), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	// 		; CH0FLT00 READ : ucLocalOvrShift
	SRLS(REGB5, CH0FLT00, REGB5),                                              		//      ; temp_delta = temp_delta >> ucLocalOvrShift
	BRC(LINE_CNT(2), DOWN, AL),														//      ; Always              													-> JP13
	MOV(REGB6, REGB5),																// JP12 ; B5 = delta ; temp_delta
	CMPS(REGB5, REGC6),                        										// JP13 ; cmps(temp_delta, tmp_AdaptorNoiseTH)
	BRC(LINE_CNT(44), DOWN, GES),													//      ; temp_delta >= tmp_AdaptorNoiseTH              						-> JP14
	CMPS(REGC7, CONST_VAL(ACTIVEPEN_TYPE_LOCAL_MS)),                          		//      ; cmps(gAlgoRawDataType, ACTIVEPEN_TYPE_LOCAL_MS)
	BRC(LINE_CNT(4), DOWN, NE),														//      ; gAlgoRawDataType != ACTIVEPEN_TYPE_LOCAL_MS              				-> JP15
	SRW0(CONST_VAL(15), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT), 	// 		; CH0FLT00 READ : g_RetVal
	CMPS(CH0FLT00, CONST_VAL(PARTIAL_PEN_COORD1)),                        			//      ; cmps(g_RetVal, PARTIAL_PEN_COORD1)
	BRC(LINE_CNT(39), DOWN, NE),													//      ; g_RetVal != PARTIAL_PEN_COORD1         								-> JP14
	
	SRW0(CONST_VAL(17), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT), 	// JP15 ; CH0FLT00 READ : tmp_AdaptorNoiseContiNum
	MOV(CH0FLT00, CH3FLT),															// 		; CH3FLT = tmp_AdaptorNoiseContiNum
	SUBS(CNT1, CONST_VAL(2), REGB4),												//		; B4 = c - 2
	_MAX(CONST_VAL(0), REGB4, REGB4),												//		; MAX(0, c - 2)
	ADDS(CNT1, CONST_VAL(2), REGB5),												// 		; B5 = c + 2
	SRW0(CONST_VAL(27), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), 	// 		; CH0FLT00 READ : col_max
	SUBS(CH0FLT00, CONST_VAL(1), REGC6),											// 		; C6 = col_max - 1
	_MIN(REGC6, REGB5, REGB5),														//		; MIN(col_max - 1, c + 2)
	
	SUBS(REGB7, CONST_VAL(1), REGC6),												//		; C6 = (r + local_rs) - 1
	CMPS(REGC6, CONST_VAL(0)),                          							//      ; cmps((r + local_rs) - 1, 0)
	BRC(LINE_CNT(10), DOWN, LTS),													//      ; (r + local_rs) - 1 < 0              									-> JP16
	SLOOP2(REGB4, REGB5, LOOP_LE, LOOP_SOURCE),                                     // 		; loop c - 2 : c + 2
	SRW3(CNT2, REGC6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    			    //      ; CH3FLT WRITE ; LOCALNOISEBUF2
    ELOOP2(),                                                                       //      ; loop end
	
	SUBS(REGB7, CONST_VAL(2), REGC6),												//		; C6 = (r + local_rs) - 2
	CMPS(REGC6, CONST_VAL(0)),                          							//      ; cmps((r + local_rs) - 2, 0)
	BRC(LINE_CNT(4), DOWN, LTS),													//      ; (r + local_rs) - 2 < 0              									-> JP16
	SLOOP2(REGB4, REGB5, LOOP_LE, LOOP_SOURCE),                                     // 		; loop c - 2 : c + 2
	SRW3(CNT2, REGC6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),	    		    //      ; CH3FLT WRITE ; LOCALNOISEBUF2
    ELOOP2(),                                                                       //      ; loop end
	
	MOV(REGB7, REGC6),																// JP16 ; REGC6 = (r + local_rs)
	SLOOP2(REGB4, REGB5, LOOP_LE, LOOP_SOURCE),                                     // 		; loop c - 2 : c + 2
	SRW3(CNT2, REGC6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    			    //      ; CH3FLT WRITE ; LOCALNOISEBUF2
    ELOOP2(),                                                                       //      ; loop end
	
	SRW0(CONST_VAL(28), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), 	// 		; CH0FLT00 READ : row_max
	ADDS(REGB7, CONST_VAL(1), REGC6),												//		; C6 = (r + local_rs) + 1
	CMPS(REGC6, CH0FLT00),                          								//      ; cmps((r + local_rs) + 1, row_max)
	BRC(LINE_CNT(16), DOWN, GES),													//      ; (r + local_rs) + 1 >= row_max  	            						-> JP17
	SLOOP2(REGB4, REGB5, LOOP_LE, LOOP_SOURCE),                                     // 		; loop c - 2 : c + 2
	SRW3(CNT2, REGC6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    		 		//      ; CH3FLT WRITE ; LOCALNOISEBUF2
    ELOOP2(),                                                                       //      ; loop end
	
	ADDS(REGB7, CONST_VAL(2), REGC6),												//		; C6 = (r + local_rs) + 2
	CMPS(REGC6, CH0FLT00),                          								//      ; cmps((r + local_rs) + 2, row_max)
	BRC(LINE_CNT(10), DOWN, GES),													//      ; (r + local_rs) + 1 >= row_max  	            						-> JP17
	SLOOP2(REGB4, REGB5, LOOP_LE, LOOP_SOURCE),                                     // 		; loop c - 2 : c + 2
	SRW3(CNT2, REGC6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    			    //      ; CH3FLT WRITE ; LOCALNOISEBUF2
    ELOOP2(),                                                                       //      ; loop end
	BRC(LINE_CNT(6), DOWN, AL),														//      ; Always              													-> JP17
	
	SRW3(CNT1, REGB7, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),            	    // JP14 ; CH3FLT = LOCALNOISEBUF2(c, r + local_rs)
	CMPS(CH3FLT, CONST_VAL(0)),                          							//      ; cmps(LOCALNOISEBUF2(c, r + local_rs), 0)
	BRC(LINE_CNT(3), DOWN, LES),													//      ; LOCALNOISEBUF2(c, r + local_rs) <= 0              					-> JP17
	SUBS(CH3FLT, CONST_VAL(1), CH3FLT),												// 		; CH3FLT = LOCALNOISEBUF2(c, r + local_rs) - 1
	SRW3(CNT1, REGB7, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    		  		//      ; CH3FLT WRITE ; LOCALNOISEBUF2
	
	SRW3(CNT1, REGB7, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),            	    // JP17 ; CH3FLT = LOCALNOISEBUF2(c, r + local_rs)
	CMPS(CH3FLT, CONST_VAL(0)),                          							//      ; cmps(LOCALNOISEBUF2(c, r + local_rs), 0)
	BRC(LINE_CNT(3), DOWN, EQ),														//      ; LOCALNOISEBUF2(c, r + local_rs) == 0              					-> JP11
	MOV(CONST_VAL(0), REGB6),														// 		; B6 = 0 ; delta
	SRW0(CONST_VAL(30), CONST_VAL(1), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),	// 		; CH0FLT00 WRITE : bAdaptorNoise_SearchMode = 1
	
	CMPS(REGB6, CONST_VAL(0)),                          							// JP11 ; cmps(delta, 0)
#ifdef FingerAreaPenDeltaNoAcc
	#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	BRC(LINE_CNT(121), DOWN, LES),													//      ; delta <= 0              												-> JP18
	#else
	BRC(LINE_CNT(101), DOWN, LES),													//      ; delta <= 0              												-> JP18
	#endif
#else
	#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	BRC(LINE_CNT(100), DOWN, LES),													//      ; delta <= 0              												-> JP18
	#else
	BRC(LINE_CNT(80), DOWN, LES),													//      ; delta <= 0              												-> JP18
	#endif
#endif
	MOV(CONST_VAL(0), REGC5),														// 		; C5 = 0 ; bNoAccFlag
#ifdef FingerAreaPenDeltaNoAcc
	SRW0(CONST_VAL(50), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	// 		; CH0FLT00 READ : cFingerAreaPenDeltaNoAcc
	MOV(CH0FLT00, REGB4),															// 		; B4 = cFingerAreaPenDeltaNoAcc
	CMPS(REGB4, CONST_VAL(0)),                          							// 		; cmps(cFingerAreaPenDeltaNoAcc, 0)
	BRC(LINE_CNT(18), DOWN, EQ),													//      ; cFingerAreaPenDeltaNoAcc == 0              							-> JP19
	SRW0(CONST_VAL(44), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	//		; CH0FLT00 READ : LocalFingerArea.rs
	SUBS(CH0FLT00, REGB4, REGB5),													//		; B5 = LocalFingerArea.rs - cFingerAreaPenDeltaNoAcc
	CMPS(REGB5, REGB7),                                      						//      ; cmps(LocalFingerArea.rs - cFingerAreaPenDeltaNoAcc, r + local_rs)
	BRC(LINE_CNT(14), DOWN, GTS),													//      ; LocalFingerArea.rs - cFingerAreaPenDeltaNoAcc > r + local_rs        	-> JP19
	SRW0(CONST_VAL(45), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	//		; CH0FLT00 READ : LocalFingerArea.re
	ADDS(CH0FLT00, REGB4, REGB5),													//		; B5 = LocalFingerArea.re + cFingerAreaPenDeltaNoAcc
	CMPS(REGB5, REGB7),                                      						//      ; cmps(LocalFingerArea.re + cFingerAreaPenDeltaNoAcc, r + local_rs)
	BRC(LINE_CNT(10), DOWN, LTS),													//      ; LocalFingerArea.re + cFingerAreaPenDeltaNoAcc < r + local_rs        	-> JP19
	SRW0(CONST_VAL(46), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	//		; CH0FLT00 READ : LocalFingerArea.cs
	SUBS(CH0FLT00, REGB4, REGB5),													//		; B5 = LocalFingerArea.cs - cFingerAreaPenDeltaNoAcc
	CMPS(REGB5, CNT1),                                      						//      ; cmps(LocalFingerArea.cs - cFingerAreaPenDeltaNoAcc, c)
	BRC(LINE_CNT(6), DOWN, GTS),													//      ; LocalFingerArea.cs - cFingerAreaPenDeltaNoAcc > c        				-> JP19
	SRW0(CONST_VAL(47), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	//		; CH0FLT00 READ : LocalFingerArea.ce
	ADDS(CH0FLT00, REGB4, REGB5),													//		; B5 = LocalFingerArea.ce + cFingerAreaPenDeltaNoAcc
	CMPS(REGB5, CNT1),                                      						//      ; cmps(LocalFingerArea.ce + cFingerAreaPenDeltaNoAcc, c)
	BRC(LINE_CNT(2), DOWN, LTS),													//      ; LocalFingerArea.ce + cFingerAreaPenDeltaNoAcc < c        				-> JP19
	MOV(CONST_VAL(1), REGC5),														// 		; C5 = 1 ; bNoAccFlag
#endif
	SRW0(CONST_VAL(30), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	// JP19 ; CH0FLT00 READ : bAdaptorNoise_SearchMode
	CMPS(CH0FLT00, CONST_VAL(1)),                          							// 		; cmps(bAdaptorNoise_SearchMode, 1)
	BRC(LINE_CNT(4), DOWN, EQ),														//      ; bAdaptorNoise_SearchMode == 1              							-> JP20
	CMPS(REGC7, CONST_VAL(ACTIVEPEN_TYPE_LOCAL_MS)),                          		// 		; cmps(gAlgoRawDataType, ACTIVEPEN_TYPE_LOCAL_MS)
	BRC(LINE_CNT(2), DOWN, NE),														//      ; gAlgoRawDataType != ACTIVEPEN_TYPE_LOCAL_MS              				-> JP20
	SRW0(CONST_VAL(36), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),	// 		; CH0FLT00 WRITE : tmpSearchNoiseRejectFrm = 0
	
	SRW0(CONST_VAL(36), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	// JP20 ; CH0FLT00 READ : tmpSearchNoiseRejectFrm
	MOV(CH0FLT00, REGC4),															// 		; C4 = tmpSearchNoiseRejectFrm
	CMPS(REGC4, CONST_VAL(0)),                          							// 		; cmps(tmpSearchNoiseRejectFrm, 0)
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	BRC(LINE_CNT(69), DOWN, LES),													//      ; tmpSearchNoiseRejectFrm <= 0              							-> JP21
#else
	BRC(LINE_CNT(59), DOWN, LES),													//      ; tmpSearchNoiseRejectFrm <= 0              							-> JP21
#endif
	SDMA3(REGA6,0,DMA_SIZE3),                                                       //      ; REGA6 : LOCALNOISEBUF1
	SRW0(CONST_VAL(37), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	// 		; CH0FLT00 READ : ucSearchNoiseRejectTH
	CMPS(REGB6, CH0FLT00),                          								// 		; cmps(delta, ucSearchNoiseRejectTH)
	BRC(LINE_CNT(7), DOWN, LES),													//      ; delta <= ucSearchNoiseRejectTH              							-> JP22
	SRW3(CNT1, REGB7, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),            	    // 		; CH3FLT = LOCALNOISEBUF1(c, r + local_rs)
	CMPS(CH3FLT, REGC4),                          									// 		; cmps(LOCALNOISEBUF1(c, r + local_rs), tmpSearchNoiseRejectFrm)
	BRC(LINE_CNT(6), DOWN, GES),													//      ; LOCALNOISEBUF1(c, r + local_rs) >= tmpSearchNoiseRejectFrm         	-> JP23
	ADDS(CH3FLT, CONST_VAL(1), CH3FLT),												// 		; CH3FLT = LOCALNOISEBUF1(c, r + local_rs) + 1
	SRW3(CNT1, REGB7, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    		  		//      ; CH3FLT WRITE ; LOCALNOISEBUF1
	BRC(LINE_CNT(3), DOWN, AL),														//      ; Always              													-> JP23
	MOV(CONST_VAL(0), CH3FLT),														// JP22 ; CH3FLT = 0
	SRW3(CNT1, REGB7, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    		  		// 		; CH3FLT WRITE ; LOCALNOISEBUF1
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	SDMA2(REGB1,0,DMA_SIZE1),                                                       // JP23 ; REGB1 : ulZeroFingerRawMaskInfo
	SRW0(CONST_VAL(29), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), 	// 		; CH0FLT00 READ : zero_finger_rawdata_mask_num
	DIVS(CNT1, CH0FLT00, REGB4),													//		; B4 = c / zero_finger_rawdata_mask_num
	MULS(REGB4, CH0FLT00, REGB5),													//		; B5 = (c / zero_finger_rawdata_mask_num) * zero_finger_rawdata_mask_num
	SUBS(CNT1, REGB5, REGB5),														//		; B5 = c - ((c / zero_finger_rawdata_mask_num) * zero_finger_rawdata_mask_num) ; c % zero_finger_rawdata_mask_num
	SRW2(REGB4, REGB7, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_32BIT),                // 		; CH2FLT = ulZeroFingerRawMaskInfo(c / zero_finger_rawdata_mask_num, r + local_rs)
	SRLS(CH2FLT, REGB5, REGC6),                                              		//      ; C6 = ulZeroFingerRawMaskInfo(c / zero_finger_rawdata_mask_num, r + local_rs) >> (c % zero_finger_rawdata_mask_num)
	AND(REGC6, CONST_VAL(1), REGC6),												//		; C6 = C6 & 0x1
	CMPS(REGC6, CONST_VAL(0)),                          							// 		; cmps(C6, 0)
	BRC(LINE_CNT(43), DOWN, NE),													//      ; C6 != 0              													-> JP24
#endif
	SRW0(CONST_VAL(39), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	// 		; CH0FLT00 READ : ucPen_th1
	CMPS(REGB6, CH0FLT00),                          								// 		; cmps(delta, ucPen_th1)
	BRC(LINE_CNT(40), DOWN, LES),													//      ; delta <= ucPen_th1              										-> JP24
	SRW3(CNT1, REGB7, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),            	    // 		; CH3FLT = LOCALNOISEBUF1(c, r + local_rs)
	CMPS(CH3FLT, REGC4),                          									// 		; cmps(LOCALNOISEBUF1(c, r + local_rs), tmpSearchNoiseRejectFrm)
	BRC(LINE_CNT(37), DOWN, GES),													//      ; LOCALNOISEBUF1(c, r + local_rs) >= tmpSearchNoiseRejectFrm         	-> JP24
	
	SUBS(REGC4, CONST_VAL(1), CH3FLT),												// 		; CH3FLT = tmpSearchNoiseRejectFrm - 1
	SUBS(CNT1, CONST_VAL(2), REGB4),												//		; B4 = c - 2
	_MAX(CONST_VAL(0), REGB4, REGB4),												//		; MAX(0, c - 2)
	ADDS(CNT1, CONST_VAL(2), REGB5),												// 		; B5 = c + 2
	SRW0(CONST_VAL(27), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), 	// 		; CH0FLT00 READ : col_max
	SUBS(CH0FLT00, CONST_VAL(1), REGC6),											// 		; C6 = col_max - 1
	_MIN(REGC6, REGB5, REGB5),														//		; MIN(col_max - 1, c + 2)
	
	SUBS(REGB7, CONST_VAL(1), REGC6),												//		; C6 = (r + local_rs) - 1
	CMPS(REGC6, CONST_VAL(0)),                          							//      ; cmps((r + local_rs) - 1, 0)
	BRC(LINE_CNT(10), DOWN, LTS),													//      ; (r + local_rs) - 1 < 0              									-> JP25
	SLOOP2(REGB4, REGB5, LOOP_LE, LOOP_SOURCE),                                     // 		; loop c - 2 : c + 2
	SRW3(CNT2, REGC6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    			    //      ; CH3FLT WRITE ; LOCALNOISEBUF1
    ELOOP2(),                                                                       //      ; loop end
	
	SUBS(REGB7, CONST_VAL(2), REGC6),												//		; C6 = (r + local_rs) - 2
	CMPS(REGC6, CONST_VAL(0)),                          							//      ; cmps((r + local_rs) - 2, 0)
	BRC(LINE_CNT(4), DOWN, LTS),													//      ; (r + local_rs) - 2 < 0              									-> JP25
	SLOOP2(REGB4, REGB5, LOOP_LE, LOOP_SOURCE),                                     // 		; loop c - 2 : c + 2
	SRW3(CNT2, REGC6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),	    		    //      ; CH3FLT WRITE ; LOCALNOISEBUF1
    ELOOP2(),                                                                       //      ; loop end
	
	MOV(REGB7, REGC6),																// JP25 ; REGC6 = (r + local_rs)
	SLOOP2(REGB4, REGB5, LOOP_LE, LOOP_SOURCE),                                     // 		; loop c - 2 : c + 2
	SRW3(CNT2, REGC6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    			    //      ; CH3FLT WRITE ; LOCALNOISEBUF1
    ELOOP2(),                                                                       //      ; loop end
	
	SRW0(CONST_VAL(28), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), 	// 		; CH0FLT00 READ : row_max
	ADDS(REGB7, CONST_VAL(1), REGC6),												//		; C6 = (r + local_rs) + 1
	CMPS(REGC6, CH0FLT00),                          								//      ; cmps((r + local_rs) + 1, row_max)
	BRC(LINE_CNT(10), DOWN, GES),													//      ; (r + local_rs) + 1 >= row_max  	            						-> JP24
	SLOOP2(REGB4, REGB5, LOOP_LE, LOOP_SOURCE),                                     // 		; loop c - 2 : c + 2
	SRW3(CNT2, REGC6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    		 		//      ; CH3FLT WRITE ; LOCALNOISEBUF1
    ELOOP2(),                                                                       //      ; loop end
	
	ADDS(REGB7, CONST_VAL(2), REGC6),												//		; C6 = (r + local_rs) + 2
	CMPS(REGC6, CH0FLT00),                          								//      ; cmps((r + local_rs) + 2, row_max)
	BRC(LINE_CNT(4), DOWN, GES),													//      ; (r + local_rs) + 1 >= row_max  	            						-> JP24
	SLOOP2(REGB4, REGB5, LOOP_LE, LOOP_SOURCE),                                     // 		; loop c - 2 : c + 2
	SRW3(CNT2, REGC6, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    			    //      ; CH3FLT WRITE ; LOCALNOISEBUF1
    ELOOP2(),                                                                       //      ; loop end
	
	SRW3(CNT1, REGB7, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),            	    // JP24 ; CH3FLT = LOCALNOISEBUF1(c, r + local_rs)
	CMPS(CH3FLT, REGC4),                          									// 		; cmps(LOCALNOISEBUF1(c, r + local_rs), tmpSearchNoiseRejectFrm)
	BRC(LINE_CNT(2), DOWN, GES),													//      ; LOCALNOISEBUF1(c, r + local_rs) >= tmpSearchNoiseRejectFrm         	-> JP21
	MOV(CONST_VAL(0), REGB6),														// 		; REGB6 = 0 ; delta
	
	CMPS(REGC5, CONST_VAL(0)),                          							// JP21 ; cmps(bNoAccFlag, 0)
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	BRC(LINE_CNT(19), DOWN, NE),													//      ; bNoAccFlag != 0         												-> JP18
#else
	BRC(LINE_CNT(9), DOWN, NE),														//      ; bNoAccFlag != 0         												-> JP18
#endif
	SDMA3(REGA3,0,DMA_SIZE3),                                                       //      ; REGA3 : LOCAL_SEARCH_IMAGE
	CMPS(REGC7, CONST_VAL(ACTIVEPEN_TYPE_LOCAL_MS)),                          		// 		; cmps(gAlgoRawDataType, ACTIVEPEN_TYPE_LOCAL_MS)
	BRC(LINE_CNT(4), DOWN, NE),														//      ; gAlgoRawDataType != ACTIVEPEN_TYPE_LOCAL_MS              				-> JP26
	SRW3(CNT1, REGB7, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),            	    // 		; CH3FLT = LOCAL_SEARCH_IMAGE(c, r + local_rs)
	ADDS(REGB6, CH3FLT, REGB6),														//		; delta = delta + LOCAL_SEARCH_IMAGE(c, r + local_rs)
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	BRC(LINE_CNT(13), DOWN, AL),													//      ; Always              													-> JP18
#else
	BRC(LINE_CNT(3), DOWN, AL),														//      ; Always              													-> JP18
#endif
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	SDMA2(REGB1,0,DMA_SIZE1),                                                       // JP26 ; REGB1 : ulZeroFingerRawMaskInfo
	SRW0(CONST_VAL(29), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), 	// 		; CH0FLT00 READ : zero_finger_rawdata_mask_num
	DIVS(CNT1, CH0FLT00, REGB4),													//		; B4 = c / zero_finger_rawdata_mask_num
	MULS(REGB4, CH0FLT00, REGB5),													//		; B5 = (c / zero_finger_rawdata_mask_num) * zero_finger_rawdata_mask_num
	SUBS(CNT1, REGB5, REGB5),														//		; B5 = c - ((c / zero_finger_rawdata_mask_num) * zero_finger_rawdata_mask_num) ; c % zero_finger_rawdata_mask_num
	SRW2(REGB4, REGB7, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_32BIT),                // 		; CH2FLT = ulZeroFingerRawMaskInfo(c / zero_finger_rawdata_mask_num, r + local_rs)
	SRLS(CH2FLT, REGB5, REGC6),                                              		//      ; C6 = ulZeroFingerRawMaskInfo(c / zero_finger_rawdata_mask_num, r + local_rs) >> (c % zero_finger_rawdata_mask_num)
	AND(REGC6, CONST_VAL(1), REGC6),												//		; C6 = C6 & 0x1
	CMPS(REGC6, CONST_VAL(0)),                          							// 		; cmps(C6, 0)
	BRC(LINE_CNT(3), DOWN, NE),														//      ; C6 != 0              													-> JP18
#endif
	SRW3(CNT1, REGB7, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),            	    // 		; CH3FLT = LOCAL_SEARCH_IMAGE2(c, r + local_rs)
	ADDS(REGB6, CH3FLT, REGB6),														//		; delta = delta + LOCAL_SEARCH_IMAGE2(c, r + local_rs)
	
	SDMA3(REGA3,0,DMA_SIZE3),                                                       // JP18 ; REGA3 : LOCAL_SEARCH_IMAGE
	MOV(REGB6, CH3FLT),																// 		; CH3FLT = delta
	SRW3(CNT1, REGB7, FT_1X1, WRITE, PS_REG, DT_SIGNED, DT_16BIT),    			    //      ; CH3FLT WRITE ; LOCAL_SEARCH_IMAGE(c, r + local_rs) = delta
	SDMA2(REGA2,0,DMA_SIZE2),                                                       //      ; REGA2 : LOCALDELTAIMAGE	
	ADDS(CNT1, CONST_VAL(PAD_), REGC6),												//		; C6 = c + PAD_
	ADDS(CNT0, CONST_VAL(PAD_), REGB5),												//		; B5 = r + PAD_
	MOV(REGB6, CH2FLT),																//		; CH2FLT = delta
	SRW2(REGC6, REGB5, FT_1X1, WRITE, PS_REG, DT_SIGNED, DT_16BIT),    			    //      ; CH2FLT WRITE ; delta(c + PAD_, r + PAD_) = delta
	
	SDMA3(REGB3,0,DMA_SIZE3),                                                       //      ; REGB3 : tDelta_local
	CMPS(REGB6, CONST_VAL(0)),                          							// 		; cmps(delta, 0)
	BRC(LINE_CNT(43), DOWN, LES),													//      ; delta <= 0              												-> JP27
	SRW0(CONST_VAL(51), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	// 		; CH0FLT00 READ : sAccumPosSumThd
	CMPS(REGB6, CH0FLT00),                          								// 		; cmps(delta, sAccumPosSumThd)
	BRC(LINE_CNT(8), DOWN, LES),													//      ; delta <= sAccumPosSumThd              								-> JP28
	SRW3(CONST_VAL(5), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 	// 		; CH3FLT READ : iPosCnt
	ADDS(CH3FLT, CONST_VAL(1), REGB4),												//		; B4 = iPosCnt + 1
	SRW3(CONST_VAL(5), REGB4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			// 		; CH3FLT WRITE : iPosCnt = iPosCnt + 1
	SUBS(REGB6, CH0FLT00, REGB4),													//		; B4 = delta - sAccumPosSumThd
	SRW3(CONST_VAL(6), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 	// 		; CH3FLT READ : iPosSum
	ADDS(CH3FLT, REGB4, REGB4),														//		; B4 = iPosSum + (delta - sAccumPosSumThd)
	SRW3(CONST_VAL(6), REGB4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			// 		; CH3FLT WRITE : iPosSum = iPosSum + (delta - sAccumPosSumThd)
	
	SRW0(CONST_VAL(12), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), 	// JP28 ; CH0FLT00 READ : delta_th
	CMPS(REGB6, CH0FLT00),                          								// 		; cmps(delta, delta_th)
	BRC(LINE_CNT(20), DOWN, LES),													//      ; delta <= delta_th              										-> JP29
	SRW3(CONST_VAL(2), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 		// 		; CH3FLT READ : tValidRect.cs
	CMPS(CH3FLT, CNT1),                          									// 		; cmps(tValidRect.cs, c)
	BRC(LINE_CNT(2), DOWN, LES),													//      ; tValidRect.cs <= c              										-> JP30
	SRW3(CONST_VAL(2), CNT1, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),			// 		; CH3FLT WRITE : tValidRect.cs = c	
	SRW3(CONST_VAL(3), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 		// JP30 ; CH3FLT READ : tValidRect.ce
	CMPS(CH3FLT, CNT1),                          									// 		; cmps(tValidRect.ce, c)
	BRC(LINE_CNT(2), DOWN, GES),													//      ; tValidRect.ce >= c              										-> JP31
	SRW3(CONST_VAL(3), CNT1, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),			// 		; CH3FLT WRITE : tValidRect.ce = c	
	SRW3(CONST_VAL(0), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 		// JP31 ; CH3FLT READ : tValidRect.rs
	CMPS(CH3FLT, CNT0),                          									// 		; cmps(tValidRect.rs, r)
	BRC(LINE_CNT(2), DOWN, LES),													//      ; tValidRect.rs <= r              										-> JP32
	SRW3(CONST_VAL(0), CNT0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),			// 		; CH3FLT WRITE : tValidRect.rs = r	
	SRW3(CONST_VAL(1), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 		// JP32 ; CH3FLT READ : tValidRect.re
	CMPS(CH3FLT, CNT0),                          									// 		; cmps(tValidRect.re, r)
	BRC(LINE_CNT(2), DOWN, GES),													//      ; tValidRect.re >= r              										-> JP33
	SRW3(CONST_VAL(1), CNT0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),			// 		; CH3FLT WRITE : tValidRect.re = r	
	SRW3(CONST_VAL(1), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT), 	// JP33 ; CH3FLT READ : iGroupedCellCnt
	ADDS(CH3FLT, CONST_VAL(1), REGB4),												//		; B4 = iGroupedCellCnt + 1
	SRW3(CONST_VAL(1), REGB4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_32BIT),		// 		; CH3FLT WRITE : iGroupedCellCnt = iGroupedCellCnt + 1
	
	SRW3(CONST_VAL(2), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 	// JP29 ; CH3FLT READ : iMaxStrength
	CMPS(CH3FLT, REGB6),                          									// 		; cmps(iMaxStrength, delta)
	BRC(LINE_CNT(22), DOWN, GES),													//      ; iMaxStrength >= delta              									-> JP34
	SRW3(CONST_VAL(2), REGB6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			// 		; CH3FLT WRITE : iMaxStrength = delta
	SRW0(CONST_VAL(11), REGB6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_16BIT),			// 		; CH0FLT00 WRITE : pen_touch_data = delta	
	SRW3(CONST_VAL(41), CNT0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),			// 		; CH3FLT WRITE : tMaxCellPos.r = r
	SRW0(CONST_VAL(21), CNT0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),			// 		; CH0FLT00 WRITE : pen_pos.r = r
	SRW3(CONST_VAL(40), CNT1, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),			// 		; CH3FLT WRITE : tMaxCellPos.c = c
	SRW0(CONST_VAL(20), CNT1, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),			// 		; CH0FLT00 WRITE : pen_pos.c = c
	BRC(LINE_CNT(15), DOWN, AL),													//      ; Always              													-> JP34
	
	SRW0(CONST_VAL(52), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	// JP27 ; CH0FLT00 READ : sAccumNegSumThd
	CMPS(REGB6, CH0FLT00),                          								// 		; cmps(delta, sAccumNegSumThd)
	BRC(LINE_CNT(8), DOWN, GES),													//      ; delta >= sAccumNegSumThd              								-> JP35
	SRW3(CONST_VAL(7), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 	// 		; CH3FLT READ : iNegCnt
	ADDS(CH3FLT, CONST_VAL(1), REGB4),												//		; B4 = iNegCnt + 1
	SRW3(CONST_VAL(7), REGB4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			// 		; CH3FLT WRITE : iNegCnt = iNegCnt + 1
	SUBS(REGB6, CH0FLT00, REGB4),													//		; B4 = delta - sAccumNegSumThd
	SRW3(CONST_VAL(8), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 	// 		; CH3FLT READ : iNegSum
	ADDS(CH3FLT, REGB4, REGB4),														//		; B4 = iNegSum + (delta - sAccumNegSumThd)
	SRW3(CONST_VAL(8), REGB4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			// 		; CH3FLT WRITE : iNegSum = iNegSum + (delta - sAccumNegSumThd)
	
	SRW3(CONST_VAL(9), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 	// JP35 ; CH3FLT READ : iMinStrength
	CMPS(CH3FLT, REGB6),                          									// 		; cmps(iMinStrength, delta)
	BRC(LINE_CNT(2), DOWN, LES),													//      ; iMinStrength <= delta              									-> JP34
	SRW3(CONST_VAL(9), REGB6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			// 		; CH3FLT WRITE : iMinStrength = delta
#ifdef TILT_ON
	SRW0(CONST_VAL(15), CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT), 	// JP34 ; CH0FLT00 READ : g_RetVal
	CMPS(CH0FLT00, CONST_VAL(PARTIAL_PEN_COORD2)),                          		// 		; cmps(g_RetVal, PARTIAL_PEN_COORD2)
	BRC(LINE_CNT(11), DOWN, NE),													//      ; g_RetVal != PARTIAL_PEN_COORD2              							-> JP36	
	CMPS(REGC7, CONST_VAL(ACTIVEPEN_TYPE_LOCAL_WACOM)),                          	// 		; cmps(gAlgoRawDataType, ACTIVEPEN_TYPE_LOCAL_WACOM)
	BRC(LINE_CNT(9), DOWN, NE),														//      ; gAlgoRawDataType != ACTIVEPEN_TYPE_LOCAL_WACOM              			-> JP36	
	SDMA3(REGA4,0,DMA_SIZE3),                                                       //      ; REGA4 : LOCALRINGRAWIMAGE
	SRW1(CNT1, CNT0, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),                  //      ; CH1FLT = raw(c, r)
	MOV(CH1FLT, CH3FLT),															//		; CH3FLT = CH1FLT
	SRW3(CNT1, CNT0, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_16BIT),    			    //      ; CH3FLT WRITE ; LOCALRINGRAWIMAGE(c, r) = raw(c, r)
	SDMA3(REGA5,0,DMA_SIZE2),                                                       //      ; REGA5 : RINGDELTAIMAGE
	SRW2(REGC6, REGB5, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),    			    //      ; CH2FLT = delta(c + PAD_, r + PAD_)	
	MOV(CH2FLT, CH3FLT),															//		; CH3FLT = CH2FLT
	SRW3(REGC6, REGB5, FT_1X1, WRITE, PS_REG, DT_SIGNED, DT_16BIT),    			    //      ; CH3FLT WRITE ; RINGDELTAIMAGE(c + PAD_, r + PAD_) = delta(c + PAD_, r + PAD_)
#endif
	SDMA3(REGB0,0,DMA_SIZE2),                                                       // JP36 ; REGB0 : LOCALLABELIMAGE
	MOV(CONST_VAL(0), CH3FLT),														//		; CH3FLT = 0
	SRW3(REGC6, REGB5, FT_1X1, WRITE, PS_REG, DT_UNSIGNED, DT_8BIT),    			//      ; CH3FLT WRITE ; LOCALLABELIMAGE(c + PAD_, r + PAD_) = 0
	
	ELOOP1(),                                                                       // JP02 ;
    ELOOP0(),																		// JP01 ;
	
    END()                                                                           // JP00 ; end
};
#endif
/********************************************************************************
  @brief    Pen noise reduction
  */
#ifdef SRAM_OPCODE
int opcode_pennoise[] = 
#else
int opcode_pennoise[] = 
#endif
{
	SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : delta img
    SDMA1(REGA1, 0, DMA_SIZE2),                                                     //      ; A1 : delta info
    SDMA2(REGA2, 0, DMA_SIZE2),                                                     //      ; A2 : pen info
	SDMA3(REGA1, 0, DMA_SIZE2),                                                     //      ; A3 : delta info
	
	CMP(REGB0, CONST_VAL(1)),														//      ; cmp(bPenNoiseReductionOff, 1)								
#ifdef PenFingerSameLineNoiseException
#ifdef TILT_ON
	BRC(LINE_CNT(149), DOWN, EQ),                                                   //		; bPenNoiseReductionOff == 1 	                    -> JP00
#else
    BRC(LINE_CNT(137), DOWN, EQ),                                                   //                              	 						-> JP00
#endif
#else
#ifdef TILT_ON
	BRC(LINE_CNT(107), DOWN, EQ),                                                   //                              	 						-> JP00
#else
    BRC(LINE_CNT(100), DOWN, EQ),                                                    //                              	 						-> JP00
#endif
	
#endif	
	CMP(REGA3, CONST_VAL(1)),                                                       //      ; cmp(thisInfo->bTouchExpect_local, 1)
#ifdef PenFingerSameLineNoiseException
#ifdef TILT_ON
	BRC(LINE_CNT(147), DOWN, NE),                                                   //      ; thisInfo->bTouchExpect_local != 1                           	 						-> JP00
#else
    BRC(LINE_CNT(135), DOWN, NE),                                                   //      ; thisInfo->bTouchExpect_local != 1                           	 						-> JP00
#endif
#else
#ifdef TILT_ON
	BRC(LINE_CNT(105), DOWN, NE),                                                   //      ; thisInfo->bTouchExpect_local != 1                           	 						-> JP00
#else
    BRC(LINE_CNT(98), DOWN, NE),                                                    //      ; thisInfo->bTouchExpect_local != 1                           	 						-> JP00
#endif
#endif

	SRW1(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	//      ; CH1FLT READ  : thisInfo->tDelta_local.tValidRect.cs
	MOV(CH1FLT, REGB3),																//		; REGB3 = thisInfo->tDelta_local.tValidRect.cs : start_slop
	MOV(REGC3, REGB4),																//		; REGB4 = -1 : end_slop
	
#ifdef TILT_ON
	CMP(REGA4, CONST_VAL(PARTIAL_PEN_COORD2)),                                      //      ; cmp(g_RetVal, PARTIAL_PEN_COORD2)
    BRC(LINE_CNT(6), DOWN, NE),                                                     //      ; g_RetVal != LOCAL_PEN_COORD2           	              								-> JP01
	CMP(REGA5, CONST_VAL(LOCAL_RING_MODE)),                                    		//      ; cmp(mode, LOCAL_RING_MODE)
    BRC(LINE_CNT(4), DOWN, NE),                                                     //      ; mode != LOCAL_RING_MODE                         											-> JP01
	MOV(REGC4, REGB0),                                                     			//      ; REGB0 = Ring_PreMaxR : MaxR
	MOV(REGC5, REGB1),                                                     			//      ; REGB1 = Ring_PreMaxC : MaxC
	BRC(LINE_CNT(3), DOWN, AL),                                                     //      ; Always			                         											-> JP02
#endif
	MOV(REGC6, REGB0),                                                     			// JP01 ; REGB0 = PreMaxR : MaxR
	MOV(REGC7, REGB1),                                                     			//      ; REGB1 = PreMaxC : MaxC
	
	CMPS(REGB0, REGC3),                                    		   					// JP02 ; cmp(REGB0, -1) : MaxR
    BRC(LINE_CNT(51), DOWN, EQ),                                                    //      ; MaxR == -1                         													-> JP03
	
	SLOOP0(0, 0, LOOP_LE, LOOP_REGC0),                                              //      ; col loop
	ADDS(CNT0, CONST_VAL(PAD_), REGB6),                                                //      ; REGB6 = CNT0 + 1 : ucPadSize
	MOV(CONST_VAL(0), REGB2),														//		; REGB2 = 0	: sum_col
	
    SLOOP1(0, 0, LOOP_LE, LOOP_REGC1),                                              //      ; row loop
	ADDS(CNT1, CONST_VAL(PAD_), REGB7),                                                //      ; REGB7 = CNT1 + 1 : ucPadSize
	SRW0(REGB6, REGB7, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),                  //      ; CH0FLT00 = delta(REGB6, REGB7)
	ADDS(REGB2, CH0FLT00, REGB2),                                              		//      ; REGB2 = REGB2 + delta(REGB6, REGB7) : sum_col
	ELOOP1(),																		//
	
	CMPS(REGB3, REGC3),                                    		   					// 		; cmp(REGB3, -1) : start_slop
	BRC(LINE_CNT(35), DOWN, EQ),                                                    //      ; start_slop == -1           	              											-> JP04
	CMPS(REGB2, REGC2),                                    		   					// 		; cmp(REGB2, thisModeConf->Label.usLocalSeedBase) : sum_col
	BRC(LINE_CNT(4), DOWN, LTS),                                                    //      ; sum_col < thisModeConf->Label.usLocalSeedBase											-> JP05
	SRW1(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	//      ; CH1FLT READ  : thisInfo->tDelta_local.tValidRect.ce
	CMPS(CNT0, CH1FLT),                                    		   					// 		; cmp(CNT0, thisInfo->tDelta_local.tValidRect.ce) : c
	BRC(LINE_CNT(30), DOWN, NE),                                                    //      ; c != thisInfo->tDelta_local.tValidRect.ce 											-> JP04
	MOV(CNT0, REGB4),																// JP05 ; REGB4 = c : end_slop
	
	CMPS(REGB3, REGB1),                                    		   					// 		; cmp(REGB3, REGB1) : start_slop, MaxC
	BRC(LINE_CNT(25), DOWN, GTS),                                                   //      ; start_slop > MaxC																		-> JP06
	CMPS(REGB1, REGB4),                                    		   					// 		; cmp(REGB1, REGB4) : MaxC, end_slop
	BRC(LINE_CNT(23), DOWN, GTS),                                                   //      ; MaxC > end_slop																		-> JP06
	SRW1(CONST_VAL(2), REGB3, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),        	//      ; CH1FLT WRITE : thisInfo->tDelta_local.tValidRect.cs = REGB3 : start_slop
	SRW3(CONST_VAL(3), REGB4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),         	//      ; CH3FLT WRITE : thisInfo->tDelta_local.tValidRect.ce = REGB4 : end_slop
	
	SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//      ; CH2FLT READ  : thisInfo->tPenInfo.ucCurrentColumnStart
	CMPS(CH2FLT, REGB1),                                    		   				// 		; cmp(thisInfo->tPenInfo.ucCurrentColumnStart, REGB1) : MaxC
	BRC(LINE_CNT(4), DOWN, GTS),                                                    //      ; thisInfo->tPenInfo.ucCurrentColumnStart > MaxC										-> JP07
	SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//      ; CH2FLT READ  : thisInfo->tPenInfo.ucCurrentColumnEnd
	CMPS(REGB1, CH2FLT),                                    		   				// 		; cmp(REGB1, thisInfo->tPenInfo.ucCurrentColumnEnd) : MaxC
	BRC(LINE_CNT(14), DOWN, LES),                                                   //      ; MaxC <= thisInfo->tPenInfo.ucCurrentColumnEnd 										-> JP08
	
	CMPS(REGB3, CONST_VAL(2)),                                    		   			// JP07 ; cmp(REGB3, 2) : start_slop
	BRC(LINE_CNT(3), DOWN, GES),                                                    //      ; start_slop >= 2		 																-> JP09
	SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnStart = 0
	BRC(LINE_CNT(3), DOWN, AL),                                                     //      ; Always																				-> JP10
	SUBS(REGB3, CONST_VAL(2), REGB5),												// JP09 ; REGB5 = REGB3 - 2 : start_slop
	SRW2(CONST_VAL(2), REGB5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  		//  	; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnStart = start_slop - 2	
	SUBS(REGA6, CONST_VAL(2), REGB5),												// JP10 ; REGB5 = REGA6 - 2 : thisInfo->ucScreenCol - 1
	CMPS(REGB4, REGB5),                                    		   					// 		; cmp(REGB4, REGB5) : end_slop
	BRC(LINE_CNT(3), DOWN, LES),                                                    //      ; end_slop <= thisInfo->ucScreenCol - 3								 					-> JP11
	SRW2(CONST_VAL(3), REGA6, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  		//      ; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnEnd = thisInfo->ucScreenCol - 1
	BRC(LINE_CNT(3), DOWN, AL),                                                     //      ; Always																				-> JP08
	ADDS(REGB4, CONST_VAL(2), REGB5),												// JP11 ; REGB5 = REGB4 + 2 : end_slop
	SRW2(CONST_VAL(3), REGB5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  		//      ; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnEnd = end_slop + 2
	BRC(LINE_CNT(9), DOWN, AL),                                                     // JP08 ; Always																				-> JP03 //break
	MOV(REGC3, REGB3),																// JP06 ; REGB3 = -1 : start_slop
	BRC(LINE_CNT(6), DOWN, AL),                                                     // 		; Always																				-> JP12
	CMPS(REGB3, REGC3),                                    		   					// JP04 ; cmp(REGB3, -1) : start_slop
	BRC(LINE_CNT(4), DOWN, NE),                                                     //      ; start_slop != -1           	              											-> JP12
	CMPS(REGB2, REGC2),                                    		   					// 		; cmp(REGB2, thisModeConf->Label.usLocalSeedBase) : sum_col
	BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; sum_col <= thisModeConf->Label.usLocalSeedBase										-> JP12
	MOV(CNT0, REGB3),																// 		; REGB3 = c : start_slop
	ELOOP0(),																		// JP12 ;	
	
	SRW1(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	// JP03 ; CH1FLT READ  : thisInfo->tDelta_local.tValidRect.cs
	SRW3(CONST_VAL(36), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	//      ; CH3FLT READ  : thisInfo->tDelta_local.tMaxCellPos.c
	CMPS(CH1FLT, CH3FLT),                                    		   				// 		; cmp(thisInfo->tDelta_local.tValidRect.cs, thisInfo->tDelta_local.tMaxCellPos.c)
	BRC(LINE_CNT(37), DOWN, GTS),                                                   //      ; thisInfo->tDelta_local.tValidRect.cs > thisInfo->tDelta_local.tMaxCellPos.c			-> JP13
	MOV(CH1FLT, REGB0),                                                     		//      ; REGB0 = thisInfo->tDelta_local.tValidRect.cs
	MOV(CH3FLT, REGB2),                                                     		//      ; REGB2 = thisInfo->tDelta_local.tMaxCellPos.c
	SRW1(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	// 		; CH1FLT READ  : thisInfo->tDelta_local.tValidRect.ce
	CMPS(CH3FLT, CH1FLT),                                    		   				// 		; cmp(thisInfo->tDelta_local.tMaxCellPos.c, thisInfo->tDelta_local.tValidRect.ce)
	BRC(LINE_CNT(32), DOWN, GTS),                                                   //      ; thisInfo->tDelta_local.tMaxCellPos.c > thisInfo->tDelta_local.tValidRect.ce			-> JP13
	SRW3(CONST_VAL(37), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	//      ; CH3FLT READ  : thisInfo->tDelta_local.tMaxCellPos.r
	MOV(CH1FLT, REGB1),                                                     		//      ; REGB1 = thisInfo->tDelta_local.tValidRect.ce
	MOV(CH3FLT, REGB3),                                                     		//      ; REGB3 = thisInfo->tDelta_local.tMaxCellPos.r	
	MOV(REGB2, REGB4),                                                     			//      ; REGB4 = thisInfo->tDelta_local.tMaxCellPos.c : cal_max_pos.c
	SUBS(REGB4, REGB0, REGB5),														// 		; REGB5 = REGB4 - thisInfo->tDelta_local.tValidRect.cs : left_size
	SUBS(REGB1, REGB4, REGB6),														// 		; REGB6 = thisInfo->tDelta_local.tValidRect.ce - REGB4 : right_size
	
	SUBS(REGB6, REGB5, REGB7),														// 		; REGB7 = right_size - left_size
	CMPS(REGB7, CONST_VAL(1)),                                    		   			// 		; cmp(right_size - left_size, 1)
	BRC(LINE_CNT(11), DOWN, LES),                                                   //      ; right_size - left_size <= 1															-> JP14
	ADDS(REGB4, REGB5, REGB7),														// 		; REGB7 = cal_max_pos.c + left_size
	ADDS(REGB7, CONST_VAL(1), REGB7),												// 		; REGB7 = REGB7 + 1
	SRW1(CONST_VAL(3), REGB7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),  			//      ; CH1FLT WRITE : thisInfo->tDelta_local.tValidRect.ce = cal_max_pos.c + left_size + 1
	ADDS(REGB7, CONST_VAL(2), REGB7),												// 		; REGB7 = REGB7 + 2
	CMPS(REGB7, REGA6),                                    		   					// 		; cmp(thisInfo->tDelta_local.tValidRect.ce + 2, thisInfo->ucScreenCol - 1)
	BRC(LINE_CNT(3), DOWN, LES),                                                    //      ; thisInfo->tDelta_local.tValidRect.ce + 2 <= thisInfo->ucScreenCol - 1					-> JP15	
	SRW2(CONST_VAL(3), REGA6, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  		//      ; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnEnd = thisInfo->ucScreenCol - 1
	BRC(LINE_CNT(15), DOWN, AL),                                                    //      ; Always																				-> JP13
	SRW2(CONST_VAL(3), REGB7, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  		// JP15 ; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnEnd = REGB7
	BRC(LINE_CNT(13), DOWN, AL),                                                    //      ; Always																				-> JP13
	
	SUBS(REGB5, REGB6, REGB7),														// JP14 ; REGB7 = left_size - right_size
	CMPS(REGB7, CONST_VAL(1)),                                    		   			// 		; cmp(left_size - right_size, 1)
	BRC(LINE_CNT(10), DOWN, LES),                                                   //      ; left_size - right_size <= 1															-> JP13
	SUBS(REGB4, REGB6, REGB7),														// 		; REGB7 = cal_max_pos.c - right_size
	SUBS(REGB7, CONST_VAL(1), REGB7),												// 		; REGB7 = REGB7 - 1
	SRW1(CONST_VAL(2), REGB7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),  			//      ; CH1FLT WRITE : thisInfo->tDelta_local.tValidRect.cs = cal_max_pos.c - left_size - 1
	SUBS(REGB7, CONST_VAL(2), REGB7),												// 		; REGB7 = REGB7 - 2
	CMPS(REGB7, CONST_VAL(0)),                                    		   			// 		; cmp(thisInfo->tDelta_local.tValidRect.cs - 2, 0)
	BRC(LINE_CNT(3), DOWN, GES),                                                    //      ; thisInfo->tDelta_local.tValidRect.cs - 2 >= 0											-> JP16
	SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnStart = 0
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always																				-> JP13
	SRW2(CONST_VAL(2), REGB7, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  		// JP16  ; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnStart = REGB7
	
#ifdef PenFingerSameLineNoiseException
	CMP(REGA5, CONST_VAL(LOCAL_MODE)),                                    		    // JP13 ; cmp(mode, LOCAL_MODE)
	//BRC(LINE_CNT(2), DOWN, AL),		
#ifdef TILT_ON
	BRC(LINE_CNT(41), DOWN, NE),                                                    //      ; mode != LOCAL_MODE                         											-> JP00
#else    
	BRC(LINE_CNT(36), DOWN, NE),                                                    //      ; mode != LOCAL_MODE                         											-> JP00
#endif

#ifdef TILT_ON
//	CMP(REGA4, CONST_VAL(PARTIAL_PEN_COORD2)),                                      //      ; cmp(g_RetVal, PARTIAL_PEN_COORD2)
//  BRC(LINE_CNT(4), DOWN, NE),                                                   //      ; g_RetVal != PARTIAL_PEN_COORD2      					-> JP17
	CMP(REGA5, CONST_VAL(LOCAL_RING_MODE)),                                    		//      ; cmp(mode, LOCAL_RING_MODE)
    BRC(LINE_CNT(4), DOWN, NE),                                                     //      ; mode != LOCAL_RING_MODE  								-> JP17
	MOV(CONST_VAL(7), REGB0),                                                     	//      ; REGB0 = 7 : rs
	MOV(CONST_VAL(6), REGB1),                                                     	//      ; REGB1 = 6 : re
	BRC(LINE_CNT(3), DOWN, AL),                                                     //      ; Always																				-> JP18
#endif
//#ifdef	COVER_GLASS_USE
//#if (CUSTOMER == NEC || CUSTOMER == MS || CUSTOMER == TOSHIBA_PEN || CUSTOMER == LENOVO_PEN)
//	MOV(CONST_VAL(3), REGB0),                                                     	// JP17 ; REGB0 = 4 : rs
//#else
//	MOV(CONST_VAL(4), REGB0),                                                     	// JP17 ; REGB0 = 3 : rs
//#endif
//#else
	MOV(REGA7, REGB0),                                                     			// JP17 ; REGB0 = REGA7 : rs
//#endif
	MOV(CONST_VAL(5), REGB1),                                                     	//      ; REGB1 = 5 : re
	
	SRW1(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	// JP18 ; CH1FLT READ  : thisInfo->tDelta_local.tValidRect.cs
	SRW3(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	// 		; CH3FLT READ  : thisInfo->tDelta_local.tValidRect.ce
	SUBS(CH3FLT, CH1FLT, REGB2),													// 		; REGB2 = thisInfo->tDelta_local.tValidRect.ce - thisInfo->tDelta_local.tValidRect.cs
	CMPS(REGB2, REGB0),                                      						//      ; cmp(thisInfo->tDelta_local.tValidRect.ce - thisInfo->tDelta_local.tValidRect.cs, rs)
	BRC(LINE_CNT(6), DOWN, GTS),                                                    //      ; thisInfo->tDelta_local.tValidRect.ce - thisInfo->tDelta_local.tValidRect.cs > rs  	-> JP19
	SRW1(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	// 		; CH1FLT READ  : thisInfo->tDelta_local.tValidRect.rs
	SRW3(CONST_VAL(1), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	// 		; CH3FLT READ  : thisInfo->tDelta_local.tValidRect.re
	SUBS(CH3FLT, CH1FLT, REGB2),													// 		; REGB2 = thisInfo->tDelta_local.tValidRect.re - thisInfo->tDelta_local.tValidRect.rs
	CMPS(REGB2, REGB0),                                       						//      ; cmp(thisInfo->tDelta_local.tValidRect.re - thisInfo->tDelta_local.tValidRect.rs, rs)
	BRC(LINE_CNT(24), DOWN, LES),                                                   //      ; thisInfo->tDelta_local.tValidRect.ce - thisInfo->tDelta_local.tValidRect.cs <= rs     -> JP00
	SRW1(CONST_VAL(37), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	// JP19 ; CH1FLT READ  : thisInfo->tDelta_local.tMaxCellPos.r
	SRW3(CONST_VAL(36), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	//      ; CH3FLT READ  : thisInfo->tDelta_local.tMaxCellPos.c
	MOV(CH1FLT, REGB3),                                                   		  	//      ; REGB3 = thisInfo->tDelta_local.tMaxCellPos.r
	MOV(CH3FLT, REGB4),                                                   		  	//      ; REGB4 = thisInfo->tDelta_local.tMaxCellPos.c
	SRW1(CONST_VAL(0), REGB3, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),        	//      ; CH1FLT WRITE : thisInfo->tDelta_local.tValidRect.rs = thisInfo->tDelta_local.tMaxCellPos.r
	SRW3(CONST_VAL(1), REGB3, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),         	//      ; CH3FLT WRITE : thisInfo->tDelta_local.tValidRect.re = thisInfo->tDelta_local.tMaxCellPos.r
	SRW1(CONST_VAL(2), REGB4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),        	//      ; CH1FLT WRITE : thisInfo->tDelta_local.tValidRect.cs = thisInfo->tDelta_local.tMaxCellPos.c
	SRW3(CONST_VAL(3), REGB4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),         	//      ; CH3FLT WRITE : thisInfo->tDelta_local.tValidRect.ce = thisInfo->tDelta_local.tMaxCellPos.c
	
	SRW1(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	// 		; CH1FLT READ  : thisInfo->tDelta_local.tValidRect.cs
	CMPS(CH1FLT, CONST_VAL(0)),                                       				//      ; cmp(thisInfo->tDelta_local.tValidRect.cs, 0)
	BRC(LINE_CNT(4), DOWN, EQ),                                                     //      ; thisInfo->tDelta_local.tValidRect.cs == 0           	    							-> JP20
	SUBS(CH1FLT, CONST_VAL(1), REGB2),												// 		; REGB2 = thisInfo->tDelta_local.tValidRect.cs - 1
	SRW2(CONST_VAL(2), REGB2, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  		//      ; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnStart = thisInfo->tDelta_local.tValidRect.cs - 1
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always																				-> JP21
	SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  // JP20 ; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnStart = 0
	
	SRW1(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	// JP21 ; CH1FLT READ  : thisInfo->tDelta_local.tValidRect.ce
	SUBS(REGA6, CONST_VAL(0), REGB2),												// 		; REGB2 = thisInfo->ucScreenCol - 1
	CMPS(CH1FLT, REGB2),                                       						//      ; cmp(thisInfo->tDelta_local.tValidRect.ce, thisInfo->ucScreenCol - 1)
	BRC(LINE_CNT(4), DOWN, EQ),                                                     //      ; thisInfo->tDelta_local.tValidRect.ce == thisInfo->ucScreenCol - 1           	    	-> JP22
	ADDS(CH1FLT, CONST_VAL(1), REGB2),												// 		; REGB2 = thisInfo->tDelta_local.tValidRect.ce + 1
	SRW2(CONST_VAL(3), REGB2, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),  		//      ; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnEnd = thisInfo->tDelta_local.tValidRect.ce + 2
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always																				-> JP00
	SRW2(CONST_VAL(3), REGA6, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT), 		// JP22 ; CH2FLT WRITE : thisInfo->tPenInfo.ucCurrentColumnEnd = thisInfo->ucScreenCol - 1	
#endif
	
	END()                                                                           // JP00 ; end
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
	CMPS(CONST_VAL(0), REGC2),														//		; cmps(thisInfo->bTouchExpect_local,0)
	BRC(LINE_CNT(56), DOWN, EQ),													//		; thisInfo->bTouchExpect_local == 0	-> END
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
  
#if (PAD_ == 0) 
	CMP(REGB7, CONST_VAL(0)),                                                    	//      ; cmp(REGB7, 0)
	BRC(LINE_CNT(54), DOWN, EQ),                                                    //      ; if(REGB7 == 0) -> JP00
	CMP(REGB7, CONST_VAL(COL_MAX-1)),                                               //      ; cmp(REGB7, COL_MAX-1)
	BRC(LINE_CNT(52), DOWN, EQ),                                                    //      ; if(REGB7 != COL_MAX-1) -> JP00
#endif

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
    BRC(LINE_CNT(187), DOWN, LE),                                                   //      ; ulStrength <= 0                            -> JP00	// line connect use o
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
// 	BRC(LINE_CNT(148), DOWN, AL),
	SDMA3(REGC3, 0, DMA_SIZE2),                                                     //      ;
	CMP(REGC2, CONST_VAL(LOCAL_MODE)),                                              //      ; cmp(mode, LOCAL_MODE)	: REGC2 = mode
	BRC(LINE_CNT(48), DOWN, NE),													//      ; mode != LOCAL_MODE                      	-> JP28
//	SRW2(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH2FLT READ  : tEdgePenSetVal.left_th
	SRW2(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT),    //      ; CH2FLT READ  : tEdgePenSetVal.left_th
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
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT),    // JP29 ; CH2FLT READ  : tEdgePenSetVal.right_th
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
//	SRW2(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP30 ; CH2FLT READ  : tEdgePenSetVal.top_th
	SRW2(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT),    // JP30 ; CH2FLT READ  : tEdgePenSetVal.top_th
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
	BRC(LINE_CNT(110), DOWN, AL),                                                   //      ; Always        							-> JP32
	SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT),  // JP31 ; CH2FLT READ  : tEdgePenSetVal.bottom_th
	SUBS(REGC1, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalYRes - tEdgePenSetVal.bottom_th
	CMPS(REGC7, REGB0),                                              				//      ; cmps(y, REGB0)
	BRC(LINE_CNT(106), DOWN, LES),													//      ; y <= REGB0              					-> JP32
	SRW3(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  	//      ; CH3FLT READ  : tEdgePenSetVal.bottom_mul
	SRW2(CONST_VAL(7), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  	//      ; CH2FLT READ  : tEdgePenSetVal.bottom_SR
	SUBS(REGC7, REGB0, REGB2),                                               		//      ; REGB2 = y - REGB0
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.bottom_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.bottom_SR
	ADDS(REGB0, REGB2, REGC7),                                               		//      ; y = REGB0 + REGB2
    SRW0(CONST_VAL(17), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.y = y
	BRC(LINE_CNT(98), DOWN, AL),                                                   	//      ; Always        							-> JP32
	CMP(REGC2, CONST_VAL(LOCAL_HOVER_MODE)),                                        // JP28 ; cmp(mode, LOCAL_HOVER_MODE)
	BRC(LINE_CNT(48), DOWN, NE),													//      ; mode != LOCAL_HOVER_MODE               	-> JP36
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
	SRW2(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // JP33 ; CH2FLT READ  : tEdgePenSetVal.right_hover_th
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
	BRC(LINE_CNT(61), DOWN, AL),                                                   	//      ; Always        							-> JP32
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // JP35 ; CH2FLT READ  : tEdgePenSetVal.bottom_hover_th
	SUBS(REGC1, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalYRes - tEdgePenSetVal.bottom_hover_th
	CMPS(REGC7, REGB0),                                              				//      ; cmps(y, REGB0)
	BRC(LINE_CNT(57), DOWN, LES),													//      ; y <= REGB0              					-> JP32
	SRW3(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	//      ; CH3FLT READ  : tEdgePenSetVal.bottom_hover_mul
	SRW2(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	//      ; CH2FLT READ  : tEdgePenSetVal.bottom_hover_SR
	SUBS(REGC7, REGB0, REGB2),                                               		//      ; REGB2 = y - REGB0
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.bottom_hover_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.bottom_hover_SR
	ADDS(REGB0, REGB2, REGC7),                                               		//      ; y = REGB0 + REGB2
    SRW0(CONST_VAL(17), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.y = y
	BRC(LINE_CNT(49), DOWN, AL),                                                   	//      ; Always        							-> JP32
	CMP(REGC2, CONST_VAL(LOCAL_RING_MODE)),                                         // JP36 ; cmp(mode, LOCAL_RING_MODE)
	BRC(LINE_CNT(47), DOWN, NE),													// 		; mode != LOCAL_RING_MODE               	-> JP32
	SRW2(CONST_VAL(20), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH2FLT READ  : tEdgePenSetVal.left_ring_th
	CMPS(REGC6, CH2FLT),                                              				//      ; cmps(x, tEdgePenSetVal.left_ring_th)
	BRC(LINE_CNT(10), DOWN, GES),													//      ; x >= tEdgePenSetVal.left_ring_th        	-> JP37
	SRW3(CONST_VAL(42), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH3FLT READ  : tEdgePenSetVal.left_ring_mul
	MOV(CH2FLT, REGB0),                                                           	//      ; REGB0 = EdgePenSetVal.left_ring_th
	SRW2(CONST_VAL(43), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH2FLT READ  : tEdgePenSetVal.left_ring_SR
	SUBS(REGB0, REGC6, REGB2),                                               		//      ; REGB2 = EdgePenSetVal.left_ring_th - x
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.left_ring_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.left_ring_SR
	SUBS(REGB0, REGB2, REGC6),                                               		//      ; x = EdgePenSetVal.left_ring_th - REGB2
    SRW0(CONST_VAL(16), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.x = x
	BRC(LINE_CNT(12), DOWN, AL),                                                   	//      ; Always        							-> JP38
	SRW2(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // JP37 ; CH2FLT READ  : tEdgePenSetVal.right_ring_th
	SUBS(REGC0, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalXRes - tEdgePenSetVal.right_ring_th
	CMPS(REGC6, REGB0),                                              				//      ; cmps(x, REGB0)
	BRC(LINE_CNT(8), DOWN, LES),													//      ; x <= REGB0              					-> JP38
	SRW3(CONST_VAL(46), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH3FLT READ  : tEdgePenSetVal.right_ring_mul
	SRW2(CONST_VAL(47), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH2FLT READ  : tEdgePenSetVal.right_ring_SR
	SUBS(REGC6, REGB0, REGB2),                                               		//      ; REGB2 = x - REGB0
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.right_ring_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.right_ring_SR
	ADDS(REGB0, REGB2, REGC6),                                               		//      ; x = REGB0 + REGB2
    SRW0(CONST_VAL(16), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.x = x
	SRW2(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // JP38 ; CH2FLT READ  : tEdgePenSetVal.top_ring_th
	CMPS(REGC7, CH2FLT),                                              				//      ; cmps(y, tEdgePenSetVal.top_ring_th)
	BRC(LINE_CNT(10), DOWN, GES),													//      ; y >= tEdgePenSetVal.top_ring_th              	-> JP39
	SRW3(CONST_VAL(34), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH3FLT READ  : tEdgePenSetVal.top_ring_mul
	MOV(CH2FLT, REGB0),                                                           	//      ; REGB0 = EdgePenSetVal.top_ring_th
	SRW2(CONST_VAL(35), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),  //      ; CH2FLT READ  : tEdgePenSetVal.top_ring_SR
	SUBS(REGB0, REGC7, REGB2),                                               		//      ; REGB2 = EdgePenSetVal.top_ring_th - y
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.top_ring_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.top_ring_SR
	SUBS(REGB0, REGB2, REGC7),                                               		//      ; y = EdgePenSetVal.top_ring_th - REGB2
    SRW0(CONST_VAL(17), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH0FLT WRITE : tOrgPos.tXY.y = y
	BRC(LINE_CNT(12), DOWN, AL),                                                   	//      ; Always        							-> JP32
	SRW2(CONST_VAL(18), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // JP39 ; CH2FLT READ  : tEdgePenSetVal.bottom_ring_th
	SUBS(REGC1, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalYRes - tEdgePenSetVal.bottom_ring_th
	CMPS(REGC7, REGB0),                                              				//      ; cmps(y, REGB0)
	BRC(LINE_CNT(8), DOWN, LES),													//      ; y <= REGB0              					-> JP32
	SRW3(CONST_VAL(38), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	//      ; CH3FLT READ  : tEdgePenSetVal.bottom_ring_mul
	SRW2(CONST_VAL(39), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	//      ; CH2FLT READ  : tEdgePenSetVal.bottom_ring_SR
	SUBS(REGC7, REGB0, REGB2),                                               		//      ; REGB2 = y - REGB0
	MULS(REGB2, CH3FLT, REGB2),                                               		//      ; REGB2 = REGB2 * tEdgePenSetVal.bottom_ring_mul
	SRLS(REGB2, CH2FLT, REGB2),                                               		//      ; REGB2 = REGB2 >> tEdgePenSetVal.bottom_ring_SR
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
//	CMP(REGB7, CONST_VAL(PARTIAL_PEN_COORD1)),                                      // 		; cmp(g_RetVal, PARTIAL_PEN_COORD1)						// LHB check o
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
#if 1//(CUSTOMER == TOSHIBA_PEN || CUSTOMER == MS || CUSTOMER == NEC)
    BRC(LINE_CNT(141), DOWN, LE),                                                   //      ; tPos.vusS <= 0                             -> JP00
#else
	BRC(LINE_CNT(106), DOWN, LE),													//      ; tPos.vusS <= 0                             -> JP00
#endif
	
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
#if 1//(CUSTOMER == TOSHIBA_PEN || CUSTOMER == MS || CUSTOMER == NEC)
	BRC(LINE_CNT(132), DOWN, LE),                                                   //      ; tPastPos[0].vusS <= 0        				-> JP25
#else
	BRC(LINE_CNT(97), DOWN, LE),                                                   //      ; tPastPos[0].vusS <= 0        				-> JP25
#endif
	SRW1(CONST_VAL(30), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // 		; CH1FLT READ : tPastPos[1].vusS
	CMP(CH1FLT, CONST_VAL(0)),                                                   	//      ; cmp(tPastPos[1].vusS, 0)
	BRC(LINE_CNT(83), DOWN, LE),                                                    //      ; tPastPos[1].vusS <= 0        				-> JP04
	SRW2(CONST_VAL(68), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // 		; CH2FLT READ : tPastPos[2].vusS
	CMP(CH2FLT, CONST_VAL(0)),                                                  	//      ; cmp(tPastPos[2].vusS, 0)
	BRC(LINE_CNT(69), DOWN, LE),                                                    //      ; tPastPos[2].vusS <= 0        				-> JP05
	
	SRW0(CONST_VAL(38), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : PenContactCnt
	CMPS(CH0FLT00, CONST_VAL(5)),                                                   //      ; cmp(PenContactCnt, 5)
#if (OrgPastPosInterpolation_OPCODE > 0)
	BRC(LINE_CNT(30), DOWN, LES),                                                   //      ; PenContactCnt <= 5        				-> JP49
#else
	BRC(LINE_CNT(30), DOWN, AL),
#endif
	SRW0(CONST_VAL(35), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tOrgPastPos[2].tXY.x
	SRW1(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tOrgPastPos[1].tXY.x
	SRW2(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tOrgPastPos[0].tXY.x
	SRW3(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH3FLT READ : tOrgPos.tXY.x
	ADDS(CH3FLT, CH2FLT, REGB7),                                              		//      ; REGB7 = CH3FLT + CH2FLT
#if (OrgPastPosInterpolation_OPCODE > 2)
	ADDS(REGB7, CH1FLT, REGB7),                                              		//      ; REGB7 = REGB7 + CH1FLT
	ADDS(REGB7, CH0FLT00, REGB7),                                              		//      ; REGB7 = REGB7 + CH0FLT
#elif (OrgPastPosInterpolation_OPCODE > 1)
	ADDS(REGB7, CH1FLT, REGB7),                                              		//      ; REGB7 = REGB7 + CH1FLT
	ADDS(REGB7, CONST_VAL(0), REGB7),                                              	//      ; REGB7 = REGB7 + 0
#else
	ADDS(REGB7, CONST_VAL(0), REGB7),                                              	//      ; REGB7 = REGB7 + 0
	ADDS(REGB7, CONST_VAL(0), REGB7),                                              	//      ; REGB7 = REGB7 + 0
#endif	
	SRW0(CONST_VAL(32), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[2].tXY.x
	SRW1(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[1].tXY.x
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.x
	ADDS(REGB7, CH0FLT00, REGB7),                                              		//      ; REGB7 = REGB7 + CH0FLT
	ADDS(REGB7, CH1FLT, REGB7),                                              		//      ; REGB7 = REGB7 + CH1FLT
	ADDS(REGB7, CH2FLT, REGB7),                                              		//      ; REGB7 = REGB7 + CH2FLT
#if (OrgPastPosInterpolation_OPCODE > 2)
	DIVS(REGB7, CONST_VAL(7), REGC6),                                              	//      ; REGC6 = REGB7 / 7 : tPos.tXY.x
#elif (OrgPastPosInterpolation_OPCODE > 1)
	DIVS(REGB7, CONST_VAL(6), REGC6),                                              	//      ; REGC6 = REGB7 / 6 : tPos.tXY.x
#else
	DIVS(REGB7, CONST_VAL(5), REGC6),                                              	//      ; REGC6 = REGB7 / 5 : tPos.tXY.x
#endif
	SRW0(CONST_VAL(36), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tOrgPastPos[2].tXY.y
	SRW1(CONST_VAL(26), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tOrgPastPos[1].tXY.y
	SRW2(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tOrgPastPos[0].tXY.y
	SRW3(CONST_VAL(17), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH3FLT READ : tOrgPos.tXY.y
	ADDS(CH3FLT, CH2FLT, REGB7),                                              		//      ; REGB7 = CH3FLT + CH2FLT
#if (OrgPastPosInterpolation_OPCODE > 2)
	ADDS(REGB7, CH1FLT, REGB7),                                              		//      ; REGB7 = REGB7 + CH1FLT
	ADDS(REGB7, CH0FLT00, REGB7),                                              		//      ; REGB7 = REGB7 + CH0FLT
#elif (OrgPastPosInterpolation_OPCODE > 1)
	ADDS(REGB7, CH1FLT, REGB7),                                              		//      ; REGB7 = REGB7 + CH1FLT
	ADDS(REGB7, CONST_VAL(0), REGB7),                                              	//      ; REGB7 = REGB7 + 0
#else
	ADDS(REGB7, CONST_VAL(0), REGB7),                                              	//      ; REGB7 = REGB7 + 0
	ADDS(REGB7, CONST_VAL(0), REGB7),                                              	//      ; REGB7 = REGB7 + 0
#endif
	SRW0(CONST_VAL(33), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[2].tXY.y
	SRW1(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tPastPos[1].tXY.y
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
	ADDS(REGB7, CH0FLT00, REGB7),                                              		//      ; REGB7 = REGB7 + CH0FLT
	ADDS(REGB7, CH1FLT, REGB7),                                              		//      ; REGB7 = REGB7 + CH1FLT
	ADDS(REGB7, CH2FLT, REGB7),                                              		//      ; REGB7 = REGB7 + CH2FLT
#if (OrgPastPosInterpolation_OPCODE > 2)
	DIVS(REGB7, CONST_VAL(7), REGC7),                                              	//      ; REGC6 = REGB7 / 7 : tPos.tXY.y
#elif (OrgPastPosInterpolation_OPCODE > 1)
	DIVS(REGB7, CONST_VAL(6), REGC7),                                              	//      ; REGC6 = REGB7 / 6 : tPos.tXY.y
#else
	DIVS(REGB7, CONST_VAL(5), REGC7),                                              	//      ; REGC6 = REGB7 / 5 : tPos.tXY.y
#endif
	BRC(LINE_CNT(55), DOWN, AL),                                                    // 		; Always                                     -> JP03
	
#ifdef DSP_SMOOTH_PASTPOS
	SRW0(CONST_VAL(32), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP49 ; CH0FLT READ : tPastPos[2].tXY.x
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
	BRC(LINE_CNT(18), DOWN, AL),                                                    //      ; Always                                     -> JP03
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
	BRC(LINE_CNT(7), DOWN, AL),                                                     //      ; Always                                     -> JP03
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

#if 1//(CUSTOMER == TOSHIBA_PEN || CUSTOMER == MS || CUSTOMER == NEC)
	// check hover mode smoothing
	CMP(REGC2, CONST_VAL(LOCAL_HOVER_MODE)), 										// JP03 ; cmp(REGC2, LOCAL_HOVER_MODE)	// REGC2 = mode
	BRC(LINE_CNT(35), DOWN, NE),                                                    //      ; mode != LOCAL_HOVER_MODE    					-> JP25
	SRW0(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[0].tXY.x
	SRW1(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH1FLT READ : tOrgPos.tXY.x
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH2FLT READ : tPastPos[0].tXY.y
	SRW3(CONST_VAL(17), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH3FLT READ : tOrgPos.tXY.y
	SUBS(CH0FLT00, REGC6, REGB1),                                                  //      ; REGB1 = pos1.x - pos2.x (tPastPos[0].tXY.x - tOrgPos.tXY.x)
    MULS(REGB1, REGB1, REGB1),                                                      //      ; REGB1 = REGB1 * REGB1
    SUBS(CH2FLT, REGC7, REGB2),                                                    //      ; REGB2 = pos1.y - pos2.y (tPastPos[0].tXY.y - tOrgPos.tXY.y)
    MULS(REGB2, REGB2, REGB2),                                                      //      ; REGB2 = REGB2 * REGB2
    ADDS(REGB1, REGB2, REGB1),                                                      //      ; REGB1 = REGB1 + REGB2 : dist
    MOV(CONST_VAL(1), REGB2),                                                       //      ; REGB2 = 1 : x
    SLOOP0(1, 15, LOOP_LE, LOOP_SOURCE),                                            //      ; loop 1:15
    DIVS(REGB1, REGB2, REGB3),                                                      //      ; REGB3 = REGB1 / REGB2
    ADDS(REGB2, REGB3, REGB3),                                                      //      ; REGB3 = REGB2 + REGB3
    SRLS(REGB3, CONST_VAL(1), REGB2),                                               //      ; REGB2 = REGB3 >> 1
    ELOOP0(),                                                                       //      ; loop end
	ADDS(REGB2, REGA1, REGB0),                                               		//      ; REGB0 = REGB2 + REGA1 (prev_curr_dist+offset)
	//DIVS(REGB2, REGA1, REGB0),
	CMPS(REGB0, CONST_VAL(10)),                                                     // 		; cmp(REGB0, 10)
    BRC(LINE_CNT(2), DOWN, GTS),                                                    //      ; (REGB0) > 10 									-> JP27
	MOV(CONST_VAL(10), REGB0),                                               		//      ; REGB0 = 10
	CMPS(REGB0, REGA4),                                                             // JP27 ; cmps(prev_curr_dist, (1<<lMoveSmoothingLevel))
    BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; prev_curr_dist <= (1<<lMoveSmoothingLevel)	-> JP26
    MOV(REGA4, REGB0),                                                              //      ; REGB0 = (1<<lMoveSmoothingLevel)
    SUBS(REGA4, REGB0, REGB1),                                                      // JP26 ; REGB1 = (1<<lMoveSmoothingLevel) - prev_curr_dist
	SRL(REGA4, CONST_VAL(1), REGB4),                                                //      ; REGB4 = (1<<lMoveSmoothingLevel) >> 1
    MULS(REGB1, CH0FLT00, REGB2),                                                   //      ; REGB2 = REGB1 * tPastPos[0].tXY.x
    MULS(REGB0, REGC6, REGB3),                                                     //      ; REGB3 = prev_curr_dist * tOrgPos.tXY.x
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC6),                                                      //      ; REGC6 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.x
    MULS(REGB1, CH2FLT, REGB2),                                                     //      ; REGB2 = REGB1 * tPastPos[0].tXY.y
    MULS(REGB0, REGC7, REGB3),                                                     //      ; REGB3 = prev_curr_dist * tOrgPos.tXY.y
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC7),                                                      //      ; REGC7 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.y
#endif

	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always                                     -> JP25
	MOV(CONST_VAL(0), REGA7),                                                       // JP00 ; REGA7 = 0 : ucIdMappedCnt
	
    // Write
    SRW1(CONST_VAL(0), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          // JP25 ; CH1FLT WRITE : tPos.tXY.x = REGC6
    SRW2(CONST_VAL(1), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH2FLT WRITE : tPos.tXY.y = REGC7
    SRW3(CONST_VAL(4), REGC4, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH3FLT WRITE : tPos.vusS = REGC4
    SRW0(CONST_VAL(5), REGC5, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),        //      ; CH0FLT WRITE : tPos.vusR = REGC5
	
    END()    
};

#ifdef SRAM_OPCODE
int opcode_PenDisBasedSmoothAdd[] = 
#else
int opcode_PenDisBasedSmoothAdd[] = 
#endif	
{	
	SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
    SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ;
    SDMA3(REGA0, 0, DMA_SIZE2),                                                     //      ; 
	SDMA2(REGC3, 0, DMA_SIZE2),                                                     // 		; C3 : pen edge
	
	SRW0(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH0FLT READ : tPos.vusS 	
    CMP(CH0FLT00, CONST_VAL(0)),                                                    //      ; cmp(tPos.vusS, 0)
    BRC(LINE_CNT(222), DOWN, LE),                                                   //      ; tPos.vusS <= 0                             -> JP00
	SRW0(CONST_VAL(24), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), // 		; CH0FLT READ : tPastPos[0].vusS
	CMP(CH0FLT00, CONST_VAL(0)),                                                    //      ; cmp(tPastPos[0].vusS, 0)
    BRC(LINE_CNT(219), DOWN, LE),                                                   //      ; tPastPos[0].vusS <= 0        				 -> JP00	
	SRW1(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH1FLT READ : tPos.tXY.x
	SRW3(CONST_VAL(1), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    // 		; CH3FLT READ : tPos.tXY.y
	MOV(CH1FLT,REGC6),
	MOV(CH3FLT,REGC7),
	MOV(CONST_VAL(0),REGB7),														//		; REGB7 = 0	
	CMP(REGC2, CONST_VAL(LOCAL_HOVER_MODE)), 										// 	    ; cmp(REGC2, LOCAL_HOVER_MODE)	// REGC2 = mode
	BRC(LINE_CNT(6), DOWN, NE),                                                     //      ; mode != LOCAL_HOVER_MODE    										-> JP28	
	SRW2(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	//      ; CH2FLT READ  : tEdgePenSetVal.edge_smooth_offset_hover
	CMPS(CH2FLT, CONST_VAL(127)),                                              		//      ; cmps(tEdgePenSetVal.edge_smooth_offset_hover,127)
	BRC(LINE_CNT(128), DOWN, GES),													//      ; edge_smooth_offset_hover >= 127						       				-> JP42
	MOV(CONST_VAL(1),REGB7),														//		; REGB7 = 1
	BRC(LINE_CNT(5), DOWN, AL),                                                     //      ; Always                                     								-> JP29
	SRW2(CONST_VAL(1), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT), 	// JP28 ; CH2FLT READ  : tEdgePenSetVal.edge_smooth_offset_contact
	CMPS(CH2FLT, CONST_VAL(127)),                                              		//      ; cmps(tEdgePenSetVal.edge_smooth_offset_contact,127)
	BRC(LINE_CNT(22), DOWN, GES),													//      ; edge_smooth_offset_contact >= 127						       				-> JP39
	MOV(CONST_VAL(2),REGB7),														//		; REGB7 = 2	
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP29 ; CH2FLT READ  : SmoothSetVal.EdgeRange 
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN) 
	CMPS(REGC6, REGC0),                                              				//      ; cmps(x, SmoothSetVal.EdgeRange)
#else
	CMPS(REGC6, CH2FLT),                                              				//      ; cmps(x, SmoothSetVal.EdgeRange)
#endif
	BRC(LINE_CNT(2), DOWN, GES),													//      ; x >= tEdgePenSetVal.left_hover_th        	-> JP30
	BRC(LINE_CNT(21), DOWN, AL),													//      ; 			             					-> JP32
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP30 ; CH2FLT READ  : tEdgePenSetVal.right_hover_th
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN) 
	SUBS(REGA2, REGC0, REGB0),                                                		//      ; REGB0 = iInternalXRes - (1<<(POS_BOOST_SHIFT_))
#else
	SUBS(REGA2, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalXRes - tEdgePenSetVal.right_hover_th
#endif
	CMPS(REGC6, REGB0),                                              				//      ; cmps(x, REGB0)
	BRC(LINE_CNT(2), DOWN, LES),													//      ; x <= REGB0              					-> JP31
	BRC(LINE_CNT(16), DOWN, AL),													//      ; 			             					-> JP32
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP31 ; CH2FLT READ  :SmoothSetVal.EdgeRange
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN) 
	CMPS(REGC7, REGC0),                                              				//      ; cmps(y, SmoothSetVal.EdgeRange)
#else
	CMPS(REGC7, CH2FLT),                                              				//      ; cmps(y, SmoothSetVal.EdgeRange)
#endif
	BRC(LINE_CNT(2), DOWN, GES),													//      ; y >= tEdgePenSetVal.top_hover_th              	-> JP38
	BRC(LINE_CNT(12), DOWN, AL),													//      ; 			             					-> JP32
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP38 ; CH2FLT READ  : SmoothSetVal.EdgeRange
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
	SUBS(REGA3, REGC0, REGB0),                                                		//      ; REGB0 = iInternalYRes - SmoothSetVal.EdgeRange
#else
	SUBS(REGA3, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalYRes - SmoothSetVal.EdgeRange
#endif
	CMPS(REGC7, REGB0),                                              				//      ; cmps(y, REGB0)
	BRC(LINE_CNT(2), DOWN, LES),													//      ; y <= REGB0              					-> JP40	
	BRC(LINE_CNT(7), DOWN, AL),														//      ; 			             					-> JP32
	CMP(REGC2, CONST_VAL(LOCAL_MODE)), 												// JP40 ; cmp(REGC2, LOCAL_MODE)	// REGC2 = mode
	BRC(LINE_CNT(102), DOWN, NE),                                                   //      ; mode != LOCAL_MODE    										-> JP42
	SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	// JP39 ; CH2FLT READ  : tEdgePenSetVal.global_smooth_dis_condition_contact
	CMP(CH2FLT, CONST_VAL(0)),                                              		//      ; cmps(tEdgePenSetVal.global_smooth_dis_condition_contact,0)
	BRC(LINE_CNT(99), DOWN, EQ),													//      ; global_smooth_dis_condition_contact == 0						-> JP42
	MOV(CONST_VAL(3),REGB7),														//		; REGB7 = 3			
	SRW1(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP32 ; CH1FLT READ : tPastPos[0].tXY.x
	SRW3(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH3FLT READ : tPastPos[0].tXY.y	
	SUBS(REGC6, CH1FLT, REGB1),                                                  	//      ; REGB1 = pos1.x - pos2.x (tPos.tXY.x - tPastPos[0].tXY.x)
    MULS(REGB1, REGB1, REGB1),                                                      //      ; REGB1 = REGB1 * REGB1
    SUBS(REGC7, CH3FLT, REGB2),                                                    	//      ; REGB2 = pos1.y - pos2.y (tPos.tXY.y - tPastPos[0].tXY.y)
    MULS(REGB2, REGB2, REGB2),                                                      //      ; REGB2 = REGB2 * REGB2
    ADDS(REGB1, REGB2, REGB1),                                                      //      ; REGB1 = REGB1 + REGB2 : dist
    MOV(CONST_VAL(1), REGB2),                                                       //      ; REGB2 = 1 : x
    SLOOP0(1, 15, LOOP_LE, LOOP_SOURCE),                                            //      ; loop 1:15
    DIVS(REGB1, REGB2, REGB3),                                                      //      ; REGB3 = REGB1 / REGB2
    ADDS(REGB2, REGB3, REGB3),                                                      //      ; REGB3 = REGB2 + REGB3
    SRLS(REGB3, CONST_VAL(1), REGB2),                                               //      ; REGB2 = REGB3 >> 1
    ELOOP0(),                                                                       //      ; loop end
	CMP(REGB7, CONST_VAL(1)), 														// 		; cmp(REGB7, 1)	
	BRC(LINE_CNT(3), DOWN, NE),                                                     //      ; REGB7 != 1			    					-> JP33
	SRW2(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	//      ; CH2FLT READ  : tEdgePenSetVal.edge_smooth_offset_hover
	BRC(LINE_CNT(15), DOWN, AL),													//      ; 			             						-> JP35	
	CMP(REGB7, CONST_VAL(2)), 														// JP33 ; cmp(REGB7, 2)
	BRC(LINE_CNT(9), DOWN, NE),                                                     // 		; REGB7 != 2			    					-> JP34
	SRW2(CONST_VAL(7), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	// 		; CH2FLT READ  : tEdgePenSetVal.edge_smooth_dis_condition_contact	
	CMPS(REGB2, CH2FLT),                                                     		// 		; cmp(prev_curr_dist, edge_smooth_dis_condition_contact)	
	BRC(LINE_CNT(76), DOWN, GTS),                                                   //      ; (prev_curr_dist) > edge_smooth_dis_condition_contact 		-> JP42	
	SRW2(CONST_VAL(1), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),    // 		; CH2FLT READ  : tEdgePenSetVal.edge_smooth_offset_contact		
	CMPS(REGB2, CONST_VAL(20)),                                                     // 		; cmp(prev_curr_dist, 20)
	BRC(LINE_CNT(2), DOWN, LTS),                                                    //      ; (prev_curr_dist) < 20 									-> JP57	
	MOV(CONST_VAL(3),REGB7),														//		; REGB7 = 3		
	BRC(LINE_CNT(5), DOWN, AL),													    // JP57 ; 			             									-> JP35	
	SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT), 	// JP34 ; CH2FLT READ  : tEdgePenSetVal.global_smooth_dis_condition_contact
	CMPS(REGB2, CH2FLT),                                                     		// 		; cmp(prev_curr_dist, global_smooth_dis_condition_contact)
    BRC(LINE_CNT(68), DOWN, GTS),                                                   //      ; (prev_curr_dist) > global_smooth_dis_condition_contact 		-> JP42	
	SRW2(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),    // 		; CH2FLT READ  : tEdgePenSetVal.global_smooth_offset_contact	
	ADDS(REGB2, CH2FLT, REGB0),                                               		// JP35 ; REGB0 = REGB2 + CH2FLT : prev_curr_dist + smooth_offset
	CMPS(REGB0, CONST_VAL(10)),                                                     // 		; cmp(prev_curr_dist, 10)
    BRC(LINE_CNT(2), DOWN, GTS),                                                    //      ; (prev_curr_dist) > 10 						-> JP41
	MOV(CONST_VAL(10), REGB0),                                               		//      ; REGB0 = 10
	CMPS(REGB0, REGA4),                                                             // JP41 ; cmps(prev_curr_dist, (1<<lMoveSmoothingLevel))
    BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; prev_curr_dist <= (1<<lMoveSmoothingLevel)	-> JP36
    MOV(REGA4, REGB0),                                                              //      ; REGB0 = (1<<lMoveSmoothingLevel)
    SUBS(REGA4, REGB0, REGB1),                                                      // JP36 ; REGB1 = (1<<lMoveSmoothingLevel) - prev_curr_dist
	CMP(REGC2, CONST_VAL(LOCAL_HOVER_MODE)), 										// 		; cmp(REGC2, LOCAL_HOVER_MODE)	// REGC2 = mode
	BRC(LINE_CNT(6), DOWN, NE),                                                     //      ; mode != LOCAL_HOVER_MODE    					-> JP37
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)	
	CMP(REGB0, CONST_VAL(0)), 														// 		; cmp(REGB0, 127)	// REGB0 = prev_curr_dist
#else
	CMP(REGB0, CONST_VAL(127)), 													// 		; cmp(REGB0, 127)	// REGB0 = prev_curr_dist
#endif
	BRC(LINE_CNT(4), DOWN, GT),                                                     //      ; prev_curr_dist > 127    						-> JP37
	MOV(REGB0,REGB2),																//		; REGB2 = REGB0 : tmp = prev_curr_dist
	MOV(REGB1,REGB0),																//		; REGB0 = REGB1 : REGB0 = (1<<lMoveSmoothingLevel) - prev_curr_dist
	MOV(REGB2,REGB1),																//		; REGB1 = REGB2 : REGB1 = prev_curr_dist
//x,y each smoothing		
	CMP(REGB7, CONST_VAL(2)), 														// JP37 ; cmp(REGB7, 2)
	BRC(LINE_CNT(39), DOWN, NE),                                                    // 		; REGB7 != 2			    								-> JP50
	CMPS(REGC6, CH1FLT), 															// 		; cmp(REGC6, CH1FLT)	// tPos.tXY.x , tPastPos[0].tXY.x
	BRC(LINE_CNT(3), DOWN, LES),                                                    //      ; tPos.tXY.x <= tPastPos[0].tXY.x							-> JP51
	SUBS(REGC6, CH1FLT, REGB0),                                                  	//      ; REGB0 = pos1.x - pos2.x (tPos.tXY.x - tPastPos[0].tXY.x)
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ;
	SUBS(CH1FLT, REGC6, REGB0),                                                  	// JP51 ; REGB0 = pos2.x - pos1.x (tPastPos[0].tXY.x - tPos.tXY.x )
	ADDS(REGB0, CH2FLT, REGB0),                                               		// 		; REGB0 = REGB2 + CH2FLT : prev_curr_dist + smooth_offset
	CMPS(REGB0, CONST_VAL(10)),                                                     // 		; cmp(prev_curr_dist, 10)
    BRC(LINE_CNT(2), DOWN, GTS),                                                    //      ; (prev_curr_dist) > 10 						-> JP52
	MOV(CONST_VAL(10), REGB0),                                               		//      ; REGB0 = 10
	CMPS(REGB0, REGA4),                                                             // JP52 ; cmps(prev_curr_dist, (1<<lMoveSmoothingLevel))
    BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; prev_curr_dist <= (1<<lMoveSmoothingLevel)	-> JP53
    MOV(REGA4, REGB0),                                                              //      ; REGB0 = (1<<lMoveSmoothingLevel)
	SUBS(REGA4, REGB0, REGB1),                                                      // JP53 ; REGB1 = (1<<lMoveSmoothingLevel) - prev_curr_dist
	SRL(REGA4, CONST_VAL(1), REGB4),                                                // 		; REGB4 = (1<<lMoveSmoothingLevel) >> 1
    MULS(REGB1, CH1FLT, REGB2),                                                   	//      ; REGB2 = REGB1 * tPastPos[0].tXY.x
    MULS(REGB0, REGC6, REGB3),                                                     	//      ; REGB3 = prev_curr_dist * tPos.tXY.x
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC6),                                                      //      ; REGC6 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.x	
	CMPS(REGC7, CH3FLT), 															// 		; cmp(REGC7, CH3FLT)	// tPos.tXY.y , tPastPos[0].tXY.y
	BRC(LINE_CNT(3), DOWN, LES),                                                    //      ; tPos.tXY.y <= tPastPos[0].tXY.y							-> JP54
	SUBS(REGC7, CH3FLT, REGB0),                                                  	//      ; REGB0 = pos1.y - pos2.y (tPos.tXY.y - tPastPos[0].tXY.y)
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ;
	SUBS(CH3FLT, REGC7, REGB0),                                                  	// JP54 ; REGB0 = pos2.y - pos1.y (tPastPos[0].tXY.y - tPos.tXY.y )
	ADDS(REGB0, CH2FLT, REGB0),                                               		// 		; REGB0 = REGB2 + CH2FLT : prev_curr_dist + smooth_offset
	CMPS(REGB0, CONST_VAL(10)),                                                     // 		; cmp(prev_curr_dist, 10)
    BRC(LINE_CNT(2), DOWN, GTS),                                                    //      ; (prev_curr_dist) > 10 						-> JP55
	MOV(CONST_VAL(10), REGB0),                                               		//      ; REGB0 = 10
	CMPS(REGB0, REGA4),                                                             // JP55 ; cmps(prev_curr_dist, (1<<lMoveSmoothingLevel))
    BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; prev_curr_dist <= (1<<lMoveSmoothingLevel)	-> JP56
    MOV(REGA4, REGB0),                                                              //      ; REGB0 = (1<<lMoveSmoothingLevel)
	SUBS(REGA4, REGB0, REGB1),                                                      // JP56 ; REGB1 = (1<<lMoveSmoothingLevel) - prev_curr_dist
    MULS(REGB1, CH3FLT, REGB2),                                                     //      ; REGB2 = REGB1 * tPastPos[0].tXY.y
    MULS(REGB0, REGC7, REGB3),                                                     	//      ; REGB3 = prev_curr_dist * tPos.tXY.y
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC7),                                                      //      ; REGC7 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.y	
	BRC(LINE_CNT(12), DOWN, AL),                                                    //      ;												-> JP42
	SRL(REGA4, CONST_VAL(1), REGB4),                                                // JP50 ; REGB4 = (1<<lMoveSmoothingLevel) >> 1
    MULS(REGB1, CH1FLT, REGB2),                                                   	//      ; REGB2 = REGB1 * tPastPos[0].tXY.x
    MULS(REGB0, REGC6, REGB3),                                                     	//      ; REGB3 = prev_curr_dist * tPos.tXY.x
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC6),                                                      //      ; REGC6 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.x
    MULS(REGB1, CH3FLT, REGB2),                                                     //      ; REGB2 = REGB1 * tPastPos[0].tXY.y
    MULS(REGB0, REGC7, REGB3),                                                     	//      ; REGB3 = prev_curr_dist * tPos.tXY.y
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC7),                                                      //      ; REGC7 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.y	
////corner&global hover delta condition	
	CMP(REGC2, CONST_VAL(LOCAL_HOVER_MODE)), 										// JP42	; cmp(REGC2, LOCAL_HOVER_MODE)	// REGC2 = mode
	BRC(LINE_CNT(80), DOWN, NE),                                                    //      ; mode != LOCAL_HOVER_MODE    					-> JP25		
	MOV(CONST_VAL(0),REGB7),														//		; REGB7 = 0		
	SRW2(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // 		; CH2FLT READ  : tEdgePenSetVal.corner_smooth_delta_condition_hover	
	SRW1(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tPos.MaxDelta 
	CMP(CH2FLT, CONST_VAL(0)), 														// 	    ; cmp(CH2FLT, 0)
	BRC(LINE_CNT(29), DOWN, EQ),                                                    // 		; corner_smooth_delta_condition_hover == 0	 -> JP01
	CMP(CH1FLT, CH2FLT), 															// 		; cmp(CH1FLT, CH2FLT)
	BRC(LINE_CNT(27), DOWN, GT),                                                    // 		; MaxDelta > corner_smooth_delta_condition_hover  	-> JP01	
	MOV(CONST_VAL(4),REGB7),														//		; REGB7 = 4		
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH2FLT READ  : SmoothSetVal.EdgeRange
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
	CMPS(REGC6, REGC0),                                              				//      ; cmps(x, SmoothSetVal.EdgeRange)
#else 
	CMPS(REGC6, CH2FLT),                                              				//      ; cmps(x, SmoothSetVal.EdgeRange)
#endif
	BRC(LINE_CNT(10), DOWN, GES),													//      ; x >= SmoothSetVal.EdgeRange	        			-> JP44
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // 		; CH2FLT READ  : SmoothSetVal.EdgeRange
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
	CMPS(REGC7, REGC0),                                              				//      ; cmps(y, SmoothSetVal.EdgeRange)
#else 
	CMPS(REGC7, CH2FLT),                                              				//      ; cmps(y, SmoothSetVal.EdgeRange)
#endif
	BRC(LINE_CNT(2), DOWN, GES),													//      ; y >= SmoothSetVal.EdgeRange		              	-> JP43
	BRC(LINE_CNT(25), DOWN, AL),													//      ; 			             							-> JP46
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP43 ; CH2FLT READ  : SmoothSetVal.EdgeRange
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
	SUBS(REGA3, REGC0, REGB0),                                                		//      ; REGB0 = iInternalYRes - SmoothSetVal.EdgeRange
#else 
	SUBS(REGA3, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalYRes - SmoothSetVal.EdgeRange
#endif
	CMPS(REGC7, REGB0),                                              				//      ; cmps(y, REGB0)
	BRC(LINE_CNT(15), DOWN, LES),													//      ; y <= REGB0              							-> JP01	
	BRC(LINE_CNT(20), DOWN, AL),													//      ; 			             							-> JP46	
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP44 ; CH2FLT READ  : SmoothSetVal.EdgeRange
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
	SUBS(REGA2, REGC0, REGB0),                                                		//      ; REGB0 = iInternalXRes - SmoothSetVal.EdgeRange
#else 
	SUBS(REGA2, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalXRes - SmoothSetVal.EdgeRange
#endif
	CMPS(REGC6, REGB0),                                              				//      ; cmps(x, REGB0)
	BRC(LINE_CNT(10), DOWN, LES),													//      ; x <= REGB0              							-> JP01
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // 		; CH2FLT READ  : SmoothSetVal.EdgeRange
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
	CMPS(REGC7, REGC0),                                              				//      ; cmps(y, SmoothSetVal.EdgeRange)
#else 
	CMPS(REGC7, CH2FLT),                                              				//      ; cmps(y, SmoothSetVal.EdgeRange)
#endif
	BRC(LINE_CNT(2), DOWN, GES),													//      ; y >= SmoothSetVal.EdgeRange		             	-> JP45
	BRC(LINE_CNT(12), DOWN, AL),													//      ; 			             							-> JP46
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  // JP45 ; CH2FLT READ  : SmoothSetVal.EdgeRange
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
	SUBS(REGA3, REGC0, REGB0),                                                		//      ; REGB0 = iInternalYRes - SmoothSetVal.EdgeRange
#else
	SUBS(REGA3, CH2FLT, REGB0),                                                		//      ; REGB0 = iInternalYRes - SmoothSetVal.EdgeRange
#endif
	CMPS(REGC7, REGB0),                                              				//      ; cmps(y, REGB0)
	BRC(LINE_CNT(2), DOWN, LES),													//      ; y <= REGB0              							-> JP01	
	BRC(LINE_CNT(7), DOWN, AL),														//      ; 			             							-> JP46
	SRW2(CONST_VAL(8), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),   // JP01	; CH2FLT READ  : tEdgePenSetVal.global_smooth_delta_condition_hover	
	CMP(CH2FLT, CONST_VAL(0)), 														// 	    ; cmp(CH2FLT, 0)
	BRC(LINE_CNT(44), DOWN, EQ),                                                    // 		; global_smooth_delta_condition_hover == 0	 		-> JP25	
	CMP(CH1FLT, CH2FLT), 															// 		; cmp(CH1FLT, CH2FLT)
	BRC(LINE_CNT(42), DOWN, GT),                                                    // 		; MaxDelta > global_smooth_delta_condition_hover  	-> JP25
	MOV(CONST_VAL(5),REGB7),														//		; REGB7 = 5	
	SRW1(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP46	; CH1FLT READ : tPastPos[0].tXY.x
	SRW3(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH3FLT READ : tPastPos[0].tXY.y	
	SUBS(REGC6, CH1FLT, REGB1),                                                  	//      ; REGB1 = pos1.x - pos2.x (tPos.tXY.x - tPastPos[0].tXY.x)
    MULS(REGB1, REGB1, REGB1),                                                      //      ; REGB1 = REGB1 * REGB1
    SUBS(REGC7, CH3FLT, REGB2),                                                    	//      ; REGB2 = pos1.y - pos2.y (tPos.tXY.y - tPastPos[0].tXY.y)
    MULS(REGB2, REGB2, REGB2),                                                      //      ; REGB2 = REGB2 * REGB2
    ADDS(REGB1, REGB2, REGB1),                                                      //      ; REGB1 = REGB1 + REGB2 : dist
    MOV(CONST_VAL(1), REGB2),                                                       //      ; REGB2 = 1 : x
    SLOOP0(1, 15, LOOP_LE, LOOP_SOURCE),                                            //      ; loop 1:15
    DIVS(REGB1, REGB2, REGB3),                                                      //      ; REGB3 = REGB1 / REGB2
    ADDS(REGB2, REGB3, REGB3),                                                      //      ; REGB3 = REGB2 + REGB3
    SRLS(REGB3, CONST_VAL(1), REGB2),                                               //      ; REGB2 = REGB3 >> 1
    ELOOP0(),                                                                       //      ; loop end		
	CMP(REGB7, CONST_VAL(4)), 														// 		; cmp(REGB7, 4)
	BRC(LINE_CNT(3), DOWN, NE),     												//		; REGB7 != 4											-> JP02
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	//      ; CH2FLT READ  : tEdgePenSetVal.corner_smooth_offset_hover
	BRC(LINE_CNT(5), DOWN, AL),														//		;														-> JP03
	SRW2(CONST_VAL(9), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	// JP02	; CH2FLT READ  : tEdgePenSetVal.global_smooth_dis_condition_hover
	CMPS(REGB2, CH2FLT), 															// 		; cmp(REGB2, CH2FLT)
	BRC(LINE_CNT(21), DOWN, GTS),     												//		; prev_curr_dist > global_smooth_dis_condition_hover	-> JP25
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),  	//      ; CH2FLT READ  : tEdgePenSetVal.global_smooth_offset_hover	
	ADDS(REGB2, CH2FLT, REGB0),                                               		// JP03	; REGB0 = REGB2 + CH2FLT : prev_curr_dist + smooth_offset
	CMPS(REGB0, CONST_VAL(10)),                                                     // 		; cmp(prev_curr_dist, 10)
    BRC(LINE_CNT(2), DOWN, GTS),                                                    //      ; (prev_curr_dist) > 10 						-> JP47
	MOV(CONST_VAL(10), REGB0),                                               		//      ; REGB0 = 10
	CMPS(REGB0, REGA4),                                                             // JP47 ; cmps(prev_curr_dist, (1<<lMoveSmoothingLevel))
    BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; prev_curr_dist <= (1<<lMoveSmoothingLevel)	-> JP48
    MOV(REGA4, REGB0),                                                              //      ; REGB0 = (1<<lMoveSmoothingLevel)
    SUBS(REGA4, REGB0, REGB1),                                                      // JP48 ; REGB1 = (1<<lMoveSmoothingLevel) - prev_curr_dist
	SRL(REGA4, CONST_VAL(1), REGB4),                                                // 		; REGB4 = (1<<lMoveSmoothingLevel) >> 1
    MULS(REGB1, CH1FLT, REGB2),                                                   	//      ; REGB2 = REGB1 * tPastPos[0].tXY.x
    MULS(REGB0, REGC6, REGB3),                                                     	//      ; REGB3 = prev_curr_dist * tPos.tXY.x
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC6),                                                      //      ; REGC6 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.x
    MULS(REGB1, CH3FLT, REGB2),                                                     //      ; REGB2 = REGB1 * tPastPos[0].tXY.y
    MULS(REGB0, REGC7, REGB3),                                                     	//      ; REGB3 = prev_curr_dist * tOrgPos.tXY.y
    ADDS(REGB2, REGB3, REGB2),                                                      //      ; REGB2 = REGB2 + REGB3
    ADDS(REGB2, REGB4, REGB2),                                                      //      ; REGB2 = REGB2 + REGB4
    SRLS(REGB2, REGA5, REGC7),                                                      //      ; REGC7 = REGB2 >> lMoveSmoothingLevel : tPos.tXY.y		
    // Write
    SRW1(CONST_VAL(0), REGC6, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          // JP25 ; CH1FLT WRITE : tPos.tXY.x = REGC6
    SRW0(CONST_VAL(1), REGC7, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH2FLT WRITE : tPos.tXY.y = REGC7	
	
// CornerSmoothContact ADD ING... HanCH
//	CMP(REGC2, CONST_VAL(LOCAL_MODE)), 												// 	    ; cmp(REGC2, LOCAL_MODE)	// REGC2 = mode
//	BRC(LINE_CNT(6), DOWN, NE),                                                     //      ; mode != LOCAL_MODE    										-> JP00	
//	SRW2(CONST_VAL(15), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	// JP02	; CH2FLT READ  : ucCornerSmoothContact_DisCondition
//	CMP(CH2FLT, CONST_VAL(0)), 														// 	    ; cmp(ucCornerSmoothContact_DisCondition, 0)	
//	BRC(LINE_CNT(6), DOWN, EQ),                                                     //      ; ucCornerSmoothContact_DisCondition == 0   					-> JP00
//	SRW2(CONST_VAL(7), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),  //      ; CH2FLT READ  : usCornerSmoothContact_CornerRange
//	CMPS(REGC6, CH2FLT),                                              				//      ; cmps(x, SmoothSetVal.usCornerSmoothContact_CornerRange)
	
    END() 																			// JP00
};

#ifdef SRAM_OPCODE
int opcode_coordpost[] = 
#else
int opcode_coordpost[] = 
#endif
{
	SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
	SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
	SDMA2(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : coord info
	SDMA3(REGA0, 0, DMA_SIZE2),														//      ; A0 : coord info
	
	SRW0(CONST_VAL(8), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),	//      ; CH0FLT WRITE : tAvgPos.x = 0
	
	CMPS(REGB5, CONST_VAL(0)),														//		; cmps(tAvgPos.y, 0)
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(342), DOWN, EQ),                                                   //      ; tAvgPos.y == 0                     								 							-> JP00
#else
	BRC(LINE_CNT(328), DOWN, EQ),                                                   //      ; tAvgPos.y == 0                     								 							-> JP00
#endif
	CMPS(REGB0, REGB2),																//      ; cmps(HID_PEN_X, thisModeConf->Coord.ucPenPostProcessXEdge)
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(340), DOWN, LTS),                                                  //      ; HID_PEN_X < thisModeConf->Coord.ucPenPostProcessXEdge       		 							-> JP00
#else
	BRC(LINE_CNT(326), DOWN, LTS),                                                  //      ; HID_PEN_X < thisModeConf->Coord.ucPenPostProcessXEdge       		 							-> JP00
#endif
	CMPS(REGB0, REGB3),																//      ; cmps(HID_PEN_X, thisCommonConf->iXResolution - thisModeConf->Coord.ucPenPostProcessXEdge)
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(338), DOWN, GTS),                                                  //      ; HID_PEN_X > thisCommonConf->iXResolution - thisModeConf->Coord.ucPenPostProcessXEdge			-> JP00
#else
	BRC(LINE_CNT(324), DOWN, GTS),                                                  //      ; HID_PEN_X > thisCommonConf->iXResolution - thisModeConf->Coord.ucPenPostProcessXEdge			-> JP00
#endif
	CMPS(REGB1, REGB2),																//      ; cmps(HID_PEN_Y, thisModeConf->Coord.ucPenPostProcessXEdge)
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(336), DOWN, LTS),                                                  //      ; HID_PEN_Y < thisModeConf->Coord.ucPenPostProcessXEdge       									-> JP00
#else
	BRC(LINE_CNT(322), DOWN, LTS),                                                  //      ; HID_PEN_Y < thisModeConf->Coord.ucPenPostProcessXEdge       									-> JP00
#endif
	CMPS(REGB1, REGB4),																//      ; cmps(HID_PEN_Y, thisCommonConf->iYResolution - thisModeConf->Coord.ucPenPostProcessXEdge)
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(334), DOWN, GTS),                                                  //      ; HID_PEN_Y > thisCommonConf->iYResolution - thisModeConf->Coord.ucPenPostProcessXEdge			-> JP00
#else
	BRC(LINE_CNT(320), DOWN, GTS),                                                  //      ; HID_PEN_Y > thisCommonConf->iYResolution - thisModeConf->Coord.ucPenPostProcessXEdge			-> JP00
#endif
	
	MOV(CONST_VAL(0), REGB0),                                                       //      ; REGB0 = 0 ; x_edge_f
	MOV(CONST_VAL(0), REGB1),                                                       //      ; REGB1 = 0 ; y_edge_f
	SRW1(CONST_VAL(48), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tOrgPastPos[0].vusS
	SRW2(CONST_VAL(54), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH2FLT READ : tOrgPastPos[1].vusS
	SRW3(CONST_VAL(74), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH3FLT READ : tOrgPastPos2.vusS
	CMP(CH1FLT, CONST_VAL(0)),                                                      //      ; cmp(tOrgPastPos[0].vusS, 0)
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(327), DOWN, LE),                                                   //      ; tOrgPastPos[0].vusS <= 0                   													-> JP00
#else
	BRC(LINE_CNT(313), DOWN, LE),                                                   //      ; tOrgPastPos[0].vusS <= 0                   													-> JP00
#endif
	CMP(CH2FLT, CONST_VAL(0)),                                                      //      ; cmp(tOrgPastPos[1].vusS, 0)
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(325), DOWN, LE),                                                   //      ; tOrgPastPos[1].vusS <= 0                       												-> JP00
#else
	BRC(LINE_CNT(311), DOWN, LE),                                                   //      ; tOrgPastPos[1].vusS <= 0                       												-> JP00
#endif
	CMP(CH3FLT, CONST_VAL(0)),                                                      //      ; cmp(tOrgPastPos2.vusS, 0)
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(323), DOWN, LE),                                                   //      ; tOrgPastPos2.vusS <= 0                       													-> JP00
#else
	BRC(LINE_CNT(309), DOWN, LE),                                                   //      ; tOrgPastPos2.vusS <= 0                       													-> JP00
#endif
	SRW1(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.x
	SRW2(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tOrgPastPos[0].tXY.y
	CMPS(CH1FLT, REGA7),															//		; cmps(tOrgPastPos[0].tXY.x, (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH))
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(6), DOWN, GES),                                                   	//      ; tOrgPastPos[0].tXY.x >= (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH)                   	-> JP01
#else
	BRC(LINE_CNT(3), DOWN, GES),                                                   	//      ; tOrgPastPos[0].tXY.x >= (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH)                   	-> JP01
#endif
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    SRW3(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH3FLT READ : tFirstPos.tXY.x
    CMPS(CH3FLT, REGC5),															//		; cmps(tFirstPos.tXY.x, (1<<POS_BOOST_SHIFT_))
	BRC(LINE_CNT(3), DOWN, LES),                                                   	//      ; tFirstPos.tXY.x <= (1<<POS_BOOST_SHIFT_)                   	                                -> JP01
#endif
	MOV(CONST_VAL(1), REGB0),                                                       //      ; REGB0 = 1 ; x_edge_f
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(9), DOWN, AL),                                                    	//      ; Always              																			-> JP02
#else
	BRC(LINE_CNT(5), DOWN, AL),                                                    	//      ; Always              																			-> JP02
#endif
	SUBS(REGA1, CH1FLT, REGB2),														// JP01 ; REGB2 = thisInfo->tCoord.iInternalXRes - tOrgPastPos[0].tXY.x
	CMPS(REGB2, REGA7),																//		; cmps(REGB2, (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH))
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(6), DOWN, GES),                                                   	//      ; REGB2 >= (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH)										-> JP02
#else
	BRC(LINE_CNT(2), DOWN, GES),                                                   	//      ; REGB2 >= (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH)										-> JP02
#endif
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    SRW3(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH3FLT READ : tFirstPos.tXY.x
    SUBS(REGA1, CH3FLT, REGB2),														//      ; REGB2 = thisInfo->tCoord.iInternalXRes - tFirstPos.tXY.x
    CMPS(REGB2, REGC5),															    //		; cmps(REGB2, (1<<POS_BOOST_SHIFT_))
	BRC(LINE_CNT(2), DOWN, LES),                                                   	//      ; REGB2 <= (1<<POS_BOOST_SHIFT_)                   	                                            -> JP02
#endif
	MOV(CONST_VAL(2), REGB0),                                                       //      ; REGB0 = 2 ; x_edge_f
	CMPS(CH2FLT, REGA7),															// JP02 ; cmps(tOrgPastPos[0].tXY.y, (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH))
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(6), DOWN, GES),                                                   	//      ; tOrgPastPos[0].tXY.y >= (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH)                  		-> JP03
#else
	BRC(LINE_CNT(3), DOWN, GES),                                                   	//      ; tOrgPastPos[0].tXY.y >= (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH)                  		-> JP03
#endif
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    SRW3(CONST_VAL(7), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH3FLT READ : tFirstPos.tXY.y
    CMPS(CH3FLT, REGC5),															//		; cmps(tFirstPos.tXY.y, (1<<POS_BOOST_SHIFT_))
	BRC(LINE_CNT(3), DOWN, LES),                                                   	//      ; tFirstPos.tXY.y <= (1<<POS_BOOST_SHIFT_)                   	                                -> JP03
#endif
	MOV(CONST_VAL(1), REGB1),                                                       //      ; REGB1 = 1 ; y_edge_f
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(9), DOWN, AL),                                                    	//      ; Always              																			-> JP04
#else
	BRC(LINE_CNT(5), DOWN, AL),                                                    	//      ; Always              																			-> JP04
#endif
	SUBS(REGA2, CH2FLT, REGB2),														// JP03 ; REGB2 = thisInfo->tCoord.iInternalYRes - tOrgPastPos[0].tXY.y
	CMPS(REGB2, REGA7),																//		; cmps(REGB2, (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH))
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    BRC(LINE_CNT(6), DOWN, GES),                                                   	//      ; REGB2 >= (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH)										-> JP04
#else
	BRC(LINE_CNT(2), DOWN, GES),                                                   	//      ; REGB2 >= (1<<thisModeConf->Coord.ucPenPostProcessEdgeTH)										-> JP04
#endif
#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
    SRW3(CONST_VAL(7), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),    //      ; CH3FLT READ : tFirstPos.tXY.y
    SUBS(REGA2, CH3FLT, REGB2),														//      ; REGB2 = thisInfo->tCoord.iInternalYRes - tFirstPos.tXY.y
    CMPS(REGB2, REGC5),															    //		; cmps(REGB2, (1<<POS_BOOST_SHIFT_))
	BRC(LINE_CNT(2), DOWN, LES),                                                   	//      ; REGB2 <= (1<<POS_BOOST_SHIFT_)                   	                                            -> JP04
#endif
	MOV(CONST_VAL(2), REGB1),                                                       //      ; REGB1 = 2 ; y_edge_f
	
	CMPS(REGB0, CONST_VAL(0)),                                                      // JP04 ; cmps(x_edge_f, 0)
	BRC(LINE_CNT(4), DOWN, GTS),                                                    //      ; x_edge_f > 0                   																-> JP05
	CMPS(REGB1, CONST_VAL(0)),                                                      //		; cmps(y_edge_f, 0)
	BRC(LINE_CNT(2), DOWN, GTS),                                                    //      ; y_edge_f > 0                   																-> JP05
	BRC(LINE_CNT(286), DOWN, AL),                                                   //      ; Always              																			-> JP00
	SRW0(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP05 ; CH0FLT READ : tPastPos[0].tXY.x
	SRW1(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPos[0].tXY.y
	SRW2(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tPastPos[1].tXY.x
	SRW3(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH3FLT READ : tPastPos[1].tXY.y
	SUBS(CH0FLT00, CH2FLT, REGB2),													// 		; REGB2 = tPastPos[0].tXY.x - tPastPos[1].tXY.x ; dist_x[0]
	SUBS(CH1FLT, CH3FLT, REGB3),													// 		; REGB3 = tPastPos[0].tXY.y - tPastPos[1].tXY.y ; dist_y[0]
	SRW2(CONST_VAL(32), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tPastPos2.tXY.x
	SRW3(CONST_VAL(33), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH3FLT READ : tPastPos2.tXY.y
	SUBS(CH0FLT00, CH2FLT, REGB4),													// 		; REGB4 = tPastPos[0].tXY.x - tPastPos2.tXY.x ; dist_x[1]
	SUBS(CH1FLT, CH3FLT, REGB5),													// 		; REGB5 = tPastPos[0].tXY.y - tPastPos2.tXY.y ; dist_y[1]
	SRW0(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // 		; CH0FLT READ : tPastPos[1].tXY.x
	SRW1(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPos[1].tXY.y
	SUBS(CH0FLT00, CH2FLT, REGB6),													// 		; REGB6 = tPastPos[1].tXY.x - tPastPos2.tXY.x ; dist_x[2]
	SUBS(CH1FLT, CH3FLT, REGB7),													// 		; REGB7 = tPastPos[1].tXY.y - tPastPos2.tXY.y ; dist_y[2]
	
	CMPS(REGB0, CONST_VAL(1)),                                                      //		; cmps(x_edge_f, 1)
	BRC(LINE_CNT(8), DOWN, NE),                                                     //      ; x_edge_f != 1                   																-> JP06
	CMPS(REGB2, REGA4),                                                     		//		; cmps(dist_x[0], -thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(6), DOWN, GES),                                                    //      ; dist_x[0] >= -thisModeConf->Coord.ucPenPostProcessDisTH)       								-> JP06
	CMPS(REGB4, REGA4),                                                     		//		; cmps(dist_x[1], -thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(4), DOWN, GES),                                                    //      ; dist_x[1] >= -thisModeConf->Coord.ucPenPostProcessDisTH)										-> JP06
	CMPS(REGB6, REGA4),                                                     		//		; cmps(dist_x[2], -thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_x[2] >= -thisModeConf->Coord.ucPenPostProcessDisTH)										-> JP06
	BRC(LINE_CNT(27), DOWN, AL),                                                    //      ; Always              																			-> JP07	
	CMPS(REGB0, CONST_VAL(2)),                                                      // JP06 ; cmps(x_edge_f, 2)
	BRC(LINE_CNT(8), DOWN, NE),                                                     //      ; x_edge_f != 2                   																-> JP08
	CMPS(REGB2, REGA3),                                                     		//		; cmps(dist_x[0], thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(6), DOWN, LES),                                                    //      ; dist_x[0] <= thisModeConf->Coord.ucPenPostProcessDisTH)       								-> JP08
	CMPS(REGB4, REGA3),                                                     		//		; cmps(dist_x[1], thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(4), DOWN, LES),                                                    //      ; dist_x[1] <= thisModeConf->Coord.ucPenPostProcessDisTH)										-> JP08
	CMPS(REGB6, REGA3),                                                     		//		; cmps(dist_x[2], thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; dist_x[2] <= thisModeConf->Coord.ucPenPostProcessDisTH)										-> JP08
	BRC(LINE_CNT(18), DOWN, AL),                                                    //      ; Always              																			-> JP07	
	CMPS(REGB1, CONST_VAL(1)),                                                      // JP08 ; cmps(y_edge_f, 1)
	BRC(LINE_CNT(8), DOWN, NE),                                                     //      ; y_edge_f != 1                   																-> JP09
	CMPS(REGB3, REGA4),                                                     		//		; cmps(dist_y[0], -thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(6), DOWN, GES),                                                    //      ; dist_y[0] >= -thisModeConf->Coord.ucPenPostProcessDisTH)       								-> JP09
	CMPS(REGB5, REGA4),                                                     		//		; cmps(dist_y[1], -thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(4), DOWN, GES),                                                    //      ; dist_y[1] >= -thisModeConf->Coord.ucPenPostProcessDisTH)										-> JP09
	CMPS(REGB7, REGA4),                                                     		//		; cmps(dist_y[2], -thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_y[2] >= -thisModeConf->Coord.ucPenPostProcessDisTH)										-> JP09
	BRC(LINE_CNT(9), DOWN, AL),                                                    	//      ; Always              																			-> JP07	
	CMPS(REGB1, CONST_VAL(2)),                                                      // JP09 ; cmps(y_edge_f, 2)
	BRC(LINE_CNT(243), DOWN, NE),                                                   //      ; y_edge_f != 2                   																-> JP00
	CMPS(REGB3, REGA3),                                                     		//		; cmps(dist_y[0], thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(241), DOWN, LES),                                                  //      ; dist_y[0] <= thisModeConf->Coord.ucPenPostProcessDisTH)       								-> JP00
	CMPS(REGB5, REGA3),                                                     		//		; cmps(dist_y[1], thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(239), DOWN, LES),                                                  //      ; dist_y[1] <= thisModeConf->Coord.ucPenPostProcessDisTH)										-> JP00
	CMPS(REGB7, REGA3),                                                     		//		; cmps(dist_y[2], thisModeConf->Coord.ucPenPostProcessDisTH)
	BRC(LINE_CNT(237), DOWN, LES),                                                  //      ; dist_y[2] <= thisModeConf->Coord.ucPenPostProcessDisTH)										-> JP00
	
	SRW0(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP07 ; CH0FLT READ : tOrgPastPos[0].tXY.x
	SRW1(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.y
	DIVS(REGB2, REGA5, REGC0),														// 		; REGC0 = dist_x[0] / thisModeConf->Coord.ucPenPostProcessExpendDiv ; tPos.tXY.x
	ADDS(CH0FLT00, REGC0, REGC0),													// 		; REGC0 = tOrgPastPos[0].tXY.x + dist_x[0] / thisModeConf->Coord.ucPenPostProcessExpendDiv
	DIVS(REGB3, REGA5, REGC1),														// 		; REGC1 = dist_y[0] / thisModeConf->Coord.ucPenPostProcessExpendDiv ; tPos.tXY.y
	ADDS(CH1FLT, REGC1, REGC1),														// 		; REGC1 = tOrgPastPos[0].tXY.y + dist_y[0] / thisModeConf->Coord.ucPenPostProcessExpendDiv
	
	
	SUBS(CONST_VAL(0), CONST_VAL(1), REGA4),                                        // 		; REGA4 = 0 - 1, A4 : -1
	MOV(CONST_VAL(0), REGA7),                                                       //      ; REGA7 = 0 ; max_idx
	CMPS(REGB0, CONST_VAL(1)),                                                      //		; cmps(x_edge_f, 1)
	BRC(LINE_CNT(4), DOWN, NE),                                                     //      ; x_edge_f != 1                   																-> JP10
	CMPS(REGC0, REGA6),                                                     		//		; cmps(tPos.tXY.x, -thisModeConf->Coord.cPenPostProcessEndMargin)
	BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; tPos.tXY.x <= -thisModeConf->Coord.cPenPostProcessEndMargin)       							-> JP10
	BRC(LINE_CNT(7), DOWN, AL),                                                    	//      ; Always              																			-> JP11
	
	SUBS(REGA1, REGA6, REGA5),														// JP10 ; REGA5 = thisInfo->tCoord.iInternalXRes - (-thisModeConf->Coord.cPenPostProcessEndMargin)
	CMPS(REGB0, CONST_VAL(2)),                                                      //		; cmps(x_edge_f, 2)
	BRC(LINE_CNT(103), DOWN, NE),                                                   //      ; x_edge_f != 2                   																-> JP12
	CMPS(REGC0, REGA5),                                                     		//		; cmps(tPos.tXY.x, thisInfo->tCoord.iInternalXRes + thisModeConf->Coord.cPenPostProcessEndMargin)
	BRC(LINE_CNT(101), DOWN, GES),                                                  //      ; tPos.tXY.x >= thisInfo->tCoord.iInternalXRes + thisModeConf->Coord.cPenPostProcessEndMargin)  -> JP12
	BRC(LINE_CNT(51), DOWN, AL),                                                    //      ; Always              																			-> JP13
	
	//JP11
	CMPS(REGB2, REGB4),                                                      		// JP11 ; cmps(dist_x[0], dist_x[1])
	BRC(LINE_CNT(3), DOWN, GTS),                                                    //      ; dist_x[0] > dist_x[1]                  														-> JP18
	MOV(REGB2, REGA5),                                                     			//      ; REGA5 = dist_x[0] ; MIN(dist_x)
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always				                  														-> JP19
	MOV(REGB4, REGA5),                                                     			// JP18 ; REGA5 = dist_x[1] ; MIN(dist_x)
	CMPS(REGA5, REGB6),                                                      		// JP19 ; cmps(MIN(dist_x), dist_x[2])
	BRC(LINE_CNT(2), DOWN, GTS),                                                    //      ; MIN(dist_x) > dist_x[2]                  														-> JP20
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always				                  														-> JP21
	MOV(REGB6, REGA5),                                                     			// JP20 ; REGA5 = dist_x[2] ; MIN(dist_x)
	ADDS(CH0FLT00, REGA5, REGC0),													// JP21	; REGC0 = tOrgPastPos[0].tXY.x + MIN(dist_x) ; tPos.tXY.x
	
	CMPS(REGB3, CONST_VAL(0)),                                                      //		; cmps(dist_y[0], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_y[0] >= 0                  																-> JP22
	MULS(REGB3, REGA4, REGC2),														// 		; REGC2 = dist_y[0] * -1 ; ABS(dist_y[0])
	CMPS(REGB5, CONST_VAL(0)),                                                      // JP22 ; cmps(dist_y[1], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_y[1] >= 0                  																-> JP23
	MULS(REGB5, REGA4, REGC3),														// 		; REGC3 = dist_y[1] * -1 ; ABS(dist_y[1])
	CMPS(REGB7, CONST_VAL(0)),                                                      // JP23 ; cmps(dist_y[2], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_y[2] >= 0                  																-> JP24
	MULS(REGB7, REGA4, REGC4),														// 		; REGC4 = dist_y[2] * -1 ; ABS(dist_y[2])
	
	CMPS(REGC2, REGC3),                                                     		// JP24 ; cmps(ABS(dist_y[0]), ABS(dist_y[1]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_y[0]) < ABS(dist_y[1])                  												-> JP25
	CMPS(REGC2, REGC4),                                                     		//		; cmps(ABS(dist_y[0]), ABS(dist_y[2]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_y[0]) < ABS(dist_y[2])                  												-> JP25
	MOV(CONST_VAL(0), REGA7),                                                       //      ; REGA7 = 0 ; max_idx
	BRC(LINE_CNT(13), DOWN, AL),                                                    //      ; Always				                  														-> JP27
	CMPS(REGC3, REGC2),                                                     		// JP25 ; cmps(ABS(dist_y[1]), ABS(dist_y[0]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_y[1]) < ABS(dist_y[0])                  												-> JP26
	CMPS(REGC3, REGC4),                                                     		//		; cmps(ABS(dist_y[1]), ABS(dist_y[2]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_y[1]) < ABS(dist_y[2])                  												-> JP26
	MOV(CONST_VAL(1), REGA7),                                                       //      ; REGA7 = 1 ; max_idx
	BRC(LINE_CNT(7), DOWN, AL),                                                     //      ; Always				                  														-> JP27
	CMPS(REGC4, REGC2),                                                     		// JP26 ; cmps(ABS(dist_y[2]), ABS(dist_y[0]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_y[2]) < ABS(dist_y[0])                  												-> JP27
	CMPS(REGC4, REGC3),                                                     		//		; cmps(ABS(dist_y[2]), ABS(dist_y[1]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_y[2]) < ABS(dist_y[1])                  												-> JP27
	MOV(CONST_VAL(2), REGA7),                                                       //      ; REGA7 = 2 ; max_idx
	
	MOV(REGB3, REGA5),                                                     			// 		; REGA5 = dist_y[0] ; dist_y[max_idx]
	CMPS(REGA7, CONST_VAL(0)),                                                 		// JP27 ; cmps(max_idx, 0))
	BRC(LINE_CNT(3), DOWN, NE),                                                     //      ; max_idx != 0                  																-> JP28
	MOV(REGB3, REGA5),                                                     			// 		; REGA5 = dist_y[0] ; dist_y[max_idx]
	BRC(LINE_CNT(8), DOWN, AL),                                                     //      ; Always				                  														-> JP29
	CMPS(REGA7, CONST_VAL(1)),                                                 		// JP28 ; cmps(max_idx, 1))
	BRC(LINE_CNT(3), DOWN, NE),                                                     //      ; max_idx != 1                  																-> JP30
	MOV(REGB5, REGA5),                                                     			// 		; REGA5 = dist_y[1] ; dist_y[max_idx]
	BRC(LINE_CNT(4), DOWN, AL),                                                     //      ; Always				                  														-> JP29
	CMPS(REGA7, CONST_VAL(2)),                                                 		// JP30 ; cmps(max_idx, 2))
	BRC(LINE_CNT(2), DOWN, NE),                                                     //      ; max_idx != 2                  																-> JP29
	MOV(REGB7, REGA5),                                                     			// 		; REGA5 = dist_y[2] ; dist_y[max_idx]
	ADDS(CH1FLT, REGA5, REGC1),														// JP29 ; REGC1 = tOrgPastPos[0].tXY.y + dist_y[max_idx] ; tPos.tXY.y
	BRC(LINE_CNT(50), DOWN, AL),                                                    //      ; Always				                  														-> JP12
	
	//JP13
	CMPS(REGB2, REGB4),                                                      		// JP13 ; cmps(dist_x[0], dist_x[1])
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; dist_x[0] < dist_x[1]                  														-> JP31
	MOV(REGB2, REGA5),                                                     			//      ; REGA5 = dist_x[0] ; MAX(dist_x)
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always				                  														-> JP32
	MOV(REGB4, REGA5),                                                     			// JP31 ; REGA5 = dist_x[1] ; MAX(dist_x)
	CMPS(REGA5, REGB6),                                                      		// JP32 ; cmps(MAX(dist_x), dist_x[2])
	BRC(LINE_CNT(2), DOWN, LTS),                                                    //      ; MAX(dist_x) < dist_x[2]                  														-> JP33
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always				                  														-> JP34
	MOV(REGB6, REGA5),                                                     			// JP33 ; REGA5 = dist_x[2] ; MAX(dist_x)
	ADDS(CH0FLT00, REGA5, REGC0),													// JP34	; REGC0 = tOrgPastPos[0].tXY.x + MAX(dist_x) ; tPos.tXY.x
	
	CMPS(REGB3, CONST_VAL(0)),                                                      //		; cmps(dist_y[0], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_y[0] >= 0                  																-> JP35
	MULS(REGB3, REGA4, REGC2),														// 		; REGC2 = dist_y[0] * -1 ; ABS(dist_y[0])
	CMPS(REGB5, CONST_VAL(0)),                                                      // JP35 ; cmps(dist_y[1], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_y[1] >= 0                  																-> JP36
	MULS(REGB5, REGA4, REGC3),														// 		; REGC3 = dist_y[1] * -1 ; ABS(dist_y[1])
	CMPS(REGB7, CONST_VAL(0)),                                                      // JP36 ; cmps(dist_y[2], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_y[2] >= 0                  																-> JP37
	MULS(REGB7, REGA4, REGC4),														// 		; REGC4 = dist_y[2] * -1 ; ABS(dist_y[2])
	
	CMPS(REGC2, REGC3),                                                     		// JP37 ; cmps(ABS(dist_y[0]), ABS(dist_y[1]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_y[0]) < ABS(dist_y[1])                  												-> JP38
	CMPS(REGC2, REGC4),                                                     		//		; cmps(ABS(dist_y[0]), ABS(dist_y[2]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_y[0]) < ABS(dist_y[2])                  												-> JP38
	MOV(CONST_VAL(0), REGA7),                                                       //      ; REGA7 = 0 ; max_idx
	BRC(LINE_CNT(13), DOWN, AL),                                                    //      ; Always				                  														-> JP40
	CMPS(REGC3, REGC2),                                                     		// JP38 ; cmps(ABS(dist_y[1]), ABS(dist_y[0]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_y[1]) < ABS(dist_y[0])                  												-> JP39
	CMPS(REGC3, REGC4),                                                     		//		; cmps(ABS(dist_y[1]), ABS(dist_y[2]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_y[1]) < ABS(dist_y[2])                  												-> JP39
	MOV(CONST_VAL(1), REGA7),                                                       //      ; REGA7 = 1 ; max_idx
	BRC(LINE_CNT(7), DOWN, AL),                                                     //      ; Always				                  														-> JP40
	CMPS(REGC4, REGC2),                                                     		// JP39 ; cmps(ABS(dist_y[2]), ABS(dist_y[0]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_y[2]) < ABS(dist_y[0])                  												-> JP40
	CMPS(REGC4, REGC3),                                                     		//		; cmps(ABS(dist_y[2]), ABS(dist_y[1]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_y[2]) < ABS(dist_y[1])                  												-> JP40
	MOV(CONST_VAL(2), REGA7),                                                       //      ; REGA7 = 2 ; max_idx
	
	MOV(REGB3, REGA5),                                                     			// 		; REGA5 = dist_y[0] ; dist_y[max_idx]
	CMPS(REGA7, CONST_VAL(0)),                                                 		// JP40 ; cmps(max_idx, 0))
	BRC(LINE_CNT(3), DOWN, NE),                                                     //      ; max_idx != 0                  																-> JP41
	MOV(REGB3, REGA5),                                                     			// 		; REGA5 = dist_y[0] ; dist_y[max_idx]
	BRC(LINE_CNT(8), DOWN, AL),                                                     //      ; Always				                  														-> JP42
	CMPS(REGA7, CONST_VAL(1)),                                                 		// JP41 ; cmps(max_idx, 1))
	BRC(LINE_CNT(3), DOWN, NE),                                                     //      ; max_idx != 1                  																-> JP43
	MOV(REGB5, REGA5),                                                     			// 		; REGA5 = dist_y[1] ; dist_y[max_idx]
	BRC(LINE_CNT(4), DOWN, AL),                                                     //      ; Always				                  														-> JP42
	CMPS(REGA7, CONST_VAL(2)),                                                 		// JP43; cmps(max_idx, 2))
	BRC(LINE_CNT(2), DOWN, NE),                                                     //      ; max_idx != 2                  																-> JP42
	MOV(REGB7, REGA5),                                                     			// 		; REGA5 = dist_y[2] ; dist_y[max_idx]
	ADDS(CH1FLT, REGA5, REGC1),														// JP42 ; REGC1 = tOrgPastPos[0].tXY.y + dist_y[max_idx] ; tPos.tXY.y
	
	//JP12
	MOV(CONST_VAL(0), REGA7),                                                       // JP12 ; REGA7 = 0 ; max_idx	
	CMPS(REGB1, CONST_VAL(1)),                                                      //		; cmps(y_edge_f, 1)
	BRC(LINE_CNT(4), DOWN, NE),                                                     //      ; y_edge_f != 1                   																-> JP14
	CMPS(REGC1, REGA6),                                                     		//		; cmps(tPos.tXY.y, -thisModeConf->Coord.cPenPostProcessEndMargin)
	BRC(LINE_CNT(2), DOWN, LES),                                                    //      ; tPos.tXY.y <= -thisModeConf->Coord.cPenPostProcessEndMargin)       							-> JP14
	BRC(LINE_CNT(7), DOWN, AL),                                                    	//      ; Always              																			-> JP15
	
	SUBS(REGA2, REGA6, REGA5),														// JP14 ; REGA5 = thisInfo->tCoord.iInternalYRes - (-thisModeConf->Coord.cPenPostProcessEndMargin)
	CMPS(REGB1, CONST_VAL(2)),                                                      //		; cmps(y_edge_f, 2)
	BRC(LINE_CNT(103), DOWN, NE),                                                   //      ; y_edge_f != 2                   																-> JP16
	CMPS(REGC1, REGA5),                                                     		//		; cmps(tPos.tXY.y, thisInfo->tCoord.iInternalYRes + thisModeConf->Coord.cPenPostProcessEndMargin)
	BRC(LINE_CNT(101), DOWN, GES),                                                  //      ; tPos.tXY.y >= thisInfo->tCoord.iInternalYRes + thisModeConf->Coord.cPenPostProcessEndMargin)  -> JP16
	BRC(LINE_CNT(51), DOWN, AL),                                                    //      ; Always              																			-> JP17
	
	//JP15
	CMPS(REGB3, REGB5),                                                      		// JP15 ; cmps(dist_y[0], dist_y[1])
	BRC(LINE_CNT(3), DOWN, GTS),                                                    //      ; dist_y[0] > dist_y[1]                  														-> JP43
	MOV(REGB3, REGA5),                                                     			//      ; REGA5 = dist_y[0] ; MIN(dist_y)
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always				                  														-> JP44
	MOV(REGB5, REGA5),                                                     			// JP43 ; REGA5 = dist_y[1] ; MIN(dist_y)
	CMPS(REGA5, REGB7),                                                      		// JP44 ; cmps(MIN(dist_y), dist_y[2])
	BRC(LINE_CNT(2), DOWN, GTS),                                                    //      ; MIN(dist_y) > dist_y[2]                  														-> JP45
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always				                  														-> JP46
	MOV(REGB7, REGA5),                                                     			// JP45 ; REGA5 = dist_y[2] ; MIN(dist_y)
	ADDS(CH1FLT, REGA5, REGC1),														// JP46	; REGC1 = tOrgPastPos[0].tXY.y + MIN(dist_y) ; tPos.tXY.y
	
	CMPS(REGB2, CONST_VAL(0)),                                                      //		; cmps(dist_x[0], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_x[0] >= 0                  																-> JP47
	MULS(REGB2, REGA4, REGC2),														// 		; REGC2 = dist_x[0] * -1 ; ABS(dist_x[0])
	CMPS(REGB4, CONST_VAL(0)),                                                      // JP47 ; cmps(dist_x[1], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_x[1] >= 0                  																-> JP48
	MULS(REGB4, REGA4, REGC3),														// 		; REGC3 = dist_x[1] * -1 ; ABS(dist_x[1])
	CMPS(REGB6, CONST_VAL(0)),                                                      // JP48 ; cmps(dist_x[2], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_x[2] >= 0                  																-> JP49
	MULS(REGB6, REGA4, REGC4),														// 		; REGC4 = dist_x[2] * -1 ; ABS(dist_x[2])
	
	CMPS(REGC2, REGC3),                                                     		// JP49 ; cmps(ABS(dist_x[0]), ABS(dist_x[1]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_x[0]) < ABS(dist_x[1])                  												-> JP50
	CMPS(REGC2, REGC4),                                                     		//		; cmps(ABS(dist_x[0]), ABS(dist_x[2]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_x[0]) < ABS(dist_x[2])                  												-> JP50
	MOV(CONST_VAL(0), REGA7),                                                       //      ; REGA7 = 0 ; max_idx
	BRC(LINE_CNT(13), DOWN, AL),                                                    //      ; Always				                  														-> JP52
	CMPS(REGC3, REGC2),                                                     		// JP50 ; cmps(ABS(dist_x[1]), ABS(dist_x[0]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_x[1]) < ABS(dist_x[0])                  												-> JP51
	CMPS(REGC3, REGC4),                                                     		//		; cmps(ABS(dist_x[1]), ABS(dist_x[2]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_x[1]) < ABS(dist_x[2])                  												-> JP51
	MOV(CONST_VAL(1), REGA7),                                                       //      ; REGA7 = 1 ; max_idx
	BRC(LINE_CNT(7), DOWN, AL),                                                     //      ; Always				                  														-> JP52
	CMPS(REGC4, REGC2),                                                     		// JP51 ; cmps(ABS(dist_x[2]), ABS(dist_x[0]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_x[2]) < ABS(dist_x[0])                  												-> JP52
	CMPS(REGC4, REGC3),                                                     		//		; cmps(ABS(dist_x[2]), ABS(dist_x[1]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_x[2]) < ABS(dist_x[1])                  												-> JP52
	MOV(CONST_VAL(2), REGA7),                                                       //      ; REGA7 = 2 ; max_idx
	
	MOV(REGB2, REGA5),                                                     			// 		; REGA5 = dist_x[0] ; dist_x[max_idx]
	CMPS(REGA7, CONST_VAL(0)),                                                 		// JP52 ; cmps(max_idx, 0))
	BRC(LINE_CNT(3), DOWN, NE),                                                     //      ; max_idx != 0                  																-> JP53
	MOV(REGB2, REGA5),                                                     			// 		; REGA5 = dist_x[0] ; dist_x[max_idx]
	BRC(LINE_CNT(8), DOWN, AL),                                                     //      ; Always				                  														-> JP54
	CMPS(REGA7, CONST_VAL(1)),                                                 		// JP53 ; cmps(max_idx, 1))
	BRC(LINE_CNT(3), DOWN, NE),                                                     //      ; max_idx != 1                  																-> JP55
	MOV(REGB4, REGA5),                                                     			// 		; REGA5 = dist_x[1] ; dist_x[max_idx]
	BRC(LINE_CNT(4), DOWN, AL),                                                     //      ; Always				                  														-> JP54
	CMPS(REGA7, CONST_VAL(2)),                                                 		// JP55 ; cmps(max_idx, 2))
	BRC(LINE_CNT(2), DOWN, NE),                                                     //      ; max_idx != 2                  																-> JP54
	MOV(REGB6, REGA5),                                                     			// 		; REGA5 = dist_x[2] ; dist_x[max_idx]
	ADDS(CH0FLT00, REGA5, REGC0),													// JP54 ; REGC0 = tOrgPastPos[0].tXY.x + dist_x[max_idx] ; tPos.tXY.x
	BRC(LINE_CNT(50), DOWN, AL),                                                    //      ; Always				                  														-> JP16
	
	//JP17
	CMPS(REGB3, REGB5),                                                      		// JP17 ; cmps(dist_y[0], dist_y[1])
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; dist_y[0] < dist_y[1]                  														-> JP56
	MOV(REGB3, REGA5),                                                     			//      ; REGA5 = dist_y[0] ; MAX(dist_y)
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always				                  														-> JP57
	MOV(REGB5, REGA5),                                                     			// JP56 ; REGA5 = dist_y[1] ; MAX(dist_y)
	CMPS(REGA5, REGB7),                                                      		// JP57 ; cmps(MAX(dist_y), dist_y[2])
	BRC(LINE_CNT(2), DOWN, LTS),                                                    //      ; MAX(dist_y) < dist_y[2]                  														-> JP58
	BRC(LINE_CNT(2), DOWN, AL),                                                     //      ; Always				                  														-> JP59
	MOV(REGB7, REGA5),                                                     			// JP58 ; REGA5 = dist_y[2] ; MAX(dist_y)
	ADDS(CH1FLT, REGA5, REGC1),														// JP59	; REGC1 = tOrgPastPos[0].tXY.y + MIN(dist_y) ; tPos.tXY.y
	
	CMPS(REGB2, CONST_VAL(0)),                                                      //		; cmps(dist_x[0], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_x[0] >= 0                  																-> JP60
	MULS(REGB2, REGA4, REGC2),														// 		; REGC2 = dist_x[0] * -1 ; ABS(dist_x[0])
	CMPS(REGB4, CONST_VAL(0)),                                                      // JP60 ; cmps(dist_x[1], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_x[1] >= 0                  																-> JP61
	MULS(REGB4, REGA4, REGC3),														// 		; REGC3 = dist_x[1] * -1 ; ABS(dist_x[1])
	CMPS(REGB6, CONST_VAL(0)),                                                      // JP61 ; cmps(dist_x[2], 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                    //      ; dist_x[2] >= 0                  																-> JP62
	MULS(REGB6, REGA4, REGC4),														// 		; REGC4 = dist_x[2] * -1 ; ABS(dist_x[2])
	
	CMPS(REGC2, REGC3),                                                     		// JP62 ; cmps(ABS(dist_x[0]), ABS(dist_x[1]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_x[0]) < ABS(dist_x[1])                  												-> JP63
	CMPS(REGC2, REGC4),                                                     		//		; cmps(ABS(dist_x[0]), ABS(dist_x[2]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_x[0]) < ABS(dist_x[2])                  												-> JP63
	MOV(CONST_VAL(0), REGA7),                                                       //      ; REGA7 = 0 ; max_idx
	BRC(LINE_CNT(13), DOWN, AL),                                                    //      ; Always				                  														-> JP65
	CMPS(REGC3, REGC2),                                                     		// JP63 ; cmps(ABS(dist_x[1]), ABS(dist_x[0]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_x[1]) < ABS(dist_x[0])                  												-> JP64
	CMPS(REGC3, REGC4),                                                     		//		; cmps(ABS(dist_x[1]), ABS(dist_x[2]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_x[1]) < ABS(dist_x[2])                  												-> JP64
	MOV(CONST_VAL(1), REGA7),                                                       //      ; REGA7 = 1 ; max_idx
	BRC(LINE_CNT(7), DOWN, AL),                                                     //      ; Always				                  														-> JP65
	CMPS(REGC4, REGC2),                                                     		// JP64 ; cmps(ABS(dist_x[2]), ABS(dist_x[0]))
	BRC(LINE_CNT(5), DOWN, LTS),                                                    //      ; ABS(dist_x[2]) < ABS(dist_x[0])                  												-> JP65
	CMPS(REGC4, REGC3),                                                     		//		; cmps(ABS(dist_x[2]), ABS(dist_x[1]))
	BRC(LINE_CNT(3), DOWN, LTS),                                                    //      ; ABS(dist_x[2]) < ABS(dist_x[1])                  												-> JP65
	MOV(CONST_VAL(2), REGA7),                                                       //      ; REGA7 = 2 ; max_idx
	
	MOV(REGB2, REGA5),                                                     			// 		; REGA5 = dist_x[0] ; dist_x[max_idx]
	CMPS(REGA7, CONST_VAL(0)),                                                 		// JP65 ; cmps(max_idx, 0))
	BRC(LINE_CNT(3), DOWN, NE),                                                     //      ; max_idx != 0                  																-> JP66
	MOV(REGB2, REGA5),                                                     			// 		; REGA5 = dist_x[0] ; dist_x[max_idx]
	BRC(LINE_CNT(8), DOWN, AL),                                                     //      ; Always				                  														-> JP67
	CMPS(REGA7, CONST_VAL(1)),                                                 		// JP66 ; cmps(max_idx, 1))
	BRC(LINE_CNT(3), DOWN, NE),                                                     //      ; max_idx != 1                  																-> JP68
	MOV(REGB4, REGA5),                                                     			// 		; REGA5 = dist_x[1] ; dist_x[max_idx]
	BRC(LINE_CNT(4), DOWN, AL),                                                     //      ; Always				                  														-> JP67
	CMPS(REGA7, CONST_VAL(2)),                                                 		// JP68 ; cmps(max_idx, 2))
	BRC(LINE_CNT(2), DOWN, NE),                                                     //      ; max_idx != 2                  																-> JP67
	MOV(REGB6, REGA5),                                                     			// 		; REGA5 = dist_x[2] ; dist_x[max_idx]
	ADDS(CH0FLT00, REGA5, REGC0),													// JP67 ; REGC0 = tOrgPastPos[0].tXY.x + dist_x[max_idx] ; tPos.tXY.x
	
	//JP16
	SRW0(CONST_VAL(0), REGC0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          // JP16 ; CH0FLT WRITE : tPos.tXY.x = REGC0
	SRW1(CONST_VAL(1), REGC1, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),          //      ; CH1FLT WRITE : tPos.tXY.y = REGC1
//	SRW2(CONST_VAL(16), REGC0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH2FLT WRITE : tOrgPos.tXY.x = REGC0
//	SRW3(CONST_VAL(17), REGC1, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),         //      ; CH3FLT WRITE : tOrgPos.tXY.y = REGC1
	SRW0(CONST_VAL(48), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH0FLT READ : tOrgPastPos[0].vusS
	SRW1(CONST_VAL(49), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tOrgPastPos[0].vusR
	SRW2(CONST_VAL(4), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),     //      ; CH2FLT WRITE : tPos.vusS = tOrgPastPos[0].vusS
	SRW3(CONST_VAL(5), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),       //      ; CH3FLT WRITE : tPos.vusR = tOrgPastPos[0].vusR
//	SRW2(CONST_VAL(36), CH0FLT00, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),    //      ; CH2FLT WRITE : tOrgPos.vusS = tOrgPastPos[0].vusS
//	SRW3(CONST_VAL(37), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),      //      ; CH3FLT WRITE : tOrgPos.vusR = tOrgPastPos[0].vusR	
	SRW1(CONST_VAL(8), CONST_VAL(1), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT WRITE : tAvgPos.x = 1

	END()                                                                           // JP00 ; 0x37000000
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

/********************************************************************************
  @brief    Label Edge Expand OPCODE
  */
#ifdef SRAM_OPCODE
int opcode_labeledgeexpand_deltabase[] = 
#else
int opcode_labeledgeexpand_deltabase[] = 
#endif
{
	// input A0~B6, loop_cnt C0~C1, interrupt A4~A6, B6
    SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : Delta
    SDMA1(REGA1, 0, DMA_SIZE2),                                                     //      ; A1 : Label map
    SDMA2(REGA2, 0, DMA_SIZE1),                                                     //      ; A2 : label info
    SDMA3(REGA3, 0, DMA_SIZE2),                                                     //      ; A3 : EdgePen

//	SRW3(CONST_VAL(30), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),
//	MOV(CH3FLT, REGB5),
//	MOV(CONST_VAL(11),REGB6),
//	SRW3(CONST_VAL(2), REGB6, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_8BIT),			//      ; CH2FLT WRITE : tCoord.x	
//	SRW3(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),		// 		; CH3FLT READ : max_sum					//TEST_CODE
//	MOV(CH3FLT, REGB7),
//	BRC(LINE_CNT(123), DOWN, AL),
	
	CMPS(REGA7, CONST_VAL(0)),														//		; cmps(RunTMH, 0)
#if (CUSTOMER == MODEL_DEF_QHD_92407_FLIP && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
	BRC(LINE_CNT(275), DOWN, EQ),													//		; RunTMH == 0			LINE_CNT(1+118+2+118)									-> JP00
#else
	BRC(LINE_CNT(249), DOWN, EQ),													//		; RunTMH == 0			LINE_CNT(1+118+2+118)									-> JP00
#endif
	
	// up,down edge
	CMPS(REGB3, CONST_VAL(0)),                                                     	// 		; cmps(search_r, 0)
#if (CUSTOMER == MODEL_DEF_QHD_92407_FLIP && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
    BRC(LINE_CNT(135), DOWN, LTS),                                                  //      ; search_r < 0     		LINE_CNT(14+104) LINE_CNT(118)							-> JP21
#else
    BRC(LINE_CNT(122), DOWN, LTS),                                                  //      ; search_r < 0     		LINE_CNT(14+104) LINE_CNT(118)							-> JP21
#endif
	MOV(CONST_VAL(0), REGB1),                                        				//      ; REGB1 = 0 ; EdgeStrength
	SLLS(REGA5, CONST_VAL(2), REGB0),												//		; REGB0 = (Ring_ExtStrength<<2)
	DIVS(REGB0, REGC7, REGB0),														//		; REGB0 = (Ring_ExtStrength<<2)/thisInfo->tLabel_local_dsp.ulExtStrength ; RingTipStrengthRatio
	SLOOP1(0, 0, LOOP_LE, LOOP_REGC1),                                              // JP23 ; column loop	for(c=cs;c<=ce;c++)
	ADD(CNT1, CONST_VAL(PAD_), REGA6),					                            //      ; REGA6 = CNT1 + 1 (PAD_), A6 : c
	SRW1(REGA6, REGB3, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),                 //      ; CH1FLT = map(search_r, c)
	CMPS(CH1FLT, CONST_VAL(0)),														//		; cmp(map(search_r, c), 0)
	BRC(LINE_CNT(5), DOWN, EQ),														//		; map(search_r, c) == 0															-> JP24
	SRW0(REGA6, REGB3, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),                  //      ; CH0FLT = delta(search_r, c)
	ADDS(REGB1, CH0FLT00, REGB1),													//		; REGB1 = REGB1 + delta(search_r, c) ; EdgeStrength	
	SRW0(REGA6, REGB5, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),					//		; CH0FLT = delta(search_r1, c)
	ADDS(REGB1, CH0FLT00, REGB1),													//		; REGB1 = REGB1 + delta(search_r1, c) ; EdgeStrength
	ELOOP1(),																		// JP24 ;
	//15

	SLOOP1(0, 0, LOOP_LE, LOOP_REGC1),                                              // 		; column loop	for(c=cs;c<=ce;c++)
	ADD(CNT1, CONST_VAL(PAD_), REGA6),				                                //      ; REGA6 = CNT1 + 1 (PAD_), A6 : c
	SRW1(REGA6, REGB3, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),                 //      ; CH1FLT = map(search_r, c)
	CMPS(CH1FLT, CONST_VAL(0)),														//		; cmp(map(search_r, c), 0)
#if (CUSTOMER == MODEL_DEF_QHD_92407_FLIP && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
    BRC(LINE_CNT(116), DOWN, EQ),													//		; map(search_r, c) == 0			LINE_CNT(15+84)	99								-> JP25
#else
    BRC(LINE_CNT(103), DOWN, EQ),													//		; map(search_r, c) == 0			LINE_CNT(15+84)	99								-> JP25
#endif
	SRW0(REGA6, REGB3, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),                  //      ; CH0FLT = delta(search_r, c) ; _d
	MOV(CH0FLT00, REGC2),															//		; C2 = _d
	SRW0(REGA6, REGB5, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),					//		; CH0FLT = delta(search_r1, c) ; _d1
	MOV(CH0FLT00, REGC3),															//		; C3 = _d1
	MOV(CONST_VAL(0), REGC4),														//		; REGB7 = 0 ; _d2
	CMPS(REGA4, CONST_VAL(LOCAL_MODE)),                                             // 		; cmps(OP_mode, LOCAL_MODE)
#if (CUSTOMER == MODEL_DEF_QHD_92407_FLIP && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
    BRC(LINE_CNT(33), DOWN, NE),                                                   	//      ; OP_mode != LOCAL_MODE     													-> JP26
#else
	BRC(LINE_CNT(20), DOWN, NE),                                                   	//      ; OP_mode != LOCAL_MODE     													-> JP26
#endif
	SRW3(CONST_VAL(51),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),		//      ; CH3FLT READ : mul0
	MOV(CH3FLT, REGB6),																//		; B6 = mul0

    CMPS(REGB6, CONST_VAL(0)),														//		; cmp(mul0, 0)
#if (CUSTOMER == MODEL_DEF_QHD_92407_FLIP && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
	BRC(LINE_CNT(29), DOWN, EQ),													//		; REGB6 == 0			                                                        -> JP26
#else
	BRC(LINE_CNT(16), DOWN, EQ),													//		; REGB6 == 0			                                                        -> JP26
#endif

#if (CUSTOMER == MODEL_DEF_QHD_92407_FLIP && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
    CMPS(REGB3, CONST_VAL(PAD_)),                                                   // 		; cmps(search_r, 0 + PAD_)
	BRC(LINE_CNT(7), DOWN, NE),                                                     //      ; search_r != 0 + PAD_                                     						-> JP50
    SRW3(CONST_VAL(20),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 	//      ; CH3FLT READ : HID_TILT_Y
    MOV(CH3FLT, REGB7),																//		; B7 = HID_TILT_Y
    SRW3(CONST_VAL(43),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT), 	//      ; CH3FLT READ : HID_TILT_TH2
    CMPS(REGB7, CH3FLT),                                                     	    // 		; cmps(HID_TILT_Y, HID_TILT_TH2)
	BRC(LINE_CNT(7), DOWN, GTS),                                                    //      ; HID_TILT_Y > HID_TILT_TH2                                      				-> JP51
    BRC(LINE_CNT(12), DOWN, AL),                                                    //      ; Always                                     					            	-> JP28
    SRW3(CONST_VAL(20),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 	// JP50 ; CH3FLT READ : HID_TILT_Y
    MOV(CH3FLT, REGB7),																//		; B7 = HID_TILT_Y
    SRW3(CONST_VAL(42),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT), 	//      ; CH3FLT READ : HID_TILT_TH1
    CMPS(REGB7, CH3FLT),                                                     	    // 		; cmps(HID_TILT_Y, HID_TILT_TH1)
	BRC(LINE_CNT(7), DOWN, GES),                                                    //      ; HID_TILT_Y >= HID_TILT_TH1                                      				-> JP28
#endif
	SRW3(CONST_VAL(52),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	// JP51 ; CH3FLT READ : sr0
	MOV(CH3FLT, REGB7),																//		; B7 = sr0
	MULS(REGC2, REGB6, REGC4),					           	            		    //      ; C4 = _d * mul0 ; _d2
	SRLS(REGC4, REGB7, REGC4),														//		; C4 = (_d * mul0) >> sr ; _d2
	ADDS(REGC4, REGC3, REGC4),														//		; C4 = _d1 + ((_d * mul) >> sr) ; _d2
	SUBS(REGC2, REGC4, REGC4),														//		; C4 = _d - (_d1 + ((_d * mul) >> sr)) ; _d2
	//20
	CMPS(REGC4, CONST_VAL(0)),                                                     	// JP28	; cmps(_d2, 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                   	//      ; _d2 >= 0     																	-> JP30
	MOV(CONST_VAL(0), REGC4),														//		; _d2 = 0
	MULS(CNT1, REGC4, REGB6),					                        		    // JP30 ; B6 = c * _d2
	ADDS(REGC5, REGB6, REGC5),														//		; C5 = REGB6 + tCoord.x ; tCoord.x	
	SRW3(CONST_VAL(69), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),	//      ; CH3FLT READ : apply_r
	MULS(CH3FLT, REGC4, REGB6),					                        		    // 		; B6 = apply_r * _d2
	ADDS(REGC6, REGB6, REGC6),														//		; C6 = REGB6 + tCoord.y ; tCoord.y
	ADDS(REGC7, REGC4, REGC7),														//		; C7 += _d2 ; ulExtStrength
	SRW2(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),	// JP26 ; CH2FLT READ : tValidMaxPos.c
	CMPS(CNT1, CH2FLT),                                                     		// 		; cmps(c, tValidMaxPos.c)
	BRC(LINE_CNT(74), DOWN, NE),                                                   	//      ; c != tValidMaxPos.c     				//LINE_CNT 72							-> JP25
	//12
	SRW3(CONST_VAL(30), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),	// 		; CH3FLT READ : max_sum
	MOV(CH3FLT, REGA7),																//		; A7 = max_sum
	CMPS(REGA4, CONST_VAL(LOCAL_HOVER_MODE)),                                       // 		; cmps(OP_mode, LOCAL_HOVER_MODE)
	BRC(LINE_CNT(25), DOWN, NE),                                                   	//      ; OP_mode != LOCAL_HOVER_MODE     												-> JP31
	SRW3(CONST_VAL(43), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//		; CH3FLT READ : PenInfo_ucHover_cnt
	MOV(CH3FLT, REGB6),																//		; B6 = PenInfo_ucHover_cnt
	SRW3(CONST_VAL(44), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//		; CH3FLT READ : Label_ucHoverOutCheckFrm
	MOV(CH3FLT, REGB7),																//		; B7 = Label_ucHoverOutCheckFrm
	CMPS(REGB6, REGB7),                                                     		// 		; cmps(thisInfo->tPenInfo.ucHover_cnt, thisModeConf->Label.ucHoverOutCheckFrm)
	BRC(LINE_CNT(7), DOWN, GES),                                                   	//      ; thisInfo->tPenInfo.ucHover_cnt >= thisModeConf->Label.ucHoverOutCheckFrm     	-> JP32
	CMPS(REGB6, CONST_VAL(0)),                                                     	// 		; cmps(thisInfo->tPenInfo.ucHover_cnt, 0)
	BRC(LINE_CNT(3), DOWN, NE),                                                   	//      ; thisInfo->tPenInfo.ucHover_cnt != 0									     	-> JP33
	MULS(REGB1, REGB7, REGB1),					                        		    // 		; EdgeStrength = EdgeStrength * thisModeConf->Label.ucHoverOutCheckFrm
	BRC(LINE_CNT(3), DOWN, AL),                                                   	//      ; Always																		-> JP32
	DIVS(REGB1, REGB6, REGB1),					                        		    // JP33	; EdgeStrength = EdgeStrength / thisInfo->tPenInfo.ucHover_cnt
	MULS(REGB1, REGB7, REGB1),					                        		    // 		; EdgeStrength = EdgeStrength * thisModeConf->Label.ucHoverOutCheckFrm
	SUBS(REGA7, REGB1, REGB6),					                        		    // JP32	; B6 = max_sum - EdgeStrength
	ADDS(REGC4, REGB6, REGC4),					                        		    // 		; _d2 += (max_sum - EdgeStrength)
	MOV(CONST_VAL(0), REGC3),														//		; REGC3 = 0  ; _d1
//	BRC(LINE_CNT(43), DOWN, AL),		//TEST_CODE JP351
	CMPS(REGB1, CONST_VAL(0)),                                                     	// 		; cmps(EdgeStrength, 0)
	BRC(LINE_CNT(2), DOWN, LES),                                                   	//      ; EdgeStrength <= 0     														-> JP34
	DIVS(REGA7, REGB1, REGC3),					                        		    // 		; C3 = max_sum / EdgeStrength ; _d1
	SRW3(CONST_VAL(42), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	// JP34 ; CH3FLT READ : max_sum_hover_div
	ADDS(CH3FLT, REGC3, REGB6),					                        		    // 		; B6 = max_sum_hover_div + _d1
	CMPS(REGB6, CONST_VAL(0)),                                                     	// 		; cmps(max_sum_hover_div + _d1, 0)
	BRC(LINE_CNT(21), DOWN, LES),                                                   //      ; max_sum_hover_div + _d1 <= 0     												-> JP35
	DIVS(REGC4, REGB6, REGC4),					                        		    // 		; _d2 = _d2 / (max_sum_hover_div + _d1)
	BRC(LINE_CNT(34), DOWN, AL),                                                   	//      ; Always																		-> JP351
//	BRC(LINE_CNT(45), DOWN, AL),		//TEST_CODE JP00
	CMPS(REGB4, CONST_VAL(0)),                                                 	    // JP31	; cmps(search_c, 0)
	BRC(LINE_CNT(4), DOWN, GES),                                                   	//      ; search_c >= 0   																-> JP36
	SUBS(REGA7, REGC7, REGB6),					                        		    // 		; B6 = max_sum - ulExtStrength
	ADDS(REGC4, REGB6, REGC4),					                        		    // 		; _d2 += (max_sum - ulExtStrength)
	BRC(LINE_CNT(14), DOWN, AL),                                                   	//      ; Always																		-> JP35
	//33
	CMPS(REGB3, CONST_VAL(PAD_)),                                                  	// JP36 ; cmps(search_r, 0+PAD_)
	BRC(LINE_CNT(7), DOWN, NE),                                                   	//      ; search_r != 0    																-> JP37
	SRW0(REGA6, REGB5, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),					//		; CH0FLT = delta(search_r1, c) ; _d1
	MULS(CH0FLT00, CONST_VAL(8), REGB6),					                        // 		; B6 = _d1 * 8
	SRW3(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),	//      ; CH3FLT READ : top_max_sum_corner
	SUBS(CH3FLT, REGB6, REGB6),					                        		    // 		; B6 = top_max_sum_corner - _d1 * 8
	ADDS(REGC4, REGB6, REGC4),					                        		    // 		; _d2 += (top_max_sum_corner - _d1 * 8)
	BRC(LINE_CNT(6), DOWN, AL),                                                   	//      ; Always																		-> JP35
	SRW0(REGA6, REGB5, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),					// JP37	; CH0FLT = delta(search_r1, c) ; _d1
	MULS(CH0FLT00, CONST_VAL(8), REGB6),					                        // 		; B6 = _d1 * 8
	SRW3(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),	//      ; CH3FLT READ : bottom_max_sum_corner
	SUBS(CH3FLT, REGB6, REGB6),					                        		    // 		; B6 = bottom_max_sum_corner - (_d1 * 8)
	ADDS(REGC4, REGB6, REGC4),					                        		    // 		; _d2 += (bottom_max_sum_corner - (_d1 * 8))
	//13
	SRW3(CONST_VAL(45), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	// JP35 ; CH3FLT READ : TiltOn
	CMPS(CH3FLT,CONST_VAL(0)),														//		; cmps(TiltOn, 0)
	BRC(LINE_CNT(13), DOWN, EQ),													//		; TiltOn == 0																	-> JP351
	SRW3(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//      ; CH3FLT READ : th0
	CMPS(REGB0, CH3FLT),                                                     		// 		; cmps(RingTipStrengthRatio, th0)
	BRC(LINE_CNT(10), DOWN, LES),                                                   //      ; RingTipStrengthRatio <= th0     												-> JP351
	CMPS(REGA4, CONST_VAL(LOCAL_MODE)),                                             // 		; cmps(OP_mode, LOCAL_MODE)
	BRC(LINE_CNT(8), DOWN, NE),                                                   	//      ; OP_mode != LOCAL_MODE     													-> JP351
	SRW3(CONST_VAL(53),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//      ; CH3FLT READ : mul1
	MOV(CH3FLT, REGB6),																//		; B6 = mul1
	SRW3(CONST_VAL(54),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//      ; CH3FLT READ : sr1
	MOV(CH3FLT, REGB7),																//		; B7 = sr1
	MULS(REGB0, REGB6, REGA7),					                  				    // 		; A7 = RingTipStrengthRatio * mul1
	SRLS(REGA7, REGB7, REGA7),														//		; A7 = (RingTipStrengthRatio * mul1) >> sr1
	ADDS(REGC4, REGA7, REGC4),					                  				    // 		; _d2 += (RingTipStrengthRatio * mul1) >> sr1
	//15
	CMPS(REGC4, CONST_VAL(0)),                                                     	// JP351; cmps(_d2, 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                   	//      ; _d2 >= 0     																	-> JP39
	MOV(CONST_VAL(0), REGC4),														//		; _d2 = 0	
	SLLS(REGC5, CONST_VAL(2),REGB6),												// JP39	; B6 = C5 << 3											//ADDED
	DIVS(REGB6, REGC7, REGB6),														//		; B6 = tCoord.x<<3 / ulExtStrength
	MULS(REGB6, REGC4, REGB6),					                        		    //		; B6 = (tCoord.x<<3 / ulExtStrength) * _d2
	SRLS(REGB6, CONST_VAL(2), REGB6),												//		; B6 = B6>>3											//ADDED
	ADDS(REGC5, REGB6, REGC5),					                        			// 		; C5 += (tCoord.x / ulExtStrength * _d2) ; tCoord.x
//	MULS(CNT1, REGC4, REGB6),				//TEST_CODE	                   		    // 		; B6 = c * _d2
//	ADDS(REGC5, REGB6, REGC5),				//TEST_CODE								//		; C5 = REGB6 + tCoord.x ; tCoord.x		
	SRW3(CONST_VAL(69), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),	//      ; CH3FLT READ : apply_r
	MULS(CH3FLT, REGC4, REGB6),					                        		    // 		; B6 = apply_r * _d2
	ADDS(REGC6, REGB6, REGC6),														//		; C6 += (apply_r * _d2) ; tCoord.y
	ADDS(REGC7, REGC4, REGC7),														//		; C7 += _d2
	
//	BRC(LINE_CNT(2), DOWN, AL),														//TEST_CODE
	
	ELOOP1(),																		// JP25 ;
	//11
	
	SRW3(CONST_VAL(71),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),		// JP21 ; CH3FLT READ : search_c1
	MOV(CH3FLT, REGB5),																//		; B5 = search_c1
	//2
	
	// left,right edge ,118
	CMPS(REGB4, CONST_VAL(0)),                                                     	// 		; cmps(search_c, 0)
#if (CUSTOMER == MODEL_DEF_QHD_92407_FLIP && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
	BRC(LINE_CNT(135), DOWN, LTS),                                                  //      ; search_c < 0     																-> JP00
#else
	BRC(LINE_CNT(122), DOWN, LTS),                                                  //      ; search_c < 0     																-> JP00
#endif
	MOV(CONST_VAL(0), REGB1),                                        				//      ; REGB1 = 0 ; EdgeStrength
	SLLS(REGA5, CONST_VAL(2), REGB0),												//		; REGB0 = (Ring_ExtStrength<<2)
	DIVS(REGB0, REGC7, REGB0),														//		; REGB0 = (Ring_ExtStrength<<2)/thisInfo->tLabel_local_dsp.ulExtStrength ; RingTipStrengthRatio
	SLOOP0(0, 0, LOOP_LE, LOOP_REGC0),                                              // JP23'; row loop	for(r=rs;r<=re;r++)
	ADD(CNT0, CONST_VAL(PAD_), REGA6),					                            //      ; REGA6 = CNT0 + 1 (PAD_), A6 : r
	SRW1(REGB4, REGA6, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),                 //      ; CH1FLT = map(r, search_c)
	CMPS(CH1FLT, CONST_VAL(0)),														//		; cmp(map(r, search_c), 0)
	BRC(LINE_CNT(5), DOWN, EQ),														//		; map(r, search_c) == 0															-> JP24'
	SRW0(REGB4, REGA6, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),                  //      ; CH0FLT = delta(r, search_c)
	ADDS(REGB1, CH0FLT00, REGB1),													//		; REGB1 = REGB1 + delta(r, search_c) ; EdgeStrength	
	SRW0(REGB5, REGA6, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),					//		; CH0FLT = delta(r, search_c1)
	ADDS(REGB1, CH0FLT00, REGB1),													//		; REGB1 = REGB1 + delta(search_r1, c) ; EdgeStrength
	ELOOP0(),																		// JP24';
	//15

	SLOOP0(0, 0, LOOP_LE, LOOP_REGC0),                                              // 		; row loop	for(r=rs;r<=re;r++)
	ADD(CNT0, CONST_VAL(PAD_), REGA6),				                                //      ; REGA6 = CNT1 + 1 (PAD_), A6 : r
	SRW1(REGB4, REGA6, FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),                 //      ; CH1FLT = map(r, search_c)
	CMPS(CH1FLT, CONST_VAL(0)),														//		; cmp(map(r, search_c), 0)
#if (CUSTOMER == MODEL_DEF_QHD_92407_FLIP && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
	BRC(LINE_CNT(116), DOWN, EQ),													//		; map(r, search_c) == 0			LINE_CNT(15+84)	99								-> JP25'
#else
	BRC(LINE_CNT(103), DOWN, EQ),													//		; map(r, search_c) == 0			LINE_CNT(15+84)	99								-> JP25'
#endif
	SRW0(REGB4, REGA6, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),                  //      ; CH0FLT = delta(r, search_c) ; _d
	MOV(CH0FLT00, REGC2),															//		; C2 = _d
	SRW0(REGB5, REGA6, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),					//		; CH0FLT = delta(r, search_c1) ; _d1
	MOV(CH0FLT00, REGC3),															//		; C3 = _d1
	MOV(CONST_VAL(0), REGC4),														//		; C4 = 0 ; _d2
	CMPS(REGA4, CONST_VAL(LOCAL_MODE)),                                             // 		; cmps(OP_mode, LOCAL_MODE)
#if (CUSTOMER == MODEL_DEF_QHD_92407_FLIP && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
	BRC(LINE_CNT(33), DOWN, NE),                                                   	//      ; OP_mode != LOCAL_MODE     													-> JP26'
#else
    BRC(LINE_CNT(20), DOWN, NE),                                                   	//      ; OP_mode != LOCAL_MODE     													-> JP26'
#endif
	SRW3(CONST_VAL(55),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),		//      ; CH3FLT READ : mul0_LR
	MOV(CH3FLT, REGB6),																//		; B6 = mul0_LR

    CMPS(REGB6, CONST_VAL(0)),														//		; cmp(mul0_LR, 0)
#if (CUSTOMER == MODEL_DEF_QHD_92407_FLIP && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
	BRC(LINE_CNT(29), DOWN, EQ),													//		; REGB6 == 0			                                                        -> JP26'
#else
	BRC(LINE_CNT(16), DOWN, EQ),													//		; REGB6 == 0			                                                        -> JP26'
#endif

#if (CUSTOMER == MODEL_DEF_QHD_92407_FLIP && USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
    CMPS(REGB4, CONST_VAL(PAD_)),                                                   // 		; cmps(search_c, 0 + PAD_)
	BRC(LINE_CNT(7), DOWN, NE),                                                     //      ; search_c != 0 + PAD_                                         					-> JP50'
    SRW3(CONST_VAL(19),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 	//      ; CH3FLT READ : HID_TILT_X
    MOV(CH3FLT, REGB7),																//		; B7 = HID_TILT_X
    SRW3(CONST_VAL(43),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT), 	//      ; CH3FLT READ : HID_TILT_TH2
    CMPS(REGB7, CH3FLT),                                                     	    // 		; cmps(HID_TILT_X, HID_TILT_TH2)
	BRC(LINE_CNT(7), DOWN, GTS),                                                    //      ; HID_TILT_X > HID_TILT_TH2                                      				-> JP51'
    BRC(LINE_CNT(12), DOWN, AL),                                                    //      ; Always                                     					            	-> JP28'
    SRW3(CONST_VAL(19),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT), 	// JP50'; CH3FLT READ : HID_TILT_X
    MOV(CH3FLT, REGB7),																//		; B7 = HID_TILT_X
    SRW3(CONST_VAL(42),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_SIGNED, DT_16BIT), 	//      ; CH3FLT READ : HID_TILT_TH1
    CMPS(REGB7, CH3FLT),                                                     	    // 		; cmps(HID_TILT_X, HID_TILT_TH1)
	BRC(LINE_CNT(7), DOWN, GES),                                                    //      ; HID_TILT_X >= HID_TILT_TH1                                      				-> JP28'
#endif
	SRW3(CONST_VAL(56),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	// JP51'; CH3FLT READ : sr0_LR
	MOV(CH3FLT, REGB7),																//		; B7 = sr0_LR
	MULS(REGC2, REGB6, REGC4),					           	            		    //      ; C4 = _d * mul0_LR ; _d2
	SRLS(REGC4, REGB7, REGC4),														//		; C4 = (_d * mul0_LR) >> sr0_LR ; _d2
	ADDS(REGC4, REGC3, REGC4),														//		; C4 = _d1 + (_d * mul0_LR) >> sr0_LR ; _d2
	SUBS(REGC2, REGC4, REGC4),														//		; C4 = _d - (_d1 + (_d * mul0_LR) >> sr0_LR) ; _d2
	//20
	CMPS(REGC4, CONST_VAL(0)),                                                     	// JP28'; cmps(_d2, 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                   	//      ; _d2 >= 0     																	-> JP30'
	MOV(CONST_VAL(0), REGC4),														//		; _d2 = 0
	SRW3(CONST_VAL(72), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),	// JP30'; CH3FLT READ : apply_c
	MULS(CH3FLT, REGC4, REGB6),					                        		    // 		; B6 = apply_c * _d2
	ADDS(REGC5, REGB6, REGC5),														//		; C5 = REGB6 + tCoord.x ; tCoord.x
	MULS(CNT0, REGC4, REGB6),					                        		    // 		; B6 = r * _d2
	ADDS(REGC6, REGB6, REGC6),														//		; C6 = REGB6 + tCoord.y ; tCoord.y
	ADDS(REGC7, REGC4, REGC7),														//		; C7 += _d2 ; ulExtStrength
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),	// JP26'; CH2FLT READ : tValidMaxPos.r
	CMPS(CNT0, CH2FLT),                                                     		// 		; cmps(r, tValidMaxPos.r)
	BRC(LINE_CNT(74), DOWN, NE),                                                   	//      ; r != tValidMaxPos.r    				//LINE_CNT 72							-> JP25'
	//12
	SRW3(CONST_VAL(31), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),	// 		; CH3FLT READ : max_sum_LR
	MOV(CH3FLT, REGA7),																//		; A7 = max_sum_LR
	CMPS(REGA4, CONST_VAL(LOCAL_HOVER_MODE)),                                       // 		; cmps(OP_mode, LOCAL_HOVER_MODE)
	BRC(LINE_CNT(25), DOWN, NE),                                                   	//      ; OP_mode != LOCAL_HOVER_MODE     												-> JP31'
	SRW3(CONST_VAL(43), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//		; CH3FLT READ : PenInfo_ucHover_cnt
	MOV(CH3FLT, REGB6),																//		; B6 = PenInfo_ucHover_cnt
	SRW3(CONST_VAL(44), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//		; CH3FLT READ : Label_ucHoverOutCheckFrm
	MOV(CH3FLT, REGB7),																//		; B7 = Label_ucHoverOutCheckFrm
	CMPS(REGB6, REGB7),                                                     		// 		; cmps(thisInfo->tPenInfo.ucHover_cnt, thisModeConf->Label.ucHoverOutCheckFrm)
	BRC(LINE_CNT(7), DOWN, GES),                                                   	//      ; thisInfo->tPenInfo.ucHover_cnt >= thisModeConf->Label.ucHoverOutCheckFrm     	-> JP32'
	CMPS(REGB6, CONST_VAL(0)),                                                     	// 		; cmps(thisInfo->tPenInfo.ucHover_cnt, 0)
	BRC(LINE_CNT(3), DOWN, NE),                                                   	//      ; thisInfo->tPenInfo.ucHover_cnt != 0									     	-> JP33'
	MULS(REGB1, REGB7, REGB1),					                        		    // 		; EdgeStrength = EdgeStrength * thisModeConf->Label.ucHoverOutCheckFrm
	BRC(LINE_CNT(3), DOWN, AL),                                                   	//      ; Always																		-> JP32'
	DIVS(REGB1, REGB6, REGB1),					                        		    // JP33'; EdgeStrength = EdgeStrength / thisInfo->tPenInfo.ucHover_cnt
	MULS(REGB1, REGB7, REGB1),					                        		    // 		; EdgeStrength = EdgeStrength * thisModeConf->Label.ucHoverOutCheckFrm
	SUBS(REGA7, REGB1, REGB6),					                        		    // JP32'; B6 = max_sum_LR - EdgeStrength
	ADDS(REGC4, REGB6, REGC4),					                        		    // 		; _d2 += (max_sum_LR - EdgeStrength)
	MOV(CONST_VAL(0), REGC3),														//		; REGC3 = 0  ; _d1
//	BRC(LINE_CNT(43), DOWN, AL),		//TEST_CODE JP351
	CMPS(REGB1, CONST_VAL(0)),                                                     	// 		; cmps(EdgeStrength, 0)
	BRC(LINE_CNT(2), DOWN, LES),                                                   	//      ; EdgeStrength <= 0     														-> JP34'
	DIVS(REGA7, REGB1, REGC3),					                        		    // 		; C3 = max_sum_LR / EdgeStrength ; _d1
	SRW3(CONST_VAL(42), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	// JP34'; CH3FLT READ : max_sum_hover_div
	ADDS(CH3FLT, REGC3, REGB6),					                        		    // 		; B6 = max_sum_hover_div + _d1
	CMPS(REGB6, CONST_VAL(0)),                                                     	// 		; cmps(max_sum_hover_div + _d1, 0)
	BRC(LINE_CNT(21), DOWN, LES),                                                   //      ; max_sum_hover_div + _d1 <= 0     												-> JP35'
	DIVS(REGC4, REGB6, REGC4),					                        		    // 		; _d2 = _d2 / (max_sum_hover_div + _d1)
	BRC(LINE_CNT(34), DOWN, AL),                                                   	//      ; Always																		-> JP351'
	CMPS(REGB3, CONST_VAL(0)),                                                 	    // JP31'; cmps(search_r, 0)
	BRC(LINE_CNT(4), DOWN, GES),                                                   	//      ; search_r >= 0   																-> JP36'
	SUBS(REGA7, REGC7, REGB6),					                        		    // 		; B6 = max_sum_LR - ulExtStrength
	ADDS(REGC4, REGB6, REGC4),					                        		    // 		; _d2 += (max_sum_LR - ulExtStrength)
	BRC(LINE_CNT(14), DOWN, AL),                                                   	//      ; Always																		-> JP35'
	//33
	CMPS(REGB4, CONST_VAL(PAD_)),                                                  	// JP36'; cmps(search_c, 0+PAD_)
	BRC(LINE_CNT(7), DOWN, NE),                                                   	//      ; search_c != 0    																-> JP37'
	SRW0(REGB5, REGA6, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),					//		; CH0FLT = delta(r, search_c1) ; _d1
	MULS(CH0FLT00, CONST_VAL(8), REGB6),					                        // 		; B6 = _d1 * 8
	SRW3(CONST_VAL(15), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),	//      ; CH3FLT READ : left_max_sum_corner
	SUBS(CH3FLT, REGB6, REGB6),					                        		    // 		; B6 = left_max_sum_corner - _d1 * 8
	ADDS(REGC4, REGB6, REGC4),					                        		    // 		; _d2 += (left_max_sum_corner - _d1 * 8)
	BRC(LINE_CNT(6), DOWN, AL),                                                   	//      ; Always																		-> JP35'
	SRW0(REGB5, REGA6, FT_1X1, READ, PS_REG, DT_SIGNED, DT_16BIT),					// JP37'; CH0FLT = delta(r, search_c1) ; _d1
	MULS(CH0FLT00, CONST_VAL(8), REGB6),					                        // 		; B6 = _d1 * 8
	SRW3(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT),	//      ; CH3FLT READ : right_max_sum_corner
	SUBS(CH3FLT, REGB6, REGB6),					                        		    // 		; B6 = right_max_sum_corner - (_d1 * 8)
	ADDS(REGC4, REGB6, REGC4),					                        		    // 		; _d2 += right_max_sum_corner - (_d1 * 8)
	//13
	SRW3(CONST_VAL(45), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	// JP35'; CH3FLT READ : TiltOn
	CMPS(CH3FLT,CONST_VAL(0)),														//		; cmps(TiltOn, 0)
	BRC(LINE_CNT(13), DOWN, EQ),													//		; TiltOn == 0																	-> JP351'
	SRW3(CONST_VAL(0), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//      ; CH3FLT READ : th0
	CMPS(REGB0, CH3FLT),                                                     		// 		; cmps(RingTipStrengthRatio, th0)
	BRC(LINE_CNT(10), DOWN, LES),                                                   //      ; RingTipStrengthRatio <= th0     												-> JP351'
	CMPS(REGA4, CONST_VAL(LOCAL_MODE)),                                             // 		; cmps(OP_mode, LOCAL_MODE)
	BRC(LINE_CNT(8), DOWN, NE),                                                   	//      ; OP_mode != LOCAL_MODE     													-> JP351'
	SRW3(CONST_VAL(57),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//      ; CH3FLT READ : mul1_LR
	MOV(CH3FLT, REGB6),																//		; B6 = mul1_LR
	SRW3(CONST_VAL(58),CONST_VAL(0),FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_8BIT),	//      ; CH3FLT READ : sr1_LR
	MOV(CH3FLT, REGB7),																//		; B7 = sr1_LR
	MULS(REGB0, REGB6, REGA7),					                  				    // 		; A7 = RingTipStrengthRatio * mul1_LR
	SRLS(REGA7, REGB7, REGA7),														//		; A7 = (RingTipStrengthRatio * mul1_LR) >> sr1_LR
	ADDS(REGC4, REGA7, REGC4),					                  				    // 		; _d2 += (RingTipStrengthRatio * mul1_LR) >> sr1_LR
	//15
	CMPS(REGC4, CONST_VAL(0)),                                                     	// JP351'; cmps(_d2, 0)
	BRC(LINE_CNT(2), DOWN, GES),                                                   	//      ; _d2 >= 0     																	-> JP39'
	MOV(CONST_VAL(0), REGC4),														//		; _d2 = 0	
	SRW3(CONST_VAL(72), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),	// JP39'; CH3FLT READ : apply_c
	MULS(CH3FLT, REGC4, REGB6),					                        		    // 		; B6 = apply_c * _d2
	ADDS(REGC5, REGB6, REGC5),														//		; C5 = REGB6 + tCoord.x ; tCoord.x
	
	SLLS(REGC6, CONST_VAL(2), REGB6),		//ADDED
	DIVS(REGB6, REGC7, REGB6),				//ADDED
	
	MULS(REGB6, REGC4, REGB6),					                        		    // 		; B6 = r * _d2
	
	SRLS(REGB6, CONST_VAL(2), REGB6),		//ADDED
	
	ADDS(REGC6, REGB6, REGC6),														//		; C6 = REGB6 + tCoord.y ; tCoord.y
	ADDS(REGC7, REGC4, REGC7),														//		; C7 += _d2 ; ulExtStrength
	
	ELOOP0(),																		// JP25';
	//10
	
	END()                                                                           // JP00 ; 0x37000000
};

#if 0
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
	CMP(REGB1, CONST_VAL(LOCAL_HOVER_MODE)),                                        //      ; cmp(REGB1, LOCAL_HOVER_MODE), B1 : mode
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
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
	BRC(LINE_CNT(37), DOWN, EQ),                                                   	//      ; search_r == -1     			-> JP04
#else
	BRC(LINE_CNT(35), DOWN, EQ),                                                   	//      ; search_r == -1     			-> JP04
#endif
	CMPS(REGC5, REGC2),                                                     		//      ; cmps(search_c, -1)
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
	BRC(LINE_CNT(6), DOWN, EQ),                                                   	//      ; search_c == -1     			-> JP05
#else
	BRC(LINE_CNT(4), DOWN, EQ),                                                   	//      ; search_c == -1     			-> JP05
#endif
#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
	CMP(REGB1, CONST_VAL(LOCAL_HOVER_MODE)),                                        //      ; cmp(REGB1, LOCAL_HOVER_MODE), B1 : mode
	BRC(LINE_CNT(4), DOWN, NE),                                                   	//      ; mode != LOCAL_HOVER_MODE		-> JP05
#endif
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
    ADD(CNT1, CONST_VAL(1), REGA7),                                                 //      ; REGA7 = CNT1 + REGB1, B1 : ucPadSize, A7 : c
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
    ADD(CNT0, CONST_VAL(1), REGA7),                                                 //      ; REGA7 = CNT0 + REGB1, B1 : ucPadSize, A7 : r
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
#endif
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

/********************************************************************************
  @brief    Pen Tilt OPCODE
  */
#ifdef SRAM_OPCODE
int opcode_tilt_step1[] = 
#else
int opcode_tilt_step1[] = 
#endif
{
    SDMA0(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : Coordi info
    SDMA1(REGA0, 0, DMA_SIZE1),                                                     //      ; 
    SDMA2(REGA1, 0, DMA_SIZE2),                                                     //      ; A1 : ArcSinLUT
    SDMA3(REGA2, 0, DMA_SIZE2),                                                     //      ; A2 : CosLUT
	
	BRC(LINE_CNT(10), DOWN, AL), 													// 		; 											-> JP06
	CMPS(REGB3, REGC2),   															// JP08 ; cmps (REGB3, REGC2) : both x, y
	BRC(LINE_CNT(2), DOWN, LES), 													//		; sx <= maxLenth							-> JP05
	MOV(REGC2, REGB3), 																//		; REGB3 = REGC2 : sx = maxLenth
	MULS(REGB3, CONST_VAL(20), REGB2),                                              // JP05	; REGB3 * 20 = REGB2 : sx * 20
	DIVS(REGB2, REGA6, REGB2),                                             			// 		; REGB2/REGA6 = REGB2 : (sx * 20)/L
	SRW0(REGB2, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),			//		; CH0FLT READ : LookUpTable[(sx * 20)/L]
	MULS(REGB3, CH0FLT00, REGB3),                                              		//		; REGB0 * CH0FLT00 = REGB0 : sx * UpTable[(sx * 20)/L] = sx
	SRLS(REGB3, CONST_VAL(7), REGB3),												//      ; REGB0 = REGB0 >> 7 : sx / 128
	RET(1),																			//		; return BLC
    
	CMP(REGA7, CONST_VAL(0)),   													// JP06 ; cmps (REGA7, 0)
	BRC(LINE_CNT(77), DOWN, EQ), 													//		; REGA7 == 0								-> JP00
	SRW0(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),	//      ; CH0FLT READ : OrgPos.x
	SRW1(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),	//      ; CH1FLT READ : OrgPastPos[0].x
	SUBS(CH0FLT00,CH1FLT, REGB0),   												//		; CH0FLT00-CH1FLT = REGB0 : x dis
	MULS(REGB0, REGA4, REGB0),														//		; REGB0 * REGA4 = REGB0 : x dis * (1.375 * 127)
	DIVS(REGB0, CONST_VAL(127), REGB0),												// 		; REGB0/127 = REGB0 : x dis mm * 100 = sx
	SRW0(CONST_VAL(17), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),	//  	; CH0FLT READ : OrgPos.y
	SRW1(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),	//      ; CH1FLT READ : OrgPastPos[0].y
	SUBS(CH0FLT00,CH1FLT, REGB1),   												//		; CH0FLT00-CH1FLT = REGB1 : y dis 
	MULS(REGB1, REGA5, REGB1),                                                      //		; REGB1 * REGA5 = REGB1 : y dis * (1.434 * 127)
	DIVS(REGB1, CONST_VAL(127), REGB1),                                             // 		; REGB1/127 = REGB1 : y dis mm * 100 = sy
	CMP(REGC0, CONST_VAL(3)),   													//		; cmps (REGC0, 3)
	BRC(LINE_CNT(25), DOWN, NE), 													//		; REGC0 != 3								-> JP03
	CMP(REGC1, CONST_VAL(0)),   													//		; cmps (REGC1, 0)
	BRC(LINE_CNT(23), DOWN, EQ), 													//		; REGC1 == 0								-> JP03
	CMPS(REGB0, CONST_VAL(0)),   													//		; cmps (REGB0, 0)
	BRC(LINE_CNT(6), DOWN, GES), 													//		; sx >= 0									-> JP04
	SDMA0(REGC3, 0, DMA_SIZE2),                                                     // 		; C3 : sxMLookUpTable
	SUBS(CONST_VAL(0), REGB0, REGB3),   											// 		; 0-REGB0 = REGB3 : 0-sx; - => +
	BLC(LINE_CNT(29), UP, AL), 														//		; repeat function							-> JP08
	SUBS(CONST_VAL(0), REGB3, REGB0),   											//		; 0-REGB3 = REGB0 : 0-sx; + => -
	BRC(LINE_CNT(5), DOWN, AL), 													// 		; 											-> JP07
	SDMA0(REGC4, 0, DMA_SIZE2),                                                     // JP04	; C4 : sxPLookUpTable
	MOV(REGB0, REGB3), 																//		; REGB3 = REGB0 : sx
	BLC(LINE_CNT(34), UP, AL), 														//		; repeat function							-> JP08
	MOV(REGB3, REGB0), 																//		; REGB3 = REGB0 : sx
	CMPS(REGB1, CONST_VAL(0)),   													// JP07	; cmps (REGB1, 0)
	BRC(LINE_CNT(6), DOWN, GES), 													//		; sy >= 0									-> JP09
	SDMA0(REGC5, 0, DMA_SIZE2),                                                     // 		; C5 : syMLookUpTable
	SUBS(CONST_VAL(0), REGB1, REGB3),   											// 		; 0-REGB1 = REGB3 : 0-sy; - => +
	BLC(LINE_CNT(40), UP, AL), 														//		; repeat function							-> JP08
	SUBS(CONST_VAL(0), REGB3, REGB1),   											//		; 0-REGB3 = REGB1 : 0-sy; + => -
	BRC(LINE_CNT(5), DOWN, AL), 													// 		; 											-> JP03
	SDMA0(REGC6, 0, DMA_SIZE2),                                                     // JP09	; C6 : syPLookUpTable
	MOV(REGB1, REGB3), 																//		; REGB3 = REGB1 : sy
	BLC(LINE_CNT(45), UP, AL), 														//		; repeat function							-> JP08
	MOV(REGB3, REGB1), 																//		; REGB3 = REGB1 : sy
	SDMA0(REGA3, 0, DMA_SIZE2),														// JP03	; A3 : Tilt info
	SDMA1(REGA3, 0, DMA_SIZE2),
	SRW0(CONST_VAL(0), REGB0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; REGB0 WRITE : TILT_sx
	SRW1(CONST_VAL(1), REGB1, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; REGB1 WRITE : TILT_sy
	MULS(REGB0, REGB0, REGB0),														//		; REGB0 * REGB0 = REGB0 : sx * sx
	MULS(REGB1, REGB1, REGB1),														//		; REGB1 * REGB1 = REGB1 : sy * sy
	ADD(REGB0,REGB1,REGB1),															//		; REGB1 + REGB0 = REGB1 : (sx * sx) + (sy * sy)
	MOV(CONST_VAL(1), REGB2),                                                       //      ; REGB2 = 1 : x
    SLOOP0(1, 15, LOOP_LE, LOOP_SOURCE),                                            //      ; loop 1:15
    DIVS(REGB1, REGB2, REGB3),                                                      //      ; REGB3 = REGB1 / REGB2
    ADDS(REGB2, REGB3, REGB3),                                                      //      ; REGB3 = REGB2 + REGB3
    SRLS(REGB3, CONST_VAL(1), REGB2),                                               //      ; REGB2 = REGB3 >> 1
    ELOOP0(),  																		//		; REGB2 : sqrt((sx * sx) + (sy * sy)) = D
	SRW0(CONST_VAL(2), REGB2, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; REGB2 WRITE : TILT_distance
	MULS(REGB2,CONST_VAL(10),REGB2),												//		; REGB2 = REGB2 * 10 : distance * 10
	DIVS(REGB2, REGA6, REGB2),														//		; REGB2/REGA6 = REGB2 : D/L 
	CMPS(REGB2, CONST_VAL(0)),														//		; cmps (D/L, 0)
	BRC(LINE_CNT(2), DOWN, GE), 													//		; D/L  >= 0 								-> JP01
	MOV(CONST_VAL(0), REGB2), 														//		; REGB2 = 0 : D/L  = 0
	CMPS(REGB2, CONST_VAL(127)),													// JP01	; cmps (D/L , 127)
	BRC(LINE_CNT(2), DOWN, LE),														//		; D/L  <= 127								-> JP02
	MOV(CONST_VAL(127), REGB2), 													//		; REGB2 = 127 : D/L = 127
	SRW2(REGB2, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),			// JP02 ; CH2FLT READ : ArcSinLUT[D/L] = theta
	SRW0(CONST_VAL(3), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; CH0FLT WRITE : TILT_theta
	CMP(REGC0, CONST_VAL(3)),   													//		; cmps (REGC0, 3)
	BRC(LINE_CNT(3), DOWN, EQ), 													//		; REGC0 == 3								-> JP10
	SRW3(CH2FLT, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_8BIT),			//		; CH3FLT READ : CosLUT[theta]
	BRC(LINE_CNT(2), DOWN, AL), 													// 		; 											-> JP11
	SRW3(CH2FLT, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),		// JP10 ; CH3FLT READ : CosLUT[theta]
	MUL(CH3FLT, REGA6, REGB1),														// JP11 ; CH3FLT * REGA6 = REGB1 : CosLUT[theta] * L = H * 10
	DIVS(REGB1, CONST_VAL(10), REGB1),												//		; REGB1/10 = REGB1 : H
	CMP(REGC0, CONST_VAL(3)),   													//		; cmps (REGC0, 3)
	BRC(LINE_CNT(2), DOWN, NE), 													//		; REGC0 != 3								-> JP12
	SRLS(REGB1, CONST_VAL(3), REGB1),												//      ; REGB1 = REGB1 >> 3 : H / 8
	SRW0(CONST_VAL(4), REGB1, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			// JP12 ; REGB1 WRITE : TILT_H
	CMP(REGC0, CONST_VAL(3)),   													//		; cmps (REGC0, 3)
	BRC(LINE_CNT(3), DOWN, NE), 													//		; REGC0 != 3								-> JP13
	MULS(REGB1, CONST_VAL(100), REGB1),												//		; REGB1 = REGB1 * 100 : H * 100
	SRLS(REGB1, CONST_VAL(7), REGB1),												//      ; REGB1 = REGB1 >> 7 : H / 128
	SRW1(CONST_VAL(9), REGB1, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			// JP13 ; REGB1 WRITE : HID_ALTITUDE
	
    END()																			// JP00
};

#ifdef SRAM_OPCODE
int opcode_tilt_step2[] = 
#else
int opcode_tilt_step2[] = 
#endif
{
    SDMA1(REGA1, 0, DMA_SIZE2),                                                     //      ; A1 : ArcTanLUT
    SDMA2(REGA2, 0, DMA_SIZE2),                                                     //      ; A2 : Tilt info
    
	CMP(REGA7, CONST_VAL(0)),   													//		; cmps (REGA7, 0)
	BRC(LINE_CNT(88), DOWN, EQ),                                                    //		; REGA7 == 0								-> JP00
	CMPS(REGA3, CONST_VAL(0)),														//		; cmps (REGA3, 0) 
	BRC(LINE_CNT(37), DOWN, LES),                                                   //		; REGA3 <= 0 : diff_x <= 0					-> JP01
	CMPS(REGA4, CONST_VAL(0)),														//		; cmps (REGA4, 0) 
	BRC(LINE_CNT(14), DOWN, LES),                                                   //		; REGA4 <= 0 : diff_y <= 0					-> JP02
	CMPS(REGA3, REGA4),																//		; cmps (REGA3, REGA4) 
	BRC(LINE_CNT(6), DOWN, LTS),                                                    //		; REGA3 < REGA4 : diff_x < diff_y			-> JP03
	MUL(REGA4, CONST_VAL(100), REGB0),												//		; REGA4 * 100 = REGB0 : diff_y * 100
	DIVS(REGB0, REGA3, REGB0),														//		; REGB0 / REGA3 = REGB0 : (diff_y*100)/diff_x
	SRW1(REGB0, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),			//		; CH1FLT READ : ArcTanLUT[REGB0]
	MOV(CH1FLT,REGB1),																//		; REGB1 = CH1FLT
	BRC(LINE_CNT(76), DOWN, AL), 													// 		; 											 ->JP04
	MUL(REGA3, CONST_VAL(100), REGB0),												// JP03 ; REGA3 * 100 = REGB0 : diff_x * 100
	DIVS(REGB0, REGA4, REGB0),														//		; REGB0 / REGA4 = REGB0 : (diff_x*100)/diff_y
	SRW1(REGB0, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),			//		; CH1FLT READ : ArcTanLUT[REGB0]
	MUL(CONST_VAL(90), CONST_VAL(100), REGB2),										//		; REGB2 = 90*100 : 9000
	SUB(REGB2,CH1FLT,REGB1),														//		; REGB1 = REGB2-CH1FLT	: 9000 - ArcTanLUT[REGB0]
	BRC(LINE_CNT(70), DOWN, AL), 													// 		; 											 ->JP04
	CMPS(REGA4, CONST_VAL(0)),														// JP02	; cmps (REGA4, 0)
	BRC(LINE_CNT(18), DOWN, EQ),                                                    //		; REGA4 == 0 : diff_y == 0					 ->JP05
	SUBS(CONST_VAL(0),REGA4,REGA4),													// 		; 0 - REGA4 = REGA4 : -diff_y
	CMPS(REGA3, REGA4),																//		; cmps (REGA3, REGA4) 
	BRC(LINE_CNT(8), DOWN, LTS),                                                    //		; REGA3 < REGA4 : diff_x < -diff_y			 ->JP06
	MULS(REGA4, CONST_VAL(100), REGB0),												//		; REGA4 * 100 = REGB0 : -diff_y * 100
	DIVS(REGB0, REGA3, REGB0),														//		; REGB0 / REGA3 = REGB0 : (-diff_y*100)/diff_x
	SRW1(REGB0, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),			//		; CH1FLT READ : ArcTanLUT[REGB0]	
	MUL(CONST_VAL(36), CONST_VAL(100), REGB2),										//		; REGB2 = 36*100 : 3600
	MUL(REGB2, CONST_VAL(10), REGB2),												//		; REGB2 = 3600*10 : 36000
	SUB(REGB2,CH1FLT,REGB1),														//		; REGB1 = REGB2-CH1FLT	: 36000 - ArcTanLUT[REGB0]
	BRC(LINE_CNT(58), DOWN, AL), 													// 		; 											 ->JP04
	MULS(REGA3, CONST_VAL(100), REGB0),												// JP06	; REGA3 * 100 = REGB0 : diff_x * 100
	DIVS(REGB0, REGA4, REGB0),														//		; REGB0 / REGA4 = REGB0 : (diff_y*100)/-diff_y
	SRW1(REGB0, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),			//		; CH1FLT READ : ArcTanLUT[REGB0]	
	MUL(CONST_VAL(27), CONST_VAL(100), REGB2),										//		; REGB2 = 27*100 : 2700
	MUL(REGB2, CONST_VAL(10), REGB2),												//		; REGB2 = 2700*10 : 27000
	ADD(REGB2,CH1FLT,REGB1),														//		; REGB1 = REGB2+CH1FLT	: 27000 + ArcTanLUT[REGB0]
	BRC(LINE_CNT(51), DOWN, AL), 													// 		; 											 ->JP04	
	MOV(CONST_VAL(0),REGB1),														// JP05 ; REGB1 = 0
	BRC(LINE_CNT(49), DOWN, AL), 													// 		; 											 ->JP04
	CMPS(REGA3, CONST_VAL(0)),														// JP01	; cmps (REGA3, 0) 
	BRC(LINE_CNT(41), DOWN, EQ),                                                    //  	; REGA3 == 0 : diff_x == 0					-> JP07
	SUBS(CONST_VAL(0),REGA3,REGA3),													// 		; 0 - REGA3 = REGA3 : -diff_x
	CMPS(REGA4, CONST_VAL(0)),														//		; cmps (REGA4, 0) 
	BRC(LINE_CNT(16), DOWN, LES),                                                   //  	; REGA4 <= 0 : diff_y <= 0					-> JP08
	CMPS(REGA3, REGA4),																//		; cmps (REGA3, REGA4) 
	BRC(LINE_CNT(7), DOWN, GES),                                                    //		; REGA3 >= REGA4 : -diff_x >= diff_y		-> JP09
	MUL(REGA3, CONST_VAL(100), REGB0),												//		; REGA3 * 100 = REGB0 : -diff_x * 100
	DIVS(REGB0, REGA4, REGB0),														//		; REGB0 / REGA4 = REGB0 : (-diff_x*100)/diff_y
	SRW1(REGB0, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),			//		; CH1FLT READ : ArcTanLUT[REGB0]
	MUL(CONST_VAL(90), CONST_VAL(100), REGB2),										//		; REGB2 = 90*100 : 9000
	ADD(REGB2,CH1FLT,REGB1),														//		; REGB1 = REGB2+CH1FLT : 9000 + ArcTanLUT[REGB0]
	BRC(LINE_CNT(36), DOWN, AL), 													// 		; 											 ->JP04	
	MUL(REGA4, CONST_VAL(100), REGB0),												// JP09 ; REGA4 * 100 = REGB0 : diff_y * 100
	DIVS(REGB0, REGA3, REGB0),														//		; REGB0 / REGA3 = REGB0 : (diff_y*100)/-diff_x
	SRW1(REGB0, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),			//		; CH1FLT READ : ArcTanLUT[REGB0]
	MUL(CONST_VAL(90), CONST_VAL(100), REGB2),										//		; REGB2 = 90*100 : 9000
	MUL(REGB2, CONST_VAL(2), REGB2),												//		; REGB2 = 9000*2 : 18000
	SUB(REGB2,CH1FLT,REGB1),														//		; REGB1 = REGB2-CH1FLT	: 18000 - ArcTanLUT[REGB0]
	BRC(LINE_CNT(29), DOWN, AL), 													// 		; 											 ->JP04
	CMPS(REGA4, CONST_VAL(0)),														// JP08	; cmps (REGA4, 0)
	BRC(LINE_CNT(18), DOWN, EQ),                                                    //		; REGA4 == 0 : diff_y == 0					 ->JP10
	SUBS(CONST_VAL(0),REGA4,REGA4),													// 		; 0 - REGA4 = REGA4 : -diff_y
	CMPS(REGA3, REGA4),																//		; cmps (REGA3, REGA4) 
	BRC(LINE_CNT(8), DOWN, LTS),                                                    //		; REGA3 < REGA4 : -diff_x < -diff_y			 ->JP11
	MULS(REGA4, CONST_VAL(100), REGB0),												//		; REGA4 * 100 = REGB0 : -diff_y * 100
	DIVS(REGB0, REGA3, REGB0),														//		; REGB0 / REGA3 = REGB0 : (-diff_y*100)/-diff_x
	SRW1(REGB0, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),			//		; CH1FLT READ : ArcTanLUT[REGB0]	
	MUL(CONST_VAL(90), CONST_VAL(100), REGB2),										//		; REGB2 = 90*100  : 9000
	MUL(REGB2, CONST_VAL(2), REGB2),												//		; REGB2 = 9000*2 : 18000
	ADD(REGB2,CH1FLT,REGB1),														//		; REGB1 = REGB2+CH1FLT	: 18000 + ArcTanLUT[REGB0]
	BRC(LINE_CNT(17), DOWN, AL), 													// 		; 											 ->JP04
	MULS(REGA3, CONST_VAL(100), REGB0),												// JP11	; REGA3 * 100 = REGB0 : -diff_x * 100
	DIVS(REGB0, REGA4, REGB0),														//		; REGB0 / REGA4 = REGB0 : (-diff_x*100)/-diff_y
	SRW1(REGB0, CONST_VAL(0), FT_1X1, READ, PS_REG, DT_UNSIGNED, DT_16BIT),			//		; CH1FLT READ : ArcTanLUT[REGB0]	
	MUL(CONST_VAL(27), CONST_VAL(100), REGB2),										//		; REGB2 = 27*100 : 2700
	MUL(REGB2, CONST_VAL(10), REGB2),												//		; REGB2 = 2700*10 : 27000
	SUB(REGB2,CH1FLT,REGB1),														//		; REGB1 = REGB2-CH1FLT	: 27000 - ArcTanLUT[REGB0]
	BRC(LINE_CNT(10), DOWN, AL), 													// 		; 											 ->JP04	
	MUL(CONST_VAL(90), CONST_VAL(100), REGB1),										// JP10	; REGB1 = 90*100 : 9000
	MUL(REGB1, CONST_VAL(2), REGB1),												//		; REGB1 = 9000*2 : 18000
	BRC(LINE_CNT(7), DOWN, AL), 													// 		; 											 ->JP04
	CMPS(REGA4, CONST_VAL(0)),														// JP07	; cmps (REGA4, 0) 
	BRC(LINE_CNT(3), DOWN, LES),                                                    //		; REGA4 <= 0 : diff_y <= 0			 		 ->JP12	
	MUL(CONST_VAL(90), CONST_VAL(100), REGB1),										//  	; REGB1 = 90*100 : 9000
	BRC(LINE_CNT(3), DOWN, AL), 													// 		; 											 ->JP04
	MUL(CONST_VAL(27), CONST_VAL(100), REGB1),										// JP12	; REGB1 = 27*100 : 2700
	MUL(REGB1, CONST_VAL(10), REGB1),												//		; REGB1 = 2700*10 : 27000	
	SRW2(REGA5, REGB1, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),					// JP04	; REGB1 WRITE : TILT_MODE(5=x,6=y,8=phi)	
	
    END()																			// JP00
};

#ifdef SRAM_OPCODE
int opcode_tilt_step3[] = 
#else
int opcode_tilt_step3[] = 
#endif
{
    SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : Tilt info
	SDMA2(REGA0, 0, DMA_SIZE2),                                                     
    SDMA3(REGA0, 0, DMA_SIZE2),														//      ; A0 : Tilt info
	SDMA0(REGA0, 0, DMA_SIZE2),
	
	CMP(REGA7, CONST_VAL(0)),   													//		; cmps (REGA7, 0)
//	BRC(LINE_CNT(207), DOWN, EQ),													//		; REGA7 == 0								-> JP00
#if (TILT_EDGE_FILTER == YES && TILT_AREA_FILTER == YES)
	BRC(LINE_CNT(206), DOWN, EQ),                                                   //		; REGA7 == 0								-> JP00
#elif (TILT_EDGE_FILTER == YES)
	BRC(LINE_CNT(97), DOWN, EQ),
#elif (TILT_AREA_FILTER == YES)
	BRC(LINE_CNT(159), DOWN, EQ),
#else
	BRC(LINE_CNT(50), DOWN, EQ),
#endif
	SRW1(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH1FLT READ : TILT_theta	
	
	CMP(REGA1, CONST_VAL(0)),														//		: cmps (REGA7, 0)
	BRC(LINE_CNT(2), DOWN, GT),														//		; REGA7>0, Tilt_cnt>0						-> JP23
	BRC(LINE_CNT(6), DOWN, AL),														//		; Tilt_cnt==0, 								-> JP22
	CMP(CH1FLT, CONST_VAL(0)),   													// JP23	; cmps (CH1FLT, 0)
	BRC(LINE_CNT(2), DOWN, NE),                                                     //		; CH1FLT != 0	: TILT_theta != 0			-> JP24
	BRC(LINE_CNT(3), DOWN, AL),														//		; CH1FLT == 0	: TILT_theta == 0			-> JP22
	CMP(CH1FLT, CONST_VAL(117)),   													// JP24 ; cmps (CH1FLT, 117)
	BRC(LINE_CNT(9), DOWN, NE),                                                     //		; CH1FLT != 117	: TILT_theta != 117			-> JP01	
	
	SRW1(CONST_VAL(12), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	// JP22	; CH1FLT READ : Smooth_PastTilt.x
	SRW2(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH2FLT READ : Smooth_PastTilt.y
	SRW1(CONST_VAL(5), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; CH1FLT WRITE : HID_TILT_X = Smooth_PastTilt.x
	SRW2(CONST_VAL(6), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; CH2FLT WRITE : HID_TILT_Y = Smooth_PastTilt.y
	SRW1(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH1FLT READ : PastAzimuth
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH2FLT READ : PastAltitude
	SRW1(CONST_VAL(8), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; CH1FLT WRITE : HID_AZIMUTH = PastAzimuth
	SRW2(CONST_VAL(9), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; CH2FLT WRITE : HID_ALTITUDE = PastAltitude		
	// Tilt Smoothing
	CMP(REGA1, CONST_VAL(1)),   													// JP01	; cmps (REGA1, 0)	
	#ifdef TILT_SMOOTHING
	BRC(LINE_CNT(23), DOWN, EQ),                                                    //		; REGA1 == 1 : Tilt_cnt == 1				-> JP15
	#else
	BRC(LINE_CNT(23), DOWN, AL),													//		; 											-> JP15
	#endif
	SRW1(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//  	; CH1FLT READ : HID_TILT_X
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH2FLT READ : HID_TILT_Y
	MOV(CH1FLT,REGB0),																//		; REGB0 = CH1FLT : REGB0 = HID_TILT_X
	MOV(CH2FLT,REGB1),																//		; REGB1 = CH2FLT : REGB1 = HID_TILT_Y
	SRW1(CONST_VAL(12), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH1FLT READ : Smooth_PastTilt.x
	SRW2(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH2FLT READ : Smooth_PastTilt.y
	MOV(CH1FLT,REGB2),																//		; REGB2 = CH1FLT : REGB2 = Smooth_PastTilt.x
	MOV(CH2FLT,REGB3),																//		; REGB3 = CH2FLT : REGB3 = Smooth_PastTilt.y
	CMP(REGA1, REGC3),   															//		; cmps (REGA1, REGC3)
	BRC(LINE_CNT(2), DOWN, GT),                                                     //		; REGA1 > REGC3 : Tilt_cnt > REGC3					-> JP03
	MOV(REGC4,REGA2),																//		; REGA2 = REGC4 : coefficient = REGC4
	SUBS(CONST_VAL(32),REGA2,REGA3),												// JP03 ; REGA3 = 32 - REGA2 : 32 - coefficient
	MULS(REGB2,REGA2,REGB2),														//		; REGB2 = REGB2*REGA2 : Smooth_PastTilt.x * coefficient
	MULS(REGB0,REGA3,REGB0),														//		; REGB0 = REGB0*REGA3 : HID_TILT_X * (32-coefficient)
	ADDS(REGB0,REGB2,REGB0),														//		; REGB0 = REGB2+REGB0 : (coefficient*Smooth_PastTilt.x) + (32-coefficient)*HID_TILT_X
	DIVS(REGB0,CONST_VAL(32),REGB0),												//		; REGB0 = REGB0/32    : ((coefficient*Smooth_PastTilt.x) + (32-coefficient)*HID_TILT_X)/32
	MULS(REGB3,REGA2,REGB3),														//		; REGB3 = REGB3*REGA2 : Smooth_PastTilt.y * coefficient
	MULS(REGB1,REGA3,REGB1),														//		; REGB1 = REGB1*REGA3 : HID_TILT_Y * (32-coefficient)
	ADDS(REGB1,REGB3,REGB1),														//		; REGB1 = REGB3+REGB1 : (coefficient*Smooth_PastTilt.y) + (32-coefficient)*HID_TILT_Y
	DIVS(REGB1,CONST_VAL(32),REGB1),												//		; REGB1 = REGB1/32    : ((coefficient*Smooth_PastTilt.y) + (32-coefficient)*HID_TILT_Y)/32	
	SRW1(CONST_VAL(5), REGB0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; REGB0 WRITE : HID_TILT_X = ((coefficient*Smooth_PastTilt.X) + (32-coefficient)*HID_TILT_X)/32
	SRW2(CONST_VAL(6), REGB1, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; REGB1 WRITE : HID_TILT_Y = ((coefficient*Smooth_PastTilt.y) + (32-coefficient)*HID_TILT_Y)/32
	//Edge Filter
	#if (TILT_EDGE_FILTER == YES)
//	#ifdef TILT_EDGE_FILTER
//	BRC(LINE_CNT(1), DOWN, AL),                                                     // JP15 ; 											-> JP16
//	#else
//	BRC(LINE_CNT(48), DOWN, AL),													// JP15	; 											-> JP02
//	#endif 
	MOV(CONST_VAL(0),REGB0),														// JP16 ; REGB0 = 0 : past_out_flag = 0
	SDMA3(REGB5, 0, DMA_SIZE2),														//      ; B5 : Label info
	SDMA0(REGB5, 0, DMA_SIZE2),
	SRW0(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),		//		; CH0FLT00 READ : tValidRect.ce
	SRW3(CONST_VAL(4), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),		//		; CH3FLT READ : tValidRect.cs
	SUBS(CH0FLT00,CH3FLT,REGB1),													//      ; REGB1 = CH0FLT00 - CH3FLT : X_sensor_len = tValidRect.ce - tValidRect.cs
	ADD(REGB1,CONST_VAL(1),REGB1),													//		; REGB1 = REGB1 + 1 : X_sensor_len = tValidRect.ce - tValidRect.cs + 1
	SRW0(CONST_VAL(3), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),		//		; CH0FLT00 READ : tValidRect.re
	SRW3(CONST_VAL(2), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),		//		; CH3FLT READ : tValidRect.rs
	SUBS(CH0FLT00,CH3FLT,REGB2),													//      ; REGB2 = CH0FLT00 - CH3FLT : Y_sensor_len = tValidRect.re - tValidRect.rs
	ADD(REGB2,CONST_VAL(1),REGB2),													//		; REGB2 = REGB2 + 1 : Y_sensor_len = tValidRect.re - tValidRect.rs + 1
	SDMA3(REGC2, 0, DMA_SIZE2),														//      ; C3 : Coordi info
	SDMA0(REGC2, 0, DMA_SIZE2),
	SRW3(CONST_VAL(16), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),	//      ; CH3FLT READ : OrgPos.x
	SRW0(CONST_VAL(17), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_32BIT),	//      ; CH0FLT00 READ : OrgPos.y
	CMP(CH3FLT, REGB6),   															//  	; cmps (CH3FLT, REGB6) : (OrgPos.x , X_start_TH)
	BRC(LINE_CNT(4), DOWN, GE),                                                     //		; CH3FLT >= REGB6 : OrgPos.x >= X_start_TH		-> JP17
	CMP(REGB1, CONST_VAL(7)),   													//  	; cmps (REGB1, 7) : (X_sensor_len, len_th)
	BRC(LINE_CNT(7), DOWN, GE),                                                     //		; REGB1 >= 7 : X_sensor_len >= 7				-> JP18
	BRC(LINE_CNT(15), DOWN, AL),													// 		; 												-> JP20
	CMP(CH3FLT, REGB7),   															// JP17 ; cmps (CH3FLT, REGB7) : (OrgPos.x , X_end_TH)
	BRC(LINE_CNT(4), DOWN, LE),                                                     //		; CH3FLT <= REGB7 : OrgPos.x <= X_end_TH		-> JP18
	CMP(REGB1, CONST_VAL(7)),   													//  	; cmps (REGB1, 7) : (X_sensor_len, len_th)
	BRC(LINE_CNT(2), DOWN, GE),                                                     //		; REGB1 >= 7 : X_sensor_len >= 7				-> JP18
	BRC(LINE_CNT(10), DOWN, AL),													// 		; 												-> JP20
	CMP(CH0FLT00, REGC0),   														// JP18 ; cmps (CH0FLT00, REGC0) : (OrgPos.y , Y_start_TH)
	BRC(LINE_CNT(4), DOWN, GE),                                                     //		; CH0FLT00 >= REGC0 : OrgPos.y >= Y_start_TH	-> JP19
	CMP(REGB2, CONST_VAL(7)),   													//  	; cmps (REGB2, 7) : (Y_sensor_len, len_th)
	BRC(LINE_CNT(7), DOWN, GE),                                                     //		; REGB2 >= 7 : Y_sensor_len >= 7				-> JP21
	BRC(LINE_CNT(5), DOWN, AL),	 													// 		; 												-> JP20
	CMP(CH0FLT00, REGC1),   														// JP19 ; cmps (CH0FLT00,REGC1) : (OrgPos.y , Y_end_TH)
	BRC(LINE_CNT(4), DOWN, LE),    	                                                //		; CH0FLT00 <= REGC1 : OrgPos.y <= Y_end_TH		-> JP21
	CMP(REGB2, CONST_VAL(7)),   													//  	; cmps (REGB2, 7) : (Y_sensor_len, len_th)
	BRC(LINE_CNT(2), DOWN, GE),                                                     //		; REGB2 >= 7 : Y_sensor_len >= 7				-> JP21
	MOV(CONST_VAL(1),REGB0),														// JP20 ; REGB0 = 1 : past_out_flag = 1	
    SDMA3(REGA0, 0, DMA_SIZE2),														// JP21 ; A0 : Tilt info
	SDMA0(REGA0, 0, DMA_SIZE2),	
	CMP(REGB0, CONST_VAL(0)),   													//  	; cmps (REGB0, 0)
	BRC(LINE_CNT(9), DOWN, EQ),           	                                        //		; REGB0 == 0 : past_out_flag == 0			-> JP02
	SRW1(CONST_VAL(12), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH1FLT READ : Smooth_PastTilt.x
	SRW2(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH2FLT READ : Smooth_PastTilt.y
	SRW1(CONST_VAL(5), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; CH1FLT WRITE : HID_TILT_X = Smooth_PastTilt.x
	SRW2(CONST_VAL(6), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; CH2FLT WRITE : HID_TILT_Y = Smooth_PastTilt.y
	SRW1(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//      ; CH1FLT READ : PastAzimuth 
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH2FLT READ : PastAltitude
	SRW1(CONST_VAL(8), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; CH1FLT WRITE : HID_AZIMUTH = PastAzimuth
	SRW2(CONST_VAL(9), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			//		; CH2FLT WRITE : HID_ALTITUDE = PastAltitude 	
	#endif
	SRW1(CONST_VAL(8), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	// JP02 ; CH1FLT READ : HID_AZIMUTH 
	SRW2(CONST_VAL(9), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH2FLT READ : HID_ALTITUDE
	SRW1(CONST_VAL(10), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH1FLT WRITE : PastAzimuth  = HID_AZIMUTH 
	SRW2(CONST_VAL(11), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH2FLT WRITE : PastAltitude = HID_ALTITUDE	 	
	SRW1(CONST_VAL(5), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//  	; CH1FLT READ : HID_TILT_X
	SRW2(CONST_VAL(6), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH2FLT READ : HID_TILT_Y
	SRW1(CONST_VAL(12), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH1FLT WRITE : Smooth_PastTilt.x = HID_TILT_X
	SRW2(CONST_VAL(13), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH2FLT WRITE : Smooth_PastTilt.y = HID_TILT_Y	
	//Area Filter
	#if (TILT_AREA_FILTER == YES)
	CMP(REGA1, CONST_VAL(1)),   													// 		; cmps (REGA1, 1)	
//	#ifdef TILT_AREA_FILTER
	BRC(LINE_CNT(104), DOWN, LE),                                                    //		; REGA1 == 1 : Tilt_cnt == 1				-> JP04
//	#else
//	BRC(LINE_CNT(108), DOWN, AL),                                                   //		; 											-> JP00
//	#endif
	// X
	SRW3(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH3FLT READ : Area_PastTilt.x
	SUBS(CH1FLT,CH3FLT,REGB2),														//		; REGB2 = CH1FLT - CH3FLT : Tilt_SUB = HID_TILT_X - Area_PastTilt.x
	CMPS(REGB2, CONST_VAL(0)),   													// 		; cmps (REGB2, 0) : (Tilt_SUB,0)
	BRC(LINE_CNT(3), DOWN, GTS),                                                    //		; REGB2 > 0 : Tilt_SUB > 0					-> JP05
	MOV(CONST_VAL(0),REGB3),														//		; REGB3 = 0 : TiltUpFlag = 0
	BRC(LINE_CNT(2), DOWN,AL),														//		;											-> JP15
	MOV(CONST_VAL(1),REGB3),														// JP05	; REGB3 = 1 : TiltUpFlag = 1
	MOV(CONST_VAL(0),REGB4),														// JP15	; REGB4 = 0 : UpDownChangeCheck = 0
	SRW0(CONST_VAL(64), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),	//		; CH0FLT00 READ : TiltUpDownST.x
	MOV(CH0FLT00,REGA4),															//		; REGA4 = CH0FLT00 : REGA4 = TiltUpDownST.x
	CMP(REGA4, CONST_VAL(0)),   													// 		; cmps (REGA4, 0) : (TiltUpDownST_X,0)
	BRC(LINE_CNT(3), DOWN, NE),                                                     //		; REGA4 != 0 : TiltUpDownST_X != 0			-> JP06
	MOV(CONST_VAL(2),REGA4),														//		; REGA4 = 2 : TiltUpDownST_X = 2
	BRC(LINE_CNT(18), DOWN,AL),														//		;											-> JP07
	CMP(REGA4, CONST_VAL(1)),   													// JP06	; cmps (REGA4, 1) : (TiltUpDownST_X,1)
	BRC(LINE_CNT(9), DOWN, NE),                                                     //		; REGA1 != 1 : TiltUpDownST_X != 1			-> JP08
	CMP(REGB3, CONST_VAL(1)),   													//  	; cmps (REGB3, 1) : (TiltUpFlag, 1)
	BRC(LINE_CNT(5), DOWN, NE),                                                     //		; TiltUpFlag != 1 : TiltUpFlag != 1			-> JP09
	
	CMPS(REGB2, REGC5),   															//  	; cmps (REGB2, REGC5) : (Tilt_SUB, Tilt_Change_TH_Right)
	BRC(LINE_CNT(3), DOWN, LES),                                                    //		; Tilt_SUB <= Tilt_Change_TH_Right 			-> JP09
	
	SRW3(CONST_VAL(14), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH1FLT WRITE : Area_PastTilt.x = HID_TILT_X
	BRC(LINE_CNT(12), DOWN,AL),														//		;											-> JP07
	MOV(CONST_VAL(1),REGB4),														// JP09	; REGB4 = 1 : UpDownChangeCheck = 1
	BRC(LINE_CNT(10), DOWN,AL),														//		;											-> JP07
	CMP(REGA4, CONST_VAL(3)),   													// JP08	; cmps (REGA4, 3) : (TiltUpDownST_X,3)
	BRC(LINE_CNT(7), DOWN, NE),                                                     //		; REGA1 != 3 : TiltUpDownST_X != 3			-> JP07
	CMP(REGB3, CONST_VAL(0)),   													//  	; cmps (REGB3, 0) : (TiltUpFlag, 0)
	BRC(LINE_CNT(5), DOWN, NE),                                                     //		; TiltUpFlag != 0 : TiltUpFlag != 0			-> JP10
	
	CMPS(REGB2, REGC6),   															//  	; cmps (REGB2, REGC5) : (Tilt_SUB, Tilt_Change_TH_Right)
	BRC(LINE_CNT(3), DOWN, GES),                                                    //		; Tilt_SUB >= -Tilt_Change_TH_Right 			-> JP10
	
	SRW3(CONST_VAL(14), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH1FLT WRITE : Area_PastTilt.x = HID_TILT_X
	BRC(LINE_CNT(2), DOWN,AL),														//		;											-> JP07
	MOV(CONST_VAL(1),REGB4),														// JP10	; REGB4 = 1 : UpDownChangeCheck = 1
	CMP(REGA4, CONST_VAL(2)),   													// JP07	; cmps (REGA4, 2) : (TiltUpDownST_X,2)
	BRC(LINE_CNT(2), DOWN, NE),                                                     //		; REGA1 != 2 : TiltUpDownST_X != 2			-> JP11		
	MOV(CONST_VAL(1),REGB4),														// 		; REGB4 = 1 : UpDownChangeCheck = 1	
	CMP(REGB4, CONST_VAL(1)),   													// JP11	; cmps (REGB4, 1) : (UpDownChangeCheck,1)
	BRC(LINE_CNT(13), DOWN, NE),                                                    //		; REGB4 != 1 : UpDownChangeCheck != 1		-> JP12	
	CMPS(REGA5, REGB2),   															//  	; cmps (REGA5, REGB2) : (Tilt_Change_TH,Tilt_SUB)
	BRC(LINE_CNT(4), DOWN, GES),                                                    //		; REGA5 >= REGB2 : Tilt_Change_TH >= Tilt_SUB	-> JP13	
	SRW3(CONST_VAL(14), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH1FLT WRITE : Area_PastTilt.x = HID_TILT_X
	MOV(CONST_VAL(1),REGA4),														//		; REGA4 = 1 : TiltUpDownST_X = 1
	BRC(LINE_CNT(8), DOWN,AL),														//		;											-> JP12
	SUBS(CONST_VAL(0),REGA5,REGA6),													// JP13 ; REGA6 = 0 - REGA5 : REGA6 = -Tilt_Change_TH
	CMPS(REGA6, REGB2),   															//  	; cmps (REGA6, REGB2) : (-Tilt_Change_TH,Tilt_SUB)
	BRC(LINE_CNT(4), DOWN, LES),                                                    //		; REGA6 <= REGB2 : -Tilt_Change_TH <= Tilt_SUB	-> JP14	
	SRW3(CONST_VAL(14), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH1FLT WRITE : Area_PastTilt.x = HID_TILT_X
	MOV(CONST_VAL(3),REGA4),														//		; REGA4 = 3 : TiltUpDownST_X = 3
	BRC(LINE_CNT(2), DOWN,AL),														//		;											-> JP12
	SRW1(CONST_VAL(5), CH3FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			// JP14	; CH3FLT WRITE : HID_TILT_X = Area_PastTilt.x
	SRW0(CONST_VAL(64), REGA4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),			// JP12	; REGA4 WRITE  : TiltUpDownST.x = REGA4
	// Y
	SRW3(CONST_VAL(15), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),	//		; CH3FLT READ : Area_PastTilt.y
	SUBS(CH2FLT,CH3FLT,REGB2),														//		; REGB2 = CH2FLT - CH3FLT : Tilt_SUB = HID_TILT_Y - Area_PastTilt.y
	CMPS(REGB2, CONST_VAL(0)),   													// 		; cmps (REGB2, 0) : (Tilt_SUB,0)
	BRC(LINE_CNT(3), DOWN, GTS),                                                    //		; REGB2 > 0 : Tilt_SUB > 0					-> JP05
	MOV(CONST_VAL(0),REGB3),														//		; REGB3 = 0 : TiltUpFlag = 0
	BRC(LINE_CNT(2), DOWN,AL),														//		;											-> JP15
	MOV(CONST_VAL(1),REGB3),														// JP05	; REGB3 = 1 : TiltUpFlag = 1
	MOV(CONST_VAL(0),REGB4),														// JP15	; REGB4 = 0 : UpDownChangeCheck = 0
	SRW0(CONST_VAL(65), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_8BIT),	//		; CH0FLT00 READ : TiltUpDownST.y
	MOV(CH0FLT00,REGA4),															//		; REGA4 = CH0FLT00 : REGA4 = TiltUpDownST.y
	CMP(REGA4, CONST_VAL(0)),   													// 		; cmps (REGA4, 0) : (TiltUpDownST.y,0)
	BRC(LINE_CNT(3), DOWN, NE),                                                     //		; REGA4 != 0 : TiltUpDownST.y != 0			-> JP06
	MOV(CONST_VAL(2),REGA4),														//		; REGA4 = 2 : TiltUpDownST.y = 2
	BRC(LINE_CNT(18), DOWN,AL),														//		;											-> JP07
	CMP(REGA4, CONST_VAL(1)),   													// JP06	; cmps (REGA4, 1) : (TiltUpDownST.y,1)
	BRC(LINE_CNT(9), DOWN, NE),                                                     //		; REGA1 != 1 : TiltUpDownST.y != 1			-> JP08
	CMP(REGB3, CONST_VAL(1)),   													//  	; cmps (REGB3, 1) : (TiltUpFlag, 1)
	BRC(LINE_CNT(5), DOWN, NE),                                                     //		; TiltUpFlag != 1 : TiltUpFlag != 1			-> JP09
	
	CMPS(REGB2, REGC5),   															//  	; cmps (REGB2, REGC5) : (Tilt_SUB, Tilt_Change_TH_Right)
	BRC(LINE_CNT(3), DOWN, LES),                                                    //		; Tilt_SUB <= Tilt_Change_TH_Right 			-> JP09
	
	SRW3(CONST_VAL(15), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH2FLT WRITE : Area_PastTilt.y = HID_TILT_Y
	BRC(LINE_CNT(12), DOWN,AL),														//		;											-> JP07
	MOV(CONST_VAL(1),REGB4),														// JP09	; REGB4 = 1 : UpDownChangeCheck = 1
	BRC(LINE_CNT(10), DOWN,AL),														//		;											-> JP07
	CMP(REGA4, CONST_VAL(3)),   													// JP08	; cmps (REGA4, 3) : (TiltUpDownST.y,3)
	BRC(LINE_CNT(8), DOWN, NE),                                                     //		; REGA1 != 3 : TiltUpDownST.y != 3			-> JP07
	CMP(REGB3, CONST_VAL(0)),   													//  	; cmps (REGB3, 0) : (TiltUpFlag, 0)
	BRC(LINE_CNT(5), DOWN, NE),                                                     //		; TiltUpFlag != 0 : TiltUpFlag != 0			-> JP10
	
	CMPS(REGB2, REGC6),   															//  	; cmps (REGB2, REGC5) : (Tilt_SUB, Tilt_Change_TH_Right)
	BRC(LINE_CNT(3), DOWN, GES),                                                    //		; Tilt_SUB >= -Tilt_Change_TH_Right 			-> JP10
	
	SRW3(CONST_VAL(15), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH2FLT WRITE : Area_PastTilt.y = HID_TILT_X
	BRC(LINE_CNT(2), DOWN,AL),														//		;											-> JP07
	MOV(CONST_VAL(1),REGB4),														// JP10	; REGB4 = 1 : UpDownChangeCheck = 1
	CMP(REGA4, CONST_VAL(2)),   													// JP07	; cmps (REGA4, 2) : (TiltUpDownST.y,2)
	BRC(LINE_CNT(2), DOWN, NE),                                                     //		; REGA1 != 2 : TiltUpDownST.y != 2			-> JP11		
	MOV(CONST_VAL(1),REGB4),														// 		; REGB4 = 1 : UpDownChangeCheck = 1	
	CMP(REGB4, CONST_VAL(1)),   													// JP11	; cmps (REGB4, 1) : (UpDownChangeCheck,1)
	BRC(LINE_CNT(13), DOWN, NE),                                                    //		; REGB4 != 1 : UpDownChangeCheck != 1		-> JP12	
	CMPS(REGA5, REGB2),   															//  	; cmps (REGA5, REGB2) : (Tilt_Change_TH,Tilt_SUB)
	BRC(LINE_CNT(4), DOWN, GES),                                                    //		; REGA5 >= REGB2 : Tilt_Change_TH >= Tilt_SUB	-> JP13	
	SRW3(CONST_VAL(15), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH2FLT WRITE : Area_PastTilt.y = HID_TILT_Y
	MOV(CONST_VAL(1),REGA4),														//		; REGA4 = 1 : TiltUpDownST.y = 1
	BRC(LINE_CNT(8), DOWN,AL),														//		;											-> JP12
	SUBS(CONST_VAL(0),REGA5,REGA6),													// JP13 ; REGA6 = 0 - REGA5 : REGA6 = -Tilt_Change_TH
	CMPS(REGA6, REGB2),   															//  	; cmps (REGA6, REGB2) : (-Tilt_Change_TH,Tilt_SUB)
	BRC(LINE_CNT(4), DOWN, LES),                                                    //		; REGA6 <= REGB2 : -Tilt_Change_TH <= Tilt_SUB	-> JP14	
	SRW3(CONST_VAL(15), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH2FLT WRITE : Area_PastTilt.y = HID_TILT_Y
	MOV(CONST_VAL(3),REGA4),														//		; REGA4 = 3 : TiltUpDownST_X = 3
	BRC(LINE_CNT(2), DOWN,AL),														//		;											-> JP12
	SRW1(CONST_VAL(6), CH3FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),			// JP14	; CH3FLT WRITE : HID_TILT_Y = Area_PastTilt.y
	SRW0(CONST_VAL(65), REGA4, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),			// JP12	; REGA4 WRITE  : TiltUpDownST.y = REGA4
	BRC(LINE_CNT(5), DOWN,AL),														//		;											-> JP00
	SRW1(CONST_VAL(14), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		// JP04	; CH1FLT WRITE : Area_PastTilt.x = HID_TILT_X
	SRW2(CONST_VAL(15), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),		//		; CH2FLT WRITE : Area_PastTilt.y = HID_TILT_Y	
	SRW0(CONST_VAL(64), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),	// 		; 0 WRITE  : TiltUpDownST.x = 0
	SRW0(CONST_VAL(65), CONST_VAL(0), FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_8BIT),	// 		; 0 WRITE  : TiltUpDownST.y = 0
	#endif
	END()																			// JP00
};

#ifdef SRAM_OPCODE
int opcode_tilt_step4[] = 
#else
int opcode_tilt_step4[] = 
#endif
{
    SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : Coordi info
    SDMA2(REGA0, 0, DMA_SIZE1),                                                     //      ; 
    SDMA3(REGA0, 0, DMA_SIZE2),                                                     //      ; 
    
	CMP(REGA7, CONST_VAL(0)),   													//		; cmps (REGA7, 0)
	BRC(LINE_CNT(40), DOWN, EQ), 													//		; REGA7 == 0								-> JP00
	CMP(REGA6, CONST_VAL(1)),   													//		; cmps (REGA6, 0)
	BRC(LINE_CNT(38), DOWN, EQ), 													//		; REGA6 == 1								-> JP00
	SRW1(CONST_VAL(30), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tPastPos[1].vusS
	CMP(CH1FLT, CONST_VAL(0)),   													//		; cmps (CH1FLT, 0)
	BRC(LINE_CNT(24), DOWN, EQ), 													//		; CH1FLT == 0								-> JP01	
	CMP(REGA5, CONST_VAL(0)),   													//		; cmps (REGA5, 0)
	BRC(LINE_CNT(22), DOWN, EQ), 													//		; REGA5 == 0								-> JP01	
	SRW1(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPos[0].tXY.x
	SRW2(CONST_VAL(13), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tPastPos[1].tXY.x
	SUBS(CH1FLT,CH2FLT,REGB0),														//		; REGB0 = CH1FLT - CH2FLT
	ADDS(CH1FLT,REGB0,REGB0),														//		; REGB0 = CH1FLT + REGB0
	SRW3(CONST_VAL(0), REGB0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; REGB0 WRITE : tPos.tXY.x = REGB0
	SRW1(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tPastPos[0].tXY.y
	SRW2(CONST_VAL(14), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tPastPos[1].tXY.y
	SUBS(CH1FLT,CH2FLT,REGB0),														//		; REGB0 = CH1FLT - CH2FLT
	ADDS(CH1FLT,REGB0,REGB0),														//		; REGB0 = CH1FLT + REGB0
	SRW3(CONST_VAL(1), REGB0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; REGB0 WRITE : tPos.tXY.y = REGB0
	SRW1(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.x
	SRW2(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tOrgPastPos[1].tXY.x
	SUBS(CH1FLT,CH2FLT,REGB0),														//		; REGB0 = CH1FLT - CH2FLT
	ADDS(CH1FLT,REGB0,REGB0),														//		; REGB0 = CH1FLT + REGB0
	SRW3(CONST_VAL(16), REGB0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; REGB0 WRITE : tOrgPos.tXY.x = REGB0
	SRW1(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.y
	SRW2(CONST_VAL(26), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tOrgPastPos[1].tXY.y
	SUBS(CH1FLT,CH2FLT,REGB0),														//		; REGB0 = CH1FLT - CH2FLT
	ADDS(CH1FLT,REGB0,REGB0),														//		; REGB0 = CH1FLT + REGB0
	SRW3(CONST_VAL(17), REGB0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; REGB0 WRITE : tOrgPos.tXY.y = REGB0	
	BRC(LINE_CNT(12), DOWN, AL),													//		;										-> JP00
	SRW1(CONST_VAL(10), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP01 ; CH1FLT READ : tPastPos[0].tXY.x
	SRW3(CONST_VAL(0), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; CH1FLT WRITE : tPos.tXY.x = CH1FLT
	SRW2(CONST_VAL(11), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tPastPos[0].tXY.y
	SRW3(CONST_VAL(1), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; CH2FLT WRITE : tPos.tXY.y = CH2FLT
	SRW1(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.x
	SRW3(CONST_VAL(16), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; CH1FLT WRITE : tOrgPos.tXY.x = CH1FLT
	SRW2(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tOrgPastPos[0].tXY.y
	SRW3(CONST_VAL(17), CH2FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; CH2FLT WRITE : tOrgPos.tXY.y = CH2FLT
	SRW1(CONST_VAL(24), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tPastPos[0].vusS
	SRW3(CONST_VAL(4), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),  		//      ; CH1FLT WRITE : tPos.vusS = CH1FLT
	SRW2(CONST_VAL(36), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),  	//      ; CH1FLT WRITE : tOrgPos.vusS = CH1FLT		
    END()																			// JP00
};

#ifdef SRAM_OPCODE
int opcode_tilt_step0[] = 
#else
int opcode_tilt_step0[] = 
#endif
{
    SDMA1(REGA0, 0, DMA_SIZE2),                                                     //      ; A0 : Coordi info
    SDMA2(REGA0, 0, DMA_SIZE1),                                                     //      ; 
    SDMA3(REGA0, 0, DMA_SIZE2),                                                     //      ; 
    
	CMP(REGA7, CONST_VAL(0)),   													//		; cmps (REGA7, 0)
	BRC(LINE_CNT(31), DOWN, EQ), 													//		; REGA7 == 0, thisInfo->tCoord_local_dsp.tAvgPos.y==0	-> JP00
//	CMP(REGA6, 1),   																//		; cmps (REGA6, 1)
//	BRC(LINE_CNT(31), DOWN, EQ), 													//		; REGA6 == 1, thisInfo->tCoord_local_dsp.tAvgPos.x==0 	-> JP00
	SRW1(CONST_VAL(54), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tOrgPastPos[1].vusS
	CMP(CH1FLT, CONST_VAL(0)),   													//		; cmps (CH1FLT, 0)
	BRC(LINE_CNT(19), DOWN, EQ), 													//		; CH1FLT == 0								-> JP01		
	//BRC(LINE_CNT(19), DOWN, AL),
	CMP(REGA5, 0),   																//		; cmps (REGA6, 1)
	BRC(LINE_CNT(17), DOWN, EQ), 													//		; REGA5 == 0, Tilt_cnt 						-> JP01	
	SRW1(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.x
	SRW2(CONST_VAL(25), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tOrgPastPos[1].tXY.x
	SUBS(CH1FLT,CH2FLT,REGB0),														//		; REGB0 = CH1FLT - CH2FLT
	ADDS(CH1FLT,REGB0,REGB0),														//		; REGB0 = CH1FLT + REGB0
	SRW3(CONST_VAL(16), REGB0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; REGB0 WRITE : tOrgPos.tXY.x = REGB0
	SRW3(CONST_VAL(0), REGB0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; REGB0 WRITE : tPos.tXY.x = REGB0
	SRW1(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.y
	SRW2(CONST_VAL(26), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH2FLT READ : tOrgPastPos[1].tXY.y
	SUBS(CH1FLT,CH2FLT,REGB0),														//		; REGB0 = CH1FLT - CH2FLT
	ADDS(CH1FLT,REGB0,REGB0),														//		; REGB0 = CH1FLT + REGB0
	SRW3(CONST_VAL(17), REGB0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; REGB0 WRITE : tOrgPos.tXY.y = REGB0
	SRW3(CONST_VAL(1), REGB0, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; REGB0 WRITE : tPos.tXY.y = REGB0	
	SRW1(CONST_VAL(48), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tOrgPastPos[0].vusS
	SRW2(CONST_VAL(36), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),  	//      ; CH1FLT WRITE : tOrgPos.vusS = CH1FLT	
	SRW3(CONST_VAL(4), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),  		//      ; CH1FLT WRITE : tPos.vusS = CH1FLT	
	BRC(LINE_CNT(10), DOWN, AL),													//		;										-> JP00
	SRW1(CONST_VAL(22), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   // JP01 ; CH1FLT READ : tOrgPastPos[0].tXY.x
	SRW2(CONST_VAL(16), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; CH1FLT WRITE : tOrgPos.tXY.x = CH1FLT
	SRW3(CONST_VAL(0), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; CH1FLT WRITE : tPos.tXY.x = CH1FLT
	SRW1(CONST_VAL(23), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_SIGNED, DT_32BIT),   //      ; CH1FLT READ : tOrgPastPos[0].tXY.y
	SRW2(CONST_VAL(17), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; CH1FLT WRITE : tOrgPos.tXY.y = CH1FLT
	SRW3(CONST_VAL(1), CH1FLT, FT_1X1, WRITE, PS_INX, DT_SIGNED, DT_32BIT),  		//      ; CH1FLT WRITE : tPos.tXY.y = CH1FLT
	SRW1(CONST_VAL(48), CONST_VAL(0), FT_1X1, READ, PS_INX, DT_UNSIGNED, DT_16BIT), //      ; CH1FLT READ : tOrgPastPos[0].vusS
	SRW2(CONST_VAL(36), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),  	//      ; CH1FLT WRITE : tOrgPos.vusS = CH1FLT	
	SRW3(CONST_VAL(4), CH1FLT, FT_1X1, WRITE, PS_INX, DT_UNSIGNED, DT_16BIT),  		//      ; CH1FLT WRITE : tPos.vusS = CH1FLT	
    END()																			// JP00
};

void TMH_COMPLETE_Method(void)
{
#if 0
    while((REG_TDSP2_BUSY & 0x01));
#endif
}

/********************************************************************************
  @brief    Pen Line Filter
  @return   None
  */
#if 1
void TMH_PenLineFilter (
	uint16_t		*pRawImg,       	/**< input raw data buffer pointer */
    uint16_t		*pBaseImg,      	/**< input base data buffer pointer */
	uint8_t			ucColStart,
	uint8_t			ucColEnd,
    uint8_t			nHeight,        	/**< height */
	uint16_t		RowStart,
	uint8_t			ucSmpNum,			/**< Sampling Number */
	uint8_t			RowStartOffset
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_linefilter>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pRawImg>>16;
	
	DSP_CON->TDSP_REGC0 = (uint32_t)nHeight;
	DSP_CON->TDSP_REGC1 = (uint32_t)(((ucColStart/ucSmpNum)<<8)|(ucColEnd/ucSmpNum));//(uint32_t)(nWidth/ucSmpNum);
	DSP_CON->TDSP_REGC2 = (uint32_t)((ucColStart<<8)|(ucColEnd));//(uint32_t)nWidth;
	DSP_CON->TDSP_REGA0 = ((uint32_t)pRawImg) & 0xFFFF;
	DSP_CON->TDSP_REGA1 = ((uint32_t)pBaseImg) & 0xFFFF;
	DSP_CON->TDSP_REGA2 = (uint32_t)RowStart;
	DSP_CON->TDSP_REGA3 = (uint32_t)0; 														// Column Start
	DSP_CON->TDSP_REGA4 = (uint32_t)INT16_MAX;
	DSP_CON->TDSP_REGA5 = (uint32_t)ucSmpNum;
	DSP_CON->TDSP_REGA6 = (uint32_t)RowStartOffset;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_linefilter) & 0xFFFF;
	
	TMH_COMPLETE_Method();

}
#endif

/********************************************************************************
  @brief    Pen calculate delta process
  @return   None
  */
#ifdef CalculateDeltaLocalSearch_OPCODE
void TMH_PenCalDelta (
    uint16_t        			 *pRawImg,      			 /**< input raw data buffer pointer */
    uint16_t       				 *pBaseImg,     			 /**< input base data buffer pointer */
	int16_t      			     *pDeltaImg,     			 /**< output delta data buffer pointer */
	int16_t       				 *pLocalSearchImg,     		 /**< output local search data buffer pointer */
	uint16_t     			     *pRingRawImg,     			 /**< output ring raw data buffer pointer */
	int16_t       				 *pRingDeltaImg,    	 	 /**< output ring delta data buffer pointer */
	uint8_t         			 *pLabelImg,     		 	 /**< output label data buffer pointer */
	tAlgorithmPenCalcDeltaConf_t *pTPenCalcDeltaSetVal,      /**< output calc delta info pointer */
	tOrigDeltaInfo_t		     *pTDeltaInfo,				 /**< output delta info pointer */
	int							  mode
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_pendelta>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pDeltaImg>>16;
	
	DSP_CON->TDSP_REGC0 = (uint32_t)((thisInfo->PenCalcDeltaSetVal.start_r<<8) | thisInfo->PenCalcDeltaSetVal.end_r);  	// row loop
	DSP_CON->TDSP_REGC1 = (uint32_t)((thisInfo->PenCalcDeltaSetVal.start_c<<8) | thisInfo->PenCalcDeltaSetVal.end_c);  	// col loop	
	DSP_CON->TDSP_REGA0 = (uint32_t)pRawImg;
	DSP_CON->TDSP_REGA1 = (uint32_t)pBaseImg;
	DSP_CON->TDSP_REGA2 = (uint32_t)pDeltaImg;
	DSP_CON->TDSP_REGA3 = (uint32_t)pLocalSearchImg;
	DSP_CON->TDSP_REGA4 = (uint32_t)pRingRawImg;
	DSP_CON->TDSP_REGA5 = (uint32_t)pRingDeltaImg;
	DSP_CON->TDSP_REGA6 = (uint32_t)LOCALNOISEBUF1;
	DSP_CON->TDSP_REGA7 = (uint32_t)LOCALNOISEBUF2;
	DSP_CON->TDSP_REGB0 = (uint32_t)pLabelImg;
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
	DSP_CON->TDSP_REGB1 = (uint32_t)ulZeroFingerRawMaskInfo;
#endif
	DSP_CON->TDSP_REGB2 = (uint32_t)pTPenCalcDeltaSetVal;
	DSP_CON->TDSP_REGB3 = (uint32_t)pTDeltaInfo;
	DSP_CON->TDSP_REGB4 = (uint32_t)mode; // Temp
	DSP_CON->TDSP_REGC7 = (uint32_t)thisInfo->PenCalcDeltaSetVal.gAlgoRawDataType;
	
	DSP_CON->TDSP_PC = ((uint32_t)opcode_pendelta) & 0xFFFF; // opcode_linefilter;

	TMH_COMPLETE_Method();
}
#endif
//void TMH_PenCalDelta (
//    uint16_t        *pRawImg,       /**< input raw data buffer pointer */
//    uint16_t        *pBaseImg,      /**< input base data buffer pointer */
//    uint8_t         *pNormalTbl,    /**< input normalize look-up table data buffer pointer */
//    int16_t         *pDeltaImg,     /**< output delta data buffer pointer */
//    tOrigDeltaInfo_t *pPenDeltaInfo, /**< output pen delta info buffer pointer */
//    int             nCurrRowStart,  /**< start current row */
//    int             nCurrColStart,  /**< start current column */
//    int             nWidth,         /**< width */
//    int             nHeight,        /**< height */
//    bool_t            bNormalize,     /**< normalize flag */
//    uint8_t         ucOvrShift,     /**< delta OvrShift */
//    uint16_t        usSeedBase,     /**< label seed base threshold */
//    uint8_t         ucMuxRowSize,   /**< mux row size */
//    uint8_t         ucPadSize       /**< pad size */
//)
//{
//	REG_TDSP2_C0 = (uint32_t)nHeight;
//	REG_TDSP2_C1 = (uint32_t)nWidth;
//	REG_TDSP2_A0 = (uint32_t)pRawImg;
//	REG_TDSP2_A1 = (uint32_t)pBaseImg;
//	REG_TDSP2_A2 = (uint32_t)pNormalTbl;
//	REG_TDSP2_A3 = (uint32_t)pDeltaImg;
//	REG_TDSP2_A4 = (uint32_t)nCurrRowStart;
//	REG_TDSP2_A5 = (uint32_t)nCurrColStart;
//	REG_TDSP2_A6 = (uint32_t)bNormalize;
//	REG_TDSP2_A7 = (uint32_t)ucOvrShift;
//	REG_TDSP2_B0 = (uint32_t)usSeedBase;
//	REG_TDSP2_B1 = (uint32_t)ucMuxRowSize;
//	REG_TDSP2_B2 = (uint32_t)ucPadSize;
//	REG_TDSP2_B3 = (uint32_t)pPenDeltaInfo;
//	REG_TDSP2_PC = (uint32_t)opcode_pendelta;        // start
//
//	TMH_COMPLETE_Method();
//    
//    if(REG_TDSP2_B2 != 0)
//    {
//        currentRowStart = REG_TDSP2_A6;
////        currentRowEnd = REG_TDSP2_A7;
//        pPenDeltaInfo->ucCurrentColumnStart = REG_TDSP2_A4;
//        pPenDeltaInfo->ucCurrentColumnEnd = REG_TDSP2_A5;
//    }
//}

/********************************************************************************
  @brief    Pen Noise Reduction
  @return   None
  */
void TMH_PenNoiseReduction (
    int16_t         *pDeltaImg,      /**< input delta data buffer pointer */
    tOrigDeltaInfo_t *pPenDeltaInfo, /**< input pen delta info buffer pointer */
    tPenInfo_t *pPenInfo, 			 /**< input pen info buffer pointer */
	int             mode,      		 /**< pen mode */
	int             nStart_r,     	 /**< start row */
    int             nEnd_r,          /**< end row */
    int             nStart_c,        /**< start column */
    int             nEnd_c,        	 /**< end column */
	int8_t          InitVal,         /**< initial value */
	uint8_t			PenFingerLineNoiseSize,
	bool_t 			bNoiseReductionOff
)
{	
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_pennoise>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pDeltaImg>>16;
	
	DSP_CON->TDSP_REGC0 = (uint32_t)((nStart_c<<8) | nEnd_c);  	// col loop
	DSP_CON->TDSP_REGC1 = (uint32_t)((nStart_r<<8) | nEnd_r);  	// row loop
	DSP_CON->TDSP_REGA0 = (uint32_t)pDeltaImg; 				  	// delta img addr.
	DSP_CON->TDSP_REGA1 = (uint32_t)pPenDeltaInfo;
	DSP_CON->TDSP_REGA2 = (uint32_t)pPenInfo;
	DSP_CON->TDSP_REGA3 = (uint32_t)thisInfo->bTouchExpect_local;
	DSP_CON->TDSP_REGA4 = (uint32_t)g_RetVal;
	DSP_CON->TDSP_REGA5 = (uint32_t)mode;
	DSP_CON->TDSP_REGA6 = (uint32_t)COL_MAX - 1;	
	DSP_CON->TDSP_REGC2 = (uint32_t)thisModeConf->Label.usLocalSeedBase;
	DSP_CON->TDSP_REGC3 = (uint32_t)InitVal;
	DSP_CON->TDSP_REGC4 = (uint32_t)thisInfo->tPenInfo.cRing_PreMaxR;
	DSP_CON->TDSP_REGC5 = (uint32_t)thisInfo->tPenInfo.cRing_PreMaxC;
	DSP_CON->TDSP_REGC6 = (uint32_t)thisInfo->tPenInfo.cPreMaxR;
	DSP_CON->TDSP_REGC7 = (uint32_t)thisInfo->tPenInfo.cPreMaxC;
	DSP_CON->TDSP_REGA7 = (uint32_t)PenFingerLineNoiseSize;
	DSP_CON->TDSP_REGB0 = (uint32_t)bNoiseReductionOff;
	DSP_CON->TDSP_PC =    (uint32_t)opcode_pennoise;               // opcode_pennoise;		// start

	TMH_COMPLETE_Method();
}

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
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_labelproc>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pSrc>>16;
	
	DSP_CON->TDSP_REGC0 = (uint32_t)((nStart_r<<8) | nEnd_r);   // row loop
	DSP_CON->TDSP_REGC1 = (uint32_t)((nStart_c<<8) | nEnd_c);   // column loop
	DSP_CON->TDSP_REGA0 = (uint32_t)pSrc;		               		 // binary addr.
	DSP_CON->TDSP_REGA1 = (uint32_t)pMap; 				        // label result addr.
	DSP_CON->TDSP_REGA2 = (uint32_t)pTLabelInfo; 				// label info addr.
	DSP_CON->TDSP_REGA3 = (uint32_t)nThreshold;
	DSP_CON->TDSP_REGA4 = (uint32_t)nEnd_r;
	DSP_CON->TDSP_REGA5 = (uint32_t)nStart_r;
	DSP_CON->TDSP_REGA6 = (uint32_t)nEnd_c;
	DSP_CON->TDSP_REGA7 = (uint32_t)nStart_c;
	DSP_CON->TDSP_REGB1 = (uint32_t)ucPadSize;
	DSP_CON->TDSP_REGC2 = (uint32_t)(thisInfo->bTouchExpect_local);
	DSP_CON->TDSP_PC    = (uint32_t)opcode_labelproc;           //opcode_label;		// start

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
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_markboundary>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pLabel>>16;
	
    DSP_CON->TDSP_REGC0 = (uint32_t)((nStart_r<<8) | nEnd_r);   // row loop
    DSP_CON->TDSP_REGC1 = (uint32_t)((nStart_c<<8) | nEnd_c);   // column loop
    DSP_CON->TDSP_REGA0 = ((uint32_t)pLabel) & 0xFFFF;
    DSP_CON->TDSP_REGA1 = ((uint32_t)pDelta) & 0xFFFF;
    DSP_CON->TDSP_REGA2 = ((uint32_t)tTable) & 0xFFFF;
    DSP_CON->TDSP_REGA3 = (uint32_t)nTable_num;                 // 
//    DSP_CON->TDSP_REGA4 = (uint32_t)nStart_r;
//    DSP_CON->TDSP_REGA5 = (uint32_t)nEnd_r;
//    DSP_CON->TDSP_REGA6 = (uint32_t)nStart_c;
//    DSP_CON->TDSP_REGA7 = (uint32_t)nEnd_c;
    DSP_CON->TDSP_REGB1 = (uint32_t)ucPad_size;
    DSP_CON->TDSP_REGC2 = (uint32_t)Boundary;                   // 
    DSP_CON->TDSP_REGC3 = (uint32_t)LABEL_BOUNDARY_MARKER;      // Marker Value
    DSP_CON->TDSP_PC = ((uint32_t)opcode_markboundary) & 0xFFFF;

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
	tAlgorithmEdgePenConf_t *pTEdgePen,
	tHidTiltInfo_t *pTTiltInfo,
	int mode
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_coordproc>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = ((uint32_t)pTCoordInfo) & 0xFFFF;
	DSP_CON->TDSP_REGA1 = ((uint32_t)pTLabelInfo) & 0xFFFF;
	DSP_CON->TDSP_REGA2 = (uint32_t)POS_BOOST_SHIFT_;
	DSP_CON->TDSP_REGA3 = (uint32_t)COORD_HISTORY_NUM;
//	DSP_CON->TDSP_REGA4 = (uint32_t)(1<<thisModeConf->Coord.lMoveSmoothingLevel);
	DSP_CON->TDSP_REGA4 = (uint32_t)thisModeConf->PenCoord.uc_connect_count;		// connect_count
//	DSP_CON->TDSP_REGA5 = (uint32_t)(thisModeConf->Coord.lMoveSmoothingLevel);
	DSP_CON->TDSP_REGA5 = (uint32_t)pTTiltInfo;
	DSP_CON->TDSP_REGA6 = (uint32_t)thisInfo->tPenInfo.ucCoordiRowStart;            // ucCoordiRowStart
	DSP_CON->TDSP_REGB5 = (uint8_t)thisInfo->bLocal_sensing;
	DSP_CON->TDSP_REGB6 = (int8_t)thisInfo->tCoord_local_dsp.cIsbefor;
	DSP_CON->TDSP_REGB7 = (uint32_t)g_RetVal;
	DSP_CON->TDSP_REGC0 = (uint32_t)thisInfo->tCoord.iInternalXRes;  				// iInternalXRes
	DSP_CON->TDSP_REGC1 = (uint32_t)thisInfo->tCoord.iInternalYRes;  				// iInternalYRes
//	DSP_CON->TDSP_REGC2 = (uint32_t)thisInfo->tCoord.iXExpandStart;
//	DSP_CON->TDSP_REGC3 = (uint32_t)thisInfo->tCoord.iYExpandStart;
	DSP_CON->TDSP_REGC3 = ((uint32_t)pTEdgePen) & 0xFFFF; 
	DSP_CON->TDSP_REGC2 = (uint32_t)mode;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_coordproc) & 0xFFFF;

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
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_coordproc>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = ((uint32_t)pTCoordInfo) & 0xFFFF;
	DSP_CON->TDSP_REGA2 = (uint32_t)thisInfo->tCoord.iInternalXRes;
	DSP_CON->TDSP_REGA3 = (uint32_t)thisInfo->tCoord.iInternalYRes;
	DSP_CON->TDSP_REGA4 = (uint32_t)(1<<thisModeConf->Coord.lMoveSmoothingLevel);
	DSP_CON->TDSP_REGA5 = (uint32_t)(thisModeConf->Coord.lMoveSmoothingLevel);
	DSP_CON->TDSP_REGA6 = (uint32_t)thisInfo->tPenInfo.ucCoordiRowStart;                 // ucCoordiRowStart
//	DSP_CON->TDSP_REGC0 = (uint32_t)thisInfo->tCoord.iInternalXRes;  	// iInternalXRes
//	DSP_CON->TDSP_REGC1 = (uint32_t)thisInfo->tCoord.iInternalYRes;  	// iInternalYRes
//	DSP_CON->TDSP_REGC2 = (uint32_t)thisInfo->tCoord.iXExpandStart;
//	DSP_CON->TDSP_REGC3 = (uint32_t)thisInfo->tCoord.iYExpandStart;
	DSP_CON->TDSP_REGC2 = (uint32_t)mode;
	DSP_CON->TDSP_REGA1 = (int32_t)(thisModeConf->PenCoord.cHoverSmoothOffset);
	DSP_CON->TDSP_PC = ((uint32_t)opcode_smoothing) & 0xFFFF;

	TMH_COMPLETE_Method();

}
#endif

void TMH_PenDisBasedSmoothAdd (
    tPenCoordInfo_t *pTCoordInfo,   /**< output coord info buffer pointer */
	tAlgorithmDisBaseSmoothConf_t *SmoothSetVal,
	int mode,
	uint16_t EdgeRange
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_coordproc>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = (uint32_t)pTCoordInfo; 				   											// label info addr.
	DSP_CON->TDSP_REGA2 = (uint32_t)thisInfo->tCoord.iInternalXRes;
	DSP_CON->TDSP_REGA3 = (uint32_t)thisInfo->tCoord.iInternalYRes;
	DSP_CON->TDSP_REGA4 = (uint32_t)(1<<thisModeConf->Coord.lMoveSmoothingLevel);
	DSP_CON->TDSP_REGA5 = (uint32_t)(thisModeConf->Coord.lMoveSmoothingLevel);
	DSP_CON->TDSP_REGA6 = (uint32_t)thisInfo->tPenInfo.ucCoordiRowStart;                 // ucCoordiRowStart
	DSP_CON->TDSP_REGC0 = (uint32_t)EdgeRange;//(1<<(POS_BOOST_SHIFT_));
//	DSP_CON->TDSP_REGC1 = (uint32_t)thisInfo->tCoord.iInternalYRes;  	// iInternalYRes
//	DSP_CON->TDSP_REGC2 = (uint32_t)thisInfo->tCoord.iXExpandStart;
//	DSP_CON->TDSP_REGC3 = (uint32_t)thisInfo->tCoord.iYExpandStart;
	DSP_CON->TDSP_REGC3 = ((uint32_t)SmoothSetVal) & 0xFFFF; 
	DSP_CON->TDSP_REGC2 = (uint32_t)mode;
	DSP_CON->TDSP_PC    = (uint32_t)opcode_PenDisBasedSmoothAdd;               							// opcode_coord;		// start

	TMH_COMPLETE_Method();

}

void TMH_PenCoord_PostProcess (
    tPenCoordInfo_t *pTCoordInfo,   /**< output coord info buffer pointer */
	uint8_t ucPenPostProcessEdgeTH,
	uint8_t ucPenPostProcessDisTH,
	uint8_t ucPenPostProcessExpendDiv
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_coordpost>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = (uint32_t)pTCoordInfo;		            								// coord info addr.
	DSP_CON->TDSP_REGA1 = (uint32_t)thisInfo->tCoord.iInternalXRes;  	// iInternalXRes
	DSP_CON->TDSP_REGA2 = (uint32_t)thisInfo->tCoord.iInternalYRes;  	// iInternalYRes
	DSP_CON->TDSP_REGA3 = (uint32_t)thisModeConf->PenCoord.ucPenPostProcessDisTH;
	DSP_CON->TDSP_REGA4 = (uint32_t)(-thisModeConf->PenCoord.ucPenPostProcessDisTH);
	DSP_CON->TDSP_REGA5 = (uint32_t)thisModeConf->PenCoord.ucPenPostProcessExpendDiv;
	DSP_CON->TDSP_REGA6 = (uint32_t)(-thisModeConf->PenCoord.cPenPostProcessEndMargin);
	DSP_CON->TDSP_REGA7 = (uint32_t)(1<<thisModeConf->PenCoord.ucPenPostProcessEdgeTH);
	DSP_CON->TDSP_REGB0 = (uint32_t)HID_PEN_X;
	DSP_CON->TDSP_REGB1 = (uint32_t)HID_PEN_Y;
	DSP_CON->TDSP_REGB2 = (uint32_t)5;//thisModeConf->PenCoord.ucPenPostProcessXEdge;
	DSP_CON->TDSP_REGB3 = (uint32_t)(thisCommonConf->iXResolution - 5);//thisModeConf->PenCoord.ucPenPostProcessXEdge);
	DSP_CON->TDSP_REGB4 = (uint32_t)(thisCommonConf->iYResolution - 5);//thisModeConf->PenCoord.ucPenPostProcessXEdge);
	DSP_CON->TDSP_REGB5 = (uint32_t)thisInfo->tCoord_local_dsp.tAvgPos.y;	
	DSP_CON->TDSP_REGC5 = (uint32_t)(1<<POS_BOOST_SHIFT_);
	DSP_CON->TDSP_PC = ((uint32_t)opcode_coordpost) & 0xFFFF;

	TMH_COMPLETE_Method();
}

/********************************************************************************
  @brief    Pen Coordinate Buffer Initialize Function
  @return   None
  */
void TMH_PenCoordInitialize(tPenCoordInfo_t *pTCoordInfo, tOrigDeltaInfo_t *pPenDeltaInfo)
{	
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_coordinit>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = ((uint32_t)pTCoordInfo) & 0xFFFF;
	DSP_CON->TDSP_REGA1 = ((uint32_t)pPenDeltaInfo) & 0xFFFF;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_coordinit) & 0xFFFF;
    
	TMH_COMPLETE_Method();
}

/********************************************************************************
  @brief    Pen Coordinate Info Update Function
  @return   None
  */
void TMH_PenUpdatePostHistoryInfo(tPenCoordInfo_t *pTCoordInfo)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_updateproc>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = ((uint32_t)pTCoordInfo) & 0xFFFF;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_updateproc) & 0xFFFF;
    
	TMH_COMPLETE_Method();
}

/********************************************************************************
  @brief    Pen Labeling Edge Expand
  @return   None
  */
extern tRingMSInfo_t pTRingInfo;
void Pre_TMH_PenLabelEdgeExpand_DeltaBase(
    tPenLabelInfo_t *pTLabelInfo,   //< output label info buffer pointer */
//	tAlgorithmPenEdgeExpand_t 	*pTPenParaEdge,	//< input pen edge info pointer */
//    int32_t         nStart_r,       //< start row 
//    int32_t         nEnd_r,         //< end row 
//    int32_t         nStart_c,       //< start column 
//    int32_t         nEnd_c,         //< end column 
	int				mode,			//< mode
	int TiltMode
)
{
//	int r, c;
	int check_r, check_c;
	int search_r = -10, search_c = -10, search_c1,search_r1;
	int apply_r, apply_c;
//	int _d,_d1,_d2,mul,sr,mul1,sr1,max_sum;
	
	//Arrange EdgeExpand parameter
	memcpy(&thisInfo->PenEdgeExpandSetVal,&thisModeConf->PenParaEdgeSetVal,sizeof(tAlgorithmPenParaEdgeConf_t));
	thisInfo->PenEdgeExpandSetVal.PenInfo_ucHover_cnt = thisInfo->tPenInfo.ucHover_cnt;
	thisInfo->PenEdgeExpandSetVal.Label_ucHoverOutCheckFrm = thisModeConf->Label.ucHoverOutCheckFrm;
	thisInfo->PenEdgeExpandSetVal.TiltOn = TiltMode;//Tilt_On;
	thisInfo->PenEdgeExpandSetVal.ScreenRow_1 = ROW_MAX-1;
	thisInfo->PenEdgeExpandSetVal.ScreenCol_1 = COL_MAX-1;
	thisInfo->PenEdgeExpandSetVal.PenPostProcessFlag = thisInfo->tPenInfo.bPenPostProcessFlag;
	thisInfo->PenEdgeExpandSetVal.ForcePenContactFlag = thisInfo->tPenInfo.bForcePenContactFlag;
	thisInfo->PenEdgeExpandSetVal.RetVal = g_RetVal;
	thisInfo->PenEdgeExpandSetVal.PenInfo_ucHover_cnt = thisInfo->tPenInfo.ucHover_cnt;
	thisInfo->PenEdgeExpandSetVal.Label_ucHoverOutCheckFrm = thisModeConf->Label.ucHoverOutCheckFrm;
    thisInfo->PenEdgeExpandSetVal.HID_TILT_X = thisInfo->tTiltInfo.HID_TILT_X;
    thisInfo->PenEdgeExpandSetVal.HID_TILT_Y = thisInfo->tTiltInfo.HID_TILT_Y;
    thisInfo->PenEdgeExpandSetVal.HID_TILT_TH1 = 8000;
    thisInfo->PenEdgeExpandSetVal.HID_TILT_TH2 = 10000;
	
	tAlgorithmPenEdgeExpand_t 	*pTPenParaEdge = &thisInfo->PenEdgeExpandSetVal;
	
	pTPenParaEdge->RunTMHPenEdgeExpand = NO;
	
	if(mode == LOCAL_RING_MODE)
	{
		thisInfo->tTiltInfo.sRing_ExtStrength = thisInfo->tLabel_local_dsp.ulExtStrength;
	}
	else if((mode == LOCAL_MODE || mode == LOCAL_HOVER_MODE) && (thisInfo->tPenInfo.bPenPostProcessFlag==0 && thisInfo->tPenInfo.bForcePenContactFlag==0))
	{
		pTPenParaEdge->RunTMHPenEdgeExpand = YES;
		
//		if((g_RetVal==PARTIAL_PEN_COORD3) && TiltMode == 2) thisInfo->tTiltInfo.sRing_ExtStrength = pTRingInfo.ulStrength;
		
		check_r = thisInfo->tLabel_local_dsp.tValidMaxPos.r + thisInfo->tPenInfo.ucCoordiRowStart;
		check_c = thisInfo->tLabel_local_dsp.tValidMaxPos.c;
		
		if( (check_r == 0 && mode == LOCAL_MODE) || (check_r <= 1 && mode == LOCAL_HOVER_MODE) )
		{
			search_r = 0, apply_r = check_r-1, search_r1 = 1;
			
			pTPenParaEdge->mul0 = pTPenParaEdge->top_mul0;
			pTPenParaEdge->sr0 = pTPenParaEdge->top_SR0;
			pTPenParaEdge->mul1 = pTPenParaEdge->top_mul1; 
			pTPenParaEdge->sr1 = pTPenParaEdge->top_SR1;
			if(mode == LOCAL_MODE)			
				pTPenParaEdge->max_sum = pTPenParaEdge->top_max_sum;
			else
				pTPenParaEdge->max_sum = pTPenParaEdge->top_max_sum_hover;
		}
		else if((check_r == ROW_MAX-1 && mode == LOCAL_MODE) || (check_r >= ROW_MAX-2 && mode == LOCAL_HOVER_MODE) )
		{
			search_r = ROW_MAX-MUX_MAX_ROW-1, apply_r = ROW_MAX-MUX_MAX_ROW-(ROW_MAX-1 - check_r), search_r1 = ROW_MAX-MUX_MAX_ROW-2;
			pTPenParaEdge->mul0 =  pTPenParaEdge->bottom_mul0;
			pTPenParaEdge->sr0 =   pTPenParaEdge->bottom_SR0;
			pTPenParaEdge->mul1 =  pTPenParaEdge->bottom_mul1;
			pTPenParaEdge->sr1 =   pTPenParaEdge->bottom_SR1;
			if(mode == LOCAL_MODE)
				pTPenParaEdge->max_sum = pTPenParaEdge->bottom_max_sum;
			else
				pTPenParaEdge->max_sum = pTPenParaEdge->bottom_max_sum_hover;
		}
		
		if( (check_c == 0 && mode == LOCAL_MODE) || (check_c <= 1 && mode == LOCAL_HOVER_MODE) )
		{
			search_c = 0;
			apply_c = check_c-1;
			search_c1 = 1;
			pTPenParaEdge->mul0_LR =  pTPenParaEdge->left_mul0;
			pTPenParaEdge->sr0_LR =   pTPenParaEdge->left_SR0;
			pTPenParaEdge->mul1_LR =  pTPenParaEdge->left_mul1;
			pTPenParaEdge->sr1_LR =   pTPenParaEdge->left_SR1;
			if(mode == LOCAL_MODE)
				pTPenParaEdge->max_sum_LR = pTPenParaEdge->left_max_sum;
			else
				pTPenParaEdge->max_sum_LR = pTPenParaEdge->left_max_sum_hover;
		}
		else if( (check_c == COL_MAX-1 && mode == LOCAL_MODE) || (check_c >= COL_MAX-2 && mode == LOCAL_HOVER_MODE) )
		{
			search_c = COL_MAX-1;
			apply_c = COL_MAX- (COL_MAX-1 - check_c); 
			search_c1 = COL_MAX-2;
			pTPenParaEdge->mul0_LR =  pTPenParaEdge->right_mul0;
			pTPenParaEdge->sr0_LR =   pTPenParaEdge->right_SR0;
			pTPenParaEdge->mul1_LR =  pTPenParaEdge->right_mul1;
			pTPenParaEdge->sr1_LR =   pTPenParaEdge->right_SR1;
			if(mode == LOCAL_MODE)			
				pTPenParaEdge->max_sum_LR = pTPenParaEdge->right_max_sum;
			else
				pTPenParaEdge->max_sum_LR = pTPenParaEdge->right_max_sum_hover;
		}
		
		pTPenParaEdge->search_r  = (int8_t)(search_r + PAD_);
		pTPenParaEdge->search_r1 = (int8_t)(search_r1 + PAD_);
		pTPenParaEdge->apply_r   = (int8_t)(apply_r);
		pTPenParaEdge->search_c  = (int8_t)(search_c + PAD_);
		pTPenParaEdge->search_c1 = (int8_t)(search_c1 + PAD_);
		pTPenParaEdge->apply_c   = (int8_t)(apply_c);

//		if(search_r != -1)	//up,down edge
//		{	
//		
//		}
//		
//		if(search_c != -1)		//left,right edge
//		{
//			
//		}
	}
	
	pTPenParaEdge->Ring_ExtStrength = thisInfo->tTiltInfo.sRing_ExtStrength;
	if(thisInfo->tLabel_local_dsp.ulExtStrength <= 0)	thisInfo->tLabel_local_dsp.ulExtStrength = 1;
	
}
void TMH_PenLabelEdgeExpand_DeltaBase(
    int16_t        	*pSrc,          //< input data buffer pointer */
    uint8_t         *pMap,          //< input map data buffer pointer */
    tPenLabelInfo_t *pTLabelInfo,   //< output label info buffer pointer */
	tAlgorithmPenEdgeExpand_t 	*pTPenParaEdge,	//< input pen edge info pointer */
    int32_t         nStart_r,       //< start row 
    int32_t         nEnd_r,         //< end row 
    int32_t         nStart_c,       //< start column 
    int32_t         nEnd_c,         //< end column 
	int				mode			//< mode
)
{
	
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_labeledgeexpand_deltabase>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pSrc>>16;

	DSP_CON->TDSP_REGC0 = (uint32_t)((nStart_r<<8) | nEnd_r);   // row loop
	DSP_CON->TDSP_REGC1 = (uint32_t)((nStart_c<<8) | nEnd_c);   // column loop
	//C2 : Loop count Reg2
	DSP_CON->TDSP_REGA0 = (uint32_t)pSrc;		               	// binary addr.
	DSP_CON->TDSP_REGA1 = (uint32_t)pMap; 				        // label result addr.
	DSP_CON->TDSP_REGA2 = (uint32_t)pTLabelInfo; 				// label info addr.
	DSP_CON->TDSP_REGA3 = (uint32_t)pTPenParaEdge;	
	DSP_CON->TDSP_REGA4 = (uint32_t)mode;
	DSP_CON->TDSP_REGA5 = (uint32_t)thisInfo->tTiltInfo.sRing_ExtStrength;
	DSP_CON->TDSP_REGA6 = (uint32_t)0;	
	DSP_CON->TDSP_REGA7 = (uint32_t)pTPenParaEdge->RunTMHPenEdgeExpand;
	DSP_CON->TDSP_REGB0 = (uint32_t)0;	//c; 	
	DSP_CON->TDSP_REGB1 = (uint32_t)0;	//EdgeStrength;								
	DSP_CON->TDSP_REGB2 = (uint32_t)thisInfo->tTiltInfo.sRingTipStrengthRatio;												
	DSP_CON->TDSP_REGB3 = (uint32_t)pTPenParaEdge->search_r;
	DSP_CON->TDSP_REGB4	= (uint32_t)pTPenParaEdge->search_c;																
	DSP_CON->TDSP_REGB5	= (uint32_t)pTPenParaEdge->search_r1;	
	DSP_CON->TDSP_REGB6	= (uint32_t)0;																				
	DSP_CON->TDSP_REGB7	= (uint32_t)0;																			
//C2 ~ C4 : reserved
	DSP_CON->TDSP_REGC2 = (uint32_t)0;
	DSP_CON->TDSP_REGC3 = (uint32_t)0;
	DSP_CON->TDSP_REGC4 = (uint32_t)0;
	DSP_CON->TDSP_REGC5 = (uint32_t)thisInfo->tLabel_local_dsp.tCoord.x;
	DSP_CON->TDSP_REGC6 = (uint32_t)thisInfo->tLabel_local_dsp.tCoord.y;
	DSP_CON->TDSP_REGC7 = (uint32_t)thisInfo->tLabel_local_dsp.ulExtStrength;
	DSP_CON->TDSP_PC    = (uint32_t)opcode_labeledgeexpand_deltabase;        //opcode_label;		// start

	TMH_COMPLETE_Method();
}

#if 0
void TMH_PenLabelEdgeExpand(
    int16_t        	*pSrc,          //< input data buffer pointer */
    uint8_t         *pMap,          //< input map data buffer pointer */
    tPenLabelInfo_t *pTLabelInfo,   //< output label info buffer pointer */
	tAlgorithmEdgePenConf_t *pTEdgePen,		//< input pen edge info pointer */
    int32_t         nStart_r,       //< start row 
    int32_t         nEnd_r,         //< end row 
    int32_t         nStart_c,       //< start column 
    int32_t         nEnd_c,         //< end column 
    uint8_t         ucPadSize,      //< pad size
	int				mode			//< mode
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_labeledgeexpand>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pSrc>>16;
	
	DSP_CON->TDSP_REGC0 = (uint32_t)((nStart_r<<8) | nEnd_r);   // row loop
	DSP_CON->TDSP_REGC1 = (uint32_t)((nStart_c<<8) | nEnd_c);   // column loop
	DSP_CON->TDSP_REGA0 = ((uint32_t)pSrc) & 0xFFFF;
	DSP_CON->TDSP_REGA1 = ((uint32_t)pMap) & 0xFFFF;
	DSP_CON->TDSP_REGA2 = ((uint32_t)pTLabelInfo) & 0xFFFF;
	DSP_CON->TDSP_REGA3 = (uint32_t)pTEdgePen;
	DSP_CON->TDSP_REGA4 = (uint32_t)(pTLabelInfo->tValidMaxPos.r + thisInfo->tPenInfo.ucCoordiRowStart);
	DSP_CON->TDSP_REGA5 = (uint32_t)pTLabelInfo->tValidMaxPos.c;
	DSP_CON->TDSP_REGA6 = (uint32_t)ROW_MAX-2;
	DSP_CON->TDSP_REGA7 = (uint32_t)COL_MAX-2;
	DSP_CON->TDSP_REGB0 = (uint32_t)256;
//	DSP_CON->TDSP_REGB1 = (uint32_t)ucPadSize;
	DSP_CON->TDSP_REGB1 = (uint32_t)mode;
	DSP_CON->TDSP_REGB2 = (uint32_t)pTLabelInfo->tCoord.x;
	DSP_CON->TDSP_REGB3 = (uint32_t)pTLabelInfo->tCoord.y;
	DSP_CON->TDSP_REGB4 = (uint32_t)pTLabelInfo->ulExtStrength;
	DSP_CON->TDSP_REGB5 = (uint32_t)ROW_MAX-MUX_MAX_ROW-1;
//	DSP_CON->TDSP_REGB6 = (uint32_t)mode;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_labeledgeexpand) & 0xFFFF;

	TMH_COMPLETE_Method();

}
#endif

/********************************************************************************
  @brief    Pen Sleep Function
  @return   None
  */

void TMH_PenSleep (
	int iIterationNum	/**< iteration number */
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_penSleep>>16;
	
	DSP_CON->TDSP_REGC0 = (uint32_t)iIterationNum;
	DSP_CON->TDSP_PC = ((uint32_t)opcode_penSleep) & 0xFFFF;

}

/********************************************************************************
  @brief    Pen Tilt Function
  @return   None
  */
#ifdef TILT_OPCODE
void TMH_PenTilt_Step1(
    uint8_t        *ArcSinLUT,       
	uint8_t 		*CosLUT,
    tPenCoordInfo_t *pTCoordInfo,      
	tHidTiltInfo_t *pTTiltInfo,
	uint8_t L
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_tilt_step1>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)ArcSinLUT>>16;
	
    DSP_CON->TDSP_REGA1 = (uint32_t)ArcSinLUT; 			// ArcSinLookUpTable addr.
	DSP_CON->TDSP_REGA2 = (uint32_t)CosLUT;             // CosLookUpTable addr
    DSP_CON->TDSP_REGA0 = (uint32_t)pTCoordInfo;        // CoordInfo addr
	DSP_CON->TDSP_REGA3 = (uint32_t)pTTiltInfo;
#if (TiltArcSinLookUp_Num > 3)
	if(thisModeConf->PenTilt.bArcSinLookUp_1==3)
	{
		DSP_CON->TDSP_REGA4 = (uint32_t)(((FPITCH_X*128)/UNIT_DIST) * 127); //243 //202; // mm scale offset X : 1.593 * 127
		DSP_CON->TDSP_REGA5 = (uint32_t)(((FPITCH_Y*128)/UNIT_DIST) * 127); //241 //205; // mm scale offset Y : 1.613 * 127
	}
	else
	{
		DSP_CON->TDSP_REGA4 = (uint32_t)(((FPITCH_X*100)/UNIT_DIST) * 127); //243 //202; // mm scale offset X : 1.593 * 127
		DSP_CON->TDSP_REGA5 = (uint32_t)(((FPITCH_Y*100)/UNIT_DIST) * 127); //241 //205; // mm scale offset Y : 1.613 * 127
	}
	DSP_CON->TDSP_REGC0 = (uint32_t)thisModeConf->PenTilt.bArcSinLookUp_1;
#elif (TiltArcSinLookUp_Num == 3)
	DSP_CON->TDSP_REGA4 = (uint32_t)(((FPITCH_X*128)/UNIT_DIST) * 127); //243 //202; // mm scale offset X : 1.593 * 127
	DSP_CON->TDSP_REGA5 = (uint32_t)(((FPITCH_Y*128)/UNIT_DIST) * 127); //241 //205; // mm scale offset Y : 1.613 * 127
	DSP_CON->TDSP_REGC0 = (uint32_t)3;//thisModeConf->PenTilt.bArcSinLookUp_1;
#else
	DSP_CON->TDSP_REGA4 = (uint32_t)(((FPITCH_X*100)/UNIT_DIST) * 127); //243 //202; // mm scale offset X : 1.593 * 127
	DSP_CON->TDSP_REGA5 = (uint32_t)(((FPITCH_Y*100)/UNIT_DIST) * 127); //241 //205; // mm scale offset Y : 1.613 * 127
	DSP_CON->TDSP_REGC0 = (uint32_t)0;//thisModeConf->PenTilt.bArcSinLookUp_1;
#endif	
	DSP_CON->TDSP_REGA6 = (uint32_t)L; 		// L : real L * 10
	DSP_CON->TDSP_REGA7 = (uint32_t)thisInfo->tCoord_local_dsp.tAvgPos.y; // tilt calculation condition
//	DSP_CON->TDSP_REGC0 = (uint32_t)thisModeConf->PenTilt.bArcSinLookUp_1;
#if (TiltAdjustEn == YES)
	DSP_CON->TDSP_REGC1 = (uint32_t)thisModeConf->PenTilt.ucTiltAdjustEn;
	DSP_CON->TDSP_REGC2 = (uint32_t)(((128*L)/10)-1);
	DSP_CON->TDSP_REGC3 = (uint32_t)sxMLookUpTable;
	DSP_CON->TDSP_REGC4 = (uint32_t)sxPLookUpTable;
	DSP_CON->TDSP_REGC5 = (uint32_t)syMLookUpTable;
	DSP_CON->TDSP_REGC6 = (uint32_t)syPLookUpTable;
#endif
    DSP_CON->TDSP_PC = (uint32_t)opcode_tilt_step1;        //opcode_tilt

	TMH_COMPLETE_Method();
}

void TMH_PenTilt_Step2(
    uint16_t        *ArcTanLUT,         //< input LUT buffer pointer
	tHidTiltInfo_t *pTTiltInfo,
	int32_t	diff_x,
	int32_t	diff_y,
	uint8_t mode
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_tilt_step2>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)ArcTanLUT>>16;
	
	//DSP_CON->TDSP_REGA0 = (uint16_t)pTCoordInfo;        // CoordInfo addr
    DSP_CON->TDSP_REGA1 = (uint32_t)ArcTanLUT; 			// ArcTanLookUpTable addr.
	DSP_CON->TDSP_REGA2 = (uint32_t)pTTiltInfo;			// Tilt info addr
	DSP_CON->TDSP_REGA3 = (int32_t)diff_x;  			// input x          
	DSP_CON->TDSP_REGA4 = (int32_t)diff_y; 				// input y
	DSP_CON->TDSP_REGA5 = (uint32_t)mode; 				// outmode : 5=tilt_x,6=tilt_y,8=azimuth
	DSP_CON->TDSP_REGA7 = (uint32_t)thisInfo->tCoord_local_dsp.tAvgPos.y; // tilt calculation condition
    DSP_CON->TDSP_PC = (uint32_t)opcode_tilt_step2;        //opcode_tilt

	TMH_COMPLETE_Method();
}

void TMH_PenTilt_Step3(
	tHidTiltInfo_t *pTTiltInfo,
	tPenLabelInfo_t *pTLabelInfo,
	tPenCoordInfo_t *pTCoordInfo,
	int ucTiltSmoothingFilterCoef
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_tilt_step3>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTTiltInfo>>16;
	
	DSP_CON->TDSP_REGA0 = (uint32_t)pTTiltInfo;			// Tilt info addr
	DSP_CON->TDSP_REGA1 = (uint32_t)thisInfo->tTiltInfo.sTilt_cnt;			// Tilt count
	DSP_CON->TDSP_REGA2 = (uint32_t)ucTiltSmoothingFilterCoef; // Smoothing Filter Coefficient (Max : 32)
	DSP_CON->TDSP_REGA7 = (uint32_t)thisInfo->tCoord_local_dsp.tAvgPos.y; // tilt calculation condition
	DSP_CON->TDSP_REGB5 = (uint32_t)pTLabelInfo;		// Label info addr
#if (TILT_EDGE_FILTER == YES)
	DSP_CON->TDSP_REGB6 = (uint32_t)(UNIT_DIST<<1);												// Edge Filter X start TH
	DSP_CON->TDSP_REGB7 = (uint32_t)thisInfo->tCoord.iInternalXRes-(UNIT_DIST<<1);				// Edge Filter X end TH
	DSP_CON->TDSP_REGC0 = (uint32_t)(UNIT_DIST<<1);												// Edge Filter Y start TH
	DSP_CON->TDSP_REGC1 = (uint32_t)thisInfo->tCoord.iInternalYRes-(UNIT_DIST<<1);              // Edge Filter Y end TH
#endif
	DSP_CON->TDSP_REGC2 = (uint32_t)pTCoordInfo;		// Coordi info addr
	DSP_CON->TDSP_REGC3 = (uint32_t)thisModeConf->PenTilt.ucHalfCoefSmoothFrm;
	DSP_CON->TDSP_REGC4 = (uint32_t)thisModeConf->PenTilt.ucHalfCoef;
#if (TILT_AREA_FILTER == YES)
	DSP_CON->TDSP_REGA5 = (uint32_t)thisModeConf->PenTilt.usTilt_Change_TH_Reverse;		// Area Filter Status Change TH
	DSP_CON->TDSP_REGC5 = (uint32_t)thisModeConf->PenTilt.usTilt_Change_TH_Right;		// Area Filter Status Change TH
	DSP_CON->TDSP_REGC6 = (int32_t)-thisModeConf->PenTilt.usTilt_Change_TH_Right;
#endif
    DSP_CON->TDSP_PC = (uint32_t)opcode_tilt_step3;        //opcode_tilt

	TMH_COMPLETE_Method();
}

void TMH_PenTilt_Step4(
	 tPenCoordInfo_t *pTCoordInfo
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_tilt_step4>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = (uint32_t)pTCoordInfo;			// CoordInfo info addr
	DSP_CON->TDSP_REGA5 = (uint32_t)thisInfo->tTiltInfo.sTilt_cnt;				// Tilt count
	DSP_CON->TDSP_REGA6 = (uint32_t)thisInfo->tCoord_local_dsp.tAvgPos.x; // Postprocess condition
	DSP_CON->TDSP_REGA7 = (uint32_t)thisInfo->tCoord_local_dsp.tAvgPos.y; // tilt calculation condition
    DSP_CON->TDSP_PC = (uint32_t)opcode_tilt_step4;        //opcode_tilt

	TMH_COMPLETE_Method();
}

void TMH_PenTilt_Step0(
	 tPenCoordInfo_t *pTCoordInfo
)
{
	DSP_CON->TDSP_BASEADD = (uint32_t)opcode_tilt_step0>>16;
	DSP_CON->TDSP_DMA_ADD = (uint32_t)pTCoordInfo>>16;
	
	DSP_CON->TDSP_REGA0 = (uint32_t)pTCoordInfo;			// CoordInfo info addr
	DSP_CON->TDSP_REGA5 = (uint32_t)thisInfo->tTiltInfo.sTilt_cnt;				// Tilt count
	DSP_CON->TDSP_REGA6 = (uint32_t)thisInfo->tCoord_local_dsp.tAvgPos.x; // Postprocess condition
	DSP_CON->TDSP_REGA7 = (uint32_t)thisInfo->tCoord_local_dsp.tAvgPos.y; // tilt calculation condition
    DSP_CON->TDSP_PC = (uint32_t)opcode_tilt_step0;        //opcode_tilt

	TMH_COMPLETE_Method();
}
#endif

#if 0
#define JITTER_MAX 30
uint8_t jitter_start, jitter_idx;
int jitter_max_val = -1;
tXY_t jitter_buff[JITTER_MAX];
tXY_t test_idx;

void algorithm_jitter_cal(tXY_t pos)
{
	if(jitter_start == 0)
	{
		jitter_idx = 0, jitter_max_val = -1;
		memset(jitter_buff, 0, sizeof(jitter_buff));
	}

	// Jitter
	if(jitter_start)
	{
		if(jitter_idx < JITTER_MAX)
		{         
			jitter_buff[jitter_idx].x = (int)(((float)pos.x/(float)32767)*(float)293760);
			jitter_buff[jitter_idx].y = (int)(((float)pos.y/(float)32767)*(float)165240);
			jitter_idx++;
		}
		else if(jitter_idx == JITTER_MAX)
		{
			 int i, j, dist;
			 for(i=0; i<JITTER_MAX-1; i++)
			 {
				 for(j=i+1; j<JITTER_MAX; j++)
				 {
					 dist = algorithm_coord_calc_distance(jitter_buff[i], jitter_buff[j]);
					 if(dist > jitter_max_val)
					 {
						 jitter_max_val = dist;
						 test_idx.x = i;
						 test_idx.y = j;
					 }
				 }
			 }
			 jitter_idx++;
		}
	}
}
#endif

extern int HID_status[];
extern int HID_x[];
extern int HID_y[];

extern void protocol_hid_PushPenEvent(const uSWIPTouchItem_t* _kptItem);
//extern uint8_t	g_ConnectedDevice;
void algorithm_PendPenEventforDSP(int mode)
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


	//if(g_ConnectedDevice == I2C_CONNECT_PC)
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
	touchItemType.active_stylus_hover = YES;
	touchItemType.active_stylus = YES;
	touchItemType.passive_stylus = YES;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */

    for (i = 0; i < 1; i++)
    {
		if(!thisModeConf->PenCoord.bUseNewCippingCond_Pen)
		{
			old_pos = thisInfo->tCoord_local_dsp.tPastSentPos.tXY;
			alogorithm_coord_modify_pos_local(&old_pos,&old_pos,mode);
		}		
		else if (thisInfo->tCoord_local_dsp.tPastSentPos.vusS > 0)
		{
			old_pos.x = thisInfo->tCoord_local_dsp.tRealPastSentPos.tXY.x;
			old_pos.y = thisInfo->tCoord_local_dsp.tRealPastSentPos.tXY.y;
		}

        if (thisInfo->tCoord_local_dsp.tPos.vusS > 0)
        {
        	pos = thisInfo->tCoord_local_dsp.tPos.tXY;

			if(thisInfo->tCoord_local_dsp.tPastSentPos.vusS > 0)
				alogorithm_coord_modify_pos_local(&old_pos,&pos,mode);
			else
				alogorithm_coord_modify_pos_local(&pos,&pos,mode);
			
            distX = pos.x - old_pos.x;
            distY = pos.y - old_pos.y;
            if (distY < 0)
                distY = -distY;
            if (distX < 0)
                distX = -distX;

//            if (!thisInfo->tCoord_local_dsp.bFirstLongDistanceMoved)
                ucMoveTHD = 0;//thisModeConf->Coord.ucFirstMoveEventTHD;
//            else
//                ucMoveTHD = thisModeConf->Coord.ucMoveEventTHD;

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
				tItem.tItem00.tInfo.bHover = 1 - thisInfo->tPenInfo.bPenContact;;
				tItem.tItem00.tInfo.bScreen = YES;
				tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
				tItem.tItem00.tInfo.b4FingerID = i + 1;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.ucRowStart = currentRowStart;
				//if(gSensingMode)
								
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
				
#if (PEN_REMOVE_EDGE_EN == YES)
				thisInfo->tCoord_local_dsp.tRealPastSentPos1.tXY.x = thisInfo->tCoord_local_dsp.tRealPastSentPos.tXY.x;
				thisInfo->tCoord_local_dsp.tRealPastSentPos1.tXY.y = thisInfo->tCoord_local_dsp.tRealPastSentPos.tXY.y;
#endif
				thisInfo->tCoord_local_dsp.tRealPastSentPos.tXY.x = pos.x;
				thisInfo->tCoord_local_dsp.tRealPastSentPos.tXY.y = pos.y;
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
			
			//algorithm_jitter_cal(pos);
        }
        else if (thisInfo->tCoord_local_dsp.tPastSentPos.vusS > 0)
        {
			#if (SWIP_QUEUE_MODE == 2)
				thisInfo->bTouchOffFlag = 1;
			#endif
			
        	uSWIPTouchItem_t tItem;
            tItem.tItem00.tInfo.bTouch = NO;
            tItem.tItem00.tInfo.bHover = 1 - thisInfo->tPenInfo.bPenContact;
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
//    thisInfo->bWasPalm = thisInfo->bIsPalm;

//    thisInfo->tCoord_local.tPastSentKey = thisInfo->tCoord_local.tKey;
//    thisInfo->bTouchChecked = (thisInfo->tCoord_local.tPastSentPos.sFinger_ || thisInfo->tCoord_local.tPastSentKey.sKey_);

    protocol_swip_SendPenEvent();
//    protocol_hid_SendPenEvent();
		
#ifdef ADD_PEN
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	if(thisInfo->tPenInfo.ucEdgeOutInDelayReport == 1 || gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS || gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WGP)
	{
		SendPenData();
	}
	else
	{
		switch(g_RetVal)
		{
			case PARTIAL_PEN_COORD1:
			case PARTIAL_PEN_COORD3:
			case PARTIAL_PEN_COORD4:
				SendPenData();
			break;
		
			default :
				thisInfo->tPenInfo.bDSP_SendDataEn = 1;
			break;
		}
	}
	#else
	SendPenData();
	#endif
#endif

}

#if 1
ePartialSensing_t g_RetVal = PARTIAL_PEN_BEACON;
extern tRingMSInfo_t pTRingInfo;
#ifdef TILT_ON
#ifndef TILT_OPCODE
void algorithm_Tilt_Calculation(void)	// step1
{
	if( thisInfo->tCoord_local_dsp.tAvgPos.y != 0 )
	{
		thisInfo->tTiltInfo.TILT_sx = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x-thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x;
		thisInfo->tTiltInfo.TILT_sy = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y-thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y;
		
		thisInfo->tTiltInfo.TILT_sx = thisInfo->tTiltInfo.TILT_sx * ((FPITCH_X*128)/UNIT_DIST) * 127;
		thisInfo->tTiltInfo.TILT_sy = thisInfo->tTiltInfo.TILT_sy * ((FPITCH_Y*128)/UNIT_DIST) * 127;
		
		thisInfo->tTiltInfo.TILT_sx /= 127;
		thisInfo->tTiltInfo.TILT_sy /= 127;

		if(thisModeConf->PenTilt.ucTiltAdjustEn)
		{
			int maxLenth = 128*thisModeConf->PenTilt.ucTiltL/10-1;
			if(thisInfo->tTiltInfo.TILT_sx < 0)
			{
				if(thisInfo->tTiltInfo.TILT_sx < -maxLenth)
					thisInfo->tTiltInfo.TILT_sx = -maxLenth;
				thisInfo->tTiltInfo.TILT_sx = (thisInfo->tTiltInfo.TILT_sx * sxMLookUpTable[(-thisInfo->tTiltInfo.TILT_sx*20)/thisModeConf->PenTilt.ucTiltL]) >> 7;
			}
			else
			{
				if(thisInfo->tTiltInfo.TILT_sx > maxLenth)
					thisInfo->tTiltInfo.TILT_sx = maxLenth;
				thisInfo->tTiltInfo.TILT_sx = (thisInfo->tTiltInfo.TILT_sx * sxPLookUpTable[(thisInfo->tTiltInfo.TILT_sx*20)/thisModeConf->PenTilt.ucTiltL]) >> 7;
			}

			if(thisInfo->tTiltInfo.TILT_sy < 0)
			{
				if(thisInfo->tTiltInfo.TILT_sy < -maxLenth)
					thisInfo->tTiltInfo.TILT_sy = -maxLenth;
				thisInfo->tTiltInfo.TILT_sy = (thisInfo->tTiltInfo.TILT_sy * syMLookUpTable[(-thisInfo->tTiltInfo.TILT_sy*20)/thisModeConf->PenTilt.ucTiltL]) >> 7;
			}
			else
			{
				if(thisInfo->tTiltInfo.TILT_sy > maxLenth)
					thisInfo->tTiltInfo.TILT_sy = maxLenth;
				thisInfo->tTiltInfo.TILT_sy = (thisInfo->tTiltInfo.TILT_sy * syPLookUpTable[(thisInfo->tTiltInfo.TILT_sy*20)/thisModeConf->PenTilt.ucTiltL]) >> 7;
			}
		}
		
		thisInfo->tTiltInfo.TILT_distance = ((thisInfo->tTiltInfo.TILT_sx*thisInfo->tTiltInfo.TILT_sx)+(thisInfo->tTiltInfo.TILT_sy*thisInfo->tTiltInfo.TILT_sy));

		thisInfo->tTiltInfo.TILT_distance = algorithm_calc_sqrt(thisInfo->tTiltInfo.TILT_distance);

		thisInfo->tTiltInfo.TILT_theta = 10*thisInfo->tTiltInfo.TILT_distance/thisModeConf->PenTilt.ucTiltL;

		if(thisInfo->tTiltInfo.TILT_theta<0)thisInfo->tTiltInfo.TILT_theta = 0;
		if(thisInfo->tTiltInfo.TILT_theta>127)thisInfo->tTiltInfo.TILT_theta = 127;

		thisInfo->tTiltInfo.TILT_theta = ArcSinLookUpTable_3[thisInfo->tTiltInfo.TILT_theta];
		
		thisInfo->tTiltInfo.TILT_H = thisModeConf->PenTilt.ucTiltL * CosLookUpTable_2[thisInfo->tTiltInfo.TILT_theta];
		thisInfo->tTiltInfo.TILT_H /= 10;
		thisInfo->tTiltInfo.TILT_H >>= 3;
		
		thisInfo->tTiltInfo.HID_ALTITUDE = (thisInfo->tTiltInfo.TILT_H*100) >> 7;
	}
}

void algorithm_Tilt_Calculaion(uint8_t OpType, uint8_t mode)
{
	if( thisInfo->tPenInfo.bPenContact == YES && ((g_RetVal==PARTIAL_PEN_COORD2 && OpType == 1) || (g_RetVal==PARTIAL_PEN_COORD1 && OpType == 2)) )
	{		
		//if(Tilt_cnt>0)
		{			
			tXY_t RingCoord;
			float L = 7.5;
			if(OpType == 1 || OpType == 3)
			{
				RingCoord = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
				if(OpType == 3)L = 5;
			}
			#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			else if(OpType == 2)
			{
				//if(pTRingInfo.MaxDirecNum != 2 && pTRingInfo.MaxDirecNum != 8)
				if(pTRingInfo.MaxDirecNum == 4 || pTRingInfo.MaxDirecNum == 6 || pTRingInfo.MaxDirecNum == 5)
					pTRingInfo.tCoord.x = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x + pTRingInfo.tCoord.x * 1/2;
				
				//if(pTRingInfo.MaxDirecNum != 4 && pTRingInfo.MaxDirecNum != 6)
				if(pTRingInfo.MaxDirecNum == 2 || pTRingInfo.MaxDirecNum == 8 || pTRingInfo.MaxDirecNum == 5)
					pTRingInfo.tCoord.y = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y + pTRingInfo.tCoord.y * 1/2; 

				RingCoord = pTRingInfo.tCoord;
				L = 5.5;
			}
			#endif
			thisInfo->tTiltInfo.TILT_sx = RingCoord.x-thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x;
			thisInfo->tTiltInfo.TILT_sy = RingCoord.y-thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y;
			
			thisInfo->tTiltInfo.TILT_sx = thisInfo->tTiltInfo.TILT_sx * (FPITCH_X*100)/UNIT_DIST; //1.593;
			thisInfo->tTiltInfo.TILT_sy = thisInfo->tTiltInfo.TILT_sy * (FPITCH_Y*100)/UNIT_DIST; //1.613;
			
			thisInfo->tTiltInfo.TILT_distance = ((thisInfo->tTiltInfo.TILT_sx*thisInfo->tTiltInfo.TILT_sx)+(thisInfo->tTiltInfo.TILT_sy*thisInfo->tTiltInfo.TILT_sy));

			thisInfo->tTiltInfo.TILT_distance = algorithm_calc_sqrt(thisInfo->tTiltInfo.TILT_distance);

			thisInfo->tTiltInfo.TILT_theta = thisInfo->tTiltInfo.TILT_distance/L;

			if(thisInfo->tTiltInfo.TILT_theta<0)thisInfo->tTiltInfo.TILT_theta = 0;
			if(thisInfo->tTiltInfo.TILT_theta>127)thisInfo->tTiltInfo.TILT_theta = 127;

			thisInfo->tTiltInfo.TILT_theta = ArcSinLookUpTable[thisInfo->tTiltInfo.TILT_theta];
			
			thisInfo->tTiltInfo.TILT_H = L * CosLookUpTable[thisInfo->tTiltInfo.TILT_theta];
			
			thisInfo->tTiltInfo.HID_TILT_X = algorithm_calc_angle_inter_2points(-thisInfo->tTiltInfo.TILT_sx,thisInfo->tTiltInfo.TILT_H);
			thisInfo->tTiltInfo.HID_TILT_Y = algorithm_calc_angle_inter_2points(-thisInfo->tTiltInfo.TILT_sy,thisInfo->tTiltInfo.TILT_H);
			thisInfo->tTiltInfo.HID_AZIMUTH = algorithm_calc_angle_inter_2points(thisInfo->tTiltInfo.TILT_sx,thisInfo->tTiltInfo.TILT_sy);
			//tTiltInfo.HID_TWIST =  tTiltInfo.HID_AZIMUTH;//dist;//theta;
			thisInfo->tTiltInfo.HID_ALTITUDE = thisInfo->tTiltInfo.TILT_H;
			
			
			if(thisInfo->tTiltInfo.TILT_theta==0 || thisInfo->tTiltInfo.TILT_theta==117)
			{
				thisInfo->tTiltInfo.HID_TILT_X = thisInfo->tTiltInfo.Smooth_PastTilt.x;
				thisInfo->tTiltInfo.HID_TILT_Y = thisInfo->tTiltInfo.Smooth_PastTilt.y;
				thisInfo->tTiltInfo.HID_AZIMUTH = thisInfo->tTiltInfo.PastAzimuth;
				thisInfo->tTiltInfo.HID_ALTITUDE = thisInfo->tTiltInfo.PastAltitude;
			}
			#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			if(OpType==2)
			{
				algorithm_Tilt_PreFilter();
			}
			#endif
			#ifdef TILT_SMOOTHING
			if(thisInfo->tTiltInfo.sTilt_cnt==1 || thisInfo->tTiltInfo.sTilt_cnt==2){
				thisInfo->tTiltInfo.HID_TILT_X = (thisInfo->tTiltInfo.Smooth_PastTilt.x + thisInfo->tTiltInfo.HID_TILT_X + 1)>>1;
				thisInfo->tTiltInfo.HID_TILT_Y = (thisInfo->tTiltInfo.Smooth_PastTilt.y + thisInfo->tTiltInfo.HID_TILT_Y + 1)>>1;
			}
			else if(thisInfo->tTiltInfo.sTilt_cnt>2){
				uint8_t coef = 30;
				thisInfo->tTiltInfo.HID_TILT_X = ((thisInfo->tTiltInfo.Smooth_PastTilt.x*coef) + ((32-coef)*thisInfo->tTiltInfo.HID_TILT_X))/32;
				thisInfo->tTiltInfo.HID_TILT_Y = ((thisInfo->tTiltInfo.Smooth_PastTilt.y*coef) + ((32-coef)*thisInfo->tTiltInfo.HID_TILT_Y))/32;
			}
			#endif
			
			#if (TILT_EDGE_FILTER == YES)
			bool past_out_flag = 0;
			uint8_t X_sensor_len = thisInfo->tLabel_local_dsp.tValidRect.ce - thisInfo->tLabel_local_dsp.tValidRect.cs + 1;
			uint8_t Y_sensor_len = thisInfo->tLabel_local_dsp.tValidRect.re - thisInfo->tLabel_local_dsp.tValidRect.rs + 1;
			uint8_t len_th = 7;
			
	//		tTiltInfo.HID_TWIST = (X_sensor_len << 4 | Y_sensor_len);
	//		if(Tilt_cnt==0)
	//		{
	//			past_out_flag = 1;
	//		}
	//		else
			{
				if(thisInfo->tCoord_local_dsp.tOrgPos.tXY.x<788)
				{
	//				if(past_out_flag == 2)past_out_flag = 2;
	//				else 
					if(len_th > X_sensor_len || Y_sensor_len < len_th)past_out_flag = 1;
				}
				else if(thisInfo->tCoord_local_dsp.tOrgPos.tXY.x>20716)
				{
	//				if(past_out_flag == 2)past_out_flag = 2;
	//				else 
					if(len_th > X_sensor_len || Y_sensor_len < len_th)past_out_flag = 1;
				}
				
				//len_th = 6;
				if(thisInfo->tCoord_local_dsp.tOrgPos.tXY.y < 809)
				{
	//				if(past_out_flag == 2)past_out_flag = 2;
	//				else 
					if(len_th > X_sensor_len || Y_sensor_len < len_th)past_out_flag = 1;
				}
				else if(thisInfo->tCoord_local_dsp.tOrgPos.tXY.y > 10711)
				{
	//				if(past_out_flag == 2)past_out_flag = 2;
	//				else 
					if(len_th > X_sensor_len || Y_sensor_len < len_th)past_out_flag = 1;
				}
			}	
				
			if(past_out_flag>0)
			{
				thisInfo->tTiltInfo.HID_TILT_X = thisInfo->tTiltInfo.Smooth_PastTilt.x;
				thisInfo->tTiltInfo.HID_TILT_Y = thisInfo->tTiltInfo.Smooth_PastTilt.y;
				thisInfo->tTiltInfo.HID_ALTITUDE = thisInfo->tTiltInfo.PastAltitude;
				thisInfo->tTiltInfo.HID_AZIMUTH = thisInfo->tTiltInfo.PastAzimuth;
			}
			#endif
			
			thisInfo->tTiltInfo.Smooth_PastTilt.x = thisInfo->tTiltInfo.HID_TILT_X; thisInfo->tTiltInfo.Smooth_PastTilt.y = thisInfo->tTiltInfo.HID_TILT_Y;
			thisInfo->tTiltInfo.PastAltitude = thisInfo->tTiltInfo.HID_ALTITUDE; thisInfo->tTiltInfo.PastAzimuth = thisInfo->tTiltInfo.HID_AZIMUTH;	
			
			#if (TILT_AREA_FILTER == YES)
			if(thisInfo->tTiltInfo.sTilt_cnt>1){
				int Tilt_SUB = thisInfo->tTiltInfo.HID_TILT_X - thisInfo->tTiltInfo.Area_PastTilt.x;
				bool_t TiltUpFlag = 0;
				
				if(Tilt_SUB > 0)TiltUpFlag = 1;
				
				bool_t UpDownChangeCheck = 0;
				if(thisInfo->tTiltInfo.TiltUpDownST_x == 0)
				{
					thisInfo->tTiltInfo.TiltUpDownST_x  = 2;
				}	
				else if(thisInfo->tTiltInfo.TiltUpDownST_x ==1)
				{
					if(TiltUpFlag==1 && Tilt_SUB > thisModeConf->PenTilt.usTilt_Change_TH_Right)
					//if(Tilt_SUB>-50)
					{
						thisInfo->tTiltInfo.Area_PastTilt.x=thisInfo->tTiltInfo.HID_TILT_X;
						UpDownChangeCheck=0;
					}
					else{
						//PenUpDownST_X = 2;
						UpDownChangeCheck = 1;		
					}
				}
				else if(thisInfo->tTiltInfo.TiltUpDownST_x ==3)
				{
					if(TiltUpFlag==0 && && Tilt_SUB < -thisModeConf->PenTilt.usTilt_Change_TH_Right)
					//if(Tilt_SUB<50)
					{
						thisInfo->tTiltInfo.Area_PastTilt.x=thisInfo->tTiltInfo.HID_TILT_X;
						UpDownChangeCheck=0;
					}
					else {
						//PenUpDownST_X = 2;
						UpDownChangeCheck = 1;
					}							
				}					
				
				if(UpDownChangeCheck == 1 || thisInfo->tTiltInfo.TiltUpDownST_x  == 2)
				{
					if(-thisModeConf->PenTilt.usTilt_Change_TH_Reverse<=Tilt_SUB && Tilt_SUB<=thisModeConf->PenTilt.usTilt_Change_TH_Reverse)thisInfo->tTiltInfo.HID_TILT_X=thisInfo->tTiltInfo.Area_PastTilt.x;
					else if(thisModeConf->PenTilt.usTilt_Change_TH_Reverse<Tilt_SUB)
					{
						thisInfo->tTiltInfo.Area_PastTilt.x=thisInfo->tTiltInfo.HID_TILT_X;
						thisInfo->tTiltInfo.TiltUpDownST_x  = 1;
					}
					else if(-thisModeConf->PenTilt.usTilt_Change_TH_Reverse>Tilt_SUB)
					{
						thisInfo->tTiltInfo.Area_PastTilt.x=thisInfo->tTiltInfo.HID_TILT_X;
						thisInfo->tTiltInfo.TiltUpDownST_x  = 3;
					}
				}
				
				Tilt_SUB = thisInfo->tTiltInfo.HID_TILT_Y - thisInfo->tTiltInfo.Area_PastTilt.y;
				
				if(Tilt_SUB > 0)TiltUpFlag = 1;
				else TiltUpFlag = 0;
				
				UpDownChangeCheck = 0;
				if(thisInfo->tTiltInfo.TiltUpDownST_y == 0)
				{
					thisInfo->tTiltInfo.TiltUpDownST_y = 2;
				}	
				else if(thisInfo->tTiltInfo.TiltUpDownST_y==1)
				{
					if(TiltUpFlag==1 && Tilt_SUB > thisModeConf->PenTilt.usTilt_Change_TH_Right)
					//if(Tilt_SUB>-50)
					{
						thisInfo->tTiltInfo.Area_PastTilt.y=thisInfo->tTiltInfo.HID_TILT_Y;
						UpDownChangeCheck=0;
					}
					else{
						//TiltUpDownST_Y = 2;
						UpDownChangeCheck = 1;	
					}							
				}
				else if(thisInfo->tTiltInfo.TiltUpDownST_y==3)
				{
					if(TiltUpFlag==0 && Tilt_SUB < -thisModeConf->PenTilt.usTilt_Change_TH_Right)
					//if(Tilt_SUB<50)
					{
						thisInfo->tTiltInfo.Area_PastTilt.y=thisInfo->tTiltInfo.HID_TILT_Y;
						UpDownChangeCheck=0;
					}
					else{
						//TiltUpDownST_Y = 2;
						UpDownChangeCheck = 1;	
					}							
				}
				
				if(UpDownChangeCheck == 1 || thisInfo->tTiltInfo.TiltUpDownST_y == 2)
				{
					if(-thisModeConf->PenTilt.usTilt_Change_TH_Reverse<=Tilt_SUB && Tilt_SUB<=thisModeConf->PenTilt.usTilt_Change_TH_Reverse)thisInfo->tTiltInfo.HID_TILT_Y=thisInfo->tTiltInfo.Area_PastTilt.y;
					else if(-thisModeConf->PenTilt.usTilt_Change_TH_Reverse>Tilt_SUB)
					{
						thisInfo->tTiltInfo.Area_PastTilt.y=thisInfo->tTiltInfo.HID_TILT_Y;
						thisInfo->tTiltInfo.TiltUpDownST_y = 3;
					}
					else if(thisModeConf->PenTilt.usTilt_Change_TH_Reverse<Tilt_SUB)
					{
						thisInfo->tTiltInfo.Area_PastTilt.y=thisInfo->tTiltInfo.HID_TILT_Y;
						thisInfo->tTiltInfo.TiltUpDownST_y = 1;
					}
				}
			}
			else{
				thisInfo->tTiltInfo.Area_PastTilt.x = thisInfo->tTiltInfo.HID_TILT_X;
				thisInfo->tTiltInfo.Area_PastTilt.y = thisInfo->tTiltInfo.HID_TILT_Y;
				thisInfo->tTiltInfo.TiltUpDownST_x = thisInfo->tTiltInfo.TiltUpDownST_y = 0;
				thisInfo->tTiltInfo.Smooth_PastTilt.x = thisInfo->tTiltInfo.HID_TILT_X; thisInfo->tTiltInfo.Smooth_PastTilt.y = thisInfo->tTiltInfo.HID_TILT_Y;
				thisInfo->tTiltInfo.PastAltitude = thisInfo->tTiltInfo.HID_ALTITUDE; thisInfo->tTiltInfo.PastAzimuth = thisInfo->tTiltInfo.HID_AZIMUTH;
			}
			#endif //TILT_AREA_FILTER end
			
			if(thisInfo->tCoord_local_dsp.tAvgPos.x==0 && OpType == 1)
			{
				#if (Pen2ReportMethod == 4)
				thisInfo->tCoord_local_dsp.tPos.tXY.x = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x;
				thisInfo->tCoord_local_dsp.tPos.tXY.y = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y;	
				thisInfo->tCoord_local_dsp.tOrgPos.tXY.x = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x;
				thisInfo->tCoord_local_dsp.tOrgPos.tXY.y = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y;
				thisInfo->tCoord_local_dsp.tPos.vusS = thisInfo->tCoord_local_dsp.tPastPos[0].vusS;
				thisInfo->tCoord_local_dsp.tOrgPos.vusS = thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS;		
				#endif
				
				#if (Pen2ReportMethod == 1)// || (Pen2ReportMethod == 2 && ReportDelayAndInterpolation>0 && USING_SMOOTH_POS<2))
				if(thisInfo->tCoord_local_dsp.tPastPos[1].vusS>0 && thisInfo->tTiltInfo.sTilt_cnt>0 /*&& PostProcessIng == 0*/){
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
				
				#if (Pen2ReportMethod == 1 || Pen2ReportMethod == 2 /*|| Pen2ReportMethod == 3*/)
				if(thisInfo->tCoord_local_dsp.tOrgPastPos[1].vusS>0 && thisInfo->tTiltInfo.sTilt_cnt>0 /*&& PostProcessIng == 0*/){
					thisInfo->tCoord_local_dsp.tOrgPos.tXY.x = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x + (thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x - thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.x);
					thisInfo->tCoord_local_dsp.tOrgPos.tXY.y = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y + (thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y - thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.y);
				}
				else
				{
					thisInfo->tCoord_local_dsp.tOrgPos.tXY.x = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x;
					thisInfo->tCoord_local_dsp.tOrgPos.tXY.y = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y;
				}
				thisInfo->tCoord_local_dsp.tPos.vusS = thisInfo->tCoord_local_dsp.tOrgPos.vusS = thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS;
				thisInfo->tCoord_local_dsp.tPos.tXY = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
				#endif
				
				#if (Pen2ReportMethod == 3)
				thisInfo->tPenInfo.bPosUpdateSkip = 1;
				#endif
			}
		}
		
		if(thisInfo->tTiltInfo.sTilt_cnt++ > 32765)thisInfo->tTiltInfo.sTilt_cnt = 100;
		//thisInfo->tPenInfo.bReportSkip = 1;
	}

	#if (Pen2ReportMethod==0)
	thisInfo->tCoord_local_dsp.tPos.tXY.x = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x;
	thisInfo->tCoord_local_dsp.tPos.tXY.y = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y;
	#endif
}
#endif
#endif //TILT_ON end

void algorithm_RangeExtend(int mode)
{
#if (CUSTOMER == MODEL_DEF_FHD_92503B_HAIER_CG && USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
	int y3;
#endif
	int th,edge_boundary,x, y, y1, y2, d, div_value;
#if (CUSTOMER == MODEL_DEF_FHD_92504_Sony_Oliver_WGP_Pen && USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)		
	int delta_temp;
#endif
	
	if(mode == LOCAL_RING_MODE)
	{
		th = thisModeConf->Label.usLocalSeedBase_Ring;
		edge_boundary = 1;
#if (CUSTOMER == MODEL_DEF_FHD_92503B_HAIER_CG && USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
		div_value = 3;
#else
		div_value = 2;
#endif
	}
	else 
	{	
		th = thisModeConf->Label.usLocalSeedBase;
		edge_boundary = thisModeConf->PenCoord.ucTipRangeExtend_On; // For Edge apply on/off, hanch
		div_value = 2;
	}
		
		
	if(thisInfo->tLabel_local_dsp.tValidRect.rs == 0 && thisInfo->tLabel_local_dsp.tValidMaxPos.r+currentRowStart >= edge_boundary-1)
	{
		y=1, y1=0, y2=-1;
#if (CUSTOMER == MODEL_DEF_FHD_92503B_HAIER_CG && USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
		y3=-2;
#endif
		for(x = thisInfo->tLabel_local_dsp.tValidRect.cs; x <= thisInfo->tLabel_local_dsp.tValidRect.ce; x++)
		{
			d = thisInfo->tPenInfo.pTmpModeDeltaImg[(y+PAD_)*(COL_MAX+PAD_+PAD_)+(x+PAD_)];

			if(d > th)
			{
				d = thisInfo->tPenInfo.pTmpModeDeltaImg[(y1+PAD_)*(COL_MAX+PAD_+PAD_)+(x+PAD_)];
#if (CUSTOMER == MODEL_DEF_FHD_92504_Sony_Oliver_WGP_Pen && USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
				delta_temp = d;
#endif
				d/=div_value;

#if (CUSTOMER == MODEL_DEF_FHD_92504_Sony_Oliver_WGP_Pen && USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
				/*if(thisInfo->tTiltInfo.sTilt_cnt > 1 && (thisInfo->tTiltInfo.HID_TILT_Y < 5000 || thisInfo->tTiltInfo.HID_TILT_Y > 13000) && mode == LOCAL_RING_MODE)// && dbg_dspB[2] == 1)
				{
						d/=2;
				}
				else */if(thisInfo->tTiltInfo.sTilt_cnt > 1 && (thisInfo->tTiltInfo.HID_TILT_Y > 6000 && thisInfo->tTiltInfo.HID_TILT_Y < 12000) && mode == LOCAL_RING_MODE && algorithm_coord_IsEdgeArea(&thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY, UNIT_DIST<<1) == 0)
				{
						d += delta_temp;
				}
#endif
				
				thisInfo->tLabel_local_dsp.tCoord.x += x*d;
				thisInfo->tLabel_local_dsp.tCoord.y += y2*d;
				thisInfo->tLabel_local_dsp.ulExtStrength += d;
				thisInfo->tLabel_local_dsp.ulStrength += d;
				
#if (CUSTOMER == MODEL_DEF_FHD_92503B_HAIER_CG && USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)				
				if(thisInfo->tTiltInfo.sTilt_cnt > 1 && thisInfo->tTiltInfo.HID_TILT_Y > 9500 && mode == LOCAL_RING_MODE)
				{
					d/=2;
					thisInfo->tLabel_local_dsp.tCoord.x += x*d;
					thisInfo->tLabel_local_dsp.tCoord.y += y3*d;
					thisInfo->tLabel_local_dsp.ulExtStrength += d;
					thisInfo->tLabel_local_dsp.ulStrength += d;
				}
#endif
			}
		}
	}
	
	if(thisInfo->tLabel_local_dsp.tValidRect.re == PEN_COORD_ROW_MAX-1 && thisInfo->tDelta_local.tMaxCellPos.r+currentRowStart <= ROW_MAX-edge_boundary)
	{
		y = PEN_COORD_ROW_MAX-2;
		y1 = PEN_COORD_ROW_MAX-1;
		y2 = PEN_COORD_ROW_MAX;
#if (CUSTOMER == MODEL_DEF_FHD_92503B_HAIER_CG && USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
		y3 = PEN_COORD_ROW_MAX+1;
#endif
		for(x = thisInfo->tLabel_local_dsp.tValidRect.cs; x <= thisInfo->tLabel_local_dsp.tValidRect.ce; x++)
		{
			d = thisInfo->tPenInfo.pTmpModeDeltaImg[(y+PAD_)*(COL_MAX+PAD_+PAD_)+(x+PAD_)];

			if(d>th)
			{
				d = thisInfo->tPenInfo.pTmpModeDeltaImg[(y1+PAD_)*(COL_MAX+PAD_+PAD_)+(x+PAD_)];
#if (CUSTOMER == MODEL_DEF_FHD_92504_Sony_Oliver_WGP_Pen && USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
				delta_temp = d;
#endif
				d/=div_value;
				
#if (CUSTOMER == MODEL_DEF_FHD_92504_Sony_Oliver_WGP_Pen && USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
				/*if(thisInfo->tTiltInfo.sTilt_cnt > 1 && (thisInfo->tTiltInfo.HID_TILT_Y < 5000 || thisInfo->tTiltInfo.HID_TILT_Y > 13000) && mode == LOCAL_RING_MODE)// && dbg_dspB[2] == 1)
				{
						d/=2;
				}
				else */if(thisInfo->tTiltInfo.sTilt_cnt > 1 && (thisInfo->tTiltInfo.HID_TILT_Y > 6000 && thisInfo->tTiltInfo.HID_TILT_Y < 12000) && mode == LOCAL_RING_MODE && algorithm_coord_IsEdgeArea(&thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY, UNIT_DIST<<1) == 0)
				{
						d += delta_temp;
				}
#endif
				
				thisInfo->tLabel_local_dsp.tCoord.x += x*d;
				thisInfo->tLabel_local_dsp.tCoord.y += y2*d;
				thisInfo->tLabel_local_dsp.ulExtStrength += d;
				thisInfo->tLabel_local_dsp.ulStrength += d;

#if (CUSTOMER == MODEL_DEF_FHD_92503B_HAIER_CG && USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)			
				if(thisInfo->tTiltInfo.sTilt_cnt > 1 && thisInfo->tTiltInfo.HID_TILT_Y < 8500 && mode == LOCAL_RING_MODE)
				{				
					d/=2;
					thisInfo->tLabel_local_dsp.tCoord.x += x*d;
					thisInfo->tLabel_local_dsp.tCoord.y += y3*d;
					thisInfo->tLabel_local_dsp.ulExtStrength += d;
					thisInfo->tLabel_local_dsp.ulStrength += d;
				}
#endif
			}
		}
	}
}

#if (RangeExtend_v2_En == YES)
extern uint16_t p_sensingRowStart_Tilt;
void algorithm_RangeExtend_v2(int mode)
{
	int max_delta = thisModeConf->PenTilt.usTiltSubMaxDelta; // 100
	int min_div = thisModeConf->PenTilt.usTiltDivMin; //(int)(1.5*UNIT_DIST);
	int max_div = thisModeConf->PenTilt.usTiltDivMax; //(int)(4*UNIT_DIST);
	int sub_delta_max = 0, sub_delta = 0, dVal;
	tRect_t sRect;
	int mark_bound_num, th, x, y, xLineSumT = 0, xLineSumB = 0, yTNum = 0, yBNum = 0;
	int yTSum[2], yBSum[2];

	if(mode == LOCAL_RING_MODE)
	{
		th = thisModeConf->Label.usLocalSeedBase_Ring;
		mark_bound_num = thisModeConf->PenTilt.ucRingMarkBoundaryNum;
	}
	else
	{
		th = thisModeConf->Label.usLocalSeedBase;
		mark_bound_num = thisModeConf->PenCoord.ucMarkBoundaryNum;
	}

	if(mark_bound_num > 0)
	{
		sRect.cs = MAX(0, thisInfo->tLabel_local_dsp.tValidRect.cs-1);
		sRect.ce = MIN(COL_MAX-1, thisInfo->tLabel_local_dsp.tValidRect.ce+1);
		sRect.rs = MAX(0, thisInfo->tLabel_local_dsp.tValidRect.rs-1);
		sRect.re = MIN(PEN_COORD_ROW_MAX-1, thisInfo->tLabel_local_dsp.tValidRect.re+1);
	}
	else
		sRect = thisInfo->tLabel_local_dsp.tValidRect;

	if(p_sensingRowStart_Tilt + sRect.rs > 0 && p_sensingRowStart_Tilt + sRect.re < ROW_MAX-1)
	{
		for(x=sRect.cs; x<=sRect.ce; x++)
		{
			xLineSumT += thisInfo->tPenInfo.pTmpModeDeltaImg[(0+PAD_)*(COL_MAX+PAD_+PAD_)+(x+PAD_)];
			xLineSumB += thisInfo->tPenInfo.pTmpModeDeltaImg[(PEN_COORD_ROW_MAX-1+PAD_)*(COL_MAX+PAD_+PAD_)+(x+PAD_)];
		}

		if(thisInfo->tDelta_local.tMaxCellPos.r > 0)
		{
			sub_delta = thisInfo->tDelta_local.iMaxStrength - thisInfo->tPenInfo.pTmpModeDeltaImg[(thisInfo->tDelta_local.tMaxCellPos.r-1+PAD_)
			*(COL_MAX+PAD_+PAD_)+(thisInfo->tDelta_local.tMaxCellPos.c+PAD_)];
			if(sub_delta_max < sub_delta)	sub_delta_max = sub_delta;
		}
		if(thisInfo->tDelta_local.tMaxCellPos.r < PEN_COORD_ROW_MAX-1)
		{
			sub_delta = thisInfo->tDelta_local.iMaxStrength - thisInfo->tPenInfo.pTmpModeDeltaImg[(thisInfo->tDelta_local.tMaxCellPos.r+1+PAD_)
			*(COL_MAX+PAD_+PAD_)+(thisInfo->tDelta_local.tMaxCellPos.c+PAD_)];
			if(sub_delta_max < sub_delta)	sub_delta_max = sub_delta;
		}
		if(sub_delta_max > max_delta)	sub_delta_max = max_delta;
		dVal = max_div - ((max_div-min_div)*(max_delta - sub_delta_max))/max_delta;
		
		for(y=0; y<2; y++)
		{
			if(sRect.rs-y-1 < 0)
			{
				xLineSumT = (xLineSumT*UNIT_DIST)/dVal;
				if(xLineSumT > 0)
				{
					yTSum[yTNum] = xLineSumT;
					yTNum++;
					sRect.rs = 0;
				}
			}

			if(sRect.re+y+1 > PEN_COORD_ROW_MAX-1)
			{
				xLineSumB = (xLineSumB*UNIT_DIST)/dVal;
				if(xLineSumB > 0)
				{
					yBSum[yBNum] = xLineSumB;
					yBNum++;
					sRect.re = PEN_COORD_ROW_MAX-1;
				}
			}
		}

		if(yTNum != 0 || yBNum != 0)
		{
			int *pSumYArray = malloc(sizeof(int) * (sRect.ce-sRect.cs+1));
			int total_sumY = 0;
			int d, yEndNum;
			
			mark_bound_num = mark_bound_num > 1 ? mark_bound_num - 1 : 0;
			for(x=sRect.cs; x<=sRect.ce; x++)
			{
				uint32_t sumY = 0;
				for(y=sRect.rs; y<=sRect.re; y++)
					sumY += thisInfo->tPenInfo.pTmpModeDeltaImg[(y+PAD_)*(COL_MAX+PAD_+PAD_)+(x+PAD_)];
				
				pSumYArray[x-sRect.cs] = sumY;
				total_sumY += sumY;
			}
				
			for(x=sRect.cs; x<=sRect.ce; x++)
			{
				if(HAL_READ_LOCAL_LABEL_IMAGE(0, x) != 0 && thisInfo->tPenInfo.pTmpModeDeltaImg[(0+PAD_)*(COL_MAX+PAD_+PAD_)+(x+PAD_)] > th)
					yEndNum = 1;
				else
					yEndNum = 0;

				for(y=0; y<yEndNum; y++)
				{
					d = (yTSum[y] * pSumYArray[x-sRect.cs] + (total_sumY>>1)) / total_sumY;
					thisInfo->tLabel_local_dsp.tCoord.x += x*d;
					thisInfo->tLabel_local_dsp.tCoord.y += (sRect.rs-y-1)*d;
					thisInfo->tLabel_local_dsp.ulExtStrength += d;
					thisInfo->tLabel_local_dsp.ulStrength += d;
					if(d > th) yEndNum = yTNum;
				}

				if(HAL_READ_LOCAL_LABEL_IMAGE(PEN_COORD_ROW_MAX-1, x) != 0 && thisInfo->tPenInfo.pTmpModeDeltaImg[(PEN_COORD_ROW_MAX-1+PAD_)*(COL_MAX+PAD_+PAD_)+(x+PAD_)] > th)
					yEndNum = 1;
				else
					yEndNum = 0;

				for(y=0; y<yEndNum; y++)
				{
					d = (yBSum[y] * pSumYArray[x-sRect.cs] + (total_sumY>>1)) / total_sumY;
					thisInfo->tLabel_local_dsp.tCoord.x += x*d;
					thisInfo->tLabel_local_dsp.tCoord.y += (sRect.re+y+1)*d;
					thisInfo->tLabel_local_dsp.ulExtStrength += d;
					thisInfo->tLabel_local_dsp.ulStrength += d;
					if(d > th) yEndNum = yBNum;
				}
			}
			free(pSumYArray);
		}
	}
}
#endif

#if (RingCoordSmooth_En == YES)
void algorithm_Tilt_RingCoordSmoothing()
{
	tXY_t sub_pos, prev_sub_pos;

	if(thisInfo->tTiltInfo.PastOrgTipPos.vusR != 0 && thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusR != 0 && thisInfo->tTiltInfo.sTilt_cnt > 15)
	{
		int temp_sub;
		prev_sub_pos.x = thisInfo->tTiltInfo.PastOrgTipPos.tXY.x - thisInfo->tTiltInfo.PastOrgTiltPos.x;
		prev_sub_pos.y = thisInfo->tTiltInfo.PastOrgTipPos.tXY.y - thisInfo->tTiltInfo.PastOrgTiltPos.y;
		sub_pos.x = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x - thisInfo->tCoord_local_dsp.tOrgPos.tXY.x;
		sub_pos.y = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y - thisInfo->tCoord_local_dsp.tOrgPos.tXY.y;

		temp_sub = prev_sub_pos.x*(thisModeConf->PenTilt.ucRingCoordSmoothCoef-1) + sub_pos.x;
		temp_sub = temp_sub < 0 ? temp_sub - (thisModeConf->PenTilt.ucRingCoordSmoothCoef>>1) : temp_sub + (thisModeConf->PenTilt.ucRingCoordSmoothCoef>>1);
		thisInfo->tCoord_local_dsp.tOrgPos.tXY.x = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x - (temp_sub/thisModeConf->PenTilt.ucRingCoordSmoothCoef);
		temp_sub = prev_sub_pos.y*(thisModeConf->PenTilt.ucRingCoordSmoothCoef-1) + sub_pos.y;
		temp_sub = temp_sub < 0 ? temp_sub - (thisModeConf->PenTilt.ucRingCoordSmoothCoef>>1) : temp_sub + (thisModeConf->PenTilt.ucRingCoordSmoothCoef>>1);
		thisInfo->tCoord_local_dsp.tOrgPos.tXY.y = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y - (temp_sub/thisModeConf->PenTilt.ucRingCoordSmoothCoef);
	}
	thisInfo->tTiltInfo.PastOrgTiltPos = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
	thisInfo->tTiltInfo.PastOrgTipPos = thisInfo->tCoord_local_dsp.tOrgPastPos[0];
	thisInfo->tCoord_local_dsp.tPos.tXY = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
}
#endif

#if (OrgPastPosInterpolation_SW>0)
#ifndef OrgPastPosInterpolation_OPCODE
void algorithm_OrgPastPosInterpolation(int mode)
{
	//int cs,ce,rs,re;

	if(mode == LOCAL_MODE && thisInfo->tCoord_local_dsp.tPos.vusS > 0)// && thisInfo->tCoord_local_dsp.tAvgPos.x == 0)
	{
		tXY_t coord_array[7];

		if(thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS>0 && thisInfo->tCoord_local_dsp.tOrgPastPos[1].vusS>0 && thisInfo->tCoord_local_dsp.tOrgPastPos2.vusS>0 && thisInfo->tCoord_local_dsp.PenContactCnt > 5)
		{
			coord_array[0] = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
			coord_array[1] = thisInfo->tCoord_local_dsp.tPastPos[0].tXY;
			coord_array[2] = thisInfo->tCoord_local_dsp.tPastPos[1].tXY;
			coord_array[3] = thisInfo->tCoord_local_dsp.tPastPos2.tXY;
			coord_array[4] = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY;	
			#if (OrgPastPosInterpolation_SW>1)
			coord_array[5] = thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY;	
			#endif
			#if (OrgPastPosInterpolation_SW>2)
			coord_array[6] = thisInfo->tCoord_local_dsp.tOrgPastPos2.tXY;	
			#endif
			
			thisInfo->tCoord_local_dsp.tPos.tXY = meanInterpolate(coord_array, 0,OrgPastPosInterpolation_SW+4);
		}
		else if(thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS>0 && thisInfo->tCoord_local_dsp.tOrgPastPos[1].vusS>0 && thisInfo->tCoord_local_dsp.tOrgPastPos2.vusS>0)
		{
			tXY_t coord_array1[5];
			
			coord_array[0] = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
			#ifdef DSP_SMOOTH_PASTPOS
			coord_array[1] = thisInfo->tCoord_local_dsp.tPastPos[0].tXY;			
			coord_array[2] = thisInfo->tCoord_local_dsp.tPastPos[1].tXY;	
			coord_array[3] = thisInfo->tCoord_local_dsp.tPastPos2.tXY;
			#else
			coord_array[1] = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY;			
			coord_array[2] = thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY;	
			coord_array[3] = thisInfo->tCoord_local_dsp.tOrgPastPos2.tXY;	
			#endif
			
			coord_array1[0] = meanInterpolate(coord_array, 0,2);
			coord_array1[1] = meanInterpolate(coord_array, 0,3);
			coord_array1[2] = meanInterpolate(coord_array, 0,4);
			coord_array1[3] = meanInterpolate(coord_array, 1,3);
			coord_array1[4] = meanInterpolate(coord_array, 2,2);
			thisInfo->tCoord_local_dsp.tPos.tXY = meanInterpolate(coord_array1, 0,5);
		}
		else if(thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS>0 && thisInfo->tCoord_local_dsp.tOrgPastPos[1].vusS>0)
		{
			coord_array[0] = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
			#ifdef DSP_SMOOTH_PASTPOS
			coord_array[1] = thisInfo->tCoord_local_dsp.tPastPos[0].tXY;			
			coord_array[2] = thisInfo->tCoord_local_dsp.tPastPos[1].tXY;
			#else
			coord_array[1] = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY;			
			coord_array[2] = thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY;	
			#endif
			thisInfo->tCoord_local_dsp.tPos.tXY = meanInterpolate(coord_array, 0,3);
		}
		else if(thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS>0)
		{
			coord_array[0] = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
			coord_array[1] = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY;			
			thisInfo->tCoord_local_dsp.tPos.tXY = meanInterpolate(coord_array, 0,2);
		}
		else thisInfo->tCoord_local_dsp.tPos.tXY = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
	}
}	
#endif 			
#endif 

#if (OUT_IN_DRAWING==YES)
void algorithm_out_in_drawing(int mode,int sPMode)
{
	int rs, re, cs;
	uint8_t EdgeOutInDelayReport = thisInfo->tPenInfo.ucEdgeOutInDelayReport;
	int bound_th,dis_th;
	static int EdgeOutInHoverCnt = 0;
	
	if(mode == LOCAL_MODE || mode == LOCAL_HOVER_MODE)
	{
		bound_th = thisModeConf->PenCoord.usOutInBoundTh;
		dis_th = thisModeConf->PenCoord.ucOutInDisTh;
		tXY_t PredicPos,Pos1,Pos2;
		if(thisInfo->tCoord_local_dsp.tOrgPos.tXY.x>-(UNIT_DIST>>1) && thisInfo->tCoord_local_dsp.tOrgPos.tXY.x<thisInfo->tCoord.iInternalXRes+(UNIT_DIST>>1) && thisInfo->tCoord_local_dsp.tOrgPos.tXY.y>-(UNIT_DIST>>1) && thisInfo->tCoord_local_dsp.tOrgPos.tXY.y<thisInfo->tCoord.iInternalYRes+(UNIT_DIST>>1))
		{
			if(EdgeOutInDelayReport>0) 
			{
				if(EdgeOutInDelayReport==1)
				{
					if(mode == LOCAL_MODE)
					{
						EdgeOutInDelayReport = 2;
						if(EdgeOutInHoverCnt <= 5)thisInfo->tPenInfo.bReportSkip = 1;
						EdgeOutInHoverCnt = 0;
					}
					else EdgeOutInHoverCnt++;
					
					if(EdgeOutInHoverCnt > 5)
					{
						EdgeOutInDelayReport = 0;
						EdgeOutInHoverCnt = 0;
					}
				}
				else if(EdgeOutInDelayReport == 2) 
				{					
					PredicPos.x = thisInfo->tPenInfo.PrePos.x;
					PredicPos.y = thisInfo->tPenInfo.PrePos.y;
					
					if(EdgeOutInHoverCnt > 0)
					{
						dis_th = dis_th * ((EdgeOutInHoverCnt+1)>>1);
						bound_th = bound_th * ((EdgeOutInHoverCnt+1)>>1);
						EdgeOutInHoverCnt = 0;
					}
					
					if(thisInfo->tPenInfo.PrePos.x < bound_th)
					{
						Pos2.x = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x-thisInfo->tPenInfo.PrePos.x;
						if(Pos2.x > dis_th)
						{
							Pos2.y = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y-thisInfo->tPenInfo.PrePos.y;
							Pos1.x = thisInfo->tPenInfo.PrePos.x;
							Pos1.y = (Pos1.x*Pos2.y)/Pos2.x;
							PredicPos.x = -(UNIT_DIST>>1);
							PredicPos.y = thisInfo->tPenInfo.PrePos.y - Pos1.y;
						}
					}
					
					if(thisInfo->tPenInfo.PrePos.x > thisInfo->tCoord.iInternalXRes-bound_th)
					{
						Pos2.x = thisInfo->tPenInfo.PrePos.x-thisInfo->tCoord_local_dsp.tOrgPos.tXY.x;
						if(Pos2.x > dis_th)
						{
							Pos2.y = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y-thisInfo->tPenInfo.PrePos.y;
							Pos1.x = thisInfo->tCoord.iInternalXRes+(UNIT_DIST>>1)-thisInfo->tPenInfo.PrePos.x;
							Pos1.y = (Pos1.x*Pos2.y)/Pos2.x;
							PredicPos.x = thisInfo->tCoord.iInternalXRes+(UNIT_DIST>>1);
							PredicPos.y = thisInfo->tPenInfo.PrePos.y - Pos1.y;
						}
					}	
					
					if(thisInfo->tPenInfo.PrePos.y > thisInfo->tCoord.iInternalYRes-bound_th)
					{
						if(PredicPos.x==thisInfo->tPenInfo.PrePos.x || ((PredicPos.x == -(UNIT_DIST>>1) || PredicPos.x == thisInfo->tCoord.iInternalXRes+(UNIT_DIST>>1)) && PredicPos.y > thisInfo->tCoord.iInternalYRes+(UNIT_DIST>>1)))
						{
							Pos2.x = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x-thisInfo->tPenInfo.PrePos.x;
							Pos2.y = thisInfo->tPenInfo.PrePos.y-thisInfo->tCoord_local_dsp.tOrgPos.tXY.y;
							if(Pos2.y > dis_th)
							{
								Pos1.y = thisInfo->tCoord.iInternalYRes+(UNIT_DIST>>1)-thisInfo->tPenInfo.PrePos.y;
								Pos1.x = (Pos2.x*Pos1.y)/Pos2.y;
								PredicPos.x = thisInfo->tPenInfo.PrePos.x - Pos1.x;
								PredicPos.y = thisInfo->tCoord.iInternalYRes+(UNIT_DIST>>1);
							}
						}
					}	

					if(thisInfo->tPenInfo.PrePos.y < bound_th)
					{
						if(PredicPos.x==thisInfo->tPenInfo.PrePos.x || ((PredicPos.x == -(UNIT_DIST>>1) || PredicPos.x == thisInfo->tCoord.iInternalXRes+(UNIT_DIST>>1)) && PredicPos.y < -(UNIT_DIST>>1)))
						{
							Pos2.x = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x-thisInfo->tPenInfo.PrePos.x;
							Pos2.y = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y-thisInfo->tPenInfo.PrePos.y;
							if(Pos2.y > dis_th)
							{
								Pos1.y = thisInfo->tPenInfo.PrePos.y;
								Pos1.x = (Pos2.x*Pos1.y)/Pos2.y;
								PredicPos.x = thisInfo->tPenInfo.PrePos.x - Pos1.x;
								PredicPos.y = -(UNIT_DIST>>1);
							}
						}
					}	
					
					if(PredicPos.x != thisInfo->tPenInfo.PrePos.x && PredicPos.y != thisInfo->tPenInfo.PrePos.y)
					{

						rs = thisInfo->tCoord_local_dsp.tPos.tXY.x;
						re = thisInfo->tCoord_local_dsp.tPos.tXY.y;
						cs = thisInfo->tCoord_local_dsp.tPos.vusS;
						thisInfo->tCoord_local_dsp.tPos.tXY.x = PredicPos.x;
						thisInfo->tCoord_local_dsp.tPos.tXY.y = PredicPos.y;
						thisInfo->tCoord_local_dsp.tPos.vusS = thisInfo->tCoord_local_dsp.tPastPos[0].vusS;
						algorithm_PendPenEventforDSP(mode);
						thisInfo->tCoord_local_dsp.tPos.tXY.x = rs;
						thisInfo->tCoord_local_dsp.tPos.tXY.y = re;
						thisInfo->tCoord_local_dsp.tPos.vusS = cs;
						EdgeOutInDelayReport = 0;
					}
					
					if(EdgeOutInDelayReport>0)EdgeOutInDelayReport = 0;
				}
			}
		
			if(g_ScanTime_Pen == 0 && EdgeOutInDelayReport == 0)
			{
				if(thisInfo->tCoord_local_dsp.tOrgPos.tXY.x < bound_th || thisInfo->tCoord_local_dsp.tOrgPos.tXY.x > thisInfo->tCoord.iInternalXRes-bound_th || thisInfo->tCoord_local_dsp.tOrgPos.tXY.y < bound_th || thisInfo->tCoord_local_dsp.tOrgPos.tXY.y > thisInfo->tCoord.iInternalYRes-bound_th) 
				{
					thisInfo->tPenInfo.bReportSkip = 1;
					if(mode == LOCAL_MODE)EdgeOutInDelayReport = 2;
					else 
					{
						EdgeOutInDelayReport = 1;
					}
					EdgeOutInHoverCnt = 0;
				}
			}
		}
	}	
	
	thisInfo->tPenInfo.ucEdgeOutInDelayReport = EdgeOutInDelayReport;
	thisInfo->tPenInfo.PrePos.x = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x;
	thisInfo->tPenInfo.PrePos.y = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y;
}
#endif

#ifdef EdgeConditionMulCoefChange_SW
#ifndef EdgeConditionMulCoefChange_OPCODE1
void algorithm_EdgeMulChange(int mode)
{
	//int left_hover_mul = thisModeConf->EdgePenSetVal.left_hover_mul;
	#if (CUSTOMER == MS || CUSTOMER == NEC)
	//if(mode == LOCAL_HOVER_MODE)
	{
		if(thisInfo->tLabel_local_dsp.ulStrength>0 && thisInfo->tCoord_local_dsp.tPastPos[0].vusS>0)
		{
			if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th)
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 22;
				thisModeConf->EdgePenSetVal.top_hover_mul = 21;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 20;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 21;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th)
			{
				thisModeConf->EdgePenSetVal.right_hover_mul = 21;
				thisModeConf->EdgePenSetVal.top_hover_mul = 21;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				thisModeConf->EdgePenSetVal.right_hover_mul = 21;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 22;
			}				
			else
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 23;
				thisModeConf->EdgePenSetVal.right_hover_mul = 22;
				thisModeConf->EdgePenSetVal.top_hover_mul = 22;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 22;
			}
			
			if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th
			|| thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				if(thisInfo->tLabel_local_dsp.sValidMaxVal>350)
				{					
					thisModeConf->EdgePenSetVal.left_hover_mul -= 2;
					thisModeConf->EdgePenSetVal.right_hover_mul -= 1;
					thisModeConf->EdgePenSetVal.top_hover_mul -= 1;
					thisModeConf->EdgePenSetVal.bottom_hover_mul -= 1;
				}					
			}
		}
	}
	#elif (CUSTOMER == TOSHIBA_PEN)
	//if(mode == LOCAL_HOVER_MODE)
	{
		if(thisInfo->tLabel_local_dsp.ulStrength>0 && thisInfo->tCoord_local_dsp.tPastPos[0].vusS>0)
		{
			if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th)
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 38;
				thisModeConf->EdgePenSetVal.top_hover_mul = 21;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 38;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 21;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th)
			{
				thisModeConf->EdgePenSetVal.right_hover_mul = 37;
				thisModeConf->EdgePenSetVal.top_hover_mul = 21;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				thisModeConf->EdgePenSetVal.right_hover_mul = 37;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 21;
			}				
			else
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 39;
				thisModeConf->EdgePenSetVal.right_hover_mul = 38;
				thisModeConf->EdgePenSetVal.top_hover_mul = 22;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 22;
			}
			
			if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th
			|| thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				if(thisInfo->tLabel_local_dsp.sValidMaxVal>250)
				{					
					thisModeConf->EdgePenSetVal.left_hover_mul -= 1;
					thisModeConf->EdgePenSetVal.right_hover_mul -= 1;
					thisModeConf->EdgePenSetVal.top_hover_mul -= 1;
					thisModeConf->EdgePenSetVal.bottom_hover_mul -= 1;
				}					
			}
		}
	}
	//else if(mode == LOCAL_MODE)
	{
		if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_th)
		{
			if(tTiltInfo.HID_TILT_X < 6500)thisModeConf->EdgePenSetVal.left_mul = 7;
			else if(tTiltInfo.HID_TILT_X > 11500)thisModeConf->EdgePenSetVal.left_mul = 10;
			else thisModeConf->EdgePenSetVal.left_mul = 8;
		}				
		else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_th)
		{
			if(tTiltInfo.HID_TILT_X < 6500)thisModeConf->EdgePenSetVal.right_mul = 9;
			else if(tTiltInfo.HID_TILT_X > 11500)thisModeConf->EdgePenSetVal.right_mul = 6;
			else thisModeConf->EdgePenSetVal.right_mul = 7;
		}
		else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_th)
		{
			if(tTiltInfo.HID_TILT_Y < 6500)thisModeConf->EdgePenSetVal.top_mul = 56;
			else if(tTiltInfo.HID_TILT_Y > 11500)thisModeConf->EdgePenSetVal.top_mul = 69;
			else thisModeConf->EdgePenSetVal.top_mul = 62;
		}
		else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_th)
		{
			if(tTiltInfo.HID_TILT_Y < 6500)thisModeConf->EdgePenSetVal.bottom_mul = 35;
			else if(tTiltInfo.HID_TILT_Y > 11500)thisModeConf->EdgePenSetVal.bottom_mul = 30;
			else thisModeConf->EdgePenSetVal.bottom_mul = 31;
		}
		else
		{
			thisModeConf->EdgePenSetVal.left_mul = 8;
			thisModeConf->EdgePenSetVal.right_mul = 7;
			thisModeConf->EdgePenSetVal.top_mul = 62;
			thisModeConf->EdgePenSetVal.bottom_mul = 31;
		}
	}
	#elif (CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
	#ifdef COVER_GLASS_USE
	//if(mode == LOCAL_HOVER_MODE)
	{
		if(thisInfo->tLabel_local_dsp.ulStrength>0 && thisInfo->tCoord_local_dsp.tPastPos[0].vusS>0)
		{
			if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th)
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 21;
				thisModeConf->EdgePenSetVal.top_hover_mul = 22;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 19;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 21;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th)
			{
				thisModeConf->EdgePenSetVal.right_hover_mul = 21;
				thisModeConf->EdgePenSetVal.top_hover_mul = 22;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				thisModeConf->EdgePenSetVal.right_hover_mul = 21;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 22;
			}				
			else
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 22;
				thisModeConf->EdgePenSetVal.right_hover_mul = 22;
				thisModeConf->EdgePenSetVal.top_hover_mul = 23;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 22;
			}
			
			if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th
			|| thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				if(thisInfo->tLabel_local_dsp.sValidMaxVal>350)
				{					
					thisModeConf->EdgePenSetVal.left_hover_mul -= 2;
					thisModeConf->EdgePenSetVal.right_hover_mul -= 1;
					thisModeConf->EdgePenSetVal.top_hover_mul -= 1;
					thisModeConf->EdgePenSetVal.bottom_hover_mul -= 1;
				}					
			}
		}
	}
	//else if(mode == LOCAL_MODE)
	{
		if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_th)
		{
			if(tTiltInfo.HID_TILT_X < 6500)thisModeConf->EdgePenSetVal.left_mul = 11;
			else if(tTiltInfo.HID_TILT_X > 11500)thisModeConf->EdgePenSetVal.left_mul = 18;
			else thisModeConf->EdgePenSetVal.left_mul = 12;
		}				
		else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_th)
		{
			if(tTiltInfo.HID_TILT_X < 6500)thisModeConf->EdgePenSetVal.right_mul = 18;
			else if(tTiltInfo.HID_TILT_X > 11500)thisModeConf->EdgePenSetVal.right_mul = 12;
			else thisModeConf->EdgePenSetVal.right_mul = 13;
		}
		else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_th)
		{
			if(tTiltInfo.HID_TILT_Y < 6500)thisModeConf->EdgePenSetVal.top_mul = 16;
			else if(tTiltInfo.HID_TILT_Y > 11500)thisModeConf->EdgePenSetVal.top_mul = 30;
			else thisModeConf->EdgePenSetVal.top_mul = 18;
		}
		else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_th)
		{
			if(tTiltInfo.HID_TILT_Y < 6500)thisModeConf->EdgePenSetVal.bottom_mul = 30;
			else if(tTiltInfo.HID_TILT_Y > 11500)thisModeConf->EdgePenSetVal.bottom_mul = 18;
			else thisModeConf->EdgePenSetVal.bottom_mul = 20;
		}
		else
		{
			thisModeConf->EdgePenSetVal.left_mul = 12;
			thisModeConf->EdgePenSetVal.right_mul = 13;
			thisModeConf->EdgePenSetVal.top_mul = 18;
			thisModeConf->EdgePenSetVal.bottom_mul = 20;
		}
	}
	#else
	{
		if(thisInfo->tLabel_local_dsp.ulStrength>0 && thisInfo->tCoord_local_dsp.tPastPos[0].vusS>0)
		{
			if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th)
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 38;
				thisModeConf->EdgePenSetVal.top_hover_mul = 21;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 38;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 21;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th)
			{
				thisModeConf->EdgePenSetVal.right_hover_mul = 37;
				thisModeConf->EdgePenSetVal.top_hover_mul = 21;
			}				
			else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				thisModeConf->EdgePenSetVal.right_hover_mul = 37;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 21;
			}				
			else
			{
				thisModeConf->EdgePenSetVal.left_hover_mul = 39;
				thisModeConf->EdgePenSetVal.right_hover_mul = 38;
				thisModeConf->EdgePenSetVal.top_hover_mul = 22;
				thisModeConf->EdgePenSetVal.bottom_hover_mul = 22;
			}
			
			if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th
			|| thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th)
			{
				if(thisInfo->tLabel_local_dsp.sValidMaxVal>250)
				{					
					thisModeConf->EdgePenSetVal.left_hover_mul -= 1;
					thisModeConf->EdgePenSetVal.right_hover_mul -= 1;
					thisModeConf->EdgePenSetVal.top_hover_mul -= 1;
					thisModeConf->EdgePenSetVal.bottom_hover_mul -= 1;
				}					
			}
		}
	}
	//else if(mode == LOCAL_MODE)
	{
		if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_th)
		{
			if(tTiltInfo.HID_TILT_X < 6500)thisModeConf->EdgePenSetVal.left_mul = 7;
			else if(tTiltInfo.HID_TILT_X > 11500)thisModeConf->EdgePenSetVal.left_mul = 11;
			else thisModeConf->EdgePenSetVal.left_mul = 8;
		}				
		else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_th)
		{
			if(tTiltInfo.HID_TILT_X < 6500)thisModeConf->EdgePenSetVal.right_mul = 10;
			else if(tTiltInfo.HID_TILT_X > 11500)thisModeConf->EdgePenSetVal.right_mul = 6;
			else thisModeConf->EdgePenSetVal.right_mul = 7;
		}
		else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_th)
		{
			if(tTiltInfo.HID_TILT_Y < 6500)thisModeConf->EdgePenSetVal.top_mul = 51;
			else if(tTiltInfo.HID_TILT_Y > 11500)thisModeConf->EdgePenSetVal.top_mul = 63;
			else thisModeConf->EdgePenSetVal.top_mul = 52;
		}
		else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_th)
		{
			if(tTiltInfo.HID_TILT_Y < 6500)thisModeConf->EdgePenSetVal.bottom_mul = 36;
			else if(tTiltInfo.HID_TILT_Y > 11500)thisModeConf->EdgePenSetVal.bottom_mul = 29;
			else thisModeConf->EdgePenSetVal.bottom_mul = 29;
		}
		else
		{
			thisModeConf->EdgePenSetVal.left_mul = 8;
			thisModeConf->EdgePenSetVal.right_mul = 7;
			thisModeConf->EdgePenSetVal.top_mul = 52;
			thisModeConf->EdgePenSetVal.bottom_mul = 29;
		}
	}
	#endif
	#else // MODEL_DEF_DEFAULT
	tEdgePen_t 	*temp_EdgePenSetVal;
	const tEdgePen_t *conf_EdgePenSetVal;
	tPenParaEdge_t 	*temp_PenParaEdgeSetVal;
	const tPenParaEdge_t *conf_PenParaEdgeSetVal;
	int high_delta_edge_ofs, high_delta_corner_ofs;
	int edge_div, edge_max, corner_div, corner_max;
	
	if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_WACOM)
	{
//		temp_EdgePenSetVal = &thisInfo->tEdgePenSetVal;
//		conf_EdgePenSetVal = &thisModeConf->EdgePenSetVal;
//		temp_PenParaEdgeSetVal = &thisInfo->tPenParaEdgeSetVal;
//		conf_PenParaEdgeSetVal = &thisModeConf->PenParaEdgeSetVal;
		edge_div = 40, edge_max = 7, corner_div = 70, corner_max = 3;
	}
	else if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
	{
//		temp_EdgePenSetVal = &thisInfo->tEdgePenSetVal;
//		conf_EdgePenSetVal = &thisModeConf->EdgePenSetVal;
//		temp_PenParaEdgeSetVal = &thisInfo->tPenParaEdgeSetVal;
//		conf_PenParaEdgeSetVal = &thisModeConf->PenParaEdgeSetVal;
		edge_div = 20, edge_max = 13, corner_div = 50, corner_max = 7;
	}
	temp_EdgePenSetVal = &thisInfo->tEdgePenSetVal;
	conf_EdgePenSetVal = &thisModeConf->EdgePenSetVal;
	temp_PenParaEdgeSetVal = &thisInfo->tPenParaEdgeSetVal;
	conf_PenParaEdgeSetVal = &thisModeConf->PenParaEdgeSetVal;
	
	{
		if(thisInfo->tLabel_local_dsp.ulStrength>0 && thisInfo->tCoord_local_dsp.tPastPos[0].vusS>0)
		{
			temp_EdgePenSetVal->left_hover_mul = conf_EdgePenSetVal->left_hover_mul;
			temp_EdgePenSetVal->right_hover_mul = conf_EdgePenSetVal->right_hover_mul;
			temp_EdgePenSetVal->top_hover_mul = conf_EdgePenSetVal->top_hover_mul;
			temp_EdgePenSetVal->bottom_hover_mul = conf_EdgePenSetVal->bottom_hover_mul;
			
			// Hover
			if(1)
			{
				high_delta_edge_ofs = thisInfo->tLabel_local_dsp.sValidMaxVal / edge_div;
				if(high_delta_edge_ofs > edge_max) high_delta_edge_ofs = edge_max;
				high_delta_corner_ofs = thisInfo->tLabel_local_dsp.sValidMaxVal / corner_div;
				if(high_delta_corner_ofs > corner_max) high_delta_corner_ofs = corner_max;
				
				if(thisInfo->tLabel_local_dsp.sValidMaxVal > conf_EdgePenSetVal->high_delta_th)
				{
					if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < conf_EdgePenSetVal->left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < conf_EdgePenSetVal->top_hover_th)
					{
						temp_EdgePenSetVal->left_hover_mul = conf_EdgePenSetVal->left_hover_mul - conf_EdgePenSetVal->left_hover_mul_offset_tl_corner - high_delta_corner_ofs;
						temp_EdgePenSetVal->top_hover_mul = conf_EdgePenSetVal->top_hover_mul - conf_EdgePenSetVal->top_hover_mul_offset_tl_corner - high_delta_corner_ofs;
					}				
					else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < conf_EdgePenSetVal->left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-conf_EdgePenSetVal->bottom_hover_th)
					{
						temp_EdgePenSetVal->left_hover_mul = conf_EdgePenSetVal->left_hover_mul - conf_EdgePenSetVal->left_hover_mul_offset_bl_corner - high_delta_corner_ofs;
						temp_EdgePenSetVal->bottom_hover_mul = conf_EdgePenSetVal->bottom_hover_mul - conf_EdgePenSetVal->bottom_hover_mul_offset_bl_corner - high_delta_corner_ofs;
					}				
					else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-conf_EdgePenSetVal->right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < conf_EdgePenSetVal->top_hover_th)
					{
						temp_EdgePenSetVal->right_hover_mul = conf_EdgePenSetVal->right_hover_mul - conf_EdgePenSetVal->right_hover_mul_offset_tr_corner - high_delta_corner_ofs;
						temp_EdgePenSetVal->top_hover_mul = conf_EdgePenSetVal->top_hover_mul - conf_EdgePenSetVal->top_hover_mul_offset_tr_corner - high_delta_corner_ofs;
					}				
					else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-conf_EdgePenSetVal->right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-conf_EdgePenSetVal->bottom_hover_th)
					{
						temp_EdgePenSetVal->right_hover_mul = conf_EdgePenSetVal->right_hover_mul - conf_EdgePenSetVal->right_hover_mul_offset_br_corner - high_delta_corner_ofs;
						temp_EdgePenSetVal->bottom_hover_mul = conf_EdgePenSetVal->bottom_hover_mul - conf_EdgePenSetVal->bottom_hover_mul_offset_br_corner - high_delta_corner_ofs;
					}
					if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < conf_EdgePenSetVal->left_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < conf_EdgePenSetVal->top_hover_th
					|| thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-conf_EdgePenSetVal->right_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-conf_EdgePenSetVal->bottom_hover_th)
					{
//						if(thisInfo->tLabel_local_dsp.sValidMaxVal>conf_EdgePenSetVal->high_delta_th)
						{
							temp_EdgePenSetVal->left_hover_mul -= (conf_EdgePenSetVal->left_hover_mul_offset_high_delta + high_delta_edge_ofs);
							temp_EdgePenSetVal->right_hover_mul -= (conf_EdgePenSetVal->right_hover_mul_offset_high_delta + high_delta_edge_ofs);
							temp_EdgePenSetVal->top_hover_mul -= (conf_EdgePenSetVal->top_hover_mul_offset_high_delta + high_delta_edge_ofs);
							temp_EdgePenSetVal->bottom_hover_mul -= (conf_EdgePenSetVal->bottom_hover_mul_offset_high_delta + high_delta_edge_ofs);
						}
					}
				}
			}
			else
			{
				if(thisInfo->tLabel_local_dsp.sValidMaxVal>conf_EdgePenSetVal->high_delta_th)
				{
					if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < conf_EdgePenSetVal->left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < conf_EdgePenSetVal->top_hover_th)
					{
						temp_EdgePenSetVal->left_hover_mul = conf_EdgePenSetVal->left_hover_mul - conf_EdgePenSetVal->left_hover_mul_offset_tl_corner;
						temp_EdgePenSetVal->top_hover_mul = conf_EdgePenSetVal->top_hover_mul - conf_EdgePenSetVal->top_hover_mul_offset_tl_corner;
					}				
					else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < conf_EdgePenSetVal->left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-conf_EdgePenSetVal->bottom_hover_th)
					{
						temp_EdgePenSetVal->left_hover_mul = conf_EdgePenSetVal->left_hover_mul - conf_EdgePenSetVal->left_hover_mul_offset_bl_corner;
						temp_EdgePenSetVal->bottom_hover_mul = conf_EdgePenSetVal->bottom_hover_mul - conf_EdgePenSetVal->bottom_hover_mul_offset_bl_corner;
					}				
					else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-conf_EdgePenSetVal->right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < conf_EdgePenSetVal->top_hover_th)
					{
						temp_EdgePenSetVal->right_hover_mul = conf_EdgePenSetVal->right_hover_mul - conf_EdgePenSetVal->right_hover_mul_offset_tr_corner;
						temp_EdgePenSetVal->top_hover_mul = conf_EdgePenSetVal->top_hover_mul - conf_EdgePenSetVal->top_hover_mul_offset_tr_corner;
					}				
					else if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-conf_EdgePenSetVal->right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-conf_EdgePenSetVal->bottom_hover_th)
					{
						temp_EdgePenSetVal->right_hover_mul = conf_EdgePenSetVal->right_hover_mul - conf_EdgePenSetVal->right_hover_mul_offset_br_corner;
						temp_EdgePenSetVal->bottom_hover_mul = conf_EdgePenSetVal->bottom_hover_mul - conf_EdgePenSetVal->bottom_hover_mul_offset_br_corner;
					}				
		//			else
		//			{
		//				temp_EdgePenSetVal->left_hover_mul = conf_EdgePenSetVal->left_hover_mul;
		//				temp_EdgePenSetVal->right_hover_mul = conf_EdgePenSetVal->right_hover_mul;
		//				temp_EdgePenSetVal->top_hover_mul = conf_EdgePenSetVal->top_hover_mul;
		//				temp_EdgePenSetVal->bottom_hover_mul = conf_EdgePenSetVal->bottom_hover_mul;
		//			}		
					if(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < conf_EdgePenSetVal->left_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < conf_EdgePenSetVal->top_hover_th
					|| thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-conf_EdgePenSetVal->right_hover_th || thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-conf_EdgePenSetVal->bottom_hover_th)
					{
		//				if(thisInfo->tLabel_local_dsp.sValidMaxVal>conf_EdgePenSetVal->high_delta_th)
						{
							temp_EdgePenSetVal->left_hover_mul -= conf_EdgePenSetVal->left_hover_mul_offset_high_delta;
							temp_EdgePenSetVal->right_hover_mul -= conf_EdgePenSetVal->right_hover_mul_offset_high_delta;
							temp_EdgePenSetVal->top_hover_mul -= conf_EdgePenSetVal->top_hover_mul_offset_high_delta;
							temp_EdgePenSetVal->bottom_hover_mul -= conf_EdgePenSetVal->bottom_hover_mul_offset_high_delta;
						}			
					}
				}
			}
		}		
	}
	#endif
}
#endif
#endif

#if 1//def FastDrawLatencyUp
void algorithm_FastDrawLatencyUp(void)
{
	static uint8_t g_LatencyUpCnt = 0;
	if(thisInfo->tCoord_local_dsp.PenContactCnt > 6)
	{
		tXY_t coord_array[5];
		coord_array[0] = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY;
		coord_array[1] = thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY;
		coord_array[2] = thisInfo->tCoord_local_dsp.tOrgPastPos2.tXY;
		coord_array[3] = meanInterpolate(coord_array, 0,3);	
		int dist = algorithm_coord_calc_distance(coord_array[3], thisInfo->tCoord_local_dsp.tOrgPos.tXY);
		if(dist>thisModeConf->PenCoord.uclatency_up_dis_condition || g_LatencyUpCnt>thisModeConf->PenCoord.uclatency_up_cnt_condition)
		{
			if(g_LatencyUpCnt>thisModeConf->PenCoord.uclatency_up_cnt_condition)
			{
				coord_array[0] = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
				coord_array[1] = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY;
				coord_array[2] = thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY;
				coord_array[3] = thisInfo->tCoord_local_dsp.tPos.tXY;
				//coord_array[4]= meanInterpolate(coord_array, 0,4);	
				coord_array[4]= meanInterpolate(coord_array, 0,2);	
				dist = algorithm_coord_calc_distance(coord_array[4], thisInfo->tCoord_local_dsp.tPos.tXY);
				dist += thisModeConf->PenCoord.clatency_up_dis_offset;
				if(dist<10)dist=10;
				if(dist>_BV(thisModeConf->Coord.lMoveSmoothingLevel))dist=_BV(thisModeConf->Coord.lMoveSmoothingLevel);
				thisInfo->tCoord_local_dsp.tPos.tXY.x = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - dist) * thisInfo->tCoord_local_dsp.tPos.tXY.x + dist * coord_array[4].x + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;					
				thisInfo->tCoord_local_dsp.tPos.tXY.y = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - dist) * thisInfo->tCoord_local_dsp.tPos.tXY.y + dist * coord_array[4].y + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
				if(dist>thisModeConf->PenCoord.uclatency_up_dis_condition)g_LatencyUpCnt=thisModeConf->PenCoord.uclatency_up_cnt_condition+7;
				else g_LatencyUpCnt--;
			}
			else g_LatencyUpCnt++;
		}
		else g_LatencyUpCnt = 0;
	}
	else g_LatencyUpCnt = 0;
}
#endif

#ifdef DisBasedSmoothAdd_SW
#ifndef DisBasedSmoothAdd_OPCODE
void algorithm_DisBasedSmoothAdd(int mode)
{		
	if((mode == LOCAL_MODE || mode == LOCAL_HOVER_MODE) && thisInfo->tCoord_local_dsp.tPos.vusS>0 && thisInfo->tCoord_local_dsp.tPastPos[0].vusS>0)
	{		
//		#ifdef FastDrawLatencyUp
//		algorithm_FastDrawLatencyUp();
//		#endif

		int f = 0;
		int prev_curr_dist = algorithm_coord_calc_distance(thisInfo->tCoord_local_dsp.tPos.tXY, thisInfo->tCoord_local_dsp.tPastPos[0].tXY);
		
	#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN) 
		if(thisInfo->tCoord_local_dsp.tPos.tXY.x < (1<<(POS_BOOST_SHIFT_)) || thisInfo->tCoord_local_dsp.tPos.tXY.y > thisInfo->tCoord.iInternalYRes-(1<<(POS_BOOST_SHIFT_))
		|| thisInfo->tCoord_local_dsp.tPos.tXY.x > thisInfo->tCoord.iInternalXRes-(1<<(POS_BOOST_SHIFT_)) || thisInfo->tCoord_local_dsp.tPos.tXY.y < (1<<(POS_BOOST_SHIFT_)))
	#else
		if(thisInfo->tCoord_local_dsp.tPos.tXY.x < thisModeConf->EdgePenSetVal.left_hover_th || thisInfo->tCoord_local_dsp.tPos.tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th 
		|| thisInfo->tCoord_local_dsp.tPos.tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th || thisInfo->tCoord_local_dsp.tPos.tXY.y < thisModeConf->EdgePenSetVal.top_hover_th)		
	#endif
		{	
			if(mode == LOCAL_HOVER_MODE && thisModeConf->PenDisBaseSmoothSetVal.c_edge_smooth_offset_hover<127)	
			{
				f = 1;
				prev_curr_dist+=thisModeConf->PenDisBaseSmoothSetVal.c_edge_smooth_offset_hover;
			}
			else if(mode == LOCAL_MODE && thisModeConf->PenDisBaseSmoothSetVal.c_edge_smooth_offset_contact<127 && (prev_curr_dist < thisModeConf->PenDisBaseSmoothSetVal.uc_edge_smooth_dis_condition_contact || 255 == thisModeConf->PenDisBaseSmoothSetVal.uc_edge_smooth_dis_condition_contact))
			{
				#if (CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN) 
				if(prev_curr_dist < 20)
					f = 2;
				else 
				#endif
				{
					f = 3;
					prev_curr_dist+=thisModeConf->PenDisBaseSmoothSetVal.c_edge_smooth_offset_contact;
				}
			}
		}
		
		if(f==0 && mode == LOCAL_MODE && thisModeConf->PenDisBaseSmoothSetVal.uc_global_smooth_dis_condition_contact > 0 && prev_curr_dist < thisModeConf->PenDisBaseSmoothSetVal.uc_global_smooth_dis_condition_contact)
		{
			f=3;
			prev_curr_dist+=thisModeConf->PenDisBaseSmoothSetVal.c_global_smooth_offset_contact;
		}
		
		if(f>0)
		{
			//if(f==1)prev_curr_dist+=thisModeConf->EdgePenSetVal.edge_smooth_offset_hover;
			//else if(f==2)prev_curr_dist+=thisModeConf->EdgePenSetVal.edge_smooth_offset_contact;
			//else prev_curr_dist+=thisModeConf->EdgePenSetVal.global_smooth_offset_contact;
			
			if(prev_curr_dist < 10)
				prev_curr_dist = 10;
				
			if(prev_curr_dist > _BV(thisModeConf->Coord.lMoveSmoothingLevel))
				prev_curr_dist = _BV(thisModeConf->Coord.lMoveSmoothingLevel);

			if(f==1 &&
			#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN) 
			prev_curr_dist < 0
			#else
			prev_curr_dist < 127
			#endif
			)
			{
				thisInfo->tCoord_local_dsp.tPos.tXY.x = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * thisInfo->tCoord_local_dsp.tPos.tXY.x + prev_curr_dist * thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
				thisInfo->tCoord_local_dsp.tPos.tXY.y = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * thisInfo->tCoord_local_dsp.tPos.tXY.y + prev_curr_dist * thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
			}
			else 
			{	
				if(f==2)
				{
					prev_curr_dist = abs(thisInfo->tCoord_local_dsp.tPos.tXY.x - thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x);
					//if( prev_curr_dist <= thisModeConf->EdgePenSetVal.edge_smooth_dis_condition_contact )
					{
						prev_curr_dist+=thisModeConf->PenDisBaseSmoothSetVal.c_edge_smooth_offset_contact;
						if(prev_curr_dist < 10)prev_curr_dist = 10;			
						if(prev_curr_dist > _BV(thisModeConf->Coord.lMoveSmoothingLevel))prev_curr_dist = _BV(thisModeConf->Coord.lMoveSmoothingLevel);
						thisInfo->tCoord_local_dsp.tPos.tXY.x = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x + prev_curr_dist * thisInfo->tCoord_local_dsp.tPos.tXY.x + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
					}
					prev_curr_dist = abs(thisInfo->tCoord_local_dsp.tPos.tXY.y - thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y);
					//if( prev_curr_dist <= thisModeConf->EdgePenSetVal.edge_smooth_dis_condition_contact )
					{
						prev_curr_dist+=thisModeConf->PenDisBaseSmoothSetVal.c_edge_smooth_offset_contact;
						if(prev_curr_dist < 10)prev_curr_dist = 10;			
						if(prev_curr_dist > _BV(thisModeConf->Coord.lMoveSmoothingLevel))prev_curr_dist = _BV(thisModeConf->Coord.lMoveSmoothingLevel);		
						//thisInfo->tCoord_local_dsp.tPos.tXY.x = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x + prev_curr_dist * thisInfo->tCoord_local_dsp.tPos.tXY.x + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;					
						thisInfo->tCoord_local_dsp.tPos.tXY.y = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y + prev_curr_dist * thisInfo->tCoord_local_dsp.tPos.tXY.y + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;						
						
					}
				}
				else
				{
					thisInfo->tCoord_local_dsp.tPos.tXY.x = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x + prev_curr_dist * thisInfo->tCoord_local_dsp.tPos.tXY.x + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;					
					thisInfo->tCoord_local_dsp.tPos.tXY.y = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y + prev_curr_dist * thisInfo->tCoord_local_dsp.tPos.tXY.y + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
				}
			}
			
		}
		
		if(mode == LOCAL_HOVER_MODE)
		{
			f = 0;
			prev_curr_dist = algorithm_coord_calc_distance(thisInfo->tCoord_local_dsp.tPos.tXY, thisInfo->tCoord_local_dsp.tPastPos[0].tXY);
			#if 1//(CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
			if( (thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < (1<<(POS_BOOST_SHIFT_)) && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < (1<<(POS_BOOST_SHIFT_))) ||
			(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < (1<<(POS_BOOST_SHIFT_)) && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-(1<<(POS_BOOST_SHIFT_))) ||
			(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-(1<<(POS_BOOST_SHIFT_)) && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < (1<<(POS_BOOST_SHIFT_))) ||
			(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-(1<<(POS_BOOST_SHIFT_)) && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-(1<<(POS_BOOST_SHIFT_))) )
			#else
			if( (thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th) ||
			(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x < thisModeConf->EdgePenSetVal.left_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th) ||
			(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y < thisModeConf->EdgePenSetVal.top_hover_th) ||
			(thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x > thisInfo->tCoord.iInternalXRes-thisModeConf->EdgePenSetVal.right_hover_th && thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y > thisInfo->tCoord.iInternalYRes-thisModeConf->EdgePenSetVal.bottom_hover_th) )
			#endif
			{
				if(thisInfo->tCoord_local_dsp.tPos.MaxDelta < thisModeConf->PenDisBaseSmoothSetVal.us_corner_smooth_delta_condition_hover && thisModeConf->PenDisBaseSmoothSetVal.us_corner_smooth_delta_condition_hover>0)
				{
					f = 1;
					prev_curr_dist+=thisModeConf->PenDisBaseSmoothSetVal.c_corner_smooth_offset_hover;
				}	
			}
			
			if(f==0 && thisModeConf->PenDisBaseSmoothSetVal.uc_global_smooth_delta_condition_hover > 0 && thisInfo->tCoord_local_dsp.tPos.MaxDelta < thisModeConf->PenDisBaseSmoothSetVal.uc_global_smooth_delta_condition_hover)
			{	
				if(prev_curr_dist < thisModeConf->PenDisBaseSmoothSetVal.uc_global_smooth_dis_condition_hover)
				{
					f = 2;
					prev_curr_dist+=thisModeConf->PenDisBaseSmoothSetVal.c_global_smooth_offset_hover;
				}
			}
			
			if(f>0)
			{
				if(prev_curr_dist < 10)
					prev_curr_dist = 10;
					
				if(prev_curr_dist > _BV(thisModeConf->Coord.lMoveSmoothingLevel))
					prev_curr_dist = _BV(thisModeConf->Coord.lMoveSmoothingLevel);
				
				thisInfo->tCoord_local_dsp.tPos.tXY.x = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x + prev_curr_dist * thisInfo->tCoord_local_dsp.tPos.tXY.x + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;					
				thisInfo->tCoord_local_dsp.tPos.tXY.y = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - prev_curr_dist) * thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y + prev_curr_dist * thisInfo->tCoord_local_dsp.tPos.tXY.y + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;
			}
		}
	}
}	
#endif
#endif

void algorithm_IdealLineInterpolation(void)
{
	thisInfo->tPenInfo.bIdeal_inter_tmp_change = 0;
	
	if(thisInfo->tCoord_local_dsp.PenContactCnt > 6)
	{
		if(thisInfo->tCoord_local_dsp.PenContactCnt == 7)
			thisInfo->tPenInfo.pre_store_pos = thisInfo->tCoord_local_dsp.tPos.tXY;
		else
		{
			int dist = algorithm_coord_calc_distance(thisInfo->tPenInfo.pre_store_pos, thisInfo->tCoord_local_dsp.tPos.tXY);
			if(dist>thisModeConf->PenCoord.ucideal_inter_dis)
			{
				//pre_store_pos1 = pre_store_pos;
				thisInfo->tPenInfo.pre_store_pos = thisInfo->tCoord_local_dsp.tPos.tXY;
				thisInfo->tPenInfo.uc_pre_store_cnt++;
			}
			else
			{
				if(thisInfo->tPenInfo.uc_pre_store_cnt > 3)
				{
#if (IdealInterOnlyCorner == YES)
					if(thisModeConf->PenCoord.us_ideal_inter_only_corner == 0 || (thisModeConf->PenCoord.us_ideal_inter_only_corner > 0 && 2 == algorithm_coord_IsEdgeArea(&thisInfo->tCoord_local_dsp.tOrgPos.tXY, thisModeConf->PenCoord.us_ideal_inter_only_corner)))
#endif					
					{
						thisInfo->tPenInfo.ideal_inter_tmp_pos = thisInfo->tCoord_local_dsp.tPos.tXY;
						dist*=thisModeConf->PenCoord.ucideal_inter_mv;
						thisInfo->tCoord_local_dsp.tPos.tXY.x = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - dist) * thisInfo->tPenInfo.pre_store_pos.x + dist * thisInfo->tCoord_local_dsp.tPos.tXY.x + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;	
						thisInfo->tCoord_local_dsp.tPos.tXY.y = ((_BV(thisModeConf->Coord.lMoveSmoothingLevel) - dist) * thisInfo->tPenInfo.pre_store_pos.y + dist * thisInfo->tCoord_local_dsp.tPos.tXY.y + _BV(thisModeConf->Coord.lMoveSmoothingLevel-1)) >> thisModeConf->Coord.lMoveSmoothingLevel;																																			
						thisInfo->tPenInfo.bIdeal_inter_tmp_change = 1;
					}
				}
			}
		}	
	}
}

void algorithm_PannelOutSideReportException(int mode,int sPMode)
{
	int r,c,rs,re,cs,ce,e_sum,dist;
	
	if(thisInfo->tCoord_local_dsp.tPos.vusS>0)
	{
		if(mode == LOCAL_HOVER_MODE && thisModeConf->PenCoord.usPannelOutSideHoverExceptionTH > 0)
		{
			e_sum = 0;
			rs = re = cs = ce = -1;
			if(thisInfo->tCoord_local_dsp.tOrgPos.tXY.x < -thisModeConf->PenCoord.ucPannelOutSideHoverExceptionEdgeDis)
			{
				rs = MAX(0,thisInfo->tLabel_local_dsp.tValidMaxPos.r-1);
				re = MIN(thisInfo->tLabel_local_dsp.tValidMaxPos.r+1,PEN_COORD_ROW_MAX-1);
				cs = thisInfo->tLabel_local_dsp.tValidMaxPos.c+1;
				ce = thisInfo->tLabel_local_dsp.tValidMaxPos.c+1;
			}
			else if(thisInfo->tCoord_local_dsp.tOrgPos.tXY.x > thisInfo->tCoord.iInternalXRes+thisModeConf->PenCoord.ucPannelOutSideHoverExceptionEdgeDis)
			{
				rs = MAX(0,thisInfo->tLabel_local_dsp.tValidMaxPos.r-1);
				re = MIN(thisInfo->tLabel_local_dsp.tValidMaxPos.r+1,PEN_COORD_ROW_MAX-1);
				cs = thisInfo->tLabel_local_dsp.tValidMaxPos.c-1;
				ce = thisInfo->tLabel_local_dsp.tValidMaxPos.c-1;						
			}											
			else if(thisInfo->tCoord_local_dsp.tOrgPos.tXY.y < -thisModeConf->PenCoord.ucPannelOutSideHoverExceptionEdgeDis)
			{
				rs = thisInfo->tLabel_local_dsp.tValidMaxPos.r+1;
				re = thisInfo->tLabel_local_dsp.tValidMaxPos.r+1;
				cs = MAX(0,thisInfo->tLabel_local_dsp.tValidMaxPos.c-1);
				ce = MIN(COL_MAX-1,thisInfo->tLabel_local_dsp.tValidMaxPos.c+1);	
			}
			else if(thisInfo->tCoord_local_dsp.tOrgPos.tXY.y > thisInfo->tCoord.iInternalYRes+thisModeConf->PenCoord.ucPannelOutSideHoverExceptionEdgeDis)
			{
				rs = thisInfo->tLabel_local_dsp.tValidMaxPos.r-1;
				re = thisInfo->tLabel_local_dsp.tValidMaxPos.r-1;
				cs = MAX(0,thisInfo->tLabel_local_dsp.tValidMaxPos.c-1);
				ce = MIN(COL_MAX-1,thisInfo->tLabel_local_dsp.tValidMaxPos.c+1);	
			}
			
			if(rs != -1)
			{
				for(r=rs; r<=re; r++)for(c=cs; c<=ce; c++)
					e_sum += HAL_READ_LOCAL_DELTA_IMAGE(r,c);
			
				if(e_sum < thisModeConf->PenCoord.usPannelOutSideHoverExceptionTH)
					thisInfo->tPenInfo.bReportSkip=1;
			}
		}
		else if(mode == LOCAL_MODE && thisModeConf->PenCoord.usPannelOutSideContactExceptionTH > 0)
		{
			if(thisInfo->tCoord_local_dsp.tOrgPos.tXY.x < -thisModeConf->PenCoord.ucPannelOutSideContactExceptionEdgeDis || thisInfo->tCoord_local_dsp.tOrgPos.tXY.x > thisInfo->tCoord.iInternalXRes+thisModeConf->PenCoord.ucPannelOutSideContactExceptionEdgeDis
			|| thisInfo->tCoord_local_dsp.tOrgPos.tXY.y < -thisModeConf->PenCoord.ucPannelOutSideContactExceptionEdgeDis || thisInfo->tCoord_local_dsp.tOrgPos.tXY.y > thisInfo->tCoord.iInternalYRes+thisModeConf->PenCoord.ucPannelOutSideContactExceptionEdgeDis)
			{
				if(thisInfo->tCoord_local_dsp.tPos.vusS < thisModeConf->PenCoord.usPannelOutSideContactExceptionTH)
				{
					int dis,min_dis = 32767;
					dis = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x - 0;
					if(dis < min_dis)min_dis = dis;
					dis = thisInfo->tCoord.iInternalXRes - thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x;
					if(dis < min_dis)min_dis = dis;
					dis = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y - 0;
					if(dis < min_dis)min_dis = dis;
					dis = thisInfo->tCoord.iInternalYRes - thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y;
					if(dis < min_dis)min_dis = dis;
					
					if(thisInfo->tCoord_local_dsp.tPastPos[0].vusS>0 && sPMode == LOCAL_MODE && thisInfo->tPenInfo.bPrevPenContact==YES && min_dis > -thisModeConf->PenCoord.ucPannelOutSideContactExceptionEdgeDis)
					{
						dist = algorithm_coord_calc_distance(thisInfo->tCoord_local_dsp.tPastPos[0].tXY, thisInfo->tCoord_local_dsp.tPos.tXY);
						if(dist < thisModeConf->PenCoord.ucPannelOutSideContactExceptionPreDis)
							thisInfo->tPenInfo.bReportSkip=1;
					}
					else thisInfo->tPenInfo.bReportSkip=1;
				}
			}
		}
	}
}
		
extern int16_t g_sPenData_Max[2][12];
//extern int16_t g_sPenData_1st_Max[12];
//extern int16_t g_sPenData_2nd_Max[12];
#ifdef TiltAccuracyTest
int change_offset2 = 1;
#endif
#if (PEN_Edge_UsePerMaxSum == YES)
uint32_t ulExtStrengthArray[10] = {0,};
uint32_t ulExtStrengthAvg = 0;
#endif
void Call_DSP_B_Func(int index, int mode)
{
	int rs, re, cs, ce;
	static int sPMode = 0;
	static bool_t temp_PenContact;
	static uint16_t us_pendata_pressure = 0;
	static uint8_t MarkB_r = 0;
	static int MarkB = 0;
	uint8_t Tilt_On = 0;
	static uint8_t ucTmpMarkBoundaryNum = 0;
	uint8_t LineFilterRowStartOffset = 0;
	uint8_t LineFilterBaseStartOffset = 0;
	static bool_t LineFilter_r = 0;
	uint8_t ucColStart=0, ucColEnd=COL_MAX, ucSmpNum=4;
#ifdef FirstTiltWaitReport	
	static bool_t ReportSkip_FirstTiltWait = 0;
#endif	
#ifdef FirstTiltWaitReportMS
	static bool_t ReportSkip_FirstTiltWait_MS = 0;
#endif	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	static bool_t change = 0;
#endif
	static tXY_t TiltTmpPos; 
#ifdef TILT_ON
//	if(ACTIVEPEN_TYPE_LOCAL_WACOM==gAlgoRawDataType)
//		Tilt_On=1;
//	else 
	if(ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType)
		Tilt_On=2;
	else if(ACTIVEPEN_TYPE_LOCAL_WGP==gAlgoRawDataType)
		Tilt_On=3;
#endif
	
	switch(index)
	{
		case PEN_COORD_INIT :
		{		
#if (CalculateDeltaLocalSearch_OPCODE && USED_DSPA_FUNC_FOR_PEN_SEARCH)
			alogorithm_dspA_get_addr(mode);
			if(thisModeConf->SensingFilter.ucLocalSearchModeLineFilter == 2 && mode == LOCAL_SEARCH_MODE)
				alogorithm_local_linefilter_dspA(thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode,LOCAL_SEARCH_MODE);
#endif
			
#if USED_DSPA_FUNC_FOR_PEN_LOCAL
			alogorithm_dspA_get_addr(mode);
			if(thisModeConf->SensingFilter.cLineFilter_Pen == 2 && (mode == LOCAL_MODE || mode == LOCAL_HOVER_MODE))
				alogorithm_local_linefilter_dspA(thisModeConf->BaseLine.b2MUX_SUM_LocalMode,LOCAL_MODE);
#endif
			
			if(thisInfo->tPenInfo.bPrevPenContact == YES && thisInfo->tPenInfo.bPenContact == NO)
				thisInfo->tPenInfo.us_pendata_pressure = us_pendata_pressure;
			
			if(/*ACTIVEPEN_TYPE_LOCAL_WACOM == gAlgoRawDataType||*/ACTIVEPEN_TYPE_LOCAL_WGP == gAlgoRawDataType)
				temp_PenContact = thisInfo->tPenInfo.bPenContact;
			
			if(mode != LOCAL_TILT_MODE)
			{
				if(sPMode != mode)
				{
					if(mode == LOCAL_MODE)
					{
						algorithm_coord_init_local_DSP();    	
						thisInfo->tPenInfo.pre_store_pos.x = -1;	
						thisInfo->tPenInfo.uc_pre_store_cnt = 0;			
	//					Tilt_cnt=1;
						thisInfo->tPenInfo.bReportSkip = thisInfo->tPenInfo.bPosUpdateSkip = 0;
						thisInfo->tCoord_local_dsp.PenContactCnt = 0;
						thisInfo->tPenInfo.bPenPostProcessFlag = 0;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)		
	#ifdef TILT_ON
						if(Tilt_On==1)
						{
							thisInfo->tTiltInfo.sTilt_cnt=1;
		#ifdef FirstTiltWaitReport
							thisInfo->tTiltInfo.HID_TILT_X = thisInfo->tTiltInfo.Smooth_PastTilt.x = 9000;
							thisInfo->tTiltInfo.HID_TILT_Y = thisInfo->tTiltInfo.Smooth_PastTilt.y = 9000;
							if(g_RetVal!=PARTIAL_PEN_COORD2)ReportSkip_FirstTiltWait=1;
		#endif			
							if(g_RetVal==PARTIAL_PEN_COORD2 && thisInfo->tPenInfo.bPenContact == YES)
							{
								thisInfo->tPenInfo.bReportSkip=thisInfo->tPenInfo.bPosUpdateSkip=1;
		#ifdef FirstTiltWaitReport
								ReportSkip_FirstTiltWait=1;
		#endif
							}
						}
	#endif
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
						if(Tilt_On == 2)
						{
	#ifdef FirstTiltWaitReportMS
							ReportSkip_FirstTiltWait_MS = 1;
	#else
							thisInfo->tTiltInfo.sTilt_cnt=2;
	#endif
						}
#endif
						if(Tilt_On==3 && thisInfo->tTiltInfo.sTilt_cnt > 1)thisInfo->tTiltInfo.sTilt_cnt=2;
#if (PEN_Edge_UsePerMaxSum == YES)						
						ulExtStrengthAvg = thisModeConf->PenParaEdgeSetVal.ulExtStrengthInit;
						memset(ulExtStrengthArray,0,sizeof(ulExtStrengthArray));
#endif
					}
					else
						thisInfo->tCoord_local_dsp.PenContactCnt = 0;
				}
			
#ifdef FirstTiltWaitReport
				if(Tilt_On==1 && thisInfo->tPenInfo.bReportSkip == 0 && ReportSkip_FirstTiltWait==1 && g_RetVal==PARTIAL_PEN_COORD2)
				{
					ReportSkip_FirstTiltWait = 0;
					thisInfo->tTiltInfo.sTilt_cnt=1;
				}
				if(Tilt_On==1 && ReportSkip_FirstTiltWait==1){
					thisInfo->tPenInfo.bReportSkip=1;
					thisInfo->tTiltInfo.sTilt_cnt=1;
				}
#endif
			}
			
			DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE0);
			DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE0, COL_MAX);
			DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE0);
			DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE0, PEN_COORD_ROW_MAX);//40

			DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE2);
			DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE2, (COL_MAX+2*PAD_));
			DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE2);
			DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE2, (PEN_COORD_ROW_MAX+2*PAD_));

			DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE3);
			DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE3, (COL_MAX));
			DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE3);
			DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE3, (ROW_MAX));

			DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE1);
			DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE1, LABEL_INFO_SIZE);
			DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE1);
			DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE1, LOOSE_POSBUF_);

#ifdef CalculateDeltaLocalSearch_OPCODE
			if(mode == LOCAL_SEARCH_MODE)
			{
		#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
				DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE1);
				DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE1, ZERO_FINGER_RAWDATA_MASK_COL_NUM);
				DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE1);
				DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE1, ROW_MAX);
		#endif
				if(thisModeConf->SensingFilter.ucLocalSearchModeLineFilter != 1)
					thisInfo->tPenInfo.ucDSP_B_Index++;
			}
			else if(mode == LOCAL_TILT_MODE)
				if(thisModeConf->SensingFilter.bRingRawLineFilter == 0)thisInfo->tPenInfo.ucDSP_B_Index++;
			else if(mode == LOCAL_MODE || mode == LOCAL_HOVER_MODE)
				if(thisModeConf->SensingFilter.cLineFilter_Pen != 1)thisInfo->tPenInfo.ucDSP_B_Index+=2;
#else	
			if( (thisModeConf->SensingFilter.cLineFilter_Pen != 1 && (mode == LOCAL_MODE || mode == LOCAL_HOVER_MODE)) 
			||	(thisModeConf->SensingFilter.bRingRawLineFilter == 0 && mode == LOCAL_TILT_MODE) )
				thisInfo->tPenInfo.ucDSP_B_Index++;
#endif
#if (PEN_REMOVE_EDGE_EN == YES)
			if(thisInfo->tCoord_local_dsp.tPos.vusR == 0)
			{
				thisInfo->tCoord_local_dsp.bRemoveEdge = 0;
			}
#endif
				
			TMH_PenCoordInitialize(&thisInfo->tCoord_local_dsp, &thisInfo->tDelta_local);
		}
		break;

		case PEN_LINE_FILTER:
		{
#if USED_ADAPTIVE_LOCAL_SENSING
			if(mode != LOCAL_SEARCH_MODE)
			{
				if(sensingRoicStart != ROIC_NUM)
				{
					ucSmpNum = 1;
					ucColStart = 6*sensingRoicStart;
					ucColEnd = ucColStart + 2*ROIC_COL_SIZE;
				}
			}
#endif /* USED_ADAPTIVE_LOCAL_SENSING */
			if((thisModeConf->BaseLine.b2MUX_SUM_LocalMode == 1 && (mode == LOCAL_MODE || mode == LOCAL_HOVER_MODE)) || 
			(thisModeConf->BaseLine.b2MUX_SUM_LocalSearchMode == 1 && mode == LOCAL_SEARCH_MODE) ||
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
			(thisModeConf->PenTilt.b2MUX_SUM_RingMode == 1 && mode == LOCAL_TILT_MODE) ||
#endif
			(thisModeConf->BaseLine.bPen_2BASE == 1 && mode != LOCAL_TILT_MODE))
			{
				if(LineFilter_r == 0)
				{
					thisInfo->tPenInfo.ucDSP_B_Index--;
					LineFilter_r = 1;
					LineFilterRowStartOffset = PEN_COORD_ROW_MAX;
					if(thisModeConf->BaseLine.bPen_2BASE == 1 && mode != LOCAL_TILT_MODE)
						LineFilterBaseStartOffset = ROW_MAX;
					else 
						LineFilterBaseStartOffset = 0;
				}
				else 
				{
					LineFilter_r = 0;
					LineFilterRowStartOffset = 0;
					LineFilterBaseStartOffset = 0;
				}
			}
			else
			{
				LineFilter_r = 0;
				if(thisModeConf->BaseLine.ucPP_MUX_Select && mode != LOCAL_TILT_MODE)
					LineFilterRowStartOffset = PEN_COORD_ROW_MAX;
				else LineFilterRowStartOffset = 0;
				LineFilterBaseStartOffset = 0;
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)	
				if(mode == LOCAL_TILT_MODE)LineFilterRowStartOffset = PEN_COORD_ROW_MAX;
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)	
				if(mode == LOCAL_TILT_MODE && ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType)LineFilterRowStartOffset = PEN_COORD_ROW_MAX;
#endif
			}
	
#ifdef CalculateDeltaLocalSearch_OPCODE
			if((mode != LOCAL_SEARCH_MODE) && LineFilter_r==0)thisInfo->tPenInfo.ucDSP_B_Index++;
#endif
			
			TMH_PenLineFilter(thisInfo->tPenInfo.pTmpModeRawImg, thisInfo->tPenInfo.pTmpModeBaseImg, ucColStart, ucColEnd, PEN_COORD_ROW_MAX, thisInfo->tPenInfo.usTmpModeRowStart+LineFilterBaseStartOffset,ucSmpNum,LineFilterRowStartOffset);			
		}
		break;

#ifdef CalculateDeltaLocalSearch_OPCODE
		case PEN_CAL_DELTA:
		{
			algorithm_local_baseline_calculate_delta_pre(mode);

			TMH_PenCalDelta(thisInfo->tPenInfo.pTmpModeRawImg, thisInfo->tPenInfo.pTmpModeBaseImg, HAL_GET_LOCAL_DELTA_IMAGE_PTR(), g_pFullHoverImage, 
			HAL_GET_LOCAL_RING_RAW_IMAGE_PTR(), HAL_GET_RING_DELTA_IMAGE_PTR(), HAL_GET_LOCAL_LABEL_IMAGE_PTR(), &thisInfo->PenCalcDeltaSetVal, &thisInfo->tDelta_local, mode);			
		}
		break;
#endif
		
		case PEN_NOISE_REDUCTION:
		{
			if(mode == LOCAL_HOVER_MODE)
			{
				if(thisInfo->tPenInfo.ucHover_cnt == 0)
				{
					algorithm_hover_accum_process();
					thisInfo->tPenInfo.ucHover_cnt = 1;
				}
				else
				{
					if(thisInfo->tPenInfo.ucHover_cnt++ >= 254)thisInfo->tPenInfo.ucHover_cnt = thisModeConf->Noise.ucHoverNoiseRejectFrm+1;
				}

#if USED_DSPA_FUNC_FOR_PEN_LOCAL
				if(p_currentRowStart != currentRowStart && thisModeConf->BaseLine.bDspA_LocalMode_CalculateDelta)
					algorithm_hover_accum_move_1();
#endif
			}
			else if(mode == LOCAL_MODE)
			{
				thisInfo->tPenInfo.ucHover_cnt = 0;
#if (ADAPTOR_NOISE_ALGO_EN)
				if(thisInfo->tPenInfo.bPrevPenContact == NO && thisInfo->tPenInfo.bPenContact == YES)
					memset(LOCALNOISEBUF2,0,sizeof(LOCALNOISEBUF2));
#endif
				//if(p_currentRowStart != currentRowStart)algorithm_hover_accum_move(); // When Prev Delta Use at Local_Mode, current all PJT not use, 200625 HanCH
			}
			
#ifdef CalculateDeltaLocalSearch_OPCODE
			if(mode == LOCAL_SEARCH_MODE)
				algorithm_local_baseline_calculate_delta_post(mode);
			else
#endif
#ifdef TILT_ON
				if(mode == LOCAL_TILT_MODE)
					algorithm_local_baseline_calculate_delta_Tilt(mode);
				else
#endif
					algorithm_local_baseline_calculate_delta(mode);
#ifdef FirstTiltWaitReportMS
			if(Tilt_On == 2 && thisInfo->tPenInfo.bReportSkip == 0 && ReportSkip_FirstTiltWait_MS == 1 /*&& g_RetVal == PARTIAL_PEN_COORD3*/ && mode == LOCAL_TILT_MODE && thisInfo->tPenInfo.bPenContact == YES)
			{
				if((thisModeConf->PenTilt.ucMS_RingMode == 0 && g_RetVal == PARTIAL_PEN_COORD3) || (thisModeConf->PenTilt.ucMS_RingMode == 1 && g_RetVal == PARTIAL_PEN_COORD1) || (thisModeConf->PenTilt.ucMS_RingMode == 2 && (g_RetVal == PARTIAL_PEN_COORD1||g_RetVal == PARTIAL_PEN_COORD3)))
				{
					ReportSkip_FirstTiltWait_MS = 0;
	#if (UseLastContact3x3 == YES)
					if(thisModeConf->PenTilt.usUseLastContact3x3Th == 0)thisInfo->tTiltInfo.sTilt_cnt = 2;
					if(abs(pTRingInfo.sLastContact3x3Val - pTRingInfo.s3x3Val) > thisModeConf->PenTilt.usUseLastContact3x3Th && thisModeConf->PenTilt.usUseLastContact3x3Th > 0)thisInfo->tTiltInfo.sTilt_cnt = 2;
					else thisInfo->tPenInfo.bUseUseLastContact3x3 = 1;
	#else
					thisInfo->tTiltInfo.sTilt_cnt = 2;
	#endif
				}
			}
			if(Tilt_On==2 && ReportSkip_FirstTiltWait_MS == 1 && thisInfo->tPenInfo.bPenContact == YES){
				thisInfo->tPenInfo.bReportSkip = 1;
	#if (UseLastContact3x3 == YES)
				if(thisModeConf->PenTilt.usUseLastContact3x3Th == 0)thisInfo->tTiltInfo.sTilt_cnt = 2;
	#endif
			}
#endif

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)				
	#ifdef TILT_ON
			if(Tilt_On==1 && mode == LOCAL_MODE && g_RetVal==PARTIAL_PEN_COORD2)
				mode = LOCAL_RING_MODE;
	#endif
#endif
			uint8_t	PenFingerLineNoiseSize = thisModeConf->Noise.ucPenFingerSameLineNoiseSize;;
#if AbnormalContactRemove_EN
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
			if(thisInfo->tPenInfo.bAdaptorNoise==1)PenFingerLineNoiseSize = 0;
	#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
			if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS && thisInfo->tPenInfo.bAdaptorNoise==1)PenFingerLineNoiseSize = 0;
	#endif
#endif
			bool_t bTmpPenNoiseReductionOff = thisModeConf->Noise.bPenNoiseReductionOff;			
			if(mode == LOCAL_SEARCH_MODE)
			{
				bTmpPenNoiseReductionOff = 1;
				thisInfo->tPenInfo.ucDSP_B_Index=PEN_UPDATE_POST_INFO;
			}
			else if(mode == LOCAL_TILT_MODE || mode == LOCAL_HOVER_MODE)bTmpPenNoiseReductionOff = 1;
			
			TMH_PenNoiseReduction(HAL_GET_LOCAL_DELTA_IMAGE_PTR(), &thisInfo->tDelta_local, &thisInfo->tPenInfo, mode, thisInfo->tDelta_local.tValidRect.rs,
				thisInfo->tDelta_local.tValidRect.re, thisInfo->tDelta_local.tValidRect.cs, thisInfo->tDelta_local.tValidRect.ce, -1, PenFingerLineNoiseSize,bTmpPenNoiseReductionOff);
		}
		break;

		case PEN_LABELING:
		{				
			memset((void *)&thisInfo->tLabel_local_dsp,0,sizeof(tPenLabelInfo_t));	
			memset(LOCALLABELIMAGE,0,sizeof(LOCALLABELIMAGE));
			
			uint16_t usLabelThd;//  = thisModeConf->Label.usLocalSeedBase;	
	
#ifdef TILT_ON
			if(mode == LOCAL_TILT_MODE 
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)	
			|| (Tilt_On==1 && g_RetVal==PARTIAL_PEN_COORD2 && mode == LOCAL_MODE)
	#endif	
			)
			{
				int A_offset = 0;
				if(thisModeConf->Label.ucRingSeedBase_Acoef > 0)
					A_offset = thisInfo->tDelta_local.iMaxStrength/thisModeConf->Label.ucRingSeedBase_Acoef;
				int F_offset = 0;
				if(thisModeConf->Label.ucRingSeedBase_Fcoef != 0)
					F_offset = thisInfo->tDelta_local.iMaxStrength - thisModeConf->Label.ucRingSeedBase_Fcoef;
				if(F_offset<0)F_offset = 0;
				usLabelThd  = thisModeConf->Label.usLocalSeedBase_Ring+A_offset+F_offset;
				
				ucTmpMarkBoundaryNum = thisModeConf->PenTilt.ucRingMarkBoundaryNum;
			}
			else
#endif		
			{
				usLabelThd  = thisModeConf->Label.usLocalSeedBase;
				ucTmpMarkBoundaryNum = thisModeConf->PenCoord.ucMarkBoundaryNum;	
			
	#if 0//(CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
				if(!(thisInfo->tDelta_local.tMaxCellPos.r+currentRowStart < 5 || thisInfo->tDelta_local.tMaxCellPos.r+currentRowStart > ROW_MAX-6 || thisInfo->tDelta_local.tMaxCellPos.c < 5 || thisInfo->tDelta_local.tMaxCellPos.c > COL_MAX-6))
				{
					usLabelThd -= 10;
		#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
					if(thisInfo->tDelta_local.tMaxCellPos.c < 5)
						usLabelThd = 50;
		#endif
				}
	#endif			
				usLabelThd += ((thisInfo->tDelta_local.iMaxStrength - usLabelThd) * thisModeConf->Label.ucLocalSeedSlope)>>6;
				
				if(thisInfo->bTouchExpect_local == NO)thisInfo->tPenInfo.ucDSP_B_Index = PEN_COORDINATE - 1;

	#if (Pen_EdgeMarkBoundary == YES)
				if(thisModeConf->PenCoord.ucEdgeMarkBoundaryNum)
				{
					if(algorithm_coord_IsEdgeArea_Cell(thisInfo->tDelta_local.tMaxCellPos.r+currentRowStart,thisInfo->tDelta_local.tMaxCellPos.c,thisModeConf->PenCoord.ucEdgeMarkBoundaryCell-1))
					{
						ucTmpMarkBoundaryNum = thisModeConf->PenCoord.ucEdgeMarkBoundaryNum;
					}
				}
					
				if(thisModeConf->PenCoord.ucEdgeMarkBoundaryOff)
				{	
					if(algorithm_coord_IsEdgeArea_Cell(thisInfo->tDelta_local.tMaxCellPos.r+currentRowStart,thisInfo->tDelta_local.tMaxCellPos.c,thisModeConf->PenCoord.ucEdgeMarkBoundaryOff-1))
					{
						ucTmpMarkBoundaryNum = 0;
					}
				}
	#endif
			}
			
			if(ucTmpMarkBoundaryNum == 0)thisInfo->tPenInfo.ucDSP_B_Index++;
			
			TMH_PenLabeling(thisInfo->tPenInfo.pTmpModeDeltaImg, HAL_GET_LOCAL_LABEL_IMAGE_PTR(), &thisInfo->tLabel_local_dsp, LABEL_INFO_SIZE, thisInfo->tDelta_local.tValidRect.rs
			, thisInfo->tDelta_local.tValidRect.re, thisInfo->tDelta_local.tValidRect.cs, thisInfo->tDelta_local.tValidRect.ce, usLabelThd, PAD_);
			
		}
		break;

		case DSP_MARKBOUNDARY1:
		{	
			if( thisInfo->bTouchExpect_local || mode == LOCAL_TILT_MODE)
			{
				if(MarkB_r == 0)
				{					
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)	
	#ifdef TILT_ON
					if(Tilt_On==1 && g_RetVal==PARTIAL_PEN_COORD2 && mode == LOCAL_MODE)
					{
						thisInfo->tPenInfo.cRing_PreMaxR = thisInfo->tLabel_local_dsp.tValidMaxPos.r+currentRowStart;
						thisInfo->tPenInfo.cRing_PreMaxC = thisInfo->tLabel_local_dsp.tValidMaxPos.c;
					}
					else
	#endif
#endif
					if(mode != LOCAL_TILT_MODE)
					{
						thisInfo->tPenInfo.cPreMaxR = thisInfo->tLabel_local_dsp.tValidMaxPos.r+currentRowStart;
						thisInfo->tPenInfo.cPreMaxC = thisInfo->tLabel_local_dsp.tValidMaxPos.c;
					}
										
					MarkB_r = ucTmpMarkBoundaryNum;
				}
				
				cs = thisInfo->tLabel_local_dsp.tValidRect.cs; ce = thisInfo->tLabel_local_dsp.tValidRect.ce;
				rs = thisInfo->tLabel_local_dsp.tValidRect.rs; re = thisInfo->tLabel_local_dsp.tValidRect.re;
				
				if( cs > 0 )
					cs--;
				if( ce < (COL_MAX - 1) )
					ce++;
				if( rs > 0 )
					rs--;
				if( re < (MAX_MUX_SIZE - 1) )
					re++;

				if(MarkB_r > 1 && thisInfo->tPenInfo.bAdaptorNoise==0)
				{
					MarkB_r--;
					MarkB = 0;
					thisInfo->tPenInfo.ucDSP_B_Index--;
				}
				else 
				{
					MarkB_r = 0;
					MarkB = 1;
				}	
#if (DeltaBaseNewEdgeCompen_SW == NO)						
				if(MarkB_r == 0 && mode == LOCAL_TILT_MODE)thisInfo->tPenInfo.ucDSP_B_Index++;
#endif				
				TMH_MarkBoundary(HAL_GET_LOCAL_LABEL_IMAGE_PTR(), thisInfo->tPenInfo.pTmpModeDeltaImg, rs, re, cs, ce, 0, &thisInfo->tLabel_local_dsp, MarkB, PAD_);
			}
		}
		break;

#if (DeltaBaseNewEdgeCompen_SW == NO)			
		case PEN_COORDINATE_EDGE_PROCESSING:
		{			
			cs = thisInfo->tLabel_local_dsp.tValidRect.cs; ce = thisInfo->tLabel_local_dsp.tValidRect.ce;
			rs = thisInfo->tLabel_local_dsp.tValidRect.rs; re = thisInfo->tLabel_local_dsp.tValidRect.re;
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)	
			if(Tilt_On==1 && g_RetVal==PARTIAL_PEN_COORD2 && mode == LOCAL_MODE)
				mode = LOCAL_RING_MODE;
	#endif			
			Pre_TMH_PenLabelEdgeExpand_DeltaBase(&thisInfo->tLabel_local_dsp, mode, Tilt_On);
			
            TMH_PenLabelEdgeExpand_DeltaBase(HAL_GET_LOCAL_DELTA_IMAGE_PTR(), HAL_GET_LOCAL_LABEL_IMAGE_PTR(), &thisInfo->tLabel_local_dsp, &thisInfo->PenEdgeExpandSetVal, rs, re, cs, ce, mode);
		}
		break;
#endif
		
		case PEN_COORDINATE:
		{
			memcpy(&thisInfo->tEdgePenSetVal,&thisModeConf->EdgePenSetVal,sizeof(tAlgorithmEdgePenConf_t));	
			
			if(mode != LOCAL_TILT_MODE)
			{
#if (DeltaBaseNewEdgeCompen_SW == YES)	
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)	
				if(Tilt_On==1 && g_RetVal==PARTIAL_PEN_COORD2 && mode == LOCAL_MODE)mode = LOCAL_RING_MODE;
	#endif			
	#if (PEN_Edge_UsePerMaxSum == YES)			
				if(mode == LOCAL_MODE)
				{
					if(0==algorithm_coord_IsEdgeArea_Cell(thisInfo->tLabel_local_dsp.tValidMaxPos.r+currentRowStart,thisInfo->tLabel_local_dsp.tValidMaxPos.c,1))
					{
						for(rs=9;rs>0;rs--)ulExtStrengthArray[rs] = ulExtStrengthArray[rs-1];
						ulExtStrengthArray[0] = thisInfo->tLabel_local_dsp.ulExtStrength;
						if(thisInfo->tCoord_local_dsp.PenContactCnt > 10)
						{
							ulExtStrengthAvg = 0;
							for(rs=0;rs<10;rs++)ulExtStrengthAvg += ulExtStrengthArray[rs];
							ulExtStrengthAvg/=10;
						}
					}
				}
	#endif
				algorithm_label_EdgeExpand_DeltaBase(mode,g_RetVal,Tilt_On);
#else
				// Pre step must be TMH_PenLabelEdgeExpand_DeltaBase
				thisInfo->tTiltInfo.sRing_ExtStrength  	 =	(int)DSP_CON->TDSP_REGA5;		   
				thisInfo->tTiltInfo.sRingTipStrengthRatio =  (int)DSP_CON->TDSP_REGB0;
				thisInfo->tLabel_local_dsp.tCoord.x = (int)DSP_CON->TDSP_REGC5;
				thisInfo->tLabel_local_dsp.tCoord.y = (int)DSP_CON->TDSP_REGC6;
				thisInfo->tLabel_local_dsp.ulExtStrength = (int)DSP_CON->TDSP_REGC7;		
				////////
#endif	
			}			
			
			DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE2);
			DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE2, COORD_INFO_SIZE);
			DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE2);
			DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE2, LOOSE_POSBUF_);

			if(mode == LOCAL_TILT_MODE
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)	
			|| (Tilt_On==1 && g_RetVal==PARTIAL_PEN_COORD2 && mode == LOCAL_MODE)
#endif
			)
			{
				mode=LOCAL_RING_MODE;
				if(thisModeConf->PenTilt.bRingRangeExtend_On == 1)algorithm_RangeExtend(mode);
#if (RangeExtend_v2_En == YES)
				else if(thisModeConf->PenTilt.bRingRangeExtend_On == 2)algorithm_RangeExtend_v2(mode);
#endif
				thisInfo->tTiltInfo.sRing_ExtStrength = thisInfo->tLabel_local_dsp.ulExtStrength;
			}
			else
			{
				if(thisModeConf->PenCoord.ucTipRangeExtend_On)
					algorithm_RangeExtend(mode);
			}
			
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			if(gAlgoRawDataType == ACTIVEPEN_TYPE_LOCAL_MS)
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			{
				if(thisInfo->tPenInfo.bPen_button[0])
				{
					mode = LOCAL_HOVER_MODE;
					thisInfo->tEdgePenSetVal.top_hover_mul += thisInfo->tEdgePenSetVal.chover_mul_button1_offset;
					thisInfo->tEdgePenSetVal.bottom_hover_mul += thisInfo->tEdgePenSetVal.chover_mul_button1_offset;
					thisInfo->tEdgePenSetVal.left_hover_mul += thisInfo->tEdgePenSetVal.chover_mul_button1_offset;
					thisInfo->tEdgePenSetVal.right_hover_mul += thisInfo->tEdgePenSetVal.chover_mul_button1_offset;
				}
			}
#endif
#if (Ring_EdgeEx_mul_HoverOffset == YES)
			if(mode==LOCAL_RING_MODE)
			{
				if(thisInfo->tPenInfo.bPenContact == NO && thisInfo->tPenInfo.bPrevPenContact == NO)
				{
					thisInfo->tEdgePenSetVal.left_ring_mul += thisInfo->tEdgePenSetVal.left_ring_mul_HoverOffset;
					thisInfo->tEdgePenSetVal.right_ring_mul += thisInfo->tEdgePenSetVal.right_ring_mul_HoverOffset;
					thisInfo->tEdgePenSetVal.top_ring_mul += thisInfo->tEdgePenSetVal.top_ring_mul_HoverOffset;						
					thisInfo->tEdgePenSetVal.bottom_ring_mul +=	thisInfo->tEdgePenSetVal.bottom_ring_mul_HoverOffset;											
				}
			}
#endif
			TMH_PenCoordinate(&thisInfo->tCoord_local_dsp, &thisInfo->tLabel_local_dsp, &thisInfo->tEdgePenSetVal, &thisInfo->tTiltInfo, mode);
		}
		break;

#if 1//(USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
	#ifdef TILT_OPCODE
		case PEN_CALCULATION_TILT_H:
		{	
			uint8_t L = thisModeConf->PenTilt.ucTiltL; 

			thisInfo->tCoord_local_dsp.cIsbefor = (int8_t)DSP_CON->TDSP_REGB6;
			thisInfo->bLocal_sensing = (uint8_t)DSP_CON->TDSP_REGB5;
			
			if(mode == LOCAL_TILT_MODE
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
			|| (Tilt_On==1 && g_RetVal==PARTIAL_PEN_COORD2 && mode==LOCAL_MODE)
		#endif
			)
			{	
				mode=LOCAL_RING_MODE;
				algorithm_coord_compensation(mode);		
				
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
				if(thisModeConf->PenTilt.ucRingDirecPosCoef > 0)
				{
					if(pTRingInfo.MaxDirecNum == 4 || pTRingInfo.MaxDirecNum == 6 || pTRingInfo.MaxDirecNum == 2 || pTRingInfo.MaxDirecNum == 8)
					{
						thisInfo->tCoord_local_dsp.tOrgPos.tXY.x += (pTRingInfo.tCoord.x * thisModeConf->PenTilt.ucRingDirecPosCoef)/100;
						thisInfo->tCoord_local_dsp.tOrgPos.tXY.y += (pTRingInfo.tCoord.y * thisModeConf->PenTilt.ucRingDirecPosCoef)/100; 
					}				
					else
					{
						thisInfo->tCoord_local_dsp.tOrgPos.tXY.x += (pTRingInfo.tCoord.x * (thisModeConf->PenTilt.ucRingDirecPosCoef-1))/100;
						thisInfo->tCoord_local_dsp.tOrgPos.tXY.y += (pTRingInfo.tCoord.y * (thisModeConf->PenTilt.ucRingDirecPosCoef-1))/100; 
					}
				}
		#endif
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
				if(ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType)
		#endif
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
				{
			#if (TiltBasedRingDelta == YES)
					if(thisModeConf->PenTilt.bTiltBasedRingDelta)
					{
						if(pTRingInfo.MaxDirecNum == 4 || pTRingInfo.MaxDirecNum == 6 || pTRingInfo.MaxDirecNum == 5)
							thisInfo->tCoord_local_dsp.tOrgPos.tXY.x = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x + pTRingInfo.tCoord.x * 1/2;
						
						if(pTRingInfo.MaxDirecNum == 2 || pTRingInfo.MaxDirecNum == 8 || pTRingInfo.MaxDirecNum == 5)
							thisInfo->tCoord_local_dsp.tOrgPos.tXY.y = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y + pTRingInfo.tCoord.y * 1/2; 
					}
			#endif
				}
		#endif			
		
		#if (RingCoordSmooth_En == YES)		
				if(thisModeConf->PenTilt.ucRingCoordSmoothCoef)
					algorithm_Tilt_RingCoordSmoothing();
		#endif
				
				thisInfo->tCoord_local_dsp.tAvgPos.y = 1;
				if(thisModeConf->PenTilt.bRingCoordiReport)
				{
					//thisInfo->tCoord_local_dsp.tPos.tXY = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
					algorithm_PendPenEventforDSP(mode);	
				}
				
				if(thisModeConf->PenTilt.bTiltCalUsingTipOrg)
				{
					TiltTmpPos = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY;
					thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY = thisInfo->tTiltInfo.TipOrgPos;
				}
			}
			else 
			{
				thisInfo->tCoord_local_dsp.tAvgPos.y = 0;
				thisInfo->tPenInfo.ucDSP_B_Index = PEN_TILT_PEN2_ORG_COORD_PREDIC;
			}
			
#if (TiltArcSinLookUp_Num > 3)
			if(thisModeConf->PenTilt.bArcSinLookUp_1==1)TMH_PenTilt_Step1((uint8_t *)ArcSinLookUpTable_1,(uint8_t *)CosLookUpTable,&thisInfo->tCoord_local_dsp,&thisInfo->tTiltInfo,L);
			else if(thisModeConf->PenTilt.bArcSinLookUp_1==2)TMH_PenTilt_Step1((uint8_t *)ArcSinLookUpTable_2,(uint8_t *)CosLookUpTable,&thisInfo->tCoord_local_dsp,&thisInfo->tTiltInfo,L);
			else if(thisModeConf->PenTilt.bArcSinLookUp_1==3)TMH_PenTilt_Step1((uint8_t *)ArcSinLookUpTable_3,(uint8_t *)CosLookUpTable_2,&thisInfo->tCoord_local_dsp,&thisInfo->tTiltInfo,L);
			else TMH_PenTilt_Step1((uint8_t *)ArcSinLookUpTable,(uint8_t *)CosLookUpTable,&thisInfo->tCoord_local_dsp,&thisInfo->tTiltInfo,L);
#elif (TiltArcSinLookUp_Num == 3)
			TMH_PenTilt_Step1((uint8_t *)ArcSinLookUpTable_3,(uint8_t *)CosLookUpTable_2,&thisInfo->tCoord_local_dsp,&thisInfo->tTiltInfo,L);
#elif (TiltArcSinLookUp_Num == 2)
			TMH_PenTilt_Step1((uint8_t *)ArcSinLookUpTable_2,(uint8_t *)CosLookUpTable,&thisInfo->tCoord_local_dsp,&thisInfo->tTiltInfo,L);
#else
			TMH_PenTilt_Step1((uint8_t *)ArcSinLookUpTable_1,(uint8_t *)CosLookUpTable,&thisInfo->tCoord_local_dsp,&thisInfo->tTiltInfo,L);
#endif
			
		}		
		break;
		
		case PEN_CALCULATION_TILT_X:
		{	
			TMH_PenTilt_Step2((uint16_t *)sucArcTanLookUpTable,&thisInfo->tTiltInfo,-(thisInfo->tTiltInfo.TILT_sx),thisInfo->tTiltInfo.TILT_H,5);
		}		
		break;
		
		case PEN_CALCULATION_TILT_Y:
		{	
			TMH_PenTilt_Step2((uint16_t *)sucArcTanLookUpTable,&thisInfo->tTiltInfo,-(thisInfo->tTiltInfo.TILT_sy),thisInfo->tTiltInfo.TILT_H,6);
		}		
		break;
		
		case PEN_CALCULATION_TILT_PHI:
		{	
			TMH_PenTilt_Step2((uint16_t *)sucArcTanLookUpTable,&thisInfo->tTiltInfo,thisInfo->tTiltInfo.TILT_sx,thisInfo->tTiltInfo.TILT_sy,8);
		}		
		break;
		
		case PEN_TILT_FILTER:
		{	
			int ucTiltSmoothingFilterCoef = thisModeConf->PenTilt.ucTiltSmoothingFilterCoef;
			algorithm_Tilt_PreFilter();
			
		#ifdef TiltAccuracyTest
			if(thisInfo->tTiltInfo.sTilt_cnt < 100)
				ucTiltSmoothingFilterCoef = thisModeConf->PenTilt.ucTiltSmoothingFilterCoef - change_offset2;
		#endif

		#if (HighDeltaTiltSmoothCoefChange == YES)
			if(thisInfo->tTiltInfo.SmoothingCoefChange)
			{
				thisInfo->tTiltInfo.SmoothingCoefChange = 0;
				ucTiltSmoothingFilterCoef = thisModeConf->PenTilt.ucTiltSmoothingFilterCoef + thisModeConf->PenTilt.cHighDelta_TiltSmooth_change_offset;
			}
		#endif
			
			if(thisInfo->tCoord_local_dsp.tAvgPos.y == 1)
			{
				if(thisInfo->tTiltInfo.sTilt_cnt++ > 32765)thisInfo->tTiltInfo.sTilt_cnt = 100;
			}
			
			TMH_PenTilt_Step3(&thisInfo->tTiltInfo,&thisInfo->tLabel_local_dsp,&thisInfo->tCoord_local_dsp, ucTiltSmoothingFilterCoef);
		}		
		break;
		
		case PEN_TILT_PEN2_ORG_COORD_PREDIC:
		{	

			if(thisInfo->tCoord_local_dsp.tAvgPos.y == 1)
			{
		#if (USED_PEN_PROTOCOL != PEN_PROTOCOL_WACOM_PEN)
			#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
				if(ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType)
			#endif
				{
					thisInfo->tCoord_local_dsp.tAvgPos.y = 0;
					if(mode == LOCAL_TILT_MODE)thisInfo->tPenInfo.ucDSP_B_Index = PEN_UPDATE_POST_INFO;		
				}
		#endif
				
		#ifdef TiltAccuracyTest
				algorithm_Tilt_PostFilter();
		#endif
				
		#if (HighDeltaTiltSmoothCoefChange == YES)
				if(thisModeConf->PenTilt.ucHighDelta_TiltSmooth_change_Th)algorithm_Tilt_RangeTestCheck();
		#endif
				
				if(thisModeConf->PenTilt.bTiltCalUsingTipOrg)thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY = TiltTmpPos;
			}

			TMH_PenTilt_Step0(&thisInfo->tCoord_local_dsp);
		}		
		break;
	#endif
#endif
		
		case PEN_SMOOTHING:
		{					
#ifdef SW_RATE_UP_EN
			if(thisInfo->tPenInfo.bRateUpFlag)
			{
				DSP_SIZE_CLEAR(REG_TDSP2_XSIZE, DMA_SIZE2);
				DSP_SIZE_SET(REG_TDSP2_XSIZE, DMA_SIZE2, COORD_INFO_SIZE);
				DSP_SIZE_CLEAR(REG_TDSP2_YSIZE, DMA_SIZE2);
				DSP_SIZE_SET(REG_TDSP2_YSIZE, DMA_SIZE2, LOOSE_POSBUF_);
			}				
#endif
			
#if (OUT_IN_DRAWING==YES)
			if(thisModeConf->PenCoord.usOutInBoundTh > 0)	
				algorithm_out_in_drawing(mode,sPMode);
#endif
			
			if(thisInfo->tPenInfo.bPenContact == NO && thisInfo->tCoord_local_dsp.cIsbefor == 1)
			{
				thisInfo->tCoord_local_dsp.cIsbefor = 0;
				thisInfo->bLocal_sensing = NO;
			}

#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
			if(thisModeConf->PenTilt.ucTipDirecShiftBasedRingDelta > 0)
			{
				if(pTRingInfo.MaxDirecNum == 4 || pTRingInfo.MaxDirecNum == 6 || pTRingInfo.MaxDirecNum == 2 || pTRingInfo.MaxDirecNum == 8)
				{
					thisInfo->tCoord_local_dsp.tOrgPos.tXY.x -= (pTRingInfo.tCoord.x * thisModeConf->PenTilt.ucTipDirecShiftBasedRingDelta)/100;
					thisInfo->tCoord_local_dsp.tOrgPos.tXY.y -= (pTRingInfo.tCoord.y * thisModeConf->PenTilt.ucTipDirecShiftBasedRingDelta)/100; 
				}				
				else
				{
					thisInfo->tCoord_local_dsp.tOrgPos.tXY.x -= (pTRingInfo.tCoord.x * (thisModeConf->PenTilt.ucTipDirecShiftBasedRingDelta-1))/100;
					thisInfo->tCoord_local_dsp.tOrgPos.tXY.y -= (pTRingInfo.tCoord.y * (thisModeConf->PenTilt.ucTipDirecShiftBasedRingDelta-1))/100; 
				}
				thisInfo->tCoord_local_dsp.tPos.tXY.x = thisInfo->tCoord_local_dsp.tOrgPos.tXY.x;
				thisInfo->tCoord_local_dsp.tPos.tXY.y = thisInfo->tCoord_local_dsp.tOrgPos.tXY.y;
			}
#endif
			
#ifdef TILT_ON
			if(thisModeConf->PenTilt.bTiltCalUsingTipOrg)thisInfo->tTiltInfo.TipOrgPos = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
			if(thisModeConf->PenTilt.ucCoordiShiftX_WithTilt > 0 || thisModeConf->PenTilt.ucCoordiShiftY_WithTilt > 0)
				algorithm_coordi_compen_with_tilt(Tilt_On, mode);
#endif
			
#ifdef SW_RATE_UP_EN
			if(thisInfo->tPenInfo.bRateUpFlag == 0)
#endif
			{
				algorithm_coord_compensation(mode);		
			}				
			
			TMH_PenSmoothing(&thisInfo->tCoord_local_dsp, mode);
		}
		break;

		case PEN_DIS_BASE_SMOOTHING_ADD:
		{
			memcpy(&thisInfo->PenDisBaseSmoothSetVal,&thisModeConf->PenDisBaseSmoothSetVal,sizeof(tAlgorithmDisBaseSmoothConf_t));	
#if (CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP && CUSTOMER != MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)			
			if(thisModeConf->PenCoord.uclatency_up_dis_condition > 0 && thisModeConf->PenCoord.uclatency_up_cnt_condition > 0)
			{
				if((mode == LOCAL_MODE || mode == LOCAL_HOVER_MODE) && thisInfo->tCoord_local_dsp.tPos.vusS>0 && thisInfo->tCoord_local_dsp.tPastPos[0].vusS>0)
				{		
					algorithm_FastDrawLatencyUp();
				}
			}
#endif			
			TMH_PenDisBasedSmoothAdd(&thisInfo->tCoord_local_dsp, &thisInfo->PenDisBaseSmoothSetVal, mode, thisInfo->PenDisBaseSmoothSetVal.usEdge_Range);
		}
		break;
		
		case PEN_POST_PROCESS:
		{							
#if (CornerSmoothContact == YES)
			if(mode == LOCAL_MODE && thisModeConf->PenDisBaseSmoothSetVal.ucCornerSmoothContact_DisCondition > 0)
				algorithm_coord_PenCornerSmoothContact();
#endif
			
			thisInfo->tCoord_local_dsp.tAvgPos.x = 0;
			thisInfo->tCoord_local_dsp.tAvgPos.y = 0;
			if(thisInfo->tCoord_local_dsp.tPos.vusS == 0 || (thisInfo->tPenInfo.bPenContact==NO && thisInfo->tPenInfo.bPrevPenContact==YES))
			{
				if(thisModeConf->PenCoord.ucPenPostProcessEdgeTH > 0)
					thisInfo->tCoord_local_dsp.tAvgPos.y = 1;
			}
			TMH_PenCoord_PostProcess(&thisInfo->tCoord_local_dsp,thisModeConf->PenCoord.ucPenPostProcessEdgeTH,thisModeConf->PenCoord.ucPenPostProcessDisTH,thisModeConf->PenCoord.ucPenPostProcessExpendDiv);
		}		
		break;
		
		case PEN_UPDATE_POST_INFO:
		{
			if(hal_get_overlap_pen() == 0)
			{
				if((mode == LOCAL_MODE && thisInfo->tCoord_local_dsp.tAvgPos.x>0)){
//					thisInfo->tCoord_local.cIsbefor[0] = 0;
					thisInfo->bLocal_sensing = YES;
					thisInfo->tPenInfo.bPenContact = YES;
					
					if(us_pendata_pressure > 1)
						thisInfo->tPenInfo.us_pendata_pressure = us_pendata_pressure;
					else thisInfo->tPenInfo.us_pendata_pressure = 500;
					
					thisInfo->tPenInfo.bPenPostProcessFlag = 1;
				}
				
				if(thisInfo->tPenInfo.bPenPostProcessFlag == 0)
					algorithm_PannelOutSideReportException(mode,sPMode);
			
#ifdef LongDisPointException
				if(thisInfo->tCoord_local_dsp.tPos.vusS>0 && thisInfo->tCoord_local_dsp.tPastPos[0].vusS>0 && thisModeConf->PenCoord.usLongDisPointExceptionTH)
				{
					int prev_curr_dist = algorithm_coord_calc_distance(thisInfo->tCoord_local_dsp.tPos.tXY, thisInfo->tCoord_local_dsp.tPastPos[0].tXY);
	
	#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP || CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
					if(prev_curr_dist > 300 && algorithm_coord_IsEdgeArea(&thisInfo->tCoord_local_dsp.tPastPos[0].tXY , 255) && mode == LOCAL_HOVER_MODE)
	#else
					if(prev_curr_dist>thisModeConf->PenCoord.usLongDisPointExceptionTH)
	#endif
					{
						if(thisInfo->tCoord_local_dsp.tPastPos[1].vusS>0)
						{
							thisInfo->tCoord_local_dsp.tPos.tXY.x = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x;// + (thisInfo->tCoord_local_dsp.tPastPos[0].tXY.x - thisInfo->tCoord_local_dsp.tPastPos[1].tXY.x);
							thisInfo->tCoord_local_dsp.tPos.tXY.y = thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y;// + (thisInfo->tCoord_local_dsp.tPastPos[0].tXY.y - thisInfo->tCoord_local_dsp.tPastPos[1].tXY.y);
							thisInfo->tCoord_local_dsp.tOrgPos.tXY.x = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x;// + (thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.x - thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.x);
							thisInfo->tCoord_local_dsp.tOrgPos.tXY.y = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y;// + (thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY.y - thisInfo->tCoord_local_dsp.tOrgPastPos[1].tXY.y);
						}
						else 
						{
							thisInfo->tCoord_local_dsp.tPos.tXY = thisInfo->tCoord_local_dsp.tPastPos[0].tXY;
							thisInfo->tCoord_local_dsp.tOrgPos.tXY = thisInfo->tCoord_local_dsp.tOrgPastPos[0].tXY;
						}
						tCell_t pen_pos;
						pen_pos.r = (thisInfo->tCoord_local_dsp.tOrgPos.tXY.y+128)/256;
						pen_pos.c = (thisInfo->tCoord_local_dsp.tOrgPos.tXY.x+128)/256;
						algorithm_baseline_calculate_local_mux_range(pen_pos.r, pen_pos.c,0);
					}
				}
#endif
				
				if(thisInfo->tCoord_local_dsp.cIsbefor>0)
				{
					tCell_t pen_pos;
					pen_pos.r = (thisInfo->tCoord_local_dsp.tOrgPos.tXY.y+128)/256;
					pen_pos.c = (thisInfo->tCoord_local_dsp.tOrgPos.tXY.x+128)/256;
					algorithm_baseline_calculate_local_mux_range(pen_pos.r, pen_pos.c,0);
					thisInfo->tPenInfo.bPosUpdateSkip = 1;
				}

#ifdef SW_RATE_UP_EN
				if(thisInfo->tCoord_local_dsp.tOrgPos.vusS && thisInfo->tCoord_local_dsp.tOrgPastPos[0].vusS && thisInfo->tCoord_local_dsp.tOrgPastPos[1].vusS && thisInfo->tCoord_local_dsp.tOrgPastPos2.vusS && thisInfo->tPenInfo.bRateUpFlag == 0 && thisInfo->tCoord_local_dsp.tAvgPos.y == 0 &&
					(g_RetVal==PARTIAL_PEN_COORD4 
	#if (SW_RATE_UP_EN>1)
					|| g_RetVal==PARTIAL_PEN_COORD1 
	#endif
	#if (SW_RATE_UP_EN>2)
					|| g_RetVal==PARTIAL_PEN_COORD3
	#endif
					)
				)
				{	
	#ifdef TILT_OPCODE
					thisInfo->tPenInfo.ucDSP_B_Index = PEN_TILT_PEN2_ORG_COORD_PREDIC;
	#else
					thisInfo->tPenInfo.ucDSP_B_Index = PEN_COORDINATE;
	#endif					
					thisInfo->tPenInfo.bRateUpFlag = 1;
				}
				else 
#endif
				{
					thisInfo->tPenInfo.ucDSP_B_Index++;		// check app_normal
#ifdef SW_RATE_UP_EN
					thisInfo->tPenInfo.bRateUpFlag = 0;
#endif
				}

				if(thisModeConf->PenCoord.ucideal_inter_dis > 0)
					algorithm_IdealLineInterpolation();
				
#if (HIGH_HOVER_JITTER_REDUCE == YES)
				if(thisModeConf->PenCoord.sHighHoverJitterReduceDisScale != 0 && mode == LOCAL_HOVER_MODE)
					algorithm_HighHoverJitterReduce();
#endif
				
#if (OUT_IN_DRAWING==NO)                
                if(thisInfo->tCoord_local_dsp.PenContactCnt < thisModeConf->PenCoord.ucPenEdgeDebCnt && algorithm_coord_IsEdgeArea(&thisInfo->tCoord_local_dsp.tPos.tXY, 0) && thisInfo->tPenInfo.bPenContact == YES)
                    thisInfo->tPenInfo.bReportSkip = 1;
#endif
	
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)				
				if(mode == LOCAL_HOVER_MODE && thisInfo->tPenInfo.bReportEraser == 0 && ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType)
				{
					thisInfo->tPenInfo.bReportSkip = 1;
				}
#endif				
				if(thisInfo->tPenInfo.bReportSkip==0)
				{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
					if(ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType)
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
					{
						if(thisInfo->tPenInfo.bPrevPenContact == NO && thisInfo->tPenInfo.bPenContact == YES)
						{
							change=1; thisInfo->tPenInfo.bPenContact = NO;
	#if (ADAPTOR_NOISE_ALGO_EN)
							memset(LOCALNOISEBUF2,0,sizeof(LOCALNOISEBUF2));
	#endif
						}
					}
#endif															
					if(!thisModeConf->PenTilt.bRingCoordiReport)
					{
#if (PEN_Latency_Test_ByFW == YES)
						algorithm_coord_latency_cal_test_pen();
#endif
						if(thisModeConf->PenCoord.bOrgCoordiReport)
							thisInfo->tCoord_local_dsp.tPos.tXY = thisInfo->tCoord_local_dsp.tOrgPos.tXY;
						
						if(thisModeConf->PenCoord.bHoverContactReport && mode==LOCAL_HOVER_MODE)
							thisInfo->tPenInfo.bPenContact = YES;

#if (PEN_FINGER_1TOUCH_REPORT == NO)
						algorithm_PendPenEventforDSP(mode);
#else
						thisInfo->tCoord.tPos.sFinger_ = 1;
						thisInfo->tCoord.tPos.tXY[0] = thisInfo->tCoord_local_dsp.tPos.tXY;
						thisInfo->tCoord.tPos.vusS[0] = thisInfo->tCoord_local_dsp.tPos.vusS;
						thisInfo->tCoord.tPos.vusR[0] = thisInfo->tCoord_local_dsp.tPos.vusR;
						algorithm_PendTouchEvent();				
#endif
						
						if(thisModeConf->PenCoord.bHoverContactReport && mode==LOCAL_HOVER_MODE)
								thisInfo->tPenInfo.bPenContact = NO;
					}
					
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)				
					if(ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType)
#endif
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
					{
						if(change==1)
						{
							change = 0;thisInfo->tPenInfo.bPenContact = YES;
						}
					}
#endif
					if(thisInfo->tPenInfo.bIdeal_inter_tmp_change)
						thisInfo->tCoord_local_dsp.tPos.tXY = thisInfo->tPenInfo.ideal_inter_tmp_pos;
				}
				else 
					thisInfo->tPenInfo.bReportSkip = 0;
				
				if(thisInfo->tPenInfo.bPosUpdateSkip==0){
					TMH_PenUpdatePostHistoryInfo(&thisInfo->tCoord_local_dsp);
				}
				else thisInfo->tPenInfo.bPosUpdateSkip=0;
				
				if(algorithm_mode_change_check())
				{
//					hal_set_SubState_flag(TOUCH_NORMAL_OPER_NORMAL_READY);
					hal_set_irq_flag(IRQ_ID_LOCAL_SAMPLE);
				}
				sPMode = mode;
				
				if(/*ACTIVEPEN_TYPE_LOCAL_WACOM == gAlgoRawDataType|| */ACTIVEPEN_TYPE_LOCAL_WGP == gAlgoRawDataType)
					thisInfo->tPenInfo.bPenContact = temp_PenContact;
				
				if(thisInfo->tPenInfo.bPrevPenContact == YES && thisInfo->tPenInfo.bPenContact == NO)
				{
					thisInfo->tPenInfo.us_pendata_pressure = 1;
					memset((void *)&g_sPenData_Max[0][0], 0, sizeof(g_sPenData_Max));
//					memset(g_sPenData_2nd_Max, 0, sizeof(g_sPenData_2nd_Max));
//					memset(g_sPenData_1st_Max, 0, sizeof(g_sPenData_1st_Max));
				}

				thisInfo->tPenInfo.bPrevPenContact = thisInfo->tPenInfo.bPenContact;

				us_pendata_pressure = thisInfo->tPenInfo.us_pendata_pressure;
				
				if(thisInfo->tPenInfo.bPenContact == YES)
					if(thisInfo->tCoord_local_dsp.PenContactCnt++>65530)
						thisInfo->tCoord_local_dsp.PenContactCnt=100;
			}
			else
			{
				thisInfo->tPenInfo.ucDSP_B_Index--;		// wait finger pend
				TMH_PenSleep(90);//90);	// max 254
			}
		}
		break;

		default:
		break;
	}
}

void algorithm_local_dsp_process(int index, ePartialSensing_t RetVal, int mode)
{
	if(mode != LOCAL_TILT_MODE || ((((thisInfo->tPenInfo.bPenContact || thisInfo->tPenInfo.bPrevPenContact) && thisModeConf->PenTilt.bTiltCalOnlyContact) || !thisModeConf->PenTilt.bTiltCalOnlyContact) && mode == LOCAL_TILT_MODE))
	{
		if(index == 1)
		{
			g_RetVal = RetVal;
			thisInfo->tPenInfo.ucDspB_Lmode = mode;
			thisInfo->tPenInfo.ucDSP_B_Index = index;
			
			if(mode == LOCAL_TILT_MODE)
			{
				thisInfo->tPenInfo.pTmpModeRawImg = HAL_GET_LOCAL_RING_RAW_IMAGE_PTR();
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)			
		#if USED_NOISE_HOPPING_FREQ
				if(ptAppInfo->eCurrentSelectFreq == FREQ_MAIN)
//				if(ptAppInfo->eSelectFreq == FREQ_MAIN)
				{
					thisInfo->tPenInfo.pTmpModeBaseImg = HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR();
				}
				else
				{
					thisInfo->tPenInfo.pTmpModeBaseImg = HAL_GET_LOCAL_BASELINE_IMAGE_PTR();
				}
		#else /* USED_NOISE_HOPPING_FREQ */
				thisInfo->tPenInfo.pTmpModeBaseImg = HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR();
		#endif /* USED_NOISE_HOPPING_FREQ */
	#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)	
				if(ACTIVEPEN_TYPE_LOCAL_MS==gAlgoRawDataType)
				{
					if(RetVal == PARTIAL_PEN_COORD3)thisInfo->tPenInfo.pTmpModeBaseImg = HAL_GET_RING_BASELINE_IMAGE_PTR();
					else thisInfo->tPenInfo.pTmpModeBaseImg = HAL_GET_RING_BASELINE_IMAGE_2_PTR();
				}
				else thisInfo->tPenInfo.pTmpModeBaseImg = HAL_GET_LOCAL_BASELINE_IMAGE_2_PTR();
	#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
				if(RetVal == PARTIAL_PEN_COORD3)
					thisInfo->tPenInfo.pTmpModeBaseImg = HAL_GET_RING_BASELINE_IMAGE_PTR();
	#if (RingBase2Off == NO)
				else
					thisInfo->tPenInfo.pTmpModeBaseImg = HAL_GET_RING_BASELINE_IMAGE_2_PTR();
	#endif
	#else
				thisInfo->tPenInfo.pTmpModeBaseImg = HAL_GET_RING_BASELINE_IMAGE_PTR();
	#endif
				thisInfo->tPenInfo.pTmpModeDeltaImg = HAL_GET_RING_DELTA_IMAGE_PTR(); 
				thisInfo->tPenInfo.usTmpModeRowStart = sensingRowStart_Tilt;
			}
			else
			{
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
				thisInfo->tPenInfo.pTmpModeRawImg = HAL_GET_LOCAL_DATA_RAW_IMAGE_3_PTR();
	#else
				thisInfo->tPenInfo.pTmpModeRawImg = HAL_GET_LOCAL_RAW_IMAGE_PTR();
	#endif

	#if USED_NOISE_HOPPING_FREQ
				if(ptAppInfo->eCurrentSelectFreq == FREQ_MAIN)
//				if(ptAppInfo->eSelectFreq == FREQ_MAIN)
				{
					thisInfo->tPenInfo.pTmpModeBaseImg = g_pLocalBaseImage;
				}
				else
				{
					thisInfo->tPenInfo.pTmpModeBaseImg = g_pLocalHop1BaseImage;
				}
	#else /* USED_NOISE_HOPPING_FREQ */
				thisInfo->tPenInfo.pTmpModeBaseImg = g_pLocalBaseImage;
	#endif /* USED_NOISE_HOPPING_FREQ */
				thisInfo->tPenInfo.pTmpModeDeltaImg = HAL_GET_LOCAL_DELTA_IMAGE_PTR(); 
				thisInfo->tPenInfo.usTmpModeRowStart = currentRowStart;
			}
		}
		
		Call_DSP_B_Func(thisInfo->tPenInfo.ucDSP_B_Index, thisInfo->tPenInfo.ucDspB_Lmode);
	}
}

#else
#endif
#endif	/* (USED_PEN_MODE_OPERATION) */
