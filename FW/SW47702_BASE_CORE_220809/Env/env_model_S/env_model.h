/******************************************************************************************************
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


#define SWIP_QUEUE_MODE 				(2)
#define SWIP_QUEUE_SIZE 				(7)
#define SHORT_NUM 						(10)


/* Define for Model Customer Dependency */
#define MODEL_DEF_UHD_DEFAULT_FLIP							(MODULE_DEF_S_1 | 4)
#define MODEL_DEF_FHD_92504_FUJITSU_Finger					(MODULE_DEF_S_1 | 5)
#define MODEL_DEF_FHD_92504_FUJITSU_Pen						(MODULE_DEF_S_1 | 6)
#define MODEL_DEF_UHD_DEFAULT_FLIP_86KHz					(MODULE_DEF_S_1 | 7)
#define MODEL_DEF_FHD_92504_Beatrice_Flip_Pen				(MODULE_DEF_S_1 | 8)
#define MODEL_DEF_UHD_98502_WGP_Pen							(MODULE_DEF_S_1 | 11)
#define MODEL_DEF_UHD_92510_Souryu_Beatrice_Finger			(MODULE_DEF_S_1 | 12)
#define MODEL_DEF_FHD_92504_Sony_Oliver_WGP_Pen				(MODULE_DEF_S_1 | 13)
#define MODEL_DEF_UHD_92510_Souryu_Beatrice_Pen				(MODULE_DEF_S_1 | 14)
#define MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_Finger			(MODULE_DEF_S_1 | 15)
#define MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_WGP_Pen		(MODULE_DEF_S_1 | 16)
#define MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_Finger		(MODULE_DEF_S_1 | 17)
#define MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_WGP_Pen		(MODULE_DEF_S_1 | 18)
#define MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_FLIP_Finger	(MODULE_DEF_S_1 | 19)
#define MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_MPP_Pen		(MODULE_DEF_S_1 | 20)


#define CUSTOMER   						(MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_Finger)

#if ((CUSTOMER == MODEL_DEF_FHD_92504_Sony_Oliver_WGP_Pen) || \
		(CUSTOMER == MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_Finger) || \
		(CUSTOMER == MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_WGP_Pen) || \
		(CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_Finger))
	#define UNIQUE_VID 									(0x29BD) // SiW
#else
	#define UNIQUE_VID 									(0x5348) // Sharp(SH)
#endif /* (CUSTOMER == MODEL_DEF_FHD_92504_Sony_Oliver_WGP_Pen) */


#if (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP)
	#include "customer/UHD_DEFAULT_FLIP/information.h"
	#include "customer/UHD_DEFAULT_FLIP/param_configset_algorithm_common.h"
	#include "customer/UHD_DEFAULT_FLIP/param_configset_algorithm_mode_wgp.h"
	#include "customer/UHD_DEFAULT_FLIP/param_configset_mspi.h"
	#include "customer/UHD_DEFAULT_FLIP/param_configset_pwmdrv.h"
	#include "customer/UHD_DEFAULT_FLIP/param_configset_roic.h"
	#include "customer/UHD_DEFAULT_FLIP/remap_table.h"
	#include "customer/UHD_DEFAULT_FLIP/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_UHD_DEFAULT_FLIP_86KHz)
	#include "customer/UHD_DEFAULT_FLIP_86khz/information.h"
	#include "customer/UHD_DEFAULT_FLIP_86khz/param_configset_algorithm_common.h"
	#include "customer/UHD_DEFAULT_FLIP_86khz/param_configset_algorithm_mode_wgp.h"
	#include "customer/UHD_DEFAULT_FLIP_86khz/param_configset_mspi.h"
	#include "customer/UHD_DEFAULT_FLIP_86khz/param_configset_pwmdrv.h"
	#include "customer/UHD_DEFAULT_FLIP_86khz/param_configset_roic.h"
	#include "customer/UHD_DEFAULT_FLIP_86khz/remap_table.h"
	#include "customer/UHD_DEFAULT_FLIP_86khz/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92504_FUJITSU_Finger)
	#include "customer/FHD_92503S_Fujitsu_Finger/information.h"
	#include "customer/FHD_92503S_Fujitsu_Finger/param_configset_algorithm_common.h"
	#include "customer/FHD_92503S_Fujitsu_Finger/param_configset_algorithm_mode_wgp.h"
	#include "customer/FHD_92503S_Fujitsu_Finger/param_configset_mspi.h"
	#include "customer/FHD_92503S_Fujitsu_Finger/param_configset_pwmdrv.h"
	#include "customer/FHD_92503S_Fujitsu_Finger/param_configset_roic.h"
	#include "customer/FHD_92503S_Fujitsu_Finger/remap_table.h"
	#include "customer/FHD_92503S_Fujitsu_Finger/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92504_FUJITSU_Pen)
	#include "customer/FHD_92503S_Fujitsu_Pen/information.h"
	#include "customer/FHD_92503S_Fujitsu_Pen/param_configset_algorithm_common.h"
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/FHD_92503S_Fujitsu_Pen/param_configset_algorithm_mode_wgp.h"
	#endif
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/FHD_92503S_Fujitsu_Pen/param_configset_algorithm_mode_mpp.h"
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) */
	#include "customer/FHD_92503S_Fujitsu_Pen/param_configset_mspi.h"
	#include "customer/FHD_92503S_Fujitsu_Pen/param_configset_pwmdrv.h"
	#include "customer/FHD_92503S_Fujitsu_Pen/param_configset_roic.h"
	#include "customer/FHD_92503S_Fujitsu_Pen/remap_table.h"
	#include "customer/FHD_92503S_Fujitsu_Pen/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92504_Beatrice_Flip_Pen)
	#include "customer/FHD_92503S_Beatrice_Flip_Pen/information.h"
	#include "customer/FHD_92503S_Beatrice_Flip_Pen/param_configset_algorithm_common.h"
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/FHD_92503S_Beatrice_Flip_Pen/param_configset_algorithm_mode_wgp.h"
	#endif
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/FHD_92503S_Beatrice_Flip_Pen/param_configset_algorithm_mode_mpp.h"
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) */
	#include "customer/FHD_92503S_Beatrice_Flip_Pen/param_configset_mspi.h"
	#include "customer/FHD_92503S_Beatrice_Flip_Pen/param_configset_pwmdrv.h"
	#include "customer/FHD_92503S_Beatrice_Flip_Pen/param_configset_roic.h"
	#include "customer/FHD_92503S_Beatrice_Flip_Pen/remap_table.h"
	#include "customer/FHD_92503S_Beatrice_Flip_Pen/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_UHD_98502_WGP_Pen)
	#include "customer/UHD_SW98502_Pen/information.h"
	#include "customer/UHD_SW98502_Pen/param_configset_algorithm_common.h"
	#include "customer/UHD_SW98502_Pen/param_configset_algorithm_mode_wgp.h"
	#include "customer/UHD_SW98502_Pen/param_configset_mspi.h"
	#include "customer/UHD_SW98502_Pen/param_configset_pwmdrv.h"
	#include "customer/UHD_SW98502_Pen/param_configset_roic.h"
	#include "customer/UHD_SW98502_Pen/remap_table.h"
	#include "customer/UHD_SW98502_Pen/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_UHD_92510_Souryu_Beatrice_Finger)
	#include "customer/FHD_92510_Souryu_Beatrice_Finger/information.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Finger/param_configset_algorithm_common.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Finger/param_configset_algorithm_mode_wgp.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Finger/param_configset_mspi.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Finger/param_configset_pwmdrv.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Finger/param_configset_roic.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Finger/remap_table.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Finger/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92504_Sony_Oliver_WGP_Pen)
	#include "customer/FHD_92503S_Sony_Oliver_WGP_Pen/information.h"
	#include "customer/FHD_92503S_Sony_Oliver_WGP_Pen/param_configset_algorithm_common.h"
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/FHD_92503S_Sony_Oliver_WGP_Pen/param_configset_algorithm_mode_wgp.h"
	#endif
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/FHD_92503S_Sony_Oliver_WGP_Pen/param_configset_algorithm_mode_mpp.h"
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) */
	#include "customer/FHD_92503S_Sony_Oliver_WGP_Pen/param_configset_mspi.h"
	#include "customer/FHD_92503S_Sony_Oliver_WGP_Pen/param_configset_pwmdrv.h"
	#include "customer/FHD_92503S_Sony_Oliver_WGP_Pen/param_configset_roic.h"
	#include "customer/FHD_92503S_Sony_Oliver_WGP_Pen/remap_table.h"
	#include "customer/FHD_92503S_Sony_Oliver_WGP_Pen/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_UHD_92510_Souryu_Beatrice_Pen)
	#include "customer/FHD_92510_Souryu_Beatrice_Pen/information.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Pen/param_configset_algorithm_common.h"
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/FHD_92510_Souryu_Beatrice_Pen/param_configset_algorithm_mode_wgp.h"
	#endif
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/FHD_92510_Souryu_Beatrice_Pen/param_configset_algorithm_mode_mpp.h"
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) */
	#include "customer/FHD_92510_Souryu_Beatrice_Pen/param_configset_mspi.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Pen/param_configset_pwmdrv.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Pen/param_configset_roic.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Pen/remap_table.h"
	#include "customer/FHD_92510_Souryu_Beatrice_Pen/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_Finger)
	#include "customer/FHD_92510_Dell_Wendy_Finger/information.h"
	#include "customer/FHD_92510_Dell_Wendy_Finger/param_configset_algorithm_common.h"
	#include "customer/FHD_92510_Dell_Wendy_Finger/param_configset_algorithm_mode_wgp.h"
	#include "customer/FHD_92510_Dell_Wendy_Finger/param_configset_mspi.h"
	#include "customer/FHD_92510_Dell_Wendy_Finger/param_configset_pwmdrv.h"
	#include "customer/FHD_92510_Dell_Wendy_Finger/param_configset_roic.h"
	#include "customer/FHD_92510_Dell_Wendy_Finger/remap_table.h"
	#include "customer/FHD_92510_Dell_Wendy_Finger/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_PLUSE_92510_Dell_Wendy_WGP_Pen)
	#include "customer/FHD_92510_Dell_Wendy_WGP_Pen/information.h"
	#include "customer/FHD_92510_Dell_Wendy_WGP_Pen/param_configset_algorithm_common.h"
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/FHD_92510_Dell_Wendy_WGP_Pen/param_configset_algorithm_mode_wgp.h"
	#endif
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/FHD_92510_Dell_Wendy_WGP_Pen/param_configset_algorithm_mode_mpp.h"
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) */
	#include "customer/FHD_92510_Dell_Wendy_WGP_Pen/param_configset_mspi.h"
	#include "customer/FHD_92510_Dell_Wendy_WGP_Pen/param_configset_pwmdrv.h"
	#include "customer/FHD_92510_Dell_Wendy_WGP_Pen/param_configset_roic.h"
	#include "customer/FHD_92510_Dell_Wendy_WGP_Pen/remap_table.h"
	#include "customer/FHD_92510_Dell_Wendy_WGP_Pen/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_Finger)
	#include "customer/UHD_92508_Dell_Yolanda_Finger/information.h"
	#include "customer/UHD_92508_Dell_Yolanda_Finger/param_configset_algorithm_common.h"
	#include "customer/UHD_92508_Dell_Yolanda_Finger/param_configset_algorithm_mode_wgp.h"
	#include "customer/UHD_92508_Dell_Yolanda_Finger/param_configset_mspi.h"
	#include "customer/UHD_92508_Dell_Yolanda_Finger/param_configset_pwmdrv.h"
	#include "customer/UHD_92508_Dell_Yolanda_Finger/param_configset_roic.h"
	#include "customer/UHD_92508_Dell_Yolanda_Finger/remap_table.h"
	#include "customer/UHD_92508_Dell_Yolanda_Finger/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_WGP_Pen)
	#include "customer/UHD_92508_Dell_Yolanda_WGP_Pen/information.h"
	#include "customer/UHD_92508_Dell_Yolanda_WGP_Pen/param_configset_algorithm_common.h"
	#include "customer/UHD_92508_Dell_Yolanda_WGP_Pen/param_configset_algorithm_mode_wgp.h"
	#include "customer/UHD_92508_Dell_Yolanda_WGP_Pen/param_configset_mspi.h"
	#include "customer/UHD_92508_Dell_Yolanda_WGP_Pen/param_configset_pwmdrv.h"
	#include "customer/UHD_92508_Dell_Yolanda_WGP_Pen/param_configset_roic.h"
	#include "customer/UHD_92508_Dell_Yolanda_WGP_Pen/remap_table.h"
	#include "customer/UHD_92508_Dell_Yolanda_WGP_Pen/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_FLIP_Finger)
	#include "customer/UHD_92508_Dell_Yolanda_FLIP_Finger/information.h"
	#include "customer/UHD_92508_Dell_Yolanda_FLIP_Finger/param_configset_algorithm_common.h"
	#include "customer/UHD_92508_Dell_Yolanda_FLIP_Finger/param_configset_algorithm_mode_wgp.h"
	#include "customer/UHD_92508_Dell_Yolanda_FLIP_Finger/param_configset_mspi.h"
	#include "customer/UHD_92508_Dell_Yolanda_FLIP_Finger/param_configset_pwmdrv.h"
	#include "customer/UHD_92508_Dell_Yolanda_FLIP_Finger/param_configset_roic.h"
	#include "customer/UHD_92508_Dell_Yolanda_FLIP_Finger/remap_table.h"
	#include "customer/UHD_92508_Dell_Yolanda_FLIP_Finger/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_UHD_PLUSE_92508_Dell_Yolanda_MPP_Pen)
	#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/information.h"
	#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/param_configset_algorithm_common.h"
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/param_configset_algorithm_mode_wgp.h"
		#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/param_configset_mspi_wgp.h"
		#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/param_configset_pwmdrv_wgp.h"
		#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/param_configset_roic_wgp.h"
	#endif
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/param_configset_algorithm_mode_mpp.h"
		#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/param_configset_mspi_mpp.h"
		#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/param_configset_pwmdrv_mpp.h"
		#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/param_configset_roic_mpp.h"
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) */
	#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/remap_table.h"
	#include "customer/UHD_92508_Dell_Yolanda_MPP_Pen/gpio_define.h"
#endif /* (CUSTOMER == MODEL_DEF_DEFAULT) */

#define VSYNC_HIGH             			(IS_GPIO_PIN(_GPIO_VSYNC))
#define TSYNC_HIGH             			(IS_GPIO_PIN(_GPIO_TSYNC_IN))


#endif /* _ENV_MODEL_H_ */
