/*
 * mip4d0.h
 *
 *  Created on: 2015. 3. 16.
 *      Author: parkyj2
 */

#ifndef __SWIP_REGMAP_H__
#define __SWIP_REGMAP_H__

#if defined(SUPPORT_ANDROID)
#define SWIP_REG_ADDR_ANDR_BASE_INFO             0x0000
#define SWIP_REG_ADDR_SPR_CHIP_ID                0x0000
#define SWIP_REG_ADDR_TC_VERSION                 0x0001
#define SWIP_REG_ADDR_CHIP_VERSION               0x0002
#define SWIP_REG_ADDR_TC_PRODUCT_ID              0x0003
#endif

#define SWIP_REG_ADDR_INFO                       0x0100
#define SWIP_REG_ADDR_INFO_PANEL                 0x0100
#define SWIP_REG_ADDR_INFO_SECTION_VERSION       0x0120
#define SWIP_REG_ADDR_INFO_SECTION_ADDR          0x0130
#define SWIP_REG_ADDR_INFO_INTEGRITY             0x0140//0x0148//0x0148
#define SWIP_REG_ADDR_INFO_INTERFACE             0x0150
#define SWIP_REG_ADDR_INFO_EXTRA                 0x0170
#define SWIP_REG_ADDR_INFO_TRIMCODE_1            0x01A0
#define SWIP_REG_ADDR_INFO_TRIMCODE_2            0x01C0

#define SWIP_REG_ADDR_EVENT                      0x0200
#if USED_MOBILE_I2C_PROTOCOL
//#define SWIP_REG_ADDR_EVENT_PACKET_INFO          0x0200
//#define SWIP_REG_ADDR_EVENT_PACKET_CONTENT       0x0211
#define SWIP_REG_ADDR_EVENT_PACKET_FORMAT	     0x0200
#define SWIP_REG_ADDR_EVENT_PACKET_INFO          0x0208
#define SWIP_REG_ADDR_EVENT_PACKET_CONTENT       0x020C
#else /* USED_MOBILE_I2C_PROTOCOL */
#define SWIP_REG_ADDR_EVENT_FORMAT               0x0200
#define SWIP_REG_ADDR_EVENT_PACKET_INFO          0x0210
#define SWIP_REG_ADDR_EVENT_PACKET_CONTENT       0x0211
#endif /* USED_MOBILE_I2C_PROTOCOL */

#if defined(SUPPORT_ANDROID)
#define SWIP_REG_ADDR_ANDROID_EVENT              0x0300
#define SWIP_REG_ADDR_ANDROID_IC_STATUS          0x0300
#define SWIP_REG_ADDR_ANDROID_TC_STATUS          0x0301
#define SWIP_REG_ADDR_ANDROID_TOUCH_INFO         0x0302
#define SWIP_REG_ADDR_ANDROID_PACKET_DATA        0x0303

#define SWIP_REG_ADDR_SPR_CHIP_INFO              0x0400
#define SWIP_REG_ADDR_SPR_CHIP_TEST              0x0400
#define SWIP_REG_ADDR_SPR_BOOT_STS               0x0401
#define SWIP_REG_ADDR_TC_DEVICE_CTL              0x0402
#define SWIP_REG_ADDR_TC_INTERRUPT_CTL           0x0403
#define SWIP_REG_ADDR_IME_STATE                  0x0404
#define SWIP_REG_ADDR_TCI_ENABLE_W               0x0405
#define SWIP_REG_ADDR_SWIPE_ENABLE_W             0x0406
#define SWIP_REG_ADDR_SPR_SUBDISP_STS            0x0407
#define SWIP_REG_ADDR_TC_DRIVE_CTL               0x0408
#endif

#define SWIP_REG_ADDR_CTRL                       0x0600
#define SWIP_REG_ADDR_CTRL_GETTER                0x0600
#define SWIP_REG_ADDR_CTRL_SETTER                0x0610

#define SWIP_REG_ADDR_PARAMETER                  0x0800
#define SWIP_REG_ADDR_PARAMETER_INFO             0x0800
//#define SWIP_REG_ADDR_PARAMETER_CONTROL          0x0810

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
#define SWIP_REG_ADDR_PWMDRV_FOR_TUNING          0x1210
#define SWIP_REG_ADDR_DRIVER_FOR_TUNING          0x1230

#define SWIP_REG_ADDR_FLASH_IAP_CTRL			 0x1400
#define SWIP_REG_ADDR_FLASH_IAP_CTRL_CMD		 0x1400
//#define SWIP_REG_ADDR_FLASH_IAP_CTRL_STATUS	 	 0x1401
//#define SWIP_REG_ADDR_FLASH_IAP_CTRL_SIZE		 0x1402
//#define SWIP_REG_ADDR_FLASH_IAP_CTRL_ADDR		 0x1404
//#define SWIP_REG_ADDR_FLASH_IAP_CTRL_BUFFER		 0x1408

#define SWIP_REG_ADDR_GENERAL_BUFFER             0x2000
#define SWIP_REG_ADDR_PARAMETER_BUFFER           0x6000
#define SWIP_REG_ADDR_RESERVED                   0xF000

#endif /* __SWIP_REGMAP_H__ */
