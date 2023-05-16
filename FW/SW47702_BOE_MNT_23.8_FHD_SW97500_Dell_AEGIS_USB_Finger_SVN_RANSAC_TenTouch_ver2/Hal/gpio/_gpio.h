/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _gpio.h
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

#ifndef __GPIO_H_
#define __GPIO_H_


/* ================================================================================ */
/* ================               GPIO Control Registers           ================ */
/* ================================================================================ */
typedef union
{
    struct {
        unsigned    GPIOM00:               1;
        unsigned    GPIOM01:               1;
        unsigned    GPIOM02:               1;
        unsigned    GPIOM03:               1;
        unsigned    GPIOM04:               1;
        unsigned    GPIOM05:               1;
        unsigned    GPIOM06:               1;
        unsigned    GPIOM07:               1;
        unsigned    GPIOM08:               1;
        unsigned    GPIOM09:               1;		//	ToDo: Added by register map
        unsigned    GPIOM10:               1;		//	ToDo: Added by register map
        unsigned    reserved:              21;
    } tBit;
    __IO uint32_t w;
} t_GPIOM_IN;

typedef union
{
    struct {
        unsigned    GPIOM00:               1;
        unsigned    GPIOM01:               1;
        unsigned    GPIOM02:               1;
        unsigned    GPIOM03:               1;
        unsigned    GPIOM04:               1;
        unsigned    GPIOM05:               1;
        unsigned    GPIOM06:               1;
        unsigned    GPIOM07:               1;
        unsigned    GPIOM08:               1;
        unsigned    GPIOM09:               1;
        unsigned    GPIOM10:               1;
        unsigned    reserved:              21;
    } tBit;
    __IO uint32_t w;
} t_GPIOM_OUT;

typedef union
{
    struct {
        unsigned    GPIOM00:               1;
        unsigned    GPIOM01:               1;
        unsigned    GPIOM02:               1;
        unsigned    GPIOM03:               1;
        unsigned    GPIOM04:               1;
        unsigned    GPIOM05:               1;
        unsigned    GPIOM06:               1;
        unsigned    GPIOM07:               1;
        unsigned    GPIOM08:               1;
        unsigned    GPIOM09:               1;
        unsigned    GPIOM10:               1;
        unsigned    reserved:              21;
    } tBit;
    __IO uint32_t w;
} t_GPIOM_OEN;

typedef union
{
    struct {
        unsigned    GPIOM00:                2;
        unsigned    GPIOM01:                2;
        unsigned    GPIOM02:                2;
        unsigned    GPIOM03:                2;
        unsigned    GPIOM04:                2;
        unsigned    GPIOM05:                2;
        unsigned    GPIOM06:                2;
        unsigned    GPIOM07:                2;
        unsigned    GPIOM08:                2;
        unsigned    GPIOM09:                2;
        unsigned    GPIOM10:                2;
        unsigned    reserved:               10;
    } tBit;
    __IO uint32_t w;
} t_GPIOM_DS;

typedef union
{
    struct {
        unsigned    GPIOM00:                2;
        unsigned    GPIOM01:                2;
        unsigned    GPIOM02:                2;
        unsigned    GPIOM03:                2;
        unsigned    GPIOM04:                2;
        unsigned    GPIOM05:                2;
        unsigned    GPIOM06:                2;
        unsigned    GPIOM07:                2;
        unsigned    GPIOM08:                2;
        unsigned    GPIOM09:                2;
        unsigned    GPIOM10:                2;
        unsigned    reserved:               10;
    } tBit;
    __IO uint32_t w;
} t_GPIOM_PE;

typedef union
{
    struct {
        unsigned    GPIOM00:               1;
        unsigned    GPIOM01:               1;
        unsigned    GPIOM02:               1;
        unsigned    GPIOM03:               1;
        unsigned    GPIOM04:               1;
        unsigned    GPIOM05:               1;
        unsigned    GPIOM06:               1;
        unsigned    GPIOM07:               1;
        unsigned    GPIOM08:               1;
        unsigned    GPIOM09:               1;
        unsigned    GPIOM10:               1;
        unsigned    reserved:              21;
    } tBit;
    __IO uint32_t w;
} t_GPIOM_SMT;

typedef union
{
    struct {
        unsigned    GPIOM00:              2;
        unsigned    GPIOM01:              2;
        unsigned    GPIOM02:              2;
        unsigned    GPIOM03:              2;
        unsigned    GPIOM04:              2;
        unsigned    GPIOM05:              2;
        unsigned    GPIOM06:              2;
        unsigned    GPIOM07:              2;
        unsigned    GPIOM08:              2;
        unsigned    GPIOM09:              2;
        unsigned    GPIOM10:              2;
        unsigned    reserved:             10;
    } tBit;
    __IO uint32_t w;
} t_GPIOM_FUNC;

typedef union
{
    struct {
        unsigned    GPIOM00:           2;
        unsigned    GPIOM01:           2;
        unsigned    GPIOM02:           2;
        unsigned    GPIOM03:           2;
        unsigned    GPIOM04:           2;
        unsigned    GPIOM05:           2;
        unsigned    GPIOM06:           2;
        unsigned    GPIOM07:           2;
        unsigned    GPIOM08:           2;
        unsigned    GPIOM09:           2;
        unsigned    GPIOM10:           2;
        unsigned    reserved:          10;
    } tBit;
    __IO uint32_t w;
} t_GPIOM_INTTYPE;

typedef union
{
    struct {
        unsigned    GPIOA00:               1;
        unsigned    GPIOA01:               1;
        unsigned    GPIOA02:               1;
        unsigned    GPIOA03:               1;
        unsigned    GPIOA04:               1;
        unsigned    GPIOA05:               1;
        unsigned    GPIOA06:               1;
        unsigned    GPIOA07:               1;
        unsigned    GPIOA08:               1;
        unsigned    GPIOA09:               1;
        unsigned    GPIOA10:               1;
        unsigned    GPIOA11:               1;
        unsigned    GPIOA12:               1;
        unsigned    GPIOA13:               1;
        unsigned    GPIOA14:               1;
        unsigned    GPIOA15:               1;
        unsigned    GPIOA16:               1;
        unsigned    GPIOA17:               1;
        unsigned    GPIOA18:               1;
        unsigned    GPIOA19:               1;
        unsigned    GPIOA20:               1;
        unsigned    GPIOA21:               1;
        unsigned    GPIOA22:               1;
        unsigned    GPIOA23:               1;
        unsigned    GPIOA24:               1;
        unsigned    GPIOA25:               1;
        unsigned    GPIOA26:               1;
        unsigned    GPIOA27:               1;
        unsigned    GPIOA28:               1;
        unsigned    GPIOA29:               1;
        unsigned    GPIOA30:               1;
        unsigned    GPIOA31:               1;
    } tBit;
    __IO uint32_t w;
} t_GPIOAL_IN;

typedef union
{
    struct {
        unsigned    GPIOA00:               1;
        unsigned    GPIOA01:               1;
        unsigned    GPIOA02:               1;
        unsigned    GPIOA03:               1;
        unsigned    GPIOA04:               1;
        unsigned    GPIOA05:               1;
        unsigned    GPIOA06:               1;
        unsigned    GPIOA07:               1;
        unsigned    GPIOA08:               1;
        unsigned    GPIOA09:               1;
        unsigned    GPIOA10:               1;
        unsigned    GPIOA11:               1;
        unsigned    GPIOA12:               1;
        unsigned    GPIOA13:               1;
        unsigned    GPIOA14:               1;
        unsigned    GPIOA15:               1;
        unsigned    GPIOA16:               1;
        unsigned    GPIOA17:               1;
        unsigned    GPIOA18:               1;
        unsigned    GPIOA19:               1;
        unsigned    GPIOA20:               1;
        unsigned    GPIOA21:               1;
        unsigned    GPIOA22:               1;
        unsigned    GPIOA23:               1;
        unsigned    GPIOA24:               1;
        unsigned    GPIOA25:               1;
        unsigned    GPIOA26:               1;
        unsigned    GPIOA27:               1;
        unsigned    GPIOA28:               1;
        unsigned    GPIOA29:               1;
        unsigned    GPIOA30:               1;
        unsigned    GPIOA31:               1;
    } tBit;
    __IO uint32_t w;
} t_GPIOAL_OUT;

typedef union
{
    struct {
        unsigned    GPIOA00:               1;
        unsigned    GPIOA01:               1;
        unsigned    GPIOA02:               1;
        unsigned    GPIOA03:               1;
        unsigned    GPIOA04:               1;
        unsigned    GPIOA05:               1;
        unsigned    GPIOA06:               1;
        unsigned    GPIOA07:               1;
        unsigned    GPIOA08:               1;
        unsigned    GPIOA09:               1;
        unsigned    GPIOA10:               1;
        unsigned    GPIOA11:               1;
        unsigned    GPIOA12:               1;
        unsigned    GPIOA13:               1;
        unsigned    GPIOA14:               1;
        unsigned    GPIOA15:               1;
        unsigned    GPIOA16:               1;
        unsigned    GPIOA17:               1;
        unsigned    GPIOA18:               1;
        unsigned    GPIOA19:               1;
        unsigned    GPIOA20:               1;
        unsigned    GPIOA21:               1;
        unsigned    GPIOA22:               1;
        unsigned    GPIOA23:               1;
        unsigned    GPIOA24:               1;
        unsigned    GPIOA25:               1;
        unsigned    GPIOA26:               1;
        unsigned    GPIOA27:               1;
        unsigned    GPIOA28:               1;
        unsigned    GPIOA29:               1;
        unsigned    GPIOA30:               1;
        unsigned    GPIOA31:               1;
    } tBit;
    __IO uint32_t w;
} t_GPIOAL_OEN;

typedef union
{
    struct {
        unsigned    GPIOA00:                2;
        unsigned    GPIOA01:                2;
        unsigned    GPIOA02:                2;
        unsigned    GPIOA03:                2;
        unsigned    GPIOA04:                2;
        unsigned    GPIOA05:                2;
        unsigned    GPIOA06:                2;
        unsigned    GPIOA07:                2;
        unsigned    GPIOA08:                2;
        unsigned    GPIOA09:                2;
        unsigned    GPIOA10:                2;
        unsigned    GPIOA11:                2;
        unsigned    GPIOA12:                2;
        unsigned    GPIOA13:                2;
        unsigned    GPIOA14:                2;
        unsigned    GPIOA15:                2;
    } tBit;
    __IO uint32_t w;
} t_GPIOALL_DS;

typedef union
{
    struct {
        unsigned    GPIOA16:                2;
        unsigned    GPIOA17:                2;
        unsigned    GPIOA18:                2;
        unsigned    GPIOA19:                2;
        unsigned    GPIOA20:                2;
        unsigned    GPIOA21:                2;
        unsigned    GPIOA22:                2;
        unsigned    GPIOA23:                2;
        unsigned    GPIOA24:                2;
        unsigned    GPIOA25:                2;
        unsigned    GPIOA26:                2;
        unsigned    GPIOA27:                2;
        unsigned    GPIOA28:                2;
        unsigned    GPIOA29:                2;
        unsigned    GPIOA30:                2;
        unsigned    GPIOA31:                2;
    } tBit;
    __IO uint32_t w;
} t_GPIOALH_DS;

typedef union
{
    struct {
        unsigned    GPIOA00:                2;
        unsigned    GPIOA01:                2;
        unsigned    GPIOA02:                2;
        unsigned    GPIOA03:                2;
        unsigned    GPIOA04:                2;
        unsigned    GPIOA05:                2;
        unsigned    GPIOA06:                2;
        unsigned    GPIOA07:                2;
        unsigned    GPIOA08:                2;
        unsigned    GPIOA09:                2;
        unsigned    GPIOA10:                2;
        unsigned    GPIOA11:                2;
        unsigned    GPIOA12:                2;
        unsigned    GPIOA13:                2;
        unsigned    GPIOA14:                2;
        unsigned    GPIOA15:                2;
    } tBit;
    __IO uint32_t w;
} t_GPIOALL_PE;

typedef union
{
    struct {
        unsigned    GPIOA16:                2;
        unsigned    GPIOA17:                2;
        unsigned    GPIOA18:                2;
        unsigned    GPIOA19:                2;
        unsigned    GPIOA20:                2;
        unsigned    GPIOA21:                2;
        unsigned    GPIOA22:                2;
        unsigned    GPIOA23:                2;
        unsigned    GPIOA24:                2;
        unsigned    GPIOA25:                2;
        unsigned    GPIOA26:                2;
        unsigned    GPIOA27:                2;
        unsigned    GPIOA28:                2;
        unsigned    GPIOA29:                2;
        unsigned    GPIOA30:                2;
        unsigned    GPIOA31:                2;
    } tBit;
    __IO uint32_t w;
} t_GPIOALH_PE;

typedef union
{
    struct {
        unsigned    GPIOA00:               1;
        unsigned    GPIOA01:               1;
        unsigned    GPIOA02:               1;
        unsigned    GPIOA03:               1;
        unsigned    GPIOA04:               1;
        unsigned    GPIOA05:               1;
        unsigned    GPIOA06:               1;
        unsigned    GPIOA07:               1;
        unsigned    GPIOA08:               1;
        unsigned    GPIOA09:               1;
        unsigned    GPIOA10:               1;
        unsigned    GPIOA11:               1;
        unsigned    GPIOA12:               1;
        unsigned    GPIOA13:               1;
        unsigned    GPIOA14:               1;
        unsigned    GPIOA15:               1;
        unsigned    GPIOA16:               1;
        unsigned    GPIOA17:               1;
        unsigned    GPIOA18:               1;
        unsigned    GPIOA19:               1;
        unsigned    GPIOA20:               1;
        unsigned    GPIOA21:               1;
        unsigned    GPIOA22:               1;
        unsigned    GPIOA23:               1;
        unsigned    GPIOA24:               1;
        unsigned    GPIOA25:               1;
        unsigned    GPIOA26:               1;
        unsigned    GPIOA27:               1;
        unsigned    GPIOA28:               1;
        unsigned    GPIOA29:               1;
        unsigned    GPIOA30:               1;
        unsigned    GPIOA31:               1;
    } tBit;
    __IO uint32_t w;
} t_GPIOAL_SMT;

typedef union
{
    struct {
        unsigned    GPIOA00:              2;
        unsigned    GPIOA01:              2;
        unsigned    GPIOA02:              2;
        unsigned    GPIOA03:              2;
        unsigned    GPIOA04:              2;
        unsigned    GPIOA05:              2;
        unsigned    GPIOA06:              2;
        unsigned    GPIOA07:              2;
        unsigned    GPIOA08:              2;
        unsigned    GPIOA09:              2;
        unsigned    GPIOA10:              2;
        unsigned    GPIOA11:              2;
        unsigned    GPIOA12:              2;
        unsigned    GPIOA13:              2;
        unsigned    GPIOA14:              2;
        unsigned    GPIOA15:              2;
    } tBit;
    __IO uint32_t w;
} t_GPIOALL_FUNC;

typedef union
{
    struct {
        unsigned    GPIOA16:              2;
        unsigned    GPIOA17:              2;
        unsigned    GPIOA18:              2;
        unsigned    GPIOA19:              2;
        unsigned    GPIOA20:              2;
        unsigned    GPIOA21:              2;
        unsigned    GPIOA22:              2;
        unsigned    GPIOA23:              2;
        unsigned    GPIOA24:              2;
        unsigned    GPIOA25:              2;
        unsigned    GPIOA26:              2;
        unsigned    GPIOA27:              2;
        unsigned    GPIOA28:              2;
        unsigned    GPIOA29:              2;
        unsigned    GPIOA30:              2;
        unsigned    GPIOA31:              2;
    } tBit;
    __IO uint32_t w;
} t_GPIOALH_FUNC;

typedef union
{
    struct {
        unsigned    GPIOA00:           2;
        unsigned    GPIOA01:           2;
        unsigned    GPIOA02:           2;
        unsigned    GPIOA03:           2;
        unsigned    GPIOA04:           2;
        unsigned    GPIOA05:           2;
        unsigned    GPIOA06:           2;
        unsigned    GPIOA07:           2;
        unsigned    GPIOA08:           2;
        unsigned    GPIOA09:           2;
        unsigned    GPIOA10:           2;
        unsigned    GPIOA11:           2;
        unsigned    GPIOA12:           2;
        unsigned    GPIOA13:           2;
        unsigned    GPIOA14:           2;
        unsigned    GPIOA15:           2;
    } tBit;
    __IO uint32_t w;
} t_GPIOALL_INTTYPE;

typedef union
{
    struct {
        unsigned    GPIOA16:           2;
        unsigned    GPIOA17:           2;
        unsigned    GPIOA18:           2;
        unsigned    GPIOA19:           2;
        unsigned    GPIOA20:           2;
        unsigned    GPIOA21:           2;
        unsigned    GPIOA22:           2;
        unsigned    GPIOA23:           2;
        unsigned    GPIOA24:           2;
        unsigned    GPIOA25:           2;
        unsigned    GPIOA26:           2;
        unsigned    GPIOA27:           2;
        unsigned    GPIOA28:           2;
        unsigned    GPIOA29:           2;
        unsigned    GPIOA30:           2;
        unsigned    GPIOA31:           2;
    } tBit;
    __IO uint32_t w;
} t_GPIOALH_INTTYPE;

typedef union
{
    struct {
        unsigned    GPIOA32:               1;
        unsigned    GPIOA33:               1;
        unsigned    GPIOA34:               1;
        unsigned    GPIOA35:               1;
        unsigned    GPIOA36:               1;
        unsigned    GPIOA37:               1;
        unsigned    GPIOA38:               1;
        unsigned    GPIOA39:               1;
        unsigned    GPIOA40:               1;
        unsigned    GPIOA41:               1;
        unsigned    GPIOA42:               1;
        unsigned    GPIOA43:               1;
        unsigned    GPIOA44:               1;
        unsigned    GPIOA45:               1;
        unsigned    reserved:              18;
    } tBit;
    __IO uint32_t w;
} t_GPIOAH_IN;

typedef union
{
    struct {
        unsigned    GPIOA32:               1;
        unsigned    GPIOA33:               1;
        unsigned    GPIOA34:               1;
        unsigned    GPIOA35:               1;
        unsigned    GPIOA36:               1;
        unsigned    GPIOA37:               1;
        unsigned    GPIOA38:               1;
        unsigned    GPIOA39:               1;
        unsigned    GPIOA40:               1;
        unsigned    GPIOA41:               1;
        unsigned    GPIOA42:               1;
        unsigned    GPIOA43:               1;
        unsigned    GPIOA44:               1;
        unsigned    GPIOA45:               1;
        unsigned    reserved:              18;
    } tBit;
    __IO uint32_t w;
} t_GPIOAH_OUT;

typedef union
{
    struct {
        unsigned    GPIOA32:               1;
        unsigned    GPIOA33:               1;
        unsigned    GPIOA34:               1;
        unsigned    GPIOA35:               1;
        unsigned    GPIOA36:               1;
        unsigned    GPIOA37:               1;
        unsigned    GPIOA38:               1;
        unsigned    GPIOA39:               1;
        unsigned    GPIOA40:               1;
        unsigned    GPIOA41:               1;
        unsigned    GPIOA42:               1;
        unsigned    GPIOA43:               1;
        unsigned    GPIOA44:               1;
        unsigned    GPIOA45:               1;
        unsigned    reserved:              18;
    } tBit;
    __IO uint32_t w;
} t_GPIOAH_OEN;

typedef union
{
    struct {
        unsigned    GPIOA32:                2;
        unsigned    GPIOA33:                2;
        unsigned    GPIOA34:                2;
        unsigned    GPIOA35:                2;
        unsigned    GPIOA36:                2;
        unsigned    GPIOA37:                2;
        unsigned    GPIOA38:                2;
        unsigned    GPIOA39:                2;
        unsigned    GPIOA40:                2;
        unsigned    GPIOA41:                2;
        unsigned    GPIOA42:                2;
        unsigned    GPIOA43:                2;
        unsigned    GPIOA44:                2;
        unsigned    GPIOA45:                2;
        unsigned    reserved:               4;
    } tBit;
    __IO uint32_t w;
} t_GPIOAH_DS;

typedef union
{
    struct {
        unsigned    GPIOA32:                2;
        unsigned    GPIOA33:                2;
        unsigned    GPIOA34:                2;
        unsigned    GPIOA35:                2;
        unsigned    GPIOA36:                2;
        unsigned    GPIOA37:                2;
        unsigned    GPIOA38:                2;
        unsigned    GPIOA39:                2;
        unsigned    GPIOA40:                2;
        unsigned    GPIOA41:                2;
        unsigned    GPIOA42:                2;
        unsigned    GPIOA43:                2;
        unsigned    GPIOA44:                2;
        unsigned    GPIOA45:                2;
        unsigned    reserved:               4;
    } tBit;
    __IO uint32_t w;
} t_GPIOAH_PE;

typedef union
{
    struct {
        unsigned    GPIOA32:               1;
        unsigned    GPIOA33:               1;
        unsigned    GPIOA34:               1;
        unsigned    GPIOA35:               1;
        unsigned    GPIOA36:               1;
        unsigned    GPIOA37:               1;
        unsigned    GPIOA38:               1;
        unsigned    GPIOA39:               1;
        unsigned    GPIOA40:               1;
        unsigned    GPIOA41:               1;
        unsigned    GPIOA42:               1;
        unsigned    GPIOA43:               1;
        unsigned    GPIOA44:               1;
        unsigned    GPIOA45:               1;
        unsigned    reserved:              18;
    } tBit;
    __IO uint32_t w;
} t_GPIOAH_SMT;

typedef union
{
    struct {
        unsigned    GPIOA32:              2;
        unsigned    GPIOA33:              2;
        unsigned    GPIOA34:              2;
        unsigned    GPIOA35:              2;
        unsigned    GPIOA36:              2;
        unsigned    GPIOA37:              2;
        unsigned    GPIOA38:              2;
        unsigned    GPIOA39:              2;
        unsigned    GPIOA40:              2;
        unsigned    GPIOA41:              2;
        unsigned    GPIOA42:              2;
        unsigned    GPIOA43:              2;
        unsigned    GPIOA44:              2;
        unsigned    GPIOA45:              2;
        unsigned    reserved:             4;
    } tBit;
    __IO uint32_t w;
} t_GPIOAH_FUNC;

typedef union
{
    struct {
        unsigned    GPIOA32:           2;
        unsigned    GPIOA33:           2;
        unsigned    GPIOA34:           2;
        unsigned    GPIOA35:           2;
        unsigned    GPIOA36:           2;
        unsigned    GPIOA37:           2;
        unsigned    GPIOA38:           2;
        unsigned    GPIOA39:           2;
        unsigned    GPIOA40:           2;
        unsigned    GPIOA41:           2;
        unsigned    GPIOA42:           2;
        unsigned    GPIOA43:           2;
        unsigned    GPIOA44:           2;
        unsigned    GPIOA45:           2;
        unsigned    reserved:          4;
    } tBit;
    __IO uint32_t w;
} t_GPIOAH_INTTYPE;

typedef union
{
    struct {
        unsigned    GPIOM:               1;
        unsigned    GPIOA:               1;
        unsigned    reserved:            30;
    } tBit;
    __IO uint32_t w;
} t_GPIO_INTEN;

typedef union
{
    struct {
        unsigned    GPIOM:               1;
        unsigned    GPIOA:               1;
        unsigned    reserved:            30;
    } tBit;
    __O uint32_t w;
} t_GPIO_INTCLR;

typedef union
{
    struct {
        unsigned    tattn_wdog_en:             1;
        unsigned    tattn_abspck_en:           1;
        unsigned    TCH_ATTN_MUX_SEL:          1;
        unsigned    reserved:                  29;
    } tBit;
    __IO uint32_t w;
} t_SPI_TATTN_OPT_CFG;

typedef struct
{													//Index
    __I  t_GPIOM_IN         	GPIOM_IN;         	//0x0040 GPIOM 0~10
    __IO t_GPIOM_OUT        	GPIOM_OUT;        	//0x0041 GPIOM 0~10
    __IO t_GPIOM_OEN        	GPIOM_OEN;        	//0x0042 GPIOM 0~10
    __IO t_GPIOM_DS         	GPIOM_DS;         	//0x0043 GPIOM 0~10
    __IO t_GPIOM_PE         	GPIOM_PE;         	//0x0044 GPIOM 0~10
    __IO t_GPIOM_SMT        	GPIOM_SMT;        	//0x0045 GPIOM 0~10
    __IO t_GPIOM_FUNC       	GPIOM_FUNC;       	//0x0046 GPIOM 0~10
    __IO t_GPIOM_INTTYPE    	GPIOM_INTTYPE;    	//0x0047 GPIOM 0~10

    __I  t_GPIOAL_IN        	GPIOAL_IN;        	//0x0048 GPIOA 0~31
    __IO t_GPIOAL_OUT       	GPIOAL_OUT;       	//0x0049 GPIOA 0~31
    __IO t_GPIOAL_OEN       	GPIOAL_OEN;       	//0x004A GPIOA 0~31
    __IO t_GPIOALL_DS       	GPIOALL_DS;       	//0x004B GPIOA 0~15
    __IO t_GPIOALH_DS       	GPIOALH_DS;       	//0x004C GPIOA 16~31
    __IO t_GPIOALL_PE       	GPIOALL_PE;       	//0x004D GPIOA 0~15
    __IO t_GPIOALH_PE       	GPIOALH_PE;       	//0x004E GPIOA 16~31
    __IO t_GPIOAL_SMT       	GPIOAL_SMT;       	//0x004F GPIOA 0~31
    __IO t_GPIOALL_FUNC     	GPIOALL_FUNC;     	//0x0050 GPIOA 0~15
    __IO t_GPIOALH_FUNC     	GPIOALH_FUNC;     	//0x0051 GPIOA 16~31
    __IO t_GPIOALL_INTTYPE  	GPIOALL_INTTYPE;  	//0x0052 GPIOA 0~15
    /*
     * GPIOM Interrupt Type. 0: diable, 1: rising edge, 2: falling edge, 3: rising/falling edge
     */
    __IO t_GPIOALH_INTTYPE  	GPIOALH_INTTYPE;  	//0x0053 GPIOA 16~31

    __I  t_GPIOAH_IN        	GPIOAH_IN;        	//0x0054 GPIOA 32~45
    __IO t_GPIOAH_OUT       	GPIOAH_OUT;       	//0x0055 GPIOA 32~45
    __IO t_GPIOAH_OEN       	GPIOAH_OEN;       	//0x0056 GPIOA 32~45
    __IO t_GPIOAH_DS        	GPIOAH_DS;        	//0x0057 GPIOA 32~45
    __IO t_GPIOAH_PE        	GPIOAH_PE;        	//0x0058 GPIOA 32~45
    __IO t_GPIOAH_SMT       	GPIOAH_SMT;       	//0x0059 GPIOA 32~45
    __IO t_GPIOAH_FUNC      	GPIOAH_FUNC;      	//0x005A GPIOA 32~45
    __IO t_GPIOAH_INTTYPE   	GPIOAH_INTTYPE;   	//0x005B GPIOA 32~45

    __IO t_GPIO_INTEN       	GPIO_INTEN;       	//0x005C
    __O  t_GPIO_INTCLR      	GPIO_INTCLEAR;    	//0x005D
    __IO t_SPI_TATTN_OPT_CFG	SPI_TATTN_OPT_CFG;	//0x005E
} tGPIO_CtrlReg_t;


#endif /* __GPIO_H_ */
