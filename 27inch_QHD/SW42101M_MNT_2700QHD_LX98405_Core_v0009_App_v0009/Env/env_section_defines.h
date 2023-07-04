/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : env_section_defines.h
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

#ifndef _ENV_SECTION_DEFINES_H_
#define _ENV_SECTION_DEFINES_H_


/*******************************************************************************
 * Allocate Functions and Variables in specific Section
 *******************************************************************************/
/*-----------------------------------------------------------------------------*
 *                            Bootloader Used                                  *
 ------------------------------------------------------------------------------*/
#define __BOOT						__attribute__((section("BOOT")))

///*
// * Application빌드 시 아래 Function들에 대한 Address가 변경이 되었는지 여부도 체크를 해야 한다.
// */
//#define APP_Fncp_APP_APP_RESET		((void *)0x00003079)
//#define APP_Fncp_APP_APP_PENDSV_IRQ ((void *)0x000030b9)
//#define APP_Fncp_APP_SYSTICK_IRQ	((void *)0x000030c9)
//#define APP_Fncp_APP_I2C_IRQ		((void *)0x000030d9)
//#define APP_Fncp_APP_WDT_IRQ		((void *)0x000030e9)
//#define APP_Fncp_APP_EXTI0_IRQ		((void *)0x000030f9)
//#define APP_Fncp_APP_EXIT1_IRQ		((void *)0x00003109)
//#define APP_Fncp_APP_TIMER_IRQ		((void *)0x00003119)
//#define APP_Fncp_APP_TSPI_IRQ		((void *)0x00003129)
//#define APP_Fncp_APP_USB_IRQ		((void *)0x00003139)
//#define APP_Fncp_APP_PWMDRV_IRQ		((void *)0x00003149)
//#define APP_Fncp_APP_MSPI_IRQ		((void *)0x00003159)
//#define APP_Fncp_APP_GPDMA_IRQ		((void *)0x00003169)
//#define APP_Fncp_APP_DSP_A_IRQ		((void *)0x00003179)
//#define APP_Fncp_APP_DSP_B_IRQ		((void *)0x00003189)
//#define APP_Fncp_APP_PLL_IRQ		((void *)0x00003199)
//#define APP_Fncp_APP_FLITF_IRQ		((void *)0x000031a9)

/*-----------------------------------------------------------------------------*
 *                            Application Used                                 *
 ------------------------------------------------------------------------------*/
#define __APP						__attribute__((section("APP")))


/*-----------------------------------------------------------------------------*
 *                            Common Used                                      *
 ------------------------------------------------------------------------------*/
#define __DATA_HEAD					__attribute__((section(".data_head")))


#endif /* _ENV_SECTION_DEFINES_H_ */
