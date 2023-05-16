/******************************************************************************************************
 * Copyright (c) 2022 - 2050 LX Semicon LIMITED
 *
 * file : DSP_B_code_2.h
 * created on : 24. 03. 2022
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

#ifndef _DSP_B_CODE_2_H_
#define _DSP_B_CODE_2_H_

#if (USED_MPP_Pen_Protocol_Process_Change == YES)
typedef union {
	struct {
		// First Symbol 6bit Info
		uint32_t Aware:				2;
		uint32_t Ring:				2;
		uint32_t PenNumber: 		2;
	} tBit;
	uint32_t Byte;
} eMPP25_1stLS_t;

typedef union {
	struct {
		// Second Symbol 6bit Info
		uint32_t HeaderProtection:	2;
		uint32_t Header:			4;
	} tBit;
	uint32_t Byte;
} eMPP25_2ndLS_t;

typedef union {
	struct {
		// Third Symbol 6bit Info
		uint32_t Parity:			1;
		uint32_t Pressure:			5;
	} tBit;
	uint32_t Byte;
} eMPP25_3rdLS_t;

typedef union {
	struct {
		// 4th Full Format Symbol 6bit Info
		uint32_t Parity:			1;
		uint32_t Data:				5;
	} tFullBit;
	struct {
		// 4th Norm Format Symbol 6bit Info
		uint32_t Parity:			1;
		uint32_t Data:				1;
		uint32_t Pressure:			4;
	} tNormBit;
	uint32_t Byte;
} eMPP25_4thLS_t;

typedef union {
	struct {
		// 5th Full Format Symbol 6bit Info
		uint32_t Parity:			1;
		uint32_t Data:				3;
		uint32_t HI:				2;
	} tFullBit;
	struct {
		// 5th Norm Format Symbol 6bit Info
		uint32_t Parity:			1;
		uint32_t Data:				3;
		uint32_t HI:				2;
	} tNormBit;
	uint32_t Byte;
} eMPP25_5thLS_t;

typedef union {
	struct {
		// 6th Full Format Symbol 6bit Info
		uint32_t Parity:			1;
		uint32_t Data:				5;
	} tFullBit;
	struct {
		// 6th Norm Format Symbol 6bit Info
		uint32_t Parity:			1;
		uint32_t Data:				3;
	} tNormBit;
	uint32_t Byte;
} eMPP25_6thLS_t;

typedef union {
	struct {
		// 7th Full Format Symbol 6bit Info
		uint32_t Parity:			1;
		uint32_t Pressure:			1;
		uint32_t Data:				2;
		uint32_t HI:				2;
	} tFullBit;
	struct {
		// 7th Norm Format Symbol 6bit Info
		uint32_t Parity:			1;
		uint32_t Pressure:			3;
		uint32_t HI:				2;
	} tNormBit;
	uint32_t Byte;
} eMPP25_7thLS_t;

typedef union {
	struct {
		// 7th Full Format Symbol 6bit Info
		uint32_t Parity:			1;
		uint32_t Data:				3;
		uint32_t HI:				2;
	} tFullBit;
	struct {
		// 7th Norm Format Symbol 6bit Info
		uint32_t Parity:			1;
		uint32_t Data:				3;
		uint32_t HI:				2;
	} tNormBit;
	uint32_t Byte;
} eMPP25_8thLS_t;

typedef struct {
	eMPP25_1stLS_t e1stLS;
	eMPP25_2ndLS_t e2ndLS;
	eMPP25_3rdLS_t e3rdLS;
	eMPP25_4thLS_t e4thLS;
	eMPP25_5thLS_t e5thLS;
	eMPP25_6thLS_t e6thLS;
	eMPP25_7thLS_t e7thLS;
	eMPP25_8thLS_t e8thLS;

} tMPP25DataStructInfo_t;

typedef enum {
	MPP25_FULL_Format = 0,
	MPP25_NORM_Format = 1,
	MPP25_NC_Format = 1,
} eFrameFormt_t;

typedef enum {
	MPP25_PenNumber_None = 		1,
	MPP25_PenNumber_1 = 		0,
	MPP25_PenNumber_2 = 		3,
	MPP25_PenNumber_Reserved = 	2,
} ePenNumber_t;

typedef enum {
	MPP25_Hover = 				0,
	MPP25_Ink = 				3,
	MPP25_Reserved1 = 			1,
	MPP25_Reserved2 = 			2,
} ePenHI_t;

typedef enum {
	MPP25_Message_No = 			0,
	MPP25_Massage_Yes = 		3,
	MPP25_Massage_Reserved1 =	1,
	MPP25_Massage_Reserved2 =	2,
} ePenAware_t;

typedef enum {
	MPP25_Tip =					0,
	MPP25_Ring = 				3,
	MPP25_Reserved3 =			1,
	MPP25_Reserved4 = 			2,
} ePenRing_t;

typedef enum {
	MPP25_MessageType_Norm_Pen_Status 	= 0x0A,
	MPP25_MessageType_FULL_ID_First		= 0x2C,
	MPP25_MessageType_FULL_ID_Continue	= 0x33,
	MPP25_MessageType_FULL_Preference	= 0x34,
	MPP25_MessageType_Reserved,
} ePenDataHeader_t;

typedef enum {
	MPP25_Button_TailEraser =		2,
	MPP25_Button_FronRightClik =	1,
	MPP25_Button_No =				3,
	MPP25_Button_Reserved =			0,
} ePenButton_t;

typedef enum {
	MPP25_Status_Buttons =			0,
	MPP25_Status_Battery =			1,
	MPP25_Status_Application_Ack =	2,
	MPP25_Status_Reerved =			3,
} ePenStatusTypes_t;

//typedef enum {
//	MPP25_ButtonStatusData
//};
//typedef enum {
//	MPP25_ButtonStatus_Buttons =	0,
//	MPP25_Status_Battery =			1,
//	MPP25_Status_Application_Ack =	2,
//	MPP25_Status_Reerved =			3,
//} ePenButtonStatusData_t;

typedef union {
	struct {
		/*
		 * ID First 		Pen ID[31:20]
		 * ID Continue 1 	Pen ID[19:8]
		 */
		uint32_t PenID: 		12;
		uint32_t Reserved: 		4;
		uint32_t FastButtons: 	2;
	} tBit;

	struct {
		/*
		 * ID Continue 2	Pen ID[7:0], CRC-4[3:0]
		 */
		uint32_t CRC_4: 		4;
		uint32_t PenID: 		8;
		uint32_t Reserved: 		4;
		uint32_t FastButtons: 	2;
	} tBit_2;

	uint32_t data; // 18bit
} tMPP25Data_FullFormat_t;

typedef union {
	struct {
		uint32_t Reserved: 				2;
		uint32_t Status_Type:			3;
		union {
			struct {
				uint32_t Reserved2:			3;
				uint32_t Tail_Tip:			1;
				uint32_t Eraser:			1;
				uint32_t RighClick:			1;
				uint32_t Reserved:			1;
			}tButton;
			struct {
				uint32_t AckType:			3;
				uint32_t Echo:				4;
			}tAppAck;
			struct {
				uint32_t Level:				7; // 0 ~ 100 Level
			}tBettery;
			uint32_t Data:		 			7;
		} uStatus_Data;
//		uint32_t Button_Status_Data:	7;
	} tBit;
	uint32_t data; // 12Bit
} tMPP25Data_NormFormat_t;

typedef union {
	tMPP25Data_FullFormat_t tFullFormat;
	tMPP25Data_NormFormat_t tNormFormat;
	uint32_t word;
} tMPP25DataInfo_t;

typedef struct {
	eFrameFormt_t eFormat;

	ePenAware_t ePenAware;
	ePenRing_t ePenRing;
	ePenNumber_t ePenNumber;

	ePenDataHeader_t ePenDataHeader;
	ePenDataHeader_t ePenDataPrevHeader;

	ePenButton_t ePenButton;

	uint32_t ulPrevPenID;
	uint32_t ulPenID;
	uint32_t ulPenID_CRC;

	ePenHI_t ePenHI;
	uint32_t ulPressure;

} tMPP25PenInfo_t;


extern void DSP_B_code_2_Init(void);
extern bool_t algorithm_local_data_baseline_calculate_delta_MPP25_Structure(ePartialSensing_t RetVal);
#endif /* (USED_MPP_Pen_Protocol_Process_Change== YES) */
#endif /* _DSP_B_CODE_2_H_ */
