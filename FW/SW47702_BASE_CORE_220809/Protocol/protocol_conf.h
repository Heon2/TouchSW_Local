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
} __PACKED tProtocolCommonConf_t;

typedef struct
{
	eProtocolEventTriggerType_t eEventTriggerType;
	int iEventPacket_;
} __PACKED tProtocolInfo_t;


// Default Methods
extern const tProtocolCommonConf_t *protocol_GetCommonConfig(void);
extern void protocol_SetCommonConfig(const tProtocolCommonConf_t * _p);
extern tProtocolInfo_t *protocol_GetInfo(void);


#endif /* __PROTOCOL_CONF_H__ */
