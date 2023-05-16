/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : tlvds.h
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

#ifndef _TLVDS_H_
#define _TLVDS_H_


#define TLVDS_SRIC_NUM					(12)
#define TLVDS_MUX_NUM					(10)

#define TLVDS_RAW_ROW					(40)
#define TLVDS_RAW_COL					(144)
#define TLVDS_RAW_NODE_SIZE				(sizeof(uint16_t))
#define TLVDS_RAW_DATA_SIZE				(TLVDS_RAW_ROW * TLVDS_RAW_COL * TLVDS_RAW_NODE_SIZE)

#define TLVDS_RAW_MEM_MAX_SIZE			(32 * 1024) // 32KB // 0x2004_0000 ~ 0x2004_7FFC

#define TLVDS_SBUF_MAX_CNT				(2)			// ROIC num
#define TLVDS_SBUF_MAX_NODE				(24)		// data num per ROIC

#define TLVDS_RAW_DATA_ADDR				4																			//	4 byte
#define TLVDS_RAW_DATA_CMD				4																			//	4 byte
#define TLVDS_RAW_NODE_MAX_PER_SRIC		(TLVDS_SBUF_MAX_NODE * TLVDS_SBUF_MAX_CNT)									//	48
#define TLVDS_RAW_DATA_MAX_PER_SRIC		(TLVDS_RAW_NODE_MAX_PER_SRIC * TLVDS_RAW_NODE_SIZE)							//	96 byte
#define TLVDS_RAW_DATA_SET_PER_SRIC		(TLVDS_RAW_DATA_ADDR + TLVDS_RAW_DATA_CMD + TLVDS_RAW_DATA_MAX_PER_SRIC)	//	104 byte
#define TLVDS_SRIC_NUM_PER_TX			(TLVDS_SRIC_NUM / 2)														//	6
#define TLVDS_RAW_DATA_MUX_OFFSET		(TLVDS_RAW_DATA_SET_PER_SRIC * TLVDS_SRIC_NUM_PER_TX)						//	624 byte
#define TLVDS_RAW_DATA_RX_MEM_OFFSET	(TLVDS_RAW_DATA_MUX_OFFSET * TLVDS_MUX_NUM)									//	6240 byte

#define TLVDS_RAW_DATA_MAX_PER_SBUF		(TLVDS_SBUF_MAX_NODE * TLVDS_RAW_NODE_SIZE)
//#define TLVDS_RAW_MUX_MAX_PER_SRIC		(

#define TLVDS_RAW_MEM_ADDRESS_RX0		(0x0)																		// 0x2004_0000
#define TLVDS_RAW_MEM_ADDRESS_RX2		(TLVDS_RAW_DATA_RX_MEM_OFFSET)												// 0x2004_1860
#define TLVDS_RAW_MEM_ADDRESS_TX0		(TLVDS_RAW_MEM_ADDRESS_RX0)
#define TLVDS_RAW_MEM_ADDRESS_TX1		(TLVDS_RAW_MEM_ADDRESS_RX2)

#define _TLVDS_REG_MULTI_OFF			(0)
#define _TLVDS_REG_MULTI_ON				(1)
#define _TLVDS_REG_READ 				(0)
#define _TLVDS_REG_WRITE				(1)
#define _TLVDS_REG_16b_DATA				(0)
#define _TLVDS_REG_12b_DATA				(2)
#define _TLVDS_REG_10b_DATA				(3)
#define _TLVDS_REG_CONFIG_REG			(0)
#define _TLVDS_REG_DATA_BUF				(1)
#define _TLVDS_REG_TRANSIT_OFF			(0)
#define _TLVDS_REG_TRANSIT_ON			(1)
#define _TLVDS_DONT_CARE				(0)

extern void TLVDS_InterruptHandler(void);
extern void TLVDS_Initialize(void);
extern void TLVDS_SetAitMode(void);
extern void TLVDS_SetClock(void);


uint8_t _TLVDS_Read( uint8_t slv_addr, uint8_t r0_or_r1, uint8_t reg_or_buf, uint8_t reg_addr, uint16_t* p_reg1_val, uint16_t* p_reg2_val, uint16_t num_bulk );

#define TLVDS_ReadRegSingle( slv_addr, r0_or_r1, reg_addr, p_reg1_val, p_reg2_val )				_TLVDS_Read( slv_addr, r0_or_r1, _TLVDS_REG_CONFIG_REG, reg_addr, p_reg1_val, p_reg2_val, 1 )
#define TLVDS_ReadRegBulk( slv_addr, r0_or_r1, reg_addr, p_reg1_val, p_reg2_val, bulk_num )		_TLVDS_Read( slv_addr, r0_or_r1, _TLVDS_REG_CONFIG_REG, reg_addr, p_reg1_val, p_reg2_val, bulk_num )
#define TLVDS_ReadBufSingle( slv_addr, r0_or_r1, reg_addr, p_reg1_val, p_reg2_val )				_TLVDS_Read( slv_addr, r0_or_r1, _TLVDS_REG_DATA_BUF, reg_addr, p_reg1_val, p_reg2_val, 1 )
#define TLVDS_ReadBufBulk( slv_addr, r0_or_r1, reg_addr, p_reg1_val, p_reg2_val, bulk_num )		_TLVDS_Read( slv_addr, r0_or_r1, _TLVDS_REG_DATA_BUF, reg_addr, p_reg1_val, p_reg2_val, bulk_num )

uint8_t _TLVDS_ReadRaw( uint8_t reg_addr, uint16_t num_bulk );
extern void TLVDS_Read_RawData_CMD_Set(uint8_t _reg_addr, uint8_t _num_bulk);

#define TLVDS_ReadRawSingle( reg_addr, num_bulk )												_TLVDS_ReadRaw( reg_addr, num_bulk )

uint8_t _TLVDS_Write( uint8_t slv_addr, uint8_t r0_or_r1, uint8_t reg_or_buf, uint8_t reg_addr, uint16_t* p_reg1_val, uint16_t* p_reg2_val, uint16_t num_bulk );

#define TLVDS_WriteRegSingle( slv_addr, r0_or_r1, reg_addr, p_reg1_val, p_reg2_val )			_TLVDS_Write( slv_addr, r0_or_r1, _TLVDS_REG_CONFIG_REG, reg_addr, p_reg1_val, p_reg2_val, 1 )
#define TLVDS_WriteBufSingle( slv_addr, r0_or_r1, reg_addr, p_reg1_val, p_reg2_val )			_TLVDS_Write( slv_addr, r0_or_r1, _TLVDS_REG_DATA_BUF, reg_addr, p_reg1_val, p_reg2_val, 1 )
#define TLVDS_WriteBufBulk( slv_addr, r0_or_r1, reg_addr, p_reg1_val, p_reg2_val, bulk_num )	_TLVDS_Write( slv_addr, r0_or_r1, _TLVDS_REG_DATA_BUF, reg_addr, p_reg1_val, p_reg2_val, bulk_num )

uint8_t _TLVDS_WriteMulti( uint8_t reg_or_buf, uint8_t reg_addr, uint16_t* p_reg1_val, uint16_t* p_reg2_val, uint16_t num_bulk );

#define TLVDS_WriteRegSingleMulti( reg_addr, p_reg1_val, p_reg2_val )							_TLVDS_WriteMulti( _TLVDS_REG_CONFIG_REG, reg_addr, p_reg1_val, p_reg2_val, 1 )
#define TLVDS_WriteBufSingleMulti( reg_addr, p_reg1_val, p_reg2_val )							_TLVDS_WriteMulti( _TLVDS_REG_DATA_BUF, reg_addr, p_reg1_val, p_reg2_val, 1 )

#if USE_TLVDS_TEST
extern uint8_t TLVDS_test_read_productid(void);
extern uint8_t TLVDS_test_rw_write_once_read_continue(void);
extern uint8_t TLVDS_test_rw2_single_write_and_single_read(void);
extern uint8_t TLVDS_test_rw3_single_write_and_single_read(void);
extern uint8_t TLVDS_test_rw4_single_buf(void);
extern uint8_t TLVDS_test_rw5_bulk_buf(void);
extern uint8_t TLVDS_test_rw6_bulk_reg(void);
extern uint32_t TLVDS_Write_Read_Test(void);
extern void TLVDS_test_read_reg_val(uint8_t _RegAddr);
extern uint8_t TLVDS_test_sric_sram_write_pattern(void);
#endif


#endif /* _TLVDS_H_ */
