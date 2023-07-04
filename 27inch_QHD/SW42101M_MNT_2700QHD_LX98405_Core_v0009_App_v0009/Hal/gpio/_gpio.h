/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _gpio.h
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

#ifndef __GPIO_H_
#define __GPIO_H_


/* ================================================================================ */
/* ================               GPIO Control Registers           ================ */
/* ================================================================================ */
typedef union
{
	struct
	{
		__IO uint32_t GPA00		: 1;		/* GPIOA_00 */
		__IO uint32_t GPA01		: 1;		/* GPIOA_01 */
		__IO uint32_t GPA02		: 1;		/* GPIOA_02 */
		__IO uint32_t GPA03		: 1;		/* GPIOA_03 */
		__IO uint32_t GPA04		: 1;		/* GPIOA_04 */
		__IO uint32_t GPA05		: 1;		/* GPIOA_05 */
		__IO uint32_t GPA06		: 1;		/* GPIOA_06 */
		__IO uint32_t GPA07		: 1;		/* GPIOA_07 */
		__IO uint32_t GPA08		: 1;		/* GPIOA_08 */
		__IO uint32_t GPA09		: 1;		/* GPIOA_09 */
		__IO uint32_t GPA10		: 1;		/* GPIOA_10 */
		__IO uint32_t GPA11		: 1;		/* GPIOA_11 */
		__IO uint32_t GPA12		: 1;		/* GPIOA_12 */
		__IO uint32_t GPA13		: 1;		/* GPIOA_13 */
		__IO uint32_t GPA14		: 1;		/* GPIOA_14 */
		__IO uint32_t GPA15		: 1;		/* GPIOA_15 */
		__IO uint32_t GPA16		: 1;		/* GPIOA_16 */
		__IO uint32_t GPA17		: 1;		/* GPIOA_17 */
		__IO uint32_t GPA18		: 1;		/* GPIOA_18 */
		__IO uint32_t GPA19		: 1;		/* GPIOA_19 */
		__IO uint32_t GPA20		: 1;		/* GPIOA_20 */
		__IO uint32_t GPA21		: 1;		/* GPIOA_21 */
		__IO uint32_t GPA22		: 1;		/* GPIOA_22 */
		__IO uint32_t GPA23		: 1;		/* GPIOA_23 */
		__IO uint32_t GPA24		: 1;		/* GPIOA_24 */
		__IO uint32_t GPA25		: 1;		/* GPIOA_25 */
		__IO uint32_t GPA26		: 1;		/* GPIOA_26 */
		__IO uint32_t GPA27		: 1;		/* GPIOA_27 */
		__IO uint32_t GPA28		: 1;		/* GPIOA_28 */
		__IO uint32_t GPA29		: 1;		/* GPIOA_29 */
		__IO uint32_t GPA30		: 1;		/* GPIOA_30 */
		__IO uint32_t GPA31		: 1;		/* GPIOA_31 */
	} tBit;
	__IO uint32_t ulBulk;
} tGPIO_PIN_0_t;

typedef union
{
	struct
	{
		__IO uint32_t GPA32		: 1;		/* GPIOA_32 */
		__IO uint32_t GPA33		: 1;		/* GPIOA_33 */
		__IO uint32_t GPA34		: 1;		/* GPIOA_34 */
		__IO uint32_t GPA35		: 1;		/* GPIOA_35 */
		__IO uint32_t GPA36		: 1;		/* GPIOA_36 */
		__IO uint32_t GPA37		: 1;		/* GPIOA_37 */
		__IO uint32_t GPB00		: 1;		/* GPIOB_00 */
		__IO uint32_t GPB01		: 1;		/* GPIOB_01 */
		__IO uint32_t GPB02		: 1;		/* GPIOB_02 */
		__IO uint32_t GPB03		: 1;		/* GPIOB_03 */
		__IO uint32_t GPB04		: 1;		/* GPIOB_04 */
		__IO uint32_t GPB05		: 1;		/* GPIOB_05 */
		__IO uint32_t GPB06		: 1;		/* GPIOB_06 */
		__IO uint32_t GPB07		: 1;		/* GPIOB_07 */
		__IO uint32_t GPB08		: 1;		/* GPIOB_08 */
		__IO uint32_t GPB09		: 1;		/* GPIOB_09 */
		__IO uint32_t GPB10		: 1;		/* GPIOB_10 */
		__IO uint32_t GPB11		: 1;		/* GPIOB_11 */
		/*
		 * Serial Flash SPI Pin
		 */
//		__I uint32_t GPB12		: 1;		/* GPIOB_12 */
//		__I uint32_t GPB13		: 1;		/* GPIOB_13 */
//		__I uint32_t GPB14		: 1;		/* GPIOB_14 */
//		__I uint32_t GPB15		: 1;		/* GPIOB_15 */
//		__I uint32_t RESERVED	: 10;
		__I uint32_t RESERVED	: 14;
	} tBit;
	__IO uint32_t ulBulk;
} tGPIO_PIN_1_t;

typedef union
{
	struct
	{
		__IO uint32_t GPA00		: 1;		/* GPIOA_00 */
		__IO uint32_t GPA01		: 1;		/* GPIOA_01 */
		__IO uint32_t GPA02		: 1;		/* GPIOA_02 */
		__IO uint32_t GPA03		: 1;		/* GPIOA_03 */
		__IO uint32_t GPA04		: 1;		/* GPIOA_04 */
		__IO uint32_t GPA05		: 1;		/* GPIOA_05 */
		__IO uint32_t GPA06		: 1;		/* GPIOA_06 */
		__IO uint32_t GPA07		: 1;		/* GPIOA_07 */
		__IO uint32_t GPA08		: 1;		/* GPIOA_08 */
		__IO uint32_t GPA09		: 1;		/* GPIOA_09 */
		__IO uint32_t GPA10		: 1;		/* GPIOA_10 */
		__IO uint32_t GPA11		: 1;		/* GPIOA_11 */
		__IO uint32_t GPA24		: 1;		/* GPIOA_24 */
		__IO uint32_t GPA25		: 1;		/* GPIOA_25 */
		__IO uint32_t GPA26		: 1;		/* GPIOA_26 */
		__IO uint32_t GPA27		: 1;		/* GPIOA_27 */
		__IO uint32_t GPA28		: 1;		/* GPIOA_28 */
		__IO uint32_t GPA29		: 1;		/* GPIOA_29 */
		__IO uint32_t GPA30		: 1;		/* GPIOA_30 */
		__IO uint32_t GPA31		: 1;		/* GPIOA_31 */
		__IO uint32_t GPA32		: 1;		/* GPIOA_32 */
		__IO uint32_t GPA33		: 1;		/* GPIOA_33 */
		__IO uint32_t GPA34		: 1;		/* GPIOA_34 */
		__IO uint32_t GPA35		: 1;		/* GPIOA_35 */
		__IO uint32_t GPA36		: 1;		/* GPIOA_36 */
		__IO uint32_t GPA37		: 1;		/* GPIOA_37 */
		__I uint32_t RESERVED	: 6;
	} tBit;
	__IO uint32_t ulBulk;
} tGPIO_EXTI_0_IO_t;

typedef union
{
	struct
	{
		__I uint32_t GPA00		: 1;		/* GPIOA_00 */
		__I uint32_t GPA01		: 1;		/* GPIOA_01 */
		__I uint32_t GPA02		: 1;		/* GPIOA_02 */
		__I uint32_t GPA03		: 1;		/* GPIOA_03 */
		__I uint32_t GPA04		: 1;		/* GPIOA_04 */
		__I uint32_t GPA05		: 1;		/* GPIOA_05 */
		__I uint32_t GPA06		: 1;		/* GPIOA_06 */
		__I uint32_t GPA07		: 1;		/* GPIOA_07 */
		__I uint32_t GPA08		: 1;		/* GPIOA_08 */
		__I uint32_t GPA09		: 1;		/* GPIOA_09 */
		__I uint32_t GPA10		: 1;		/* GPIOA_10 */
		__I uint32_t GPA11		: 1;		/* GPIOA_11 */
		__I uint32_t GPA24		: 1;		/* GPIOA_24 */
		__I uint32_t GPA25		: 1;		/* GPIOA_25 */
		__I uint32_t GPA26		: 1;		/* GPIOA_26 */
		__I uint32_t GPA27		: 1;		/* GPIOA_27 */
		__I uint32_t GPA28		: 1;		/* GPIOA_28 */
		__I uint32_t GPA29		: 1;		/* GPIOA_29 */
		__I uint32_t GPA30		: 1;		/* GPIOA_30 */
		__I uint32_t GPA31		: 1;		/* GPIOA_31 */
		__I uint32_t GPA32		: 1;		/* GPIOA_32 */
		__I uint32_t GPA33		: 1;		/* GPIOA_33 */
		__I uint32_t GPA34		: 1;		/* GPIOA_34 */
		__I uint32_t GPA35		: 1;		/* GPIOA_35 */
		__I uint32_t GPA36		: 1;		/* GPIOA_36 */
		__I uint32_t GPA37		: 1;		/* GPIOA_37 */
		__I uint32_t RESERVED	: 6;
	} tBit;
	__I uint32_t ulBulk;
} tGPIO_EXTI_0_I_t;

typedef union
{
	struct
	{
		__O uint32_t GPA00		: 1;		/* GPIOA_00 */
		__O uint32_t GPA01		: 1;		/* GPIOA_01 */
		__O uint32_t GPA02		: 1;		/* GPIOA_02 */
		__O uint32_t GPA03		: 1;		/* GPIOA_03 */
		__O uint32_t GPA04		: 1;		/* GPIOA_04 */
		__O uint32_t GPA05		: 1;		/* GPIOA_05 */
		__O uint32_t GPA06		: 1;		/* GPIOA_06 */
		__O uint32_t GPA07		: 1;		/* GPIOA_07 */
		__O uint32_t GPA08		: 1;		/* GPIOA_08 */
		__O uint32_t GPA09		: 1;		/* GPIOA_09 */
		__O uint32_t GPA10		: 1;		/* GPIOA_10 */
		__O uint32_t GPA11		: 1;		/* GPIOA_11 */
		__O uint32_t GPA24		: 1;		/* GPIOA_24 */
		__O uint32_t GPA25		: 1;		/* GPIOA_25 */
		__O uint32_t GPA26		: 1;		/* GPIOA_26 */
		__O uint32_t GPA27		: 1;		/* GPIOA_27 */
		__O uint32_t GPA28		: 1;		/* GPIOA_28 */
		__O uint32_t GPA29		: 1;		/* GPIOA_29 */
		__O uint32_t GPA30		: 1;		/* GPIOA_30 */
		__O uint32_t GPA31		: 1;		/* GPIOA_31 */
		__O uint32_t GPA32		: 1;		/* GPIOA_32 */
		__O uint32_t GPA33		: 1;		/* GPIOA_33 */
		__O uint32_t GPA34		: 1;		/* GPIOA_34 */
		__O uint32_t GPA35		: 1;		/* GPIOA_35 */
		__O uint32_t GPA36		: 1;		/* GPIOA_36 */
		__O uint32_t GPA37		: 1;		/* GPIOA_37 */
		__I uint32_t RESERVED	: 6;
	} tBit;
	__I uint32_t ulBulk;
} tGPIO_EXTI_0_O_t;

typedef union
{
	struct
	{
		__IO uint32_t GPA12		: 1;		/* GPIOA_12 */
		__IO uint32_t GPA13		: 1;		/* GPIOA_13 */
		__IO uint32_t GPA14		: 1;		/* GPIOA_14 */
		__IO uint32_t GPA15		: 1;		/* GPIOA_15 */
		__IO uint32_t GPA16		: 1;		/* GPIOA_16 */
		__IO uint32_t GPA17		: 1;		/* GPIOA_17 */
		__IO uint32_t GPA18		: 1;		/* GPIOA_18 */
		__IO uint32_t GPA19		: 1;		/* GPIOA_19 */
		__IO uint32_t GPA20		: 1;		/* GPIOA_20 */
		__IO uint32_t GPA21		: 1;		/* GPIOA_21 */
		__IO uint32_t GPA22		: 1;		/* GPIOA_22 */
		__IO uint32_t GPA23		: 1;		/* GPIOA_23 */
		__IO uint32_t GPB00		: 1;		/* GPIOB_00 */
		__IO uint32_t GPB01		: 1;		/* GPIOB_01 */
		__IO uint32_t GPB02		: 1;		/* GPIOB_02 */
		__IO uint32_t GPB03		: 1;		/* GPIOB_03 */
		__IO uint32_t GPB04		: 1;		/* GPIOB_04 */
		__IO uint32_t GPB05		: 1;		/* GPIOB_05 */
		__IO uint32_t GPB06		: 1;		/* GPIOB_06 */
		__IO uint32_t GPB07		: 1;		/* GPIOB_07 */
		__IO uint32_t GPB08		: 1;		/* GPIOB_08 */
		__IO uint32_t GPB09		: 1;		/* GPIOB_09 */
		__IO uint32_t GPB10		: 1;		/* GPIOB_10 */
		__IO uint32_t GPB11		: 1;		/* GPIOB_11 */
//		__I uint32_t GPB12		: 1;		/* GPIOB_12 */
//		__I uint32_t GPB13		: 1;		/* GPIOB_13 */
//		__I uint32_t GPB14		: 1;		/* GPIOB_14 */
//		__I uint32_t GPB15		: 1;		/* GPIOB_15 */
//		__I uint32_t RESERVED	: 4;
		__I uint32_t RESERVED	: 8;
	} tBit;
	__IO uint32_t ulBulk;
} tGPIO_EXTI_1_IO_t;

typedef union
{
	struct
	{
		__I uint32_t GPA12		: 1;		/* GPIOA_12 */
		__I uint32_t GPA13		: 1;		/* GPIOA_13 */
		__I uint32_t GPA14		: 1;		/* GPIOA_14 */
		__I uint32_t GPA15		: 1;		/* GPIOA_15 */
		__I uint32_t GPA16		: 1;		/* GPIOA_16 */
		__I uint32_t GPA17		: 1;		/* GPIOA_17 */
		__I uint32_t GPA18		: 1;		/* GPIOA_18 */
		__I uint32_t GPA19		: 1;		/* GPIOA_19 */
		__I uint32_t GPA20		: 1;		/* GPIOA_20 */
		__I uint32_t GPA21		: 1;		/* GPIOA_21 */
		__I uint32_t GPA22		: 1;		/* GPIOA_22 */
		__I uint32_t GPA23		: 1;		/* GPIOA_23 */
		__I uint32_t GPB00		: 1;		/* GPIOB_00 */
		__I uint32_t GPB01		: 1;		/* GPIOB_01 */
		__I uint32_t GPB02		: 1;		/* GPIOB_02 */
		__I uint32_t GPB03		: 1;		/* GPIOB_03 */
		__I uint32_t GPB04		: 1;		/* GPIOB_04 */
		__I uint32_t GPB05		: 1;		/* GPIOB_05 */
		__I uint32_t GPB06		: 1;		/* GPIOB_06 */
		__I uint32_t GPB07		: 1;		/* GPIOB_07 */
		__I uint32_t GPB08		: 1;		/* GPIOB_08 */
		__I uint32_t GPB09		: 1;		/* GPIOB_09 */
		__I uint32_t GPB10		: 1;		/* GPIOB_10 */
		__I uint32_t GPB11		: 1;		/* GPIOB_11 */
//		__I uint32_t GPB12		: 1;		/* GPIOB_12 */
//		__I uint32_t GPB13		: 1;		/* GPIOB_13 */
//		__I uint32_t GPB14		: 1;		/* GPIOB_14 */
//		__I uint32_t GPB15		: 1;		/* GPIOB_15 */
//		__I uint32_t RESERVED	: 4;
		__I uint32_t RESERVED	: 8;
	} tBit;
	__I uint32_t ulBulk;
} tGPIO_EXTI_1_I_t;

typedef union
{
	struct
	{
		__O uint32_t GPA12		: 1;		/* GPIOA_12 */
		__O uint32_t GPA13		: 1;		/* GPIOA_13 */
		__O uint32_t GPA14		: 1;		/* GPIOA_14 */
		__O uint32_t GPA15		: 1;		/* GPIOA_15 */
		__O uint32_t GPA16		: 1;		/* GPIOA_16 */
		__O uint32_t GPA17		: 1;		/* GPIOA_17 */
		__O uint32_t GPA18		: 1;		/* GPIOA_18 */
		__O uint32_t GPA19		: 1;		/* GPIOA_19 */
		__O uint32_t GPA20		: 1;		/* GPIOA_20 */
		__O uint32_t GPA21		: 1;		/* GPIOA_21 */
		__O uint32_t GPA22		: 1;		/* GPIOA_22 */
		__O uint32_t GPA23		: 1;		/* GPIOA_23 */
		__O uint32_t GPB00		: 1;		/* GPIOB_00 */
		__O uint32_t GPB01		: 1;		/* GPIOB_01 */
		__O uint32_t GPB02		: 1;		/* GPIOB_02 */
		__O uint32_t GPB03		: 1;		/* GPIOB_03 */
		__O uint32_t GPB04		: 1;		/* GPIOB_04 */
		__O uint32_t GPB05		: 1;		/* GPIOB_05 */
		__O uint32_t GPB06		: 1;		/* GPIOB_06 */
		__O uint32_t GPB07		: 1;		/* GPIOB_07 */
		__O uint32_t GPB08		: 1;		/* GPIOB_08 */
		__O uint32_t GPB09		: 1;		/* GPIOB_09 */
		__O uint32_t GPB10		: 1;		/* GPIOB_10 */
		__O uint32_t GPB11		: 1;		/* GPIOB_11 */
//		__O uint32_t GPB12		: 1;		/* GPIOB_12 */
//		__I uint32_t GPB13		: 1;		/* GPIOB_13 */
//		__I uint32_t GPB14		: 1;		/* GPIOB_14 */
//		__I uint32_t GPB15		: 1;		/* GPIOB_15 */
//		__I uint32_t RESERVED	: 4;
		__I uint32_t RESERVED	: 8;
	} tBit;
	__O uint32_t ulBulk;
} tGPIO_EXTI_1_O_t;

typedef union
{
	struct
	{
		__IO uint32_t GPA00		: 2;		/* GPIOA_00 */
		__IO uint32_t GPA01		: 2;		/* GPIOA_01 */
		__IO uint32_t GPA02		: 2;		/* GPIOA_02 */
		__IO uint32_t GPA03		: 2;		/* GPIOA_03 */
		__IO uint32_t GPA04		: 2;		/* GPIOA_04 */
		__IO uint32_t GPA05		: 2;		/* GPIOA_05 */
		__IO uint32_t GPA06		: 2;		/* GPIOA_06 */
		__IO uint32_t GPA07		: 2;		/* GPIOA_07 */
		__IO uint32_t GPA08		: 2;		/* GPIOA_08 */
		__IO uint32_t GPA09		: 2;		/* GPIOA_09 */
		__IO uint32_t GPA10		: 2;		/* GPIOA_10 */
		__IO uint32_t GPA11		: 2;		/* GPIOA_11 */
		__IO uint32_t GPA12		: 2;		/* GPIOA_12 */
		__IO uint32_t GPA13		: 2;		/* GPIOA_13 */
		__IO uint32_t GPA14		: 2;		/* GPIOA_14 */
		__IO uint32_t GPA15		: 2;		/* GPIOA_15 */
	} tBit;
	__IO uint32_t ulBulk;
} tGPIO_AFIO_0_t;

typedef union
{
	struct
	{
		__IO uint32_t GPA16		: 2;		/* GPIOA_16 */
		__IO uint32_t GPA17		: 2;		/* GPIOA_17 */
		__IO uint32_t GPA18		: 2;		/* GPIOA_18 */
		__IO uint32_t GPA19		: 2;		/* GPIOA_19 */
		__IO uint32_t GPA20		: 2;		/* GPIOA_20 */
		__IO uint32_t GPA21		: 2;		/* GPIOA_21 */
		__IO uint32_t GPA22		: 2;		/* GPIOA_22 */
		__IO uint32_t GPA23		: 2;		/* GPIOA_23 */
		__IO uint32_t GPA24		: 2;		/* GPIOA_24 */
		__IO uint32_t GPA25		: 2;		/* GPIOA_25 */
		__IO uint32_t GPA26		: 2;		/* GPIOA_26 */
		__IO uint32_t GPA27		: 2;		/* GPIOA_27 */
		__IO uint32_t GPA28		: 2;		/* GPIOA_28 */
		__IO uint32_t GPA29		: 2;		/* GPIOA_29 */
		__IO uint32_t GPA30		: 2;		/* GPIOA_30 */
		__IO uint32_t GPA31		: 2;		/* GPIOA_31 */
	} tBit;
	__IO uint32_t ulBulk;
} tGPIO_AFIO_1_t;

typedef union
{
	struct
	{
		__IO uint32_t GPA32		: 2;		/* GPIOA_32 */
		__IO uint32_t GPA33		: 2;		/* GPIOA_33 */
		__IO uint32_t GPA34		: 2;		/* GPIOA_34 */
		__IO uint32_t GPA35		: 2;		/* GPIOA_35 */
		__IO uint32_t GPA36		: 2;		/* GPIOA_36 */
		__IO uint32_t GPA37		: 2;		/* GPIOA_37 */
		__IO uint32_t GPB00		: 2;		/* GPIOB_00 */
		__IO uint32_t GPB01		: 2;		/* GPIOB_01 */
		__IO uint32_t GPB02		: 2;		/* GPIOB_02 */
		__IO uint32_t GPB03		: 2;		/* GPIOB_03 */
		__IO uint32_t GPB04		: 2;		/* GPIOB_04 */
		__IO uint32_t GPB05		: 2;		/* GPIOB_05 */
		__IO uint32_t GPB06		: 2;		/* GPIOB_06 */
		__IO uint32_t GPB07		: 2;		/* GPIOB_07 */
		__IO uint32_t GPB08		: 2;		/* GPIOB_08 */
		__IO uint32_t GPB09		: 2;		/* GPIOB_09 */
	} tBit;
	__IO uint32_t ulBulk;
} tGPIO_AFIO_2_t;

typedef union
{
	struct
	{
		__IO uint32_t GPB10		: 2;		/* GPIOB_10 */
		__IO uint32_t GPB11		: 2;		/* GPIOB_11 */
//		__I uint32_t GPB12		: 2;		/* GPIOB_12 */
//		__I uint32_t GPB13		: 2;		/* GPIOB_13 */
//		__I uint32_t GPB14		: 2;		/* GPIOB_14 */
//		__I uint32_t GPB15		: 2;		/* GPIOB_15 */
//		__I uint32_t RESERVED	: 20;
		__I uint32_t RESERVED	: 28;
	} tBit;
	__IO uint32_t ulBulk;
} tGPIO_AFIO_3_t;

typedef struct
{
	/*
	 * When AFIO is GPIO Mode, observe the external input and control the internal output value
	 * At Read operation : Observe the external input value
	 * At Write operation : Control the internal output value (0:Low, 1:High)
	 */
	tGPIO_PIN_0_t tGPIO_DATA_0;
	tGPIO_PIN_1_t tGPIO_DATA_1;
	/*
	 * When AFIO is GPIO Mode, configuration the input/output of GPIO Pins
	 * 0 : Set as Input
	 * 1 : Set as Output
	 */
	tGPIO_PIN_0_t tGPIO_DIR_0;
	tGPIO_PIN_1_t tGPIO_DIR_1;
	/*
	 * Open Drain Control
	 * 0 : Disable
	 * 1 : Enable
	 */
	tGPIO_PIN_0_t tGPIO_OD_0;
	tGPIO_PIN_1_t tGPIO_OD_1;
	/*
	 * Control the Pull-Up function
	 * 0 : Disable Pull-Up function
	 * 1 : Enable Pull-Up function
	 */
	tGPIO_PIN_0_t tGPIO_PU_0;
	tGPIO_PIN_1_t tGPIO_PU_1;
	/*
	 * Control the Pull-Down function
	 * 0 : Disable Pull-Down function
	 * 1 : Enable Pull-Down function
	 */
	tGPIO_PIN_0_t tGPIO_PD_0;
	tGPIO_PIN_1_t tGPIO_PD_1;
	/*
	 * GPIO interrupt Detection control
	 * 0 : Edge Detection
	 * 1 : Level Detection
	 */
	tGPIO_EXTI_0_IO_t tGPIO_EXTI0_IS;
	/*
	 * GPIO interrupt edge control
	 * 0 : Single Edge
	 * 1 : Both Edge
	 */
	tGPIO_EXTI_0_IO_t tGPIO_EXTI0_IBE;
	/*
	 * GPIO interrupt direction control
	 * 0 : Negative Edge / Low Level
	 * 1 : Positive Edge / High Level
	 */
	tGPIO_EXTI_0_IO_t tGPIO_EXTI0_IEV;
	/*
	 * Set the Interrupt operation
	 * 0 : Disable Interrupt
	 * 1 : Enable Interrupt
	 */
	tGPIO_EXTI_0_IO_t tGPIO_EXTI0_IE;
	/*
	 * GPIO raw interrupt status from
	 */
	tGPIO_EXTI_0_I_t tGPIO_EXTI0_RIS;
	/*
	 * GPIO masked interrupt status from
	 */
	tGPIO_EXTI_0_I_t tGPIO_EXTI0_MIS;
	/*
	 * GPIO interrupt clear register
	 */
	tGPIO_EXTI_0_O_t tGPIO_EXTI0_INTC;

	tGPIO_EXTI_1_IO_t tGPIO_EXTI1_IS;
	tGPIO_EXTI_1_IO_t tGPIO_EXTI1_IBE;
	tGPIO_EXTI_1_IO_t tGPIO_EXTI1_IEV;
	tGPIO_EXTI_1_IO_t tGPIO_EXTI1_IE;
	tGPIO_EXTI_1_I_t tGPIO_EXTI1_RIS;
	tGPIO_EXTI_1_I_t tGPIO_EXTI1_MIS;
	tGPIO_EXTI_1_O_t tGPIO_EXTI1_INTC;

	tGPIO_AFIO_0_t tGPIO_AFIO_0;
	tGPIO_AFIO_1_t tGPIO_AFIO_1;
	tGPIO_AFIO_2_t tGPIO_AFIO_2;
	tGPIO_AFIO_3_t tGPIO_AFIO_3;

	tGPIO_PIN_0_t tGPIO_IE0;
	tGPIO_PIN_1_t tGPIO_IE1;

	tGPIO_PIN_0_t tGPIO_P2_0;
	tGPIO_PIN_1_t tGPIO_P2_1;

	tGPIO_PIN_0_t tGPIO_P1_0;
	tGPIO_PIN_1_t tGPIO_P1_1;

	tGPIO_PIN_0_t tGPIO_SMT_0;
	tGPIO_PIN_1_t tGPIO_SMT_1;

} tGPIO_CtrlReg_t;


#endif /* __GPIO_H_ */
