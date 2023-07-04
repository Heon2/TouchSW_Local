
/****************************************************************************************************//**
 * @file     flitf.h
 *
 * @brief    CMSIS Cortex-M3 Core Peripheral Access Layer Header File for
 *           default mtlp Device Series
 *
 * @version  Vrev.B
 * @date     19. April 2013
 *
 * @note     
 *
 * @par      ARM Limited (ARM) is supplying this software for use with Cortex-M
 *           processor based microcontroller, but can be equally used for other
 *           suitable processor architectures. This file can be freely distributed.
 *           Modifications to this file shall be clearly marked.
 *           
 *           THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *           OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *           MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *           ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *           CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. 
 *
 *******************************************************************************************************/



/* ================================================================================ */
/* ================                     FLITF                      ================ */
/* ================================================================================ */

/**
 * @Brief  FLITF Register Map
 */
#define FLITFCTRL_COMMAND_FLASH_NONE			(0x00)
#define FLITFCTRL_COMMAND_FLASH_PAGE_ERASE		(0x01)
#define FLITFCTRL_COMMAND_FLASH_MASS_ERASE		(0x02)
#define FLITFCTRL_COMMAND_FLASH_WRITE			(0x03)
#define FLITFCTRL_COMMAND_FLASH_READ			(0x04)
#define FLITFCTRL_COMMAND_FLASH_GET_VERIFY		(0x05)
#define FLITFCTRL_COMMAND_FLASH_ENTER_IAP_MODE	(0x06)
#define FLITFCTRL_COMMAND_FLASH_EXIT_IAP_MODE	(0x07)
#define FLITFCTRL_COMMAND_FLASH_4KB_UPDATE_MODE	(0x08)

#define FLASHCTRL_STATUS_NONE					(0x00)
#define FLASHCTRL_STATUS_SUCCESS				(0x01)
#define FLASHCTRL_STATUS_PAGE_ERASE_FAILED		(0x02)
#define FLASHCTRL_STATUS_PAGE_WRITE_FAILED		(0x03)
#define FLASHCTRL_STATUS_PAFE_READ_FAILED		(0x03)

extern void hal_flitf_init(void);
extern void hal_flitf_process(void);
extern void hal_flitf_another_process(void);
#if defined(USE_BOOTLOADER_16KB)
extern void FLASH_Write(uint32_t addr, uint32_t val);
extern uint32_t FLASH_Read(uint32_t addr);
#endif /* (USE_BOOTLOADER_16KB) */

typedef struct
{
	uint32_t addr;
	uint16_t size;
	volatile uint8_t status;
	volatile uint8_t cmd;
} __attribute__ ((packed)) tFlashIAPCmd_t;

typedef struct
{
	tFlashIAPCmd_t * Ctrl;
} tFlashIAPPacket_t;

extern tFlashIAPPacket_t tFlashIAPPacket;

#define FLASH_WRITE_SIZE	128
#define	DFUP_BUFFER_SIZE	4096
extern uint8_t DFUP_BUFFER[DFUP_BUFFER_SIZE];
typedef struct
{
	union
    {	
       uint32_t FACR;	
		
		struct {
			uint32_t LATENCY				:4;
            uint32_t RESERVED0			:28;
        } FACR_b ;
    };

	
	uint32_t FKEYR;                  // 0x0004 | FCR register write enable KEY1/KEY2
	uint32_t FOPTKEYR;               // 0x0008 | Reserved
	union 
    {	
       uint32_t FSR;                    // 0x000C | Status register      
		
		struct{
			uint32_t NVSTR         :1 ; //FSR[ 0]
			uint32_t RSVD3         :1 ; //FSR[ 1]
			uint32_t PGERR         :1 ; //FSR[ 2]
			uint32_t RSVD2         :1 ; //FSR[ 3]
			uint32_t RSVD1         :1 ; //FSR[ 4]
			uint32_t EOP           :1 ; //FSR[ 5]
			uint32_t INT_FLITF     :1 ; //FSR[ 6]
			uint32_t RSVD0         :1 ; //FSR[ 7]
			uint32_t key1_ok       :1 ; //FSR[ 8]
			uint32_t key2_ok       :1 ; //FSR[ 9]
			uint32_t optkey1_ok    :1 ; //FSR[10]
			uint32_t optkey2_ok    :1 ; //FSR[11]
			uint32_t ISP_MODE      :1 ; //FSR[12]
			uint32_t ISP_REGISTER  :1 ; //FSR[13]
			uint32_t AHBPATH_EN    :1 ; //FSR[14]
			uint32_t INFOBLK_LOAD  :1 ; //FSR[15]
			uint32_t STANDBY       :1 ; //FSR[16]
			uint32_t WFIC_EN       :1 ; //FSR[17]
			uint32_t OE            :1 ; //FSR[18]
			uint32_t CS            :1 ; //FSR[19]
			uint32_t fsm_wfirgset  :1 ; //FSR[20]
			uint32_t fsm_rdmd      :1 ; //FSR[21]
			uint32_t fsm_wrmd      :1 ; //FSR[22]
			uint32_t fsm_scer      :1 ; //FSR[23]
			uint32_t fsm_mcer      :1 ; //FSR[24]
			uint32_t fsm_wfic      :1 ; //FSR[25]
			uint32_t fsm_isp       :1 ; //FSR[26]
			uint32_t fsm_ifmd      :1 ; //FSR[27]
			uint32_t fsm_ifbrd     :1 ; //FSR[28]
			uint32_t fsm_idle      :1 ; //FSR[29]  
			uint32_t fsm_bist      :1 ; //FSR[30]
			uint32_t BIST_MODE     :1 ; //FSR[31] 
		} FSR_b ;
	};

	union 
    {		
		uint32_t FCR;                    // 0x0010 | Control register             
		struct{
			uint32_t PG               :1 ;//FCR[ 0]   program
			uint32_t PER              :1 ;//FCR[ 1]   page erase 
			uint32_t MER              :1 ;//FCR[ 2]   macro erase
			uint32_t READ_             :1 ;//FCR[ 3]   read operation
			uint32_t RSVD0            :2 ;//FCR[5:4]  
			uint32_t STRT             :1 ;//FCR[ 6]   operation start 
			uint32_t LOCK             :1 ;//FCR[ 7]   control register write lock : write '1' is only 
			uint32_t WFRGSET          :1 ;//FCR[ 8]   WFIC mode register setting mode 
			uint32_t WFIETEN          :1 ;//FCR[ 9]   WFIC mode Enter Enable
			uint32_t ERRIE            :1 ;//FCR[10]   error interrupt enable 
			uint32_t RSVD1            :1 ;//FCR[11]   
			uint32_t EOPIE            :1 ;//FCR[12]   end of operation interrupt enable
			uint32_t CS_TIE_LOW       :1 ;//FCR[13]   CS Tie Low
			uint32_t CS_SLP           :1 ;//FCR[14]   CS Controlled by SLEEP signal
			uint32_t FCR_CE_OPTEN     :1 ;//FCR[15]   CE option control enable (ONLY use in PT measuring cell current) 
			uint32_t FCR_CE_OPTVAL    :1 ;//FCR[16]   CE option control value (ONLY use in PT measuring cell current) 
			uint32_t PRFTEN_FCR       :1 ;//FCR[17]   
			uint32_t RSVD3            :4 ;//FCR[21:18]   
			uint32_t OTFLTPG_DIS      :1 ;//FCR[22]    On the fly latency programming disable
			uint32_t CACHE_EN_FCR     :1 ;//FCR[23]    Cache Enable !!! 
			uint32_t ALTRDEN_FCR      :1 ;//FCR[24]    Cache Enable !!! 
			uint32_t RSVD4            :5 ;//FCR[29:25]
			uint32_t IFMDCGEN         :1 ;//FCR[30]    Mode Change Enable, 0 (default) : Option Byte select, 1: r_FCR register select
			uint32_t NVSSEL           :1 ;//FCR[31]    NVSTR drive select, 0 : TBIT , 1 : Self Count 
		} FCR_b ;
	};
	
       uint32_t FAR;                    // 0x0014 | Address register 
	
	union 
    {				
		uint32_t FCR1;                   // 0x0018 | Control register1 
		struct{
			uint32_t FCR1_INF         :1 ;//FCR1[0]     INF signal value 
			uint32_t FCR1_SAVEN       :1 ;//FCR1[1]     SAVEN signal value 
			uint32_t FCR1_WRONLY      :1 ;//FCR1[2]     WRONLY signal value 
			uint32_t FCR1_PROG        :1 ;//FCR1[3]     PROG signal value 
			uint32_t FCR1_PERASE      :1 ;//FCR1[4]     PERASE signal value 
			uint32_t FCR1_SERASE      :1 ;//FCR1[5]     SERASE signal value 
			uint32_t FCR1_SAV_SRCSEL  :1 ;//FCR1[6]     SAV_SRCSEL signal value 
			uint32_t RSVD0            :1 ;//FCR1[7]   
			uint32_t FCR1_TM          :4 ;//FCR1[11:8]  TM signal value    
		} FCR1_b ;
	};
	
	union 
    {		
		uint32_t FCR2;                   // 0x001C | Control register2
		struct{
			uint32_t FCR2_PGM_BYTE_LEN:5 ;//FCR2[4:0]   Byte & Page program and Page write data length
			uint32_t RSVD0											:2; //FCR2[6:5]
			uint32_t FCR2_SFR_WREN    :1 ;//FCR2[5]     SFR or non SFR write selection                
		} FCR2_b ;
	};

		uint32_t Reserved0;              // 0x0020 | Reserved 
		uint32_t Reserved1;              // 0x0024 | Reserved
		uint32_t FWDRLW;                 // 0x0028 | Write Data Buffer Register0
		uint32_t FACR1;                  // 0x002C | Access Control Register1
		uint32_t FRDRLW;                 // 0x0030 | Read Data Buffer Register Low Word
		uint32_t Reserved3;              // 0x0034 | Reserved
		uint32_t PGERSR0;                // 0x0038 | Page Erase Status  Register 0 
		uint32_t PGERSR1;                // 0x003C | Page Erase Status  Register 1
		uint32_t PGERSR2;                // 0x0040 | Page Erase Status  Register 2 
		uint32_t PGERSR3;                // 0x0044 | Page Erase Status  Register 3 

	union 
    {		
		uint32_t ERRESPCR;               // 0x0048 | Error Response Control Register
		struct{
			uint32_t EN_KEY1:1 ;
			uint32_t EN_KEY2    :1 ;
			uint32_t EN_OPTKEY1    :1 ;
			uint32_t EN_OPTKEY2    :1 ;
			uint32_t EN_LOCK_WR0    :1 ;
			uint32_t RSVD0            :1 ;
			uint32_t EN_FAR_DW    :1 ;
			uint32_t EN_FRDRLW    :1 ;
		} ERRESPCR_b ;
	};

		uint32_t ISPMSCR;                // 0x004C | SW ISP Mode config register
		uint32_t EXTRASCR0;              // 0x0050 | Extra System Configuration 0 
		uint32_t EXTRASCR1;              // 0x0054 | Extra System Configuration 1 
		uint32_t EXTRASCR2;              // 0x0058 | Extra System Configuration 2 
		uint32_t EXTRASCR3;              // 0x005C | Extra System Configuration 3 
		uint32_t PROTECTION;             // 0x0060 | READ data protection
		uint32_t PGERSR4;                // 0x0064 | Page Erase Status  Register 4 
		uint32_t PGERSR5;                // 0x0068 | Page Erase Status  Register 5
		uint32_t PGERSR6;                // 0x006C | Page Erase Status  Register 6 
		uint32_t PGERSR7;                // 0x0070 | Page Erase Status  Register 7 
		uint32_t PGERSR8;                // 0x0074 | Page Erase Status  Register 8 
		uint32_t PGERSR9;                // 0x0078 | Page Erase Status  Register 9 
		uint32_t PGERSR10;               // 0x007C | Page Erase Status  Register 10 
		uint32_t IFBRD_TCNT_END;         // 0x0080 | Flash Control signal timing tuning register
		uint32_t MCER_TCNT_END;          // 0x0084 | Flash Control signal timing tuning register
		uint32_t SCER_TCNT_END;          // 0x0088 | Flash Control signal timing tuning register
		uint32_t WRMD_TCNT_END;          // 0x008C | Flash Control signal timing tuning register
		uint32_t RDMD_TCNT_END;          // 0x0090 | Flash Control signal timing tuning register
		uint32_t AE_IFBRD_STR;           // 0x0094 | Flash Control signal timing tuning register
		uint32_t AE_MCER_STR;            // 0x0098 | Flash Control signal timing tuning register
		uint32_t AE_SCER_STR;            // 0x009C | Flash Control signal timing tuning register
		uint32_t AE_WRMD_STR;            // 0x00A0 | Flash Control signal timing tuning register
		uint32_t AE_RDMD_STR;            // 0x00A4 | Flash Control signal timing tuning register
		uint32_t AE_IFBRD_END;           // 0x00A8 | Flash Control signal timing tuning register
		uint32_t AE_MCER_END;            // 0x00AC | Flash Control signal timing tuning register
		uint32_t AE_SCER_END;            // 0x00B0 | Flash Control signal timing tuning register
		uint32_t AE_WRMD_END;            // 0x00B4 | Flash Control signal timing tuning register
		uint32_t AE_RDMD_END;            // 0x00B8 | Flash Control signal timing tuning register
		uint32_t NVSTR_MCER_STR;         // 0x00BC | Flash Control signal timing tuning register
		uint32_t NVSTR_SCER_STR;         // 0x00C0 | Flash Control signal timing tuning register
		uint32_t NVSTR_WRMD_STR;         // 0x00C4 | Flash Control signal timing tuning register
		uint32_t NVSTR_MCER_LTH;         // 0x00C8 | Flash Control signal timing tuning register
		uint32_t NVSTR_SCER_LTH;         // 0x00CC | Flash Control signal timing tuning register
		uint32_t NVSTR_WRMD_LTH;         // 0x00D0 | Flash Control signal timing tuning register
		uint32_t DOUTVALID_IFBRD;        // 0x00D4 | Flash Control signal timing tuning register
		uint32_t DOUTVALID_RDMD;         // 0x00D8 | Flash Control signal timing tuning register
		uint32_t A17_WRMD_STR;           // 0x00DC | Flash Control signal timing tuning register
		uint32_t A17_WRMD_END;           // 0x00E0 | Flash Control signal timing tuning register
		uint32_t WFRGST_TCNT_END;        // 0x00E4 | Flash Control signal timing tuning register
		uint32_t DBGR;                   // 0x00E8 | Flash Debug register
	union 
    {
		uint32_t BCR;                    // 0x00EC | Flash BIST : Page Number
		struct{
			uint32_t RSVD0            :5 ;
			uint32_t NB_PG_NUM:10 ;
			uint32_t RSVD1            :6 ;
			uint32_t INFO_PG_NUM    :10 ;
		} BCR_b ;
	};
		uint32_t BWDRLW;                 // 0x00F0 | Flash BIST Data register
		uint32_t FSM_INIT;               // 0x00F4 | Reserved
	union 
    {	
		uint32_t BSCR;                   // 0x00F8 | Flash BIST Control register
		struct{
			uint32_t NERASE_EN            :1 ;
			uint32_t NERRD_EN:1 ;
			uint32_t NPG_EN            :1 ;
			uint32_t NPGRD_EN    :1 ;
			uint32_t IERASE_EN    :1 ;
			uint32_t IERRD_EN    :1 ;
			uint32_t IPG_EN    :1 ;
			uint32_t IPGRD_EN    :1 ;
			uint32_t SECTOR_NUM    :1 ;
		} BSCR_b ;
	};
		uint32_t DEVID;                  // 0x00FC | Device ID
		uint32_t FWDRLW01;               // 0x0100 | Write Data Buffer Register01
		uint32_t FWDRLW02;               // 0x0104 | Write Data Buffer Register02
		uint32_t FWDRLW03;               // 0x0108 | Write Data Buffer Register03
		uint32_t FWDRLW04;               // 0x010C | Write Data Buffer Register04
		uint32_t FWDRLW05;               // 0x0110 | Write Data Buffer Register05
		uint32_t FWDRLW06;               // 0x0114 | Write Data Buffer Register06
		uint32_t FWDRLW07;               // 0x0118 | Write Data Buffer Register07
		uint32_t FWDRLW08;               // 0x011C | Write Data Buffer Register08
		uint32_t FWDRLW09;               // 0x0120 | Write Data Buffer Register09
		uint32_t FWDRLW10;               // 0x0124 | Write Data Buffer Register10
		uint32_t FWDRLW11;               // 0x0128 | Write Data Buffer Register11
		uint32_t FWDRLW12;               // 0x012C | Write Data Buffer Register12
		uint32_t FWDRLW13;               // 0x0130 | Write Data Buffer Register13
		uint32_t FWDRLW14;               // 0x0134 | Write Data Buffer Register14
		uint32_t FWDRLW15;               // 0x0138 | Write Data Buffer Register15
		uint32_t FWDRLW16;               // 0x013C | Write Data Buffer Register16
		uint32_t FWDRLW17;               // 0x0140 | Write Data Buffer Register17
		uint32_t FWDRLW18;               // 0x0144 | Write Data Buffer Register18
		uint32_t FWDRLW19;               // 0x0148 | Write Data Buffer Register19
		uint32_t FWDRLW20;               // 0x014C | Write Data Buffer Register20
		uint32_t FWDRLW21;               // 0x0150 | Write Data Buffer Register21
		uint32_t FWDRLW22;               // 0x0154 | Write Data Buffer Register22
		uint32_t FWDRLW23;               // 0x0158 | Write Data Buffer Register23
		uint32_t FWDRLW24;               // 0x015C | Write Data Buffer Register24
		uint32_t FWDRLW25;               // 0x0160 | Write Data Buffer Register25
		uint32_t FWDRLW26;               // 0x0164 | Write Data Buffer Register26
		uint32_t FWDRLW27;               // 0x0168 | Write Data Buffer Register27
		uint32_t FWDRLW28;               // 0x016C | Write Data Buffer Register28
		uint32_t FWDRLW29;               // 0x0170 | Write Data Buffer Register29
		uint32_t FWDRLW30;               // 0x0174 | Write Data Buffer Register30
		uint32_t FWDRLW31;               // 0x0178 | Write Data Buffer Register31
		uint32_t PGERSR11;               // 0x017C | Page Erase Status  Register 11
		uint32_t PGERSR12;               // 0x0180 | Page Erase Status  Register 12
		uint32_t PGERSR13;               // 0x0184 | Page Erase Status  Register 13
		uint32_t PGERSR14;               // 0x0188 | Page Erase Status  Register 14
		uint32_t PGERSR15;               // 0x018C | Page Erase Status  Register 15
		uint32_t PGERSR16;               // 0x0190 | Page Erase Status  Register 16
		uint32_t PGERSR17;               // 0x0194 | Page Erase Status  Register 17
		uint32_t PGERSR18;               // 0x0198 | Page Erase Status  Register 18
		uint32_t PGERSR19;               // 0x019C | Page Erase Status  Register 19
		uint32_t PGERSR20;               // 0x01A0 | Page Erase Status  Register 20
		uint32_t PGERSR21;               // 0x01A4 | Page Erase Status  Register 21
		uint32_t PGERSR22;               // 0x01A8 | Page Erase Status  Register 22
		uint32_t PGERSR23;               // 0x01AC | Page Erase Status  Register 23
		uint32_t PGERSR24;               // 0x01B0 | Page Erase Status  Register 24
		uint32_t PGERSR25;               // 0x01B4 | Page Erase Status  Register 25
		uint32_t PGERSR26;               // 0x01B8 | Page Erase Status  Register 26
		uint32_t PGERSR27;               // 0x01BC | Page Erase Status  Register 27
		uint32_t PGERSR28;               // 0x01C0 | Page Erase Status  Register 28
		uint32_t PGERSR29;               // 0x01C4 | Page Erase Status  Register 29
		uint32_t PGERSR30;               // 0x01C8 | Page Erase Status  Register 30
		uint32_t PGERSR31;               // 0x01CC | Page Erase Status  Register 31
} FLITF_TypeDef ;

typedef struct
{

  union {
    __I  uint32_t  CALIB_OSC  ;       
    
    struct {
      __I  uint32_t  R_FINE   :  4;  
      __I  uint32_t  R_COARSE :  4;  
    } CALIB_OSC_b;                      
  } ;


  union {
    __I  uint32_t  CALIB_LDO ;       
    
    struct {
      __I  uint32_t  CAL_SEL :  4;  
    } CALIB_LDO_b;                      
  } ;


} INFO_TypeDef;

//ECCBOOT_v3.00 : CRC Info
typedef struct
{	
	uint32_t CRC_1;   
	uint32_t CRC_2;   
	
} BACKUP_CRC_TypeDef;

//ECCBOOT_v3.00 : Back-Up Info
typedef struct
{	
	union {
		uint32_t I2C_BOOT_INFO;

		struct {
			uint32_t	DUMMY			:  8;
			uint32_t	I2C_SADDR		:  8;
			uint32_t	BOOT_VERSION	:  16;
		} I2C_BOOT_INFO_b;
	};

	union {
		uint32_t VID_PID_INFO;

		struct {
			uint32_t	VID_INFO		:  16;
			uint32_t	PID_INFO		:  16;
		} VID_PID_INFO_b;
	};
	
} BACKUP_INFO_TypeDef;

//ECCBOOT_v3.00 : Back-Up Info Error
typedef struct
{	
	union {
		uint32_t BACKUP_INFO_ERROR;

		struct {
			uint32_t	I2C_INFO_ERROR		:  8;
			uint32_t	BOOT_VER_ERROR		:  8;
			uint32_t	VID_INFO_ERROR		:  8;
			uint32_t	PID_INFO_ERROR		:  8;
		} BACKUP_INFO_ERROR_b;
	};
	
} BACKUP_INFO_ERROR_TypeDef, *P_BACKUP_INFO_ERROR_TypeDef;
