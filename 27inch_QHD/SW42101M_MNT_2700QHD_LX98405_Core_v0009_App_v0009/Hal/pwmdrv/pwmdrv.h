/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : pwmdrv.h
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

#ifndef _PWMDRV_H_
#define _PWMDRV_H_



#if USED_FINGER_ONLY
#include "LGD\parameter_pwm_finger.h"
#else /* USED_FINGER_ONLY */
#include "LGD\parameter_pwm_pen.h"
#endif /* USED_FINGER_ONLY */



#define PWM_FINGER_MODE				(0)
#define PWM_PEN_MODE				(1)
#define PWM_DEFAULT_SET				PWM_FINGER_MODE

#define TSYNC_LHB					(1)

#define INTR_CFG_SINGLE_EDGE 		(0)
#define INTR_CFG_BOTH_EDGE 			(1)
#define INTR_CFG_FALLING_EDGE 		(0)
#define INTR_CFG_RISING_EDGE 		(1)
#define INTR_CFG_DISABLE 			(0)
#define INTR_CFG_ENABLE 			(1)

#define PWM_FINGER 					(0x0)
#define PWM_PEN_POSITON				(0x1)
#define PWM_PEN_DATA 				(0x2)
#define PWM_BEACON      			(0x3)

#define ENA_DSSS					(0x01)
#define ENA_PRE						(0x02)
#define ENA_ACT						(0x04)
#define ENA_PRE_LFD0				(0x08)
#define ENA_PRE_LFD1				(0x10)
#define ENA_ACT_LFD0				(0x20)
#define ENA_ACT_LFD1				(0x40)

#define PWMDRV_DSSS_CODE_0			(0x00)
#define PWMDRV_DSSS_CODE_1			(0x01)
#define PWMDRV_DSSS_CODE_2			(0x02)
#define PWMDRV_DSSS_CODE_3			(0x03)
#define PWMDRV_DSSS_CODE_4			(0x04)
#define PWMDRV_DSSS_CODE_5			(0x05)
#define PWMDRV_DSSS_CODE_6			(0x06)
#define PWMDRV_DSSS_CODE_7			(0x07)
#define PWMDRV_DSSS_CODE_8			(0x08)
#define PWMDRV_DSSS_CODE_9			(0x09)
#define PWMDRV_DSSS_CODE_A			(0x0A)
#define PWMDRV_DSSS_CODE_B			(0x0B)
#define PWMDRV_DSSS_CODE_C			(0x0C)
#define PWMDRV_DSSS_CODE_D			(0x0D)
#define PWMDRV_DSSS_CODE_E			(0x0E)
#define PWMDRV_DSSS_CODE_F			(0x0F)
#define PWMDRV_DSSS_CODE_P			(0x10)
#define PWMDRV_DSSS_CODE_N			(0x18)

#define PWM_PEN_POSITON 			(0x1)
#define PWM_PEN_DATA 				(0x2)
#define PWM_BEACON      			(0x3)

#define Touch_CLK 					(12E+6)								// 12MHz
#define PWM_us(val)					((val == 0) ? 0 : (((Touch_CLK/1E+6)*(val))-3))			// unit us
//#define PWM_KHz(val)				((Touch_CLK/1000)/(val))
#define PWM_Full_PRD_KHz(val)		((val == 0) ? 0 : ((12000 / val)-2))
#define PWM_Half_PRD_KHz(val)		((val == 0) ? 0 : ((6000 / val)-2))

#define us_to_cnt_at_12MHz(val) 	(val*12)
#define ms_to_cnt_at_12MHz(val) 	(val*12*1000)
#define kHz_to_cnt_at_12MHz(val) 	(12000/val)

#define LHB1		1
#define LHB2		2
#define LHB3		3
#define LHB4		4
#define LHB5		5
#define LHB6		6
#define LHB7		7
#define LHB8		8
#define LHB9		9
#define LHB10		10
#define LHB11		11
#define LHB12		12
#define LHB13		13
#define LHB14		14
#define LHB15		15
#define LHB16		16



void PWMDRV_PRE(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t PRE_DLY, uint16_t DSSS_DLY);
void PWMDRV_FG_F_F0_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM);
void PWMDRV_FG_F_F1_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM);
void PWMDRV_FG_F_F2_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM);
void PWMDRV_FG_F_F3_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM);
void PWMDRV_FG_L_F0_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM);
void PWMDRV_PN_P_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM);
void PWMDRV_PN_D_ACT(uint16_t TX_PRD, uint16_t TX_LOW, uint16_t TX_NUM, uint16_t DLY, uint16_t LINE_NUM);
/************************************************************/
extern void PWMDRV_Initialize(void);
extern void PWMDRV_Init(eSENSING_MODE_t eSensingMode);
extern void PWMDRV_GPIO_Init(eSENSING_MODE_t eSensingMode);
extern void PWMDRV_Cmd(FunctionalState NewState);
extern void PWMDRV_ITConfig(FunctionalState NewState);
/************************************************************/
extern void PWMDRV_SectionEnable(eSENSING_MODE_t mode);
extern void PWMDRV_Set_DSSS(void);
extern void PWMDRV_Set_VSWT(void);
extern void PWMDRV_Set_Pulse_Config(eSENSING_MODE_t eSensingMode);
extern void PWMDRV_Set_Mode(eSENSING_MODE_t mode);


#endif /* _PWMDRV_H_ */
