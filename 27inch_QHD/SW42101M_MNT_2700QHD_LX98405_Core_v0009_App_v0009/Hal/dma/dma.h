/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : dma.h
 * version : 0.1
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

#ifndef _DMA_H_
#define _DMA_H_


#define MAX_DMA_CHANNELS			1
#define DMA_BASE				    ((uint32_t)BASE_GPDMA)
#define DMA_Channel0_BASE		(DMA_BASE + 0x0000)

#define DMA_Global_BASE		  (DMA_BASE + 0x02C0)
#define DMA_Channel0			  ((DMA_Channel_TypeDef*)DMA_Channel0_BASE)
#define DMA_Global				  ((DMA_GLOBAL_TypeDef*)DMA_Global_BASE)



//CTLx
#define  DMA_INTERRUPT_Enable                    ((uint64_t)0x0000000000000001)
#define  DMA_DestinationTransferWidth_8bit       ((uint8_t)0x0)
#define  DMA_DestinationTransferWidth_16bit      ((uint8_t)0x1)
#define  DMA_DestinationTransferWidth_32bit      ((uint8_t)0x2)
#define  DMA_DestinationTransferWidth_64bit      ((uint8_t)0x3)
#define  DMA_DestinationTransferWidth_128bit     ((uint8_t)0x4)
#define  DMA_DestinationTransferWidth_256bit     ((uint8_t)0x5)


#define  DMA_SourceTransferWidth_8bit            ((uint8_t)0x0)
#define  DMA_SourceTransferWidth_16bit           ((uint8_t)0x1)
#define  DMA_SourceTransferWidth_32bit           ((uint8_t)0x2)
#define  DMA_SourceTransferWidth_64bit           ((uint8_t)0x3)
#define  DMA_SourceTransferWidth_128bit          ((uint8_t)0x4)
#define  DMA_SourceTransferWidth_256bit          ((uint8_t)0x5)

#define	DMA_DestinationAddress_Increment				((uint8_t)0x00) //  <<7
#define	DMA_DestinationAddress_Decrement				((uint8_t)0x01) //  <<7
#define	DMA_DestinationAddress_NoChange					((uint8_t)0x02) //  <<7

#define	DMA_SourceAddress_Increment							((uint8_t)0x00) //  <<9
#define	DMA_SourceAddress_Decrement							((uint8_t)0x01) //  <<9
#define	DMA_SourceAddress_NoChange							((uint8_t)0x02) //  <<9


#define	DMA_DestinationBurstTransLength_1				((uint8_t)0x00) //  <<11
#define	DMA_DestinationBurstTransLength_4				((uint8_t)0x01) //  <<11
#define	DMA_DestinationBurstTransLength_8				((uint8_t)0x02) //  <<11
#define	DMA_DestinationBurstTransLength_16			((uint8_t)0x03) //  <<11
#define	DMA_DestinationBurstTransLength_32			((uint8_t)0x04) //  <<11
#define	DMA_DestinationBurstTransLength_64			((uint8_t)0x05) //  <<11
#define	DMA_DestinationBurstTransLength_128			((uint8_t)0x06) //  <<11
#define	DMA_DestinationBurstTransLength_256			((uint8_t)0x07) //  <<11

#define	DMA_SourceBurstTransLength_1						((uint8_t)0x00) //  <<14
#define	DMA_SourceBurstTransLength_4						((uint8_t)0x01) //  <<14            
#define	DMA_SourceBurstTransLength_8						((uint8_t)0x02) //  <<14
#define	DMA_SourceBurstTransLength_16						((uint8_t)0x03) //  <<14
#define	DMA_SourceBurstTransLength_32						((uint8_t)0x04) //  <<14
#define	DMA_SourceBurstTransLength_64						((uint8_t)0x05) //  <<14
#define	DMA_SourceBurstTransLength_128					((uint8_t)0x06) //  <<14
#define	DMA_SourceBurstTransLength_256					((uint8_t)0x07) //  <<14

#define	DMA_SourceGatherDisable								  ((uint8_t)0x00) //  <<17
#define	DMA_SourceGatherEnable								  ((uint8_t)0x01) //  <<17
#define	DMA_DestinationScatterDisable						((uint8_t)0x00) //  <<18
#define	DMA_DestinationScatterEnable						((uint8_t)0x01) //  <<18

#define	DMA_DataTransferDir_M2M								  ((uint8_t)0x00) //  <<20
#define	DMA_DataTransferDir_M2P								  ((uint8_t)0x01) //  <<20
#define	DMA_DataTransferDir_P2M								  ((uint8_t)0x02) //  <<20
#define	DMA_DataTransferDir_P2P								  ((uint8_t)0x03) //  <<20

#define	DMA_DestinationAHBBus_Master1						((uint8_t)0x00) //  <<23
#define	DMA_DestinationAHBBus_Master2						((uint8_t)0x01) //  <<23
#define	DMA_DestinationAHBBus_Master3						((uint8_t)0x02) //  <<23
#define	DMA_DestinationAHBBus_Master4						((uint8_t)0x03) //  <<23

#define	DMA_SourceAHBBus_Master1							  ((uint8_t)0x00) //  <<25
#define	DMA_SourceAHBBus_Master2							  ((uint8_t)0x01) //  <<25
#define	DMA_SourceAHBBus_Master3							  ((uint8_t)0x02) //  <<25
#define	DMA_SourceAHBBus_Master4							  ((uint8_t)0x03) //  <<25

#define	DMA_DestinationLLPDisable						    ((uint8_t)0x00) //  <<27
#define	DMA_DestinationLLPEnable						    ((uint8_t)0x01) //  <<27

#define	DMA_SourceLLPDisable								    ((uint8_t)0x00) //  <<28
#define	DMA_SourceLLPEnable								      ((uint8_t)0x01) //  <<28

#define	CTLx_CLEAR_Mask										      ((uint64_t)0xFFFFF000F80E0001)
#define	DMA_BLOCK_TS_Mask									      ((uint64_t)0x00000FFF00000000)

//CFGx
#define	DMA_PRIORITY_Level_0								    ((uint8_t)0x07) //  <<5     highest priority
#define	DMA_PRIORITY_Level_1								    ((uint8_t)0x06) //  <<5             
#define	DMA_PRIORITY_Level_2								    ((uint8_t)0x05) //  <<5
#define	DMA_PRIORITY_Level_3								    ((uint8_t)0x04) //  <<5
#define	DMA_PRIORITY_Level_4								    ((uint8_t)0x03) //  <<5
#define	DMA_PRIORITY_Level_5								    ((uint8_t)0x02) //  <<5
#define	DMA_PRIORITY_Level_6								    ((uint8_t)0x01) //  <<5
#define	DMA_PRIORITY_Level_7								    ((uint8_t)0x00) //  <<5     lowest

#define	DMA_DestinationSoftwareHandShaking		  ((uint8_t)0x01) //  <<10
#define	DMA_DestinationHardwareHandShaking			((uint8_t)0x00) //  <<10

#define	DMA_SourceSoftwareHandShaking						((uint8_t)0x01) //  <<11
#define	DMA_SourceHardwareHandShaking						((uint8_t)0x00) //  <<11

#define	DMA_SourceReloadDisable								  ((uint8_t)0x00) //  <<30
#define	DMA_SourceReloadEnable								  ((uint8_t)0x01) //  <<30

#define	DMA_DestinationReloadDisable						((uint8_t)0x00) //  <<31
#define	DMA_DestinationReloadEnable						  ((uint8_t)0x01) //  <<31

#define	DMA_DestinationStateUpdateDisable       ((uint8_t)0x00) //  <<37
#define	DMA_DestinationStateUpdateEnable				((uint8_t)0x01) //  <<37

#define	DMA_SourceStateUpdateDisable						((uint8_t)0x00) //  <<38
#define	DMA_SourceStateUpdateEnable							((uint8_t)0x01) //  <<38

#define	DMA_DMADoneDisable						          ((uint8_t)0x00) //  <<44
#define	DMA_DMADoneEnable							          ((uint8_t)0x01) //  <<44

/////////////////////////////////
// change by hnkim             //
/////////////////////////////////
#define	DMA_SOURCE_PERI_I2CTX								    ((uint8_t)0x00) //  <<39
#define	DMA_SOURCE_PERI_I2CRX								    ((uint8_t)0x01) //  <<39
#define	DMA_SOURCE_PERI_TSPITX							    ((uint8_t)0x02) //  <<39
#define	DMA_SOURCE_PERI_TSPIRX							    ((uint8_t)0x03) //  <<39
#define	DMA_SOURCE_PERI_NONE								    ((uint8_t)0x04) //  <<39

#define	DMA_DESTINATION_PERI_I2CTX							((uint8_t)0x00) //  <<43
#define	DMA_DESTINATION_PERI_I2CRX							((uint8_t)0x01) //  <<43
#define	DMA_DESTINATION_PERI_TSPITX							((uint8_t)0x02) //  <<43
#define	DMA_DESTINATION_PERI_TSPIRX							((uint8_t)0x03) //  <<43
#define	DMA_DESTINATION_PERI_NONE							  ((uint8_t)0x04) //  <<43


#define	CFGx_Mask											          ((uint64_t)0xFFFF807F3FFFF31F)

//DmaCfgReg
#define	DMA_GlobalChannel_Enable							  ((uint32_t)0x00000001)

  /////////////////////////////////
  //ChEnReg // change by hnkim   //
  /////////////////////////////////
  #define  DMA_CH0_Flag                            ((uint16_t)0x0001)
//#define  DMA_CH1_Flag                            ((uint16_t)0x0002)
//#define  DMA_CH2_Flag                            ((uint16_t)0x0003)
  #define  DMA_Channel_Mask                        ((uint16_t)0x0007)

//ClearBlock, ClearDstTran,ClearErr,ClearSrcTran,ClearTfr
#define	TYPE_TRANFER_COMPLETE								    ((uint16_t)0x0001)
#define	TYPE_BLOCK_COMPLETE									    ((uint16_t)0x0002)
#define	TYPE_SOURCE_TRANSACTION_COMPLETE				((uint16_t)0x0004)
#define	TYPE_DESTINATION_TRANSACTION_COMPLETE		((uint16_t)0x0008)
#define	TYPE_ERROR_OCCUR									      ((uint16_t)0x0010)

//StatusInt
#define	STATUS_OCCUR_Error									    ((uint16_t)0x0010)
#define	STATUS_OCCUR_DesTran								    ((uint16_t)0x0008)
#define	STATUS_OCCUR_SrcTran								    ((uint16_t)0x0004)
#define	STATUS_OCCUR_Block									    ((uint16_t)0x0002)
#define	STATUS_OCCUR_Tfr									      ((uint16_t)0x0001)

#define	    SatatusInt_Mask									    ((uint16_t)0x001F)

typedef struct
{
	uint32_t	DMA_SRCBaseAddr;							      //Source Address of DMA tarnsfer        "SARx"  
	uint32_t	DMA_DSTBaseAddr;							      //Destination address of DMA transfer   "DARx"

// CTL
	uint8_t		DMA_DSTTransBusWidth;						    //Destination Transfer Bus Width   "CTLx[3:1]"
	uint8_t		DMA_SRCTransBusWidth;						    //Source    Transfer Bus Width     "CTLx[6:4]" 

	uint8_t		DMA_DSTAddInc;								      //Destination Address Increment     "CTLx[8:7]" //  << 7
	uint8_t		DMA_SRCAddInc;								      //Source Address Increment          "CTLx[10:9]"//  <<9

	uint8_t		DMA_DSTBurstTransactionRequest;			//DMA Request"CTLx[13:11]"   //  <<11
	uint8_t		DMA_SRCBurstTransactionRequest;			//DMA Request"CTLx[16:14]"   //  <<14

  uint8_t		DMA_SrcGatherEn;						        //Source Gather En    "CTLx[17]"   //  <<17
  uint8_t		DMA_DstScatterEn;						        //Destination Scatter En    "CTLx[18]" //  <<18
  
  uint8_t		DMA_SrcDestDirection;						    //Transfer Type and Flow Control    "CTLx[22:20]" //  <<20
	uint16_t	RESERVED0;

	uint8_t   DMA_DSTMasterBusSel;						    //Destination Master Bus Select     "CTLx[24:23]" //  <<23
	uint8_t   DMA_SRCMasterBusSel;						    //Source Master Bus Select          "CTLx[26:25]" //  <<25
	uint16_t  RESERVED1;

  uint8_t		DMA_DstLLPEn;						            //Destination LLP En    "CTLx[27]"
  uint8_t		DMA_SrcLLPEn;						            //Source LLP En    "CTLx[28]"                 

	uint64_t  DMA_BufferSize;                     //  (<<32)-1
  uint8_t		DMA_LLPDone;						            //LLP Done    "CTLx[44]"                           
    
//  CFGx
	uint8_t   DMA_ChannelPriority;						   //Channel Priority                                     //  <<5
	uint8_t   DMA_DSTHandShakingSel;				     //Destination Software or Hardware Handshaking Select  //  <<10
	uint8_t   DMA_SRCHandShakingSel;					   //Source Software or Hardware Handshaking Select       //  <<11
	uint8_t   RESERVED2;                              

  uint8_t		DMA_SrcReloadEn;						       //Source Reload En    "CFGx[30]"
  uint8_t		DMA_DstReloadEn;						       //Destination Reload En    "CFGx[31]"

  uint64_t	DMA_DstUPDEn;						           //Destination State Update En    "CFGx[37]"
  uint64_t	DMA_SrcUPDEn;						           //Source State Update En    "CFGx[38]"

	uint64_t  DMA_SRCHardwarePeriSel;					   //Source peripheral  hardware handshaking interface     //  <<39
	uint64_t  DMA_DSTHardwarePeriSel;				     //Destination peripheral hardware handshaking interface //  <<43
} DMA_InitTypeDef;



  void DMA_SETUP (void);



//----------------------------------------------------------------------
/**@brief DMA ?? ?? ??? 
  @param DMA_CHx : DMA_CH? ?? Pointer
  @param DMA_InitStruct  : DMA? ?? ???? ?? ? Wirte 
**///----------------------------------------------------------------------    
  //void DMA_Init (DMA_Channel_TypeDef* DMA_CHx, DMA_InitTypeDef* DMA_InitStruct);
  void DMA_Init (DMA_Channel_TypeDef* DMA_CHx);
// ssung start
//void DMA_SetDestinationStatusReg(DMA_Channel_TypeDef* DMA_CHx,uint32_t reg);
//void DMA_SetDestinationStatusAddr(DMA_Channel_TypeDef* DMA_CHx,uint32_t addr);
//void DMA_SetDestinationLLIAddr(DMA_Channel_TypeDef* DMA_CHx,uint32_t addr);
//void DMA_SetDestinationBaseAddr(DMA_Channel_TypeDef* DMA_CHx,uint32_t addr);
//void DMA_SetBlockTransferSize(DMA_Channel_TypeDef* DMA_CHx,uint64_t size);
  // ssjung end

//----------------------------------------------------------------------
/**@brief DMA_Cmd DMA? ?? Channel? ?? ? Enalbe
  @param DMA_ch : DMA_CH ??
  @param NewState  : DMA Enable Flag
**///----------------------------------------------------------------------    
//void DMA_Cmd(uint32_t DMA_ch,FunctionalState NewState);
  void DMA_Cmd(uint32_t DMA_ch,uint32_t DMA_chen);

//----------------------------------------------------------------------
/**@brief DMA_Global_Channel_Enable ? ?? Channel? ?? Flag
  @param NewState  : DMA_Global_Channel Flag
**///----------------------------------------------------------------------    
  void DMA_Global_Channel_Enable(FunctionalState NewState);
  // ssjung remove
//FlagStatus DMA_GetLastStatus(uint32_t DMA_FLAG);

//----------------------------------------------------------------------
/**@brief DMA_Clear ??? ?? Flag
  @param FlagType  : Flag
  @param NewState  : DMA Channel ?
**///----------------------------------------------------------------------    
  void DMA_ClearFlag(uint16_t FlagType,uint16_t DMA_ch);

//----------------------------------------------------------------------
/**@brief DMA_ITMaskTfrConfig ??? ?? Flag
  @param DMA_ch  : DMA Channel ?
  @param NewState  : Reset ??
**///----------------------------------------------------------------------    
  void DMA_ITMaskTfrConfig(uint16_t DMA_ch,FlagStatus NewState);
  // ssjung remove
//void DMA_ITMaskErrConfig(uint16_t DMA_ch,FlagStatus NewState);
//----------------------------------------------------------------------
/**@brief DMA_ITConfig DMA Interrupt Enable ?? ?? Function
  @param DMA_ch  : DMA_CHx? ?? pointer ?
  @param NewState  : enable or disable
**///----------------------------------------------------------------------    
  void DMA_ITConfig(__IO DMA_Channel_TypeDef* DMA_CHx, FunctionalState NewState);


  // ssjung add
//  uint16_t DMA_Channel_Select(DMA_Channel_TypeDef* DMAx);
  // ssjung add
  void DMA_Transfer(DMA_Channel_TypeDef* DMA_CHx, uint64_t SRCADDR, uint64_t DESADDR, uint64_t BufferSize);


  DMA_Channel_TypeDef* DMA_GetNonBusyChannel(void);
  uint64_t DMA_GetDmaComponentID(void);
  uint16_t DMA_GetITStatus(void);
  uint16_t DMA_GetRawTfr(void);
  uint16_t DMA_GetRawErr(void);
  uint16_t DMA_GetRawIntBlock(void);
  uint16_t DMA_GetRawSrcTran(void);
  uint16_t DMA_GetRawDstTran(void);

//uint64_t DMA_ChannelxLLPData(DMA_Channel_TypeDef* DMA_CHx);



#endif /* _DMA_H_ */
