/*
 * protocol_conf.h
 *
 *  Created on: 2015. 3. 20.
 *      Author: parkyj2
 */

#ifndef __PROTOCOL_CONF_H__
#define __PROTOCOL_CONF_H__

#include "protocol.h"
/*
 * Types
 */
typedef struct
{
    eSWIPPacketFormatId_t ePacketFormatId;
//    int iMaxFinger_;
} __PACKED tProtocolCommonConf_t;

//typedef struct
//{
//	int t;
//} __PACKED tProtocolConf_t;

typedef struct
{
	eProtocolEventTriggerType_t eEventTriggerType;
	bool_t bEnableHandShake;
	bool_t bApplyCoordinate;
	int iEventPacket_;
} __PACKED tProtocolInfo_t;


/*
 * Default Methods
 */
extern void protocol_SetCommonConfig(const tProtocolCommonConf_t * _p);
extern const tProtocolCommonConf_t *protocol_GetCommonConfig(void);
extern tProtocolInfo_t *protocol_GetInfo(void);


#endif /* __PROTOCOL_CONF_H__ */
