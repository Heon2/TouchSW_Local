/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  hal_config.c
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

#ifndef _HAL_CONF_H_
#define _HAL_CONF_H_


typedef struct
{
	tMSPI_SCR_t tParam_SCR;
	tMSPI_SPIENA_t tParam_SPIENA;

} __PACKED tHalMspiCommonConf_t;

typedef struct
{
	tPWMDRV_GBL_t		tPWMDRV_GBL;
	tPWMDRV_INTR_CFG_t  tPWMDRV_INTR_CFG;
	uint32_t 			ulBeaconTable;
	uint8_t 			ucSelTsyncOut;
	uint16_t 			usPwmFreq;
	uint8_t 			ucPwmPreNum;
	uint8_t 			ucPwmSetNum;
	uint8_t 			ucPwmFingerActNum;
	uint8_t 			ucPwmFinger1LHBMuxNum;
	uint8_t				ucPwmPenPosActNum;
	uint8_t				ucPwmPenPos1LHBMuxNum;
	uint8_t 			ucPwmPenDataActNum;
	uint8_t 			ucPwmPenData1LHBMuxNum;
	uint8_t 			ucPwmPenFingerActNum;
	uint8_t 			ucPwmPenFinger1LHBMuxNum;
	uint8_t				ucPwmLpwgActiveActNum;
	uint8_t				ucPwmLpwgActive1LHBMuxNum;
	uint8_t				ucPwmLpwgIdleActNum;
	uint8_t				ucPwmLpwgIdle1LHBMuxNum;

	uint16_t			usPwmNiFreq1;
	uint8_t 			ucPwmNiActNum;
	uint8_t 			ucPwmNi1LHBMuxNum;

	uint16_t 			usFullFingerPWMIntervalDly;
	uint16_t			usPenPositionPWMIntervalDly;
	uint16_t 			usPenDataPWMIntervalDly;
	uint16_t			usPenFingerPWMIntervalDly;
	uint16_t			usLpwgActivePWMIntervalDly;
	uint16_t			usLpwgIdlePWMIntervalDly;

	tPWMDRV_PRE_0_t		tPWMDRV_PRE_0;
	tPWMDRV_PRE_1_t		tPWMDRV_PRE_1;
	tPWMDRV_PRE_2_t		tPWMDRV_PRE_2;
	tPWMDRV_EPLG_0_t	tPWMDRV_EPLG_0;
	tPWMDRV_EPLG_1_t	tPWMDRV_EPLG_1;
	tPWMDRV_EPLG_2_t	tPWMDRV_EPLG_2;
	tPWMDRV_PRLG_t		tPWMDRV_PRLG;

	tPWMDRV_FG_0_t		tPWMDRV_FG_0;
	tPWMDRV_FG_1_t		tPWMDRV_FG_1;

	tPWMDRV_PN_0_t		tPWMDRV_PN_0;
	tPWMDRV_PN_1_t		tPWMDRV_PN_1;

	tPWMDRV_IN_CTRL_t   tPWMDRV_IN_CTRL;
	tPWMDRV_ENA_PWM_t   tPWMDRV_ENA_PWM[ePWM_PARAM_MAX];

} __PACKED tHalPwmdrvCommonConf_t;

typedef struct
{
    uint8_t ucDeviceAddr;
} __PACKED tHalI2CCommonConf_t;

typedef struct
{
    uint8_t ucDummy;
} __PACKED tHalUSBCommonConf_t;

typedef struct
{
    tHalMspiCommonConf_t tMSPI_Conf;
    tHalPwmdrvCommonConf_t tPWMDRV_Conf;
    tHalI2CCommonConf_t tI2C_Conf;
    tHalUSBCommonConf_t tUSB_Conf;
} __PACKED tHalCommonConf_t;


typedef struct
{
	eSENSING_CHANGE_MODE_t eSensingChangeMode;
	eSENSING_MODE_t eSensingMode;

#if USED_ECLK_ON_OFF_CONTROL
	bool_t bIsECLKOnOffStart;
	bool_t bIsECLKOnOffStartCheckCnt;
#endif /* USED_ECLK_ON_OFF_CONTROL */

#if USED_TPIC_MUXEN_ON_OFF_CONTROL
	bool_t bIsTPICMuxEnOnOffStart;
	bool_t bIsTPICMuxEnOnOfftartCheckCnt;
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */

} tHalInfo_t;

extern void hal_SetCommonConfig(const tHalCommonConf_t * _p);
extern const tHalCommonConf_t *hal_GetCommonConfig(void);
extern const tHalMspiCommonConf_t *hal_mspi_GetCommonConfig(void);
extern const tHalPwmdrvCommonConf_t *hal_pwmdrv_GetCommonConfig(void);
extern tHalInfo_t *hal_GetInfo(void);

#endif /* _HAL_CONF_H_ */
