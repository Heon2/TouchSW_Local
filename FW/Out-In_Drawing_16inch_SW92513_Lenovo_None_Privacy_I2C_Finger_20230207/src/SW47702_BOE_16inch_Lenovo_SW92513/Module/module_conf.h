/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  module_conf.h
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

#ifndef _MODULE_CONF_H_
#define _MODULE_CONF_H_


#include "module.h"


typedef struct
{
#if ((USED_ROIC_DEF == ROIC_SW98500) || (USED_ROIC_DEF == ROIC_SW98502))
	#if USED_SPI_NBIT_TRANSMODE
		uint16_t ulFullSensing_Remap_Table[MSPI_ROW_MAX_MUX*ROIC_ALIGNED_ROW_LEN][COL_MAX];
	#else /* USED_SPI_NBIT_TRANSMODE */
		uint16_t ulFullSensing_Remap_Table[ROW_MAX][COL_MAX];
		uint16_t ulLocalSensing_Remap_Table[ROW_MAX][COL_MAX];
	#endif /* USED_SPI_NBIT_TRANSMODE */
#else /* ((USED_ROIC_DEF == ROIC_SW98500) || (USED_ROIC_DEF == ROIC_SW98502)) */
	#if USED_ESD_RECOVERY_SENSING_WITHOUT_MODULATION
		uint16_t ulFullSensing_Remap_Table[ROW_MAX + (FINGER_ESD_SCAN_MUX_NUM * ROIC_ALIGNED_ROW_LEN)][COL_MAX];
	#else
		uint16_t ulFullSensing_Remap_Table[ROW_MAX][COL_MAX];
	#endif
#endif /* ((USED_ROIC_DEF == ROIC_SW98500) || (USED_ROIC_DEF == ROIC_SW98502)) */
} __PACKED tModuleFixedConf_t;


typedef struct
{
    tModuleSRICCommonConf_t tSRIC_Conf;

} __PACKED tModuleCommonConf_t;

typedef struct
{
    uint8_t ucOvrShift;
    uint8_t ucIdleOvrShift;
    uint8_t ucLocalOvrShift;
    uint8_t ucLocalIdleOvrShift;
	uint8_t ucLocalOvrShift_Ring;
} __PACKED tModuleModeConf_t;


typedef struct
{
	uint8_t ucTxLessCol;
	uint8_t ucTxLessRow;
	uint8_t ucScreenCol;
	uint8_t ucScreenRow;
	uint8_t ucOvrShift;

	uint32_t uiVSyncRateInit;
	uint32_t uiVSyncChangeCnt;
	uint32_t uiVSyncRateLcdOff;
	uint8_t ucVSyncChangeCntThd;
	uint8_t ucVSyncRateGapThd;

	volatile bool_t bApplied;
	volatile bool_t bContOrShot_Sensing;
	volatile uint8_t ucVSyncSkipNum;
	volatile uint8_t ucVSyncCnt;
	volatile bool_t bLcdOff;

} __PACKED tModuleInfo_t;

/*
 * Methods
 */
extern void module_SetFixedConfig(const tModuleFixedConf_t* p);
extern const tModuleFixedConf_t* module_GetFixedConfig(void);
extern void module_SetCommonConfig(const tModuleCommonConf_t * _p);
extern const tModuleCommonConf_t *module_GetCommonConfig(void);
extern const tModuleSRICCommonConf_t * module_SRIC_GetCommonConfig(void);
extern void module_SetModeConfig(const tModuleModeConf_t * _p);
extern const tModuleModeConf_t *module_GetModeConfig(void);

extern tModuleInfo_t *module_GetInfo(void);

#endif /* _MODULE_CONF_H_ */
