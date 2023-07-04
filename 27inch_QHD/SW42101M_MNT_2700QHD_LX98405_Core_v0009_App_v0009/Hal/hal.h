/****************************************************************************************************//**
* Copyright (c) 2017 - 2025 SiliconWorks LIMITED
*
* file : hal.h
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

#ifndef _HAL_H_
#define _HAL_H_


#define I2C_SLAVE_ADDR					(0x34)


#define SVCall_IRQn_Priority									(1)
#define PendSV_IRQn_Priority									((1UL << __NVIC_PRIO_BITS) - 1UL)
/* -----------------------  MFTP Specific Interrupt Numbers  ----------------------- */
#define WDT_IRQn_Priority										(4)
#define EXTI0_IRQn_Priority										(1)//(3) // Operation Time of GPIO ISR is Must Short!!
#define EXTI1_IRQn_Priority										(3)
#define TIMER_IRQn_Priority										(5)
#define I2C_IRQn_Priority										(1)
#define TSPI_IRQn_Priority										(2)
#define USB_IRQn_Priority										(0)
#define PWMDRV_IRQn_Priority									(3)
#define MSPI_IRQn_Priority										(0)
#define GPDMA_IRQn_Priority										(4)
#define DSP_A_IRQn_Priority										(3)
#define DSP_B_IRQn_Priority										(3)
#define PLL_IRQn_Priority										(1)
#define FLITF_IRQn_Priority										(1)


enum enumIRQPriority 
{
    IRQ_PRIORITY_UWDT = 0,
    IRQ_PRIORITY_EXTI0,
    IRQ_PRIORITY_EXTI1,
    IRQ_PRIORITY_TIMER0,
    IRQ_PRIORITY_PWMDRV,
    IRQ_PRIORITY_USB,
    IRQ_PRIORITY_I2C,
    IRQ_PRIORITY_BOD,
    IRQ_PRIORITY_TSPI,
    IRQ_PRIORITY_MSPI,
    IRQ_PRIORITY_GPDMA,
    IRQ_PRIORITY_HWACC,
    IRQ_PRIORITY_FLITF,
    IRQ_PRIORITY_UART,
    IRQ_PRIORITY_TIMER123,
};

#define BLOCK_RESET_DELAY \
			do {\
				__NOP(); \
				__NOP(); \
				__NOP(); \
				__NOP(); \
				__NOP(); \
			} while(0);

extern __IO tHalInterruptHandle_t tHalIntrHandle;;

//extern __IO uint32_t gTSyncInRisingCnt;
//extern __IO uint32_t gMspiCounterPen;
//extern __IO uint32_t isFirstFrame;
//extern __IO uint32_t gDoneMSPI;
//extern __IO uint32_t gSensingMode;
//#if USED_IDLE_MODE_CONTROL
//extern __IO eOP_CONTROL_MODE_t gOperationIntrHandle;
//#endif /* USED_IDLE_MODE_CONTROL */


void initBoardGPIO(void);
void initMSPI_Pins(void);
extern void initECLK(void);
#if USED_ECLK_ON_OFF_CONTROL
void HAL_SetECLKOnOffControl(bool_t bIsEn);
bool_t HAL_GetECLKOnOffControl(void);
void HAL_ECLK_On(void);
void HAL_ECLK_Off(void);
#endif /* USED_ECLK_ON_OFF_CONTROL */

#if USED_TPIC_MUXEN_ON_OFF_CONTROL
void HAL_SetTPICMuxEnControl(bool_t bIsEn);
bool_t HAL_GetTPICMuxEnControl(void);
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */

extern bool_t Hal_sric_start(bool_t cmuxoff);
extern void Hal_VccOff_State(void);

#define NVIC_INT_CTRL_REG		SCB->ICSR
#define NVIC_PENDSVSET_BIT		( 1UL << 28UL )

void callPendSV(void);

/*
 * NOTE : New Function
 */
extern void HAL_Initialize(bool_t bIsLPWG);
#if USED_PEN_MODE_OPERATION
extern void Interrupt_Init(void);
#endif /* USED_PEN_MODE_OPERATION */

extern eSENSING_CHANGE_MODE_t HAL_GetSensingChangeMode(void);
extern void HAL_SetSensingChangeMode(eSENSING_CHANGE_MODE_t mode);
extern eSENSING_MODE_t HAL_GetSensingMode(void);
extern void HAL_SetSensingMode(eSENSING_MODE_t mode);
extern bool_t HAL_CheckSensningModeChange(eSENSING_CHANGE_MODE_t mode);
extern void HAL_SetLocalIndex(uint8_t index, uint8_t val);
extern uint16_t * HAL_GetBaseImagePointer(eSENSING_MODE_t mode, eBaseImageType_t type);

#if USED_MCU_IDLE_LOW_PWR_CONTROL
extern uint32_t Hal_Exit_MCU_Sleep(void);
extern uint32_t Hal_Enter_MCU_Sleep(void);
#endif /* USED_MCU_IDLE_LOW_PWR_CONTROL */

#if USED_LPWG_MCU_SLEEP
extern void Hal_WaitSampleDoneSleep(void);
extern void Hal_WaitModernStanbySleep(void);
#endif /* USED_LPWG_MCU_SLEEP */

#endif /* _HAL_H_ */
