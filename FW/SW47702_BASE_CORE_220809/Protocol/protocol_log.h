/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  protocol_log.h
 * created on :  17. 4. 2017
 * Author :  mhjang
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

#ifndef _PROTOCOL_LOG_H_
#define _PROTOCOL_LOG_H_


/*
 * Log Registers
 */
#define SWIP_LOG_PROTOCOL_ID                     0x0001

typedef enum
{
    LT_DIAGNOSIS,
    LT_PRE_RAWDATA,
    LT_RAWDATA_TXLESS,
    LT_RAWDATA,
    LT_INTENSITY,
    LT_OVERSAMPLE_BUFFER,
    LT_REFERENCE,
    LT_FILTERED_INTENSITY,
    LT_GROUP,
    LT_FILTERED_GROUP,
    LT_DELAY,
    LT_RECAL_INFO,
    LT_HOVER_INFO,
    LT_SPLIT_INFO,
    LT_MERGE_INFO,
    LT_COORD_INFO,
    LT_NOISE_INFO,
    LT_SCREEN_BENDING_INFO,
    LT_PALM_INFO,
    LT_GNDNOISE_INFO,
    LT_STYLUS_INFO,
    LT_STYLUS_PALM_REJECT_INFO,
    LT_CONTACT_THRESHOLD_TUNING,
    LT_DEBUG,
    LT_DEBUG2,
    LT_PENPOS_RAWDATA = 25,
    LT_PENDATA_RAWDATA = 26,
    LT_PENPOS_INTENSITY = 27,
    LT_PENDATA_INTENSITY = 28,
	LT_NI_RAW			 = 29,
	LT_NI_INT			 = 30,
    LT_LIMIT
} eLogType_t;

typedef enum
{
    LTR_NONE,
    LTR_TRIG,
    LTR_WAIT = 255
} eLogTriggerType_t; // NOTE : warning제거

typedef struct
{
    uint16_t usBufferAddr;
    uint16_t usProtocolId;
} __PACKED tLogInfo_t;

typedef struct
{
    uint32_t ulLogMask;
//    volatile enum
//    {
//        LTR_NONE,
//        LTR_TRIG,
//        LTR_WAIT = 255
//    } __PACKED eTrigger; // NOTE : warning제거
     __PACKED volatile eLogTriggerType_t eTrigger;
} __PACKED tLogControl_t;

typedef struct
{
    uint8_t ucRow_;
    uint8_t ucCol_;
    uint8_t ucBufferCol_;
    tSignedByteDataType_t tDataType;
    uint8_t ucLogIndex_;
    struct
    {
        uint8_t b6Rightshift_   :6;
        uint8_t bBitfieldData   :1;
        uint8_t bIsRotated      :1;
    } __PACKED tOptions;
    uint16_t usLocalRowIdxCheckCode;
    uint16_t usLocalRowIdx;
} __PACKED tLogDataFormat_t;

typedef struct
{
    tLogInfo_t* ptInfo;
    tLogControl_t* ptControl;
    const tLogDataFormat_t* ptDataFormat;
} __PACKED tProtocolLog_t;

/*
 * Image Registers
 */
#define LOG_IMAGE_PROTOCOL_ID                   0x0001

typedef struct
{
    uint16_t usBufferAddr;
    uint16_t usProtocolId;
} __PACKED tImageInfo_t;

typedef enum
{
    IT_NONE = 0,
    IT_RAW_IMAGE,
    IT_BASELINE_IMAGE,
    IT_DELTA_IMAGE,
    IT_LABEL_IMAGE,
    IT_FILTERED_DELTA_IMAGE,
    IT_WAIT = 0xFF
} __PACKED eImageType_t;

typedef struct
{
    volatile eImageType_t eImageType;
} __PACKED tImageControl_t;

typedef struct
{
    uint8_t ucRow_;
    uint8_t ucCol_;
    uint8_t ucBufferCol_;
    bool_t bIsRotated;
    uint8_t ucKey_;
    tSignedByteDataType_t tDataType;
} __PACKED tImageDataFmt_t;

typedef struct
{
    tImageInfo_t* ptInfo;
    tImageControl_t* ptCtrl;
    const tImageDataFmt_t* ptFormat;
    uint8_t* pucFinger_;
    tRect_t* ptRect;
} __PACKED tProtocolImage_t;

#define _protocol_LogMatrix(LogType, datanum, data, iRamCol_, row, Code, Shift_, bTranspose) \
		protocol_Log((LogType),   \
                &(const tLogDataFormat_t)   \
        {   \
            .ucRow_ = (row), \
            .ucCol_ = (datanum), \
            .ucBufferCol_ = (iRamCol_),    \
            .tDataType = datatypeof((data)[0]),  \
            .ucLogIndex_ = (Code), \
            .tOptions = {.bIsRotated = bTranspose, .b6Rightshift_ = (Shift_)},  \
			.usLocalRowIdxCheckCode = 0,  \
			.usLocalRowIdx = 0,  \
        }, (void*)(data))

#define _protocol_LogLocalMatrix(LogType, datanum, data, iRamCol_, row, Code, Shift_, bTranspose, LocalRowIdx) \
		protocol_Log((LogType),   \
                &(const tLogDataFormat_t)   \
        {   \
            .ucRow_ = (row), \
            .ucCol_ = (datanum), \
            .ucBufferCol_ = (iRamCol_),    \
            .tDataType = datatypeof((data)[0]),  \
            .ucLogIndex_ = (Code), \
            .tOptions = {.bIsRotated = bTranspose, .b6Rightshift_ = (Shift_)},  \
			.usLocalRowIdxCheckCode = 0x7702,  \
			.usLocalRowIdx = LocalRowIdx,  \
        }, (void*)(data))

#define _protocol_LogMatrix_unsigned(LogType, datanum, data, iRamCol_, row, Code, Shift_, bTranspose) \
		protocol_Log((LogType),   \
                &(const tLogDataFormat_t)   \
        {   \
            .ucRow_ = (row), \
            .ucCol_ = (datanum), \
            .ucBufferCol_ = (iRamCol_),    \
            .tDataType = unsigneddatatypeof((data)[0]),  \
            .ucLogIndex_ = (Code), \
            .tOptions = {.bIsRotated = bTranspose, .b6Rightshift_ = (Shift_)},  \
        }, (void*)(data))

#define protocol_LogMatrix(LogType, datanum, data, iRamCol_, row, Code) \
		_protocol_LogMatrix(LogType, datanum, data, iRamCol_, row, Code, 0, NO)

#define protocol_LogMatrix_unsigned(LogType, datanum, data, iRamCol_, row, Code) \
		_protocol_LogMatrix_unsigned(LogType, datanum, data, iRamCol_, row, Code, 0, NO)

#define protocol_LogMatrixTranspose(LogType, datanum, data, iRamCol_, row, Code) \
		_protocol_LogMatrix(LogType, datanum, data, iRamCol_, row, Code, 0, YES)

#define protocol_LogMatrixRshift(LogType, datanum, data, iRamCol_, row, Code, Shift_) \
		_protocol_LogMatrix(LogType, datanum, data, iRamCol_, row, Code, Shift_, NO)

#define protocol_LogMatrixRshiftTranspose(LogType, datanum, data, iRamCol_, row, Code, Shift_) \
		_protocol_LogMatrix(LogType, datanum, data, iRamCol_, row, Code, Shift_, YES)

#define protocol_LogPaddedMatrix(LogType, datanum, data, iRamCol_, row, Code) \
		_protocol_LogMatrix(LogType, datanum, &ACCESS_MATRIX(data, iRamCol_ + 2*PAD_, PAD_, PAD_), iRamCol_ + 2*PAD_, row, Code, 0, NO)

#define protocol_LogOffsetMatrix(LogType, datanum, data, iRamCol_, row, col_offset, row_offset, Code) \
		_protocol_LogMatrix(LogType, datanum, &ACCESS_MATRIX(data, iRamCol_, row_offset, col_offset), iRamCol_, row, Code, 0, NO)

#define protocol_LogPaddedOffsetMatrix(LogType, datanum, data, iRamCol_, row, col_offset, row_offset, Code) \
		_protocol_LogMatrix(LogType, datanum, &ACCESS_MATRIX(data, iRamCol_ + 2*PAD_, row_offset + PAD_, col_offset + PAD_), iRamCol_ + 2*PAD_, row, Code, 0, NO)

#define protocol_LogLocalMatrix(LogType, datanum, data, iRamCol_, row, Code, LocalRowIdx) \
		_protocol_LogLocalMatrix(LogType, datanum, data, iRamCol_, row, Code, 0, NO, LocalRowIdx)

#define protocol_LogLocalPaddedMatrix(LogType, datanum, data, iRamCol_, row, Code, LocalRowIdx) \
		_protocol_LogLocalMatrix(LogType, datanum, &ACCESS_MATRIX(data, iRamCol_ + 2*PAD_, PAD_, PAD_), iRamCol_ + 2*PAD_, row, Code, 0, NO, LocalRowIdx)

 
typedef struct
{
 uint16_t VALUE[92][2];
} __PACKED tDRIVERSetting_t;
 
typedef enum
{
    SW9502_REG_ADDR_MDIDLE = 0,     // MdIdle   0
    SW9502_REG_ADDR_SNRSTR,         // SnrStr   2
    SW9502_REG_ADDR_MDGNRL,         // MdGnrl   4
    SW9502_REG_ADDR_AIPADC,         // AipAdc   6
    SW9502_REG_ADDR_SSUCTRL,        // SsuCtrl  8
    SW9502_REG_ADDR_TSYNCNUM0,      // TsyncNum0 10
    SW9502_REG_ADDR_TSYNCNUM1,      // TsyncNum1 12
    SW9502_REG_ADDR_TSYNCDMY1,      // TsyncDmy1 14
    SW9502_REG_ADDR_PWMNUM0,        // PwmNum0   16
    SW9502_REG_ADDR_PWMNUM1,        // PwmNum1   18
    SW9502_REG_ADDR_CMUXNRM,        // CmuxNrm   20
    SW9502_REG_ADDR_CMUXNSE,        // CmuxNse   22
    SW9502_REG_ADDR_COLNUM,         // ColNum    24
    SW9502_REG_ADDR_ROWNUM,         // RowNum    26
    SW9502_REG_ADDR_DIGGAIN0,       // DigGain0  28
    SW9502_REG_ADDR_DIGGAIN1,       // DigGain1  30
    SW9502_REG_ADDR_NIHMIN0,        // NihMin0   32
    SW9502_REG_ADDR_NIHMAX0,        // NihMax0   34
    SW9502_REG_ADDR_NIHMIN1,        // NihMin1   36
    SW9502_REG_ADDR_NIHMAX1,        // NihMax1   38
    SW9502_REG_ADDR_NIHMIN2,        // NihMin2   40
    SW9502_REG_ADDR_NIHMAX2,        // NihMax2   42
    SW9502_REG_ADDR_NIHMIN3,        // NihMin3   44
    SW9502_REG_ADDR_NIHMAX3,        // NihMax3   46
    SW9502_REG_ADDR_NIHRDAT0,       // NihRdat0  48
    SW9502_REG_ADDR_NIHRDAT1,       // NihRdat1  50
    SW9502_REG_ADDR_NIHRDAT2,       // NihRdat2  52
    SW9502_REG_ADDR_NIHRDAT3,       // NihRdat3  54
    SW9502_REG_ADDR_MDSPCL,         // MdSpcl    56
    SW9502_REG_ADDR_SHASTR0,        // ShaStr0   58
    SW9502_REG_ADDR_SHASTR1,        // ShaStr1   60
    SW9502_REG_ADDR_SHASTR2,        // ShaStr2   62
    SW9502_REG_ADDR_VCRSTR,         // VcrStr    64
    SW9502_REG_ADDR_VCRNUM0,        // VcrNum0   66
    SW9502_REG_ADDR_VCRNUM1,        // VcrNum1   68
    SW9502_REG_ADDR_VCRNUM2,        // VcrNum2   70
    SW9502_REG_ADDR_VCRNUM3,        // VcrNum3   72
    SW9502_REG_ADDR_VCRNUM4,        // VcrNum4   74
    SW9502_REG_ADDR_VCRNUM5,        // VcrNum5   76
    SW9502_REG_ADDR_RESERVED0,      // 78
    SW9502_REG_ADDR_RESERVED1,      // 80
    SW9502_REG_ADDR_RESERVED2,      // 82
    SW9502_REG_ADDR_RESERVED3,      // 84
    SW9502_REG_ADDR_RESERVED4,      // 86
    SW9502_REG_ADDR_RESERVED5,      // 88
    SW9502_REG_ADDR_RESERVED6,      // 90
    SW9502_REG_ADDR_MAX
} eSW9502_RegMap_t;

typedef struct
{
 uint16_t TSYNC_NUM;
 uint16_t LINE_NUM;
 uint16_t INTV_PERIOD;
 uint16_t OFFSET0_PERIOD;
 uint16_t OFFSET1_PERIOD;
 uint16_t OFFSET2_PERIOD;
 uint16_t PRE_NUM;
 uint16_t PRE_LOW;
 uint16_t PRE_PERIOD;
 uint16_t PRE_ITV_PERIOD;
 uint16_t F0_ACT0_NUM;
 uint16_t F0_ACT1_NUM;
 uint16_t F0_ACT_LOW;
 uint16_t F0_ACT_PERIOD;
 uint16_t F1_ACT_PERIOD;
 uint16_t F1_ACT_LOW;
 uint16_t F2_ACT_PERIOD;
 uint16_t F2_ACT_LOW;
 uint16_t F1_ACT_NUM;
 uint16_t F2_ACT_NUM;
 uint16_t F1_LINE_NUM;
 uint16_t F2_LINE_NUM;
} __PACKED tPWMDRVSetting_t;


extern tProtocolImage_t tProtocolImage;
extern tProtocolLog_t tProtocolLog;

extern void protocol_Log(eLogType_t eLogType, const tLogDataFormat_t* _ptDataFormat, const void* _pBuf);
extern void protocol_LogImage(eImageType_t _type, const tImageDataFmt_t* _ptDataFormat, uint8_t ucFinger_, tRect_t rect[ucFinger_], const void* _pBuf);
extern uint32_t protocol_log_get_mode(void);
extern void protocol_log_set_mode(eLogTriggerType_t _m);


#endif /* _PROTOCOL_LOG_H_ */
