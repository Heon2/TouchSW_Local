/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : mspi_.h
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

#ifndef _MSPI__H_
#define _MSPI__H_


//----------------------------------------------------------------------------------------------
// SPI CR register setting parameters
//----------------------------------------------------------------------------------------------
#define bitLen8			(0)
#define bitLen10		(1)
#define bitLen12		(2)
#define bitLen16		(3)
#define mosiOutEn		(1)
#define mosiOutDis		(0)
#define CphaIs0			(0)
#define CphaIs1			(1)
#define CpolIs0			(0)
#define CpolIs1			(1)
#define spiMstMode		(1)
#define spiSlvMode		(0)
#define LsbFirst		(1)
#define MsbFirst		(0)
#define spiEna			(1)
#define spiDis			(0)

//----------------------------------------------------------------------------------------------
// SPI FIFO CR register setting parameters
//----------------------------------------------------------------------------------------------
#define FifoTxClr		(1)
#define FifoTxLet		(0)
#define FifoRxClr		(1)
#define FifoRxLet		(0)
#define FifoRxWmLv31	(31)
#define FifoRxWmLv16	(16)
#define FifoRxWmLv08	(8)
#define FifoRxWmLv02	(2)
#define FifoRxWmLv01	(1)
#define FifoRxWmLv00	(0)
#define FifoTxWmLv31	(31)
#define FifoTxWmLv16	(16)
#define FifoTxWmLv08 	(8)
#define FifoTxWmLv02 	(2)
#define FifoTxWmLv01 	(1)
#define FifoTxWmLv00 	(0)
#define FifoTxDmaEna 	(1)
#define FifoTxDmaDis 	(0)
#define FifoRxDmaEna 	(1)
#define FifoRxDmaDis 	(0)
#define FifoTxErrClr 	(1)
#define FifoTxErrLet 	(0)
#define FifoRxErrClr 	(1)
#define FifoRxErrLet 	(0)

//----------------------------------------------------------------------------------------------
// SPI Enalbe & Transfer Size register setting parameters
//----------------------------------------------------------------------------------------------
#define spi0TxEna 		(1)
#define spi1TxEna 		(1)
#define spi2TxEna 		(1)
#define spi3TxEna 		(1)
#define spi4TxEna 		(1)
#define spi5TxEna 		(1)

#define spi0TxDis 		(0)
#define spi1TxDis 		(0)
#define spi2TxDis 		(0)
#define spi3TxDis 		(0)
#define spi4TxDis 		(0)
#define spi5TxDis 		(0)

#define spi0RxEna 		(1)
#define spi1RxEna 		(1)
#define spi2RxEna 		(1)
#define spi3RxEna 		(1)
#define spi4RxEna 		(1)
#define spi5RxEna 		(1)

#define spi0RxDis 		(0)
#define spi1RxDis 		(0)
#define spi2RxDis 		(0)
#define spi3RxDis 		(0)
#define spi4RxDis 		(0)
#define spi5RxDis 		(0)

#define TxEna0 			(1)
#define TxEna1 			(1)
#define TxEna2 			(1)
#define TxEna3 			(1)
#define TxEna4 			(1)
#define TxEna5 			(1)

#define TxDis0 			(0)
#define TxDis1 			(0)
#define TxDis2 			(0)
#define TxDis3 			(0)
#define TxDis4 			(0)
#define TxDis5 			(0)

#define RxEna0 			(1)
#define RxEna1 			(1)
#define RxEna2 			(1)
#define RxEna3 			(1)
#define RxEna4 			(1)
#define RxEna5 			(1)

#define RxDis0 			(0)
#define RxDis1 			(0)
#define RxDis2 			(0)
#define RxDis3 			(0)
#define RxDis4 			(0)
#define RxDis5 			(0)

#define spi0TrSze 		(8)
#define spi1TrSze 		(8)
#define spi2TrSze 		(8)
#define spi3TrSze 		(8)
#define spi4TrSze 		(8)
#define spi5TrSze 		(8)

//----------------------------------------------------------------------------------------------
// SPI Each State length setting parameters
//----------------------------------------------------------------------------------------------
#define spiPreShftLenIs2  		(2)
#define spiTmpIdleLenIs2  		(2)
#define spiPostShftLenIs2 		(2)
#define spiPostShftLenIs4 		(4)
#define spiPostShftLenIs5 		(5)
#define spiPostShftLenIs6 		(6)
#define spiPostShftLenIs8 		(8)
#define spiPostShftLenIsF 		(15)
#define spiSnglIdleLenIs2 		(2)
#define spiAitIdleLenIs2 		(2)
#define spiAitIdleLenIs8 		(8)
#define spiAitIdleLenIs9 		(9)

//----------------------------------------------------------------------------------------------
// SPI Operation Start Command register setting 
//----------------------------------------------------------------------------------------------
#define spiStartAll 			(63)
#define spiStart0 				(1)
#define spiStart1 				(2)
#define spiStart2 				(4)
#define spiStart3 				(8)
#define spiStart4 				(16)
#define spiStart5 				(32)

//----------------------------------------------------------------------------------------------
// SPI Operation Mode register setting 
//----------------------------------------------------------------------------------------------
#define spiTlpMode 				0
#define spiAitMode 				1
#define spiFifoMode 0
#define spiSramMode 1
#define spiSwMode 0
#define spiHwMode 1
#define spiSnglMode 1
#define spiBrstMode 1
#define spiSramNormMode 0
#define spiSramDebugMode 1
#define spiSramWrDefault 0
#define spiSramWrOpt 1
#define spiTrsPerWr0 0
#define spiTrsPerWr1 1
#define spiTrsPerWr2 2
#define spiTrsPerRd0 0
#define spiTrsPerRd1 1
#define spiTrsPerRd2 2
#define spiPwfe0Sel 0
#define spiPwfe1Sel 1
#define spiPwfe2Sel 2
#define spiPwfe3Sel 3
#define spiPwfe4Sel 4
#define spiPwfe5Sel 5
#define spiCommPwfeSel 1
#define spiEachPwfeSel 0
#define spiNonProtocol 0
#define spiTlpProtocol 1
#define spiHatProtocol 2
#define spiRdHlfWrdLsbFrst 0
#define spiRdHlfWrdMsbFrst 1
#define spiWrHlfWrdLsbFrst 0
#define spiWrHlfWrdMsbFrst 1

//----------------------------------------------------------------------------------------------
// SPI example pattern for Optional Write Mode
//----------------------------------------------------------------------------------------------
#define spiStrtWAd0 7
#define spiStrtWAd1 115
#define spiStrtWAd2 231
#define spiStrtWAd3 364
#define spiStrtWAd4 528
#define spiStrtWAd5 755

#define spiStrtRAd0 1007
#define spiStrtRAd1 1115
#define spiStrtRAd2 1231
#define spiStrtRAd3 1364
#define spiStrtRAd4 1528
#define spiStrtRAd5 1755

#define spiStrtDin0 99
#define spiStrtDin1 55
#define spiStrtDin2 33
#define spiStrtDin3 66
#define spiStrtDin4 1010
#define spiStrtDin5 1212

//----------------------------------------------------------------------------------------------
// SPI Interrupt Masking register setting
//----------------------------------------------------------------------------------------------
#define IntrAitWlvEna 1
#define IntrAitWlvDis 0
#define IntrMemEna 1
#define IntrMemDis 0
#define IntrRoriEna 1
#define IntrRoriDis 0
#define IntrToriEna 1
#define IntrToriDis 0
#define IntrRxuriEna 1
#define IntrRxuriDis 0
#define IntrTxuriEna 1
#define IntrTxuriDis 0
#define IntrRxiEna 1
#define IntrRxiDis 0
#define IntrTxiEna 1
#define IntrTxiDis 0

//----------------------------------------------------------------------------------------------
// TLP/HAT SPIS regiser setting             
//----------------------------------------------------------------------------------------------
#define SensBase 0
#define RefrBase 4
#define CfgrBase 8
#define TlpWrite 0
#define TlpRead  1
#define TlpBulk  0
#define TlpSngl  1 

#define HatSensBase 0
#define HatRefrBase 4
#define HatCfgrBase 8
#define HatWrite 0
#define HatRead  1
#define HatBulk  0
#define HatSngl  1 

#define TlpAddr0 0 
#define TlpAddr2 2 
#define TlpAddr4 4 
#define TlpAddr6 6 

#define TlpAddr8 8 
#define TlpAddrA 10 
#define TlpAddrC 12 
#define TlpAddrE 14 

#define HatAddr0 0 
#define HatAddr2 2 
#define HatAddr4 4 
#define HatAddr6 6 

#define HatAddr8 8 
#define HatAddrA 10 
#define HatAddrC 12 
#define HatAddrE 14

#define TlpWDat0 0

#define HatWDat0 0

//#define HatIndvl 8'h40
//#define HatIndvl 8'h41


#define spiAitWlvEna 1
#define spiAitWlvDis 0
#define spiAitWlvSel0 0
#define spiAitWlvSel1 1
#define spiAitWlvSel2 2
#define spiAitWlvSel3 3
#define spiAitWlvSel4 4
#define spiAitWlvSel5 5

#define AitDmyDelEna 1
#define AitDmyDelDis 0

//----------------------------------------------------------------------------------------------
// RAIT SPIS regiser setting             
//----------------------------------------------------------------------------------------------
#define AlgnLbuf 0
#define Ait0Lbuf 1
#define Ait1Lbuf 2
#define AitCfgr0 3
#define AitCfgr1 4

#define AitWrite 0
#define AitRead  1
#define AitBulk  0
#define AitSngl  1 

#define AitAddr0 0 
#define AitAddr2 2 
#define AitAddr4 4 
#define AitAddr6 6 

#define MdIdle   0
#define SnrStr   2
#define MdGnrl   4
#define AipAdc   6
#define SsuCtrl  8
#define TsyncNum0 10
#define TsyncNum1 12
#define TsyncDmy1 14
#define PwmNum0   16
#define PwmNum1   18 
#define CmuxNrm   20 
#define CmuxNse   22 
//#define ColNum    24 
//#define RowNum    26 
#define DigGain0  28 
#define DigGain1  30 
#define NihMin0   32 
#define NihMax0   34 
#define NihMin1   36 
#define NihMax1   38 
#define NihMin2   40 
#define NihMax2   42 
#define NihMin3   44 
#define NihMax3   46 
#define NihRdat0  48 
#define NihRdat1  50 
#define NihRdat2  52 
#define NihRdat3  54 
#define MdSpcl    56 
#define ShaStr0   58 
#define ShaStr1   60 
#define ShaStr2   62 
#define VcrStr    64 
#define VcrNum0   66 
#define VcrNum1   68 
#define VcrNum2   70 
#define VcrNum3   72 
#define VcrNum4   74 
#define VcrNum5   76 

#define StrTsync0Is0 0 
#define EndTsync0Is1 1 
#define StrTsync1Is0 0 
#define EndTsync1Is1 1 
#define DmyTsync1Is0 0 
#define ChMxIntvlIs8 8 
#define PrePwmNumIs5 5 
#define SetPwmNumIs1 1 
#define ActPwmNumIs20 20 
#define DinPwmNumIs4 4 
#define StrCmxNumIs0 0 
#define EndCmxNumIs15 15 
#define Ni1CmxNumIs8 8 
#define Ni2CmxNumIs8 8 
#define StrColNumIs0 0 
#define EndColNumIs6 6 
#define EndColNumIs19 19 
#define ColLen0IsIs7 7 
#define ColLen1IsIs7 7 
#define ColLen0Is15 15 
#define ColLen1Is15 15 
#define ColLen0Is20 20 
#define ColLen1Is20 20 
#define EndRowNumIs49 49 
#define TopOuterEna  1 
#define TopOuterDis  0 
#define BotOuterEna  1 
#define BotOuterDis  0 
#define LefOuterEna  1 
#define LefOuterDis  0 
#define RghtOuterEna  1 
#define RghtOuterDis  0 


#endif /* _MSPI__H_ */
