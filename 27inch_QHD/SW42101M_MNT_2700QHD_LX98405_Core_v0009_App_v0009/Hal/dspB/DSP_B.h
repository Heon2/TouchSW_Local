/********************************************************************************
  @file     DSP_B.h
  @brief    Touch DSP H/W OpCode
 *******************************************************************************/

/********************************************************************************
  @mainpage TDSP_HW Ver.2.0
  @section intro INTRODUCTION
      This file include touch DSP Ver.2.0 library. All library functions operate
      at SW3704 H/W platform.
  @section createinfo AUTHOR
      - 2012/02/01 by J.H.Kim
  @section modifyinfo REVISION HISTORY
      - 2013/02/20 by S.Y.Kim : modified to improve readability       
  *******************************************************************************/

#ifndef DSP_B_H_
#define DSP_B_H_


#include "algorithm_def.h"


#define REGA0                       0x00
#define REGA1                       0x01
#define REGA2                       0x02
#define REGA3                       0x03
#define REGA4                       0x04
#define REGA5                       0x05
#define REGA6                       0x06
#define REGA7                       0x07
#define REGB0                       0x08
#define REGB1                       0x09
#define REGB2                       0x0A
#define REGB3                       0x0B
#define REGB4                       0x0C
#define REGB5                       0x0D
#define REGB6                       0x0E
#define REGB7                       0x0F
#define REGC0                       0x10
#define REGC1                       0x11
#define REGC2                       0x12
#define REGC3                       0x13
#define REGC4                       0x14
#define REGC5                       0x15
#define REGC6                       0x16
#define REGC7                       0x17
#define MEM00                       0x20
#define CNT0                        0x21
#define CNT1                        0x22
#define CNT2                        0x23
#define CH0FLT00                    0x30
#define CH0FLT01                    0x31
#define CH0FLT02                    0x32
#define CH0FLT03                    0x33
#define CH0FLT04                    0x34
#define CH0FLT05                    0x35
#define CH0FLT06                    0x36
#define CH0FLT07                    0x37
#define CH0FLT08                    0x38
#define CH1FLT                      0x39
#define CH2FLT                      0x3A
#define CH3FLT                      0x3B    
#define CONST_VAL(x)                (0x80 | x)
#define DUMMY                       0xFF

// rdma, wdma data type
#define DM_32BIT                    0x0
#define DM_16BIT                    0x1
#define DM_8BIT                     0x2
#define DM_4BIT                     0x3
#define DM_1BIT                     0x4

// data type
#define DT_8BIT                     0x0
#define DT_16BIT                    0x1
#define DT_32BIT                    0x2
#define DT_4BIT                     0x3
#define DT_1BIT                     0x4

// sign
#define DT_UNSIGNED                 0x0
#define DT_SIGNED                   0x1

// burst size
#define BS_1BURST                   0x0
#define BS_4BURST                   0x1
#define BS_8BURST                   0x2

// filter type
#define FT_1X1                      0x0
#define FT_3X3                      0x1

// position selection type
#define PS_REG                      0x0
#define PS_VAL                      0x1
#define PS_INX                      0x2

// read, write
#define READ                        0x0
#define WRITE                       0x1

// branch condition
#define AL                          0x0
#define EQ                          0x1
#define NE                          0x2
#define GE                          0x3
#define GT                          0x4
#define LE                          0x5
#define LT                          0x6
#define GES                         0x7
#define GTS                         0x8
#define LES                         0x9
#define LTS                         0xA

// branch direction
#define DOWN                        0x0
#define UP                          0x1

// branch line count
#define LINE_CNT(x)                 (x << 2)

// clear mask
#define CLR_WDMA0                   0x2
#define CLR_RDMA0                   0x1

// loop sel
#define LOOP_LT                     0x0
#define LOOP_LE                     0x1

#define LOOP_REGC0                  0x0
#define LOOP_REGC1                  0x1
#define LOOP_REGC2                  0x2
#define LOOP_SOURCE                 0x3

#define NOP()                                       0x00000000
#define ADD(s0, s1, d)                              ((0x01 << 24) | (s0 << 16) | (s1 << 8) | d)
#define SUB(s0, s1, d)                              ((0x03 << 24) | (s0 << 16) | (s1 << 8) | d)
#define MUL(s0, s1, d)                              ((0x04 << 24) | (s0 << 16) | (s1 << 8) | d)
#define DIV(s0, s1, d)                              ((0x06 << 24) | (s0 << 16) | (s1 << 8) | d)
#define SRL(s0, s1, d)                              ((0x07 << 24) | (s0 << 16) | (s1 << 8) | d)
#define SLL(s0, s1, d)                              ((0x08 << 24) | (s0 << 16) | (s1 << 8) | d)
#define AND(s0, s1, d)                              ((0x0A << 24) | (s0 << 16) | (s1 << 8) | d)
#define OR(s0, s1, d)                               ((0x0B << 24) | (s0 << 16) | (s1 << 8) | d)
#define XOR(s0, s1, d)                              ((0x0C << 24) | (s0 << 16) | (s1 << 8) | d)
#define NOT(s0, d)                                  ((0x0D << 24) | (s0 << 16) | d)
#define MOV(s0, d)                                  ((0x0E << 24) | (s0 << 16) | d)
#define CMP(s0, s1)                                 ((0x0F << 24) | (s0 << 16) | (s1 << 8) | DUMMY)
#define ADDS(s0, s1, d)                             ((0x10 << 24) | (s0 << 16) | (s1 << 8) | d)
#define SUBS(s0, s1, d)                             ((0x11 << 24) | (s0 << 16) | (s1 << 8) | d)
#define MULS(s0, s1, d)                             ((0x12 << 24) | (s0 << 16) | (s1 << 8) | d)
#define DIVS(s0, s1, d)                             ((0x14 << 24) | (s0 << 16) | (s1 << 8) | d)
#define SRLS(s0, s1, d)                             ((0x15 << 24) | (s0 << 16) | (s1 << 8) | d)
#define SLLS(s0, s1, d)                             ((0x16 << 24) | (s0 << 16) | (s1 << 8) | d)
#define CMPS(s0, s1)                                ((0x18 << 24) | (s0 << 16) | (s1 << 8) | DUMMY)
#define MRGB(s0, s1, d)                             ((0x19 << 24) | (s0 << 16) | (s1 << 8) | d)
#define MRGS(s0, s1, d)                             ((0x1A << 24) | (s0 << 16) | (s1 << 8) | d)
#define _MIN(s0, s1, d)                              ((0x1B << 24) | (s0 << 16) | (s1 << 8) | d)
#define _MAX(s0, s1, d)                              ((0x1C << 24) | (s0 << 16) | (s1 << 8) | d)
#define CABS(s0, s1)                                ((0x1D << 24) | (s0 << 16) | (s1 << 8) | DUMMY)
#define SLOOP0(st, ed, sel, cs)                     ((0x20 << 24) | (st << 16) | (ed << 8) | (sel<<2) | cs)
#define ELOOP0()                                    ((0x21 << 24))
#define SLOOP1(st, ed, sel, cs)                     ((0x22 << 24) | (st << 16) | (ed << 8) | (sel<<2) | cs)
#define ELOOP1()                                    ((0x23 << 24))
#define SLOOP2(st, ed, sel, cs)                     ((0x24 << 24) | (st << 16) | (ed << 8) | (sel<<2) | cs)
#define ELOOP2()                                    ((0x25 << 24))
#define BR(addr, cond)                              ((0x26 << 24) | (addr << 8) | cond)
#define BRC(addr, dir, cond)                        ((0x27 << 24) | (addr << 8) | (dir<<4) | cond)
#define BL(addr, cond)                              ((0x28 << 24) | (addr << 8) | cond)
#define BLC(addr, dir, cond)                        ((0x29 << 24) | (addr << 8) | (dir<<4) | cond)
#define RDMAC0(addr, sign, dr, bst, bit)            ((0x2A << 24) | (addr << (dr ? 8 : 16)) | (sign<<6) | (dr<<5) | (bst<<3) | bit)
#define WDMAC0(addr, sign, dr, bst, bit)            ((0x2B << 24) | (addr << (dr ? 8 : 16)) | (sign<<6) | (dr<<5) | (bst<<3) | bit)
#define SDMA0(addr, dr, size)                       ((0x2C << 24) | (addr << (dr ? 8 : 16)) | (dr<<5) | size)
#define SDMA1(addr, dr, size)                       ((0x2D << 24) | (addr << (dr ? 8 : 16)) | (dr<<5) | size)
#define SDMA2(addr, dr, size)                       ((0x2E << 24) | (addr << (dr ? 8 : 16)) | (dr<<5) | size)
#define SDMA3(addr, dr, size)                       ((0x2F << 24) | (addr << (dr ? 8 : 16)) | (dr<<5) | size)
#define SRW0(x, y, flt, wr, psel, sign, bit)        ((0x30 << 24) | (x<<16) | (y<<8) | (flt<<7) | (psel<<5) | (sign<<4) | (wr<<3) | bit)
#define SRW1(x, y, flt, wr, psel, sign, bit)        ((0x31 << 24) | (x<<16) | (y<<8) | (flt<<7) | (psel<<5) | (sign<<4) | (wr<<3) | bit)
#define SRW2(x, y, flt, wr, psel, sign, bit)        ((0x32 << 24) | (x<<16) | (y<<8) | (flt<<7) | (psel<<5) | (sign<<4) | (wr<<3) | bit)
#define SRW3(x, y, flt, wr, psel, sign, bit)        ((0x33 << 24) | (x<<16) | (y<<8) | (flt<<7) | (psel<<5) | (sign<<4) | (wr<<3) | bit)
#define RET(type)                                   ((0x34 << 24) | type)
#define WCNT(cnt)                                   ((0x35 << 24) | (cnt<<8))
#define WUNT()                                      ((0x36 << 24))
#define END()                                       ((0x37 << 24))
#define CLR(mask)                                   ((0x38 << 24) | mask)
#define CONST(val, d)                               ((0x39 << 24) | (val<<8) | d)

// size set
#define DMA_SIZE0                                   0
#define DMA_SIZE1                                   1
#define DMA_SIZE2                                   2
#define DMA_SIZE3                                   3

#define DSP_SIZE_CLEAR(addr, size_num)              ((addr) &= (uint32_t)(~(((uint32_t)0xff) << ((size_num)<<3)))); // NOTE : 상수는 컴파일러가 signed로 인식을 한다. 명시적으로 unsigned라고 해 주엉 warning이 발생 하지 않는다.
#define DSP_SIZE_SET(addr, size_num, set_val)       ((addr) |= (uint32_t)(((uint32_t)(set_val)) << ((size_num)<<3))); // NOTE : 상수는 컴파일러가 signed로 인식을 한다. 명시적으로 unsigned라고 해 주엉 warning이 발생 하지 않는다.

#define	REG32P	*(volatile unsigned int*)
#define	REG16P	*(volatile unsigned short*)

uint8_t TMH_Labeling (
    int16_t   *pSrc,          /**< input data buffer pointer */
    uint8_t   *pMap,          /**< output map data buffer pointer */
    uint8_t   bWidth,         /**< width */
    uint8_t   bHeight,        /**< height */
    uint8_t   bStride,        /**< stride */
    int     nThreshold,     /**< threshold */
    short   *pEqTbl         /**< equality table */
);

uint8_t TMH_Labeling_v2 (
    int16_t   *pSrc,          /**< input data buffer pointer */
    uint8_t   *pMap,          /**< output map data buffer pointer */
    uint8_t   bWidth,         /**< width */
    uint8_t   bHeight,        /**< height */
    uint8_t   bStride,        /**< stride */
    int     nThreshold,     /**< threshold */
    short   *pEqTbl        /**< equality table */
);
void TMH_WaterLabelExtension(
    int16_t   *pSrc,          /**< input data buffer pointer */
    uint8_t   *pMap,          /**< output map data buffer pointer */
    uint8_t   bWidth,         /**< width */
    uint8_t   bHeight,        /**< height */
    uint8_t   bStride,        /**< stride */
    int     w_thres,     /**< threshold */
    uint8_t bLabel_num,
    uint8_t bExtend_size
);
void TMH_PreWater(
    int16_t   *pSrc,          /**< input data buffer pointer */
    uint8_t   *pMap,          /**< output map data buffer pointer */
    uint8_t   bWidth,         /**< width */
    uint8_t   bHeight,        /**< height */
    uint8_t   bStride,        /**< stride */
    int     w_thres,     /**< threshold */
    uint8_t bLabel_num,
    uint8_t bExtend_size
);
void TMH_PreWater_v10(
    int16_t   *pSrc,          /**< input data buffer pointer */
    uint8_t   *pMap,          /**< output map data buffer pointer */
    uint8_t   bWidth,         /**< width */
    uint8_t   bHeight,        /**< height */
    uint8_t   bStride,        /**< stride */
    int     p_th,     /**< threshold */
    int     m_th,
    uint8_t bLabel_num,
    uint8_t bExtend_size
);
void TMH_PartialAccum_v3 (
    short   *pSrc,          /**< input data buffer pointer */
    short   *pDst,          /**< output data buffer pointer */
    uint8_t   bWidth,         /**< width */
    uint8_t   bHeight,        /**< height */
    uint8_t   bStride,        /**< stride */
	uint8_t		*map,			/**< map */
    char    bThre           /**< threshold */
);

void TMH_DC_Remove (
    short   *pSrc,          /**< input data buffer pointer */
    short   *pDst,          /**< output data buffer pointer */
    uint8_t   bWidth,         /**< width */
    uint8_t   bHeight,        /**< height */
    uint8_t   bStride,        /**< stride */
    uint8_t   bDC_LevSft,     /**< DC level shift */
    uint8_t   bWeightSft      /**< weight shift */
);

void TMH_CompenForAKS(
	short   *pSrc,          /**< input data buffer pointer */
	short   *pDst,          /**< output data buffer pointer */
	uint8_t   bWidth,         /**< width */
    uint8_t   bHeight,        /**< height */
	uint8_t   bStride,        /**< stride */
	short   bThre
);

uint16_t TMH_1cell_noise_remove(
    int16_t		*pSrc,			/**< input data buffer pointer */
    int16_t		*pDst,			/**< output data buffer pointer */
    uint8_t	bWidth,			/**< width */
    uint8_t	bHeight,		/**< height */
    uint8_t	bStride,		/**< stride */
	uint16_t	bChkThr,		/**< check threshold */
	uint16_t	bAbsThr,		/**< Absolute threshold */
	uint16_t	bOriThr,		/**< Original threshold */
	uint16_t	bSameThr,		/**< SameValue threshold */
	uint16_t	bCentThr		/**< CneterValue threshold */
);

void TMH_PenCoordinate(tPenCoordInfo_t *pTCoordInfo, tPenLabelInfo_t *pTLabelInfo, tEdgePen_t *pTEdgePen, int mode);
void TMH_PenLabeling (
    int16_t             *pSrc,          /**< input data buffer pointer */
    uint8_t           *pMap,          /**< output map data buffer pointer */
    tPenLabelInfo_t *pTLabelInfo,   /**< output label info buffer pointer */
    int             nLabelInfoSize, /**< label info size */
    int             nStart_r,       /**< start row */
    int             nEnd_r,         /**< end row */
    int             nStart_c,       /**< start column */
    int             nEnd_c,         /**< end column */
    int             nThreshold,     /**< threshold */
    uint8_t         ucPadSize       /**< pad size */
);
    
void TMH_MarkBoundary (
    uint8_t        *pLabel,         //< input Label buffer pointer 
    int16_t        *pDelta,         //< input Delta buffer pointer
    int32_t         nStart_r,       //< start row 
    int32_t         nEnd_r,         //< end row 
    int32_t         nStart_c,       //< start column 
    int32_t         nEnd_c,         //< end column 
    int32_t         nTable_num,     //< 4data or 8data
    tPenLabelInfo_t *tTable,        //< Output tTable Structure pointer
    int32_t         Boundary,
    uint8_t	        ucPad_size
);
    
void TMH_PenCalDelta (
    uint16_t        *pRawImg,       /**< input raw data buffer pointer */
    uint16_t        *pBaseImg,      /**< input base data buffer pointer */
    uint8_t         *pNormalTbl,    /**< input normalize look-up table data buffer pointer */
    int16_t         *pDeltaImg,     /**< output delta data buffer pointer */
    tOrigDeltaInfo_t *pPenDeltaInfo, /**< output pen delta info buffer pointer */
    int             nCurrRowStart,  /**< start current row */
    int             nCurrColStart,  /**< start current column */
    int             nWidth,         /**< width */
    int             nHeight,        /**< height */
    bool_t            bNormalize,     /**< normalize flag */
    uint8_t         ucOvrShift,     /**< delta OvrShift */
    uint16_t        uint8_tSeedBase,     /**< label seed base threshold */
    uint8_t         ucMuxRowSize,   /**< mux row size */
    uint8_t         ucPadSize       /**< pad size */
);

void TMH_PenCoordInitialize(tPenCoordInfo_t *pTCoordInfo, tOrigDeltaInfo_t *pPenDeltaInfo);
void TMH_PenUpdatePostHistoryInfo(tPenCoordInfo_t *pTCoordInfo);
void algorithm_local_dsp_process(int index, ePartialSensing_t RetVal, int mode);
void algorithm_hover_full_search(void);
bool_t algorithm_mode_change_check(void);
void algorithm_hover_accum_process(void);
void algorithm_hover_accum_move(void);
bool_t algorithm_local_baseline_tracking_initial(void);
void algorithm_data_local_process(ePartialSensing_t RetVal);
void alogorithm_coord_modify_pos_local(tXY_t* pos);


// warning 발생하여 추가
void algorithm_coord_init_local_DSP(void);

/*
 * NOTE : define안으로 위치 변경!!
 */
extern void algorithm_init_local(void);
extern void init_DSP_B(void);
extern void Clear_DSP_B_Intr(void);

// NOTE : DSP_B_code.c에서 구현된 함수를 외부에서 참조하는 경우에도 일단 여기다 extern으로 선언
extern void algorithm_local_init(void);
extern void algorithm_local_baseline_init(void);
extern void algorithm_baseline_calculate_local_mux_range(int r, int c);
extern void algorithm_coord_init_local(void);


#endif /* DSP_B_H_ */

/*
 * NOTE : 왜 아래 함수는 디파인안에 포함을 안시켰지?
 */
//Extern 
//extern void algorithm_init_local(void);
//extern void init_DSP_B(void);
//extern void Clear_DSP_B_Intr(void);
