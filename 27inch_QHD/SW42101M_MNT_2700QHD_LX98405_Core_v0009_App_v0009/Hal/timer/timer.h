
/****************************************************************************************************//**
 * @file     timer.h
 *
 * @brief    CMSIS Cortex-M3 Core Peripheral Access Layer Header File for
 *           default MTLP Device Series
 *
 * @version  Vrev.B
 * @date     19. April 2013
 *
 * @note     
 *           
 *           
 * @par      ARM Limited (ARM) is supplying this software for use with Cortex-M
 *           processor based microcontroller, but can be equally used for other
 *           suitable processor architectures. This file can be freely distributed.
 *           Modifications to this file shall be clearly marked.
 *           
 *           THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *           OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *           MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *           ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *           CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. 
 *
 *******************************************************************************************************/


/* ================================================================================ */
/* ================                     TIMER                      ================ */
/* ================================================================================ */

/**
 * @Brief  Flash Control Register
 */

#ifndef __TIMER_H__
#define __TIMER_H__

#ifdef __cplusplus
 extern "C" {
#endif


extern uint8_t TMA0_cnt;
extern uint8_t TMB0_cnt;
extern uint8_t TMA1_cnt;
extern uint8_t TMB1_cnt;

extern uint8_t mode;
	 
//////////////////////////////

#define	TIM_MAX_CNT_VAL						0xFFFFFFFF



#define	TIMER_CLOCK_MASK					0xFC

#define	TIM_EN_Set                 			0x01
#define	TIM_EN_Reset            		  	0xFE

#define	TIM_Mode_Run                 		0x00
#define	TIM_Mode_Count                 		0x01

#define	TIM_INT_Mask					    0x04
#define	TIM_INT_Not_Mask			        0xFB
//#define	TIM_PWM_Enable				        ((uint8_t)0x02)
//#define	TIM_PWM_Disable				        ((uint8_t)0xFD)

//#define	TIM_CAPTURE_Enable			        ((uint8_t)0x01)
//#define	TIM_CAPTURE_Disable			        ((uint8_t)0xFE)

//#define	TIM_INT_Set					        ((uint8_t)0x02)
//#define	TIM_INT_Reset				        ((uint8_t)0xFD)


//#define	TIM_MODE_FreeRunning		        ((uint8_t)0x00)
//#define	TIM_MODE_Count		    	      	((uint8_t)0x10)

#define	TIM_INT_Mask_DISABLE    	      	0x00
#define	TIM_INT_Mask_EN		    	      	0x01

#define OBSERVE_TIM_Init(ch)				HAL_Observe_Timer_Init(ch)
#define OBSERVE_TIM_CLR(ch)                HAL_Observe_Timer_Clear(ch)
#define OBSERVE_TIM_START(ch)                HAL_Observe_Timer_Start(ch)
#define OBSERVE_TIM_END(ch)              HAL_Observe_Timer_Disable(ch)



typedef enum
{
	TIM_Channel_0 = 0x00,
	TIM_Channel_1 = 0x01,
	TIM_Channel_2 = 0x02,
	TIM_Channel_3 = 0x03,
	TIM_Channel_4 = 0x04,
	TIM_Channel_5 = 0x05,
	TIM_Channel_6 = 0x06,
	TIM_Channel_7 = 0x07
}TIM_Channel;

typedef struct
{
	uint8_t TIM_Mode;   			
	uint8_t TIM_Int_Mask;
	TIM_Channel TIM_Channel;
	uint32_t TIM_Count;
} TIM_TimeBaseInitTypeDef;       


//////////////////////////////	 
extern void TIM_DeInit(TIM_Channel TIMx_Chanel);
void TIM_TimeBaseInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
extern void TIM_Cmd(TIM_Channel TIMx_Chanel, FunctionalState NewState);
extern void TIM_ITConfig(TIM_Channel TIMx_Chanel, FunctionalState NewState);
extern void TIM_SetCounter(TIM_Channel TIMx_Chanel, uint32_t Counter);
extern void TIM_CtrlCaptureInput(FunctionalState NewState) ;
extern void TIM_GetCounter(TIM_Channel TIMx_Chanel);
extern void TIM_GetITStatus(TIM_Channel TIMx_Chanel);


extern uint32_t TIM_EOIStatus(void);
extern void HAL_Timer_Init(void);
extern void HAL_Timer_Clear(void);
extern void HAL_Timer_Start(void);
extern void HAL_Timer_Get_Counter(void);
extern void HAL_Observe_Timer_Init(TIM_Channel TIMx_Chanel);
extern void HAL_Observe_Timer_Clear(TIM_Channel TIMx_Chanel);
extern uint32_t HAL_Observe_Timer_Disable(TIM_Channel TIMx_Chanel);
extern void HAL_Observe_Timer_Start(TIM_Channel TIMx_Chanel);

extern void HAL_Timer_Enable(TIM_Channel TIM_Channel_Idx, FunctionalState En);
extern void HAL_Timer_Set_Count_us(TIM_Channel TIM_Channel_Idx, uint32_t Count);

#ifdef __cplusplus
}
#endif
#endif





