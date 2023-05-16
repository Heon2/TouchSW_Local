/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : tlvds.c
 * created on : 05. 9. 2018
 * Author : HongTK
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
#include "memory_pool.h"
//#include "module_types.h"


volatile int iSricReadyIntrNum;

void TLVDS_InterruptHandler(void)
{
	if( TLVDS->TLVDS_STATUS.tBit.int_fr_done )
	{
		TLVDS->INT_CLR.tBit.int_fr_done_clr = 1;
		TLVDS->INT_CLR.tBit.int_fr_done_clr = 0;

		TLVDS->TLVDS_CR2.tBit.mem_addr_clr = 1;
		iSricReadyIntrNum = 0;

		hal_set_irq_flag(IRQ_ID_FULL_SAMPLE);
	}
	else if( TLVDS->TLVDS_STATUS.tBit.int_tx_done )
	{
		TLVDS->INT_CLR.tBit.int_tx_done_clr = 1;
		TLVDS->INT_CLR.tBit.int_tx_done_clr = 0;
	}
	else if( TLVDS->TLVDS_STATUS.tBit.int_rx_done )
	{
		TLVDS->INT_CLR.tBit.int_rx_done_clr = 1;
		TLVDS->INT_CLR.tBit.int_rx_done_clr = 0;
	}
	else if( TLVDS->TLVDS_STATUS.tBit.int_sric_ready )
	{
		TLVDS->INT_CLR.tBit.int_sric_ready_clr = 1;
		TLVDS->INT_CLR.tBit.int_sric_ready_clr = 0;
		iSricReadyIntrNum++;
	}
	else if( TLVDS->TLVDS_STATUS.tBit.int_chksum_rx0 || TLVDS->TLVDS_STATUS.tBit.int_chksum_rx1 || TLVDS->TLVDS_STATUS.tBit.int_chksum_rx2 || TLVDS->TLVDS_STATUS.tBit.int_chksum_rx3 )
	{
		TLVDS->INT_CLR.tBit.int_chksum_clr = 1;
		TLVDS->INT_CLR.tBit.int_chksum_clr = 0;
	}
	else if ( TLVDS->TLVDS_STATUS.tBit.int_mux_done )
	{
		TLVDS->INT_CLR.tBit.int_mux_done_clr = 1;
		TLVDS->INT_CLR.tBit.int_mux_done_clr = 0;
	}
}

void TLVDS_Initialize(void)
{
	/*
	 * TLVDS analog init (SCRB)
	 */
	SCRB->SYS_TLVDS_PD_N.tBit.R_TLVDS_BIAS_PD_N = 1;
	SCRB->SYS_TLVDS_PD_N.tBit.A_TLVDS_PDB_TECLK0 = 1;
	SCRB->SYS_TLVDS_PD_N.tBit.A_TLVDS_PDB_TECLK1 = 1;
	SCRB->SYS_TLVDS_PD_N.tBit.A_TLVDS_PDB_TPWM0 = 1;
	SCRB->SYS_TLVDS_PD_N.tBit.A_TLVDS_PDB_TPWM1 = 1;
	SCRB->SYS_TLVDS_PD_N.tBit.A_TLVDS_DRV_TECLK0 = 1;
	SCRB->SYS_TLVDS_PD_N.tBit.A_TLVDS_DRV_TECLK1 = 1;
	SCRB->SYS_TLVDS_PD_N.tBit.A_TLVDS_DRV_TPWM0 = 1;
	SCRB->SYS_TLVDS_PD_N.tBit.A_TLVDS_DRV_TPWM1 = 1;

///////////////////////////////////////////////////////////////////////////////////////////

	//	Interval control register
	TLVDS->INTERVAL_CR.tBit.t1 = 5;
	TLVDS->INTERVAL_CR.tBit.t2 = 5;
	TLVDS->INTERVAL_CR.tBit.t2_1 = 1;
	TLVDS->INTERVAL_CR.tBit.t3 = 8; 	// minimum 8

	//	Start Address
	TLVDS->TX0_ST_ADDR = TLVDS_RAW_MEM_ADDRESS_TX0/sizeof(uint32_t);
	TLVDS->TX1_ST_ADDR = TLVDS_RAW_MEM_ADDRESS_TX1/sizeof(uint32_t);
	TLVDS->RX0_ST_ADDR = TLVDS_RAW_MEM_ADDRESS_RX0/sizeof(uint32_t);
	TLVDS->RX1_ST_ADDR = 0;
	TLVDS->RX2_ST_ADDR = TLVDS_RAW_MEM_ADDRESS_RX2/sizeof(uint32_t);
	TLVDS->RX3_ST_ADDR = 0;

	//	TLVDS control register #1
	TLVDS->TLVDS_CR1.tBit.checksum_en = 0;

	//	TLVDS control register #2
	TLVDS->TLVDS_CR2.tBit.tx_lsb_first_en = 0;	// 0: MSB first, 1: LSB first
	TLVDS->TLVDS_CR2.tBit.rx_lsb_first_en = 0;	// 0: MSB first, 1: LSB first
	TLVDS->TLVDS_CR2.tBit.header_len = 0; 		// 0: Address Header 16bits, 1: 24bits, 2: 32bits
	TLVDS->TLVDS_CR2.tBit.header_num = 1;		// Header number (default: 1)
	TLVDS->TLVDS_CR2.tBit.rdmy_len = 0;		// 0: 16bits, 1: 32bits
	TLVDS->TLVDS_CR2.tBit.wdmy_len = 0;		// 0: 16bits, 1: 32bits
	TLVDS->TLVDS_CR2.tBit.sense_done_sel = 0; 	// 0: RX0, 1: RX1, 2: RX2, 3: RX3
	TLVDS->TLVDS_CR2.tBit.wdata_len = 0; 		// 0: 16bits, 1: 12bits
	TLVDS->TLVDS_CR2.tBit.rdata_len = 2; 		// 0: 16bits, 1: 12bits, 2: 16bits, 3: 32bits
	TLVDS->TLVDS_CR2.tBit.tx_number = 1;		// The number of TX
	TLVDS->TLVDS_CR2.tBit.rx_number = 1;		// The number of RX
	TLVDS->TLVDS_CR2.tBit.tx0_on = 1;
	TLVDS->TLVDS_CR2.tBit.tx1_on = 1;
	TLVDS->TLVDS_CR2.tBit.rx0_on = 1;
	TLVDS->TLVDS_CR2.tBit.rx1_on = 0;
	TLVDS->TLVDS_CR2.tBit.rx2_on = 1;
	TLVDS->TLVDS_CR2.tBit.rx3_on = 0;

	TLVDS->TLVDS_DLY.tBit.trdy_smpl_dly = 0;	// Touch Ready sample delay (for filtering)
	TLVDS->TLVDS_DLY.tBit.mask_dly = 20;		// Unknown period mask period

	//	AFE_ON time control
	TLVDS->AFE_ON_TIME.tBit.off_time = 10;
	TLVDS->AFE_ON_TIME.tBit.drv_time = 10;
	TLVDS->AFE_ON_TIME.tBit.pdb_time = 10;

	TLVDS->TLVDS_CR3.tBit.sric_number = 5;
	TLVDS->TLVDS_CR3.tBit.buf_number = 4;
	TLVDS->TLVDS_CR3.tBit.mux_number = 10;

	//	TLVDS PHY power stuck control
	TLVDS->TLVDS_PHY_STUCK_CR.tBit.tcsn0_pdb = 1;
	TLVDS->TLVDS_PHY_STUCK_CR.tBit.tcsn1_pdb = 1;
	TLVDS->TLVDS_PHY_STUCK_CR.tBit.tcsn0_drv = 1;
	TLVDS->TLVDS_PHY_STUCK_CR.tBit.tcsn1_drv = 1;

	TLVDS->TLVDS_PHY_STUCK_CR.tBit.rdat0_pdb = 1;

	//	TLVDS PHY power stuck value
	TLVDS->TLVDS_PHY_STUCK_VALUE.tBit.tcsn0_pdb = 1;
	TLVDS->TLVDS_PHY_STUCK_VALUE.tBit.tcsn1_pdb = 1;
	TLVDS->TLVDS_PHY_STUCK_VALUE.tBit.tcsn0_drv = 1;
	TLVDS->TLVDS_PHY_STUCK_VALUE.tBit.tcsn1_drv = 1;

	TLVDS->TLVDS_PHY_STUCK_VALUE.tBit.rdat0_pdb = 1;

	//	Touch ready sample delay
	TLVDS->TLVDS_DLY.tBit.trdy_smpl_dly = 6;

	//	Frame interrupt index count
	TLVDS->TLVDS_FINDEX0.tBit.tlvds_findex0 = 9;
	TLVDS->TLVDS_FINDEX0.tBit.tlvds_findex1 = 9;
	TLVDS->TLVDS_FINDEX0.tBit.tlvds_findex2 = 9;
	TLVDS->TLVDS_FINDEX0.tBit.tlvds_findex3 = 9;
	TLVDS->TLVDS_FINDEX1.tBit.tlvds_findex4 = 9;
	TLVDS->TLVDS_FINDEX1.tBit.tlvds_findex5 = 9;
	TLVDS->TLVDS_FINDEX1.tBit.tlvds_findex6 = 9;
	TLVDS->TLVDS_FINDEX1.tBit.tlvds_findex7 = 9;

	Fncp_TLVDS_IRQHandler = TLVDS_InterruptHandler;
	NVIC_SetPriority(EXTInterface_IRQn, TLVDS_IRQn_Priority);
	NVIC_EnableIRQ(EXTInterface_IRQn);
}

void TLVDS_SetAitMode(void)
{
	//	AIT mode
	TLVDS->TLVDS_CR2.tBit.mem_addr_clr = 1;
	TLVDS->INT_EN.tBit.int_sric_ready_en = 1;
	TLVDS->INT_EN.tBit.int_sric_ready_mask_en = 1;
	TLVDS->INT_EN.tBit.int_fr_done_en= 1;
	TLVDS->TLVDS_CR2.tBit.ait_mode = 1;
}

void TLVDS_SetClock(void)
{
	if (1)	//	when using USb clock
	{
		SCRB->TLVDSCLK_CFG.tBit.tlvclkpre_sel = 1;			// 0: MainClk, 1: USB Clk
		SCRB->TLVDSCLK_CFG.tBit.tlvusbdiv = 5;				// USB clk div (USB clk / tlvusbdiv+1)
	}
	else	//	when using main clock
	{
		SCRB->TLVDSCLK_CFG.tBit.tlvplldiv = 0;//7;		// Use main clk pll, 0: 96MHz, 7: 12MHz
	}
}


#define SRIC_OFFSET_		(TLVDS_SRIC_NUM/2)
#define _TLVDS_REG_SRIC_MAX		(16)
#define _TLVDS_BULK_LEN			(TLVDS_SBUF_MAX_NODE * TLVDS_SBUF_MAX_CNT)
#define _TLVDS_READ_SET( mem_offset, slv_addr, multi, rd_161210b, cfgr_sbuf, roic_addr, reg_addr, rd_wr, bulk_single, transition, num_blk ) \
	*(uint16_t*)(BASE_RAW_SRAM + ((mem_offset)<<2)) = ((slv_addr)<<12) | ((multi)<<11) | (((rd_161210b)>>1)<<10) | ((cfgr_sbuf)<<9) | ((roic_addr)<<8) | ((reg_addr)<<0); \
	*(uint16_t*)(BASE_RAW_SRAM + ((mem_offset)<<2) + 4) = ((rd_wr)<<15) | ((bulk_single)<<14) | ((transition)<<13) | ((0x00)<<8) | (((rd_161210b)&1)<<7) | ((num_blk)<<0);
#define _TLVDS_MEM_GET_P( mem_offset, bulk_index ) \
	(uint16_t*)((uint16_t*)(BASE_RAW_SRAM + (mem_offset<<2) + 8) + bulk_index)

uint8_t _TLVDS_Read( uint8_t slv_addr, uint8_t r0_or_r1, uint8_t reg_or_buf, uint8_t reg_addr, uint16_t* p_reg1_val, uint16_t* p_reg2_val, uint16_t num_bulk )
{
	if( 0 == num_bulk )
		return 0;

	uint16_t rx0_mem_offset = TLVDS->RX0_ST_ADDR;
	uint16_t rx2_mem_offset = TLVDS->RX2_ST_ADDR;

	_TLVDS_READ_SET(
		rx0_mem_offset,			// TMCU memory word offset value
		slv_addr, 				// 0 ~ 15: sric addr
		_TLVDS_REG_MULTI_OFF,	// 0: multi disable, 1: multi enable
		_TLVDS_REG_16b_DATA,	// 0: 16 bits data, 1: 12 bits data
		reg_or_buf,				// 0: Configuration Register, 1: Sensing Data Buffer
		r0_or_r1,				// 0: ROIC0, 1: ROIC1
		reg_addr,				// SRIC register address (unit: byte)
		_TLVDS_REG_READ,		// 0: read, 1: write
		num_bulk>1 ? 0 : 1,		// 0: bulk, 1: single
		_TLVDS_REG_TRANSIT_ON,	// 0: transition disable(write), 1: transition enable(read)
		num_bulk				// bulk data number (unit: 2bytes)
	);

	_TLVDS_READ_SET(
		rx2_mem_offset,			// TMCU memory word offset value
		slv_addr/*(slv_addr + 1)*/, 				// 0 ~ 15: sric addr
		_TLVDS_REG_MULTI_OFF,	// 0: multi disable, 1: multi enable
		_TLVDS_REG_16b_DATA,	// 0: 16 bits data, 1: 12 bits data
		reg_or_buf,				// 0: Configuration Register, 1: Sensing Data Buffer
		r0_or_r1,				// 0: ROIC0, 1: ROIC1
		reg_addr,				// SRIC register address (unit: byte)
		_TLVDS_REG_READ,		// 0: read, 1: write
		num_bulk>1 ? 0 : 1,		// 0: bulk, 1: single
		_TLVDS_REG_TRANSIT_ON,	// 0: transition disable(write), 1: transition enable(read)
		num_bulk				// bulk data number (unit: 2bytes)
	);

	TLVDS->TLVDS_CR1.tBit.tx_en = _TLVDS_REG_READ;
	TLVDS->TLVDS_CR1.tBit.tr_en = _TLVDS_REG_TRANSIT_ON;
	TLVDS->TLVDS_CR1.tBit.bulk_en = 1; // always 1
	TLVDS->TLVDS_CR1.tBit.bulk_num = num_bulk;

	TLVDS->TLVDS_CR2.tBit.mem_addr_clr = 1;

	TLVDS->TLVDS_CTRL.tBit.mst_start = 1;

	while( TLVDS->TLVDS_STATUS.tBit.tlvds_fsm );

	int i, bulk;

	if( p_reg1_val )
	{
		i = 0;
		bulk = num_bulk;
		while( bulk-- ) {
			*(p_reg1_val+i) = *_TLVDS_MEM_GET_P(rx0_mem_offset, i);
			i++;
		}
	}

	if( p_reg2_val )
	{
		i = 0;
		bulk = num_bulk;
		while( bulk-- ) {
			*(p_reg2_val+i) = *_TLVDS_MEM_GET_P(rx2_mem_offset, i);
			i++;
		}
	}

	return i;
}

uint8_t _TLVDS_ReadRaw( uint8_t reg_addr, uint16_t num_bulk )
{

	if( 0 == num_bulk )
		return 0;

	uint16_t rx0_mem_offset, rx2_mem_offset;

	int i, j;

	for( i = 0 ; i < TLVDS_MUX_NUM ; i++ ) {
		for( j = 0 ; j < TLVDS_SRIC_NUM/2 ; j++ ) {

			rx0_mem_offset = (TLVDS_RAW_DATA_SET_PER_SRIC*j + TLVDS_RAW_DATA_SET_PER_SRIC*TLVDS_SRIC_NUM*i) / sizeof(uint32_t);

			_TLVDS_READ_SET(
				rx0_mem_offset,			// TMCU memory word offset value
				j, 						// 0 ~ 15: sric addr
				_TLVDS_REG_MULTI_OFF,	// 0: multi disable, 1: multi enable
				_TLVDS_REG_16b_DATA,	// 0: 16 bits data, 1: 12 bits data
				_TLVDS_REG_CONFIG_REG,	// 0: Configuration Register, 1: Sensing Data Buffer
				0,						// 0: ROIC0, 1: ROIC1
				reg_addr,				// SRIC register address (unit: byte)
				_TLVDS_REG_READ,		// 0: read, 1: write
				num_bulk>1 ? 0 : 1,		// 0: bulk, 1: single
				_TLVDS_REG_TRANSIT_ON,	// 0: transition disable(write), 1: transition enable(read)
				num_bulk				// bulk data number (unit: 2bytes)
			);

			rx2_mem_offset = (TLVDS_RAW_DATA_SET_PER_SRIC*j + TLVDS_RAW_DATA_SET_PER_SRIC*TLVDS_SRIC_NUM*i + TLVDS_RAW_DATA_SET_PER_SRIC*TLVDS_SRIC_NUM/2) / sizeof(uint32_t);

			_TLVDS_READ_SET(
				rx2_mem_offset,			// TMCU memory word offset value
				TLVDS_SRIC_NUM/2 + j, 	// 0 ~ 15: sric addr
				_TLVDS_REG_MULTI_OFF,	// 0: multi disable, 1: multi enable
				_TLVDS_REG_16b_DATA,	// 0: 16 bits data, 1: 12 bits data
				_TLVDS_REG_CONFIG_REG,	// 0: Configuration Register, 1: Sensing Data Buffer
				0,						// 0: ROIC0, 1: ROIC1
				reg_addr,				// SRIC register address (unit: byte)
				_TLVDS_REG_READ,		// 0: read, 1: write
				num_bulk>1 ? 0 : 1,		// 0: bulk, 1: single
				_TLVDS_REG_TRANSIT_ON,	// 0: transition disable(write), 1: transition enable(read)
				num_bulk				// bulk data number (unit: 2bytes)
			);
		}
	}

	TLVDS->TLVDS_CR1.tBit.tx_en = _TLVDS_REG_READ;
	TLVDS->TLVDS_CR1.tBit.tr_en = _TLVDS_REG_TRANSIT_ON;
	TLVDS->TLVDS_CR1.tBit.bulk_en = 1; // always 1
	TLVDS->TLVDS_CR1.tBit.bulk_num = num_bulk;

	TLVDS->TLVDS_CR2.tBit.mem_addr_clr = 1;

	TLVDS->TLVDS_CR2.tBit.ait_mode = 1;

	TLVDS->TLVDS_CTRL.tBit.mst_start = 1;
	while( TLVDS->TLVDS_STATUS.tBit.tlvds_fsm );

	return num_bulk;
}

#define _TLVDS_WRITE_SET( mem_offset, slv_addr, multi, rd_161210b, cfgr_sbuf, roic_addr, reg_addr, rd_wr, bulk_single, transition, num_blk ) \
	*(uint16_t*)(BASE_RAW_SRAM + (mem_offset<<2)) = (slv_addr<<12) | (multi<<11) | ((rd_161210b>>1)<<10) | (cfgr_sbuf<<9) | (roic_addr<<8) | (reg_addr<<0); \
	*(uint16_t*)(BASE_RAW_SRAM + (mem_offset<<2) + 4) = (rd_wr<<15) | (bulk_single<<14) | (transition<<13) | (0x00<<8) | ((rd_161210b&1)<<7) | (num_blk<<0);

uint8_t _TLVDS_Write( uint8_t slv_addr, uint8_t r0_or_r1, uint8_t reg_or_buf, uint8_t reg_addr, uint16_t* p_reg1_val, uint16_t* p_reg2_val, uint16_t num_bulk )
{

	if( 0 == num_bulk )
		return 0;

	uint16_t tx0_mem_offset = TLVDS->TX0_ST_ADDR;
	uint16_t tx1_mem_offset = TLVDS->TX1_ST_ADDR;

#if 1 // for debug
	memset( (void*)BASE_RAW_SRAM, 0x00, 32*1024 );
#endif

	_TLVDS_WRITE_SET(
		tx0_mem_offset,			// TMCU memory word offset value
		slv_addr, 				// 0 ~ 15: sric addr
		_TLVDS_REG_MULTI_OFF,	// 0: multi disable, 1: multi enable
		_TLVDS_REG_16b_DATA,	// 0: 16 bits data, 1: 12 bits data
		reg_or_buf,				// 0: Configuration Register, 1: Sensing Data Buffer
		r0_or_r1,				// 0: ROIC0, 1: ROIC1
		reg_addr,				// SRIC register address (unit: byte)
		_TLVDS_REG_WRITE,		// 0: read, 1: write
		num_bulk>1 ? 0 : 1,		// 0: bulk, 1: single
		_TLVDS_REG_TRANSIT_OFF,	// 0: transition disable(write), 1: transition enable(read)
		num_bulk				// bulk data number (unit: 2bytes)
	);

	_TLVDS_WRITE_SET(
		tx1_mem_offset,			// TMCU memory word offset value
		slv_addr/*(slv_addr + 1)*/, 				// 0 ~ 15: sric addr
		_TLVDS_REG_MULTI_OFF,	// 0: multi disable, 1: multi enable
		_TLVDS_REG_16b_DATA,	// 0: 16 bits data, 1: 12 bits data
		reg_or_buf,				// 0: Configuration Register, 1: Sensing Data Buffer
		r0_or_r1,				// 0: ROIC0, 1: ROIC1
		reg_addr,				// SRIC register address (unit: byte)
		_TLVDS_REG_WRITE,		// 0: read, 1: write
		num_bulk>1 ? 0 : 1,		// 0: bulk, 1: single
		_TLVDS_REG_TRANSIT_OFF,	// 0: transition disable(write), 1: transition enable(read)
		num_bulk				// bulk data number (unit: 2bytes)
	);

	int i, bulk;

	if( p_reg1_val ) {
		i = 0;
		bulk = num_bulk;
		while( bulk-- ) {
			*_TLVDS_MEM_GET_P(tx0_mem_offset, i) = *(p_reg1_val+i);
			i++;
		}
	}

	if( p_reg2_val ) {
		i = 0;
		bulk = num_bulk;
		while( bulk-- ) {
			*_TLVDS_MEM_GET_P(tx1_mem_offset, i) = *(p_reg2_val+i);
			i++;
		}
	}

	TLVDS->TLVDS_CR1.tBit.tx_en = _TLVDS_REG_WRITE;
	TLVDS->TLVDS_CR1.tBit.tr_en = _TLVDS_REG_TRANSIT_OFF;
	TLVDS->TLVDS_CR1.tBit.bulk_en = 1; // always 1
	TLVDS->TLVDS_CR1.tBit.bulk_num = num_bulk;

	TLVDS->TLVDS_CR2.tBit.mem_addr_clr = 1;

	TLVDS->TLVDS_CTRL.tBit.mst_start = 1;

	while( TLVDS->TLVDS_STATUS.tBit.tlvds_fsm );

	return num_bulk;
}

uint8_t _TLVDS_WriteMulti( uint8_t reg_or_buf, uint8_t reg_addr, uint16_t* p_reg1_val, uint16_t* p_reg2_val, uint16_t num_bulk )
{

	if( 0 == num_bulk )
		return 0;

	uint16_t tx0_mem_offset = TLVDS->TX0_ST_ADDR;
	uint16_t tx1_mem_offset = TLVDS->TX1_ST_ADDR;

	_TLVDS_WRITE_SET(
		tx0_mem_offset,			// TMCU memory word offset value
		_TLVDS_DONT_CARE,		// 0 ~ 15: sric addr
		_TLVDS_REG_MULTI_ON,	// 0: multi disable, 1: multi enable
		_TLVDS_REG_16b_DATA,	// 0: 16 bits data, 1: 12 bits data
		reg_or_buf,				// 0: Configuration Register, 1: Sensing Data Buffer
		_TLVDS_DONT_CARE,		// 0: ROIC0, 1: ROIC1
		reg_addr,				// SRIC register address (unit: byte)
		_TLVDS_REG_WRITE,		// 0: read, 1: write
		num_bulk>1 ? 0 : 1,		// 0: bulk, 1: single
		_TLVDS_REG_TRANSIT_OFF,	// 0: transition disable(write), 1: transition enable(read)
		num_bulk				// bulk data number (unit: 2bytes)
	);

	_TLVDS_WRITE_SET(
		tx1_mem_offset,			// TMCU memory word offset value
		_TLVDS_DONT_CARE,		// 0 ~ 15: sric addr
		_TLVDS_REG_MULTI_ON,	// 0: multi disable, 1: multi enable
		_TLVDS_REG_16b_DATA,	// 0: 16 bits data, 1: 12 bits data
		reg_or_buf,				// 0: Configuration Register, 1: Sensing Data Buffer
		_TLVDS_DONT_CARE,		// 0: ROIC0, 1: ROIC1
		reg_addr,				// SRIC register address (unit: byte)
		_TLVDS_REG_WRITE,		// 0: read, 1: write
		num_bulk>1 ? 0 : 1,		// 0: bulk, 1: single
		_TLVDS_REG_TRANSIT_OFF,	// 0: transition disable(write), 1: transition enable(read)
		num_bulk				// bulk data number (unit: 2bytes)
	);

	int i, bulk;

	if( p_reg1_val ) {
		i = 0;
		bulk = num_bulk;
		while( bulk-- ) {
			*_TLVDS_MEM_GET_P(tx0_mem_offset, i) = *(p_reg1_val+i);
			i++;
		}
	}

	if( p_reg2_val ) {
		i = 0;
		bulk = num_bulk;
		while( bulk-- ) {
			*_TLVDS_MEM_GET_P(tx1_mem_offset, i) = *(p_reg2_val+i);
			i++;
		}
	}

	TLVDS->TLVDS_CR1.tBit.tx_en = _TLVDS_REG_WRITE;
	TLVDS->TLVDS_CR1.tBit.tr_en = _TLVDS_REG_TRANSIT_OFF;
	TLVDS->TLVDS_CR1.tBit.bulk_en = 1; // always 1
	TLVDS->TLVDS_CR1.tBit.bulk_num = num_bulk;

	TLVDS->TLVDS_CR2.tBit.mem_addr_clr = 1;

	TLVDS->TLVDS_CTRL.tBit.mst_start = 1;

	while( TLVDS->TLVDS_STATUS.tBit.tlvds_fsm );

	return num_bulk;
}

void TLVDS_Read_RawData_CMD_Set(uint8_t _reg_addr, uint8_t _num_bulk)
{

	if( 0 == _num_bulk )
		return;

	uint16_t rx0_mem_offset, rx2_mem_offset;

	int i, j;

#if 1 // for debug
	memset( (void*)BASE_RAW_SRAM, 0x00, 32*1024 );
#endif

	for( i = 0 ; i < TLVDS_MUX_NUM ; i++ )
	{
		for( j = 0 ; j < TLVDS_SRIC_NUM/2 ; j++ )
		{
			rx0_mem_offset = (TLVDS_RAW_DATA_SET_PER_SRIC*j + TLVDS_RAW_DATA_MUX_OFFSET*i) / sizeof(uint32_t);

			_TLVDS_READ_SET(
				rx0_mem_offset,			// TMCU memory word offset value
				j, 						// 0 ~ 15: sric addr
				_TLVDS_REG_MULTI_OFF,	// 0: multi disable, 1: multi enable
				_TLVDS_REG_16b_DATA,	// 0: 16 bits data, 1: 12 bits data
				_TLVDS_REG_DATA_BUF,	// 0: Configuration Register, 1: Sensing Data Buffer
				0,						// 0: ROIC0, 1: ROIC1
				_reg_addr,				// SRIC register address (unit: byte)
				_TLVDS_REG_READ,		// 0: read, 1: write
				_num_bulk>1 ? 0 : 1,	// 0: bulk, 1: single
				_TLVDS_REG_TRANSIT_ON,	// 0: transition disable(write), 1: transition enable(read)
				_num_bulk				// bulk data number (unit: 2bytes)
			);

			rx2_mem_offset = (TLVDS_RAW_DATA_SET_PER_SRIC*j + TLVDS_RAW_DATA_MUX_OFFSET*i + TLVDS_RAW_DATA_RX_MEM_OFFSET) / sizeof(uint32_t);

			_TLVDS_READ_SET(
				rx2_mem_offset,			// TMCU memory word offset value
				j,					 	// 0 ~ 15: sric addr
				_TLVDS_REG_MULTI_OFF,	// 0: multi disable, 1: multi enable
				_TLVDS_REG_16b_DATA,	// 0: 16 bits data, 1: 12 bits data
				_TLVDS_REG_DATA_BUF,	// 0: Configuration Register, 1: Sensing Data Buffer
				0,						// 0: ROIC0, 1: ROIC1
				_reg_addr,				// SRIC register address (unit: byte)
				_TLVDS_REG_READ,		// 0: read, 1: write
				_num_bulk>1 ? 0 : 1,	// 0: bulk, 1: single
				_TLVDS_REG_TRANSIT_ON,	// 0: transition disable(write), 1: transition enable(read)
				_num_bulk				// bulk data number (unit: 2bytes)
			);
		}
	}

	TLVDS->TLVDS_CR1.tBit.tx_en = _TLVDS_REG_READ;
	TLVDS->TLVDS_CR1.tBit.tr_en = _TLVDS_REG_TRANSIT_ON;
	TLVDS->TLVDS_CR1.tBit.bulk_en = 1; // always 1
	TLVDS->TLVDS_CR1.tBit.bulk_num = _num_bulk;
}
#if USE_TLVDS_TEST
#define CFGR_PRODUCT_ID					(0x00)
#define CFGR_DIG_GAIN0					(0x1C)
#define CFGR_DUMMY						CFGR_DIG_GAIN0

#define TEST_COUNT						(0xFFFFFFFF)
static uint16_t temp1, temp2;

typedef struct {
	uint16_t R0_Val;
	uint16_t R1_Val;
} SRIC_REG_VAL_t;

SRIC_REG_VAL_t SRIC_REG_VAL[2/*ROIC NUM*/][TLVDS_SRIC_NUM/*SRIC NUM*/];

uint8_t TLVDS_test_read_productid(void)
{
	uint32_t test_count = 0;

	SCRB->SYS_DUMMY0 = 0;
	SCRB->SYS_DUMMY1 = 0;
	TIMER->SYS_DUMMY2 = 0;
	TIMER->SYS_DUMMY3 = 0;

	while( test_count < TEST_COUNT )
	{
		for(int i = 0 ; i < TLVDS_SRIC_NUM/2 ; i++ )
		{
			TLVDS_ReadRegSingle( i, 0, (uint8_t)CFGR_PRODUCT_ID, &temp1, &temp2 );

			if( temp1 != 0x8191 )
			{
				SCRB->SYS_DUMMY0 ++;
			}
			else {
				TIMER->SYS_DUMMY2 ++;
			}

			if( temp2 != 0x8191 ) {
				SCRB->SYS_DUMMY1 ++;
			}
			else {
				TIMER->SYS_DUMMY3 ++;
			}
		}
		test_count++;
	}

	return 0;
}

uint8_t TLVDS_test_rw_write_once_read_continue(void)
{
#define TEST_PTTRN1			(0xFEED)
#define TEST_PTTRN2			(0xBEEF)

	uint32_t test_count = 0;
	int i = 4;

	uint16_t tx1, tx2;
	uint16_t rx1, rx2;

	SCRB->SYS_DUMMY0 = 0;
	SCRB->SYS_DUMMY1 = 0;
	TIMER->SYS_DUMMY2 = 0;
	TIMER->SYS_DUMMY3 = 0;

	// Write
	tx1 = TEST_PTTRN1;
	tx2 = TEST_PTTRN2;
	TLVDS_WriteRegSingle( i, 0, CFGR_DUMMY, &tx1, &tx2 );

	while( test_count < TEST_COUNT )
	{
		// Read
		TLVDS_ReadRegSingle( i, 0, CFGR_DUMMY, &rx1, &rx2 );

		if( tx1 != rx1 )
			SCRB->SYS_DUMMY0 ++;
		else
			TIMER->SYS_DUMMY2 ++;

		if( tx2 != rx2 )
			SCRB->SYS_DUMMY1 ++;
		else
			TIMER->SYS_DUMMY3 ++;

		test_count++;
	}

	return 0;
}

uint8_t TLVDS_test_rw2_single_write_and_single_read(void)
{

	uint32_t test_count = 0;
	int i;

	uint16_t tx1, tx2;
	uint16_t rx1, rx2;

	SCRB->SYS_DUMMY0 = 0;
	SCRB->SYS_DUMMY1 = 0;
	TIMER->SYS_DUMMY2 = 0;
	TIMER->SYS_DUMMY3 = 0;
	GDMA->SYS_DUMMY4 = 0;
	GDMA->SYS_DUMMY5 = 0;

	while( test_count < TEST_COUNT ) {

		// Write
		for( i = 0 ; i < TLVDS_SRIC_NUM/2 ; i++ )
		{
			tx1 = rand() % 0xFFFF;
			tx2 = rand() % 0xFFFF;
			TLVDS_WriteRegSingle( i, 0, CFGR_DUMMY, &tx1, &tx2 );
			TLVDS_ReadRegSingle( i, 0, CFGR_DUMMY, &rx1, &rx2 );

			if( (tx1 != rx1) || (tx2 != rx2) )
			{
				switch( i )
				{
					case 0: SCRB->SYS_DUMMY0 ++; break;
					case 1: SCRB->SYS_DUMMY1 ++; break;
					case 2: TIMER->SYS_DUMMY2 ++; break;
					case 3: TIMER->SYS_DUMMY3 ++; break;
					case 4: GDMA->SYS_DUMMY4 ++; break;
					case 5: GDMA->SYS_DUMMY5 ++; break;
				}
			}

			medium_delay(1000);
		}

		test_count++;
	}

	return 0;
}

#define CNT_SBUF_PER_SRIC			(2)
#define NUM_BUF_PER_SRIC			(96)

static uint16_t tx1[NUM_BUF_PER_SRIC];
static uint16_t tx2[NUM_BUF_PER_SRIC];
static uint16_t rx1[NUM_BUF_PER_SRIC];
static uint16_t rx2[NUM_BUF_PER_SRIC];
static uint8_t cp1[NUM_BUF_PER_SRIC];
static uint8_t cp2[NUM_BUF_PER_SRIC];

uint8_t TLVDS_test_rw3_single_write_and_single_read(void)
{
	uint32_t test_count = 0;
	int i;
#define TEST_NUM	(4369)

	while( test_count < TEST_COUNT )
	{
		// Write
		for( i = 0 ; i < TLVDS_SRIC_NUM/2 ; i++ )
		{
//			tx1[i] = rand() % 0xFFFF;
//			tx2[i] = rand() % 0xFFFF;
			tx1[i] = (TEST_NUM * (i + 1)) % 0xFFFF;
			tx2[i] = (TEST_NUM * (i + 1)) % 0xFFFF;
			TLVDS_WriteRegSingle( i, 0, CFGR_DUMMY, &tx1[i], &tx2[i] );
		}

		// Read
		for( i = 0 ; i < TLVDS_SRIC_NUM/2 ; i++ )
		{
			TLVDS_ReadRegSingle( i, 0, CFGR_DUMMY, &rx1[i], &rx2[i] );
		}


		// Compare
		for( i = 0 ; i < TLVDS_SRIC_NUM/2 ; i++ )
		{
			SCRB->SYS_DUMMY1 = (tx2[i] << 16) | (0xFFFF & tx1[i]);
			TIMER->SYS_DUMMY2 = (rx2[i] << 16) | (0xFFFF & rx1[i]);
			SCRB->SYS_DUMMY0 = i;

//			if( tx1[i] != rx1[i] )
//				while(1); // ERROR occurred
//
//			if( tx2[i] != rx2[i] )
//				while(1); // ERROR occurred
		}

		test_count++;
	}

	return 0;
}

static uint16_t g_buf1_pttrn[NUM_BUF_PER_SRIC];
static uint16_t g_buf2_pttrn[NUM_BUF_PER_SRIC];

uint8_t TLVDS_test_sric_sram_write_pattern(void)
{
	uint8_t dev_id, roic_idx, buf_idx;
	uint8_t i;
	uint16_t test_val;

	for( i = 0 ; i < NUM_BUF_PER_SRIC ; i++ )
	{
		g_buf1_pttrn[i] = i+1;
		g_buf2_pttrn[i] = 1024 + i+1;
	}

	test_val = 0x1234;
	for( dev_id = 0; dev_id < TLVDS_SRIC_NUM/2; dev_id++ )
	{
		for( roic_idx = 0; roic_idx < 1; roic_idx ++ )
		{
			for( buf_idx = 0; buf_idx < 24; buf_idx++ )
			{
				//TLVDS_ReadRegSingle( dev_id, roic_idx, (uint16_t)SricRegisterInitTbl[reg_idx][0], &Read_1_SricValue[reg_idx], &Read_2_SricValue[reg_idx] );
				/*
				#define TLVDS_WriteBufBulk( slv_addr, r0_or_r1, reg_addr, p_reg1_val, p_reg2_val, bulk_num )
				*/
				//TLVDS_WriteBufBulk( dev_id, roic_idx, 0x00, &g_buf1_pttrn[0], &g_buf2_pttrn[0], NUM_BUF_PER_SRIC );
				/*
				#define TLVDS_WriteBufSingle( slv_addr, r0_or_r1, reg_addr, p_reg1_val, p_reg2_val )			_TLVDS_Write( slv_addr, r0_or_r1, _TLVDS_REG_DATA_BUF, reg_addr, p_reg1_val, p_reg2_val, 1 )
				*/
				TLVDS_WriteBufSingle( dev_id, roic_idx, buf_idx*2, &test_val, &test_val );
			}
		}
	}

	test_val = 0x0200;
	TLVDS_WriteRegSingleMulti( 0x4A, &test_val, &test_val ); // SRIC sram buffer update stop

	return 0;
}

uint8_t TLVDS_test_rw4_single_buf(void)
{

	uint32_t test_count = 0;
	int i;
	uint8_t dev_id, r0_or_r1, buf_addr;

	SCRB->SYS_DUMMY0 = 0;
	SCRB->SYS_DUMMY1 = 0;
	TIMER->SYS_DUMMY2 = 0;
	TIMER->SYS_DUMMY3 = 0;

	// Pattern Generate
	for( i = 0 ; i < NUM_BUF_PER_SRIC; i++ ) {
		tx1[i] = rand() % 0xFFFF;
		tx2[i] = rand() % 0xFFFF;
	}

	while( test_count < TEST_COUNT ) {

		dev_id = 0;
		i = 87;

		if( i < 24 ) {
			r0_or_r1 = 0;
			buf_addr = i * sizeof(uint16_t);
		}
		else if( i < 48 ) {
			r0_or_r1 = 0;
			buf_addr = (i-24) * sizeof(uint16_t) + 80;
		}
		else if( i < 72 ) {
			r0_or_r1 = 1;
			buf_addr = (i-48) * sizeof(uint16_t);
		}
		else {
			r0_or_r1 = 1;
			buf_addr = (i-72) * sizeof(uint16_t) + 80;
		}
	#if 1
		TLVDS_WriteBufSingle( dev_id, r0_or_r1, buf_addr, &tx1[i], &tx2[i] );
	#else
		TLVDS_WriteRegSingle( dev_id, r0_or_r1, CFGR_DUMMY, &tx1[i], &tx2[i] );
	#endif

		if( i < 24 ) {
			r0_or_r1 = 0;
			buf_addr = i * sizeof(uint16_t);
		}
		else if( i < 48 ) {
			r0_or_r1 = 0;
			buf_addr = (i-24) * sizeof(uint16_t) + 80;
		}
		else if( i < 72 ) {
			r0_or_r1 = 1;
			buf_addr = (i-48) * sizeof(uint16_t);
		}
		else {
			r0_or_r1 = 1;
			buf_addr = (i-72) * sizeof(uint16_t) + 80;
		}
	#if 1
		TLVDS_ReadBufSingle( dev_id, r0_or_r1, buf_addr, &rx1[i], &rx2[i] );
	#else
		TLVDS_ReadRegSingle( dev_id, r0_or_r1, CFGR_DUMMY, &rx1[i], &rx2[i] );
	#endif

		if( tx1[i] != rx1[i] ) {
			SCRB->SYS_DUMMY0 ++;
		}
		else {
			TIMER->SYS_DUMMY2 ++;
		}

		if( tx2[i] != rx2[i] ) {
			SCRB->SYS_DUMMY1 ++;
		}
		else {
			TIMER->SYS_DUMMY3 ++;
		}

		test_count++;
	}

	return 0;
}

uint8_t TLVDS_test_rw5_bulk_buf(void)
{

	uint32_t test_count = 0;
	int i, j;
	uint8_t dev_id, r0_or_r1, buf_addr;

	SCRB->SYS_DUMMY0 = 0;
	SCRB->SYS_DUMMY1 = 0;
	TIMER->SYS_DUMMY2 = 0;
	TIMER->SYS_DUMMY3 = 0;

	while( test_count < TEST_COUNT ) {

		// Pattern Generate
		for( i = 0 ; i < NUM_BUF_PER_SRIC; i++ ) {
			tx1[i] = rand() % 0xFFFF;
			tx2[i] = rand() % 0xFFFF;
			//tx1[i] = 0xFEED % 0xFFFF;
			//tx2[i] = 0xBEEF % 0xFFFF;
		}

		dev_id = 0;
		j = i = 0;
#if 0
		// Write
		TLVDS_WriteBufBulk( dev_id, 0, i, &tx1[0], &tx2[0], NUM_BUF_PER_SRIC );
#else
		for( i = 0 ; i < NUM_BUF_PER_SRIC ; i++ ) {
			if( i < 24 ) {
				r0_or_r1 = 0;
				buf_addr = i * sizeof(uint16_t);
			}
			else if( i < 48 ) {
				r0_or_r1 = 0;
				buf_addr = (i-24) * sizeof(uint16_t) + 80;
			}
			else if( i < 72 ) {
				r0_or_r1 = 1;
				buf_addr = (i-48) * sizeof(uint16_t);
			}
			else {
				r0_or_r1 = 1;
				buf_addr = (i-72) * sizeof(uint16_t) + 80;
			}
			TLVDS_WriteBufSingle( dev_id, r0_or_r1, buf_addr, &tx1[i], &tx2[i] );
		}
#endif

#if 1
		// Read
		TLVDS_ReadBufBulk( dev_id, 0, 0x00, &rx1[0], &rx2[0], NUM_BUF_PER_SRIC );
#else
		for( i = 0 ; i < NUM_BUF_PER_SRIC ; i++ ) {
			if( i < 24 ) {
				r0_or_r1 = 0;
				buf_addr = i * sizeof(uint16_t);
			}
			else if( i < 48 ) {
				r0_or_r1 = 0;
				buf_addr = (i-24) * sizeof(uint16_t) + 80;
			}
			else if( i < 72 ) {
				r0_or_r1 = 1;
				buf_addr = (i-48) * sizeof(uint16_t);
			}
			else {
				r0_or_r1 = 1;
				buf_addr = (i-72) * sizeof(uint16_t) + 80;
			}
			TLVDS_ReadBufSingle( dev_id, r0_or_r1, buf_addr, &rx1[i], &rx2[i] );
		}
#endif

		// Compare
		for( i = 0 ; i < NUM_BUF_PER_SRIC ; i++ ) {

			if( tx1[i] != rx1[i] ) {
				SCRB->SYS_DUMMY0 ++;
				cp1[i] = 1;
			}
			else {
				TIMER->SYS_DUMMY2 ++;
				cp1[i] = 0;
			}

			if( tx2[i] != rx2[i] ) {
				SCRB->SYS_DUMMY1 ++;
				cp2[i] = 1;
			}
			else {
				TIMER->SYS_DUMMY3 ++;
				cp2[i] = 0;
			}
		}

		test_count++;
	}

	return 0;
}

uint8_t g_bulk_reg1[0x100];
uint8_t g_bulk_reg2[0x100];

uint8_t TLVDS_test_rw6_bulk_reg(void)
{
//	uint32_t test_count = 0;
//	int i, j, reg_idx;
//	uint8_t dev_id, r0_or_r1, addr;
//	uint16_t val;
//
//	SCRB->SYS_DUMMY0 = 0;
//	SCRB->SYS_DUMMY1 = 0;
//	TIMER->SYS_DUMMY2 = 0;
//	TIMER->SYS_DUMMY3 = 0;
//
//	dev_id = 0;
//	while( test_count < TEST_COUNT )
//	{
//		//for( dev_id = 0 ; dev_id < TLVDS_SRIC_NUM/2 ; dev_id++ ) {
//
//			// Read
//			TLVDS_ReadRegBulk( dev_id, 0, 0x00, (uint16_t*)&g_bulk_reg1[0], (uint16_t*)&g_bulk_reg2[0], 0x100/2 );
//
//			// Compare
//			for( reg_idx = 0 ; reg_idx < LibSricSetupNum ; reg_idx++ ) {
//				addr = (uint8_t)SricRegisterInitTbl[reg_idx][0];
//				val = (uint16_t)SricRegisterInitTbl[reg_idx][1];
//
//				if( val != *(uint16_t*)&g_bulk_reg1[addr] )
//					SCRB->SYS_DUMMY0 ++;
//				else
//					TIMER->SYS_DUMMY2 ++;
//
//				if( val != *(uint16_t*)&g_bulk_reg2[addr] )
//					SCRB->SYS_DUMMY1 ++;
//				else
//					TIMER->SYS_DUMMY3 ++;
//			}
//		//}
//
//		test_count++;
//	}

	return 0;
}

uint32_t TLVDS_Write_Read_Test(void)
{
	uint32_t test_count, vulFailCnt[TLVDS_SRIC_NUM] = {0, }, ulFailCnt;
	int i;

	uint16_t tx1, tx2;
	uint16_t rx1, rx2;

	test_count = ulFailCnt = 0;

	while( test_count < 10000/*TEST_COUNT*/ )
	{
//		for( i = 0 ; i < TLVDS_SRIC_NUM; i+=2 )
		for( i = 0 ; i < TLVDS_SRIC_NUM/2; i++ )
		{
			tx1 = rand() % 0xFFFF;
			tx2 = rand() % 0xFFFF;
			TLVDS_WriteRegSingle(i, 0, CFGR_DUMMY, &tx1, &tx2);
			TLVDS_ReadRegSingle(i, 0, CFGR_DUMMY, &rx1, &rx2);

			if(tx1 != rx1)
				vulFailCnt[i*2]++;;
			if (tx2 != rx2)
				vulFailCnt[i*2+1]++;

			medium_delay(1000);
			rx1 = rx2 = 0;
		}

		test_count++;
	}

	for( i = 0 ; i < TLVDS_SRIC_NUM; i++ )
		ulFailCnt += vulFailCnt[i];

	return ulFailCnt;
}

/*
#define TLVDS_ReadRegSingle( slv_addr, r0_or_r1, reg_addr, p_reg1_val, p_reg2_val )
*/
uint32_t TLVDS_test_read_status(uint8_t reg_addr)
{
	uint16_t reg1, reg2;

	TLVDS_ReadRegSingle( 5, 0, reg_addr, &reg1, &reg2 );

	//return (reg2<<16 | reg1);
	return (reg2);
}

void TLVDS_test_read_reg_val(uint8_t _RegAddr)
{
	int dev_id, roic_idx;

	memset((void*)SRIC_REG_VAL, 0, sizeof(SRIC_REG_VAL));

	for( dev_id = 0 ; dev_id < TLVDS_SRIC_NUM/2 ; dev_id++ )
	{
		for( roic_idx = 0 ; roic_idx < 2 ; roic_idx ++ )
		{
			TLVDS_ReadRegSingle( dev_id, roic_idx, _RegAddr, &SRIC_REG_VAL[roic_idx][dev_id].R0_Val, &SRIC_REG_VAL[roic_idx][dev_id+SRIC_OFFSET_].R1_Val);
		}
	}
}


#endif
