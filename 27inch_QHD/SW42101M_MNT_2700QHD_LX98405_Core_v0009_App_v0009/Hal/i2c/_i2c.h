/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _i2c.h
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

#ifndef __I2C_H_
#define __I2C_H_


/* ================================================================================ */
/* ================                      I2C                       ================ */
/* ================================================================================ */

typedef struct
{
	union
	{
		struct
		{
			__IO uint32_t I2cId : 7;	// I2C Master/Slave Device Address
		} tBit;
		__IO uint32_t ulBulk;	  // 0x00
	} I2C_DEVICE_ADDR;	// I2C Master/Slave Device Address Register

	union
	{
		struct
		{
			__O uint32_t I2cSWReset : 1;	// I2C Software Reset
		} tBit;
		__O uint32_t ulBulk;	  // 0x04
	} I2C_SW_RESET;	// I2C Master/Slave Software Reset Register

	union
	{
		struct
		{
			__IO uint32_t I2cItrptEn        : 1;	// I2C Interrupt Enable
			__IO uint32_t I2cStrItrptEn     : 1;	// I2C Slave Start Interrupt Enable
			__IO uint32_t I2cStpItrptEn     : 1;	// I2C Stop Interrupt Enable
			__IO uint32_t I2cAddChkItrptEn  : 1;	// I2C Slave Device Address matched Intrrupt Enable
			__IO uint32_t I2cByteItrptEn    : 1;	// I2C Slave Byte Done Intrrupt Enable
			__IO uint32_t I2cMstItrptEn     : 1;	// I2C Master Packet Done Interrupt Enable
			__IO uint32_t I2cIspModeEn      : 1;	// I2C ISP Protocol Entry Mode Enable
			__IO uint32_t I2cTxFifoItrptEn  : 1;	// I2C TX FIFO Interrupt Enable
			__IO uint32_t I2cRxFifoItrptEn  : 1;	// I2C RX FIFO Interrupt Enable
			__IO uint32_t I2cSclHoldItrptEn : 1;	// I2C SCL Hold Interrupt Enable
			__IO uint32_t I2cFilterEn       : 1;	// I2C Filter Enable
		} tBit;
		__IO uint32_t ulBulk;	  // 0x08
	} I2C_GLB_CR;	// I2C Interrupt Control Register

	union
	{
		struct
		{
			__IO uint32_t I2cMstClkDiv : 16;	// I2C Master SCLK Clock Divide Value
		} tBit;
		__IO uint32_t ulBulk;	  // 0x0C
	} I2C_MST_CR1;	// I2C Master Control Register 1

	union
	{
		struct
		{
			__IO uint32_t I2cMstDataTr	: 8;	// I2C Master Data Transfer
			__IO uint32_t I2cMstStr		: 1;	// I2C Master Start Condition
			__IO uint32_t I2cMstStop		: 1;	// I2C Master Stop Condition
			__IO uint32_t I2cMstRcvMode	: 1;	// I2C Master Receive Mode
			__IO uint32_t I2cMstNackTr	: 1;	// I2C Ack Condition
		} tBit;
		__IO uint32_t ulBulk;	  // 0x10
	} I2C_MST_CR2;	// I2C Master Control Register 2

	union
	{
		struct
		{
			__IO uint32_t I2C_ITRPT       : 1;	// I2C Interrupt Flag
			__I uint32_t IspMode         : 1;	// I2C ISP Mode Status
			__I uint32_t Rsvd1           : 1;	// Not Used
			__I uint32_t I2cSlvRdWrFlag  : 1;	// I2C Slave R/W Condition Status
			__I uint32_t I2cSlvAckRcv    : 1;	// I2C Slave Ack Condition
			__I uint32_t I2cPacketEn     : 1;	// I2CMaster packet Status
			__I uint32_t I2cMstAckRcv    : 1;	// I2C Master Received Ack Condition
			__I uint32_t Rsvd2           : 1;	// Not Used
			__I uint32_t I2cMstDataRcv   : 8;	// I2C Master Received Data Status
			__I uint32_t I2cItrptState   : 4;	// I2C Interrupt State
		} tBit;
		__IO uint32_t ulBulk;		  // 0x14
	} I2C_GLB_SR;	// I2C Global Status Register

	union
	{
		struct
		{
			__I uint32_t I2cSlvStSR   : 14;	// I2C Slave FSM Status
		} tBit;
		__I  uint32_t ulBulk;	  // 0x18
	} I2C_SLV_ST_SR;	// I2C Slave Status Register

	union
	{
		struct
		{
			__IO uint32_t TxFifoInit    : 1;	// I2C TXFIFO WPTR / RPTR Clear
			__IO uint32_t TxDmaIfEn     : 1;	// I2C DMA I/F TX Enable
			__IO uint32_t TxFifoWmLv    : 5;	// I2C TXFIFO Watermark Level
			__IO uint32_t TxFifoReqSel  : 1;	// TXFIFO Request Selection
			__IO uint32_t RxFifoInit    : 1;	// I2C RXFIFO WPTR / RPTR Clear
			__IO uint32_t RxDmaIfEn     : 1;	// I2C DMA I/F RX Enable
			__IO uint32_t RxFifoWmLv    : 5;	// I2C RXFIFO Watermark Level
			__IO uint32_t RxFifoReqSel  : 1;	// RXFIFO Request Selection
		} tBit;
		__IO uint32_t ulBulk;	  // 0x1C
	}I2C_FIFO_CR;	// I2C FIFO Control Register

	union
	{
		struct
		{
			__O uint32_t TxFifoData  : 8;	// TXFIFO Data
		} tBit;
		__O uint32_t ulBulk;  // 0x20
	} I2C_TXFIFO_DATA;	// I2C TXFIFO Data Register

	union
	{
		struct
		{
			__I uint32_t RxFifoData  : 8;	// RXFIFO Data
		} tBit;
		__I uint32_t ulBulk;  // 0x24
	} I2C_RXFIFO_DATA;	// I2C RXFIFO Data Register

	union
	{
		struct
		{
			__I uint32_t TxFifoEmpty   : 1;	// TXFIFO Empty Flag
			__I uint32_t TxFifoFull    : 1;	// TXFIFO Full Flag
			__I uint32_t TxFifoWmFlag  : 1;	// TXFIFO Watermark Level Flag
			__I uint32_t TxFifoWmBlw   : 1;	// TXFIFO Watermark Level Below Flag
			__I uint32_t TxWrPtr       : 5;	// TXFIFO Write Pointer
			__I uint32_t TxRdPtr       : 5;	// TXFIFO Read Pointer
			__I uint32_t Rsvd1         : 2;	// Not Used
			__I uint32_t RxFifoEmpty   : 1;	// RXFIFO Empty Flag
			__I uint32_t RxFifoFull    : 1;	// RXFIFO Full Flag
			__I uint32_t RxFifoWmFlag  : 1;	// RXFIFO Watermark Level Flag
			__I uint32_t RxFifoWmAbv   : 1;	// RXFIFO Watermark Level Above Flag
			__I uint32_t RxWrPtr       : 5;	// RXFIFO Write Pointer
			__I uint32_t RxRdPtr       : 5;	// RXFIFO Read Pointer
			__I uint32_t Rsvd2         : 2;	// Not Used
		} tBit;
		__I uint32_t ulBulk;  // 0x28
	} I2C_FIFO_SR;	// I2C TXFIFO / RXFIFO Status Register

	union
	{
		struct
		{
			__IO uint32_t SetPwrRegLSBOn    : 8;	// Power Register LSB for Wakeup Mode
			__IO uint32_t SetPwrRegLSBSleep : 8;	// Power Register LSB for Sleep Mode
			__IO uint32_t SetPwrRegMSB      : 8;	// Register MSB of Power Mode
			__IO uint32_t SetPwrRegLSBFirst : 1;	// Set I2C protocol, LSB first
		} tBit;
		__IO uint32_t ulBulk;  // 0x2C
	} I2C_SET_PWR_REG;	// I2C Set Power Register

	union
	{
		struct
		{
			__IO uint32_t SetPwrCmdLSB    : 8;	// Command LSB of Power Mode
			__IO uint32_t SetPwrCmdMSB    : 8;	// Command MSB of Power mode
			__IO uint32_t SetPwrCmdEn     : 1;	// Power Command Enable
			__IO uint32_t SetPwrLSBFirst  : 1;	// Set I2C Protocol, LB first
		} tBit;
		__IO uint32_t ulBulk;  // 0x30
	} I2C_SET_PWR_CMD;	// I2C Set Power Command Register

	union
	{
		struct
		{
			__IO uint32_t WakeUpItrptEn   : 1;	// Wake up Interrupt Enable
			__IO uint32_t SleepItrptEn    : 1;	// Sleep Interrup Enable
			__IO uint32_t WakeUpItrpt     : 1;	// Wake Up Interrupt
			__IO uint32_t SleepItrpt      : 1;	// Sleep Interrupt
			__I uint32_t PowerState      : 1;	// State of Power Save Mode
		} tBit;
		__IO uint32_t ulBulk;  // 0x34
	} I2C_SET_PWR_INT;	// I2C Set Power Interrupt Register

	union
	{
		struct
		{
			__IO uint32_t I2cDlyVal   : 6;	// Delay after negative edge of SCL
		} tBit;
		__IO uint32_t ulBulk;	  // 0x38
	} I2C_DLY_VALUE;	// I2C Delay Value Register

	union
	{
		struct
		{
			__IO uint32_t I2cSlvTrLen   : 15;	// I2C Slave Transfer Length
			__IO uint32_t Rsvd          : 1;	// Not Used
			__I uint32_t I2cSlvTrCnt   : 15;	// I2C Slave Transfer Count Value
			__I uint32_t I2cSlvTrDone  : 1;	// I2C Slave Transfer Done Flag
		} tBit;
		__IO uint32_t ulBulk;	  // 0x3C
	} I2C_SLV_DBG;	// I2C Slave Debugging Register

	union
	{
		struct
		{
			__IO uint32_t I2cMstTrLen   : 15;	// I2C Master Transfer Length
			__IO uint32_t Rsvd          : 1;	// Not Used
			__I uint32_t I2cMstTrCnt   : 15;	// I2C Master Transfer Count Value
			__I uint32_t I2cMstTrDone  : 1;	// I2C Master Transfer Done Flag
		} tBit;
		__IO uint32_t ulBulk;	  // 0x40
	} I2C_MST_DBG;	// I2C Master Debugging Register

	union
	{
		struct
		{
			__IO uint32_t TxFifoInit2   : 1;	// TXFIFO WPTR / RPTR Clear
			__IO uint32_t TxFifoIntEna2 : 1;	// Interrupt I/F TX Enable
			__IO uint32_t TxFifoWmLv2   : 5;	// TXFIFO Watermark Level 2
			__IO uint32_t TxFifoIntSel  : 1;	// TXFIFO Interrupt Selection
			__IO uint32_t RxFifoInit2   : 1;	// RXFIFO WPTR / RPTR Clear
			__IO uint32_t RxFifoIntEna2 : 1;	// Interrupt I/F RX Enable
			__IO uint32_t RxFifoWmLv2   : 5;	// RXFIFO Watermark Level 2
			__IO uint32_t RxFifoIntSel  : 1;	// RXFIFO Interrupt Selection
		} tBit;
		__IO uint32_t ulBulk;	  // 0x44
	} I2C_FIFO_CR2;	// I2C FIFO Control Register 2

	union
	{
		struct
		{
			__I uint32_t TxFifoEmpty   : 1;	// TXFIFO Empty Flag
			__I uint32_t TxFifoFull    : 1;	// TXFIFO Full Flag
			__I uint32_t TxFifoWmFlag2 : 1;	// TXFIFO Watermark Level Flag
			__I uint32_t TxFifoWmBlw2  : 1;	// TXFIFO Watermark Level Below Flag
			__I uint32_t TxWrPtr       : 5;	// TXFIFO Write Pointer
			__I uint32_t TxRdPtr       : 5;	// TXFIFO Read Pointer
			__I uint32_t TxFifoInt     : 1;	// TXFIFO Interrupt
			__I uint32_t Rsvd          : 1;	// Not Used
			__I uint32_t RxFifoEmpty   : 1;	// RXFIFO Empty Flag
			__I uint32_t RxFifoFull    : 1;	// RXFIFO Full Flag
			__I uint32_t RxFifoWmFlag2 : 1;	// RXFIFO Watermark Level Flag
			__I uint32_t RxFifoWmAbv2  : 1;	// RXFIFO Watermark Level Above Flag
			__I uint32_t RxWrPtr       : 5;	// RXFIFO Write Pointer
			__I uint32_t RxRdPtr       : 5;	// RXFIFO Read Pointer
			__I uint32_t RxFifoInt     : 1;	// RXFIFO Interrupt
		} tBit;
		__I uint32_t ulBulk;	  // 0x48
	} I2C_FIFO_SR2;	// I2C TXFIFO / RXFIFO Status Register 2

	union
	{
		struct
		{
			__IO uint32_t I2cStretchEn  : 1;
			__IO uint32_t I2cStretchVal : 31;
		} tBit;
		__IO uint32_t ulBulk;	  // 0x4C
	} I2C_STRTCH_CR1;

	union
	{
		struct
		{
			__IO uint32_t I2cStretchSel   : 1;
			__IO uint32_t I2cStretchApp   : 1;
			__IO uint32_t I2cStretchType  : 1;
		} tBit;
		__IO uint32_t ulBulk;	  // 0x50
	} I2C_STRTCH_CR2;

	union
	{
		struct
		{
			__IO uint32_t I2cSclLowVal  : 32;
		} tBit;
		__I uint32_t ulBulk;	  // 0x54
	} I2C_SCL_VAL;

	union
	{
		struct
		{
			__IO uint32_t SlpCr     : 1;	// Sleep Enable
			__IO uint32_t PrMux     : 1;	// APB Bus RDATA Selection
		} tBit;
		__IO uint32_t ulBulk;		  // 0x58
	} I2C_SLP_CR; 	// I2C Sleep Control Register

	union
	{
		struct
		{
			__IO uint32_t SlpSr		: 1;	// Device Address Check Interrupt
			__I uint32_t PclkEna	: 1;	// Normal PCLK Enable
			__I uint32_t PclkCr		: 1;	// SCLK Enable
		} tBit;
		__IO uint32_t ulBulk;		  // 0x5C
	} I2C_SLP_SR;	// I2C Sleep Status Register

	union
	{
		struct
		{
			__IO uint32_t I2cSclHoldEn		: 1;	// SCL Stretch Function1 Enable
			__I uint32_t I2cSclHoldStatus	: 1;	// SCL Sretch Status
		} tBit;
		__IO uint32_t ulBulk;		  // 0x60
	} I2C_SCL_HOLD;	// I2C SCL Stretch Control Register

	union 
	{
		struct 
		{
			__IO uint32_t I2cSclHoldEn2		: 1;	// SCL Stretch Fuction2 Enable
			__I uint32_t I2cSclHoldRls		: 1;	// SCL Stretch Status 
			__IO uint32_t I2cSclHoldCntEn	: 1;	// SCL Hold Timeout Count Enable
			__I uint32_t I2cSclHoldTOutSt	: 1;	// SCL Hold Timeout Status
			__IO uint32_t Rsvd				: 12;	// Not Used
			__IO uint32_t I2cSclHoldTOutVal	: 16;	// SCL Hold Timeout Counter Value
		} tBit;
		__IO uint32_t ulBulk;		  // 0x64
	} I2C_SCL_HOLD2;	// I2C SCL Stretch Control Register 2

	__IO uint32_t Reserved0;	          // 0x68
	__IO uint32_t Reserved1;	          // 0x6C
	__IO uint32_t Reserved2;	          // 0x70
	__IO uint32_t Reserved3;	          // 0x74
	__IO uint32_t SLP_I2C_DEVICE_ADDR;  // 0x78
	__IO uint32_t SLP_I2C_SW_RESET;	  // 0x7C
	__IO uint32_t SLP_I2C_GLB_CR;	      // 0x80
	__IO uint32_t SLP_I2C_MST_CR1;	  // 0x84
	__IO uint32_t SLP_I2C_MST_CR2;	  // 0x88
	__IO uint32_t SLP_I2C_GLB_SR;		  // 0x8C
	__I  uint32_t SLP_I2C_SLV_ST_SR;	  // 0x90
	__IO uint32_t SLP_I2C_FIFO_CR;	  // 0x94
	__IO uint32_t SLP_I2C_TXFIFO_DATA;  // 0x98
	__I	 uint32_t SLP_I2C_RXFIFO_DATA;  // 0x9C
	__I  uint32_t SLP_I2C_FIFO_SR;	  // 0xA0
	__IO uint32_t SLP_I2C_SET_PWR_REG;  // 0xA4
	__IO uint32_t SLP_I2C_SET_PWR_CMD;  // 0xA8
	__IO uint32_t SLP_I2C_SET_PWR_INT;  // 0xAC
	__IO uint32_t SLP_I2C_DLY_VALUE;	  // 0xB0
	__IO uint32_t SLP_I2C_SLV_DBG;	  // 0xB4
	__IO uint32_t SLP_I2C_MST_DBG;	  // 0xB8
	__IO uint32_t SLP_I2C_FIFO_CR2;	  // 0xBC
	__IO uint32_t SLP_I2C_FIFO_SR2;	  // 0xC0
	__IO uint32_t SLP_I2C_STRTCH_CR1;	  // 0xC4
	__IO uint32_t SLP_I2C_STRTCH_CR2;	  // 0xC8
	__IO uint32_t SLP_I2C_SCL_VAL;	  // 0xCC
	__IO uint32_t SLP_I2C_SCL_HOLD;	  // 0xD0
	__IO uint32_t SLP_I2C_SCL_HOLD2;	  // 0xD4

} tI2C_CtrlReg_t;    

#endif /* __I2C_H_ */
