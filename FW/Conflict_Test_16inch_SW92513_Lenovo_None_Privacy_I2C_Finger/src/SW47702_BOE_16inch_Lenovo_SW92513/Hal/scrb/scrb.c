/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : scrb.c
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

#include "hal_def.h"


void SCRB_Initialize(void)
{
	/*
	 * Trim Code Read and Write
	 */
	{
#if 0 /* Old Trim Code */
		unsigned * saddr;
		unsigned int Trimdata = 0;

		FLASH->FACR.tBit.LATENCY = 0x6;
		FLASH->FUSRCTRL.tBit.ECC_EN = 0x1;

		saddr = (unsigned *)0x00020088;
		Trimdata = *saddr;
		SCRB->SYS_ANA_TRIM.tBit.R_MAIN_VREF_TRIM = (Trimdata>>5) & 0xF;
		SCRB->SYS_ANA_TRIM.tBit.R_MAIN_IREF_TRIM = Trimdata & 0x1F;

		saddr = (unsigned *)0x00020084;
		Trimdata = *saddr;
		SCRB->SYS_ANA_TRIM.tBit.R_LDO_TRIM = Trimdata & 0x1F;

		saddr = (unsigned *)0x00020080;
		Trimdata = *saddr;
		SCRB->SYS_ANA_TRIM.tBit.R_OSC12M_ITRIM = (Trimdata>>6) & 0x7;
		SCRB->SYS_ANA_TRIM.tBit.R_OSC12M_VTRIM = Trimdata & 0x3F;

		FLASH->FUSRCTRL.tBit.ECC_EN = 0x3;
		FLASH->FACR.tBit.LATENCY = 0x6;
#else
		tFlashPTTrimCodeInfo_t PTTrimCodeInfo = {0,};

		// Flash access latency - Must do
		FLASH->FACR.tBit.LATENCY = 0x6;			// flash access latency, must be over 6

		SCRB->SYS_OSC_PD_CTL.ulBulk = 0x7;		// for BOD Control

		// Analog Trim setting - Must do
		FLASH->FUSRCTRL.tBit.ECC_EN = 0x1;		//	ECC OFF

		if(FLITF_CheckTrimInfoSectionIntegrity(&PTTrimCodeInfo))
		{
			SCRB->SYS_ANA_TRIM.tBit.R_OSC12M_VTRIM = PTTrimCodeInfo.tTrim1.R_OSC12M_VTRIM;
			SCRB->SYS_ANA_TRIM.tBit.R_OSC12M_ITRIM = PTTrimCodeInfo.tTrim1.R_OSC12M_ITRIM;
			SCRB->SYS_ANA_TRIM.tBit.R_LDO_TRIM = PTTrimCodeInfo.tTrim2.R_LDO_TRIM;
			SCRB->SYS_ANA_TRIM.tBit.R_MAIN_VBGR_CTL = PTTrimCodeInfo.tTrim3.R_MAIN_VBGR_CTL;		//	New Added.
			SCRB->SYS_ANA_TRIM.tBit.R_MAIN_IREF_TRIM = PTTrimCodeInfo.tTrim3.R_MAIN_IREF_TRIM;
			SCRB->SYS_ANA_TRIM.tBit.R_MAIN_VREF_TRIM = PTTrimCodeInfo.tTrim3.R_MAIN_VREF_TRIM;
		}
#ifdef _USE_WITH_BOOT_
	#if USED_TRIMCODE_UPDATE_SECURITY_FUNC
		else
		{
			tSimpleBootFlashCtrlInfo_t * pSimpleBootFlashCtrlInfo = (tSimpleBootFlashCtrlInfo_t *)SRAM_SIMPLE_BOOT_CTRL_INFO_ADDR;
			pSimpleBootFlashCtrlInfo->ulFlashUpdateType = SIMPLE_BOOT_FLASH_UPDATE_TRIM_CODE_WRITE;
			{
				/*
				 * PT Trim Code Update
				 */
				memset((void *)&pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo, 0x0, sizeof(tFlashPTTrimCodeInfo_t));
				pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.ulMagicCode = EFLASH_PT_MAGIC_CODE;

				pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim1.R_OSC12M_VTRIM = 0xA;
				pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim1.R_OSC12M_ITRIM = 0x7;

				pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim2.R_LDO_TRIM = 0x11;

				pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_VBGR_CTL = 0x4;
				pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_IREF_TRIM = 0xF;
				pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.tTrim3.R_MAIN_VREF_TRIM = 0xC;

				pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo.CheckSum = FLITF_Calc32bitCheckSum((uint32_t *)&pSimpleBootFlashCtrlInfo->tFlashPTTrimCodeInfo, EFLASH_ANALOG_TRIM_PT_INFO_WORD_SIZE-1);
			}

			{
				/*
				 * FT Trim Code Update
				 */
				memset((void *)&pSimpleBootFlashCtrlInfo->tFlashFTTrimCodeInfo, 0x0, sizeof(tFlashFTTrimCodeInfo_t));

				pSimpleBootFlashCtrlInfo->tFlashFTTrimCodeInfo.CHIP_ID_ECC = EFLASH_FT_CHIP_ID_CODE;

				pSimpleBootFlashCtrlInfo->tFlashFTTrimCodeInfo.CheckSum = FLITF_Calc32bitCheckSum((uint32_t *)&pSimpleBootFlashCtrlInfo->tFlashFTTrimCodeInfo, EFLASH_ANALOG_TRIM_FT_INFO_WORD_SIZE-1);
			}

			FLITF_FlashInformationRegionWriteOperation();
		}
	#endif /* USED_TRIMCODE_UPDATE_SECURITY_FUNC */
#endif /* _USE_WITH_BOOT_ */

		// Analog Trim setting - Must do
		FLASH->FUSRCTRL.tBit.ECC_EN = 0x3;		//	ECC ON
		// Flash access latency - Must do
		FLASH->FACR.tBit.LATENCY = 0x6;			// flash access latency, must be over 6
#endif
	}

	/*
	 * ECLK OFF시키자!! Default가 Enable이라 PLL On되면 ECLK바로 구동 되어 버림!!
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
#ifdef MODE_I2C
		_SYS_CLK_CTL.tBit.usbcclk_en = NO;
		_SYS_CLK_CTL.tBit.usbhclk_en = NO;
#else /* MODE_I2C */
		_SYS_CLK_CTL.tBit.usbcclk_en = YES;
		_SYS_CLK_CTL.tBit.usbhclk_en = YES;
#endif /* MODE_I2C */
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

#ifdef MODE_I2C
	#if !USED_PEN_MODE_OPERATION
		/*
		 * X-tal Oscillator Off
		 */
		USB_PHY.tBit.oscouten = 0;
	#endif /* !USED_PEN_MODE_OPERATION */
		USB_PHY.tBit.ponrst = 0;
#else /* MODE_I2C */
		USB_PHY.tBit.ponrst = 1;
#endif /* MODE_I2C */
		SCRB->USB_PHY_FC.ulBulk = USB_PHY.ulBulk;
//		SCRB->USB_PHY_FC.ulBulk = 0x31B;		// USB POR ON, USB should be worked after 3msec with this setting.

		medium_delay(3000);
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
#if USED_SPI_NBIT_TRANSMODE
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

		SCRB->PLL_CFG.tBit.pllin_sel = 1;		// 0: int OSC, 1:XTAL (if XTAL, you need stable time 2msec after power on)  // input clk

	#if USED_SW98502_MSPI_16MHz
		#if (SPI_TRANSFER_BIT_NUM == 10)
			SCRB->PLL_CFG.tBit.refdiv = 1;//1;		// M = refdiv+1
			SCRB->PLL_CFG.tBit.outdiv = 0;//1;		// O = 0:1, 1:2, 2:4, 3:8
			SCRB->PLL_CFG.tBit.fbdiv = 36;		// N = fbdiv (>5). 108MHz
		//		SCRB->PLL_CFG.tBit.fbdiv = 28;		// N = fbdiv (>5).	84MHz
		#elif (SPI_TRANSFER_BIT_NUM == 11)
			SCRB->PLL_CFG.tBit.refdiv = 1;//1;		// M = refdiv+1
			SCRB->PLL_CFG.tBit.outdiv = 0;//1;		// O = 0:1, 1:2, 2:4, 3:8
			SCRB->PLL_CFG.tBit.fbdiv = 32;		// N = fbdiv (>5).  288MHz		//	feedback divider
		#elif (SPI_TRANSFER_BIT_NUM == 12)
			SCRB->PLL_CFG.tBit.refdiv = 0;//1;		// M = refdiv+1
			SCRB->PLL_CFG.tBit.outdiv = 0;//1;		// O = 0:1, 1:2, 2:4, 3:8
			SCRB->PLL_CFG.tBit.fbdiv = 16;		// N = fbdiv (>5).  288MHz		//	feedback divider
		#endif
	#else
		#if (SPI_TRANSFER_BIT_NUM == 10)
			SCRB->PLL_CFG.tBit.refdiv = 1;//1;		// M = refdiv+1
			SCRB->PLL_CFG.tBit.outdiv = 0;//1;		// O = 0:1, 1:2, 2:4, 3:8
			SCRB->PLL_CFG.tBit.fbdiv = 36;		// N = fbdiv (>5). 108MHz
		//		SCRB->PLL_CFG.tBit.fbdiv = 28;		// N = fbdiv (>5).	84MHz
		#elif (SPI_TRANSFER_BIT_NUM == 11)
			SCRB->PLL_CFG.tBit.refdiv = 1;//1;		// M = refdiv+1
			SCRB->PLL_CFG.tBit.outdiv = 0;//1;		// O = 0:1, 1:2, 2:4, 3:8
			SCRB->PLL_CFG.tBit.fbdiv = 32;		// N = fbdiv (>5).  288MHz		//	feedback divider
		#elif (SPI_TRANSFER_BIT_NUM == 12)
			SCRB->PLL_CFG.tBit.refdiv = 1;//1;		// M = refdiv+1
			SCRB->PLL_CFG.tBit.outdiv = 0;//1;		// O = 0:1, 1:2, 2:4, 3:8
			SCRB->PLL_CFG.tBit.fbdiv = 32;		// N = fbdiv (>5).  288MHz		//	feedback divider
		#endif
	#endif

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
		SCRB->SYS_MAINCLK_CFG.tBit.pllclkdiv = 1;//0;//1;//0;		// PLL clock divider. PLLCLK/(pllclkdiv+1)
		SCRB->SYS_MAINCLK_CFG.tBit.usbclkdiv = 4;		// USB480 clock divider. 480MHz/(usbclkdiv+1)
	#if (SPI_TRANSFER_BIT_NUM == 10)
		SCRB->SYS_MAINCLK_CFG.tBit.hsclksel = 1;		// HIGH speed clock select. 0:PLLCLK_div, 1:USBCLK480_div
	#elif (SPI_TRANSFER_BIT_NUM == 11)
		SCRB->SYS_MAINCLK_CFG.tBit.hsclksel = 0;		// HIGH speed clock select. 0:PLLCLK_div, 1:USBCLK480_div
	#elif (SPI_TRANSFER_BIT_NUM == 12)
		SCRB->SYS_MAINCLK_CFG.tBit.hsclksel = 0;		// HIGH speed clock select. 0:PLLCLK_div, 1:USBCLK480_div
	#endif
		SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 0;	// 0: INT OSC 1: PLL/USB clock
#else /* USED_SPI_NBIT_TRANSMODE */
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

#ifdef MODE_I2C
	#if USED_PEN_MODE_OPERATION
		SCRB->PLL_CFG.tBit.pllin_sel = 1;		// 0: int OSC, 1:XTAL (if XTAL, you need stable time 2msec after power on)  // input clk
	#else
		SCRB->PLL_CFG.tBit.pllin_sel = 0;		// 0: int OSC, 1:XTAL (if XTAL, you need stable time 2msec after power on)  // input clk
	#endif
#else /* MODE_I2C */
		SCRB->PLL_CFG.tBit.pllin_sel = 1;		// 0: int OSC, 1:XTAL (if XTAL, you need stable time 2msec after power on)  // input clk
#endif /* MODE_I2C */
		SCRB->PLL_CFG.tBit.refdiv = 0;//1;		// M = refdiv+1
		SCRB->PLL_CFG.tBit.outdiv = 0;//1;		// O = 0:1, 1:2, 2:4, 3:8

		SCRB->PLL_CFG.tBit.fbdiv = 16;		// N = fbdiv (>5).  96MHz		//	feedback divider
//		SCRB->PLL_CFG.tBit.fbdiv = 36;		// N = fbdiv (>5). 108MHz
//		SCRB->PLL_CFG.tBit.fbdiv = 28;		// N = fbdiv (>5).	84MHz

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
		SCRB->SYS_MAINCLK_CFG.tBit.pllclkdiv = 1;//1;//0;		// PLL clock divider. PLLCLK/(pllclkdiv+1)
		SCRB->SYS_MAINCLK_CFG.tBit.usbclkdiv = 4;		// USB480 clock divider. 480MHz/(usbclkdiv+1)
		SCRB->SYS_MAINCLK_CFG.tBit.hsclksel = 0;		// HIGH speed clock select. 0:PLLCLK_div, 1:USBCLK480_div
		SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 0;	// 0: INT OSC 1: PLL/USB clock
#endif /* USED_SPI_NBIT_TRANSMODE */
	}

	{
		/*
		 * SSCG control : SSCG input range - 40MHz~50MHz
		 */
#if ((USED_ROIC_DEF == ROIC_SW98500) || (USED_ROIC_DEF == ROIC_SW98502))
	#if USED_SPI_NBIT_TRANSMODE
		#if USED_SW98502_MSPI_16MHz
			#if (SPI_TRANSFER_BIT_NUM == 10) // SPI 18MHz
				SCRB->SSCG_IN_CFG.tBit.sscgplldiv = 2;//1;	// PLLCLK_div. PLLCLK/(sscgplldiv+1)
				SCRB->SSCG_IN_CFG.tBit.sscgusbdiv = 5;//7;	// USBCLK480_div. 480MHz/(sscgusbdiv+1) -> 48MHz input
				SCRB->SSCG_IN_CFG.tBit.sscgin_sel = 0;	// 0: PLLCLK_div, 1:USBCLK480_div
			#elif (SPI_TRANSFER_BIT_NUM == 11) // SPI 20MHz
				SCRB->SSCG_IN_CFG.tBit.sscgplldiv = 2;//1;	// PLLCLK_div. PLLCLK/(sscgplldiv+1)
				SCRB->SSCG_IN_CFG.tBit.sscgusbdiv = 7;	// USBCLK480_div. 480MHz/(sscgusbdiv+1) -> 48MHz input
				SCRB->SSCG_IN_CFG.tBit.sscgin_sel = 0;//1;	// 0: PLLCLK_div, 1:USBCLK480_div
			#elif (SPI_TRANSFER_BIT_NUM == 12) // SPI 18MHz
				SCRB->SSCG_IN_CFG.tBit.sscgplldiv = 3;//1;	// PLLCLK_div. PLLCLK/(sscgplldiv+1)
				SCRB->SSCG_IN_CFG.tBit.sscgusbdiv = 9;	// USBCLK480_div. 480MHz/(sscgusbdiv+1) -> 48MHz input
				SCRB->SSCG_IN_CFG.tBit.sscgin_sel = 0;//1;	// 0: PLLCLK_div, 1:USBCLK480_div
			#endif
		#else
			#if (SPI_TRANSFER_BIT_NUM == 10) // SPI 18MHz
				SCRB->SSCG_IN_CFG.tBit.sscgplldiv = 2;//1;	// PLLCLK_div. PLLCLK/(sscgplldiv+1)
				SCRB->SSCG_IN_CFG.tBit.sscgusbdiv = 5;//7;	// USBCLK480_div. 480MHz/(sscgusbdiv+1) -> 48MHz input
				SCRB->SSCG_IN_CFG.tBit.sscgin_sel = 0;	// 0: PLLCLK_div, 1:USBCLK480_div
			#elif (SPI_TRANSFER_BIT_NUM == 11) // SPI 20MHz
				SCRB->SSCG_IN_CFG.tBit.sscgplldiv = 2;//1;	// PLLCLK_div. PLLCLK/(sscgplldiv+1)
				SCRB->SSCG_IN_CFG.tBit.sscgusbdiv = 7;	// USBCLK480_div. 480MHz/(sscgusbdiv+1) -> 48MHz input
				SCRB->SSCG_IN_CFG.tBit.sscgin_sel = 0;//1;	// 0: PLLCLK_div, 1:USBCLK480_div
			#elif (SPI_TRANSFER_BIT_NUM == 12) // SPI 18MHz
				SCRB->SSCG_IN_CFG.tBit.sscgplldiv = 2;//1;	// PLLCLK_div. PLLCLK/(sscgplldiv+1)
				SCRB->SSCG_IN_CFG.tBit.sscgusbdiv = 7;	// USBCLK480_div. 480MHz/(sscgusbdiv+1) -> 48MHz input
				SCRB->SSCG_IN_CFG.tBit.sscgin_sel = 0;//1;	// 0: PLLCLK_div, 1:USBCLK480_div
			#endif
		#endif
		SCRB->SSCG_IN_CFG.tBit.sscgin_inv = 0;

		#if (SPI_TRANSFER_BIT_NUM == 12) // SPI 18MHz
		SCRB->SSCG_PD_CTL.tBit.R_DSSC_PDB = 0;	// SSCG power on
		#else
		SCRB->SSCG_PD_CTL.tBit.R_DSSC_PDB = 0;	// SSCG power on
		#endif
		medium_delay(300);						// You need stable time

		SCRB->SSCG_OP_CTRL.tBit.R_DSSC_MF = 3;	// Modulation frequency (0~3)
		SCRB->SSCG_OP_CTRL.tBit.R_DSSC_MR = 7;	// Modulation ratio (0~7). 7:2%
//		#if (SPI_TRANSFER_BIT_NUM == 12) // SPI 18MHz
		SCRB->SSCG_PD_CTL.tBit.R_DSSC_EN = 0;	// SSCG operation start
//		#else
//		SCRB->SSCG_PD_CTL.tBit.R_DSSC_EN = 0;	// SSCG operation start
//		#endif

		SCRB->SSCG_IN_CFG.tBit.sscgclk_sel = 0;	// SSCGCLK select. 0: no sscg, 1:sscg out
		SCRB->SSCG_OP_CTRL.tBit.modu_cnt_en = 1;	// SSCG modulation monitoring enable. monitor SSCG_MODU_CNT
	#else /* USED_SPI_NBIT_TRANSMODE */
		SCRB->SSCG_IN_CFG.tBit.sscgplldiv = 1;	// PLLCLK_div. PLLCLK/(sscgplldiv+1)
		SCRB->SSCG_IN_CFG.tBit.sscgusbdiv = 9;	// USBCLK480_div. 480MHz/(sscgusbdiv+1) -> 48MHz input
		SCRB->SSCG_IN_CFG.tBit.sscgin_sel = 0;	// 0: PLLCLK_div, 1:USBCLK480_div
		SCRB->SSCG_IN_CFG.tBit.sscgin_inv = 0;

		SCRB->SSCG_PD_CTL.tBit.R_DSSC_PDB = 1;	// SSCG power on
		medium_delay(300);							// You need stable time

		SCRB->SSCG_OP_CTRL.tBit.R_DSSC_MF = 3;	// Modulation frequency (0~3)
		SCRB->SSCG_OP_CTRL.tBit.R_DSSC_MR = 7;	// Modulation ratio (0~7). 7:2%
		SCRB->SSCG_PD_CTL.tBit.R_DSSC_EN = 1;		// SSCG operation start

		SCRB->SSCG_IN_CFG.tBit.sscgclk_sel = 0;	// SSCGCLK select. 0: no sscg, 1:sscg out
		SCRB->SSCG_OP_CTRL.tBit.modu_cnt_en = 1;	// SSCG modulation monitoring enable. monitor SSCG_MODU_CNT
	#endif /* USED_SPI_NBIT_TRANSMODE */
#else /* ((USED_ROIC_DEF == ROIC_SW98500) || (USED_ROIC_DEF == ROIC_SW98502)) */
		SCRB->SSCG_IN_CFG.tBit.sscgplldiv = 3;//1;	// PLLCLK_div. PLLCLK/(sscgplldiv+1)
		SCRB->SSCG_IN_CFG.tBit.sscgusbdiv = 9;	// USBCLK480_div. 480MHz/(sscgusbdiv+1) -> 48MHz input
		SCRB->SSCG_IN_CFG.tBit.sscgin_sel = 0;	// 0: PLLCLK_div, 1:USBCLK480_div
		SCRB->SSCG_IN_CFG.tBit.sscgin_inv = 0;

	#if (USED_ROIC_DEF == ROIC_SW97500)
		#if USED_SSCG_ON_OFF_CONTORL_AITnTLP_MODE
		SCRB->SSCG_PD_CTL.tBit.R_DSSC_PDB = 1;	// SSCG power on
		#else
		SCRB->SSCG_PD_CTL.tBit.R_DSSC_PDB = 0;	// SSCG power on
		#endif
	#else
		SCRB->SSCG_PD_CTL.tBit.R_DSSC_PDB = 1;	// SSCG power on
	#endif
		medium_delay(300);							// You need stable time

		SCRB->SSCG_OP_CTRL.tBit.R_DSSC_MF = 3;	// Modulation frequency (0~3)
		SCRB->SSCG_OP_CTRL.tBit.R_DSSC_MR = 7;	// Modulation ratio (0~7). 7:2%
		SCRB->SSCG_PD_CTL.tBit.R_DSSC_EN = 1;		// SSCG operation start

	#if (USED_ROIC_DEF == ROIC_SW97500)
		SCRB->SSCG_IN_CFG.tBit.sscgclk_sel = 0;	// SSCGCLK select. 0: no sscg, 1:sscg out
	#else
		SCRB->SSCG_IN_CFG.tBit.sscgclk_sel = 1;	// SSCGCLK select. 0: no sscg, 1:sscg out
	#endif
		SCRB->SSCG_OP_CTRL.tBit.modu_cnt_en = 1;	// SSCG modulation monitoring enable. monitor SSCG_MODU_CNT
#endif /* ((USED_ROIC_DEF == ROIC_SW98500) || (USED_ROIC_DEF == ROIC_SW98502)) */
	}

	{
		/*
		 * PWM clock control
		 */
#if USED_SPI_NBIT_TRANSMODE
		SCRB->SYS_PWMCLK_CFG.tBit.pllclkdiv = 1;//0;	// PLLCLK_div. PLLCLK/(pllclkdiv+1)
		SCRB->SYS_PWMCLK_CFG.tBit.usbclkdiv = 4;	// USBCLK480_div. 480MHz/(usbclkdiv+1) -> 96MHz input
	#if (SPI_TRANSFER_BIT_NUM == 10)
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclksel = 1;	// pre-PWMCLK select. 0:PLLCLK_div, 1:USBCLK480_div
	#elif (SPI_TRANSFER_BIT_NUM == 11)
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclksel = 0;	// pre-PWMCLK select. 0:PLLCLK_div, 1:USBCLK480_div
	#elif (SPI_TRANSFER_BIT_NUM == 12)
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclksel = 0;	// pre-PWMCLK select. 0:PLLCLK_div, 1:USBCLK480_div
	#endif
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclkdiv = 0;//1;	// PWM source clock divider - TSYNC sync. pre-PWMCLK/(pwmclkdiv+1) -> 96MHz
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclkdiv_num = 3;//1;	// PWMDRV_CLK - PWM/ECLK generation clock divide. pre-PWMLCK/(pwmclkdiv_num+1), 3: 12Mhz
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclk_phase_en = 0;// ECLK to TSYNC sync enable
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclkdiv_en = 1;	// PWMDRV_CLK - PWM/ECLK generation clock enable. -> 48MHz
		SCRB->SYS_CLK_CTL.tBit.pwmclk_en = 1;	// PWMCLK on
#else /* USED_SPI_NBIT_TRANSMODE */
		SCRB->SYS_PWMCLK_CFG.tBit.pllclkdiv = 1;//0;	// PLLCLK_div. PLLCLK/(pllclkdiv+1)
		SCRB->SYS_PWMCLK_CFG.tBit.usbclkdiv = 4;	// USBCLK480_div. 480MHz/(usbclkdiv+1) -> 96MHz input
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclksel = 0;	// pre-PWMCLK select. 0:PLLCLK_div, 1:USBCLK480_div
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclkdiv = 0;//1;	// PWM source clock divider - TSYNC sync. pre-PWMCLK/(pwmclkdiv+1) -> 96MHz
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclkdiv_num = 3;//1;	// PWMDRV_CLK - PWM/ECLK generation clock divide. pre-PWMLCK/(pwmclkdiv_num+1), 3: 12Mhz
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclk_phase_en = 0;// ECLK to TSYNC sync enable
		SCRB->SYS_PWMCLK_CFG.tBit.pwmclkdiv_en = 1;	// PWMDRV_CLK - PWM/ECLK generation clock enable. -> 48MHz
		SCRB->SYS_CLK_CTL.tBit.pwmclk_en = 1;	// PWMCLK on
#endif /* USED_SPI_NBIT_TRANSMODE */
	}

	{
		/*
		 * Clock Enable
		 */
		SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 1;		// 1: PLL clk enable
	}

	{
		/*
		 * VDDA(3.3V) BOD Power Down Function Enable
		 * If VDDA level is down(3.3V -> 2.75V(R_VOD_VHLS Set Level (Default 2:2.719V)))), reset mcu
		 */
		SCRB->SYS_OSC_PD_CTL.tBit.R_BOD_PD_N = 1;
	}
}

void SCRB_PLL_Clock_Off(bool_t bUsedSystemClk)
{
	SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 0;		//	main system clk: 12MHz, default: 0
	delay_usec(1);
//	SCRB->SSCG_IN_CFG.tBit.sscgclk_sel = 0;	// SSCGCLK select. 0: no sscg, 1:sscg out
//	SCRB->SSCG_PD_CTL.ulBulk = 0x0;

#ifdef MODE_I2C
	if(bUsedSystemClk == NO)
	{
		/*
		 * I2C는 24M이상에서만 동작 하는 것을 확인
		 * (7+1)8분주 적용 하여 192/8=24M로 구동시켜 야만 I2C동작함. 그 이하는 동작 하지 않음
		 */
		/*
		 * USB는 30M이상에서만 동작 하는 것을 확인
		 * (5+1)6분주 적용 하여 192/6=32M로 구동시켜 야만 USB동작함. 그 이하는 동작 하지 않음
		 */
		/*
		 * Dell Set에서 HID over I2C의 경우, 64M이상에서만 동작 하는 것을 확인
		 * (2+1)6분주 적용 하여 192/3=64M로 구동시켜 야만 HID over I2C동작함. 그 이하는 동작 하지 않음
		 * Set Shurt down시 VDD가 Off된 후 Host로 부터 Touch개수가 몇개인지에 대한 응답을 하기 위해서는 이 이상 구동이 필요함.
		 */
		SCRB->SYS_MAINCLK_CFG.tBit.pllclkdiv = 2;//5;
		delay_usec(1);
		SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 1;		//	main system clk: 12MHz, default: 0
	}
#else /* MODE_I2C */
	#if USED_VTSP_ONLY_HOST_INTERFACE_OFF
	{
		/*
		 * USB and X-tal Oscillator Off
		 */
		NVIC_ClearPendingIRQ(USB_IRQn);
		SCRB->USB_INTR_CLR.ulBulk = 0x7; // USB CM3 Internal Interrupt clear!!
		NVIC_DisableIRQ (USB_IRQn);
		SCRB->USB_PHY_FC.tBit.extctrl_suspendm = 0;
		SCRB->USB_PHY_FC.tBit.ponrst = 0;
		SCRB->USB_PHY_FC.tBit.oscouten = 0;
	}
	#else /* USED_VTSP_ONLY_HOST_INTERFACE_OFF */
	{
		/*
		 * USB는 30M이상에서만 동작 하는 것을 확인
		 * (5+1)6분주 적용 하여 192/6=32M로 구동시켜 야만 USB동작함. 그 이하는 동작 하지 않음
		 */
		SCRB->SYS_MAINCLK_CFG.tBit.pllclkdiv = 5;
		delay_usec(1);
		SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 1;		//	main system clk: 12MHz, default: 0
	}
	#endif /* USED_VTSP_ONLY_HOST_INTERFACE_OFF */

#endif /* MODE_I2C */
	tSYS_CLK_CTL _SYS_CLK_CTL;
	_SYS_CLK_CTL.tBit.wdtclk_en = YES;
	_SYS_CLK_CTL.tBit.timclk0_en = YES;
	_SYS_CLK_CTL.tBit.timclk1_en = NO;
	_SYS_CLK_CTL.tBit.timclk2_en = NO;
	_SYS_CLK_CTL.tBit.timclk3_en = NO;
	_SYS_CLK_CTL.tBit.i2cclk_en = YES;
	_SYS_CLK_CTL.tBit.dspaclk_en = NO;
	_SYS_CLK_CTL.tBit.tdspclk_en = NO;
#ifdef MODE_I2C
	_SYS_CLK_CTL.tBit.usbcclk_en = NO;
	_SYS_CLK_CTL.tBit.usbhclk_en = NO;
#else /* MODE_I2C */
	#if USED_VTSP_ONLY_HOST_INTERFACE_OFF
		_SYS_CLK_CTL.tBit.usbcclk_en = NO;
		_SYS_CLK_CTL.tBit.usbhclk_en = NO;
	#else /* USED_VTSP_ONLY_HOST_INTERFACE_OFF */
		_SYS_CLK_CTL.tBit.usbcclk_en = YES;
		_SYS_CLK_CTL.tBit.usbhclk_en = YES;
	#endif /* USED_VTSP_ONLY_HOST_INTERFACE_OFF */
#endif /* MODE_I2C */
	_SYS_CLK_CTL.tBit.pwmclk_en = NO;
	_SYS_CLK_CTL.tBit.mspiclk_en = NO;
	_SYS_CLK_CTL.tBit.sscgclk_en = NO;
	_SYS_CLK_CTL.tBit.mpiclk_en = NO;
	_SYS_CLK_CTL.tBit.tlvclk_en = NO;

#if USED_VTSP_ONLY_HOST_INTERFACE_OFF
	_SYS_CLK_CTL.tBit.i2cm0clk_en = NO;
	_SYS_CLK_CTL.tBit.i2cm0clk_slp_en = NO;
	_SYS_CLK_CTL.tBit.i2cm1clk_en = NO;
	_SYS_CLK_CTL.tBit.i2cm1clk_slp_en = NO;
#else /* USED_VTSP_ONLY_HOST_INTERFACE_OFF */
	_SYS_CLK_CTL.tBit.i2cm0clk_en = YES;
	_SYS_CLK_CTL.tBit.i2cm0clk_slp_en = YES;
	_SYS_CLK_CTL.tBit.i2cm1clk_en = YES;
	_SYS_CLK_CTL.tBit.i2cm1clk_slp_en = YES;
#endif /* USED_VTSP_ONLY_HOST_INTERFACE_OFF */
	_SYS_CLK_CTL.tBit.osc_deglitch_en = NO;
	SCRB->SYS_CLK_CTL.ulBulk = _SYS_CLK_CTL.ulBulk;

}

void SCRB_PLL_Clock_On(void)
{
#if USED_VTSP_ONLY_HOST_INTERFACE_OFF
	Hal_WDT_ForceReset();
#else /* USED_VTSP_ONLY_HOST_INTERFACE_OFF */
	SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 0;		//	main system clk: 12MHz, default: 0
	delay_usec(1);
	SCRB->SYS_MAINCLK_CFG.tBit.pllclkdiv = 1;
	delay_usec(1);
	SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 1;		//	main system clk: 12MHz, default: 0
	delay_usec(1);
#endif /* USED_VTSP_ONLY_HOST_INTERFACE_OFF */

	tSYS_CLK_CTL _SYS_CLK_CTL;
	_SYS_CLK_CTL.tBit.wdtclk_en = YES;
	_SYS_CLK_CTL.tBit.timclk0_en = YES;
	_SYS_CLK_CTL.tBit.timclk1_en = YES;
	_SYS_CLK_CTL.tBit.timclk2_en = YES;
	_SYS_CLK_CTL.tBit.timclk3_en = YES;
	_SYS_CLK_CTL.tBit.i2cclk_en = YES;
	_SYS_CLK_CTL.tBit.dspaclk_en = YES;
	_SYS_CLK_CTL.tBit.tdspclk_en = YES;
#ifdef MODE_I2C
	_SYS_CLK_CTL.tBit.usbcclk_en = NO;
	_SYS_CLK_CTL.tBit.usbhclk_en = NO;
#else /* MODE_I2C */
	_SYS_CLK_CTL.tBit.usbcclk_en = YES;
	_SYS_CLK_CTL.tBit.usbhclk_en = YES;
#endif /* MODE_I2C */
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
}

void SCRB_USB_Reset(void)
{
	SCRB->SYS_RST_CTL.tBit.usb_rst = 1;
	SCRB->USB_PHY_FC.tBit.ponrst = 0;

	for (int i=0; i<100; i++);

	SCRB->USB_PHY_FC.tBit.ponrst = 1;
	SCRB->SYS_RST_CTL.tBit.usb_rst = 0;
}

void SCRB_Remap_And_Reset(uint8_t _num)
{
	SCRB->SYS_BUS_REMAP = _num;
	SCRB->CM3_REMAP_RESET = 1;
}

#if USED_IDLE_LOW_POWER
void SCRB_Clock_Control(eClK_CTRL_STATUS_t eStatus)
{
	switch(eStatus)
	{
		case CLK_NORMAL_CTRL:
		{
			SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 0;		//	main system clk: 12MHz, default: 0
			delay_usec(1);
			SCRB->SYS_MAINCLK_CFG.tBit.pllclkdiv = 1;
			delay_usec(1);
			SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 1;		//	main system clk: 12MHz, default: 0
			delay_usec(1);
			break;
		}
		case CLK_IDLE_CTRL:
		{
			SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 0;		//	main system clk: 12MHz, default: 0
			delay_usec(1);
#ifdef MODE_I2C
			/*
			 * I2C는 24M이상에서만 동작 하는 것을 확인
			 * (7+1)8분주 적용 하여 192/8=24M로 구동시켜 야만 I2C동작함. 그 이하는 동작 하지 않음
			 */
			SCRB->SYS_MAINCLK_CFG.tBit.pllclkdiv = 5; // (N + 1)
#else
			/*
			 * USB는 30M이상에서만 동작 하는 것을 확인
			 * (5+1)6분주 적용 하여 192/6=32M로 구동시켜 야만 USB동작함. 그 이하는 동작 하지 않음
			 */
			SCRB->SYS_MAINCLK_CFG.tBit.pllclkdiv = 5; // (N + 1)
#endif
			delay_usec(1);
			SCRB->SYS_MAINCLK_CFG.tBit.mainclksel = 1;		//	main system clk: 12MHz, default: 0
			delay_usec(1);
			break;
		}
	}
}
#endif /* USED_IDLE_LOW_POWER */
