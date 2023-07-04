/* Copyright (c) 2009 - 2016 SiliconWorks LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of SiW nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/

/*------------  Header Include -------------------------------------------------*/
#include "hal_def.h"
#include "protocol_def.h"
#include "module_def.h"
#include "misc.h"
#include "crc.h"
//#include "MFTP.h"
//#include "protocol.h"
//#include "protocol_log.h"
//#include "protocol_swip.h"
//#include "misc.h"
//#include "app_main.h"
//#include "module.h"
//#include "scrb.h" // 정의 추가 SCB_VECTKEY 가 정의 되어 있는곳

uint8_t DFUP_BUFFER[DFUP_BUFFER_SIZE];
uint8_t VERI_BUFFER[DFUP_BUFFER_SIZE];

#define FCR_PG				0x00000001
#define FCR_PER				0x00000002
#define FCR_MER				0x00000004
#define FCR_READ			0x00000008
#define FCR_START			0x00000040
#define FCR_LOCK			0x00000080
#define FCR_WFRGSET			0x00000100
#define FCR_WFIETEN			0x00000200
#define FCR_EOPIE			0x00001000
#define FSR_EOP				0x00000020
#define FSR_INT_FLITF		0x00000040
#define FSR_ISP_MODE		0x00001000
#define FSR_ISP_REGISTER	0x00002000
#define FSR_STANDBY			0x00010000
#define FSR_WFIC_EN			0x00020000
void FCR_UnLock(void)
{
  FLITF->FKEYR=0x76543210;
	udelay(10);
  FLITF->FKEYR=0xFEDCBA98;
//  printf("> FCR_LockRelease\n");
}

void Protection_UnLock(void)
{
			FLITF->FCR2=0;	
			FLITF->FCR2_b.FCR2_SFR_WREN=1;
			FLITF->FCR1=0;
			FLITF->FCR1_b.FCR1_TM=1;
			udelay(70);
			FLITF->NVSTR_WRMD_LTH=10;
			FLITF->FAR=12;
			FLITF->FWDRLW=0x0030027B;

			FLITF->FCR=0;
			FLITF->FCR_b.NVSSEL = 1;
			FLITF->FCR_b.PG=1;
			FLITF->FCR_b.STRT=1;
			while(FLITF->FSR_b.EOP==0)
			{
				udelay(10);
			}
			FLITF->FSR_b.EOP =1;
			udelay(50);
}
void Protection_UnLock_read(void)
{
			FLITF->DOUTVALID_RDMD =15;
			FLITF->RDMD_TCNT_END = 25;
			FLITF->FCR1=0;
			FLITF->FCR1_b.FCR1_TM=2;
			udelay(70);
			FLITF->FCR2 = 0;
			FLITF->FAR=12;
			FLITF->FCR=0;
			FLITF->FCR_b.READ_ = 1;
			FLITF->FCR_b.STRT=1;
			while(FLITF->FSR_b.EOP==0)
			{
				udelay(10);
			}
			FLITF->FSR_b.EOP =1;
			udelay(50);
}
void FLASH_PER(uint8_t TM, uint8_t INF, uint32_t adr)
{
//  printf("Page Erase = %x @ Address = %x\n", adr, adr);

  FLITF->FCR1=0x00000000l
          | TM<<8   // `FCR1_TM          
          | 1<<4    // `FCR1_PERASE          
          | INF<<0; // `FCR1_INF          
  FLITF->FAR=adr;
  FLITF->FCR=0x00000000 
          | 0<<31   //`FCR_NVSSEL 
          | 1<<12   //`FCR_EOPIE 
          | 1<<9    //`FCR_WFIETEN 
          | 1<<6    //`FCR_STRT 
          | 1<<1;   //`FCR_PER;
  __WFI();
  //__WFI_DEEP();   // not operation with FLITF interrupt
}


void FLASH_WR(uint8_t TM, uint8_t INF, uint8_t PROG, uint8_t WRONLY, 
              uint32_t str_adr, uint32_t end_adr, 
              uint32_t d0, uint32_t d1, uint32_t d2, uint32_t d3, uint32_t d4, 
              uint32_t d5, uint32_t d6, uint32_t d7, uint32_t d8, uint32_t d9, 
              uint32_t d10, uint32_t d11, uint32_t d12, uint32_t d13, uint32_t d14, 
              uint32_t d15, uint32_t d16, uint32_t d17, uint32_t d18, uint32_t d19, 
              uint32_t d20, uint32_t d21, uint32_t d22, uint32_t d23, uint32_t d24, 
              uint32_t d25, uint32_t d26, uint32_t d27, uint32_t d28, uint32_t d29, 
              uint32_t d30, uint32_t d31                                            )
{
//  printf("Program Word @ Address = %x\n", str_adr);
  
  FLITF->FCR1=0x00000000
          | TM<<8     // `FCR1_TM          
          | PROG<<3   // `FCR1_PROG          
          | WRONLY<<2 // `FCR1_WRONLY
          | INF<<0;   // `FCR1_INF          

  FLITF->FCR2     = (end_adr - str_adr)/4  ; 
  FLITF->FAR      = str_adr;
  
  FLITF->FWDRLW   = d0;
  FLITF->FWDRLW01 = d1;               
  FLITF->FWDRLW02 = d2;               
  FLITF->FWDRLW03 = d3;               
  FLITF->FWDRLW04 = d4;               
  FLITF->FWDRLW05 = d5;               
  FLITF->FWDRLW06 = d6;               
  FLITF->FWDRLW07 = d7;               
  FLITF->FWDRLW08 = d8;               
  FLITF->FWDRLW09 = d9;               
  FLITF->FWDRLW10 = d10;               
  FLITF->FWDRLW11 = d11;               
  FLITF->FWDRLW12 = d12;               
  FLITF->FWDRLW13 = d13;               
  FLITF->FWDRLW14 = d14;               
  FLITF->FWDRLW15 = d15;               
  FLITF->FWDRLW16 = d16;               
  FLITF->FWDRLW17 = d17;               
  FLITF->FWDRLW18 = d18;               
  FLITF->FWDRLW19 = d19;               
  FLITF->FWDRLW20 = d20;               
  FLITF->FWDRLW21 = d21;               
  FLITF->FWDRLW22 = d22;               
  FLITF->FWDRLW23 = d23;               
  FLITF->FWDRLW24 = d24;               
  FLITF->FWDRLW25 = d25;               
  FLITF->FWDRLW26 = d26;               
  FLITF->FWDRLW27 = d27;               
  FLITF->FWDRLW28 = d28;               
  FLITF->FWDRLW29 = d29;               
  FLITF->FWDRLW30 = d30;               
  FLITF->FWDRLW31 = d31;               

  FLITF->FCR=0x00000000 
          | 0<<31 //`FCR_NVSSEL 
          | 1<<12 //`FCR_EOPIE 
          | 1<<9  //`FCR_WFIETEN 
          | 1<<6  //`FCR_STRT 
          | 1<<0; //`FCR_PG;
  __WFI();
}

uint32_t FLASH_RD(uint32_t adr)
{
  uint32_t dat;

//  FLITF->FAR=adr; // (64th page)
//  FLITF->FCR=0x00000000 
//          | 1<<31 //`FCR_NVSSEL 
//          | 1<<12 //`FCR_EOPIE 
//          | 1<<9  //`FCR_WFIETEN 
//          | 1<<6  //`FCR_STRT 
//          | 1<<3; //`FCR_READ;
//  __WFI();
//  dat = HW_REG(adr);
//  printf("Read Word = %x @ Address = %x\n", dat, adr);

  return dat;
}

void FLASH_Write(uint32_t addr, uint32_t val)
{

	FLITF->ISPMSCR = SCB_VECTKEY | 0x00000001;
	while( (FLITF->ISPMSCR) == 0x00000000 );
	FCR_UnLock();
	while(FLITF->FCR_b.LOCK!=0) ;	
	Protection_UnLock();
	FLITF->FCR1 = 0x0;
	FLITF->FCR1_b.FCR1_PROG = 1;
	FLITF->FCR2 = 0;

	FLITF->FAR = addr;
	FLITF->FWDRLW = val;	

	FLITF->FCR=0x41;
	while(FLITF->FSR_b.EOP==0)
	{
		 udelay(10);
	}
	FLITF->FSR_b.EOP =1;
	udelay(10);			

	FLITF->ISPMSCR = SCB_VECTKEY | 0x00000000;
	udelay(5);
	while( (FLITF->ISPMSCR) != 0x00000000 );	
}

uint32_t FLASH_Read(uint32_t addr)
{	
	return (*(volatile uint32_t *)addr);
}


tFlashIAPPacket_t tFlashIAPPacket =
{
	.Ctrl = &(tFlashIAPCmd_t)
	{
		.cmd = 0x00,
		.status = 0x00,
	}
};
uint32_t hal_flitf_FlashRead(uint32_t addr, uint16_t sz, uint32_t *buf);
void hal_flitf_init(void)
{
	vtProtocolBufferPointers.pParameterBuffer = (void *)DFUP_BUFFER;
}
 uint32_t hal_flitf_ProgramPage (uint32_t addr, uint16_t sz, uint8_t *buf)
{
    return 0;
}
int count_flitf;
uint32_t hal_flitf_FlashWriteWord(uint32_t addr, uint32_t data)
{
	FLITF->FAR = addr;
	FLITF->FWDRLW = data;
FLITF->FCR=0x41;
	 while(FLITF->FSR_b.EOP==0)
	 {
		 udelay(10);
	 }
	FLITF->FSR_b.EOP =1;
	 udelay(10);
	return 0;
}

uint32_t hal_flitf_FlashWrite(uint32_t addr, uint32_t *buf)
{
	FLITF->FAR = addr;
	FLITF->FWDRLW 	= buf[0];
	FLITF->FWDRLW01 = buf[1];        
	FLITF->FWDRLW02 = buf[2];         
	FLITF->FWDRLW03 = buf[3]; 
	FLITF->FWDRLW04 = buf[4]; 
	FLITF->FWDRLW05 = buf[5]; 
	FLITF->FWDRLW06 = buf[6]; 
	FLITF->FWDRLW07 = buf[7];  
	FLITF->FWDRLW08 = buf[8]; 
	FLITF->FWDRLW09 = buf[9]; 
	FLITF->FWDRLW10 = buf[10];               
	FLITF->FWDRLW11 = buf[11];                
	FLITF->FWDRLW12 = buf[12];                
	FLITF->FWDRLW13 = buf[13];                
	FLITF->FWDRLW14 = buf[14];                
	FLITF->FWDRLW15 = buf[15]; 
	FLITF->FWDRLW16 = buf[16];                
	FLITF->FWDRLW17 = buf[17];                
	FLITF->FWDRLW18 = buf[18];                
	FLITF->FWDRLW19 = buf[19];                
	FLITF->FWDRLW20 = buf[20];                
	FLITF->FWDRLW21 = buf[21];                
	FLITF->FWDRLW22 = buf[22];               
	FLITF->FWDRLW23 = buf[23] ;               
	FLITF->FWDRLW24 = buf[24] ;               
	FLITF->FWDRLW25 = buf[25] ;               
	FLITF->FWDRLW26 = buf[26] ;               
	FLITF->FWDRLW27 = buf[27] ;               
	FLITF->FWDRLW28 = buf[28] ;               
	FLITF->FWDRLW29 = buf[29] ;               
	FLITF->FWDRLW30 = buf[30] ;               
	FLITF->FWDRLW31 = buf[31];        
	FLITF->FCR=0x41;
	while(FLITF->FSR_b.EOP==0)
	{
		udelay(10);
	}
	FLITF->FSR_b.EOP =1;
	udelay(10);		

    return 0;
}

uint32_t hal_flitf_FlashWrite_Verify(uint32_t addr, uint16_t sz, uint32_t *buf)
{
	uint32_t nRet = FLASHCTRL_STATUS_SUCCESS;
	int i;
	for( i=0; i<sz; i+=128 )
	{
		if( *(uint32_t *)(addr+i) != *(buf) )
		{
			nRet = FLASHCTRL_STATUS_PAGE_WRITE_FAILED;
		}
	}
    return nRet;
}

 void hal_flitf_another_process(void)
{
	uint32_t nRet = FLASHCTRL_STATUS_NONE;
	int i;
	eProtocolMode_t currMode;
	
	if(tFlashIAPPacket.Ctrl->cmd != FLITFCTRL_COMMAND_FLASH_NONE)
	{
		tFlashIAPCmd_t Curr;
		Curr = *tFlashIAPPacket.Ctrl;
		switch( Curr.cmd )
		{
			case FLITFCTRL_COMMAND_FLASH_PAGE_ERASE:
			{
				break;
			}
			case FLITFCTRL_COMMAND_FLASH_MASS_ERASE:
			{
				break;
			}
			case FLITFCTRL_COMMAND_FLASH_WRITE:
			{
				FLITF->ISPMSCR = SCB_VECTKEY | 0x00000001;
				while( (FLITF->ISPMSCR) == 0x00000000 );
				FCR_UnLock();
				while(FLITF->FCR_b.LOCK!=0)	;	
				Protection_UnLock();
				FLITF->FCR1 = 0x0;
				FLITF->FCR1_b.FCR1_PROG=1;
				FLITF->FCR2 = 31;
				for(i=0; i<Curr.size ;i+=FLASH_WRITE_SIZE) 
				{
					hal_flitf_FlashWrite(Curr.addr+i, (uint32_t*)&DFUP_BUFFER[i]);
				}
				FLITF->ISPMSCR = SCB_VECTKEY | 0x00000000;
				udelay(5);
				while( (FLITF->ISPMSCR) != 0x00000000 );
				break;
			}
			case FLITFCTRL_COMMAND_FLASH_GET_VERIFY:
			{
				memcpy(VERI_BUFFER, (void *)Curr.addr, Curr.size);
				
				static uint32_t crc_value_tool;
				static uint32_t crc_value_flash;
				
				crc_value_tool = *((uint32_t *)DFUP_BUFFER);
				
				crc_value_flash = (uint32_t)Crc16WordCalc((const uint16_t*)&VERI_BUFFER[0], Curr.size / 2, 0) | (Crc16WordCalc((const uint16_t*)&VERI_BUFFER[2], Curr.size / 2, 0) << 16);
				crc_value_flash = crc_value_flash ^ 0xFFFFFFFF;
				
				if(crc_value_tool == crc_value_flash)
					nRet = FLASHCTRL_STATUS_SUCCESS;
				else
					nRet = FLASHCTRL_STATUS_NONE;
				
				break;
			}
			case FLITFCTRL_COMMAND_FLASH_READ:
			{
				memcpy(DFUP_BUFFER, (void *)Curr.addr, Curr.size);
				nRet = FLASHCTRL_STATUS_SUCCESS;
				break;
			}
			case FLITFCTRL_COMMAND_FLASH_ENTER_IAP_MODE:
			{
				nRet = FLASHCTRL_STATUS_SUCCESS;
				break;
			}
			case FLITFCTRL_COMMAND_FLASH_EXIT_IAP_MODE:
			{
				nRet = FLASHCTRL_STATUS_SUCCESS;
				break;
			}
			case FLITFCTRL_COMMAND_FLASH_4KB_UPDATE_MODE:
			{
				nRet = FLASHCTRL_STATUS_SUCCESS;
				break;
			}
			default:
				break;
		}
		tFlashIAPPacket.Ctrl->cmd = FLITFCTRL_COMMAND_FLASH_NONE;
		tFlashIAPPacket.Ctrl->status = nRet;
		protocol_dfup_PendReadyStatus();
	}

	currMode = protocol_swip_GetMode();
	if( currMode == M_WATCH_DOG_RESET )
	{
//#ifdef MODE_WDT
		module_Watch_Enable();
		while(1);
//#endif
	}
}

