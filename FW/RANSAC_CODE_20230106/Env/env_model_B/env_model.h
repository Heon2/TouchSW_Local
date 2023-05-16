/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  env_model.h
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

#ifndef _ENV_MODEL_H_
#define _ENV_MODEL_H_


#define UNIQUE_VID 									(0x29BD) // BOE(BO)

#define SWIP_QUEUE_MODE 				(2)
#define SWIP_QUEUE_SIZE 				(7)
#define SHORT_NUM 						(10)


/* Define for Model Customer Dependency */
#define MODEL_DEF_DEFAULT				(1)
#define MODEL_DEF_FHD_92503B			(2) /* EN4 */
#define MODEL_DEF_FHD_92503B_HAIER		(3) /* FHD Haier */
#define MODEL_DEF_FHD_92503B_HAIER_CG	(4) /* FHD Haier w/CG */
#define MODEL_DEF_FHD_97500_MNT_S3		(5) /* FHD HP */

#define CUSTOMER   						(MODEL_DEF_FHD_97500_MNT_S3)

#if (CUSTOMER == MODEL_DEF_DEFAULT)
#include "customer/DEFAULT/information.h"
#include "customer/DEFAULT/param_configset_algorithm_common.h"
#include "customer/DEFAULT/param_configset_algorithm_mode.h"
#include "customer/DEFAULT/param_configset_mspi.h"
#include "customer/DEFAULT/param_configset_pwmdrv.h"
#include "customer/DEFAULT/param_configset_roic.h"
#include "customer/DEFAULT/remap_table.h"
#include "customer/DEFAULT/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92503B)
#include "customer/FHD_92503B/information.h"
#include "customer/FHD_92503B/param_configset_algorithm_common.h"
#include "customer/FHD_92503B/param_configset_algorithm_mode.h"
#include "customer/FHD_92503B/param_configset_mspi.h"
#include "customer/FHD_92503B/param_configset_pwmdrv.h"
#include "customer/FHD_92503B/param_configset_roic.h"
#include "customer/FHD_92503B/remap_table.h"
#include "customer/FHD_92503B/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92503B_HAIER)
#include "customer/FHD_92503B_haier/information.h"
#include "customer/FHD_92503B_haier/param_configset_algorithm_common.h"
#include "customer/FHD_92503B_haier/param_configset_algorithm_mode.h"
#include "customer/FHD_92503B_haier/param_configset_mspi.h"
#include "customer/FHD_92503B_haier/param_configset_pwmdrv.h"
#include "customer/FHD_92503B_haier/param_configset_roic.h"
#include "customer/FHD_92503B_haier/remap_table.h"
#include "customer/FHD_92503B_haier/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92503B_HAIER_CG)
#include "customer/FHD_92503B_haier_CG/information.h"
#include "customer/FHD_92503B_haier_CG/param_configset_algorithm_common.h"
#include "customer/FHD_92503B_haier_CG/param_configset_algorithm_mode.h"
#include "customer/FHD_92503B_haier_CG/param_configset_mspi.h"
#include "customer/FHD_92503B_haier_CG/param_configset_pwmdrv.h"
#include "customer/FHD_92503B_haier_CG/param_configset_roic.h"
#include "customer/FHD_92503B_haier_CG/remap_table.h"
#include "customer/FHD_92503B_haier_CG/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3)
#include "customer/FHD_97500_MNT_S3/information.h"
#include "customer/FHD_97500_MNT_S3/param_configset_algorithm_common.h"
#include "customer/FHD_97500_MNT_S3/param_configset_algorithm_mode.h"
#include "customer/FHD_97500_MNT_S3/param_configset_mspi.h"
#include "customer/FHD_97500_MNT_S3/param_configset_pwmdrv.h"
#include "customer/FHD_97500_MNT_S3/param_configset_roic.h"
#include "customer/FHD_97500_MNT_S3/remap_table.h"
#include "customer/FHD_97500_MNT_S3/gpio_define.h"
#endif /* (CUSTOMER == MODEL_DEF_DEFAULT) */

#define VSYNC_HIGH             			(IS_GPIO_PIN(_GPIO_VSYNC))
#define TSYNC_HIGH             			(IS_GPIO_PIN(_GPIO_TSYNC_IN))


#endif /* _ENV_MODEL_H_ */
