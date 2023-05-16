/*
 * protocol_swip.h
 *
 *  Created on: 2015. 3. 12.
 *      Author: parkyj2
 */

#ifndef __PROTOCOL_SWIP_H__
#define __PROTOCOL_SWIP_H__


#include "protocol_swip_regmap.h"
#include "protocol_log.h"
#include "protocol.h"



/*
 * Information Registers
 */
#define PRODUCT_NAME_                       16
#define TEST_DEVICE_READ_PACKED             0x0030//0x0042

typedef struct
{
    char vcProductName[PRODUCT_NAME_];
    uint16_t usXResolution;
    uint16_t usYResolution;
    uint8_t ucXNode_;
    uint8_t ucYNode_;
    uint8_t ucLocalYNode_;
} __PACKED tSWIPPanel_t;

typedef struct
{
    uint16_t bcdBootVer;
    uint16_t bcdAppVer;
    uint16_t bcdParamVer;
} __PACKED tSWIPFirmwareSectionVersion_t;

typedef struct
{
    uint8_t ucBootStartAddr;
    uint8_t ucBootEndAddr;
    uint8_t ucAppStartAddr;
    uint8_t ucAppEndAddr;
    uint8_t ucParamlStartAddr;
    uint8_t ucParamlEndAddr;
} __PACKED tSWIPFirmwareSectionAddress_t;

typedef struct
{
	uint32_t ulBootCRC;
	uint32_t ulAppCRC;
	uint32_t ulParamCRC;
} __PACKED tSWIPFirmwareIntegrity_t;

#define PROTOCOL_NAME_                       8

typedef struct
{
    char vcProtocolName[PROTOCOL_NAME_];
    uint16_t bcdProtocolVersion;
	uint16_t I2C_VID;
	uint16_t I2C_PID;
} __PACKED tSWIPInterface_t;

typedef struct
{
	uint16_t usPWMTxFrequecy;
} __PACKED tSWIPExtra_t;

typedef struct
{
	uint16_t ulTrimCode[14];
	uint32_t ulTrimCRC;
} __PACKED tSWIPTrimCode_t;

typedef struct
{
	tSWIPTrimCode_t tTrimCode_1Set;
	tSWIPTrimCode_t tTrimCode_2Set;
} __PACKED tSWIPTrimCodeSet_t;

/*
 * Event Registers
 */
typedef enum
{
    PF_NORMAL = 0,
    PF_ANGLE_WITHOUT_STRENGTH = 1,
    PF_SNR_MODE = 2,
    PF_LIMIT,
    PF_FOR_SIZEFIX = 0xFFFF,
} __PACKED eSWIPPacketFormatId_t;

typedef struct
{
    uint32_t reserved;
    eSWIPPacketFormatId_t ePacketFormatId;
    uint8_t ucTouchPacketItemSize;
} __PACKED tSWIPEventFormat_t;

typedef struct
{
    struct
    {
        uint8_t b4FingerID :4;
        uint8_t bPalm :1;
        uint8_t bHover :1;
        uint8_t bScreen :1;
        uint8_t bTouch :1;
    } __PACKED tInfo;
    uint8_t ucXHigh;
    uint8_t ucYHigh;
    uint8_t ucXLow;
    uint8_t ucYLow;
    uint8_t ucWidth;
    uint16_t usStrength;
	uint8_t  ucRowStart;
} __PACKED tSWIPTouchItem00_t;

typedef struct
{
	struct
	{
		uint8_t b4FingerID  :4;
		uint8_t bPalm       :1;
		uint8_t bHover      :1;
		uint8_t bScreen     :1;
		uint8_t bTouch      :1;
	} __PACKED tInfo;
	uint8_t ucXHigh;
	uint8_t ucYHigh;
	uint8_t ucXLow;
	uint8_t ucYLow;
	uint8_t ucWidth;
	int8_t cAngle;
	uint8_t ucMajorLength;
	uint8_t ucMinorLength;
} __PACKED tSWIPTouchItem01_t;

#if USED_SHARP_SPECIFIC_PROTOCOL
/*
 * @ TouchItem02
 *
 * SW42102 - Only Use Sharp protocol Format
 *
 * */
typedef enum {
	TOUCH_STATUS_RELEASE = 0,
	TOUCH_STATUS_PRESS,
	TOUCH_STATUS_REMAIN,
	TOUCH_STATUS_MOVE,
	TOUCH_STATUS_LIMIT
} eTouchItemInfo;

typedef enum {
	TOUCH_TYPE_FINGER = 0,
	TOUCH_TYPE_GLOVE,
	TOUCH_TYPE_HOVER,
	TOUCH_TYPE_PASSIVE_STYLUS,
	TOUCH_TYPE_ACTIVE_STYLUS,
	TOUCH_TYPE_ACTIVE_STYLUS_HOVER
} eTouchItemStatus;

typedef struct {
	uint8_t finger;
	uint8_t glove;
	uint8_t hover;
	uint8_t passive_stylus;
	uint8_t active_stylus;
	uint8_t active_stylus_hover;
} tTouchItemType_t;

typedef struct
{
	struct
	{
		uint8_t b4FingerID 		:4;
		uint8_t b1Status		:1;
		uint8_t b6Type			:6;
		uint8_t b4Reserved		:5;
	} __PACKED tInfo;	// 2byte
    uint8_t ucXHigh;
    uint8_t ucYHigh;
    uint8_t ucXLow;
    uint8_t ucYLow;
    uint8_t ucWidth;
    uint16_t usStrength;
    uint8_t  ucRowStart;
} __PACKED tSWIPTouchItem02_t;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */

typedef union
{
#if USED_SHARP_SPECIFIC_PROTOCOL
	tSWIPTouchItem02_t tItem00;
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
	tSWIPTouchItem00_t tItem00;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
    tSWIPTouchItem01_t tItem01;		
} uSWIPTouchItem_t;


typedef struct
{
	uint16_t ReportSize;
	uint8_t  ReportID;
	
	struct
	{
		uint8_t  Status;
		uint8_t  ID;
		uint16_t ucX;
		uint16_t ucY;
	} __PACKED tTouchInfo[MAX_TOUCH_];

	uint8_t   ucContactCnt;
	uint16_t  RowStart;
} __PACKED tSWIPPacketInfo_t;

typedef enum
{
    GT_NONE
} eSWIPGestureType_t;

typedef struct
{
    enum
    {
        NT_NONE = 0,
        NT_ESD,
        NT_WAKEUP_GESTURE_DETECTED
    } eNotificationType;
    union
    {
        struct
        {
            uint8_t ucFrameCnt;
        } __PACKED tESDAlertPacket;
        struct
        {
            eSWIPGestureType_t eGestureType;
        } __PACKED tWakeupGestureAlertPacket;
    } __PACKED uData;
} __PACKED tSWIPAlertPacket_t;

/*
 * Parameter Mode Registers
 */
#define SWIP_PARAMETER_PROTOCOL_ID               0x0001

typedef struct
{
    uint16_t usBufferAddr;
    uint16_t usProtocolId;
} __PACKED tSWIPParameterInfo_t;

/*
 * Cm Test Mode Registers
 */
#define SWIP_TEST_PROTOCOL_ID                 	0x0001

typedef struct
{
    uint16_t usBufferAddr;
    uint16_t usProtocolId;
} __PACKED tSWIPTestInfo_t;

typedef enum
{
    CTT_RESERVED		= 0,
    CTT_ABS				= 1,
	CTT_JITTER			= 2,
	CTT_ABS_DIFF		= 3,
	CTT_DC_ABS			= 4,
	CTT_CRC_CHECK		= 5,
	CTT_SHORT_1			= 6,
	CTT_SHORT_2			= 7,
	CTT_OPEN			= 8,
    CTT_DC_ABS_JITTER 	= 9,
	CTT_TP_INFO_WRITE	= 0xF0,
	CTT_NONE			= 0xFF,

} __PACKED eSWIPTestType_t;

typedef struct
{
	volatile eSWIPTestType_t eTestType;
	volatile uint8_t ucABSAvrCount;
	volatile uint8_t ucDCABSAvrCount;
	volatile uint8_t ucOpenAvrCount;
	volatile uint8_t ucShortAvrCount;
	volatile uint8_t ucJitterAvrCount;
	volatile uint8_t ucJitterCheckCount;
} __PACKED tSWIPTestControl_t;

typedef struct
{
    uint8_t ucRow_;
    uint8_t ucCol_;
    uint8_t ucBufferCol_;
    bool_t bIsRotated;
    uint8_t ucKey_;
    tSignedByteDataType_t tDataType;
} __PACKED tSWIPTestDataFmt_t;

typedef struct
{
    struct
    {
        tSWIPTestInfo_t* ptInfo;
        tSWIPTestControl_t* ptCtrl;
        const tSWIPTestDataFmt_t* ptFormat;
    } __PACKED  tTest;
} __PACKED tSWIPTest_t;

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
typedef struct
{
    uint16_t usCounterValue;
    uint8_t ucPCTimeStamp[12];
    uint8_t ucComputerName[10];
    uint32_t ulCRC;
} __PACKED tSWIPPTInspectionInfo_t;

typedef struct
{
	tSWIPPTInspectionInfo_t* ptGetInfo;
	tSWIPPTInspectionInfo_t* ptSetInfo;

} __PACKED tSWIPPTInspection_t;
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

typedef struct
{
    bool_t bGNDNoiseStatus;
    bool_t bLCDNoiseStatus;
    uint8_t ucOscVal;

    bool_t bReadModuleConfig;
} __PACKED tSWIPControlForTuning_t;

typedef struct
{
    tSWIPPanel_t* ptPanel;
    tSWIPFirmwareSectionVersion_t* ptVersion;
    tSWIPFirmwareSectionAddress_t* ptSectionAddress;
    tSWIPFirmwareIntegrity_t* ptIntegrity;
    tSWIPInterface_t* ptInterface;
    tSWIPExtra_t* ptExtra;
    tSWIPTrimCodeSet_t* ptTrimCode;

} __PACKED tSWIPInfo_t;

typedef struct
{
    tSWIPEventFormat_t* ptEventFormat;
    tSWIPPacketInfo_t* ptPacketInfo;
} __PACKED tSWIPEvent_t;

typedef struct
{
    tSWIPControlForTuning_t* ptControlForTuning;
    tPWMDRVSetting_t*        ptPWMDRVParam;
    tDRIVERSetting_t*        ptROICParam;
} __PACKED tSWIPSpecialAction_t;

typedef struct
{
    tSWIPParameterInfo_t* ptInfo;
} __PACKED tSWIPParameter_t;

typedef struct
{
    uint8_t** ppucBuffer;
    uint16_t* vusStartAddr;
    int iSize;
} __PACKED tSWIPBufferInfo_t;

typedef struct
{
    uint8_t** ppucData;//Pointer of array of pointers.
    uint8_t* vucStartLAddr;
    int iSize;
} __PACKED tSWIPSubsetInfo_t;

/*
 * Interfaces
 */

/* Define Functions */

extern void protocol_swip_Init(void);
extern eProtocolMode_t protocol_swip_GetMode(void);
extern void protocol_swip_SetMode(eProtocolMode_t _eMode);

extern bool_t protocol_swip_GetLocalIdxFixedEn(void);
extern bool_t protocol_swip_GetLocalIdx(void);
extern bool_t protocol_swip_GetEnableBulkLog(void);
extern void protocol_swip_SetEnableBulkLog(bool_t _bVal);
extern bool_t protocol_swip_GetDFUP_Ready(void);
extern void protocol_swip_SetDFUP_Ready(bool_t _bVal);

extern uint8_t protocol_swip_GetABSAvrCount(void);
extern uint8_t protocol_swip_GetDCABSAvrCount(void);
extern uint8_t protocol_swip_GetOpenAvrCount(void);
extern uint8_t protocol_swip_GetShortAvrCount(void);
extern uint8_t protocol_swip_GetJitterAvrCount(void);
extern uint8_t protocol_swip_GetJitterCheckCount(void);

extern void protocol_swip_PendReadyStatus(void);
extern eSWIPTestType_t protocol_swip_GetTestType(void);

#if (USED_MODULE_DEF == MODULE_DEF_S_1)
extern uint8_t* protocol_swip_GetPTInspectionSetBufPrt(void);
extern void protocol_swip_UpdatePTInspectionGetInfo(void);
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */

extern void protocol_swip_PendTestResult(const tSWIPTestDataFmt_t* _ptDataFormat, const void* _pBuf);
extern eSWIPPacketFormatId_t protocol_swip_GetPacketFormatId(void);
extern void protocol_swip_InitTouchEventBuffer(void);
extern void protocol_swip_PushTouchEvent(const uSWIPTouchItem_t* _kptItem);
extern void protocol_swip_SendTouchEvent(void);
extern void protocol_swip_SendPenEvent(void);

extern uint8_t protocol_swip_GetOscVal(void);
extern void protocol_swip_SetOscVal(uint8_t oscval);

extern uint8_t* protocol_swip_GetMappedPointer(uint16_t _addr);
extern void protocol_swip_ClearInterrupt(uint16_t _addr);
extern bool_t protocol_swip_GetEventIntrType(void);
#endif /* __PROTOCOL_SWIP_H__ */
