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


#define UNIQUE_VID 									(0x424F) // BOE(BO)

#define SWIP_QUEUE_MODE 				(2)
#define SWIP_QUEUE_SIZE 				(7)
#define SHORT_NUM 						(10)


/* Define for Model Customer Dependency */
#define MODEL_DEF_FHD_92503B_HAIER					(MODULE_DEF_B_1 | 1) /* FHD Haier */
#define MODEL_DEF_FHD_92503B_HAIER_CG				(MODULE_DEF_B_1 | 2) /* FHD Haier w/CG */
#define MODEL_DEF_FHD_97500_MNT_S3					(MODULE_DEF_B_1 | 3) /* FHD HP */
//#define MODEL_DEF_FHD_92503B_HAIER_CG_MPP			(MODULE_DEF_B_1 | 4) /* FHD Haier w/CG */
#define MODEL_DEF_FHD_92511_HAIER_WGP				(MODULE_DEF_B_1 | 5) /* FHD Haier wo/CG */
//#define MODEL_DEF_SQHD_92509_HUANAN_WGP				(MODULE_DEF_B_1 | 6) /* SQHD Huanan */
//#define MODEL_DEF_SQHD_92509_HUANAN_MPP				(MODULE_DEF_B_1 | 7) /* SQHD Huanan */
#define MODEL_DEF_SQHD_92509_HUANAN_SPLIT_MPP		(MODULE_DEF_B_1 | 8) /* SQHD Huanan */
#define MODEL_DEF_FHD_92513_LENOVO					(MODULE_DEF_B_1 | 9) /* FHD Lenovo 16" */
#define MODEL_DEF_FHD_92513_LENOVO_NON_PRIVACY		(MODULE_DEF_B_1 | 10) /* FHD Lenovo 16" */

#define CUSTOMER   									(MODEL_DEF_SQHD_92509_HUANAN_SPLIT_MPP)

#if (CUSTOMER == MODEL_DEF_FHD_92503B_HAIER)
	#include "customer/FHD_92503B_haier/information.h"
	#include "customer/FHD_92503B_haier/param_configset_algorithm_common.h"
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			#include "customer/FHD_92503B_haier/param_configset_algorithm_mode_wgp.h"
		#endif
		#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
			#include "customer/FHD_92503B_haier/param_configset_algorithm_mode_mpp.h"
		#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) */
	#include "customer/FHD_92503B_haier/param_configset_mspi.h"
	#include "customer/FHD_92503B_haier/param_configset_pwmdrv.h"
	#include "customer/FHD_92503B_haier/param_configset_roic.h"
	#include "customer/FHD_92503B_haier/remap_table.h"
	#include "customer/FHD_92503B_haier/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92503B_HAIER_CG)
	#include "customer/FHD_92503B_haier_CG/information.h"
	#include "customer/FHD_92503B_haier_CG/param_configset_algorithm_common.h"
	#include "customer/FHD_92503B_haier_CG/param_configset_algorithm_mode_wgp.h"
	#include "customer/FHD_92503B_haier_CG/param_configset_mspi.h"
	#include "customer/FHD_92503B_haier_CG/param_configset_pwmdrv.h"
	#include "customer/FHD_92503B_haier_CG/param_configset_roic.h"
	#include "customer/FHD_92503B_haier_CG/remap_table.h"
	#include "customer/FHD_92503B_haier_CG/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92503B_HAIER_CG_MPP)
	#include "customer/FHD_92503B_haier_CG_MPP/information.h"
	#include "customer/FHD_92503B_haier_CG_MPP/param_configset_algorithm_common.h"
	#include "customer/FHD_92503B_haier_CG_MPP/param_configset_algorithm_mode_mpp.h"
	#include "customer/FHD_92503B_haier_CG_MPP/param_configset_mspi.h"
	#include "customer/FHD_92503B_haier_CG_MPP/param_configset_pwmdrv.h"
	#include "customer/FHD_92503B_haier_CG_MPP/param_configset_roic.h"
	#include "customer/FHD_92503B_haier_CG_MPP/remap_table.h"
	#include "customer/FHD_92503B_haier_CG_MPP/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_97500_MNT_S3)
	#include "customer/FHD_97500_MNT_S3/information.h"
	#include "customer/FHD_97500_MNT_S3/param_configset_algorithm_common.h"
	#include "customer/FHD_97500_MNT_S3/param_configset_algorithm_mode_wgp.h"
	#include "customer/FHD_97500_MNT_S3/param_configset_mspi.h"
	#include "customer/FHD_97500_MNT_S3/param_configset_pwmdrv.h"
	#include "customer/FHD_97500_MNT_S3/param_configset_roic.h"
	#include "customer/FHD_97500_MNT_S3/remap_table.h"
	#include "customer/FHD_97500_MNT_S3/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92511_HAIER_WGP)
#undef UNIQUE_VID
#define UNIQUE_VID 									(0x29BD)
	#include "customer/FHD_92511_haier_WGP/information.h"
	#include "customer/FHD_92511_haier_WGP/param_configset_algorithm_common.h"
	#include "customer/FHD_92511_haier_WGP/param_configset_algorithm_mode_wgp.h"
	#include "customer/FHD_92511_haier_WGP/param_configset_mspi.h"
	#include "customer/FHD_92511_haier_WGP/param_configset_pwmdrv.h"
	#include "customer/FHD_92511_haier_WGP/param_configset_roic.h"
	#include "customer/FHD_92511_haier_WGP/remap_table.h"
	#include "customer/FHD_92511_haier_WGP/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_WGP)
#undef UNIQUE_VID
#define UNIQUE_VID 									(0x29BD)
	#include "customer/SQHD_92509_Huanan_13_WGP/information.h"
	#include "customer/SQHD_92509_Huanan_13_WGP/param_configset_algorithm_common.h"
	#include "customer/SQHD_92509_Huanan_13_WGP/param_configset_algorithm_mode_wgp.h"
	#include "customer/SQHD_92509_Huanan_13_WGP/param_configset_mspi_wgp.h"
	#include "customer/SQHD_92509_Huanan_13_WGP/param_configset_pwmdrv_wgp.h"
	#include "customer/SQHD_92509_Huanan_13_WGP/param_configset_roic_wgp.h"
	#include "customer/SQHD_92509_Huanan_13_WGP/remap_table.h"
	#include "customer/SQHD_92509_Huanan_13_WGP/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_MPP)
#undef UNIQUE_VID
#define UNIQUE_VID 									(0x29BD)
	#include "customer/SQHD_92509_Huanan_13_MPP/information.h"
	#include "customer/SQHD_92509_Huanan_13_MPP/param_configset_algorithm_common.h"
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/SQHD_92509_Huanan_13_MPP/param_configset_algorithm_mode_wgp.h"
		#include "customer/SQHD_92509_Huanan_13_MPP/param_configset_mspi_wgp.h"
		#include "customer/SQHD_92509_Huanan_13_MPP/param_configset_pwmdrv_wgp.h"
		#include "customer/SQHD_92509_Huanan_13_MPP/param_configset_roic_wgp.h"
	#endif
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/SQHD_92509_Huanan_13_MPP/param_configset_algorithm_mode_mpp.h"
		#include "customer/SQHD_92509_Huanan_13_MPP/param_configset_mspi_mpp.h"
		#include "customer/SQHD_92509_Huanan_13_MPP/param_configset_pwmdrv_mpp.h"
		#include "customer/SQHD_92509_Huanan_13_MPP/param_configset_roic_mpp.h"
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) */
	#include "customer/SQHD_92509_Huanan_13_MPP/remap_table.h"
	#include "customer/SQHD_92509_Huanan_13_MPP/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_SQHD_92509_HUANAN_SPLIT_MPP)
#undef UNIQUE_VID
#define UNIQUE_VID 									(0x29BD)
	#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/information.h"
	#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/param_configset_algorithm_common.h"
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/param_configset_algorithm_mode_wgp.h"
		#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/param_configset_mspi_wgp.h"
		#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/param_configset_pwmdrv_wgp.h"
		#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/param_configset_roic_wgp.h"
	#endif
	#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
		#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/param_configset_algorithm_mode_mpp.h"
		#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/param_configset_mspi_mpp.h"
		#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/param_configset_pwmdrv_mpp.h"
		#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/param_configset_roic_mpp.h"
	#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN) */
	#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/remap_table.h"
	#include "customer/SQHD_92509_Huanan_13_SPLIT_MPP/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92513_LENOVO)
#undef UNIQUE_VID
#define UNIQUE_VID 									(0x29BD)
	#include "customer/FHD_92513_16_Lenovo/information.h"
	#include "customer/FHD_92513_16_Lenovo/param_configset_algorithm_common.h"
	#include "customer/FHD_92513_16_Lenovo/param_configset_algorithm_mode_wgp.h"
	#include "customer/FHD_92513_16_Lenovo/param_configset_mspi.h"
	#include "customer/FHD_92513_16_Lenovo/param_configset_pwmdrv.h"
	#include "customer/FHD_92513_16_Lenovo/param_configset_roic.h"
	#include "customer/FHD_92513_16_Lenovo/remap_table.h"
	#include "customer/FHD_92513_16_Lenovo/gpio_define.h"
#elif (CUSTOMER == MODEL_DEF_FHD_92513_LENOVO_NON_PRIVACY)
#undef UNIQUE_VID
#define UNIQUE_VID 									(0x29BD)
	#include "customer/FHD_92513_16_Lenovo_NonPrivacy/information.h"
	#include "customer/FHD_92513_16_Lenovo_NonPrivacy/param_configset_algorithm_common.h"
	#include "customer/FHD_92513_16_Lenovo_NonPrivacy/param_configset_algorithm_mode_wgp.h"
	#include "customer/FHD_92513_16_Lenovo_NonPrivacy/param_configset_mspi.h"
	#include "customer/FHD_92513_16_Lenovo_NonPrivacy/param_configset_pwmdrv.h"
	#include "customer/FHD_92513_16_Lenovo_NonPrivacy/param_configset_roic.h"
	#include "customer/FHD_92513_16_Lenovo_NonPrivacy/remap_table.h"
	#include "customer/FHD_92513_16_Lenovo_NonPrivacy/gpio_define.h"
#endif /* (CUSTOMER == MODEL_DEF_DEFAULT) */

#define VSYNC_HIGH             			(IS_GPIO_PIN(_GPIO_VSYNC))
#define TSYNC_HIGH             			(IS_GPIO_PIN(_GPIO_TSYNC_IN))


#endif /* _ENV_MODEL_H_ */
