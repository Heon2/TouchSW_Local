/****************************************************************************************************//**
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file : _sric_p.h
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

#ifndef __SW97400B_REGISTER_H_
#define __SW97400B_REGISTER_H_

#define	SW97400B_REGISTER_VALUE_ACTIVE                                          \
				.R0_RegVal_Active =                                             \
				{                                                               \
					.SRIC_CFGR_00H		= {0x4190, 0x4190, 0x4190, 0x4190},     \
					.SRIC_CFGR_02H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_04H		= {0x4061, 0x4061, 0x4061, 0x4061},     \
					.SRIC_CFGR_06H		= {0x1E3F, 0x1E3F, 0x1E3F, 0x1E3F},     \
					.SRIC_CFGR_08H		= {0x59BB, 0x59BB, 0x59BB, 0x59BB},     \
					.SRIC_CFGR_0AH		= {0x0700, 0x0700, 0x0700, 0x0700},     \
					.SRIC_CFGR_0CH		= {0x0700, 0x0700, 0x0700, 0x0700},     \
					.SRIC_CFGR_0EH		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_10H		= {0x0104, 0x0104, 0x0104, 0x0104},     \
					.SRIC_CFGR_12H		= {0x0912, 0x0912, 0x0912, 0x0912},     \
					.SRIC_CFGR_14H		= {0x2380, 0x2380, 0x2380, 0x2380},     \
					.SRIC_CFGR_16H		= {0x0050, 0x0050, 0x0050, 0x0050},     \
					.SRIC_CFGR_18H		= {0xAA90, 0xAA90, 0xAA90, 0xAA90},     \
					.SRIC_CFGR_1AH		= {0x4003, 0x4003, 0x4003, 0x4003},     \
					.SRIC_CFGR_1CH		= {0x4040, 0x4040, 0x4040, 0x4040},     \
					.SRIC_CFGR_1EH		= {0x0040, 0x0040, 0x0040, 0x0040},     \
					.SRIC_CFGR_20H		= {0x03E8, 0x03E8, 0x03E8, 0x03E8},     \
					.SRIC_CFGR_22H		= {0x044C, 0x044C, 0x044C, 0x044C},     \
					.SRIC_CFGR_24H		= {0x07D0, 0x07D0, 0x07D0, 0x07D0},     \
					.SRIC_CFGR_26H		= {0x0834, 0x0834, 0x0834, 0x0834},     \
					.SRIC_CFGR_28H		= {0x0BB8, 0x0BB8, 0x0BB8, 0x0BB8},     \
					.SRIC_CFGR_2AH		= {0x0C1C, 0x0C1C, 0x0C1C, 0x0C1C},     \
					.SRIC_CFGR_2CH		= {0x0FA0, 0x0FA0, 0x0FA0, 0x0FA0},     \
					.SRIC_CFGR_2EH		= {0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF},     \
					.SRIC_CFGR_30H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_32H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_34H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_36H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_38H		= {0x2040, 0x2040, 0x2040, 0x2040},     \
					.SRIC_CFGR_3AH		= {0x001B, 0x001B, 0x001B, 0x001B},     \
					.SRIC_CFGR_3CH		= {0x4040, 0x4040, 0x4040, 0x4040},     \
					.SRIC_CFGR_3EH		= {0x0004, 0x0004, 0x0004, 0x0004},     \
					.SRIC_CFGR_40H		= {0x0680, 0x0680, 0x0680, 0x0680},     \
					.SRIC_CFGR_42H		= {0x0614, 0x0614, 0x0614, 0x0614},     \
					.SRIC_CFGR_44H		= {0x001E, 0x001E, 0x001E, 0x001E},     \
					.SRIC_CFGR_46H		= {0x0001, 0x0001, 0x0001, 0x0001},     \
					.SRIC_CFGR_48H		= {0x0004, 0x0004, 0x0004, 0x0004},     \
					.SRIC_CFGR_4AH		= {0x000F, 0x000F, 0x000F, 0x000F},     \
					.SRIC_CFGR_4CH		= {0x00B8, 0x00B8, 0x00B8, 0x0054},     \
					.SRIC_CFGR_4EH		= {0x7576, 0x7576, 0x7576, 0x7576},     \
					.SRIC_CFGR_50H		= {0x7474, 0x7474, 0x7474, 0x7474},     \
					.SRIC_CFGR_52H		= {0x7474, 0x7474, 0x7474, 0x7474},     \
					.SRIC_CFGR_54H		= {0x7373, 0x7373, 0x7373, 0x7373},     \
					.SRIC_CFGR_56H		= {0x0071, 0x0071, 0x0071, 0x0071},     \
					.SRIC_CFGR_58H		= {0x7777, 0x7777, 0x7777, 0x7777},     \
					.SRIC_CFGR_5AH		= {0x7777, 0x7777, 0x7777, 0x7777},     \
					.SRIC_CFGR_5CH		= {0x7576, 0x7576, 0x7576, 0x7577},     \
					.SRIC_CFGR_5EH		= {0x7474, 0x7474, 0x7474, 0x7474},     \
					.SRIC_CFGR_60H		= {0x7474, 0x7474, 0x7474, 0x7474},     \
					.SRIC_CFGR_62H		= {0x7373, 0x7373, 0x7373, 0x7373},     \
					.SRIC_CFGR_64H		= {0x0071, 0x0071, 0x0071, 0x0073},     \
					.SRIC_CFGR_66H		= {0x7777, 0x7777, 0x7777, 0x7777},     \
					.SRIC_CFGR_68H		= {0x7777, 0x7777, 0x7777, 0x7777},     \
					.SRIC_CFGR_6AH		= {0x7576, 0x7576, 0x7576, 0x7576},     \
					.SRIC_CFGR_6CH		= {0x7474, 0x7474, 0x7474, 0x7474},     \
					.SRIC_CFGR_6EH		= {0x7474, 0x7474, 0x7474, 0x7474},     \
					.SRIC_CFGR_70H		= {0x7373, 0x7373, 0x7373, 0x7373},     \
					.SRIC_CFGR_72H		= {0x0071, 0x0071, 0x0071, 0x0071},     \
					.SRIC_CFGR_74H		= {0x7777, 0x7777, 0x7777, 0x7777},     \
					.SRIC_CFGR_76H		= {0x7777, 0x7777, 0x7777, 0x7777},     \
					.SRIC_CFGR_78H		= {0x7576, 0x7576, 0x7576, 0x7576},     \
					.SRIC_CFGR_7AH		= {0x7474, 0x7474, 0x7474, 0x7474},     \
					.SRIC_CFGR_7CH		= {0x7474, 0x7474, 0x7474, 0x7474},     \
					.SRIC_CFGR_7EH		= {0x7373, 0x7373, 0x7373, 0x7373},     \
					.SRIC_CFGR_80H		= {0x0071, 0x0071, 0x0071, 0x0071},     \
					.SRIC_CFGR_82H		= {0x7777, 0x7777, 0x7777, 0x7777},     \
					.SRIC_CFGR_84H		= {0x7777, 0x7777, 0x7777, 0x7777},     \
					.SRIC_CFGR_86H		= {0x7576, 0x7576, 0x7576, 0x7576},     \
					.SRIC_CFGR_88H		= {0x7474, 0x7474, 0x7474, 0x7474},     \
					.SRIC_CFGR_8AH		= {0x7474, 0x7474, 0x7474, 0x7474},     \
					.SRIC_CFGR_8CH		= {0x7373, 0x7373, 0x7373, 0x7373},     \
					.SRIC_CFGR_8EH		= {0x0071, 0x0071, 0x0071, 0x0071},     \
					.SRIC_CFGR_90H		= {0x7777, 0x7777, 0x7777, 0x7777},     \
					.SRIC_CFGR_92H		= {0x7777, 0x7777, 0x7777, 0x7777},     \
					.SRIC_CFGR_94H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_96H		= {0x0321, 0x0321, 0x0321, 0x0321},     \
					.SRIC_CFGR_98H		= {0x0654, 0x0654, 0x0654, 0x0654},     \
					.SRIC_CFGR_9AH		= {0x0987, 0x0987, 0x0987, 0x0987},     \
					.SRIC_CFGR_9CH		= {0x4112, 0x4112, 0x4112, 0x4112},     \
					.SRIC_CFGR_9EH		= {0x4112, 0x4112, 0x4112, 0x4112},     \
					.SRIC_CFGR_A0H		= {0x4112, 0x4112, 0x4112, 0x4112},     \
					.SRIC_CFGR_A2H		= {0x4112, 0x4112, 0x4112, 0x4112},     \
					.SRIC_CFGR_A4H		= {0x0003, 0x0003, 0x0003, 0x0003},     \
					.SRIC_CFGR_A6H		= {0x000C, 0x000C, 0x000C, 0x000C},     \
					.SRIC_CFGR_A8H		= {0x0030, 0x0030, 0x0030, 0x0030},     \
					.SRIC_CFGR_AAH		= {0x01C0, 0x01C0, 0x01C0, 0x01C0},     \
					.SRIC_CFGR_ACH		= {0x0013, 0x0013, 0x0013, 0x0013},     \
					.SRIC_CFGR_AEH		= {0x0013, 0x0013, 0x0013, 0x0013},     \
					.SRIC_CFGR_B0H		= {0x0013, 0x0013, 0x0013, 0x0013},     \
					.SRIC_CFGR_B2H		= {0x0013, 0x0013, 0x0013, 0x0013},     \
					.SRIC_CFGR_B4H		= {0x0909, 0x0909, 0x0909, 0x0909},     \
					.SRIC_CFGR_B6H		= {0x0909, 0x0909, 0x0909, 0x0909},     \
					.SRIC_CFGR_B8H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_BAH		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_BCH		= {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},     \
					.SRIC_CFGR_FAH		= {0x0003, 0x0003, 0x0003, 0x0003},     \
					.SRIC_CFGR_FCH		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_FEH		= {0x0000, 0x0000, 0x0000, 0x0000},     \
				},                                                              \
				.R1_RegVal_Active =                                             \
				{                                                               \
					.SRIC_CFGR_00H		= {0x4190,	0x4190,	0x4190, 0x4190},    \
					.SRIC_CFGR_02H		= {0x0000,	0x0000,	0x0000, 0x0000},    \
					.SRIC_CFGR_04H		= {0x4061,	0x4061,	0x4061, 0x4061},    \
					.SRIC_CFGR_06H		= {0x1E3F,	0x1E3F,	0x1E3F, 0x1E3F},    \
					.SRIC_CFGR_08H		= {0x59BB,	0x59BB,	0x59BB, 0x59BB},    \
					.SRIC_CFGR_0AH		= {0x0700,	0x0700,	0x0700, 0x0700},    \
					.SRIC_CFGR_0CH		= {0x0700,	0x0700,	0x0700, 0x0700},    \
					.SRIC_CFGR_0EH		= {0x0000,	0x0000,	0x0000, 0x0000},    \
					.SRIC_CFGR_10H		= {0x0104,	0x0104,	0x0104, 0x0104},    \
					.SRIC_CFGR_12H		= {0x0912,	0x0912,	0x0912, 0x0912},    \
					.SRIC_CFGR_14H		= {0x2380,	0x2380,	0x2380, 0x2380},    \
					.SRIC_CFGR_16H		= {0x0050,	0x0050,	0x0050, 0x0050},    \
					.SRIC_CFGR_18H		= {0xAA90,	0xAA90,	0xAA90, 0xAA90},    \
					.SRIC_CFGR_1AH		= {0x401A,	0x4003,	0x4003, 0x4003},    \
					.SRIC_CFGR_1CH		= {0x4040,	0x4040,	0x4040, 0x4040},    \
					.SRIC_CFGR_1EH		= {0x0040,	0x0040,	0x0040, 0x0040},    \
					.SRIC_CFGR_20H		= {0x03E8,	0x03E8,	0x03E8, 0x03E8},    \
					.SRIC_CFGR_22H		= {0x044C,	0x044C,	0x044C, 0x044C},    \
					.SRIC_CFGR_24H		= {0x07D0,	0x07D0,	0x07D0, 0x07D0},    \
					.SRIC_CFGR_26H		= {0x0834,	0x0834,	0x0834, 0x0834},    \
					.SRIC_CFGR_28H		= {0x0BB8,	0x0BB8,	0x0BB8, 0x0BB8},    \
					.SRIC_CFGR_2AH		= {0x0C1C,	0x0C1C,	0x0C1C, 0x0C1C},    \
					.SRIC_CFGR_2CH		= {0x0FA0,	0x0FA0,	0x0FA0, 0x0FA0},    \
					.SRIC_CFGR_2EH		= {0x0FFF,	0x0FFF,	0x0FFF, 0x0FFF},    \
					.SRIC_CFGR_30H		= {0x0000,	0x0000,	0x0000, 0x0000},    \
					.SRIC_CFGR_32H		= {0x0000,	0x0000,	0x0000, 0x0000},    \
					.SRIC_CFGR_34H		= {0x0000,	0x0000,	0x0000, 0x0000},    \
					.SRIC_CFGR_36H		= {0x0000,	0x0000,	0x0000, 0x0000},    \
					.SRIC_CFGR_38H		= {0x2040,	0x2040,	0x2040, 0x2040},    \
					.SRIC_CFGR_3AH		= {0x001B,	0x001B,	0x001B, 0x001B},    \
					.SRIC_CFGR_3CH		= {0x3040,	0x4040,	0x4040, 0x4040},    \
					.SRIC_CFGR_3EH		= {0x0004,	0x0004,	0x0004, 0x0004},    \
					.SRIC_CFGR_40H		= {0x0680,	0x0680,	0x0680, 0x0680},    \
					.SRIC_CFGR_42H		= {0x0614,	0x0614,	0x0614, 0x0614},    \
					.SRIC_CFGR_44H		= {0x001E,	0x001E,	0x001E, 0x001E},    \
					.SRIC_CFGR_46H		= {0x0001,	0x0001,	0x0001, 0x0001},    \
					.SRIC_CFGR_48H		= {0x0004,	0x0004,	0x0004, 0x0004},    \
					.SRIC_CFGR_4AH		= {0x000F,	0x000F,	0x000F, 0x000F},    \
					.SRIC_CFGR_4CH		= {0x00B8,	0x00B8,	0x00B8, 0x00B8},    \
					.SRIC_CFGR_4EH		= {0x7577,	0x7576,	0x7576, 0x7576},    \
					.SRIC_CFGR_50H		= {0x7474,	0x7474,	0x7474, 0x7474},    \
					.SRIC_CFGR_52H		= {0x7474,	0x7474,	0x7474, 0x7474},    \
					.SRIC_CFGR_54H		= {0x7373,	0x7373,	0x7373, 0x7373},    \
					.SRIC_CFGR_56H		= {0x0072,	0x0071,	0x0071, 0x0071},    \
					.SRIC_CFGR_58H		= {0x7777,	0x7777,	0x7777, 0x7777},    \
					.SRIC_CFGR_5AH		= {0x7777,	0x7777,	0x7777, 0x7777},    \
					.SRIC_CFGR_5CH		= {0x7576,	0x7576,	0x7576, 0x7576},    \
					.SRIC_CFGR_5EH		= {0x7474,	0x7474,	0x7474, 0x7474},    \
					.SRIC_CFGR_60H		= {0x7474,	0x7474,	0x7474, 0x7474},    \
					.SRIC_CFGR_62H		= {0x7373,	0x7373,	0x7373, 0x7373},    \
					.SRIC_CFGR_64H		= {0x0071,	0x0071,	0x0071, 0x0071},    \
					.SRIC_CFGR_66H		= {0x7777,	0x7777,	0x7777, 0x7777},    \
					.SRIC_CFGR_68H		= {0x7777,	0x7777,	0x7777, 0x7777},    \
					.SRIC_CFGR_6AH		= {0x7576,	0x7576,	0x7576, 0x7576},    \
					.SRIC_CFGR_6CH		= {0x7474,	0x7474,	0x7474, 0x7474},    \
					.SRIC_CFGR_6EH		= {0x7474,	0x7474,	0x7474, 0x7474},    \
					.SRIC_CFGR_70H		= {0x7373,	0x7373,	0x7373, 0x7373},    \
					.SRIC_CFGR_72H		= {0x0071,	0x0071,	0x0071, 0x0071},    \
					.SRIC_CFGR_74H		= {0x7777,	0x7777,	0x7777, 0x7777},    \
					.SRIC_CFGR_76H		= {0x7777,	0x7777,	0x7777, 0x7777},    \
					.SRIC_CFGR_78H		= {0x7577,	0x7576,	0x7576, 0x7576},    \
					.SRIC_CFGR_7AH		= {0x7474,	0x7474,	0x7474, 0x7474},    \
					.SRIC_CFGR_7CH		= {0x7474,	0x7474,	0x7474, 0x7474},    \
					.SRIC_CFGR_7EH		= {0x7373,	0x7373,	0x7373, 0x7373},    \
					.SRIC_CFGR_80H		= {0x0072,	0x0071,	0x0071, 0x0071},    \
					.SRIC_CFGR_82H		= {0x7777,	0x7777,	0x7777, 0x7777},    \
					.SRIC_CFGR_84H		= {0x7777,	0x7777,	0x7777, 0x7777},    \
					.SRIC_CFGR_86H		= {0x7777,	0x7576,	0x7576, 0x7576},    \
					.SRIC_CFGR_88H		= {0x7576,	0x7474,	0x7474, 0x7474},    \
					.SRIC_CFGR_8AH		= {0x7576,	0x7474,	0x7474, 0x7474},    \
					.SRIC_CFGR_8CH		= {0x7475,	0x7373,	0x7373, 0x7373},    \
					.SRIC_CFGR_8EH		= {0x0074,	0x0072,	0x0071, 0x0071},    \
					.SRIC_CFGR_90H		= {0x7777,	0x7777,	0x7777, 0x7777},    \
					.SRIC_CFGR_92H		= {0x7777,	0x7777,	0x7777, 0x7777},    \
					.SRIC_CFGR_94H		= {0x0000,	0x0000,	0x0000, 0x0000},    \
					.SRIC_CFGR_96H		= {0x0321,	0x0321,	0x0321, 0x0321},    \
					.SRIC_CFGR_98H		= {0x0654,	0x0654,	0x0654, 0x0654},    \
					.SRIC_CFGR_9AH		= {0x0987,	0x0987,	0x0987, 0x0987},    \
					.SRIC_CFGR_9CH		= {0x4112,	0x4112,	0x4112, 0x4112},    \
					.SRIC_CFGR_9EH		= {0x4112,	0x4112,	0x4112, 0x4112},    \
					.SRIC_CFGR_A0H		= {0x4112,	0x4112,	0x4112, 0x4112},    \
					.SRIC_CFGR_A2H		= {0x4112,	0x4112,	0x4112, 0x4112},    \
					.SRIC_CFGR_A4H		= {0x0003,	0x0003,	0x0003, 0x0003},    \
					.SRIC_CFGR_A6H		= {0x000C,	0x000C,	0x000C, 0x000C},    \
					.SRIC_CFGR_A8H		= {0x0030,	0x0030,	0x0030, 0x0030},    \
					.SRIC_CFGR_AAH		= {0x01C0,	0x01C0,	0x01C0, 0x01C0},    \
					.SRIC_CFGR_ACH		= {0x0013,	0x0013,	0x0013, 0x0013},    \
					.SRIC_CFGR_AEH		= {0x0013,	0x0013,	0x0013, 0x0013},    \
					.SRIC_CFGR_B0H		= {0x0013,	0x0013,	0x0013, 0x0013},    \
					.SRIC_CFGR_B2H		= {0x0013,	0x0013,	0x0013, 0x0013},    \
					.SRIC_CFGR_B4H		= {0x0909,	0x0909,	0x0909, 0x0909},    \
					.SRIC_CFGR_B6H		= {0x0909,	0x0909,	0x0909, 0x0909},    \
					.SRIC_CFGR_B8H		= {0x0000,	0x0000,	0x0000, 0x0000},    \
					.SRIC_CFGR_BAH		= {0x0000,	0x0000,	0x0000, 0x0000},    \
					.SRIC_CFGR_BCH		= {0xFFFF,	0xFFFF,	0xFFFF, 0xFFFF},    \
					.SRIC_CFGR_FAH		= {0x0003,	0x0003,	0x0003, 0x0003},    \
					.SRIC_CFGR_FCH		= {0x0000,	0x0000,	0x0000, 0x0000},    \
					.SRIC_CFGR_FEH		= {0x0000,	0x0000,	0x0000, 0x0000},    \
				},

#define	SW97400B_REGISTER_VALUE_LPWG	                                        \
				.R0_RegVal_LPWG =                                               \
				{                                                               \
					.SRIC_CFGR_00H		= {0x4190, 0x4190, 0x4190, 0x4190},     \
					.SRIC_CFGR_02H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_04H		= {0x4061, 0x4061, 0x4061, 0x4061},     \
					.SRIC_CFGR_06H		= {0x1E3F, 0x1E3F, 0x1E3F, 0x1E3F},     \
					.SRIC_CFGR_08H		= {0x599B, 0x599B, 0x599B, 0x599B},     \
					.SRIC_CFGR_0AH		= {0x0700, 0x0700, 0x0700, 0x0700},     \
					.SRIC_CFGR_0CH		= {0x0700, 0x0700, 0x0700, 0x0700},     \
					.SRIC_CFGR_0EH		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_10H		= {0x0104, 0x0104, 0x0104, 0x0104},     \
					.SRIC_CFGR_12H		= {0x0912, 0x0912, 0x0912, 0x0912},     \
					.SRIC_CFGR_14H		= {0x2380, 0x2380, 0x2380, 0x2380},     \
					.SRIC_CFGR_16H		= {0x0050, 0x0050, 0x0050, 0x0050},     \
					.SRIC_CFGR_18H		= {0xAA90, 0xAA90, 0xAA90, 0xAA90},     \
					.SRIC_CFGR_1AH		= {0x4003, 0x4003, 0x4003, 0x4003},     \
					.SRIC_CFGR_1CH		= {0x4040, 0x4040, 0x4040, 0x4040},     \
					.SRIC_CFGR_1EH		= {0x0040, 0x0040, 0x0040, 0x0040},     \
					.SRIC_CFGR_20H		= {0x03E8, 0x03E8, 0x03E8, 0x03E8},     \
					.SRIC_CFGR_22H		= {0x044C, 0x044C, 0x044C, 0x044C},     \
					.SRIC_CFGR_24H		= {0x07D0, 0x07D0, 0x07D0, 0x07D0},     \
					.SRIC_CFGR_26H		= {0x0834, 0x0834, 0x0834, 0x0834},     \
					.SRIC_CFGR_28H		= {0x0BB8, 0x0BB8, 0x0BB8, 0x0BB8},     \
					.SRIC_CFGR_2AH		= {0x0C1C, 0x0C1C, 0x0C1C, 0x0C1C},     \
					.SRIC_CFGR_2CH		= {0x0FA0, 0x0FA0, 0x0FA0, 0x0FA0},     \
					.SRIC_CFGR_2EH		= {0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF},     \
					.SRIC_CFGR_30H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_32H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_34H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_36H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_38H		= {0x2040, 0x2040, 0x2040, 0x2040},     \
					.SRIC_CFGR_3AH		= {0x001B, 0x001B, 0x001B, 0x001B},     \
					.SRIC_CFGR_3CH		= {0x4040, 0x4040, 0x4040, 0x4040},     \
					.SRIC_CFGR_3EH		= {0x0004, 0x0004, 0x0004, 0x0004},     \
					.SRIC_CFGR_40H		= {0x0680, 0x0680, 0x0680, 0x0680},     \
					.SRIC_CFGR_42H		= {0x0614, 0x0614, 0x0614, 0x0614},     \
					.SRIC_CFGR_44H		= {0x001E, 0x001E, 0x001E, 0x001E},     \
					.SRIC_CFGR_46H		= {0x0001, 0x0001, 0x0001, 0x0001},     \
					.SRIC_CFGR_48H		= {0x0004, 0x0004, 0x0004, 0x0004},     \
					.SRIC_CFGR_4AH		= {0x000F, 0x000F, 0x000F, 0x000F},     \
					.SRIC_CFGR_4CH		= {0x00B8, 0x00B8, 0x00B8, 0x0054},     \
					.SRIC_CFGR_4EH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_50H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_52H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_54H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_56H		= {0x0067, 0x0067, 0x0067, 0x0067},     \
					.SRIC_CFGR_58H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_5AH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_5CH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_5EH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_60H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_62H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_64H		= {0x0067, 0x0067, 0x0067, 0x0067},     \
					.SRIC_CFGR_66H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_68H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_6AH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_6CH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_6EH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_70H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_72H		= {0x0067, 0x0067, 0x0067, 0x0067},     \
					.SRIC_CFGR_74H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_76H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_78H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_7AH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_7CH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_7EH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_80H		= {0x0067, 0x0067, 0x0067, 0x0067},     \
					.SRIC_CFGR_82H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_84H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_86H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_88H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_8AH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_8CH		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_8EH		= {0x0067, 0x0067, 0x0067, 0x0067},     \
					.SRIC_CFGR_90H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_92H		= {0x6767, 0x6767, 0x6767, 0x6767},     \
					.SRIC_CFGR_94H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_96H		= {0x0321, 0x0321, 0x0321, 0x0321},     \
					.SRIC_CFGR_98H		= {0x0654, 0x0654, 0x0654, 0x0654},     \
					.SRIC_CFGR_9AH		= {0x0987, 0x0987, 0x0987, 0x0987},     \
					.SRIC_CFGR_9CH		= {0x4112, 0x4112, 0x4112, 0x4112},     \
					.SRIC_CFGR_9EH		= {0x4112, 0x4112, 0x4112, 0x4112},     \
					.SRIC_CFGR_A0H		= {0x4112, 0x4112, 0x4112, 0x4112},     \
					.SRIC_CFGR_A2H		= {0x4112, 0x4112, 0x4112, 0x4112},     \
					.SRIC_CFGR_A4H		= {0x0003, 0x0003, 0x0003, 0x0003},     \
					.SRIC_CFGR_A6H		= {0x000C, 0x000C, 0x000C, 0x000C},     \
					.SRIC_CFGR_A8H		= {0x0030, 0x0030, 0x0030, 0x0030},     \
					.SRIC_CFGR_AAH		= {0x01C0, 0x01C0, 0x01C0, 0x01C0},     \
					.SRIC_CFGR_ACH		= {0x0013, 0x0013, 0x0013, 0x0013},     \
					.SRIC_CFGR_AEH		= {0x0013, 0x0013, 0x0013, 0x0013},     \
					.SRIC_CFGR_B0H		= {0x0013, 0x0013, 0x0013, 0x0013},     \
					.SRIC_CFGR_B2H		= {0x0013, 0x0013, 0x0013, 0x0013},     \
					.SRIC_CFGR_B4H		= {0x0909, 0x0909, 0x0909, 0x0909},     \
					.SRIC_CFGR_B6H		= {0x0909, 0x0909, 0x0909, 0x0909},     \
					.SRIC_CFGR_B8H		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_BAH		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_BCH		= {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},     \
					.SRIC_CFGR_FAH		= {0x0003, 0x0003, 0x0003, 0x0003},     \
					.SRIC_CFGR_FCH		= {0x0000, 0x0000, 0x0000, 0x0000},     \
					.SRIC_CFGR_FEH		= {0x0004, 0x0004, 0x0004, 0x0004},     \
				},                                                              \
				.R1_RegVal_LPWG =                                               \
				{                                                               \
					.SRIC_CFGR_00H		= {0x4190, 0x4190, 0x4190, 0x4190},    \
					.SRIC_CFGR_02H		= {0x0000, 0x0000, 0x0000, 0x0000},    \
					.SRIC_CFGR_04H		= {0x4061, 0x4061, 0x4061, 0x4061},    \
					.SRIC_CFGR_06H		= {0x1E3F, 0x1E3F, 0x1E3F, 0x1E3F},    \
					.SRIC_CFGR_08H		= {0x599B, 0x599B, 0x599B, 0x599B},    \
					.SRIC_CFGR_0AH		= {0x0700, 0x0700, 0x0700, 0x0700},    \
					.SRIC_CFGR_0CH		= {0x0700, 0x0700, 0x0700, 0x0700},    \
					.SRIC_CFGR_0EH		= {0x0000, 0x0000, 0x0000, 0x0000},    \
					.SRIC_CFGR_10H		= {0x0104, 0x0104, 0x0104, 0x0104},    \
					.SRIC_CFGR_12H		= {0x0912, 0x0912, 0x0912, 0x0912},    \
					.SRIC_CFGR_14H		= {0x2380, 0x2380, 0x2380, 0x2380},    \
					.SRIC_CFGR_16H		= {0x0050, 0x0050, 0x0050, 0x0050},    \
					.SRIC_CFGR_18H		= {0xAA90, 0xAA90, 0xAA90, 0xAA90},    \
					.SRIC_CFGR_1AH		= {0x401A, 0x4003, 0x4003, 0x4003},    \
					.SRIC_CFGR_1CH		= {0x4040, 0x4040, 0x4040, 0x4040},    \
					.SRIC_CFGR_1EH		= {0x0040, 0x0040, 0x0040, 0x0040},    \
					.SRIC_CFGR_20H		= {0x03E8, 0x03E8, 0x03E8, 0x03E8},    \
					.SRIC_CFGR_22H		= {0x044C, 0x044C, 0x044C, 0x044C},    \
					.SRIC_CFGR_24H		= {0x07D0, 0x07D0, 0x07D0, 0x07D0},    \
					.SRIC_CFGR_26H		= {0x0834, 0x0834, 0x0834, 0x0834},    \
					.SRIC_CFGR_28H		= {0x0BB8, 0x0BB8, 0x0BB8, 0x0BB8},    \
					.SRIC_CFGR_2AH		= {0x0C1C, 0x0C1C, 0x0C1C, 0x0C1C},    \
					.SRIC_CFGR_2CH		= {0x0FA0, 0x0FA0, 0x0FA0, 0x0FA0},    \
					.SRIC_CFGR_2EH		= {0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF},    \
					.SRIC_CFGR_30H		= {0x0000, 0x0000, 0x0000, 0x0000},    \
					.SRIC_CFGR_32H		= {0x0000, 0x0000, 0x0000, 0x0000},    \
					.SRIC_CFGR_34H		= {0x0000, 0x0000, 0x0000, 0x0000},    \
					.SRIC_CFGR_36H		= {0x0000, 0x0000, 0x0000, 0x0000},    \
					.SRIC_CFGR_38H		= {0x2040, 0x2040, 0x2040, 0x2040},    \
					.SRIC_CFGR_3AH		= {0x001B, 0x001B, 0x001B, 0x001B},    \
					.SRIC_CFGR_3CH		= {0x3040, 0x4040, 0x4040, 0x4040},    \
					.SRIC_CFGR_3EH		= {0x0004, 0x0004, 0x0004, 0x0004},    \
					.SRIC_CFGR_40H		= {0x0680, 0x0680, 0x0680, 0x0680},    \
					.SRIC_CFGR_42H		= {0x0614, 0x0614, 0x0614, 0x0614},    \
					.SRIC_CFGR_44H		= {0x001E, 0x001E, 0x001E, 0x001E},    \
					.SRIC_CFGR_46H		= {0x0001, 0x0001, 0x0001, 0x0001},    \
					.SRIC_CFGR_48H		= {0x0004, 0x0004, 0x0004, 0x0004},    \
					.SRIC_CFGR_4AH		= {0x000F, 0x000F, 0x000F, 0x000F},    \
					.SRIC_CFGR_4CH		= {0x00B8, 0x00B8, 0x00B8, 0x00B8},    \
					.SRIC_CFGR_4EH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_50H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_52H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_54H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_56H		= {0x0067, 0x0067, 0x0067, 0x0067},    \
					.SRIC_CFGR_58H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_5AH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_5CH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_5EH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_60H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_62H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_64H		= {0x0067, 0x0067, 0x0067, 0x0067},    \
					.SRIC_CFGR_66H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_68H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_6AH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_6CH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_6EH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_70H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_72H		= {0x0067, 0x0067, 0x0067, 0x0067},    \
					.SRIC_CFGR_74H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_76H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_78H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_7AH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_7CH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_7EH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_80H		= {0x0067, 0x0067, 0x0067, 0x0067},    \
					.SRIC_CFGR_82H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_84H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_86H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_88H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_8AH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_8CH		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_8EH		= {0x0067, 0x0067, 0x0067, 0x0067},    \
					.SRIC_CFGR_90H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_92H		= {0x6767, 0x6767, 0x6767, 0x6767},    \
					.SRIC_CFGR_94H		= {0x0000, 0x0000, 0x0000, 0x0000},    \
					.SRIC_CFGR_96H		= {0x0321, 0x0321, 0x0321, 0x0321},    \
					.SRIC_CFGR_98H		= {0x0654, 0x0654, 0x0654, 0x0654},    \
					.SRIC_CFGR_9AH		= {0x0987, 0x0987, 0x0987, 0x0987},    \
					.SRIC_CFGR_9CH		= {0x4112, 0x4112, 0x4112, 0x4112},    \
					.SRIC_CFGR_9EH		= {0x4112, 0x4112, 0x4112, 0x4112},    \
					.SRIC_CFGR_A0H		= {0x4112, 0x4112, 0x4112, 0x4112},    \
					.SRIC_CFGR_A2H		= {0x4112, 0x4112, 0x4112, 0x4112},    \
					.SRIC_CFGR_A4H		= {0x0003, 0x0003, 0x0003, 0x0003},    \
					.SRIC_CFGR_A6H		= {0x000C, 0x000C, 0x000C, 0x000C},    \
					.SRIC_CFGR_A8H		= {0x0030, 0x0030, 0x0030, 0x0030},    \
					.SRIC_CFGR_AAH		= {0x01C0, 0x01C0, 0x01C0, 0x01C0},    \
					.SRIC_CFGR_ACH		= {0x0013, 0x0013, 0x0013, 0x0013},    \
					.SRIC_CFGR_AEH		= {0x0013, 0x0013, 0x0013, 0x0013},    \
					.SRIC_CFGR_B0H		= {0x0013, 0x0013, 0x0013, 0x0013},    \
					.SRIC_CFGR_B2H		= {0x0013, 0x0013, 0x0013, 0x0013},    \
					.SRIC_CFGR_B4H		= {0x0909, 0x0909, 0x0909, 0x0909},    \
					.SRIC_CFGR_B6H		= {0x0909, 0x0909, 0x0909, 0x0909},    \
					.SRIC_CFGR_B8H		= {0x0000, 0x0000, 0x0000, 0x0000},    \
					.SRIC_CFGR_BAH		= {0x0000, 0x0000, 0x0000, 0x0000},    \
					.SRIC_CFGR_BCH		= {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},    \
					.SRIC_CFGR_FAH		= {0x0003, 0x0003, 0x0003, 0x0003},    \
					.SRIC_CFGR_FCH		= {0x0000, 0x0000, 0x0000, 0x0000},    \
					.SRIC_CFGR_FEH		= {0x0004, 0x0004, 0x0004, 0x0004},    \
				},
#endif /* __SW97400B_REGISTER_H_ */
