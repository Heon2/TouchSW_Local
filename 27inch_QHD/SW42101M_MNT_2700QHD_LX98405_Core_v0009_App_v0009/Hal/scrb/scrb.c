/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : scrb.c
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

#include "hal_def.h"


void SCRB_Initialize(void)
{
	// 1. LDO & OSC Calibration
	SCRB->LGD_LDO_FC.ulBulk = (((uint8_t)INFO->CALIB_LDO_b.CAL_SEL)
								| SCB_VECTKEY);
	SCRB->LGD_OSC_FC.ulBulk = (((uint8_t)INFO->CALIB_OSC_b.R_FINE) | (((uint8_t)INFO->CALIB_OSC_b.R_COARSE) << 4)
								| SCB_VECTKEY);

	SCRB->STCALIB.tBit.NOREF = 0x0;  // 0:-, 1:NoRef
	SCRB->STCALIB.tBit.SYSTICK_SRC = 0x2;  // 0:FCLK/8, 1:40kHz, 2:12MHz, 3:-

	tLGD_OSC_UC_t tLGD_OSC_UC;
	tLGD_OSC_UC.ulBulk = SCRB->LGD_OSC_UC.ulBulk;
	tLGD_OSC_UC.tBit.OSC_PDB_12M = 0; // 0 : External, 1 : Internal �궡遺� �겢�윮 �궗�슜�떆 USB媛� �룞�옉�쓣 �븯吏� �븡�뒗�떎. Default瑜� �쇅遺� �겢�윮�쑝濡� �꽕�젙
	tLGD_OSC_UC.tBit.OSC_PDB_40K = 0;
	tLGD_OSC_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->LGD_OSC_UC.ulBulk = tLGD_OSC_UC.ulBulk;
#ifdef MODE_I2C
	tCK_ENA_RUN0_t tCK_ENA_RUN0;
	tCK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
	tCK_ENA_RUN0.tBit.r_USB_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_WDT_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_TIM_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_LFDTX_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_TSPI_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_DSPA_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_DSPB_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_SRAM1_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM2_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM3_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_DMAC_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_I2C_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_FLITF_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_GPIO_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN0.ulBulk = tCK_ENA_RUN0.ulBulk;

	tCK_ENA_RUN1_t tCK_ENA_RUN1;
	tCK_ENA_RUN1.ulBulk = SCRB->CK_ENA_RUN1.ulBulk;
	tCK_ENA_RUN1.tBit.r_MSPI01_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI23_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI45_CLK_ENA = 1;
//	tCK_ENA_RUN1.tBit.r_SIF_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_SFL_CLK_ENA = 0;
	tCK_ENA_RUN1.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN1.ulBulk = tCK_ENA_RUN1.ulBulk;
#else /* MODE_I2C */
	tCK_ENA_RUN0_t tCK_ENA_RUN0;
	tCK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
	tCK_ENA_RUN0.tBit.r_USB_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_WDT_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_TIM_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_LFDTX_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_TSPI_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_DSPA_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_DSPB_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_SRAM1_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM2_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_SRAM3_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_DMAC_CLK_ENA = 0;
	tCK_ENA_RUN0.tBit.r_I2C_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_FLITF_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit.r_GPIO_CLK_ENA = 1;
	tCK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN0.ulBulk = tCK_ENA_RUN0.ulBulk;

	tCK_ENA_RUN1_t tCK_ENA_RUN1;
	tCK_ENA_RUN1.ulBulk = SCRB->CK_ENA_RUN1.ulBulk;
	tCK_ENA_RUN1.tBit.r_MSPI01_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI23_CLK_ENA = 1;
	tCK_ENA_RUN1.tBit.r_MSPI45_CLK_ENA = 1;
//	tCK_ENA_RUN1.tBit.r_SIF_CLK_ENA = 0;
//	tCK_ENA_RUN1.tBit.r_SFL_CLK_ENA = 0;
	tCK_ENA_RUN1.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CK_ENA_RUN1.ulBulk = tCK_ENA_RUN1.ulBulk;
#endif /* MODE_I2C */

	tCLK_SRC_SEL_t tCLK_SRC_SEL;
	tCLK_SRC_SEL.ulBulk = SCRB->CLK_SRC_SEL.ulBulk;
	/*
	 * 0 : 12MHz(Internal or External OSC)
	 * 1 : PLL Out Clock
	 * 2,3 : 40KHz (Internal OSC)
	 */
	tCLK_SRC_SEL.tBit.CCLK_SEL = 0; // System Clock
	tCLK_SRC_SEL.tBit.WDCLK_SEL = 2; // PCLK
	tCLK_SRC_SEL.tBit.TIMCLK_SEL = 0;
	tCLK_SRC_SEL.tBit.SSCGOUT_SEL = 0;
	tCLK_SRC_SEL.tBit.SSCGOUT2X_SEL = 0;//1;
	tCLK_SRC_SEL.tBit.TOUCHCLK_SEL = 0;
	tCLK_SRC_SEL.tBit.PLLOUT_SEL = 0;
	tCLK_SRC_SEL.tBit.SSCGIN_SEL = 0;
	tCLK_SRC_SEL.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CLK_SRC_SEL.ulBulk = tCLK_SRC_SEL.ulBulk;

#if USED_PLL_LOCKED_DEFENSE_CODE
	tUMC_PLL_UC_t tUMC_PLL_UC;
	uint8_t ucPLL_Locked_Retry_Cnt = 0;
	uint8_t ucPLL_Locked_Retry_Max = 5;
	uint32_t ulPLL_Locked_Start = 0;
	uint32_t ulPLL_Locked_TimeOut = 500;

	do {
		/*
		 * PLL 異쒕젰 援ы븯�뒗 怨듭떇
		 *                       Fref X (Feedback divider number)
		 * Fout = --------------------------------------------------------
		 *          (Reference divider number) X (Output divider number)
		 */
		tUMC_PLL_UC.ulBulk = SCRB->UMC_PLL_UC.ulBulk;
		tUMC_PLL_UC.tBit.PLL_STBY_I = 1;
		// 90MHz
#if USED_PLL_OUT_CLK_CONFIG
	#if (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) // MSPI 16M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 16;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 1;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_90MHz) // MSPI 15M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 15;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 1;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_45MHz) // MSPI 11.3M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 15;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 2;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_37p5MHz) // MSPI 9.4M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 25;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 3;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_31p5MHz) // MSPI 7.9M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 21;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 3;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#else /* (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) */ // MSPI 15M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 15;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 1;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#endif /* (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) */
#else /* USED_PLL_OUT_CLK_CONFIG */
#if (TMCU_MAIN_TRIM_CLOCK_SPEED == 90)
		// 90MHz
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 15;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 1;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)

#elif(TMCU_MAIN_TRIM_CLOCK_SPEED == 72)
		// 72MHz
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 24;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 2;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
#endif
#endif /* USED_PLL_OUT_CLK_CONFIG */
		tUMC_PLL_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
		SCRB->UMC_PLL_UC.ulBulk = tUMC_PLL_UC.ulBulk;

		delay_usec(1);

		tUMC_PLL_UC.tBit.PLL_STBY_I = 0;
		tUMC_PLL_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
		SCRB->UMC_PLL_UC.ulBulk = tUMC_PLL_UC.ulBulk;

		if(ucPLL_Locked_Retry_Cnt < ucPLL_Locked_Retry_Max)
		{
			ucPLL_Locked_Retry_Cnt++;
			ulPLL_Locked_Start = getSysTick();
			do {
				if(SCRB->UMC_PLL_IS.tBit.PLL_LOCKED_O == 1)
				{
					break;
				}
			}while (getUSfromTick(getElapsedSYSTICK(ulPLL_Locked_Start)) < ulPLL_Locked_TimeOut);
		}
		else
		{
			Hal_WDT_Init();
			while(1);
		}

	} while(SCRB->UMC_PLL_IS.tBit.PLL_LOCKED_O == 0);

#else /* USED_PLL_LOCKED_DEFENSE_CODE */
	/*
	 * PLL 異쒕젰 援ы븯�뒗 怨듭떇
	 *                       Fref X (Feedback divider number)
	 * Fout = --------------------------------------------------------
	 *          (Reference divider number) X (Output divider number)
	 */
	tUMC_PLL_UC_t tUMC_PLL_UC;
	tUMC_PLL_UC.ulBulk = SCRB->UMC_PLL_UC.ulBulk;
	tUMC_PLL_UC.tBit.PLL_STBY_I = 1;

#if USED_PLL_OUT_CLK_CONFIG
	#if (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) // MSPI 16M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 16;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 1;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_90MHz) // MSPI 15M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 15;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 1;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_45MHz) // MSPI 11.3M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 15;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 2;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_37p5MHz) // MSPI 9.4M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 25;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 3;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_31p5MHz) // MSPI 7.9M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 21;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 3;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#else /* (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) */ // MSPI 15M
		tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
		tUMC_PLL_UC.tBit.FBDIV = 15;	// Feedback divider number = (FBDIV) : (5 ~ 50)
		tUMC_PLL_UC.tBit.OUTDIV = 1;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
	#endif /* (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) */
#else /* USED_PLL_OUT_CLK_CONFIG */
	// 90MHz
	tUMC_PLL_UC.tBit.REFDIV = 0;	// Reference divider number = (REFDIV + 1) : (1 ~ 8)
	tUMC_PLL_UC.tBit.FBDIV = 15;	// Feedback divider number = (FBDIV) : (5 ~ 50)
	tUMC_PLL_UC.tBit.OUTDIV = 1;//1;	// Output divider number = (2^OUTDIV) : (1, 2, 4, 8)
#endif /* USED_PLL_OUT_CLK_CONFIG */
	tUMC_PLL_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->UMC_PLL_UC.ulBulk = tUMC_PLL_UC.ulBulk;
//	GPIO->tGPIO_DIR_1.tBit.GPB10 = 1;
	delay_usec(1); // PLL諛� Clock Divider�꽕�젙 �쟾�씠湲� �븣臾몄뿉.. �뒓由щ떎.. ���왂 1/10�젙�룄..
	tUMC_PLL_UC.tBit.PLL_STBY_I = 0;
	tUMC_PLL_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->UMC_PLL_UC.ulBulk = tUMC_PLL_UC.ulBulk;
#endif /* USED_PLL_LOCKED_DEFENSE_CODE */

#ifdef MODE_I2C
	tUSB_PHY_FC_t tUSB_PHY_FC;
	tUSB_PHY_FC.ulBulk = SCRB->USB_PHY_FC.ulBulk;
	tUSB_PHY_FC.tBit.PLLALIV = 0;
	tUSB_PHY_FC.tBit.PONRST = 0;
	SCRB->USB_PHY_FC.ulBulk = tUSB_PHY_FC.ulBulk;
#else /* MODE_I2C */
	tUSB_PHY_FC_t tUSB_PHY_FC;
	tUSB_PHY_FC.ulBulk = SCRB->USB_PHY_FC.ulBulk;
	tUSB_PHY_FC.tBit.PONRST = 1;
	SCRB->USB_PHY_FC.ulBulk = tUSB_PHY_FC.ulBulk;
#endif /* MODE_I2C */

	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();

	tRST_CTRL_t tRST_CTRL;
	tRST_CTRL.ulBulk = SCRB->RST_CTRL.ulBulk;
	tRST_CTRL.tBit.USB_RSTN_CTRL = 0;
	tRST_CTRL.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->RST_CTRL.ulBulk = tRST_CTRL.ulBulk;

	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();

	tRST_CTRL.tBit.USB_RSTN_CTRL = 1;
	tRST_CTRL.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->RST_CTRL.ulBulk = tRST_CTRL.ulBulk;

#if !USED_PLL_LOCKED_DEFENSE_CODE
	while (SCRB->UMC_PLL_IS.tBit.PLL_LOCKED_O == 0)
	{
	};
#endif /* !USED_PLL_LOCKED_DEFENSE_CODE */

	//FLITF->FACR = 6;	// 120MHz
	//FLITF->FACR = 5;	// 100MHz
	FLITF->FACR = 5;	// 100MHz

	tCLK_DIV_t tCLK_DIV;
	tCLK_DIV.ulBulk = SCRB->CLK_DIV.ulBulk;
	tCLK_DIV.tBit.HCLK_DIV = 0;
	tCLK_DIV.tBit.PCLK_DIV = 1;
#if USED_ECLK_ON_OFF_CONTROL
	tCLK_DIV.tBit.TIMCLK_DIV = 0; /*timer clk : 0(/1), 1(/2), ... 7(/128) */
#else /* USED_ECLK_ON_OFF_CONTROL */
	tCLK_DIV.tBit.TIMCLK_DIV = 2; /*timer clk : 0(/1), 1(/2), ... 7(/128) */
#endif /* USED_ECLK_ON_OFF_CONTROL */
	tCLK_DIV.tBit.WDTCLK_DIV = 3;
	tCLK_DIV.tBit.SSCGIN_DIV = 1;
	tCLK_DIV.tBit.TOUCHCLK_DIV = 0;
	tCLK_DIV.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CLK_DIV.ulBulk = tCLK_DIV.ulBulk;


//	tCLK_SRC_SEL_t tCLK_SRC_SEL;
	tCLK_SRC_SEL.ulBulk = SCRB->CLK_SRC_SEL.ulBulk;
	/*
	 * 0 : 12MHz(Internal or External OSC)
	 * 1 : PLL Out Clock
	 * 2,3 : 40KHz (Internal OSC)
	 */
	tCLK_SRC_SEL.tBit.CCLK_SEL = 1; // PLL Out Clock
	tCLK_SRC_SEL.tBit.WDCLK_SEL = 2; // PCLK
	tCLK_SRC_SEL.tBit.TIMCLK_SEL = 0;
	tCLK_SRC_SEL.tBit.SSCGOUT_SEL = 1;
	tCLK_SRC_SEL.tBit.SSCGOUT2X_SEL = 1;//1;
	tCLK_SRC_SEL.tBit.TOUCHCLK_SEL = 0;
	tCLK_SRC_SEL.tBit.PLLOUT_SEL = 0;
	tCLK_SRC_SEL.tBit.SSCGIN_SEL = 0;
	tCLK_SRC_SEL.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->CLK_SRC_SEL.ulBulk = tCLK_SRC_SEL.ulBulk;


	tLGD_SSC_FC_t tLGD_SSC_FC;
	tLGD_SSC_FC.ulBulk = SCRB->LGD_SSC_FC.ulBulk;
	tLGD_SSC_FC.tBit.SSCG_MR = 0x7;
	tLGD_SSC_FC.tBit.SSCG_MF = 2;
//	tLGD_SSC_FC.tBit.SSCG_FRAC_EN = 0;
//	tLGD_SSC_FC.tBit.SSCG_ICP = 1;
//	tLGD_SSC_FC.tBit.SSCG_RSEL = 1;
//	tLGD_SSC_FC.tBit.SSCG_KVC = 1;
	tCLK_SRC_SEL.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->LGD_SSC_FC.ulBulk = tLGD_SSC_FC.ulBulk;

	tLGD_SSC_UC_t tLGD_SSC_UC;
	tLGD_SSC_UC.ulBulk = SCRB->LGD_SSC_UC.ulBulk;
	tLGD_SSC_UC.tBit.SSCG_PDB = 1;
	tLGD_SSC_UC.tBit.SSCG_EN = 1;//1;
	tLGD_SSC_UC.tBit.SSCG_INIT = 0;
	tLGD_SSC_UC.tBit._VECTKEY = SCB_VECTKEY_VALUE;
	SCRB->LGD_SSC_UC.ulBulk = tLGD_SSC_UC.ulBulk;

//	tPMU_CONTROL_t tPMU_CONTROL;
//	tPMU_CONTROL.ulBulk = SCRB->PMU_CONTROL.ulBulk;
//	tPMU_CONTROL.tBit.DLY_SLP = 4000;
//	tPMU_CONTROL.tBit.BYPASS_SLP = 0;
//	tPMU_CONTROL.tBit.PMUENABLE = SCB_VECTKEY_VALUE;
//	SCRB->PMU_CONTROL.ulBulk = tPMU_CONTROL.ulBulk;
}
