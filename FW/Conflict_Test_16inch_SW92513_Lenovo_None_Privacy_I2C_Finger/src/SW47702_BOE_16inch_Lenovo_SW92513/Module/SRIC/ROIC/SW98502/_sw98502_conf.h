//-------------------------------------------------------
//-   Register Structure Auto Generation                 
//-------------------------------------------------------


#ifndef __SW98502_CONF_H_
#define __SW98502_CONF_H_

#if (USED_ROIC_DEF == ROIC_SW98502)

#define SW98502_MODE_FINGER          (0)
#define SW98502_MODE_BEACON          (1)
#define SW98502_MODE_PEN_POS         (2)
#define SW98502_MODE_PEN_TILT        (2)
#define SW98502_MODE_PEN_DAT         (3)
#define SW98502_MODE_DUMMY           (6)

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
        __IO uint32_t tattn_out                  : 1  ;
        __IO uint32_t tattn_oe                   : 1  ;
        __IO uint32_t tattn_ds                   : 1  ;
        __IO uint32_t tattn_func                 : 1  ;
        __IO uint32_t tattn_sel0                 : 1  ;
        __IO uint32_t tattn_sel1                 : 1  ;
        __IO uint32_t tattn_func2                : 4  ;
        __IO uint32_t pad_tattn_test             : 1  ;
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
        __IO uint32_t buf_clk_on                 : 1  ;
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
        __IO uint32_t r0_dum_drv_en              : 2  ;
        __IO uint32_t r0_ch_en_int               : 7  ;
        __IO uint32_t r0_ch_en_hvr               : 9  ;
        __IO uint32_t r0_ch_en_hvc               : 9  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CH_EN_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_dum_drv_en              : 2  ;
        __IO uint32_t r1_ch_en_int               : 7  ;
        __IO uint32_t r1_ch_en_hvr               : 9  ;
        __IO uint32_t r1_ch_en_hvc               : 9  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CH_EN_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_ch_num                 : 6  ;
        __IO uint32_t pp_ch_num                  : 6  ;
        __IO uint32_t pd_ch_num                  : 6  ;
        __IO uint32_t pdrv_ch_num                : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tCH_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t tot_mux_num                : 4  ; // N+1
        __IO uint32_t mux_int_en                 : 4  ;
        __IO uint32_t mux_int_stuck_val          : 9  ;
        __IO uint32_t top_mux_num                : 4  ; // 0~N
        __IO uint32_t bot_mux_num                : 4  ; // 0~N
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
        __IO uint32_t mux_m1_even_dly            : 6  ;
        __IO uint32_t mux_m1_odd_dly             : 6  ;
        __IO uint32_t mux_nd_dly                 : 6  ;
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
        __IO uint32_t stuck_abd                  : 1  ;
        __IO uint32_t abd                        : 1  ;
        __IO uint32_t abd_pol                    : 1  ;
        __IO uint32_t abd_inv                    : 1  ;
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
        __IO uint32_t fig_pwm_prd                : 10 ;
        __IO uint32_t pen_pwm_prd                : 10 ;
        __IO uint32_t nd_pwm_prd                 : 10 ;
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
        __IO uint32_t fig_rstp_rise_num          : 10 ;
        __IO uint32_t pen_rstp_rise_num          : 10 ;
        __IO uint32_t nd_rstp_rise_num           : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTP_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_rstp_fall_num1         : 10 ;
        __IO uint32_t pen_rstp_fall_num1         : 10 ;
        __IO uint32_t nd_rstp_fall_num1          : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTP_FALL_NUM1_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_rstp_fall_num2         : 10 ;
        __IO uint32_t pen_rstp_fall_num2         : 10 ;
        __IO uint32_t nd_rstp_fall_num2          : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTP_FALL_NUM2_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phtcr_rise_num         : 10 ;
        __IO uint32_t pen_phtcr_rise_num         : 10 ;
        __IO uint32_t nd_phtcr_rise_num          : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTCR_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phtcr_fall_num         : 10 ;
        __IO uint32_t pen_phtcr_fall_num         : 10 ;
        __IO uint32_t nd_phtcr_fall_num          : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTCR_FALL_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_vcr_num                : 10 ;
        __IO uint32_t pen_vcr_num                : 10 ;
        __IO uint32_t nd_vcr_num                 : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tVCR_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_rsti_rise_num          : 10 ;
        __IO uint32_t pen_rsti_rise_num          : 10 ;
        __IO uint32_t nd_rsti_rise_num           : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTI_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_rsti_fall_num1         : 10 ;
        __IO uint32_t pen_rsti_fall_num1         : 10 ;
        __IO uint32_t nd_rsti_fall_num1          : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTI_FALL_NUM1_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_rsti_fall_num2         : 10 ;
        __IO uint32_t pen_rsti_fall_num2         : 10 ;
        __IO uint32_t nd_rsti_fall_num2          : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tRSTI_FALL_NUM2_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phth0_rise_num         : 10 ;
        __IO uint32_t pen_phth0_rise_num         : 10 ;
        __IO uint32_t nd_phth0_rise_num          : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTH0_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phth0_fall_num         : 10 ;
        __IO uint32_t pen_phth0_fall_num         : 10 ;
        __IO uint32_t nd_phth0_fall_num          : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTH0_FALL_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phth1_rise_num         : 10 ;
        __IO uint32_t pen_phth1_rise_num         : 10 ;
        __IO uint32_t nd_phth1_rise_num          : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTH1_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_phth1_fall_num         : 10 ;
        __IO uint32_t pen_phth1_fall_num         : 10 ;
        __IO uint32_t nd_phth1_fall_num          : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHTH1_FALL_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t pht_prd                    : 8  ;
        __IO uint32_t pht_opt_inv                : 1  ;
        __IO uint32_t pht_end_time               : 10 ;
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
        __IO uint32_t fig_pht_rise_num           : 10 ;
        __IO uint32_t pen_pht_rise_num           : 10 ;
        __IO uint32_t nd_pht_rise_num            : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHT_RISE_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_pht_fall_num           : 10 ;
        __IO uint32_t pen_pht_fall_num           : 10 ;
        __IO uint32_t nd_pht_fall_num            : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHT_FALL_NUM_t;

typedef union
{
    struct
    {
        __IO uint32_t adc_op_opt                 : 1  ;
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
        __IO uint32_t display_vcomr              : 2  ;
        __IO uint32_t touch_f_vcomr              : 2  ;
        __IO uint32_t touch_p_vcomr              : 2  ;
        __IO uint32_t stuck_vcomr_left           : 1  ;
        __IO uint32_t stuck_vcomr_right          : 1  ;
        __IO uint32_t stuck_vcomr_level          : 1  ;
        __IO uint32_t tsync_opt                  : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tVCOMR_OPT_t;

typedef union
{
    struct
    {
        __IO uint32_t double_buf_en              : 1  ;
        __IO uint32_t pre_drv_en                 : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tBUF_OPT_t;

typedef union
{
    struct
    {
        __IO uint32_t stuck_rstp                 : 2  ;
        __IO uint32_t stuck_phtcr                : 2  ;
        __IO uint32_t stuck_vcr                  : 2  ;
        __IO uint32_t stuck_rsti                 : 2  ;
        __IO uint32_t stuck_phth0                : 2  ;
        __IO uint32_t stuck_phth1                : 2  ;
        __IO uint32_t stuck_pht0                 : 2  ;
        __IO uint32_t stuck_pht1                 : 2  ;
        __IO uint32_t r0_fig_stuck_vcr_en_odd    : 1  ;
        __IO uint32_t r0_pen_stuck_vcr_en_odd    : 1  ;
        __IO uint32_t r1_fig_stuck_vcr_en_odd    : 1  ;
        __IO uint32_t r1_pen_stuck_vcr_en_odd    : 1  ;
        __IO uint32_t r0_fig_stuck_vcr_en_even    : 1  ;
        __IO uint32_t r0_pen_stuck_vcr_en_even    : 1  ;
        __IO uint32_t r1_fig_stuck_vcr_en_even    : 1  ;
        __IO uint32_t r1_pen_stuck_vcr_en_even    : 1  ;
        __IO uint32_t stuck_muxs_en              : 1  ;
        __IO uint32_t stuck_muxf_en              : 1  ;
        __IO uint32_t vcr_inv_en                 : 1  ;
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
        __IO uint32_t adc_in                     : 32 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tADC_IN_t;


typedef union
{
    struct
    {
        __IO uint32_t mux_s_stuck                : 6  ;
        __IO uint32_t mux_s_line_stuck           : 9  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMUX_S_STUCK_VAL_t;

typedef union
{
    struct
    {
        __IO uint32_t mux_f_stuck_val            : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMUX_F_STUCK_VAL_t;


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
        __IO uint32_t sgap_num                   : 10 ;
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
        __IO uint32_t pen_pos2_lhb_mux_num       : 4  ;
        __IO uint32_t pen_dat1_lhb_mux_num       : 4  ;
        __IO uint32_t pen_dat2_lhb_mux_num       : 4  ;
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
        __IO uint32_t pen_pos2_mux_cfg0          : 6  ;
        __IO uint32_t pen_pos2_mux_cfg1          : 6  ;
        __IO uint32_t pen_pos2_mux_cfg2          : 6  ;
        __IO uint32_t pen_pos2_mux_cfg3          : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPEN_POS2_LHB_CFG_t;

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
        __IO uint32_t pen_dat2_mux_cfg0          : 6  ;
        __IO uint32_t pen_dat2_mux_cfg1          : 6  ;
        __IO uint32_t pen_dat2_mux_cfg2          : 6  ;
        __IO uint32_t pen_dat2_mux_cfg3          : 6  ;
        __IO uint32_t pen_dat2_tmuxnum           : 4  ;
        __IO uint32_t pen_dat2_tsync_muxnum      : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPEN_DAT2_LHB_CFG_t;

typedef union
{
    struct
    {
        __IO uint32_t mux_fctl_rise_num1         : 10 ;
        __IO uint32_t mux_fctl_rise_num2         : 10 ;
        __IO uint32_t fctl_rsti_off              : 1  ;
        __IO uint32_t mux_off_en                 : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMUX_FCTL_NUM1_t;

typedef union
{
    struct
    {
        __IO uint32_t mux_fctl_fall_num1         : 10 ;
        __IO uint32_t mux_fctl_fall_num2         : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMUX_FCTL_NUM2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_uplink_mux              : 6  ;
        __IO uint32_t r1_uplink_mux              : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tUPLINK_MUX_t;

typedef union
{
    struct
    {
        __IO uint32_t mux_m1_bit_en              : 6  ;
        __IO uint32_t mux_nd_bit_en              : 6  ;
        __IO uint32_t mux_pp_bit_en              : 9  ;
        __IO uint32_t mux_pd_bit_en              : 9  ;
        __IO uint32_t m1_mode_sel                : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tLHB_MUX_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t ping_max                   : 10 ;
        __IO uint32_t ping_pwm_num               : 7  ;
        __IO uint32_t uplink_state               : 2  ;
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
}__PACKED tR0_CR_MUX1_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux1_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux1_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux1_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_MUX1_2_t;

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
}__PACKED tR0_CR_MUX2_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux2_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux2_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux2_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_MUX2_2_t;

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
}__PACKED tR0_CR_MUX3_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux3_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux3_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux3_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_MUX3_2_t;

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
}__PACKED tR0_CR_MUX4_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux4_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux4_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux4_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_MUX4_2_t;

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
}__PACKED tR0_CR_MUX5_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux5_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux5_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux5_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_MUX5_2_t;

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
}__PACKED tR0_CR_MUX6_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux6_r3g1            : 5  ;
        __IO uint32_t r0_cr_mux6_r3g2            : 5  ;
        __IO uint32_t r0_cr_mux6_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_MUX6_2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_m1_odd_g1            : 5  ;
        __IO uint32_t r0_cr_m1_odd_g2            : 5  ;
        __IO uint32_t r0_cr_m1_odd_g3            : 5  ;
        __IO uint32_t r0_cr_m1_even_g1           : 5  ;
        __IO uint32_t r0_cr_m1_even_g2           : 5  ;
        __IO uint32_t r0_cr_m1_even_g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_CR_M1_t;

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
}__PACKED tR1_CR_MUX1_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux1_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux1_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux1_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_MUX1_2_t;

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
}__PACKED tR1_CR_MUX2_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux2_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux2_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux2_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_MUX2_2_t;

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
}__PACKED tR1_CR_MUX3_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux3_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux3_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux3_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_MUX3_2_t;

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
}__PACKED tR1_CR_MUX4_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux4_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux4_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux4_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_MUX4_2_t;

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
}__PACKED tR1_CR_MUX5_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux5_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux5_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux5_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_MUX5_2_t;

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
}__PACKED tR1_CR_MUX6_1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux6_r3g1            : 5  ;
        __IO uint32_t r1_cr_mux6_r3g2            : 5  ;
        __IO uint32_t r1_cr_mux6_r3g3            : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_MUX6_2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_m1_odd_g1            : 5  ;
        __IO uint32_t r1_cr_m1_odd_g2            : 5  ;
        __IO uint32_t r1_cr_m1_odd_g3            : 5  ;
        __IO uint32_t r1_cr_m1_even_g1           : 5  ;
        __IO uint32_t r1_cr_m1_even_g2           : 5  ;
        __IO uint32_t r1_cr_m1_even_g3           : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_CR_M1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_nd_g1                : 5  ;
        __IO uint32_t r0_cr_nd_g2                : 5  ;
        __IO uint32_t r0_cr_nd_g3                : 5  ;
        __IO uint32_t r1_cr_nd_g1                : 5  ;
        __IO uint32_t r1_cr_nd_g2                : 5  ;
        __IO uint32_t r1_cr_nd_g3                : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR_CR_ND_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_top_fig_gtune           : 3  ;
        __IO uint32_t r0_mid_fig_gtune           : 3  ;
        __IO uint32_t r0_bot_fig_gtune           : 3  ;
        __IO uint32_t r0_pen_gtune               : 3  ;
        __IO uint32_t r0_pdrv_gtune              : 3  ;
        __IO uint32_t r1_top_fig_gtune           : 3  ;
        __IO uint32_t r1_mid_fig_gtune           : 3  ;
        __IO uint32_t r1_bot_fig_gtune           : 3  ;
        __IO uint32_t r1_pen_gtune               : 3  ;
        __IO uint32_t r1_pdrv_gtune              : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR_CR_GTUNE_t;

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
//
//
//typedef union
//{
//    struct
//    {
//        __IO uint32_t reserved_3                 : 32 ;
//    }__PACKED tBit;
//    __IO uint32_t ulBulk;
//}__PACKED tRESERVED_3_t;
//
//
//typedef union
//{
//    struct
//    {
//        __IO uint32_t reserved_4                 : 32 ;
//    }__PACKED tBit;
//    __IO uint32_t ulBulk;
//}__PACKED tRESERVED_4_t;


typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux1_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row5_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row6_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row7_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row8_gsel       : 2  ;
        __IO uint32_t r0_cr_mux1_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_ROW_MUX1_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux2_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row5_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row6_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row7_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row8_gsel       : 2  ;
        __IO uint32_t r0_cr_mux2_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_ROW_MUX2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux3_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row5_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row6_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row7_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row8_gsel       : 2  ;
        __IO uint32_t r0_cr_mux3_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_ROW_MUX3_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux4_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row5_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row6_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row7_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row8_gsel       : 2  ;
        __IO uint32_t r0_cr_mux4_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_ROW_MUX4_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux5_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row5_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row6_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row7_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row8_gsel       : 2  ;
        __IO uint32_t r0_cr_mux5_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_ROW_MUX5_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_mux6_row1_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row2_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row3_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row4_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row5_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row6_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row7_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row8_gsel       : 2  ;
        __IO uint32_t r0_cr_mux6_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR0_TUNE_ROW_MUX6_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux1_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row5_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row6_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row7_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row8_gsel       : 2  ;
        __IO uint32_t r1_cr_mux1_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_ROW_MUX1_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux2_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row5_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row6_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row7_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row8_gsel       : 2  ;
        __IO uint32_t r1_cr_mux2_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_ROW_MUX2_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux3_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row5_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row6_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row7_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row8_gsel       : 2  ;
        __IO uint32_t r1_cr_mux3_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_ROW_MUX3_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux4_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row5_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row6_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row7_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row8_gsel       : 2  ;
        __IO uint32_t r1_cr_mux4_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_ROW_MUX4_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux5_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row5_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row6_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row7_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row8_gsel       : 2  ;
        __IO uint32_t r1_cr_mux5_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_ROW_MUX5_t;

typedef union
{
    struct
    {
        __IO uint32_t r1_cr_mux6_row1_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row2_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row3_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row4_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row5_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row6_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row7_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row8_gsel       : 2  ;
        __IO uint32_t r1_cr_mux6_row9_gsel       : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR1_TUNE_ROW_MUX6_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_cr_col1_gsel            : 2  ;
        __IO uint32_t r0_cr_col2_gsel            : 2  ;
        __IO uint32_t r0_cr_col3_gsel            : 2  ;
        __IO uint32_t r0_cr_col4_gsel            : 2  ;
        __IO uint32_t r0_cr_col5_gsel            : 2  ;
        __IO uint32_t r1_cr_col1_gsel            : 2  ;
        __IO uint32_t r1_cr_col2_gsel            : 2  ;
        __IO uint32_t r1_cr_col3_gsel            : 2  ;
        __IO uint32_t r1_cr_col4_gsel            : 2  ;
        __IO uint32_t r1_cr_col5_gsel            : 2  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR_TUNE_GROUP_COL_t;

typedef union
{
    struct
    {
        __IO uint32_t pwrcr1                     : 6  ;
        __IO uint32_t pwrcr2                     : 6  ;
        __IO uint32_t pwrcr3                     : 6  ;
        __IO uint32_t pwrcr4                     : 6  ;
        __IO uint32_t pwrcr5                     : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSD_PWRCR1_t;

typedef union
{
    struct
    {
        __IO uint32_t pwrcr6                     : 6  ;
        __IO uint32_t pwrcr7                     : 6  ;
        __IO uint32_t pwrcr8                     : 6  ;
        __IO uint32_t pwrcr9                     : 6  ;
        __IO uint32_t pwrcr10                    : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSD_PWRCR2_t;

typedef union
{
    struct
    {
        __IO uint32_t pwrcr11                    : 6  ;
        __IO uint32_t pwrcr12                    : 6  ;
        __IO uint32_t pwrcr13                    : 6  ;
        __IO uint32_t pwrcr14                    : 6  ;
        __IO uint32_t pwrcr15                    : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSD_PWRCR3_t;

typedef union
{
    struct
    {
        __IO uint32_t pwrcr16                    : 6  ;
        __IO uint32_t pwrcr17                    : 6  ;
        __IO uint32_t pwrcr18                    : 6  ;
        __IO uint32_t pwrcr19                    : 6  ;
        __IO uint32_t pwrcr20                    : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSD_PWRCR4_t;

typedef union
{
    struct
    {
        __IO uint32_t pwrcr21                    : 6  ;
        __IO uint32_t pwrcr22                    : 6  ;
        __IO uint32_t pwrcr23                    : 6  ;
        __IO uint32_t pwrcr24                    : 6  ;
        __IO uint32_t pwrcr25                    : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSD_PWRCR5_t;

typedef union
{
    struct
    {
        __IO uint32_t pwrcr26                    : 6  ;
        __IO uint32_t pwrcr27                    : 6  ;
        __IO uint32_t pwrcr28                    : 6  ;
        __IO uint32_t pwrcr29                    : 6  ;
        __IO uint32_t pwrcr30                    : 6  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSD_PWRCR6_t;

typedef union
{
    struct
    {
        __IO uint32_t pwrcr31                    : 6  ;
        __IO uint32_t pwrcr32                    : 6  ;
        __IO uint32_t sd_lhbnum                  : 5  ;
        __IO uint32_t set_sel                    : 1  ;
        __IO uint32_t rocen                      : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSD_PWRCR7_t;

typedef union
{
    struct
    {
        __IO uint32_t pen_dc_md_pen              : 2  ;
        __IO uint32_t pen_dc_md_fig              : 2  ;
        __IO uint32_t pen_dc_md_stuck            : 2  ;
        __IO uint32_t pre_comp                   : 1  ;
        __IO uint32_t pre_ch_conb_en             : 1  ;
        __IO uint32_t pre_ch_conb_inv            : 1  ;
        __IO uint32_t fig_int_ref                : 3  ;
        __IO uint32_t pen_int_ref                : 3  ;
        __IO uint32_t fig_sha_ref                : 3  ;
        __IO uint32_t pen_sha_ref                : 3  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tAFE_SENSE_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_pre_gc                 : 3  ;
        __IO uint32_t pen_pre_gc_con             : 3  ;
        __IO uint32_t pen_pre_gc_hov             : 3  ;
        __IO uint32_t pdrv_pre_gc_con            : 3  ;
        __IO uint32_t pdrv_pre_gc_hov            : 3  ;
        __IO uint32_t fig_int_gc                 : 2  ;
        __IO uint32_t pen_int_gc                 : 2  ;
        __IO uint32_t fig_int_half               : 1  ;
        __IO uint32_t pen_int_half_con           : 1  ;
        __IO uint32_t pen_int_half_hov           : 1  ;
        __IO uint32_t pdrv_int_half_con          : 1  ;
        __IO uint32_t pdrv_int_half_hov          : 1  ;
        __IO uint32_t fig_pre_bs_lp              : 1  ;
        __IO uint32_t pen_pre_bs_lp              : 1  ;
        __IO uint32_t pdrv_pre_bs_lp             : 1  ;
        __IO uint32_t fig_int_bs_lp              : 1  ;
        __IO uint32_t pen_int_bs_lp              : 1  ;
        __IO uint32_t fig_sha_bs_lp              : 1  ;
        __IO uint32_t pen_sha_bs_lp              : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tAFE_SENSE_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_hv_ssu_bcon            : 3  ;
        __IO uint32_t pen_hv_ssu_bcon            : 3  ;
        __IO uint32_t pdrv_hv_ssu_bcon           : 3  ;
        __IO uint32_t fig_lv_ssu_bcon            : 3  ;
        __IO uint32_t pen_lv_ssu_bcon            : 3  ;
        __IO uint32_t fig_lv_ssu_bcons           : 3  ;
        __IO uint32_t pen_lv_ssu_bcons           : 3  ;
        __IO uint32_t lv_ssu_bconp               : 3  ;
        __IO uint32_t lv_ssu_bconp_buf           : 1  ;
        __IO uint32_t ref_bcon                   : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tAFE_SENSE_CTL3_t;

typedef union
{
    struct
    {
        __IO uint32_t rst_phd_en                 : 1  ;
        __IO uint32_t phd_gc_con                 : 2  ;
        __IO uint32_t phd_gc_hov                 : 2  ;
        __IO uint32_t phd_md                     : 1  ;
        __IO uint32_t adc_in_phd                 : 1  ;
        __IO uint32_t r0_phd_in_s                : 2  ;
        __IO uint32_t r1_phd_in_s                : 2  ;
        __IO uint32_t r0_phd_en                  : 7  ;
        __IO uint32_t r1_phd_en                  : 7  ;
        __IO uint32_t stuck_rst_phd              : 1  ;
        __IO uint32_t stuck_adc_in_phd           : 1  ;
        __IO uint32_t stuck_phd_md               : 1  ;
        __IO uint32_t stuck_phd_en               : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_SENSE_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t rst_phd_fall_num           : 10 ;
        __IO uint32_t phd_all_fall_num           : 10 ;
        __IO uint32_t adc_in_phd_rise_num        : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_SENSE_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t fig_lv_adc_ref_bcon        : 2  ;
        __IO uint32_t pen_lv_adc_ref_bcon        : 2  ;
        __IO uint32_t pdrv_lv_adc_ref_bcon       : 2  ;
        __IO uint32_t fig_lv_adc_bcon            : 3  ;
        __IO uint32_t pen_lv_adc_bcon            : 3  ;
        __IO uint32_t pdrv_lv_adc_bcon           : 3  ;
        __IO uint32_t adc_clk_div_1p5            : 1  ;
        __IO uint32_t adc_stc_insel              : 1  ;
        __IO uint32_t fig_adc_comp_bias_ctl      : 1  ;
        __IO uint32_t pen_adc_comp_bias_ctl      : 1  ;
        __IO uint32_t pdrv_adc_comp_bias_ctl     : 1  ;
        __IO uint32_t fig_adc_mdac_comp_ctl      : 2  ;
        __IO uint32_t pen_adc_mdac_comp_ctl      : 2  ;
        __IO uint32_t pdrv_adc_mdac_comp_ctl     : 2  ;
        __IO uint32_t fig_adc_mdac_slew_ctl      : 1  ;
        __IO uint32_t pen_adc_mdac_slew_ctl      : 1  ;
        __IO uint32_t pdrv_adc_mdac_slew_ctl     : 1  ;
        __IO uint32_t fig_adc_ref_idrv_ctl       : 1  ;
        __IO uint32_t pen_adc_ref_idrv_ctl       : 1  ;
        __IO uint32_t pdrv_adc_ref_idrv_ctl      : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tADC_SENSE_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t pdb_hvbias                 : 1  ;
        __IO uint32_t pdb_hvc                    : 1  ;
        __IO uint32_t pdb_hvr                    : 1  ;
        __IO uint32_t pdb_lvbias                 : 1  ;
        __IO uint32_t pdb_int                    : 1  ;
        __IO uint32_t pdb_sha                    : 1  ;
        __IO uint32_t bgr_en                     : 1  ;
        __IO uint32_t bias_en                    : 1  ;
        __IO uint32_t pdb_adc                    : 1  ;
        __IO uint32_t stuck_hvbias               : 2  ;
        __IO uint32_t stuck_hvc                  : 2  ;
        __IO uint32_t stuck_hvr                  : 2  ;
        __IO uint32_t stuck_lvbias               : 2  ;
        __IO uint32_t stuck_int                  : 2  ;
        __IO uint32_t stuck_sha                  : 2  ;
        __IO uint32_t stuck_bgr_en               : 2  ;
        __IO uint32_t stuck_bias_en              : 2  ;
        __IO uint32_t stuck_adc                  : 2  ;
        __IO uint32_t pdb_hvr_shift_en           : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPDB_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t pdb_phd                    : 1  ;
        __IO uint32_t pdb_phd_buf                : 1  ;
        __IO uint32_t stuck_phd                  : 2  ;
        __IO uint32_t stuck_phd_buf              : 2  ;
        __IO uint32_t phd_en_op_num              : 10 ;
        __IO uint32_t phd_md_op_num              : 10 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPDB_PHD_CTL_t;

typedef union
{
    struct
    {
        __IO uint32_t adc_in_shift_num0          : 5  ;
        __IO uint32_t adc_in_shift_num1          : 5  ;
        __IO uint32_t adc_in_shift_num2          : 5  ;
        __IO uint32_t adc_in_shift_num3          : 5  ;
        __IO uint32_t adc_in_shift_num4          : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tADC_IN_SHIFT_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t adc_in_shift_num5          : 5  ;
        __IO uint32_t adc_in_shift_num6          : 5  ;
        __IO uint32_t adc_in_shift_num7          : 5  ;
        __IO uint32_t adc_in_shift_num8          : 5  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tADC_IN_SHIFT_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t r0_reserve                 : 4  ;
        __IO uint32_t r1_reserve                 : 4  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tR_RESERVE_t;

typedef union
{
    struct
    {
        __IO uint32_t sys_dummy0                 : 32 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSYS_DUMMY0_t;


typedef union
{
    struct
    {
        __IO uint32_t sys_dummy1                 : 32 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tSYS_DUMMY1_t;


typedef union
{
    struct
    {
        __IO uint32_t r0_tm_mon_en               : 1  ;
        __IO uint32_t r1_tm_mon_en               : 1  ;
        __IO uint32_t r0_tm_mon_s                : 3  ;
        __IO uint32_t r1_tm_mon_s                : 3  ;
        __IO uint32_t r0_pen_mode_en             : 1  ;
        __IO uint32_t r1_pen_mode_en             : 1  ;
        __IO uint32_t r0_tm_ssu_pen              : 1  ;
        __IO uint32_t r1_tm_ssu_pen              : 1  ;
        __IO uint32_t r0_test_adc_a              : 1  ;
        __IO uint32_t r0_test_adc_b              : 1  ;
        __IO uint32_t r1_test_adc_a              : 1  ;
        __IO uint32_t r1_test_adc_b              : 1  ;
        __IO uint32_t test_adc_sel               : 2  ;
        __IO uint32_t test_adc_dec               : 2  ;
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
        __IO uint32_t adc_skipnum                : 6  ;
        __IO uint32_t adc_th0                    : 12 ;
        __IO uint32_t adc_th1                    : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_CTL1_t;

typedef union
{
    struct
    {
        __IO uint32_t dly_th                     : 8  ;
        __IO uint32_t edgecnt_th                 : 4  ;
        __IO uint32_t offset_dly                 : 8  ;
        __IO uint32_t invalid_dly                : 8  ;
        __IO uint32_t sel_delay                  : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_CTL2_t;

typedef union
{
    struct
    {
        __IO uint32_t bypass_en                  : 1  ;
        __IO uint32_t coef_val                   : 8  ;
        __IO uint32_t offset_val                 : 8  ;
        __IO uint32_t adc_mon_data_sel           : 2  ;
        __IO uint32_t phd_mon_en                 : 1  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_CTL3_t;

typedef union
{
    struct
    {
        __IO uint32_t adc_mon_th_r               : 12 ;
        __IO uint32_t adc_mon_th_f               : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_CTL4_t;

typedef union
{
    struct
    {
        __I uint32_t insert_dly_val              : 8  ;
        __I uint32_t real0_edgecnt               : 4  ;
        __I uint32_t real1_edgecnt               : 4  ;
        __I uint32_t pos_dly0_buf                : 8  ;
        __I uint32_t pos_dly1_buf                : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_ST1_t;

typedef union
{
    struct
    {
        __I uint32_t pos_dly0_sum                : 12 ;
        __I uint32_t pos_dly1_sum                : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_ST2_t;

typedef union
{
    struct
    {
        __I uint32_t invalid_delay               : 2  ;
        __I uint32_t cal_delay                   : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tPHD_ST3_t;

typedef union
{
    struct
    {
        __I uint32_t mon_r0_adcdo_a              : 12 ;
        __I uint32_t reserve_zero                : 4  ;
        __I uint32_t mon_r0_adcdo_b              : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_R0_ADCDO_t;

typedef union
{
    struct
    {
        __I uint32_t mon_r1_adcdo_a              : 12 ;
        __I uint32_t reserve_zero                : 4  ;
        __I uint32_t mon_r1_adcdo_b              : 12 ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_R1_ADCDO_t;

typedef union
{
    struct
    {
        __I uint32_t reserved01                : 2  ;
        __I uint32_t cal_delay0                  : 8  ;
        __I uint32_t reserved02                : 6  ;
        __I uint32_t cal_delay1                  : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_CAL_DELAY_t;

typedef union
{
    struct
    {
        __I uint32_t reserved01                : 2  ;
        __I uint32_t r0_a_egsign                 : 8  ;
        __I uint32_t reserve_zero                : 6  ;
        __I uint32_t r0_b_egsign                 : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_EDGE_SIGN_R0_t;

typedef union
{
    struct
    {
        __I uint32_t reserved01                : 2  ;
        __I uint32_t r1_a_egsign                 : 8  ;
        __I uint32_t reserve_zero                : 6  ;
        __I uint32_t r1_b_egsign                 : 8  ;
    }__PACKED tBit;
    __IO uint32_t ulBulk;
}__PACKED tMON_EDGE_SIGN_R1_t;


typedef struct
{
        tPRODUCT_ID_t                        PRODUCT_ID          ;  // 0x0000    R    Default Val : 0x09850200
        tSPIS_CFG_t                          SPIS_CFG            ;  // 0x0004    R/W  Default Val : 0x00000003
        tSPIS_ERROR_CLR_t                    SPIS_ERROR_CLR      ;  // 0x0008    R/W  Default Val : 0x00000000
        tSPIS_ERROR_ST_t                     SPIS_ERROR_ST       ;  // 0x000C    R    Default Val : 0x00000000
        tSPIS_PAD_CTL_t                      SPIS_PAD_CTL        ;  // 0x0010    R/W  Default Val : 0x00011041
        tSYS_CFG_t                           SYS_CFG             ;  // 0x0014    R/W  Default Val : 0x0000000C
        tTC_START_t                          TC_START            ;  // 0x0018    R/W  Default Val : 0x00000000
        tR0_CH_EN_t                          R0_CH_EN            ;  // 0x001C    R/W  Default Val : 0x0003FFFC
        tR1_CH_EN_t                          R1_CH_EN            ;  // 0x0020    R/W  Default Val : 0x0003FFFC
        tCH_NUM_t                            CH_NUM              ;  // 0x0024    R/W  Default Val : 0x00820820
        tMUX_CTL_t                           MUX_CTL             ;  // 0x0028    R/W  Default Val : 0x00A00000
        tMUX_DLY_0_t                         MUX_DLY_0           ;  // 0x002C    R/W  Default Val : 0x00000000
        tMUX_DLY_1_t                         MUX_DLY_1           ;  // 0x0030    R/W  Default Val : 0x00000000
        tMUX_DLY_2_t                         MUX_DLY_2           ;  // 0x0034    R/W  Default Val : 0x00000000
        tSDIC_CFG_t                          SDIC_CFG            ;  // 0x0038    R/W  Default Val : 0x00100020
        tPWM_FIG_CTL_t                       PWM_FIG_CTL         ;  // 0x003C    R/W  Default Val : 0x0001C086
        tPWM_POS_CTL_t                       PWM_POS_CTL         ;  // 0x0040    R/W  Default Val : 0x001C0860
        tPWM_DAT_CTL_t                       PWM_DAT_CTL         ;  // 0x0044    R/W  Default Val : 0x0E043060
        tPWM_ND_CTL_t                        PWM_ND_CTL          ;  // 0x0048    R/W  Default Val : 0x001C0860
        tPWM_PRD_t                           PWM_PRD             ;  // 0x004C    R/W  Default Val : 0x0731CC73
        tSMPL_CTL_t                          SMPL_CTL            ;  // 0x0050    R/W  Default Val : 0x0001C387
        tRSTP_RISE_NUM_t                     RSTP_RISE_NUM       ;  // 0x0054    R/W  Default Val : 0x00E0380E
        tRSTP_FALL_NUM1_t                    RSTP_FALL_NUM1      ;  // 0x0058    R/W  Default Val : 0x00300C03
        tRSTP_FALL_NUM2_t                    RSTP_FALL_NUM2      ;  // 0x005C    R/W  Default Val : 0x00300C03
        tPHTCR_RISE_NUM_t                    PHTCR_RISE_NUM      ;  // 0x0060    R/W  Default Val : 0x05E1785E
        tPHTCR_FALL_NUM_t                    PHTCR_FALL_NUM      ;  // 0x0064    R/W  Default Val : 0x01E0781E
        tVCR_NUM_t                           VCR_NUM             ;  // 0x0068    R/W  Default Val : 0x05114451
        tRSTI_RISE_NUM_t                     RSTI_RISE_NUM       ;  // 0x006C    R/W  Default Val : 0x0350D435
        tRSTI_FALL_NUM1_t                    RSTI_FALL_NUM1      ;  // 0x0070    R/W  Default Val : 0x01B06C1B
        tRSTI_FALL_NUM2_t                    RSTI_FALL_NUM2      ;  // 0x0074    R/W  Default Val : 0x01B06C1B
        tPHTH0_RISE_NUM_t                    PHTH0_RISE_NUM      ;  // 0x0078    R/W  Default Val : 0x01104010
        tPHTH0_FALL_NUM_t                    PHTH0_FALL_NUM      ;  // 0x007C    R/W  Default Val : 0x01004010
        tPHTH1_RISE_NUM_t                    PHTH1_RISE_NUM      ;  // 0x0080    R/W  Default Val : 0x01004010
        tPHTH1_FALL_NUM_t                    PHTH1_FALL_NUM      ;  // 0x0084    R/W  Default Val : 0x01004010
        tPHT_CTL_t                           PHT_CTL             ;  // 0x0088    R/W  Default Val : 0x00082906
        tPHT_RISE_NUM_t                      PHT_RISE_NUM        ;  // 0x008C    R/W  Default Val : 0x0110442A
        tPHT_FALL_NUM_t                      PHT_FALL_NUM        ;  // 0x0090    R/W  Default Val : 0x0110442A
        tADC_CTL1_t                          ADC_CTL1            ;  // 0x0094    R/W  Default Val : 0x20000014
        tADC_CTL2_t                          ADC_CTL2            ;  // 0x0098    R/W  Default Val : 0x0E40809F
        tADC_CTL3_t                          ADC_CTL3            ;  // 0x009C    R/W  Default Val : 0x0000809F
        tVCOMR_OPT_t                         VCOMR_OPT           ;  // 0x00A0    R/W  Default Val : 0x00000000
        tBUF_OPT_t                           BUF_OPT             ;  // 0x00A4    R/W  Default Val : 0x00000003
        tTG_STUCK_t                          TG_STUCK            ;  // 0x00A8    R/W  Default Val : 0x60550000
        tADC_IN_t                            ADC_IN              ;  // 0x00AC    R/W  Default Val : 0x00000001
        tMUX_S_STUCK_VAL_t                   MUX_S_STUCK_VAL     ;  // 0x00B0    R/W  Default Val : 0x00000000
        tMUX_F_STUCK_VAL_t                   MUX_F_STUCK_VAL     ;  // 0x00B4    R/W  Default Val : 0x00000000
        tFIG_MUX_CFG_00_t                    FIG_MUX_CFG_00      ;  // 0x00B8    R/W  Default Val : 0x76543210
        tFIG_MUX_CFG_01_t                    FIG_MUX_CFG_01      ;  // 0x00BC    R/W  Default Val : 0x00000098
        tRCOM_LHB_CFG_t                      RCOM_LHB_CFG        ;  // 0x00C0    R/W  Default Val : 0x00000000
        tDEFA_LHB_MCFG00_t                   DEFA_LHB_MCFG00     ;  // 0x00C4    R/W  Default Val : 0x00000000
        tDEFA_LHB_MCFG01_t                   DEFA_LHB_MCFG01     ;  // 0x00C8    R/W  Default Val : 0x00000000
        tDEFA_LHB_MCFG02_t                   DEFA_LHB_MCFG02     ;  // 0x00CC    R/W  Default Val : 0x00000000
        tDEFA_LHB_MCFG03_t                   DEFA_LHB_MCFG03     ;  // 0x00D0    R/W  Default Val : 0x00000000
        tLHB_MUX_NUM_t                       LHB_MUX_NUM         ;  // 0x00D4    R/W  Default Val : 0x00000000
        tPEN_POS1_LHB_CFG_t                  PEN_POS1_LHB_CFG    ;  // 0x00D8    R/W  Default Val : 0x00000000
        tPEN_POS2_LHB_CFG_t                  PEN_POS2_LHB_CFG    ;  // 0x00DC    R/W  Default Val : 0x00000000
        tPEN_DAT1_LHB_CFG_t                  PEN_DAT1_LHB_CFG    ;  // 0x00E0    R/W  Default Val : 0x00000000
        tPEN_DAT2_LHB_CFG_t                  PEN_DAT2_LHB_CFG    ;  // 0x00E4    R/W  Default Val : 0x00000000
        tMUX_FCTL_NUM1_t                     MUX_FCTL_NUM1       ;  // 0x00E8    R/W  Default Val : 0x00000000
        tMUX_FCTL_NUM2_t                     MUX_FCTL_NUM2       ;  // 0x00EC    R/W  Default Val : 0x00000000
        tUPLINK_MUX_t                        UPLINK_MUX          ;  // 0x00F0    R/W  Default Val : 0x00000000
        tLHB_MUX_CTL_t                       LHB_MUX_CTL         ;  // 0x00F4    R/W  Default Val : 0x3FFFFFFF
        tPING_MUX_CTL_t                      PING_MUX_CTL        ;  // 0x00F8    R/W  Default Val : 0x00000000
        tPRE_DRV_CTL_t                       PRE_DRV_CTL         ;  // 0x00FC    R/W  Default Val : 0x00000000
        tR0_CR_MUX1_1_t                      R0_CR_MUX1_1[6]        ;  // 0x0100    R/W  Default Val : 0x00000000
        tR0_CR_MUX1_2_t                      R0_CR_MUX1_2[6]        ;  // 0x0104    R/W  Default Val : 0x00000000
        tR0_CR_MUX2_1_t                      R0_CR_MUX2_1[6]        ;  // 0x0108    R/W  Default Val : 0x00000000
        tR0_CR_MUX2_2_t                      R0_CR_MUX2_2[6]        ;  // 0x010C    R/W  Default Val : 0x00000000
        tR0_CR_MUX3_1_t                      R0_CR_MUX3_1[6]        ;  // 0x0110    R/W  Default Val : 0x00000000
        tR0_CR_MUX3_2_t                      R0_CR_MUX3_2[6]        ;  // 0x0114    R/W  Default Val : 0x00000000
        tR0_CR_MUX4_1_t                      R0_CR_MUX4_1[6]        ;  // 0x0118    R/W  Default Val : 0x00000000
        tR0_CR_MUX4_2_t                      R0_CR_MUX4_2[6]        ;  // 0x011C    R/W  Default Val : 0x00000000
        tR0_CR_MUX5_1_t                      R0_CR_MUX5_1[6]        ;  // 0x0120    R/W  Default Val : 0x00000000
        tR0_CR_MUX5_2_t                      R0_CR_MUX5_2[6]        ;  // 0x0124    R/W  Default Val : 0x00000000
        tR0_CR_MUX6_1_t                      R0_CR_MUX6_1[6]        ;  // 0x0128    R/W  Default Val : 0x00000000
        tR0_CR_MUX6_2_t                      R0_CR_MUX6_2[6]        ;  // 0x012C    R/W  Default Val : 0x00000000
        tR0_CR_M1_t                          R0_CR_M1            ;  // 0x0130    R/W  Default Val : 0x00000000
        tR1_CR_MUX1_1_t                      R1_CR_MUX1_1[6]        ;  // 0x0134    R/W  Default Val : 0x00000000
        tR1_CR_MUX1_2_t                      R1_CR_MUX1_2[6]        ;  // 0x0138    R/W  Default Val : 0x00000000
        tR1_CR_MUX2_1_t                      R1_CR_MUX2_1[6]        ;  // 0x013C    R/W  Default Val : 0x00000000
        tR1_CR_MUX2_2_t                      R1_CR_MUX2_2[6]        ;  // 0x0140    R/W  Default Val : 0x00000000
        tR1_CR_MUX3_1_t                      R1_CR_MUX3_1[6]        ;  // 0x0144    R/W  Default Val : 0x00000000
        tR1_CR_MUX3_2_t                      R1_CR_MUX3_2[6]        ;  // 0x0148    R/W  Default Val : 0x00000000
        tR1_CR_MUX4_1_t                      R1_CR_MUX4_1[6]        ;  // 0x014C    R/W  Default Val : 0x00000000
        tR1_CR_MUX4_2_t                      R1_CR_MUX4_2[6]        ;  // 0x0150    R/W  Default Val : 0x00000000
        tR1_CR_MUX5_1_t                      R1_CR_MUX5_1[6]        ;  // 0x0154    R/W  Default Val : 0x00000000
        tR1_CR_MUX5_2_t                      R1_CR_MUX5_2[6]        ;  // 0x0158    R/W  Default Val : 0x00000000
        tR1_CR_MUX6_1_t                      R1_CR_MUX6_1[6]        ;  // 0x015C    R/W  Default Val : 0x00000000
        tR1_CR_MUX6_2_t                      R1_CR_MUX6_2[6]        ;  // 0x0160    R/W  Default Val : 0x00000000
        tR1_CR_M1_t                          R1_CR_M1            ;  // 0x0164    R/W  Default Val : 0x00000000
        tR_CR_ND_t                           R_CR_ND             ;  // 0x0168    R/W  Default Val : 0x00000000
        tR_CR_GTUNE_t                        R_CR_GTUNE[6]          ;  // 0x016C    R/W  Default Val : 0x00000000
 //       tRESERVED_1_t                        RESERVED_1          ;  // 0x0170    R/W  Default Val : 0x00000000
 //       tRESERVED_2_t                        RESERVED_2          ;  // 0x0174    R/W  Default Val : 0x00000000
 //       tRESERVED_3_t                        RESERVED_3          ;  // 0x0178    R/W  Default Val : 0x00000000
 //       tRESERVED_4_t                        RESERVED_4          ;  // 0x017C    R/W  Default Val : 0x00000000
        tR0_TUNE_ROW_MUX1_t                  R0_TUNE_ROW_MUX1    ;  // 0x0180    R/W  Default Val : 0x0002AAA4
        tR0_TUNE_ROW_MUX2_t                  R0_TUNE_ROW_MUX2    ;  // 0x0184    R/W  Default Val : 0x0002AAA4
        tR0_TUNE_ROW_MUX3_t                  R0_TUNE_ROW_MUX3    ;  // 0x0188    R/W  Default Val : 0x0002AAA4
        tR0_TUNE_ROW_MUX4_t                  R0_TUNE_ROW_MUX4    ;  // 0x018C    R/W  Default Val : 0x0002AAA4
        tR0_TUNE_ROW_MUX5_t                  R0_TUNE_ROW_MUX5    ;  // 0x0190    R/W  Default Val : 0x0002AAA4
        tR0_TUNE_ROW_MUX6_t                  R0_TUNE_ROW_MUX6    ;  // 0x0194    R/W  Default Val : 0x0002AAA4
        tR1_TUNE_ROW_MUX1_t                  R1_TUNE_ROW_MUX1    ;  // 0x0198    R/W  Default Val : 0x0002AAA4
        tR1_TUNE_ROW_MUX2_t                  R1_TUNE_ROW_MUX2    ;  // 0x019C    R/W  Default Val : 0x0002AAA4
        tR1_TUNE_ROW_MUX3_t                  R1_TUNE_ROW_MUX3    ;  // 0x01A0    R/W  Default Val : 0x0002AAA4
        tR1_TUNE_ROW_MUX4_t                  R1_TUNE_ROW_MUX4    ;  // 0x01A4    R/W  Default Val : 0x0002AAA4
        tR1_TUNE_ROW_MUX5_t                  R1_TUNE_ROW_MUX5    ;  // 0x01A8    R/W  Default Val : 0x0002AAA4
        tR1_TUNE_ROW_MUX6_t                  R1_TUNE_ROW_MUX6    ;  // 0x01AC    R/W  Default Val : 0x0002AAA4
        tR_TUNE_GROUP_COL_t                  R_TUNE_GROUP_COL    ;  // 0x01B0    R/W  Default Val : 0x000A92A4
        tSD_PWRCR1_t                         SD_PWRCR1           ;  // 0x01B4    R/W  Default Val : 0x0000000F
        tSD_PWRCR2_t                         SD_PWRCR2           ;  // 0x01B8    R/W  Default Val : 0x00000000
        tSD_PWRCR3_t                         SD_PWRCR3           ;  // 0x01BC    R/W  Default Val : 0x00000000
        tSD_PWRCR4_t                         SD_PWRCR4           ;  // 0x01C0    R/W  Default Val : 0x00000000
        tSD_PWRCR5_t                         SD_PWRCR5           ;  // 0x01C4    R/W  Default Val : 0x00000000
        tSD_PWRCR6_t                         SD_PWRCR6           ;  // 0x01C8    R/W  Default Val : 0x00000000
        tSD_PWRCR7_t                         SD_PWRCR7           ;  // 0x01CC    R/W  Default Val : 0x00000000
        tAFE_SENSE_CTL1_t                    AFE_SENSE_CTL1      ;  // 0x01D0    R/W  Default Val : 0x00124800
        tAFE_SENSE_CTL2_t                    AFE_SENSE_CTL2      ;  // 0x01D4    R/W  Default Val : 0x7F07FFFF
        tAFE_SENSE_CTL3_t                    AFE_SENSE_CTL3      ;  // 0x01D8    R/W  Default Val : 0x00291249
        tPHD_SENSE_CTL1_t                    PHD_SENSE_CTL1      ;  // 0x01DC    R/W  Default Val : 0x0000028B
        tPHD_SENSE_CTL2_t                    PHD_SENSE_CTL2      ;  // 0x01E0    R/W  Default Val : 0x00000000
        tADC_SENSE_CTL_t                     ADC_SENSE_CTL       ;  // 0x01E4    R/W  Default Val : 0x015036D5
        tPDB_CTL_t                           PDB_CTL             ;  // 0x01E8    R/W  Default Val : 0x000000C0
        tPDB_PHD_CTL_t                       PDB_PHD_CTL         ;  // 0x01EC    R/W  Default Val : 0x00190640
        tADC_IN_SHIFT_CTL1_t                 ADC_IN_SHIFT_CTL1   ;  // 0x01F0    R/W  Default Val : 0x00E51C60
        tADC_IN_SHIFT_CTL2_t                 ADC_IN_SHIFT_CTL2   ;  // 0x01F4    R/W  Default Val : 0x000E62B1
        tR_RESERVE_t                         R_RESERVE           ;  // 0x01F8    R/W  Default Val : 0x00000000
        tSYS_DUMMY0_t                        SYS_DUMMY0          ;  // 0x01FC    R/W  Default Val : 0x00000000
        tSYS_DUMMY1_t                        SYS_DUMMY1          ;  // 0x0200    R/W  Default Val : 0xFFFFFFFF
        tTEST_MUX_CTL_t                      TEST_MUX_CTL        ;  // 0x0204    R/W  Default Val : 0x00000000
        tPHD_CTL1_t                          PHD_CTL1            ;  // 0x0208    R/W  Default Val : 0x00000000
        tPHD_CTL2_t                          PHD_CTL2            ;  // 0x020C    R/W  Default Val : 0x00000000
        tPHD_CTL3_t                          PHD_CTL3            ;  // 0x0210    R/W  Default Val : 0x00000000
        tPHD_CTL4_t                          PHD_CTL4            ;  // 0x0214    R/W  Default Val : 0x00000000
        tPHD_ST1_t                           PHD_ST1             ;  // 0x0218    R    Default Val : 0x00000000
        tPHD_ST2_t                           PHD_ST2             ;  // 0x021C    R    Default Val : 0x00000000
        tPHD_ST3_t                          PHD_ST3             ;  // 0x0220    R    Default Val : 0x00000000
        tMON_R0_ADCDO_t                      MON_R0_ADCDO        ;  // 0x0224    R    Default Val : 0x00000000
        tMON_R1_ADCDO_t                      MON_R1_ADCDO        ;  // 0x0228    R    Default Val : 0x00000000
        tMON_CAL_DELAY_t                     MON_CAL_DELAY       ;  // 0x07F4    R    Default Val : 0x00000000
        tMON_EDGE_SIGN_R0_t                  MON_EDGE_SIGN_R0    ;  // 0x07F8    R    Default Val : 0x00000000
        tMON_EDGE_SIGN_R1_t                  MON_EDGE_SIGN_R1    ;  // 0x07FC    R    Default Val : 0x00000000
} __PACKED tModuleSRICCommonConf_t;

#include "_sw98502_parampreset.h" 

#endif /* (USED_ROIC_DEF == ROIC_SW98502) */

#endif /* __SW98502_CONF_H_ */ 

