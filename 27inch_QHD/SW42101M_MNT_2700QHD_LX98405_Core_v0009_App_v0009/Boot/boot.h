/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : boot.h
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

#ifndef _BOOT_H_
#define _BOOT_H_


typedef enum
{
	BOOT_OP_STATUS_ENTRY 						= 0,
	BOOT_OP_STATUS_BOOTCODE_CHECK				= 1,
	BOOT_OP_STATUS_APPCODE_CHECK				= 2,
	BOOT_OP_STATUS_APPCODE_UPDATE				= 3,

	BOOT_OP_STATUS_APPCODE_UPDATE_DONE			= 4,
	BOOT_OP_STATUS_TOTALCODE_UPDATE_DONE		= 5,

	BOOT_OP_STATUS_APPCODE_DUMP_AND_RUN			= 6,
	BOOT_OP_STATUS_BOOTCODE_UPDATE_DONE			= 7,
	BOOT_OP_STATUS_BOOTCODE_DONOT_UPDATE		= 8,

	BOOT_OP_STATUS_ERROR_BOOTCODE_ERROR			= 9,
	BOOT_OP_STATUS_ERROR_BOOTCODE_UPDATE_FAIL	= 10,
	BOOT_OP_STATUS_ERROR_MAGICCODE_UPDATE_FAIL	= 11,
	BOOT_OP_STATUS_ERROR_APPCODE_ERROR			= 12,
	BOOT_OP_STATUS_ERROR_APPCODE_DUMP_ERROR		= 13,

	BOOT_OP_STATUS_ERROR_APPCODE_UPDATE_FAIL	= 14,
	BOOT_OP_STATUS_ERROR_TOTALCODE_UPDATE_FAIL	= 15,

	BOOT_OP_STATUS_LIMIT						= 0xFFFF

} eBootOperMainState_t;

__BOOT extern eBootOperMainState_t Boot_IAP_DownloadHandler(void);


#endif /* _BOOT_H_ */
