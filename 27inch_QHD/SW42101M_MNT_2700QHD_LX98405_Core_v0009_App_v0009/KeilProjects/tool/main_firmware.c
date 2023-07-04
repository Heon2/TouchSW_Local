
/* *
* ECC BOOTLOADER Build TOOL
* by lee.bj
* 27/11/2018
* */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "../MemoryInfo.h"

#define ON					1
#define OFF					0

#define ECC         		1
#define ECC_BOOT     		2
#define ECC_FIRMWARE		3

#define VID					0x29BD
#define PID 				0x5357
#define BOOT_VER			0x0302
#define I2C_ADDRESS 		0x0034

#define BUILD_OPTION		ECC_FIRMWARE

#if	  	( BUILD_OPTION == ECC )

#define CRC_BACKUP_MODE		ON
#define ECC_BACKUP_MODE		OFF
#define INFO_BACKUP_MODE	OFF

#define BINARY_ADDR_START	BASEADDR_ECC
#define BINARY_ADDR_END		BASEADDR_BOOT
#define BINARY_SIZE			ECC_SECTOR_SIZE
#define SECTOR_ADDR_START	BASEADDR_ECC
#define SECTOR_ADDR_END		BASEADDR_BOOT
#define SECTOR_SIZE			ECC_SECTOR_SIZE
#define SECTOR_CODE_SIZE	ECC_CODE_MAX_SIZE
#define BACKUP_CRC			BACKUP_ECC_CRC

#elif	( BUILD_OPTION == ECC_BOOT )

#define CRC_BACKUP_MODE		ON
#define ECC_BACKUP_MODE		ON
#define INFO_BACKUP_MODE	ON

#define BINARY_ADDR_START	BASEADDR_ECC
#define BINARY_ADDR_END		BASEADDR_FW
#define BINARY_SIZE			ECC_SECTOR_SIZE + BOOT_SECTOR_SIZE
#define SECTOR_ADDR_START	BASEADDR_BOOT
#define SECTOR_ADDR_END		BASEADDR_FW
#define SECTOR_ADDR_ECC_1	BASEADDR_BOOT_ECC_1
#define SECTOR_ADDR_ECC_2	BASEADDR_BOOT_ECC_2
#define SECTOR_SIZE			BOOT_SECTOR_SIZE
#define SECTOR_CODE_SIZE	BOOT_CODE_MAX_SIZE
#define BACKUP_CRC			BACKUP_BOOT_CRC
#define BACKUP_INFO_1		BACKUP_BOOT_INFO_1
#define BACKUP_INFO_2		BACKUP_BOOT_INFO_2
#define BACKUP_INFO_3		BACKUP_BOOT_INFO_3

#elif	( BUILD_OPTION == ECC_FIRMWARE )

#define CRC_BACKUP_MODE		ON
#define ECC_BACKUP_MODE		ON
#define INFO_BACKUP_MODE	OFF

#define BINARY_ADDR_START	BASEADDR_FW
#define BINARY_ADDR_END		FLASH_SIZE
#define BINARY_SIZE			FW_SECTOR_SIZE
#define SECTOR_ADDR_START	BASEADDR_FW
#define SECTOR_ADDR_END		FLASH_SIZE
#define SECTOR_ADDR_ECC_1	BASEADDR_FW_ECC_1
#define SECTOR_ADDR_ECC_2	BASEADDR_FW_ECC_2
#define SECTOR_SIZE			FW_SECTOR_SIZE
#define SECTOR_CODE_SIZE	FW_CODE_MAX_SIZE
#define BACKUP_CRC			BACKUP_FW_CRC

#endif


#if ECC_BACKUP_MODE
/*
 * Pre-calculated 256-way 1 byte column parity
 */
static const uint8_t flash_ecc_precalc_table[] = {
    0x00, 0x55, 0x56, 0x03, 0x59, 0x0c, 0x0f, 0x5a, 0x5a, 0x0f, 0x0c, 0x59, 0x03, 0x56, 0x55, 0x00,
    0x65, 0x30, 0x33, 0x66, 0x3c, 0x69, 0x6a, 0x3f, 0x3f, 0x6a, 0x69, 0x3c, 0x66, 0x33, 0x30, 0x65,
    0x66, 0x33, 0x30, 0x65, 0x3f, 0x6a, 0x69, 0x3c, 0x3c, 0x69, 0x6a, 0x3f, 0x65, 0x30, 0x33, 0x66,
    0x03, 0x56, 0x55, 0x00, 0x5a, 0x0f, 0x0c, 0x59, 0x59, 0x0c, 0x0f, 0x5a, 0x00, 0x55, 0x56, 0x03,
    0x69, 0x3c, 0x3f, 0x6a, 0x30, 0x65, 0x66, 0x33, 0x33, 0x66, 0x65, 0x30, 0x6a, 0x3f, 0x3c, 0x69,
    0x0c, 0x59, 0x5a, 0x0f, 0x55, 0x00, 0x03, 0x56, 0x56, 0x03, 0x00, 0x55, 0x0f, 0x5a, 0x59, 0x0c,
    0x0f, 0x5a, 0x59, 0x0c, 0x56, 0x03, 0x00, 0x55, 0x55, 0x00, 0x03, 0x56, 0x0c, 0x59, 0x5a, 0x0f,
    0x6a, 0x3f, 0x3c, 0x69, 0x33, 0x66, 0x65, 0x30, 0x30, 0x65, 0x66, 0x33, 0x69, 0x3c, 0x3f, 0x6a,
    0x6a, 0x3f, 0x3c, 0x69, 0x33, 0x66, 0x65, 0x30, 0x30, 0x65, 0x66, 0x33, 0x69, 0x3c, 0x3f, 0x6a,
    0x0f, 0x5a, 0x59, 0x0c, 0x56, 0x03, 0x00, 0x55, 0x55, 0x00, 0x03, 0x56, 0x0c, 0x59, 0x5a, 0x0f,
    0x0c, 0x59, 0x5a, 0x0f, 0x55, 0x00, 0x03, 0x56, 0x56, 0x03, 0x00, 0x55, 0x0f, 0x5a, 0x59, 0x0c,
    0x69, 0x3c, 0x3f, 0x6a, 0x30, 0x65, 0x66, 0x33, 0x33, 0x66, 0x65, 0x30, 0x6a, 0x3f, 0x3c, 0x69,
    0x03, 0x56, 0x55, 0x00, 0x5a, 0x0f, 0x0c, 0x59, 0x59, 0x0c, 0x0f, 0x5a, 0x00, 0x55, 0x56, 0x03,
    0x66, 0x33, 0x30, 0x65, 0x3f, 0x6a, 0x69, 0x3c, 0x3c, 0x69, 0x6a, 0x3f, 0x65, 0x30, 0x33, 0x66,
    0x65, 0x30, 0x33, 0x66, 0x3c, 0x69, 0x6a, 0x3f, 0x3f, 0x6a, 0x69, 0x3c, 0x66, 0x33, 0x30, 0x65,
    0x00, 0x55, 0x56, 0x03, 0x59, 0x0c, 0x0f, 0x5a, 0x5a, 0x0f, 0x0c, 0x59, 0x03, 0x56, 0x55, 0x00
};

/*
 * calc_block_ecc - Calculate 1-byte ECC
 */
int calc_1byte_ecc(uint8_t dat)
{
    uint8_t idx, colParity;

    idx = flash_ecc_precalc_table[dat];
    colParity = (idx & 0x3f);

    return colParity;
}

uint8_t calc_2byte_ecc(uint8_t first, uint8_t second)
{
    int i;
    uint8_t idx1,idx2, colparity = 0, lineparity = 0;
    uint8_t parity = 0;
    // calc col parity
    idx1 = flash_ecc_precalc_table[first];
    idx2 = flash_ecc_precalc_table[second];
    colparity = (idx1 & 0x3f) ^ (idx2 & 0x3f);

    idx1 = 0;
    idx2 = 0;
    // calc line parity
    for(i = 0; i < 8; i++)
    {
        idx1 ^= (first >> i) & 0x01;
        idx2 ^= (second >> i) & 0x01;
    }

    lineparity = ( idx1 << 1) | (idx2);

    parity = (colparity & 0x3f) | ((lineparity & 0x03) << 6);

    return parity;
}
/*
 * calc_block_ecc - Calculate 3-byte ECC for 256-byte block
 */
int calc_block_ecc(uint8_t *dat, uint8_t *ecc_code)
{
    uint8_t idx, reg1, reg2, reg3, tmp1, tmp2;

    int i;

    /* Initialize variables */
    reg1 = reg2 = reg3 = 0;

    /* Build up column parity */
    for (i = 0; i < 256; i++) {
        /* Get CP0 - CP5 from table */
        idx = flash_ecc_precalc_table[*dat++];
        reg1 ^= (idx & 0x3f);

        /* All bit XOR = 1 ? */
        if (idx & 0x40) {
            reg3 ^= (uint8_t) i;
            reg2 ^= ~((uint8_t) i);
        }
    }

    /* Create non-inverted ECC code from line parity */
    tmp1  = (reg3 & 0x80) >> 0; /* B7 -> B7 */
    tmp1 |= (reg2 & 0x80) >> 1; /* B7 -> B6 */
    tmp1 |= (reg3 & 0x40) >> 1; /* B6 -> B5 */
    tmp1 |= (reg2 & 0x40) >> 2; /* B6 -> B4 */
    tmp1 |= (reg3 & 0x20) >> 2; /* B5 -> B3 */
    tmp1 |= (reg2 & 0x20) >> 3; /* B5 -> B2 */
    tmp1 |= (reg3 & 0x10) >> 3; /* B4 -> B1 */
    tmp1 |= (reg2 & 0x10) >> 4; /* B4 -> B0 */

    tmp2  = (reg3 & 0x08) << 4; /* B3 -> B7 */
    tmp2 |= (reg2 & 0x08) << 3; /* B3 -> B6 */
    tmp2 |= (reg3 & 0x04) << 3; /* B2 -> B5 */
    tmp2 |= (reg2 & 0x04) << 2; /* B2 -> B4 */
    tmp2 |= (reg3 & 0x02) << 2; /* B1 -> B3 */
    tmp2 |= (reg2 & 0x02) << 1; /* B1 -> B2 */
    tmp2 |= (reg3 & 0x01) << 1; /* B0 -> B1 */
    tmp2 |= (reg2 & 0x01) << 0; /* B7 -> B0 */

    /* Calculate final ECC code */
    ecc_code[0] = ~tmp1;
    ecc_code[1] = ~tmp2;
    ecc_code[2] = ((~reg1) << 2) | 0x03;

#ifdef ECC_DEBUG
    printf("ECC CODE0 : 0x%x, ECC CODE1 : 0x%x, ECC CODE2 : 0x%x\n",ecc_code[0],ecc_code[1],ecc_code[2]);
#endif

    return 0;
}

uint32_t save_ecc_code(unsigned char *pFullBuf, uint32_t binSize)
{

	uint8_t	 ecc_code[ECC_CODE_SIZE] = {0,};
	uint8_t	 read_bin_block[ECC_BLOCK_SIZE] = {0,};
	uint16_t blockNum = ( binSize / ECC_BLOCK_SIZE);

	uint32_t i = 0;
	uint32_t ret = 0;

	printf("==================================\n");
	printf("ECC Block Number : %d\n",blockNum);

	for(i = 0; i < blockNum; i++)
	{

#ifdef ECC_DEBUG
		printf("Block Number : %d\n",i);
#endif

		memcpy(read_bin_block, (unsigned char *)&pFullBuf[SECTOR_ADDR_START + ( i * ECC_BLOCK_SIZE )], ECC_BLOCK_SIZE);

		calc_block_ecc(read_bin_block, ecc_code);

		memcpy((unsigned char *)&pFullBuf[SECTOR_ADDR_ECC_1 + ( i * ECC_CODE_SIZE )], ecc_code, 3);
		memcpy((unsigned char *)&pFullBuf[SECTOR_ADDR_ECC_2 + ( i * ECC_CODE_SIZE )], ecc_code, 3);

		memset(read_bin_block, 0, ECC_BLOCK_SIZE);
	}

	ret = blockNum * ECC_CODE_SIZE;

	return ret;
}
#endif

// LOOK UP TABLE for CRC16 generation
// Polynomial X^16+X^15+X^2+1
uint16_t CRC16Lut[] = {
	0x0000, 0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
	0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027, 0x0022,
	0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D, 0x8077, 0x0072,
	0x0050, 0x8055, 0x805F, 0x005A, 0x804B, 0x004E, 0x0044, 0x8041,
	0x80C3, 0x00C6, 0x00CC, 0x80C9, 0x00D8, 0x80DD, 0x80D7, 0x00D2,
	0x00F0, 0x80F5, 0x80FF, 0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1,
	0x00A0, 0x80A5, 0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1,
	0x8093, 0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
	0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197, 0x0192,
	0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE, 0x01A4, 0x81A1,
	0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB, 0x01FE, 0x01F4, 0x81F1,
	0x81D3, 0x01D6, 0x01DC, 0x81D9, 0x01C8, 0x81CD, 0x81C7, 0x01C2,
	0x0140, 0x8145, 0x814F, 0x014A, 0x815B, 0x015E, 0x0154, 0x8151,
	0x8173, 0x0176, 0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162,
	0x8123, 0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
	0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104, 0x8101,
	0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D, 0x8317, 0x0312,
	0x0330, 0x8335, 0x833F, 0x033A, 0x832B, 0x032E, 0x0324, 0x8321,
	0x0360, 0x8365, 0x836F, 0x036A, 0x837B, 0x037E, 0x0374, 0x8371,
	0x8353, 0x0356, 0x035C, 0x8359, 0x0348, 0x834D, 0x8347, 0x0342,
	0x03C0, 0x83C5, 0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1,
	0x83F3, 0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
	0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7, 0x03B2,
	0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E, 0x0384, 0x8381,
	0x0280, 0x8285, 0x828F, 0x028A, 0x829B, 0x029E, 0x0294, 0x8291,
	0x82B3, 0x02B6, 0x02BC, 0x82B9, 0x02A8, 0x82AD, 0x82A7, 0x02A2,
	0x82E3, 0x02E6, 0x02EC, 0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2,
	0x02D0, 0x82D5, 0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1,
	0x8243, 0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
	0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264, 0x8261,
	0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E, 0x0234, 0x8231,
	0x8213, 0x0216, 0x021C, 0x8219, 0x0208, 0x820D, 0x8207, 0x0202
};

uint16_t Crc16WordCalc(const uint16_t *DataIn, uint32_t DataLen, uint16_t InitVal)
{
	uint32_t    i;
	uint16_t CRCSum;
	uint8_t tempData;

	CRCSum = InitVal;
	//for(i = 0; i < DataLen; i++)
	for (i = 0; i < DataLen; i += 2)
	{
		tempData = (uint8_t)((DataIn[i] >> 8) & 0xFF);
		CRCSum = (CRCSum << 8) ^ CRC16Lut[((CRCSum >> 8) & 0xFF) ^ tempData];

		tempData = (uint8_t)(DataIn[i] & 0xFF);
		CRCSum = (CRCSum << 8) ^ CRC16Lut[((CRCSum >> 8) & 0xFF) ^ tempData];
	}

	return CRCSum;
}

/*
* intial version
*/
uint32_t tool_major_ver = 0;
uint32_t tool_minor_ver = 1;

void printhelp(void)
{
	printf("sw42101_bin_tool(version : v%2.2d.%2.2d)\n", tool_major_ver, tool_minor_ver);
	printf("usage) \n");
	printf("1.img create\t: sw42101_bin_tool [fw file] [img file]\n");
//	printf("2.fw img check\t: sw42101_bin_tool -c [img file]\n");
//	printf("3.font img check\t: sw42101_bin_tool -f [font data file]\n");
//	printf("4.fw img version change\t: sw42101_bin_tool -vc [font data file]\n");
}

int main(int argc, const char *argv[])
{
	FILE *bin_file, *img_file, *c_file;

	int i, file_size;
	unsigned int  fw_crc_value;

	char fname[50];

	printf("<< SW42101 Firmware Tool version %2.2d.%2.2d >>\n", tool_major_ver, tool_minor_ver);

	if (argc < 3) {
		printhelp();
		exit(0);
	}

	// Binary File
	bin_file = fopen(argv[1], "rb");
	if (bin_file == NULL) {
		printf("file open error %s\n", argv[2]);
		exit(0);
	}

	// Image File
	img_file = fopen(argv[2], "wb");
	if (img_file == NULL) {
		printf("full binary image file open error \n");
		exit(0);
	}

	// C File
	sprintf(fname, "bin/FW_x_xx.c");

	c_file = fopen(fname, "w");
	if (c_file == NULL) {
		printf("file open error %s\n", fname);
		exit(0);
	}

	// Full Buffer
	memset(FLASH_BUFFER, 0xFF, FLASH_SIZE);

	// Read Binary File
	fseek(bin_file, 0, SEEK_END);
	file_size = ftell(bin_file);

	fseek(bin_file, 0, SEEK_SET);
	fread(&FLASH_BUFFER[BINARY_ADDR_START], 1, file_size, bin_file);

#if INFO_BACKUP_MODE
	// Write Boot Version & I2C Address
	BACKUP_INFO_1->I2C_BOOT_INFO_b.I2C_SADDR    = I2C_ADDRESS;
	BACKUP_INFO_1->I2C_BOOT_INFO_b.BOOT_VERSION = BOOT_VER;

	BACKUP_INFO_2->I2C_BOOT_INFO_b.I2C_SADDR    = I2C_ADDRESS;
	BACKUP_INFO_2->I2C_BOOT_INFO_b.BOOT_VERSION = BOOT_VER;

	BACKUP_INFO_3->I2C_BOOT_INFO_b.I2C_SADDR    = I2C_ADDRESS;
	BACKUP_INFO_3->I2C_BOOT_INFO_b.BOOT_VERSION = BOOT_VER;
#endif

#if ECC_BACKUP_MODE
	int ecc_size;
	// Calculate & Write ECC Code
	ecc_size = save_ecc_code(FLASH_BUFFER, SECTOR_CODE_SIZE);
	printf("ECC Size : %8.8X(%d)\n", ecc_size, ecc_size);
#endif

	// Calculate CRC Code
	fw_crc_value = Crc16WordCalc((const uint16_t*)&FLASH_BUFFER[SECTOR_ADDR_START], SECTOR_CODE_SIZE / 2, 0) | (Crc16WordCalc((const uint16_t*)&FLASH_BUFFER[SECTOR_ADDR_START+2], SECTOR_CODE_SIZE / 2, 0) << 16);
	fw_crc_value = fw_crc_value ^ 0xFFFFFFFF;

#if CRC_BACKUP_MODE
	// Write CRC Code
	BACKUP_CRC->CRC_1 = fw_crc_value;
	BACKUP_CRC->CRC_2 = fw_crc_value;
#endif

	// Write Image File
	fwrite(&FLASH_BUFFER[BINARY_ADDR_START], 1, BINARY_SIZE, img_file);

	// Write C File
	for(i=BINARY_ADDR_START; i<BINARY_ADDR_END; i++){
		fprintf(c_file, "0x%02x, ", FLASH_BUFFER[i]);
	}

	// Print Code Size & CRC
	printf("==================================\n");
	printf("Firmware Code Size : %8.8X(%d)\n", file_size, file_size);
	printf("Firmware CRC : %8.8X\n", fw_crc_value);
	printf("==================================\n");

	fclose(bin_file);
	fclose(img_file);
	fclose(c_file);

	return 0;
}
