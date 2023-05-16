/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  param_config_sric.h
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

#include "param_def.h"


#if defined(_USE_COMPRESSED_CONFIG_)
tParamFixedMainSet_t ktParamFixed;
tParamFixedMainSet_t ktCustomFixed_Data =
#else /* defined(_USE_COMPRESSED_CONFIG_) */
const tParamFixedMainSet_t ktParamFixedMainConf =
#endif /* defined(_USE_COMPRESSED_CONFIG_) */
{
	.tModuleFixedConf =
	{
#if ((USED_ROIC_DEF == ROIC_SWL92406) || (USED_ROIC_DEF == ROIC_SWL92407))
		.ulPartialSensing_MsPen_RemapTable =
		{
			PARTIAL_SENSING_REMAP_TABLE_MSPEN
		},
		.ulPartialSensing_WacomPen_RemapTable =
		{
			PARTIAL_SENSING_REMAP_TABLE_WACOMPEN
		}
#else /* (USED_ROIC_DEF == ROIC_SWL92406) */
		.ulFullSensing_Remap_Table =
		{
			FULL_SENSING_REMAP_TABLE
		},
#if ((USED_ROIC_DEF == ROIC_SW98500) && USED_SPI_NBIT_TRANSMODE == NO)
		.ulLocalSensing_Remap_Table =
		{
			LOCAL_SENSING_REMAP_TABLE
		},
#endif /* ((USED_ROIC_DEF == ROIC_SW98500) && USED_SPI_NBIT_TRANSMODE == NO) */
#endif /* (USED_ROIC_DEF == ROIC_SWL92406) */
	}
};
