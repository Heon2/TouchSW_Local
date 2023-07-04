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
} __PACKED tSWIPPanel_t;

typedef struct
{
    uint16_t bcdBootVer;
    uint16_t bcdCoreVer;
    uint16_t bcdAppVer;
    uint16_t bcdParaVer;
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
//	uint32_t ulBootCRC;
//	uint32_t ulAppCRC;
//	uint32_t ulParamCRC;
	uint8_t usCalculateCRC1;
	uint8_t usCalculateCRC2;
	uint8_t usCalculateCRC3;
	uint8_t usCalculateCRC4;

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


#if USED_MOBILE_I2C_PROTOCOL

//typedef union
//{
//    struct
//    {
//        unsigned wakeUpType    :  8;
//        unsigned touch_cnt     :  5;
//        unsigned buttonCnt     :  3;
//        unsigned palmBit       : 16;
//    } b;
//} tTouchInfo_t;
//
//typedef struct
//{
//    unsigned tool_type   : 4;
//    unsigned event       : 4;
//    unsigned track_id    : 8;
//    unsigned x           : 16;
//    unsigned y           : 16;
//    unsigned pressure    : 8;
//    unsigned angle       : 8;
//    unsigned width_major : 16;
//    unsigned width_minor : 16;
//} tTouchData_t;

typedef struct
{
	uint32_t ulDummy[2];
	struct
	{
		unsigned wakeUpType    :  8;
		unsigned touch_cnt     :  8;
		unsigned palmBit       : 16;
	} __PACKED tTouchinfo;

	struct
	{
	    unsigned event       : 4;
	    unsigned tool_type   : 4;
	    unsigned track_id    : 8;
	    unsigned x           : 16;
	    unsigned y           : 16;
	    unsigned pressure    : 8;
	    unsigned angle       : 8;
	    unsigned width_major : 16;
	    unsigned width_minor : 16;
	} __PACKED tTouchData[MAX_TOUCH_];
//    tTouchInfo_t tTouchinfo;
//    tTouchData_t tTouchData[MAX_TOUCH_];
	uint8_t   ucContactCnt;
	uint16_t  RowStart;
} __PACKED tSWIPPacketInfo_t;

#else /* USED_MOBILE_I2C_PROTOCOL */
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
#endif /* USED_MOBILE_I2C_PROTOCOL */

#if defined(SUPPORT_ANDROID)
typedef struct
{
		unsigned  running_sts        : 5;	
		unsigned  device_checked_sts : 1;
		unsigned  code_valid         : 1;
		unsigned  cfg_valid          : 1;//10
		unsigned  font_valid         : 1;
		unsigned  abnormal_sts       : 1;
		unsigned  esd_error_sts      : 1;
		unsigned  reserved0          : 2;	
		unsigned  disp_mode_mismatch : 1;		
		unsigned  reserved1          : 1;			
		unsigned  interrupt_sts      : 1;//10	
		unsigned  interrupt_type     : 4;//10	
		unsigned  touch_int_en_sts   : 1;
		unsigned  dwatch_int_en_sts  : 1;			
		unsigned  tc_drv_valid       : 1;		
		unsigned  tc_cfg_load_type   : 2;
		unsigned  dic_disp_sts       : 2;
		unsigned  model_id_load_flag : 1;
		unsigned  pt_info_error      : 1;
		unsigned  reserved2          : 3;
} __PACKED t_tc_status;


	
typedef struct
{
		unsigned wakeUpType    :  8;
		unsigned touch_cnt     :  5;
		unsigned buttonCnt     :  3;
		unsigned palmBit       : 16;
} __PACKED tTouchInfo_t;

typedef struct
{
    unsigned tool_type   : 4;
    unsigned event       : 4;
    unsigned track_id    : 8;
    unsigned x           : 16;
    unsigned y           : 16;
    unsigned pressure    : 8;
    unsigned angle       : 8;
    unsigned width_major : 16;
    unsigned width_minor : 16;
} __PACKED tTouchData_t;

typedef struct
{    
    uint32_t       _ic_status;
  	t_tc_status    _tc_status;		
    tTouchInfo_t   _info;
		tTouchData_t   _data[10];
}tAndroidDevInfo_t;


typedef struct
{
    uint32_t*     ic_status;
    t_tc_status*  tc_status;
    tTouchInfo_t* info;
    tTouchData_t* data;
} __PACKED tReportPacket_t;

#endif


//static __inline__ int protocol_swip_GetPacketSize(eSWIPPacketFormatId_t id)
//{
//    return ((int [])
//    {
//        sizeof(tSWIPTouchItem00_t), sizeof(tSWIPTouchItem01_t)
//    })[id];
//}

//static __inline__ int protocol_swip_GetFormattedStr(char* p, eSWIPPacketFormatId_t id)
//{
//    //�⺻ charactor�� 8��.
//    switch( id )
//    {
//        case PF_NORMAL:
//        {
//            const char fmt[] = "[%2d]={%4d,%4d,%3d,%4d},";
//            strcpy(p, fmt);
//            return 26;
//        }
//        case PF_ANGLE_WITHOUT_STRENGTH:
//        {
//            const char fmt[] = "[%2d]={%4d,%4d,%3d,%3d,%3d,%3d},";
//            strcpy(p, fmt);
//            return 31;
//        }
//    }
//    return 0; //NOTE : warning����... 0���� ���� �޾��� �� ����ó�� �ʿ�!!
//}


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

#if USED_MNT_USB_CUSTOM_PROTOCOL
typedef enum
{
    CTT_RESERVED0	= 0,
	CTT_RESERVED1	= 1,
	CTT_ABS			= 2,
	CTT_JITTER		= 3,
	CTT_SHORT		= 4,
	CTT_CRC_CHECK	= 5,
	CTT_NONE		= 0xFF,
} __PACKED eSWIPTestType_t;
#else
typedef enum
{
    CTT_RESERVED	= 0,
    CTT_ABS			= 1,
	CTT_JITTER		= 2,
	CTT_ABS_DIFF	= 3,
	CTT_DC_ABS		= 4,
	CTT_CRC_CHECK	= 5,
	CTT_EVENODD_SHORT		= 6,
	CTT_OPEN_SHORT	= 7,
	CTT_NONE		= 0xFF,
} __PACKED eSWIPTestType_t;
#endif

typedef struct
{
    volatile eSWIPTestType_t eTestType;
    volatile uint8_t ucABSDiffCount;
	volatile uint8_t ucABSCount;
	volatile uint8_t ucDCABSCount;
	volatile uint8_t ucJitterAVGCount;
	volatile uint8_t ucJitterMAXCount;
	volatile uint32_t lCRCValue;
} __attribute__ ((packed)) tSWIPTestControl_t;

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

#if defined(SUPPORT_ANDROID)
typedef struct  
{
		uint8_t minor;
		uint8_t major:4;
		uint8_t build:4;
		uint8_t chip;
		uint8_t protocol:4;
		uint8_t rsvd;
} __PACKED tc_version_t;

typedef struct  
{
		uint16_t boot;
		uint16_t core;
} __PACKED chip_version_t;


typedef struct
{
    u4byteString_t*    ptSprChipID;
    tc_version_t*      ptTcVersion;
    chip_version_t*    ptChipVersion;
    u8byteString_t*    ptTcProductId;
} __PACKED tSWIPAndroidBaseInfo_t;

typedef struct
{
    uint32_t*          ptSprChipTest;    //0x400
		uint32_t* 				 ptSprBootSts;     //0x401
		uint32_t* 				 ptTcDeviceCtl;    //0x402
		uint32_t* 				 ptTcInterruptCtl; //0x403
		uint32_t* 				 ptImeState;       //0x404
		uint32_t* 				 ptTciEnableW;     //0x405
		uint32_t* 				 ptSwipeEnableW;   //0x406
		uint32_t* 				 ptSprSubDispSts;  //0x407
		uint32_t* 				 ptTcDriveCtl;     //0x408
} __PACKED tSWIPAndroidSprChipInfo_t;
#endif


typedef struct
{
#if USED_MOBILE_I2C_PROTOCOL
//    tSWIPEventFormat_t* ptEventFormat;
    tSWIPPacketInfo_t* ptPacketInfo;
#else /* USED_MOBILE_I2C_PROTOCOL */
    tSWIPEventFormat_t* ptEventFormat;
    tSWIPPacketInfo_t* ptPacketInfo;
#endif /* USED_MOBILE_I2C_PROTOCOL */
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

extern bool_t protocol_swip_GetRecalibrate(void);
extern void protocol_swip_SetRecalibrate(bool_t _bRecalibrate);
extern ePowerConsumptionState_t protocol_swip_GetPowerConsumptionState(void);
extern void protocol_swip_SetPowerConsumptionState(ePowerConsumptionState_t _eState);
extern uint32_t protocol_swip_GetGestureType(void);
extern void protocol_swip_SetGestureType(uint32_t _ulGestureType);
extern bool_t protocol_swip_GetDisableESDAlert(void);
extern void protocol_swip_SetDiableESDAlert(bool_t _bVal);
extern bool_t protocol_swip_GetChargerAttached(void);
extern void protocol_swip_SetChargetAttached(bool_t _bVal);
extern bool_t protocol_swip_GetSensingOnWindowEnable(void);
extern void protocol_swip_SetSensingOnWindowEnable(bool_t _bVal);
extern bool_t protocol_swip_GetGloveSensingEnable(void);
extern void protocol_swip_SetGloveSensingEnable(bool_t _bVal);
extern bool_t protocol_swip_GetPalmRejectionEnable(void);
extern void protocol_swip_SetPalmRejectionEnable(bool_t _bVal);
extern bool_t protocol_swip_GetDisableEdgeExpand(void);
extern void protocol_swip_SetDisableEdgeExpand(bool_t _bVal);
extern uint8_t protocol_swip_GetABSDiffCount(void);
extern uint8_t protocol_swip_GetABSCount(void);
extern uint8_t protocol_swip_GetDCABSCount(void);
extern uint8_t protocol_swip_GetJitterAVGCount(void);
extern uint8_t protocol_swip_GetJitterMAXCount(void);
//extern uint32_t protocol_swip_GetCRCValue(void);
//extern void protocol_swip_SetCRCValue(uint32_t _lCRCValue);
extern void protocol_swip_PendReadyStatus(void);
extern void protocol_swip_PendReadyStatusCustom(eProtocolReadyStatus_t data); // NOTE : warning����
extern void protocol_swip_SetParameterBuffer(void* p);
extern void protocol_swip_SetTestType(eSWIPTestType_t _t);
extern eSWIPTestType_t protocol_swip_GetTestType(void);
extern void protocol_swip_PendTestResult(const tSWIPTestDataFmt_t* _ptDataFormat, const void* _pBuf);
extern eSWIPPacketFormatId_t protocol_swip_GetPacketFormatId(void);
extern void protocol_swip_InitTouchEventBuffer(void);
extern void protocol_swip_PushTouchEvent(const uSWIPTouchItem_t* _kptItem);
extern void protocol_swip_SendTouchEvent(void);
extern void protocol_swip_SendPenEvent(void);
#if defined(SUPPORT_ANDROID)
extern void protocol_Android_PushTouchEvent(const uSWIPTouchItem_t* _kptItem);
#endif

extern bool_t protocol_swip_GetGNDNoiseHandlingStatus(void);
extern void protocol_swip_SetGNDNoiseHandlingStatus(bool_t _bStatus);
extern bool_t protocol_swip_GetLCDNoiseHandlingStatus(void);
extern void protocol_swip_SetLCDNoiseHandlingStatus(bool_t _bStatus);
extern uint8_t protocol_swip_GetOscVal(void);
extern void protocol_swip_SetOscVal(uint8_t oscval);
extern bool_t protocol_swip_GetReadModuleConfigStatus(void);
extern void protocol_swip_SetReadModuleConfigStatus(bool_t _bStatus);

extern uint8_t* protocol_swip_GetMappedPointer(uint16_t _addr);
extern void protocol_swip_ClearInterrupt(uint16_t _addr);
extern bool_t protocol_swip_GetEventIntrType(void);
#if defined(SUPPORT_ANDROID)
extern bool_t protocol_android_SetEventIntrType(void);
extern bool_t protocol_android_SetDevCtlSts(void);
#endif
#endif /* __PROTOCOL_SWIP_H__ */
