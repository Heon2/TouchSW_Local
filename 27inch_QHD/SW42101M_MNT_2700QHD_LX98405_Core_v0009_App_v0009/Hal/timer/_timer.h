
/****************************************************************************************************//**
 * @file     timer.h
 *
 * @brief    CMSIS Cortex-M3 Core Peripheral Access Layer Header File for
 *           default TIGER Device Series
 *
 * @version  Vrev.B
 * @date     19. April 2013
 *
 * @note     Generated with SVDConv V2.73b  on Friday, 19.04.2013 19:56:29
 *           from CMSIS SVD File 'LDC1004A_TIGER_svd.xml' Version rev.B,
 *           created on Monday, 08.04.2013 08:30:30, last modified on Friday, 19.04.2013 10:55:20
 *
 * @par      ARM Limited (ARM) is supplying this software for use with Cortex-M
 *           processor based microcontroller, but can be equally used for other
 *           suitable processor architectures. This file can be freely distributed.
 *           Modifications to this file shall be clearly marked.
 *           
 *           THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *           OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *           MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *           ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *           CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. 
 *
 *******************************************************************************************************/


/* ================================================================================ */
/* ================                     TIMER                      ================ */
/* ================================================================================ */

/**
 * @Brief  Flash Control Register
 */


extern uint8_t TMA0_cnt;
extern uint8_t TMB0_cnt;
extern uint8_t TMA1_cnt;
extern uint8_t TMB1_cnt;

extern uint8_t mode;




typedef struct
{
    //-----------------------------------
    //              Timer0
    //-----------------------------------
    union {   // 0x00 : Timer0
	    __IO uint32_t	Timer0_LoadCount_CR;        // Timer0 Load Count CR 

      struct {
          __IO uint32_t Timer0_LoadCount      : 32; // Timer0 Load Count 
      } Timer0_LoadCount_R_b;
    } ;

    union {   // 0x04 : Timer0
	    __IO uint32_t	Timer0_CurrentValue_SR;     // Timer0 CurrentValue SR

      struct {
          __IO uint32_t Timer0_CurrentValue   : 32; // Timer0 CurrentValue 
      } Timer0_CurrentValue_SR_b;
    } ;

    union {   // 0x08 : Timer0
	    __IO uint32_t	Timer0_CR;                  // Timer0 CR

      struct {
          __IO uint32_t Timer0_En             : 1;  // Timer0 Enable 
          __IO uint32_t Timer0_Mode           : 1;  // Timer0 Mode         
          __IO uint32_t Timer0_InterruptMask  : 1;  // Timer0 InterruptMask
      } Timer0_CR_b;
    } ;

    union {   // 0x0C : Timer0
	    __IO uint32_t	Timer0_EOI_SR;              // Timer0 End of Interrupt SR

      struct {
          __IO uint32_t Timer0_EOI            : 1;  // Timer0 EOI 
      } Timer0_EOI_SR_b;
    } ;

    union {   // 0x10 : Timer0
	    __IO uint32_t	Timer0_Int_SR;              // Timer0 Interrupt SR

      struct {
          __IO uint32_t Timer0_Int            : 1;  // Timer0 Interrupt
      } Timer0_Int_SR_b;
    } ;


    //-----------------------------------
    //              Timer1
    //-----------------------------------
    union {   // 0x14 : Timer1
	    __IO uint32_t	Timer1_LoadCount_CR;        // Timer1 Load Count CR 

      struct {
          __IO uint32_t Timer1_LoadCount      : 32; // Timer1 Load Count 
      } Timer1_LoadCount_R_b;
    } ;

    union {   // 0x18 : Timer1
	    __IO uint32_t	Timer1_CurrentValue_SR;     // Timer1 CurrentValue SR

      struct {
          __IO uint32_t Timer1_CurrentValue   : 32; // Timer1 CurrentValue 
      } Timer1_CurrentValue_SR_b;
    } ;

    union {   // 0x1C : Timer1
	    __IO uint32_t	Timer1_CR;                  // Timer1 CR

      struct {
          __IO uint32_t Timer1_En             : 1;  // Timer1 Enable 
          __IO uint32_t Timer1_Mode           : 1;  // Timer1 Mode         
          __IO uint32_t Timer1_InterruptMask  : 1;  // Timer1 InterruptMask
      } Timer1_CR_b;
    } ;

    union {   // 0x20 : Timer1
	    __IO uint32_t	Timer1_EOI_SR;              // Timer1 End of Interrupt SR

      struct {
          __IO uint32_t Timer1_EOI            : 1;  // Timer1 EOI 
      } Timer1_EOI_SR_b;
    } ;

    union {   // 0x24 : Timer1
	    __IO uint32_t	Timer1_Int_SR;              // Timer1 Interrupt SR

      struct {
          __IO uint32_t Timer1_Int            : 1;  // Timer1 Interrupt
      } Timer1_Int_SR_b;
    } ;


    //-----------------------------------
    //              Timer2
    //-----------------------------------
    union {   // 0x28 : Timer2
	    __IO uint32_t	Timer2_LoadCount_CR;        // Timer2 Load Count CR 

      struct {
          __IO uint32_t Timer2_LoadCount      : 32; // Timer2 Load Count 
      } Timer2_LoadCount_R_b;
    } ;

    union {   // 0x2C : Timer2
	    __IO uint32_t	Timer2_CurrentValue_SR;     // Timer2 CurrentValue SR

      struct {
          __IO uint32_t Timer2_CurrentValue   : 32; // Timer2 CurrentValue 
      } Timer2_CurrentValue_SR_b;
    } ;

    union {   // 0x30 : Timer2
	    __IO uint32_t	Timer2_CR;                  // Timer2 CR

      struct {
          __IO uint32_t Timer2_En             : 1;  // Timer2 Enable 
          __IO uint32_t Timer2_Mode           : 1;  // Timer2 Mode         
          __IO uint32_t Timer2_InterruptMask  : 1;  // Timer2 InterruptMask
      } Timer2_CR_b;
    } ;

    union {   // 0x34 : Timer2
	    __IO uint32_t	Timer2_EOI_SR;              // Timer2 End of Interrupt SR

      struct {
          __IO uint32_t Timer2_EOI            : 1;  // Timer2 EOI 
      } Timer2_EOI_SR_b;
    } ;

    union {   // 0x38 : Timer2
	    __IO uint32_t	Timer2_Int_SR;              // Timer2 Interrupt SR

      struct {
          __IO uint32_t Timer2_Int            : 1;  // Timer2 Interrupt
      } Timer2_Int_SR_b;
    } ;


    //-----------------------------------
    //              Timer3
    //-----------------------------------
    union {   // 0x3C : Timer3
	    __IO uint32_t	Timer3_LoadCount_CR;        // Timer3 Load Count CR 

      struct {
          __IO uint32_t Timer3_LoadCount      : 32; // Timer3 Load Count 
      } Timer3_LoadCount_R_b;
    } ;

    union {   // 0x40 : Timer3
	    __IO uint32_t	Timer3_CurrentValue_SR;     // Timer3 CurrentValue SR

      struct {
          __IO uint32_t Timer3_CurrentValue   : 32; // Timer3 CurrentValue 
      } Timer3_CurrentValue_SR_b;
    } ;

    union {   // 0x44 : Timer3
	    __IO uint32_t	Timer3_CR;                  // Timer3 CR

      struct {
          __IO uint32_t Timer3_En             : 1;  // Timer3 Enable 
          __IO uint32_t Timer3_Mode           : 1;  // Timer3 Mode         
          __IO uint32_t Timer3_InterruptMask  : 1;  // Timer3 InterruptMask
      } Timer3_CR_b;
    } ;

    union {   // 0x48 : Timer3
	    __IO uint32_t	Timer3_EOI_SR;              // Timer3 End of Interrupt SR

      struct {
          __IO uint32_t Timer3_EOI            : 1;  // Timer3 EOI 
      } Timer3_EOI_SR_b;
    } ;

    union {   // 0x4C : Timer3
	    __IO uint32_t	Timer3_Int_SR;              // Timer3 Interrupt SR

      struct {
          __IO uint32_t Timer3_Int            : 1;  // Timer3 Interrupt
      } Timer3_Int_SR_b;
    } ;


    //-----------------------------------
    //              Timer4
    //-----------------------------------
    union {   // 0x50 : Timer4
	    __IO uint32_t	Timer4_LoadCount_CR;        // Timer4 Load Count CR 

      struct {
          __IO uint32_t Timer4_LoadCount      : 32; // Timer4 Load Count 
      } Timer4_LoadCount_R_b;
    } ;

    union {   // 0x54 : Timer4
	    __IO uint32_t	Timer4_CurrentValue_SR;     // Timer4 CurrentValue SR

      struct {
          __IO uint32_t Timer4_CurrentValue   : 32; // Timer4 CurrentValue 
      } Timer4_CurrentValue_SR_b;
    } ;

    union {   // 0x58 : Timer4
	    __IO uint32_t	Timer4_CR;                  // Timer4 CR

      struct {
          __IO uint32_t Timer4_En             : 1;  // Timer4 Enable 
          __IO uint32_t Timer4_Mode           : 1;  // Timer4 Mode         
          __IO uint32_t Timer4_InterruptMask  : 1;  // Timer4 InterruptMask
      } Timer4_CR_b;
    } ;

    union {   // 0x5C : Timer4
	    __IO uint32_t	Timer4_EOI_SR;              // Timer4 End of Interrupt SR

      struct {
          __IO uint32_t Timer4_EOI            : 1;  // Timer4 EOI 
      } Timer4_EOI_SR_b;
    } ;

    union {   // 0x60 : Timer4
	    __IO uint32_t	Timer4_Int_SR;              // Timer4 Interrupt SR

      struct {
          __IO uint32_t Timer4_Int            : 1;  // Timer4 Interrupt
      } Timer4_Int_SR_b;
    } ;


    //-----------------------------------
    //              Timer5
    //-----------------------------------
    union {   // 0x64 : Timer5
	    __IO uint32_t	Timer5_LoadCount_CR;        // Timer5 Load Count CR 

      struct {
          __IO uint32_t Timer5_LoadCount      : 32; // Timer5 Load Count 
      } Timer5_LoadCount_R_b;
    } ;

    union {   // 0x68 : Timer5
	    __IO uint32_t	Timer5_CurrentValue_SR;     // Timer5 CurrentValue SR

      struct {
          __IO uint32_t Timer5_CurrentValue   : 32; // Timer5 CurrentValue 
      } Timer5_CurrentValue_SR_b;
    } ;

    union {   // 0x6C : Timer5
	    __IO uint32_t	Timer5_CR;                  // Timer5 CR

      struct {
          __IO uint32_t Timer5_En             : 1;  // Timer5 Enable 
          __IO uint32_t Timer5_Mode           : 1;  // Timer5 Mode         
          __IO uint32_t Timer5_InterruptMask  : 1;  // Timer5 InterruptMask
      } Timer5_CR_b;
    } ;

    union {   // 0x70 : Timer5
	    __IO uint32_t	Timer5_EOI_SR;              // Timer5 End of Interrupt SR

      struct {
          __IO uint32_t Timer5_EOI            : 1;  // Timer5 EOI 
      } Timer5_EOI_SR_b;
    } ;

    union {   // 0x74 : Timer5
	    __IO uint32_t	Timer5_Int_SR;              // Timer5 Interrupt SR

      struct {
          __IO uint32_t Timer5_Int            : 1;  // Timer5 Interrupt
      } Timer5_Int_SR_b;
    } ;


    //-----------------------------------
    //              Timer6
    //-----------------------------------
    union {   // 0x78 : Timer6
	    __IO uint32_t	Timer6_LoadCount_CR;        // Timer6 Load Count CR 

      struct {
          __IO uint32_t Timer6_LoadCount      : 32; // Timer6 Load Count 
      } Timer6_LoadCount_R_b;
    } ;

    union {   // 0x7C : Timer6
	    __IO uint32_t	Timer6_CurrentValue_SR;     // Timer6 CurrentValue SR

      struct {
          __IO uint32_t Timer6_CurrentValue   : 32; // Timer6 CurrentValue 
      } Timer6_CurrentValue_SR_b;
    } ;

    union {   // 0x80 : Timer6
	    __IO uint32_t	Timer6_CR;                  // Timer6 CR

      struct {
          __IO uint32_t Timer6_En             : 1;  // Timer6 Enable 
          __IO uint32_t Timer6_Mode           : 1;  // Timer6 Mode         
          __IO uint32_t Timer6_InterruptMask  : 1;  // Timer6 InterruptMask
      } Timer6_CR_b;
    } ;

    union {   // 0x84 : Timer6
	    __IO uint32_t	Timer6_EOI_SR;              // Timer6 End of Interrupt SR

      struct {
          __IO uint32_t Timer6_EOI            : 1;  // Timer6 EOI 
      } Timer6_EOI_SR_b;
    } ;

    union {   // 0x88 : Timer6
	    __IO uint32_t	Timer6_Int_SR;              // Timer6 Interrupt SR

      struct {
          __IO uint32_t Timer6_Int            : 1;  // Timer6 Interrupt
      } Timer6_Int_SR_b;
    } ;

    
    //-----------------------------------
    //              Timer7
    //-----------------------------------
    union {   // 0x8C : Timer7
	    __IO uint32_t	Timer7_LoadCount_CR;        // Timer7 Load Count CR 

      struct {
          __IO uint32_t Timer7_LoadCount      : 32; // Timer7 Load Count 
      } Timer7_LoadCount_R_b;
    } ;

    union {   // 0x90 : Timer7
	    __IO uint32_t	Timer7_CurrentValue_SR;     // Timer7 CurrentValue SR

      struct {
          __IO uint32_t Timer7_CurrentValue   : 32; // Timer7 CurrentValue 
      } Timer7_CurrentValue_SR_b;
    } ;

    union {   // 0x94 : Timer7
	    __IO uint32_t	Timer7_CR;                  // Timer7 CR

      struct {
          __IO uint32_t Timer7_En             : 1;  // Timer7 Enable 
          __IO uint32_t Timer7_Mode           : 1;  // Timer7 Mode         
          __IO uint32_t Timer7_InterruptMask  : 1;  // Timer7 InterruptMask
      } Timer7_CR_b;
    } ;

    union {   // 0x98 : Timer7
	    __IO uint32_t	Timer7_EOI_SR;              // Timer7 End of Interrupt SR

      struct {
          __IO uint32_t Timer7_EOI            : 1;  // Timer7 EOI 
      } Timer7_EOI_SR_b;
    } ;

    union {   // 0x9C : Timer7
	    __IO uint32_t	Timer7_Int_SR;              // Timer7 Interrupt SR

      struct {
          __IO uint32_t Timer7_Int            : 1;  // Timer7 Interrupt
      } Timer7_Int_SR_b;
    } ;


    //-----------------------------------
    //    Global Status Register 
    //-----------------------------------
    union {   // 0xA0 : Global Status Register 
	    __IO uint32_t	Timers_Int_SR;              // Timers Interrupt SR

      struct {
          __IO uint32_t Timers_Int            : 8;  // Timers Interrupt
      } Timers_Int_SR_b;
    } ;

    union {   // 0xA4 : Global Status Register 
	    __IO uint32_t	Timers_EOI_SR;              // Timers End of Interrupt SR

      struct {
          __IO uint32_t Timers_EOI            : 8;  // Timers EOI
      } Timers_EOI_SR_b;
    } ;

    union {   // 0xA8 : Global Status Register 
	    __IO uint32_t	Timers_RawInt_SR;           // Timers Raw Interrupt SR

      struct {
          __IO uint32_t Timers_RawInt         : 8;  // Timers Raw Interrupt 
      } Timers_RawInt_SR_b;
    } ;

    union {   // 0xAC : Global Status Register 
	    __IO uint32_t	Timers_Comp_Version_SR;     // Current Verion number of the timers component SR

      struct {
          __IO uint32_t Timers_Comp_Version   : 32; // Current Verion number of the timers component 
      } Timers_Comp_Version_SR_b;
    } ;


}tTIMER_CtrlReg_t;




//typedef struct
//{
////// A
//    union {
//	    __IO uint32_t	TCLR0A;			     //	 Timer0 A Clear Regiser
//
//      struct {
//          __IO uint32_t Tm0AClr : 1; // Timer0 A Clear 
//      } TCLR0A_b;
//    } ;
//
//    union {
//	    __IO uint32_t	TCON0A;			     //	 Timer0 A Control Regiser
//
//      struct {
//          __IO uint32_t Tm0AEn     : 1; // Timer0 A Enable
//          __IO uint32_t Tm0AIntrEn : 1; // Timer0 A Interrupt Enable
//          __IO uint32_t Tm0AClkSel : 2; // Timer0 A Clock Select
//          __IO uint32_t Tm0AMode   : 2; // Timer0 A Mode Select
//          __IO uint32_t Tm0ASize   : 2; // Timer0 A Counter Size Select
//      } TCON0A_b;
//    } ;
//
//    union {
//	    __IO uint32_t	TWIDTH0A;			     //	 Timer0 A Count Width Regiser
//
//      struct {
//          __IO uint32_t Tm0AWIDTH     : 32; // Timer0 A Period Width
//      } TWIDTH0A_b;
//    } ;
//
//    union {
//	    __I uint32_t	LOAD0A;			     //	 Timer0 A Count Load Register
//
//      struct {
//          __IO uint32_t Tm0ACntLoad   : 32; // Timer0 A Counting Value
//      } LOAD0A_b;
//    } ;
/////// B
//    union {
//	    __IO uint32_t	TCLR0B;			     //	 Timer0 B Clear Regiser
//
//      struct {
//          __IO uint32_t Tm0BClr : 1; // Timer0 B Clear 
//      } TCLR0B_b;
//    } ;
//
//    union {
//	    __IO uint32_t	TCON0B;			     //	 Timer0 B Control Regiser
//
//      struct {
//          __IO uint32_t Tm0BEn     : 1; // Timer0 B Enable
//          __IO uint32_t Tm0BIntrEn : 1; // Timer0 B Interrupt Enable
//          __IO uint32_t Tm0BClkSel : 2; // Timer0 B Clock Select
//          __IO uint32_t Tm0BMode   : 2; // Timer0 B Mode Select
//          __IO uint32_t Tm0BSize   : 2; // Timer0 B Counter Size Select
//      } TCON0B_b;
//    } ;
//
//    union {
//	    __IO uint32_t	TWIDTH0B;			     //	 Timer0 B Count Width Regiser
//
//      struct {
//          __IO uint32_t Tm0BWIDTH     : 32; // Timer0 B Period Width
//      } TWIDTH0B_b;
//    } ;
//
//    union {
//	    __I uint32_t	LOAD0B;			     //	 Timer0 B Count Load Register
//
//      struct {
//          __IO uint32_t Tm0BCntLoad   : 32; // Timer0 B Counting Value
//      } LOAD0B_b;
//    } ;
//
//    union {
//	    __I uint32_t	CAPLOW0;			   //	 Capture0 Low Value
//
//      struct {
//          __I uint32_t CaptureLow   : 32; // Timer  Counting High Value 0
//      } CAPLOW0_b;
//    } ;
//
//    union {
//	    __I uint32_t	CAPHIGH0;			   //	 Capture0 High Value
//
//      struct {
//          __I uint32_t CaptureHigh   : 32; // Timer Counting High Value 0
//      } CAPHIGH0_b;
//    } ;
//
//    union {
//	    __IO uint32_t	PWMLOW0;			   //	 PWM Low Value0
//
//      struct {
//          __IO uint32_t PWMLowWidth   : 32; // Timer PWM Low Width Value 0
//      } PWMLOW0_b;
//    } ;
//
//
/////// 1
////// A
//    union {
//	    __IO uint32_t	TCLR1A;			     //	 Timer1 A Clear Regiser
//
//      struct {
//          __IO uint32_t Tm1AClr : 1; // Timer1 A Clear 
//      } TCLR1A_b;
//    } ;
//
//    union {
//	    __IO uint32_t	TCON1A;			     //	 Timer1 A Control Regiser
//
//      struct {
//          __IO uint32_t Tm1AEn     : 1; // Timer1 A Enable
//          __IO uint32_t Tm1AIntrEn : 1; // Timer1 A Interrupt Enable
//          __IO uint32_t Tm1AClkSel : 2; // Timer1 A Clock Select
//          __IO uint32_t Tm1AMode   : 2; // Timer1 A Mode Select
//          __IO uint32_t Tm1ASize   : 2; // Timer1 A Counter Size Select
//      } TCON1A_b;
//    } ;
//
//    union {
//	    __IO uint32_t	TWIDTH1A;			     //	 Timer1 A Count Width Regiser
//
//      struct {
//          __IO uint32_t Tm1AWIDTH     : 32; // Timer1 A Period Width
//      } TWIDTH1A_b;
//    } ;
//
//    union {
//	    __I uint32_t	LOAD1A;			     //	 Timer1 A Count Load Register
//
//      struct {
//          __IO uint32_t Tm1ACntLoad   : 32; // Timer1 A Counting Value
//      } LOAD1A_b;
//    } ;
/////// B
//    union {
//	    __IO uint32_t	TCLR1B;			     //	 Timer1 B Clear Regiser
//
//      struct {
//          __IO uint32_t Tm1BClr : 1; // Timer1 B Clear 
//      } TCLR1B_b;
//    } ;
//
//    union {
//	    __IO uint32_t	TCON1B;			     //	 Timer1 B Control Regiser
//
//      struct {
//          __IO uint32_t Tm1BEn     : 1; // Timer1 B Enable
//          __IO uint32_t Tm1BIntrEn : 1; // Timer1 B Interrupt Enable
//          __IO uint32_t Tm1BClkSel : 2; // Timer1 B Clock Select
//          __IO uint32_t Tm1BMode   : 2; // Timer1 B Mode Select
//          __IO uint32_t Tm1BSize   : 2; // Timer1 B Counter Size Select
//      } TCON1B_b;
//    } ;
//
//    union {
//	    __IO uint32_t	TWIDTH1B;			     //	 Timer1 B Count Width Regiser
//
//      struct {
//          __IO uint32_t Tm1BWIDTH     : 32; // Timer1 B Period Width
//      } TWIDTH1B_b;
//    } ;
//
//    union {
//	    __I uint32_t	LOAD1B;			     //	 Timer1 B Count Load Register
//
//      struct {
//          __IO uint32_t Tm1BCntLoad   : 32; // Timer1 B Counting Value
//      } LOAD1B_b;
//    } ;
//
//    union {
//	    __I uint32_t	CAPLOW1;			   //	 Capture1 Low Value
//
//      struct {
//          __IO uint32_t CaptureLow   : 32; // Timer  Counting High Value 1
//      } CAPLOW1_b;
//    } ;
//
//    union {
//	    __I uint32_t	CAPHIGH1;			   //	 Capture1 High Value
//
//      struct {
//          __IO uint32_t CaptureHigh   : 32; // Timer Counting High Value 1
//      } CAPHIGH1_b;
//    } ;
//
//    union {
//	    __IO uint32_t	PWMLOW1;			   //	 PWM Low Value1
//
//      struct {
//          __IO uint32_t PWMLowWidth   : 32; // Timer PWM Low Width Value 1
//      } PWMLOW1_b;
//    } ;
//
//    union {
//	    __IO uint32_t	CONFIG;			     //	 Timer Configuration Register
//
//      struct {
//          __IO uint32_t  Tm0CapMode       : 1; // Timer0 Capture Mode 
//          __IO uint32_t  Tm0PwmMode       : 1; // Timer0 Pulse Width Modulator Mode 
//          __IO uint32_t  Tm1CapMode       : 1; // Timer1 Capture Mode 
//          __IO uint32_t  Tm1PwmMode       : 1; // Timer1 Pulse Width Modulator Mode 
//          __IO uint32_t  Tm0AIntrAutoClr  : 1; // Timer0 A Interrupt Auto Clear  
//          __IO uint32_t  Tm0BIntrAutoClr  : 1; // Timer0 B Interrupt Auto Clear 
//          __IO uint32_t  Tm1AIntrAutoClr  : 1; // Timer1 A Interrupt Auto Clear 
//          __IO uint32_t  Tm1BIntrAutoClr  : 1; // Timer1 B Interrupt Auto Clear
//      } CONFIG_b;
//    } ;
//
//    union {
//	    __IO uint32_t	LRAWINTSTATUS;    //	 Timer Raw Level Inerrupt Status Register
//
//      struct {
//          __IO uint32_t  Tm0ARLIS       : 1; // Timer0 A Raw Level Interrupt Status
//          __IO uint32_t  Tm0BRLIS       : 1; // Timer0 B Raw Leve1 Interrupt Status
//          __IO uint32_t  Tm1ARLIS       : 1; // Timer1 A Raw Leve1 Interrupt Status
//          __IO uint32_t  Tm1BRLIS       : 1; // Timer1 B Raw Level Interrupt Status
//      } RAWLINTSTATUS_b;
//    } ;
//
//    union {
//	    __IO uint32_t	LINTSTATUS;	        //	 Timer Mask Level Inerrupt Status Register
//
//      struct {
//          __IO uint32_t  Tm0AMLIS       : 1; // Timer0 A Mask Level Interrupt Status
//          __IO uint32_t  Tm0BMLIS       : 1; // Timer0 B Mask Leve1 Interrupt Status
//          __IO uint32_t  Tm1AMLIS       : 1; // Timer1 A Mask Leve1 Interrupt Status
//          __IO uint32_t  Tm1BMLIS       : 1; // Timer1 B Mask Level Interrupt Status
//      } LINTSTATUS_b;
//    } ;
//
//    union {
//	    __IO uint32_t	INTRMODE;	        //	 Timer Interrupt Mode Edeg : Level
//
//      struct {
//          __IO uint32_t  Tm0AINTRMode         : 1; // Timer0 A Interrupt Detect Mode Select
//          __IO uint32_t  Tm0BINTRMode         : 1; // Timer0 B Interrupt Detect Mode Select
//          __IO uint32_t  Tm1AINTRMode         : 1; // Timer1 A Interrupt Detect Mode Select
//          __IO uint32_t  Tm1BINTRMode         : 1; // Timer1 B Interrupt Detect Mode Select
//      } INTRMODE_b;
//    } ;
//
//    union {
//	    __IO uint32_t	RAWEINTSTATUS;    //	 Timer Raw Edge Inerrupt Status Register
//
//      struct {
//          __IO uint32_t  Tm0AREIS       : 1; // Timer0 A Raw Edge Interrupt Status
//          __IO uint32_t  Tm0BREIS       : 1; // Timer0 B Raw Edge Interrupt Status
//          __IO uint32_t  Tm1AREIS       : 1; // Timer1 A Raw Edge Interrupt Status
//          __IO uint32_t  Tm1BREIS       : 1; // Timer1 B Raw Edge Interrupt Status
//      } RAWEINTSTATUS_b;
//    } ;
//
//    union {
//	    __IO uint32_t	EINTSTATUS;	        //	 Timer Mask Edge Inerrupt Status Register
//
//      struct {
//          __IO uint32_t  Tm0AMEIS       : 1; // Timer0 A Mask Edge Interrupt Status
//          __IO uint32_t  Tm0BMEIS       : 1; // Timer0 B Mask Edge Interrupt Status
//          __IO uint32_t  Tm1AMEIS       : 1; // Timer1 A Mask Edge Interrupt Status
//          __IO uint32_t  Tm1BMEIS       : 1; // Timer1 B Mask Edge Interrupt Status
//      } EINTSTATUS_b;
//    } ;
//       
//}TIMER_TypeDef;




