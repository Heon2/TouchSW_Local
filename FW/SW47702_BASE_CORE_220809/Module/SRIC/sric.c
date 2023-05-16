/******************************************************************************************************
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
#elif (USED_ROIC_DEF == ROIC_SW98500)
#include "ROIC\SW98500\roic_ctrl_sw98500.h"
#elif (USED_ROIC_DEF == ROIC_SW92505)
#include "ROIC\SW92505\roic_ctrl_sw92505.h"
#elif (USED_ROIC_DEF == ROIC_SW98502)
#include "ROIC\SW98502\roic_ctrl_sw98502.h"
#elif (USED_ROIC_DEF == ROIC_SW92510)
#include "ROIC\SW92510\roic_ctrl_sw92510.h"
#elif (USED_ROIC_DEF == ROIC_SW92508)
#include "ROIC\SW92508\roic_ctrl_sw92508.h"
#elif (USED_ROIC_DEF == ROIC_SW92509)
#include "ROIC\SW92509\roic_ctrl_sw92509.h"
#elif (USED_ROIC_DEF == ROIC_SW92511)
#include "ROIC\SW92511\roic_ctrl_sw92511.h"
#elif (USED_ROIC_DEF == ROIC_SW92512)
#include "ROIC\SW92512\roic_ctrl_sw92512.h"
#elif (USED_ROIC_DEF == ROIC_SW92513)
#include "ROIC\SW92513\roic_ctrl_sw92513.h"
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
#if USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml
bool_t (*Fncp_ROIC_RegisterCheck)(eSENSING_MODE_t eSensingMode);
#endif /* USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml */


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
#elif (USED_ROIC_DEF == ROIC_SW98502)
	SW98502_Initialize();
	Fncp_ROIC_Reset = &SW98502_Reset;
	Fncp_ROIC_RegisterInit = &SW98502_RegisterInit;
	Fncp_ROIC_Run = &SW98502_Run;
	Fncp_ROIC_SetLocalIndex = &SW98502_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW98502_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW98502_SetActiveOperationMode;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW98502_SetRuntimeChangeRegister;
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW98502_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#elif (USED_ROIC_DEF == ROIC_SW92510)
	SW92510_Initialize();
	Fncp_ROIC_Reset = &SW92510_Reset;
	Fncp_ROIC_RegisterInit = &SW92510_RegisterInit;
	Fncp_ROIC_Run = &SW92510_Run;
	Fncp_ROIC_SetLocalIndex = &SW92510_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW92510_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW92510_SetActiveOperationMode;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW92510_SetRuntimeChangeRegister;
	Fncp_ROIC_DiagTestOperation = &SW92510_SetDiagTestOperationMode;
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW92510_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#if USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml
	Fncp_ROIC_RegisterCheck = &SW92510_RegisterCheck;
#endif /* USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml */
#elif (USED_ROIC_DEF == ROIC_SW92508)
	SW92508_Initialize();
	Fncp_ROIC_Reset = &SW92508_Reset;
	Fncp_ROIC_RegisterInit = &SW92508_RegisterInit;
	Fncp_ROIC_Run = &SW92508_Run;
	Fncp_ROIC_SetLocalIndex = &SW92508_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW92508_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW92508_SetActiveOperationMode;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW92508_SetRuntimeChangeRegister;
	Fncp_ROIC_DiagTestOperation = &SW92508_SetDiagTestOperationMode;
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW92508_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#if USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml
	Fncp_ROIC_RegisterCheck = &SW92508_RegisterCheck;
#endif /* USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml */
#elif (USED_ROIC_DEF == ROIC_SW92509)
	SW92509_Initialize();
	Fncp_ROIC_Reset = &SW92509_Reset;
	Fncp_ROIC_RegisterInit = &SW92509_RegisterInit;
	Fncp_ROIC_Run = &SW92509_Run;
	Fncp_ROIC_SetLocalIndex = &SW92509_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW92509_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW92509_SetActiveOperationMode;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW92509_SetRuntimeChangeRegister;
	Fncp_ROIC_DiagTestOperation = &SW92509_SetDiagTestOperationMode;
#if USED_RUNTIME_LOCAL_TUNE_RAWDATA
	Fncp_ROIC_RawDataLocalRuntimeCalibration = &SW92509_RawDataLocalRuntimeCalibration;
#endif /* USED_RUNTIME_LOCAL_TUNE_RAWDATA */
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW92509_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#elif (USED_ROIC_DEF == ROIC_SW92511)
	SW92511_Initialize();
	Fncp_ROIC_Reset = &SW92511_Reset;
	Fncp_ROIC_RegisterInit = &SW92511_RegisterInit;
	Fncp_ROIC_Run = &SW92511_Run;
	Fncp_ROIC_SetLocalIndex = &SW92511_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW92511_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW92511_SetActiveOperationMode;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW92511_SetRuntimeChangeRegister;
	Fncp_ROIC_DiagTestOperation = &SW92511_SetDiagTestOperationMode;
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW92511_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#elif (USED_ROIC_DEF == ROIC_SW92512)
	SW92512_Initialize();
	Fncp_ROIC_Reset = &SW92512_Reset;
	Fncp_ROIC_RegisterInit = &SW92512_RegisterInit;
	Fncp_ROIC_Run = &SW92512_Run;
	Fncp_ROIC_SetLocalIndex = &SW92512_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW92512_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW92512_SetActiveOperationMode;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW92512_SetRuntimeChangeRegister;
	Fncp_ROIC_DiagTestOperation = &SW92512_SetDiagTestOperationMode;
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW92512_RawDataCalibration;
#endif /* USED_RAWDATA_TUNE_CALIBRATION */
#elif (USED_ROIC_DEF == ROIC_SW92513)
	SW92513_Initialize();
	Fncp_ROIC_Reset = &SW92513_Reset;
	Fncp_ROIC_RegisterInit = &SW92513_RegisterInit;
	Fncp_ROIC_Run = &SW92513_Run;
	Fncp_ROIC_SetLocalIndex = &SW92513_SetLocalIndex;
	Fncp_ROIC_IdleOperation = &SW92513_SetIdleOperationMode;
	Fncp_ROIC_ActiveOperation = &SW92513_SetActiveOperationMode;
	Fncp_ROIC_SetRuntimeChangeRegigster = &SW92513_SetRuntimeChangeRegister;
	Fncp_ROIC_DiagTestOperation = &SW92513_SetDiagTestOperationMode;
#if USED_RAWDATA_TUNE_CALIBRATION
	Fncp_ROIC_RawDataCalibration = &SW92513_RawDataCalibration;
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
#if (CUSTOMER != MODEL_DEF_FHD_92513_LENOVO)
	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#endif
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
	if(eMode == ROIC_REG_SET_CHANGE_Full_To_Local ||
		eMode == ROIC_REG_SET_CHANGE_LocalIdle_To_Local)
	{
	#if USED_PEN_DATA_AFE_GAIN_OTHER_SET
		Fncp_ROIC_SetLocalIndex(0xC0000000 | sensingRowStart);
	#else /* USED_PEN_DATA_AFE_GAIN_OTHER_SET */
		Fncp_ROIC_SetLocalIndex(sensingRowStart);
	#endif /* USED_PEN_DATA_AFE_GAIN_OTHER_SET */
	}
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

#if USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml
bool_t SRIC_RegisterCheckEveryFrame(eSENSING_MODE_t eSensingMode)
{
	return Fncp_ROIC_RegisterCheck(eSensingMode);
}
#endif /* USED_ESD_RECOERY_DETECTION_ROIC_Abnoraml */
