/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _sw92502_conf.h
 * created on : 10. 3. 2019
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

#ifndef __SW92502_CONF_H_
#define __SW92502_CONF_H_


#if (USED_ROIC_DEF == ROIC_SW92502)

typedef union
{
    struct {
        unsigned    device_id:				16;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_DEVICE_ID_t;

typedef union
{
    struct {
        unsigned    r0_rev_id:                 2;
        unsigned    r1_rev_id:                 2;
        unsigned    RESERVED:                  12;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_REV_ID_t;

typedef union
{
    struct {
        unsigned    scan_start:               1;
        unsigned    tg_clk_on:               1;
        unsigned    buf_clk_on:               1;
        unsigned    RESERVED0:               1;
        unsigned    tg_reset:               1;
        unsigned    sw_reset:               1;
        unsigned    mcnt_reset:               1;
        unsigned    RESERVED1:                  9;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_SYS_CFG_t;

typedef union
{
    struct {
        unsigned    lhb_type:               3;
        unsigned    RESERVED0:               1;
        unsigned    local_position1:         6;
        unsigned    local_position2:         6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PEN_POS1_t;

typedef union
{
    struct {
        unsigned    local_position3:               6;
        unsigned    local_position4:               6;
        unsigned    RESERVED:                  4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PEN_POS2_t;

typedef union
{
    struct {
        unsigned    sdic_lcd_off:               1;
        unsigned    sdic_lfd_float_r0:               1;
        unsigned    sdic_lfd_float_r1:               1;
        unsigned    sdic_gnd_r0:               1;
        unsigned    sdic_gnd_r1:               1;
        unsigned    tsync_in_pol:               1;
        unsigned    pwm_pol:               1;
        unsigned    cfg_2mux_short:               4;
        unsigned    half_pwm_en:               1;
        unsigned    tsync2_en:               1;
        unsigned    tsync2_in_pol:               1;
        unsigned    adc_stc_insel:               1;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_SDIC_CFG_t;

typedef union
{
    struct {
        unsigned    adc_op_opt0:               1;
        unsigned    adc_op_opt1:               1;
        unsigned    adc_clk_opt:               1;
        unsigned    adc_clk_div_f:               2;
        unsigned    adc_clk_div_p:               2;
        unsigned    adc_stc_dly:               5;
        unsigned    adc_in_pos:               4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_ADC_CFG_t;

typedef union
{
    struct {
        unsigned    pwr_lv_bias:               2;
        unsigned    pwr_hv_bias:               2;
        unsigned    pwr_adc:               2;
        unsigned    pwr_bgr:               2;
        unsigned    ch_dum_drv_en_0:               2;
        unsigned    ch_dum_drv_en_1:               2;
        unsigned    lvr_pwr_opt:               2;
        unsigned    hvr_pwr_opt:               2;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PWR_CFG1_t;

typedef union
{
    struct {
        unsigned    r0_pwr_ch_lv:               7;
        unsigned    r0_pwr_ch_hv:               9;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PWR_CFG2_t;

typedef union
{
    struct {
        unsigned    r1_pwr_ch_lv:               7;
        unsigned    r1_pwr_ch_hv:               9;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PWR_CFG3_t;

typedef union
{
    struct {
        unsigned    chip0_len:               8;
        unsigned    double_buf_en:               1;
        unsigned    pad_ds_miso:               1;
        unsigned    irq_en:               1;
        unsigned    sel_raw_bufd:               1;
        unsigned    RESERVED:                  4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_SPI_CFG_t;

typedef union
{
    struct {
        unsigned    pwm_prd1:               8;
        unsigned    pwm_prd2:               8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PWM_PRD1_t;

typedef union
{
    struct {
        unsigned    pwm_prd3:               8;
        unsigned    RESERVED:                  8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PWM_PRD2_t;

typedef union
{
    struct {
        unsigned    smop_prd1:               7;
        unsigned    crrpt_num_1:               3;
        unsigned    crrpt_num_2:               3;
        unsigned    RESERVED:                  3;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_SMPL_CTL1_t;

typedef union
{
    struct {
        unsigned    rstp_num1:               8;
        unsigned    rstp_num2:               8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_RSTP_NUM1_t;

typedef union
{
    struct {
        unsigned    phtcr_num1:               8;
        unsigned    phtcr_num2:               8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHTCR_NUM1_t;

typedef union
{
    struct {
        unsigned    vcr_num1:               8;
        unsigned    vcr_inv:               1;
        unsigned    vcr_en_off:               1;
        unsigned    RESERVED:                  6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_VCR_NUM1_t;

typedef union
{
    struct {
        unsigned    vcr_en_num1:               8;
        unsigned    vcr_en_num2:               8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_VCR_EN_NUM1_t;

typedef union
{
    struct {
        unsigned    phth0_num1:               8;
        unsigned    phth0_num2:               8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHTH0_NUM1_t;

typedef union
{
    struct {
        unsigned    phth1_num1:               8;
        unsigned    phth1_num2:               8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHTH1_NUM1_t;

typedef union
{
    struct {
        unsigned    rsti_num1:               8;
        unsigned    rsti_num2:               8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_RSTI_NUM1_t;

typedef union
{
    struct {
        unsigned    rsti_num3:               8;
        unsigned    pht_etime:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHT_ETIME1_t;

typedef union
{
    struct {
        unsigned    pht_prd:              8;
        unsigned    pht_opt_smp:              1;
        unsigned    pht_opt_inv:              1;
        unsigned    RESERVED_t:                  6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHT_CTL1_t;

typedef union
{
    struct {
        unsigned    pht_num1:              8;
        unsigned    pht_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHT_NUM1_t;

typedef union
{
    struct {
        unsigned    smop_prd1:              7;
        unsigned    crrpt_num_1:              3;
        unsigned    crrpt_num_2:              3;
        unsigned    RESERVED:                  3;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_SMPL_CTL2_t;

typedef union
{
    struct {
        unsigned    rstp_num1:              8;
        unsigned    rstp_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_RSTP_NUM2_t;

typedef union
{
    struct {
        unsigned    phtcr_num1:              8;
        unsigned    phtcr_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHTCR_NUM2_t;

typedef union
{
    struct {
        unsigned    vcr_num1:              8;
        unsigned    vcr_inv_p:              1;
        unsigned    vcr_inv_d:              1;
        unsigned    vcr_en_off_p:              1;
        unsigned    vcr_en_off_d:              1;
        unsigned    RESERVED:                  4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_VCR_NUM2_t;

typedef union
{
    struct {
        unsigned    vcr_en_num1:              8;
        unsigned    vcr_en_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_VCR_EN_NUM2_t;

typedef union
{
    struct {
        unsigned    phth0_num1:              8;
        unsigned    phth0_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHTH0_NUM2_t;

typedef union
{
    struct {
        unsigned    phth1_num1:              8;
        unsigned    phth1_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHTH1_NUM2_t;

typedef union
{
    struct {
        unsigned    rsti_num1:              8;
        unsigned    rsti_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_RSTI_NUM2_t;

typedef union
{
    struct {
        unsigned    rsti_num3:              8;
        unsigned    pht_etime:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHT_ETIME2_t;

typedef union
{
    struct {
        unsigned    pht_prd:              8;
        unsigned    pht_opt_smp:              1;
        unsigned    pht_opt_inv:              1;
        unsigned    RESERVED:                  6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHT_CTL2_t;

typedef union
{
    struct {
        unsigned    pht_num1:              8;
        unsigned    pht_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHT_NUM2_t;

typedef union
{
    struct {
        unsigned    smop_prd1:              7;
        unsigned    crrpt_num_1:              3;
        unsigned    crrpt_num_2:              3;
        unsigned    RESERVED:                  3;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_SMPL_CTL3_t;

typedef union
{
    struct {
        unsigned    rstp_num1:              8;
        unsigned    rstp_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_RSTP_NUM3_t;

typedef union
{
    struct {
        unsigned    phtcr_num1:              8;
        unsigned    phtcr_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHTCR_NUM3_t;

typedef union
{
    struct {
        unsigned    vcr_num1:              8;
        unsigned    vcr_inv:              1;
        unsigned    vcr_en_off:              1;
        unsigned    RESERVED:                  6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_VCR_NUM3_t;

typedef union
{
    struct {
        unsigned    vcr_en_num1:              8;
        unsigned    vcr_en_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_VCR_EN_NUM3_t;

typedef union
{
    struct {
        unsigned    phth0_num1:              8;
        unsigned    phth0_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHTH0_NUM3_t;

typedef union
{
    struct {
        unsigned    phth1_num1:              8;
        unsigned    phth1_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHTH1_NUM3_t;

typedef union
{
    struct {
        unsigned    rsti_num1:              8;
        unsigned    rsti_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_RSTI_NUM3_t;

typedef union
{
    struct {
        unsigned    rsti_num3:              8;
        unsigned    pht_etime:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHT_ETIME3_t;

typedef union
{
    struct {
        unsigned    pht_prd:              8;
        unsigned    pht_opt_smp:              1;
        unsigned    pht_opt_inv:              1;
        unsigned    RESERVED:                  6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHT_CTL3_t;

typedef union
{
    struct {
        unsigned    pht_num1:              8;
        unsigned    pht_num2:              8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_PHT_NUM3_t;

typedef union
{
    struct {
        unsigned    half_copy_dat:              1;
        unsigned    half_copy_pos:              1;
        unsigned    partial_pos_opt1:              1;
        unsigned    partial_pos1:              6;
        unsigned    partial_pos_opt2:              1;
        unsigned    partial_pos2:              6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_HALF_COPY_t;

typedef union
{
    struct {
        unsigned    stuck_rstp:              2;
        unsigned    stuck_phtcr:              2;
        unsigned    stuck_vcr:              2;
        unsigned    stuck_rsti:              2;
        unsigned    stuck_phth0:              2;
        unsigned    stuck_phth1:              2;
        unsigned    stuck_pht0:              2;
        unsigned    stuck_pht1:              2;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_TEST_OPT1_t;

typedef union
{
    struct {
        unsigned    stuck_vcren_odd:              2;
        unsigned    stuck_vcren_even:              2;
        unsigned    pow_sel:              1;
        unsigned    display_vcomr:              2;
        unsigned    touch_vcomr:              2;
        unsigned    uplink_vcomr:              2;
        unsigned    stuck_enable:              1;
        unsigned    stuck_level:              1;
        unsigned    tsync_opt:              1;
        unsigned    muxs_ctl_en:              1;
        unsigned    muxf_ctl_en:              1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_TEST_OPT2_t;

typedef union
{
    struct {
        unsigned    muxs_ctl_bit:              12;
        unsigned    mux_int_sel:              4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_TEST_OPT3_t;

typedef union
{
    struct {
        unsigned    muxf_ctl_bit:              12;
        unsigned    RESERVED:                  4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_TEST_OPT4_t;

typedef union
{
    struct {
        unsigned    mx_order_01:              4;
        unsigned    mx_order_02:              4;
        unsigned    mx_order_03:              4;
        unsigned    mx_order_04:              4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_CMUX_REMAP1_t;

typedef union
{
    struct {
        unsigned    mx_order_05:              4;
        unsigned    mx_order_06:              4;
        unsigned    mx_order_07:              4;
        unsigned    mx_order_08:              4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_CMUX_REMAP2_t;

typedef union
{
    struct {
        unsigned    mx_order_09:              4;
        unsigned    mx_order_10:              4;
        unsigned    mx_order_11:              4;
        unsigned    mx_order_12:              4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_CMUX_REMAP3_t;

typedef union
{
    struct {
        unsigned    RESERVED0:              16;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_RSV_0_t;

typedef union
{
    struct {
        unsigned    md1_lhb_mux:              4;
        unsigned    md2_lhb_mux:              4;
        unsigned    md3_lhb_mux:              4;
        unsigned    RESERVED:                  4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_LHB_CFG1_t;

typedef union
{
    struct {
        unsigned    md5_lhb_mux:              4;
        unsigned    md6_lhb_mux:              4;
        unsigned    end_mux_num:              4;
        unsigned    RESERVED:                  4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_LHB_CFG2_t;

typedef union
{
    struct {
        unsigned    mux_cfg_en:              1;
        unsigned    mux_cfg_bit1:              12;
        unsigned    RESERVED:                  3;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD1_MUX_CFG_t;

typedef union
{
    struct {
        unsigned    pre_pwm:              4;
        unsigned    set_pwm_en:              1;
        unsigned    act_pwm:              5;
        unsigned    RESERVED:                  6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD1_PWM_CFG_t;

typedef union
{
    struct {
        unsigned    bcon_pre:              3;
        unsigned    pre_bs_lp:              1;
        unsigned    bcon_int:              3;
        unsigned    int_bs_lp:              1;
        unsigned    bcon_sha:              3;
        unsigned    sha_bs_lp:              1;
        unsigned    bcon_adc:              2;
        unsigned    RESERVED:                  2;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD1_BCON_CFG_t;

typedef union
{
    struct {
        unsigned    pre_gc:              2;
        unsigned    int_gc:              2;
        unsigned    int_half:              1;
        unsigned    cr_g_tune:              2;
        unsigned    int_ref:              2;
        unsigned    sha_ref:              2;
        unsigned    RESERVED:                  5;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD1_AFE_CFG_t;

typedef union
{
    struct {
        unsigned    mux_cfg_en:              1;
        unsigned    mux_cfg_bit1:              12;
        unsigned    RESERVED:                  3;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD2_MUX_CFG_t;

typedef union
{
    struct {
        unsigned    pre_pwm:              4;
        unsigned    set_pwm_en:              1;
        unsigned    act_pwm:              5;
        unsigned    RESERVED:                  6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD2_PWM_CFG_t;

typedef union
{
    struct {
        unsigned    bcon_pre:              3;
        unsigned    pre_bs_lp:              1;
        unsigned    bcon_int:              3;
        unsigned    int_bs_lp:              1;
        unsigned    bcon_sha:              3;
        unsigned    sha_bs_lp:              1;
        unsigned    bcon_adc:              2;
        unsigned    RESERVED:                  2;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD2_BCON_CFG_t;

typedef union
{
    struct {
        unsigned    pre_gc:              2;
        unsigned    int_gc:              2;
        unsigned    int_half:              1;
        unsigned    cr_g_tune:              2;
        unsigned    int_ref:              2;
        unsigned    sha_ref:              2;
        unsigned    RESERVED:                  5;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD2_AFE_CFG_t;

typedef union
{
    struct {
        unsigned    mux_cfg_bit1:              12;
        unsigned    RESERVED:                  4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD3_MUX_CFG1_t;

typedef union
{
    struct {
        unsigned    mux_cfg_bit2:              12;
        unsigned    RESERVED:                  4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD3_MUX_CFG2_t;

typedef union
{
    struct {
        unsigned    mux_cfg_bit3:              12;
        unsigned    RESERVED:                  4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD3_MUX_CFG3_t;

typedef union
{
    struct {
        unsigned    mux_cfg_bit4:              12;
        unsigned    RESERVED:                  4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD3_MUX_CFG4_t;

typedef union
{
    struct {
        unsigned    pre_pwm:              4;
        unsigned    set_pwm_en:              1;
        unsigned    act_pwm:              5;
        unsigned    RESERVED:                  6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD3_PWM_CFG_t;

typedef union
{
    struct {
        unsigned    bcon_pre:              3;
        unsigned    pre_bs_lp:              1;
        unsigned    bcon_int:              3;
        unsigned    int_bs_lp:              1;
        unsigned    bcon_sha:              3;
        unsigned    sha_bs_lp:              1;
        unsigned    bcon_adc:              2;
        unsigned    RESERVED:                  2;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD3_BCON_CFG_t;

typedef union
{
    struct {
        unsigned    pre_gc:              2;
        unsigned    int_gc:              2;
        unsigned    int_half:              1;
        unsigned    cr_g_tune:              2;
        unsigned    int_ref:              2;
        unsigned    sha_ref:              2;
        unsigned    RESERVED:                  5;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD3_AFE_CFG_t;

typedef union
{
    struct {
        unsigned    pre_pwm:              4;
        unsigned    set_pwm_en:              1;
        unsigned    act_pwm:              5;
        unsigned    RESERVED:                  6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD5_PWM_CFG_t;

typedef union
{
    struct {
        unsigned    bcon_pre:              3;
        unsigned    pre_bs_lp:              1;
        unsigned    bcon_int:              3;
        unsigned    int_bs_lp:              1;
        unsigned    bcon_sha:              3;
        unsigned    sha_bs_lp:              1;
        unsigned    bcon_adc:              2;
        unsigned    RESERVED:                  2;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD5_BCON_CFG_t;

typedef union
{
    struct {
        unsigned    pre_gc:              2;
        unsigned    int_gc:              2;
        unsigned    int_half:              1;
        unsigned    cr_g_tune:              2;
        unsigned    int_ref:              2;
        unsigned    sha_ref:              2;
        unsigned    RESERVED:                  5;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD5_AFE_CFG_t;

typedef union
{
    struct {
        unsigned    pre_pwm:              4;
        unsigned    set_pwm_en:              1;
        unsigned    act_pwm:              5;
        unsigned    RESERVED:                  6;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_MD6_PWM_CFG_t;

typedef union
{
    struct {
        unsigned    cr_group_r0:              1;
        unsigned    cr_group_r1:              1;
        unsigned    r0_cr_sel_c0:              2;
        unsigned    r0_cr_sel_c1:              2;
        unsigned    r0_cr_sel_c2:              2;
        unsigned    r1_cr_sel_c0:              2;
        unsigned    r1_cr_sel_c1:              2;
        unsigned    r1_cr_sel_c2:              2;
        unsigned    RESERVED:                  2;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_CR_SEL_t;

typedef union
{
    struct {
        unsigned    md1_crt_mx1_g1:              5;
        unsigned    md1_crt_mx1_g2:              5;
        unsigned    md1_crt_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CRT_MX1_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx1_g1:              5;
        unsigned    md1_cr_mx1_g2:              5;
        unsigned    md1_cr_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX1_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx2_g1:              5;
        unsigned    md1_cr_mx2_g2:              5;
        unsigned    md1_cr_mx2_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX2_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx3_g1:              5;
        unsigned    md1_cr_mx3_g2:              5;
        unsigned    md1_cr_mx3_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX3_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx4_g1:              5;
        unsigned    md1_cr_mx4_g2:              5;
        unsigned    md1_cr_mx4_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX4_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx5_g1:              5;
        unsigned    md1_cr_mx5_g2:              5;
        unsigned    md1_cr_mx5_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX5_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx6_g1:              5;
        unsigned    md1_cr_mx6_g2:              5;
        unsigned    md1_cr_mx6_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX6_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx7_g1:              5;
        unsigned    md1_cr_mx7_g2:              5;
        unsigned    md1_cr_mx7_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX7_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx8_g1:              5;
        unsigned    md1_cr_mx8_g2:              5;
        unsigned    md1_cr_mx8_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX8_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx9_g1:              5;
        unsigned    md1_cr_mx9_g2:              5;
        unsigned    md1_cr_mx9_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX9_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx10_g1:              5;
        unsigned    md1_cr_mx10_g2:              5;
        unsigned    md1_cr_mx10_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX10_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx11_g1:              5;
        unsigned    md1_cr_mx11_g2:              5;
        unsigned    md1_cr_mx11_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX11_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx12_g1:              5;
        unsigned    md1_cr_mx12_g2:              5;
        unsigned    md1_cr_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CR_MX12_t;

typedef union
{
    struct {
        unsigned    md1_crb_mx12_g1:              5;
        unsigned    md1_crb_mx12_g2:              5;
        unsigned    md1_crb_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD1_CRB_MX12_t;

typedef union
{
    struct {
        unsigned    md1_crt_mx1_g1:              5;
        unsigned    md1_crt_mx1_g2:              5;
        unsigned    md1_crt_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CRT_MX1_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx1_g1:              5;
        unsigned    md1_cr_mx1_g2:              5;
        unsigned    md1_cr_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX1_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx2_g1:              5;
        unsigned    md1_cr_mx2_g2:              5;
        unsigned    md1_cr_mx2_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX2_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx3_g1:              5;
        unsigned    md1_cr_mx3_g2:              5;
        unsigned    md1_cr_mx3_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX3_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx4_g1:              5;
        unsigned    md1_cr_mx4_g2:              5;
        unsigned    md1_cr_mx4_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX4_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx5_g1:              5;
        unsigned    md1_cr_mx5_g2:              5;
        unsigned    md1_cr_mx5_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX5_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx6_g1:              5;
        unsigned    md1_cr_mx6_g2:              5;
        unsigned    md1_cr_mx6_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX6_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx7_g1:              5;
        unsigned    md1_cr_mx7_g2:              5;
        unsigned    md1_cr_mx7_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX7_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx8_g1:              5;
        unsigned    md1_cr_mx8_g2:              5;
        unsigned    md1_cr_mx8_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX8_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx9_g1:              5;
        unsigned    md1_cr_mx9_g2:              5;
        unsigned    md1_cr_mx9_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX9_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx10_g1:              5;
        unsigned    md1_cr_mx10_g2:              5;
        unsigned    md1_cr_mx10_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX10_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx11_g1:              5;
        unsigned    md1_cr_mx11_g2:              5;
        unsigned    md1_cr_mx11_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX11_t;

typedef union
{
    struct {
        unsigned    md1_cr_mx12_g1:              5;
        unsigned    md1_cr_mx12_g2:              5;
        unsigned    md1_cr_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CR_MX12_t;

typedef union
{
    struct {
        unsigned    md1_crb_mx12_g1:              5;
        unsigned    md1_crb_mx12_g2:              5;
        unsigned    md1_crb_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD1_CRB_MX12_t;

typedef union
{
    struct {
        unsigned    md2_crt_mx1_g1:              5;
        unsigned    md2_crt_mx1_g2:              5;
        unsigned    md2_crt_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CRT_MX1_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx1_g1:              5;
        unsigned    md2_cr_mx1_g2:              5;
        unsigned    md2_cr_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX1_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx2_g1:              5;
        unsigned    md2_cr_mx2_g2:              5;
        unsigned    md2_cr_mx2_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX2_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx3_g1:              5;
        unsigned    md2_cr_mx3_g2:              5;
        unsigned    md2_cr_mx3_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX3_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx4_g1:              5;
        unsigned    md2_cr_mx4_g2:              5;
        unsigned    md2_cr_mx4_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX4_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx5_g1:              5;
        unsigned    md2_cr_mx5_g2:              5;
        unsigned    md2_cr_mx5_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX5_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx6_g1:              5;
        unsigned    md2_cr_mx6_g2:              5;
        unsigned    md2_cr_mx6_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX6_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx7_g1:              5;
        unsigned    md2_cr_mx7_g2:              5;
        unsigned    md2_cr_mx7_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX7_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx8_g1:              5;
        unsigned    md2_cr_mx8_g2:              5;
        unsigned    md2_cr_mx8_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX8_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx9_g1:              5;
        unsigned    md2_cr_mx9_g2:              5;
        unsigned    md2_cr_mx9_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX9_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx10_g1:              5;
        unsigned    md2_cr_mx10_g2:              5;
        unsigned    md2_cr_mx10_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX10_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx11_g1:              5;
        unsigned    md2_cr_mx11_g2:              5;
        unsigned    md2_cr_mx11_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX11_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx12_g1:              5;
        unsigned    md2_cr_mx12_g2:              5;
        unsigned    md2_cr_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CR_MX12_t;

typedef union
{
    struct {
        unsigned    md2_crb_mx12_g1:              5;
        unsigned    md2_crb_mx12_g2:              5;
        unsigned    md2_crb_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD2_CRB_MX12_t;

typedef union
{
    struct {
        unsigned    md2_crt_mx1_g1:              5;
        unsigned    md2_crt_mx1_g2:              5;
        unsigned    md2_crt_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CRT_MX1_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx1_g1:              5;
        unsigned    md2_cr_mx1_g2:              5;
        unsigned    md2_cr_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX1_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx2_g1:              5;
        unsigned    md2_cr_mx2_g2:              5;
        unsigned    md2_cr_mx2_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX2_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx3_g1:              5;
        unsigned    md2_cr_mx3_g2:              5;
        unsigned    md2_cr_mx3_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX3_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx4_g1:              5;
        unsigned    md2_cr_mx4_g2:              5;
        unsigned    md2_cr_mx4_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX4_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx5_g1:              5;
        unsigned    md2_cr_mx5_g2:              5;
        unsigned    md2_cr_mx5_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX5_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx6_g1:              5;
        unsigned    md2_cr_mx6_g2:              5;
        unsigned    md2_cr_mx6_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX6_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx7_g1:              5;
        unsigned    md2_cr_mx7_g2:              5;
        unsigned    md2_cr_mx7_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX7_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx8_g1:              5;
        unsigned    md2_cr_mx8_g2:              5;
        unsigned    md2_cr_mx8_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX8_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx9_g1:              5;
        unsigned    md2_cr_mx9_g2:              5;
        unsigned    md2_cr_mx9_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX9_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx10_g1:              5;
        unsigned    md2_cr_mx10_g2:              5;
        unsigned    md2_cr_mx10_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX10_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx11_g1:              5;
        unsigned    md2_cr_mx11_g2:              5;
        unsigned    md2_cr_mx11_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX11_t;

typedef union
{
    struct {
        unsigned    md2_cr_mx12_g1:              5;
        unsigned    md2_cr_mx12_g2:              5;
        unsigned    md2_cr_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CR_MX12_t;

typedef union
{
    struct {
        unsigned    md2_crb_mx12_g1:              5;
        unsigned    md2_crb_mx12_g2:              5;
        unsigned    md2_crb_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD2_CRB_MX12_t;

typedef union
{
    struct {
        unsigned    md3_crt_mx1_g1:              5;
        unsigned    md3_crt_mx1_g2:              5;
        unsigned    md3_crt_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD3_CRT_MX1_t;

typedef union
{
    struct {
        unsigned    md3_cr_mx1_g1:              5;
        unsigned    md3_cr_mx1_g2:              5;
        unsigned    md3_cr_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD3_CR_MX1_t;

typedef union
{
    struct {
        unsigned    md3_cr_mx2_g1:              5;
        unsigned    md3_cr_mx2_g2:              5;
        unsigned    md3_cr_mx2_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD3_CR_MX2_t;

typedef union
{
    struct {
        unsigned    md3_cr_mx3_g1:              5;
        unsigned    md3_cr_mx3_g2:              5;
        unsigned    md3_cr_mx3_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD3_CR_MX3_t;

typedef union
{
    struct {
        unsigned    md3_cr_mx4_g1:              5;
        unsigned    md3_cr_mx4_g2:              5;
        unsigned    md3_cr_mx4_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD3_CR_MX4_t;

typedef union
{
    struct {
        unsigned    md3_crt_mx1_g1:              5;
        unsigned    md3_crt_mx1_g2:              5;
        unsigned    md3_crt_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD3_CRT_MX1_t;

typedef union
{
    struct {
        unsigned    md3_cr_mx1_g1:              5;
        unsigned    md3_cr_mx1_g2:              5;
        unsigned    md3_cr_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD3_CR_MX1_t;

typedef union
{
    struct {
        unsigned    md3_cr_mx2_g1:              5;
        unsigned    md3_cr_mx2_g2:              5;
        unsigned    md3_cr_mx2_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD3_CR_MX2_t;

typedef union
{
    struct {
        unsigned    md3_cr_mx3_g1:              5;
        unsigned    md3_cr_mx3_g2:              5;
        unsigned    md3_cr_mx3_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD3_CR_MX3_t;

typedef union
{
    struct {
        unsigned    md3_cr_mx4_g1:              5;
        unsigned    md3_cr_mx4_g2:              5;
        unsigned    md3_cr_mx4_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD3_CR_MX4_t;

typedef union
{
    struct {
        unsigned    md5_crt_mx1_g1:              5;
        unsigned    md5_crt_mx1_g2:              5;
        unsigned    md5_crt_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD5_CRT_MX1_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx1_g1:              5;
        unsigned    md5_cr_mx1_g2:              5;
        unsigned    md5_cr_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD5_CR_MX1_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx2_g1:              5;
        unsigned    md5_cr_mx2_g2:              5;
        unsigned    md5_cr_mx2_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD5_CR_MX2_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx3_g1:              5;
        unsigned    md5_cr_mx3_g2:              5;
        unsigned    md5_cr_mx3_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD5_CR_MX3_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx4_g1:              5;
        unsigned    md5_cr_mx4_g2:              5;
        unsigned    md5_cr_mx4_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD5_CR_MX4_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx5_g1:              5;
        unsigned    md5_cr_mx5_g2:              5;
        unsigned    md5_cr_mx5_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD5_CR_MX5_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx9_g1:              5;
        unsigned    md5_cr_mx9_g2:              5;
        unsigned    md5_cr_mx9_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD5_CR_MX9_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx10_g1:              5;
        unsigned    md5_cr_mx10_g2:              5;
        unsigned    md5_cr_mx10_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD5_CR_MX10_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx11_g1:              5;
        unsigned    md5_cr_mx11_g2:              5;
        unsigned    md5_cr_mx11_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD5_CR_MX11_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx12_g1:              5;
        unsigned    md5_cr_mx12_g2:              5;
        unsigned    md5_cr_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD5_CR_MX12_t;

typedef union
{
    struct {
        unsigned    md5_crb_mx12_g1:              5;
        unsigned    md5_crb_mx12_g2:              5;
        unsigned    md5_crb_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R0_MD5_CRB_MX12_t;

typedef union
{
    struct {
        unsigned    md5_crt_mx1_g1:              5;
        unsigned    md5_crt_mx1_g2:              5;
        unsigned    md5_crt_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD5_CRT_MX1_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx1_g1:              5;
        unsigned    md5_cr_mx1_g2:              5;
        unsigned    md5_cr_mx1_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD5_CR_MX1_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx2_g1:              5;
        unsigned    md5_cr_mx2_g2:              5;
        unsigned    md5_cr_mx2_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD5_CR_MX2_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx3_g1:              5;
        unsigned    md5_cr_mx3_g2:              5;
        unsigned    md5_cr_mx3_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD5_CR_MX3_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx4_g1:              5;
        unsigned    md5_cr_mx4_g2:              5;
        unsigned    md5_cr_mx4_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD5_CR_MX4_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx5_g1:              5;
        unsigned    md5_cr_mx5_g2:              5;
        unsigned    md5_cr_mx5_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD5_CR_MX5_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx9_g1:              5;
        unsigned    md5_cr_mx9_g2:              5;
        unsigned    md5_cr_mx9_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD5_CR_MX9_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx10_g1:              5;
        unsigned    md5_cr_mx10_g2:              5;
        unsigned    md5_cr_mx10_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD5_CR_MX10_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx11_g1:              5;
        unsigned    md5_cr_mx11_g2:              5;
        unsigned    md5_cr_mx11_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD5_CR_MX11_t;

typedef union
{
    struct {
        unsigned    md5_cr_mx12_g1:              5;
        unsigned    md5_cr_mx12_g2:              5;
        unsigned    md5_cr_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD5_CR_MX12_t;

typedef union
{
    struct {
        unsigned    md5_crb_mx12_g1:              5;
        unsigned    md5_crb_mx12_g2:              5;
        unsigned    md5_crb_mx12_g3:              5;
        unsigned    RESERVED:                  1;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_R1_MD5_CRB_MX12_t;

typedef union
{
    struct {
        unsigned    miso_func:              3;
        unsigned    gpo0_func:              3;
        unsigned    gpo1_func:              3;
        unsigned    RESERVED:                  7;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_GPO_FUNC_t;

typedef union
{
    struct {
        unsigned    nd_num:              4;
        unsigned    nd_en:              1;
        unsigned    RESERVED:                  11;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_ND_CTRL_t;

typedef union
{
    struct {
        unsigned    ch_en_num0:              6;
        unsigned    ch_en_num1:              6;
        unsigned    RESERVED:                  4;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_CH_EN_NUM_t;

typedef union
{
    struct {
        unsigned    r0_roic_rev:               4;
        unsigned    r1_roic_rev:               4;
        unsigned    RESERVED:                  8;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_ROIC_REV_t;

typedef union
{
    struct {
        unsigned    tsync_fault_clr:              1;
        unsigned    pwm_fault_clr:              1;
        unsigned    chksum_fault_clr:              1;
        unsigned    RESERVED:                  13;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_ERR_CLR_t;

typedef union
{
    struct {
        unsigned    tsync_fault:              1;
        unsigned    pwm_fault:              1;
        unsigned    chksum_fault:              1;
        unsigned    RESERVED:                  13;
    } __PACKED tBit;
    __IO uint16_t ulBulk;
} __PACKED tCFGR_ERR_STATUS_t;

typedef struct
{
    tCFGR_DEVICE_ID_t            CFGR_DEVICE_ID;                 //0x0000
    tCFGR_REV_ID_t               CFGR_REV_ID;                    //0x0001
    tCFGR_SYS_CFG_t              CFGR_SYS_CFG;                   //0x0002
    tCFGR_PEN_POS1_t             CFGR_PEN_POS1;                  //0x0003
    tCFGR_PEN_POS2_t             CFGR_PEN_POS2;                  //0x0004
    tCFGR_SDIC_CFG_t             CFGR_SDIC_CFG;                  //0x0005
    tCFGR_ADC_CFG_t              CFGR_ADC_CFG;                   //0x0006
    tCFGR_PWR_CFG1_t             CFGR_PWR_CFG1;                  //0x0007
    tCFGR_PWR_CFG2_t             CFGR_PWR_CFG2;                  //0x0008
    tCFGR_PWR_CFG3_t             CFGR_PWR_CFG3;                  //0x0009
    tCFGR_SPI_CFG_t              CFGR_SPI_CFG;                   //0x000A
    tCFGR_PWM_PRD1_t             CFGR_PWM_PRD1;                  //0x000B
    tCFGR_PWM_PRD2_t             CFGR_PWM_PRD2;                  //0x000C
    tCFGR_SMPL_CTL1_t            CFGR_SMPL_CTL1;                 //0x000D
    tCFGR_RSTP_NUM1_t            CFGR_RSTP_NUM1;                 //0x000E
    tCFGR_PHTCR_NUM1_t           CFGR_PHTCR_NUM1;                //0x000F
    tCFGR_VCR_NUM1_t             CFGR_VCR_NUM1;                  //0x0010
    tCFGR_VCR_EN_NUM1_t          CFGR_VCR_EN_NUM1;               //0x0011
    tCFGR_PHTH0_NUM1_t           CFGR_PHTH0_NUM1;                //0x0012
    tCFGR_PHTH1_NUM1_t           CFGR_PHTH1_NUM1;                //0x0013
    tCFGR_RSTI_NUM1_t            CFGR_RSTI_NUM1;                 //0x0014
    tCFGR_PHT_ETIME1_t           CFGR_PHT_ETIME1;                //0x0015
    tCFGR_PHT_CTL1_t             CFGR_PHT_CTL1;                  //0x0016
    tCFGR_PHT_NUM1_t             CFGR_PHT_NUM1;                  //0x0017
    tCFGR_SMPL_CTL2_t            CFGR_SMPL_CTL2;                 //0x0018
    tCFGR_RSTP_NUM2_t            CFGR_RSTP_NUM2;                 //0x0019
    tCFGR_PHTCR_NUM2_t           CFGR_PHTCR_NUM2;                //0x001A
    tCFGR_VCR_NUM2_t             CFGR_VCR_NUM2;                  //0x001B
    tCFGR_VCR_EN_NUM2_t          CFGR_VCR_EN_NUM2;               //0x001C
    tCFGR_PHTH0_NUM2_t           CFGR_PHTH0_NUM2;                //0x001D
    tCFGR_PHTH1_NUM2_t           CFGR_PHTH1_NUM2;                //0x001E
    tCFGR_RSTI_NUM2_t            CFGR_RSTI_NUM2;                 //0x001F
    tCFGR_PHT_ETIME2_t           CFGR_PHT_ETIME2;                //0x0020
    tCFGR_PHT_CTL2_t             CFGR_PHT_CTL2;                  //0x0021
    tCFGR_PHT_NUM2_t             CFGR_PHT_NUM2;                  //0x0022
    tCFGR_SMPL_CTL3_t            CFGR_SMPL_CTL3;                 //0x0023
    tCFGR_RSTP_NUM3_t            CFGR_RSTP_NUM3;                 //0x0024
    tCFGR_PHTCR_NUM3_t           CFGR_PHTCR_NUM3;                //0x0025
    tCFGR_VCR_NUM3_t             CFGR_VCR_NUM3;                  //0x0026
    tCFGR_VCR_EN_NUM3_t          CFGR_VCR_EN_NUM3;               //0x0027
    tCFGR_PHTH0_NUM3_t           CFGR_PHTH0_NUM3;                //0x0028
    tCFGR_PHTH1_NUM3_t           CFGR_PHTH1_NUM3;                //0x0029
    tCFGR_RSTI_NUM3_t            CFGR_RSTI_NUM3;                 //0x002A
    tCFGR_PHT_ETIME3_t           CFGR_PHT_ETIME3;                //0x002B
    tCFGR_PHT_CTL3_t             CFGR_PHT_CTL3;                  //0x002C
    tCFGR_PHT_NUM3_t             CFGR_PHT_NUM3;                  //0x002D
    tCFGR_HALF_COPY_t            CFGR_HALF_COPY;                 //0x002E
    tCFGR_TEST_OPT1_t            CFGR_TEST_OPT1;                 //0x002F
    tCFGR_TEST_OPT2_t            CFGR_TEST_OPT2;                 //0x0030
    tCFGR_TEST_OPT3_t            CFGR_TEST_OPT3;                 //0x0031
    tCFGR_TEST_OPT4_t            CFGR_TEST_OPT4;                 //0x0032
    tCFGR_CMUX_REMAP1_t          CFGR_CMUX_REMAP1;               //0x0033
    tCFGR_CMUX_REMAP2_t          CFGR_CMUX_REMAP2;               //0x0034
    tCFGR_CMUX_REMAP3_t          CFGR_CMUX_REMAP3;               //0x0035
    __IO uint16_t                CFGR_MD1_MUX_SEL1;              //0x0036
    __IO uint16_t                CFGR_MD1_MUX_SEL2;              //0x0037
    __IO uint16_t                CFGR_MD1_MUX_SEL3;              //0x0038
    __IO uint16_t                CFGR_MD1_MUX_SEL4;              //0x0039
    __IO uint16_t                CFGR_MD1_MUX_SEL5;              //0x003A
    __IO uint16_t                CFGR_MD1_MUX_SEL6;              //0x003B
    __IO uint16_t                CFGR_MD1_MUX_SEL7;              //0x003C
    __IO uint16_t                CFGR_MD1_MUX_SEL8;              //0x003D
    __IO uint16_t                CFGR_MD1_MUX_SEL9;              //0x003E
    __IO uint16_t                CFGR_MD1_MUX_SEL10;             //0x003F
    __IO uint16_t                CFGR_MD1_MUX_SEL11;             //0x0040
    __IO uint16_t                CFGR_MD1_MUX_SEL12;             //0x0041
    __IO uint16_t                CFGR_MD2_MUX_SEL1;              //0x0042
    __IO uint16_t                CFGR_MD2_MUX_SEL2;              //0x0043
    __IO uint16_t                CFGR_MD2_MUX_SEL3;              //0x0044
    __IO uint16_t                CFGR_MD2_MUX_SEL4;              //0x0045
    __IO uint16_t                CFGR_MD2_MUX_SEL5;              //0x0046
    __IO uint16_t                CFGR_MD2_MUX_SEL6;              //0x0047
    __IO uint16_t                CFGR_MD2_MUX_SEL7;              //0x0048
    __IO uint16_t                CFGR_MD2_MUX_SEL8;              //0x0049
    __IO uint16_t                CFGR_MD2_MUX_SEL9;              //0x004A
    __IO uint16_t                CFGR_MD2_MUX_SEL10;             //0x004B
    __IO uint16_t                CFGR_MD2_MUX_SEL11;             //0x004C
    __IO uint16_t                CFGR_MD2_MUX_SEL12;             //0x004D
    tCFGR_RSV_0_t                CFGR_RSV_0;                     //0x004E
    tCFGR_LHB_CFG1_t             CFGR_LHB_CFG1;                  //0x004F
    tCFGR_LHB_CFG2_t             CFGR_LHB_CFG2;                  //0x0050
    tCFGR_MD1_MUX_CFG_t          CFGR_MD1_MUX_CFG;               //0x0051
    tCFGR_MD1_PWM_CFG_t          CFGR_MD1_PWM_CFG;               //0x0052
    tCFGR_MD1_BCON_CFG_t         CFGR_MD1_BCON_CFG;              //0x0053
    tCFGR_MD1_AFE_CFG_t          CFGR_MD1_AFE_CFG;               //0x0054
    tCFGR_MD2_MUX_CFG_t          CFGR_MD2_MUX_CFG;               //0x0055
    tCFGR_MD2_PWM_CFG_t          CFGR_MD2_PWM_CFG;               //0x0056
    tCFGR_MD2_BCON_CFG_t         CFGR_MD2_BCON_CFG;              //0x0057
    tCFGR_MD2_AFE_CFG_t          CFGR_MD2_AFE_CFG;               //0x0058
    tCFGR_MD3_MUX_CFG1_t         CFGR_MD3_MUX_CFG1;              //0x0059
    tCFGR_MD3_MUX_CFG2_t         CFGR_MD3_MUX_CFG2;              //0x005A
    tCFGR_MD3_MUX_CFG3_t         CFGR_MD3_MUX_CFG3;              //0x005B
    tCFGR_MD3_MUX_CFG4_t         CFGR_MD3_MUX_CFG4;              //0x005C
    tCFGR_MD3_PWM_CFG_t          CFGR_MD3_PWM_CFG;               //0x005D
    tCFGR_MD3_BCON_CFG_t         CFGR_MD3_BCON_CFG;              //0x005E
    tCFGR_MD3_AFE_CFG_t          CFGR_MD3_AFE_CFG;               //0x005F
    tCFGR_MD5_PWM_CFG_t          CFGR_MD5_PWM_CFG;               //0x0060
    tCFGR_MD5_BCON_CFG_t         CFGR_MD5_BCON_CFG;              //0x0061
    tCFGR_MD5_AFE_CFG_t          CFGR_MD5_AFE_CFG;               //0x0062
    tCFGR_MD6_PWM_CFG_t          CFGR_MD6_PWM_CFG;               //0x0063
    tCFGR_CR_SEL_t               CFGR_CR_SEL;                    //0x0064
    tCFGR_R0_MD1_CRT_MX1_t       CFGR_R0_MD1_CRT_MX1;            //0x0065
    tCFGR_R0_MD1_CR_MX1_t        CFGR_R0_MD1_CR_MX1;             //0x0066
    tCFGR_R0_MD1_CR_MX2_t        CFGR_R0_MD1_CR_MX2;             //0x0067
    tCFGR_R0_MD1_CR_MX3_t        CFGR_R0_MD1_CR_MX3;             //0x0068
    tCFGR_R0_MD1_CR_MX4_t        CFGR_R0_MD1_CR_MX4;             //0x0069
    tCFGR_R0_MD1_CR_MX5_t        CFGR_R0_MD1_CR_MX5;             //0x006A
    tCFGR_R0_MD1_CR_MX6_t        CFGR_R0_MD1_CR_MX6;             //0x006B
    tCFGR_R0_MD1_CR_MX7_t        CFGR_R0_MD1_CR_MX7;             //0x006C
    tCFGR_R0_MD1_CR_MX8_t        CFGR_R0_MD1_CR_MX8;             //0x006D
    tCFGR_R0_MD1_CR_MX9_t        CFGR_R0_MD1_CR_MX9;             //0x006E
    tCFGR_R0_MD1_CR_MX10_t       CFGR_R0_MD1_CR_MX10;            //0x006F
    tCFGR_R0_MD1_CR_MX11_t       CFGR_R0_MD1_CR_MX11;            //0x0070
    tCFGR_R0_MD1_CR_MX12_t       CFGR_R0_MD1_CR_MX12;            //0x0071
    tCFGR_R0_MD1_CRB_MX12_t      CFGR_R0_MD1_CRB_MX12;           //0x0072
    tCFGR_R1_MD1_CRT_MX1_t       CFGR_R1_MD1_CRT_MX1;            //0x0073
    tCFGR_R1_MD1_CR_MX1_t        CFGR_R1_MD1_CR_MX1;             //0x0074
    tCFGR_R1_MD1_CR_MX2_t        CFGR_R1_MD1_CR_MX2;             //0x0075
    tCFGR_R1_MD1_CR_MX3_t        CFGR_R1_MD1_CR_MX3;             //0x0076
    tCFGR_R1_MD1_CR_MX4_t        CFGR_R1_MD1_CR_MX4;             //0x0077
    tCFGR_R1_MD1_CR_MX5_t        CFGR_R1_MD1_CR_MX5;             //0x0078
    tCFGR_R1_MD1_CR_MX6_t        CFGR_R1_MD1_CR_MX6;             //0x0079
    tCFGR_R1_MD1_CR_MX7_t        CFGR_R1_MD1_CR_MX7;             //0x007A
    tCFGR_R1_MD1_CR_MX8_t        CFGR_R1_MD1_CR_MX8;             //0x007B
    tCFGR_R1_MD1_CR_MX9_t        CFGR_R1_MD1_CR_MX9;             //0x007C
    tCFGR_R1_MD1_CR_MX10_t       CFGR_R1_MD1_CR_MX10;            //0x007D
    tCFGR_R1_MD1_CR_MX11_t       CFGR_R1_MD1_CR_MX11;            //0x007E
    tCFGR_R1_MD1_CR_MX12_t       CFGR_R1_MD1_CR_MX12;            //0x007F
    tCFGR_R1_MD1_CRB_MX12_t      CFGR_R1_MD1_CRB_MX12;           //0x0080
    tCFGR_R0_MD2_CRT_MX1_t       CFGR_R0_MD2_CRT_MX1;            //0x0081
    tCFGR_R0_MD2_CR_MX1_t        CFGR_R0_MD2_CR_MX1;             //0x0082
    tCFGR_R0_MD2_CR_MX2_t        CFGR_R0_MD2_CR_MX2;             //0x0083
    tCFGR_R0_MD2_CR_MX3_t        CFGR_R0_MD2_CR_MX3;             //0x0084
    tCFGR_R0_MD2_CR_MX4_t        CFGR_R0_MD2_CR_MX4;             //0x0085
    tCFGR_R0_MD2_CR_MX5_t        CFGR_R0_MD2_CR_MX5;             //0x0086
    tCFGR_R0_MD2_CR_MX6_t        CFGR_R0_MD2_CR_MX6;             //0x0087
    tCFGR_R0_MD2_CR_MX7_t        CFGR_R0_MD2_CR_MX7;             //0x0088
    tCFGR_R0_MD2_CR_MX8_t        CFGR_R0_MD2_CR_MX8;             //0x0089
    tCFGR_R0_MD2_CR_MX9_t        CFGR_R0_MD2_CR_MX9;             //0x008A
    tCFGR_R0_MD2_CR_MX10_t       CFGR_R0_MD2_CR_MX10;            //0x008B
    tCFGR_R0_MD2_CR_MX11_t       CFGR_R0_MD2_CR_MX11;            //0x008C
    tCFGR_R0_MD2_CR_MX12_t       CFGR_R0_MD2_CR_MX12;            //0x008D
    tCFGR_R0_MD2_CRB_MX12_t      CFGR_R0_MD2_CRB_MX12;           //0x008E
    tCFGR_R1_MD2_CRT_MX1_t       CFGR_R1_MD2_CRT_MX1;            //0x008F
    tCFGR_R1_MD2_CR_MX1_t        CFGR_R1_MD2_CR_MX1;             //0x0090
    tCFGR_R1_MD2_CR_MX2_t        CFGR_R1_MD2_CR_MX2;             //0x0091
    tCFGR_R1_MD2_CR_MX3_t        CFGR_R1_MD2_CR_MX3;             //0x0092
    tCFGR_R1_MD2_CR_MX4_t        CFGR_R1_MD2_CR_MX4;             //0x0093
    tCFGR_R1_MD2_CR_MX5_t        CFGR_R1_MD2_CR_MX5;             //0x0094
    tCFGR_R1_MD2_CR_MX6_t        CFGR_R1_MD2_CR_MX6;             //0x0095
    tCFGR_R1_MD2_CR_MX7_t        CFGR_R1_MD2_CR_MX7;             //0x0096
    tCFGR_R1_MD2_CR_MX8_t        CFGR_R1_MD2_CR_MX8;             //0x0097
    tCFGR_R1_MD2_CR_MX9_t        CFGR_R1_MD2_CR_MX9;             //0x0098
    tCFGR_R1_MD2_CR_MX10_t       CFGR_R1_MD2_CR_MX10;            //0x0099
    tCFGR_R1_MD2_CR_MX11_t       CFGR_R1_MD2_CR_MX11;            //0x009A
    tCFGR_R1_MD2_CR_MX12_t       CFGR_R1_MD2_CR_MX12;            //0x009B
    tCFGR_R1_MD2_CRB_MX12_t      CFGR_R1_MD2_CRB_MX12;           //0x009C
    tCFGR_R0_MD3_CRT_MX1_t       CFGR_R0_MD3_CRT_MX1;            //0x009D
    tCFGR_R0_MD3_CR_MX1_t        CFGR_R0_MD3_CR_MX1;             //0x009E
    tCFGR_R0_MD3_CR_MX2_t        CFGR_R0_MD3_CR_MX2;             //0x009F
    tCFGR_R0_MD3_CR_MX3_t        CFGR_R0_MD3_CR_MX3;             //0x00A0
    tCFGR_R0_MD3_CR_MX4_t        CFGR_R0_MD3_CR_MX4;             //0x00A1
    tCFGR_R1_MD3_CRT_MX1_t       CFGR_R1_MD3_CRT_MX1;            //0x00A2
    tCFGR_R1_MD3_CR_MX1_t        CFGR_R1_MD3_CR_MX1;             //0x00A3
    tCFGR_R1_MD3_CR_MX2_t        CFGR_R1_MD3_CR_MX2;             //0x00A4
    tCFGR_R1_MD3_CR_MX3_t        CFGR_R1_MD3_CR_MX3;             //0x00A5
    tCFGR_R1_MD3_CR_MX4_t        CFGR_R1_MD3_CR_MX4;             //0x00A6
    tCFGR_R0_MD5_CRT_MX1_t       CFGR_R0_MD5_CRT_MX1;            //0x00A7
    tCFGR_R0_MD5_CR_MX1_t        CFGR_R0_MD5_CR_MX1;             //0x00A8
    tCFGR_R0_MD5_CR_MX2_t        CFGR_R0_MD5_CR_MX2;             //0x00A9
    tCFGR_R0_MD5_CR_MX3_t        CFGR_R0_MD5_CR_MX3;             //0x00AA
    tCFGR_R0_MD5_CR_MX4_t        CFGR_R0_MD5_CR_MX4;             //0x00AB
    tCFGR_R0_MD5_CR_MX5_t        CFGR_R0_MD5_CR_MX5;             //0x00AC
    tCFGR_R0_MD5_CR_MX9_t        CFGR_R0_MD5_CR_MX9;             //0x00AD
    tCFGR_R0_MD5_CR_MX10_t       CFGR_R0_MD5_CR_MX10;            //0x00AE
    tCFGR_R0_MD5_CR_MX11_t       CFGR_R0_MD5_CR_MX11;            //0x00AF
    tCFGR_R0_MD5_CR_MX12_t       CFGR_R0_MD5_CR_MX12;            //0x00B0
    tCFGR_R0_MD5_CRB_MX12_t      CFGR_R0_MD5_CRB_MX12;           //0x00B1
    tCFGR_R1_MD5_CRT_MX1_t       CFGR_R1_MD5_CRT_MX1;            //0x00B2
    tCFGR_R1_MD5_CR_MX1_t        CFGR_R1_MD5_CR_MX1;             //0x00B3
    tCFGR_R1_MD5_CR_MX2_t        CFGR_R1_MD5_CR_MX2;             //0x00B4
    tCFGR_R1_MD5_CR_MX3_t        CFGR_R1_MD5_CR_MX3;             //0x00B5
    tCFGR_R1_MD5_CR_MX4_t        CFGR_R1_MD5_CR_MX4;             //0x00B6
    tCFGR_R1_MD5_CR_MX5_t        CFGR_R1_MD5_CR_MX5;             //0x00B7
    tCFGR_R1_MD5_CR_MX9_t        CFGR_R1_MD5_CR_MX9;             //0x00B8
    tCFGR_R1_MD5_CR_MX10_t       CFGR_R1_MD5_CR_MX10;            //0x00B9
    tCFGR_R1_MD5_CR_MX11_t       CFGR_R1_MD5_CR_MX11;            //0x00BA
    tCFGR_R1_MD5_CR_MX12_t       CFGR_R1_MD5_CR_MX12;            //0x00BB
    tCFGR_R1_MD5_CRB_MX12_t      CFGR_R1_MD5_CRB_MX12;           //0x00BC
    tCFGR_GPO_FUNC_t             CFGR_GPO_FUNC;                  //0x00BD
    tCFGR_ND_CTRL_t              CFGR_ND_CTRL;                   //0x00BE
    tCFGR_CH_EN_NUM_t            CFGR_CH_EN_NUM;                 //0x00BF
    tCFGR_ROIC_REV_t             CFGR_ROIC_REV;                  //0x00C0
    __IO uint16_t                CFGR_RESERVE_0;                 //0x00C1
    tCFGR_ERR_CLR_t              CFGR_ERR_CLR;                   //0x00C2
    tCFGR_ERR_STATUS_t           CFGR_ERR_STATUS;                //0x00C3

} __PACKED tModuleSRICCommonConf_t;

#include "_sw92502_parampreset.h"

#endif /* (USED_ROIC_DEF == ROIC_SW92502) */


#endif /* __SW92502_CONF_H_ */
