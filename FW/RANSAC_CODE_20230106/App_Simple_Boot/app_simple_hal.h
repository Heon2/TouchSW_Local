/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_simple_hal.h
 * created on : 04. 05.2020
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

#ifndef _APP_SIMPLE_HAL_H_
#define _APP_SIMPLE_HAL_H_


#include "MFTP.h"
#include "flitf_types.h"
#include "gpio_define.h"


extern void SimpleHal_Initialize(tSimpleBootFlashCtrlInfo_t * pSimpleBootFlashCtrlInfo);
extern void SimplHal_medium_delay(uint32_t usec);

extern void SimplHal_FLASH_InitializeRegister(void);
extern void SimplHal_FLASH_POR_Reset(void);
extern bool_t SimplHal_FLASH_Program_Init(void);
extern bool_t SimplHal_FLASH_Erase_Page(uint32_t _addr);
extern bool_t SimplHal_FLASH_Program_Page(uint32_t _addr, uint32_t *buf, uint32_t ulWordSize);
extern bool_t SimplHal_FLASH_DisableWriteProtection(void);
extern bool_t SimplHal_FLASH_Program_UnInit(void);


#endif /* _APP_SIMPLE_HAL_H_ */
