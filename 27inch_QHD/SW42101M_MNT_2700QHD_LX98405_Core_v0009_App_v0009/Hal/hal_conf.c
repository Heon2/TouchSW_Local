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

const tHalPwmdrvCommonConf_t *hal_pwmdrv_GetCommonConfig(void)
{
	return &s_kptHalCommonConf->tPWMDRV_Conf;
}

tHalInfo_t *hal_GetInfo(void)
{
    return s_ptHalInfo;
}

