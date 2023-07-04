/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : gpio_define.h
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

#ifndef _GPIO_DEFINE_H_
#define _GPIO_DEFINE_H_


#define _GPIO_MSPI_0_CSN			tBit.GPA00
#define _GPIO_MSPI_0_SCLK			tBit.GPA01
#define _GPIO_MSPI_0_MOSI			tBit.GPA02
#define _GPIO_MSPI_0_MISO			tBit.GPA03

#define _GPIO_MSPI_1_CSN			tBit.GPA04
#define _GPIO_MSPI_1_SCLK			tBit.GPA05
#define _GPIO_MSPI_1_MOSI			tBit.GPA06
#define _GPIO_MSPI_1_MISO			tBit.GPA07

#define _GPIO_MSPI_2_CSN			tBit.GPA08
#define _GPIO_MSPI_2_SCLK			tBit.GPA09
#define _GPIO_MSPI_2_MOSI			tBit.GPA10
#define _GPIO_MSPI_2_MISO			tBit.GPA11

#define _GPIO_MSPI_3_CSN			tBit.GPA12
#define _GPIO_MSPI_3_SCLK			tBit.GPA13
#define _GPIO_MSPI_3_MOSI			tBit.GPA14
#define _GPIO_MSPI_3_MISO			tBit.GPA15

#define _GPIO_MSPI_4_CSN			tBit.GPA16
#define _GPIO_MSPI_4_SCLK			tBit.GPA17
#define _GPIO_MSPI_4_MOSI			tBit.GPA18
#define _GPIO_MSPI_4_MISO			tBit.GPA19

#define _GPIO_MSPI_5_CSN			tBit.GPA20
#define _GPIO_MSPI_5_SCLK			tBit.GPA21
#define _GPIO_MSPI_5_MOSI			tBit.GPA22
#define _GPIO_MSPI_5_MISO			tBit.GPA23

#define _GPIO_VSYNC					tBit.GPA26
#define _GPIO_TSYNC_IN				tBit.GPA27
#define _GPIO_TSYNC2_IN				tBit.GPA37
#define _GPIO_TSYNC_OUT				tBit.GPA35
#define _GPIO_PWM_SRIC				tBit.GPA28
//#define _GPIO_PWM_TPIC				tBit.GPA29
#define _GPIO_PWM_GATE				tBit.GPA29
//#define _GPIO_RSTN_SRIC				tBit.GPA33
#define _GPIO_LCD_ON				tBit.GPA34
#define _GPIO_TP_EN					tBit.GPB09
#define _GPIO_TP_INTR				tBit.GPB10
#define _GPIO_TPIC_MUX_EN			tBit.GPA36
#define _GPIO_ECLK_0				tBit.GPA24
#define _GPIO_ECLK_1				tBit.GPA25
#define _GPIO_SWDIO					tBit.GPB00
#define _GPIO_SWCLK					tBit.GPB01
#define _GPIO_RSTN_0				tBit.GPA30
#define _GPIO_RSTN_1				tBit.GPA31

#define _GPIO_VTSP18				tBit.GPA32

#define _GPIO_DEBUG_B5				tBit.GPB05
#define _GPIO_SLEEP_RST				tBit.GPB08

//#define _GPIO_VSWT0					tBit.GPA33
#define _GPIO_TOGGLE				tBit.GPA33



#define GPIO_MSPI_0_CSN				(PIN_GPA00)
#define GPIO_MSPI_0_CLK				(PIN_GPA01)
#define GPIO_MSPI_0_MOSI			(PIN_GPA02)
#define GPIO_MSPI_0_MISO			(PIN_GPA03)
#define GPIO_MSPI_1_CSN				(PIN_GPA04)
#define GPIO_MSPI_1_CLK				(PIN_GPA05)
#define GPIO_MSPI_1_MOSI			(PIN_GPA06)
#define GPIO_MSPI_1_MISO			(PIN_GPA07)
#define GPIO_MSPI_2_CSN				(PIN_GPA08)
#define GPIO_MSPI_2_CLK				(PIN_GPA09)
#define GPIO_MSPI_2_MOSI			(PIN_GPA10)
#define GPIO_MSPI_2_MISO			(PIN_GPA11)
#define GPIO_MSPI_3_CSN				(PIN_GPA12)
#define GPIO_MSPI_3_CLK				(PIN_GPA13)
#define GPIO_MSPI_3_MOSI			(PIN_GPA14)
#define GPIO_MSPI_3_MISO			(PIN_GPA15)
#define GPIO_MSPI_4_CSN				(PIN_GPA16)
#define GPIO_MSPI_4_CLK				(PIN_GPA17)
#define GPIO_MSPI_4_MOSI			(PIN_GPA18)
#define GPIO_MSPI_4_MISO			(PIN_GPA19)
#define GPIO_MSPI_5_CSN				(PIN_GPA20)
#define GPIO_MSPI_5_CLK				(PIN_GPA21)
#define GPIO_MSPI_5_MOSI			(PIN_GPA22)
#define GPIO_MSPI_5_MISO			(PIN_GPA23)
#define GPIO_ECLK_0					(PIN_GPA24)
#define GPIO_ECLK_1					(PIN_GPA25)
#define GPIO_GPIOA1					(PIN_GPA25)
#define GPIO_VSYNC					(PIN_GPA26)
#define GPIO_TSYNC_IN				(PIN_GPA27)
#define GPIO_PWM_TX					(PIN_GPA28)
#define GPIO_PWM_DATA				(PIN_GPA29)
#define GPIO_PWM_GATE				(PIN_GPA30)
#define GPIO_VSWT2					(PIN_GPA31)
#define GPIO_GPIOA2					(PIN_GPA31)
#define GPIO_VSWT3					(PIN_GPA32)
#define GPIO_GPIOA3					(PIN_GPA32)
#define GPIO_VSWT0					(PIN_GPA33)
#define GPIO_RSTN_SRIC				(PIN_GPA33)
#define GPIO_VSWT1					(PIN_GPA34)
#define GPIO_LCD_ON					(PIN_GPA34)
#define GPIO_TSYNC_OUT				(PIN_GPA35)
#define GPIO_I2C_M_SCL				(PIN_GPA36)
#define GPIO_I2C_M_SDA				(PIN_GPA37)
#define GPIO_SWDIO					(PIN_GPB00)
#define GPIO_SWCLK					(PIN_GPB01)
#define GPIO_I2C_S_SCL				(PIN_GPB02)
#define GPIO_I2C_S_SDA				(PIN_GPB03)
#define GPIO_TSPI_CSN				(PIN_GPB04)
#define GPIO_TSPI_CLK				(PIN_GPB05)
#define GPIO_TSPI_MOSI				(PIN_GPB06)
#define GPIO_TSPI_MISO				(PIN_GPB07)
#define GPIO_TSPI_INTR				(PIN_GPB08)
#define GPIO_TP_EN					(PIN_GPB09)
#define GPIO_GPIOB1					(PIN_GPB09)
#define GPIO_TP_INTR				(PIN_GPB10)
#define GPIO_GPIOB3					(PIN_GPB10)
#define GPIO_SWV					(PIN_GPB11)
#define GPIO_GPIOB2					(PIN_GPB11)
#define GPIO_SFLASH_CLK				(PIN_GPB12)
#define GPIO_SFLASH_CSN				(PIN_GPB13)
#define GPIO_SFLASH_MISO			(PIN_GPB14)
#define GPIO_SFLASH_MOSI			(PIN_GPB15)


#endif /* _GPIO_DEFINE_H_ */
