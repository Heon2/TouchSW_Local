/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_conf.c
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

#include "core_def.h"


static const tAppCommonConf_t * s_kptAppCommonConf = NULL;
#ifdef _USE_WITH_BOOT_
static tAppInfo_t * s_ptAppInfo = &(tAppInfo_t) {
#else
tAppInfo_t * s_ptAppInfo = &(tAppInfo_t) {
#endif
    /*
     * Operation Mode
     */
    .lEnterIdleModeCnt = 0,
    .bBlockESDDetection = NO,

    /*
     * Idle Mode Handling
     */
    .iIdleModeFrameCnt = 0,

    /*
     * Nose Handling
     */
#if USED_NOISE_HOPPING_FREQ
	.eNoiseStatus = NOISE_NONE,
	.eSelectFreq = FREQ_MAIN,
	.eHoppingStatus = FREQ_HOPPING_NONE,
	.ucHoppFrameCnt = 0,
#endif /* USED_NOISE_HOPPING_FREQ */
};

void app_SetCommonConfig(const tAppCommonConf_t *_p)
{
	s_kptAppCommonConf = _p;
}

const tAppCommonConf_t *app_GetCommonConfig(void)
{
    return s_kptAppCommonConf;
}

tAppInfo_t *app_GetInfo(void)
{
    return s_ptAppInfo;
}
