/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : gpio.h
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

#ifndef _GPIO_H_
#define _GPIO_H_

#define GPIO_Pin_0                 ((uint32_t)0x00000001)  /*!< Pin 0 selected */
#define GPIO_Pin_1                 ((uint32_t)0x00000002)  /*!< Pin 1 selected */
#define GPIO_Pin_2                 ((uint32_t)0x00000004)  /*!< Pin 2 selected */
#define GPIO_Pin_3                 ((uint32_t)0x00000008)  /*!< Pin 3 selected */
#define GPIO_Pin_4                 ((uint32_t)0x00000010)  /*!< Pin 4 selected */
#define GPIO_Pin_5                 ((uint32_t)0x00000020)  /*!< Pin 5 selected */
#define GPIO_Pin_6                 ((uint32_t)0x00000040)  /*!< Pin 6 selected */
#define GPIO_Pin_7                 ((uint32_t)0x00000080)  /*!< Pin 7 selected */
#define GPIO_Pin_8                 ((uint32_t)0x00000100)  /*!< Pin 8 selected */
#define GPIO_Pin_9                 ((uint32_t)0x00000200)  /*!< Pin 9 selected */
#define GPIO_Pin_10                ((uint32_t)0x00000400)  /*!< Pin 10 selected */
#define GPIO_Pin_11                ((uint32_t)0x00000800)  /*!< Pin 11 selected */
#define GPIO_Pin_12                ((uint32_t)0x00001000)  /*!< Pin 12 selected */
#define GPIO_Pin_13                ((uint32_t)0x00002000)  /*!< Pin 13 selected */
#define GPIO_Pin_14                ((uint32_t)0x00004000)  /*!< Pin 14 selected */
#define GPIO_Pin_15                ((uint32_t)0x00008000)  /*!< Pin 15 selected */
#define GPIO_Pin_16                ((uint32_t)0x00010000)  /*!< Pin 16 selected */
#define GPIO_Pin_17                ((uint32_t)0x00020000)  /*!< Pin 17 selected */
#define GPIO_Pin_18                ((uint32_t)0x00040000)  /*!< Pin 18 selected */
#define GPIO_Pin_19                ((uint32_t)0x00080000)  /*!< Pin 19 selected */
#define GPIO_Pin_20                ((uint32_t)0x00100000)  /*!< Pin 20 selected */
#define GPIO_Pin_21                ((uint32_t)0x00200000)  /*!< Pin 21 selected */
#define GPIO_Pin_22                ((uint32_t)0x00400000)  /*!< Pin 22 selected */
#define GPIO_Pin_23                ((uint32_t)0x00800000)  /*!< Pin 23 selected */
#define GPIO_Pin_24                ((uint32_t)0x01000000)  /*!< Pin 24 selected */
#define GPIO_Pin_25                ((uint32_t)0x02000000)  /*!< Pin 25 selected */
#define GPIO_Pin_26                ((uint32_t)0x04000000)  /*!< Pin 26 selected */
#define GPIO_Pin_27                ((uint32_t)0x08000000)  /*!< Pin 27 selected */
#define GPIO_Pin_28                ((uint32_t)0x10000000)  /*!< Pin 28 selected */
#define GPIO_Pin_29                ((uint32_t)0x20000000)  /*!< Pin 29 selected */
#define GPIO_Pin_30                ((uint32_t)0x40000000)  /*!< Pin 30 selected */
#define GPIO_Pin_31                ((uint32_t)0x80000000)  /*!< Pin 31 selected */
#define GPIO_Pin_All               ((uint32_t)0xFFFFFFFF)  /*!< All pins selected */

//#define LEVEL_DETECTION_GPIO		(1)
//#define EDGE_DETECTION_GPIO			(0)

//#define BOTH_EDGE_GPIO				(1)
//#define SINGLE_EDGE_GPIO			(0)

//#define POSITIVE_HIGH_GPIO			(1)
//#define NEGATIVE_LOW_GPIO			(0)

//#define ENABLE_GPIO					(1)
//#define DISABLE_GPIO				(0)

//#include "gpio_define.h"

typedef enum
{
    GPIO_M00 = 0,
    GPIO_M01,
    GPIO_M02,
    GPIO_M03,
    GPIO_M04,
    GPIO_M05,
    GPIO_M06,
    GPIO_M07,
    GPIO_M08,
    GPIO_M09,
    GPIO_M10,
    GPIO_A00,
    GPIO_A01,
    GPIO_A02,
    GPIO_A03,
    GPIO_A04,
    GPIO_A05,
    GPIO_A06,
    GPIO_A07,
    GPIO_A08,
    GPIO_A09,
    GPIO_A10,
    GPIO_A11,
    GPIO_A12,
    GPIO_A13,
    GPIO_A14,
    GPIO_A15,
    GPIO_A16,
    GPIO_A17,
    GPIO_A18,
    GPIO_A19,
    GPIO_A20,
    GPIO_A21,
    GPIO_A22,
    GPIO_A23,
    GPIO_A24,
    GPIO_A25,
    GPIO_A26,
    GPIO_A27,
    GPIO_A28,
    GPIO_A29,
    GPIO_A30,
    GPIO_A31,
    GPIO_A32,
    GPIO_A33,
    GPIO_A34,
    GPIO_A35,
    GPIO_A36,
    GPIO_A37,
    GPIO_A38,
    GPIO_A39,
    GPIO_A40,
    GPIO_A41,
    GPIO_A42,
    GPIO_A43,
    GPIO_A44,
    GPIO_A45
} GPIOPin_TypeDef;

typedef enum
{
    GPIO_DATA_LOW = 0,
    GPIO_DATA_HIGH,
    GPIO_DATA_NONE
} GPIODATA_TypeDef;

typedef enum
{
    GPIO_DIR_OUTPUT = 0,
    GPIO_DIR_INPUT,
    GPIO_DIR_NONE
} GPIODIR_TypeDef;

typedef enum
{
    GPIO_PE_DISABLE = 0,
    GPIO_PE_PULL_DOWM,
    GPIO_PE_PULL_UP,
    GPIO_PE_KEEPER
} GPIOPE_TypeDef;
	
typedef enum
{
    GPIO_DRIVE_STR_4mA = 0,
    GPIO_DRIVE_STR_8mA,
    GPIO_DRIVE_STR_16mA,
    GPIO_DRIVE_STR_20mA
} GPIODS_TypeDef;

typedef enum
{
    GPIO_MODE_FUNC_0 = 0,
    GPIO_MODE_FUNC_1,
    GPIO_MODE_FUNC_2,
    GPIO_MODE_FUNC_3,
    GPIO_MODE_FUNC_NONE
} GPIOFunc_TypeDef;

typedef enum
{
    GPIO_INTEN_DISABLE = 0,
	GPIO_INTEN_ENABLE,
    GPIO_INTEN_NONE
} GPIOINTEN_TypeDef;

typedef enum
{
    GPIO_INTTYPE_DISABLE = 0,
	GPIO_INTTYPE_RISING_EDGE,
	GPIO_INTTYPE_FALLING_EDGE,
	GPIO_INTTYPE_BOTH_EDGE,
	GPIO_INTTYPE_NONE
} GPIOINTType_TypeDef;

#define _gToggle(pin)               GPIO_Toggle(pin)                   // GPIO Toggle function

#ifdef _USE_WITH_BOOT_
#define _gT(pin)
#else
#define _gT(pin)                    GPIO_Toggle(pin); GPIO_Toggle(pin) // GPIO Toggle function
#endif

#define _gOut(pin, state)           GPIO_Set_DATA(pin, state)          // GPIO Set Output status
#define IS_GPIO_PIN(pin)            GPIO_Get_IN(pin)
#define IS_GPIO_POUT(pin)           GPIO_Get_OUT(pin)

//#define GPIO_INTR_ENABLE			(1)
//#define GPIO_INTR_DISABLE			(0)
//
//#define GPIO_INTR_RISING_EDGE		(1)
//#define GPIO_INTR_FALLING_EDGE		(2)
//#define GPIO_INTR_BOTH_EDGE			(3)

extern void GPIO_Initialize(void);

extern void GPIO_Init(GPIOPin_TypeDef GPIOx, GPIOFunc_TypeDef mode, GPIODIR_TypeDef dir, GPIODATA_TypeDef data);
extern void GPIO_Set_Mode(GPIOPin_TypeDef GPIOx, GPIOFunc_TypeDef mode);
extern void GPIO_Set_Dir(GPIOPin_TypeDef GPIOx, GPIODIR_TypeDef dir);
extern void GPIO_Set_DATA(GPIOPin_TypeDef GPIOx, GPIODATA_TypeDef data);
extern void GPIO_Set_PE(GPIOPin_TypeDef GPIOx, GPIOPE_TypeDef pe);
extern void GPIO_Set_DS(GPIOPin_TypeDef GPIOx, GPIODS_TypeDef ds);
extern bool_t GPIO_Get_IN(GPIOPin_TypeDef GPIOx);
extern bool_t GPIO_Get_OUT(GPIOPin_TypeDef GPIOx);
extern void GPIO_Set_INT(GPIOPin_TypeDef GPIOx, GPIOINTEN_TypeDef En, GPIOINTType_TypeDef type);
extern void GPIO_Toggle(GPIOPin_TypeDef GPIOx);

//extern bool_t GPIO_Set_Reverse(GPIOPin_TypeDef GPIOx);
// extern bool_t IS_GPIO_PIN(GPIOPin_TypeDef GPIOx);

#if USED_GPIO_TEST_HANDSHAKE
extern void _____TEST_GPB09_HandShake(uint32_t ulNum, uint32_t ulusecDelay);
#else /* USED_GPIO_TEST_HANDSHAKE */
#define _____TEST_GPB09_HandShake(a, b)
#endif /* USED_GPIO_TEST_HANDSHAKE */


#endif /* _GPIO_H_ */
