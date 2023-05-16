/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : protocol.h
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

#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_


typedef enum
{
    RS_READY    = 0xA0,
    RS_NONE     = 0x05,
    RS_LOG      = 0x77,
    RS_IMAGE	= 0xAA
} __PACKED eProtocolReadyStatus_t;

typedef enum
{
    ETT_NONE,
    ETT_INTERRUPT,
    ETT_REGISTER
} eProtocolEventTriggerType_t;

/*
 * Control Registers
 */

typedef struct
{
    volatile eProtocolReadyStatus_t eReadyStatus;
    __IO bool_t bEventReady;
} __PACKED tProtocolGetter_t;


typedef enum
{
    M_TOUCH_NORMAL,
    M_TOUCH_DIAG,
    M_TOUCH_DFUP,
    M_PARAMETER,
    M_TOUCH_LPWG,
    M_CHECK_DNR,
    M_CHECK_DRTIME,
    M_CHECK_IRES,
    M_CHECK_CM,
    M_CHECK_STACK,
    M_CHECK_HOPPING_VALIDITY,
    M_CHECK_NOISE_SPECTRUM,
    M_CHECK_RAWDATA_ON_DELAY,
    M_GET_MAX_INTENSITY_ON_EACH_NODE,
    M_GET_OVERSAMPLE_BUFFER,
    M_GET_UNSORTED_OVERSAMPLE_BUFFER,
    M_WAIT,
    M_WATCH_DOG_RESET,
    M_LIMIT
} __PACKED eProtocolMode_t;

typedef struct
{
    volatile eProtocolMode_t eMode;
    volatile eProtocolEventTriggerType_t eEventTriggerType;
    volatile bool_t LocalIdxFixedEn;
    volatile uint8_t LocalIdx;
    volatile bool_t dummy3_1;
	volatile bool_t dummy3_2;
	volatile bool_t dummy3_3;
	volatile bool_t dummy3_4;
    volatile bool_t dummy4;
    volatile bool_t dummy5;
    volatile bool_t dummy6;
    volatile bool_t dummy7;
    volatile bool_t dummy8;
    volatile bool_t dummy9;
    volatile bool_t dummy10;
    volatile bool_t dummy11;
	volatile bool_t bDrawDebug;
	volatile bool_t bHID_TOUCH_OFF;
    volatile bool_t bEnableBulkLog;
    volatile bool_t bDFUP_Ready;

} __PACKED tProtocolSetter_t;

typedef struct
{
    const void* pGeneralBuffer;
    void* pParameterBuffer;
} __PACKED tProtocolBufferPointers_t;

typedef struct
{
    tProtocolGetter_t* getter;
    tProtocolSetter_t* setter;
} __PACKED tProtocolCtrl_t;

extern tProtocolBufferPointers_t vtProtocolBufferPointers;
extern tProtocolCtrl_t tProtocolCtrl;

extern uint8_t * (*protocol_GetMappedPointer)(uint16_t _addr);
extern void (*protocol_ClearInterrupt)(uint16_t _addr);

extern void protocol_init(void);


#endif /* _PROTOCOL_H_ */
