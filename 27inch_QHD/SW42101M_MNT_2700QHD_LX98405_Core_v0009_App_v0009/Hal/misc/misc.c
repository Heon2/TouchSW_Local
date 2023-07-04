
/********************************************************************************************
 * @file    : misc.c
 * @author  : 
 * @version : mtop
 * @date    : 12/27/2013
 * @brief   : This file contains the miscellous fuction 
 ********************************************************************************************
 * @copy
 *	This confidential and proprietary intellectual property may be used only as
 *	authorised by a licensing agreement from LG Display Co., Ltd. 
 *
 *
 *	    The entire notice above must be reproduced on all authorised 
 *	    copies and copies may only be made to the extent permitted 
 *	    by a licensing agreement from LG Display Co., Ltd. 
 *
 * <h2><center>&copy; (C) COPYRIGHT 2011 LG Display Co., Ltd. ALL RIGHTS RESERVED </center></h2>
 */

#include "hal_def.h"


#if defined(USE_BOOTLOADER_8KB)
	#define	VECTOR_BASE	0x00002000
#elif defined(USE_BOOTLOADER_16KB)
	#define	VECTOR_BASE	0x00004000
#else
	#define	VECTOR_BASE	0x00000000
#endif

#define VECTOR_SIZE	(16+14) 

 __IO uint32_t vectorTable[VECTOR_SIZE] __attribute__ ((aligned(128)));

void udelay (uint32_t usec)
{
	int count = 0;
	int utime = usec;
	do {
		if ( ++count > utime )
		{
			return ;
		}
	} while (1);
}
/**
  * @brief  Sets the vector table location and Offset.
  * @param  NVIC_VectTab: specifies if the vector table is in RAM or FLASH memory.
  *   This parameter can be one of the following values:
  *     @arg NVIC_VectTab_RAM
  *     @arg NVIC_VectTab_FLASH
  * @param  Offset: Vector Table base offset field. This value must be a multiple of 0x100.
  * @retval None
  */
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset)
{ 
	SCB->VTOR = NVIC_VectTab | (Offset & (uint32_t)0x1FFFFF80);
}

void ReMapVectorTableToRam(void)
{
	int i;
	for(i = 0; i < VECTOR_SIZE; i++)
	{
		vectorTable[i] = *(__IO uint32_t*)(VECTOR_BASE + (i<<2));
	}

	SCB->VTOR = (uint32_t)vectorTable;
}
