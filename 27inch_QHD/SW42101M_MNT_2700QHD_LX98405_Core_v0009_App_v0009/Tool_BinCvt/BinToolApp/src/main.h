/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : main.h
 * version : 0.1
 * created on : 16. 5. 2017
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

/*
 * Chip List
 */
#define USE_GDMA_CRC_BUG_WORKROUND						(1)


#define BINTOOL_CHIP_SW42102							(1)

/*
 * Chip Select
 */
#define BINTOOL_CHIP									(BINTOOL_CHIP_SW42102)

/*
 * SW42102 Define
 */
#define SW42102_BINTOOLAPP_MAJOR_VERSION					(0x00)
#define SW42102_BINTOOLAPP_MINOR_VERSION					(0x01)

#define SW42102_FLASH_BOOT_SECTION_KBYTE_SIZE				(12)
#define SW42102_FLASH_APP_SECTION_KBYTE_SIZE				(68)
#define SW42102_FLASH_CONFIG_SECTION_KBYTE_SIZE				(40)
#define SW42102_FLASH_FULLMEM_APP_SECTION_KBYTE_SIZE		(80)
#define SW42102_FLASH_FULLMEM_CONFIG_SECTION_KBYTE_SIZE		(28)
#define SW42102_FLASH_FULL_KBYTE_SIZE						(SW42102_FLASH_BOOT_SECTION_KBYTE_SIZE + SW42102_FLASH_APP_SECTION_KBYTE_SIZE + SW42102_FLASH_CONFIG_SECTION_KBYTE_SIZE)

#define SW42102_BOOT_BYTE_SIZE								(SW42102_FLASH_BOOT_SECTION_KBYTE_SIZE * 1024)
#define SW42102_APP_BYTE_SIZE								(SW42102_FLASH_APP_SECTION_KBYTE_SIZE * 1024)
#define SW42102_CONFIG_BYTE_SIZE							(SW42102_FLASH_CONFIG_SECTION_KBYTE_SIZE * 1024)
#define SW42102_FULLMEM_APP_BYTE_SIZE						(SW42102_FLASH_FULLMEM_APP_SECTION_KBYTE_SIZE * 1024)
#define SW42102_FULLMEM_CONFIG_BYTE_SIZE					(SW42102_FLASH_FULLMEM_CONFIG_SECTION_KBYTE_SIZE * 1024)
#define SW42102_TOTAL_BYTE_SIZE								(SW42102_FLASH_FULL_KBYTE_SIZE * 1024)

#define SW42102_BOOT_INFO_BYTE_SIZE

/*
 * OTHER
 */
//#define OTHER_BINTOOLAPP_MAJOR_VERSION
//#define OTHER_BINTOOLAPP_MINOR_VERSION
//
//#define OTHER_FLASH_BOOT_SECTION_KBYTE_SIZE
//#define OTHER_FLASH_APP_SECTION_KBYTE_SIZE
//#define OTHER_FLASH_CONFIG_SECTION_KBYTE_SIZE
//#define OTHER_FLASH_FULLMEM_APP_SECTION_KBYTE_SIZE
//#define OTHER_FLASH_FULLMEM_CONFIG_SECTION_KBYTE_SIZE
//#define OTHER_FLASH_FULL_KBYTE_SIZE					(OTHER_FLASH_BOOT_SECTION_KBYTE_SIZE + OTHER_FLASH_APP_SECTION_KBYTE_SIZE + OTHER_FLASH_CONFIG_SECTION_KBYTE_SIZE)
//
//#define OTHER_BOOT_BYTE_SIZE							(OTHER_FLASH_BOOT_SECTION_KBYTE_SIZE * 1024)
//#define OTHER_APP_BYTE_SIZE							(OTHER_FLASH_APP_SECTION_KBYTE_SIZE * 1024)
//#define OTHER_CONFIG_BYTE_SIZE						(OTHER_FLASH_CONFIG_SECTION_KBYTE_SIZE * 1024)
//#define OTHER_FULLMEM_APP_BYTE_SIZE					(OTHER_FLASH_FULLMEM_APP_SECTION_KBYTE_SIZE * 1024)
//#define OTHER_FULLMEM_CONFIG_BYTE_SIZE				(OTHER_FLASH_FULLMEM_CONFIG_SECTION_KBYTE_SIZE * 1024)
//#define OTHER_TOTAL_BYTE_SIZE							(OTHER_FLASH_FULL_KBYTE_SIZE * 1024)



#if (BINTOOL_CHIP == BINTOOL_CHIP_SW42102)
#define BIN_TOOL_MAJOR_VERSION							(SW42102_BINTOOLAPP_MAJOR_VERSION)
#define BIN_TOOL_MINOR_VERSION							(SW42102_BINTOOLAPP_MINOR_VERSION)
#define BOOT_BINARY_FULL_SIZE							(SW42102_BOOT_BYTE_SIZE)
#define APP_BINARY_FULL_SIZE							(SW42102_APP_BYTE_SIZE)
#define CONFIG_BINARY_FULL_SIZE							(SW42102_CONFIG_BYTE_SIZE)
#define FULLMEM_APP_BINARY_FULL_SIZE					(SW42102_FULLMEM_APP_BYTE_SIZE)
#define FULLMEM_CONFIG_BINARY_FULL_SIZE					(SW42102_FULLMEM_CONFIG_BYTE_SIZE)
#define TOTAL_BINARY_FULL_SIZE							(SW42102_TOTAL_BYTE_SIZE)
#else /* (BINTOOL_CHIP == BINTOOL_CHIP_SW42102) */
#define BIN_TOOL_MAJOR_VERSION							(OTHER_BINTOOLAPP_MAJOR_VERSION)
#define BIN_TOOL_MINOR_VERSION							(OTHER_BINTOOLAPP_MINOR_VERSION)
#define BOOT_BINARY_FULL_SIZE							(OTHER_BOOT_BYTE_SIZE)
#define APP_BINARY_FULL_SIZE							(OTHER_APP_BYTE_SIZE)
#define CONFIG_BINARY_FULL_SIZE							(OTHER_CONFIG_BYTE_SIZE)
#define FULLMEM_APP_BINARY_FULL_SIZE					(OTHER_FULLMEM_APP_BYTE_SIZE)
#define FULLMEM_CONFIG_BINARY_FULL_SIZE					(OTHER_FULLMEM_CONFIG_BYTE_SIZE)
#define TOTAL_BINARY_FULL_SIZE							(OTHER_TOTAL_BYTE_SIZE)
#endif /* (BINTOOL_CHIP == BINTOOL_CHIP_SW42102) */

/*
 * Common Define!!
 */
#define CRC_CODE_BYTE_SIZE								(4)
#define CTYPE_ONE_BYTE_NUM								(6) // "0xFF, " 6Byte
#define CTYPE_ONE_LINE_BYTE_NUM							(12) // �Ѷ����� 12���� Data�� ����
#define CTYPE_LINE_FEED_BYTE_NUM						(1) // "\n" 1Byte
#define CTYPE_TAB_BYTE_NUM								(1) // "\n" 1Byte

#define CODE_SRAM_APP_RESERV_BYTE_SIZE					(512)
#define CONFIG_LENGTH_SIZE								(4)


typedef enum
{
	/* Bootloader : Created Boot.img */
	BINTOOL_BINARY_TYPE_BOOT_IMG,

	/* Application : Created App.img */
	BINTOOL_BINARY_TYPE_APP_IMG,			/*  */
	BINTOOL_BINARY_TYPE_FULLMEM_APP_IMG,		/* application used full memory, not include configuration */

	/* Bootloader + Application : Created Total.img & App.img */
	BINTOOL_BINARY_TYPE_TOTAL_IMG,			/*  */
	BINTOOL_BINARY_TYPE_FULLMEM_TOTAL_IMG,		/* application used full memory, not include configuration */

	BINTOOL_BINARY_TYPE_ERROR
} eBinaryTypeInfo_e;

#define MAJORVERSION(v)		((uint8_t)(((v)>>8) & 0xFF))
#define MINORVERSION(v)		((uint8_t)((v) & 0xFF))
