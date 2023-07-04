/****************************************************************************************************/ /**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : parameter_sric_finger.h
 * created on : 18. 9. 2017
 * Author : mhjang
 *
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright
 *	 notice, this list of conditions and the following disclaimer.
 *	 - Redistributions in binary form must reproduce the above copyright
 *	 notice, this list of conditions and the following disclaimer in the
 *	 documentation and/or other materials provided with the distribution.
 * - Neither the name of SiW nor the names of its contributors may be used
 *	 to endorse or promote products derived from this software without
 *	 specific prior written permission.
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

#ifndef _CUSTOM_SRIC_FINGER_H_
#define _CUSTOM_SRIC_FINGER_H_


// SRIC Setting
#if USED_REPORTRATE_120HZ
#define __md_one_frm				(0) // R_MD_GENERAL0 0xC050
#define __md_two_frm				(0)
#define __md_lhb_pen				(0)
#define __md_lhb_one				(0)
#define __md_lhb					(1)
#define __md_dintg					(0)
#define __md_double					(1)
#define __md_24mhz					(0)
#define __md_ni_f1					(0)
#define __md_ni_f2					(0)
#define __md_ni_f3					(0)
#define __md_ni_f4					(0)
#if USED_MUX_SENSING_REVERSE
#define __cmux_remap				(1)
#else /* USED_MUX_SENSING_REVERSE */
#define __cmux_remap				(0)
#endif /* USED_MUX_SENSING_REVERSE */
#define __tsync_flt					(1)
#define __tsync_pos					(1)

//#define SRIC_SENSING_TSYNC_ACTIVE_BITMASK	(0x1FFE)
//#define SRIC_SENSING_TSYNC_IDLE_BITMASK		(0x7E)
#define SRIC_SENSING_TSYNC_ACTIVE_BITMASK	(0x3F7E)
#define SRIC_SENSING_TSYNC_IDLE_BITMASK		(0x7E)
#define __str_tsync0				(1)//(1)			// Start TSYNC Number for 0th Frame 0 ~ 47 (default: 7'd0)
#define __end_tsync0				(6)//(6)			// End TSYNC Number for 0th Frame 1 ~ 48 (default: 7'd6)
#define __str_tsync1				(1)//(0)//(1)			// Start TSYNC Number for 1th Frame 0 ~ 47 (default: 7'd0)
#define __end_tsync1				(6)//(5)//(6)			// End TSYNC Number for 1th Frame 1 ~ 48 (default: 7'd6)
#define __dmy_tsync1				(2)//(3)//(2)			// Dummy TSYNC Number after 1th Frame 0 (default: 7'd0)
#define __str_tsync0_pen			(1)			// Start TSYNC Number for Pen's Frame 0 ~ 30 (default: 7'd1)
#define __end_tsync0_pen			(15)			// End TSYNC Number for 0th Frame 1 ~ 31 (default: 7'd15)
#define __dmy_tsync_pen				(0)			// Dummy TSYNC Number for Pen's Frame1 (default: 7'd0)

#define __num_pre_pwm				(3)			// Number of Previous PWM Pulse in Finger Mode (default: 8'd5)
#define __num_set_pwm				(1)			// Number of Set PWM Pulse  in Finger Mode (default: 6'd1)
#define __num_act_pwm				(11)//(9)			// Number of Active PWM Pulse (default: 8'd20)
#else /* USED_REPORTRATE_120HZ */
#define __md_one_frm				(0) // R_MD_GENERAL0 0xC048
#define __md_two_frm				(0)
#define __md_lhb_pen				(0)
#define __md_lhb_one				(1)
#define __md_lhb					(0)
#define __md_dintg					(0)
#define __md_double					(1)
#define __md_24mhz					(0)
#define __md_ni_f1					(0)
#define __md_ni_f2					(0)
#define __md_ni_f3					(0)
#define __md_ni_f4					(0)
#define __cmux_remap				(0)
#define __tsync_flt					(1)
#define __tsync_pos					(1)

#define __str_tsync0				(1)			// Start TSYNC Number for 0th Frame 0 ~ 47 (default: 7'd0)
#define __end_tsync0				(6)			// End TSYNC Number for 0th Frame 1 ~ 48 (default: 7'd6)
#define __str_tsync1				(1)			// Start TSYNC Number for 1th Frame 0 ~ 47 (default: 7'd0)
#define __end_tsync1				(6)			// End TSYNC Number for 1th Frame 1 ~ 48 (default: 7'd6)
#define __dmy_tsync1				(3)			// Dummy TSYNC Number after 1th Frame 0 (default: 7'd0)
#define __str_tsync0_pen			(1)			// Start TSYNC Number for Pen's Frame 0 ~ 30 (default: 7'd1)
#define __end_tsync0_pen			(15)			// End TSYNC Number for 0th Frame 1 ~ 31 (default: 7'd15)
#define __dmy_tsync_pen				(0)			// Dummy TSYNC Number for Pen's Frame1 (default: 7'd0)

#define __num_pre_pwm				(5)			// Number of Previous PWM Pulse in Finger Mode (default: 8'd5)
#define __num_set_pwm				(1)			// Number of Set PWM Pulse  in Finger Mode (default: 6'd1)
#define __num_act_pwm				(10)			// Number of Active PWM Pulse (default: 8'd20)
#endif /* USED_REPORTRATE_120HZ */

#define __num_din_pwm				(0)			// Number of PWM Pulse for Digital Integration (default: 6'd10)
#define __num_fgr1_act_pwm			(6)			// Number of Active PWM Pulse at Finger MUX-Pen Mode (default: 8'd20)
#define __num_fgr1_din_pwm			(0)			// Number of PWM Pulse at Digital Integration at Finger MUX-Pen Mode (default: 6'd10)
#define __num_pen_act_pwm			(8)			// Number of Active PWM Pulse at Pen Position Mux (default: 8'd40)
#define __num_pen_din_pwm			(0)			// Number of PWM Pulse at Digital Integration Pen Position Mux (default: 6'd20)
#define __num_data_act_pwm			(7)			// Number of Active PWM Pulse at Pen Data Mux (default: 8'd40)
#define __num_data_din_pwm			(0)			// Number of PWM Pulse at Digital Integration Pen Data Mux (default: 6'd10)
#define __num_fgr1_set_pwm			(1)			// Number of Set PWM Pulse at Finger MUX-Pen Mode (default: 6'd1)
#define __num_pen_set_pwm			(1)			// Number of Set PWM Pulse at Pen Position MUX (default: 5'd1)
#define __num_data_set_pwm			(1)			// Number of Set PWM Pulse at Pen Data MUX (default: 5'd1)

//#define __str_cmux					(0)			// Start Channel Mux (0 ~ 10) (default: 5'd0)
//#define __end_cmux					(11)			// End Channel Mux (1 ~ 11) (default: 5'd11)
//#define __end_row					(47)			// End Row for Bottom Outer Sensor (0 ~ 48) (default: 6'd47)
#if USED_REPORTRATE_120HZ
#define __num_frg0_cmux				(2)			// Number of CMUX in a Tsync for Finger Mode (default : 4'd1)
#define __num_frg1_cmux				(2)			// Number of CMUX in a Tsync for Finger Mux of Pen Mode (default : 4'd2)
#define __num_pen_cmux				(2)			// Number of CMUX in a Tsync for Position Mux of Pen Mode (default : 4'd1)
#define __num_data_cmux				(4)			// Number of CMUX in a Tsync for Data Mux of Pen Mode (default : 4'd1)
#else /* USED_REPORTRATE_120HZ */
#define __num_frg0_cmux				(1)			// Number of CMUX in a Tsync for Finger Mode (default : 4'd1)
#define __num_frg1_cmux				(2)			// Number of CMUX in a Tsync for Finger Mux of Pen Mode (default : 4'd2)
#define __num_pen_cmux				(1)			// Number of CMUX in a Tsync for Position Mux of Pen Mode (default : 4'd1)
#define __num_data_cmux				(1)			// Number of CMUX in a Tsync for Data Mux of Pen Mode (default : 4'd1)
#endif /* USED_REPORTRATE_120HZ */

//#define __chip0_len					(56)			// Chip 0 Aligned Sensing Buffer Length ( Default 7'd96)
//#define __str_col					(0)			// Start Column (0 ~ 5) (default: 5'd16)
//#define __end_col					(6)			// End Column (1 ~ 12) (default: 5'd5)
//#define __col_len0					(7)			// Column Length for RAIT0 (default: 5'd19)
//#define __dg_inner					(6)			// Digital Gain for Inner (0 ~ 3.984375) (default: 8'h6, / 1.0)
//#define __dg_side					(6)			// Digital Gain for Side (0 ~ 3.984375) (default: 8'h6 / 1.0)
//#define __dg_top					(6)			// Digital Gain for Top (0 ~ 3.984375) (default: 8'h6 / 1.0)
//#define __dg_bottom					(6)			// Digital Gain for Bottom (0 ~ 3.984375) (default: 8'h6 / 1.0)
//#define __dg_t_vertex				(6)			// Digital Gain for Top Vertex (0 ~ 3.984375) (default: 8'h6 / 1.0)
//#define __dg_b_vertex				(6)			// Digital Gain for Bottom Vertex (0 ~ 3.984375) (default: 8'h6 / 1.0)
//
//#define __nih_cado					(0)			// Noise index Histogram calibrated ADC Output Selected (default 1'b0)
//#define __self_td_th				(32)			// Touch Detect Threshold value (default: 9'd32)
//#define __self_td_sel				(8)			// Noise Index Range Selected for Self Touch Detect Mode (default: 4'b1000)
//#define __self_td_or				(0)			// Self Touch Monitoring - 1: Or Mode 0: And Mode (default: 1'b0)
//
//#define __sha_str					(20)			// SHA Clock Start cycle from pwm low counter end (default: 10'd48 / 17 for 12 MHz)
//#define __rstp_width				(4)			// RSTP high width(default: 8'd2), should be bigger than 2
//#define __vcr_str					(4)			// Charge Remover Start Cycle from pwm_tx rising edge (default: 1'b0)
//#define __vcr_ena 					(1)			// Charge Remover Enable (default: 1'b1)
//#define __vcr_hperiod				(6)			// Charge Remover Half Period (1 MHz, 12/1/2=6, Even Number) (default: 8'd6)
//
//#define __vcr_p_num					(4)			// Charge Remover Pulse Number - Master (default: 4'd4)
//#define __vcr2_md					(1)			// VCR 2 Mode select (default: 1'b1)
//#define __vcr2_str_dly				(2)			// VCR 2 Start Delay (default: 8'd2)
//
//#define __vcr2_phtcr_hiw			(4)			// VCR2 PHTCR High Width (default: 9'd20)
//#define __phth0_width				(1)			// PHTH0 rising edge from Rising edge of TX_PWM (default: 10'd1)
//#define __phth1_width				(8)			// PHTH1 High Width frem negative edge of TX_PWM (default: 10'd4)
//#define __itg_sha_run				(8)			// ITG_SHA_RUN Width ( default : 8'h3)
//#define __sha_run					(16)			// HI/LO_SHA_RUN Width (default : 4)
//
//#define __rstp_dly1					(1)			// Delay from PHTH0 Falling Edge to RSTP Rising Edge (1~4Clk)
//#define __rstp_dly2					(1)			// Delay from PHTH0 Falling Edge to RSTP Rising Edge (1~4Clk)
//
//#define __rsti_dly1					(10)			// PHT0 Delay for SHA
//#define __rsti_dly2					(0)			// Delay from PHT0 Falling Edge to RSTI Rising Edge (1~8Clk)
//
//#define __ssu_on_row				(3)			// SSU Power On Row (default: 2'b11) [4] LV_SSU_PDB  /  [5] HV_SSU_PDB
//
//#define __pow_sel					(0)			// pow_sel Control (default : 0)
//
//#define __sbuf_cp_ena				(1)			// Sensing Buffer Copy Enable (default: 1)
//
//#define __tsyncn_bypass				(0)			// TsyncN Bypass (defautl: 1'b0), "L" = Used Internal Tsync, "H" = PAD_Tsyncn(bypass)
//#define __rstp_high					(0)			// RSTP high debugging mode (default:1'b0)
//#define __adc_rst					(0)			// ADC Reset Control 1: ADC Data Out =12'h0 (default: 1'b0)
//
//#define __cr_tgl_off				(0)			// Charge Remover Signal toggle off (default: 0)
//
//#define __lv_ssu_on					(4095)		// Low Voltage SSU (Column) Enable by S/W (default: 12'b1111_1111_1111) (sw_power_ena = "H" ½A active)
//#define __hv_ssu_on					(4095)		// High Voltage SSU (Column) Enable by S/W (default: 12'b1111_1111_1111) (sw_power_ena = "H" ½A active)

#if 1
#define __ssu_cr_mx00_i_ROIC0		{1, 1, 1, 1, 1, 1}//{3, 3, 3, 3, 3, 3}			// SSU MUX00 Inner SSU fine charge remover cap selection (default :4'b0101) (0000:NC, 0001:0.833pF, 0010:1.08pF, 0010:1.913pF, 0100:1.17pF, 0101:2.003pF, 0110:2.25pF. 0111:3.083pF)
#define __ssu_cr_mx02_i_ROIC0		{1, 1, 1, 1, 1, 1}//{2, 2, 2, 2, 2, 2}			// SSU MUX02 Inner SSU fine charge remover cap selection (default :4'b0101)
#define __ssu_cr_mx04_i_ROIC0		{1, 1, 1, 1, 1, 1}//{1, 2, 1, 1, 1, 1}			// SSU MUX04 Inner SSU fine charge remover cap selection (default :4'b0101)
#define __ssu_cr_mx06_i_ROIC0		{1, 1, 1, 1, 1, 1}//{1, 1, 1, 1, 0, 1}			// SSU MUX06 Inner SSU fine charge remover cap selection (default 4'b0101)
#define __ssu_cr_mx08_i_ROIC0		{1, 1, 1, 1, 1, 1}//{0, 1, 0, 0, 0, 0}			// SSU MUX08 Inner SSU fine charge remover cap selection (default :3'b101)
#define	__ssu_cr_mx10_i_ROIC0		{1, 1, 1, 1, 1, 1}			// SSU MUX10 Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx12_i_ROIC0		(4)			// MUX12(Noise Index1) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx13_i_ROIC0		(4)			// MUX13(Noise Index2) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx14_i_ROIC0		(4)			// MUX14(Noise Index3) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx15_i_ROIC0		(4)			// MUX15(Noise Index4) Inner SSU fine charge remover cap selection (default :3'b101)

#define __ssu_cr_mx00_i_ROIC1		{1, 1, 1, 1, 1, 1}//{3, 3, 3, 3, 3, 3}			// SSU MUX00 Inner SSU fine charge remover cap selection (default :4'b0101) (0000:NC, 0001:0.833pF, 0010:1.08pF, 0010:1.913pF, 0100:1.17pF, 0101:2.003pF, 0110:2.25pF. 0111:3.083pF)
#define __ssu_cr_mx02_i_ROIC1		{1, 1, 1, 1, 1, 1}//{2, 2, 2, 1, 2, 2}			// SSU MUX02 Inner SSU fine charge remover cap selection (default :4'b0101)
#define __ssu_cr_mx04_i_ROIC1		{1, 1, 1, 1, 1, 1}//{2, 1, 1, 1, 1, 1}			// SSU MUX04 Inner SSU fine charge remover cap selection (default :4'b0101)
#define __ssu_cr_mx06_i_ROIC1		{1, 1, 1, 1, 1, 1}//{1, 0, 0, 0, 1, 1}			// SSU MUX06 Inner SSU fine charge remover cap selection (default 4'b0101)
#define __ssu_cr_mx08_i_ROIC1		{1, 1, 1, 1, 1, 1}//{1, 0, 0, 0, 0, 0}			// SSU MUX08 Inner SSU fine charge remover cap selection (default :3'b101)
#define	__ssu_cr_mx10_i_ROIC1		{1, 1, 1, 1, 1, 1}			// SSU MUX10 Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx12_i_ROIC1		(4)			// MUX12(Noise Index1) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx13_i_ROIC1		(4)			// MUX13(Noise Index2) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx14_i_ROIC1		(4)			// MUX14(Noise Index3) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx15_i_ROIC1		(4)			// MUX15(Noise Index4) Inner SSU fine charge remover cap selection (default :3'b101)

#define __ssu_cr_left0_R0			{1, 1, 1, 1, 1, 1}			// SSU Left CRC → Left 0 (default: 1'b0)
#define __ssu_cr_left1_R0			{1, 1, 1, 1, 1, 1}			// SSU Left CRC → Left 1 (default: 1'b0)
#define __ssu_cr_right0_R0			{1, 1, 1, 1, 1, 1}			// SSU Right CRC → Right 0 (default: 1'b0)
#define __ssu_cr_right1_R0			{1, 1, 1, 1, 1, 1}			// SSU Right CRC → Right 1 (default: 1'b0)
#define __ssu_cr_left0_R1			{1, 1, 1, 1, 1, 1}			// SSU Left CRC → Left 0 (default: 1'b0)
#define __ssu_cr_left1_R1			{1, 1, 1, 1, 1, 1}			// SSU Left CRC → Left 1 (default: 1'b0)
#define __ssu_cr_right0_R1			{1, 1, 1, 1, 1, 1}			// SSU Right CRC → Right 0 (default: 1'b0)
#define __ssu_cr_right1_R1			{1, 1, 1, 1, 1, 1}			// SSU Right CRC → Right 1 (default: 1'b0)
#define __rep_cr_i					(0)			// Setting 1st Mux Inner Charge Remover Cap to representative Cap for all mux (default :1'b0)
#define __rep_cr_e					(0)			// Setting 1st Mux Eged Charge Remover Cap to representative Cap for all mux (default :1'b0)
#define __fg0_int_half				(0)			// SSU Integrator Sampling Cap Select in Finger Mode (0:INT_GCx1, 1: INT_GCx1/2) (default : 1'b0)
#define __fg1_int_half				(0)			// SSU Integrator Sampling Cap Select in Finger MUX of Pen Mode (0:INT_GCx1, 1: INT_GCx1/2) (default : 1'b0)
#define __pen_int_half				(0)			// SSU Integrator Sampling Cap Select in Position (0:INT_GCx1, 1: INT_GCx1/2) (default : 1'b0)
#define __data_int_half				(0)			// SSU Integrator Sampling Cap Select in Data MUX  (0:INT_GCx1, 1: INT_GCx1/2) (default : 1'b0)
#define __ni_int_half				(0)			// SSU Integrator Sampling Cap Select in Noise Index Mode  (0:INT_GCx1, 1: INT_GCx1/2) (default : 1'b0)
#define __ssu_pre_gc_ni				(2)			// Noise Index Mux Pre Amp Feedback Cap Select (default : 2'b10)
#define __ssu_int_gc_ni				(2)			// Noise Index Mux Integrator Gain Select (default : 2'b10)

#define __ssu_cr_mx00_e_ROIC0		{1, 1, 1, 1, 1, 1}//{5, 4, 4, 4, 4, 4}//{5, 4, 4, 4, 4, 4}//{0, 0, 0, 0, 0, 0}//{3, 3, 3, 3, 2, 3}			// SSU MUX00 Edge SSU fine charge remover cap selection (default :3'b101) (0000:NC, 0001:0.833pF, 0010:1.08pF, 0010:1.913pF, 0100:1.17pF, 0101:2.003pF, 0110:2.25pF. 0111:3.083pF)
#define __ssu_cr_mx02_e_ROIC0		{1, 1, 1, 1, 1, 1}//{3, 3, 3, 2, 3, 3}//{3, 3, 3, 2, 3, 3}//{0, 0, 0, 0, 0, 0}//{2, 2, 2, 2, 1, 2}			// SSU MUX02 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx04_e_ROIC0		{1, 1, 1, 1, 1, 1}//{2, 1, 2, 1, 2, 2}//{2, 1, 2, 1, 2, 2}//{0, 0, 0, 0, 0, 0}//{1, 1, 1, 1, 1, 1}			// SSU MUX04 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx06_e_ROIC0		{1, 1, 1, 1, 1, 1}//{2, 1, 1, 1, 1, 1}//{2, 1, 1, 1, 1, 1}//{0, 0, 0, 0, 0, 0}//{1, 1, 0, 0, 0, 1}			// SSU MUX06 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx08_e_ROIC0		{1, 1, 1, 1, 1, 1}//{1, 1, 0, 0, 1, 0}//{1, 1, 0, 0, 1, 0}//{0, 0, 0, 0, 0, 0}//{1, 0, 0, 0, 0, 0}			// SSU MUX08 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx10_e_ROIC0		{1, 1, 1, 1, 1, 1}//{2, 1, 1, 0, 1, 2}//{2, 1, 1, 0, 1, 2}//{0, 0, 0, 0, 0, 0}//{1, 0, 0, 0, 0, 0}			// SSU MUX10 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx12_e_ROIC0		(4)			// MUX12(Noise Index1) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx13_e_ROIC0		(4)			// MUX13(Noise Index2) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx14_e_ROIC0		(4)			// MUX14(Noise Index3) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx15_e_ROIC0		(4)			// MUX15(Noise Index4) Edge SSU fine charge remover cap selection (default :3'b101)

#define __ssu_cr_mx00_e_ROIC1		{1, 1, 1, 1, 1, 1}//{6, 4, 4, 4, 4, 6}//{6, 4, 4, 4, 4, 6}//{0, 0, 0, 0, 0, 0}//{3, 3, 3, 3, 3, 4}			// SSU MUX00 Edge SSU fine charge remover cap selection (default :3'b101) (0000:NC, 0001:0.833pF, 0010:1.08pF, 0010:1.913pF, 0100:1.17pF, 0101:2.003pF, 0110:2.25pF. 0111:3.083pF)
#define __ssu_cr_mx02_e_ROIC1		{1, 1, 1, 1, 1, 1}//{4, 3, 3, 3, 3, 4}//{4, 3, 3, 3, 3, 4}//{0, 0, 0, 0, 0, 0}//{2, 2, 2, 2, 2, 2}			// SSU MUX02 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx04_e_ROIC1		{1, 1, 1, 1, 1, 1}//{3, 3, 2, 2, 2, 2}//{3, 3, 2, 2, 2, 2}//{0, 0, 0, 0, 0, 0}//{1, 1, 1, 1, 1, 2}			// SSU MUX04 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx06_e_ROIC1		{1, 1, 1, 1, 1, 1}//{2, 2, 1, 2, 1, 2}//{2, 2, 1, 2, 1, 2}//{0, 0, 0, 0, 0, 0}//{1, 0, 0, 0, 1, 1}			// SSU MUX06 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx08_e_ROIC1		{1, 1, 1, 1, 1, 1}//{1, 1, 1, 2, 1, 1}//{1, 1, 1, 2, 1, 1}//{0, 0, 0, 0, 0, 0}//{1, 0, 0, 0, 0, 1}			// SSU MUX08 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx10_e_ROIC1		{1, 1, 1, 1, 1, 1}//{0, 0, 0, 2, 1, 1}//{0, 0, 0, 2, 1, 1}//{0, 0, 0, 0, 0, 0}//{0, 0, 0, 0, 0, 1}			// SSU MUX10 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx12_e_ROIC1		(4)			// MUX12(Noise Index1) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx13_e_ROIC1		(4)			// MUX13(Noise Index2) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx14_e_ROIC1		(4)			// MUX14(Noise Index3) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx15_e_ROIC1		(4)			// MUX15(Noise Index4) Edge SSU fine charge remover cap selection (default :3'b101)
#else
#define __ssu_cr_mx00_i_ROIC0	{	4		,	5		,	4		,	4		,	4		,	4		}
#define __ssu_cr_mx02_i_ROIC0	{	3		,	3		,	3		,	3		,	3		,	3		}
#define __ssu_cr_mx04_i_ROIC0	{	2		,	2		,	2		,	2		,	2		,	2		}
#define __ssu_cr_mx06_i_ROIC0	{	1		,	1		,	1		,	1		,	1		,	1		}
#define __ssu_cr_mx08_i_ROIC0	{	0		,	0		,	1		,	0		,	1		,	0		}
#define	__ssu_cr_mx10_i_ROIC0	{	0		,	1		,	1		,	0		,	1		,	0		}


//#define __ssu_cr_mx00_i_ROIC0		{5, 4, 4, 4, 4, 4}//{0, 0, 0, 0, 0, 0}//{3, 3, 3, 3, 3, 3}			// SSU MUX00 Inner SSU fine charge remover cap selection (default :4'b0101) (0000:NC, 0001:0.833pF, 0010:1.08pF, 0010:1.913pF, 0100:1.17pF, 0101:2.003pF, 0110:2.25pF. 0111:3.083pF)
//#define __ssu_cr_mx02_i_ROIC0		{3, 3, 3, 3, 3, 3}//{0, 0, 0, 0, 0, 0}//{2, 2, 2, 2, 2, 2}			// SSU MUX02 Inner SSU fine charge remover cap selection (default :4'b0101)
//#define __ssu_cr_mx04_i_ROIC0		{2, 2, 2, 2, 2, 2}//{0, 0, 0, 0, 0, 0}//{1, 2, 1, 1, 1, 1}			// SSU MUX04 Inner SSU fine charge remover cap selection (default :4'b0101)
//#define __ssu_cr_mx06_i_ROIC0		{1, 1, 1, 1, 2, 1}//{0, 0, 0, 0, 0, 0}//{1, 1, 1, 1, 0, 1}			// SSU MUX06 Inner SSU fine charge remover cap selection (default 4'b0101)
//#define __ssu_cr_mx08_i_ROIC0		{1, 1, 1, 1, 1, 1}//{0, 0, 0, 0, 0, 0}//{0, 1, 0, 0, 0, 0}			// SSU MUX08 Inner SSU fine charge remover cap selection (default :3'b101)
//#define	__ssu_cr_mx10_i_ROIC0		{1, 1, 1, 1, 1, 1}//{0, 0, 0, 0, 0, 0}			// SSU MUX10 Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx12_i_ROIC0		(4)			// MUX12(Noise Index1) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx13_i_ROIC0		(4)			// MUX13(Noise Index2) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx14_i_ROIC0		(4)			// MUX14(Noise Index3) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx15_i_ROIC0		(4)			// MUX15(Noise Index4) Inner SSU fine charge remover cap selection (default :3'b101)

#define __ssu_cr_mx00_i_ROIC1		{	5		,	4		,	4		,	4		,	4		,	4		}
#define __ssu_cr_mx02_i_ROIC1		{	3		,	3		,	3		,	3		,	3		,	3		}
#define __ssu_cr_mx04_i_ROIC1		{	2		,	2		,	2		,	2		,	2		,	2		}
#define __ssu_cr_mx06_i_ROIC1		{	1		,	1		,	1		,	1		,	1		,	1		}
#define __ssu_cr_mx08_i_ROIC1		{	1		,	1		,	0		,	0		,	1		,	1		}
#define	__ssu_cr_mx10_i_ROIC1		{	1		,	1		,	0		,	0		,	0		,	1		}

//#define __ssu_cr_mx00_i_ROIC1		{5, 4, 4, 4, 4, 4}//{0, 0, 0, 0, 0, 0}//{3, 3, 3, 3, 3, 3}			// SSU MUX00 Inner SSU fine charge remover cap selection (default :4'b0101) (0000:NC, 0001:0.833pF, 0010:1.08pF, 0010:1.913pF, 0100:1.17pF, 0101:2.003pF, 0110:2.25pF. 0111:3.083pF)
//#define __ssu_cr_mx02_i_ROIC1		{3, 3, 3, 3, 3, 3}//{0, 0, 0, 0, 0, 0}//{2, 2, 2, 1, 2, 2}			// SSU MUX02 Inner SSU fine charge remover cap selection (default :4'b0101)
//#define __ssu_cr_mx04_i_ROIC1		{2, 2, 2, 2, 2, 2}//{0, 0, 0, 0, 0, 0}//{2, 1, 1, 1, 1, 1}			// SSU MUX04 Inner SSU fine charge remover cap selection (default :4'b0101)
//#define __ssu_cr_mx06_i_ROIC1		{1, 1, 1, 1, 1, 1}//{0, 0, 0, 0, 0, 0}//{1, 0, 0, 0, 1, 1}			// SSU MUX06 Inner SSU fine charge remover cap selection (default 4'b0101)
//#define __ssu_cr_mx08_i_ROIC1		{1, 1, 1, 1, 1, 2}//{0, 0, 0, 0, 0, 0}//{1, 0, 0, 0, 0, 0}			// SSU MUX08 Inner SSU fine charge remover cap selection (default :3'b101)
//#define	__ssu_cr_mx10_i_ROIC1		{1, 1, 1, 1, 1, 1}//{0, 0, 0, 0, 0, 0}			// SSU MUX10 Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx12_i_ROIC1		(4)			// MUX12(Noise Index1) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx13_i_ROIC1		(4)			// MUX13(Noise Index2) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx14_i_ROIC1		(4)			// MUX14(Noise Index3) Inner SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx15_i_ROIC1		(4)			// MUX15(Noise Index4) Inner SSU fine charge remover cap selection (default :3'b101)

#define __ssu_cr_left0_R0			{1, 1, 1, 1, 1, 1}			// SSU Left CRC → Left 0 (default: 1'b0)
#define __ssu_cr_left1_R0			{1, 1, 1, 1, 1, 1}			// SSU Left CRC → Left 1 (default: 1'b0)
#define __ssu_cr_right0_R0			{1, 1, 1, 1, 1, 1}			// SSU Right CRC → Right 0 (default: 1'b0)
#define __ssu_cr_right1_R0			{1, 1, 1, 1, 1, 1}			// SSU Right CRC → Right 1 (default: 1'b0)
#define __ssu_cr_left0_R1			{1, 1, 1, 1, 1, 1}			// SSU Left CRC → Left 0 (default: 1'b0)
#define __ssu_cr_left1_R1			{1, 1, 1, 1, 1, 1}			// SSU Left CRC → Left 1 (default: 1'b0)
#define __ssu_cr_right0_R1			{1, 1, 1, 1, 1, 1}			// SSU Right CRC → Right 0 (default: 1'b0)
#define __ssu_cr_right1_R1			{1, 1, 1, 1, 1, 1}			// SSU Right CRC → Right 1 (default: 1'b0)
#define __rep_cr_i				(0)			// Setting 1st Mux Inner Charge Remover Cap to representative Cap for all mux (default :1'b0)
#define __rep_cr_e				(0)			// Setting 1st Mux Eged Charge Remover Cap to representative Cap for all mux (default :1'b0)
#define __fg0_int_half			(0)			// SSU Integrator Sampling Cap Select in Finger Mode (0:INT_GCx1, 1: INT_GCx1/2) (default : 1'b0)
#define __fg1_int_half			(0)			// SSU Integrator Sampling Cap Select in Finger MUX of Pen Mode (0:INT_GCx1, 1: INT_GCx1/2) (default : 1'b0)
#define __pen_int_half			(0)			// SSU Integrator Sampling Cap Select in Position (0:INT_GCx1, 1: INT_GCx1/2) (default : 1'b0)
#define __data_int_half			(0)			// SSU Integrator Sampling Cap Select in Data MUX  (0:INT_GCx1, 1: INT_GCx1/2) (default : 1'b0)
#define __ni_int_half			(0)			// SSU Integrator Sampling Cap Select in Noise Index Mode  (0:INT_GCx1, 1: INT_GCx1/2) (default : 1'b0)
#define __ssu_pre_gc_ni			(2)			// Noise Index Mux Pre Amp Feedback Cap Select (default : 2'b10)
#define __ssu_int_gc_ni			(2)			// Noise Index Mux Integrator Gain Select (default : 2'b10)

#define __ssu_cr_mx00_e_ROIC0		{5, 4, 4, 4, 4, 4}//{5, 4, 4, 4, 4, 4}//{0, 0, 0, 0, 0, 0}//{3, 3, 3, 3, 2, 3}			// SSU MUX00 Edge SSU fine charge remover cap selection (default :3'b101) (0000:NC, 0001:0.833pF, 0010:1.08pF, 0010:1.913pF, 0100:1.17pF, 0101:2.003pF, 0110:2.25pF. 0111:3.083pF)
#define __ssu_cr_mx02_e_ROIC0		{3, 3, 3, 2, 3, 3}//{3, 3, 3, 2, 3, 3}//{0, 0, 0, 0, 0, 0}//{2, 2, 2, 2, 1, 2}			// SSU MUX02 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx04_e_ROIC0		{2, 1, 2, 1, 2, 2}//{2, 1, 2, 1, 2, 2}//{0, 0, 0, 0, 0, 0}//{1, 1, 1, 1, 1, 1}			// SSU MUX04 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx06_e_ROIC0		{2, 1, 1, 1, 1, 1}//{2, 1, 1, 1, 1, 1}//{0, 0, 0, 0, 0, 0}//{1, 1, 0, 0, 0, 1}			// SSU MUX06 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx08_e_ROIC0		{1, 1, 0, 0, 1, 0}//{1, 1, 0, 0, 1, 0}//{0, 0, 0, 0, 0, 0}//{1, 0, 0, 0, 0, 0}			// SSU MUX08 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx10_e_ROIC0		{2, 1, 1, 0, 1, 2}//{2, 1, 1, 0, 1, 2}//{0, 0, 0, 0, 0, 0}//{1, 0, 0, 0, 0, 0}			// SSU MUX10 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx12_e_ROIC0		(4)			// MUX12(Noise Index1) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx13_e_ROIC0		(4)			// MUX13(Noise Index2) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx14_e_ROIC0		(4)			// MUX14(Noise Index3) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx15_e_ROIC0		(4)			// MUX15(Noise Index4) Edge SSU fine charge remover cap selection (default :3'b101)

#define __ssu_cr_mx00_e_ROIC1		{6, 4, 4, 4, 4, 6}//{6, 4, 4, 4, 4, 6}//{0, 0, 0, 0, 0, 0}//{3, 3, 3, 3, 3, 4}			// SSU MUX00 Edge SSU fine charge remover cap selection (default :3'b101) (0000:NC, 0001:0.833pF, 0010:1.08pF, 0010:1.913pF, 0100:1.17pF, 0101:2.003pF, 0110:2.25pF. 0111:3.083pF)
#define __ssu_cr_mx02_e_ROIC1		{4, 3, 3, 3, 3, 4}//{4, 3, 3, 3, 3, 4}//{0, 0, 0, 0, 0, 0}//{2, 2, 2, 2, 2, 2}			// SSU MUX02 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx04_e_ROIC1		{3, 3, 2, 2, 2, 2}//{3, 3, 2, 2, 2, 2}//{0, 0, 0, 0, 0, 0}//{1, 1, 1, 1, 1, 2}			// SSU MUX04 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx06_e_ROIC1		{2, 2, 1, 2, 1, 2}//{2, 2, 1, 2, 1, 2}//{0, 0, 0, 0, 0, 0}//{1, 0, 0, 0, 1, 1}			// SSU MUX06 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx08_e_ROIC1		{1, 1, 1, 2, 1, 1}//{1, 1, 1, 2, 1, 1}//{0, 0, 0, 0, 0, 0}//{1, 0, 0, 0, 0, 1}			// SSU MUX08 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx10_e_ROIC1		{0, 0, 0, 2, 1, 1}//{0, 0, 0, 2, 1, 1}//{0, 0, 0, 0, 0, 0}//{0, 0, 0, 0, 0, 1}			// SSU MUX10 Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx12_e_ROIC1		(4)			// MUX12(Noise Index1) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx13_e_ROIC1		(4)			// MUX13(Noise Index2) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx14_e_ROIC1		(4)			// MUX14(Noise Index3) Edge SSU fine charge remover cap selection (default :3'b101)
#define __ssu_cr_mx15_e_ROIC1		(4)			// MUX15(Noise Index4) Edge SSU fine charge remover cap selection (default :3'b101)
#endif

/*
 * NOTE : SRIC에서 Mux Remap은 (0, 2, 4, 6, 8, 10) Index만 Regsiger가 동작을 하고 나머지 Index는 동작을 하지 않는다고함
 * 이유 : 교차 Mux구조로 가면서 두개가 하나의 Register로 동작하게끔 컨셉이 변경이 되었지만, 실제 Register수정은 시간관계상 이루어 지지 않았다고함.
 * 주의 : 아래 Remap Register를 동작시키기 위해서는 CFGR_MD_GENERAL0_b.cmux_remap 을 1로 enable시켜야함.
 */
//
#define __remap_mx00				(5)			// Channel Mux 0 remap (default :4'd1)
#define __remap_mx02				(4)			// Channel Mux 2 remap (default :4'd3)
#define __remap_mx04				(3)			// Channel Mux 4 remap (default :4'd5)
#define __remap_mx06				(2)			// Channel Mux 6 remap (default :4'd7)
#define __remap_mx08				(1)			// Channel Mux 8 remap (default :4'd9)
#define __remap_mx10				(0)			// Channel Mux 10 remap (default :4'd11)
//#define __remap_mx01				2			// Channel Mux 1 remap (default :4'd2)
//#define __remap_mx03				4			// Channel Mux 3 remap (default :4'd4)
//#define __remap_mx05				6			// Channel Mux 5 remap (default :4'd6)
//#define __remap_mx07				8			// Channel Mux 7 remap (default :4'd8)
//#define __remap_mx09				10			// Channel Mux 9 remap (default :4'd10)
//#define __remap_mx11				12			// Channel Mux 11 remap (default :4'd12)

#define __sm_enable					(0)			// Share Mode Enable (default : 0)
#define __spi_rd_back				(0)			// SPI Command Read Back - Write (Address, Command, Data ...), Read (Address, Data,...) (default : 0)
#define __pad_ds_miso				(0)			// MISO Drive Strength (default : 0)
#define __adc_in_ctrl				(1)			// adc_in control Optioin - (default :0) (0 : DRD , 1 : nDRD)
#define __d_local_position			(0)			// Local Sensing Position Selec (default : 6'd0) , max:5'd20
#define __md_pen					(0)			// Pen Sensing Mode (default : 2'd0) 0: Finger mode, 1: Pen-Finger mode, 2: Pen Position-Data mode, 3: Pen Data Mode - It Can be updated using auxillary write command (only bulk read with address of 0x0000)
#define __pen_data_dc				(0)			// Enable Pen Data DC Enable during Position Sensing Time for VCOM-DC mode (default : 1'b0)
#define __tg_local_position			(0)			// TG Local Sensing Position Select (Read Only)
#define __tg_md_pen					(0)			// TG Pen Sensing Mode (Read Only)

#define __pen0_tsycn0				(0)			// MUX Type of 0th TSYCN for Pen-Finger mode (default : 2'b0) (0 : Not Used, 1 : Finger, 2: Pen Position, 3 : Pen Data)
#define __pen0_tsycn1				(0)			// MUX Type of 1st TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn2				(0)			// MUX Type of 2nd TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn3				(0)			// MUX Type of 3rd TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn4				(0)			// MUX Type of 4th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn5				(0)			// MUX Type of 5th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn6				(0)			// MUX Type of 6th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn7				(0)			// MUX Type of 7th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn8				(0)			// MUX Type of 8th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn9				(0)			// MUX Type of 9th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn10				(0)			// MUX Type of 10th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn11				(0)			// MUX Type of 11th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn12				(0)			// MUX Type of 12th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn13				(0)			// MUX Type of 13th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn14				(0)			// MUX Type of 14th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn15				(0)			// MUX Type of15th TSYCN for Pen-Finger mode (default : 2'b0)

#define __pen0_tsycn16				(0)			// MUX Type of 16th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn17				(0)			// MUX Type of 17th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn18				(0)			// MUX Type of 18th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn19				(0)			// MUX Type of 19th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn20				(0)			// MUX Type of 20th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn21				(0)			// MUX Type of 21th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn22				(0)			// MUX Type of 22th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn23				(0)			// MUX Type of 23th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn24				(0)			// MUX Type of 24th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn25				(0)			// MUX Type of 25th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn26				(0)			// MUX Type of 26th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn27				(0)			// MUX Type of 27th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn28				(0)			// MUX Type of 28th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn29				(0)			// MUX Type of 29th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn30				(0)			// MUX Type of 30th TSYCN for Pen-Finger mode (default : 2'b0)
#define __pen0_tsycn31				(0)			// MUX Type of 31th TSYCN for Pen-Finger mode (default : 2'b0)

#define __num_bcon_act_pwm			(0)			// Number of Active PWM Pulse (default: 8'd20)
#define __num_bcon_set_pwm			(0)			// Number of Set PWM Pulse  in Finger Mode (default: 6'd1)


/*
 * TODO : 아래 값은 위와 같이 개별 값으로 변경해야함!!
 */
#define R_PRODUCT_ED			(0x1910)				/*	0			0x300			0x1910		*/
#define R_SNSR_STR				(0x0000)				/*	2			0x302			0x0000		*/
#if USED_REPORTRATE_120HZ
// 2 MUX
//#define R_MD_GENERAL0			(0xC050)				/*	4			0x304			0xC050		*/
//#define R_AIP_ADC				(0x0D3F)				/*	6			0x306			0x1D3F		*/
#if USED_NOT_USE_AFE_OFF
#define __R_AIP_ADC_bgr_ena			(1)			// Block Reference BIAS Generator Enable 1: Enable (default: 1)
#define __R_AIP_ADC_bgr_ena_auto	(1)			// BGR_EN Automatic Control(default : 1b'1)
#define __R_AIP_ADC_lv_ssu_bias_on	(1)			// Low Voltage SSU BIAS Enable S/W(default : 1b'1)
#define __R_AIP_ADC_hv_ssu_bias_on	(1)			// High Voltage SSU BIAS Enable S/W(default : 1b'1)
#define __R_AIP_ADC_adc_on			(1)			// ADC Enable by S/W (default: 1)
#define __R_AIP_ADC_sw_power_ena	(1)			// S/W PDB Selected For ADC/SSU (default : 1b'0, 1 : enable, 0 : Disable)
#define __R_AIP_ADC_adc_bcon		(1)			// ADC BIAS Control 0 : 12uA, 1: 16uA, 2:20uA, 3 : 24uA(default : 2'b01)
#define __R_AIP_ADC_adc_freq		(3)			// ADC Input Clock Selection (default : 1'b11)      -  0 : 4MHz, 1 : 4.8MHz, 2 : 6MHz, 3 : 8MHz @ 24MHz
												// -  0 : 2MHz, 1 : 2.4MHz, 2 : 3Hz,   3 : 4MHz @ 12MHz
#define __R_AIP_ADC_adc_fast_clk	(0)			// ADC Input Clock is 6 MHz(750k SPS) 12MHz(1.5M SPS With 24MHz ECLK, forbidden)(default : 1'b1)
#define __R_AIP_ADC_adc_wdiv		(0)			// ADC input range control, 0: External, 1 : internal(default : 1'b0)
#define __R_AIP_ADC_adc_int_stc		(0)			// ADC STC Selection 0: External 1: Internal (default : 1'b0)
#else /* USED_NOT_USE_AFE_OFF */
#define __R_AIP_ADC_bgr_ena			(1)			// Block Reference BIAS Generator Enable 1: Enable (default: 1)
#define __R_AIP_ADC_bgr_ena_auto	(1)			// BGR_EN Automatic Control(default : 1b'1)
#define __R_AIP_ADC_lv_ssu_bias_on	(1)			// Low Voltage SSU BIAS Enable S/W(default : 1b'1)
#define __R_AIP_ADC_hv_ssu_bias_on	(1)			// High Voltage SSU BIAS Enable S/W(default : 1b'1)
#define __R_AIP_ADC_adc_on			(1)			// ADC Enable by S/W (default: 1)
#define __R_AIP_ADC_sw_power_ena	(0)			// S/W PDB Selected For ADC/SSU (default : 1b'0, 1 : enable, 0 : Disable)
#define __R_AIP_ADC_adc_bcon		(1)			// ADC BIAS Control 0 : 12uA, 1: 16uA, 2:20uA, 3 : 24uA(default : 2'b01)
#define __R_AIP_ADC_adc_freq		(3)			// ADC Input Clock Selection (default : 1'b11)      -  0 : 4MHz, 1 : 4.8MHz, 2 : 6MHz, 3 : 8MHz @ 24MHz
												// -  0 : 2MHz, 1 : 2.4MHz, 2 : 3Hz,   3 : 4MHz @ 12MHz
#define __R_AIP_ADC_adc_fast_clk	(0)			// ADC Input Clock is 6 MHz(750k SPS) 12MHz(1.5M SPS With 24MHz ECLK, forbidden)(default : 1'b1)
#define __R_AIP_ADC_adc_wdiv		(0)			// ADC input range control, 0: External, 1 : internal(default : 1'b0)
#define __R_AIP_ADC_adc_int_stc		(0)			// ADC STC Selection 0: External 1: Internal (default : 1'b0)

#endif /* USED_NOT_USE_AFE_OFF */

//#define R_SSU_CTRL				(0x0309)//(0x3339)				/*	8			0x308			0x3339		*/
#define __CFGR_SSU_CTRL_int_ref			(1)		// Integrator Reference Voltage Selection (default : 2'b01) 0:0.5Vm 1: 0.7V, 2: 0.9V, 3: 0.9V, 4: 1.1V
#define __CFGR_SSU_CTRL_sha_ref			(2)		// SHA Referen Voltage Selection (default :2'10) 0: 0.80V, 1: 0.85V, 2:0.90V, 3: 0.95V
#define __CFGR_SSU_CTRL_lv_ssu_bcon		(0)		// Low Voltage SSI BIAS(Integrator) Current Control(default : 3'b011) 000 : 2.5uA, 001 : 5uA, 101 : 7.5uA, 011 : 10uA,  100 :12.5uA, 101 : 15uA, 110 : 17.5uA, 111 : 20uA
#define __CFGR_SSU_CTRL_lv_ssu_bcons	(3)		// Low Voltage SSI BIAS(SHA) Current Control(default : 3'b011) 000 : 2.5uA, 001 : 5uA, 101 : 7.5uA, 011 : 10uA,  100 :12.5uA, 101 : 15uA, 110 : 17.5uA, 111 : 20uA
#define __CFGR_SSU_CTRL_hv_ssu_bcon		(0)		// High Voltage Ssu BIAS (Preamp) Current Control (default : 3'b011) 000 : 5uA, 001 : 10uA, 101 : 15uA, 011 : 20uA,  100 : 25uA, 101 : 30uA, 110 : 35uA, 111 : 40uA

//#define R_TSYNC_NUM0			(0x0601)				/*	10			0x30A			0x0600		*/
//#define R_TSYNC_NUM1			(0x0602)				/*	12			0x30C			0x0600		*/
//#define R_TSYNC_DMMY			(0x0001)				/*	14			0x30E			0x0000		*/
//#define R_TSYNC_NUM_PEN 		(0x0F01)				/*	16			0x310			0x0F01		*/
//#define R_TSYNC_DMMY_PEN		(0x0000)				/*	18			0x312			0x0000		*/
//#define R_PWM_NUM0				(0x0402)				/*	20			0x314			0x0105		*/
//#define R_PWM_NUM1				(0x0A08)				/*	22			0x316			0x0A14		*/
//#define R_PWM_NUM2				(0x0A14)				/*	24			0x318			0x0A14		*/
//#define R_PWM_NUM3				(0x1428)				/*	26			0x31A			0x1428		*/
//#define R_PWM_NUM4				(0x0A28)				/*	28			0x31C			0x0A28		*/
//#define R_PWM_NUM5				(0x0841)				/*	30			0x31E			0x0841		*/
#define R_CMUX_NORM 			(0xBD60)				/*	32			0x320			0xBD60		*/
//#define R_CMUX_NUM_PEN			(0x1E22)				/*	34			0x322			0x1E22		*/
//#define R_CMUX_NUM				(0x1121)				/*	36			0x324			0x1121		*/
#define R_CHIP0_LEN 			(0x0038)				/*	38			0x326			0x0060		*/
#define R_COL_NUM				(0x1CC0)				/*	40			0x328			0xCCB0		*/
#else /* USED_REPORTRATE_120HZ */
// 1 MUX
//#define R_MD_GENERAL0			(0xC048)				/*	4			0x304			0xC050		*/
//#define R_AIP_ADC				(0x0D3D)//0x0D7F				/*	6			0x306			0x1D3F		*/
#define __R_AIP_ADC_bgr_ena			(1)			// Block Reference BIAS Generator Enable 1: Enable (default: 1)
#define __R_AIP_ADC_bgr_ena_auto	(0)			// BGR_EN Automatic Control(default : 1b'1)
#define __R_AIP_ADC_lv_ssu_bias_on	(1)			// Low Voltage SSU BIAS Enable S/W(default : 1b'1)
#define __R_AIP_ADC_hv_ssu_bias_on	(1)			// High Voltage SSU BIAS Enable S/W(default : 1b'1)
#define __R_AIP_ADC_adc_on			(1)			// ADC Enable by S/W (default: 1)
#define __R_AIP_ADC_sw_power_ena	(0)			// S/W PDB Selected For ADC/SSU (default : 1b'0, 1 : enable, 0 : Disable)
#define __R_AIP_ADC_adc_bcon		(1)			// ADC BIAS Control 0 : 12uA, 1: 16uA, 2:20uA, 3 : 24uA(default : 2'b01)
#define __R_AIP_ADC_adc_freq		(3)			// ADC Input Clock Selection (default : 1'b11)      -  0 : 4MHz, 1 : 4.8MHz, 2 : 6MHz, 3 : 8MHz @ 24MHz
												// -  0 : 2MHz, 1 : 2.4MHz, 2 : 3Hz,   3 : 4MHz @ 12MHz
#define __R_AIP_ADC_adc_fast_clk	(0)			// ADC Input Clock is 6 MHz(750k SPS) 12MHz(1.5M SPS With 24MHz ECLK, forbidden)(default : 1'b1)
#define __R_AIP_ADC_adc_wdiv		(0)			// ADC input range control, 0: External, 1 : internal(default : 1'b0)
#define __R_AIP_ADC_adc_int_stc		(0)			// ADC STC Selection 0: External 1: Internal (default : 1'b0)

//#define R_SSU_CTRL				(0x3339)				/*	8			0x308			0x3339		*/
#define __CFGR_SSU_CTRL_int_ref			(1)		// Integrator Reference Voltage Selection (default : 2'b01) 0:0.5Vm 1: 0.7V, 2: 0.9V, 3: 0.9V, 4: 1.1V
#define __CFGR_SSU_CTRL_sha_ref			(2)		// SHA Referen Voltage Selection (default :2'10) 0: 0.80V, 1: 0.85V, 2:0.90V, 3: 0.95V
#define __CFGR_SSU_CTRL_lv_ssu_bcon		(3)		// Low Voltage SSI BIAS(Integrator) Current Control(default : 3'b011) 000 : 2.5uA, 001 : 5uA, 101 : 7.5uA, 011 : 10uA,  100 :12.5uA, 101 : 15uA, 110 : 17.5uA, 111 : 20uA
#define __CFGR_SSU_CTRL_lv_ssu_bcons	(3)		// Low Voltage SSI BIAS(SHA) Current Control(default : 3'b011) 000 : 2.5uA, 001 : 5uA, 101 : 7.5uA, 011 : 10uA,  100 :12.5uA, 101 : 15uA, 110 : 17.5uA, 111 : 20uA
#define __CFGR_SSU_CTRL_hv_ssu_bcon		(3)		// High Voltage Ssu BIAS (Preamp) Current Control (default : 3'b011) 000 : 5uA, 001 : 10uA, 101 : 15uA, 011 : 20uA,  100 : 25uA, 101 : 30uA, 110 : 35uA, 111 : 40uA

//#define R_TSYNC_NUM0			(0x0601)				/*	10			0x30A			0x0600		*/
//#define R_TSYNC_NUM1			(0x0601)				/*	12			0x30C			0x0600		*/
//#define R_TSYNC_DMMY			(0x0003)				/*	14			0x30E			0x0000		*/
//#define R_TSYNC_NUM_PEN 		(0x0F01)				/*	16			0x310			0x0F01		*/
//#define R_TSYNC_DMMY_PEN		(0x0000)				/*	18			0x312			0x0000		*/
//#define R_PWM_NUM0				(0x0105)				/*	20			0x314			0x0105		*/
//#define R_PWM_NUM1				(0x000A)				/*	22			0x316			0x0A14		*/
//#define R_PWM_NUM2				(0x0A14)				/*	24			0x318			0x0A14		*/
//#define R_PWM_NUM3				(0x1428)				/*	26			0x31A			0x1428		*/
//#define R_PWM_NUM4				(0x0A28)				/*	28			0x31C			0x0A28		*/
//#define R_PWM_NUM5				(0x0841)				/*	30			0x31E			0x0841		*/
#define R_CMUX_NORM 			(0xBD60)				/*	32			0x320			0xBD60		*/
//#define R_CMUX_NUM_PEN			(0x1E22)				/*	34			0x322			0x1E22		*/
//#define R_CMUX_NUM				(0x1121)				/*	36			0x324			0x1121		*/
#define R_CHIP0_LEN 			(0x0038)				/*	38			0x326			0x0060		*/
#define R_COL_NUM				(0x1CC0)				/*	40			0x328			0xCCB0		*/
#endif /* USED_REPORTRATE_120HZ */

#define R_OUTER 				(0x0600)				/*	42			0x32A			0x0600		*/
#define R_DIG_GAIN0 			(0x0606)				/*	44			0x32C			0x0606		*/
#define R_DIG_GAIN1 			(0x0606)				/*	46			0x32E			0x0606		*/
#define R_DIG_GAIN2 			(0x0606)				/*	48			0x330			0x0606		*/
#define R_RSVD0 				(0x0000)				/*	50			0x332			0x0000		*/
#define R_NIH_MIN0				(0x03E8)				/*	52			0x334			0x03E8		*/
#define R_NIH_MAX0				(0x044C)				/*	54			0x336			0x044C		*/
#define R_NIH_MIN1				(0x07D0)				/*	56			0x338			0x07D0		*/
#define R_NIH_MAX1				(0x0834)				/*	58			0x33A			0x0834		*/
#define R_NIH_MIN2				(0x0BB8)				/*	60			0x33C			0x0BB8		*/
#define R_NIH_MAX2				(0x0C1C)				/*	62			0x33E			0x0C1C		*/
#define R_NIH_MIN3				(0x0FA0)				/*	64			0x340			0x0FA0		*/
#define R_NIH_MAX3				(0x0FFF)				/*	66			0x342			0x0FFF		*/
#define R_NIH_RDAT0 			(0x0000)				/*	68			0x344			0x0000		*/
#define R_NIH_RDAT1 			(0x0000)				/*	70			0x346			0x0000		*/
#define R_NIH_RDAT2 			(0x0000)				/*	72			0x348			0x0000		*/
#define R_NIH_RDAT3 			(0x0000)				/*	74			0x34A			0x0000		*/
#define R_NIH_STD				(0x2040)				/*	76			0x34C			0x2040		*/

#if (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_91K)
//#define R_SHA_STR				(0x001B)//(0x0030)				/*	78			0x34E			0x0030		*/
#define CFGR_SHA_STR_sha_str		(27)
//#define R_RSTP_WIDTH			(0x0008)//(0x0018)				/*	80			0x350			0x0002		*/
#define CFGR_RSTP_WIDTH_rstp_width	(8)
//#define R_VCR_STR				(0x0696)//(0x0684)				/*	82			0x352			0x0680		*/
#define CFGR_VCR_STR_vcr_str		(22)//(22)//(22)//(22)
#define CFGR_VCR_STR_vcr_ena		(1)
#define CFGR_VCR_STR_vcr_hperiod	(6)

//#define R_VCR2_MD				(0x0414)//(0x0214)				/*	84			0x354			0x0214		*/
#define CFGR_VCR2_MD_vcr_p_num		(1)//(4)
#define CFGR_VCR2_MD_vcr2_md		(1)
#define CFGR_VCR2_MD_vcr2_str_dly	(4)

//#define R_VCR2_PHTCR			(0x0008)//(0x0004)				/*	86			0x356			0x0014		*/
#define CFGR_VCR2_PHTCR_vcr2_phtcr_hiw	(8)

//#define R_PHTH0_WIDTH			(0x0001)				/*	88			0x358			0x0001		*/
#define CFGR_PHTH0_WIDTH_phth0_width	(1)

//#define R_PHTH1_WIDTH			(0x0027)//(0x0021)				/*	90			0x35A			0x0004		*/
#define CFGR_PHTH1_WIDTH_phth1_width	(39)

//#define R_SHA_RUN				(0x0B08)//(0x1008)				/*	92			0x35C			0x0403		*/
#define CFGR_SHA_RUN_itg_sha_run	(8)
#define CFGR_SHA_RUN_sha_run		(11)

//#define R_RSTP_DLY1 			(0x0101)				/*	94			0x35E			0x0101		*/
#define CFGR_RSTP_DLY1_rstp_dly1 	(1)
#define CFGR_RSTP_DLY1_rstp_dly2	(1)

//#define R_RSTP_DLY2 			(0x0102)//(0x000A)				/*	96			0x360			0x011F		*/
#define CFGR_RSTP_DLY2_rsti_dly1	(2)
#define CFGR_RSTP_DLY2_rsti_dly2	(1)

#else /* (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_91K) */
#define R_SHA_STR				(0x0019)				/*	78			0x34E			0x0030		*/
#define R_RSTP_WIDTH			(0x0006)				/*	80			0x350			0x0002		*/
#define R_VCR_STR				(0x068A)				/*	82			0x352			0x0680		*/
#define R_VCR2_MD				(0x0314)				/*	84			0x354			0x0214		*/
#define R_VCR2_PHTCR			(0x0006)				/*	86			0x356			0x0014		*/
#define R_PHTH0_WIDTH			(0x0001)				/*	88			0x358			0x0001		*/
#define R_PHTH1_WIDTH			(0x0018)				/*	90			0x35A			0x0004		*/
#define R_SHA_RUN				(0x0B06)				/*	92			0x35C			0x0403		*/
#define R_RSTP_DLY1 			(0x0101)				/*	94			0x35E			0x0101		*/
#define R_RSTP_DLY2 			(0x0104)				/*	96			0x360			0x011F		*/
#endif /* (PWMDRV_USED_FREQUENCY == PWMDRV_FREQUENCY_91K) */

#define R_TEST_OPT				(0x0230)				/*	98			0x362			0x0230		*/
#define R_LV_SSU_ON 			(0x0FFF)				/*	100			0x364			0x0FFF		*/
#define R_HV_SSU_ON 			(0x0FFF)				/*	102			0x366			0x0FFF		*/
//#define R_SSU_PRE_GC			(0xAAAA)				/*	126			0x37E			0xAAAA		*/
#define __ssu_pre_gc_fgr0		(2)//(2)		// 0:2.67pF, 1:4.45pF, 2:6.97pF, 3:8.01pF
#define __ssu_pre_gc_fgr1		(2)
#define __ssu_pre_gc_pen		(2)
#define __ssu_pre_gc_data		(2)
#define __ssu_int_gc_fgr0		(2)//(2)		// 0:0.414pF, 1:1.241pF, 2:2.177pF, 3:3.004pF
#define __ssu_int_gc_fgr1		(2)
#define __ssu_int_gc_pen		(2)
#define __ssu_int_gc_data		(2)

#define R_PWM_NUM_NI			(0x0004)				/*	134			0x386			0x0004		*/
#define R_CMUX_NI1				(0x0555)				/*	136			0x388			0x0555		*/
#define R_CMUX_NI2				(0x0AAA)				/*	138			0x38A			0x0AAA		*/
#define R_CMUX_NI3				(0x0555)				/*	140			0x38C			0x0555		*/
#define R_CMUX_NI4				(0x0AAA)				/*	142			0x38E			0x0AAA		*/
//#define R_AFE_DUM				(0x0010)				/*	144			0x390			0x0000		*/
#define __AFE_DUM_sm_enable		(0)			// Share Mode Enable (default : 0)
#define __AFE_DUM_spi_rd_back	(0)			// SPI Command Read Back - Write (Address, Command, Data ...), Read (Address, Data,...) (default : 0)
#define __AFE_DUM_pad_ds_miso	(0)			// MISO Drive Strength (default : 0)
#define __AFE_DUM_adc_in_ctrl	(1)			// adc_in control Optioin - (default :0) (0 : DRD , 1 : nDRD)

#define R_MD_IDLE				(0x0000)				/*	146			0x392			0x0000		*/
#define R_PEN_CTRL				(0x0000)				/*	148			0x394			0x0000		*/
#define R_HALF_COPY 			(0x0000)				/*	150			0x396			0x0000		*/
#define R_PEN_0_TSYNC0			(0x0000)				/*	152			0x398			0x0000		*/
#define R_PEN_0_TSYNC1			(0x0000)				/*	154			0x39A			0x0000		*/
#define R_PEN_0_TSYNC2			(0x0000)				/*	156			0x39C			0x0000		*/
#define R_PEN_0_TSYNC3			(0x0000)				/*	158			0x39E			0x0000		*/
#define R_FSM_MON0				(0x0003)				/*	160			0x3A0			0x0000		*/
#define R_FSM_MON1				(0x0000)				/*	162			0x3A2			0x0000		*/
#define R_BEACON_PWM0			(0x0000)				/*	164			0x3A4			0x0114		*/


#endif /* _CUSTOM_SRIC_FINGER_H_ */
