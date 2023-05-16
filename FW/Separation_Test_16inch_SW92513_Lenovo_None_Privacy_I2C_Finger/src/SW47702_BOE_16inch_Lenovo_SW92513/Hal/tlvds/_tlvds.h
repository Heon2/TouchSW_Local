/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _gdma.h
 * created on : 05. 9. 2018
* Author : HongTK
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

#ifndef __TLVDS_H_
#define __TLVDS_H_

typedef union
{
    struct {
        unsigned    mst_start:                 1;
        unsigned    reserved:                  31;
    } tBit;
    __IO uint32_t ulBulk;
} t_TLVDS_CTRL;

typedef union
{
    struct {
        unsigned    tcsn0_pdb:                 1;
        unsigned    tcsn1_pdb:                 1;
        unsigned    tclk0_pdb:                 1;
        unsigned    tclk1_pdb:                 1;
        unsigned    tdat0_pdb:                 1;
        unsigned    tdat1_pdb:                 1;
        unsigned    rclk0_pdb:                 1;
        unsigned    rclk1_pdb:                 1;
        unsigned    rclk2_pdb:                 1;
        unsigned    rclk3_pdb:                 1;
        unsigned    rdat0_pdb:                 1;
        unsigned    rdat1_pdb:                 1;
        unsigned    rdat2_pdb:                 1;
        unsigned    rdat3_pdb:                 1;
        unsigned    tcsn0_drv:                 1;
        unsigned    tcsn1_drv:                 1;
        unsigned    tclk0_drv:                 1;
        unsigned    tclk1_drv:                 1;
        unsigned    tdat0_drv:                 1;
        unsigned    tdat1_drv:                 1;
        unsigned    reserved:                  12;
    } tBit;
    __IO uint32_t ulBulk;
} t_TLVDS_PHY_STUCK_CR;

typedef union
{
    struct {
        unsigned    tcsn0_pdb:                 1;
        unsigned    tcsn1_pdb:                 1;
        unsigned    tclk0_pdb:                 1;
        unsigned    tclk1_pdb:                 1;
        unsigned    tdat0_pdb:                 1;
        unsigned    tdat1_pdb:                 1;
        unsigned    rclk0_pdb:                 1;
        unsigned    rclk1_pdb:                 1;
        unsigned    rclk2_pdb:                 1;
        unsigned    rclk3_pdb:                 1;
        unsigned    rdat0_pdb:                 1;
        unsigned    rdat1_pdb:                 1;
        unsigned    rdat2_pdb:                 1;
        unsigned    rdat3_pdb:                 1;
        unsigned    tcsn0_drv:                 1;
        unsigned    tcsn1_drv:                 1;
        unsigned    tclk0_drv:                 1;
        unsigned    tclk1_drv:                 1;
        unsigned    tdat0_drv:                 1;
        unsigned    tdat1_drv:                 1;
        unsigned    reserved:                  12;
    } tBit;
    __IO uint32_t ulBulk;
} t_TLVDS_PHY_STUCK_VALUE;

typedef union
{
    struct {
    	unsigned    t1:						   6;
    	unsigned    t2:                        6;
        unsigned    t2_1:                      6;
        unsigned    t3:                        6;
        unsigned    reserved:                  8;
    } tBit;
    __IO uint32_t ulBulk;
} t_INTERVAL_CR;

//typedef union
//{
//    struct {
//    	unsigned    int_tx_done_clr:						   6;
//    	unsigned    t2:                        6;
//        unsigned    t2_1:                      6;
//        unsigned    t3:                        6;
//        unsigned    reserved:                  8;
//    } tBit;
//    __IO uint32_t ulBulk;
//} t_TLVDS_RESERVED00;

typedef union
{
    struct {
        unsigned    pdb_time:                  8;
        unsigned    drv_time:                  8;
        unsigned    off_time:                  5;
        unsigned    reserved:                  11;
    } tBit;
    __IO uint32_t ulBulk;
} t_AFE_ON_TIME;

typedef union
{
    struct {
        unsigned    rx0_cnt:                   5;
        unsigned    rx1_cnt:                   5;
        unsigned    rx2_cnt:                   5;
        unsigned    rx3_cnt:                   5;
        unsigned    reserved:                  12;
    } tBit;
    __IO uint32_t ulBulk;
} t_RX_STATUS;

typedef union
{
    struct {
        unsigned    tlvds_fsm:                 4;
        unsigned    bulk_cnt:                  8;
        unsigned    sric_cnt:                  4;
        unsigned    int_tx_done:               1;
        unsigned    int_rx_done:               1;
        unsigned    int_sric_ready:            1;
        unsigned    int_mux_done:              1;
        unsigned    int_fr_done:               1;
        unsigned    int_chksum_rx3:            1;
        unsigned    int_chksum_rx2:            1;
        unsigned    int_chksum_rx1:            1;
        unsigned    int_chksum_rx0:            1;
        unsigned    reserved:                  7;
    } tBit;
    __IO uint32_t ulBulk;
} t_TLVDS_STATUS;

typedef union
{
    struct {
        unsigned    int_tx_done_clr:           1;		// write done
        unsigned    int_rx_done_clr:           1;		// read done
        unsigned    int_sric_ready_clr:        1;		// sample & ADC done per one MUX
        unsigned    int_mux_done_clr:          1;		//
        unsigned    int_fr_done_clr:           1;		// all MUX done
        unsigned    int_chksum_clr:            1;		// checksum err
        unsigned    reserved:                  26;
    } tBit;
    __IO uint32_t ulBulk;
} t_INT_CLR;

typedef union
{
    struct {
        unsigned    int_tx_done_en:            1;
        unsigned    int_rx_done_en:            1;
        unsigned    int_sric_ready_en:         1;
        unsigned    int_mux_done_en:           1;
        unsigned    int_fr_done_en:            1;
        unsigned    int_chksum_en:             1;
        unsigned    int_sric_ready_mask_en:	   1;
        unsigned    reserved:                  25;
    } tBit;
    __IO uint32_t ulBulk;
} t_INT_EN;

typedef union
{
    struct {
        unsigned    tx_en:                     1;
        unsigned    tr_en:                     1;
        unsigned    bulk_en:                   1;
        unsigned    bulk_num:                  8;
        unsigned    checksum_en:               1;
        unsigned    int_mux_done_sel:          1;
        unsigned    reserved:                  19;
    } tBit;
    __IO uint32_t ulBulk;
} t_TLVDS_CR1;

typedef union
{
    struct {
        unsigned    tx_lsb_first_en:           1;
        unsigned    rx_lsb_first_en:           1;
        unsigned    header_len:                2;
        unsigned    header_num:                3;
        unsigned    rdmy_len:                  1;
        unsigned    wdmy_len:                  1;
        unsigned    ait_mode:                  1;
        unsigned    buf_mode:                  1;
        unsigned    sense_done_sel:            2;
        unsigned    wdata_len:                 1;
        unsigned    rdata_len:                 2;
        unsigned    tx_number:                 2;
        unsigned    rx_number:                 2;
        unsigned    mem_addr_clr:              1;
        unsigned    tx0_on:                    1;
        unsigned    tx1_on:                    1;
        unsigned    rx0_on:                    1;
        unsigned    rx1_on:                    1;
        unsigned    rx2_on:                    1;
        unsigned    rx3_on:                    1;
        unsigned    reserved:                  5;
    } tBit;
    __IO uint32_t ulBulk;
} t_TLVDS_CR2;

typedef union
{
    struct {
        unsigned    trdy_smpl_dly:             8;
        unsigned    mask_dly:                  6;
        unsigned    reserved:                  18;
    } tBit;
    __IO uint32_t ulBulk;
} t_TLVDS_DLY;

typedef union
{
    struct {
        unsigned    sric_number:               4;
        unsigned    buf_number:                3;
        unsigned    mux_number:                7;
        unsigned    tdat_pdn_pre_num:		   3;
        unsigned    tdat_drv_pre_num:   	   3;
        unsigned    reserved:                  12;
    } tBit;
    __IO uint32_t ulBulk;
} t_TLVDS_CR3;

typedef union
{
    struct {
        unsigned    TCSN0:               	   1;
        unsigned    TXCLK0:                	   1;
        unsigned    TDAT0:                	   1;
        unsigned    TCSN1:		   			   1;
        unsigned    TXCLK1:   	   			   1;
        unsigned    TDAT1:               	   1;
        unsigned    RXCLK0:                	   1;
        unsigned    RDAT0:                	   1;
        unsigned    RXCLK1:                	   1;
        unsigned    RDAT1:                	   1;
        unsigned    RXCLK2:                	   1;
        unsigned    RDAT2:                	   1;
        unsigned    RXCLK3:                	   1;
        unsigned    RDAT3:                	   1;
        unsigned    reserved:                  18;
    } tBit;
    __IO uint32_t ulBulk;
} t_TLVDS_INV_CR;

typedef union
{
    struct {
        unsigned    tlvds_findex0:             7;
        unsigned    reserved0:                 1;
        unsigned    tlvds_findex1:             7;
        unsigned    reserved1:                 1;
        unsigned    tlvds_findex2:             7;
        unsigned    reserved2:                 1;
        unsigned    tlvds_findex3:             7;
        unsigned    reserved3:                 1;
    } tBit;
    __IO uint32_t ulBulk;
} t_TLVDS_FINDEX0;

typedef union
{
    struct {
        unsigned    tlvds_findex4:             7;
        unsigned    reserved4:                 1;
        unsigned    tlvds_findex5:             7;
        unsigned    reserved5:                 1;
        unsigned    tlvds_findex6:             7;
        unsigned    reserved6:                 1;
        unsigned    tlvds_findex7:             7;
        unsigned    reserved7:                 1;
    } tBit;
    __IO uint32_t ulBulk;
} t_TLVDS_FINDEX1;

typedef struct
{
    __O  t_TLVDS_CTRL                TLVDS_CTRL;                     //0x0000
    __IO t_TLVDS_PHY_STUCK_CR        TLVDS_PHY_STUCK_CR;             //0x0001
    __IO t_TLVDS_PHY_STUCK_VALUE     TLVDS_PHY_STUCK_VALUE;          //0x0002
    __IO t_INTERVAL_CR               INTERVAL_CR;                    //0x0003
    __IO uint32_t                    TLVDS_RESERVED00;               //0x0004
    __IO uint32_t                    TLVDS_RESERVED01;               //0x0005
    __IO uint32_t                    TLVDS_RESERVED02;               //0x0006
    __IO uint32_t                    TLVDS_RESERVED03;               //0x0007
    __IO uint32_t                    TX0_ST_ADDR;                    //0x0008
    __IO uint32_t                    TX1_ST_ADDR;                    //0x0009
    __IO uint32_t                    RX0_ST_ADDR;                    //0x000A
    __IO uint32_t                    RX1_ST_ADDR;                    //0x000B
    __IO uint32_t                    RX2_ST_ADDR;                    //0x000C
    __IO uint32_t                    RX3_ST_ADDR;                    //0x000D
    __IO t_AFE_ON_TIME               AFE_ON_TIME;                    //0x000E
    __I  t_RX_STATUS                 RX_STATUS;                      //0x000F
    __I  t_TLVDS_STATUS              TLVDS_STATUS;                   //0x0010
    __O  t_INT_CLR                   INT_CLR;                        //0x0011
    __IO t_INT_EN                    INT_EN;                         //0x0012
    __IO t_TLVDS_CR1                 TLVDS_CR1;                      //0x0013
    __IO t_TLVDS_CR2                 TLVDS_CR2;                      //0x0014
    __IO t_TLVDS_DLY                 TLVDS_DLY;                      //0x0015
    __IO t_TLVDS_CR3                 TLVDS_CR3;                      //0x0016
    __IO t_TLVDS_INV_CR				 TLVDS_INV_CR;                   //0x0017
    __IO t_TLVDS_FINDEX0             TLVDS_FINDEX0;                  //0x0018
    __IO t_TLVDS_FINDEX1             TLVDS_FINDEX1;                  //0x0019

} tTLVDS_CtrlReg_t ;

#endif /* __TLVDS_H_ */
