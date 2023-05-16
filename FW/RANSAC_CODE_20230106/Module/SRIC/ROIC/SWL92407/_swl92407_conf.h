/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _swl92407_conf.h
 * created on : 5. 1. 2020
 * Author : bjlee
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

#ifndef __SWL92407_CONF_H_
#define __SWL92407_CONF_H_


#if (USED_ROIC_DEF == ROIC_SWL92407)

typedef struct				
{				
	__IO	uint16_t	R0_CFGR_PRODUCT_ID;			/*0x0300, [0]*/ 
	__IO	uint16_t	R1_CFGR_PRODUCT_ID;     	/*0x0400, [0]*/ 
	__IO	uint16_t	R0_CFGR_SNSR_STR;       	/*0x0302, [1]*/ 
	__IO	uint16_t	R1_CFGR_SNSR_STR;       	/*0x0402, [1]*/ 
	__IO	uint16_t	R0_CFGR_MD_GENERAL;     	/*0x0304, [2]*/ 
	__IO	uint16_t	R1_CFGR_MD_GENERAL;     	/*0x0404, [2]*/ 
	__IO	uint16_t	R0_CFGR_AIP_ADC;        	/*0x0306, [3]*/ 
	__IO	uint16_t	R1_CFGR_AIP_ADC;        	/*0x0406, [3]*/ 
	__IO	uint16_t	R0_CFGR_SSU_CTRL;       	/*0x0308, [4]*/ 
	__IO	uint16_t	R1_CFGR_SSU_CTRL;       	/*0x0408, [4]*/ 
	__IO	uint16_t	R0_CFGR_TSYNC_NUM0;     	/*0x030A, [5]*/ 
	__IO	uint16_t	R1_CFGR_TSYNC_NUM0;     	/*0x040A, [5]*/ 
	__IO	uint16_t	R0_CFGR_TSYNC_NUM1;     	/*0x030C, [6]*/ 
	__IO	uint16_t	R1_CFGR_TSYNC_NUM1;     	/*0x040C, [6]*/ 
	__IO	uint16_t	R0_CFGR_TSYNC_DMMY;     	/*0x030E, [7]*/ 
	__IO	uint16_t	R1_CFGR_TSYNC_DMMY;     	/*0x040E, [7]*/ 
	__IO	uint16_t	R0_CFGR_PWM_NUM0;       	/*0x0310, [8]*/ 
	__IO	uint16_t	R1_CFGR_PWM_NUM0;       	/*0x0410, [8]*/ 
	__IO	uint16_t	R0_CFGR_PWM_NUM1;       	/*0x0312, [9]*/ 
	__IO	uint16_t	R1_CFGR_PWM_NUM1;       	/*0x0412, [9]*/ 
	__IO	uint16_t	R0_CFGR_CMUX_NORM;      	/*0x0314, [10]*/
	__IO	uint16_t	R1_CFGR_CMUX_NORM;      	/*0x0414, [10]*/
	__IO	uint16_t	R0_CFGR_CHIP0_LEN;      	/*0x0316, [11]*/
	__IO	uint16_t	R1_CFGR_CHIP0_LEN;      	/*0x0416, [11]*/
	__IO	uint16_t	R0_CFGR_COL_NUM;        	/*0x0318, [12]*/
	__IO	uint16_t	R1_CFGR_COL_NUM;        	/*0x0418, [12]*/
	__IO	uint16_t	R0_CFGR_SHA_STR;        	/*0x033A, [13]*/
	__IO	uint16_t	R1_CFGR_SHA_STR;        	/*0x043A, [13]*/
	__IO	uint16_t	R0_CFGR_DIG_GAIN2;      	/*0x033C, [14]*/
	__IO	uint16_t	R1_CFGR_DIG_GAIN2;      	/*0x043C, [14]*/
	__IO	uint16_t	R0_CFGR_RSTP_WIDTH;     	/*0x033E, [15]*/
	__IO	uint16_t	R1_CFGR_RSTP_WIDTH;     	/*0x043E, [15]*/
	__IO	uint16_t	R0_CFGR_VCR_STR;        	/*0x0340, [16]*/
	__IO	uint16_t	R1_CFGR_VCR_STR;        	/*0x0440, [16]*/
	__IO	uint16_t	R0_CFGR_VCR2_MD;        	/*0x0342, [17]*/
	__IO	uint16_t	R1_CFGR_VCR2_MD;        	/*0x0442, [17]*/
	__IO	uint16_t	R0_CFGR_VCR2_PHTCR;     	/*0x0344, [18]*/
	__IO	uint16_t	R1_CFGR_VCR2_PHTCR;     	/*0x0444, [18]*/
	__IO	uint16_t	R0_CFGR_PHTH0_WIDTH;    	/*0x0346, [19]*/
	__IO	uint16_t	R1_CFGR_PHTH0_WIDTH;    	/*0x0446, [19]*/
	__IO	uint16_t	R0_CFGR_PHTH1_WIDTH;    	/*0x0348, [20]*/
	__IO	uint16_t	R1_CFGR_PHTH1_WIDTH;    	/*0x0448, [20]*/
	__IO	uint16_t	R0_CFGR_TEST_OPT;       	/*0x034A, [21]*/
	__IO	uint16_t	R1_CFGR_TEST_OPT;       	/*0x044A, [21]*/
	__IO	uint16_t	R0_CFGR_SSU_ON;         	/*0x034C, [22]*/
	__IO	uint16_t	R1_CFGR_SSU_ON;         	/*0x044C, [22]*/
	__IO	uint16_t	R0_CFGR_CMUX_NUM;       	/*0x034E, [23]*/
	__IO	uint16_t	R1_CFGR_CMUX_NUM;       	/*0x044E, [23]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_I00;     	/*0x0350, [24]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_I00;     	/*0x0450, [24]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_I04;     	/*0x0352, [25]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_I04;     	/*0x0452, [25]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_I08;     	/*0x0354, [26]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_I08;     	/*0x0454, [26]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_I12;     	/*0x0356, [27]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_I12;     	/*0x0456, [27]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_I14;     	/*0x0358, [28]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_I14;     	/*0x0458, [28]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_E00;     	/*0x035A, [29]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_E00;     	/*0x045A, [29]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_E04;     	/*0x035C, [30]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_E04;     	/*0x045C, [30]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_E08;     	/*0x035E, [31]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_E08;     	/*0x045E, [31]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_E12;     	/*0x0360, [32]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_E12;     	/*0x0460, [32]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_E14;     	/*0x0362, [33]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_E14;     	/*0x0462, [33]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_PEN_I00; 	/*0x0364, [34]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_PEN_I00; 	/*0x0464, [34]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_PEN_I04; 	/*0x0366, [35]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_PEN_I04; 	/*0x0466, [35]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_PEN_I08; 	/*0x0368, [36]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_PEN_I08; 	/*0x0468, [36]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_PEN_I12; 	/*0x036A, [37]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_PEN_I12; 	/*0x046A, [37]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_PEN_I14; 	/*0x036C, [38]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_PEN_I14; 	/*0x046C, [38]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_PEN_E00; 	/*0x036E, [39]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_PEN_E00; 	/*0x046E, [39]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_PEN_E04; 	/*0x0370, [40]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_PEN_E04; 	/*0x0470, [40]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_PEN_E08; 	/*0x0372, [41]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_PEN_E08; 	/*0x0472, [41]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_PEN_E12; 	/*0x0374, [42]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_PEN_E12; 	/*0x0474, [42]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_PEN_E14; 	/*0x0376, [43]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_PEN_E14; 	/*0x0476, [43]*/
	__IO	uint16_t	R0_CFGR_SSU_INT_GC;     	/*0x037A, [44]*/
	__IO	uint16_t	R1_CFGR_SSU_INT_GC;     	/*0x047A, [44]*/
	__IO	uint16_t	R0_CFGR_EDGE_CR_SEL;    	/*0x037C, [45]*/
	__IO	uint16_t	R1_CFGR_EDGE_CR_SEL;    	/*0x047C, [45]*/
	__IO	uint16_t	R0_CFGR_SSU_PRE_GC;     	/*0x037E, [46]*/
	__IO	uint16_t	R1_CFGR_SSU_PRE_GC;     	/*0x047E, [46]*/
	__IO	uint16_t	R0_CFGR_CMUX_REMAP0;    	/*0x0380, [47]*/
	__IO	uint16_t	R1_CFGR_CMUX_REMAP0;    	/*0x0480, [47]*/
	__IO	uint16_t	R0_CFGR_CMUX_REMAP1;    	/*0x0382, [48]*/
	__IO	uint16_t	R1_CFGR_CMUX_REMAP1;    	/*0x0482, [48]*/
	__IO	uint16_t	R0_CFGR_CMUX_REMAP2;    	/*0x0384, [49]*/
	__IO	uint16_t	R1_CFGR_CMUX_REMAP2;    	/*0x0484, [49]*/
	__IO	uint16_t	R0_CFGR_TSYNC_NUM_PEN;  	/*0x0386, [50]*/
	__IO	uint16_t	R1_CFGR_TSYNC_NUM_PEN;  	/*0x0486, [50]*/
	__IO	uint16_t	R0_CFGR_TSYNC_DMMY_PEN; 	/*0x0388, [51]*/
	__IO	uint16_t	R1_CFGR_TSYNC_DMMY_PEN; 	/*0x0488, [51]*/
	__IO	uint16_t	R0_CFGR_CMUX_NUM_PEN;   	/*0x038A, [52]*/
	__IO	uint16_t	R1_CFGR_CMUX_NUM_PEN;   	/*0x048A, [52]*/
	__IO	uint16_t	R0_CFGR_PEN_CTRL;       	/*0x038C, [53]*/
	__IO	uint16_t	R1_CFGR_PEN_CTRL;       	/*0x048C, [53]*/
	__IO	uint16_t	R0_CFGR_HALF_COPY;      	/*0x038E, [54]*/
	__IO	uint16_t	R1_CFGR_HALF_COPY;      	/*0x048E, [54]*/
	__IO	uint16_t	R0_CFGR_PEN0_TSYNC0;    	/*0x0390, [55]*/
	__IO	uint16_t	R1_CFGR_PEN0_TSYNC0;    	/*0x0490, [55]*/
	__IO	uint16_t	R0_CFGR_PEN0_TSYNC1;    	/*0x0392, [56]*/
	__IO	uint16_t	R1_CFGR_PEN0_TSYNC1;    	/*0x0492, [56]*/
	__IO	uint16_t	R0_CFGR_PEN0_TSYNC2;    	/*0x0394, [57]*/
	__IO	uint16_t	R1_CFGR_PEN0_TSYNC2;    	/*0x0494, [57]*/
	__IO	uint16_t	R0_CFGR_PEN_CTRL2;      	/*0x0396, [58]*/
	__IO	uint16_t	R1_CFGR_PEN_CTRL2;      	/*0x0496, [58]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_MN1_IE;  	/*0x0398, [59]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_MN1_IE;  	/*0x0498, [59]*/
	__IO	uint16_t	R0_CFGR_SSU_CR_MN2_IE;  	/*0x039A, [60]*/
	__IO	uint16_t	R1_CFGR_SSU_CR_MN2_IE;  	/*0x049A, [60]*/
	__IO	uint16_t	R0_CFGR_PWM_NUM2;       	/*0x03A0, [61]*/
	__IO	uint16_t	R1_CFGR_PWM_NUM2;       	/*0x04A0, [61]*/
	__IO	uint16_t	R0_CFGR_PWM_NUM3;       	/*0x03A2, [62]*/
	__IO	uint16_t	R1_CFGR_PWM_NUM3;       	/*0x04A2, [62]*/
	__IO	uint16_t	R0_CFGR_PWM_NUM4;       	/*0x03A4, [63]*/
	__IO	uint16_t	R1_CFGR_PWM_NUM4;       	/*0x04A4, [63]*/
	__IO	uint16_t	R0_CFGR_PWM_NUM5;       	/*0x03A6, [64]*/
	__IO	uint16_t	R1_CFGR_PWM_NUM5;       	/*0x04A6, [64]*/
	__IO	uint16_t	R0_CFGR_PWM_NUM_NI;     	/*0x03A8, [65]*/
	__IO	uint16_t	R1_CFGR_PWM_NUM_NI;     	/*0x04A8, [65]*/
	__IO	uint16_t	R0_CFGR_CMUX_NI1;       	/*0x03AA, [66]*/
	__IO	uint16_t	R1_CFGR_CMUX_NI1;       	/*0x04AA, [66]*/
	__IO	uint16_t	R0_CFGR_CMUX_NI2;       	/*0x03AC, [67]*/
	__IO	uint16_t	R1_CFGR_CMUX_NI2;       	/*0x04AC, [67]*/
	__IO	uint16_t	R0_CFGR_CMUX_NI3;       	/*0x03AE, [68]*/
	__IO	uint16_t	R1_CFGR_CMUX_NI3;       	/*0x04AE, [68]*/
	__IO	uint16_t	R0_CFGR_CMUX_NI4;       	/*0x03B0, [69]*/
	__IO	uint16_t	R1_CFGR_CMUX_NI4;       	/*0x04B0, [69]*/
	__IO	uint16_t	R0_CFGR_AFE_DUM;        	/*0x03B2, [70]*/
	__IO	uint16_t	R1_CFGR_AFE_DUM;        	/*0x04B2, [70]*/
	__IO	uint16_t	R0_CFGR_PSVB_PEN_TSYNC; 	/*0x03B4, [71]*/
	__IO	uint16_t	R1_CFGR_PSVB_PEN_TSYNC; 	/*0x04B4, [71]*/
	__IO	uint16_t	R0_CFGR_PSVB_FGR_TSYNC; 	/*0x03B6, [72]*/
	__IO	uint16_t	R1_CFGR_PSVB_FGR_TSYNC; 	/*0x04B6, [72]*/
	__IO	uint16_t	R0_CFGR_PEN_LHB_ABD;    	/*0x03B8, [73]*/
	__IO	uint16_t	R1_CFGR_PEN_LHB_ABD;    	/*0x04B8, [73]*/
	__IO	uint16_t	R0_CFGR_SSU_BCON1;      	/*0x03BA, [74]*/
	__IO	uint16_t	R1_CFGR_SSU_BCON1;      	/*0x04BA, [74]*/
	__IO	uint16_t	R0_CFGR_SSU_BCON2;      	/*0x03BC, [75]*/
	__IO	uint16_t	R1_CFGR_SSU_BCON2;      	/*0x04BC, [75]*/
	__IO	uint16_t	R0_CFGR_SSU_BCON3;      	/*0x03BE, [76]*/
	__IO	uint16_t	R1_CFGR_SSU_BCON3;      	/*0x04BE, [76]*/
	__IO	uint16_t	R0_CFGR_SPIS_CFG;       	/*0x03C0, [77]*/
	__IO	uint16_t	R1_CFGR_SPIS_CFG;       	/*0x04C0, [77]*/
	__IO	uint16_t	R0_CFGR_SSU_BCON4;      	/*0x03C2, [78]*/
	__IO	uint16_t	R1_CFGR_SSU_BCON4;      	/*0x04C2, [78]*/
	__IO	uint16_t	R0_CFGR_ACLK_DIV2;      	/*0x03C4, [79]*/
	__IO	uint16_t	R1_CFGR_ACLK_DIV2;      	/*0x04C4, [79]*/
	__IO	uint16_t	R0_CFGR_ADIV2_TOG_PAT;  	/*0x03C6, [80]*/
	__IO	uint16_t	R1_CFGR_ADIV2_TOG_PAT;  	/*0x04C6, [80]*/
	__IO	uint16_t	R0_CFGR_PSVB_AFE;       	/*0x03C8, [81]*/
	__IO	uint16_t	R1_CFGR_PSVB_AFE;       	/*0x04C8, [81]*/
	__IO	uint16_t	R0_CFGR_AIP_ENA;        	/*0x03CA, [82]*/
	__IO	uint16_t	R1_CFGR_AIP_ENA;        	/*0x04CA, [82]*/
	__IO	uint16_t	R0_CFGR_AIP_ENA2;       	/*0x03CC, [83]*/
	__IO	uint16_t	R1_CFGR_AIP_ENA2;       	/*0x04CC, [83]*/
	__IO	uint16_t	R0_CFGR_PSVB_EV_TSYNC;  	/*0x03CE, [84]*/
	__IO	uint16_t	R1_CFGR_PSVB_EV_TSYNC;  	/*0x04CE, [84]*/
	__IO	uint16_t	R0_CFGR_PSVB_OD_TSYNC;  	/*0x03D0, [85]*/
	__IO	uint16_t	R1_CFGR_PSVB_OD_TSYNC;  	/*0x04D0, [85]*/
	__IO	uint16_t	R0_CFGR_AIP_ENA3;       	/*0x03D2, [86]*/
	__IO	uint16_t	R1_CFGR_AIP_ENA3;       	/*0x04D2, [86]*/
	__IO	uint16_t	R0_CFGR_CMUX_MP1;       	/*0x03EA, [87]*/
	__IO	uint16_t	R1_CFGR_CMUX_MP1;       	/*0x04EA, [87]*/
	__IO	uint16_t	R0_CFGR_CMUX_MP2;       	/*0x03EC, [88]*/
	__IO	uint16_t	R1_CFGR_CMUX_MP2;       	/*0x04EC, [88]*/
	__IO	uint16_t	R0_CFGR_PWM_NUM6;       	/*0x03EE, [89]*/
	__IO	uint16_t	R1_CFGR_PWM_NUM6;       	/*0x04EE, [89]*/
	__IO	uint16_t	R0_CFGR_PWM_NUM7;       	/*0x03F0, [90]*/
	__IO	uint16_t	R1_CFGR_PWM_NUM7;       	/*0x04F0, [90]*/
	__IO	uint16_t	R0_CFGR_PWM_NUM8;       	/*0x03F2, [91]*/
	__IO	uint16_t	R1_CFGR_PWM_NUM8;       	/*0x04F2, [91]*/
	__IO	uint16_t	R0_CFGR_MD_DIFF_CMUX;   	/*0x03F4, [92]*/
	__IO	uint16_t	R1_CFGR_MD_DIFF_CMUX;   	/*0x04F4, [92]*/
	__IO	uint16_t	R0_CFGR_CMUX_MN1;       	/*0x03F6, [93]*/
	__IO	uint16_t	R1_CFGR_CMUX_MN1;       	/*0x04F6, [93]*/
	__IO	uint16_t	R0_CFGR_CMUX_MN2;       	/*0x03F8, [94]*/
	__IO	uint16_t	R1_CFGR_CMUX_MN2;       	/*0x04F8, [94]*/
	__IO	uint16_t	R0_CFGR_MD_IDLE;        	/*0x03FE, [95]*/
	__IO	uint16_t	R1_CFGR_MD_IDLE;        	/*0x04FE, [95]*/
				
} __PACKED tSW92407_RegValueDef;				


typedef struct
{
	uint16_t ulADDR;
	uint16_t ulMSLocalValue;
	uint16_t ulMSFullValue;
	uint16_t ulWacomLocalValue;
	uint16_t ulWacomFullValue;

} __PACKED tSW92407_FullLocal_CFG_t;				

#define SRIC_PROTOCOL_RESET_COUNT   		(7)		
#define SRIC_REG_INIT_VALUE_NUM				(95)	

typedef struct
{
//	tSW92407_RegAddrDef		RegAddr;
	tSW92407_RegValueDef 	RegVal;

} __PACKED tModuleSRICCommonConf_t;

#include "_swl92407_parampreset.h"

#endif /* (USED_ROIC_DEF == ROIC_SWL92407) */


#endif /* __SWL92407_CONF_H_ */
