/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_conf.h
 * created on : 14. 5. 2019
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

#ifndef _APP_CONF_H_
#define _APP_CONF_H_


/*
 * Types
 */
typedef struct
{
    char vcProductCode[16];//u8byteString_t uProductCode;

	uint8_t ucFrameRate;
	uint8_t ucIdleFrameRate;

    /*
     * Idle Mode.
     */
    bool_t bUsedIdleModeCtrl;
    uint16_t ucIdleModeEnterSec;
    uint16_t ucPenLocalModeEnterSec;
    uint16_t HoppMainRollbackSec;

    /*
     * Frequency Hopping Settings.
     */
    bool_t bUseFreqHopp;
    eSENSING_FREQ_t MainFreq;
    eSENSING_FREQ_t HoppFreq1;
	eSENSING_FREQ_t HoppFreq2;

	uint8_t ucPenLocalModeChangeFrameCntTHD;
	uint8_t ucPenFullModeChangeFrameCntTHD;

} __PACKED tAppCommonConf_t;

typedef struct
{
	int iFrameCnt;
	volatile int lEnterIdleModeCnt;
	volatile bool_t bBlockESDDetection;

	/*
	* Idle Mode Handling
	*/
	int iIdleModeFrameCnt;
	int iFrameRate;

	/*
	* Noise Handling
	*/
#if USED_NOISE_HOPPING_FREQ
	eNoiseStatus_t eNoiseStatus;
	eSelectFREQ eCurrentSelectFreq;
	eSelectFREQ eSelectFreq;
	eHoppingStatus_t eHoppingStatus;
	uint8_t ucHoppFrameCnt;
#if USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE
	bool_t bIsNormalReadyIdleCheckCountMaintain;
	bool_t bIsHoppFreqBaseUpdateContinueCheckStart;
	uint32_t ulHoppFreqBaseUpdateFrameCheckCnt;
	uint32_t ulHoppFreqBaseUpdateContinueCheckCnt;
#endif /* USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE */
#endif /* USED_NOISE_HOPPING_FREQ */
} __PACKED tAppInfo_t;

/*
 * Default Methods
 */

extern void app_SetCommonConfig(const tAppCommonConf_t *_p);
extern const tAppCommonConf_t *app_GetCommonConfig(void);
extern tAppInfo_t *app_GetInfo(void);

#if USED_NOISE_HOPPING_FREQ
extern eSelectFREQ app_GetCurrentSelectFrequency(void);
extern void app_SetCurrentSelectFrequency(eSelectFREQ eSelFreq);
extern eSelectFREQ app_GetSelectFrequency(void);
extern void app_SetSelectFrequency(eSelectFREQ eSelFreq);
#endif /* USED_NOISE_HOPPING_FREQ */

#endif /* _APP_CONF_H_ */
