/*
 * protocol_dfup.h
 *
 *  Created on: 2015. 4. 30.
 *      Author: parkyj2
 */

#ifndef __PROTOCOL_DFUP_H__
#define __PROTOCOL_DFUP_H__

#include "protocol_dfup_regmap.h"

/*
 * Control Registers
 */

#define PROTOCOL_NAME_                       8

typedef struct
{
    uint16_t bcdBootVer;
    uint16_t bcdCoreVer;
    uint16_t bcdAppVer;
    uint16_t bcdParaVer;
} __PACKED tDFUPFirmwareSectionVersion_t;

typedef struct
{
    uint8_t ucBootStartAddr;
    uint8_t ucBootEndAddr;
    uint8_t ucAppStartAddr;
    uint8_t ucAppEndAddr;
    uint8_t ucParamlStartAddr;
    uint8_t ucParamlEndAddr;
} __PACKED tDFUPFirmwareSectionAddress_t;

typedef struct
{
	uint32_t ulBootCRC;
	uint32_t ulAppCRC;
	uint32_t ulParamCRC;
} __PACKED tDFUPFirmwareIntegrity_t;

typedef struct
{
    char vcProtocolName[PROTOCOL_NAME_];
    uint16_t bcdProtocolVersion;
    uint16_t I2C_VID;
    uint16_t I2C_PID;
} __PACKED tDFUPInterface_t;

typedef struct
{
	uint16_t ulTrimCode[14];
	uint32_t ulTrimCRC;
} __PACKED tDFUPTrimCode_t;

typedef struct
{
	tDFUPTrimCode_t tTrimCode_1Set;
	tDFUPTrimCode_t tTrimCode_2Set;
} __PACKED tDFUPTrimCodeSet_t;

typedef struct
{
	tDFUPFirmwareSectionVersion_t* ptVersion;
	tDFUPFirmwareSectionAddress_t* ptSectionAddress;
	tDFUPFirmwareIntegrity_t* ptIntegrity;
    tDFUPInterface_t* ptInterface;
    tDFUPTrimCodeSet_t* ptTrimCode;
} __PACKED tDFUPInfo_t;

/*
 * Event Registers
 */

typedef struct
{
    uint8_t b7Length    :7;
    uint8_t bAlert      :1;
} __PACKED tDFUPPacketInfo_t;

typedef enum
{
    DFUP_PF_NORMAL = 0,
    DFUP_PF_ANGLE_WITHOUT_STRENGTH = 1,
    DFUP_PF_LIMIT,
    DFUP_PF_FOR_SIZEFIX = 0xFFFF,
} __PACKED eDFUPPacketFormatId_t;

typedef struct
{
    uint32_t reserved;
    eDFUPPacketFormatId_t ePacketFormatId;
    uint8_t ucTouchPacketItemSize;
} __PACKED tDFUPEventFormat_t;

typedef struct
{
    tDFUPEventFormat_t* ptEventFormat;
    tDFUPPacketInfo_t* ptPacketInfo;
    uint8_t* vucPacketContent;
} __PACKED tDFUPEvent_t;

typedef struct
{
    uint8_t** ppucBuffer;
    uint16_t* vusStartAddr;
    int iSize;
} __PACKED tDFUPBufferInfo_t;

typedef struct
{
    uint8_t** ppucData;//Pointer of array of pointers.
    uint8_t* vucStartLAddr;
    int iSize;
} __PACKED tDFUPSubsetInfo_t;

extern void protocol_dfup_Init(void);
extern uint8_t* protocol_dfup_GetMappedPointer(uint16_t _addr);
extern void protocol_dfup_ClearInterrupt(uint16_t _addr);
extern void protocol_dfup_PendReadyStatus(void);
extern eProtocolMode_t protocol_dfup_GetMode(void);

#endif /* __PROTOCOL_DFUP_H__ */
