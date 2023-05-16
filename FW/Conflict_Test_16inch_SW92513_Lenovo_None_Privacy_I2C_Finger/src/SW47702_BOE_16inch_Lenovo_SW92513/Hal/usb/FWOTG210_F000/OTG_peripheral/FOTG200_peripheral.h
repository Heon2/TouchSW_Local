#ifndef _FOTG200_PERIPHERAL_H_
#define _FOTG200_PERIPHERAL_H_

#include "env_def.h"
#include "SIW47701_Version.h"
#include "timer_tick.h"


	//#define IRQ_FOTG200 					40	//27
	#define FOTG200_BASE_ADDRESS			BASE_USB_SRAM
//========== 1.Define Data Type  =========================================================================================
//	typedef unsigned char BOOLEAN;
//	typedef unsigned char uint8_t;		/* 1 byte */
//	typedef unsigned short uint16_t;		/* 2 bytes */
//	typedef unsigned int uint32_t;		/* 4 bytes */
//	typedef unsigned long long UINT64;  /* 8 bytes */
//	typedef signed char int8_t;			/* 1 byte */
//	typedef signed short int16_t;		/* 2 bytes */
//	typedef signed int int32_t;			/* 4 bytes */

	#define FEATURELIST__COMMAND_FEATURE 		(1 << 0)
	#define FEATURELIST__READYSTATUS_INTERRUPT 	(1 << 1)
	#define FEATURELIST__RESERVED_1 			(0 << 2)
	#define FEATURELIST__RESERVED_2 			(0 << 3)
	#define FEATURELIST__RESERVED_3 			(0 << 4)
	#define FEATURELIST__RESERVED_4 			(0 << 5)
	#define FEATURELIST__RESERVED_5 			(0 << 6)
	#define FEATURELIST__RESERVED_6 			(0 << 7)
	#define MESS_ERROR		(0x01 << 0)
	#define MESS_WARNING	(0x01 << 1)
	#define MESS_INFO		(0x01 << 2)

	// Macro
	#define bFOTGPeri_Port(bOffset)		*((volatile uint8_t*) ( FOTG200_BASE_ADDRESS | (bOffset)))
	#define hwFOTGPeri_Port(bOffset)	*((volatile uint16_t *) ( FOTG200_BASE_ADDRESS | (bOffset)))
	#define wFOTGPeri_Port(bOffset)		*((volatile uint32_t *) ( FOTG200_BASE_ADDRESS | (bOffset)))

	// Remote Wakeup
	#define REMOTE_WAKEUP_ADDR				0x400000A4UL
	#define REMOTE_WAKEUP_Port(bOffset)		*((volatile uint8_t*) ( REMOTE_WAKEUP_ADDR | (bOffset)))
	#define mUsbRemoteWakeUpST()			(REMOTE_WAKEUP_Port(0x00) & BIT1)
	#define mUsbRemoteWakeUpSet_1()			(REMOTE_WAKEUP_Port(0x00) |= BIT1)
	#define mUsbRemoteWakeUpSet_0()			(REMOTE_WAKEUP_Port(0x00) &= ~BIT1)

	// Mask of LPM L1
	#define mUsbL1IntEn()					(wFOTGPeri_Port(0x33C) &= ~BIT0)
	#define mUsbL1IntDis()					(wFOTGPeri_Port(0x33C) |= BIT0)

	// Interrupt LPM
	#define mUsbL1IntST()					(wFOTGPeri_Port(0x338) & BIT0)
	#define mUsbL1IntClr()					(wFOTGPeri_Port(0x338) |= BIT0)
	#define mUsbLPMCap()					(wFOTGPeri_Port(0x334) & BIT0)
	

	#define mUsbIntPolarityLow()	(wFOTGPeri_Port(0xC4) &= ~BIT3)
	#define mUsbIntPolarityHigh()	(wFOTGPeri_Port(0xC4) & BIT3)

	// Main control register(0x100)
	#define mUsbRmWkupST()			(wFOTGPeri_Port(0x100) & BIT0)
	#define mUsbRmWkupSet()		    (wFOTGPeri_Port(0x100) |= BIT0)
	#define mUsbRmWkupClr()			(wFOTGPeri_Port(0x100) &= ~BIT0)
	
	#define mUsbTstHalfSpeedEn()	(wFOTGPeri_Port(0x100) |= BIT1)
	#define mUsbTstHalfSpeedDis()	(wFOTGPeri_Port(0x100) &= ~BIT1)

	#define mUsbGlobIntEnRd()		(wFOTGPeri_Port(0x100) & BIT2)
	#define mUsbGlobIntEnSet()		(wFOTGPeri_Port(0x100) |= BIT2)
	#define mUsbGlobIntDis()		(wFOTGPeri_Port(0x100) &= ~BIT2)
	
	#define mUsbGoSuspend()			(wFOTGPeri_Port(0x100) |=  BIT3)
	#define mUsbClearSuspend()		(wFOTGPeri_Port(0x100) &=  ~BIT3)
	
	#define mUsbSoftRstStatus()		(wFOTGPeri_Port(0x100) &  BIT4)	
	#define mUsbSoftRstSet()		(wFOTGPeri_Port(0x100) |=  BIT4)
	#define mUsbSoftRstClr()		(wFOTGPeri_Port(0x100) &= ~BIT4)

	#define mUsbChipEnSet()			(wFOTGPeri_Port(0x100) |= BIT5)
	
	#define mUsbOTGHighSpeedST()	(wFOTGPeri_Port(0x100) & BIT6)
	#define mUsbOTGDevFS()			(wFOTGPeri_Port(0x100) |= BIT9)	
	#define mUsbOTGDevHS()			(wFOTGPeri_Port(0x100) &= ~BIT9)


	#define mUsbLPMEn()				(wFOTGPeri_Port(0x100) |= BIT25)
	#define mUsbLPMDis()			(wFOTGPeri_Port(0x100) &= ~BIT25)

	#define mUsbLPMAck()			(wFOTGPeri_Port(0x100) |= BIT26)
	#define mUsbLPMNyet()			(wFOTGPeri_Port(0x100) &= ~BIT25)

	// Device address register(0x104)
	#define mUsbDevAddrSet(Value)	(wFOTGPeri_Port(0x104) = (uint32_t)Value)
	#define mUsbCfgST()				(wFOTGPeri_Port(0x104) & BIT7)
	#define mUsbCfgSet()			(wFOTGPeri_Port(0x104) |= BIT7)
	#define mUsbCfgClr()			(wFOTGPeri_Port(0x104) &= ~BIT7)
	
	// old DMA ///////////////////////
    #define mUsbDMARst()            { (wFOTGPeri_Port(0x1c8) = 0); (wFOTGPeri_Port(0x1c8) = BIT3); }	
    // VDMA //////////////////////////
    #define mUsbCXDMARst()          (wFOTGPeri_Port(0x300) = 0)    
    #define mUsbEXDMARst(i)         (wFOTGPeri_Port(0x308+i*8) = 0)  
        
                         //(wFOTGPeri_Port(0x100) |= BIT8)
    #define mUsbFIFOClr(fifo_num)   (wFOTGPeri_Port(0x1b0+fifo_num*4) |= BIT12)

	// Test register(0x108)
	#define mUsbClrAllFIFOSet()		(wFOTGPeri_Port(0x108) |= BIT0)
	#define mUsbClrAllFIFOClr()		(wFOTGPeri_Port(0x108) &= ~BIT0)

	// SOF Frame Number register(0x10C)
	#define mUsbFrameNo()			(uint16_t)(wFOTGPeri_Port(0x10C) & 0x7FF)
	#define mUsbMicroFrameNo()		(uint8_t)((wFOTGPeri_Port(0x10C) & 0x3800)>>11)

	// SOF Mask register(0x110)
	#define mUsbSOFMaskHS()		    (wFOTGPeri_Port(0x110) = 0x44c)
	#define mUsbSOFMaskFS()		    (wFOTGPeri_Port(0x110) = 0x2710)

	// PHY Test Mode Selector register(0x114)
	#define mUsbTsMdWr(item)		(wFOTGPeri_Port(0x114) = (uint32_t)item)
	#define mUsbUnPLGClr()			(wFOTGPeri_Port(0x114) &= ~BIT0)
	#define mUsbUnPLGSet()			(wFOTGPeri_Port(0x114) |= BIT0)
	// Vendor Specific IO Control register(0x118)

	// Cx configuration and status register(0x11C)

	// Cx configuration and FIFO Empty Status register(0x120)
	#define mUsbEP0DoneSet()		(wFOTGPeri_Port(0x120) |= BIT0)
	#define mUsbTsPkDoneSet()		(wFOTGPeri_Port(0x120) |= BIT1)
	#define mUsbEP0StallSet()		(wFOTGPeri_Port(0x120) |= BIT2)
	#define mUsbCxFClr()			(wFOTGPeri_Port(0x120) |= BIT3)

	#define mUsbCxFFull()			(wFOTGPeri_Port(0x120) & BIT4)
	#define mUsbCxFEmpty()			(wFOTGPeri_Port(0x120) & BIT5)
	#define mUsbCxFByteCnt()		(uint8_t)((wFOTGPeri_Port(0x120) & 0x7F000000)>>24)
	
	// IDLE Counter register(0x124)
	#define mUsbIdleCnt(time)		(wFOTGPeri_Port(0x124) = (uint32_t)time)

	// Mask of interrupt group(0x130)
	#define mUsbIntGrp0Dis()		(wFOTGPeri_Port(0x130) |= BIT0)
	#define mUsbIntGrp1Dis()		(wFOTGPeri_Port(0x130) |= BIT1)
	#define mUsbIntGrp2Dis()		(wFOTGPeri_Port(0x130) |= BIT2)
	#define mUsbIntGrp3Dis()		(wFOTGPeri_Port(0x130) |= BIT3)  //VDMA

	#define mUsbIntGroupMaskRd()	(wFOTGPeri_Port(0x130))
	
	// Mask of interrupt source group 0(0x134)
	#define mUsbIntEP0SetupDis()	(wFOTGPeri_Port(0x134) |= BIT0)
	#define mUsbIntEP0InDis()		(wFOTGPeri_Port(0x134) |= BIT1)
	#define mUsbIntEP0OutDis()		(wFOTGPeri_Port(0x134) |= BIT2)
	#define mUsbIntEP0EndDis()		(wFOTGPeri_Port(0x134) |= BIT3)
	#define mUsbIntEP0FailDis()		(wFOTGPeri_Port(0x134) |= BIT4)

	#define mUsbIntEP0SetupEn()		(wFOTGPeri_Port(0x134) &= ~(BIT0))
	#define mUsbIntEP0InEn()			(wFOTGPeri_Port(0x134) &= ~(BIT1))
	#define mUsbIntEP0OutEn()		(wFOTGPeri_Port(0x134) &= ~(BIT2))
	#define mUsbIntEP0EndEn()		(wFOTGPeri_Port(0x134) &= ~(BIT3))
	#define mUsbIntEP0FailEn()		(wFOTGPeri_Port(0x134) &= ~(BIT4))

	#define mUsbIntSrc0MaskRd()		(wFOTGPeri_Port(0x134))
	
	// Mask of interrupt source group 1(0x138)
	#define mUsbIntFIFO0_3OUTDis()	(wFOTGPeri_Port(0x138) |= 0xFF)
	#define mUsbIntFIFO0_3INDis()	(wFOTGPeri_Port(0x138) |= 0xF0000)
	
	#define mUsbIntF0OUTEn()		(wFOTGPeri_Port(0x138) &= ~(BIT1 | BIT0))	
	#define mUsbIntF0OUTDis()		(wFOTGPeri_Port(0x138) |= (BIT1 | BIT0))	
	#define mUsbIntF1OUTEn()		(wFOTGPeri_Port(0x138) &= ~(BIT3 | BIT2))
	#define mUsbIntF1OUTDis()		(wFOTGPeri_Port(0x138) |= (BIT3 | BIT2))
	#define mUsbIntF2OUTEn()		(wFOTGPeri_Port(0x138) &= ~(BIT5 | BIT4))
	#define mUsbIntF2OUTDis()		(wFOTGPeri_Port(0x138) |= (BIT5 | BIT4))
	#define mUsbIntF0INEn()			(wFOTGPeri_Port(0x138) &= ~BIT16)
	#define mUsbIntF0INDis()		(wFOTGPeri_Port(0x138) |= BIT16)
	#define mUsbIntF3OUTEn()		(wFOTGPeri_Port(0x138) &= ~(BIT7 | BIT6))
	#define mUsbIntF3OUTDis()		(wFOTGPeri_Port(0x138) |= (BIT7 | BIT6))

	#define mUsbIntF0INEn()			(wFOTGPeri_Port(0x138) &= ~BIT16)
	#define mUsbIntF0INDis()		(wFOTGPeri_Port(0x138) |= BIT16)
	#define mUsbIntF1INEn()			(wFOTGPeri_Port(0x138) &= ~BIT17)
	#define mUsbIntF1INDis()		(wFOTGPeri_Port(0x138) |= BIT17)
	#define mUsbIntF2INEn()			(wFOTGPeri_Port(0x138) &= ~BIT18)
	#define mUsbIntF2INDis()		(wFOTGPeri_Port(0x138) |= BIT18)
	#define mUsbIntF3INEn()			(wFOTGPeri_Port(0x138) &= ~BIT19)
	#define mUsbIntF3INDis()		(wFOTGPeri_Port(0x138) |= BIT19)


	#define mUsbIntSrc1MaskRd()		(wFOTGPeri_Port(0x138))
	
	// Mask of interrupt source group 2(DMA int mask)(0x13C)
	#define mUsbIntSuspDis()		(wFOTGPeri_Port(0x13C) |= BIT1)		
	#define mUsbIntDmaErrDis()		(wFOTGPeri_Port(0x13C) |= BIT8)
	#define mUsbIntDmaFinishDis()	(wFOTGPeri_Port(0x13C) |= BIT7)
	#define mUsbIntWakebyVbusDis()	(wFOTGPeri_Port(0x13C) |= BIT10)
	#define mUsbIntDevIdleDis()	    (wFOTGPeri_Port(0x13C) |= BIT9)	

	#define mUsbIntSuspEn()			(wFOTGPeri_Port(0x13C) &= ~(BIT1))		
	#define mUsbIntDmaErrEn()		(wFOTGPeri_Port(0x13C) &= ~(BIT8))
	#define mUsbIntDmaFinishEn()	(wFOTGPeri_Port(0x13C) &= ~(BIT7))
	#define mUsbIntWakebyVbusEn()	(wFOTGPeri_Port(0x13C) &= ~(BIT10))	
	#define mUsbIntDevIdleEn()	    (wFOTGPeri_Port(0x13C) &= ~(BIT9))		

	#define mUsbIntSrc2MaskRd()		(wFOTGPeri_Port(0x13C))

    // VDMA ////////////////////////////////////////////////////////////	
	#define mUsbEXIntDmaErrDis(i)	 (wFOTGPeri_Port(0x32C) |= (BIT17<<i))
	#define mUsbEXIntDmaFinishDis(i) (wFOTGPeri_Port(0x32C) |= (BIT1<<i))
	#define mUsbCXIntDmaErrDis()	 (wFOTGPeri_Port(0x32C) |= BIT16)
	#define mUsbCXIntDmaFinishDis()	 (wFOTGPeri_Port(0x32C) |= BIT0)
		
	#define mUsbEXIntDmaErrEn(i)	 (wFOTGPeri_Port(0x32C) &= ~(BIT17<<i))
	#define mUsbEXIntDmaFinishEn(i)	 (wFOTGPeri_Port(0x32C) &= ~(BIT1<<i))
	#define mUsbCXIntDmaErrEn()		 (wFOTGPeri_Port(0x32C) &= ~(BIT16))
	#define mUsbCXIntDmaFinishEn()	 (wFOTGPeri_Port(0x32C) &= ~(BIT0))		

	#define mUsbIntSrc3MaskRd()		(wFOTGPeri_Port(0x32C))    
    //////////////////////////////////////////////////////////////////

	// Interrupt group (0x140)
	#define mUsbIntGroupRegRd()		(wFOTGPeri_Port(0x140))
	#define mUsbIntGroupRegSet(wValue)	(wFOTGPeri_Port(0x140) |= wValue)
	
	// Interrupt source group 0(0x144)
	#define mUsbIntSrc0Rd()			(wFOTGPeri_Port(0x144))	
#if 1	
	#define mUsbIntEP0AbortClr()		(wFOTGPeri_Port(0x144) = BIT5)	
#else	
	#define mUsbIntEP0AbortClr()		(wFOTGPeri_Port(0x144) &= ~(BIT5))		
#endif	
	#define mUsbIntSrc0Clr()			(wFOTGPeri_Port(0x144) = 0)
	#define mUsbIntSrc0Set(wValue)	(wFOTGPeri_Port(0x144) |= wValue)
	
	// Interrupt source group 1(0x148)
	#define mUsbIntSrc1Rd()			(wFOTGPeri_Port(0x148))
	#define mUsbIntSrc1Set(wValue)	(wFOTGPeri_Port(0x148) |= wValue)
	
	// Interrupt source group 2(0x14C)
	#define mUsbIntSrc2Rd()			(wFOTGPeri_Port(0x14C))
	#define mUsbIntSrc2Set(wValue)	(wFOTGPeri_Port(0x14C) |= wValue)

#if 0	
	#define mUsbIntBusRstClr()		(wFOTGPeri_Port(0x14C) &= ~BIT0)		
	#define mUsbIntSuspClr()			(wFOTGPeri_Port(0x14C) &= ~BIT1)		
	#define mUsbIntResmClr()			(wFOTGPeri_Port(0x14C) &= ~BIT2)		
	#define mUsbIntIsoSeqErrClr()		(wFOTGPeri_Port(0x14C) &= ~BIT3)			
	#define mUsbIntIsoSeqAbortClr()	(wFOTGPeri_Port(0x14C) &= ~BIT4)			
	#define mUsbIntTX0ByteClr()		(wFOTGPeri_Port(0x14C) &= ~BIT5)			
	#define mUsbIntRX0ByteClr()		(wFOTGPeri_Port(0x14C) &= ~BIT6)			
	#define mUsbIntDmaFinishClr()	(wFOTGPeri_Port(0x14C) &= ~BIT7)			
	#define mUsbIntDmaErrClr()		(wFOTGPeri_Port(0x14C) &= ~BIT8)			
	#define mUsbIntDmaFinishRd()	(wFOTGPeri_Port(0x14C) &BIT7)			

	#define mUsbIntDmaFinish()		(wFOTGPeri_Port(0x14C) & BIT7)			
	#define mUsbIntDmaErr()			(wFOTGPeri_Port(0x14C) & BIT8)			
#else
	#define mUsbIntBusRstClr()		(wFOTGPeri_Port(0x14C) = BIT0)		
	#define mUsbIntSuspClr()			(wFOTGPeri_Port(0x14C) = BIT1)		
	#define mUsbIntResmClr()			(wFOTGPeri_Port(0x14C) = BIT2)		
	#define mUsbIntIsoSeqErrClr()		(wFOTGPeri_Port(0x14C) = BIT3)			
	#define mUsbIntIsoSeqAbortClr()	(wFOTGPeri_Port(0x14C) = BIT4)			
	#define mUsbIntTX0ByteClr()		(wFOTGPeri_Port(0x14C) = BIT5)			
	#define mUsbIntRX0ByteClr()		(wFOTGPeri_Port(0x14C) = BIT6)			
	#define mUsbIntDmaFinishClr()	(wFOTGPeri_Port(0x14C) = BIT7)			
	#define mUsbIntDmaErrClr()		(wFOTGPeri_Port(0x14C) = BIT8)			
	#define mUsbIntDmaFinishRd()	(wFOTGPeri_Port(0x14C) &BIT7)			

	#define mUsbIntDmaFinish()		(wFOTGPeri_Port(0x14C) & BIT7)			
	#define mUsbIntDmaErr()			(wFOTGPeri_Port(0x14C) & BIT8)		
#endif

	// VDMA ////////////////////////////////////////////////////////	
	// Interrupt source group 3(0x328)
	#define mUsbIntSrc3Rd()			(wFOTGPeri_Port(0x328))
	#define mUsbIntSrc3Set(wValue)	(wFOTGPeri_Port(0x328) |= wValue)
			
	#define mUsbCXDmaFinishClr()	(wFOTGPeri_Port(0x328) = BIT0)			
	#define mUsbCXDmaFinishRd()	    (wFOTGPeri_Port(0x328) & BIT0)	
	#define mUsbCXDmaErrClr()		(wFOTGPeri_Port(0x328) = BIT16)							
	#define mUsbCXDmaErrRd()		(wFOTGPeri_Port(0x328) & BIT16)		
	
	#define mUsbEXDmaFinishClr(i)	(wFOTGPeri_Port(0x328) = (BIT1<<i))			
	#define mUsbEXDmaFinishRd(i)	(wFOTGPeri_Port(0x328) & (BIT1<<i))
	#define mUsbEXDmaErrClr(i)		(wFOTGPeri_Port(0x328) = (BIT17<<i))					
	#define mUsbEXDmaErrRd(i)		(wFOTGPeri_Port(0x328) & (BIT17<<i))	
		
    ////////////////////////////////////////////////////////////////		
	
	// Rx 0 byte packet register(0x150)
	#define mUsbIntRX0ByteRd()		(uint8_t)(wFOTGPeri_Port(0x150))
	#define mUsbIntRX0ByteSetClr(set)		(wFOTGPeri_Port(0x150) &= ~((uint32_t)set))
	
	// Tx 0 byte packet register(0x154)
	#define mUsbIntTX0ByteRd()		(uint8_t)(wFOTGPeri_Port(0x154))
	#define mUsbIntTX0ByteSetClr(data)		(wFOTGPeri_Port(0x154) &= ~((uint32_t)data))

	// ISO sequential Error/Abort register(0x158)
	#define mUsbIntIsoSeqErrRd()		(uint8_t)((wFOTGPeri_Port(0x158) & 0xff0000)>>16)
	#define mUsbIntIsoSeqErrSetClr(data)		(wFOTGPeri_Port(0x158) &= ~(((uint32_t)data)<<16))

	#define mUsbIntIsoSeqAbortRd()	(uint8_t)(wFOTGPeri_Port(0x158) & 0xff)
	#define mUsbIntIsoSeqAbortSetClr(data)	(wFOTGPeri_Port(0x158) &= ~((uint32_t)data))

	// IN Endpoint MaxPacketSize register(0x160,0x164,...,0x17C)
	#define mUsbEPinHighBandSet(EPn, dir , size )	(wFOTGPeri_Port(0x160 + ((EPn - 1) << 2)) &= ~(BIT14 |BIT13));  (wFOTGPeri_Port(0x160 + ((EPn - 1) << 2)) |= ((((uint8_t)(size >> 11)+1) << 13)*(1 - dir)) )
	#define mUsbEPMxPtSz(EPn, dir, size)		(wFOTGPeri_Port(0x160 + (dir * 0x20) + ((EPn - 1) << 2)) = (uint16_t)(size))
	#define mUsbEPMxPtSzClr(EPn, dir)			(wFOTGPeri_Port(0x160 + (dir * 0x20) + ((EPn - 1) << 2)) = 0)

	#define mUsbEPinMxPtSz(EPn)		(wFOTGPeri_Port(0x160 + ((EPn - 1) << 2)) & 0x7ff)
	#define mUsbEPinStallST(EPn)		((wFOTGPeri_Port(0x160 + ((EPn - 1) << 2)) & BIT11) >> 11)
	#define mUsbEPinStallClr(EPn)		(wFOTGPeri_Port(0x160 + ((EPn - 1) << 2)) &= ~BIT11)
	#define mUsbEPinStallSet(EPn)		(wFOTGPeri_Port(0x160 + ((EPn - 1) << 2)) |=  BIT11)
	#define mUsbEPinRsTgClr(EPn)		(wFOTGPeri_Port(0x160 + ((EPn - 1) << 2)) &= ~BIT12)
	#define mUsbEPinRsTgSet(EPn)	(wFOTGPeri_Port(0x160 + ((EPn - 1) << 2)) |=  BIT12)

	// OUT Endpoint MaxPacketSize register(0x180,0x164,...,0x19C)
	#define mUsbEPoutMxPtSz(EPn)	((wFOTGPeri_Port(0x180 + ((EPn - 1) << 2))) & 0x7ff)
	#define mUsbEPoutStallST(EPn)	((wFOTGPeri_Port(0x180 + ((EPn - 1) << 2)) & BIT11) >> 11)
	#define mUsbEPoutStallClr(EPn)	(wFOTGPeri_Port(0x180 + ((EPn - 1) << 2)) &= ~BIT11)
	#define mUsbEPoutStallSet(EPn)	(wFOTGPeri_Port(0x180 + ((EPn - 1) << 2)) |=  BIT11)
	#define mUsbEPoutRsTgClr(EPn)	(wFOTGPeri_Port(0x180 + ((EPn - 1) << 2)) &= ~BIT12)
	#define mUsbEPoutRsTgSet(EPn)	(wFOTGPeri_Port(0x180 + ((EPn - 1) << 2)) |=  BIT12)

	// Endpoint & FIFO Configuration
	// Endpoint 1~4 Map register(0x1a0), Endpoint 5~8 Map register(0x1a4)
	#define mUsbEPMap(EPn, MAP)	(bFOTGPeri_Port(0x1a0 + (EPn-1)) = MAP)
	#define mUsbEPMapRd(EPn)		(bFOTGPeri_Port(0x1a0+ (EPn-1)))
	#define mUsbEPMapAllClr()		(wFOTGPeri_Port(0x1a0) = 0);(wFOTGPeri_Port(0x1a4) = 0)
	
	// FIFO Map register(0x1a8)
	#define mUsbFIFOMap(FIFOn, MAP)	(bFOTGPeri_Port(0x1a8 + FIFOn) = MAP)
	#define mUsbFIFOMapRd(FIFOn)		(bFOTGPeri_Port(0x1a8 + FIFOn))
	#define mUsbFIFOMapAllClr()			(wFOTGPeri_Port(0x1a8) = 0)
	
	// FIFO Configuration register(0x1ac)
	#define mUsbFIFOConfig(FIFOn, CONFIG)	(bFOTGPeri_Port(0x1ac + FIFOn) = CONFIG)
	#define mUsbFIFOConfigRd(FIFOn)			(bFOTGPeri_Port(0x1ac + FIFOn))
	#define mUsbFIFOConfigAllClr()		(bFOTGPeri_Port(0x1ac) = 0)
	#define FIFOEnBit					0x20

	// FIFO byte count register(0x1b0)
	#define mUsbFIFOOutByteCount(fifo_num)	(((wFOTGPeri_Port(0x1b0+fifo_num*4)&0x7ff)))
	//#define mUsbFIFODone(fifo_num)			(wFOTGPeri_Port(0x1b0+fifo_num*4) |= BIT11)
    #define mUsbFIFOReset(fifo_num)			(wFOTGPeri_Port(0x1b0+fifo_num*4) |= BIT12)

/////// old DMA method ///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
	// DMA target FIFO register(0x1c0)
	#define FOTG200_DMA2FIFO_Non 		0
	#define FOTG200_DMA2FIFO0 			BIT0
	#define FOTG200_DMA2FIFO1 			BIT1
	#define FOTG200_DMA2FIFO2 			BIT2
	#define FOTG200_DMA2FIFO3 			BIT3
	#define FOTG200_DMA2CxFIFO 		    BIT4
	
	#define mUsbDMA2FIFOSel(sel)		(wFOTGPeri_Port(0x1c0) = sel)
	#define mUsbDMA2FIFORd()			(wFOTGPeri_Port(0x1c0))
	
	// DMA parameter set 1 (0x1c8)	
	#define mUsbDmaConfig(len,Dir)		(wFOTGPeri_Port(0x1c8) = (((uint32_t)len)<<8)|((1-Dir)<<1))
	//#define mUsbDmaLenRd()				((wFOTGPeri_Port(0x1c8) & 0x1fff0000) >> 8)
    #define mUsbDmaLenRd()				((wFOTGPeri_Port(0x1c8) & 0x00FFFFFF00) >> 8)	
	#define mUsbDmaConfigRd()			(wFOTGPeri_Port(0x1c8))
	#define mUsbDmaConfigSet(set)		(wFOTGPeri_Port(0x1c8) = set)
	
	#define mUsbDmaStart()				(wFOTGPeri_Port(0x1c8) |= BIT0)
	#define mUsbDmaStop()				(wFOTGPeri_Port(0x1c8) &= ~BIT0)

	// DMA parameter set 2 (0x1cc)	
	#define mUsbDmaAddr(addr)			(wFOTGPeri_Port(0x1cc) = addr)
	#define mUsbDmaAddrRd()			(wFOTGPeri_Port(0x1cc))
	
	// 8 byte command data port(0x1d0)
	#define mUsbEP0CmdDataRdDWord()	(wFOTGPeri_Port(0x1d0))
///////////////////////////////////////////////////////////////////////////////////

/////// new VDMA method ///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
	#define mUsbVDMAEnable()		    (wFOTGPeri_Port(0x330) = 1)
	#define mUsbVDMADisable()		    (wFOTGPeri_Port(0x330) = 0)
		
	// CX FIFO DMA	
	#define mUsbCXDmaConfig(len,Dir)	(wFOTGPeri_Port(0x300) = (((uint32_t)len)<<8)|((1-Dir)<<1))
    #define mUsbCXDmaLenRd()			((wFOTGPeri_Port(0x300) & 0x1FFFF00) >> 8)   	
	#define mUsbCXDmaConfigRd()			(wFOTGPeri_Port(0x300))
	#define mUsbCXDmaConfigSet(set)		(wFOTGPeri_Port(0x300) = set)
	
	#define mUsbCXDmaStart()			(wFOTGPeri_Port(0x300) |= BIT0)
	#define mUsbCXDmaStop()				(wFOTGPeri_Port(0x300) &= ~BIT0)

	// CX FIFO DMA parameter set 2 	
	#define mUsbCXDmaAddr(addr)			(wFOTGPeri_Port(0x304) = addr)
	#define mUsbCXDmaAddrRd()			(wFOTGPeri_Port(0x304))
	
    // F0-F3 FIFO DMA
	#define mUsbEXDmaConfig(i,len,Dir)	(wFOTGPeri_Port(0x308+i*8) = (((uint32_t)len)<<8)|((1-Dir)<<1))
    #define mUsbEXDmaLenRd(i)			((wFOTGPeri_Port(0x308+i*8) & 0x1FFFF00) >> 8)   	
	#define mUsbEXDmaConfigRd(i)		(wFOTGPeri_Port(0x308+i*8))
	#define mUsbEXDmaConfigSet(i,set)	(wFOTGPeri_Port(0x308+i*8) = set)
	
	#define mUsbEXDmaStart(i)			(wFOTGPeri_Port(0x308+i*8) |= BIT0)
	#define mUsbEXDmaStop(i)			(wFOTGPeri_Port(0x308+i*8) &= ~BIT0)
	
	#define mUsbEXDmaAbort(i)	        (wFOTGPeri_Port(0x308+i*8) |= BIT3)
	#define mUsbEXDmaRdAbort(i)	        (wFOTGPeri_Port(0x308+i*8) & BIT3)
	
	// F0-F3 FIFO DMA parameter set 2 	
	#define mUsbEXDmaAddr(i,addr)		(wFOTGPeri_Port(0x30C+i*8) = addr)
	#define mUsbEXDmaAddrRd(i)			(wFOTGPeri_Port(0x30C+i*8))
	
	
	// Endpoint or FIFO direction define
	#define DIRECTION_IN		0
	#define DIRECTION_OUT		1

	// Max. Packet Size define
	#define MX_PA_SZ_8			8
	#define MX_PA_SZ_16			16
	#define MX_PA_SZ_32			32
	#define MX_PA_SZ_64			64
	#define MX_PA_SZ_128		128
	#define MX_PA_SZ_256		256
	#define MX_PA_SZ_512		512
	#define MX_PA_SZ_1024		1024

	// Endpoint number define
	#define EP0					0x00
	#define EP1					0x01
	#define EP2					0x02
	#define EP3					0x03
	#define EP4					0x04
	#define EP5					0x05
	#define EP6					0x06
	#define EP7					0x07
	#define EP8					0x08
	#define EP9					0x09
	#define EP10				0x10
	#define EP11				0x11
	#define EP12				0x12
	#define EP13				0x13
	#define EP14				0x14
	#define EP15				0x15

///////////////////////////////////////////////////////////////////////////////////	
	

#pragma pack(1)


//
// I2C
//

#define I2C_SLAVE_INTERRUPT_STATUS_NONE         	0
#define I2C_SLAVE_INTERRUPT_STATUS_START			1
#define I2C_SLAVE_INTERRUPT_STATUS_STOP				2
#define I2C_SLAVE_INTERRUPT_STATUS_BYTE_TRANSFER	3
#define I2C_SLAVE_INTERRUPT_STATUS_ADDR_MATCH		4

#define I2C_SLAVE_FSM_STATUS_IDLE					0x0001
#define I2C_SLAVE_FSM_STATUS_WAIT_NEG				0x0002
#define I2C_SLAVE_FSM_STATUS_SLV_ADDR				0x0004
#define I2C_SLAVE_FSM_STATUS_ADDR_CHK				0x0008
#define I2C_SLAVE_FSM_STATUS_SLV_ACK				0x0010
#define I2C_SLAVE_FSM_STATUS_SLV_DLY				0x0020
#define I2C_SLAVE_FSM_STATUS_READ					0x0040
#define I2C_SLAVE_FSM_STATUS_READ_ACK				0x0080
#define I2C_SLAVE_FSM_STATUS_READ_WAIT				0x0100
#define I2C_SLAVE_FSM_STATUS_READ_DLY				0x0200
#define I2C_SLAVE_FSM_STATUS_READ_END				0x0400
#define I2C_SLAVE_FSM_STATUS_WRITE					0x0800
#define I2C_SLAVE_FSM_STATUS_WRITE_ACK				0x1000
#define I2C_SLAVE_FSM_STATUS_WRITE_DLY				0x2000


#define I2C_REPORT_REGISTER				0x0021
#define I2C_COMMAND_REGISTER			0x0022
#define I2C_DATA_REGISTER				0x0023
#define I2C_INPUT_REGISTER				0x0024
#define I2C_OUTPUT_REGISTER				0x0025

#define I2C_DATA_LENGTH					0x40
#define I2C_MAX_INPUT_LENGTH			(0x02 + I2C_DATA_LENGTH) // Length 2Bytes + Data 64Bytes
#define I2C_MAX_OUTPUT_LENGTH			(0x04 + I2C_DATA_LENGTH) // Register 2Bytes + Length 2Bytes + Data 64Bytes

#define I2C_VENDORID					UNIQUE_VID
#define I2C_PRODUCTID					UNIQUE_APP_PID
#define I2C_VERSION						(I2C__MAJOR << 8 | I2C__MINOR << 4 | I2C__BUILD)	// I2C F/W Version

// Interrupt
#define I2C_STR_ITRPT					1
#define I2C_STP_ITRPT					2
#define I2C_BYTE_ITRPT					3
#define I2C_ADDR_ITRPT					4
#define I2C_MST_ITRPT					5
#define I2C_SCL_HOLD_ITRPT				6


// We can not process Touch, Custom, Pen during processing command data.
#define I2C_DELAY_TIME					1000 // (0.1 sec)

// Ready
#define I2C_NOT_READY					0 // Default
#define I2C_READY						1

// Connect Status
#define I2C_CONNECT_NONE 				0
#define I2C_CONNECT_PC					1
#define I2C_CONNECT_TOOL				2
#define I2C_CONNECT_TOOL_0x150			3

// Reset
#define I2C_NORMAL						0 // Default
#define I2C_RESET						1

// GPIO
#define I2C_GPIO_NORMAL					0 // Default
#define I2C_GPIO_DISABLE				1


typedef struct _I2C_HID_DESCRIPTOR
{
	uint16_t	BCDVersion;
	uint16_t	ReportLength;
	uint16_t	ReportRegister;
	uint16_t	InputRegister;
	uint16_t	MaxInputLength;
	uint16_t	OutputRegister;
	uint16_t	MaxOutputLength;
	uint16_t	CommandRegister;
	uint16_t	DataRegister;
	uint16_t	VendorID;
	uint16_t	ProductID;
	uint16_t	VersionID;
	uint32_t	Reserved;

} I2C_HID_DESCRIPTOR, *PI2C_HID_DESCRIPTOR;


typedef struct _I2C_REQUEST_COMMON
{
	uint8_t ReportID : 4;
	uint8_t ReportType : 2;
	uint8_t Reserved_1 : 2;

} I2C_REQUEST_COMMON, *PI2C_REQUEST_COMMON;

typedef struct _I2C_REQUEST_POWER
{
	uint8_t PowerState : 4;
	uint8_t ReportType : 2;
	uint8_t Reserved_1 : 2;

} I2C_REQUEST_POWER, *PI2C_REQUEST_POWER;


typedef struct _I2C__REQUEST
{
	uint16_t	CommandRegister;

	union
	{
		I2C_REQUEST_COMMON	I2C_Request_Common;
		I2C_REQUEST_POWER	I2C_Request_Power;
	};

	uint8_t OpCode : 4;
	uint8_t Reserved_2 : 4;

	uint16_t DataRegister;
	uint16_t DataLength;
	uint8_t  Data[1];

} I2C__REQUEST, *PI2C__REQUEST;


typedef struct _I2C__REQUEST_LXS
{
	uint16_t	CommandRegister;

	union
	{
		I2C_REQUEST_COMMON	I2C_Request_Common;
		I2C_REQUEST_POWER	I2C_Request_Power;
	};

	uint8_t OpCode : 4;
	uint8_t Reserved_2 : 4;

	uint16_t DataRegister;
	uint16_t DataLength;

	uint8_t  ReportID;
	uint16_t ProtocolDataLength;
	uint8_t  Data[1];

} I2C__REQUEST_LXS, *PI2C__REQUEST_LXS;

typedef struct _I2C__OUTPUT
{
	uint16_t	CommandRegister;
	uint16_t	DataLength;
	uint8_t		ReportID;
	uint8_t		Data[1];
} I2C__OUTPUT, *PI2C__OUTPUT;

typedef enum _I2C__REQUEST_OPCODE
{
	I2C__REQUEST_OPCODE__RESERVED = 0x0,
	I2C__REQUEST_OPCODE__RESET = 0x1,
	I2C__REQUEST_OPCODE__GET_REPORT = 0x2,
	I2C__REQUEST_OPCODE__SET_REPORT = 0x3,
	I2C__REQUEST_OPCODE__GET_IDLE = 0x4,
	I2C__REQUEST_OPCODE__SET_IDLE = 0x5,
	I2C__REQUEST_OPCODE__GET_PROTOCOL = 0x6,
	I2C__REQUEST_OPCODE__SET_PROTOCOL = 0x7,
	I2C__REQUEST_OPCODE__SET_POWER = 0x8,
	I2C__REQUEST_OPCODE__VENDOR = 0xE,

} I2C_REQUEST__OPCODE;


typedef enum _I2C__REQUEST_REPORT_TYPE
{
	I2C__REQUEST_REPORT_TYPE__NONE = 0x0,
	I2C__REQUEST_REPORT_TYPE__INPUT = 0x1,
	I2C__REQUEST_REPORT_TYPE__OUTPUT = 0x2,
	I2C__REQUEST_REPORT_TYPE__FEATURE = 0x3,

} I2C__REQUEST_REPORT_TYPE;


typedef enum _I2C__REQUEST_REPORT_ID
{
	I2C__REQUEST_REPORT_ID__NONE = 0x0,

} I2C__REQUEST_REPORT_ID;


typedef enum _I2C__REQUEST_POWER_STATE
{
	I2C__REQUEST_REPORT_POWER_STATE__ON = 0x0,
	I2C__REQUEST_REPORT_POWER_STATE__SLEEP = 0x1,

} I2C__REQUEST_REPORT_POWER_STATE;











//
// USB
//

// DMA Ready
#define DMA_NOT_READY					0
#define DMA_READY						1


// Decide whether to use each interface.
#ifdef ADD_TOUCH
#define TOUCH_ENABLE					1
#else
#define TOUCH_ENABLE					0
#endif

#ifdef ADD_PEN
#define PEN_ENABLE						1
#else
#define PEN_ENABLE						0
#endif

#ifdef ADD_CUSTOM
#define CUSTOM_ENABLE					1
#else
#define CUSTOM_ENABLE					0
#endif

#ifdef ADD_BULK_CUSTOM
#define BULK_CUSTOM_ENABLE				1
#else
#define BULK_CUSTOM_ENABLE				0
#endif



// Interface Num
#define INTERFACE_COUNT					(TOUCH_ENABLE + PEN_ENABLE + CUSTOM_ENABLE + BULK_CUSTOM_ENABLE)

// Device Desc
#define DEVICE_CLASS					0XEF
#define DEVICE_SUB_CLASS				0X02
#define DEVICE_PROTOCOL					0X01
#define DEVICE_MANUFACTURER				0X02
#define DEVICE_PRODUCT					0X01
#define DEVICE_SERIALNUMBER				0X00
#define DEVICE_CONFIG_NUMBER			0X01

// VID, PID
#define DEVICE_USB_SPEC_VER				0x0200 // 0X0110
#define DEVICE_VENDOR_ID				UNIQUE_VID
#define DEVICE_PRODUCT_ID				UNIQUE_APP_PID
#define DEVICE_DEVICE_RELEASE_NO		(USB_BCDDEVICE__MAJOR << 8 | USB_BCDDEVICE__MINOR << 4 | USB_BCDDEVICE__BUILD)


// Descriptor Types
#define DT_DEVICE						1
#define DT_CONFIGURATION				2
#define DT_STRING						3
#define DT_INTERFACE					4
#define DT_ENDPOINT						5
#define DT_DEVICE_QUALIFIER				6
#define DT_OTHER_SPEED_CONFIGURATION	7
#define DT_INTERFACE_POWER				8
#define DT_OTG							9 
#define DT_IAD							11

// EP
#define EP_IN							0x80
#define EP_OUT							0x00

// EP Transfer Type
#define EP_TRANSFER_TYPE__ISO			0x01
#define EP_TRANSFER_TYPE__BULK			0x02
#define EP_TRANSFER_TYPE__INTERRUPT		0x03

// Class
#define INTERFACE_CLASS__HID			0x03
#define FUNCTION_CLASS__HID				0x03
#define FUNCTION_CLASS__0xFF			0xFF

// Sub Class
#define INTERFACE_SUB_CLASS__NONE		0x00
#define INTERFACE_SUB_CLASS__BOOT		0x01

// Protocol
#define INTERFACE_PROTOCOL__NONE		0x00
#define INTERFACE_PROTOCOL__KEYBOARD	0x01
#define INTERFACE_PROTOCOL__MOUSE		0x02

// Attribute
#define ATTRIBUTE_REMOTE_WAKE_UP		0x20	// Enable : 0x20, Disable : 0x00
#define ATTRIBUTE_BUS_POWERD			0x40	// BusPowerd : 0x00, SelfPowerd : 0x40
#define ATTRIBUTE_RESERVED				0x80

// Max Power
#define DEVICE_MAX_POWER				0x32 // (100 mA)

// Descriptor Length
#define STRING_LANG_IDS_LENGTH			4
#define STRING_PRODUCT_LENGTH			50
#define STRING_MANUFACTURER_LENGTH		26

#define DEVICE_DESC_LENGTH				18
#define CONFIG_LENGTH					9
#define IAD_LENGTH						8
#define INTERFACE_LENGTH				9
#define HID_LENGTH						9
#define ENDPOINT_LENGTH					7

// HID Version (1.11)
#define HID_VERSION						0x0111

// Decide whether to include an Endpoint.

#ifdef ADD_TOUCH
#define TOUCH_IN_EP_ADD					1
#define TOUCH_OUT_EP_ADD				0
#else
#define TOUCH_IN_EP_ADD					0
#define TOUCH_OUT_EP_ADD				0
#endif


#ifdef ADD_PEN
#define PEN_IN_EP_ADD					1
#define PEN_OUT_EP_ADD					0
#else
#define PEN_IN_EP_ADD					0
#define PEN_OUT_EP_ADD					0
#endif

#ifdef ADD_CUSTOM
#define CUSTOM_IN_EP_ADD				1
#define CUSTOM_OUT_EP_ADD				1
#else
#define CUSTOM_IN_EP_ADD				0
#define CUSTOM_OUT_EP_ADD				0
#endif

#ifdef ADD_BULK_CUSTOM
#define BULK_CUSTOM_IN_EP_ADD			1
#define BULK_CUSTOM_OUT_EP_ADD			1
#else
#define BULK_CUSTOM_IN_EP_ADD			0
#define BULK_CUSTOM_OUT_EP_ADD			0
#endif




// Endpoint Number
#define TOUCH_OUT_EP_NUM				1
#define TOUCH_IN_EP_NUM					2
#define CUSTOM_OUT_EP_NUM				3
#define CUSTOM_IN_EP_NUM				4
#define PEN_OUT_EP_NUM					5
#define PEN_IN_EP_NUM					6
#define BULK_CUSTOM_OUT_EP_NUM			7
#define BULK_CUSTOM_IN_EP_NUM			8

// EP Size
#define EP0_MAX_PACKET_SIZE				0x40
#define EP1_MAX_PACKET_SIZE				0x40
#define EP2_MAX_PACKET_SIZE				0x40
#define EP3_MAX_PACKET_SIZE				0x40
#define EP4_MAX_PACKET_SIZE				0x40
#define EP5_MAX_PACKET_SIZE				0x40
#define EP6_MAX_PACKET_SIZE				0x40
#define EP7_MAX_PACKET_SIZE				0x40
#define EP8_MAX_PACKET_SIZE				0x40

// EP Max Packet Size
#define TOUCH_OUT_EP_SIZE				EP1_MAX_PACKET_SIZE
#define TOUCH_IN_EP_SIZE				EP2_MAX_PACKET_SIZE
#define CUSTOM_OUT_EP_SIZE				EP3_MAX_PACKET_SIZE
#define CUSTOM_IN_EP_SIZE				EP4_MAX_PACKET_SIZE
#define PEN_OUT_EP_SIZE					EP5_MAX_PACKET_SIZE
#define PEN_IN_EP_SIZE					EP6_MAX_PACKET_SIZE
#define BULK_CUSTOM_OUT_EP_SIZE			EP7_MAX_PACKET_SIZE
#define BULK_CUSTOM_IN_EP_SIZE			EP8_MAX_PACKET_SIZE

// FIFO Number
#define TOUCH_FIFO_IN					1
#define CUSTOM_FIFO_IN					0
#define CUSTOM_FIFO_OUT					2
#define PEN_FIFO_IN						3
#define BULK_CUSTOM_FIFO_IN				0
#define BULK_CUSTOM_FIFO_OUT			2


// Interfade Number
#define TOUCH_INTERFACE_NUM				0
#define CUSTOM_INTERFACE_NUM			1
#define PEN_INTERFACE_NUM				2
#define BULK_CUSTOM_INTERFACE_NUM		3


#define TOUCH_ENDPOINT_COUNT			(TOUCH_IN_EP_ADD + TOUCH_OUT_EP_ADD)
#define PEN_ENDPOINT_COUNT				(PEN_IN_EP_ADD + PEN_OUT_EP_ADD)
#define CUSTOM_ENDPOINT_COUNT			(CUSTOM_IN_EP_ADD + CUSTOM_OUT_EP_ADD)
#define BULK_CUSTOM_ENDPOINT_COUNT		(BULK_CUSTOM_IN_EP_ADD + BULK_CUSTOM_OUT_EP_ADD)


#if TOUCH_ENABLE
#define TOUCH_DESC_LENGTH				(IAD_LENGTH + INTERFACE_LENGTH + HID_LENGTH + (ENDPOINT_LENGTH * TOUCH_ENDPOINT_COUNT))
#else
#define TOUCH_DESC_LENGTH				0
#endif

#if PEN_ENABLE
#define PEN_DESC_LENGTH					(IAD_LENGTH + INTERFACE_LENGTH + HID_LENGTH + (ENDPOINT_LENGTH * PEN_ENDPOINT_COUNT))
#else
#define PEN_DESC_LENGTH					0
#endif

#if CUSTOM_ENABLE
#define CUSTOM_DESC_LENGTH				(IAD_LENGTH + INTERFACE_LENGTH + HID_LENGTH + (ENDPOINT_LENGTH * CUSTOM_ENDPOINT_COUNT))
#else
#define CUSTOM_DESC_LENGTH				0
#endif

#if BULK_CUSTOM_ENABLE
#define BULK_CUSTOM_DESC_LENGTH			(IAD_LENGTH + INTERFACE_LENGTH + (ENDPOINT_LENGTH * BULK_CUSTOM_ENDPOINT_COUNT))
#else
#define BULK_CUSTOM_DESC_LENGTH			0
#endif


#define	CONFIG_DESC_LENGTH				(CONFIG_LENGTH + TOUCH_DESC_LENGTH + PEN_DESC_LENGTH + CUSTOM_DESC_LENGTH + BULK_CUSTOM_DESC_LENGTH)


// This feature is not supported until Windows 10 version 1511
//define LATENCY_MODE
#define LATENCY_MODE__NORMAL			0
#define LATENCY_MODE__HIGH				1



// Request Type
#define SETUPPACKET_REQUEST_TYPE__STANDARD				0x00
#define SETUPPACKET_REQUEST_TYPE__CLASS					0x01
#define SETUPPACKET_REQUEST_TYPE__VENDOR				0x02

// Standard Request
#define SETUPPACKET_STANDARD_REQUEST__GET_STATUS		0x00
#define SETUPPACKET_STANDARD_REQUEST__CLEAR_FEATURE		0x01
#define SETUPPACKET_STANDARD_REQUEST__SET_FEATURE		0x03
#define SETUPPACKET_STANDARD_REQUEST__SET_ADDRESS		0x05
#define SETUPPACKET_STANDARD_REQUEST__GET_DESCRIPTOR	0x06
#define SETUPPACKET_STANDARD_REQUEST__SET_DESCRIPTOR	0x07
#define SETUPPACKET_STANDARD_REQUEST__GET_CONFIGURATION	0x08
#define SETUPPACKET_STANDARD_REQUEST__SET_CONFIGURATION	0x09
#define SETUPPACKET_STANDARD_REQUEST__GET_INTERFACE		0x0A
#define SETUPPACKET_STANDARD_REQUEST__SET_INFERFACE		0x0B
#define SETUPPACKET_STANDARD_REQUEST__SYNCH_FRAME		0x0C

// Feature
#define SETUPPACKET_FEATURE__ENDPOINT_HALT				0x00
#define SETUPPACKET_FEATURE__DEVICE_REMOTE_WAKEUP		0x01

// Host to Device
#define SETUPPACKET_CLASS_REQUEST__GET_REPORT		0x01
#define SETUPPACKET_CLASS_REQUEST__GET_IDLE			0x02
#define SETUPPACKET_CLASS_REQUEST__GET_PROTOCOL		0x03
#define SETUPPACKET_CLASS_REQUEST__SET_REPORT		0x09
#define SETUPPACKET_CLASS_REQUEST__SET_IDLE			0x0A
#define SETUPPACKET_CLASS_REQUEST__SET_PROTOCOL		0x0B


// Descriptor
#define SETUPPACKET_DESCRIPTOR__DEVICE					0x01
#define SETUPPACKET_DESCRIPTOR__CONFIGURATION			0x02
#define SETUPPACKET_DESCRIPTOR__STRING					0x03
#define SETUPPACKET_DESCRIPTOR__HID						0x21
#define SETUPPACKET_DESCRIPTOR__REPORT					0x22
#define SETUPPACKET_DESCRIPTOR__BOS						0x0F
#define SETUPPACKET_DESCRIPTOR__MS_OS					0xEE
#define SETUPPACKET_DESCRIPTOR__MS_OS_2					0x03EE

// MS OS Descriptor
#define SETUPPACKET_DESCRIPTOR__MS_OS_VENDOR_CODE		0x98
#define MS_OS_DESCRIPTOR_TYPE__COMPATIBLE_ID			0x04
#define MS_OS_DESCRIPTOR_TYPE__PROPERTIES				0x05

// DEVICE_ICON, DEVICE_LEBEL
//#define MS_OS_EXT_PROP__ICON
//#define MS_OS_EXT_PROP__LABEL
#define MS_OS_EXT_PROP__WINUSB

// FIFO Config
#define FIFO_CONFIG_TYPE__RESERVED						0x00
#define FIFO_CONFIG_TYPE__ISO							0x01
#define FIFO_CONFIG_TYPE__BULK							0x02
#define FIFO_CONFIG_TYPE__INT							0x03

#define FIFO_CONFIG_BLOCK_NBUMBER__SINGLE				0x00
#define FIFO_CONFIG_BLOCK_NBUMBER__DOUBLE				0x01
#define FIFO_CONFIG_BLOCK_NBUMBER__TRIPLE				0x02
#define FIFO_CONFIG_BLOCK_NBUMBER__RESERVED				0x03

#define FIFO_CONFIG_BLOCK_SIZE__512						0x00
#define FIFO_CONFIG_BLOCK_SIZE__1024					0x01

#define FIFO_CONFIG__DISABLE							0x00
#define FIFO_CONFIG__ENABLE								0x01

#define FIFO_CONFIG_DIRECTION__OUT						0x00
#define FIFO_CONFIG_DIRECTION__IN						0x01
#define FIFO_CONFIG_DIRECTION__BIDIRECTIONAL			0x02
#define FIFO_CONFIG_DIRECTION__NOT_ALLOWED				0x03


typedef struct _USB20_EXT_DESCRIPTOR
{
	uint8_t	Length;
	uint8_t	Type;
	uint8_t	DevCapabilityType;
	uint32_t	bmAttributes_Reserved0 : 1;
	uint32_t	bmAttributes_LPM_Support : 1;
	uint32_t	bmAttributes_BESL_Support : 1;
	uint32_t	bmAttributes_BaseLineBESL : 1;
	uint32_t	bmAttributes_DeepBESL : 1;
	uint32_t	bmAttributes_Reserved1 : 3;
	uint32_t	bmAttributes_BESL : 4;
	uint32_t	bmAttributes_DBESL : 4;
	uint32_t	bmAttributes_Reserved2 : 8;
	uint32_t	bmAttributes_Reserved3 : 8;

} USB20_EXT_DESCRIPTOR, *PUSB20_EXT_DESCRIPTOR;

typedef struct _USB_SS_EXT_DESCRIPTOR
{
	uint8_t I_Dont_Know;

} USB_SS_EXT_DESCRIPTOR, *PUSB_SS_EXT_DESCRIPTOR;

typedef struct _BOS_DESCRIPTOR
{
	uint8_t	Length;
	uint8_t	Type;
	uint16_t	TotalLength;
	uint8_t	NumCapability;
	USB20_EXT_DESCRIPTOR Usb20ExtDesc;

} BOS_DESCRIPTOR, *PBOS_DESCRIPTOR;

// MS OS String Descriptor
typedef struct _MS_OS_STRING_DESCRIPTOR
{
	uint8_t	Length;
	uint8_t	Type;
	uint8_t	Signature[14];
	uint8_t	MSVendorCode;
	uint8_t	Pad;

} MS_OS_STRING_DESCRIPTOR, *PMS_OS_STRING_DESCRIPTOR;

typedef struct _COMPATIBLE_ID_FEATURE_DESCRIPTOR
{
	uint32_t	Length;
	uint16_t	bcdVersion;
	uint16_t	Index;
	uint8_t	Count;
	uint8_t	Reserved1[7];
	uint8_t	FirstInterfaceNumber;
	uint8_t	Reserved2;
	uint8_t	CompatibleID[8];
	uint8_t	SubCompatibleID[8];
	uint8_t	Reserved3[6];

} COMPATIBLE_ID_FEATURE_DESCRIPTOR, *PCOMPATIBLE_ID_FEATURE_DESCRIPTOR;

// Properties - Selective Suspend
#define SELECTIVE_SUSPEND_STRING	"SelectiveSuspendEnabled"
typedef struct _PROPERTY_SECTION__SELECTIVE_SUSPEND
{
	uint32_t	Size;
	uint32_t	PropertyDataType;
	uint16_t	PropertyNameLength;
	uint8_t	PropertyName[48];
	uint32_t	PropertyDataLength;
	uint32_t	PropertyData;
	
} PROPERTY_SECTION__SELECTIVE_SUSPEND, *PPROPERTY_SECTION__SELECTIVE_SUSPEND;

// Properties - DeviceInterfaceGUID (WinUSB)
#define DEVICEINTERFACEGUID_STRING	"{8FE6D4D7-49DD-41E7-9486-49AFC6BFE470}"
#define DEVICEINTERFACEGUID_NAME	"DeviceInterfaceGUID"
typedef struct _PROPERTY_SECTION__DEVICEINTERFACEGUID
{
	uint32_t	Size;
	uint32_t	PropertyDataType;
	uint16_t	PropertyNameLength;
	uint8_t	PropertyName[40];
	uint32_t	PropertyDataLength;
	uint8_t	PropertyData[78];

} PROPERTY_SECTION__DEVICEINTERFACEGUID, *PPROPERTY_SECTION__DEVICEINTERFACEGUID;

// Properties - DeviceIdleEnabled (WinUSB)
#define DEVICEIDLEENABLED_NAME	"DeviceIdleEnabled"
typedef struct _PROPERTY_SECTION__DEVICEIDLEENABLED
{
	uint32_t	Size;
	uint32_t	PropertyDataType;
	uint16_t	PropertyNameLength;
	uint8_t	PropertyName[36];
	uint32_t	PropertyDataLength;
	uint32_t	PropertyData;

} PROPERTY_SECTION__DEVICEIDLEENABLED, *PPROPERTY_SECTION__DEVICEIDLEENABLED;

// Properties - DefaultIdleState (WinUSB)
#define DEFAULTIDLESTATE_NAME	"DefaultIdleState"
typedef struct _PROPERTY_SECTION__DEFAULTIDLESTATE
{
	uint32_t	Size;
	uint32_t	PropertyDataType;
	uint16_t	PropertyNameLength;
	uint8_t	PropertyName[34];
	uint32_t	PropertyDataLength;
	uint32_t	PropertyData;

} PROPERTY_SECTION__DEFAULTIDLESTATE, *PPROPERTY_SECTION__DEFAULTIDLESTATE;

// Properties - DefaultIdleTimeout (WinUSB)
#define DEFAULTIDLETIMEOUT_NAME	"DefaultIdleTimeout"
typedef struct _PROPERTY_SECTION__DEFAULTIDLETIMEOUT
{
	uint32_t	Size;
	uint32_t	PropertyDataType;
	uint16_t	PropertyNameLength;
	uint8_t	PropertyName[38];
	uint32_t	PropertyDataLength;
	uint32_t	PropertyData;

} PROPERTY_SECTION__DEFAULTIDLETIMEOUT, *PPROPERTY_SECTION__DEFAULTIDLETIMEOUT;

// Properties - UserSetDeviceIdleEnabled (WinUSB)
#define USERSETDEVICEIDLEENABLED_NAME	"UserSetDeviceIdleEnabled"
typedef struct _PROPERTY_SECTION__USERSETDEVICEIDLEENABLED
{
	uint32_t	Size;
	uint32_t	PropertyDataType;
	uint16_t	PropertyNameLength;
	uint8_t	PropertyName[50];
	uint32_t	PropertyDataLength;
	uint32_t	PropertyData;

} PROPERTY_SECTION__USERSETDEVICEIDLEENABLED, *PPROPERTY_SECTION__USERSETDEVICEIDLEENABLED;

// Properties - SystemWakeEnabled (WinUSB)
#define SYSTEMWAKEENABLED_NAME	"SystemWakeEnabled"
typedef struct _PROPERTY_SECTION__SYSTEMWAKEENABLED
{
	uint32_t	Size;
	uint32_t	PropertyDataType;
	uint16_t	PropertyNameLength;
	uint8_t	PropertyName[36];
	uint32_t	PropertyDataLength;
	uint32_t	PropertyData;

} PROPERTY_SECTION__SYSTEMWAKEENABLED, *PPROPERTY_SECTION__SYSTEMWAKEENABLED;

// Properties - Device Icon
#define DEVICE_ICON_STRING	"%SystemRoot%\system32\shell32.dll,-230"
typedef struct _PROPERTY_SECTION__DEVICE_ICON
{
	uint32_t	Size;
	uint32_t	PropertyDataType;
	uint16_t	PropertyNameLength;
	uint8_t	PropertyName[12];
	uint32_t	PropertyDataLength;
	uint8_t	PropertyData[78];
	
} PROPERTY_SECTION__DEVICE_ICON, *PPROPERTY_SECTION__DEVICE_ICON;

// Properties - Device Label
#define DEVICE_LABEL_STRING	"Siliconworks"
typedef struct _PROPERTY_SECTION__DEVICE_LABEL
{
	uint32_t	Size;
	uint32_t	PropertyDataType;
	uint16_t	PropertyNameLength;
	uint8_t	PropertyName[12];
	uint32_t	PropertyDataLength;
	uint8_t	PropertyData[26];
	
} PROPERTY_SECTION__DEVICE_LABEL, *PPROPERTY_SECTION__DEVICE_LABEL;

typedef struct _PROPERTIES_DESCRIPTOR_HEADER
{
	// Header
	uint32_t	Length;
	uint16_t	bcdVersion;
	uint16_t	Index;
	uint16_t	Count;

} PROPERTIES_DESCRIPTOR_HEADER, *PPROPERTIES_DESCRIPTOR_HEADER;

typedef struct _PROPERTIES_DESCRIPTOR
{
	// Header
	PROPERTIES_DESCRIPTOR_HEADER	Header;

	// Selective Suspend
	PROPERTY_SECTION__SELECTIVE_SUSPEND 	SelectiveSuspend;
	
#ifdef MS_OS_EXT_PROP__WINUSB
	// DeviceInterfaceGUID
	PROPERTY_SECTION__DEVICEINTERFACEGUID		DeviceInterfaceGUID;
	PROPERTY_SECTION__DEVICEIDLEENABLED			DeviceIdleEnabled;
	PROPERTY_SECTION__DEFAULTIDLESTATE			DefaultIdleState;
	PROPERTY_SECTION__DEFAULTIDLETIMEOUT		DefaultIdleTimeout;
	PROPERTY_SECTION__USERSETDEVICEIDLEENABLED	UserSetDeviceIdleEnabled;
	PROPERTY_SECTION__SYSTEMWAKEENABLED			SystemWakeEnabled;
#endif

#ifdef MS_OS_EXT_PROP__ICON
	// Device Icon
	PROPERTY_SECTION__DEVICE_ICON			DeviceIcon;
#endif
	
#ifdef MS_OS_EXT_PROP__LABEL
	// Device Label
	PROPERTY_SECTION__DEVICE_LABEL			DeviceLabel;
#endif


} PROPERTIES_DESCRIPTOR, *PPROPERTIES_DESCRIPTOR;

#define REG_SZ 			1
#define REG_EXPAND_SZ	2
#define REG_DWORD		4
#define REG_MULTI_SZ	7


typedef struct _SETUP_PACKET
{
	uint8_t	bmRequestType_Recipient : 5;
	uint8_t	bmRequestType_Type : 2;
	uint8_t	bmRequestType_Direction : 1;
	uint8_t	bRequest;
	uint16_t	wValue;
	uint16_t	wIndex;
	uint16_t	wLength;

} SETUP_PACKET, *PSETUP_PACKET;

typedef struct _SETUP_GET_STATUS
{
	union
	{
		struct
		{
			uint16_t	SelfPowered : 1;
			uint16_t	RemoteWakeup : 1;
			uint16_t	Reserved : 14;
		} Global;

		struct
		{
			uint16_t	EndPointHalt : 1;
			uint16_t	Reserved : 15;

		} EP;

	} Status;

} SETUP_GET_STATUS, *PSETUP_GET_STATUS;

typedef enum _CXF_STATUS
{
	CXF_STATUS__NORMAL = 0,
	CXF_STATUS__DOING = 1,
	CXF_STATUS__NEED_TO_DONE = 2,
	CXF_STATUS__COMPLETE_DONE = 3

} CXF_STATUS;




//
// HID Descriptor
//

typedef struct _TOUCH_MAX_COUNT
{
	uint8_t		ReportID;
	uint8_t		Count;

} TOUCH_MAX_COUNT, *PTOUCH_MAX_COUNT;


typedef struct _TOUCH_IDLE
{
    uint16_t    Idle;
    
} TOUCH_IDLE, *PTOUCH_IDLE;


// For USB
typedef struct _SETUP_HID_DESCRIPTOR
{
	uint8_t	bLength;
	uint8_t	bDescriptorType;
	uint16_t	bcdHID;
	uint8_t	bCountryCode;
	uint8_t	bNumDescriptors;
	uint8_t	bDescriptorType_Class;
	uint16_t	wDescriptorLength;

} SETUP_HID_DESCRIPTOR, *PSETUP_HID_DESCRIPTOR;
#define HID_DESCRIPTOR_LENGTH			0x09



// HID Report ID
#define HID_REPORT_ID__FEATURE_2 		0x01	// 2 Byte
#define HID_REPORT_ID__FEATURE_4 		0x02	// 4 Bytes
#define HID_REPORT_ID__FEATURE_6 		0x03	// 6 Bytes
#define HID_REPORT_ID__FEATURE_20 		0x04	// 20 Bytes
#define HID_REPORT_ID__FEATURE_60 		0x05	// 60 Bytes

#define HID_REPORT_ID__BLOB_CODE		0x06
#define HID_REPORT_ID__DEVICE_MODE 		0x07
#define HID_REPORT_ID__CONTACT_COUNT 	0x08

#define HID_REPORT_ID__CUSTOM_OUT		0x09
#define HID_REPORT_ID__CUSTOM_IN		0x0A

#if USED_WACOM_HIDI2C_DRIVER
	#define HID_REPORT_ID__PEN				0x0C
	#define HID_REPORT_ID__WACOM_PEN		0x0D
	#define HID_REPORT_ID__WACOM_CUSTOM		0x0B
#else /* USED_WACOM_HIDI2C_DRIVER */
	#define HID_REPORT_ID__PEN				0x0B
	#define HID_REPORT_ID__PEN_SECOND		0x0C
#endif /* USED_WACOM_HIDI2C_DRIVER */

#define HID_REPORT_ID__LATENCY_MODE		0x0D
#define HID_REPORT_ID__MULTI_TOUCH 		0x10
#define HID_REPORT_ID__MOUSE 			0x11







//
// Multi-Touch
//

#define HID_MAX_TOUCH 					0x0A
#define HID_MAX_TOUCH_HYBRID			0x05

#define	CONTACT_COUNT_LENGTH			12
#define SCAN_TIME_LENGTH				25
#define MAX_COUNT_LENGTH				12
#define BLOB_CODE_LENGTH				19
#define DEVICE_MODE_LENGTH				0 // 28
#if USED_S3_WAKEUP_MOUSE_DEVICE
#define MOUSE_LENGTH					(54)
#else /* USED_S3_WAKEUP_MOUSE_DEVICE */
#define MOUSE_LENGTH					(0)
#endif /* USED_S3_WAKEUP_MOUSE_DEVICE */

#ifdef LATENCY_MODE
#define LATENCY_LENGTH					18
#else
#define LATENCY_LENGTH					0
#endif


#define HID_MULTITOUCH_DESC_HEAD_LENGTH	(0x08)	
#define HID_MULTITOUCH_DESC_MAIN_LENGTH	0x43
#define HID_MULTITOUCH_DESC_TAIL_LENGTH	(CONTACT_COUNT_LENGTH + SCAN_TIME_LENGTH + MAX_COUNT_LENGTH + BLOB_CODE_LENGTH + LATENCY_LENGTH + DEVICE_MODE_LENGTH + MOUSE_LENGTH + 1)
#define HID_MULTITOUCH_DESC_TOTAL_LENGTH (HID_MULTITOUCH_DESC_HEAD_LENGTH + (HID_MULTITOUCH_DESC_MAIN_LENGTH * HID_MAX_TOUCH) + HID_MULTITOUCH_DESC_TAIL_LENGTH)
#define HID_TOUCH_BLOB_LENGTH			0x101

// Queue
#define QUEUE_MAX_COUNT__TOUCH			10

// Tip
#define FINGER_STATUS__TIP_SWITCH		0x01

// Device Mode
#define DEVICE_MODE__MOUSE				0x00
#define DEVICE_MODE__SINGLE_INPUT		0x01
#define DEVICE_MODE__MULTI_INPUT		0x02


// X, Y Logical Maximum
#define X_LOGICAL_MAX					32767
#define Y_LOGICAL_MAX					32767

#define SCAN_TIME_MAX					65535

typedef struct _SETREPORT_DEVICE_MODE
{
	uint8_t	ReportID;
	uint8_t	DeviceMode;
	uint8_t	DeviceIdentifier;

} SETREPORT_DEVICE_MODE, *PSETREPORT_DEVICE_MODE;

typedef struct _SETREPORT_LATENCY_MODE
{
	uint8_t	ReportID;
	uint8_t	Mode : 1; // Normal 0, High 1
	uint8_t	Reserved : 7;

} SETREPORT_LATENCY_MODE, *PSETREPORT_LATENCY_MODE;

// For I2C
typedef struct _PROTOCOL_MOUSE_MODE
{
	uint8_t	ReportID;
	uint8_t	Protocol;

} PROTOCOL_MOUSE_MODE, *PPROTOCOL_MOUSE_MODE;


typedef struct _HID_TOUCH
{
	uint8_t	Status;
	uint8_t	ID;
	uint16_t	x;
	uint16_t	y;

} HID_TOUCH, *PHID_TOUCH;


// For USB
typedef struct _HID_MULTITOUCH
{
	uint8_t		ReportID;
	HID_TOUCH 	Touch[HID_MAX_TOUCH];
	uint8_t		ContactCount;
	uint16_t 		ScanTime;

} HID_MULTITOUCH, *PHID_MULTITOUCH;

typedef struct _HID_MULTITOUCH_HYBRID
{
	uint8_t		ReportID;
	HID_TOUCH 	Touch[HID_MAX_TOUCH_HYBRID];
	uint8_t		ContactCount;
	uint16_t 		ScanTime;

} HID_MULTITOUCH_HYBRID, *PHID_MULTITOUCH_HYBRID;


// For I2C
typedef struct _HID_MULTITOUCH_I2C
{
	uint16_t					I2C_Length;
	HID_MULTITOUCH			Data;

} HID_MULTITOUCH_I2C, *PHID_MULTITOUCH_I2C;

#if USED_S3_WAKEUP_MOUSE_DEVICE
typedef struct _HID_MOUSE
{
	uint8_t  ReportID; // HID_REPORT_ID__MOUSE
	uint8_t Button; // 0
	uint8_t  x; // 1
	uint8_t  y; // 1
	uint8_t  Wheel; // 0

} HID_MOUSE, *PHID_MOUSE;
#endif /* USED_S3_WAKEUP_MOUSE_DEVICE */




//
// Custom
//

#define HID_CUSTOM_DESC_LENGTH			(0x26+(18*5))
//#define HID_CUSTOM_LOOP_BACK_TEST

typedef struct _HID_CUSTOM
{
	uint8_t	ReportID;
	uint8_t	MoveType;

} HID_CUSTOM, *PHID_CUSTOM;

// Callback
typedef uint8_t(*PCOMPLETION_ROUTINE) (uint8_t* pContext, uint8_t nResult);
typedef uint8_t(*PINPUT_REPORT_REQUEST_COMPLETE) (PCOMPLETION_ROUTINE pCompletionRoutine, uint8_t* pContext, uint8_t bCustom);
typedef uint8_t(*POUTPUT_REPORT_REQUEST_COMPLETE) (PCOMPLETION_ROUTINE pCompletionRoutine, uint8_t* pContext, uint8_t bCustom);
typedef uint8_t(*PSEND_REQUEST_COMPLETE) (PCOMPLETION_ROUTINE pCompletionRoutine, uint8_t* pContext);

typedef struct _SILICONWORKS_HID_FRAMEWORK_RETURN_STRUCT
{
	PINPUT_REPORT_REQUEST_COMPLETE		pInputReportRequestComplete;
	POUTPUT_REPORT_REQUEST_COMPLETE		pOutputReportRequestComplete;
	PSEND_REQUEST_COMPLETE 				pSendRequestComplete;
	uint8_t*								pControllBuffer;
	uint32_t 								ControllBufferLength;
	uint8_t*								pInputBuffer;
	uint32_t								InputBufferLength;
	uint8_t* 								pOutputBuffer;
	uint32_t								OutputBufferLength;
	uint8_t								TempBuffer[64];
	uint16_t 								InputOffset;
	uint16_t								OutputOffset;
	bool_t 							bConnected;
	bool_t								bSuspend;
} SILICONWORKS_HID_FRAMEWORK_RETURN_STRUCT, *PSILICONWORKS_HID_FRAMEWORK_RETURN_STRUCT;

typedef struct
{
	uint8_t PacketID;

	struct
	{
		uint8_t bRead : 1;
		uint8_t addr : 7;

	} DeviceID_b;

	uint16_t Length;
	uint8_t Data[60];

} HJ_HID_CONTROL_STRUCT, *PHJ_HID_CONTROL_STRUCT;

// For I2C
typedef struct _HJ_HID_CONTROL_STRUCT_I2C
{
	uint16_t					I2C_Length;
	HJ_HID_CONTROL_STRUCT	Data;

} HJ_HID_CONTROL_STRUCT_I2C, *PHJ_HID_CONTROL_STRUCT_I2C;

typedef struct _LX_GETFEATURE_DATA
{
	uint8_t 	ReportID;
	uint8_t 	Data[60];

} LX_GETFEATURE_DATA, *PLX_GETFEATURE_DATA;


//
// Pen
//

//#ifdef ADD_PEN
//#define JOSH3_PEN_TEST
//#endif

#ifdef ADD_PEN
	#define HID_AZIMUTH_INPUT
	#define HID_PEN_SCAN_TIME
	#define ADD_PEN_EXTRA
#endif

#ifdef ADD_PEN_EXTRA
#if USED_WACOM_HIDI2C_DRIVER
	#define PEN_EXTRA_LENGTH				(61)
#else
	#define PEN_EXTRA_LENGTH				(24)
#endif
#else
	#define PEN_EXTRA_LENGTH				(0)
#endif

#ifdef HID_AZIMUTH_INPUT
#define PEN_AZIMUTH_LENGTH				(26+24)
#else
#define PEN_AZIMUTH_LENGTH				(0)
#endif

#ifdef HID_PEN_SCAN_TIME
#define HID_PEN_SCAN_TIME_LENGTH		(23)
#else
#define HID_PEN_SCAN_TIME_LENGTH		(0)
#endif


#if USED_WACOM_HIDI2C_DRIVER
	#define HID_PEN_DESC_LENGTH				(((0x93 + PEN_AZIMUTH_LENGTH + HID_PEN_SCAN_TIME_LENGTH)) + (PEN_EXTRA_LENGTH))
	#define HID_WACOM_PEN_DESC_LENGTH		(((0x94 + PEN_AZIMUTH_LENGTH + HID_PEN_SCAN_TIME_LENGTH)) + (PEN_EXTRA_LENGTH)+12)
#else /* USED_WACOM_HIDI2C_DRIVER */
	#define HID_PEN_DESC_LENGTH				(((0x97 + PEN_AZIMUTH_LENGTH + HID_PEN_SCAN_TIME_LENGTH)) + (PEN_EXTRA_LENGTH))
#endif /* USED_WACOM_HIDI2C_DRIVER */

// Queue
#define QUEUE_MAX_COUNT__PEN			20

#define HID_PEN_TIP						0x01
#define HID_PEN_BARREL					0x02
#define HID_PEN_INVERT					0x04
#define HID_PEN_ERASER					0x08
#define HID_PEN_INRANGE					0x20

// Pen Extra
#define HID_PEN__SERIAL_CODE			0x5B
#define HID_PEN__BATTERY_LEVEL			0x3B

// Pressure
#define PRESSURE_MAX					4095

// Tilt
#define TILT_X_MIN						(-9000)
#define TILT_Y_MIN						(-9000)
#define TILT_X_MAX						9000
#define TILT_Y_MAX						9000

// Altitude
#define ALTITUDE_MIN					(-9000)
#define ALTITUDE_MAX					9000

// Azimuth
#define AZIMUTH_MAX						36000

// Twist
#define TWIST_MAX						36000
 
// Pen ID
#define PEN_ID_19BIT(ID)				(ID & 0x7FFFF)
#define PEN_ID_51BIT(ID)				(ID >> 19)


// For USB
typedef struct _HID_PEN
{
	uint8_t	ReportID;

	union
	{
		struct
		{
			uint8_t		Tip : 1;
			uint8_t		Barrel : 1;
#if USED_WACOM_HIDI2C_DRIVER
			uint8_t		Eraser : 1;
			uint8_t		Invert : 1;
			uint8_t		SecondaryBarrelSwitch : 1;
			uint8_t		InRange : 1;
			uint8_t		Reserved1 : 1;
#else /* USED_WACOM_HIDI2C_DRIVER */
			uint8_t		Invert : 1;
			uint8_t		Eraser : 1;
			uint8_t		Reserved1 : 1;
			uint8_t		InRange : 1;
			uint8_t		Reserved2 : 2;
#endif /* USED_WACOM_HIDI2C_DRIVER */
		} u;

		uint8_t Data;

	} SwitchData;

	uint16_t	x;
	uint16_t	y;

	uint16_t	Pressure;
	int16_t  Tilt_x;
	int16_t	Tilt_y;

#ifdef HID_AZIMUTH_INPUT
	int16_t	Altitude;
	uint16_t	Azimuth;
#endif

	uint16_t	Twist;

#ifdef HID_PEN_SCAN_TIME
	uint16_t 	ScanTime;
#endif

#ifdef ADD_PEN_EXTRA
#if USED_WACOM_HIDI2C_DRIVER
	// Pen ID
	uint64_t 	PenID : 43; // (DeviceType 16 + SerialNumber 27)
	uint64_t 	PenID_Reserved1 : 3;
	uint64_t 	PenID_VendorID : 5;
	uint64_t 	PenID_Reserved2 : 5;
	
	// Bettery Level
    uint64_t 	BetteryLevel : 8;
#else
	// Pen ID
	uint64_t 	PenID : 51;
	uint64_t 	PenID_Reserved : 13;
	
	// Bettery Level
    uint8_t 	BetteryLevel;
#endif
#endif

} HID_PEN, *PHID_PEN;

// For I2C
typedef struct _HID_PEN_I2C
{
	uint16_t	I2C_Length;
	HID_PEN	Data;

} HID_PEN_I2C, *PHID_PEN_I2C;






//
// Common (Touch + Pen)
//

typedef struct _HID_COMMON_USB
{
	uint8_t	Data[64];

} HID_COMMON_USB, *PHID_COMMON_USB;

typedef struct _HID_COMMON_I2C
{
	uint16_t	I2C_Length;
	uint8_t	Data[64];

} HID_COMMON_I2C, *PHID_COMMON_I2C;


// Static Queue
#define QUEUE_MAX_COUNT__COMMON			(30)
#define QUEUE_BLOCK_SIZE				(66)
#define QUEUE_SIGNATURE					"SIW4"
typedef struct _STATIC_QUEUE
{
	uint8_t	Signature[4];
	uint8_t	Buffer[QUEUE_BLOCK_SIZE * QUEUE_MAX_COUNT__COMMON];
	uint8_t	PushPoint;
	uint8_t	PopPoint;
	uint32_t	Count;
    uint8_t    Doing;

} STATIC_QUEUE, *PSTATIC_QUEUE;

uint8_t StaticQueue_Init(PSTATIC_QUEUE pQueue);
uint8_t StaticQueue_CheckInit(PSTATIC_QUEUE pQueue);
uint8_t StaticQueue_Push(PSTATIC_QUEUE pQueue, uint8_t* pData);
uint8_t StaticQueue_Pop(PSTATIC_QUEUE pQueue, uint8_t* pData);
uint8_t  StaticQueue_HeadDelete(PSTATIC_QUEUE pQueue);
uint8_t* StaticQueue_Get(PSTATIC_QUEUE pQueue);
uint8_t StaticQueue_CheckFull(PSTATIC_QUEUE pQueue);
uint8_t StaticQueue_CheckEmpty(PSTATIC_QUEUE pQueue);

// Protocol
void Protocol_hid_Init(void);
void Protocol_hid__SetAddress(uint16_t usRegAddr);
void Protocol_hid__FromHostToDevice(uint8_t Data);
uint8_t Protocol_hid_FromDeviceToHost(uint8_t* pRetData, uint8_t b2Byte);


// I2C
#ifdef MODE_I2C
uint8_t CallReadyStatus_ToHost(void); // 2021.12.06
uint8_t SendTouchData_I2C(PHID_MULTITOUCH_I2C pTouchData);
void SendPenData_I2C(PHID_PEN_I2C pPenData);
void QueueCommonData_I2C(void);
void GetCustomData_I2C(uint8_t* pData);
void SendCustomData_I2C(PHJ_HID_CONTROL_STRUCT_I2C pData);
void HidReadWrite__Read_I2C(PHJ_HID_CONTROL_STRUCT_I2C pHidControl);
#endif /* MODE_I2C */


// USB
void USB_DevInit(void);
void ResumeSigal(void);
uint8_t CheckUsbConfig(void);
uint8_t CheckHIDReady(void);
void SendTouchData(void);
void SendTouchData_USB(PHID_MULTITOUCH pUserData);
void DMATouchData_USB(void);
void SendPenData(void);
void SendPenData_Multi(void);
void SendPenData_USB(PHID_PEN pUserData);
void DMAPenData_USB(void);
void QueueCommonData_USB(void);
void RecieveCustomData(uint8_t* pData);
void HidReadWrite__Read(PHJ_HID_CONTROL_STRUCT pOutBuffer);
void HidReadWrite__Write(PHJ_HID_CONTROL_STRUCT pHidControl);

#pragma pack()

#endif /* _FOTG200_PERIPHERAL_H_  */
