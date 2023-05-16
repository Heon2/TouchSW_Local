/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : roic_ctrl_SW92510.h
 * created on : 29. 12. 2020
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

#ifndef ROIC_CTRL_SW92512_H_
#define ROIC_CTRL_SW92512_H_


#define SW92512_MAX_LHB_NUM			(16)


extern void SW92512_Initialize(void);
extern void SW92512_Reset(eSENSING_MODE_t eSensingMode);
extern bool_t SW92512_RegisterInit(eSENSING_MODE_t eSensingMode);
extern void SW92512_Run(uint8_t Enable);
extern void SW92512_SetLocalIndex(uint32_t ulIdx);
extern void SW92512_SetIdleOperationMode(void);
extern void SW92512_SetActiveOperationMode(void);
//extern void SW92512_SetFingerPenFullModeChange(bool_t bIsFullMode);
extern void SW92512_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode);
extern void SW92512_SetDiagTestOperationMode(eDIAG_TEST_CHANGE_MODE_t TestMode);

#if USED_RAWDATA_TUNE_CALIBRATION
extern void SW92512_RawDataCalibration(void);
#endif /* USED_RAWDATA_TUNE_CALIBRATION */

#endif /* ROIC_CTRL_SW92512_H_ */
