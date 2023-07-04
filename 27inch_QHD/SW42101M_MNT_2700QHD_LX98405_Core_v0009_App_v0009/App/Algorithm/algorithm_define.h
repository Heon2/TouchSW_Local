/*
 * algorithm_define.h
 *
 *  Created on: 2015. 5. 11.
 *      Author: parkyj2
 */

#ifndef __ALGORITHM_DEFINE_H__
#define __ALGORITHM_DEFINE_H__

//#define MAX_TOUCH_                      10
//#define MAX_KEY_                        4

#define POSBUF_                         10
#define POSBUF_MARGIN                   6 //30
#define LABEL_MARGIN					40
#define LOOSE_POSBUF_                   (POSBUF_ + POSBUF_MARGIN) //!It must be a even #!
#define LABEL_BOUNDARY_MARKER           (LOOSE_POSBUF_ + 2)
#define LABEL_CONFLICT_MARKER           63

#define NOISE_DETECTION_FRAME_NUM		20


////////////////////////////big finger
#define NON_LABEL       0
#define NON_OVERLAP     1
#define OVERLAP_LABEL   2

#define NON_FINGER      0
#define BIG_FINGER      1
#define NORMAL_FINGER   2

#define oCNT    0
#define oFLAG   1

#define XMIN    0
#define XMAX    1
#define YMIN    2
#define YMAX    3

#define VERIFICATION_FRAME 15
#define BIG_CHECK_FRAME		5

#define SEN_CONT_CNT 10

#define MINRAWDATA_MARGIN 10


#endif /* __ALGORITHM_DEFINE_H__ */
