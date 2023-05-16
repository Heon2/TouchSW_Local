/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : flitf_types.h
 * created on : 04. 28. 2020
 * Author : mhjang
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


#ifndef _FLITF_TYPES_H_
#define _FLITF_TYPES_H_


typedef struct // 36 Byte
{
	uint32_t ulMagicCode;
	uint32_t Dummy1[4];

	struct {
		uint32_t R_OSC12M_VTRIM		:6;
		uint32_t R_OSC12M_ITRIM		:3;
		uint32_t RESERVED			:23;
	} __PACKED tTrim1;

	struct {
		uint32_t R_LDO_TRIM			:5;
		uint32_t RESERVED			:27;
	} __PACKED tTrim2;

	struct {
		uint32_t R_MAIN_VBGR_CTL	:3;
		uint32_t R_MAIN_IREF_TRIM	:5;
		uint32_t R_MAIN_VREF_TRIM	:4;
		uint32_t RESERVED			:20;
	} __PACKED tTrim3;

	uint32_t Dummy2[2];
	uint32_t CheckSum;

} __PACKED tFlashPTTrimCodeInfo_t;

typedef struct // 36 Byte
{
	uint32_t CHIP_ID_ECC;
	uint32_t Dummy[3];
	uint32_t CheckSum;

} __PACKED tFlashFTTrimCodeInfo_t;

typedef struct // 16 Byte
{
	struct {
		uint32_t BOOT_VID				:16;
		uint32_t BOOT_PID				:16;
	} __PACKED tDeviceId;

	struct {
		uint32_t BOOT_I2C_SLV_ADDR		:8;
		uint32_t APP_KBYTE_SIZE			:8;
		uint32_t reserved				:16;
	} __PACKED tDeviceInfo;

	uint32_t BOOT_INFO_WRITE_EN_CODE;
	uint32_t CheckSum;

} __PACKED tFlashBootInterfaceInfo_t;

typedef struct // 16 Byte
{
    uint16_t usCounterValue;
    uint8_t ucPCTimeStamp[12];
    uint8_t ucComputerName[10];
    uint32_t ulCRC;

} __PACKED tFlashPTInspectionInfo_t;

typedef struct
{
	uint32_t ulFlashUpdateType;
	tFlashBootInterfaceInfo_t tFlashBootInterfaceInfo;
	tFlashPTInspectionInfo_t tFlashPTInspectionInfo;
	tFlashPTTrimCodeInfo_t tFlashPTTrimCodeInfo;
	tFlashFTTrimCodeInfo_t tFlashFTTrimCodeInfo;
} __PACKED tSimpleBootFlashCtrlInfo_t;


#define WORD_BYTE_SIZE							(4)
#define CODE_SRAM_START_ADDR					(0x20000000UL)
#define FLASH_BOOTLOADER_START_ADDR				(0x0)
#define FLASH_APP_START_ADDR					(0x3000)
#define FLASH_SIMPLE_BOOT_START_ADDR			(0x1F400)

#define SRAM_SIMPLE_BOOT_CTRL_INFO_ADDR			(0x20010000UL)
#define SRAM_SIMPLE_BOOT_CTRL_INFO_ADDR_2		(0x20010800UL)

#define CODE_SRAM_KBYTE_SIZE					(12)	//	12K: After revision
#define CODE_SRAM_BYTE_SIZE						(CODE_SRAM_KBYTE_SIZE * 1024)
#define CODE_SRAM_WORD_SIZE						(CODE_SRAM_BYTE_SIZE / WORD_BYTE_SIZE)

#define FLASH_BOOTLOADER_KBYTE_SIZE				(12)	//	12K: After revision
#define FLASH_BOOTLOADER_BYTE_SIZE				(FLASH_BOOTLOADER_KBYTE_SIZE * 1024)
#define FLASH_BOOTLOADER_WORD_SIZE				(FLASH_BOOTLOADER_BYTE_SIZE / WORD_BYTE_SIZE)


#define FLASH_SIMPLE_BOOT_KBYTE_SIZE			(3)	//	12K: After revision
#define FLASH_SIMPLE_BOOT_BYTE_SIZE				(FLASH_SIMPLE_BOOT_KBYTE_SIZE * 1024)
#define FLASH_SIMPLE_BOOT_WORD_SIZE				(FLASH_SIMPLE_BOOT_BYTE_SIZE / WORD_BYTE_SIZE)

#define FLASH_APPLICATION_KBYTE_SIZE			(116)


#define EFLASH_ANALOG_TRIM_1_PT_ADDR			(0x00020000)
#define EFLASH_ANALOG_TRIM_2_PT_ADDR			(0x00020200)
#define EFLASH_PT_MAGIC_CODE					(0x00477010) // SW47701 & SW47702 are same code value.
#define EFLASH_FT_CHIP_ID_CODE					(0x00477020) // SW47701 is ID Code : 0x00477010, SW47702 is ID Code : 0x00477020
#define EFLASH_FT_SECTION_BYTE_OFFSET			(0x80)
#define EFLASH_ANALOG_TRIM_PT_INFO_WORD_SIZE	(11)
#define EFLASH_ANALOG_TRIM_FT_INFO_WORD_SIZE	(5)
#define EFLASH_TRIMCODE_SECTION_NUM				(2)


#define EFLASH_BOOT_INFO_WRITE_EN_CODE			(0x4A4D4801)
#define EFLASH_VID_PID_I2CSLV_1_ADDR			(0x00020400)
#define EFLASH_VID_PID_I2CSLV_2_ADDR			(0x00020480)
#define EFLASH_VID_PID_I2CSLV_BYTE_SIZE			(16)
#define EFLASH_VID_PID_I2CSLV_WORD_SIZE			(EFLASH_VID_PID_I2CSLV_BYTE_SIZE / 4)
#define EFLASH_BOOT_INFO_SECTION_NUM			(2)


#define EFLASH_PTINSPECTION_INFO_ADDR			(0x00020500)
#define EFLASH_PTINSPECTION_INFO_BYTE_SIZE		(28)
#define EFLASH_PTINSPECTION_INFO_WORD_SIZE		(EFLASH_PTINSPECTION_INFO_BYTE_SIZE / 4)
#define EFLASH_PTINSPECTION_INFO_SECTION_NUM	(1)

#define DISABLE_WRITE_PROTECTION	(0x00303270)

#define SIMPLE_BOOT_FLASH_UPDATE_HOST_INTERFACE		(0xF00)
#define SIMPLE_BOOT_FLASH_UPDATE_PT_INFO_WRITE		(0xF01)
#define SIMPLE_BOOT_FLASH_UPDATE_TRIM_CODE_WRITE	(0xFA7)

#endif /* _FLITF_TYPES_H_ */


