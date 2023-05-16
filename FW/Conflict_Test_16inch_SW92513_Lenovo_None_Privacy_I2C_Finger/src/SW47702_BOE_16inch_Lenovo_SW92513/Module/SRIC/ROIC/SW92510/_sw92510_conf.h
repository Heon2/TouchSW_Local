/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _SW92510_conf.h
 * created on : 29. 12. 2020
 * Author : mhjang
 *
 * All rights RESERVED.
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

#ifndef __SW92510_CONF_H_
#define __SW92510_CONF_H_

#if (USED_ROIC_DEF == ROIC_SW92510)

#define SW92510_MODE_FINGER         (0)
#define SW92510_MODE_BEACON         (1)
#define SW92510_MODE_PEN_POS        (2)
#define SW92510_MODE_PEN_TILT       (2)
#define SW92510_MODE_PEN_DAT        (3)
#define SW92510_MODE_NOISE_SCAN		(0)//(4)
#define SW92510_MODE_DUMMY          (6)

typedef union
{
    struct
    {
        __I uint32_t r0_rev_id                   : 4  ;
        __I uint32_t r1_rev_id                   : 4  ;
        __I uint32_t chip_id                     : 24 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPRODUCT_ID_t;

typedef union
{
    struct
    {
        __IO uint32_t chksum_opt                 : 1  ;
        __IO uint32_t spis_irq_en                : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSPIS_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t spi_chksum_clr             : 1  ;
        __IO uint32_t tsync_fault_clr            : 1  ;
        __IO uint32_t pwm_fault_clr              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSPIS_ERROR_CLR_t;

typedef union
{
    struct
    {
        __I uint32_t spi_chksum_err_cnt          : 8  ;
        __I uint32_t tsync_fault_err             : 1  ;
        __I uint32_t pwm_fault_err               : 1  ;
        __I uint32_t sense_active                : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSPIS_ERROR_ST_t;

typedef union
{
    struct
    {
        __IO uint32_t miso_ds                    : 1  ;
        __IO uint32_t miso_dout                  : 1  ;
        __IO uint32_t miso_func                  : 4  ;
        __IO uint32_t mosi_ds                    : 1  ;
        __IO uint32_t mosi_dout                  : 1  ;
        __IO uint32_t mosi_func                  : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSPIS_PAD_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t tg_reset                   : 1  ;
        __IO uint32_t sw_reset                   : 1  ;
        __IO uint32_t tg_clk_all_on              : 1  ;
        __IO uint32_t cfclk_on                   : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSYS_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t tc_start                   : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tTC_START_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_ch_num                 : 6  ;
        __IO uint32_t pp_ch_num                  : 6  ;
        __IO uint32_t pdrv_ch_num                : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tCH_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t tot_mux_num                : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMUX_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t mux_1_dly                  : 6  ;
        __IO uint32_t mux_2_dly                  : 6  ;
        __IO uint32_t mux_3_dly                  : 6  ;
        __IO uint32_t mux_4_dly                  : 6  ;
        __IO uint32_t mux_5_dly                  : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMUX_DLY_0_t;

typedef union
{
    struct
    {
        __IO uint32_t mux_6_dly                  : 6  ;
        __IO uint32_t mux_7_dly                  : 6  ;
        __IO uint32_t mux_8_dly                  : 6  ;
        __IO uint32_t mux_9_dly                  : 6  ;
        __IO uint32_t mux_10_dly                 : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMUX_DLY_1_t;

typedef union
{
    struct
    {
        __IO uint32_t pen_mux_dly                : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMUX_DLY_2_t;

typedef union
{
    struct
    {
        __IO uint32_t vsync_pol                  : 1  ;
        __IO uint32_t vsync_tg_en                : 1  ;
        __IO uint32_t vsync_tg_act               : 1  ;
        __IO uint32_t tsync_in_pol               : 1  ;
        __IO uint32_t tsync_out_pol              : 1  ;
        __IO uint32_t tsync_out_bypass           : 1  ;
        __IO uint32_t tsync_out_stuck            : 1  ;
        __IO uint32_t tsync_out_level            : 1  ;
        __IO uint32_t pwm_pol                    : 1  ;
        __IO uint32_t sd_off_en                  : 1  ;
        __IO uint32_t sd_float_en                : 1  ;
        __IO uint32_t sd_gnd_en                  : 1  ;
        __IO uint32_t sd_off_ctl                 : 2  ;
        __IO uint32_t sd_float_ctl               : 2  ;
        __IO uint32_t sd_gnd_ctl                 : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSDIC_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t pwm_fig_act_num            : 7  ;
        __IO uint32_t pwm_fig_mgap_num           : 7  ;
        __IO uint32_t pwm_fig_dum_num            : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPWM_FIG_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t pwm_pos_pdrv_num           : 4  ;
        __IO uint32_t pwm_pos_act_num            : 7  ;
        __IO uint32_t pwm_pos_mgap_num           : 7  ;
        __IO uint32_t pwm_pos_dum_num            : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPWM_POS_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t pwm_dat_pdrv_num           : 4  ;
        __IO uint32_t pwm_dat_pre_act_num        : 7  ;
        __IO uint32_t pwm_dat_act_num            : 7  ;
        __IO uint32_t pwm_dat_mgap_num           : 7  ;
        __IO uint32_t pwm_dat_dum_num            : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPWM_DAT_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t pwm_nd_pdrv_num            : 4  ;
        __IO uint32_t pwm_nd_act_num             : 7  ;
        __IO uint32_t pwm_nd_mgap_num            : 7  ;
        __IO uint32_t pwm_nd_dum_num             : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPWM_ND_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_pwm_prd                : 8  ;
        __IO uint32_t pen_pwm_prd                : 8  ;
        __IO uint32_t nd_pwm_prd                 : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPWM_PRD_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_smop_prd               : 7  ;
        __IO uint32_t pen_smop_prd               : 7  ;
        __IO uint32_t nd_smop_prd                : 7  ;
        __IO uint32_t cr_repeat_num              : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSMPL_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_rstp_rise_num          : 8  ;
        __IO uint32_t pen_rstp_rise_num          : 8  ;
        __IO uint32_t nd_rstp_rise_num           : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTP_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_rstp_fall_num1         : 8  ;
        __IO uint32_t pen_rstp_fall_num1         : 8  ;
        __IO uint32_t nd_rstp_fall_num1          : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTP_FALL_NUM1_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_rstp_fall_num2         : 8  ;
        __IO uint32_t pen_rstp_fall_num2         : 8  ;
        __IO uint32_t nd_rstp_fall_num2          : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTP_FALL_NUM2_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phtcr_rise_num         : 8  ;
        __IO uint32_t pen_phtcr_rise_num         : 8  ;
        __IO uint32_t nd_phtcr_rise_num          : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTCR_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phtcr_fall_num         : 8  ;
        __IO uint32_t pen_phtcr_fall_num         : 8  ;
        __IO uint32_t nd_phtcr_fall_num          : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTCR_FALL_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_vcr_num                : 8  ;
        __IO uint32_t pen_vcr_num                : 8  ;
        __IO uint32_t nd_vcr_num                 : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tVCR_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_rsti_rise_num          : 8  ;
        __IO uint32_t pen_rsti_rise_num          : 8  ;
        __IO uint32_t nd_rsti_rise_num           : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTI_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_rsti_fall_num1         : 8  ;
        __IO uint32_t pen_rsti_fall_num1         : 8  ;
        __IO uint32_t nd_rsti_fall_num1          : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTI_FALL_NUM1_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_rsti_fall_num2         : 8  ;
        __IO uint32_t pen_rsti_fall_num2         : 8  ;
        __IO uint32_t nd_rsti_fall_num2          : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTI_FALL_NUM2_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phth0_rise_num         : 8  ;
        __IO uint32_t pen_phth0_rise_num         : 8  ;
        __IO uint32_t nd_phth0_rise_num          : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTH0_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phth0_fall_num         : 8  ;
        __IO uint32_t pen_phth0_fall_num         : 8  ;
        __IO uint32_t nd_phth0_fall_num          : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTH0_FALL_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phth1_rise_num         : 8  ;
        __IO uint32_t pen_phth1_rise_num         : 8  ;
        __IO uint32_t nd_phth1_rise_num          : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTH1_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phth1_fall_num         : 8  ;
        __IO uint32_t pen_phth1_fall_num         : 8  ;
        __IO uint32_t nd_phth1_fall_num          : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTH1_FALL_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t pht_prd                    : 8  ;
        __IO uint32_t pht_opt_inv                : 1  ;
        __IO uint32_t pht_end_time               : 8  ;
        __IO uint32_t pht_act_en                 : 1  ;
        __IO uint32_t pht_act_pwm_num            : 3  ;
        __IO uint32_t pht_act_pwr_num            : 3  ;
        __IO uint32_t fig_pre_pht_sel            : 1  ;
        __IO uint32_t pen_pos_pre_pht_sel        : 1  ;
        __IO uint32_t pen_dat_pre_pht_sel        : 1  ;
        __IO uint32_t nd_pre_pht_sel             : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHT_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_pht_rise_num           : 8  ;
        __IO uint32_t pen_pht_rise_num           : 8  ;
        __IO uint32_t nd_pht_rise_num            : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHT_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_pht_fall_num           : 8  ;
        __IO uint32_t pen_pht_fall_num           : 8  ;
        __IO uint32_t nd_pht_fall_num            : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHT_FALL_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t adc_clk_opt                : 2  ;
        __IO uint32_t adc_clk_pol                : 1  ;
        __IO uint32_t fig_adc_clk_prd            : 3  ;
        __IO uint32_t pen_adc_clk_prd            : 3  ;
        __IO uint32_t pdrv_adc_clk_prd           : 3  ;
        __IO uint32_t fig_conv_smpl_num          : 5  ;
        __IO uint32_t pen_conv_smpl_num          : 5  ;
        __IO uint32_t pdrv_conv_smpl_num         : 5  ;
        __IO uint32_t adc_clk_spt                : 1  ;
        __IO uint32_t phd_adc_done_skip          : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tADC_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t adc_stc_dly                : 6  ;
        __IO uint32_t adc_sgap_num               : 6  ;
        __IO uint32_t adc_stc_prd                : 3  ;
        __IO uint32_t adc_pgap_num               : 6  ;
        __IO uint32_t adc_in_pos                 : 4  ;
        __IO uint32_t adc_clk_num                : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tADC_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t pdrv_adc_stc_dly           : 6  ;
        __IO uint32_t pdrv_adc_sgap_num          : 6  ;
        __IO uint32_t pdrv_adc_stc_prd           : 3  ;
        __IO uint32_t pdrv_adc_pgap_num          : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tADC_CTL3_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_vcr_off_en             : 1  ;
        __IO uint32_t fig_phtcr_off_en           : 1  ;
        __IO uint32_t pen_vcr_off_en             : 1  ;
        __IO uint32_t pen_phtcr_off_en           : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tTG_STUCK_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_mux_00                 : 4  ;
        __IO uint32_t fig_mux_01                 : 4  ;
        __IO uint32_t fig_mux_02                 : 4  ;
        __IO uint32_t fig_mux_03                 : 4  ;
        __IO uint32_t fig_mux_04                 : 4  ;
        __IO uint32_t fig_mux_05                 : 4  ;
        __IO uint32_t fig_mux_06                 : 4  ;
        __IO uint32_t fig_mux_07                 : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tFIG_MUX_CFG_00_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_mux_08                 : 4  ;
        __IO uint32_t fig_mux_09                 : 4  ;
        __IO uint32_t fig_mux_10                 : 4  ;
        __IO uint32_t fig_mux_11                 : 4  ;
        __IO uint32_t fig_mux_12                 : 4  ;
        __IO uint32_t fig_mux_13                 : 4  ;
        __IO uint32_t fig_mux_14                 : 4  ;
        __IO uint32_t fig_mux_15                 : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tFIG_MUX_CFG_01_t;

typedef union
{
    struct
    {
        __IO uint32_t nxt_lhb_mode               : 3  ;
        __IO uint32_t tsync_num                  : 6  ;
        __IO uint32_t dum_tsync_num              : 4  ;
        __IO uint32_t beacon_en                  : 1  ;
        __IO uint32_t rdcom_en                   : 1  ;
        __IO uint32_t sgap_num                   : 8  ;
        __IO uint32_t r0pd                       : 1  ;
        __IO uint32_t r1pd                       : 1  ;
        __IO uint32_t sel_hover                  : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRCOM_LHB_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t lhb_mode01                 : 3  ;
        __IO uint32_t lhb_mode02                 : 3  ;
        __IO uint32_t lhb_mode03                 : 3  ;
        __IO uint32_t lhb_mode04                 : 3  ;
        __IO uint32_t lhb_mode05                 : 3  ;
        __IO uint32_t lhb_mode06                 : 3  ;
        __IO uint32_t lhb_mode07                 : 3  ;
        __IO uint32_t lhb_mode08                 : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tDEFA_LHB_MCFG00_t;

typedef union
{
    struct
    {
        __IO uint32_t lhb_mode09                 : 3  ;
        __IO uint32_t lhb_mode10                 : 3  ;
        __IO uint32_t lhb_mode11                 : 3  ;
        __IO uint32_t lhb_mode12                 : 3  ;
        __IO uint32_t lhb_mode13                 : 3  ;
        __IO uint32_t lhb_mode14                 : 3  ;
        __IO uint32_t lhb_mode15                 : 3  ;
        __IO uint32_t lhb_mode16                 : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tDEFA_LHB_MCFG01_t;

typedef union
{
    struct
    {
        __IO uint32_t lhb_mode17                 : 3  ;
        __IO uint32_t lhb_mode18                 : 3  ;
        __IO uint32_t lhb_mode19                 : 3  ;
        __IO uint32_t lhb_mode20                 : 3  ;
        __IO uint32_t lhb_mode21                 : 3  ;
        __IO uint32_t lhb_mode22                 : 3  ;
        __IO uint32_t lhb_mode23                 : 3  ;
        __IO uint32_t lhb_mode24                 : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tDEFA_LHB_MCFG02_t;

typedef union
{
    struct
    {
        __IO uint32_t lhb_mode25                 : 3  ;
        __IO uint32_t lhb_mode26                 : 3  ;
        __IO uint32_t lhb_mode27                 : 3  ;
        __IO uint32_t lhb_mode28                 : 3  ;
        __IO uint32_t lhb_mode29                 : 3  ;
        __IO uint32_t lhb_mode30                 : 3  ;
        __IO uint32_t lhb_mode31                 : 3  ;
        __IO uint32_t lhb_mode32                 : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tDEFA_LHB_MCFG03_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_lhb_mux_num            : 4  ;
        __IO uint32_t pen_pos1_lhb_mux_num       : 4  ;
        __IO uint32_t pen_dat1_lhb_mux_num       : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tLHB_MUX_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t pen_pos1_mux_cfg0          : 6  ;
        __IO uint32_t pen_pos1_mux_cfg1          : 6  ;
        __IO uint32_t pen_pos1_mux_cfg2          : 6  ;
        __IO uint32_t pen_pos1_mux_cfg3          : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPEN_POS1_LHB_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t pen_dat1_mux_cfg0          : 6  ;
        __IO uint32_t pen_dat1_mux_cfg1          : 6  ;
        __IO uint32_t pen_dat1_mux_cfg2          : 6  ;
        __IO uint32_t pen_dat1_mux_cfg3          : 6  ;
        __IO uint32_t pen_dat1_tmuxnum           : 4  ;
        __IO uint32_t pen_dat1_tsync_muxnum      : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPEN_DAT1_LHB_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t mux_fctl_rise_num1         : 8  ;
        __IO uint32_t mux_fctl_rise_num2         : 8  ;
        __IO uint32_t fctl_rsti_off              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMUX_FCTL_NUM1_t;

typedef union
{
    struct
    {
        __IO uint32_t mux_fctl_fall_num1         : 8  ;
        __IO uint32_t mux_fctl_fall_num2         : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMUX_FCTL_NUM2_t;

typedef union
{
    struct
    {
        __IO uint32_t ping_max                   : 8  ;
        __IO uint32_t ping_pwm_num               : 7  ;
        __IO uint32_t ping_mux_sel               : 1  ;
        __IO uint32_t ping_mode                  : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPING_MUX_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t pdrv_mode                  : 1  ;
        __IO uint32_t pdrv_adc_en                : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPRE_DRV_CTL_t;

//typedef union
//{
//    struct
//    {
//        __IO uint32_t reserved_1                 : 32 ;
//    }__PACKED tBit;
//    __IO uint32_t ulBulk;
//}__PACKED tRESERVED_1_t;
//
//
//typedef union
//{
//    struct
//    {
//        __IO uint32_t reserved_2                 : 32 ;
//    }__PACKED tBit;
//    __IO uint32_t ulBulk;
//}__PACKED tRESERVED_2_t;


typedef union
{
    struct
    {
        __IO uint32_t pen_dc_md_pen              : 2  ;
        __IO uint32_t pen_dc_md_fig              : 2  ;
        __IO uint32_t pre_ch_conb_en             : 1  ;
        __IO uint32_t pre_ch_conb_inv            : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tAFE_SENSE_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t rst_phd_fall_num           : 8  ;
        __IO uint32_t phd_all_fall_num           : 8  ;
        __IO uint32_t adc_in_phd_rise_num        : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_SENSE_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t phd_en_op_num              : 10 ;
        __IO uint32_t phd_md_op_num              : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPDB_PHD_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t sys_dummy0                 : 16 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSYS_DUMMY0_t;


typedef union
{
    struct
    {
        __IO uint32_t sys_dummy1                 : 16 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSYS_DUMMY1_t;


typedef union
{
    struct
    {
        __IO uint32_t test_adc_sel               : 1  ;
        __IO uint32_t mon_adcdo_en               : 1  ;
        __IO uint32_t test_adc_eoc_sel           : 2  ;
        __IO uint32_t phd_mon_sel                : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tTEST_MUX_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t edgecnt_th                 : 4  ;
        __IO uint32_t sel_delay                  : 1  ;
        __IO uint32_t invalid_dly                : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t offset_val                 : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_CTL3_t;

typedef union
{
    struct
    {
        __I uint32_t insert_dly_val              : 8  ;
        __I uint32_t real0_edgecnt               : 4  ;
        __I uint32_t real1_edgecnt               : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_ST1_t;

typedef union
{
    struct
    {
        __I uint32_t cal_delay                   : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_ST3_t;

typedef union
{
    struct
    {
        __I uint32_t mon_r0_adcdo_a              : 12 ;
        __I uint32_t reserve_zero1               : 4  ;
        __I uint32_t mon_r0_adcdo_b              : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_R0_ADCDO_t;

typedef union
{
    struct
    {
        __I uint32_t mon_r1_adcdo_a              : 12 ;
        __I uint32_t reserve_zero2               : 4  ;
        __I uint32_t mon_r1_adcdo_b              : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_R1_ADCDO_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_buf_clk_on              : 1  ;
        __IO uint32_t r0_cfclk_on                : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_SYS_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_dum_drv_en              : 2  ;
        __IO uint32_t r0_ch_en_int               : 7  ;
        __IO uint32_t r0_ch_en_hvc               : 9  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CH_EN_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_top_mux_num             : 4  ;
        __IO uint32_t r0_bot_mux_num             : 4  ;
        __IO uint32_t r0_mux_int_en              : 4  ;
        __IO uint32_t r0_mux_int_stuck_val       : 5  ;
        __IO uint32_t r0_mux_off_en              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_MUX_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_mux_s_stuck             : 10 ;
        __IO uint32_t r0_mux_s_line_stuck        : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_MUX_S_STUCK_VAL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_mux_f_stuck_val         : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_MUX_F_STUCK_VAL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux1_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux1_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux1_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux2_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux2_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux2_r1g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R1G_MUX1_2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux1_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux1_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux1_r2g3            : 5  ;
        __IO uint32_t r0_cr_mux2_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux2_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux2_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R2G_MUX1_2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux1_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux1_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux1_r3g3            : 5  ;
        __IO uint32_t r0_cr_mux2_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux2_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux2_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R3G_MUX1_2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux3_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux3_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux3_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux4_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux4_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux4_r1g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R1G_MUX3_4_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux3_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux3_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux3_r2g3            : 5  ;
        __IO uint32_t r0_cr_mux4_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux4_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux4_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R2G_MUX3_4_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux3_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux3_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux3_r3g3            : 5  ;
        __IO uint32_t r0_cr_mux4_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux4_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux4_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R3G_MUX3_4_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux5_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux5_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux5_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux6_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux6_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux6_r1g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R1G_MUX5_6_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux5_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux5_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux5_r2g3            : 5  ;
        __IO uint32_t r0_cr_mux6_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux6_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux6_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R2G_MUX5_6_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux5_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux5_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux5_r3g3            : 5  ;
        __IO uint32_t r0_cr_mux6_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux6_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux6_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R3G_MUX5_6_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux7_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux7_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux7_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux8_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux8_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux8_r1g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R1G_MUX7_8_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux7_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux7_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux7_r2g3            : 5  ;
        __IO uint32_t r0_cr_mux8_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux8_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux8_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R2G_MUX7_8_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux7_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux7_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux7_r3g3            : 5  ;
        __IO uint32_t r0_cr_mux8_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux8_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux8_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R3G_MUX7_8_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux9_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux9_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux9_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux10_r1g1           : 5  ;
        __IO uint32_t r0_cr_mux10_r1g2           : 5  ;
        __IO uint32_t r0_cr_mux10_r1g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R1G_MUX9_10_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux9_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux9_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux9_r2g3            : 5  ;
        __IO uint32_t r0_cr_mux10_r2g1           : 5  ;
        __IO uint32_t r0_cr_mux10_r2g2           : 5  ;
        __IO uint32_t r0_cr_mux10_r2g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R2G_MUX9_10_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux9_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux9_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux9_r3g3            : 5  ;
        __IO uint32_t r0_cr_mux10_r3g1           : 5  ;
        __IO uint32_t r0_cr_mux10_r3g2           : 5  ;
        __IO uint32_t r0_cr_mux10_r3g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R3G_MUX9_10_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_top_fig_gtune           : 3  ;
        __IO uint32_t r0_mid_fig_gtune           : 3  ;
        __IO uint32_t r0_bot_fig_gtune           : 3  ;
        __IO uint32_t r0_pen_gtune               : 3  ;
        __IO uint32_t r0_pdrv_gtune              : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_GTUNE_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux1_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row5_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row5_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_ROW_MUX1_2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux3_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row5_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row5_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_ROW_MUX3_4_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux5_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row5_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row5_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_ROW_MUX5_6_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux7_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux7_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux7_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux7_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux7_row5_gsel       : 2  ;
        __IO uint32_t r0_cr_mux8_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux8_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux8_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux8_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux8_row5_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_ROW_MUX7_8_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux9_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux9_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux9_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux9_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux9_row5_gsel       : 2  ;
        __IO uint32_t r0_cr_mux10_row1_gsel      : 2  ;
        __IO uint32_t r0_cr_mux10_row2_gsel      : 2  ;
        __IO uint32_t r0_cr_mux10_row3_gsel      : 2  ;
        __IO uint32_t r0_cr_mux10_row4_gsel      : 2  ;
        __IO uint32_t r0_cr_mux10_row5_gsel      : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_ROW_MUX9_10_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_col1_gsel            : 2  ;
        __IO uint32_t r0_cr_col2_gsel            : 2  ;
        __IO uint32_t r0_cr_col3_gsel            : 2  ;
        __IO uint32_t r0_cr_col4_gsel            : 2  ;
        __IO uint32_t r0_cr_col5_gsel            : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_GROUP_COL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_adc_skipnum             : 6  ;
        __IO uint32_t r0_adc_th                  : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_PHD_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_dly_th                  : 8  ;
        __IO uint32_t r0_offset_dly              : 8  ;
        __IO uint32_t r0_invalid_dly             : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_PHD_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_bypass_en               : 1  ;
        __IO uint32_t r0_coef_val1               : 6  ;
        __IO uint32_t r0_coef_val2               : 6  ;
        __IO uint32_t r0_adc_mon_data_sel        : 2  ;
        __IO uint32_t r0_phd_mon_en              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_PHD_CTL3_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_adc_mon_th_r            : 12 ;
        __IO uint32_t r0_adc_mon_th_f            : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_PHD_CTL4_t;

typedef union
{
    struct
    {
        __I uint32_t r0_pos_dly_buf              : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_PHD_ST1_t;

typedef union
{
    struct
    {
        __I uint32_t r0_pos_dly_sum              : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_PHD_ST2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_phd_in_s                : 2  ;
        __IO uint32_t r0_phd_en                  : 7  ;
        __IO uint32_t r0_rst_phd_en              : 1  ;
        __IO uint32_t r0_phd_gc_con              : 2  ;
        __IO uint32_t r0_phd_gc_hov              : 2  ;
        __IO uint32_t r0_phd_md                  : 1  ;
        __IO uint32_t r0_adc_in_phd              : 1  ;
        __IO uint32_t r0_stuck_rst_phd           : 1  ;
        __IO uint32_t r0_stuck_adc_in_phd        : 1  ;
        __IO uint32_t r0_stuck_phd_md            : 1  ;
        __IO uint32_t r0_stuck_phd_en            : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_PHD_SENSE_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_fig_lv_adc_ref_bcon     : 2  ;
        __IO uint32_t r0_pen_lv_adc_ref_bcon     : 2  ;
        __IO uint32_t r0_pdrv_lv_adc_ref_bcon    : 2  ;
        __IO uint32_t r0_fig_lv_adc_bcon         : 3  ;
        __IO uint32_t r0_pen_lv_adc_bcon         : 3  ;
        __IO uint32_t r0_pdrv_lv_adc_bcon        : 3  ;
        __IO uint32_t r0_adc_clk_div_1p5         : 1  ;
        __IO uint32_t r0_adc_stc_insel           : 1  ;
        __IO uint32_t r0_fig_adc_comp_bias_ctl    : 1  ;
        __IO uint32_t r0_pen_adc_comp_bias_ctl    : 1  ;
        __IO uint32_t r0_pdrv_adc_comp_bias_ctl    : 1  ;
        __IO uint32_t r0_fig_adc_mdac_comp_ctl    : 2  ;
        __IO uint32_t r0_pen_adc_mdac_comp_ctl    : 2  ;
        __IO uint32_t r0_pdrv_adc_mdac_comp_ctl    : 2  ;
        __IO uint32_t r0_fig_adc_mdac_slew_ctl    : 1  ;
        __IO uint32_t r0_pen_adc_mdac_slew_ctl    : 1  ;
        __IO uint32_t r0_pdrv_adc_mdac_slew_ctl    : 1  ;
        __IO uint32_t r0_fig_adc_ref_idrv_ctl    : 1  ;
        __IO uint32_t r0_pen_adc_ref_idrv_ctl    : 1  ;
        __IO uint32_t r0_pdrv_adc_ref_idrv_ctl    : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_ADC_SENSE_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_pdb_hvbias              : 1  ;
        __IO uint32_t r0_pdb_hvc                 : 1  ;
        __IO uint32_t r0_pdb_lvbias              : 1  ;
        __IO uint32_t r0_pdb_int                 : 1  ;
        __IO uint32_t r0_pdb_sha                 : 1  ;
        __IO uint32_t r0_bgr_en                  : 1  ;
        __IO uint32_t r0_bias_en                 : 1  ;
        __IO uint32_t r0_pdb_adc                 : 1  ;
        __IO uint32_t r0_stuck_hvbias            : 2  ;
        __IO uint32_t r0_stuck_hvc               : 2  ;
        __IO uint32_t r0_stuck_lvbias            : 2  ;
        __IO uint32_t r0_stuck_int               : 2  ;
        __IO uint32_t r0_stuck_sha               : 2  ;
        __IO uint32_t r0_stuck_bgr_en            : 2  ;
        __IO uint32_t r0_stuck_bias_en           : 2  ;
        __IO uint32_t r0_stuck_adc               : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_PDB_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_pdb_phd                 : 1  ;
        __IO uint32_t r0_pdb_phd_buf             : 1  ;
        __IO uint32_t r0_stuck_phd               : 2  ;
        __IO uint32_t r0_stuck_phd_buf           : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_PDB_PHD_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_reserve                 : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_RESERVE_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_pen_dc_md_stuck         : 2  ;
        __IO uint32_t r0_pre_comp                : 1  ;
        __IO uint32_t r0_fig_int_ref             : 3  ;
        __IO uint32_t r0_pen_int_ref             : 3  ;
        __IO uint32_t r0_fig_sha_ref             : 3  ;
        __IO uint32_t r0_pen_sha_ref             : 3  ;
        __IO uint32_t r0_fig_pre_bs_lp           : 1  ;
        __IO uint32_t r0_pen_pre_bs_lp           : 1  ;
        __IO uint32_t r0_pdrv_pre_bs_lp          : 1  ;
        __IO uint32_t r0_fig_int_bs_lp           : 1  ;
        __IO uint32_t r0_pen_int_bs_lp           : 1  ;
        __IO uint32_t r0_fig_sha_bs_lp           : 1  ;
        __IO uint32_t r0_pen_sha_bs_lp           : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_AFE_SENSE_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_fig_pre_gc              : 3  ;
        __IO uint32_t r0_pen_pre_gc_con          : 3  ;
        __IO uint32_t r0_pen_pre_gc_hov          : 3  ;
        __IO uint32_t r0_pdrv_pre_gc_con         : 3  ;
        __IO uint32_t r0_pdrv_pre_gc_hov         : 3  ;
        __IO uint32_t r0_fig_int_gc              : 2  ;
        __IO uint32_t r0_pen_int_gc_con          : 2  ;
        __IO uint32_t r0_pen_int_gc_hov          : 2  ;
        __IO uint32_t r0_fig_int_half            : 1  ;
        __IO uint32_t r0_pen_int_half_con        : 1  ;
        __IO uint32_t r0_pen_int_half_hov        : 1  ;
        __IO uint32_t r0_pdrv_int_half_con       : 1  ;
        __IO uint32_t r0_pdrv_int_half_hov       : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_AFE_SENSE_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_fig_hv_ssu_bcon         : 3  ;
        __IO uint32_t r0_pen_hv_ssu_bcon         : 3  ;
        __IO uint32_t r0_pdrv_hv_ssu_bcon        : 3  ;
        __IO uint32_t r0_fig_lv_ssu_bcon         : 3  ;
        __IO uint32_t r0_pen_lv_ssu_bcon         : 3  ;
        __IO uint32_t r0_fig_lv_ssu_bcons        : 3  ;
        __IO uint32_t r0_pen_lv_ssu_bcons        : 3  ;
        __IO uint32_t r0_lv_ssu_bconp            : 3  ;
        __IO uint32_t r0_lv_ssu_bconp_buf        : 1  ;
        __IO uint32_t r0_ref_bcon                : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_AFE_SENSE_CTL3_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_display_vcomr           : 2  ;
        __IO uint32_t r0_touch_f_vcomr           : 2  ;
        __IO uint32_t r0_touch_p_vcomr           : 2  ;
        __IO uint32_t r0_stuck_vcomr             : 1  ;
        __IO uint32_t r0_stuck_vcomr_level       : 1  ;
        __IO uint32_t r0_tsync_opt               : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_VCOMR_OPT_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_double_buf_en           : 1  ;
        __IO uint32_t r0_pre_drv_en              : 1  ;
        __IO uint32_t r0_pdrv_buf_st_num         : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_BUF_OPT_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_stuck_rstp              : 2  ;
        __IO uint32_t r0_stuck_phtcr             : 2  ;
        __IO uint32_t r0_stuck_vcr               : 2  ;
        __IO uint32_t r0_stuck_rsti              : 2  ;
        __IO uint32_t r0_stuck_phth0             : 2  ;
        __IO uint32_t r0_stuck_phth1             : 2  ;
        __IO uint32_t r0_stuck_pht0              : 2  ;
        __IO uint32_t r0_stuck_pht1              : 2  ;
        __IO uint32_t r0_stuck_muxs_en           : 1  ;
        __IO uint32_t r0_stuck_muxf_en           : 1  ;
        __IO uint32_t r0_vcr_inv_en              : 1  ;
        __IO uint32_t r0_fig_stuck_vcr_en_odd    : 1  ;
        __IO uint32_t r0_pen_stuck_vcr_en_odd    : 1  ;
        __IO uint32_t r0_fig_stuck_vcr_en_even    : 1  ;
        __IO uint32_t r0_pen_stuck_vcr_en_even    : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TG_STUCK_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_adc_in                  : 18 ;
        __IO uint32_t r0_adc_op_opt              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_ADC_IN_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_uplink_mux              : 10 ;
        __IO uint32_t r0_uplink_state            : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_UPLINK_MUX_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_mux_m1_bit_en           : 10 ;
        __IO uint32_t r0_mux_nd_bit_en           : 10 ;
        __IO uint32_t r0_mux_pp_bit_en           : 5  ;
        __IO uint32_t r0_mux_pd_bit_en           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_LHB_MUX_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_tm_mon_en               : 1  ;
        __IO uint32_t r0_tm_mon_s                : 3  ;
        __IO uint32_t r0_tm_ps_ev                : 1  ;
        __IO uint32_t r0_tm_ps_od                : 1  ;
        __IO uint32_t r0_tm_ssu_pen              : 1  ;
        __IO uint32_t r0_test_adc_a              : 1  ;
        __IO uint32_t r0_test_adc_b              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TEST_MUX_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_buf_clk_on              : 1  ;
        __IO uint32_t r1_cfclk_on                : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_SYS_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_dum_drv_en              : 2  ;
        __IO uint32_t r1_ch_en_int               : 7  ;
        __IO uint32_t r1_ch_en_hvc               : 9  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CH_EN_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_top_mux_num             : 4  ;
        __IO uint32_t r1_bot_mux_num             : 4  ;
        __IO uint32_t r1_mux_int_en              : 4  ;
        __IO uint32_t r1_mux_int_stuck_val       : 5  ;
        __IO uint32_t r1_mux_off_en              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_MUX_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_mux_s_stuck             : 10 ;
        __IO uint32_t r1_mux_s_line_stuck        : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_MUX_S_STUCK_VAL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_mux_f_stuck_val         : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_MUX_F_STUCK_VAL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux1_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux1_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux1_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux2_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux2_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux2_r1g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R1G_MUX1_2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux1_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux1_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux1_r2g3            : 5  ;
        __IO uint32_t r1_cr_mux2_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux2_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux2_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R2G_MUX1_2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux1_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux1_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux1_r3g3            : 5  ;
        __IO uint32_t r1_cr_mux2_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux2_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux2_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R3G_MUX1_2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux3_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux3_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux3_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux4_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux4_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux4_r1g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R1G_MUX3_4_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux3_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux3_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux3_r2g3            : 5  ;
        __IO uint32_t r1_cr_mux4_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux4_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux4_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R2G_MUX3_4_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux3_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux3_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux3_r3g3            : 5  ;
        __IO uint32_t r1_cr_mux4_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux4_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux4_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R3G_MUX3_4_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux5_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux5_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux5_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux6_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux6_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux6_r1g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R1G_MUX5_6_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux5_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux5_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux5_r2g3            : 5  ;
        __IO uint32_t r1_cr_mux6_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux6_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux6_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R2G_MUX5_6_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux5_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux5_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux5_r3g3            : 5  ;
        __IO uint32_t r1_cr_mux6_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux6_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux6_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R3G_MUX5_6_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux7_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux7_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux7_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux8_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux8_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux8_r1g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R1G_MUX7_8_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux7_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux7_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux7_r2g3            : 5  ;
        __IO uint32_t r1_cr_mux8_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux8_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux8_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R2G_MUX7_8_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux7_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux7_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux7_r3g3            : 5  ;
        __IO uint32_t r1_cr_mux8_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux8_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux8_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R3G_MUX7_8_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux9_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux9_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux9_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux10_r1g1           : 5  ;
        __IO uint32_t r1_cr_mux10_r1g2           : 5  ;
        __IO uint32_t r1_cr_mux10_r1g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R1G_MUX9_10_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux9_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux9_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux9_r2g3            : 5  ;
        __IO uint32_t r1_cr_mux10_r2g1           : 5  ;
        __IO uint32_t r1_cr_mux10_r2g2           : 5  ;
        __IO uint32_t r1_cr_mux10_r2g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R2G_MUX9_10_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux9_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux9_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux9_r3g3            : 5  ;
        __IO uint32_t r1_cr_mux10_r3g1           : 5  ;
        __IO uint32_t r1_cr_mux10_r3g2           : 5  ;
        __IO uint32_t r1_cr_mux10_r3g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R3G_MUX9_10_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_top_fig_gtune           : 3  ;
        __IO uint32_t r1_mid_fig_gtune           : 3  ;
        __IO uint32_t r1_bot_fig_gtune           : 3  ;
        __IO uint32_t r1_pen_gtune               : 3  ;
        __IO uint32_t r1_pdrv_gtune              : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_GTUNE_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux1_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row5_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row5_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_ROW_MUX1_2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux3_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row5_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row5_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_ROW_MUX3_4_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux5_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row5_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row5_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_ROW_MUX5_6_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux7_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux7_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux7_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux7_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux7_row5_gsel       : 2  ;
        __IO uint32_t r1_cr_mux8_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux8_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux8_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux8_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux8_row5_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_ROW_MUX7_8_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux9_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux9_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux9_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux9_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux9_row5_gsel       : 2  ;
        __IO uint32_t r1_cr_mux10_row1_gsel      : 2  ;
        __IO uint32_t r1_cr_mux10_row2_gsel      : 2  ;
        __IO uint32_t r1_cr_mux10_row3_gsel      : 2  ;
        __IO uint32_t r1_cr_mux10_row4_gsel      : 2  ;
        __IO uint32_t r1_cr_mux10_row5_gsel      : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_ROW_MUX9_10_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_col1_gsel            : 2  ;
        __IO uint32_t r1_cr_col2_gsel            : 2  ;
        __IO uint32_t r1_cr_col3_gsel            : 2  ;
        __IO uint32_t r1_cr_col4_gsel            : 2  ;
        __IO uint32_t r1_cr_col5_gsel            : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_GROUP_COL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_adc_skipnum             : 6  ;
        __IO uint32_t r1_adc_th                  : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_PHD_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_dly_th                  : 8  ;
        __IO uint32_t r1_offset_dly              : 8  ;
        __IO uint32_t r1_invalid_dly             : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_PHD_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_bypass_en               : 1  ;
        __IO uint32_t r1_coef_val1               : 6  ;
        __IO uint32_t r1_coef_val2               : 6  ;
        __IO uint32_t r1_adc_mon_data_sel        : 2  ;
        __IO uint32_t r1_phd_mon_en              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_PHD_CTL3_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_adc_mon_th_r            : 12 ;
        __IO uint32_t r1_adc_mon_th_f            : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_PHD_CTL4_t;

typedef union
{
    struct
    {
        __I uint32_t r1_pos_dly_buf              : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_PHD_ST1_t;

typedef union
{
    struct
    {
        __I uint32_t r1_pos_dly_sum              : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_PHD_ST2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_phd_in_s                : 2  ;
        __IO uint32_t r1_phd_en                  : 7  ;
        __IO uint32_t r1_rst_phd_en              : 1  ;
        __IO uint32_t r1_phd_gc_con              : 2  ;
        __IO uint32_t r1_phd_gc_hov              : 2  ;
        __IO uint32_t r1_phd_md                  : 1  ;
        __IO uint32_t r1_adc_in_phd              : 1  ;
        __IO uint32_t r1_stuck_rst_phd           : 1  ;
        __IO uint32_t r1_stuck_adc_in_phd        : 1  ;
        __IO uint32_t r1_stuck_phd_md            : 1  ;
        __IO uint32_t r1_stuck_phd_en            : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_PHD_SENSE_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_fig_lv_adc_ref_bcon     : 2  ;
        __IO uint32_t r1_pen_lv_adc_ref_bcon     : 2  ;
        __IO uint32_t r1_pdrv_lv_adc_ref_bcon    : 2  ;
        __IO uint32_t r1_fig_lv_adc_bcon         : 3  ;
        __IO uint32_t r1_pen_lv_adc_bcon         : 3  ;
        __IO uint32_t r1_pdrv_lv_adc_bcon        : 3  ;
        __IO uint32_t r1_adc_clk_div_1p5         : 1  ;
        __IO uint32_t r1_adc_stc_insel           : 1  ;
        __IO uint32_t r1_fig_adc_comp_bias_ctl    : 1  ;
        __IO uint32_t r1_pen_adc_comp_bias_ctl    : 1  ;
        __IO uint32_t r1_pdrv_adc_comp_bias_ctl    : 1  ;
        __IO uint32_t r1_fig_adc_mdac_comp_ctl    : 2  ;
        __IO uint32_t r1_pen_adc_mdac_comp_ctl    : 2  ;
        __IO uint32_t r1_pdrv_adc_mdac_comp_ctl    : 2  ;
        __IO uint32_t r1_fig_adc_mdac_slew_ctl    : 1  ;
        __IO uint32_t r1_pen_adc_mdac_slew_ctl    : 1  ;
        __IO uint32_t r1_pdrv_adc_mdac_slew_ctl    : 1  ;
        __IO uint32_t r1_fig_adc_ref_idrv_ctl    : 1  ;
        __IO uint32_t r1_pen_adc_ref_idrv_ctl    : 1  ;
        __IO uint32_t r1_pdrv_adc_ref_idrv_ctl    : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_ADC_SENSE_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_pdb_hvbias              : 1  ;
        __IO uint32_t r1_pdb_hvc                 : 1  ;
        __IO uint32_t r1_pdb_lvbias              : 1  ;
        __IO uint32_t r1_pdb_int                 : 1  ;
        __IO uint32_t r1_pdb_sha                 : 1  ;
        __IO uint32_t r1_bgr_en                  : 1  ;
        __IO uint32_t r1_bias_en                 : 1  ;
        __IO uint32_t r1_pdb_adc                 : 1  ;
        __IO uint32_t r1_stuck_hvbias            : 2  ;
        __IO uint32_t r1_stuck_hvc               : 2  ;
        __IO uint32_t r1_stuck_lvbias            : 2  ;
        __IO uint32_t r1_stuck_int               : 2  ;
        __IO uint32_t r1_stuck_sha               : 2  ;
        __IO uint32_t r1_stuck_bgr_en            : 2  ;
        __IO uint32_t r1_stuck_bias_en           : 2  ;
        __IO uint32_t r1_stuck_adc               : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_PDB_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_pdb_phd                 : 1  ;
        __IO uint32_t r1_pdb_phd_buf             : 1  ;
        __IO uint32_t r1_stuck_phd               : 2  ;
        __IO uint32_t r1_stuck_phd_buf           : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_PDB_PHD_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_reserve                 : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_RESERVE_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_pen_dc_md_stuck         : 2  ;
        __IO uint32_t r1_pre_comp                : 1  ;
        __IO uint32_t r1_fig_int_ref             : 3  ;
        __IO uint32_t r1_pen_int_ref             : 3  ;
        __IO uint32_t r1_fig_sha_ref             : 3  ;
        __IO uint32_t r1_pen_sha_ref             : 3  ;
        __IO uint32_t r1_fig_pre_bs_lp           : 1  ;
        __IO uint32_t r1_pen_pre_bs_lp           : 1  ;
        __IO uint32_t r1_pdrv_pre_bs_lp          : 1  ;
        __IO uint32_t r1_fig_int_bs_lp           : 1  ;
        __IO uint32_t r1_pen_int_bs_lp           : 1  ;
        __IO uint32_t r1_fig_sha_bs_lp           : 1  ;
        __IO uint32_t r1_pen_sha_bs_lp           : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_AFE_SENSE_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_fig_pre_gc              : 3  ;
        __IO uint32_t r1_pen_pre_gc_con          : 3  ;
        __IO uint32_t r1_pen_pre_gc_hov          : 3  ;
        __IO uint32_t r1_pdrv_pre_gc_con         : 3  ;
        __IO uint32_t r1_pdrv_pre_gc_hov         : 3  ;
        __IO uint32_t r1_fig_int_gc              : 2  ;
        __IO uint32_t r1_pen_int_gc_con          : 2  ;
        __IO uint32_t r1_pen_int_gc_hov          : 2  ;
        __IO uint32_t r1_fig_int_half            : 1  ;
        __IO uint32_t r1_pen_int_half_con        : 1  ;
        __IO uint32_t r1_pen_int_half_hov        : 1  ;
        __IO uint32_t r1_pdrv_int_half_con       : 1  ;
        __IO uint32_t r1_pdrv_int_half_hov       : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_AFE_SENSE_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_fig_hv_ssu_bcon         : 3  ;
        __IO uint32_t r1_pen_hv_ssu_bcon         : 3  ;
        __IO uint32_t r1_pdrv_hv_ssu_bcon        : 3  ;
        __IO uint32_t r1_fig_lv_ssu_bcon         : 3  ;
        __IO uint32_t r1_pen_lv_ssu_bcon         : 3  ;
        __IO uint32_t r1_fig_lv_ssu_bcons        : 3  ;
        __IO uint32_t r1_pen_lv_ssu_bcons        : 3  ;
        __IO uint32_t r1_lv_ssu_bconp            : 3  ;
        __IO uint32_t r1_lv_ssu_bconp_buf        : 1  ;
        __IO uint32_t r1_ref_bcon                : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_AFE_SENSE_CTL3_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_display_vcomr           : 2  ;
        __IO uint32_t r1_touch_f_vcomr           : 2  ;
        __IO uint32_t r1_touch_p_vcomr           : 2  ;
        __IO uint32_t r1_stuck_vcomr             : 1  ;
        __IO uint32_t r1_stuck_vcomr_level       : 1  ;
        __IO uint32_t r1_tsync_opt               : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_VCOMR_OPT_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_double_buf_en           : 1  ;
        __IO uint32_t r1_pre_drv_en              : 1  ;
        __IO uint32_t r1_pdrv_buf_st_num         : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_BUF_OPT_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_stuck_rstp              : 2  ;
        __IO uint32_t r1_stuck_phtcr             : 2  ;
        __IO uint32_t r1_stuck_vcr               : 2  ;
        __IO uint32_t r1_stuck_rsti              : 2  ;
        __IO uint32_t r1_stuck_phth0             : 2  ;
        __IO uint32_t r1_stuck_phth1             : 2  ;
        __IO uint32_t r1_stuck_pht0              : 2  ;
        __IO uint32_t r1_stuck_pht1              : 2  ;
        __IO uint32_t r1_stuck_muxs_en           : 1  ;
        __IO uint32_t r1_stuck_muxf_en           : 1  ;
        __IO uint32_t r1_vcr_inv_en              : 1  ;
        __IO uint32_t r1_fig_stuck_vcr_en_odd    : 1  ;
        __IO uint32_t r1_pen_stuck_vcr_en_odd    : 1  ;
        __IO uint32_t r1_fig_stuck_vcr_en_even   : 1  ;
        __IO uint32_t r1_pen_stuck_vcr_en_even   : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TG_STUCK_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_adc_in                  : 18 ;
        __IO uint32_t r1_adc_op_opt              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_ADC_IN_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_uplink_mux              : 10 ;
        __IO uint32_t r1_uplink_state            : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_UPLINK_MUX_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_mux_m1_bit_en           : 10 ;
        __IO uint32_t r1_mux_nd_bit_en           : 10 ;
        __IO uint32_t r1_mux_pp_bit_en           : 5  ;
        __IO uint32_t r1_mux_pd_bit_en           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_LHB_MUX_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_tm_mon_en               : 1  ;
        __IO uint32_t r1_tm_mon_s                : 3  ;
        __IO uint32_t r1_tm_ps_ev                : 1  ;
        __IO uint32_t r1_tm_ps_od                : 1  ;
        __IO uint32_t r1_tm_ssu_pen              : 1  ;
        __IO uint32_t r1_test_adc_a              : 1  ;
        __IO uint32_t r1_test_adc_b              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TEST_MUX_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t apen_cfclk_on              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tAPEN_CFCLK_ON_t;


typedef union
{
    struct
    {
        __I uint32_t reserve_zero3               : 2  ;
        __I uint32_t cal_delay0                  : 8  ;
        __I uint32_t reserve_zero4               : 6  ;
        __I uint32_t cal_delay1                  : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_CAL_DELAY_t;

typedef union
{
    struct
    {
        __I uint32_t reserve_zero5               : 2  ;
        __I uint32_t r0_a_egsign                 : 8  ;
        __I uint32_t reserve_zero6               : 6  ;
        __I uint32_t r0_b_egsign                 : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_EDGE_SIGN_R0_t;

typedef union
{
    struct
    {
        __I uint32_t reserve_zero7               : 2  ;
        __I uint32_t r1_a_egsign                 : 8  ;
        __I uint32_t reserve_zero8               : 6  ;
        __I uint32_t r1_b_egsign                 : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_EDGE_SIGN_R1_t;


typedef struct
{
        tPRODUCT_ID_t                        PRODUCT_ID          ;  // 0x0000    R    Default Val : 0x09251000
        tSPIS_CFG_t                          SPIS_CFG            ;  // 0x0004    R/W  Default Val : 0x00000003
        tSPIS_ERROR_CLR_t                    SPIS_ERROR_CLR      ;  // 0x0008    R/W  Default Val : 0x00000000
        tSPIS_ERROR_ST_t                     SPIS_ERROR_ST       ;  // 0x000C    R    Default Val : 0x00000000
        tSPIS_PAD_CTL_t                      SPIS_PAD_CTL        ;  // 0x0010    R/W  Default Val : 0x00000041
        tSYS_CFG_t                           SYS_CFG             ;  // 0x0014    R/W  Default Val : 0x00000004
        tTC_START_t                          TC_START            ;  // 0x0018    R/W  Default Val : 0x00000000
        tCH_NUM_t                            CH_NUM              ;  // 0x001C    R/W  Default Val : 0x00012492
        tMUX_CTL_t                           MUX_CTL             ;  // 0x0020    R/W  Default Val : 0x00000009
        tMUX_DLY_0_t                         MUX_DLY_0           ;  // 0x0024    R/W  Default Val : 0x00000000
        tMUX_DLY_1_t                         MUX_DLY_1           ;  // 0x0028    R/W  Default Val : 0x00000000
        tMUX_DLY_2_t                         MUX_DLY_2           ;  // 0x002C    R/W  Default Val : 0x00000000
        tSDIC_CFG_t                          SDIC_CFG            ;  // 0x0030    R/W  Default Val : 0x00000020
        tPWM_FIG_CTL_t                       PWM_FIG_CTL         ;  // 0x0034    R/W  Default Val : 0x0001C086
        tPWM_POS_CTL_t                       PWM_POS_CTL         ;  // 0x0038    R/W  Default Val : 0x001C0860
        tPWM_DAT_CTL_t                       PWM_DAT_CTL         ;  // 0x003C    R/W  Default Val : 0x0E043060
        tPWM_ND_CTL_t                        PWM_ND_CTL          ;  // 0x0040    R/W  Default Val : 0x001C0860
        tPWM_PRD_t                           PWM_PRD             ;  // 0x0044    R/W  Default Val : 0x002E2E2E
        tSMPL_CTL_t                          SMPL_CTL            ;  // 0x0048    R/W  Default Val : 0x0001C387
        tRSTP_RISE_NUM_t                     RSTP_RISE_NUM       ;  // 0x004C    R/W  Default Val : 0x000E0E0E
        tRSTP_FALL_NUM1_t                    RSTP_FALL_NUM1      ;  // 0x0050    R/W  Default Val : 0x00030303
        tRSTP_FALL_NUM2_t                    RSTP_FALL_NUM2      ;  // 0x0054    R/W  Default Val : 0x00030303
        tPHTCR_RISE_NUM_t                    PHTCR_RISE_NUM      ;  // 0x0058    R/W  Default Val : 0x002C2C2C
        tPHTCR_FALL_NUM_t                    PHTCR_FALL_NUM      ;  // 0x005C    R/W  Default Val : 0x001E1E1E
        tVCR_NUM_t                           VCR_NUM             ;  // 0x0060    R/W  Default Val : 0x00282828
        tRSTI_RISE_NUM_t                     RSTI_RISE_NUM       ;  // 0x0064    R/W  Default Val : 0x000F0F0F
        tRSTI_FALL_NUM1_t                    RSTI_FALL_NUM1      ;  // 0x0068    R/W  Default Val : 0x001E1E1E
        tRSTI_FALL_NUM2_t                    RSTI_FALL_NUM2      ;  // 0x006C    R/W  Default Val : 0x00030303
        tPHTH0_RISE_NUM_t                    PHTH0_RISE_NUM      ;  // 0x0070    R/W  Default Val : 0x001E1E1E
        tPHTH0_FALL_NUM_t                    PHTH0_FALL_NUM      ;  // 0x0074    R/W  Default Val : 0x00141414
        tPHTH1_RISE_NUM_t                    PHTH1_RISE_NUM      ;  // 0x0078    R/W  Default Val : 0x00111111
        tPHTH1_FALL_NUM_t                    PHTH1_FALL_NUM      ;  // 0x007C    R/W  Default Val : 0x001E1E1E
        tPHT_CTL_t                           PHT_CTL             ;  // 0x0080    R/W  Default Val : 0x00022906
        tPHT_RISE_NUM_t                      PHT_RISE_NUM        ;  // 0x0084    R/W  Default Val : 0x00171717
        tPHT_FALL_NUM_t                      PHT_FALL_NUM        ;  // 0x0088    R/W  Default Val : 0x00111111
        tADC_CTL1_t                          ADC_CTL1            ;  // 0x008C    R/W  Default Val : 0x1000000A
        tADC_CTL2_t                          ADC_CTL2            ;  // 0x0090    R/W  Default Val : 0x0E40809F
        tADC_CTL3_t                          ADC_CTL3            ;  // 0x0094    R/W  Default Val : 0x0000809F
        tTG_STUCK_t                          TG_STUCK            ;  // 0x0098    R/W  Default Val : 0x0000000C
        tFIG_MUX_CFG_00_t                    FIG_MUX_CFG_00      ;  // 0x009C    R/W  Default Val : 0x76543210
        tFIG_MUX_CFG_01_t                    FIG_MUX_CFG_01      ;  // 0x00A0    R/W  Default Val : 0x00000098
        tRCOM_LHB_CFG_t                      RCOM_LHB_CFG        ;  // 0x00A4    R/W  Default Val : 0x00000000

        tDEFA_LHB_MCFG00_t                   DEFA_LHB_MCFG00[3]     ;  // 0x00A8    R/W  Default Val : 0x00000000
        tDEFA_LHB_MCFG01_t                   DEFA_LHB_MCFG01[3]     ;  // 0x00AC    R/W  Default Val : 0x00000000
        tDEFA_LHB_MCFG02_t                   DEFA_LHB_MCFG02[3]     ;  // 0x00B0    R/W  Default Val : 0x00000000
        tDEFA_LHB_MCFG03_t                   DEFA_LHB_MCFG03[3]     ;  // 0x00B4    R/W  Default Val : 0x00000000

        tLHB_MUX_NUM_t                       LHB_MUX_NUM         ;  // 0x00B8    R/W  Default Val : 0x00000000
        tPEN_POS1_LHB_CFG_t                  PEN_POS1_LHB_CFG    ;  // 0x00BC    R/W  Default Val : 0x00000000
        tPEN_DAT1_LHB_CFG_t                  PEN_DAT1_LHB_CFG    ;  // 0x00C0    R/W  Default Val : 0x00000000
        tMUX_FCTL_NUM1_t                     MUX_FCTL_NUM1       ;  // 0x00C4    R/W  Default Val : 0x00000000
        tMUX_FCTL_NUM2_t                     MUX_FCTL_NUM2       ;  // 0x00C8    R/W  Default Val : 0x00000000
        tPING_MUX_CTL_t                      PING_MUX_CTL        ;  // 0x00CC    R/W  Default Val : 0x00000000
        tPRE_DRV_CTL_t                       PRE_DRV_CTL         ;  // 0x00D0    R/W  Default Val : 0x00000000
//        tRESERVED_1_t                        RESERVED_1          ;  // 0x00D4    R/W  Default Val : 0x00000000
//        tRESERVED_2_t                        RESERVED_2          ;  // 0x00D8    R/W  Default Val : 0x00000000
        tAFE_SENSE_CTL1_t                    AFE_SENSE_CTL1      ;  // 0x00DC    R/W  Default Val : 0x00000000
        tPHD_SENSE_CTL2_t                    PHD_SENSE_CTL2      ;  // 0x00E0    R/W  Default Val : 0x00000000
        tPDB_PHD_CTL_t                       PDB_PHD_CTL         ;  // 0x00E4    R/W  Default Val : 0x0000A028
        tSYS_DUMMY0_t                        SYS_DUMMY0          ;  // 0x00E8    R/W  Default Val : 0x00000000
        tSYS_DUMMY1_t                        SYS_DUMMY1          ;  // 0x00EC    R/W  Default Val : 0x0000FFFF
        tTEST_MUX_CTL_t                      TEST_MUX_CTL        ;  // 0x00F0    R/W  Default Val : 0x00000000
        tPHD_CTL2_t                          PHD_CTL2            ;  // 0x00F4    R/W  Default Val : 0x00000000
        tPHD_CTL3_t                          PHD_CTL3            ;  // 0x00F8    R/W  Default Val : 0x00000000
        tPHD_ST1_t                           PHD_ST1             ;  // 0x00FC    R    Default Val : 0x00000000
        tPHD_ST3_t                          PHD_ST3             ;  // 0x0100    R    Default Val : 0x00000000
        tMON_R0_ADCDO_t                      MON_R0_ADCDO        ;  // 0x0104    R    Default Val : 0x00000000
        tMON_R1_ADCDO_t                      MON_R1_ADCDO        ;  // 0x0108    R    Default Val : 0x00000000
        tR0_SYS_CFG_t                        R0_SYS_CFG          ;  // 0x0200    R/W  Default Val : 0x00000001
        tR0_CH_EN_t                          R0_CH_EN            ;  // 0x0204    R/W  Default Val : 0x000001FC
        tR0_MUX_CTL_t                        R0_MUX_CTL          ;  // 0x0208    R/W  Default Val : 0x00000090
        tR0_MUX_S_STUCK_VAL_t                R0_MUX_S_STUCK_VAL  ;  // 0x020C    R/W  Default Val : 0x00000000
        tR0_MUX_F_STUCK_VAL_t                R0_MUX_F_STUCK_VAL  ;  // 0x0210    R/W  Default Val : 0x00000000
        tR0_CR_R1G_MUX1_2_t                  R0_CR_R1G_MUX1_2[6] ;  // 0x0214    R/W  Default Val : 0x00000000
        tR0_CR_R2G_MUX1_2_t                  R0_CR_R2G_MUX1_2[6] ;  // 0x0218    R/W  Default Val : 0x00000000
        tR0_CR_R3G_MUX1_2_t                  R0_CR_R3G_MUX1_2[6] ;  // 0x021C    R/W  Default Val : 0x00000000
        tR0_CR_R1G_MUX3_4_t                  R0_CR_R1G_MUX3_4[6] ;  // 0x0220    R/W  Default Val : 0x00000000
        tR0_CR_R2G_MUX3_4_t                  R0_CR_R2G_MUX3_4[6] ;  // 0x0224    R/W  Default Val : 0x00000000
        tR0_CR_R3G_MUX3_4_t                  R0_CR_R3G_MUX3_4[6] ;  // 0x0228    R/W  Default Val : 0x00000000
        tR0_CR_R1G_MUX5_6_t                  R0_CR_R1G_MUX5_6[6] ;  // 0x022C    R/W  Default Val : 0x00000000
        tR0_CR_R2G_MUX5_6_t                  R0_CR_R2G_MUX5_6[6] ;  // 0x0230    R/W  Default Val : 0x00000000
        tR0_CR_R3G_MUX5_6_t                  R0_CR_R3G_MUX5_6[6] ;  // 0x0234    R/W  Default Val : 0x00000000
        tR0_CR_R1G_MUX7_8_t                  R0_CR_R1G_MUX7_8[6] ;  // 0x0238    R/W  Default Val : 0x00000000
        tR0_CR_R2G_MUX7_8_t                  R0_CR_R2G_MUX7_8[6] ;  // 0x023C    R/W  Default Val : 0x00000000
        tR0_CR_R3G_MUX7_8_t                  R0_CR_R3G_MUX7_8[6] ;  // 0x0240    R/W  Default Val : 0x00000000
        tR0_CR_R1G_MUX9_10_t                 R0_CR_R1G_MUX9_10[6];  // 0x0244    R/W  Default Val : 0x00000000
        tR0_CR_R2G_MUX9_10_t                 R0_CR_R2G_MUX9_10[6];  // 0x0248    R/W  Default Val : 0x00000000
        tR0_CR_R3G_MUX9_10_t                 R0_CR_R3G_MUX9_10[6];  // 0x024C    R/W  Default Val : 0x00000000
        tR0_CR_GTUNE_t                       R0_CR_GTUNE[6]      ;  // 0x0250    R/W  Default Val : 0x00000000
        tR0_TUNE_ROW_MUX1_2_t                R0_TUNE_ROW_MUX1_2  ;  // 0x0254    R/W  Default Val : 0x000A92A4
        tR0_TUNE_ROW_MUX3_4_t                R0_TUNE_ROW_MUX3_4  ;  // 0x0258    R/W  Default Val : 0x000A92A4
        tR0_TUNE_ROW_MUX5_6_t                R0_TUNE_ROW_MUX5_6  ;  // 0x025C    R/W  Default Val : 0x000A92A4
        tR0_TUNE_ROW_MUX7_8_t                R0_TUNE_ROW_MUX7_8  ;  // 0x0260    R/W  Default Val : 0x000A92A4
        tR0_TUNE_ROW_MUX9_10_t               R0_TUNE_ROW_MUX9_10 ;  // 0x0264    R/W  Default Val : 0x000A92A4
        tR0_TUNE_GROUP_COL_t                 R0_TUNE_GROUP_COL   ;  // 0x0268    R/W  Default Val : 0x000002A4
        tR0_PHD_CTL1_t                       R0_PHD_CTL1         ;  // 0x026C    R/W  Default Val : 0x00000000
        tR0_PHD_CTL2_t                       R0_PHD_CTL2         ;  // 0x0270    R/W  Default Val : 0x00000000
        tR0_PHD_CTL3_t                       R0_PHD_CTL3         ;  // 0x0274    R/W  Default Val : 0x00000000
        tR0_PHD_CTL4_t                       R0_PHD_CTL4         ;  // 0x0278    R/W  Default Val : 0x00000000
        tR0_PHD_ST1_t                        R0_PHD_ST1          ;  // 0x027C    R    Default Val : 0x00000000
        tR0_PHD_ST2_t                        R0_PHD_ST2          ;  // 0x0280    R    Default Val : 0x00000000
        tR0_PHD_SENSE_CTL1_t                 R0_PHD_SENSE_CTL1   ;  // 0x0284    R/W  Default Val : 0x00001601
        tR0_ADC_SENSE_CTL_t                  R0_ADC_SENSE_CTL    ;  // 0x0288    R/W  Default Val : 0x015036D5
        tR0_PDB_CTL_t                        R0_PDB_CTL          ;  // 0x028C    R/W  Default Val : 0x00000060
        tR0_PDB_PHD_CTL_t                    R0_PDB_PHD_CTL      ;  // 0x0290    R/W  Default Val : 0x00000000
        tR0_RESERVE_t                        R0_RESERVE          ;  // 0x0294    R/W  Default Val : 0x00000000
        tR0_AFE_SENSE_CTL1_t                 R0_AFE_SENSE_CTL1   ;  // 0x0298    R/W  Default Val : 0x003FC920
        tR0_AFE_SENSE_CTL2_t                 R0_AFE_SENSE_CTL2   ;  // 0x029C    R/W  Default Val : 0x001FFFFF
        tR0_AFE_SENSE_CTL3_t                 R0_AFE_SENSE_CTL3   ;  // 0x02A0    R/W  Default Val : 0x00249249
        tR0_VCOMR_OPT_t                      R0_VCOMR_OPT        ;  // 0x02A4    R/W  Default Val : 0x00000000
        tR0_BUF_OPT_t                        R0_BUF_OPT          ;  // 0x02A8    R/W  Default Val : 0x00000003
        tR0_TG_STUCK_t                       R0_TG_STUCK         ;  // 0x02AC    R/W  Default Val : 0x00000000
        tR0_ADC_IN_CTL_t                     R0_ADC_IN_CTL       ;  // 0x02B0    R/W  Default Val : 0x00000000
        tR0_UPLINK_MUX_t                     R0_UPLINK_MUX       ;  // 0x02B4    R/W  Default Val : 0x00000000
        tR0_LHB_MUX_CTL_t                    R0_LHB_MUX_CTL      ;  // 0x02B8    R/W  Default Val : 0x3FFFFFFF
        tR0_TEST_MUX_CTL_t                   R0_TEST_MUX_CTL     ;  // 0x02BC    R/W  Default Val : 0x00000000
        tR1_SYS_CFG_t                        R1_SYS_CFG          ;  // 0x0300    R/W  Default Val : 0x00000001
        tR1_CH_EN_t                          R1_CH_EN            ;  // 0x0304    R/W  Default Val : 0x000001FC
        tR1_MUX_CTL_t                        R1_MUX_CTL          ;  // 0x0308    R/W  Default Val : 0x00000090
        tR1_MUX_S_STUCK_VAL_t                R1_MUX_S_STUCK_VAL  ;  // 0x030C    R/W  Default Val : 0x00000000
        tR1_MUX_F_STUCK_VAL_t                R1_MUX_F_STUCK_VAL  ;  // 0x0310    R/W  Default Val : 0x00000000
        tR1_CR_R1G_MUX1_2_t                  R1_CR_R1G_MUX1_2[6] ;  // 0x0314    R/W  Default Val : 0x00000000
        tR1_CR_R2G_MUX1_2_t                  R1_CR_R2G_MUX1_2[6] ;  // 0x0318    R/W  Default Val : 0x00000000
        tR1_CR_R3G_MUX1_2_t                  R1_CR_R3G_MUX1_2[6] ;  // 0x031C    R/W  Default Val : 0x00000000
        tR1_CR_R1G_MUX3_4_t                  R1_CR_R1G_MUX3_4[6] ;  // 0x0320    R/W  Default Val : 0x00000000
        tR1_CR_R2G_MUX3_4_t                  R1_CR_R2G_MUX3_4[6] ;  // 0x0324    R/W  Default Val : 0x00000000
        tR1_CR_R3G_MUX3_4_t                  R1_CR_R3G_MUX3_4[6] ;  // 0x0328    R/W  Default Val : 0x00000000
        tR1_CR_R1G_MUX5_6_t                  R1_CR_R1G_MUX5_6[6] ;  // 0x032C    R/W  Default Val : 0x00000000
        tR1_CR_R2G_MUX5_6_t                  R1_CR_R2G_MUX5_6[6] ;  // 0x0330    R/W  Default Val : 0x00000000
        tR1_CR_R3G_MUX5_6_t                  R1_CR_R3G_MUX5_6[6] ;  // 0x0334    R/W  Default Val : 0x00000000
        tR1_CR_R1G_MUX7_8_t                  R1_CR_R1G_MUX7_8[6] ;  // 0x0338    R/W  Default Val : 0x00000000
        tR1_CR_R2G_MUX7_8_t                  R1_CR_R2G_MUX7_8[6] ;  // 0x033C    R/W  Default Val : 0x00000000
        tR1_CR_R3G_MUX7_8_t                  R1_CR_R3G_MUX7_8[6] ;  // 0x0340    R/W  Default Val : 0x00000000
        tR1_CR_R1G_MUX9_10_t                 R1_CR_R1G_MUX9_10[6];  // 0x0344    R/W  Default Val : 0x00000000
        tR1_CR_R2G_MUX9_10_t                 R1_CR_R2G_MUX9_10[6];  // 0x0348    R/W  Default Val : 0x00000000
        tR1_CR_R3G_MUX9_10_t                 R1_CR_R3G_MUX9_10[6];  // 0x034C    R/W  Default Val : 0x00000000
        tR1_CR_GTUNE_t                       R1_CR_GTUNE[6]      ;  // 0x0350    R/W  Default Val : 0x00000000
        tR1_TUNE_ROW_MUX1_2_t                R1_TUNE_ROW_MUX1_2  ;  // 0x0354    R/W  Default Val : 0x000A92A4
        tR1_TUNE_ROW_MUX3_4_t                R1_TUNE_ROW_MUX3_4  ;  // 0x0358    R/W  Default Val : 0x000A92A4
        tR1_TUNE_ROW_MUX5_6_t                R1_TUNE_ROW_MUX5_6  ;  // 0x035C    R/W  Default Val : 0x000A92A4
        tR1_TUNE_ROW_MUX7_8_t                R1_TUNE_ROW_MUX7_8  ;  // 0x0360    R/W  Default Val : 0x000A92A4
        tR1_TUNE_ROW_MUX9_10_t               R1_TUNE_ROW_MUX9_10 ;  // 0x0364    R/W  Default Val : 0x000A92A4
        tR1_TUNE_GROUP_COL_t                 R1_TUNE_GROUP_COL   ;  // 0x0368    R/W  Default Val : 0x000002A4
        tR1_PHD_CTL1_t                       R1_PHD_CTL1         ;  // 0x036C    R/W  Default Val : 0x00000000
        tR1_PHD_CTL2_t                       R1_PHD_CTL2         ;  // 0x0370    R/W  Default Val : 0x00000000
        tR1_PHD_CTL3_t                       R1_PHD_CTL3         ;  // 0x0374    R/W  Default Val : 0x00000000
        tR1_PHD_CTL4_t                       R1_PHD_CTL4         ;  // 0x0378    R/W  Default Val : 0x00000000
        tR1_PHD_ST1_t                        R1_PHD_ST1          ;  // 0x037C    R    Default Val : 0x00000000
        tR1_PHD_ST2_t                        R1_PHD_ST2          ;  // 0x0380    R    Default Val : 0x00000000
        tR1_PHD_SENSE_CTL1_t                 R1_PHD_SENSE_CTL1   ;  // 0x0384    R/W  Default Val : 0x00002A01
        tR1_ADC_SENSE_CTL_t                  R1_ADC_SENSE_CTL    ;  // 0x0388    R/W  Default Val : 0x015036D5
        tR1_PDB_CTL_t                        R1_PDB_CTL          ;  // 0x038C    R/W  Default Val : 0x00000060
        tR1_PDB_PHD_CTL_t                    R1_PDB_PHD_CTL      ;  // 0x0390    R/W  Default Val : 0x00000000
        tR1_RESERVE_t                        R1_RESERVE          ;  // 0x0394    R/W  Default Val : 0x00000000
        tR1_AFE_SENSE_CTL1_t                 R1_AFE_SENSE_CTL1   ;  // 0x0398    R/W  Default Val : 0x003FC920
        tR1_AFE_SENSE_CTL2_t                 R1_AFE_SENSE_CTL2   ;  // 0x039C    R/W  Default Val : 0x001FFFFF
        tR1_AFE_SENSE_CTL3_t                 R1_AFE_SENSE_CTL3   ;  // 0x03A0    R/W  Default Val : 0x00249249
        tR1_VCOMR_OPT_t                      R1_VCOMR_OPT        ;  // 0x03A4    R/W  Default Val : 0x00000000
        tR1_BUF_OPT_t                        R1_BUF_OPT          ;  // 0x03A8    R/W  Default Val : 0x00000003
        tR1_TG_STUCK_t                       R1_TG_STUCK         ;  // 0x03AC    R/W  Default Val : 0x00000000
        tR1_ADC_IN_CTL_t                     R1_ADC_IN_CTL       ;  // 0x03B0    R/W  Default Val : 0x00000000
        tR1_UPLINK_MUX_t                     R1_UPLINK_MUX       ;  // 0x03B4    R/W  Default Val : 0x00000000
        tR1_LHB_MUX_CTL_t                    R1_LHB_MUX_CTL      ;  // 0x03B8    R/W  Default Val : 0x3FFFFFFF
        tR1_TEST_MUX_CTL_t                   R1_TEST_MUX_CTL     ;  // 0x03BC    R/W  Default Val : 0x00000000
        tAPEN_CFCLK_ON_t                     APEN_CFCLK_ON       ;  // 0x07F0    R/W  Default Val : 0x00000001
        tMON_CAL_DELAY_t                     MON_CAL_DELAY       ;  // 0x07F4    R    Default Val : 0x00000000
        tMON_EDGE_SIGN_R0_t                  MON_EDGE_SIGN_R0    ;  // 0x07F8    R    Default Val : 0x00000000
        tMON_EDGE_SIGN_R1_t                  MON_EDGE_SIGN_R1    ;  // 0x07FC    R    Default Val : 0x00000000
} __PACKED tModuleSRICCommonConf_t;

typedef struct
{
		tPWM_FIG_CTL_t                       PWM_FIG_CTL         ;  // 0x0034    R/W  Default Val : 0x0001C086
		tPWM_POS_CTL_t                       PWM_POS_CTL         ;  // 0x0038    R/W  Default Val : 0x001C0860
		tPWM_DAT_CTL_t                       PWM_DAT_CTL         ;  // 0x003C    R/W  Default Val : 0x0E043060
		tPWM_ND_CTL_t                        PWM_ND_CTL          ;  // 0x0040    R/W  Default Val : 0x001C0860
		tPWM_PRD_t                           PWM_PRD             ;  // 0x0044    R/W  Default Val : 0x002E2E2E
        tSMPL_CTL_t                          SMPL_CTL            ;  // 0x0048    R/W  Default Val : 0x0001C387
        tRSTP_RISE_NUM_t                     RSTP_RISE_NUM       ;  // 0x004C    R/W  Default Val : 0x000E0E0E
        tRSTP_FALL_NUM1_t                    RSTP_FALL_NUM1      ;  // 0x0050    R/W  Default Val : 0x00030303
        tRSTP_FALL_NUM2_t                    RSTP_FALL_NUM2      ;  // 0x0054    R/W  Default Val : 0x00030303
        tPHTCR_RISE_NUM_t                    PHTCR_RISE_NUM      ;  // 0x0058    R/W  Default Val : 0x002C2C2C
        tPHTCR_FALL_NUM_t                    PHTCR_FALL_NUM      ;  // 0x005C    R/W  Default Val : 0x001E1E1E
        tVCR_NUM_t                           VCR_NUM             ;  // 0x0060    R/W  Default Val : 0x00282828
        tRSTI_RISE_NUM_t                     RSTI_RISE_NUM       ;  // 0x0064    R/W  Default Val : 0x000F0F0F
        tRSTI_FALL_NUM1_t                    RSTI_FALL_NUM1      ;  // 0x0068    R/W  Default Val : 0x001E1E1E
        tRSTI_FALL_NUM2_t                    RSTI_FALL_NUM2      ;  // 0x006C    R/W  Default Val : 0x00030303
        tPHTH0_RISE_NUM_t                    PHTH0_RISE_NUM      ;  // 0x0070    R/W  Default Val : 0x001E1E1E
        tPHTH0_FALL_NUM_t                    PHTH0_FALL_NUM      ;  // 0x0074    R/W  Default Val : 0x00141414
        tPHTH1_RISE_NUM_t                    PHTH1_RISE_NUM      ;  // 0x0078    R/W  Default Val : 0x00111111
        tPHTH1_FALL_NUM_t                    PHTH1_FALL_NUM      ;  // 0x007C    R/W  Default Val : 0x001E1E1E
        tPHT_CTL_t                           PHT_CTL             ;  // 0x0080    R/W  Default Val : 0x00022906
        tPHT_RISE_NUM_t                      PHT_RISE_NUM        ;  // 0x0084    R/W  Default Val : 0x00171717
        tPHT_FALL_NUM_t                      PHT_FALL_NUM        ;  // 0x0088    R/W  Default Val : 0x00111111
		tMUX_FCTL_NUM1_t                     MUX_FCTL_NUM1       ;  // 0x00C4    R/W  Default Val : 0x00000000
        tMUX_FCTL_NUM2_t                     MUX_FCTL_NUM2       ;  // 0x00C8    R/W  Default Val : 0x00000000
} __PACKED tSW92510_AFEReg_CFG_t;

typedef struct
{
		tR0_CR_R1G_MUX1_2_t                  R0_CR_R1G_MUX1_2[6] ;  // 0x0214    R/W  Default Val : 0x00000000
        tR0_CR_R2G_MUX1_2_t                  R0_CR_R2G_MUX1_2[6] ;  // 0x0218    R/W  Default Val : 0x00000000
        tR0_CR_R3G_MUX1_2_t                  R0_CR_R3G_MUX1_2[6] ;  // 0x021C    R/W  Default Val : 0x00000000
        tR0_CR_R1G_MUX3_4_t                  R0_CR_R1G_MUX3_4[6] ;  // 0x0220    R/W  Default Val : 0x00000000
        tR0_CR_R2G_MUX3_4_t                  R0_CR_R2G_MUX3_4[6] ;  // 0x0224    R/W  Default Val : 0x00000000
        tR0_CR_R3G_MUX3_4_t                  R0_CR_R3G_MUX3_4[6] ;  // 0x0228    R/W  Default Val : 0x00000000
        tR0_CR_R1G_MUX5_6_t                  R0_CR_R1G_MUX5_6[6] ;  // 0x022C    R/W  Default Val : 0x00000000
        tR0_CR_R2G_MUX5_6_t                  R0_CR_R2G_MUX5_6[6] ;  // 0x0230    R/W  Default Val : 0x00000000
        tR0_CR_R3G_MUX5_6_t                  R0_CR_R3G_MUX5_6[6] ;  // 0x0234    R/W  Default Val : 0x00000000
        tR0_CR_R1G_MUX7_8_t                  R0_CR_R1G_MUX7_8[6] ;  // 0x0238    R/W  Default Val : 0x00000000
        tR0_CR_R2G_MUX7_8_t                  R0_CR_R2G_MUX7_8[6] ;  // 0x023C    R/W  Default Val : 0x00000000
        tR0_CR_R3G_MUX7_8_t                  R0_CR_R3G_MUX7_8[6] ;  // 0x0240    R/W  Default Val : 0x00000000
        tR0_CR_R1G_MUX9_10_t                 R0_CR_R1G_MUX9_10[6];  // 0x0244    R/W  Default Val : 0x00000000
        tR0_CR_R2G_MUX9_10_t                 R0_CR_R2G_MUX9_10[6];  // 0x0248    R/W  Default Val : 0x00000000
        tR0_CR_R3G_MUX9_10_t                 R0_CR_R3G_MUX9_10[6];  // 0x024C    R/W  Default Val : 0x00000000

		tR1_CR_R1G_MUX1_2_t                  R1_CR_R1G_MUX1_2[6] ;  // 0x0314    R/W  Default Val : 0x00000000
        tR1_CR_R2G_MUX1_2_t                  R1_CR_R2G_MUX1_2[6] ;  // 0x0318    R/W  Default Val : 0x00000000
        tR1_CR_R3G_MUX1_2_t                  R1_CR_R3G_MUX1_2[6] ;  // 0x031C    R/W  Default Val : 0x00000000
        tR1_CR_R1G_MUX3_4_t                  R1_CR_R1G_MUX3_4[6] ;  // 0x0320    R/W  Default Val : 0x00000000
        tR1_CR_R2G_MUX3_4_t                  R1_CR_R2G_MUX3_4[6] ;  // 0x0324    R/W  Default Val : 0x00000000
        tR1_CR_R3G_MUX3_4_t                  R1_CR_R3G_MUX3_4[6] ;  // 0x0328    R/W  Default Val : 0x00000000
        tR1_CR_R1G_MUX5_6_t                  R1_CR_R1G_MUX5_6[6] ;  // 0x032C    R/W  Default Val : 0x00000000
        tR1_CR_R2G_MUX5_6_t                  R1_CR_R2G_MUX5_6[6] ;  // 0x0330    R/W  Default Val : 0x00000000
        tR1_CR_R3G_MUX5_6_t                  R1_CR_R3G_MUX5_6[6] ;  // 0x0334    R/W  Default Val : 0x00000000
        tR1_CR_R1G_MUX7_8_t                  R1_CR_R1G_MUX7_8[6] ;  // 0x0338    R/W  Default Val : 0x00000000
        tR1_CR_R2G_MUX7_8_t                  R1_CR_R2G_MUX7_8[6] ;  // 0x033C    R/W  Default Val : 0x00000000
        tR1_CR_R3G_MUX7_8_t                  R1_CR_R3G_MUX7_8[6] ;  // 0x0340    R/W  Default Val : 0x00000000
        tR1_CR_R1G_MUX9_10_t                 R1_CR_R1G_MUX9_10[6];  // 0x0344    R/W  Default Val : 0x00000000
        tR1_CR_R2G_MUX9_10_t                 R1_CR_R2G_MUX9_10[6];  // 0x0348    R/W  Default Val : 0x00000000
        tR1_CR_R3G_MUX9_10_t                 R1_CR_R3G_MUX9_10[6];  // 0x034C    R/W  Default Val : 0x00000000
} __PACKED tSW92510_CRReg_CFG_t;

#include "_sw92510_parampreset.h" 

#endif /* (USED_ROIC_DEF == ROIC_SW92510) */

#endif /* __SW92510_CONF_H_ */ 

