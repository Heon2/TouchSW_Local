/****************************************************************************************************//**
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
extern bool_t module_Start(void);
extern void module_DIag_Start(void);

extern void module_CmuxOff_Start(void);

extern void module_read_full_NI_sample_data(void); // NOTE : warning����

extern void module_Stop(void);
extern void module_Watch_Enable(void);

extern bool_t module_wait_full_sample_done(void);
#if USED_IDLE_MODE_CONTROL
extern bool_t module_wait_NI_sample_done(void);
#endif /* USED_IDLE_MODE_CONTROL */
//extern bool_t module_wait_lpwg_sample_done(void);
extern ePartialSensing_t module_wait_local_sample_done(void);
#if USED_NOISE_HOPPING_FREQ	
extern bool_t module_Switch_Freq(eSENSING_FREQ_t _Freq);
#endif /* USED_NOISE_HOPPING_FREQ */
//extern void module_SetPCSMode(ePowerConsumptionState_t _ePCSMode, int _iFrameRate);
extern bool_t module_IsChanged_VsyncRate(void);

//extern void module_LocalStart(void);
extern void module_wait_Vsync_signal(eSensingMode_t _mode, int _waitCnt);

extern void hal_set_irq_flag(int _id);
extern void hal_clear_irq_flag(int _id);
extern bool_t hal_get_irq_flag(int _id);

extern void hal_set_overlap_pen(void); // NOTE : warning����
extern void hal_clear_overlap_pen(void); // NOTE : warning����
extern uint8_t hal_get_overlap_pen(void); // NOTE : warning����

extern void SensingBufferInit(void);

extern void hal_set_LocalType_flag(ePartialSensing_t _id);
extern void hal_clear_LocalType_flag(void);
extern ePartialSensing_t hal_get_LocalType_flag(void);

// NOTE : �Ʒ� Function�� �ܺο��� �����ϴ� �Լ���!!
extern void hal_set_SubState_flag(eNormalOperSubState_t _id);
extern void hal_clear_SubState_flag(void);
extern eNormalOperSubState_t hal_get_SubState_flag(void);

extern void hal_PendSVHandlerInitialize(void);



extern ePartialSensing_t module_read_local_sample_data(void);

extern bool_t module_Wait_LcdOn(void);
extern bool_t module_Check_LcdOn(bool_t bPullDownGPIO);
extern bool_t module_Init_TPEN(void);
extern bool_t module_Check_TPEN(void);

#ifdef MODE_SMT
extern void module_Init_LcdOn(void);
extern void module_Tsync1_SignalBypass(void);
extern void module_Smt_Mode_Enter(void);
#endif /* MODE_SMT */

extern bool_t module_Init_Signal(void);
extern bool_t module_Skip_Event(void);
extern void module_start_delay(void);
extern void module_Protocol_Init(void);
extern void module_HW_Init(void);
extern bool_t module_Defense_Recovery(void);

#endif /* _MODULE_H_ */
