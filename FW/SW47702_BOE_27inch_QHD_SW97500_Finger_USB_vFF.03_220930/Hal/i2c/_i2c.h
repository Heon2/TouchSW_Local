/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _i2c.h
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

#ifndef __I2C_H_
#define __I2C_H_


/* ================================================================================ */
/* ================                      I2C                       ================ */
/* ================================================================================ */

typedef union
{
	struct {
		unsigned	I2cId:					7;	// I2C Master/Slave Device Address
		unsigned	reserved:				25;
	} tBit;
	__IO uint32_t ulBulk;
} t_I2C_DEVICE_ADDR;	// I2C Master/Slave Device Address Register

typedef union
{
	struct {
		unsigned	I2cSWReset:				1;	// I2C Software Reset
		unsigned 	reserved:				31;
	} tBit;
	__O uint32_t ulBulk;
} t_I2C_SW_RESET;	// I2C Master/Slave Software Reset Register

typedef union
{
	struct {
		unsigned I2cItrptEn:       			1;	// I2C Interrupt Enable
		unsigned I2cStrItrptEn:     		1;	// I2C Slave Start Interrupt Enable
		unsigned I2cStpItrptEn:     		1;	// I2C Stop Interrupt Enable
		unsigned I2cAddChkItrptEn:  		1;	// I2C Slave Device Address matched Interrupt Enable
		unsigned I2cByteItrptEn:    		1;	// I2C Slave Byte Done Interrupt Enable
		unsigned I2cMstItrptEn:     		1;	// I2C Master Packet Done Interrupt Enable
		unsigned I2cIspModeEn:      		1;	// I2C ISP Protocol Entry Mode Enable
		unsigned I2cTxFifoItrptEn:  		1;	// I2C TX FIFO Interrupt Enable
		unsigned I2cRxFifoItrptEn:  		1;	// I2C RX FIFO Interrupt Enable
		unsigned I2cSclHoldItrptEn: 		1;	// I2C SCL Hold Interrupt Enable
		unsigned I2cFilterEn:				1;	// I2C Filter Enable
		unsigned reserved:					21;
	} tBit;
	__IO uint32_t ulBulk;
} t_I2C_GLB_CR;	// I2C Interrupt Control Register

typedef union
{
	struct {
		unsigned I2cMstClkDiv: 				16;	// I2C Master SCLK Clock Divide Value
		unsigned reserved:					16;
	} tBit;
	__IO uint32_t ulBulk;	  // 0x0C
} t_I2C_MST_CR1;	// I2C Master Control Register 1

typedef union
{
	struct {
		unsigned I2cMstDataTr: 				8;	// I2C Master Data Transfer
		unsigned I2cMstStr: 				1;	// I2C Master Start Condition
		unsigned I2cMstStop:				1;	// I2C Master Stop Condition
		unsigned I2cMstRcvMode:				1;	// I2C Master Receive Mode
		unsigned I2cMstNackTr:				1;	// I2C Ack Condition
		unsigned reserved:					20;
	} tBit;
	__IO uint32_t ulBulk;	  // 0x10
} t_I2C_MST_CR2;	// I2C Master Control Register 2

typedef union
{
	struct {
		unsigned I2C_ITRPT:					1;	// I2C Interrupt Flag
		unsigned reserved00:				1;	// Not Used
		unsigned IspMode:          			1;	// I2C ISP Mode Status
		unsigned I2cSlvRdWrFlag:   			1;	// I2C Slave R/W Condition Status
		unsigned I2cSlvAckRcv:     			1;	// I2C Slave Ack Condition
		unsigned I2cPacketEn:      			1;	// I2CMaster packet Status
		unsigned I2cMstAckRcv:     			1;	// I2C Master Received Ack Condition
		unsigned reserved01:            	1;	// Not Used
		unsigned I2cMstDataRcv:    			8;	// I2C Master Received Data Status
		unsigned I2cItrptState:    			4;	// I2C Interrupt State
		unsigned reserved:					12;
	} tBit;
	__IO uint32_t ulBulk;		  // 0x14
} t_I2C_GLB_SR;	// I2C Global Status Register

typedef union
{
	struct {
		unsigned I2cSlvStSR:    			14;	// I2C Slave FSM Status
		unsigned reserved:					18;
	} tBit;
	__I  uint32_t ulBulk;	  // 0x18
} t_I2C_SLV_ST_SR;	// I2C Slave Status Register

typedef union
{
	struct {
		unsigned TxFifoInit:     			1;	// I2C TXFIFO WPTR / RPTR Clear
		unsigned TxDmaIfEn :     			1;	// I2C DMA I/F TX Enable
		unsigned TxFifoWmLv:     			5;	// I2C TXFIFO Watermark Level
		unsigned TxFifoReqSel:   			1;	// TXFIFO Request Selection
		unsigned RxFifoInit:     			1;	// I2C RXFIFO WPTR / RPTR Clear
		unsigned RxDmaIfEn:      			1;	// I2C DMA I/F RX Enable
		unsigned RxFifoWmLv:     			5;	// I2C RXFIFO Watermark Level
		unsigned RxFifoReqSel:   			1;	// RXFIFO Request Selection
		unsigned reserved:					16;
	} tBit;
	__IO uint32_t ulBulk;	  // 0x1C
} t_I2C_FIFO_CR;	// I2C FIFO Control Register

typedef union
{
	struct {
		unsigned TxFifoData:   				8;	// TXFIFO Data	//	ToDo There is not on register map !!!
		unsigned reserved:					24;
	} tBit;
	__O uint32_t ulBulk;  // 0x20
} t_I2C_TXFIFO_DATA;	// I2C TXFIFO Data Register

typedef union
{
	struct {
		unsigned RxFifoData:   				8;	// RXFIFO Data	//	ToDo There is not on register map !!!
		unsigned reserved:					24;
	} tBit;
	__I uint32_t ulBulk;  // 0x24
} t_I2C_RXFIFO_DATA;	// I2C RXFIFO Data Register

typedef union
{
	struct {
		unsigned TxFifoEmpty:    			1;	// TXFIFO Empty Flag
		unsigned TxFifoFull:     			1;	// TXFIFO Full Flag
		unsigned TxFifoWmFlag:   			1;	// TXFIFO Watermark Level Flag
		unsigned TxFifoWmBlw:    			1;	// TXFIFO Watermark Level Below Flag
		unsigned TxWrPtr:        			5;	// TXFIFO Write Pointer
		unsigned TxRdPtr:        			5;	// TXFIFO Read Pointer
		unsigned reserved00:				2;	// Not Used
		unsigned RxFifoEmpty:    			1;	// RXFIFO Empty Flag
		unsigned RxFifoFull:     			1;	// RXFIFO Full Flag
		unsigned RxFifoWmFlag:   			1;	// RXFIFO Watermark Level Flag
		unsigned RxFifoWmAbv:    			1;	// RXFIFO Watermark Level Above Flag
		unsigned RxWrPtr:        			5;	// RXFIFO Write Pointer
		unsigned RxRdPtr:       			5;	// RXFIFO Read Pointer
		unsigned reserved01:          		2;	// Not Used
	} tBit;
	__I uint32_t ulBulk;  // 0x28
} t_I2C_FIFO_SR;	// I2C TXFIFO / RXFIFO Status Register

typedef union
{
	struct {
		unsigned SetPwrRegLSBOn:     		8;	// Power Register LSB for Wakeup Mode
		unsigned SetPwrRegLSBSleep:  		8;	// Power Register LSB for Sleep Mode
		unsigned SetPwrRegMSB:       		8;	// Register MSB of Power Mode
		unsigned SetPwrRegLSBFirst:  		1;	// Set I2C protocol, LSB first
		unsigned reserved:					7;
	} tBit;
	__IO uint32_t ulBulk;  // 0x2C
} t_I2C_SET_PWR_REG;	// I2C Set Power Register

typedef union
{
	struct {
		unsigned SetPwrCmdLSB:     			8;	// Command LSB of Power Mode
		unsigned SetPwrCmdMSB:     			8;	// Command MSB of Power mode
		unsigned SetPwrCmdEn:      			1;	// Power Command Enable
		unsigned SetPwrLSBFirst:   			1;	// Set I2C Protocol, LB first
		unsigned reserved:					14;
	} tBit;
	__IO uint32_t ulBulk;  // 0x30
} t_I2C_SET_PWR_CMD;	// I2C Set Power Command Register

typedef union
{
	struct {
		unsigned WakeUpItrptEn:    			1;	// Wake up Interrupt Enable
		unsigned SleepItrptEn:     			1;	// Sleep Interrup Enable
		unsigned WakeUpItrpt:      			1;	// Wake Up Interrupt
		unsigned SleepItrpt:      	 		1;	// Sleep Interrupt
		unsigned PowerState:        		1;	// State of Power Save Mode
		unsigned reserved:					27;
	} tBit;
	__IO uint32_t ulBulk;  // 0x34
} t_I2C_SET_PWR_INT;	// I2C Set Power Interrupt Register

typedef union
{
	struct {
		unsigned I2cDlyVal:    				6;	// Delay after negative edge of SCL
		unsigned reserved:					26;
	} tBit;
	__IO uint32_t ulBulk;	  // 0x38
} t_I2C_DLY_VALUE;	// I2C Delay Value Register

typedef union
{
	struct {
		unsigned I2cSlvTrLen:    			15;	// I2C Slave Transfer Length
		unsigned reserved00:				1;	// Not Used
		unsigned I2cSlvTrCnt:     			15;	// I2C Slave Transfer Count Value
		unsigned I2cSlvTrDone:    			1;	// I2C Slave Transfer Done Flag
	} tBit;
	__IO uint32_t ulBulk;	  // 0x3C
} t_I2C_SLV_DBG;	// I2C Slave Debugging Register

typedef union
{
	struct {
		unsigned I2cMstTrLen:    			15;	// I2C Master Transfer Length
		unsigned reserved00:           		1;	// Not Used
		unsigned I2cMstTrCnt:     			15;	// I2C Master Transfer Count Value
		unsigned I2cMstTrDone:    			1;	// I2C Master Transfer Done Flag
	} tBit;
	__IO uint32_t ulBulk;	  // 0x40
} t_I2C_MST_DBG;	// I2C Master Debugging Register

typedef union
{
	struct {
		unsigned TxFifoInit2:    			1;	// TXFIFO WPTR / RPTR Clear
		unsigned TxFifoIntEna2:  			1;	// Interrupt I/F TX Enable
		unsigned TxFifoWmLv2:    			5;	// TXFIFO Watermark Level 2
		unsigned TxFifoIntSel:   			1;	// TXFIFO Interrupt Selection
		unsigned RxFifoInit2:    			1;	// RXFIFO WPTR / RPTR Clear
		unsigned RxFifoIntEna2:  			1;	// Interrupt I/F RX Enable
		unsigned RxFifoWmLv2:    			5;	// RXFIFO Watermark Level 2
		unsigned RxFifoIntSel:   			1;	// RXFIFO Interrupt Selection
		unsigned reserved:					16;
	} tBit;
	__IO uint32_t ulBulk;	  // 0x44
} t_I2C_FIFO_CR2;	// I2C FIFO Control Register 2

typedef union
{
	struct {
		unsigned TxFifoEmpty:    			1;	// TXFIFO Empty Flag
		unsigned TxFifoFull:     			1;	// TXFIFO Full Flag
		unsigned TxFifoWmFlag2:  			1;	// TXFIFO Watermark Level Flag
		unsigned TxFifoWmBlw2:   			1;	// TXFIFO Watermark Level Below Flag
		unsigned TxWrPtr:        			5;	// TXFIFO Write Pointer
		unsigned TxRdPtr:        			5;	// TXFIFO Read Pointer
		unsigned TxFifoInt:      			1;	// TXFIFO Interrupt
		unsigned reserved00:           		1;	// Not Used
		unsigned RxFifoEmpty:    			1;	// RXFIFO Empty Flag
		unsigned RxFifoFull:     			1;	// RXFIFO Full Flag
		unsigned RxFifoWmFlag2:  			1;	// RXFIFO Watermark Level Flag
		unsigned RxFifoWmAbv2:   			1;	// RXFIFO Watermark Level Above Flag
		unsigned RxWrPtr:        			5;	// RXFIFO Write Pointer
		unsigned RxRdPtr:        			5;	// RXFIFO Read Pointer
		unsigned RxFifoInt:      			1;	// RXFIFO Interrupt
		unsigned reserved01:				1;
	} tBit;
	__I uint32_t ulBulk;	  // 0x48
} t_I2C_FIFO_SR2;	// I2C TXFIFO / RXFIFO Status Register 2

typedef union
{
	struct {
		unsigned SlpCr:      				1;	// Sleep Enable
		unsigned PrMux:      				1;	// APB Bus RDATA Selection
		unsigned reserved:					30;
	} tBit;
	__IO uint32_t ulBulk;		  // 0x58
} t_I2C_SLP_CR; 	// I2C Sleep Control Register

typedef union
{
	struct {
		unsigned SlpSr:		 				1;	// Device Address Check Interrupt
		unsigned PclkEna:	 				1;	// Normal PCLK Enable
		unsigned PclkCr:		 			1;	// SCLK Enable
		unsigned reserved:					29;
	} tBit;
	__IO uint32_t ulBulk;		  // 0x5C
} t_I2C_SLP_SR;	// I2C Sleep Status Register

typedef union
{
	struct {
		unsigned I2cSclHoldEn:		 		1;	// SCL Stretch Function1 Enable
		unsigned I2cSclHoldStatus:	 		1;	// SCL Sretch Status
		unsigned reserved:					30;
	} tBit;
	__IO uint32_t ulBulk;		  // 0x60
} t_I2C_SCL_HOLD;	// I2C SCL Stretch Control Register

typedef union
{
	struct {
		unsigned I2cSclHoldEn2:		 		1;	// SCL Stretch Fuction2 Enable
		unsigned I2cSclHoldRls:		 		1;	// SCL Stretch Status
		unsigned I2cSclHoldCntEn:	 		1;	// SCL Hold Timeout Count Enable
		unsigned I2cSclHoldTOutSt:	 		1;	// SCL Hold Timeout Status
		unsigned reserved00:				12;	// Not Used
		unsigned I2cSclHoldTOutVal:	 		16;	// SCL Hold Timeout Counter Value
	} tBit;
	__IO uint32_t ulBulk;		  // 0x64
} t_I2C_SCL_HOLD2;	// I2C SCL Stretch Control Register 2

typedef struct
{																		//Index
	__IO t_I2C_DEVICE_ADDR 			I2C_DEVICE_ADDR;						//0x0000
	__O  t_I2C_SW_RESET				I2C_SW_RESET;                   	//0x0001
	__IO t_I2C_GLB_CR  				I2C_GLB_CR;                     	//0x0002
	__IO t_I2C_MST_CR1  			I2C_MST_CR1;                    	//0x0003
	__IO t_I2C_MST_CR2 				I2C_MST_CR2;                    	//0x0004
	__IO t_I2C_GLB_SR  				I2C_GLB_SR;                     	//0x0005
	__I  t_I2C_SLV_ST_SR   			I2C_SLV_ST_SR;                  	//0x0006
	__IO t_I2C_FIFO_CR 				I2C_FIFO_CR;                    	//0x0007
	__O  uint32_t 					I2C_TXFIFO_DATA;                	//0x0008
	__I  uint32_t 					I2C_RXFIFO_DATA;                	//0x0009
	__I  t_I2C_FIFO_SR 				I2C_FIFO_SR;                    	//0x000A
	__IO t_I2C_SET_PWR_REG 			I2C_SET_PWR_REG;                	//0x000B
	__IO t_I2C_SET_PWR_CMD 			I2C_SET_PWR_CMD;                	//0x000C
	__IO t_I2C_SET_PWR_INT 			I2C_SET_PWR_INT;                	//0x000D
	__IO t_I2C_DLY_VALUE 			I2C_DLY_VALUE;                  	//0x000E
	__IO t_I2C_SLV_DBG 				I2C_SLV_DBG;                    	//0x000F
	__IO t_I2C_MST_DBG 				I2C_MST_DBG;                    	//0x0010
	__IO t_I2C_FIFO_CR2 			I2C_FIFO_CR2;                   	//0x0011
	__I  t_I2C_FIFO_SR2 			I2C_FIFO_SR2;                   	//0x0012
	__IO t_I2C_SLP_CR 				I2C_SLP_CR;                     	//0x0013
	__IO t_I2C_SLP_SR 				I2C_SLP_SR;                     	//0x0014
	__IO t_I2C_SCL_HOLD 			I2C_SCL_HOLD;                   	//0x0015
	__IO t_I2C_SCL_HOLD2 			I2C_SCL_HOLD2;                  	//0x0016
	__IO uint32_t 					I2C_Reserved00;              		//0x0017
	__IO uint32_t 					I2C_Reserved01;              		//0x0018
	__IO uint32_t 					I2C_Reserved02;              		//0x0019
	__IO uint32_t 					I2C_Reserved03;              		//0x001A
	__IO uint32_t 					I2C_Reserved04;              		//0x001B
	__IO uint32_t 					I2C_Reserved05;              		//0x001C
	__IO uint32_t 					I2C_Reserved06;              		//0x001D
	__IO uint32_t 					I2C_Reserved07;              		//0x001E
	__IO uint32_t 					I2C_Reserved08;              		//0x001F

} tI2C_CtrlReg_t;


//
//	__IO t_I2C_DEVICE_ADDR 			I2CM1_DEVICE_ADD;					//0x0020
//	__O  t_I2C_SW_RESET				I2CM1_SW_RESET;                   	//0x0021
//	__IO t_I2C_GLB_CR  				I2CM1_GLB_CR;                     	//0x0022
//	__IO t_I2C_MST_CR1  			I2CM1_MST_CR1;                    	//0x0023
//	__IO t_I2C_MST_CR2 				I2CM1_MST_CR2;                    	//0x0024
//	__IO t_I2C_GLB_SR  				I2CM1_GLB_SR;                     	//0x0025
//	__I  t_I2C_SLV_ST_SR   			I2CM1_SLV_ST_SR;                  	//0x0026
//	__IO t_I2C_FIFO_CR 				I2CM1_FIFO_CR;                    	//0x0027
//	__O  uint32_t 					I2CM1_TXFIFO_DATA;                	//0x0028
//	__I  uint32_t 					I2CM1_RXFIFO_DATA;                	//0x0029
//	__I  t_I2C_FIFO_SR 				I2CM1_FIFO_SR;                    	//0x002A
//	__IO t_I2C_SET_PWR_REG 			I2CM1_SET_PWR_REG;                	//0x002B
//	__IO t_I2C_SET_PWR_CMD 			I2CM1_SET_PWR_CMD;                	//0x002C
//	__IO t_I2C_SET_PWR_INT 			I2CM1_SET_PWR_INT;                	//0x002D
//	__IO t_I2C_DLY_VALUE 			I2CM1_DLY_VALUE;                  	//0x002E
//	__IO t_I2C_SLV_DBG 				I2CM1_SLV_DBG;                    	//0x002F
//	__IO t_I2C_MST_DBG 				I2CM1_MST_DBG;                    	//0x0030
//	__IO t_I2C_FIFO_CR2 			I2CM1_FIFO_CR2;                   	//0x0031
//	__I  t_I2C_FIFO_SR2 			I2CM1_FIFO_SR2;                   	//0x0032
//	__IO t_I2C_SLP_CR 				I2CM1_SLP_CR;                     	//0x0033
//	__IO t_I2C_SLP_SR 				I2CM1_SLP_SR;                     	//0x0034
//	__IO t_I2C_SCL_HOLD 			I2CM1_SCL_HOLD;                   	//0x0035
//	__IO t_I2C_SCL_HOLD2 			I2CM1_SCL_HOLD2;                  	//0x0036
//	__IO uint32_t 					I2CM1_Reserved00;              		//0x0037
//	__IO uint32_t 					I2CM1_Reserved01;              		//0x0038
//	__IO uint32_t 					I2CM1_Reserved02;                   //0x0039
//	__IO uint32_t 					I2CM1_Reserved03;                   //0x003A
//	__IO uint32_t 					I2CM1_Reserved04;                   //0x003B
//	__IO uint32_t 					I2CM1_Reserved05;                   //0x003C
//	__IO uint32_t 					I2CM1_Reserved06;                   //0x003D
//	__IO uint32_t 					I2CM1_Reserved07;                   //0x003E
//	__IO uint32_t 					I2CM1_Reserved08;				    //0x003F
//	__IO uint32_t 					I2CM1_Reserved09;                   //0x0040
//	__IO uint32_t 					I2CM1_Reserved10;                   //0x0041
//	__IO uint32_t 					I2CM1_Reserved11;                   //0x0042
//	__IO uint32_t 					I2CM1_Reserved12;                   //0x0043
//	__IO uint32_t 					I2CM1_Reserved13;                   //0x0044
//	__IO uint32_t 					I2CM1_Reserved14;                   //0x0045
//	__IO uint32_t 					I2CM1_Reserved15;                   //0x0046
//	__IO uint32_t 					I2CM1_Reserved16;              		//0x0047
//
//} tI2C_CtrlReg_t;



#endif /* __I2C_H_ */
