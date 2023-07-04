/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : wdgt.h
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

#ifndef _WDGT_H_
#define	_WDGT_H_


#ifdef __cplusplus
 extern "C" {
#endif 

//#include "MFTP.h"


#define	WDGT_Clear					      ((uint16_t)0x0001)

#define	WDGT_AccessMask			    	((uint16_t)0x0001)

#define	WDGT_CLOCK_PCLKDIVIDED2		((uint16_t)0x0000)
#define	WDGT_CLOCK_PCLKDIVIDED4		((uint16_t)0x0001)
#define	WDGT_CLOCK_PCLKDIVIDED8		((uint16_t)0x0002)
#define	WDGT_CLOCK_PCLKDIVIDED16	((uint16_t)0x0003)
#define	WDGT_CLOCK_PCLKDIVIDED32	((uint16_t)0x0004)
#define	WDGT_CLOCK_PCLKDIVIDED64	((uint16_t)0x0005)
#define	WDGT_CLOCK_PCLKDIVIDED128	((uint16_t)0x0006)
#define	WDGT_CLOCK_PCLKDIVIDED256	((uint16_t)0x0007)

#define	WDGT_CLOCK_MASK				    ((uint16_t)0x0007)

#define	WDGT_WDGT_DisableMask		  ((uint16_t)0xFFF7)
#define	WDGT_WDGT_Enable			    ((uint16_t)0x0008)
 
#define	WDGT_INT_DisableMask		  ((uint16_t)0xFFEF)
#define	WDGT_INT_Enable				    ((uint16_t)0x0010)

#define	WDGT_RESET_DisableMask	  ((uint16_t)0xFFDF)
#define	WDGT_RESET_Enable			    ((uint16_t)0x0020)

#define	WDGT_OVERFLOW_Status		  ((uint16_t)0x0040)
#define	WDGT_INTERRUPT_Status		  ((uint16_t)0x0080)

#define	WDGT_RESET_Status			    ((uint16_t)0x0100)

#define	WDGT_ACCEDSS_KEY			    ((uint16_t)0xACCE)




//#define	Peripheral_UsrWdgtClr_ADDRESS			0x40008000

//#define	UsrWdgtClr_Band_Offset					(Peripheral_UsrWdgtClr_ADDRESS - PERI_BIT_BAND_Base)
//#define UsrWdgt_Clr_Offset						0
//#define	USRWDGT_CLR								(*(__IO uint32_t *)(PERI_BIT_BAND_AliasBase+ (UsrWdgtClr_Band_Offset * 32) + (UsrWdgt_Clr_Offset * 4)))

//#define	Peripheral_LockUpWdgtClr_ADDRESS		0x40013000

//#define	LockUpWdgtClr_Band_Offset				(Peripheral_LockUpWdgtClr_ADDRESS - PERI_BIT_BAND_Base)
//#define	LockUpWdgt_Clr_Offset					0
//#define	LWDT_CLR							  	(*(__IO uint32_t *)(PERI_BIT_BAND_AliasBase+ (LockUpWdgtClr_Band_Offset * 32) + (LockUpWdgt_Clr_Offset * 4)))


#define START_DOG()             Hal_Kick_DOG()
#define KICK_DOG()              Hal_Kick_DOG()
#define FREE_DOG()              Hal_Release_DOG()

typedef struct
{
	uint16_t WDGT_Prescaler;					//000 DIV2, 001 DIV4, 010 DIV8, 011 DIV16, 100 DIV32, 101 DIV64, 110 DIV128, 111 DIV256	
	uint16_t WDGT_Count;						  // Wdgt value
	uint16_t WDGT_ResetDelayCount;
	uint16_t WDGT_ResetCount;					// Max 15
	
	//uint16_t WDGT_IRQChannelCmd;
	uint16_t WDGT_RSTIRQChannelCmd;
} WDGTS_InitTypeDef;								//Lock Up Watch Dog 

void WDGT_Init(WDT_TypeDef* WDGTx);
void WDGT_DeInit(WDT_TypeDef* WDGTx);

void WDGT_SetConfig(WDT_TypeDef* WDGTx, WDGTS_InitTypeDef* WDGT_InitStructure);

void WDGT_SetCLR(WDT_TypeDef* WDGTx);
void WDGT_SetLock(WDT_TypeDef* WDGTx);
void WDGT_ITConfig(WDT_TypeDef* WDGTx, FunctionalState NewFunction);
void WDGT_Cmd(WDT_TypeDef* WDGTx, FunctionalState NewFunction);
uint16_t WDGT_GetAccessRegStatus(WDT_TypeDef* WDGTx);
//void Hal_WDT_Config(void); // NOTE : not used!!
extern void Hal_Kick_DOG(void);
extern void Hal_Release_DOG(void);
extern void Hal_WDT_Init(void);
extern void Hal_WDT_DeInit(void);




#ifdef __cplusplus
}
#endif

#endif /* _WDGT_H_ */
