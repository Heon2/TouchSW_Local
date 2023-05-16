/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  app_info.h
 * created on :  17. 4. 2017
 * Author :  mhjang
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

#ifndef _APP_INFO_H_
#define _APP_INFO_H_


typedef struct
{
	uint16_t usBootCompVer;
	uint16_t usAppVer;
	uint16_t usConfigVer;
	uint16_t usUsedConfigFile;
	uint16_t usAppMemSize;
	uint16_t usConfigMemSize;
	uint16_t usAppVID;
	uint16_t usAppPID;

} tAppConfigGenInfo_t;

typedef struct
{
	uint16_t usBootCompVer;
	uint16_t usAppVer;
	uint16_t usConfigCompVer;
	uint16_t usUsedConfigFile;
	uint16_t usAppMemSize;
	uint16_t usConfigMemSize;
	uint16_t usAppVID;
	uint16_t usAppPID;
	uint32_t usCRCValue;

} tAppTailInfo_t;

typedef struct
{
	uint16_t usConfigVer;
	uint16_t usConfigMemSize;
	uint32_t usCRCValue;

} tConfigTailInfo_t;


#endif /* _APP_INFO_H_ */

