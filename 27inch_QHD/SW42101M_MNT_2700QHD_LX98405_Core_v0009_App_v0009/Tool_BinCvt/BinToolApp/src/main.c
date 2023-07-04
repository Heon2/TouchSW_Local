/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : main.c
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

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "crc.h"
#include "lz.h"
#include "main.h"
/*
 * F/W ������� ���� �κ�!!
 */
#include "..\..\..\App\app_info.h"
#include "..\..\..\Boot\boot_info.h"


static int32_t Boot_Binary_Process(const char * pFBootImgfileName_, const char * pFBootBinfileName_, const char * pFCTypefileName_);
static int32_t App_Binary_Process(const char * pFAppImgfileName_, const char * pfAppBinFineName, const char * pfConfigBinFileName);
static int32_t Total_Binary_Process(const char * pFTotalImgfileName_, const char * pFBootBinFileName, const char * pfAppBinFineName, const char * pfConfigBinFileName);
static int32_t App_FullMem_Binary_Process(const char * pFAppImgfileName_, const char * pfAppBinFineName, const char * pfConfigBinFileName);
static int32_t Total_FullMem_Binary_Process(const char * pFTotalImgfileName_, const char * pFBootBinFileName, const char * pfAppBinFineName, const char * pfConfigBinFileName);


static uint32_t g_ulBootCodeSize;
static uint32_t g_ulAppCodeSize;
static uint32_t g_ulConfigCodeSize;
static uint32_t g_ulConfigCompressedCodeSize;
static uint32_t g_ulBootCRCValue;
static uint32_t g_ulAppCRCValue;
static uint32_t g_ulConfigCRCValue;
static uint16_t g_ulBootVersion;
static uint16_t g_ulAppVersion;
static uint16_t g_ulConfigVersion;
static uint16_t g_usBootMemSize;
static uint16_t g_usAppMemSize;
static uint16_t g_usConfigMemSize;
static uint16_t g_usBootVID;
static uint16_t g_usBootPID;
static uint16_t g_usAppVID;
static uint16_t g_usAppPID;

/*
 * input parameter :
 *   argc - Parameter Count
 *   argv[0] -
 */
int32_t main(int32_t argc, const uint8_t *argv[])
{
	uint32_t ulCompressedRatio1, ulCompressedRatio2;
	eBinaryTypeInfo_e eBinaryType = BINTOOL_BINARY_TYPE_ERROR;

	printf("=========================================================\n");
	printf("================ Binary Convert Start  ==================\n");
	printf("<< SW42102 Firmware Tool version %2.2d.%2.2d >>\n", BIN_TOOL_MAJOR_VERSION, BIN_TOOL_MINOR_VERSION);

	if( argc < 4 )
		return 0;
	if( strlen(argv[1]) < 4 )
		return 0;

	if(strncmp(argv[1], "-boot", 5) == 0)
	{
		eBinaryType = BINTOOL_BINARY_TYPE_BOOT_IMG;
	}
	else if(strncmp(argv[1], "-app", 4) == 0)
	{
		eBinaryType = BINTOOL_BINARY_TYPE_APP_IMG;
	}
	else if(strncmp(argv[1], "-total", 6) == 0)
	{
		eBinaryType = BINTOOL_BINARY_TYPE_TOTAL_IMG;
	}
	else if(strncmp(argv[1], "-fullapp", 8) == 0)
	{
		eBinaryType = BINTOOL_BINARY_TYPE_FULLMEM_APP_IMG;
	}
	else if(strncmp(argv[1], "-fulltotal", 10) == 0)
	{
		eBinaryType = BINTOOL_BINARY_TYPE_FULLMEM_TOTAL_IMG;
	}

	switch(eBinaryType)
	{
		case BINTOOL_BINARY_TYPE_BOOT_IMG:
		{
			if(Boot_Binary_Process(argv[2], argv[3], argv[4]) < 0)
			{
				goto GOTO_ERROR_HANDLE;
			}
			printf("Bootloader Code Size : %8.8X(%d)byte\n", g_ulBootCodeSize, g_ulBootCodeSize);
			printf("Bootloader Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulBootVersion), MINORVERSION(g_ulBootVersion));
			printf("Bootloader CRC       : %8.8X\n", g_ulBootCRCValue);
//			printf("Bootloader Memory    : %dkByte\n", g_usBootMemSize);
			printf("Bootloader VID       : 0x%4X\n", g_usBootVID);
			printf("Bootloader PID       : 0x%4X\n", g_usBootPID);

			break;
		}
		case BINTOOL_BINARY_TYPE_APP_IMG:
		{
			if(App_Binary_Process(argv[2], argv[3], argv[4]) < 0)
			{
				goto GOTO_ERROR_HANDLE;
			}

			printf("Application       Code Size : %8.8X(%d)byte\n", g_ulAppCodeSize, g_ulAppCodeSize);
			if(g_ulConfigCodeSize > 0)
			{
				printf("Config            Code Size : %8.8X(%d)byte\n", g_ulConfigCodeSize, g_ulConfigCodeSize);
				printf("Compressed Config Code Size : %8.8X(%d)byte\n", g_ulConfigCompressedCodeSize, g_ulConfigCompressedCodeSize);
				ulCompressedRatio1 = ((g_ulConfigCodeSize - g_ulConfigCompressedCodeSize) * 10000) / g_ulConfigCodeSize;
				ulCompressedRatio2 = ulCompressedRatio1 % 100;
				ulCompressedRatio1 = ulCompressedRatio1 / 100;
				printf("Compressed Ratio            : %d.%d%% \n", ulCompressedRatio1, ulCompressedRatio2);
				printf("Application       Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulAppVersion), MINORVERSION(g_ulAppVersion));
				printf("Config            Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulConfigVersion), MINORVERSION(g_ulConfigVersion));
				printf("Application       CRC       : %8.8X\n", g_ulAppCRCValue);
				printf("Config            CRC       : %8.8X\n", g_ulConfigCRCValue);
			}
			else
			{
				printf("Application       Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulAppVersion), MINORVERSION(g_ulAppVersion));
				printf("Application       CRC       : %8.8X\n", g_ulAppCRCValue);
			}
			printf("Application       VID       : 0x%4X\n", g_usAppVID);
			printf("Application       PID       : 0x%4X\n", g_usAppPID);
			break;
		}
		case BINTOOL_BINARY_TYPE_TOTAL_IMG:
		{
			/*
			 * Total�� ���, App.img���ϰ� Total.img���� ��� �����ϵ��� �Ѵ�.
			 */
			if (App_Binary_Process(argv[2], argv[5], argv[6]) < 0)
			{
				goto GOTO_ERROR_HANDLE;
			}
			if (Total_Binary_Process(argv[3], argv[4], argv[5], argv[6]) < 0)
			{
				goto GOTO_ERROR_HANDLE;
			}

			printf("Bootloader        Code Size : %8.8X(%d)byte\n", g_ulBootCodeSize, g_ulBootCodeSize);
			printf("Application       Code Size : %8.8X(%d)byte\n", g_ulAppCodeSize, g_ulAppCodeSize);
			if(g_ulConfigCodeSize > 0)
			{
				printf("Config            Code Size : %8.8X(%d)byte\n", g_ulConfigCodeSize, g_ulConfigCodeSize);
				printf("Compressed Config Code Size : %8.8X(%d)byte\n", g_ulConfigCompressedCodeSize, g_ulConfigCompressedCodeSize);
				ulCompressedRatio1 = ((g_ulConfigCodeSize - g_ulConfigCompressedCodeSize) * 10000) / g_ulConfigCodeSize;
				ulCompressedRatio2 = ulCompressedRatio1 % 100;
				ulCompressedRatio1 = ulCompressedRatio1 / 100;
				printf("Compressed Ratio            : %d.%d%% \n", ulCompressedRatio1, ulCompressedRatio2);
				printf("Bootloader        Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulBootVersion), MINORVERSION(g_ulBootVersion));
				printf("Application       Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulAppVersion), MINORVERSION(g_ulAppVersion));
				printf("Config            Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulConfigVersion), MINORVERSION(g_ulConfigVersion));
				printf("Bootloader        CRC       : %8.8X\n", g_ulBootCRCValue);
				printf("Application       CRC       : %8.8X\n", g_ulAppCRCValue);
				printf("Config            CRC       : %8.8X\n", g_ulConfigCRCValue);
			}
			else
			{
				printf("Bootloader        Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulBootVersion), MINORVERSION(g_ulBootVersion));
				printf("Application       Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulAppVersion), MINORVERSION(g_ulAppVersion));
				printf("Bootloader        CRC       : %8.8X\n", g_ulBootCRCValue);
				printf("Application       CRC       : %8.8X\n", g_ulAppCRCValue);
			}
			printf("Bootloader        VID       : 0x%4X\n", g_usBootVID);
			printf("Bootloader        PID       : 0x%4X\n", g_usBootPID);
			printf("Application       VID       : 0x%4X\n", g_usAppVID);
			printf("Application       PID       : 0x%4X\n", g_usAppPID);
			break;
		}
		case BINTOOL_BINARY_TYPE_FULLMEM_APP_IMG:
		{
			if(App_FullMem_Binary_Process(argv[2], argv[3], argv[4]) < 0)
			{
				goto GOTO_ERROR_HANDLE;
			}

			printf("Application       Code Size : %8.8X(%d)byte\n", g_ulAppCodeSize, g_ulAppCodeSize);
			if(g_ulConfigCodeSize > 0)
			{
				printf("Config            Code Size : %8.8X(%d)byte\n", g_ulConfigCodeSize, g_ulConfigCodeSize);
				printf("Compressed Config Code Size : %8.8X(%d)byte\n", g_ulConfigCompressedCodeSize, g_ulConfigCompressedCodeSize);
				ulCompressedRatio1 = ((g_ulConfigCodeSize - g_ulConfigCompressedCodeSize) * 10000) / g_ulConfigCodeSize;
				ulCompressedRatio2 = ulCompressedRatio1 % 100;
				ulCompressedRatio1 = ulCompressedRatio1 / 100;
				printf("Compressed Ratio            : %d.%d%% \n", ulCompressedRatio1, ulCompressedRatio2);
				printf("Application       Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulAppVersion), MINORVERSION(g_ulAppVersion));
				printf("Config            Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulConfigVersion), MINORVERSION(g_ulConfigVersion));
				printf("Application       CRC       : %8.8X\n", g_ulAppCRCValue);
				printf("Config            CRC       : %8.8X\n", g_ulConfigCRCValue);
			}
			else
			{
				printf("Application       Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulAppVersion), MINORVERSION(g_ulAppVersion));
				printf("Application       CRC       : %8.8X\n", g_ulAppCRCValue);
			}
			printf("Application       VID       : 0x%4X\n", g_usAppVID);
			printf("Application       PID       : 0x%4X\n", g_usAppPID);

			break;
		}
		case BINTOOL_BINARY_TYPE_FULLMEM_TOTAL_IMG:
		{
			/*
			 * Total�� ���, App.img���ϰ� Total.img���� ��� �����ϵ��� �Ѵ�.
			 */
			if (App_FullMem_Binary_Process(argv[2], argv[5], argv[6]) < 0)
			{
				goto GOTO_ERROR_HANDLE;
			}
			if (Total_FullMem_Binary_Process(argv[3], argv[4], argv[5], argv[6]) < 0)
			{
				goto GOTO_ERROR_HANDLE;
			}

			printf("Bootloader        Code Size : %8.8X(%d)byte\n", g_ulBootCodeSize, g_ulBootCodeSize);
			printf("Application       Code Size : %8.8X(%d)byte\n", g_ulAppCodeSize, g_ulAppCodeSize);
			if(g_ulConfigCodeSize > 0)
			{
				printf("Config            Code Size : %8.8X(%d)byte\n", g_ulConfigCodeSize, g_ulConfigCodeSize);
				printf("Compressed Config Code Size : %8.8X(%d)byte\n", g_ulConfigCompressedCodeSize, g_ulConfigCompressedCodeSize);
				ulCompressedRatio1 = ((g_ulConfigCodeSize - g_ulConfigCompressedCodeSize) * 10000) / g_ulConfigCodeSize;
				ulCompressedRatio2 = ulCompressedRatio1 % 100;
				ulCompressedRatio1 = ulCompressedRatio1 / 100;
				printf("Compressed Ratio            : %d.%d%% \n", ulCompressedRatio1, ulCompressedRatio2);
				printf("Bootloader        Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulBootVersion), MINORVERSION(g_ulBootVersion));
				printf("Application       Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulAppVersion), MINORVERSION(g_ulAppVersion));
				printf("Config            Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulConfigVersion), MINORVERSION(g_ulConfigVersion));
				printf("Bootloader        CRC       : %8.8X\n", g_ulBootCRCValue);
				printf("Application       CRC       : %8.8X\n", g_ulAppCRCValue);
				printf("Config            CRC       : %8.8X\n", g_ulConfigCRCValue);
			}
			else
			{
				printf("Bootloader        Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulBootVersion), MINORVERSION(g_ulBootVersion));
				printf("Application       Version   : %2.2X.%2.2X\n", MAJORVERSION(g_ulAppVersion), MINORVERSION(g_ulAppVersion));
				printf("Bootloader        CRC       : %8.8X\n", g_ulBootCRCValue);
				printf("Application       CRC       : %8.8X\n", g_ulAppCRCValue);
			}
			printf("Bootloader        VID       : 0x%4X\n", g_usBootVID);
			printf("Bootloader        PID       : 0x%4X\n", g_usBootPID);
			printf("Application       VID       : 0x%4X\n", g_usAppVID);
			printf("Application       PID       : 0x%4X\n", g_usAppPID);

			break;
		}
		case BINTOOL_BINARY_TYPE_ERROR:
		default:
		{
			printf("Binary Type Error!!");
			goto GOTO_ERROR_HANDLE;
		}
	}

	printf("===============  Binary Convert Success!!  ==============\n");
	printf("=========================================================\n");

	return 0;

GOTO_ERROR_HANDLE:

	printf("++++++++++++++++ Binary Convert Fail!! ++++++++++++++++++\n");
	printf("=========================================================\n");
	return 0;
}

static int32_t Boot_Binary_Process(const char * pFBootImgfileName_, const char * pFBootBinfileName_, const char * pFCTypefileName_)
{
	int32_t lReg = 0;
	FILE * pFBootBinFile = NULL;
	FILE * pFBootInfoBinFile = NULL;
	FILE * pFBootImgFile = NULL;
	FILE * pFCTypeFile = NULL;
	uint8_t * pFullBinaryBuf;
	char vcBootInfoFilePath[32];
	tBootGenInfo_t tBootGenInfo;
	tBootTailInfo_t tBootTailInfo;
	uint32_t ulBootInfoBinFileSize;

	/*
	 * Bin���� Open
	 */
	pFBootBinFile = fopen(pFBootBinfileName_, "rb");
	if (pFBootBinFile)
	{
		/*
		 * BOOT_INFO.bin ���� Open
		 */
		sprintf(&vcBootInfoFilePath[0], "bin\\Binary\\BOOT_INFO.bin");
		pFBootInfoBinFile = fopen(vcBootInfoFilePath, "rb");
		if (pFBootInfoBinFile)
		{
			/*
			 * ������ Image���� ����
			 */
			pFBootImgFile = fopen(pFBootImgfileName_, "wb");
			if (pFBootImgFile)
			{
				pFullBinaryBuf = (uint8_t *)malloc(BOOT_BINARY_FULL_SIZE);
				if (pFullBinaryBuf)
				{
					memset(pFullBinaryBuf, 0xFF, BOOT_BINARY_FULL_SIZE);
					/*
					 * Bin ���� Size Check!!
					 */
					fseek(pFBootBinFile, 0, SEEK_END);
					g_ulBootCodeSize = ftell(pFBootBinFile);
					if(g_ulBootCodeSize <= BOOT_BINARY_FULL_SIZE)
					{
						/*
						 * Bin���� Size��ŭ Read�Ͽ� FullBinaryBuf�� ��´�.
						 */
						fseek(pFBootBinFile, 0, SEEK_SET);
						fread(&pFullBinaryBuf[0], 1, g_ulBootCodeSize, pFBootBinFile);

						/*
						 * Bootloader Information Buffer�� Write
						 */
						fseek(pFBootInfoBinFile, 0, SEEK_END);
						ulBootInfoBinFileSize = ftell(pFBootInfoBinFile);
						fseek(pFBootInfoBinFile, 0, SEEK_SET);
						fread((uint8_t *)&tBootGenInfo, 1, ulBootInfoBinFileSize, pFBootInfoBinFile);
						g_ulBootVersion = tBootTailInfo.usBootVer = tBootGenInfo.usBootVer;
						g_usBootMemSize = tBootTailInfo.usBootMemSize = tBootGenInfo.usBootMemSize;
						g_usBootVID = tBootTailInfo.usBootVID = tBootGenInfo.usBootVID;
						g_usBootPID = tBootTailInfo.usBootPID = tBootGenInfo.usBootPID;
						memcpy(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE - sizeof(tBootTailInfo_t)], &tBootTailInfo, sizeof(tBootTailInfo_t));

						/*
						 * CRC�� ��� �� Buffer�� Write
						 */
						g_ulBootCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[0]), BOOT_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE);
						memcpy(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE], &g_ulBootCRCValue, CRC_CODE_BYTE_SIZE);


						/*
						 * BinaryBuf�� �ִ� ������ Img���Ͽ� ���!!
						 */
						fwrite(&pFullBinaryBuf[0], 1, BOOT_BINARY_FULL_SIZE, pFBootImgFile);

						/*
						 * BinaryBuf�� �ִ� ������ .C���Ϸ� ����!!
						 */
						if (pFCTypefileName_)
						{
							pFCTypeFile = fopen(pFCTypefileName_, "wb");
							if (pFCTypeFile)
							{
								uint32_t i;
								uint8_t * pFullCtypeBuf = NULL;
								uint32_t ulFullCtypeBufferIdx;
								uint32_t ulFullCtypeBufSize = ((BOOT_BINARY_FULL_SIZE) * CTYPE_ONE_BYTE_NUM) - 2;
								ulFullCtypeBufSize += (BOOT_BINARY_FULL_SIZE / CTYPE_ONE_LINE_BYTE_NUM);

								pFullCtypeBuf = (uint8_t *)malloc(ulFullCtypeBufSize);
								if (pFullCtypeBuf)
								{
									ulFullCtypeBufferIdx = 0;
									for (i = 0; i<BOOT_BINARY_FULL_SIZE; i++)
									{
										if (i == 0)
										{
											sprintf(&pFullCtypeBuf[ulFullCtypeBufferIdx], "\t0x%02X, ", pFullBinaryBuf[i]);
											ulFullCtypeBufferIdx += (CTYPE_ONE_BYTE_NUM + CTYPE_TAB_BYTE_NUM);
										}
										else if (i == BOOT_BINARY_FULL_SIZE-1)
										{
											sprintf(&pFullCtypeBuf[ulFullCtypeBufferIdx], "0x%02X", pFullBinaryBuf[i]);
										}
										else if (i > 0 && i % (CTYPE_ONE_LINE_BYTE_NUM) == (CTYPE_ONE_LINE_BYTE_NUM - 1))
										{
											sprintf(&pFullCtypeBuf[ulFullCtypeBufferIdx], "0x%02X,\n\t", pFullBinaryBuf[i]);
											ulFullCtypeBufferIdx += (CTYPE_ONE_BYTE_NUM + CTYPE_TAB_BYTE_NUM);
										}
										else
										{
											sprintf(&pFullCtypeBuf[ulFullCtypeBufferIdx], "0x%02X, ", pFullBinaryBuf[i]);
											ulFullCtypeBufferIdx += CTYPE_ONE_BYTE_NUM;
										}
									}

									fwrite(&pFullCtypeBuf[0], 1, ulFullCtypeBufSize, pFCTypeFile);

									free(pFullCtypeBuf);
								}
								else
								{
									lReg = -1;
									printf("CType buffer memory allocation error \n");
								}

								fclose(pFCTypeFile);
							}
							else
							{
								lReg = -1;
								printf("cType file open error %s\n", pFCTypefileName_);
							}
						} // if (pFCTypefileName_)
					}
					else
					{
						lReg = -1;
						printf("boot Binary Size Exceed [%d] \n", g_ulBootCodeSize);
					}

					free(pFullBinaryBuf);
				}
				else
				{
					lReg = -1;
					printf("binary buffer memory allocation error \n");
				}

				fclose(pFBootImgFile);
			}
			else
			{
				lReg = -1;
				printf("image file open error %s\n", pFBootImgfileName_);
			}

			fclose(pFBootInfoBinFile);
		}
		else
		{
			lReg = -1;
			printf("bin file open error BOOT_INFO.bin\n");
		}

		fclose(pFBootBinFile);
	}
	else
	{
		lReg = -1;
		printf("bin file open error %s\n", pFBootBinfileName_);
	}

	return lReg;
}

static int32_t App_Binary_Process(const char * pFAppImgfileName_, const char * pfAppBinFineName, const char * pfConfigBinFileName)
{
	int32_t lReg = 0;
	char * pcConfigCompressedFileName = NULL;
	FILE * pFAppBinFile = NULL;
	FILE * pFConfigBinFile = NULL;
	FILE * pFConfigCompressedBinFile = NULL;
	FILE * pFAppConfigInfoBinFile = NULL;
	FILE * pFAppImgFile = NULL;
	uint8_t * pFullBinaryBuf = NULL;
	uint8_t * pConfigBinaryBuf = NULL;
	uint8_t * pConfigCompressedBinaryBuf = NULL;

	char vcAppConfigInfoFilePath[32];
	tAppConfigGenInfo_t tAppConfigGenInfo;
	tAppTailInfo_t tAppTailInfo;
	tConfigTailInfo_t tConfigTailInfo;
	uint32_t ulAppConfigInfoBinFileSize;

	if (pFAppImgfileName_ == NULL || pfAppBinFineName == NULL)
	{
		printf("Input File Name Error!! \n");
		return -1;
	}

	/*
	 * App Bin���� Open
	 */
	pFAppBinFile = fopen(pfAppBinFineName, "rb");
	if (pFAppBinFile)
	{
		/*
		 * Config Bin���� Open (���� �� ���� ���� ���� ������ �������!!)
		 */
		if (pfConfigBinFileName)
		{
			pcConfigCompressedFileName = (char *)malloc(_MAX_PATH);
			memset(pcConfigCompressedFileName, 0, (_MAX_PATH));
			if(pcConfigCompressedFileName)
			{
				sprintf(pcConfigCompressedFileName, "%s.compressed", pfConfigBinFileName);
				pFConfigBinFile = fopen(pfConfigBinFileName, "rb");
				pFConfigCompressedBinFile = fopen(pcConfigCompressedFileName, "wb");
				free(pcConfigCompressedFileName);
			}
		}

		if ((pfConfigBinFileName == NULL) || (pfConfigBinFileName != NULL && pFConfigBinFile && pFConfigCompressedBinFile))
		{
			/*
			 * APP_INFO.bin ���� Open
			 */
			sprintf(&vcAppConfigInfoFilePath[0], "bin\\Binary\\APP_INFO.bin");
			pFAppConfigInfoBinFile = fopen(vcAppConfigInfoFilePath, "rb");
			if (pFAppConfigInfoBinFile)
			{
				/*
				 * ������ Image ���� Open
				 */
				pFAppImgFile = fopen(pFAppImgfileName_, "wb");
				if (pFAppImgFile)
				{
					pFullBinaryBuf = (uint8_t *)malloc((APP_BINARY_FULL_SIZE + CONFIG_BINARY_FULL_SIZE));
					if (pFullBinaryBuf)
					{
						memset(pFullBinaryBuf, 0xFF, (APP_BINARY_FULL_SIZE + CONFIG_BINARY_FULL_SIZE));
						/*
						 * App Bin ���� Size Check!!
						 */
						fseek(pFAppBinFile, 0, SEEK_END);
						g_ulAppCodeSize = ftell(pFAppBinFile);
						if (g_ulAppCodeSize <= APP_BINARY_FULL_SIZE)
						{
							/*
							 * Config Bin �������� �� ��쿡�� Size Check!!
							 */
							g_ulConfigCodeSize = 0;
							g_ulConfigCompressedCodeSize = 0;
							if (pFConfigBinFile)
							{
								fseek(pFConfigBinFile, 0, SEEK_END);
								g_ulConfigCodeSize = ftell(pFConfigBinFile);
								pConfigBinaryBuf = (uint8_t *)malloc(g_ulConfigCodeSize);
								pConfigCompressedBinaryBuf = (uint8_t *)malloc((g_ulConfigCodeSize << 1));

								if(pConfigBinaryBuf && pConfigCompressedBinaryBuf)
								{
									fseek(pFConfigBinFile, 0, SEEK_SET);
									fread(&pConfigBinaryBuf[0], 1, g_ulConfigCodeSize, pFConfigBinFile);

									g_ulConfigCompressedCodeSize = LZ_Compress(&pConfigBinaryBuf[0], &pConfigCompressedBinaryBuf[0], g_ulConfigCodeSize);
								}
							}

							if ((pFConfigBinFile == NULL) ||
								(pFConfigBinFile && (g_ulConfigCompressedCodeSize > 0) && (g_ulConfigCompressedCodeSize <= (CONFIG_BINARY_FULL_SIZE - CONFIG_LENGTH_SIZE))))
							{
								/*
								 * Application Bin���� Size��ŭ Read�Ͽ� FullBinaryBuf�� ��´�.
								 */
								fseek(pFAppBinFile, 0, SEEK_SET);
								fread(&pFullBinaryBuf[0], 1, g_ulAppCodeSize, pFAppBinFile);

								/*
								 * Application & Config Information Buffer�� Write
								 */
								fseek(pFAppConfigInfoBinFile, 0, SEEK_END);
								ulAppConfigInfoBinFileSize = ftell(pFAppConfigInfoBinFile);
								fseek(pFAppConfigInfoBinFile, 0, SEEK_SET);
								fread((uint8_t *)&tAppConfigGenInfo, 1, ulAppConfigInfoBinFileSize, pFAppConfigInfoBinFile);
								tAppTailInfo.usBootCompVer = tAppConfigGenInfo.usBootCompVer;
								tAppTailInfo.usConfigCompVer = tAppConfigGenInfo.usConfigVer;
								tAppTailInfo.usConfigMemSize = tAppConfigGenInfo.usConfigMemSize;
								g_ulAppVersion = tAppTailInfo.usAppVer = tAppConfigGenInfo.usAppVer;
								g_ulConfigVersion = tConfigTailInfo.usConfigVer = tAppConfigGenInfo.usConfigVer;
								g_usAppMemSize = tAppTailInfo.usAppMemSize = tAppConfigGenInfo.usAppMemSize;
								tAppTailInfo.usUsedConfigFile = tAppConfigGenInfo.usUsedConfigFile;
								g_usConfigMemSize = tConfigTailInfo.usConfigMemSize = tAppConfigGenInfo.usConfigMemSize;
								g_usAppVID = tAppTailInfo.usAppVID = tAppConfigGenInfo.usAppVID;
								g_usAppPID = tAppTailInfo.usAppPID = tAppConfigGenInfo.usAppPID;
	#if USE_GDMA_CRC_BUG_WORKROUND
								memcpy(&pFullBinaryBuf[APP_BINARY_FULL_SIZE - sizeof(tAppTailInfo_t) - 4], &tAppTailInfo, sizeof(tAppTailInfo_t));
	#else /* USE_GDMA_CRC_BUG_WORKROUND */
								memcpy(&pFullBinaryBuf[APP_BINARY_FULL_SIZE - sizeof(tAppTailInfo_t)], &tAppTailInfo, sizeof(tAppTailInfo_t));
	#endif /* USE_GDMA_CRC_BUG_WORKROUND */
								memcpy(&pFullBinaryBuf[(APP_BINARY_FULL_SIZE + CONFIG_BINARY_FULL_SIZE) - sizeof(tConfigTailInfo_t)], &tConfigTailInfo, sizeof(tConfigTailInfo_t));

								if (pFConfigBinFile)
								{
									memcpy(&pFullBinaryBuf[APP_BINARY_FULL_SIZE], &g_ulConfigCompressedCodeSize, CONFIG_LENGTH_SIZE);									// length of compressed ConfigFixed
									memcpy(&pFullBinaryBuf[APP_BINARY_FULL_SIZE + CONFIG_LENGTH_SIZE], &pConfigCompressedBinaryBuf[0], g_ulConfigCompressedCodeSize);	// compressed ConfigFixed
								}
								else
								{
									memcpy(&pFullBinaryBuf[APP_BINARY_FULL_SIZE], &g_ulConfigCompressedCodeSize, CONFIG_LENGTH_SIZE);
								}

	#if USE_GDMA_CRC_BUG_WORKROUND
								g_ulAppCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[0]), APP_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE - 4);
								memcpy(&pFullBinaryBuf[APP_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE - 4], &g_ulAppCRCValue, CRC_CODE_BYTE_SIZE);
	#else /* USE_GDMA_CRC_BUG_WORKROUND */
								g_ulAppCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[0]), APP_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE);
								memcpy(&pFullBinaryBuf[APP_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE], &g_ulAppCRCValue, CRC_CODE_BYTE_SIZE);
	#endif /* USE_GDMA_CRC_BUG_WORKROUND */
								g_ulConfigCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[APP_BINARY_FULL_SIZE]), CONFIG_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE);
								memcpy(&pFullBinaryBuf[(APP_BINARY_FULL_SIZE + CONFIG_BINARY_FULL_SIZE) - CRC_CODE_BYTE_SIZE], &g_ulConfigCRCValue, CRC_CODE_BYTE_SIZE);

								/*
								 * BinaryBuf�� �ִ� ������ Img���Ͽ� ���!!
								 */
								fwrite(&pFullBinaryBuf[0], 1, (APP_BINARY_FULL_SIZE + CONFIG_BINARY_FULL_SIZE), pFAppImgFile);
								if(pFConfigCompressedBinFile)
								{
									fseek(pFConfigCompressedBinFile, 0, SEEK_SET);
									fwrite(&pConfigCompressedBinaryBuf[0], 1, g_ulConfigCompressedCodeSize, pFConfigCompressedBinFile);
								}
							}
							else
							{
								lReg = -1;
								printf("Config Binary Size Exceed [%d] \n", g_ulConfigCodeSize);
							}
						}
						else
						{
							lReg = -1;
							printf("App Binary Size Exceed [%d] \n", g_ulAppCodeSize);
						}

						free(pFullBinaryBuf);
					}
					else
					{
						lReg = -1;
						printf("Full binary buffer memory allocation error \n");
					}

					fclose(pFAppImgFile);
				}
				else
				{
					lReg = -1;
					printf("App Image file open error %s\n", pFAppImgfileName_);
				}

				fclose(pFAppConfigInfoBinFile);
			}
			else
			{
				lReg = -1;
				printf("bin file open error APP_INFO.bin\n");
			}

			if (pFConfigBinFile)
			{
				fclose(pFConfigBinFile);
			}
			if (pFConfigCompressedBinFile)
			{
				fclose(pFConfigCompressedBinFile);
			}
		}
		else
		{
			lReg = -1;
			printf("Config bin file open error %s\n", pfConfigBinFileName);
		}

		fclose(pFAppBinFile);
	}
	else
	{
		lReg = -1;
		printf("App bin file open error %s\n", pfAppBinFineName);
	}

	return lReg;
}

static int32_t Total_Binary_Process(const char * pFTotalImgfileName_, const char * pFBootBinFileName, const char * pfAppBinFineName, const char * pfConfigBinFileName)
{
	int32_t lReg = 0;
	char * pcConfigCompressedFileName = NULL;
	FILE * pFBootBinFile = NULL;
	FILE * pFAppBinFile = NULL;
	FILE * pFConfigBinFile = NULL;
	FILE * pFConfigCompressedBinFile = NULL;
	FILE * pFBootInfoBinFile = NULL;
	FILE * pFAppConfigInfoBinFile = NULL;
	FILE * pFTotalImgFile = NULL;
	uint8_t * pFullBinaryBuf;
	uint8_t * pConfigBinaryBuf = NULL;
	uint8_t * pConfigCompressedBinaryBuf = NULL;
	char vcBootInfoFilePath[32];
	char vcAppConfigInfoFilePath[32];
	tBootGenInfo_t tBootGenInfo;
	tBootTailInfo_t tBootTailInfo;
	uint32_t ulBootInfoBinFileSize;
	tAppConfigGenInfo_t tAppConfigGenInfo;
	tAppTailInfo_t tAppTailInfo;
	tConfigTailInfo_t tConfigTailInfo;
	uint32_t ulAppConfigInfoBinFileSize;

	if (pFTotalImgfileName_ == NULL || pFBootBinFileName == NULL || pfAppBinFineName == NULL)
	{
		printf("Input File Name Error!! \n");
		return -1;
	}

	/*
	 * Boot Bin���� Open
	 */
	pFBootBinFile = fopen(pFBootBinFileName, "rb");
	if (pFBootBinFile)
	{
		/*
		 * App Bin���� Open
		 */
		pFAppBinFile = fopen(pfAppBinFineName, "rb");
		if (pFAppBinFile)
		{
			/*
			 * Config Bin���� Open (���� �� ���� ���� ���� ������ �������!!)
			 */
			if (pfConfigBinFileName)
			{
				pcConfigCompressedFileName = (char *)malloc(_MAX_PATH);
				memset(pcConfigCompressedFileName, 0, (_MAX_PATH));
				if(pcConfigCompressedFileName)
				{
					sprintf(pcConfigCompressedFileName, "%s.compressed", pfConfigBinFileName);
					pFConfigBinFile = fopen(pfConfigBinFileName, "rb");
					pFConfigCompressedBinFile = fopen(pcConfigCompressedFileName, "wb");
					free(pcConfigCompressedFileName);
				}
			}

			if ((pfConfigBinFileName == NULL) || (pfConfigBinFileName != NULL && pFConfigBinFile && pFConfigCompressedBinFile))
			{
				/*
				 * BOOT_INFO.bin ���� Open
				 */
				sprintf(&vcBootInfoFilePath[0], "bin\\Binary\\BOOT_INFO.bin");
				pFBootInfoBinFile = fopen(vcBootInfoFilePath, "rb");
				if (pFBootInfoBinFile)
				{
					/*
					 * APP_INFO.bin ���� Open
					 */
					sprintf(&vcAppConfigInfoFilePath[0], "bin\\Binary\\APP_INFO.bin");
					pFAppConfigInfoBinFile = fopen(vcAppConfigInfoFilePath, "rb");
					if (pFAppConfigInfoBinFile)
					{
						/*
						 * ������ Image ���� Open
						 */
						pFTotalImgFile = fopen(pFTotalImgfileName_, "wb");
						if (pFTotalImgFile)
						{
							pFullBinaryBuf = (uint8_t *)malloc(TOTAL_BINARY_FULL_SIZE);
							if (pFullBinaryBuf)
							{
								memset(pFullBinaryBuf, 0xFF, TOTAL_BINARY_FULL_SIZE);
								/*
								 * Boot Bin ���� Size Check!!
								 */
								fseek(pFBootBinFile, 0, SEEK_END);
								g_ulBootCodeSize = ftell(pFBootBinFile);
								if (g_ulBootCodeSize <= BOOT_BINARY_FULL_SIZE)
								{
									/*
									 * App Bin ���� Size Check!!
									 */
									fseek(pFAppBinFile, 0, SEEK_END);
									g_ulAppCodeSize = ftell(pFAppBinFile);
									if (g_ulAppCodeSize <= APP_BINARY_FULL_SIZE)
									{
										/*
										 * Config Bin �������� �� ��쿡�� Size Check!!
										 */
										g_ulConfigCodeSize = 0;
										g_ulConfigCompressedCodeSize = 0;
										if (pFConfigBinFile)
										{
											fseek(pFConfigBinFile, 0, SEEK_END);
											g_ulConfigCodeSize = ftell(pFConfigBinFile);
											pConfigBinaryBuf = (uint8_t *)malloc(g_ulConfigCodeSize);
											pConfigCompressedBinaryBuf = (uint8_t *)malloc((g_ulConfigCodeSize << 1));

											if(pConfigBinaryBuf && pConfigCompressedBinaryBuf)
											{
												fseek(pFConfigBinFile, 0, SEEK_SET);
												fread(&pConfigBinaryBuf[0], 1, g_ulConfigCodeSize, pFConfigBinFile);

												g_ulConfigCompressedCodeSize = LZ_Compress(&pConfigBinaryBuf[0], &pConfigCompressedBinaryBuf[0], g_ulConfigCodeSize);
											}
										}

										if ((pFConfigBinFile == NULL) ||
											(pFConfigBinFile && (g_ulConfigCompressedCodeSize > 0) && (g_ulConfigCompressedCodeSize <= (CONFIG_BINARY_FULL_SIZE - CONFIG_LENGTH_SIZE))))
										{
											/*
											 * Bootloader Bin���� Size��ŭ Read�Ͽ� FullBinaryBuf�� ��´�.
											 */
											fseek(pFBootBinFile, 0, SEEK_SET);
											fread(&pFullBinaryBuf[0], 1, g_ulBootCodeSize, pFBootBinFile);
											/*
											 * Application Bin���� Size��ŭ Read�Ͽ� FullBinaryBuf�� ��´�.
											 */
											fseek(pFAppBinFile, 0, SEEK_SET);
											fread(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE], 1, g_ulAppCodeSize, pFAppBinFile);

											/*
											 * Bootloader Information Buffer�� Write
											 */
											fseek(pFBootInfoBinFile, 0, SEEK_END);
											ulBootInfoBinFileSize = ftell(pFBootInfoBinFile);
											fseek(pFBootInfoBinFile, 0, SEEK_SET);
											fread((uint8_t *)&tBootGenInfo, 1, ulBootInfoBinFileSize, pFBootInfoBinFile);
											g_ulBootVersion = tBootTailInfo.usBootVer = tBootGenInfo.usBootVer;
											g_usBootMemSize = tBootTailInfo.usBootMemSize = tBootGenInfo.usBootMemSize;
											g_usBootVID = tBootTailInfo.usBootVID = tBootGenInfo.usBootVID;
											g_usBootPID = tBootTailInfo.usBootPID = tBootGenInfo.usBootPID;
											memcpy(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE - sizeof(tBootTailInfo_t)], &tBootTailInfo, sizeof(tBootTailInfo_t));

											/*
											 * Application & Config Information Buffer�� Write
											 */
											fseek(pFAppConfigInfoBinFile, 0, SEEK_END);
											ulAppConfigInfoBinFileSize = ftell(pFAppConfigInfoBinFile);
											fseek(pFAppConfigInfoBinFile, 0, SEEK_SET);
											fread((uint8_t *)&tAppConfigGenInfo, 1, ulAppConfigInfoBinFileSize, pFAppConfigInfoBinFile);
											tAppTailInfo.usBootCompVer = tAppConfigGenInfo.usBootCompVer;
											tAppTailInfo.usConfigCompVer = tAppConfigGenInfo.usConfigVer;
											tAppTailInfo.usConfigMemSize = tAppConfigGenInfo.usConfigMemSize;
											g_ulAppVersion = tAppTailInfo.usAppVer = tAppConfigGenInfo.usAppVer;
											g_ulConfigVersion = tConfigTailInfo.usConfigVer = tAppConfigGenInfo.usConfigVer;
											g_usAppMemSize = tAppTailInfo.usAppMemSize = tAppConfigGenInfo.usAppMemSize;
											tAppTailInfo.usUsedConfigFile = tAppConfigGenInfo.usUsedConfigFile;
											g_usConfigMemSize = tConfigTailInfo.usConfigMemSize = tAppConfigGenInfo.usConfigMemSize;
											g_usAppVID = tAppTailInfo.usAppVID = tAppConfigGenInfo.usAppVID;
											g_usAppPID = tAppTailInfo.usAppPID = tAppConfigGenInfo.usAppPID;
	#if USE_GDMA_CRC_BUG_WORKROUND
											memcpy(&pFullBinaryBuf[(BOOT_BINARY_FULL_SIZE + APP_BINARY_FULL_SIZE) - sizeof(tAppTailInfo_t) - 4], &tAppTailInfo, sizeof(tAppTailInfo_t));
	#else /* USE_GDMA_CRC_BUG_WORKROUND */
											memcpy(&pFullBinaryBuf[(BOOT_BINARY_FULL_SIZE + APP_BINARY_FULL_SIZE) - sizeof(tAppTailInfo_t)], &tAppTailInfo, sizeof(tAppTailInfo_t));
	#endif /* USE_GDMA_CRC_BUG_WORKROUND */
											memcpy(&pFullBinaryBuf[TOTAL_BINARY_FULL_SIZE - sizeof(tConfigTailInfo_t)], &tConfigTailInfo, sizeof(tConfigTailInfo_t));

											if (pFConfigBinFile)
											{
												memcpy(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE + APP_BINARY_FULL_SIZE], &g_ulConfigCompressedCodeSize, CONFIG_LENGTH_SIZE);									// length of compressed ConfigFixed
												memcpy(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE + APP_BINARY_FULL_SIZE + CONFIG_LENGTH_SIZE], &pConfigCompressedBinaryBuf[0], g_ulConfigCompressedCodeSize);	// compressed ConfigFixed
											}
											else
											{
												memcpy(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE + APP_BINARY_FULL_SIZE], &g_ulConfigCompressedCodeSize, CONFIG_LENGTH_SIZE);									// length of compressed ConfigFixed
											}

											/*
											 * CRC�� ��� �� Buffer�� Write
											 */
											g_ulBootCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[0]), BOOT_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE);
											memcpy(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE-CRC_CODE_BYTE_SIZE], &g_ulBootCRCValue, CRC_CODE_BYTE_SIZE);
		#if USE_GDMA_CRC_BUG_WORKROUND
											g_ulAppCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE]), APP_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE - 4);
											memcpy(&pFullBinaryBuf[(BOOT_BINARY_FULL_SIZE + APP_BINARY_FULL_SIZE)-CRC_CODE_BYTE_SIZE - 4], &g_ulAppCRCValue, CRC_CODE_BYTE_SIZE);
		#else /* USE_GDMA_CRC_BUG_WORKROUND */
											g_ulAppCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE]), APP_BINARY_FULL_SIZE-CRC_CODE_BYTE_SIZE);
											memcpy(&pFullBinaryBuf[(BOOT_BINARY_FULL_SIZE + SW42102_APP_BYTE_SIZE)-CRC_CODE_BYTE_SIZE], &g_ulAppCRCValue, CRC_CODE_BYTE_SIZE);
		#endif /* USE_GDMA_CRC_BUG_WORKROUND */
											g_ulConfigCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[(BOOT_BINARY_FULL_SIZE + APP_BINARY_FULL_SIZE)]), CONFIG_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE);
											memcpy(&pFullBinaryBuf[TOTAL_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE], &g_ulConfigCRCValue, CRC_CODE_BYTE_SIZE);

											/*
											 * BinaryBuf�� �ִ� ������ Img���Ͽ� ���!!
											 */
											fwrite(&pFullBinaryBuf[0], 1, TOTAL_BINARY_FULL_SIZE, pFTotalImgFile);
											if(pFConfigCompressedBinFile)
											{
												fseek(pFConfigCompressedBinFile, 0, SEEK_SET);
												fwrite(&pConfigCompressedBinaryBuf[0], 1, g_ulConfigCompressedCodeSize, pFConfigCompressedBinFile);
											}
										}
										else
										{
											lReg = -1;
											printf("Config Binary Size Exceed [%d] \n", g_ulConfigCodeSize);
										}

										if (pConfigBinaryBuf)
										{
											free(pConfigBinaryBuf);
										}
										if (pConfigCompressedBinaryBuf)
										{
											free(pConfigCompressedBinaryBuf);
										}
									}
									else
									{
										lReg = -1;
										printf("App Binary Size Exceed [%d] \n", g_ulAppCodeSize);
									}
								}
								else
								{
									lReg = -1;
									printf("boot Binary Size Exceed [%d] \n", g_ulBootCodeSize);
								}


								free(pFullBinaryBuf);
							}
							else
							{
								lReg = -1;
								printf("Full binary buffer memory allocation error \n");
							}

							fclose(pFTotalImgFile);
						}
						else
						{
							lReg = -1;
							printf("Total Image file open error %s\n", pFTotalImgfileName_);
						}

						fclose(pFAppConfigInfoBinFile);
					}
					else
					{
						lReg = -1;
						printf("bin file open error APP_INFO.bin\n");
					}

					fclose(pFBootInfoBinFile);
				}
				else
				{
					lReg = -1;
					printf("bin file open error BOOT_INFO.bin\n");
				}

				if (pFConfigBinFile)
				{
					fclose(pFConfigBinFile);
				}
				if (pFConfigCompressedBinFile)
				{
					fclose(pFConfigCompressedBinFile);
				}
			}
			else
			{
				lReg = -1;
				printf("Config bin file open error %s\n", pfConfigBinFileName);
			}

			fclose(pFAppBinFile);
		}
		else
		{
			lReg = -1;
			printf("App bin file open error %s\n", pfAppBinFineName);
		}

		fclose(pFBootBinFile);
	}
	else
	{
		lReg = -1;
		printf("Boot bin file open error %s\n", pFBootBinFileName);
	}

	return lReg;
}

static int32_t App_FullMem_Binary_Process(const char * pFAppImgfileName_, const char * pfAppBinFineName, const char * pfConfigBinFileName)
{
	int32_t lReg = 0;
	char * pcConfigCompressedFileName = NULL;
	FILE * pFAppBinFile = NULL;
	FILE * pFConfigBinFile = NULL;
	FILE * pFConfigCompressedBinFile = NULL;
	FILE * pFAppConfigInfoBinFile = NULL;
	FILE * pFAppImgFile = NULL;
	uint8_t * pFullBinaryBuf = NULL;
	uint8_t * pConfigBinaryBuf = NULL;
	uint8_t * pConfigCompressedBinaryBuf = NULL;

	char vcAppConfigInfoFilePath[32];
	tAppConfigGenInfo_t tAppConfigGenInfo;
	tAppTailInfo_t tAppTailInfo;
	tConfigTailInfo_t tConfigTailInfo;
	uint32_t ulAppConfigInfoBinFileSize;

	if (pFAppImgfileName_ == NULL || pfAppBinFineName == NULL)
	{
		printf("Input File Name Error!! \n");
		return -1;
	}

	/*
	 * App Bin���� Open
	 */
	pFAppBinFile = fopen(pfAppBinFineName, "rb");
	if (pFAppBinFile)
	{
		/*
		 * Config Bin���� Open (���� �� ���� ���� ���� ������ �������!!)
		 */
		if (pfConfigBinFileName)
		{
			pcConfigCompressedFileName = (char *)malloc(_MAX_PATH);
			memset(pcConfigCompressedFileName, 0, (_MAX_PATH));
			if(pcConfigCompressedFileName)
			{
				sprintf(pcConfigCompressedFileName, "%s.compressed", pfConfigBinFileName);
				pFConfigBinFile = fopen(pfConfigBinFileName, "rb");
				pFConfigCompressedBinFile = fopen(pcConfigCompressedFileName, "wb");
				free(pcConfigCompressedFileName);
			}
		}

		if ((pfConfigBinFileName == NULL) || (pfConfigBinFileName != NULL && pFConfigBinFile && pFConfigCompressedBinFile))
		{
			/*
			 * APP_INFO.bin ���� Open
			 */
			sprintf(&vcAppConfigInfoFilePath[0], "bin\\Binary\\APP_INFO.bin");
			pFAppConfigInfoBinFile = fopen(vcAppConfigInfoFilePath, "rb");
			if (pFAppConfigInfoBinFile)
			{
				/*
				 * ������ Image ���� Open
				 */
				pFAppImgFile = fopen(pFAppImgfileName_, "wb");
				if (pFAppImgFile)
				{
					pFullBinaryBuf = (uint8_t *)malloc((FULLMEM_APP_BINARY_FULL_SIZE + FULLMEM_CONFIG_BINARY_FULL_SIZE));
					if (pFullBinaryBuf)
					{
						memset(pFullBinaryBuf, 0xFF, (FULLMEM_APP_BINARY_FULL_SIZE + FULLMEM_CONFIG_BINARY_FULL_SIZE));
						/*
						 * App Bin ���� Size Check!!
						 */
						fseek(pFAppBinFile, 0, SEEK_END);
						g_ulAppCodeSize = ftell(pFAppBinFile);
						if (g_ulAppCodeSize <= FULLMEM_APP_BINARY_FULL_SIZE - CODE_SRAM_APP_RESERV_BYTE_SIZE)
						{
							/*
							 * Config Bin �������� �� ��쿡�� Size Check!!
							 */
							g_ulConfigCodeSize = 0;
							g_ulConfigCompressedCodeSize = 0;
							if (pFConfigBinFile)
							{
								fseek(pFConfigBinFile, 0, SEEK_END);
								g_ulConfigCodeSize = ftell(pFConfigBinFile);
								pConfigBinaryBuf = (uint8_t *)malloc(g_ulConfigCodeSize);
								pConfigCompressedBinaryBuf = (uint8_t *)malloc((g_ulConfigCodeSize << 1));

								if(pConfigBinaryBuf && pConfigCompressedBinaryBuf)
								{
									fseek(pFConfigBinFile, 0, SEEK_SET);
									fread(&pConfigBinaryBuf[0], 1, g_ulConfigCodeSize, pFConfigBinFile);

									g_ulConfigCompressedCodeSize = LZ_Compress(&pConfigBinaryBuf[0], &pConfigCompressedBinaryBuf[0], g_ulConfigCodeSize);
								}
							}

							if ((pFConfigBinFile == NULL) ||
								(pFConfigBinFile && (g_ulConfigCompressedCodeSize > 0) && (g_ulConfigCompressedCodeSize <= (FULLMEM_CONFIG_BINARY_FULL_SIZE - CONFIG_LENGTH_SIZE))))
							{
								/*
								 * Application Bin���� Size��ŭ Read�Ͽ� FullBinaryBuf�� ��´�.
								 */
								fseek(pFAppBinFile, 0, SEEK_SET);
								fread(&pFullBinaryBuf[0], 1, g_ulAppCodeSize, pFAppBinFile);

								/*
								 * Application & Config Information Buffer�� Write
								 */
								fseek(pFAppConfigInfoBinFile, 0, SEEK_END);
								ulAppConfigInfoBinFileSize = ftell(pFAppConfigInfoBinFile);
								fseek(pFAppConfigInfoBinFile, 0, SEEK_SET);
								fread((uint8_t *)&tAppConfigGenInfo, 1, ulAppConfigInfoBinFileSize, pFAppConfigInfoBinFile);
								tAppTailInfo.usBootCompVer = tAppConfigGenInfo.usBootCompVer;
								tAppTailInfo.usConfigCompVer = tAppConfigGenInfo.usConfigVer;
								tAppTailInfo.usConfigMemSize = tAppConfigGenInfo.usConfigMemSize;
								g_ulAppVersion = tAppTailInfo.usAppVer = tAppConfigGenInfo.usAppVer;
								g_ulConfigVersion = tConfigTailInfo.usConfigVer = tAppConfigGenInfo.usConfigVer;
								g_usAppMemSize = tAppTailInfo.usAppMemSize = tAppConfigGenInfo.usAppMemSize;
								tAppTailInfo.usUsedConfigFile = tAppConfigGenInfo.usUsedConfigFile;
								g_usConfigMemSize = tConfigTailInfo.usConfigMemSize = tAppConfigGenInfo.usConfigMemSize;
								g_usAppVID = tAppTailInfo.usAppVID = tAppConfigGenInfo.usAppVID;
								g_usAppPID = tAppTailInfo.usAppPID = tAppConfigGenInfo.usAppPID;
								memcpy(&pFullBinaryBuf[FULLMEM_APP_BINARY_FULL_SIZE - CODE_SRAM_APP_RESERV_BYTE_SIZE - sizeof(tAppTailInfo_t)], &tAppTailInfo, sizeof(tAppTailInfo_t));
								memcpy(&pFullBinaryBuf[(FULLMEM_APP_BINARY_FULL_SIZE + FULLMEM_CONFIG_BINARY_FULL_SIZE) - sizeof(tConfigTailInfo_t)], &tConfigTailInfo, sizeof(tConfigTailInfo_t));

								if (pFConfigBinFile)
								{
									memcpy(&pFullBinaryBuf[FULLMEM_APP_BINARY_FULL_SIZE], &g_ulConfigCompressedCodeSize, CONFIG_LENGTH_SIZE);									// length of compressed ConfigFixed
									memcpy(&pFullBinaryBuf[FULLMEM_APP_BINARY_FULL_SIZE + CONFIG_LENGTH_SIZE], &pConfigCompressedBinaryBuf[0], g_ulConfigCompressedCodeSize);	// compressed ConfigFixed
								}
								else
								{
									memcpy(&pFullBinaryBuf[FULLMEM_APP_BINARY_FULL_SIZE], &g_ulConfigCompressedCodeSize, CONFIG_LENGTH_SIZE);
								}

								g_ulAppCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[0]), FULLMEM_APP_BINARY_FULL_SIZE - CODE_SRAM_APP_RESERV_BYTE_SIZE - CRC_CODE_BYTE_SIZE);
								memcpy(&pFullBinaryBuf[FULLMEM_APP_BINARY_FULL_SIZE - CODE_SRAM_APP_RESERV_BYTE_SIZE - CRC_CODE_BYTE_SIZE], &g_ulAppCRCValue, CRC_CODE_BYTE_SIZE);
								g_ulConfigCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[FULLMEM_APP_BINARY_FULL_SIZE]), FULLMEM_CONFIG_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE);
								memcpy(&pFullBinaryBuf[(FULLMEM_APP_BINARY_FULL_SIZE + FULLMEM_CONFIG_BINARY_FULL_SIZE) - CRC_CODE_BYTE_SIZE], &g_ulConfigCRCValue, CRC_CODE_BYTE_SIZE);

								/*
								 * BinaryBuf�� �ִ� ������ Img���Ͽ� ���!!
								 */
								fwrite(&pFullBinaryBuf[0], 1, (FULLMEM_APP_BINARY_FULL_SIZE + FULLMEM_CONFIG_BINARY_FULL_SIZE), pFAppImgFile);
								if(pFConfigCompressedBinFile)
								{
									fseek(pFConfigCompressedBinFile, 0, SEEK_SET);
									fwrite(&pConfigCompressedBinaryBuf[0], 1, g_ulConfigCompressedCodeSize, pFConfigCompressedBinFile);
								}
							}
							else
							{
								lReg = -1;
								printf("Config Binary Size Exceed [%d] \n", g_ulConfigCodeSize);
							}
						}
						else
						{
							lReg = -1;
							printf("App Binary Size Exceed Limit[%d] size[%d] \n", FULLMEM_APP_BINARY_FULL_SIZE - CODE_SRAM_APP_RESERV_BYTE_SIZE, g_ulAppCodeSize);
						}

						free(pFullBinaryBuf);
					}
					else
					{
						lReg = -1;
						printf("Full binary buffer memory allocation error \n");
					}

					fclose(pFAppImgFile);
				}
				else
				{
					lReg = -1;
					printf("App Image file open error %s\n", pFAppImgfileName_);
				}

				fclose(pFAppConfigInfoBinFile);
			}
			else
			{
				lReg = -1;
				printf("bin file open error APP_INFO.bin\n");
			}

			if (pFConfigBinFile)
			{
				fclose(pFConfigBinFile);
			}
			if (pFConfigCompressedBinFile)
			{
				fclose(pFConfigCompressedBinFile);
			}
		}
		else
		{
			lReg = -1;
			printf("Config bin file open error %s\n", pfConfigBinFileName);
		}

		fclose(pFAppBinFile);
	}
	else
	{
		lReg = -1;
		printf("App bin file open error %s\n", pfAppBinFineName);
	}

	return lReg;
}

static int32_t Total_FullMem_Binary_Process(const char * pFTotalImgfileName_, const char * pFBootImgFileName, const char * pfAppBinFineName, const char * pfConfigBinFileName)
{
	int32_t lReg = 0;
	char * pcConfigCompressedFileName = NULL;
	FILE * pFBootImgFile = NULL;
	FILE * pFAppBinFile = NULL;
	FILE * pFConfigBinFile = NULL;
	FILE * pFConfigCompressedBinFile = NULL;
	FILE * pFAppConfigInfoBinFile = NULL;
	FILE * pFTotalImgFile = NULL;
	uint8_t * pFullBinaryBuf;
	uint8_t * pConfigBinaryBuf = NULL;
	uint8_t * pConfigCompressedBinaryBuf = NULL;
	char vcAppConfigInfoFilePath[32];
	tBootTailInfo_t * ptBootTailInfo;
	tAppConfigGenInfo_t tAppConfigGenInfo;
	tAppTailInfo_t tAppTailInfo;
	tConfigTailInfo_t tConfigTailInfo;
	uint32_t ulAppConfigInfoBinFileSize;

	if (pFTotalImgfileName_ == NULL || pFBootImgFileName == NULL || pfAppBinFineName == NULL)
	{
		printf("Input File Name Error!! \n");
		return -1;
	}

	/*
	 * Boot Img���� Open
	 */
	pFBootImgFile = fopen(pFBootImgFileName, "rb");
	if (pFBootImgFile)
	{
		/*
		 * App Bin���� Open
		 */
		pFAppBinFile = fopen(pfAppBinFineName, "rb");
		if (pFAppBinFile)
		{
			/*
			 * Config Bin���� Open (���� �� ���� ���� ���� ������ �������!!)
			 */
			if (pfConfigBinFileName)
			{
				pcConfigCompressedFileName = (char *)malloc(_MAX_PATH);
				memset(pcConfigCompressedFileName, 0, (_MAX_PATH));
				if(pcConfigCompressedFileName)
				{
					sprintf(pcConfigCompressedFileName, "%s.compressed", pfConfigBinFileName);
					pFConfigBinFile = fopen(pfConfigBinFileName, "rb");
					pFConfigCompressedBinFile = fopen(pcConfigCompressedFileName, "wb");
					free(pcConfigCompressedFileName);
				}
			}

			if ((pfConfigBinFileName == NULL) || (pfConfigBinFileName != NULL && pFConfigBinFile && pFConfigCompressedBinFile))
			{
				/*
				 * APP_INFO.bin ���� Open
				 */
				sprintf(&vcAppConfigInfoFilePath[0], "bin\\Binary\\APP_INFO.bin");
				pFAppConfigInfoBinFile = fopen(vcAppConfigInfoFilePath, "rb");
				if (pFAppConfigInfoBinFile)
				{
					/*
					 * ������ Image ���� Open
					 */
					pFTotalImgFile = fopen(pFTotalImgfileName_, "wb");
					if (pFTotalImgFile)
					{
						pFullBinaryBuf = (uint8_t *)malloc(TOTAL_BINARY_FULL_SIZE);
						if (pFullBinaryBuf)
						{
							memset(pFullBinaryBuf, 0xFF, TOTAL_BINARY_FULL_SIZE);
							/*
							 * Boot Bin ���� Size Check!!
							 */
							fseek(pFBootImgFile, 0, SEEK_END);
							g_ulBootCodeSize = ftell(pFBootImgFile);
							if (g_ulBootCodeSize == BOOT_BINARY_FULL_SIZE)
							{
								/*
								 * App Bin ���� Size Check!!
								 */
								fseek(pFAppBinFile, 0, SEEK_END);
								g_ulAppCodeSize = ftell(pFAppBinFile);
								if (g_ulAppCodeSize <= FULLMEM_APP_BINARY_FULL_SIZE - CODE_SRAM_APP_RESERV_BYTE_SIZE)
								{
									/*
									 * Config Bin �������� �� ��쿡�� Size Check!!
									 */
									g_ulConfigCodeSize = 0;
									g_ulConfigCompressedCodeSize = 0;
									if (pFConfigBinFile)
									{
										fseek(pFConfigBinFile, 0, SEEK_END);
										g_ulConfigCodeSize = ftell(pFConfigBinFile);
										pConfigBinaryBuf = (uint8_t *)malloc(g_ulConfigCodeSize);
										pConfigCompressedBinaryBuf = (uint8_t *)malloc((g_ulConfigCodeSize << 1));

										if(pConfigBinaryBuf && pConfigCompressedBinaryBuf)
										{
											fseek(pFConfigBinFile, 0, SEEK_SET);
											fread(&pConfigBinaryBuf[0], 1, g_ulConfigCodeSize, pFConfigBinFile);

											g_ulConfigCompressedCodeSize = LZ_Compress(&pConfigBinaryBuf[0], &pConfigCompressedBinaryBuf[0], g_ulConfigCodeSize);
										}
									}

									if ((pFConfigBinFile == NULL) ||
										(pFConfigBinFile && (g_ulConfigCompressedCodeSize > 0) && (g_ulConfigCompressedCodeSize <= (FULLMEM_CONFIG_BINARY_FULL_SIZE - CONFIG_LENGTH_SIZE))))
									{
										/*
										 * Bootloader Bin���� Size��ŭ Read�Ͽ� FullBinaryBuf�� ��´�.
										 */
										fseek(pFBootImgFile, 0, SEEK_SET);
										fread(&pFullBinaryBuf[0], 1, g_ulBootCodeSize, pFBootImgFile);
										/*
										 * Application Bin���� Size��ŭ Read�Ͽ� FullBinaryBuf�� ��´�.
										 */
										fseek(pFAppBinFile, 0, SEEK_SET);
										fread(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE], 1, g_ulAppCodeSize, pFAppBinFile);

										/*
										 * Bootloader Information Buffer���� Read
										 */
										ptBootTailInfo = (tBootTailInfo_t *)(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE - sizeof(tBootTailInfo_t)]);
										g_ulBootVersion = ptBootTailInfo->usBootVer;
										g_usBootMemSize = ptBootTailInfo->usBootMemSize;
										g_usBootVID = ptBootTailInfo->usBootVID;
										g_usBootPID = ptBootTailInfo->usBootPID;

										/*
										 * Application & Config Information Buffer�� Write
										 */
										fseek(pFAppConfigInfoBinFile, 0, SEEK_END);
										ulAppConfigInfoBinFileSize = ftell(pFAppConfigInfoBinFile);
										fseek(pFAppConfigInfoBinFile, 0, SEEK_SET);
										fread((uint8_t *)&tAppConfigGenInfo, 1, ulAppConfigInfoBinFileSize, pFAppConfigInfoBinFile);
										tAppTailInfo.usBootCompVer = tAppConfigGenInfo.usBootCompVer;
										tAppTailInfo.usConfigCompVer = tAppConfigGenInfo.usConfigVer;
										tAppTailInfo.usConfigMemSize = tAppConfigGenInfo.usConfigMemSize;
										g_ulAppVersion = tAppTailInfo.usAppVer = tAppConfigGenInfo.usAppVer;
										g_ulConfigVersion = tConfigTailInfo.usConfigVer = tAppConfigGenInfo.usConfigVer;
										g_usAppMemSize = tAppTailInfo.usAppMemSize = tAppConfigGenInfo.usAppMemSize;
										tAppTailInfo.usUsedConfigFile = tAppConfigGenInfo.usUsedConfigFile;
										g_usConfigMemSize = tConfigTailInfo.usConfigMemSize = tAppConfigGenInfo.usConfigMemSize;
										g_usAppVID = tAppTailInfo.usAppVID = tAppConfigGenInfo.usAppVID;
										g_usAppPID = tAppTailInfo.usAppPID = tAppConfigGenInfo.usAppPID;
										memcpy(&pFullBinaryBuf[(BOOT_BINARY_FULL_SIZE + FULLMEM_APP_BINARY_FULL_SIZE - CODE_SRAM_APP_RESERV_BYTE_SIZE) - sizeof(tAppTailInfo_t)], &tAppTailInfo, sizeof(tAppTailInfo_t));
										memcpy(&pFullBinaryBuf[TOTAL_BINARY_FULL_SIZE - sizeof(tConfigTailInfo_t)], &tConfigTailInfo, sizeof(tConfigTailInfo_t));

										if (pFConfigBinFile)
										{
											memcpy(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE + FULLMEM_APP_BINARY_FULL_SIZE], &g_ulConfigCompressedCodeSize, CONFIG_LENGTH_SIZE);									// length of compressed ConfigFixed
											memcpy(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE + FULLMEM_APP_BINARY_FULL_SIZE + CONFIG_LENGTH_SIZE], &pConfigCompressedBinaryBuf[0], g_ulConfigCompressedCodeSize);	// compressed ConfigFixed
										}
										else
										{
											memcpy(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE + FULLMEM_APP_BINARY_FULL_SIZE], &g_ulConfigCompressedCodeSize, CONFIG_LENGTH_SIZE);									// length of compressed ConfigFixed
										}

										/*
										 * CRC�� ��� �� Buffer�� Write
										 */
										g_ulBootCRCValue = ptBootTailInfo->usCRCValue;
										g_ulAppCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[BOOT_BINARY_FULL_SIZE]), FULLMEM_APP_BINARY_FULL_SIZE - CODE_SRAM_APP_RESERV_BYTE_SIZE - CRC_CODE_BYTE_SIZE);
										memcpy(&pFullBinaryBuf[(BOOT_BINARY_FULL_SIZE + FULLMEM_APP_BINARY_FULL_SIZE) - CODE_SRAM_APP_RESERV_BYTE_SIZE - CRC_CODE_BYTE_SIZE], &g_ulAppCRCValue, CRC_CODE_BYTE_SIZE);
										g_ulConfigCRCValue = GetCRCValue((const uint16_t *)(&pFullBinaryBuf[(BOOT_BINARY_FULL_SIZE + FULLMEM_APP_BINARY_FULL_SIZE)]), FULLMEM_CONFIG_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE);
										memcpy(&pFullBinaryBuf[TOTAL_BINARY_FULL_SIZE - CRC_CODE_BYTE_SIZE], &g_ulConfigCRCValue, CRC_CODE_BYTE_SIZE);

										/*
										 * BinaryBuf�� �ִ� ������ Img���Ͽ� ���!!
										 */
										fwrite(&pFullBinaryBuf[0], 1, TOTAL_BINARY_FULL_SIZE, pFTotalImgFile);
										if(pFConfigCompressedBinFile)
										{
											fseek(pFConfigCompressedBinFile, 0, SEEK_SET);
											fwrite(&pConfigCompressedBinaryBuf[0], 1, g_ulConfigCompressedCodeSize, pFConfigCompressedBinFile);
										}
									}
									else
									{
										lReg = -1;
										printf("Config Binary Size Exceed [%d] \n", g_ulConfigCodeSize);
									}

									if (pConfigBinaryBuf)
									{
										free(pConfigBinaryBuf);
									}
									if (pConfigCompressedBinaryBuf)
									{
										free(pConfigCompressedBinaryBuf);
									}
								}
								else
								{
									lReg = -1;
									printf("App Binary Size Exceed [%d] \n", g_ulAppCodeSize);
								}
							}
							else
							{
								lReg = -1;
								printf("boot Binary Size Exceed [%d] \n", g_ulBootCodeSize);
							}


							free(pFullBinaryBuf);
						}
						else
						{
							lReg = -1;
							printf("Full binary buffer memory allocation error \n");
						}

						fclose(pFTotalImgFile);
					}
					else
					{
						lReg = -1;
						printf("Total Image file open error %s\n", pFTotalImgfileName_);
					}

					fclose(pFAppConfigInfoBinFile);
				}
				else
				{
					lReg = -1;
					printf("bin file open error APP_INFO.bin\n");
				}

				if (pFConfigBinFile)
				{
					fclose(pFConfigBinFile);
				}
				if (pFConfigCompressedBinFile)
				{
					fclose(pFConfigCompressedBinFile);
				}
			}
			else
			{
				lReg = -1;
				printf("Config bin file open error %s\n", pfConfigBinFileName);
			}

			fclose(pFAppBinFile);
		}
		else
		{
			lReg = -1;
			printf("App bin file open error %s\n", pfAppBinFineName);
		}

		fclose(pFBootImgFile);
	}
	else
	{
		lReg = -1;
		printf("Boot img file open error %s\n", pFBootImgFileName);
	}

	return lReg;
}
