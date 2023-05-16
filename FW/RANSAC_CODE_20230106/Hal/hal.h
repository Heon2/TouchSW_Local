/****************************************************************************************************//**
* Copyright (c) 2017 - 2025 SiliconWorks LIMITED
*
* file : hal.h
* created on : 17. 4. 2017
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

#ifndef _HAL_H_
#define _HAL_H_


//#define I2C_SLAVE_ADDR					(0x34)


#if (USED_MODULE_DEF == MODULE_DEF_L_1)
#define SVCall_IRQn_Priority									(2)
#define PendSV_IRQn_Priority									((1UL << __NVIC_PRIO_BITS) - 1UL)
/* -----------------------  MFTP Specific Interrupt Numbers  ----------------------- */
#define WDGT_IRQn_Priority										(8)
#define TIMER_IRQn_Priority										(2)
#define DBG_I2C_IRQn_Priority									(0)
#define FLITF_IRQn_Priority										(5)
#define DBG_SPI_IRQn_Priority									(2)
#define AB_ACC_IRQn_Priority									(0)
#define GDMA_IRQn_Priority										(4)
#define USER_IRQn_Priority										(4)
#define GPIOA_IRQn_Priority										(5)
#define GPIOM_IRQn_Priority										(5)
#define VSYNC_IN_IRQn_Priority									(3)
#define TSYNC_IN_IRQn_Priority									(3)
#if USED_VCF_SYNC_CONTROL
#define TSYNC_OUT_IRQn_Priority									(1)
#else /* USED_VCF_SYNC_CONTROL */
#define TSYNC_OUT_IRQn_Priority									(3)
#endif /* USED_VCF_SYNC_CONTROL */

#define PWMDRV_IRQn_Priority									(3)
#define DSP_A_IRQn_Priority										(6)
#define DSP_B_IRQn_Priority										(15)
#define USB_IRQn_Priority										(4)
#define MSPI_IRQn_Priority										(2)
//#define SRIC_TRX_IRQn_Priority									(0)
#define TLVDS_IRQn_Priority										(2)
#define MPI_IRQn_Priority										(2)
//#define USB_SUSM_IRQn_Priority									(0)
//#define USB_LPMEN_IRQn_Priority									(0)
#define I2C_SLV_IRQn_Priority									(0)
#define I2C_SLV_Sleep_IRQn_Priority								(0)
#define I2C_SLV_Wakeup_IRQn_Priority							(0)
#define I2C_MST_IRQn_Priority									(0)
#define I2C_MST_Sleep_IRQn_Priority								(0)
#define I2C_MST_Wakeup_IRQn_Priority							(0)
#else //(USED_MODULE_DEF == MODULE_DEF_L_1)
#define SVCall_IRQn_Priority								(1)
#define PendSV_IRQn_Priority								((1UL << __NVIC_PRIO_BITS) - 1UL)
/* -----------------------  MFTP Specific Interrupt Numbers  ----------------------- */
#define WDGT_IRQn_Priority										(7)
#define TIMER_IRQn_Priority										(6)
#define DBG_I2C_IRQn_Priority									(0)
#define FLITF_IRQn_Priority										(6)
#define DBG_SPI_IRQn_Priority									(1)
#define AB_ACC_IRQn_Priority									(0)
#define GDMA_IRQn_Priority										(5)
#define USER_IRQn_Priority										(3)
#define GPIOA_IRQn_Priority										(5)
#define GPIOM_IRQn_Priority										(5)
#define VSYNC_IN_IRQn_Priority									(3)
#define TSYNC_IN_IRQn_Priority									(3)
#define TSYNC_OUT_IRQn_Priority									(3)
#define PWMDRV_IRQn_Priority									(3)
#define DSP_A_IRQn_Priority										(4)
#define DSP_B_IRQn_Priority										(5)//(4)		// For DSP_A Sync 4 -> 5
#define USB_IRQn_Priority										(1)//(0)
#define MSPI_IRQn_Priority										(1)
//#define SRIC_TRX_IRQn_Priority									(0)
#define TLVDS_IRQn_Priority										(1)
#define MPI_IRQn_Priority										(1)
//#define USB_SUSM_IRQn_Priority									(0)
//#define USB_LPMEN_IRQn_Priority									(0)
#define I2C_SLV_IRQn_Priority									(0)
#define I2C_SLV_Sleep_IRQn_Priority								(5)
#define I2C_SLV_Wakeup_IRQn_Priority							(5)
#define I2C_MST_IRQn_Priority									(0)
#define I2C_MST_Sleep_IRQn_Priority								(0)
#define I2C_MST_Wakeup_IRQn_Priority							(0)
#endif //(USED_MODULE_DEF == MODULE_DEF_L_1)

extern __IO uint32_t gMspiCounter;
extern __IO tHalInterruptHandle_t tHalIntrHandle;


extern void initBoardGPIO(void);
#if USED_MNT_S3_MODE_FUNCTION
extern void initMNT_S3_MODE_GPIO(void);
#endif /* USED_MNT_S3_MODE_FUNCTION */
extern void initECLK(void); // NOTE : 외부에서 참조

#if USED_VCF_SYNC_CONTROL
extern void initVcfGPIO(void);
extern void HAL_SetPrivacyEnControl(bool_t bIsEn);
extern bool_t HAL_GetPrivacyEnControl(void);
#endif /* USED_VCF_SYNC_CONTROL */

#if USED_ECLK_ON_OFF_CONTROL
extern void HAL_SetECLKOnOffControl(bool_t bIsEn);
extern bool_t HAL_GetECLKOnOffControl(void);
extern void HAL_ECLK_On(void);
extern void HAL_ECLK_Off(void);
#endif /* USED_ECLK_ON_OFF_CONTROL */

#if USED_TPIC_MUXEN_ON_OFF_CONTROL
extern void HAL_SetTPICMuxEnControl(bool_t bIsEn, bool_t bIsVCCOff);
extern bool_t HAL_GetTPICMuxEnControl(void);
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */

#if USED_S3_VDD_OE_INPUT_OUTPUT_CTRL
extern void HAL_Set_S3_VDD_OddEven_Ctrl(bool_t bIsEn);
extern bool_t HAL_Get_S3_VDD_OddEven_Ctrl(void);
extern void HAL_Change_S3_VDD_OddEven_Stauts(void);
#endif /* USED_S3_VDD_OE_INPUT_OUTPUT_CTRL */

#if USED_TOUCH_REPORT_ON_OFF_CONTROL
extern void HAL_SetTouchReportEnControl(bool_t bIsEn);
extern bool_t HAL_GetTouchReportEnControl(void);
#endif /* USED_TOUCH_REPORT_ON_OFF_CONTROL */

extern bool_t Hal_sric_start(bool_t cmuxoff); // NOTE : 외부에서 참조
extern void Hal_VccOff_State(void); // NOTE : 외부에서 참조
#if USED_TP_RST_OPERATION
extern void Hal_TPRSTOff_State(void);
#endif /* USED_TP_RST_OPERATION */
#define NVIC_INT_CTRL_REG		SCB->ICSR
#define NVIC_PENDSVSET_BIT		( 1UL << 28UL )

extern void callPendSV(void);


extern void HAL_Initialize(void);
extern void HAL_ConfigInit(bool_t bIsS3);
#if USED_PEN_MODE_OPERATION
extern void Interrupt_Init(void);
#endif /* USED_PEN_MODE_OPERATION */
extern void HAL_PendSVHandlerInitialize(void);
extern void SensingBufferInit(void);

extern eSENSING_CHANGE_MODE_t HAL_GetSensingChangeMode(void);
extern void HAL_SetSensingChangeMode(eSENSING_CHANGE_MODE_t mode);
extern eSENSING_MODE_t HAL_GetSensingMode(void);
extern void HAL_SetSensingMode(eSENSING_MODE_t mode);
extern eDIAG_TEST_CHANGE_MODE_t HAL_GetDiagTestSensingChangeMode(void);
extern void HAL_SetDiagTestSensingChangeMode(eDIAG_TEST_CHANGE_MODE_t mode);
extern eROIC_REG_SET_CHANGE_MODE_t HAL_GetROICRegSetChangeMode(void);
extern void HAL_SetROICRegSetChangeMode(eROIC_REG_SET_CHANGE_MODE_t mode);

extern bool_t HAL_CheckSensningModeChange(eSENSING_CHANGE_MODE_t mode);
extern uint16_t * HAL_GetBaseImagePointer(eSENSING_MODE_t mode, eBaseImageType_t type);

extern void HAL_SetActivePenChagneType(eActivePenChangeType_t eType);
extern bool_t HAL_CheckActivePenChangeType(void);
extern bool_t HAL_CheckActivePenTypeSwap(void);

#if USED_TPIC_VCOM_LEVEL_I2CM_CONTROL
extern void HAL_TPIC_UplinkModulation_LevelCtrl_Enable(void);
extern void HAL_TPIC_UplinkModulation_LevelCtrl_Disable(void);
#endif /* USED_TPIC_VCOM_LEVEL_I2CM_CONTROL */

extern void HAL_CheckBootInterfaceInfoOnSecurityRegion(void);
#if USED_LPWG_MCU_SLEEP
extern void Hal_WaitSampleDoneSleep(void);
extern void Hal_WaitModernStanbySleep(void);
#endif /* USED_LPWG_MCU_SLEEP */

#endif /* _HAL_H_ */
