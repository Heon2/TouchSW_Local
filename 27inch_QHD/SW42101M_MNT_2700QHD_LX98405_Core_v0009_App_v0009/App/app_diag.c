/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : app_diag.c
 * created on : 03. 01. 2018
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

#include "core_def.h"
#include "param_def.h"
#include "crc.h"
#include "sric.h"
#include "pwmdrv.h"
#include "gpio.h"
#include "Mspi.h"
#if defined(USE_BOOTLOADER_8KB)
	volatile unsigned long BaseAddr = 0x00002000UL;
#elif defined(USE_BOOTLOADER_16KB)
	volatile unsigned long BaseAddr = 0x00004000UL;
#else
	volatile unsigned long BaseAddr = 0x00000000UL;
#endif

unsigned char* fullBuffer;
static tAlgorithmInfo_t * sptAlgorithmInfo  = NULL;
__IO uint32_t fw_crc_value;
#if !defined(FINGER_ONLY)
extern uint16_t sensingRowStart;
#endif /* !defined(FINGER_ONLY) */
void SRIC_Stop(void);
void app_diag_Init(void)
{
	sptAlgorithmInfo = algorithm_GetInfo();		
}

#ifdef DEBUG
void
__error__(char *pcFilename, unsigned long ulLine)
{
}
#endif

static void app_diag_CMuxOFF_Control(bool_t bIsEn)
{
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);

	MSPI_Set_TLPMODE();
	SW92400_Set_CMUXOFF(bIsEn);
	MSPI_Set_AITMODE(HAL_GetSensingMode());

	MSPI->SPISTART = 0x3F;
}

static void app_diag_EvenOdd_SHORT_Control(uint8_t index)
{
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);

	SRIC_Stop();
	MSPI_Set_TLPMODE();

	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x0);
	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x1);

//	SRIC_Init(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);

	// Even Short...
	LX98405_EvenOdd_Short_Setting(index);  // Even Short...

	LX98405_Short_Local_Global_Tune();

	SRIC_Run();

	MSPI_Set_AITMODE(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
	MSPI->SPISTART = 0x3F;

	module_wait_full_sample_done();

}

static void app_diag_OPENSHORT_Control(uint8_t index)
{
#if (CUSTOMER == MODEL_LGD_SW92400)
	uint16_t regbuf[5] = { 0x35E1, 0x35D1, 0x35C9, 0x35C5, 0x35C3 };

	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
	SRIC_Stop();
	MSPI_Set_TLPMODE();
	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x0);
	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x1);
	SRIC_Init(HAL_GetSensingMode());
	SRIC_Run();
	
	if(index == 0)
	{
		SRIC_Set_OS(regbuf[0], 0x0010);
	}
	else if(index == 1)
	{
		SRIC_Set_OS(regbuf[1], 0x0010);
	}
	else if(index == 2)
	{
		SRIC_Set_OS(regbuf[2], 0x0010);
	}
	else if(index == 3)
	{
		SRIC_Set_OS(regbuf[3], 0x0010);
	}
	else if(index == 4)
	{
		SRIC_Set_OS(regbuf[4], 0x0010);
	}
	MSPI_Set_AITMODE(HAL_GetSensingMode());


	MSPI->SPISTART = 0x3F;

	module_wait_full_sample_done();
#elif (CUSTOMER == MODEL_LGD_LX98405)
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);

	SRIC_Stop();
	MSPI_Set_TLPMODE();

	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x0);
	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x1);

//	SRIC_Init(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);

	LX98405_OpenShort_SourceGnd_Setting();

	LX98405_OpenShort_Local_Global_Tune();

	if (index == 0)
		LX98405_OpenShort_Mux_Low_En(1);
	else if (index == 1)
		LX98405_OpenShort_Mux_Low_En(2);
	else if (index == 2)
		LX98405_OpenShort_Mux_Low_En(4);
	else if (index == 3)
		LX98405_OpenShort_Mux_Low_En(8);
	else if (index == 4)
		LX98405_OpenShort_Mux_Low_En(16);

	SRIC_Run();

	MSPI_Set_AITMODE(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
	MSPI->SPISTART = 0x3F;

	module_wait_full_sample_done();

#else /* if(CUSTOMER == MODEL_LGD_SW97400B) */
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);
	
	SRIC_Stop();
	MSPI_Set_TLPMODE();
	
	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x0);
	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x1);
	
	SRIC_Init(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
	SRIC_Run();

	SRIC_Set_OS(0x1E7F, 0x008F);
	
	MSPI_Set_AITMODE(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
	MSPI->SPISTART = 0x3F;

	module_wait_full_sample_done();
#endif /* (CUSTOMER == MODEL_LGD_SW92400) */
}

static void app_diag_LX98405_Reg_Restore_Setting(uint8_t index)
{
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 1);
	while(GPIO->tGPIO_DATA_0._GPIO_VSYNC == 0);

	SRIC_Stop();
	MSPI_Set_TLPMODE();

	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x0);
	while(GPIO->tGPIO_DATA_0._GPIO_TSYNC_IN == 0x1);

	LX98405_Reg_Restore_Setting(index);

	SRIC_Run();

	MSPI_Set_AITMODE(SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE);
	MSPI->SPISTART = 0x3F;
}

uint8_t DiffCnt;
__IO uint32_t ulFrame1Count;
__IO uint32_t ulFrame2Count;
__IO uint32_t ulFrameOSCount;
eTouchOperMainState_t app_diag_oper_handler(void)
{
	eTouchOperMainState_t main_state;
	eDiagOperSubState_t sub_state;
	bool_t bLoop = YES;
	int i, FrameCnt;
	uint8_t r, c;
	int deltaData;

    int k, j;
    int tcnt = 1;

	app_diag_Init();
	
	sub_state = TOUCH_DIAG_OPER_ENTER;
	sptAlgorithmInfo->bDiagMode = YES;
 
    while(bLoop)
    {
    	switch(sub_state)
    	{
			case TOUCH_DIAG_OPER_ENTER:
			{
				sub_state = TOUCH_DIAG_OPER_WAIT;
				break;
			}
			case TOUCH_DIAG_OPER_WAIT:
			{
				protocol_swip_PendReadyStatus();
				sub_state = TOUCH_DIAG_OPER_NORMAL;
				break;
			}
			case TOUCH_DIAG_OPER_NORMAL:
			{
				const tModuleCommonConf_t * lptModuleCommonConf = module_GetCommonConfig();
				const tAlgorithmModeConf_t * lptAlgorithmConf = algorithm_GetModeConfig();

				switch(protocol_swip_GetTestType())
				{
					case CTT_ABS:	// = MNT RAWDATA
					{
						for(r = 0; r < lptModuleCommonConf->ucScreenRow_; r++)
						{
							for(c = 0; c < lptModuleCommonConf->ucScreenCol_; c++)
							{
								HAL_WRITE_ABS_IMAGE(r, c, 0);
							}
						}

						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}

						// ABS
//						ulFrame1Count = protocol_swip_GetABSCount();
//						if(ulFrame1Count == 0)
						{
							ulFrame1Count = 10;     // Default value
						}

						for(i=0; i<ulFrame1Count; i++)
						{
							module_wait_full_sample_done();

							for(r = lptModuleCommonConf->ucScreenRow_; r--; )
							{
								for(c = lptModuleCommonConf->ucScreenCol_; c--; )
								{
									HAL_WRITE_ABS_IMAGE(r, c, QUOT(HAL_READ_RAW_IMAGE(r,c), ulFrame1Count) + HAL_READ_ABS_IMAGE(r,c));
								}
							}
						}

						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = lptModuleCommonConf->ucScreenCol_,
							.ucRow_ = lptModuleCommonConf->ucScreenRow_,
							.ucBufferCol_ = COL_MAX,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint16_t)
						};

						protocol_swip_PendTestResult(tTestDataFmt, (const void *)HAL_GET_ABS_IMAGE_PTR());
						break;
					}
#if !defined(FINGER_ONLY)
					case CTT_DC_ABS:
					{
						protocol_LogCode(LT_DIAGNOSIS, (22)/*System is Entered!*/);

						for( r=0; r<lptModuleCommonConf->ucScreenRow_; r++ )
						{
							for( c=0; c<lptModuleCommonConf->ucScreenCol_; c++ )
							{
								HAL_WRITE_DC_ABS_IMAGE(r, c, 0);
							}
						}

						// DC ABS
						int re = 8;
						ePartialSensing_t RetVal = PARTIAL_PEN_BEACON;
						sensingRowStart = 0;
						setSensingMode(SET_SM_FINGERPEN_MODE);

						module_wait_Vsync_signal(LOCAL_MODE, lptAlgorithmConf->BaseLine.ucDiscardFrameNum);

						while(YES)
						{
							RetVal = module_wait_local_sample_done();
							if(RetVal == PARTIAL_FINGER4)
								break;
						}

						ulFrame1Count = protocol_swip_GetDCABSCount();
						if(ulFrame1Count == 0)
						{
							ulFrame1Count = 10;     // Default value
						}

						for(i=0; i<ulFrame1Count;)
						{
							RetVal = module_wait_local_sample_done();
							switch( RetVal )
							{
								case PARTIAL_PEN_COORD1:
								case PARTIAL_PEN_COORD2:
								case PARTIAL_PEN_COORD3:
								case PARTIAL_PEN_COORD4:
								{
									for( r=re; r--; )
									{
										for( c=lptModuleCommonConf->ucScreenCol_; c--; )
										{
											HAL_WRITE_DC_ABS_IMAGE(r+sensingRowStart, c, QUOT(HAL_READ_LOCAL_RAW_IMAGE(r,c), DiffCnt) + HAL_READ_DC_ABS_IMAGE(r+sensingRowStart,c));
										}
									}
									i++;

									if(i == ulFrame1Count)
									{
										sensingRowStart += 8;
										if(sensingRowStart == 48)
										{
											sensingRowStart = 0;
										}
										else
										{
											i = 0;
											if(sensingRowStart == 40)
											{
												re = 5;
											}
										}
									}
								}
								break;

								default:
									break;
							}
						}
						setSensingMode(SET_SM_FINGER_MODE);

						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = lptModuleCommonConf->ucScreenCol_,
							.ucRow_ = lptModuleCommonConf->ucScreenRow_,
							.ucBufferCol_ = COL_MAX,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint16_t)
						};

						protocol_swip_PendTestResult( tTestDataFmt, (const void *)HAL_GET_DC_ABS_IMAGE_PTR());
						break;
					}
#endif /* !defined(FINGER_ONLY) */

					case CTT_JITTER:
					{
						
						uint8_t err_flag = 0;
						for(r=0; r<lptModuleCommonConf->ucScreenRow_; r++)
						{
							for(c=0; c<lptModuleCommonConf->ucScreenCol_; c++)
							{
								HAL_WRITE_ABS_IMAGE(r, c, 0);
								HAL_WRITE_JITTER_IMAGE(r, c, 0);
							}
						}

						for(i=0; i<lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
#if LGD_ERROR_FRAME_PROCESS_EN
							if(LGD_error_frame_process())
							{
								for(i=0; i<15/*lptAlgorithmConf->BaseLine.ucDiscardFrameNum*/; i++)
								{
									module_wait_full_sample_done();
								}	
							}
#endif
						}

						// Jitter
						ulFrame1Count = protocol_swip_GetJitterAVGCount();
						if(ulFrame1Count == 0)
						{
							ulFrame1Count = 60;     // Default value
						}
						
						for(FrameCnt = 0; FrameCnt < ulFrame1Count;)
						{
							module_wait_full_sample_done();
#if LGD_ERROR_FRAME_PROCESS_EN
							if(LGD_error_frame_process() == NO)
#else
							if (1)//(LGD_error_frame_process() == NO)
#endif
							{		
								FrameCnt++;
								if(FrameCnt == 1)
								{
									for(r = lptModuleCommonConf->ucScreenRow_; r--; )
									{
										for(c = lptModuleCommonConf->ucScreenCol_; c--; )
										{
											HAL_WRITE_ABS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
										}
									}
								}
								else
								{
									for(r = lptModuleCommonConf->ucScreenRow_; r--; )
									{
										for(c = lptModuleCommonConf->ucScreenCol_; c--; )
										{
											HAL_WRITE_ABS_IMAGE(r, c, (HAL_READ_RAW_IMAGE(r, c) + HAL_READ_ABS_IMAGE(r, c))/2);
										}
									}
								}
							}
						}

						ulFrame2Count = protocol_swip_GetJitterMAXCount();
						
//						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
//						{
//							.bIsRotated = NO,
//							.ucCol_ = lptModuleCommonConf->ucScreenCol_,
//							.ucRow_ = lptModuleCommonConf->ucScreenRow_,
//							.ucBufferCol_ = COL_MAX,
//							.ucKey_ = 0,
//							.tDataType = datatypeof(int16_t)
//						};
//						protocol_swip_PendTestResult( tTestDataFmt, (const void *)HAL_GET_ABS_IMAGE_PTR());
						if(ulFrame2Count == 0)
						{
							ulFrame2Count = 200;     // Default value
						}

						for(FrameCnt = 0; FrameCnt < ulFrame2Count; i++)
						{
							module_wait_full_sample_done();
#if LGD_ERROR_FRAME_PROCESS_EN
							if(LGD_error_frame_process() == NO)
#else
							if (1)//(LGD_error_frame_process() == NO)
#endif
							{
								FrameCnt++;
								for(r=lptModuleCommonConf->ucScreenRow_; r--; )
								{
									for(c=lptModuleCommonConf->ucScreenCol_; c--; )
									{
										deltaData = HAL_READ_RAW_IMAGE(r, c) - HAL_READ_ABS_IMAGE(r, c);
										if(deltaData < 0) deltaData = -deltaData;
		
										if(deltaData > (int)HAL_READ_JITTER_IMAGE(r, c))
										{
											HAL_WRITE_JITTER_IMAGE(r, c, deltaData);
										}
									}
								}
							}	
						}

						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = lptModuleCommonConf->ucScreenCol_,
							.ucRow_ = lptModuleCommonConf->ucScreenRow_,
							.ucBufferCol_ = COL_MAX,
							.ucKey_ = 0,
							.tDataType = datatypeof(int16_t)
						};

//						[ROW_MAX + 2*PAD_][COL_MAX + 2*PAD_];
//						memset((void *)HAL_GET_JITTER_IMAGE_PTR(), 0x00, sizeof(uint16_t)*((ROW_MAX)*(COL_MAX)));

						protocol_swip_PendTestResult( tTestDataFmt, (const void *)HAL_GET_JITTER_IMAGE_PTR());
						break;
					}

					case CTT_CRC_CHECK:
					{
						fullBuffer = (unsigned char *)BaseAddr;
	#if defined(USE_BOOTLOADER_16KB)
						fw_crc_value = Crc16WordCalc((const uint16_t*)&fullBuffer[0], FW_CRC_SIZE / 2, 0) | (Crc16WordCalc((const uint16_t*)&fullBuffer[2], FW_CRC_SIZE / 2, 0) << 16);
	#else
						fw_crc_value = Crc16WordCalc((const uint16_t*)&fullBuffer[0], FW_SIZE / 2 - 4, 0) | (Crc16WordCalc((const uint16_t*)&fullBuffer[2], FW_SIZE / 2 - 4, 0) << 16);
	#endif
						fw_crc_value = fw_crc_value ^ 0xFFFFFFFF;
						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = 1,
							.ucRow_ = 1,
							.ucBufferCol_ = 1,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint32_t)
						};
						protocol_swip_PendTestResult( tTestDataFmt, (const void *)((uint32_t *)&fw_crc_value));
						free((void *)fullBuffer);
						break;
					}

					case CTT_EVENODD_SHORT:
					{

						for(r = 0; r < lptModuleCommonConf->ucScreenRow_; r++)
						{
							for(c = 0; c < lptModuleCommonConf->ucScreenCol_; c++)
							{
								HAL_WRITE_OS_IMAGE(r, c, 0);
							}
						}

						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}

#if (CUSTOMER == MODEL_LGD_SW92400)
						for(i=0; i < 5; i++)
						{
							app_diag_OPENSHORT_Control(i);

							module_wait_full_sample_done();

							for(r = lptModuleCommonConf->ucScreenRow_; r--; )
							{
								if(r%5 == i)
								{
									for(c = lptModuleCommonConf->ucScreenCol_; c--; )
									{
										HAL_WRITE_OS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
									}
								}
							}
						}
#elif (CUSTOMER == MODEL_LGD_LX98405)

						// Even Short...
						app_diag_EvenOdd_SHORT_Control(0);

						module_wait_full_sample_done();

						for (r = lptModuleCommonConf->ucScreenRow_; r--; )
						{
							if ( (r%5 == 0) || (r%5 == 2) || (r%5 == 3) )
							{
								for(c = lptModuleCommonConf->ucScreenCol_; c--; )
								{
									if (c%2 == 1)
										HAL_WRITE_OS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
								}
							}
							else if ( (r%5 == 1) || (r%5 == 4) )
							{
								for(c = lptModuleCommonConf->ucScreenCol_; c--; )
								{
									if (c%2 == 0)
										HAL_WRITE_OS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
								}
							}
						}

						// Odd Short...
						app_diag_EvenOdd_SHORT_Control(1);

						module_wait_full_sample_done();

						for (r = lptModuleCommonConf->ucScreenRow_; r--; )
						{
							if ( (r%5 == 0) || (r%5 == 2) || (r%5 == 3) )
							{
								for(c = lptModuleCommonConf->ucScreenCol_; c--; )
								{
									if (c%2 == 0)
										HAL_WRITE_OS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
								}
							}
							else if ( (r%5 == 1) || (r%5 == 4) )
							{
								for(c = lptModuleCommonConf->ucScreenCol_; c--; )
								{
									if (c%2 == 1)
										HAL_WRITE_OS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
								}
							}

						}


//						app_diag_LX98405_Reg_Restore_Setting();
						
#else /* if(CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */
						app_diag_OPENSHORT_Control(0);

						module_wait_full_sample_done();

						for(r = lptModuleCommonConf->ucScreenRow_; r--; )
						{
							for(c = lptModuleCommonConf->ucScreenCol_; c--; )
							{
								HAL_WRITE_OS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
							}
						}
#endif /* (CUSTOMER == MODEL_LGD_SW92400) */

						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = lptModuleCommonConf->ucScreenCol_,
							.ucRow_ = lptModuleCommonConf->ucScreenRow_,
							.ucBufferCol_ = COL_MAX,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint16_t)
						};

						protocol_swip_PendTestResult(tTestDataFmt, (const void *)HAL_GET_OS_IMAGE_PTR());

						app_diag_LX98405_Reg_Restore_Setting(1);

						break;
					}

					case CTT_OPEN_SHORT:
					{

						for(r = 0; r < lptModuleCommonConf->ucScreenRow_; r++)
						{
							for(c = 0; c < lptModuleCommonConf->ucScreenCol_; c++)
							{
								HAL_WRITE_OS_IMAGE(r, c, 0);
							}
						}

						for(i = 0; i < lptAlgorithmConf->BaseLine.ucDiscardFrameNum; i++)
						{
							module_wait_full_sample_done();
						}

						for (i=0; i<5; i++)
						{
							app_diag_OPENSHORT_Control(i);

							module_wait_full_sample_done();

							for (r = lptModuleCommonConf->ucScreenRow_; r--; )
							{
								if (i == 0)
								{
									if (r%5 == 2)
									{
										for(c = lptModuleCommonConf->ucScreenCol_; c--; )
										{
											HAL_WRITE_OS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
										}
									}
								}
								else if (i == 1)
								{
									if (r%5 == 1)
									{
										for(c = lptModuleCommonConf->ucScreenCol_; c--; )
										{
											HAL_WRITE_OS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
										}
									}
								}
								else if (i == 2)
								{
									if (r%5 == 0)
									{
										for(c = lptModuleCommonConf->ucScreenCol_; c--; )
										{
											HAL_WRITE_OS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
										}
									}
								}
								else if (i == 3)
								{
									if (r%5 == 4)
									{
										for(c = lptModuleCommonConf->ucScreenCol_; c--; )
										{
											HAL_WRITE_OS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
										}
									}
								}
								else if (i == 4)
								{
									if (r%5 == 3)
									{
										for(c = lptModuleCommonConf->ucScreenCol_; c--; )
										{
											HAL_WRITE_OS_IMAGE(r, c, HAL_READ_RAW_IMAGE(r, c));
										}
									}
								}

							}

						}

						const tSWIPTestDataFmt_t * tTestDataFmt = &(tSWIPTestDataFmt_t)
						{
							.bIsRotated = NO,
							.ucCol_ = lptModuleCommonConf->ucScreenCol_,
							.ucRow_ = lptModuleCommonConf->ucScreenRow_,
							.ucBufferCol_ = COL_MAX,
							.ucKey_ = 0,
							.tDataType = datatypeof(uint16_t)
						};

						protocol_swip_PendTestResult(tTestDataFmt, (const void *)HAL_GET_OS_IMAGE_PTR());

						app_diag_LX98405_Reg_Restore_Setting(2);

						break;
					}
				} /* switch(protocol_swip_GetTestType()) */

				module_Stop();
//				test_state = CTT_NONE; // NOTE : not used!!

				break;
			}

			case TOUCH_DIAG_OPER_EXIT:
			{
				protocol_swip_PendReadyStatus();

				bLoop = NO;
				continue;
				/* no break */
			}
    	}

    	switch( protocol_swip_GetMode() )
    	{
			case M_TOUCH_NORMAL:
			{
				sub_state = TOUCH_DIAG_OPER_EXIT;
				main_state = TOUCH_MAIN_OPERATION_NORMAL;
				break;
			}
    	}
    }

    return main_state; // NOTE : �ʱⰪ�� ������.. swip Mode�� M_TOUCH_NORMAL�� �ƴ� ���� ������ Check�ʿ�!!
}
