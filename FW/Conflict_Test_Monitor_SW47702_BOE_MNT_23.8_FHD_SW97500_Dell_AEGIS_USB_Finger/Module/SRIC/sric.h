/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : sric.h
 * created on : 17. 4. 2017
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

#ifndef SRIC_H_
#define SRIC_H_


#include "_sric.h"


#define PEN_TSYNC_BEACON		(0)
#define PEN_TSYNC_NOTUSED		(0)
#define PEN_TSYNC_FINGER		(1)
#define PEN_TSYNC_POSITION		(2)
#define PEN_TSYNC_DATA			(3)

typedef enum
{
	ROIC_0 		= 0,
	ROIC_1 		= 1,
	ROIC_ALL 	= 2,
	DEFAULT 	= 3
} eROICSelect_t;

#define R0_str_Adr				(0x300)
#define R1_str_Adr				(0x400)

#define R0(Address)				((Address) + R0_str_Adr)
#define R1(Address)				((Address) + R1_str_Adr)


extern void SRIC_Initialize(void);
extern void SRIC_Reset(eSENSING_MODE_t eSensingMode);
extern bool_t SRIC_RegisterInit(eSENSING_MODE_t eSensingMode);
extern void SRIC_Run(uint8_t Enable);
#if USED_ADAPTIVE_LOCAL_SENSING
extern void SRIC_SetRoicIndex(uint32_t ulIdx);
#endif /* USED_ADAPTIVE_LOCAL_SENSING */
extern void SRIC_SetLocalIndex(uint32_t ulIdx);
extern void SRIC_SetIdleOperationMode(void);
extern void SRIC_SetActiveOperationMode(void);
extern void SRIC_SetDiagTestOperationMode(eDIAG_TEST_CHANGE_MODE_t TestMode);
extern void SRIC_SetFingerPenFullModeChange(bool_t bIsFullMode);
extern void SRIC_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode);
#if USED_RUNTIME_LOCAL_TUNE_RAWDATA
extern void SRIC_RawDataLocalRuntimeCalibration(void);
#endif /* USED_RUNTIME_LOCAL_TUNE_RAWDATA */
#if USED_RAWDATA_TUNE_CALIBRATION
extern void SRIC_RawDataCalibration(void);
#endif /* USED_RAWDATA_TUNE_CALIBRATION */

#endif /* SRIC_H_ */

