/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _usb.h
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

#ifndef __USB_H_
#define __USB_H_


/**
  * @brief USB Control Register(USB)
  */
typedef struct {
		uint32_t	HCCAP; /*HC Capability Register	0x00*/
		uint32_t	HCSPARAMS; /*HC Structural Parameters	0x04*/
		uint32_t	HCCPARAMS; /*HC Capability Parameters	0x08*/
		uint32_t	Reserved0;
		uint32_t	USBCMD; /*HC USB Command Register	0x10*/
		uint32_t	USBSTS; /*HC USB Status Register	0x14*/
		uint32_t	USBINTR; /*HC USB Interrupt Enable Register	0x18*/
		uint32_t	FRINDEX; /*HC Frame Index Register	0x1C*/
		uint32_t	Reserved1;
		uint32_t	PERIODICLISTBASE; /*HC Periodic Frame List Base Address Register	0x24*/
		uint32_t	ASYNCLISTADDR; /*HC Current Asynchronous List Address Register	0x28*/
		uint32_t	Reserved2;
		uint32_t	PORTSC; /*HC Port Status and Control Register	0x30*/
		uint32_t	Reserved3[3];
		uint32_t	HCMISC; /*HC Miscellaneous Register	0x40*/
		uint32_t	FS_EOF; /*HC Full-Speed (FS) EOF1 Timing Point Register	0x44*/
		uint32_t	HS_EOF; /*HC High-Speed (HS) EOF1 Timing Point Register	0x48*/
} USB_HC_TypeDef;		
		
typedef struct {
		uint32_t	OTG_CSR; /*OTG Control Status Register	0x80*/
		uint32_t	OTG_ISR; /*OTG Interrupt Status Register	0x84*/
		uint32_t	OTG_IER; /*OTG Interrupt Enable Register	0x88*/
} USB_OTG_TypeDef;

typedef struct {
		uint32_t	GLB_ISR; /*Global HC/OTG/DEV Interrupt Status Register	0xC0*/
		uint32_t	GLB_INT; /*Global Mask of HC/OTG/DEV Interrupt Register	0xC4*/
		uint32_t	Reserved0[6];
		uint32_t	REVISION; /*Revision Information Register	0xE0*/
		uint32_t	FEATURE; /*Configured Information Register	0xE4*/
} USB_GLOBAL_TypeDef;

typedef struct {
		uint32_t	DEV_CTL; /*Device Main Control Register	0x100*/
		uint32_t	DEV_ADR; /*Device Address Register	0x104*/
		uint32_t	DEV_TST; /*Device Test Register	0x108*/
		uint32_t	DEV_SFN; /*Device SOF Frame Number Register	0x10C*/
		uint32_t	DEV_SMT; /*Device SOF Mask Timer Register	0x110*/
		uint32_t	PHY_TST; /*PHY Test Mode Selector Register	0x114*/
		uint32_t	DEV_VCTL; /*Device Vendor-Speci?c I/O Control Register	0x118*/
		uint32_t	DEV_CXCFG; /*Device CX Con?guration Status Register	0x11C*/
		uint32_t	DEV_CXCFE; /*Device CX Con?guration and FIFO Empty Status Register	0x120*/
		uint32_t	DEV_ICR; /*Device Idle Counter Register	0x124*/
		uint32_t	Reserved0[2];
		uint32_t	DEV_MIGR; /*Device Mask of Interrupt Group Register	0x130*/
		uint32_t	DEV_MISG0; /*Device Mask of Interrupt Source Group 0 Register	0x134*/
		uint32_t	DEV_MISG1; /*Device Mask of Interrupt Source Group 1 Register	0x138*/
		uint32_t	DEV_MISG2; /*Device Mask of Interrupt Source Group 2 Register	0x13C*/
		uint32_t	DEV_IGR; /*Device Interrupt Group Register	0x140*/
		uint32_t	DEV_ISG0; /*Device Interrupt Source Group 0 Register	0x144*/
		uint32_t	DEV_ISG1; /*Device Interrupt Source Group 1 Register	0x148*/
		uint32_t	DEV_ISG2; /*Device Interrupt Source Group 2 Register	0x14C*/
		uint32_t	DEV_RXZ; /*Device Receive Zero-Length Data Packet Register	0x150*/
		uint32_t	DEV_TXZ; /*Device Transfer Zero-Length Data Packet Register	0x154*/
		uint32_t	DEV_ISE; /*Device lsochronous Sequential Error/Abort Register	0x158*/
		uint32_t	Reserved1;
		uint32_t	DEV_INMPS1; /*Device IN Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x160*/
		uint32_t	DEV_INMPS2; /*Device IN Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x164*/
		uint32_t	DEV_INMPS3; /*Device IN Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x168*/
		uint32_t	DEV_INMPS4; /*Device IN Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x16C*/
		uint32_t	DEV_INMPS5; /*Device IN Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x170*/
		uint32_t	DEV_INMPS6; /*Device IN Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x174*/
		uint32_t	DEV_INMPS7; /*Device IN Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x178*/
		uint32_t	DEV_INMPS8; /*Device IN Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x17C*/
		uint32_t	DEV_OUTMPS1; /*Device OUT Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x180*/
		uint32_t	DEV_OUTMPS2; /*Device OUT Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x184*/
		uint32_t	DEV_OUTMPS3; /*Device OUT Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x188*/
		uint32_t	DEV_OUTMPS4; /*Device OUT Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x18C*/
		uint32_t	DEV_OUTMPS5; /*Device OUT Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x190*/
		uint32_t	DEV_OUTMPS6; /*Device OUT Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x194*/
		uint32_t	DEV_OUTMPS7; /*Device OUT Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x198*/
		uint32_t	DEV_OUTMPS8; /*Device OUT Endpoint n MaxPacketSize Register (n = 1 ~ 8)	0x19C*/
		uint32_t	DEV_EPMAP0; /*Device Endpoint 1 ~ 4 Map Register	0x1A0*/
		uint32_t	DEV_EPMAP1; /*Device Endpoint 5 ~ 8 Map Register	0x1A4*/
		uint32_t	DEV_FMAP; /*Device FIFO Map Register	0x1A8*/
		uint32_t	DEV_FCFG; /*Device FIFO Con?guration Register	0x1AC*/
		uint32_t	DEV_FIBC0; /*Device FIFO n Instruction and Byte Count Register (n = 0 ~ 3)	0x1B0*/
		uint32_t	DEV_FIBC1; /*Device FIFO n Instruction and Byte Count Register (n = 0 ~ 3)	0x1B4*/
		uint32_t	DEV_FIBC2; /*Device FIFO n Instruction and Byte Count Register (n = 0 ~ 3)	0x1B8*/
		uint32_t	DEV_FIBC3; /*Device FIFO n Instruction and Byte Count Register (n = 0 ~ 3)	0x1BC*/
		uint32_t	DMA_TFN; /*Device DMA Target FIFO Number Register	0x1C0*/
		uint32_t	DMA_CPS0; /*Device DMA Controller Parameter Setting 0 Register	0x1C4*/
		uint32_t	DMA_CPS1; /*Device DMA Controller Parameter Setting 1 Register	0x1C8*/
		uint32_t	DMA_CPS2; /*Device DMA Controller Parameter Setting 2 Register	0x1CC*/
		uint32_t	DMA_CPS3; /*Device DMA Controller Parameter Setting 3 Register	0x1D0*/
		uint32_t	Reserved2[75];
		uint32_t	VDMA_CXFPS1; /*Device Virtual DMA CXF Parameter Setting 1 Register	0x300*/
		uint32_t	VDMA_CXFPS2; /*Device Virtual DMA CXF Parameter Setting 2 Register	0x304*/
		uint32_t	VDMA_F0PS1; /*Device Virtual DMA FIFO0 Parameter Setting 1 Register	0x308*/
		uint32_t	VDMA_F0PS2; /*Device Virtual DMA FIFO0 Parameter Setting 2 Register	0x30C*/
		uint32_t	VDMA_F1PS1; /*Device Virtual DMA FIFO1 Parameter Setting 1 Register	0x310*/
		uint32_t	VDMA_F1PS2; /*Device Virtual DMA FIFO1 Parameter Setting 2 Register	0x314*/
		uint32_t	VDMA_F2PS1; /*Device Virtual DMA FIFO2 Parameter Setting 1 Register	0x318*/
		uint32_t	VDMA_F2PS2; /*Device Virtual DMA FIFO2 Parameter Setting 2 Register	0x31C*/
		uint32_t	VDMA_F3PS1; /*Device Virtual DMA FIFO3 Parameter Setting 1 Register	0x320*/
		uint32_t	VDMA_F3PS2; /*Device Virtual DMA FIFO3 Parameter Setting 2 Register	0x324*/
		uint32_t	DEV_ISG3; /*Device Interrupt Source Group 3 Register	0x328*/
		uint32_t	DEV_MISG3; /*Device Mask of Interrupt Source Group 3 Register	0x32C*/
		uint32_t	VDMA_CTRL; /*Device Virtual DMA Control Register	0x330*/
		uint32_t	LPM_CAP; /*Device LPM Capability Register	0x334*/
		uint32_t	DEV_ISG4; /*Device Interrupt Source Group 4 Register	0x338*/
		uint32_t	DEV_MISG4; /*Device Mask of Interrupt Source Group 4 Register	0x33C*/
} USB_DEVICE_TypeDef;


#endif /* __USB_H_ */
