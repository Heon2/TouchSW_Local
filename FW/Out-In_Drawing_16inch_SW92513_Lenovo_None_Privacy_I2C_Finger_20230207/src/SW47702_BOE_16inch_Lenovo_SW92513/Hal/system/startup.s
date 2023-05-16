;/******************************************************************************************************
; * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
; *
; * file : startup.s
; * created on : 17. 4. 2017
; * Author : mhjang
; *
; * All rights reserved.
; * Redistribution and use in source and binary forms, with or without
; * modification, are permitted provided that the following conditions are met:
; * - Redistributions of source code must retain the above copyright
; *   notice, this list of conditions and the following disclaimer.
; *   - Redistributions in binary form must reproduce the above copyright
; *   notice, this list of conditions and the following disclaimer in the
; *   documentation and/or other materials provided with the distribution.
; * - Neither the name of SiW nor the names of its contributors may be used
; *   to endorse or promote products derived from this software without
; *   specific prior written permission.
; * *
; * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
; * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
; * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
; * ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
; * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
; * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
; * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
; * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
; * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
; * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
; * POSSIBILITY OF SUCH DAMAGE.
; *******************************************************************************************************/


Stack_Size      EQU     0x00000800 ;2KB

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000400	;1KB

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    VECTOR, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors   DCD     __initial_sp          ; Top of Stack
			DCD     Reset_Handler               ; Reset Handler
			DCD     NMI_Handler                 ; NMI Handler
			DCD     HardFault_Handler           ; Hard Fault Handler
			DCD     MemManage_Handler           ; MPU Fault Handler
			DCD     BusFault_Handler            ; Bus Fault Handler
			DCD     UsageFault_Handler          ; Usage Fault Handler
			DCD     0                           ; Reserved
			DCD     0                           ; Reserved
			DCD     0                           ; Reserved
			DCD     0                           ; Reserved
			DCD     SVC_Handler                 ; SVCall Handler
			DCD     DebugMon_Handler            ; Debug Monitor Handler
			DCD     0                           ; Reserved
			DCD     PendSV_Handler              ; PendSV Handler
			DCD     0             				; SysTick Handler
			
; External Interrupts
            DCD     WDGT_IRQHandler         	;  0: Watchdog Interrupt
            DCD     TIMER_IRQHandler            ;  1: TIMER Interrupt
            DCD     DBG_I2C_IRQHandler        	;  2: Debug I2C Slave Interrupt
            DCD     FLITF_IRQHandler       		;  3: Flash Interrupt
            DCD     DBG_SPI_IRQHandler        	;  4: Debug SPI Slave Interrupt
            DCD     AB_ACC_IRQHandler           ;  5: Abnormal & Stack over Interrupt
            DCD     GDMA_IRQHandler             ;  6: GDMA Transfer Done Interrupt
            DCD     USER_IRQHandler             ;  7: User Interrupt
            DCD     GPIOA_IRQHandler            ;  8: GPIOA Interrupt
            DCD     GPIOM_IRQHandler            ;  9: GPIOM Interrupt
            DCD     VSYNC_IN_IRQHandler         ; 10: VSYNC In Interrupt
            DCD     TSYNC_IN_IRQHandler         ; 11: TSYNC In input Interrupt
            DCD     TSYNC_OUT_IRQHandler        ; 12: TSYNC Out Interrupt
            DCD     PWM_IRQHandler              ; 13: PWM Interrupt
            DCD     DSP_A_IRQHandler            ; 14: DSPA Interrupt
            DCD     DSP_B_IRQHandler            ; 15: TDSP Interrupt
            DCD     USB_IRQHandler              ; 16: USB/USB Suspend mode/USB Low power mode Interrupt
            DCD     0                           ; 17:
            DCD     0                           ; 18:
            DCD     EXTInterface_IRQHandler		; 19: MSPI/TLVDS/MPI Interrupt
            DCD     0         					; 20:
            DCD     0        					; 21:
            DCD     I2C_MST_IRQHandler          ; 22: I2CM0 Interrupt
            DCD     I2C_MST_Sleep_IRQHandler    ; 23: I2CM0 Sleep Interrupt
            DCD     I2C_MST_Wakeup_IRQHandler   ; 24: I2CM0 Wakeup Interrupt
            DCD     I2C_SLV_IRQHandler          ; 25: I2CM1 Interrupt
            DCD     I2C_SLV_Sleep_IRQHandler    ; 26: I2CM1 Sleep Interrupt
            DCD     I2C_SLV_Wakeup_IRQHandler   ; 27: I2CM1 Wakeup Interrupt
            DCD     0                           ; 28: Reserved
            DCD     0                           ; 29: Reserved
            DCD     0                           ; 30: Reserved
            DCD     0                           ; 31: Reserved
            DCD     0                           ; 32: Reserved
            DCD     0                           ; 33: Reserved
            DCD     0                           ; 34: Reserved
            DCD     0                           ; 35: Reserved
            DCD     0                           ; 36: Reserved
            DCD     0                           ; 37: Reserved
__Vectors_End

__Vectors_Size  EQU  __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Reset handler routine
;Reset_Handler    PROC
;                EXPORT  Reset_Handler             [WEAK]
; 	             IMPORT  sys_init
; 	             IMPORT  __main
;                 LDR     R0, =sys_init
;                 BLX     R0
;                 LDR     R0, =__main
;                 BLX     R0
;                ENDP
 
Reset_Handler    PROC
               EXPORT  Reset_Handler             [WEAK]
 			   MOV               r1, #0xE000E000
			   MOVS   r0, #0x10
			   STR                r0, [r1, #0x180]
	             IMPORT  __main
               LDR     R0, =__main
               BLX     R0
               ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler          [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler          [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler           [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler           [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler             [WEAK]
                B       .
                ENDP
;SysTick_Handler PROC
;                EXPORT  SysTick_Handler            [WEAK]
;                B       .
;                ENDP

Default_Handler PROC
                EXPORT  WDGT_IRQHandler         	[WEAK]
                EXPORT  TIMER_IRQHandler            [WEAK]
                EXPORT  DBG_I2C_IRQHandler        	[WEAK]
                EXPORT  FLITF_IRQHandler       		[WEAK]
                EXPORT  DBG_SPI_IRQHandler        	[WEAK]
                EXPORT  AB_ACC_IRQHandler           [WEAK]
                EXPORT  GDMA_IRQHandler             [WEAK]
                EXPORT  USER_IRQHandler             [WEAK]
                EXPORT  GPIOA_IRQHandler            [WEAK]
                EXPORT  GPIOM_IRQHandler            [WEAK]
                EXPORT  VSYNC_IN_IRQHandler         [WEAK]
                EXPORT  TSYNC_IN_IRQHandler         [WEAK]
                EXPORT  TSYNC_OUT_IRQHandler        [WEAK]
                EXPORT  PWM_IRQHandler              [WEAK]
                EXPORT  DSP_A_IRQHandler            [WEAK]
                EXPORT  DSP_B_IRQHandler            [WEAK]
                EXPORT  USB_IRQHandler              [WEAK]
                EXPORT  EXTInterface_IRQHandler     [WEAK]
                EXPORT  I2C_MST_IRQHandler          [WEAK]
                EXPORT  I2C_MST_Sleep_IRQHandler    [WEAK]
                EXPORT  I2C_MST_Wakeup_IRQHandler   [WEAK]
                EXPORT  I2C_SLV_IRQHandler          [WEAK]
                EXPORT  I2C_SLV_Sleep_IRQHandler    [WEAK]
                EXPORT  I2C_SLV_Wakeup_IRQHandler   [WEAK]


WDGT_IRQHandler
TIMER_IRQHandler
DBG_I2C_IRQHandler
FLITF_IRQHandler
DBG_SPI_IRQHandler
AB_ACC_IRQHandler
GDMA_IRQHandler
USER_IRQHandler
GPIOA_IRQHandler
GPIOM_IRQHandler
VSYNC_IN_IRQHandler
TSYNC_IN_IRQHandler
TSYNC_OUT_IRQHandler
PWM_IRQHandler
DSP_A_IRQHandler
DSP_B_IRQHandler
USB_IRQHandler
EXTInterface_IRQHandler
I2C_MST_IRQHandler
I2C_MST_Sleep_IRQHandler
I2C_MST_Wakeup_IRQHandler
I2C_SLV_IRQHandler
I2C_SLV_Sleep_IRQHandler
I2C_SLV_Wakeup_IRQHandler

					ENDP


                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                 IF      :DEF:__MICROLIB
                
                 EXPORT  __initial_sp
                 EXPORT  __heap_base
                 EXPORT  __heap_limit
                
                 ELSE
                
                 IMPORT  __use_two_region_memory
				         EXPORT  __user_initial_stackheap

__user_initial_stackheap

                 LDR     R0, =  Heap_Mem
                 LDR     R1, =(Stack_Mem + Stack_Size)
                 LDR     R2, = (Heap_Mem +  Heap_Size)
                 LDR     R3, = Stack_Mem
                 BX      LR

                 ALIGN

                 ENDIF

                 END

