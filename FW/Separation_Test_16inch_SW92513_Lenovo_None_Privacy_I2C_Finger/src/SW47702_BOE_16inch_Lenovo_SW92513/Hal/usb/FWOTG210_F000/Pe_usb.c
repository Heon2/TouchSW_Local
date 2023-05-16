/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : Pe_usb.c
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

#include "hal_def.h"
#include "protocol_def.h"
#include "module_def.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
// USB
//

// Check
uint8_t										g_Configuration = 0;
uint8_t										g_HIDReady = 0;


#ifndef MODE_I2C
SETUP_GET_STATUS							g_Status[8 + 1] = { 0, };
CXF_STATUS									g_CXF_Done = CXF_STATUS__NORMAL;

// Descriptor
extern uint8_t								u8_FS_DeviceDesc[DEVICE_DESC_LENGTH];
extern uint8_t								u8_FS_ConfigDesc[CONFIG_DESC_LENGTH];
extern uint8_t								u8O_StrDesc_Product[STRING_PRODUCT_LENGTH];
extern uint8_t								u8O_StrDesc_Manufacturer[STRING_MANUFACTURER_LENGTH];
extern uint8_t								u8O_StrDesc_LangIDs[STRING_LANG_IDS_LENGTH];

#ifdef USB_SELECTIVE_SUSPEND
extern BOS_DESCRIPTOR						BOS_Descriptor;
extern MS_OS_STRING_DESCRIPTOR				MS_OS_Descriptor;
extern COMPATIBLE_ID_FEATURE_DESCRIPTOR		MS_OS_CompatibleID;
extern PROPERTIES_DESCRIPTOR				MS_OS_Property;
#endif


// Backup SetupPacket 8 Bytes
uint32_t										g_EP0_Packet[2] = { 0, };
PSETUP_PACKET								g_pSetupPacket = (PSETUP_PACKET)g_EP0_Packet;

// Idle
uint8_t										g_IdleDuration[0xFF] = { 0, };

// Remote Wakeup
uint8_t										g_RemoteWakeup = 0;
uint8_t										g_SuspendOn = 0;

// EP
uint8_t*										g_EP0_BufferAddr = 0;
uint8_t*										g_EP0_BufferAddr_Free = 0;
uint16_t										g_EP0_BufferLength = 0;
uint32_t										g_EP0_Offset = 0;
uint32_t										g_EP0_Remain = 0;
uint8_t										g_EP0_Check = 0;

// Interrupt
uint32_t										g_IntGroup = 0;
uint32_t										g_IntControl = 0;
uint32_t										g_IntVDMA = 0;
uint32_t										g_IntEP0 = 0;
uint32_t										g_IntEP = 0;


// HID Descriptor
SETUP_HID_DESCRIPTOR						g_HID_Descriptor = { 0, };
#endif

//
// Multi-Touch
//

SETREPORT_DEVICE_MODE						g_DeviceMode = { 0, };
SETREPORT_LATENCY_MODE						g_LatencyMode = { 0, }; // Normal 0, High 1
TOUCH_MAX_COUNT								g_MaxTouchCount = { 0, };

// Check
uint8_t										g_CheckVDMAComplete_Touch = DMA_READY;
uint8_t										g_Touch[QUEUE_BLOCK_SIZE] = { 0, };

#ifdef ADD_TOUCH

#ifndef MODE_I2C
// Report Descriptor
extern uint8_t u8_HID_MultiTouch_Descriptor_Head[HID_MULTITOUCH_DESC_HEAD_LENGTH];
extern uint8_t u8_HID_MultiTouch_Descriptor_Main[HID_MULTITOUCH_DESC_MAIN_LENGTH];
extern uint8_t u8_HID_MultiTouch_Descriptor_Tail[HID_MULTITOUCH_DESC_TAIL_LENGTH];
extern uint8_t u8_HID_Touch_Blob[HID_TOUCH_BLOB_LENGTH];
uint8_t u8_HID_MultiTouchReportDesc_Temp[HID_MULTITOUCH_DESC_TOTAL_LENGTH];
#endif

uint32_t 			g_ScanTime = 0;
uint64_t			g_StartTime = 0;
uint8_t			g_TouchTip[HID_MAX_TOUCH+1] = { 0, }; // (Index + 1), Index value is ID and Real value is Tip

// only use recovery (Remotewakeup)
uint32_t 			g_ScanTime_Recovery = 0;
uint64_t			g_StartTime_Recovery = 0;
uint8_t 			ResumeCnt = 0;
uint32_t 			g_ScanTime_Recovery_ClearSus = 0;
uint64_t			g_StartTime_Recovery_ClearSus = 0;
bool_t Recovery_ClearSus_Flag = 0;
#endif








//
// Custom
//

// Buffer
uint8_t	g_CustomBuffer[CUSTOM_IN_EP_SIZE];
uint8_t	g_CheckVDMAComplete_Custom = DMA_READY;

#ifndef MODE_I2C
#ifdef ADD_CUSTOM
// Report Descriptor
extern uint8_t u8_HID_Custom_Descriptor[HID_CUSTOM_DESC_LENGTH];
#endif
#endif





//
// Pen
//

uint8_t			g_CheckVDMAComplete_Pen = DMA_READY;

#ifdef ADD_PEN
// Report Descriptor
extern uint8_t u8_HID_Pen_Descriptor[HID_PEN_DESC_LENGTH];

#ifdef HID_PEN_SCAN_TIME
uint32_t 			g_ScanTime_Pen = 0;
uint64_t			g_StartTime_Pen = 0;

uint32_t 			g_ScanTime_Pen_Multi[2] = { 0, };
uint64_t			g_StartTime_Pen_Multi[2] = { 0, };
#endif

uint8_t			g_PenTip = 0;
uint8_t			g_PenTip_Multi[2] =  { 0, };
uint8_t 			g_Pen[QUEUE_BLOCK_SIZE] = { 0, };
#endif








//
// Bulk Custom
//

// Buffer
uint8_t	g_BulkCustomBuffer[QUEUE_BLOCK_SIZE];
uint8_t	g_CheckVDMAComplete_BulkCustom = DMA_READY;





//
// Tool
//

//extern __IO uint8_t custom_tool;

int HID_id[HID_MAX_TOUCH] = {0,};
int HID_x[HID_MAX_TOUCH] = {0,};
int HID_y[HID_MAX_TOUCH] = {0,};
int HID_status[HID_MAX_TOUCH] = {0,};

int HID_PEN_X = 0;
int HID_PEN_Y = 0;
int HID_PEN_STATUS =0;

//int HID_TILT_X = 0;
//int HID_TILT_Y = 0;
//int HID_TWIST = 0;
//int HID_AZIMUTH = 0;
//int HID_ALTITUDE = 0;

uint8_t	g_PenEventNum = 0;





//
// Static Queue
//


// Queue
STATIC_QUEUE	g_Queue_Common = { 0, };





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Checking the USB device is ready to be used.
uint8_t CheckUsbConfig(void)
{
	return g_Configuration;
}

// Touch Contact Count
uint8_t CheckHIDReady(void)
{
	return g_HIDReady;
}

void ResumeSigal(void)
{
	mUsbRemoteWakeUpSet_1();
}









//
// Static Queue
//


uint8_t StaticQueue_Init(PSTATIC_QUEUE pQueue)
{
	uint8_t nRet = 0;

	if (pQueue == NULL)
	{
		goto STATICQUEUE_INIT__GOTO_END;
	}

	//InitializeCriticalSection(&g_cs);
	memcpy(pQueue->Signature, (uint8_t*)QUEUE_SIGNATURE, 4);
	memset(pQueue->Buffer, 0, QUEUE_BLOCK_SIZE * QUEUE_MAX_COUNT__COMMON);
	pQueue->PushPoint = 0;
	pQueue->PopPoint = 0;
	pQueue->Count = 0;

	nRet = 1;

STATICQUEUE_INIT__GOTO_END:

	return nRet;
}


uint8_t StaticQueue_CheckInit(PSTATIC_QUEUE pQueue)
{
	uint8_t	nRet = 1;
	uint8_t*	pCompare = (uint8_t*)QUEUE_SIGNATURE;
	uint8_t	i = 0;

	if (pQueue == NULL)
	{
		goto  STATICQUEUE_CHECKINIT__GOTO_END;
	}

	for (i = 0; i < 4; i++)
	{
		if (pQueue->Signature[i] != pCompare[i])
		{
			nRet = 0;
			break;
		}
	}

STATICQUEUE_CHECKINIT__GOTO_END:

	return nRet;
}

uint8_t StaticQueue_Push(PSTATIC_QUEUE pQueue, uint8_t* pData)
{
	uint8_t nRet = 0;

	if ((pQueue == NULL) || (pData == NULL))
	{
		goto STATICQUEUE_PUSH__GOTO_END;
	}

	// Full
	if (pQueue->Count >= QUEUE_MAX_COUNT__COMMON)
	{
		goto STATICQUEUE_PUSH__GOTO_END;
	}

    pQueue->Doing = TRUE;
    
	memcpy(&pQueue->Buffer[pQueue->PushPoint * QUEUE_BLOCK_SIZE], pData, QUEUE_BLOCK_SIZE);
	pQueue->Count += 1;
	pQueue->PushPoint += 1;
	if (pQueue->PushPoint >= QUEUE_MAX_COUNT__COMMON)
	{
		pQueue->PushPoint = 0;
	}

	nRet = 1;
    pQueue->Doing = FALSE;

STATICQUEUE_PUSH__GOTO_END:

	return nRet;
}


uint8_t StaticQueue_Pop(PSTATIC_QUEUE pQueue, uint8_t* pData)
{
	uint8_t nRet = FALSE;

	if ((pQueue == NULL) || (pData == NULL))
	{
		goto STATICQUEUE_POP__GOTO_END;
	}

	// Empty
	if (pQueue->Count <= 0)
	{
		goto STATICQUEUE_POP__GOTO_END;
	}
    
    if (pQueue->Doing == TRUE)
    {
        goto STATICQUEUE_POP__GOTO_END;
    }

	memcpy(pData, &pQueue->Buffer[pQueue->PopPoint * QUEUE_BLOCK_SIZE], QUEUE_BLOCK_SIZE);
	pQueue->Count -= 1;
	pQueue->PopPoint += 1;
	if (pQueue->PopPoint >= QUEUE_MAX_COUNT__COMMON)
	{
		pQueue->PopPoint = 0;
	}

	nRet = TRUE;

STATICQUEUE_POP__GOTO_END:

	return nRet;
}


uint8_t StaticQueue_HeadDelete(PSTATIC_QUEUE pQueue)
{
	uint8_t nRet = 0;

	if (pQueue == NULL)
	{
		goto STATICQUEUE_POP__GOTO_END;
	}

	//EnterCriticalSection(&g_cs);

	// Empty
	if (pQueue->Count <= 0)
	{
		goto STATICQUEUE_POP__GOTO_END;
	}

    pQueue->Doing = TRUE;

	pQueue->Count -= 1;
	pQueue->PopPoint += 1;
	if (pQueue->PopPoint >= QUEUE_MAX_COUNT__COMMON)
	{
		pQueue->PopPoint = 0;
	}

	nRet = 1;

    pQueue->Doing = FALSE;

STATICQUEUE_POP__GOTO_END:

	//LeaveCriticalSection(&g_cs);
	return nRet;
}



uint8_t* StaticQueue_Get(PSTATIC_QUEUE pQueue)
{
	uint8_t* pRet = 0;

	if (pQueue == NULL)
	{
		goto STATICQUEUE_GET__GOTO_END;
	}

	// Empty
	if (pQueue->Count <= 0)
	{
		goto STATICQUEUE_GET__GOTO_END;
	}

	pRet = &pQueue->Buffer[pQueue->PopPoint * QUEUE_BLOCK_SIZE];

STATICQUEUE_GET__GOTO_END:

	return pRet;
}

uint32_t g_Full = 0;


uint8_t StaticQueue_CheckFull(PSTATIC_QUEUE pQueue)
{
	uint8_t nRet = 0;

	if (pQueue == NULL)
	{
		goto STATICQUEUE_CHECKFULL__GOTO_END;
	}

	//EnterCriticalSection(&g_cs);
	if (pQueue->Count >= QUEUE_MAX_COUNT__COMMON)
	{
		g_Full += 1;
		nRet = 1;
	}
	//LeaveCriticalSection(&g_cs);

STATICQUEUE_CHECKFULL__GOTO_END:

	return nRet;
}


uint8_t StaticQueue_CheckEmpty(PSTATIC_QUEUE pQueue)
{
	uint8_t nRet = 0;

	if (pQueue == NULL)
	{
		goto STATICQUEUE_CHECKEMPTY__GOTO_END;
	}

	//EnterCriticalSection(&g_cs);
	if (pQueue->Count <= 0)
	{
		nRet = 1;
	}
	//LeaveCriticalSection(&g_cs);

STATICQUEUE_CHECKEMPTY__GOTO_END:

	return nRet;
}


uint16_t GetScanTime(uint64_t* StartTime, uint32_t* ScanTime)
{
	uint16_t Temp = 0;

	if (*StartTime == 0)
	{
		goto GETSCANTIME__GOTO_END;
	}

	Temp = (uint16_t)(getElapsedUS(*StartTime) / 100);
	*ScanTime += Temp;

GETSCANTIME__GOTO_END:

	*StartTime = (uint64_t)getLongSysTick();
	return *ScanTime;
}




//
// Multi-Touch
//

#ifdef ADD_TOUCH

void SendTouchData_USB(PHID_MULTITOUCH pUserData)
{
	if (StaticQueue_CheckFull(&g_Queue_Common) == 1)
	{
		StaticQueue_HeadDelete(&g_Queue_Common);
	}

	StaticQueue_Push(&g_Queue_Common, (uint8_t*)pUserData);

//SENDTOUCHDATA_USB__GOTO_END:

	return;
}




void DMATouchData_USB(void)
{
#ifndef MODE_I2C
	// Virtual DMA Mask - MultiTouch
	mUsbEXIntDmaErrEn(TOUCH_FIFO_IN);
	mUsbEXIntDmaFinishEn(TOUCH_FIFO_IN);

	// Virtual DMA Start !!!!
	mUsbEXDmaConfig(TOUCH_FIFO_IN, sizeof(HID_MULTITOUCH), DIRECTION_IN);
	mUsbEXDmaAddr(TOUCH_FIFO_IN, (uint32_t)&g_Touch);
	mUsbEXDmaStart(TOUCH_FIFO_IN);
#endif
	return;
}



void SendTouchData(void)
{
	uint8_t				i = 0;
	uint8_t				ContactCount = 0;
	uint8_t				TouchDownCount = 0;
	HID_MULTITOUCH_I2C	TouchData_I2C = { 0, };
	PHID_MULTITOUCH		TouchData = &TouchData_I2C.Data;

	if (module_Skip_Event())
	{
		goto SENDTOUCHDATA__GOTO_END;
	}

	TouchData->ReportID = HID_REPORT_ID__MULTI_TOUCH;

	for (i = 0; i < HID_MAX_TOUCH; i++)
	{
		if (HID_id[i] != 0)
		{
#if (ID_MAPPING_CHANGE)
			ContactCount += 1;
#else
			if (g_TouchTip[HID_id[i]] != HID_status[i]) // It may be deleted on Current F/W... 200730, HanCH
			{
				g_TouchTip[HID_id[i]] = HID_status[i];
				ContactCount += 1;
			}
			else
			{
				if (HID_status[i] == FINGER_STATUS__TIP_SWITCH)
				{
					ContactCount += 1;
				}
			}
#endif
			// ScanTime / Touch Down
			if (HID_status[i] == FINGER_STATUS__TIP_SWITCH)
			{
				TouchDownCount += 1;
			}
		}

		TouchData->Touch[i].Status = HID_status[i];
		TouchData->Touch[i].ID = HID_id[i];
		TouchData->Touch[i].x = HID_x[i];
		TouchData->Touch[i].y = HID_y[i];
	}


	for (i = 0; i < HID_MAX_TOUCH; i++)
	{
		HID_status[i] = 0;
		HID_id[i] = 0;
		HID_x[i] = 0;
		HID_y[i] = 0;
	}

	
	if (ContactCount)
	{
		TouchData->ContactCount = ContactCount;
		TouchData->ScanTime = GetScanTime(&g_StartTime, &g_ScanTime);

		// ScanTime Init
		if (TouchDownCount == 0)
		{
			g_ScanTime = 0;
			g_StartTime = 0;
		}
	}

#ifndef MODE_I2C
#ifdef USB_SELECTIVE_SUSPEND
//	if (g_RemoteWakeup == 0)
//	{
//		g_ScanTime_Recovery = 0;
//		g_StartTime_Recovery = 0;
//	}

			
	//for (i = 0; i < HID_MAX_TOUCH; i++)
	{
		//if (TouchData->Touch[i].Status != 0)
		{
			if (g_RemoteWakeup == 1)// || g_Status[0].Status.Global.RemoteWakeup == 1)
			{
				if (ContactCount)
				{
					ResumeSigal();
					SendTouchData_USB(TouchData);
					if(g_StartTime_Recovery == 0)
					{
						GetScanTime(&g_StartTime_Recovery, &g_ScanTime_Recovery);
					}
				}
				
				if(g_StartTime_Recovery > 0)
				{
					if (GetScanTime(&g_StartTime_Recovery, &g_ScanTime_Recovery) >= 20000)
					{
						g_RemoteWakeup = 0;
						g_Status[0].Status.Global.RemoteWakeup = 0;
						g_ScanTime_Recovery = 0;
						g_StartTime_Recovery = 0;
						ResumeCnt = 0;
						
						// H/W Reset !!
						module_Protocol_Init();
						while(1);
					}
				}
			}
#if (CUSTOMER == NEC)
			else if(g_Status[0].Status.Global.RemoteWakeup == 1 && Recovery_ClearSus_Flag == 1)
			{
				if(ResumeCnt==5)
				{
					while(1);
				}
				else if(GetScanTime(&g_StartTime_Recovery_ClearSus, &g_ScanTime_Recovery_ClearSus )> 200 && ResumeCnt < 5) 
				{
					mUsbGoSuspend();						
					g_RemoteWakeup = 1;	
					ResumeSigal();
					ResumeCnt++;
					g_StartTime_Recovery_ClearSus = g_ScanTime_Recovery_ClearSus =0;
					Recovery_ClearSus_Flag = 0;
				}
			}
#endif				
		}
	}
#endif
#endif

	

	// USB
	if (ContactCount 
#ifndef MODE_I2C
		&& g_RemoteWakeup==0
#endif
	)
	{
		if ((CheckUsbConfig() != 0) && (CheckHIDReady() != 0))
		{
			SendTouchData_USB(TouchData);
		}
#ifdef MODE_I2C
		// I2C
		//else if (CheckI2CReady() != 0 && (custom_tool == 0))
		{
			TouchData_I2C.I2C_Length = sizeof(HID_MULTITOUCH_I2C);
			SendTouchData_I2C(&TouchData_I2C);
		}
#endif
	}

SENDTOUCHDATA__GOTO_END:

	return;
}

#endif







//
// Custom
//

uint16_t g_usRegAddr = 0;
uint8_t* rmi_read_ptr = NULL;
uint8_t* rmi_write_ptr = NULL;
int protocol_sent_byte = 0;
int protocol_received_byte = 0;

#if USED_I2C_READ_DATA_UNIT_2BYTE
uint8_t usTempSendData = 0;
bool_t bIsTempSend = NO;
#endif /* USED_I2C_READ_DATA_UNIT_2BYTE */

extern uint8_t* (*protocol_GetMappedPointer)(uint16_t addr);
extern void(*protocol_ClearInterrupt)(uint16_t addr);
__IO int hid_index;


void SendCustomData_USB(uint8_t* pUserData)
{
	if (StaticQueue_CheckFull(&g_Queue_Common) == 1)
	{
		goto SENDCUSTOMDATA_USB__GOTO_END;
	}

	StaticQueue_Push(&g_Queue_Common, (uint8_t*)pUserData);

SENDCUSTOMDATA_USB__GOTO_END:

	return;
}


// Device to Host
void DMACustomData_USB()
{
#ifndef MODE_I2C
	// Virtual DMA Mask - Custom IN
	mUsbEXIntDmaErrEn(CUSTOM_FIFO_IN);
	mUsbEXIntDmaFinishEn(CUSTOM_FIFO_IN);

	// Virtual DMA Start !!!!
	mUsbEXDmaConfig(CUSTOM_FIFO_IN, MX_PA_SZ_64, DIRECTION_IN);
	mUsbEXDmaAddr(CUSTOM_FIFO_IN, (uint32_t)g_CustomBuffer);
	mUsbEXDmaStart(CUSTOM_FIFO_IN);
#endif
	return;
}

void RecieveCustomData_DMA(void)
{
#ifndef MODE_I2C
#ifdef ADD_CUSTOM
	// Custom OUT
	mUsbEXDmaFinishClr(CUSTOM_FIFO_OUT);
	mUsbEXIntDmaErrDis(CUSTOM_FIFO_OUT);
	mUsbEXIntDmaFinishDis(CUSTOM_FIFO_OUT);

	// Virtual DMA Mask - Custom OUT
	mUsbEXIntDmaErrEn(CUSTOM_FIFO_OUT);
	mUsbEXIntDmaFinishEn(CUSTOM_FIFO_OUT);

	// Virtual DMA Start !!!!
	mUsbEXDmaConfig(CUSTOM_FIFO_OUT, MX_PA_SZ_64, DIRECTION_OUT);
	mUsbEXDmaAddr(CUSTOM_FIFO_OUT, (uint32_t)g_CustomBuffer);
	mUsbEXDmaStart(CUSTOM_FIFO_OUT);
#endif
#endif
	return;
}


void Protocol_hid_Init(void)
{
	//rmi_read_ptr = NULL;
	//protocol_sent_byte = 0;

	rmi_write_ptr = NULL;
	protocol_received_byte = 0;

	return;
}

void Protocol_hid__SetAddress(uint16_t usRegAddr)
{
	if (protocol_GetMappedPointer != NULL)
	{
		g_usRegAddr = usRegAddr;
		rmi_read_ptr = rmi_write_ptr = (*protocol_GetMappedPointer)(usRegAddr);
		protocol_sent_byte = 0;
		protocol_received_byte = 0;
	}

	return;
}


void Protocol_hid__FromHostToDevice(uint8_t Data)
{
	if (rmi_write_ptr != NULL)
	{
		*(rmi_write_ptr++) = Data;
		protocol_received_byte++;
	}

	return;
}


uint8_t Protocol_hid_FromDeviceToHost(uint8_t* pRetData, uint8_t b2Byte)
{
	uint8_t nRet = FALSE;

	if (rmi_read_ptr)
	{
#if USED_I2C_READ_DATA_UNIT_2BYTE
		if (b2Byte == TRUE)
		{
			if(bIsTempSend)
			{
				pRetData[0] = usTempSendData;
				bIsTempSend = NO;
			}
			else
			{
				pRetData[0] = *(rmi_read_ptr++);
				usTempSendData = *(rmi_read_ptr++);
				bIsTempSend = YES;
			}
		}
		else
		{
			pRetData[0] = *(rmi_read_ptr++);
		}
#else /* USED_I2C_READ_DATA_UNIT_2BYTE */
		pRetData[0] = *(rmi_read_ptr++);
#endif /* USED_I2C_READ_DATA_UNIT_2BYTE */

		if (protocol_ClearInterrupt != NULL)
		{
			(*protocol_ClearInterrupt)(g_usRegAddr + protocol_sent_byte);
		}
		protocol_sent_byte++;

		nRet = TRUE;
	}

	return nRet;
}



void HidReadWrite__Read(PHJ_HID_CONTROL_STRUCT pOutBuffer)
{
	uint16_t	index = 0;
	uint8_t		nData = 0;

	pOutBuffer->PacketID = HID_REPORT_ID__CUSTOM_IN;
	pOutBuffer->DeviceID_b.addr = 0x34;
	pOutBuffer->DeviceID_b.bRead = TRUE;
	
	for (index = 0; index< pOutBuffer->Length; index++)
	{
		if (Protocol_hid_FromDeviceToHost(&nData, FALSE) == TRUE)
		{
			pOutBuffer->Data[index] = nData;
		}
	}

#ifdef ADD_CUSTOM
	SendCustomData_USB((uint8_t*)pOutBuffer);
#endif
	return;
}


#ifdef MODE_I2C
void HidReadWrite__Read_I2C(PHJ_HID_CONTROL_STRUCT_I2C pHidControl)
{
	uint16_t	index = 0;
	uint8_t		nData = 0;

	pHidControl->Data.PacketID = HID_REPORT_ID__CUSTOM_IN;
	pHidControl->Data.DeviceID_b.addr = 0x34;
	pHidControl->Data.DeviceID_b.bRead = TRUE;

	for (index = 0; index < pHidControl->Data.Length; index++)
	{
		if (Protocol_hid_FromDeviceToHost(&nData, FALSE) == TRUE)
		{
			pHidControl->Data.Data[index] = nData;
		}
	}

	// Send
	SendCustomData_I2C(pHidControl);
	return;
}
#endif /* MODE_I2C */


void HidReadWrite__Write(PHJ_HID_CONTROL_STRUCT pHidControl)
{
	uint16_t usRegAddr = 0;
	uint16_t index = 0;

	usRegAddr = pHidControl->Data[0] << 8;
	usRegAddr |= pHidControl->Data[1];

	Protocol_hid__SetAddress(usRegAddr);
	for (index = 0; index < (pHidControl->Length-2); index++)
	{
		Protocol_hid__FromHostToDevice(pHidControl->Data[2+index]);
	}

	return;
}

// Host to Device
void RecieveCustomData(uint8_t* pData)
{
	PHJ_HID_CONTROL_STRUCT  pHidControl = (PHJ_HID_CONTROL_STRUCT)pData;

	switch (pHidControl->PacketID)
	{
		case HID_REPORT_ID__CUSTOM_OUT:
		{
			if (pHidControl->DeviceID_b.bRead)
			{
				HidReadWrite__Read(pHidControl);
			}
			else
			{
				HidReadWrite__Write((PHJ_HID_CONTROL_STRUCT)pData);
			}

			break;
		}
	}

	return;
}



void protocol_hid_PushTouchEvent(const uSWIPTouchItem_t* _kptItem)
{
	if (hid_index < HID_MAX_TOUCH)
	{
#if USED_SHARP_SPECIFIC_PROTOCOL
		HID_status[hid_index] = (_kptItem->tItem00.tInfo.b1Status & 0x01);
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
		HID_status[hid_index] = _kptItem->tItem00.tInfo.bTouch;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
		HID_id[hid_index] = _kptItem->tItem00.tInfo.b4FingerID;;
#if USED_POOR_PANEL_COLLINE_DISABLE
		uint32_t ulTempXPos;
		ulTempXPos = ((uint32_t)((_kptItem->tItem00.ucXHigh << 8 | _kptItem->tItem00.ucXLow) * 10145))/10000;
		if(ulTempXPos > I2C_X_RESOLUTION)
			ulTempXPos = I2C_X_RESOLUTION;
		HID_x[hid_index] = ulTempXPos;
#else /* USED_POOR_PANEL_COLLINE_DISABLE */
		HID_x[hid_index] = _kptItem->tItem00.ucXHigh << 8 | _kptItem->tItem00.ucXLow;
#endif /* USED_POOR_PANEL_COLLINE_DISABLE */
		HID_y[hid_index] = _kptItem->tItem00.ucYHigh << 8 | _kptItem->tItem00.ucYLow;

		hid_index++;
	}
}

static tAlgorithmInfo_t * sptAlgorithmInfo = NULL;

void protocol_hid_PushPenEvent(const uSWIPTouchItem_t* _kptItem)
{
#if USED_SHARP_SPECIFIC_PROTOCOL
	HID_PEN_STATUS = (_kptItem->tItem00.tInfo.b1Status & 0x01);
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
	HID_PEN_STATUS = sptAlgorithmInfo->bLocal_sensing | (sptAlgorithmInfo->tPenInfo.bPenContact<<1);
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
	HID_PEN_X = _kptItem->tItem00.ucXHigh << 8 | _kptItem->tItem00.ucXLow;
	HID_PEN_Y = _kptItem->tItem00.ucYHigh << 8 | _kptItem->tItem00.ucYLow;

	g_PenEventNum++;
}

#ifdef ADD_PEN

void SendPenData_USB(PHID_PEN pUserData)
{
	if (StaticQueue_CheckFull(&g_Queue_Common) == 1)
	{
		goto SENDPENDATA_USB__GOTO_END;
	}

	StaticQueue_Push(&g_Queue_Common, (uint8_t*)pUserData);

SENDPENDATA_USB__GOTO_END:

	return;
}


void DMAPenData_USB(void)
{
#ifndef MODE_I2C
	// Virtual DMA Mask - Pen
	mUsbEXIntDmaErrEn(PEN_FIFO_IN);
	mUsbEXIntDmaFinishEn(PEN_FIFO_IN);

	// Virtual DMA Start !!!!
	mUsbEXDmaConfig(PEN_FIFO_IN, sizeof(HID_PEN), DIRECTION_IN);
	mUsbEXDmaAddr(PEN_FIFO_IN, (uint32_t)&g_Pen);
	mUsbEXDmaStart(PEN_FIFO_IN);
#endif
	return;
}


#ifdef JOSH3_PEN_TEST
uint8_t g_InRange = 0;
uint8_t g_InRange_Multi[2] = { 0, };
uint16_t g_Azimuth = 0;
uint16_t g_Altitude = 9000;
uint16_t g_Tilt_x = -9000;
uint16_t g_Tilt_y = 9000;
uint16_t g_Pressure = 2000;
uint16_t g_Twist = 36000;
#endif

uint8_t inrange_cnt = 0;
#if USED_WACOM_HIDI2C_DRIVER
extern uint8_t g_WacomISD;
#endif

#if USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL
uint16_t ulPrevRealPressure = 0;
uint16_t ulPrev1stCompPressure = 0;
uint16_t ulPressureChangeRatio_Current;
uint16_t ulPressureChangeRatio_Prev;
uint16_t ulPressureChangeRatio_PrevPrev;
#endif /* USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL */
//uint8_t prev_InRange = 0, prev_Tip = 0;

#define USED_PRESSURE_DEBUG	(NO)
#if USED_PRESSURE_DEBUG
#define DEF_PRESSURE_DATA_DBUG_NUM		(8)
uint32_t ulRealPressureData[DEF_PRESSURE_DATA_DBUG_NUM] = {0,};
uint32_t ulPostPressureData[DEF_PRESSURE_DATA_DBUG_NUM] = {0,};
uint32_t ulDebugPressureDataCnt = 0;

uint8_t ulDebugCurrentChangeRatio[DEF_PRESSURE_DATA_DBUG_NUM] = {0,};
uint8_t ulDebugPostChangeRatio[DEF_PRESSURE_DATA_DBUG_NUM] = {0,};
uint32_t ulDebugChangeRatioCnt = 0;
#endif
#if USED_NOISE_HOPPING_FREQ
int ChangeFreqCnt = 3;
#endif
void SendPenData(void)
{
	static HID_PEN prevHIDData;
#if (USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL || USED_NOISE_HOPPING_FREQ)
	#if USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL
		int16_t sSumChangeRaito = 0;
		static uint16_t prev2HIDDataPressure;
		static uint8_t BrushFinishTipCnt = 0;
	#endif
	const tAlgorithmModeConf_t * pAlgorithmModeConf = algorithm_GetModeConfig();;
#endif /* (USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL || USED_NOISE_HOPPING_FREQ) */
	HID_PEN_I2C		PenData_I2C = { 0, };
	PHID_PEN		PenData = &PenData_I2C.Data;
#if USED_PEN_ID_GET_FUNCTION
	uint64_t pSerialID;
	if(sptAlgorithmInfo->tPenInfo.bGetPenIDComplete == NO)
	{
		goto SENDPENDATA__GOTO_END;
	}
	pSerialID = sptAlgorithmInfo->tPenInfo.bPenIDVal;
#endif /* USED_PEN_ID_GET_FUNCTION */

	if (module_Skip_Event())
	{
		goto SENDPENDATA__GOTO_END;
	}

	PenData->ReportID = HID_REPORT_ID__PEN;
	
	PenData->x = HID_PEN_X;
#if USED_WACOM_HIDI2C_DRIVER
	PenData->SwitchData.Data = 0;
#endif /* USED_WACOM_HIDI2C_DRIVER */

	PenData->SwitchData.u.InRange = HID_PEN_STATUS & 0x1;
	PenData->SwitchData.u.Tip = ((HID_PEN_STATUS>>1) & 0x1) & PenData->SwitchData.u.InRange;
#if USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL
	{
		uint16_t usPressureValue;
		/*
		 * 1st Processing
		 */
		/*
		 * The Frame rate of pen position is 240Hz, but the Frame rate of pen pressure is 120Hz
		 * So, two pen position must use the same pen pressure data.
		 */
		usPressureValue = sptAlgorithmInfo->tPenInfo.us_pendata_pressure;
		if(usPressureValue > 0)
		{
			if(ulPrevRealPressure == usPressureValue)
			{
				if(pAlgorithmModeConf->PenData.bOrgPressureInterpolation == 1)usPressureValue = usPressureValue*16 + prevHIDData.Pressure*0; 
				else usPressureValue = usPressureValue*(16 - pAlgorithmModeConf->PenData.ulPressureLevelIIR_Prev_Coef_THD) + prevHIDData.Pressure * pAlgorithmModeConf->PenData.ulPressureLevelIIR_Prev_Coef_THD;
			}
			else
			{
				if(pAlgorithmModeConf->PenData.bOrgPressureInterpolation == 1)usPressureValue = usPressureValue*(16 - pAlgorithmModeConf->PenData.ulPressureLevelIIR_Prev_Coef_THD) + ulPrevRealPressure * pAlgorithmModeConf->PenData.ulPressureLevelIIR_Prev_Coef_THD;
				else usPressureValue = usPressureValue*8 + prevHIDData.Pressure*8;
			}
			usPressureValue = (prevHIDData.Pressure > 2047) ? usPressureValue + 15 : usPressureValue;
			usPressureValue = usPressureValue >> 4;
		}

		ulPrevRealPressure = sptAlgorithmInfo->tPenInfo.us_pendata_pressure;

		/*
		 * 2nd Processing
		 * For Soft calligraphic expression
		 */
		if(usPressureValue > 0)
		{
	#if USED_PRESSURE_DEBUG
			ulRealPressureData[ulDebugPressureDataCnt] = usPressureValue;
	#endif /* USED_PRESSURE_DEBUG */
			if(usPressureValue < ulPrev1stCompPressure)
			{
				ulPressureChangeRatio_Current = ((ulPrev1stCompPressure - usPressureValue) * 100) / ulPrev1stCompPressure;
				ulPrev1stCompPressure = usPressureValue;
				sSumChangeRaito = ulPressureChangeRatio_Current + ulPressureChangeRatio_Prev + ulPressureChangeRatio_PrevPrev;
				sSumChangeRaito = (sSumChangeRaito * pAlgorithmModeConf->PenData.ulPressureChangeRatioTHD) / 100;
				ulPressureChangeRatio_PrevPrev = ulPressureChangeRatio_Prev;
				ulPressureChangeRatio_Prev = ulPressureChangeRatio_Current;

	#if USED_PRESSURE_DEBUG
				ulDebugCurrentChangeRatio[ulDebugChangeRatioCnt] = ulPressureChangeRatio_Current;
				ulDebugPostChangeRatio[ulDebugChangeRatioCnt] = sSumChangeRaito;
				ulDebugChangeRatioCnt++;
				if(ulDebugChangeRatioCnt >= DEF_PRESSURE_DATA_DBUG_NUM)
					ulDebugChangeRatioCnt = 0;
	#endif /* USED_PRESSURE_DEBUG */
				if(sSumChangeRaito > 100)
				{
					sSumChangeRaito = 100;
				}

				usPressureValue = usPressureValue - (usPressureValue * sSumChangeRaito / 100);
				if(usPressureValue == 0)
				{
					usPressureValue = 1;
				}

	#if USED_PRESSURE_DEBUG
				ulPostPressureData[ulDebugPressureDataCnt] = usPressureValue;
				ulDebugPressureDataCnt++;
				if(ulDebugPressureDataCnt >= DEF_PRESSURE_DATA_DBUG_NUM)
					ulDebugPressureDataCnt = 0;
	#endif /* USED_PRESSURE_DEBUG */
				PenData->Pressure = usPressureValue;
			}
			else
			{
				ulPressureChangeRatio_Current = 0;
				ulPressureChangeRatio_Prev = 0;
				ulPressureChangeRatio_PrevPrev = 0;

				if(pAlgorithmModeConf->PenData.bOrgPressureInterpolation == 1)PenData->Pressure = usPressureValue;
				else
				{
					PenData->Pressure = (usPressureValue*1 + prevHIDData.Pressure*3);
					PenData->Pressure = (prevHIDData.Pressure > 2047) ? PenData->Pressure + 3 : PenData->Pressure;
					PenData->Pressure = PenData->Pressure >> 2;
				}

				ulPrev1stCompPressure = PenData->Pressure;
			}
		}
		else
		{
			PenData->Pressure = 0;
		}
	}
#else /* USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL */
	PenData->Pressure = (sptAlgorithmInfo->tPenInfo.us_pendata_pressure*1 + prevHIDData.Pressure*3);
	PenData->Pressure = (prevHIDData.Pressure > 2047) ? PenData->Pressure + 3 : PenData->Pressure;
	PenData->Pressure = PenData->Pressure >> 2;
#endif /* USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL */
	//PenData->Pressure = tTiltInfo.HID_ALTITUDE;


	PenData->y = HID_PEN_Y;

#if USED_WACOM_HIDI2C_DRIVER
	// MS In-box Driver
	if (g_WacomISD == 0)
	{
		PenData->SwitchData.u.Eraser = sptAlgorithmInfo->tPenInfo.bPen_button[0] & PenData->SwitchData.u.InRange & PenData->SwitchData.u.Tip;
		PenData->SwitchData.u.Barrel = sptAlgorithmInfo->tPenInfo.bPen_button[1];
		PenData->SwitchData.u.Invert = (sptAlgorithmInfo->tPenInfo.bPen_button[0] & PenData->SwitchData.u.InRange);// & (1 - PenData->SwitchData.u.Eraser) & PenData->SwitchData.u.InRange);
		PenData->SwitchData.u.Tip = (/*(1-g_pen_button2) &*/ (1 - sptAlgorithmInfo->tPenInfo.bPen_button[0])) & PenData->SwitchData.u.Tip;
	}
	// Wacom ISD Driver
	else
	{
		PenData->SwitchData.u.Eraser = 0;
		PenData->SwitchData.u.Barrel = sptAlgorithmInfo->tPenInfo.bPen_button[0];
		PenData->SwitchData.u.SecondaryBarrelSwitch = sptAlgorithmInfo->tPenInfo.bPen_button[1];
		PenData->SwitchData.u.Invert = 0;
		//PenData->SwitchData.u.Tip = (/*(1-g_pen_button2) &*/ (1 - sptAlgorithmInfo->tPenInfo.bPen_button[0])) & PenData->SwitchData.u.Tip;
	}
#else
	PenData->SwitchData.u.Eraser = sptAlgorithmInfo->tPenInfo.bPen_button[0] & PenData->SwitchData.u.InRange & PenData->SwitchData.u.Tip;
	PenData->SwitchData.u.Barrel = sptAlgorithmInfo->tPenInfo.bPen_button[1];
	PenData->SwitchData.u.Invert = (sptAlgorithmInfo->tPenInfo.bPen_button[0] & PenData->SwitchData.u.InRange);// & (1 - PenData->SwitchData.u.Eraser) & PenData->SwitchData.u.InRange);
	PenData->SwitchData.u.Tip = (/*(1-g_pen_button2) &*/ (1 - sptAlgorithmInfo->tPenInfo.bPen_button[0])) & PenData->SwitchData.u.Tip;
#endif

	PenData->Tilt_x = sptAlgorithmInfo->tTiltInfo.HID_TILT_X-9000;
	PenData->Tilt_y = sptAlgorithmInfo->tTiltInfo.HID_TILT_Y-9000;
	PenData->Twist = sptAlgorithmInfo->tTiltInfo.HID_AZIMUTH;//tTiltInfo.HID_TWIST;

#ifdef HID_AZIMUTH_INPUT
	PenData->Azimuth = sptAlgorithmInfo->tTiltInfo.HID_AZIMUTH;
	PenData->Altitude = sptAlgorithmInfo->tTiltInfo.HID_ALTITUDE;
#endif

#ifdef HID_PEN_SCAN_TIME
	PenData->ScanTime = GetScanTime(&g_StartTime_Pen, &g_ScanTime_Pen);
	//PenData->ScanTime = tTiltInfo.HID_TWIST;
#endif

#ifdef ADD_PEN_EXTRA
#if USED_WACOM_HIDI2C_DRIVER
	// Pen ID
	// 101 0101 0101 0101 0101 0101 0101 0101 0101 0101 0101 0101 0101 (51bit)
	#if USED_PEN_ID_GET_FUNCTION
		PenData->PenID = pSerialID;
		PenData->PenID_VendorID = 0x03;
		PenData->PenID_Reserved1 = 0;
		PenData->PenID_Reserved2 = 0;
	#else
		PenData->PenID = 0x7477025369121;
	#endif

	// Bettery Level
	PenData->BetteryLevel = 255;
#else
	#if USED_PEN_ID_GET_FUNCTION
		PenData->PenID = pSerialID;
	#else
		PenData->PenID = 0x7477025369121;
	#endif
	PenData->PenID_Reserved = 0;

	// Bettery Level
	PenData->BetteryLevel = 0;
#endif
#endif

#ifdef JOSH3_PEN_TEST

	/*
	if (PenData->SwitchData.u.InRange == 1)
	{
		if (g_InRange == 0)
		{
			g_InRange = 1;
		}
		else
		{
			PenData->SwitchData.u.Tip = 1;
		}
	}
	else
	{
		g_InRange = 0;
		PenData->SwitchData.u.Tip = 0;
	}
	*/

	if (HID_status[0] == FINGER_STATUS__TIP_SWITCH)
	{
		PenData->SwitchData.u.InRange = 1;

		if (g_InRange == 0)
		{
			g_InRange = 1;
			PenData->SwitchData.u.Tip = 0;
		}
		else
		{
			PenData->SwitchData.u.Tip = 1;
		}

		PenData->Pressure = g_Pressure;

		g_Azimuth += 1;
		g_Altitude -= 1;

		g_Tilt_x += 10;
		g_Tilt_y -= 10;

		g_Pressure += 1;
		g_Twist -= 1;
	}
	else
	{
		g_InRange = 0;
		PenData->SwitchData.u.InRange = 0;
		PenData->SwitchData.u.Tip = 0;
		PenData->Pressure = 0;
	}

	PenData->x = HID_x[0];
	PenData->y = HID_y[0];
	PenData->Tilt_x = g_Tilt_x;
	PenData->Tilt_y = g_Tilt_y;
	PenData->Twist = g_Twist;

#ifdef HID_AZIMUTH_INPUT
	PenData->Azimuth = g_Azimuth;
	PenData->Altitude = g_Altitude;
#endif
#endif


#ifdef JOSH3_PEN_TEST
#else
	if (g_PenEventNum == 0)
		PenData->SwitchData.Data = 0;
	else if (HID_PEN_STATUS == 0)
		PenData->SwitchData.Data = 0;
	
	// In-range -> In-range Tip
	if(prevHIDData.SwitchData.u.InRange == NO && PenData->SwitchData.u.InRange == YES && PenData->SwitchData.u.Tip == YES)
	{
		PenData->SwitchData.u.Tip = NO;
	}
	// In-range Tip -> In-range
	if(prevHIDData.SwitchData.u.InRange == YES && prevHIDData.SwitchData.u.Tip == YES && PenData->SwitchData.u.InRange == NO && PenData->SwitchData.u.Tip == NO)
	{
		PenData->SwitchData.u.InRange = YES;
	}
	
#if USED_NOISE_HOPPING_FREQ
	if(pAlgorithmModeConf->Noise.bHoppingConnectPenContact)
	{
		if(hal_Info_GetCurrentWGPPenBeaconType() == PWM_WGP_PEN_HOPP_SETTABLE_BEACON)
		{
			ChangeFreqCnt = 0;
		}
		if(ChangeFreqCnt < 3)
		{
			ChangeFreqCnt++;
			if(PenData->SwitchData.u.Tip == NO)
				PenData = &prevHIDData;
		}
	}
#endif

#if USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL
	{
		bool_t bIsBrushFinishReport = NO;
		uint32_t ulPrevIIRCoefValue = 0;
		if(PenData->Pressure != 0 && PenData->SwitchData.u.Tip == NO && PenData->SwitchData.u.InRange == YES)
		{
			if(BrushFinishTipCnt > 0 && prevHIDData.Pressure >= 1)
			{
//				PenData->Pressure = 1;
				bIsBrushFinishReport = YES;
				BrushFinishTipCnt--;
			}
			else
			{
				PenData->Pressure = 0;
				BrushFinishTipCnt = 0;
			}
		}
		else if(PenData->SwitchData.u.Tip == YES && PenData->SwitchData.u.InRange == YES)
		{
			if(PenData->Pressure < 1)
			{
				if(prevHIDData.Pressure > 0)
				{
					PenData->Pressure = prevHIDData.Pressure;
					prevHIDData.Pressure = 0;
				}
				else
				{
					PenData->Pressure = 1;
				}
			}
			
			BrushFinishTipCnt = pAlgorithmModeConf->PenData.bUsedBrushFinishTip;
		}

		if(bIsBrushFinishReport)
		{
			if(pAlgorithmModeConf->PenData.bBrushFinishPressure1Report)
			{
				int32_t lxyDiff_Sum;
				ulPrevIIRCoefValue = ((4095 - prevHIDData.Pressure)*100) / 4095;
				lxyDiff_Sum = ABS((int16_t)PenData->x - (int16_t)prevHIDData.x) + ABS((int16_t)PenData->y - (int16_t)prevHIDData.y);
				if(lxyDiff_Sum < 100 || ulPrevIIRCoefValue > 100)
				{
					ulPrevIIRCoefValue = 100;
				}
				
				PenData->Pressure = 1;
			

				PenData->x = ((PenData->x * (100 - ulPrevIIRCoefValue)) + (prevHIDData.x * ulPrevIIRCoefValue)) / 100;
				PenData->y = ((PenData->y * (100 - ulPrevIIRCoefValue)) + (prevHIDData.y * ulPrevIIRCoefValue)) / 100;
			}		
			else
			{				
				int pres_array[2];
				int tmp_pres = pres_array[0] = prevHIDData.Pressure;//PenData->Pressure;
				pres_array[1] =	prev2HIDDataPressure;
					
				for(int i = 0; i < 1; i++)
				{
					if(pres_array[i] > 0 && (pres_array[i] != pres_array[i+1]))
					{
						if(pres_array[i] <= pres_array[i+1])tmp_pres = pres_array[i] >> 1;
						else tmp_pres = pres_array[i] + (pres_array[i] - pres_array[i+1]);
						break;
					}
				}
						
				if(tmp_pres < 10)tmp_pres = 10;
				PenData->Pressure  = (uint16_t)tmp_pres;				
				
			}
		}
		
		if((prevHIDData.SwitchData.u.Invert != PenData->SwitchData.u.Invert) ||
			(prevHIDData.SwitchData.u.Barrel != PenData->SwitchData.u.Barrel))
		{
			prev2HIDDataPressure = prevHIDData.Pressure;
			prevHIDData = *PenData;
			PenData->SwitchData.Data = 0;
		}
		else
		{
			prev2HIDDataPressure = prevHIDData.Pressure;
			prevHIDData = *PenData;

			if(bIsBrushFinishReport)
			{
				PenData->SwitchData.u.Tip = YES;
				prevHIDData.SwitchData.u.Tip = YES;
				if(BrushFinishTipCnt == 0)prevHIDData.Pressure = 0;
			}
		}
	}
#else /* USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL */
	if(PenData->Pressure != 0 && PenData->SwitchData.u.Tip == NO && PenData->SwitchData.u.InRange == YES)
	{
		PenData->Pressure = 0;
	}
	else if(PenData->Pressure <= 1 && PenData->SwitchData.u.Tip == YES && PenData->SwitchData.u.InRange == YES)
	{
		if(prevHIDData.Pressure > 0)
		{
			PenData->Pressure = prevHIDData.Pressure;
		}
		else
		{
			PenData->Pressure = 1;
		}
	}
		
	if((prevHIDData.SwitchData.u.Invert != PenData->SwitchData.u.Invert) ||
		(prevHIDData.SwitchData.u.Barrel != PenData->SwitchData.u.Barrel))
	{
#if USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL
		prev2HIDDataPressure = prevHIDData.Pressure;
#endif
		prevHIDData = *PenData;
		PenData->SwitchData.Data = 0;
	}
	else
	{
#if USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL
		prev2HIDDataPressure = prevHIDData.Pressure;
#endif
		prevHIDData = *PenData;
	}
#endif /* USED_PEN_PRESSURE_BRUSH_LEVEL_CTRL */
	
	g_PenEventNum = 0;
	
	if(PenData->SwitchData.u.Tip == NO && PenData->SwitchData.u.InRange == NO && PenData->Pressure != 0)
	{
		PenData->Pressure = 0;
	}
	
	if( PenData->SwitchData.u.InRange == NO && PenData->SwitchData.u.Tip == NO)
	{
		sptAlgorithmInfo->tPenInfo.bReportEraser = 0;
	}
	
#endif

#ifndef MODE_I2C
#ifdef USB_SELECTIVE_SUSPEND
	if (PenData->SwitchData.u.InRange != 0)
	{
		if (g_RemoteWakeup == 1)
		{
			ResumeSigal();
			return;
		}
	}
#endif
#endif

	if (g_PenTip != PenData->SwitchData.u.InRange)
	{
		g_PenTip = PenData->SwitchData.u.InRange;
	}
	else
	{
		if (g_PenTip == 0)
		{
			// No Data ...
			g_ScanTime_Pen = 0;
			g_StartTime_Pen = 0;
			goto SENDPENDATA__GOTO_END;
		}
	}
	
	/*
	 * NOTE : what is the below code? I don't understand.TT
	 */
//	if(PenData->SwitchData.u.Tip == YES)			// finger touch pen contact
//	{
//		if(inrange_cnt < 7)
//		{
//			PenData->SwitchData.u.Tip = NO;
//			inrange_cnt++;
//		}
//	}
//	else
//	{
//		if(PenData->SwitchData.u.InRange == YES && inrange_cnt < 7)
//			inrange_cnt++;
//	}

	// USB
	if ((CheckUsbConfig() != 0) && (CheckHIDReady() != 0))
	{
		SendPenData_USB(PenData);
	}
#ifdef MODE_I2C
	// I2C
//	else if (CheckI2CReady() != 0)
	else
	{
		SendPenData_I2C(&PenData_I2C);
	}
#endif


SENDPENDATA__GOTO_END:

	return;
}







#if 0
void SendPenData_Multi(void)
{	
	static HID_PEN prevHIDData;
	
	HID_PEN_I2C		PenData_I2C = { 0, };
	PHID_PEN		PenData = &PenData_I2C.Data;
	uint8_t			i = 0;

	if (module_Skip_Event())
	{
		goto SENDPENDATA__GOTO_END;
	}

	
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			PenData->ReportID = HID_REPORT_ID__PEN;
		}
		else
		{
			PenData->ReportID = HID_REPORT_ID__PEN_SECOND;
		}
		
		PenData->ScanTime = GetScanTime(&g_StartTime_Pen_Multi[i], &g_ScanTime_Pen_Multi[i]);
		
#ifdef ADD_PEN_EXTRA
		PenData->TransducerIndex_PenID = i;
		PenData->TransducerIndex_WacomID_LSB = (UINT32)PEN_ID_19BIT(0x12345678);
#ifdef ADD_WACOM_51BIT
		PenData->TransducerIndex_WacomID_MSB = (UINT32)PEN_ID_51BIT(0x12345678);
#endif
		PenData->SerialNumber = 0x12345678 + i;
		PenData->VendorID = 200;
		PenData->BatteryStlength = 201;
#endif

#ifdef JOSH3_PEN_TEST
		//
		// Test Code !!!
		//
		if (HID_status[i] == FINGER_STATUS__TIP_SWITCH)
		{
			PenData->SwitchData.u.InRange = 1;

			if (g_InRange_Multi[i] == 0)
			{
				g_InRange_Multi[i] = 1;
				PenData->SwitchData.u.Tip = 0;
			}
			else
			{
				PenData->SwitchData.u.Tip = 1;
			}

			PenData->Pressure = 2000;
		}
		else
		{
			g_InRange_Multi[i] = 0;
			PenData->SwitchData.u.InRange = 0;
			PenData->SwitchData.u.Tip = 0;
			PenData->Pressure = 0;
		}

		PenData->x = HID_x[i];
		PenData->y = HID_y[i];
		PenData->Tilt_x = 0;
		PenData->Tilt_y = 0;
		PenData->Twist = 0;
		PenData->Azimuth = 0;
		PenData->Altitude = 0;
#else
		//
		// Real Code !!
		//
		PenData->x = HID_PEN_X;
		PenData->SwitchData.u.InRange = sptAlgorithmInfo->bLocal_sensing;
		PenData->SwitchData.u.Tip = sptAlgorithmInfo->tPenInfo.bPenContact & PenData->SwitchData.u.InRange;
		PenData->Pressure = (sptAlgorithmInfo->tPenInfo.us_pendata_pressure*1 + prevHIDData.Pressure*3);
		PenData->Pressure = (prevHIDData.Pressure > 2047) ? PenData->Pressure + 3 : PenData->Pressure;
		PenData->Pressure = PenData->Pressure >> 2;

		PenData->y = HID_PEN_Y;
		PenData->SwitchData.u.Eraser = g_pen_button1 & PenData->SwitchData.u.InRange & PenData->SwitchData.u.Tip;
		PenData->SwitchData.u.Invert = ((g_pen_button1) & PenData->SwitchData.u.InRange);// & (1 - PenData->SwitchData.u.Eraser) & PenData->SwitchData.u.InRange);
		PenData->SwitchData.u.Tip = (/*(1-g_pen_button2) &*/ (1 - g_pen_button1)) & PenData->SwitchData.u.Tip;
		PenData->SwitchData.u.Barrel = g_pen_button2;
		PenData->Tilt_x = tTiltInfo.HID_TILT_X-9000;
		PenData->Tilt_y = tTiltInfo.HID_TILT_Y-9000;
		PenData->Twist = tTiltInfo.HID_AZIMUTH;

	#ifdef HID_AZIMUTH_INPUT
		PenData->Azimuth = tTiltInfo.HID_AZIMUTH;
		PenData->Altitude = tTiltInfo.HID_ALTITUDE;
	#endif
		
		if (g_PenEventNum == 0)
		{
			PenData->SwitchData.Data = 0;
		}
		else if (HID_PEN_STATUS == 0)
		{
			PenData->SwitchData.Data = 0;
		}
		
		if(!PenData->SwitchData.u.Tip && (prevHIDData.SwitchData.u.Invert != PenData->SwitchData.u.Invert))
		{
			prevHIDData = *PenData;
			PenData->SwitchData.Data = 0;
		}
		else
		{
			prevHIDData = *PenData;
		}
	
		g_PenEventNum = 0;



		if (g_PenTip_Multi[i] != PenData->SwitchData.u.InRange)
		{
			g_PenTip_Multi[i] = PenData->SwitchData.u.InRange;
		}
		else
		{
			if (g_PenTip_Multi[i] == 0)
			{
				// No Data ...
				g_ScanTime_Pen_Multi[i] = 0;
				g_StartTime_Pen_Multi[i] = 0;
				goto SENDPENDATA__GOTO_END;
			}
		}


		// finger touch pen contact
		if(PenData->SwitchData.u.Tip == YES)			
		{
			if(inrange_cnt < 7)
			{
				PenData->SwitchData.u.Tip = NO;
				inrange_cnt++;
			}
		}
		else
		{
			if(PenData->SwitchData.u.InRange == YES && inrange_cnt < 7)
				inrange_cnt++;
		}
#endif

		// USB
		if ((CheckUsbConfig() != 0) && (CheckHIDReady() != 0))
		{
			SendPenData_USB(PenData);
		}
	}


SENDPENDATA__GOTO_END:

	return;
}
#endif

#endif





//
// Bulk Custom
//


// Host to Device
void RecieveBulkCustomData_DMA(void)
{
#ifndef MODE_I2C
#ifdef ADD_BULK_CUSTOM
	// Bulk Custom OUT
	mUsbEXDmaFinishClr(BULK_CUSTOM_FIFO_OUT);
	mUsbEXIntDmaErrDis(BULK_CUSTOM_FIFO_OUT);
	mUsbEXIntDmaFinishDis(BULK_CUSTOM_FIFO_OUT);

	// Virtual DMA Mask - Bulk Custom OUT
	mUsbEXIntDmaErrEn(BULK_CUSTOM_FIFO_OUT);
	mUsbEXIntDmaFinishEn(BULK_CUSTOM_FIFO_OUT);

	// Virtual DMA Start !!!!
	mUsbEXDmaConfig(BULK_CUSTOM_FIFO_OUT, MX_PA_SZ_64, DIRECTION_OUT);
	mUsbEXDmaAddr(BULK_CUSTOM_FIFO_OUT, (uint32_t)g_BulkCustomBuffer);
	mUsbEXDmaStart(BULK_CUSTOM_FIFO_OUT);
#endif
#endif
	return;
}

// Device to Host
void DMABulkData_USB(void)
{
#ifndef MODE_I2C
	// Virtual DMA Mask - Bulk Custom IN
	mUsbEXIntDmaErrEn(BULK_CUSTOM_FIFO_IN);
	mUsbEXIntDmaFinishEn(BULK_CUSTOM_FIFO_IN);

	// Virtual DMA Start !!!!
	mUsbEXDmaConfig(BULK_CUSTOM_FIFO_IN, MX_PA_SZ_64, DIRECTION_IN);
	mUsbEXDmaAddr(BULK_CUSTOM_FIFO_IN, (uint32_t)g_BulkCustomBuffer);
	mUsbEXDmaStart(BULK_CUSTOM_FIFO_IN);
#endif
	return;
}


// Host to Device
void RecieveBulkCustomData(uint8_t* pData)
{
#ifndef MODE_I2C
	// Something !!!

	DMABulkData_USB();

	// Something !!!
#endif
	return;
}













//
// Common (Touch + Pen + Custom)
//
#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN
bool_t bReportDelayFlag = 0;
#endif
void QueueCommonData_USB(void)
{
#ifndef MODE_I2C
	uint8_t* pCheckID = NULL;

	if ((CheckUsbConfig() == 0) || (CheckHIDReady() == 0) || (g_CXF_Done != CXF_STATUS__COMPLETE_DONE))
	{
		goto QUEUECOMMONDATA_USB__GOTO_END;
	}
	
	if (g_RemoteWakeup == 1)
	{
		goto QUEUECOMMONDATA_USB__GOTO_END;
	}
	
#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN
	if(bReportDelayFlag == 0)
#endif
	{
		if (StaticQueue_CheckEmpty(&g_Queue_Common) == 0)
		{
			pCheckID = StaticQueue_Get(&g_Queue_Common);
			switch (pCheckID[0])
			{
				case HID_REPORT_ID__MULTI_TOUCH:
	#if USED_S3_WAKEUP_MOUSE_DEVICE
				case HID_REPORT_ID__MOUSE:
	#endif /* USED_S3_WAKEUP_MOUSE_DEVICE */
				{
	#ifdef ADD_TOUCH
					if ((g_CheckVDMAComplete_Touch == DMA_READY) && ((g_CXF_Done == CXF_STATUS__COMPLETE_DONE)))
					{
						// Pop
						if (StaticQueue_Pop(&g_Queue_Common, (uint8_t*)&g_Touch) == TRUE)
	                    {
	                        g_CheckVDMAComplete_Touch = DMA_NOT_READY;
	                        mUsbIntF1INEn(); // Touch IN
	                    }
					}
	#endif
					break;
				}

				case HID_REPORT_ID__PEN:
				case HID_REPORT_ID__PEN_SECOND:
				{
	#ifdef ADD_PEN
					if ((g_CheckVDMAComplete_Pen == DMA_READY) && ((g_CXF_Done == CXF_STATUS__COMPLETE_DONE)))
					{
						// Pop
						if (StaticQueue_Pop(&g_Queue_Common, (uint8_t*)&g_Pen) == TRUE)
	                    {
	                        g_CheckVDMAComplete_Pen = DMA_NOT_READY;
	                        mUsbIntF3INEn(); // Pen IN
	                    }
					}
	#endif

					break;
				}

				// Custom or Bulk
				case HID_REPORT_ID__CUSTOM_IN:
				default:
				{
	#ifdef ADD_CUSTOM
					if ((g_CheckVDMAComplete_Custom == DMA_READY) && ((g_CXF_Done == CXF_STATUS__COMPLETE_DONE)))
					{
						// Pop
						if (StaticQueue_Pop(&g_Queue_Common, (uint8_t*)&g_CustomBuffer) == TRUE)
	                    {
	                        g_CheckVDMAComplete_Custom = DMA_NOT_READY;
	                        mUsbIntF0INEn(); // Custom IN
	                    }
					}
	#endif

					break;
				}
			}
		}
	}
QUEUECOMMONDATA_USB__GOTO_END:

#endif
	return;
}












#ifndef MODE_I2C

//
// USB
//

void EP0_TxRx_Proc(uint8_t Dirction)
{
	uint16_t wLength = 0;

	if (g_EP0_Remain == 0)
	{
		if (g_pSetupPacket->wLength >= g_EP0_BufferLength)
		{
			wLength = (g_EP0_BufferLength >= MX_PA_SZ_64) ? MX_PA_SZ_64 : g_EP0_BufferLength;
		}
		else
		{
			wLength = g_pSetupPacket->wLength;
		}
	}
	else
	{
		if (g_EP0_Remain >= MX_PA_SZ_64)
		{
			wLength = MX_PA_SZ_64;
		}
		else
		{
			wLength = g_EP0_Remain;
		}
	}

	

	g_EP0_Offset += wLength;
	g_EP0_Remain = g_EP0_BufferLength - g_EP0_Offset;
	g_EP0_Check = 1;

	// Virtual DMA
	mUsbCXIntDmaErrEn();
	mUsbCXIntDmaFinishEn();

	mUsbCXDmaConfig(wLength, Dirction);
	mUsbCXDmaAddr((uint32_t)g_EP0_BufferAddr);
	mUsbCXDmaStart();
	return;
}


void EP0_SetupPacket_GetDescriptor(void)
{
	uint8_t	bStall = TRUE;

	switch ((g_pSetupPacket->wValue & 0xFF00) >> 8)
	{
		case SETUPPACKET_DESCRIPTOR__DEVICE:
		{
			g_EP0_BufferAddr = &u8_FS_DeviceDesc[0];
			g_EP0_BufferLength = DEVICE_DESC_LENGTH;

			// Tx
			EP0_TxRx_Proc(DIRECTION_IN);
			bStall = FALSE;
			break;
		}

		case SETUPPACKET_DESCRIPTOR__CONFIGURATION:
		{
			g_EP0_BufferAddr = &u8_FS_ConfigDesc[g_EP0_Offset];
			g_EP0_BufferLength = CONFIG_DESC_LENGTH;

			// Tx
			EP0_TxRx_Proc(DIRECTION_IN);
			bStall = FALSE;
			break;
		}

		case SETUPPACKET_DESCRIPTOR__STRING:
		{
			switch (g_pSetupPacket->wValue & 0x00FF)
			{
				// Lang IDs
				case 0:
				{
					g_EP0_BufferAddr = &u8O_StrDesc_LangIDs[g_EP0_Offset];
					g_EP0_BufferLength = STRING_LANG_IDS_LENGTH;

					// Tx
					EP0_TxRx_Proc(DIRECTION_IN);
					bStall = FALSE;
					break;
				}

				// Product String
				case DEVICE_PRODUCT:
				{
					g_EP0_BufferAddr = &u8O_StrDesc_Product[g_EP0_Offset];
					g_EP0_BufferLength = STRING_PRODUCT_LENGTH;

					// Tx
					EP0_TxRx_Proc(DIRECTION_IN);
					bStall = FALSE;
					break;
				}
				
				// Manufacturer
				case DEVICE_MANUFACTURER:
				{
					g_EP0_BufferAddr = &u8O_StrDesc_Manufacturer[g_EP0_Offset];
					g_EP0_BufferLength = STRING_MANUFACTURER_LENGTH;

					// Tx
					EP0_TxRx_Proc(DIRECTION_IN);
					bStall = FALSE;
					break;
				}

				// String Microsoft OS
				case SETUPPACKET_DESCRIPTOR__MS_OS:
				{
					if (g_pSetupPacket->wValue == SETUPPACKET_DESCRIPTOR__MS_OS_2)
					{
#ifdef USB_SELECTIVE_SUSPEND
						uint8_t* pBuffer = (uint8_t*)&MS_OS_Descriptor;

						MS_OS_Descriptor.Length = sizeof(MS_OS_STRING_DESCRIPTOR);
						MS_OS_Descriptor.Type = SETUPPACKET_DESCRIPTOR__STRING;
						MS_OS_Descriptor.Signature[0] = 'M';
						MS_OS_Descriptor.Signature[2] = 'S';
						MS_OS_Descriptor.Signature[4] = 'F';
						MS_OS_Descriptor.Signature[6] = 'T';
						MS_OS_Descriptor.Signature[8] = '1';
						MS_OS_Descriptor.Signature[10] = '0';
						MS_OS_Descriptor.Signature[12] = '0';
						MS_OS_Descriptor.MSVendorCode = SETUPPACKET_DESCRIPTOR__MS_OS_VENDOR_CODE;
						MS_OS_Descriptor.Pad = 0x00;

						g_EP0_BufferAddr = (uint8_t*)&pBuffer[g_EP0_Offset];
						g_EP0_BufferLength = sizeof(MS_OS_STRING_DESCRIPTOR);
						
						// Tx
						EP0_TxRx_Proc(DIRECTION_IN);
						bStall = FALSE;
#endif
					}

					break;
				}
			}

			break;
		}

		case SETUPPACKET_DESCRIPTOR__HID:
		{
			uint8_t	i = 0;
			uint8_t*	pBuffer = (uint8_t*)&g_HID_Descriptor;

			g_HID_Descriptor.bLength = HID_DESCRIPTOR_LENGTH;
			g_HID_Descriptor.bDescriptorType = SETUPPACKET_DESCRIPTOR__HID;
			g_HID_Descriptor.bcdHID = HID_VERSION;
			g_HID_Descriptor.bCountryCode = 0;
			g_HID_Descriptor.bNumDescriptors = 1;
			g_HID_Descriptor.bDescriptorType_Class = SETUPPACKET_DESCRIPTOR__REPORT;
	
			switch (g_pSetupPacket->wIndex)
			{
#ifdef ADD_TOUCH
				// Multi-Touch
				case TOUCH_INTERFACE_NUM:
				{
					g_HID_Descriptor.wDescriptorLength = HID_MULTITOUCH_DESC_HEAD_LENGTH;
					for (i = 0; i < HID_MAX_TOUCH; i++)
					{
						g_HID_Descriptor.wDescriptorLength += HID_MULTITOUCH_DESC_MAIN_LENGTH;
					}

					g_HID_Descriptor.wDescriptorLength += HID_MULTITOUCH_DESC_TAIL_LENGTH;
					break;
				}
#endif

#ifdef ADD_CUSTOM
				// Custom
				case CUSTOM_INTERFACE_NUM:
				{
					g_HID_Descriptor.wDescriptorLength = HID_CUSTOM_DESC_LENGTH;
					break;
				}
#endif

#ifdef ADD_PEN
				// Pen
				case PEN_INTERFACE_NUM:
				{
					g_HID_Descriptor.wDescriptorLength = HID_PEN_DESC_LENGTH;
					break;
				}
#endif
			}

			g_EP0_BufferAddr = (uint8_t*)&pBuffer[g_EP0_Offset];
			g_EP0_BufferLength = HID_DESCRIPTOR_LENGTH;

			// Tx
			EP0_TxRx_Proc(DIRECTION_IN);
			bStall = FALSE;
			break;
		}

		case SETUPPACKET_DESCRIPTOR__REPORT:
		{
			switch (g_pSetupPacket->wIndex)
			{
#ifdef ADD_TOUCH
				// Multi-Touch
				case TOUCH_INTERFACE_NUM:
				{
					uint8_t	i = 0;
					uint16_t	Offset = 0;

					// Head
					memcpy(&u8_HID_MultiTouchReportDesc_Temp[Offset], u8_HID_MultiTouch_Descriptor_Head, HID_MULTITOUCH_DESC_HEAD_LENGTH);
					Offset += HID_MULTITOUCH_DESC_HEAD_LENGTH;

					// Main
					for (i = 0; i < HID_MAX_TOUCH; i++)
					{
						memcpy(&u8_HID_MultiTouchReportDesc_Temp[Offset], u8_HID_MultiTouch_Descriptor_Main, HID_MULTITOUCH_DESC_MAIN_LENGTH);
						Offset += HID_MULTITOUCH_DESC_MAIN_LENGTH;
					}

					// Tail
					memcpy(&u8_HID_MultiTouchReportDesc_Temp[Offset], u8_HID_MultiTouch_Descriptor_Tail, HID_MULTITOUCH_DESC_TAIL_LENGTH);
					Offset += HID_MULTITOUCH_DESC_TAIL_LENGTH;
					

					g_EP0_BufferAddr = &u8_HID_MultiTouchReportDesc_Temp[g_EP0_Offset];
					g_EP0_BufferLength = Offset;
					break;
				}
#endif

#ifdef ADD_CUSTOM
				// Custom
				case CUSTOM_INTERFACE_NUM:
				{
					g_EP0_BufferAddr = &u8_HID_Custom_Descriptor[g_EP0_Offset];
					g_EP0_BufferLength = HID_CUSTOM_DESC_LENGTH;
					break;
				}
#endif

#ifdef ADD_PEN
				// Pen
				case PEN_INTERFACE_NUM:
				{
					g_EP0_BufferAddr = &u8_HID_Pen_Descriptor[g_EP0_Offset];
					g_EP0_BufferLength = HID_PEN_DESC_LENGTH;
					break;
				}
#endif
			}

			// Tx
			EP0_TxRx_Proc(DIRECTION_IN);
			bStall = FALSE;
			break;
		}

#ifdef USB_SELECTIVE_SUSPEND
		case SETUPPACKET_DESCRIPTOR__BOS:
		{
			uint8_t*	pBuffer = (uint8_t*)&BOS_Descriptor;

			BOS_Descriptor.Length = 5;
			BOS_Descriptor.Type = SETUPPACKET_DESCRIPTOR__BOS;
			BOS_Descriptor.TotalLength = sizeof(BOS_DESCRIPTOR);
			BOS_Descriptor.NumCapability = 1;
			BOS_Descriptor.Usb20ExtDesc.Length = sizeof(USB20_EXT_DESCRIPTOR);
			BOS_Descriptor.Usb20ExtDesc.Type = 0x10;
			BOS_Descriptor.Usb20ExtDesc.DevCapabilityType = 0x02;
			BOS_Descriptor.Usb20ExtDesc.bmAttributes_LPM_Support = 1;
			BOS_Descriptor.Usb20ExtDesc.bmAttributes_BESL_Support = 1;
			BOS_Descriptor.Usb20ExtDesc.bmAttributes_BaseLineBESL = 1;
			BOS_Descriptor.Usb20ExtDesc.bmAttributes_DeepBESL = 1;
			BOS_Descriptor.Usb20ExtDesc.bmAttributes_BESL = 10;
			BOS_Descriptor.Usb20ExtDesc.bmAttributes_DBESL = 11;

			g_EP0_BufferAddr = (uint8_t*)&pBuffer[g_EP0_Offset];
			g_EP0_BufferLength = sizeof(BOS_DESCRIPTOR);
			EP0_TxRx_Proc(DIRECTION_IN);
			bStall = FALSE;
			break;
		}
#endif
	}


	if (bStall == TRUE)
	{
		mUsbEP0StallSet();
		mUsbEP0DoneSet();
		g_CXF_Done = CXF_STATUS__COMPLETE_DONE;
	}

	return;
}


void EP0_SetupPacket(void)
{
	uint8_t	bStall = TRUE;

	if (mUsbOTGHighSpeedST())
	{
		return;
	}

	// Device to Host
	switch (g_pSetupPacket->bmRequestType_Type)
	{
		case SETUPPACKET_REQUEST_TYPE__STANDARD:
		{
			// Standard
			switch (g_pSetupPacket->bRequest)
			{
				case SETUPPACKET_STANDARD_REQUEST__GET_STATUS:
				{					
					g_EP0_BufferAddr = (uint8_t*)&g_Status[g_pSetupPacket->wIndex];
					g_EP0_BufferLength = sizeof(SETUP_GET_STATUS);

					// Tx
					EP0_TxRx_Proc(DIRECTION_IN);
					bStall = FALSE;
					break;
				}

				case SETUPPACKET_STANDARD_REQUEST__CLEAR_FEATURE:
				{
					switch (g_pSetupPacket->wValue & 0x00FF)
					{
						case SETUPPACKET_FEATURE__ENDPOINT_HALT:
						{
							g_Status[g_pSetupPacket->wIndex].Status.EP.EndPointHalt = 0;
							break;
						}

						case SETUPPACKET_FEATURE__DEVICE_REMOTE_WAKEUP:
						{
							/*
							 * When the MCU receives the clear-suspend Command from Host, The MCU Status becomes Resume!!
							 * At this time, The MCU is able to position report.
							 */
							// Clear Suspend
							mUsbClearSuspend();
							
							g_Status[g_pSetupPacket->wIndex].Status.Global.RemoteWakeup = 0;
							g_StartTime_Recovery_ClearSus = g_ScanTime_Recovery_ClearSus = 0; 
							ResumeCnt=0;
							Recovery_ClearSus_Flag = 0;
							break;
						}
					}

					mUsbEP0DoneSet();
					g_CXF_Done = CXF_STATUS__COMPLETE_DONE;
					bStall = FALSE;
					break;
				}

				case SETUPPACKET_STANDARD_REQUEST__SET_FEATURE:
				{
					
					switch (g_pSetupPacket->wValue & 0x00FF)
					{
						case SETUPPACKET_FEATURE__ENDPOINT_HALT:
						{
							g_Status[g_pSetupPacket->wIndex].Status.EP.EndPointHalt = 1;

							if (g_pSetupPacket->wIndex & 0x0080)
							{
								mUsbEPinRsTgClr(g_pSetupPacket->wIndex & 0x000F);
							}
							else
							{
								mUsbEPoutRsTgClr(g_pSetupPacket->wIndex & 0x000F);
							}

							mUsbEP0DoneSet();
							g_CXF_Done = CXF_STATUS__COMPLETE_DONE;
							bStall = FALSE;
							break;
						}

						case SETUPPACKET_FEATURE__DEVICE_REMOTE_WAKEUP:
						{
							mUsbEP0DoneSet();
							
							// Suspend
							mUsbGoSuspend();
							
							g_CXF_Done = CXF_STATUS__COMPLETE_DONE;
							g_RemoteWakeup = 1;
							g_SuspendOn = 1;
							g_Status[g_pSetupPacket->wIndex].Status.Global.RemoteWakeup = 1;
							bStall = FALSE;
							break;
						}
					}
					
					
					break;
				}

				case SETUPPACKET_STANDARD_REQUEST__SET_ADDRESS:
				{
					mUsbDevAddrSet(g_pSetupPacket->wValue);
					mUsbEP0DoneSet();
					g_CXF_Done = CXF_STATUS__COMPLETE_DONE;
					bStall = FALSE;
					break;
				}

				case SETUPPACKET_STANDARD_REQUEST__GET_DESCRIPTOR:
				{
					EP0_SetupPacket_GetDescriptor();
					bStall = FALSE;
					break;
				}

				case SETUPPACKET_STANDARD_REQUEST__SET_DESCRIPTOR:
				{
					break;
				}

				case SETUPPACKET_STANDARD_REQUEST__GET_CONFIGURATION:
				{
					g_EP0_BufferAddr = &g_Configuration;
					g_EP0_BufferLength = 1;

					// Tx
					EP0_TxRx_Proc(DIRECTION_IN);
					bStall = FALSE;
					break;
				}

				case SETUPPACKET_STANDARD_REQUEST__SET_CONFIGURATION:
				{
					// EP FIFO
					mUsbEPMap(EP2, TOUCH_FIFO_IN);				// MultiTouch IN
					mUsbEPMap(EP3, CUSTOM_FIFO_OUT << 4);		// Custom OUT 
					mUsbEPMap(EP4, CUSTOM_FIFO_IN);				// Custom IN
					mUsbEPMap(EP6, PEN_FIFO_IN);				// Pen IN
					//mUsbEPMap(EP7, BULK_CUSTOM_FIFO_OUT << 4);	// Bulk Custom OUT 
					//mUsbEPMap(EP8, BULK_CUSTOM_FIFO_IN);		// Bulk Custom IN

					// FIFO
					mUsbFIFOMap(TOUCH_FIFO_IN, EP2 | (FIFO_CONFIG_DIRECTION__IN << 4));
					mUsbFIFOMap(CUSTOM_FIFO_OUT, EP3 | (FIFO_CONFIG_DIRECTION__OUT << 4));
					mUsbFIFOMap(CUSTOM_FIFO_IN, EP4 | (FIFO_CONFIG_DIRECTION__IN << 4));
					mUsbFIFOMap(PEN_FIFO_IN, EP6 | (FIFO_CONFIG_DIRECTION__IN << 4));
					//mUsbFIFOMap(BULK_CUSTOM_FIFO_OUT, EP7 | (FIFO_CONFIG_DIRECTION__OUT << 4));
					//mUsbFIFOMap(BULK_CUSTOM_FIFO_IN, EP8 | (FIFO_CONFIG_DIRECTION__IN << 4));

					// Max Packet Size
					mUsbEPMxPtSz(EP2, DIRECTION_IN, MX_PA_SZ_64);
					mUsbEPMxPtSz(EP3, DIRECTION_OUT, MX_PA_SZ_64);
					mUsbEPMxPtSz(EP4, DIRECTION_IN, MX_PA_SZ_64);
					mUsbEPMxPtSz(EP6, DIRECTION_IN, MX_PA_SZ_64);
					//mUsbEPMxPtSz(EP7, DIRECTION_OUT, MX_PA_SZ_64);
					//mUsbEPMxPtSz(EP8, DIRECTION_IN, MX_PA_SZ_64);

					// FIFO Config
					mUsbFIFOConfig(TOUCH_FIFO_IN, FIFO_CONFIG_TYPE__INT | (FIFO_CONFIG_BLOCK_NBUMBER__SINGLE << 2) | (FIFO_CONFIG_BLOCK_SIZE__512 << 4) | (FIFO_CONFIG__ENABLE << 5));
					mUsbFIFOConfig(CUSTOM_FIFO_OUT, FIFO_CONFIG_TYPE__INT | (FIFO_CONFIG_BLOCK_NBUMBER__SINGLE << 2) | (FIFO_CONFIG_BLOCK_SIZE__512 << 4) | (FIFO_CONFIG__ENABLE << 5));
					mUsbFIFOConfig(CUSTOM_FIFO_IN, FIFO_CONFIG_TYPE__INT | (FIFO_CONFIG_BLOCK_NBUMBER__SINGLE << 2) | (FIFO_CONFIG_BLOCK_SIZE__512 << 4) | (FIFO_CONFIG__ENABLE << 5));
					mUsbFIFOConfig(PEN_FIFO_IN, FIFO_CONFIG_TYPE__INT | (FIFO_CONFIG_BLOCK_NBUMBER__SINGLE << 2) | (FIFO_CONFIG_BLOCK_SIZE__512 << 4) | (FIFO_CONFIG__ENABLE << 5));
					//mUsbFIFOConfig(BULK_CUSTOM_FIFO_OUT, FIFO_CONFIG_TYPE__BULK | (FIFO_CONFIG_BLOCK_NBUMBER__SINGLE << 2) | (FIFO_CONFIG_BLOCK_SIZE__512 << 4) | (FIFO_CONFIG__ENABLE << 5));
					//mUsbFIFOConfig(BULK_CUSTOM_FIFO_IN, FIFO_CONFIG_TYPE__BULK | (FIFO_CONFIG_BLOCK_NBUMBER__SINGLE << 2) | (FIFO_CONFIG_BLOCK_SIZE__512 << 4) | (FIFO_CONFIG__ENABLE << 5));

					// Custom OUT
					RecieveCustomData_DMA();

					// Bulk Custom OUT
					RecieveBulkCustomData_DMA();

					// Toggle
					mUsbEPinRsTgClr(EP2);
					mUsbEPoutRsTgClr(EP3);
					mUsbEPinRsTgClr(EP4);
					mUsbEPinRsTgClr(EP6);
					//mUsbEPoutRsTgClr(EP7);
					//mUsbEPinRsTgClr(EP8);

					// SOF
					mUsbSOFMaskFS();

					// Done !!
					mUsbEP0DoneSet();

					// After Set Configuration
					mUsbCfgSet();

					g_CXF_Done = CXF_STATUS__COMPLETE_DONE;
					g_Configuration = (uint8_t)(g_pSetupPacket->wValue & 0x00FF);
					g_HIDReady = 1;
					bStall = FALSE;
					break;
				}

				case SETUPPACKET_STANDARD_REQUEST__GET_INTERFACE:
				{
					uint8_t AlterInterface = 0;

					g_EP0_BufferAddr = &AlterInterface;
					g_EP0_BufferLength = 1;

					// Tx
					EP0_TxRx_Proc(DIRECTION_IN);
					bStall = FALSE;
					break;
				}

				case SETUPPACKET_STANDARD_REQUEST__SET_INFERFACE:
				{
					switch (g_pSetupPacket->wIndex)
					{
						// MultiTouch
						case TOUCH_INTERFACE_NUM:
						{
							mUsbEPinRsTgClr(EP2);
							break;
						}

						// Custom
						case CUSTOM_INTERFACE_NUM:
						{
							mUsbEPoutRsTgClr(EP3);
							mUsbEPinRsTgClr(EP4);
							break;
						}

						// Pen
						case PEN_INTERFACE_NUM:
						{
							mUsbEPinRsTgClr(EP6);
							break;
						}
					}

					mUsbEP0DoneSet();
					g_CXF_Done = CXF_STATUS__COMPLETE_DONE;
					bStall = FALSE;
					break;
				}

				case SETUPPACKET_STANDARD_REQUEST__SYNCH_FRAME:
				{
					break;
				}

				default:
				{
					break;
				}
			}

			break;
		}

		case SETUPPACKET_REQUEST_TYPE__CLASS:
		{
			switch (g_pSetupPacket->bRequest)
			{
				// Get Report
				case SETUPPACKET_CLASS_REQUEST__GET_REPORT:
				{
					// Feature
					if ((g_pSetupPacket->wValue & 0xFF00) == 0x0300)
					{
						switch (g_pSetupPacket->wValue & 0x00FF)
						{
#ifdef ADD_TOUCH
							// Contact count Mamimum
							case HID_REPORT_ID__CONTACT_COUNT:
							{
								g_MaxTouchCount.ReportID = HID_REPORT_ID__CONTACT_COUNT;
								g_MaxTouchCount.Count = HID_MAX_TOUCH;
								//g_MaxTouchCount.Reserved = 0;

								g_EP0_BufferAddr = (uint8_t*)&g_MaxTouchCount;
								g_EP0_BufferLength = sizeof(TOUCH_MAX_COUNT);

								// Tx
								EP0_TxRx_Proc(DIRECTION_IN);
								bStall = FALSE;
								break;
							}

							case HID_REPORT_ID__BLOB_CODE:
							{
								g_EP0_BufferAddr = &u8_HID_Touch_Blob[g_EP0_Offset];
								g_EP0_BufferLength = HID_TOUCH_BLOB_LENGTH;

								// Tx
								EP0_TxRx_Proc(DIRECTION_IN);
								bStall = FALSE;
								break;
							}
#endif
						}
					}
					break;
				}

				// Set Report
				case SETUPPACKET_CLASS_REQUEST__SET_REPORT:
				{
					// Feature
					if ((g_pSetupPacket->wValue & 0xFF00) == 0x0300)
					{
#ifdef ADD_TOUCH
						// Device Mode
						if ((g_pSetupPacket->wValue & 0x00FF) == HID_REPORT_ID__DEVICE_MODE)
						{
							g_EP0_BufferAddr = (uint8_t*)&g_DeviceMode;
							g_EP0_BufferLength = g_pSetupPacket->wLength;

							// Rx
							EP0_TxRx_Proc(DIRECTION_OUT);
							bStall = FALSE;
						}
#endif

						// Latency Mode
						if ((g_pSetupPacket->wValue & 0x00FF) == HID_REPORT_ID__LATENCY_MODE)
						{
							g_EP0_BufferAddr = (uint8_t*)&g_LatencyMode;
							g_EP0_BufferLength = g_pSetupPacket->wLength;

							// Rx
							EP0_TxRx_Proc(DIRECTION_OUT);
							bStall = FALSE;
						}
					}

					break;
				}

				// Set Idle
				case SETUPPACKET_CLASS_REQUEST__SET_IDLE:
				{
					uint8_t	ReportID = 0;
					uint8_t	Duration = 0;

					ReportID = (uint8_t)(g_pSetupPacket->wValue & 0x00FF);
					Duration = (uint8_t)((g_pSetupPacket->wValue & 0xFF00) >> 8);

					// All
					if (ReportID == 0)
					{
						mUsbEP0StallSet();
						mUsbEP0DoneSet();
						g_CXF_Done = CXF_STATUS__COMPLETE_DONE;
						bStall = FALSE;
					}
					// Other Report
					else
					{
						g_IdleDuration[ReportID] = Duration;
						mUsbEP0DoneSet();
						g_CXF_Done = CXF_STATUS__COMPLETE_DONE;
						bStall = FALSE;
					}

					break;
				}

				// Get Idle
				case SETUPPACKET_CLASS_REQUEST__GET_IDLE:
				{
					uint8_t	ReportID = 0;

					ReportID = (uint8_t)(g_pSetupPacket->wValue & 0x00FF);

					g_EP0_BufferAddr = (uint8_t*)&g_IdleDuration[ReportID];
					g_EP0_BufferLength = 1;

					// Rx
					EP0_TxRx_Proc(DIRECTION_IN);
					bStall = FALSE;
					break;
				}
			}

			break;
		}

		case SETUPPACKET_REQUEST_TYPE__VENDOR:
		{
			switch (g_pSetupPacket->bRequest)
			{
				// MS OS Descriptor
				case SETUPPACKET_DESCRIPTOR__MS_OS_VENDOR_CODE:
				{
					switch (g_pSetupPacket->wIndex)
					{

						case MS_OS_DESCRIPTOR_TYPE__COMPATIBLE_ID:
						{
#ifdef ADD_BULK_CUSTOM
							MS_OS_CompatibleID.Length = sizeof(COMPATIBLE_ID_FEATURE_DESCRIPTOR);
							MS_OS_CompatibleID.bcdVersion = 0x0100;
							MS_OS_CompatibleID.Index = MS_OS_DESCRIPTOR_TYPE__COMPATIBLE_ID;
							MS_OS_CompatibleID.Count = 0x01;
							MS_OS_CompatibleID.FirstInterfaceNumber = BULK_CUSTOM_INTERFACE_NUM;

							// WINUSB
							MS_OS_CompatibleID.CompatibleID[0] = 'W';
							MS_OS_CompatibleID.CompatibleID[1] = 'I';
							MS_OS_CompatibleID.CompatibleID[2] = 'N';
							MS_OS_CompatibleID.CompatibleID[3] = 'U';
							MS_OS_CompatibleID.CompatibleID[4] = 'S';
							MS_OS_CompatibleID.CompatibleID[5] = 'B';
							MS_OS_CompatibleID.CompatibleID[6] = 0;
							MS_OS_CompatibleID.CompatibleID[7] = 0;

							g_EP0_BufferAddr = (uint8_t*)&MS_OS_CompatibleID;
							g_EP0_BufferLength = sizeof(COMPATIBLE_ID_FEATURE_DESCRIPTOR);

							// Rx
							EP0_TxRx_Proc(DIRECTION_IN);
							bStall = FALSE;
#endif
							break;
						}

						case MS_OS_DESCRIPTOR_TYPE__PROPERTIES:
						{
#ifdef USB_SELECTIVE_SUSPEND
							uint32_t	i = 0;
							uint8_t*	pString = 0;
							uint8_t*	pBuffer = (uint8_t*)&MS_OS_Property;

							MS_OS_Property.Header.Length = sizeof(PROPERTIES_DESCRIPTOR_HEADER);
							MS_OS_Property.Header.bcdVersion = 0x0100;
							MS_OS_Property.Header.Index = MS_OS_DESCRIPTOR_TYPE__PROPERTIES;
							MS_OS_Property.Header.Count = 0;
							
							// SelectiveSuspend
							pString = SELECTIVE_SUSPEND_STRING;
							MS_OS_Property.SelectiveSuspend.Size = sizeof(PROPERTY_SECTION__SELECTIVE_SUSPEND);
							MS_OS_Property.SelectiveSuspend.PropertyDataType = REG_DWORD;
							MS_OS_Property.SelectiveSuspend.PropertyNameLength = 48;
							for (i = 0; i < (MS_OS_Property.SelectiveSuspend.PropertyNameLength/2); i++)
							{
								MS_OS_Property.SelectiveSuspend.PropertyName[i*2] = pString[i];
							}
							MS_OS_Property.SelectiveSuspend.PropertyDataLength = 0x04;
							MS_OS_Property.SelectiveSuspend.PropertyData = 0x01;
							MS_OS_Property.Header.Count += 1;
							MS_OS_Property.Header.Length += sizeof(PROPERTY_SECTION__SELECTIVE_SUSPEND);

#ifdef ADD_BULK_CUSTOM
#ifdef MS_OS_EXT_PROP__WINUSB
							if (InterfaceNumber == BULK_CUSTOM_INTERFACE_NUM)
							{
								// DeviceInterfaceGUID
								MS_OS_Property.DeviceInterfaceGUID.Size = sizeof(PROPERTY_SECTION__DEVICEINTERFACEGUID);
								MS_OS_Property.DeviceInterfaceGUID.PropertyDataType = REG_SZ;
								pString = DEVICEINTERFACEGUID_NAME;
								MS_OS_Property.DeviceInterfaceGUID.PropertyNameLength = 40;
								for (i = 0; i < (MS_OS_Property.DeviceInterfaceGUID.PropertyNameLength / 2); i++)
								{
									MS_OS_Property.DeviceInterfaceGUID.PropertyName[i * 2] = pString[i];
								}
								pString = DEVICEINTERFACEGUID_STRING;
								MS_OS_Property.DeviceInterfaceGUID.PropertyDataLength = 78;
								for (i = 0; i < (MS_OS_Property.DeviceInterfaceGUID.PropertyDataLength / 2); i++)
								{
									MS_OS_Property.DeviceInterfaceGUID.PropertyData[i * 2] = pString[i];
								}
								MS_OS_Property.Header.Count += 1;
								MS_OS_Property.Header.Length += sizeof(PROPERTY_SECTION__DEVICEINTERFACEGUID);


								// DeviceIdleEnabled
								pString = DEVICEIDLEENABLED_NAME;
								MS_OS_Property.DeviceIdleEnabled.Size = sizeof(PROPERTY_SECTION__DEVICEIDLEENABLED);
								MS_OS_Property.DeviceIdleEnabled.PropertyDataType = REG_DWORD;
								MS_OS_Property.DeviceIdleEnabled.PropertyNameLength = 36;
								for (i = 0; i < (MS_OS_Property.DeviceIdleEnabled.PropertyNameLength / 2); i++)
								{
									MS_OS_Property.DeviceIdleEnabled.PropertyName[i * 2] = pString[i];
								}
								MS_OS_Property.DeviceIdleEnabled.PropertyDataLength = 0x04;
								MS_OS_Property.DeviceIdleEnabled.PropertyData = 0x01;
								MS_OS_Property.Header.Count += 1;
								MS_OS_Property.Header.Length += sizeof(PROPERTY_SECTION__DEVICEIDLEENABLED);


								// DefaultIdleState
								pString = DEFAULTIDLESTATE_NAME;
								MS_OS_Property.DefaultIdleState.Size = sizeof(PROPERTY_SECTION__DEFAULTIDLESTATE);
								MS_OS_Property.DefaultIdleState.PropertyDataType = REG_DWORD;
								MS_OS_Property.DefaultIdleState.PropertyNameLength = 34;
								for (i = 0; i < (MS_OS_Property.DefaultIdleState.PropertyNameLength / 2); i++)
								{
									MS_OS_Property.DefaultIdleState.PropertyName[i * 2] = pString[i];
								}
								MS_OS_Property.DefaultIdleState.PropertyDataLength = 0x04;
								MS_OS_Property.DefaultIdleState.PropertyData = 0x01;
								MS_OS_Property.Header.Count += 1;
								MS_OS_Property.Header.Length += sizeof(PROPERTY_SECTION__DEFAULTIDLESTATE);


								// DefaultIdleTimeout
								pString = DEFAULTIDLETIMEOUT_NAME;
								MS_OS_Property.DefaultIdleTimeout.Size = sizeof(PROPERTY_SECTION__DEFAULTIDLETIMEOUT);
								MS_OS_Property.DefaultIdleTimeout.PropertyDataType = REG_DWORD;
								MS_OS_Property.DefaultIdleTimeout.PropertyNameLength = 38;
								for (i = 0; i < (MS_OS_Property.DefaultIdleTimeout.PropertyNameLength / 2); i++)
								{
									MS_OS_Property.DefaultIdleTimeout.PropertyName[i * 2] = pString[i];
								}
								MS_OS_Property.DefaultIdleTimeout.PropertyDataLength = 0x04;
								MS_OS_Property.DefaultIdleTimeout.PropertyData = 0x00001388; // 5000 ms
								MS_OS_Property.Header.Count += 1;
								MS_OS_Property.Header.Length += sizeof(PROPERTY_SECTION__DEFAULTIDLETIMEOUT);


								// UserSetDeviceIdleEnabled
								pString = USERSETDEVICEIDLEENABLED_NAME;
								MS_OS_Property.UserSetDeviceIdleEnabled.Size = sizeof(PROPERTY_SECTION__USERSETDEVICEIDLEENABLED);
								MS_OS_Property.UserSetDeviceIdleEnabled.PropertyDataType = REG_DWORD;
								MS_OS_Property.UserSetDeviceIdleEnabled.PropertyNameLength = 50;
								for (i = 0; i < (MS_OS_Property.UserSetDeviceIdleEnabled.PropertyNameLength / 2); i++)
								{
									MS_OS_Property.UserSetDeviceIdleEnabled.PropertyName[i * 2] = pString[i];
								}
								MS_OS_Property.UserSetDeviceIdleEnabled.PropertyDataLength = 0x04;
								MS_OS_Property.UserSetDeviceIdleEnabled.PropertyData = 0x01;
								MS_OS_Property.Header.Count += 1;
								MS_OS_Property.Header.Length += sizeof(PROPERTY_SECTION__USERSETDEVICEIDLEENABLED);


								// SystemWakeEnabled
								pString = SYSTEMWAKEENABLED_NAME;
								MS_OS_Property.SystemWakeEnabled.Size = sizeof(PROPERTY_SECTION__SYSTEMWAKEENABLED);
								MS_OS_Property.SystemWakeEnabled.PropertyDataType = REG_DWORD;
								MS_OS_Property.SystemWakeEnabled.PropertyNameLength = 36;
								for (i = 0; i < (MS_OS_Property.SystemWakeEnabled.PropertyNameLength / 2); i++)
								{
									MS_OS_Property.SystemWakeEnabled.PropertyName[i * 2] = pString[i];
								}
								MS_OS_Property.SystemWakeEnabled.PropertyDataLength = 0x04;
								MS_OS_Property.SystemWakeEnabled.PropertyData = 0x01;
								MS_OS_Property.Header.Count += 1;
								MS_OS_Property.Header.Length += sizeof(PROPERTY_SECTION__SYSTEMWAKEENABLED);
							}
#endif
#endif
							
#ifdef MS_OS_EXT_PROP__ICON
							// DeviceIcon
							pString = DEVICE_ICON_STRING;
							MS_OS_Property.DeviceIcon.Size = sizeof(PROPERTY_SECTION__DEVICE_ICON);
							MS_OS_Property.DeviceIcon.PropertyDataType = REG_MULTI_SZ;
							MS_OS_Property.DeviceIcon.PropertyNameLength = 12;
							MS_OS_Property.DeviceIcon.PropertyName[0] = 'I';
							MS_OS_Property.DeviceIcon.PropertyName[2] = 'c';
							MS_OS_Property.DeviceIcon.PropertyName[4] = 'o';
							MS_OS_Property.DeviceIcon.PropertyName[6] = 'n';
							MS_OS_Property.DeviceIcon.PropertyName[8] = 's';
							MS_OS_Property.DeviceIcon.PropertyDataLength = 78;
							for (i = 0; i < (MS_OS_Property.DeviceIcon.PropertyDataLength/2); i++)
							{
								MS_OS_Property.DeviceIcon.PropertyData[i*2] = pString[i];
							}
							MS_OS_Property.Header.Count += 1;
							MS_OS_Property.Header.Length += sizeof(PROPERTY_SECTION__DEVICE_ICON);
#endif
							
#ifdef MS_OS_EXT_PROP__LABEL
							// DeviceLabel
							pString = DEVICE_LABEL_STRING;
							MS_OS_Property.DeviceLabel.Size = sizeof(PROPERTY_SECTION__DEVICE_LABEL);
							MS_OS_Property.DeviceLabel.PropertyDataType = REG_SZ;
							MS_OS_Property.DeviceLabel.PropertyNameLength = 12;
							MS_OS_Property.DeviceLabel.PropertyName[0] = 'L';
							MS_OS_Property.DeviceLabel.PropertyName[2] = 'a';
							MS_OS_Property.DeviceLabel.PropertyName[4] = 'b';
							MS_OS_Property.DeviceLabel.PropertyName[6] = 'e';
							MS_OS_Property.DeviceLabel.PropertyName[8] = 'l';
							MS_OS_Property.DeviceLabel.PropertyDataLength = 26;
							for (i = 0; i < (MS_OS_Property.DeviceLabel.PropertyDataLength/2); i++)
							{
								MS_OS_Property.DeviceLabel.PropertyData[i*2] = pString[i];
							}
							MS_OS_Property.Header.Count += 1;
							MS_OS_Property.Header.Length += sizeof(PROPERTY_SECTION__DEVICE_LABEL);
#endif
							
							
							
							g_EP0_BufferAddr = (uint8_t*)&pBuffer[g_EP0_Offset];
							g_EP0_BufferLength = MS_OS_Property.Header.Length;

							// Rx
							EP0_TxRx_Proc(DIRECTION_IN);
							bStall = FALSE;
#endif
							break;
						}

					}

					break;
				}
			}
			break;
		}
	}


	if (bStall == TRUE)
	{
		mUsbEP0StallSet();
		mUsbEP0DoneSet();
		g_CXF_Done = CXF_STATUS__COMPLETE_DONE;
	}

	return;
}







//
// USB - ISR
//

void USB_ResetResume(void)
{
	// DMA
	mUsbVDMADisable();
	mUsbVDMAEnable();

#ifdef ADD_TOUCH
	mUsbEXDmaAbort(TOUCH_FIFO_IN);
	mUsbEXDmaStop(TOUCH_FIFO_IN);

	//g_ScanTime = 0;
	//g_StartTime = 0;
	g_CheckVDMAComplete_Touch = DMA_READY;
	mUsbIntF1INDis();
#endif

#ifdef ADD_PEN
	mUsbEXDmaAbort(PEN_FIFO_IN);
	mUsbEXDmaStop(PEN_FIFO_IN);

	//g_ScanTime_Pen = 0;
	//g_StartTime_Pen = 0;
	g_CheckVDMAComplete_Pen = DMA_READY;
	mUsbIntF3INDis();
#endif

#ifdef ADD_CUSTOM
	// Custom IN
	mUsbEXDmaAbort(CUSTOM_FIFO_IN);
	mUsbEXDmaStop(CUSTOM_FIFO_IN);

	g_CheckVDMAComplete_Custom = DMA_READY;
	mUsbIntF0INDis();

	// Custom OUT
	RecieveCustomData_DMA();
#endif

#ifdef ADD_BULK_CUSTOM
	// Bulk Custom IN
	mUsbEXDmaAbort(BULK_CUSTOM_FIFO_IN);
	mUsbEXDmaStop(BULK_CUSTOM_FIFO_IN);

	g_CheckVDMAComplete_BulkCustom = DMA_READY;
	mUsbIntF0INDis();

	// Bulk Custom OUT
	RecieveBulkCustomData_DMA();
#endif

	return;
}



void SetupPacket_AfterCheck(PSETUP_PACKET pSetupPacket)
{
	switch (g_pSetupPacket->bRequest)
	{
		// Get Report
		case SETUPPACKET_CLASS_REQUEST__GET_REPORT:
		{
			// Feature
			if ((g_pSetupPacket->wValue & 0xFF00) == 0x0300)
			{
				switch (g_pSetupPacket->wValue & 0x00FF)
				{
					case HID_REPORT_ID__CONTACT_COUNT:
					{
						g_HIDReady = 1;
						break;
					}
				}
			}

			break;
		}
	}

	return;
}
#endif


void USB_InterruptHandler(void)
{
//	SCRB->USB_INTR_CLR.ulBulk = 0x7; // USB CM3 Internal Interrupt clear!!

#ifndef MODE_I2C
	g_IntGroup = mUsbIntGroupRegRd();	// 0x140
	// EP0
	if (g_IntGroup & BIT0)
	{
		g_IntEP0 = mUsbIntSrc0Rd(); // 0x144

		if (g_IntEP0 & BIT0)
		{
			//if ((g_CheckVDMAComplete_Touch == DMA_READY) && (g_CheckVDMAComplete_Custom == DMA_READY) && (g_CheckVDMAComplete_Pen == DMA_READY))
			if ((g_CXF_Done == CXF_STATUS__NORMAL) || (g_CXF_Done == CXF_STATUS__COMPLETE_DONE))
			{
				g_CXF_Done = CXF_STATUS__DOING;

				mUsbCXIntDmaErrEn();
				mUsbCXIntDmaFinishEn();

				mUsbCXDmaConfig(8, DIRECTION_OUT); // Memory To FIFO
				mUsbCXDmaAddr((uint32_t)g_EP0_Packet);
				mUsbCXDmaStart();
			}

		}
	}



	// Virtual DMA 
	if (g_IntGroup & BIT3)
	{
		g_IntVDMA = mUsbIntSrc3Rd();

		// CXF Complete
		if (g_IntVDMA & BIT0)
		{
			// DMA g_CXF_Done CXF_STATUS__NEED_TO_DONE
			if (g_EP0_Check == 1)
			{
				// Buffer Host Done !!
				if ((g_EP0_Offset == g_EP0_BufferLength) || (g_EP0_Offset == g_pSetupPacket->wLength))
				{
					// Cx Done!!!
					g_CXF_Done = CXF_STATUS__NEED_TO_DONE;

					g_EP0_Offset = 0;
					g_EP0_Remain = 0;
					g_EP0_BufferLength = 0;
				}

				g_EP0_Check = 0;
			}

			if (g_CXF_Done == CXF_STATUS__NEED_TO_DONE)
			{
				mUsbCXDmaFinishClr();
				mUsbCXDmaErrClr();
				mUsbCXIntDmaFinishDis();
				mUsbEP0DoneSet();

				g_CXF_Done = CXF_STATUS__COMPLETE_DONE;

				// DMA Flag
				SetupPacket_AfterCheck(g_pSetupPacket);

				memset(g_pSetupPacket, 0, sizeof(SETUP_PACKET));
				return;
			}
			else if (g_CXF_Done == CXF_STATUS__DOING)
			{
				//if ((g_CheckVDMAComplete_Touch == DMA_READY) && (g_CheckVDMAComplete_Custom == DMA_READY) && (g_CheckVDMAComplete_Pen == DMA_READY))
				{
					mUsbCXDmaFinishClr();
					mUsbCXDmaErrClr();
					mUsbCXIntDmaFinishDis();

					EP0_SetupPacket();
					return;
				}
			}
		}

#ifdef ADD_TOUCH
		// FIFO Complete - MultiTouch
		if (g_IntVDMA & (BIT1 << TOUCH_FIFO_IN))
		{
			mUsbEXDmaFinishClr(TOUCH_FIFO_IN);
			mUsbEXIntDmaErrDis(TOUCH_FIFO_IN);
			mUsbEXIntDmaFinishDis(TOUCH_FIFO_IN);

			// Touch DMA
			g_CheckVDMAComplete_Touch = DMA_READY;
		}
#endif
		
		
#ifdef ADD_CUSTOM
		// FIFO Complete - Custom OUT
		if (g_IntVDMA & (BIT1 << CUSTOM_FIFO_OUT))
		{
			// Custom OUT
			RecieveCustomData_DMA();
			
#ifdef JOSH3_LOOP_BACK_TEST
			g_CustomBuffer[0] = HID_REPORT_ID__CUSTOM_IN;
			SendCustomData_USB((UINT8*)g_CustomBuffer);
#else
			// App Call
			RecieveCustomData(g_CustomBuffer);
#endif
		}

		// FIFO Complete - Custom IN
		if (g_IntVDMA & (BIT1 << CUSTOM_FIFO_IN))
		{
			mUsbEXDmaFinishClr(CUSTOM_FIFO_IN);
			mUsbEXIntDmaErrDis(CUSTOM_FIFO_IN);
			mUsbEXIntDmaFinishDis(CUSTOM_FIFO_IN);

			// Custom DMA
			g_CheckVDMAComplete_Custom = DMA_READY;
		}
#endif
		
		
		
#ifdef ADD_PEN
		// FIFO Complete - Pen
		if (g_IntVDMA & (BIT1 << PEN_FIFO_IN))
		{
			mUsbEXDmaFinishClr(PEN_FIFO_IN);
			mUsbEXIntDmaErrDis(PEN_FIFO_IN);
			mUsbEXIntDmaFinishDis(PEN_FIFO_IN);

			// Touch DMA
			g_CheckVDMAComplete_Pen = DMA_READY;
		}
#endif



#ifdef ADD_BULK_CUSTOM
		// FIFO Complete - Bulk Custom OUT
		if (g_IntVDMA & (BIT1 << BULK_CUSTOM_FIFO_OUT))
		{
			// Bulk Custom OUT
			RecieveBulkCustomData_DMA();

			// App Call
			RecieveBulkCustomData(g_BulkCustomBuffer);
		}

		// FIFO Complete - Bulk Custom IN
		if (g_IntVDMA & (BIT1 << BULK_CUSTOM_FIFO_IN))
		{
			mUsbEXDmaFinishClr(BULK_CUSTOM_FIFO_IN);
			mUsbEXIntDmaErrDis(BULK_CUSTOM_FIFO_IN);
			mUsbEXIntDmaFinishDis(BULK_CUSTOM_FIFO_IN);

			// Bulk Custom DMA
			g_CheckVDMAComplete_BulkCustom = DMA_READY;
		}
#endif



		// CXF Error
		if (g_IntVDMA & BIT16)
		{
			mUsbCXDmaErrClr();
		}

		// FIFO 0 Error
		if (g_IntVDMA & BIT17)
		{
			mUsbEXDmaErrClr(0);
		}

		// FIFO 1 Error
		if (g_IntVDMA & BIT18)
		{
			mUsbEXDmaErrClr(1);
		}

		// FIFO 2 Error
		if (g_IntVDMA & BIT19)
		{
			mUsbEXDmaErrClr(2);
		}

		// FIFO 3 Error
		if (g_IntVDMA & BIT20)
		{
			mUsbEXDmaErrClr(3);
		}
	}



	// USB Controll
	if (g_IntGroup & BIT2)
	{
		g_IntControl = mUsbIntSrc2Rd();

		// USBRST_INT
		if (g_IntControl & BIT0)
		{
			g_RemoteWakeup = 0;
			g_Configuration = 0;
			g_HIDReady = 0;

			// Clear
			mUsbIntBusRstClr();

			// Addr
			mUsbDevAddrSet(0);

			// FIFO
			mUsbClrAllFIFOSet();

			// EP0 FIFO Clear
			mUsbCxFClr();

			// Full Speed
			mUsbOTGDevFS();

			// Init
			USB_ResetResume();
			
			// Queue
			StaticQueue_Init(&g_Queue_Common);

			// SelfPowerd, RemoteWakeup Disable Status
			g_Status[0].Status.Global.SelfPowered = 1;
			g_Status[0].Status.Global.RemoteWakeup = 0;
		}

		// SUSP_INT
		if (g_IntControl & BIT1)
		{
			g_Configuration = 0;
			g_HIDReady = 0;

			mUsbIntSuspClr();
		}

		// RESM_INT
		if (g_IntControl & BIT2)
		{
			if (g_RemoteWakeup == 1)
			{
				g_RemoteWakeup = 0;
				mUsbRemoteWakeUpSet_0();
				g_ScanTime_Recovery = 0;
				g_StartTime_Recovery = 0;
				GetScanTime(&g_StartTime_Recovery_ClearSus, &g_ScanTime_Recovery_ClearSus);
				Recovery_ClearSus_Flag = 1;
			}

			mUsbIntResmClr();
			g_Configuration=1;
			g_HIDReady=1;

			// Init
			USB_ResetResume();
		}

		// DMA_COMPLT
		if (g_IntControl & BIT7)
		{
			// Finish
			mUsbIntDmaFinishClr();

			// FIFO Control Stop
			mUsbDMA2FIFOSel(0);
		}

	}




	if (g_IntGroup & BIT1)
	{
		g_IntEP = mUsbIntSrc1Rd(); // 0x148

#ifdef ADD_TOUCH
		// Multi Touch (IN)
		if (g_IntEP & (BIT16 << TOUCH_FIFO_IN))
		{
			if ((g_CheckVDMAComplete_Touch == DMA_NOT_READY) && (g_CXF_Done == CXF_STATUS__COMPLETE_DONE))
			{
				mUsbIntF1INDis();
				DMATouchData_USB();
				return;
			}
		}
#endif

#ifdef ADD_CUSTOM
		// Custom (IN)
		if (g_IntEP & (BIT16 << CUSTOM_FIFO_IN))
		{
			if ((g_CheckVDMAComplete_Custom == DMA_NOT_READY) && (g_CXF_Done == CXF_STATUS__COMPLETE_DONE))
			{
				mUsbIntF0INDis();
				DMACustomData_USB();
				return;
			}
		}
#endif

#ifdef ADD_PEN
		// Pen (IN)
		if (g_IntEP & (BIT16 << PEN_FIFO_IN))
		{
			if ((g_CheckVDMAComplete_Pen == DMA_NOT_READY) && (g_CXF_Done == CXF_STATUS__COMPLETE_DONE))
			{
				mUsbIntF3INDis();
				DMAPenData_USB();
				return;
			}
		}
#endif

#ifdef ADD_BULK_CUSTOM
		// Bulk Custom (IN)
		if (g_IntEP & (BIT16 << BULK_CUSTOM_FIFO_IN))
		{
			if ((g_CheckVDMAComplete_BulkCustom == DMA_NOT_READY) && (g_CXF_Done == CXF_STATUS__COMPLETE_DONE))
			{
				mUsbIntF0INDis();
				DMABulkData_USB();
				return;
			}
		}
#endif

	}

#endif
	return;
}



void USB_DevInit(void)
{
#ifndef MODE_I2C
	Fncp_USB_IRQHandler = &USB_InterruptHandler;
	
	// suspend counter
	mUsbIdleCnt(7);

	mUsbUnPLGClr();

	// Clear interrupt
	mUsbIntBusRstClr();
	mUsbIntSuspClr();
	mUsbIntResmClr();

	// Disable all fifo interrupt
	mUsbIntFIFO0_3OUTDis();
	mUsbIntFIFO0_3INDis();

	// Clear all fifo
	mUsbClrAllFIFOSet();

	mUsbIntWakebyVbusDis();
	mUsbIntDevIdleDis();

	// Enable usb200 global interrupt
	mUsbGlobIntEnSet();
	mUsbChipEnSet();
	mUsbOTGDevFS();

	// Interrupt Mode
	mUsbIntPolarityLow();

	
	// Virtual DMA
	mUsbVDMAEnable();

	// Virtual DMA Mask - CXF Enable
	mUsbCXIntDmaErrEn();
	mUsbCXIntDmaFinishEn();
	

	// RemoteWakeup
	mUsbRmWkupSet(); 
#endif

#ifdef ADD_PEN //ADD_CUSTOM // NOTE : In this case, used the Pen Mode status
    sptAlgorithmInfo = algorithm_GetInfo();
#endif

	// Queue
	StaticQueue_Init(&g_Queue_Common);
	return;
}


