/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : protocol.c
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

#include "protocol_def.h"


tProtocolBufferPointers_t vtProtocolBufferPointers =
{
    NULL,//logging 格利狼 buffer double pointer
    NULL //Image, Test 格利狼 傍侩 buffer double pointer.
};

tProtocolGetter_t ktProtocolGetter  =
{
	.eReadyStatus = RS_NONE
};

tProtocolSetter_t ktProtocolSetter  =
{
	.eMode                  = M_TOUCH_NORMAL,
	.eEventTriggerType      = ETT_NONE,
	.bRecalibrate           = NO,
	.ePowerConsumptionState = PCS_ACTIVE,
	.ulGestureType          = 0,
	.bDisableESDAlert       = NO,
	.bChargerAttached       = NO,
	.bGloveSensingEnable    = NO,
	.bSensingOnWindowEnable = NO,
	.bPalmRejectionEnable   = NO,
	.bDisableEdgeExpand     = NO,
	.bEnableHandShake       = NO,
	.bApplyCoordinate       = NO,
};

tProtocolCtrl_t tProtocolCtrl  =
{
    .getter = &(ktProtocolGetter),
    .setter = &(ktProtocolSetter)
};

void (*protocol_Init)(void) ;
uint8_t* (*protocol_GetMappedPointer)(uint16_t addr) ;
void (*protocol_ClearInterrupt)(uint16_t addr) ;

#if !defined(USE_BOOTLOADER_CODE)
extern __IO int dfup;
#endif /* USE_BOOTLOADER_CODE */

void protocol_init(void)
{
#if !( defined(USE_BOOTLOADER_8KB) || defined(USE_BOOTLOADER_16KB) )
#if defined(_BOOTLOADER)
		protocol_Init               = &protocol_dfup_Init;
		protocol_GetMappedPointer   = &protocol_dfup_GetMappedPointer;
		protocol_ClearInterrupt     = &protocol_dfup_ClearInterrupt;
#else
		protocol_Init               = &protocol_swip_Init;
		protocol_GetMappedPointer   = &protocol_swip_GetMappedPointer;
		protocol_ClearInterrupt     = &protocol_swip_ClearInterrupt;
#endif
#else //USE_BOOTLOADER
		if (dfup)
		{
			protocol_Init 				= &protocol_dfup_Init;
			protocol_GetMappedPointer 	= &protocol_dfup_GetMappedPointer;
			protocol_ClearInterrupt 	= &protocol_dfup_ClearInterrupt;
		}
		else
		{
			protocol_Init 				= &protocol_swip_Init;
			protocol_GetMappedPointer 	= &protocol_swip_GetMappedPointer;
			protocol_ClearInterrupt 	= &protocol_swip_ClearInterrupt;
		}
#endif

    if( protocol_Init )
    {
    	(*protocol_Init)();
    }
}
