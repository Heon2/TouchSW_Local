//-------------------------------------------------------
//-   Register Structure Auto Generation                 
//-------------------------------------------------------


#ifndef __LX98405_CONF_H_
#define __LX98405_CONF_H_
#include "lx98405_param_configset_roic.h"
#include "lx98405_parameter_set.h"

//#if (USED_ROIC_DEF == ROIC_LX98405)

//#define LX98405_MODE_FINGER1         (0)
//#define LX98405_MODE_FINGER2         (1)
//#define LX98405_MODE_DUMMY           (3)

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
        __IO uint32_t tg_clk_on                  : 1  ;
        __IO uint32_t cfclk_on                   : 1  ;
        __IO uint32_t spis_chksum_opt            : 1  ;
        __IO uint32_t spis_irq_en                : 1  ;
        __IO uint32_t tlvds_chksum_inv           : 1  ;
        __IO uint32_t tlvds_irq_en               : 1  ;
        __IO uint32_t tlvds_sclk_on              : 1  ;
        __IO uint32_t tlvds_sclk_to_data         : 1  ;
        __IO uint32_t tlvds_op_case              : 2  ;
        __IO uint32_t rbuf_addr_bit_md0          : 2  ;
        __IO uint32_t rbuf_addr_bit_md1          : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tINTERFACE_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t miso_ds                    : 1  ;
        __IO uint32_t miso_dout                  : 1  ;
        __IO uint32_t miso_func                  : 2  ;
        __IO uint32_t mosi_ds                    : 1  ;
        __IO uint32_t mosi_dout                  : 1  ;
        __IO uint32_t mosi_func                  : 2  ;
        __IO uint32_t tst_out0_out               : 1  ;
        __IO uint32_t tst_out0_oe                : 1  ;
        __IO uint32_t tst_out0_ds                : 1  ;
        __IO uint32_t tst_out0_func              : 1  ;
        __IO uint32_t tst_out0_sel0              : 1  ;
        __IO uint32_t tst_out0_sel1              : 1  ;
        __IO uint32_t tst_out0_func2             : 3  ;
        __IO uint32_t tst_out0_test              : 1  ;
        __IO uint32_t tst_out1_out               : 1  ;
        __IO uint32_t tst_out1_oe                : 1  ;
        __IO uint32_t tst_out1_ds                : 1  ;
        __IO uint32_t tst_out1_func              : 1  ;
        __IO uint32_t tst_out1_sel0              : 1  ;
        __IO uint32_t tst_out1_sel1              : 1  ;
        __IO uint32_t tst_out1_func2             : 3  ;
        __IO uint32_t tst_out1_test              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSPIS_PAD_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t tlvds_vod_ctrl             : 4  ;
        __IO uint32_t tlvds_vocm_ctrl            : 2  ;
        __IO uint32_t tlvds_rx_bcon              : 4  ;
        __IO uint32_t tlvds_rext_en              : 1  ;
        __IO uint32_t tlvds_vocm_sel             : 1  ;
        __IO uint32_t pdb_tlvds_bias             : 1  ;
        __IO uint32_t pdb_tlvds_mcsn_ctl         : 1  ;
        __IO uint32_t pdb_tlvds_mclk_ctl         : 2  ;
        __IO uint32_t pdb_tlvds_mdat_ctl         : 2  ;
        __IO uint32_t pdb_tlvds_sclk_ctl         : 2  ;
        __IO uint32_t pdb_tlvds_sdat_ctl         : 2  ;
        __IO uint32_t pdb_tlvds_eclk             : 1  ;
        __IO uint32_t pdb_tlvds_pwm_tx_ctl       : 2  ;
        __IO uint32_t eclk_sel                   : 1  ;
        __IO uint32_t pwm_tx_sel                 : 1  ;
        __IO uint32_t tlvds_sclk_en_ctl          : 2  ;
        __IO uint32_t tlvds_sdat_en_ctl          : 2  ;
        __IO uint32_t tlvds_pattern_en           : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tLVDS_PHY_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t tlvds_dum0                 : 32 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tTLVDS_DUM0_t;


typedef union
{
    struct
    {
        __IO uint32_t tlvds_dum1                 : 32 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tTLVDS_DUM1_t;


typedef union
{
    struct
    {
        __IO uint32_t reset_one_write_en         : 1  ;
        __IO uint32_t sw_reset                   : 1  ;
        __IO uint32_t tg_reset                   : 1  ;
        __IO uint32_t buf_reset                  : 1  ;
        __IO uint32_t chksum_clr                 : 1  ;
        __IO uint32_t tsync_pwm_fault_clr        : 1  ;
        __IO uint32_t defend_option              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSYS_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t vsync_pol                  : 1  ;
        __IO uint32_t vsync_tg_en                : 1  ;
        __IO uint32_t vsync_tg_act               : 1  ;
        __IO uint32_t tsync_in_pol               : 1  ;
        __IO uint32_t pwm_pol                    : 1  ;
        __IO uint32_t sd_rocen                   : 1  ;
        __IO uint32_t sd_off_ctl                 : 2  ;
        __IO uint32_t sd_float_0_ctl             : 2  ;
        __IO uint32_t sd_float_1_ctl             : 2  ;
        __IO uint32_t sd_gnd_0_ctl               : 2  ;
        __IO uint32_t sd_gnd_1_ctl               : 2  ;
        __IO uint32_t r0_ropd                    : 1  ;
        __IO uint32_t r1_ropd                    : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSDIC_CFG_t;

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
        __IO uint32_t ch_tot_num                 : 5  ;
        __IO uint32_t roic_tsync_num             : 6  ;
        __IO uint32_t mux_st_num                 : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tCH_MUX_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t md0_tot_mux_num            : 4  ;
        __IO uint32_t md1_tot_mux_num            : 4  ;
        __IO uint32_t md0_lhb_mux_num            : 4  ;
        __IO uint32_t md1_lhb_mux_num            : 4  ;
        __IO uint32_t md0_freq_sel               : 1  ;
        __IO uint32_t md1_freq_sel               : 1  ;
        __IO uint32_t nd_freq_sel                : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tLHB_MUX_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t md0_pwm_dum_num            : 5  ;
        __IO uint32_t md0_pwm_act_num            : 5  ;
        __IO uint32_t md0_pwm_mgap_num           : 5  ;
        __IO uint32_t md1_pwm_dum_num            : 5  ;
        __IO uint32_t md1_pwm_act_num            : 5  ;
        __IO uint32_t md1_pwm_mgap_num           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMD_PWM_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t md0_mux_00                 : 4  ;
        __IO uint32_t md0_mux_01                 : 4  ;
        __IO uint32_t md0_mux_02                 : 4  ;
        __IO uint32_t md0_mux_03                 : 4  ;
        __IO uint32_t md0_mux_04                 : 4  ;
        __IO uint32_t md0_mux_05                 : 4  ;
        __IO uint32_t md0_mux_06                 : 4  ;
        __IO uint32_t md0_mux_07                 : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMD0_MUX_CFG_00_t;

typedef union
{
    struct
    {
        __IO uint32_t md0_mux_08                 : 4  ;
        __IO uint32_t md0_mux_09                 : 4  ;
        __IO uint32_t md0_mux_10                 : 4  ;
        __IO uint32_t md0_mux_11                 : 4  ;
        __IO uint32_t md0_mux_12                 : 4  ;
        __IO uint32_t md0_mux_13                 : 4  ;
        __IO uint32_t md1_mux_00                 : 4  ;
        __IO uint32_t md1_mux_01                 : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMD0_MUX_CFG_01_t;

typedef union
{
    struct
    {
        __IO uint32_t lhb_mode01                 : 2  ;
        __IO uint32_t lhb_mode02                 : 2  ;
        __IO uint32_t lhb_mode03                 : 2  ;
        __IO uint32_t lhb_mode04                 : 2  ;
        __IO uint32_t lhb_mode05                 : 2  ;
        __IO uint32_t lhb_mode06                 : 2  ;
        __IO uint32_t lhb_mode07                 : 2  ;
        __IO uint32_t lhb_mode08                 : 2  ;
        __IO uint32_t lhb_mode09                 : 2  ;
        __IO uint32_t lhb_mode10                 : 2  ;
        __IO uint32_t lhb_mode11                 : 2  ;
        __IO uint32_t lhb_mode12                 : 2  ;
        __IO uint32_t lhb_mode13                 : 2  ;
        __IO uint32_t lhb_mode14                 : 2  ;
        __IO uint32_t lhb_mode15                 : 2  ;
        __IO uint32_t lhb_mode16                 : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tDEFA_LHB_MCFG00_t;

typedef union
{
    struct
    {
        __IO uint32_t f1_pwm_prd                 : 7  ;
        __IO uint32_t f2_pwm_prd                 : 6  ;
        __IO uint32_t nd_pwm_prd_margin          : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPWM_PRD_t;

typedef union
{
    struct
    {
        __IO uint32_t pwm_mux1_dly               : 2  ;
        __IO uint32_t pwm_mux2_dly               : 2  ;
        __IO uint32_t pwm_mux3_dly               : 2  ;
        __IO uint32_t pwm_mux4_dly               : 2  ;
        __IO uint32_t pwm_mux5_dly               : 2  ;
        __IO uint32_t pwm_mux6_dly               : 2  ;
        __IO uint32_t pwm_mux7_dly               : 2  ;
        __IO uint32_t pwm_mux8_dly               : 2  ;
        __IO uint32_t pwm_mux9_dly               : 2  ;
        __IO uint32_t pwm_mux10_dly              : 2  ;
        __IO uint32_t pwm_mux11_dly              : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPWM_MUX_DLY_PRD_t;

typedef union
{
    struct
    {
        __IO uint32_t cvc1_drv_init              : 1  ;
        __IO uint32_t cvc1_rstp_dum_en           : 1  ;
        __IO uint32_t vcr_dum_en                 : 1  ;
        __IO uint32_t vcr_inv_en                 : 1  ;
        __IO uint32_t phtcr_dum_en               : 1  ;
        __IO uint32_t cvc1_drv_rstp_dly          : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tAFE_SIG_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t f1_cvc1_drv_rise_num       : 3  ;
        __IO uint32_t f1_cvc1_drv_fall_num       : 3  ;
        __IO uint32_t f1_cvc1_drv_d_rise_num     : 7  ;
        __IO uint32_t f1_cvc1_drv_d_fall_num     : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tF1_CVC1_DRV_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t f1_rstp_rise_num           : 7  ;
        __IO uint32_t f1_rstp_fall_num           : 7  ;
        __IO uint32_t f1_pht0_rise_num           : 7  ;
        __IO uint32_t f1_pht0_fall_num           : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tF1_RSTP_PHT_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t f1_phtcr_rise_num          : 7  ;
        __IO uint32_t f1_phtcr_fall_num          : 7  ;
        __IO uint32_t f1_smop_prd                : 5  ;
        __IO uint32_t f1_cr_repeat_num           : 2  ;
        __IO uint32_t f1_vcr_num                 : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tF1_PHTCR_VCR_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t f1_rsti_rise_num           : 7  ;
        __IO uint32_t f1_rsti_fall_num1          : 7  ;
        __IO uint32_t f1_rsti_fall_num2          : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tF1_RSTI_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t f1_phth0_rise_num          : 7  ;
        __IO uint32_t f1_phth0_fall_num          : 7  ;
        __IO uint32_t f1_phth1_rise_num          : 7  ;
        __IO uint32_t f1_phth1_fall_num          : 7  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tF1_PHTH_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t f2_cvc1_drv_rise_num       : 3  ;
        __IO uint32_t f2_cvc1_drv_fall_num       : 3  ;
        __IO uint32_t f2_cvc1_drv_d_rise_num     : 6  ;
        __IO uint32_t f2_cvc1_drv_d_fall_num     : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tF2_CVC1_DRV_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t f2_rstp_rise_num           : 6  ;
        __IO uint32_t f2_rstp_fall_num           : 6  ;
        __IO uint32_t f2_pht0_rise_num           : 5  ;
        __IO uint32_t f2_pht0_fall_num           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tF2_RSTP_PHT_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t f2_phtcr_rise_num          : 6  ;
        __IO uint32_t f2_phtcr_fall_num          : 6  ;
        __IO uint32_t f2_smop_prd                : 4  ;
        __IO uint32_t f2_cr_repeat_num           : 2  ;
        __IO uint32_t f2_vcr_num                 : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tF2_PHTCR_VCR_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t f2_rsti_rise_num           : 5  ;
        __IO uint32_t f2_rsti_fall_num1          : 6  ;
        __IO uint32_t f2_rsti_fall_num2          : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tF2_RSTI_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t f2_phth0_rise_num          : 6  ;
        __IO uint32_t f2_phth0_fall_num          : 5  ;
        __IO uint32_t f2_phth1_rise_num          : 5  ;
        __IO uint32_t f2_phth1_fall_num          : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tF2_PHTH_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t pht_prd                    : 5  ;
        __IO uint32_t pht_opt_inv                : 1  ;
        __IO uint32_t pht_end_time               : 5  ;
        __IO uint32_t pre_pht_sel                : 1  ;
        __IO uint32_t pht_act_pwm_num            : 3  ;
        __IO uint32_t pht_act_pwr_num            : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHT_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t adc_clk_prd                : 2  ;
        __IO uint32_t adc_clk_opt                : 2  ;
        __IO uint32_t adc_clk_pol                : 1  ;
        __IO uint32_t adc_clk_spt                : 1  ;
        __IO uint32_t adc_in_pos                 : 5  ;
        __IO uint32_t adc_st_num                 : 5  ;
        __IO uint32_t adc_clk_num                : 4  ;
        __IO uint32_t adc_clk_st_num             : 5  ;
        __IO uint32_t adc_clk_ctl_opt            : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tADC_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t adc_skip_num               : 4  ;
        __IO uint32_t adc_sgap_num               : 5  ;
        __IO uint32_t adc_act_num                : 5  ;
        __IO uint32_t adc_sm_prd                 : 5  ;
        __IO uint32_t adc_margin                 : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tADC_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t cmfb_init_en               : 1  ;
        __IO uint32_t cmfb_init_fall_num         : 7  ;
        __IO uint32_t adc_rstb_rise_num          : 7  ;
        __IO uint32_t pht2_rise_num              : 5  ;
        __IO uint32_t pht2_fall_num              : 5  ;
        __IO uint32_t adc_eoc_ctl_en             : 1  ;
        __IO uint32_t adc_sm_eoc_prd             : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tADC_CTL3_t;

typedef union
{
    struct
    {
        __IO uint32_t mon_adcdo_en               : 1  ;
        __IO uint32_t qcnt_vcom_th_en            : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tTEST_MUX_CTL_t;

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
        __IO uint32_t r0_buf_cfclk_on            : 1  ;
        __IO uint32_t r0_buf_clk_on              : 1  ;
        __IO uint32_t r0_cfclk_on                : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_AFE_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_ch_dum_drv_en           : 3  ;
        __IO uint32_t r0_ch_en_int               : 6  ;
        __IO uint32_t r0_ch_en_hvc               : 9  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CH_EN_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_double_buf_en           : 1  ;
        __IO uint32_t r0_buf_test_mode           : 1  ;
        __IO uint32_t r0_buf_cnt_ctl_en          : 1  ;
        __IO uint32_t r0_buf_cnt_skip_sel        : 1  ;
        __IO uint32_t r0_buf_cnt_num             : 6  ;
        __IO uint32_t r0_buf_auto_clr            : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_BUF_OPT_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_display_vcomr           : 2  ;
        __IO uint32_t r0_touch_f_vcomr           : 2  ;
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
        __IO uint32_t r0_mux_s_stuck_en          : 1  ;
        __IO uint32_t r0_mux_int_stuck_val       : 5  ;
        __IO uint32_t r0_mux_s_stuck_val         : 11 ;
        __IO uint32_t r0_mux_f_ctl_en            : 1  ;
        __IO uint32_t r0_muxf_inv                : 1  ;
        __IO uint32_t r0_mux_f_stuck_en          : 1  ;
        __IO uint32_t r0_mux_nd_bit_en           : 11 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_MUX_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux1_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux1_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux1_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux1_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux1_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux1_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_RG_MUX1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux2_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux2_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux2_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux2_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux2_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux2_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_RG_MUX2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux3_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux3_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux3_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux3_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux3_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux3_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_RG_MUX3_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux4_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux4_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux4_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux4_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux4_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux4_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_RG_MUX4_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux5_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux5_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux5_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux5_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux5_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux5_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_RG_MUX5_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux6_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux6_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux6_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux6_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux6_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux6_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_RG_MUX6_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux7_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux7_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux7_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux7_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux7_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux7_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_RG_MUX7_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux8_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux8_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux8_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux8_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux8_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux8_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_RG_MUX8_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux9_r1g1            : 5  ;
        __IO uint32_t r0_cr_mux9_r1g2            : 5  ;
        __IO uint32_t r0_cr_mux9_r1g3            : 5  ;
        __IO uint32_t r0_cr_mux9_r2g1            : 5  ;
        __IO uint32_t r0_cr_mux9_r2g2            : 5  ;
        __IO uint32_t r0_cr_mux9_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_RG_MUX9_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux10_r1g1           : 5  ;
        __IO uint32_t r0_cr_mux10_r1g2           : 5  ;
        __IO uint32_t r0_cr_mux10_r1g3           : 5  ;
        __IO uint32_t r0_cr_mux10_r2g1           : 5  ;
        __IO uint32_t r0_cr_mux10_r2g2           : 5  ;
        __IO uint32_t r0_cr_mux10_r2g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_RG_MUX10_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux11_r1g1           : 5  ;
        __IO uint32_t r0_cr_mux11_r1g2           : 5  ;
        __IO uint32_t r0_cr_mux11_r1g3           : 5  ;
        __IO uint32_t r0_cr_mux11_r2g1           : 5  ;
        __IO uint32_t r0_cr_mux11_r2g2           : 5  ;
        __IO uint32_t r0_cr_mux11_r2g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_RG_MUX11_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_muxe_r1g1            : 5  ;
        __IO uint32_t r0_cr_muxe_r1g2            : 5  ;
        __IO uint32_t r0_cr_muxe_r1g3            : 5  ;
        __IO uint32_t r0_cr_muxe_r2g1            : 5  ;
        __IO uint32_t r0_cr_muxe_r2g2            : 5  ;
        __IO uint32_t r0_cr_muxe_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R1G_MUXE_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_muxo_r1g1            : 5  ;
        __IO uint32_t r0_cr_muxo_r1g2            : 5  ;
        __IO uint32_t r0_cr_muxo_r1g3            : 5  ;
        __IO uint32_t r0_cr_muxo_r2g1            : 5  ;
        __IO uint32_t r0_cr_muxo_r2g2            : 5  ;
        __IO uint32_t r0_cr_muxo_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_R1G_MUXO_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_mux1_gtune              : 3  ;
        __IO uint32_t r0_mux2_gtune              : 3  ;
        __IO uint32_t r0_mux3_gtune              : 3  ;
        __IO uint32_t r0_mux4_gtune              : 3  ;
        __IO uint32_t r0_mux5_gtune              : 3  ;
        __IO uint32_t r0_mux6_gtune              : 3  ;
        __IO uint32_t r0_mux7_gtune              : 3  ;
        __IO uint32_t r0_mux8_gtune              : 3  ;
        __IO uint32_t r0_mux9_gtune              : 3  ;
        __IO uint32_t r0_mux10_gtune             : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_GTUNE1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_mux11_gtune             : 3  ;
        __IO uint32_t r0_muxeo_gtune             : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_GTUNE2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux1_row2_gsel       : 1  ;
        __IO uint32_t r0_cr_mux1_row3_gsel       : 1  ;
        __IO uint32_t r0_cr_mux1_row4_gsel       : 1  ;
        __IO uint32_t r0_cr_mux2_row2_gsel       : 1  ;
        __IO uint32_t r0_cr_mux2_row3_gsel       : 1  ;
        __IO uint32_t r0_cr_mux2_row4_gsel       : 1  ;
        __IO uint32_t r0_cr_mux3_row2_gsel       : 1  ;
        __IO uint32_t r0_cr_mux3_row3_gsel       : 1  ;
        __IO uint32_t r0_cr_mux3_row4_gsel       : 1  ;
        __IO uint32_t r0_cr_mux4_row2_gsel       : 1  ;
        __IO uint32_t r0_cr_mux4_row3_gsel       : 1  ;
        __IO uint32_t r0_cr_mux4_row4_gsel       : 1  ;
        __IO uint32_t r0_cr_mux5_row2_gsel       : 1  ;
        __IO uint32_t r0_cr_mux5_row3_gsel       : 1  ;
        __IO uint32_t r0_cr_mux5_row4_gsel       : 1  ;
        __IO uint32_t r0_cr_mux6_row2_gsel       : 1  ;
        __IO uint32_t r0_cr_mux6_row3_gsel       : 1  ;
        __IO uint32_t r0_cr_mux6_row4_gsel       : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_GROUP_SEL1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux7_row2_gsel       : 1  ;
        __IO uint32_t r0_cr_mux7_row3_gsel       : 1  ;
        __IO uint32_t r0_cr_mux7_row4_gsel       : 1  ;
        __IO uint32_t r0_cr_mux8_row2_gsel       : 1  ;
        __IO uint32_t r0_cr_mux8_row3_gsel       : 1  ;
        __IO uint32_t r0_cr_mux8_row4_gsel       : 1  ;
        __IO uint32_t r0_cr_mux9_row2_gsel       : 1  ;
        __IO uint32_t r0_cr_mux9_row3_gsel       : 1  ;
        __IO uint32_t r0_cr_mux9_row4_gsel       : 1  ;
        __IO uint32_t r0_cr_mux10_row2_gsel      : 1  ;
        __IO uint32_t r0_cr_mux10_row3_gsel      : 1  ;
        __IO uint32_t r0_cr_mux10_row4_gsel      : 1  ;
        __IO uint32_t r0_cr_mux11_row2_gsel      : 1  ;
        __IO uint32_t r0_cr_mux11_row3_gsel      : 1  ;
        __IO uint32_t r0_cr_mux11_row4_gsel      : 1  ;
        __IO uint32_t r0_cr_muxeo_row2_gsel      : 1  ;
        __IO uint32_t r0_cr_muxeo_row3_gsel      : 1  ;
        __IO uint32_t r0_cr_muxeo_row4_gsel      : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_GROUP_SEL2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_col2_gsel            : 2  ;
        __IO uint32_t r0_cr_col3_gsel            : 2  ;
        __IO uint32_t r0_cr_col4_gsel            : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_GROUP_SEL3_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_adc_in                  : 30 ;
        __IO uint32_t r0_adc_op_opt              : 1  ;
        __IO uint32_t r0_adc_in_stuck_en         : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_ADC_IN_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_adc_ref_sel             : 2  ;
        __IO uint32_t r0_cvc1_comp               : 1  ;
        __IO uint32_t r0_int_ref                 : 3  ;
        __IO uint32_t r0_sha_ref                 : 3  ;
        __IO uint32_t r0_cvc1_gc                 : 2  ;
        __IO uint32_t r0_cvc2_gc                 : 2  ;
        __IO uint32_t r0_int_gc                  : 2  ;
        __IO uint32_t r0_int_half                : 1  ;
        __IO uint32_t r0_hv_cvc1_bcon            : 3  ;
        __IO uint32_t r0_hv_cvc2_bcon            : 3  ;
        __IO uint32_t r0_lv_int_bcon             : 2  ;
        __IO uint32_t r0_lv_sha_bcon             : 2  ;
        __IO uint32_t r0_ref_bcon                : 1  ;
        __IO uint32_t r0_lv_adc_ref_bcon         : 2  ;
        __IO uint32_t r0_lv_sha_buf_bcon         : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_AFE_SENSE_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_pdb_hvbias              : 1  ;
        __IO uint32_t r0_pdb_hvc                 : 1  ;
        __IO uint32_t r0_pdb_lvbias              : 1  ;
        __IO uint32_t r0_pdb_int                 : 1  ;
        __IO uint32_t r0_pdb_sha                 : 1  ;
        __IO uint32_t r0_pdb_sha_buf             : 1  ;
        __IO uint32_t r0_bgr_en                  : 1  ;
        __IO uint32_t r0_bias_en                 : 1  ;
        __IO uint32_t r0_pdb_adc_ref             : 1  ;
        __IO uint32_t r0_stuck_hvbias            : 2  ;
        __IO uint32_t r0_stuck_hvc               : 2  ;
        __IO uint32_t r0_stuck_lvbias            : 2  ;
        __IO uint32_t r0_stuck_int               : 2  ;
        __IO uint32_t r0_stuck_sha               : 2  ;
        __IO uint32_t r0_stuck_sha_buf           : 2  ;
        __IO uint32_t r0_stuck_bgr_en            : 2  ;
        __IO uint32_t r0_stuck_bias_en           : 2  ;
        __IO uint32_t r0_stuck_adc_ref           : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_PDB_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_stuck_cvc1_drv          : 2  ;
        __IO uint32_t r0_stuck_cvc1_drv_d        : 2  ;
        __IO uint32_t r0_stuck_rstp              : 2  ;
        __IO uint32_t r0_stuck_phtcr             : 2  ;
        __IO uint32_t r0_stuck_vcr               : 2  ;
        __IO uint32_t r0_stuck_rsti              : 2  ;
        __IO uint32_t r0_stuck_phth0             : 2  ;
        __IO uint32_t r0_stuck_phth1             : 2  ;
        __IO uint32_t r0_stuck_pht0              : 2  ;
        __IO uint32_t r0_stuck_pht1              : 2  ;
        __IO uint32_t r0_stuck_pht2              : 2  ;
        __IO uint32_t r0_stuck_pht3              : 2  ;
        __IO uint32_t r0_stuck_cmfb_init         : 2  ;
        __IO uint32_t r0_stuck_adc_rstb          : 2  ;
        __IO uint32_t r0_stuck_vcr_en_odd        : 1  ;
        __IO uint32_t r0_stuck_vcr_en_even       : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TG_STUCK_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_tm_mon_en               : 1  ;
        __IO uint32_t r0_tm_mon_s                : 3  ;
        __IO uint32_t r0_tm_ps_ev                : 1  ;
        __IO uint32_t r0_tm_ps_od                : 1  ;
        __IO uint32_t r0_test_adc                : 1  ;
        __IO uint32_t r0_tm_cr                   : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TEST_MODE_CTL_t;

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
        __IO uint32_t r1_buf_cfclk_on            : 1  ;
        __IO uint32_t r1_buf_clk_on              : 1  ;
        __IO uint32_t r1_cfclk_on                : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_AFE_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_ch_dum_drv_en           : 3  ;
        __IO uint32_t r1_ch_en_int               : 6  ;
        __IO uint32_t r1_ch_en_hvc               : 9  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CH_EN_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_double_buf_en           : 1  ;
        __IO uint32_t r1_buf_test_mode           : 1  ;
        __IO uint32_t r1_buf_cnt_ctl_en          : 1  ;
        __IO uint32_t r1_buf_cnt_skip_sel        : 1  ;
        __IO uint32_t r1_buf_cnt_num             : 6  ;
        __IO uint32_t r1_buf_auto_clr            : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_BUF_OPT_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_display_vcomr           : 2  ;
        __IO uint32_t r1_touch_f_vcomr           : 2  ;
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
        __IO uint32_t r1_mux_s_stuck_en          : 1  ;
        __IO uint32_t r1_mux_int_stuck_val       : 5  ;
        __IO uint32_t r1_mux_s_stuck_val         : 11 ;
        __IO uint32_t r1_mux_f_ctl_en            : 1  ;
        __IO uint32_t r1_muxf_inv                : 1  ;
        __IO uint32_t r1_mux_f_stuck_en          : 1  ;
        __IO uint32_t r1_mux_nd_bit_en           : 11 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_MUX_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux1_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux1_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux1_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux1_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux1_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux1_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_RG_MUX1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux2_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux2_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux2_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux2_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux2_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux2_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_RG_MUX2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux3_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux3_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux3_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux3_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux3_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux3_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_RG_MUX3_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux4_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux4_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux4_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux4_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux4_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux4_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_RG_MUX4_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux5_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux5_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux5_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux5_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux5_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux5_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_RG_MUX5_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux6_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux6_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux6_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux6_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux6_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux6_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_RG_MUX6_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux7_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux7_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux7_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux7_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux7_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux7_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_RG_MUX7_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux8_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux8_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux8_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux8_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux8_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux8_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_RG_MUX8_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux9_r1g1            : 5  ;
        __IO uint32_t r1_cr_mux9_r1g2            : 5  ;
        __IO uint32_t r1_cr_mux9_r1g3            : 5  ;
        __IO uint32_t r1_cr_mux9_r2g1            : 5  ;
        __IO uint32_t r1_cr_mux9_r2g2            : 5  ;
        __IO uint32_t r1_cr_mux9_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_RG_MUX9_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux10_r1g1           : 5  ;
        __IO uint32_t r1_cr_mux10_r1g2           : 5  ;
        __IO uint32_t r1_cr_mux10_r1g3           : 5  ;
        __IO uint32_t r1_cr_mux10_r2g1           : 5  ;
        __IO uint32_t r1_cr_mux10_r2g2           : 5  ;
        __IO uint32_t r1_cr_mux10_r2g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_RG_MUX10_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux11_r1g1           : 5  ;
        __IO uint32_t r1_cr_mux11_r1g2           : 5  ;
        __IO uint32_t r1_cr_mux11_r1g3           : 5  ;
        __IO uint32_t r1_cr_mux11_r2g1           : 5  ;
        __IO uint32_t r1_cr_mux11_r2g2           : 5  ;
        __IO uint32_t r1_cr_mux11_r2g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_RG_MUX11_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_muxe_r1g1            : 5  ;
        __IO uint32_t r1_cr_muxe_r1g2            : 5  ;
        __IO uint32_t r1_cr_muxe_r1g3            : 5  ;
        __IO uint32_t r1_cr_muxe_r2g1            : 5  ;
        __IO uint32_t r1_cr_muxe_r2g2            : 5  ;
        __IO uint32_t r1_cr_muxe_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R1G_MUXE_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_muxo_r1g1            : 5  ;
        __IO uint32_t r1_cr_muxo_r1g2            : 5  ;
        __IO uint32_t r1_cr_muxo_r1g3            : 5  ;
        __IO uint32_t r1_cr_muxo_r2g1            : 5  ;
        __IO uint32_t r1_cr_muxo_r2g2            : 5  ;
        __IO uint32_t r1_cr_muxo_r2g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_R1G_MUXO_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_mux1_gtune              : 3  ;
        __IO uint32_t r1_mux2_gtune              : 3  ;
        __IO uint32_t r1_mux3_gtune              : 3  ;
        __IO uint32_t r1_mux4_gtune              : 3  ;
        __IO uint32_t r1_mux5_gtune              : 3  ;
        __IO uint32_t r1_mux6_gtune              : 3  ;
        __IO uint32_t r1_mux7_gtune              : 3  ;
        __IO uint32_t r1_mux8_gtune              : 3  ;
        __IO uint32_t r1_mux9_gtune              : 3  ;
        __IO uint32_t r1_mux10_gtune             : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_GTUNE1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_mux11_gtune             : 3  ;
        __IO uint32_t r1_muxeo_gtune             : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_GTUNE2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux1_row2_gsel       : 1  ;
        __IO uint32_t r1_cr_mux1_row3_gsel       : 1  ;
        __IO uint32_t r1_cr_mux1_row4_gsel       : 1  ;
        __IO uint32_t r1_cr_mux2_row2_gsel       : 1  ;
        __IO uint32_t r1_cr_mux2_row3_gsel       : 1  ;
        __IO uint32_t r1_cr_mux2_row4_gsel       : 1  ;
        __IO uint32_t r1_cr_mux3_row2_gsel       : 1  ;
        __IO uint32_t r1_cr_mux3_row3_gsel       : 1  ;
        __IO uint32_t r1_cr_mux3_row4_gsel       : 1  ;
        __IO uint32_t r1_cr_mux4_row2_gsel       : 1  ;
        __IO uint32_t r1_cr_mux4_row3_gsel       : 1  ;
        __IO uint32_t r1_cr_mux4_row4_gsel       : 1  ;
        __IO uint32_t r1_cr_mux5_row2_gsel       : 1  ;
        __IO uint32_t r1_cr_mux5_row3_gsel       : 1  ;
        __IO uint32_t r1_cr_mux5_row4_gsel       : 1  ;
        __IO uint32_t r1_cr_mux6_row2_gsel       : 1  ;
        __IO uint32_t r1_cr_mux6_row3_gsel       : 1  ;
        __IO uint32_t r1_cr_mux6_row4_gsel       : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_GROUP_SEL1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux7_row2_gsel       : 1  ;
        __IO uint32_t r1_cr_mux7_row3_gsel       : 1  ;
        __IO uint32_t r1_cr_mux7_row4_gsel       : 1  ;
        __IO uint32_t r1_cr_mux8_row2_gsel       : 1  ;
        __IO uint32_t r1_cr_mux8_row3_gsel       : 1  ;
        __IO uint32_t r1_cr_mux8_row4_gsel       : 1  ;
        __IO uint32_t r1_cr_mux9_row2_gsel       : 1  ;
        __IO uint32_t r1_cr_mux9_row3_gsel       : 1  ;
        __IO uint32_t r1_cr_mux9_row4_gsel       : 1  ;
        __IO uint32_t r1_cr_mux10_row2_gsel      : 1  ;
        __IO uint32_t r1_cr_mux10_row3_gsel      : 1  ;
        __IO uint32_t r1_cr_mux10_row4_gsel      : 1  ;
        __IO uint32_t r1_cr_mux11_row2_gsel      : 1  ;
        __IO uint32_t r1_cr_mux11_row3_gsel      : 1  ;
        __IO uint32_t r1_cr_mux11_row4_gsel      : 1  ;
        __IO uint32_t r1_cr_muxeo_row2_gsel      : 1  ;
        __IO uint32_t r1_cr_muxeo_row3_gsel      : 1  ;
        __IO uint32_t r1_cr_muxeo_row4_gsel      : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_GROUP_SEL2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_col2_gsel            : 2  ;
        __IO uint32_t r1_cr_col3_gsel            : 2  ;
        __IO uint32_t r1_cr_col4_gsel            : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_GROUP_SEL3_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_adc_in                  : 30 ;
        __IO uint32_t r1_adc_op_opt              : 1  ;
        __IO uint32_t r1_adc_in_stuck_en         : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_ADC_IN_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_adc_ref_sel             : 2  ;
        __IO uint32_t r1_cvc1_comp               : 1  ;
        __IO uint32_t r1_int_ref                 : 3  ;
        __IO uint32_t r1_sha_ref                 : 3  ;
        __IO uint32_t r1_cvc1_gc                 : 2  ;
        __IO uint32_t r1_cvc2_gc                 : 2  ;
        __IO uint32_t r1_int_gc                  : 2  ;
        __IO uint32_t r1_int_half                : 1  ;
        __IO uint32_t r1_hv_cvc1_bcon            : 3  ;
        __IO uint32_t r1_hv_cvc2_bcon            : 3  ;
        __IO uint32_t r1_lv_int_bcon             : 2  ;
        __IO uint32_t r1_lv_sha_bcon             : 2  ;
        __IO uint32_t r1_ref_bcon                : 1  ;
        __IO uint32_t r1_lv_adc_ref_bcon         : 2  ;
        __IO uint32_t r1_lv_sha_buf_bcon         : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_AFE_SENSE_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_pdb_hvbias              : 1  ;
        __IO uint32_t r1_pdb_hvc                 : 1  ;
        __IO uint32_t r1_pdb_lvbias              : 1  ;
        __IO uint32_t r1_pdb_int                 : 1  ;
        __IO uint32_t r1_pdb_sha                 : 1  ;
        __IO uint32_t r1_pdb_sha_buf             : 1  ;
        __IO uint32_t r1_bgr_en                  : 1  ;
        __IO uint32_t r1_bias_en                 : 1  ;
        __IO uint32_t r1_pdb_adc_ref             : 1  ;
        __IO uint32_t r1_stuck_hvbias            : 2  ;
        __IO uint32_t r1_stuck_hvc               : 2  ;
        __IO uint32_t r1_stuck_lvbias            : 2  ;
        __IO uint32_t r1_stuck_int               : 2  ;
        __IO uint32_t r1_stuck_sha               : 2  ;
        __IO uint32_t r1_stuck_sha_buf           : 2  ;
        __IO uint32_t r1_stuck_bgr_en            : 2  ;
        __IO uint32_t r1_stuck_bias_en           : 2  ;
        __IO uint32_t r1_stuck_adc_ref           : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_PDB_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_stuck_cvc1_drv          : 2  ;
        __IO uint32_t r1_stuck_cvc1_drv_d        : 2  ;
        __IO uint32_t r1_stuck_rstp              : 2  ;
        __IO uint32_t r1_stuck_phtcr             : 2  ;
        __IO uint32_t r1_stuck_vcr               : 2  ;
        __IO uint32_t r1_stuck_rsti              : 2  ;
        __IO uint32_t r1_stuck_phth0             : 2  ;
        __IO uint32_t r1_stuck_phth1             : 2  ;
        __IO uint32_t r1_stuck_pht0              : 2  ;
        __IO uint32_t r1_stuck_pht1              : 2  ;
        __IO uint32_t r1_stuck_pht2              : 2  ;
        __IO uint32_t r1_stuck_pht3              : 2  ;
        __IO uint32_t r1_stuck_cmfb_init         : 2  ;
        __IO uint32_t r1_stuck_adc_rstb          : 2  ;
        __IO uint32_t r1_stuck_vcr_en_odd        : 1  ;
        __IO uint32_t r1_stuck_vcr_en_even       : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TG_STUCK_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_tm_mon_en               : 1  ;
        __IO uint32_t r1_tm_mon_s                : 3  ;
        __IO uint32_t r1_tm_ps_ev                : 1  ;
        __IO uint32_t r1_tm_ps_od                : 1  ;
        __IO uint32_t r1_test_adc                : 1  ;
        __IO uint32_t r1_tm_cr                   : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TEST_MODE_CTL_t;

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
        __IO uint32_t spi_write_defend           : 16 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSPI_WRITE_DEFEND_t;


typedef union
{
    struct
    {
        __IO uint32_t mon_cfclk_on               : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_CFCLK_ON_t;


typedef union
{
    struct
    {
        __I uint32_t r0_mon_adcdo                : 11 ;
        __I uint32_t reserve_zero1               : 5  ;
        __I uint32_t r1_mon_adcdo                : 11 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_ADCDO_t;

typedef union
{
    struct
    {
        __I uint32_t spi_sm                      : 1  ;
        __I uint32_t tlvds_slave_id              : 4  ;
        __I uint32_t chksum_err_cnt              : 3  ;
        __I uint32_t tsync_fault_err             : 1  ;
        __I uint32_t pwm_fault_err               : 1  ;
        __I uint32_t buf_phase_err               : 1  ;
        __I uint32_t reserve_zero3               : 5  ;
        __I uint32_t cur_lhb_mode_st             : 2  ;
        __I uint32_t cur_mux_num                 : 4  ;
        __I uint32_t cur_lhb_num                 : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSRIC_STATE_t;


typedef struct
{
        tPRODUCT_ID_t                        PRODUCT_ID               ;  // 0x0000    R    Default Val : 0x09840500
        tINTERFACE_CFG_t                     INTERFACE_CFG            ;  // 0x0004    R/W  Default Val : 0x00000041
        tSPIS_PAD_CTL_t                      SPIS_PAD_CTL             ;  // 0x0008    R/W  Default Val : 0x00000011
        tLVDS_PHY_CTL_t                      LVDS_PHY_CTL             ;  // 0x000C    R/W  Default Val : 0x50D57458
        tTLVDS_DUM0_t                        TLVDS_DUM0               ;  // 0x0010    R/W  Default Val : 0xA5A59669
        tTLVDS_DUM1_t                        TLVDS_DUM1               ;  // 0x0014    R/W  Default Val : 0x9669A5A5
        tSYS_CFG_t                           SYS_CFG                  ;  // 0x0018    R/W  Default Val : 0x00000001
        tSDIC_CFG_t                          SDIC_CFG                 ;  // 0x001C    R/W  Default Val : 0x00000000
        tTC_START_t                          TC_START                 ;  // 0x0020    R/W  Default Val : 0x00000000
        tCH_MUX_NUM_t                        CH_MUX_NUM               ;  // 0x0024    R/W  Default Val : 0x0000093E
        tLHB_MUX_CTL_t                       LHB_MUX_CTL              ;  // 0x0028    R/W  Default Val : 0x00061219
        tMD_PWM_CTL_t                        MD_PWM_CTL               ;  // 0x002C    R/W  Default Val : 0x026384C7
        tMD0_MUX_CFG_00_t                    MD0_MUX_CFG_00           ;  // 0x0030    R/W  Default Val : 0x76543210
        tMD0_MUX_CFG_01_t                    MD0_MUX_CFG_01           ;  // 0x0034    R/W  Default Val : 0xDC000A98
        tDEFA_LHB_MCFG00_t                   DEFA_LHB_MCFG00          ;  // 0x0038    R/W  Default Val : 0x00000000
        tPWM_PRD_t                           PWM_PRD                  ;  // 0x003C    R/W  Default Val : 0x0000132E
        tPWM_MUX_DLY_PRD_t                   PWM_MUX_DLY_PRD          ;  // 0x0040    R/W  Default Val : 0x00000000
        tAFE_SIG_CTL_t                       AFE_SIG_CTL              ;  // 0x0044    R/W  Default Val : 0x000000FF
        tF1_CVC1_DRV_CTL1_t                  F1_CVC1_DRV_CTL1         ;  // 0x0048    R/W  Default Val : 0x00052749
        tF1_RSTP_PHT_CTL_t                   F1_RSTP_PHT_CTL          ;  // 0x004C    R/W  Default Val : 0x0104902C
        tF1_PHTCR_VCR_CTL_t                  F1_PHTCR_VCR_CTL         ;  // 0x0050    R/W  Default Val : 0x0460CF26
        tF1_RSTI_CTL_t                       F1_RSTI_CTL              ;  // 0x0054    R/W  Default Val : 0x000A9502
        tF1_PHTH_CTL_t                       F1_PHTH_CTL              ;  // 0x0058    R/W  Default Val : 0x0341831A
        tF2_CVC1_DRV_CTL1_t                  F2_CVC1_DRV_CTL1         ;  // 0x005C    R/W  Default Val : 0x00022589
        tF2_RSTP_PHT_CTL_t                   F2_RSTP_PHT_CTL          ;  // 0x0060    R/W  Default Val : 0x000D0624
        tF2_PHTCR_VCR_CTL_t                  F2_PHTCR_VCR_CTL         ;  // 0x0064    R/W  Default Val : 0x006C351F
        tF2_RSTI_CTL_t                       F2_RSTI_CTL              ;  // 0x0068    R/W  Default Val : 0x00012482
        tF2_PHTH_CTL_t                       F2_PHTH_CTL              ;  // 0x006C    R/W  Default Val : 0x00122952
        tPHT_CTL_t                           PHT_CTL                  ;  // 0x0070    R/W  Default Val : 0x00000526
        tADC_CTL1_t                          ADC_CTL1                 ;  // 0x0074    R/W  Default Val : 0x00B61388
        tADC_CTL2_t                          ADC_CTL2                 ;  // 0x0078    R/W  Default Val : 0x0022DF41
        tADC_CTL3_t                          ADC_CTL3                 ;  // 0x007C    R/W  Default Val : 0x2C471427
        tTEST_MUX_CTL_t                      TEST_MUX_CTL             ;  // 0x0080    R/W  Default Val : 0x00000000
        tSYS_DUMMY0_t                        SYS_DUMMY0               ;  // 0x0084    R/W  Default Val : 0x000000FF
        tR0_AFE_CFG_t                        R0_AFE_CFG               ;  // 0x0200    R/W  Default Val : 0x00000003
        tR0_CH_EN_t                          R0_CH_EN                 ;  // 0x0204    R/W  Default Val : 0x00000000
        tR0_BUF_OPT_t                        R0_BUF_OPT               ;  // 0x0208    R/W  Default Val : 0x00000009
        tR0_VCOMR_OPT_t                      R0_VCOMR_OPT             ;  // 0x020C    R/W  Default Val : 0x00000000
        tR0_MUX_CTL1_t                       R0_MUX_CTL1              ;  // 0x0210    R/W  Default Val : 0x7FF9FFFE
        tR0_CR_RG_MUX1_t                     R0_CR_RG_MUX1[8]         ;  // 0x0214    R/W  Default Val : 0x00000000
        tR0_CR_RG_MUX2_t                     R0_CR_RG_MUX2[8]         ;  // 0x0218    R/W  Default Val : 0x00000000
        tR0_CR_RG_MUX3_t                     R0_CR_RG_MUX3[8]         ;  // 0x021C    R/W  Default Val : 0x00000000
        tR0_CR_RG_MUX4_t                     R0_CR_RG_MUX4[8]         ;  // 0x0220    R/W  Default Val : 0x00000000
        tR0_CR_RG_MUX5_t                     R0_CR_RG_MUX5[8]         ;  // 0x0224    R/W  Default Val : 0x00000000
        tR0_CR_RG_MUX6_t                     R0_CR_RG_MUX6[8]         ;  // 0x0228    R/W  Default Val : 0x00000000
        tR0_CR_RG_MUX7_t                     R0_CR_RG_MUX7[8]         ;  // 0x022C    R/W  Default Val : 0x00000000
        tR0_CR_RG_MUX8_t                     R0_CR_RG_MUX8[8]         ;  // 0x0230    R/W  Default Val : 0x00000000
        tR0_CR_RG_MUX9_t                     R0_CR_RG_MUX9[8]         ;  // 0x0234    R/W  Default Val : 0x00000000
        tR0_CR_RG_MUX10_t                    R0_CR_RG_MUX10[8]        ;  // 0x0238    R/W  Default Val : 0x00000000
        tR0_CR_RG_MUX11_t                    R0_CR_RG_MUX11[8]        ;  // 0x023C    R/W  Default Val : 0x00000000
        tR0_CR_R1G_MUXE_t                    R0_CR_R1G_MUXE[8]        ;  // 0x0240    R/W  Default Val : 0x00000000
        tR0_CR_R1G_MUXO_t                    R0_CR_R1G_MUXO[8]        ;  // 0x0244    R/W  Default Val : 0x00000000
        tR0_CR_GTUNE1_t                      R0_CR_GTUNE1[8]          ;  // 0x0248    R/W  Default Val : 0x00000000
        tR0_CR_GTUNE2_t                      R0_CR_GTUNE2[8]          ;  // 0x024C    R/W  Default Val : 0x00000000
        tR0_TUNE_GROUP_SEL1_t                R0_TUNE_GROUP_SEL1[8]    ;  // 0x0250    R/W  Default Val : 0x00024924
        tR0_TUNE_GROUP_SEL2_t                R0_TUNE_GROUP_SEL2[8]    ;  // 0x0254    R/W  Default Val : 0x00024924
        tR0_TUNE_GROUP_SEL3_t                R0_TUNE_GROUP_SEL3[8]    ;  // 0x0258    R/W  Default Val : 0x00000015
        tR0_ADC_IN_CTL_t                     R0_ADC_IN_CTL            ;  // 0x025C    R/W  Default Val : 0x00000000
        tR0_AFE_SENSE_CTL_t                  R0_AFE_SENSE_CTL         ;  // 0x0260    R/W  Default Val : 0x29137927
        tR0_PDB_CTL_t                        R0_PDB_CTL               ;  // 0x0264    R/W  Default Val : 0x000000C0
        tR0_TG_STUCK_t                       R0_TG_STUCK              ;  // 0x0268    R/W  Default Val : 0x00000000
        tR0_TEST_MODE_CTL_t                  R0_TEST_MODE_CTL         ;  // 0x026C    R/W  Default Val : 0x00000000
        tR0_RESERVE_t                        R0_RESERVE               ;  // 0x0270    R/W  Default Val : 0x00000000
        tR1_AFE_CFG_t                        R1_AFE_CFG               ;  // 0x0300    R/W  Default Val : 0x00000003
        tR1_CH_EN_t                          R1_CH_EN                 ;  // 0x0304    R/W  Default Val : 0x00000000
        tR1_BUF_OPT_t                        R1_BUF_OPT               ;  // 0x0308    R/W  Default Val : 0x00000009
        tR1_VCOMR_OPT_t                      R1_VCOMR_OPT             ;  // 0x030C    R/W  Default Val : 0x00000000
        tR1_MUX_CTL1_t                       R1_MUX_CTL1              ;  // 0x0310    R/W  Default Val : 0x7FF9FFFE
        tR1_CR_RG_MUX1_t                     R1_CR_RG_MUX1[8]         ;  // 0x0314    R/W  Default Val : 0x00000000
        tR1_CR_RG_MUX2_t                     R1_CR_RG_MUX2[8]         ;  // 0x0318    R/W  Default Val : 0x00000000
        tR1_CR_RG_MUX3_t                     R1_CR_RG_MUX3[8]         ;  // 0x031C    R/W  Default Val : 0x00000000
        tR1_CR_RG_MUX4_t                     R1_CR_RG_MUX4[8]         ;  // 0x0320    R/W  Default Val : 0x00000000
        tR1_CR_RG_MUX5_t                     R1_CR_RG_MUX5[8]         ;  // 0x0324    R/W  Default Val : 0x00000000
        tR1_CR_RG_MUX6_t                     R1_CR_RG_MUX6[8]         ;  // 0x0328    R/W  Default Val : 0x00000000
        tR1_CR_RG_MUX7_t                     R1_CR_RG_MUX7[8]         ;  // 0x032C    R/W  Default Val : 0x00000000
        tR1_CR_RG_MUX8_t                     R1_CR_RG_MUX8[8]         ;  // 0x0330    R/W  Default Val : 0x00000000
        tR1_CR_RG_MUX9_t                     R1_CR_RG_MUX9[8]         ;  // 0x0334    R/W  Default Val : 0x00000000
        tR1_CR_RG_MUX10_t                    R1_CR_RG_MUX10[8]        ;  // 0x0338    R/W  Default Val : 0x00000000
        tR1_CR_RG_MUX11_t                    R1_CR_RG_MUX11[8]        ;  // 0x033C    R/W  Default Val : 0x00000000
        tR1_CR_R1G_MUXE_t                    R1_CR_R1G_MUXE[8]        ;  // 0x0340    R/W  Default Val : 0x00000000
        tR1_CR_R1G_MUXO_t                    R1_CR_R1G_MUXO[8]        ;  // 0x0344    R/W  Default Val : 0x00000000
        tR1_CR_GTUNE1_t                      R1_CR_GTUNE1[8]          ;  // 0x0348    R/W  Default Val : 0x00000000
        tR1_CR_GTUNE2_t                      R1_CR_GTUNE2[8]          ;  // 0x034C    R/W  Default Val : 0x00000000
        tR1_TUNE_GROUP_SEL1_t                R1_TUNE_GROUP_SEL1[8]    ;  // 0x0350    R/W  Default Val : 0x00024924
        tR1_TUNE_GROUP_SEL2_t                R1_TUNE_GROUP_SEL2[8]    ;  // 0x0354    R/W  Default Val : 0x00024924
        tR1_TUNE_GROUP_SEL3_t                R1_TUNE_GROUP_SEL3[8]    ;  // 0x0358    R/W  Default Val : 0x00000015
        tR1_ADC_IN_CTL_t                     R1_ADC_IN_CTL            ;  // 0x035C    R/W  Default Val : 0x00000000
        tR1_AFE_SENSE_CTL_t                  R1_AFE_SENSE_CTL         ;  // 0x0360    R/W  Default Val : 0x29137927
        tR1_PDB_CTL_t                        R1_PDB_CTL               ;  // 0x0364    R/W  Default Val : 0x000000C0
        tR1_TG_STUCK_t                       R1_TG_STUCK              ;  // 0x0368    R/W  Default Val : 0x00000000
        tR1_TEST_MODE_CTL_t                  R1_TEST_MODE_CTL         ;  // 0x036C    R/W  Default Val : 0x00000000
        tR1_RESERVE_t                        R1_RESERVE               ;  // 0x0370    R/W  Default Val : 0x00000000
        tSPI_WRITE_DEFEND_t                  SPI_WRITE_DEFEND         ;  // 0x07F0    R/W  Default Val : 0x000000FF
        tMON_CFCLK_ON_t                      MON_CFCLK_ON             ;  // 0x07F4    R/W  Default Val : 0x00000001
        tMON_ADCDO_t                         MON_ADCDO                ;  // 0x07F8    R    Default Val : 0x00000000
        tSRIC_STATE_t                        SRIC_STATE               ;  // 0x07FC    R    Default Val : 0x00000000
} __PACKED tModuleSRICCommonConf_t;

//#include "lx98405_parameter_set.h"

//#endif /* (USED_ROIC_DEF == ROIC_LX98405) */

#endif /* __LX98405_CONF_H_ */ 

