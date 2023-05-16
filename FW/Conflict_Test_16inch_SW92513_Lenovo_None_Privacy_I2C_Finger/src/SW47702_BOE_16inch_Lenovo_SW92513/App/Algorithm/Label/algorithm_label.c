/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  algorithm_label.c
 * created on :  17. 4. 2017
 * Author :  mhjang
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

#include "core_def.h"


//static const tAlgorithmCommonConf_t * thisCommonConf = NULL;
static const tAlgorithmModeConf_t * thisModeConf = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;

tRect_t PalmRect[POSBUF_];
uint8_t PalmRegionNum = 0, PalmRectEnable[POSBUF_] = {0};
#if (PENnPalm_PalmAreaMaintain_EN == YES)
uint8_t PenEnable = 0;
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */

//void algorithm_label_mark_boundary(tRect_t _label_rect);

static t4SearchInfo_t BOUNDARY_4_SEARCH_TABLE[BOUNDARY_4_SEARCH_DIRECTION + 1]  =
{
	{ 4, {{-1,  0}, { 0, -1}, { 1,  0}, { 0,  1}} },
	{ 3, {{-1,  0}, { 0, -1}, { 0,  1}, { 0,  0}} }, /* {-1,  0} */
	{ 3, {{-1,  0}, { 0, -1}, { 1,  0}, { 0,  0}} }, /* { 0, -1} */
	{ 3, {{ 0, -1}, { 1,  0}, { 0,  1}, { 0,  0}} }, /* { 1,  0} */
	{ 3, {{-1,  0}, { 1,  0}, { 0,  1}, { 0,  0}} }, /* { 0,  1} */
};

static t8SearchInfo_t BOUNDARY_8_SEARCH_TABLE[BOUNDARY_8_SEARCH_DIRECTION + 1]  =
{
	{ 8, {{-1,  0}, {-1, -1}, { 0, -1}, { 1, -1}, { 1,  0}, { 1,  1}, { 0,  1}, {-1,  1}} },
#if 1
	{ 7, {{ 1,  1}, { 0,  1}, {-1,  1}, {-1,  0}, {-1, -1}, { 0, -1}, { 1, -1}, { 0,  0}} },
	{ 6, {{-1,  1}, {-1,  0}, {-1, -1}, { 0, -1}, { 1, -1}, { 1,  0}, { 0,  0}, { 0,  0}} },
	{ 5, {{-1, -1}, { 0, -1}, { 1, -1}, { 1,  0}, { 1,  1}, { 0,  0}, { 0,  0}, { 0,  0}} },
	{ 6, {{-1, -1}, { 0, -1}, { 1, -1}, { 1,  0}, { 1,  1}, { 0,  1}, { 0,  0}, { 0,  0}} },
	{ 5, {{ 1, -1}, { 1,  0}, { 1,  1}, { 0,  1}, {-1,  1}, { 0,  0}, { 0,  0}, { 0,  0}} },
	{ 6, {{ 1, -1}, { 1,  0}, { 1,  1}, { 0,  1}, {-1,  1}, {-1,  0}, { 0,  0}, { 0,  0}} },
	{ 4, {{ 1,  1}, { 0,  1}, {-1,  1}, {-1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}} },
	{ 5, {{ 1,  1}, { 0,  1}, {-1,  1}, {-1,  0}, {-1, -1}, { 0,  0}, { 0,  0}, { 0,  0}} }
#else
	{ 7, {{-1,  0}, {-1, -1}, { 0, -1}, { 1, -1}, { 1,  1}, { 0,  1}, {-1,  1}, { 0,  0}} }, /* -1,  0 */
	{ 7, {{-1,  0}, {-1, -1}, { 0, -1}, { 1, -1}, { 1,  0}, { 0,  1}, {-1,  1}, { 0,  0}} }, /* -1, -1 */
	{ 7, {{-1,  0}, {-1, -1}, { 0, -1}, { 1, -1}, { 1,  0}, { 1,  1}, {-1,  1}, { 0,  0}} }, /*  0, -1 */
	{ 7, {{-1,  0}, {-1, -1}, { 0, -1}, { 1, -1}, { 1,  0}, { 1,  1}, { 0,  1}, { 0,  0}} }, /*  1, -1 */
	{ 7, {{-1, -1}, { 0, -1}, { 1, -1}, { 1,  0}, { 1,  1}, { 0,  1}, {-1,  1}, { 0,  0}} }, /*  1,  0 */
	{ 7, {{-1,  0}, { 0, -1}, { 1, -1}, { 1,  0}, { 1,  1}, { 0,  1}, {-1,  1}, { 0,  0}} }, /*  1,  1 */
	{ 7, {{-1,  0}, {-1, -1}, { 1, -1}, { 1,  0}, { 1,  1}, { 0,  1}, {-1,  1}, { 0,  0}} }, /*  0,  1 */
	{ 7, {{-1,  0}, {-1, -1}, { 0, -1}, { 1,  0}, { 1,  1}, { 0,  1}, {-1,  1}, { 0,  0}} }  /* -1,  1 */
#endif
};

//int dbg_label[6] = {0,};

void algorithm_label_init(void)
{
//	int r, c;

	algorithm_label_init_param();
//	thisCommonConf = algorithm_GetCommonConfig();
	thisInfo       = algorithm_GetInfo();

	memset(LABELIMAGE,0,sizeof(LABELIMAGE));
	memset(COMMONIMAGE,0,sizeof(COMMONIMAGE));
//	for( r=-PAD_; r<ROW_MAX + PAD_; r++ )
//	{
//		for( c=-PAD_; c<COL_MAX + PAD_; c++ )
//		{
//			HAL_WRITE_LABEL_IMAGE(r, c, 0);
//			HAL_WRITE_LABEL_LINKLIST_IMAGE(r, c, 0);
//		}
//	}
}

void algorithm_label_init_param(void)
{
	thisModeConf   = algorithm_GetModeConfig();
}

void algorithm_label_initialise(int mode)
{
//	int r, c, l; // NOTE : not used!!
	int l;

	tLabelInfo_t 		*temp_label;

	temp_label = &thisInfo->tLabel;

	temp_label->ucNum = 0;
	temp_label->ucValidNum = 0;

	for( l=LOOSE_POSBUF_; l--; )
	{
		memset(&temp_label->tTable[l], 0x00, sizeof(tLabelTable_t));

		temp_label->tValidRect[l].cs            = COL_MAX-1;
		temp_label->tValidRect[l].ce            = 0;
		temp_label->tValidRect[l].rs            = ROW_MAX-1;
		temp_label->tValidRect[l].re            = 0;
		temp_label->sValidMaxVal[l]             = 0;
		temp_label->usValidCellCnt[l]           = 0;
		temp_label->tValidMaxPos[l].c           = 0;
		temp_label->tValidMaxPos[l].r           = 0;
	}
#if (LABEL_FAST_EN != 2)
	memset(LABELIMAGE,0,sizeof(LABELIMAGE));
#endif
	memset(COMMONIMAGE,0,sizeof(COMMONIMAGE));
}

//#define GET_ROW_INDEX_FROM_ADDR_OF_LINKEDLIST(Addr) 	((((unsigned long)Addr - (unsigned long)HAL_GET_LABEL_LINKLIST_IMAGE_PTR())/sizeof(unsigned long))/(COL_MAX + 2*PAD_) - PAD_)
//#define GET_COL_INDEX_FROM_ADDR_OF_LINKEDLIST(Addr) 	((((unsigned long)Addr - (unsigned long)HAL_GET_LABEL_LINKLIST_IMAGE_PTR())/sizeof(unsigned long))%(COL_MAX + 2*PAD_) - PAD_)
#define GET_ROW_INDEX_FROM_ADDR_OF_LINKEDLIST(Addr) 	((((unsigned long)Addr - (unsigned long)HAL_GET_LABEL_LINKLIST_IMAGE_PTR())>>2)/(COL_MAX + 2*PAD_) - PAD_)
#define GET_COL_INDEX_FROM_ADDR_OF_LINKEDLIST(Addr) 	((((unsigned long)Addr - (unsigned long)HAL_GET_LABEL_LINKLIST_IMAGE_PTR())>>2)%(COL_MAX + 2*PAD_) - PAD_)
#define GET_NEWNODE_FOR_LINKEDLIST(r, c)				HAL_GET_LABEL_LINKLIST_NODE_PTR(r, c)

void algorithm_label_Insert_NewRecord_to_LabelTable(uint8_t _idx, tCell_t _tCell, int16_t _d, bool_t _bAdd2List, int mode)
{
	tLabelInfo_t	*temp_label;
	
	temp_label = &thisInfo->tLabel;

	if( _idx < LOOSE_POSBUF_ )
	{
		temp_label->tTable[_idx].cId          = _idx + 1;
		temp_label->tTable[_idx].sMaxCellVal  = _d;
		temp_label->tTable[_idx].tMaxCell     = _tCell;
		temp_label->tTable[_idx].tRect.rs     = _tCell.r;
		temp_label->tTable[_idx].tRect.re     = _tCell.r;
		temp_label->tTable[_idx].tRect.cs     = _tCell.c;
		temp_label->tTable[_idx].tRect.ce     = _tCell.c;
		temp_label->tTable[_idx].tCoord.x     = _tCell.c * _d;
		temp_label->tTable[_idx].tCoord.y     = _tCell.r * _d;
		temp_label->tTable[_idx].ulStrength   = _d;
		temp_label->tTable[_idx].ulExtStrength= _d;
		temp_label->tTable[_idx].usCellNum    = 1;

//		if( _bAdd2List )
//		{
//			temp_label->tTable[_idx].ptListHead = GET_NEWNODE_FOR_LINKEDLIST(_tCell.r, _tCell.c);
//			temp_label->tTable[_idx].ptListTail = temp_label->tTable[_idx].ptListHead;
//		}

		HAL_WRITE_LABEL_IMAGE(_tCell.r, _tCell.c, temp_label->tTable[_idx].cId);

		temp_label->ucNum++;
	}
}

void algorithm_label_Add_NewNode_to_LabelRecord(uint8_t _idx, tCell_t _tCell, int16_t _d, bool_t _bBoundary, bool_t _bAdd2List, int mode)
{
	tLabelInfo_t	*temp_label;

	temp_label = &thisInfo->tLabel;

	if(_d < 0) _d = 0;
	
	temp_label->tTable[_idx].tCoord.x      += _tCell.c * _d;
	temp_label->tTable[_idx].tCoord.y      += _tCell.r * _d;
	temp_label->tTable[_idx].ulExtStrength += _d;
	if( _bBoundary == NO )
	{
		temp_label->tTable[_idx].ulStrength    += _d;
		temp_label->tTable[_idx].usCellNum++;

		if( temp_label->tTable[_idx].sMaxCellVal < _d )
		{
			temp_label->tTable[_idx].sMaxCellVal = _d;
			temp_label->tTable[_idx].tMaxCell.r = _tCell.r;
			temp_label->tTable[_idx].tMaxCell.c = _tCell.c;
		}

		if( temp_label->tTable[_idx].tRect.rs > _tCell.r )
			temp_label->tTable[_idx].tRect.rs = _tCell.r;
		if( temp_label->tTable[_idx].tRect.re < _tCell.r )
			temp_label->tTable[_idx].tRect.re = _tCell.r;
		if( temp_label->tTable[_idx].tRect.cs > _tCell.c )
			temp_label->tTable[_idx].tRect.cs = _tCell.c;
		if( temp_label->tTable[_idx].tRect.ce < _tCell.c )
			temp_label->tTable[_idx].tRect.ce = _tCell.c;
	}

	// add ptr of Node into Tail of Linked-List
//	if( _bAdd2List )
//	{
//		*temp_label->tTable[_idx].ptListTail = (uint32_t)GET_NEWNODE_FOR_LINKEDLIST(_tCell.r, _tCell.c);
//		temp_label->tTable[_idx].ptListTail = (uint32_t *)*temp_label->tTable[_idx].ptListTail;
//	}
}

void algorithm_label_GetConflictInfo(bool_t _bModify, uint8_t _Direction, uint8_t _search_idx, tCell_t _tPos, tConflictInfo_t * _ptConflict, int mode)
{
	int i, r_i, c_i;
	uint8_t neighbor_label_id;

	if( _search_idx == 0 )
	{
		_ptConflict->ulValue = 0x00000000;
	}
	else if( _search_idx > 0 )
	{
		_ptConflict->tInfo.NUM = 1;
	}

    if( _Direction == BOUNDARY_4_SEARCH_DIRECTION )
    {
    	for( i=0; i<BOUNDARY_4_SEARCH_TABLE[_search_idx].Num; i++ )
		{
#if (PAD_ == 0)
			if((_tPos.r == 0 && BOUNDARY_4_SEARCH_TABLE[_search_idx].Table[i].r == -1) || (_tPos.r == ROW_MAX-1 && BOUNDARY_4_SEARCH_TABLE[_search_idx].Table[i].r == 1))
				r_i = _tPos.r;
			else
				r_i = _tPos.r + BOUNDARY_4_SEARCH_TABLE[_search_idx].Table[i].r;

			if((_tPos.c == 0 && BOUNDARY_4_SEARCH_TABLE[_search_idx].Table[i].c == -1) || (_tPos.c == COL_MAX-1 && BOUNDARY_4_SEARCH_TABLE[_search_idx].Table[i].c == 1))
				c_i = _tPos.c;
			else
				c_i = _tPos.c + BOUNDARY_4_SEARCH_TABLE[_search_idx].Table[i].c;
#else 
			r_i = _tPos.r + BOUNDARY_4_SEARCH_TABLE[_search_idx].Table[i].r;
			c_i = _tPos.c + BOUNDARY_4_SEARCH_TABLE[_search_idx].Table[i].c;
#endif

			neighbor_label_id = HAL_READ_LABEL_IMAGE(r_i, c_i);

			//if( (neighbor_label_id != LABEL_CONFLICT_MARKER) && (neighbor_label_id != LABEL_BOUNDARY_MARKER) && neighbor_label_id != 0 )
			if( (neighbor_label_id > 0) && (neighbor_label_id <= LOOSE_POSBUF_) )
			{
				if( (_ptConflict->tInfo.BF & _BV(neighbor_label_id-1)) == 0 )
				{
					_ptConflict->tInfo.BF |= _BV(neighbor_label_id-1);
					_ptConflict->tInfo.NUM++;
				}
			}
		}
    }
    else if( _Direction == BOUNDARY_8_SEARCH_DIRECTION )
    {
		for( i=0; i<BOUNDARY_8_SEARCH_TABLE[_search_idx].Num; i++ )
		{
#if (PAD_ == 0)
			if((_tPos.r == 0 && BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].r == -1) || (_tPos.r == ROW_MAX-1 && BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].r == 1))
				r_i = _tPos.r;
			else
				r_i = _tPos.r + BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].r;

			if((_tPos.c == 0 && BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].c == -1) || (_tPos.c == COL_MAX-1 && BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].c == 1))
				c_i = _tPos.c;
			else
				c_i = _tPos.c + BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].c;
#else 
			r_i = _tPos.r + BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].r;
			c_i = _tPos.c + BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].c;
#endif

			neighbor_label_id = HAL_READ_LABEL_IMAGE(r_i, c_i);

			//if( (neighbor_label_id != LABEL_CONFLICT_MARKER) && (neighbor_label_id != LABEL_BOUNDARY_MARKER) && neighbor_label_id != 0 )
			if( (neighbor_label_id > 0) && (neighbor_label_id <= LOOSE_POSBUF_) )
			{
				if( (_ptConflict->tInfo.BF & _BV(neighbor_label_id-1)) == 0 )
				{
					_ptConflict->tInfo.BF |= _BV(neighbor_label_id-1);
					_ptConflict->tInfo.NUM++;
				}
			}
		}
    }

	if( _bModify == YES )
	{
		if( _ptConflict->tInfo.NUM == 0 )
		{


		}
		else if( _ptConflict->tInfo.NUM == 1 )
		{
			for( i=0; i<LOOSE_POSBUF_; i++ )
			{
				if( (_ptConflict->tInfo.BF & _BV(i)) )
				{
//					if(mode == LOCAL_FINGER_MODE)
//					{
//						algorithm_label_Add_NewNode_to_LabelRecord(i, _tPos, HAL_READ_LOCAL_FINGER_DELTA_IMAGE(_tPos.r, _tPos.c), NO, YES, mode);
//						HAL_WRITE_LABEL_IMAGE(_tPos.r, _tPos.c, thisInfo->tLabel.tTable[i].cId);
//					}
//					else
					{
						algorithm_label_Add_NewNode_to_LabelRecord(i, _tPos, HAL_READ_DELTA_IMAGE(_tPos.r, _tPos.c), NO, YES, mode);
						HAL_WRITE_LABEL_IMAGE(_tPos.r, _tPos.c, thisInfo->tLabel.tTable[i].cId);
					}
				}
			}
		}
		else if( _ptConflict->tInfo.NUM > 1 )
		{
			HAL_WRITE_LABEL_IMAGE(_tPos.r, _tPos.c, LABEL_CONFLICT_MARKER);
		}
	}
}

void algorithm_label_MarkBoundary(bool_t _bBoundary, int mode)
{
    int l, i;
    tCell_t tCellPos;
    tConflictInfo_t tConflict;
    uint8_t rLabel_val;

	tLabelInfo_t	*temp_label;

	temp_label = &thisInfo->tLabel;

    for( l=0; l<temp_label->ucValidNum; l++ )
    {
		if( temp_label->tValidRect[l].cs > 0 )
			temp_label->tValidRect[l].cs--;
		if( temp_label->tValidRect[l].ce < (COL_MAX - 1) )
			temp_label->tValidRect[l].ce++;
		if( temp_label->tValidRect[l].rs > 0 )
			temp_label->tValidRect[l].rs--;		
		
		{
			if( temp_label->tValidRect[l].re < (ROW_MAX - 1) )
				temp_label->tValidRect[l].re++;
		}

    	for( tCellPos.r=temp_label->tValidRect[l].rs; tCellPos.r<= temp_label->tValidRect[l].re; tCellPos.r++ )
    	{
    		for( tCellPos.c=temp_label->tValidRect[l].cs; tCellPos.c<= temp_label->tValidRect[l].ce; tCellPos.c++ )
    		{
				rLabel_val = HAL_READ_LABEL_IMAGE(tCellPos.r, tCellPos.c);

    			if( rLabel_val == 0 )
    			{
    				tConflict.ulValue = 0;

    				algorithm_label_GetConflictInfo(NO, BOUNDARY_4_SEARCH_DIRECTION, 0, tCellPos, &tConflict, mode);

    				if( tConflict.tInfo.NUM )
    				{
    					for(i=LOOSE_POSBUF_; i--; )
    					{
    						if( tConflict.tInfo.BF & _BV(i) )
    						{
								int sum_delta;
								
//    							if(mode == LOCAL_MODE || mode == LOCAL_HOVER_MODE)
//    							{
//    								algorithm_label_Add_NewNode_to_LabelRecord(i, tCellPos, HAL_READ_LOCAL_DELTA_IMAGE(tCellPos.r, tCellPos.c), YES, NO, mode);
//    							}
//    							else if(mode == LOCAL_FINGER_MODE)
//    							{
//    								algorithm_label_Add_NewNode_to_LabelRecord(i, tCellPos, HAL_READ_LOCAL_FINGER_DELTA_IMAGE(tCellPos.r, tCellPos.c), YES, NO, mode);
//    							}
//								else
//								{
//    								algorithm_label_Add_NewNode_to_LabelRecord(i, tCellPos, HAL_READ_DELTA_IMAGE(tCellPos.r, tCellPos.c), YES, NO, mode);
//    							}

//								if(mode == LOCAL_FINGER_MODE)
//    								sum_delta = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(tCellPos.r, tCellPos.c);
//								else
    								sum_delta = HAL_READ_DELTA_IMAGE(tCellPos.r, tCellPos.c);
								
								if(sum_delta < 0)	sum_delta = 0;
								
								algorithm_label_Add_NewNode_to_LabelRecord(i, tCellPos, sum_delta, _bBoundary, NO, mode);
    						}
    					}

    	    			HAL_WRITE_LABEL_IMAGE(tCellPos.r, tCellPos.c, LABEL_BOUNDARY_MARKER);
    				}
    			}
    		}
    	}
    }
}

bool_t algorithm_nearby_rect(tRect_t RectA, tRect_t RectB, uint8_t dist_th)
{
	if(RectA.rs <= RectB.re+dist_th && RectB.rs <= RectA.re+dist_th){
		if(RectA.cs <= RectB.ce+dist_th && RectB.cs <= RectA.ce+dist_th){
			return YES;
		}
	}
	return NO;
}

tRect_t algorithm_merge_rect(tRect_t RectA, tRect_t RectB)
{
	tRect_t RectC;
	
	RectC.cs = RectA.cs < RectB.cs ? RectA.cs : RectB.cs;
	RectC.ce = RectA.ce > RectB.ce ? RectA.ce : RectB.ce;
	RectC.rs = RectA.rs < RectB.rs ? RectA.rs : RectB.rs;
	RectC.re = RectA.re > RectB.re ? RectA.re : RectB.re;
	
	return RectC;
}
bool_t algorithm_nearby_rect_point(tRect_t RectA, tXY_t PointA, uint8_t dist_th)
{
	if(RectA.rs <= (PointA.y>>POS_BOOST_SHIFT_)+dist_th && RectA.re+dist_th >= (PointA.y>>POS_BOOST_SHIFT_)){
		if(RectA.cs <= (PointA.x>>POS_BOOST_SHIFT_)+dist_th && RectA.ce+dist_th >= (PointA.x>>POS_BOOST_SHIFT_)){
			return YES;
		}
	}
	return NO;
}
tRect_t algorithm_merge_rect_point(tRect_t RectA, tXY_t PointA)
{
	tRect_t RectB, RectC;
	
	RectB.cs = 0 < (PointA.x>>POS_BOOST_SHIFT_) ? (PointA.x>>POS_BOOST_SHIFT_)-1 : 0;
	RectB.ce = (COL_MAX - 1) > (PointA.x>>POS_BOOST_SHIFT_) ? (PointA.x>>POS_BOOST_SHIFT_)+1 : (COL_MAX - 1);
	RectB.rs = 0 < (PointA.y>>POS_BOOST_SHIFT_) ? (PointA.y>>POS_BOOST_SHIFT_)-1 : 0;
	RectB.re = (ROW_MAX - 1) > (PointA.y>>POS_BOOST_SHIFT_) ? (PointA.y>>POS_BOOST_SHIFT_)+1 : (ROW_MAX - 1);
	
	RectC.cs = RectA.cs < RectB.cs ? RectA.cs : RectB.cs;
	RectC.ce = RectA.ce > RectB.ce ? RectA.ce : RectB.ce;
	RectC.rs = RectA.rs < RectB.rs ? RectA.rs : RectB.rs;
	RectC.re = RectA.re > RectB.re ? RectA.re : RectB.re;
	
//	RectC.cs = RectA.cs < (PointA.x>>POS_BOOST_SHIFT_) ? RectA.cs : (PointA.x>>POS_BOOST_SHIFT_);
//	RectC.ce = RectA.ce > (PointA.x>>POS_BOOST_SHIFT_) ? RectA.ce : (PointA.x>>POS_BOOST_SHIFT_);
//	RectC.rs = RectA.rs < (PointA.y>>POS_BOOST_SHIFT_) ? RectA.rs : (PointA.y>>POS_BOOST_SHIFT_);
//	RectC.re = RectA.re > (PointA.y>>POS_BOOST_SHIFT_) ? RectA.re : (PointA.y>>POS_BOOST_SHIFT_);
	
	return RectC;
}
//#define KEEPPALMREGIONFRAME 50
void algorithm_label_palm_rejection(int mode)
{
	tLabelInfo_t	*temp_label;
	uint8_t IsPalm[LOOSE_POSBUF_] = {0,};		//0: Normal finger, 1: Big label(palm), 2: small label cascaded to big label 3: touch down label
	static int PalmRegionUpdateCnt = 0;
	tRect_t CascadeRect[LOOSE_POSBUF_];
	uint8_t PalmDetectingFlag = 0,PalmTouchDownFlag = 0, SavePalmRegion = 0, PalmCnt = 0;
	int cl,pl,pl2,r,c;
#if (PENnPalm_PalmAreaMaintain_EN == YES)
	bool_t bPalmRegionInit = 1;
	bool_t bPenPalmParam = 0;
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */
//	int tmp = 0;
	
	temp_label = &thisInfo->tLabel;
//	tmp = temp_label->ucValidNum;
#if (PENnPalm_PalmAreaMaintain_EN == YES)
	if(thisModeConf->Palm.bPenPalmDetection)
	{
		if(thisInfo->bLocal_sensing)
			PenEnable = thisModeConf->Palm.ucPen_KEEPFRAME;
		else if(PenEnable) PenEnable--;
		
		if(PenEnable)
			bPenPalmParam = 1;
	}
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */

	thisInfo->bIsPalm = NO;
	//Initialize and counting touch down frame
#if (PENnPalm_PalmAreaMaintain_EN == YES)
	if(temp_label->ucValidNum == 0)
	{
		if(temp_label->TouchFrameCnt && !thisInfo->bWasPalm_AtLeastOnce)
		{
			PalmRegionNum = 0;
			memset(PalmRectEnable,0,sizeof(PalmRectEnable));
		}
		temp_label->PalmTouchDownCnt = 0;
		PalmRegionUpdateCnt = 0;
		temp_label->TouchFrameCnt = 0;
		thisInfo->bWasPalm_AtLeastOnce = 0;
		
		if(bPenPalmParam)
		{
			for(pl=PalmRegionNum; pl--; )
			{
				if(PalmRectEnable[pl])
				{
					bPalmRegionInit = 0;
					break;
				}
			}
		}
		if(bPalmRegionInit)
		{
			PalmRegionNum = 0;
			memset(PalmRectEnable,0,sizeof(PalmRectEnable));
		}
	}
	else if(temp_label->PalmTouchDownCnt < thisModeConf->Palm.ucPalm_TOUCHDOWNFRAMEMAX){
		temp_label->PalmTouchDownCnt++;
		if(temp_label->PalmTouchDownCnt <= thisModeConf->Palm.ucPalm_IGNOREFRAMENUM)	PalmTouchDownFlag = YES;
	}
	
	// In Pen & Palm conditions, if your finger enters a non-Palm area when there is no Palm, the Palm area is released
	if(bPenPalmParam && !thisInfo->bWasPalm_AtLeastOnce)
	{
		for(pl = 0; pl < MAX_TOUCH_; pl++)
		{
			if(thisInfo->tCoord.tPastPos[0].vusS[pl])
			{
				PalmRegionNum = 0;
				memset(PalmRectEnable,0,sizeof(PalmRectEnable));
				break;
			}
		}
	}
	
	// In Pen & Palm conditions, when there is no Palm, if more than ucPalmRelaseFrame is drawn, the Palm area is released
	if(bPenPalmParam && !thisInfo->bWasPalm_AtLeastOnce && temp_label->ucValidNum > 0)
	{
		if(temp_label->TouchFrameCnt < thisModeConf->Palm.ucPalmRelaseFrame) temp_label->TouchFrameCnt++;
		else
		{
			PalmRegionNum = 0;
			memset(PalmRectEnable,0,sizeof(PalmRectEnable));
		}
	}
#else /* (PENnPalm_PalmAreaMaintain_EN == YES) */
	if(temp_label->ucValidNum == 0)
	{
		PalmRegionNum = 0;
		memset(PalmRectEnable,0,sizeof(PalmRectEnable));
		temp_label->PalmTouchDownCnt = 0;
		PalmRegionUpdateCnt = 0;
	}
	else if(temp_label->PalmTouchDownCnt < thisModeConf->Palm.ucPalm_TOUCHDOWNFRAMEMAX){
		temp_label->PalmTouchDownCnt++;
		if(temp_label->PalmTouchDownCnt <= thisModeConf->Palm.ucPalm_IGNOREFRAMENUM)	PalmTouchDownFlag = YES;
	}
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */
	
	//Detect touch down
	//compare peak value and nearby value when only 1 label
	//if touch down palm, slope is lower than normal finger.
	//Do not save palm region for touch down label.
	if(temp_label->ucValidNum == 1 && temp_label->PalmTouchDownCnt < thisModeConf->Palm.ucPalm_TOUCHDOWNFRAMEMAX)
	{
		if(!thisInfo->tCoord.tPastPos[0].vusS[0])
		{
			int neighbor_mean = 0;
			tCell_t MaxPos;
			uint16_t SlopeTh = 0;
			
			SlopeTh = thisModeConf->Palm.ucPalm_TOUCHDOWNSLOPETHRESHOLD;
			MaxPos.r = temp_label->tValidMaxPos[0].r;
			MaxPos.c = temp_label->tValidMaxPos[0].c;
			if(0 < MaxPos.r && MaxPos.r < ROW_MAX-1 && 0 < MaxPos.c && MaxPos.c < COL_MAX-1)
			{
				for(r=MaxPos.r-1 ; r<=MaxPos.r+1 ; r++){
					for(c=MaxPos.c-1 ; c<=MaxPos.c+1 ; c++){
						if( !(r==MaxPos.r && c==MaxPos.c) )
							neighbor_mean += HAL_READ_DELTA_IMAGE(r,c);
					}
				}
				neighbor_mean >>= 3;
				if(temp_label->sValidMaxVal[0]*100/neighbor_mean < SlopeTh)	PalmTouchDownFlag = YES;
			}
		}
		else
			temp_label->PalmTouchDownCnt = thisModeConf->Palm.ucPalm_TOUCHDOWNFRAMEMAX;
	}
	
	for( cl=temp_label->ucValidNum; cl--; )
	{
		uint8_t merged_flag = 0;
		SavePalmRegion = NO;
	
		if(thisModeConf->Palm.usPalmLevel < temp_label->usValidCellCnt[cl] ){	//&& temp_label->usValidCellCnt[cl] < (thisModeConf->Palm.usPalmLevel<<6)){	//Certain Big palm
			IsPalm[cl] = 1;
			SavePalmRegion = YES;
		}	//if first frame, palm threshold is in half. It is decided by experimental.
#if (PalmFirstDetectionShift == YES)
		else if((temp_label->PalmTouchDownCnt==1 && temp_label->usValidCellCnt[cl] > (thisModeConf->Palm.usPalmLevel>>thisModeConf->Palm.ucPalmLevelShift)) || PalmTouchDownFlag)	//Touch down label
#else
		else if((temp_label->PalmTouchDownCnt==1 && temp_label->usValidCellCnt[cl] > (thisModeConf->Palm.usPalmLevel>>1)) || PalmTouchDownFlag)	//Touch down label
#endif
			IsPalm[cl] = 3;
		
		if(IsPalm[cl])
		{
			//Merge previous palm region and new palm
			for(pl=PalmRegionNum; pl--; )
			{
				if(PalmRectEnable[pl]){
#if (PENnPalm_PalmAreaMaintain_EN == YES)
					if((!bPenPalmParam && algorithm_nearby_rect(temp_label->tValidRect[cl], PalmRect[pl],thisModeConf->Palm.ucPalm_PALM_CONNECT_DIST)) ||
						(bPenPalmParam && algorithm_nearby_rect(temp_label->tValidRect[cl], PalmRect[pl],thisModeConf->Palm.ucPenPalm_PALM_CONNECT_DIST))){
#else /* (PENnPalm_PalmAreaMaintain_EN == YES) */
					if(algorithm_nearby_rect(temp_label->tValidRect[cl], PalmRect[pl],thisModeConf->Palm.ucPalm_PALM_CONNECT_DIST)){
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */
						PalmRect[pl] = algorithm_merge_rect(temp_label->tValidRect[cl], PalmRect[pl]);
						merged_flag = YES;
						break;
					}
				}
			}
			//Save new palm region
			if(!merged_flag && SavePalmRegion){
				PalmRect[PalmRegionNum] = temp_label->tValidRect[cl];
#if (PENnPalm_PalmAreaMaintain_EN == YES)
				if(!bPenPalmParam)
					PalmRectEnable[PalmRegionNum] = thisModeConf->Palm.ucPalm_KEEPPALMREGIONFRAME;
				else
					PalmRectEnable[PalmRegionNum] = thisModeConf->Palm.ucPenPalm_KEEPPALMREGIONFRAME;
#else /* (PENnPalm_PalmAreaMaintain_EN == YES) */
				PalmRectEnable[PalmRegionNum] = thisModeConf->Palm.ucPalm_KEEPPALMREGIONFRAME;
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */
				if(PalmRegionNum < LOOSE_POSBUF_)
					PalmRegionNum++;
			}
			
			thisInfo->bIsPalm = YES;
		}
		else{
			PalmDetectingFlag = YES;
		}
	}
	
	if(PalmDetectingFlag)
	{
		int16_t MinDist = 0, Xdist = 0, Ydist = 0;
		int8_t match_pl = 0;
		//Expand Palm region method2
		for(cl=temp_label->ucValidNum; cl--; )
		{
			if((IsPalm[cl] & 0x80) == 0)
			{
#if (PENnPalm_PalmAreaMaintain_EN == YES)
				if(!bPenPalmParam)
					MinDist = thisModeConf->Palm.ucPalm_PALM_CONNECT_DIST;
				else
					MinDist = thisModeConf->Palm.ucPenPalm_PALM_CONNECT_DIST;
#else /* (PENnPalm_PalmAreaMaintain_EN == YES) */
				MinDist = thisModeConf->Palm.ucPalm_PALM_CONNECT_DIST;
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */
				match_pl = -1;
				for(pl=PalmRegionNum; pl--; )
				{
					if(PalmRectEnable[pl])
					{
#if (PENnPalm_PalmAreaMaintain_EN == YES)
						if((!bPenPalmParam && algorithm_nearby_rect(temp_label->tValidRect[cl], PalmRect[pl], thisModeConf->Palm.ucPalm_PALM_CONNECT_DIST)) ||
							(bPenPalmParam && algorithm_nearby_rect(temp_label->tValidRect[cl], PalmRect[pl], thisModeConf->Palm.ucPenPalm_PALM_CONNECT_DIST))){
#else /* (PENnPalm_PalmAreaMaintain_EN == YES) */
						if(algorithm_nearby_rect(temp_label->tValidRect[cl], PalmRect[pl], thisModeConf->Palm.ucPalm_PALM_CONNECT_DIST)){
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */
							Xdist = abs(temp_label->tValidMaxPos[cl].c - ((PalmRect[pl].cs+PalmRect[pl].ce)>>1)) - ((PalmRect[pl].ce-PalmRect[pl].cs)>>1);
							if(Xdist < 0) Xdist = 0;
							Ydist = abs(temp_label->tValidMaxPos[cl].r - ((PalmRect[pl].rs+PalmRect[pl].re)>>1)) - ((PalmRect[pl].re-PalmRect[pl].rs)>>1);
							if(Ydist < 0) Ydist = 0;
							if(Xdist+Ydist < MinDist){
								MinDist = Xdist+Ydist;
								match_pl = pl;
							}
						}
						
					}
				}
				if(match_pl != -1)
				{
					PalmRect[match_pl] = algorithm_merge_rect(temp_label->tValidRect[cl], PalmRect[match_pl]);
					if(IsPalm[cl] == 0){
						IsPalm[cl] = 2;
					}
					IsPalm[cl] |= 0x80;
				}
			}
		}
		
		//Expand Palm region
//		for(pl=PalmRegionNum; pl--; )
//		{
//			if(PalmRectEnable[pl])
//			{
//				uint8_t expand_flag = YES;
//				while(expand_flag){
//					expand_flag = NO;
//					for( cl=temp_label->ucValidNum; cl--; )
//					{
//						if((IsPalm[cl] & 0x80) == 0)
//						{
//							if(algorithm_nearby_rect(temp_label->tValidRect[cl], PalmRect[pl], thisModeConf->Palm.ucPalm_PALM_CONNECT_DIST)){
//								PalmRect[pl] = algorithm_merge_rect(temp_label->tValidRect[cl], PalmRect[pl]);
//								expand_flag = YES;
//								if(IsPalm[cl] == 0){
//									IsPalm[cl] = 2;
//								}
//								IsPalm[cl] |= 0x80;
//							}
//						}
//					}
//				}
//			}
//		}
	}
	
	//Release or downsize palm region
	for(pl=PalmRegionNum; pl--; )
	{
		if(PalmRectEnable[pl])
		{
			uint8_t TouchedFlag = 0, ParentLabelIdx = 0;
			uint16_t MaxCellCnt = 0;
			for( cl=temp_label->ucValidNum; cl--; )
			{
#if (PENnPalm_PalmAreaMaintain_EN == YES)
				if((!bPenPalmParam && algorithm_nearby_rect(temp_label->tValidRect[cl], PalmRect[pl], thisModeConf->Palm.ucPalm_PALM_CONNECT_DIST)) ||
					(bPenPalmParam && algorithm_nearby_rect(temp_label->tValidRect[cl], PalmRect[pl], thisModeConf->Palm.ucPenPalm_PALM_CONNECT_DIST))){		//Overlap
#else /* (PENnPalm_PalmAreaMaintain_EN == YES) */
				if(algorithm_nearby_rect(temp_label->tValidRect[cl], PalmRect[pl], thisModeConf->Palm.ucPalm_PALM_CONNECT_DIST)){		//Overlap
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */			
					if( (IsPalm[cl] & 0x0F) > 0 )
						TouchedFlag = 1;
					else if(TouchedFlag == 0)	//For debugging
						TouchedFlag = 2;
					
					if(MaxCellCnt < temp_label->usValidCellCnt[cl]){
						MaxCellCnt = temp_label->usValidCellCnt[cl];
						ParentLabelIdx = cl;
					}
				}
			}
			
			//if no touch label in palm region during KEEPPALMREGIONFRAME, release palm region.
			if(TouchedFlag == 0){
				if(PalmRectEnable[pl])						PalmRectEnable[pl]--;
//				if(PalmRectEnable[pl]==0 && PalmRegionNum>0)	PalmRegionNum--;		//Release palm region
			}
			else{
				uint8_t CascadeFlag = YES;	//Cascade label based on parent label
				uint8_t CheckCascade[LOOSE_POSBUF_] = {0};
#if (PENnPalm_PalmAreaMaintain_EN == YES)
				if(bPenPalmParam)
					PalmRectEnable[pl] = thisModeConf->Palm.ucPenPalm_KEEPPALMREGIONFRAME;
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */				
				
				if(PalmRegionUpdateCnt++ > thisModeConf->Palm.ucPalm_PALM_REGION_UPDATE_PERIOD)
				{
					PalmRegionUpdateCnt = 0;
					CascadeRect[pl] = temp_label->tValidRect[ParentLabelIdx];	//Initial cascade label
					while(CascadeFlag){
						CascadeFlag = NO;
						for( cl=temp_label->ucValidNum; cl--; )
						{
							if(CheckCascade[cl] == NO){
#if (PENnPalm_PalmAreaMaintain_EN == YES)
								if((!bPenPalmParam && algorithm_nearby_rect(temp_label->tValidRect[cl], CascadeRect[pl], thisModeConf->Palm.ucPalm_PALM_CONNECT_DIST)) ||
									(bPenPalmParam && algorithm_nearby_rect(temp_label->tValidRect[cl], CascadeRect[pl], thisModeConf->Palm.ucPenPalm_PALM_CONNECT_DIST))){
#else /* (PENnPalm_PalmAreaMaintain_EN == YES) */
								if(algorithm_nearby_rect(temp_label->tValidRect[cl], CascadeRect[pl], thisModeConf->Palm.ucPalm_PALM_CONNECT_DIST)){
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */							
									CascadeRect[pl] = algorithm_merge_rect(temp_label->tValidRect[cl], CascadeRect[pl]);	//Update cascade rect
									CascadeFlag = YES;
									CheckCascade[cl] = YES;
								}
							}
						}
					}
					//downsize palm region
//					PalmRect[pl] = CascadeRect[pl];
//					PalmRect[pl].cs = ((CascadeRect[pl].cs + PalmRect[pl].cs)>>1);
//					PalmRect[pl].ce = ((CascadeRect[pl].ce + PalmRect[pl].ce)>>1);
//					PalmRect[pl].rs = ((CascadeRect[pl].rs + PalmRect[pl].rs)>>1);
//					PalmRect[pl].re = ((CascadeRect[pl].re + PalmRect[pl].re)>>1);
					
					PalmRect[pl] = CascadeRect[pl];
				}
			}
		}
	}
	
	//Merge overlapped palm region
	for(pl=0; pl<PalmRegionNum; pl++)
	{
		if(PalmRectEnable[pl])
		{
			for(pl2 = pl+1; pl2 < PalmRegionNum; pl2++)
			{
				if(PalmRectEnable[pl2])
				{
					if(algorithm_nearby_rect(PalmRect[pl], PalmRect[pl2], 0)){
						PalmRect[pl] = algorithm_merge_rect(PalmRect[pl], PalmRect[pl2]);
						PalmRectEnable[pl2] = NO;
						
					}
				}
			}
		}
	}
	
	//Rearrange PalmRect
	PalmCnt = 0;
	for(pl=0; pl<PalmRegionNum; pl++)
	{
		if(PalmRectEnable[pl])
		{
			PalmRect[PalmCnt] = PalmRect[pl];
			PalmRectEnable[PalmCnt] = PalmRectEnable[pl];
			PalmCnt++;
		}
	}
	PalmRegionNum = PalmCnt;
			
	//Remove Palm label
	{
		int normal_label_num = 0;
		for(cl = 0;cl < temp_label->ucValidNum;cl++)
		{
			if((IsPalm[cl] & 0x0F) == 0){
				temp_label->tValidRect[normal_label_num] = temp_label->tValidRect[cl];
				temp_label->sValidMaxVal[normal_label_num] = temp_label->sValidMaxVal[cl];
				temp_label->tValidMaxPos[normal_label_num] = temp_label->tValidMaxPos[cl];
				temp_label->usValidCellCnt[normal_label_num] = temp_label->usValidCellCnt[cl];
				normal_label_num++;
			}
			else
				thisInfo->bIsPalm = YES;
		}
		temp_label->ucValidNum = normal_label_num;
	}
#if (PENnPalm_PalmAreaMaintain_EN == YES)
	for(cl = 0; cl < LOOSE_POSBUF_; cl++)
	{
		if((IsPalm[cl] & 0x0F) == 1)
			thisInfo->bWasPalm_AtLeastOnce = 1;
	}
#endif /* (PENnPalm_PalmAreaMaintain_EN == YES) */	
}

#if LABEL_FAST_EN
uint8_t g_ucEqTbl[LOOSE_POSBUF_];
uint8_t g_label_num;
void algorithm_label_SearchValidArea_Fast(tRect_t _tRect, int16_t _deltaThd, int mode)
{
	int32_t r, c, i, j,k,l,idx_r,idx_c;
	uint8_t u_val, l_val, ul_val, ur_val;
	uint8_t max_val1, max_val2, max_val3, min_val1, min_val2, min_val3;
	int16_t delta;
	uint8_t label_new, label_max;
	uint8_t	map_val, eq_val, map_data;
	uint8_t remap_index;
//	uint8_t ucEqTbl[LOOSE_POSBUF_];
	tLabelInfo_t	*temp_label;

	temp_label = &thisInfo->tLabel;

	int USE_COL_IN_ARRAY = COL_IN_ARRAY;
#if (LABEL_FAST_EN != 2)
	g_label_num = 0;
	memset((void *)g_ucEqTbl, 0x00, sizeof(uint8_t)*LOOSE_POSBUF_);
	// Stage1
	for (k = 0; k < ROW_MAX; k+=ROW_IN_ARRAY)
	{
		for (l = 0; l < COL_MAX; l+=USE_COL_IN_ARRAY)
		{
			USE_COL_IN_ARRAY = COL_IN_ARRAY;
			idx_r = k/ROW_IN_ARRAY;
			idx_c = l/COL_IN_ARRAY;
			if(thisInfo->tLabel.ucLabel_Check[idx_r][idx_c])
			{
				USE_COL_IN_ARRAY += COL_IN_ARRAY;
				for(c = idx_c + 1; c < ARRAY_COL; c++)
				{
					if(thisInfo->tLabel.ucLabel_Check[idx_r][c] == 1)
						USE_COL_IN_ARRAY += COL_IN_ARRAY;
					else
						break;
				}
				
				for (r = k; r < k+ROW_IN_ARRAY; r++)
				{
					for (c = l; c < l+(USE_COL_IN_ARRAY - COL_IN_ARRAY); c++)
					{
						if(_tRect.rs<=r&&r<=_tRect.re&&_tRect.cs<=c&&c<=_tRect.ce)
						{							
//							if(mode == LOCAL_FINGER_MODE)
//								delta = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(r,c);
//							else
								delta = HAL_READ_DELTA_IMAGE(r,c);

							if ( delta >= _deltaThd)
							{
	#if (PAD_ == 0)
								if(r == 0)
								{
									u_val  = 0;
									ul_val = 0;
									ur_val = 0;
								}
								else
								{
									u_val  = HAL_READ_LABEL_IMAGE(r-1, c  );
									if(c == 0)
										ul_val = 0;
									else 
										ul_val = HAL_READ_LABEL_IMAGE(r-1, c-1);
									
									if(c == COL_MAX-1)
										ur_val = 0;
									else 
										ur_val = HAL_READ_LABEL_IMAGE(r-1, c+1);
								}
								
								if(c == 0)
									l_val  = 0;
								else
									l_val  = HAL_READ_LABEL_IMAGE(r  , c-1);
	#else
								u_val  = HAL_READ_LABEL_IMAGE(r-1, c  );
								ul_val = HAL_READ_LABEL_IMAGE(r-1, c-1);
								ur_val = HAL_READ_LABEL_IMAGE(r-1, c+1);
								l_val  = HAL_READ_LABEL_IMAGE(r  , c-1);
	#endif
								max_val1 = MAX(ul_val, l_val);
								max_val2 = MAX(u_val, ur_val);
								max_val3 = MAX(max_val1, max_val2);

								if (max_val3 != 0)
								{
									if (u_val == 0)  u_val  = 127;
									if (l_val == 0)  l_val  = 127;
									if (ul_val == 0) ul_val = 127;
									if (ur_val == 0) ur_val = 127;

									min_val1 = MIN(u_val, l_val);
									min_val2 = MIN(ul_val, ur_val);
									min_val3 = MIN(min_val1, min_val2);

									if (min_val3 != max_val3)
									{
										map_val = min_val3;
										//*(thisInfo->ucEqTbl+max_val3) = min_val3;

										if(u_val != 127)
										{
											remap_index = u_val;
											while(remap_index != g_ucEqTbl[remap_index])
											{
												remap_index = g_ucEqTbl[remap_index];
												if(min_val3 < remap_index)
													g_ucEqTbl[remap_index] = min_val3;
											}

											if( g_ucEqTbl[u_val] > min_val3 )
												g_ucEqTbl[u_val] = min_val3;
										}
										if(l_val != 127)
										{
											remap_index = l_val;
											while(remap_index != g_ucEqTbl[remap_index])
											{
												remap_index = g_ucEqTbl[remap_index];
												if(min_val3 < remap_index)
													g_ucEqTbl[remap_index] = min_val3;
											}

											if( g_ucEqTbl[l_val] > min_val3 )
												g_ucEqTbl[l_val] = min_val3;
										}
										if(ul_val != 127)
										{
											remap_index = ul_val;
											while(remap_index != g_ucEqTbl[remap_index])
											{
												remap_index = g_ucEqTbl[remap_index];
												if(min_val3 < remap_index)
													g_ucEqTbl[remap_index] = min_val3;
											}

											if( g_ucEqTbl[ul_val] > min_val3 )
												g_ucEqTbl[ul_val] = min_val3;
										}
										if(ur_val != 127)
										{
											remap_index = ur_val;
											while(remap_index != g_ucEqTbl[remap_index])
											{
												remap_index = g_ucEqTbl[remap_index];
												if(min_val3 < remap_index)
													g_ucEqTbl[remap_index] = min_val3;
											}

											if( g_ucEqTbl[ur_val] > min_val3 )
												g_ucEqTbl[ur_val] = min_val3;
										}
									}
									else
									{
										map_val = max_val3;
									}
								}
								else
								{
									if( g_label_num < LOOSE_POSBUF_ )
									{
										g_label_num++;
									}

									map_val = g_label_num;
									g_ucEqTbl[g_label_num] = g_label_num;
								}
							}
							else
							{
								map_val = 0;
							}
							HAL_WRITE_LABEL_IMAGE(r, c, map_val);
						}
					}
				}
			}
		}
	}
#endif
	g_label_num = MIN( g_label_num, LOOSE_POSBUF_ );

	if( g_label_num > 0 )
	{
		// Stage2
		for (i=g_label_num; i>0; i--)
		{
			eq_val = g_ucEqTbl[i];
			if (eq_val != i)
			{
				do
				{
					j = eq_val;
					eq_val = g_ucEqTbl[j];
				} while (j != eq_val);
				g_ucEqTbl[i] = eq_val;
			}
		}

		// Stage3
		label_max = 1;
		label_new = 1;
		for (i=1; i<=g_label_num; i++)
		{
			eq_val = g_ucEqTbl[i];
			if (eq_val < label_max)
			{
				g_ucEqTbl[i] = g_ucEqTbl[eq_val];
			}
			else if (eq_val > label_max)
			{
				label_new++;
				label_max = eq_val;
				g_ucEqTbl[i] = label_new;
			}
			else
			{
				g_ucEqTbl[i] = label_new;
			}
		}

		// Stage4
		for (k = 0; k < ROW_MAX; k+=ROW_IN_ARRAY)
		{
			for (l = 0; l < COL_MAX; l+=USE_COL_IN_ARRAY)
			{
				USE_COL_IN_ARRAY = COL_IN_ARRAY;
				idx_r = k/ROW_IN_ARRAY;
				idx_c = l/COL_IN_ARRAY;
				if(thisInfo->tLabel.ucLabel_Check[idx_r][idx_c])
				{
					USE_COL_IN_ARRAY += COL_IN_ARRAY;
					for(c = idx_c + 1; c < ARRAY_COL; c++)
					{
						if(thisInfo->tLabel.ucLabel_Check[idx_r][c] == 1)
							USE_COL_IN_ARRAY += COL_IN_ARRAY;
						else
							break;
					}
					
					for (r = k; r < k+ROW_IN_ARRAY; r++)
					{
						for (c = l; c < l+(USE_COL_IN_ARRAY - COL_IN_ARRAY); c++)
						{
							if(_tRect.rs<=r&&r<=_tRect.re&&_tRect.cs<=c&&c<=_tRect.ce)
							{			
								map_val  = HAL_READ_LABEL_IMAGE(r,c);
								delta = HAL_READ_DELTA_IMAGE(r, c);
								if( map_val > 0 && delta > _deltaThd )
								{
									eq_val   = g_ucEqTbl[map_val];

									if (/*map_val != 0 &&*/ eq_val <= LOOSE_POSBUF_)
									{
										map_data = eq_val;
									}
									else
									{
										map_data = 0;
									}

//									HAL_WRITE_LABEL_IMAGE(r, c, 0);

									if( map_data > 0 )
									{
//										if(mode == LOCAL_FINGER_MODE)
//											delta = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(r,c);
//										else
//											delta = HAL_READ_DELTA_IMAGE(r, c);

										if( temp_label->tValidRect[map_data-1].cs > c )
											temp_label->tValidRect[map_data-1].cs = c;
										if( temp_label->tValidRect[map_data-1].ce < c )
											temp_label->tValidRect[map_data-1].ce = c;
										if( temp_label->tValidRect[map_data-1].rs > r )
											temp_label->tValidRect[map_data-1].rs = r;
										if( temp_label->tValidRect[map_data-1].re < r )
											temp_label->tValidRect[map_data-1].re = r;

										if( temp_label->sValidMaxVal[map_data-1] < delta )
										{
											temp_label->sValidMaxVal[map_data-1] = delta;

											temp_label->tValidMaxPos[map_data-1].r = r;
											temp_label->tValidMaxPos[map_data-1].c = c;
										}


										temp_label->usValidCellCnt[map_data-1]++;
									}
								}
							}
						}
					}
				}
			}
		}
		
		temp_label->ucValidNum = MIN(label_new, LOOSE_POSBUF_);
		memset(LABELIMAGE,0,sizeof(LABELIMAGE));
	}
}
#else
void algorithm_label_SearchValidArea(tRect_t _tRect, int16_t _deltaThd, int mode)
{
	int32_t r, c, i, j;
	uint8_t u_val, l_val, ul_val, ur_val;
	uint8_t max_val1, max_val2, max_val3, min_val1, min_val2, min_val3;
	uint8_t label_num;
	int16_t delta;
	uint8_t label_new, label_max;
	uint8_t	map_val, eq_val, map_data;
	uint8_t remap_index;
	uint8_t ucEqTbl[(LOOSE_POSBUF_ + LABEL_MARGIN)];

	tLabelInfo_t	*temp_label;

	temp_label = &thisInfo->tLabel;

	label_num = 0;
	memset((void *)ucEqTbl, 0x00, sizeof(uint8_t)*(LOOSE_POSBUF_ + LABEL_MARGIN));

	// Stage1
	for (r = _tRect.rs; r <= _tRect.re; r++)
	{
		for (c = _tRect.cs; c <= _tRect.ce; c++)
		{
//			if(mode == LOCAL_FINGER_MODE)
//				delta = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(r,c);
//			else
				delta = HAL_READ_DELTA_IMAGE(r,c);

			if ( delta >= _deltaThd)
			{
#if (PAD_ == 0)
				if(r == 0)
				{
					u_val  = 0;
					ul_val = 0;
					ur_val = 0;
				}
				else
				{
					u_val  = HAL_READ_LABEL_IMAGE(r-1, c  );
					if(c == 0)
						ul_val = 0;
					else 
						ul_val = HAL_READ_LABEL_IMAGE(r-1, c-1);
					
					if(c == COL_MAX-1)
						ur_val = 0;
					else 
						ur_val = HAL_READ_LABEL_IMAGE(r-1, c+1);
				}
				
				if(c == 0)
					l_val  = 0;
				else
					l_val  = HAL_READ_LABEL_IMAGE(r  , c-1);
#else
				u_val  = HAL_READ_LABEL_IMAGE(r-1, c  );
				ul_val = HAL_READ_LABEL_IMAGE(r-1, c-1);
				ur_val = HAL_READ_LABEL_IMAGE(r-1, c+1);
				l_val  = HAL_READ_LABEL_IMAGE(r  , c-1);				
#endif
				max_val1 = MAX(ul_val, l_val);
				max_val2 = MAX(u_val, ur_val);
				max_val3 = MAX(max_val1, max_val2);

				if (max_val3 != 0)
				{
					if (u_val == 0)  u_val  = 127;
					if (l_val == 0)  l_val  = 127;
					if (ul_val == 0) ul_val = 127;
					if (ur_val == 0) ur_val = 127;

					min_val1 = MIN(u_val, l_val);
					min_val2 = MIN(ul_val, ur_val);
					min_val3 = MIN(min_val1, min_val2);

					if (min_val3 != max_val3)
					{
						map_val = min_val3;
						//*(thisInfo->ucEqTbl+max_val3) = min_val3;

						if(u_val != 127)
						{
							remap_index = u_val;
							while(remap_index != ucEqTbl[remap_index])
							{
								remap_index = ucEqTbl[remap_index];
								if(min_val3 < remap_index)
									ucEqTbl[remap_index] = min_val3;
							}

							if( ucEqTbl[u_val] > min_val3 )
								ucEqTbl[u_val] = min_val3;
						}
						if(l_val != 127)
						{
							remap_index = l_val;
							while(remap_index != ucEqTbl[remap_index])
							{
								remap_index = ucEqTbl[remap_index];
								if(min_val3 < remap_index)
									ucEqTbl[remap_index] = min_val3;
							}

							if( ucEqTbl[l_val] > min_val3 )
							    ucEqTbl[l_val] = min_val3;
						}
						if(ul_val != 127)
						{
							remap_index = ul_val;
							while(remap_index != ucEqTbl[remap_index])
							{
								remap_index = ucEqTbl[remap_index];
								if(min_val3 < remap_index)
									ucEqTbl[remap_index] = min_val3;
							}

							if( ucEqTbl[ul_val] > min_val3 )
								ucEqTbl[ul_val] = min_val3;
						}
						if(ur_val != 127)
						{
							remap_index = ur_val;
							while(remap_index != ucEqTbl[remap_index])
							{
								remap_index = ucEqTbl[remap_index];
								if(min_val3 < remap_index)
									ucEqTbl[remap_index] = min_val3;
							}

							if( ucEqTbl[ur_val] > min_val3 )
								ucEqTbl[ur_val] = min_val3;
						}
					}
					else
					{
						map_val = max_val3;
					}
				}
				else
				{
					if( label_num < (LOOSE_POSBUF_ + LABEL_MARGIN) )
					{
						label_num++;
					}

					map_val = label_num;
					ucEqTbl[label_num] = label_num;
				}
			}
			else
			{
				map_val = 0;
			}
			HAL_WRITE_LABEL_IMAGE(r, c, map_val);
		}
	}

	label_num = MIN( label_num, (LOOSE_POSBUF_ + LABEL_MARGIN) );

	if( label_num > 0 )
	{
		// Stage2
		for (i=label_num; i>0; i--)
		{
			eq_val = ucEqTbl[i];
			if (eq_val != i)
			{
				do
				{
					j = eq_val;
					eq_val = ucEqTbl[j];
				} while (j != eq_val);
				ucEqTbl[i] = eq_val;
			}
		}

		// Stage3
		label_max = 1;
		label_new = 1;
		for (i=1; i<=label_num; i++)
		{
			eq_val = ucEqTbl[i];
			if (eq_val < label_max)
			{
				ucEqTbl[i] = ucEqTbl[eq_val];
			}
			else if (eq_val > label_max)
			{
				label_new++;
				label_max = eq_val;
				ucEqTbl[i] = label_new;
			}
			else
			{
				ucEqTbl[i] = label_new;
			}
		}

		// Stage4
		for (r = _tRect.rs; r <= _tRect.re; r++)
		{
			for (c = _tRect.cs; c <= _tRect.ce; c++)
			{
				map_val  = HAL_READ_LABEL_IMAGE(r,c);

				if( map_val > 0 )
				{

					eq_val   = ucEqTbl[map_val];

					if (map_val != 0 && eq_val <= (LOOSE_POSBUF_ + LABEL_MARGIN))
					{
						if(eq_val <= LOOSE_POSBUF_)
							map_data = eq_val;
						else
							map_data = LOOSE_POSBUF_;
					}
					else
					{
						map_data = 0;
					}

					HAL_WRITE_LABEL_IMAGE(r, c, 0);

					if( map_data > 0 )
					{
//						if(mode == LOCAL_FINGER_MODE)
//							delta = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(r,c);
//						else
							delta = HAL_READ_DELTA_IMAGE(r, c);

						if( temp_label->tValidRect[map_data-1].cs > c )
							temp_label->tValidRect[map_data-1].cs = c;
						if( temp_label->tValidRect[map_data-1].ce < c )
							temp_label->tValidRect[map_data-1].ce = c;
						if( temp_label->tValidRect[map_data-1].rs > r )
							temp_label->tValidRect[map_data-1].rs = r;
						if( temp_label->tValidRect[map_data-1].re < r )
							temp_label->tValidRect[map_data-1].re = r;

						if( temp_label->sValidMaxVal[map_data-1] < delta )
						{
							temp_label->sValidMaxVal[map_data-1] = delta;

							temp_label->tValidMaxPos[map_data-1].r = r;
							temp_label->tValidMaxPos[map_data-1].c = c;
						}


						temp_label->usValidCellCnt[map_data-1]++;
					}
				}
			}
		}

		temp_label->ucValidNum = MIN(label_new, LOOSE_POSBUF_);
	}
	else{
		temp_label->LabelSplitCnt = 0;
		temp_label->LabelSplitFrmCnt = 0;
		temp_label->LabelSplitMergeCnt = 0;
	}
}
#endif

#if defined(FAST_SPLIT)
	#define MAX_SPLIT_NUM	200//64
	uint8_t split_buf[MAX_SPLIT_NUM];
	tCell_t split_pos[MAX_SPLIT_NUM];
#endif

void algorithm_label_Split(uint8_t _valid_area_idx, uint8_t _label_start_idx, int16_t _LowerThd, int mode)
{
    int16_t threshold = INT16_MAX; // for labeling
    uint8_t label_num;
    tConflictInfo_t tConflict;
    tCell_t tPos;

    int16_t LabelNoiseThd = 0;
    int16_t delta;
    uint8_t rLabel_val;

#if FAST_SPLIT		//original
    bool_t sort_en = YES;
#else
	int16_t threshold_next = 0;
#endif
    // About 3 groups can be eliminated after re-ordering if it is small unmatched group.
    // Grouping Start
    label_num = _label_start_idx;

    threshold = thisInfo->tLabel.sValidMaxVal[_valid_area_idx];

//    algorithm_label_Insert_NewRecord_to_LabelTable(label_num, thisInfo->tLabel.tValidMaxPos[_valid_area_idx], thisInfo->tLabel.sValidMaxVal[_valid_area_idx], YES, mode);

//    if( thisInfo->tLabel.usValidCellCnt[_valid_area_idx] > thisModeConf->Label.usMediumNodeCnt )
//    {
//    	LabelNoiseThd = thisInfo->tLabel.sValidMaxVal[_valid_area_idx] - _LowerThd;
////    	LabelNoiseThd = MAX(((thisInfo->tLabel.sValidMaxVal[_valid_area_idx] - _LowerThd)/5), 10);
//    }
//    else if( thisInfo->tLabel.usValidCellCnt[_valid_area_idx] > thisModeConf->Label.usSmallNodeCnt )
//    {
//    	LabelNoiseThd = MAX(((thisInfo->tLabel.sValidMaxVal[_valid_area_idx] - _LowerThd)/5), 10);
//    }
//    else
//    {
//    	LabelNoiseThd = MAX(((thisInfo->tLabel.sValidMaxVal[_valid_area_idx] - _LowerThd)/10), 5);
//    }

	LabelNoiseThd = thisModeConf->Label.ucLabelNoiseThd;

#if FAST_SPLIT		//original
	int i,ii;
    if(sort_en == YES)
    {
    	int valid_sort_num;
    	int temp_data;
    	int max_pos;
		int comp_val;
		int split_num = 0;
		int split_num_first = 0;
		int split_start_num;
    	tCell_t temp_pos;

		if(HAL_READ_LABEL_IMAGE(thisInfo->tLabel.tValidMaxPos[_valid_area_idx].r, thisInfo->tLabel.tValidMaxPos[_valid_area_idx].c)== 0)
		{
			tConflict.ulValue = 0;

			algorithm_label_GetConflictInfo(YES, BOUNDARY_8_SEARCH_DIRECTION, 0, thisInfo->tLabel.tValidMaxPos[_valid_area_idx], &tConflict, mode);

			if( tConflict.tInfo.NUM == 0 && split_num_first < MAX_SPLIT_NUM-1)
			{
				algorithm_label_Insert_NewRecord_to_LabelTable(label_num, thisInfo->tLabel.tValidMaxPos[_valid_area_idx], thisInfo->tLabel.sValidMaxVal[_valid_area_idx], YES, mode);
				split_buf[split_num_first] = thisInfo->tLabel.sValidMaxVal[_valid_area_idx];
				split_pos[split_num_first] = thisInfo->tLabel.tValidMaxPos[_valid_area_idx];
				split_num_first++;
			}
		}
		split_start_num = split_num_first;
	
		comp_val = (threshold - LabelNoiseThd);
    	split_num = MAX_SPLIT_NUM-1;

		for (tPos.r = thisInfo->tLabel.tValidRect[_valid_area_idx].rs; tPos.r <= thisInfo->tLabel.tValidRect[_valid_area_idx].re; tPos.r++)
		{
			for (tPos.c = thisInfo->tLabel.tValidRect[_valid_area_idx].cs; tPos.c <= thisInfo->tLabel.tValidRect[_valid_area_idx].ce; tPos.c++)
			{
//				if(mode == LOCAL_FINGER_MODE)
//				{
//					delta = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(tPos.r, tPos.c);
//				}
//				else
				{
					delta = HAL_READ_DELTA_IMAGE(tPos.r, tPos.c);
				}
				rLabel_val = HAL_READ_LABEL_IMAGE(tPos.r, tPos.c);

				if(delta >= comp_val && rLabel_val == 0 && split_num_first < MAX_SPLIT_NUM-1)
				{
					split_buf[split_num_first] = delta;
					split_pos[split_num_first] = tPos;
					split_num_first++;
				}
				else if(delta >= _LowerThd && rLabel_val == 0)
				{
					split_buf[split_num] = delta;
					split_pos[split_num] = tPos;
					split_num--;
					if(split_num < split_num_first)
					{
						tPos.r = thisInfo->tLabel.tValidRect[_valid_area_idx].re;
						break;
					}
				}
			}
		}
		
		valid_sort_num = MAX_SPLIT_NUM - 1 - split_num + split_num_first;
		
		if(valid_sort_num < MAX_SPLIT_NUM)
		{
			for(i=split_num_first; i<valid_sort_num; i++)
			{
				split_num++;
				split_buf[i] = split_buf[split_num];
				split_pos[i] = split_pos[split_num];
			}

			for(i=split_num_first; i<valid_sort_num-1; i++)
			{
				temp_data = split_buf[i];
				max_pos = i;
				for(ii=i+1; ii<valid_sort_num; ii++)
				{
					if(temp_data < split_buf[ii])
						max_pos = ii, temp_data = split_buf[ii];
				}
				split_buf[max_pos] = split_buf[i];
				split_buf[i] = temp_data;
				temp_pos = split_pos[max_pos];
				split_pos[max_pos] = split_pos[i];
				split_pos[i] = temp_pos;
			}

			label_num = thisInfo->tLabel.ucNum;
			for(i=split_start_num; i<valid_sort_num; i++)
			{
				rLabel_val = HAL_READ_LABEL_IMAGE(split_pos[i].r, split_pos[i].c);

				if (rLabel_val == 0)
				{
					tConflict.tInfo.SET = NO;
					tConflict.tInfo.NUM = 0;
					tConflict.tInfo.BF  = 0;

					algorithm_label_GetConflictInfo(YES, BOUNDARY_8_SEARCH_DIRECTION, 0, split_pos[i], &tConflict, mode);

					if( tConflict.tInfo.NUM == 0 )
					{
						if( label_num < LOOSE_POSBUF_ )
						{
							algorithm_label_Insert_NewRecord_to_LabelTable(label_num, split_pos[i], split_buf[i], YES, mode);

							label_num++;
						}
					}
				}
			}
		}
    }
    else
    {
		if(HAL_READ_LABEL_IMAGE(thisInfo->tLabel.tValidMaxPos[_valid_area_idx].r, thisInfo->tLabel.tValidMaxPos[_valid_area_idx].c)== 0)
		{
			tConflict.ulValue = 0;

			algorithm_label_GetConflictInfo(YES, BOUNDARY_8_SEARCH_DIRECTION, 0, thisInfo->tLabel.tValidMaxPos[_valid_area_idx], &tConflict, mode);

			if( tConflict.tInfo.NUM == 0 )
				algorithm_label_Insert_NewRecord_to_LabelTable(label_num, thisInfo->tLabel.tValidMaxPos[_valid_area_idx], thisInfo->tLabel.sValidMaxVal[_valid_area_idx], YES, mode);
		}

		// process prev linked-list
		label_num = thisInfo->tLabel.ucNum;

		for (tPos.r = thisInfo->tLabel.tValidRect[_valid_area_idx].rs; tPos.r <= thisInfo->tLabel.tValidRect[_valid_area_idx].re; tPos.r++)
		{
			for (tPos.c = thisInfo->tLabel.tValidRect[_valid_area_idx].cs; tPos.c <= thisInfo->tLabel.tValidRect[_valid_area_idx].ce; tPos.c++)
			{
//				if(mode == LOCAL_FINGER_MODE)
//				{
//					delta = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(tPos.r, tPos.c);
//				}
//				else
				{
					delta = HAL_READ_DELTA_IMAGE(tPos.r, tPos.c);
				}
				rLabel_val = HAL_READ_LABEL_IMAGE(tPos.r, tPos.c);

				if ((delta >= _LowerThd) && (rLabel_val == 0))
				{
					tConflict.tInfo.SET = NO;
					tConflict.tInfo.NUM = 0;
					tConflict.tInfo.BF  = 0;

					algorithm_label_GetConflictInfo(YES, BOUNDARY_8_SEARCH_DIRECTION, 0, tPos, &tConflict, mode);

					if( tConflict.tInfo.NUM == 0 )
					{
						if( label_num < LOOSE_POSBUF_ )
						{
							algorithm_label_Insert_NewRecord_to_LabelTable(label_num, tPos, delta, YES, mode);

							label_num++;
						}
					}
				}
			}
		}
    }
#else
	uint8_t SearchDirc = BOUNDARY_8_SEARCH_DIRECTION;
	if(HAL_READ_LABEL_IMAGE(thisInfo->tLabel.tValidMaxPos[_valid_area_idx].r, thisInfo->tLabel.tValidMaxPos[_valid_area_idx].c)== 0)
	{
		tConflict.ulValue = 0;

		if(thisModeConf->Label.bSplitSearchDirc_4_On)SearchDirc = BOUNDARY_4_SEARCH_DIRECTION;
		
		algorithm_label_GetConflictInfo(YES, SearchDirc, 0, thisInfo->tLabel.tValidMaxPos[_valid_area_idx], &tConflict, mode);

		if( tConflict.tInfo.NUM == 0 )
			algorithm_label_Insert_NewRecord_to_LabelTable(label_num, thisInfo->tLabel.tValidMaxPos[_valid_area_idx], thisInfo->tLabel.sValidMaxVal[_valid_area_idx], YES, mode);
	}

	thisInfo->tLabel.LabelSplitMergeCnt = 0;

    do
    {
    	threshold = MAX((threshold - LabelNoiseThd), _LowerThd);

    	// process prev linked-list
    	label_num = thisInfo->tLabel.ucNum;

		threshold_next = 0;
		for (tPos.r = thisInfo->tLabel.tValidRect[_valid_area_idx].rs; tPos.r <= thisInfo->tLabel.tValidRect[_valid_area_idx].re; tPos.r++)
		{
			for (tPos.c = thisInfo->tLabel.tValidRect[_valid_area_idx].cs; tPos.c <= thisInfo->tLabel.tValidRect[_valid_area_idx].ce; tPos.c++)
			{
//				if(mode == LOCAL_FINGER_MODE)
//				{
//					delta = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(tPos.r, tPos.c);
//				}
//				else
				{
					delta = HAL_READ_DELTA_IMAGE(tPos.r, tPos.c);
				}					
				rLabel_val = HAL_READ_LABEL_IMAGE(tPos.r, tPos.c);

				if ((delta >= threshold) && (rLabel_val == 0))
				{
					tConflict.tInfo.SET = NO;
					tConflict.tInfo.NUM = 0;
					tConflict.tInfo.BF  = 0;

					if(thisModeConf->Label.bSplitSearchDirc_4_On)
					{
						if(thisInfo->DrawingDirection == 1 || thisInfo->DrawingDirection == 2)SearchDirc = BOUNDARY_8_SEARCH_DIRECTION;
						else SearchDirc = BOUNDARY_4_SEARCH_DIRECTION;
					}
						
					algorithm_label_GetConflictInfo(YES, SearchDirc, 0, tPos, &tConflict, mode);
	
					if( tConflict.tInfo.NUM == 0 )
					{
						thisInfo->tLabel.LabelSplitMergeCnt++;
						if(thisInfo->TouchNumCnt > thisModeConf->Coord.ucTouchCountMax && label_num >= thisInfo->tCoord.tOrgPastPos[0].sFinger_)	continue;
						
						if( label_num < LOOSE_POSBUF_ )
						{
							algorithm_label_Insert_NewRecord_to_LabelTable(label_num, tPos, delta, YES, mode);

							label_num++;
						}
					}
				}
				else if( delta < threshold )
				{
					if( threshold_next < delta )
					{
						threshold_next = delta;
					}
				}
			}
		}

		//if( temp_label->usValidCellCnt[_valid_area_idx] < thisModeConf->Label.usSmallTouchThd/*thisModeConf->Label.usLargeTouchThd*/ )
		{
			LabelNoiseThd = (threshold - threshold_next);
		}
    } while (threshold > _LowerThd);
#endif
}

int testLabelArray[4];
int testLabelArray2[4];
int heon_algorithm(int id, uint8_t _search_idx, tCell_t _tPos)
{
	int i, r_i, c_i;
	uint8_t neighbor_label_id;
	int sum = 0;

	for( i=0; i<BOUNDARY_8_SEARCH_TABLE[_search_idx].Num; i++ )
	{
#if (PAD_ == 0)
			if((_tPos.r == 0 && BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].r == -1) || (_tPos.r == ROW_MAX-1 && BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].r == 1))
				r_i = _tPos.r;
			else
				r_i = _tPos.r + BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].r;

			if((_tPos.c == 0 && BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].c == -1) || (_tPos.c == COL_MAX-1 && BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].c == 1))
				c_i = _tPos.c;
			else
				c_i = _tPos.c + BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].c;
#else 
			r_i = _tPos.r + BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].r;
			c_i = _tPos.c + BOUNDARY_8_SEARCH_TABLE[_search_idx].Table[i].c;
#endif

		if(HAL_READ_LABEL_IMAGE(r_i,c_i) == id)
		{
			if(id==1)
				testLabelArray[i] = HAL_READ_DELTA_IMAGE(r_i,c_i);
			else
				testLabelArray2[i] = HAL_READ_DELTA_IMAGE(r_i,c_i);
			
			sum += HAL_READ_DELTA_IMAGE(r_i,c_i);
		}
	}
	
	return sum;
}

int testConflictValue = 0;
int testLabelSum[10] = {0, };
int testSum = 0;

uint8_t algorithm_label_Split_PostProcess(uint8_t _valid_area_idx, uint8_t _label_start_idx, int mode)
{
	int l;
	int16_t d, label_id;
	tConflictInfo_t tConflict;
	tCell_t tPos;
	uint8_t rtn_val = _label_start_idx;
	int sum = 0;
	tLabelInfo_t	*temp_label;

	temp_label = &thisInfo->tLabel;

	for( tPos.r=temp_label->tValidRect[_valid_area_idx].rs; tPos.r<=temp_label->tValidRect[_valid_area_idx].re; tPos.r++ )
	{
		for( tPos.c=temp_label->tValidRect[_valid_area_idx].cs; tPos.c<=temp_label->tValidRect[_valid_area_idx].ce; tPos.c++ )
		{
			label_id = HAL_READ_LABEL_IMAGE(tPos.r, tPos.c);

			if( label_id == LABEL_CONFLICT_MARKER )
			{
				sum = 0;
				tConflict.ulValue = 0;

				algorithm_label_GetConflictInfo(NO, BOUNDARY_8_SEARCH_DIRECTION, 0, tPos, &tConflict, mode);
				
				#if WeightedConflict
				for( l=LOOSE_POSBUF_; l--; )
				{
					if( (tConflict.tInfo.BF & _BV(l)) )
					{
						testLabelSum[l] = heon_algorithm(l+1, 0, tPos);
						sum += heon_algorithm(l+1, 0, tPos);
					}
				}
				testSum = sum;
				testConflictValue = HAL_READ_DELTA_IMAGE(tPos.r, tPos.c);
				#endif
				
				for( l=LOOSE_POSBUF_; l--; )
				{
					if( (tConflict.tInfo.BF & _BV(l)) )
					{
//						if(mode == LOCAL_FINGER_MODE)
//							d = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(tPos.r, tPos.c)/tConflict.tInfo.NUM;
//						else
						
						
						
						#if WeightedConflict
							#if ConflictTest
								if(sum != 0 && tPos.c < COL_MAX >> 1){
									d = (HAL_READ_DELTA_IMAGE(tPos.r, tPos.c) * heon_algorithm(l+1, 0, tPos)/ sum);
								}
								else
									d = HAL_READ_DELTA_IMAGE(tPos.r, tPos.c)/tConflict.tInfo.NUM;
							#else
								if(sum != 0){
									d = HAL_READ_DELTA_IMAGE(tPos.r, tPos.c) * heon_algorithm(l+1, 0, tPos)/ sum;
								}
								else
									d = HAL_READ_DELTA_IMAGE(tPos.r, tPos.c)/tConflict.tInfo.NUM;
							#endif
						#else
							d = HAL_READ_DELTA_IMAGE(tPos.r, tPos.c)/tConflict.tInfo.NUM;
						#endif
						
						
						algorithm_label_Add_NewNode_to_LabelRecord(l, tPos, d, NO, NO, mode);

						temp_label->tTable[l].tConflictInfo.tInfo.BF |= tConflict.tInfo.BF;
						if(rtn_val > l)        rtn_val = l;
					}
				}

				tConflict.tInfo.SET = YES;
				HAL_WRITE_CONFLICT_LABEL_IMAGE(tPos.r, tPos.c, tConflict.ulValue);
			}
			else
			{
				HAL_WRITE_CONFLICT_LABEL_IMAGE(tPos.r, tPos.c, 0);
			}
		}
	}
	return rtn_val;
}

void algorithm_label_Merge( uint8_t _valid_area_idx, uint8_t _label_start_idx, int mode)
{
	int r, c, i, j;
	tXY_t tPos_i, tPos_j;
	int delta_i, delta_mean, delta_j, delta_target, delta_ratio;
	tCell_t node_i, node_mean, node_j;
	tConflictInfo_t tConflict;
	tRect_t tExpectConflictRect;
    uint8_t rLabel_val;
	#if USED_NOISE_HOPPING_FREQ
	int delta_min, delta_max;
	#endif

	tLabelInfo_t	*temp_label;

	temp_label = &thisInfo->tLabel;

	for( i=_label_start_idx; i<temp_label->ucNum; i++ )
	{
		if( temp_label->tTable[i].ulStrength == 0 )
		{
			continue;
		}

		for( j=i+1; j<LOOSE_POSBUF_; j++ )
		{
			if( temp_label->tTable[i].tConflictInfo.tInfo.BF & _BV(j) )
			{
				if( temp_label->tTable[j].ulStrength == 0 )
				{
					temp_label->tTable[i].tConflictInfo.tInfo.BF &= ~_BV(j);
					temp_label->tTable[i].tConflictInfo.tInfo.NUM--;

					continue;
				}

				tPos_i.x  = (temp_label->tTable[i].tCoord.x + (temp_label->tTable[i].ulStrength>>1))<<POS_BOOST_SHIFT_;
				tPos_i.x /= temp_label->tTable[i].ulStrength;
				tPos_i.y  = (temp_label->tTable[i].tCoord.y + (temp_label->tTable[i].ulStrength>>1))<<POS_BOOST_SHIFT_;
				tPos_i.y /= temp_label->tTable[i].ulStrength;

				tPos_j.x  = (temp_label->tTable[j].tCoord.x + (temp_label->tTable[j].ulStrength>>1))<<POS_BOOST_SHIFT_;
				tPos_j.x /= temp_label->tTable[j].ulStrength;
				tPos_j.y  = (temp_label->tTable[j].tCoord.y + (temp_label->tTable[j].ulStrength>>1))<<POS_BOOST_SHIFT_;
				tPos_j.y /= temp_label->tTable[j].ulStrength;

				node_i.c = temp_label->tTable[i].tMaxCell.c;
				node_i.r = temp_label->tTable[i].tMaxCell.r;

//				if(mode == LOCAL_FINGER_MODE)
//					delta_i = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(node_i.r, node_i.c);
//				else
					delta_i = HAL_READ_DELTA_IMAGE(node_i.r, node_i.c);

				node_j.c = temp_label->tTable[j].tMaxCell.c;
				node_j.r = temp_label->tTable[j].tMaxCell.r;

//				if(mode == LOCAL_FINGER_MODE)
//					delta_j = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(node_j.r, node_j.c);
//				else
					delta_j = HAL_READ_DELTA_IMAGE(node_j.r, node_j.c);

				if( temp_label->usValidCellCnt[_valid_area_idx] < thisModeConf->Label.usSmallNodeCnt )
				{
					tExpectConflictRect.cs = MIN(temp_label->tTable[i].tRect.cs, temp_label->tTable[j].tRect.cs);
					tExpectConflictRect.ce = MAX(temp_label->tTable[i].tRect.ce, temp_label->tTable[j].tRect.ce);
					tExpectConflictRect.rs = MIN(temp_label->tTable[i].tRect.rs, temp_label->tTable[j].tRect.rs);
					tExpectConflictRect.re = MAX(temp_label->tTable[i].tRect.re, temp_label->tTable[j].tRect.re);
				}
				else
				{
					tExpectConflictRect.cs = MIN(node_i.c, node_j.c);
					tExpectConflictRect.ce = MAX(node_i.c, node_j.c);
					tExpectConflictRect.rs = MIN(node_i.r, node_j.r);
					tExpectConflictRect.re = MAX(node_i.r, node_j.r);
				}

				delta_mean = INT16_MIN;
				node_mean.r = (node_i.r + node_j.r)>>1;
				node_mean.c = (node_i.c + node_j.c)>>1;
				for( r=tExpectConflictRect.rs; r<=tExpectConflictRect.re; r++ )
				{
					for( c=tExpectConflictRect.cs; c<= tExpectConflictRect.ce; c++ )
					{
						rLabel_val = HAL_READ_LABEL_IMAGE(r, c);

						if( rLabel_val == LABEL_CONFLICT_MARKER )
						{
							tConflict.ulValue = HAL_READ_CONFLICT_LABEL_IMAGE(r, c);

							if( (tConflict.tInfo.BF & (_BV(temp_label->tTable[i].cId - 1) | _BV(temp_label->tTable[j].cId - 1))) ==
									(_BV(temp_label->tTable[i].cId - 1) | _BV(temp_label->tTable[j].cId - 1)) )
							{
								int16_t delta_t;

//								if(mode == LOCAL_FINGER_MODE)
//									delta_t = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(r, c);
//								else
									delta_t = HAL_READ_DELTA_IMAGE(r, c);

								if( delta_mean < delta_t)
								{
									delta_mean = delta_t;
									node_mean.r = r;
									node_mean.c = c;
								}
							}
						}
					}
				}

				if( delta_mean == INT16_MIN )
				{
//					if(mode == LOCAL_FINGER_MODE)
//						delta_mean = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(node_mean.r, node_mean.c);
//					else
						delta_mean = HAL_READ_DELTA_IMAGE(node_mean.r, node_mean.c);
				}

				delta_target = (delta_i*temp_label->tTable[j].ulStrength + delta_j*temp_label->tTable[i].ulStrength)/(temp_label->tTable[i].ulStrength + temp_label->tTable[j].ulStrength);

//				#ifdef GetAngleLookUpHighResolution
//				angle = algorithm_calc_angle_inter_2points_HighResolution(tPos_j.x-tPos_i.x, tPos_j.y-tPos_i.y) * 0.001;
//				#else
//				angle = algorithm_calc_angle_inter_2points(tPos_j.x-tPos_i.x, tPos_j.y-tPos_i.y) * 0.01;
//				#endif

//				if( (temp_label->usValidCellCnt[_valid_area_idx] < thisModeConf->Label.usSmallNodeCnt) && (angle%90 > 20 && angle%90 < 70) )
//				{
//					delta_ratio = (delta_mean * thisModeConf->Label.ucMergeSmallDiagThdPer)/delta_target;
//				}
//				else if( (temp_label->usValidCellCnt[_valid_area_idx] < thisModeConf->Label.usMediumNodeCnt) && (angle%90 > 30 && angle%90 < 60) )
//				{
//					delta_ratio = (delta_mean * thisModeConf->Label.ucMergeMediumDiagThdPer)/delta_target;
//				}
//				else
				{
					delta_ratio = (delta_mean * 100)/delta_target;
				}

				if( temp_label->usValidCellCnt[_valid_area_idx] < thisModeConf->Label.usSmallNodeCnt )
				{
					temp_label->iMergeThdPer = thisModeConf->Label.ucMergeSmallThdPer;
				}
				else if( temp_label->usValidCellCnt[_valid_area_idx] < thisModeConf->Label.usMediumNodeCnt )
				{
//					temp_label->iMergeThdPer = thisModeConf->Label.ucSmallMergeThdPer;
//					temp_label->iMergeThdPer += ((thisModeConf->Label.ucLargeMergeThdPer - thisModeConf->Label.ucSmallMergeThdPer)
//							*(temp_label->usValidCellCnt[_valid_area_idx] - thisModeConf->Label.usSmallTouchThd))
//							/(thisModeConf->Label.usLargeTouchThd - thisModeConf->Label.usSmallTouchThd);
					temp_label->iMergeThdPer = thisModeConf->Label.ucMergeMediumThdPer;
				}
				else
				{
					temp_label->iMergeThdPer = thisModeConf->Label.ucMergeMediumThdPer;
				}
				
				#if USED_NOISE_HOPPING_FREQ
				if(temp_label->tTable[i].sMaxCellVal > temp_label->tTable[j].sMaxCellVal)
				{
					delta_max = temp_label->tTable[i].sMaxCellVal;
					delta_min = temp_label->tTable[j].sMaxCellVal;
				}
				else
				{
					delta_max = temp_label->tTable[j].sMaxCellVal;
					delta_min = temp_label->tTable[i].sMaxCellVal;
				}
				
				if((abs(delta_mean - delta_min) < thisModeConf->Label.usLabelPeakValleyDiffTh || (delta_max - delta_min) > thisModeConf->Label.usLabelPeakDiffTh) && temp_label->usValidCellCnt[_valid_area_idx] < thisModeConf->Label.usMergeLabelSizeTh)
				{
					delta_ratio = temp_label->iMergeThdPer + 1;
				}
				#endif

				if( temp_label->iMergeThdPer < delta_ratio )
				{
					int k;
					
					for( r=temp_label->tTable[j].tRect.rs; r<=temp_label->tTable[j].tRect.re; r++ )
					{
						for( c=temp_label->tTable[j].tRect.cs; c<=temp_label->tTable[j].tRect.ce; c++ )
						{
							tCell_t tNodePos = { .r = r, .c = c };

							rLabel_val = HAL_READ_LABEL_IMAGE(r, c);

							if( rLabel_val == temp_label->tTable[j].cId )
							{
//								if(mode == LOCAL_FINGER_MODE)
//								{
//									HAL_WRITE_LABEL_IMAGE(r, c, temp_label->tTable[i].cId);
//									algorithm_label_Add_NewNode_to_LabelRecord(i, tNodePos, HAL_READ_LOCAL_FINGER_DELTA_IMAGE(r, c), NO, NO, mode);
//								}
//								else
								{
									HAL_WRITE_LABEL_IMAGE(r, c, temp_label->tTable[i].cId);
									algorithm_label_Add_NewNode_to_LabelRecord(i, tNodePos, HAL_READ_DELTA_IMAGE(r, c), NO, NO, mode);
								}
							}
							else if( rLabel_val == LABEL_CONFLICT_MARKER )
							{
								tConflict.ulValue = HAL_READ_CONFLICT_LABEL_IMAGE(r, c);

								if( (tConflict.tInfo.BF & _BV(i)) && (tConflict.tInfo.BF & _BV(j)) )
								{
									tConflict.tInfo.NUM--;
									tConflict.tInfo.BF &= ~(tConflict.tInfo.BF & _BV(j));
								}
								else if( tConflict.tInfo.BF & _BV(j) )
								{
									tConflict.tInfo.BF |=  _BV(i);
									tConflict.tInfo.BF &= ~_BV(j);
								}

								if( tConflict.tInfo.NUM == 1 || tConflict.tInfo.BF == 0 )
								{
									HAL_WRITE_LABEL_IMAGE(r, c, temp_label->tTable[i].cId);
									tConflict.ulValue = 0;
								}
								HAL_WRITE_CONFLICT_LABEL_IMAGE(r, c, tConflict.ulValue);
							}
						}
					}

					temp_label->tTable[i].tConflictInfo.tInfo.BF |= temp_label->tTable[j].tConflictInfo.tInfo.BF;
					temp_label->tTable[i].tConflictInfo.tInfo.NUM = 0;
					for( k=LOOSE_POSBUF_; k--; )
					{
						if( temp_label->tTable[i].tConflictInfo.tInfo.BF & _BV(k) )
						{
							temp_label->tTable[i].tConflictInfo.tInfo.NUM++;
						}
					}
					// Merge S&R inter 2 Points iTh <== jTh
					{

					}
					// Clear LabelTable & PosTable 2nd Point
					{
						memset(&temp_label->tTable[j], 0x00, sizeof(tLabelTable_t) );
					}
				}
			}
		}
	}
}

void algorithm_label_Merge_PostProcess(uint8_t _valid_area_idx, uint8_t _label_start_idx, int mode)
{
	int i, j, l, r, c;
	uint8_t ucDeleteLabel_num = 0;
    uint8_t rLabel_val;

	tLabelInfo_t	*temp_label;
	temp_label = &thisInfo->tLabel;

	for( i=_label_start_idx; i<temp_label->ucNum-1; i++ )
	{
		if( temp_label->tTable[i].ulStrength == 0 )
		{
			for( j=i+1; j<temp_label->ucNum; j++ )
			{
				if( temp_label->tTable[j].ulStrength != 0 )
				{
					temp_label->tTable[i] = temp_label->tTable[j];
					memset((void *)&temp_label->tTable[j], 0x00, sizeof(tLabelTable_t));

					break;
				}
			}
		}
	}

	for( l=_label_start_idx; l<temp_label->ucNum; l++ )
	{
		if( temp_label->tTable[l].ulStrength != 0 )
		{
			int _Id = temp_label->tTable[l].cId;
			if( _Id != (l+1) )
			{
				for( r=temp_label->tValidRect[_valid_area_idx].rs; r<=temp_label->tValidRect[_valid_area_idx].re; r++ )
				{
					for( c=temp_label->tValidRect[_valid_area_idx].cs; c<=temp_label->tValidRect[_valid_area_idx].ce; c++ )
					{
						rLabel_val = HAL_READ_LABEL_IMAGE(r, c);

						if( rLabel_val == _Id )
						{
							HAL_WRITE_LABEL_IMAGE(r, c, l+1);
						}
					}
				}
			}

			memset((void *)&temp_label->tTable[l], 0x00, sizeof(tLabelTable_t));
			temp_label->tTable[l].cId = l+1;
			temp_label->tTable[l].tRect.cs = COL_MAX-1;
			temp_label->tTable[l].tRect.rs = ROW_MAX-1;

			for( r=temp_label->tValidRect[_valid_area_idx].rs; r<=temp_label->tValidRect[_valid_area_idx].re; r++ )
			{
				for( c=temp_label->tValidRect[_valid_area_idx].cs; c<=temp_label->tValidRect[_valid_area_idx].ce; c++ )
				{
					tCell_t tNodePos = { .r = r, .c = c };

					rLabel_val = HAL_READ_LABEL_IMAGE(r, c);

					if( rLabel_val == l+1 )
					{
//						if(mode == LOCAL_FINGER_MODE)
//							algorithm_label_Add_NewNode_to_LabelRecord(l, tNodePos, HAL_READ_LOCAL_FINGER_DELTA_IMAGE(r, c), NO, NO, mode);
//						else
							algorithm_label_Add_NewNode_to_LabelRecord(l, tNodePos, HAL_READ_DELTA_IMAGE(r, c), NO, NO, mode);
					}
					else if( rLabel_val == LABEL_CONFLICT_MARKER )
					{
						int d;
						tConflictInfo_t tConflict;

						algorithm_label_GetConflictInfo(NO, BOUNDARY_8_SEARCH_DIRECTION, 0, tNodePos, &tConflict, mode);

						if( tConflict.tInfo.BF & _BV(l) )
						{
//							if(mode == LOCAL_FINGER_MODE)
//								d = HAL_READ_LOCAL_FINGER_DELTA_IMAGE(tNodePos.r, tNodePos.c)/tConflict.tInfo.NUM;
//							else
								d = HAL_READ_DELTA_IMAGE(tNodePos.r, tNodePos.c)/tConflict.tInfo.NUM;

							algorithm_label_Add_NewNode_to_LabelRecord(l, tNodePos, d, NO, NO, mode);
						}
					}
				}
			}
		}
		else
		{
			ucDeleteLabel_num++;
		}
	}

	temp_label->ucNum -= ucDeleteLabel_num;
}

#ifdef SHORT_COMPENSATION
extern uint8_t short_cnt;
extern tCell_t short_pos[SHORT_NUM];
void algorithm_label_Delta_Compensation(uint8_t _valid_area_idx, uint8_t _label_start_idx, int16_t usLabelThd)
{
	int i, k, r, c, cnt, avg;
	int delta_buf[4], delta_flag[4];
	
	for (k = 0; k < short_cnt; k++)
	{
		for (r = thisInfo->tLabel.tValidRect[_valid_area_idx].rs; r <= thisInfo->tLabel.tValidRect[_valid_area_idx].re; r++)
		{
			if( r == short_pos[k].r )
			{
				for (c = thisInfo->tLabel.tValidRect[_valid_area_idx].cs; c <= thisInfo->tLabel.tValidRect[_valid_area_idx].ce; c++)
				{
					if( c == short_pos[k].c )
					{
						cnt = 0;
						memset(delta_flag, 0, sizeof(delta_flag));
						delta_buf[0]  = HAL_READ_DELTA_IMAGE(r-1, c);
						delta_buf[1]  = HAL_READ_DELTA_IMAGE(r, c-1);
						delta_buf[2]  = HAL_READ_DELTA_IMAGE(r, c+1);
						delta_buf[3]  = HAL_READ_DELTA_IMAGE(r+1, c);
						
						for (i = 0; i < short_cnt; i++)
						{
							if( i == k )	continue;
							if( r == short_pos[i].r )
							{
								if( (c-1) == short_pos[i].c )			delta_flag[1] = 1, cnt++;
								else if( (c+1) == short_pos[i].c )		delta_flag[2] = 1, cnt++;
							}
							else if( (r-1) == short_pos[i].r )
							{
								if( c == short_pos[i].c )				delta_flag[0] = 1, cnt++;
							}
							else if( (r+1) == short_pos[i].r )
							{
								if( c == short_pos[i].c )				delta_flag[3] = 1, cnt++;
							}
						}
						
						for(i=0; i<4; i++){
							if(delta_flag[i]==0 && delta_buf[i]==0) 	delta_flag[i] = 1, cnt++;
						}

						
						if( cnt == 0 ){
							avg = ( delta_buf[0] + delta_buf[1] + delta_buf[2] + delta_buf[3] ) >> 2;
						}
						else if( cnt == 1 ){
							if( delta_flag[0] == 1 ||  delta_flag[3] == 1 )
							{
								avg = ( delta_buf[1] + delta_buf[2] ) >> 1;
							}
							else
							{
								avg = ( delta_buf[0] + delta_buf[3] ) >> 1;
							}
						}
						else{
							avg = 0, cnt = 0;
							if(delta_flag[0] == 0){
								avg += delta_buf[0], cnt++;
							}
							if(delta_flag[1] == 0){
								avg += delta_buf[1], cnt++;
							}
							if(delta_flag[2] == 0){
								avg += delta_buf[2], cnt++;
							}
							if(delta_flag[3] == 0){
								avg += delta_buf[3], cnt++;
							}
							avg /= cnt;
						}
						
						HAL_WRITE_DELTA_IMAGE(r, c, avg);
					}
				}
			}
		}
	}
}
#endif

void algorithm_label_SplitNMerge_process(int mode)
{
	uint8_t valid_area_idx, label_start_idx;
	uint16_t usLabelThd;

	tOrigDeltaInfo_t	*temp_delta;
	tLabelInfo_t 		*temp_label;

	temp_delta = &thisInfo->tDelta;
	temp_label = &thisInfo->tLabel;
	
	
#if ADAPTIVE_SEEDBASE
	int16_t AdaptiveSeedBase = 0;
	
	if(thisInfo->bIsPalm){
		AdaptiveSeedBase = thisModeConf->Label.usSeedBase - (temp_delta->iPosCnt>>4);
		if(AdaptiveSeedBase < (thisModeConf->Label.usSeedBase>>1))
			AdaptiveSeedBase = (thisModeConf->Label.usSeedBase>>1);
	}
	else					
		AdaptiveSeedBase = thisModeConf->Label.usSeedBase;
	
	usLabelThd  = AdaptiveSeedBase;
	usLabelThd += ((temp_delta->iMaxStrength - AdaptiveSeedBase) * thisModeConf->Label.ucSeedSlope)>>6;
#else			
	usLabelThd  = thisModeConf->Label.usSeedBase;
	usLabelThd += ((temp_delta->iMaxStrength - thisModeConf->Label.usSeedBase) * thisModeConf->Label.ucSeedSlope)>>6;
#endif		

			
#if LABEL_FAST_EN	
	algorithm_label_SearchValidArea_Fast(temp_delta->tValidRect, usLabelThd, mode);
#else
	algorithm_label_SearchValidArea(temp_delta->tValidRect, usLabelThd, mode);
#endif
			
	if(thisModeConf->Palm.ucPalmDetectionOn == 2 || (thisModeConf->Palm.ucPalmDetectionOn == 3 && thisInfo->bNewVersionPalm == 1))
		algorithm_label_palm_rejection(mode);
			
	for( valid_area_idx=0; valid_area_idx<temp_label->ucValidNum; valid_area_idx++ )
	{
		label_start_idx = temp_label->ucNum;
		
	#ifdef SHORT_COMPENSATION			
		algorithm_label_Delta_Compensation(valid_area_idx, label_start_idx, usLabelThd);
	#endif	
		
		algorithm_label_Split(valid_area_idx, label_start_idx, usLabelThd, mode);
		label_start_idx = algorithm_label_Split_PostProcess(valid_area_idx, label_start_idx, mode);
		algorithm_label_Merge(valid_area_idx, label_start_idx, mode);
		algorithm_label_Merge_PostProcess(valid_area_idx, label_start_idx, mode);			
	}

	if( thisModeConf->Label.bExpand )
	{
		algorithm_label_MarkBoundary(YES, mode);
	}

#if (FingerAreaPenDeltaDelete==1 || FingerAreaPenDeltaNoAcc==1 || FingerAreaLineFilter == 1)		
	if(thisModeConf->BaseLine.cFingerAreaPenDeltaDelete != 0 || thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc != 0 || thisModeConf->SensingFilter.sFingerAreaLineFilterLimit != 0)
	{
		int i;
		for(i = 0; i<temp_label->ucNum; i++)
		{
			if(thisInfo->tPenInfo.LocalFingerArea.rs > temp_label->tTable[i].tRect.rs)thisInfo->tPenInfo.LocalFingerArea.rs = temp_label->tTable[i].tRect.rs;
			if(thisInfo->tPenInfo.LocalFingerArea.re < temp_label->tTable[i].tRect.re)thisInfo->tPenInfo.LocalFingerArea.re = temp_label->tTable[i].tRect.re;
			if(thisInfo->tPenInfo.LocalFingerArea.cs > temp_label->tTable[i].tRect.cs)thisInfo->tPenInfo.LocalFingerArea.cs = temp_label->tTable[i].tRect.cs;
			if(thisInfo->tPenInfo.LocalFingerArea.ce < temp_label->tTable[i].tRect.ce)thisInfo->tPenInfo.LocalFingerArea.ce = temp_label->tTable[i].tRect.ce;
		}
	}	
#endif
}

#if USED_PEN_MODE_OPERATION
#if (DeltaBaseNewEdgeCompen_SW == YES)
extern tRingMSInfo_t pTRingInfo;
#if (PEN_Edge_UsePerMaxSum == YES)
extern uint32_t ulExtStrengthAvg;
#endif
void algorithm_label_EdgeExpand_DeltaBase(int mode,int iRetVal, int TiltMode)
{
	int r, c;
	int check_r, check_c;
	int search_r = -1, search_c = -1, search_c1,search_r1;
	int apply_r, apply_c, OP_Mode;
//	int sum_val;
//	int edge_ratio;
	int _d,_d1,_d2,mul,sr,/*xof,*/mul1,sr1,max_sum,max_sum_LR;
//	static int PreStrength = 0;
	int mul_r,sr_r,mul1_r,sr1_r;
	int EdgeStrength = 0;


	__attribute__ ((aligned(4)))tAlgorithmPenParaEdgeConf_t tTmpParaEdgeSetVal;
	
//	if(ACTIVEPEN_TYPE_LOCAL_WGP == gAlgoRawDataType)
//		memcpy(&tTmpParaEdgeSetVal,&thisModeConf->PenParaEdgeSetVal,sizeof(tAlgorithmPenParaEdgeConf_t));
//	else if(ACTIVEPEN_TYPE_LOCAL_MS == gAlgoRawDataType)
	memcpy(&tTmpParaEdgeSetVal,&thisModeConf->PenParaEdgeSetVal,sizeof(tAlgorithmPenParaEdgeConf_t));
	
	if(mode == LOCAL_RING_MODE)
	{
		thisInfo->tTiltInfo.sRing_ExtStrength = thisInfo->tLabel_local_dsp.ulExtStrength;
	}
	else if((mode == LOCAL_MODE || mode == LOCAL_HOVER_MODE) && (thisInfo->tPenInfo.bPenPostProcessFlag==0 && thisInfo->tPenInfo.bForcePenContactFlag==0))
	{
//		if((iRetVal==PARTIAL_PEN_COORD3 /*|| iRetVal==PARTIAL_PEN_COORD1*/) && TiltMode == 2)thisInfo->tTiltInfo.sRing_ExtStrength = pTRingInfo.ulStrength;
		
		check_r = thisInfo->tLabel_local_dsp.tValidMaxPos.r + thisInfo->tPenInfo.ucCoordiRowStart;
		check_c = thisInfo->tLabel_local_dsp.tValidMaxPos.c;
		
		if(mode == LOCAL_HOVER_MODE)
			OP_Mode = LOCAL_HOVER_MODE;
		else OP_Mode = LOCAL_MODE;
		
		//if(check_r <= 1)
		if( (check_r == 0 && OP_Mode == LOCAL_MODE) || (check_r <= 1 && OP_Mode == LOCAL_HOVER_MODE) )
		{
			search_r = 0, apply_r = check_r-1, search_r1 = 1;
			mul_r = tTmpParaEdgeSetVal.top_mul0; 
			sr_r = tTmpParaEdgeSetVal.top_SR0;
			mul1_r = tTmpParaEdgeSetVal.top_mul1; 
			sr1_r = tTmpParaEdgeSetVal.top_SR1;
			if(OP_Mode == LOCAL_MODE)			
			{
				max_sum = tTmpParaEdgeSetVal.top_max_sum;
	#if (PEN_CORNER_EXPEND_ADD_1 == YES)			
				if(check_c == 1)
				{
					mul_r += tTmpParaEdgeSetVal.top_mul0_LeftCornerOffset;
					max_sum += tTmpParaEdgeSetVal.top_max_sum_LeftCornerOffset;
				}
				else if(check_c == COL_MAX-2)
				{
					mul_r += tTmpParaEdgeSetVal.top_mul0_RightCornerOffset;
					max_sum += tTmpParaEdgeSetVal.top_max_sum_RightCornerOffset;
				}
	#endif
			}
			else
				max_sum = tTmpParaEdgeSetVal.top_max_sum_hover;
		}
		else if((check_r == ROW_MAX-1 && OP_Mode == LOCAL_MODE) || (check_r >= ROW_MAX-2 && OP_Mode == LOCAL_HOVER_MODE) )
		{
			search_r = ROW_MAX-MUX_MAX_ROW-1, apply_r = ROW_MAX-MUX_MAX_ROW-(ROW_MAX-1 - check_r), search_r1 = ROW_MAX-MUX_MAX_ROW-2;
			mul_r =  tTmpParaEdgeSetVal.bottom_mul0;
			sr_r =   tTmpParaEdgeSetVal.bottom_SR0;
			mul1_r = tTmpParaEdgeSetVal.bottom_mul1;
			sr1_r =  tTmpParaEdgeSetVal.bottom_SR1;
			if(OP_Mode == LOCAL_MODE)		
			{				
				max_sum = tTmpParaEdgeSetVal.bottom_max_sum;
	#if (PEN_CORNER_EXPEND_ADD_1 == YES)			
				if(check_c == 1)
				{
					mul_r += tTmpParaEdgeSetVal.bottom_mul0_LeftCornerOffset;
					max_sum += tTmpParaEdgeSetVal.bottom_max_sum_LeftCornerOffset;
				}
				else if(check_c == COL_MAX-2)
				{
					mul_r += tTmpParaEdgeSetVal.bottom_mul0_RightCornerOffset;
					max_sum += tTmpParaEdgeSetVal.bottom_max_sum_RightCornerOffset;
				}
	#endif
			}
			else
				max_sum = tTmpParaEdgeSetVal.bottom_max_sum_hover;
		}
			
		if( (check_c == 0 && OP_Mode == LOCAL_MODE) || (check_c <= 1 && OP_Mode == LOCAL_HOVER_MODE) )
		{
			search_c = 0;
			apply_c = check_c-1;
			search_c1 = 1;
			mul =  tTmpParaEdgeSetVal.left_mul0;
			sr =   tTmpParaEdgeSetVal.left_SR0;
			mul1 = tTmpParaEdgeSetVal.left_mul1;
			sr1 =  tTmpParaEdgeSetVal.left_SR1;
			if(OP_Mode == LOCAL_MODE)			
				max_sum_LR = tTmpParaEdgeSetVal.left_max_sum;
			else
				max_sum_LR = tTmpParaEdgeSetVal.left_max_sum_hover;
		}
		else if( (check_c == COL_MAX-1 && OP_Mode == LOCAL_MODE) || (check_c >= COL_MAX-2 && OP_Mode == LOCAL_HOVER_MODE) )
		{
			search_c = COL_MAX-1;
			apply_c = COL_MAX- (COL_MAX-1 - check_c); 
			search_c1 = COL_MAX-2;
			mul =  tTmpParaEdgeSetVal.right_mul0;
			sr =   tTmpParaEdgeSetVal.right_SR0;
			mul1 = tTmpParaEdgeSetVal.right_mul1;
			sr1 =  tTmpParaEdgeSetVal.right_SR1;
			if(OP_Mode == LOCAL_MODE)			
				max_sum_LR = tTmpParaEdgeSetVal.right_max_sum;
			else
				max_sum_LR = tTmpParaEdgeSetVal.right_max_sum_hover;
		}
		
		if(search_r != -1 && search_c != -1 && OP_Mode == LOCAL_MODE)
		{
			max_sum = max_sum_LR = 0;
#if (PEN_CORNER_EXPEND_ADD == NO)
			if(search_r == 0 && tTmpParaEdgeSetVal.top_max_sum_corner != 0)
			{
	#if (PEN_Edge_UsePerMaxSum == YES)
				if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum = (ulExtStrengthAvg*tTmpParaEdgeSetVal.top_max_sum_corner)/100;	
				else 
	#endif
					max_sum = tTmpParaEdgeSetVal.top_max_sum_corner;	
			}
			else if(check_r == ROW_MAX-1 && tTmpParaEdgeSetVal.bottom_max_sum_corner != 0)
			{
	#if (PEN_Edge_UsePerMaxSum == YES)
				if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum = (ulExtStrengthAvg*tTmpParaEdgeSetVal.bottom_max_sum_corner)/100;
				else 
	#endif
					max_sum = tTmpParaEdgeSetVal.bottom_max_sum_corner;	
			}
			
			if(search_c == 0 && tTmpParaEdgeSetVal.left_max_sum_corner != 0)
			{
	#if (PEN_Edge_UsePerMaxSum == YES)
				if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum_LR = (ulExtStrengthAvg*tTmpParaEdgeSetVal.left_max_sum_corner)/100;
				else 
	#endif
					max_sum_LR = tTmpParaEdgeSetVal.left_max_sum_corner;	
			}
			else if(search_c == COL_MAX-1 && tTmpParaEdgeSetVal.right_max_sum_corner != 0)
			{
	#if (PEN_Edge_UsePerMaxSum == YES)
				if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum_LR = (ulExtStrengthAvg*tTmpParaEdgeSetVal.right_max_sum_corner)/100;	
				else 
	#endif
					max_sum_LR = tTmpParaEdgeSetVal.right_max_sum_corner;	
			}
#else
			if(search_r == 0)
			{
				if(search_c == 0)
				{
					if(tTmpParaEdgeSetVal.top_max_sum_corner != 0)
					{
	#if (PEN_Edge_UsePerMaxSum == YES)
						if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum = (ulExtStrengthAvg*tTmpParaEdgeSetVal.top_max_sum_corner)/100;	
						else
    #endif							
							max_sum = tTmpParaEdgeSetVal.top_max_sum_corner;
						
						if(tTmpParaEdgeSetVal.max_sum_corner_TiltY_LT && thisInfo->tTiltInfo.sTilt_cnt > 1 && thisInfo->tTiltInfo.HID_TILT_Y > 10000 && thisInfo->tTiltInfo.HID_TILT_X < 10500)
							max_sum += ABS(thisInfo->tTiltInfo.HID_TILT_Y - 9000)/tTmpParaEdgeSetVal.max_sum_corner_TiltY_LT;	
					}
					
					if(tTmpParaEdgeSetVal.left_max_sum_corner != 0)
					{
	#if (PEN_Edge_UsePerMaxSum == YES)
						if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum_LR = (ulExtStrengthAvg*tTmpParaEdgeSetVal.left_max_sum_corner)/100;
						else
    #endif							
							max_sum_LR = tTmpParaEdgeSetVal.left_max_sum_corner;
						
						if(tTmpParaEdgeSetVal.max_sum_corner_TiltX_LT && thisInfo->tTiltInfo.sTilt_cnt > 1 && thisInfo->tTiltInfo.HID_TILT_Y < 10500 && thisInfo->tTiltInfo.HID_TILT_X > 10000)
							max_sum_LR += ABS(thisInfo->tTiltInfo.HID_TILT_X - 9000)/tTmpParaEdgeSetVal.max_sum_corner_TiltX_LT;	
					}
				}
				else if(search_c == COL_MAX-1) 
				{
					if(tTmpParaEdgeSetVal.top_max_sum_corner1 != 0)
					{
	#if (PEN_Edge_UsePerMaxSum == YES)
						if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum = (ulExtStrengthAvg*tTmpParaEdgeSetVal.top_max_sum_corner1)/100;	
						else
    #endif							
							max_sum = tTmpParaEdgeSetVal.top_max_sum_corner1;
						
						if(tTmpParaEdgeSetVal.max_sum_corner_TiltY_RT && thisInfo->tTiltInfo.sTilt_cnt > 1 && thisInfo->tTiltInfo.HID_TILT_Y > 10000 && thisInfo->tTiltInfo.HID_TILT_X > 7500)
							max_sum += ABS(thisInfo->tTiltInfo.HID_TILT_Y - 9000)/tTmpParaEdgeSetVal.max_sum_corner_TiltY_RT;
					}
					
					if(tTmpParaEdgeSetVal.right_max_sum_corner != 0)
					{
	#if (PEN_Edge_UsePerMaxSum == YES)
						if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum_LR = (ulExtStrengthAvg*tTmpParaEdgeSetVal.right_max_sum_corner)/100;
						else
	#endif
							max_sum_LR = tTmpParaEdgeSetVal.right_max_sum_corner;
						
						if(tTmpParaEdgeSetVal.max_sum_corner_TiltX_RT && thisInfo->tTiltInfo.sTilt_cnt > 1 && thisInfo->tTiltInfo.HID_TILT_Y < 10500 && thisInfo->tTiltInfo.HID_TILT_X < 8000)
							max_sum_LR += ABS(thisInfo->tTiltInfo.HID_TILT_X - 9000)/tTmpParaEdgeSetVal.max_sum_corner_TiltX_RT;
					}
				}
			}
			else if(check_r == ROW_MAX-1)
			{
				if(search_c == 0)
				{
					if(tTmpParaEdgeSetVal.bottom_max_sum_corner != 0)
					{
	#if (PEN_Edge_UsePerMaxSum == YES)
						if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum = (ulExtStrengthAvg*tTmpParaEdgeSetVal.bottom_max_sum_corner)/100;	
						else
	#endif
							max_sum = tTmpParaEdgeSetVal.bottom_max_sum_corner;
						
						if(tTmpParaEdgeSetVal.max_sum_corner_TiltY_LB && thisInfo->tTiltInfo.sTilt_cnt > 1 && thisInfo->tTiltInfo.HID_TILT_Y < 8000 && thisInfo->tTiltInfo.HID_TILT_X < 10500)
							max_sum = ABS(thisInfo->tTiltInfo.HID_TILT_Y - 9000)/tTmpParaEdgeSetVal.max_sum_corner_TiltY_LB;
					}
					
					if(tTmpParaEdgeSetVal.left_max_sum_corner1 != 0)
					{
	#if (PEN_Edge_UsePerMaxSum == YES)
						if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum_LR = (ulExtStrengthAvg*tTmpParaEdgeSetVal.left_max_sum_corner1)/100;
						else
	#endif
							max_sum_LR = tTmpParaEdgeSetVal.left_max_sum_corner1;
						
						if(tTmpParaEdgeSetVal.max_sum_corner_TiltX_LB && thisInfo->tTiltInfo.sTilt_cnt > 1 && thisInfo->tTiltInfo.HID_TILT_Y > 7500 && thisInfo->tTiltInfo.HID_TILT_X > 10000)
							max_sum_LR += ABS(thisInfo->tTiltInfo.HID_TILT_X - 9000)/tTmpParaEdgeSetVal.max_sum_corner_TiltX_LB;
					}
				}
				else if(search_c == COL_MAX-1)
				{
					if(tTmpParaEdgeSetVal.bottom_max_sum_corner1 != 0)
					{
	#if (PEN_Edge_UsePerMaxSum == YES)
						if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum = (ulExtStrengthAvg*tTmpParaEdgeSetVal.bottom_max_sum_corner1)/100;	
						else
	#endif
							max_sum = tTmpParaEdgeSetVal.bottom_max_sum_corner1;
						
						if(tTmpParaEdgeSetVal.max_sum_corner_TiltY_RB && thisInfo->tTiltInfo.sTilt_cnt > 1 && thisInfo->tTiltInfo.HID_TILT_Y < 8000 && thisInfo->tTiltInfo.HID_TILT_X > 7500)
							max_sum += ABS(thisInfo->tTiltInfo.HID_TILT_Y - 9000)/tTmpParaEdgeSetVal.max_sum_corner_TiltY_RB;										
					}			

					if(tTmpParaEdgeSetVal.right_max_sum_corner1 != 0)
					{
	#if (PEN_Edge_UsePerMaxSum == YES)
						if(tTmpParaEdgeSetVal.ucUsePerMaxSum)max_sum_LR = (ulExtStrengthAvg*tTmpParaEdgeSetVal.right_max_sum_corner1)/100;
						else
	#endif
							max_sum_LR = tTmpParaEdgeSetVal.right_max_sum_corner1;
						
						if(tTmpParaEdgeSetVal.max_sum_corner_TiltX_RB && thisInfo->tTiltInfo.sTilt_cnt > 1 && thisInfo->tTiltInfo.HID_TILT_Y > 7500 && thisInfo->tTiltInfo.HID_TILT_X < 8000)
							max_sum_LR += ABS(thisInfo->tTiltInfo.HID_TILT_X - 9000)/tTmpParaEdgeSetVal.max_sum_corner_TiltX_RB;
					}						
				}										
			}
#endif
		}
		
		if(search_r != -1)	//up,down edge
		{	
			thisInfo->tTiltInfo.sRingTipStrengthRatio = (thisInfo->tTiltInfo.sRing_ExtStrength<<2)/thisInfo->tLabel_local_dsp.ulExtStrength;
			EdgeStrength = 0;
			for(c = thisInfo->tLabel_local_dsp.tValidRect.cs; c <= thisInfo->tLabel_local_dsp.tValidRect.ce; c++)
			{
				if(HAL_READ_LOCAL_LABEL_IMAGE(search_r, c) != 0)
				{
					EdgeStrength += HAL_READ_LOCAL_DELTA_IMAGE(search_r, c);
					EdgeStrength += HAL_READ_LOCAL_DELTA_IMAGE(search_r1, c);
				}
			}
#if (PEN_Edge_UsePerMaxSum == YES)			
			if(tTmpParaEdgeSetVal.ucUsePerMaxSum && mul_r != 0)mul_r -= ulExtStrengthAvg/tTmpParaEdgeSetVal.ucUsePerMaxSum;
#endif
			for(c = thisInfo->tLabel_local_dsp.tValidRect.cs; c <= thisInfo->tLabel_local_dsp.tValidRect.ce; c++)
			{	
				if(HAL_READ_LOCAL_LABEL_IMAGE(search_r, c) != 0)
				{
					_d = HAL_READ_LOCAL_DELTA_IMAGE(search_r, c);
					_d1 = HAL_READ_LOCAL_DELTA_IMAGE(search_r1, c);
			
					_d2 = 0;
					if(OP_Mode == LOCAL_MODE && mul_r != 0)	
					{						
						_d2 = _d - ((_d1 + ((_d*mul_r)>>sr_r)));

						if(_d2<0)_d2 = 0;
						
						thisInfo->tLabel_local_dsp.tCoord.x      += c * _d2;
						thisInfo->tLabel_local_dsp.tCoord.y      += apply_r * _d2;
						thisInfo->tLabel_local_dsp.ulExtStrength += _d2;
					}
					
					if(c == thisInfo->tLabel_local_dsp.tValidMaxPos.c)
					{
						if(OP_Mode == LOCAL_HOVER_MODE && max_sum != 0)
						{
							if(thisInfo->tPenInfo.ucHover_cnt < thisModeConf->Label.ucHoverOutCheckFrm)
							{
								if(thisInfo->tPenInfo.ucHover_cnt == 0)EdgeStrength = EdgeStrength * thisModeConf->Label.ucHoverOutCheckFrm;
								else EdgeStrength = EdgeStrength/(thisInfo->tPenInfo.ucHover_cnt) * thisModeConf->Label.ucHoverOutCheckFrm;
							}
							_d2 += max_sum - EdgeStrength;
							
							_d1 = 0;
							if(EdgeStrength > 0)
								_d1 = (max_sum/EdgeStrength);
							
							if(tTmpParaEdgeSetVal.max_sum_hover_div + _d1 > 0)
								_d2=_d2/(tTmpParaEdgeSetVal.max_sum_hover_div + _d1);
						}
						else if(max_sum != 0) 
						{
							if(search_c == -1)
							{
#if (PEN_Edge_UsePerMaxSum == YES)
								if(tTmpParaEdgeSetVal.ucUsePerMaxSum)
									_d2 += (ulExtStrengthAvg * max_sum)/100 - thisInfo->tLabel_local_dsp.ulExtStrength;	
								else
#endif
									_d2 += max_sum - thisInfo->tLabel_local_dsp.ulExtStrength;	
							}								
							else
							{
								_d2 += max_sum - HAL_READ_LOCAL_DELTA_IMAGE(search_r1, c) * 8;
							}
						}
						
#ifdef TILT_ON
						if(thisInfo->tTiltInfo.sRingTipStrengthRatio > tTmpParaEdgeSetVal.th0 && OP_Mode == LOCAL_MODE && mul1_r != 0)
						{
							_d2 += (thisInfo->tTiltInfo.sRingTipStrengthRatio*mul1_r)>>sr1_r;
						}
#endif
						
						if(_d2<0)_d2 = 0;
						thisInfo->tLabel_local_dsp.tCoord.x      +=	(float)thisInfo->tLabel_local_dsp.tCoord.x / thisInfo->tLabel_local_dsp.ulExtStrength *_d2;
						thisInfo->tLabel_local_dsp.tCoord.y      += apply_r * _d2;
						thisInfo->tLabel_local_dsp.ulExtStrength += _d2;
					}
				}
			}
		}
		
		if(search_c != -1)		//left,right edge
		{
			thisInfo->tTiltInfo.sRingTipStrengthRatio = (thisInfo->tTiltInfo.sRing_ExtStrength<<2)/thisInfo->tLabel_local_dsp.ulExtStrength;
			EdgeStrength = 0;
			for(r = thisInfo->tLabel_local_dsp.tValidRect.rs; r <= thisInfo->tLabel_local_dsp.tValidRect.re; r++)
			{
				if(HAL_READ_LOCAL_LABEL_IMAGE(r, search_c) != 0)
				{
					EdgeStrength += HAL_READ_LOCAL_DELTA_IMAGE(r, search_c);
					EdgeStrength += HAL_READ_LOCAL_DELTA_IMAGE(r, search_c1);
				}
			}
#if (PEN_Edge_UsePerMaxSum == YES)			
			if(tTmpParaEdgeSetVal.ucUsePerMaxSum && mul != 0)mul -= ulExtStrengthAvg/tTmpParaEdgeSetVal.ucUsePerMaxSum;
#endif
			for(r = thisInfo->tLabel_local_dsp.tValidRect.rs; r <= thisInfo->tLabel_local_dsp.tValidRect.re; r++)
			{
				if(HAL_READ_LOCAL_LABEL_IMAGE(r, search_c) != 0)
				{
					_d = HAL_READ_LOCAL_DELTA_IMAGE(r, search_c);
					_d1 = HAL_READ_LOCAL_DELTA_IMAGE(r, search_c1);
				
					_d2 = 0;
					if(OP_Mode == LOCAL_MODE && mul != 0)
					{						
						_d2 = _d - ((_d1 + ((_d*mul)>>sr)));
						
						if(_d2<0)_d2 = 0;
						thisInfo->tLabel_local_dsp.tCoord.x      += apply_c * _d2;
						thisInfo->tLabel_local_dsp.tCoord.y      += r * _d2;
						thisInfo->tLabel_local_dsp.ulExtStrength += _d2;				
					}
					
					if(r == thisInfo->tLabel_local_dsp.tValidMaxPos.r)
					{				
						if(OP_Mode == LOCAL_HOVER_MODE && max_sum_LR != 0)
						{
							if(thisInfo->tPenInfo.ucHover_cnt < thisModeConf->Label.ucHoverOutCheckFrm)
							{
								if(thisInfo->tPenInfo.ucHover_cnt == 0)EdgeStrength = EdgeStrength * thisModeConf->Label.ucHoverOutCheckFrm;
								else EdgeStrength = EdgeStrength/(thisInfo->tPenInfo.ucHover_cnt) * thisModeConf->Label.ucHoverOutCheckFrm;
							}							
							_d2 += max_sum_LR - EdgeStrength;
							
							_d1 = 0;
							if(EdgeStrength > 0)
								_d1 = (max_sum_LR/EdgeStrength);
							
							if(tTmpParaEdgeSetVal.max_sum_hover_div + _d1 > 0)							
								_d2=_d2/(tTmpParaEdgeSetVal.max_sum_hover_div + _d1);
						}
						else if(max_sum_LR != 0)
						{
							if(search_r == -1)
							{	
#if (PEN_Edge_UsePerMaxSum == YES)
								if(tTmpParaEdgeSetVal.ucUsePerMaxSum)
									_d2 += (ulExtStrengthAvg * max_sum_LR)/100 - thisInfo->tLabel_local_dsp.ulExtStrength;	
								else
#endif									
									_d2 += max_sum_LR - thisInfo->tLabel_local_dsp.ulExtStrength;	
							}
							else
							{
								_d2 += max_sum_LR - HAL_READ_LOCAL_DELTA_IMAGE(r, search_c1) * 8;	
							}
						}
						
#ifdef TILT_ON
						if(thisInfo->tTiltInfo.sRingTipStrengthRatio > tTmpParaEdgeSetVal.th0 && OP_Mode == LOCAL_MODE && mul1 != 0)
						{
							_d2 += (thisInfo->tTiltInfo.sRingTipStrengthRatio*mul1)>>sr1;
						}
#endif
		
						if(_d2<0)_d2 = 0;
						thisInfo->tLabel_local_dsp.tCoord.x      += apply_c * _d2;
						thisInfo->tLabel_local_dsp.tCoord.y      += (float)thisInfo->tLabel_local_dsp.tCoord.y / thisInfo->tLabel_local_dsp.ulExtStrength *_d2;
						thisInfo->tLabel_local_dsp.ulExtStrength += _d2;
					}
				}
			}
		}
	}
}
#endif
#endif /* USED_PEN_MODE_OPERATION  */

void algorithm_label_process(int mode)
{
	algorithm_label_initialise(mode);

//	if( (thisInfo->bTouchExpect && mode == FULL_MODE) | (thisInfo->bTouchExpect && mode == LOCAL_FINGER_MODE) 
//		| (thisInfo->bTouchExpect_local && mode == LOCAL_MODE) | (thisInfo->bTouchExpect_local && mode == LOCAL_HOVER_MODE))
	{
		algorithm_label_SplitNMerge_process(mode);
	}
}
