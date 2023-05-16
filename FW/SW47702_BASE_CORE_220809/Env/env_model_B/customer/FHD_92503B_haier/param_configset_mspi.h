/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : param_configset_mspi.h
 * created on : 3. 4. 2019
 * Author : mhjang
 *
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright
 *	 notice, this list of conditions and the following disclaimer.
 *	 - Redistributions in binary form must reproduce the above copyright
 *	 notice, this list of conditions and the following disclaimer in the
 *	 documentation and/or other materials provided with the distribution.
 * - Neither the name of SiW nor the names of its contributors may be used
 *	 to endorse or promote products derived from this software without
 *	 specific prior written permission.
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

#ifndef _PARAM_CONFIGSET_MSPI_H_
#define _PARAM_CONFIGSET_MSPI_H_


#define PARAMSET_MSPI_ENA_spi_TX_Ena0							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_TX_Ena1							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_TX_Ena2							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_TX_Ena3							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_TX_Ena4							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_TX_Ena5							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_TX_Ena6							(SPI_DISABLE)
#define PARAMSET_MSPI_ENA_spi_TX_Ena7							(SPI_DISABLE)

#define PARAMSET_MSPI_ENA_spi_RX_Ena0							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_RX_Ena1							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_RX_Ena2							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_RX_Ena3							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_RX_Ena4							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_RX_Ena5							(SPI_ENABLE)
#define PARAMSET_MSPI_ENA_spi_RX_Ena6							(SPI_DISABLE)
#define PARAMSET_MSPI_ENA_spi_RX_Ena7							(SPI_DISABLE)

#define PARAMSET_MSPI_ENA_spi_TRX_Ena0							(SPI_DUALMODE_DISABLE)
#define PARAMSET_MSPI_ENA_spi_TRX_Ena1							(SPI_DUALMODE_DISABLE)
#define PARAMSET_MSPI_ENA_spi_TRX_Ena2							(SPI_DUALMODE_DISABLE)
#define PARAMSET_MSPI_ENA_spi_TRX_Ena3							(SPI_DUALMODE_DISABLE)
#define PARAMSET_MSPI_ENA_spi_TRX_Ena4							(SPI_DUALMODE_DISABLE)
#define PARAMSET_MSPI_ENA_spi_TRX_Ena5							(SPI_DUALMODE_DISABLE)
#define PARAMSET_MSPI_ENA_spi_TRX_Ena6							(SPI_DUALMODE_DISABLE)
#define PARAMSET_MSPI_ENA_spi_TRX_Ena7							(SPI_DUALMODE_DISABLE)

/*
 * Setting MSPI RX Pos
 * 48M base : MSPI Clock Divider
 * 1 : 0
 * 2 : 0~1 Delay : (0 -> 1) 32Mhz
 * 3 : 0~2 Delay : (0 -> 2 -> 1) 16Mhz
 * 4 : 0~3 : (0 -> 2 -> 3 -> 1) 8Mhz
 */
#define PARAMSET_MSPI_RX_POS									(0x2)

/*
 * #define GPIO_DRIVE_STR_4mA			(0)
 * #define GPIO_DRIVE_STR_8mA			(1)
 * #define GPIO_DRIVE_STR_16mA			(2)
 * #define GPIO_DRIVE_STR_20mA			(3)
 */
#define PARAMSET_MSPI_0_CSN_DRVSTR_LEVEL						(GPIO_DRIVE_STR_4mA)
#define PARAMSET_MSPI_0_CLK_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)
#define PARAMSET_MSPI_0_MOSI_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)

#define PARAMSET_MSPI_1_CSN_DRVSTR_LEVEL						(GPIO_DRIVE_STR_4mA)
#define PARAMSET_MSPI_1_CLK_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)
#define PARAMSET_MSPI_1_MOSI_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)

#define PARAMSET_MSPI_2_CSN_DRVSTR_LEVEL						(GPIO_DRIVE_STR_4mA)
#define PARAMSET_MSPI_2_CLK_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)
#define PARAMSET_MSPI_2_MOSI_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)

#define PARAMSET_MSPI_3_CSN_DRVSTR_LEVEL						(GPIO_DRIVE_STR_4mA)
#define PARAMSET_MSPI_3_CLK_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)
#define PARAMSET_MSPI_3_MOSI_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)

#define PARAMSET_MSPI_4_CSN_DRVSTR_LEVEL						(GPIO_DRIVE_STR_4mA)
#define PARAMSET_MSPI_4_CLK_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)
#define PARAMSET_MSPI_4_MOSI_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)

#define PARAMSET_MSPI_5_CSN_DRVSTR_LEVEL						(GPIO_DRIVE_STR_4mA)
#define PARAMSET_MSPI_5_CLK_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)
#define PARAMSET_MSPI_5_MOSI_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)

#define PARAMSET_MSPI_6_CSN_DRVSTR_LEVEL						(GPIO_DRIVE_STR_4mA)
#define PARAMSET_MSPI_6_CLK_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)
#define PARAMSET_MSPI_6_MOSI_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)

#define PARAMSET_MSPI_7_CSN_DRVSTR_LEVEL						(GPIO_DRIVE_STR_4mA)
#define PARAMSET_MSPI_7_CLK_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)
#define PARAMSET_MSPI_7_MOSI_DRVSTR_LEVEL						(GPIO_DRIVE_STR_16mA)


/********************************************************************************************************************/
/* 									MS Pen LHB Control Configuration Value 											*/
/********************************************************************************************************************/
/*
 * Local Finger Mux Scan Order Index
 */
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_1Mux	(FINGER_SCAN_MUX_1)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_2Mux	(FINGER_SCAN_MUX_2)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_3Mux	(FINGER_SCAN_MUX_3)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_1stLHB_4Mux	(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_1Mux	(FINGER_SCAN_MUX_4)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_2Mux	(FINGER_SCAN_MUX_5)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_3Mux	(FINGER_SCAN_MUX_6)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_2ndLHB_4Mux	(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_1Mux	(FINGER_SCAN_MUX_7)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_2Mux	(FINGER_SCAN_MUX_8)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_3Mux	(FINGER_SCAN_MUX_9)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_3rdLHB_4Mux	(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_4thLHB_1Mux	(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_4thLHB_2Mux	(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_4thLHB_3Mux	(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_4thLHB_4Mux	(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_5thLHB_1Mux	(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_5thLHB_2Mux	(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_5thLHB_3Mux	(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_5thLHB_4Mux	(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_6thLHB_1Mux	(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_6thLHB_2Mux	(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_6thLHB_3Mux	(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_MS_6thLHB_4Mux	(DONOT_SCAN)
/*
 * Full Finger Mux Scan Order Index
 */
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_1Mux		(FINGER_SCAN_MUX_1)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_2Mux		(FINGER_SCAN_MUX_2)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_3Mux		(FINGER_SCAN_MUX_3)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_1stLHB_4Mux		(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_1Mux		(FINGER_SCAN_MUX_4)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_2Mux		(FINGER_SCAN_MUX_5)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_3Mux		(FINGER_SCAN_MUX_6)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_2ndLHB_4Mux		(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_1Mux		(FINGER_SCAN_MUX_7)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_2Mux		(FINGER_SCAN_MUX_8)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_3Mux		(FINGER_SCAN_MUX_9)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_3rdLHB_4Mux		(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_4thLHB_1Mux		(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_4thLHB_2Mux		(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_4thLHB_3Mux		(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_4thLHB_4Mux		(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_5thLHB_1Mux		(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_5thLHB_2Mux		(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_5thLHB_3Mux		(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_5thLHB_4Mux		(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_6thLHB_1Mux		(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_6thLHB_2Mux		(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_6thLHB_3Mux		(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_MS_6thLHB_4Mux		(DONOT_SCAN)



#define PARAMSET_MSPI_ControlConf_Local_MS_LHBCount				(10)
#define PARAMSET_MSPI_ControlConf_Local_MS_Buf_Panel_ColNum		((MSPI_NUM * MSPI_MSPEN_ALIGNED_COL_LEN))

#define PARAMSET_MSPI_ControlConf_Local_MS_1LHB_Pen				/* Beacon 1 */
#define PARAMSET_MSPI_ControlConf_Local_MS_2LHB_Pen				PARTIAL_PEN_COORD1,
#define PARAMSET_MSPI_ControlConf_Local_MS_3LHB_Pen				PARTIAL_PEN_DATA1,
#define PARAMSET_MSPI_ControlConf_Local_MS_4LHB_Pen				PARTIAL_PEN_DATA2,
#define PARAMSET_MSPI_ControlConf_Local_MS_5LHB_Pen				PARTIAL_PEN_DATA3,
#define PARAMSET_MSPI_ControlConf_Local_MS_6LHB_Pen				PARTIAL_PEN_COORD2,
#define PARAMSET_MSPI_ControlConf_Local_MS_7LHB_Pen				PARTIAL_PEN_DATA4,
#define PARAMSET_MSPI_ControlConf_Local_MS_8LHB_Pen				/* Noise */
#define PARAMSET_MSPI_ControlConf_Local_MS_9LHB_Pen				/* Beacon 2 */
#define PARAMSET_MSPI_ControlConf_Local_MS_10LHB_Pen			PARTIAL_PEN_COORD3,
#define PARAMSET_MSPI_ControlConf_Local_MS_11LHB_Pen			/* PARTIAL_Dummy, */
#define PARAMSET_MSPI_ControlConf_Local_MS_12LHB_Pen			/* PARTIAL_Dummy, */
#define PARAMSET_MSPI_ControlConf_Local_MS_13LHB_Pen			PARTIAL_FINGER1,
#define PARAMSET_MSPI_ControlConf_Local_MS_14LHB_Pen			PARTIAL_PEN_COORD4,
#define PARAMSET_MSPI_ControlConf_Local_MS_15LHB_Pen			PARTIAL_FINGER2,
#define PARAMSET_MSPI_ControlConf_Local_MS_16LHB_Pen			PARTIAL_FINGER3,

/********************************************************************************************************************/
/* 									Wacom AIT Pen LHB Control Configuration Value 									*/
/********************************************************************************************************************/
/*
 * Local Finger Mux Scan Order Index
 */
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_1stLHB_1Mux			(FINGER_SCAN_MUX_1)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_1stLHB_2Mux			(FINGER_SCAN_MUX_2)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_1stLHB_3Mux			(FINGER_SCAN_MUX_3)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_1stLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_2ndLHB_1Mux			(FINGER_SCAN_MUX_4)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_2ndLHB_2Mux			(FINGER_SCAN_MUX_5)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_2ndLHB_3Mux			(FINGER_SCAN_MUX_6)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_2ndLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_3rdLHB_1Mux			(FINGER_SCAN_MUX_7)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_3rdLHB_2Mux			(FINGER_SCAN_MUX_8)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_3rdLHB_3Mux			(FINGER_SCAN_MUX_9)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_3rdLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_4thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_4thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_4thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_4thLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_5thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_5thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_5thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_5thLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_6thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_6thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_6thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_Wacom_6thLHB_4Mux			(DONOT_SCAN)
/*
 * Full Finger Mux Scan Order Index
 */
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_1stLHB_1Mux			(FINGER_SCAN_MUX_1)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_1stLHB_2Mux			(FINGER_SCAN_MUX_2)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_1stLHB_3Mux			(FINGER_SCAN_MUX_3)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_1stLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_2ndLHB_1Mux			(FINGER_SCAN_MUX_4)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_2ndLHB_2Mux			(FINGER_SCAN_MUX_5)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_2ndLHB_3Mux			(FINGER_SCAN_MUX_6)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_2ndLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_3rdLHB_1Mux			(FINGER_SCAN_MUX_7)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_3rdLHB_2Mux			(FINGER_SCAN_MUX_8)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_3rdLHB_3Mux			(FINGER_SCAN_MUX_9)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_3rdLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_4thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_4thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_4thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_4thLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_5thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_5thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_5thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_5thLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_6thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_6thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_6thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_Wacom_6thLHB_4Mux			(DONOT_SCAN)



#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_LHBCount				(12)
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_Buf_Panel_ColNum		((MSPI_NUM * MSPI_WACOMPEN_ALIGNED_COL_LEN))

#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_1LHB_Pen				/* Beacon 1 */
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_2LHB_Pen				PARTIAL_PEN_COORD1,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_3LHB_Pen				PARTIAL_PEN_DATA1,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_4LHB_Pen				PARTIAL_FINGER1,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_5LHB_Pen				PARTIAL_PEN_COORD2,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_6LHB_Pen				PARTIAL_PEN_DATA2,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_7LHB_Pen				PARTIAL_PEN_DATA3,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_8LHB_Pen				PARTIAL_FINGER2,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_9LHB_Pen				PARTIAL_PEN_COORD3,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_10LHB_Pen				PARTIAL_FINGER3,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_11LHB_Pen				/* PARTIAL_Dummy, */
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_12LHB_Pen				/* PARTIAL_Dummy, */
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_13LHB_Pen				PARTIAL_PEN_COORD4,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_14LHB_Pen				PARTIAL_PEN_DATA4,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_15LHB_Pen				PARTIAL_PEN_DATA5,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_AIT_16LHB_Pen				PARTIAL_FINGER4,

/********************************************************************************************************************/
/* 									Wacom WGP Pen LHB Control Configuration Value 									*/
/********************************************************************************************************************/
/*
 * Local Finger Mux Scan Order Index
 */
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_1Mux			(FINGER_SCAN_MUX_1)//(FINGER_SCAN_MUX_1)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_2Mux			(FINGER_SCAN_MUX_2)//(FINGER_SCAN_MUX_2)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_3Mux			(FINGER_SCAN_MUX_3)//(FINGER_SCAN_MUX_3)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_1stLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_1Mux			(FINGER_SCAN_MUX_4)//(FINGER_SCAN_MUX_4)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_2Mux			(FINGER_SCAN_MUX_5)//(FINGER_SCAN_MUX_5)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_3Mux			(FINGER_SCAN_MUX_6)//(FINGER_SCAN_MUX_6)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_2ndLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_1Mux			(FINGER_SCAN_MUX_7)//(FINGER_SCAN_MUX_7)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_2Mux			(FINGER_SCAN_MUX_8)//(FINGER_SCAN_MUX_8)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_3Mux			(FINGER_SCAN_MUX_9)//(FINGER_SCAN_MUX_9)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_3rdLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_4thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_4thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_4thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_4thLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_5thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_5thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_5thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_5thLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_6thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_6thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_6thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Local_WGP_6thLHB_4Mux			(DONOT_SCAN)
/*
 * Full Finger Mux Scan Order Index
 */
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_1Mux			(FINGER_SCAN_MUX_1)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_2Mux			(FINGER_SCAN_MUX_2)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_3Mux			(FINGER_SCAN_MUX_3)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_1stLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_1Mux			(FINGER_SCAN_MUX_4)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_2Mux			(FINGER_SCAN_MUX_5)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_3Mux			(FINGER_SCAN_MUX_6)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_2ndLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_1Mux			(FINGER_SCAN_MUX_7)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_2Mux			(FINGER_SCAN_MUX_8)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_3Mux			(FINGER_SCAN_MUX_9)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_3rdLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_4thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_4thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_4thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_4thLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_5thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_5thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_5thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_5thLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_6thLHB_1Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_6thLHB_2Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_6thLHB_3Mux			(DONOT_SCAN)
#define PARAMSET_MSPI_FINGER_MUX_SCAN_ORDER_IDX_Full_WGP_6thLHB_4Mux			(DONOT_SCAN)

#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_LHBCount						(12)
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_Buf_Panel_ColNum				((MSPI_NUM * MSPI_WGPPEN_ALIGNED_COL_LEN))

#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_1LHB_Pen				/* Beacon 1 */
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_2LHB_Pen				PARTIAL_PEN_COORD1,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_3LHB_Pen				/* PARTIAL_Dummy, */
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_4LHB_Pen				/* PARTIAL_Dummy, */
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_5LHB_Pen				PARTIAL_TILT1,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_6LHB_Pen				PARTIAL_PEN_COORD2,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_7LHB_Pen				PARTIAL_PEN_DATA1,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_8LHB_Pen				PARTIAL_PEN_DATA2,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_9LHB_Pen				PARTIAL_FINGER1,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_10LHB_Pen				PARTIAL_PEN_COORD3,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_11LHB_Pen				PARTIAL_FINGER2,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_12LHB_Pen				PARTIAL_FINGER3,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_13LHB_Pen				PARTIAL_TILT2,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_14LHB_Pen				PARTIAL_PEN_COORD4,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_15LHB_Pen				PARTIAL_PEN_DATA3,
#define PARAMSET_MSPI_ControlConf_Local_WACOM_WGP_16LHB_Pen				PARTIAL_PEN_DATA4,

#endif /* _PARAM_CONFIGSET_MSPI_H_ */
