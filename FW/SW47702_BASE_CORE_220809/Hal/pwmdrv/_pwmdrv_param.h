/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _pwmdrv_param.h
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

#ifndef __PWMDRV_PARAM_H_
#define __PWMDRV_PARAM_H_

/*
 * defines
 *
 * */

typedef enum {
	PWM_PARAM_FINGER = 0,
	PWM_PARAM_PEN = 1,
	PWM_PARAM_MAX,

} ePwmParamOpMode;

/*
 * typedef
 *
 * */
typedef union
{
    struct {
        unsigned    pwm_gen_enable:            1;
        unsigned    kiosk_mode:                1;
        unsigned    tfd_mode:                  1;
        unsigned    continuos_en:              1;
        unsigned    frame_rate:                2;
        unsigned    chip_length0:              5;
        unsigned    chip_length1:              5;
        unsigned    frame_intr_sel:            1;
        unsigned    pen_mode:                  1;
        unsigned    offclk_ctrl_tpic:          1;
        unsigned    offclk_ctrl_sric:          1;
        unsigned    offclk_ctrl_mux:           1;
        unsigned    offclk_ctrl_vgh:           1;
        unsigned    offclk_ctrl_gma:           1;
        unsigned    offclk_ctrl_en:            1;
        unsigned    pwm_sric_output_en:        1;
        unsigned    pwm_tpic_output_en:        1;
        unsigned    pwm_mux_output_en:         1;
        unsigned    pwm_vgh_output_en:         1;
        unsigned    pwm_gma_output_en:         1;
        unsigned    reserved:                  3;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWMGEN_CR0_t;

typedef union
{
    struct {
        unsigned    fstart_en:                 1;
        unsigned    skip_num:                  5;
        unsigned    beacon_data_num:           4;
        unsigned    sric_dummy_num:            6;
        unsigned    tpic_dummy_num:            6;
        unsigned    dummy_gap_en:              1;
        unsigned    pgap_en:                   1;
        unsigned    pen_s_pwmnum:              7;
        unsigned    reserved:                  1;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWMGEN_CR1_t;

typedef union
{
    struct {
        unsigned    pen_d_pwmnum:              7;
        unsigned    finger_pwmnum:             7;
        unsigned    nm_num:                    7;
        unsigned    total_mux_num:             6;
        unsigned    reserved:                  5;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWMGEN_CR2_t;

typedef union
{
    struct {
        unsigned    set_tx_en:                 1;
        unsigned    set_tx_num:                7;
        unsigned    reserved:                  24;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SET_TX_CR_t;

typedef union
{
    struct {
        unsigned    tsync_num:                 5;
        unsigned    tsync_end_loc:             1;
        unsigned    tsync_dglitch_len:         3;
        unsigned    tsynct_in_sel:             1;
        unsigned    tsynct_in_inv:             1;
        unsigned    tsynct_out_inv:            1;
        unsigned    tsync_sric_in_sel:         1;
        unsigned    tsync_sric_out_sel:        1;
        unsigned    tsync_sric_in_inv:         1;
        unsigned    tsync_sric_out_inv:        1;
        unsigned    tsynct2_in_sel:            1;
        unsigned    tsynct2_in_inv:            1;
        unsigned    tsynct_kiosk_in_sel:       1;
        unsigned    tsync_sric_redge_sel:      1;		//	ToDo: Added by register map
        unsigned    tsync_sric_fedge_sel:      1;		//	ToDo: Added by register map
        unsigned    reserved:                  11;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_TSYNC_CR_t;

typedef union
{
    struct {
        unsigned    beacon_en:                 1;
        unsigned    pen_s_en:                  1;
        unsigned    pen_d_en:                  1;
        unsigned    finger_en:                 1;
        unsigned    nm_en:                     1;
        unsigned    none_en:                   1;
        unsigned    st_pnt:                    12;
        unsigned    end_pnt:                   10;
        unsigned    kiosk_sgap_end:            1;
        unsigned    kiosk_pwm_end:             1;
        unsigned    kiosk_tch_time_end:        1;
        unsigned    reserved:                  1;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_TSYNC_D2_CR_t;

typedef union
{
    struct {
        unsigned    sgap_prd:                  14;
        unsigned    ping_prd:                  11;
        unsigned    reserved:                  7;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_DLY_CNT1_t;

typedef union
{
    struct {
        unsigned    mgap_prd_f:                10;
        unsigned    mgap_prd_p_s:              10;
        unsigned    mgap_prd_p_d:              10;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_DLY_CNT2_t;

typedef union
{
    struct {
        unsigned    egap_prd:                  14;
        unsigned    dgap_prd:                  10;
        unsigned    offclk_dly:                6;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_DLY_CNT3_t;

typedef union
{
    struct {
        unsigned    beacon_en:                 1;
        unsigned    pen_s_en:                  1;
        unsigned    pen_d_en:                  1;
        unsigned    finger_en:                 1;
        unsigned    nm_en:                     1;
        unsigned    none_en:                   1;
        unsigned    pen_s_ping_en:             1;
        unsigned    pen_d_ping_en:             1;
        unsigned    finger_ping_en:            1;
        unsigned    pen_s_pwm_en:              1;
        unsigned    pen_d_pwm_en:              1;
        unsigned    finger_pwm_en:             1;
        unsigned    ping_only_en:              1;
        unsigned    delay:                     12;
        unsigned    kiosk_tch_time_end_off:    1;
        unsigned    reserved:                  6;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_TSYNC_TPIC_CR_t;

typedef union
{
    struct {
        unsigned    pwm_sric_f:                10;
        unsigned    pwm_tpic_f:                10;
        unsigned    pwm_mux_f:                 10;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_DLY1_t;

typedef union
{
    struct {
        unsigned    ping_finger:               5;
        unsigned    ping_pen_pos:              5;
        unsigned    ping_pen_dat:              5;
        unsigned    reserved:                  17;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_DSSS_INFO0_t;

typedef union
{
    struct {
        unsigned    beacon_cfg0:               5;
        unsigned    beacon_cfg1:               5;
        unsigned    beacon_cfg2:               5;
        unsigned    beacon_cfg3:               5;
        unsigned    beacon_cfg4:               5;
        unsigned    beacon_cfg5:               5;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_DSSS_INFO1_t;

typedef union
{
    struct {
        unsigned    beacon_cfg6:               5;
        unsigned    beacon_cfg7:               5;
        unsigned    beacon_cfg8:               5;
        unsigned    beacon_cfg9:               5;
        unsigned    beacon_cfg10:              5;
        unsigned    beacon_cfg11:              5;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_DSSS_INFO2_t;

typedef union
{
    struct {
        unsigned    beacon_en:                 1;
        unsigned    pen_s_ping_en:             1;
        unsigned    pen_d_ping_en:             1;
        unsigned    finger_ping_en:            1;
        unsigned    pen_s_en:                  1;
        unsigned    pen_d_en:                  1;
        unsigned    finger_en:                 1;
        unsigned    pen_s_dmy_en:              1;
        unsigned    pen_d_dmy_en:              1;
        unsigned    finger_dmy_en:             1;
        unsigned    pen_s_set_tx_en:           1;
        unsigned    pen_d_set_tx_en:           1;
        unsigned    finger_set_tx_en:          1;
        unsigned    nm_en:                     1;
        unsigned    inv_en:                    1;
        unsigned    ping_only_en:              1;
        unsigned    reserved:                  16;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_TPIC_CR_t;

typedef union
{
    struct {
        unsigned    beacon_en:                 1;
        unsigned    pen_s_ping_en:             1;
        unsigned    pen_d_ping_en:             1;
        unsigned    finger_ping_en:            1;
        unsigned    pen_s_en:                  1;
        unsigned    pen_d_en:                  1;
        unsigned    finger_en:                 1;
        unsigned    pen_s_dmy_en:              1;
        unsigned    pen_d_dmy_en:              1;
        unsigned    finger_dmy_en:             1;
        unsigned    pen_s_set_tx_en:           1;
        unsigned    pen_d_set_tx_en:           1;
        unsigned    finger_set_tx_en:          1;
        unsigned    nm_en:                     1;
        unsigned    inv_en:                    1;
        unsigned    pwm_2x_en:                 1;
        unsigned    pen_s_tsync_d2_en:         1;
        unsigned    pen_d_tsync_d2_en:         1;
        unsigned    finger_tsync_d2_en:        1;
        unsigned    ping_only_en:              1;
        unsigned    reserved:                  12;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_SRIC_CR_t;

typedef union
{
    struct {
        unsigned    beacon_en:                 1;
        unsigned    pen_s_ping_en:             1;
        unsigned    pen_d_ping_en:             1;
        unsigned    finger_ping_en:            1;
        unsigned    pen_s_en:                  1;
        unsigned    pen_d_en:                  1;
        unsigned    finger_en:                 1;
        unsigned    pen_s_dmy_en:              1;
        unsigned    pen_d_dmy_en:              1;
        unsigned    finger_dmy_en:             1;
        unsigned    pen_s_set_tx_en:           1;
        unsigned    pen_d_set_tx_en:           1;
        unsigned    finger_set_tx_en:          1;
        unsigned    nm_en:                     1;
        unsigned    inv_en:                    1;
        unsigned    ping_only_en:              1;
        unsigned    reserved:                  16;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_MUX_CR_t;

typedef union
{
    struct {
        unsigned    eclk_en:                   1;
        unsigned    eclk0_inv_en:              1;
        unsigned    eclk1_inv_en:              1;
        unsigned    eclk_div_en:               1;		//	ToDo: Added by register map
        unsigned    div_num:                   5;
        unsigned    eclk_force_on:             1;
        unsigned    eclk_en_src0:              1;		//	ToDo: Modified by register map
        unsigned    eclk_en_src1:              1;		//	ToDo: Added by register map
        unsigned    eclk_en_pnt:               9;
        unsigned    reserved:                  11;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_ECLK_CR_t;

typedef union
{
    struct {
        unsigned    pen_d:                     10;
        unsigned    pen_s:                     10;
        unsigned    finger:                    10;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_FREQ_CR1_t;

typedef union
{
    struct {
        unsigned    freq_beacon:               8;
        unsigned    reserved:                  24;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_FREQ_CR2_t;

typedef union
{
    struct {
        unsigned    lhb1:                      3;
        unsigned    lhb2:                      3;
        unsigned    lhb3:                      3;
        unsigned    lhb4:                      3;
        unsigned    lhb5:                      3;
        unsigned    lhb6:                      3;
        unsigned    lhb7:                      3;
        unsigned    lhb8:                      3;
        unsigned    lhb9:                      3;
        unsigned    lhb10:                     3;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_LHB_CONFIG11_t;

typedef union
{
    struct {
        unsigned    lhb11:                     3;
        unsigned    lhb12:                     3;
        unsigned    lhb13:                     3;
        unsigned    lhb14:                     3;
        unsigned    lhb15:                     3;
        unsigned    lhb16:                     3;
        unsigned    lhb17:                     3;
        unsigned    lhb18:                     3;
        unsigned    lhb19:                     3;
        unsigned    lhb20:                     3;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_LHB_CONFIG12_t;

typedef union
{
    struct {
        unsigned    lhb21:                     3;
        unsigned    lhb22:                     3;
        unsigned    lhb23:                     3;
        unsigned    lhb24:                     3;
        unsigned    lhb25:                     3;
        unsigned    lhb26:                     3;
        unsigned    lhb27:                     3;
        unsigned    lhb28:                     3;
        unsigned    lhb29:                     3;
        unsigned    lhb30:                     3;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_LHB_CONFIG13_t;

typedef union
{
    struct {
        unsigned    lhb31:                     3;
        unsigned    lhb32:                     3;
        unsigned    reserved:                  26;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_LHB_CONFIG14_t;

typedef union
{
    struct {
        unsigned    lhb1:                      3;
        unsigned    lhb2:                      3;
        unsigned    lhb3:                      3;
        unsigned    lhb4:                      3;
        unsigned    lhb5:                      3;
        unsigned    lhb6:                      3;
        unsigned    lhb7:                      3;
        unsigned    lhb8:                      3;
        unsigned    lhb9:                      3;
        unsigned    lhb10:                     3;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_LHB_CONFIG21_t;

typedef union
{
    struct {
        unsigned    lhb11:                     3;
        unsigned    lhb12:                     3;
        unsigned    lhb13:                     3;
        unsigned    lhb14:                     3;
        unsigned    lhb15:                     3;
        unsigned    lhb16:                     3;
        unsigned    lhb17:                     3;
        unsigned    lhb18:                     3;
        unsigned    lhb19:                     3;
        unsigned    lhb20:                     3;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_LHB_CONFIG22_t;

typedef union
{
    struct {
        unsigned    lhb21:                     3;
        unsigned    lhb22:                     3;
        unsigned    lhb23:                     3;
        unsigned    lhb24:                     3;
        unsigned    lhb25:                     3;
        unsigned    lhb26:                     3;
        unsigned    lhb27:                     3;
        unsigned    lhb28:                     3;
        unsigned    lhb29:                     3;
        unsigned    lhb30:                     3;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_LHB_CONFIG23_t;

typedef union
{
    struct {
        unsigned    lhb31:                     3;
        unsigned    lhb32:                     3;
        unsigned    reserved:                  26;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_LHB_CONFIG24_t;

typedef union
{
    struct {
        unsigned    beacon:                    1;
        unsigned    pen_s:                     1;
        unsigned    pen_d:                     1;
        unsigned    finger:                    1;
        unsigned    nm:                        1;
        unsigned    none:                      1;
        unsigned    ping_only:                 1;
        unsigned    reserved:                  25;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PING_CR_t;

typedef union
{
    struct {
        unsigned    sync_gen_en:               1;
        unsigned    vsync_stuck_en:            1;
        unsigned    vsync_stuck_level:         1;
        unsigned    tsynct_stuck_en:           1;
        unsigned    tsynct_stuck_level:        1;
        unsigned    tsyncd_stuck_en:           1;
        unsigned    tsyncd_stuck_level:        1;
        unsigned    reserved:                  25;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_SYNC_GEN_CR_t;

//typedef union
//{
//    struct {
//        unsigned    busy:                      1;
//        unsigned    state:                     4;
//        unsigned    reserved:                  27;
//    } __PACKED tBit;
//    __IO uint32_t ulBulk;
//} __PACKED tCP_TE_STATUS_t;

typedef union
{
    struct {
        unsigned    tsync_tpic_out_bypass_enb:	1;
        unsigned    tsync_sric_out_bypass_enb:	1;
        unsigned    tsync_sric_lhb_ping_en:		1;
        unsigned    sync_gen_fr_done_mask_en:	1;
        unsigned    disp_off_beacon_only:		1;
        unsigned    reserved:                  27;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_TG_DUM5_t;

typedef union
{
    struct {
        unsigned    stuck_en:                  1;
        unsigned    stuck_value:               1;
        unsigned    disp_off_fpnt:             14;
        unsigned    inv_en:                    1;
        unsigned    disp_off_en:               1;		//	ToDo: Added by register map
        unsigned    reserved:                  14;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_DISP_OFF_CR_t;

typedef union
{
    struct {
        unsigned    pen_s_h_pnt:               10;
        unsigned    pen_d_h_pnt:               10;
        unsigned    reserved:                  12;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_CR1_t;

typedef union
{
    struct {
        unsigned    finger_h_pnt:              10;
        unsigned    dmy_h_pnt:                 10;
        unsigned    reserved:                  12;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_CR2_t;

typedef union
{
    struct {
        unsigned    vsync_in_inv:              1;
        unsigned    vsync_in_sel:              1;
        unsigned    vsync_locate:              5;
        unsigned    rising_pnt:                10;
        unsigned    falling_pnt:               10;
        unsigned    vsync_kiosk_in_sel:        1;
        unsigned    gst_in_inv: 		       1;		//	ToDo: Added by register map
        unsigned    reserved:                  3;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_VSYNC_CR_t;

typedef union
{
    struct {
        unsigned    pen_s:                     6;
        unsigned    pen_d:                     6;
        unsigned    finger:                    6;
        unsigned    nm:                        2;
        unsigned    reserved:                  12;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_MUX_CR_t;

typedef union
{
    struct {
        unsigned    beacon_stuck:              1;
        unsigned    pen_s_ping_stuck:          1;
        unsigned    pen_d_ping_stuck:          1;
        unsigned    finger_ping_stuck:         1;
        unsigned    pen_s_stuck:               1;
        unsigned    pen_d_stuck:               1;
        unsigned    finger_stuck:              1;
        unsigned    pen_s_dmy_stuck:           1;
        unsigned    pen_d_dmy_stuck:           1;
        unsigned    finger_dmy_stuck:          1;
        unsigned    pen_s_set_tx_stuck:        1;
        unsigned    pen_d_set_tx_stuck:        1;
        unsigned    finger_set_tx_stuck:       1;
        unsigned    nm_stuck:                  1;
        unsigned    reserved:                  18;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_TPIC_ST_CR_t;

typedef union
{
    struct {
        unsigned    beacon_stuck:              1;
        unsigned    pen_s_ping_stuck:          1;
        unsigned    pen_d_ping_stuck:          1;
        unsigned    finger_ping_stuck:         1;
        unsigned    pen_s_stuck:               1;
        unsigned    pen_d_stuck:               1;
        unsigned    finger_stuck:              1;
        unsigned    pen_s_dmy_stuck:           1;
        unsigned    pen_d_dmy_stuck:           1;
        unsigned    finger_dmy_stuck:          1;
        unsigned    pen_s_set_tx_stuck:        1;
        unsigned    pen_d_set_tx_stuck:        1;
        unsigned    finger_set_tx_stuck:       1;
        unsigned    nm_stuck:                  1;
        unsigned    reserved:                  18;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_SRIC_ST_CR_t;

typedef union
{
    struct {
        unsigned    beacon_stuck:              1;
        unsigned    pen_s_ping_stuck:          1;
        unsigned    pen_d_ping_stuck:          1;
        unsigned    finger_ping_stuck:         1;
        unsigned    pen_s_stuck:               1;
        unsigned    pen_d_stuck:               1;
        unsigned    finger_stuck:              1;
        unsigned    pen_s_dmy_stuck:           1;
        unsigned    pen_d_dmy_stuck:           1;
        unsigned    finger_dmy_stuck:          1;
        unsigned    pen_s_set_tx_stuck:        1;
        unsigned    pen_d_set_tx_stuck:        1;
        unsigned    finger_set_tx_stuck:       1;
        unsigned    nm_stuck:                  1;
        unsigned    reserved:                  18;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_MUX_ST_CR_t;

typedef union
{
    struct {
        unsigned    freq_nm1:                  10;
        unsigned    freq_nm2:                  10;
        unsigned    freq_nm3:                  10;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_NM_FREQ_t;

//typedef union
//{
//    struct {
//        unsigned    state:                     5;
//        unsigned    tsync_cnt:                 5;
//        unsigned    lhb_drv:                   3;
//        unsigned    mux_cnt:                   6;
//        unsigned    reserved:                  13;
//    } __PACKED tBit;
//    __IO uint32_t ulBulk;
//} __PACKED tCP_PWM_STATUS_t;

typedef union
{
    struct {
        unsigned    pwm_vgh_f:                 10;
        unsigned    pwm_gma_f:                 10;
        unsigned    reserved:                  12;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_DLY2_t;

typedef union
{
    struct {
        unsigned    bgap_prd:                  11;
        unsigned    bc_egap_prd:               13;
        unsigned    reserved:                  8;
	} __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_DLY_CNT4_t;

typedef union
{
    struct {
        unsigned    pwm_sric_p:                10;
        unsigned    pwm_tpic_p:                10;
        unsigned    pwm_mux_p:                 10;
        unsigned    reserved:                  2;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_DLY3_t;

typedef union
{
    struct {
        unsigned    pwm_vgh_p:                 10;
        unsigned    pwm_gma_p:                 10;
        unsigned    reserved:                  12;
    } __PACKED tBit;
    __IO uint32_t ulBulk;
} __PACKED tCP_PWM_DLY4_t;

//typedef union
//{
//    struct {
//        unsigned    mgap_prd_f_1:              4;
//        unsigned    mgap_prd_p_s_1:            4;
//        unsigned    mgap_prd_p_d_1:            4;
//        unsigned    reserved:                  20;
//    } __PACKED tBit;
//    __IO uint32_t ulBulk;
//} __PACKED tCP_DLY_CNT5_t;

typedef struct
{
    uint32_t tCP_DSSS_CODE_P_0; //0x000E
    uint32_t tCP_DSSS_CODE_P_1; //0x000F
    uint32_t tCP_DSSS_CODE_0_0; //0x0010
    uint32_t tCP_DSSS_CODE_0_1; //0x0011
    uint32_t tCP_DSSS_CODE_1_0; //0x0012
    uint32_t tCP_DSSS_CODE_1_1; //0x0013
    uint32_t tCP_DSSS_CODE_2_0; //0x0014
    uint32_t tCP_DSSS_CODE_2_1; //0x0015
    uint32_t tCP_DSSS_CODE_3_0; //0x0016
    uint32_t tCP_DSSS_CODE_3_1; //0x0017
    uint32_t tCP_DSSS_CODE_4_0; //0x0018
    uint32_t tCP_DSSS_CODE_4_1; //0x0019
    uint32_t tCP_DSSS_CODE_5_0; //0x001A
    uint32_t tCP_DSSS_CODE_5_1; //0x001B
    uint32_t tCP_DSSS_CODE_6_0; //0x001C
    uint32_t tCP_DSSS_CODE_6_1; //0x001D
    uint32_t tCP_DSSS_CODE_7_0; //0x001E
    uint32_t tCP_DSSS_CODE_7_1; //0x001F

} __PACKED tCP_DSSS_CODE_Value_t;

/*
 *
 * Sample structure
typedef union
{
	struct {

	} __PACKED tBit;

	__IO uint32_t ulBulk;

} __PACKED tPWMDRV_PRE_2_t;
*/
#endif /* __PWMDRV_PARAM_H_ */
