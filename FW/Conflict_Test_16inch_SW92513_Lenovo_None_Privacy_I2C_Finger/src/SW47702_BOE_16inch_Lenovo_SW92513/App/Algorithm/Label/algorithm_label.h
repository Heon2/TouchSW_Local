/*
 * algorithm_label.h
 *
 *  Created on: 2015. 5. 6.
 *      Author: parkyj2
 */

#ifndef __ALGORITHM_LABEL_H__
#define __ALGORITHM_LABEL_H__

typedef struct
{
	uint16_t usSeedBase;
	uint8_t  ucSeedSlope;
	uint8_t  ucLabelNoiseThd;
	bool_t   bExpand;
	bool_t   bSplitSearchDirc_4_On;
	uint16_t usSmallNodeCnt;
	uint16_t usMediumNodeCnt;
	uint8_t  ucMergeSmallThdPer;
	uint8_t  ucMergeMediumThdPer;
	uint8_t  ucMergeSmallDiagThdPer;
	uint8_t  ucMergeMediumDiagThdPer;

	uint16_t usLocalSeedBase;
	uint8_t  ucLocalSeedSlope;
	uint16_t usLocalSmallNodeCnt;
	uint16_t usLocalMediumNodeCnt;
	uint8_t  ucLocalMergeSmallThdPer;
	uint8_t  ucLocalMergeMediumThdPer;
	uint16_t usLocalSeedBase_Ring;
	uint8_t  ucRingSeedBase_Acoef;
	uint8_t  ucRingSeedBase_Fcoef;
	uint8_t  ucLocalPenDetectTH1;
	uint8_t  ucLocalPenDetectTH2;
	uint8_t  ucLocalPenDetectTH1_Offset;
	uint8_t  ucLocalPenDetectTH2_Offset;
	uint8_t  ucLocalPenRingDetectTH1;
	uint8_t  ucLocalPenRingDetectTH2;
	uint8_t  ucHoverInCheckFrm;
	uint8_t  ucHoverOutCheckFrm;
	uint8_t  ucHoverOutOffset;
	
	uint16_t usLabelPeakValleyDiffTh;
	uint16_t usLabelPeakDiffTh;
	uint16_t usMergeLabelSizeTh;
} __PACKED tAlgorithmLabelConf_t;

typedef union
{
	struct
	{
		uint32_t BF       : LOOSE_POSBUF_;
		uint32_t NUM      : 8;
		uint32_t Reserved : 7;
		uint32_t SET      : 1;
	} __PACKED tInfo;

	uint32_t ulValue;
} __PACKED tConflictInfo_t;

typedef struct
{
	int8_t   cId;
	tRect_t  tRect;
	uint16_t usCellNum;
	int16_t sMaxCellVal;
	tCell_t  tMaxCell;
	tXY_t    tCoord;
	uint32_t ulStrength;
	uint32_t ulExtStrength;

	tConflictInfo_t tConflictInfo;

	uint32_t * ptListHead;
	uint32_t * ptListTail;
} __PACKED tLabelTable_t;

#define BOUNDARY_4_SEARCH_DIRECTION		4
#define BOUNDARY_8_SEARCH_DIRECTION		8

typedef struct
{
	uint8_t Num;
	tCell_t Table[BOUNDARY_4_SEARCH_DIRECTION];
} __PACKED t4SearchInfo_t;

typedef struct
{
	uint8_t Num;
	tCell_t Table[BOUNDARY_8_SEARCH_DIRECTION];
} __PACKED t8SearchInfo_t;

typedef struct
{
	uint8_t	ucNum;
	tLabelTable_t tTable[LOOSE_POSBUF_];
	uint8_t ucValidNum;
	tRect_t tValidRect[LOOSE_POSBUF_];
	tCell_t tValidMaxPos[LOOSE_POSBUF_];
	int16_t sValidMaxVal[LOOSE_POSBUF_];
	uint16_t usValidCellCnt[LOOSE_POSBUF_];

	uint8_t PalmTouchDownCnt;
#if (PENnPalm_PalmAreaMaintain_EN == YES)
	uint8_t TouchFrameCnt;
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */	
	int32_t LabelSplitCnt;
//	int32_t LabelNearbyCnt;
	int16_t LabelSplitMergeCnt;
	int32_t LabelSplitFrmCnt;
	uint16_t uValidLabelNum;
	int32_t iMergeThdPer;
	uint8_t ucPalmCnt;

#if LABEL_FAST_EN
	uint8_t ucLabel_Check[ARRAY_ROW][ARRAY_COL];
#endif
} __PACKED tLabelInfo_t;

typedef struct
{
    int16_t     cId;             						  //  0, 0, 0
    tRect_t     tValidRect;       						//  2, 1, 0
    uint16_t    usValidCellCnt;   						//  6, 3, 0
    int16_t     sValidMaxVal;     						//  8, 4, 2
    tCell_t     tValidMaxPos;     						// 10, 5, 0
    tXY_t       tCoord;           						// 12, 6, 3
    uint32_t    ulStrength;       						// 20, 10, 5
    uint32_t    ulExtStrength;   						  // 24, 12, 6
} __PACKED tPenLabelInfo_t;    // 28, 14, 7

#define LABEL_INFO_SIZE    sizeof(tPenLabelInfo_t)
	
extern void algorithm_label_init(void);
extern void algorithm_label_init_param(void);
extern void algorithm_label_process(int mode);
void algorithm_label_SearchValidAreaforPen(tRect_t _tRect, int16_t _deltaThd, int mode);
#if USED_PEN_MODE_OPERATION
#if (DeltaBaseNewEdgeCompen_SW == YES)
extern void algorithm_label_EdgeExpand_DeltaBase(int mode,int iRetVal, int TiltMode);
#endif
#endif /* USED_PEN_MODE_OPERATION */
extern void algorithm_label_EdgeExpand_DeltaBase_ADD(int mode);

#endif /* __ALGORITHM_LABEL_H__ */
