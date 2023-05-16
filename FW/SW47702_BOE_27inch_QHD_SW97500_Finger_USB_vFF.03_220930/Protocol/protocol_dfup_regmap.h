/*
 * mip4d0.h
 *
 *  Created on: 2015. 3. 16.
 *      Author: parkyj2
 */

#ifndef __DFUP_REGMAP_H__
#define __DFUP_REGMAP_H__

#define SWIP_REG_ADDR_INFO                       0x0100
#define SWIP_REG_ADDR_INFO_PANEL                 0x0100
#define SWIP_REG_ADDR_INFO_SECTION_VERSION       0x0120
#define SWIP_REG_ADDR_INFO_SECTION_ADDR          0x0130
#define SWIP_REG_ADDR_INFO_INTEGRITY             0x0140
#define SWIP_REG_ADDR_INFO_INTERFACE             0x0150
#define SWIP_REG_ADDR_INFO_EXTRA                 0x0170
#define SWIP_REG_ADDR_INFO_TRIMCODE_1            0x01A0
#define SWIP_REG_ADDR_INFO_TRIMCODE_2            0x01C0

#define SWIP_REG_ADDR_EVENT                      0x0200
#define SWIP_REG_ADDR_EVENT_FORMAT               0x0200
#define SWIP_REG_ADDR_EVENT_PACKET_INFO          0x0210
#define SWIP_REG_ADDR_EVENT_PACKET_CONTENT       0x0211

#define DFUP_REG_ADDR_FLASH_CTRL			 	 0x0300
#define DFUP_REG_ADDR_FLASH_CTRL_CMD			 0x0300
#define DFUP_REG_ADDR_FLASH_CTRL_STATUS 		 0x0310

#define DFUP_REG_ADDR_FLASH_IAP_CTRL			 0x1400
#define DFUP_REG_ADDR_FLASH_IAP_CTRL_CMD		 0x1400
#define DFUP_REG_ADDR_FLASH_IAP_CTRL_STATUS	 	 0x1401
#define DFUP_REG_ADDR_FLASH_IAP_CTRL_SIZE		 0x1402
#define DFUP_REG_ADDR_FLASH_IAP_CTRL_ADDR		 0x1404
#define DFUP_REG_ADDR_FLASH_IAP_CTRL_BUFFER		 0x1408

#define SWIP_REG_ADDR_CTRL                       0x0600
#define SWIP_REG_ADDR_CTRL_GETTER                0x0600
#define SWIP_REG_ADDR_CTRL_SETTER                0x0610

#define SWIP_REG_ADDR_PARAMETER                  0x0800
#define SWIP_REG_ADDR_PARAMETER_INFO             0x0800
#define SWIP_REG_ADDR_PARAMETER_CONTROL          0x0810

#define SWIP_REG_ADDR_TEST                       0x0A00
#define SWIP_REG_ADDR_TEST_CM_INFO               0x0A00
#define SWIP_REG_ADDR_TEST_CM_CONTROL            0x0A10
#define SWIP_REG_ADDR_TEST_CM_DATA_FORMAT        0x0A20

#define SWIP_REG_ADDR_IMAGE                      0x0C00
#define SWIP_REG_ADDR_IMAGE_INFO                 0x0C00
#define SWIP_REG_ADDR_IMAGE_CONTROL              0x0C10
#define SWIP_REG_ADDR_IMAGE_DATA_FORMAT          0x0C20
#define SWIP_REG_ADDR_IMAGE_FINGER_NUM           0x0C30
#define SWIP_REG_ADDR_IMAGE_FINGER_AREA          0x0C31

#define SWIP_REG_ADDR_LOG                        0x1000
#define SWIP_REG_ADDR_LOG_INFO                   0x1000
#define SWIP_REG_ADDR_LOG_CONTROL                0x1010
#define SWIP_REG_ADDR_LOG_DATA_FORMAT            0x1020

#define SWIP_REG_ADDR_SPECIAL_ACTION             0x1200
#define SWIP_REG_ADDR_CONTROL_FOR_TUNING         0x1200

#define SWIP_REG_ADDR_GENERAL_BUFFER             0x2000
#define SWIP_REG_ADDR_PARAMETER_BUFFER           0x6000
#define SWIP_REG_ADDR_RESERVED                   0xF000

#endif /* __SWIP_REGMAP_H__ */
