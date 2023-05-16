/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _dbgserial.h
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

#ifndef __DBGSERIAL_H_
#define __DBGSERIAL_H_


typedef union {
	struct {
		unsigned i2c_en :1;
		unsigned spi_en :1;
		unsigned reserved :30;
	} tBit;
	__IO uint32_t ulBulk;
} tSERIAL_CTL_t;

typedef union {
	struct {
		unsigned int_i2c_en :1;
		unsigned int_serial_error_en :1;
		unsigned int_report_done_en :1;
		unsigned int_spi_en :1;
		unsigned int_spi_report_done_en :1;
		unsigned reserved :27;
	} tBit;
	__IO uint32_t ulBulk;
} tSERIAL_INT_EN_t;

typedef union {
	struct {
		unsigned int_i2c_clr :1;
		unsigned int_serial_error_clr :1;
		unsigned int_report_done_clr :1;
		unsigned int_spi_clr :1;
		unsigned int_spi_report_done_clr :1;
		unsigned reserved :27;
	} tBit;
	__IO uint32_t ulBulk;
} tSERIAL_INT_CLR_t;

typedef union {
	struct {
		unsigned i2c_degl_len :3;
		unsigned scl_dly_len :3;
		unsigned sda_dly_len :3;
		unsigned spi_cpol :1;
		unsigned spi_cpha :1;
		unsigned spi_pre_pha_miso :1;
		unsigned spi_spck_compval_sel :1;
		unsigned reserved :19;
	} tBit;
	__IO uint32_t ulBulk;
} tSERIAL_CFG_t;

typedef union {
	struct {
		unsigned i2c_dev_addr1 :7;
		unsigned i2c_dev_addr2 :7;
		unsigned reserved :18;
	} tBit;
	__IO uint32_t ulBulk;
} tI2C_DEV_ADDR_t;

typedef union {
	struct {
		unsigned code :1;
		unsigned data0 :1;
		unsigned data1 :1;
		unsigned data2 :1;
		unsigned sys :1;
		unsigned dspa :1;
		unsigned tdsp :1;
		unsigned pwm :1;
		unsigned mspi :1;
		unsigned mpi :1;
		unsigned tlvds :1;
		unsigned usb :1;
		unsigned report :1;
		unsigned raw :1;
		unsigned cmd :1;
		unsigned extm0 :1;
		unsigned extm1 :1;
		unsigned reserved :15;
	} tBit;
	__IO uint32_t ulBulk;
} tI2C_BUS_SEL_t;

typedef union {
	struct {
		unsigned i2c_access_addr :16;
		unsigned i2c_rw_cmd :1;
		unsigned reserved :15;
	} tBit;
	__IO uint32_t ulBulk;
} tI2C_CMD_ADDR_t;

typedef union {
	struct {
		unsigned code :1;
		unsigned data0 :1;
		unsigned data1 :1;
		unsigned data2 :1;
		unsigned sys :1;
		unsigned dspa :1;
		unsigned tdsp :1;
		unsigned pwm :1;
		unsigned mspi :1;
		unsigned mpi :1;
		unsigned tlvds :1;
		unsigned usb :1;
		unsigned report :1;
		unsigned raw :1;
		unsigned cmd :1;
		unsigned extm0 :1;
		unsigned extm1 :1;
		unsigned reserved :15;
	} tBit;
	__IO uint32_t ulBulk;
} tSPI_BUS_SEL_t;

typedef union {
	struct {
		unsigned spi_access_addr :16;
		unsigned spi_rw_cmd :1;
		unsigned reserved :15;
	} tBit;
	__IO uint32_t ulBulk;
} tSPI_CMD_ADDR_t;

typedef union {
	struct {
		unsigned i2c_multi_read :1;
		unsigned spi_multi_read :1;
		unsigned reserved :30;
	} tBit;
	__IO uint32_t ulBulk;
} tSERIAL_RD_STS_t;

typedef struct
{
	__IO tSERIAL_CTL_t SERIAL_CTL; //0x0080
	__IO tSERIAL_INT_EN_t SERIAL_INT_EN; //0x0081
	__O tSERIAL_INT_CLR_t SERIAL_INT_CLR; //0x0082
	__IO tSERIAL_CFG_t SERIAL_CFG; //0x0083
	__IO uint32_t SERIAL_CMD_START_ADDR; //0x0084
	__IO uint32_t SERIAL_ENDIAN_SEL; //0x0085
	__IO tI2C_DEV_ADDR_t I2C_DEV_ADDR; //0x0086
	__IO uint32_t I2C_RESERVE00; //0x0087
	__IO tI2C_BUS_SEL_t I2C_BUS_SEL; //0x0088
	__IO uint32_t I2C_CODE_OFFSET; //0x0089
	__IO uint32_t I2C_REPORT_START; //0x008A
	__IO uint32_t I2C_REPORT_END; //0x008B
	__IO uint32_t I2C_RESERVE01; //0x008C
	__IO uint32_t I2C_RAW_START; //0x008D
	__IO uint32_t I2C_DATA0_OFFSET; //0x008E
	__IO uint32_t I2C_DATA1_OFFSET; //0x008F
	__IO uint32_t I2C_DATA2_OFFSET; //0x0090
	__IO uint32_t I2C_RAW_OFFSET; //0x0091
	__IO uint32_t I2C_EXTM0_START; //0x0092
	__IO uint32_t I2C_EXTM1_START; //0x0093
	__IO uint32_t I2C_EXTM0_OFFSET; //0x0094
	__IO uint32_t I2C_EXTM1_OFFSET; //0x0095
	__IO uint32_t I2C_WR_DATA; //0x0096
	__I tI2C_CMD_ADDR_t I2C_CMD_ADDR; //0x0097
	__I uint32_t I2C_CMD_LENGTH; //0x0098
	__I uint32_t I2C_RD_DATA; //0x0099
	__IO tSPI_BUS_SEL_t SPI_BUS_SEL; //0x009A
	__IO uint32_t SPI_CODE_OFFSET; //0x009B
	__IO uint32_t SPI_REPORT_START; //0x009C
	__IO uint32_t SPI_REPORT_END; //0x009D
	__IO uint32_t SPI_RESERVED0; //0x009E
	__IO uint32_t SPI_RAW_START; //0x009F
	__IO uint32_t SPI_DATA0_OFFSET; //0x00A0
	__IO uint32_t SPI_DATA1_OFFSET; //0x00A1
	__IO uint32_t SPI_DATA2_OFFSET; //0x00A2
	__IO uint32_t SPI_RAW_OFFSET; //0x00A3
	__IO uint32_t SPI_EXTM0_START; //0x00A4
	__IO uint32_t SPI_EXTM1_START; //0x00A5
	__IO uint32_t SPI_EXTM0_OFFSET; //0x00A6
	__IO uint32_t SPI_EXTM1_OFFSET; //0x00A7
	__IO uint32_t SPI_WR_DATA; //0x00A8
	__I tSPI_CMD_ADDR_t SPI_CMD_ADDR; //0x00A9
	__I uint32_t SPI_CMD_LENGTH; //0x00AA
	__I uint32_t SPI_RD_DATA; //0x00AB
	__O uint32_t SPI_SPCK_CLR; //0x00AC
	__I tSERIAL_RD_STS_t SERIAL_RD_STS; //0x00AD
	__I uint32_t SPI_FAULT_TYPE_CFG; //0x00AE
	__I uint32_t SPI_RESET_CNT_CFG; //0x00AF
	__IO uint32_t SPI_RESERVED01; //0x00B0
	__IO uint32_t SERIAL_RESERVED01; //0x00B1
	__IO uint32_t SERIAL_RESERVED02; //0x00B2
	__IO uint32_t SERIAL_RESERVED03; //0x00B3
	__IO uint32_t SERIAL_RESERVED04; //0x00B4
	__IO uint32_t SERIAL_RESERVED05; //0x00B5
	__IO uint32_t SERIAL_RESERVED06; //0x00B6
	__IO uint32_t SERIAL_RESERVED07; //0x00B7
	__IO uint32_t SERIAL_RESERVED08; //0x00B8
	__IO uint32_t SERIAL_RESERVED09; //0x00B9
	__IO uint32_t SERIAL_RESERVED10; //0x00BA
	__IO uint32_t SERIAL_RESERVED11; //0x00BB
	__IO uint32_t SERIAL_RESERVED12; //0x00BC
	__IO uint32_t SERIAL_RESERVED14; //0x00BD
	__IO uint32_t SERIAL_RESERVED15; //0x00BE
	__IO uint32_t SERIAL_RESERVED16; //0x00BF

} tDBGSERIAL_CtrlReg_t;


#endif /* __DBGSERIAL_H_ */
