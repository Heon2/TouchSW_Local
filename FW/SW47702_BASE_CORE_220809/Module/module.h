/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : module.h
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

#ifndef _MODULE_H_
#define _MODULE_H_


extern void MODULE_Initialize(void);
extern void module_init_param(void);
extern void module_Protocol_Init(void);
extern void module_HW_Init(void);
extern bool_t module_Start(void);
extern void module_Stop(bool_t bIsVCCOff);
extern void module_Watch_Enable(void);
extern void module_Watch_Disable(void);
extern bool_t module_Init_Signal(void);
#if USED_SMT_OP_MODE
extern bool_t module_Check_SMT_Mode(void);
extern void module_Enter_SMT_Mode(void);
extern void module_Exit_SMT_Mode(void);
extern void module_SignalOut_SMT_Mode(void);
#endif /* USED_SMT_OP_MODE */
#if USED_TP_LCD_ON_OPERATION
extern bool_t module_Check_LcdOn(void);
#endif /* USED_TP_LCD_ON_OPERATION */
extern bool_t module_Init_TPEN(void);
extern bool_t module_Check_TPEN(void);
#if USED_TP_RST_OPERATION
extern void module_Init_TPRST(void);
extern bool_t module_Check_TPRST(void);
#endif /* USED_TP_RST_OPERATION */

#if DEF_TOUCH_SLEEP_CTRL_HOST_GPIO_TEST_TPEN
extern void module_Init_TOUCH_SLEEP(void);
extern bool_t module_Check_TOUCH_SLEEP(void);
#endif /* DEF_TOUCH_SLEEP_CTRL_HOST_GPIO_TEST_TPEN */

#if USED_MNT_S3_MODE_FUNCTION

#if USED_S3_PGAMMA_SW_I2C_CTRL
extern void module_S3_PGAMMA_I2C_SW_Enable(void);
extern void module_S3_PGAMMA_I2C_SW_Disable(void);
#endif /* USED_S3_PGAMMA_SW_I2C_CTRL */
#endif /* USED_MNT_S3_MODE_FUNCTION */

extern bool_t module_Skip_Event(void);
extern void module_start_delay(void);
extern void module_wait_Vsync_signal(eSensingMode_t _mode, int _waitCnt);
#if USED_NOISE_HOPPING_FREQ
extern bool_t module_Switch_Freq(eSENSING_FREQ_t _Freq);
#endif /* USED_NOISE_HOPPING_FREQ */

extern bool_t module_wait_full_sample_done(void);
#if (USED_IDLE_MODE_CONTROL || USED_LOCAL_IDLE_MODE_CONTROL)
extern bool_t module_wait_NI_sample_done(void);
#endif /* (USED_IDLE_MODE_CONTROL || USED_LOCAL_IDLE_MODE_CONTROL) */
#if USED_MNT_S3_MODE_FUNCTION
extern bool_t module_wait_S3_sample_done(void);
#endif /* USED_MNT_S3_MODE_FUNCTION */
extern ePartialSensing_t module_wait_local_sample_done(void);
extern void module_wait_local_sample_last_done(void);

extern void module_read_full_sample_data(void);

#if (USED_IDLE_MODE_CONTROL || USED_LOCAL_IDLE_MODE_CONTROL)
extern void module_read_NI_sample_data(void);
#endif /* (USED_IDLE_MODE_CONTROL || USED_LOCAL_IDLE_MODE_CONTROL) */

#if USED_MNT_S3_MODE_FUNCTION
extern void module_read_S3_sample_data(void);
#endif /* USED_MNT_S3_MODE_FUNCTION */

extern void module_read_local_finger_sample_data(ePartialSensing_t eLocalLHBType);

#if (USED_IDLE_MODE_CONTROL || USED_LOCAL_IDLE_MODE_CONTROL)
extern void module_read_NI_sample_data(void);
#endif /* (USED_IDLE_MODE_CONTROL || USED_LOCAL_IDLE_MODE_CONTROL) */

#if IS_WGPPEN_PROTOCOL_OPERATION || ((IS_MULTI_PROTOCOL_OPERATION || IS_MSPEN_PROTOCOL_OPERATION) && USED_MPP_Pen_Protocol_Process_Change == NO)
extern void module_read_local_penposition_sample_data(ePartialSensing_t eLocalLHBType);
#endif /* IS_WGPPEN_PROTOCOL_OPERATION || ((IS_MULTI_PROTOCOL_OPERATION || IS_MSPEN_PROTOCOL_OPERATION) && USED_MPP_Pen_Protocol_Process_Change == NO) */

#if IS_WGPPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION
extern void module_read_local_pentilt_sample_data(ePartialSensing_t eLocalLHBType);
#endif /* IS_WGPPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION || IS_WGPUHDPEN_PROTOCOL_OPERATION */

#if IS_WGPPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION || (IS_MSPEN_PROTOCOL_OPERATION && USED_MPP_Pen_Protocol_Process_Change == NO)
extern void module_read_local_pendata_sample_data(ePartialSensing_t eLocalLHBType);
#endif /* IS_WGPPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION || (IS_MSPEN_PROTOCOL_OPERATION && USED_MPP_Pen_Protocol_Process_Change == NO) */

#if IS_WGPUHDPEN_PROTOCOL_OPERATION
extern void module_read_local_penposition_pendata_sample_data(ePartialSensing_t eLocalLHBType);
#endif

#if (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) && (USED_MPP_Pen_Protocol_Process_Change == YES)
extern void module_read_local_penposition_pendata_sample_data(ePartialSensing_t eLocalLHBType);
#endif /* (IS_MSPEN_PROTOCOL_OPERATION || IS_MULTI_PROTOCOL_OPERATION) && (USED_MPP_Pen_Protocol_Process_Change == YES) */

#if USED_EVERY_VSYNC_TIMING_DYNAMIC_MATCHING
extern void module_Check_VSync_Matching_Control(void);
#endif /* USED_EVERY_VSYNC_TIMING_DYNAMIC_MATCHING */

/*
 * Below Function : Change location!!
 */
extern void hal_set_irq_flag(int _id);
extern void hal_clear_irq_flag(int _id);
extern bool_t hal_get_irq_flag(int _id);

extern void hal_set_LocalType_flag(ePartialSensing_t _id);
extern void hal_clear_LocalType_flag(void);
extern ePartialSensing_t hal_get_LocalType_flag(void);

extern void hal_set_overlap_pen(void);
extern void hal_clear_overlap_pen(void);
extern uint8_t hal_get_overlap_pen(void);

//extern void hal_set_SubState_flag(eNormalOperSubState_t _id);
//extern void hal_clear_SubState_flag(void);
//extern eNormalOperSubState_t hal_get_SubState_flag(void);

#endif /* _MODULE_H_ */
