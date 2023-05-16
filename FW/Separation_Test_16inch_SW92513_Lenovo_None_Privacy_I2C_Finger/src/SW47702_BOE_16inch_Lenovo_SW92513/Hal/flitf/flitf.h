/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : flitf.h
 * created on : 04. 28. 2020
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


#ifndef _FLITF_H_
#define _FLITF_H_


extern uint32_t FLITF_Calc32bitCheckSum(uint32_t * pCheckSumBuf, uint32_t ulWordSize);
extern bool_t FLITF_CheckTrimInfoSectionIntegrity(tFlashPTTrimCodeInfo_t * ptTrimmingCode);
extern bool_t FLITF_EnsureBootInterfaceCodeFlashIntegrity(void);
#if (USED_MODULE_DEF == MODULE_DEF_S_1)
extern void FLITF_TPInspectionInfoCodeFlashRead(uint8_t * _pBuf);
extern void FLITF_TPInspectionInfoCodeFlashWrite(uint8_t * _pBuf);
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
extern void FLITF_FlashInformationRegionWriteOperation(void);


#endif /* _FLITF_H_ */


