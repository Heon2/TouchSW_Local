/*
 * MemoryInfo.h
 *
 *  Created on: 2018. 11. 27.
 *      Author: leebj
 */

#ifndef MEMORYINFO_H_
#define MEMORYINFO_H_

/* ============================================= */
/* ===========    Back-Up TypeDef    =========== */
/* ============================================= */
typedef struct {
	uint32_t CRC_1;
	uint32_t CRC_2;

} BACKUP_CRC_TypeDef;

typedef struct {
	union {
		uint32_t I2C_BOOT_INFO;

		struct {
			uint32_t DUMMY :8;
			uint32_t I2C_SADDR :8;
			uint32_t BOOT_VERSION :16;
		} I2C_BOOT_INFO_b;
	};

	union {
		uint32_t VID_PID_INFO;

		struct {
			uint32_t VID_INFO :16;
			uint32_t PID_INFO :16;
		} VID_PID_INFO_b;
	};

} BACKUP_INFO_TypeDef;

/* ============================================= */
/* ===========    F/W & BOOT Size    =========== */
/* ============================================= */
#define FLASH_SIZE					( 128 * 1024 )

#define FW_SECTOR_SIZE				( 112 * 1024 )
#define ECC_SECTOR_SIZE				(   6 * 1024 )
#define BOOT_SECTOR_SIZE			(  10 * 1024 )

#define FW_CODE_MAX_SIZE			( 108 * 1024 )
#define ECC_CODE_MAX_SIZE			(   5 * 1024 )
#define BOOT_CODE_MAX_SIZE			(   9 * 1024 )

#define ECC_CODE_SIZE				(		   3 )	//   3byte
#define ECC_BLOCK_SIZE				( 		 256 )	// 256byte
#define ECC_SPARE_SIZE				( MAX_FW_SIZE / ECC_BLOCK_SIZE * ECC_CODE_SIZE )

/* ============================================ */
/* ===========    ECC Memory Map    =========== */
/* ============================================ */
#define	BASEADDR_ECC				0x00000000UL
#define	BASEADDR_ECC_CRC			0x00001400UL
#define	BASEADDR_FW					0x00004000UL
#define	BASEADDR_FW_CRC				0x0001FC00UL
#define	BASEADDR_FW_ECC_1			0x0001F000UL
#define	BASEADDR_FW_ECC_2			0x0001F600UL
#define BASEADDR_BOOT				0x00001800UL
#define BASEADDR_BOOT_CRC			0x00003F80UL
#define BASEADDR_BOOT_ECC_1			0x00003C00UL
#define BASEADDR_BOOT_ECC_2			0x00003D00UL
#define BASEADDR_BOOT_INFO_1		0x00003E00UL
#define BASEADDR_BOOT_INFO_2		0x00003E80UL
#define BASEADDR_BOOT_INFO_3		0x00003F00UL

#define BASEADDR_FW_ERROR			0x000017F4UL
#define BASEADDR_INFO_ERROR			0x000017F0UL

/* ================================================================================== */
/* ==============================    ECC Declaration    ============================= */
/* ================================================================================== */
uint8_t FLASH_BUFFER[FLASH_SIZE] = { 0, };

#define BACKUP_FW_CRC				((BACKUP_CRC_TypeDef	*) &FLASH_BUFFER[BASEADDR_FW_CRC]		)
#define BACKUP_ECC_CRC				((BACKUP_CRC_TypeDef	*) &FLASH_BUFFER[BASEADDR_ECC_CRC]		)
#define BACKUP_BOOT_CRC        		((BACKUP_CRC_TypeDef	*) &FLASH_BUFFER[BASEADDR_BOOT_CRC]		)
#define BACKUP_BOOT_INFO_1          ((BACKUP_INFO_TypeDef	*) &FLASH_BUFFER[BASEADDR_BOOT_INFO_1]	)
#define BACKUP_BOOT_INFO_2         	((BACKUP_INFO_TypeDef	*) &FLASH_BUFFER[BASEADDR_BOOT_INFO_2]	)
#define BACKUP_BOOT_INFO_3          ((BACKUP_INFO_TypeDef	*) &FLASH_BUFFER[BASEADDR_BOOT_INFO_3]	)

#endif /* MEMORYINFO_H_ */
