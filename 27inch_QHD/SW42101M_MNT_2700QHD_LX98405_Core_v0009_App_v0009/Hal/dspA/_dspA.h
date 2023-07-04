/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _dspA.h
 * version : 0.1
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

#ifndef __DSPA_H_
#define __DSPA_H_


/* ================================================================================ */
/* ================                      DSPA                      ================ */
/* ================================================================================ */

typedef struct
{
	union
	{
		struct
		{
			__IO uint32_t SwStr 	: 1;	// Software Start
			__IO uint32_t Init  	: 1;	// Initialize
			__I uint32_t RESERVED  	: 30;
		} tBit;
		__IO uint32_t ulBulk;
	} HWACC_CTRL;

	union
	{
		struct
		{
			__IO uint32_t ItrptEn   : 1;	// Interrupt Enable
			__IO uint32_t ItrptFlag : 1;	// Interrupt Flag(Read), Interrupt Clear by writing 0(write)
			__I uint32_t RESERVED  	: 30;
		} tBit;
		__IO uint32_t ulBulk;
	} ITRPT_CTRL;

	union
	{
		struct
		{
			__IO uint32_t RowNum  : 8;	// Pannel의 Row개수(Pad 미포함)
			__IO uint32_t ColNum  : 8;	// Pannel의 Column개수(Pad 미포함)
			__IO uint32_t DataLen : 16;	// Total전송 Data개수(Pad 포함)
		} tBit;
		__IO uint32_t ulBulk;
	} SIZE_CTRL;

	__IO uint32_t RAW_ADDR;

	__IO uint32_t BASE_ADDR;

	__IO uint32_t NMLZ_ADDR;

	__IO uint32_t DEST_ADDR;

	union
	{
		struct
		{
			__IO uint32_t PadEn   	: 1;
			__IO uint32_t RESERVED1	: 3;
			__IO uint32_t PadSize	: 4;
			__IO uint32_t RESERVED2	: 8;
			__IO uint32_t PadData	: 16;
		} tBit;
		__IO uint32_t ulBulk;
	} PAD_CTRL;

	union
	{
		struct
		{
			__IO uint32_t NmlzEn    : 1;
			__IO uint32_t RESERVED  : 7;
			__IO uint32_t NmlzShift : 8;
		} tBit;
		__IO uint32_t ulBulk;
	} NMLZ_CTRL;

	union
	{
        struct
		{
			__IO uint32_t BitShift	: 8;
			__IO uint32_t RESERVED	: 24;
		} tBit;
		__IO uint32_t ulBulk;
	} BIT_SHIFT;

	union
	{
		struct
		{
			__IO uint32_t UpperLimit	: 16;
			__IO uint32_t RESERVED		: 16;
		} tBit;
		__IO uint32_t ulBulk;
	} UPR_LIMIT;

	union
	{
		struct
		{
			__IO uint32_t LowerLimit	: 16;
			__IO uint32_t RESERVED		: 16;
		} tBit;
		__IO uint32_t ulBulk;
	} LWR_LIMIT;

	union
	{
		struct
		{
			__IO uint32_t Threshold	: 16;
			__IO uint32_t RESERVED	: 16;
		} tBit;
		__IO uint32_t ulBulk;
	} THRESHOLD;

	union
	{
		struct
		{
			__I uint32_t PlusCellNum	: 16;
			__I uint32_t RESERVED		: 16;
		} tBit;
		__I uint32_t ulBulk;
	} P_CELL_NUM;

	__I uint32_t P_CELL_SUM;

	union
	{
		struct
		{
			__I uint32_t PlusMaxVal	: 16;
			__I uint32_t RESERVED	: 16;
		} tBit;
		__I uint32_t ulBulk;
	} P_MAX_VAL;

	union
	{
		struct
		{
			__I uint32_t PlusMaxRow	: 8;
			__I uint32_t PlusMaxCol	: 8;
		} tBit;
		__I uint32_t ulBulk;
	} P_MAX_POS;

	union
	{
		struct
		{
			__I uint32_t MinusCellNum	: 16;
			__I uint32_t RESERVED		: 16;
		} tBit;
		__I uint32_t ulBulk;
	} M_CELL_NUM;

	__I uint32_t M_CELL_SUM;

	union
	{
		struct
		{
			__I uint32_t MinusMaxVal	: 16;
			__I uint32_t RESERVED	: 16;
		} tBit;
		__I uint32_t ulBulk;
	} M_MAX_VAL;

	union
	{
		struct
		{
			__I uint32_t MinusMaxRow	: 8;
			__I uint32_t MinusMaxCol	: 8;
		} tBit;
		__I uint32_t ulBulk;
	} M_MAX_POS;

	union
	{
		struct
		{
			__I uint32_t TouchMinCol	: 8;
			__I uint32_t TouchMaxCol	: 8;
			__I uint32_t TouchMinRow	: 8;
			__I uint32_t TouchMaxRow	: 8;
		} tBit;
		__I uint32_t ulBulk;
	} T_GROUP;

	union
	{
		struct
		{
			__I uint32_t TouchCellNum	: 16;
			__I uint32_t RESERVED		: 16;
		} tBit;
		__I uint32_t ulBulk;
	} T_CELL_NUM;

	union
	{
		struct
		{
			__IO uint32_t PlusEn	: 1;
			__IO uint32_t MinusEn	: 1;
			__IO uint32_t RESERVED	: 14;
			__IO uint32_t PConstant	: 16;
		} tBit;
		__IO uint32_t ulBulk;
	} PLUS_OPT;

	union
	{
		struct
		{
			__IO uint32_t MultEn	: 1;
			__IO uint32_t RESERVED	: 15;
			__IO uint32_t MConstant	: 16;
		} tBit;
		__IO uint32_t ulBulk;
	} MULT_OPT;

	union
	{
		struct
		{
			__IO uint32_t MasterLock	: 1;
			__IO uint32_t RESERVED		: 30;
		} tBit;
		__IO uint32_t ulBulk;
	} MASTLOCK;

} tDSPA_CtrlReg_t;

#endif /* __DSPA_H_ */
