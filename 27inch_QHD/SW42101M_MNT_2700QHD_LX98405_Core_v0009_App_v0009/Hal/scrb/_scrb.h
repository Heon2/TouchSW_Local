/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _scrb.h
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

#ifndef __SCRB_H_
#define __SCRB_H_


/* ================================================================================ */
/* ================                      SCR                       ================ */
/* ================================================================================ */

/**
 * @Brief  SCR Control Register
 */
typedef union
{
	struct
	{
		__I uint32_t METAL_REV		: 4;
		__I uint32_t FULL_REV		: 4;
		__I uint32_t CHIP_NAME		: 16;
		__I uint32_t reserved		: 8;
	} tBit;
	__I uint32_t ulBulk;
} tDEVICE_ID_t;

typedef union
{
	struct
	{
		__I uint32_t LOCKUP		: 1;
		__I uint32_t HALTED		: 1;
		__I uint32_t reserved	: 30;
	} tBit;
	__I uint32_t ulBulk;
} tCM3_STATUS_t;

typedef union
{
	struct
	{
		__IO uint32_t RST_STS_CLR	: 1;
		__I uint32_t SYSTEM_RST		: 1;
		__I uint32_t WDT_RST		: 1;
		__I uint32_t EXT_RST		: 1;
		__I uint32_t reserved		: 28;
	} tBit;
	__IO uint32_t ulBulk;
} tRST_STATUS_t;

typedef union
{
	struct
	{
		__IO uint32_t I2C_BLK		: 1;
		__IO uint32_t I2C_WAKEUP	: 1;
		__IO uint32_t I2C_SLEEP		: 1;
		__I uint32_t reserved		: 29;
	} tBit;
	__IO uint32_t ulBulk;
} tINTR_I2C_CFG_t;

typedef union
{
	struct
	{
		__IO uint32_t INTR_USR_WDT			: 1;
		__IO uint32_t INTR_EXTI0			: 1;
		__IO uint32_t INTR_EXTI1			: 1;
		__IO uint32_t INTR_TIMER			: 1;
		__IO uint32_t INTR_I2C				: 1;
		__IO uint32_t INTR_TSPI				: 1;
		__IO uint32_t INTR_USB				: 1;
		__IO uint32_t INTR_LFDTX			: 1;
		__IO uint32_t INTR_MSPI				: 1;
		__IO uint32_t INTR_GDMA				: 1;
		__IO uint32_t INTR_DSPA				: 1;
		__IO uint32_t INTR_DSPB				: 1;
		__IO uint32_t INTR_PLL				: 1;
		__IO uint32_t INTR_FLITF			: 1;
		__IO uint32_t INTR_LOCK_WDT			: 1;
		__IO uint32_t INTR_I2C_wakeup		: 1;
		__IO uint32_t INTR_USB_SUSMPENDM	: 1;
		__IO uint32_t INTR_USB_LPMEN		: 1;
		__I uint32_t reserved				: 14;
	} tBit;
	__IO uint32_t ulBulk;
} tINTR_NMI_CFG_t;

typedef union
{
	struct
	{
		__IO uint32_t TENMS			: 24;
		__IO uint32_t SKEW			: 1;
		__IO uint32_t NOREF			: 1;
		__IO uint32_t SYSTICK_SRC	: 2;
		__I uint32_t reserved		: 4;
	} tBit;
	__IO uint32_t ulBulk;
} tSTCALIB_t;

typedef union
{
	struct
	{
		__IO uint32_t r_USB_CLK_ENA		: 1;
		__IO uint32_t r_WDT_CLK_ENA		: 1;
		__IO uint32_t r_TIM_CLK_ENA		: 1;
		__IO uint32_t r_LFDTX_CLK_ENA	: 1;
		__IO uint32_t r_TSPI_CLK_ENA	: 1;
		__IO uint32_t r_DSPA_CLK_ENA	: 1;
		__IO uint32_t r_DSPB_CLK_ENA	: 1;
		__IO uint32_t r_SRAM1_CLK_ENA	: 1;
		__IO uint32_t r_SRAM2_CLK_ENA	: 1;
		__IO uint32_t r_SRAM3_CLK_ENA	: 1;
		__IO uint32_t r_DMAC_CLK_ENA	: 1;
		__IO uint32_t r_I2C_CLK_ENA		: 1;
		__IO uint32_t r_FLITF_CLK_ENA	: 1;
		__IO uint32_t r_GPIO_CLK_ENA	: 1;
		__I uint32_t reserved			: 2;
		__O uint32_t _VECTKEY			: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tCK_ENA_RUN0_t;

typedef union
{
	struct
	{
		__IO uint32_t r_MSPI01_CLK_ENA	: 1;
		__IO uint32_t r_MSPI23_CLK_ENA	: 1;
		__IO uint32_t r_MSPI45_CLK_ENA	: 1;
		__IO uint32_t r_SIF_CLK_ENA		: 1;
		__IO uint32_t r_SFL_CLK_ENA		: 1;
		__I uint32_t reserved			: 11;
		__O uint32_t _VECTKEY			: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tCK_ENA_RUN1_t;

typedef union
{
	struct
	{
		__IO uint32_t s_USB_CLK_ENA		: 1;
		__IO uint32_t s_WDT_CLK_ENA		: 1;
		__IO uint32_t s_TIM_CLK_ENA		: 1;
		__IO uint32_t s_LFDTX_CLK_ENA	: 1;
		__IO uint32_t s_TSPI_CLK_ENA	: 1;
		__IO uint32_t s_DSPA_CLK_ENA	: 1;
		__IO uint32_t s_DSPB_CLK_ENA	: 1;
		__IO uint32_t s_SRAM1_CLK_ENA	: 1;
		__IO uint32_t s_SRAM2_CLK_ENA	: 1;
		__IO uint32_t s_SRAM3_CLK_ENA	: 1;
		__IO uint32_t s_DMAC_CLK_ENA	: 1;
		__IO uint32_t s_I2C_CLK_ENA		: 1;
		__IO uint32_t s_FLITF_CLK_ENA	: 1;
		__IO uint32_t s_GPIO_CLK_ENA	: 1;
		__I uint32_t reserved			: 2;
		__O uint32_t _VECTKEY			: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tCK_ENA_SLP0_t;

typedef union
{
	struct
	{
		__IO uint32_t s_MSPI01_CLK_ENA	: 1;
		__IO uint32_t s_MSPI23_CLK_ENA	: 1;
		__IO uint32_t s_MSPI45_CLK_ENA	: 1;
		__IO uint32_t s_SCB_CLK_ENA		: 1;
		__IO uint32_t s_COR_CLK_ENA		: 1;
		__IO uint32_t s_SYS_CLK_ENA		: 1;
		__IO uint32_t s_SIF_CLK_ENA		: 1;
		__IO uint32_t s_SFL_CLK_ENA		: 1;
		__I uint32_t reserved			: 8;
		__O uint32_t _VECTKEY			: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tCK_ENA_SLP1_t;

typedef union
{
	struct
	{
		__IO uint32_t USB_RSTN_CTRL		: 1;
		__IO uint32_t WDT_RSTN_CTRL		: 1;
		__IO uint32_t TIM_RSTN_CTRL		: 1;
		__IO uint32_t LFDTX_RSTN_CTRL	: 1;
		__IO uint32_t TSPI_RSTN_CTRL	: 1;
		__IO uint32_t DSPA_RSTN_CTRL	: 1;
		__IO uint32_t DSPB_RSTN_CTRL	: 1;
		__IO uint32_t I2C_RSTN_CTRL		: 1;
		__IO uint32_t GPIO_RSTN_CTRL	: 1;
		__IO uint32_t MSPI_RSTN_CTRL	: 1;
		__IO uint32_t SIF_RSTN_CTRL		: 1;
		__IO uint32_t SFL_RSTN_CTRL		: 1;
		__I uint32_t reserved			: 4;
		__O uint32_t _VECTKEY			: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tRST_CTRL_t;

typedef union
{
	struct
	{
		__IO uint32_t DLY_SLP			: 16;
		__IO uint32_t BYPASS_SLP		: 1;
		__IO uint32_t PMUENABLE			: 1;
		__I uint32_t reserved			: 14;
//        	__O uint32_t _VECTKEY			: 16; // Write : 0x05FA NOTE : 설정 불가!!
	} tBit;
	__IO uint32_t ulBulk;
} tPMU_CONTROL_t;

typedef union
{
	struct
	{
		__IO uint32_t CCLK_SEL			: 2;
		__IO uint32_t WDCLK_SEL			: 2;
		__IO uint32_t TIMCLK_SEL		: 2;
		__IO uint32_t SSCGOUT_SEL		: 1;
		__IO uint32_t SSCGOUT2X_SEL		: 1;
		__IO uint32_t TOUCHCLK_SEL		: 2;
		__IO uint32_t PLLOUT_SEL		: 3;
		__IO uint32_t SSCGIN_SEL		: 1;
		__I uint32_t reserved			: 2;
		__O uint32_t _VECTKEY			: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tCLK_SRC_SEL_t;

typedef union
{
	struct
	{
		__IO uint32_t HCLK_DIV			: 3;
		__IO uint32_t PCLK_DIV			: 2;
		__IO uint32_t TIMCLK_DIV		: 3;
		__IO uint32_t WDTCLK_DIV		: 3;
		__IO uint32_t SSCGIN_DIV		: 2;
		__IO uint32_t TOUCHCLK_DIV		: 3;
		__O uint32_t _VECTKEY			: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tCLK_DIV_t;

typedef union
{
	struct
	{
		__IO uint32_t ECLK_SEL		: 4;
		__IO uint32_t ECLK_DIV1		: 3;
		__IO uint32_t ECLK_DIV2		: 2;
		__IO uint32_t USBPHY_SEL	: 2;
		__I uint32_t reserved		: 5;
		__O uint32_t _VECTKEY		: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tECLK_CFG_t;

typedef union
{
	struct
	{
		__IO uint32_t PLL_STBY_I	: 1;	// Powerdown Input : (0)Normal Operation, (1)Powerdown Mode
		__IO uint32_t REFDIV		: 3;	// Reference divider control : M = REFDIV[2:0] + 1, M = {1~8}
		__IO uint32_t FBDIV			: 6;	// Feedback divider control : N = FBDIV[5:0], N = {5~50}
		__IO uint32_t OUTDIV		: 2;	// Output divider control : O = 2*OUTDIV[1:0], O = {1,2,4,8}
		__I uint32_t reserved		: 4;
		__O uint32_t _VECTKEY		: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tUMC_PLL_UC_t;

typedef union
{
	struct
	{
		__IO uint32_t RSEL			: 3;
		__IO uint32_t ICPSELA		: 1;
		__IO uint32_t ICPSELB		: 1;
		__IO uint32_t VCOSETUPSEL	: 1;
		__I uint32_t reserved		: 10;
		__O uint32_t _VECTKEY		: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tUMC_PLL_FC_t;

typedef union
{
	struct
	{
		__IO uint32_t PLL_IE	: 1;
		__IO uint32_t PLL_IEV	: 1;
		__IO uint32_t PLL_IBE	: 1;
		__I uint32_t reserved	: 29;
	} tBit;
	__IO uint32_t ulBulk;
} tUMC_PLL_IC_t;

typedef union
{
	struct
	{
		__O uint32_t PLL_INTC		: 1;
		__I uint32_t PLL_MIS		: 1;
		__I uint32_t PLL_RIS		: 1;
		__I uint32_t PLL_LOCKED_O	: 1;
		__I uint32_t reserved		: 28;
	} tBit;
	__IO uint32_t ulBulk;
} tUMC_PLL_IS_t;

typedef union
{
	struct
	{
		__IO uint32_t OSC_PDB_12M	: 1;
		__IO uint32_t OSC_PDB_40K	: 1;
		__I uint32_t reserved		: 14;
		__O uint32_t _VECTKEY		: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tLGD_OSC_UC_t;

typedef union
{
	struct
	{
		__IO uint32_t IREF_TST		: 1;
		__IO uint32_t OSC_TRIM		: 7;
		__IO uint32_t LOSC_TRIM		: 4;
		__I uint32_t reserved		: 4;
		__O uint32_t _VECTKEY		: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tLGD_OSC_FC_t;

typedef union
{
	struct
	{
		__IO uint32_t CAL_SEL  		:  4;
		__I uint32_t VSEL_OUT 		:  1;
		__I uint32_t reserved		: 11;
		__O uint32_t _VECTKEY		: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tLGD_LDO_FC_t;

typedef union
{
	struct
	{
		__IO uint32_t SSCG_PDB		: 1;
		__IO uint32_t SSCG_EN		: 1;
		__IO uint32_t SSCG_INIT		: 1;
		__I uint32_t reserved		: 13;
		__O uint32_t _VECTKEY		: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tLGD_SSC_UC_t;

typedef union
{
	struct
	{
		__IO uint32_t SSCG_MR		: 3;
		__IO uint32_t SSCG_MF		: 2;
		__IO uint32_t SSCG_FRAC_EN	: 1;
		__IO uint32_t SSCG_ICP		: 2;
		__IO uint32_t SSCG_RSEL		: 2;
		__IO uint32_t SSCG_KVC		: 1;
		__I uint32_t reserved		: 5;
		__O uint32_t _VECTKEY		: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tLGD_SSC_FC_t;

typedef union
{
	struct
	{
		__IO uint32_t SSCG_SEL_NRST	: 1;
		__IO uint32_t SSCG_DIG_RSTN	: 1;
		__IO uint32_t SSCG_DIG_TST	: 1;
		__I uint32_t SSCG_FLAG		: 1;
		__I uint32_t reserved		: 12;
		__O uint32_t _VECTKEY		: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tLGD_SSC_TC_t;

typedef union
{
	struct
	{
		__IO uint32_t ATOP_DUMMY 	: 8;
		__I uint32_t reserved 		: 8;
		__O uint32_t _VECTKEY		: 16; // Write : 0x05FA
	} tBit;
	__IO uint32_t ulBulk;
} tLGD_ANA_DM_t;
//    __IO uint32_t LGD_ANA_DM;                     //0x001A

typedef union
{
	struct
	{
		__IO uint32_t VBUSVALID			: 1;
		__IO uint32_t WAKEUP			: 1;
		__IO uint32_t L1_WAKEUP			: 1;
		__IO uint32_t SEL_VBUSVALID		: 1;
		__IO uint32_t SEL_WAKEUP		: 1;
		__IO uint32_t SEL_L1_WAKEUP		: 1;
		__I uint32_t reserved			: 26;
	} tBit;
	__IO uint32_t ulBulk;
} tUSB_CTL_UC_t;

typedef union
{
	struct
	{
		__IO uint32_t EXTCTRL_SUSPENDM	: 1;
		__IO uint32_t OSCOUTEN			: 1;
		__IO uint32_t XTLSEL			: 1;
		__IO uint32_t PLLALIV			: 1;
		__IO uint32_t PONRST			: 1;
		__IO uint32_t OUTCLKSEL			: 1;
		__IO uint32_t TA				: 1;
		__IO uint32_t TB				: 1;
		__IO uint32_t TC				: 1;
		__I uint32_t reserved			: 23;
	} tBit;
	__IO uint32_t ulBulk;
} tUSB_PHY_FC_t;

typedef union
{
	struct
	{
		__IO uint32_t USB_SUSM_INTR_EN		: 1;
		__IO uint32_t USB_SUSM_INTR_POSNEG	: 1;
		__IO uint32_t USB_SUSM_INTR_BOTH	: 1;
		__IO uint32_t USB_LPM_INTR_EN		: 1;
		__IO uint32_t USB_LPM_INTR_POSNEG	: 1;
		__IO uint32_t USB_LPM_INTR_BOTH		: 1;
		__IO uint32_t USB_IP_INTR_EN		: 1;
		__IO uint32_t USB_IP_INTR_INV		: 1;
		__I uint32_t reserved				: 24;
	} tBit;
	__IO uint32_t ulBulk;
} tUSB_ITR_IC_t;

typedef union
{
	struct
	{
		__O uint32_t USB_SUSM_INTC		: 1;
		__I uint32_t USB_SUSM_MIS		: 1;
		__I uint32_t USB_SUSM_RIS		: 1;
		__I uint32_t USB_SUSM_RAW		: 1;
		__O uint32_t USB_LPM_EN_INTC	: 1;
		__I uint32_t USB_LPM_EN_MIS		: 1;
		__I uint32_t USB_LPM_EN_RIS		: 1;
		__I uint32_t USB_LPM_EN_RAW		: 1;
		__I uint32_t reserved			: 24;
	} tBit;
	__IO uint32_t ulBulk;
} tUSB_ITR_IS_t;

//typedef union
//{
//	struct
//	{
//		__IO uint32_t BEN_TST		: 1;
//		__IO uint32_t REN_TST		: 1;
//		__IO uint32_t CEN_TST		: 1;
//		__IO uint32_t IREF_TST		: 1;
//		__IO uint32_t IREF_TRIM		: 4;
//		__IO uint32_t BOFF_TRIM		: 3;
//		__I uint32_t reserved		: 5;
//		__O uint32_t _VECTKEY		: 16; // Write : 0x05FA
//	} tBit;
//	__IO uint32_t ulBulk;
//} tMAIN_BIAS_t;
//
//typedef union
//{
//	struct
//	{
//		__IO uint32_t DCTC_AMUX_EN_LV	: 1;
//		__IO uint32_t DCTC_LV_MUX0		: 4;
//		__IO uint32_t DCTC_LV_MUX1		: 4;
//		__I uint32_t reserved			: 7;
//		__O uint32_t _VECTKEY			: 16; // Write : 0x05FA
//	} tBit;
//	__IO uint32_t ulBulk;
//} tTEST_MUX_t;

typedef struct
{
	tDEVICE_ID_t DEVICE_ID;
    __IO uint32_t SYSTEM_INFO;                    //0x0001
    tCM3_STATUS_t CM3_STATUS;
    tRST_STATUS_t RST_STATUS;
    tINTR_I2C_CFG_t INTR_I2C_CFG;
    tINTR_NMI_CFG_t INTR_NMI_CFG;
    tSTCALIB_t STCALIB;
    tCK_ENA_RUN0_t CK_ENA_RUN0;
    tCK_ENA_RUN1_t CK_ENA_RUN1;
    tCK_ENA_SLP0_t CK_ENA_SLP0;
    tCK_ENA_SLP1_t CK_ENA_SLP1;
    tRST_CTRL_t RST_CTRL;
    tPMU_CONTROL_t PMU_CONTROL;
    tCLK_SRC_SEL_t CLK_SRC_SEL;
    tCLK_DIV_t CLK_DIV;
    tECLK_CFG_t ECLK_CFG;
    tUMC_PLL_UC_t UMC_PLL_UC;
    tUMC_PLL_FC_t UMC_PLL_FC;
    tUMC_PLL_IC_t UMC_PLL_IC;
    tUMC_PLL_IS_t UMC_PLL_IS;
    tLGD_OSC_UC_t LGD_OSC_UC;
    tLGD_OSC_FC_t LGD_OSC_FC;
    tLGD_LDO_FC_t LGD_LDO_FC;
    tLGD_SSC_UC_t LGD_SSC_UC;
    tLGD_SSC_FC_t LGD_SSC_FC;
    tLGD_SSC_TC_t LGD_SSC_TC;
    tLGD_ANA_DM_t LGD_ANA_DM;
//    __IO uint32_t LGD_ANA_DM;                     //0x001A
    tUSB_CTL_UC_t USB_CTL_UC;
    tUSB_PHY_FC_t USB_PHY_FC;
    tUSB_ITR_IC_t USB_ITR_IC;
    tUSB_ITR_IS_t USB_ITR_IS;
//    tMAIN_BIAS_t MAIN_BIAS;
//    tTEST_MUX_t TEST_MUX;
	
} tSCRB_CtrlReg_t;


#endif /* __SCRB_H_ */
