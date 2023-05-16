/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_simple_hal.c
 * created on : 04. 05.2020
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


#include "app_simple_hal.h"
//#include "gpio_define.h"


void SimpleHal_Initialize(tSimpleBootFlashCtrlInfo_t * pSimpleBootFlashCtrlInfo)
{
	/*
	 * Trim Code Write
	 */
	{
//		FLASH->FACR.tBit.LATENCY = 6;
//		// Analog Trim setting - Must do
//		FLASH->FUSRCTRL.ulBulk = 1;//	ECC OFF
//		SimplHal_medium_delay(1000);
//		// Analog Trim setting - Must do
//		FLASH->FUSRCTRL.ulBulk = 3;//	ECC ON
//		FLASH->FACR.tBit.LATENCY = 6;

		SCRB->SYS_ANA_TRIM.tBit.R_OSC12M_VTRIM = pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim1.R_OSC12M_VTRIM;
		SCRB->SYS_ANA_TRIM.tBit.R_OSC12M_ITRIM = pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim1.R_OSC12M_ITRIM;
		SCRB->SYS_ANA_TRIM.tBit.R_LDO_TRIM = pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim2.R_LDO_TRIM;
		SCRB->SYS_ANA_TRIM.tBit.R_MAIN_VBGR_CTL = pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_VBGR_CTL;
		SCRB->SYS_ANA_TRIM.tBit.R_MAIN_IREF_TRIM = pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_IREF_TRIM;
		SCRB->SYS_ANA_TRIM.tBit.R_MAIN_VREF_TRIM = pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_VREF_TRIM;
	}

	/*
	 * ECLK OFF��Ű��!! Default�� Enable�̶� PLL On�Ǹ� ECLK�ٷ� ���� �Ǿ� ����!!
	 */
	PWMDRV->ECLK_CR.tBit.eclk_force_on = 0;
	PWMDRV->ECLK_CR.tBit.eclk_en = 0;

	{
		tSYS_CLK_CTL _SYS_CLK_CTL;
		_SYS_CLK_CTL.tBit.wdtclk_en = YES;
		_SYS_CLK_CTL.tBit.timclk0_en = YES;
		_SYS_CLK_CTL.tBit.timclk1_en = YES;
		_SYS_CLK_CTL.tBit.timclk2_en = YES;
		_SYS_CLK_CTL.tBit.timclk3_en = YES;
		_SYS_CLK_CTL.tBit.i2cclk_en = YES;//YES;
		_SYS_CLK_CTL.tBit.dspaclk_en = YES;
		_SYS_CLK_CTL.tBit.tdspclk_en = YES;
		_SYS_CLK_CTL.tBit.usbcclk_en = YES;
		_SYS_CLK_CTL.tBit.usbhclk_en = YES;
		_SYS_CLK_CTL.tBit.pwmclk_en = YES;
		_SYS_CLK_CTL.tBit.mspiclk_en = YES;
		_SYS_CLK_CTL.tBit.sscgclk_en = YES;
		_SYS_CLK_CTL.tBit.mpiclk_en = NO;
		_SYS_CLK_CTL.tBit.tlvclk_en = NO;
		_SYS_CLK_CTL.tBit.i2cm0clk_en = YES;
		_SYS_CLK_CTL.tBit.i2cm0clk_slp_en = YES;
		_SYS_CLK_CTL.tBit.i2cm1clk_en = YES;
		_SYS_CLK_CTL.tBit.i2cm1clk_slp_en = YES;
		_SYS_CLK_CTL.tBit.osc_deglitch_en = NO;
		SCRB->SYS_CLK_CTL.ulBulk = _SYS_CLK_CTL.ulBulk;

	    SCRB->SYS_RST_CTL.ulBulk = 0x00; /* all release */
	    WDT->WDOG_RSTCLR = 1; // watchdog interrupt status clear

	    SCB->SHCSR |= (7 << 16);
	    SCB->SCR = SCB_SCR_SLEEPDEEP_Msk;
	}

	{
		/*
		 * USB POR set
		 */
		tUSB_PHY_FC USB_PHY;
		USB_PHY.ulBulk = SCRB->USB_PHY_FC.ulBulk;
		USB_PHY.tBit.pllaliv = 0;
		USB_PHY.tBit.ponrst = 1;
		SCRB->USB_PHY_FC.ulBulk = USB_PHY.ulBulk;
//		SCRB->USB_PHY_FC.ulBulk = 0x31B;		// USB POR ON, USB should be worked after 3msec with this setting.


		SimplHal_medium_delay(10000);
		/*
		 * Internal OSC use (12MHz) - Default.
		 */
		SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 0;	//	main system clk: 12MHz, default: 0
		/*
		 * MCLK freq. setting
		 */
		SCRB->SYS_MAINCLK_CFG.tBit.mclksel = 0;	// 0: int OSC, 1:XTAL (if XTAL, you need stable time 2msec after power on)		//	0: internal OSC, 1: External Crystal
		SCRB->SYS_MAINCLK_CFG.tBit.mclkdiv = 15;	// WATCHDOG_BASE_ADDR & timer clock. OSC freq./(mclkdiv+1)    ( default: 12)

		/*
		 * Cache Control
		 */
		SCRB->CACHE_CTRL.tBit.CACHE_EN = 0;	// 1: ENABLE. 0 : disable
		while(SCRB->CACHE_ST != 1)
		{
			;
		}
		SCRB->CACHE_CTRL.tBit.CACHE_FLUSH = 0;
		SCRB->CACHE_CTRL.tBit.CACHE_FLUSH = 1;
		SCRB->CACHE_CTRL.tBit.CACHE_FLUSH = 0;

		SCRB->CACHE_CTRL.tBit.CACHE_BST = 3;	// burst 8
		SCRB->CACHE_CTRL.tBit.CACHE_DEN = 0;//1;	// data enable
		SCRB->CACHE_CTRL.tBit.CACHE_EN = 1;	// 1: ENABLE. 0 : disable
	}

	{
		/*
		 * PLL Power On
		 * 	- VCO range : 150 < (Fin*N)/M < 300 ==> MUST BE !!     // Fin: input clk
		 * 	- PLL clock = (Fin*N)/(M*O)
		 */

#define PLL_RSEL_MAX			(5)
#define PLL_RECOVERY_CNT		(870)	//	870: about 1ms  @12MHz
		uint8_t ucRselIdx = 0;
		uint8_t vucRselValue[PLL_RSEL_MAX] = {3, 2, 1, 0, 4};
		uint32_t ulPllLockCnt = 0;

		SCRB->PLL_CFG.tBit.pll_stby_i = 1;	// PLL power off & control register set

		SCRB->PLL_CFG.tBit.rsel = 4;
		SCRB->PLL_CFG.tBit.pllin_sel = 0;		// 0: int OSC, 1:XTAL (if XTAL, you need stable time 2msec after power on)  // input clk
//		SCRB->PLL_CFG.tBit.pllin_sel = 1;		// 0: int OSC, 1:XTAL (if XTAL, you need stable time 2msec after power on)  // input clk
//		for(int i=0; i<10000; i++);

		SCRB->PLL_CFG.tBit.refdiv	= 0;		// M = refdiv+1
		SCRB->PLL_CFG.tBit.outdiv = 0;		// O = 0:1, 1:2, 2:4, 3:8
		SCRB->PLL_CFG.tBit.fbdiv	= 16;		// N = fbdiv (>5).  96MHz		//	feedback divider
//		SCRB->PLL_CFG.b.fbdiv = 36;			// N = fbdiv (>5). 108MHz
//		SCRB->PLL_CFG.b.fbdiv = 28;			// N = fbdiv (>5).	84MHz

		SCRB->PLL_CFG.tBit.pll_stby_i = 0;	// PLL power on

		while (!SCRB->PLL_LOCK)				// Wait Lock
		{
			ulPllLockCnt++;

			if (ulPllLockCnt > PLL_RECOVERY_CNT)
			{
				SCRB->PLL_CFG.tBit.rsel = vucRselValue[ucRselIdx++];		//	rsel update
				ulPllLockCnt = 0;

				if (ucRselIdx >= PLL_RSEL_MAX)
					ucRselIdx = 0;
			}
		}

		/*
		 * Change PLL clock
		 */
		SCRB->SYS_MAINCLK_CFG.tBit.pllclkdiv	= 1;		// PLL clock divider. PLLCLK/(pllclkdiv+1)
		SCRB->SYS_MAINCLK_CFG.tBit.usbclkdiv	= 4;		// USB480 clock divider. 480MHz/(usbclkdiv+1)
		SCRB->SYS_MAINCLK_CFG.tBit.hsclksel	= 0;		// HIGH speed clock select. 0:PLLCLK_div, 1:USBCLK480_div
		SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 0;		// 0: INT OSC 1: PLL/USB clock
	}

	{
		/*
		 * SSCG control : SSCG input range - 40MHz~50MHz
		 */
		SCRB->SSCG_IN_CFG.tBit.sscgplldiv = 1;	// PLLCLK_div. PLLCLK/(sscgplldiv+1)
		SCRB->SSCG_IN_CFG.tBit.sscgusbdiv = 9;	// USBCLK480_div. 480MHz/(sscgusbdiv+1) -> 48MHz input
		SCRB->SSCG_IN_CFG.tBit.sscgin_sel = 0;	// 0: PLLCLK_div, 1:USBCLK480_div
		SCRB->SSCG_IN_CFG.tBit.sscgin_inv = 0;

		SCRB->SSCG_PD_CTL.tBit.R_DSSC_PDB = 1;	// SSCG power on
		SimplHal_medium_delay(300);							// You need stable time

		SCRB->SSCG_OP_CTRL.tBit.R_DSSC_MF = 3;	// Modulation frequency (0~3)
		SCRB->SSCG_OP_CTRL.tBit.R_DSSC_MR = 7;	// Modulation ratio (0~7). 7:2%
		SCRB->SSCG_PD_CTL.tBit.R_DSSC_EN = 1;		// SSCG operation start

		SCRB->SSCG_IN_CFG.tBit.sscgclk_sel = 1;	// SSCGCLK select. 0: no sscg, 1:sscg out
		SCRB->SSCG_OP_CTRL.tBit.modu_cnt_en = 1;	// SSCG modulation monitoring enable. monitor SSCG_MODU_CNT
	}

	{
		/*
		 * PWM clock control
		 */
		SCRB->SYS_PWMCLK_CFG.tBit.pllclkdiv = 0;	// PLLCLK_div. PLLCLK/(pllclkdiv+1)
		SCRB->SYS_PWMCLK_CFG.tBit.usbclkdiv = 4;	// USBCLK480_div. 480MHz/(usbclkdiv+1) -> 96MHz input
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclksel = 0;	// pre-PWMCLK select. 0:PLLCLK_div, 1:USBCLK480_div
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclkdiv = 0;//1;	// PWM source clock divider - TSYNC sync. pre-PWMCLK/(pwmclkdiv+1) -> 96MHz
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclkdiv_num = 3;//1;	// PWMDRV_CLK - PWM/ECLK generation clock divide. pre-PWMLCK/(pwmclkdiv_num+1), 3: 12Mhz
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclk_phase_en = 0;// ECLK to TSYNC sync enable
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclkdiv_en = 1;	// PWMDRV_CLK - PWM/ECLK generation clock enable. -> 48MHz
		SCRB->SYS_CLK_CTL.tBit.pwmclk_en = 1;	// PWMCLK on
	}

	{
		/*
		 * Clock Enable
		 */
		SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 	1;		// 1: PLL clk enable
	}
}

void SimplHal_medium_delay(uint32_t usec)
{
	/*
	 	Base on 96MHz
	 	1 		:    1.43	us
		5		:    2.78	us
		10 		:    4.58	us
		100 	:   36.08	us
		1000	:  351.4	us
		10000	: 3503.0	us
		time(usec) = 2.854 x (Clock) - 3.019
	*/
    __IO uint32_t i = 0;
    uint32_t ulCheckClk;
    ulCheckClk = ((2854 * usec) - 3019)/1000;

    for (i = 0; i < ulCheckClk; i++)
    {
        __ISB();
    }
}

void SimplHal_FLASH_InitializeRegister(void)
{
	FLASH->FCR2.ulBulk	= 0x0000001F;				//	Set FCR2 default value
	FLASH->FCR1.ulBulk	= 0x00000000;				//	Set FCR1 default value
	FLASH->FAR.ulBulk	= 0x00000000;				//	Set FAR default value
}

void SimplHal_FLASH_POR_Reset(void)
{
	FLASH->FCR.ulBulk		= 0x00002000;			//	CE low
	FLASH->FUSRCTRL.ulBulk	= 0x00000000;			// 	Flash POR low
	SimplHal_medium_delay(10);
	while (!FLASH->FSR.tBit.RBB);
	FLASH->FUSRCTRL.ulBulk	= 0x00000001;			// 	Flash POR high
	SimplHal_medium_delay(10);
	while (!FLASH->FSR.tBit.RBB);
	FLASH->FCR.ulBulk		= 0x00000000;			//	CE high
}

bool_t SimplHal_FLASH_Program_Init(void)
{
	int i;

//	FLASH->FACR.tBit.LATENCY = 6;
	// Analog Trim setting - Must do
//	FLASH->FUSRCTRL.ulBulk = 1;//	ECC OFF


	// Analog Trim setting - Must do
//	FLASH->FUSRCTRL.ulBulk = 3;//	ECC ON
//	FLASH->FACR.tBit.LATENCY = 6;

	SCRB->SYS_BOOT_CTL = 0;
	SCRB->SYS_BUS_REMAP = 1;
	SCRB->SYS_BOOT_CTL = 1;

	for(i = 0; i < 10; i++);

	SCRB->SYS_BOOT_CTL = 0;
	FLASH->FKEYR = 0x76543210;
	FLASH->FKEYR = 0xFEDCBA98;

	if (FLASH->FCR.tBit.LOCK != 0)
		return NO;

	FLASH->ISPMSCR.ulBulk = 0x05FA0001;

	if (FLASH->FSR.tBit.ISP_REGISTER != 1)
		return NO;

	return YES;
}

bool_t SimplHal_FLASH_Erase_Page(uint32_t _addr)
{
//	uint32_t i;

	FLASH->FAR.tBit.Address = (_addr & 0x1FFFF);

//	FLASH->FCR1.tBit.INF = 1;
//	FLASH->FCR1.tBit.PERASE = 1;
	FLASH->FCR1.ulBulk = 0x11;

//	FLASH->FCR.tBit.PER = 1;
//	FLASH->FCR.tBit.STRT = 1;			//	start
	FLASH->FCR.ulBulk = 0x42;

	while(FLASH->FSR.tBit.fsm_scer != 0);
//	for( i=0; i<1000; i++);				//	delay
//
//	while (FLASH->FSR.tBit.RBB == 0);
//	if (FLASH->FSR.tBit.RBB != 1)
//		return NO;	//	fail

	return YES;
}

bool_t SimplHal_FLASH_Program_Page(uint32_t _addr, uint32_t *buf, uint32_t ulWordSize)
{
	uint32_t i;
//	uint32_t * write_buffer = (uint32_t *)&FLASH->FWDRLW01;
	uint32_t * write_buffer = (uint32_t *)0x40008100;

	FLASH->FAR.tBit.Address = (_addr & 0x1FFFF);
	FLASH->FWDRLW = buf[0];		//	address: 0x500
	for(i=1; i<ulWordSize; i++)
	{
		*(write_buffer+i-1) = buf[i];
	}
//	FLASH->FCR1.tBit.INF = 1;
//	FLASH->FCR1.tBit.WRONLY = 1;
	FLASH->FCR1.ulBulk = 0x5;

//	FLASH->FCR.tBit.PG = 1;
//	FLASH->FCR.tBit.STRT = 1;			// start
	FLASH->FCR.ulBulk = 0x41;

	while(FLASH->FSR.tBit.fsm_wrmd != 0);
//	for( i=0; i<1000; i++);				//	delay
//
//	while (FLASH->FSR.tBit.RBB == 0);

//	{
//		uint32_t r;
//		bool_t bReg = YES;
//		uint32_t * ulFlashBuf = (uint32_t *)EFLASH_VID_PID_I2CSLV_1_ADDR;
//		if(buf[2] != EFLASH_BOOT_INFO_WRITE_EN_CODE || ulFlashBuf[2] != EFLASH_BOOT_INFO_WRITE_EN_CODE)
//		{
//			SCRB->SYS_DUMMY0 = buf[0];
//			SCRB->SYS_DUMMY1 = buf[1];
//			TIMER->SYS_DUMMY2 = buf[2];
//			TIMER->SYS_DUMMY3 = buf[3];
//			bReg = NO;
//		}
////		for(r=0; r<ulWordSize; r++)
////		{
////			if(ulFlashBuf[r] != buf[r])
////			{
////				bReg = NO;
////			}
////		}
//
//		if(bReg == NO)
//		{
//			while(1)
//			{
//				SimplHal_medium_delay(500);
//				_gOut(_GPIO_TP_INTR, GPIO_DATA_LOW);
//				SimplHal_medium_delay(2000);
//				_gOut(_GPIO_TP_INTR, GPIO_DATA_HIGH);
//			}
//		}
//		else
//		{
//			while(1)
//			{
//				SimplHal_medium_delay(2000);
//				_gOut(_GPIO_TP_INTR, GPIO_DATA_LOW);
//				SimplHal_medium_delay(2000);
//				_gOut(_GPIO_TP_INTR, GPIO_DATA_HIGH);
//			}
//		}
//	}

	return YES;
}

bool_t SimplHal_FLASH_DisableWriteProtection(void)
{
	bool_t bRet = NO;

	FLASH->FUSRCTRL.tBit.ECC_EN = 0;				//	ECC off

	FLASH->FCR1.ulBulk	= 0x00000100;				//	Select SFR write operation ( TM, 0: main or information, 1: SFR write, 2: SFR Read, 6: SPP )
	FLASH->FCR2.ulBulk	= 0x00000080;				//	SFR write enable & 1 word
	FLASH->FAR.ulBulk	= 0x0000000C;				//	SFR[3] address ( 0: SFR[0], 4: SFR[1], 8: SFR[2], C: SFR[3] )
	FLASH->FWDRLW		= DISABLE_WRITE_PROTECTION;	//	Write protection disable code ( enable: 0x03703270 )
	FLASH->FCR.ulBulk	= 0x80000041;				//	Program start
	while(FLASH->FSR.tBit.fsm_wrmd);				//	wait for program complete

	/*
	 * SFR read
	 */
	FLASH->FCR1.ulBulk	= 0x00000200;				//	Select SFR read operation ( TM, 0: main or information, 1: SFR write, 2: SFR Read, 6: SPP )
	FLASH->FAR.ulBulk	= 0x0000000C;				//	SFR[3] address ( 0: SFR[0], 4: SFR[1], 8: SFR[2], C: SFR[3] )
	FLASH->FCR2.ulBulk	= 0x00000000;				//	1 word
	FLASH->FCR.ulBulk	= 0x80000048;				//	Read start
	while(FLASH->FSR.tBit.fsm_rdmd);				//	wait for read complete
	if (FLASH->FRDRLW == DISABLE_WRITE_PROTECTION)
		bRet = YES;									//	Write protection disable success

	FLASH->FUSRCTRL.tBit.ECC_EN = 1;				//	ECC on

	SimplHal_FLASH_InitializeRegister();						//	Initialize register

	return bRet;
}

bool_t SimplHal_FLASH_Program_UnInit(void)
{
	FLASH->ISPMSCR.ulBulk = 0x05FA0000;
	if (FLASH->FSR.tBit.ISP_REGISTER != 0)
		return NO;

	// Unloking for flash function access
	FLASH->FCR.tBit.LOCK = 1;
	if (FLASH->FCR.tBit.LOCK != 1)
		return NO;

	SCRB->SYS_BUS_REMAP = 0;
//	SCRB->SYS_BOOT_CTL = 0;

	return YES;
}
