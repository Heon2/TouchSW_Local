/*
 * protocol_log.c
 *
 *  Created on: 2015. 3. 12.
 *      Author: parkyj2
 */

//#include "system_def.h"
//#include "hal_def.h"
//#include "module_def.h"
//#include <stdint.h>
//#include "MFTP.h"
#include "protocol_def.h"
#include "protocol_swip_regmap.h"
#include "protocol_log.h"
#include "hal_def.h"



static tImageInfo_t ktProtocolImageInfo  =
{
	.usBufferAddr = SWIP_REG_ADDR_GENERAL_BUFFER,
	.usProtocolId = LOG_IMAGE_PROTOCOL_ID
};

static tImageControl_t ktProtocolImageControl  =
{
	.eImageType = IT_NONE
};

tProtocolImage_t tProtocolImage  =
{
    .ptInfo = &(ktProtocolImageInfo),
    .ptCtrl = &(ktProtocolImageControl),
    .ptFormat = NULL,
    .pucFinger_ = NULL,
    .ptRect = NULL
};

static tLogInfo_t ktProtocolLogInfo  =
{
	.usBufferAddr = SWIP_REG_ADDR_GENERAL_BUFFER,
	.usProtocolId = SWIP_LOG_PROTOCOL_ID
};

static tLogControl_t ktProtocolLogControl  =
{
	.ulLogMask = _BV(LT_DIAGNOSIS),
	.eTrigger = LTR_NONE
};

tProtocolLog_t tProtocolLog  =
{
    .ptInfo = &(ktProtocolLogInfo),
    .ptControl = &(ktProtocolLogControl),
};

void protocol_LogImage(eImageType_t _type, const tImageDataFmt_t* _ptDataFormat, uint8_t ucFinger_, tRect_t rect[ucFinger_], const void* _pBuf)
{
    if( tProtocolImage.ptCtrl->eImageType == _type )
    {
    	tProtocolImage.ptCtrl->eImageType = IT_WAIT;
        //Set data format.
    	tProtocolImage.ptFormat = _ptDataFormat;

    	tProtocolImage.pucFinger_ = &ucFinger_;
    	tProtocolImage.ptRect = rect;

        //Set buffer address.
        vtProtocolBufferPointers.pGeneralBuffer = (void*)_pBuf;

//#if USED_TPIC_MUXEN_ON_OFF_CONTROL_DISABLE_DATAREAD
//        HAL_SetTPICMuxEnControl(NO);
//#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL_DISABLE_DATAREAD */

#if USED_ECLK_ON_OFF_CONTROL_DISABLE_DATAREAD
		HAL_SetECLKOnOffControl(NO);
#endif /* USED_ECLK_ON_OFF_CONTROL_DISABLE_DATAREAD */

        //Pend wait flag and wait for image type setting.
        tProtocolCtrl.getter->eReadyStatus = RS_IMAGE;
        while( tProtocolImage.ptCtrl->eImageType == IT_WAIT && tProtocolCtrl.setter->eMode == M_TOUCH_NORMAL ) ;

//#if USED_TPIC_MUXEN_ON_OFF_CONTROL_DISABLE_DATAREAD
//        HAL_SetTPICMuxEnControl(YES);
//#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL_DISABLE_DATAREAD */

#if USED_ECLK_ON_OFF_CONTROL_DISABLE_DATAREAD
		HAL_SetECLKOnOffControl(YES);
#endif /* USED_ECLK_ON_OFF_CONTROL_DISABLE_DATAREAD */
    }
}

void protocol_Log(eLogType_t eLogType, const tLogDataFormat_t* _ptDataFormat, const void* _pBuf)
{
    if( tProtocolLog.ptControl->eTrigger == LTR_TRIG )
    {
        if( tProtocolLog.ptControl->ulLogMask & _BV(eLogType) )
        {
        	tProtocolLog.ptControl->eTrigger = LTR_WAIT;
            //Set data format.
        	tProtocolLog.ptDataFormat = _ptDataFormat;

            //Set buffer address.
            vtProtocolBufferPointers.pGeneralBuffer = _pBuf;

//#if USED_TPIC_MUXEN_ON_OFF_CONTROL_DISABLE_DATAREAD
//            HAL_SetTPICMuxEnControl(NO);
//#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL_DISABLE_DATAREAD */

#if USED_ECLK_ON_OFF_CONTROL_DISABLE_DATAREAD
			HAL_SetECLKOnOffControl(NO);
#endif /* USED_ECLK_ON_OFF_CONTROL_DISABLE_DATAREAD */
            //Pend wait flag and wait for image type setting.
            tProtocolCtrl.getter->eReadyStatus = RS_LOG;
            while( tProtocolLog.ptControl->eTrigger == LTR_WAIT ) ;

//#if USED_TPIC_MUXEN_ON_OFF_CONTROL_DISABLE_DATAREAD
//            HAL_SetTPICMuxEnControl(YES);
//#endif /* USED_TPIC_MUXEN_ON_OFF_CONTROL_DISABLE_DATAREAD */

#if USED_ECLK_ON_OFF_CONTROL_DISABLE_DATAREAD
			HAL_SetECLKOnOffControl(YES);
#endif /* USED_ECLK_ON_OFF_CONTROL_DISABLE_DATAREAD */
        }
    }
}

uint32_t protocol_log_get_mode(void)
{
	return tProtocolLog.ptControl->eTrigger;
}

void protocol_log_set_mode(eLogTriggerType_t _m)
{
	tProtocolLog.ptControl->eTrigger = _m;
}
