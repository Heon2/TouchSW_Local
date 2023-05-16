/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _pwmdrv.h
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

#ifndef __PWMDRV_H_
#define __PWMDRV_H_


#include "_pwmdrv_param.h"
/* ================================================================================ */
/* ================                      PWMDRV                    ================ */
/* ================================================================================ */
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
    } tBit;
    __IO uint32_t ulBulk;
} t_PWMGEN_CR0;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_PWMGEN_CR1;

typedef union
{
    struct {
        unsigned    pen_d_pwmnum:              7;
        unsigned    finger_pwmnum:             7;
        unsigned    nm_num:                    7;
        unsigned    total_mux_num:             6;
        unsigned    reserved:                  5;
    } tBit;
    __IO uint32_t ulBulk;
} t_PWMGEN_CR2;

typedef union
{
    struct {
        unsigned    set_tx_en:                 1;
        unsigned    set_tx_num:                7;
        unsigned    reserved:                  24;
    } tBit;
    __IO uint32_t ulBulk;
} t_SET_TX_CR;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_TSYNC_CR;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_TSYNC_D2_CR;

typedef union
{
    struct {
        unsigned    sgap_prd:                  14;
        unsigned    ping_prd:                  11;
        unsigned    reserved:                  7;
    } tBit;
    __IO uint32_t ulBulk;
} t_DLY_CNT1;

typedef union
{
    struct {
        unsigned    mgap_prd_f:                10;
        unsigned    mgap_prd_p_s:              10;
        unsigned    mgap_prd_p_d:              10;
        unsigned    reserved:                  2;
    } tBit;
    __IO uint32_t ulBulk;
} t_DLY_CNT2;

typedef union
{
    struct {
        unsigned    egap_prd:                  14;
        unsigned    dgap_prd:                  10;
        unsigned    offclk_dly:                6;
        unsigned    reserved:                  2;
    } tBit;
    __IO uint32_t ulBulk;
} t_DLY_CNT3;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_TSYNC_TPIC_CR;

typedef union
{
    struct {
        unsigned    pwm_sric_f:                10;
        unsigned    pwm_tpic_f:                10;
        unsigned    pwm_mux_f:                 10;
        unsigned    reserved:                  2;
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_DLY1;

typedef union
{
    struct {
        unsigned    ping_finger:               5;
        unsigned    ping_pen_pos:              5;
        unsigned    ping_pen_dat:              5;
        unsigned    reserved:                  17;
    } tBit;
    __IO uint32_t ulBulk;
} t_DSSS_INFO0;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_DSSS_INFO1;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_DSSS_INFO2;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_TPIC_CR;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_SRIC_CR;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_MUX_CR;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_ECLK_CR;

typedef union
{
    struct {
        unsigned    pen_d:                     10;
        unsigned    pen_s:                     10;
        unsigned    finger:                    10;
        unsigned    reserved:                  2;
    } tBit;
    __IO uint32_t ulBulk;
} t_FREQ_CR1;

typedef union
{
    struct {
        unsigned    freq_beacon:               8;
        unsigned    reserved:                  24;
    } tBit;
    __IO uint32_t ulBulk;
} t_FREQ_CR2;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_LHB_CONFIG11;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_LHB_CONFIG12;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_LHB_CONFIG13;

typedef union
{
    struct {
        unsigned    lhb31:                     3;
        unsigned    lhb32:                     3;
        unsigned    reserved:                  26;
    } tBit;
    __IO uint32_t ulBulk;
} t_LHB_CONFIG14;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_LHB_CONFIG21;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_LHB_CONFIG22;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_LHB_CONFIG23;

typedef union
{
    struct {
        unsigned    lhb31:                     3;
        unsigned    lhb32:                     3;
        unsigned    reserved:                  26;
    } tBit;
    __IO uint32_t ulBulk;
} t_LHB_CONFIG24;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_PING_CR;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_SYNC_GEN_CR;

typedef union
{
    struct {
        unsigned    busy:                      1;
        unsigned    state:                     4;
        unsigned    reserved:                  27;
    } tBit;
    __IO uint32_t ulBulk;
} t_TE_STATUS;

typedef union
{
    struct {
        unsigned    tsync_tpic_out_bypass_enb:	1;
        unsigned    tsync_sric_out_bypass_enb:	1;
        unsigned    tsync_sric_lhb_ping_en:		1;
        unsigned    sync_gen_fr_done_mask_en:	1;
        unsigned    disp_off_beacon_only:		1;
        unsigned    reserved:                  27;
    } tBit;
    __IO uint32_t ulBulk;
} t_TG_DUM5;

typedef union
{
    struct {
        unsigned    stuck_en:                  1;
        unsigned    stuck_value:               1;
        unsigned    disp_off_fpnt:             14;
        unsigned    inv_en:                    1;
//        unsigned    disp_off_en:               1;		//	ToDo: Added by register map
        unsigned    reserved:                  14;
    } tBit;
    __IO uint32_t ulBulk;
} t_DISP_OFF_CR;

typedef union
{
    struct {
        unsigned    pen_s_h_pnt:               10;
        unsigned    pen_d_h_pnt:               10;
        unsigned    reserved:                  12;
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_CR1;

typedef union
{
    struct {
        unsigned    finger_h_pnt:              10;
        unsigned    dmy_h_pnt:                 10;
        unsigned    reserved:                  12;
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_CR2;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_VSYNC_CR;

typedef union
{
    struct {
        unsigned    pen_s:                     6;
        unsigned    pen_d:                     6;
        unsigned    finger:                    6;
        unsigned    nm:                        2;
        unsigned    reserved:                  12;
    } tBit;
    __IO uint32_t ulBulk;
} t_MUX_CR;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_TPIC_ST_CR;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_SRIC_ST_CR;

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
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_MUX_ST_CR;

typedef union
{
    struct {
        unsigned    freq_nm1:                  10;
        unsigned    freq_nm2:                  10;
        unsigned    freq_nm3:                  10;
        unsigned    reserved:                  2;
    } tBit;
    __IO uint32_t ulBulk;
} t_NM_FREQ;

typedef union
{
    struct {
        unsigned    state:                     5;
        unsigned    tsync_cnt:                 5;
        unsigned    lhb_drv:                   3;
        unsigned    mux_cnt:                   6;
        unsigned    reserved:                  13;
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_STATUS;

typedef union
{
    struct {
        unsigned    pwm_vgh_f:                 10;
        unsigned    pwm_gma_f:                 10;
        unsigned    reserved:                  12;
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_DLY2;

typedef union
{
    struct {
        unsigned    bgap_prd:                  11;
        unsigned    bc_egap_prd:               14;		//	ToDo: Bit-number modified by register map
        unsigned    reserved:                  7;
	} tBit;
    __IO uint32_t ulBulk;
} t_DLY_CNT4;

typedef union
{
    struct {
        unsigned    pwm_sric_p:                10;
        unsigned    pwm_tpic_p:                10;
        unsigned    pwm_mux_p:                 10;
        unsigned    reserved:                  2;
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_DLY3;

typedef union
{
    struct {
        unsigned    pwm_vgh_p:                 10;
        unsigned    pwm_gma_p:                 10;
        unsigned    reserved:                  12;
    } tBit;
    __IO uint32_t ulBulk;
} t_PWM_DLY4;

typedef union
{
    struct {
        unsigned    mgap_prd_f_1:              4;
        unsigned    mgap_prd_p_s_1:            4;
        unsigned    mgap_prd_p_d_1:            4;
        unsigned    reserved:                  20;
    } tBit;
    __IO uint32_t ulBulk;
} t_DLY_CNT5;

/**
  * @brief PWMDRV / PWM TX Generation Configuration Register
  */
typedef struct {                             /*!< PWMDRV Structure   */
    __IO t_PWMGEN_CR0                PWMGEN_CR0;                     //0x0000
    __IO t_PWMGEN_CR1                PWMGEN_CR1;                     //0x0001
    __IO t_PWMGEN_CR2                PWMGEN_CR2;                     //0x0002
    __IO t_SET_TX_CR                 SET_TX_CR;                      //0x0003
    __IO t_TSYNC_CR                  TSYNC_CR;                       //0x0004
    __IO t_TSYNC_D2_CR               TSYNC_D2_CR;                    //0x0005
    __IO t_DLY_CNT1                  DLY_CNT1;                       //0x0006
    __IO t_DLY_CNT2                  DLY_CNT2;                       //0x0007
    __IO t_DLY_CNT3                  DLY_CNT3;                       //0x0008
    __IO t_TSYNC_TPIC_CR             TSYNC_TPIC_CR;                  //0x0009
    __IO t_PWM_DLY1                  PWM_DLY1;                       //0x000A
    __IO t_DSSS_INFO0                DSSS_INFO0;                     //0x000B
    __IO t_DSSS_INFO1                DSSS_INFO1;                     //0x000C
    __IO t_DSSS_INFO2                DSSS_INFO2;                     //0x000D
    __IO uint32_t                    DSSS_CODE_P_0;                  //0x000E
    __IO uint32_t                    DSSS_CODE_P_1;                  //0x000F
    __IO uint32_t                    DSSS_CODE_0_0;                  //0x0010
    __IO uint32_t                    DSSS_CODE_0_1;                  //0x0011
    __IO uint32_t                    DSSS_CODE_1_0;                  //0x0012
    __IO uint32_t                    DSSS_CODE_1_1;                  //0x0013
    __IO uint32_t                    DSSS_CODE_2_0;                  //0x0014
    __IO uint32_t                    DSSS_CODE_2_1;                  //0x0015
    __IO uint32_t                    DSSS_CODE_3_0;                  //0x0016
    __IO uint32_t                    DSSS_CODE_3_1;                  //0x0017
    __IO uint32_t                    DSSS_CODE_4_0;                  //0x0018
    __IO uint32_t                    DSSS_CODE_4_1;                  //0x0019
    __IO uint32_t                    DSSS_CODE_5_0;                  //0x001A
    __IO uint32_t                    DSSS_CODE_5_1;                  //0x001B
    __IO uint32_t                    DSSS_CODE_6_0;                  //0x001C
    __IO uint32_t                    DSSS_CODE_6_1;                  //0x001D
    __IO uint32_t                    DSSS_CODE_7_0;                  //0x001E
    __IO uint32_t                    DSSS_CODE_7_1;                  //0x001F
    __IO t_PWM_TPIC_CR               PWM_TPIC_CR;                    //0x0020
    __IO t_PWM_SRIC_CR               PWM_SRIC_CR;                    //0x0021
    __IO t_PWM_MUX_CR                PWM_MUX_CR;                     //0x0022
    __IO t_ECLK_CR                   ECLK_CR;                        //0x0023
    __IO uint32_t                    DMY_FREQ;                       //0x0024
    __IO t_FREQ_CR1                  FREQ_CR1;                       //0x0025
    __IO t_FREQ_CR2                  FREQ_CR2;                       //0x0026
    __IO t_LHB_CONFIG11              LHB_CONFIG11;                   //0x0027
    __IO t_LHB_CONFIG12              LHB_CONFIG12;                   //0x0028
    __IO t_LHB_CONFIG13              LHB_CONFIG13;                   //0x0029
    __IO t_LHB_CONFIG14              LHB_CONFIG14;                   //0x002A
    __IO t_LHB_CONFIG21              LHB_CONFIG21;                   //0x002B
    __IO t_LHB_CONFIG22              LHB_CONFIG22;                   //0x002C
    __IO t_LHB_CONFIG23              LHB_CONFIG23;                   //0x002D
    __IO t_LHB_CONFIG24              LHB_CONFIG24;                   //0x002E
    __IO t_PING_CR                   PING_CR;                        //0x002F
    __IO t_SYNC_GEN_CR               SYNC_GEN_CR;                    //0x0030
    __IO uint32_t                    TE_RDY_CNT;                     //0x0031
    __IO uint32_t                    TE_TCH_V_FPCH;                  //0x0032
    __IO uint32_t                    TE_TCH_V_HIGH;                  //0x0033
    __IO uint32_t                    TE_TCH_FPCH;                    //0x0034
    __IO uint32_t                    TE_TCH_T_HIGH;                  //0x0035
    __IO uint32_t                    TE_TCH_D_HIGH;                  //0x0036
    __IO uint32_t                    TE_TCH_LOW;                     //0x0037
    __IO uint32_t                    TE_TCH_BPCH;                    //0x0038
    __IO uint32_t                    TE_TCH_PD_LOW;                  //0x0039
    __I  t_TE_STATUS                 TE_STATUS;                      //0x003A
    __IO uint32_t                    TG_DUM1;                        //0x003B
    __IO uint32_t                    TG_DUM2;                        //0x003C
    __IO uint32_t                    TG_DUM3;                        //0x003D
    __IO uint32_t                    TG_DUM4;                        //0x003E
    __IO t_TG_DUM5                   TG_DUM5;                        //0x003F
    __IO t_DISP_OFF_CR               DISP_OFF_CR;                    //0x0040
    __IO t_PWM_CR1                   PWM_CR1;                        //0x0041
    __IO t_PWM_CR2                   PWM_CR2;                        //0x0042
    __IO t_VSYNC_CR                  VSYNC_CR;                       //0x0043
    __IO t_MUX_CR                    MUX_CR;                         //0x0044
    __IO t_PWM_TPIC_ST_CR            PWM_TPIC_ST_CR;                 //0x0045
    __IO t_PWM_SRIC_ST_CR            PWM_SRIC_ST_CR;                 //0x0046
    __IO t_PWM_MUX_ST_CR             PWM_MUX_ST_CR;                  //0x0047
    __IO t_NM_FREQ                   NM_FREQ;                        //0x0048
    __I  t_PWM_STATUS                PWM_STATUS;                     //0x0049
    __IO t_PWM_DLY2                  PWM_DLY2;                       //0x004A
    __IO t_DLY_CNT4                  DLY_CNT4;                       //0x004B
    __IO uint32_t                    KIOSK_VSYNC_TIMER;              //0x004C
    __IO t_PWM_DLY3                  PWM_DLY3;                       //0x004D
    __IO t_PWM_DLY4                  PWM_DLY4;                       //0x004E
//    __IO t_DLY_CNT5                  DLY_CNT5;                       //0x004F			//	Deleted by register map

} tPWMDRV_CtrlReg_t;


#endif /* __PWMDRV_H_ */
