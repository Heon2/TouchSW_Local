/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : sric.c
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

#include "hal_def.h"
#include "module_def.h"
#if (USED_ROIC_DEF == ROIC_SW97500)
#include "ROIC\SW97500\roic_ctrl_sw97500.h"
#elif (USED_ROIC_DEF == ROIC_SW92502)
#include "ROIC\SW92502\roic_ctrl_sw92502.h"
#elif (USED_ROIC_DEF == ROIC_SW92503)
#include "ROIC\SW92503\roic_ctrl_sw92503.h"
#elif (USED_ROIC_DEF == ROIC_SW92503S)
#include "ROIC\SW92503S\roic_ctrl_sw92503S.h"
#elif (USED_ROIC_DEF == ROIC_SW92503B)
#include "ROIC\SW92503B\roic_ctrl_sw92503B.h"
#elif (USED_ROIC_DEF == ROIC_SWL92406)
#include "ROIC\SWL92406\roic_ctrl_swl92406.h"
#elif (USED_ROIC_DEF == ROIC_SW98500)
#include "ROIC\SW98500\roic_ctrl_sw98500.h"
#elif (USED_ROIC_DEF == ROIC_SWL92407)
#include "ROIC\SWL92407\roic_ctrl_swl92407.h"
#elif (USED_ROIC_DEF == ROIC_SW92505)
#include "ROIC\SW92505\roic_ctrl_sw92505.h"
#endif /* (USED_ROIC_DEF == ROIC_SW97500) */

extern __IO uint16_t sensingRowStart;

void (*Fncp_ROIC_Reset)(eSENSING_MODE_t eSensingMode);
bool_t (*Fncp_ROIC_RegisterInit)(eSENSING_MODE_t eSensingMode);
void (*Fncp_ROIC_Run)(uint8_t Enable);
#if USED_ADAPTIVE_LOCAL_SENSING
void (*Fncp_ROIC_SetRoicIndex)(uint32_t ulIdx);
#endif /* USED_ADAPTIVE_LOCAL_SENSING */
void (*Fncp_ROIC_SetLocalIndex)(uint32_t ulIdx);
bool_t (*Fncp_ROIC_S3Operation)(void);
void (*Fncp_ROIC_IdleOperation)(void);
void (*Fncp_ROIC_ActiveOperation)(void);
//void (*Fncp_ROIC_FingerPenFullModeChange)(bool_t bIsFullMode);
void (*Fncp_ROIC_SetRuntimeChangeRegigster)(eROIC_REG_SET_CHANGE_MODE_t eMode);
void (*Fncp_ROIC_DiagTestOperation)(eDIAG_TEST_CHANGE_MODE_t TestMode);
#if USED_RUNTIME_LOCAL_TUNE_RAWDATA
void (*Fncp_ROIC_RawDataLocalRuntimeCalibration)(void);
#endif /* USED_RUNTIME_LOCAL_TUNE_RAWDATA */
#if USED_RAWDATA_TUNE_CALIBRATION
void (*Fncp_ROIC_RawDataCalibration)(void);
#endif /* USED_RAWDATA_TUNE_CALIBRATION */


void SRIC_Initialize(void)
{
#if (USED_ROIC_DEF == ROIC_SW97500)
	SW97500_Initialize();
	Fncp_ROIC_Reset = &SW97500_Reset;
	Fncp_ROIC_RegisterInit = &SW97500_RegisterInit;
	Fncp_ROIC_Run = &SW97500_Run;
	Fncp_ROIC_S3Operation = &SW97500_SetS3OperationMode;
	Fncp_ROIC_IdleOperation = &SW97500_SetIdleOperationMode;
	Fncp_ROIC_DiagTestOperation = &SW97500_SetDiagTestOperationMode;
	Fncp_ROIC_ActiveOperation = &SW97500_SetActiveOperationMode;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW97500_SetRuntimeChangeRegister;
#if USED_RUNTIME_LOCAL_TUNE_RAWDATA
	Fncp_ROIC_RawDataLocalRuntimeCalibration = &SW97500_RawDataLocalRuntimeCalibration;
#endif /* USED_RUNTIME_LOCAL_TUNE_RAWDATA */
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW97500_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#elif (USED_ROIC_DEF == ROIC_SW98500)
	SW98500_Initialize();
	Fncp_ROIC_Reset = &SW98500_Reset;
	Fncp_ROIC_RegisterInit = &SW98500_RegisterInit;
	Fncp_ROIC_Run = &SW98500_Run;
	Fncp_ROIC_SetLocalIndex = &SW98500_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW98500_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW98500_SetActiveOperationMode;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW98500_SetRuntimeChangeRegister;
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW98500_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#elif (USED_ROIC_DEF == ROIC_SW92502)
	SW92502_Initialize();
	Fncp_ROIC_Reset = &SW92502_Reset;
	Fncp_ROIC_RegisterInit = &SW92502_RegisterInit;
	Fncp_ROIC_Run = &SW92502_Run;
	Fncp_ROIC_IdleOperation = &SW92502_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW92502_SetActiveOperationMode;
#elif (USED_ROIC_DEF == ROIC_SW92503)
	SW92503_Initialize();
	Fncp_ROIC_Reset = &SW92503_Reset;
	Fncp_ROIC_RegisterInit = &SW92503_RegisterInit;
	Fncp_ROIC_Run = &SW92503_Run;
	Fncp_ROIC_SetLocalIndex = &SW92503_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW92503_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW92503_SetActiveOperationMode;
//	Fncp_ROIC_FingerPenFullModeChange = &SW92503_SetFingerPenFullModeChange;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW92503_SetRuntimeChangeRegister;
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW92503_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#elif (USED_ROIC_DEF == ROIC_SW92503B)
	SW92503B_Initialize();
	Fncp_ROIC_Reset = &SW92503B_Reset;
	Fncp_ROIC_RegisterInit = &SW92503B_RegisterInit;
	Fncp_ROIC_Run = &SW92503B_Run;
	Fncp_ROIC_SetLocalIndex = &SW92503B_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW92503B_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW92503B_SetActiveOperationMode;
//	Fncp_ROIC_FingerPenFullModeChange = &SW92503B_SetFingerPenFullModeChange;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW92503B_SetRuntimeChangeRegister;
	Fncp_ROIC_DiagTestOperation = &SW92503B_SetDiagTestOperationMode;
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW92503B_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#elif (USED_ROIC_DEF == ROIC_SW92503S)
	SW92503S_Initialize();
	Fncp_ROIC_Reset = &SW92503S_Reset;
	Fncp_ROIC_RegisterInit = &SW92503S_RegisterInit;
	Fncp_ROIC_Run = &SW92503S_Run;
	Fncp_ROIC_SetLocalIndex = &SW92503S_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW92503S_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW92503S_SetActiveOperationMode;
//	Fncp_ROIC_FingerPenFullModeChange = &SW92503S_SetFingerPenFullModeChange;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW92503S_SetRuntimeChangeRegister;
	Fncp_ROIC_DiagTestOperation = &SW92503S_SetDiagTestOperationMode;
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW92503S_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#elif (USED_ROIC_DEF == ROIC_SWL92406)
	SWL92406_Initialize();
	Fncp_ROIC_Reset = &SWL92406_Reset;
	Fncp_ROIC_RegisterInit = &SWL92406_RegisterInit;
	Fncp_ROIC_Run = &SWL92406_Run;
	Fncp_ROIC_SetLocalIndex = &SWL92406_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SWL92406_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SWL92406_SetActiveOperationMode;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SWL92406_SetRuntimeChangeRegister;
#elif (USED_ROIC_DEF == ROIC_SWL92407)
	SWL92407_Initialize();
	Fncp_ROIC_Reset = &SWL92407_Reset;
	Fncp_ROIC_RegisterInit = &SWL92407_RegisterInit;
	Fncp_ROIC_Run = &SWL92407_Run;
#if USED_ADAPTIVE_LOCAL_SENSING
	Fncp_ROIC_SetRoicIndex = &SWL92407_SetRoicIndex;
#endif /* USED_ADAPTIVE_LOCAL_SENSING */
	Fncp_ROIC_SetLocalIndex = &SWL92407_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SWL92407_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SWL92407_SetActiveOperationMode;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SWL92407_SetRuntimeChangeRegister;
#elif (USED_ROIC_DEF == ROIC_SW92505)
	SW92505_Initialize();
	Fncp_ROIC_Reset = &SW92505_Reset;
	Fncp_ROIC_RegisterInit = &SW92505_RegisterInit;
	Fncp_ROIC_Run = &SW92505_Run;
	Fncp_ROIC_SetLocalIndex = &SW92505_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW92505_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW92505_SetActiveOperationMode;
//	Fncp_ROIC_FingerPenFullModeChange = &SW92503S_SetFingerPenFullModeChange;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW92505_SetRuntimeChangeRegister;
	Fncp_ROIC_DiagTestOperation = &SW92505_SetDiagTestOperationMode;
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW92505_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#endif /* (USED_ROIC_DEF == ROIC_SW97500) */
}

void SRIC_Reset(eSENSING_MODE_t eSensingMode)
{
	Fncp_ROIC_Reset(eSensingMode);
}

bool_t SRIC_RegisterInit(eSENSING_MODE_t eSensingMode)
{
	bool_t bReg = YES;
	bReg = Fncp_ROIC_RegisterInit(eSensingMode);
#if USED_MNT_S3_MODE_FUNCTION
	if(bReg && IS_S3_MODE(eSensingMode))
	{
		bReg = Fncp_ROIC_S3Operation();
	}
#endif /* USED_MNT_S3_MODE_FUNCTION */

	return bReg;
}

void SRIC_Run(uint8_t Enable)
{
	Fncp_ROIC_Run(Enable);
}

#if USED_ADAPTIVE_LOCAL_SENSING
void SRIC_SetRoicIndex(uint32_t ulIdx)
{
	MSPI_Set_TLPMODE();
	Fncp_ROIC_SetRoicIndex(ulIdx);
	MSPI_Set_AITMODE(HAL_GetSensingMode());
}
#endif /* USED_ADAPTIVE_LOCAL_SENSING */

void SRIC_SetLocalIndex(uint32_t ulIdx)
{
	MSPI_Set_TLPMODE();
	Fncp_ROIC_SetLocalIndex(ulIdx);
	MSPI_Set_AITMODE(HAL_GetSensingMode());
}

void SRIC_SetIdleOperationMode(void)
{
	MSPI_Set_TLPMODE();
	Fncp_ROIC_IdleOperation();
	MSPI_Set_AITMODE(HAL_GetSensingMode());
	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
}

void SRIC_SetActiveOperationMode(void)
{
	MSPI_Set_TLPMODE();
	Fncp_ROIC_ActiveOperation();
	MSPI_Set_AITMODE(HAL_GetSensingMode());
	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
}

void SRIC_SetDiagTestOperationMode(eDIAG_TEST_CHANGE_MODE_t TestMode)
{
	MSPI_Set_TLPMODE();
	Fncp_ROIC_DiagTestOperation(TestMode);
	MSPI_Set_AITMODE(HAL_GetSensingMode());
	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
}

//void SRIC_SetFingerPenFullModeChange(bool_t bIsFullMode)
//{
//	MSPI_Set_TLPMODE();
//	Fncp_ROIC_FingerPenFullModeChange(bIsFullMode);
//	MSPI_Set_AITMODE(HAL_GetSensingMode());
////	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
//}

void SRIC_SetRuntimeChangeRegister(eROIC_REG_SET_CHANGE_MODE_t eMode)
{
	MSPI_Set_TLPMODE();
	Fncp_ROIC_SetRuntimeChangeRegigster(eMode);
#if USED_PEN_MODE_OPERATION
#if (USED_MODULE_DEF == MODULE_DEF_L_1)
	Fncp_ROIC_SetLocalIndex(sensingRowStart);
#else /* (USED_MODULE_DEF == MODULE_DEF_L_1) */
	if(eMode != ROIC_REG_SET_CHANGE_FINGER_PEN_FULL &&
		eMode != ROIC_REG_SET_CHANGE_FINGER_PEN_LOCAL_IDLE)
	{
		Fncp_ROIC_SetLocalIndex(sensingRowStart);
	}
#endif /* (USED_MODULE_DEF == MODULE_DEF_L_1) */
#endif /* USED_PEN_MODE_OPERATION */

	MSPI_Set_AITMODE(HAL_GetSensingMode());
}

#if USED_RUNTIME_LOCAL_TUNE_RAWDATA
void SRIC_RawDataLocalRuntimeCalibration(void)
{
	Fncp_ROIC_RawDataLocalRuntimeCalibration();
}
#endif /* USED_RUNTIME_LOCAL_TUNE_RAWDATA */

#if USED_RAWDATA_TUNE_CALIBRATION
void SRIC_RawDataCalibration(void)
{
	Fncp_ROIC_RawDataCalibration();
}
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
