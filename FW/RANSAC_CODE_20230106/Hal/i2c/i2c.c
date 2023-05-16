/****************************************************************************************************//**
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


// I2C Register
tI2C_CtrlReg_t*							g_I2C = I2C;

// Power On 상태, 데이터 처리가 가능한 상태
uint8_t									g_Ready = I2C_NOT_READY;
uint8_t									g_Ready_Complete = I2C_NOT_READY;

// 초기화 이후에 Touch 데이터 내보내기 전에 몇 초 정도 딜레이 시킨다.
uint8_t									g_DelayCheck = 0;
uint32_t 									g_DelayTime = 0;
uint64_t									g_StartTime_I2C = 0;

// 터치 장치가 PC 에 연결될 경우가 있고 Tool 에 연결될 경우가 있다.
// 이 두 가지 상태를 구분할 수 있는 근거는 맨 처음 Host 로 부터 받는 명령어가 0x0150 인지 확인하는 것이다.
// PC 에 연결되면 값이 0, Tool 에 연결되면 값이 1, Tool 에서 0x0150 데이터를 받으면 값이 2
uint8_t 								g_ConnectedDevice = I2C_CONNECT_TOOL;

// Tool 에 연결되었을 경우 Slave Address 처리 부분이 중복 호출 되지 않도록 한다
uint8_t 								g_ConnectedDevice_FirstCheck = 0; 

// Reset 
uint8_t									g_bReset = I2C_NORMAL;

// GPIO
uint8_t									g_GpioDisable = I2C_GPIO_NORMAL;

// Master 에서 Slave 로 보내주는 명령어를 보관
uint8_t									g_RxCommand[100] = { 0, };
uint32_t								g_RxCommandIndex = 0;

// 명령어에 대해서 Slave 에서 응답하는 데이터의 포인터
uint8_t*								g_TxPtr = NULL;
uint32_t								g_TxIndex = 0;

uint8_t*								g_TxPtr_Touch = NULL;
uint32_t								g_TxIndex_Touch = 0;

uint8_t*								g_TxPtr_Pen = NULL;
uint32_t								g_TxIndex_Pen = 0;

uint8_t*								g_TxPtr_Custom = NULL;
uint32_t								g_TxIndex_Custom = 0;
uint8_t									g_CheckComplete_Custom_I2C = DMA_READY;

#ifdef MODE_I2C

// I2C HID Descriptor
I2C_HID_DESCRIPTOR						g_I2CHidDescriptor = { 0, };


SETREPORT_DEVICE_MODE					g_DeviceMode_I2C = { 0, };
SETREPORT_LATENCY_MODE					g_LatencyMode_I2C = { 0, }; // LATENCY_MODE__NORMAL, LATENCY_MODE__HIGH



//
// Multi-Touch
//

uint8_t									g_HID_ReportDesc_Temp[HID_MULTITOUCH_DESC_TOTAL_LENGTH + HID_PEN_DESC_LENGTH + HID_CUSTOM_DESC_LENGTH] = { 0, };

#ifdef ADD_TOUCH
// Report Descriptor
extern uint8_t							u8_HID_MultiTouch_Descriptor_Head[HID_MULTITOUCH_DESC_HEAD_LENGTH];
extern uint8_t							u8_HID_MultiTouch_Descriptor_Main[HID_MULTITOUCH_DESC_MAIN_LENGTH];
extern uint8_t							u8_HID_MultiTouch_Descriptor_Tail[HID_MULTITOUCH_DESC_TAIL_LENGTH];
extern uint8_t							u8_HID_Touch_Blob[HID_TOUCH_BLOB_LENGTH];


// Touch Max Count
TOUCH_MAX_COUNT							g_MaxTouchCount_I2C = { 0, };
#endif







//
// Custom
//

#ifdef ADD_CUSTOM
// Report Descriptor
extern uint8_t							u8_HID_Custom_Descriptor[HID_CUSTOM_DESC_LENGTH];

#endif






//
// Pen
//

#ifdef ADD_PEN
// Report Descriptor
extern uint8_t							u8_HID_Pen_Descriptor[HID_PEN_DESC_LENGTH];
#endif

#endif








//
// Common (Touch + Pen + Custom)
//

// Queue
extern STATIC_QUEUE						g_Queue_Common;
HID_COMMON_I2C							g_Common_I2C = { 0, };

// Touch, Custom, Pen 데이터의 포인터
uint8_t*								g_TxPtr_Common = NULL;
uint32_t								g_TxIndex_Common = 0;
uint8_t									g_CheckComplete_Common_I2C = DMA_READY;




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


uint8_t CheckI2CReady(void)
{
	if (g_ConnectedDevice == I2C_CONNECT_TOOL)
	{
		return 1;
	}
	else
	{
		return g_Ready_Complete;
	}
}



#ifdef MODE_I2C

uint16_t GetDelayTime(void)
{
	uint16_t Temp = 0;

	if (g_StartTime_I2C == 0)
	{
		goto GETSCANTIME__GOTO_END;
	}

	// getLongSysTick() 함수를 통해서 구한 값은 계속 작아진다.
	// 일반적인 Tick Count 와는 다른 듯...
	Temp = (uint16_t)(getElapsedUS(g_StartTime_I2C) / 100);
	g_DelayTime += Temp;

GETSCANTIME__GOTO_END:

	g_StartTime_I2C = (uint64_t)getLongSysTick();
	return g_DelayTime;
}


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

	// Reset 명령에 대한 응답으로 2바이트 0 을 준비한다.
	// Host 에서는 36바이트 정도를 읽어가는 것 같다.
	I2C->I2C_TXFIFO_DATA = 0x00;
	I2C->I2C_TXFIFO_DATA = 0x00;

	// GPIO Interrupt Enable
	GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_LOW);
	return;
}

static void Init_HidDescriptor(void)
{
	//g_I2CHidDescriptor.DescLength = sizeof(I2C_HID_DESCRIPTOR); // I2C_IRQHandler 에서 2바이트를 먼저 처리 하기 때문에 이 부분 필요 없음
	g_I2CHidDescriptor.BCDVersion = 0x0100; // MS 문서에 1.0 으로 명시되어 있음!

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
void SendTouchData_I2C(PHID_MULTITOUCH_I2C pUserData)
{
	if (g_DelayCheck == 0)
	{
		// 0.5 Sec
		if (GetDelayTime() < I2C_DELAY_TIME)
		{
			goto  SENDTOUCHDATA_I2C__GOTO_END;
		}

		g_DelayCheck = 1;
	}

	if (StaticQueue_CheckFull(&g_Queue_Common) == 1)
	{
		// 큐의 최대치를 넘어가면..  (데이터 손실)
		goto SENDTOUCHDATA_I2C__GOTO_END;
	}

	StaticQueue_Push(&g_Queue_Common, (uint8_t*)pUserData);

SENDTOUCHDATA_I2C__GOTO_END:

	return;
}

#endif

#endif







//
// Custom
//

static volatile uint16_t usRegAddr = 0;
static volatile uint8_t* rmi_read_ptr = NULL;
static volatile uint8_t* rmi_write_ptr = NULL;
static int i2c_sent_byte = 0;
static int i2c_received_byte = 0;
extern uint8_t* (*protocol_GetMappedPointer)(uint16_t addr);
extern void(*protocol_ClearInterrupt)(uint16_t addr);
__IO uint8_t custom_tool;
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
		// 큐의 최대치를 넘어가면..  (데이터 손실)
		goto SENDCUSTOMDATA_I2C__GOTO_END;
	}

	pUserData->I2C_Length = sizeof(HJ_HID_CONTROL_STRUCT_I2C);
	StaticQueue_Push(&g_Queue_Common, (uint8_t*)pUserData);

SENDCUSTOMDATA_I2C__GOTO_END:

	return;
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


uint16_t swap_uint16(uint16_t val)
{
	return (val << 8) | (val >> 8);
}


void GetCustomData_I2C(uint8_t* pData)
{
	memcpy(&g_CustomBuffer_I2C.Data, pData, I2C_DATA_LENGTH);
	return;
}






#ifdef MODE_I2C
//
// Pen
//

#ifdef ADD_PEN
void SendPenData_I2C(PHID_PEN_I2C pUserData)
{
	if (g_DelayCheck == 0)
	{
		if (GetDelayTime() < I2C_DELAY_TIME)
		{
			goto  SENDPENDATA_I2C__GOTO_END;
		}

		g_DelayCheck = 1;
	}

	if (StaticQueue_CheckFull(&g_Queue_Common) == 1)
	{
		// 큐의 최대치를 넘어가면..  (데이터 손실)
		goto SENDPENDATA_I2C__GOTO_END;
	}

	pUserData->I2C_Length = sizeof(HID_PEN_I2C);
	StaticQueue_Push(&g_Queue_Common, (uint8_t*)pUserData);

SENDPENDATA_I2C__GOTO_END:

	return;
}
#endif
#endif







//
// Common I2C (Touch + Pen + Custom)
//

void QueueCommonData_I2C(void)
{
	if ((g_CheckComplete_Common_I2C == DMA_READY) && (g_RxCommandIndex == 0))
	{
		if (StaticQueue_CheckEmpty(&g_Queue_Common) == 0)
		{
			// Pop
			if (StaticQueue_Pop(&g_Queue_Common, (uint8_t*)&g_Common_I2C) == TRUE)
			{
                // Flag
                g_CheckComplete_Common_I2C = DMA_NOT_READY;

                // Pointer
                g_TxPtr_Common = (uint8_t*)&g_Common_I2C;
                g_TxIndex_Common = 0;

                // Clear Tx
                I2C->I2C_FIFO_CR.ulBulk |= 0x01;

                // GPIO Interrupt Enable
                GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_LOW);
            }
		}
	}

	return;
}






//
// I2C - ISR
//

#if USED_I2C_STOP_STATE_CHECK
#define I2C_SLV_TR_MAX_CNT_		(66)

bool_t g_bSkipStopProcess = NO;

void I2C_StopProcess(void)
{
	if (g_RxCommandIndex > 0)
	{
		uint16_t*	pCheckRegister = (uint16_t*)g_RxCommand;

		switch (*pCheckRegister)
		{
			// Master 에서 I2C HID Descriptor 의 내용을 참고해서 Command Register 를 명령어로 보낸다.
			case I2C_COMMAND_REGISTER:
			{
				PI2C__REQUEST pRequest = (PI2C__REQUEST)g_RxCommand;

				// Set Power (22 00 00 08)
				if ((pRequest->I2C_Request_Power.PowerState == I2C__REQUEST_REPORT_POWER_STATE__ON) &&
					(pRequest->OpCode == I2C__REQUEST_OPCODE__SET_POWER))
				{
					g_TxPtr = NULL;
					g_TxIndex = 0;

					g_Ready = I2C_READY;
					break;
				}
				// Sleep
				else if ((pRequest->I2C_Request_Power.PowerState == I2C__REQUEST_REPORT_POWER_STATE__SLEEP) &&
						 (pRequest->OpCode == I2C__REQUEST_OPCODE__SET_POWER))
				{
					g_TxPtr = NULL;
					g_TxIndex = 0;

					g_Ready = I2C_NOT_READY;
					break;
				}
				// Reset (22 00 00 01)
				else if ((pRequest->I2C_Request_Common.ReportType == I2C__REQUEST_REPORT_TYPE__NONE) &&
					(pRequest->OpCode == I2C__REQUEST_OPCODE__RESET))
				{
					g_TxPtr = NULL;
					g_TxIndex = 0;

					g_bReset = I2C_RESET;
					break;
				}
#ifdef MODE_I2C
				// Device Mode - (22 00 37 03 23 00 05 00 07 02 00)
				else if ((pRequest->I2C_Request_Common.ReportID == HID_REPORT_ID__DEVICE_MODE) &&
					(pRequest->OpCode == I2C__REQUEST_OPCODE__SET_REPORT))
				{
					g_TxPtr = NULL;
					g_TxIndex = 0;

					memcpy((uint8_t*)&g_DeviceMode_I2C, (uint8_t*)&pRequest->Data[0], sizeof(SETREPORT_DEVICE_MODE));
					break;
				}
				// Latency Mode (22 00 35 03 23 04 00 05 00 or 01)
				else if ((pRequest->I2C_Request_Common.ReportID == HID_REPORT_ID__LATENCY_MODE) &&
					(pRequest->OpCode == I2C__REQUEST_OPCODE__SET_REPORT))
				{
					g_TxPtr = NULL;
					g_TxIndex = 0;

					memcpy((uint8_t*)&g_LatencyMode_I2C, (uint8_t*)&pRequest->Data[0], sizeof(SETREPORT_LATENCY_MODE));
					break;
				}
#endif

				break;
			}
			case I2C_OUTPUT_REGISTER:
			{
				PI2C__OUTPUT pOutputData = (PI2C__OUTPUT)g_RxCommand;
				custom_tool=1;

#ifdef ADD_CUSTOM
				if (pOutputData->ReportID == HID_REPORT_ID__CUSTOM_OUT)
				{
					GetCustomData_I2C(&pOutputData->ReportID);
					RecieveCustomData_I2C(&g_CustomBuffer_I2C);

					// Init Command 처리 없이 Custom OUT 데이터가 먼저 들어올 수 있다.
					// 이 경우에는 여기서 Ready 를 체크 해줘야 한다.
					g_Ready = I2C_READY;

					// Custom App 를 사용해서 F/W Download 를 했을 경우 Custom OUT 을 마지막으로
					// 장치가 Reboot 되는데 이후에 Init Command 없이 곧 바로 Touch 가 동작할 수 있어야 한다.
					// 그래서 Delay 작업을 하면 안 된다.
					g_DelayCheck = 1;
				}
#endif
				break;
			}
		}

		memset(g_RxCommand, 0, 100);
		g_RxCommandIndex = 0;
	}

	// Touch, Custom, Pen
	else if (g_CheckComplete_Common_I2C == DMA_NOT_READY)
	{
		g_CheckComplete_Common_I2C = DMA_READY;
		g_GpioDisable = I2C_GPIO_DISABLE;
	}

#ifdef MODE_I2C
	GetDelayTime();
#endif

	if (g_Ready == I2C_READY)
	{
		g_Ready_Complete = I2C_READY;
	}
	else
	{
		g_Ready_Complete = I2C_NOT_READY;
		g_StartTime_I2C = 0;
		g_DelayTime = 0;
	}

	if (g_GpioDisable == I2C_GPIO_DISABLE)
	{
		// Check GPIO Interrupt
		if (IS_GPIO_PIN(_GPIO_TP_INTR) == GPIO_DATA_LOW)
		{
			// Disable GPIO Interrupt
			GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_HIGH);
		}

		g_GpioDisable = I2C_GPIO_NORMAL;
	}

#ifdef MODE_I2C
	// Reset 명령에 대한 응답을 준비한다.
	if (g_bReset == I2C_RESET)
	{
		Make_EmptyI2CData();
	}
#endif
}
#endif

void I2C_InterruptHandler(void)
{
	uint16_t nTransCnt = 0;

	nTransCnt = I2C->I2C_SLV_DBG.tBit.I2cSlvTrCnt;

	// Interrupt Clear
	I2C->I2C_GLB_SR.tBit.I2C_ITRPT = 0;

	// Reset 관련 처리 중
	if (g_bReset == I2C_RESET)
	{
		g_bReset = I2C_NORMAL;

		// Check GPIO Interrupt
		if (IS_GPIO_PIN(_GPIO_TP_INTR) == GPIO_DATA_LOW)
		{
			// Disable GPIO Interrupt
			GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_HIGH);
		}

		// Touch, Pen 데이터를 내보내는 작업을 지연시킨다.
		g_DelayCheck = 0;
		g_StartTime_I2C = 0;
		g_DelayTime = 0;
	}


#ifdef I2C_SELECTIVE_SUSPEND
	// Sleep Interrupt 처리
	if (I2C->I2C_SET_PWR_INT.tBit.SleepItrpt == 1)
	{
		// Clear
		I2C->I2C_SET_PWR_INT.tBit.SleepItrpt = 0;

		I2C->I2C_SET_PWR_REG.tBit.SetPwrRegLSBSleep = 1; // 현재는 Sleep 상태
		I2C->I2C_SET_PWR_REG.tBit.SetPwrRegLSBOn = 0;

		I2C->I2C_SET_PWR_CMD.tBit.SetPwrCmdMSB = I2C__REQUEST_REPORT_POWER_STATE__ON; // WakeUp 명령이 오길 기다린다.
		I2C->I2C_SET_PWR_CMD.tBit.SetPwrCmdLSB = I2C__REQUEST_OPCODE__SET_POWER;
	
		// Sleep Enable
		I2C->I2C_SLP_CR.tBit.SlpCr = 1;
		I2C->I2C_SLP_CR.tBit.PrMux = 1;

		goto I2C_IRQHANDLER__GOTO_END;
	}

	// WakeUp Interrupt 처리
	if (I2C->I2C_SET_PWR_INT.tBit.WakeUpItrpt == 1)
	{
		// Clear
		I2C->I2C_SET_PWR_INT.tBit.WakeUpItrpt = 0;

		I2C->I2C_SET_PWR_REG.tBit.SetPwrRegLSBSleep = 0;
		I2C->I2C_SET_PWR_REG.tBit.SetPwrRegLSBOn = 1;	// 현재는 WakeUp 상태

		I2C->I2C_SET_PWR_CMD.tBit.SetPwrCmdMSB = I2C__REQUEST_REPORT_POWER_STATE__SLEEP; // Sleep 명령이 오길 기다린다.
		I2C->I2C_SET_PWR_CMD.tBit.SetPwrCmdLSB = I2C__REQUEST_OPCODE__SET_POWER;
	
		// Sleep Enable
		I2C->I2C_SLP_CR.tBit.SlpCr = 0;
		I2C->I2C_SLP_CR.tBit.PrMux = 0;

		goto I2C_IRQHANDLER__GOTO_END;
	}
#endif




	// Start
	if (I2C->I2C_GLB_SR.tBit.I2cItrptState == I2C_STR_ITRPT)
	{
#if USED_I2C_STOP_STATE_CHECK
		g_bSkipStopProcess = NO;
#endif

		// Command 를 처리하고 있지 않을 때
		if (g_RxCommandIndex == 0)
		{
			if (CheckI2CReady() == 1)
			{
				if (g_CheckComplete_Common_I2C == DMA_NOT_READY)
				{
					// 2바이트를 먼저 넣어놓고 (Length)
					I2C->I2C_TXFIFO_DATA = g_TxPtr_Common[g_TxIndex_Common];
					g_TxIndex_Common += 1;

					I2C->I2C_TXFIFO_DATA = g_TxPtr_Common[g_TxIndex_Common];
					g_TxIndex_Common += 1;
					goto I2C_IRQHANDLER__PASS;
				}
			}
		}
		else
		{
			// 만약 Command 를 처리해야 할 때 Touch, Custom, Pen 데이터의 처리 과정이 겹치게 되면
			// Touch, Custom, Pen 데이터를 처리하지 않도록 한다.
			if (g_CheckComplete_Common_I2C == DMA_NOT_READY)
			{
				g_CheckComplete_Common_I2C = DMA_READY;

				g_DelayCheck = 0;
				g_StartTime_I2C = 0;
				g_DelayTime = 0;

				// Check GPIO Interrupt
				if (IS_GPIO_PIN(_GPIO_TP_INTR) == GPIO_DATA_LOW)
				{
					// Disable GPIO Interrupt 
					GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_HIGH);
				}
			}
		}


I2C_IRQHANDLER__PASS:


		if (g_RxCommandIndex > 0)
		{
			uint16_t*	pCheckRegister = (uint16_t*)g_RxCommand;

			if (g_CheckComplete_Common_I2C == DMA_NOT_READY)
			{
				goto I2C_IRQHANDLER__GOTO_END;
			}

			switch (*pCheckRegister)
			{
#ifdef MODE_I2C
				// 첫 번째로 받는 명령어
				// I2C HID Descriptor 로 응답한다.
				case HID_DESCRIPTOR_ADDRESS:
				{
					uint16_t	Length = 0;
					
					g_ConnectedDevice = I2C_CONNECT_PC;

					// Clear Tx
					I2C->I2C_FIFO_CR.ulBulk |= 0x01;

					// I2C HID Descriptor
					Length = sizeof(I2C_HID_DESCRIPTOR) + 2;

					// 2 바이트 먼저 입력
					I2C->I2C_TXFIFO_DATA = (uint8_t)(Length & 0x00FF);
					I2C->I2C_TXFIFO_DATA = (uint8_t)(Length >> 8);

					g_TxPtr = (uint8_t*)&g_I2CHidDescriptor;
					g_TxIndex = 0;
					break;
				}

				// Master 에서 I2C HID Descriptor 의 내용을 참고해서 Report Register 를 명령어로 보낸다.
				// HID Report Descriptor 로 응답한다.
				case I2C_REPORT_REGISTER:
				{
					// Clear Tx
					I2C->I2C_FIFO_CR.ulBulk |= 0x01;

					// HID Report Descriptor
					g_TxPtr = (uint8_t*)g_HID_ReportDesc_Temp;
					g_TxIndex = 0;

					// 2바이트 먼저 입력
					I2C->I2C_TXFIFO_DATA = g_TxPtr[g_TxIndex];
					g_TxIndex += 1;
					I2C->I2C_TXFIFO_DATA = g_TxPtr[g_TxIndex];
					g_TxIndex += 1;
					break;
				}
#endif
				// Master 에서 I2C HID Descriptor 의 내용을 참고해서 Command Register 를 명령어로 보낸다.
				case I2C_COMMAND_REGISTER:
				{
					PI2C__REQUEST pRequest = (PI2C__REQUEST)g_RxCommand;

					if (pRequest->OpCode == I2C__REQUEST_OPCODE__GET_REPORT)
					{
#ifdef MODE_I2C
#ifdef ADD_TOUCH
						// Report ID : 8 - Get MaxTouch Count (22 00 38 02 23 00)
						if (pRequest->I2C_Request_Common.ReportID == HID_REPORT_ID__CONTACT_COUNT)
						{
							uint16_t	Length = 0;
							
							// Clear Tx
							I2C->I2C_FIFO_CR.ulBulk |= 0x01;

							// I2C HID Descriptor
							Length = sizeof(TOUCH_MAX_COUNT) + 2;

							// 2 바이트 먼저 입력
							I2C->I2C_TXFIFO_DATA = (uint8_t)(Length & 0x00FF);
							I2C->I2C_TXFIFO_DATA = (uint8_t)(Length >> 8);

							g_TxPtr = (uint8_t*)&g_MaxTouchCount_I2C;
							g_TxIndex = 0;

							g_MaxTouchCount_I2C.ReportID = HID_REPORT_ID__CONTACT_COUNT;
							g_MaxTouchCount_I2C.Count = HID_MAX_TOUCH;
							break;
						}

						// Report ID : 6 - Get BlobCode (22 00 36 02 23 00)
						if (pRequest->I2C_Request_Common.ReportID == HID_REPORT_ID__BLOB_CODE)
						{
							uint16_t	Length = 0;
							
							// Clear Tx
							I2C->I2C_FIFO_CR.ulBulk |= 0x01;

							// I2C HID Descriptor
							Length = HID_TOUCH_BLOB_LENGTH + 2;

							// 2 바이트 먼저 입력
							I2C->I2C_TXFIFO_DATA = (uint8_t)(Length & 0x00FF);
							I2C->I2C_TXFIFO_DATA = (uint8_t)(Length >> 8);

							g_TxPtr = (uint8_t*)u8_HID_Touch_Blob;
							g_TxIndex = 0;
							break;
						}
#endif
#endif
					}

					break;
				}

				case I2C_DATA_REGISTER:
				{
					break;
				}

				case I2C_INPUT_REGISTER:
				{
					break;
				}

				case I2C_OUTPUT_REGISTER:
				{
					break;
				}
			}
		}

	}
	else if (I2C->I2C_GLB_SR.tBit.I2cItrptState == I2C_BYTE_ITRPT)
	{
		// Master --> Slave
		if (I2C->I2C_GLB_SR.tBit.I2cSlvRdWrFlag == 0)
		{
			//
			// I2C 장치에 연결할 때
			//
			if (g_ConnectedDevice > I2C_CONNECT_PC)
			{
				if (nTransCnt == 1)
				{
					usRegAddr = (uint8_t)(I2C->I2C_RXFIFO_DATA & 0xFF);
					usRegAddr <<= 8;
				}
				else if (nTransCnt == 2)
				{
					usRegAddr |= (uint8_t)(I2C->I2C_RXFIFO_DATA & 0xFF);

					if (g_ConnectedDevice_FirstCheck == 0)
					{
						if ((swap_uint16(usRegAddr) == HID_DESCRIPTOR_ADDRESS) || (swap_uint16(usRegAddr) == I2C_COMMAND_REGISTER) || (swap_uint16(usRegAddr) == I2C_OUTPUT_REGISTER))
						{
							// PC 에 연결했다고 판단한다.
							g_ConnectedDevice_FirstCheck = 1;
							g_ConnectedDevice = I2C_CONNECT_PC;

							g_RxCommand[0] = (uint8_t)(usRegAddr >> 8);
							g_RxCommand[1] = (uint8_t)(usRegAddr & 0x00FF);
							g_RxCommandIndex = 2;
							goto I2C_IRQHANDLER__GOTO_END;
						}

						// 장치랑 연결하게 되면 가장 먼저 0x0150 을 받게 된다!!
						if (usRegAddr == 0x0150)
						{
							g_ConnectedDevice = I2C_CONNECT_TOOL_0x150;
						}
					}

					g_ConnectedDevice_FirstCheck = 1;

					I2C->I2C_FIFO_CR.ulBulk |= 0x01;	// Clear

					if (protocol_GetMappedPointer != NULL)
					{
						rmi_read_ptr = rmi_write_ptr = (*protocol_GetMappedPointer)(usRegAddr);
						i2c_sent_byte = i2c_received_byte = 0;

						if (rmi_read_ptr != NULL)
						{
							I2C->I2C_TXFIFO_DATA = *(rmi_read_ptr++);
							if (protocol_ClearInterrupt != NULL)
							{
								(*protocol_ClearInterrupt)(usRegAddr + i2c_sent_byte);
							}

							i2c_sent_byte++;
						}
					}
				}
				else if (nTransCnt > 2)
				{
					if (rmi_write_ptr != NULL)
					{
						*(rmi_write_ptr++) = I2C->I2C_RXFIFO_DATA;
						i2c_received_byte++;
					}
				}
			}

			//
			// PC 에 연결할 때
			//
			else
			{
				if (I2C->I2C_FIFO_SR2.tBit.RxFifoEmpty == 0)
				{
					uint8_t ReadData = 0;

					ReadData = (uint8_t)(I2C->I2C_RXFIFO_DATA & 0xFF);
					if (g_RxCommandIndex < 100)
					{
						g_RxCommand[g_RxCommandIndex] = ReadData;
						g_RxCommandIndex += 1;

						// OUTPUT 데이터가 들어올 때는 Delay 작업을 하지 않는다.
						if ((g_RxCommand[0] != (uint8_t)I2C_OUTPUT_REGISTER))
						{
							// Touch, Pen 데이터를 내보내는 작업을 지연시킨다.
							g_DelayCheck = 0;
							g_StartTime_I2C = 0;
							g_DelayTime = 0;
						}
					}
				}
			}
		}
		// Slave --> Master
		else
		{
			// g_ConnectedDevice 값이 1인 경우에는 Slave --> Master 방향으로 데이터가 처리 될 수 없다.
			// 이 경우는 PC 에 연결되었다고 판단하게 되므로 g_ConnectedDevice 값을 0 으로 바꿔서 처리 해야 한다.
			if (g_ConnectedDevice == I2C_CONNECT_TOOL)
			{
				g_ConnectedDevice = I2C_CONNECT_PC;
				g_Ready_Complete = I2C_READY;
				g_Ready = I2C_READY;
			}

			//
			// I2C 장치에 연결할 때
			//
			if (g_ConnectedDevice > I2C_CONNECT_PC) // Tool 에 연결되었고 0x0150 데이터를 받았다는 것 까지 체크 한다.
			{
				if (rmi_read_ptr)
				{
					I2C->I2C_TXFIFO_DATA = *(rmi_read_ptr++);
					if (protocol_ClearInterrupt != NULL)
					{
						(*protocol_ClearInterrupt)(usRegAddr + i2c_sent_byte);
					}

					i2c_sent_byte++;
				}
			}

			//
			// PC 에 연결할 때
			//
			else
			{
				g_Ready = I2C_READY;

				// HID Descriptor 처리 하는 부분
				if (g_RxCommandIndex > 0)
				{
					I2C->I2C_TXFIFO_DATA = g_TxPtr[g_TxIndex];
					g_TxIndex += 1;
				}

				if (CheckI2CReady() == 1)
				{
					if (g_CheckComplete_Common_I2C == DMA_NOT_READY)
					{
						I2C->I2C_TXFIFO_DATA = g_TxPtr_Common[g_TxIndex_Common];
						g_TxIndex_Common += 1;
//						goto I2C_IRQHANDLER__GOTO_END;

#if USED_I2C_STOP_STATE_CHECK
						if (I2C->I2C_SLV_DBG.tBit.I2cSlvTrCnt == I2C_SLV_TR_MAX_CNT_ && I2C->I2C_GLB_SR.tBit.I2cItrptState == I2C_STP_ITRPT)
						{
							I2C_StopProcess();
							g_bSkipStopProcess = YES;
						}
#endif
					}
				}
			}

		}
	}
	// Stop
	else if (I2C->I2C_GLB_SR.tBit.I2cItrptState == I2C_STP_ITRPT)
	{
#if USED_I2C_STOP_STATE_CHECK
		if (!g_bSkipStopProcess)
		{
			I2C_StopProcess();
		}
#else
		if (g_RxCommandIndex > 0)
		{
			uint16_t*	pCheckRegister = (uint16_t*)g_RxCommand;

			switch (*pCheckRegister)
			{
				// Master 에서 I2C HID Descriptor 의 내용을 참고해서 Command Register 를 명령어로 보낸다.
				case I2C_COMMAND_REGISTER:
				{
					PI2C__REQUEST pRequest = (PI2C__REQUEST)g_RxCommand;

					// Set Power (22 00 00 08)
					if ((pRequest->I2C_Request_Power.PowerState == I2C__REQUEST_REPORT_POWER_STATE__ON) &&
						(pRequest->OpCode == I2C__REQUEST_OPCODE__SET_POWER))
					{
						g_TxPtr = NULL;
						g_TxIndex = 0;

						g_Ready = I2C_READY;
						break;
					}
					// Sleep
					else if ((pRequest->I2C_Request_Power.PowerState == I2C__REQUEST_REPORT_POWER_STATE__SLEEP) &&
							 (pRequest->OpCode == I2C__REQUEST_OPCODE__SET_POWER))
					{
						g_TxPtr = NULL;
						g_TxIndex = 0;

						g_Ready = I2C_NOT_READY;
						break;
					}
					// Reset (22 00 00 01)
					else if ((pRequest->I2C_Request_Common.ReportType == I2C__REQUEST_REPORT_TYPE__NONE) &&
						(pRequest->OpCode == I2C__REQUEST_OPCODE__RESET))
					{
						g_TxPtr = NULL;
						g_TxIndex = 0;

						g_bReset = I2C_RESET;
						break;
					}
#ifdef MODE_I2C
					// Device Mode - (22 00 37 03 23 00 05 00 07 02 00)
					else if ((pRequest->I2C_Request_Common.ReportID == HID_REPORT_ID__DEVICE_MODE) &&
						(pRequest->OpCode == I2C__REQUEST_OPCODE__SET_REPORT))
					{
						g_TxPtr = NULL;
						g_TxIndex = 0;

						memcpy((uint8_t*)&g_DeviceMode_I2C, (uint8_t*)&pRequest->Data[0], sizeof(SETREPORT_DEVICE_MODE));
						break;
					}
					// Latency Mode (22 00 35 03 23 04 00 05 00 or 01)
					else if ((pRequest->I2C_Request_Common.ReportID == HID_REPORT_ID__LATENCY_MODE) &&
						(pRequest->OpCode == I2C__REQUEST_OPCODE__SET_REPORT))
					{
						g_TxPtr = NULL;
						g_TxIndex = 0;

						memcpy((uint8_t*)&g_LatencyMode_I2C, (uint8_t*)&pRequest->Data[0], sizeof(SETREPORT_LATENCY_MODE));
						break;
					}
#endif

					break;
				}
				case I2C_OUTPUT_REGISTER:
				{
					PI2C__OUTPUT pOutputData = (PI2C__OUTPUT)g_RxCommand;
					custom_tool=1;

#ifdef ADD_CUSTOM
					if (pOutputData->ReportID == HID_REPORT_ID__CUSTOM_OUT)
					{
						GetCustomData_I2C(&pOutputData->ReportID);
						RecieveCustomData_I2C(&g_CustomBuffer_I2C);

						// Init Command 처리 없이 Custom OUT 데이터가 먼저 들어올 수 있다.
						// 이 경우에는 여기서 Ready 를 체크 해줘야 한다.
						g_Ready = I2C_READY;

						// Custom App 를 사용해서 F/W Download 를 했을 경우 Custom OUT 을 마지막으로
						// 장치가 Reboot 되는데 이후에 Init Command 없이 곧 바로 Touch 가 동작할 수 있어야 한다.
						// 그래서 Delay 작업을 하면 안 된다.
						g_DelayCheck = 1;
					}
#endif
					break;
				}
			}

			memset(g_RxCommand, 0, 100);
			g_RxCommandIndex = 0;
		}

		// Touch, Custom, Pen
		else if (g_CheckComplete_Common_I2C == DMA_NOT_READY)
		{
			g_CheckComplete_Common_I2C = DMA_READY;
			g_GpioDisable = I2C_GPIO_DISABLE;
		}

#ifdef MODE_I2C
		GetDelayTime();
#endif

		if (g_Ready == I2C_READY)
		{
			g_Ready_Complete = I2C_READY;
		}
		else
		{
			g_Ready_Complete = I2C_NOT_READY;
			g_StartTime_I2C = 0;
			g_DelayTime = 0;
		}

		if (g_GpioDisable == I2C_GPIO_DISABLE)
		{
			// Check GPIO Interrupt
			if (IS_GPIO_PIN(_GPIO_TP_INTR) == GPIO_DATA_LOW)
			{
				// Disable GPIO Interrupt
				GPIO_Set_DATA(_GPIO_TP_INTR, GPIO_DATA_HIGH);
			}

			g_GpioDisable = I2C_GPIO_NORMAL;
		}

#ifdef MODE_I2C
		// Reset 명령에 대한 응답을 준비한다.
		if (g_bReset == I2C_RESET)
		{
			Make_EmptyI2CData();
		}
#endif
#endif
	}
	else if (I2C->I2C_GLB_SR.tBit.I2cItrptState == I2C_ADDR_ITRPT)
	{
		if (g_ConnectedDevice > I2C_CONNECT_PC)
		{
			if (rmi_read_ptr)
			{
				I2C->I2C_TXFIFO_DATA = *(rmi_read_ptr++);
				if (protocol_ClearInterrupt != NULL)
				{
					(*protocol_ClearInterrupt)(usRegAddr + i2c_sent_byte);
				}

				i2c_sent_byte++;
			}
		}
	}

I2C_IRQHANDLER__GOTO_END:

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

	/*
	 * ISP모드가 아닐 경우에만 I2C초기화를 수행한다.
	 */
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

#ifdef I2C_SELECTIVE_SUSPEND
	// Sleep Interrupt Enable
	I2C->I2C_SET_PWR_INT.tBit.SleepItrptEn = 1;

	// WakeUp Interrupt Enable
	I2C->I2C_SET_PWR_INT.tBit.WakeUpItrptEn = 1;

	// Power Reg
	I2C->I2C_SET_PWR_REG.tBit.SetPwrRegLSBFirst = 0;
	I2C->I2C_SET_PWR_REG.tBit.SetPwrRegMSB = (uint8_t)I2C_COMMAND_REGISTER;
	I2C->I2C_SET_PWR_REG.tBit.SetPwrRegLSBSleep = 0;
	I2C->I2C_SET_PWR_REG.tBit.SetPwrRegLSBOn = 1; // 현재는 Wakeup 상태

	// Power Command
	I2C->I2C_SET_PWR_CMD.tBit.SetPwrCmdEn = 1;
	I2C->I2C_SET_PWR_CMD.tBit.SetPwrLSBFirst = 0;
	I2C->I2C_SET_PWR_CMD.tBit.SetPwrCmdMSB = I2C__REQUEST_REPORT_POWER_STATE__SLEEP; // Sleep 명령이 오길 기다린다.
	I2C->I2C_SET_PWR_CMD.tBit.SetPwrCmdLSB = I2C__REQUEST_OPCODE__SET_POWER;
#endif
}

void I2C_DeInitialize(void)
{
//	tCK_ENA_RUN0_t tLocal_CK_ENA_RUN0;
//	Fncp_I2C_SLV_IRQHandler = NULL;
//	/*
//	 * ISP모드가 아닐 경우에만 I2C초기화를 수행한다.
//	 */
//	// I2C SLAVE Setting
//	NVIC_DisableIRQ(I2C_SLV_IRQn);    /* Interrupt Disable */
//	tLocal_CK_ENA_RUN0.ulBulk = SCRB->CK_ENA_RUN0.ulBulk;
//	tLocal_CK_ENA_RUN0.tBit.r_I2C_CLK_ENA = 0;
//	tLocal_CK_ENA_RUN0.tBit._VECTKEY = SCB_VECTKEY_VALUE;
//	SCRB->CK_ENA_RUN0.ulBulk = tLocal_CK_ENA_RUN0.ulBulk;
}

