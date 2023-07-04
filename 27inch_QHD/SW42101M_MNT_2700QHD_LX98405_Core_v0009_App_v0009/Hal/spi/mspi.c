/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : mspi.c
 * created on : 17. 4. 2017
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

#include "hal_def.h"
#include "module_def.h"


#if 0
#define MSPI_		(MSPI)
#else
MSPI_TypeDef * pTestMSPI = MSPI;
#define MSPI_		(pTestMSPI) // For Debugging
#endif

#if USED_ESD_RECOVERY_CODE
extern uint8_t FSM_ON_FLAG;
extern uint8_t MUX_COUNT_ERROR;
#endif /* USED_ESD_RECOVERY_CODE */

//#define SRIC_ACCESS_REG_NUM		50
extern __IO uint16_t sensingRowStart;
extern volatile uint8_t IDLE_FLAG;
volatile uint8_t HOPP_FLAG = FALSE;
extern void SRIC_Stop(void);
__IO uint32_t gFrameCnt;

void MSPI_InterruptHandler(void)
{
	__IO static int nextMSPISize;
	const tHalPwmdrvCommonConf_t * pktHalPwmdrvCommonConf = hal_pwmdrv_GetCommonConfig();

#if ((!USED_FINGER_ONLY) || USED_PEN_MODE_OPERATION)
//	static uint8_t f_LastLHB;
#endif /* ((!USED_FINGER_ONLY) || USED_PEN_MODE_OPERATION) */

	if ((MSPI_->SPIMODE & 0x1) != 0)
	{
		//AIT Mode
		if ((MSPI_->SINTRMSSR & 0x40) != 0)
		{
			//AIT Mode 1
			MSPI_->SINTRMSCR = INTR_MEM_ENA;
			MSPI_->SINTRENCR = 0x1;

#if USED_ESD_RECOVERY_CODE
			if(FSM_ON_FLAG == NO) 
			{
				MUX_COUNT_ERROR = YES;
			}
#endif /* USED_ESD_RECOVERY_CODE */			
			
			switch(HAL_GetSensingMode())
			{
#if ((!USED_FINGER_ONLY) || USED_PEN_MODE_OPERATION)
				case SM_FINGER_PEN_ACTIVE_MODE:
				case SM_FINGER_PEN_IDLE_MODE:
				case SM_FINGER_PEN_HOVER_ACTIVE_MODE:
				case SM_FINGER_PEN_HOVER_IDLE_MODE:
				{
					gMspiCounterPen = gMspiCounterPen + 1;

//					sensingRowStart = 0;

					// test
					if (gMspiCounterPen > 14)
					{
						gMspiCounterPen = 0;
//						bIsRefInitDone = 1;
//						f_LastLHB = 1;
					}
					nextMSPISize = gMspiCounterPen;
//					dbgsensingRowStart = sensingRowStart;
					switch (nextMSPISize)
					{
						// Finger �씪寃쎌슦 LFD瑜� �빐以섏빞�븯湲� �븣臾몄뿉 �븳 LHB�쟾�뿉 Pen DC �꽭�똿�쓣 0�쑝濡� 蹂�寃� (0:LFD on / 1:LFD off)
						case 2:		// 3LHB
						case 6:		// 7LHB
						case 8:		// 9LHB
						case 9:		// 10LHB
						case 10:	// 11LHB
						case 14:	// 15LHB
//							HAL_SetLocalIndex(0, 0);
							HAL_SetLocalIndex(sensingRowStart, 0);
							break;

						default:
//							HAL_SetLocalIndex(0, 1);
							HAL_SetLocalIndex(sensingRowStart, 1);
							break;
					}
					MSPI_Set_BUFSIZE_FingerPenMode(nextMSPISize);

					callPendSV();
					break;
				}
#endif /* (!USED_FINGER_ONLY) */
#if USED_LPWG_MODE_CONTROL
				case SM_FINGER_ONLY_LPWG_MODE:
#endif /* USED_LPWG_MODE_CONTROL */
				case SM_FINGER_ONLY_ACTIVE_FRQ_MAIN_MODE:
				case SM_FINGER_ONLY_ACTIVE_FRQ_HOP1_MODE:
				case SM_FINGER_ONLY_ACTIVE_FRQ_HOP2_MODE:
				case SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_MAIN_MODE:
				case SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_HOP1_MODE:
				case SM_FINGER_PEN_SEARCH_ACTIVE_FRQ_HOP2_MODE:
				{
#if (!USED_FINGER_ONLY)
					MSPI_Set_BUFSIZE_FingerMode(gFrameCnt);
#endif /* (!USED_FINGER_ONLY) */
//					F_GPB11();
//					GPIO->tGPIO_DATA_1._GPIO_TOGGLE = 1;
//					GPIO->tGPIO_DATA_1._GPIO_TOGGLE = 0;
					
					hal_set_irq_flag(IRQ_ID_FULL_SAMPLE);
					break;
				}
				case SM_FINGER_ONLY_IDLE_MODE:
				case SM_FINGER_PEN_SEARCH_IDLE_MODE:
				{
#if USED_FRAME_SKIP_IDLE_MODE_CONTROL
					hal_set_irq_flag(IRQ_ID_FULL_SAMPLE);
#else /* USED_FRAME_SKIP_IDLE_MODE_CONTROL */
//					F_GPB11();
					hal_set_irq_flag(IRQ_ID_FULL_SAMPLE_NI);
#endif /* USED_FRAME_SKIP_IDLE_MODE_CONTROL */
					break;
				}
				case SM_S3_ACTIVE_MODE:
				case SM_S3_IDLE_MODE:
#if (!USED_FINGER_ONLY)
					MSPI_Set_BUFSIZE_FingerMode(gFrameCnt);
#endif /* (!USED_FINGER_ONLY) */
					hal_set_irq_flag(IRQ_ID_FULL_SAMPLE);
					break;
				default:
					break;
			}
			MSPI->SPISTART = 0x03f/*All SPIs Command*/;
		}

//#if ((!USED_FINGER_ONLY) || USED_PEN_MODE_OPERATION)
//		sensingMode = getSensingMode();
//		// FingerPen - > Finger 紐⑤뱶�쟾�솚
//		if (gMspiCounterPen == (TSYNC_LHB - 2))
//		{
//			if ((sensingMode & _SETTING_MODE_MASK_)== SET_SM_FINGER_MODE)
//			{
////					MSPI_CommandWrite( MSPI_AUX_WRITE, MSPI_FINGER_MODE, LOCAL_0TH_POSITION);
//				setSensingMode(SM_MSPI_SET_MODE);
//			}
//		}
//#endif /* ((!USED_FINGER_ONLY) || USED_PEN_MODE_OPERATION)*/

#if ((!USED_FINGER_ONLY) || USED_PEN_MODE_OPERATION)
		if ((MSPI->SINTRMSSR & 0x100) != 0)
		{
			//AIT Mode 2-0
			CLEAR_BIT(MSPI->SINTRMSCR,BIT7 ) ;
			CLEAR_BIT(MSPI->SPIAITWLVCR,BIT0 ) ;
			MSPI->SINTRENCR = 0x1;
		}
		if ((MSPI->SINTRMSSR & 0x200) != 0)
		{
			//AIT Mode 2-1
			CLEAR_BIT(MSPI->SINTRMSCR,BIT8 );
			CLEAR_BIT(MSPI->SPIAITWLVCR,BIT4 );
			MSPI->SINTRENCR = 0x1;
		}
		if ((MSPI->SINTRMSSR & 0x400) != 0)
		{
			//AIT Mode 2-2
			CLEAR_BIT(MSPI->SINTRMSCR,BIT9 ) ;
			CLEAR_BIT(MSPI->SPIAITWLVCR,BIT8 ) ;
			MSPI->SINTRENCR = 0x1;
		}
		if ((MSPI->SINTRMSSR & 0x800) != 0)
		{
			//AIT Mode 2-3
			CLEAR_BIT(MSPI->SINTRMSCR,BIT10 ) ;
			CLEAR_BIT(MSPI->SPIAITWLVCR,BIT12 ) ;
			MSPI->SINTRENCR = 0x1;
		}
#endif /* ((!USED_FINGER_ONLY) || USED_PEN_MODE_OPERATION) */
	}
}

void MSPI_Initialize(void)
{
	const tHalMspiCommonConf_t * kptHalMspiCommonConf;
	Fncp_MSPI_IRQHandler = &MSPI_InterruptHandler;
	kptHalMspiCommonConf = hal_mspi_GetCommonConfig();
	
	//MSPI PIN Setting
	MSPI_GPIO_Init();
	
	// MSPI Clock Set
#if USED_PLL_OUT_CLK_CONFIG
	#if (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) // MSPI 16M
		MSPI_Set_CLK(3);//(3);
		MSPI_Set_GLF(3);//(3);
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_90MHz) // MSPI 15M - check
		MSPI_Set_CLK(3);//(3);
		MSPI_Set_GLF(3);//(3);
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_45MHz) // MSPI 11.3M
		MSPI_Set_CLK(2);//(3);
		MSPI_Set_GLF(2);//(3);
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_37p5MHz) // MSPI 9.4M
		MSPI_Set_CLK(2);//(3);
		MSPI_Set_GLF(2);//(3);
	#elif (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_31p5MHz) // MSPI 7.9M
		MSPI_Set_CLK();//(3);
		MSPI_Set_GLF(2);//(3);
	#else /* (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) */ // MSPI 15M
		MSPI_Set_CLK(3);//(3);
		MSPI_Set_GLF(3);//(3);
	#endif /* (PLL_OUT_CLOCK_SPEED == PLL_OUT_CLOCK_96MHz) */
#else /* USED_PLL_OUT_CLK_CONFIG */
	MSPI_Set_CLK(3); // (6);//(3);	// MSPI 6M choigs
	MSPI_Set_GLF(3); // (6);//(3);
#endif /* USED_PLL_OUT_CLK_CONFIG */
	
	MSPI->SCR = kptHalMspiCommonConf->tParam_SCR.ulBulk;
	MSPI->SPIENA = kptHalMspiCommonConf->tParam_SPIENA.ulBulk;
}

void MSPI_Reset(void)
{
	const tHalMspiCommonConf_t * kptHalMspiCommonConf;
	tMSPI_SCR_t tMSPI_SCR;

	kptHalMspiCommonConf = hal_mspi_GetCommonConfig();
	/*
	 * MSPI Init�떆 APB Clock Domain�쓣 Reset�빐 以��떎.
	 */
	GPIO->tGPIO_DATA_1.tBit.GPB11 = 1;

	tMSPI_SCR.ulBulk = kptHalMspiCommonConf->tParam_SCR.ulBulk;
	tMSPI_SCR.tBit.SWPRST = 1;
	tMSPI_SCR.tBit.SWHRST = 1;
	MSPI->SCR = tMSPI_SCR.ulBulk;
	__NOP();
	__NOP();
	__NOP();
	tMSPI_SCR.tBit.SWPRST = 0;
	tMSPI_SCR.tBit.SWHRST = 0;
	MSPI->SCR = tMSPI_SCR.ulBulk;

	GPIO->tGPIO_DATA_1.tBit.GPB11 = 0;
}

void MSPI_Set_TLPMODE(void)
{
	MSPI->SPIMODE_b.AitTlpMode 		= spiTlpMode;
	MSPI->SPIMODE_b.SramFifoMode 	= spiSramMode;
	MSPI->SPIMODE_b.HwSwMode 		= spiSwMode;
	MSPI->SPIMODE_b.BrstSnglMode 	= spiSnglMode;
	MSPI->SPIMODE_b.SramDebugMode 	= spiSramNormMode;
	MSPI->SPIMODE_b.SramWrOpt 		= spiSramWrOpt;
	MSPI->SPIMODE_b.TrsPerRd 		= spiTrsPerRd1;
	MSPI->SPIMODE_b.TrsPerWr 		= spiTrsPerWr1;
	MSPI->SPIMODE_b.PwfeSel 		= spiPwfe5Sel;
	MSPI->SPIMODE_b.CommPwfeSel 	= spiCommPwfeSel;
	MSPI->SPIMODE_b.Protocol 		= spiTlpProtocol;
	MSPI->SPIMODE_b.RdHlfWrdMsbFrst = spiRdHlfWrdLsbFrst;
	MSPI->SPIMODE_b.WrHlfWrdMsbFrst = spiWrHlfWrdLsbFrst;

	MSPI->SPISTATELEN_b.PreShftLen	 = 2;//16;
	MSPI->SPISTATELEN_b.TmpIdleLen 	 = 2;
	MSPI->SPISTATELEN_b.PostShftLen  = 15;
	MSPI->SPISTATELEN_b.SnglIdleLen  = 2;
	MSPI->SPISTATELEN_b.AitIdleLen 	 = 10;

	MSPI->SINTRMSCR_b.IntrMemMSCR = IntrMemDis;
}

#if USED_SW92400_OLD_SRIC_PROTOCOL
void MSPI_Set_AITMODE(eSENSING_MODE_t eSensingMode)
{
//	uint32_t *pLengthAddr, *pMosiAddr, *pMisoAddr, *pSyncLenAddr;
	uint8_t iMspi, i;

	const tHalPwmdrvCommonConf_t * pktHalPwmdrvCommonConf = hal_pwmdrv_GetCommonConfig();

	MSPI->SPIMODE_b.AitTlpMode		= spiAitMode;
	MSPI->SPIMODE_b.SramFifoMode	= spiSramMode;
	MSPI->SPIMODE_b.HwSwMode		= spiSwMode;
	MSPI->SPIMODE_b.BrstSnglMode	= spiBrstMode;
	MSPI->SPIMODE_b.SramDebugMode	= spiSramNormMode;
	MSPI->SPIMODE_b.SramWrOpt		= spiSramWrDefault;
	MSPI->SPIMODE_b.TrsPerRd		= spiTrsPerRd1;
	MSPI->SPIMODE_b.TrsPerWr		= spiTrsPerWr0;
	MSPI->SPIMODE_b.PwfeSel 		= spiPwfe5Sel;
	MSPI->SPIMODE_b.CommPwfeSel 	= spiCommPwfeSel;
	MSPI->SPIMODE_b.Protocol		= spiTlpProtocol;
	MSPI->SPIMODE_b.RdHlfWrdMsbFrst = spiRdHlfWrdMsbFrst;
	MSPI->SPIMODE_b.WrHlfWrdMsbFrst = spiWrHlfWrdLsbFrst;

	MSPI->SPIAITDMYDEL = AitDmyDelDis;
	MSPI->SINTRMSCR_b.IntrMemMSCR = IntrMemEna;

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
//		MSPI_BUF->ReadCommand[iMspi].Addr = READ_ALIGNED_BUF ;
//		MSPI_BUF->ReadCommand[iMspi].tBit.nBulk = 0;
//		MSPI_BUF->ReadCommand[iMspi].tBit.nWrite = 1;
// // LX98405 New - Choigs
		
		MSPI_BUF->ReadCommand[iMspi].Addr = READ_ALIGNED_BUF | 0x1 << 13 ; // share mode
		MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = 30;
		MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 0; // 0:32bit, 3:24bit
		MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 0;
		MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
		MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read		
		
		
		for (i = 0; i < SZ_MSPIBUF_MUXDATA*2 ; i++)
		{
			MSPI_BUF->ReadCommand[iMspi].Data[i] = 0;
		}
	}
/*
	if(IS_ACTIVE_MODE(eSensingMode))
	{
		MSPI->SPITRSZE0 = SZ_MSPIBUF_FINGER_FULL_FRAME;
		MSPI->SPITRSZE1 = SZ_MSPIBUF_FINGER_FULL_FRAME;
		MSPI->SPITRSZE2 = SZ_MSPIBUF_FINGER_FULL_FRAME;
		MSPI->SPITRSZE3 = SZ_MSPIBUF_FINGER_FULL_FRAME;
		MSPI->SPITRSZE4 = SZ_MSPIBUF_FINGER_FULL_FRAME;
		MSPI->SPITRSZE5 = SZ_MSPIBUF_FINGER_FULL_FRAME;
	}
	else
	{
		MSPI->SPITRSZE0 = SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME;
		MSPI->SPITRSZE1 = SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME;
		MSPI->SPITRSZE2 = SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME;
		MSPI->SPITRSZE3 = SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME;
		MSPI->SPITRSZE4 = SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME;
		MSPI->SPITRSZE5 = SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME;
	}
*/
		MSPI->SPITRSZE0 = SZ_MSPIBUF_FINGER_FULL_FRAME;
		MSPI->SPITRSZE1 = SZ_MSPIBUF_FINGER_FULL_FRAME;
		MSPI->SPITRSZE2 = SZ_MSPIBUF_FINGER_FULL_FRAME;
		MSPI->SPITRSZE3 = SZ_MSPIBUF_FINGER_FULL_FRAME;
		MSPI->SPITRSZE4 = SZ_MSPIBUF_FINGER_FULL_FRAME;
		MSPI->SPITRSZE5 = SZ_MSPIBUF_FINGER_FULL_FRAME;
		
	MSPI->SPITSYNCSZE0 = SZ_MSPIBUF_MUXDATA;
	MSPI->SPITSYNCSZE1 = SZ_MSPIBUF_MUXDATA;
	MSPI->SPITSYNCSZE2 = SZ_MSPIBUF_MUXDATA;
	MSPI->SPITSYNCSZE3 = SZ_MSPIBUF_MUXDATA;
	MSPI->SPITSYNCSZE4 = SZ_MSPIBUF_MUXDATA;
	MSPI->SPITSYNCSZE5 = SZ_MSPIBUF_MUXDATA;


	MSPI->SPISTRTRAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]));
	MSPI->SPISTRTRAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0])<<16 | 0x0000);
	MSPI->SPISTRTRAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]));

	MSPI->SPISTRTWAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1]));
	MSPI->SPISTRTWAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0])<<16 | 0x0000);
	MSPI->SPISTRTWAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3]));

}


#else /* USED_SW92400_OLD_SRIC_PROTOCOL */
void MSPI_Set_AITMODE(eSENSING_MODE_t eSensingMode)
{
	uint32_t *pLengthAddr, *pMosiAddr, *pMisoAddr, *pSyncLenAddr;
	uint8_t iMspi, i;

	const tHalPwmdrvCommonConf_t * pktHalPwmdrvCommonConf = hal_pwmdrv_GetCommonConfig();

	MSPI->SPIMODE_b.AitTlpMode		= spiAitMode;
	MSPI->SPIMODE_b.SramFifoMode	= spiSramMode;
	MSPI->SPIMODE_b.HwSwMode		= spiSwMode;
	MSPI->SPIMODE_b.BrstSnglMode	= spiBrstMode;
	MSPI->SPIMODE_b.SramDebugMode	= spiSramNormMode;
	MSPI->SPIMODE_b.SramWrOpt		= spiSramWrDefault;
	MSPI->SPIMODE_b.TrsPerRd		= spiTrsPerRd1;
	MSPI->SPIMODE_b.TrsPerWr		= spiTrsPerWr0;
	MSPI->SPIMODE_b.PwfeSel 		= spiPwfe5Sel;
	MSPI->SPIMODE_b.CommPwfeSel 	= spiCommPwfeSel;
	MSPI->SPIMODE_b.Protocol		= spiTlpProtocol;
	MSPI->SPIMODE_b.RdHlfWrdMsbFrst = spiRdHlfWrdMsbFrst;
	MSPI->SPIMODE_b.WrHlfWrdMsbFrst = spiWrHlfWrdLsbFrst;

	MSPI->SPIAITDMYDEL = AitDmyDelDis;
	MSPI->SINTRMSCR_b.IntrMemMSCR = IntrMemEna;

	pLengthAddr = (uint32_t *)&MSPI->SPITRSZE0;
	pSyncLenAddr = (uint32_t *)&MSPI->SPITSYNCSZE0;
	pMosiAddr = (uint32_t *)&MSPI->SPISTRTRAD01;
	pMisoAddr = (uint32_t *)&MSPI->SPISTRTWAD01;

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
//		MSPI_BUF->ReadCommand[iMspi].Addr = READ_ALIGNED_BUF ;
//	  MSPI_BUF->ReadCommand[iMspi].Command = ( MSPI_READ | MSPI_BURST);

		MSPI_BUF->ReadCommand[iMspi].Addr = READ_ALIGNED_BUF | 0x1 << 13; // share mode
		MSPI_BUF->ReadCommand[iMspi].tBit.Burst_Len = 30; // check
		MSPI_BUF->ReadCommand[iMspi].tBit.ReadFormat = 0; // 3:32bit, 1:24bit
		MSPI_BUF->ReadCommand[iMspi].tBit.DualRxEn = 0;
		MSPI_BUF->ReadCommand[iMspi].tBit.ChkSum = 0;
		MSPI_BUF->ReadCommand[iMspi].tBit.RW = 1; // 0 : write, 1 : Read

		MSPI_BUF->ReadCommand[iMspi].Data_M = 0;
		MSPI_BUF->ReadCommand[iMspi].Data_L = 0;
	

		for (i = 0; i < SZ_MSPIBUF_MUXDATA*2 ; i++)
		{
			MSPI_BUF->ReadCommand[iMspi].Data[i] = 0;
		}
	}

	for(iMspi = 0; iMspi < (MSPI_NUM + 2); iMspi += 2)
	{
		if(IS_ACTIVE_MODE(eSensingMode))
		{
			*pLengthAddr++ = SZ_MSPIBUF_FINGER_FULL_FRAME;
			*pLengthAddr++ = SZ_MSPIBUF_FINGER_FULL_FRAME;
		}
		else
		{
			*pLengthAddr++ = SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME;
			*pLengthAddr++ = SZ_MSPIBUF_FINGER_IDLE_FULL_FRAME;
		}
		*pSyncLenAddr++ = SZ_MSPIBUF_MUXDATA;
		*pSyncLenAddr++ = SZ_MSPIBUF_MUXDATA;
	}


//	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]) << 16; //SRIC 1
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]);	//SRIC 0

	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[3]) << 16;//SRIC 3
//	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[2]);//SRIC 2
	pMosiAddr++;

	*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[1]) << 16;//SRIC 5
	*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->ReadCommand[0]);//SRIC 4


//	*pMisoAddr = MSPI_MEM_INDEX(MSPI_BUF->Rawdata[3]) << 16;//SRIC 1
	*pMisoAddr++ |= MSPI_MEM_INDEX(MSPI_BUF->Rawdata[2]);//SRIC 0

	*pMisoAddr = MSPI_MEM_INDEX(MSPI_BUF->Rawdata[3]) << 16;//SRIC 3
//	*pMisoAddr++ |= MSPI_MEM_INDEX(MSPI_BUF->Rawdata[2]);//SRIC 2
	pMisoAddr++;
	*pMisoAddr = MSPI_MEM_INDEX(MSPI_BUF->Rawdata[1]) << 16;//SRIC 5
	*pMisoAddr++ |= MSPI_MEM_INDEX(MSPI_BUF->Rawdata[0]);//SRIC 4
}
#endif /* USED_SW92400_OLD_SRIC_PROTOCOL */

void MSPI_Set_GLF(int divisor)
{
	//* BEGIN OF MISO Glitch Filter Setting
	switch (divisor)
	{
	case 2:
		MSPI->SPIGFCR0   = 0X01010404;
		MSPI->SPIGFCR1   = 0X01010404;
		MSPI->SPIGFCR2   = 0X01010404;
		MSPI->SPIGFCR3   = 0X01010404;
		MSPI->SPIGFCR4   = 0X01010404;
		MSPI->SPIGFCR5   = 0X01010404;
		MSPI->SPIGFENA0  = 0X0000000D;
		MSPI->SPIGFENA1  = 0X0000000D;
		MSPI->SPIGFENA2  = 0X0000000D;
		MSPI->SPIGFENA3  = 0X0000000D;
		MSPI->SPIGFENA4  = 0X0000000D;
		MSPI->SPIGFENA5  = 0X0000000D;
		break;
	case 3:
		MSPI->SPIGFCR0   = 0X01020606;
		MSPI->SPIGFCR1   = 0X01020606;
		MSPI->SPIGFCR2   = 0X01020606;
		MSPI->SPIGFCR3   = 0X01020606;
		MSPI->SPIGFCR4   = 0X01020606;
		MSPI->SPIGFCR5   = 0X01020606;
		MSPI->SPIGFENA0  = 0X0000003B;
		MSPI->SPIGFENA1  = 0X0000003B;
		MSPI->SPIGFENA2  = 0X0000003B;
		MSPI->SPIGFENA3  = 0X0000003B;
		MSPI->SPIGFENA4  = 0X0000003B;
		MSPI->SPIGFENA5  = 0X0000003B;
		break;
	case 4:
		MSPI->SPIGFCR0   = 0X01020808;
		MSPI->SPIGFCR1   = 0X01020808;
		MSPI->SPIGFCR2   = 0X01020808;
		MSPI->SPIGFCR3   = 0X01020808;
		MSPI->SPIGFCR4   = 0X01020808;
		MSPI->SPIGFCR5   = 0X01020808;
		MSPI->SPIGFENA0  = 0X000000E3;
		MSPI->SPIGFENA1  = 0X000000E3;
		MSPI->SPIGFENA2  = 0X000000E3;
		MSPI->SPIGFENA3  = 0X000000E3;
		MSPI->SPIGFENA4  = 0X000000E3;
		MSPI->SPIGFENA5  = 0X000000E3;
		break;
	case 6:
		MSPI->SPIGFCR0   = 0X01020C0C;
		MSPI->SPIGFCR1   = 0X01020C0C;
		MSPI->SPIGFCR2   = 0X01020C0C;
		MSPI->SPIGFCR3   = 0X01020C0C;
		MSPI->SPIGFCR4   = 0X01020C0C;
		MSPI->SPIGFCR5   = 0X01020C0C;
		MSPI->SPIGFENA0  = 0X00000E03;
		MSPI->SPIGFENA1  = 0X00000E03;
		MSPI->SPIGFENA2  = 0X00000E03;
		MSPI->SPIGFENA3  = 0X00000E03;
		MSPI->SPIGFENA4  = 0X00000E03;
		MSPI->SPIGFENA5  = 0X00000E03;
		break;
	case 8:
		MSPI->SPIGFCR0   = 0X01021010;
		MSPI->SPIGFCR1   = 0X01021010;
		MSPI->SPIGFCR2   = 0X01021010;
		MSPI->SPIGFCR3   = 0X01021010;
		MSPI->SPIGFCR4   = 0X01021010;
		MSPI->SPIGFCR5   = 0X01021010;
		MSPI->SPIGFENA0  = 0X0000E003;
		MSPI->SPIGFENA1  = 0X0000E003;
		MSPI->SPIGFENA2  = 0X0000E003;
		MSPI->SPIGFENA3  = 0X0000E003;
		MSPI->SPIGFENA4  = 0X0000E003;
		MSPI->SPIGFENA5  = 0X0000E003;
		break;
	default:
		break;
	}
	//* END  OF MISO Glitch Filter Setting

}

void MSPI_Set_CLK(int divisor)
{
	switch (divisor)
	{
	case 2:
		MSPI->SPIPCLKEND = 0X2212;
		MSPI->SPIHCLKCOMMEND = 0X15;
		break;
	case 3:
		MSPI->SMISC      = 0X8;
		MSPI->SPIHCLKCOMMEND = 0X15;
		break;
	case 4:
		MSPI->SPIPCLKEND = 0X4434;
		MSPI->SPIHCLKCOMMEND = 0X45;
		break;
	case 6:
		MSPI->SPIPCLKEND = 0X4656;
		MSPI->SPIHCLKCOMMEND = 0X65;
		break;
	case 8:
		MSPI->SPIPCLKEND = 0X6878;
		MSPI->SPIHCLKCOMMEND = 0X85;
		break;
	default:
		break;
	}
}

void MSPI_ITConfig(FunctionalState NewState)
{	
	NVIC_ClearPendingIRQ(MSPI_IRQn);
	NVIC_SetPriority(MSPI_IRQn, MSPI_IRQn_Priority);
	
	if(NewState != DISABLE)
	{
		NVIC_EnableIRQ(MSPI_IRQn);
	}
	else
	{
		NVIC_DisableIRQ(MSPI_IRQn);
	}
}

void MSPI_Cmd(FunctionalState NewState)
{	
	if(NewState != DISABLE)
	{
		MSPI->SPISTART = 0x3F;
	}
	else
	{
		MSPI->SPISTART = 0;
	}
}

// choigs // Check
void MSPI_IntCLR(void)
{

	while(1)
	{
		if( MSPI->SINTRSR & INTR_MEM_ENA) 		/*[6] : Memory Interrupt Status*/
		{
			MSPI->SINTRENCR = 0x1;
			break;
		}
	}
}


// Choigs

// LX98405 New - Choigs
void MSPI_RegisterRead( uint32_t Addr, volatile uint32_t *ReadBuf, eROIC_Read_Option_t eOption)
{
	uint32_t *pLengthAddr, *pMisoAddr, *pMosiAddr;
	//    uint8_t iMspi, i; // NOTE : WarningA|째A
	uint8_t iMspi;
	
	 uint32_t ulAddr ;
	
		ulAddr = Addr;
	if(eOption == MSPI_READ_SM1)
	{
		ulAddr += 0x1 << 12 ;  // Select SM0
	}
		
	/** Protocol setup */ 
	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
//		MSPI_BUF->SricRegWriteBuffer[iMspi].Addr = Addr;
//		MSPI_BUF->SricRegWriteBuffer[iMspi].Command = (MSPI_READ | MSPI_SINGLE);
		//MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.nBulk = 1;//MSPI_SINGLE;
	//	MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.nWrite = 1;//MSPI_READ;
	//	MSPI_BUF->SricRegWriteBuffer[iMspi].Data = 0;
		
		MSPI_BUF->SricRegWriteBuffer[iMspi].Addr = ulAddr;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.Burst_Len = 1;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.DualRxEn = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.ChkSum = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.RW = 1; // 0 : write, 1 : Read

		MSPI_BUF->SricRegWriteBuffer[iMspi].Data_M = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].Data_L = 0;
		
	}
	
	/** MSPI Control Setup */
	pLengthAddr = (uint32_t *)&MSPI->SPITRSZE0;
	pMosiAddr = (uint32_t *)&MSPI->SPISTRTRAD01;
	pMisoAddr = (uint32_t *)&MSPI->SPISTRTWAD01;

#ifdef _DV_SAMPLE_

	MSPI->SPITRSZE0 = SZ_MSPIBUF_REGISTER;
//	MSPI->SPITRSZE1 = SZ_MSPIBUF_REGISTER;
//	MSPI->SPITRSZE2 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE3 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE4 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE5 = SZ_MSPIBUF_REGISTER;


	MSPI->SPISTRTRAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[1]));
	MSPI->SPISTRTRAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[0])<<16 | 0x0000);
	MSPI->SPISTRTRAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[3]));

	MSPI->SPISTRTWAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[1]));
	MSPI->SPISTRTWAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[0])<<16 | 0x0000);
	MSPI->SPISTRTWAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[3]));
#else
	for(iMspi = 0; iMspi<MSPI_NUM ; iMspi+=2)
	{
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;
		
		*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][iMspi+1]) << 16;
		*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_SEND][iMspi]);

		*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][iMspi+1]) << 16;
		*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[IDX_READ][iMspi]);
	}
#endif    
	
	MSPI->SINTRMSCR = DISABLE;

	/** MSPI Start */
	MSPI->SPISTART = BIT5|BIT4|BIT3|BIT2|BIT1|BIT0;
	
	
	MSPI_IntCLR();
	
	for (iMspi = 0; iMspi < MSPI_NUM; iMspi++)
	{
		*ReadBuf++= MSPI_BUF->SricRegReadBuffer[iMspi].Data1 << 16 |  MSPI_BUF->SricRegReadBuffer[iMspi].Data2;
	}
}






void MSPI_Set_FingerMode(void)
{
	uint32_t *pLengthAddr;
	int i;
	pLengthAddr = (uint32_t *)&MSPI->SPITRSZE0;
	for (i = 0; i<MSPI_NUM ; i+=2)
	{
		*pLengthAddr++ = SZ_MSPIBUF_FINGER_FULL_FRAME;
		*pLengthAddr++ = SZ_MSPIBUF_FINGER_FULL_FRAME;
	}
}

void MSPI_Set_FingerPenMode(void)
{
	
	uint32_t *pLengthAddr;
	int i;
	pLengthAddr = (uint32_t *)&MSPI->SPITRSZE0;
	for (i = 0; i<MSPI_NUM ; i+=2)
	{
		*pLengthAddr++ = SZ_MSPIBUF_FINGERPEN_FRAME;
		*pLengthAddr++ = SZ_MSPIBUF_FINGERPEN_FRAME;
		//		*pLengthAddr++ = SZ_MSPIBUF_MUXDATA;
		//		*pLengthAddr++ = SZ_MSPIBUF_MUXDATA;
	}
}


void MSPI_Set_BUFSIZE_FingerPenMode(int index)
{
//	uint32_t *pLengthAddr;
//	int i;

	
//	pLengthAddr = (uint32_t *)&MSPI->SPITRSZE0;
//
//	for (i = 0; i<MSPI_NUM ; i+=2)
//	{
//		*pLengthAddr++ = SZ_MSPIBUF_MUXDATA[index];
//		*pLengthAddr++ = SZ_MSPIBUF_MUXDATA[index];
//	}
}

#if (!USED_FINGER_ONLY)
void MSPI_Set_BUFSIZE_FingerMode(int index)
{
	uint32_t *pLengthAddr;
	int i;
	uint32_t sizeLut[3]={
			FINGER_MUX_NUM,
			FINGER_MUX_NUM,
			FINGER_NI_MUX_NUM
	};

	pLengthAddr = (uint32_t *)&MSPI->SPITRSZE0;

	for (i = 0; i<MSPI_NUM ; i+=2){
		*pLengthAddr++ = SZ_MSPIBUF_MUXDATA*sizeLut[index];
		*pLengthAddr++ = SZ_MSPIBUF_MUXDATA*sizeLut[index];
	}
}
#endif /* (!USED_FINGER_ONLY) */

void MSPI_Set_BUFAddress_FingerMode(int index)
{
	uint32_t * pMisoAddr;
	pMisoAddr = (uint32_t *)&MSPI->SPISTRTWAD01;

//	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[4][index]) << 16;//SRIC 1
	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[2][index]);//SRIC 0

	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[3][index]) << 16;//SRIC 3
//	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[5][index]);//SRIC 2
	pMisoAddr++;

	*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[1][index]) << 16;//SRIC 5
	*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->Rawdata[0][index]);//SRIC 4
}


void MSPI_CommandWrite( uint32_t write_control, uint32_t pen_mode, uint16_t local_position)
{
	int i;
	for (i = 0; i < MSPI_NUM ; i++)
	{
		MSPI_BUF->ReadCommand[i].Command = ( (write_control<<12) | (pen_mode<<6) | (local_position<<0) | MSPI_READ|MSPI_BURST);
	}

}

// // LX98405 New - Choigs

void MSPI_EachRegisterWrite( uint32_t Addr, uint32_t * pvalue, eROIC_Read_Option_t eOption)
{
	uint32_t *pLengthAddr, *pMisoAddr, *pMosiAddr;
	uint8_t iMspi;
  uint32_t pvalue_sel[4];
	
	uint32_t ulAddr ;
	
		ulAddr = Addr;
	if(eOption == MSPI_READ_SM1)
	{
		ulAddr += 0x1 << 12 ;  // Select SM=1
		pvalue_sel[0] = pvalue[0]; // SRIC1
		pvalue_sel[1] = pvalue[2]; // SRIC3
		pvalue_sel[2] = pvalue[4]; // SRIC5
		pvalue_sel[3] = pvalue[6]; // SRIC7
	}
	else{
		pvalue_sel[0] = pvalue[0]; // SRIC2
		pvalue_sel[1] = pvalue[2]; // SRIC4
		pvalue_sel[2] = pvalue[4]; // SRIC6
		pvalue_sel[3] = pvalue[6]; // SRIC8
	}
	
	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
//		MSPI_BUF->SricRegWriteBuffer[iMspi].Addr = Addr ;
//		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.nBulk = 1;
//		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.nWrite = 0;
//		MSPI_BUF->SricRegWriteBuffer[iMspi].Data = pvalue[iMspi];
		
		
		MSPI_BUF->SricRegWriteBuffer[iMspi].Addr = ulAddr;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.Burst_Len = 1;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.DualRxEn = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.ChkSum = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.RW = 0; // 0 : write, 1 : Read
		
		
		MSPI_BUF->SricRegWriteBuffer[iMspi].Data_M = pvalue_sel[iMspi] >> 16;
		MSPI_BUF->SricRegWriteBuffer[iMspi].Data_L = pvalue_sel[iMspi] & 0xFFFF;
		
		
	}

#ifdef _DV_SAMPLE_
	MSPI->SPITRSZE0 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE1 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE2 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE3 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE4 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE5 = SZ_MSPIBUF_REGISTER;

	MSPI->SPISTRTRAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[1]));
	MSPI->SPISTRTRAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[0])<<16 | 0x0000);
	MSPI->SPISTRTRAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[3]));

	MSPI->SPISTRTWAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[1]));
	MSPI->SPISTRTWAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[0])<<16 | 0x0000);
	MSPI->SPISTRTWAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[3]));

#endif
	MSPI->SINTRMSCR = DISABLE;

	MSPI->SPISTART = BIT5|BIT4|BIT3|BIT2|BIT1|BIT0;
	MSPI_IntCLR();
}


// // LX98405 New - Choigs

//void MSPI_RegisterWrite( uint32_t Addr, uint16_t value)

void MSPI_RegisterWrite (uint32_t Addr, uint32_t value, eROIC_Read_Option_t eOption)
{
	uint32_t iMspi;

		uint32_t ulAddr ;
	
		ulAddr = Addr;
	if(eOption == MSPI_READ_SM1)
	{
		ulAddr += 0x1 << 12 ;  // Select SM0
	}	
	
	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		//MSPI_BUF->SricRegWriteBuffer[iMspi].Addr = Addr ;
		//MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.nBulk = 1;//MSPI_SINGLE;
		//MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.nWrite = 0;//MSPI_WRITE;
		//		MSPI_BUF->SricRegWriteBuffer[iMspi].Data = value;		
		
	  MSPI_BUF->SricRegWriteBuffer[iMspi].Addr = ulAddr;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.Burst_Len = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.DualRxEn = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.ChkSum = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.RW = 0; // 0 : write, 1 : Read	
		MSPI_BUF->SricRegWriteBuffer[iMspi].Data_M = value >> 16;
		MSPI_BUF->SricRegWriteBuffer[iMspi].Data_L = value & 0xFFFF;
		
		
	}

#ifdef _DV_SAMPLE_
	// TR Size
	MSPI->SPITRSZE0 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE1 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE2 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE3 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE4 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE5 = SZ_MSPIBUF_REGISTER;

	MSPI->SPISTRTRAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[1]));
	MSPI->SPISTRTRAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[0])<<16 | 0x0000);
	MSPI->SPISTRTRAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[3]));

	MSPI->SPISTRTWAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[1]));
	MSPI->SPISTRTWAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[0])<<16 | 0x0000);
	MSPI->SPISTRTWAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[3]));
#else
	for (iMspi = 0; iMspi<MSPI_NUM ; iMspi+=2)
	{
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;

		*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[0][iMspi+1]) << 16;
		*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[0][iMspi]);

		*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[1][iMspi+1]) << 16;
		*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[1][iMspi]);
	}
#endif

	MSPI->SINTRMSCR = DISABLE;

	MSPI->SPISTART = BIT5|BIT4|BIT3|BIT2|BIT1|BIT0;
	MSPI_IntCLR();
}




// Choigs

//void MSPI_RegisterWrite( uint32_t Addr, uint16_t value)

void MSPI_RegisterAllSricWrite (uint32_t Addr, uint32_t value)
{
	uint32_t iMspi;

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
		//MSPI_BUF->SricRegWriteBuffer[iMspi].Addr = Addr ;
		//MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.nBulk = 1;//MSPI_SINGLE;
		//MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.nWrite = 0;//MSPI_WRITE;
		//		MSPI_BUF->SricRegWriteBuffer[iMspi].Data = value;		
		
	  MSPI_BUF->SricRegWriteBuffer[iMspi].Addr = Addr | 0x1 << 13;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.Burst_Len = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.DualRxEn = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.ChkSum = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.RW = 0; // 0 : write, 1 : Read	
		MSPI_BUF->SricRegWriteBuffer[iMspi].Data_M = value >> 16;
		MSPI_BUF->SricRegWriteBuffer[iMspi].Data_L = value & 0xFFFF;
		
		
	}

#ifdef _DV_SAMPLE_
	// TR Size
	MSPI->SPITRSZE0 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE1 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE2 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE3 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE4 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE5 = SZ_MSPIBUF_REGISTER;

	MSPI->SPISTRTRAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[1]));
	MSPI->SPISTRTRAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[0])<<16 | 0x0000);
	MSPI->SPISTRTRAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[3]));

	MSPI->SPISTRTWAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[1]));
	MSPI->SPISTRTWAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[0])<<16 | 0x0000);
	MSPI->SPISTRTWAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[3]));
#else
	for (iMspi = 0; iMspi<MSPI_NUM ; iMspi+=2)
	{
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;

		*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[0][iMspi+1]) << 16;
		*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[0][iMspi]);

		*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[1][iMspi+1]) << 16;
		*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[1][iMspi]);
	}
#endif

	MSPI->SINTRMSCR = DISABLE;

	MSPI->SPISTART = BIT5|BIT4|BIT3|BIT2|BIT1|BIT0;
	MSPI_IntCLR();
}

#if (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405)
void MSPI_RegisterWriteBuf(uint32_t Addr, uint32_t *WriteBuf,eROIC_Read_Option_t eOption)
{
	uint32_t iMspi;

	for (iMspi = 0; iMspi < MSPI_NUM ; iMspi++)
	{
//		MSPI_BUF->SricRegWriteBuffer[iMspi].Addr = Addr ;
//		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.nBulk = 1;
//		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.nWrite = 0;
//		MSPI_BUF->SricRegWriteBuffer[iMspi].Data = WriteBuf[iMspi];
		
 	  MSPI_BUF->SricRegWriteBuffer[iMspi].Addr = Addr;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.Burst_Len = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.ReadFormat = 0; // 0:32bit, 1:24bit
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.DualRxEn = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.ChkSum = 0;
		MSPI_BUF->SricRegWriteBuffer[iMspi].tBit.RW = 0; // 0 : write, 1 : Read
		
		MSPI_BUF->SricRegWriteBuffer[iMspi].Data_M = WriteBuf[iMspi] >> 16;
		MSPI_BUF->SricRegWriteBuffer[iMspi].Data_L = WriteBuf[iMspi] & 0xFFFF;
		
		
	}

#ifdef _DV_SAMPLE_
	MSPI->SPITRSZE0 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE1 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE2 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE3 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE4 = SZ_MSPIBUF_REGISTER;
	MSPI->SPITRSZE5 = SZ_MSPIBUF_REGISTER;
		
	MSPI->SPISTRTRAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[1]));
	MSPI->SPISTRTRAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[0])<<16 | 0x0000);
	MSPI->SPISTRTRAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->SricRegWriteBuffer[3]));
	
	MSPI->SPISTRTWAD01 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[1]));
	MSPI->SPISTRTWAD23 = (uint32_t)(MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[0])<<16 | 0x0000);
	MSPI->SPISTRTWAD45 = (uint32_t)((MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[2])<<16) | MSPI_MEM_INDEX(&MSPI_BUF->SricRegReadBuffer[3]));
#else
	for (iMspi = 0; iMspi<MSPI_NUM ; iMspi+=2)
	{
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;
		*pLengthAddr++ = SZ_MSPIBUF_REGISTER;

		*pMosiAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[0][iMspi+1]) << 16;
		*pMosiAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[0][iMspi]);

		*pMisoAddr = MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[1][iMspi+1]) << 16;
		*pMisoAddr++ |= MSPI_MEM_INDEX(&MSPI_BUF->SricBuffer[1][iMspi]);
	}
#endif

	MSPI->SINTRMSCR = DISABLE;

	MSPI->SPISTART = BIT5|BIT4|BIT3|BIT2|BIT1|BIT0;
	MSPI_IntCLR();
}
#endif /* (CUSTOMER == MODEL_LGD_SW97400B || CUSTOMER == MODEL_LGD_LX98405) */

#if USED_SW92400_OLD_SRIC_PROTOCOL
void MSPI_Single_Write(uint8_t ch, uint16_t Addr, uint16_t value)
{
//	MSPI_BUF->SricRegWriteBuffer[ch].Addr = Addr;
//	MSPI_BUF->SricRegWriteBuffer[ch].tBit.nBulk = 1;
//	MSPI_BUF->SricRegWriteBuffer[ch].tBit.nWrite = 0;
//	MSPI_BUF->SricRegWriteBuffer[ch].Data = value;
//
//	// SPIENA Enable �릺�뼱�엳�뒗 梨꾨꼸�뿉 ���빐�꽌�뒗 諛섎뱶�떆 W/R Size �꽕�젙
//	MSPI->SPITRSZE0 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//	MSPI->SPITRSZE1 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//	MSPI->SPITRSZE2 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//	MSPI->SPITRSZE3 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//	MSPI->SPITRSZE4 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//	MSPI->SPITRSZE5 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//
//	// Write Buffer Start Address Setting
//	switch (ch)
//	{
//		case MSPI0:
//			MSPI->SPISTRTRAD01 |= MSPI_MEM_LSB(&MSPI_BUF->SricRegWriteBuffer[ch]);
//			break;
//		case MSPI1:
//			MSPI->SPISTRTRAD01 |= MSPI_MEM_MSB(&MSPI_BUF->SricRegWriteBuffer[ch]);
//			break;
//		case MSPI2:
//			MSPI->SPISTRTRAD23 |= MSPI_MEM_LSB(&MSPI_BUF->SricRegWriteBuffer[ch]);
//			break;
//		case MSPI3:
//			MSPI->SPISTRTRAD23 |= MSPI_MEM_MSB(&MSPI_BUF->SricRegWriteBuffer[ch]);
//			break;
//		case MSPI4:
//			MSPI->SPISTRTRAD45 |= MSPI_MEM_LSB(&MSPI_BUF->SricRegWriteBuffer[ch]);
//			break;
//		case MSPI5:
//			MSPI->SPISTRTRAD45 |= MSPI_MEM_MSB(&MSPI_BUF->SricRegWriteBuffer[ch]);
//			break;
//		default:
//			break;
//	}
//
//	MSPI->SINTRMSCR = DISABLE;
//
//	// SPIENA Enable �릺�뼱�엳�뒗 梨꾨꼸�뿉 ���빐�꽌�뒗 諛섎뱶�떆 Bit �꽕�젙
//	MSPI->SPISTART = BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0;
//	MSPI_IntCLR();
}

uint16_t MSPI_Single_Read(uint8_t ch, uint16_t Addr)
{
	uint16_t usData;
	return usData;
//	MSPI_BUF->SricBuffer[IDX_SEND][ch].Addr = Addr;
//	MSPI_BUF->SricBuffer[IDX_SEND][ch].Command = (MSPI_READ | MSPI_SINGLE);
//
//	// SPIENA Enable �릺�뼱�엳�뒗 梨꾨꼸�뿉 ���빐�꽌�뒗 諛섎뱶�떆 W/R Size �꽕�젙
//	MSPI->SPITRSZE0 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//	MSPI->SPITRSZE1 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//	MSPI->SPITRSZE2 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//	MSPI->SPITRSZE3 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//	MSPI->SPITRSZE4 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//	MSPI->SPITRSZE5 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
//
//	// Read Buffer Start Address Setting
//	switch (ch)
//	{
//		case MSPI0:
//			MSPI->SPISTRTWAD01 |= MSPI_MEM_LSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
//			break;
//		case MSPI1:
//			MSPI->SPISTRTWAD01 |= MSPI_MEM_MSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
//			break;
//		case MSPI2:
//			MSPI->SPISTRTWAD23 |= MSPI_MEM_LSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
//			break;
//		case MSPI3:
//			MSPI->SPISTRTWAD23 |= MSPI_MEM_MSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
//			break;
//		case MSPI4:
//			MSPI->SPISTRTWAD45 |= MSPI_MEM_LSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
//			break;
//		case MSPI5:
//			MSPI->SPISTRTWAD45 |= MSPI_MEM_MSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
//			break;
//		default:
//			break;
//	}
//
//	MSPI->SINTRMSCR = DISABLE;
//
//	// SPIENA Enable �릺�뼱�엳�뒗 梨꾨꼸�뿉 ���빐�꽌�뒗 諛섎뱶�떆 Bit �꽕�젙
//	MSPI->SPISTART = BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0;
//	MSPI_IntCLR();
//
//	return (MSPI_BUF->SricBuffer[IDX_READ][ch].Addr);
}
#else /* USED_SW92400_OLD_SRIC_PROTOCOL */
void MSPI_Single_Write(uint8_t ch, uint16_t Addr, uint16_t value)
{
	MSPI_BUF->SricBuffer[IDX_SEND][ch].Addr = Addr;
	MSPI_BUF->SricBuffer[IDX_SEND][ch].Command = (MSPI_SINGLE | MSPI_WRITE);
	MSPI_BUF->SricBuffer[IDX_SEND][ch].Data = value;

	// SPIENA Enable �릺�뼱�엳�뒗 梨꾨꼸�뿉 ���빐�꽌�뒗 諛섎뱶�떆 W/R Size �꽕�젙
	MSPI->SPITRSZE0 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
	MSPI->SPITRSZE1 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
	MSPI->SPITRSZE2 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
	MSPI->SPITRSZE3 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
	MSPI->SPITRSZE4 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
	MSPI->SPITRSZE5 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)

	// Write Buffer Start Address Setting
	switch (ch)
	{
		case MSPI0:
			MSPI->SPISTRTRAD01 |= MSPI_MEM_LSB(&MSPI_BUF->SricBuffer[IDX_SEND][ch]);
			break;
		case MSPI1:
			MSPI->SPISTRTRAD01 |= MSPI_MEM_MSB(&MSPI_BUF->SricBuffer[IDX_SEND][ch]);
			break;
		case MSPI2:
			MSPI->SPISTRTRAD23 |= MSPI_MEM_LSB(&MSPI_BUF->SricBuffer[IDX_SEND][ch]);
			break;
		case MSPI3:
			MSPI->SPISTRTRAD23 |= MSPI_MEM_MSB(&MSPI_BUF->SricBuffer[IDX_SEND][ch]);
			break;
		case MSPI4:
			MSPI->SPISTRTRAD45 |= MSPI_MEM_LSB(&MSPI_BUF->SricBuffer[IDX_SEND][ch]);
			break;
		case MSPI5:
			MSPI->SPISTRTRAD45 |= MSPI_MEM_MSB(&MSPI_BUF->SricBuffer[IDX_SEND][ch]);
			break;
		default:
			break;
	}

	MSPI->SINTRMSCR = DISABLE;

	// SPIENA Enable �릺�뼱�엳�뒗 梨꾨꼸�뿉 ���빐�꽌�뒗 諛섎뱶�떆 Bit �꽕�젙
	MSPI->SPISTART = BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0;
	MSPI_IntCLR();
}

uint16_t MSPI_Single_Read(uint8_t ch, uint16_t Addr)
{
	MSPI_BUF->SricBuffer[IDX_SEND][ch].Addr = Addr;
	MSPI_BUF->SricBuffer[IDX_SEND][ch].Command = (MSPI_READ | MSPI_SINGLE);

	// SPIENA Enable �릺�뼱�엳�뒗 梨꾨꼸�뿉 ���빐�꽌�뒗 諛섎뱶�떆 W/R Size �꽕�젙
	MSPI->SPITRSZE0 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
	MSPI->SPITRSZE1 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
	MSPI->SPITRSZE2 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
	MSPI->SPITRSZE3 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
	MSPI->SPITRSZE4 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)
	MSPI->SPITRSZE5 = SZ_MSPIBUF_REGISTER;	// Tx/Rx buffer Size (Dummy 2 + 1)

	// Read Buffer Start Address Setting
	switch (ch)
	{
		case MSPI0:
			MSPI->SPISTRTWAD01 |= MSPI_MEM_LSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
			break;
		case MSPI1:
			MSPI->SPISTRTWAD01 |= MSPI_MEM_MSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
			break;
		case MSPI2:
			MSPI->SPISTRTWAD23 |= MSPI_MEM_LSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
			break;
		case MSPI3:
			MSPI->SPISTRTWAD23 |= MSPI_MEM_MSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
			break;
		case MSPI4:
			MSPI->SPISTRTWAD45 |= MSPI_MEM_LSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
			break;
		case MSPI5:
			MSPI->SPISTRTWAD45 |= MSPI_MEM_MSB(&MSPI_BUF->SricBuffer[IDX_READ][ch]);
			break;
		default:
			break;
	}

	MSPI->SINTRMSCR = DISABLE;

	// SPIENA Enable �릺�뼱�엳�뒗 梨꾨꼸�뿉 ���빐�꽌�뒗 諛섎뱶�떆 Bit �꽕�젙
	MSPI->SPISTART = BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0;
	MSPI_IntCLR();

	return (MSPI_BUF->SricBuffer[IDX_READ][ch].Addr);
}
#endif /* USED_SW92400_OLD_SRIC_PROTOCOL */

void MSPI_GPIO_Init(void)
{
	/////////////////////////////////////////////////////////////////////////////////
	// MSPI GPIO Initialization                
	/////////////////////////////////////////////////////////////////////////////////

#if MSPI_GPIO_SRIC0_EN
	/*
	 * 1111 PANNEL SRIC 5 (Pannel SRIC 1踰덈룞�옉)
	 */
	GPIO->tGPIO_AFIO_0.tBit.GPA00 = 0x1; // 0:GPIO, 1:MSPI0_MST_SSN
	GPIO->tGPIO_AFIO_0.tBit.GPA01 = 0x1; // 0:GPIO, 1:MSPI0_MST_SCLK
	GPIO->tGPIO_AFIO_0.tBit.GPA02 = 0x1; // 0:GPIO, 1:MSPI0_MST_MOSI
	GPIO->tGPIO_AFIO_0.tBit.GPA03 = 0x1; // 0:GPIO, 1:MSPI0_MST_MISO
#else /* MSPI_GPIO_SRIC0_EN */
	GPIO->tGPIO_AFIO_0.tBit.GPA00 = 0x0; // 0:GPIO, 1:MSPI0_MST_SSN
	GPIO->tGPIO_AFIO_0.tBit.GPA01 = 0x0; // 0:GPIO, 1:MSPI0_MST_SCLK
	GPIO->tGPIO_AFIO_0.tBit.GPA02 = 0x0; // 0:GPIO, 1:MSPI0_MST_MOSI
	GPIO->tGPIO_AFIO_0.tBit.GPA03 = 0x0; // 0:GPIO, 1:MSPI0_MST_MISO

	GPIO->tGPIO_DIR_0.tBit.GPA00 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DIR_0.tBit.GPA01 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DIR_0.tBit.GPA02 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DIR_0.tBit.GPA03 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_DATA_0.tBit.GPA00 = 0x0; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DATA_0.tBit.GPA01 = 0x0; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DATA_0.tBit.GPA02 = 0x0; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DATA_0.tBit.GPA03 = 0x0; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_PD_0.tBit.GPA00 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_PD_0.tBit.GPA01 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_PD_0.tBit.GPA02 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_PD_0.tBit.GPA03 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
#endif /* MSPI_GPIO_SRIC0_EN */

#if MSPI_GPIO_SRIC1_EN
	/*
	 * 2222 PANNEL SRIC 6 (�룞�옉 X)
	 */
	GPIO->tGPIO_AFIO_0.tBit.GPA04 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_AFIO_0.tBit.GPA05 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_AFIO_0.tBit.GPA06 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_AFIO_0.tBit.GPA07 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
#else /* MSPI_GPIO_SRIC1_EN */
	/*
	 * 2222 PANNEL SRIC 6 (�룞�옉 X)
	 */
	GPIO->tGPIO_AFIO_0.tBit.GPA04 = 0x0; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_AFIO_0.tBit.GPA05 = 0x0; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_AFIO_0.tBit.GPA06 = 0x0; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_AFIO_0.tBit.GPA07 = 0x0; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_DIR_0.tBit.GPA04 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DIR_0.tBit.GPA05 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DIR_0.tBit.GPA06 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DIR_0.tBit.GPA07 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_DATA_0.tBit.GPA04 = 0x0; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DATA_0.tBit.GPA05 = 0x0; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DATA_0.tBit.GPA06 = 0x0; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DATA_0.tBit.GPA07 = 0x0; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_PD_0.tBit.GPA04 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_PD_0.tBit.GPA05 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_PD_0.tBit.GPA06 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_PD_0.tBit.GPA07 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
#endif /* MSPI_GPIO_SRIC1_EN */

#if MSPI_GPIO_SRIC2_EN
	/*
	 * 3333 PANNEL SRIC 1 (�룞�옉X)
	 */
	GPIO->tGPIO_AFIO_0.tBit.GPA08 = 0x1; // 0:GPIO, 1:MSPI2_MST_SSN
	GPIO->tGPIO_AFIO_0.tBit.GPA09 = 0x1; // 0:GPIO, 1:MSPI2_MST_SCLK
	GPIO->tGPIO_AFIO_0.tBit.GPA10 = 0x1; // 0:GPIO, 1:MSPI2_MST_MOSI
	GPIO->tGPIO_AFIO_0.tBit.GPA11 = 0x1; // 0:GPIO, 1:MSPI2_MST_MISO
#else /* MSPI_GPIO_SRIC2_EN */
	/*
	 * 3333 PANNEL SRIC 1 (�룞�옉X)
	 */
	GPIO->tGPIO_AFIO_0.tBit.GPA08 = 0x0; // 0:GPIO, 1:MSPI2_MST_SSN
	GPIO->tGPIO_AFIO_0.tBit.GPA09 = 0x0; // 0:GPIO, 1:MSPI2_MST_SCLK
	GPIO->tGPIO_AFIO_0.tBit.GPA10 = 0x0; // 0:GPIO, 1:MSPI2_MST_MOSI
	GPIO->tGPIO_AFIO_0.tBit.GPA11 = 0x0; // 0:GPIO, 1:MSPI2_MST_MISO

	GPIO->tGPIO_DIR_0.tBit.GPA08 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DIR_0.tBit.GPA09 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DIR_0.tBit.GPA10 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DIR_0.tBit.GPA11 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_DATA_0.tBit.GPA08 = 0x0; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DATA_0.tBit.GPA09 = 0x0; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DATA_0.tBit.GPA10 = 0x0; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DATA_0.tBit.GPA11 = 0x0; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_PD_0.tBit.GPA08 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_PD_0.tBit.GPA09 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_PD_0.tBit.GPA10 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_PD_0.tBit.GPA11 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
#endif /* MSPI_GPIO_SRIC2_EN */

#if MSPI_GPIO_SRIC3_EN
	/*
	 * 4444 PANNEL SRIC 4 (�룞�옉X)
	 */
	GPIO->tGPIO_AFIO_0.tBit.GPA12 = 0x1; // 0:GPIO, 1:MSPI3_MST_SSN
	GPIO->tGPIO_AFIO_0.tBit.GPA13 = 0x1; // 0:GPIO, 1:MSPI3_MST_SCLK
	GPIO->tGPIO_AFIO_0.tBit.GPA14 = 0x1; // 0:GPIO, 1:MSPI3_MST_MOSI
	GPIO->tGPIO_AFIO_0.tBit.GPA15 = 0x1; // 0:GPIO, 1:MSPI3_MST_MISO
#else /* MSPI_GPIO_SRIC3_EN */
	/*
	 * 4444 PANNEL SRIC 4
	 */
	GPIO->tGPIO_AFIO_0.tBit.GPA12 = 0x0; // 0:GPIO, 1:MSPI3_MST_SSN
	GPIO->tGPIO_AFIO_0.tBit.GPA13 = 0x0; // 0:GPIO, 1:MSPI3_MST_SCLK
	GPIO->tGPIO_AFIO_0.tBit.GPA14 = 0x0; // 0:GPIO, 1:MSPI3_MST_MOSI
	GPIO->tGPIO_AFIO_0.tBit.GPA15 = 0x0; // 0:GPIO, 1:MSPI3_MST_MISO

	GPIO->tGPIO_DIR_0.tBit.GPA12 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DIR_0.tBit.GPA13 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DIR_0.tBit.GPA14 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DIR_0.tBit.GPA15 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_DATA_0.tBit.GPA12 = 0x0; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DATA_0.tBit.GPA13 = 0x0; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DATA_0.tBit.GPA14 = 0x0; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DATA_0.tBit.GPA15 = 0x0; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_PD_0.tBit.GPA12 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_PD_0.tBit.GPA13 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_PD_0.tBit.GPA14 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_PD_0.tBit.GPA15 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
#endif /* MSPI_GPIO_SRIC3_EN */

#if MSPI_GPIO_SRIC4_EN
	/*
	 * 55555 PANNEL SRIC 2 (�룞�옉 X)
	 */
	GPIO->tGPIO_AFIO_1.tBit.GPA16 = 0x1; // 0:GPIO, 1:MSPI4_MST_SSN
	GPIO->tGPIO_AFIO_1.tBit.GPA17 = 0x1; // 0:GPIO, 1:MSPI4_MST_SCLK
	GPIO->tGPIO_AFIO_1.tBit.GPA18 = 0x1; // 0:GPIO, 1:MSPI4_MST_MOSI
	GPIO->tGPIO_AFIO_1.tBit.GPA19 = 0x1; // 0:GPIO, 1:MSPI4_MST_MISO
#else /* MSPI_GPIO_SRIC4_EN */
	/*
	 * 55555 PANNEL SRIC 2
	 */
	GPIO->tGPIO_AFIO_1.tBit.GPA16 = 0x0; // 0:GPIO, 1:MSPI4_MST_SSN
	GPIO->tGPIO_AFIO_1.tBit.GPA17 = 0x0; // 0:GPIO, 1:MSPI4_MST_SCLK
	GPIO->tGPIO_AFIO_1.tBit.GPA18 = 0x0; // 0:GPIO, 1:MSPI4_MST_MOSI
	GPIO->tGPIO_AFIO_1.tBit.GPA19 = 0x0; // 0:GPIO, 1:MSPI4_MST_MISO

	GPIO->tGPIO_DIR_0.tBit.GPA16 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DIR_0.tBit.GPA17 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DIR_0.tBit.GPA18 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DIR_0.tBit.GPA19 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_DATA_0.tBit.GPA16 = 0x0; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DATA_0.tBit.GPA17 = 0x0; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DATA_0.tBit.GPA18 = 0x0; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DATA_0.tBit.GPA19 = 0x0; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_PD_0.tBit.GPA16 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_PD_0.tBit.GPA17 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_PD_0.tBit.GPA18 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_PD_0.tBit.GPA19 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
#endif /* MSPI_GPIO_SRIC4_EN */

#if MSPI_GPIO_SRIC5_EN
	/*
	 * 6666 PANNEL SRIC 3
	 */
	GPIO->tGPIO_AFIO_1.tBit.GPA20 = 0x1; // 0:GPIO, 1:MSPI5_MST_SSN
	GPIO->tGPIO_AFIO_1.tBit.GPA21 = 0x1; // 0:GPIO, 1:MSPI5_MST_SCLK
	GPIO->tGPIO_AFIO_1.tBit.GPA22 = 0x1; // 0:GPIO, 1:MSPI5_MST_MOSI
	GPIO->tGPIO_AFIO_1.tBit.GPA23 = 0x1; // 0:GPIO, 1:MSPI5_MST_MISO
#else /* MSPI_GPIO_SRIC5_EN */
	/*
	 * 6666 PANNEL SRIC 3
	 */
	GPIO->tGPIO_AFIO_1.tBit.GPA20 = 0x0; // 0:GPIO, 1:MSPI5_MST_SSN
	GPIO->tGPIO_AFIO_1.tBit.GPA21 = 0x0; // 0:GPIO, 1:MSPI5_MST_SCLK
	GPIO->tGPIO_AFIO_1.tBit.GPA22 = 0x0; // 0:GPIO, 1:MSPI5_MST_MOSI
	GPIO->tGPIO_AFIO_1.tBit.GPA23 = 0x0; // 0:GPIO, 1:MSPI5_MST_MISO

	GPIO->tGPIO_DIR_0.tBit.GPA20 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DIR_0.tBit.GPA21 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DIR_0.tBit.GPA22 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DIR_0.tBit.GPA23 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_DATA_0.tBit.GPA20 = 0x0; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_DATA_0.tBit.GPA21 = 0x0; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_DATA_0.tBit.GPA22 = 0x0; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_DATA_0.tBit.GPA23 = 0x0; // 0:GPIO, 1:MSPI1_MST_MISO

	GPIO->tGPIO_PD_0.tBit.GPA20 = 0x1; // 0:GPIO, 1:MSPI1_MST_SSN
	GPIO->tGPIO_PD_0.tBit.GPA21 = 0x1; // 0:GPIO, 1:MSPI1_MST_SCLK
	GPIO->tGPIO_PD_0.tBit.GPA22 = 0x1; // 0:GPIO, 1:MSPI1_MST_MOSI
	GPIO->tGPIO_PD_0.tBit.GPA23 = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
#endif /* MSPI_GPIO_SRIC5_EN */


	GPIO->tGPIO_PU_0._GPIO_MSPI_0_MISO = 0x0;
	GPIO->tGPIO_PU_0._GPIO_MSPI_1_MISO = 0x0;
	GPIO->tGPIO_PU_0._GPIO_MSPI_2_MISO = 0x0;
	GPIO->tGPIO_PU_0._GPIO_MSPI_3_MISO = 0x0;
	GPIO->tGPIO_PU_0._GPIO_MSPI_4_MISO = 0x0;
	GPIO->tGPIO_PU_0._GPIO_MSPI_5_MISO = 0x0;
//
	GPIO->tGPIO_PD_0._GPIO_MSPI_0_MISO = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
	GPIO->tGPIO_PD_0._GPIO_MSPI_1_MISO = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
	GPIO->tGPIO_PD_0._GPIO_MSPI_2_MISO = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
	GPIO->tGPIO_PD_0._GPIO_MSPI_3_MISO = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
	GPIO->tGPIO_PD_0._GPIO_MSPI_4_MISO = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO
	GPIO->tGPIO_PD_0._GPIO_MSPI_5_MISO = 0x1; // 0:GPIO, 1:MSPI1_MST_MISO

// {P2,P1} = Drive Strength

	GPIO->tGPIO_P1_0._GPIO_MSPI_0_CSN = MSPI_DRIVING_STRANGTH_CSN_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_0_SCLK = MSPI_DRIVING_STRANGTH_SCLK_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_0_MOSI =MSPI_DRIVING_STRANGTH_MOSI_0;
	GPIO->tGPIO_P2_0._GPIO_MSPI_0_CSN =MSPI_DRIVING_STRANGTH_CSN_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_0_SCLK =MSPI_DRIVING_STRANGTH_SCLK_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_0_MOSI = MSPI_DRIVING_STRANGTH_MOSI_1;
	

	GPIO->tGPIO_P1_0._GPIO_MSPI_1_CSN = MSPI_DRIVING_STRANGTH_CSN_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_1_SCLK = MSPI_DRIVING_STRANGTH_SCLK_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_1_MOSI = MSPI_DRIVING_STRANGTH_MOSI_0;
	GPIO->tGPIO_P2_0._GPIO_MSPI_1_CSN = MSPI_DRIVING_STRANGTH_CSN_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_1_SCLK = MSPI_DRIVING_STRANGTH_SCLK_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_1_MOSI = MSPI_DRIVING_STRANGTH_MOSI_1;

	GPIO->tGPIO_P1_0._GPIO_MSPI_2_CSN = MSPI_DRIVING_STRANGTH_CSN_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_2_SCLK = MSPI_DRIVING_STRANGTH_SCLK_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_2_MOSI = MSPI_DRIVING_STRANGTH_MOSI_0;
	GPIO->tGPIO_P2_0._GPIO_MSPI_2_CSN = MSPI_DRIVING_STRANGTH_CSN_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_2_SCLK = MSPI_DRIVING_STRANGTH_SCLK_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_2_MOSI = MSPI_DRIVING_STRANGTH_MOSI_1;

	/*
	 *
	 */
	GPIO->tGPIO_P1_0._GPIO_MSPI_3_CSN =  MSPI_DRIVING_STRANGTH_CSN_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_3_SCLK = MSPI_DRIVING_STRANGTH_SCLK_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_3_MOSI = MSPI_DRIVING_STRANGTH_MOSI_0;
	GPIO->tGPIO_P2_0._GPIO_MSPI_3_CSN =  MSPI_DRIVING_STRANGTH_CSN_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_3_SCLK = MSPI_DRIVING_STRANGTH_SCLK_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_3_MOSI = MSPI_DRIVING_STRANGTH_MOSI_1;

	GPIO->tGPIO_P1_0._GPIO_MSPI_4_CSN = MSPI_DRIVING_STRANGTH_CSN_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_4_SCLK = MSPI_DRIVING_STRANGTH_SCLK_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_4_MOSI = MSPI_DRIVING_STRANGTH_MOSI_0;
	GPIO->tGPIO_P2_0._GPIO_MSPI_4_CSN = MSPI_DRIVING_STRANGTH_CSN_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_4_SCLK = MSPI_DRIVING_STRANGTH_SCLK_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_4_MOSI = MSPI_DRIVING_STRANGTH_MOSI_1;

	GPIO->tGPIO_P1_0._GPIO_MSPI_5_CSN = MSPI_DRIVING_STRANGTH_CSN_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_5_SCLK = MSPI_DRIVING_STRANGTH_SCLK_0;
	GPIO->tGPIO_P1_0._GPIO_MSPI_5_MOSI = MSPI_DRIVING_STRANGTH_MOSI_0;
	GPIO->tGPIO_P2_0._GPIO_MSPI_5_CSN = MSPI_DRIVING_STRANGTH_CSN_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_5_SCLK = MSPI_DRIVING_STRANGTH_SCLK_1;
	GPIO->tGPIO_P2_0._GPIO_MSPI_5_MOSI = MSPI_DRIVING_STRANGTH_MOSI_1;


//	GPIO->tGPIO_P1_0.tBit.GPA04 = 0x0;
//	GPIO->tGPIO_P1_0.tBit.GPA05 = 0x0;
//	GPIO->tGPIO_P1_0.tBit.GPA06 = 0x0;
//
//	GPIO->tGPIO_P2_0.tBit.GPA04 = 0x0;
//	GPIO->tGPIO_P2_0.tBit.GPA05 = 0x1;
//	GPIO->tGPIO_P2_0.tBit.GPA06 = 0x1;
//
//	GPIO->tGPIO_P1_0.tBit.GPA08 = 0x0;
//	GPIO->tGPIO_P1_0.tBit.GPA09 = 0x0;
//	GPIO->tGPIO_P1_0.tBit.GPA09 = 0x0;
//
//	GPIO->tGPIO_P2_0.tBit.GPA08 = 0x0;
//	GPIO->tGPIO_P2_0.tBit.GPA09 = 0x1;
//	GPIO->tGPIO_P2_0.tBit.GPA10 = 0x1;
//
//	GPIO->tGPIO_P1_0.tBit.GPA12 = 0x0;
//	GPIO->tGPIO_P1_0.tBit.GPA13 = 0x0;
//	GPIO->tGPIO_P1_0.tBit.GPA14 = 0x0;
//
//	GPIO->tGPIO_P2_0.tBit.GPA12 = 0x0;
//	GPIO->tGPIO_P2_0.tBit.GPA13 = 0x1;
//	GPIO->tGPIO_P2_0.tBit.GPA14 = 0x1;
//
//	GPIO->tGPIO_P1_0.tBit.GPA16 = 0x0;
//	GPIO->tGPIO_P1_0.tBit.GPA17 = 0x0;
//	GPIO->tGPIO_P1_0.tBit.GPA18 = 0x0;
//
//	GPIO->tGPIO_P2_0.tBit.GPA16 = 0x0;
//	GPIO->tGPIO_P2_0.tBit.GPA17 = 0x1;
//	GPIO->tGPIO_P2_0.tBit.GPA18 = 0x1;
//
//	GPIO->tGPIO_P1_0.tBit.GPA20 = 0x0;
//	GPIO->tGPIO_P1_0.tBit.GPA21 = 0x0;
//	GPIO->tGPIO_P1_0.tBit.GPA22 = 0x0;
//
//	GPIO->tGPIO_P2_0.tBit.GPA20 = 0x0;
//	GPIO->tGPIO_P2_0.tBit.GPA21 = 0x1;
//	GPIO->tGPIO_P2_0.tBit.GPA22 = 0x1;
}
