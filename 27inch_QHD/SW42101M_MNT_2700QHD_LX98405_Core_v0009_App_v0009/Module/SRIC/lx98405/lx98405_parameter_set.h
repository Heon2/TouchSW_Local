//-------------------------------------------------------
//-   Reg Setting Auto Generation                        
//-------------------------------------------------------


#ifndef __LX98405_PARAMETERSET_H_
#define __LX98405_PARAMETERSET_H_

#if (1)//(USED_ROIC_DEF == ROIC_LX98405)
#define SRIC_Conf_Set \
 .INTERFACE_CFG = \
 { \
  .tBit.tg_clk_on = PARAMSET_ROIC_INTERFACE_CFG_tg_clk_on, \
  .tBit.cfclk_on = PARAMSET_ROIC_INTERFACE_CFG_cfclk_on, \
  .tBit.spis_chksum_opt = PARAMSET_ROIC_INTERFACE_CFG_spis_chksum_opt, \
  .tBit.spis_irq_en = PARAMSET_ROIC_INTERFACE_CFG_spis_irq_en, \
  .tBit.tlvds_chksum_inv = PARAMSET_ROIC_INTERFACE_CFG_tlvds_chksum_inv, \
  .tBit.tlvds_irq_en = PARAMSET_ROIC_INTERFACE_CFG_tlvds_irq_en, \
  .tBit.tlvds_sclk_on = PARAMSET_ROIC_INTERFACE_CFG_tlvds_sclk_on, \
  .tBit.tlvds_sclk_to_data = PARAMSET_ROIC_INTERFACE_CFG_tlvds_sclk_to_data, \
  .tBit.tlvds_op_case = PARAMSET_ROIC_INTERFACE_CFG_tlvds_op_case, \
  .tBit.rbuf_addr_bit_md0 = PARAMSET_ROIC_INTERFACE_CFG_rbuf_addr_bit_md0, \
  .tBit.rbuf_addr_bit_md1 = PARAMSET_ROIC_INTERFACE_CFG_rbuf_addr_bit_md1, \
 } ,\
 .SPIS_PAD_CTL = \
 { \
  .tBit.miso_ds = PARAMSET_ROIC_SPIS_PAD_CTL_miso_ds, \
  .tBit.miso_dout = PARAMSET_ROIC_SPIS_PAD_CTL_miso_dout, \
  .tBit.miso_func = PARAMSET_ROIC_SPIS_PAD_CTL_miso_func, \
  .tBit.mosi_ds = PARAMSET_ROIC_SPIS_PAD_CTL_mosi_ds, \
  .tBit.mosi_dout = PARAMSET_ROIC_SPIS_PAD_CTL_mosi_dout, \
  .tBit.mosi_func = PARAMSET_ROIC_SPIS_PAD_CTL_mosi_func, \
  .tBit.tst_out0_out = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out0_out, \
  .tBit.tst_out0_oe = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out0_oe, \
  .tBit.tst_out0_ds = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out0_ds, \
  .tBit.tst_out0_func = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out0_func, \
  .tBit.tst_out0_sel0 = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out0_sel0, \
  .tBit.tst_out0_sel1 = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out0_sel1, \
  .tBit.tst_out0_func2 = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out0_func2, \
  .tBit.tst_out0_test = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out0_test, \
  .tBit.tst_out1_out = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out1_out, \
  .tBit.tst_out1_oe = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out1_oe, \
  .tBit.tst_out1_ds = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out1_ds, \
  .tBit.tst_out1_func = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out1_func, \
  .tBit.tst_out1_sel0 = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out1_sel0, \
  .tBit.tst_out1_sel1 = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out1_sel1, \
  .tBit.tst_out1_func2 = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out1_func2, \
  .tBit.tst_out1_test = PARAMSET_ROIC_SPIS_PAD_CTL_tst_out1_test, \
 } ,\
 .LVDS_PHY_CTL = \
 { \
  .tBit.tlvds_vod_ctrl = PARAMSET_ROIC_LVDS_PHY_CTL_tlvds_vod_ctrl, \
  .tBit.tlvds_vocm_ctrl = PARAMSET_ROIC_LVDS_PHY_CTL_tlvds_vocm_ctrl, \
  .tBit.tlvds_rx_bcon = PARAMSET_ROIC_LVDS_PHY_CTL_tlvds_rx_bcon, \
  .tBit.tlvds_rext_en = PARAMSET_ROIC_LVDS_PHY_CTL_tlvds_rext_en, \
  .tBit.tlvds_vocm_sel = PARAMSET_ROIC_LVDS_PHY_CTL_tlvds_vocm_sel, \
  .tBit.pdb_tlvds_bias = PARAMSET_ROIC_LVDS_PHY_CTL_pdb_tlvds_bias, \
  .tBit.pdb_tlvds_mcsn_ctl = PARAMSET_ROIC_LVDS_PHY_CTL_pdb_tlvds_mcsn_ctl, \
  .tBit.pdb_tlvds_mclk_ctl = PARAMSET_ROIC_LVDS_PHY_CTL_pdb_tlvds_mclk_ctl, \
  .tBit.pdb_tlvds_mdat_ctl = PARAMSET_ROIC_LVDS_PHY_CTL_pdb_tlvds_mdat_ctl, \
  .tBit.pdb_tlvds_sclk_ctl = PARAMSET_ROIC_LVDS_PHY_CTL_pdb_tlvds_sclk_ctl, \
  .tBit.pdb_tlvds_sdat_ctl = PARAMSET_ROIC_LVDS_PHY_CTL_pdb_tlvds_sdat_ctl, \
  .tBit.pdb_tlvds_eclk = PARAMSET_ROIC_LVDS_PHY_CTL_pdb_tlvds_eclk, \
  .tBit.pdb_tlvds_pwm_tx_ctl = PARAMSET_ROIC_LVDS_PHY_CTL_pdb_tlvds_pwm_tx_ctl, \
  .tBit.eclk_sel = PARAMSET_ROIC_LVDS_PHY_CTL_eclk_sel, \
  .tBit.pwm_tx_sel = PARAMSET_ROIC_LVDS_PHY_CTL_pwm_tx_sel, \
  .tBit.tlvds_sclk_en_ctl = PARAMSET_ROIC_LVDS_PHY_CTL_tlvds_sclk_en_ctl, \
  .tBit.tlvds_sdat_en_ctl = PARAMSET_ROIC_LVDS_PHY_CTL_tlvds_sdat_en_ctl, \
  .tBit.tlvds_pattern_en = PARAMSET_ROIC_LVDS_PHY_CTL_tlvds_pattern_en, \
 } ,\
 .TLVDS_DUM0 = \
 { \
  .tBit.tlvds_dum0 = 0xA5A59669, \
 } ,\
 .TLVDS_DUM1 = \
 { \
  .tBit.tlvds_dum1 = 0x9669A5A5, \
 } ,\
 .SYS_CFG = \
 { \
  .tBit.reset_one_write_en = PARAMSET_ROIC_SYS_CFG_reset_one_write_en, \
  .tBit.sw_reset = PARAMSET_ROIC_SYS_CFG_sw_reset, \
  .tBit.tg_reset = PARAMSET_ROIC_SYS_CFG_tg_reset, \
  .tBit.buf_reset = PARAMSET_ROIC_SYS_CFG_buf_reset, \
  .tBit.chksum_clr = PARAMSET_ROIC_SYS_CFG_chksum_clr, \
  .tBit.tsync_pwm_fault_clr = PARAMSET_ROIC_SYS_CFG_tsync_pwm_fault_clr, \
  .tBit.defend_option = PARAMSET_ROIC_SYS_CFG_defend_option, \
 } ,\
 .SDIC_CFG = \
 { \
  .tBit.vsync_pol = 0, \
  .tBit.vsync_tg_en = 0, \
  .tBit.vsync_tg_act = 0, \
  .tBit.tsync_in_pol = 0, \
  .tBit.pwm_pol = 0, \
  .tBit.sd_rocen = PARAMSET_ROIC_SDIC_CFG_sd_rocen, \
  .tBit.sd_off_ctl = PARAMSET_ROIC_SDIC_CFG_sd_off_ctl, \
  .tBit.sd_float_0_ctl = PARAMSET_ROIC_SDIC_CFG_sd_float_0_ctl, \
  .tBit.sd_float_1_ctl = PARAMSET_ROIC_SDIC_CFG_sd_float_1_ctl, \
  .tBit.sd_gnd_0_ctl = PARAMSET_ROIC_SDIC_CFG_sd_gnd_0_ctl, \
  .tBit.sd_gnd_1_ctl = PARAMSET_ROIC_SDIC_CFG_sd_gnd_1_ctl, \
  .tBit.r0_ropd = 0, \
  .tBit.r1_ropd = 0, \
 } ,\
 .TC_START = \
 { \
  .tBit.tc_start = 0x00000000, \
 } ,\
 .CH_MUX_NUM = \
 { \
  .tBit.ch_tot_num = PARAMSET_ROIC_CH_MUX_NUM_ch_tot_num, \
  .tBit.roic_tsync_num = PARAMSET_ROIC_CH_MUX_NUM_roic_tsync_num, \
  .tBit.mux_st_num = PARAMSET_ROIC_CH_MUX_NUM_mux_st_num, \
 } ,\
 .LHB_MUX_CTL = \
 { \
  .tBit.md0_tot_mux_num = PARAMSET_ROIC_LHB_MUX_CTL_md0_tot_mux_num, \
  .tBit.md1_tot_mux_num = PARAMSET_ROIC_LHB_MUX_CTL_md1_tot_mux_num, \
  .tBit.md0_lhb_mux_num = PARAMSET_ROIC_LHB_MUX_CTL_md0_lhb_mux_num, \
  .tBit.md1_lhb_mux_num = PARAMSET_ROIC_LHB_MUX_CTL_md1_lhb_mux_num, \
  .tBit.md0_freq_sel = PARAMSET_ROIC_LHB_MUX_CTL_md0_freq_sel, \
  .tBit.md1_freq_sel = PARAMSET_ROIC_LHB_MUX_CTL_md1_freq_sel, \
  .tBit.nd_freq_sel = PARAMSET_ROIC_LHB_MUX_CTL_nd_freq_sel, \
 } ,\
 .MD_PWM_CTL = \
 { \
  .tBit.md0_pwm_dum_num = PARAMSET_ROIC_MD_PWM_CTL_md0_pwm_dum_num, \
  .tBit.md0_pwm_act_num = PARAMSET_ROIC_MD_PWM_CTL_md0_pwm_act_num, \
  .tBit.md0_pwm_mgap_num = PARAMSET_ROIC_MD_PWM_CTL_md0_pwm_mgap_num, \
  .tBit.md1_pwm_dum_num = PARAMSET_ROIC_MD_PWM_CTL_md1_pwm_dum_num, \
  .tBit.md1_pwm_act_num = PARAMSET_ROIC_MD_PWM_CTL_md1_pwm_act_num, \
  .tBit.md1_pwm_mgap_num = PARAMSET_ROIC_MD_PWM_CTL_md1_pwm_mgap_num, \
 } ,\
 .MD0_MUX_CFG_00 = \
 { \
  .tBit.md0_mux_00 = PARAMSET_ROIC_MD0_MUX_CFG_00_md0_mux_00, \
  .tBit.md0_mux_01 = PARAMSET_ROIC_MD0_MUX_CFG_00_md0_mux_01, \
  .tBit.md0_mux_02 = PARAMSET_ROIC_MD0_MUX_CFG_00_md0_mux_02, \
  .tBit.md0_mux_03 = PARAMSET_ROIC_MD0_MUX_CFG_00_md0_mux_03, \
  .tBit.md0_mux_04 = PARAMSET_ROIC_MD0_MUX_CFG_00_md0_mux_04, \
  .tBit.md0_mux_05 = PARAMSET_ROIC_MD0_MUX_CFG_00_md0_mux_05, \
  .tBit.md0_mux_06 = PARAMSET_ROIC_MD0_MUX_CFG_00_md0_mux_06, \
  .tBit.md0_mux_07 = PARAMSET_ROIC_MD0_MUX_CFG_00_md0_mux_07, \
 } ,\
 .MD0_MUX_CFG_01 = \
 { \
  .tBit.md0_mux_08 = PARAMSET_ROIC_MD0_MUX_CFG_01_md0_mux_08, \
  .tBit.md0_mux_09 = PARAMSET_ROIC_MD0_MUX_CFG_01_md0_mux_09, \
  .tBit.md0_mux_10 = PARAMSET_ROIC_MD0_MUX_CFG_01_md0_mux_10, \
  .tBit.md0_mux_11 = PARAMSET_ROIC_MD0_MUX_CFG_01_md0_mux_11, \
  .tBit.md0_mux_12 = PARAMSET_ROIC_MD0_MUX_CFG_01_md0_mux_12, \
  .tBit.md0_mux_13 = PARAMSET_ROIC_MD0_MUX_CFG_01_md0_mux_13, \
  .tBit.md1_mux_00 = PARAMSET_ROIC_MD0_MUX_CFG_01_md1_mux_00, \
  .tBit.md1_mux_01 = PARAMSET_ROIC_MD0_MUX_CFG_01_md1_mux_01, \
 } ,\
 .DEFA_LHB_MCFG00 = \
 { \
  .tBit.lhb_mode01 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode01, \
  .tBit.lhb_mode02 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode02, \
  .tBit.lhb_mode03 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode03, \
  .tBit.lhb_mode04 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode04, \
  .tBit.lhb_mode05 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode05, \
  .tBit.lhb_mode06 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode06, \
  .tBit.lhb_mode07 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode07, \
  .tBit.lhb_mode08 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode08, \
  .tBit.lhb_mode09 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode09, \
  .tBit.lhb_mode10 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode10, \
  .tBit.lhb_mode11 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode11, \
  .tBit.lhb_mode12 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode12, \
  .tBit.lhb_mode13 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode13, \
  .tBit.lhb_mode14 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode14, \
  .tBit.lhb_mode15 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode15, \
  .tBit.lhb_mode16 = PARAMSET_ROIC_DEFA_LHB_MCFG00_lhb_mode16, \
 } ,\
 .PWM_PRD = \
 { \
  .tBit.f1_pwm_prd = PARAMSET_ROIC_PWM_PRD_f1_pwm_prd, \
  .tBit.f2_pwm_prd = PARAMSET_ROIC_PWM_PRD_f2_pwm_prd, \
  .tBit.nd_pwm_prd_margin = PARAMSET_ROIC_PWM_PRD_nd_pwm_prd_margin, \
 } ,\
 .PWM_MUX_DLY_PRD = \
 { \
  .tBit.pwm_mux1_dly = PARAMSET_ROIC_PWM_MUX_DLY_PRD_pwm_mux1_dly, \
  .tBit.pwm_mux2_dly = PARAMSET_ROIC_PWM_MUX_DLY_PRD_pwm_mux2_dly, \
  .tBit.pwm_mux3_dly = PARAMSET_ROIC_PWM_MUX_DLY_PRD_pwm_mux3_dly, \
  .tBit.pwm_mux4_dly = PARAMSET_ROIC_PWM_MUX_DLY_PRD_pwm_mux4_dly, \
  .tBit.pwm_mux5_dly = PARAMSET_ROIC_PWM_MUX_DLY_PRD_pwm_mux5_dly, \
  .tBit.pwm_mux6_dly = PARAMSET_ROIC_PWM_MUX_DLY_PRD_pwm_mux6_dly, \
  .tBit.pwm_mux7_dly = PARAMSET_ROIC_PWM_MUX_DLY_PRD_pwm_mux7_dly, \
  .tBit.pwm_mux8_dly = PARAMSET_ROIC_PWM_MUX_DLY_PRD_pwm_mux8_dly, \
  .tBit.pwm_mux9_dly = PARAMSET_ROIC_PWM_MUX_DLY_PRD_pwm_mux9_dly, \
  .tBit.pwm_mux10_dly = PARAMSET_ROIC_PWM_MUX_DLY_PRD_pwm_mux10_dly, \
  .tBit.pwm_mux11_dly = PARAMSET_ROIC_PWM_MUX_DLY_PRD_pwm_mux11_dly, \
 } ,\
 .AFE_SIG_CTL = \
 { \
  .tBit.cvc1_drv_init = PARAMSET_ROIC_AFE_SIG_CTL_cvc1_drv_init, \
  .tBit.cvc1_rstp_dum_en = PARAMSET_ROIC_AFE_SIG_CTL_cvc1_rstp_dum_en, \
  .tBit.vcr_dum_en = PARAMSET_ROIC_AFE_SIG_CTL_vcr_dum_en, \
  .tBit.vcr_inv_en = PARAMSET_ROIC_AFE_SIG_CTL_vcr_inv_en, \
  .tBit.phtcr_dum_en = PARAMSET_ROIC_AFE_SIG_CTL_phtcr_dum_en, \
  .tBit.cvc1_drv_rstp_dly = PARAMSET_ROIC_AFE_SIG_CTL_cvc1_drv_rstp_dly, \
 } ,\
 .F1_CVC1_DRV_CTL1 = \
 { \
  .tBit.f1_cvc1_drv_rise_num = PARAMSET_ROIC_F1_CVC1_DRV_CTL1_f1_cvc1_drv_rise_num, \
  .tBit.f1_cvc1_drv_fall_num = PARAMSET_ROIC_F1_CVC1_DRV_CTL1_f1_cvc1_drv_fall_num, \
  .tBit.f1_cvc1_drv_d_rise_num = PARAMSET_ROIC_F1_CVC1_DRV_CTL1_f1_cvc1_drv_d_rise_num, \
  .tBit.f1_cvc1_drv_d_fall_num = PARAMSET_ROIC_F1_CVC1_DRV_CTL1_f1_cvc1_drv_d_fall_num, \
 } ,\
 .F1_RSTP_PHT_CTL = \
 { \
  .tBit.f1_rstp_rise_num = PARAMSET_ROIC_F1_RSTP_PHT_CTL_f1_rstp_rise_num, \
  .tBit.f1_rstp_fall_num = PARAMSET_ROIC_F1_RSTP_PHT_CTL_f1_rstp_fall_num, \
  .tBit.f1_pht0_rise_num = PARAMSET_ROIC_F1_RSTP_PHT_CTL_f1_pht0_rise_num, \
  .tBit.f1_pht0_fall_num = PARAMSET_ROIC_F1_RSTP_PHT_CTL_f1_pht0_fall_num, \
 } ,\
 .F1_PHTCR_VCR_CTL = \
 { \
  .tBit.f1_phtcr_rise_num = PARAMSET_ROIC_F1_PHTCR_VCR_CTL_f1_phtcr_rise_num, \
  .tBit.f1_phtcr_fall_num = PARAMSET_ROIC_F1_PHTCR_VCR_CTL_f1_phtcr_fall_num, \
  .tBit.f1_smop_prd = PARAMSET_ROIC_F1_PHTCR_VCR_CTL_f1_smop_prd, \
  .tBit.f1_cr_repeat_num = PARAMSET_ROIC_F1_PHTCR_VCR_CTL_f1_cr_repeat_num, \
  .tBit.f1_vcr_num = PARAMSET_ROIC_F1_PHTCR_VCR_CTL_f1_vcr_num, \
 } ,\
 .F1_RSTI_CTL = \
 { \
  .tBit.f1_rsti_rise_num = PARAMSET_ROIC_F1_RSTI_CTL_f1_rsti_rise_num, \
  .tBit.f1_rsti_fall_num1 = PARAMSET_ROIC_F1_RSTI_CTL_f1_rsti_fall_num1, \
  .tBit.f1_rsti_fall_num2 = PARAMSET_ROIC_F1_RSTI_CTL_f1_rsti_fall_num2, \
 } ,\
 .F1_PHTH_CTL = \
 { \
  .tBit.f1_phth0_rise_num = PARAMSET_ROIC_F1_PHTH_CTL_f1_phth0_rise_num, \
  .tBit.f1_phth0_fall_num = PARAMSET_ROIC_F1_PHTH_CTL_f1_phth0_fall_num, \
  .tBit.f1_phth1_rise_num = PARAMSET_ROIC_F1_PHTH_CTL_f1_phth1_rise_num, \
  .tBit.f1_phth1_fall_num = PARAMSET_ROIC_F1_PHTH_CTL_f1_phth1_fall_num, \
 } ,\
 .F2_CVC1_DRV_CTL1 = \
 { \
  .tBit.f2_cvc1_drv_rise_num = PARAMSET_ROIC_F2_CVC1_DRV_CTL1_f2_cvc1_drv_rise_num, \
  .tBit.f2_cvc1_drv_fall_num = PARAMSET_ROIC_F2_CVC1_DRV_CTL1_f2_cvc1_drv_fall_num, \
  .tBit.f2_cvc1_drv_d_rise_num = PARAMSET_ROIC_F2_CVC1_DRV_CTL1_f2_cvc1_drv_d_rise_num, \
  .tBit.f2_cvc1_drv_d_fall_num = PARAMSET_ROIC_F2_CVC1_DRV_CTL1_f2_cvc1_drv_d_fall_num, \
 } ,\
 .F2_RSTP_PHT_CTL = \
 { \
  .tBit.f2_rstp_rise_num = PARAMSET_ROIC_F2_RSTP_PHT_CTL_f2_rstp_rise_num, \
  .tBit.f2_rstp_fall_num = PARAMSET_ROIC_F2_RSTP_PHT_CTL_f2_rstp_fall_num, \
  .tBit.f2_pht0_rise_num = PARAMSET_ROIC_F2_RSTP_PHT_CTL_f2_pht0_rise_num, \
  .tBit.f2_pht0_fall_num = PARAMSET_ROIC_F2_RSTP_PHT_CTL_f2_pht0_fall_num, \
 } ,\
 .F2_PHTCR_VCR_CTL = \
 { \
  .tBit.f2_phtcr_rise_num = PARAMSET_ROIC_F2_PHTCR_VCR_CTL_f2_phtcr_rise_num, \
  .tBit.f2_phtcr_fall_num = PARAMSET_ROIC_F2_PHTCR_VCR_CTL_f2_phtcr_fall_num, \
  .tBit.f2_smop_prd = PARAMSET_ROIC_F2_PHTCR_VCR_CTL_f2_smop_prd, \
  .tBit.f2_cr_repeat_num = PARAMSET_ROIC_F2_PHTCR_VCR_CTL_f2_cr_repeat_num, \
  .tBit.f2_vcr_num = PARAMSET_ROIC_F2_PHTCR_VCR_CTL_f2_vcr_num, \
 } ,\
 .F2_RSTI_CTL = \
 { \
  .tBit.f2_rsti_rise_num = PARAMSET_ROIC_F2_RSTI_CTL_f2_rsti_rise_num, \
  .tBit.f2_rsti_fall_num1 = PARAMSET_ROIC_F2_RSTI_CTL_f2_rsti_fall_num1, \
  .tBit.f2_rsti_fall_num2 = PARAMSET_ROIC_F2_RSTI_CTL_f2_rsti_fall_num2, \
 } ,\
 .F2_PHTH_CTL = \
 { \
  .tBit.f2_phth0_rise_num = PARAMSET_ROIC_F2_PHTH_CTL_f2_phth0_rise_num, \
  .tBit.f2_phth0_fall_num = PARAMSET_ROIC_F2_PHTH_CTL_f2_phth0_fall_num, \
  .tBit.f2_phth1_rise_num = PARAMSET_ROIC_F2_PHTH_CTL_f2_phth1_rise_num, \
  .tBit.f2_phth1_fall_num = PARAMSET_ROIC_F2_PHTH_CTL_f2_phth1_fall_num, \
 } ,\
 .PHT_CTL = \
 { \
  .tBit.pht_prd = PARAMSET_ROIC_PHT_CTL_pht_prd, \
  .tBit.pht_opt_inv = PARAMSET_ROIC_PHT_CTL_pht_opt_inv, \
  .tBit.pht_end_time = PARAMSET_ROIC_PHT_CTL_pht_end_time, \
  .tBit.pre_pht_sel = PARAMSET_ROIC_PHT_CTL_pre_pht_sel, \
  .tBit.pht_act_pwm_num = PARAMSET_ROIC_PHT_CTL_pht_act_pwm_num, \
  .tBit.pht_act_pwr_num = PARAMSET_ROIC_PHT_CTL_pht_act_pwr_num, \
 } ,\
 .ADC_CTL1 = \
 { \
  .tBit.adc_clk_prd = PARAMSET_ROIC_ADC_CTL1_adc_clk_prd, \
  .tBit.adc_clk_opt = PARAMSET_ROIC_ADC_CTL1_adc_clk_opt, \
  .tBit.adc_clk_pol = PARAMSET_ROIC_ADC_CTL1_adc_clk_pol, \
  .tBit.adc_clk_spt  = PARAMSET_ROIC_ADC_CTL1_adc_clk_spt , \
  .tBit.adc_in_pos = PARAMSET_ROIC_ADC_CTL1_adc_in_pos, \
  .tBit.adc_st_num = PARAMSET_ROIC_ADC_CTL1_adc_st_num, \
  .tBit.adc_clk_num = PARAMSET_ROIC_ADC_CTL1_adc_clk_num, \
  .tBit.adc_clk_st_num = PARAMSET_ROIC_ADC_CTL1_adc_clk_st_num, \
  .tBit.adc_clk_ctl_opt = PARAMSET_ROIC_ADC_CTL1_adc_clk_ctl_opt, \
 } ,\
 .ADC_CTL2 = \
 { \
  .tBit.adc_skip_num = PARAMSET_ROIC_ADC_CTL2_adc_skip_num, \
  .tBit.adc_sgap_num = PARAMSET_ROIC_ADC_CTL2_adc_sgap_num, \
  .tBit.adc_act_num = PARAMSET_ROIC_ADC_CTL2_adc_act_num, \
  .tBit.adc_sm_prd = PARAMSET_ROIC_ADC_CTL2_adc_sm_prd, \
  .tBit.adc_margin = PARAMSET_ROIC_ADC_CTL2_adc_margin, \
 } ,\
 .ADC_CTL3 = \
 { \
  .tBit.cmfb_init_en = PARAMSET_ROIC_ADC_CTL3_cmfb_init_en, \
  .tBit.cmfb_init_fall_num = PARAMSET_ROIC_ADC_CTL3_cmfb_init_fall_num, \
  .tBit.adc_rstb_rise_num = PARAMSET_ROIC_ADC_CTL3_adc_rstb_rise_num, \
  .tBit.pht2_rise_num = PARAMSET_ROIC_ADC_CTL3_pht2_rise_num, \
  .tBit.pht2_fall_num = PARAMSET_ROIC_ADC_CTL3_pht2_fall_num, \
  .tBit.adc_eoc_ctl_en = PARAMSET_ROIC_ADC_CTL3_adc_eoc_ctl_en, \
  .tBit.adc_sm_eoc_prd = PARAMSET_ROIC_ADC_CTL3_adc_sm_eoc_prd, \
 } ,\
 .TEST_MUX_CTL = \
 { \
  .tBit.mon_adcdo_en = 0, \
  .tBit.qcnt_vcom_th_en = PARAMSET_ROIC_TEST_MUX_CTL_qcnt_vcom_th_en, \
 } ,\
 .SYS_DUMMY0 = \
 { \
  .tBit.sys_dummy0 = 0x000000FF, \
 } ,\
 .R0_AFE_CFG = \
 { \
  .tBit.r0_buf_cfclk_on = PARAMSET_ROIC_R0_AFE_CFG_r0_buf_cfclk_on, \
  .tBit.r0_buf_clk_on = PARAMSET_ROIC_R0_AFE_CFG_r0_buf_clk_on, \
  .tBit.r0_cfclk_on = PARAMSET_ROIC_R0_AFE_CFG_r0_cfclk_on, \
 } ,\
 .R0_CH_EN = \
 { \
  .tBit.r0_ch_dum_drv_en = PARAMSET_ROIC_R0_CH_EN_r0_ch_dum_drv_en, \
  .tBit.r0_ch_en_int = PARAMSET_ROIC_R0_CH_EN_r0_ch_en_int, \
  .tBit.r0_ch_en_hvc = PARAMSET_ROIC_R0_CH_EN_r0_ch_en_hvc, \
 } ,\
 .R0_BUF_OPT = \
 { \
  .tBit.r0_double_buf_en = PARAMSET_ROIC_R0_BUF_OPT_r0_double_buf_en, \
  .tBit.r0_buf_test_mode = PARAMSET_ROIC_R0_BUF_OPT_r0_buf_test_mode, \
  .tBit.r0_buf_cnt_ctl_en = PARAMSET_ROIC_R0_BUF_OPT_r0_buf_cnt_ctl_en, \
  .tBit.r0_buf_cnt_skip_sel = PARAMSET_ROIC_R0_BUF_OPT_r0_buf_cnt_skip_sel, \
  .tBit.r0_buf_cnt_num = PARAMSET_ROIC_R0_BUF_OPT_r0_buf_cnt_num, \
  .tBit.r0_buf_auto_clr = PARAMSET_ROIC_R0_BUF_OPT_r0_buf_auto_clr, \
 } ,\
 .R0_VCOMR_OPT = \
 { \
  .tBit.r0_display_vcomr = PARAMSET_ROIC_R0_VCOMR_OPT_r0_display_vcomr, \
  .tBit.r0_touch_f_vcomr = PARAMSET_ROIC_R0_VCOMR_OPT_r0_touch_f_vcomr, \
  .tBit.r0_stuck_vcomr = PARAMSET_ROIC_R0_VCOMR_OPT_r0_stuck_vcomr, \
  .tBit.r0_stuck_vcomr_level = PARAMSET_ROIC_R0_VCOMR_OPT_r0_stuck_vcomr_level, \
  .tBit.r0_tsync_opt = PARAMSET_ROIC_R0_VCOMR_OPT_r0_tsync_opt, \
 } ,\
 .R0_MUX_CTL1 = \
 { \
  .tBit.r0_mux_s_stuck_en = PARAMSET_ROIC_R0_MUX_CTL1_r0_mux_s_stuck_en, \
  .tBit.r0_mux_int_stuck_val = PARAMSET_ROIC_R0_MUX_CTL1_r0_mux_int_stuck_val, \
  .tBit.r0_mux_s_stuck_val = PARAMSET_ROIC_R0_MUX_CTL1_r0_mux_s_stuck_val, \
  .tBit.r0_mux_f_ctl_en = PARAMSET_ROIC_R0_MUX_CTL1_r0_mux_f_ctl_en, \
  .tBit.r0_muxf_inv = PARAMSET_ROIC_R0_MUX_CTL1_r0_muxf_inv, \
  .tBit.r0_mux_f_stuck_en = PARAMSET_ROIC_R0_MUX_CTL1_r0_mux_f_stuck_en, \
  .tBit.r0_mux_nd_bit_en = PARAMSET_ROIC_R0_MUX_CTL1_r0_mux_nd_bit_en, \
 } ,\
 .R0_CR_RG_MUX1 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX1_r0_cr_mux1_r1g1, \
   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX1_r0_cr_mux1_r1g2, \
   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX1_r0_cr_mux1_r1g3, \
   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX1_r0_cr_mux1_r2g1, \
   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX1_r0_cr_mux1_r2g2, \
   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX1_r0_cr_mux1_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX1_r0_cr_mux1_r1g1, \
   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX1_r0_cr_mux1_r1g2, \
   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX1_r0_cr_mux1_r1g3, \
   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX1_r0_cr_mux1_r2g1, \
   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX1_r0_cr_mux1_r2g2, \
   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX1_r0_cr_mux1_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX1_r0_cr_mux1_r1g1, \
   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX1_r0_cr_mux1_r1g2, \
   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX1_r0_cr_mux1_r1g3, \
   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX1_r0_cr_mux1_r2g1, \
   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX1_r0_cr_mux1_r2g2, \
   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX1_r0_cr_mux1_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX1_r0_cr_mux1_r1g1, \
   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX1_r0_cr_mux1_r1g2, \
   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX1_r0_cr_mux1_r1g3, \
   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX1_r0_cr_mux1_r2g1, \
   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX1_r0_cr_mux1_r2g2, \
   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX1_r0_cr_mux1_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX1_r0_cr_mux1_r1g1, \
   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX1_r0_cr_mux1_r1g2, \
   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX1_r0_cr_mux1_r1g3, \
   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX1_r0_cr_mux1_r2g1, \
   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX1_r0_cr_mux1_r2g2, \
   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX1_r0_cr_mux1_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX1_r0_cr_mux1_r1g1, \
   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX1_r0_cr_mux1_r1g2, \
   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX1_r0_cr_mux1_r1g3, \
   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX1_r0_cr_mux1_r2g1, \
   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX1_r0_cr_mux1_r2g2, \
   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX1_r0_cr_mux1_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX1_r0_cr_mux1_r1g1, \
   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX1_r0_cr_mux1_r1g2, \
   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX1_r0_cr_mux1_r1g3, \
   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX1_r0_cr_mux1_r2g1, \
   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX1_r0_cr_mux1_r2g2, \
   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX1_r0_cr_mux1_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux1_r1g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX1_r0_cr_mux1_r1g1, \
   .tBit.r0_cr_mux1_r1g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX1_r0_cr_mux1_r1g2, \
   .tBit.r0_cr_mux1_r1g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX1_r0_cr_mux1_r1g3, \
   .tBit.r0_cr_mux1_r2g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX1_r0_cr_mux1_r2g1, \
   .tBit.r0_cr_mux1_r2g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX1_r0_cr_mux1_r2g2, \
   .tBit.r0_cr_mux1_r2g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX1_r0_cr_mux1_r2g3, \
  } ,\
 } ,\
 .R0_CR_RG_MUX2 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX2_r0_cr_mux2_r1g1, \
   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX2_r0_cr_mux2_r1g2, \
   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX2_r0_cr_mux2_r1g3, \
   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX2_r0_cr_mux2_r2g1, \
   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX2_r0_cr_mux2_r2g2, \
   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX2_r0_cr_mux2_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX2_r0_cr_mux2_r1g1, \
   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX2_r0_cr_mux2_r1g2, \
   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX2_r0_cr_mux2_r1g3, \
   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX2_r0_cr_mux2_r2g1, \
   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX2_r0_cr_mux2_r2g2, \
   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX2_r0_cr_mux2_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX2_r0_cr_mux2_r1g1, \
   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX2_r0_cr_mux2_r1g2, \
   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX2_r0_cr_mux2_r1g3, \
   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX2_r0_cr_mux2_r2g1, \
   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX2_r0_cr_mux2_r2g2, \
   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX2_r0_cr_mux2_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX2_r0_cr_mux2_r1g1, \
   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX2_r0_cr_mux2_r1g2, \
   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX2_r0_cr_mux2_r1g3, \
   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX2_r0_cr_mux2_r2g1, \
   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX2_r0_cr_mux2_r2g2, \
   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX2_r0_cr_mux2_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX2_r0_cr_mux2_r1g1, \
   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX2_r0_cr_mux2_r1g2, \
   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX2_r0_cr_mux2_r1g3, \
   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX2_r0_cr_mux2_r2g1, \
   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX2_r0_cr_mux2_r2g2, \
   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX2_r0_cr_mux2_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX2_r0_cr_mux2_r1g1, \
   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX2_r0_cr_mux2_r1g2, \
   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX2_r0_cr_mux2_r1g3, \
   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX2_r0_cr_mux2_r2g1, \
   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX2_r0_cr_mux2_r2g2, \
   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX2_r0_cr_mux2_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX2_r0_cr_mux2_r1g1, \
   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX2_r0_cr_mux2_r1g2, \
   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX2_r0_cr_mux2_r1g3, \
   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX2_r0_cr_mux2_r2g1, \
   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX2_r0_cr_mux2_r2g2, \
   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX2_r0_cr_mux2_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux2_r1g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX2_r0_cr_mux2_r1g1, \
   .tBit.r0_cr_mux2_r1g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX2_r0_cr_mux2_r1g2, \
   .tBit.r0_cr_mux2_r1g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX2_r0_cr_mux2_r1g3, \
   .tBit.r0_cr_mux2_r2g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX2_r0_cr_mux2_r2g1, \
   .tBit.r0_cr_mux2_r2g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX2_r0_cr_mux2_r2g2, \
   .tBit.r0_cr_mux2_r2g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX2_r0_cr_mux2_r2g3, \
  } ,\
 } ,\
 .R0_CR_RG_MUX3 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX3_r0_cr_mux3_r1g1, \
   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX3_r0_cr_mux3_r1g2, \
   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX3_r0_cr_mux3_r1g3, \
   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX3_r0_cr_mux3_r2g1, \
   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX3_r0_cr_mux3_r2g2, \
   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX3_r0_cr_mux3_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX3_r0_cr_mux3_r1g1, \
   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX3_r0_cr_mux3_r1g2, \
   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX3_r0_cr_mux3_r1g3, \
   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX3_r0_cr_mux3_r2g1, \
   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX3_r0_cr_mux3_r2g2, \
   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX3_r0_cr_mux3_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX3_r0_cr_mux3_r1g1, \
   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX3_r0_cr_mux3_r1g2, \
   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX3_r0_cr_mux3_r1g3, \
   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX3_r0_cr_mux3_r2g1, \
   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX3_r0_cr_mux3_r2g2, \
   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX3_r0_cr_mux3_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX3_r0_cr_mux3_r1g1, \
   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX3_r0_cr_mux3_r1g2, \
   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX3_r0_cr_mux3_r1g3, \
   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX3_r0_cr_mux3_r2g1, \
   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX3_r0_cr_mux3_r2g2, \
   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX3_r0_cr_mux3_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX3_r0_cr_mux3_r1g1, \
   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX3_r0_cr_mux3_r1g2, \
   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX3_r0_cr_mux3_r1g3, \
   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX3_r0_cr_mux3_r2g1, \
   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX3_r0_cr_mux3_r2g2, \
   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX3_r0_cr_mux3_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX3_r0_cr_mux3_r1g1, \
   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX3_r0_cr_mux3_r1g2, \
   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX3_r0_cr_mux3_r1g3, \
   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX3_r0_cr_mux3_r2g1, \
   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX3_r0_cr_mux3_r2g2, \
   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX3_r0_cr_mux3_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX3_r0_cr_mux3_r1g1, \
   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX3_r0_cr_mux3_r1g2, \
   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX3_r0_cr_mux3_r1g3, \
   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX3_r0_cr_mux3_r2g1, \
   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX3_r0_cr_mux3_r2g2, \
   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX3_r0_cr_mux3_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux3_r1g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX3_r0_cr_mux3_r1g1, \
   .tBit.r0_cr_mux3_r1g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX3_r0_cr_mux3_r1g2, \
   .tBit.r0_cr_mux3_r1g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX3_r0_cr_mux3_r1g3, \
   .tBit.r0_cr_mux3_r2g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX3_r0_cr_mux3_r2g1, \
   .tBit.r0_cr_mux3_r2g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX3_r0_cr_mux3_r2g2, \
   .tBit.r0_cr_mux3_r2g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX3_r0_cr_mux3_r2g3, \
  } ,\
 } ,\
 .R0_CR_RG_MUX4 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX4_r0_cr_mux4_r1g1, \
   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX4_r0_cr_mux4_r1g2, \
   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX4_r0_cr_mux4_r1g3, \
   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX4_r0_cr_mux4_r2g1, \
   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX4_r0_cr_mux4_r2g2, \
   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX4_r0_cr_mux4_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX4_r0_cr_mux4_r1g1, \
   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX4_r0_cr_mux4_r1g2, \
   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX4_r0_cr_mux4_r1g3, \
   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX4_r0_cr_mux4_r2g1, \
   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX4_r0_cr_mux4_r2g2, \
   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX4_r0_cr_mux4_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX4_r0_cr_mux4_r1g1, \
   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX4_r0_cr_mux4_r1g2, \
   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX4_r0_cr_mux4_r1g3, \
   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX4_r0_cr_mux4_r2g1, \
   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX4_r0_cr_mux4_r2g2, \
   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX4_r0_cr_mux4_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX4_r0_cr_mux4_r1g1, \
   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX4_r0_cr_mux4_r1g2, \
   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX4_r0_cr_mux4_r1g3, \
   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX4_r0_cr_mux4_r2g1, \
   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX4_r0_cr_mux4_r2g2, \
   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX4_r0_cr_mux4_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX4_r0_cr_mux4_r1g1, \
   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX4_r0_cr_mux4_r1g2, \
   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX4_r0_cr_mux4_r1g3, \
   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX4_r0_cr_mux4_r2g1, \
   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX4_r0_cr_mux4_r2g2, \
   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX4_r0_cr_mux4_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX4_r0_cr_mux4_r1g1, \
   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX4_r0_cr_mux4_r1g2, \
   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX4_r0_cr_mux4_r1g3, \
   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX4_r0_cr_mux4_r2g1, \
   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX4_r0_cr_mux4_r2g2, \
   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX4_r0_cr_mux4_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX4_r0_cr_mux4_r1g1, \
   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX4_r0_cr_mux4_r1g2, \
   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX4_r0_cr_mux4_r1g3, \
   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX4_r0_cr_mux4_r2g1, \
   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX4_r0_cr_mux4_r2g2, \
   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX4_r0_cr_mux4_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux4_r1g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX4_r0_cr_mux4_r1g1, \
   .tBit.r0_cr_mux4_r1g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX4_r0_cr_mux4_r1g2, \
   .tBit.r0_cr_mux4_r1g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX4_r0_cr_mux4_r1g3, \
   .tBit.r0_cr_mux4_r2g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX4_r0_cr_mux4_r2g1, \
   .tBit.r0_cr_mux4_r2g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX4_r0_cr_mux4_r2g2, \
   .tBit.r0_cr_mux4_r2g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX4_r0_cr_mux4_r2g3, \
  } ,\
 } ,\
 .R0_CR_RG_MUX5 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX5_r0_cr_mux5_r1g1, \
   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX5_r0_cr_mux5_r1g2, \
   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX5_r0_cr_mux5_r1g3, \
   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX5_r0_cr_mux5_r2g1, \
   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX5_r0_cr_mux5_r2g2, \
   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX5_r0_cr_mux5_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX5_r0_cr_mux5_r1g1, \
   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX5_r0_cr_mux5_r1g2, \
   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX5_r0_cr_mux5_r1g3, \
   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX5_r0_cr_mux5_r2g1, \
   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX5_r0_cr_mux5_r2g2, \
   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX5_r0_cr_mux5_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX5_r0_cr_mux5_r1g1, \
   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX5_r0_cr_mux5_r1g2, \
   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX5_r0_cr_mux5_r1g3, \
   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX5_r0_cr_mux5_r2g1, \
   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX5_r0_cr_mux5_r2g2, \
   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX5_r0_cr_mux5_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX5_r0_cr_mux5_r1g1, \
   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX5_r0_cr_mux5_r1g2, \
   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX5_r0_cr_mux5_r1g3, \
   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX5_r0_cr_mux5_r2g1, \
   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX5_r0_cr_mux5_r2g2, \
   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX5_r0_cr_mux5_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX5_r0_cr_mux5_r1g1, \
   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX5_r0_cr_mux5_r1g2, \
   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX5_r0_cr_mux5_r1g3, \
   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX5_r0_cr_mux5_r2g1, \
   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX5_r0_cr_mux5_r2g2, \
   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX5_r0_cr_mux5_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX5_r0_cr_mux5_r1g1, \
   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX5_r0_cr_mux5_r1g2, \
   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX5_r0_cr_mux5_r1g3, \
   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX5_r0_cr_mux5_r2g1, \
   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX5_r0_cr_mux5_r2g2, \
   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX5_r0_cr_mux5_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX5_r0_cr_mux5_r1g1, \
   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX5_r0_cr_mux5_r1g2, \
   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX5_r0_cr_mux5_r1g3, \
   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX5_r0_cr_mux5_r2g1, \
   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX5_r0_cr_mux5_r2g2, \
   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX5_r0_cr_mux5_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux5_r1g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX5_r0_cr_mux5_r1g1, \
   .tBit.r0_cr_mux5_r1g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX5_r0_cr_mux5_r1g2, \
   .tBit.r0_cr_mux5_r1g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX5_r0_cr_mux5_r1g3, \
   .tBit.r0_cr_mux5_r2g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX5_r0_cr_mux5_r2g1, \
   .tBit.r0_cr_mux5_r2g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX5_r0_cr_mux5_r2g2, \
   .tBit.r0_cr_mux5_r2g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX5_r0_cr_mux5_r2g3, \
  } ,\
 } ,\
 .R0_CR_RG_MUX6 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX6_r0_cr_mux6_r1g1, \
   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX6_r0_cr_mux6_r1g2, \
   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX6_r0_cr_mux6_r1g3, \
   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX6_r0_cr_mux6_r2g1, \
   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX6_r0_cr_mux6_r2g2, \
   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX6_r0_cr_mux6_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX6_r0_cr_mux6_r1g1, \
   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX6_r0_cr_mux6_r1g2, \
   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX6_r0_cr_mux6_r1g3, \
   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX6_r0_cr_mux6_r2g1, \
   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX6_r0_cr_mux6_r2g2, \
   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX6_r0_cr_mux6_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX6_r0_cr_mux6_r1g1, \
   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX6_r0_cr_mux6_r1g2, \
   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX6_r0_cr_mux6_r1g3, \
   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX6_r0_cr_mux6_r2g1, \
   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX6_r0_cr_mux6_r2g2, \
   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX6_r0_cr_mux6_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX6_r0_cr_mux6_r1g1, \
   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX6_r0_cr_mux6_r1g2, \
   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX6_r0_cr_mux6_r1g3, \
   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX6_r0_cr_mux6_r2g1, \
   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX6_r0_cr_mux6_r2g2, \
   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX6_r0_cr_mux6_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX6_r0_cr_mux6_r1g1, \
   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX6_r0_cr_mux6_r1g2, \
   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX6_r0_cr_mux6_r1g3, \
   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX6_r0_cr_mux6_r2g1, \
   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX6_r0_cr_mux6_r2g2, \
   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX6_r0_cr_mux6_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX6_r0_cr_mux6_r1g1, \
   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX6_r0_cr_mux6_r1g2, \
   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX6_r0_cr_mux6_r1g3, \
   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX6_r0_cr_mux6_r2g1, \
   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX6_r0_cr_mux6_r2g2, \
   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX6_r0_cr_mux6_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX6_r0_cr_mux6_r1g1, \
   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX6_r0_cr_mux6_r1g2, \
   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX6_r0_cr_mux6_r1g3, \
   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX6_r0_cr_mux6_r2g1, \
   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX6_r0_cr_mux6_r2g2, \
   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX6_r0_cr_mux6_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux6_r1g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX6_r0_cr_mux6_r1g1, \
   .tBit.r0_cr_mux6_r1g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX6_r0_cr_mux6_r1g2, \
   .tBit.r0_cr_mux6_r1g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX6_r0_cr_mux6_r1g3, \
   .tBit.r0_cr_mux6_r2g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX6_r0_cr_mux6_r2g1, \
   .tBit.r0_cr_mux6_r2g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX6_r0_cr_mux6_r2g2, \
   .tBit.r0_cr_mux6_r2g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX6_r0_cr_mux6_r2g3, \
  } ,\
 } ,\
 .R0_CR_RG_MUX7 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX7_r0_cr_mux7_r1g1, \
   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX7_r0_cr_mux7_r1g2, \
   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX7_r0_cr_mux7_r1g3, \
   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX7_r0_cr_mux7_r2g1, \
   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX7_r0_cr_mux7_r2g2, \
   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX7_r0_cr_mux7_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX7_r0_cr_mux7_r1g1, \
   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX7_r0_cr_mux7_r1g2, \
   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX7_r0_cr_mux7_r1g3, \
   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX7_r0_cr_mux7_r2g1, \
   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX7_r0_cr_mux7_r2g2, \
   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX7_r0_cr_mux7_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX7_r0_cr_mux7_r1g1, \
   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX7_r0_cr_mux7_r1g2, \
   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX7_r0_cr_mux7_r1g3, \
   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX7_r0_cr_mux7_r2g1, \
   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX7_r0_cr_mux7_r2g2, \
   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX7_r0_cr_mux7_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX7_r0_cr_mux7_r1g1, \
   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX7_r0_cr_mux7_r1g2, \
   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX7_r0_cr_mux7_r1g3, \
   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX7_r0_cr_mux7_r2g1, \
   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX7_r0_cr_mux7_r2g2, \
   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX7_r0_cr_mux7_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX7_r0_cr_mux7_r1g1, \
   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX7_r0_cr_mux7_r1g2, \
   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX7_r0_cr_mux7_r1g3, \
   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX7_r0_cr_mux7_r2g1, \
   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX7_r0_cr_mux7_r2g2, \
   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX7_r0_cr_mux7_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX7_r0_cr_mux7_r1g1, \
   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX7_r0_cr_mux7_r1g2, \
   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX7_r0_cr_mux7_r1g3, \
   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX7_r0_cr_mux7_r2g1, \
   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX7_r0_cr_mux7_r2g2, \
   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX7_r0_cr_mux7_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX7_r0_cr_mux7_r1g1, \
   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX7_r0_cr_mux7_r1g2, \
   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX7_r0_cr_mux7_r1g3, \
   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX7_r0_cr_mux7_r2g1, \
   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX7_r0_cr_mux7_r2g2, \
   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX7_r0_cr_mux7_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux7_r1g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX7_r0_cr_mux7_r1g1, \
   .tBit.r0_cr_mux7_r1g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX7_r0_cr_mux7_r1g2, \
   .tBit.r0_cr_mux7_r1g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX7_r0_cr_mux7_r1g3, \
   .tBit.r0_cr_mux7_r2g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX7_r0_cr_mux7_r2g1, \
   .tBit.r0_cr_mux7_r2g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX7_r0_cr_mux7_r2g2, \
   .tBit.r0_cr_mux7_r2g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX7_r0_cr_mux7_r2g3, \
  } ,\
 } ,\
 .R0_CR_RG_MUX8 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX8_r0_cr_mux8_r1g1, \
   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX8_r0_cr_mux8_r1g2, \
   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX8_r0_cr_mux8_r1g3, \
   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX8_r0_cr_mux8_r2g1, \
   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX8_r0_cr_mux8_r2g2, \
   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX8_r0_cr_mux8_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX8_r0_cr_mux8_r1g1, \
   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX8_r0_cr_mux8_r1g2, \
   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX8_r0_cr_mux8_r1g3, \
   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX8_r0_cr_mux8_r2g1, \
   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX8_r0_cr_mux8_r2g2, \
   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX8_r0_cr_mux8_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX8_r0_cr_mux8_r1g1, \
   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX8_r0_cr_mux8_r1g2, \
   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX8_r0_cr_mux8_r1g3, \
   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX8_r0_cr_mux8_r2g1, \
   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX8_r0_cr_mux8_r2g2, \
   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX8_r0_cr_mux8_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX8_r0_cr_mux8_r1g1, \
   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX8_r0_cr_mux8_r1g2, \
   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX8_r0_cr_mux8_r1g3, \
   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX8_r0_cr_mux8_r2g1, \
   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX8_r0_cr_mux8_r2g2, \
   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX8_r0_cr_mux8_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX8_r0_cr_mux8_r1g1, \
   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX8_r0_cr_mux8_r1g2, \
   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX8_r0_cr_mux8_r1g3, \
   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX8_r0_cr_mux8_r2g1, \
   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX8_r0_cr_mux8_r2g2, \
   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX8_r0_cr_mux8_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX8_r0_cr_mux8_r1g1, \
   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX8_r0_cr_mux8_r1g2, \
   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX8_r0_cr_mux8_r1g3, \
   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX8_r0_cr_mux8_r2g1, \
   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX8_r0_cr_mux8_r2g2, \
   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX8_r0_cr_mux8_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX8_r0_cr_mux8_r1g1, \
   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX8_r0_cr_mux8_r1g2, \
   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX8_r0_cr_mux8_r1g3, \
   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX8_r0_cr_mux8_r2g1, \
   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX8_r0_cr_mux8_r2g2, \
   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX8_r0_cr_mux8_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux8_r1g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX8_r0_cr_mux8_r1g1, \
   .tBit.r0_cr_mux8_r1g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX8_r0_cr_mux8_r1g2, \
   .tBit.r0_cr_mux8_r1g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX8_r0_cr_mux8_r1g3, \
   .tBit.r0_cr_mux8_r2g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX8_r0_cr_mux8_r2g1, \
   .tBit.r0_cr_mux8_r2g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX8_r0_cr_mux8_r2g2, \
   .tBit.r0_cr_mux8_r2g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX8_r0_cr_mux8_r2g3, \
  } ,\
 } ,\
 .R0_CR_RG_MUX9 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX9_r0_cr_mux9_r1g1, \
   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX9_r0_cr_mux9_r1g2, \
   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX9_r0_cr_mux9_r1g3, \
   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX9_r0_cr_mux9_r2g1, \
   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX9_r0_cr_mux9_r2g2, \
   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX9_r0_cr_mux9_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX9_r0_cr_mux9_r1g1, \
   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX9_r0_cr_mux9_r1g2, \
   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX9_r0_cr_mux9_r1g3, \
   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX9_r0_cr_mux9_r2g1, \
   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX9_r0_cr_mux9_r2g2, \
   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX9_r0_cr_mux9_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX9_r0_cr_mux9_r1g1, \
   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX9_r0_cr_mux9_r1g2, \
   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX9_r0_cr_mux9_r1g3, \
   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX9_r0_cr_mux9_r2g1, \
   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX9_r0_cr_mux9_r2g2, \
   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX9_r0_cr_mux9_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX9_r0_cr_mux9_r1g1, \
   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX9_r0_cr_mux9_r1g2, \
   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX9_r0_cr_mux9_r1g3, \
   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX9_r0_cr_mux9_r2g1, \
   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX9_r0_cr_mux9_r2g2, \
   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX9_r0_cr_mux9_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX9_r0_cr_mux9_r1g1, \
   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX9_r0_cr_mux9_r1g2, \
   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX9_r0_cr_mux9_r1g3, \
   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX9_r0_cr_mux9_r2g1, \
   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX9_r0_cr_mux9_r2g2, \
   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX9_r0_cr_mux9_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX9_r0_cr_mux9_r1g1, \
   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX9_r0_cr_mux9_r1g2, \
   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX9_r0_cr_mux9_r1g3, \
   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX9_r0_cr_mux9_r2g1, \
   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX9_r0_cr_mux9_r2g2, \
   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX9_r0_cr_mux9_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX9_r0_cr_mux9_r1g1, \
   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX9_r0_cr_mux9_r1g2, \
   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX9_r0_cr_mux9_r1g3, \
   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX9_r0_cr_mux9_r2g1, \
   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX9_r0_cr_mux9_r2g2, \
   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX9_r0_cr_mux9_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux9_r1g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX9_r0_cr_mux9_r1g1, \
   .tBit.r0_cr_mux9_r1g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX9_r0_cr_mux9_r1g2, \
   .tBit.r0_cr_mux9_r1g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX9_r0_cr_mux9_r1g3, \
   .tBit.r0_cr_mux9_r2g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX9_r0_cr_mux9_r2g1, \
   .tBit.r0_cr_mux9_r2g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX9_r0_cr_mux9_r2g2, \
   .tBit.r0_cr_mux9_r2g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX9_r0_cr_mux9_r2g3, \
  } ,\
 } ,\
 .R0_CR_RG_MUX10 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX10_r0_cr_mux10_r1g1, \
   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX10_r0_cr_mux10_r1g2, \
   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX10_r0_cr_mux10_r1g3, \
   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX10_r0_cr_mux10_r2g1, \
   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX10_r0_cr_mux10_r2g2, \
   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX10_r0_cr_mux10_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX10_r0_cr_mux10_r1g1, \
   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX10_r0_cr_mux10_r1g2, \
   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX10_r0_cr_mux10_r1g3, \
   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX10_r0_cr_mux10_r2g1, \
   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX10_r0_cr_mux10_r2g2, \
   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX10_r0_cr_mux10_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX10_r0_cr_mux10_r1g1, \
   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX10_r0_cr_mux10_r1g2, \
   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX10_r0_cr_mux10_r1g3, \
   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX10_r0_cr_mux10_r2g1, \
   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX10_r0_cr_mux10_r2g2, \
   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX10_r0_cr_mux10_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX10_r0_cr_mux10_r1g1, \
   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX10_r0_cr_mux10_r1g2, \
   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX10_r0_cr_mux10_r1g3, \
   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX10_r0_cr_mux10_r2g1, \
   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX10_r0_cr_mux10_r2g2, \
   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX10_r0_cr_mux10_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX10_r0_cr_mux10_r1g1, \
   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX10_r0_cr_mux10_r1g2, \
   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX10_r0_cr_mux10_r1g3, \
   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX10_r0_cr_mux10_r2g1, \
   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX10_r0_cr_mux10_r2g2, \
   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX10_r0_cr_mux10_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX10_r0_cr_mux10_r1g1, \
   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX10_r0_cr_mux10_r1g2, \
   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX10_r0_cr_mux10_r1g3, \
   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX10_r0_cr_mux10_r2g1, \
   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX10_r0_cr_mux10_r2g2, \
   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX10_r0_cr_mux10_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX10_r0_cr_mux10_r1g1, \
   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX10_r0_cr_mux10_r1g2, \
   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX10_r0_cr_mux10_r1g3, \
   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX10_r0_cr_mux10_r2g1, \
   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX10_r0_cr_mux10_r2g2, \
   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX10_r0_cr_mux10_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux10_r1g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX10_r0_cr_mux10_r1g1, \
   .tBit.r0_cr_mux10_r1g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX10_r0_cr_mux10_r1g2, \
   .tBit.r0_cr_mux10_r1g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX10_r0_cr_mux10_r1g3, \
   .tBit.r0_cr_mux10_r2g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX10_r0_cr_mux10_r2g1, \
   .tBit.r0_cr_mux10_r2g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX10_r0_cr_mux10_r2g2, \
   .tBit.r0_cr_mux10_r2g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX10_r0_cr_mux10_r2g3, \
  } ,\
 } ,\
 .R0_CR_RG_MUX11 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux11_r1g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX11_r0_cr_mux11_r1g1, \
   .tBit.r0_cr_mux11_r1g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX11_r0_cr_mux11_r1g2, \
   .tBit.r0_cr_mux11_r1g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX11_r0_cr_mux11_r1g3, \
   .tBit.r0_cr_mux11_r2g1 = PARAMSET_ROIC_0_R0_CR_RG_MUX11_r0_cr_mux11_r2g1, \
   .tBit.r0_cr_mux11_r2g2 = PARAMSET_ROIC_0_R0_CR_RG_MUX11_r0_cr_mux11_r2g2, \
   .tBit.r0_cr_mux11_r2g3 = PARAMSET_ROIC_0_R0_CR_RG_MUX11_r0_cr_mux11_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux11_r1g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX11_r0_cr_mux11_r1g1, \
   .tBit.r0_cr_mux11_r1g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX11_r0_cr_mux11_r1g2, \
   .tBit.r0_cr_mux11_r1g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX11_r0_cr_mux11_r1g3, \
   .tBit.r0_cr_mux11_r2g1 = PARAMSET_ROIC_1_R0_CR_RG_MUX11_r0_cr_mux11_r2g1, \
   .tBit.r0_cr_mux11_r2g2 = PARAMSET_ROIC_1_R0_CR_RG_MUX11_r0_cr_mux11_r2g2, \
   .tBit.r0_cr_mux11_r2g3 = PARAMSET_ROIC_1_R0_CR_RG_MUX11_r0_cr_mux11_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux11_r1g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX11_r0_cr_mux11_r1g1, \
   .tBit.r0_cr_mux11_r1g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX11_r0_cr_mux11_r1g2, \
   .tBit.r0_cr_mux11_r1g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX11_r0_cr_mux11_r1g3, \
   .tBit.r0_cr_mux11_r2g1 = PARAMSET_ROIC_2_R0_CR_RG_MUX11_r0_cr_mux11_r2g1, \
   .tBit.r0_cr_mux11_r2g2 = PARAMSET_ROIC_2_R0_CR_RG_MUX11_r0_cr_mux11_r2g2, \
   .tBit.r0_cr_mux11_r2g3 = PARAMSET_ROIC_2_R0_CR_RG_MUX11_r0_cr_mux11_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux11_r1g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX11_r0_cr_mux11_r1g1, \
   .tBit.r0_cr_mux11_r1g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX11_r0_cr_mux11_r1g2, \
   .tBit.r0_cr_mux11_r1g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX11_r0_cr_mux11_r1g3, \
   .tBit.r0_cr_mux11_r2g1 = PARAMSET_ROIC_3_R0_CR_RG_MUX11_r0_cr_mux11_r2g1, \
   .tBit.r0_cr_mux11_r2g2 = PARAMSET_ROIC_3_R0_CR_RG_MUX11_r0_cr_mux11_r2g2, \
   .tBit.r0_cr_mux11_r2g3 = PARAMSET_ROIC_3_R0_CR_RG_MUX11_r0_cr_mux11_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux11_r1g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX11_r0_cr_mux11_r1g1, \
   .tBit.r0_cr_mux11_r1g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX11_r0_cr_mux11_r1g2, \
   .tBit.r0_cr_mux11_r1g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX11_r0_cr_mux11_r1g3, \
   .tBit.r0_cr_mux11_r2g1 = PARAMSET_ROIC_4_R0_CR_RG_MUX11_r0_cr_mux11_r2g1, \
   .tBit.r0_cr_mux11_r2g2 = PARAMSET_ROIC_4_R0_CR_RG_MUX11_r0_cr_mux11_r2g2, \
   .tBit.r0_cr_mux11_r2g3 = PARAMSET_ROIC_4_R0_CR_RG_MUX11_r0_cr_mux11_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux11_r1g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX11_r0_cr_mux11_r1g1, \
   .tBit.r0_cr_mux11_r1g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX11_r0_cr_mux11_r1g2, \
   .tBit.r0_cr_mux11_r1g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX11_r0_cr_mux11_r1g3, \
   .tBit.r0_cr_mux11_r2g1 = PARAMSET_ROIC_5_R0_CR_RG_MUX11_r0_cr_mux11_r2g1, \
   .tBit.r0_cr_mux11_r2g2 = PARAMSET_ROIC_5_R0_CR_RG_MUX11_r0_cr_mux11_r2g2, \
   .tBit.r0_cr_mux11_r2g3 = PARAMSET_ROIC_5_R0_CR_RG_MUX11_r0_cr_mux11_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux11_r1g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX11_r0_cr_mux11_r1g1, \
   .tBit.r0_cr_mux11_r1g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX11_r0_cr_mux11_r1g2, \
   .tBit.r0_cr_mux11_r1g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX11_r0_cr_mux11_r1g3, \
   .tBit.r0_cr_mux11_r2g1 = PARAMSET_ROIC_6_R0_CR_RG_MUX11_r0_cr_mux11_r2g1, \
   .tBit.r0_cr_mux11_r2g2 = PARAMSET_ROIC_6_R0_CR_RG_MUX11_r0_cr_mux11_r2g2, \
   .tBit.r0_cr_mux11_r2g3 = PARAMSET_ROIC_6_R0_CR_RG_MUX11_r0_cr_mux11_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux11_r1g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX11_r0_cr_mux11_r1g1, \
   .tBit.r0_cr_mux11_r1g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX11_r0_cr_mux11_r1g2, \
   .tBit.r0_cr_mux11_r1g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX11_r0_cr_mux11_r1g3, \
   .tBit.r0_cr_mux11_r2g1 = PARAMSET_ROIC_7_R0_CR_RG_MUX11_r0_cr_mux11_r2g1, \
   .tBit.r0_cr_mux11_r2g2 = PARAMSET_ROIC_7_R0_CR_RG_MUX11_r0_cr_mux11_r2g2, \
   .tBit.r0_cr_mux11_r2g3 = PARAMSET_ROIC_7_R0_CR_RG_MUX11_r0_cr_mux11_r2g3, \
  } ,\
 } ,\
 .R0_CR_R1G_MUXE = \
 { \
  [0] = { \
   .tBit.r0_cr_muxe_r1g1 = PARAMSET_ROIC_0_R0_CR_R1G_MUXE_r0_cr_muxe_r1g1, \
   .tBit.r0_cr_muxe_r1g2 = PARAMSET_ROIC_0_R0_CR_R1G_MUXE_r0_cr_muxe_r1g2, \
   .tBit.r0_cr_muxe_r1g3 = PARAMSET_ROIC_0_R0_CR_R1G_MUXE_r0_cr_muxe_r1g3, \
   .tBit.r0_cr_muxe_r2g1 = PARAMSET_ROIC_0_R0_CR_R1G_MUXE_r0_cr_muxe_r2g1, \
   .tBit.r0_cr_muxe_r2g2 = PARAMSET_ROIC_0_R0_CR_R1G_MUXE_r0_cr_muxe_r2g2, \
   .tBit.r0_cr_muxe_r2g3 = PARAMSET_ROIC_0_R0_CR_R1G_MUXE_r0_cr_muxe_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_muxe_r1g1 = PARAMSET_ROIC_1_R0_CR_R1G_MUXE_r0_cr_muxe_r1g1, \
   .tBit.r0_cr_muxe_r1g2 = PARAMSET_ROIC_1_R0_CR_R1G_MUXE_r0_cr_muxe_r1g2, \
   .tBit.r0_cr_muxe_r1g3 = PARAMSET_ROIC_1_R0_CR_R1G_MUXE_r0_cr_muxe_r1g3, \
   .tBit.r0_cr_muxe_r2g1 = PARAMSET_ROIC_1_R0_CR_R1G_MUXE_r0_cr_muxe_r2g1, \
   .tBit.r0_cr_muxe_r2g2 = PARAMSET_ROIC_1_R0_CR_R1G_MUXE_r0_cr_muxe_r2g2, \
   .tBit.r0_cr_muxe_r2g3 = PARAMSET_ROIC_1_R0_CR_R1G_MUXE_r0_cr_muxe_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_muxe_r1g1 = PARAMSET_ROIC_2_R0_CR_R1G_MUXE_r0_cr_muxe_r1g1, \
   .tBit.r0_cr_muxe_r1g2 = PARAMSET_ROIC_2_R0_CR_R1G_MUXE_r0_cr_muxe_r1g2, \
   .tBit.r0_cr_muxe_r1g3 = PARAMSET_ROIC_2_R0_CR_R1G_MUXE_r0_cr_muxe_r1g3, \
   .tBit.r0_cr_muxe_r2g1 = PARAMSET_ROIC_2_R0_CR_R1G_MUXE_r0_cr_muxe_r2g1, \
   .tBit.r0_cr_muxe_r2g2 = PARAMSET_ROIC_2_R0_CR_R1G_MUXE_r0_cr_muxe_r2g2, \
   .tBit.r0_cr_muxe_r2g3 = PARAMSET_ROIC_2_R0_CR_R1G_MUXE_r0_cr_muxe_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_muxe_r1g1 = PARAMSET_ROIC_3_R0_CR_R1G_MUXE_r0_cr_muxe_r1g1, \
   .tBit.r0_cr_muxe_r1g2 = PARAMSET_ROIC_3_R0_CR_R1G_MUXE_r0_cr_muxe_r1g2, \
   .tBit.r0_cr_muxe_r1g3 = PARAMSET_ROIC_3_R0_CR_R1G_MUXE_r0_cr_muxe_r1g3, \
   .tBit.r0_cr_muxe_r2g1 = PARAMSET_ROIC_3_R0_CR_R1G_MUXE_r0_cr_muxe_r2g1, \
   .tBit.r0_cr_muxe_r2g2 = PARAMSET_ROIC_3_R0_CR_R1G_MUXE_r0_cr_muxe_r2g2, \
   .tBit.r0_cr_muxe_r2g3 = PARAMSET_ROIC_3_R0_CR_R1G_MUXE_r0_cr_muxe_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_muxe_r1g1 = PARAMSET_ROIC_4_R0_CR_R1G_MUXE_r0_cr_muxe_r1g1, \
   .tBit.r0_cr_muxe_r1g2 = PARAMSET_ROIC_4_R0_CR_R1G_MUXE_r0_cr_muxe_r1g2, \
   .tBit.r0_cr_muxe_r1g3 = PARAMSET_ROIC_4_R0_CR_R1G_MUXE_r0_cr_muxe_r1g3, \
   .tBit.r0_cr_muxe_r2g1 = PARAMSET_ROIC_4_R0_CR_R1G_MUXE_r0_cr_muxe_r2g1, \
   .tBit.r0_cr_muxe_r2g2 = PARAMSET_ROIC_4_R0_CR_R1G_MUXE_r0_cr_muxe_r2g2, \
   .tBit.r0_cr_muxe_r2g3 = PARAMSET_ROIC_4_R0_CR_R1G_MUXE_r0_cr_muxe_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_muxe_r1g1 = PARAMSET_ROIC_5_R0_CR_R1G_MUXE_r0_cr_muxe_r1g1, \
   .tBit.r0_cr_muxe_r1g2 = PARAMSET_ROIC_5_R0_CR_R1G_MUXE_r0_cr_muxe_r1g2, \
   .tBit.r0_cr_muxe_r1g3 = PARAMSET_ROIC_5_R0_CR_R1G_MUXE_r0_cr_muxe_r1g3, \
   .tBit.r0_cr_muxe_r2g1 = PARAMSET_ROIC_5_R0_CR_R1G_MUXE_r0_cr_muxe_r2g1, \
   .tBit.r0_cr_muxe_r2g2 = PARAMSET_ROIC_5_R0_CR_R1G_MUXE_r0_cr_muxe_r2g2, \
   .tBit.r0_cr_muxe_r2g3 = PARAMSET_ROIC_5_R0_CR_R1G_MUXE_r0_cr_muxe_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_muxe_r1g1 = PARAMSET_ROIC_6_R0_CR_R1G_MUXE_r0_cr_muxe_r1g1, \
   .tBit.r0_cr_muxe_r1g2 = PARAMSET_ROIC_6_R0_CR_R1G_MUXE_r0_cr_muxe_r1g2, \
   .tBit.r0_cr_muxe_r1g3 = PARAMSET_ROIC_6_R0_CR_R1G_MUXE_r0_cr_muxe_r1g3, \
   .tBit.r0_cr_muxe_r2g1 = PARAMSET_ROIC_6_R0_CR_R1G_MUXE_r0_cr_muxe_r2g1, \
   .tBit.r0_cr_muxe_r2g2 = PARAMSET_ROIC_6_R0_CR_R1G_MUXE_r0_cr_muxe_r2g2, \
   .tBit.r0_cr_muxe_r2g3 = PARAMSET_ROIC_6_R0_CR_R1G_MUXE_r0_cr_muxe_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_muxe_r1g1 = PARAMSET_ROIC_7_R0_CR_R1G_MUXE_r0_cr_muxe_r1g1, \
   .tBit.r0_cr_muxe_r1g2 = PARAMSET_ROIC_7_R0_CR_R1G_MUXE_r0_cr_muxe_r1g2, \
   .tBit.r0_cr_muxe_r1g3 = PARAMSET_ROIC_7_R0_CR_R1G_MUXE_r0_cr_muxe_r1g3, \
   .tBit.r0_cr_muxe_r2g1 = PARAMSET_ROIC_7_R0_CR_R1G_MUXE_r0_cr_muxe_r2g1, \
   .tBit.r0_cr_muxe_r2g2 = PARAMSET_ROIC_7_R0_CR_R1G_MUXE_r0_cr_muxe_r2g2, \
   .tBit.r0_cr_muxe_r2g3 = PARAMSET_ROIC_7_R0_CR_R1G_MUXE_r0_cr_muxe_r2g3, \
  } ,\
 } ,\
 .R0_CR_R1G_MUXO = \
 { \
  [0] = { \
   .tBit.r0_cr_muxo_r1g1 = PARAMSET_ROIC_0_R0_CR_R1G_MUXO_r0_cr_muxo_r1g1, \
   .tBit.r0_cr_muxo_r1g2 = PARAMSET_ROIC_0_R0_CR_R1G_MUXO_r0_cr_muxo_r1g2, \
   .tBit.r0_cr_muxo_r1g3 = PARAMSET_ROIC_0_R0_CR_R1G_MUXO_r0_cr_muxo_r1g3, \
   .tBit.r0_cr_muxo_r2g1 = PARAMSET_ROIC_0_R0_CR_R1G_MUXO_r0_cr_muxo_r2g1, \
   .tBit.r0_cr_muxo_r2g2 = PARAMSET_ROIC_0_R0_CR_R1G_MUXO_r0_cr_muxo_r2g2, \
   .tBit.r0_cr_muxo_r2g3 = PARAMSET_ROIC_0_R0_CR_R1G_MUXO_r0_cr_muxo_r2g3, \
  } ,\
  [1] = { \
   .tBit.r0_cr_muxo_r1g1 = PARAMSET_ROIC_1_R0_CR_R1G_MUXO_r0_cr_muxo_r1g1, \
   .tBit.r0_cr_muxo_r1g2 = PARAMSET_ROIC_1_R0_CR_R1G_MUXO_r0_cr_muxo_r1g2, \
   .tBit.r0_cr_muxo_r1g3 = PARAMSET_ROIC_1_R0_CR_R1G_MUXO_r0_cr_muxo_r1g3, \
   .tBit.r0_cr_muxo_r2g1 = PARAMSET_ROIC_1_R0_CR_R1G_MUXO_r0_cr_muxo_r2g1, \
   .tBit.r0_cr_muxo_r2g2 = PARAMSET_ROIC_1_R0_CR_R1G_MUXO_r0_cr_muxo_r2g2, \
   .tBit.r0_cr_muxo_r2g3 = PARAMSET_ROIC_1_R0_CR_R1G_MUXO_r0_cr_muxo_r2g3, \
  } ,\
  [2] = { \
   .tBit.r0_cr_muxo_r1g1 = PARAMSET_ROIC_2_R0_CR_R1G_MUXO_r0_cr_muxo_r1g1, \
   .tBit.r0_cr_muxo_r1g2 = PARAMSET_ROIC_2_R0_CR_R1G_MUXO_r0_cr_muxo_r1g2, \
   .tBit.r0_cr_muxo_r1g3 = PARAMSET_ROIC_2_R0_CR_R1G_MUXO_r0_cr_muxo_r1g3, \
   .tBit.r0_cr_muxo_r2g1 = PARAMSET_ROIC_2_R0_CR_R1G_MUXO_r0_cr_muxo_r2g1, \
   .tBit.r0_cr_muxo_r2g2 = PARAMSET_ROIC_2_R0_CR_R1G_MUXO_r0_cr_muxo_r2g2, \
   .tBit.r0_cr_muxo_r2g3 = PARAMSET_ROIC_2_R0_CR_R1G_MUXO_r0_cr_muxo_r2g3, \
  } ,\
  [3] = { \
   .tBit.r0_cr_muxo_r1g1 = PARAMSET_ROIC_3_R0_CR_R1G_MUXO_r0_cr_muxo_r1g1, \
   .tBit.r0_cr_muxo_r1g2 = PARAMSET_ROIC_3_R0_CR_R1G_MUXO_r0_cr_muxo_r1g2, \
   .tBit.r0_cr_muxo_r1g3 = PARAMSET_ROIC_3_R0_CR_R1G_MUXO_r0_cr_muxo_r1g3, \
   .tBit.r0_cr_muxo_r2g1 = PARAMSET_ROIC_3_R0_CR_R1G_MUXO_r0_cr_muxo_r2g1, \
   .tBit.r0_cr_muxo_r2g2 = PARAMSET_ROIC_3_R0_CR_R1G_MUXO_r0_cr_muxo_r2g2, \
   .tBit.r0_cr_muxo_r2g3 = PARAMSET_ROIC_3_R0_CR_R1G_MUXO_r0_cr_muxo_r2g3, \
  } ,\
  [4] = { \
   .tBit.r0_cr_muxo_r1g1 = PARAMSET_ROIC_4_R0_CR_R1G_MUXO_r0_cr_muxo_r1g1, \
   .tBit.r0_cr_muxo_r1g2 = PARAMSET_ROIC_4_R0_CR_R1G_MUXO_r0_cr_muxo_r1g2, \
   .tBit.r0_cr_muxo_r1g3 = PARAMSET_ROIC_4_R0_CR_R1G_MUXO_r0_cr_muxo_r1g3, \
   .tBit.r0_cr_muxo_r2g1 = PARAMSET_ROIC_4_R0_CR_R1G_MUXO_r0_cr_muxo_r2g1, \
   .tBit.r0_cr_muxo_r2g2 = PARAMSET_ROIC_4_R0_CR_R1G_MUXO_r0_cr_muxo_r2g2, \
   .tBit.r0_cr_muxo_r2g3 = PARAMSET_ROIC_4_R0_CR_R1G_MUXO_r0_cr_muxo_r2g3, \
  } ,\
  [5] = { \
   .tBit.r0_cr_muxo_r1g1 = PARAMSET_ROIC_5_R0_CR_R1G_MUXO_r0_cr_muxo_r1g1, \
   .tBit.r0_cr_muxo_r1g2 = PARAMSET_ROIC_5_R0_CR_R1G_MUXO_r0_cr_muxo_r1g2, \
   .tBit.r0_cr_muxo_r1g3 = PARAMSET_ROIC_5_R0_CR_R1G_MUXO_r0_cr_muxo_r1g3, \
   .tBit.r0_cr_muxo_r2g1 = PARAMSET_ROIC_5_R0_CR_R1G_MUXO_r0_cr_muxo_r2g1, \
   .tBit.r0_cr_muxo_r2g2 = PARAMSET_ROIC_5_R0_CR_R1G_MUXO_r0_cr_muxo_r2g2, \
   .tBit.r0_cr_muxo_r2g3 = PARAMSET_ROIC_5_R0_CR_R1G_MUXO_r0_cr_muxo_r2g3, \
  } ,\
  [6] = { \
   .tBit.r0_cr_muxo_r1g1 = PARAMSET_ROIC_6_R0_CR_R1G_MUXO_r0_cr_muxo_r1g1, \
   .tBit.r0_cr_muxo_r1g2 = PARAMSET_ROIC_6_R0_CR_R1G_MUXO_r0_cr_muxo_r1g2, \
   .tBit.r0_cr_muxo_r1g3 = PARAMSET_ROIC_6_R0_CR_R1G_MUXO_r0_cr_muxo_r1g3, \
   .tBit.r0_cr_muxo_r2g1 = PARAMSET_ROIC_6_R0_CR_R1G_MUXO_r0_cr_muxo_r2g1, \
   .tBit.r0_cr_muxo_r2g2 = PARAMSET_ROIC_6_R0_CR_R1G_MUXO_r0_cr_muxo_r2g2, \
   .tBit.r0_cr_muxo_r2g3 = PARAMSET_ROIC_6_R0_CR_R1G_MUXO_r0_cr_muxo_r2g3, \
  } ,\
  [7] = { \
   .tBit.r0_cr_muxo_r1g1 = PARAMSET_ROIC_7_R0_CR_R1G_MUXO_r0_cr_muxo_r1g1, \
   .tBit.r0_cr_muxo_r1g2 = PARAMSET_ROIC_7_R0_CR_R1G_MUXO_r0_cr_muxo_r1g2, \
   .tBit.r0_cr_muxo_r1g3 = PARAMSET_ROIC_7_R0_CR_R1G_MUXO_r0_cr_muxo_r1g3, \
   .tBit.r0_cr_muxo_r2g1 = PARAMSET_ROIC_7_R0_CR_R1G_MUXO_r0_cr_muxo_r2g1, \
   .tBit.r0_cr_muxo_r2g2 = PARAMSET_ROIC_7_R0_CR_R1G_MUXO_r0_cr_muxo_r2g2, \
   .tBit.r0_cr_muxo_r2g3 = PARAMSET_ROIC_7_R0_CR_R1G_MUXO_r0_cr_muxo_r2g3, \
  } ,\
 } ,\
 .R0_CR_GTUNE1 = \
 { \
  [0] = { \
   .tBit.r0_mux1_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE1_r0_mux1_gtune, \
   .tBit.r0_mux2_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE1_r0_mux2_gtune, \
   .tBit.r0_mux3_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE1_r0_mux3_gtune, \
   .tBit.r0_mux4_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE1_r0_mux4_gtune, \
   .tBit.r0_mux5_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE1_r0_mux5_gtune, \
   .tBit.r0_mux6_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE1_r0_mux6_gtune, \
   .tBit.r0_mux7_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE1_r0_mux7_gtune, \
   .tBit.r0_mux8_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE1_r0_mux8_gtune, \
   .tBit.r0_mux9_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE1_r0_mux9_gtune, \
   .tBit.r0_mux10_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE1_r0_mux10_gtune, \
  } ,\
  [1] = { \
   .tBit.r0_mux1_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE1_r0_mux1_gtune, \
   .tBit.r0_mux2_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE1_r0_mux2_gtune, \
   .tBit.r0_mux3_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE1_r0_mux3_gtune, \
   .tBit.r0_mux4_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE1_r0_mux4_gtune, \
   .tBit.r0_mux5_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE1_r0_mux5_gtune, \
   .tBit.r0_mux6_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE1_r0_mux6_gtune, \
   .tBit.r0_mux7_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE1_r0_mux7_gtune, \
   .tBit.r0_mux8_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE1_r0_mux8_gtune, \
   .tBit.r0_mux9_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE1_r0_mux9_gtune, \
   .tBit.r0_mux10_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE1_r0_mux10_gtune, \
  } ,\
  [2] = { \
   .tBit.r0_mux1_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE1_r0_mux1_gtune, \
   .tBit.r0_mux2_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE1_r0_mux2_gtune, \
   .tBit.r0_mux3_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE1_r0_mux3_gtune, \
   .tBit.r0_mux4_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE1_r0_mux4_gtune, \
   .tBit.r0_mux5_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE1_r0_mux5_gtune, \
   .tBit.r0_mux6_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE1_r0_mux6_gtune, \
   .tBit.r0_mux7_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE1_r0_mux7_gtune, \
   .tBit.r0_mux8_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE1_r0_mux8_gtune, \
   .tBit.r0_mux9_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE1_r0_mux9_gtune, \
   .tBit.r0_mux10_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE1_r0_mux10_gtune, \
  } ,\
  [3] = { \
   .tBit.r0_mux1_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE1_r0_mux1_gtune, \
   .tBit.r0_mux2_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE1_r0_mux2_gtune, \
   .tBit.r0_mux3_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE1_r0_mux3_gtune, \
   .tBit.r0_mux4_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE1_r0_mux4_gtune, \
   .tBit.r0_mux5_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE1_r0_mux5_gtune, \
   .tBit.r0_mux6_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE1_r0_mux6_gtune, \
   .tBit.r0_mux7_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE1_r0_mux7_gtune, \
   .tBit.r0_mux8_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE1_r0_mux8_gtune, \
   .tBit.r0_mux9_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE1_r0_mux9_gtune, \
   .tBit.r0_mux10_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE1_r0_mux10_gtune, \
  } ,\
  [4] = { \
   .tBit.r0_mux1_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE1_r0_mux1_gtune, \
   .tBit.r0_mux2_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE1_r0_mux2_gtune, \
   .tBit.r0_mux3_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE1_r0_mux3_gtune, \
   .tBit.r0_mux4_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE1_r0_mux4_gtune, \
   .tBit.r0_mux5_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE1_r0_mux5_gtune, \
   .tBit.r0_mux6_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE1_r0_mux6_gtune, \
   .tBit.r0_mux7_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE1_r0_mux7_gtune, \
   .tBit.r0_mux8_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE1_r0_mux8_gtune, \
   .tBit.r0_mux9_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE1_r0_mux9_gtune, \
   .tBit.r0_mux10_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE1_r0_mux10_gtune, \
  } ,\
  [5] = { \
   .tBit.r0_mux1_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE1_r0_mux1_gtune, \
   .tBit.r0_mux2_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE1_r0_mux2_gtune, \
   .tBit.r0_mux3_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE1_r0_mux3_gtune, \
   .tBit.r0_mux4_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE1_r0_mux4_gtune, \
   .tBit.r0_mux5_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE1_r0_mux5_gtune, \
   .tBit.r0_mux6_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE1_r0_mux6_gtune, \
   .tBit.r0_mux7_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE1_r0_mux7_gtune, \
   .tBit.r0_mux8_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE1_r0_mux8_gtune, \
   .tBit.r0_mux9_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE1_r0_mux9_gtune, \
   .tBit.r0_mux10_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE1_r0_mux10_gtune, \
  } ,\
  [6] = { \
   .tBit.r0_mux1_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE1_r0_mux1_gtune, \
   .tBit.r0_mux2_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE1_r0_mux2_gtune, \
   .tBit.r0_mux3_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE1_r0_mux3_gtune, \
   .tBit.r0_mux4_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE1_r0_mux4_gtune, \
   .tBit.r0_mux5_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE1_r0_mux5_gtune, \
   .tBit.r0_mux6_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE1_r0_mux6_gtune, \
   .tBit.r0_mux7_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE1_r0_mux7_gtune, \
   .tBit.r0_mux8_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE1_r0_mux8_gtune, \
   .tBit.r0_mux9_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE1_r0_mux9_gtune, \
   .tBit.r0_mux10_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE1_r0_mux10_gtune, \
  } ,\
  [7] = { \
   .tBit.r0_mux1_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE1_r0_mux1_gtune, \
   .tBit.r0_mux2_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE1_r0_mux2_gtune, \
   .tBit.r0_mux3_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE1_r0_mux3_gtune, \
   .tBit.r0_mux4_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE1_r0_mux4_gtune, \
   .tBit.r0_mux5_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE1_r0_mux5_gtune, \
   .tBit.r0_mux6_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE1_r0_mux6_gtune, \
   .tBit.r0_mux7_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE1_r0_mux7_gtune, \
   .tBit.r0_mux8_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE1_r0_mux8_gtune, \
   .tBit.r0_mux9_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE1_r0_mux9_gtune, \
   .tBit.r0_mux10_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE1_r0_mux10_gtune, \
  } ,\
 } ,\
 .R0_CR_GTUNE2 = \
 { \
  [0] = { \
   .tBit.r0_mux11_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE2_r0_mux11_gtune, \
   .tBit.r0_muxeo_gtune = PARAMSET_ROIC_0_R0_CR_GTUNE2_r0_muxeo_gtune, \
  } ,\
  [1] = { \
   .tBit.r0_mux11_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE2_r0_mux11_gtune, \
   .tBit.r0_muxeo_gtune = PARAMSET_ROIC_1_R0_CR_GTUNE2_r0_muxeo_gtune, \
  } ,\
  [2] = { \
   .tBit.r0_mux11_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE2_r0_mux11_gtune, \
   .tBit.r0_muxeo_gtune = PARAMSET_ROIC_2_R0_CR_GTUNE2_r0_muxeo_gtune, \
  } ,\
  [3] = { \
   .tBit.r0_mux11_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE2_r0_mux11_gtune, \
   .tBit.r0_muxeo_gtune = PARAMSET_ROIC_3_R0_CR_GTUNE2_r0_muxeo_gtune, \
  } ,\
  [4] = { \
   .tBit.r0_mux11_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE2_r0_mux11_gtune, \
   .tBit.r0_muxeo_gtune = PARAMSET_ROIC_4_R0_CR_GTUNE2_r0_muxeo_gtune, \
  } ,\
  [5] = { \
   .tBit.r0_mux11_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE2_r0_mux11_gtune, \
   .tBit.r0_muxeo_gtune = PARAMSET_ROIC_5_R0_CR_GTUNE2_r0_muxeo_gtune, \
  } ,\
  [6] = { \
   .tBit.r0_mux11_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE2_r0_mux11_gtune, \
   .tBit.r0_muxeo_gtune = PARAMSET_ROIC_6_R0_CR_GTUNE2_r0_muxeo_gtune, \
  } ,\
  [7] = { \
   .tBit.r0_mux11_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE2_r0_mux11_gtune, \
   .tBit.r0_muxeo_gtune = PARAMSET_ROIC_7_R0_CR_GTUNE2_r0_muxeo_gtune, \
  } ,\
 } ,\
 .R0_TUNE_GROUP_SEL1 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux1_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row2_gsel, \
   .tBit.r0_cr_mux1_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row3_gsel, \
   .tBit.r0_cr_mux1_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row4_gsel, \
   .tBit.r0_cr_mux2_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row2_gsel, \
   .tBit.r0_cr_mux2_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row3_gsel, \
   .tBit.r0_cr_mux2_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row4_gsel, \
   .tBit.r0_cr_mux3_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row2_gsel, \
   .tBit.r0_cr_mux3_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row3_gsel, \
   .tBit.r0_cr_mux3_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row4_gsel, \
   .tBit.r0_cr_mux4_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row2_gsel, \
   .tBit.r0_cr_mux4_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row3_gsel, \
   .tBit.r0_cr_mux4_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row4_gsel, \
   .tBit.r0_cr_mux5_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row2_gsel, \
   .tBit.r0_cr_mux5_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row3_gsel, \
   .tBit.r0_cr_mux5_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row4_gsel, \
   .tBit.r0_cr_mux6_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row2_gsel, \
   .tBit.r0_cr_mux6_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row3_gsel, \
   .tBit.r0_cr_mux6_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row4_gsel, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux1_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row2_gsel, \
   .tBit.r0_cr_mux1_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row3_gsel, \
   .tBit.r0_cr_mux1_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row4_gsel, \
   .tBit.r0_cr_mux2_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row2_gsel, \
   .tBit.r0_cr_mux2_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row3_gsel, \
   .tBit.r0_cr_mux2_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row4_gsel, \
   .tBit.r0_cr_mux3_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row2_gsel, \
   .tBit.r0_cr_mux3_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row3_gsel, \
   .tBit.r0_cr_mux3_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row4_gsel, \
   .tBit.r0_cr_mux4_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row2_gsel, \
   .tBit.r0_cr_mux4_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row3_gsel, \
   .tBit.r0_cr_mux4_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row4_gsel, \
   .tBit.r0_cr_mux5_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row2_gsel, \
   .tBit.r0_cr_mux5_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row3_gsel, \
   .tBit.r0_cr_mux5_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row4_gsel, \
   .tBit.r0_cr_mux6_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row2_gsel, \
   .tBit.r0_cr_mux6_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row3_gsel, \
   .tBit.r0_cr_mux6_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row4_gsel, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux1_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row2_gsel, \
   .tBit.r0_cr_mux1_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row3_gsel, \
   .tBit.r0_cr_mux1_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row4_gsel, \
   .tBit.r0_cr_mux2_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row2_gsel, \
   .tBit.r0_cr_mux2_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row3_gsel, \
   .tBit.r0_cr_mux2_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row4_gsel, \
   .tBit.r0_cr_mux3_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row2_gsel, \
   .tBit.r0_cr_mux3_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row3_gsel, \
   .tBit.r0_cr_mux3_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row4_gsel, \
   .tBit.r0_cr_mux4_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row2_gsel, \
   .tBit.r0_cr_mux4_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row3_gsel, \
   .tBit.r0_cr_mux4_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row4_gsel, \
   .tBit.r0_cr_mux5_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row2_gsel, \
   .tBit.r0_cr_mux5_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row3_gsel, \
   .tBit.r0_cr_mux5_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row4_gsel, \
   .tBit.r0_cr_mux6_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row2_gsel, \
   .tBit.r0_cr_mux6_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row3_gsel, \
   .tBit.r0_cr_mux6_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row4_gsel, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux1_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row2_gsel, \
   .tBit.r0_cr_mux1_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row3_gsel, \
   .tBit.r0_cr_mux1_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row4_gsel, \
   .tBit.r0_cr_mux2_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row2_gsel, \
   .tBit.r0_cr_mux2_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row3_gsel, \
   .tBit.r0_cr_mux2_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row4_gsel, \
   .tBit.r0_cr_mux3_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row2_gsel, \
   .tBit.r0_cr_mux3_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row3_gsel, \
   .tBit.r0_cr_mux3_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row4_gsel, \
   .tBit.r0_cr_mux4_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row2_gsel, \
   .tBit.r0_cr_mux4_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row3_gsel, \
   .tBit.r0_cr_mux4_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row4_gsel, \
   .tBit.r0_cr_mux5_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row2_gsel, \
   .tBit.r0_cr_mux5_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row3_gsel, \
   .tBit.r0_cr_mux5_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row4_gsel, \
   .tBit.r0_cr_mux6_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row2_gsel, \
   .tBit.r0_cr_mux6_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row3_gsel, \
   .tBit.r0_cr_mux6_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row4_gsel, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux1_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row2_gsel, \
   .tBit.r0_cr_mux1_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row3_gsel, \
   .tBit.r0_cr_mux1_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row4_gsel, \
   .tBit.r0_cr_mux2_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row2_gsel, \
   .tBit.r0_cr_mux2_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row3_gsel, \
   .tBit.r0_cr_mux2_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row4_gsel, \
   .tBit.r0_cr_mux3_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row2_gsel, \
   .tBit.r0_cr_mux3_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row3_gsel, \
   .tBit.r0_cr_mux3_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row4_gsel, \
   .tBit.r0_cr_mux4_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row2_gsel, \
   .tBit.r0_cr_mux4_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row3_gsel, \
   .tBit.r0_cr_mux4_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row4_gsel, \
   .tBit.r0_cr_mux5_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row2_gsel, \
   .tBit.r0_cr_mux5_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row3_gsel, \
   .tBit.r0_cr_mux5_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row4_gsel, \
   .tBit.r0_cr_mux6_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row2_gsel, \
   .tBit.r0_cr_mux6_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row3_gsel, \
   .tBit.r0_cr_mux6_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row4_gsel, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux1_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row2_gsel, \
   .tBit.r0_cr_mux1_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row3_gsel, \
   .tBit.r0_cr_mux1_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row4_gsel, \
   .tBit.r0_cr_mux2_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row2_gsel, \
   .tBit.r0_cr_mux2_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row3_gsel, \
   .tBit.r0_cr_mux2_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row4_gsel, \
   .tBit.r0_cr_mux3_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row2_gsel, \
   .tBit.r0_cr_mux3_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row3_gsel, \
   .tBit.r0_cr_mux3_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row4_gsel, \
   .tBit.r0_cr_mux4_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row2_gsel, \
   .tBit.r0_cr_mux4_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row3_gsel, \
   .tBit.r0_cr_mux4_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row4_gsel, \
   .tBit.r0_cr_mux5_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row2_gsel, \
   .tBit.r0_cr_mux5_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row3_gsel, \
   .tBit.r0_cr_mux5_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row4_gsel, \
   .tBit.r0_cr_mux6_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row2_gsel, \
   .tBit.r0_cr_mux6_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row3_gsel, \
   .tBit.r0_cr_mux6_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row4_gsel, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux1_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row2_gsel, \
   .tBit.r0_cr_mux1_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row3_gsel, \
   .tBit.r0_cr_mux1_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row4_gsel, \
   .tBit.r0_cr_mux2_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row2_gsel, \
   .tBit.r0_cr_mux2_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row3_gsel, \
   .tBit.r0_cr_mux2_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row4_gsel, \
   .tBit.r0_cr_mux3_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row2_gsel, \
   .tBit.r0_cr_mux3_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row3_gsel, \
   .tBit.r0_cr_mux3_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row4_gsel, \
   .tBit.r0_cr_mux4_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row2_gsel, \
   .tBit.r0_cr_mux4_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row3_gsel, \
   .tBit.r0_cr_mux4_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row4_gsel, \
   .tBit.r0_cr_mux5_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row2_gsel, \
   .tBit.r0_cr_mux5_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row3_gsel, \
   .tBit.r0_cr_mux5_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row4_gsel, \
   .tBit.r0_cr_mux6_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row2_gsel, \
   .tBit.r0_cr_mux6_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row3_gsel, \
   .tBit.r0_cr_mux6_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row4_gsel, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux1_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row2_gsel, \
   .tBit.r0_cr_mux1_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row3_gsel, \
   .tBit.r0_cr_mux1_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux1_row4_gsel, \
   .tBit.r0_cr_mux2_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row2_gsel, \
   .tBit.r0_cr_mux2_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row3_gsel, \
   .tBit.r0_cr_mux2_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux2_row4_gsel, \
   .tBit.r0_cr_mux3_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row2_gsel, \
   .tBit.r0_cr_mux3_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row3_gsel, \
   .tBit.r0_cr_mux3_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux3_row4_gsel, \
   .tBit.r0_cr_mux4_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row2_gsel, \
   .tBit.r0_cr_mux4_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row3_gsel, \
   .tBit.r0_cr_mux4_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux4_row4_gsel, \
   .tBit.r0_cr_mux5_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row2_gsel, \
   .tBit.r0_cr_mux5_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row3_gsel, \
   .tBit.r0_cr_mux5_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux5_row4_gsel, \
   .tBit.r0_cr_mux6_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row2_gsel, \
   .tBit.r0_cr_mux6_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row3_gsel, \
   .tBit.r0_cr_mux6_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL1_r0_cr_mux6_row4_gsel, \
  } ,\
 } ,\
 .R0_TUNE_GROUP_SEL2 = \
 { \
  [0] = { \
   .tBit.r0_cr_mux7_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row2_gsel, \
   .tBit.r0_cr_mux7_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row3_gsel, \
   .tBit.r0_cr_mux7_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row4_gsel, \
   .tBit.r0_cr_mux8_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row2_gsel, \
   .tBit.r0_cr_mux8_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row3_gsel, \
   .tBit.r0_cr_mux8_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row4_gsel, \
   .tBit.r0_cr_mux9_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row2_gsel, \
   .tBit.r0_cr_mux9_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row3_gsel, \
   .tBit.r0_cr_mux9_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row4_gsel, \
   .tBit.r0_cr_mux10_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row2_gsel, \
   .tBit.r0_cr_mux10_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row3_gsel, \
   .tBit.r0_cr_mux10_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row4_gsel, \
   .tBit.r0_cr_mux11_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row2_gsel, \
   .tBit.r0_cr_mux11_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row3_gsel, \
   .tBit.r0_cr_mux11_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row4_gsel, \
   .tBit.r0_cr_muxeo_row2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row2_gsel, \
   .tBit.r0_cr_muxeo_row3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row3_gsel, \
   .tBit.r0_cr_muxeo_row4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row4_gsel, \
  } ,\
  [1] = { \
   .tBit.r0_cr_mux7_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row2_gsel, \
   .tBit.r0_cr_mux7_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row3_gsel, \
   .tBit.r0_cr_mux7_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row4_gsel, \
   .tBit.r0_cr_mux8_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row2_gsel, \
   .tBit.r0_cr_mux8_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row3_gsel, \
   .tBit.r0_cr_mux8_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row4_gsel, \
   .tBit.r0_cr_mux9_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row2_gsel, \
   .tBit.r0_cr_mux9_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row3_gsel, \
   .tBit.r0_cr_mux9_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row4_gsel, \
   .tBit.r0_cr_mux10_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row2_gsel, \
   .tBit.r0_cr_mux10_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row3_gsel, \
   .tBit.r0_cr_mux10_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row4_gsel, \
   .tBit.r0_cr_mux11_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row2_gsel, \
   .tBit.r0_cr_mux11_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row3_gsel, \
   .tBit.r0_cr_mux11_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row4_gsel, \
   .tBit.r0_cr_muxeo_row2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row2_gsel, \
   .tBit.r0_cr_muxeo_row3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row3_gsel, \
   .tBit.r0_cr_muxeo_row4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row4_gsel, \
  } ,\
  [2] = { \
   .tBit.r0_cr_mux7_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row2_gsel, \
   .tBit.r0_cr_mux7_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row3_gsel, \
   .tBit.r0_cr_mux7_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row4_gsel, \
   .tBit.r0_cr_mux8_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row2_gsel, \
   .tBit.r0_cr_mux8_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row3_gsel, \
   .tBit.r0_cr_mux8_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row4_gsel, \
   .tBit.r0_cr_mux9_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row2_gsel, \
   .tBit.r0_cr_mux9_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row3_gsel, \
   .tBit.r0_cr_mux9_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row4_gsel, \
   .tBit.r0_cr_mux10_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row2_gsel, \
   .tBit.r0_cr_mux10_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row3_gsel, \
   .tBit.r0_cr_mux10_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row4_gsel, \
   .tBit.r0_cr_mux11_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row2_gsel, \
   .tBit.r0_cr_mux11_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row3_gsel, \
   .tBit.r0_cr_mux11_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row4_gsel, \
   .tBit.r0_cr_muxeo_row2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row2_gsel, \
   .tBit.r0_cr_muxeo_row3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row3_gsel, \
   .tBit.r0_cr_muxeo_row4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row4_gsel, \
  } ,\
  [3] = { \
   .tBit.r0_cr_mux7_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row2_gsel, \
   .tBit.r0_cr_mux7_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row3_gsel, \
   .tBit.r0_cr_mux7_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row4_gsel, \
   .tBit.r0_cr_mux8_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row2_gsel, \
   .tBit.r0_cr_mux8_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row3_gsel, \
   .tBit.r0_cr_mux8_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row4_gsel, \
   .tBit.r0_cr_mux9_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row2_gsel, \
   .tBit.r0_cr_mux9_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row3_gsel, \
   .tBit.r0_cr_mux9_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row4_gsel, \
   .tBit.r0_cr_mux10_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row2_gsel, \
   .tBit.r0_cr_mux10_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row3_gsel, \
   .tBit.r0_cr_mux10_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row4_gsel, \
   .tBit.r0_cr_mux11_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row2_gsel, \
   .tBit.r0_cr_mux11_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row3_gsel, \
   .tBit.r0_cr_mux11_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row4_gsel, \
   .tBit.r0_cr_muxeo_row2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row2_gsel, \
   .tBit.r0_cr_muxeo_row3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row3_gsel, \
   .tBit.r0_cr_muxeo_row4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row4_gsel, \
  } ,\
  [4] = { \
   .tBit.r0_cr_mux7_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row2_gsel, \
   .tBit.r0_cr_mux7_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row3_gsel, \
   .tBit.r0_cr_mux7_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row4_gsel, \
   .tBit.r0_cr_mux8_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row2_gsel, \
   .tBit.r0_cr_mux8_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row3_gsel, \
   .tBit.r0_cr_mux8_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row4_gsel, \
   .tBit.r0_cr_mux9_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row2_gsel, \
   .tBit.r0_cr_mux9_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row3_gsel, \
   .tBit.r0_cr_mux9_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row4_gsel, \
   .tBit.r0_cr_mux10_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row2_gsel, \
   .tBit.r0_cr_mux10_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row3_gsel, \
   .tBit.r0_cr_mux10_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row4_gsel, \
   .tBit.r0_cr_mux11_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row2_gsel, \
   .tBit.r0_cr_mux11_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row3_gsel, \
   .tBit.r0_cr_mux11_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row4_gsel, \
   .tBit.r0_cr_muxeo_row2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row2_gsel, \
   .tBit.r0_cr_muxeo_row3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row3_gsel, \
   .tBit.r0_cr_muxeo_row4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row4_gsel, \
  } ,\
  [5] = { \
   .tBit.r0_cr_mux7_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row2_gsel, \
   .tBit.r0_cr_mux7_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row3_gsel, \
   .tBit.r0_cr_mux7_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row4_gsel, \
   .tBit.r0_cr_mux8_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row2_gsel, \
   .tBit.r0_cr_mux8_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row3_gsel, \
   .tBit.r0_cr_mux8_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row4_gsel, \
   .tBit.r0_cr_mux9_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row2_gsel, \
   .tBit.r0_cr_mux9_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row3_gsel, \
   .tBit.r0_cr_mux9_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row4_gsel, \
   .tBit.r0_cr_mux10_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row2_gsel, \
   .tBit.r0_cr_mux10_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row3_gsel, \
   .tBit.r0_cr_mux10_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row4_gsel, \
   .tBit.r0_cr_mux11_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row2_gsel, \
   .tBit.r0_cr_mux11_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row3_gsel, \
   .tBit.r0_cr_mux11_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row4_gsel, \
   .tBit.r0_cr_muxeo_row2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row2_gsel, \
   .tBit.r0_cr_muxeo_row3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row3_gsel, \
   .tBit.r0_cr_muxeo_row4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row4_gsel, \
  } ,\
  [6] = { \
   .tBit.r0_cr_mux7_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row2_gsel, \
   .tBit.r0_cr_mux7_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row3_gsel, \
   .tBit.r0_cr_mux7_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row4_gsel, \
   .tBit.r0_cr_mux8_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row2_gsel, \
   .tBit.r0_cr_mux8_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row3_gsel, \
   .tBit.r0_cr_mux8_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row4_gsel, \
   .tBit.r0_cr_mux9_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row2_gsel, \
   .tBit.r0_cr_mux9_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row3_gsel, \
   .tBit.r0_cr_mux9_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row4_gsel, \
   .tBit.r0_cr_mux10_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row2_gsel, \
   .tBit.r0_cr_mux10_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row3_gsel, \
   .tBit.r0_cr_mux10_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row4_gsel, \
   .tBit.r0_cr_mux11_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row2_gsel, \
   .tBit.r0_cr_mux11_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row3_gsel, \
   .tBit.r0_cr_mux11_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row4_gsel, \
   .tBit.r0_cr_muxeo_row2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row2_gsel, \
   .tBit.r0_cr_muxeo_row3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row3_gsel, \
   .tBit.r0_cr_muxeo_row4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row4_gsel, \
  } ,\
  [7] = { \
   .tBit.r0_cr_mux7_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row2_gsel, \
   .tBit.r0_cr_mux7_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row3_gsel, \
   .tBit.r0_cr_mux7_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux7_row4_gsel, \
   .tBit.r0_cr_mux8_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row2_gsel, \
   .tBit.r0_cr_mux8_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row3_gsel, \
   .tBit.r0_cr_mux8_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux8_row4_gsel, \
   .tBit.r0_cr_mux9_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row2_gsel, \
   .tBit.r0_cr_mux9_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row3_gsel, \
   .tBit.r0_cr_mux9_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux9_row4_gsel, \
   .tBit.r0_cr_mux10_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row2_gsel, \
   .tBit.r0_cr_mux10_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row3_gsel, \
   .tBit.r0_cr_mux10_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux10_row4_gsel, \
   .tBit.r0_cr_mux11_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row2_gsel, \
   .tBit.r0_cr_mux11_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row3_gsel, \
   .tBit.r0_cr_mux11_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_mux11_row4_gsel, \
   .tBit.r0_cr_muxeo_row2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row2_gsel, \
   .tBit.r0_cr_muxeo_row3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row3_gsel, \
   .tBit.r0_cr_muxeo_row4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL2_r0_cr_muxeo_row4_gsel, \
  } ,\
 } ,\
 .R0_TUNE_GROUP_SEL3 = \
 { \
  [0] = { \
   .tBit.r0_cr_col2_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL3_r0_cr_col2_gsel, \
   .tBit.r0_cr_col3_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL3_r0_cr_col3_gsel, \
   .tBit.r0_cr_col4_gsel = PARAMSET_ROIC_0_R0_TUNE_GROUP_SEL3_r0_cr_col4_gsel, \
  } ,\
  [1] = { \
   .tBit.r0_cr_col2_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL3_r0_cr_col2_gsel, \
   .tBit.r0_cr_col3_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL3_r0_cr_col3_gsel, \
   .tBit.r0_cr_col4_gsel = PARAMSET_ROIC_1_R0_TUNE_GROUP_SEL3_r0_cr_col4_gsel, \
  } ,\
  [2] = { \
   .tBit.r0_cr_col2_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL3_r0_cr_col2_gsel, \
   .tBit.r0_cr_col3_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL3_r0_cr_col3_gsel, \
   .tBit.r0_cr_col4_gsel = PARAMSET_ROIC_2_R0_TUNE_GROUP_SEL3_r0_cr_col4_gsel, \
  } ,\
  [3] = { \
   .tBit.r0_cr_col2_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL3_r0_cr_col2_gsel, \
   .tBit.r0_cr_col3_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL3_r0_cr_col3_gsel, \
   .tBit.r0_cr_col4_gsel = PARAMSET_ROIC_3_R0_TUNE_GROUP_SEL3_r0_cr_col4_gsel, \
  } ,\
  [4] = { \
   .tBit.r0_cr_col2_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL3_r0_cr_col2_gsel, \
   .tBit.r0_cr_col3_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL3_r0_cr_col3_gsel, \
   .tBit.r0_cr_col4_gsel = PARAMSET_ROIC_4_R0_TUNE_GROUP_SEL3_r0_cr_col4_gsel, \
  } ,\
  [5] = { \
   .tBit.r0_cr_col2_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL3_r0_cr_col2_gsel, \
   .tBit.r0_cr_col3_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL3_r0_cr_col3_gsel, \
   .tBit.r0_cr_col4_gsel = PARAMSET_ROIC_5_R0_TUNE_GROUP_SEL3_r0_cr_col4_gsel, \
  } ,\
  [6] = { \
   .tBit.r0_cr_col2_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL3_r0_cr_col2_gsel, \
   .tBit.r0_cr_col3_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL3_r0_cr_col3_gsel, \
   .tBit.r0_cr_col4_gsel = PARAMSET_ROIC_6_R0_TUNE_GROUP_SEL3_r0_cr_col4_gsel, \
  } ,\
  [7] = { \
   .tBit.r0_cr_col2_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL3_r0_cr_col2_gsel, \
   .tBit.r0_cr_col3_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL3_r0_cr_col3_gsel, \
   .tBit.r0_cr_col4_gsel = PARAMSET_ROIC_7_R0_TUNE_GROUP_SEL3_r0_cr_col4_gsel, \
  } ,\
 } ,\
 .R0_ADC_IN_CTL = \
 { \
  .tBit.r0_adc_in = PARAMSET_ROIC_R0_ADC_IN_CTL_r0_adc_in, \
  .tBit.r0_adc_op_opt = PARAMSET_ROIC_R0_ADC_IN_CTL_r0_adc_op_opt, \
  .tBit.r0_adc_in_stuck_en = PARAMSET_ROIC_R0_ADC_IN_CTL_r0_adc_in_stuck_en, \
 } ,\
 .R0_AFE_SENSE_CTL = \
 { \
  .tBit.r0_adc_ref_sel = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_adc_ref_sel, \
  .tBit.r0_cvc1_comp = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_cvc1_comp, \
  .tBit.r0_int_ref = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_int_ref, \
  .tBit.r0_sha_ref = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_sha_ref, \
  .tBit.r0_cvc1_gc = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_cvc1_gc, \
  .tBit.r0_cvc2_gc = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_cvc2_gc, \
  .tBit.r0_int_gc = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_int_gc, \
  .tBit.r0_int_half = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_int_half, \
  .tBit.r0_hv_cvc1_bcon = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_hv_cvc1_bcon, \
  .tBit.r0_hv_cvc2_bcon = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_hv_cvc2_bcon, \
  .tBit.r0_lv_int_bcon = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_lv_int_bcon, \
  .tBit.r0_lv_sha_bcon = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_lv_sha_bcon, \
  .tBit.r0_ref_bcon = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_ref_bcon, \
  .tBit.r0_lv_adc_ref_bcon = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_lv_adc_ref_bcon, \
  .tBit.r0_lv_sha_buf_bcon = PARAMSET_ROIC_R0_AFE_SENSE_CTL_r0_lv_sha_buf_bcon, \
 } ,\
 .R0_PDB_CTL = \
 { \
  .tBit.r0_pdb_hvbias = PARAMSET_ROIC_R0_PDB_CTL_r0_pdb_hvbias, \
  .tBit.r0_pdb_hvc = PARAMSET_ROIC_R0_PDB_CTL_r0_pdb_hvc, \
  .tBit.r0_pdb_lvbias = PARAMSET_ROIC_R0_PDB_CTL_r0_pdb_lvbias, \
  .tBit.r0_pdb_int = PARAMSET_ROIC_R0_PDB_CTL_r0_pdb_int, \
  .tBit.r0_pdb_sha = PARAMSET_ROIC_R0_PDB_CTL_r0_pdb_sha, \
  .tBit.r0_pdb_sha_buf = PARAMSET_ROIC_R0_PDB_CTL_r0_pdb_sha_buf, \
  .tBit.r0_bgr_en = PARAMSET_ROIC_R0_PDB_CTL_r0_bgr_en, \
  .tBit.r0_bias_en = PARAMSET_ROIC_R0_PDB_CTL_r0_bias_en, \
  .tBit.r0_pdb_adc_ref = PARAMSET_ROIC_R0_PDB_CTL_r0_pdb_adc_ref, \
  .tBit.r0_stuck_hvbias = PARAMSET_ROIC_R0_PDB_CTL_r0_stuck_hvbias, \
  .tBit.r0_stuck_hvc = PARAMSET_ROIC_R0_PDB_CTL_r0_stuck_hvc, \
  .tBit.r0_stuck_lvbias = PARAMSET_ROIC_R0_PDB_CTL_r0_stuck_lvbias, \
  .tBit.r0_stuck_int = PARAMSET_ROIC_R0_PDB_CTL_r0_stuck_int, \
  .tBit.r0_stuck_sha = PARAMSET_ROIC_R0_PDB_CTL_r0_stuck_sha, \
  .tBit.r0_stuck_sha_buf = PARAMSET_ROIC_R0_PDB_CTL_r0_stuck_sha_buf, \
  .tBit.r0_stuck_bgr_en = PARAMSET_ROIC_R0_PDB_CTL_r0_stuck_bgr_en, \
  .tBit.r0_stuck_bias_en = PARAMSET_ROIC_R0_PDB_CTL_r0_stuck_bias_en, \
  .tBit.r0_stuck_adc_ref = PARAMSET_ROIC_R0_PDB_CTL_r0_stuck_adc_ref, \
 } ,\
 .R0_TG_STUCK = \
 { \
  .tBit.r0_stuck_cvc1_drv = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_cvc1_drv, \
  .tBit.r0_stuck_cvc1_drv_d = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_cvc1_drv_d, \
  .tBit.r0_stuck_rstp = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_rstp, \
  .tBit.r0_stuck_phtcr = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_phtcr, \
  .tBit.r0_stuck_vcr = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_vcr, \
  .tBit.r0_stuck_rsti = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_rsti, \
  .tBit.r0_stuck_phth0 = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_phth0, \
  .tBit.r0_stuck_phth1 = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_phth1, \
  .tBit.r0_stuck_pht0 = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_pht0, \
  .tBit.r0_stuck_pht1 = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_pht1, \
  .tBit.r0_stuck_pht2 = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_pht2, \
  .tBit.r0_stuck_pht3 = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_pht3, \
  .tBit.r0_stuck_cmfb_init = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_cmfb_init, \
  .tBit.r0_stuck_adc_rstb = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_adc_rstb, \
  .tBit.r0_stuck_vcr_en_odd = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_vcr_en_odd, \
  .tBit.r0_stuck_vcr_en_even = PARAMSET_ROIC_R0_TG_STUCK_r0_stuck_vcr_en_even, \
 } ,\
 .R0_TEST_MODE_CTL = \
 { \
  .tBit.r0_tm_mon_en = PARAMSET_ROIC_R0_TEST_MODE_CTL_r0_tm_mon_en, \
  .tBit.r0_tm_mon_s = PARAMSET_ROIC_R0_TEST_MODE_CTL_r0_tm_mon_s, \
  .tBit.r0_tm_ps_ev = PARAMSET_ROIC_R0_TEST_MODE_CTL_r0_tm_ps_ev, \
  .tBit.r0_tm_ps_od = PARAMSET_ROIC_R0_TEST_MODE_CTL_r0_tm_ps_od, \
  .tBit.r0_test_adc = PARAMSET_ROIC_R0_TEST_MODE_CTL_r0_test_adc, \
  .tBit.r0_tm_cr = PARAMSET_ROIC_R0_TEST_MODE_CTL_r0_tm_cr, \
 } ,\
 .R0_RESERVE = \
 { \
  .tBit.r0_reserve = PARAMSET_ROIC_R0_RESERVE_r0_reserve, \
 } ,\
 .R1_AFE_CFG = \
 { \
  .tBit.r1_buf_cfclk_on = PARAMSET_ROIC_R1_AFE_CFG_r1_buf_cfclk_on, \
  .tBit.r1_buf_clk_on = PARAMSET_ROIC_R1_AFE_CFG_r1_buf_clk_on, \
  .tBit.r1_cfclk_on = PARAMSET_ROIC_R1_AFE_CFG_r1_cfclk_on, \
 } ,\
 .R1_CH_EN = \
 { \
  .tBit.r1_ch_dum_drv_en = PARAMSET_ROIC_R1_CH_EN_r1_ch_dum_drv_en, \
  .tBit.r1_ch_en_int = PARAMSET_ROIC_R1_CH_EN_r1_ch_en_int, \
  .tBit.r1_ch_en_hvc = PARAMSET_ROIC_R1_CH_EN_r1_ch_en_hvc, \
 } ,\
 .R1_BUF_OPT = \
 { \
  .tBit.r1_double_buf_en = PARAMSET_ROIC_R1_BUF_OPT_r1_double_buf_en, \
  .tBit.r1_buf_test_mode = PARAMSET_ROIC_R1_BUF_OPT_r1_buf_test_mode, \
  .tBit.r1_buf_cnt_ctl_en = PARAMSET_ROIC_R1_BUF_OPT_r1_buf_cnt_ctl_en, \
  .tBit.r1_buf_cnt_skip_sel = PARAMSET_ROIC_R1_BUF_OPT_r1_buf_cnt_skip_sel, \
  .tBit.r1_buf_cnt_num = PARAMSET_ROIC_R1_BUF_OPT_r1_buf_cnt_num, \
  .tBit.r1_buf_auto_clr = PARAMSET_ROIC_R1_BUF_OPT_r1_buf_auto_clr, \
 } ,\
 .R1_VCOMR_OPT = \
 { \
  .tBit.r1_display_vcomr = PARAMSET_ROIC_R1_VCOMR_OPT_r1_display_vcomr, \
  .tBit.r1_touch_f_vcomr = PARAMSET_ROIC_R1_VCOMR_OPT_r1_touch_f_vcomr, \
  .tBit.r1_stuck_vcomr = PARAMSET_ROIC_R1_VCOMR_OPT_r1_stuck_vcomr, \
  .tBit.r1_stuck_vcomr_level = PARAMSET_ROIC_R1_VCOMR_OPT_r1_stuck_vcomr_level, \
  .tBit.r1_tsync_opt = PARAMSET_ROIC_R1_VCOMR_OPT_r1_tsync_opt, \
 } ,\
 .R1_MUX_CTL1 = \
 { \
  .tBit.r1_mux_s_stuck_en = PARAMSET_ROIC_R1_MUX_CTL1_r1_mux_s_stuck_en, \
  .tBit.r1_mux_int_stuck_val = PARAMSET_ROIC_R1_MUX_CTL1_r1_mux_int_stuck_val, \
  .tBit.r1_mux_s_stuck_val = PARAMSET_ROIC_R1_MUX_CTL1_r1_mux_s_stuck_val, \
  .tBit.r1_mux_f_ctl_en = PARAMSET_ROIC_R1_MUX_CTL1_r1_mux_f_ctl_en, \
  .tBit.r1_muxf_inv = PARAMSET_ROIC_R1_MUX_CTL1_r1_muxf_inv, \
  .tBit.r1_mux_f_stuck_en = PARAMSET_ROIC_R1_MUX_CTL1_r1_mux_f_stuck_en, \
  .tBit.r1_mux_nd_bit_en = PARAMSET_ROIC_R1_MUX_CTL1_r1_mux_nd_bit_en, \
 } ,\
 .R1_CR_RG_MUX1 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX1_r1_cr_mux1_r1g1, \
   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX1_r1_cr_mux1_r1g2, \
   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX1_r1_cr_mux1_r1g3, \
   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX1_r1_cr_mux1_r2g1, \
   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX1_r1_cr_mux1_r2g2, \
   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX1_r1_cr_mux1_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX1_r1_cr_mux1_r1g1, \
   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX1_r1_cr_mux1_r1g2, \
   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX1_r1_cr_mux1_r1g3, \
   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX1_r1_cr_mux1_r2g1, \
   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX1_r1_cr_mux1_r2g2, \
   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX1_r1_cr_mux1_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX1_r1_cr_mux1_r1g1, \
   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX1_r1_cr_mux1_r1g2, \
   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX1_r1_cr_mux1_r1g3, \
   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX1_r1_cr_mux1_r2g1, \
   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX1_r1_cr_mux1_r2g2, \
   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX1_r1_cr_mux1_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX1_r1_cr_mux1_r1g1, \
   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX1_r1_cr_mux1_r1g2, \
   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX1_r1_cr_mux1_r1g3, \
   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX1_r1_cr_mux1_r2g1, \
   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX1_r1_cr_mux1_r2g2, \
   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX1_r1_cr_mux1_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX1_r1_cr_mux1_r1g1, \
   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX1_r1_cr_mux1_r1g2, \
   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX1_r1_cr_mux1_r1g3, \
   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX1_r1_cr_mux1_r2g1, \
   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX1_r1_cr_mux1_r2g2, \
   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX1_r1_cr_mux1_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX1_r1_cr_mux1_r1g1, \
   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX1_r1_cr_mux1_r1g2, \
   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX1_r1_cr_mux1_r1g3, \
   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX1_r1_cr_mux1_r2g1, \
   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX1_r1_cr_mux1_r2g2, \
   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX1_r1_cr_mux1_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX1_r1_cr_mux1_r1g1, \
   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX1_r1_cr_mux1_r1g2, \
   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX1_r1_cr_mux1_r1g3, \
   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX1_r1_cr_mux1_r2g1, \
   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX1_r1_cr_mux1_r2g2, \
   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX1_r1_cr_mux1_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux1_r1g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX1_r1_cr_mux1_r1g1, \
   .tBit.r1_cr_mux1_r1g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX1_r1_cr_mux1_r1g2, \
   .tBit.r1_cr_mux1_r1g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX1_r1_cr_mux1_r1g3, \
   .tBit.r1_cr_mux1_r2g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX1_r1_cr_mux1_r2g1, \
   .tBit.r1_cr_mux1_r2g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX1_r1_cr_mux1_r2g2, \
   .tBit.r1_cr_mux1_r2g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX1_r1_cr_mux1_r2g3, \
  } ,\
 } ,\
 .R1_CR_RG_MUX2 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX2_r1_cr_mux2_r1g1, \
   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX2_r1_cr_mux2_r1g2, \
   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX2_r1_cr_mux2_r1g3, \
   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX2_r1_cr_mux2_r2g1, \
   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX2_r1_cr_mux2_r2g2, \
   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX2_r1_cr_mux2_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX2_r1_cr_mux2_r1g1, \
   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX2_r1_cr_mux2_r1g2, \
   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX2_r1_cr_mux2_r1g3, \
   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX2_r1_cr_mux2_r2g1, \
   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX2_r1_cr_mux2_r2g2, \
   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX2_r1_cr_mux2_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX2_r1_cr_mux2_r1g1, \
   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX2_r1_cr_mux2_r1g2, \
   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX2_r1_cr_mux2_r1g3, \
   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX2_r1_cr_mux2_r2g1, \
   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX2_r1_cr_mux2_r2g2, \
   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX2_r1_cr_mux2_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX2_r1_cr_mux2_r1g1, \
   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX2_r1_cr_mux2_r1g2, \
   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX2_r1_cr_mux2_r1g3, \
   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX2_r1_cr_mux2_r2g1, \
   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX2_r1_cr_mux2_r2g2, \
   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX2_r1_cr_mux2_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX2_r1_cr_mux2_r1g1, \
   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX2_r1_cr_mux2_r1g2, \
   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX2_r1_cr_mux2_r1g3, \
   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX2_r1_cr_mux2_r2g1, \
   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX2_r1_cr_mux2_r2g2, \
   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX2_r1_cr_mux2_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX2_r1_cr_mux2_r1g1, \
   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX2_r1_cr_mux2_r1g2, \
   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX2_r1_cr_mux2_r1g3, \
   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX2_r1_cr_mux2_r2g1, \
   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX2_r1_cr_mux2_r2g2, \
   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX2_r1_cr_mux2_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX2_r1_cr_mux2_r1g1, \
   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX2_r1_cr_mux2_r1g2, \
   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX2_r1_cr_mux2_r1g3, \
   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX2_r1_cr_mux2_r2g1, \
   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX2_r1_cr_mux2_r2g2, \
   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX2_r1_cr_mux2_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux2_r1g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX2_r1_cr_mux2_r1g1, \
   .tBit.r1_cr_mux2_r1g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX2_r1_cr_mux2_r1g2, \
   .tBit.r1_cr_mux2_r1g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX2_r1_cr_mux2_r1g3, \
   .tBit.r1_cr_mux2_r2g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX2_r1_cr_mux2_r2g1, \
   .tBit.r1_cr_mux2_r2g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX2_r1_cr_mux2_r2g2, \
   .tBit.r1_cr_mux2_r2g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX2_r1_cr_mux2_r2g3, \
  } ,\
 } ,\
 .R1_CR_RG_MUX3 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX3_r1_cr_mux3_r1g1, \
   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX3_r1_cr_mux3_r1g2, \
   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX3_r1_cr_mux3_r1g3, \
   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX3_r1_cr_mux3_r2g1, \
   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX3_r1_cr_mux3_r2g2, \
   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX3_r1_cr_mux3_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX3_r1_cr_mux3_r1g1, \
   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX3_r1_cr_mux3_r1g2, \
   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX3_r1_cr_mux3_r1g3, \
   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX3_r1_cr_mux3_r2g1, \
   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX3_r1_cr_mux3_r2g2, \
   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX3_r1_cr_mux3_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX3_r1_cr_mux3_r1g1, \
   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX3_r1_cr_mux3_r1g2, \
   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX3_r1_cr_mux3_r1g3, \
   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX3_r1_cr_mux3_r2g1, \
   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX3_r1_cr_mux3_r2g2, \
   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX3_r1_cr_mux3_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX3_r1_cr_mux3_r1g1, \
   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX3_r1_cr_mux3_r1g2, \
   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX3_r1_cr_mux3_r1g3, \
   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX3_r1_cr_mux3_r2g1, \
   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX3_r1_cr_mux3_r2g2, \
   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX3_r1_cr_mux3_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX3_r1_cr_mux3_r1g1, \
   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX3_r1_cr_mux3_r1g2, \
   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX3_r1_cr_mux3_r1g3, \
   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX3_r1_cr_mux3_r2g1, \
   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX3_r1_cr_mux3_r2g2, \
   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX3_r1_cr_mux3_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX3_r1_cr_mux3_r1g1, \
   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX3_r1_cr_mux3_r1g2, \
   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX3_r1_cr_mux3_r1g3, \
   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX3_r1_cr_mux3_r2g1, \
   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX3_r1_cr_mux3_r2g2, \
   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX3_r1_cr_mux3_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX3_r1_cr_mux3_r1g1, \
   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX3_r1_cr_mux3_r1g2, \
   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX3_r1_cr_mux3_r1g3, \
   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX3_r1_cr_mux3_r2g1, \
   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX3_r1_cr_mux3_r2g2, \
   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX3_r1_cr_mux3_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux3_r1g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX3_r1_cr_mux3_r1g1, \
   .tBit.r1_cr_mux3_r1g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX3_r1_cr_mux3_r1g2, \
   .tBit.r1_cr_mux3_r1g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX3_r1_cr_mux3_r1g3, \
   .tBit.r1_cr_mux3_r2g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX3_r1_cr_mux3_r2g1, \
   .tBit.r1_cr_mux3_r2g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX3_r1_cr_mux3_r2g2, \
   .tBit.r1_cr_mux3_r2g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX3_r1_cr_mux3_r2g3, \
  } ,\
 } ,\
 .R1_CR_RG_MUX4 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX4_r1_cr_mux4_r1g1, \
   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX4_r1_cr_mux4_r1g2, \
   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX4_r1_cr_mux4_r1g3, \
   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX4_r1_cr_mux4_r2g1, \
   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX4_r1_cr_mux4_r2g2, \
   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX4_r1_cr_mux4_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX4_r1_cr_mux4_r1g1, \
   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX4_r1_cr_mux4_r1g2, \
   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX4_r1_cr_mux4_r1g3, \
   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX4_r1_cr_mux4_r2g1, \
   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX4_r1_cr_mux4_r2g2, \
   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX4_r1_cr_mux4_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX4_r1_cr_mux4_r1g1, \
   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX4_r1_cr_mux4_r1g2, \
   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX4_r1_cr_mux4_r1g3, \
   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX4_r1_cr_mux4_r2g1, \
   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX4_r1_cr_mux4_r2g2, \
   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX4_r1_cr_mux4_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX4_r1_cr_mux4_r1g1, \
   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX4_r1_cr_mux4_r1g2, \
   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX4_r1_cr_mux4_r1g3, \
   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX4_r1_cr_mux4_r2g1, \
   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX4_r1_cr_mux4_r2g2, \
   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX4_r1_cr_mux4_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX4_r1_cr_mux4_r1g1, \
   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX4_r1_cr_mux4_r1g2, \
   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX4_r1_cr_mux4_r1g3, \
   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX4_r1_cr_mux4_r2g1, \
   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX4_r1_cr_mux4_r2g2, \
   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX4_r1_cr_mux4_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX4_r1_cr_mux4_r1g1, \
   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX4_r1_cr_mux4_r1g2, \
   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX4_r1_cr_mux4_r1g3, \
   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX4_r1_cr_mux4_r2g1, \
   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX4_r1_cr_mux4_r2g2, \
   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX4_r1_cr_mux4_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX4_r1_cr_mux4_r1g1, \
   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX4_r1_cr_mux4_r1g2, \
   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX4_r1_cr_mux4_r1g3, \
   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX4_r1_cr_mux4_r2g1, \
   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX4_r1_cr_mux4_r2g2, \
   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX4_r1_cr_mux4_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux4_r1g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX4_r1_cr_mux4_r1g1, \
   .tBit.r1_cr_mux4_r1g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX4_r1_cr_mux4_r1g2, \
   .tBit.r1_cr_mux4_r1g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX4_r1_cr_mux4_r1g3, \
   .tBit.r1_cr_mux4_r2g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX4_r1_cr_mux4_r2g1, \
   .tBit.r1_cr_mux4_r2g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX4_r1_cr_mux4_r2g2, \
   .tBit.r1_cr_mux4_r2g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX4_r1_cr_mux4_r2g3, \
  } ,\
 } ,\
 .R1_CR_RG_MUX5 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX5_r1_cr_mux5_r1g1, \
   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX5_r1_cr_mux5_r1g2, \
   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX5_r1_cr_mux5_r1g3, \
   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX5_r1_cr_mux5_r2g1, \
   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX5_r1_cr_mux5_r2g2, \
   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX5_r1_cr_mux5_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX5_r1_cr_mux5_r1g1, \
   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX5_r1_cr_mux5_r1g2, \
   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX5_r1_cr_mux5_r1g3, \
   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX5_r1_cr_mux5_r2g1, \
   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX5_r1_cr_mux5_r2g2, \
   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX5_r1_cr_mux5_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX5_r1_cr_mux5_r1g1, \
   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX5_r1_cr_mux5_r1g2, \
   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX5_r1_cr_mux5_r1g3, \
   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX5_r1_cr_mux5_r2g1, \
   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX5_r1_cr_mux5_r2g2, \
   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX5_r1_cr_mux5_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX5_r1_cr_mux5_r1g1, \
   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX5_r1_cr_mux5_r1g2, \
   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX5_r1_cr_mux5_r1g3, \
   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX5_r1_cr_mux5_r2g1, \
   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX5_r1_cr_mux5_r2g2, \
   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX5_r1_cr_mux5_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX5_r1_cr_mux5_r1g1, \
   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX5_r1_cr_mux5_r1g2, \
   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX5_r1_cr_mux5_r1g3, \
   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX5_r1_cr_mux5_r2g1, \
   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX5_r1_cr_mux5_r2g2, \
   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX5_r1_cr_mux5_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX5_r1_cr_mux5_r1g1, \
   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX5_r1_cr_mux5_r1g2, \
   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX5_r1_cr_mux5_r1g3, \
   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX5_r1_cr_mux5_r2g1, \
   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX5_r1_cr_mux5_r2g2, \
   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX5_r1_cr_mux5_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX5_r1_cr_mux5_r1g1, \
   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX5_r1_cr_mux5_r1g2, \
   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX5_r1_cr_mux5_r1g3, \
   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX5_r1_cr_mux5_r2g1, \
   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX5_r1_cr_mux5_r2g2, \
   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX5_r1_cr_mux5_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux5_r1g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX5_r1_cr_mux5_r1g1, \
   .tBit.r1_cr_mux5_r1g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX5_r1_cr_mux5_r1g2, \
   .tBit.r1_cr_mux5_r1g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX5_r1_cr_mux5_r1g3, \
   .tBit.r1_cr_mux5_r2g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX5_r1_cr_mux5_r2g1, \
   .tBit.r1_cr_mux5_r2g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX5_r1_cr_mux5_r2g2, \
   .tBit.r1_cr_mux5_r2g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX5_r1_cr_mux5_r2g3, \
  } ,\
 } ,\
 .R1_CR_RG_MUX6 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX6_r1_cr_mux6_r1g1, \
   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX6_r1_cr_mux6_r1g2, \
   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX6_r1_cr_mux6_r1g3, \
   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX6_r1_cr_mux6_r2g1, \
   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX6_r1_cr_mux6_r2g2, \
   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX6_r1_cr_mux6_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX6_r1_cr_mux6_r1g1, \
   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX6_r1_cr_mux6_r1g2, \
   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX6_r1_cr_mux6_r1g3, \
   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX6_r1_cr_mux6_r2g1, \
   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX6_r1_cr_mux6_r2g2, \
   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX6_r1_cr_mux6_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX6_r1_cr_mux6_r1g1, \
   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX6_r1_cr_mux6_r1g2, \
   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX6_r1_cr_mux6_r1g3, \
   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX6_r1_cr_mux6_r2g1, \
   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX6_r1_cr_mux6_r2g2, \
   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX6_r1_cr_mux6_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX6_r1_cr_mux6_r1g1, \
   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX6_r1_cr_mux6_r1g2, \
   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX6_r1_cr_mux6_r1g3, \
   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX6_r1_cr_mux6_r2g1, \
   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX6_r1_cr_mux6_r2g2, \
   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX6_r1_cr_mux6_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX6_r1_cr_mux6_r1g1, \
   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX6_r1_cr_mux6_r1g2, \
   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX6_r1_cr_mux6_r1g3, \
   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX6_r1_cr_mux6_r2g1, \
   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX6_r1_cr_mux6_r2g2, \
   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX6_r1_cr_mux6_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX6_r1_cr_mux6_r1g1, \
   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX6_r1_cr_mux6_r1g2, \
   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX6_r1_cr_mux6_r1g3, \
   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX6_r1_cr_mux6_r2g1, \
   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX6_r1_cr_mux6_r2g2, \
   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX6_r1_cr_mux6_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX6_r1_cr_mux6_r1g1, \
   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX6_r1_cr_mux6_r1g2, \
   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX6_r1_cr_mux6_r1g3, \
   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX6_r1_cr_mux6_r2g1, \
   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX6_r1_cr_mux6_r2g2, \
   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX6_r1_cr_mux6_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux6_r1g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX6_r1_cr_mux6_r1g1, \
   .tBit.r1_cr_mux6_r1g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX6_r1_cr_mux6_r1g2, \
   .tBit.r1_cr_mux6_r1g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX6_r1_cr_mux6_r1g3, \
   .tBit.r1_cr_mux6_r2g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX6_r1_cr_mux6_r2g1, \
   .tBit.r1_cr_mux6_r2g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX6_r1_cr_mux6_r2g2, \
   .tBit.r1_cr_mux6_r2g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX6_r1_cr_mux6_r2g3, \
  } ,\
 } ,\
 .R1_CR_RG_MUX7 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX7_r1_cr_mux7_r1g1, \
   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX7_r1_cr_mux7_r1g2, \
   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX7_r1_cr_mux7_r1g3, \
   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX7_r1_cr_mux7_r2g1, \
   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX7_r1_cr_mux7_r2g2, \
   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX7_r1_cr_mux7_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX7_r1_cr_mux7_r1g1, \
   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX7_r1_cr_mux7_r1g2, \
   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX7_r1_cr_mux7_r1g3, \
   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX7_r1_cr_mux7_r2g1, \
   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX7_r1_cr_mux7_r2g2, \
   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX7_r1_cr_mux7_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX7_r1_cr_mux7_r1g1, \
   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX7_r1_cr_mux7_r1g2, \
   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX7_r1_cr_mux7_r1g3, \
   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX7_r1_cr_mux7_r2g1, \
   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX7_r1_cr_mux7_r2g2, \
   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX7_r1_cr_mux7_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX7_r1_cr_mux7_r1g1, \
   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX7_r1_cr_mux7_r1g2, \
   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX7_r1_cr_mux7_r1g3, \
   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX7_r1_cr_mux7_r2g1, \
   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX7_r1_cr_mux7_r2g2, \
   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX7_r1_cr_mux7_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX7_r1_cr_mux7_r1g1, \
   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX7_r1_cr_mux7_r1g2, \
   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX7_r1_cr_mux7_r1g3, \
   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX7_r1_cr_mux7_r2g1, \
   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX7_r1_cr_mux7_r2g2, \
   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX7_r1_cr_mux7_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX7_r1_cr_mux7_r1g1, \
   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX7_r1_cr_mux7_r1g2, \
   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX7_r1_cr_mux7_r1g3, \
   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX7_r1_cr_mux7_r2g1, \
   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX7_r1_cr_mux7_r2g2, \
   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX7_r1_cr_mux7_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX7_r1_cr_mux7_r1g1, \
   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX7_r1_cr_mux7_r1g2, \
   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX7_r1_cr_mux7_r1g3, \
   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX7_r1_cr_mux7_r2g1, \
   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX7_r1_cr_mux7_r2g2, \
   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX7_r1_cr_mux7_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux7_r1g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX7_r1_cr_mux7_r1g1, \
   .tBit.r1_cr_mux7_r1g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX7_r1_cr_mux7_r1g2, \
   .tBit.r1_cr_mux7_r1g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX7_r1_cr_mux7_r1g3, \
   .tBit.r1_cr_mux7_r2g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX7_r1_cr_mux7_r2g1, \
   .tBit.r1_cr_mux7_r2g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX7_r1_cr_mux7_r2g2, \
   .tBit.r1_cr_mux7_r2g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX7_r1_cr_mux7_r2g3, \
  } ,\
 } ,\
 .R1_CR_RG_MUX8 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX8_r1_cr_mux8_r1g1, \
   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX8_r1_cr_mux8_r1g2, \
   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX8_r1_cr_mux8_r1g3, \
   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX8_r1_cr_mux8_r2g1, \
   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX8_r1_cr_mux8_r2g2, \
   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX8_r1_cr_mux8_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX8_r1_cr_mux8_r1g1, \
   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX8_r1_cr_mux8_r1g2, \
   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX8_r1_cr_mux8_r1g3, \
   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX8_r1_cr_mux8_r2g1, \
   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX8_r1_cr_mux8_r2g2, \
   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX8_r1_cr_mux8_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX8_r1_cr_mux8_r1g1, \
   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX8_r1_cr_mux8_r1g2, \
   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX8_r1_cr_mux8_r1g3, \
   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX8_r1_cr_mux8_r2g1, \
   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX8_r1_cr_mux8_r2g2, \
   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX8_r1_cr_mux8_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX8_r1_cr_mux8_r1g1, \
   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX8_r1_cr_mux8_r1g2, \
   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX8_r1_cr_mux8_r1g3, \
   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX8_r1_cr_mux8_r2g1, \
   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX8_r1_cr_mux8_r2g2, \
   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX8_r1_cr_mux8_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX8_r1_cr_mux8_r1g1, \
   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX8_r1_cr_mux8_r1g2, \
   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX8_r1_cr_mux8_r1g3, \
   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX8_r1_cr_mux8_r2g1, \
   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX8_r1_cr_mux8_r2g2, \
   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX8_r1_cr_mux8_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX8_r1_cr_mux8_r1g1, \
   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX8_r1_cr_mux8_r1g2, \
   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX8_r1_cr_mux8_r1g3, \
   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX8_r1_cr_mux8_r2g1, \
   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX8_r1_cr_mux8_r2g2, \
   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX8_r1_cr_mux8_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX8_r1_cr_mux8_r1g1, \
   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX8_r1_cr_mux8_r1g2, \
   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX8_r1_cr_mux8_r1g3, \
   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX8_r1_cr_mux8_r2g1, \
   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX8_r1_cr_mux8_r2g2, \
   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX8_r1_cr_mux8_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux8_r1g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX8_r1_cr_mux8_r1g1, \
   .tBit.r1_cr_mux8_r1g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX8_r1_cr_mux8_r1g2, \
   .tBit.r1_cr_mux8_r1g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX8_r1_cr_mux8_r1g3, \
   .tBit.r1_cr_mux8_r2g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX8_r1_cr_mux8_r2g1, \
   .tBit.r1_cr_mux8_r2g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX8_r1_cr_mux8_r2g2, \
   .tBit.r1_cr_mux8_r2g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX8_r1_cr_mux8_r2g3, \
  } ,\
 } ,\
 .R1_CR_RG_MUX9 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX9_r1_cr_mux9_r1g1, \
   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX9_r1_cr_mux9_r1g2, \
   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX9_r1_cr_mux9_r1g3, \
   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX9_r1_cr_mux9_r2g1, \
   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX9_r1_cr_mux9_r2g2, \
   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX9_r1_cr_mux9_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX9_r1_cr_mux9_r1g1, \
   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX9_r1_cr_mux9_r1g2, \
   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX9_r1_cr_mux9_r1g3, \
   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX9_r1_cr_mux9_r2g1, \
   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX9_r1_cr_mux9_r2g2, \
   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX9_r1_cr_mux9_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX9_r1_cr_mux9_r1g1, \
   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX9_r1_cr_mux9_r1g2, \
   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX9_r1_cr_mux9_r1g3, \
   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX9_r1_cr_mux9_r2g1, \
   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX9_r1_cr_mux9_r2g2, \
   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX9_r1_cr_mux9_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX9_r1_cr_mux9_r1g1, \
   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX9_r1_cr_mux9_r1g2, \
   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX9_r1_cr_mux9_r1g3, \
   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX9_r1_cr_mux9_r2g1, \
   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX9_r1_cr_mux9_r2g2, \
   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX9_r1_cr_mux9_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX9_r1_cr_mux9_r1g1, \
   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX9_r1_cr_mux9_r1g2, \
   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX9_r1_cr_mux9_r1g3, \
   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX9_r1_cr_mux9_r2g1, \
   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX9_r1_cr_mux9_r2g2, \
   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX9_r1_cr_mux9_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX9_r1_cr_mux9_r1g1, \
   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX9_r1_cr_mux9_r1g2, \
   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX9_r1_cr_mux9_r1g3, \
   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX9_r1_cr_mux9_r2g1, \
   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX9_r1_cr_mux9_r2g2, \
   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX9_r1_cr_mux9_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX9_r1_cr_mux9_r1g1, \
   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX9_r1_cr_mux9_r1g2, \
   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX9_r1_cr_mux9_r1g3, \
   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX9_r1_cr_mux9_r2g1, \
   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX9_r1_cr_mux9_r2g2, \
   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX9_r1_cr_mux9_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux9_r1g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX9_r1_cr_mux9_r1g1, \
   .tBit.r1_cr_mux9_r1g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX9_r1_cr_mux9_r1g2, \
   .tBit.r1_cr_mux9_r1g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX9_r1_cr_mux9_r1g3, \
   .tBit.r1_cr_mux9_r2g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX9_r1_cr_mux9_r2g1, \
   .tBit.r1_cr_mux9_r2g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX9_r1_cr_mux9_r2g2, \
   .tBit.r1_cr_mux9_r2g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX9_r1_cr_mux9_r2g3, \
  } ,\
 } ,\
 .R1_CR_RG_MUX10 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX10_r1_cr_mux10_r1g1, \
   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX10_r1_cr_mux10_r1g2, \
   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX10_r1_cr_mux10_r1g3, \
   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX10_r1_cr_mux10_r2g1, \
   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX10_r1_cr_mux10_r2g2, \
   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX10_r1_cr_mux10_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX10_r1_cr_mux10_r1g1, \
   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX10_r1_cr_mux10_r1g2, \
   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX10_r1_cr_mux10_r1g3, \
   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX10_r1_cr_mux10_r2g1, \
   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX10_r1_cr_mux10_r2g2, \
   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX10_r1_cr_mux10_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX10_r1_cr_mux10_r1g1, \
   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX10_r1_cr_mux10_r1g2, \
   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX10_r1_cr_mux10_r1g3, \
   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX10_r1_cr_mux10_r2g1, \
   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX10_r1_cr_mux10_r2g2, \
   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX10_r1_cr_mux10_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX10_r1_cr_mux10_r1g1, \
   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX10_r1_cr_mux10_r1g2, \
   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX10_r1_cr_mux10_r1g3, \
   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX10_r1_cr_mux10_r2g1, \
   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX10_r1_cr_mux10_r2g2, \
   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX10_r1_cr_mux10_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX10_r1_cr_mux10_r1g1, \
   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX10_r1_cr_mux10_r1g2, \
   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX10_r1_cr_mux10_r1g3, \
   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX10_r1_cr_mux10_r2g1, \
   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX10_r1_cr_mux10_r2g2, \
   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX10_r1_cr_mux10_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX10_r1_cr_mux10_r1g1, \
   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX10_r1_cr_mux10_r1g2, \
   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX10_r1_cr_mux10_r1g3, \
   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX10_r1_cr_mux10_r2g1, \
   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX10_r1_cr_mux10_r2g2, \
   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX10_r1_cr_mux10_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX10_r1_cr_mux10_r1g1, \
   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX10_r1_cr_mux10_r1g2, \
   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX10_r1_cr_mux10_r1g3, \
   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX10_r1_cr_mux10_r2g1, \
   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX10_r1_cr_mux10_r2g2, \
   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX10_r1_cr_mux10_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux10_r1g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX10_r1_cr_mux10_r1g1, \
   .tBit.r1_cr_mux10_r1g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX10_r1_cr_mux10_r1g2, \
   .tBit.r1_cr_mux10_r1g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX10_r1_cr_mux10_r1g3, \
   .tBit.r1_cr_mux10_r2g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX10_r1_cr_mux10_r2g1, \
   .tBit.r1_cr_mux10_r2g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX10_r1_cr_mux10_r2g2, \
   .tBit.r1_cr_mux10_r2g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX10_r1_cr_mux10_r2g3, \
  } ,\
 } ,\
 .R1_CR_RG_MUX11 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux11_r1g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX11_r1_cr_mux11_r1g1, \
   .tBit.r1_cr_mux11_r1g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX11_r1_cr_mux11_r1g2, \
   .tBit.r1_cr_mux11_r1g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX11_r1_cr_mux11_r1g3, \
   .tBit.r1_cr_mux11_r2g1 = PARAMSET_ROIC_0_R1_CR_RG_MUX11_r1_cr_mux11_r2g1, \
   .tBit.r1_cr_mux11_r2g2 = PARAMSET_ROIC_0_R1_CR_RG_MUX11_r1_cr_mux11_r2g2, \
   .tBit.r1_cr_mux11_r2g3 = PARAMSET_ROIC_0_R1_CR_RG_MUX11_r1_cr_mux11_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux11_r1g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX11_r1_cr_mux11_r1g1, \
   .tBit.r1_cr_mux11_r1g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX11_r1_cr_mux11_r1g2, \
   .tBit.r1_cr_mux11_r1g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX11_r1_cr_mux11_r1g3, \
   .tBit.r1_cr_mux11_r2g1 = PARAMSET_ROIC_1_R1_CR_RG_MUX11_r1_cr_mux11_r2g1, \
   .tBit.r1_cr_mux11_r2g2 = PARAMSET_ROIC_1_R1_CR_RG_MUX11_r1_cr_mux11_r2g2, \
   .tBit.r1_cr_mux11_r2g3 = PARAMSET_ROIC_1_R1_CR_RG_MUX11_r1_cr_mux11_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux11_r1g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX11_r1_cr_mux11_r1g1, \
   .tBit.r1_cr_mux11_r1g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX11_r1_cr_mux11_r1g2, \
   .tBit.r1_cr_mux11_r1g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX11_r1_cr_mux11_r1g3, \
   .tBit.r1_cr_mux11_r2g1 = PARAMSET_ROIC_2_R1_CR_RG_MUX11_r1_cr_mux11_r2g1, \
   .tBit.r1_cr_mux11_r2g2 = PARAMSET_ROIC_2_R1_CR_RG_MUX11_r1_cr_mux11_r2g2, \
   .tBit.r1_cr_mux11_r2g3 = PARAMSET_ROIC_2_R1_CR_RG_MUX11_r1_cr_mux11_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux11_r1g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX11_r1_cr_mux11_r1g1, \
   .tBit.r1_cr_mux11_r1g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX11_r1_cr_mux11_r1g2, \
   .tBit.r1_cr_mux11_r1g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX11_r1_cr_mux11_r1g3, \
   .tBit.r1_cr_mux11_r2g1 = PARAMSET_ROIC_3_R1_CR_RG_MUX11_r1_cr_mux11_r2g1, \
   .tBit.r1_cr_mux11_r2g2 = PARAMSET_ROIC_3_R1_CR_RG_MUX11_r1_cr_mux11_r2g2, \
   .tBit.r1_cr_mux11_r2g3 = PARAMSET_ROIC_3_R1_CR_RG_MUX11_r1_cr_mux11_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux11_r1g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX11_r1_cr_mux11_r1g1, \
   .tBit.r1_cr_mux11_r1g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX11_r1_cr_mux11_r1g2, \
   .tBit.r1_cr_mux11_r1g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX11_r1_cr_mux11_r1g3, \
   .tBit.r1_cr_mux11_r2g1 = PARAMSET_ROIC_4_R1_CR_RG_MUX11_r1_cr_mux11_r2g1, \
   .tBit.r1_cr_mux11_r2g2 = PARAMSET_ROIC_4_R1_CR_RG_MUX11_r1_cr_mux11_r2g2, \
   .tBit.r1_cr_mux11_r2g3 = PARAMSET_ROIC_4_R1_CR_RG_MUX11_r1_cr_mux11_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux11_r1g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX11_r1_cr_mux11_r1g1, \
   .tBit.r1_cr_mux11_r1g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX11_r1_cr_mux11_r1g2, \
   .tBit.r1_cr_mux11_r1g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX11_r1_cr_mux11_r1g3, \
   .tBit.r1_cr_mux11_r2g1 = PARAMSET_ROIC_5_R1_CR_RG_MUX11_r1_cr_mux11_r2g1, \
   .tBit.r1_cr_mux11_r2g2 = PARAMSET_ROIC_5_R1_CR_RG_MUX11_r1_cr_mux11_r2g2, \
   .tBit.r1_cr_mux11_r2g3 = PARAMSET_ROIC_5_R1_CR_RG_MUX11_r1_cr_mux11_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux11_r1g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX11_r1_cr_mux11_r1g1, \
   .tBit.r1_cr_mux11_r1g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX11_r1_cr_mux11_r1g2, \
   .tBit.r1_cr_mux11_r1g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX11_r1_cr_mux11_r1g3, \
   .tBit.r1_cr_mux11_r2g1 = PARAMSET_ROIC_6_R1_CR_RG_MUX11_r1_cr_mux11_r2g1, \
   .tBit.r1_cr_mux11_r2g2 = PARAMSET_ROIC_6_R1_CR_RG_MUX11_r1_cr_mux11_r2g2, \
   .tBit.r1_cr_mux11_r2g3 = PARAMSET_ROIC_6_R1_CR_RG_MUX11_r1_cr_mux11_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux11_r1g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX11_r1_cr_mux11_r1g1, \
   .tBit.r1_cr_mux11_r1g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX11_r1_cr_mux11_r1g2, \
   .tBit.r1_cr_mux11_r1g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX11_r1_cr_mux11_r1g3, \
   .tBit.r1_cr_mux11_r2g1 = PARAMSET_ROIC_7_R1_CR_RG_MUX11_r1_cr_mux11_r2g1, \
   .tBit.r1_cr_mux11_r2g2 = PARAMSET_ROIC_7_R1_CR_RG_MUX11_r1_cr_mux11_r2g2, \
   .tBit.r1_cr_mux11_r2g3 = PARAMSET_ROIC_7_R1_CR_RG_MUX11_r1_cr_mux11_r2g3, \
  } ,\
 } ,\
 .R1_CR_R1G_MUXE = \
 { \
  [0] = { \
   .tBit.r1_cr_muxe_r1g1 = PARAMSET_ROIC_0_R1_CR_R1G_MUXE_r1_cr_muxe_r1g1, \
   .tBit.r1_cr_muxe_r1g2 = PARAMSET_ROIC_0_R1_CR_R1G_MUXE_r1_cr_muxe_r1g2, \
   .tBit.r1_cr_muxe_r1g3 = PARAMSET_ROIC_0_R1_CR_R1G_MUXE_r1_cr_muxe_r1g3, \
   .tBit.r1_cr_muxe_r2g1 = PARAMSET_ROIC_0_R1_CR_R1G_MUXE_r1_cr_muxe_r2g1, \
   .tBit.r1_cr_muxe_r2g2 = PARAMSET_ROIC_0_R1_CR_R1G_MUXE_r1_cr_muxe_r2g2, \
   .tBit.r1_cr_muxe_r2g3 = PARAMSET_ROIC_0_R1_CR_R1G_MUXE_r1_cr_muxe_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_muxe_r1g1 = PARAMSET_ROIC_1_R1_CR_R1G_MUXE_r1_cr_muxe_r1g1, \
   .tBit.r1_cr_muxe_r1g2 = PARAMSET_ROIC_1_R1_CR_R1G_MUXE_r1_cr_muxe_r1g2, \
   .tBit.r1_cr_muxe_r1g3 = PARAMSET_ROIC_1_R1_CR_R1G_MUXE_r1_cr_muxe_r1g3, \
   .tBit.r1_cr_muxe_r2g1 = PARAMSET_ROIC_1_R1_CR_R1G_MUXE_r1_cr_muxe_r2g1, \
   .tBit.r1_cr_muxe_r2g2 = PARAMSET_ROIC_1_R1_CR_R1G_MUXE_r1_cr_muxe_r2g2, \
   .tBit.r1_cr_muxe_r2g3 = PARAMSET_ROIC_1_R1_CR_R1G_MUXE_r1_cr_muxe_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_muxe_r1g1 = PARAMSET_ROIC_2_R1_CR_R1G_MUXE_r1_cr_muxe_r1g1, \
   .tBit.r1_cr_muxe_r1g2 = PARAMSET_ROIC_2_R1_CR_R1G_MUXE_r1_cr_muxe_r1g2, \
   .tBit.r1_cr_muxe_r1g3 = PARAMSET_ROIC_2_R1_CR_R1G_MUXE_r1_cr_muxe_r1g3, \
   .tBit.r1_cr_muxe_r2g1 = PARAMSET_ROIC_2_R1_CR_R1G_MUXE_r1_cr_muxe_r2g1, \
   .tBit.r1_cr_muxe_r2g2 = PARAMSET_ROIC_2_R1_CR_R1G_MUXE_r1_cr_muxe_r2g2, \
   .tBit.r1_cr_muxe_r2g3 = PARAMSET_ROIC_2_R1_CR_R1G_MUXE_r1_cr_muxe_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_muxe_r1g1 = PARAMSET_ROIC_3_R1_CR_R1G_MUXE_r1_cr_muxe_r1g1, \
   .tBit.r1_cr_muxe_r1g2 = PARAMSET_ROIC_3_R1_CR_R1G_MUXE_r1_cr_muxe_r1g2, \
   .tBit.r1_cr_muxe_r1g3 = PARAMSET_ROIC_3_R1_CR_R1G_MUXE_r1_cr_muxe_r1g3, \
   .tBit.r1_cr_muxe_r2g1 = PARAMSET_ROIC_3_R1_CR_R1G_MUXE_r1_cr_muxe_r2g1, \
   .tBit.r1_cr_muxe_r2g2 = PARAMSET_ROIC_3_R1_CR_R1G_MUXE_r1_cr_muxe_r2g2, \
   .tBit.r1_cr_muxe_r2g3 = PARAMSET_ROIC_3_R1_CR_R1G_MUXE_r1_cr_muxe_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_muxe_r1g1 = PARAMSET_ROIC_4_R1_CR_R1G_MUXE_r1_cr_muxe_r1g1, \
   .tBit.r1_cr_muxe_r1g2 = PARAMSET_ROIC_4_R1_CR_R1G_MUXE_r1_cr_muxe_r1g2, \
   .tBit.r1_cr_muxe_r1g3 = PARAMSET_ROIC_4_R1_CR_R1G_MUXE_r1_cr_muxe_r1g3, \
   .tBit.r1_cr_muxe_r2g1 = PARAMSET_ROIC_4_R1_CR_R1G_MUXE_r1_cr_muxe_r2g1, \
   .tBit.r1_cr_muxe_r2g2 = PARAMSET_ROIC_4_R1_CR_R1G_MUXE_r1_cr_muxe_r2g2, \
   .tBit.r1_cr_muxe_r2g3 = PARAMSET_ROIC_4_R1_CR_R1G_MUXE_r1_cr_muxe_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_muxe_r1g1 = PARAMSET_ROIC_5_R1_CR_R1G_MUXE_r1_cr_muxe_r1g1, \
   .tBit.r1_cr_muxe_r1g2 = PARAMSET_ROIC_5_R1_CR_R1G_MUXE_r1_cr_muxe_r1g2, \
   .tBit.r1_cr_muxe_r1g3 = PARAMSET_ROIC_5_R1_CR_R1G_MUXE_r1_cr_muxe_r1g3, \
   .tBit.r1_cr_muxe_r2g1 = PARAMSET_ROIC_5_R1_CR_R1G_MUXE_r1_cr_muxe_r2g1, \
   .tBit.r1_cr_muxe_r2g2 = PARAMSET_ROIC_5_R1_CR_R1G_MUXE_r1_cr_muxe_r2g2, \
   .tBit.r1_cr_muxe_r2g3 = PARAMSET_ROIC_5_R1_CR_R1G_MUXE_r1_cr_muxe_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_muxe_r1g1 = PARAMSET_ROIC_6_R1_CR_R1G_MUXE_r1_cr_muxe_r1g1, \
   .tBit.r1_cr_muxe_r1g2 = PARAMSET_ROIC_6_R1_CR_R1G_MUXE_r1_cr_muxe_r1g2, \
   .tBit.r1_cr_muxe_r1g3 = PARAMSET_ROIC_6_R1_CR_R1G_MUXE_r1_cr_muxe_r1g3, \
   .tBit.r1_cr_muxe_r2g1 = PARAMSET_ROIC_6_R1_CR_R1G_MUXE_r1_cr_muxe_r2g1, \
   .tBit.r1_cr_muxe_r2g2 = PARAMSET_ROIC_6_R1_CR_R1G_MUXE_r1_cr_muxe_r2g2, \
   .tBit.r1_cr_muxe_r2g3 = PARAMSET_ROIC_6_R1_CR_R1G_MUXE_r1_cr_muxe_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_muxe_r1g1 = PARAMSET_ROIC_7_R1_CR_R1G_MUXE_r1_cr_muxe_r1g1, \
   .tBit.r1_cr_muxe_r1g2 = PARAMSET_ROIC_7_R1_CR_R1G_MUXE_r1_cr_muxe_r1g2, \
   .tBit.r1_cr_muxe_r1g3 = PARAMSET_ROIC_7_R1_CR_R1G_MUXE_r1_cr_muxe_r1g3, \
   .tBit.r1_cr_muxe_r2g1 = PARAMSET_ROIC_7_R1_CR_R1G_MUXE_r1_cr_muxe_r2g1, \
   .tBit.r1_cr_muxe_r2g2 = PARAMSET_ROIC_7_R1_CR_R1G_MUXE_r1_cr_muxe_r2g2, \
   .tBit.r1_cr_muxe_r2g3 = PARAMSET_ROIC_7_R1_CR_R1G_MUXE_r1_cr_muxe_r2g3, \
  } ,\
 } ,\
 .R1_CR_R1G_MUXO = \
 { \
  [0] = { \
   .tBit.r1_cr_muxo_r1g1 = PARAMSET_ROIC_0_R1_CR_R1G_MUXO_r1_cr_muxo_r1g1, \
   .tBit.r1_cr_muxo_r1g2 = PARAMSET_ROIC_0_R1_CR_R1G_MUXO_r1_cr_muxo_r1g2, \
   .tBit.r1_cr_muxo_r1g3 = PARAMSET_ROIC_0_R1_CR_R1G_MUXO_r1_cr_muxo_r1g3, \
   .tBit.r1_cr_muxo_r2g1 = PARAMSET_ROIC_0_R1_CR_R1G_MUXO_r1_cr_muxo_r2g1, \
   .tBit.r1_cr_muxo_r2g2 = PARAMSET_ROIC_0_R1_CR_R1G_MUXO_r1_cr_muxo_r2g2, \
   .tBit.r1_cr_muxo_r2g3 = PARAMSET_ROIC_0_R1_CR_R1G_MUXO_r1_cr_muxo_r2g3, \
  } ,\
  [1] = { \
   .tBit.r1_cr_muxo_r1g1 = PARAMSET_ROIC_1_R1_CR_R1G_MUXO_r1_cr_muxo_r1g1, \
   .tBit.r1_cr_muxo_r1g2 = PARAMSET_ROIC_1_R1_CR_R1G_MUXO_r1_cr_muxo_r1g2, \
   .tBit.r1_cr_muxo_r1g3 = PARAMSET_ROIC_1_R1_CR_R1G_MUXO_r1_cr_muxo_r1g3, \
   .tBit.r1_cr_muxo_r2g1 = PARAMSET_ROIC_1_R1_CR_R1G_MUXO_r1_cr_muxo_r2g1, \
   .tBit.r1_cr_muxo_r2g2 = PARAMSET_ROIC_1_R1_CR_R1G_MUXO_r1_cr_muxo_r2g2, \
   .tBit.r1_cr_muxo_r2g3 = PARAMSET_ROIC_1_R1_CR_R1G_MUXO_r1_cr_muxo_r2g3, \
  } ,\
  [2] = { \
   .tBit.r1_cr_muxo_r1g1 = PARAMSET_ROIC_2_R1_CR_R1G_MUXO_r1_cr_muxo_r1g1, \
   .tBit.r1_cr_muxo_r1g2 = PARAMSET_ROIC_2_R1_CR_R1G_MUXO_r1_cr_muxo_r1g2, \
   .tBit.r1_cr_muxo_r1g3 = PARAMSET_ROIC_2_R1_CR_R1G_MUXO_r1_cr_muxo_r1g3, \
   .tBit.r1_cr_muxo_r2g1 = PARAMSET_ROIC_2_R1_CR_R1G_MUXO_r1_cr_muxo_r2g1, \
   .tBit.r1_cr_muxo_r2g2 = PARAMSET_ROIC_2_R1_CR_R1G_MUXO_r1_cr_muxo_r2g2, \
   .tBit.r1_cr_muxo_r2g3 = PARAMSET_ROIC_2_R1_CR_R1G_MUXO_r1_cr_muxo_r2g3, \
  } ,\
  [3] = { \
   .tBit.r1_cr_muxo_r1g1 = PARAMSET_ROIC_3_R1_CR_R1G_MUXO_r1_cr_muxo_r1g1, \
   .tBit.r1_cr_muxo_r1g2 = PARAMSET_ROIC_3_R1_CR_R1G_MUXO_r1_cr_muxo_r1g2, \
   .tBit.r1_cr_muxo_r1g3 = PARAMSET_ROIC_3_R1_CR_R1G_MUXO_r1_cr_muxo_r1g3, \
   .tBit.r1_cr_muxo_r2g1 = PARAMSET_ROIC_3_R1_CR_R1G_MUXO_r1_cr_muxo_r2g1, \
   .tBit.r1_cr_muxo_r2g2 = PARAMSET_ROIC_3_R1_CR_R1G_MUXO_r1_cr_muxo_r2g2, \
   .tBit.r1_cr_muxo_r2g3 = PARAMSET_ROIC_3_R1_CR_R1G_MUXO_r1_cr_muxo_r2g3, \
  } ,\
  [4] = { \
   .tBit.r1_cr_muxo_r1g1 = PARAMSET_ROIC_4_R1_CR_R1G_MUXO_r1_cr_muxo_r1g1, \
   .tBit.r1_cr_muxo_r1g2 = PARAMSET_ROIC_4_R1_CR_R1G_MUXO_r1_cr_muxo_r1g2, \
   .tBit.r1_cr_muxo_r1g3 = PARAMSET_ROIC_4_R1_CR_R1G_MUXO_r1_cr_muxo_r1g3, \
   .tBit.r1_cr_muxo_r2g1 = PARAMSET_ROIC_4_R1_CR_R1G_MUXO_r1_cr_muxo_r2g1, \
   .tBit.r1_cr_muxo_r2g2 = PARAMSET_ROIC_4_R1_CR_R1G_MUXO_r1_cr_muxo_r2g2, \
   .tBit.r1_cr_muxo_r2g3 = PARAMSET_ROIC_4_R1_CR_R1G_MUXO_r1_cr_muxo_r2g3, \
  } ,\
  [5] = { \
   .tBit.r1_cr_muxo_r1g1 = PARAMSET_ROIC_5_R1_CR_R1G_MUXO_r1_cr_muxo_r1g1, \
   .tBit.r1_cr_muxo_r1g2 = PARAMSET_ROIC_5_R1_CR_R1G_MUXO_r1_cr_muxo_r1g2, \
   .tBit.r1_cr_muxo_r1g3 = PARAMSET_ROIC_5_R1_CR_R1G_MUXO_r1_cr_muxo_r1g3, \
   .tBit.r1_cr_muxo_r2g1 = PARAMSET_ROIC_5_R1_CR_R1G_MUXO_r1_cr_muxo_r2g1, \
   .tBit.r1_cr_muxo_r2g2 = PARAMSET_ROIC_5_R1_CR_R1G_MUXO_r1_cr_muxo_r2g2, \
   .tBit.r1_cr_muxo_r2g3 = PARAMSET_ROIC_5_R1_CR_R1G_MUXO_r1_cr_muxo_r2g3, \
  } ,\
  [6] = { \
   .tBit.r1_cr_muxo_r1g1 = PARAMSET_ROIC_6_R1_CR_R1G_MUXO_r1_cr_muxo_r1g1, \
   .tBit.r1_cr_muxo_r1g2 = PARAMSET_ROIC_6_R1_CR_R1G_MUXO_r1_cr_muxo_r1g2, \
   .tBit.r1_cr_muxo_r1g3 = PARAMSET_ROIC_6_R1_CR_R1G_MUXO_r1_cr_muxo_r1g3, \
   .tBit.r1_cr_muxo_r2g1 = PARAMSET_ROIC_6_R1_CR_R1G_MUXO_r1_cr_muxo_r2g1, \
   .tBit.r1_cr_muxo_r2g2 = PARAMSET_ROIC_6_R1_CR_R1G_MUXO_r1_cr_muxo_r2g2, \
   .tBit.r1_cr_muxo_r2g3 = PARAMSET_ROIC_6_R1_CR_R1G_MUXO_r1_cr_muxo_r2g3, \
  } ,\
  [7] = { \
   .tBit.r1_cr_muxo_r1g1 = PARAMSET_ROIC_7_R1_CR_R1G_MUXO_r1_cr_muxo_r1g1, \
   .tBit.r1_cr_muxo_r1g2 = PARAMSET_ROIC_7_R1_CR_R1G_MUXO_r1_cr_muxo_r1g2, \
   .tBit.r1_cr_muxo_r1g3 = PARAMSET_ROIC_7_R1_CR_R1G_MUXO_r1_cr_muxo_r1g3, \
   .tBit.r1_cr_muxo_r2g1 = PARAMSET_ROIC_7_R1_CR_R1G_MUXO_r1_cr_muxo_r2g1, \
   .tBit.r1_cr_muxo_r2g2 = PARAMSET_ROIC_7_R1_CR_R1G_MUXO_r1_cr_muxo_r2g2, \
   .tBit.r1_cr_muxo_r2g3 = PARAMSET_ROIC_7_R1_CR_R1G_MUXO_r1_cr_muxo_r2g3, \
  } ,\
 } ,\
 .R1_CR_GTUNE1 = \
 { \
  [0] = { \
   .tBit.r1_mux1_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE1_r1_mux1_gtune, \
   .tBit.r1_mux2_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE1_r1_mux2_gtune, \
   .tBit.r1_mux3_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE1_r1_mux3_gtune, \
   .tBit.r1_mux4_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE1_r1_mux4_gtune, \
   .tBit.r1_mux5_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE1_r1_mux5_gtune, \
   .tBit.r1_mux6_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE1_r1_mux6_gtune, \
   .tBit.r1_mux7_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE1_r1_mux7_gtune, \
   .tBit.r1_mux8_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE1_r1_mux8_gtune, \
   .tBit.r1_mux9_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE1_r1_mux9_gtune, \
   .tBit.r1_mux10_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE1_r1_mux10_gtune, \
  } ,\
  [1] = { \
   .tBit.r1_mux1_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE1_r1_mux1_gtune, \
   .tBit.r1_mux2_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE1_r1_mux2_gtune, \
   .tBit.r1_mux3_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE1_r1_mux3_gtune, \
   .tBit.r1_mux4_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE1_r1_mux4_gtune, \
   .tBit.r1_mux5_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE1_r1_mux5_gtune, \
   .tBit.r1_mux6_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE1_r1_mux6_gtune, \
   .tBit.r1_mux7_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE1_r1_mux7_gtune, \
   .tBit.r1_mux8_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE1_r1_mux8_gtune, \
   .tBit.r1_mux9_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE1_r1_mux9_gtune, \
   .tBit.r1_mux10_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE1_r1_mux10_gtune, \
  } ,\
  [2] = { \
   .tBit.r1_mux1_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE1_r1_mux1_gtune, \
   .tBit.r1_mux2_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE1_r1_mux2_gtune, \
   .tBit.r1_mux3_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE1_r1_mux3_gtune, \
   .tBit.r1_mux4_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE1_r1_mux4_gtune, \
   .tBit.r1_mux5_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE1_r1_mux5_gtune, \
   .tBit.r1_mux6_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE1_r1_mux6_gtune, \
   .tBit.r1_mux7_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE1_r1_mux7_gtune, \
   .tBit.r1_mux8_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE1_r1_mux8_gtune, \
   .tBit.r1_mux9_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE1_r1_mux9_gtune, \
   .tBit.r1_mux10_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE1_r1_mux10_gtune, \
  } ,\
  [3] = { \
   .tBit.r1_mux1_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE1_r1_mux1_gtune, \
   .tBit.r1_mux2_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE1_r1_mux2_gtune, \
   .tBit.r1_mux3_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE1_r1_mux3_gtune, \
   .tBit.r1_mux4_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE1_r1_mux4_gtune, \
   .tBit.r1_mux5_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE1_r1_mux5_gtune, \
   .tBit.r1_mux6_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE1_r1_mux6_gtune, \
   .tBit.r1_mux7_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE1_r1_mux7_gtune, \
   .tBit.r1_mux8_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE1_r1_mux8_gtune, \
   .tBit.r1_mux9_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE1_r1_mux9_gtune, \
   .tBit.r1_mux10_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE1_r1_mux10_gtune, \
  } ,\
  [4] = { \
   .tBit.r1_mux1_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE1_r1_mux1_gtune, \
   .tBit.r1_mux2_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE1_r1_mux2_gtune, \
   .tBit.r1_mux3_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE1_r1_mux3_gtune, \
   .tBit.r1_mux4_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE1_r1_mux4_gtune, \
   .tBit.r1_mux5_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE1_r1_mux5_gtune, \
   .tBit.r1_mux6_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE1_r1_mux6_gtune, \
   .tBit.r1_mux7_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE1_r1_mux7_gtune, \
   .tBit.r1_mux8_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE1_r1_mux8_gtune, \
   .tBit.r1_mux9_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE1_r1_mux9_gtune, \
   .tBit.r1_mux10_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE1_r1_mux10_gtune, \
  } ,\
  [5] = { \
   .tBit.r1_mux1_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE1_r1_mux1_gtune, \
   .tBit.r1_mux2_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE1_r1_mux2_gtune, \
   .tBit.r1_mux3_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE1_r1_mux3_gtune, \
   .tBit.r1_mux4_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE1_r1_mux4_gtune, \
   .tBit.r1_mux5_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE1_r1_mux5_gtune, \
   .tBit.r1_mux6_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE1_r1_mux6_gtune, \
   .tBit.r1_mux7_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE1_r1_mux7_gtune, \
   .tBit.r1_mux8_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE1_r1_mux8_gtune, \
   .tBit.r1_mux9_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE1_r1_mux9_gtune, \
   .tBit.r1_mux10_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE1_r1_mux10_gtune, \
  } ,\
  [6] = { \
   .tBit.r1_mux1_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE1_r1_mux1_gtune, \
   .tBit.r1_mux2_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE1_r1_mux2_gtune, \
   .tBit.r1_mux3_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE1_r1_mux3_gtune, \
   .tBit.r1_mux4_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE1_r1_mux4_gtune, \
   .tBit.r1_mux5_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE1_r1_mux5_gtune, \
   .tBit.r1_mux6_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE1_r1_mux6_gtune, \
   .tBit.r1_mux7_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE1_r1_mux7_gtune, \
   .tBit.r1_mux8_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE1_r1_mux8_gtune, \
   .tBit.r1_mux9_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE1_r1_mux9_gtune, \
   .tBit.r1_mux10_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE1_r1_mux10_gtune, \
  } ,\
  [7] = { \
   .tBit.r1_mux1_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE1_r1_mux1_gtune, \
   .tBit.r1_mux2_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE1_r1_mux2_gtune, \
   .tBit.r1_mux3_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE1_r1_mux3_gtune, \
   .tBit.r1_mux4_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE1_r1_mux4_gtune, \
   .tBit.r1_mux5_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE1_r1_mux5_gtune, \
   .tBit.r1_mux6_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE1_r1_mux6_gtune, \
   .tBit.r1_mux7_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE1_r1_mux7_gtune, \
   .tBit.r1_mux8_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE1_r1_mux8_gtune, \
   .tBit.r1_mux9_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE1_r1_mux9_gtune, \
   .tBit.r1_mux10_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE1_r1_mux10_gtune, \
  } ,\
 } ,\
 .R1_CR_GTUNE2 = \
 { \
  [0] = { \
   .tBit.r1_mux11_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE2_r1_mux11_gtune, \
   .tBit.r1_muxeo_gtune = PARAMSET_ROIC_0_R1_CR_GTUNE2_r1_muxeo_gtune, \
  } ,\
  [1] = { \
   .tBit.r1_mux11_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE2_r1_mux11_gtune, \
   .tBit.r1_muxeo_gtune = PARAMSET_ROIC_1_R1_CR_GTUNE2_r1_muxeo_gtune, \
  } ,\
  [2] = { \
   .tBit.r1_mux11_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE2_r1_mux11_gtune, \
   .tBit.r1_muxeo_gtune = PARAMSET_ROIC_2_R1_CR_GTUNE2_r1_muxeo_gtune, \
  } ,\
  [3] = { \
   .tBit.r1_mux11_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE2_r1_mux11_gtune, \
   .tBit.r1_muxeo_gtune = PARAMSET_ROIC_3_R1_CR_GTUNE2_r1_muxeo_gtune, \
  } ,\
  [4] = { \
   .tBit.r1_mux11_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE2_r1_mux11_gtune, \
   .tBit.r1_muxeo_gtune = PARAMSET_ROIC_4_R1_CR_GTUNE2_r1_muxeo_gtune, \
  } ,\
  [5] = { \
   .tBit.r1_mux11_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE2_r1_mux11_gtune, \
   .tBit.r1_muxeo_gtune = PARAMSET_ROIC_5_R1_CR_GTUNE2_r1_muxeo_gtune, \
  } ,\
  [6] = { \
   .tBit.r1_mux11_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE2_r1_mux11_gtune, \
   .tBit.r1_muxeo_gtune = PARAMSET_ROIC_6_R1_CR_GTUNE2_r1_muxeo_gtune, \
  } ,\
  [7] = { \
   .tBit.r1_mux11_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE2_r1_mux11_gtune, \
   .tBit.r1_muxeo_gtune = PARAMSET_ROIC_7_R1_CR_GTUNE2_r1_muxeo_gtune, \
  } ,\
 } ,\
 .R1_TUNE_GROUP_SEL1 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux1_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row2_gsel, \
   .tBit.r1_cr_mux1_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row3_gsel, \
   .tBit.r1_cr_mux1_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row4_gsel, \
   .tBit.r1_cr_mux2_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row2_gsel, \
   .tBit.r1_cr_mux2_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row3_gsel, \
   .tBit.r1_cr_mux2_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row4_gsel, \
   .tBit.r1_cr_mux3_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row2_gsel, \
   .tBit.r1_cr_mux3_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row3_gsel, \
   .tBit.r1_cr_mux3_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row4_gsel, \
   .tBit.r1_cr_mux4_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row2_gsel, \
   .tBit.r1_cr_mux4_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row3_gsel, \
   .tBit.r1_cr_mux4_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row4_gsel, \
   .tBit.r1_cr_mux5_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row2_gsel, \
   .tBit.r1_cr_mux5_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row3_gsel, \
   .tBit.r1_cr_mux5_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row4_gsel, \
   .tBit.r1_cr_mux6_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row2_gsel, \
   .tBit.r1_cr_mux6_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row3_gsel, \
   .tBit.r1_cr_mux6_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row4_gsel, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux1_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row2_gsel, \
   .tBit.r1_cr_mux1_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row3_gsel, \
   .tBit.r1_cr_mux1_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row4_gsel, \
   .tBit.r1_cr_mux2_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row2_gsel, \
   .tBit.r1_cr_mux2_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row3_gsel, \
   .tBit.r1_cr_mux2_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row4_gsel, \
   .tBit.r1_cr_mux3_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row2_gsel, \
   .tBit.r1_cr_mux3_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row3_gsel, \
   .tBit.r1_cr_mux3_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row4_gsel, \
   .tBit.r1_cr_mux4_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row2_gsel, \
   .tBit.r1_cr_mux4_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row3_gsel, \
   .tBit.r1_cr_mux4_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row4_gsel, \
   .tBit.r1_cr_mux5_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row2_gsel, \
   .tBit.r1_cr_mux5_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row3_gsel, \
   .tBit.r1_cr_mux5_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row4_gsel, \
   .tBit.r1_cr_mux6_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row2_gsel, \
   .tBit.r1_cr_mux6_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row3_gsel, \
   .tBit.r1_cr_mux6_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row4_gsel, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux1_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row2_gsel, \
   .tBit.r1_cr_mux1_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row3_gsel, \
   .tBit.r1_cr_mux1_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row4_gsel, \
   .tBit.r1_cr_mux2_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row2_gsel, \
   .tBit.r1_cr_mux2_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row3_gsel, \
   .tBit.r1_cr_mux2_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row4_gsel, \
   .tBit.r1_cr_mux3_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row2_gsel, \
   .tBit.r1_cr_mux3_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row3_gsel, \
   .tBit.r1_cr_mux3_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row4_gsel, \
   .tBit.r1_cr_mux4_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row2_gsel, \
   .tBit.r1_cr_mux4_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row3_gsel, \
   .tBit.r1_cr_mux4_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row4_gsel, \
   .tBit.r1_cr_mux5_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row2_gsel, \
   .tBit.r1_cr_mux5_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row3_gsel, \
   .tBit.r1_cr_mux5_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row4_gsel, \
   .tBit.r1_cr_mux6_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row2_gsel, \
   .tBit.r1_cr_mux6_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row3_gsel, \
   .tBit.r1_cr_mux6_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row4_gsel, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux1_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row2_gsel, \
   .tBit.r1_cr_mux1_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row3_gsel, \
   .tBit.r1_cr_mux1_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row4_gsel, \
   .tBit.r1_cr_mux2_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row2_gsel, \
   .tBit.r1_cr_mux2_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row3_gsel, \
   .tBit.r1_cr_mux2_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row4_gsel, \
   .tBit.r1_cr_mux3_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row2_gsel, \
   .tBit.r1_cr_mux3_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row3_gsel, \
   .tBit.r1_cr_mux3_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row4_gsel, \
   .tBit.r1_cr_mux4_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row2_gsel, \
   .tBit.r1_cr_mux4_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row3_gsel, \
   .tBit.r1_cr_mux4_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row4_gsel, \
   .tBit.r1_cr_mux5_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row2_gsel, \
   .tBit.r1_cr_mux5_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row3_gsel, \
   .tBit.r1_cr_mux5_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row4_gsel, \
   .tBit.r1_cr_mux6_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row2_gsel, \
   .tBit.r1_cr_mux6_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row3_gsel, \
   .tBit.r1_cr_mux6_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row4_gsel, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux1_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row2_gsel, \
   .tBit.r1_cr_mux1_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row3_gsel, \
   .tBit.r1_cr_mux1_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row4_gsel, \
   .tBit.r1_cr_mux2_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row2_gsel, \
   .tBit.r1_cr_mux2_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row3_gsel, \
   .tBit.r1_cr_mux2_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row4_gsel, \
   .tBit.r1_cr_mux3_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row2_gsel, \
   .tBit.r1_cr_mux3_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row3_gsel, \
   .tBit.r1_cr_mux3_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row4_gsel, \
   .tBit.r1_cr_mux4_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row2_gsel, \
   .tBit.r1_cr_mux4_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row3_gsel, \
   .tBit.r1_cr_mux4_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row4_gsel, \
   .tBit.r1_cr_mux5_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row2_gsel, \
   .tBit.r1_cr_mux5_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row3_gsel, \
   .tBit.r1_cr_mux5_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row4_gsel, \
   .tBit.r1_cr_mux6_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row2_gsel, \
   .tBit.r1_cr_mux6_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row3_gsel, \
   .tBit.r1_cr_mux6_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row4_gsel, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux1_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row2_gsel, \
   .tBit.r1_cr_mux1_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row3_gsel, \
   .tBit.r1_cr_mux1_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row4_gsel, \
   .tBit.r1_cr_mux2_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row2_gsel, \
   .tBit.r1_cr_mux2_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row3_gsel, \
   .tBit.r1_cr_mux2_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row4_gsel, \
   .tBit.r1_cr_mux3_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row2_gsel, \
   .tBit.r1_cr_mux3_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row3_gsel, \
   .tBit.r1_cr_mux3_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row4_gsel, \
   .tBit.r1_cr_mux4_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row2_gsel, \
   .tBit.r1_cr_mux4_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row3_gsel, \
   .tBit.r1_cr_mux4_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row4_gsel, \
   .tBit.r1_cr_mux5_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row2_gsel, \
   .tBit.r1_cr_mux5_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row3_gsel, \
   .tBit.r1_cr_mux5_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row4_gsel, \
   .tBit.r1_cr_mux6_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row2_gsel, \
   .tBit.r1_cr_mux6_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row3_gsel, \
   .tBit.r1_cr_mux6_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row4_gsel, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux1_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row2_gsel, \
   .tBit.r1_cr_mux1_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row3_gsel, \
   .tBit.r1_cr_mux1_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row4_gsel, \
   .tBit.r1_cr_mux2_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row2_gsel, \
   .tBit.r1_cr_mux2_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row3_gsel, \
   .tBit.r1_cr_mux2_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row4_gsel, \
   .tBit.r1_cr_mux3_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row2_gsel, \
   .tBit.r1_cr_mux3_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row3_gsel, \
   .tBit.r1_cr_mux3_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row4_gsel, \
   .tBit.r1_cr_mux4_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row2_gsel, \
   .tBit.r1_cr_mux4_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row3_gsel, \
   .tBit.r1_cr_mux4_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row4_gsel, \
   .tBit.r1_cr_mux5_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row2_gsel, \
   .tBit.r1_cr_mux5_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row3_gsel, \
   .tBit.r1_cr_mux5_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row4_gsel, \
   .tBit.r1_cr_mux6_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row2_gsel, \
   .tBit.r1_cr_mux6_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row3_gsel, \
   .tBit.r1_cr_mux6_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row4_gsel, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux1_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row2_gsel, \
   .tBit.r1_cr_mux1_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row3_gsel, \
   .tBit.r1_cr_mux1_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux1_row4_gsel, \
   .tBit.r1_cr_mux2_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row2_gsel, \
   .tBit.r1_cr_mux2_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row3_gsel, \
   .tBit.r1_cr_mux2_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux2_row4_gsel, \
   .tBit.r1_cr_mux3_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row2_gsel, \
   .tBit.r1_cr_mux3_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row3_gsel, \
   .tBit.r1_cr_mux3_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux3_row4_gsel, \
   .tBit.r1_cr_mux4_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row2_gsel, \
   .tBit.r1_cr_mux4_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row3_gsel, \
   .tBit.r1_cr_mux4_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux4_row4_gsel, \
   .tBit.r1_cr_mux5_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row2_gsel, \
   .tBit.r1_cr_mux5_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row3_gsel, \
   .tBit.r1_cr_mux5_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux5_row4_gsel, \
   .tBit.r1_cr_mux6_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row2_gsel, \
   .tBit.r1_cr_mux6_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row3_gsel, \
   .tBit.r1_cr_mux6_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL1_r1_cr_mux6_row4_gsel, \
  } ,\
 } ,\
 .R1_TUNE_GROUP_SEL2 = \
 { \
  [0] = { \
   .tBit.r1_cr_mux7_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row2_gsel, \
   .tBit.r1_cr_mux7_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row3_gsel, \
   .tBit.r1_cr_mux7_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row4_gsel, \
   .tBit.r1_cr_mux8_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row2_gsel, \
   .tBit.r1_cr_mux8_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row3_gsel, \
   .tBit.r1_cr_mux8_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row4_gsel, \
   .tBit.r1_cr_mux9_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row2_gsel, \
   .tBit.r1_cr_mux9_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row3_gsel, \
   .tBit.r1_cr_mux9_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row4_gsel, \
   .tBit.r1_cr_mux10_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row2_gsel, \
   .tBit.r1_cr_mux10_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row3_gsel, \
   .tBit.r1_cr_mux10_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row4_gsel, \
   .tBit.r1_cr_mux11_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row2_gsel, \
   .tBit.r1_cr_mux11_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row3_gsel, \
   .tBit.r1_cr_mux11_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row4_gsel, \
   .tBit.r1_cr_muxeo_row2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row2_gsel, \
   .tBit.r1_cr_muxeo_row3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row3_gsel, \
   .tBit.r1_cr_muxeo_row4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row4_gsel, \
  } ,\
  [1] = { \
   .tBit.r1_cr_mux7_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row2_gsel, \
   .tBit.r1_cr_mux7_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row3_gsel, \
   .tBit.r1_cr_mux7_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row4_gsel, \
   .tBit.r1_cr_mux8_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row2_gsel, \
   .tBit.r1_cr_mux8_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row3_gsel, \
   .tBit.r1_cr_mux8_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row4_gsel, \
   .tBit.r1_cr_mux9_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row2_gsel, \
   .tBit.r1_cr_mux9_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row3_gsel, \
   .tBit.r1_cr_mux9_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row4_gsel, \
   .tBit.r1_cr_mux10_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row2_gsel, \
   .tBit.r1_cr_mux10_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row3_gsel, \
   .tBit.r1_cr_mux10_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row4_gsel, \
   .tBit.r1_cr_mux11_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row2_gsel, \
   .tBit.r1_cr_mux11_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row3_gsel, \
   .tBit.r1_cr_mux11_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row4_gsel, \
   .tBit.r1_cr_muxeo_row2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row2_gsel, \
   .tBit.r1_cr_muxeo_row3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row3_gsel, \
   .tBit.r1_cr_muxeo_row4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row4_gsel, \
  } ,\
  [2] = { \
   .tBit.r1_cr_mux7_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row2_gsel, \
   .tBit.r1_cr_mux7_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row3_gsel, \
   .tBit.r1_cr_mux7_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row4_gsel, \
   .tBit.r1_cr_mux8_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row2_gsel, \
   .tBit.r1_cr_mux8_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row3_gsel, \
   .tBit.r1_cr_mux8_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row4_gsel, \
   .tBit.r1_cr_mux9_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row2_gsel, \
   .tBit.r1_cr_mux9_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row3_gsel, \
   .tBit.r1_cr_mux9_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row4_gsel, \
   .tBit.r1_cr_mux10_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row2_gsel, \
   .tBit.r1_cr_mux10_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row3_gsel, \
   .tBit.r1_cr_mux10_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row4_gsel, \
   .tBit.r1_cr_mux11_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row2_gsel, \
   .tBit.r1_cr_mux11_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row3_gsel, \
   .tBit.r1_cr_mux11_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row4_gsel, \
   .tBit.r1_cr_muxeo_row2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row2_gsel, \
   .tBit.r1_cr_muxeo_row3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row3_gsel, \
   .tBit.r1_cr_muxeo_row4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row4_gsel, \
  } ,\
  [3] = { \
   .tBit.r1_cr_mux7_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row2_gsel, \
   .tBit.r1_cr_mux7_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row3_gsel, \
   .tBit.r1_cr_mux7_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row4_gsel, \
   .tBit.r1_cr_mux8_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row2_gsel, \
   .tBit.r1_cr_mux8_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row3_gsel, \
   .tBit.r1_cr_mux8_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row4_gsel, \
   .tBit.r1_cr_mux9_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row2_gsel, \
   .tBit.r1_cr_mux9_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row3_gsel, \
   .tBit.r1_cr_mux9_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row4_gsel, \
   .tBit.r1_cr_mux10_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row2_gsel, \
   .tBit.r1_cr_mux10_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row3_gsel, \
   .tBit.r1_cr_mux10_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row4_gsel, \
   .tBit.r1_cr_mux11_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row2_gsel, \
   .tBit.r1_cr_mux11_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row3_gsel, \
   .tBit.r1_cr_mux11_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row4_gsel, \
   .tBit.r1_cr_muxeo_row2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row2_gsel, \
   .tBit.r1_cr_muxeo_row3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row3_gsel, \
   .tBit.r1_cr_muxeo_row4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row4_gsel, \
  } ,\
  [4] = { \
   .tBit.r1_cr_mux7_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row2_gsel, \
   .tBit.r1_cr_mux7_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row3_gsel, \
   .tBit.r1_cr_mux7_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row4_gsel, \
   .tBit.r1_cr_mux8_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row2_gsel, \
   .tBit.r1_cr_mux8_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row3_gsel, \
   .tBit.r1_cr_mux8_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row4_gsel, \
   .tBit.r1_cr_mux9_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row2_gsel, \
   .tBit.r1_cr_mux9_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row3_gsel, \
   .tBit.r1_cr_mux9_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row4_gsel, \
   .tBit.r1_cr_mux10_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row2_gsel, \
   .tBit.r1_cr_mux10_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row3_gsel, \
   .tBit.r1_cr_mux10_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row4_gsel, \
   .tBit.r1_cr_mux11_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row2_gsel, \
   .tBit.r1_cr_mux11_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row3_gsel, \
   .tBit.r1_cr_mux11_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row4_gsel, \
   .tBit.r1_cr_muxeo_row2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row2_gsel, \
   .tBit.r1_cr_muxeo_row3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row3_gsel, \
   .tBit.r1_cr_muxeo_row4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row4_gsel, \
  } ,\
  [5] = { \
   .tBit.r1_cr_mux7_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row2_gsel, \
   .tBit.r1_cr_mux7_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row3_gsel, \
   .tBit.r1_cr_mux7_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row4_gsel, \
   .tBit.r1_cr_mux8_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row2_gsel, \
   .tBit.r1_cr_mux8_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row3_gsel, \
   .tBit.r1_cr_mux8_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row4_gsel, \
   .tBit.r1_cr_mux9_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row2_gsel, \
   .tBit.r1_cr_mux9_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row3_gsel, \
   .tBit.r1_cr_mux9_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row4_gsel, \
   .tBit.r1_cr_mux10_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row2_gsel, \
   .tBit.r1_cr_mux10_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row3_gsel, \
   .tBit.r1_cr_mux10_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row4_gsel, \
   .tBit.r1_cr_mux11_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row2_gsel, \
   .tBit.r1_cr_mux11_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row3_gsel, \
   .tBit.r1_cr_mux11_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row4_gsel, \
   .tBit.r1_cr_muxeo_row2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row2_gsel, \
   .tBit.r1_cr_muxeo_row3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row3_gsel, \
   .tBit.r1_cr_muxeo_row4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row4_gsel, \
  } ,\
  [6] = { \
   .tBit.r1_cr_mux7_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row2_gsel, \
   .tBit.r1_cr_mux7_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row3_gsel, \
   .tBit.r1_cr_mux7_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row4_gsel, \
   .tBit.r1_cr_mux8_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row2_gsel, \
   .tBit.r1_cr_mux8_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row3_gsel, \
   .tBit.r1_cr_mux8_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row4_gsel, \
   .tBit.r1_cr_mux9_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row2_gsel, \
   .tBit.r1_cr_mux9_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row3_gsel, \
   .tBit.r1_cr_mux9_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row4_gsel, \
   .tBit.r1_cr_mux10_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row2_gsel, \
   .tBit.r1_cr_mux10_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row3_gsel, \
   .tBit.r1_cr_mux10_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row4_gsel, \
   .tBit.r1_cr_mux11_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row2_gsel, \
   .tBit.r1_cr_mux11_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row3_gsel, \
   .tBit.r1_cr_mux11_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row4_gsel, \
   .tBit.r1_cr_muxeo_row2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row2_gsel, \
   .tBit.r1_cr_muxeo_row3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row3_gsel, \
   .tBit.r1_cr_muxeo_row4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row4_gsel, \
  } ,\
  [7] = { \
   .tBit.r1_cr_mux7_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row2_gsel, \
   .tBit.r1_cr_mux7_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row3_gsel, \
   .tBit.r1_cr_mux7_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux7_row4_gsel, \
   .tBit.r1_cr_mux8_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row2_gsel, \
   .tBit.r1_cr_mux8_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row3_gsel, \
   .tBit.r1_cr_mux8_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux8_row4_gsel, \
   .tBit.r1_cr_mux9_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row2_gsel, \
   .tBit.r1_cr_mux9_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row3_gsel, \
   .tBit.r1_cr_mux9_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux9_row4_gsel, \
   .tBit.r1_cr_mux10_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row2_gsel, \
   .tBit.r1_cr_mux10_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row3_gsel, \
   .tBit.r1_cr_mux10_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux10_row4_gsel, \
   .tBit.r1_cr_mux11_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row2_gsel, \
   .tBit.r1_cr_mux11_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row3_gsel, \
   .tBit.r1_cr_mux11_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_mux11_row4_gsel, \
   .tBit.r1_cr_muxeo_row2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row2_gsel, \
   .tBit.r1_cr_muxeo_row3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row3_gsel, \
   .tBit.r1_cr_muxeo_row4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL2_r1_cr_muxeo_row4_gsel, \
  } ,\
 } ,\
 .R1_TUNE_GROUP_SEL3 = \
 { \
  [0] = { \
   .tBit.r1_cr_col2_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL3_r1_cr_col2_gsel, \
   .tBit.r1_cr_col3_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL3_r1_cr_col3_gsel, \
   .tBit.r1_cr_col4_gsel = PARAMSET_ROIC_0_R1_TUNE_GROUP_SEL3_r1_cr_col4_gsel, \
  } ,\
  [1] = { \
   .tBit.r1_cr_col2_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL3_r1_cr_col2_gsel, \
   .tBit.r1_cr_col3_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL3_r1_cr_col3_gsel, \
   .tBit.r1_cr_col4_gsel = PARAMSET_ROIC_1_R1_TUNE_GROUP_SEL3_r1_cr_col4_gsel, \
  } ,\
  [2] = { \
   .tBit.r1_cr_col2_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL3_r1_cr_col2_gsel, \
   .tBit.r1_cr_col3_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL3_r1_cr_col3_gsel, \
   .tBit.r1_cr_col4_gsel = PARAMSET_ROIC_2_R1_TUNE_GROUP_SEL3_r1_cr_col4_gsel, \
  } ,\
  [3] = { \
   .tBit.r1_cr_col2_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL3_r1_cr_col2_gsel, \
   .tBit.r1_cr_col3_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL3_r1_cr_col3_gsel, \
   .tBit.r1_cr_col4_gsel = PARAMSET_ROIC_3_R1_TUNE_GROUP_SEL3_r1_cr_col4_gsel, \
  } ,\
  [4] = { \
   .tBit.r1_cr_col2_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL3_r1_cr_col2_gsel, \
   .tBit.r1_cr_col3_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL3_r1_cr_col3_gsel, \
   .tBit.r1_cr_col4_gsel = PARAMSET_ROIC_4_R1_TUNE_GROUP_SEL3_r1_cr_col4_gsel, \
  } ,\
  [5] = { \
   .tBit.r1_cr_col2_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL3_r1_cr_col2_gsel, \
   .tBit.r1_cr_col3_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL3_r1_cr_col3_gsel, \
   .tBit.r1_cr_col4_gsel = PARAMSET_ROIC_5_R1_TUNE_GROUP_SEL3_r1_cr_col4_gsel, \
  } ,\
  [6] = { \
   .tBit.r1_cr_col2_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL3_r1_cr_col2_gsel, \
   .tBit.r1_cr_col3_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL3_r1_cr_col3_gsel, \
   .tBit.r1_cr_col4_gsel = PARAMSET_ROIC_6_R1_TUNE_GROUP_SEL3_r1_cr_col4_gsel, \
  } ,\
  [7] = { \
   .tBit.r1_cr_col2_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL3_r1_cr_col2_gsel, \
   .tBit.r1_cr_col3_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL3_r1_cr_col3_gsel, \
   .tBit.r1_cr_col4_gsel = PARAMSET_ROIC_7_R1_TUNE_GROUP_SEL3_r1_cr_col4_gsel, \
  } ,\
 } ,\
 .R1_ADC_IN_CTL = \
 { \
  .tBit.r1_adc_in = PARAMSET_ROIC_R1_ADC_IN_CTL_r1_adc_in, \
  .tBit.r1_adc_op_opt = PARAMSET_ROIC_R1_ADC_IN_CTL_r1_adc_op_opt, \
  .tBit.r1_adc_in_stuck_en = PARAMSET_ROIC_R1_ADC_IN_CTL_r1_adc_in_stuck_en, \
 } ,\
 .R1_AFE_SENSE_CTL = \
 { \
  .tBit.r1_adc_ref_sel = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_adc_ref_sel, \
  .tBit.r1_cvc1_comp = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_cvc1_comp, \
  .tBit.r1_int_ref = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_int_ref, \
  .tBit.r1_sha_ref = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_sha_ref, \
  .tBit.r1_cvc1_gc = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_cvc1_gc, \
  .tBit.r1_cvc2_gc = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_cvc2_gc, \
  .tBit.r1_int_gc = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_int_gc, \
  .tBit.r1_int_half = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_int_half, \
  .tBit.r1_hv_cvc1_bcon = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_hv_cvc1_bcon, \
  .tBit.r1_hv_cvc2_bcon = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_hv_cvc2_bcon, \
  .tBit.r1_lv_int_bcon = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_lv_int_bcon, \
  .tBit.r1_lv_sha_bcon = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_lv_sha_bcon, \
  .tBit.r1_ref_bcon = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_ref_bcon, \
  .tBit.r1_lv_adc_ref_bcon = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_lv_adc_ref_bcon, \
  .tBit.r1_lv_sha_buf_bcon = PARAMSET_ROIC_R1_AFE_SENSE_CTL_r1_lv_sha_buf_bcon, \
 } ,\
 .R1_PDB_CTL = \
 { \
  .tBit.r1_pdb_hvbias = PARAMSET_ROIC_R1_PDB_CTL_r1_pdb_hvbias, \
  .tBit.r1_pdb_hvc = PARAMSET_ROIC_R1_PDB_CTL_r1_pdb_hvc, \
  .tBit.r1_pdb_lvbias = PARAMSET_ROIC_R1_PDB_CTL_r1_pdb_lvbias, \
  .tBit.r1_pdb_int = PARAMSET_ROIC_R1_PDB_CTL_r1_pdb_int, \
  .tBit.r1_pdb_sha = PARAMSET_ROIC_R1_PDB_CTL_r1_pdb_sha, \
  .tBit.r1_pdb_sha_buf = PARAMSET_ROIC_R1_PDB_CTL_r1_pdb_sha_buf, \
  .tBit.r1_bgr_en = PARAMSET_ROIC_R1_PDB_CTL_r1_bgr_en, \
  .tBit.r1_bias_en = PARAMSET_ROIC_R1_PDB_CTL_r1_bias_en, \
  .tBit.r1_pdb_adc_ref = PARAMSET_ROIC_R1_PDB_CTL_r1_pdb_adc_ref, \
  .tBit.r1_stuck_hvbias = PARAMSET_ROIC_R1_PDB_CTL_r1_stuck_hvbias, \
  .tBit.r1_stuck_hvc = PARAMSET_ROIC_R1_PDB_CTL_r1_stuck_hvc, \
  .tBit.r1_stuck_lvbias = PARAMSET_ROIC_R1_PDB_CTL_r1_stuck_lvbias, \
  .tBit.r1_stuck_int = PARAMSET_ROIC_R1_PDB_CTL_r1_stuck_int, \
  .tBit.r1_stuck_sha = PARAMSET_ROIC_R1_PDB_CTL_r1_stuck_sha, \
  .tBit.r1_stuck_sha_buf = PARAMSET_ROIC_R1_PDB_CTL_r1_stuck_sha_buf, \
  .tBit.r1_stuck_bgr_en = PARAMSET_ROIC_R1_PDB_CTL_r1_stuck_bgr_en, \
  .tBit.r1_stuck_bias_en = PARAMSET_ROIC_R1_PDB_CTL_r1_stuck_bias_en, \
  .tBit.r1_stuck_adc_ref = PARAMSET_ROIC_R1_PDB_CTL_r1_stuck_adc_ref, \
 } ,\
 .R1_TG_STUCK = \
 { \
  .tBit.r1_stuck_cvc1_drv = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_cvc1_drv, \
  .tBit.r1_stuck_cvc1_drv_d = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_cvc1_drv_d, \
  .tBit.r1_stuck_rstp = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_rstp, \
  .tBit.r1_stuck_phtcr = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_phtcr, \
  .tBit.r1_stuck_vcr = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_vcr, \
  .tBit.r1_stuck_rsti = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_rsti, \
  .tBit.r1_stuck_phth0 = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_phth0, \
  .tBit.r1_stuck_phth1 = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_phth1, \
  .tBit.r1_stuck_pht0 = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_pht0, \
  .tBit.r1_stuck_pht1 = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_pht1, \
  .tBit.r1_stuck_pht2 = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_pht2, \
  .tBit.r1_stuck_pht3 = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_pht3, \
  .tBit.r1_stuck_cmfb_init = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_cmfb_init, \
  .tBit.r1_stuck_adc_rstb = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_adc_rstb, \
  .tBit.r1_stuck_vcr_en_odd = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_vcr_en_odd, \
  .tBit.r1_stuck_vcr_en_even = PARAMSET_ROIC_R1_TG_STUCK_r1_stuck_vcr_en_even, \
 } ,\
 .R1_TEST_MODE_CTL = \
 { \
  .tBit.r1_tm_mon_en = PARAMSET_ROIC_R1_TEST_MODE_CTL_r1_tm_mon_en, \
  .tBit.r1_tm_mon_s = PARAMSET_ROIC_R1_TEST_MODE_CTL_r1_tm_mon_s, \
  .tBit.r1_tm_ps_ev = PARAMSET_ROIC_R1_TEST_MODE_CTL_r1_tm_ps_ev, \
  .tBit.r1_tm_ps_od = PARAMSET_ROIC_R1_TEST_MODE_CTL_r1_tm_ps_od, \
  .tBit.r1_test_adc = PARAMSET_ROIC_R1_TEST_MODE_CTL_r1_test_adc, \
  .tBit.r1_tm_cr = PARAMSET_ROIC_R1_TEST_MODE_CTL_r1_tm_cr, \
 } ,\
 .R1_RESERVE = \
 { \
  .tBit.r1_reserve = PARAMSET_ROIC_R1_RESERVE_r1_reserve, \
 } ,\
 .SPI_WRITE_DEFEND = \
 { \
  .tBit.spi_write_defend = PARAMSET_ROIC_SPI_WRITE_DEFEND_spi_write_defend, \
 } ,\
 .MON_CFCLK_ON = \
 { \
  .tBit.mon_cfclk_on = PARAMSET_ROIC_MON_CFCLK_ON_mon_cfclk_on, \
 } ,\

//#define SRIC_Conf_Set        SRIC_WGPPEN_Conf_Set

#endif

#endif

