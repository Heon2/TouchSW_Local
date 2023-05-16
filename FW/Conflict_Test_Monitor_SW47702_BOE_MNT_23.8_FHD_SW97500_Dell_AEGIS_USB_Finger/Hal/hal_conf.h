/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  hal_config.c
 * created on :  17. 4. 2017
 * Author :  mhjang
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

#ifndef _HAL_CONF_H_
#define _HAL_CONF_H_


typedef struct
{
	uint8_t ucLocalFingerMUXScanOrderIDX[6][4]; // [FINGER_LHB NUM_MAX][MUX_SCAN_NUM_MAX]
	uint8_t ucFullFingerMUXScanOrderIDX[6][4]; // [FINGER_LHB NUM_MAX][MUX_SCAN_NUM_MAX]

} __PACKED tHalMspiFingerMuxScanOrder_t;

typedef struct
{
	/*
	 * Protocol
	 */
	uint32_t			MSPI_LHBCountNum;
	uint32_t			MSPI_BUF_Panel_ColNum;
	ePartialSensing_t	ePenPartialIndex[16];
	tHalMspiFingerMuxScanOrder_t tMspiFingerMuxScanOrder;

} __PACKED tHalMspiControlConf_t;

typedef struct
{
	tHalMspiControlConf_t tMSPIControlConf[ACTIVEPEN_TYPE_NUM];
	tCP_SPIENA_t tParam_SPIENA;
	tCP_SPISCR_t tParam_SPISCR;

} __PACKED tHalMspiCommonConf_t;

typedef struct
{
    tCP_PWMGEN_CR0_t            tCP_PWMGEN_CR0;                     //0x0000
    tCP_PWMGEN_CR1_t            tCP_PWMGEN_CR1;                  	//0x0001
    tCP_PWMGEN_CR2_t            tCP_PWMGEN_CR2;                 	//0x0002
    tCP_SET_TX_CR_t             tCP_SET_TX_CR;                      //0x0003
    tCP_TSYNC_CR_t              tCP_TSYNC_CR;                       //0x0004
    tCP_TSYNC_D2_CR_t           tCP_TSYNC_D2_CR;                    //0x0005
    tCP_DLY_CNT1_t              tCP_DLY_CNT1;                       //0x0006
    tCP_DLY_CNT2_t              tCP_DLY_CNT2;                       //0x0007
    tCP_DLY_CNT3_t              tCP_DLY_CNT3;                       //0x0008
    tCP_TSYNC_TPIC_CR_t         tCP_TSYNC_TPIC_CR;                  //0x0009
    tCP_PWM_DLY1_t              tCP_PWM_DLY1;                       //0x000A
    tCP_DSSS_INFO0_t            tCP_DSSS_INFO0;                     //0x000B
    tCP_DSSS_INFO1_t            tCP_DSSS_INFO1[2];                  //0x000C
    tCP_DSSS_INFO2_t            tCP_DSSS_INFO2[2];                  //0x000E

    tCP_DSSS_CODE_Value_t		tCP_DSSS_CODE_Value[PWM_LHB_BEACON_NUM]; //0x0010

    tCP_PWM_TPIC_CR_t           tCP_PWM_TPIC_CR;                    //0x0020
    tCP_PWM_SRIC_CR_t           tCP_PWM_SRIC_CR;                    //0x0021
    tCP_PWM_MUX_CR_t            tCP_PWM_MUX_CR;                     //0x0022
    uint32_t                    tCP_DMY_FREQ;                       //0x0023
    tCP_FREQ_CR1_t              tCP_FREQ_CR1;                       //0x0024
    tCP_FREQ_CR2_t              tCP_FREQ_CR2;                       //0x0025
    tCP_LHB_CONFIG11_t          tCP_LHB_CONFIG11;                   //0x0026
    tCP_LHB_CONFIG12_t          tCP_LHB_CONFIG12;                   //0x0027
    tCP_LHB_CONFIG13_t          tCP_LHB_CONFIG13;                   //0x0028
    tCP_LHB_CONFIG14_t          tCP_LHB_CONFIG14;                   //0x0029
    tCP_LHB_CONFIG21_t          tCP_LHB_CONFIG21;                   //0x002A
    tCP_LHB_CONFIG22_t          tCP_LHB_CONFIG22;                   //0x002B
    tCP_LHB_CONFIG23_t          tCP_LHB_CONFIG23;                   //0x002C
    tCP_LHB_CONFIG24_t          tCP_LHB_CONFIG24;                   //0x002D
    tCP_PING_CR_t               tCP_PING_CR;                        //0x002E
    tCP_SYNC_GEN_CR_t           tCP_SYNC_GEN_CR;                    //0x003F
    uint32_t                    tCP_TE_RDY_CNT;                     //0x0030
    uint32_t                    tCP_TE_TCH_V_FPCH;                  //0x0031
    uint32_t                    tCP_TE_TCH_V_HIGH;                  //0x0032
    uint32_t                    tCP_TE_TCH_FPCH;                    //0x0033
    uint32_t                    tCP_TE_TCH_T_HIGH;                  //0x0034
    uint32_t                    tCP_TE_TCH_D_HIGH;                  //0x0035
    uint32_t                    tCP_TE_TCH_LOW;                     //0x0036
    uint32_t                    tCP_TE_TCH_BPCH;                    //0x0037
    uint32_t                    tCP_TE_TCH_PD_LOW;                  //0x0038
    uint32_t                    tCP_TG_DUM1;                        //0x003B
    uint32_t                    tCP_TG_DUM2;                        //0x003C
    uint32_t                    tCP_TG_DUM3;                        //0x003D
    uint32_t                    tCP_TG_DUM4;                        //0x003E
    tCP_TG_DUM5_t               tCP_TG_DUM5;                        //0x003F
    tCP_DISP_OFF_CR_t           tCP_DISP_OFF_CR;                    //0x0040
    tCP_PWM_CR1_t               tCP_PWM_CR1;                        //0x0042
    tCP_PWM_CR2_t               tCP_PWM_CR2;                        //0x0043
    tCP_VSYNC_CR_t              tCP_VSYNC_CR;                       //0x0044
    tCP_MUX_CR_t                tCP_MUX_CR;                         //0x0045
    tCP_PWM_TPIC_ST_CR_t        tCP_PWM_TPIC_ST_CR;                 //0x0046
    tCP_PWM_SRIC_ST_CR_t        tCP_PWM_SRIC_ST_CR;                 //0x0047
    tCP_PWM_MUX_ST_CR_t         tCP_PWM_MUX_ST_CR;                  //0x0048
    tCP_NM_FREQ_t				tCP_NM_FREQ;
//    tCP_PWM_STATUS_t			tCP_PWM_STATUS;
    tCP_PWM_DLY2_t				tCP_PWM_DLY2;
    tCP_DLY_CNT4_t				tCP_DLY_CNT4;
    uint32_t					tCP_KIOSK_VSYNC_TIMER;
    tCP_PWM_DLY3_t				tCP_PWM_DLY3;
    tCP_PWM_DLY4_t				tCP_PWM_DLY4;
//    tCP_DLY_CNT5_t					tCP_DLY_CNT5;

} __PACKED tHalPwmdrvControlConf_t;

typedef struct
{
	tHalPwmdrvControlConf_t 	tPwmControlConf[ACTIVEPEN_TYPE_NUM];
    tCP_ECLK_CR_t               tCP_ECLK_CR;                        //0x0023

} __PACKED tHalPwmdrvCommonConf_t;

//typedef struct
//{
//    uint8_t ucDeviceAddr;
//} __PACKED tHalI2CCommonConf_t;

typedef struct
{
    uint8_t ucDummy;
} __PACKED tHalUSBCommonConf_t;

typedef struct
{
    tHalMspiCommonConf_t tMSPI_Conf;
    tHalPwmdrvCommonConf_t tPWMDRV_Conf;
//    tHalI2CCommonConf_t tI2C_Conf;
    tHalUSBCommonConf_t tUSB_Conf;
} __PACKED tHalCommonConf_t;


typedef struct
{
	__IO eSENSING_CHANGE_MODE_t eSensingChangeMode;
	__IO eSENSING_MODE_t eSensingMode;
   	eDIAG_TEST_CHANGE_MODE_t eDiagTestChangeMode;
	eROIC_REG_SET_CHANGE_MODE_t eROICRegSetChangeMode;
	
#if USED_VCF_SYNC_CONTROL
	__IO bool_t bIsPrivacyEn;
#endif /* USED_VCF_SYNC_CONTROL */

#if USED_ECLK_ON_OFF_CONTROL
	__IO bool_t bIsECLKOnOffStart;
	__IO uint32_t bIsECLKOnOffStartCheckCnt;
#endif /* USED_ECLK_ON_OFF_CONTROL */

#if USED_TPIC_MUXEN_ON_OFF_CONTROL
	__IO bool_t bIsTPICMuxEnOnOffStart;
	__IO uint32_t bIsTPICMuxEnOnOffStartCheckCnt;
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */

#if USED_TOUCH_REPORT_ON_OFF_CONTROL
	__IO bool_t bIsTouchReportOnOffStart;
	__IO uint32_t bIsTouchReportOnOffStartCheckCnt;
#endif /* USED_TOUCH_REPORT_ON_OFF_CONTROL */

#if USED_S3_VDD_OE_INPUT_OUTPUT_CTRL
	__IO bool_t bIsS3VddOddEvenControlStart;
	__IO uint32_t bIsS3VddOddEvenControlStartCheckCnt;
	__IO uint8_t ucS3VddOddEvenStatus;
	__IO uint32_t bIsS3VddOddEvenControlFrameCheckCnt;
#endif /* USED_S3_VDD_OE_INPUT_OUTPUT_CTRL */

	__IO eActivePenType_t ulActivePenSettingType;
	__IO eActivePenType_t ulActivePenOPType;
	__IO eActivePenType_t ulActivePenRawDataType;
	__IO eActivePenType_t ulLocalFingerOPType;
	__IO eActivePenChangeType_t ulActivePenChangeType;

	__IO bool_t bIsPenDection;
	__IO bool_t bIsPenTypeSwapCheckStart;
	__IO uint32_t ulPenTypeSwapCheckFrameCnt;
	__IO uint32_t ulMSPenIdleOpFrameNumTHD;
	__IO uint32_t ulWacomPenIdleOpFrameNumTHD;

	__IO uint32_t ulWGPBeaconType;
	__IO uint32_t ulMPP1stBeaconType;

} tHalInfo_t;

extern void hal_SetCommonConfig(const tHalCommonConf_t * _p);
extern const tHalCommonConf_t *hal_GetCommonConfig(void);
extern const tHalMspiCommonConf_t *hal_mspi_GetCommonConfig(void);
extern const tHalMspiControlConf_t *hal_mspi_GetControlConfig(void);
extern const tHalPwmdrvCommonConf_t *hal_pwmdrv_GetCommonConfig(void);
extern const tHalPwmdrvControlConf_t *hal_pwmdrv_GetControlConfig(void);

extern void hal_Info_SetControlActivePenSettingType(eActivePenType_t eType);
extern eActivePenType_t hal_Info_GetControlActivePenSettingType(void);
extern void hal_Info_SetControlActivePenOPType(eActivePenType_t eType);
extern eActivePenType_t hal_Info_GetControlActivePenOPType(void);
extern void hal_Info_SetControlActivePenRawDataType(eActivePenType_t eType);
extern eActivePenType_t hal_Info_GetControlActivePenRawDataType(void);
extern void hal_Info_SetControlLocalFingerOPType(eActivePenType_t eType);
extern eActivePenType_t hal_Info_GetControlLocalFingerOPType(void);
extern void hal_Info_SetPenDectionEnable(bool_t bIsEn);
extern bool_t hal_Info_GetPenDectionEnable(void);
extern void hal_Info_SetPenTypeSwapCheckEnable(bool_t bIsEn);

extern uint32_t hal_Info_GetWGPPenBeaconType(void);
extern void hal_Info_SetWGPPenBeaconType(uint32_t ulType);

extern uint32_t hal_Info_GetMPPPen1stBeaconType(void);
extern void hal_Info_SetMPPPen1stBeaconType(uint32_t ulType);

extern tHalInfo_t *hal_GetInfo(void);

#endif /* _HAL_CONF_H_ */
