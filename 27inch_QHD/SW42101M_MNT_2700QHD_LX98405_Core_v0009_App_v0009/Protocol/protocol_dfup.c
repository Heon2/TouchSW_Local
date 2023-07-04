/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  protocol_dfup.c
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

#include "Hal_def.h"
#include "protocol_def.h"
//#include "sflash_dfup.h"
//#include "syscfg.h"


static tDFUPFirmwareSectionVersion_t ktDFUPInfoFirmwareSectionVersion;
static tDFUPFirmwareSectionAddress_t ktDFUPInfoFirmwareSectionAddress;
static tDFUPFirmwareIntegrity_t ktDFUPInfoFirmwareIntegrity;
static tDFUPInterface_t ktDFUPInfoInterface =
{
	.vcProtocolName = "DFUP",
	.bcdProtocolVersion = 0x0500,
	.I2C_VID = UNIQUE_VID,
	.I2C_PID = UNIQUE_APP_PID,
};
static tDFUPTrimCodeSet_t ktSWIPInfoTrimCode;

static tDFUPInfo_t tDFUPInfo =
{
	.ptVersion = &(ktDFUPInfoFirmwareSectionVersion),
	.ptSectionAddress = &(ktDFUPInfoFirmwareSectionAddress),
	.ptIntegrity = &(ktDFUPInfoFirmwareIntegrity),
    .ptInterface = &(ktDFUPInfoInterface),
	.ptTrimCode	= &(ktSWIPInfoTrimCode)
};

static tDFUPEvent_t tDFUPEvent =
{
    .ptEventFormat = &(tDFUPEventFormat_t)
    {
    	.reserved = 0,
		.ePacketFormatId = DFUP_PF_NORMAL,//0, // NOTE : warning제거
		.ucTouchPacketItemSize = 0
    }

    //vtTouchItem은 malloc으로 공간 잡아줌.
    //Packet은 INTR 생성 후 가져갈 때 까지 다른 로직을 수행하므로 scope에 제한받지 않는 dedicated buffer 활용해야 하기 때문임.
};

static tDFUPBufferInfo_t tDFUPBufferInfo  =
{
    .ppucBuffer = (uint8_t**)&vtProtocolBufferPointers,
    .vusStartAddr = (uint16_t [])
    {
        SWIP_REG_ADDR_GENERAL_BUFFER,
        SWIP_REG_ADDR_PARAMETER_BUFFER
    },
    .iSize = sizeof(vtProtocolBufferPointers)/sizeof(void*)
};

static tDFUPSubsetInfo_t* vtMRmiMap[]  =
{
	//[0x00] = NULL,
	[MSB(SWIP_REG_ADDR_INFO)] = &(tDFUPSubsetInfo_t)
	{
		.ppucData = (uint8_t**)&tDFUPInfo,
		.vucStartLAddr = (uint8_t [])
		{
			LSB(SWIP_REG_ADDR_INFO_SECTION_VERSION),
			LSB(SWIP_REG_ADDR_INFO_SECTION_ADDR),
			LSB(SWIP_REG_ADDR_INFO_INTEGRITY),
			LSB(SWIP_REG_ADDR_INFO_INTERFACE),
			LSB(SWIP_REG_ADDR_INFO_TRIMCODE_1),
			LSB(SWIP_REG_ADDR_INFO_TRIMCODE_2)
		},
		.iSize = sizeof(tDFUPInfo)/sizeof(void*)
	},
	[MSB(SWIP_REG_ADDR_CTRL)] = &(tDFUPSubsetInfo_t)
	{
		.ppucData = (uint8_t**)&tProtocolCtrl,
		 .vucStartLAddr = (uint8_t [])
		{
			LSB(SWIP_REG_ADDR_CTRL_GETTER),
			LSB(SWIP_REG_ADDR_CTRL_SETTER)
		},
		.iSize = sizeof(tProtocolCtrl)/sizeof(void*)
	},
//	[MSB(SWIP_REG_ADDR_IMAGE)         ] = NULL,
	[MSB(SWIP_REG_ADDR_LOG)] = &(tDFUPSubsetInfo_t)
	{
		.ppucData = (uint8_t**)&tProtocolLog,
		 .vucStartLAddr = (uint8_t [])
		{
			LSB(SWIP_REG_ADDR_LOG_INFO),
			LSB(SWIP_REG_ADDR_LOG_CONTROL),
			LSB(SWIP_REG_ADDR_LOG_DATA_FORMAT)
		},
		.iSize = sizeof(tProtocolLog)/sizeof(void*)
	},
//	[MSB(SWIP_REG_ADDR_SPECIAL_ACTION)] = NULL,
	[MSB(DFUP_REG_ADDR_FLASH_IAP_CTRL)] = &(tDFUPSubsetInfo_t)
	{
		.ppucData = (uint8_t**)&tFlashIAPPacket,
		 .vucStartLAddr = (uint8_t [])
		{
			LSB(DFUP_REG_ADDR_FLASH_IAP_CTRL_CMD)
		},
		.iSize = sizeof(tFlashIAPPacket)/sizeof(void*)
	},
};

static eProtocolEventTriggerType_t eEventTriggerType = ETT_NONE;

void protocol_dfup_Init(void)
{
	tDFUPInfo.ptVersion->bcdBootVer = BOOT_VER;
	tDFUPInfo.ptVersion->bcdCoreVer = 0xFFFF;
	tDFUPInfo.ptVersion->bcdAppVer  = 0xFFFF;
	tDFUPInfo.ptVersion->bcdParaVer = 0xFFFF;

	tDFUPInfo.ptIntegrity->ulBootCRC = 0x0;//SYSCFG_SPI_BOOT_crc_code_read();
	tDFUPInfo.ptIntegrity->ulAppCRC = 0x0;
	tDFUPInfo.ptIntegrity->ulParamCRC = 0x0;
}

uint8_t* protocol_dfup_GetMappedPointer(uint16_t _addr)
{
    int i;
    uint8_t maddr = MSB(_addr), laddr = LSB(_addr);
    //TODO: remove it! 임시로 기존 프로토콜 사용하기 위해서 작업해 두었습니다.
    if( _addr >= SWIP_REG_ADDR_RESERVED )
        return (uint8_t*)NULL;
	
	if(_addr == 0x0150)
	{
		    if( maddr < GET_ARRAY_(vtMRmiMap) )
    {
    	if(maddr == 0x01)
    	{
            const tDFUPSubsetInfo_t* info = vtMRmiMap[maddr];
            if(info)
            {
                for( i=info->iSize; i--; )
                {
                    int start_addr = info->vucStartLAddr[i];
                    if( laddr >= start_addr )
                        return info->ppucData[i] + laddr - start_addr;
                }
            }
    	}
    	else
    	{
            const tDFUPSubsetInfo_t* info = vtMRmiMap[maddr];
            if(info)
            {
                for( i=info->iSize; i--; )
                {
                    int start_addr = info->vucStartLAddr[i];
                    if( laddr >= start_addr )
                        return info->ppucData[i] + laddr - start_addr;
                }
            }
    	}
    }
    else //16K buffers.
    {
        for( i=tDFUPBufferInfo.iSize; i--; )
        {
            int start_addr = tDFUPBufferInfo.vusStartAddr[i];
            if( _addr >= start_addr)
                return tDFUPBufferInfo.ppucBuffer[i] + _addr - start_addr;
        }
    }
	}
	else
	{
		    if( maddr < GET_ARRAY_(vtMRmiMap) )
    {
    	if(maddr == 0x01)
    	{
            const tDFUPSubsetInfo_t* info = vtMRmiMap[maddr];
            if(info)
            {
                for( i=info->iSize; i--; )
                {
                    int start_addr = info->vucStartLAddr[i];
                    if( laddr >= start_addr )
                        return info->ppucData[i] + laddr - start_addr;
                }
            }
    	}
    	else
    	{
            const tDFUPSubsetInfo_t* info = vtMRmiMap[maddr];
            if(info)
            {
                for( i=info->iSize; i--; )
                {
                    int start_addr = info->vucStartLAddr[i];
                    if( laddr >= start_addr )
                        return info->ppucData[i] + laddr - start_addr;
                }
            }
    	}
    }
    else //16K buffers.
    {
        for( i=tDFUPBufferInfo.iSize; i--; )
        {
            int start_addr = tDFUPBufferInfo.vusStartAddr[i];
            if( _addr >= start_addr)
                return tDFUPBufferInfo.ppucBuffer[i] + _addr - start_addr;
        }
    }
	}

    return (uint8_t*)NULL;
}

void protocol_dfup_ClearEventInterrupt(void)
{
    switch( eEventTriggerType )
    {
    case ETT_INTERRUPT:
       // Hal_ClearIntr();
        break;
    case ETT_REGISTER:
    	tProtocolCtrl.getter->bEventReady = NO;
        break;
    }
}

void protocol_dfup_ClearInterrupt(uint16_t _addr)
{
	if( _addr == SWIP_REG_ADDR_CTRL_GETTER + offsetof(tProtocolGetter_t, eReadyStatus) )
	{
		if( tProtocolCtrl.getter->eReadyStatus != RS_NONE )
			tProtocolCtrl.getter->eReadyStatus = RS_NONE;
	}
	//Touch packet의 마지막 data를 읽어갈 때,
	else if( _addr == SWIP_REG_ADDR_EVENT_PACKET_CONTENT + tDFUPEvent.ptPacketInfo->b7Length - 1)
	{
		protocol_dfup_ClearEventInterrupt();
	}
}

void protocol_dfup_PendReadyStatus(void)
{
    tProtocolCtrl.getter->eReadyStatus = RS_READY;
    while( tProtocolCtrl.getter->eReadyStatus == RS_READY ){
#ifdef MODE_I2C
		QueueCommonData_I2C();
#else
		QueueCommonData_USB();
#endif
	};
}

eProtocolMode_t protocol_dfup_GetMode(void)
{
    return tProtocolCtrl.setter->eMode;
}
