/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : env_types.h
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


#ifndef _ENV_TYPES_H_
#define _ENV_TYPES_H_


#include "module_types.h"
#include "hal_types.h"
#include "app_types.h"


typedef union
{
    uint8_t STRING[8];
    uint16_t HALFWORD[4];
    uint32_t WORD[2];
    uint64_t LONG;
} u8byteString_t;

typedef union
{
    uint32_t WORD;
    uint16_t HALFWORD[2];
    uint8_t BYTE[4];
} uTypes32_t;

typedef union
{
    uint64_t LONG;
    uint32_t WORD[2];
    uint16_t HALFWORD[4];
    uint8_t BYTE[8];
} uTypes64_t;

typedef struct
{
    int8_t rs;
    int8_t re;
    int8_t cs;
    int8_t ce;
} __PACKED tRect_t;

typedef struct
{
    int8_t c;
    int8_t r;
} __PACKED tCell_t;

typedef struct
{
    uint8_t b7Size      : 7;
    uint8_t b1Sign      : 1;
} __PACKED tSignedByteDataType_t;

#define datatypeof(expr)    \
        { .b7Size = sizeof(expr), .b1Sign = 1 }

#define unsigneddatatypeof(expr)    \
        { .b7Size = sizeof(expr), .b1Sign = 0 }


#endif /* _ENV_TYPES_H_ */
