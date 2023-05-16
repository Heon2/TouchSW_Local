/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : gpio_define.h
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

#ifndef _GPIO_DEFINE_H_
#define _GPIO_DEFINE_H_

#define GET_GPIO_TSYNC_IN_STATUS			(GPIO->GPIOAH_IN.tBit.GPIOA35)
#define GPIO_TP_INTR_OUT_STATUS				(GPIO->GPIOM_OUT.tBit.GPIOM04)

	#define _GPIO_SWCLK					GPIO_M00
	#define _GPIO_SWDIO					GPIO_M01
	#define _GPIO_SLV_SCL				GPIO_M02
	#define _GPIO_SLV_SDA				GPIO_M03
	#define _GPIO_TP_INTR				GPIO_M04
	#define _GPIO_TCH_CSN		        GPIO_M05
	#if USED_TP_RST_OPERATION
		#define _GPIO_TP_RST				GPIO_M06
	#else /* USED_TP_RST_OPERATION */
		#define _GPIO_TCH_SCK				GPIO_M06
	#endif /* USED_TP_RST_OPERATION */
	#define _GPIO_TP_EN  				GPIO_M07
	#define _GPIO_TCH_MISO				GPIO_M08
	#define _GPIO_MSPI_0_CSN			GPIO_A00
	#define _GPIO_MSPI_0_CLK			GPIO_A01
	#define _GPIO_MSPI_0_MOSI			GPIO_A02
	#define _GPIO_MSPI_0_MISO			GPIO_A03
	#define _GPIO_MSPI_1_CSN			GPIO_A04
	#define _GPIO_MSPI_1_CLK			GPIO_A05
	#define _GPIO_MSPI_1_MOSI			GPIO_A06
	#define _GPIO_MSPI_1_MISO			GPIO_A07
	#define _GPIO_MSPI_2_CSN			GPIO_A08
	#define _GPIO_MSPI_2_CLK			GPIO_A09
	#define _GPIO_MSPI_2_MOSI			GPIO_A10
	#define _GPIO_MSPI_2_MISO			GPIO_A11
	#define _GPIO_MSPI_3_CSN			GPIO_A12
	#define _GPIO_MSPI_3_CLK			GPIO_A13
	#define _GPIO_MSPI_3_MOSI			GPIO_A14
	#define _GPIO_MSPI_3_MISO			GPIO_A15
	#define _GPIO_MSPI_4_CSN			GPIO_A16
	#define _GPIO_MSPI_4_CLK			GPIO_A17
	#define _GPIO_MSPI_4_MOSI			GPIO_A18
	#define _GPIO_MSPI_4_MISO			GPIO_A19
	#define _GPIO_MSPI_5_CSN			GPIO_A20
	#define _GPIO_MSPI_5_CLK			GPIO_A21
#define SET_GPIO_MUX_EN_TPIC_STATUS				(GPIO->GPIOAL_OUT.tBit.GPIOA22)
	#define _GPIO_MUX_EN_TPIC			GPIO_A22
	#define _GPIO_MSPI_5_MISO			GPIO_A23
	#define _GPIO_MSPI_6_CSN			GPIO_A24    // NC
	#define _GPIO_MSPI_6_CLK			GPIO_A25    // NC
	#define _GPIO_MSPI_6_MOSI			GPIO_A26    // NC
	#define _GPIO_MSPI_6_MISO			GPIO_A27    // NC
	#define _GPIO_MSPI_7_CSN			GPIO_A28    // NC
	#define _GPIO_MSPI_7_CLK			GPIO_A29    // NC
	#define _GPIO_MSPI_7_MOSI			GPIO_A30    // NC
	#define _GPIO_MSPI_7_MISO			GPIO_A31    // NC
	#define _GPIO_ECLK_0				GPIO_A32
	#define _GPIO_ECLK_1				GPIO_A33
	#define _GPIO_VSYNC					GPIO_A34
	#define _GPIO_TSYNC_IN				GPIO_A35
	#define _GPIO_PWM_SRIC				GPIO_A36
	#define _GPIO_PWM_TPIC				GPIO_A37
	#define _GPIO_TSYNC_2_IN			GPIO_A38    // TP
	#define _GPIO_TSYNC_OUT				GPIO_A39
	#define _GPIO_TSYNC_TMIC			GPIO_A40
	#define _GPIO_RSTN_SRIC				GPIO_A41
	#define _GPIO_LCD_ON				GPIO_A42
#define SET_GPIO_Uplink_GPIO_STATUS				(GPIO->GPIOAH_OUT.tBit.GPIOA43)
	#define _GPIO_Uplink_GPIO			GPIO_A43    // TP
	#define _GPIO_MST_SCL				GPIO_A44    // TP
	#define _GPIO_MST_SDA				GPIO_A45    // TP

#endif /* _GPIO_DEFINE_H_ */
