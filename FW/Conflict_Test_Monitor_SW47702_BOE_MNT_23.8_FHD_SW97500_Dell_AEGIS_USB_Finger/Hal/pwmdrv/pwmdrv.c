/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : pwmdrv.c
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
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
extern __IO uint16_t p_currentRowStart;
extern __IO uint16_t currentRowStart;
extern __IO uint16_t currentColStart;
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */


void PWMDRV_VSync_In_InterruptHandler(void)
{
	if(SCRB->SYS_INT_ST.tBit.int_vsyncin != 0)
	{
		SCRB->PWM_INT_CLR.tBit.vsyncin_int_clr = 0x1;
#if USED_TOUCH_TUNING_PROCESS
#include "app_tuning_process.h"
		if(gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index != tHalIntrHandle.ulTSyncInFallingCnt)
		{
			gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index = tHalIntrHandle.ulTSyncInFallingCnt;
			gtuning_ctrl_RawTune_Type.ulVsync_and_Touch_Timing_Continuos_Count = gtuning_ctrl_RawTune_Type.ulVsync_and_Touch_Timing_Continuos_CheckCount;
			gtuning_ctrl_RawTune_Type.ulVsync_and_Touch_Timing_Continuos_CheckCount = 0;
		}
		else
		{
			gtuning_ctrl_RawTune_Type.ulVsync_and_Touch_Timing_Continuos_CheckCount++;
		}
#endif /* USED_TOUCH_TUNING_PROCESS */
	}

	if(SCRB->SYS_INT_ST.tBit.int_tsync_ab != 0)
	{
		SCRB->PWM_INT_CLR.tBit.tsync_ab_int_clr = 0x1;
	}
}

void PWMDRV_TSync_In_InterruptHandler(void)
{
	if(SCRB->SYS_INT_ST.tBit.int_tsyncin != 0)
	{
#if USED_VCF_SYNC_CONTROL
		if(tHalIntrHandle.ulInitFirstFrame == 0)
#else
		if(tHalIntrHandle.ulInitFirstFrame == 1)
		{
			tHalIntrHandle.ulTSyncInRisingCnt = 0;
			tHalIntrHandle.ulTSyncInFallingCnt = 0;
		}
		else
#endif /* USED_VCF_SYNC_CONTROL */
		{
			eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();
			eActivePenType_t ePenType = hal_Info_GetControlActivePenOPType();

			if(GET_GPIO_TSYNC_IN_STATUS == GPIO_DATA_LOW)
			{
				/*
				 * Falling
				 */
#if USED_TSYNC_TMIC_GPIO_CONTROL
				GPIO_Set_DATA(_GPIO_TSYNC_TMIC, GPIO_DATA_LOW);
#endif /* USED_TSYNC_TMIC_GPIO_CONTROL */

#if (USED_VCF_SYNC_CONTROL == NO)
				tHalIntrHandle.ulTSyncInFallingCnt++;
	#if USED_LOCAL_IDLE_MODE_CONTROL
				if(IS_IDLE_MODE(eSensingMode))
				{
					if(tHalIntrHandle.ulTSyncInFallingCnt >= LOCAL_IDLE_LHB_NUM)
					{
						tHalIntrHandle.ulTSyncInFallingCnt = 0;
					}
				}
				else
	#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
				{
					if(tHalIntrHandle.ulTSyncInFallingCnt >= LHB_NUM)
					{
						tHalIntrHandle.ulTSyncInFallingCnt = 0;
//						_gT(_GPIO_TP_INTR);
					}
				}

#endif /* USED_VCF_SYNC_CONTROL */

				switch(ePenType)
				{
#if ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN))
					case ACTIVEPEN_TYPE_LOCAL_MS:
					{
						if(IS_FINGER_PEN_MODE(eSensingMode))
						{
							if(IS_ACTIVE_MODE(eSensingMode))
							{
	#if (USED_ECLK_ON_OFF_CONTROL && (USED_ROIC_DEF == ROIC_SWL92407))
								if(tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
								   tHalIntrHandle.ulTSyncInFallingCnt == 8 ||
								   tHalIntrHandle.ulTSyncInFallingCnt == 9)
								{
									if(HAL_GetECLKOnOffControl())
									{
										HAL_ECLK_Off();
									}
								}
	#endif /* #if (USED_ECLK_ON_OFF_CONTROL && (USED_ROIC_DEF == ROIC_SWL92407)) */

	#if (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON)
								if(HAL_GetTPICMuxEnControl())
								{
									if (tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 2 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 3 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 4 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 5 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 6 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 7 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 9 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 10 ||
		//								tHalIntrHandle.ulTSyncInFallingCnt == 11 ||
		//								tHalIntrHandle.ulTSyncInFallingCnt == 12 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 13 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 14 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 15 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 0)
									{
										SET_GPIO_MUX_EN_TPIC_STATUS = GPIO_DATA_HIGH;
//										GPIO_Set_DATA(_GPIO_MUX_EN_TPIC, GPIO_DATA_HIGH);
									}
								}
	#endif /* (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON) */
							}
							else
							{
	#if USED_LOCAL_IDLE_MODE_CONTROL
	#if (USED_ECLK_ON_OFF_CONTROL && (USED_ROIC_DEF == ROIC_SWL92407))
								if(tHalIntrHandle.ulTSyncInFallingCnt != 2)
								{
									if(HAL_GetECLKOnOffControl())
									{
										HAL_ECLK_Off();
									}
								}
	#endif /* (USED_ECLK_ON_OFF_CONTROL && (USED_ROIC_DEF == ROIC_SWL92407)) */
	#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
	#if (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON)
	#endif /* (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON) */
							}
						}
						else
						{
	#if (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON)
							if(HAL_GetTPICMuxEnControl())
							{
								if (tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 2 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 4 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 5 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 6 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 7 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 8 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 9 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 10 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 11 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 12 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 13 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 14 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 0)
								{
									SET_GPIO_MUX_EN_TPIC_STATUS = GPIO_DATA_HIGH;
//									GPIO_Set_DATA(_GPIO_MUX_EN_TPIC, GPIO_DATA_HIGH);
								}
							}
	#endif /* (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON) */
						}

						break;
					}
					case ACTIVEPEN_TYPE_LOCAL_WACOM:
					{
						break;
					}
#endif /* ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)) */
					case ACTIVEPEN_TYPE_LOCAL_WGP:
					{
#if (USED_GPIO_UPLINK_LEVEL_CONTROL && (DEF_UPLINK_CONTROL_OPERATION == DEF_UPLINK_SW_CONTROL))
						if(tHalIntrHandle.ulTSyncInFallingCnt == 1)
						{
							GPIO_Set_DATA(_GPIO_Uplink_GPIO, GPIO_DATA_HIGH);
						}
#endif /* (USED_GPIO_UPLINK_LEVEL_CONTROL && (DEF_UPLINK_CONTROL_OPERATION == DEF_UPLINK_SW_CONTROL)) */

#if USED_PEN_MODE_OPERATION
						if(IS_FINGER_PEN_MODE(eSensingMode))
						{
	#if (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON)
							// MUX EN Code Add
							if(HAL_GetTPICMuxEnControl())
							{
								bool_t bIsControl = NO;
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
								if (tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 2 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 3 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 4 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 5 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 6 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 7 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 0)
								{
									bIsControl = YES;
								}
		#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
			#if USED_WGP_16LHB_ACTIVEPEN
				#if  USED_LOCAL_IDLE_MODE_CONTROL
								if(IS_ACTIVE_MODE(eSensingMode))
								{
									if (tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 2 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 5 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 6 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 7 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 8 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 9 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 10 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 11 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 12 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 13 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 14 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 15 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 0)
									{
										bIsControl = YES;
									}
								}
								else
								{
					#if USED_LOCAL_IDLE_30Hz
									if (tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 15 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 16)
					#else /* USED_LOCAL_IDLE_30Hz */
										if (tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
											tHalIntrHandle.ulTSyncInFallingCnt == 15 ||
											tHalIntrHandle.ulTSyncInFallingCnt == 0)
					#endif /* USED_LOCAL_IDLE_30Hz */
									{
										bIsControl = YES;
									}
								}
				#else
								if(IS_ACTIVE_MODE(eSensingMode))
								{
									if (tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 2 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 5 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 6 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 7 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 8 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 9 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 10 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 11 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 12 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 13 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 14 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 15 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 0)
									{
										bIsControl = YES;
									}
								}
				#endif
			#else /* USED_WGP_16LHB_ACTIVEPEN */
								if (tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 2 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 4 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 5 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 6 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 7 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 8 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 9 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 10 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 11 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 12 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 13 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 14 ||
									tHalIntrHandle.ulTSyncInFallingCnt == 0)
								{
									bIsControl = YES;
								}
			#endif /* USED_WGP_16LHB_ACTIVEPEN */
		#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */

								if(bIsControl)
								{
									SET_GPIO_MUX_EN_TPIC_STATUS = GPIO_DATA_HIGH;
//									GPIO_Set_DATA(_GPIO_MUX_EN_TPIC, GPIO_DATA_HIGH);
								}
							}
	#endif /* (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON) */

	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
//							if(tHalIntrHandle.ulTSyncInFallingCnt == 1)
//							{
//								/*
//								 * Defense Code!! for matching sync mspi buf index
//								 */
//								MSPI_Set_BUFSIZE_FingerPenMode(0);
//				//				MSPI->tMSPI_FINDEX0.tBit.findex0 = 0;
//							}
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
						}
						else
#endif /* USED_PEN_MODE_OPERATION */
						{
#if USED_ECLK_ON_OFF_CONTROL
							if(HAL_GetECLKOnOffControl())
							{
								HAL_ECLK_On();
							}
#endif /* USED_ECLK_ON_OFF_CONTROL */
#if (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON)
							// MUX EN Code Add
							if(HAL_GetTPICMuxEnControl())
							{
								bool_t bIsControl = NO;
								if(IS_ACTIVE_MODE(eSensingMode))
								{
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
									if (tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 2 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 4 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 6 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 0)
	#elif (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3)
	#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
		#if USED_WGP_16LHB_ACTIVEPEN
										if (
			#if USED_PEN_MODE_OPERATION
										tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
			#endif /* USED_PEN_MODE_OPERATION */
										tHalIntrHandle.ulTSyncInFallingCnt == 6 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 7 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 8 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 14 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 15 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 0)
		#else /* USED_WGP_16LHB_ACTIVEPEN */
									if (tHalIntrHandle.ulTSyncInFallingCnt == 1 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 5 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 6 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 7 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 13 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 14 ||
										tHalIntrHandle.ulTSyncInFallingCnt == 0)
		#endif /* USED_WGP_16LHB_ACTIVEPEN */
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
									{
										bIsControl = YES;
									}
								}
								else
								{
									if (tHalIntrHandle.ulTSyncInFallingCnt == 0)
									{
										bIsControl = YES;
									}
								}

								if(bIsControl)
								{
									SET_GPIO_MUX_EN_TPIC_STATUS = GPIO_DATA_HIGH;
								}
							}
#endif /* (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON) */
						}
						break;
					}
				}
#if USED_MSPEN_LINEDIM_WORKAROUND
				if(ePenType == ACTIVEPEN_TYPE_LOCAL_MS)
				{
					switch(tHalIntrHandle.ulTSyncInFallingCnt)
					{
						case 1: case 8: case 15:
						{
							/*
							 * CMUX Off
							 */
							MSPI_Set_TLPMODE();
							MSPI_RegisterWrite(0x3FE, 0x1000);
							MSPI_Set_AITMODE(HAL_GetSensingMode());
							MSPI_Set_BUFSIZE_FingerPenMode(0);
							MSPI->SPIAITSTART = MSPI_START_VAL;
							break;
						}
						case 2:
						{
							/*
							 * CMUX On
							 */
							MSPI_Set_TLPMODE();
							MSPI_RegisterWrite(0x3FE, 0x2000);
							MSPI_Set_AITMODE(HAL_GetSensingMode());
							MSPI_Set_BUFSIZE_FingerPenMode(0);
							MSPI->SPIAITSTART = MSPI_START_VAL;
							break;
						}
						case 10:
						{
							/*
							 * CMUX On
							 */
							MSPI_Set_TLPMODE();
							MSPI_RegisterWrite(0x3FE, 0x2000);
							MSPI_Set_AITMODE(HAL_GetSensingMode());
							MSPI_Set_BUFSIZE_FingerPenMode(6);
							MSPI->SPIAITSTART = MSPI_START_VAL;
							break;
						}
						case 0:
						{
							/*
							 * CMUX On
							 */
							MSPI_Set_TLPMODE();
							MSPI_RegisterWrite(0x3FE, 0x2000);
							MSPI_Set_AITMODE(HAL_GetSensingMode());
							MSPI_Set_BUFSIZE_FingerPenMode(11);
							MSPI->SPIAITSTART = MSPI_START_VAL;
							break;
						}
					}
				}
#endif /* USED_MSPEN_LINEDIM_WORKAROUND */
			}
			else
			{
				/*
				 * Rising
				 */
#if USED_TSYNC_TMIC_GPIO_CONTROL
				GPIO_Set_DATA(_GPIO_TSYNC_TMIC, GPIO_DATA_HIGH);
#endif /* USED_TSYNC_TMIC_GPIO_CONTROL */

#if (USED_VCF_SYNC_CONTROL == NO)
				tHalIntrHandle.ulTSyncInRisingCnt++;

#if USED_LOCAL_IDLE_MODE_CONTROL
				if(IS_IDLE_MODE(eSensingMode))
				{
					if(tHalIntrHandle.ulTSyncInRisingCnt >= LOCAL_IDLE_LHB_NUM)
					{
						tHalIntrHandle.ulTSyncInRisingCnt = 0;
					}
				}
				else
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
				{
					if(tHalIntrHandle.ulTSyncInRisingCnt >= LHB_NUM)
					{
						tHalIntrHandle.ulTSyncInRisingCnt = 0;
					}
				}
#endif /* USED_VCF_SYNC_CONTROL */

				if(tHalIntrHandle.ulTSyncInRisingCnt == 0)
				{
#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
	#if 1 // R00
					SCRB->SYS_RST_CTL.tBit.pwm_rst = 1;
					SCRB->SYS_RST_CTL.tBit.pwm_rst = 0;
	#else // R01
					PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = DISABLE;
					delay_us(30);
					PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = ENABLE;
	#endif
#else /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
	#if 1 // R00
					SCRB->SYS_RST_CTL.tBit.pwm_rst = 1;
					SCRB->SYS_RST_CTL.tBit.pwm_rst = 0;
	#else // R01
					PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = DISABLE;
					delay_us(30);
					PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = ENABLE;
	#endif
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
					tHalIntrHandle.ulTSyncInFallingCnt = 0; // Sync Matching Count of Rising and Falling
					tHalIntrHandle.ulVSyncFlag = 1;

#if USED_LOCAL_IDLE_30Hz
					if(IS_IDLE_MODE(eSensingMode))
					{
						tCFGR_SYS_CFG_t tCFGR_SYS_CFG;
						const tModuleSRICCommonConf_t * pktmoduleSRICCommonConf = module_SRIC_GetCommonConfig();
						tCFGR_SYS_CFG.ulBulk = pktmoduleSRICCommonConf->CFGR_SYS_CFG.ulBulk;
						MSPI_Set_TLPMODE();
						/*
						 * ROIC Power On!!
						 */
						MSPI_RegisterWrite((uint32_t)(0x01C0), pktmoduleSRICCommonConf->CFGR_SSU_PW_CTRL.ulBulk);
						/*
						 * TG Reset 1 -> 0
						 */
						tCFGR_SYS_CFG.tBit.tg_reset = 1;
						MSPI_RegisterWrite((uint32_t)(0x0014), tCFGR_SYS_CFG.ulBulk);
						tCFGR_SYS_CFG.tBit.tg_reset = 0;
						MSPI_RegisterWrite((uint32_t)(0x0014), tCFGR_SYS_CFG.ulBulk);

						MSPI_Set_AITMODE(HAL_GetSensingMode());
					}
#endif /* USED_LOCAL_IDLE_30Hz */
//					_gT(_GPIO_TP_INTR);
				}

				switch(ePenType)
				{
#if ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN))
					case ACTIVEPEN_TYPE_LOCAL_MS:
					{
//						if(IS_FINGER_PEN_MODE(eSensingMode))
						{
	#if USED_TPIC_VCOM_LEVEL_I2CM_CONTROL
							switch(tHalIntrHandle.ulTSyncInRisingCnt)
							{
								case 0:
								{
									/*
									 * 첫 번째 Beacon
									 */
									PWMDRV_Set_DSSS_CODE(hal_Info_GetMPPPen1stBeaconType());
									HAL_TPIC_UplinkModulation_LevelCtrl_Enable();
									break;
								}
								case 1:
								{
									HAL_TPIC_UplinkModulation_LevelCtrl_Disable();
									break;
								}
								case 2:
								case 3:
								case 4:
								case 5:
								case 6:
								case 7:
									break;
								case 8:
								{
									/*
									 * 두 번째 Beacon
									 */
									PWMDRV_Set_DSSS_CODE(PWM_MPP_PEN_2nd_BEACON);
									HAL_TPIC_UplinkModulation_LevelCtrl_Enable();
									break;
								}
								case 9:
									HAL_TPIC_UplinkModulation_LevelCtrl_Disable();
									break;
								case 10:
								case 11:
								case 12:
								case 13:
								case 14:
								case 15:
									break;
							}
	#else /* USED_TPIC_VCOM_LEVEL_I2CM_CONTROL */
							if(tHalIntrHandle.ulTSyncInRisingCnt == 0)
							{
								/*
								 * 첫 번째 Beacon
								 */
								PWMDRV_Set_DSSS_CODE(hal_Info_GetMPPPen1stBeaconType());
							}
							else if(tHalIntrHandle.ulTSyncInRisingCnt == 8)
							{
								/*
								 * 두 번째 Beacon
								 */
								PWMDRV_Set_DSSS_CODE(PWM_MPP_PEN_2nd_BEACON);
							}
	#endif /* USED_TPIC_VCOM_LEVEL_I2CM_CONTROL */
						}
						break;
					}
					case ACTIVEPEN_TYPE_LOCAL_WACOM:
					{
	#if USED_SW47701_PINGONLY_LHB_WORKAROUND
						if(tHalIntrHandle.ulTSyncInRisingCnt == 10)
						{
							PWMDRV->PWM_SRIC_CR.tBit.pen_s_en = DISABLE;
							PWMDRV->PWM_SRIC_CR.tBit.pen_s_ping_en = DISABLE;
						}
		#if (USED_ROIC_DEF == ROIC_SWL92406)
						else if(tHalIntrHandle.ulTSyncInRisingCnt == 12)
						{
							PWMDRV->PWM_SRIC_CR.tBit.pen_s_en = ENABLE;
							PWMDRV->PWM_SRIC_CR.tBit.pen_s_ping_en = ENABLE;
						}
		#elif (USED_ROIC_DEF == ROIC_SWL92407)
						else if(tHalIntrHandle.ulTSyncInRisingCnt == 11)
						{
							PWMDRV->PWM_SRIC_CR.tBit.pen_s_en = ENABLE;
							PWMDRV->PWM_SRIC_CR.tBit.pen_s_ping_en = ENABLE;
						}
		#endif /* (USED_ROIC_DEF == ROIC_SWL92406) */
	#endif /* USED_SW47701_PINGONLY_LHB_WORKAROUND */
						break;
					}
#endif /* ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)) */
					case ACTIVEPEN_TYPE_LOCAL_WGP:
					{
#if (USED_GPIO_UPLINK_LEVEL_CONTROL && (DEF_UPLINK_CONTROL_OPERATION == DEF_UPLINK_SW_CONTROL))
						if(tHalIntrHandle.ulTSyncInRisingCnt == 1)
						{
							GPIO_Set_DATA(_GPIO_Uplink_GPIO, GPIO_DATA_LOW);
						}
#endif /* (USED_GPIO_UPLINK_LEVEL_CONTROL && (DEF_UPLINK_CONTROL_OPERATION == DEF_UPLINK_SW_CONTROL)) */

#if USED_PEN_MODE_OPERATION
						if(IS_FINGER_PEN_MODE(eSensingMode))
						{
							if(tHalIntrHandle.ulTSyncInRisingCnt == 0)
							{
								/*
								 * 첫 번째 Beacon
								 */
								PWMDRV_Set_DSSS_INFO(hal_Info_GetWGPPenBeaconType());
							}
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
							if(tHalIntrHandle.ulLocalIndexChangeStart == 1 && tHalIntrHandle.ulTSyncInRisingCnt == 1)
							{
								tAlgorithmInfo_t * ptAlgorithmInfo = algorithm_GetInfo();
								SRIC_SetLocalIndex(sensingRowStart);
								MSPI_Set_BUFSIZE_FingerPenMode(0);
								p_currentRowStart = currentRowStart;
								currentRowStart = sensingRowStart;
								currentColStart = ptAlgorithmInfo->tPenInfo.ucCurrentColumnStart;
							}
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN) */
						}
						else
#endif /* USED_PEN_MODE_OPERATION */
						{
#if (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON && !USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM)
							if(HAL_GetTPICMuxEnControl())
							{

	#if USED_PWM_PULSE_END_FLAG_CHECK
								if(tHalIntrHandle.ulPWM_Pulse_End_Flag == YES)
								{
		#if USED_MUX_EN_DONOT_CONTROL_IN_ACTVIEMODE
									SET_GPIO_MUX_EN_TPIC_STATUS = GPIO_DATA_HIGH;
		#else /* USED_MUX_EN_DONOT_CONTROL_IN_ACTVIEMODE */
									SET_GPIO_MUX_EN_TPIC_STATUS = GPIO_DATA_LOW;
		#endif /* USED_MUX_EN_DONOT_CONTROL_IN_ACTVIEMODE */
	#if USED_TPIC_MUXEN_2_ON_OFF_CONTROL
									GPIO_Set_DATA(_GPIO_MUX_EN2_TPIC, GPIO_DATA_LOW);
	#endif /* USED_TPIC_MUXEN_2_ON_OFF_CONTROL */
									tHalIntrHandle.ulPWM_Pulse_End_Flag = NO;
								}
	#endif /* USED_PWM_PULSE_END_FLAG_CHECK */
							}
#endif /* (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TSYNC2_INPUT_FROM_TCON !USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM) */
						}
						break;
					}
				}

#if (!USED_QUEUECOMMONDATA_SEND_Timer_Tick)
				#ifdef MODE_I2C
					QueueCommonData_I2C();
				#else
					QueueCommonData_USB();
				#endif
#endif /* (!USED_QUEUECOMMONDATA_SEND_Timer_Tick) */
			}
		}

		SCRB->PWM_INT_CLR.tBit.tsyncin_int_clr = 0x1;
	}
}

void PWMDRV_TSync_Out_InterruptHandler(void)
{
	if(SCRB->SYS_INT_ST.tBit.int_tsyncout != 0)
	{
#if USED_VCF_SYNC_CONTROL
		if(tHalIntrHandle.ulInitFirstFrame == 1)
		{
			tHalIntrHandle.ulTSyncInRisingCnt = 0;
			tHalIntrHandle.ulTSyncInFallingCnt = 0;
		}
		else
		{
			if(IS_GPIO_PIN(_GPIO_TSYNC_IN) == GPIO_DATA_LOW)
			{
				/*
				 * Falling
				 */
				tHalIntrHandle.ulTSyncInFallingCnt++;
				if(tHalIntrHandle.ulTSyncInFallingCnt >= LHB_NUM)
				{
					tHalIntrHandle.ulTSyncInFallingCnt = 0;
				}
				
				// VCF Signal : Floating Sync
				if(tHalIntrHandle.ulTSyncInFallingCnt != 1)
					_gOut(_GPIO_FLOAT_SYNC, GPIO_DATA_LOW);
				
				if(HAL_GetPrivacyEnControl())
				{
					// VCF Signal : Discharging Sync
					if(tHalIntrHandle.ulTSyncInFallingCnt == 2)
						_gOut(_GPIO_DISCHG_SYNC, GPIO_DATA_HIGH);
				}
			}
			else
			{
				/*
				 * Rising
				 */
				tHalIntrHandle.ulTSyncInRisingCnt++;
				if(tHalIntrHandle.ulTSyncInRisingCnt >= LHB_NUM)
				{
					tHalIntrHandle.ulTSyncInRisingCnt = 0;
				}
				
				// VCF Signal : Floating Sync
				if(tHalIntrHandle.ulTSyncInRisingCnt != 1)
					_gOut(_GPIO_FLOAT_SYNC, GPIO_DATA_HIGH);
				
				if(HAL_GetPrivacyEnControl())
				{
					// VCF Signal : Discharging Sync
					if(tHalIntrHandle.ulTSyncInRisingCnt == 0)
						_gOut(_GPIO_DISCHG_SYNC, GPIO_DATA_LOW);
					
				#if (USED_VCF_SYNC_CONTROL_FREQ == VCF_SYNC_30Hz)
					// VCF Signal : VCF Sync 30Hz
					if(tHalIntrHandle.ulTSyncInRisingCnt == 0)		_gToggle(_GPIO_VCF_SYNC);
				#elif (USED_VCF_SYNC_CONTROL_FREQ == VCF_SYNC_60Hz)
					// VCF Signal : VCF Sync 60Hz
					if(tHalIntrHandle.ulTSyncInRisingCnt == 0)
						_gOut(_GPIO_VCF_SYNC, GPIO_DATA_HIGH);
					if(tHalIntrHandle.ulTSyncInRisingCnt == 9)
						_gOut(_GPIO_VCF_SYNC, GPIO_DATA_LOW);
				#endif
					
				}
			}
		}
#endif /* USED_VCF_SYNC_CONTROL */

#if (USED_S3_VDD_OE_INPUT_OUTPUT_CTRL || USED_ECLK_ON_OFF_CONTROL || USED_TPIC_MUXEN_ON_OFF_CONTROL)
		if(tHalIntrHandle.ulInitFirstFrame == 1)
		{
//			_gT(_GPIO_TP_INTR);
		}
		else
		{
#if USED_PWM_PULSE_END_FLAG_CHECK
			if(tHalIntrHandle.ulPWM_Pulse_End_Flag == YES)
			{
				tHalIntrHandle.ulPWM_Pulse_End_Flag = NO;
	#if (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM)
				if(HAL_GetTPICMuxEnControl())
				{
					SET_GPIO_MUX_EN_TPIC_STATUS = GPIO_DATA_LOW;
		#if USED_TPIC_MUXEN_2_ON_OFF_CONTROL
					GPIO_Set_DATA(_GPIO_MUX_EN2_TPIC, GPIO_DATA_LOW);
		#endif /* USED_TPIC_MUXEN_2_ON_OFF_CONTROL */
				}
	#endif /* (USED_TPIC_MUXEN_ON_OFF_CONTROL && !USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM) */
			}
			else
#endif /* USED_PWM_PULSE_END_FLAG_CHECK */
			{
#if USED_ECLK_ON_OFF_CONTROL
				if(HAL_GetECLKOnOffControl())
				{
					HAL_ECLK_On();
				}
#endif /* USED_ECLK_ON_OFF_CONTROL */

#if USED_TPIC_MUXEN_ON_OFF_CONTROL
				if(HAL_GetTPICMuxEnControl())
				{
					SET_GPIO_MUX_EN_TPIC_STATUS = GPIO_DATA_HIGH;
	#if USED_TPIC_MUXEN_2_ON_OFF_CONTROL
					GPIO_Set_DATA(_GPIO_MUX_EN2_TPIC, GPIO_DATA_HIGH);
	#endif /* USED_TPIC_MUXEN_2_ON_OFF_CONTROL */
				}
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
#if USED_S3_VDD_OE_INPUT_OUTPUT_CTRL
				HAL_Change_S3_VDD_OddEven_Stauts();
#endif /* USED_S3_VDD_OE_INPUT_OUTPUT_CTRL */
			}
		}
#endif /* (USED_S3_VDD_OE_INPUT_OUTPUT_CTRL || USED_ECLK_ON_OFF_CONTROL || USED_TPIC_MUXEN_ON_OFF_CONTROL) */

		SCRB->PWM_INT_CLR.tBit.tsyncout_int_clr = 0x1;
	}
}

void PWMDRV_PWM_Out_InterruptHandler(void)
{
	if(SCRB->SYS_INT_ST.tBit.r_pwm_ab_intr != 0)
	{
		SCRB->PWM_INT_CLR.tBit.pwm_ab_int_clr = 0x1;
	}

	if(SCRB->SYS_INT_ST.tBit.r_pwm_frame_intr != 0)
	{
		SCRB->PWM_INT_CLR.tBit.pwm_frame_int_clr = 0x1;
	}

	if(SCRB->SYS_INT_ST2.tBit.int_lhb != 0)
	{
#if (USED_TPIC_MUXEN_ON_OFF_CONTROL && USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM)
		if(HAL_GetTPICMuxEnControl())
		{
			// MUX EN Code Add
	#if USED_MUX_EN_DONOT_CONTROL_IN_ACTVIEMODE
			if(IS_ACTIVE_MODE(HAL_GetSensingMode()))
			{
				SET_GPIO_MUX_EN_TPIC_STATUS = GPIO_DATA_HIGH;
			}
			else
			{
				SET_GPIO_MUX_EN_TPIC_STATUS = GPIO_DATA_LOW;
			}
	#else /* USED_MUX_EN_DONOT_CONTROL_IN_ACTVIEMODE */
			SET_GPIO_MUX_EN_TPIC_STATUS = GPIO_DATA_LOW;
	#endif /* USED_MUX_EN_DONOT_CONTROL_IN_ACTVIEMODE */
	#if USED_TPIC_MUXEN_2_ON_OFF_CONTROL
			GPIO_Set_DATA(_GPIO_MUX_EN2_TPIC, GPIO_DATA_LOW);
	#endif /* USED_TPIC_MUXEN_2_ON_OFF_CONTROL */
		}
#endif /* (USED_TPIC_MUXEN_ON_OFF_CONTROL && USED_TPIC_MUXEN_OFF_TIMING_LAST_PWM) */

#if USED_PWM_PULSE_END_FLAG_CHECK
		tHalIntrHandle.ulPWM_Pulse_End_Flag = YES;
#endif /* USED_PWM_PULSE_END_FLAG_CHECK */

		SCRB->PWM_INT_CLR.tBit.lhb_int_clr = 0x1;
	}
}

void PWMDRV_Init(eSENSING_MODE_t _eSensingMode)
{
	Fncp_VSYNC_IN_IRQHandler = &PWMDRV_VSync_In_InterruptHandler;
	Fncp_TSYNC_IN_IRQHandler = &PWMDRV_TSync_In_InterruptHandler;
	Fncp_TSYNC_OUT_IRQHandler = &PWMDRV_TSync_Out_InterruptHandler;
	Fncp_PWMDRV_IRQHandler = &PWMDRV_PWM_Out_InterruptHandler;

	PWMDRV_RegisterInit(_eSensingMode);
	PWMDRV_GPIO_Init(_eSensingMode);

#if USED_MNT_S3_MODE_FUNCTION
	if(IS_S3_MODE(_eSensingMode))
	{
		SCRB->PWM_INT_CTRL.tBit.int_en_pwm_ab = PWM_INTR_DISABLE;
		SCRB->PWM_INT_CTRL.tBit.int_en_pwm_frame = PWM_INTR_DISABLE;
		SCRB->PWM_INT_CTRL.tBit.int_en_tsync_ab = PWM_INTR_DISABLE;
#if (USED_TPIC_MUXEN_ON_OFF_CONTROL || USED_ECLK_ON_OFF_CONTROL)
		SCRB->PWM_INT_CTRL.tBit.int_en_lhb = PWM_INTR_ENABLE;
	#if USED_PWM_PULSE_END_FLAG_CHECK
		SCRB->PWM_INT_CTRL.tBit.int_en_tsyncout = PWM_INTR_BOTH_EDGE;
	#else /* USED_PWM_PULSE_END_FLAG_CHECK */
		SCRB->PWM_INT_CTRL.tBit.int_en_tsyncout = PWM_INTR_FALLING_EDGE;
	#endif /* USED_PWM_PULSE_END_FLAG_CHECK */
#else /* (USED_TPIC_MUXEN_ON_OFF_CONTROL || USED_ECLK_ON_OFF_CONTROL) */
		SCRB->PWM_INT_CTRL.tBit.int_en_lhb = PWM_INTR_DISABLE;
		SCRB->PWM_INT_CTRL.tBit.int_en_tsyncout = PWM_INTR_RISING_EDGE;
#endif /* (USED_TPIC_MUXEN_ON_OFF_CONTROL || USED_ECLK_ON_OFF_CONTROL) */

#if USED_TOUCH_TUNING_PROCESS
		SCRB->PWM_INT_CTRL.tBit.int_en_vsyncin = PWM_INTR_RISING_EDGE;
#else /* USED_TOUCH_TUNING_PROCESS */
		SCRB->PWM_INT_CTRL.tBit.int_en_vsyncin = PWM_INTR_DISABLE;
#endif /* USED_TOUCH_TUNING_PROCESS */
		SCRB->PWM_INT_CTRL.tBit.int_en_tsyncin = PWM_INTR_DISABLE;
		SCRB->PWM_INT_CTRL.tBit.int_tsyncin_src_sel = PWM_TYNCIN_INT_SOURCE_TSYNC_D;

		{
			tPWM_INTR_CFG_t tPWM_INTR_CFG[4] =
			{
				{VSYNC_IN_IRQn, VSYNC_IN_IRQn_Priority, DISABLE},
				{TSYNC_IN_IRQn, TSYNC_IN_IRQn_Priority, DISABLE},
				{TSYNC_OUT_IRQn, TSYNC_OUT_IRQn_Priority, ENABLE},
	#if (USED_TPIC_MUXEN_ON_OFF_CONTROL || USED_ECLK_ON_OFF_CONTROL)
				{PWMDRV_IRQn, PWMDRV_IRQn_Priority, ENABLE}
	#else /* (USED_TPIC_MUXEN_ON_OFF_CONTROL || USED_ECLK_ON_OFF_CONTROL) */
				{PWMDRV_IRQn, PWMDRV_IRQn_Priority, DISABLE}
	#endif /* (USED_TPIC_MUXEN_ON_OFF_CONTROL || USED_ECLK_ON_OFF_CONTROL) */
			};
			PWMDRV_ITConfig((tPWM_INTR_CFG_t *)&tPWM_INTR_CFG[0], 4);
		}
	}
	else
#endif /* USED_MNT_S3_MODE_FUNCTION */
	{
		SCRB->PWM_INT_CTRL.tBit.int_en_pwm_ab = PWM_INTR_DISABLE;
		SCRB->PWM_INT_CTRL.tBit.int_en_pwm_frame = PWM_INTR_DISABLE;
		SCRB->PWM_INT_CTRL.tBit.int_en_tsync_ab = PWM_INTR_DISABLE;
#if USED_TPIC_MUXEN_ON_OFF_CONTROL
		SCRB->PWM_INT_CTRL.tBit.int_en_lhb = PWM_INTR_ENABLE;
#else /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
		SCRB->PWM_INT_CTRL.tBit.int_en_lhb = PWM_INTR_DISABLE;
#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */

#if USED_TOUCH_TUNING_PROCESS
		SCRB->PWM_INT_CTRL.tBit.int_en_vsyncin = PWM_INTR_RISING_EDGE;
#else /* USED_TOUCH_TUNING_PROCESS */
		SCRB->PWM_INT_CTRL.tBit.int_en_vsyncin = PWM_INTR_DISABLE;
#endif /* USED_TOUCH_TUNING_PROCESS */
		SCRB->PWM_INT_CTRL.tBit.int_en_tsyncin = PWM_INTR_BOTH_EDGE;
#if USED_VCF_SYNC_CONTROL
		SCRB->PWM_INT_CTRL.tBit.int_en_tsyncout = PWM_INTR_BOTH_EDGE; // Rising
#else
		SCRB->PWM_INT_CTRL.tBit.int_en_tsyncout = PWM_INTR_DISABLE; // Rising
#endif /* USED_VCF_SYNC_CONTROL */
		SCRB->PWM_INT_CTRL.tBit.int_tsyncin_src_sel = PWM_TYNCIN_INT_SOURCE_TSYNC_T;

		{
	#if USED_DO_NOT_TOUCH_ONLY_DISPLAY
			tPWM_INTR_CFG_t tPWM_INTR_CFG[4] =
			{
				{VSYNC_IN_IRQn, VSYNC_IN_IRQn_Priority, DISABLE},
				{TSYNC_IN_IRQn, TSYNC_IN_IRQn_Priority, DISABLE},
				{TSYNC_OUT_IRQn, TSYNC_OUT_IRQn_Priority, DISABLE},
				{PWMDRV_IRQn, PWMDRV_IRQn_Priority, DISABLE}
			};
	#else /* USED_DO_NOT_TOUCH_ONLY_DISPLAY */
			tPWM_INTR_CFG_t tPWM_INTR_CFG[4] =
			{
	#if USED_TOUCH_TUNING_PROCESS
				{VSYNC_IN_IRQn, VSYNC_IN_IRQn_Priority, ENABLE},
	#else /* USED_TOUCH_TUNING_PROCESS */
				{VSYNC_IN_IRQn, VSYNC_IN_IRQn_Priority, DISABLE},
	#endif /* USED_TOUCH_TUNING_PROCESS */

				{TSYNC_IN_IRQn, TSYNC_IN_IRQn_Priority, ENABLE},
	#if USED_VCF_SYNC_CONTROL
				{TSYNC_OUT_IRQn, TSYNC_OUT_IRQn_Priority, ENABLE},
	#else
				{TSYNC_OUT_IRQn, TSYNC_OUT_IRQn_Priority, DISABLE},
	#endif /* USED_VCF_SYNC_CONTROL */

	#if USED_TPIC_MUXEN_ON_OFF_CONTROL
				{PWMDRV_IRQn, PWMDRV_IRQn_Priority, ENABLE}
	#else /* USED_TPIC_MUXEN_ON_OFF_CONTROL */
				{PWMDRV_IRQn, PWMDRV_IRQn_Priority, DISABLE}
	#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL */

			};
	#endif /* USED_DO_NOT_TOUCH_ONLY_DISPLAY */
			PWMDRV_ITConfig((tPWM_INTR_CFG_t *)&tPWM_INTR_CFG[0], 4);
		}
	}
}

void PWMDRV_RegisterInit(eSENSING_MODE_t _eSensingMode)
{
	const tHalPwmdrvControlConf_t * ptHalPwmdrvControlConf = hal_pwmdrv_GetControlConfig();
	tCP_PWMGEN_CR0_t tCP_PWMGEN_CR0;
	tCP_PWMGEN_CR1_t tCP_PWMGEN_CR1;
	tCP_PWMGEN_CR2_t tCP_PWMGEN_CR2;

	tCP_PWMGEN_CR0.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR0.ulBulk;

#if USED_MNT_S3_MODE_FUNCTION
	if(IS_S3_MODE(_eSensingMode))
	{
		tCP_PWMGEN_CR0.tBit.pen_mode = (PWM_FULL_FINGER_MODE);
		PWMDRV->PWMGEN_CR1.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR1.ulBulk;
		PWMDRV->PWMGEN_CR2.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR2.ulBulk;
		PWMDRV->PWMGEN_CR2.tBit.total_mux_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_Idle_total_mux_num;
		PWMDRV->PWMGEN_CR2.tBit.finger_pwmnum = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_Idle_finger_pwmnum;


		PWMDRV->TSYNC_CR.ulBulk = ptHalPwmdrvControlConf->tCP_TSYNC_CR.ulBulk;
		PWMDRV->TSYNC_CR.tBit.tsync_num = 0;
		PWMDRV->TSYNC_CR.tBit.tsynct_in_sel = PWM_TSYNC_INTR_INTERNAL;
		PWMDRV->TSYNC_CR.tBit.tsynct_in_inv = 0;
		PWMDRV->TSYNC_CR.tBit.tsync_sric_in_sel = PWM_TSYNC_SRIC_INTR_INTERNAL;
		PWMDRV->TSYNC_CR.tBit.tsync_sric_out_inv = 0;
		{
#define TSYNCGEN_TIMING_DIV_VALUE		(534)
			uint32_t ulTotal_Time_usec;
//			ulTotal_Time_usec = (1000*1000/S3_MODE_FRAME_RATE_Hz)>>1; // 1LHB of 2LHB?? (/2)
//			PWMDRV->TE_TCH_T_HIGH = ((ulTotal_Time_usec-S3_MODE_TOUCH_TIME_usec)*100)/TSYNCGEN_TIMING_DIV_VALUE;
//			PWMDRV->TE_TCH_D_HIGH = ((ulTotal_Time_usec-S3_MODE_TOUCH_TIME_usec)*100)/TSYNCGEN_TIMING_DIV_VALUE;
//			PWMDRV->TE_TCH_LOW = (S3_MODE_TOUCH_TIME_usec*100)/TSYNCGEN_TIMING_DIV_VALUE;

			ulTotal_Time_usec = (1000*1000/S3_MODE_FRAME_RATE_Hz); // 1LHB of 1LHB
			PWMDRV->TE_TCH_T_HIGH = (S3_MODE_TOUCH_TIME_usec*100)/TSYNCGEN_TIMING_DIV_VALUE;
			PWMDRV->TE_TCH_D_HIGH = (S3_MODE_TOUCH_TIME_usec*100)/TSYNCGEN_TIMING_DIV_VALUE;
			PWMDRV->TE_TCH_LOW = ((ulTotal_Time_usec-S3_MODE_TOUCH_TIME_usec)*100)/TSYNCGEN_TIMING_DIV_VALUE;
#undef TSYNCGEN_TIMING_DIV_VALUE
		}
//		PWMDRV->TE_TCH_T_HIGH = 3933;//ptHalPwmdrvControlConf->tCP_TE_TCH_T_HIGH;
//		PWMDRV->TE_TCH_D_HIGH = 2000;//ptHalPwmdrvControlConf->tCP_TE_TCH_D_HIGH;
//		PWMDRV->TE_TCH_LOW = 749;//ptHalPwmdrvControlConf->tCP_TE_TCH_LOW;
	}
	else
#endif /* USED_MNT_S3_MODE_FUNCTION */
	{
		if(IS_FINGER_PEN_MODE(_eSensingMode))
		{
			tCP_PWMGEN_CR0.tBit.pen_mode = (PWM_LOCAL_PEN_MODE);
			if(IS_ACTIVE_MODE(_eSensingMode))
			{
				/*
				 * PWM Pulse Setting
				 */
				PWMDRV->PWMGEN_CR1.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR1.ulBulk;
				PWMDRV->PWMGEN_CR2.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR2.ulBulk;
				PWMDRV->TSYNC_CR.ulBulk = ptHalPwmdrvControlConf->tCP_TSYNC_CR.ulBulk;
			}
	#if USED_LOCAL_IDLE_MODE_CONTROL
			else
			{
				/*
				 * PWM Pulse Setting
				 */
				PWMDRV->PWMGEN_CR1.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR1.ulBulk;

				tCP_PWMGEN_CR2.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR2.ulBulk;
				tCP_PWMGEN_CR2.tBit.finger_pwmnum = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_nm_num;
				tCP_PWMGEN_CR2.tBit.total_mux_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_nm_total_mux_num;
				PWMDRV->PWMGEN_CR2.ulBulk = tCP_PWMGEN_CR2.ulBulk;

				PWMDRV->TSYNC_CR.ulBulk = ptHalPwmdrvControlConf->tCP_TSYNC_CR.ulBulk;
				PWMDRV->TSYNC_CR.tBit.tsync_num = (LOCAL_IDLE_LHB_NUM-1);
			}
	#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
		}
		else
		{
			tCP_PWMGEN_CR0.tBit.pen_mode = (PWM_FULL_FINGER_MODE);
			if(IS_ACTIVE_MODE(_eSensingMode))
			{
#if USED_NOISE_HOPPING_FREQ
				if(IS_ACTIVE_MODE_FRQ_MAIN(_eSensingMode))
				{
					/*
					 * PWM Pulse Setting
					 */
					PWMDRV->PWMGEN_CR1.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR1.ulBulk;
					tCP_PWMGEN_CR2.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR2.ulBulk;
					tCP_PWMGEN_CR2.tBit.total_mux_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_total_mux_num;
					PWMDRV->PWMGEN_CR2.ulBulk = tCP_PWMGEN_CR2.ulBulk;

					PWMDRV->TSYNC_CR.ulBulk = ptHalPwmdrvControlConf->tCP_TSYNC_CR.ulBulk;
				}
				else if(IS_ACTIVE_MODE_FRQ_HOP1(_eSensingMode))
				{
					/*
					 * PWM Pulse Setting
					 */
					PWMDRV->PWMGEN_CR1.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR1.ulBulk;
					tCP_PWMGEN_CR2.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR2.ulBulk;
					tCP_PWMGEN_CR2.tBit.finger_pwmnum = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_HoppFrq_finger_pwmnum;
					tCP_PWMGEN_CR2.tBit.total_mux_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_total_mux_num;
					PWMDRV->PWMGEN_CR2.ulBulk = tCP_PWMGEN_CR2.ulBulk;

					PWMDRV->TSYNC_CR.ulBulk = ptHalPwmdrvControlConf->tCP_TSYNC_CR.ulBulk;
				}
#else
				/*
				 * PWM Pulse Setting
				 */
				PWMDRV->PWMGEN_CR1.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR1.ulBulk;
				tCP_PWMGEN_CR2.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR2.ulBulk;
				tCP_PWMGEN_CR2.tBit.total_mux_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_total_mux_num;
				PWMDRV->PWMGEN_CR2.ulBulk = tCP_PWMGEN_CR2.ulBulk;

				PWMDRV->TSYNC_CR.ulBulk = ptHalPwmdrvControlConf->tCP_TSYNC_CR.ulBulk;
#endif
			}
#if USED_IDLE_MODE_CONTROL
			else
			{
				/*
				 * PWM Pulse Setting
				 */
				PWMDRV->PWMGEN_CR1.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR1.ulBulk;
				tCP_PWMGEN_CR2.ulBulk = ptHalPwmdrvControlConf->tCP_PWMGEN_CR2.ulBulk;
				tCP_PWMGEN_CR2.tBit.finger_pwmnum = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_nm_num;
				tCP_PWMGEN_CR2.tBit.total_mux_num = PARAMSET_PWMDRV_WGP_PWMGEN_CR2_nm_total_mux_num;
				PWMDRV->PWMGEN_CR2.ulBulk = tCP_PWMGEN_CR2.ulBulk;

				PWMDRV->TSYNC_CR.ulBulk = ptHalPwmdrvControlConf->tCP_TSYNC_CR.ulBulk;
			}
#endif /* USED_IDLE_MODE_CONTROL */
		}

		PWMDRV->TE_TCH_T_HIGH = ptHalPwmdrvControlConf->tCP_TE_TCH_T_HIGH;
		PWMDRV->TE_TCH_D_HIGH = ptHalPwmdrvControlConf->tCP_TE_TCH_D_HIGH;
		PWMDRV->TE_TCH_LOW = ptHalPwmdrvControlConf->tCP_TE_TCH_LOW;
	}

	PWMDRV->PWMGEN_CR0.ulBulk = tCP_PWMGEN_CR0.ulBulk;
	PWMDRV->SET_TX_CR.ulBulk = ptHalPwmdrvControlConf->tCP_SET_TX_CR.ulBulk;
	PWMDRV->TSYNC_D2_CR.ulBulk = ptHalPwmdrvControlConf->tCP_TSYNC_D2_CR.ulBulk;
	PWMDRV->DLY_CNT1.ulBulk = ptHalPwmdrvControlConf->tCP_DLY_CNT1.ulBulk;
	PWMDRV->DLY_CNT2.ulBulk = ptHalPwmdrvControlConf->tCP_DLY_CNT2.ulBulk;
	PWMDRV->DLY_CNT3.ulBulk = ptHalPwmdrvControlConf->tCP_DLY_CNT3.ulBulk;
	PWMDRV->TSYNC_TPIC_CR.ulBulk = ptHalPwmdrvControlConf->tCP_TSYNC_TPIC_CR.ulBulk;
	PWMDRV->PWM_DLY1.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_DLY1.ulBulk;
	PWMDRV->DSSS_INFO0.ulBulk = ptHalPwmdrvControlConf->tCP_DSSS_INFO0.ulBulk;
	PWMDRV->PWM_TPIC_CR.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_TPIC_CR.ulBulk;
	PWMDRV->PWM_SRIC_CR.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_SRIC_CR.ulBulk;
	PWMDRV->PWM_MUX_CR.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_MUX_CR.ulBulk;
#if USED_NOISE_HOPPING_FREQ
	{
		if(IS_ACTIVE_MODE_FRQ_HOP1(_eSensingMode))
		{
			PWMDRV->DMY_FREQ = PARAMSET_PWMDRV_WGP_HOPP1_DMY_FREQ;
			tCP_FREQ_CR1_t tCP_FREQ_CR1;
			tCP_FREQ_CR1.tBit.pen_s = PARAMSET_PWMDRV_WGP_HOPP1_PEN_POS_FREQ;
			tCP_FREQ_CR1.tBit.pen_d = PARAMSET_PWMDRV_WGP_HOPP1_PEN_DAT_FREQ;
			tCP_FREQ_CR1.tBit.finger = PARAMSET_PWMDRV_WGP_HOPP1_FINGER_FREQ;
			PWMDRV->FREQ_CR1.ulBulk = tCP_FREQ_CR1.ulBulk;
		}
		else
		{
			PWMDRV->DMY_FREQ = ptHalPwmdrvControlConf->tCP_DMY_FREQ;
			PWMDRV->FREQ_CR1.ulBulk = ptHalPwmdrvControlConf->tCP_FREQ_CR1.ulBulk;
		}
	}
#else
	PWMDRV->DMY_FREQ = ptHalPwmdrvControlConf->tCP_DMY_FREQ;
	PWMDRV->FREQ_CR1.ulBulk = ptHalPwmdrvControlConf->tCP_FREQ_CR1.ulBulk;
#endif
	PWMDRV->FREQ_CR2.ulBulk = ptHalPwmdrvControlConf->tCP_FREQ_CR2.ulBulk;

	PWMDRV_LocalLHBSetting(_eSensingMode);
	PWMDRV->PING_CR.ulBulk = ptHalPwmdrvControlConf->tCP_PING_CR.ulBulk;
	PWMDRV->SYNC_GEN_CR.ulBulk = ptHalPwmdrvControlConf->tCP_SYNC_GEN_CR.ulBulk;
	PWMDRV->TE_RDY_CNT = ptHalPwmdrvControlConf->tCP_TE_RDY_CNT;
	PWMDRV->TE_TCH_V_FPCH = ptHalPwmdrvControlConf->tCP_TE_TCH_V_FPCH;
	PWMDRV->TE_TCH_V_HIGH = ptHalPwmdrvControlConf->tCP_TE_TCH_V_HIGH;
	PWMDRV->TE_TCH_FPCH = ptHalPwmdrvControlConf->tCP_TE_TCH_FPCH;
//	PWMDRV->TE_TCH_T_HIGH = ptHalPwmdrvControlConf->tCP_TE_TCH_T_HIGH;
//	PWMDRV->TE_TCH_D_HIGH = ptHalPwmdrvControlConf->tCP_TE_TCH_D_HIGH;
//	PWMDRV->TE_TCH_LOW = ptHalPwmdrvControlConf->tCP_TE_TCH_LOW;
	PWMDRV->TE_TCH_BPCH = ptHalPwmdrvControlConf->tCP_TE_TCH_BPCH;
	PWMDRV->TE_TCH_PD_LOW = ptHalPwmdrvControlConf->tCP_TE_TCH_PD_LOW;
	PWMDRV->TG_DUM1 = ptHalPwmdrvControlConf->tCP_TG_DUM1;
	PWMDRV->TG_DUM2 = ptHalPwmdrvControlConf->tCP_TG_DUM2;
	PWMDRV->TG_DUM3 = ptHalPwmdrvControlConf->tCP_TG_DUM3;
	PWMDRV->TG_DUM4 = ptHalPwmdrvControlConf->tCP_TG_DUM4;
	PWMDRV->TG_DUM5.ulBulk = ptHalPwmdrvControlConf->tCP_TG_DUM5.ulBulk;
#if USED_MNT_S3_MODE_FUNCTION
	if(IS_S3_MODE(_eSensingMode))
	{
		PWMDRV->TG_DUM5.tBit.tsync_sric_out_bypass_enb = 1; //0:Bypass, 1:Internal Timing
	}
#endif /* USED_MNT_S3_MODE_FUNCTION */

	PWMDRV->DISP_OFF_CR.ulBulk = ptHalPwmdrvControlConf->tCP_DISP_OFF_CR.ulBulk;
#if USED_NOISE_HOPPING_FREQ
	{
		if(IS_ACTIVE_MODE_FRQ_HOP1(_eSensingMode))
		{
			tCP_PWM_CR1_t tCP_PWM_CR1;
			tCP_PWM_CR1.tBit.pen_s_h_pnt = PARAMSET_PWMDRV_WGP_HOPP1_PWM_CR2_pen_s_h_pnt;
			tCP_PWM_CR1.tBit.pen_d_h_pnt = PARAMSET_PWMDRV_WGP_HOPP1_PWM_CR2_pen_d_h_pnt;
			PWMDRV->PWM_CR1.ulBulk = tCP_PWM_CR1.ulBulk;

			tCP_PWM_CR2_t tCP_PWM_CR2;
			tCP_PWM_CR2.tBit.finger_h_pnt = PARAMSET_PWMDRV_WGP_HOPP1_PWM_CR2_finger_h_pnt;
			tCP_PWM_CR2.tBit.dmy_h_pnt = PARAMSET_PWMDRV_WGP_HOPP1_PWM_CR2_dmy_h_pnt;
			PWMDRV->PWM_CR2.ulBulk = tCP_PWM_CR2.ulBulk;
		}
		else
		{
			PWMDRV->PWM_CR1.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_CR1.ulBulk;
			PWMDRV->PWM_CR2.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_CR2.ulBulk;
		}
	}
#else
	PWMDRV->PWM_CR1.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_CR1.ulBulk;
	PWMDRV->PWM_CR2.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_CR2.ulBulk;
#endif
	PWMDRV->VSYNC_CR.ulBulk = ptHalPwmdrvControlConf->tCP_VSYNC_CR.ulBulk;

	if(IS_ACTIVE_MODE(_eSensingMode))
	{
		PWMDRV->MUX_CR.ulBulk = ptHalPwmdrvControlConf->tCP_MUX_CR.ulBulk;
	}
#if USED_LOCAL_IDLE_MODE_CONTROL
	else
	{
		tCP_MUX_CR_t tCP_MUX_CR;
		tCP_MUX_CR.ulBulk = ptHalPwmdrvControlConf->tCP_MUX_CR.ulBulk;
		tCP_MUX_CR.tBit.pen_s = PARAMSET_PWMDRV_WGP_MUX_CR_Idle_pen_s;
		tCP_MUX_CR.tBit.finger = PARAMSET_PWMDRV_WGP_MUX_CR_Idle_finger;
		PWMDRV->MUX_CR.ulBulk = tCP_MUX_CR.ulBulk;
	}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
#if USED_IDLE_MODE_CONTROL
	else
	{
		tCP_MUX_CR_t tCP_MUX_CR;
		tCP_MUX_CR.ulBulk = ptHalPwmdrvControlConf->tCP_MUX_CR.ulBulk;
		tCP_MUX_CR.tBit.finger = PARAMSET_PWMDRV_WGP_MUX_CR_Idle_finger;
		PWMDRV->MUX_CR.ulBulk = tCP_MUX_CR.ulBulk;
	}
#endif /* USED_IDLE_MODE_CONTROL */

	PWMDRV->PWM_TPIC_ST_CR.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_TPIC_ST_CR.ulBulk;
	PWMDRV->PWM_SRIC_ST_CR.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_SRIC_ST_CR.ulBulk;
	PWMDRV->PWM_MUX_ST_CR.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_MUX_ST_CR.ulBulk;
	PWMDRV->NM_FREQ.ulBulk = ptHalPwmdrvControlConf->tCP_NM_FREQ.ulBulk;
	PWMDRV->PWM_DLY2.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_DLY2.ulBulk;
	PWMDRV->DLY_CNT4.ulBulk = ptHalPwmdrvControlConf->tCP_DLY_CNT4.ulBulk;
	PWMDRV->KIOSK_VSYNC_TIMER = ptHalPwmdrvControlConf->tCP_KIOSK_VSYNC_TIMER;
	PWMDRV->PWM_DLY3.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_DLY3.ulBulk;
	PWMDRV->PWM_DLY4.ulBulk = ptHalPwmdrvControlConf->tCP_PWM_DLY4.ulBulk;

	/*
	 * Pen Beacon Setting
	 */
	PWMDRV_Set_DSSS_INFO(PWMDRV->PWMGEN_CR0.tBit.pen_mode);
	PWMDRV_Set_DSSS_CODE(PWM_PEN_COMMON_BEACON);
}

#if  (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL)
tCP_LHB_CONFIG21_t g_tCP_LHB_CONFIG21 =
{
	.tBit.lhb1 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_1,
	.tBit.lhb2 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_2,
	.tBit.lhb3 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_3,
	.tBit.lhb4 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_4,
	.tBit.lhb5 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_5,
	.tBit.lhb6 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_6,
	.tBit.lhb7 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_7,
	.tBit.lhb8 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_8,
	.tBit.lhb9 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_9,
	.tBit.lhb10 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_10,
};
tCP_LHB_CONFIG22_t g_tCP_LHB_CONFIG22 =
{
	.tBit.lhb11 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_11,
	.tBit.lhb12 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_12,
	.tBit.lhb13 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_13,
	.tBit.lhb14 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_14,
	.tBit.lhb15 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_15,
	.tBit.lhb16 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_16,
	.tBit.lhb17 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_17,
	.tBit.lhb18 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_18,
	.tBit.lhb19 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_19,
	.tBit.lhb20 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_20,
};
tCP_LHB_CONFIG23_t g_tCP_LHB_CONFIG23 =
{
	.tBit.lhb21 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_21,
	.tBit.lhb22 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_22,
	.tBit.lhb23 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_23,
	.tBit.lhb24 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_24,
	.tBit.lhb25 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_25,
	.tBit.lhb26 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_26,
	.tBit.lhb27 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_27,
	.tBit.lhb28 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_28,
	.tBit.lhb29 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_29,
	.tBit.lhb30 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_30,
};
tCP_LHB_CONFIG24_t g_tCP_LHB_CONFIG24 =
{
	.tBit.lhb31 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_31,
	.tBit.lhb32 = PARAMSET_PWMDRV_WGP_LOCAL_IDLE_LHB_32,
};
#endif /* (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL) */
#if USED_MNT_S3_MODE_FUNCTION
tCP_LHB_CONFIG11_t g_tCP_S3_LHB_CONFIG11 =
{
	.tBit.lhb1 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb2 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb3 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb4 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb5 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb6 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb7 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb8 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb9 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb10 = PWM_LHB_CONFIG_FINGER,
};
tCP_LHB_CONFIG12_t g_tCP_S3_LHB_CONFIG12 =
{
	.tBit.lhb11 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb12 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb13 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb14 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb15 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb16 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb17 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb18 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb19 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb20 = PWM_LHB_CONFIG_FINGER,
};
tCP_LHB_CONFIG13_t g_tCP_S3_LHB_CONFIG13 =
{
	.tBit.lhb21 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb22 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb23 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb24 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb25 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb26 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb27 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb28 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb29 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb30 = PWM_LHB_CONFIG_FINGER,
};
tCP_LHB_CONFIG14_t g_tCP_S3_LHB_CONFIG14 =
{
	.tBit.lhb31 = PWM_LHB_CONFIG_FINGER,
	.tBit.lhb32 = PWM_LHB_CONFIG_FINGER,
};
#endif /* USED_MNT_S3_MODE_FUNCTION */

void PWMDRV_LocalLHBSetting(eSENSING_MODE_t _eSensingMode)
{
	const tHalPwmdrvControlConf_t * ptHalPwmdrvControlConf = hal_pwmdrv_GetControlConfig();

#if USED_MNT_S3_MODE_FUNCTION
	if(IS_S3_MODE(_eSensingMode))
	{
		PWMDRV->LHB_CONFIG11.ulBulk = g_tCP_S3_LHB_CONFIG11.ulBulk;
		PWMDRV->LHB_CONFIG12.ulBulk = g_tCP_S3_LHB_CONFIG12.ulBulk;
		PWMDRV->LHB_CONFIG13.ulBulk = g_tCP_S3_LHB_CONFIG13.ulBulk;
		PWMDRV->LHB_CONFIG14.ulBulk = g_tCP_S3_LHB_CONFIG14.ulBulk;

		PWMDRV->LHB_CONFIG21.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG21.ulBulk;
		PWMDRV->LHB_CONFIG22.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG22.ulBulk;
		PWMDRV->LHB_CONFIG23.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG23.ulBulk;
		PWMDRV->LHB_CONFIG24.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG24.ulBulk;
	}
	else
#endif /* USED_MNT_S3_MODE_FUNCTION */
	{
	#if USED_IDLE_MODE_CONTROL
		if(IS_ACTIVE_MODE(_eSensingMode))
		{
			PWMDRV->LHB_CONFIG11.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG11.ulBulk;
			PWMDRV->LHB_CONFIG12.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG12.ulBulk;
			PWMDRV->LHB_CONFIG13.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG13.ulBulk;
			PWMDRV->LHB_CONFIG14.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG14.ulBulk;
		}
		else
		{
			PWMDRV->LHB_CONFIG11.ulBulk = g_tCP_LHB_CONFIG21.ulBulk;
			PWMDRV->LHB_CONFIG12.ulBulk = g_tCP_LHB_CONFIG22.ulBulk;
			PWMDRV->LHB_CONFIG13.ulBulk = g_tCP_LHB_CONFIG23.ulBulk;
			PWMDRV->LHB_CONFIG14.ulBulk = g_tCP_LHB_CONFIG24.ulBulk;
		}
	#else /* USED_IDLE_MODE_CONTROL */
		PWMDRV->LHB_CONFIG11.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG11.ulBulk;
		PWMDRV->LHB_CONFIG12.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG12.ulBulk;
		PWMDRV->LHB_CONFIG13.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG13.ulBulk;
		PWMDRV->LHB_CONFIG14.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG14.ulBulk;
	#endif /* USED_IDLE_MODE_CONTROL */

	#if  USED_LOCAL_IDLE_MODE_CONTROL
		if(IS_ACTIVE_MODE(_eSensingMode))
		{
			PWMDRV->LHB_CONFIG21.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG21.ulBulk;
			PWMDRV->LHB_CONFIG22.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG22.ulBulk;
			PWMDRV->LHB_CONFIG23.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG23.ulBulk;
			PWMDRV->LHB_CONFIG24.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG24.ulBulk;
		}
		else
		{
			PWMDRV->LHB_CONFIG21.ulBulk = g_tCP_LHB_CONFIG21.ulBulk;
			PWMDRV->LHB_CONFIG22.ulBulk = g_tCP_LHB_CONFIG22.ulBulk;
			PWMDRV->LHB_CONFIG23.ulBulk = g_tCP_LHB_CONFIG23.ulBulk;
			PWMDRV->LHB_CONFIG24.ulBulk = g_tCP_LHB_CONFIG24.ulBulk;
		}
	#else /* USED_LOCAL_IDLE_MODE_CONTROL */
		PWMDRV->LHB_CONFIG21.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG21.ulBulk;
		PWMDRV->LHB_CONFIG22.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG22.ulBulk;
		PWMDRV->LHB_CONFIG23.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG23.ulBulk;
		PWMDRV->LHB_CONFIG24.ulBulk = ptHalPwmdrvControlConf->tCP_LHB_CONFIG24.ulBulk;
	#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
	}
}

void PWMDRV_GPIO_Init(eSENSING_MODE_t _eSensingMode)
{
	// I/O COnfiguration
#if USED_OPERATION_STAND_ALONE
	GPIO_Init(_GPIO_VSYNC, GPIO_MODE_FUNC_0, GPIO_DIR_OUTPUT, GPIO_DATA_NONE);
	GPIO_Init(GPIO_TSYNC_IN, GPIO_MODE_FUNC_0, GPIO_DIR_OUTPUT, GPIO_DATA_NONE);
#if USED_TSYNC2_INPUT_FROM_TCON
	GPIO_Init(_GPIO_TSYNC_2_IN, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_NONE);
#endif /* USED_TSYNC2_INPUT_FROM_TCON */
#else /* USED_OPERATION_STAND_ALONE */

	if(IS_S3_MODE(_eSensingMode))
	{
		GPIO_Init(_GPIO_VSYNC, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
		GPIO_Init(_GPIO_TSYNC_IN, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
#if USED_TSYNC2_INPUT_FROM_TCON
		GPIO_Init(_GPIO_TSYNC_2_IN, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
#endif /* USED_TSYNC2_INPUT_FROM_TCON */
	}
	else
	{
#if USED_TOUCH_TUNING_PROCESS
		GPIO_Set_Mode(_GPIO_VSYNC, GPIO_MODE_FUNC_0); // Used VSync Interrupt
#else /* USED_TOUCH_TUNING_PROCESS */
		GPIO_Init(_GPIO_VSYNC, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
#endif /* USED_TOUCH_TUNING_PROCESS */
		GPIO_Set_Mode(_GPIO_TSYNC_IN, GPIO_MODE_FUNC_0);
#if USED_TSYNC2_INPUT_FROM_TCON
		GPIO_Init(_GPIO_TSYNC_2_IN, GPIO_MODE_FUNC_3, GPIO_DIR_INPUT, GPIO_DATA_NONE);
#endif /* USED_TSYNC2_INPUT_FROM_TCON */
	}
#endif /* USED_OPERATION_STAND_ALONE */

	GPIO_Set_Mode(_GPIO_PWM_SRIC, GPIO_MODE_FUNC_0); // PWM_TX
	GPIO_Set_Mode(_GPIO_PWM_TPIC, GPIO_MODE_FUNC_0); // PWM_DATA (PWM_LFD)
#if USED_PWM_GATE_CONTROL
	GPIO_Set_Mode(_GPIO_PWM_GATE, GPIO_MODE_FUNC_1); // PWM_DATA (PWM_LFD)
#endif /* USED_PWM_GATE_CONTROL */

	GPIO_Set_DS(_GPIO_PWM_SRIC, GPIO_DRIVE_STR_20mA);
	GPIO_Set_DS(_GPIO_PWM_TPIC, GPIO_DRIVE_STR_20mA);
#if USED_PWM_GATE_CONTROL
	GPIO_Set_DS(_GPIO_PWM_GATE, GPIO_DRIVE_STR_20mA);
#endif /* USED_PWM_GATE_CONTROL */

	GPIO_Set_Mode(_GPIO_TSYNC_OUT, GPIO_MODE_FUNC_0); // TSYNCN_OUT
	GPIO_Set_DS(_GPIO_TSYNC_OUT, GPIO_DRIVE_STR_20mA);

#if (USED_MODULE_DEF == MODULE_DEF_B_1)
#if USED_REVISION_PINMAP
#if (USED_REVISION_PINMAP_2)
	GPIO_Set_Mode(_GPIO_TSYNC_TMIC, GPIO_MODE_FUNC_0);
	GPIO_Set_DS(_GPIO_TSYNC_TMIC, GPIO_DRIVE_STR_20mA);
#endif /* (USED_REVISION_PINMAP_2 */
#else  /* USED_REVISION_PINMAP */
#if USED_TSYNC_TMIC_GPIO_CONTROL
	GPIO_Init(_GPIO_TSYNC_TMIC, GPIO_MODE_FUNC_3, GPIO_DIR_OUTPUT, GPIO_DATA_HIGH);
#else  /* USED_TSYNC_TMIC_GPIO_CONTROL */
	GPIO_Set_Mode(_GPIO_TSYNC_TMIC, GPIO_MODE_FUNC_0);
	GPIO_Set_DS(_GPIO_TSYNC_TMIC, GPIO_DRIVE_STR_20mA);
#endif /* USED_TSYNC_TMIC_GPIO_CONTROL */
#endif /* USED_REVISION_PINMAP */
#elif (USED_MODULE_DEF == MODULE_DEF_S_1)
#if (USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S01)
	GPIO_Set_Mode(_GPIO_TSYNC_TMIC, GPIO_MODE_FUNC_0);
	GPIO_Set_DS(_GPIO_TSYNC_TMIC, GPIO_DRIVE_STR_20mA);
#endif /* (USED_PCB_PINMAP == SHARP_NBPC_PIN_TYPE_S01) */
#endif /* (USED_MODULE_DEF == MODULE_DEF_B_1) */
}

void PWMDRV_Cmd(FunctionalState _NewState)
{
	PWMDRV->PWMGEN_CR0.tBit.pwm_gen_enable = _NewState;
//	if(_NewState == ENABLE)
//	{
//		SCRB->SYS_RST_CTL.tBit.pwm_rst = 0;
//	}
//	else
//	{
//		SCRB->SYS_RST_CTL.tBit.pwm_rst = 1;
//	}
	PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = _NewState;

//	PWMDRV->PWMGEN_CR0.tBit.pwm_gen_enable = _NewState;
//	if(_NewState == DISABLE)
//	{
//		PWMDRV->SYNC_GEN_CR.tBit.sync_gen_en = DISABLE;
//	}
}

void PWMDRV_ITConfig(tPWM_INTR_CFG_t * pIntrCfg, uint32_t ulNum)
{
	uint32_t ulIdx;

	for(ulIdx = 0; ulIdx < ulNum; ulIdx++)
	{
		NVIC_ClearPendingIRQ(pIntrCfg[ulIdx].PWM_IRQ_TYPE);
		NVIC_SetPriority(pIntrCfg[ulIdx].PWM_IRQ_TYPE, pIntrCfg[ulIdx].ulIRQ_Priority);
		if(pIntrCfg[ulIdx].newState != DISABLE)
		{
			NVIC_EnableIRQ(pIntrCfg[ulIdx].PWM_IRQ_TYPE);
		}
		else
		{
			NVIC_DisableIRQ(pIntrCfg[ulIdx].PWM_IRQ_TYPE);
		}
	}
}

void PWMDRV_Set_DSSS_INFO(uint32_t ulIdx)
{
	const tHalPwmdrvControlConf_t * ptHalPwmdrvControlConf = hal_pwmdrv_GetControlConfig();
	PWMDRV->DSSS_INFO1.ulBulk = ptHalPwmdrvControlConf->tCP_DSSS_INFO1[ulIdx].ulBulk;
	PWMDRV->DSSS_INFO2.ulBulk = ptHalPwmdrvControlConf->tCP_DSSS_INFO2[ulIdx].ulBulk;
}

void PWMDRV_Set_DSSS_CODE(uint32_t ulIdx)
{
	const tHalPwmdrvControlConf_t * ptHalPwmdrvControlConf = hal_pwmdrv_GetControlConfig();
	tCP_DSSS_CODE_Value_t * pCP_DSSS_CODE_Value = (tCP_DSSS_CODE_Value_t *)&ptHalPwmdrvControlConf->tCP_DSSS_CODE_Value[ulIdx];

	PWMDRV->DSSS_CODE_P_0 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_P_0;
	PWMDRV->DSSS_CODE_P_1 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_P_1;
	PWMDRV->DSSS_CODE_0_0 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_0_0;
	PWMDRV->DSSS_CODE_0_1 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_0_1;
	PWMDRV->DSSS_CODE_1_0 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_1_0;
	PWMDRV->DSSS_CODE_1_1 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_1_1;
	PWMDRV->DSSS_CODE_2_0 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_2_0;
	PWMDRV->DSSS_CODE_2_1 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_2_1;
	PWMDRV->DSSS_CODE_3_0 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_3_0;
	PWMDRV->DSSS_CODE_3_1 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_3_1;
	PWMDRV->DSSS_CODE_4_0 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_4_0;
	PWMDRV->DSSS_CODE_4_1 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_4_1;
	PWMDRV->DSSS_CODE_5_0 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_5_0;
	PWMDRV->DSSS_CODE_5_1 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_5_1;
	PWMDRV->DSSS_CODE_6_0 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_6_0;
	PWMDRV->DSSS_CODE_6_1 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_6_1;
	PWMDRV->DSSS_CODE_7_0 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_7_0;
	PWMDRV->DSSS_CODE_7_1 = pCP_DSSS_CODE_Value->tCP_DSSS_CODE_7_1;
}

//void PWMDRV_SectionEnable(eSENSING_MODE_t mode)
//{
//}
//
//void PWMDRV_Set_Pulse_Config(eSENSING_MODE_t eSensingMode)
//{
//}
//
//void PWMDRV_Set_Mode(eSENSING_MODE_t _mode)
//{
//}
