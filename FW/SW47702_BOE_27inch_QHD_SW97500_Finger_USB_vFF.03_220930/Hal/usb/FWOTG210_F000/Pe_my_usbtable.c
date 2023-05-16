#include "env_def.h"
#include "FOTG200_peripheral.h"


#ifndef MODE_I2C

 // Full speed Configuration
 uint8_t u8_FS_DeviceDesc[DEVICE_DESC_LENGTH] =
 {
	  DEVICE_DESC_LENGTH,
	  DT_DEVICE,
	  LSB(DEVICE_USB_SPEC_VER), MSB(DEVICE_USB_SPEC_VER),
	  DEVICE_CLASS,
	  DEVICE_SUB_CLASS,
	  DEVICE_PROTOCOL,
	  EP0_MAX_PACKET_SIZE,
	  LSB(DEVICE_VENDOR_ID), MSB(DEVICE_VENDOR_ID),
	  LSB(DEVICE_PRODUCT_ID), MSB(DEVICE_PRODUCT_ID),
#if (CUSTOMER == MODEL_DEF_FHD_92504_Sony_Oliver_WGP_Pen)
	  LSB(APP_VERSION), MSB(APP_VERSION),
#else
	  LSB(DEVICE_DEVICE_RELEASE_NO), MSB(DEVICE_DEVICE_RELEASE_NO),
#endif
	  DEVICE_MANUFACTURER,
	  DEVICE_PRODUCT,
	  DEVICE_SERIALNUMBER,
	  DEVICE_CONFIG_NUMBER
 };



 uint8_t u8_FS_ConfigDesc[CONFIG_DESC_LENGTH] =
 {
	  // Configuration descriptor
	 CONFIG_LENGTH, 
	 DT_CONFIGURATION, 
	 LSB(CONFIG_DESC_LENGTH), MSB(CONFIG_DESC_LENGTH), 
	 INTERFACE_COUNT,
	 0x01, 
	 0x00, 
	 (ATTRIBUTE_REMOTE_WAKE_UP | ATTRIBUTE_BUS_POWERD | ATTRIBUTE_RESERVED),
	 DEVICE_MAX_POWER,

#if TOUCH_ENABLE
	  //Interface Association descriptor
	  IAD_LENGTH, DT_IAD, TOUCH_INTERFACE_NUM, 0x01, FUNCTION_CLASS__HID, 0x00, 0x00, 0x00,

	  // Interface descriptor
	  INTERFACE_LENGTH, DT_INTERFACE, TOUCH_INTERFACE_NUM, 0x00, TOUCH_ENDPOINT_COUNT, INTERFACE_CLASS__HID, INTERFACE_SUB_CLASS__NONE, INTERFACE_PROTOCOL__NONE, 0x00,

	  // HID
	  HID_LENGTH, SETUPPACKET_DESCRIPTOR__HID, LSB(HID_VERSION), MSB(HID_VERSION), 0x00, 0x01, SETUPPACKET_DESCRIPTOR__REPORT, LSB(HID_MULTITOUCH_DESC_TOTAL_LENGTH), MSB(HID_MULTITOUCH_DESC_TOTAL_LENGTH),

	  // EndPoint
#if TOUCH_OUT_EP_ADD
	  ENDPOINT_LENGTH, DT_ENDPOINT, (EP_OUT | TOUCH_OUT_EP_NUM), EP_TRANSFER_TYPE__INTERRUPT, LSB(TOUCH_OUT_EP_SIZE), MSB(TOUCH_OUT_EP_SIZE), 0x01,
#endif

#if TOUCH_IN_EP_ADD
	  // EndPoint
	  ENDPOINT_LENGTH, DT_ENDPOINT, (EP_IN | TOUCH_IN_EP_NUM), EP_TRANSFER_TYPE__INTERRUPT, LSB(TOUCH_IN_EP_SIZE), MSB(TOUCH_IN_EP_SIZE), 0x01,
#endif
#endif

	 
	 
#if CUSTOM_ENABLE
	  //Interface Association descriptor
	  IAD_LENGTH, DT_IAD, CUSTOM_INTERFACE_NUM, 0x01, FUNCTION_CLASS__HID, 0x00, 0x00, 0x00,

	  // Interface descriptor
	  INTERFACE_LENGTH, DT_INTERFACE, CUSTOM_INTERFACE_NUM, 0x00, CUSTOM_ENDPOINT_COUNT, INTERFACE_CLASS__HID, INTERFACE_SUB_CLASS__NONE, INTERFACE_PROTOCOL__NONE, 0x00,

	  // HID
	  HID_LENGTH, SETUPPACKET_DESCRIPTOR__HID, LSB(HID_VERSION), MSB(HID_VERSION), 0x00, 0x01, SETUPPACKET_DESCRIPTOR__REPORT, LSB(HID_CUSTOM_DESC_LENGTH), MSB(HID_CUSTOM_DESC_LENGTH),

	  // EndPoint
#if CUSTOM_OUT_EP_ADD
	  ENDPOINT_LENGTH, DT_ENDPOINT, (EP_OUT | CUSTOM_OUT_EP_NUM), EP_TRANSFER_TYPE__INTERRUPT, LSB(CUSTOM_OUT_EP_SIZE), MSB(CUSTOM_OUT_EP_SIZE), 0x01,
#endif

	  // EndPoint
#if CUSTOM_IN_EP_ADD
	  ENDPOINT_LENGTH, DT_ENDPOINT, (EP_IN | CUSTOM_IN_EP_NUM), EP_TRANSFER_TYPE__INTERRUPT, LSB(CUSTOM_IN_EP_SIZE), MSB(CUSTOM_IN_EP_SIZE), 0x01,
#endif
#endif
	


#if PEN_ENABLE
	  //Interface Association descriptor
	  IAD_LENGTH, DT_IAD, PEN_INTERFACE_NUM, 0x01, FUNCTION_CLASS__HID, 0x00, 0x00, 0x00,

	  // Interface descriptor
	  INTERFACE_LENGTH, DT_INTERFACE, PEN_INTERFACE_NUM, 0x00, PEN_ENDPOINT_COUNT, INTERFACE_CLASS__HID, INTERFACE_SUB_CLASS__NONE, INTERFACE_PROTOCOL__NONE, 0x00,

	  // HID
	  HID_LENGTH, SETUPPACKET_DESCRIPTOR__HID, LSB(HID_VERSION), MSB(HID_VERSION), 0x00, 0x01, SETUPPACKET_DESCRIPTOR__REPORT, LSB(HID_PEN_DESC_LENGTH), MSB(HID_PEN_DESC_LENGTH),

	  // EndPoint
#if PEN_OUT_EP_ADD
	  ENDPOINT_LENGTH, DT_ENDPOINT, (EP_OUT | PEN_OUT_EP_NUM), EP_TRANSFER_TYPE__INTERRUPT, LSB(PEN_OUT_EP_SIZE), MSB(PEN_OUT_EP_SIZE), 0x01,
#endif

	  // EndPoint
#if PEN_IN_EP_ADD
	  ENDPOINT_LENGTH, DT_ENDPOINT, (EP_IN | PEN_IN_EP_NUM), EP_TRANSFER_TYPE__INTERRUPT, LSB(PEN_IN_EP_SIZE), MSB(PEN_IN_EP_SIZE), 0x01,
#endif
#endif



#if BULK_CUSTOM_ENABLE
	  //Interface Association descriptor
	  IAD_LENGTH, DT_IAD, BULK_CUSTOM_INTERFACE_NUM, 0x01, FUNCTION_CLASS__0xFF, 0x00, 0x00, 0x00,

	  // Interface descriptor
	  INTERFACE_LENGTH, DT_INTERFACE, BULK_CUSTOM_INTERFACE_NUM, 0x00, BULK_CUSTOM_ENDPOINT_COUNT, FUNCTION_CLASS__0xFF, INTERFACE_SUB_CLASS__NONE, INTERFACE_PROTOCOL__NONE, 0x00,

	  // EndPoint
#if BULK_CUSTOM_OUT_EP_ADD
	  ENDPOINT_LENGTH, DT_ENDPOINT, (EP_OUT | BULK_CUSTOM_OUT_EP_NUM), EP_TRANSFER_TYPE__BULK, LSB(BULK_CUSTOM_OUT_EP_SIZE), MSB(BULK_CUSTOM_OUT_EP_SIZE), 0x01,
#endif

	  // EndPoint
#if BULK_CUSTOM_IN_EP_ADD
	  ENDPOINT_LENGTH, DT_ENDPOINT, (EP_IN | BULK_CUSTOM_IN_EP_NUM), EP_TRANSFER_TYPE__BULK, LSB(BULK_CUSTOM_IN_EP_SIZE), MSB(BULK_CUSTOM_IN_EP_SIZE), 0x01,
#endif
#endif

 };



 uint8_t u8O_StrDesc_LangIDs[STRING_LANG_IDS_LENGTH] =
 {
	 STRING_LANG_IDS_LENGTH,
	 DT_STRING,
	 0X09, // LANGID: English (US)
	 0X04,
  };

 // "SiW HID Touch Controller"
 uint8_t u8O_StrDesc_Product[STRING_PRODUCT_LENGTH] =
 {
	 STRING_PRODUCT_LENGTH,
	 DT_STRING,
	 'S',  0x00,
	 'i',  0x00,
	 'W',  0x00,
	 ' ',  0x00,
	 'H',  0x00,
	 'I',  0x00,
	 'D',  0x00,
	 ' ',  0x00,
	 'T',  0x00,
	 'o',  0x00,
	 'u',  0x00,
	 'c',  0x00,
	 'h',  0x00,
	 ' ',  0x00,
	 'C',  0x00,
	 'o',  0x00,
	 'n',  0x00,
	 't',  0x00,
	 'r',  0x00,
	 'o',  0x00,
	 'l',  0x00,
	 'l',  0x00,
	 'e',  0x00,
	 'r',  0x00
 };

 // "Siliconworks"
 uint8_t u8O_StrDesc_Manufacturer[STRING_MANUFACTURER_LENGTH] =
 {
	 STRING_MANUFACTURER_LENGTH,
	 DT_STRING,
	 'S',	0x00,
	 'i',  0x00,
	 'l',  0x00,
	 'i',  0x00,
	 'c',  0x00,
	 'o',  0x00,
	 'n',  0x00,
	 'w',  0x00,
	 'o',  0x00,
	 'r',  0x00,
	 'k',  0x00,
	 's',  0x00,
 };



#ifdef USB_SELECTIVE_SUSPEND
 BOS_DESCRIPTOR						BOS_Descriptor = { 0, };
 MS_OS_STRING_DESCRIPTOR			MS_OS_Descriptor = { 0, };
 COMPATIBLE_ID_FEATURE_DESCRIPTOR	MS_OS_CompatibleID = { 0, };
 PROPERTIES_DESCRIPTOR				MS_OS_Property = { 0, };
#endif

#endif


#ifdef ADD_TOUCH

// HID Multi-Touch
uint8_t u8_HID_MultiTouch_Descriptor_Head[HID_MULTITOUCH_DESC_HEAD_LENGTH] =
{
	0x05, 0x0d,                         // USAGE_PAGE (Digitizers)
	0x09, 0x04,                         // USAGE (Touch Screen)
	0xa1, 0x01,                         // COLLECTION (Application)
	0x85, HID_REPORT_ID__MULTI_TOUCH    //   REPORT_ID (Touch)	
};

uint8_t u8_HID_MultiTouch_Descriptor_Main[HID_MULTITOUCH_DESC_MAIN_LENGTH] =
{
	// Tip Switch
	0x05, 0x0d,							// USAGE_PAGE (Digitizers)
	0x09, 0x22,                         //   USAGE (Finger)
	0xa1, 0x02,                         //     COLLECTION (Logical)
	0x09, 0x42,                         //       USAGE (Tip Switch)
	0x15, 0x00,                         //       LOGICAL_MINIMUM (0)
	0x25, 0x01,                         //       LOGICAL_MAXIMUM (1)
	0x75, 0x01,                         //       REPORT_SIZE (1)
	0x95, 0x01,                         //       REPORT_COUNT (1)
	0x81, 0x02,                         //       INPUT (Data,Var,Abs)
	0x95, 0x07,                         //       REPORT_COUNT (7)
	0x81, 0x03,                         //       INPUT (Cnst,Var,Abs)

	// ID
	0x75, 0x08,                         //       REPORT_SIZE (8)
	0x09, 0x51,                         //       USAGE (Contact Identifier)
	0x95, 0x01,                         //       REPORT_COUNT (1)
	0x81, 0x02,                         //       INPUT (Data,Var,Abs)

	// X, Y
	0x05, 0x01,                         //       USAGE_PAGE (Generic Desk..
	0x26, LSB(X_LOGICAL_MAX), MSB(X_LOGICAL_MAX), // LOGICAL_MAXIMUM (32767)
	0x75, 0x10,                         //       REPORT_SIZE (16)
	0x55, 0x0D,                         //       UNIT_EXPONENT (-3)
	0x65, 0x11,                         //       UNIT(SI Lin, Distance)
	0x09, 0x30,                         //       USAGE (X)
	0x35, 0x00,                         //       PHYSICAL_MINIMUM (0)
	0x47, LSB2(X_PHYSICAL_MAX), LSB1(X_PHYSICAL_MAX), MSB2(X_PHYSICAL_MAX), MSB1(X_PHYSICAL_MAX),   //    PHYSICAL_MAXIMUM
	0x95, 0x01,                         //       REPORT_COUNT (1)
	0x81, 0x02,                         //       INPUT (Data,Var,Abs)
	0x09, 0x31,                         //       USAGE (Y)
	0x47, LSB2(Y_PHYSICAL_MAX), LSB1(Y_PHYSICAL_MAX), MSB2(Y_PHYSICAL_MAX), MSB1(Y_PHYSICAL_MAX),   //    PHYSICAL_MAXIMUM
	0x26, LSB(Y_LOGICAL_MAX), MSB(Y_LOGICAL_MAX), // LOGICAL_MAXIMUM
	0x81, 0x02,                         //       INPUT (Data,Var,Abs)
	0xc0                               //    END_COLLECTION
};

uint8_t u8_HID_MultiTouch_Descriptor_Tail[HID_MULTITOUCH_DESC_TAIL_LENGTH] =
{
	// Contact Count
	0x05, 0x0d,                         //    USAGE_PAGE (Digitizers)
	0x09, 0x54,                         //   USAGE (Contact count)
	0x25, 0x7f,                           //   LOGICAL_MAXIMUM (127)
	0x95, 0x01,                         //   REPORT_COUNT (1)
	0x75, 0x08,                         //   REPORT_SIZE (8)
	0x81, 0x02,                         //   INPUT (Data,Var,Abs)

	// Scan Time
	0x05, 0x0d,													//	USAGE_PAGE (Digitizers)
	0x55, 0x0C,													//	UNIT_EXPONENT (-4)
	0x66, 0x01, 0x10,											//	UNIT (Seconds)
	0x47, LSB(SCAN_TIME_MAX), MSB(SCAN_TIME_MAX), 0x00, 0x00,	//	PHYSICAL_MAXIMUM (65535)
	0x27, LSB(SCAN_TIME_MAX), MSB(SCAN_TIME_MAX), 0x00, 0x00,	//	LOGICAL_MAXIMUM (65535)
	0x75, 0x10,													//	REPORT_SIZE (16)
	0x95, 0x01,													//	REPORT_COUNT (1)
	0x09, 0x56,													//	USAGE (Scan Time)
	0x81, 0x02,													//	INPUT (Data,Var,Abs)

	// MAX Count
	0x85, HID_REPORT_ID__CONTACT_COUNT, //   REPORT_ID (Feature)
	0x09, 0x55,                         //   USAGE(Contact Count Maximum)
	0x75, 0x08,                         //   REPORT_SIZE (8)
	0x95, 0x01,                         //   REPORT_COUNT (1)
	0x25, 0x0A,                         //   LOGICAL_MAXIMUM (10)
	0xb1, 0x02,                         //   FEATURE (Data,Var,Abs)

	// Touch Hardware Quality Assurance (Blob Code)
	0x85, HID_REPORT_ID__BLOB_CODE,		//	REPORT_ID (Blob Code) 
	0x06, 0x00, 0xFF,					//	USAGE_PAGE (Vendor Defined)
	0x09, 0xC5,							//  USAGE (Vendor Usage 0xC5)
	0x15, 0x00,							//  LOGICAL_MINIMUM (0) 
	0x26, 0xFF, 0x00,					//  LOGICAL_MAXIMUM (0xff)
	0x75, 0x08,							//  REPORT_SIZE (8)
	0x96, 0x00, 0x01,					//  REPORT_COUNT (0x100 (256))
	0xb1, 0x02,							//  FEATURE (Data,Var,Abs)

#ifdef LATENCY_MODE
	0x85, HID_REPORT_ID__LATENCY_MODE,	//    REPORT_ID (Latency)              
	0x09, 0x60,                         //    USAGE(Latency Mode)
	0x75, 0x01,                         //    REPORT_SIZE (1) 
	0x95, 0x01,                         //    REPORT_COUNT (1)
	0x15, 0x00,                         //    LOGICAL_MINIMUM (0)
	0x25, 0x01,                         //    LOGICAL_MAXIMUM (1)
	0xb1, 0x02,                         //    FEATURE (Data,Var,Abs)
	0x95, 0x07,                         //    REPORT_COUNT (7)             
	0xb1, 0x03,                         //    FEATURE (Cnst,Var,Abs)  
#endif

	0xc0,                              // END_COLLECTION		

#if (DEVICE_MODE_LENGTH > 0)
	// Device Mode
	0x05, 0x0D,
	0x09, 0x0E,
	0xa1, 0x01,
	0x85, HID_REPORT_ID__DEVICE_MODE,
	0x09, 0x22,
	0xa1, 0x00,
	0x09, 0x52,
	0x09, 0x53,
	0x15, 0x00,
	0x25, 0x0a,
	0x75, 0x08,
	0x95, 0x02,
	0xb1, 0x02,
	0xc0,
	0xc0,
#endif


#if (MOUSE_LENGTH > 0)
	// Mouse
	 0x05, 0x01,
	 0x09, 0x02,
	 0xA1, 0x01,
	 0x85, HID_REPORT_ID__MOUSE,
	 0x09, 0x01,
	 0xA1, 0x00,
	 0x05, 0x09,
	 0x19, 0x01,
	 0x29, 0x03,
	 0x15, 0x00,
	 0x25, 0x01,
	 0x95, 0x03,
	 0x75, 0x01,
	 0x81, 0x02,
	 0x95, 0x01,
	 0x75, 0x05,
	 0x81, 0x03,
	 0x05, 0x01,
	 0x09, 0x30,
	 0x09, 0x31,
	 0x09, 0x38,
	 0x15, 0x81,
	 0x25, 0x7F,
	 0x75, 0x08,
	 0x95, 0x03,
	 0x81, 0x06,
	 0xC0,
	 0xC0

#endif
};


// HID Blob Code
uint8_t u8_HID_Touch_Blob[HID_TOUCH_BLOB_LENGTH] =
{
	HID_REPORT_ID__BLOB_CODE,
	0xfc, 0x28, 0xfe, 0x84, 0x40, 0xcb, 0x9a, 0x87,
	0x0d, 0xbe, 0x57, 0x3c, 0xb6, 0x70, 0x09, 0x88,
	0x07, 0x97, 0x2d, 0x2b, 0xe3, 0x38, 0x34, 0xb6,
	0x6c, 0xed, 0xb0, 0xf7, 0xe5, 0x9c, 0xf6, 0xc2,
	0x2e, 0x84, 0x1b, 0xe8, 0xb4, 0x51, 0x78, 0x43,
	0x1f, 0x28, 0x4b, 0x7c, 0x2d, 0x53, 0xaf, 0xfc,
	0x47, 0x70, 0x1b, 0x59, 0x6f, 0x74, 0x43, 0xc4,
	0xf3, 0x47, 0x18, 0x53, 0x1a, 0xa2, 0xa1, 0x71,
	0xc7, 0x95, 0x0e, 0x31, 0x55, 0x21, 0xd3, 0xb5,
	0x1e, 0xe9, 0x0c, 0xba, 0xec, 0xb8, 0x89, 0x19,
	0x3e, 0xb3, 0xaf, 0x75, 0x81, 0x9d, 0x53, 0xb9,
	0x41, 0x57, 0xf4, 0x6d, 0x39, 0x25, 0x29, 0x7c,
	0x87, 0xd9, 0xb4, 0x98, 0x45, 0x7d, 0xa7, 0x26,
	0x9c, 0x65, 0x3b, 0x85, 0x68, 0x89, 0xd7, 0x3b,
	0xbd, 0xff, 0x14, 0x67, 0xf2, 0x2b, 0xf0, 0x2a,
	0x41, 0x54, 0xf0, 0xfd, 0x2c, 0x66, 0x7c, 0xf8,
	0xc0, 0x8f, 0x33, 0x13, 0x03, 0xf1, 0xd3, 0xc1,
	0x0b, 0x89, 0xd9, 0x1b, 0x62, 0xcd, 0x51, 0xb7,
	0x80, 0xb8, 0xaf, 0x3a, 0x10, 0xc1, 0x8a, 0x5b,
	0xe8, 0x8a, 0x56, 0xf0, 0x8c, 0xaa, 0xfa, 0x35,
	0xe9, 0x42, 0xc4, 0xd8, 0x55, 0xc3, 0x38, 0xcc,
	0x2b, 0x53, 0x5c, 0x69, 0x52, 0xd5, 0xc8, 0x73,
	0x02, 0x38, 0x7c, 0x73, 0xb6, 0x41, 0xe7, 0xff,
	0x05, 0xd8, 0x2b, 0x79, 0x9a, 0xe2, 0x34, 0x60,
	0x8f, 0xa3, 0x32, 0x1f, 0x09, 0x78, 0x62, 0xbc,
	0x80, 0xe3, 0x0f, 0xbd, 0x65, 0x20, 0x08, 0x13,
	0xc1, 0xe2, 0xee, 0x53, 0x2d, 0x86, 0x7e, 0xa7,
	0x5a, 0xc5, 0xd3, 0x7d, 0x98, 0xbe, 0x31, 0x48,
	0x1f, 0xfb, 0xda, 0xaf, 0xa2, 0xa8, 0x6a, 0x89,
	0xd6, 0xbf, 0xf2, 0xd3, 0x32, 0x2a, 0x9a, 0xe4,
	0xcf, 0x17, 0xb7, 0xb8, 0xf4, 0xe1, 0x33, 0x08,
	0x24, 0x8b, 0xc4, 0x43, 0xa5, 0xe5, 0x24, 0xc2
};

#endif




#ifdef ADD_CUSTOM
// HID Custom
uint8_t u8_HID_Custom_Descriptor[HID_CUSTOM_DESC_LENGTH] =
{
	0x06, 0x00, 0xFF,						// USAGE_PAGE (Custom)
	0x09, 0x01,								// USAGE (0xFF)
	0xA1, 0x01,								// COLLECTION (Application)

	0x85, HID_REPORT_ID__CUSTOM_OUT,		// REPORT_ID
	0x09, 0x02,								// USAGE (0x02)
	0x15, 0x00,								// LOGICAL_MINIMUM (0x00)
	0x26, 0xFF, 0x00,	                    // REPORT_COUNT (0x03F or 0x3FF)
	0x75, 0x08,								// REPORT_SIZE (0x08)
	0x95, 0x3F,								// REPORT_COUNT (0x03F or 0x3FF)
	0x91, 0x00,								// OUT

	0x85, HID_REPORT_ID__CUSTOM_IN,			// REPORT_ID
	0x09, 0x03,								// USAGE (0x03)
	0x15, 0x00,								// LOGICAL_MINIMUM (0x00)
	0x26, 0xFF, 0x00,   					// LOGICAL_MAXIMUM (0xFF)
	0x75, 0x08,								// REPORT_SIZE (0x08)
	0x95, 0x3F,								// REPORT_COUNT (0x03F or 0x3FF)
	0x81, 0x00,								// IN

	// Get Feature - 2 Byte
	0x85, HID_REPORT_ID__FEATURE_2,			// REPORT_ID       
	0x75, 0x08,                         	// REPORT_SIZE (8) 
	0x95, 0x02,                         	// REPORT_COUNT (0x02)
	0x09, 0x04,                         	// USAGE (0x04)
	0x46, 0xFF, 0x00,						// PHYSICAL_MAXIMUM (0xFF)
	0x15, 0x00,                         	// LOGICAL_MINIMUM (0)
	0x26, 0xFF, 0x00,   					// LOGICAL_MAXIMUM (0xFF)     
	0xb1, 0x02,                         	// FEATURE

	// Get Feature - 4 Byte
	0x85, HID_REPORT_ID__FEATURE_4,			// REPORT_ID       
	0x75, 0x08,                         	// REPORT_SIZE (8) 
	0x95, 0x04,                         	// REPORT_COUNT (0x04)
	0x09, 0x05,                         	// USAGE (0x05)
	0x46, 0xFF, 0x00,						// PHYSICAL_MAXIMUM (0xFF)
	0x15, 0x00,                         	// LOGICAL_MINIMUM (0)
	0x26, 0xFF, 0x00,   					// LOGICAL_MAXIMUM (0xFF)     
	0xb1, 0x02,                         	// FEATURE

	// Get Feature - 6 Byte
	0x85, HID_REPORT_ID__FEATURE_6,			// REPORT_ID       
	0x75, 0x08,                         	// REPORT_SIZE (8) 
	0x95, 0x06,                         	// REPORT_COUNT (0x06)
	0x09, 0x06,                         	// USAGE (0x06)
	0x46, 0xFF, 0x00,						// PHYSICAL_MAXIMUM (0xFF)
	0x15, 0x00,                         	// LOGICAL_MINIMUM (0)
	0x26, 0xFF, 0x00,   					// LOGICAL_MAXIMUM (0xFF)     
	0xb1, 0x02,                         	// FEATURE

	// Get Feature - 20 Byte
	0x85, HID_REPORT_ID__FEATURE_20,		// REPORT_ID       
	0x75, 0x08,                         	// REPORT_SIZE (8) 
	0x95, 0x14,                         	// REPORT_COUNT (0x14)
	0x09, 0x07,                         	// USAGE (0x07)
	0x46, 0xFF, 0x00,						// PHYSICAL_MAXIMUM (0xFF)
	0x15, 0x00,                         	// LOGICAL_MINIMUM (0)
	0x26, 0xFF, 0x00,   					// LOGICAL_MAXIMUM (0xFF)     
	0xb1, 0x02,                         	// FEATURE

	// Get Feature - 60 Byte
	0x85, HID_REPORT_ID__FEATURE_60,		// REPORT_ID       
	0x75, 0x08,                         	// REPORT_SIZE (8) 
	0x95, 0x3C,                         	// REPORT_COUNT (0x3C)
	0x09, 0x07,                         	// USAGE (0x07)
	0x46, 0xFF, 0x00,						// PHYSICAL_MAXIMUM (0xFF)
	0x15, 0x00,                         	// LOGICAL_MINIMUM (0)
	0x26, 0xFF, 0x00,   					// LOGICAL_MAXIMUM (0xFF)     
	0xb1, 0x02,                         	// FEATURE

	0xC0									// END COLLECTION
};
#endif


#ifdef ADD_PEN
// HID Pen
uint8_t u8_HID_Pen_Descriptor[HID_PEN_DESC_LENGTH] =
{
	0x05, 0x0d,                         // USAGE_PAGE (Digitizers)          
	0x09, 0x02,                         // USAGE (Pen)      
	0xa1, 0x01,                         // COLLECTION (Application)         
	0x85, HID_REPORT_ID__PEN,           //   REPORT_ID (Pen)                
	0x09, 0x20,                         //   USAGE (Stylus)    

	0xa1, 0x00,                         //   COLLECTION (Physical)       
	0x09, 0x42,                         //     USAGE (Tip Switch)           
	0x09, 0x44,                         //     USAGE (Barrel Switch)        
	0x09, 0x3c,                         //     USAGE (Invert)               
	0x09, 0x45,                         //     USAGE (Eraser Switch)        
	0x15, 0x00,                         //     LOGICAL_MINIMUM (0)          
	0x25, 0x01,                         //     LOGICAL_MAXIMUM (1)          
	0x75, 0x01,                         //     REPORT_SIZE (1)              
	0x95, 0x04,                         //     REPORT_COUNT (4)             
	0x81, 0x02,                         //     INPUT (Data,Var,Abs)         
	0x95, 0x01,                         //     REPORT_COUNT (1)             
	0x81, 0x03,                         //     INPUT (Cnst,Var,Abs)         
	0x09, 0x32,                         //     USAGE (In Range)             
	0x81, 0x02,                         //     INPUT (Data,Var,Abs)         
	0x95, 0x02,                         //     REPORT_COUNT (2)             
	0x81, 0x03,                         //     INPUT (Cnst,Var,Abs)         

	// X, Y
	0x05, 0x01,											// USAGE_PAGE (Generic Desktop) 
	0x09, 0x30,											// USAGE (X)                    
	0x75, 0x10,											// REPORT_SIZE (16)             
	0x95, 0x01,											// REPORT_COUNT (1)             
	0xa4,												// PUSH                         
	0x55, 0x0d,											// UNIT_EXPONENT (-3)
	0x65, 0x11,											// UNIT(cm,EngLinear)
	0x26, LSB(X_LOGICAL_MAX), MSB(X_LOGICAL_MAX),		// LOGICAL_MAXIMUM (32767)
	0x35, 0x00,											// PHYSICAL_MINIMUM (0)         
	0x46, LSB(X_PHYSICAL_MAX), MSB(X_PHYSICAL_MAX),		// PHYSICAL_MAXIMUM (29.376)
	0x81, 0x42,											// INPUT (Data,Var,Abs)         
	0x09, 0x31,											// USAGE (Y)                    
	0x46, LSB(Y_PHYSICAL_MAX), MSB(Y_PHYSICAL_MAX),		// PHYSICAL_MAXIMUM (16.524)
	0x26, LSB(Y_LOGICAL_MAX), MSB(Y_LOGICAL_MAX),		// LOGICAL_MAXIMUM (32767)
	0x81, 0x42,											// INPUT (Data,Var,Abs)         
	0xb4,												// POP                          


	// Pressure
	0x05, 0x0d,									//     USAGE_PAGE (Digitizers)      
	0x09, 0x30,									//     USAGE (Tip Pressure)         
	0x26, LSB(PRESSURE_MAX), MSB(PRESSURE_MAX), //     LOGICAL_MAXIMUM (4095)       
	0x55, 0x00,									//     UNIT_EXPONENT (0)
	0x81, 0x02,									//     INPUT (Data,Var,Abs)         

	// X Tilt
	0x09, 0x3d,								//     USAGE (X Tilt)               
	0x16, LSB(TILT_X_MIN), MSB(TILT_X_MIN),	//     LOGICAL_MINIMUM (-9000)      
	0x26, LSB(TILT_X_MAX), MSB(TILT_X_MAX),	//     LOGICAL_MAXIMUM (9000)  
	0x65, 0x14,								//     UNIT (Degrees,EngRotation)        
	0x55, 0x0e,								//     UNIT_EXPONENT (-2)
	0x36, LSB(TILT_X_MIN), MSB(TILT_X_MIN),	//     PHYSICAL_MINIMUM (-9000)         
	0x46, LSB(TILT_X_MAX), MSB(TILT_X_MAX),	//     PHYSICAL_MAXIMUM (9000)      
	0x81, 0x02,								//     INPUT (Data,Var,Abs)        

	// Y Tilt
	0x09, 0x3e,								//     USAGE (Y Tilt)    
	0x16, LSB(TILT_Y_MIN), MSB(TILT_Y_MIN),	//     LOGICAL_MINIMUM (-9000)      
	0x26, LSB(TILT_Y_MAX), MSB(TILT_Y_MAX),	//     LOGICAL_MAXIMUM (9000)  
	0x65, 0x14,								//     UNIT (Degrees,EngRotation)        
	0x55, 0x0e,								//     UNIT_EXPONENT (-2)
	0x36, LSB(TILT_Y_MIN), MSB(TILT_Y_MIN),	//     PHYSICAL_MINIMUM (-9000)         
	0x46, LSB(TILT_Y_MAX), MSB(TILT_Y_MAX),	//     PHYSICAL_MAXIMUM (9000) 
	0x81, 0x02,								//     INPUT (Data,Var,Abs)   

#ifdef HID_AZIMUTH_INPUT
	// Altitude
	0x09, 0x40,													//	USAGE (Altitute - Orientation)
	0x95, 0x01,													//	REPORT_COUNT (1)
	0x75, 0x10,													//	REPORT_SIZE (16)
	0x55, 0x0E,													//	UNIT_EXPONENT (-2)
	0x65, 0x14,													//	UNIT (Degrees)
	0x36, LSB(ALTITUDE_MIN), MSB(ALTITUDE_MIN),					//	PHYSICAL_MINIMUM (-9000)
	0x46, LSB(ALTITUDE_MAX), MSB(ALTITUDE_MAX),					//	PHYSICAL_MAXIMUM (9000)
	0x16, LSB(ALTITUDE_MIN), MSB(ALTITUDE_MIN),					//	LOGICAL_MINIMUM (-9000)
	0x26, LSB(ALTITUDE_MAX), MSB(ALTITUDE_MAX),					//	LOGICAL_MAXIMUM (9000)
	0x81, 0x02,													//	INPUT (Data,Var,Abs)

	// Azimuth
	0x09, 0x3f,													//	USAGE (Azimuth - Orientation)
	0x95, 0x01,													//	REPORT_COUNT (1)
	0x75, 0x10,													//	REPORT_SIZE (16)
	0x55, 0x0E,													//	UNIT_EXPONENT (-2)
	0x65, 0x14,													//	UNIT (Degrees)
	0x35, 0x00,													//	PHYSICAL_MINIMUM (0)
	0x47, LSB(AZIMUTH_MAX), MSB(AZIMUTH_MAX), 0x00, 0x00,		//	PHYSICAL_MAXIMUM (36000)
	0x15, 0x00,													//	LOGICAL_MINIMUM (0)
	0x27, LSB(AZIMUTH_MAX), MSB(AZIMUTH_MAX), 0x00, 0x00,		//	LOGICAL_MAXIMUM (36000)
	0x81, 0x02,													//	INPUT (Data,Var,Abs)
#endif

	// Twist
	0x09, 0x41,													//     USAGE (Twist)  
	0x15, 0x00,													//     LOGICAL_MINIMUM (0)      
	0x27, LSB(TWIST_MAX), MSB(TWIST_MAX), 0x00, 0x00,			//     LOGICAL_MAXIMUM (36000)  
	0x65, 0x14,													//     UNIT (Degrees,EngRotation)
	0x55, 0x0e,													//     UNIT_EXPONENT (0)
	0x35, 0x00,													//     PHYSICAL_MINIMUM (0)         
	0x47, LSB(TWIST_MAX), MSB(TWIST_MAX), 0x00, 0x00,			//    PHYSICAL_MAXIMUM (36000)      
	0x81, 0x02,													//     INPUT (Data,Var,Abs)  

#ifdef HID_PEN_SCAN_TIME
	// Scan Time
	0x55, 0x0C,														//	 UNIT_EXPONENT (-4)
	0x66, 0x01, 0x10,												//	 UNIT (Seconds)
	0x47, LSB(SCAN_TIME_MAX), MSB(SCAN_TIME_MAX), 0x00, 0x00,		//	 PHYSICAL_MAXIMUM (65535)
	0x27, LSB(SCAN_TIME_MAX), MSB(SCAN_TIME_MAX), 0x00, 0x00,       //   LOGICAL_MAXIMUM (65535)
	0x75, 0x10,														//   REPORT_SIZE (16)
	0x95, 0x01,														//   REPORT_COUNT (1)
	0x09, 0x56,														//   USAGE (Scan Time)
	0x81, 0x02,														//   INPUT (Data,Var,Abs)
#endif



#ifdef ADD_PEN_EXTRA

	// Serial Code
	0x05, 0x0D,
	0x09, HID_PEN__SERIAL_CODE,
	0x15, 0x00,                         //     LOGICAL_MINIMUM (0)          
	0x25, 0x01,                         //     LOGICAL_MAXIMUM (1)          
	0x75, 0x08,                         //     REPORT_SIZE (8)              
	0x95, 0x08,                         //     REPORT_COUNT (8)   
	0x81, 0x02,

	// Battery Level
	0x05, 0x0D,
	0x09, HID_PEN__BATTERY_LEVEL,
	0x75, 0x08,                         //     REPORT_SIZE (8)              
	0x95, 0x01,                         //     REPORT_COUNT (1)   
	0x81, 0x02,

#endif


	0xc0, //   END_COLLECTION                
	0xc0,  // END_COLLECTION 
};
#endif


