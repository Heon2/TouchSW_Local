/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _wdt.h
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

#ifndef __WDT_H_
#define __WDT_H_


/* ================================================================================ */
/* ================                       WDT                      ================ */
/* ================================================================================ */

/**
 * @Brief  Flash Control Register
 */



extern uint8_t cnt;

typedef struct
{

    union {
	    __IO uint32_t	WDT_CLR;		  // 0x00	WDT Clear				      0x0 
      
      struct {
          __IO uint32_t wdtClr : 1; // WDT Clear 
      } WDT_CLR_b;
    } ;

    union {
	    __IO uint32_t	WDT_ACCE;		  // 0x04	WDT Access Control		0x0 
      
      struct {
          __IO uint32_t wdtLock : 1; // WDT Access lock 
      } WDT_ACCE_b;
    } ;

    union {
	    __IO uint32_t	WDT_CON;		  // 0x08	WDT Control Register	0x0000_0007 
      
      struct {
          __IO uint32_t wdtclksel    : 3; // WDT divided clock source sel
          __IO uint32_t wdten        : 1; // WDT Enable in normal mode 
          __IO uint32_t wdtintren    : 1; // WDT Interrupt Enable  
          __IO uint32_t wdtrsten     : 1; // WDT Reset Enable  
          __IO uint32_t wdtreserved  : 2; // WDT reserved
          __I  uint32_t wdtovf       : 1; // WDT count overflow
          __I  uint32_t wdtintrout   : 1; // WDT interrupt out
          __I  uint32_t wdtrstout    : 1; // WDT reset out
      } WDT_CON_b;
    } ;

    union {
	    __IO uint32_t	WDT_WIDTH;		// 0x0C	WDT Period Value		  0xFFFF_FFFF 
      
      struct {
          __IO uint32_t wdtwidth : 16; // WDT timer period
          __I  uint32_t wdttmcnt : 16; // WDT timer count
      } WDT_WIDTH_b;
    } ;

    union {
	    __IO uint32_t	WDT_RST_DLY;	// 0x10	Reset Delay.			    0xFFFF_FFFF 
      
      struct {
          __IO uint32_t rstdlywidth : 16; // WDT Reset delay Width 
          __I  uint32_t rstdlycnt   : 16; // WDT Reset delay count
      } WDT_RST_DLY_b;
    } ;

    union {
	    __IO uint32_t	WDT_RST_DUR;	// 0x14	Reset Duration			  0x0000_00FF 
      
      struct {
          __IO uint32_t rstdlywidth : 4; // WDT Reset delay Width 
          __I  uint32_t rstdlycnt   : 4; // WDT Reset delay count
      } WDT_RST_DUR_b;
    } ;

    union {
	    __IO uint32_t	WDT_CLR_DLY;
      
      struct {
          __IO uint32_t rstdlywidth : 8; // WDT Timer Clear delay Width 
          __IO  uint32_t rstdlycnt   : 1; // WDT Timer Clear delay enable
      } WDT_CLR_DLY_b;
    } ;

} WDT_TypeDef;


#endif /* __WDT_H_ */
