/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  remap_table.h
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

#ifndef _REMAP_TABLE_H_
#define _REMAP_TABLE_H_

#define FULL_SENSING_REMAP_TABLE \
	{0x0DF2,	0x0DF8,	0x0E06,	0x0E0C,	0x0E1A,	0x0E20,	0x0E2E,	0x0E76,	0x0E68,	0x0E62,	0x0E54,	0x0E4E,	0x0E40,	0x0E3A,	0x14B2,	0x14B8,	0x14C6,	0x14CC,	0x14DA,	0x14E0,	0x14EE,	0x1536,	0x1528,	0x1522,	0x1514,	0x150E,	0x1500,	0x14FA,	0x1B72,	0x1B78,	0x1B86,	0x1B8C,	0x1B9A,	0x1BA0,	0x1BAE,	0x1BF6,	0x1BE8,	0x1BE2,	0x1BD4,	0x1BCE,	0x1BC0,	0x1BBA,	0x2232,	0x2238,	0x2246,	0x224C,	0x225A,	0x2260,	0x226E,	0x22B6,	0x22A8,	0x22A2,	0x2294,	0x228E,	0x2280,	0x227A,	0x28F2,	0x28F8,	0x2906,	0x290C,	0x291A,	0x2920,	0x292E,	0x2976,	0x2968,	0x2962,	0x2954,	0x294E,	0x2940,	0x293A}, \
	{0x0DF0,	0x0DFE,	0x0E04,	0x0E12,	0x0E18,	0x0E26,	0x0E2C,	0x0E74,	0x0E6E,	0x0E60,	0x0E5A,	0x0E4C,	0x0E46,	0x0E38,	0x14B0,	0x14BE,	0x14C4,	0x14D2,	0x14D8,	0x14E6,	0x14EC,	0x1534,	0x152E,	0x1520,	0x151A,	0x150C,	0x1506,	0x14F8,	0x1B70,	0x1B7E,	0x1B84,	0x1B92,	0x1B98,	0x1BA6,	0x1BAC,	0x1BF4,	0x1BEE,	0x1BE0,	0x1BDA,	0x1BCC,	0x1BC6,	0x1BB8,	0x2230,	0x223E,	0x2244,	0x2252,	0x2258,	0x2266,	0x226C,	0x22B4,	0x22AE,	0x22A0,	0x229A,	0x228C,	0x2286,	0x2278,	0x28F0,	0x28FE,	0x2904,	0x2912,	0x2918,	0x2926,	0x292C,	0x2974,	0x296E,	0x2960,	0x295A,	0x294C,	0x2946,	0x2938}, \
	{0x0DF6,	0x0DFC,	0x0E0A,	0x0E10,	0x0E1E,	0x0E24,	0x0E32,	0x0E7A,	0x0E6C,	0x0E66,	0x0E58,	0x0E52,	0x0E44,	0x0E3E,	0x14B6,	0x14BC,	0x14CA,	0x14D0,	0x14DE,	0x14E4,	0x14F2,	0x153A,	0x152C,	0x1526,	0x1518,	0x1512,	0x1504,	0x14FE,	0x1B76,	0x1B7C,	0x1B8A,	0x1B90,	0x1B9E,	0x1BA4,	0x1BB2,	0x1BFA,	0x1BEC,	0x1BE6,	0x1BD8,	0x1BD2,	0x1BC4,	0x1BBE,	0x2236,	0x223C,	0x224A,	0x2250,	0x225E,	0x2264,	0x2272,	0x22BA,	0x22AC,	0x22A6,	0x2298,	0x2292,	0x2284,	0x227E,	0x28F6,	0x28FC,	0x290A,	0x2910,	0x291E,	0x2924,	0x2932,	0x297A,	0x296C,	0x2966,	0x2958,	0x2952,	0x2944,	0x293E}, \
	{0x0DF4,	0x0E02,	0x0E08,	0x0E16,	0x0E1C,	0x0E2A,	0x0E30,	0x0E78,	0x0E72,	0x0E64,	0x0E5E,	0x0E50,	0x0E4A,	0x0E3C,	0x14B4,	0x14C2,	0x14C8,	0x14D6,	0x14DC,	0x14EA,	0x14F0,	0x1538,	0x1532,	0x1524,	0x151E,	0x1510,	0x150A,	0x14FC,	0x1B74,	0x1B82,	0x1B88,	0x1B96,	0x1B9C,	0x1BAA,	0x1BB0,	0x1BF8,	0x1BF2,	0x1BE4,	0x1BDE,	0x1BD0,	0x1BCA,	0x1BBC,	0x2234,	0x2242,	0x2248,	0x2256,	0x225C,	0x226A,	0x2270,	0x22B8,	0x22B2,	0x22A4,	0x229E,	0x2290,	0x228A,	0x227C,	0x28F4,	0x2902,	0x2908,	0x2916,	0x291C,	0x292A,	0x2930,	0x2978,	0x2972,	0x2964,	0x295E,	0x2950,	0x294A,	0x293C}, \
	{0x0DFA,	0x0E00,	0x0E0E,	0x0E14,	0x0E22,	0x0E28,	0x0E36,	0x0E7E,	0x0E70,	0x0E6A,	0x0E5C,	0x0E56,	0x0E48,	0x0E42,	0x14BA,	0x14C0,	0x14CE,	0x14D4,	0x14E2,	0x14E8,	0x14F6,	0x153E,	0x1530,	0x152A,	0x151C,	0x1516,	0x1508,	0x1502,	0x1B7A,	0x1B80,	0x1B8E,	0x1B94,	0x1BA2,	0x1BA8,	0x1BB6,	0x1BFE,	0x1BF0,	0x1BEA,	0x1BDC,	0x1BD6,	0x1BC8,	0x1BC2,	0x223A,	0x2240,	0x224E,	0x2254,	0x2262,	0x2268,	0x2276,	0x22BE,	0x22B0,	0x22AA,	0x229C,	0x2296,	0x2288,	0x2282,	0x28FA,	0x2900,	0x290E,	0x2914,	0x2922,	0x2928,	0x2936,	0x297E,	0x2970,	0x296A,	0x295C,	0x2956,	0x2948,	0x2942}, \
	{0x0E82,	0x0E88,	0x0E96,	0x0E9C,	0x0EAA,	0x0EB0,	0x0EBE,	0x0F06,	0x0EF8,	0x0EF2,	0x0EE4,	0x0EDE,	0x0ED0,	0x0ECA,	0x1542,	0x1548,	0x1556,	0x155C,	0x156A,	0x1570,	0x157E,	0x15C6,	0x15B8,	0x15B2,	0x15A4,	0x159E,	0x1590,	0x158A,	0x1C02,	0x1C08,	0x1C16,	0x1C1C,	0x1C2A,	0x1C30,	0x1C3E,	0x1C86,	0x1C78,	0x1C72,	0x1C64,	0x1C5E,	0x1C50,	0x1C4A,	0x22C2,	0x22C8,	0x22D6,	0x22DC,	0x22EA,	0x22F0,	0x22FE,	0x2346,	0x2338,	0x2332,	0x2324,	0x231E,	0x2310,	0x230A,	0x2982,	0x2988,	0x2996,	0x299C,	0x29AA,	0x29B0,	0x29BE,	0x2A06,	0x29F8,	0x29F2,	0x29E4,	0x29DE,	0x29D0,	0x29CA}, \
	{0x0E80,	0x0E8E,	0x0E94,	0x0EA2,	0x0EA8,	0x0EB6,	0x0EBC,	0x0F04,	0x0EFE,	0x0EF0,	0x0EEA,	0x0EDC,	0x0ED6,	0x0EC8,	0x1540,	0x154E,	0x1554,	0x1562,	0x1568,	0x1576,	0x157C,	0x15C4,	0x15BE,	0x15B0,	0x15AA,	0x159C,	0x1596,	0x1588,	0x1C00,	0x1C0E,	0x1C14,	0x1C22,	0x1C28,	0x1C36,	0x1C3C,	0x1C84,	0x1C7E,	0x1C70,	0x1C6A,	0x1C5C,	0x1C56,	0x1C48,	0x22C0,	0x22CE,	0x22D4,	0x22E2,	0x22E8,	0x22F6,	0x22FC,	0x2344,	0x233E,	0x2330,	0x232A,	0x231C,	0x2316,	0x2308,	0x2980,	0x298E,	0x2994,	0x29A2,	0x29A8,	0x29B6,	0x29BC,	0x2A04,	0x29FE,	0x29F0,	0x29EA,	0x29DC,	0x29D6,	0x29C8}, \
	{0x0E86,	0x0E8C,	0x0E9A,	0x0EA0,	0x0EAE,	0x0EB4,	0x0EC2,	0x0F0A,	0x0EFC,	0x0EF6,	0x0EE8,	0x0EE2,	0x0ED4,	0x0ECE,	0x1546,	0x154C,	0x155A,	0x1560,	0x156E,	0x1574,	0x1582,	0x15CA,	0x15BC,	0x15B6,	0x15A8,	0x15A2,	0x1594,	0x158E,	0x1C06,	0x1C0C,	0x1C1A,	0x1C20,	0x1C2E,	0x1C34,	0x1C42,	0x1C8A,	0x1C7C,	0x1C76,	0x1C68,	0x1C62,	0x1C54,	0x1C4E,	0x22C6,	0x22CC,	0x22DA,	0x22E0,	0x22EE,	0x22F4,	0x2302,	0x234A,	0x233C,	0x2336,	0x2328,	0x2322,	0x2314,	0x230E,	0x2986,	0x298C,	0x299A,	0x29A0,	0x29AE,	0x29B4,	0x29C2,	0x2A0A,	0x29FC,	0x29F6,	0x29E8,	0x29E2,	0x29D4,	0x29CE}, \
	{0x0E84,	0x0E92,	0x0E98,	0x0EA6,	0x0EAC,	0x0EBA,	0x0EC0,	0x0F08,	0x0F02,	0x0EF4,	0x0EEE,	0x0EE0,	0x0EDA,	0x0ECC,	0x1544,	0x1552,	0x1558,	0x1566,	0x156C,	0x157A,	0x1580,	0x15C8,	0x15C2,	0x15B4,	0x15AE,	0x15A0,	0x159A,	0x158C,	0x1C04,	0x1C12,	0x1C18,	0x1C26,	0x1C2C,	0x1C3A,	0x1C40,	0x1C88,	0x1C82,	0x1C74,	0x1C6E,	0x1C60,	0x1C5A,	0x1C4C,	0x22C4,	0x22D2,	0x22D8,	0x22E6,	0x22EC,	0x22FA,	0x2300,	0x2348,	0x2342,	0x2334,	0x232E,	0x2320,	0x231A,	0x230C,	0x2984,	0x2992,	0x2998,	0x29A6,	0x29AC,	0x29BA,	0x29C0,	0x2A08,	0x2A02,	0x29F4,	0x29EE,	0x29E0,	0x29DA,	0x29CC}, \
	{0x0E8A,	0x0E90,	0x0E9E,	0x0EA4,	0x0EB2,	0x0EB8,	0x0EC6,	0x0F0E,	0x0F00,	0x0EFA,	0x0EEC,	0x0EE6,	0x0ED8,	0x0ED2,	0x154A,	0x1550,	0x155E,	0x1564,	0x1572,	0x1578,	0x1586,	0x15CE,	0x15C0,	0x15BA,	0x15AC,	0x15A6,	0x1598,	0x1592,	0x1C0A,	0x1C10,	0x1C1E,	0x1C24,	0x1C32,	0x1C38,	0x1C46,	0x1C8E,	0x1C80,	0x1C7A,	0x1C6C,	0x1C66,	0x1C58,	0x1C52,	0x22CA,	0x22D0,	0x22DE,	0x22E4,	0x22F2,	0x22F8,	0x2306,	0x234E,	0x2340,	0x233A,	0x232C,	0x2326,	0x2318,	0x2312,	0x298A,	0x2990,	0x299E,	0x29A4,	0x29B2,	0x29B8,	0x29C6,	0x2A0E,	0x2A00,	0x29FA,	0x29EC,	0x29E6,	0x29D8,	0x29D2}, \
	{0x0F12,	0x0F18,	0x0F26,	0x0F2C,	0x0F3A,	0x0F40,	0x0F4E,	0x0F96,	0x0F88,	0x0F82,	0x0F74,	0x0F6E,	0x0F60,	0x0F5A,	0x15D2,	0x15D8,	0x15E6,	0x15EC,	0x15FA,	0x1600,	0x160E,	0x1656,	0x1648,	0x1642,	0x1634,	0x162E,	0x1620,	0x161A,	0x1C92,	0x1C98,	0x1CA6,	0x1CAC,	0x1CBA,	0x1CC0,	0x1CCE,	0x1D16,	0x1D08,	0x1D02,	0x1CF4,	0x1CEE,	0x1CE0,	0x1CDA,	0x2352,	0x2358,	0x2366,	0x236C,	0x237A,	0x2380,	0x238E,	0x23D6,	0x23C8,	0x23C2,	0x23B4,	0x23AE,	0x23A0,	0x239A,	0x2A12,	0x2A18,	0x2A26,	0x2A2C,	0x2A3A,	0x2A40,	0x2A4E,	0x2A96,	0x2A88,	0x2A82,	0x2A74,	0x2A6E,	0x2A60,	0x2A5A}, \
	{0x0F10,	0x0F1E,	0x0F24,	0x0F32,	0x0F38,	0x0F46,	0x0F4C,	0x0F94,	0x0F8E,	0x0F80,	0x0F7A,	0x0F6C,	0x0F66,	0x0F58,	0x15D0,	0x15DE,	0x15E4,	0x15F2,	0x15F8,	0x1606,	0x160C,	0x1654,	0x164E,	0x1640,	0x163A,	0x162C,	0x1626,	0x1618,	0x1C90,	0x1C9E,	0x1CA4,	0x1CB2,	0x1CB8,	0x1CC6,	0x1CCC,	0x1D14,	0x1D0E,	0x1D00,	0x1CFA,	0x1CEC,	0x1CE6,	0x1CD8,	0x2350,	0x235E,	0x2364,	0x2372,	0x2378,	0x2386,	0x238C,	0x23D4,	0x23CE,	0x23C0,	0x23BA,	0x23AC,	0x23A6,	0x2398,	0x2A10,	0x2A1E,	0x2A24,	0x2A32,	0x2A38,	0x2A46,	0x2A4C,	0x2A94,	0x2A8E,	0x2A80,	0x2A7A,	0x2A6C,	0x2A66,	0x2A58}, \
	{0x0F16,	0x0F1C,	0x0F2A,	0x0F30,	0x0F3E,	0x0F44,	0x0F52,	0x0F9A,	0x0F8C,	0x0F86,	0x0F78,	0x0F72,	0x0F64,	0x0F5E,	0x15D6,	0x15DC,	0x15EA,	0x15F0,	0x15FE,	0x1604,	0x1612,	0x165A,	0x164C,	0x1646,	0x1638,	0x1632,	0x1624,	0x161E,	0x1C96,	0x1C9C,	0x1CAA,	0x1CB0,	0x1CBE,	0x1CC4,	0x1CD2,	0x1D1A,	0x1D0C,	0x1D06,	0x1CF8,	0x1CF2,	0x1CE4,	0x1CDE,	0x2356,	0x235C,	0x236A,	0x2370,	0x237E,	0x2384,	0x2392,	0x23DA,	0x23CC,	0x23C6,	0x23B8,	0x23B2,	0x23A4,	0x239E,	0x2A16,	0x2A1C,	0x2A2A,	0x2A30,	0x2A3E,	0x2A44,	0x2A52,	0x2A9A,	0x2A8C,	0x2A86,	0x2A78,	0x2A72,	0x2A64,	0x2A5E}, \
	{0x0F14,	0x0F22,	0x0F28,	0x0F36,	0x0F3C,	0x0F4A,	0x0F50,	0x0F98,	0x0F92,	0x0F84,	0x0F7E,	0x0F70,	0x0F6A,	0x0F5C,	0x15D4,	0x15E2,	0x15E8,	0x15F6,	0x15FC,	0x160A,	0x1610,	0x1658,	0x1652,	0x1644,	0x163E,	0x1630,	0x162A,	0x161C,	0x1C94,	0x1CA2,	0x1CA8,	0x1CB6,	0x1CBC,	0x1CCA,	0x1CD0,	0x1D18,	0x1D12,	0x1D04,	0x1CFE,	0x1CF0,	0x1CEA,	0x1CDC,	0x2354,	0x2362,	0x2368,	0x2376,	0x237C,	0x238A,	0x2390,	0x23D8,	0x23D2,	0x23C4,	0x23BE,	0x23B0,	0x23AA,	0x239C,	0x2A14,	0x2A22,	0x2A28,	0x2A36,	0x2A3C,	0x2A4A,	0x2A50,	0x2A98,	0x2A92,	0x2A84,	0x2A7E,	0x2A70,	0x2A6A,	0x2A5C}, \
	{0x0F1A,	0x0F20,	0x0F2E,	0x0F34,	0x0F42,	0x0F48,	0x0F56,	0x0F9E,	0x0F90,	0x0F8A,	0x0F7C,	0x0F76,	0x0F68,	0x0F62,	0x15DA,	0x15E0,	0x15EE,	0x15F4,	0x1602,	0x1608,	0x1616,	0x165E,	0x1650,	0x164A,	0x163C,	0x1636,	0x1628,	0x1622,	0x1C9A,	0x1CA0,	0x1CAE,	0x1CB4,	0x1CC2,	0x1CC8,	0x1CD6,	0x1D1E,	0x1D10,	0x1D0A,	0x1CFC,	0x1CF6,	0x1CE8,	0x1CE2,	0x235A,	0x2360,	0x236E,	0x2374,	0x2382,	0x2388,	0x2396,	0x23DE,	0x23D0,	0x23CA,	0x23BC,	0x23B6,	0x23A8,	0x23A2,	0x2A1A,	0x2A20,	0x2A2E,	0x2A34,	0x2A42,	0x2A48,	0x2A56,	0x2A9E,	0x2A90,	0x2A8A,	0x2A7C,	0x2A76,	0x2A68,	0x2A62}, \
	{0x0FA2,	0x0FA8,	0x0FB6,	0x0FBC,	0x0FCA,	0x0FD0,	0x0FDE,	0x1026,	0x1018,	0x1012,	0x1004,	0x0FFE,	0x0FF0,	0x0FEA,	0x1662,	0x1668,	0x1676,	0x167C,	0x168A,	0x1690,	0x169E,	0x16E6,	0x16D8,	0x16D2,	0x16C4,	0x16BE,	0x16B0,	0x16AA,	0x1D22,	0x1D28,	0x1D36,	0x1D3C,	0x1D4A,	0x1D50,	0x1D5E,	0x1DA6,	0x1D98,	0x1D92,	0x1D84,	0x1D7E,	0x1D70,	0x1D6A,	0x23E2,	0x23E8,	0x23F6,	0x23FC,	0x240A,	0x2410,	0x241E,	0x2466,	0x2458,	0x2452,	0x2444,	0x243E,	0x2430,	0x242A,	0x2AA2,	0x2AA8,	0x2AB6,	0x2ABC,	0x2ACA,	0x2AD0,	0x2ADE,	0x2B26,	0x2B18,	0x2B12,	0x2B04,	0x2AFE,	0x2AF0,	0x2AEA}, \
	{0x0FA0,	0x0FAE,	0x0FB4,	0x0FC2,	0x0FC8,	0x0FD6,	0x0FDC,	0x1024,	0x101E,	0x1010,	0x100A,	0x0FFC,	0x0FF6,	0x0FE8,	0x1660,	0x166E,	0x1674,	0x1682,	0x1688,	0x1696,	0x169C,	0x16E4,	0x16DE,	0x16D0,	0x16CA,	0x16BC,	0x16B6,	0x16A8,	0x1D20,	0x1D2E,	0x1D34,	0x1D42,	0x1D48,	0x1D56,	0x1D5C,	0x1DA4,	0x1D9E,	0x1D90,	0x1D8A,	0x1D7C,	0x1D76,	0x1D68,	0x23E0,	0x23EE,	0x23F4,	0x2402,	0x2408,	0x2416,	0x241C,	0x2464,	0x245E,	0x2450,	0x244A,	0x243C,	0x2436,	0x2428,	0x2AA0,	0x2AAE,	0x2AB4,	0x2AC2,	0x2AC8,	0x2AD6,	0x2ADC,	0x2B24,	0x2B1E,	0x2B10,	0x2B0A,	0x2AFC,	0x2AF6,	0x2AE8}, \
	{0x0FA6,	0x0FAC,	0x0FBA,	0x0FC0,	0x0FCE,	0x0FD4,	0x0FE2,	0x102A,	0x101C,	0x1016,	0x1008,	0x1002,	0x0FF4,	0x0FEE,	0x1666,	0x166C,	0x167A,	0x1680,	0x168E,	0x1694,	0x16A2,	0x16EA,	0x16DC,	0x16D6,	0x16C8,	0x16C2,	0x16B4,	0x16AE,	0x1D26,	0x1D2C,	0x1D3A,	0x1D40,	0x1D4E,	0x1D54,	0x1D62,	0x1DAA,	0x1D9C,	0x1D96,	0x1D88,	0x1D82,	0x1D74,	0x1D6E,	0x23E6,	0x23EC,	0x23FA,	0x2400,	0x240E,	0x2414,	0x2422,	0x246A,	0x245C,	0x2456,	0x2448,	0x2442,	0x2434,	0x242E,	0x2AA6,	0x2AAC,	0x2ABA,	0x2AC0,	0x2ACE,	0x2AD4,	0x2AE2,	0x2B2A,	0x2B1C,	0x2B16,	0x2B08,	0x2B02,	0x2AF4,	0x2AEE}, \
	{0x0FA4,	0x0FB2,	0x0FB8,	0x0FC6,	0x0FCC,	0x0FDA,	0x0FE0,	0x1028,	0x1022,	0x1014,	0x100E,	0x1000,	0x0FFA,	0x0FEC,	0x1664,	0x1672,	0x1678,	0x1686,	0x168C,	0x169A,	0x16A0,	0x16E8,	0x16E2,	0x16D4,	0x16CE,	0x16C0,	0x16BA,	0x16AC,	0x1D24,	0x1D32,	0x1D38,	0x1D46,	0x1D4C,	0x1D5A,	0x1D60,	0x1DA8,	0x1DA2,	0x1D94,	0x1D8E,	0x1D80,	0x1D7A,	0x1D6C,	0x23E4,	0x23F2,	0x23F8,	0x2406,	0x240C,	0x241A,	0x2420,	0x2468,	0x2462,	0x2454,	0x244E,	0x2440,	0x243A,	0x242C,	0x2AA4,	0x2AB2,	0x2AB8,	0x2AC6,	0x2ACC,	0x2ADA,	0x2AE0,	0x2B28,	0x2B22,	0x2B14,	0x2B0E,	0x2B00,	0x2AFA,	0x2AEC}, \
	{0x0FAA,	0x0FB0,	0x0FBE,	0x0FC4,	0x0FD2,	0x0FD8,	0x0FE6,	0x102E,	0x1020,	0x101A,	0x100C,	0x1006,	0x0FF8,	0x0FF2,	0x166A,	0x1670,	0x167E,	0x1684,	0x1692,	0x1698,	0x16A6,	0x16EE,	0x16E0,	0x16DA,	0x16CC,	0x16C6,	0x16B8,	0x16B2,	0x1D2A,	0x1D30,	0x1D3E,	0x1D44,	0x1D52,	0x1D58,	0x1D66,	0x1DAE,	0x1DA0,	0x1D9A,	0x1D8C,	0x1D86,	0x1D78,	0x1D72,	0x23EA,	0x23F0,	0x23FE,	0x2404,	0x2412,	0x2418,	0x2426,	0x246E,	0x2460,	0x245A,	0x244C,	0x2446,	0x2438,	0x2432,	0x2AAA,	0x2AB0,	0x2ABE,	0x2AC4,	0x2AD2,	0x2AD8,	0x2AE6,	0x2B2E,	0x2B20,	0x2B1A,	0x2B0C,	0x2B06,	0x2AF8,	0x2AF2}, \
	{0x1032,	0x1038,	0x1046,	0x104C,	0x105A,	0x1060,	0x106E,	0x10B6,	0x10A8,	0x10A2,	0x1094,	0x108E,	0x1080,	0x107A,	0x16F2,	0x16F8,	0x1706,	0x170C,	0x171A,	0x1720,	0x172E,	0x1776,	0x1768,	0x1762,	0x1754,	0x174E,	0x1740,	0x173A,	0x1DB2,	0x1DB8,	0x1DC6,	0x1DCC,	0x1DDA,	0x1DE0,	0x1DEE,	0x1E36,	0x1E28,	0x1E22,	0x1E14,	0x1E0E,	0x1E00,	0x1DFA,	0x2472,	0x2478,	0x2486,	0x248C,	0x249A,	0x24A0,	0x24AE,	0x24F6,	0x24E8,	0x24E2,	0x24D4,	0x24CE,	0x24C0,	0x24BA,	0x2B32,	0x2B38,	0x2B46,	0x2B4C,	0x2B5A,	0x2B60,	0x2B6E,	0x2BB6,	0x2BA8,	0x2BA2,	0x2B94,	0x2B8E,	0x2B80,	0x2B7A}, \
	{0x1030,	0x103E,	0x1044,	0x1052,	0x1058,	0x1066,	0x106C,	0x10B4,	0x10AE,	0x10A0,	0x109A,	0x108C,	0x1086,	0x1078,	0x16F0,	0x16FE,	0x1704,	0x1712,	0x1718,	0x1726,	0x172C,	0x1774,	0x176E,	0x1760,	0x175A,	0x174C,	0x1746,	0x1738,	0x1DB0,	0x1DBE,	0x1DC4,	0x1DD2,	0x1DD8,	0x1DE6,	0x1DEC,	0x1E34,	0x1E2E,	0x1E20,	0x1E1A,	0x1E0C,	0x1E06,	0x1DF8,	0x2470,	0x247E,	0x2484,	0x2492,	0x2498,	0x24A6,	0x24AC,	0x24F4,	0x24EE,	0x24E0,	0x24DA,	0x24CC,	0x24C6,	0x24B8,	0x2B30,	0x2B3E,	0x2B44,	0x2B52,	0x2B58,	0x2B66,	0x2B6C,	0x2BB4,	0x2BAE,	0x2BA0,	0x2B9A,	0x2B8C,	0x2B86,	0x2B78}, \
	{0x1036,	0x103C,	0x104A,	0x1050,	0x105E,	0x1064,	0x1072,	0x10BA,	0x10AC,	0x10A6,	0x1098,	0x1092,	0x1084,	0x107E,	0x16F6,	0x16FC,	0x170A,	0x1710,	0x171E,	0x1724,	0x1732,	0x177A,	0x176C,	0x1766,	0x1758,	0x1752,	0x1744,	0x173E,	0x1DB6,	0x1DBC,	0x1DCA,	0x1DD0,	0x1DDE,	0x1DE4,	0x1DF2,	0x1E3A,	0x1E2C,	0x1E26,	0x1E18,	0x1E12,	0x1E04,	0x1DFE,	0x2476,	0x247C,	0x248A,	0x2490,	0x249E,	0x24A4,	0x24B2,	0x24FA,	0x24EC,	0x24E6,	0x24D8,	0x24D2,	0x24C4,	0x24BE,	0x2B36,	0x2B3C,	0x2B4A,	0x2B50,	0x2B5E,	0x2B64,	0x2B72,	0x2BBA,	0x2BAC,	0x2BA6,	0x2B98,	0x2B92,	0x2B84,	0x2B7E}, \
	{0x1034,	0x1042,	0x1048,	0x1056,	0x105C,	0x106A,	0x1070,	0x10B8,	0x10B2,	0x10A4,	0x109E,	0x1090,	0x108A,	0x107C,	0x16F4,	0x1702,	0x1708,	0x1716,	0x171C,	0x172A,	0x1730,	0x1778,	0x1772,	0x1764,	0x175E,	0x1750,	0x174A,	0x173C,	0x1DB4,	0x1DC2,	0x1DC8,	0x1DD6,	0x1DDC,	0x1DEA,	0x1DF0,	0x1E38,	0x1E32,	0x1E24,	0x1E1E,	0x1E10,	0x1E0A,	0x1DFC,	0x2474,	0x2482,	0x2488,	0x2496,	0x249C,	0x24AA,	0x24B0,	0x24F8,	0x24F2,	0x24E4,	0x24DE,	0x24D0,	0x24CA,	0x24BC,	0x2B34,	0x2B42,	0x2B48,	0x2B56,	0x2B5C,	0x2B6A,	0x2B70,	0x2BB8,	0x2BB2,	0x2BA4,	0x2B9E,	0x2B90,	0x2B8A,	0x2B7C}, \
	{0x103A,	0x1040,	0x104E,	0x1054,	0x1062,	0x1068,	0x1076,	0x10BE,	0x10B0,	0x10AA,	0x109C,	0x1096,	0x1088,	0x1082,	0x16FA,	0x1700,	0x170E,	0x1714,	0x1722,	0x1728,	0x1736,	0x177E,	0x1770,	0x176A,	0x175C,	0x1756,	0x1748,	0x1742,	0x1DBA,	0x1DC0,	0x1DCE,	0x1DD4,	0x1DE2,	0x1DE8,	0x1DF6,	0x1E3E,	0x1E30,	0x1E2A,	0x1E1C,	0x1E16,	0x1E08,	0x1E02,	0x247A,	0x2480,	0x248E,	0x2494,	0x24A2,	0x24A8,	0x24B6,	0x24FE,	0x24F0,	0x24EA,	0x24DC,	0x24D6,	0x24C8,	0x24C2,	0x2B3A,	0x2B40,	0x2B4E,	0x2B54,	0x2B62,	0x2B68,	0x2B76,	0x2BBE,	0x2BB0,	0x2BAA,	0x2B9C,	0x2B96,	0x2B88,	0x2B82}, \
	{0x10C2,	0x10C8,	0x10D6,	0x10DC,	0x10EA,	0x10F0,	0x10FE,	0x1146,	0x1138,	0x1132,	0x1124,	0x111E,	0x1110,	0x110A,	0x1782,	0x1788,	0x1796,	0x179C,	0x17AA,	0x17B0,	0x17BE,	0x1806,	0x17F8,	0x17F2,	0x17E4,	0x17DE,	0x17D0,	0x17CA,	0x1E42,	0x1E48,	0x1E56,	0x1E5C,	0x1E6A,	0x1E70,	0x1E7E,	0x1EC6,	0x1EB8,	0x1EB2,	0x1EA4,	0x1E9E,	0x1E90,	0x1E8A,	0x2502,	0x2508,	0x2516,	0x251C,	0x252A,	0x2530,	0x253E,	0x2586,	0x2578,	0x2572,	0x2564,	0x255E,	0x2550,	0x254A,	0x2BC2,	0x2BC8,	0x2BD6,	0x2BDC,	0x2BEA,	0x2BF0,	0x2BFE,	0x2C46,	0x2C38,	0x2C32,	0x2C24,	0x2C1E,	0x2C10,	0x2C0A}, \
	{0x10C0,	0x10CE,	0x10D4,	0x10E2,	0x10E8,	0x10F6,	0x10FC,	0x1144,	0x113E,	0x1130,	0x112A,	0x111C,	0x1116,	0x1108,	0x1780,	0x178E,	0x1794,	0x17A2,	0x17A8,	0x17B6,	0x17BC,	0x1804,	0x17FE,	0x17F0,	0x17EA,	0x17DC,	0x17D6,	0x17C8,	0x1E40,	0x1E4E,	0x1E54,	0x1E62,	0x1E68,	0x1E76,	0x1E7C,	0x1EC4,	0x1EBE,	0x1EB0,	0x1EAA,	0x1E9C,	0x1E96,	0x1E88,	0x2500,	0x250E,	0x2514,	0x2522,	0x2528,	0x2536,	0x253C,	0x2584,	0x257E,	0x2570,	0x256A,	0x255C,	0x2556,	0x2548,	0x2BC0,	0x2BCE,	0x2BD4,	0x2BE2,	0x2BE8,	0x2BF6,	0x2BFC,	0x2C44,	0x2C3E,	0x2C30,	0x2C2A,	0x2C1C,	0x2C16,	0x2C08}, \
	{0x10C6,	0x10CC,	0x10DA,	0x10E0,	0x10EE,	0x10F4,	0x1102,	0x114A,	0x113C,	0x1136,	0x1128,	0x1122,	0x1114,	0x110E,	0x1786,	0x178C,	0x179A,	0x17A0,	0x17AE,	0x17B4,	0x17C2,	0x180A,	0x17FC,	0x17F6,	0x17E8,	0x17E2,	0x17D4,	0x17CE,	0x1E46,	0x1E4C,	0x1E5A,	0x1E60,	0x1E6E,	0x1E74,	0x1E82,	0x1ECA,	0x1EBC,	0x1EB6,	0x1EA8,	0x1EA2,	0x1E94,	0x1E8E,	0x2506,	0x250C,	0x251A,	0x2520,	0x252E,	0x2534,	0x2542,	0x258A,	0x257C,	0x2576,	0x2568,	0x2562,	0x2554,	0x254E,	0x2BC6,	0x2BCC,	0x2BDA,	0x2BE0,	0x2BEE,	0x2BF4,	0x2C02,	0x2C4A,	0x2C3C,	0x2C36,	0x2C28,	0x2C22,	0x2C14,	0x2C0E}, \
	{0x10C4,	0x10D2,	0x10D8,	0x10E6,	0x10EC,	0x10FA,	0x1100,	0x1148,	0x1142,	0x1134,	0x112E,	0x1120,	0x111A,	0x110C,	0x1784,	0x1792,	0x1798,	0x17A6,	0x17AC,	0x17BA,	0x17C0,	0x1808,	0x1802,	0x17F4,	0x17EE,	0x17E0,	0x17DA,	0x17CC,	0x1E44,	0x1E52,	0x1E58,	0x1E66,	0x1E6C,	0x1E7A,	0x1E80,	0x1EC8,	0x1EC2,	0x1EB4,	0x1EAE,	0x1EA0,	0x1E9A,	0x1E8C,	0x2504,	0x2512,	0x2518,	0x2526,	0x252C,	0x253A,	0x2540,	0x2588,	0x2582,	0x2574,	0x256E,	0x2560,	0x255A,	0x254C,	0x2BC4,	0x2BD2,	0x2BD8,	0x2BE6,	0x2BEC,	0x2BFA,	0x2C00,	0x2C48,	0x2C42,	0x2C34,	0x2C2E,	0x2C20,	0x2C1A,	0x2C0C}, \
	{0x10CA,	0x10D0,	0x10DE,	0x10E4,	0x10F2,	0x10F8,	0x1106,	0x114E,	0x1140,	0x113A,	0x112C,	0x1126,	0x1118,	0x1112,	0x178A,	0x1790,	0x179E,	0x17A4,	0x17B2,	0x17B8,	0x17C6,	0x180E,	0x1800,	0x17FA,	0x17EC,	0x17E6,	0x17D8,	0x17D2,	0x1E4A,	0x1E50,	0x1E5E,	0x1E64,	0x1E72,	0x1E78,	0x1E86,	0x1ECE,	0x1EC0,	0x1EBA,	0x1EAC,	0x1EA6,	0x1E98,	0x1E92,	0x250A,	0x2510,	0x251E,	0x2524,	0x2532,	0x2538,	0x2546,	0x258E,	0x2580,	0x257A,	0x256C,	0x2566,	0x2558,	0x2552,	0x2BCA,	0x2BD0,	0x2BDE,	0x2BE4,	0x2BF2,	0x2BF8,	0x2C06,	0x2C4E,	0x2C40,	0x2C3A,	0x2C2C,	0x2C26,	0x2C18,	0x2C12}, \
	{0x1152,	0x1158,	0x1166,	0x116C,	0x117A,	0x1180,	0x118E,	0x11D6,	0x11C8,	0x11C2,	0x11B4,	0x11AE,	0x11A0,	0x119A,	0x1812,	0x1818,	0x1826,	0x182C,	0x183A,	0x1840,	0x184E,	0x1896,	0x1888,	0x1882,	0x1874,	0x186E,	0x1860,	0x185A,	0x1ED2,	0x1ED8,	0x1EE6,	0x1EEC,	0x1EFA,	0x1F00,	0x1F0E,	0x1F56,	0x1F48,	0x1F42,	0x1F34,	0x1F2E,	0x1F20,	0x1F1A,	0x2592,	0x2598,	0x25A6,	0x25AC,	0x25BA,	0x25C0,	0x25CE,	0x2616,	0x2608,	0x2602,	0x25F4,	0x25EE,	0x25E0,	0x25DA,	0x2C52,	0x2C58,	0x2C66,	0x2C6C,	0x2C7A,	0x2C80,	0x2C8E,	0x2CD6,	0x2CC8,	0x2CC2,	0x2CB4,	0x2CAE,	0x2CA0,	0x2C9A}, \
	{0x1150,	0x115E,	0x1164,	0x1172,	0x1178,	0x1186,	0x118C,	0x11D4,	0x11CE,	0x11C0,	0x11BA,	0x11AC,	0x11A6,	0x1198,	0x1810,	0x181E,	0x1824,	0x1832,	0x1838,	0x1846,	0x184C,	0x1894,	0x188E,	0x1880,	0x187A,	0x186C,	0x1866,	0x1858,	0x1ED0,	0x1EDE,	0x1EE4,	0x1EF2,	0x1EF8,	0x1F06,	0x1F0C,	0x1F54,	0x1F4E,	0x1F40,	0x1F3A,	0x1F2C,	0x1F26,	0x1F18,	0x2590,	0x259E,	0x25A4,	0x25B2,	0x25B8,	0x25C6,	0x25CC,	0x2614,	0x260E,	0x2600,	0x25FA,	0x25EC,	0x25E6,	0x25D8,	0x2C50,	0x2C5E,	0x2C64,	0x2C72,	0x2C78,	0x2C86,	0x2C8C,	0x2CD4,	0x2CCE,	0x2CC0,	0x2CBA,	0x2CAC,	0x2CA6,	0x2C98}, \
	{0x1156,	0x115C,	0x116A,	0x1170,	0x117E,	0x1184,	0x1192,	0x11DA,	0x11CC,	0x11C6,	0x11B8,	0x11B2,	0x11A4,	0x119E,	0x1816,	0x181C,	0x182A,	0x1830,	0x183E,	0x1844,	0x1852,	0x189A,	0x188C,	0x1886,	0x1878,	0x1872,	0x1864,	0x185E,	0x1ED6,	0x1EDC,	0x1EEA,	0x1EF0,	0x1EFE,	0x1F04,	0x1F12,	0x1F5A,	0x1F4C,	0x1F46,	0x1F38,	0x1F32,	0x1F24,	0x1F1E,	0x2596,	0x259C,	0x25AA,	0x25B0,	0x25BE,	0x25C4,	0x25D2,	0x261A,	0x260C,	0x2606,	0x25F8,	0x25F2,	0x25E4,	0x25DE,	0x2C56,	0x2C5C,	0x2C6A,	0x2C70,	0x2C7E,	0x2C84,	0x2C92,	0x2CDA,	0x2CCC,	0x2CC6,	0x2CB8,	0x2CB2,	0x2CA4,	0x2C9E}, \
	{0x1154,	0x1162,	0x1168,	0x1176,	0x117C,	0x118A,	0x1190,	0x11D8,	0x11D2,	0x11C4,	0x11BE,	0x11B0,	0x11AA,	0x119C,	0x1814,	0x1822,	0x1828,	0x1836,	0x183C,	0x184A,	0x1850,	0x1898,	0x1892,	0x1884,	0x187E,	0x1870,	0x186A,	0x185C,	0x1ED4,	0x1EE2,	0x1EE8,	0x1EF6,	0x1EFC,	0x1F0A,	0x1F10,	0x1F58,	0x1F52,	0x1F44,	0x1F3E,	0x1F30,	0x1F2A,	0x1F1C,	0x2594,	0x25A2,	0x25A8,	0x25B6,	0x25BC,	0x25CA,	0x25D0,	0x2618,	0x2612,	0x2604,	0x25FE,	0x25F0,	0x25EA,	0x25DC,	0x2C54,	0x2C62,	0x2C68,	0x2C76,	0x2C7C,	0x2C8A,	0x2C90,	0x2CD8,	0x2CD2,	0x2CC4,	0x2CBE,	0x2CB0,	0x2CAA,	0x2C9C}, \
	{0x115A,	0x1160,	0x116E,	0x1174,	0x1182,	0x1188,	0x1196,	0x11DE,	0x11D0,	0x11CA,	0x11BC,	0x11B6,	0x11A8,	0x11A2,	0x181A,	0x1820,	0x182E,	0x1834,	0x1842,	0x1848,	0x1856,	0x189E,	0x1890,	0x188A,	0x187C,	0x1876,	0x1868,	0x1862,	0x1EDA,	0x1EE0,	0x1EEE,	0x1EF4,	0x1F02,	0x1F08,	0x1F16,	0x1F5E,	0x1F50,	0x1F4A,	0x1F3C,	0x1F36,	0x1F28,	0x1F22,	0x259A,	0x25A0,	0x25AE,	0x25B4,	0x25C2,	0x25C8,	0x25D6,	0x261E,	0x2610,	0x260A,	0x25FC,	0x25F6,	0x25E8,	0x25E2,	0x2C5A,	0x2C60,	0x2C6E,	0x2C74,	0x2C82,	0x2C88,	0x2C96,	0x2CDE,	0x2CD0,	0x2CCA,	0x2CBC,	0x2CB6,	0x2CA8,	0x2CA2}, \
	{0x11E2,	0x11E8,	0x11F6,	0x11FC,	0x120A,	0x1210,	0x121E,	0x1266,	0x1258,	0x1252,	0x1244,	0x123E,	0x1230,	0x122A,	0x18A2,	0x18A8,	0x18B6,	0x18BC,	0x18CA,	0x18D0,	0x18DE,	0x1926,	0x1918,	0x1912,	0x1904,	0x18FE,	0x18F0,	0x18EA,	0x1F62,	0x1F68,	0x1F76,	0x1F7C,	0x1F8A,	0x1F90,	0x1F9E,	0x1FE6,	0x1FD8,	0x1FD2,	0x1FC4,	0x1FBE,	0x1FB0,	0x1FAA,	0x2622,	0x2628,	0x2636,	0x263C,	0x264A,	0x2650,	0x265E,	0x26A6,	0x2698,	0x2692,	0x2684,	0x267E,	0x2670,	0x266A,	0x2CE2,	0x2CE8,	0x2CF6,	0x2CFC,	0x2D0A,	0x2D10,	0x2D1E,	0x2D66,	0x2D58,	0x2D52,	0x2D44,	0x2D3E,	0x2D30,	0x2D2A}, \
	{0x11E0,	0x11EE,	0x11F4,	0x1202,	0x1208,	0x1216,	0x121C,	0x1264,	0x125E,	0x1250,	0x124A,	0x123C,	0x1236,	0x1228,	0x18A0,	0x18AE,	0x18B4,	0x18C2,	0x18C8,	0x18D6,	0x18DC,	0x1924,	0x191E,	0x1910,	0x190A,	0x18FC,	0x18F6,	0x18E8,	0x1F60,	0x1F6E,	0x1F74,	0x1F82,	0x1F88,	0x1F96,	0x1F9C,	0x1FE4,	0x1FDE,	0x1FD0,	0x1FCA,	0x1FBC,	0x1FB6,	0x1FA8,	0x2620,	0x262E,	0x2634,	0x2642,	0x2648,	0x2656,	0x265C,	0x26A4,	0x269E,	0x2690,	0x268A,	0x267C,	0x2676,	0x2668,	0x2CE0,	0x2CEE,	0x2CF4,	0x2D02,	0x2D08,	0x2D16,	0x2D1C,	0x2D64,	0x2D5E,	0x2D50,	0x2D4A,	0x2D3C,	0x2D36,	0x2D28}, \
	{0x11E6,	0x11EC,	0x11FA,	0x1200,	0x120E,	0x1214,	0x1222,	0x126A,	0x125C,	0x1256,	0x1248,	0x1242,	0x1234,	0x122E,	0x18A6,	0x18AC,	0x18BA,	0x18C0,	0x18CE,	0x18D4,	0x18E2,	0x192A,	0x191C,	0x1916,	0x1908,	0x1902,	0x18F4,	0x18EE,	0x1F66,	0x1F6C,	0x1F7A,	0x1F80,	0x1F8E,	0x1F94,	0x1FA2,	0x1FEA,	0x1FDC,	0x1FD6,	0x1FC8,	0x1FC2,	0x1FB4,	0x1FAE,	0x2626,	0x262C,	0x263A,	0x2640,	0x264E,	0x2654,	0x2662,	0x26AA,	0x269C,	0x2696,	0x2688,	0x2682,	0x2674,	0x266E,	0x2CE6,	0x2CEC,	0x2CFA,	0x2D00,	0x2D0E,	0x2D14,	0x2D22,	0x2D6A,	0x2D5C,	0x2D56,	0x2D48,	0x2D42,	0x2D34,	0x2D2E}, \
	{0x11E4,	0x11F2,	0x11F8,	0x1206,	0x120C,	0x121A,	0x1220,	0x1268,	0x1262,	0x1254,	0x124E,	0x1240,	0x123A,	0x122C,	0x18A4,	0x18B2,	0x18B8,	0x18C6,	0x18CC,	0x18DA,	0x18E0,	0x1928,	0x1922,	0x1914,	0x190E,	0x1900,	0x18FA,	0x18EC,	0x1F64,	0x1F72,	0x1F78,	0x1F86,	0x1F8C,	0x1F9A,	0x1FA0,	0x1FE8,	0x1FE2,	0x1FD4,	0x1FCE,	0x1FC0,	0x1FBA,	0x1FAC,	0x2624,	0x2632,	0x2638,	0x2646,	0x264C,	0x265A,	0x2660,	0x26A8,	0x26A2,	0x2694,	0x268E,	0x2680,	0x267A,	0x266C,	0x2CE4,	0x2CF2,	0x2CF8,	0x2D06,	0x2D0C,	0x2D1A,	0x2D20,	0x2D68,	0x2D62,	0x2D54,	0x2D4E,	0x2D40,	0x2D3A,	0x2D2C}, \
	{0x11EA,	0x11F0,	0x11FE,	0x1204,	0x1212,	0x1218,	0x1226,	0x126E,	0x1260,	0x125A,	0x124C,	0x1246,	0x1238,	0x1232,	0x18AA,	0x18B0,	0x18BE,	0x18C4,	0x18D2,	0x18D8,	0x18E6,	0x192E,	0x1920,	0x191A,	0x190C,	0x1906,	0x18F8,	0x18F2,	0x1F6A,	0x1F70,	0x1F7E,	0x1F84,	0x1F92,	0x1F98,	0x1FA6,	0x1FEE,	0x1FE0,	0x1FDA,	0x1FCC,	0x1FC6,	0x1FB8,	0x1FB2,	0x262A,	0x2630,	0x263E,	0x2644,	0x2652,	0x2658,	0x2666,	0x26AE,	0x26A0,	0x269A,	0x268C,	0x2686,	0x2678,	0x2672,	0x2CEA,	0x2CF0,	0x2CFE,	0x2D04,	0x2D12,	0x2D18,	0x2D26,	0x2D6E,	0x2D60,	0x2D5A,	0x2D4C,	0x2D46,	0x2D38,	0x2D32}, \
	{0x1272,	0x1278,	0x1286,	0x128C,	0x129A,	0x12A0,	0x12AE,	0x12F6,	0x12E8,	0x12E2,	0x12D4,	0x12CE,	0x12C0,	0x12BA,	0x1932,	0x1938,	0x1946,	0x194C,	0x195A,	0x1960,	0x196E,	0x19B6,	0x19A8,	0x19A2,	0x1994,	0x198E,	0x1980,	0x197A,	0x1FF2,	0x1FF8,	0x2006,	0x200C,	0x201A,	0x2020,	0x202E,	0x2076,	0x2068,	0x2062,	0x2054,	0x204E,	0x2040,	0x203A,	0x26B2,	0x26B8,	0x26C6,	0x26CC,	0x26DA,	0x26E0,	0x26EE,	0x2736,	0x2728,	0x2722,	0x2714,	0x270E,	0x2700,	0x26FA,	0x2D72,	0x2D78,	0x2D86,	0x2D8C,	0x2D9A,	0x2DA0,	0x2DAE,	0x2DF6,	0x2DE8,	0x2DE2,	0x2DD4,	0x2DCE,	0x2DC0,	0x2DBA}, \
	{0x1270,	0x127E,	0x1284,	0x1292,	0x1298,	0x12A6,	0x12AC,	0x12F4,	0x12EE,	0x12E0,	0x12DA,	0x12CC,	0x12C6,	0x12B8,	0x1930,	0x193E,	0x1944,	0x1952,	0x1958,	0x1966,	0x196C,	0x19B4,	0x19AE,	0x19A0,	0x199A,	0x198C,	0x1986,	0x1978,	0x1FF0,	0x1FFE,	0x2004,	0x2012,	0x2018,	0x2026,	0x202C,	0x2074,	0x206E,	0x2060,	0x205A,	0x204C,	0x2046,	0x2038,	0x26B0,	0x26BE,	0x26C4,	0x26D2,	0x26D8,	0x26E6,	0x26EC,	0x2734,	0x272E,	0x2720,	0x271A,	0x270C,	0x2706,	0x26F8,	0x2D70,	0x2D7E,	0x2D84,	0x2D92,	0x2D98,	0x2DA6,	0x2DAC,	0x2DF4,	0x2DEE,	0x2DE0,	0x2DDA,	0x2DCC,	0x2DC6,	0x2DB8}, \
	{0x1276,	0x127C,	0x128A,	0x1290,	0x129E,	0x12A4,	0x12B2,	0x12FA,	0x12EC,	0x12E6,	0x12D8,	0x12D2,	0x12C4,	0x12BE,	0x1936,	0x193C,	0x194A,	0x1950,	0x195E,	0x1964,	0x1972,	0x19BA,	0x19AC,	0x19A6,	0x1998,	0x1992,	0x1984,	0x197E,	0x1FF6,	0x1FFC,	0x200A,	0x2010,	0x201E,	0x2024,	0x2032,	0x207A,	0x206C,	0x2066,	0x2058,	0x2052,	0x2044,	0x203E,	0x26B6,	0x26BC,	0x26CA,	0x26D0,	0x26DE,	0x26E4,	0x26F2,	0x273A,	0x272C,	0x2726,	0x2718,	0x2712,	0x2704,	0x26FE,	0x2D76,	0x2D7C,	0x2D8A,	0x2D90,	0x2D9E,	0x2DA4,	0x2DB2,	0x2DFA,	0x2DEC,	0x2DE6,	0x2DD8,	0x2DD2,	0x2DC4,	0x2DBE}, \
	{0x1274,	0x1282,	0x1288,	0x1296,	0x129C,	0x12AA,	0x12B0,	0x12F8,	0x12F2,	0x12E4,	0x12DE,	0x12D0,	0x12CA,	0x12BC,	0x1934,	0x1942,	0x1948,	0x1956,	0x195C,	0x196A,	0x1970,	0x19B8,	0x19B2,	0x19A4,	0x199E,	0x1990,	0x198A,	0x197C,	0x1FF4,	0x2002,	0x2008,	0x2016,	0x201C,	0x202A,	0x2030,	0x2078,	0x2072,	0x2064,	0x205E,	0x2050,	0x204A,	0x203C,	0x26B4,	0x26C2,	0x26C8,	0x26D6,	0x26DC,	0x26EA,	0x26F0,	0x2738,	0x2732,	0x2724,	0x271E,	0x2710,	0x270A,	0x26FC,	0x2D74,	0x2D82,	0x2D88,	0x2D96,	0x2D9C,	0x2DAA,	0x2DB0,	0x2DF8,	0x2DF2,	0x2DE4,	0x2DDE,	0x2DD0,	0x2DCA,	0x2DBC}, \
	{0x127A,	0x1280,	0x128E,	0x1294,	0x12A2,	0x12A8,	0x12B6,	0x12FE,	0x12F0,	0x12EA,	0x12DC,	0x12D6,	0x12C8,	0x12C2,	0x193A,	0x1940,	0x194E,	0x1954,	0x1962,	0x1968,	0x1976,	0x19BE,	0x19B0,	0x19AA,	0x199C,	0x1996,	0x1988,	0x1982,	0x1FFA,	0x2000,	0x200E,	0x2014,	0x2022,	0x2028,	0x2036,	0x207E,	0x2070,	0x206A,	0x205C,	0x2056,	0x2048,	0x2042,	0x26BA,	0x26C0,	0x26CE,	0x26D4,	0x26E2,	0x26E8,	0x26F6,	0x273E,	0x2730,	0x272A,	0x271C,	0x2716,	0x2708,	0x2702,	0x2D7A,	0x2D80,	0x2D8E,	0x2D94,	0x2DA2,	0x2DA8,	0x2DB6,	0x2DFE,	0x2DF0,	0x2DEA,	0x2DDC,	0x2DD6,	0x2DC8,	0x2DC2}, \




#endif /* _REMAP_TABLE_H_ */
