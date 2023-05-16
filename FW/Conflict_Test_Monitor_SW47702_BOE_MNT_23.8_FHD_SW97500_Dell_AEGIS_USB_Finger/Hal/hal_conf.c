/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : hal_conf.h
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

#include "hal_def.h"


static const tHalCommonConf_t * s_kptHalCommonConf  = NULL;
static tHalInfo_t * s_ptHalInfo = &(tHalInfo_t){
	.eSensingChangeMode = SM_CHANGE_COMPLETE,
	.eSensingMode = SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE,
#if USED_ECLK_ON_OFF_CONTROL
	.bIsECLKOnOffStart = NO,
	.bIsECLKOnOffStartCheckCnt = 0,
#endif /* USED_ECLK_ON_OFF_CONTROL */
#if USED_TPIC_MUXEN_ON_OFF_CONTROL
	.bIsTPICMuxEnOnOffStart = NO,
	.bIsTPICMuxEnOnOffStartCheckCnt = 0,
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
#if USED_TOUCH_REPORT_ON_OFF_CONTROL
	.bIsTouchReportOnOffStart = NO,
	.bIsTouchReportOnOffStartCheckCnt = 0,
#endif /* USED_TOUCH_REPORT_ON_OFF_CONTROL */
#if USED_S3_VDD_OE_INPUT_OUTPUT_CTRL
	.bIsS3VddOddEvenControlStart = NO,
	.bIsS3VddOddEvenControlStartCheckCnt = 0,
	.ucS3VddOddEvenStatus = GPIO_DATA_LOW,
	.bIsS3VddOddEvenControlFrameCheckCnt = 0,
#endif /* USED_S3_VDD_OE_INPUT_OUTPUT_CTRL */

#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
	.ulActivePenSettingType = ACTIVEPEN_TYPE_LOCAL_MS,
	.ulActivePenOPType = ACTIVEPEN_TYPE_LOCAL_MS,
	.ulActivePenRawDataType = ACTIVEPEN_TYPE_LOCAL_MS,
	.ulLocalFingerOPType = ACTIVEPEN_TYPE_LOCAL_MS,
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
	.ulActivePenSettingType = ACTIVEPEN_TYPE_LOCAL_MS,
	.ulActivePenOPType = ACTIVEPEN_TYPE_LOCAL_MS,
	.ulActivePenRawDataType = ACTIVEPEN_TYPE_LOCAL_MS,
	.ulLocalFingerOPType = ACTIVEPEN_TYPE_LOCAL_MS,
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN)
	.ulActivePenSettingType = ACTIVEPEN_TYPE_LOCAL_WACOM,
	.ulActivePenOPType = ACTIVEPEN_TYPE_LOCAL_WACOM,//ACTIVEPEN_TYPE_LOCAL_MS, ACTIVEPEN_TYPE_LOCAL_WACOM
	.ulActivePenRawDataType = ACTIVEPEN_TYPE_LOCAL_WACOM,
	.ulLocalFingerOPType = ACTIVEPEN_TYPE_LOCAL_WACOM,
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	.ulActivePenSettingType = ACTIVEPEN_TYPE_LOCAL_WGP,
	.ulActivePenOPType = ACTIVEPEN_TYPE_LOCAL_WGP,//ACTIVEPEN_TYPE_LOCAL_MS, ACTIVEPEN_TYPE_LOCAL_WACOM
	.ulActivePenRawDataType = ACTIVEPEN_TYPE_LOCAL_WGP,
	.ulLocalFingerOPType = ACTIVEPEN_TYPE_LOCAL_WGP,
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN) */

	.ulActivePenChangeType = ACTIVEPEN_CHANGE_DONE,

	.bIsPenDection = NO,
	.bIsPenTypeSwapCheckStart = NO,
	.ulPenTypeSwapCheckFrameCnt = 0,
#if (USED_MODULE_DEF == MODULE_DEF_L_1)
	.ulMSPenIdleOpFrameNumTHD = 5,
#else
	.ulMSPenIdleOpFrameNumTHD = 4,
#endif
	.ulWacomPenIdleOpFrameNumTHD = 4,

	.ulWGPBeaconType = PWM_WGP_PEN_SETTABLE_BEACON,
};

void hal_SetCommonConfig(const tHalCommonConf_t * _p)
{
	s_kptHalCommonConf = _p;
}

const tHalCommonConf_t *hal_GetCommonConfig(void)
{
    return s_kptHalCommonConf;
}

const tHalMspiCommonConf_t *hal_mspi_GetCommonConfig(void)
{
    return &s_kptHalCommonConf->tMSPI_Conf;
}

const tHalMspiControlConf_t *hal_mspi_GetControlConfig(void)
{
	return &s_kptHalCommonConf->tMSPI_Conf.tMSPIControlConf[s_ptHalInfo->ulActivePenSettingType];
}

const tHalPwmdrvCommonConf_t *hal_pwmdrv_GetCommonConfig(void)
{
	return &s_kptHalCommonConf->tPWMDRV_Conf;
}

const tHalPwmdrvControlConf_t *hal_pwmdrv_GetControlConfig(void)
{
	return &s_kptHalCommonConf->tPWMDRV_Conf.tPwmControlConf[s_ptHalInfo->ulActivePenSettingType];
}

void hal_Info_SetControlActivePenSettingType(eActivePenType_t eType)
{
	s_ptHalInfo->ulActivePenSettingType = eType;
}

eActivePenType_t hal_Info_GetControlActivePenSettingType(void)
{
	return s_ptHalInfo->ulActivePenSettingType;
}

void hal_Info_SetControlActivePenOPType(eActivePenType_t eType)
{
	s_ptHalInfo->ulActivePenOPType = eType;
}

eActivePenType_t hal_Info_GetControlActivePenOPType(void)
{
	return s_ptHalInfo->ulActivePenOPType;
}

void hal_Info_SetControlActivePenRawDataType(eActivePenType_t eType)
{
	s_ptHalInfo->ulActivePenRawDataType = eType;
}

eActivePenType_t hal_Info_GetControlActivePenRawDataType(void)
{
	return s_ptHalInfo->ulActivePenRawDataType;
}

void hal_Info_SetControlLocalFingerOPType(eActivePenType_t eType)
{
	s_ptHalInfo->ulLocalFingerOPType = eType;
}

eActivePenType_t hal_Info_GetControlLocalFingerOPType(void)
{
	return s_ptHalInfo->ulLocalFingerOPType;
}

void hal_Info_SetPenDectionEnable(bool_t bIsEn)
{
	s_ptHalInfo->bIsPenDection = bIsEn;
}

bool_t hal_Info_GetPenDectionEnable(void)
{
	return s_ptHalInfo->bIsPenDection;
}

void hal_Info_SetPenTypeSwapCheckEnable(bool_t bIsEn)
{
	s_ptHalInfo->bIsPenTypeSwapCheckStart = bIsEn;
}

uint32_t hal_Info_GetWGPPenBeaconType(void)
{
	return s_ptHalInfo->ulWGPBeaconType;
}

void hal_Info_SetWGPPenBeaconType(uint32_t ulType)
{
	s_ptHalInfo->ulWGPBeaconType = ulType;
}

uint32_t hal_Info_GetMPPPen1stBeaconType(void)
{
	return s_ptHalInfo->ulMPP1stBeaconType;
}

void hal_Info_SetMPPPen1stBeaconType(uint32_t ulType)
{
	s_ptHalInfo->ulMPP1stBeaconType = ulType;
}

tHalInfo_t *hal_GetInfo(void)
{
    return s_ptHalInfo;
}

