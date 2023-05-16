/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : dbgserial.c
 * created on : 05. 9. 2018
 * Author : kimjw
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
#include "module_def.h"


void DBG_I2C_InterruptHandler(void)
{
}

void DBG_SPI_InterruptHandler(void)
{
}

void DBGSERIAL_Initialize(void)
{
	Fncp_DBG_I2C_IRQHandler = DBG_I2C_InterruptHandler;
	NVIC_SetPriority(DBG_I2C_IRQn, DBG_I2C_IRQn_Priority);
	NVIC_EnableIRQ(DBG_I2C_IRQn);

	Fncp_DBG_SPI_IRQHandler = DBG_SPI_InterruptHandler;
	NVIC_SetPriority(DBG_SPI_IRQn, DBG_SPI_IRQn_Priority);
	NVIC_EnableIRQ(DBG_SPI_IRQn);

	DBGSERIAL->SERIAL_ENDIAN_SEL	= DBG_I2C_ENDIAN;

    DBGSERIAL->SERIAL_CTL.ulBulk    = (DBG_I2C_EN)|		// I2C enable
                                      (DBG_SPI_EN<<1);	// SPI enable

    DBGSERIAL->SERIAL_CFG.ulBulk    = (0<<0)|					// I2C deglitch length
    								  (DBG_I2C_SCL_DLY<<3)|		// SCL delay length
    								  (DBG_I2C_SDA_DLY<<6)|		// SDA delay length
    								  (DBG_SPI_CPOL<<9)|		// SPI clock polarity
    								  (DBG_SPI_CPHA<<10)|		// SPI clock phase
    								  (OFF<<12)|				// miso is toggled as half phase early
    								  (0<<13);					// spi_spck_compval_sel

	/* I2C */
    DBGSERIAL->I2C_DEV_ADDR.ulBulk 	= (I2C_ADDRESS)|		// touch i2c device addr
   									  (0x29<<7);			// watch i2c device addr( not used )

	DBGSERIAL->I2C_BUS_SEL.ulBulk	= (DGB_SERIAL_HARDWARE<<0)|	// Code
									  (DGB_SERIAL_HARDWARE<<1)|	// Data 0
									  (DGB_SERIAL_HARDWARE<<2)|	// Data 1
									  (DGB_SERIAL_HARDWARE<<3)|	// Data 2
									  (DGB_SERIAL_HARDWARE<<4)|	// SYS
									  (DGB_SERIAL_HARDWARE<<5)|	// DSP A
									  (DGB_SERIAL_HARDWARE<<6)|	// DSP B
									  (DGB_SERIAL_HARDWARE<<7)|	// PWM
									  (DGB_SERIAL_HARDWARE<<8)|	// MSPI
									  (DGB_SERIAL_HARDWARE<<9)|	// MPI
									  (DGB_SERIAL_HARDWARE<<10)|// TLVDS
									  (DGB_SERIAL_HARDWARE<<11)|// USB
									  (DGB_SERIAL_HARDWARE<<12)|// REPORT
									  (DGB_SERIAL_HARDWARE<<13)|// RAW
									  (DGB_SERIAL_HARDWARE<<14)|// CMD
									  (DGB_SERIAL_HARDWARE<<15)|// external memory 0
									  (DGB_SERIAL_HARDWARE<<16);// external memory 1

    DBGSERIAL->I2C_REPORT_START  	= TO_BE_DEFINED;
    DBGSERIAL->I2C_REPORT_END    	= TO_BE_DEFINED;

	/* SPI */
	DBGSERIAL->SPI_BUS_SEL.ulBulk	= (DGB_SERIAL_HARDWARE<<0)|	// Code
									  (DGB_SERIAL_HARDWARE<<1)|	// Data 0
									  (DGB_SERIAL_HARDWARE<<2)|	// Data 1
									  (DGB_SERIAL_HARDWARE<<3)|	// Data 2
									  (DGB_SERIAL_HARDWARE<<4)|	// SYS
									  (DGB_SERIAL_HARDWARE<<5)|	// DSP A
									  (DGB_SERIAL_HARDWARE<<6)|	// DSP B
									  (DGB_SERIAL_HARDWARE<<7)|	// PWM
									  (DGB_SERIAL_HARDWARE<<8)|	// MSPI
									  (DGB_SERIAL_HARDWARE<<9)|	// MPI
									  (DGB_SERIAL_HARDWARE<<10)|// TLVDS
									  (DGB_SERIAL_HARDWARE<<11)|// USB
									  (DGB_SERIAL_HARDWARE<<12)|// REPORT
									  (DGB_SERIAL_HARDWARE<<13)|// RAW
									  (DGB_SERIAL_HARDWARE<<14)|// CMD
									  (DGB_SERIAL_HARDWARE<<15)|// external memory 0
									  (DGB_SERIAL_HARDWARE<<16);// external memory 1

    DBGSERIAL->SPI_REPORT_START  	= TO_BE_DEFINED;
    DBGSERIAL->SPI_REPORT_END    	= TO_BE_DEFINED + 8;


	/*0xC00 ~ 0xEFF*/
    DBGSERIAL->SERIAL_CMD_START_ADDR = TO_BE_DEFINED;

    DBGSERIAL->SERIAL_INT_EN.ulBulk		= (ON<<0)|	// int_i2c_en
    								  (ON<<1)|	// int_serial_error_en
    								  (ON<<2)|	// int_i2c_report_done_en
    								  (ON<<3)|	// int_spi_en
    								  (ON<<4);	// int_spi_report_done_en

}

void DBGSERIAL_DeInitialize(void)
{
    DBGSERIAL->SERIAL_INT_EN.ulBulk = 0;

	NVIC_DisableIRQ(DBG_I2C_IRQn);
	NVIC_ClearPendingIRQ(DBG_I2C_IRQn);
	Fncp_DBG_I2C_IRQHandler = NULL;

	NVIC_DisableIRQ(DBG_SPI_IRQn);
	NVIC_ClearPendingIRQ(DBG_SPI_IRQn);
	Fncp_DBG_SPI_IRQHandler = NULL;
}
