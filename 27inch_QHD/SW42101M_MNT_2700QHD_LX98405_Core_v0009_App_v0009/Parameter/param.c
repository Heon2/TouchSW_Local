/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  param.c
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

#include "hal_def.h"
#include "param_def.h"


tParamFixedMainSet_t * s_ptParamFixedMainSet = &(tParamFixedMainSet_t) {0,};
tParamPreMainSet_t * s_ptParamPreMainSet = &(tParamPreMainSet_t) {0,};

static tParamModeConf_t * ptParamModeConf;
static tParamInfo_t *ptParamInfo = &(tParamInfo_t)
{
	.eParamMode = PARAM_MODE_NONE,
};

void PARAM_Initialize(void)
{
    memcpy(s_ptParamFixedMainSet, &ktParamFixedMainConf, sizeof(ktParamFixedMainConf));
    memcpy(s_ptParamPreMainSet, &ktParamPresetMainConf, sizeof(ktParamPresetMainConf));

    module_SetFixedConfig(&s_ptParamFixedMainSet->tModuleFixedConf);

    app_SetCommonConfig(&s_ptParamPreMainSet->tParamCommonConf.tApp);
    algorithm_SetCommonConfig(&s_ptParamPreMainSet->tParamCommonConf.tAlgorithm);
    protocol_SetCommonConfig(&s_ptParamPreMainSet->tParamCommonConf.tProtocol);
    hal_SetCommonConfig(&s_ptParamPreMainSet->tParamCommonConf.tHal);
    module_SetCommonConfig(&s_ptParamPreMainSet->tParamCommonConf.tModule);

    PARAM_MemConfigInIt();
}

void PARAM_MemConfigInIt(void)
{
    const tModuleCommonConf_t * _ptModuleCommonConf = module_GetCommonConfig();
    const tAlgorithmCommonConf_t * _ptAlogorithmCommonConf = algorithm_GetCommonConfig();

    /*
     * Update Memory Configurations of Reftrack module.
     */
 //   ptMemConf->iCol_        = _ptModuleCommonConf->ucScreenCol_;
 //   ptMemConf->iRamCol_     = _ptModuleCommonConf->ucScreenCol_ + (PAD_ * 2) + (_ptModuleCommonConf->ucScreenCol_ & 1); //must be a even number
 //   ptMemConf->iRow_        = _ptModuleCommonConf->ucScreenRow_;
 //   ptMemConf->iScreenNode_ = ptMemConf->iRow_ * ptMemConf->iCol_;

//    ptMemConf->iMaxTouch_   = _ptAlogorithmCommonConf->ucMaxTouch_;
//    ptMemConf->bSwapXY      = _ptModuleCommonConf->bIsSwapXY_;
//    ptMemConf->bFlipX       = _ptModuleCommonConf->bIsFlipX_;
}

void * PARAM_GetFixedMainSet(void)
{
	return s_ptParamFixedMainSet;
}

void * PARAM_GetPreMainSet(void)
{
	return s_ptParamPreMainSet;
}

void PARAM_InitConfig(void)
{
	ptParamModeConf = &s_ptParamPreMainSet->vtParamModeConf[ptParamInfo->eParamMode];

    algorithm_SetModeConfig(&ptParamModeConf->tAlgorithm);
    module_SetModeConfig(&ptParamModeConf->tModule);
}

void PARAM_SetMode(eParamMode_t _m)
{
    ptParamInfo->eParamMode = _m;
}

eParamMode_t PARAM_GetMode(void)
{
    return ptParamInfo->eParamMode;
}
