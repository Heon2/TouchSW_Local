/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _timer.h
 * created on : 10. 05. 2019
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

#ifndef __TIMER_H_
#define __TIMER_H_


/* ================================================================================ */
/* ================           TIMER Control Registers              ================ */
/* ================================================================================ */

/* ================================================================================ */
/* ================           TIMER Control Registers              ================ */
/* ================================================================================ */
typedef union
{
    struct {
        unsigned    timer0_en:                 1;
        unsigned    int_timer0_en:             1;
        unsigned    timer1_en:                 1;
        unsigned    int_timer1_en:             1;
        unsigned    timer2_en:                 1;
        unsigned    int_timer2_en:             1;
        unsigned    timer3_en:                 1;
        unsigned    int_timer3_en:             1;
        unsigned    reserved:                  24;
    } tBit;
    __IO uint32_t w;
} t_TIMER_CTRL;

typedef union
{
    struct {
        unsigned    timer_reload_val:         20;
        unsigned    timer_prev_val:           3;
        unsigned    reserved:                 9;
    } tBit;
    __IO uint32_t w;
} t_TIMER_RELOAD;

typedef union
{
    struct {
        unsigned    timer0_os_start:           1;
        unsigned    timer1_os_start:           1;
        unsigned    timer2_os_start:           1;
        unsigned    timer3_os_start:           1;
        unsigned    reserved:                  28;
    } tBit;
    __IO uint32_t w;
} t_TIMER_OS_START;

typedef union
{
    struct {
        unsigned    timer0_int_clr:            1;
        unsigned    timer1_int_clr:            1;
        unsigned    timer2_int_clr:            1;
        unsigned    timer3_int_clr:            1;
        unsigned    reserved:                  28;
    } tBit;
    __IO uint32_t w;
} t_TIMER_INT_CLR;

typedef union
{
    struct {
        unsigned    timer0_status:             1;
        unsigned    timer1_status:             1;
        unsigned    timer2_status:             1;
        unsigned    timer3_status:             1;
        unsigned    reserved:                  28;
    } tBit;
    __IO uint32_t w;
} t_TIMER_STATUS;


// __PACKED typedef struct
typedef struct
{
    __IO t_TIMER_CTRL                TIMER_CTRL;                     //0x0067
    __IO t_TIMER_RELOAD              TIMER_RELOAD[4];                //0x0068~0x006B
    __O  t_TIMER_OS_START            TIMER_OS_START;                 //0x006C
    __O  t_TIMER_INT_CLR             TIMER_INT_CLR;                  //0x006D
    __I  uint32_t                    TIMER_VALUE[4];                 //0x006E~0x0071
    __I  t_TIMER_STATUS              TIMER_STATUS;                   //0x0072
    __IO uint32_t                    SYS_DUMMY2;                     //0x0073
    __IO uint32_t                    SYS_DUMMY3;                     //0x0074
    __IO uint32_t                    GPIO_RESERVED06;                //0x0075
    __IO uint32_t                    GPIO_RESERVED07;                //0x0076
    __IO uint32_t                    GPIO_RESERVED08;                //0x0077
    __IO uint32_t                    GPIO_RESERVED09;                //0x0078
    __IO uint32_t                    GPIO_RESERVED10;                //0x0079
    __IO uint32_t                    GPIO_RESERVED11;                //0x007A
    __IO uint32_t                    GPIO_RESERVED12;                //0x007B
    __IO uint32_t                    GPIO_RESERVED13;                //0x007C
    __IO uint32_t                    GPIO_RESERVED14;                //0x007D
    __IO uint32_t                    GPIO_RESERVED15;                //0x007E
    __IO uint32_t                    GPIO_RESERVED16;                //0x007F
} tTIMER_CtrlReg_t;


#endif /* __TIMER_H_ */
