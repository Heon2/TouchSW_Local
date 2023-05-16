/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : i2c.c
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
 * I2C Register
 */
tI2C_CtrlReg_t*							g_I2C = I2C;

/*
 * Power On State! Data processing is possible.
 */
#ifdef MODE_I2C
uint8_t									g_Ready = I2C_READY;
#endif/* MODE_I2C */


LX_GETFEATURE_DATA 						g_FeatureData = { 0, 0x00 };
uint8_t 								g_FeatureDataLength = 0;

/*
 * After initilization, it is delay a few milli seconds before sending data.
 */
#ifdef MODE_I2C
#define DEF_I2C_DELAY_CHECK_CNT_THD		(50) // about 70msec (Timer Tick Count)
typedef struct
{
	bool_t bIsDelayStart;
	bool_t bIsDelayStopCheckCountEnable;
	uint16_t usDelayStopCheckCount;
} tI2CDelayCheckInfo_t;
tI2CDelayCheckInfo_t					g_tDelayCheckInfo = {NO, NO, 0};
#endif/* MODE_I2C */

/*
 * Reset
 */
#ifdef MODE_I2C
uint8_t									g_bReset = I2C_NORMAL;
uint8_t 								g_nResetTxCount = 0;
#endif/* MODE_I2C */

/*
 * Read Data From Master (Host)
 */
uint8_t									g_RxCommand[100] = { 0, };
uint32_t								g_RxCommandIndex = 0;

/*
 * Write Data to Master (Host)
 */
#ifdef MODE_I2C
uint8_t*								g_TxPtr = NULL;
uint32_t								g_TxIndex = 0;
#endif/* MODE_I2C */

#ifdef MODE_I2C

/*
 * I2C HID Descriptor
 */
I2C_HID_DESCRIPTOR						g_I2CHidDescriptor = { 0, };

SETREPORT_DEVICE_MODE					g_DeviceMode_I2C = { 0, };
SETREPORT_LATENCY_MODE					g_LatencyMode_I2C = { 0, }; // LATENCY_MODE__NORMAL, LATENCY_MODE__HIGH

/*
 * Multi-Touch
 */
uint8_t									g_HID_ReportDesc_Temp[HID_MULTITOUCH_DESC_TOTAL_LENGTH + HID_PEN_DESC_LENGTH + HID_CUSTOM_DESC_LENGTH] = { 0, };

#ifdef ADD_TOUCH
/*
 * Report Descriptor
 */
extern uint8_t							u8_HID_MultiTouch_Descriptor_Head[HID_MULTITOUCH_DESC_HEAD_LENGTH];
extern uint8_t							u8_HID_MultiTouch_Descriptor_Main[HID_MULTITOUCH_DESC_MAIN_LENGTH];
extern uint8_t							u8_HID_MultiTouch_Descriptor_Tail[HID_MULTITOUCH_DESC_TAIL_LENGTH];
extern uint8_t							u8_HID_Touch_Blob[HID_TOUCH_BLOB_LENGTH];

/*
 * Touch Max Count
 */
TOUCH_MAX_COUNT							g_MaxTouchCount_I2C = { 0, };

/*
 * Idle
 */
TOUCH_IDLE                              g_TouchIdle_I2C = { 0, };
#endif

/*
 * Custom
 */
#ifdef ADD_CUSTOM
/*
 * Report Descriptor
 */
extern uint8_t							u8_HID_Custom_Descriptor[HID_CUSTOM_DESC_LENGTH];

#endif


/*
 * Pen
 */
#ifdef ADD_PEN
/*
 * Report Descriptor
 */
extern uint8_t							u8_HID_Pen_Descriptor[HID_PEN_DESC_LENGTH];
#endif

#endif // MODE_I2C


/*
 *  Common (Touch + Pen + Custom)
 */

/*
 * Queue
 */
#ifdef MODE_I2C
extern STATIC_QUEUE						g_Queue_Common;
HID_COMMON_I2C							g_Common_I2C = { 0, };
#endif /* MODE_I2C */

/*
 * Touch, Custom, Pen
 */
#ifdef MODE_I2C
uint8_t*								g_TxPtr_Common = NULL;
uint32_t								g_TxIndex_Common = 0;
uint32_t 								g_TxSendCount = 0;
uint32_t 								g_TxByteInterruptCount = 0;
uint8_t									g_CheckComplete_Common_I2C = DMA_READY;
#endif /* MODE_I2C */


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifdef MODE_I2C
void I2C_TxData(uint8_t* pData, uint16_t Length)
{
	uint16_t i = 0;

	for (i = 0; i < Length; i++)
	{
		I2C->I2C_TXFIFO_DATA = pData[i];
	}

	return;
}

void Make_EmptyI2CData(void)
{
	// Clear Tx
	I2C->I2C_FIFO_CR.ulBulk |= 0x01;

	// It is ready 2byte as reponse Resect CMD from Host.
	// It seems like to read 36Byte from Host.
	I2C->I2C_TXFIFO_DATA = 0x00;
	I2C->I2C_TXFIFO_DATA = 0x00;

	// GPIO Interrupt Enable
	GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_LOW);
	return;
}

static void Init_HidDescriptor(void)
{
	g_I2CHidDescriptor.BCDVersion = 0x0100; // 1.0 in MS document!!

#ifdef ADD_TOUCH
	g_I2CHidDescriptor.ReportLength = HID_MULTITOUCH_DESC_TOTAL_LENGTH;
#endif

#ifdef ADD_PEN
	g_I2CHidDescriptor.ReportLength += HID_PEN_DESC_LENGTH;
#endif

#ifdef ADD_CUSTOM
	g_I2CHidDescriptor.ReportLength += HID_CUSTOM_DESC_LENGTH;
#endif

	g_I2CHidDescriptor.ReportRegister = I2C_REPORT_REGISTER;
	g_I2CHidDescriptor.InputRegister = I2C_INPUT_REGISTER;
	g_I2CHidDescriptor.MaxInputLength = I2C_MAX_INPUT_LENGTH;
	g_I2CHidDescriptor.OutputRegister = I2C_OUTPUT_REGISTER;
	g_I2CHidDescriptor.MaxOutputLength = I2C_MAX_OUTPUT_LENGTH;
	g_I2CHidDescriptor.CommandRegister = I2C_COMMAND_REGISTER;
	g_I2CHidDescriptor.DataRegister = I2C_DATA_REGISTER;
	g_I2CHidDescriptor.VendorID = I2C_VENDORID;
	g_I2CHidDescriptor.ProductID = I2C_PRODUCTID;
	g_I2CHidDescriptor.VersionID = I2C_VERSION;
	g_I2CHidDescriptor.Reserved = 0x00000000;

	return;
}


static void Init_HidReportDescriptor(void)
{
#ifdef ADD_TOUCH
	uint8_t		i = 0;
#endif
	uint16_t	Offset = 0;

#ifdef ADD_TOUCH
	// Head
	memcpy(&g_HID_ReportDesc_Temp[Offset], u8_HID_MultiTouch_Descriptor_Head, HID_MULTITOUCH_DESC_HEAD_LENGTH);
	Offset += HID_MULTITOUCH_DESC_HEAD_LENGTH;

	// Main
	for (i = 0; i < HID_MAX_TOUCH; i++)
	{
		memcpy(&g_HID_ReportDesc_Temp[Offset], u8_HID_MultiTouch_Descriptor_Main, HID_MULTITOUCH_DESC_MAIN_LENGTH);
		Offset += HID_MULTITOUCH_DESC_MAIN_LENGTH;
	}

	// Tail
	memcpy(&g_HID_ReportDesc_Temp[Offset], u8_HID_MultiTouch_Descriptor_Tail, HID_MULTITOUCH_DESC_TAIL_LENGTH);
	Offset += HID_MULTITOUCH_DESC_TAIL_LENGTH;
#endif

#ifdef ADD_PEN
	memcpy(&g_HID_ReportDesc_Temp[Offset], u8_HID_Pen_Descriptor, HID_PEN_DESC_LENGTH);
	Offset += HID_PEN_DESC_LENGTH;

#endif


#ifdef ADD_CUSTOM
	memcpy(&g_HID_ReportDesc_Temp[Offset], u8_HID_Custom_Descriptor, HID_CUSTOM_DESC_LENGTH);
	Offset += HID_CUSTOM_DESC_LENGTH;
#endif


	return;
}







//
// Touch
//

#ifdef ADD_TOUCH
uint8_t SendTouchData_I2C(PHID_MULTITOUCH_I2C pUserData)
{
	uint8_t bPush = FALSE;

	if(g_tDelayCheckInfo.bIsDelayStart == NO)
	{
		if(StaticQueue_CheckFull(&g_Queue_Common) == 1)
		{
			StaticQueue_HeadDelete(&g_Queue_Common);
		}

		StaticQueue_Push(&g_Queue_Common, (uint8_t*)pUserData);
		bPush = TRUE;
	}

	return bPush;
}

#endif

#endif // MODE_I2C







//
// Custom
//

#ifdef MODE_I2C
//__IO uint8_t custom_tool;
HJ_HID_CONTROL_STRUCT_I2C g_CustomBuffer_I2C = { 0, };

void SendCustomData_I2C(PHJ_HID_CONTROL_STRUCT_I2C pUserData)
{
	if (StaticQueue_CheckInit(&g_Queue_Common) == 0)
	{
		// Init Queue
		StaticQueue_Init(&g_Queue_Common);
	}

	if (StaticQueue_CheckFull(&g_Queue_Common) == 1)
	{
		StaticQueue_HeadDelete(&g_Queue_Common);
	}

	pUserData->I2C_Length = sizeof(HJ_HID_CONTROL_STRUCT_I2C);
	StaticQueue_Push(&g_Queue_Common, (uint8_t*)pUserData);
}

void RecieveCustomData_I2C(PHJ_HID_CONTROL_STRUCT_I2C pData)
{
	switch (pData->Data.PacketID)
	{
		case HID_REPORT_ID__CUSTOM_OUT:
		{
			if (pData->Data.DeviceID_b.bRead)
			{
				HidReadWrite__Read_I2C(pData);
			}
			else
			{
				HidReadWrite__Write(&pData->Data);
			}

			break;
		}
	}

	return;
}
#endif /* MODE_I2C */


uint16_t swap_uint16(uint16_t val)
{
	return (val << 8) | (val >> 8);
}


#ifdef MODE_I2C
void GetCustomData_I2C(uint8_t* pData)
{
	memcpy(&g_CustomBuffer_I2C.Data, pData, I2C_DATA_LENGTH);
	return;
}

//
// Pen
//

#ifdef ADD_PEN
void SendPenData_I2C(PHID_PEN_I2C pUserData)
{
	if(g_tDelayCheckInfo.bIsDelayStart == NO)
	{
		if (StaticQueue_CheckFull(&g_Queue_Common) == 1)
		{
			StaticQueue_HeadDelete(&g_Queue_Common);
		}

		pUserData->I2C_Length = sizeof(HID_PEN_I2C);
		StaticQueue_Push(&g_Queue_Common, (uint8_t*)pUserData);
	}

	return;
}
#endif
#endif







//
// Common I2C (Touch + Pen + Custom)
//

#ifdef MODE_I2C

uint8_t g_bCallReadyStatus = FALSE;

// 2021.12.06
uint8_t CallReadyStatus_ToHost(void)
{
	HID_MULTITOUCH_I2C 	DummyData = { 0, };
	uint8_t*			pFlag = NULL;
	uint8_t* 			pFeatureBit = NULL;
	uint8_t 			bRet = FALSE;

	DummyData.I2C_Length = sizeof(HID_MULTITOUCH_I2C);
	DummyData.Data.ReportID = HID_REPORT_ID__MULTI_TOUCH;
	DummyData.Data.ContactCount = 0;
	pFlag = (uint8_t*)&DummyData.Data.ScanTime;
	pFlag[0] = 'L';
	pFlag[1] = 'X';

	pFeatureBit = (uint8_t*)&DummyData.Data.Touch[0];
	*pFeatureBit |= FEATURELIST__COMMAND_FEATURE;
	*pFeatureBit |= FEATURELIST__READYSTATUS_INTERRUPT;
	*pFeatureBit |= FEATURELIST__RESERVED_1;
	*pFeatureBit |= FEATURELIST__RESERVED_2;
	*pFeatureBit |= FEATURELIST__RESERVED_3;
	*pFeatureBit |= FEATURELIST__RESERVED_4;
	*pFeatureBit |= FEATURELIST__RESERVED_5;
	*pFeatureBit |= FEATURELIST__RESERVED_6;

	bRet = SendTouchData_I2C(&DummyData);
	return bRet;
}


void QueueCommonData_I2C(void)
{
	if(g_tDelayCheckInfo.bIsDelayStopCheckCountEnable == YES)
	{
		if(g_tDelayCheckInfo.usDelayStopCheckCount > DEF_I2C_DELAY_CHECK_CNT_THD)
		{
			g_tDelayCheckInfo.bIsDelayStart = NO;
			g_tDelayCheckInfo.bIsDelayStopCheckCountEnable = NO;
		}
		else
		{
			g_tDelayCheckInfo.usDelayStopCheckCount++;
		}
	}
	else
	{
		g_tDelayCheckInfo.usDelayStopCheckCount = 0;
	}

	if (g_bCallReadyStatus == TRUE)
	{
		if (CallReadyStatus_ToHost() == TRUE)
		{
			g_bCallReadyStatus = FALSE;
		}
	}

	do
	{
		if (g_CheckComplete_Common_I2C != DMA_READY)
		{
			break;
		}

		if (g_Ready != I2C_READY)
		{
			break;
		}

		if (g_bReset != I2C_NORMAL)
		{
			break;
		}

		if (g_TxPtr != NULL)
		{
			break;
		}

		if (g_RxCommandIndex > 0)
		{
			break;
		}

		if (StaticQueue_CheckEmpty(&g_Queue_Common) != 0)
		{
			break;
		}

		// Pop
		if (StaticQueue_Pop(&g_Queue_Common, (uint8_t*)&g_Common_I2C) == TRUE)
		{
			uint16_t* pLength = (uint16_t*)&g_Common_I2C;

			// Tx Count
			g_TxSendCount = pLength[0];

			// Flag
			g_CheckComplete_Common_I2C = DMA_NOT_READY;

			// Pointer
			g_TxPtr_Common = (uint8_t*)&g_Common_I2C;
			g_TxIndex_Common = 0;

			// Clear Tx
			I2C->I2C_FIFO_CR.ulBulk |= 0x01;

			// 2 Byte - Length
			I2C->I2C_TXFIFO_DATA = g_TxPtr_Common[g_TxIndex_Common];
			g_TxIndex_Common += 1;

			I2C->I2C_TXFIFO_DATA = g_TxPtr_Common[g_TxIndex_Common];
			g_TxIndex_Common += 1;

			g_TxByteInterruptCount = 0;

			// GPIO Interrupt Enable
			GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_LOW);
		}

	} while (FALSE);

	return;
}
#endif





//
// I2C - ISR
//

#if USED_I2C_READ_DATA_UNIT_2BYTE
extern bool_t bIsTempSend;
#endif /* USED_I2C_READ_DATA_UNIT_2BYTE */

void I2C_InterruptHandler(void)
{
	do
	{
		// Interrupt Clear
		I2C->I2C_GLB_SR.tBit.I2C_ITRPT = 0;

#ifdef MODE_I2C
		// Reset !!!
		if (g_bReset == I2C_RESET)
		{
			g_nResetTxCount += 1;
			I2C->I2C_TXFIFO_DATA  = 0;

			if (g_nResetTxCount >= 2)
			{
				g_bReset = I2C_NORMAL;
				
				// Check GPIO Interrupt
				if (IS_GPIO_PIN(_GPIO_TP_INTR) == GPIO_DATA_LOW)
				{
					// Disable GPIO Interrupt
					GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_HIGH);
				}
			}

			break;
		}
#endif // MODE_I2C

		//
		// Host --> Device
		//
		if (I2C->I2C_GLB_SR.tBit.I2cSlvRdWrFlag == 0)
		{
			uint8_t 	ReadData = 0;
			uint8_t 	bCompleted = FALSE;
#ifdef MODE_I2C
			uint16_t*	pCheckRegister = NULL;
#endif

			if (I2C->I2C_FIFO_SR2.tBit.RxFifoEmpty != 0)
			{
				break;
			}

			if (g_RxCommandIndex == 0)
			{
				Protocol_hid_Init();
			}

			ReadData = (uint8_t)(I2C->I2C_RXFIFO_DATA & 0xFF);
			if (g_RxCommandIndex < 100)
			{
				g_RxCommand[g_RxCommandIndex] = ReadData;
				g_RxCommandIndex += 1;
			}
			

			if (g_RxCommandIndex < 2)
			{
				break;
			}

#ifdef MODE_I2C
			g_TxByteInterruptCount = 0;
			///////////////// 2021.08.06 josh3 //////////////////
			////
			////    To block Touch or Pen data while device process Protocol data.
//			g_StartTime_I2C = 0;
//			g_DelayTime = 0;
			g_tDelayCheckInfo.bIsDelayStart = YES;
			g_tDelayCheckInfo.usDelayStopCheckCount = 0;

			// Cancel touch or pen data transmission. (for SUD with ISP board)
			if (IS_GPIO_PIN(_GPIO_TP_INTR) == GPIO_DATA_LOW)
			{
				// Disable GPIO Interrupt
				GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_HIGH);

				// Init value
				g_TxSendCount = 0;
				g_CheckComplete_Common_I2C = DMA_READY;
				g_TxPtr_Common = NULL;
				g_TxIndex_Common = 0;

				// Clear Tx
				I2C->I2C_FIFO_CR.ulBulk |= 0x01;

				// Clear Queue
				StaticQueue_Init(&g_Queue_Common);
			}
			////
			////
			/////////////////////////////////////////////////////
				
			pCheckRegister = (uint16_t*)g_RxCommand;
			switch(pCheckRegister[0])
			{
				// I2C HID Descriptor
				case HID_DESCRIPTOR_ADDRESS:
				{
					uint16_t	Length = 0;

					// Clear Tx
					I2C->I2C_FIFO_CR.ulBulk |= 0x01;

					// I2C HID Descriptor
					Length = sizeof(I2C_HID_DESCRIPTOR) + 2;
					g_TxSendCount = Length;

					I2C->I2C_TXFIFO_DATA = (uint8_t)(Length & 0x00FF);
					I2C->I2C_TXFIFO_DATA = (uint8_t)(Length >> 8);

					g_TxPtr = (uint8_t*)&g_I2CHidDescriptor;
					g_TxIndex = 0;

					bCompleted = TRUE;
					break;
				}
				case I2C_REPORT_REGISTER:
				{
					// Clear Tx
					I2C->I2C_FIFO_CR.ulBulk |= 0x01;

					// HID Report Descriptor
					g_TxPtr = (uint8_t*)g_HID_ReportDesc_Temp;
					g_TxSendCount = g_I2CHidDescriptor.ReportLength;
					
					// Length
					g_TxIndex = 0;
					I2C->I2C_TXFIFO_DATA = g_TxPtr[g_TxIndex];
					g_TxIndex += 1;
					I2C->I2C_TXFIFO_DATA = g_TxPtr[g_TxIndex];
					g_TxIndex += 1;

					bCompleted = TRUE;
					break;
				}

				case I2C_COMMAND_REGISTER:
				{
					PI2C__REQUEST pRequest = (PI2C__REQUEST)g_RxCommand;

					if (pRequest->OpCode == I2C__REQUEST_OPCODE__SET_REPORT)
					{
						// 2021.12.04 josh3
						// ex: 0x0150( 22 00 32 03 23 00 07 00 02 0E 00 01 50 )
						if (pRequest->I2C_Request_Common.ReportID == HID_REPORT_ID__FEATURE_4)
						{
							PI2C__REQUEST_LXS pRequestLxs = (PI2C__REQUEST_LXS)g_RxCommand;

							if (g_RxCommandIndex < 13)
							{
								break;
							}

							if (pRequestLxs->ProtocolDataLength > 0)
							{
								g_CustomBuffer_I2C.I2C_Length = 0x42;
								g_CustomBuffer_I2C.Data.PacketID = 0x09;
								g_CustomBuffer_I2C.Data.DeviceID_b.bRead = FALSE;
								g_CustomBuffer_I2C.Data.DeviceID_b.addr = 0x34;
								g_CustomBuffer_I2C.Data.Length = 2;
								g_CustomBuffer_I2C.Data.Data[0] = pRequestLxs->Data[0];
								g_CustomBuffer_I2C.Data.Data[1] = pRequestLxs->Data[1];

								// Length - For next read command
								g_FeatureDataLength = pRequestLxs->ProtocolDataLength;

								RecieveCustomData_I2C(&g_CustomBuffer_I2C);
							}
							else
							{
								// Just check !!!
								// ( 22 00 32 03 23 00 07 00 02 00 00 07 98 )
								g_FeatureDataLength = 0;
							}

							bCompleted = TRUE;
							break;
						}
					}
					else if (pRequest->OpCode == I2C__REQUEST_OPCODE__GET_REPORT)
					{
						switch(pRequest->I2C_Request_Common.ReportID)
						{
							// ( 22 00 34 02 23 00 )
							case HID_REPORT_ID__FEATURE_2:
							case HID_REPORT_ID__FEATURE_4:
							case HID_REPORT_ID__FEATURE_6:
							case HID_REPORT_ID__FEATURE_20:
							case HID_REPORT_ID__FEATURE_60:
							{
								uint16_t	Length = 0;
								uint16_t	index = 0;
								uint8_t		nData = 0;

								if (g_RxCommandIndex < 6)
								{
									break;
								}

								g_FeatureData.ReportID = pRequest->I2C_Request_Common.ReportID;
								memset(g_FeatureData.Data, 0, 60);


								if (g_FeatureDataLength == 0)
								{
									// Just check !!!
									g_FeatureData.Data[0] = 0x98;
									g_FeatureData.Data[1] = 0x07;
									g_FeatureDataLength = 2;
								}
								else
								{
									for (index = 0; index < g_FeatureDataLength; index++)
									{
										if (Protocol_hid_FromDeviceToHost(&nData, FALSE) == TRUE)
										{
											g_FeatureData.Data[index] = nData;
										}
									}
								}

								// Clear Tx
								I2C->I2C_FIFO_CR.ulBulk |= 0x01;

								// Size
								Length = g_FeatureDataLength + 3; // (ReportID + Length)
								g_TxSendCount = Length;

								I2C->I2C_TXFIFO_DATA = (uint8_t)(Length & 0x00FF);
								I2C->I2C_TXFIFO_DATA = (uint8_t)(Length >> 8);

								// ex : 0x0150 ( 11 00 04 53 57 49 50 00 00 00 00 10 01 BD 29 01 32 .... )
								g_TxPtr = (uint8_t*)&g_FeatureData;
								g_TxIndex = 0;

								bCompleted = TRUE;
								break;
							}

							// Report ID : 8 - Get MaxTouch Count (22 00 38 02 23 00)
							case HID_REPORT_ID__CONTACT_COUNT:
							{
								uint16_t	Length = 0;

								if (g_RxCommandIndex < 6)
								{
									break;
								}
					
								// Clear Tx
								I2C->I2C_FIFO_CR.ulBulk |= 0x01;

								// Size
								Length = sizeof(TOUCH_MAX_COUNT) + 2;
								g_TxSendCount = Length;

								I2C->I2C_TXFIFO_DATA = (uint8_t)(Length & 0x00FF);
								I2C->I2C_TXFIFO_DATA = (uint8_t)(Length >> 8);

								g_TxPtr = (uint8_t*)&g_MaxTouchCount_I2C;
								g_TxIndex = 0;

								g_MaxTouchCount_I2C.ReportID = HID_REPORT_ID__CONTACT_COUNT;
								g_MaxTouchCount_I2C.Count = HID_MAX_TOUCH;

								bCompleted = TRUE;
								break;
							}

							// Report ID : 6 - Get BlobCode (22 00 36 02 23 00)
							case HID_REPORT_ID__BLOB_CODE:
							{
								uint16_t	Length = 0;

								if (g_RxCommandIndex < 6)
								{
									break;
								}
					
								// Clear Tx
								I2C->I2C_FIFO_CR.ulBulk |= 0x01;

								// Size
								Length = HID_TOUCH_BLOB_LENGTH + 2;
								g_TxSendCount = Length;

								I2C->I2C_TXFIFO_DATA = (uint8_t)(Length & 0x00FF);
								I2C->I2C_TXFIFO_DATA = (uint8_t)(Length >> 8);

								g_TxPtr = (uint8_t*)u8_HID_Touch_Blob;
								g_TxIndex = 0;

								bCompleted = TRUE;
								break;
							}
						}
					}
					//  Get Idle (22 00 10 04)
					else if (pRequest->OpCode == I2C__REQUEST_OPCODE__GET_IDLE)
					{
						uint16_t	Length = 0;

						if (g_RxCommandIndex < 4)
						{
							break;
						}
					
						// Clear Tx
						I2C->I2C_FIFO_CR.ulBulk |= 0x01;

						//  Size
						Length = sizeof(TOUCH_IDLE) + 2;
						g_TxSendCount = Length;

						I2C->I2C_TXFIFO_DATA = (uint8_t)(Length & 0x00FF);
						I2C->I2C_TXFIFO_DATA = (uint8_t)(Length >> 8);

						g_TxPtr = (uint8_t*)&g_TouchIdle_I2C;
						g_TxIndex = 0;

						bCompleted = TRUE;
					}
					else if (pRequest->OpCode == I2C__REQUEST_OPCODE__SET_POWER)
					{
						if (g_RxCommandIndex < 4)
						{
							break;
						}

						// Set Power (22 00 00 08)
						if (pRequest->I2C_Request_Power.PowerState == I2C__REQUEST_REPORT_POWER_STATE__ON)
						{
							g_Ready = I2C_READY;
							bCompleted = TRUE;
						}
						// Sleep (22 00 01 08)
						else if (pRequest->I2C_Request_Power.PowerState == I2C__REQUEST_REPORT_POWER_STATE__SLEEP)
						{
							g_Ready = I2C_NOT_READY;
							bCompleted = TRUE;
						}
					}
					// Reset (22 00 00 01)
					else if (pRequest->OpCode == I2C__REQUEST_OPCODE__RESET)
					{
						if (g_RxCommandIndex < 4)
						{
							break;
						}

						g_bReset = I2C_RESET;
						g_nResetTxCount = 0;

						// Clear Tx
						I2C->I2C_FIFO_CR.ulBulk |= 0x01;

						// GPIO Interrupt Enable
						GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_LOW);

						bCompleted = TRUE;
					}

					break;
				}
				
				case I2C_OUTPUT_REGISTER:
				{
					PI2C__OUTPUT pOutputData = (PI2C__OUTPUT)g_RxCommand;

					if (pOutputData->ReportID == HID_REPORT_ID__CUSTOM_OUT)
					{
						// sizeof OUTPUT Data - 68 Bytes
						if (g_RxCommandIndex != 68)
						{
							break;
						}

						// 0x0150
						if ((pOutputData->Data[0] == 0x69) && (pOutputData->Data[3] == 0x01) && (pOutputData->Data[4] == 0x50))
						{
							g_bCallReadyStatus = TRUE;
						}

						GetCustomData_I2C(&pOutputData->ReportID);
						RecieveCustomData_I2C(&g_CustomBuffer_I2C);

						// Init Command 처리 없이 Custom OUT 데이터가 먼저 들어올 수 있다.
						// 이 경우에는 여기서 Ready 를 체크 해줘야 한다.
						g_Ready = I2C_READY;

						bCompleted = TRUE;
					}

					break;
				}

				// SUD - Host to Device
				default:
				{
					if (g_RxCommandIndex == 2)
					{
						uint16_t usRegAddr = 0;
						uint8_t nData = 0;
						uint8_t b2Byte = FALSE;

#if USED_I2C_READ_DATA_UNIT_2BYTE
						bIsTempSend = NO;
						b2Byte = TRUE;
#endif /* USED_I2C_READ_DATA_UNIT_2BYTE */

						// Clear
						I2C->I2C_FIFO_CR.ulBulk |= 0x01;	

						// Addr
						usRegAddr = g_RxCommand[0] << 8;
						usRegAddr |= g_RxCommand[1];

						// 0x0150
						if ((g_RxCommand[0] == 0x01) && (g_RxCommand[1] == 0x50))
						{
							g_bCallReadyStatus = TRUE;
						}

						Protocol_hid__SetAddress(usRegAddr);
						if (Protocol_hid_FromDeviceToHost(&nData, b2Byte) == TRUE)
						{
							I2C->I2C_TXFIFO_DATA = nData;
						}
					}
					else if (g_RxCommandIndex > 2)
					{
						// Data
						Protocol_hid__FromHostToDevice(g_RxCommand[g_RxCommandIndex-1]);
					}
					break;
				}
			}
#else // MODE_I2C
			if (g_RxCommandIndex == 2)
			{
				uint16_t usRegAddr = 0;
				uint8_t nData = 0;
				uint8_t b2Byte = FALSE;

	#if USED_I2C_READ_DATA_UNIT_2BYTE
				bIsTempSend = NO;
				b2Byte = TRUE;
	#endif /* USED_I2C_READ_DATA_UNIT_2BYTE */

				// Clear
				I2C->I2C_FIFO_CR.ulBulk |= 0x01;	

				// Addr
				usRegAddr = g_RxCommand[0] << 8;
				usRegAddr |= g_RxCommand[1];

				Protocol_hid__SetAddress(usRegAddr);
				if (Protocol_hid_FromDeviceToHost(&nData, b2Byte) == TRUE)
				{
					I2C->I2C_TXFIFO_DATA = nData;
				}
			}
			else if (g_RxCommandIndex > 2)
			{
				// Data
				Protocol_hid__FromHostToDevice(g_RxCommand[g_RxCommandIndex-1]);
			}
#endif // MODE_I2C

			if (bCompleted == TRUE)
			{
				memset(g_RxCommand, 0, 100);
				g_RxCommandIndex = 0;
			}
		}
		//
		// Device --> Host
		//
		else if (I2C->I2C_GLB_SR.tBit.I2cSlvRdWrFlag == 1)
		{
#ifdef MODE_I2C
			if (I2C->I2C_GLB_SR.tBit.I2cItrptState == I2C_BYTE_ITRPT)
			{
				g_TxByteInterruptCount += 1;
			}
			// HID over I2C - Command
			if (g_TxPtr != NULL)
			{
				I2C->I2C_TXFIFO_DATA = g_TxPtr[g_TxIndex];
				g_TxIndex += 1;

				if (g_TxByteInterruptCount == g_TxSendCount)
				{
					g_TxPtr = NULL;
					g_TxIndex = 0;

					memset(g_RxCommand, 0, 100);
					g_RxCommandIndex = 0;

					g_TxByteInterruptCount = 0;
				}
			}
			// HID over I2C - Touch, Pen, Custom
			else if (g_TxPtr_Common != NULL)
			{
				if (g_TxIndex_Common < g_TxSendCount)
				{
					I2C->I2C_TXFIFO_DATA = g_TxPtr_Common[g_TxIndex_Common];
					g_TxIndex_Common += 1;
				}

				if (g_TxByteInterruptCount == g_TxSendCount)
				{
					g_CheckComplete_Common_I2C = DMA_READY;
					g_TxPtr_Common = NULL;
					g_TxIndex_Common = 0;
					g_TxSendCount = 0;
					g_TxByteInterruptCount = 0;

					// Check GPIO Interrupt
					if (IS_GPIO_PIN(_GPIO_TP_INTR) == GPIO_DATA_LOW)
					{
						// Disable GPIO Interrupt
						GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_HIGH);
					}
				}
			}
			// SUD
			else
#endif /* MODE_I2C */
			{
				uint8_t nData = 0;
				uint8_t b2Byte = FALSE;

				if (I2C->I2C_GLB_SR.tBit.I2cItrptState == I2C_STP_ITRPT)
				{
					break;
				}

#if USED_I2C_READ_DATA_UNIT_2BYTE
				b2Byte = TRUE;
#endif /* USED_I2C_READ_DATA_UNIT_2BYTE */

				if (Protocol_hid_FromDeviceToHost(&nData, b2Byte) == TRUE)
				{
					I2C->I2C_TXFIFO_DATA = nData;
				}
			}
		}

	} while (FALSE);

	if (I2C->I2C_GLB_SR.tBit.I2cItrptState == I2C_STP_ITRPT)
	{
#ifdef MODE_I2C
		if (g_TxPtr != NULL)
		{
			g_TxPtr = NULL;
			g_TxIndex = 0;
		}
#endif // MODE_I2C

		if (g_RxCommandIndex > 0)
		{		
			memset(g_RxCommand, 0, 100);
			g_RxCommandIndex = 0;
		}
#ifdef MODE_I2C
		g_tDelayCheckInfo.bIsDelayStopCheckCountEnable = YES;
#endif
	}

	return;
}


void I2C_Initialize(void)
{
	Fncp_I2C_SLV_IRQHandler = &I2C_InterruptHandler;

	GPIO_Set_Mode(_GPIO_SLV_SCL, GPIO_MODE_FUNC_0);
	GPIO_Set_Mode(_GPIO_SLV_SDA, GPIO_MODE_FUNC_0);

#ifdef MODE_I2C
	// I2C SLAVE Setting
	Init_HidDescriptor();
	Init_HidReportDescriptor();
#endif

	// I2C SLAVE Setting
	NVIC_SetPendingIRQ(I2C_SLV_IRQn);    /* Interrupt Enable */
	NVIC_EnableIRQ(I2C_SLV_IRQn);    /* Interrupt Enable */
	NVIC_SetPriority(I2C_SLV_IRQn, I2C_SLV_IRQn_Priority);

	I2C->I2C_DEVICE_ADDR.tBit.I2cId = I2C_ADDRESS;
	I2C->I2C_SW_RESET.tBit.I2cSWReset = 1;
	I2C->I2C_DEVICE_ADDR.tBit.I2cId	= I2C_ADDRESS;
	I2C->I2C_GLB_CR.ulBulk = 0x000007FF;

	// FIFO
	I2C->I2C_FIFO_CR.tBit.TxFifoInit = 1;
	I2C->I2C_FIFO_CR.tBit.RxFifoInit = 1;
}

void I2C_DeInitialize(void)
{
	GPIO_Set_Mode(_GPIO_SLV_SCL, GPIO_MODE_FUNC_0);
	GPIO_Set_Mode(_GPIO_SLV_SDA, GPIO_MODE_FUNC_0);

	tSYS_CLK_CTL _SYS_CLK_CTL;
	Fncp_I2C_SLV_IRQHandler = NULL;

	// I2C SLAVE Setting
	NVIC_SetPendingIRQ(I2C_SLV_IRQn);    /* Interrupt Enable */
	NVIC_DisableIRQ(I2C_SLV_IRQn);    /* Interrupt Disable */
	_SYS_CLK_CTL.ulBulk = SCRB->SYS_CLK_CTL.ulBulk;
	_SYS_CLK_CTL.tBit.i2cm0clk_en = YES;
	_SYS_CLK_CTL.tBit.i2cm0clk_slp_en = YES;
	_SYS_CLK_CTL.tBit.i2cm1clk_en = YES;
	_SYS_CLK_CTL.tBit.i2cm1clk_slp_en = YES;
	SCRB->SYS_CLK_CTL.ulBulk = _SYS_CLK_CTL.ulBulk;
}

