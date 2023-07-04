/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : module_conf.c
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
#include "module_def.h"


static const tModuleFixedConf_t * s_kptModuleFixedConf = NULL;
static const tModuleCommonConf_t * s_kptModuleCommonConf = NULL;
static const tModuleModeConf_t * s_kptModuleConf = NULL;
static tModuleInfo_t * s_ptModuleInfo = &(tModuleInfo_t) {
	.uiVSyncRateInit = 60 * 10,
	.uiVSyncChangeCnt = 0,
};

void module_SetFixedConfig(const tModuleFixedConf_t* p)
{
	s_kptModuleFixedConf = p;
}

const tModuleFixedConf_t* module_GetFixedConfig(void)
{
    return s_kptModuleFixedConf;
}

void module_SetCommonConfig(const tModuleCommonConf_t * _p)
{
	s_kptModuleCommonConf = _p;
}

const tModuleCommonConf_t *module_GetCommonConfig(void)
{
    return s_kptModuleCommonConf;
}

//const tModuleSRICCommonConf_t * module_SRIC_GetCommonConfig(void)
//{
//	return &s_kptModuleCommonConf->tSRIC_Conf;
//}

void module_SetModeConfig(const tModuleModeConf_t * _p)
{
	s_kptModuleConf = _p;
}

const tModuleModeConf_t *module_GetModeConfig(void)
{
    return s_kptModuleConf;
}

tModuleInfo_t *module_GetInfo(void)
{
    return s_ptModuleInfo;
}

