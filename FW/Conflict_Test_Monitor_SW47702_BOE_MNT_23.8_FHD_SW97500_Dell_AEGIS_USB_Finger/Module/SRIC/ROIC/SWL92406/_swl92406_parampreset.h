/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _swl92406_parampreset.h
 * created on : 13. 5. 2019
 * Author : mhjang
 *
 * All rights RESERVED.
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

#ifndef __SWL92406_PARAMPRESET_H_
#define __SWL92406_PARAMPRESET_H_


#if (USED_ROIC_DEF == ROIC_SWL92406)
#define SRIC_MSPEN_Conf_Set	\
	.value[	0	] = {	0x0300	,	0x2196	,	0x2196	},	/* [00]	CFGR_PRODUCT_ID	*/ \
	.value[	1	] = {	0x0302	,	0x0000	,	0x0000	},	/* [01]	CFGR_SNSR_STR	*/ \
	.value[	2	] = {	0x0304	,	0x4050	,	0x4050	},	/* [02]	CFGR_MD_GENERAL	*/ \
	.value[	3	] = {	0x0306	,	0x9D3F	,	0x9D3F	},	/* [03]	CFGR_AIP_ADC	*/ \
	.value[	4	] = {	0x0308	,	0x310A	,	0x310A	},	/* [04]	CFGR_SSU_CTRL	*/ \
	.value[	5	] = {	0x030A	,	0x0501	,	0x0501	},	/* [05]	CFGR_TSYNC_NUM0	*/ \
	.value[	6	] = {	0x030C	,	0x0501	,	0x0501	},	/* [06]	CFGR_TSYNC_NUM1	*/ \
	.value[	7	] = {	0x030E	,	0x0000	,	0x0000	},	/* [07]	CFGR_TSYNC_DMMY	*/ \
	.value[	8	] = {	0x0310	,	0x0104	,	0x0104	},	/* [08]	CFGR_PWM_NUM0	*/ \
	.value[	9	] = {	0x0312	,	0x050C	,	0x050C	},	/* [09]	CFGR_PWM_NUM1	*/ \
	.value[	10	] = {	0x0314	,	0xA0E0	,	0xA0E0	},	/* [10]	CFGR_CMUX_NORM	*/ \
	.value[	11	] = {	0x0316	,	0x003C	,	0x003C	},	/* [11]	CFGR_CHIP0_LEN	*/ \
	.value[	12	] = {	0x0318	,	0x0650	,	0x0650	},	/* [12]	CFGR_COL_NUM	*/ \
	.value[	13	] = {	0x031A	,	0x4003	,	0x4003	},	/* [13]	CFGR_OUTER	*/ \
	.value[	14	] = {	0x031C	,	0x4040	,	0x4040	},	/* [14]	CFGR_DIG_GAIN0	*/ \
	.value[	15	] = {	0x031E	,	0x0040	,	0x0040	},	/* [15]	CFGR_DIG_GAIN1	*/ \
	.value[	16	] = {	0x0330	,	0x1111	,	0x1111	},	/* [16]	CFGR_SSU_CR_MN1_IE	*/ \
	.value[	17	] = {	0x0332	,	0x1111	,	0x1111	},	/* [17]	CFGR_SSU_CR_MN2_IE	*/ \
	.value[	18	] = {	0x033A	,	0x0011	,	0x0011	},	/* [18]	CFGR_SHA_STR	*/ \
	.value[	19	] = {	0x033C	,	0x4040	,	0x4040	},	/* [19]	CFGR_DIG_GAIN2	*/ \
	.value[	20	] = {	0x033E	,	0x0002	,	0x0002	},	/* [20]	CFGR_RSTP_WIDTH	*/ \
	.value[	21	] = {	0x0340	,	0x0680	,	0x0680	},	/* [21]	CFGR_VCR_STR	*/ \
	.value[	22	] = {	0x0342	,	0x0234	,	0x0234	},	/* [22]	CFGR_VCR2_MD	*/ \
	.value[	23	] = {	0x0344	,	0x0014	,	0x0014	},	/* [23]	CFGR_VCR2_PHTCR	*/ \
	.value[	24	] = {	0x0346	,	0x0001	,	0x0001	},	/* [24]	CFGR_PHTH0_WIDTH	*/ \
	.value[	25	] = {	0x0348	,	0x0004	,	0x0004	},	/* [25]	CFGR_PHTH1_WIDTH	*/ \
	.value[	26	] = {	0x034A	,	0x8000	,	0x8000	},	/* [26]	CFGR_TEST_OPT	*/ \
	.value[	27	] = {	0x034C	,	0x3F3F	,	0x3F3F	},	/* [27]	CFGR_SSU_ON	*/ \
	.value[	28	] = {	0x034E	,	0x3322	,	0x3322	},	/* [28]	CFGR_CMUX_NUM	*/ \
	.value[	29	] = {	0x0350	,	0x7711	,	0x7711	},	/* [29]	CFGR_SSU_CR_I00	*/ \
	.value[	30	] = {	0x0352	,	0x0000	,	0x0000	},	/* [30]	CFGR_SSU_CR_I04	*/ \
	.value[	31	] = {	0x0354	,	0x0000	,	0x0000	},	/* [31]	CFGR_SSU_CR_I08	*/ \
	.value[	32	] = {	0x0356	,	0x0000	,	0x0000	},	/* [32]	CFGR_SSU_CR_I12	*/ \
	.value[	33	] = {	0x0358	,	0x0000	,	0x0000	},	/* [33]	CFGR_SSU_CR_I14	*/ \
	.value[	34	] = {	0x035A	,	0x0000	,	0x0000	},	/* [34]	CFGR_SSU_CR_E00	*/ \
	.value[	35	] = {	0x035C	,	0x0000	,	0x0000	},	/* [35]	CFGR_SSU_CR_E04	*/ \
	.value[	36	] = {	0x035E	,	0x0000	,	0x0000	},	/* [36]	CFGR_SSU_CR_E08	*/ \
	.value[	37	] = {	0x0360	,	0x0000	,	0x0000	},	/* [37]	CFGR_SSU_CR_E12	*/ \
	.value[	38	] = {	0x0362	,	0x0000	,	0x0000	},	/* [38]	CFGR_SSU_CR_E14	*/ \
	.value[	39	] = {	0x0364	,	0x0000	,	0x0000	},	/* [39]	CFGR_SSU_CR_PEN_I00	*/ \
	.value[	40	] = {	0x0366	,	0x0000	,	0x0000	},	/* [40]	CFGR_SSU_CR_PEN_I04	*/ \
	.value[	41	] = {	0x0368	,	0x0000	,	0x0000	},	/* [41]	CFGR_SSU_CR_PEN_I08	*/ \
	.value[	42	] = {	0x036A	,	0x0000	,	0x0000	},	/* [42]	CFGR_SSU_CR_PEN_I12	*/ \
	.value[	43	] = {	0x036C	,	0x0000	,	0x0000	},	/* [43]	CFGR_SSU_CR_PEN_I14	*/ \
	.value[	44	] = {	0x036E	,	0x0000	,	0x0000	},	/* [44]	CFGR_SSU_CR_PEN_E00	*/ \
	.value[	45	] = {	0x0370	,	0x0000	,	0x0000	},	/* [45]	CFGR_SSU_CR_PEN_E04	*/ \
	.value[	46	] = {	0x0372	,	0x0000	,	0x0000	},	/* [46]	CFGR_SSU_CR_PEN_E08	*/ \
	.value[	47	] = {	0x0374	,	0x0000	,	0x0000	},	/* [47]	CFGR_SSU_CR_PEN_E12	*/ \
	.value[	48	] = {	0x0376	,	0x0000	,	0x0000	},	/* [48]	CFGR_SSU_CR_PEN_E14	*/ \
	.value[	49	] = {	0x037A	,	0x2252	,	0x2252	},	/* [49]	CFGR_SSU_INT_GC	*/ \
	.value[	50	] = {	0x037C	,	0x0010	,	0x0010	},	/* [50]	CFGR_EDGE_CR_SEL	*/ \
	.value[	51	] = {	0x037E	,	0x2492	,	0x2492	},	/* [51]	CFGR_SSU_GC	*/ \
	.value[	52	] = {	0x0380	,	0x4321	,	0x4321	},	/* [52]	CFGR_CMUX_REMAP0	*/ \
	.value[	53	] = {	0x0382	,	0x8765	,	0x8765	},	/* [53]	CFGR_CMUX_REMAP1	*/ \
	.value[	54	] = {	0x0384	,	0x00A9	,	0x00A9	},	/* [54]	CFGR_CMUX_REMAP2	*/ \
	.value[	55	] = {	0x0386	,	0x0F01	,	0x0F01	},	/* [55]	CFGR_TSYNC_NUM_PEN	*/ \
	.value[	56	] = {	0x0388	,	0x0000	,	0x0000	},	/* [56]	CFGR_TSYNC_DMMY_PEN	*/ \
	.value[	57	] = {	0x038A	,	0x2020	,	0x2020	},	/* [57]	CFGR_CMUX_NUM_PEN	*/ \
	.value[	58	] = {	0x038C	,	0x0040	,	0x0040	},	/* [58]	CFGR_PEN_CTRL	*/ \
	.value[	59	] = {	0x038E	,	0x8844	,	0x8844	},	/* [59]	CFGR_HALF_COPY	*/ \
	.value[	60	] = {	0x0390	,	0x0AAA	,	0x0AAA	},	/* [60]	CFGR_PEN0_TSYNC0	*/ \
	.value[	61	] = {	0x0392	,	0x1256	,	0x1256	},	/* [61]	CFGR_PEN0_TSYNC1	*/ \
	.value[	62	] = {	0x0394	,	0x0AAA	,	0x0AAA	},	/* [62]	CFGR_PEN0_TSYNC2	*/ \
	.value[	63	] = {	0x0396	,	0x0000	,	0x0000	},	/* [63]	CFGR_PEN_CTRL2	*/ \
	.value[	64	] = {	0x03A0	,	0x050C	,	0x050C	},	/* [64]	CFGR_PWM_NUM2	*/ \
	.value[	65	] = {	0x03A2	,	0x0505	,	0x0505	},	/* [65]	CFGR_PWM_NUM3	*/ \
	.value[	66	] = {	0x03A4	,	0x1212	,	0x1212	},	/* [66]	CFGR_PWM_NUM4	*/ \
	.value[	67	] = {	0x03A6	,	0x0841	,	0x0841	},	/* [67]	CFGR_PWM_NUM5	*/ \
	.value[	68	] = {	0x03A8	,	0x010A	,	0x010A	},	/* [68]	CFGR_PWM_NUM_NI	*/ \
	.value[	69	] = {	0x03AA	,	0x0155	,	0x0155	},	/* [69]	CFGR_CMUX_NI1	*/ \
	.value[	70	] = {	0x03AC	,	0x02AA	,	0x02AA	},	/* [70]	CFGR_CMUX_NI2	*/ \
	.value[	71	] = {	0x03AE	,	0x0155	,	0x0155	},	/* [71]	CFGR_CMUX_NI3	*/ \
	.value[	72	] = {	0x03B0	,	0x02AA	,	0x02AA	},	/* [72]	CFGR_CMUX_NI4	*/ \
	.value[	73	] = {	0x03B2	,	0x0000	,	0x0000	},	/* [73]	CFGR_AFE_DUM	*/ \
	.value[	74	] = {	0x03B4	,	0xBE7E	,	0xBE7E	},	/* [74]	CFGR_PSVB_PEN_TSYNC	*/ \
	.value[	75	] = {	0x03B6	,	0xFFFF	,	0xFFFF	},	/* [75]	CFGR_PSVB_FGR_TSYNC	*/ \
	.value[	76	] = {	0x03B8	,	0x0000	,	0x0000	},	/* [76]	CFGR_PEN_LHB_ABD	*/ \
	.value[	77	] = {	0x03BA	,	0x3331	,	0x3331	},	/* [77]	CFGR_SSU_BCON1	*/ \
	.value[	78	] = {	0x03BC	,	0x3331	,	0x3331	},	/* [78]	CFGR_SSU_BCON2	*/ \
	.value[	79	] = {	0x03BE	,	0x3333	,	0x3333	},	/* [79]	CFGR_SSU_BCON3	*/ \
	.value[	80	] = {	0x03C0	,	0x3000	,	0x3000	},	/* [80]	CFGR_SPIS_CFG	*/ \
	.value[	81	] = {	0x03C2	,	0x3333	,	0x3333	},	/* [81]	CFGR_SSU_BCON4	*/ \
	.value[	82	] = {	0x03C4	,	0x09E0	,	0x09E0	},	/* [82]	CFGR_ACLK_DIV2	*/ \
	.value[	83	] = {	0x03C6	,	0x3336	,	0x3336	},	/* [83]	CFGR_ADIV2_TOG_PAT	*/ \
	.value[	84	] = {	0x03C8	,	0x0000	,	0x0000	},	/* [84]	CFGR_PSVB_AFE	*/ \
	.value[	85	] = {	0x03CA	,	0x0000	,	0x0000	},	/* [85]	CFGR_AIP_ENA	*/ \
	.value[	86	] = {	0x03EA	,	0x0000	,	0x0000	},	/* [86]	CFGR_CMUX_MP1	*/ \
	.value[	87	] = {	0x03EC	,	0x0000	,	0x0000	},	/* [87]	CFGR_CMUX_MP2	*/ \
	.value[	88	] = {	0x03EE	,	0x0505	,	0x0505	},	/* [88]	CFGR_PWM_NUM6	*/ \
	.value[	89	] = {	0x03F0	,	0x0505	,	0x0505	},	/* [89]	CFGR_PWM_NUM7	*/ \
	.value[	90	] = {	0x03F2	,	0x0505	,	0x0505	},	/* [90]	CFGR_PWM_NUM8	*/ \
	.value[	91	] = {	0x03F4	,	0x0000	,	0x0000	},	/* [91]	CFGR_MD_DIFF_CMUX	*/ \
	.value[	92	] = {	0x03F6	,	0x0000	,	0x0000	},	/* [92]	CFGR_CMUX_MN1	*/ \
	.value[	93	] = {	0x03F8	,	0x03FF	,	0x03FF	},	/* [93]	CFGR_CMUX_MN2	*/ \
	.value[	94	] = {	0x03FE	,	0x1000	,	0x1000	},	/* [94]	CFGR_MD_IDLE	*/ \

//#if USED_MSPEN_LINEDIM_WORKAROUND \
//	.value[	92	] =	/* CFGR_CMUX_MN1 */ \
//		{0x3F6	,	0x0000	,	0x0000	},	\
//	.value[	93	] =	/* CFGR_CMUX_MN2 */ \
//		{0x3F8	,	0x03FF	,	0x03FF	},	\
//	.value[	94	] =	/* CFGR_MD_IDLE */ \
//		{0x3FE	,	0x1000	,	0x1000	},	\
//#else /* USED_MSPEN_LINEDIM_WORKAROUND */ \
//	.value[	92	] =	/* CFGR_CMUX_MN1 */ \
//		{0x3F6	,	0x03FF	,	0x03FF	},	\
//	.value[	93	] =	/* CFGR_CMUX_MN2 */ \
//		{0x3F8	,	0x03FF	,	0x03FF	},	\
//	.value[	94	] =	/* CFGR_MD_IDLE */ \
//		{0x3FE	,	0x2000	,	0x2000	},	\
//#endif /* USED_MSPEN_LINEDIM_WORKAROUND */ \



#define SRIC_WACOMPEN_Conf_Set	\
	.value[	0	] = {	0x0300	,	0x2196	,	0x2196	},	/* [00]	CFGR_PRODUCT_ID	*/ \
	.value[	1	] = {	0x0302	,	0x0000	,	0x0000	},	/* [01]	CFGR_SNSR_STR	*/ \
	.value[	2	] = {	0x0304	,	0x4050	,	0x4050	},	/* [02]	CFGR_MD_GENERAL	*/ \
	.value[	3	] = {	0x0306	,	0x9D3F	,	0x9D3F	},	/* [03]	CFGR_AIP_ADC	*/ \
	.value[	4	] = {	0x0308	,	0x333A	,	0x333A	},	/* [04]	CFGR_SSU_CTRL	*/ \
	.value[	5	] = {	0x030A	,	0x0501	,	0x0501	},	/* [05]	CFGR_TSYNC_NUM0	*/ \
	.value[	6	] = {	0x030C	,	0x0501	,	0x0501	},	/* [06]	CFGR_TSYNC_NUM1	*/ \
	.value[	7	] = {	0x030E	,	0x0000	,	0x0000	},	/* [07]	CFGR_TSYNC_DMMY	*/ \
	.value[	8	] = {	0x0310	,	0x010F	,	0x010F	},	/* [08]	CFGR_PWM_NUM0	*/ \
	.value[	9	] = {	0x0312	,	0x050C	,	0x050C	},	/* [09]	CFGR_PWM_NUM1	*/ \
	.value[	10	] = {	0x0314	,	0xA0E0	,	0xA0E0	},	/* [10]	CFGR_CMUX_NORM	*/ \
	.value[	11	] = {	0x0316	,	0x003C	,	0x003C	},	/* [11]	CFGR_CHIP0_LEN	*/ \
	.value[	12	] = {	0x0318	,	0x0650	,	0x0650	},	/* [12]	CFGR_COL_NUM	*/ \
	.value[	13	] = {	0x031A	,	0x4003	,	0x4003	},	/* [13]	CFGR_OUTER	*/ \
	.value[	14	] = {	0x031C	,	0x4040	,	0x4040	},	/* [14]	CFGR_DIG_GAIN0	*/ \
	.value[	15	] = {	0x031E	,	0x0040	,	0x0040	},	/* [15]	CFGR_DIG_GAIN1	*/ \
	.value[	16	] = {	0x0330	,	0x1111	,	0x1111	},	/* [16]	CFGR_SSU_CR_MN1_IE	*/ \
	.value[	17	] = {	0x0332	,	0x1111	,	0x1111	},	/* [17]	CFGR_SSU_CR_MN2_IE	*/ \
	.value[	18	] = {	0x033A	,	0x0011	,	0x0011	},	/* [18]	CFGR_SHA_STR	*/ \
	.value[	19	] = {	0x033C	,	0x4040	,	0x4040	},	/* [19]	CFGR_DIG_GAIN2	*/ \
	.value[	20	] = {	0x033E	,	0x0002	,	0x0002	},	/* [20]	CFGR_RSTP_WIDTH	*/ \
	.value[	21	] = {	0x0340	,	0x0680	,	0x0680	},	/* [21]	CFGR_VCR_STR	*/ \
	.value[	22	] = {	0x0342	,	0x0234	,	0x0234	},	/* [22]	CFGR_VCR2_MD	*/ \
	.value[	23	] = {	0x0344	,	0x0014	,	0x0014	},	/* [23]	CFGR_VCR2_PHTCR	*/ \
	.value[	24	] = {	0x0346	,	0x0001	,	0x0001	},	/* [24]	CFGR_PHTH0_WIDTH	*/ \
	.value[	25	] = {	0x0348	,	0x0004	,	0x0004	},	/* [25]	CFGR_PHTH1_WIDTH	*/ \
	.value[	26	] = {	0x034A	,	0x0000	,	0x0000	},	/* [26]	CFGR_TEST_OPT	*/ \
	.value[	27	] = {	0x034C	,	0x3F3F	,	0x3F3F	},	/* [27]	CFGR_SSU_ON	*/ \
	.value[	28	] = {	0x034E	,	0x2222	,	0x2222	},	/* [28]	CFGR_CMUX_NUM	*/ \
	.value[	29	] = {	0x0350	,	0x3322	,	0x3322	},	/* [29]	CFGR_SSU_CR_I00	*/ \
	.value[	30	] = {	0x0352	,	0x0000	,	0x0000	},	/* [30]	CFGR_SSU_CR_I04	*/ \
	.value[	31	] = {	0x0354	,	0x0000	,	0x0000	},	/* [31]	CFGR_SSU_CR_I08	*/ \
	.value[	32	] = {	0x0356	,	0x0000	,	0x0000	},	/* [32]	CFGR_SSU_CR_I12	*/ \
	.value[	33	] = {	0x0358	,	0x0000	,	0x0000	},	/* [33]	CFGR_SSU_CR_I14	*/ \
	.value[	34	] = {	0x035A	,	0x0000	,	0x0000	},	/* [34]	CFGR_SSU_CR_E00	*/ \
	.value[	35	] = {	0x035C	,	0x0000	,	0x0000	},	/* [35]	CFGR_SSU_CR_E04	*/ \
	.value[	36	] = {	0x035E	,	0x0000	,	0x0000	},	/* [36]	CFGR_SSU_CR_E08	*/ \
	.value[	37	] = {	0x0360	,	0x0000	,	0x0000	},	/* [37]	CFGR_SSU_CR_E12	*/ \
	.value[	38	] = {	0x0362	,	0x0000	,	0x0000	},	/* [38]	CFGR_SSU_CR_E14	*/ \
	.value[	39	] = {	0x0364	,	0x0000	,	0x0000	},	/* [39]	CFGR_SSU_CR_PEN_I00	*/ \
	.value[	40	] = {	0x0366	,	0x0000	,	0x0000	},	/* [40]	CFGR_SSU_CR_PEN_I04	*/ \
	.value[	41	] = {	0x0368	,	0x0000	,	0x0000	},	/* [41]	CFGR_SSU_CR_PEN_I08	*/ \
	.value[	42	] = {	0x036A	,	0x0000	,	0x0000	},	/* [42]	CFGR_SSU_CR_PEN_I12	*/ \
	.value[	43	] = {	0x036C	,	0x0000	,	0x0000	},	/* [43]	CFGR_SSU_CR_PEN_I14	*/ \
	.value[	44	] = {	0x036E	,	0x0000	,	0x0000	},	/* [44]	CFGR_SSU_CR_PEN_E00	*/ \
	.value[	45	] = {	0x0370	,	0x0000	,	0x0000	},	/* [45]	CFGR_SSU_CR_PEN_E04	*/ \
	.value[	46	] = {	0x0372	,	0x0000	,	0x0000	},	/* [46]	CFGR_SSU_CR_PEN_E08	*/ \
	.value[	47	] = {	0x0374	,	0x0000	,	0x0000	},	/* [47]	CFGR_SSU_CR_PEN_E12	*/ \
	.value[	48	] = {	0x0376	,	0x0000	,	0x0000	},	/* [48]	CFGR_SSU_CR_PEN_E14	*/ \
	.value[	49	] = {	0x037A	,	0x20DA	,	0x20DA	},	/* [49]	CFGR_SSU_INT_GC	*/ \
	.value[	50	] = {	0x037C	,	0x0010	,	0x0010	},	/* [50]	CFGR_EDGE_CR_SEL	0210 Pen Position Int Half */ \
	.value[	51	] = {	0x037E	,	0x2532	,	0x2532	},	/* [51]	CFGR_SSU_GC 2632, 2732 (Down) Wacom Pen Position Gain */ \
	.value[	52	] = {	0x0380	,	0x4321	,	0x4321	},	/* [52]	CFGR_CMUX_REMAP0	*/ \
	.value[	53	] = {	0x0382	,	0x8765	,	0x8765	},	/* [53]	CFGR_CMUX_REMAP1	*/ \
	.value[	54	] = {	0x0384	,	0x00A9	,	0x00A9	},	/* [54]	CFGR_CMUX_REMAP2	*/ \
	.value[	55	] = {	0x0386	,	0x0F01	,	0x0F01	},	/* [55]	CFGR_TSYNC_NUM_PEN	*/ \
	.value[	56	] = {	0x0388	,	0x0000	,	0x0000	},	/* [56]	CFGR_TSYNC_DMMY_PEN	*/ \
	.value[	57	] = {	0x038A	,	0x1A1A	,	0x1A1A	},	/* [57]	CFGR_CMUX_NUM_PEN	*/ \
	.value[	58	] = {	0x038C	,	0x0040	,	0x0040	},	/* [58]	CFGR_PEN_CTRL	*/ \
	.value[	59	] = {	0x038E	,	0x8944	,	0x8944	},	/* [59]	CFGR_HALF_COPY	*/ \
	.value[	60	] = {	0x0390	,	0x9F9E	,	0x9F9E	},	/* [60]	CFGR_PEN0_TSYNC0	*/ \
	.value[	61	] = {	0x0392	,	0x1F81	,	0x1F81	},	/* [61]	CFGR_PEN0_TSYNC1	*/ \
	.value[	62	] = {	0x0394	,	0x0AAA	,	0x0AAA	},	/* [62]	CFGR_PEN0_TSYNC2	*/ \
	.value[	63	] = {	0x0396	,	0x0000	,	0x0000	},	/* [63]	CFGR_PEN_CTRL2	*/ \
	.value[	64	] = {	0x03A0	,	0x070E	,	0x070E	},	/* [64]	CFGR_PWM_NUM2	*/ \
	.value[	65	] = {	0x03A2	,	0x0A10	,	0x0A10	},	/* [65]	CFGR_PWM_NUM3	*/ \
	.value[	66	] = {	0x03A4	,	0x0514	,	0x0514	},	/* [66]	CFGR_PWM_NUM4	*/ \
	.value[	67	] = {	0x03A6	,	0x0841	,	0x0841	},	/* [67]	CFGR_PWM_NUM5	*/ \
	.value[	68	] = {	0x03A8	,	0x810E	,	0x810E	},	/* [68]	CFGR_PWM_NUM_NI	*/ \
	.value[	69	] = {	0x03AA	,	0x0155	,	0x0155	},	/* [69]	CFGR_CMUX_NI1	*/ \
	.value[	70	] = {	0x03AC	,	0x02AA	,	0x02AA	},	/* [70]	CFGR_CMUX_NI2	*/ \
	.value[	71	] = {	0x03AE	,	0x0155	,	0x0155	},	/* [71]	CFGR_CMUX_NI3	*/ \
	.value[	72	] = {	0x03B0	,	0x02AA	,	0x02AA	},	/* [72]	CFGR_CMUX_NI4	*/ \
	.value[	73	] = {	0x03B2	,	0x0000	,	0x0000	},	/* [73]	CFGR_AFE_DUM	*/ \
	.value[	74	] = {	0x03B4	,	0xF3FE	,	0xF3FE	},	/* [74]	CFGR_PSVB_PEN_TSYNC	*/ \
	.value[	75	] = {	0x03B6	,	0xFFFF	,	0xFFFF	},	/* [75]	CFGR_PSVB_FGR_TSYNC	*/ \
	.value[	76	] = {	0x03B8	,	0x0000	,	0x0000	},	/* [76]	CFGR_PEN_LHB_ABD	*/ \
	.value[	77	] = {	0x03BA	,	0x3331	,	0x3331	},	/* [77]	CFGR_SSU_BCON1	*/ \
	.value[	78	] = {	0x03BC	,	0x3331	,	0x3331	},	/* [78]	CFGR_SSU_BCON2	*/ \
	.value[	79	] = {	0x03BE	,	0x3333	,	0x3333	},	/* [79]	CFGR_SSU_BCON3	*/ \
	.value[	80	] = {	0x03C0	,	0x3000	,	0x3000	},	/* [80]	CFGR_SPIS_CFG	*/ \
	.value[	81	] = {	0x03C2	,	0x3333	,	0x3333	},	/* [81]	CFGR_SSU_BCON4	*/ \
	.value[	82	] = {	0x03C4	,	0xAED1	,	0xAED1	},	/* [82]	CFGR_ACLK_DIV2	*/ \
	.value[	83	] = {	0x03C6	,	0x3336	,	0x3336	},	/* [83]	CFGR_ADIV2_TOG_PAT	*/ \
	.value[	84	] = {	0x03C8	,	0x0000	,	0x0000	},	/* [84]	CFGR_PSVB_AFE	*/ \
	.value[	85	] = {	0x03CA	,	0x0000	,	0x0000	},	/* [85]	CFGR_AIP_ENA	*/ \
	.value[	86	] = {	0x03EA	,	0x0000	,	0x0000	},	/* [86]	CFGR_CMUX_MP1	*/ \
	.value[	87	] = {	0x03EC	,	0x0000	,	0x0000	},	/* [87]	CFGR_CMUX_MP2	*/ \
	.value[	88	] = {	0x03EE	,	0x0505	,	0x0505	},	/* [88]	CFGR_PWM_NUM6	*/ \
	.value[	89	] = {	0x03F0	,	0x0505	,	0x0505	},	/* [89]	CFGR_PWM_NUM7	*/ \
	.value[	90	] = {	0x03F2	,	0x0505	,	0x0505	},	/* [90]	CFGR_PWM_NUM8	*/ \
	.value[	91	] = {	0x03F4	,	0x0000	,	0x0000	},	/* [91]	CFGR_MD_DIFF_CMUX	*/ \
	.value[	92	] = {	0x03F6	,	0x03FF	,	0x03FF	},	/* [92]	CFGR_CMUX_MN1	*/ \
	.value[	93	] = {	0x03F8	,	0x03FF	,	0x03FF	},	/* [93]	CFGR_CMUX_MN2	*/ \
	.value[	94	] = {	0x03FE	,	0x0000	,	0x0000	},	/* [94]	CFGR_MD_IDLE	*/ \



#if ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN))
#define SRIC_Conf_Set	SRIC_MSPEN_Conf_Set
#elif ((USED_PEN_PROTOCOL == PEN_PROTOCOL_WACOM_PEN))
#define SRIC_Conf_Set	SRIC_WACOMPEN_Conf_Set
#endif /* ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN)) */

#endif /* (USED_ROIC_DEF == ROIC_SW97500) */



#endif /* __SWL92406_PARAMPRESET_H_ */
