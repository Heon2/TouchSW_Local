/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : env_defines.h
 * created on : 14. 5. 2019
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


#ifndef _ENV_DEFINES_H_
#define _ENV_DEFINES_H_


/****************************************************************************************
 *                              Define Of Panel Vender
 ****************************************************************************************/
#define MODULE_DEF_S_1						(0x00010000)
#define MODULE_DEF_B_1						(0x00020000)
#define MODULE_DEF_INX_1					(0x00040000)
#define MODULE_DEF_T_1						(0x00080000)
#define MODULE_DEF_A_1						(0x00100000)
//#define MODULE_DEF_					(0x00200000)
//#define MODULE_DEF_					(0x00400000)
//#define MODULE_DEF_					(0x00800000)
//#define MODULE_DEF_					(0x01000000)
//#define MODULE_DEF_					(0x02000000)
//#define MODULE_DEF_					(0x04000000)
//#define MODULE_DEF_					(0x08000000)
//#define MODULE_DEF_					(0x10000000)
//#define MODULE_DEF_					(0x20000000)
//#define MODULE_DEF_					(0x40000000)
//#define MODULE_DEF_					(0x80000000)
#define USED_MODULE_DEF						(MODULE_DEF_B_1)


#define IS_MODULE_DEF_S_1(M)				(MODULE_DEF_S_1 & (M))
#define IS_MODULE_DEF_B_1(M)				(MODULE_DEF_B_1 & (M))
#define IS_MODULE_DEF_INX_1(M)				(MODULE_DEF_INX_1 & (M))
#define IS_MODULE_DEF_T_1(M)				(MODULE_DEF_T_1 & (M))
#define IS_MODULE_DEF_A_1(M)				(MODULE_DEF_A_1 & (M))
//#define IS_MODULE_DEF_(M)				(MODULE_DEF_ & (M))
//#define IS_MODULE_DEF_(M)				(MODULE_DEF_ & (M))
//#define IS_MODULE_DEF_(M)				(MODULE_DEF_ & (M))
//#define IS_MODULE_DEF_(M)				(MODULE_DEF_ & (M))
//#define IS_MODULE_DEF_(M)				(MODULE_DEF_ & (M))
//#define IS_MODULE_DEF_(M)				(MODULE_DEF_ & (M))
//#define IS_MODULE_DEF_(M)				(MODULE_DEF_ & (M))
/****************************************************************************************
 *                              Define Of Active Stylus Pen Protocol
 ****************************************************************************************/
#define PEN_PROTOCOL_MULTI_PROTOCOL_OPERATION			(0x00010000)
#define PEN_PROTOCOL_MS_PEN								(1)
#define PEN_PROTOCOL_WACOM_PEN							(2)
#define PEN_PROTOCOL_MSnWACOM_PEN						(PEN_PROTOCOL_MULTI_PROTOCOL_OPERATION | 3)
#define PEN_PROTOCOL_WGP_PEN							(4)
#define PEN_PROTOCOL_MSnWGP_PEN							(PEN_PROTOCOL_MULTI_PROTOCOL_OPERATION | 5)
#define PEN_PROTOCOL_WGP_UHD_PEN						(6)

/****************************************************************************************
 *                              Define Of ROIC Define
 ****************************************************************************************/
#define ROIC_SW97500						(1)
#define ROIC_SW92502						(2)
#define ROIC_SW92503						(3)
#define ROIC_SW92503S						(4)
#define ROIC_SW92503B						(5)
#define ROIC_SW98500						(7)
#define ROIC_SW92505						(9)
#define ROIC_SW98502						(10)
#define ROIC_SW92510						(11)
#define ROIC_SW92508						(12)
#define ROIC_SW92509						(13)
#define ROIC_SW92512						(14)
#define ROIC_SW92511						(15)
#define ROIC_SW92513						(16)

/****************************************************************************************
 *                              Define Of Sensing Frequency
 ****************************************************************************************/
#define PWMDRV_FREQUENCY_80K				(80)
#define PWMDRV_FREQUENCY_86K				(86)
#define PWMDRV_FREQUENCY_91K				(91)
#define PWMDRV_FREQUENCY_112K				(112)
#define PWMDRV_FREQUENCY_114K				(114)
#define PWMDRV_FREQUENCY_133K				(133)

#include "boot_info.h"

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
#include "env_model_S/env_model.h"
#elif (USED_MODULE_DEF == MODULE_DEF_B_1)
#include "env_model_B/env_model.h"
#elif (USED_MODULE_DEF == MODULE_DEF_INX_1)
#include "env_model_INX/env_model.h"
#elif (USED_MODULE_DEF == MODULE_DEF_T_1)
#include "env_model_T/env_model.h"
#elif (USED_MODULE_DEF == MODULE_DEF_A_1)
#include "env_model_A/env_model.h"
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

#define IS_ROIC_DEF_SW97500					(USED_ROIC_DEF == ROIC_SW97500)
#define IS_ROIC_DEF_SW92502					(USED_ROIC_DEF == ROIC_SW92502)
#define IS_ROIC_DEF_SW92503					(USED_ROIC_DEF == ROIC_SW92503)
#define IS_ROIC_DEF_SW92503S				(USED_ROIC_DEF == ROIC_SW92503S)
#define IS_ROIC_DEF_SW92503B				(USED_ROIC_DEF == ROIC_SW92503B)
#define IS_ROIC_DEF_SW98500					(USED_ROIC_DEF == ROIC_SW98500)
#define IS_ROIC_DEF_SW92505					(USED_ROIC_DEF == ROIC_SW92505)
#define IS_ROIC_DEF_SW98502					(USED_ROIC_DEF == ROIC_SW98502)
#define IS_ROIC_DEF_SW92510					(USED_ROIC_DEF == ROIC_SW92510)
#define IS_ROIC_DEF_SW92508					(USED_ROIC_DEF == ROIC_SW92508)
#define IS_ROIC_DEF_SW92509					(USED_ROIC_DEF == ROIC_SW92509)
#define IS_ROIC_DEF_SW92512					(USED_ROIC_DEF == ROIC_SW92512)
#define IS_ROIC_DEF_SW92511					(USED_ROIC_DEF == ROIC_SW92511)
#define IS_ROIC_DEF_SW92513					(USED_ROIC_DEF == ROIC_SW92513)


#define IS_MULTI_PROTOCOL_OPERATION			(USED_PEN_PROTOCOL & PEN_PROTOCOL_MULTI_PROTOCOL_OPERATION)
#define IS_WGPPEN_PROTOCOL_OPERATION		(USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
#define IS_WGPUHDPEN_PROTOCOL_OPERATION		(USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
#define IS_MSPEN_PROTOCOL_OPERATION			(USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN)
#define IS_WACOMPEN_PROTOCOL_OPERATION		(USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN)

#define IS_NOT_WGPPEN_PROTOCOL_OPERATION		(USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_PEN)
#define IS_NOT_WGPUHDPEN_PROTOCOL_OPERATION		(USED_PEN_PROTOCOL != PEN_PROTOCOL_WGP_UHD_PEN)
#define IS_NOT_MSPEN_PROTOCOL_OPERATION			(USED_PEN_PROTOCOL != PEN_PROTOCOL_MS_PEN)
#define IS_NOT_WACOMPEN_PROTOCOL_OPERATION		(USED_PEN_PROTOCOL != PEN_PROTOCOL_WACOM_PEN)

#define DEFAULT_X_RESOLUTION				(32768)
#define DEFAULT_Y_RESOLUTION				(32768)


#define ACCESS_MATRIX(_p, _col_, _r, _c)    (*((_p)+(_col_)*(_r)+(_c)))
#define POW(a)                              (a)
#define SQRT(a)								algorithm_calc_sqrt(POW(a))

/***************************************************************************************************************************************
 * typedef enum
 ***************************************************************************************************************************************/
typedef enum
{
    OM_NORMAL,
    OM_NOISE,
    OM_DIAG,
    OM_LIMIT
} __PACKED eOperMode_t; //TODO:

typedef enum
{
	FULL_MODE = 0,
	LOCAL_MODE,					// 1
	LOCAL_FINGER_MODE,			// 2
	LOCAL_HOVER_MODE,			// 3
	LOCAL_SEARCH_MODE,			// 4
	LOCAL_RING_MODE,	      // 5
	LOCAL_TILT_MODE,
} __PACKED eSensingMode_t;

typedef enum
{
	PEN_COORD_INIT = 1,				// 1
	PEN_LINE_FILTER,	
#ifdef CalculateDeltaLocalSearch_OPCODE
	PEN_CAL_DELTA,
#endif	
	PEN_NOISE_REDUCTION,
	PEN_LABELING,					
	DSP_MARKBOUNDARY1,	
#if (DeltaBaseNewEdgeCompen_SW == NO)	
	PEN_COORDINATE_EDGE_PROCESSING,
#endif
	PEN_COORDINATE,		
#if 1//(USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)
#ifdef TILT_OPCODE
	PEN_CALCULATION_TILT_H,
	PEN_CALCULATION_TILT_X,
	PEN_CALCULATION_TILT_Y,
	PEN_CALCULATION_TILT_PHI,
	PEN_TILT_FILTER,
	//PEN_TILT_PEN2REPORT,
	PEN_TILT_PEN2_ORG_COORD_PREDIC,
#endif
#endif
	PEN_SMOOTHING,	
	PEN_DIS_BASE_SMOOTHING_ADD,
	PEN_POST_PROCESS,	
	PEN_UPDATE_POST_INFO,	
} __PACKED eDSPBMode_t;

/***************************************************************************************************************************************
 * typedef structure
 ***************************************************************************************************************************************/
//typedef struct
//{
//    int iRow_;
//    int iCol_;
//    int iRamCol_;
//    int iScreenNode_;
//    int iKey_;
//    int iMaxTouch_;
//    bool_t bSwapXY;
//    bool_t bFlipX;
//
//} tMemConf_t;

/***************************************************************************************************************************************
 * Variables
 ***************************************************************************************************************************************/
//extern tMemConf_t *ptMemConf;
//extern tMemConf_t* ptMemLocalConf;
extern volatile uint8_t* pucBuf;



#define waitTsyncHigh()							while(TSYNC_HIGH == 0)
#define waitTsyncLow()							while(TSYNC_HIGH != 0)
#define waitTsyncRising() \
	do{ \
		waitTsyncLow(); \
		waitTsyncHigh(); \
	}while(0)

#define waitTsyncFalling() \
	do{ \
		waitTsyncHigh(); \
		waitTsyncLow(); \
	}while(0)

#define waitVsyncHigh()							while(VSYNC_HIGH == 0)
#define waitVsyncLow()							while(VSYNC_HIGH != 0)
#define waitVsyncRising() \
	do{ \
		waitVsyncLow(); \
		waitVsyncHigh(); \
	}while(0)

#define waitVsyncFalling() \
	do { \
		waitVsyncHigh(); \
		waitVsyncLow(); \
	}while(0)


#if (USED_ROIC_DEF == ROIC_SW97500)
typedef struct
{
	uint16_t Addr;
//	uint16_t reserved0;

	union
	{
		struct
		{
			uint16_t Dummy		:7;
			uint16_t Burst_Len 	:7;
			uint16_t CKS 		:1; // Checksum
			uint16_t RW 		:1;
		} tBit;
		uint16_t Command;
	};
//	uint16_t reserved2;

	uint16_t Data_M;
//	uint16_t reserved3;
	uint16_t Data_L;
//	uint16_t reserved4;
} tMSPI_Reg_WriteBuf_t;

typedef struct
{
//	uint16_t Dummy[2];
	uint32_t Data;
	uint32_t Dummy;
} tMSPI_Reg_ReadBuf_t;

#define SW97500_ADDR_CMD_NUM		(2)
#define SW97500_R0_RAW_CH_NUM		(25)
#define SW97500_R0_DUM_CH_NUM		(3)
#define SW97500_BROADCAST_NUM		(4)

typedef struct _ReadCommand_Buf_
{
    uint16_t Addr       ;
//    uint16_t reserved0  ;

    union{
        struct
        {
			uint16_t Dummy		:7;
			uint16_t Burst_Len 	:7;
			uint16_t CKS 		:1;
			uint16_t RW 		:1;
        } tBit;
        uint16_t Command;
    };
//    uint16_t reserved2 ;

    uint32_t Data[SW97500_ADDR_CMD_NUM + ((SW97500_R0_RAW_CH_NUM + SW97500_R0_DUM_CH_NUM) * SW97500_BROADCAST_NUM)];
} MSPI_ReadCommand_TypeDef;

typedef struct _MSPI_RAWDATA_
{
    uint16_t Data[((SW97500_R0_RAW_CH_NUM + SW97500_R0_DUM_CH_NUM) * SW97500_BROADCAST_NUM)];
} MSPI_Rawdata_Typedef;

typedef struct MSPI_Buffer
{
	tMSPI_Reg_WriteBuf_t SricRegWriteBuffer[MSPI_NUM];
	tMSPI_Reg_ReadBuf_t SricRegReadBuffer[MSPI_NUM];
//    uint32_t ulDummy[512];
    MSPI_ReadCommand_TypeDef ReadCommand[MSPI_NUM];
    MSPI_Rawdata_Typedef Rawdata[MSPI_NUM][MSPI_ROW_MAX_MUX];
} MSPI_Buffer_TypeDef;

#elif ((USED_ROIC_DEF == ROIC_SW98500) || (USED_ROIC_DEF == ROIC_SW98502) || (USED_ROIC_DEF == ROIC_SW92510) || (USED_ROIC_DEF == ROIC_SW92508) || (USED_ROIC_DEF == ROIC_SW92509) || (USED_ROIC_DEF == ROIC_SW92511) || (USED_ROIC_DEF == ROIC_SW92512) || (USED_ROIC_DEF == ROIC_SW92513))
typedef struct
{
    uint16_t Addr;

    union {
        struct
        {
            uint16_t Dummy : 1;
            uint16_t ExtCMDEnOr : 1;
            uint16_t ExtCMDEnst : 1;
            uint16_t Burst_Len : 7;
            uint16_t ReadFormat : 2;
            uint16_t ExtCMDEn : 1;
            uint16_t DualRxEn : 1;
            uint16_t ChkSum : 1;
            uint16_t RW : 1;
        } tBit;
        uint16_t Command;
    };

    uint16_t Data_M;
    uint16_t Data_L;
} tMSPI_Reg_WriteBuf_t;

typedef struct
{
    //	uint16_t Dummy[2];
    uint32_t Data;
} tMSPI_Reg_ReadBuf_t;

#define SW97500_ADDR_CMD_NUM (2)
#define SW97500_R0_RAW_CH_NUM (25)
#define SW97500_R0_DUM_CH_NUM (3)
#define SW97500_BROADCAST_NUM (4)

typedef struct _ReadCommand_Buf_
{
#if USED_SPI_NBIT_TRANSMODE
	union {
		struct
		{
			uint16_t Dummy : 1;
			uint16_t ExtCMDEnOr : 1;
			uint16_t ExtCMDEnst : 1;
			uint16_t Burst_Len : 7;
			uint16_t ReadFormat : 2;
			uint16_t ExtCMDEn : 1;
			uint16_t DualRxEn : 1;
			uint16_t ChkSum : 1;
			uint16_t RW : 1;
		} tBit;
		uint16_t Command;
	};
	uint16_t Addr;
#else /* USED_SPI_NBIT_TRANSMODE */
	uint16_t Addr;
	union {
		struct
		{
			uint16_t Dummy : 1;
			uint16_t ExtCMDEnOr : 1;
			uint16_t ExtCMDEnst : 1;
			uint16_t Burst_Len : 7;
			uint16_t ReadFormat : 2;
			uint16_t ExtCMDEn : 1;
			uint16_t DualRxEn : 1;
			uint16_t ChkSum : 1;
			uint16_t RW : 1;
		} tBit;
		uint16_t Command;
	};
#endif /* USED_SPI_NBIT_TRANSMODE */
    uint32_t Data[MSPI_WGPPEN_ALIGNED_COL_LEN * MSPI_WGPPEN_ALIGNED_ROW_LEN + MSPI_WGPPEN_ALIGNED_DUMMY];
} MSPI_ReadCommand_TypeDef;

typedef struct _MSPI_RAWDATA_
{
    uint16_t Data[MSPI_WGPPEN_ALIGNED_COL_LEN * MSPI_WGPPEN_ALIGNED_ROW_LEN + MSPI_WGPPEN_ALIGNED_DUMMY];
} MSPI_Rawdata_Typedef;

typedef struct MSPI_Buffer
{
    tMSPI_Reg_WriteBuf_t SricRegWriteBuffer[MSPI_NUM];
    tMSPI_Reg_ReadBuf_t SricRegReadBuffer[MSPI_NUM];
    uint32_t ulDummy[512];
    MSPI_ReadCommand_TypeDef ReadCommand[MSPI_NUM];
	#if USED_ESD_RECOVERY_SENSING_WITHOUT_MODULATION
		MSPI_Rawdata_Typedef Rawdata[MSPI_NUM][FINGER_ESD_SCAN_MUX_NUM + MSPI_ROW_MAX_MUX];
	#else
		MSPI_Rawdata_Typedef Rawdata[MSPI_NUM][MSPI_ROW_MAX_MUX];
	#endif
} MSPI_Buffer_TypeDef;

#elif (USED_ROIC_DEF == ROIC_SW92502)
typedef struct
{
    uint16_t Addr       ;
    uint16_t reserved0  ;

    union
    {
        struct
        {
            uint16_t dummy		: 14;
            uint16_t CKS		:  1; // Checksum
            uint16_t RW			:  1; // Read 1, Write 0
        } tBit;
        uint16_t Command;
    };
    uint16_t reserved2 ;

    uint16_t Data;
    uint16_t reserved3;

} tMSPI_Reg_WriteBuf_t;

typedef struct
{
    uint16_t Addr       ;
    uint16_t reserved0  ;

    union{
        struct
        {
        	uint16_t CurrentLHBIdx	:5;
        	uint16_t NextLHBMode	:3;
        	uint16_t Reserved		:4;
			uint16_t Dummy			:1;
			uint16_t Extend 		:1;
			uint16_t CKS 			:1; // Checksum
			uint16_t RW 			:1; // Read 1, Write 0
        } tBit;
        uint16_t Command;
    };
    uint16_t reserved2;

    uint16_t Data[SZ_MSPIBUF_MUXDATA*2];
} MSPI_ReadCommand_TypeDef;

typedef struct
{
    uint32_t Dummy;
    uint16_t Data[SM_NUM][ROIC_ALIGNED_ROW_LEN][ROIC_ALIGNED_COL_LEN];
} MSPI_Rawdata_Typedef;

typedef struct
{
    tMSPI_Reg_WriteBuf_t SricBuffer[2][MSPI_NUM];
    MSPI_ReadCommand_TypeDef ReadCommand[MSPI_NUM];
    MSPI_Rawdata_Typedef Rawdata[MSPI_NUM][FINGER_MUX_NUM];
} MSPI_Buffer_TypeDef;
#elif (USED_ROIC_DEF == ROIC_SW92503 || USED_ROIC_DEF == ROIC_SW92503S || USED_ROIC_DEF == ROIC_SW92503B || USED_ROIC_DEF == ROIC_SW92505)
typedef struct
{
	uint16_t Addr;

	union
	{
		struct
		{
			uint16_t Dummy		:4;
			uint16_t Burst_Len	:7;
			uint16_t ReadFormat	:1;
			uint16_t ExtCMDEn	:1;
			uint16_t DualRxEn	:1;
			uint16_t ChkSum		:1;
			uint16_t RW			:1;
		} tBit;
		uint16_t Command;
	};

	uint16_t Data_M;
	uint16_t Data_L;
} tMSPI_Reg_WriteBuf_t;

typedef struct
{
//	uint16_t Dummy[2];
	uint32_t Data;
} tMSPI_Reg_ReadBuf_t;

#define SW97500_ADDR_CMD_NUM		(2)
#define SW97500_R0_RAW_CH_NUM		(25)
#define SW97500_R0_DUM_CH_NUM		(3)
#define SW97500_BROADCAST_NUM		(4)

typedef struct _ReadCommand_Buf_
{
    uint16_t Addr       ;

    union{
        struct
        {
			uint16_t Dummy		:4;
			uint16_t Burst_Len	:7;
			uint16_t ReadFormat	:1;
			uint16_t ExtCMDEn	:1;
			uint16_t DualRxEn	:1;
			uint16_t ChkSum		:1;
			uint16_t RW			:1;
        } tBit;
        uint16_t Command;
    };

    uint32_t Data[MSPI_WGPPEN_ALIGNED_COL_LEN*MSPI_WGPPEN_ALIGNED_ROW_LEN+MSPI_WGPPEN_ALIGNED_DUMMY];
} MSPI_ReadCommand_TypeDef;

typedef struct _MSPI_RAWDATA_
{
    uint16_t Data[MSPI_WGPPEN_ALIGNED_COL_LEN*MSPI_WGPPEN_ALIGNED_ROW_LEN+MSPI_WGPPEN_ALIGNED_DUMMY];
} MSPI_Rawdata_Typedef;

typedef struct MSPI_Buffer
{
	tMSPI_Reg_WriteBuf_t SricRegWriteBuffer[MSPI_NUM];
	tMSPI_Reg_ReadBuf_t SricRegReadBuffer[MSPI_NUM];
    uint32_t ulDummy[512];
    MSPI_ReadCommand_TypeDef ReadCommand[MSPI_NUM];
    MSPI_Rawdata_Typedef Rawdata[MSPI_NUM][MSPI_ROW_MAX_MUX];
} MSPI_Buffer_TypeDef;

#endif /* (USED_ROIC_DEF == ROIC_SW97500) */


typedef enum {
	_FREQ_UNKNOWN_ = 0,
	_FREQ_80k_ = 1,
	_FREQ_86k_ = 2,
	_FREQ_91k_ = 3,
	_FREQ_112k_ = 4,
	_FREQ_114k_ = 5,
	_FREQ_133k_ = 6,

} eSENSING_FREQ_t;

#define MSPI_BUF			((volatile MSPI_Buffer_TypeDef              *)BASE_RAW_SRAM    )
#define MSPI_MSPEN_BUF		((volatile MSPI_MSPEN_Buffer_TypeDef        *)BASE_RAW_SRAM    )
#define MSPI_WACOMPEN_BUF	((volatile MSPI_WACOMPEN_Buffer_TypeDef     *)BASE_RAW_SRAM    )

#define __inline__

#endif /* _ENV_DEFINES_H_ */
