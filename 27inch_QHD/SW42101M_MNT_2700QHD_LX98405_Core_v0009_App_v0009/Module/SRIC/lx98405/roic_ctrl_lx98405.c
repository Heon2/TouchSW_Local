//-------------------------------------------------------
//-   Reg Setting Example                                
//-------------------------------------------------------
#include "hal_def.h"
#include "module_def.h"

#include "lx98405_parameter_info.h"
#include "lx98405_param_configset_roic.h"
#include "lx98405_parameter_set.h"

tModuleSRICCommonConf_t s_ktmoduleSRICCommonConf = {
	SRIC_Conf_Set
};

void LX98405_Reg_CRTuneSetting_tmp(void);// tmp
void LX98405_Reg_CRTuneSetting (void); // main tune
tModuleSRICCommonConf_t * s_pktmoduleSRICCommonConf = NULL;

// SPI & TST_OUT Pad Condtrol

void LX98405_RegisterInit(eSENSING_MODE_t eSensingMode)
{
	
	  s_pktmoduleSRICCommonConf = &s_ktmoduleSRICCommonConf;
    uint32_t ulBuf[8];
    uint32_t ulBuf_w[8];
	
	// R/W Test
 #if 0
  	MSPI_RegisterRead((uint32_t)(0x0000) | 0x1 << 12 , &ulBuf[0], MSPI_READ_NONE);
  	MSPI_RegisterRead((uint32_t)(0x0000), &ulBuf[0],MSPI_READ_SM0);  //SM0 Read
  	MSPI_RegisterRead((uint32_t)(0x0000), &ulBuf[0],MSPI_READ_SM1); // SM1 Read
	
		 MSPI_RegisterWrite((uint32_t)(0x0010), 0x0000ffff, MSPI_READ_SM0                          );  // R/W  
		 MSPI_RegisterWrite((uint32_t)(0x0010) | 0x1 << 12 , 0xffff0000 , MSPI_READ_SM0      );  // R/W  	
	
  	MSPI_RegisterRead((uint32_t)(0x0010), &ulBuf[0], MSPI_READ_SM1);
  	MSPI_RegisterRead((uint32_t)(0x0010) | 0x1 << 12, &ulBuf[0], MSPI_READ_SM1);	
	
	
 	  MSPI_RegisterWrite((uint32_t)(0x0010), 0x12345678   , MSPI_READ_SM0      );  // R/W  
  	MSPI_RegisterRead((uint32_t)(0x0010), &ulBuf[0], MSPI_READ_SM0);
	
		 MSPI_RegisterWrite((uint32_t)(0x0010), 0x00FF    , MSPI_READ_SM1     );  // R/W  
		MSPI_RegisterRead((uint32_t)(0x0010), &ulBuf[0], MSPI_READ_SM1);
	
	  ulBuf_w[0] = 1;
		ulBuf_w[1] = 2;
		ulBuf_w[2] = 3;
		ulBuf_w[3] = 4;
	  ulBuf_w[4] = 5;
		ulBuf_w[5] = 6;
		ulBuf_w[6] = 7;
		ulBuf_w[7] = 8;
		// Each Write
	  MSPI_EachRegisterWrite ((uint32_t)(0x0010), &ulBuf_w[0], MSPI_READ_SM0);
	  MSPI_EachRegisterWrite ((uint32_t)(0x0010) , &ulBuf_w[0], MSPI_READ_SM1);
		
	  MSPI_RegisterRead((uint32_t)(0x0010), &ulBuf[0], MSPI_READ_SM0);
	  MSPI_RegisterRead((uint32_t)(0x0010), &ulBuf[0], MSPI_READ_SM1);	
		
		MSPI_RegisterRead((uint32_t)(0x0010), &ulBuf[0], MSPI_READ_SM0);
	  MSPI_RegisterRead((uint32_t)(0x0010), &ulBuf[0], MSPI_READ_SM1);	

    MSPI_RegisterAllSricWrite((uint32_t)(0x0010), 0x12345678  );
	  MSPI_RegisterRead((uint32_t)(0x0010), &ulBuf[0], MSPI_READ_SM0);
	  MSPI_RegisterRead((uint32_t)(0x0010), &ulBuf[0], MSPI_READ_SM1);	
#endif 


//    MSPI_RegisterWrite((uint32_t)(0x0000), s_pktmoduleSRICCommonConf->PRODUCT_ID[0].ulBulk            );  // R    
    MSPI_RegisterAllSricWrite((uint32_t)(0x0004), s_pktmoduleSRICCommonConf->INTERFACE_CFG.ulBulk            );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0008), s_pktmoduleSRICCommonConf->SPIS_PAD_CTL.ulBulk             );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x000C), s_pktmoduleSRICCommonConf->LVDS_PHY_CTL.ulBulk             );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0010), s_pktmoduleSRICCommonConf->TLVDS_DUM0.ulBulk               );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0014), s_pktmoduleSRICCommonConf->TLVDS_DUM1.ulBulk               );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0018), s_pktmoduleSRICCommonConf->SYS_CFG.ulBulk                  );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x001C), s_pktmoduleSRICCommonConf->SDIC_CFG.ulBulk                 );  // R/W  
//    MSPI_RegisterAllSricWrite((uint32_t)(0x0020), s_pktmoduleSRICCommonConf->TC_START.ulBulk                 );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0024), s_pktmoduleSRICCommonConf->CH_MUX_NUM.ulBulk               );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0028), s_pktmoduleSRICCommonConf->LHB_MUX_CTL.ulBulk              );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x002C), s_pktmoduleSRICCommonConf->MD_PWM_CTL.ulBulk               );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0030), s_pktmoduleSRICCommonConf->MD0_MUX_CFG_00.ulBulk           );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0034), s_pktmoduleSRICCommonConf->MD0_MUX_CFG_01.ulBulk           );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0038), s_pktmoduleSRICCommonConf->DEFA_LHB_MCFG00.ulBulk          );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x003C), s_pktmoduleSRICCommonConf->PWM_PRD.ulBulk                  );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0040), s_pktmoduleSRICCommonConf->PWM_MUX_DLY_PRD.ulBulk          );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0044), s_pktmoduleSRICCommonConf->AFE_SIG_CTL.ulBulk              );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0048), s_pktmoduleSRICCommonConf->F1_CVC1_DRV_CTL1.ulBulk         );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x004C), s_pktmoduleSRICCommonConf->F1_RSTP_PHT_CTL.ulBulk          );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0050), s_pktmoduleSRICCommonConf->F1_PHTCR_VCR_CTL.ulBulk         );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0054), s_pktmoduleSRICCommonConf->F1_RSTI_CTL.ulBulk              );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0058), s_pktmoduleSRICCommonConf->F1_PHTH_CTL.ulBulk              );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x005C), s_pktmoduleSRICCommonConf->F2_CVC1_DRV_CTL1.ulBulk         );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0060), s_pktmoduleSRICCommonConf->F2_RSTP_PHT_CTL.ulBulk          );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0064), s_pktmoduleSRICCommonConf->F2_PHTCR_VCR_CTL.ulBulk         );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0068), s_pktmoduleSRICCommonConf->F2_RSTI_CTL.ulBulk              );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x006C), s_pktmoduleSRICCommonConf->F2_PHTH_CTL.ulBulk              );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0070), s_pktmoduleSRICCommonConf->PHT_CTL.ulBulk                  );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0074), s_pktmoduleSRICCommonConf->ADC_CTL1.ulBulk                 );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0078), s_pktmoduleSRICCommonConf->ADC_CTL2.ulBulk                 );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x007C), s_pktmoduleSRICCommonConf->ADC_CTL3.ulBulk                 );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0080), s_pktmoduleSRICCommonConf->TEST_MUX_CTL.ulBulk             );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0084), s_pktmoduleSRICCommonConf->SYS_DUMMY0.ulBulk               );  // R/W  
		
    MSPI_RegisterAllSricWrite((uint32_t)(0x0200), s_pktmoduleSRICCommonConf->R0_AFE_CFG.ulBulk               );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0204), s_pktmoduleSRICCommonConf->R0_CH_EN.ulBulk                 );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0208), s_pktmoduleSRICCommonConf->R0_BUF_OPT.ulBulk               );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x020C), s_pktmoduleSRICCommonConf->R0_VCOMR_OPT.ulBulk             );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0210), s_pktmoduleSRICCommonConf->R0_MUX_CTL1.ulBulk              );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0214), s_pktmoduleSRICCommonConf->R0_CR_RG_MUX1[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0218), s_pktmoduleSRICCommonConf->R0_CR_RG_MUX2[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x021C), s_pktmoduleSRICCommonConf->R0_CR_RG_MUX3[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0220), s_pktmoduleSRICCommonConf->R0_CR_RG_MUX4[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0224), s_pktmoduleSRICCommonConf->R0_CR_RG_MUX5[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0228), s_pktmoduleSRICCommonConf->R0_CR_RG_MUX6[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x022C), s_pktmoduleSRICCommonConf->R0_CR_RG_MUX7[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0230), s_pktmoduleSRICCommonConf->R0_CR_RG_MUX8[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0234), s_pktmoduleSRICCommonConf->R0_CR_RG_MUX9[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0238), s_pktmoduleSRICCommonConf->R0_CR_RG_MUX10[0].ulBulk        );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x023C), s_pktmoduleSRICCommonConf->R0_CR_RG_MUX11[0].ulBulk        );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0240), s_pktmoduleSRICCommonConf->R0_CR_R1G_MUXE[0].ulBulk        );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0244), s_pktmoduleSRICCommonConf->R0_CR_R1G_MUXO[0].ulBulk        );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0248), s_pktmoduleSRICCommonConf->R0_CR_GTUNE1[0].ulBulk          );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x024C), s_pktmoduleSRICCommonConf->R0_CR_GTUNE2[0].ulBulk          );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0250), s_pktmoduleSRICCommonConf->R0_TUNE_GROUP_SEL1[0].ulBulk    );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0254), s_pktmoduleSRICCommonConf->R0_TUNE_GROUP_SEL2[0].ulBulk    );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0258), s_pktmoduleSRICCommonConf->R0_TUNE_GROUP_SEL3[0].ulBulk    );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x025C), s_pktmoduleSRICCommonConf->R0_ADC_IN_CTL.ulBulk            );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0260), s_pktmoduleSRICCommonConf->R0_AFE_SENSE_CTL.ulBulk         );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0264), s_pktmoduleSRICCommonConf->R0_PDB_CTL.ulBulk               );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0268), s_pktmoduleSRICCommonConf->R0_TG_STUCK.ulBulk              );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x026C), s_pktmoduleSRICCommonConf->R0_TEST_MODE_CTL.ulBulk         );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0270), s_pktmoduleSRICCommonConf->R0_RESERVE.ulBulk               );  // R/W  
		

    MSPI_RegisterAllSricWrite((uint32_t)(0x0300), s_pktmoduleSRICCommonConf->R1_AFE_CFG.ulBulk               );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0304), s_pktmoduleSRICCommonConf->R1_CH_EN.ulBulk                 );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0308), s_pktmoduleSRICCommonConf->R1_BUF_OPT.ulBulk               );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x030C), s_pktmoduleSRICCommonConf->R1_VCOMR_OPT.ulBulk             );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0310), s_pktmoduleSRICCommonConf->R1_MUX_CTL1.ulBulk              );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0314), s_pktmoduleSRICCommonConf->R1_CR_RG_MUX1[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0318), s_pktmoduleSRICCommonConf->R1_CR_RG_MUX2[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x031C), s_pktmoduleSRICCommonConf->R1_CR_RG_MUX3[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0320), s_pktmoduleSRICCommonConf->R1_CR_RG_MUX4[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0324), s_pktmoduleSRICCommonConf->R1_CR_RG_MUX5[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0328), s_pktmoduleSRICCommonConf->R1_CR_RG_MUX6[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x032C), s_pktmoduleSRICCommonConf->R1_CR_RG_MUX7[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0330), s_pktmoduleSRICCommonConf->R1_CR_RG_MUX8[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0334), s_pktmoduleSRICCommonConf->R1_CR_RG_MUX9[0].ulBulk         );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0338), s_pktmoduleSRICCommonConf->R1_CR_RG_MUX10[0].ulBulk        );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x033C), s_pktmoduleSRICCommonConf->R1_CR_RG_MUX11[0].ulBulk        );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0340), s_pktmoduleSRICCommonConf->R1_CR_R1G_MUXE[0].ulBulk        );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0344), s_pktmoduleSRICCommonConf->R1_CR_R1G_MUXO[0].ulBulk        );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0348), s_pktmoduleSRICCommonConf->R1_CR_GTUNE1[0].ulBulk          );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x034C), s_pktmoduleSRICCommonConf->R1_CR_GTUNE2[0].ulBulk          );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0350), s_pktmoduleSRICCommonConf->R1_TUNE_GROUP_SEL1[0].ulBulk    );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0354), s_pktmoduleSRICCommonConf->R1_TUNE_GROUP_SEL2[0].ulBulk    );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x0358), s_pktmoduleSRICCommonConf->R1_TUNE_GROUP_SEL3[0].ulBulk    );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x035C), s_pktmoduleSRICCommonConf->R1_ADC_IN_CTL.ulBulk            );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0360), s_pktmoduleSRICCommonConf->R1_AFE_SENSE_CTL.ulBulk         );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0364), s_pktmoduleSRICCommonConf->R1_PDB_CTL.ulBulk               );  // R/W  
			  MSPI_RegisterRead((uint32_t)(0x0364), &ulBuf[0], MSPI_READ_SM1);	
    MSPI_RegisterAllSricWrite((uint32_t)(0x0368), s_pktmoduleSRICCommonConf->R1_TG_STUCK.ulBulk              );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x036C), s_pktmoduleSRICCommonConf->R1_TEST_MODE_CTL.ulBulk         );  // R/W  
    MSPI_RegisterAllSricWrite((uint32_t)(0x0370), s_pktmoduleSRICCommonConf->R1_RESERVE.ulBulk               );  // R/W  
   // MSPI_RegisterAllSricWrite((uint32_t)(0x07F0), s_pktmoduleSRICCommonConf->SPI_WRITE_DEFEND.ulBulk         );  // R/W  
  //  MSPI_RegisterAllSricWrite((uint32_t)(0x07F4), s_pktmoduleSRICCommonConf->MON_CFCLK_ON.ulBulk             );  // R/W  
//    MSPI_RegisterWrite((uint32_t)(0x07F8), s_pktmoduleSRICCommonConf->MON_ADCDO[0].ulBulk             );  // R    
//    MSPI_RegisterWrite((uint32_t)(0x07FC), s_pktmoduleSRICCommonConf->SRIC_STATE[0].ulBulk            );  // R    

  //  LX98405_Reg_CRTuneSetting_tmp(); // Temp Setting
     LX98405_Reg_CRTuneSetting();
// SRIC IQR Enable
//	  MSPI_RegisterWrite((uint32_t)(0x0004), 0x1 << 3 | 0x1 , MSPI_READ_SM1           );  // R/W  	
	  MSPI_RegisterWrite((uint32_t)(0x0004), 0x1 <<12  | 0x1 << 10| 0x1 << 3 | 0x1 , MSPI_READ_SM1           );  // R/W  			

}


void LX98405_Reg_CRTuneSetting(void)
{
	  s_pktmoduleSRICCommonConf = &s_ktmoduleSRICCommonConf;
	// MSPI_EachRegisterWrite --> Setting Register Value - Each Register
 // SRIC1,3,5,7
	// R1 Setting 
   MSPI_EachRegisterWrite((uint32_t)(0x0214), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX1[0].ulBulk , MSPI_READ_SM0        );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0218), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX2[0].ulBulk  , MSPI_READ_SM0       );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x021C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX3[0].ulBulk  , MSPI_READ_SM0       );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0220), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX4[0].ulBulk   , MSPI_READ_SM0      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0224), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX5[0].ulBulk   , MSPI_READ_SM0      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0228), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX6[0].ulBulk   , MSPI_READ_SM0      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x022C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX7[0].ulBulk  , MSPI_READ_SM0       );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0230), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX8[0].ulBulk   , MSPI_READ_SM0      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0234), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX9[0].ulBulk   , MSPI_READ_SM0      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0238), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX10[0].ulBulk  , MSPI_READ_SM0      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x023C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX11[0].ulBulk  , MSPI_READ_SM0      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0240), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUXE[0].ulBulk   , MSPI_READ_SM0     );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0244), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUXO[0].ulBulk   , MSPI_READ_SM0     );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0248), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE1[0].ulBulk   , MSPI_READ_SM0       );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x024C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE2[0].ulBulk    , MSPI_READ_SM0      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0250), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_TUNE_GROUP_SEL1[0].ulBulk  , MSPI_READ_SM0  );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0254), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_TUNE_GROUP_SEL2[0].ulBulk   , MSPI_READ_SM0 );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0258), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_TUNE_GROUP_SEL3[0].ulBulk  , MSPI_READ_SM0  );  // R/W  
	
	
	// R1 Setting 
    MSPI_EachRegisterWrite((uint32_t)(0x0314), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX1[0].ulBulk     , MSPI_READ_SM0    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0318), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX2[0].ulBulk     , MSPI_READ_SM0    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x031C),(uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR_RG_MUX3[0].ulBulk     , MSPI_READ_SM0    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0320), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX4[0].ulBulk     , MSPI_READ_SM0    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0324), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX5[0].ulBulk     , MSPI_READ_SM0    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0328), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX6[0].ulBulk     , MSPI_READ_SM0    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x032C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX7[0].ulBulk     , MSPI_READ_SM0    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0330), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX8[0].ulBulk      , MSPI_READ_SM0   );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0334), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX9[0].ulBulk      , MSPI_READ_SM0   );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0338), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX10[0].ulBulk    , MSPI_READ_SM0    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x033C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX11[0].ulBulk   , MSPI_READ_SM0     );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0340), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUXE[0].ulBulk    , MSPI_READ_SM0    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0344), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUXO[0].ulBulk    , MSPI_READ_SM0    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0348), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE1[0].ulBulk       , MSPI_READ_SM0   );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x034C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE2[0].ulBulk       , MSPI_READ_SM0   );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0350), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_TUNE_GROUP_SEL1[0].ulBulk  , MSPI_READ_SM0  );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0354), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_TUNE_GROUP_SEL2[0].ulBulk  , MSPI_READ_SM0  );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0358), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_TUNE_GROUP_SEL3[0].ulBulk   , MSPI_READ_SM0 );  // R/W  

 // SRIC2,4,6,8
	// R1 Setting 
   MSPI_EachRegisterWrite((uint32_t)(0x0214), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX1[0].ulBulk , MSPI_READ_SM1        );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0218), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX2[0].ulBulk  , MSPI_READ_SM1       );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x021C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX3[0].ulBulk  , MSPI_READ_SM1       );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0220), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX4[0].ulBulk   , MSPI_READ_SM1      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0224), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX5[0].ulBulk   , MSPI_READ_SM1      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0228), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX6[0].ulBulk   , MSPI_READ_SM1      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x022C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX7[0].ulBulk  , MSPI_READ_SM1       );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0230), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX8[0].ulBulk   , MSPI_READ_SM1      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0234), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX9[0].ulBulk   , MSPI_READ_SM1      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0238), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX10[0].ulBulk  , MSPI_READ_SM1      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x023C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_RG_MUX11[0].ulBulk  , MSPI_READ_SM1      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0240), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUXE[0].ulBulk   , MSPI_READ_SM1     );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0244), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_R1G_MUXO[0].ulBulk   , MSPI_READ_SM1     );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0248), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE1[0].ulBulk   , MSPI_READ_SM1       );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x024C), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_CR_GTUNE2[0].ulBulk    , MSPI_READ_SM1      );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0250), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_TUNE_GROUP_SEL1[0].ulBulk  , MSPI_READ_SM1  );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0254), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_TUNE_GROUP_SEL2[0].ulBulk   , MSPI_READ_SM1 );  // R/W  
   MSPI_EachRegisterWrite((uint32_t)(0x0258), (uint32_t *)&s_pktmoduleSRICCommonConf->R0_TUNE_GROUP_SEL3[0].ulBulk  , MSPI_READ_SM1  );  // R/W  
	
	
	// R1 Setting 
    MSPI_EachRegisterWrite((uint32_t)(0x0314), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX1[0].ulBulk     , MSPI_READ_SM1    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0318), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX2[0].ulBulk     , MSPI_READ_SM1    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x031C),(uint32_t *)& s_pktmoduleSRICCommonConf->R1_CR_RG_MUX3[0].ulBulk     , MSPI_READ_SM1    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0320), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX4[0].ulBulk     , MSPI_READ_SM1   );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0324), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX5[0].ulBulk     , MSPI_READ_SM1    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0328), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX6[0].ulBulk     , MSPI_READ_SM1    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x032C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX7[0].ulBulk     , MSPI_READ_SM1    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0330), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX8[0].ulBulk      , MSPI_READ_SM1   );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0334), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX9[0].ulBulk      , MSPI_READ_SM1   );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0338), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX10[0].ulBulk    , MSPI_READ_SM1    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x033C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_RG_MUX11[0].ulBulk   , MSPI_READ_SM1    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0340), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUXE[0].ulBulk    , MSPI_READ_SM1    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0344), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_R1G_MUXO[0].ulBulk    , MSPI_READ_SM1    );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0348), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE1[0].ulBulk       , MSPI_READ_SM1   );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x034C), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_CR_GTUNE2[0].ulBulk       , MSPI_READ_SM1   );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0350), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_TUNE_GROUP_SEL1[0].ulBulk  , MSPI_READ_SM1  );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0354), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_TUNE_GROUP_SEL2[0].ulBulk  , MSPI_READ_SM1  );  // R/W  
    MSPI_EachRegisterWrite((uint32_t)(0x0358), (uint32_t *)&s_pktmoduleSRICCommonConf->R1_TUNE_GROUP_SEL3[0].ulBulk   , MSPI_READ_SM1 );  // R/W  

}


// For Test Tune
void LX98405_Reg_CRTuneSetting_tmp(void)
{
	
	// Temp
	
		  uint32_t CR_TEMP;
			uint32_t CR_VAL ;
			CR_VAL = 0x01;
			CR_TEMP = CR_VAL << 0 | CR_VAL << 5 | CR_VAL << 10 | CR_VAL << 15 | CR_VAL << 20 | CR_VAL << 25 ;
	
	    MSPI_RegisterAllSricWrite((uint32_t)(0x0214),   CR_TEMP    );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0218),   CR_TEMP      );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x021C),   CR_TEMP      );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0220),    CR_TEMP     );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0224),     CR_TEMP    );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0228),    CR_TEMP     ) ;          // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x022C),     CR_TEMP    );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0230),     CR_TEMP    );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0234),     CR_TEMP     );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0238),    CR_TEMP       );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x023C),     CR_TEMP     );  // R/W  
	
	
	   MSPI_RegisterAllSricWrite((uint32_t)(0x0248),  0x9249249    );  // R/W  0x12492492, 0x9249249
     MSPI_RegisterAllSricWrite((uint32_t)(0x024C),  0x9249249     );  // R/W  

    MSPI_RegisterAllSricWrite((uint32_t)(0x0348), 0x9249249      );  // R/W   0x9249249
    MSPI_RegisterAllSricWrite((uint32_t)(0x034C), 0x9249249       );  // R/W  
	
	
      MSPI_RegisterAllSricWrite((uint32_t)(0x0314),   CR_TEMP    );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0318),   CR_TEMP      );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x031C),   CR_TEMP      );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0320),    CR_TEMP     );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0324),     CR_TEMP    );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0328),    CR_TEMP     ) ;          // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x032C),     CR_TEMP    );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0330),     CR_TEMP    );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0334),     CR_TEMP     );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x0338),    CR_TEMP       );  // R/W  
      MSPI_RegisterAllSricWrite((uint32_t)(0x033C),     CR_TEMP     );  // R/W  
			
}


// Test mode...
void LX98405_EvenOdd_Short_Setting(uint8_t index)
{
//	s_pktmoduleSRICCommonConf = &s_ktmoduleSRICCommonConf;

	tR0_TG_STUCK_t tR0_TG_STUCK;
	tR1_TG_STUCK_t tR1_TG_STUCK;

	tR0_TEST_MODE_CTL_t tR0_TEST_MODE_CTL;
	tR1_TEST_MODE_CTL_t tR1_TEST_MODE_CTL;


	tR0_TG_STUCK.ulBulk= s_pktmoduleSRICCommonConf->R0_TG_STUCK.ulBulk;
	tR1_TG_STUCK.ulBulk= s_pktmoduleSRICCommonConf->R1_TG_STUCK.ulBulk;

	tR0_TEST_MODE_CTL.ulBulk = s_pktmoduleSRICCommonConf->R0_TEST_MODE_CTL.ulBulk;
	tR1_TEST_MODE_CTL.ulBulk = s_pktmoduleSRICCommonConf->R1_TEST_MODE_CTL.ulBulk;

	tR0_TG_STUCK.tBit.r0_stuck_phth0 = 2;
	tR1_TG_STUCK.tBit.r1_stuck_phth0 = 2;

	MSPI_RegisterAllSricWrite((uint32_t)(0x0268), tR0_TG_STUCK.ulBulk              );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0368), tR1_TG_STUCK.ulBulk              );  // R/W

	if (index == 0)  // Even Short...
	{
		tR0_TEST_MODE_CTL.tBit.r0_tm_ps_ev = 0;
		tR0_TEST_MODE_CTL.tBit.r0_tm_ps_od = 1;
		tR1_TEST_MODE_CTL.tBit.r1_tm_ps_ev = 1;
		tR1_TEST_MODE_CTL.tBit.r1_tm_ps_od = 0;
	}
	else if (index == 1)  // Odd Short...
	{
		tR0_TEST_MODE_CTL.tBit.r0_tm_ps_ev = 1;
		tR0_TEST_MODE_CTL.tBit.r0_tm_ps_od = 0;
		tR1_TEST_MODE_CTL.tBit.r1_tm_ps_ev = 0;
		tR1_TEST_MODE_CTL.tBit.r1_tm_ps_od = 1;
	}

	MSPI_RegisterAllSricWrite((uint32_t)(0x026C), tR0_TEST_MODE_CTL.ulBulk  );
	MSPI_RegisterAllSricWrite((uint32_t)(0x036C), tR1_TEST_MODE_CTL.ulBulk  );

}

void LX98405_Short_Local_Global_Tune(void)
{
	uint32_t CR_TEMP,  CR_VAL ; // Local Tune
	uint32_t GCR_VAL,  GCR_VAL_TEMP ; // Global Tune

	// Local Tune Setting
	CR_VAL = 0;
	CR_TEMP = CR_VAL << 0 | CR_VAL << 5 | CR_VAL << 10 |
	                    CR_VAL << 15 | CR_VAL << 20 | CR_VAL << 25 ;
	MSPI_RegisterAllSricWrite((uint32_t)(0x0214),   CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0218),   CR_TEMP      );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x021C),   CR_TEMP      );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0220),    CR_TEMP     );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0224),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0228),    CR_TEMP     ) ;          // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x022C),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0230),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0234),     CR_TEMP     );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0238),    CR_TEMP       );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x023C),     CR_TEMP     );
	MSPI_RegisterAllSricWrite((uint32_t)(0x0314),   CR_TEMP    );
	MSPI_RegisterAllSricWrite((uint32_t)(0x0318),   CR_TEMP      );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x031C),   CR_TEMP      );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0320),    CR_TEMP     );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0324),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0328),    CR_TEMP     ) ;   // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x032C),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0330),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0334),     CR_TEMP     );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0338),    CR_TEMP       );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x033C),     CR_TEMP     );  // R/W

	// Global Tune Setting
	GCR_VAL = 0;
	GCR_VAL_TEMP = GCR_VAL << 0  | GCR_VAL << 3  | GCR_VAL << 6| GCR_VAL << 9 | GCR_VAL << 12 |
	                  GCR_VAL << 15  | GCR_VAL << 18 | GCR_VAL << 21 | GCR_VAL << 24| GCR_VAL << 27 ;

	MSPI_RegisterAllSricWrite((uint32_t)(0x0248),  GCR_VAL_TEMP    );
	MSPI_RegisterAllSricWrite((uint32_t)(0x024C),  GCR_VAL_TEMP     );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0348), GCR_VAL_TEMP      );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x034C), GCR_VAL_TEMP       );  // R/W


}

void LX98405_OpenShort_SourceGnd_Setting(void)
{
//	s_pktmoduleSRICCommonConf = &s_ktmoduleSRICCommonConf;

	tSDIC_CFG_t tSDIC_CFG ;

	tSDIC_CFG.ulBulk = s_pktmoduleSRICCommonConf->SDIC_CFG.ulBulk;

	// Source Ground Setting
	tSDIC_CFG.tBit.sd_rocen = 1;
	tSDIC_CFG.tBit.sd_float_0_ctl = 1;
	tSDIC_CFG.tBit.sd_float_1_ctl = 1;
	tSDIC_CFG.tBit.sd_gnd_0_ctl = 1;
	tSDIC_CFG.tBit.sd_gnd_1_ctl = 1;
	MSPI_RegisterAllSricWrite((uint32_t)(0x001C), tSDIC_CFG.ulBulk );

}

void LX98405_OpenShort_Local_Global_Tune(void)
{
	uint32_t CR_TEMP,  CR_VAL ; // Local Tune
	uint32_t GCR_VAL,  GCR_VAL_TEMP ; // Global Tune

	// Local Tune Setting
	CR_VAL = 31;
	CR_TEMP = CR_VAL << 0 | CR_VAL << 5 | CR_VAL << 10 |
	                    CR_VAL << 15 | CR_VAL << 20 | CR_VAL << 25 ;

	MSPI_RegisterAllSricWrite((uint32_t)(0x0214),   CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0218),   CR_TEMP      );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x021C),   CR_TEMP      );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0220),    CR_TEMP     );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0224),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0228),    CR_TEMP     ) ;          // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x022C),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0230),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0234),     CR_TEMP     );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0238),    CR_TEMP       );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x023C),     CR_TEMP     );

	MSPI_RegisterAllSricWrite((uint32_t)(0x0314),   CR_TEMP    );
	MSPI_RegisterAllSricWrite((uint32_t)(0x0318),   CR_TEMP      );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x031C),   CR_TEMP      );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0320),    CR_TEMP     );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0324),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0328),    CR_TEMP     ) ;   // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x032C),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0330),     CR_TEMP    );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0334),     CR_TEMP     );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0338),    CR_TEMP       );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x033C),     CR_TEMP     );  // R/W

	// Global Tune Setting
	GCR_VAL = 7;
	GCR_VAL_TEMP = GCR_VAL << 0  | GCR_VAL << 3  | GCR_VAL << 6| GCR_VAL << 9 | GCR_VAL << 12 |
	                  GCR_VAL << 15  | GCR_VAL << 18 | GCR_VAL << 21 | GCR_VAL << 24| GCR_VAL << 27 ;

	MSPI_RegisterAllSricWrite((uint32_t)(0x0248),  GCR_VAL_TEMP    );
	MSPI_RegisterAllSricWrite((uint32_t)(0x024C),  GCR_VAL_TEMP     );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0348), GCR_VAL_TEMP      );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x034C), GCR_VAL_TEMP       );  // R/W

}

void LX98405_OpenShort_Mux_Low_En(uint8_t index)
{
//	s_pktmoduleSRICCommonConf = &s_ktmoduleSRICCommonConf;

	tR0_MUX_CTL1_t  tR0_MUX_CTL1_r1;
	tR1_MUX_CTL1_t  tR1_MUX_CTL1_r1;

	tR0_MUX_CTL1_r1.ulBulk = s_pktmoduleSRICCommonConf->R0_MUX_CTL1.ulBulk ; // 추가
	tR1_MUX_CTL1_r1.ulBulk = s_pktmoduleSRICCommonConf->R1_MUX_CTL1.ulBulk ; // 추가

	// Row(rowNum) – 1 Frame
	tR0_MUX_CTL1_r1.tBit.r0_mux_int_stuck_val = index;
	tR1_MUX_CTL1_r1.tBit.r1_mux_int_stuck_val = index;

	MSPI_RegisterAllSricWrite((uint32_t)(0x0210), tR0_MUX_CTL1_r1.ulBulk              );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0310), tR1_MUX_CTL1_r1.ulBulk              );  // R/W


}

void LX98405_Reg_Restore_Setting(uint8_t index)
{
	s_pktmoduleSRICCommonConf = &s_ktmoduleSRICCommonConf;

	MSPI_RegisterAllSricWrite((uint32_t)(0x0268), s_pktmoduleSRICCommonConf->R0_TG_STUCK.ulBulk              );  // R/W
	MSPI_RegisterAllSricWrite((uint32_t)(0x0368), s_pktmoduleSRICCommonConf->R1_TG_STUCK.ulBulk              );  // R/W

	// Restore Setting
	if (index == 1)  // Test type Short...
	{
		MSPI_RegisterAllSricWrite((uint32_t)(0x026C), s_pktmoduleSRICCommonConf->R0_TEST_MODE_CTL.ulBulk         );  // R/W
		MSPI_RegisterAllSricWrite((uint32_t)(0x036C), s_pktmoduleSRICCommonConf->R1_TEST_MODE_CTL.ulBulk         );  // R/W

	}
	else if (index == 2)  // Test type Open Short...
	{
		MSPI_RegisterAllSricWrite((uint32_t)(0x001C), s_pktmoduleSRICCommonConf-> SDIC_CFG.ulBulk );

		MSPI_RegisterAllSricWrite((uint32_t)(0x0210), s_pktmoduleSRICCommonConf->R0_MUX_CTL1.ulBulk              );  // R/W
		MSPI_RegisterAllSricWrite((uint32_t)(0x0310), s_pktmoduleSRICCommonConf->R1_MUX_CTL1.ulBulk              );  // R/W
	}

	LX98405_Reg_CRTuneSetting(); // CR Recover

}
