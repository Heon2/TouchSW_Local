/**
 ******************************************************************************
 * @file    SiWApp_tdsp.h
 * @author  Touch Team, Silicon Works Co., Ltd.
 * @version V1.0
 * @date    2016/06/17
 * @description   
 ******************************************************************************       
 */

#ifndef _SW3711_TDSP2_H_
#define _SW3711_TDSP2_H_

#define TDSP_BASE_ADDR           0x4000A000

/*
 ******************************************************************************
 * Peripheral Group 'TDSP'  Structure 
 ******************************************************************************
 */
 
/*
 ******************************************************************************
 * TDSP2 Controller Peripheral Group Function Definitions
 ******************************************************************************
 */		  

#define REG_TDSP2_A0	 		(REG32P(TDSP_BASE_ADDR + 0x00))
#define REG_TDSP2_A1	 		(REG32P(TDSP_BASE_ADDR + 0x04))
#define REG_TDSP2_A2	 		(REG32P(TDSP_BASE_ADDR + 0x08))
#define REG_TDSP2_A3	 		(REG32P(TDSP_BASE_ADDR + 0x0C))
#define REG_TDSP2_A4	 		(REG32P(TDSP_BASE_ADDR + 0x10))
#define REG_TDSP2_A5	 		(REG32P(TDSP_BASE_ADDR + 0x14))
#define REG_TDSP2_A6	 		(REG32P(TDSP_BASE_ADDR + 0x18))
#define REG_TDSP2_A7	 		(REG32P(TDSP_BASE_ADDR + 0x1C))

#define REG_TDSP2_B0	 		(REG32P(TDSP_BASE_ADDR + 0x20))
#define REG_TDSP2_B1	 		(REG32P(TDSP_BASE_ADDR + 0x24))
#define REG_TDSP2_B2	 		(REG32P(TDSP_BASE_ADDR + 0x28))
#define REG_TDSP2_B3	 		(REG32P(TDSP_BASE_ADDR + 0x2C))
#define REG_TDSP2_B4	 		(REG32P(TDSP_BASE_ADDR + 0x30))
#define REG_TDSP2_B5	 		(REG32P(TDSP_BASE_ADDR + 0x34))
#define REG_TDSP2_B6	 		(REG32P(TDSP_BASE_ADDR + 0x38))					
#define REG_TDSP2_B7	 		(REG32P(TDSP_BASE_ADDR + 0x3C))

#define REG_TDSP2_C0	 		(REG32P(TDSP_BASE_ADDR + 0x40))
#define REG_TDSP2_C1	 		(REG32P(TDSP_BASE_ADDR + 0x44))
#define REG_TDSP2_C2	 		(REG32P(TDSP_BASE_ADDR + 0x48))
#define REG_TDSP2_C3	 		(REG32P(TDSP_BASE_ADDR + 0x4C))
#define REG_TDSP2_C4	 		(REG32P(TDSP_BASE_ADDR + 0x50))
#define REG_TDSP2_C5	 		(REG32P(TDSP_BASE_ADDR + 0x54))
#define REG_TDSP2_C6	 		(REG32P(TDSP_BASE_ADDR + 0x58))
#define REG_TDSP2_C7	 		(REG32P(TDSP_BASE_ADDR + 0x5C))

#define REG_TDSP2_PC	 		(REG32P(TDSP_BASE_ADDR + 0x100))
#define REG_TDSP2_BUSY	 		(REG32P(TDSP_BASE_ADDR + 0x124))
#define REG_TDSP2_OPCODE_BASEADDR	(REG32P(TDSP_BASE_ADDR + 0x128))
#define REG_TDSP2_INTERRUPT		(REG32P(TDSP_BASE_ADDR + 0x138))

#define REG_TDSP2_XSIZE 		(REG32P(TDSP_BASE_ADDR + 0x200))
#define REG_TDSP2_YSIZE 		(REG32P(TDSP_BASE_ADDR + 0x204))
#define REG_TDSP2_DMA_BASEADDR	(REG32P(TDSP_BASE_ADDR + 0x208))

#endif  /* _SW3711_TDSP2_H_ */

