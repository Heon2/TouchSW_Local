;******************** (C) COPYRIGHT 2009 STMicroelectronics ********************
;* File Name          : startup.s
;* Author             : LG Display
;* Version            : V0.1
;* Date               : 04/14/2016
;* Description        : MFTP vector table for RVMDK 
;*                      toolchain. 
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler
;*                      - Set the vector table entries with the exceptions ISR address
;*                      - Branches to __main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the CortexM3 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;* <<< Use Configuration Wizard in Context Menu >>>   
;*******************************************************************************
; THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
; WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
; AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
; INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
; CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
; INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
;*******************************************************************************

; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

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
                AREA    RESET, DATA, READONLY
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
			DCD     SysTick_Handler             ; SysTick Handler
			
			; External Interrupts
			DCD		WDT_IRQHandler		    ; IRS#00 : Watchdog Timer Interrupt
			DCD   EXTI0_IRQHandler			; IRS#01 : EXTI0 Interrupt
			DCD   EXTI1_IRQHandler			; IRS#02 : EXTI1 Interrupt
			DCD		TIMER_IRQHandler			; IRS#03 : Timer Interrupt 
			DCD		I2C_IRQHandler			  ; IRS#04 : I2C Interrupt
			DCD		TSPI_IRQHandler			  ; IRS#05 : TSPI Interrupt
			DCD		USB_IRQHandler			  ; IRS#06 : USB Interrupt 
      DCD		PWMDRV_IRQHandler			; IRS#07 : PWMDRV Interrupt
			DCD		MSPI_IRQHandler			  ; IRS#08 : MSPI Interrupt
			DCD		GPDMA_IRQHandler		  ; IRS#09 : GPDMA Interrupt
			DCD		DSP_A_IRQHandler		  ; IRS#10 : DSPA(LGD) Interrupt
			DCD		DSP_B_IRQHandler		  ; IRS#11 : DSPB(SiW) Interrupt
			DCD		PLL_IRQHandler			  ; IRS#12 : PLL Interrupt
      DCD   FLITF_IRQHandler			; IRS#13 : Flash Controller Interrupt
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
SysTick_Handler PROC
                EXPORT  SysTick_Handler            [WEAK]
                B       .
                ENDP

Default_Handler PROC

			      EXPORT		WDT_IRQHandler		[WEAK]  ; IRS#00 : Watchdog Timer Interrupt
			      EXPORT    EXTI0_IRQHandler	[WEAK]  ; IRS#01 : EXTI0 Interrupt
			      EXPORT    EXTI1_IRQHandler	[WEAK]  ; IRS#02 : EXTI1 Interrupt
			      EXPORT		TIMER_IRQHandler	[WEAK]	; IRS#03 : Timer Interrupt 
			      EXPORT		I2C_IRQHandler		[WEAK]  ; IRS#04 : I2C Interrupt
			      EXPORT		TSPI_IRQHandler		[WEAK]  ; IRS#05 : TSPI Interrupt
			      EXPORT		USB_IRQHandler		[WEAK]  ; IRS#06 : USB Interrupt 
            EXPORT		PWMDRV_IRQHandler	[WEAK]	; IRS#07 : PWMDRV Interrupt
			      EXPORT		MSPI_IRQHandler		[WEAK]  ; IRS#08 : MSPI Interrupt
			      EXPORT		GPDMA_IRQHandler	[WEAK]  ; IRS#09 : GPDMA Interrupt
			      EXPORT		DSP_A_IRQHandler	[WEAK]  ; IRS#10 : DSPA(LGD) Interrupt
			      EXPORT		DSP_B_IRQHandler	[WEAK]  ; IRS#11 : DSPB(SiW) Interrupt
			      EXPORT		PLL_IRQHandler		[WEAK]  ; IRS#12 : PLL Interrupt
            EXPORT    FLITF_IRQHandler	[WEAK]  ; IRS#13 : Flash Controller Interrupt
				

WDT_IRQHandler		
EXTI0_IRQHandler	
EXTI1_IRQHandler	
TIMER_IRQHandler	
I2C_IRQHandler		  
TSPI_IRQHandler		
USB_IRQHandler		
PWMDRV_IRQHandler	
MSPI_IRQHandler		
GPDMA_IRQHandler	
DSP_A_IRQHandler	
DSP_B_IRQHandler	
PLL_IRQHandler		
FLITF_IRQHandler	  
	 


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

;******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE*****
