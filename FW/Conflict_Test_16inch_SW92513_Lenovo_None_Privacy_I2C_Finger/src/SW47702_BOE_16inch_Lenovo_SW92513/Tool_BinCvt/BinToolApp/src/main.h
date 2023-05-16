/******************************************************************************************************
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


#define BINTOOL_CHIP_SW47701							(1)

/*
 * Chip Select
 */
#define BINTOOL_CHIP									(BINTOOL_CHIP_SW47701)

/*
 * SW47701 Define
 */
#define SW47701_BINTOOLAPP_MAJOR_VERSION					(0x00)
#define SW47701_BINTOOLAPP_MINOR_VERSION					(0x03)

#define SW47701_FLASH_10KBOOT_SECTION_KBYTE_SIZE			(10)
#define SW47701_FLASH_12KBOOT_SECTION_KBYTE_SIZE			(12)
#define SW47701_FLASH_FULLMEM_APP_SECTION_KBYTE_SIZE		(116)
#define SW47701_FLASH_FULLMEM_SIMPLEBOOT_SECTION_KBYTE_SIZE	(3)
#define SW47701_FLASH_FULL_KBYTE_SIZE						(SW47701_FLASH_12KBOOT_SECTION_KBYTE_SIZE + SW47701_FLASH_FULLMEM_APP_SECTION_KBYTE_SIZE)


#define SW47701_10KBOOT_BYTE_SIZE							(SW47701_FLASH_10KBOOT_SECTION_KBYTE_SIZE * 1024)
#define SW47701_12KBOOT_BYTE_SIZE							(SW47701_FLASH_12KBOOT_SECTION_KBYTE_SIZE * 1024)
//#define SW47701_APP_BYTE_SIZE								(SW47701_FLASH_APP_SECTION_KBYTE_SIZE * 1024)
//#define SW47701_CONFIG_BYTE_SIZE							(SW47701_FLASH_CONFIG_SECTION_KBYTE_SIZE * 1024)
#define SW47701_FULLMEM_APP_BYTE_SIZE						(SW47701_FLASH_FULLMEM_APP_SECTION_KBYTE_SIZE * 1024)
#define SW47701_FULLMEM_SIMPLEBOOT_BYTE_SIZE				(SW47701_FLASH_FULLMEM_SIMPLEBOOT_SECTION_KBYTE_SIZE * 1024)
//#define SW47701_FULLMEM_CONFIG_BYTE_SIZE					(SW47701_FLASH_FULLMEM_CONFIG_SECTION_KBYTE_SIZE * 1024)
#define SW47701_TOTAL_BYTE_SIZE								(SW47701_FLASH_FULL_KBYTE_SIZE * 1024)



#define BIN_TOOL_MAJOR_VERSION								(SW47701_BINTOOLAPP_MAJOR_VERSION)
#define BIN_TOOL_MINOR_VERSION								(SW47701_BINTOOLAPP_MINOR_VERSION)
#define BOOT10K_BINARY_FULL_SIZE							(SW47701_10KBOOT_BYTE_SIZE)
#define BOOT12K_BINARY_FULL_SIZE							(SW47701_12KBOOT_BYTE_SIZE)
//#define APP_BINARY_FULL_SIZE								(SW47701_APP_BYTE_SIZE)
//#define CONFIG_BINARY_FULL_SIZE							(SW47701_CONFIG_BYTE_SIZE)
#define FULLMEM_APP_BINARY_FULL_SIZE						(SW47701_FULLMEM_APP_BYTE_SIZE)
//#define FULLMEM_CONFIG_BINARY_FULL_SIZE					(SW47701_FULLMEM_CONFIG_BYTE_SIZE)
#define TOTAL_BINARY_FULL_SIZE								(SW47701_TOTAL_BYTE_SIZE)

/*
 * Common Define!!
 */
#define CRC_CODE_BYTE_SIZE								(4)
#define CTYPE_ONE_BYTE_NUM								(6) // "0xFF, " 6Byte
#define CTYPE_ONE_LINE_BYTE_NUM							(12) // 한라인을 12개의 Data로 구성
#define CTYPE_LINE_FEED_BYTE_NUM						(1) // "\n" 1Byte
#define CTYPE_TAB_BYTE_NUM								(1) // "\n" 1Byte

//#define CODE_SRAM_APP_RESERV_BYTE_SIZE					(512)
#define CONFIG_LENGTH_SIZE								(4)


typedef enum
{
	/* Bootloader : Created Boot.img */
	BINTOOL_BINARY_TYPE_BOOT_10K_IMG,
	BINTOOL_BINARY_TYPE_BOOT_12K_IMG,

	/* Application : Created App.img */
	BINTOOL_BINARY_TYPE_APP_FULLMEM_IMG,					/* Application */
	BINTOOL_BINARY_TYPE_APP_CONFIG_IMG,						/* Application + Configuration */

	/* Application : Created App.img */
	BINTOOL_BINARY_TYPE_APP_SIMPLEBOOT_FULLMEM_IMG,			/* Application + SimpleBoot */
	BINTOOL_BINARY_TYPE_APP_SIMPLEBOOT_CONFIG_IMG,			/* Application + SimpleBoot + Configuration */

	/* Bootloader + Application : Created Total.img & App.img */
	BINTOOL_BINARY_TYPE_TOTAL_APP_FULLMEM_IMG,				/* BOOT + Application */
	BINTOOL_BINARY_TYPE_TOTAL_APP_CONFIG_IMG,				/* BOOT + Application + Configuration */

	/* Bootloader + Application : Created Total.img & App.img */
	BINTOOL_BINARY_TYPE_TOTAL_APP_SIMPLEBOOT_FULLMEM_IMG,	/* BOOT + Application + SimpleBoot */
	BINTOOL_BINARY_TYPE_TOTAL_APP_SIMPLEBOOT_CONFIG_IMG,	/* BOOT + Application + SimpleBoot + Configuration */

	BINTOOL_BINARY_TYPE_ERROR
} eBinaryTypeInfo_e;

#define MAJORVERSION(v)		((uint8_t)(((v)>>8) & 0xFF))
#define MINORVERSION(v)		((uint8_t)((v) & 0xFF))

