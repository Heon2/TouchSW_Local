/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : MFTP.h
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

/** @addtogroup MFTP
  * @{
  */

#ifndef _MFTP_H_
#define _MFTP_H_

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
/* -------------------  Cortex-M3 Processor Exceptions Numbers  ------------------- */
  Reset_IRQn                    = -15,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn           = -14,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = -13,              /*!<   3  Hard Fault, all classes of Fault                                 */
  MemoryManagement_IRQn         = -12,              /*!<   4  Memory Management, MPU mismatch, including Access Violation
                                                         and No Match                                                          */
  BusFault_IRQn                 = -11,              /*!<   5  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory
                                                         related Fault                                                         */
  UsageFault_IRQn               = -10,              /*!<   6  Usage Fault, i.e. Undef Instruction, Illegal State Transition    */
  SVCall_IRQn                   =  -5,              /*!<  11  System Service Call via SVC instruction                          */
  DebugMonitor_IRQn             =  -4,              /*!<  12  Debug Monitor                                                    */
  PendSV_IRQn                   =  -2,              /*!<  14  Pendable request for system service                              */
//  SysTick_IRQn                  =  -1,              /*!<  15  System Tick Timer                                                */
/* -----------------------  MFTP Specific Interrupt Numbers  ----------------------- */
  WDGT_IRQn						=   0,              /*!<   X  WatchDog Timer                                                   */
  TIMER_IRQn					=   1,              /*!<   X  TIMER                                                            */
  DBG_I2C_IRQn					=   2,              /*!<   X  Debug I2C Slave                                         		   */
  FLITF_IRQn					=   3,              /*!<   X  Flash                                                            */
  DBG_SPI_IRQn					=   4,              /*!<   X  Debug SPI Slave                                                  */
  AB_ACC_IRQn					=   5,              /*!<   X  Abnormal Access Detection                                        */
  GDMA_IRQn						=   6,              /*!<   X  GDMA Done                                                        */
  USER_IRQn						=   7,              /*!<   X  User Interrupt                                                   */
  GPIOA_IRQn					=   8,              /*!<   X  GPIO A                                                           */
  GPIOM_IRQn					=   9,              /*!<   X  GPIO M                                                           */
  VSYNC_IN_IRQn					=  10,              /*!<   X  VSync In                                                         */
  TSYNC_IN_IRQn					=  11,              /*!<   X  TSync In                                                         */
  TSYNC_OUT_IRQn				=  12,              /*!<   X  TSync Out                                                        */
  PWMDRV_IRQn					=  13,              /*!<   X  PWM                                                              */
  DSP_A_IRQn					=  14,              /*!<   X  DSP A                                                            */
  DSP_B_IRQn					=  15,              /*!<   X  DSP B                                                            */
  USB_IRQn						=  16,              /*!<   X  USB                                                              */
// Reserved						=  17,
// Reserved						=  18,
  EXTInterface_IRQn				=  19,          	/*!<   X  MPI / T-LVDS / MSPI											   */
// Reserved						=  20,
// Reserved						=  21,
  I2C_MST_IRQn               	=  22,     			/*!< I2CM0 Interrupt         					                           */
  I2C_MST_SLEEP_IRQn         	=  23,     			/*!< I2CM0 Sleep Interrupt                                                 */
  I2C_MST_WAKEUP_IRQn        	=  24,     			/*!< I2CM0 Wakeup Interrupt                                                */
  I2C_SLV_IRQn               	=  25,     			/*!< I2CM1 Interrupt                                                       */
  I2C_SLV_SLEEP_IRQn         	=  26,     			/*!< I2CM1 Sleep Interrupt                                                 */
  I2C_SLV_WAKEUP_IRQn        	=  27,     			/*!< I2CM1 Wakeup Interrupt                                                */

} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the Cortex-M3 Processor and Core Peripherals---------------- */
#define __CM3_REV                 0x0201            /*!< Cortex-M3 Core Revision                                               */
#define __MPU_PRESENT                  0            /*!< MPU present or not                                                    */
#define __NVIC_PRIO_BITS               3            /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0            /*!< Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include <core_cm3.h>                               /*!< Cortex-M3 processor and core peripherals                              */

#if defined ( __CC_ARM   )
#define __BITBAND					__attribute__ ((bitband))
#define __PACKED                    __attribute__ ((packed))
#define __ALIGNED4                  __attribute__ ((aligned(4)))
#define __INTERRUPT                 __attribute__ ((interrupt))
#define __WEAK                      __attribute__ ((weak))
#elif defined ( __ICCARM__ )
#define __NOP           __no_operation                              /*!< no operation intrinsic in IAR Compiler */

#elif defined ( __GNUC__ )
#define __BITBAND					__attribute__ ((bitband))
#define __PACKED                    __attribute__ ((packed))
#define __ALIGNED4                  __attribute__ ((aligned(4)))
#define __INTERRUPT                 __attribute__ ((interrupt))
#define __WEAK                      __attribute__ ((weak))
#endif
/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */


/** @addtogroup Device_Peripheral_Registers
  * @{
  */


/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif


/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)

#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif

/*
Code Memory
FLASH: 128kB
0x00000000~0x0001FFFF

Code Memory
SRAM: 64kB
0x10000000~0x1000FFFF

System Memory
SRAM: 64kB
0x20000000~0x2000FFFF

System Memory
SRAM: 32kB
0x20010000~0x20017FFF

System Memory
SRAM: 32kB
0x20018000~0x2001FFFF

MSPI Memory
SRAM: 64kB
0x20020000~0x2002FFFF
*/
#define USED_MSPI_MODIFY				(0)
/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */
#define BASE_INFO                       0x00020000UL

#define BASE_SRAM1                      0x20000000UL
#define BASE_SRAM2                      0x20010000UL
#define BASE_SRAM3                      0x20020000UL
#define BASE_SRAM_END					0x2002D000UL
#define BASE_RAW_SRAM					0x20040000UL
#define BASE_USB_SRAM					0x20100000UL

#define BASE_SCRB                       0x40000000UL
#define BASE_GPIO                       0x40000100UL
#define BASE_WDT                       	0x4000017CUL
#define BASE_TIMER                      0x4000019CUL
#define BASE_DBGSERIAL                  0x40000200UL
#define BASE_GDMA	                    0x40000300UL //LFSR + GDMA + CRC
#define BASE_DSPB						0x40001000UL
#define BASE_PWMDRV                     0x40002000UL
#define BASE_DSPA                       0x40003000UL
#define BASE_MSPI                       0x40004000UL
#define BASE_TLVDS						0x40006000UL
#define BASE_I2C_1                      0x40007000UL
#define BASE_I2C_2                      0x40007080UL
#define BASE_FLASH						0x40008000UL	// Flash


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */
#define INFO                            ((INFO_TypeDef        *) BASE_INFO  )
#define SCRB                            ((tSCRB_CtrlReg_t     *) BASE_SCRB  )
#define GPIO                            ((tGPIO_CtrlReg_t     *) BASE_GPIO)
#define WDT                            	((tWDT_CtrlReg_t      *) BASE_WDT  )
#define TIMER                           ((tTIMER_CtrlReg_t    *) BASE_TIMER )
#define DBGSERIAL                       ((tDBGSERIAL_CtrlReg_t*) BASE_DBGSERIAL )
#define GDMA                            ((tGDMA_CtrlReg_t     *) BASE_GDMA  )
#define DSP_CON	                        ((tDSPB_CtrlReg_t     *) BASE_DSPB  )
#define PWMDRV                          ((tPWMDRV_CtrlReg_t   *) BASE_PWMDRV)
#define DSPA                            ((tDSPA_CtrlReg_t     *) BASE_DSPA  )
#define MSPI                            ((tMSPI_CtrlReg_t     *) BASE_MSPI  )
#define TLVDS                           ((tTLVDS_CtrlReg_t    *) BASE_TLVDS )
#define I2C_1                           ((tI2C_CtrlReg_t      *) BASE_I2C_1   )
#define I2C_2                           ((tI2C_CtrlReg_t      *) BASE_I2C_2   )
#define FLASH							((tFLASH_CtrlReg_t    *) BASE_FLASH   )



/* -------------------  Include System Peripheral CMSIS Definition ------------------ */
#include "_scrb.h"
#include "_gpio.h"
#include "_wdgt.h"
#include "_timer.h"
#include "_dbgserial.h"
#include "_gdma.h"
#include "_dspB.h"
#include "_pwmdrv.h"
#include "_dspA.h"
#include "_mspi.h"
#include "_tlvds.h"
#include "_flitf.h"
#include "_i2c.h"

//#include "_tspi.h"




/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group MFTP */
/** @} */ /* End of group LG Display */

/** @addtogroup Exported_macro
  * @{
  */
#define HW_REG(addr) (*((volatile unsigned long *)(addr)))
#define READ_MEMORY32(Reg)		(*(__IO uint32_t*)Reg)
#define READ_MEMORY16(Reg)		(*(__IO uint16_t*)Reg)
#define READ_MEMORY8(Reg)		(*(__IO uint8_t*)Reg)
#define WRITE_MEMORY32(reg,value) 	(READ_MEMORY32(reg) = value)
#define WRITE_MEMORY16(reg,value) 	(READ_MEMORY16(reg) = value)
#define WRITE_MEMORY8(reg,value)		(READ_MEMORY8(reg) = value)
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))
#define CLEAR_REG(REG)        ((REG) = (0x0))
#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define __I     volatile const            /*!< defines 'read only' permissions      */
#define __O     volatile                  /*!< defines 'write only' permissions     */
#define __IO    volatile                  /*!< defines 'read / write' permissions   */

/* -------------------  Bit Definition ------------------ */
#define BIT0		((uint32_t)0x0000000000000001) /** Bit 0 select mask */
#define BIT1		((uint32_t)0x0000000000000002) /** Bit 1 select mask */
#define BIT2		((uint32_t)0x0000000000000004) /** Bit 2 select mask */
#define BIT3		((uint32_t)0x0000000000000008) /** Bit 3 select mask */
#define BIT4		((uint32_t)0x0000000000000010) /** Bit 4 select mask */
#define BIT5		((uint32_t)0x0000000000000020) /** Bit 5 select mask */
#define BIT6		((uint32_t)0x0000000000000040) /** Bit 6 select mask */
#define BIT7		((uint32_t)0x0000000000000080) /** Bit 7 select mask */
#define BIT8		((uint32_t)0x0000000000000100) /** Bit 8 select mask */
#define BIT9		((uint32_t)0x0000000000000200) /** Bit 9 select mask */
#define BIT10		((uint32_t)0x0000000000000400) /** Bit 10 select mask */
#define BIT11		((uint32_t)0x0000000000000800) /** Bit 11 select mask */
#define BIT12		((uint32_t)0x0000000000001000) /** Bit 12 select mask */
#define BIT13		((uint32_t)0x0000000000002000) /** Bit 13 select mask */
#define BIT14		((uint32_t)0x0000000000004000) /** Bit 14 select mask */
#define BIT15		((uint32_t)0x0000000000008000) /** Bit 15 select mask */
#define BIT16		((uint32_t)0x0000000000010000) /** Bit 16 select mask */
#define BIT17		((uint32_t)0x0000000000020000) /** Bit 17 select mask */
#define BIT18		((uint32_t)0x0000000000040000) /** Bit 18 select mask */
#define BIT19		((uint32_t)0x0000000000080000) /** Bit 19 select mask */
#define BIT20		((uint32_t)0x0000000000100000) /** Bit 20 select mask */
#define BIT21		((uint32_t)0x0000000000200000) /** Bit 21 select mask */
#define BIT22		((uint32_t)0x0000000000400000) /** Bit 22 select mask */
#define BIT23		((uint32_t)0x0000000000800000) /** Bit 23 select mask */
#define BIT24		((uint32_t)0x0000000001000000) /** Bit 24 select mask */
#define BIT25		((uint32_t)0x0000000002000000) /** Bit 25 select mask */
#define BIT26		((uint32_t)0x0000000004000000) /** Bit 26 select mask */
#define BIT27		((uint32_t)0x0000000008000000) /** Bit 27 select mask */
#define BIT28		((uint32_t)0x0000000010000000) /** Bit 28 select mask */
#define BIT29		((uint32_t)0x0000000020000000) /** Bit 29 select mask */
#define BIT30		((uint32_t)0x0000000040000000) /** Bit 30 select mask */
#define BIT31		((uint32_t)0x0000000080000000) /** Bit 31 select mask */
#define BIT32		((uint64_t)0x0000000100000000) /** Bit 32 select mask */
#define BIT33		((uint64_t)0x0000000200000000) /** Bit 33 select mask */
#define BIT34		((uint64_t)0x0000000400000000) /** Bit 34 select mask */
#define BIT35		((uint64_t)0x0000000800000000) /** Bit 35 select mask */
#define BIT36		((uint64_t)0x0000001000000000) /** Bit 36 select mask */
#define BIT37		((uint64_t)0x0000002000000000) /** Bit 37 select mask */
#define BIT38		((uint64_t)0x0000004000000000) /** Bit 38 select mask */
#define BIT39		((uint64_t)0x0000008000000000) /** Bit 39 select mask */
#define BIT40		((uint64_t)0x0000010000000000) /** Bit 40 select mask */
#define BIT41		((uint64_t)0x0000020000000000) /** Bit 41 select mask */
#define BIT42		((uint64_t)0x0000040000000000) /** Bit 42 select mask */
#define BIT43		((uint64_t)0x0000080000000000) /** Bit 43 select mask */
#define BIT44		((uint64_t)0x0000100000000000) /** Bit 44 select mask */
#define BIT45		((uint64_t)0x0000200000000000) /** Bit 45 select mask */
#define BIT46		((uint64_t)0x0000400000000000) /** Bit 46 select mask */
#define BIT(X)		(1<<(X)) /** Bit X select mask */
#define vBIT0(X)		(X<<(0))
#define vBIT1(X)		(X<<(1))
#define vBIT2(X)		(X<<(2))
#define vBIT3(X)		(X<<(3))
#define vBIT4(X)		(X<<(4))
#define vBIT5(X)		(X<<(5))
#define vBIT6(X)		(X<<(6))
#define vBIT7(X)		(X<<(7))
#define vBIT8(X)		(X<<(8))
#define vBIT9(X)		(X<<(9))


#ifndef _BV
#define _BV( x )            ( 1 << (x) )
#endif
#define x_BV( x )           0


#define BYTE7(X)    ((X & 0xff00000000000000) >> 56)
#define BYTE6(X)    ((X & 0x00ff000000000000) >> 48)
#define BYTE5(X)    ((X & 0x0000ff0000000000) >> 40)
#define BYTE4(X)    ((X & 0x000000ff00000000) >> 32)
#define BYTE3(X)    ((X & 0x00000000ff000000) >> 24)
#define BYTE2(X)    ((X & 0x0000000000ff0000) >> 16)
#define BYTE1(X)    ((X & 0x000000000000ff00) >> 8)
#define BYTE0(X)    ((X & 0x00000000000000ff) >> 0)

#define SHORT0(X)   ((X & 0x000000000000FFFF) >>  0)
#define SHORT1(X)   ((X & 0x00000000FFFF0000) >>  16)
#define SHORT2(X)   ((X & 0x0000FFFF00000000) >>  32)
#define SHORT3(X)   ((X & 0xFFFF000000000000) >>  48)

#define WORD0(X)    ((X & 0x00000000FFFFFFFF) >>  0)
#define WORD1(X)    ((X & 0xFFFFFFFF00000000) >> 32)

#ifndef signof
#define signof(expr)       ((typeof(expr)) -1 < ((typeof(expr)) 0))
#endif /* signof */

#define GET_ARRAY_(x)       (sizeof(x)/sizeof(*(x)))

#define _PSTR(x)            #x
#define PSTR(x)             _PSTR(x)

typedef enum  {RESET = 0, SET = 1}         	FlagStatus, ITStatus;
typedef enum  {DISABLE = 0, ENABLE = 1}  	FunctionalState;
typedef enum  {ERROR = 0, SUCCESS = 1}     	ErrorStatus;
typedef enum  {ODD = 0, EVEN = 1}           ParityNum;


#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
typedef unsigned char bool_t;

#define ON						(0==0)
#define OFF						(1==0)

#define YES						(0==0)
#define NO						(1==0)

#define TRUE					(0==0)
#define FALSE					(1==0)

#define IS_TRUE(X)				((X) != 0)
#define IS_FALSE(X)				((X) == 0)

#define MSB_2BYTE(x)			(((x)>>8)&0xFF)
#define LSB_2BYTE(x)			((x)&0xFF)

#define TO_BE_DEFINED			(0)

/* -------------------  Other User Definition ------------------ */

#ifndef NULL
#define NULL                ((void *)0)
#endif

#define MSB(x)              (((x)>>8) & 0xFF)
#define LSB(x)              ((x) & 0xFF)
#define MSB1(x)       		(((x)>>24)&0xFF)
#define MSB2(x)       		(((x)>>16)&0xFF)
#define LSB1(x)       		(((x)>>8)&0xFF)
#define LSB2(x)       		((x)&0xFF)

#ifndef MAX
#define MAX( x, y )         ( ( ( x ) > ( y ) ) ? ( x ) : ( y ) )
#endif

#ifndef MIN
#define MIN( x, y )         ( ( ( x ) < ( y ) ) ? ( x ) : ( y ) )
#endif

#ifndef QUOT
#define QUOT( x, y )        ( ( ( x ) + ( y / 2 ) ) / ( y ) )
#endif

#ifndef MOD
#define MOD( x, y )         ( ( ( x )+( y ) )%( y ) )
#endif

#ifndef ABS
#define ABS( x )            (( ( x ) >= 0 )? (x) : -(x))
#endif

/** @} */ /* End of group Exported_macro */
#ifdef __cplusplus
}
#endif


#endif  /* _MFTP_H_ */
