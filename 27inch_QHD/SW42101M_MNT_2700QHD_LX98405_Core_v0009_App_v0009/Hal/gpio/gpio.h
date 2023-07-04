/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : gpio.h
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

#ifndef _GPIO_H_
#define _GPIO_H_


typedef enum
{
	Input					  	= 0x00,
	Output						= 0x01,
	PullupIn					= 0x02
} GpIoconValue_TypeDef;

/**
 * @brief  GPIO Mode Configure Register : Setting Values
 */
typedef enum
{
    GPIO_Mode0_GPIO	= 0x00,		/// GPIO0 Mode
    GPIO_Mode1_AF1	= 0x01,		/// Alternate Function 1 Mode
    GPIO_Mode2_AF2	= 0x02,		/// Alternate Function 2 Mode
    GPIO_Mode3_AF3	= 0x03,		/// Alternate Function 3 Mode
} GpModeValue_TypeDef;

/**
 * @brief  
 */
typedef struct
{
	uint64_t				  GPIO_Pin;
    GpModeValue_TypeDef		  GPIO_Mode;
	GpIoconValue_TypeDef	  GPIO_Config;
} GPIO_InitTypeDef;

/**
 * @brief External Interrupt Initial Params
 */
typedef struct
{
	uint64_t				    GPIO_Pin;
    uint8_t                     LevelDetection;
    uint8_t                     BothEdge;
    uint8_t                     PositivePolarity;
    uint8_t                     EnableInterrupt;
} EXIT_Typedef;
    

#define LEVEL_DETECTION_GPIO		(1)
#define EDGE_DETECTION_GPIO			(0)
#define BOTH_EDGE_GPIO				(1)
#define SINGLE_EDGE_GPIO			(0)
#define POSITIVE_HIGH_GPIO			(1)
#define NEGATIVE_LOW_GPIO			(0)
#define ENABLE_GPIO					(1)
#define DISABLE_GPIO				(0)


/**
  * @brief  Bit_SET and Bit_RESET enumeration
  */
typedef enum
{
    Bit_RESET = 0,
    Bit_SET
}
BitAction;
/**
  * @brief  Bit_HIGHT and Bit_LOW enumeration
  */
typedef enum
{
    LOW = 0,
    HIGH = 1
}EnumBit;

typedef enum
{
	PIN_GPA00	=	0	,
	PIN_GPA01	=	1	,
	PIN_GPA02	=	2	,
	PIN_GPA03	=	3	,
	PIN_GPA04	=	4	,
	PIN_GPA05	=	5	,
	PIN_GPA06	=	6	,
	PIN_GPA07	=	7	,
	PIN_GPA08	=	8	,
	PIN_GPA09	=	9	,
	PIN_GPA10	=	10	,
	PIN_GPA11	=	11	,
	PIN_GPA12	=	12	,
	PIN_GPA13	=	13	,
	PIN_GPA14	=	14	,
	PIN_GPA15	=	15	,
	PIN_GPA16	=	16	,
	PIN_GPA17	=	17	,
	PIN_GPA18	=	18	,
	PIN_GPA19	=	19	,
	PIN_GPA20	=	20	,
	PIN_GPA21	=	21	,
	PIN_GPA22	=	22	,
	PIN_GPA23	=	23	,
	PIN_GPA24	=	24	,
	PIN_GPA25	=	25	,
	PIN_GPA26	=	26	,
	PIN_GPA27	=	27	,
	PIN_GPA28	=	28	,
	PIN_GPA29	=	29	,
	PIN_GPA30	=	30	,
	PIN_GPA31	=	31	,
	PIN_GPA32	=	32	,
	PIN_GPA33	=	33	,
	PIN_GPA34	=	34	,
	PIN_GPA35	=	35	,
	PIN_GPA36	=	36	,
	PIN_GPA37	=	37	,
	PIN_GPB00	=	38	,
	PIN_GPB01	=	39	,
	PIN_GPB02	=	40	,
	PIN_GPB03	=	41	,
	PIN_GPB04	=	42	,
	PIN_GPB05	=	43	,
	PIN_GPB06	=	44	,
	PIN_GPB07	=	45	,
	PIN_GPB08	=	46	,
	PIN_GPB09	=	47	,
	PIN_GPB10	=	48	,
	PIN_GPB11	=	49	,
	PIN_GPB12	=	50	,
	PIN_GPB13	=	51	,
	PIN_GPB14	=	52	,
	PIN_GPB15	=	53

}EnumGPIO;

#include "gpio_define.h"

#define GPIO_Bit_0		((uint32_t)0x0000000000000001) /** Pin 0 select mask */
#define GPIO_Bit_1		((uint32_t)0x0000000000000002) /** Pin 1 select mask */
#define GPIO_Bit_2		((uint32_t)0x0000000000000004) /** Pin 2 select mask */
#define GPIO_Bit_3		((uint32_t)0x0000000000000008) /** Pin 3 select mask */
#define GPIO_Bit_4		((uint32_t)0x0000000000000010) /** Pin 4 select mask */
#define GPIO_Bit_5		((uint32_t)0x0000000000000020) /** Pin 5 select mask */
#define GPIO_Bit_6		((uint32_t)0x0000000000000040) /** Pin 6 select mask */
#define GPIO_Bit_7		((uint32_t)0x0000000000000080) /** Pin 7 select mask */
#define GPIO_Bit_8		((uint32_t)0x0000000000000100) /** Pin 8 select mask */
#define GPIO_Bit_9		((uint32_t)0x0000000000000200) /** Pin 9 select mask */
#define GPIO_Bit_10		((uint32_t)0x0000000000000400) /** Pin 10 select mask */
#define GPIO_Bit_11		((uint32_t)0x0000000000000800) /** Pin 11 select mask */
#define GPIO_Bit_12		((uint32_t)0x0000000000001000) /** Pin 12 select mask */
#define GPIO_Bit_13		((uint32_t)0x0000000000002000) /** Pin 13 select mask */
#define GPIO_Bit_14		((uint32_t)0x0000000000004000) /** Pin 14 select mask */
#define GPIO_Bit_15		((uint32_t)0x0000000000008000) /** Pin 15 select mask */
#define GPIO_Bit_16		((uint32_t)0x0000000000010000) /** Pin 16 select mask */
#define GPIO_Bit_17		((uint32_t)0x0000000000020000) /** Pin 17 select mask */
#define GPIO_Bit_18		((uint32_t)0x0000000000040000) /** Pin 18 select mask */
#define GPIO_Bit_19		((uint32_t)0x0000000000080000) /** Pin 19 select mask */
#define GPIO_Bit_20		((uint32_t)0x0000000000100000) /** Pin 20 select mask */
#define GPIO_Bit_21		((uint32_t)0x0000000000200000) /** Pin 21 select mask */
#define GPIO_Bit_22		((uint32_t)0x0000000000400000) /** Pin 22 select mask */
#define GPIO_Bit_23		((uint32_t)0x0000000000800000) /** Pin 23 select mask */
#define GPIO_Bit_24		((uint32_t)0x0000000001000000) /** Pin 24 select mask */
#define GPIO_Bit_25		((uint32_t)0x0000000002000000) /** Pin 25 select mask */
#define GPIO_Bit_26		((uint32_t)0x0000000004000000) /** Pin 26 select mask */
#define GPIO_Bit_27		((uint32_t)0x0000000008000000) /** Pin 27 select mask */
#define GPIO_Bit_28		((uint32_t)0x0000000010000000) /** Pin 28 select mask */
#define GPIO_Bit_29		((uint32_t)0x0000000020000000) /** Pin 29 select mask */
#define GPIO_Bit_30		((uint32_t)0x0000000040000000) /** Pin 30 select mask */
#define GPIO_Bit_31		((uint32_t)0x0000000080000000) /** Pin 31 select mask */

#define GPIO_Bit_32		((uint64_t)0x0000000100000000) /** Pin 32 select mask */
#define GPIO_Bit_33		((uint64_t)0x0000000200000000) /** Pin 33 select mask */
#define GPIO_Bit_34		((uint64_t)0x0000000400000000) /** Pin 34 select mask */
#define GPIO_Bit_35		((uint64_t)0x0000000800000000) /** Pin 35 select mask */
#define GPIO_Bit_36		((uint64_t)0x0000001000000000) /** Pin 36 select mask */
#define GPIO_Bit_37		((uint64_t)0x0000002000000000) /** Pin 37 select mask */
#define GPIO_Bit_38		((uint64_t)0x0000004000000000) /** Pin 38 select mask */
#define GPIO_Bit_39		((uint64_t)0x0000008000000000) /** Pin 39 select mask */
#define GPIO_Bit_40		((uint64_t)0x0000010000000000) /** Pin 40 select mask */
#define GPIO_Bit_41		((uint64_t)0x0000020000000000) /** Pin 41 select mask */
#define GPIO_Bit_42		((uint64_t)0x0000040000000000) /** Pin 42 select mask */
#define GPIO_Bit_43		((uint64_t)0x0000080000000000) /** Pin 43 select mask */
#define GPIO_Bit_44		((uint64_t)0x0000100000000000) /** Pin 44 select mask */
#define GPIO_Bit_45		((uint64_t)0x0000200000000000) /** Pin 45 select mask */
#define GPIO_Bit_46		((uint64_t)0x0000400000000000) /** Pin 46 select mask */


#define Set_GPB11(val)			(GPIO->tGPIO_DATA_1.tBit.GPB11 = val)
#define Set_GPA36(val)			(GPIO->tGPIO_DATA_1.tBit.GPA36 = val)
#define Set_GPA37(val)			(GPIO->tGPIO_DATA_1.tBit.GPA37 = val)

#define T_GPB11()			(GPIO->tGPIO_DATA_1.tBit.GPB11 ^= 1)
#define T_GPA36()			(GPIO->tGPIO_DATA_1.tBit.GPA36 ^= 1)
#define T_GPA37()			(GPIO->tGPIO_DATA_1.tBit.GPA37 ^= 1)

#define F_GPB09() \
	do { \
		(GPIO->tGPIO_DATA_1.tBit.GPB09 = 1); \
		(GPIO->tGPIO_DATA_1.tBit.GPB09 = 0); \
	} while(0)

#define F_GPB10() \
	do { \
		(GPIO->tGPIO_DATA_1.tBit.GPB10 = 1); \
		(GPIO->tGPIO_DATA_1.tBit.GPB10 = 0); \
	} while(0)

#define F_GPB11() \
	do { \
		(GPIO->tGPIO_DATA_1.tBit.GPB11 = 1); \
		(GPIO->tGPIO_DATA_1.tBit.GPB11 = 0); \
	} while(0)

#define F_GPB36() \
	do { \
		(GPIO->tGPIO_DATA_1.tBit.GPB36 = 1); \
		(GPIO->tGPIO_DATA_1.tBit.GPB36 = 0); \
	} while(0)

#define F_GPB37() \
	do { \
		(GPIO->tGPIO_DATA_1.tBit.GPB37 = 1); \
		(GPIO->tGPIO_DATA_1.tBit.GPB37 = 0); \
	}while(0)


extern void GPIO_Initialize(void);
//extern void GPIO_SetConfiguration();


void init_EXITs(EXIT_Typedef* EXIT_InitStruct);
void writeBitToGPIO(EnumGPIO pin, EnumBit val);
void initGPIOs(GPIO_InitTypeDef* GPIO_InitStruct);
void initGPIO(EnumGPIO pin, GpModeValue_TypeDef GPIO_Mode,GpIoconValue_TypeDef GPIO_Config);
void init_EXIT(EnumGPIO pin, uint8_t LevelDetection, uint8_t BothEdge, uint8_t PositivePolarity, uint8_t EnableInterrupt);

#if USED_GPIO_TEST_HANDSHAKE
extern void _____TEST_GPB09_HandShake(uint32_t ulNum, uint32_t ulusecDelay);
#else /* USED_GPIO_TEST_HANDSHAKE */
#define _____TEST_GPB09_HandShake(a, b)
#endif /* USED_GPIO_TEST_HANDSHAKE */


#endif /* _GPIO_H_ */
