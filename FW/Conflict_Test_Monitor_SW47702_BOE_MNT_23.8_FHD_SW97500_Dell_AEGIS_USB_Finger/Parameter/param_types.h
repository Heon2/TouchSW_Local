/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  param_types.h
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

#ifndef _PARAM_TYPES_H_
#define _PARAM_TYPES_H_


typedef enum
{
	PARAM_MODE_NONE = -1,
	PARAM_MODE_NORMAL = 0,
	PARAM_MODE_NORMAL_1 = 1,
	PARAM_MODE_LIMIT = 2,

}  eParamMode_t;

#if USED_TOUCH_TUNING_PROCESS
typedef struct
{
	uint32_t DataType;
	uint32_t LocalIndex;

} __PACKED tParamTuningConf_t;
#endif /* USED_TOUCH_TUNING_PROCESS */

typedef struct
{
    tAppCommonConf_t tApp;
	tAlgorithmCommonConf_t tAlgorithm;
	tProtocolCommonConf_t tProtocol;
    tHalCommonConf_t tHal;
    tModuleCommonConf_t tModule;

} __PACKED tParamCommonConf_t;

typedef struct
{
    tAlgorithmModeConf_t tAlgorithm;
    tModuleModeConf_t tModule;

} __PACKED tParamModeConf_t;

typedef struct
{
	tModuleFixedConf_t tModuleFixedConf;

} __PACKED tParamFixedMainSet_t;

typedef struct
{
#if USED_TOUCH_TUNING_PROCESS
	tParamTuningConf_t tParamTuningConf;
#endif /* USED_TOUCH_TUNING_PROCESS */
	tParamCommonConf_t tParamCommonConf;
	tParamModeConf_t vtParamModeConf[PARAM_MODE_LIMIT];

} __PACKED tParamPreMainSet_t;

typedef struct
{
	eParamMode_t eParamMode;

} __PACKED tParamInfo_t;


#endif /* _PARAM_TYPES_H_ */
