/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _scrb.h
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

#ifndef __SCRB_H_
#define __SCRB_H_


typedef union
{
	struct {
		unsigned	wdtclk_en:					1;
		unsigned	timclk0_en:					1;
		unsigned	timclk1_en:					1;
		unsigned	timclk2_en:					1;
		unsigned	timclk3_en:					1;
		unsigned	i2cclk_en:					1;
		unsigned	dspaclk_en:					1;
		unsigned	tdspclk_en:					1;
		unsigned	usbcclk_en:					1;
		unsigned	usbhclk_en:					1;
		unsigned	pwmclk_en:					1;
		unsigned	mspiclk_en:					1;
		unsigned	sscgclk_en:					1;
		unsigned	mpiclk_en:					1;
		unsigned	tlvclk_en:					1;
		unsigned	i2cm0clk_en:				1;
		unsigned	i2cm0clk_slp_en:			1;
		unsigned	i2cm1clk_en:				1;
		unsigned	i2cm1clk_slp_en:			1;
		unsigned	osc_deglitch_en:			1;
		unsigned	reserved:					12;
	} tBit;
	__IO uint32_t ulBulk;
} tSYS_CLK_CTL;

typedef union
{
	struct {
		unsigned	sys_rst:					1;
		unsigned	cm3_rst:					1;
		unsigned	serial_rst:					1;
		unsigned	dspa_rst:					1;
		unsigned	tdsp_rst:					1;
		unsigned	usb_rst:					1;
		unsigned	pwm_rst:					1;
		unsigned	mspi_rst:					1;
		unsigned	sscg_rst:					1;
		unsigned	mpi_rst:					1;
		unsigned	tlv_rst:					1;
		unsigned	i2cm_rst:					1;
		unsigned	reserved:					20;
	} tBit;
	__IO uint32_t ulBulk;
} tSYS_RST_CTL;

typedef union
{
	struct {
		unsigned	stack_over_int_clr:			1;
		unsigned	abnormal_addr_int_clr:		1;
		unsigned	reserved:					30;
	} tBit;
	__O uint32_t ulBulk;
} tSYS_INT_CTRL;

typedef union
{
	struct {
		unsigned	int_watchdog:				1;
		unsigned	int_timer0:					1;
		unsigned	int_timer1:					1;
		unsigned	int_timer2:					1;
		unsigned	int_timer3:					1;
		unsigned	int_i2c_slave:				1;
		unsigned	int_i2c_report_done:		1;
		unsigned	int_serial_error:			1;
		unsigned	int_i2c_mst:				1;
		unsigned	int_spi_slave:				1;
		unsigned	int_spi_report_done:		1;
		unsigned	int_stack_over:				1;
		unsigned	int_abnormal_addr:			1;
		unsigned	int_gdma:					1;
		unsigned	crc_error_int:				1;
		unsigned	int_user:					1;
		unsigned	int_gpioa:					1;
		unsigned	int_gpiom:					1;
		unsigned	int_vsyncin:				1;
		unsigned	int_tsyncin:				1;
		unsigned	int_tsyncout:				1;
		unsigned	r_pwm_frame_intr:			1;
		unsigned	r_pwm_ab_intr:				1;
		unsigned	int_tsync_ab:				1;
		unsigned	int_dspa:					1;
		unsigned	int_tdsp:					1;
		unsigned	int_usb:					1;
		unsigned	int_usb_lpmen:				1;
		unsigned	int_usb_susm :				1;
		unsigned	int_mspi:					1;
		unsigned	int_tlvds:					1;
		unsigned	int_mpi:					1;
	} tBit;
	__I uint32_t ulBulk;
} tSYS_INT_ST;

typedef union
{
	struct {
		unsigned	sysrst_req:					1;
		unsigned	serial_sw_resetn_req:		1;
		unsigned	reserved:					30;
	} tBit;
	__I uint32_t ulBulk;
} tSYS_RSTINFO;

typedef union
{
	struct {
		unsigned	watchdog:					1;
		unsigned	abnormal_spck:				1;
		unsigned	reserved:					30;
	} tBit;
	__I uint32_t ulBulk;
} tSYS_ERROR_ST;

typedef union
{
	struct {
		unsigned	R_OSC12M_PD_N:				1;
		unsigned	R_MAIN_BIAS_PD_N:			1;
		unsigned	R_BOD_PD_N:					1;
		unsigned	reserved:					29;
	} tBit;
	__IO uint32_t ulBulk;
} tSYS_OSC_PD_CTL;

typedef union
{
	struct {
		unsigned	R_OSC12M_VTRIM:				6;
		unsigned	R_OSC12M_ITRIM:				3;
		unsigned	R_LDO_TRIM:					5;
		unsigned	R_LDO_LL_CTL:				1;
		unsigned	R_LDO_RZ_SEL:				1;
		unsigned	R_MAIN_VBGR_CTL:			3;
		unsigned	R_MAIN_IREF_TRIM:			5;
		unsigned	R_MAIN_VREF_TRIM:			4;
		unsigned	reserved:					4;
	} tBit;
	__IO uint32_t ulBulk;
} tSYS_ANA_TRIM;

typedef union
{
	struct {
		unsigned	R_MAIN_LDOIN_CTL:			2;
		unsigned	R_MAIN_TLVDS_CTL:			2;
		unsigned	R_BOD_DLY_CTL:				2;
		unsigned	R_BOD_VHLS:					2;
		unsigned	R_BOD_VLHS:					2;
		unsigned	reserved:					22;
	} tBit;
	__IO uint32_t ulBulk;
} tSYS_ANA_CTRL;

typedef union
{
	struct {
		unsigned	R_MAIN_VBGR_OBV:			1;
		unsigned	R_MAIN_VREF1P2V_OBV:		1;
		unsigned	R_MAIN_IREF_OBV:			1;
		unsigned	R_OSC12M_LDO_OBV:			1;
		unsigned	R_FLASH_OBV:				1;
		unsigned	reserved:					27;
	} tBit;
	__IO uint32_t ulBulk;
} tSYS_OSC_TEST;

typedef union
{
	struct {
		unsigned	R_DSSC_EN:					1;
		unsigned	R_DSSC_PDB:					1;
		unsigned	reserved:					30;
	} tBit;
	__IO uint32_t ulBulk;
} tSSCG_PD_CTL;

typedef union
{
	struct {
		unsigned	R_DSSC_FRAC_EN:				1;
		unsigned	R_DSSC_ICP:					2;
		unsigned	R_DSSC_RSEL:				2;
		unsigned	R_DSSC_KVC:					1;
		unsigned	R_DSSC_KVC2:				1;
		unsigned	R_DSSC_DIG_RSTN:			1;
		unsigned	R_DSSC_SEL_NRST:			1;
		unsigned	R_DSSC_INIT:				1;
		unsigned	R_DSSC_MF:					2;
		unsigned	R_DSSC_MR:					3;
		unsigned	R_DSSC_DIG_TST:				1;
		unsigned	modu_cnt_en:				1;
		unsigned	reserved:					15;
	} tBit;
	__IO uint32_t ulBulk;
} tSSCG_OP_CTRL;

typedef union
{
	struct {
		unsigned	sscg_ldo_test:				1;
		unsigned	sscg_vcont_test:			1;
		unsigned	reserved:					30;
	} tBit;
	__IO uint32_t ulBulk;
} tSSCG_TEST_CTL;		//	ToDo: Delete

typedef union
{
	struct {
		unsigned	TLVDS_TPWM0_INV:			1;
		unsigned	TLVDS_TPWM1_INV:			1;
		unsigned	TLVDS_TECLK0_INV:			1;
		unsigned	TLVDS_TECLK1_INV:			1;
		unsigned	R_TLVDS_ITX_CTL:			3;
		unsigned	R_TLVDS_IRX_CTL:			3;
		unsigned	R_reserved:					4;
		unsigned	reserved:					18;
	} tBit;
	__IO uint32_t ulBulk;
} tSYS_TLVDS_CTRL;

typedef union
{
	struct {
		unsigned	R_TLVDS_BIAS_PD_N:			1;
		unsigned	A_TLVDS_PDB_TPWM0:			1;
		unsigned	A_TLVDS_PDB_TECLK0:			1;
		unsigned	A_TLVDS_PDB_TPWM1:			1;
		unsigned	A_TLVDS_PDB_TECLK1:			1;
		unsigned	A_TLVDS_DRV_TPWM0:			1;
		unsigned	A_TLVDS_DRV_TECLK0:			1;
		unsigned	A_TLVDS_DRV_TPWM1:			1;
		unsigned	A_TLVDS_DRV_TECLK1:			1;
		unsigned	reserved:					23;
	} tBit;
	__IO uint32_t ulBulk;
} tSYS_TLVDS_PD_N;

typedef union
{
	struct {
		unsigned	mainclksel:					1;
		unsigned	hsclksel:					1;
		unsigned	pllclkdiv:					4;
		unsigned	usbclkdiv:					4;
		unsigned	mclkdiv:					6;
		unsigned	mclksel:					1;
		unsigned	reserved:					15;
	} tBit;
	__IO uint32_t ulBulk;
} tSYS_MAINCLK_CFG;

typedef union
{
	struct {
		unsigned	pwmclksel:					1;
		unsigned	pwmclkdiv:					3;
		unsigned	pllclkdiv:					4;
		unsigned	usbclkdiv:					4;
		unsigned	pwmclkdiv_en:				1;
		unsigned	pwmclkdiv_num:				3;
		unsigned	pwmclk_phase_en:			1;
		unsigned	reserved:					15;
	} tBit;
	__IO uint32_t ulBulk;
} tSYS_PWMCLK_CFG;

typedef union
{
	struct {
		unsigned	sscgin_sel:					1;
		unsigned	sscgin_inv:					1;
		unsigned	sscgplldiv:					3;
		unsigned	sscgusbdiv:					4;
		unsigned	sscgclk_sel:				1;
		unsigned	reserved:					22;
	} tBit;
	__IO uint32_t ulBulk;
} tSSCG_IN_CFG;

typedef union
{
	struct {
		unsigned	tlvclkpre_sel:				1;
		unsigned	tlvplldiv:					3;
		unsigned	tlvusbdiv:					3;
		unsigned	reserved:					12;
	} tBit;
	__IO uint32_t ulBulk;
} tTLVDSCLK_CFG;

typedef union
{
	struct {
		unsigned	dspa_lp_en:					1;
		unsigned	tdsp_lp_en:					1;
		unsigned	mspi_lp_en:					1;
		unsigned	reserved:					29;
	} tBit;
	__IO uint32_t ulBulk;
} tCLK_LP_MODE;

typedef union
{
	struct {
		unsigned	serial_slv_div:				4;
		unsigned	i2cm0_div:					4;
		unsigned	i2cm1_div:					4;
		unsigned	reserved:					20;
	} tBit;
	__IO uint32_t ulBulk;
} tSERIAL_CLK_DIV;

typedef union
{
	struct {
		unsigned	refdiv:						3;
		unsigned	fbdiv:						6;
		unsigned	outdiv:						2;
		unsigned	icpsela:					1;
		unsigned	icpselb:					1;
		unsigned	pll_stby_i:					1;
		unsigned	rsel:						3;
		unsigned	vcosetupsel:				1;
		unsigned	pllin_sel:					1;
		unsigned	reserved:					13;
	} tBit;
	__IO uint32_t ulBulk;
} tPLL_CFG;

typedef union
{
	struct {
		unsigned	a_modu_clk:					1;
		unsigned	reserved:					31;
	} tBit;
	__I uint32_t ulBulk;
} tSSCG_STATUS;

typedef union
{
	struct {
		unsigned	modu_low_cnt:				14;
		unsigned	reserved0:					2;
		unsigned	modu_high_cnt:				14;
		unsigned	reserved1:					2;
	} tBit;
	__I uint32_t ulBulk;
} tSSCG_MODU_CNT;

typedef union
{
	struct {
		unsigned	int_en_pwm_ab:				1;
		unsigned	int_en_pwm_frame:			1;
		unsigned	int_en_tsync_ab:			1;
		unsigned	int_en_tsyncin:				2;
		unsigned	int_en_vsyncin:				2;
		unsigned	int_en_tsyncout:			2;
		unsigned	int_tsyncin_src_sel:		1;
		unsigned	int_en_lhb:					1;
		unsigned	reserved:					21;
	} tBit;
	__IO uint32_t ulBulk;
} tPWM_INT_CTRL;

typedef union
{
	struct {
		unsigned	pwm_ab_int_clr:				1;
		unsigned	pwm_frame_int_clr:			1;
		unsigned	tsync_ab_int_clr:			1;
		unsigned	vsyncin_int_clr:			1;
		unsigned	tsyncin_int_clr:			1;
		unsigned	tsyncout_int_clr:			1;
		unsigned	lhb_int_clr:				1;
		unsigned	reserved:					25;
	} tBit;
	__O uint32_t ulBulk;
} tPWM_INT_CLR;

typedef union
{
	struct {
		unsigned	CACHE_EN:					1;
		unsigned	CACHE_FLUSH:				1;
		unsigned	CACHE_BST:					2;
		unsigned	CACHE_DEN:					1;
		unsigned	dly_num:					4;
		unsigned	reserved:					23;
	} tBit;
	__IO uint32_t ulBulk;
} tCACHE_CTRL;

typedef union
{
	struct {
		unsigned	int_lhb:					1;
		unsigned	int_fll_done:				1;
		unsigned	reserved:					30;
	} tBit;
	__I uint32_t ulBulk;
} tSYS_INT_ST2;

typedef union
{
	struct {
		unsigned	usbphyclk_sel:				1;
		unsigned	reserved:					31;
	} tBit;
	__IO uint32_t ulBulk;
} tUSB_CFG;

typedef union
{
	struct {
		unsigned	vbusvalid:					1;
		unsigned	wakeup:						1;
		unsigned	l1_wakeup:					1;
		unsigned	sel_wakeup:					1;
		unsigned	sel_l1_wakeup:				1;
		unsigned	reserved:					27;
	} tBit;
	__IO uint32_t ulBulk;
} tUSB_CTRL_UC;

typedef union
{
	struct {
		unsigned	extctrl_suspendm:			1;
		unsigned	oscouten:					1;
		unsigned	xtlsel:						1;
		unsigned	pllaliv:					1;
		unsigned	ponrst:						1;
		unsigned	outclksel:					1;
		unsigned	ta:							1;
		unsigned	tb:							1;
		unsigned	tc:							1;
		unsigned	hstx_sw:					2;
		unsigned	reserved:					21;
	} tBit;
	__IO uint32_t ulBulk;
} tUSB_PHY_FC;

typedef union
{
	struct {
		unsigned	susm_intr_en:				1;
		unsigned	susm_intr_pos:				1;
		unsigned	susm_intr_neg:				1;
		unsigned	lpm_intr_en:				1;
		unsigned	lpm_intr_pos:				1;
		unsigned	lpm_intr_neg:				1;
		unsigned	ip_intr_en:					1;
		unsigned	ip_intr_inv:				1;
		unsigned	reserved:					24;
	} tBit;
	__IO uint32_t ulBulk;
} tUSB_INTR_CTL;

typedef union
{
	struct {
		unsigned	susm_intr_clr:				1;
		unsigned	lpm_intr_clr:				1;
		unsigned	ip_intr_clr:				1;
		unsigned	reserved:					29;
	} tBit;
	__IO uint32_t ulBulk;
} tUSB_INTR_CLR;

typedef union
{
	struct {
		unsigned	boot_crc_check_ok:			1;
		unsigned	boot_ecc_flag:				1;
		unsigned	boot_ecc_unknown_err:		1;
		unsigned	boot_crc_check_busy:		1;
		unsigned	boot_ecc_cnt:				14;
		unsigned	reserved:					14;
	} tBit;
	__I uint32_t ulBulk;
} tBOOT_ST;

typedef union
{
	struct {
		unsigned	fll_en:						1;
		unsigned	clk_en_fll:					1;
		unsigned	resetn_fll:					1;
		unsigned	int_en_fll:					1;
		unsigned	reserved:					28;
	} tBit;
	__IO uint32_t ulBulk;
} tFLL_CTRL;

typedef union
{
	struct {
		unsigned	fll_result:					14;
		unsigned	fll_done:					1;
		unsigned	reserved:					17;
	} tBit;
	__I uint32_t ulBulk;
} tFLL_ST;

typedef struct{																		// Index
	__I  uint32_t							SYS_CHIP_ID;							// 0x0000
	__I  uint32_t                       	SYS_CHIP_VERSION;						// 0x0001
	__IO tSYS_CLK_CTL						SYS_CLK_CTL;                            // 0x0002
	__IO tSYS_RST_CTL                      SYS_RST_CTL;                            // 0x0003
	__IO uint32_t                       	SYS_BOOT_CTL;                           // 0x0004
	__O  tSYS_INT_CTRL                     SYS_INT_CTRL;                           // 0x0005
	__I  tSYS_INT_ST                       SYS_INT_ST;                             // 0x0006
	__IO uint32_t                       	SYS_USERINT_CTRL;                       // 0x0007
	__I  tSYS_RSTINFO                      SYS_RSTINFO;                            // 0x0008
	__I  tSYS_ERROR_ST                     SYS_ERROR_ST;                           // 0x0009
	__IO tSYS_OSC_PD_CTL                   SYS_OSC_PD_CTL;                         // 0x000A
	__IO tSYS_ANA_TRIM                     SYS_ANA_TRIM;                           // 0x000B
	__IO tSYS_ANA_CTRL                     SYS_ANA_CTRL;                           // 0x000C
	__IO tSYS_OSC_TEST                     SYS_OSC_TEST;                           // 0x000D
	__IO uint32_t                      		SYS_STACK_OVER_ADDR;                    // 0x000E
	__IO uint32_t                       	SYS_DEBUG_RW_EN;                        // 0x000F
	__IO uint32_t                       	SYS_ABNORMAL_ADDR;                      // 0x0010
	__IO uint32_t                   		SYS_ABNORMAL_ADDR_M;                    // 0x0011
	__IO uint32_t                       	SYS_DELAY_TICK;                         // 0x0012
	__IO tSSCG_PD_CTL                      SSCG_PD_CTL;                            // 0x0013
	__IO tSSCG_OP_CTRL                     SSCG_OP_CTRL;                           // 0x0014
	__IO tSSCG_TEST_CTL                    SSCG_TEST_CTL;                          // 0x0015
	__IO tSYS_TLVDS_CTRL                   SYS_TLVDS_CTRL;                         // 0x0016
	__IO tSYS_TLVDS_PD_N                   SYS_TLVDS_PD_N;                         // 0x0017
	__IO tSYS_MAINCLK_CFG                  SYS_MAINCLK_CFG;                        // 0x0018
	__IO tSYS_PWMCLK_CFG                   SYS_PWMCLK_CFG;                         // 0x0019
	__IO tSSCG_IN_CFG                      SSCG_IN_CFG;                            // 0x001A
	__IO tTLVDSCLK_CFG                     TLVDSCLK_CFG;                           // 0x001B
	__IO tCLK_LP_MODE                      CLK_LP_MODE;                            // 0x001C
	__IO tSERIAL_CLK_DIV                   SERIAL_CLK_DIV;                         // 0x001D
	__IO tPLL_CFG                          PLL_CFG;                                // 0x001E
	__I  uint32_t                         	PLL_LOCK;                               // 0x001F
	__I  tSSCG_STATUS                      SSCG_STATUS;                            // 0x0020
	__I  tSSCG_MODU_CNT                    SSCG_MODU_CNT;                          // 0x0021
	__IO tPWM_INT_CTRL                     PWM_INT_CTRL;                           // 0x0022
	__O  tPWM_INT_CLR                      PWM_INT_CLR;                            // 0x0023
	__IO tCACHE_CTRL                       CACHE_CTRL;                             // 0x0024
	__I  uint32_t                         	CACHE_ST;                               // 0x0025
	__I  tSYS_INT_ST2                      SYS_INT_ST2;                            // 0x0026
	__IO uint32_t                       	SYSTEM_RESERVED10;                      // 0x0027
	__IO tUSB_CFG                          USB_CFG;                                // 0x0028
	__IO tUSB_CTRL_UC                      USB_CTRL_UC;                            // 0x0029
	__IO tUSB_PHY_FC                       USB_PHY_FC;                             // 0x002A
	__IO tUSB_INTR_CTL                     USB_INTR_CTL;                           // 0x002B
	__IO tUSB_INTR_CLR                     USB_INTR_CLR;                           // 0x002C
	__IO uint32_t                       	SYS_BUS_REMAP;                          // 0x002D
	__I  uint32_t                       	BUS_REMAP_ST;                           // 0x002E
	__O  uint32_t                       	CM3_REMAP_RESET;                        // 0x002F
	__I  tBOOT_ST                          BOOT_ST;                                // 0x0030
	__IO uint32_t                       	BOOT_CRC_RESULT;                        // 0x0031
	__IO tFLL_CTRL                         FLL_CTRL;                               // 0x0032
	__I  tFLL_ST                           FLL_ST;                                 // 0x0033
	__O  uint32_t                       	FLL_INT_CLR;                            // 0x0034
	__IO uint32_t                       	SYSTEM_RESERVED16;                      // 0x0035
	__IO uint32_t                        	SYSTEM_RESERVED17;                      // 0x0036
	__IO uint32_t                        	SYSTEM_RESERVED18;                      // 0x0037
	__IO uint32_t                        	SYSTEM_RESERVED19;                      // 0x0038
	__IO uint32_t                        	SYSTEM_RESERVED20;                      // 0x0039
	__IO uint32_t                        	SYSTEM_RESERVED21;                      // 0x003A
	__IO uint32_t                        	SYSTEM_RESERVED22;                      // 0x003B
	__IO uint32_t                        	SYSTEM_RESERVED23;                      // 0x003C
	__IO uint32_t                        	SYSTEM_RESERVED24;                      // 0x003D
	__IO uint32_t                           SYS_DUMMY0;                             // 0x003E
	__IO uint32_t                           SYS_DUMMY1;                             // 0x003F
} tSCRB_CtrlReg_t;


typedef struct
{

  union {
    __I  uint32_t  CALIB_OSC  ;

    struct {
      __I  uint32_t  R_FINE   :  4;
      __I  uint32_t  R_COARSE :  4;
    } CALIB_OSC_b;
  } ;


  union {
    __I  uint32_t  CALIB_LDO ;

    struct {
      __I  uint32_t  CAL_SEL :  4;
    } CALIB_LDO_b;
  } ;


} INFO_TypeDef;


#endif /* __SCRB_H_ */
