/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : env_defines.h
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


#ifndef _ENV_DEFINES_H_
#define _ENV_DEFINES_H_

#include "boot_info.h"

//#define _USE_APP_LGD_LIB_

#if defined(USE_BOOTLOADER_8KB)
	#define	VECTOR_BASE	0x00002000
#elif defined(USE_BOOTLOADER_16KB)
	#define	VECTOR_BASE	0x00004000
#else
	#define	VECTOR_BASE	0x00000000
#endif


#define MODULE_DEF_L						(1)
#define MODULE_DEF_S_1						(2)
#define MODULE_DEF_B_1						(3)
#define USED_ONLY_KEIL_DEBUG				(YES)
#define USED_MODULE_DEF						(MODULE_DEF_L)

#define PWMDRV_FREQUENCY_50K				(1)
#define PWMDRV_FREQUENCY_91K				(2)
#define PWMDRV_FREQUENCY_133K				(3)
#define PWMDRV_FREQUENCY_150K				(4)
#define PWMDRV_FREQUENCY_200K				(5)

#define PLL_OUT_CLOCK_96MHz					(1)
#define PLL_OUT_CLOCK_90MHz					(2)
#define PLL_OUT_CLOCK_45MHz					(3)
#define PLL_OUT_CLOCK_37p5MHz				(4)
#define PLL_OUT_CLOCK_31p5MHz				(5)

#define MSPI_CLOCK_DIV_2					(1)
#define MSPI_CLOCK_DIV_3					(2)

#include "env_model_L/env_model.h"

#define USED_MUX_SENSING_REVERSE		(NO)

#if USED_SPEED_MESURE
#define USED_SPEED_MESURE_TOUCHNUM			(10)
#endif /* USED_SPEED_MESURE */


#if (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz)
#define MSPI_CLOCK_DIV						(MSPI_CLOCK_DIV_3) // 16M
#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_90MHz)
#define MSPI_CLOCK_DIV						(MSPI_CLOCK_DIV_3) // 15M
#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_45MHz)
#define MSPI_CLOCK_DIV						(MSPI_CLOCK_DIV_2) // 11.3M
#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_37p5MHz)
#define MSPI_CLOCK_DIV						(MSPI_CLOCK_DIV_2) // 9.4M
#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_31p5MHz)
#define MSPI_CLOCK_DIV						(MSPI_CLOCK_DIV_2) // 7.9M
#else /* (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) */
#define PLL_OUT_CLOCK_SPEED					(PLL_OUT_CLOCK_90MHz)
#define MSPI_CLOCK_DIV						(MSPI_CLOCK_DIV_3) // 15M
#endif /* (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) */


#if USED_OPERATION_STAND_ALONE
#define USED_ONE_VSYNC_ONE_FRAME			(YES)

#define USED_NOT_USE_ALL_AFE_OFF			(NO)
#define USED_LPWG_CROSS_AFE_OFF				(NO)
#define USED_LREDGE_AFE_OFF					(NO)
#define USED_PLL_OUT_CLK_CONFIG				(YES)
#define VSYNC_ONE_FRAME_RATE_HZ				(20)
#define VSYNC_ONE_FRAME_TIME_usec			(1000000/VSYNC_ONE_FRAME_RATE_HZ)
#define TSYNC_ONE_FRAME_RATE_HZ				(70)//(80)
#define TSYNC_ONE_FRAME_TIME_usec			(1000000/TSYNC_ONE_FRAME_RATE_HZ)
#define TSYNC_LHB_NUM						(16)
#define TSYNC_PRIOD							(TSYNC_ONE_FRAME_TIME_usec/TSYNC_LHB_NUM)
#else /* USED_OPERATION_STAND_ALONE */
#define USED_ONE_VSYNC_ONE_FRAME			(NO)
#define USED_NOT_USE_ALL_AFE_OFF			(NO)
#define USED_LPWG_CROSS_AFE_OFF				(NO)
#define USED_PLL_OUT_CLK_CONFIG				(NO)
#endif /* USED_OPERATION_STAND_ALONE */

#define USED_SRIC_REG_MSPI_CHECK			(NO)


#define DEFAULT_X_RESOLUTION				(32768)
#define DEFAULT_Y_RESOLUTION				(32768)

/***************************************************************************************************************************************
 * typedef enum
 ***************************************************************************************************************************************/
typedef enum
{
	PCS_NONE,
    PCS_ACTIVE,
    PCS_IDLE,
    PCS_LIMIT,
} __PACKED ePowerConsumptionState_t;

typedef enum
{
    OM_NORMAL,
    OM_NOISE,
    OM_DIAG,
    OM_LIMIT
} __PACKED eOperMode_t; //TODO: 이름 바꾸기!

typedef enum
{
	FULL_MODE = 0,
	LOCAL_MODE,					// 1
	LOCAL_FINGER_MODE,			// 2
	LOCAL_HOVER_MODE,			// 3
	LOCAL_SEARCH_MODE,			// 4
} __PACKED eSensingMode_t;

typedef enum
{
	PEN_COORD_INIT = 1,			// 1
	PEN_LINE_FILTER,			// 2
	PEN_LABELING,				// 3
	DSP_MARKBOUNDARY1,			// 4
	DSP_MARKBOUNDARY2,			// 5
	PEN_LABEL_EDGE_EXPAND,		// 6
	PEN_COORDINATE,				// 7
	PEN_SMOOTHING,				// 8
	PEN_POST_PROCESS,			// 9
	PEN_UPDATE_POST_INFO,		// 10
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

#if USED_SW92400_OLD_SRIC_PROTOCOL
//typedef struct
//{
//    uint16_t Addr       ;
//    uint16_t reserved0  ;
//
//    union
//    {
//        struct
//        {
//            uint16_t reserved1  : 14;
//            uint16_t nBulk      : 1;
//            uint16_t nWrite     : 1;
//        } tBit;
//        uint16_t Command;
//    };
//    uint16_t reserved2 ;
//
//    uint16_t Data;
//    uint16_t reserved3;
//} MSPI_RegWriteBuf_TypeDef;

// // LX98405 New - Choigs
typedef struct
{
    uint16_t Addr       ;
    uint16_t reserved0  ;

    union
    {
        struct
        {
            uint16_t Dummy : 3;
            uint16_t Burst_Len : 7;
            uint16_t ReadFormat : 2;
            uint16_t reserved1 : 1;
            uint16_t DualRxEn : 1;
            uint16_t ChkSum : 1;
            uint16_t RW : 1;
        } tBit;
        uint16_t Command;
    };
    uint16_t reserved2 ;

    uint16_t Data_M;
    uint16_t reserved3 ;
		
    uint16_t Data_L;
    uint16_t reserved4 ;
		
} MSPI_RegWriteBuf_TypeDef;

// // LX98405 New - Choigs
typedef struct
{
	uint16_t Data1;
	uint16_t reserved0  ;
	uint16_t Data2;
	uint16_t reserved1  ;
} MSPI_RegReadBuf_TypeDef;



//typedef struct
//{
//    union
//    {
//        uint16_t Addr       ;
//        uint16_t Readback   ;
//    };
//    uint16_t reserved0  ;
//
//    uint16_t reserved1  : 14;
//    uint16_t nBulk      : 1;
//    uint16_t nWrite     : 1;
//    uint16_t reserved2 ;
//
//    uint32_t Data[32];
//}MSPI_SensingBuf_TypeDef;

//typedef struct
//{
//    uint16_t Addr       ;
//    uint16_t reserved0  ;
//
//    union{
//        struct
//        {
//            uint16_t reserved1  : 14;
//            uint16_t nBulk      : 1;
//            uint16_t nWrite     : 1;
//        } tBit;
//        uint16_t Command;
//    };
//    uint16_t reserved2 ;
//
//    uint16_t Data[SZ_MSPIBUF_MUXDATA*2];
//}MSPI_ReadCommand_TypeDef;

// // LX98405 New - Choigs
typedef struct
{
    uint16_t Addr       ;
    uint16_t reserved0  ;

    union{
        struct
        {
				
            uint16_t Dummy : 3;
            uint16_t Burst_Len : 7;
            uint16_t ReadFormat : 2;
            uint16_t Reserve : 1;
            uint16_t DualRxEn : 1;
            uint16_t ChkSum : 1;
            uint16_t RW : 1;

        } tBit;
        uint16_t Command;
    };
    uint16_t reserved2 ;

    uint16_t Data[SZ_MSPIBUF_MUXDATA*2];
}MSPI_ReadCommand_TypeDef;


typedef struct _MSPI_RAWDATA_
{
    uint16_t Dummy[2];
    uint16_t Data[SM_NUM][R0_ALIGNED_ROW_LEN][SM_COL_LEN*2];
}MSPI_Rawdata_Typedef;

typedef struct MSPI_Buffer
{
	MSPI_RegWriteBuf_TypeDef SricRegWriteBuffer[MSPI_NUM];
	MSPI_RegReadBuf_TypeDef SricRegReadBuffer[MSPI_NUM];
    uint32_t ulDummy[512];
    MSPI_ReadCommand_TypeDef ReadCommand[MSPI_NUM];
    MSPI_Rawdata_Typedef Rawdata[MSPI_NUM][MSPI_ROW_MAX_MUX];
    MSPI_Rawdata_Typedef PenRawdata[MSPI_NUM][FINGERPEN_MUX_NUM];
}MSPI_Buffer_TypeDef;



#else /* USED_SW92400_OLD_SRIC_PROTOCOL */
typedef struct _MSPI_RegisterBuf
{
    uint16_t Addr       ;
    uint16_t reserved0  ;

    union
    {
        struct
        {
            uint16_t reserved1  : 14;
            uint16_t nBulk      : 1;
            uint16_t nWrite     : 1;
        } bulkwrite_b;
        uint16_t Command;
    };
    uint16_t reserved2 ;

    uint16_t Data;
    uint16_t reserved3;
} MSPI_RegisterBuf_TypeDef;


typedef struct _MSPI_SensingBuf
{
    union
    {
        uint16_t Addr       ;
        uint16_t Readback   ;
    };
    uint16_t reserved0  ;

    uint16_t reserved1  : 14;
    uint16_t nBulk      : 1;
    uint16_t nWrite     : 1;
    uint16_t reserved2 ;

    uint32_t Data[32];
}MSPI_SensingBuf_TypeDef;

typedef struct _ReadCommand_Buf_
{
    uint16_t Addr       ;
    uint16_t reserved0  ;

    union{
        struct
        {
            uint16_t reserved1  : 14;
            uint16_t nBulk      : 1;
            uint16_t nWrite     : 1;
        } bulkwrite_b;
        uint16_t Command;
    };
    uint16_t reserved2 ;

    uint16_t Data[SZ_MSPIBUF_MUXDATA*2];
}MSPI_ReadCommand_TypeDef;

typedef struct _MSPI_RAWDATA_
{
    uint32_t Dummy;
    uint16_t Data[SM_NUM][R0_ALIGNED_ROW_LEN][SM_COL_LEN*2];
}MSPI_Rawdata_Typedef;

typedef struct MSPI_Buffer
{
    MSPI_RegisterBuf_TypeDef SricBuffer[2][MSPI_NUM];
    MSPI_SensingBuf_TypeDef DataBuffer[2][MSPI_NUM];
    MSPI_ReadCommand_TypeDef ReadCommand[MSPI_NUM];
    MSPI_Rawdata_Typedef Rawdata[MSPI_NUM][MSPI_ROW_MAX_MUX];
    MSPI_Rawdata_Typedef PenRawdata[MSPI_NUM][FINGERPEN_MUX_NUM];
}MSPI_Buffer_TypeDef;
#endif /* USED_SW92400_OLD_SRIC_PROTOCOL */


typedef enum {
	_FREQ_UNKNOWN_ = 0,
	_FREQ_91k_ = 1,
	_FREQ_110k_ = 2,
	_FREQ_130k_ = 3,
	_FREQ_133k_ = 4,
	_FREQ_174k_ = 5,
	_FREQ_182k_ = 6,
	_FREQ_190k_ = 7,
	_FREQ_200k_ = 8
} eSENSING_FREQ_t;

extern volatile MSPI_Buffer_TypeDef*  SBuf;
#define FRAME_MEMORY		((volatile void								*)BASE_MSPI_SRAM    )
#define MSPI_BUF			((volatile MSPI_Buffer_TypeDef              *)BASE_MSPI_SRAM    )

#define __inline__

#endif /* _ENV_DEFINES_H_ */
