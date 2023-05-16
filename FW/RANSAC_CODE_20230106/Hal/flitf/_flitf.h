/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _flitf.h
 * created on : 10. 05. 2019
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


/* ================================================================================ */
/* ================                     FLITF                      ================ */
/* ================================================================================ */

#ifndef __FLITF_H_
#define __FLITF_H_


typedef union
{
    struct {
	    unsigned	LATENCY:					4;
        unsigned	Reserved:					28;
    } tBit;
    __IO uint32_t ulBulk;
} t_FACR;

typedef union
{
    struct {
	    unsigned	RBB:						1;
	    unsigned	Reserved0:                  1;
	    unsigned	PGERR:                      1;
	    unsigned	Reserved1:                  1;
	    unsigned	Reserved2:                  1;
	    unsigned	EOP:                        1;
	    unsigned	INT_FLITF:                  1;
	    unsigned	Reserved3:                  1;
	    unsigned	KEY1_OK:                    1;
	    unsigned	KEY2_OK:                    1;
	    unsigned	Reserved4:                  1;
	    unsigned	Reserved5:                  1;
	    unsigned	ISP_MODE:                   1;
	    unsigned	ISP_REGISTER:               1;
	    unsigned	AHBPATH_EN:                 1;
	    unsigned	Reserved6:                  1;
	    unsigned	STANDBY:                    1;
	    unsigned	WFIC_EN:                    1;
	    unsigned	Reserved7:                  1;
	    unsigned	CE:                         1;
	    unsigned	fsm_wfirgset:               1;
	    unsigned	fsm_rdmd:                   1;
	    unsigned	fsm_wrmd:                   1;
	    unsigned	fsm_scer:                   1;
	    unsigned	fsm_mcer:                   1;
	    unsigned	fsm_wfic:                   1;
	    unsigned	fsm_isp:                    1;
	    unsigned	fsm_ifmd:                   1;
	    unsigned	fsm_ifbrd:                  1;
	    unsigned	fsm_idle:                   1;
	    unsigned	fsm_bist:                   1;
	    unsigned	BIST_MODE:                  1;
    } tBit;
    __IO uint32_t ulBulk;
} t_FSR;

typedef union
{
    struct {
	    unsigned	PG:                         1;
	    unsigned	PER:                        1;
	    unsigned	MER:                        1;
	    unsigned	READ:                       1;
	    unsigned	Reserved0:                  1;
	    unsigned	Reserved1:                  1;
	    unsigned	STRT:                       1;
	    unsigned	LOCK:                       1;
	    unsigned	WFRGSET:                    1;
	    unsigned	WFIETEN:                    1;
	    unsigned	ERRIE:                      1;
	    unsigned	Reserved2:                  1;
	    unsigned	EOPIE:                      1;
	    unsigned	CE_TIE_LOW:                 1;
	    unsigned	CE_SLP:                     1;
	    unsigned	CE_OPTEN:                   1;
	    unsigned	CE_OPTVAL:                  1;
	    unsigned	Reserved3:                  5;
	    unsigned	OTFLPG_DIS:                 1;
	    unsigned	Reserved4:                  8;
	    unsigned	NVSTRSEL:                   1;
    } tBit;
    __IO uint32_t ulBulk;
} t_FCR;

typedef union
{
    struct {
	    unsigned	Address:                    18;
        unsigned	Reserved:					14;
    } tBit;
    __IO uint32_t ulBulk;
} t_FAR;

typedef union
{
    struct {
	    unsigned	INF:                        1;
	    unsigned	SAVEN:                      1;
	    unsigned	WRONLY:                     1;
	    unsigned	PROG:                       1;
	    unsigned	PERASE:                     1;
	    unsigned	SERASE:                     1;
	    unsigned	SAV_SRCSEL:                 1;
	    unsigned	Reserved0:                  1;
	    unsigned	TM:                         4;
        unsigned	Reserved1:					20;
    } tBit;
    __IO uint32_t ulBulk;
} t_FCR1;

typedef union
{
    struct {
	    unsigned	PGM_BYTE_LEN:               5;
	    unsigned	Reserved0:                  2;
	    unsigned	SFR_WREN:                   1;
        unsigned	Reserved1:					24;
    } tBit;
    __IO uint32_t ulBulk;
} t_FCR2;

typedef union
{
    struct {
	    unsigned	FCELL_TEST_EN:              1;
	    unsigned	Reserved:                   31;
    } tBit;
    __IO uint32_t ulBulk;
} t_ANASWCR;

typedef union
{
    struct {
	    unsigned	LT_MD:                      1;
	    unsigned	Reserved:                   31;
    } tBit;
    __IO uint32_t ulBulk;
} t_FACR1;

typedef union
{
    struct {
	    unsigned	EN_KEY1_ERR:				1;
	    unsigned	EN_KEY2_ERR:                1;
	    unsigned	Reserved0:                  1;
	    unsigned	Reserved1:                  1;
	    unsigned	EN_LOCK_WR0_ERR:            1;
	    unsigned	Reserved:                   1;
	    unsigned	EN_FAR_DW_ERR:              1;
	    unsigned	EN_FRDRLW_WR_ERR:           1;
	    unsigned	Reserved2:                  24;
    } tBit;
    __IO uint32_t ulBulk;
} t_ERRESPCR;

typedef union
{
    struct {
    	unsigned	ISP_REGISTER:               1;
    	unsigned	Reserved:                   31;
    } tBit;
    __IO uint32_t ulBulk;
} t_ISPMSCR;

typedef union
{
    struct {
	    unsigned	IFBRD_TCNT_END:				10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_IFBRD_TCNT_END;

typedef union
{
    struct {
	    unsigned	MCER_TCNT_END:              10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_MCER_TCNT_END;

typedef union
{
    struct {
	    unsigned	SCER_TCNT_END:              10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_SCER_TCNT_END;

typedef union
{
    struct {
	    unsigned	WRMD_TCNT_END:              10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_WRMD_TCNT_END;

typedef union
{
    struct {
	    unsigned	RDMD_TCNT_END:              10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_RDMD_TCNT_END;

typedef union
{
    struct {
	    unsigned	AE_MCER_STR:                10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_AE_MCER_STR;

typedef union
{
    struct {
	    unsigned	AE_SCER_STR:                10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_AE_SCER_STR;

typedef union
{
    struct {
	    unsigned	AE_WRMD_STR:                10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_AE_WRMD_STR;

typedef union
{
    struct {
	    unsigned	AE_RDMD_STR:                10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_AE_RDMD_STR;

typedef union
{
    struct {
	    unsigned	AE_MCER_END:                10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_AE_MCER_END;

typedef union
{
    struct {
	    unsigned	AE_SCER_END:                10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_AE_SCER_END;

typedef union
{
    struct {
	    unsigned	AE_WRMD_END:                10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_AE_WRMD_END;

typedef union
{
    struct {
	    unsigned	AE_RDMD_END:                10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_AE_RDMD_END;

typedef union
{
    struct {
	    unsigned	NVSTR_MCER_STR:             10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_NVSTR_MCER_STR;

typedef union
{
    struct {
	    unsigned	NVSTR_SCER_STR:             10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_NVSTR_SCER_STR;

typedef union
{
    struct {
	    unsigned	NVSTR_WRMD_STR:             10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_NVSTR_WRMD_STR;

typedef union
{
    struct {
	    unsigned	NVSTR_MCER_LTH:             12;
	    unsigned	Reserved:                   20;
    } tBit;
    __IO uint32_t ulBulk;
} t_NVSTR_MCER_LTH;

typedef union
{
    struct {
	    unsigned	NVSTR_SCER_LTH:             12;
	    unsigned	Reserved:                   20;
    } tBit;
    __IO uint32_t ulBulk;
} t_NVSTR_SCER_LTH;

typedef union
{
    struct {
	    unsigned	NVSTR_WRMD_LTH:             12;
	    unsigned	Reserved:                   20;
    } tBit;
    __IO uint32_t ulBulk;
} t_NVSTR_WRMD_LTH;

typedef union
{
    struct {
	    unsigned	DOUTVALID_RDMD:             10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_DOUTVALID_RDMD;

typedef union
{
    struct {
	    unsigned	WFRGSET_TCNT_END:           10;
	    unsigned	Reserved:                   22;
    } tBit;
    __IO uint32_t ulBulk;
} t_WFRGSET_TCNT_END;

typedef union
{
    struct {
	    unsigned	FSMDBG0:                    1;
	    unsigned	FSMDBG1:                    1;
	    unsigned	Reserved:                   30;
    } tBit;
    __IO uint32_t ulBulk;
} t_DBGR;

typedef union
{
    struct {
	    unsigned	Reserved0:                  7;
	    unsigned	NB_PAGE_NUM:                8;
	    unsigned	Reserved1:                  1;
	    unsigned	Reserved2:                  5;
	    unsigned	INFO_PAGE_NUM:              10;
	    unsigned	Reserved3:                  1;
    } tBit;
    __IO uint32_t ulBulk;
} t_BCR;

typedef union
{
    struct {
	    unsigned	FSM_INIT:                   1;
	    unsigned	Reserved:                   31;
    } tBit;
    __IO uint32_t ulBulk;
} t_FSM_INIT;

typedef union
{
    struct {
	    unsigned	NERASE_EN:                  1;
	    unsigned	NERRD_EN:                   1;
	    unsigned	NPG_EN:                     1;
	    unsigned	NPGRD_EN:                   1;
	    unsigned	IERASE_EN:                  1;
	    unsigned	IERRD_EN:                   1;
	    unsigned	IPG_EN:                     1;
	    unsigned	IPGRD_EN:                   1;
	    unsigned	SECTOR_NUM:                 4;
	    unsigned	Reserved:                   20;
    } tBit;
    __IO uint32_t ulBulk;
} t_BSCR;

typedef union
{
    struct {
	    unsigned	DEVICE_ID:                  24;
	    unsigned	Reserved:                   8;
    } tBit;
    __IO uint32_t ulBulk;
} t_DEVID;

typedef union
{
    struct {
	    unsigned	POR:                        1;
	    unsigned	ECC_EN:                     1;
        unsigned	reserved:					30;
    } tBit;
    __IO uint32_t ulBulk;
} t_FUSRCTRL;

typedef union
{
    struct {
	    unsigned	PAT_OUT:                    1;
	    unsigned	UNKNOWN_ERR:                1;
	    unsigned	ECC_FLAG:                   1;
        unsigned	reserved:					24;
    } tBit;
    __I uint32_t ulBulk;
} t_FECCST;


typedef struct
{
	__IO t_FACR 				FACR;
	__IO uint32_t 				FKEYR;
	__IO uint32_t 				FOPTKEYR;
	__IO t_FSR 					FSR;
	__IO t_FCR 					FCR;
	__IO t_FAR 					FAR;
	__IO t_FCR1 				FCR1;
	__IO t_FCR2 				FCR2;
	__IO uint32_t 				FLASH_RESERVED0;
	__IO t_ANASWCR 				ANASWCR;
	__IO uint32_t 				FWDRLW;
	__IO t_FACR1 				FACR1;
	__I	 uint32_t 				FRDRLW;
	__IO uint32_t 				FLASH_RESERVED1;
	__I  uint32_t 				PGERSR0;
	__I  uint32_t 				PGERSR1;
	__I  uint32_t 				PGERSR2;
	__I  uint32_t 				PGERSR3;
	__IO t_ERRESPCR 			ERRESPCR;
	__IO t_ISPMSCR 				ISPMSCR;
	__IO uint32_t 				FLASH_RESERVED2;
	__IO uint32_t 				FLASH_RESERVED3;
	__IO uint32_t 				FLASH_RESERVED4;
	__IO uint32_t 				FLASH_RESERVED5;
	__IO uint32_t 				PROTECTION;
	__I  uint32_t 				PGERSR4;
	__I  uint32_t 				PGERSR5;
	__I  uint32_t 				PGERSR6;
	__I  uint32_t 				PGERSR7;
	__I  uint32_t 				PGERSR8;
	__I  uint32_t 				PGERSR9;
	__I  uint32_t 				PGERSR10;
	__IO t_IFBRD_TCNT_END 		IFBRD_TCNT_END;
	__IO t_MCER_TCNT_END 		MCER_TCNT_END;
	__IO t_SCER_TCNT_END 		SCER_TCNT_END;
	__IO t_WRMD_TCNT_END 		WRMD_TCNT_END;
	__IO t_RDMD_TCNT_END 		RDMD_TCNT_END;
	__IO uint32_t 				FLASH_RESERVED6;
	__IO t_AE_MCER_STR 			AE_MCER_STR;
	__IO t_AE_SCER_STR 			AE_SCER_STR;
	__IO t_AE_WRMD_STR 			AE_WRMD_STR;
	__IO t_AE_RDMD_STR 			AE_RDMD_STR;
	__IO uint32_t 				FLASH_RESERVED7;
	__IO t_AE_MCER_END 			AE_MCER_END;
	__IO t_AE_SCER_END 			AE_SCER_END;
	__IO t_AE_WRMD_END 			AE_WRMD_END;
	__IO t_AE_RDMD_END 			AE_RDMD_END;
	__IO t_NVSTR_MCER_STR 		NVSTR_MCER_STR;
	__IO t_NVSTR_SCER_STR 		NVSTR_SCER_STR;
	__IO t_NVSTR_WRMD_STR 		NVSTR_WRMD_STR;
	__IO t_NVSTR_MCER_LTH 		NVSTR_MCER_LTH;
	__IO t_NVSTR_SCER_LTH 		NVSTR_SCER_LTH;
	__IO t_NVSTR_WRMD_LTH 		NVSTR_WRMD_LTH;
	__IO uint32_t 				FLASH_RESERVED8;
	__IO t_DOUTVALID_RDMD 		DOUTVALID_RDMD;
	__IO uint32_t 				FLASH_RESERVED9;
	__IO uint32_t 				FLASH_RESERVED10;
	__IO t_WFRGSET_TCNT_END 	WFRGSET_TCNT_END;
	__IO t_DBGR 				DBGR;
	__IO t_BCR 					BCR;
	__IO uint32_t 				BWDRLW;
	__IO t_FSM_INIT 			FSM_INIT;
	__IO t_BSCR 				BSCR;
	__IO t_DEVID 				DEVID;
	__IO uint32_t 				FWDRLW01;
	__IO uint32_t 				FWDRLW02;
	__IO uint32_t 				FWDRLW03;
	__IO uint32_t 				FWDRLW04;
	__IO uint32_t 				FWDRLW05;
	__IO uint32_t 				FWDRLW06;
	__IO uint32_t 				FWDRLW07;
	__IO uint32_t 				FWDRLW08;
	__IO uint32_t 				FWDRLW09;
	__IO uint32_t 				FWDRLW10;
	__IO uint32_t 				FWDRLW11;
	__IO uint32_t 				FWDRLW12;
	__IO uint32_t 				FWDRLW13;
	__IO uint32_t 				FWDRLW14;
	__IO uint32_t 				FWDRLW15;
	__IO uint32_t 				FWDRLW16;
	__IO uint32_t 				FWDRLW17;
	__IO uint32_t 				FWDRLW18;
	__IO uint32_t 				FWDRLW19;
	__IO uint32_t 				FWDRLW20;
	__IO uint32_t 				FWDRLW21;
	__IO uint32_t 				FWDRLW22;
	__IO uint32_t 				FWDRLW23;
	__IO uint32_t 				FWDRLW24;
	__IO uint32_t 				FWDRLW25;
	__IO uint32_t 				FWDRLW26;
	__IO uint32_t 				FWDRLW27;
	__IO uint32_t 				FWDRLW28;
	__IO uint32_t 				FWDRLW29;
	__IO uint32_t 				FWDRLW30;
	__IO uint32_t 				FWDRLW31;
	__I  uint32_t 				PGERSR11;
	__I  uint32_t 				PGERSR12;
	__I  uint32_t 				PGERSR13;
	__I  uint32_t 				PGERSR14;
	__I  uint32_t 				PGERSR15;
	__I  uint32_t 				PGERSR16;
	__I  uint32_t 				PGERSR17;
	__I  uint32_t 				PGERSR18;
	__I  uint32_t 				PGERSR19;
	__I  uint32_t 				PGERSR20;
	__I  uint32_t 				PGERSR21;
	__I  uint32_t 				PGERSR22;
	__I  uint32_t 				PGERSR23;
	__I  uint32_t 				PGERSR24;
	__I  uint32_t 				PGERSR25;
	__I  uint32_t 				PGERSR26;
	__I  uint32_t 				PGERSR27;
	__I  uint32_t 				PGERSR28;
	__I  uint32_t 				PGERSR29;
	__I  uint32_t 				PGERSR30;
	__I  uint32_t 				PGERSR31;
	__IO t_FUSRCTRL 			FUSRCTRL;
	__I  uint32_t 				FECCPIN;
	__I  t_FECCST 				FECCST;
	__O  uint32_t 				FECCCNTCLR;
} tFLASH_CtrlReg_t;

#endif
