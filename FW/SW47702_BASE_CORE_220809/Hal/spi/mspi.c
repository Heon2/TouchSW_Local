/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : mspi.c
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

#include "hal_def.h"
#include "module_def.h"


extern __IO uint16_t sensingRowStart;
#if USED_ADAPTIVE_LOCAL_SENSING
extern __IO uint16_t sensingRoicStart;
#endif /* USED_ADAPTIVE_LOCAL_SENSING */
__IO uint32_t gFrameCnt;

void MSPI_InterruptHandler(void)
{
	__IO static int nextMSPISize;
#if USED_PEN_MODE_OPERATION
	__IO uint32_t ulLocalIndexSetCheckBitMask = 0;
#endif /* USED_PEN_MODE_OPERATION */
#if USED_PEN_DATA_AFE_GAIN_OTHER_SET
	__IO uint32_t ulLocalDataGainSetCheckBitMask = 0;
#endif /* USED_PEN_DATA_AFE_GAIN_OTHER_SET */
	const tHalPwmdrvCommonConf_t * pktHalPwmdrvCommonConf = hal_pwmdrv_GetCommonConfig();
	const tHalMspiControlConf_t * tHalMSPIControlConf = hal_mspi_GetControlConfig();
	eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();

	if(SCRB->SYS_INT_ST.tBit.int_mspi != 0)
	{
		MSPI->tSINTRENCLR.ulBulk = 0x1F;
		switch(eSensingMode)
		{
#if USED_PEN_MODE_OPERATION
			case SM_FINGER_PEN_ACTIVE_FRQ_MAIN_MODE:
			case SM_FINGER_PEN_ACTIVE_FRQ_HOP1_MODE:
			case SM_FINGER_PEN_ACTIVE_FRQ_HOP2_MODE:
			{
				tHalIntrHandle.eLocalSensingType = tHalMSPIControlConf->ePenPartialIndex[tHalIntrHandle.ulMSPIPenModeIntrCnt];

				tHalIntrHandle.ulMSPIPenModeIntrCnt++;
				if(tHalIntrHandle.ulMSPIPenModeIntrCnt > tHalMSPIControlConf->MSPI_LHBCountNum)
				{
					tHalIntrHandle.ulMSPIPenModeIntrCnt = 0;
				}
				nextMSPISize = tHalIntrHandle.ulMSPIPenModeIntrCnt;
//				_gT(_GPIO_TP_INTR);

				hal_Info_SetControlActivePenRawDataType(hal_Info_GetControlActivePenOPType());
				if(tHalIntrHandle.ulLocalIndexChangeStart == 1)
				{
					if(nextMSPISize == 0)
					{
	#if IS_MULTI_PROTOCOL_OPERATION
						if(HAL_CheckSensningModeChange(HAL_GetSensingChangeMode()))
						{
							HAL_SetSensingChangeMode(SM_CHANGE_COMPLETE);
						}
						else
						{
							if(HAL_CheckActivePenTypeSwap())
							{
								if(HAL_CheckActivePenChangeType())
								{
									HAL_SetActivePenChagneType(ACTIVEPEN_CHANGE_DONE);
								}
							}
							else
							{
								SRIC_SetLocalIndex(((nextMSPISize << 16) | sensingRowStart));
							}
						}
	#else /* IS_MULTI_PROTOCOL_OPERATION */
						if(HAL_CheckSensningModeChange(HAL_GetSensingChangeMode()))
						{
							HAL_SetSensingChangeMode(SM_CHANGE_COMPLETE);
							MSPI_Set_BUFSIZE_FingerPenMode(nextMSPISize);
							break;
						}
	#endif /* IS_MULTI_PROTOCOL_OPERATION */
					}

	#if IS_MULTI_PROTOCOL_OPERATION
					switch(hal_Info_GetControlActivePenSettingType())
					{
						case ACTIVEPEN_TYPE_LOCAL_MS:
						{
							ulLocalIndexSetCheckBitMask = tHalIntrHandle.ulLocalPenRowIdxSetByMspiIdxBitMask_MSPen;
							break;
						}
						case ACTIVEPEN_TYPE_LOCAL_WACOM:
						{
							ulLocalIndexSetCheckBitMask = tHalIntrHandle.ulLocalPenRowIdxSetByMspiIdxBitMask_AITPen;
							break;
						}
						case ACTIVEPEN_TYPE_LOCAL_WGP:
						{
							ulLocalIndexSetCheckBitMask = tHalIntrHandle.ulLocalPenRowIdxSetByMspiIdxBitMask_WGPPen;
							break;
						}
					}

					if(ulLocalIndexSetCheckBitMask & (1<<nextMSPISize))
					{
						SRIC_SetLocalIndex(((nextMSPISize << 16) | sensingRowStart));
					}
	#else /* IS_MULTI_PROTOCOL_OPERATION */
					{
						uint32_t ulTempNextSPISize;
		#if USED_PEN_DATA_AFE_GAIN_OTHER_SET
						bool_t bIsSetLocalIdx = NO;
						uint32_t ulLocalIdxSetValue;
		#endif /* USED_PEN_DATA_AFE_GAIN_OTHER_SET */
						if(IS_ACTIVE_MODE(eSensingMode))
						{
							ulLocalIndexSetCheckBitMask = tHalIntrHandle.ulLocalPenRowIdxSetByMspiIdxBitMask[0];
		#if USED_PEN_DATA_AFE_GAIN_OTHER_SET
							ulLocalDataGainSetCheckBitMask = DEF_PEN_LOCAL_DATA_GAIN_SET_BIT_MASK_Idle;
		#endif /* USED_PEN_DATA_AFE_GAIN_OTHER_SET */
							ulTempNextSPISize = nextMSPISize;
						}
						else // Idle Mode
						{
							ulLocalIndexSetCheckBitMask = tHalIntrHandle.ulLocalPenRowIdxSetByMspiIdxBitMask[1];
							if(nextMSPISize == 3)
							{
								ulTempNextSPISize = nextMSPISize + 3;
							}
							else if(nextMSPISize == 6)
							{
								ulTempNextSPISize = nextMSPISize + 4;
							}
						}

		#if USED_PEN_DATA_AFE_GAIN_OTHER_SET
						if(ulLocalIndexSetCheckBitMask & (1<<nextMSPISize))
						{
							bIsSetLocalIdx = YES;
							ulLocalIdxSetValue = DEF_LOCAL_IDX_SET_ENABLE_BIT_MASK | (ulTempNextSPISize << 16) | sensingRowStart;
						}

						if(ulLocalDataGainSetCheckBitMask & (1<<nextMSPISize))
						{
							bIsSetLocalIdx = YES;
							ulLocalIdxSetValue |= (DEF_LOCAL_DATA_OTHER_SET_ENABLE_BIT_MASK | (ulTempNextSPISize << 16));
						}

						if(bIsSetLocalIdx)
						{
							SRIC_SetLocalIndex(ulLocalIdxSetValue);
						}
		#else /* USED_PEN_DATA_AFE_GAIN_OTHER_SET */
						if(ulLocalIndexSetCheckBitMask & (1<<nextMSPISize))
						{
							SRIC_SetLocalIndex(((ulTempNextSPISize << 16) | sensingRowStart));
						}
		#endif /* USED_PEN_DATA_AFE_GAIN_OTHER_SET */
					}
	#endif /* IS_MULTI_PROTOCOL_OPERATION */
				}

				MSPI_Set_BUFSIZE_FingerPenMode(nextMSPISize);
				callPendSV();
				break;
			}
#endif /* USED_PEN_MODE_OPERATION */
			case SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE:
			case SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE:
			case SM_FINGER_ONLY_ACTIVE_FRQ_HOP2_MODE:
			case SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_MAIN_MODE:
			case SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_HOP1_MODE:
			case SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_HOP2_MODE:
			{
#if !(((USED_MODULE_DEF == MODULE_DEF_B_1) || (USED_MODULE_DEF == MODULE_DEF_C_1)) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))
				tHalIntrHandle.ulMSPIPenModeIntrCnt++;
	#if USED_WGP_PEN_UHD_16LHB_OPERATION
				if(tHalIntrHandle.ulMSPIPenModeIntrCnt > 3)
	#else /* USED_WGP_PEN_UHD_16LHB_OPERATION */
				if(tHalIntrHandle.ulMSPIPenModeIntrCnt > 1)
	#endif /* USED_WGP_PEN_UHD_16LHB_OPERATION */
				{
					tHalIntrHandle.ulMSPIPenModeIntrCnt = 0;
				}
				nextMSPISize = tHalIntrHandle.ulMSPIPenModeIntrCnt;

//				_gT(_GPIO_TP_INTR);
				if(nextMSPISize == 0)
#endif /* !(((USED_MODULE_DEF == MODULE_DEF_B_1) || (USED_MODULE_DEF == MODULE_DEF_C_1)) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3)) */
				{
					if(HAL_CheckSensningModeChange(HAL_GetSensingChangeMode()))
					{
						HAL_SetSensingChangeMode(SM_CHANGE_COMPLETE);
					}
				}
				MSPI_Set_BUFSIZE_FingerPenMode(nextMSPISize);

				hal_set_irq_flag(IRQ_ID_FULL_SAMPLE);
				break;
			}
			case SM_FINGER_ONLY_IDLE_MODE:
			case SM_FINGER_PEN_IDLE_MODE:
			{
//				_gT(_GPIO_TP_INTR);
//				MSPI_Set_BUFSIZE_FingerPenMode(nextMSPISize);
#if USED_FULLSCAN_SWITCH_IDLE_TO_ACTIVE
				if(HAL_GetSensingChangeMode() != SM_CHANGE_FULLSCAN_IDLE_MODE)
				{
					if(HAL_CheckSensningModeChange(HAL_GetSensingChangeMode()))
					{
						HAL_SetSensingChangeMode(SM_CHANGE_COMPLETE);
						MSPI_Set_BUFSIZE_FingerPenMode(0);
					}
				}
#else /* USED_FULLSCAN_SWITCH_IDLE_TO_ACTIVE */
				if(HAL_CheckSensningModeChange(HAL_GetSensingChangeMode()))
				{
					HAL_SetSensingChangeMode(SM_CHANGE_COMPLETE);
					MSPI_Set_BUFSIZE_FingerPenMode(0);
				}
#endif /* USED_FULLSCAN_SWITCH_IDLE_TO_ACTIVE */
#if USED_LOCAL_IDLE_30Hz
				else
				{
					MSPI_Set_TLPMODE();
					/*
					 * ROIC Power Down!!
					 */
					MSPI_RegisterWrite((uint32_t)(0x01C0), 0);
					MSPI_Set_AITMODE(HAL_GetSensingMode());
					MSPI_Set_BUFSIZE_FingerPenMode(0);
				}
#endif /* USED_LOCAL_IDLE_30Hz */
				hal_set_irq_flag(IRQ_ID_NI_SAMPLE);
				break;
			}
			case SM_S3_ACTIVE_MODE:
			case SM_S3_IDLE_MODE:
			{
				hal_set_irq_flag(IRQ_ID_S3_SAMPLE);
				break;
			}
			default:
				break;
		}

#if ECLK_NEED_DURING_MSPI_OPERATION
		if(HAL_GetECLKOnOffControl())
		{
			HAL_ECLK_Off();
		}
#endif /* ECLK_NEED_DURING_MSPI_OPERATION */

		MSPI->SPIAITSTART = MSPI_START_VAL;
	}
}

void MSPI_Initialize(void)
{
	const tHalMspiCommonConf_t * kptHalMspiCommonConf;
	Fncp_MSPI_IRQHandler = &MSPI_InterruptHandler;
	kptHalMspiCommonConf = hal_mspi_GetCommonConfig();
	
	MSPI_GPIO_Init();
	
	MSPI->tSPIENA.ulBulk = kptHalMspiCommonConf->tParam_SPIENA.ulBulk;
	MSPI->tSPISCR.ulBulk = kptHalMspiCommonConf->tParam_SPISCR.ulBulk;

	MSPI->tSINTRENCLR.ulBulk = 0x1F;

	MSPI->tSINTRMSCR.tBit.intmux_en = DISABLE;
	MSPI->tSINTRMSCR.tBit.intframe_en = ENABLE;
	MSPI->tSINTRMSCR.tBit.introic_en = DISABLE;
	MSPI->tSINTRMSCR.tBit.intchksum_en = DISABLE;
	MSPI->tSINTRMSCR.tBit.intmisozero_en = DISABLE;

	SPI_ALL_ROIC_INTR_DISABLE_MASK(MSPI->tSINTRMASK.ulBulk);
	SPI_ALL_CHECKSUM_ERROR_INTR_DISABLE_MASK(MSPI->tSINTRMASK.ulBulk);
	SPI_ALL_MISOZERO_INTR_DISABLE_MASK(MSPI->tSINTRMASK.ulBulk);
}

void MSPI_ITConfig(FunctionalState NewState)
{
	NVIC_ClearPendingIRQ(EXTInterface_IRQn);
	NVIC_SetPriority(EXTInterface_IRQn, MSPI_IRQn_Priority);

	if(NewState != DISABLE)
	{
		NVIC_EnableIRQ(EXTInterface_IRQn);
	}
	else
	{
		NVIC_DisableIRQ(EXTInterface_IRQn);
	}
}

void MSPI_Cmd(FunctionalState NewState)
{
	if(NewState != DISABLE)
	{
		MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
	}
	else
	{
		MSPI->tSPISTART.ulBulk = 0;
	}
}

void MSPI_IntCLR(void)
{
	while(1)
	{
		if(MSPI->tSPISTART.ulBulk == 0x00)
		{
			break;
		}
	}
}

#if (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_MPP) || (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_MPP_Pen) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_SPLIT_MPP)

	#if USED_FINGER_2MUX_1LHB
		uint32_t sizeLut_MSPen[13] =
		{
			// Beacon	1 LHB
			6,//		2 LHB
			6,//		3 LHB
			6,//		4 LHB
			6,//		5 LHB
			6,//		6 LHB
			6,//		7 LHB
			// None		8 LHB
			// Beacon	9 LHB
			6,//		10 LHB
			2,//		11 LHB
			2,//		12 LHB
			2,//		13 LHB
			6,//		14 LHB
			2,//		15 LHB
			2,// 		16 LHB
		};
	#else /* USED_FINGER_2MUX_1LHB */
		uint32_t sizeLut_MSPen[12] =
		{
			// Beacon	1 LHB
			6,//		2 LHB
			6,//		3 LHB
			6,//		4 LHB
			6,//		5 LHB
			6,//		6 LHB
			6,//		7 LHB
			// None		8 LHB
			// Beacon	9 LHB
			6,//		10 LHB
			// None		11 LHB
			3,//		12 LHB
			3,//		13 LHB
			6,//		14 LHB
			3,//		15 LHB
			1,// 		16 LHB
		};
	#endif /* USED_FINGER_2MUX_1LHB */

#else
	uint32_t sizeLut_MSPen[11] =
	{
		// Beacon	1 LHB
		6,//		2 LHB
		6,//		3 LHB
		6,//		4 LHB
		6,//		5 LHB
		6,//		6 LHB
		6,//		7 LHB
		// None		8 LHB
		// Beacon	9 LHB
		6,//		10 LHB
	//	2,//		11 LHB
	//	2,//		12 LHB
		3,//2,//		13 LHB
		6,//		14 LHB
		3,//2,//		15 LHB
		3,//2,// 		16 LHB
	};
#endif

#if ((CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_MPP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_SPLIT_MPP))
	#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
	uint32_t sizeLut_WGP[14] =
	{
		// Beacon	1 LHB
		2,//		2 LHB
		//Dummy		3 LHB
		3,//		4 LHB
		2,//		5 LHB
		2,//		6 LHB
		8,//		7 LHB
		8,//		8 LHB
		3,//		9 LHB
		2,//		10 LHB
		3,//		11 LHB
		1,//		12 LHB
		2,//		13 LHB
		2,//		14 LHB
		8,//		15 LHB
		8,//		16 LHB
	};

	uint32_t sizeLut_UHD_WGP[7] =
	{
		// Beacon	1 LHB
		8,//		2 LHB
		2,//		3 LHB
		8,//		4 LHB
		3,//		5 LHB
		8,//		6 LHB
		3,//		7 LHB
		8,//		8 LHB
	};
	#else
	uint32_t sizeLut_WGP[13] =
	{
		// Beacon	1 LHB
		2,//		2 LHB
		//Dummy		3 LHB
		3,//		4 LHB
		2,//		5 LHB
		2,//		6 LHB
		7,//		7 LHB
		7,//		8 LHB
		3,//		9 LHB
		2,//		10 LHB
		3,//		11 LHB
		1,//		12 LHB
		2,//		13 LHB
		2,//		14 LHB
		7,//		15 LHB
		7,//		16 LHB
	};

	uint32_t sizeLut_UHD_WGP[7] =
	{
		// Beacon	1 LHB
		7,//		2 LHB
		2,//		3 LHB
		7,//		4 LHB
		3,//		5 LHB
		7,//		6 LHB
		3,//		7 LHB
		7,//		8 LHB
	};
	#endif
#elif (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_WGP_Pen) || (CUSTOMER == MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_WGP_Pen)
	#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
		uint32_t sizeLut_WGP[14] =
		{
			// Beacon	1 LHB
			2,//		2 LHB
			//Dummy		3 LHB
			3,//		4 LHB
			2,//		5 LHB
			2,//		6 LHB
			8,//		7 LHB
			8,//		8 LHB
			3,//		9 LHB
			2,//		10 LHB
			3,//		11 LHB
			1,//		12 LHB
			2,//		13 LHB
			2,//		14 LHB
			8,//		15 LHB
			8,//		16 LHB
		};

		uint32_t sizeLut_UHD_WGP[7] =
		{
			// Beacon	1 LHB
			8,//		2 LHB
			2,//		3 LHB
			8,//		4 LHB
			3,//		5 LHB
			8,//		6 LHB
			3,//		7 LHB
			8,//		8 LHB
		};
	#else
		uint32_t sizeLut_WGP[14] =
		{
				// Beacon	1 LHB
				2,//		2 LHB
				//Dummy		3 LHB
				3,//		4 LHB
				2,//		5 LHB
				2,//		6 LHB
				7,//		7 LHB
				7,//		8 LHB
				3,//		9 LHB
				2,//		10 LHB
				3,//		11 LHB
				1,//		12 LHB
				2,//		13 LHB
				2,//		14 LHB
				7,//		15 LHB
				7,//		16 LHB
		};

		uint32_t sizeLut_UHD_WGP[7] =
		{
			// Beacon	1 LHB
			7,//		2 LHB
			2,//		3 LHB
			7,//		4 LHB
			3,//		5 LHB
			7,//		6 LHB
			3,//		7 LHB
			7,//		8 LHB
		};
	#endif
#else /* (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) */
	#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
		uint32_t sizeLut_WGP[13] =
		{
			// Beacon	1 LHB
			2,//		2 LHB
			2,//		4 LHB
			2,//		5 LHB
			8,//3,//7,//		6 LHB
			8,//3,//7,//		7 LHB
			3,//		8 LHB
			2,//		9 LHB
			3,//		10 LHB
			3,//		11 LHB
			2,//		12 LHB
			2,//		13 LHB
			8,//3,//7,//		14 LHB
			8,//3,//7,//		15 LHB
		};

	#if (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_UHD_PEN)
		#if USED_WGP_PEN_UHD_16LHB_OPERATION
			uint32_t sizeLut_UHD_WGP[7] =
			{
				// Beacon	1 LHB
				8,//		2 LHB
				2,//		3 LHB
				8,//		4 LHB
				4,//3,//		5 LHB
				8,//		6 LHB
				4,//3,//		7 LHB
				8,//		8 LHB
				// Beacon	9 LHB
				8,//		10LHB
				2,//		11LHB
				8,//		12LHB
				2,//3,//		13LHB
				8,//		14LHB
				//1,//		15LHB
				8,//		16LHB
			};
		#else /* USED_WGP_PEN_UHD_16LHB_OPERATION */
			uint32_t sizeLut_UHD_WGP[7] =
			{
				// Beacon	1 LHB
				8,//		2 LHB
				2,//		3 LHB
				8,//		4 LHB
				5,//3,//		5 LHB
				8,//		6 LHB
				5,//3,//		7 LHB
				8,//		8 LHB
			};
		#endif /* USED_WGP_PEN_UHD_16LHB_OPERATION */
	#else /* (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_UHD_PEN) */
	uint32_t sizeLut_UHD_WGP[7] =
	{
		// Beacon	1 LHB
		8,//		2 LHB
		2,//		3 LHB
		8,//		4 LHB
		3,//		5 LHB
		8,//		6 LHB
		3,//		7 LHB
		8,//		8 LHB
	};
	#endif /* (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_UHD_PEN) */

	#else
	uint32_t sizeLut_WGP[13] =
	{
		// Beacon	1 LHB
		2,//		2 LHB
	//	3,//		3 LHB
		2,//		4 LHB
		2,//		5 LHB
		7,//3,//7,//		6 LHB
		7,//3,//7,//		7 LHB
		3,//		8 LHB
		2,//		9 LHB
		3,//		10 LHB
		3,//		11 LHB
		2,//		12 LHB
		2,//		13 LHB
		7,//3,//7,//		14 LHB
		7,//3,//7,//		15 LHB
	};

	uint32_t sizeLut_UHD_WGP[7] =
	{
		// Beacon	1 LHB
		7,//		2 LHB
		2,//		3 LHB
		7,//		4 LHB
		3,//		5 LHB
		7,//		6 LHB
		3,//		7 LHB
		7,//		8 LHB
	};
	#endif
#endif /* (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) */

#if  USED_LOCAL_IDLE_MODE_CONTROL
uint32_t sizeLut_WGP_IDLE[13] =
{
	// Beacon	1 LHB
	2,//		2 LHB
//	3,//		3 LHB
//	2,//		4 LHB
	2,//		5 LHB
//	7,//3,//7,//		6 LHB
//	7,//3,//7,//		7 LHB
	3,//3,//		8 LHB
	2,//		9 LHB
	3,//		10 LHB
	3,//		11 LHB
//	2,//		12 LHB
	2,//		13 LHB
//	7,//3,//7,//		14 LHB
//	7,//3,//7,//		15 LHB
};
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */

#if (USED_PEN_MODE_OPERATION && IS_WGPUHDPEN_PROTOCOL_OPERATION)
static void MSPI_Set_BUFSIZE_UHD_WGP_FingerPenMdoe_ActiveMode(int index)
{
	MSPI->SPIMUXNUM = sizeLut_UHD_WGP[index] - 1;
#if USED_SPI_NBIT_TRANSMODE
	#if USED_TOUCH_WGP_PREDRV_MUX_SENSING
	if(sizeLut_UHD_WGP[index] == 8 || sizeLut_UHD_WGP[index] == 2)
	#else
	if(sizeLut_UHD_WGP[index] == 7 || sizeLut_UHD_WGP[index] == 2)
	#endif
	{
		uint32_t iMspi;
		for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
		{
			MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);
			MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_LOCAL_PEN_MUXDATA>>1)-1;
	#if (SPI_TRANSFER_BIT_NUM == 10)
			MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 1;//3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
	#elif (SPI_TRANSFER_BIT_NUM == 11)
			MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 2;//3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
	#elif (SPI_TRANSFER_BIT_NUM == 12)
			MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 3;//3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
	#endif
			MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
			MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
			MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
			MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
		}
	#if USED_PEN_ROW_5Line_SCAN_SW98502
		MSPI->tSPITRSIZE0.tBit.spitrsize0 = 35;//SZ_MSPIBUF_MUXDATA+1; // SZ_MSPIBUF_LOCAL_PEN_MUXDATA
		MSPI->tSPITRSIZE0.tBit.spitrsize1 = 35;//SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE0.tBit.spitrsize3 = 35;//SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize4 = 35;//SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize6 = 35;//SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize7 = 35;//SZ_MSPIBUF_MUXDATA+1;

		MSPI->tSPIDATALEN.tBit.rxdata_len = 34;//(SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
	#endif /* USED_PEN_ROW_5Line_SCAN_SW98502 */

	#if (SPI_TRANSFER_BIT_NUM == 10)
		MSPI->tSPIDATALEN.tBit.rxbitlen = 19;
	#elif (SPI_TRANSFER_BIT_NUM == 11)
		MSPI->tSPIDATALEN.tBit.rxbitlen = 21; // 11bit
	#elif (SPI_TRANSFER_BIT_NUM == 12)
		MSPI->tSPIDATALEN.tBit.rxbitlen = 23; // 12bit
	#endif
	}
	else
	{
		uint32_t iMspi;
		for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
		{
			MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);
			MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_MUXDATA>>1)-1;
			MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
			MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
			MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
			MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
			MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
		}
	#if USED_PEN_ROW_5Line_SCAN_SW98502
		MSPI->tSPITRSIZE0.tBit.spitrsize0 = 63;//SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE0.tBit.spitrsize1 = 63;//SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE0.tBit.spitrsize3 = 63;//SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize4 = 63;//SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize6 = 63;//SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize7 = 63;//SZ_MSPIBUF_MUXDATA+1;

		MSPI->tSPIDATALEN.tBit.rxdata_len = 62;//(SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
	#endif /* USED_PEN_ROW_5Line_SCAN_SW98502 */

		MSPI->tSPIDATALEN.tBit.rxbitlen = 23; // 12bit
	}
#else /* USED_SPI_NBIT_TRANSMODE */
	#if (ROIC_ALIGNED_ROW_LEN != ROIC_ALIGNED_LOCAL_PEN_ROW_LEN)
	if(sizeLut_UHD_WGP[index] == 7 || sizeLut_UHD_WGP[index] == 2)
	{
		uint32_t iMspi;
		for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
		{
			MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);
			MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_LOCAL_PEN_MUXDATA>>1);
			MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
			MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
			MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
			MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
			MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
		}

		MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_LOCAL_PEN_MUXDATA+1;
		MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_LOCAL_PEN_MUXDATA+1;
		MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_LOCAL_PEN_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_LOCAL_PEN_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize6 = SZ_MSPIBUF_LOCAL_PEN_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize7 = SZ_MSPIBUF_LOCAL_PEN_MUXDATA+1;
		MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_LOCAL_PEN_MUXDATA - SPI_DMY_LEN) + 1;
	}
	else
	{
		uint32_t iMspi;
		for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
		{
			MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);
			MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_MUXDATA>>1);
			MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
			MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
			MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
			MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
			MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
		}

		MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize6 = SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPITRSIZE1.tBit.spitrsize7 = SZ_MSPIBUF_MUXDATA+1;
		MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
	}
	#endif /* (ROIC_ALIGNED_ROW_LEN != ROIC_ALIGNED_LOCAL_PEN_ROW_LEN) */
#endif /* USED_SPI_NBIT_TRANSMODE */
}
#endif /* (USED_PEN_MODE_OPERATION && IS_WGPUHDPEN_PROTOCOL_OPERATION) */

void MSPI_Set_BUFSIZE_FingerPenMode(int index)
{
	eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();

#if USED_PEN_MODE_OPERATION

	#if IS_MULTI_PROTOCOL_OPERATION
	{
		switch(hal_Info_GetControlActivePenSettingType())
		{
			case ACTIVEPEN_TYPE_LOCAL_MS:
			{
				if(IS_FINGER_PEN_MODE(eSensingMode))
				{
					MSPI->SPIMUXNUM = sizeLut_MSPen[index]-1;
				}
				else
				{
					MSPI->SPIMUXNUM = FINGER_MUX_NUM-1;
				}
				MSPI->tMSPI_FINDEX0.tBit.findex0 = 0;//sizeLut_MSPen[index];
				break;
			}
			case ACTIVEPEN_TYPE_LOCAL_WGP:
			{
				if(IS_FINGER_PEN_MODE(eSensingMode))
				{
		#if  USED_LOCAL_IDLE_MODE_CONTROL
			#if IS_WGPUHDPEN_PROTOCOL_OPERATION
					if(IS_ACTIVE_MODE(eSensingMode))
					{
						MSPI_Set_BUFSIZE_UHD_WGP_FingerPenMdoe_ActiveMode(index);
					}
					else
					{
						uint32_t iMspi;
						MSPI->SPIMUXNUM = USED_IDLE_NI_SENSING_MUX_NUM-1;
						for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
						{
							MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);
							MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_MUXDATA>>1)-1;
							MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
							MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
							MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
							MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
							MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
						}
						MSPI->tSPIDATALEN.tBit.rxbitlen = 23;
					}
			#else /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
					if(IS_ACTIVE_MODE(eSensingMode))
					{
						MSPI->SPIMUXNUM = sizeLut_WGP[index]-1;
					}
					else
					{
						MSPI->SPIMUXNUM = USED_IDLE_NI_SENSING_MUX_NUM-1;
					}
			#endif /* IS_WGPUHDPEN_PROTOCOL_OPERATION */
		#else /* USED_LOCAL_IDLE_MODE_CONTROL */
			#if IS_WGPUHDPEN_PROTOCOL_OPERATION
					MSPI_Set_BUFSIZE_UHD_WGP_FingerPenMdoe_ActiveMode(index);
			#else /* USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN */
					MSPI->SPIMUXNUM = sizeLut_WGP[index] - 1;
			#endif /* USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN */
		#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
					MSPI->tMSPI_FINDEX0.tBit.findex0 = 0;
				}
				else
				{
					// _gT(_GPIO_TP_INTR);
					MSPI->SPIMUXNUM = FINGER_MUX_NUM-1;
		#if (IS_WGPUHDPEN_PROTOCOL_OPERATION && (ROIC_ALIGNED_ROW_LEN != ROIC_ALIGNED_LOCAL_PEN_ROW_LEN))
					MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPITRSIZE1.tBit.spitrsize6 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPITRSIZE1.tBit.spitrsize7 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
		#endif /* (IS_WGPUHDPEN_PROTOCOL_OPERATION && (ROIC_ALIGNED_ROW_LEN != ROIC_ALIGNED_LOCAL_PEN_ROW_LEN)) */
					MSPI->tMSPI_FINDEX0.tBit.findex0 = 0;//sizeLut_Wacom[index];
				}
				break;
			}
		}
	}

	#else /* IS_MULTI_PROTOCOL_OPERATION */
		#if IS_WGPPEN_PROTOCOL_OPERATION
			{
				if(IS_FINGER_PEN_MODE(eSensingMode))
				{
		#if  USED_LOCAL_IDLE_MODE_CONTROL
					if(IS_ACTIVE_MODE(eSensingMode))
					{
						MSPI->SPIMUXNUM = sizeLut_WGP[index]-1;
					}
					else
					{
						MSPI->SPIMUXNUM = USED_IDLE_NI_SENSING_MUX_NUM-1;
					}
		#else /* USED_LOCAL_IDLE_MODE_CONTROL */
					MSPI->SPIMUXNUM = sizeLut_WGP[index] - 1;
		#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
					MSPI->tMSPI_FINDEX0.tBit.findex0 = 0;
				}
				else
				{
					// _gT(_GPIO_TP_INTR);
					MSPI->SPIMUXNUM = FINGER_MUX_NUM-1;
					MSPI->tMSPI_FINDEX0.tBit.findex0 = 0;//sizeLut_Wacom[index];
				}
			}
		#elif IS_WGPUHDPEN_PROTOCOL_OPERATION
			{
				if(IS_FINGER_PEN_MODE(eSensingMode))
				{
			#if  USED_LOCAL_IDLE_MODE_CONTROL
					if(IS_ACTIVE_MODE(eSensingMode))
					{
						MSPI_Set_BUFSIZE_UHD_WGP_FingerPenMdoe_ActiveMode(index);
					}
					else
					{
						uint32_t iMspi;
				#if (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_UHD_PEN)
						MSPI->SPIMUXNUM = USED_IDLE_NI_SENSING_MUX_NUM-1;
						for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
						{
							MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);
							MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_MUXDATA>>1);
							MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
							MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
							MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
							MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
							MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
						}
				#else /* (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_UHD_PEN) */
						MSPI->SPIMUXNUM = USED_IDLE_NI_SENSING_MUX_NUM-1;
						for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
						{
							MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);
							MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_MUXDATA>>1)-1;
							MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
							MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
							MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
							MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
							MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
						}
						MSPI->tSPIDATALEN.tBit.rxbitlen = 23;
				#endif /* (CUSTOMER == MODEL_DEF_QHD_92512_Dell_WGP_UHD_PEN) */
					}
			#else /* USED_LOCAL_IDLE_MODE_CONTROL */
					MSPI_Set_BUFSIZE_UHD_WGP_FingerPenMdoe_ActiveMode(index);
			#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
					MSPI->tMSPI_FINDEX0.tBit.findex0 = 0;
				}
				else
				{
					// _gT(_GPIO_TP_INTR);
					MSPI->SPIMUXNUM = FINGER_MUX_NUM-1;
			#if (IS_WGPUHDPEN_PROTOCOL_OPERATION && (ROIC_ALIGNED_ROW_LEN != ROIC_ALIGNED_LOCAL_PEN_ROW_LEN))
					MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPITRSIZE1.tBit.spitrsize6 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPITRSIZE1.tBit.spitrsize7 = SZ_MSPIBUF_MUXDATA+1;
					MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			#endif /* (IS_WGPUHDPEN_PROTOCOL_OPERATION && (ROIC_ALIGNED_ROW_LEN != ROIC_ALIGNED_LOCAL_PEN_ROW_LEN)) */
					MSPI->tMSPI_FINDEX0.tBit.findex0 = 0;//sizeLut_Wacom[index];
				}
			}
		#elif IS_MSPEN_PROTOCOL_OPERATION
			{
				if(IS_FINGER_PEN_MODE(eSensingMode))
				{
					MSPI->SPIMUXNUM = sizeLut_MSPen[index]-1;
				}
				else
				{
					MSPI->SPIMUXNUM = FINGER_MUX_NUM-1;
				}
				MSPI->tMSPI_FINDEX0.tBit.findex0 = 0;
			}
		#endif
	#endif /* IS_MULTI_PROTOCOL_OPERATION */

#else /* USED_PEN_MODE_OPERATION */
	#if USED_MNT_S3_MODE_FUNCTION
	if(IS_S3_MODE(eSensingMode))
	{
		MSPI->SPIMUXNUM = FINGER_IDLE_NI_MUX_NUM-1;
	}
	else
	#endif /* USED_MNT_S3_MODE_FUNCTION */
	{
		if(IS_ACTIVE_MODE(eSensingMode))
		{
			MSPI->SPIMUXNUM = FINGER_MUX_NUM-1;
			MSPI->tSINTRMSCR.tBit.intmux_en = DISABLE;
			MSPI->tSINTRMSCR.tBit.intframe_en = ENABLE;
		}
		else
		{
			if(FINGER_IDLE_NI_MUX_NUM-1 <= 0)
			{
				MSPI->tSINTRMSCR.tBit.intmux_en = ENABLE;
				MSPI->tSINTRMSCR.tBit.intframe_en = DISABLE;
			}
			else
			{
				MSPI->SPIMUXNUM = FINGER_IDLE_NI_MUX_NUM-1;
				MSPI->tSINTRMSCR.tBit.intmux_en = DISABLE;
				MSPI->tSINTRMSCR.tBit.intframe_en = ENABLE;
			}
		}
	}

	MSPI->tMSPI_FINDEX0.tBit.findex0 = 0;
#endif /* USED_PEN_MODE_OPERATION */
}

void MSPI_GPIO_Init(void)
{
	const tHalMspiCommonConf_t * kptHalMspiCommonConf;
	kptHalMspiCommonConf = hal_mspi_GetCommonConfig();
	uint32_t ulMSPI_0_En;
	uint32_t ulMSPI_1_En;
	uint32_t ulMSPI_2_En;
	uint32_t ulMSPI_3_En;
	uint32_t ulMSPI_4_En;
	uint32_t ulMSPI_5_En;
	uint32_t ulMSPI_6_En;
	uint32_t ulMSPI_7_En;

	ulMSPI_0_En = kptHalMspiCommonConf->tParam_SPIENA.tBit.spiTxEna0;
	ulMSPI_1_En = kptHalMspiCommonConf->tParam_SPIENA.tBit.spiTxEna1;
	ulMSPI_2_En = kptHalMspiCommonConf->tParam_SPIENA.tBit.spiTxEna2;
	ulMSPI_3_En = kptHalMspiCommonConf->tParam_SPIENA.tBit.spiTxEna3;
	ulMSPI_4_En = kptHalMspiCommonConf->tParam_SPIENA.tBit.spiTxEna4;
	ulMSPI_5_En = kptHalMspiCommonConf->tParam_SPIENA.tBit.spiTxEna5;
	ulMSPI_6_En = kptHalMspiCommonConf->tParam_SPIENA.tBit.spiTxEna6;
	ulMSPI_7_En = kptHalMspiCommonConf->tParam_SPIENA.tBit.spiTxEna7;

	/////////////////////////////////////////////////////////////////////////////////
	// MSPI GPIO Initialization
	/////////////////////////////////////////////////////////////////////////////////
	if(ulMSPI_0_En == SPI_DISABLE)
	{
		GPIO_Init(_GPIO_MSPI_0_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_0_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_0_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_0_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);


		GPIO_Set_PE(_GPIO_MSPI_0_CSN, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_0_CLK, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_0_MOSI, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_0_MISO, GPIO_PE_PULL_DOWM);
	}
	else
	{
		GPIO_Set_Mode(_GPIO_MSPI_0_CSN, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_0_CLK, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_0_MOSI, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_0_MISO, GPIO_MODE_FUNC_0);

		GPIO_Set_DS(_GPIO_MSPI_0_CSN, PARAMSET_MSPI_0_CSN_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_0_CLK, PARAMSET_MSPI_0_CLK_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_0_MOSI, PARAMSET_MSPI_0_MOSI_DRVSTR_LEVEL);
	}

	if(ulMSPI_1_En == SPI_DISABLE)
	{
		GPIO_Init(_GPIO_MSPI_1_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_1_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_1_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_1_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

		GPIO_Set_PE(_GPIO_MSPI_1_CSN, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_1_CLK, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_1_MOSI, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_1_MISO, GPIO_PE_PULL_DOWM);
	}
	else
	{
		GPIO_Set_Mode(_GPIO_MSPI_1_CSN, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_1_CLK, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_1_MOSI, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_1_MISO, GPIO_MODE_FUNC_0);

		GPIO_Set_DS(_GPIO_MSPI_1_CSN, PARAMSET_MSPI_1_CSN_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_1_CLK, PARAMSET_MSPI_1_CLK_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_1_MOSI, PARAMSET_MSPI_1_MOSI_DRVSTR_LEVEL);
	}

	if(ulMSPI_2_En == SPI_DISABLE)
	{
		GPIO_Init(_GPIO_MSPI_2_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_2_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_2_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_2_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

		GPIO_Set_PE(_GPIO_MSPI_2_CSN, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_2_CLK, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_2_MOSI, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_2_MISO, GPIO_PE_PULL_DOWM);
	}
	else
	{
		GPIO_Set_Mode(_GPIO_MSPI_2_CSN, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_2_CLK, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_2_MOSI, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_2_MISO, GPIO_MODE_FUNC_0);

		GPIO_Set_DS(_GPIO_MSPI_2_CSN, PARAMSET_MSPI_2_CSN_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_2_CLK, PARAMSET_MSPI_2_CLK_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_2_MOSI, PARAMSET_MSPI_2_MOSI_DRVSTR_LEVEL);
	}

	if(ulMSPI_3_En == SPI_DISABLE)
	{
		GPIO_Init(_GPIO_MSPI_3_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_3_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_3_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_3_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

		GPIO_Set_PE(_GPIO_MSPI_3_CSN, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_3_CLK, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_3_MOSI, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_3_MISO, GPIO_PE_PULL_DOWM);
	}
	else
	{
		GPIO_Set_Mode(_GPIO_MSPI_3_CSN, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_3_CLK, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_3_MOSI, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_3_MISO, GPIO_MODE_FUNC_0);

		GPIO_Set_DS(_GPIO_MSPI_3_CSN, PARAMSET_MSPI_3_CSN_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_3_CLK, PARAMSET_MSPI_3_CLK_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_3_MOSI, PARAMSET_MSPI_3_MOSI_DRVSTR_LEVEL);
	}

	if(ulMSPI_4_En == SPI_DISABLE)
	{
		GPIO_Init(_GPIO_MSPI_4_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_4_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_4_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_4_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

		GPIO_Set_PE(_GPIO_MSPI_4_CSN, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_4_CLK, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_4_MOSI, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_4_MISO, GPIO_PE_PULL_DOWM);
	}
	else
	{
		GPIO_Set_Mode(_GPIO_MSPI_4_CSN, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_4_CLK, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_4_MOSI, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_4_MISO, GPIO_MODE_FUNC_0);

		GPIO_Set_DS(_GPIO_MSPI_4_CSN, PARAMSET_MSPI_4_CSN_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_4_CLK, PARAMSET_MSPI_4_CLK_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_4_MOSI, PARAMSET_MSPI_4_MOSI_DRVSTR_LEVEL);
	}

	if(ulMSPI_5_En == SPI_DISABLE)
	{
		GPIO_Init(_GPIO_MSPI_5_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#if !USED_TPIC_PENEN_ON_OFF_CONTROL
		GPIO_Init(_GPIO_MSPI_5_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif
#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	#if (USED_PCB_PINMAP != SHARP_NBPC_PIN_TYPE_S01)
		GPIO_Init(_GPIO_MSPI_5_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#endif /* (USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S01) */
#elif (USED_MODULE_DEF == MODULE_DEF_A_1)
		GPIO_Init(_GPIO_MSPI_5_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
		GPIO_Init(_GPIO_MSPI_5_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
		GPIO_Init(_GPIO_MSPI_5_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

		GPIO_Set_PE(_GPIO_MSPI_5_CSN, GPIO_PE_PULL_DOWM);
#if !USED_TPIC_PENEN_ON_OFF_CONTROL
		GPIO_Set_PE(_GPIO_MSPI_5_CLK, GPIO_PE_PULL_DOWM);
#endif

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	#if (USED_PCB_PINMAP != SHARP_NBPC_PIN_TYPE_S01)
		GPIO_Set_PE(_GPIO_MSPI_5_MOSI, GPIO_PE_PULL_DOWM);
	#endif /* (USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S01) */
#elif (USED_MODULE_DEF == MODULE_DEF_A_1)
		GPIO_Set_PE(_GPIO_MSPI_5_MOSI, GPIO_PE_PULL_DOWM);
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
		GPIO_Set_PE(_GPIO_MSPI_5_MOSI, GPIO_PE_PULL_DOWM);
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
		GPIO_Set_PE(_GPIO_MSPI_5_MISO, GPIO_PE_PULL_DOWM);
	}
	else
	{
		GPIO_Set_Mode(_GPIO_MSPI_5_CSN, GPIO_MODE_FUNC_0);
#if !USED_TPIC_PENEN_ON_OFF_CONTROL
		GPIO_Set_Mode(_GPIO_MSPI_5_CLK, GPIO_MODE_FUNC_0);
#endif

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	#if (USED_PCB_PINMAP != SHARP_NBPC_PIN_TYPE_S01)
		GPIO_Set_Mode(_GPIO_MSPI_5_MOSI, GPIO_MODE_FUNC_0);
	#endif /* (USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S01) */
#elif (USED_MODULE_DEF == MODULE_DEF_A_1)
		GPIO_Set_Mode(_GPIO_MSPI_5_MOSI, GPIO_MODE_FUNC_0);
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
		GPIO_Set_Mode(_GPIO_MSPI_5_MOSI, GPIO_MODE_FUNC_0);
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
		GPIO_Set_Mode(_GPIO_MSPI_5_MISO, GPIO_MODE_FUNC_0);

		GPIO_Set_DS(_GPIO_MSPI_5_CSN, PARAMSET_MSPI_5_CSN_DRVSTR_LEVEL);
#if !USED_TPIC_PENEN_ON_OFF_CONTROL
		GPIO_Set_DS(_GPIO_MSPI_5_CLK, PARAMSET_MSPI_5_CLK_DRVSTR_LEVEL);
#endif

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	#if (USED_PCB_PINMAP != SHARP_NBPC_PIN_TYPE_S01)
		GPIO_Set_DS(_GPIO_MSPI_5_MOSI, PARAMSET_MSPI_5_MOSI_DRVSTR_LEVEL);
	#endif /* (USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S01) */
#elif (USED_MODULE_DEF == MODULE_DEF_A_1)
		GPIO_Set_DS(_GPIO_MSPI_5_MOSI, PARAMSET_MSPI_5_MOSI_DRVSTR_LEVEL);
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

		GPIO_Set_DS(_GPIO_MSPI_5_MOSI, PARAMSET_MSPI_5_MOSI_DRVSTR_LEVEL);
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	}

	if(ulMSPI_6_En == SPI_DISABLE)
	{
		GPIO_Init(_GPIO_MSPI_6_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_6_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#if ((!(((USED_MODULE_DEF == MODULE_DEF_B_1) || (USED_MODULE_DEF == MODULE_DEF_C_1)) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))) && (!USED_GPIO_MSPI_6_IS_MUX_EN)) && \
		!((USED_MODULE_DEF == MODULE_DEF_T_1)) && !((USED_MODULE_DEF == MODULE_DEF_B_1) && ((CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_MPP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_SPLIT_MPP))) && \
		!(USED_MODULE_DEF == MODULE_DEF_A_1)
		GPIO_Init(_GPIO_MSPI_6_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
#endif /* (!(((USED_MODULE_DEF == MODULE_DEF_B_1) || (USED_MODULE_DEF == MODULE_DEF_C_1)) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))) */
		GPIO_Init(_GPIO_MSPI_6_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

		GPIO_Set_PE(_GPIO_MSPI_6_CSN, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_6_CLK, GPIO_PE_PULL_DOWM);
#if ((!(((USED_MODULE_DEF == MODULE_DEF_B_1) || (USED_MODULE_DEF == MODULE_DEF_C_1)) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))) && (!USED_GPIO_MSPI_6_IS_MUX_EN)) && \
		!((USED_MODULE_DEF == MODULE_DEF_T_1)) && !((USED_MODULE_DEF == MODULE_DEF_B_1) && ((CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_MPP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_SPLIT_MPP))) && \
		!(USED_MODULE_DEF == MODULE_DEF_A_1)
		GPIO_Set_PE(_GPIO_MSPI_6_MOSI, GPIO_PE_PULL_DOWM);
#endif /* (!((USED_MODULE_DEF == MODULE_DEF_B_1 || (USED_MODULE_DEF == MODULE_DEF_C_1)) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))) */
		GPIO_Set_PE(_GPIO_MSPI_6_MISO, GPIO_PE_PULL_DOWM);
	}
	else
	{
		GPIO_Set_Mode(_GPIO_MSPI_6_CSN, GPIO_MODE_FUNC_0);	// 0:GPIO, 1:MSPI5_MST_SSN
		GPIO_Set_Mode(_GPIO_MSPI_6_CLK, GPIO_MODE_FUNC_0);	// 0:GPIO, 1:MSPI5_MST_SCLK
#if ((!(((USED_MODULE_DEF == MODULE_DEF_B_1) || (USED_MODULE_DEF == MODULE_DEF_C_1)) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))) && (!USED_GPIO_MSPI_6_IS_MUX_EN)) && \
		!((USED_MODULE_DEF == MODULE_DEF_T_1)) && !((USED_MODULE_DEF == MODULE_DEF_B_1) && ((CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_MPP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_SPLIT_MPP))) && \
		!(USED_MODULE_DEF == MODULE_DEF_A_1)
		GPIO_Set_Mode(_GPIO_MSPI_6_MOSI, GPIO_MODE_FUNC_0);	// 0:GPIO, 1:MSPI5_MST_MOSI
#endif /* (!(((USED_MODULE_DEF == MODULE_DEF_B_1) || (USED_MODULE_DEF == MODULE_DEF_C_1)) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))) */
		GPIO_Set_Mode(_GPIO_MSPI_6_MISO, GPIO_MODE_FUNC_0);	// 0:GPIO, 1:MSPI5_MST_MISO

		GPIO_Set_DS(_GPIO_MSPI_6_CSN, PARAMSET_MSPI_6_CSN_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_6_CLK, PARAMSET_MSPI_6_CLK_DRVSTR_LEVEL);
#if ((!(((USED_MODULE_DEF == MODULE_DEF_B_1) || (USED_MODULE_DEF == MODULE_DEF_C_1)) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))) && (!USED_GPIO_MSPI_6_IS_MUX_EN)) && \
		!((USED_MODULE_DEF == MODULE_DEF_T_1)) && !((USED_MODULE_DEF == MODULE_DEF_B_1) && ((CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_MPP) || (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_SPLIT_MPP))) && \
		!(USED_MODULE_DEF == MODULE_DEF_A_1)
		GPIO_Set_DS(_GPIO_MSPI_6_MOSI, PARAMSET_MSPI_6_MOSI_DRVSTR_LEVEL);
#endif /* (!(((USED_MODULE_DEF == MODULE_DEF_B_1) || (USED_MODULE_DEF == MODULE_DEF_C_1)) && (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3))) */
	}

	if(ulMSPI_7_En == SPI_DISABLE)
	{
		GPIO_Init(_GPIO_MSPI_7_CSN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
		GPIO_Init(_GPIO_MSPI_7_CLK, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#if !USED_PWM_GATE_CONTROL
		GPIO_Init(_GPIO_MSPI_7_MOSI, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);
	#endif
		GPIO_Init(_GPIO_MSPI_7_MISO, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_LOW);

		GPIO_Set_PE(_GPIO_MSPI_7_CSN, GPIO_PE_PULL_DOWM);
		GPIO_Set_PE(_GPIO_MSPI_7_CLK, GPIO_PE_PULL_DOWM);
	#if !USED_PWM_GATE_CONTROL
		GPIO_Set_PE(_GPIO_MSPI_7_MOSI, GPIO_PE_PULL_DOWM);
	#endif
		GPIO_Set_PE(_GPIO_MSPI_7_MISO, GPIO_PE_PULL_DOWM);
	}
	else
	{
		GPIO_Set_Mode(_GPIO_MSPI_7_CSN, GPIO_MODE_FUNC_0);
		GPIO_Set_Mode(_GPIO_MSPI_7_CLK, GPIO_MODE_FUNC_0);
	#if !USED_PWM_GATE_CONTROL
		GPIO_Set_Mode(_GPIO_MSPI_7_MOSI, GPIO_MODE_FUNC_0);
	#endif
		GPIO_Set_Mode(_GPIO_MSPI_7_MISO, GPIO_MODE_FUNC_0);

		GPIO_Set_DS(_GPIO_MSPI_7_CSN, PARAMSET_MSPI_7_CSN_DRVSTR_LEVEL);
		GPIO_Set_DS(_GPIO_MSPI_7_CLK, PARAMSET_MSPI_7_CLK_DRVSTR_LEVEL);
	#if !USED_PWM_GATE_CONTROL
		GPIO_Set_DS(_GPIO_MSPI_7_MOSI, PARAMSET_MSPI_7_MOSI_DRVSTR_LEVEL);
	#endif
	}
	GPIO_Set_PE(_GPIO_MSPI_0_MISO, GPIO_PE_PULL_DOWM);
	GPIO_Set_PE(_GPIO_MSPI_1_MISO, GPIO_PE_PULL_DOWM);
	GPIO_Set_PE(_GPIO_MSPI_2_MISO, GPIO_PE_PULL_DOWM);
	GPIO_Set_PE(_GPIO_MSPI_3_MISO, GPIO_PE_PULL_DOWM);
	GPIO_Set_PE(_GPIO_MSPI_4_MISO, GPIO_PE_PULL_DOWM);
	GPIO_Set_PE(_GPIO_MSPI_5_MISO, GPIO_PE_PULL_DOWM);
	GPIO_Set_PE(_GPIO_MSPI_6_MISO, GPIO_PE_PULL_DOWM);
	GPIO_Set_PE(_GPIO_MSPI_7_MISO, GPIO_PE_PULL_DOWM);
}

void MSPI_Set_TLPMODE(void)
{
#if USED_SSCG_ON_OFF_CONTORL_AITnTLP_MODE
	SCRB->SSCG_IN_CFG.tBit.sscgclk_sel = 0;	// SSCGCLK select. 0: no sscg, 1:sscg out
#endif

	MSPI->tSPIMODE.tBit.aitmode 			= SPI_MODE_TLPMODE;

	MSPI->tSPISCR.tBit.BITLEN 				= SPI_BITLEN_HALF_WORD;
    MSPI->tSPISCR.tBit.DUALACC 				= SPI_RX_SINGLE_MODE;
    MSPI->tSPISCR.tBit.DUALBITORD 			= SPI_RX_DUAL_BIT_ORDER_MOSI_MISO;
    MSPI->tSPISCR.tBit.TXDORD 				= SPI_DATA_ORDER_MSB_FIRST;
    MSPI->tSPISCR.tBit.RXDORD 				= SPI_DATA_ORDER_MSB_FIRST;
    MSPI->tSPISCR.tBit.TXCHKSUM_EN			= SPI_CHECK_SUM_DISABLE;
    MSPI->tSPISCR.tBit.RXCHKSUM_EN			= SPI_CHECK_SUM_DISABLE;
    MSPI->tSPISCR.tBit.RXPOS 				= PARAMSET_MSPI_RX_POS;
#if (USED_ROIC_DEF == ROIC_SW97500)
    MSPI->tSPISCR.tBit.SCLKDIV 				= SPI_SCLK_SPEED_7_DIV;
#else /* (USED_ROIC_DEF == ROIC_SW97500) */
    MSPI->tSPISCR.tBit.SCLKDIV 				= SPI_SCLK_SPEED_3_DIV;
#endif /* (USED_ROIC_DEF == ROIC_SW97500) */
    MSPI->tSPISCR.tBit.MISO_ZERO_CHK_EN 	= DISABLE;

	MSPI->tSPIDATALEN.tBit.rxbitlen			= 15;
	MSPI->tSPIDATALEN.tBit.txbitlen			= 15;
	/*
	 * rxdata_len and txdata_len do not update in here!
	 * That update at read and write.
	 */
//	MSPI->tSPIDATALEN.tBit.rxdata_len		= 0x0;
//	MSPI->tSPIDATALEN.tBit.txdata_len		= 0x2;

	MSPI->tSPISTATELEN.tBit.PreShftLen		= 16;
	MSPI->tSPISTATELEN.tBit.TmpIdleLen		= 2;
	MSPI->tSPISTATELEN.tBit.PostShftLen  	= 15;
	MSPI->tSPISTATELEN.tBit.txbufnum 		= 7;
}

#if (USED_ROIC_DEF == ROIC_SW97500)
uint32_t ulTestMSPI_1ReadBuff;
uint32_t ulTestMSPI_2ReadBuff;
uint32_t ulTestMSPI_3ReadBuff;
uint32_t ulTestMSPI_4ReadBuff;

uint32_t ulTestMSPI_1ReadBuff_REG;
uint32_t ulTestMSPI_2ReadBuff_REG;
uint32_t ulTestMSPI_3ReadBuff_REG;
uint32_t ulTestMSPI_4ReadBuff_REG;

uint32_t ulTestMSPI_1WriteBuff;
uint32_t ulTestMSPI_2WriteBuff;
uint32_t ulTestMSPI_3WriteBuff;
uint32_t ulTestMSPI_4WriteBuff;

uint32_t ulTestMSPI_1WriteBuff_REG;
uint32_t ulTestMSPI_2WriteBuff_REG;
uint32_t ulTestMSPI_3WriteBuff_REG;
uint32_t ulTestMSPI_4WriteBuff_REG;


void MSPI_Set_AITMODE(eSENSING_MODE_t eSensingMode)
{
	uint8_t iMspi;

#if USED_SSCG_ON_OFF_CONTORL_AITnTLP_MODE
	SCRB->SSCG_IN_CFG.tBit.sscgclk_sel = 1;	// SSCGCLK select. 0: no sscg, 1:sscg out
#endif

#if USED_MSPEN_MSPI_24BIT_TRANSMODE
	MSPI->tSPISCR.tBit.BITLEN 				= SPI_BITLEN_WORD;
#else /* USED_MSPEN_MSPI_24BIT_TRANSMODE */
	MSPI->tSPISCR.tBit.BITLEN 				= SPI_BITLEN_HALF_WORD;
#endif /* USED_MSPEN_MSPI_24BIT_TRANSMODE */

    MSPI->tSPISCR.tBit.DUALACC 				= SPI_RX_SINGLE_MODE;//SPI_RX_SINGLE_MODE;//SPI_RX_DUAL_MODE;//SPI_RX_SINGLE_MODE;
    MSPI->tSPISCR.tBit.DUALBITORD 			= SPI_RX_DUAL_BIT_ORDER_MOSI_MISO;//SPI_RX_DUAL_BIT_ORDER_MISO_MOSI;//SPI_RX_DUAL_BIT_ORDER_MOSI_MISO;
    MSPI->tSPISCR.tBit.TXDORD 				= SPI_DATA_ORDER_MSB_FIRST;
    MSPI->tSPISCR.tBit.RXDORD 				= SPI_DATA_ORDER_MSB_FIRST;
    MSPI->tSPISCR.tBit.TXCHKSUM_EN			= SPI_CHECK_SUM_DISABLE;
    MSPI->tSPISCR.tBit.RXCHKSUM_EN			= SPI_CHECK_SUM_DISABLE;
#if USED_S3_MSPI_4MHz_OPERATION
    if(IS_S3_MODE(eSensingMode))
    {
        MSPI->tSPISCR.tBit.SCLKDIV 			= SPI_SCLK_SPEED_12_DIV; // 48M/12Div = 4MHz
        MSPI->tSPISCR.tBit.RXPOS 			= 0x2;
    }
    else
    {
        MSPI->tSPISCR.tBit.SCLKDIV 			= SPI_SCLK_SPEED_6_DIV; // 48M/6Div = 8MHz
        MSPI->tSPISCR.tBit.RXPOS 			= 0x2;
    }
#else
    MSPI->tSPISCR.tBit.SCLKDIV 				= SPI_SCLK_SPEED_6_DIV;
    MSPI->tSPISCR.tBit.RXPOS 				= 0x0;
#endif
//    MSPI->tSPISCR.tBit.RXPOS 				= PARAMSET_MSPI_RX_POS;
    MSPI->tSPISCR.tBit.MISO_ZERO_CHK_EN 	= DISABLE;

    MSPI->MSPI_WFE_ENA						= BIT(0) | BIT(1) | BIT(2) | BIT(3); // Miso Interrupt SPI Number Setting

	MSPI->tSPISTATELEN.tBit.PreShftLen		= 15;//16;
	MSPI->tSPISTATELEN.tBit.TmpIdleLen		= 1;//0;//1;
	MSPI->tSPISTATELEN.tBit.PostShftLen  	= 9;//10;
	MSPI->tSPISTATELEN.tBit.txbufnum 		= 10;//6;//7;

	MSPI->SPIMUXNUM = FINGER_MUX_NUM-1;

	MSPI->tSPIENA.tBit.spiRxEna0 = PARAMSET_MSPI_ENA_spi_RX_Ena0;
	MSPI->tSPIENA.tBit.spiRxEna1 = PARAMSET_MSPI_ENA_spi_RX_Ena1;
	MSPI->tSPIENA.tBit.spiRxEna2 = PARAMSET_MSPI_ENA_spi_RX_Ena2;
	MSPI->tSPIENA.tBit.spiRxEna3 = PARAMSET_MSPI_ENA_spi_RX_Ena3;

	MSPI->tSPIMODE.tBit.aitmode = SPI_MODE_AITMODE;

	MSPI->tSINTRMSCR.tBit.intframe_en = ENABLE;

	switch(hal_Info_GetControlActivePenSettingType())
	{
		case ACTIVEPEN_TYPE_LOCAL_MS:
		case ACTIVEPEN_TYPE_LOCAL_WACOM:
		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
			{
				MSPI_BUF->ReadCommand[iMspi].Addr = MSPI_BROADCAST | MSPI_RAWDATA; //0x2400;//READ_ALIGNED_BUF ;
				MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
				MSPI_BUF->ReadCommand[iMspi].tBit.CKS = 0;
				MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = 13;

//				for (i = 0; i < (SW97500_ADDR_CMD_NUM + ((SW97500_R0_RAW_CH_NUM + SW97500_R0_DUM_CH_NUM) * SW97500_BROADCAST_NUM))*2 ; i++)
//				{
//					MSPI_BUF->ReadCommand[iMspi].Data[i] = 0;
//				}
			}

			MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize2 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1 - 2;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 15;
			MSPI->tSPIDATALEN.tBit.txbitlen = 15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 1

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 1

			break;
		}
	}
}

void MSPI_RegisterWrite(uint32_t Addr, uint32_t value)
{
	uint8_t iMspi;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

#if USE_ECLK_CONTROL_WHEN_USING_MSPI
	PWMDRV->ECLK_CR.tBit.eclk_force_on = 0;
#endif

	pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
	pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = Addr;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 0; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].tBit.CKS = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 1;//2;
		pMSPI_SEND_BUFF[iMspi].Data_M = value >> 16;
		pMSPI_SEND_BUFF[iMspi].Data_L = value & 0xFFFF;
	}

	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;

	MSPI_IntCLR();
#if USE_ECLK_CONTROL_WHEN_USING_MSPI
	PWMDRV->ECLK_CR.tBit.eclk_force_on = 1;
#endif
}

void MSPI_RegisterRead(uint32_t Addr, uint32_t * ReadBuf, eROIC_Read_Option_t eOption)
{
	uint8_t iMspi;
	uint32_t ulAddr;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

#if USE_ECLK_CONTROL_WHEN_USING_MSPI
	PWMDRV->ECLK_CR.tBit.eclk_force_on = 0;
#endif

	pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
	pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];

	ulAddr = Addr;
	switch(eOption)
	{
		case MSPI_READ_SM0_R0:
		{
			ulAddr = Addr | MSPI_ROIC_LEFT | MSPI_NORMALMODE;
			break;
		}
		case MSPI_READ_SM0_R1:
		{
			ulAddr = Addr | MSPI_ROIC_RIGHT | MSPI_NORMALMODE;
			break;
		}
		case MSPI_READ_SM1_R0:
		{
			ulAddr = Addr | MSPI_ROIC_LEFT | MSPI_SHAREMODE;
			break;
		}
		case MSPI_READ_SM1_R1:
		{
			ulAddr = Addr | MSPI_ROIC_RIGHT | MSPI_SHAREMODE;
			break;
		}
	}

	for (iMspi = 0; iMspi < MSPI_NUM; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = ulAddr;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].tBit.CKS = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 1;//2;
		pMSPI_SEND_BUFF[iMspi].Data_M = 0;
		pMSPI_SEND_BUFF[iMspi].Data_L = 0;
	}

	MSPI->tSPIENA.tBit.spiRxEna0 = PARAMSET_MSPI_ENA_spi_RX_Ena0;
	MSPI->tSPIENA.tBit.spiRxEna1 = PARAMSET_MSPI_ENA_spi_RX_Ena1;
	MSPI->tSPIENA.tBit.spiRxEna2 = PARAMSET_MSPI_ENA_spi_RX_Ena2;
	MSPI->tSPIENA.tBit.spiRxEna3 = PARAMSET_MSPI_ENA_spi_RX_Ena3;
	MSPI->tSPIENA.tBit.spiRxEna4 = PARAMSET_MSPI_ENA_spi_RX_Ena4;
	MSPI->tSPIENA.tBit.spiRxEna5 = PARAMSET_MSPI_ENA_spi_RX_Ena5;
	MSPI->tSPIENA.tBit.spiRxEna6 = PARAMSET_MSPI_ENA_spi_RX_Ena6;
	MSPI->tSPIENA.tBit.spiRxEna7 = PARAMSET_MSPI_ENA_spi_RX_Ena7;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize6 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize7 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x1;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x1;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;

	MSPI_IntCLR();

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
//		*ReadBuf++ = pMSPI_READ_BUFF[iMspi].Data;
		*ReadBuf++ = (uint32_t)(((pMSPI_READ_BUFF[iMspi].Data >> 16) & 0xFFFF) | ((pMSPI_READ_BUFF[iMspi].Data << 16) & 0xFFFF0000));
	}
#if USE_ECLK_CONTROL_WHEN_USING_MSPI
	PWMDRV->ECLK_CR.tBit.eclk_force_on = 1;
#endif
}

void MSPI_RegisterMultiWrite(uint32_t Addr, uint32_t * value)
{
	uint8_t iMspi;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

#if USE_ECLK_CONTROL_WHEN_USING_MSPI
	PWMDRV->ECLK_CR.tBit.eclk_force_on = 0;
#endif	

	pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
	pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = Addr;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 0; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].tBit.CKS = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 2;
		pMSPI_SEND_BUFF[iMspi].Data_M = value[iMspi] >> 16;
		pMSPI_SEND_BUFF[iMspi].Data_L = value[iMspi] & 0xFFFF;
	}

	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;

	MSPI_IntCLR();
#if USE_ECLK_CONTROL_WHEN_USING_MSPI
	PWMDRV->ECLK_CR.tBit.eclk_force_on = 1;
#endif	
}

void MSPI_RegisterSingleWrite(uint32_t Addr, uint32_t * value, uint8_t ch)
{
	uint8_t iMspi;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

#if USE_ECLK_CONTROL_WHEN_USING_MSPI
	PWMDRV->ECLK_CR.tBit.eclk_force_on = 0;
#endif

	pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
	pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = Addr;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 0; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].tBit.CKS = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 2;
		pMSPI_SEND_BUFF[iMspi].Data_M = value[iMspi] >> 16;
		pMSPI_SEND_BUFF[iMspi].Data_L = value[iMspi] & 0xFFFF;
	}

	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = ch;

	MSPI_IntCLR();
#if USE_ECLK_CONTROL_WHEN_USING_MSPI
	PWMDRV->ECLK_CR.tBit.eclk_force_on = 1;
#endif
}


void MSPI_RegisterShareModeMultiWrite(uint32_t Addr, uint32_t * value)
{
	uint32_t ulMspi, ulMode;
	uint32_t vValue[MSPI_NUM];
	uint32_t ulAddr;

	for(ulMode = 0; ulMode < 2; ulMode++)
	{
		ulAddr = Addr | (MSPI_SHAREMODE * ulMode);
		for(ulMspi = 0; ulMspi < MSPI_NUM; ulMspi++)
		{
			vValue[ulMspi] = value[ulMspi*2+ulMode];
		}
		MSPI_RegisterMultiWrite(ulAddr, &vValue[0]);
	}
}

void MSPI_RegisterShareModeSingleWrite(uint32_t Addr, uint32_t value, uint8_t ch)
{
	uint32_t ulMspi, ulMode;
	uint32_t vValue[MSPI_NUM];
	uint32_t ulAddr;

	for(ulMode = 0; ulMode < 2; ulMode++)
	{
		ulAddr = Addr | (MSPI_SHAREMODE * ulMode);
		for(ulMspi = 0; ulMspi < MSPI_NUM; ulMspi++)
		{
			vValue[ulMspi] = value;
		}
		MSPI_RegisterSingleWrite(ulAddr, &vValue[0], ch);
	}
}


#elif (USED_ROIC_DEF == ROIC_SW92502)

void MSPI_Set_AITMODE(eSENSING_MODE_t eSensingMode)
{
	uint32_t *pLengthAddr, *pMosiAddr, *pMisoAddr, *pSyncLenAddr;
	uint8_t iMspi, i;

	MSPI->SPIMODE_b.AitTlpMode		= spiAitMode;
	MSPI->SPIMODE_b.SramFifoMode	= spiSramMode;
	MSPI->SPIMODE_b.HwSwMode		= spiSwMode;
	MSPI->SPIMODE_b.BrstSnglMode	= spiBrstMode;
	MSPI->SPIMODE_b.SramDebugMode	= spiSramNormMode;
	MSPI->SPIMODE_b.SramWrOpt		= spiSramWrDefault;
	MSPI->SPIMODE_b.TrsPerRd		= spiTrsPerRd1;
	MSPI->SPIMODE_b.TrsPerWr		= spiTrsPerWr0;
	MSPI->SPIMODE_b.PwfeSel 		= spiPwfe3Sel;//spiPwfe0Sel;
	MSPI->SPIMODE_b.CommPwfeSel 	= spiCommPwfeSel;
	MSPI->SPIMODE_b.Protocol		= spiTlpProtocol;
	MSPI->SPIMODE_b.RdHlfWrdMsbFrst = spiRdHlfWrdMsbFrst;
	MSPI->SPIMODE_b.WrHlfWrdMsbFrst = spiWrHlfWrdLsbFrst;


	MSPI->SPIAITDMYDEL = AitDmyDelDis;
	MSPI->SINTRMSCR_b.IntrMemMSCR = IntrMemEna;


	pLengthAddr = (uint32_t *)&MSPI->SPITRSZE0;
	pSyncLenAddr = (uint32_t *)&MSPI->SPITSYNCSZE0;
	pMosiAddr = (uint32_t *)&MSPI->SPISTRTRAD01;
	pMisoAddr = (uint32_t *)&MSPI->SPISTRTWAD01;

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		MSPI_BUF->ReadCommand[iMspi].Addr = READ_ALIGNED_BUF;
		MSPI_BUF->ReadCommand[iMspi].Command = 0;
		MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1;
		MSPI_BUF->ReadCommand[iMspi].tBit.CKS = 0;
		MSPI_BUF->ReadCommand[iMspi].tBit.Extend = 0;
		MSPI_BUF->ReadCommand[iMspi].tBit.NextLHBMode = 0;
		MSPI_BUF->ReadCommand[iMspi].tBit.CurrentLHBIdx = 0;

		for (i = 0; i < SZ_MSPIBUF_MUXDATA*2 ; i++)
		{
			MSPI_BUF->ReadCommand[iMspi].Data[i] = 0;
		}
	}

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi+=2)
	{
		if(IS_ACTIVE_MODE(eSensingMode))
		{
			*pLengthAddr++ = SZ_MSPIBUF_FINGER_FULL_FRAME;
			*pLengthAddr++ = SZ_MSPIBUF_FINGER_FULL_FRAME;
		}
		else
		{
			*pLengthAddr++ = SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME;
			*pLengthAddr++ = SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME;

		}
		*pSyncLenAddr++ = SZ_MSPIBUF_MUXDATA;
		*pSyncLenAddr++ = SZ_MSPIBUF_MUXDATA;
	}

	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]) << 16; //SRIC 1
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]);	//SRIC 0

	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]) << 16;//SRIC 3
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]);//SRIC 2

	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[5]) << 16;//SRIC 5
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]);//SRIC 4

	*pMisoAddr = MSPI_MEM_INDEX(MSPI_BUF->Rawdata[1]) << 16;//SRIC 1
	*pMisoAddr++ |= MSPI_MEM_INDEX(MSPI_BUF->Rawdata[0]);//SRIC 0

	*pMisoAddr = MSPI_MEM_INDEX(MSPI_BUF->Rawdata[3]) << 16;//SRIC 3
	*pMisoAddr++ |= MSPI_MEM_INDEX(MSPI_BUF->Rawdata[2]);//SRIC 2

	*pMisoAddr = MSPI_MEM_INDEX(MSPI_BUF->Rawdata[5]) << 16;//SRIC 5
	*pMisoAddr++ |= MSPI_MEM_INDEX(MSPI_BUF->Rawdata[4]);//SRIC 4
}

void MSPI_RegisterWrite(uint32_t Addr, uint32_t value)
{
	uint32_t *pLengthAddr, *pMisoAddr, *pMosiAddr;
	uint8_t iMspi;

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		MSPI_BUF->SricBuffer[IDX_SEND][iMspi].Addr = Addr;
		MSPI_BUF->SricBuffer[IDX_SEND][iMspi].Command = 0;
		MSPI_BUF->SricBuffer[IDX_SEND][iMspi].tBit.RW = 0;
		MSPI_BUF->SricBuffer[IDX_SEND][iMspi].tBit.CKS = 0;
		MSPI_BUF->SricBuffer[IDX_SEND][iMspi].Data = (uint16_t)value;
	}

	pLengthAddr = (uint32_t *)&MSPI->SPITRSZE0;
	pMosiAddr = (uint32_t *)&MSPI->SPISTRTRAD01;
	pMisoAddr = (uint32_t *)&MSPI->SPISTRTWAD01;

#ifdef _DV_SAMPLE_
	for (iMspi = 0; iMspi<MSPI_NUM ; iMspi+=2)
	{
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;
	}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][1]) << 16; //SRIC 1
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][0]);  //SRIC 0

	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][3]) << 16;//SRIC 3
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][2]);//SRIC 2

	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][5]) << 16;//SRIC 5
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][4]);//SRIC 4



	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][1]) << 16;//SRIC 1
	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][0]);//SRIC 0

	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][3]) << 16;//SRIC 3
	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][2]);//SRIC 2

	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][5]) << 16;//SRIC 5
	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][4]);//SRIC 4
#elif (USED_MODULE_DEF == MODULE_DEF_B_1)
	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][1]) << 16; //SRIC 1
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][0]);  //SRIC 0

//	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[0][3]) << 16;//SRIC 3
	*pMosiAddr++ = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][2]);//SRIC 2

//	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[0][5]) << 16;//SRIC 5
//	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[0][4]);//SRIC 4



	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][1]) << 16;//SRIC 1
	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][0]);//SRIC 0

//	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[1][3]) << 16;//SRIC 3
	*pMisoAddr++ = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][2]);//SRIC 2

//	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[1][5]) << 16;//SRIC 5
//	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[1][4]);//SRIC 4
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

#else
	for (iMspi = 0; iMspi<MSPI_NUM ; iMspi+=2)
	{
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;

		*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[0][iMspi+1]) << 16;
		*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[0][iMspi]);

		*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[1][iMspi+1]) << 16;
		*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[1][iMspi]);
	}
#endif

	MSPI->SINTRMSCR = DISABLE;

	MSPI->SPISTART = MSPI_START_VAL;
	MSPI_IntCLR();
}

void MSPI_RegisterRead(uint32_t Addr, uint32_t * ReadBuf, eROIC_Read_Option_t eOption)
{
	uint32_t *pLengthAddr, *pMisoAddr, *pMosiAddr;
	uint8_t iMspi;

	/** Protocol setup */
	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		MSPI_BUF->SricBuffer[IDX_SEND][iMspi].Addr = Addr ;
		MSPI_BUF->SricBuffer[IDX_SEND][iMspi].Command = 0;
		MSPI_BUF->SricBuffer[IDX_SEND][iMspi].tBit.RW = 1;
		MSPI_BUF->SricBuffer[IDX_SEND][iMspi].tBit.CKS = 0;
	}

	/** MSPI Control Setup */
	pLengthAddr = (uint32_t *)&MSPI->SPITRSZE0;
	pMosiAddr = (uint32_t *)&MSPI->SPISTRTRAD01;
	pMisoAddr = (uint32_t *)&MSPI->SPISTRTWAD01;

#ifdef _DV_SAMPLE_
	for (iMspi = 0; iMspi<MSPI_NUM ; iMspi+=2)
	{
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;
	}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][1]) << 16; //SRIC 1
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][0]);  //SRIC 0

	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][3]) << 16;//SRIC 3
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][2]);//SRIC 2

	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][5]) << 16;//SRIC 5
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][4]);//SRIC 4



	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][1]) << 16;//SRIC 1
	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][0]);//SRIC 0

	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][3]) << 16;//SRIC 3
	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][2]);//SRIC 2

	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][5]) << 16;//SRIC 5
	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][4]);//SRIC 4
#elif (USED_MODULE_DEF == MODULE_DEF_B_1)
	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][1]) << 16; //SRIC 1
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][0]);  //SRIC 0

//	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][3]) << 16;//SRIC 3
	*pMosiAddr++ = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][2]);//SRIC 2

//	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][5]) << 16;//SRIC 5
//	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][4]);//SRIC 4



	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][1]) << 16;//SRIC 1
	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][0]);//SRIC 0

//	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][3]) << 16;//SRIC 3
	*pMisoAddr++ = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][2]);//SRIC 2

//	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][5]) << 16;//SRIC 5
//	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][4]);//SRIC 4
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

#else
	for(iMspi = 0; iMspi<MSPI_NUM ; iMspi+=2)
	{
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;

		*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][iMspi+1]) << 16;
		*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][iMspi]);

		*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][iMspi+1]) << 16;
		*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][iMspi]);
	}
#endif

	MSPI->SINTRMSCR = DISABLE;


	/** MSPI Start */
#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	MSPI->SPISTART = MSPI_START_VAL;
#elif (USED_MODULE_DEF == MODULE_DEF_B_1)
	MSPI->SPISTART = BIT2|BIT1|BIT0;
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	MSPI_IntCLR();

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		*ReadBuf ++ = MSPI_BUF->SricBuffer[IDX_READ][iMspi].Addr;
	}
}

void MSPI_Set_ReadCommand(uint32_t ulNexLHBMode, uint32_t ulCurrentLHBIdx)
{
	uint32_t iMspi;

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		MSPI_BUF->ReadCommand[iMspi].Addr = READ_ALIGNED_BUF;
		MSPI_BUF->ReadCommand[iMspi].Command = 0;
		MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1;
		MSPI_BUF->ReadCommand[iMspi].tBit.CKS = 0;
		MSPI_BUF->ReadCommand[iMspi].tBit.Extend = 0;
		MSPI_BUF->ReadCommand[iMspi].tBit.NextLHBMode = ulNexLHBMode;
		MSPI_BUF->ReadCommand[iMspi].tBit.CurrentLHBIdx = ulCurrentLHBIdx;
	}
}

#elif (USED_ROIC_DEF == ROIC_SW92503 || USED_ROIC_DEF == ROIC_SW92503S || USED_ROIC_DEF == ROIC_SW92503B || USED_ROIC_DEF == ROIC_SW92505)

void MSPI_Set_AITMODE(eSENSING_MODE_t eSensingMode)
{
	uint8_t iMspi;
#if USED_MSPEN_MSPI_24BIT_TRANSMODE
	MSPI->tSPISCR.tBit.BITLEN 				= SPI_BITLEN_WORD;
#else /* USED_MSPEN_MSPI_24BIT_TRANSMODE */
	MSPI->tSPISCR.tBit.BITLEN 				= SPI_BITLEN_HALF_WORD;
#endif /* USED_MSPEN_MSPI_24BIT_TRANSMODE */

    MSPI->tSPISCR.tBit.DUALACC 				= SPI_RX_DUAL_MODE;//SPI_RX_SINGLE_MODE;//SPI_RX_DUAL_MODE;//SPI_RX_SINGLE_MODE;
    MSPI->tSPISCR.tBit.DUALBITORD 			= SPI_RX_DUAL_BIT_ORDER_MOSI_MISO;//SPI_RX_DUAL_BIT_ORDER_MISO_MOSI;//SPI_RX_DUAL_BIT_ORDER_MOSI_MISO;
    MSPI->tSPISCR.tBit.TXDORD 				= SPI_DATA_ORDER_MSB_FIRST;
    MSPI->tSPISCR.tBit.RXDORD 				= SPI_DATA_ORDER_MSB_FIRST;
    MSPI->tSPISCR.tBit.TXCHKSUM_EN			= SPI_CHECK_SUM_DISABLE;
    MSPI->tSPISCR.tBit.RXCHKSUM_EN			= SPI_CHECK_SUM_DISABLE;
    MSPI->tSPISCR.tBit.RXPOS 				= PARAMSET_MSPI_RX_POS;
    MSPI->tSPISCR.tBit.SCLKDIV 				= SPI_SCLK_SPEED_3_DIV;
    MSPI->tSPISCR.tBit.MISO_ZERO_CHK_EN 	= DISABLE;

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
    MSPI->MSPI_WFE_ENA						= BIT(0) | BIT(1) | BIT(3) | BIT(4) | BIT(6) | BIT(7); // Miso Interrupt SPI Number Setting
#elif (USED_MODULE_DEF == MODULE_DEF_INX_1)
    MSPI->MSPI_WFE_ENA						= BIT(0) | BIT(1) | BIT(2) | BIT(3) | BIT(4); // Miso Interrupt SPI Number Setting
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
    MSPI->MSPI_WFE_ENA						= BIT(0) | BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5); // Miso Interrupt SPI Number Setting
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

	MSPI->tSPISTATELEN.tBit.PreShftLen		= 15;//16;
	MSPI->tSPISTATELEN.tBit.TmpIdleLen		= 0;//1;
	MSPI->tSPISTATELEN.tBit.PostShftLen  	= 9;//10;
	MSPI->tSPISTATELEN.tBit.txbufnum 		= 6;//7;

	MSPI->SPIMUXNUM = FINGER_MUX_NUM-1;

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = ENABLE;
#elif (USED_MODULE_DEF == MODULE_DEF_INX_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = DISABLE;
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = DISABLE;
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

	MSPI->tSPIMODE.tBit.aitmode = SPI_MODE_AITMODE;

	MSPI->tSINTRMSCR.tBit.intframe_en = ENABLE;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
			{
				MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);

				MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_MUXDATA>>1)+1;
				MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 1;//0; // 0:32bit, 1:24bit
				MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
				MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
				MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
				MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read

//				MSPI_BUF->ReadCommand[iMspi].Command = ( MSPI_READ | MSPI_BURST);

//				for (i = 0; i < SZ_WACOMPEN_MSPIBUF_MUXDATA*2 ; i++)
//				{
//					MSPI_WACOMPEN_BUF->ReadCommand[iMspi].Data[i] = 0;
//				}
			}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize6 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize7 = SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 11;//15;
			MSPI->tSPIDATALEN.tBit.txbitlen = 15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 1
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 1
			MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 1
			MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[5]); //SRIC 1

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 1
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 1
			MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 1
			MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[5]); //SRIC 1
#elif (USED_MODULE_DEF == MODULE_DEF_INX_1)
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize2 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 11;//15;
			MSPI->tSPIDATALEN.tBit.txbitlen = 15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 1
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 1

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 1
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 1

#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize2 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize5 = SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 11;//15;
			MSPI->tSPIDATALEN.tBit.txbitlen = 15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 1
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 1
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[5]); //SRIC 1

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 1
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 1
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[5]); //SRIC 1

#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
//			break;
		}
//	}
}

void MSPI_RegisterWrite(uint32_t Addr, uint32_t value)
{
	uint8_t iMspi;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
			pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];
//			break;
		}
//	}

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = Addr;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		pMSPI_SEND_BUFF[iMspi].tBit.ExtCMDEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.DualRxEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ChkSum = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 0; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].Data_M = value >> 16;
		pMSPI_SEND_BUFF[iMspi].Data_L = value & 0xFFFF;
	}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize6 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize7 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#elif (USED_MODULE_DEF == MODULE_DEF_INX_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

	MSPI_IntCLR();

	/*
	 * Read Test Code after write!!
	 */
//	{
//		uint32_t ulBuf[6];
//		MSPI_RegisterRead(Addr, &ulBuf[0], MSPI_READ_NONE);
//	}
}

void MSPI_RegisterRead(uint32_t Addr, uint32_t * ReadBuf, eROIC_Read_Option_t eOption)
{
	uint8_t iMspi;
	uint32_t ulAddr;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
			pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];
//			break;
		}
//	}

	ulAddr = Addr;
	if(eOption == MSPI_READ_SM0_R1)
	{
		ulAddr += 0x100;
	}

	for (iMspi = 0; iMspi < MSPI_NUM; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = ulAddr;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 1;
		pMSPI_SEND_BUFF[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		pMSPI_SEND_BUFF[iMspi].tBit.ExtCMDEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.DualRxEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ChkSum = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].Data_M = 0;
		pMSPI_SEND_BUFF[iMspi].Data_L = 0;
	}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = ENABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize6 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize7 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x1;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x1;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#elif (USED_MODULE_DEF == MODULE_DEF_INX_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x1;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x1;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = ENABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x1;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x1;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

	MSPI_IntCLR();

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		*ReadBuf++ = (uint32_t)(((pMSPI_READ_BUFF[iMspi].Data >> 16) & 0xFFFF) | ((pMSPI_READ_BUFF[iMspi].Data << 16) & 0xFFFF0000));
	}
}

void MSPI_RegisterMultiWrite(uint32_t Addr, uint32_t * value)
{
	uint8_t iMspi;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
			pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];
//			break;
		}
//	}

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = Addr;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		pMSPI_SEND_BUFF[iMspi].tBit.ExtCMDEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.DualRxEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ChkSum = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 0; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].Data_M = value[iMspi] >> 16;
		pMSPI_SEND_BUFF[iMspi].Data_L = value[iMspi] & 0xFFFF;
	}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize6 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize7 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#elif (USED_MODULE_DEF == MODULE_DEF_INX_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

	MSPI_IntCLR();

	/*
	 * Read Test Code after write!!
	 */
//	{
//		uint32_t ulBuf[6];
//		MSPI_RegisterRead(Addr, &ulBuf[0], MSPI_READ_NONE);
//	}
}
#elif ((USED_ROIC_DEF == ROIC_SW98500) || (USED_ROIC_DEF == ROIC_SW98502) || (USED_ROIC_DEF == ROIC_SW92510) || (USED_ROIC_DEF == ROIC_SW92511) || (USED_ROIC_DEF == ROIC_SW92512) || (USED_ROIC_DEF == ROIC_SW92509) || (USED_ROIC_DEF == ROIC_SW92513))
void MSPI_Set_AITMODE(eSENSING_MODE_t eSensingMode)
{
	uint32_t iMspi;
#if USED_SPI_NBIT_TRANSMODE
	MSPI->tSPISCR.tBit.BITLEN 				= SPI_BITLEN_WORD;
#else /* USED_SPI_NBIT_TRANSMODE */
	MSPI->tSPISCR.tBit.BITLEN 				= SPI_BITLEN_HALF_WORD;
#endif /* USED_SPI_NBIT_TRANSMODE */

    MSPI->tSPISCR.tBit.DUALACC 				= SPI_RX_DUAL_MODE;//SPI_RX_SINGLE_MODE;//SPI_RX_DUAL_MODE;//SPI_RX_SINGLE_MODE;
    MSPI->tSPISCR.tBit.DUALBITORD 			= SPI_RX_DUAL_BIT_ORDER_MOSI_MISO;//SPI_RX_DUAL_BIT_ORDER_MISO_MOSI;//SPI_RX_DUAL_BIT_ORDER_MOSI_MISO;
    MSPI->tSPISCR.tBit.TXDORD 				= SPI_DATA_ORDER_MSB_FIRST;
    MSPI->tSPISCR.tBit.RXDORD 				= SPI_DATA_ORDER_MSB_FIRST;
    MSPI->tSPISCR.tBit.TXCHKSUM_EN			= SPI_CHECK_SUM_DISABLE;
    MSPI->tSPISCR.tBit.RXCHKSUM_EN			= SPI_CHECK_SUM_DISABLE;
    MSPI->tSPISCR.tBit.RXPOS 				= PARAMSET_MSPI_RX_POS;
    MSPI->tSPISCR.tBit.SCLKDIV 				= SPI_SCLK_SPEED_3_DIV;
    MSPI->tSPISCR.tBit.MISO_ZERO_CHK_EN 	= DISABLE;

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
    MSPI->MSPI_WFE_ENA						= BIT(0) | BIT(1) | BIT(3) | BIT(4) | BIT(6) | BIT(7); // Miso Interrupt SPI Number Setting
#elif (USED_MODULE_DEF == MODULE_DEF_T_1) || (USED_MODULE_DEF == MODULE_DEF_A_1)
    MSPI->MSPI_WFE_ENA						= BIT(0) | BIT(1) | BIT(2) | BIT(3) | BIT(4); // Miso Interrupt SPI Number Setting
#elif (CUSTOMER == MODEL_DEF_FHD_92513_LENOVO || CUSTOMER == MODEL_DEF_FHD_92513_LENOVO_NON_PRIVACY)
    MSPI->MSPI_WFE_ENA						= MSPI_START_VAL; // Miso Interrupt SPI Number Setting
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
    MSPI->MSPI_WFE_ENA						= BIT(0) | BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5); // Miso Interrupt SPI Number Setting
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

	MSPI->tSPISTATELEN.tBit.PreShftLen		= 15;//16;
	MSPI->tSPISTATELEN.tBit.TmpIdleLen		= 0;//1;
	MSPI->tSPISTATELEN.tBit.PostShftLen  	= 9;//10;
	MSPI->tSPISTATELEN.tBit.txbufnum 		= 6;//7;
	MSPI->SPIMUXNUM = FINGER_MUX_NUM-1;

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = ENABLE;
#elif (USED_MODULE_DEF == MODULE_DEF_T_1) || (USED_MODULE_DEF == MODULE_DEF_A_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = DISABLE;
#elif (CUSTOMER == MODEL_DEF_FHD_92513_LENOVO || CUSTOMER == MODEL_DEF_FHD_92513_LENOVO_NON_PRIVACY)
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = DISABLE;
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = DISABLE;
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

	MSPI->tSPIMODE.tBit.aitmode = SPI_MODE_AITMODE;

	MSPI->tSINTRMSCR.tBit.intframe_en = ENABLE;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
#if USED_SPI_NBIT_TRANSMODE
			for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
			{
				MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);
				MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_MUXDATA>>1)-1;
				MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
				MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
				MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
				MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
				MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
			}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize6 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize7 = 63;//SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = 62;//(SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 23;
			MSPI->tSPIDATALEN.tBit.txbitlen = 31;//15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 2
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 3
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 4
			MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 5
			MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[5]); //SRIC 6

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 2
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 3
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 4
			MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 5
			MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[5]); //SRIC 6

#elif (USED_MODULE_DEF == MODULE_DEF_T_1) || (USED_MODULE_DEF == MODULE_DEF_A_1)
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize2 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = 63;//SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = 62;//(SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 23;
			MSPI->tSPIDATALEN.tBit.txbitlen = 31;//15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 2
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 3
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 4
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 5

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 2
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 3
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 4
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 5
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize2 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize5 = SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 11;//15;
			MSPI->tSPIDATALEN.tBit.txbitlen = 15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 1
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 1
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[5]); //SRIC 1

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 1
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 1
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[5]); //SRIC 1

#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
#else /* USED_SPI_NBIT_TRANSMODE */
			for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
			{
				MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);

				MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_MUXDATA>>1);
				MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
				MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
				MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
				MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
				MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read

//				MSPI_BUF->ReadCommand[iMspi].Command = ( MSPI_READ | MSPI_BURST);

//				for (i = 0; i < SZ_WACOMPEN_MSPIBUF_MUXDATA*2 ; i++)
//				{
//					MSPI_WACOMPEN_BUF->ReadCommand[iMspi].Data[i] = 0;
//				}
			}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize6 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize7 = SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 11;//15;
			MSPI->tSPIDATALEN.tBit.txbitlen = 15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 2
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 3
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 4
			MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 5
			MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[5]); //SRIC 6

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 2
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 3
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 4
			MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 5
			MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[5]); //SRIC 6
#elif (USED_MODULE_DEF == MODULE_DEF_T_1) || (USED_MODULE_DEF == MODULE_DEF_A_1)
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize2 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 11;//15;
			MSPI->tSPIDATALEN.tBit.txbitlen = 15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 2
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 3
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 4
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 5

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 2
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 3
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 4
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 5
#elif (CUSTOMER == MODEL_DEF_FHD_92513_LENOVO || CUSTOMER == MODEL_DEF_FHD_92513_LENOVO_NON_PRIVACY)
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize2 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 11;//15;
			MSPI->tSPIDATALEN.tBit.txbitlen = 15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 1

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 1
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize2 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize5 = SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 11;//15;
			MSPI->tSPIDATALEN.tBit.txbitlen = 15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 1
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 1
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[5]); //SRIC 1

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 1
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 1
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[5]); //SRIC 1
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
#endif /* USED_SPI_NBIT_TRANSMODE */
//			break;
		}
//	}
}

void MSPI_RegisterWrite(uint32_t Addr, uint32_t value)
{
	uint8_t iMspi;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
			pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];
//			break;
		}
//	}

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = Addr;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		pMSPI_SEND_BUFF[iMspi].tBit.ExtCMDEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.DualRxEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ChkSum = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 0; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].Data_M = value >> 16;
		pMSPI_SEND_BUFF[iMspi].Data_L = value & 0xFFFF;
	}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize6 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize7 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#elif (USED_MODULE_DEF == MODULE_DEF_T_1) || (USED_MODULE_DEF == MODULE_DEF_A_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#elif (CUSTOMER == MODEL_DEF_FHD_92513_LENOVO || CUSTOMER == MODEL_DEF_FHD_92513_LENOVO_NON_PRIVACY)
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

	MSPI_IntCLR();

	/*
	 * Read Test Code after write!!
	 */
//	{
//		uint32_t ulBuf[6];
//		MSPI_RegisterRead(Addr, &ulBuf[0], MSPI_READ_NONE);
//	}
}

void MSPI_RegisterRead(uint32_t Addr, uint32_t * ReadBuf, eROIC_Read_Option_t eOption)
{
	uint8_t iMspi;
	uint32_t ulAddr;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
			pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];
//			break;
		}
//	}

	ulAddr = Addr;
	if(eOption == MSPI_READ_SM0_R1)
	{
		ulAddr += 0x100;
	}

	for (iMspi = 0; iMspi < MSPI_NUM; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = ulAddr;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 1;
		pMSPI_SEND_BUFF[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		pMSPI_SEND_BUFF[iMspi].tBit.ExtCMDEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.DualRxEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ChkSum = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].Data_M = 0;
		pMSPI_SEND_BUFF[iMspi].Data_L = 0;
	}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = ENABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize6 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize7 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x1;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x1;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#elif (USED_MODULE_DEF == MODULE_DEF_T_1) || (USED_MODULE_DEF == MODULE_DEF_A_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x1;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x1;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#elif (CUSTOMER == MODEL_DEF_FHD_92513_LENOVO || CUSTOMER == MODEL_DEF_FHD_92513_LENOVO_NON_PRIVACY)
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x1;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x1;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = ENABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x1;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x1;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

	MSPI_IntCLR();

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		*ReadBuf++ = (uint32_t)(((pMSPI_READ_BUFF[iMspi].Data >> 16) & 0xFFFF) | ((pMSPI_READ_BUFF[iMspi].Data << 16) & 0xFFFF0000));
	}
}

void MSPI_RegisterMultiWrite(uint32_t Addr, uint32_t * value)
{
	uint8_t iMspi;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
			pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];
//			break;
		}
//	}

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = Addr;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		pMSPI_SEND_BUFF[iMspi].tBit.ExtCMDEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.DualRxEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ChkSum = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 0; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].Data_M = value[iMspi] >> 16;
		pMSPI_SEND_BUFF[iMspi].Data_L = value[iMspi] & 0xFFFF;
	}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize6 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize7 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#elif (USED_MODULE_DEF == MODULE_DEF_T_1) || (USED_MODULE_DEF == MODULE_DEF_A_1)
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#elif (CUSTOMER == MODEL_DEF_FHD_92513_LENOVO)
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

	MSPI_IntCLR();

	/*
	 * Read Test Code after write!!
	 */
//	{
//		uint32_t ulBuf[6];
//		MSPI_RegisterRead(Addr, &ulBuf[0], MSPI_READ_NONE);
//	}
}

#elif (USED_ROIC_DEF == ROIC_SW92508)
void MSPI_Set_AITMODE(eSENSING_MODE_t eSensingMode)
{
	uint32_t iMspi;
#if USED_SPI_NBIT_TRANSMODE
	MSPI->tSPISCR.tBit.BITLEN 				= SPI_BITLEN_WORD;
#else /* USED_SPI_NBIT_TRANSMODE */
	MSPI->tSPISCR.tBit.BITLEN 				= SPI_BITLEN_HALF_WORD;
#endif /* USED_SPI_NBIT_TRANSMODE */

    MSPI->tSPISCR.tBit.DUALACC 				= SPI_RX_DUAL_MODE;//SPI_RX_SINGLE_MODE;//SPI_RX_DUAL_MODE;//SPI_RX_SINGLE_MODE;
    MSPI->tSPISCR.tBit.DUALBITORD 			= SPI_RX_DUAL_BIT_ORDER_MOSI_MISO;//SPI_RX_DUAL_BIT_ORDER_MISO_MOSI;//SPI_RX_DUAL_BIT_ORDER_MOSI_MISO;
    MSPI->tSPISCR.tBit.TXDORD 				= SPI_DATA_ORDER_MSB_FIRST;
    MSPI->tSPISCR.tBit.RXDORD 				= SPI_DATA_ORDER_MSB_FIRST;
    MSPI->tSPISCR.tBit.TXCHKSUM_EN			= SPI_CHECK_SUM_DISABLE;
    MSPI->tSPISCR.tBit.RXCHKSUM_EN			= SPI_CHECK_SUM_DISABLE;
    MSPI->tSPISCR.tBit.RXPOS 				= PARAMSET_MSPI_RX_POS;//0x2;
    MSPI->tSPISCR.tBit.SCLKDIV 				= SPI_SCLK_SPEED_3_DIV;
    MSPI->tSPISCR.tBit.MISO_ZERO_CHK_EN 	= DISABLE;

    MSPI->MSPI_WFE_ENA						= MSPI_START_VAL; //BIT(0) | BIT(1) | BIT(2) | BIT(3) | BIT(4) | BIT(5) | BIT(6) | BIT(7); // Miso Interrupt SPI Number Setting

	MSPI->tSPISTATELEN.tBit.PreShftLen		= 15;//16;
	MSPI->tSPISTATELEN.tBit.TmpIdleLen		= 0;//1;
	MSPI->tSPISTATELEN.tBit.PostShftLen  	= 9;//10;
	MSPI->tSPISTATELEN.tBit.txbufnum 		= 6;//7;

	MSPI->SPIMUXNUM = FINGER_MUX_NUM-1;

	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = ENABLE;

	MSPI->tSPIMODE.tBit.aitmode = SPI_MODE_AITMODE;

	MSPI->tSINTRMSCR.tBit.intframe_en = ENABLE;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
#if USED_SPI_NBIT_TRANSMODE
			for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
			{
				MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);
				MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_MUXDATA>>1)-1;
				MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
				MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
				MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
				MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
				MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
			}

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize6 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize7 = 63;//SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = 62;//(SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 23;
			MSPI->tSPIDATALEN.tBit.txbitlen = 31;//15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 2
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 3
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 4
			MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 5
			MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[5]); //SRIC 6

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 2
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 3
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 4
			MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 5
			MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[5]); //SRIC 6

#elif (USED_MODULE_DEF == MODULE_DEF_T_1)
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize2 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = 63;//SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = 63;//SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = 62;//(SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 23;
			MSPI->tSPIDATALEN.tBit.txbitlen = 31;//15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 2
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 3
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 4
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 5

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 2
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 3
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 4
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 5
#else /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
			MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize2 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize5 = SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 11;//15;
			MSPI->tSPIDATALEN.tBit.txbitlen = 15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 1
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 1
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 1
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[5]); //SRIC 1

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 1
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 1
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 1
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[5]); //SRIC 1

#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
#else /* USED_SPI_NBIT_TRANSMODE */
			for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
			{
				MSPI_BUF->ReadCommand[iMspi].Addr = 0x0800;//(READ_ALIGNED_BUF | MSPI_16BITMODE);

				MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = (SZ_MSPIBUF_MUXDATA>>1);
				MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 3;//0; // 0:32bit, 1:20bit, 2:22bit 3:24bit
				MSPI_BUF->ReadCommand[iMspi].tBit.ExtCMDEn = 0;
				MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 1;//0;//1;//0;
				MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
				MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read

//				MSPI_BUF->ReadCommand[iMspi].Command = ( MSPI_READ | MSPI_BURST);

//				for (i = 0; i < SZ_WACOMPEN_MSPIBUF_MUXDATA*2 ; i++)
//				{
//					MSPI_WACOMPEN_BUF->ReadCommand[iMspi].Data[i] = 0;
//				}
			}

			MSPI->tSPITRSIZE0.tBit.spitrsize0 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize1 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize2 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE0.tBit.spitrsize3 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize4 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize5 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize6 = SZ_MSPIBUF_MUXDATA+1;
			MSPI->tSPITRSIZE1.tBit.spitrsize7 = SZ_MSPIBUF_MUXDATA+1;

			MSPI->tSPIDATALEN.tBit.rxdata_len = (SZ_MSPIBUF_MUXDATA - SPI_DMY_LEN) + 1;
			MSPI->tSPIDATALEN.tBit.txdata_len = 0;//SPI_DMY_LEN-1;

			MSPI->tSPIDATALEN.tBit.rxbitlen = 11;//15;
			MSPI->tSPIDATALEN.tBit.txbitlen = 15;

			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]); //SRIC 1
			MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]); //SRIC 2
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]); //SRIC 3
			MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]); //SRIC 4
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[4]); //SRIC 5
			MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[5]); //SRIC 6
			MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[6]); //SRIC 7
			MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[7]); //SRIC 8

			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0]); //SRIC 1
			MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]); //SRIC 2
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2]); //SRIC 3
			MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]); //SRIC 4
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4]); //SRIC 5
			MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[5]); //SRIC 6
			MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[6]); //SRIC 7
			MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[7]); //SRIC 8
#endif /* USED_SPI_NBIT_TRANSMODE */
//			break;
		}
//	}
}

void MSPI_RegisterWrite(uint32_t Addr, uint32_t value)
{
	uint8_t iMspi;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
			pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];
//			break;
		}
//	}

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = Addr;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		pMSPI_SEND_BUFF[iMspi].tBit.ExtCMDEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.DualRxEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ChkSum = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 0; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].Data_M = value >> 16;
		pMSPI_SEND_BUFF[iMspi].Data_L = value & 0xFFFF;
	}

	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize6 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize7 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[6]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[7]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[6]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[7]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;

	MSPI_IntCLR();

	/*
	 * Read Test Code after write!!
	 */
//	{
//		uint32_t ulBuf[6];
//		MSPI_RegisterRead(Addr, &ulBuf[0], MSPI_READ_NONE);
//	}
}

void MSPI_RegisterRead(uint32_t Addr, uint32_t * ReadBuf, eROIC_Read_Option_t eOption)
{
	uint8_t iMspi;
	uint32_t ulAddr;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
			pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];
//			break;
		}
//	}

	ulAddr = Addr;
	if(eOption == MSPI_READ_SM0_R1)
	{
		ulAddr += 0x100;
	}

	for (iMspi = 0; iMspi < MSPI_NUM; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = ulAddr;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 1;
		pMSPI_SEND_BUFF[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		pMSPI_SEND_BUFF[iMspi].tBit.ExtCMDEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.DualRxEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ChkSum = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 1; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].Data_M = 0;
		pMSPI_SEND_BUFF[iMspi].Data_L = 0;
	}

	MSPI->tSPIENA.tBit.spiRxEna0 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = ENABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = ENABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize6 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize7 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x1;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x1;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[6]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[7]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[6]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[7]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;

	MSPI_IntCLR();

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		*ReadBuf++ = (uint32_t)(((pMSPI_READ_BUFF[iMspi].Data >> 16) & 0xFFFF) | ((pMSPI_READ_BUFF[iMspi].Data << 16) & 0xFFFF0000));
	}
}

void MSPI_RegisterMultiWrite(uint32_t Addr, uint32_t * value)
{
	uint8_t iMspi;
	tMSPI_Reg_WriteBuf_t * pMSPI_SEND_BUFF;
	tMSPI_Reg_ReadBuf_t * pMSPI_READ_BUFF;

//	switch(hal_Info_GetControlActivePenSettingType())
//	{
//		case ACTIVEPEN_TYPE_LOCAL_MS:
//		case ACTIVEPEN_TYPE_LOCAL_WACOM:
//		case ACTIVEPEN_TYPE_LOCAL_WGP:
		{
			pMSPI_SEND_BUFF = (tMSPI_Reg_WriteBuf_t *)&MSPI_BUF->SricRegWriteBuffer[0];
			pMSPI_READ_BUFF = (tMSPI_Reg_ReadBuf_t *)&MSPI_BUF->SricRegReadBuffer[0];
//			break;
		}
//	}

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		pMSPI_SEND_BUFF[iMspi].Addr = Addr;
		pMSPI_SEND_BUFF[iMspi].tBit.Burst_Len = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		pMSPI_SEND_BUFF[iMspi].tBit.ExtCMDEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.DualRxEn = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.ChkSum = 0;
		pMSPI_SEND_BUFF[iMspi].tBit.RW = 0; // 0 : write, 1 : Read
		pMSPI_SEND_BUFF[iMspi].Data_M = value[iMspi] >> 16;
		pMSPI_SEND_BUFF[iMspi].Data_L = value[iMspi] & 0xFFFF;
	}

	MSPI->tSPIENA.tBit.spiRxEna0 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna1 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna2 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna3 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna4 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna5 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna6 = DISABLE;
	MSPI->tSPIENA.tBit.spiRxEna7 = DISABLE;

	MSPI->tSPITRSIZE0.tBit.spitrsize0 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize1 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize2 = 0x3;
	MSPI->tSPITRSIZE0.tBit.spitrsize3 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize4 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize5 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize6 = 0x3;
	MSPI->tSPITRSIZE1.tBit.spitrsize7 = 0x3;

	MSPI->tSPIDATALEN.tBit.rxdata_len = 0x0;
	MSPI->tSPIDATALEN.tBit.txdata_len = 0x3;

	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd0 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[0]);
	MSPI->tSPISTRTWAD01.tBit.spiStrtWAd1 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[1]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd2 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[2]);
	MSPI->tSPISTRTWAD23.tBit.spiStrtWAd3 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[3]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd4 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[4]);
	MSPI->tSPISTRTWAD45.tBit.spiStrtWAd5 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[5]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd6 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[6]);
	MSPI->tSPISTRTWAD67.tBit.spiStrtWAd7 = MSPI_MEM_INDEX(&pMSPI_SEND_BUFF[7]);

	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd0 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[0]);
	MSPI->tSPISTRTRAD01.tBit.spiStrtRAd1 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[1]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd2 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[2]);
	MSPI->tSPISTRTRAD23.tBit.spiStrtRAd3 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[3]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd4 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[4]);
	MSPI->tSPISTRTRAD45.tBit.spiStrtRAd5 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[5]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd6 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[6]);
	MSPI->tSPISTRTRAD67.tBit.spiStrtRAd7 = MSPI_MEM_INDEX(&pMSPI_READ_BUFF[7]);

	MSPI->tSINTRMSCR.ulBulk = DISABLE;

	MSPI->tSPISTART.ulBulk = MSPI_START_VAL;

	MSPI_IntCLR();

	/*
	 * Read Test Code after write!!
	 */
//	{
//		uint32_t ulBuf[6];
//		MSPI_RegisterRead(Addr, &ulBuf[0], MSPI_READ_NONE);
//	}
}


#endif /* (USED_ROIC_DEF == ROIC_SW97500) */

