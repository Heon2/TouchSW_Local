/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : i2cm.h
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

#ifndef _I2CM_H_
#define _I2CM_H_


#define I2CM			(I2C_1)

#define I2C_MST_NACK_TR			(11)
#define I2C_MST_RCV_MODE		(10)
#define I2C_MST_STOP			(9)
#define I2C_MST_STR				(8)
#define I2C_MST_DATA_TR			(0)

#if USED_TPIC_VCOM_LEVEL_I2CM_CONTROL
#define TPIC_CTRL_I2C_SLAVE_ADDR				(0x54)
#define TPIC_VCOM_H_ADDR						(0x01)
#define TPIC_VCOM_L_ADDR						(0x02)
#define TPIC_VGL1_H_ADDR						(0x03)
#define TPIC_VGL2_H_ADDR						(0x04)

typedef enum
{
	VCOM_H_V_4v		= 0,
	VCOM_H_V_4_2v	= 1,
	VCOM_H_V_4_4v	= 2,
	VCOM_H_V_4_6v	= 3,
	VCOM_H_V_4_8v	= 4,
	VCOM_H_V_5v		= 5,
	VCOM_H_V_5_2v	= 6,
	VCOM_H_V_5_4v	= 7,
	VCOM_H_V_5_6v	= 8,
	VCOM_H_V_5_8v	= 9,
	VCOM_H_V_6v		= 10,
	VCOM_H_V_6_2v	= 11,
	VCOM_H_V_6_4v	= 12,
	VCOM_H_V_6_6v	= 13,
	VCOM_H_V_6_8v	= 14,
	VCOM_H_V_7v		= 15,
	VCOM_H_V_7_2v	= 16,
	VCOM_H_V_7_4v	= 17,
	VCOM_H_V_7_6v	= 18,
	VCOM_H_V_7_8v	= 19,
	VCOM_H_V_8v		= 20,
	VCOM_H_V_8_2v	= 21,
	VCOM_H_V_8_4v	= 22,
	VCOM_H_V_8_6v	= 23,
	VCOM_H_V_8_8v	= 24,
	VCOM_H_V_9v		= 25,
	VCOM_H_V_9_2v	= 26,
	VCOM_H_V_9_4v	= 27,
	VCOM_H_V_9_6v	= 28,
	VCOM_H_V_9_8v	= 29,
	VCOM_H_V_10v	= 30,
	VCOM_H_V_10_2v	= 31,

	VCOM_H_V_LIMIT	= 0xFF

} eTPIC_VCOM_H_t;

typedef enum
{
	VCOM_L_V_1v		= 0,
	VCOM_L_V_1_2v	= 1,
	VCOM_L_V_1_4v	= 2,
	VCOM_L_V_1_6v	= 3,
	VCOM_L_V_1_8v	= 4,
	VCOM_L_V_2v		= 5,
	VCOM_L_V_2_2v	= 6,
	VCOM_L_V_2_4v	= 7,
	VCOM_L_V_2_6v	= 8,
	VCOM_L_V_2_8v	= 9,
	VCOM_L_V_3v		= 10,
	VCOM_L_V_3_2v	= 11,
	VCOM_L_V_3_4v	= 12,
	VCOM_L_V_3_6v	= 13,
	VCOM_L_V_3_8v	= 14,
	VCOM_L_V_4v		= 15,
	VCOM_L_V_4_2v	= 16,
	VCOM_L_V_4_4v	= 17,
	VCOM_L_V_4_6v	= 18,
	VCOM_L_V_4_8v	= 19,
	VCOM_L_V_5v		= 20,
	VCOM_L_V_5_2v	= 21,
	VCOM_L_V_5_4v	= 22,
	VCOM_L_V_5_6v	= 23,
	VCOM_L_V_5_8v	= 24,
	VCOM_L_V_6v		= 25,
	VCOM_L_V_6_2v	= 26,
	VCOM_L_V_6_4v	= 27,
	VCOM_L_V_6_6v	= 28,
	VCOM_L_V_6_8v	= 29,
	VCOM_L_V_7v		= 30,
	VCOM_L_V_7_2v	= 31,

	VCOM_L_V_LIMIT	= 0xFF

} eTPIC_VCOM_L_t;

typedef enum
{
	VGL1_H_V_minus_1v		= 0,
	VGL1_H_V_minus_1_2v		= 1,
	VGL1_H_V_minus_1_4v		= 2,
	VGL1_H_V_minus_1_6v		= 3,
	VGL1_H_V_minus_1_8v		= 4,
	VGL1_H_V_minus_2v		= 5,
	VGL1_H_V_minus_2_2v		= 6,
	VGL1_H_V_minus_2_4v		= 7,
	VGL1_H_V_minus_2_6v		= 8,
	VGL1_H_V_minus_2_8v		= 9,
	VGL1_H_V_minus_3v		= 10,
	VGL1_H_V_minus_3_2v		= 11,
	VGL1_H_V_minus_3_4v		= 12,
	VGL1_H_V_minus_3_6v		= 13,
	VGL1_H_V_minus_3_8v		= 14,
	VGL1_H_V_minus_4v		= 15,
	VGL1_H_V_minus_4_2v		= 16,
	VGL1_H_V_minus_4_4v		= 17,
	VGL1_H_V_minus_4_6v		= 18,
	VGL1_H_V_minus_4_8v		= 19,
	VGL1_H_V_minus_5v		= 20,
	VGL1_H_V_minus_5_2v		= 21,
	VGL1_H_V_minus_5_4v		= 22,
	VGL1_H_V_minus_5_6v		= 23,
	VGL1_H_V_minus_5_8v		= 24,
	VGL1_H_V_minus_6v		= 25,
	VGL1_H_V_minus_6_2v		= 26,
	VGL1_H_V_minus_6_4v		= 27,
	VGL1_H_V_minus_6_6v		= 28,
	VGL1_H_V_minus_6_8v		= 29,
	VGL1_H_V_minus_7v		= 30,
	VGL1_H_V_minus_7_2v		= 31,
	VGL1_H_V_minus_7_4v		= 32,
	VGL1_H_V_minus_7_6v		= 33,
	VGL1_H_V_minus_7_8v		= 34,
	VGL1_H_V_minus_8v		= 35,
	VGL1_H_V_minus_8_2v		= 36,
	VGL1_H_V_minus_8_4v		= 37,
	VGL1_H_V_minus_8_6v		= 38,
	VGL1_H_V_minus_8_8v		= 39,
	VGL1_H_V_minus_9v		= 40,
	VGL1_H_V_minus_9_2v		= 41,
	VGL1_H_V_minus_9_4v		= 42,
	VGL1_H_V_minus_9_6v		= 43,
	VGL1_H_V_minus_9_8v		= 44,
	VGL1_H_V_minus_10v		= 45,
	VGL1_H_V_minus_10_2v	= 46,
	VGL1_H_V_minus_10_4v	= 47,
	VGL1_H_V_minus_10_6v	= 48,
	VGL1_H_V_minus_10_8v	= 49,
	VGL1_H_V_minus_11v		= 50,

	VGL1_H_V_LIMIT	= 0xFF

} eTPIC_VGL1_H_t;

typedef enum
{
	VGL2_H_V_minus_2v		= 0,
	VGL2_H_V_minus_2_2v		= 1,
	VGL2_H_V_minus_2_4v		= 2,
	VGL2_H_V_minus_2_6v		= 3,
	VGL2_H_V_minus_2_8v		= 4,
	VGL2_H_V_minus_3v		= 5,
	VGL2_H_V_minus_3_2v		= 6,
	VGL2_H_V_minus_3_4v		= 7,
	VGL2_H_V_minus_3_6v		= 8,
	VGL2_H_V_minus_3_8v		= 9,
	VGL2_H_V_minus_4v		= 10,
	VGL2_H_V_minus_4_2v		= 11,
	VGL2_H_V_minus_4_4v		= 12,
	VGL2_H_V_minus_4_6v		= 13,
	VGL2_H_V_minus_4_8v		= 14,
	VGL2_H_V_minus_5v		= 15,
	VGL2_H_V_minus_5_2v		= 16,
	VGL2_H_V_minus_5_4v		= 17,
	VGL2_H_V_minus_5_6v		= 18,
	VGL2_H_V_minus_5_8v		= 19,
	VGL2_H_V_minus_6v		= 20,
	VGL2_H_V_minus_6_2v		= 21,
	VGL2_H_V_minus_6_4v		= 22,
	VGL2_H_V_minus_6_6v		= 23,
	VGL2_H_V_minus_6_8v		= 24,
	VGL2_H_V_minus_7v		= 25,
	VGL2_H_V_minus_7_2v		= 26,
	VGL2_H_V_minus_7_4v		= 27,
	VGL2_H_V_minus_7_6v		= 28,
	VGL2_H_V_minus_7_8v		= 29,
	VGL2_H_V_minus_8v		= 30,
	VGL2_H_V_minus_8_2v		= 31,
	VGL2_H_V_minus_8_4v		= 32,
	VGL2_H_V_minus_8_6v		= 33,
	VGL2_H_V_minus_8_8v		= 34,
	VGL2_H_V_minus_9v		= 35,
	VGL2_H_V_minus_9_2v		= 36,
	VGL2_H_V_minus_9_4v		= 37,
	VGL2_H_V_minus_9_6v		= 38,
	VGL2_H_V_minus_9_8v		= 39,
	VGL2_H_V_minus_10v		= 40,
	VGL2_H_V_minus_10_2v	= 41,
	VGL2_H_V_minus_10_4v	= 42,
	VGL2_H_V_minus_10_6v	= 43,
	VGL2_H_V_minus_10_8v	= 44,
	VGL2_H_V_minus_11v		= 45,
	VGL2_H_V_minus_11_2v	= 46,
	VGL2_H_V_minus_11_4v	= 47,
	VGL2_H_V_minus_11_6v	= 48,
	VGL2_H_V_minus_11_8v	= 49,
	VGL2_H_V_minus_12v		= 50,
	VGL2_H_V_minus_12_2v	= 51,
	VGL2_H_V_minus_12_4v	= 52,
	VGL2_H_V_minus_12_6v	= 53,
	VGL2_H_V_minus_12_8v	= 54,
	VGL2_H_V_minus_13v		= 55,

	VGL2_H_V_LIMIT	= 0xFF

} eTPIC_VGL2_H_t;

#endif /* USED_TPIC_VCOM_LEVEL_I2CM_CONTROL */


extern void I2CM_Initialize(void);
extern void I2CM_SendByte(uint8_t ulSlaveAddr, uint8_t *data, uint16_t length);
extern void I2CM_RcvByte(uint8_t ulSlaveAddr, uint8_t addr, uint8_t *data, uint32_t length);


#endif /* _I2CM_H_ */

