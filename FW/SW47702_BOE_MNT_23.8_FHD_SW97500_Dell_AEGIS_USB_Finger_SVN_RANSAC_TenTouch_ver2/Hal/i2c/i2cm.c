/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : i2cm.c
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

#include "hal_def.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// I2C Register

void I2CM_Initialize(void)
{
	GPIO_Set_Mode(_GPIO_MST_SCL, GPIO_MODE_FUNC_1);
	GPIO_Set_Mode(_GPIO_MST_SDA, GPIO_MODE_FUNC_1);

	I2CM->I2C_MST_CR1.tBit.I2cMstClkDiv = (96000/400);	//(system clock / i2c target speed)
	I2CM->I2C_MST_DBG.tBit.I2cMstTrLen = 5;

	I2CM->I2C_FIFO_CR.tBit.TxFifoInit = 1;
	I2CM->I2C_FIFO_CR.tBit.RxFifoInit = 1;

	SCRB->SERIAL_CLK_DIV.tBit.i2cm0_div = 0;
	SCRB->SYS_CLK_CTL.tBit.i2cm0clk_en = 1;		// I2CM0 clock enable
	SCRB->SYS_RST_CTL.tBit.i2cm_rst = 0;		// I2CM0 reset

//	I2CM->I2C_DEVICE_ADDR.tBit.I2cId = TPIC_I2C_ADDR;//I2C_ADDRESS;
	I2CM->I2C_SW_RESET.tBit.I2cSWReset = 1;
//	I2CM->I2C_DEVICE_ADDR.tBit.I2cId = TPIC_I2C_ADDR;//I2C_ADDRESS;
}

void I2CM_SendByte(uint8_t ulSlaveAddr, uint8_t *data, uint16_t length)
{
	uint32_t i = 0;

	I2CM->I2C_MST_CR2.ulBulk = 0 | (1 << I2C_MST_STR) | (ulSlaveAddr << I2C_MST_DATA_TR);

	while(I2CM->I2C_GLB_SR.tBit.I2cPacketEn);

	for(i = 0; i < length; i++)
	{
		if(i == length-1)
			I2CM->I2C_MST_CR2.ulBulk = 0 | (1<<I2C_MST_STOP) | (data[i]<<I2C_MST_DATA_TR);
		else
			I2CM->I2C_MST_CR2.ulBulk = 0 | (data[i]<<I2C_MST_DATA_TR);

		while(I2CM->I2C_GLB_SR.tBit.I2cPacketEn);
	}
	I2CM->I2C_GLB_SR.tBit.I2C_ITRPT = 0;
}

void I2CM_RcvByte(uint8_t ulSlaveAddr, uint8_t addr, uint8_t *data, uint32_t length)
{
	uint32_t i = 0;

	I2CM->I2C_MST_CR2.ulBulk = 0 | (1 << I2C_MST_STR) | (ulSlaveAddr << I2C_MST_DATA_TR);

	while(I2CM->I2C_GLB_SR.tBit.I2cPacketEn);

	I2CM->I2C_MST_CR2.ulBulk = 0 | (addr<<I2C_MST_DATA_TR);

	while(I2CM->I2C_GLB_SR.tBit.I2cPacketEn);

	I2CM->I2C_MST_CR2.ulBulk = 0 | (1 << I2C_MST_STR) | ((ulSlaveAddr | 0x1) << I2C_MST_DATA_TR);

	while(I2CM->I2C_GLB_SR.tBit.I2cPacketEn);

	for(i = 0; i < length; i++)
	{
		if(i == length-1)
			I2CM->I2C_MST_CR2.ulBulk = 0 | (1 << I2C_MST_STOP) | (1 << I2C_MST_RCV_MODE) | (1 << I2C_MST_NACK_TR);
		else
			I2CM->I2C_MST_CR2.ulBulk = 0 | (1 << I2C_MST_RCV_MODE);

		while(I2CM->I2C_GLB_SR.tBit.I2cPacketEn);
		data[i] = I2CM->I2C_GLB_SR.tBit.I2cMstDataRcv;
	}
}
