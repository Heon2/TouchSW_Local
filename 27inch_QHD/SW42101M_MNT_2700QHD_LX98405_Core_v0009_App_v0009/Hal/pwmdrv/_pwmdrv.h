/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _pwmdrv.h
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

#ifndef __PWMDRV_H_
#define __PWMDRV_H_

#include "_pwmdrv_param.h"
/* ================================================================================ */
/* ================                      PWMDRV                    ================ */
/* ================================================================================ */


/**
  * @brief PWMDRV / PWM TX Generation Configuration Register
  */
typedef struct {                             /*!< PWMDRV Structure   */

  union {
    __IO uint32_t  GBL;                      /*!< CFG               */

    struct {
      __IO uint32_t  PWMDRV_ENA         :  1;    /*!<                   */
      __IO uint32_t  VSYNC_EDGE         :  1;    /*!<                   */
      __IO uint32_t  TSYNC_EDGE         :  1;    /*!<                   */
      __IO uint32_t  SEL_EXT_VSYNC      :  1;    /*!<                   */
      __IO uint32_t  SEL_EXT_TSYNC      :  1;    /*!<                   */
      __IO uint32_t  SEL_FR_TSYNC       :  1;    /*!<                   */
      __IO uint32_t  UPDATE_VSYNC       :  1;    /*!<                   */
      __IO uint32_t  UPDATE_TSYNC       :  1;    /*!<                   */
      __IO uint32_t  UPDATE_DBG         :  1;    /*!<                   */
      __IO uint32_t  VSYNC_FREQ_EN      :  1;    /*!<                   */
      __IO uint32_t  TSYNC_FREQ_EN_FG_F :  1;    /*!<                   */
      __IO uint32_t  DSSS_FREQ          :  6;    /*!<                   */
      __IO uint32_t  ENA_PRTX_P0        :  1;    /*!<                   */
      __IO uint32_t  ENA_PRTX_D0        :  1;    /*!<                   */
      __IO uint32_t  ENA_DSSS_P         :  1;    /*!<                   */
      __IO uint32_t  ENA_DSSS_D         :  1;    /*!<                   */
      __IO uint32_t  ENA_PRTX_P1        :  1;    /*!<                   */
      __IO uint32_t  ENA_PRTX_D1        :  1;    /*!<                   */
      __IO uint32_t  ENA_ACTX_PD        :  1;    /*!<                   */
      __IO uint32_t  ENA_ECLK_AUTO      :  1;    /*!<                   */
      __IO uint32_t  VSYNC_NUM          :  6;    /*!<                   */
      __IO uint32_t  VSYNC_BP           :  1;    /*!<                   */
    } GBL_b;                                 /*!< BitSize           */
  };


  union {
    __IO uint32_t  FW_CTRL;                /*!< CFG               */

    struct {
      __IO uint32_t  PEN_MODE     :  1;    /*!<                   */
      __IO uint32_t  VSYNC_IN     :  1;    /*!<                   */
      __IO uint32_t  TSYNC_IN     :  1;    /*!<                   */
    } FW_CTRL_b;                           /*!< BitSize           */
  };


  union {
    __IO uint32_t  IN_CTRL;                 /*!< CFG               */

    struct {
      __IO uint32_t  TSYNC_MNT_ENA      :  1;   /*!<                   */
      __IO uint32_t  TSYNC_MNT_CLR      :  1;   /*!<                   */
      __IO uint32_t  FR_SEL_POINT       :  2;   /*!<                   */
      __IO uint32_t  FR_TSYNC_PRD       :  16;  /*!<                   */
      __IO uint32_t  FR_TSYNC_NUM       :  6;   /*!<                   */
      __IO uint32_t  SYNC_AUTO_CLR      :  1;   /*!<                   */
      __IO uint32_t  SEL_ECLK_AUTO      :  1;   /*!<                   */
      __IO uint32_t  ENA_VSYNC_INIT     :  1;   /*!<                   */
      __IO uint32_t  ENA_TSYNC_INIT     :  1;   /*!<                   */
      __IO uint32_t  TSYNC_FREQ_EN_FG_L :  1;    /*!<                   */
    } IN_CTRL_b;                            /*!< BitSize           */
  };


  union {
    __IO uint32_t  TSYNC_LTD;           /*!< CFG               */

    struct {
      __IO uint32_t  HIGH       :  16;  /*!<                   */
      __IO uint32_t  LOW        :  16;  /*!<                   */
    } TSYNC_LTD_b;                      /*!< BitSize           */
  };


  union {
    __IO uint32_t  FG_0 ;           /*!< CFG               */

    struct {
      __IO uint32_t  LHB_01     :  2;   /*!<                   */
      __IO uint32_t  LHB_02     :  2;   /*!<                   */
      __IO uint32_t  LHB_03     :  2;   /*!<                   */
      __IO uint32_t  LHB_04     :  2;   /*!<                   */
      __IO uint32_t  LHB_05     :  2;   /*!<                   */
      __IO uint32_t  LHB_06     :  2;   /*!<                   */
      __IO uint32_t  LHB_07     :  2;   /*!<                   */
      __IO uint32_t  LHB_08     :  2;   /*!<                   */
      __IO uint32_t  LHB_09     :  2;   /*!<                   */
      __IO uint32_t  LHB_10     :  2;   /*!<                   */
      __IO uint32_t  LHB_11     :  2;   /*!<                   */
      __IO uint32_t  LHB_12     :  2;   /*!<                   */
      __IO uint32_t  LHB_13     :  2;   /*!<                   */
      __IO uint32_t  LHB_14     :  2;   /*!<                   */
      __IO uint32_t  LHB_15     :  2;   /*!<                   */
      __IO uint32_t  LHB_16     :  2;   /*!<                   */
    } FG_0_b;                       /*!< BitSize           */
  };


  union {
    __IO uint32_t  FG_1 ;           /*!< CFG               */

    struct {
      __IO uint32_t  LHB_17     :  2;   /*!<                   */
      __IO uint32_t  LHB_18     :  2;   /*!<                   */
      __IO uint32_t  LHB_19     :  2;   /*!<                   */
      __IO uint32_t  LHB_20     :  2;   /*!<                   */
      __IO uint32_t  LHB_21     :  2;   /*!<                   */
      __IO uint32_t  LHB_22     :  2;   /*!<                   */
      __IO uint32_t  LHB_23     :  2;   /*!<                   */
      __IO uint32_t  LHB_24     :  2;   /*!<                   */
      __IO uint32_t  LHB_25     :  2;   /*!<                   */
      __IO uint32_t  LHB_26     :  2;   /*!<                   */
      __IO uint32_t  LHB_27     :  2;   /*!<                   */
      __IO uint32_t  LHB_28     :  2;   /*!<                   */
      __IO uint32_t  LHB_29     :  2;   /*!<                   */
      __IO uint32_t  LHB_30     :  2;   /*!<                   */
      __IO uint32_t  LHB_31     :  2;   /*!<                   */
      __IO uint32_t  LHB_32     :  2;   /*!<                   */
    } FG_1_b;                       /*!< BitSize           */
  };


  union {
    __IO uint32_t  PN_0 ;           /*!< CFG               */

    struct {
      __IO uint32_t  LHB_01     :  2;   /*!<                   */
      __IO uint32_t  LHB_02     :  2;   /*!<                   */
      __IO uint32_t  LHB_03     :  2;   /*!<                   */
      __IO uint32_t  LHB_04     :  2;   /*!<                   */
      __IO uint32_t  LHB_05     :  2;   /*!<                   */
      __IO uint32_t  LHB_06     :  2;   /*!<                   */
      __IO uint32_t  LHB_07     :  2;   /*!<                   */
      __IO uint32_t  LHB_08     :  2;   /*!<                   */
      __IO uint32_t  LHB_09     :  2;   /*!<                   */
      __IO uint32_t  LHB_10     :  2;   /*!<                   */
      __IO uint32_t  LHB_11     :  2;   /*!<                   */
      __IO uint32_t  LHB_12     :  2;   /*!<                   */
      __IO uint32_t  LHB_13     :  2;   /*!<                   */
      __IO uint32_t  LHB_14     :  2;   /*!<                   */
      __IO uint32_t  LHB_15     :  2;   /*!<                   */
      __IO uint32_t  LHB_16     :  2;   /*!<                   */
    } PN_0_b;                       /*!< BitSize           */
  };


  union {
    __IO uint32_t  PN_1 ;           /*!< CFG               */

    struct {
      __IO uint32_t  LHB_17     :  2;   /*!<                   */
      __IO uint32_t  LHB_18     :  2;   /*!<                   */
      __IO uint32_t  LHB_19     :  2;   /*!<                   */
      __IO uint32_t  LHB_20     :  2;   /*!<                   */
      __IO uint32_t  LHB_21     :  2;   /*!<                   */
      __IO uint32_t  LHB_22     :  2;   /*!<                   */
      __IO uint32_t  LHB_23     :  2;   /*!<                   */
      __IO uint32_t  LHB_24     :  2;   /*!<                   */
      __IO uint32_t  LHB_25     :  2;   /*!<                   */
      __IO uint32_t  LHB_26     :  2;   /*!<                   */
      __IO uint32_t  LHB_27     :  2;   /*!<                   */
      __IO uint32_t  LHB_28     :  2;   /*!<                   */
      __IO uint32_t  LHB_29     :  2;   /*!<                   */
      __IO uint32_t  LHB_30     :  2;   /*!<                   */
      __IO uint32_t  LHB_31     :  2;   /*!<                   */
      __IO uint32_t  LHB_32     :  2;   /*!<                   */
    } PN_1_b;                       /*!< BitSize           */
  };


  union {
    __IO uint32_t  VSYNC_FREQ ;       /*!< CFG               */

    struct {
      __IO uint32_t  F0_TSYNC :  6;   /*!<                   */
      __IO uint32_t  F1_TSYNC :  6;   /*!<                   */
      __IO uint32_t  F2_TSYNC :  6;   /*!<                   */
      __IO uint32_t  F3_TSYNC :  6;   /*!<                   */
    } VSYNC_FREQ_b;                   /*!< BitSize           */
  };


  union {
    __IO uint32_t  VSYNC_F1_ACT_0 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_PRD :  16;    /*!<                   */
      __IO uint32_t  TX_LOW :  16;    /*!<                   */
    } VSYNC_F1_ACT_0_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  VSYNC_F1_ACT_1 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_NUM  :  10;   /*!<                   */
      __IO uint32_t  DLY :  16;   /*!<                   */
    } VSYNC_F1_ACT_1_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  VSYNC_F1_ACT_2 ;   /*!< CFG               */

    struct {
      __IO uint32_t  LINE_NUM :  8;   /*!<                   */
    } VSYNC_F1_ACT_2_b;               /*!< BitSize           */
  };



  union {
    __IO uint32_t  VSYNC_F2_ACT_0 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_PRD :  16;    /*!<                   */
      __IO uint32_t  TX_LOW :  16;    /*!<                   */
    } VSYNC_F2_ACT_0_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  VSYNC_F2_ACT_1 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_NUM  :  10;   /*!<                   */
      __IO uint32_t  DLY :  16;   /*!<                   */
    } VSYNC_F2_ACT_1_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  VSYNC_F2_ACT_2 ;   /*!< CFG               */

    struct {
      __IO uint32_t  LINE_NUM :  8;   /*!<                   */
    } VSYNC_F2_ACT_2_b;               /*!< BitSize           */
  };



  union {
    __IO uint32_t  VSYNC_F3_ACT_0 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_PRD :  16;    /*!<                   */
      __IO uint32_t  TX_LOW :  16;    /*!<                   */
    } VSYNC_F3_ACT_0_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  VSYNC_F3_ACT_1 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_NUM  :  10;   /*!<                   */
      __IO uint32_t  DLY :  16;   /*!<                   */
    } VSYNC_F3_ACT_1_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  VSYNC_F3_ACT_2 ;   /*!< CFG               */

    struct {
      __IO uint32_t  LINE_NUM :  8;   /*!<                   */
    } VSYNC_F3_ACT_2_b;               /*!< BitSize           */
  };



  union {
    __IO uint32_t  PRLG ;           /*!< CFG               */

    struct {
      __IO uint32_t  DLY_0 :  16;   /*!<                   */
      __IO uint32_t  DLY_1 :  16;   /*!<                   */
    } PRLG_b;                       /*!< BitSize           */
  };



  union {
    __IO uint32_t  PRE_0 ;          /*!< CFG               */

    struct {
      __IO uint32_t  TX_PRD :  16;  /*!<                   */
      __IO uint32_t  TX_LOW :  16;  /*!<                   */
    } PRE_0_b;                      /*!< BitSize           */
  };

  union {
    __IO uint32_t  PRE_1 ;          /*!< CFG               */

    struct {
      __IO uint32_t  TX_NUM  :  10; /*!<                   */
      __IO uint32_t  PRE_DLY :  16; /*!<                   */
    } PRE_1_b;                      /*!< BitSize           */
  };

  union {
    __IO uint32_t  PRE_2 ;          /*!< CFG               */

    struct {
      __IO uint32_t  DSSS_DLY :  8; /*!<                   */
    } PRE_2_b;                      /*!< BitSize           */
  };



  union {
    __IO uint32_t  EPLG_0 ;               /*!< CFG               */

    struct {
      __IO uint32_t  DLY_0_BEACON :  16;  /*!<                   */
      __IO uint32_t  DLY_1        :  16;  /*!<                   */
    } EPLG_0_b;                           /*!< BitSize           */
  };

  union {
    __IO uint32_t  EPLG_1 ;               /*!< CFG               */

    struct {
      __IO uint32_t  DLY_0_PING_FG_F  :  16;  /*!<                   */
      __IO uint32_t  DLY_0_PING_FG_L  :  16;  /*!<                   */
    } EPLG_1_b;                           /*!< BitSize           */
  };

  union {
    __IO uint32_t  EPLG_2 ;               /*!< CFG               */

    struct {
      __IO uint32_t  DLY_0_PING_PN_P  :  16;  /*!<                   */
      __IO uint32_t  DLY_0_PING_PN_D  :  16;  /*!<                   */
    } EPLG_2_b;                           /*!< BitSize           */
  };



//union {
//  __IO uint32_t  FG_L_ACT_0 ;   /*!< CFG               */
//
//  struct {
//    __IO uint32_t  TX_PRD :  16;    /*!<                   */
//    __IO uint32_t  TX_LOW :  16;    /*!<                   */
//  } FG_L_ACT_0_b;               /*!< BitSize           */
//};
//
//union {
//  __IO uint32_t  FG_L_ACT_1 ;   /*!< CFG               */
//
//  struct {
//    __IO uint32_t  TX_NUM  :  10;   /*!<                   */
//    __IO uint32_t  DLY     :  16;   /*!<                   */
//  } FG_L_ACT_1_b;               /*!< BitSize           */
//};
//
//union {
//  __IO uint32_t  FG_L_ACT_2 ;   /*!< CFG               */
//
//  struct {
//    __IO uint32_t  LINE_NUM :  8;   /*!<                   */
//  } FG_L_ACT_2_b;               /*!< BitSize           */
//};


union {
  __IO uint32_t  FG_L_F0_ACT_0 ;   /*!< CFG               */

  struct {
    __IO uint32_t  TX_PRD :  16;    /*!<                   */
    __IO uint32_t  TX_LOW :  16;    /*!<                   */
  } FG_L_F0_ACT_0_b;               /*!< BitSize           */
};

union {
  __IO uint32_t  FG_L_F0_ACT_1 ;   /*!< CFG               */

  struct {
    __IO uint32_t  TX_NUM  :  10;   /*!<                   */
    __IO uint32_t  DLY     :  16;   /*!<                   */
  } FG_L_F0_ACT_1_b;               /*!< BitSize           */
};

union {
  __IO uint32_t  FG_L_F0_ACT_2 ;   /*!< CFG               */

  struct {
    __IO uint32_t  LINE_NUM :  8;   /*!<                   */
  } FG_L_F0_ACT_2_b;               /*!< BitSize           */
};


union {
  __IO uint32_t  FG_L_F1_ACT_0 ;   /*!< CFG               */

  struct {
    __IO uint32_t  TX_PRD :  16;    /*!<                   */
    __IO uint32_t  TX_LOW :  16;    /*!<                   */
  } FG_L_F1_ACT_0_b;               /*!< BitSize           */
};

union {
  __IO uint32_t  FG_L_F1_ACT_1 ;   /*!< CFG               */

  struct {
    __IO uint32_t  TX_NUM  :  10;   /*!<                   */
    __IO uint32_t  DLY     :  16;   /*!<                   */
  } FG_L_F1_ACT_1_b;               /*!< BitSize           */
};

union {
  __IO uint32_t  FG_L_F1_ACT_2 ;   /*!< CFG               */

  struct {
    __IO uint32_t  LINE_NUM :  8;   /*!<                   */
  } FG_L_F1_ACT_2_b;               /*!< BitSize           */
};


union {
  __IO uint32_t  FG_L_F2_ACT_0 ;   /*!< CFG               */

  struct {
    __IO uint32_t  TX_PRD :  16;    /*!<                   */
    __IO uint32_t  TX_LOW :  16;    /*!<                   */
  } FG_L_F2_ACT_0_b;               /*!< BitSize           */
};

union {
  __IO uint32_t  FG_L_F2_ACT_1 ;   /*!< CFG               */

  struct {
    __IO uint32_t  TX_NUM  :  10;   /*!<                   */
    __IO uint32_t  DLY     :  16;   /*!<                   */
  } FG_L_F2_ACT_1_b;               /*!< BitSize           */
};

union {
  __IO uint32_t  FG_L_F2_ACT_2 ;   /*!< CFG               */

  struct {
    __IO uint32_t  LINE_NUM :  8;   /*!<                   */
  } FG_L_F2_ACT_2_b;               /*!< BitSize           */
};


union {
  __IO uint32_t  FG_L_F3_ACT_0 ;   /*!< CFG               */

  struct {
    __IO uint32_t  TX_PRD :  16;    /*!<                   */
    __IO uint32_t  TX_LOW :  16;    /*!<                   */
  } FG_L_F3_ACT_0_b;               /*!< BitSize           */
};

union {
  __IO uint32_t  FG_L_F3_ACT_1 ;   /*!< CFG               */

  struct {
    __IO uint32_t  TX_NUM  :  10;   /*!<                   */
    __IO uint32_t  DLY     :  16;   /*!<                   */
  } FG_L_F3_ACT_1_b;               /*!< BitSize           */
};

union {
  __IO uint32_t  FG_L_F3_ACT_2 ;   /*!< CFG               */

  struct {
    __IO uint32_t  LINE_NUM :  8;   /*!<                   */
  } FG_L_F3_ACT_2_b;               /*!< BitSize           */
};



  union {
    __IO uint32_t  PN_P_ACT_0 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_PRD :  16;    /*!<                   */
      __IO uint32_t  TX_LOW :  16;    /*!<                   */
    } PN_P_ACT_0_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  PN_P_ACT_1 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_NUM  :  10;   /*!<                   */
      __IO uint32_t  DLY     :  16;   /*!<                   */
    } PN_P_ACT_1_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  PN_P_ACT_2 ;   /*!< CFG               */

    struct {
      __IO uint32_t  LINE_NUM :  8;   /*!<                   */
    } PN_P_ACT_2_b;               /*!< BitSize           */
  };



  union {
    __IO uint32_t  PN_D_ACT_0 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_PRD :  16;    /*!<                   */
      __IO uint32_t  TX_LOW :  16;    /*!<                   */
    } PN_D_ACT_0_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  PN_D_ACT_1 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_NUM  :  10;   /*!<                   */
      __IO uint32_t  DLY     :  16;   /*!<                   */
    } PN_D_ACT_1_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  PN_D_ACT_2 ;   /*!< CFG               */

    struct {
      __IO uint32_t  LINE_NUM :  8;   /*!<                   */
    } PN_D_ACT_2_b;               /*!< BitSize           */
  };




  union {
    __IO uint32_t  FG_F_F0_ACT_0 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_PRD :  16;    /*!<                   */
      __IO uint32_t  TX_LOW :  16;    /*!<                   */
    } FG_F_F0_ACT_0_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  FG_F_F0_ACT_1 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_NUM  :  10;   /*!<                   */
      __IO uint32_t  DLY     :  16;   /*!<                   */
    } FG_F_F0_ACT_1_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  FG_F_F0_ACT_2 ;   /*!< CFG               */

    struct {
      __IO uint32_t  LINE_NUM :  8;   /*!<                   */
    } FG_F_F0_ACT_2_b;               /*!< BitSize           */
  };



  union {
    __IO uint32_t  FG_F_F1_ACT_0 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_PRD :  16;    /*!<                   */
      __IO uint32_t  TX_LOW :  16;    /*!<                   */
    } FG_F_F1_ACT_0_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  FG_F_F1_ACT_1 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_NUM  :  10;   /*!<                   */
      __IO uint32_t  DLY     :  16;   /*!<                   */
    } FG_F_F1_ACT_1_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  FG_F_F1_ACT_2 ;   /*!< CFG               */

    struct {
      __IO uint32_t  LINE_NUM :  8;   /*!<                   */
    } FG_F_F1_ACT_2_b;               /*!< BitSize           */
  };



  union {
    __IO uint32_t  FG_F_F2_ACT_0 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_PRD :  16;    /*!<                   */
      __IO uint32_t  TX_LOW :  16;    /*!<                   */
    } FG_F_F2_ACT_0_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  FG_F_F2_ACT_1 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_NUM  :  10;   /*!<                   */
      __IO uint32_t  DLY     :  16;   /*!<                   */
    } FG_F_F2_ACT_1_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  FG_F_F2_ACT_2 ;   /*!< CFG               */

    struct {
      __IO uint32_t  LINE_NUM :  8;   /*!<                   */
    } FG_F_F2_ACT_2_b;               /*!< BitSize           */
  };



  union {
    __IO uint32_t  FG_F_F3_ACT_0 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_PRD :  16;    /*!<                   */
      __IO uint32_t  TX_LOW :  16;    /*!<                   */
    } FG_F_F3_ACT_0_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  FG_F_F3_ACT_1 ;   /*!< CFG               */

    struct {
      __IO uint32_t  TX_NUM :  10;   /*!<                   */
      __IO uint32_t  DLY    :  16;   /*!<                   */
    } FG_F_F3_ACT_1_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  FG_F_F3_ACT_2 ;   /*!< CFG               */

    struct {
      __IO uint32_t  LINE_NUM :  8;   /*!<                   */
    } FG_F_F3_ACT_2_b;               /*!< BitSize           */
  };


  union {
    __IO uint32_t  VSWT_SET;          /*!< CFG               */

    struct {
      __IO uint32_t  INT_0  :  4;     /*!<                   */
      __IO uint32_t  INT_1  :  4;     /*!<                   */
      __IO uint32_t  INT_2  :  4;     /*!<                   */
      __IO uint32_t  INT_3  :  4;     /*!<                   */
    } VSWT_SET_b;                     /*!< BitSize           */
  };


  union {
    __IO uint32_t  DSSS_INFO_0  ;           /*!< CFG               */

    struct {
      __IO uint32_t  PING_FG     :  5;     /*!<                   */
      __IO uint32_t  PING_PNPOS  :  5;     /*!<                   */
      __IO uint32_t  PING_PNDAT  :  5;     /*!<                   */
    } DSSS_INFO_0_b;                        /*!< BitSize           */
  };


  union {
    __IO uint32_t  DSSS_INFO_1  ;           /*!< CFG               */

    struct {
      __IO uint32_t  BEACON_D0    :  5;     /*!<                   */
      __IO uint32_t  BEACON_D1    :  5;     /*!<                   */
      __IO uint32_t  BEACON_D2    :  5;     /*!<                   */
      __IO uint32_t  BEACON_D3    :  5;     /*!<                   */
      __IO uint32_t  BEACON_D4    :  5;     /*!<                   */
      __IO uint32_t  BEACON_D5    :  5;     /*!<                   */
    } DSSS_INFO_1_b;                        /*!< BitSize           */
  };


  __IO uint32_t  DSSS_CODE_P_0  ; /*!< CFG               */
  __IO uint32_t  DSSS_CODE_P_1  ; /*!< CFG               */

  __IO uint32_t  DSSS_CODE_0_0  ; /*!< CFG               */
  __IO uint32_t  DSSS_CODE_0_1  ; /*!< CFG               */

  __IO uint32_t  DSSS_CODE_1_0  ; /*!< CFG               */
  __IO uint32_t  DSSS_CODE_1_1  ; /*!< CFG               */

  __IO uint32_t  DSSS_CODE_2_0  ; /*!< CFG               */
  __IO uint32_t  DSSS_CODE_2_1  ; /*!< CFG               */

  __IO uint32_t  DSSS_CODE_3_0  ; /*!< CFG               */
  __IO uint32_t  DSSS_CODE_3_1  ; /*!< CFG               */

  __IO uint32_t  DSSS_CODE_4_0  ; /*!< CFG               */
  __IO uint32_t  DSSS_CODE_4_1  ; /*!< CFG               */

  __IO uint32_t  DSSS_CODE_5_0  ; /*!< CFG               */
  __IO uint32_t  DSSS_CODE_5_1  ; /*!< CFG               */

  __IO uint32_t  DSSS_CODE_6_0  ; /*!< CFG               */
  __IO uint32_t  DSSS_CODE_6_1  ; /*!< CFG               */

  __IO uint32_t  DSSS_CODE_7_0  ; /*!< CFG               */
  __IO uint32_t  DSSS_CODE_7_1  ; /*!< CFG               */


  union {
    __IO uint32_t  ENA_PWM_0 ;     /*!< CFG               */

    struct {
      __IO uint32_t  T_0 :  7;     /*!<                   */
      __IO uint32_t  T_1 :  7;     /*!<                   */
      __IO uint32_t  T_2 :  7;     /*!<                   */
    } ENA_PWM_0_b ;                /*!< BitSize           */
  };


  union {
    __IO uint32_t  ENA_PWM_1 ;     /*!< CFG               */

    struct {
      __IO uint32_t  T_3 :  7;     /*!<                   */
      __IO uint32_t  T_4 :  7;     /*!<                   */
    } ENA_PWM_1_b ;                /*!< BitSize           */
  };


  union {
    __IO uint32_t  INV_PWM_0 ;     /*!< CFG               */

    struct {
      __IO uint32_t  T_0 :  7;     /*!<                   */
      __IO uint32_t  T_1 :  7;     /*!<                   */
      __IO uint32_t  T_2 :  7;     /*!<                   */
    } INV_PWM_0_b ;                /*!< BitSize           */
  };


  union {
    __IO uint32_t  INV_PWM_1 ;     /*!< CFG               */

    struct {
      __IO uint32_t  T_3 :  7;     /*!<                   */
      __IO uint32_t  T_4 :  7;     /*!<                   */
    } INV_PWM_1_b ;                /*!< BitSize           */
  };


  union {
    __IO uint32_t  VSWT_CFG_0 ;           /*!< CFG               */

    struct {
      __IO uint32_t  SEL_VSWT_0     : 4;  /*!<                   */
      __IO uint32_t  SEL_VSWT_1     : 4;  /*!<                   */
      __IO uint32_t  SEL_VSWT_2     : 4;  /*!<                   */
      __IO uint32_t  SEL_VSWT_3     : 4;  /*!<                   */
      __IO uint32_t  SEL_0_pwm_tx   : 3;  /*!<                   */
      __IO uint32_t  SEL_0_pwm_data : 3;  /*!<                   */
      __IO uint32_t  SEL_0_pwm_gate : 3;  /*!<                   */
      __IO uint32_t  SEL_1_pwm_tx   : 2;  /*!<                   */
      __IO uint32_t  SEL_1_pwm_data : 2;  /*!<                   */
      __IO uint32_t  SEL_1_pwm_gate : 2;  /*!<                   */
    } VSWT_CFG_0_b;                       /*!< BitSize           */
  };


  union {
    __IO uint32_t  VSWT_CFG_1 ;               /*!< CFG               */

    struct {
      __IO uint32_t  SEL_TSYNC_INV    : 1;    /*!<                   */
      __IO uint32_t  SEL_TSYNC_OUT    : 2;    /*!<                   */
      __IO uint32_t  DLY_SEL_PWM_PRE  : 3;    /*!<                   */
      __IO uint32_t  DLY_SEL_PWM_ACT  : 3;    /*!<                   */
      __IO uint32_t  DLY_ENA_PWM_TX   : 1;    /*!<                   */
      __IO uint32_t  DLY_ENA_PWM_DATA : 1;    /*!<                   */
      __IO uint32_t  DLY_ENA_PWM_GATE : 1;    /*!<                   */
      __IO uint32_t  DLY_BP_PRE_TX    : 1;    /*!<                   */
      __IO uint32_t  DLY_BP_PRE_DATA  : 1;    /*!<                   */
      __IO uint32_t  DLY_BP_PRE_GATE  : 1;    /*!<                   */
      __IO uint32_t  DLY_BP_PWM_TX    : 1;    /*!<                   */
      __IO uint32_t  DLY_BP_PWM_DATA  : 1;    /*!<                   */
      __IO uint32_t  DLY_BP_PWM_GATE  : 1;    /*!<                   */
      __IO uint32_t  DLY_INV_PWM_TX   : 1;    /*!<                   */
      __IO uint32_t  DLY_INV_PWM_DATA : 1;    /*!<                   */
      __IO uint32_t  DLY_INV_PWM_GATE : 1;    /*!<                   */
    } VSWT_CFG_1_b;                           /*!< BitSize           */
  };



  union {
    __IO uint32_t  DLY_PWM_CFG_0  ;  /*!< CFG               */

    struct {
      __IO uint32_t  TX   :  16;     /*!<                   */
      __IO uint32_t  DATA :  16;     /*!<                   */
    } DLY_PWM_CFG_0_b;               /*!< BitSize           */
  };

  union {
    __IO uint32_t  DLY_PWM_CFG_1  ;  /*!< CFG               */

    struct {
      __IO uint32_t  GATE :  16;     /*!<                   */
    } DLY_PWM_CFG_1_b;               /*!< BitSize           */
  };


  union {
    __IO uint32_t  WFE_CFG_0  ;               /*!< CFG               */

    struct {
      __IO uint32_t  ENA  :  6;    /*!<                   */
      __IO uint32_t  SEL  :  6;    /*!<                   */
      __IO uint32_t  PUL  :  6;    /*!<                   */
      __IO uint32_t  DBG  :  6;    /*!<                   */
      __IO uint32_t  DRV  :  6;    /*!<                   */
    } WFE_CFG_0_b;                          /*!< BitSize           */
  };


  union {
    __IO uint32_t  WFE_CFG_1  ;               /*!< CFG               */

    struct {
      __IO uint32_t  DLY  :  6;    /*!<                   */
      __IO uint32_t  smpl :  8;    /*!<                   */
    } WFE_CFG_1_b;                          /*!< BitSize           */
  };


  union {
    __IO uint32_t  INTR_CFG ;                  /*!< CFG               */

    struct {
      __IO uint32_t  HI_ABOVE_NUM       :  6;    /*!<                   */
      __IO uint32_t  LO_BELOW_NUM       :  6;    /*!<                   */
      __IO uint32_t  FSM_ON_IBE         :  1;    /*!<                   */
      __IO uint32_t  FSM_ON_IEV         :  1;    /*!<                   */
      __IO uint32_t  FSM_ON_IE          :  1;    /*!<                   */
      __IO uint32_t  VSYNC_IN_EXT_IBE   :  1;    /*!<                   */
      __IO uint32_t  VSYNC_IN_EXT_IEV   :  1;    /*!<                   */
      __IO uint32_t  VSYNC_IN_EXT_IE    :  1;    /*!<                   */
      __IO uint32_t  TSYNC_IN_EXT_IBE   :  1;    /*!<                   */
      __IO uint32_t  TSYNC_IN_EXT_IEV   :  1;    /*!<                   */
      __IO uint32_t  TSYNC_IN_EXT_IE    :  1;    /*!<                   */
      __IO uint32_t  TSYNC_OUT_EXT_IBE  :  1;    /*!<                   */
      __IO uint32_t  TSYNC_OUT_EXT_IEV  :  1;    /*!<                   */
      __IO uint32_t  TSYNC_OUT_EXT_IE   :  1;    /*!<                   */
      __IO uint32_t  TSYNC_FR_IBE       :  1;    /*!<                   */
      __IO uint32_t  TSYNC_FR_IEV       :  1;    /*!<                   */
      __IO uint32_t  TSYNC_FR_IE        :  1;    /*!<                   */
      __IO uint32_t  TSYNC_MNT_IBE      :  1;    /*!<                   */
      __IO uint32_t  TSYNC_MNT_IEV      :  1;    /*!<                   */
      __IO uint32_t  TSYNC_MNT_IE       :  1;    /*!<                   */
    } INTR_CFG_b;                              /*!< BitSize           */
  };


  union {
    __IO uint32_t  INTR_CLR ;                /*!< CFG               */

    struct {
      __IO uint32_t  FSM_ON         :  1;    /*!<                   */
      __IO uint32_t  VSYNC_IN_EXT   :  1;    /*!<                   */
      __IO uint32_t  TSYNC_IN_EXT   :  1;    /*!<                   */
      __IO uint32_t  TSYNC_OUT_EXT  :  1;    /*!<                   */
      __IO uint32_t  TSYNC_FR       :  1;    /*!<                   */
      __IO uint32_t  TSYNC_MNT      :  1;    /*!<                   */
    } INTR_CLR_b;                            /*!< BitSize           */
  };


  union {
    __I  uint32_t  INTR_ST ;                    /*!< CFG               */

    struct {
      __I uint32_t  MIS_FSM_ON         :  1;    /*!<                   */
      __I uint32_t  MIS_VSYNC_IN_EXT   :  1;    /*!<                   */
      __I uint32_t  MIS_TSYNC_IN_EXT   :  1;    /*!<                   */
      __I uint32_t  MIS_TSYNC_OUT_EXT  :  1;    /*!<                   */
      __I uint32_t  MIS_TSYNC_FR       :  1;    /*!<                   */
      __I uint32_t  MIS_TSYNC_MNT      :  1;    /*!<                   */
      __I uint32_t  RIS_FSM_ON         :  1;    /*!<                   */
      __I uint32_t  RIS_VSYNC_IN_EXT   :  1;    /*!<                   */
      __I uint32_t  RIS_TSYNC_IN_EXT   :  1;    /*!<                   */
      __I uint32_t  RIS_TSYNC_OUT_EXT  :  1;    /*!<                   */
      __I uint32_t  RIS_TSYNC_FR       :  1;    /*!<                   */
      __I uint32_t  RIS_TSYNC_MNT      :  1;    /*!<                   */
      __I uint32_t  FSM_ON         :  1;    /*!<                   */
      __I uint32_t  VSYNC_IN_EXT   :  1;    /*!<                   */
      __I uint32_t  TSYNC_IN_EXT   :  1;    /*!<                   */
      __I uint32_t  TSYNC_OUT_EXT  :  1;    /*!<                   */
      __I uint32_t  TSYNC_FR       :  1;    /*!<                   */
      __I uint32_t  TSYNC_MNT      :  1;    /*!<                   */
    } INTR_ST_b;                                /*!< BitSize           */
  };

	union {
	  __IO	uint32_t  DSSS_CFG ;

	  struct {
		__IO uint32_t  beacon_en		 :	1;
		__IO uint32_t  ping_en			 :	1;
		__IO uint32_t  dsss_sel 		 :	1;
	  } DSSS_CFG_b;
	};

	__IO  uint32_t	USI_CHIP_LEN ;

	union {
	  __IO	uint32_t  USI_CODE_LEN ;

	  struct {
		__IO uint32_t  beacon			 :	6;
		__IO uint32_t  finger			 :	6;
		__IO uint32_t  penpos			 :	6;
		__IO uint32_t  pendat			 :	6;
	  } USI_CODE_LEN_b;
	};

	__IO  uint32_t	USI_DSSS_CHIP0 ;
	__IO  uint32_t	USI_DSSS_CHIP1 ;
	__IO  uint32_t	USI_BEACON_CODE0 ;
	__IO  uint32_t	USI_BEACON_CODE1 ;


	union {
	  __IO	uint32_t  USI_PING_CODE ;

	  struct {
		__IO uint32_t  ping_finger		 :	8;
		__IO uint32_t  ping_penpos		 :	8;
		__IO uint32_t  ping_pendat		 :	8;
	  } USI_PING_CODE_b;
	};


} PWMDRV_TypeDef;


#endif /* __PWMDRV_H_ */
