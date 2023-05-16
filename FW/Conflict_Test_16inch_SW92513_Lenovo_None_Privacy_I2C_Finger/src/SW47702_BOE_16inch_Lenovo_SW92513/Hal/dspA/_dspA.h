/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _dspA.h
 * created on : 14. 5. 2019
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

#ifndef __DSPA_H_
#define __DSPA_H_


/* ================================================================================ */
/* ================                      DSPA                      ================ */
/* ================================================================================ */
typedef union
{
    struct {
        unsigned    cal1_mode:                 1;
        unsigned    cal2_mode:                 3;
        unsigned    sens_dir:                  1;
        unsigned    reserved:                  27;
    } tBit;
    __IO uint32_t w;
} t_dspa_mode;

typedef union
{
    struct {
        unsigned    src2_div_en:               1;
        unsigned    dst_div_en:                1;
        unsigned    get_val_en:                1;
        unsigned    reserved:                  29;
    } tBit;
    __IO uint32_t w;
} t_dspa_cal_ctrl;

typedef union
{
    struct {
        unsigned    const_a:                   10;
        unsigned    const_b:                   10;
        unsigned    const_n:                   4;
        unsigned    reserved:                  8;
    } tBit;
    __IO uint32_t w;
} t_dspa_cal_const;

typedef union
{
    struct {
        unsigned    xsize:                     8;
        unsigned    ysize:                     8;
        unsigned    datalen:                   16;
    } tBit;
    __IO uint32_t w;
} t_dspa_size_cfg;

typedef union
{
    struct {
        unsigned    src2_dsize:                2;
        unsigned    dst_dsize:                 2;
        unsigned    tot_xsize:                 8;
        unsigned    reserved:                  20;
    } tBit;
    __IO uint32_t w;
} t_dspa_dsize;

typedef union
{
    struct {
        unsigned    int_op_end:                1;
        unsigned    event_en:                  1;
        unsigned    int_cal_ovf:               1;
        unsigned    int_tmode:                 1;
        unsigned    reserved:                  28;
    } tBit;
    __IO uint32_t w;
} t_dspa_int_en;

typedef union
{
    struct {
        unsigned    int_op_end_clr:            1;
        unsigned    int_cal_ovf_clr:           1;
        unsigned    int_tmode_clr:             1;
        unsigned    reserved:                  29;
    } tBit;
    __IO uint32_t w;
} t_dspa_int_clr;

typedef union
{
    struct {
        unsigned    int_op_end_sts:            1;
        unsigned    int_ovf_upper_sts:         1;
        unsigned    int_ovf_lower_sts:         1;
        unsigned    dspa_busy:                 1;
        unsigned    dspa_fsm:                  4;
        unsigned    dspa_xcnt:                 8;
        unsigned    dspa_ycnt:                 8;
        unsigned    reserved:                  8;
    } tBit;
    __IO uint32_t w;
} t_dspa_status;

typedef union
{
    struct {
        unsigned    tmode_brk_en:              1;
        unsigned    tmode_brk_pos:             16;
        unsigned    tmode_brk_st:              1;
        unsigned    reserved:                  14;
    } tBit;
    __IO uint32_t w;
} t_dspa_tmode_cfg;

typedef union
{
		struct {
				unsigned    div_x0:              8;
				unsigned    div_x1:              8;
				unsigned    div_x2:              8;
				unsigned    div_x3:              8;
		} Linefilter;
		struct {
				unsigned    p_cell_num:          16;
				unsigned    p_max_val:           16;
		} Normalize;
		struct {
				unsigned    div_x0:              8;
				unsigned    div_x1:              8;
				unsigned    div_x2:              8;
				unsigned    div_x3:              8;
		} Linecount;
		__IO uint32_t w;
} t_dspa_gen_reg0;

typedef union
{
		struct {
				unsigned    div_x4:              8;
				unsigned    div_x5:              8;
				unsigned    div_x6:              8;
				unsigned    div_x7:              8;
		} Linefilter;
		struct {
				unsigned    p_cell_sum:          32;
		} Normalize;
		struct {
				unsigned    div_x4:              8;
				unsigned    div_x5:              8;
				unsigned    div_x6:              8;
				unsigned    div_x7:              8;
		} Linecount;
		__IO uint32_t w;
} t_dspa_gen_reg1;

typedef union
{
		struct {
				unsigned    n_cnt0:              16;
				unsigned    n_cnt1:              16;
		} Linefilter;
		struct {
				unsigned    p_max_pos_col:       8;
				unsigned    p_max_pos_row:       8;
				unsigned    m_max_pos_col:       8;
				unsigned    m_max_pos_row:       8;
		} Normalize;
		struct {
				unsigned    line_x0:             8;
				unsigned    line_x1:             8;
				unsigned    line_x2:             8;
				unsigned    line_x3:             8;
		} Linecount;
		__IO uint32_t w;
} t_dspa_gen_reg2;

typedef union
{
		struct {
				unsigned    n_cnt2:              16;
				unsigned    n_cnt3:              16;
		} Linefilter;
		struct {
				unsigned    m_cell_num:       	 16;
				unsigned    m_max_val:       		 16;
		} Normalize;
		struct {
				unsigned    line_x4:             8;
				unsigned    line_x5:             8;
				unsigned    line_x6:             8;
				unsigned    line_x7:             8;
		} Linecount;
		__IO uint32_t w;
} t_dspa_gen_reg3;

typedef union
{
		struct {
				unsigned    n_cnt4:              16;
				unsigned    n_cnt5:              16;
		} Linefilter;
		struct {
				unsigned    m_cell_sum:       	 16;
		} Normalize;
		struct {
				unsigned    line_x8:             8;
				unsigned    line_x9:             8;
				unsigned    line_x10:            8;
				unsigned    line_x11:            8;
		} Linecount;
		__IO uint32_t w;
} t_dspa_gen_reg4;

typedef union
{
		struct {
				unsigned    n_cnt6:              16;
				unsigned    n_cnt7:              16;
		} Linefilter;
		struct {
				unsigned    t_group_col_min:     8;
				unsigned    t_group_col_max:     8;
				unsigned    t_group_row_max:     8;
				unsigned    t_group_row_min:     8;
		} Normalize;
		struct {
				unsigned    line_x12:            8;
				unsigned    line_x13:            8;
				unsigned    line_x14:            8;
				unsigned    line_x15:            8;
		} Linecount;
		__IO uint32_t w;
} t_dspa_gen_reg5;


typedef struct
{
    __O  uint32_t                    dspa_start;                     //0x0000
    __O  uint32_t                    dspa_init;                      //0x0001
    __IO t_dspa_mode                 dspa_mode;                      //0x0002
    __IO t_dspa_cal_ctrl             dspa_cal_ctrl;                  //0x0003
    __IO t_dspa_cal_const            dspa_cal_const;                 //0x0004
    __IO t_dspa_size_cfg             dspa_size_cfg;                  //0x0005
    __IO t_dspa_dsize                dspa_dsize;                     //0x0006
    __IO uint32_t                    dspa_src1_addr;                 //0x0007
    __IO uint32_t                    dspa_src2_addr;                 //0x0008
    __IO uint32_t                    dspa_src3_addr;                 //0x0009
    __IO uint32_t                    dspa_dst_addr;                  //0x000A
    __IO uint32_t                    dspa_lf_uppth;                  //0x000B
    __IO uint32_t                    dspa_lf_lowth;                  //0x000C
    __IO uint32_t                    dspa_lcnt_uppth;                //0x000D
    __IO uint32_t                    dspa_lcnt_lowth;                //0x000E
    __IO uint32_t                    dspa_param_th;                  //0x000F
    __IO uint32_t                    dspa_ovf_uppth;                 //0x0010
    __IO uint32_t                    dspa_ovf_lowth;                 //0x0011
    __IO t_dspa_gen_reg0             dspa_gen_reg0;                  //0x0012
    __IO t_dspa_gen_reg1             dspa_gen_reg1;                  //0x0013
    __IO t_dspa_gen_reg2             dspa_gen_reg2;                  //0x0014
    __IO t_dspa_gen_reg3             dspa_gen_reg3;                  //0x0015
    __IO t_dspa_gen_reg4             dspa_gen_reg4;                  //0x0016
    __IO t_dspa_gen_reg5             dspa_gen_reg5;                  //0x0017
    __IO uint32_t                    RESERVED0;                      //0x0018
    __IO t_dspa_int_en               dspa_int_en;                    //0x0019
    __O  t_dspa_int_clr              dspa_int_clr;                   //0x001A
    __I  t_dspa_status               dspa_status;                    //0x001B
    __I  uint32_t                    dspa_src1_curr_addr;            //0x001C
    __I  uint32_t                    dspa_src2_curr_addr;            //0x001D
    __I  uint32_t                    dspa_src3_curr_addr;            //0x001E
    __I  uint32_t                    dspa_dst_curr_addr;             //0x001F
    __I  uint32_t                    dspa_src1_buf;                  //0x0020
    __I  uint32_t                    dspa_src2_buf;                  //0x0021
    __I  uint32_t                    dspa_src3_buf;                  //0x0022
    __I  uint32_t                    dspa_dst_buf;                   //0x0023
    __IO t_dspa_tmode_cfg            dspa_tmode_cfg;                 //0x0024
    __O  uint32_t                    dspa_tmode_clr;                 //0x0025

} tDSPA_CtrlReg_t;


#endif /* __DSPA_H_ */
