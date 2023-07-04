/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _dma.h
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

#ifndef __DMA_H_
#define __DMA_H_


typedef struct
{
	__IO uint32_t 	SAR;          /*!< 0x?? : SAR : Channel? Source Address Register		*/
	     uint32_t		xRESERVED0;
	
	__IO uint32_t	  DAR;				  /*!< 0x?? : DAR : Channel? Destination Address Register		*/
	     uint32_t		xRESERVED1;

	__IO uint32_t	  LLP;				  /*!< 0x?? : LLP	: Channel? Linked List Pointer Register		*/
	     uint32_t		xRESERVED2;

	__IO uint64_t	  CTL;				  /*!< 0x?? : CTL	: Channel? Control Register		*/

	__IO uint32_t	  SSTAT;				/*!< 0x?? : SSTAT	: Channel? Source Status Register	*/
	     uint32_t		xRESERVED3;

	__IO uint32_t	  DSTAT;				/*!< 0x?? : DSTAT	: Channel? Destination Status Register	*/
	     uint32_t		xRESERVED4;

	__IO uint32_t	  SSTATAR;			/*!< 0x?? : SSTATAR	: Channel? Source Status Register	*/
	     uint32_t		xRESERVED5;

	__IO uint32_t	  DSTATAR;			/*!< 0x?? : DSTATAR	: Channel? Destination Status Address Register	*/
	     uint32_t		xRESERVED6;

	__IO uint64_t	  CFG;				  /*!< 0x?? : CFG	: Channel? Configuration Register		*/

	__IO uint32_t 	SGR;			  	/*!< 0x?? : SGR	: Channel? Source Gather Register		*/
	     uint32_t		xRESERVED7;

	__IO uint32_t	  DSR;				  /*!< 0x?? : DSR	: Channel? Destination Scatter Register		*/
	     uint32_t		xRESERVED8;
} DMA_Channel_TypeDef, *pDMA_Channel_TypeDef;

typedef struct
{
	__IO uint32_t	  RawTfr;				      /*!< 0x2C0 : RawTfr : Raw Status for IntTfr Interrupt	*/
	     uint32_t		RawTfrRsvd;
	__IO uint32_t	  RawIntBlock;		    /*!< 0x2C8 : RawBlock : Raw Status for IntBlock Interrupt	*/
	     uint32_t		RawBlockRsvd;
	__IO uint32_t	  RawSrcTran;			    /*!< 0x2D0 : RawSrcTran : Raw Status for IntSrcTran Interrupt	*/
	     uint32_t		RawSrcTranRsvd;
	__IO uint32_t	  RawDstTran;			    /*!< 0x2D8 : RawDstTran : Raw Status for IntDstTran Interrupt	*/
	     uint32_t		RawDstTranRsvd;
	__IO uint32_t	  RawErr;				      /*!< 0x2E0 : RawErr : Raw Status for IntErr Interrupt	*/
	     uint32_t		RawErrRsvd;

	__I  uint32_t	  StatusTfr;			    /*!< 0x2E8 : StatusTfr : Status for IntTfr Interrupt	*/
	     uint32_t		StatusTfrRsvd;
	__I  uint32_t	  StatusBlock;		    /*!< 0x2F0 : StatusBlock : Status for IntBlock Interrupt	*/
	     uint32_t		StatusBlockRsvd;
	__I  uint32_t	  StatusSrcTran;		  /*!< 0x2F8 : StatusSrcTran : Status for IntSrcTran Interrupt	*/
	     uint32_t		StatusSrcTranRsvd;
	__I  uint32_t	  StatusDstTran;		  /*!< 0x300 : StatusDstTran : Status for IntDstTran Interrupt	*/
	     uint32_t		StatusDstTranRsvd;
	__I  uint32_t	  StatusErr;			    /*!< 0x308 : StatusErr : Status for IntErr Interrupt	*/
	     uint32_t		StatusErrRsvd;

	__IO uint32_t	  MaskTfr;			      /*!< 0x310 : MaskTfr : Mask for IntTfr Interrupt	*/
	     uint32_t		MaskTfrRsvd;
	__IO uint32_t	  MaskBlock;			    /*!< 0x318 : MaskBlock : Mask for IntBlock Interrupt	*/
	     uint32_t		MaskBlockRsvd;
	__IO uint32_t	  MaskSrcTran;		    /*!< 0x320 : MaskSrcTran : Mask for IntSrcTran Interrupt	*/
	     uint32_t		MaskSrcTranRsvd;
	__IO uint32_t	  MaskDstTran;		    /*!< 0x328 : MaskDstTran : Mask for IntDstTran Interrupt	*/
	     uint32_t		MaskDstTranRsvd;
	__IO uint32_t	  MaskErr;			      /*!< 0x330 : MaskErr : Mask for IntErr Interrupt	*/
	     uint32_t		MaskErrRsvd;

	__IO uint32_t	  ClearTfr;			      /*!< 0x338 : ClearTfr : Clear for IntTfr Interrupt	*/
	     uint32_t		ClearTfrRsvd;
	__IO uint32_t	  ClearBlock;			    /*!< 0x340 : ClearBlock : Clear for IntBlock Interrupt	*/
	     uint32_t		ClearBlockRsvd;
	__IO uint32_t	  ClearSrcTran;		    /*!< 0x348 : ClearSrcTran : Clear for IntSrcTran Interrupt	*/
	     uint32_t		ClearSrcTranRsvd;
	__IO uint32_t	  ClearDstTran;		    /*!< 0x350 : ClearDstTran : Clear for IntDstTran Interrupt	*/
	     uint32_t		ClearDstTranRsvd;
	__IO uint32_t	  ClearErr;			      /*!< 0x358 : ClearErr : Clear for IntErr Interrupt	*/
	     uint32_t		ClearErrRsvd;

	__IO uint64_t	  StatusInt;			    /*!< 0x360 : StatusInt : Status for each interrupt type	*/
	__IO uint64_t	  ReqSrcReg;			    /*!< 0x368 : ReqSrcReg : Source Software Transaction Request Register	*/
	__IO uint64_t	  ReqDstReg;			    /*!< 0x370 : ReqDstReg : Destination Software Transaction Request Register	*/
	__IO uint64_t	  SglReqSrcReg;		    /*!< 0x378 : SglReqSrcReg : Single Source Transaction Request Register	*/
	__IO uint64_t	  SglReqDstReg;		    /*!< 0x380 : SglReqDstReg : Single Destination Transaction Request Register	*/
	__IO uint64_t	  LstSrcReg;			    /*!< 0x388 : LstSrcReg : Last Source Transaction Request Register	*/
	__IO uint64_t	  LstDstReg;			    /*!< 0x390 : LstDstReg : Last Destination Transaction Request Register	*/

	__IO uint32_t	  DmaCfgReg;			    /*!< 0x398 : DmaCfgReg : DMA Configuration Register	*/
	     uint32_t 	DmaCfgRegReserved;	  

	__IO uint32_t	  ChEnReg;			      /*!< 0x3a0 : ChEnReg : DMA Channel Enable Register	*/
	     uint32_t		ChEnRegReserved;

	__IO uint64_t	  DmaIdReg;			      /*!< 0x3a8 : DmaIdReg : DMA ID Register	*/
	__IO uint64_t	  DmaTestReg;			    /*!< 0x3b0 : DmaTestReg : DMA Test Register	*/

	__IO uint64_t	  DMA_COMP_PARAMS_4;	/*!< 0x3d8 : DMA_COMP_PARAMS_4 : Component parameter settings for Channel4 and Channel3 	*/
	__IO uint64_t	  DMA_COMP_PARAMS_3;	/*!< 0x3e0 : DMA_COMP_PARAMS_3 : Component parameter settings for Channel2 and Channel1 	*/
	__IO uint64_t	  DMA_COMP_PARAMS_2;	/*!< 0x3e8 : DMA_COMP_PARAMS_2 : Component parameter settings 	*/
	__IO uint64_t	  DMA_COMP_PARAMS_1;	/*!< 0x3f0 : DMA_COMP_PARAMS_1 : Component parameter settings 	*/

	__IO uint64_t	DmaCompID;			    /*!< 0x3f8 : DMA Component ID Register : Component version register	*/
} DMA_GLOBAL_TypeDef;

#endif /* __DMA_H_ */
