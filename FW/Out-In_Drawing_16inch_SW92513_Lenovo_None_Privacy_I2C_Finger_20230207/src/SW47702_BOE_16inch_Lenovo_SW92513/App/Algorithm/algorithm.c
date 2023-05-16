/******************************************************************************************************
 * Copyright (c) 2017 - 2025 SiliconWorks LIMITED
 *
 * file :  algorithm.c
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

#include "core_def.h"
#include "Protocol_swip.h"
#include "FOTG200_peripheral.h"
//Heon
int testflag = 0;
int pendflag = 0;
tXY_t testArray[10] = {0, };
int testcnt = 0;
tXY_t realOutInPos;
int pendcheck=0;
int testvusS = 0;

static const tModuleModeConf_t * ptModuleModeConf = NULL;
static const tAlgorithmModeConf_t * thisModeConf = NULL;
static tAlgorithmInfo_t * thisInfo = NULL;
#if USED_NOISE_HOPPING_FREQ
static tAppInfo_t * ptAppInfo = NULL;
#endif /* USED_NOISE_HOPPING_FREQ */
tAlgorithmInfo_t * DebugAlgorithmInfo = NULL;
//uint8_t HoppingInitFlag = 0;
extern __IO uint16_t sensingRowStart;
uint8_t DoReportOrgPos = 0, ErrorFrameProcessMode = 0;
extern uint16_t* g_pFingerBaseImage;
#if USED_NOISE_HOPPING_FREQ
extern uint16_t* g_pFingerHop1BaseImage;
#endif /* USED_NOISE_HOPPING_FREQ */

#if USED_ESD_DEBUG
bool_t gbRawdataStuckReset = NO;
bool_t gbRecalReset = NO;
#endif

//int dbg_algo[16] = {0,};
#if 1 // O0·Î ºôµå½Ã ÀÌ Çì´õÆÄÀÏÀ» includeÇÏ´Â °÷¿¡¼­ ¾Æ·¡ º¯¼ö°¡ data·Î ÀâÇô ¹ö¸².. .cÆÄÀÏ·Î ¿Å±è
#ifdef GetAngleLookUpHighResolution
extern int32_t ArcTanLookUp[1001]      =
{
0,57, 114, 171, 229, 286, 343, 401, 458, 515, 572, 630, 687, 744, 802, 859, 916, 973, 1031, 1088, 1145,
1203, 1260, 1317, 1374, 1432, 1489, 1546, 1603, 1661, 1718, 1775, 1832, 1890, 1947, 2004, 2061, 2119, 2176, 2233,
2290, 2347, 2405, 2462, 2519, 2576, 2633, 2690, 2748, 2805, 2862, 2919, 2976, 3033, 3091, 3148, 3205, 3262, 3319,
3376, 3433, 3490, 3547, 3604, 3661, 3719, 3776, 3833, 3890, 3947, 4004, 4061, 4118, 4175, 4232, 4289, 4346, 4403,
4460, 4517, 4573, 4630, 4687, 4744, 4801, 4858, 4915, 4972, 5029, 5085, 5142, 5199, 5256, 5313, 5370, 5426, 5483,
5540, 5597, 5653, 5710, 5767, 5824, 5880, 5937, 5994, 6050, 6107, 6164, 6220, 6277, 6333, 6390, 6447, 6503, 6560,
6616, 6673, 6729, 6786, 6842, 6899, 6955, 7012, 7068, 7125, 7181, 7237, 7294, 7350, 7406, 7463, 7519, 7575, 7632,
7688, 7744, 7801, 7857, 7913, 7969, 8025, 8082, 8138, 8194, 8250, 8306, 8362, 8418, 8474, 8530, 8586, 8642, 8698,
8754, 8810, 8866, 8922, 8978, 9034, 9090, 9146, 9202, 9257, 9313, 9369, 9425, 9480, 9536, 9592, 9648, 9703, 9759,
9815, 9870, 9926, 9981, 10037, 10092, 10148, 10204, 10259, 10314, 10370, 10425, 10481, 10536, 10592, 10647, 10702, 10758, 10813,
10868, 10923, 10979, 11034, 11089, 11144, 11199, 11254, 11309, 11365, 11420, 11475, 11530, 11585, 11640, 11695, 11750, 11804, 11859,
11914, 11969, 12024, 12079, 12133, 12188, 12243, 12298, 12352, 12407, 12462, 12516, 12571, 12625, 12680, 12734, 12789, 12843, 12898,
12952, 13007, 13061, 13115, 13170, 13224, 13278, 13333, 13387, 13441, 13495, 13549, 13604, 13658, 13712, 13766, 13820, 13874, 13928,
13982, 14036, 14090, 14144, 14197, 14251, 14305, 14359, 14413, 14466, 14520, 14574, 14627, 14681, 14735, 14788, 14842, 14895, 14949,
15002, 15056, 15109, 15163, 15216, 15269, 15323, 15376, 15429, 15482, 15535, 15589, 15642, 15695, 15748, 15801, 15854, 15907, 15960,
16013, 16066, 16119, 16172, 16225, 16277, 16330, 16383, 16436, 16488, 16541, 16594, 16646, 16699, 16751, 16804, 16856, 16909, 16961,
17014, 17066, 17118, 17171, 17223, 17275, 17327, 17380, 17432, 17484, 17536, 17588, 17640, 17692, 17744, 17796, 17848, 17900, 17952,
18004, 18056, 18107, 18159, 18211, 18262, 18314, 18366, 18417, 18469, 18520, 18572, 18623, 18675, 18726, 18778, 18829, 18880, 18932,
18983, 19034, 19085, 19136, 19187, 19239, 19290, 19341, 19392, 19443, 19494, 19544, 19595, 19646, 19697, 19748, 19798, 19849, 19900,
19950, 20001, 20052, 20102, 20153, 20203, 20254, 20304, 20354, 20405, 20455, 20505, 20556, 20606, 20656, 20706, 20756, 20806, 20856,
20906, 20956, 21006, 21056, 21106, 21156, 21206, 21256, 21305, 21355, 21405, 21454, 21504, 21554, 21603, 21653, 21702, 21752, 21801,
21850, 21900, 21949, 21998, 22047, 22097, 22146, 22195, 22244, 22293, 22342, 22391, 22440, 22489, 22538, 22587, 22636, 22684, 22733,
22782, 22831, 22879, 22928, 22976, 23025, 23074, 23122, 23170, 23219, 23267, 23316, 23364, 23412, 23460, 23509, 23557, 23605, 23653,
23701, 23749, 23797, 23845, 23893, 23941, 23989, 24036, 24084, 24132, 24180, 24227, 24275, 24323, 24370, 24418, 24465, 24513, 24560,
24607, 24655, 24702, 24749, 24796, 24844, 24891, 24938, 24985, 25032, 25079, 25126, 25173, 25220, 25267, 25314, 25361, 25407, 25454,
25501, 25547, 25594, 25641, 25687, 25734, 25780, 25827, 25873, 25919, 25966, 26012, 26058, 26104, 26151, 26197, 26243, 26289, 26335,
26381, 26427, 26473, 26519, 26565, 26610, 26656, 26702, 26748, 26793, 26839, 26885, 26930, 26976, 27021, 27067, 27112, 27157, 27203,
27248, 27293, 27339, 27384, 27429, 27474, 27519, 27564, 27609, 27654, 27699, 27744, 27789, 27834, 27878, 27923, 27968, 28013, 28057,
28102, 28146, 28191, 28235, 28280, 28324, 28369, 28413, 28457, 28502, 28546, 28590, 28634, 28678, 28722, 28766, 28810, 28854, 28898,
28942, 28986, 29030, 29074, 29117, 29161, 29205, 29248, 29292, 29336, 29379, 29423, 29466, 29509, 29553, 29596, 29639, 29683, 29726,
29769, 29812, 29855, 29898, 29941, 29984, 30027, 30070, 30113, 30156, 30199, 30242, 30284, 30327, 30370, 30412, 30455, 30498, 30540,
30583, 30625, 30667, 30710, 30752, 30794, 30837, 30879, 30921, 30963, 31005, 31047, 31090, 31132, 31173, 31215, 31257, 31299, 31341,
31383, 31424, 31466, 31508, 31549, 31591, 31633, 31674, 31716, 31757, 31798, 31840, 31881, 31922, 31964, 32005, 32046, 32087, 32128,
32169, 32210, 32251, 32292, 32333, 32374, 32415, 32456, 32497, 32537, 32578, 32619, 32659, 32700, 32741, 32781, 32822, 32862, 32902,
32943, 32983, 33023, 33064, 33104, 33144, 33184, 33224, 33264, 33304, 33344, 33384, 33424, 33464, 33504, 33544, 33584, 33623, 33663,
33703, 33742, 33782, 33822, 33861, 33901, 33940, 33980, 34019, 34058, 34098, 34137, 34176, 34215, 34254, 34294, 34333, 34372, 34411,
34450, 34489, 34528, 34566, 34605, 34644, 34683, 34722, 34760, 34799, 34837, 34876, 34915, 34953, 34992, 35030, 35068, 35107, 35145,
35183, 35222, 35260, 35298, 35336, 35374, 35412, 35450, 35488, 35526, 35564, 35602, 35640, 35678, 35716, 35753, 35791, 35829, 35866,
35904, 35942, 35979, 36017, 36054, 36092, 36129, 36166, 36204, 36241, 36278, 36315, 36353, 36390, 36427, 36464, 36501, 36538, 36575,
36612, 36649, 36686, 36722, 36759, 36796, 36833, 36869, 36906, 36943, 36979, 37016, 37052, 37089, 37125, 37162, 37198, 37234, 37271,
37307, 37343, 37379, 37416, 37452, 37488, 37524, 37560, 37596, 37632, 37668, 37704, 37739, 37775, 37811, 37847, 37882, 37918, 37954,
37989, 38025, 38060, 38096, 38131, 38167, 38202, 38238, 38273, 38308, 38344, 38379, 38414, 38449, 38484, 38519, 38554, 38589, 38624,
38659, 38694, 38729, 38764, 38799, 38834, 38868, 38903, 38938, 38972, 39007, 39042, 39076, 39111, 39145, 39180, 39214, 39248, 39283,
39317, 39351, 39386, 39420, 39454, 39488, 39522, 39556, 39590, 39624, 39658, 39692, 39726, 39760, 39794, 39828, 39861, 39895, 39929,
39963, 39996, 40030, 40063, 40097, 40130, 40164, 40197, 40231, 40264, 40297, 40331, 40364, 40397, 40431, 40464, 40497, 40530, 40563,
40596, 40629, 40662, 40695, 40728, 40761, 40794, 40827, 40859, 40892, 40925, 40958, 40990, 41023, 41055, 41088, 41121, 41153, 41185,
41218, 41250, 41283, 41315, 41347, 41380, 41412, 41444, 41476, 41508, 41540, 41573, 41605, 41637, 41669, 41701, 41733, 41764, 41796,
41828, 41860, 41892, 41923, 41955, 41987, 42018, 42050, 42082, 42113, 42145, 42176, 42208, 42239, 42270, 42302, 42333, 42364, 42396,
42427, 42458, 42489, 42520, 42551, 42583, 42614, 42645, 42676, 42707, 42737, 42768, 42799, 42830, 42861, 42892, 42922, 42953, 42984,
43014, 43045, 43076, 43106, 43137, 43167, 43198, 43228, 43258, 43289, 43319, 43350, 43380, 43410, 43440, 43470, 43501, 43531, 43561,
43591, 43621, 43651, 43681, 43711, 43741, 43771, 43801, 43830, 43860, 43890, 43920, 43949, 43979, 44009, 44038, 44068, 44098, 44127,
44157, 44186, 44216, 44245, 44274, 44304, 44333, 44362, 44392, 44421, 44450, 44479, 44508, 44537, 44567, 44596, 44625, 44654, 44683,
44712, 44741, 44769, 44798, 44827, 44856, 44885, 44913, 44942, 44971, 45000,
};
#endif 
#endif

tAlgorithmInfo_t * tTempAlgorithmInfoDebug;
void algorithm_init(void)
{
#if (USED_IDLE_MODE_CONTROL || USED_PEN_MODE_OPERATION || USED_LOCAL_IDLE_MODE_CONTROL || USED_NOISE_HOPPING_FREQ)
	const tAppCommonConf_t * _ptAppCommonConf = NULL;
	_ptAppCommonConf = app_GetCommonConfig();
#endif
	
	algorithm_init_param();
	thisInfo = algorithm_GetInfo();
#if USED_NOISE_HOPPING_FREQ
	ptAppInfo = app_GetInfo();
#endif /* USED_NOISE_HOPPING_FREQ */

	DebugAlgorithmInfo = thisInfo;
	tTempAlgorithmInfoDebug = thisInfo;

#if USED_IDLE_MODE_CONTROL
	#if USED_ENTER_IDLE_REAL_TIME_CHECK
		thisInfo->ulIdleModeEnterFrameCntTHD = _ptAppCommonConf->ucIdleModeEnterSec;
	#else
		thisInfo->ulIdleModeEnterFrameCntTHD = _ptAppCommonConf->ucIdleModeEnterSec * _ptAppCommonConf->ucFrameRate;
	#endif /* USED_ENTER_IDLE_REAL_TIME_CHECK */
	thisInfo->ulIdleModeEnterCheckCount = 0;
#if USED_NOISE_HOPPING_FREQ
	thisInfo->ulHopFrqIdleModeFrameCntTHD = thisInfo->ulIdleModeEnterFrameCntTHD;
#endif /* USED_NOISE_HOPPING_FREQ */

#endif /* USED_IDLE_MODE_CONTROL */

#if USED_PEN_MODE_OPERATION
	thisInfo->uPenLocalModeEnterFrameCntTHD = _ptAppCommonConf->ucPenLocalModeEnterSec * _ptAppCommonConf->ucFrameRate;
	thisInfo->ulPenLocalModeEnterCheckCount = 0;

	thisInfo->ulPenLocalModeChangeFrameCntTHD = _ptAppCommonConf->ucPenLocalModeChangeFrameCntTHD;
	thisInfo->ulPenLocalModeChangeCheckCount = 0;
	thisInfo->ulPenFullModeChangeFrameCntTHD = _ptAppCommonConf->ucPenFullModeChangeFrameCntTHD;
	thisInfo->ulPenFullModeChangeCheckCount = 0;

#if USED_LOCAL_IDLE_MODE_CONTROL
	thisInfo->ulPenLocalIdleModeEnterFrameCntTHD = _ptAppCommonConf->ucIdleModeEnterSec * (_ptAppCommonConf->ucFrameRate / 2);
	thisInfo->ulPenLocalIdleModeEnterCheckCount = 0;
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
#endif /* USED_PEN_MODE_OPERATION */

#if USED_NOISE_HOPPING_FREQ
	thisInfo->ulHoppMainRollbackFrameCntTHD = _ptAppCommonConf->HoppMainRollbackSec * _ptAppCommonConf->ucFrameRate;
	thisInfo->ulHoppMainRollbackCheckCount = 0;
#if USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE
	ptAppInfo->bIsHoppFreqBaseUpdateContinueCheckStart = NO;
	ptAppInfo->bIsNormalReadyIdleCheckCountMaintain = NO;
	ptAppInfo->ulHoppFreqBaseUpdateFrameCheckCnt = 0;
	ptAppInfo->ulHoppFreqBaseUpdateContinueCheckCnt = 0;
#endif /* USE_FREQ_HOPPING_BASELINE_CONTI_UPDATE */
#endif /* USED_NOISE_HOPPING_FREQ */
//	thisInfo-> = _ptAppCommonConf->ucIdleModeEnterSec * _ptAppCommonConf->ucFrameRate;

	algorithm_baseline_init();
	algorithm_label_init();
	algorithm_coord_init();
#if USED_NOISE_HOPPING_FREQ
	algorithm_noise_init();
#endif /* USED_NOISE_HOPPING_FREQ */
}

void algorithm_init_param(void)
{
	ptModuleModeConf = module_GetModeConfig();
	thisModeConf = algorithm_GetModeConfig();
	algorithm_baseline_init_param();
	algorithm_label_init_param();
//	algorithm_coord_init();
	algorithm_coord_init_param();
}

#if USED_IDLE_MODE_CONTROL
bool_t algorithm_CheckFingerIdleModeControl(void)
{
	eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();

	if(IS_ACTIVE_MODE(eSensingMode))
	{
		if(thisInfo->bTouchExpect)
		{
			thisInfo->ulIdleModeEnterCheckCount = 0;
		}
		else
		{
	#if USED_ENTER_IDLE_REAL_TIME_CHECK
			if(thisInfo->ulIdleModeEnterCheckCount == 0)
			{
				TimerTick_ResetIdleModeCheckTime();
				thisInfo->ulIdleModeEnterCheckCount++;
			}
	#else /* USED_ENTER_IDLE_REAL_TIME_CHECK */
			thisInfo->ulIdleModeEnterCheckCount++;
	#endif /* USED_ENTER_IDLE_REAL_TIME_CHECK */

#if USED_NOISE_HOPPING_FREQ
	#if USED_ENTER_IDLE_REAL_TIME_CHECK
			if(IS_ACTIVE_MODE_FRQ_MAIN(eSensingMode))
			{
				if(TimerTick_GetIdleModeCheckTimeSec() >= thisInfo->ulIdleModeEnterFrameCntTHD)
				{
					thisInfo->ulIdleModeEnterCheckCount = 0;
					HAL_SetSensingChangeMode(SM_CHANGE_IDLE_MODE);
					return YES;
				}
			}
	#else /* USED_ENTER_IDLE_REAL_TIME_CHECK */
			if(IS_ACTIVE_MODE_FRQ_MAIN(eSensingMode))
			{
				if(thisInfo->ulIdleModeEnterCheckCount > thisInfo->ulIdleModeEnterFrameCntTHD)
				{
					thisInfo->ulIdleModeEnterCheckCount = 0;
					HAL_SetSensingChangeMode(SM_CHANGE_IDLE_MODE);
					return YES;
				}
			}
			else
			{
				if(thisInfo->ulIdleModeEnterCheckCount > thisInfo->ulHopFrqIdleModeFrameCntTHD)
				{
//					HoppingInitFlag = YES;
					thisInfo->ulIdleModeEnterCheckCount = 0;
					return YES;
				}
			}
	#endif /* USED_ENTER_IDLE_REAL_TIME_CHECK */
#else /* USED_NOISE_HOPPING_FREQ */
	#if USED_ENTER_IDLE_REAL_TIME_CHECK
			if(TimerTick_GetIdleModeCheckTimeSec() >= thisInfo->ulIdleModeEnterFrameCntTHD)
			{
				thisInfo->ulIdleModeEnterCheckCount = 0;
				HAL_SetSensingChangeMode(SM_CHANGE_IDLE_MODE);
				return YES;
			}
	#else /* USED_ENTER_IDLE_REAL_TIME_CHECK */
			if(thisInfo->ulIdleModeEnterCheckCount > thisInfo->ulIdleModeEnterFrameCntTHD)
			{
				thisInfo->ulIdleModeEnterCheckCount = 0;
				HAL_SetSensingChangeMode(SM_CHANGE_IDLE_MODE);
				return YES;
			}
	#endif /* USED_ENTER_IDLE_REAL_TIME_CHECK */
#endif /* USED_NOISE_HOPPING_FREQ */
		}
	}
	else
	{
		if(thisInfo->bTouchExpect)
		{
			/*
			 * NOTE : Idle -> Active Is Always Normal Frequency Operation
			 */
#if USED_FULLSCAN_SWITCH_IDLE_TO_ACTIVE
			HAL_SetSensingChangeMode(SM_CHANGE_FULLSCAN_IDLE_MODE);
#else /* USED_FULLSCAN_SWITCH_IDLE_TO_ACTIVE */
	#if USED_FAST_SWITCH_IDLE_TO_ACTIVE
			HAL_SetSensingChangeMode(SM_FAST_CHANGE_ACTIVE_MODE);
	#else /* USED_FAST_SWITCH_IDLE_TO_ACTIVE */
			HAL_SetSensingChangeMode(SM_CHANGE_ACTIVE_MODE);
	#endif /* USED_FAST_SWITCH_IDLE_TO_ACTIVE */
#endif /* USED_FULLSCAN_SWITCH_IDLE_TO_ACTIVE */
#if USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE
			thisInfo->bIsIdleToActive = YES;
#endif /* USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE */

			return YES;
		}
	}

	return NO;
}
#endif /* USED_IDLE_MODE_CONTROL */

#if USED_PEN_MODE_OPERATION
#if USED_LOCAL_IDLE_MODE_CONTROL
uint32_t ulIdleEnterCheckCountStopCnt = 0;
bool_t algorithm_CheckLocalPenIdleModeControl(void)
{
	eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();

	if(IS_ACTIVE_MODE(eSensingMode))
	{
		/*
		 * Idle-Mode only works in Local-Mode
		 */
		if(IS_FINGER_PEN_MODE(eSensingMode))
		{
			if(hal_Info_GetPenDectionEnable() || thisInfo->bTouchExpect)
			{
				ulIdleEnterCheckCountStopCnt++;
				if(ulIdleEnterCheckCountStopCnt > thisInfo->ulPenFullModeChangeFrameCntTHD)
				{
					ulIdleEnterCheckCountStopCnt = 0;
					thisInfo->ulPenLocalIdleModeEnterCheckCount = 0;
				}
			}
			else
			{
				ulIdleEnterCheckCountStopCnt = 0;
				thisInfo->ulPenLocalIdleModeEnterCheckCount++;
				if(thisInfo->ulPenLocalIdleModeEnterCheckCount > thisInfo->ulPenLocalIdleModeEnterFrameCntTHD)
				{
	#if USED_NOISE_HOPPING_FREQ
					if(IS_ACTIVE_MODE_FRQ_MAIN(eSensingMode))
					{
						thisInfo->ulPenLocalIdleModeEnterCheckCount = 0;
						HAL_SetSensingChangeMode(SM_CHANGE_IDLE_MODE);
						return YES;
					}
					else
					{
						if(ptAppInfo->eHoppingStatus != FREQ_HOPPING_CHANGED)
						{
							ptAppInfo->eNoiseStatus = NOISE_FREQ_HOPPING;
						}
					}
	#else /* USED_NOISE_HOPPING_FREQ */
					thisInfo->ulPenLocalIdleModeEnterCheckCount = 0;
					HAL_SetSensingChangeMode(SM_CHANGE_IDLE_MODE);
					return YES;
	#endif /* USED_NOISE_HOPPING_FREQ */
				}
			}
		}
	}
	else
	{
		if(thisInfo->bTouchExpect)
		{
			thisInfo->ulPenLocalIdleModeEnterCheckCount = 0;

	#if USED_FAST_SWITCH_LOCAL_IDLE_TO_ACTIVE
			HAL_SetSensingChangeMode(SM_FAST_CHANGE_LocalIdle_To_Local_MODE);
	#else /* USED_FAST_SWITCH_LOCAL_IDLE_TO_ACTIVE */
			HAL_SetSensingChangeMode(SM_CHANGE_LocalIdle_To_Local_MODE);
	#endif /* USED_FAST_SWITCH_LOCAL_IDLE_TO_ACTIVE */
			return YES;
		}
	}

	return NO;
}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */

bool_t algorithm_CheckFingerPenModeControl(void)
{
	eSENSING_MODE_t eSensingMode = HAL_GetSensingMode();

	if(IS_FINGER_PEN_MODE(eSensingMode))
	{
#if USED_ONLY_LOCAL_MODE
		thisInfo->ulPenFullModeChangeCheckCount = 0;
#else /* USED_ONLY_LOCAL_MODE */
#if USED_ONLY_FULL_MODE
		thisInfo->ulPenFullModeChangeCheckCount = 0;
		thisInfo->ulPenLocalModeEnterCheckCount = 0;
		HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);
		return YES;
#else /* USED_ONLY_FULL_MODE */
		if(hal_Info_GetPenDectionEnable() || (thisModeConf->PenCoord.bFullFingerOn == NO) || (thisInfo->bIsPalm == YES && thisInfo->tCoord.tPos.sFinger_ == 0))
		{
			thisInfo->ulPenFullModeChangeCheckCount = 0;
		}
		else
		{
			if(thisInfo->bTouchExpect)
			{
				thisInfo->ulPenFullModeChangeCheckCount++;
				if(thisInfo->ulPenFullModeChangeCheckCount > thisInfo->ulPenFullModeChangeFrameCntTHD)
				{
					thisInfo->ulPenFullModeChangeCheckCount = 0;
					thisInfo->ulPenLocalModeEnterCheckCount = 0;
#if USED_LOCAL_IDLE_MODE_CONTROL
					thisInfo->ulPenLocalIdleModeEnterCheckCount = 0;
					ulIdleEnterCheckCountStopCnt = 0;
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
					HAL_SetSensingChangeMode(SM_CHAGNE_Local_To_Full_MODE);
					return YES;
				}
			}
			else
			{
				thisInfo->ulPenFullModeChangeCheckCount = 0;
			}
		}
#endif /* USED_ONLY_FULL_MODE */
#endif /* USED_ONLY_LOCAL_MODE */
	}
	else
	{
#if (!USED_ONLY_FULL_MODE)
		if(thisInfo->tCoord.tPos.sFinger_ == 0)
		{
			thisInfo->ulPenLocalModeEnterCheckCount++;
		}
		else 
		{
			thisInfo->ulPenLocalModeEnterCheckCount = 0;
		}
		
		if(thisInfo->bLocal_sensing ||
			thisInfo->ulPenLocalModeEnterCheckCount > thisInfo->uPenLocalModeEnterFrameCntTHD)
		{
			if(thisInfo->bLocal_sensing)
			{
				thisInfo->tPenInfo.bSearch_Mode_Flag = 0;
				hal_Info_SetPenDectionEnable(YES);
#if ((USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) || (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWACOM_PEN))
				hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_PEN_BEACON);
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN || USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_UHD_PEN)
				hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETABS_BEACON);
#elif (USED_PEN_PROTOCOL == PEN_PROTOCOL_MSnWGP_PEN)
				hal_Info_SetMPPPen1stBeaconType(PWM_MPP_PEN_1st_PEN_BEACON);
				hal_Info_SetChangeWGPPenBeaconType(PWM_WGP_PEN_GETABS_BEACON);
#endif /* (USED_PEN_PROTOCOL == PEN_PROTOCOL_MS_PEN) */

//#if (USED_PEN_PROTOCOL == PEN_PROTOCOL_WGP_PEN)
//				SRIC_SetLocalIndex(((0 << 16) | sensingRowStart));
//#endif
			}
			
			thisInfo->ulPenLocalModeEnterCheckCount = 0;
			HAL_SetSensingChangeMode(SM_CHAGNE_Full_To_Local_MODE);
			return YES;
		}
#endif /* (!USED_ONLY_FULL_MODE) */
	}

	return NO;
}
#endif /* USED_PEN_MODE_OPERATION */

uint64_t OperStartTime;
uint32_t OperEndTime;
void GetOperTimeUS(uint64_t* StartTime, uint32_t* ScanTime)
{
	uint16_t Temp = 0;

	if (*StartTime == 0)
	{
		goto GETSCANTIME__GOTO_END;
	}
	
	Temp = (uint16_t)(getElapsedUS(*StartTime));
	*ScanTime += Temp;

GETSCANTIME__GOTO_END:

	*StartTime = (uint64_t)getLongSysTick();
}

int32_t algorithm_calc_sqrt(int32_t d)
{
    uint32_t x = 1;

    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;
    x = (x + d/x)>>1;

    return x;
}

#ifdef GetAngleLookUpHighResolution
int32_t algorithm_calc_angle_inter_2points_HighResolution(int diff_x, int diff_y)
{
	int angle = 0;

//	int diff_x, diff_y;

//	diff_x = _tPos2.x - _tPos1.x;
//	diff_y = _tPos2.y - _tPos1.y;
	
	if( diff_x > 0  )
	{
		if( diff_y > 0 )
		{
			if( diff_x >= diff_y ){
				//angle = sucArcTanLookUpTable[(diff_y << 6)/diff_x];
				angle = ArcTanLookUp[MIN(1000,MAX(0,(int)((double)diff_y/(double)diff_x * 1000)))];
			}
			else
				//angle = 90 - sucArcTanLookUpTable[(diff_x << 6)/diff_y];
				angle = 90000 - ArcTanLookUp[MIN(1000,MAX(0,(int)((double)diff_x/(double)diff_y * 1000)))];
		}
		else if( diff_y < 0 )
		{
			if( diff_x >= -(diff_y) )
				//angle = 360 - sucArcTanLookUpTable[(-diff_y << 6)/diff_x];
				angle = 360000 - ArcTanLookUp[MIN(1000,MAX(0,(int)((double)-diff_y/(double)diff_x * 1000)))];
			else
				//angle = 270 + sucArcTanLookUpTable[(diff_x << 6)/-diff_y];
				angle = 270000 - ArcTanLookUp[MIN(1000,MAX(0,(int)((double)diff_x/(double)-diff_y * 1000)))];
		}
		else
		{
			angle = 0;
		}
	}
	else if( diff_x < 0 )
	{
		if( diff_y > 0 )
		{
			if( -diff_x < diff_y )
				//angle = 90 + sucArcTanLookUpTable[(-diff_x << 6)/diff_y];
				angle = 90000 + ArcTanLookUp[MIN(1000,MAX(0,(int)((double)-diff_x/(double)diff_y * 1000)))];
			else
				//angle = 180 - sucArcTanLookUpTable[(diff_y << 6)/-diff_x];
				angle = 180000 - ArcTanLookUp[MIN(1000,MAX(0,(int)((double)diff_y/(double)-diff_x * 1000)))];
		}
		else if( diff_y < 0 )
		{
			if( -diff_x >= -diff_y )
				//angle = 180 + sucArcTanLookUpTable[(-diff_y << 6)/-diff_x];
				angle = 180000 + ArcTanLookUp[MIN(1000,MAX(0,(int)((double)-diff_y/(double)-diff_x * 1000)))];
			else
				//angle = 270 - sucArcTanLookUpTable[(-diff_x << 6)/-diff_y];
				angle = 270000 - ArcTanLookUp[MIN(1000,MAX(0,(int)((double)-diff_x/(double)-diff_y * 1000)))];
		}
		else
		{
			angle = 180000;
		}
	}
	else
	{
		if( diff_y > 0 )
			angle = 90000;
		else if( diff_y < 0 )
		{
			angle = 270000;
		}
	}

	return angle;
}
#else
#ifndef TILT_OPCODE
int32_t algorithm_calc_angle_inter_2points(int diff_x, int diff_y)
{
	int angle = 0;

//	int diff_x, diff_y;

//	diff_x = _tPos2.x - _tPos1.x;
//	diff_y = _tPos2.y - _tPos1.y;

	if( diff_x > 0  )
	{
		if( diff_y > 0 )
		{
			if( diff_x >= diff_y )
				angle = sucArcTanLookUpTable[(diff_y * 100)/diff_x];
			else
				angle = 9000 - sucArcTanLookUpTable[(diff_x * 100)/diff_y];
		}
		else if( diff_y < 0 )
		{
			if( diff_x >= -(diff_y) )
				angle = 36000 - sucArcTanLookUpTable[(-diff_y * 100)/diff_x];
			else
				angle = 27000 + sucArcTanLookUpTable[(diff_x * 100)/-diff_y];
		}
		else
		{
			angle = 0;
		}
	}
	else if( diff_x < 0 )
	{
		if( diff_y > 0 )
		{
			if( -diff_x < diff_y )
				angle = 9000 + sucArcTanLookUpTable[(-diff_x * 100)/diff_y];
			else
				angle = 18000 - sucArcTanLookUpTable[(diff_y * 100)/-diff_x];
		}
		else if( diff_y < 0 )
		{
			if( -diff_x >= -diff_y )
				angle = 18000 + sucArcTanLookUpTable[(-diff_y * 100)/-diff_x];
			else
				angle = 27000 - sucArcTanLookUpTable[(-diff_x * 100)/-diff_y];
		}
		else
		{
			angle = 18000;
		}
	}
	else
	{
		if( diff_y > 0 )
			angle = 9000;
		else if( diff_y < 0 )
		{
			angle = 27000;
		}
	}

	return angle;
}
#endif /* TILT_OPCODE */

#if 0
int32_t algorithm_calc_angle_inter_2points(tXY_t _tPos1, tXY_t _tPos2)
{
	int angle = 0;

	int diff_x, diff_y;

	diff_x = _tPos2.x - _tPos1.x;
	diff_y = _tPos2.y - _tPos1.y;

	if( diff_x > 0  )
	{
		if( diff_y > 0 )
		{
			if( diff_x >= diff_y )
				angle = sucArcTanLookUpTable[(diff_y << 6)/diff_x];
			else
				angle = 90 - sucArcTanLookUpTable[(diff_x << 6)/diff_y];
		}
		else if( diff_y < 0 )
		{
			if( diff_x >= -(diff_y) )
				angle = 360 - sucArcTanLookUpTable[(-diff_y << 6)/diff_x];
			else
				angle = 270 + sucArcTanLookUpTable[(diff_x << 6)/-diff_y];
		}
		else
		{
			angle = 0;
		}
	}
	else if( diff_x < 0 )
	{
		if( diff_y > 0 )
		{
			if( -diff_x < diff_y )
				angle = 90 + sucArcTanLookUpTable[(-diff_x << 6)/diff_y];
			else
				angle = 180 - sucArcTanLookUpTable[(diff_y << 6)/-diff_x];
		}
		else if( diff_y < 0 )
		{
			if( -diff_x >= -diff_y )
				angle = 180 + sucArcTanLookUpTable[(-diff_y << 6)/-diff_x];
			else
				angle = 270 - sucArcTanLookUpTable[(-diff_x << 6)/-diff_y];
		}
		else
		{
			angle = 180;
		}
	}
	else
	{
		if( diff_y > 0 )
			angle = 90;
		else if( diff_y < 0 )
		{
			angle = 270;
		}
	}

	return angle;
}
#endif
#endif

#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN
extern bool_t bBigFingerEdgeTestFlag[4];
uint8_t ucBigFingerEdgeTest_MoveEventTHD_Change = 0;
extern bool_t bBigFingerEdgeTestEn[4];
extern bool_t bReportDelayFlag;
uint8_t ucReportDelayCnt = 0;
tXY_t ReportDelayTmpPos;
extern STATIC_QUEUE	g_Queue_Common;
extern uint8_t	g_Touch[QUEUE_BLOCK_SIZE];
void algorithm_EdgeReportDelay(void)
{
	int i, distX, distY;
	static uint8_t ucTmpEdgeReportDelayCnt =0;
	
	if(thisModeConf->EdgeExpand.ucEdgeReportDelayCnt)
	{
		if(thisInfo->tCoord.tPastPos[0].vusS[0] == 0 && thisInfo->tCoord.tPos.vusS[0] && thisInfo->tCoord.tPos.sFinger_ == 1)
		{
			int8_t edge_type = algorithm_coord_IsEdgeArea(&thisInfo->tCoord.tPos.tXY[0],UNIT_DIST>>1);
			if(edge_type)
			{
				distY = distX = 0;
				if(thisInfo->tCoord.tPos.tXY[0].y < (UNIT_DIST+(UNIT_DIST>>1)))
				{
					for(i = thisInfo->tCoord.tPos.rect[0].cs; i < thisInfo->tCoord.tPos.rect[0].ce; i++)
					{
						distY += HAL_READ_DELTA_IMAGE(0,i);
					}
				}
				else if(thisInfo->tCoord.tPos.tXY[0].y > thisInfo->tCoord.iInternalYRes-(UNIT_DIST+(UNIT_DIST>>1)))
				{
					for(i = thisInfo->tCoord.tPos.rect[0].cs; i <= thisInfo->tCoord.tPos.rect[0].ce; i++)
					{
						distY += HAL_READ_DELTA_IMAGE(ROW_MAX-1,i);
					}
				}

				if(thisInfo->tCoord.tPos.tXY[0].x < (UNIT_DIST+(UNIT_DIST>>1)))
				{
					for(i = thisInfo->tCoord.tPos.rect[0].rs; i <= thisInfo->tCoord.tPos.rect[0].re; i++)
					{
						distX += HAL_READ_DELTA_IMAGE(i,0);
					}
				}
				else if(thisInfo->tCoord.tPos.tXY[0].x > thisInfo->tCoord.iInternalXRes-(UNIT_DIST+(UNIT_DIST>>1)))
				{
					for(i = thisInfo->tCoord.tPos.rect[0].cs; i <= thisInfo->tCoord.tPos.rect[0].ce; i++)
					{
						distX += HAL_READ_DELTA_IMAGE(i,COL_MAX-1);
					}
				}
				
				if(distX > 30 || distY > 30)
				{
					bReportDelayFlag=1;
					ucReportDelayCnt = 0;
					ReportDelayTmpPos = thisInfo->tCoord.tPos.tXY[0];
					ucTmpEdgeReportDelayCnt = thisModeConf->EdgeExpand.ucEdgeReportDelayCnt;
					if(edge_type==2)ucTmpEdgeReportDelayCnt+=5;
				}
			}
		}
		
		if(bReportDelayFlag)
		{
//			if(thisInfo->tCoord.tPastPos[0].vusS[0])
			{
				if(algorithm_coord_calc_distance(thisInfo->tCoord.tFirstPos.tXY[0],thisInfo->tCoord.tPos.tXY[0]) > 512 || ucReportDelayCnt > ucTmpEdgeReportDelayCnt)
				{
					bReportDelayFlag = 0;
					ucReportDelayCnt = 0;
				}
				else
				{
					if(ucReportDelayCnt == ucTmpEdgeReportDelayCnt)
					{
						for(i = 0; i < thisModeConf->EdgeExpand.ucEdgeReportDelayCnt; i++)
							StaticQueue_Pop(&g_Queue_Common, (uint8_t*)&g_Touch);
					}
					ucReportDelayCnt++;
					
				}
			}
		}
	}
}

void algorithm_BigFingerEdgeAccTest(tXY_t *pos1, tXY_t *pos2,bool_t EndEventMode)
{
	int distX, distY;
	tXY_t pos, old_pos;
	static uint8_t end_cliping_flag = 0;

	old_pos.x = pos2->x;
	old_pos.y = pos2->y;
	pos.x = pos1->x;
	pos.y = pos1->y;
	if(EndEventMode == 0)
	{
		if(thisInfo->tCoord.tPastSentPos.vusS[0])
		{
			distX = old_pos.x - pos.x;
			distY = old_pos.y - pos.y;
			if(distX<0)distX=-distX;
			if(distY<0)distY=-distY;

			if(ucBigFingerEdgeTest_MoveEventTHD_Change != 0 || bBigFingerEdgeTestFlag[0] != 0 || bBigFingerEdgeTestFlag[1] != 0 || bBigFingerEdgeTestFlag[2] != 0 || bBigFingerEdgeTestFlag[3] != 0)
			{
				if(!algorithm_coord_IsEdgeArea(&thisInfo->tCoord.tPos.tXY[0],150))
				{
					ucBigFingerEdgeTest_MoveEventTHD_Change = 0;
					bBigFingerEdgeTestFlag[0]=bBigFingerEdgeTestFlag[1]=bBigFingerEdgeTestFlag[2]=bBigFingerEdgeTestFlag[3]=0;
					bBigFingerEdgeTestEn[0]=bBigFingerEdgeTestEn[1]=bBigFingerEdgeTestEn[2]=bBigFingerEdgeTestEn[3]=1;
				}
			}
			
			if(end_cliping_flag > 0 && end_cliping_flag < 5 && algorithm_coord_IsEdgeArea_Cell(thisInfo->tLabel.tValidMaxPos[0].r,thisInfo->tLabel.tValidMaxPos[0].c,0) != 2)
				end_cliping_flag = 5;
			
			if(distY > thisModeConf->EdgeExpand.usBigFingerEdgeTest_MoveEventTHD_Y || distX > thisModeConf->EdgeExpand.usBigFingerEdgeTest_MoveEventTHD_X)
			{
				ucBigFingerEdgeTest_MoveEventTHD_Change=0;
			}

			if(ucBigFingerEdgeTest_MoveEventTHD_Change == 3)
			{
				pos.x = old_pos.x;
				pos.y = old_pos.y;
			}
			
			if(bBigFingerEdgeTestFlag[0] != 0 || bBigFingerEdgeTestFlag[1] != 0 || bBigFingerEdgeTestFlag[2] != 0 || bBigFingerEdgeTestFlag[3] != 0)
			{						
				if(distX > 196 || distY > 365)
				{
					bBigFingerEdgeTestFlag[0]=bBigFingerEdgeTestFlag[1]=bBigFingerEdgeTestFlag[2]=bBigFingerEdgeTestFlag[3]=0;
					bBigFingerEdgeTestEn[0]=bBigFingerEdgeTestEn[1]=bBigFingerEdgeTestEn[2]=bBigFingerEdgeTestEn[3]=1;
				}
			}
		}
					
//		if(bBigFingerEdgeTestFlag[0] && pos.y > thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop)pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
//		if(bBigFingerEdgeTestFlag[1] && pos.y < 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom)pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
//		if(bBigFingerEdgeTestFlag[2] && pos.x > thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft)pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
//		if(bBigFingerEdgeTestFlag[3] && pos.x < 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight)pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;
			
		if(bBigFingerEdgeTestFlag[0])
		{
			if(bBigFingerEdgeTestFlag[2])
			{
				pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
				pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
//				if(pos.x < thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft)pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
//				if(pos.y < thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop) pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
			}
			else if(bBigFingerEdgeTestFlag[3])
			{
				pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;
				pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
				//if(pos.x > 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight)pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;
				//if(pos.y < thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop)		  pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
			}
		}
		else if(bBigFingerEdgeTestFlag[1])
		{
			if(bBigFingerEdgeTestFlag[2])
			{
				pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
				pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
				//if(pos.x < thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft)		   pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
				//if(pos.y > 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom)pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
			}
			else if(bBigFingerEdgeTestFlag[3])
			{
				pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;
				pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
				//if(pos.x > 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight) pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;
				//if(pos.y > 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom)pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
			}
		}		

//		if(bBigFingerEdgeTestFlag[0])
//		{
//			pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
//		}
//		else if(bBigFingerEdgeTestFlag[1])
//		{
//			pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
//		}
//			
//		if(bBigFingerEdgeTestFlag[2])
//		{
//			pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
//		}
//		else if(bBigFingerEdgeTestFlag[3])
//		{
//			pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;
//		}

		if(end_cliping_flag == 0)
		{
			if(!bBigFingerEdgeTestEn[0] && !bBigFingerEdgeTestEn[1] && !bBigFingerEdgeTestEn[2] && !bBigFingerEdgeTestEn[3] && thisModeConf->EdgeExpand.bFingerCornerTestClippingOn)
			{
				if(algorithm_coord_IsEdgeArea(&thisInfo->tCoord.tFirstPos.tXY[0],0) == 2 && thisInfo->tCoord.tPos.sFinger_ == 1)
				{
					if(algorithm_coord_IsEdgeArea_Cell(thisInfo->tLabel.tValidMaxPos[0].r,thisInfo->tLabel.tValidMaxPos[0].c,0) == 2)
					{
						if(thisInfo->tLabel.tValidMaxPos[0].r == 0)
						{
							if(thisInfo->tLabel.tValidMaxPos[0].c == 0)
							{
								if(pos.x < 196)pos.x = 196;
								if(pos.y < 365)pos.y = 365;
								end_cliping_flag = 1;
							}
							else
							{
								if(pos.x > 32767-196)pos.x = 32767-196;
								if(pos.y < 365)pos.y = 365;
								end_cliping_flag = 2;
							}
						}
						else
						{
							if(thisInfo->tLabel.tValidMaxPos[0].c == 0)
							{
								if(pos.x < 196)pos.x = 196;
								if(pos.y > 32767-365)pos.y = 32767-365;
								end_cliping_flag = 3;
							}
							else
							{
								if(pos.x > 32767-196)pos.x = 32767-196;
								if(pos.y > 32767-365)pos.y = 32767-365;
								end_cliping_flag = 4;
							}
						}
					}
				}
			}
		}
		
		 pos1->x=pos.x;
		 pos1->y=pos.y;
	}
	else
	{
//		if(bBigFingerEdgeTestFlag[0] && old_pos.y > thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop)old_pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
//		if(bBigFingerEdgeTestFlag[1] && old_pos.y < 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom)old_pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
//		if(bBigFingerEdgeTestFlag[2] && old_pos.x > thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft)old_pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
//		if(bBigFingerEdgeTestFlag[3] && old_pos.x < 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight)old_pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;		
			
		if(bBigFingerEdgeTestFlag[0])
		{
			if(bBigFingerEdgeTestFlag[2])
			{
				old_pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
				old_pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
				//if(old_pos.x < thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft)old_pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
				//if(old_pos.y < thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop) old_pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
			}
			else if(bBigFingerEdgeTestFlag[3])
			{
				old_pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;
				old_pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
				//if(old_pos.x > 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight)old_pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;
				//if(old_pos.y < thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop)		  old_pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
			}
		}
		else if(bBigFingerEdgeTestFlag[1])
		{
			if(bBigFingerEdgeTestFlag[2])
			{
				old_pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
				old_pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
				//if(old_pos.x < thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft)		   old_pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
				//if(old_pos.y > 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom)old_pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
			}
			else if(bBigFingerEdgeTestFlag[3])
			{
				old_pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;
				old_pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
				//if(old_pos.x > 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight) old_pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;
				//if(old_pos.y > 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom)old_pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
			}
		}

//		if(bBigFingerEdgeTestFlag[0])
//		{
//			old_pos.y = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingTop;
//		}
//		else if(bBigFingerEdgeTestFlag[1])
//		{
//			old_pos.y = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingBottom;
//		}
//			
//		if(bBigFingerEdgeTestFlag[2])
//		{
//			old_pos.x = thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingLeft;
//		}
//		else if(bBigFingerEdgeTestFlag[3])
//		{
//			old_pos.x = 32767-thisModeConf->EdgeExpand.usBigFingerEdgeTestClippingRight;
//		}
	
		if(end_cliping_flag == 1)
		{
			if(old_pos.x < 196)old_pos.x = 196;
			if(old_pos.y < 365)old_pos.y = 365;
		}
		else if(end_cliping_flag == 2)
		{
			if(old_pos.x > 32767-196)old_pos.x = 32767-196;
			if(old_pos.y < 365)old_pos.y = 365;
		}						
		else if(end_cliping_flag == 3)
		{
			if(old_pos.x < 196)old_pos.x = 196;
			if(old_pos.y > 32767-365)old_pos.y = 32767-365;
		}
		else if(end_cliping_flag == 4)
		{
			if(old_pos.x > 32767-196)old_pos.x = 32767-196;
			if(old_pos.y > 32767-365)old_pos.y = 32767-365;
		}	

		pos2->x=old_pos.x;
		pos2->y=old_pos.y;
		
		if(bReportDelayFlag)bReportDelayFlag=0;	
	}
}
#endif

tXY_t testcrood;
void algorithm_OutInCheck(void)
{
	if(thisInfo->bIsOutIn == YES){
		for(int i=MAX_TOUCH_; i--; ){
			if(thisInfo->tCoord.bOutInFlag[i]==YES && thisInfo->tCoord.tPastPos[0].vusS[i] > 0){
				//thisInfo->tCoord.tPos.tXY[i] = thisInfo->tCoord.tOutInPos.tXY[i];
				
				thisInfo->tCoord.tPos.tXY[i].x = (thisInfo->tCoord.tOrgPos.tXY[i].x + thisInfo->tCoord.tPastPos[0].tXY[i].x)/2;
				thisInfo->tCoord.tPos.tXY[i].y = (thisInfo->tCoord.tOrgPos.tXY[i].y + thisInfo->tCoord.tPastPos[0].tXY[i].y)/2;
				
//				thisInfo->tCoord.tPos.tXY[i] = thisInfo->tCoord.tFirstOutInPos.tXY[i];
//				thisInfo->tCoord.tPos.vusS[i] = thisInfo->tCoord.tFirstOutInPos.vusS[i];
//				testvusS = thisInfo->tCoord.tFirstOutInPos.vusS[i];
				
				//testcrood = thisInfo->tCoord.tPos.tXY[i];
				thisInfo->tCoord.bOutInFlag[i] = NO;
				thisInfo->tCoord.bOutInFlag2[i] = NO;
			}
		}
	
		algorithm_PendTouchEvent();
		//algorithm_coord_UpdatePosHistoryInfo();
		algorithm_coord_UpdatePosHistoryInfo_OutInDrawing();
		
		thisInfo->bIsOutIn = NO;
		pendflag++;
		
//		for(int i=MAX_TOUCH_; i--; ){
//			if(thisInfo->tCoord.bOutInFlag[i]==YES && thisInfo->tCoord.tPastPos[0].vusS[i] > 0){
//				thisInfo->tCoord.bOutInFlag[i] = NO;
//				thisInfo->tCoord.bOutInFlag2[i] = NO;
//			}
//		}
	}
}

extern int hid_index;
extern int HID_status[];
extern int HID_id[];
extern int HID_x[];
extern int HID_y[];
extern void protocol_hid_PushTouchEvent(const uSWIPTouchItem_t* _kptItem);
//extern uint8_t	g_ConnectedDevice;
void algorithm_PendTouchEvent(void)
{
	int i;
	int distX, distY;
	tXY_t pos, old_pos;
	uint8_t ucMoveTHD_X,ucMoveTHD_Y;

#if (ID_MAPPING_CHANGE)
static uint8_t NewID = 50;
static uint8_t Id_Map[MAX_TOUCH_] = {0,};
static uint16_t NonTouchCnt = 0;
#endif

	hal_set_overlap_pen();

	memset(HID_status,0,HID_MAX_TOUCH);
	memset(HID_id,0,HID_MAX_TOUCH);
	memset(HID_x,0,HID_MAX_TOUCH);
	memset(HID_y,0,HID_MAX_TOUCH);

	eSWIPPacketFormatId_t id = protocol_swip_GetPacketFormatId();
#define SET_POS(tItem, pos)  \
	do{    \
			(tItem).tItem00.ucXHigh = ((pos).x >> 8) & 0xFF;    \
			(tItem).tItem00.ucYHigh = ((pos).y >> 8) & 0xFF;    \
			(tItem).tItem00.ucXLow = (pos).x & 0xFF;    \
			(tItem).tItem00.ucYLow = (pos).y & 0xFF;    \
		} while(0)

	//if(g_ConnectedDevice == I2C_CONNECT_PC)
	{
		protocol_swip_InitTouchEventBuffer();
		//    protocol_hid_InitTouchEventBuffer();
	}
	
	hid_index=0;
	
#if (SWIP_QUEUE_MODE)
	thisInfo->bQueueStart 	= 0;
	#if (SWIP_QUEUE_MODE == 2)
		thisInfo->bTouchOffFlag	= 0;
	#endif
#endif

#if USED_SHARP_SPECIFIC_PROTOCOL
	tTouchItemType_t touchItemType;
	memset(&touchItemType, 0, sizeof(tTouchItemType_t));
	/*
	 * TODO : finger mode¸¦ ±âº»À¸·Î ¼³Á¤.
	 * algorithmÀ» °ÅÄ£ ÈÄ touch type¿¡ µû¸¥ flag¸¦ setting ÇØ¾ß ÇÔ.
	 */
	touchItemType.active_stylus_hover = YES;
	touchItemType.active_stylus = YES;
	touchItemType.passive_stylus = YES;
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */

#ifdef LocalFingerNoiseRemove
	#if (PEN_FINGER_1TOUCH_REPORT == NO)
	if(thisInfo->bLocal_sensing == YES /*&& thisInfo->tCoord_local_dsp.PenContactCnt < 100*/)
	{	
		uint8_t Label_num = 0;
		for( i=MAX_TOUCH_; i--; )
		{		
			if (thisInfo->tCoord.tPos.vusS[i] > 0)
			{
				Label_num++;
			}
		}
	
		for( i=MAX_TOUCH_; i--; )
		{
			distX = algorithm_coord_calc_distance(thisInfo->tCoord.tPos.tXY[i], thisInfo->tCoord_local_dsp.tPos.tXY);
			
			if( distX > 1024 && ((thisInfo->tCoord.tPos.MaxDelta[i] > thisModeConf->CoordTracking.sFirstTouchOnMaxCellVal && Label_num > 1) || (thisInfo->tCoord.tPos.MaxDelta[i] > (thisModeConf->CoordTracking.sFirstTouchOnMaxCellVal+20) && Label_num == 1)) )
			{
			}
			else
			{
				thisInfo->tCoord.tPos.vusS[i] = 0;
				thisInfo->tCoord.cScreenDebCnt[i] = 0;
			}
		}
	}
	#endif
#endif
	
	if(thisModeConf->Palm.bPalm_WholeTouchRemove && thisInfo->bIsPalm == YES)
	{
		for( i=MAX_TOUCH_; i--; )thisInfo->tCoord.tPos.vusS[i] = 0;
	}

#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN	
	algorithm_EdgeReportDelay();
#endif
	
	for (i = 0; i < MAX_TOUCH_; i++)
	{
		//        bool_t bIsHover = NO;
		if (thisInfo->tCoord.tPastSentPos.vusS[i] > 0)
		{
//			old_pos = thisInfo->tCoord.tPastSentPos.tXY[i];
//			alogorithm_coord_modify_pos(&old_pos,&old_pos, i);
			old_pos.x = thisInfo->tCoord.tRealPastSentPos.tXY[i].x;
			old_pos.y = thisInfo->tCoord.tRealPastSentPos.tXY[i].y;
			
			//Heon
			if(thisInfo->tCoord.bOutInFlag2[i] == YES && thisInfo->bIsOutIn == YES && thisInfo->tCoord.bOutInFlag[i] == NO && thisInfo->tCoord.tPastPos[1].vusS[i] > 0){
				old_pos.x = thisInfo->tCoord.tPastPos[1].tXY[i].x;		//outinì´ ì•„ë‹Œ ìƒí™©ì—ì„œëŠ” ì¤‘ë³µëœ ì¢Œí‘œë¥¼ ë‚´ë³´ë‚´ê¸° ë•Œë¬¸
				old_pos.y = thisInfo->tCoord.tPastPos[1].tXY[i].y;
			}
			
			if(thisInfo->bIsOutIn == YES && thisInfo->tCoord.bOutInFlag[i] == NO && thisInfo->tCoord.tPastPos[1].vusS[i] > 0){
				thisInfo->tCoord.bOutInFlag2[i] = YES;	//outinì´ ì•„ë‹Œ ìƒí™©
			}
			//
		}

		if (thisInfo->tCoord.tPos.vusS[i] > 0)
		{
			pos = thisInfo->tCoord.tPos.tXY[i];			
			

				
//			if(thisModeConf->Palm.ucPalmDrawingOn > 1)
//				algorithm_width_height_calculation(i);

			if (thisInfo->tCoord.tPastSentPos.vusS[i] > 0)
				alogorithm_coord_modify_pos(&old_pos,&pos, i);
			else
				alogorithm_coord_modify_pos(&pos, &pos, i);
			
			if(testcnt < 10)		//Heon
				testArray[testcnt++] = pos;
			
			if(thisInfo->bIsOutIn == YES){
				realOutInPos = pos;
			}
		}
		//Heon
		if(thisInfo->tCoord.tPos.vusS[0] == 0){
			testcnt = 0;
		}
		//
		if (thisInfo->tCoord.tPos.vusS[i] > 0)
		{
#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN
			if(i == 0)algorithm_BigFingerEdgeAccTest(&pos,&old_pos,0);
#endif
			
			distX = pos.x - old_pos.x;
			distY = pos.y - old_pos.y;
			if (distY < 0)
			distY = -distY;
			if (distX < 0)
			distX = -distX;

			if (!thisInfo->tCoord.bFirstLongDistanceMoved[i])
			{
				ucMoveTHD_X = thisModeConf->Coord.ucFirstMoveEventTHD;
				ucMoveTHD_Y = thisModeConf->Coord.ucFirstMoveEventTHD;
			}
			else
			{
				ucMoveTHD_X = thisModeConf->Coord.ucMoveEventTHD;
				ucMoveTHD_Y = thisModeConf->Coord.ucMoveEventTHD;
			}

			
			if (thisInfo->tCoord.tPastSentPos.vusS[i] == 0 || (distY >= ucMoveTHD_Y) || (distX >= ucMoveTHD_X))
			{
#if (ID_MAPPING_CHANGE)
				if (thisInfo->tCoord.tPastSentPos.vusS[i] == 0 )
				{
					NewID++;
					if(NewID > 30)NewID=1;
					Id_Map[i] = NewID;
				}
#endif				
				uSWIPTouchItem_t tItem;
#if USED_SHARP_SPECIFIC_PROTOCOL
				tItem.tItem00.tInfo.b4FingerID = i + 1;					// id
				tItem.tItem00.tInfo.b1Status = TOUCH_STATUS_PRESS;		// status
				tItem.tItem00.tInfo.b6Type = (touchItemType.finger << TOUCH_TYPE_FINGER) |
									  (touchItemType.glove << TOUCH_TYPE_GLOVE) |
									  (touchItemType.hover << TOUCH_TYPE_HOVER) |
									  (touchItemType.passive_stylus << TOUCH_TYPE_PASSIVE_STYLUS) |
									  (touchItemType.active_stylus << TOUCH_TYPE_ACTIVE_STYLUS) |
									  (touchItemType.active_stylus_hover << TOUCH_TYPE_ACTIVE_STYLUS_HOVER);
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.tInfo.bTouch = YES;
				tItem.tItem00.tInfo.bHover = NO;
				tItem.tItem00.tInfo.bScreen = YES;
				tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
	#if (ID_MAPPING_CHANGE)
				tItem.tItem00.tInfo.b4FingerID = Id_Map[i];
	#else
				tItem.tItem00.tInfo.b4FingerID = i + 1;
	#endif
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.ucRowStart = 0;

				SET_POS(tItem, pos);
				tItem.tItem00.ucWidth = MIN(thisInfo->tCoord.tPos.vusR[i], UINT8_MAX);
				//                tItem.tItem00.ucWidth = thisInfo->tCoord.cScreenDebCnt[i];
				
//				tItem.tItem02.usWidth = thisInfo->tCoord.tPos.vusW[i];
//				tItem.tItem02.usHeight = thisInfo->tCoord.tPos.vusH[i];
				
				if(id == 0)
				{
					tItem.tItem00.usStrength = thisInfo->tCoord.tPos.vusS[i];
				}
#if !(ID_MAPPING_CHANGE)
				protocol_swip_PushTouchEvent(&tItem);
#endif				
				protocol_hid_PushTouchEvent(&tItem);

				if (thisInfo->tCoord.tPastSentPos.vusS[i] > 0 && ((distY >= ucMoveTHD_Y) || (distX >= ucMoveTHD_X)) ) //distance moved.
				{
					thisInfo->tCoord.bFirstLongDistanceMoved[i] = YES;
				}
				else //1st touch.
				{
					thisInfo->tCoord.bFirstLongDistanceMoved[i] = NO;
				}

				thisInfo->tCoord.tPastSentPos.tXY[i].x = thisInfo->tCoord.tPos.tXY[i].x;
				thisInfo->tCoord.tPastSentPos.tXY[i].y = thisInfo->tCoord.tPos.tXY[i].y;
				thisInfo->tCoord.tPastSentPos.vusS[i] = thisInfo->tCoord.tPos.vusS[i];
				thisInfo->tCoord.tPastSentPos.vusR[i] = thisInfo->tCoord.tPos.vusR[i];
//				thisInfo->tCoord.tPastSentPos.vusW[i] = thisInfo->tCoord.tPos.vusW[i];
//				thisInfo->tCoord.tPastSentPos.vusH[i] = thisInfo->tCoord.tPos.vusH[i];
				
				thisInfo->tCoord.tRealPastSentPos.tXY[i].x = pos.x;
				thisInfo->tCoord.tRealPastSentPos.tXY[i].y = pos.y;
				
				if(thisInfo->bIsOutIn == YES)
					pendcheck++;
			}
			else
			{
				uSWIPTouchItem_t tItem;
#if USED_SHARP_SPECIFIC_PROTOCOL
				tItem.tItem00.tInfo.b4FingerID = i + 1;					// id
				tItem.tItem00.tInfo.b1Status = TOUCH_STATUS_PRESS;		// status
				tItem.tItem00.tInfo.b6Type = (touchItemType.finger << TOUCH_TYPE_FINGER) |
									  (touchItemType.glove << TOUCH_TYPE_GLOVE) |
									  (touchItemType.hover << TOUCH_TYPE_HOVER) |
									  (touchItemType.passive_stylus << TOUCH_TYPE_PASSIVE_STYLUS) |
									  (touchItemType.active_stylus << TOUCH_TYPE_ACTIVE_STYLUS) |
									  (touchItemType.active_stylus_hover << TOUCH_TYPE_ACTIVE_STYLUS_HOVER);
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.tInfo.bTouch = YES;
				tItem.tItem00.tInfo.bHover = NO;
				tItem.tItem00.tInfo.bScreen = YES;
				tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
	#if (ID_MAPPING_CHANGE)
				tItem.tItem00.tInfo.b4FingerID = Id_Map[i];
	#else
				tItem.tItem00.tInfo.b4FingerID = i + 1;
	#endif
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
				tItem.tItem00.ucRowStart = 0;
				SET_POS(tItem, old_pos);
				tItem.tItem00.ucWidth = MIN(thisInfo->tCoord.tPos.vusR[i], UINT8_MAX);

				//To do	-> Old Width, Height
//				tItem.tItem02.usWidth = thisInfo->tCoord.tPos.vusW[i];
//				tItem.tItem02.usHeight = thisInfo->tCoord.tPos.vusH[i];
				
				if(id == 0)
				{
					tItem.tItem00.usStrength = thisInfo->tCoord.tPos.vusS[i];
				}
#if !(ID_MAPPING_CHANGE)
				protocol_swip_PushTouchEvent(&tItem);
#endif				
				protocol_hid_PushTouchEvent(&tItem);
				
			}
#if USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE
			thisInfo->bIsIdleToActive = NO;
#endif /* USED_IDLE_CORNER_EDGE_DEBOUNC_DISABLE */
		}
		else if (thisInfo->tCoord.tPastSentPos.vusS[i] > 0)
		{
			
		#if (SWIP_QUEUE_MODE == 2)
			thisInfo->bTouchOffFlag = 1;
		#endif
			
			uSWIPTouchItem_t tItem;
#if USED_SHARP_SPECIFIC_PROTOCOL
			tItem.tItem00.tInfo.b4FingerID = i + 1;					// id
			tItem.tItem00.tInfo.b1Status = TOUCH_STATUS_RELEASE;		// status
			tItem.tItem00.tInfo.b6Type = (touchItemType.finger << TOUCH_TYPE_FINGER) |
								  (touchItemType.glove << TOUCH_TYPE_GLOVE) |
								  (touchItemType.hover << TOUCH_TYPE_HOVER) |
								  (touchItemType.passive_stylus << TOUCH_TYPE_PASSIVE_STYLUS) |
								  (touchItemType.active_stylus << TOUCH_TYPE_ACTIVE_STYLUS) |
								  (touchItemType.active_stylus_hover << TOUCH_TYPE_ACTIVE_STYLUS_HOVER);
#else /* USED_SHARP_SPECIFIC_PROTOCOL */
			tItem.tItem00.tInfo.bTouch = NO;
			tItem.tItem00.tInfo.bHover = NO;
			tItem.tItem00.tInfo.bScreen = YES;
			tItem.tItem00.tInfo.bPalm = thisInfo->bIsPalm;
	#if (ID_MAPPING_CHANGE)
			tItem.tItem00.tInfo.b4FingerID = Id_Map[i];
	#else
			tItem.tItem00.tInfo.b4FingerID = i + 1;
	#endif
#endif /* USED_SHARP_SPECIFIC_PROTOCOL */
			tItem.tItem00.ucRowStart = 0;

#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN
			if(i == 0)algorithm_BigFingerEdgeAccTest(&pos,&old_pos,1);			
#endif
			
			SET_POS(tItem, old_pos);	
			tItem.tItem00.ucWidth = 0;
			//			thisInfo->bGhostState = NO;

			if(id == 0)
			{
				tItem.tItem00.usStrength =thisInfo->tCoord.tPos.vusS[i];
			}

			thisInfo->tCoord.bFirstLongDistanceMoved[i] = NO;
#if !(ID_MAPPING_CHANGE)
			protocol_swip_PushTouchEvent(&tItem);
#endif
			protocol_hid_PushTouchEvent(&tItem);
		}
		thisInfo->tCoord.tPastSentPos.vusS[i] = thisInfo->tCoord.tPos.vusS[i];
	}
#if (SWIP_QUEUE_MODE)
	if(thisInfo->bQueueStart == 1){
	#if (SWIP_QUEUE_MODE == 2)
		if(thisInfo->QueueFront == thisInfo->QueueRear || thisInfo->bTouchOffFlag )
	#endif
		{
			thisInfo->QueueRear++;
			thisInfo->QueueRear = (thisInfo->QueueRear) % SWIP_QUEUE_SIZE;
		}
	}
#endif	
	//¡Æu¡ÆA A¢´¨¬¢¬ ¢¬©£¥ìI ¨ú¡À¥ì¡ÍAI¨¡¢ç.
	thisInfo->tCoord.tPastSentPos.sFinger_ = thisInfo->tCoord.tPos.sFinger_;
//	thisInfo->bWasPalm = thisInfo->bIsPalm;

//	if ((CheckI2CReady() == 0))
#if !(ID_MAPPING_CHANGE)
	protocol_swip_SendTouchEvent(); // ¿©±â¼­ »¸À½
#endif
//	 protocol_hid_SendTouchEvent();

#ifdef JOSH3_PEN_TEST
	SendPenData();
#else
#ifdef ADD_TOUCH
	SendTouchData();
#endif
#endif
#if (ID_MAPPING_CHANGE)	
	if(thisInfo->tCoord.tPos.sFinger_ == 0 && thisInfo->tCoord.tPastPos[0].sFinger_ == 0){if(NonTouchCnt++ > 32767)NonTouchCnt=30;}
	else NonTouchCnt = 0;
	
	if(NonTouchCnt >= 30)
	{
		NewID = 30;
		memset(Id_Map,0,sizeof(Id_Map));
	}
#endif	
	hal_clear_overlap_pen();

#if BIG_FINGER_EDGE_ACC_TEST_ALGO_EN
	if(thisInfo->tCoord.tPos.sFinger_==0 || thisInfo->tCoord.tPos.sFinger_>1)
	{
		if(bBigFingerEdgeTestEn[0] || bBigFingerEdgeTestEn[1] || bBigFingerEdgeTestEn[2] || bBigFingerEdgeTestEn[3])
		{
			ucBigFingerEdgeTest_MoveEventTHD_Change=0;
			memset(bBigFingerEdgeTestFlag,0,sizeof(bBigFingerEdgeTestFlag));
			if(thisInfo->tCoord.tPos.sFinger_==0)bBigFingerEdgeTestEn[0]=bBigFingerEdgeTestEn[1]=bBigFingerEdgeTestEn[2]=bBigFingerEdgeTestEn[3]=0;
		}
	}	
#endif
	
}

void algorithm_check_recal_cond(void)
{
	thisInfo->bIsRecalCond  = NO;
	thisInfo->bIsRecalCond2 = NO;

	thisInfo->bIsRecalCond = (
			   (thisInfo->tDelta.iPosSum >= thisModeConf->BaseLine.iRecalCond1_PosSum_Thd)
			&& ((thisInfo->tDelta.iNegSum + thisInfo->tDelta.iPosSum) < thisModeConf->BaseLine.iRecalCond1_AccSum_Thd)
	);
	thisInfo->bIsRecalCond2 = (
			   (thisInfo->bTouchExpect == NO)
			&& (thisInfo->tDelta.iNegSum < thisModeConf->BaseLine.iRecalCond2_AccSum_Thd)
	);
}

bool_t algorithm_is_recalibrate(void)
{
  
    /*
     * Debouncing.
     */
    if (thisInfo->bIsRecalCond)
    {
        if (thisInfo->iRecalCondCnt <= thisModeConf->BaseLine.ucRecalCond1_WaitCnt)
        {
            thisInfo->iRecalCondCnt++;
        }
        else
        {
            thisInfo->iRecalCondCnt = 0;   // added
            return YES;
        }
    }
    else if (thisInfo->bIsRecalCond2)
    {
        if (thisInfo->iRecalCond2Cnt <= thisModeConf->BaseLine.ucRecalCond2_WaitCnt)     // 300 msec
        {
        	thisInfo->iRecalCond2Cnt++;
        }
        else
        {
        	thisInfo->iRecalCond2Cnt = 0;   // added
            return YES;
        }
    }
    else
    {
        thisInfo->iRecalCondCnt = 0;
        thisInfo->iRecalCond2Cnt = 0;
    }

    return NO;
}

#if (USED_PEN_MODE_OPERATION && LOCAL_REBASE_ALGO_EN)	
void algorithm_check_recal_pen(void)
{
	if(thisInfo->tDelta_local.iNegSum < thisModeConf->BaseLine.iRecalCond2_AccSum_Thd)
		thisInfo->bIsRecalCondLocal = YES;
}
#endif

#define PALM_VALID_AREA		(22 << POS_BOOST_SHIFT_)
#define PALM_KEEP_FRM		(10)
void public_func_PalmTouch_handler(void)
{
	static uint8_t ucFrameCnt[POSBUF_]  = {0,};
//	static uint16_t usPrevMaxCellNum[POSBUF_]  = {0,}; // NOTE : Not used!!
	static uint8_t ucPalmContCnt[POSBUF_]  = {0,};
	static uint8_t ucParNum[POSBUF_]  = {0,};
	static tXY_t ucPalmPos[POSBUF_] ;
	static tRect_t ucPalmRect[POSBUF_] ;
	uint8_t ucParCnt[POSBUF_] = {0,};
	uint8_t ucParBF[POSBUF_] = {0,};
	bool_t bIsPalm[POSBUF_] = {0,};
	uint8_t ucPalmExpect[POSBUF_] = {0,};
	int cl;
	
//    if(!sptPalmTouchConf->bEnable) return;

//	tMemConf_t       * ptMemConf = (tMemConf_t *)param1;
//	tAlgorithmInfo_t * ptInfo     = (tAlgorithmInfo_t *)param2;

//	sptPalmTouchConf->bPalmExpect = NO;

	thisInfo->bIsPalm = NO;
	
	for( cl=MAX_TOUCH_; cl--; )
	{
		if(thisInfo->tCoord.tPos.vusR[cl] != 0)
		{
			if(thisInfo->tCoord.tPos.vusR[cl] > thisModeConf->Palm.usPalmLevel)
			{
				bIsPalm[cl] = YES;
				ucParNum[cl] = cl;
				ucPalmPos[cl] = thisInfo->tCoord.tPos.tXY[cl];
			}
//			else if(ucFrameCnt[cl] < 10
//				&& ((thisInfo->tCoord.tPos.vusR[cl] > 10
//				&& (int16_t)(thisInfo->tCoord.tPos.vusR[cl] - usPrevMaxCellNum[cl]) > 3 )
//				|| ((int16_t)(thisInfo->tCoord.tPos.vusR[cl] - usPrevMaxCellNum[cl]) > (3*2+1))))
//			{
//				thisInfo->tCoord.tPos.vusS[cl] = 0;
//				ucPalmExpect[cl] = 1;
//			}
			else
			{
				int pl, i;
				uint8_t ucOverlap[POSBUF_] = {0,};
				uint8_t ucOverlapCnt = 0;

				for( pl=MAX_TOUCH_; pl--; )
				{
					if(ucPalmContCnt[pl] != 0)
					{
						if(ucPalmRect[pl].rs <= thisInfo->tCoord.tPos.rect[cl].re && thisInfo->tCoord.tPos.rect[cl].rs <= ucPalmRect[pl].re)
						{
							if(ucPalmRect[pl].cs <= thisInfo->tCoord.tPos.rect[cl].ce && thisInfo->tCoord.tPos.rect[cl].cs <= ucPalmRect[pl].ce)
								ucOverlap[ucOverlapCnt++] = pl;
						}
					}
				}

				if(ucOverlapCnt != 0)
				{
					if(ucOverlapCnt > 1)
					{
						int palm_dist;
						int min_dist = INT32_MAX;

						for(i=0; i<ucOverlapCnt; i++)
						{
							palm_dist = algorithm_coord_calc_distance(ucPalmPos[ucOverlap[i]], thisInfo->tCoord.tPos.tXY[cl]);
							if(min_dist > palm_dist)
								min_dist = palm_dist, pl = ucOverlap[i];
						}
					}
					else
						pl = ucOverlap[0];

					bIsPalm[cl] = YES;
					ucParCnt[pl]++;
					ucParBF[pl] |= _BV(cl);
					if(ucPalmContCnt[cl] == 0)
						ucParNum[cl] = ucParNum[pl];

					ucPalmPos[cl] = thisInfo->tCoord.tPos.tXY[cl];
				}
			}

			if( ucFrameCnt[cl] < 10 )
				ucFrameCnt[cl]++;
		}
		else
			ucFrameCnt[cl] = 0;
	}

	for( cl=MAX_TOUCH_; cl--;)
	{
		if(ucParCnt[cl] > 1)
		{
			int max_palm_num = -1;
			int max_palm_size = 0;

			if(bIsPalm[cl] == NO)
			{
				int pl;

				for( pl=MAX_TOUCH_; pl--;)
				{
					if((ucParBF[cl] & _BV(pl)) != 0)
					{
						if(max_palm_size < thisInfo->tCoord.tPos.vusR[pl])
						{
							max_palm_num = pl;
							max_palm_size = thisInfo->tCoord.tPos.vusR[pl];
						}
					}
				}

				for( pl=MAX_TOUCH_; pl--;)
				{
					if((ucParBF[cl] & _BV(pl)) != 0)
						ucParNum[pl] = max_palm_num;
				}

				ucPalmContCnt[cl] = 0;
			}
		}
	}

	for( cl=MAX_TOUCH_; cl--;)
	{
		if(bIsPalm[cl] == YES)
		{
			if(ucParNum[cl] != cl)
			{
				int pl = ucParNum[cl];
				int palm_dist;

				if(thisInfo->tCoord.tPos.vusR[pl] == 0 && ucPalmContCnt[cl] != 0)
				{
					int pcl;
					int max_palm_num = -1;
					int max_palm_size = 0;

					for( pcl=MAX_TOUCH_; pcl--;)
					{
						if(pcl != cl && bIsPalm[pcl] == YES)
						{
							if(ucPalmRect[pl].rs <= thisInfo->tCoord.tPos.rect[pcl].re && thisInfo->tCoord.tPos.rect[pcl].rs <= ucPalmRect[pl].re)
							{
								if(max_palm_size < thisInfo->tCoord.tPos.vusR[pcl])
									max_palm_size = thisInfo->tCoord.tPos.vusR[pcl], max_palm_num = pcl;
							}
						}
					}

					if(max_palm_num != -1)
					{

						ucParNum[cl] = max_palm_num;
						for( pcl=MAX_TOUCH_; pcl--;)
						{
							if(ucPalmContCnt[pcl] != 0)
							{
								if(ucParNum[pcl] == pl)
									ucParNum[pcl] = max_palm_num;
							}
						}
					}
					else
						ucParNum[cl] = cl;
				}

				if(ucPalmContCnt[pl] != 0)
				{
					palm_dist = algorithm_coord_calc_distance(ucPalmPos[pl], ucPalmPos[cl]);
					if(PALM_VALID_AREA < palm_dist)
						bIsPalm[cl] = NO;
				}
				else
					bIsPalm[cl] = NO;
			}
		}

		if(bIsPalm[cl] == YES)
		{
			ucPalmExpect[cl] = 1;
			ucPalmContCnt[cl] = PALM_KEEP_FRM;
			ucPalmRect[cl] = thisInfo->tCoord.tPos.rect[cl];
			ucPalmPos[cl] = thisInfo->tCoord.tPos.tXY[cl];
			thisInfo->tCoord.tPos.vusS[cl] = 0;

			if(ucPalmRect[cl].rs > 0)
				ucPalmRect[cl].rs--;
			if(ucPalmRect[cl].re < (ROW_MAX - 1))
				ucPalmRect[cl].re++;
			if(ucPalmRect[cl].cs > 0)
				ucPalmRect[cl].cs--;
			if(ucPalmRect[cl].ce < (COL_MAX - 1))
				ucPalmRect[cl].ce++;
			
			thisInfo->bIsPalm = YES;
			thisInfo->tCoord.tPos.sFinger_--;
		}
	}

	for( cl=MAX_TOUCH_; cl--;)
	{
		if(ucPalmExpect[cl] != 0)
		{
			int pl;
//			tRect_t ori_rect, cmp_rect; // NOTE : not used
			tRect_t ori_rect;

#if (CUSTOMER == MODEL_DEF_QHD_92407 || CUSTOMER == MODEL_DEF_QHD_92407_FLIP)
			int offset = 5;
#else
			int offset = 1;
#endif
			
            if(thisInfo->tCoord.tPos.rect[cl].rs > (offset-1))
				ori_rect.rs = thisInfo->tCoord.tPos.rect[cl].rs - offset;
            else
                ori_rect.rs = 0;
			if(thisInfo->tCoord.tPos.rect[cl].re < (ROW_MAX - offset))
				ori_rect.re = thisInfo->tCoord.tPos.rect[cl].re + offset;
            else
                ori_rect.re = ROW_MAX - 1;
			if(thisInfo->tCoord.tPos.rect[cl].cs > (offset-1))
				ori_rect.cs = thisInfo->tCoord.tPos.rect[cl].cs - offset;
            else
                ori_rect.cs = 0;
			if(thisInfo->tCoord.tPos.rect[cl].ce < (COL_MAX - offset))
				ori_rect.ce = thisInfo->tCoord.tPos.rect[cl].ce + offset;
            else
                ori_rect.ce = COL_MAX - 1;
            
            for( pl=MAX_TOUCH_; pl--;)
			{
				if(thisInfo->tCoord.tPos.vusS[pl])
				{
					if(ori_rect.rs <= thisInfo->tCoord.tPos.rect[pl].re+1 && thisInfo->tCoord.tPos.rect[pl].rs-1 <= ori_rect.re)
					{
						if(ori_rect.cs <= thisInfo->tCoord.tPos.rect[pl].ce+1 && thisInfo->tCoord.tPos.rect[pl].cs-1 <= ori_rect.ce)
						{
							thisInfo->tCoord.tPos.vusS[pl] = 0;
						}
					}
				}
			}
		}

		if(ucPalmContCnt[cl] != 0)
			ucPalmContCnt[cl]--;

//		usPrevMaxCellNum[cl] = thisInfo->tCoord.tPos.vusR[cl];  // NOTE : Not used!!		
	}

//	public_protocol_LogCode(LT_DIAGNOSIS, (220)/*System is Entered!*/);
}

int16_t sLFOffsetRow[ROW_MAX] = {0,};
/*
 * Àü Line¿¡´ëÇØ Even Col¿¡´ëÇØ Filter¸¦ µ¿ÀÛ ½ÃÅ³ °æ¿ì, 951usecÀÇ ¼öÇà ¼Óµµ
 */
void alogorithm_linefilter_2(void)
{
	uint32_t r, c;
	uint32_t i, j;
	int16_t d;
	int16_t SortBufCol[COL_MAX], TempBuf;
	uint8_t sort_cnt, sort_range;
	int16_t sub_offset;
	uint16_t * pBaseImage;
	int Max_Val, Min_Val;
	int lDiff, lDiffSum = 0, lDiffSumCnt = 0;
	int min_delta_th = (thisModeConf->SensingFilter.ucMinDeltaTh << ptModuleModeConf->ucOvrShift);
	int lUpperTHD = thisModeConf->SensingFilter.sLineFilterUpLimit<<ptModuleModeConf->ucOvrShift, lLowTHD = thisModeConf->SensingFilter.sLineFilterLowLimit<<ptModuleModeConf->ucOvrShift;
//	eActivePenType_t eLocalFingerOPType = hal_Info_GetControlLocalFingerOPType();

	//int max_compan_val = 11;
#if (ROW_MAX == 45)
	uint8_t do_row[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44};
#elif (ROW_MAX == 47)
	uint8_t do_row[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46};
#elif (ROW_MAX == 48)
	uint8_t do_row[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47};
#elif (ROW_MAX == 50)
	uint8_t do_row[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
#endif
	uint8_t row_cnt = sizeof(do_row);
	uint8_t real_row;
	
	sort_cnt = 4;//(uint8_t)(((int)COL_MAX * 5)/100);
	sort_range = COL_MAX/4 + COL_MAX%4;

#if USED_NOISE_HOPPING_FREQ
	if(ptAppInfo->eCurrentSelectFreq == FREQ_MAIN)
//	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	{
		pBaseImage = g_pFingerBaseImage;
	}
	else
	{
		pBaseImage = g_pFingerHop1BaseImage;
	}
#else /* USED_NOISE_HOPPING_FREQ */
	pBaseImage = g_pFingerBaseImage;//HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
#endif /* USED_NOISE_HOPPING_FREQ */
	
	for(r = 0; r < row_cnt; r++)
	{
		real_row = do_row[r];
		lDiffSum = 0, lDiffSumCnt = 0;
		Max_Val = INT16_MIN, Min_Val = INT16_MAX;
		for( c = 0; c < sort_range; c++ )
		{
			SortBufCol[c] = lDiff = (int16_t)HAL_READ_RAW_IMAGE(real_row, (c*4)) - (int16_t)pBaseImage[real_row*COL_MAX + c*4];
			
			if(lDiff < lUpperTHD && lDiff > lLowTHD)
			{
				if(Max_Val < lDiff)Max_Val = lDiff;
				if(Min_Val > lDiff)Min_Val = lDiff;
				lDiffSum += lDiff;
				lDiffSumCnt++;
			}
		}
		
		if(min_delta_th && Min_Val < -min_delta_th && thisInfo->tLabel.ucPalmCnt < 10)
		{
			if(lDiffSumCnt > 3)
			{
				sLFOffsetRow[real_row] = lDiffSum / ((int16_t)lDiffSumCnt);
			}
		}
		else
		{
			for( i=0; i<=(sort_cnt); i++ )
			{
				for( j=(i+1); j<sort_range; j++ )
				{
					if( SortBufCol[i] > SortBufCol[j] )
					{
						TempBuf = SortBufCol[i];
						SortBufCol[i] = SortBufCol[j];
						SortBufCol[j] = TempBuf;
					}
				}
			}
			TempBuf = SortBufCol[sort_cnt];
			
			sLFOffsetRow[real_row] = TempBuf;
		}
	}

#if !FAST_LF_EN		
	for(r = 0; r < row_cnt; r++)
	{
		real_row = do_row[r];
		for( c=0; c<COL_MAX; c++ )
		{
			d = (int16_t)HAL_READ_RAW_IMAGE(real_row, c);
			sub_offset = sLFOffsetRow[real_row];
			d = d - sub_offset;
			if(d < 0)
			{
				d = 0;
			}
			HAL_WRITE_RAW_IMAGE(real_row, c, (uint16_t)d);
		}
	}
#endif
}
#if FINGER_LF_VER1_EN
void alogorithm_linefilter(eSENSING_MODE_t eSensingMode)
{
	uint32_t r, c;
	uint16_t r_pos;
	int16_t LINE_FILTER_UPPER_LIMIT			= thisModeConf->SensingFilter.sLineFilterUpLimit<<ptModuleModeConf->ucOvrShift;
	int16_t LINE_FILTER_LOWER_LIMIT			= thisModeConf->SensingFilter.sLineFilterLowLimit<<ptModuleModeConf->ucOvrShift;
	uint8_t LINE_FILTER_COL_OFFSET			= (thisModeConf->SensingFilter.ucLineFilterColOffset);
	
	int16_t lDiff;
	int16_t lDiffSum = 0, lDiffSum2 = 0;
	uint32_t lDiffSumCnt = 0, lDiffSumCnt2 = 0;
	int32_t lLowTHD, lUpperTHD;
	uint16_t * pBaseImage;
	uint16_t rawdata;
	eActivePenType_t eLocalFingerOPType = hal_Info_GetControlLocalFingerOPType();

	lUpperTHD = LINE_FILTER_UPPER_LIMIT;
	lLowTHD = LINE_FILTER_LOWER_LIMIT;

#if USED_NOISE_HOPPING_FREQ
	if(ptAppInfo->eCurrentSelectFreq == FREQ_MAIN)
//	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	{
		pBaseImage = g_pFingerBaseImage;
	}
	else
	{
		pBaseImage = g_pFingerHop1BaseImage;
	}
//	pBaseImage = HAL_GET_FREQ_BASELINE_PTR(ptAppInfo->eSelectFreq);
#else /* USED_NOISE_HOPPING_FREQ */
	pBaseImage = g_pFingerBaseImage;//HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
#endif /* USED_NOISE_HOPPING_FREQ */

	int Max_Val, Min_Val;
	int LineFilterRepeatTH = thisModeConf->SensingFilter.ucLineFilterRepeatTH << ptModuleModeConf->ucOvrShift;
#if USED_TOUCH_TUNING_PROCESS
	LineFilterRepeatTH = 0;
#endif /* USED_TOUCH_TUNING_PROCESS */
	for(r=0; r<ROW_MAX; r++)
	{
		lDiffSumCnt2 = 0;
		lDiffSum2 = 0;
		
		Max_Val = 0;
//		Avg_Val = 0;
		Min_Val = 32767;
		r_pos = r*COL_MAX;
		for(c = 0; c < COL_MAX; c+=LINE_FILTER_COL_OFFSET)
		{
			rawdata = HAL_READ_RAW_IMAGE(r, c);
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
			if(rawdata > 0)
#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
			{
				lDiff = (int16_t)(rawdata - pBaseImage[r_pos+c]);
				//pBaseImage += LINE_FILTER_COL_OFFSET;
				if(lDiff < lUpperTHD && lDiff > lLowTHD)
				{
					if(Max_Val < lDiff)Max_Val = lDiff;
					if(Min_Val > lDiff)Min_Val = lDiff;
					lDiffSum2 += lDiff;
					lDiffSumCnt2++;
				}
			}
		}

		if(LineFilterRepeatTH > 0 && Max_Val - Min_Val > LineFilterRepeatTH  &&
				(eLocalFingerOPType!=ACTIVEPEN_TYPE_LOCAL_MS || (eLocalFingerOPType==ACTIVEPEN_TYPE_LOCAL_MS && hal_Info_GetPenDectionEnable() == NO))
				&& Min_Val > thisModeConf->SensingFilter.cLineFilterMinTH<<ptModuleModeConf->ucOvrShift && thisInfo->bLineFilterRepeatCheck)
		{
			lDiffSumCnt = 0;
			lDiffSum = 0;
			for(c = 0; c < COL_MAX; c+=LINE_FILTER_COL_OFFSET)
			{
				rawdata = HAL_READ_RAW_IMAGE(r, c);
#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
				if(rawdata > 0)
#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
				{
					lDiff = (int16_t)(rawdata - pBaseImage[r_pos+c]);
					if(lDiff < lUpperTHD && lDiff > lLowTHD)
					{
						if(abs(Max_Val - lDiff) > abs(Min_Val - lDiff))
						{
							lDiffSum += lDiff;
							lDiffSumCnt++;
						}
					}
				}
			}
		}
		else
		{
			lDiffSumCnt = lDiffSumCnt2;
			lDiffSum = lDiffSum2;
		}
		
		if(lDiffSumCnt > 3)
		{
			sLFOffsetRow[r] = lDiffSum / ((int16_t)lDiffSumCnt);

#if USED_TOUCH_TUNING_PROCESS
#include "app_tuning_process.h"
			gtuning_ctrl_RawTune_Type.ulGIPNoiseRowIndex_CheckBuf[gtuning_ctrl_RawTune_Type.ulVSync_TouchSync_Timing_Index][r] = sLFOffsetRow[r];
#endif /* USED_TOUCH_TUNING_PROCESS */

#if !FAST_LF_EN			
			for(c = 0; c < COL_MAX; c++)
			{
				rawdata = HAL_READ_RAW_IMAGE(r, c);
	#if USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS
				if(rawdata > 0 && rawdata > sLFOffsetRow[r])
	#else /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
				if(rawdata > sLFOffsetRow[r])
	#endif /* USED_ZERO_FINGER_RAWDATA_DONOT_PEN_PROCESS */
				{
					lDiff = (((int16_t)rawdata) - sLFOffsetRow[r]);
					if(lDiff < 0)lDiff = 0;
					HAL_WRITE_RAW_IMAGE(r, c, (uint16_t)lDiff);
				}
			}
#endif
		}
	}
}
#endif
void alogorithm_linefilter_simple(eSENSING_MODE_t eSensingMode)
{
	uint32_t r, c, pos;
	int16_t LINE_FILTER_UPPER_LIMIT			= thisModeConf->SensingFilter.sLineFilterUpLimit<<ptModuleModeConf->ucOvrShift;
	int16_t LINE_FILTER_LOWER_LIMIT			= thisModeConf->SensingFilter.sLineFilterLowLimit<<ptModuleModeConf->ucOvrShift;
	uint8_t LINE_FILTER_COL_OFFSET			= (thisModeConf->SensingFilter.ucLineFilterColOffset);
	
	int16_t lDiff;
	int16_t lDiffSum = 0;//, lDiffSum2 = 0;
	uint32_t lDiffSumCnt = 0;//, lDiffSumCnt2 = 0;
	int32_t lLowTHD, lUpperTHD;
	uint16_t * pBaseImage;
//	uint16_t rawdata;
//	eActivePenType_t eLocalFingerOPType = hal_Info_GetControlLocalFingerOPType();

	lUpperTHD = LINE_FILTER_UPPER_LIMIT;
	lLowTHD = LINE_FILTER_LOWER_LIMIT;

#if USED_NOISE_HOPPING_FREQ
	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	{
		pBaseImage = g_pFingerBaseImage;
	}
	else
	{
		pBaseImage = g_pFingerHop1BaseImage;
	}
//	pBaseImage = HAL_GET_FREQ_BASELINE_PTR(ptAppInfo->eSelectFreq);
#else /* USED_NOISE_HOPPING_FREQ */
	pBaseImage = g_pFingerBaseImage;//HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
#endif /* USED_NOISE_HOPPING_FREQ */

	pos = 0;
	for(r=0; r< ROW_MAX; r++, pos += COL_MAX)
	{
		lDiffSumCnt = 0;
		lDiffSum = 0;

		for(c = 0; c < COL_MAX; c+=LINE_FILTER_COL_OFFSET)
		{
			lDiff = (int16_t)(HAL_READ_RAW_IMAGE(r, c) - pBaseImage[pos+c]);
			if(lDiff < lUpperTHD && lDiff > lLowTHD)
			{
				lDiffSum += lDiff;
				lDiffSumCnt++;
			}
		}

		if(lDiffSumCnt > 3)
		{
			sLFOffsetRow[r] = lDiffSum / ((int16_t)lDiffSumCnt);
#if !FAST_LF_EN		
			for(c = 0; c < COL_MAX; c++)
			{
				lDiff = (((int16_t)HAL_READ_RAW_IMAGE(r, c)) - sLFOffsetRow[r]);
				if(lDiff<0)lDiff=0;
				HAL_WRITE_RAW_IMAGE(r, c, (uint16_t)lDiff);
			}
#endif
		}
	}
}

#if (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL)
void alogorithm_linefilter_idle(void)
{
	int32_t r, c;
	int16_t LINE_FILTER_UPPER_LIMIT			= (thisModeConf->SensingFilter.sLineFilterUpLimit_Idle) << ptModuleModeConf->ucIdleOvrShift; //thisModeConf->SensingFilter.sLineFilterUpLimit<<ptModuleModeConf->ucOvrShift;
	int16_t LINE_FILTER_LOWER_LIMIT			= (thisModeConf->SensingFilter.sLineFilterLowLimit_Idle) << ptModuleModeConf->ucIdleOvrShift; //thisModeConf->SensingFilter.sLineFilterLowLimit<<ptModuleModeConf->ucOvrShift;
	uint8_t LINE_FILTER_COL_OFFSET			= (thisModeConf->SensingFilter.ucLineFilterColOffset);
	int16_t sDiff;
	int16_t sDiffSum = 0;
	uint32_t ulDiffSumCnt = 0;

	uint16_t *pBaseImage, *pRawImage;

	pRawImage = HAL_NI_GET_RAW_IMAGE_PTR();
	pBaseImage = HAL_NI_GET_BASELINE_IMAGE_PTR();

	for(r = 0; r < NI_ROW_MAX; r++)
	{
		sDiffSum = 0;
		ulDiffSumCnt = 0;
		for(c = 0; c < COL_MAX; c+=LINE_FILTER_COL_OFFSET)
		{
			sDiff = (int16_t)(pRawImage[r*COL_MAX+c] - pBaseImage[r*COL_MAX+c]);
			if(sDiff < LINE_FILTER_UPPER_LIMIT || sDiff > LINE_FILTER_LOWER_LIMIT)
			{
				sDiffSum += sDiff;
				ulDiffSumCnt++;
			}
		}

		if(ulDiffSumCnt > 3)
		{
			sLFOffsetRow[r] = sDiffSum / ((int16_t)ulDiffSumCnt);

			for(c = 0; c < COL_MAX; c++)
			{
				sDiff = (int16_t)pRawImage[r*COL_MAX+c] - sLFOffsetRow[r];
				if(sDiff < 0)
					sDiff = 0;
				pRawImage[r*COL_MAX+c] = (uint16_t)sDiff;
			}
		}
	}
}
#endif /* (USED_LOCAL_IDLE_MODE_CONTROL || USED_IDLE_MODE_CONTROL) */

#if USED_MNT_S3_MODE_FUNCTION
void alogorithm_linefilter_S3(void)
{
	uint32_t r, c;
#if (USED_MODULE_DEF == MODULE_DEF_S_1)
#define IDLE_LINE_FILTER_UPPER_LIMIT		((45)<<ptModuleModeConf->ucIdleOvrShift) //((16)<<ptModuleModeConf->ucOvrShift)
#define IDLE_LINE_FILTER_LOWER_LIMIT		(-((45)<<ptModuleModeConf->ucIdleOvrShift)) //(-((16)<<ptModuleModeConf->ucOvrShift))
#elif (USED_MODULE_DEF == MODULE_DEF_B_1)
#define IDLE_LINE_FILTER_UPPER_LIMIT		((50)<<ptModuleModeConf->ucIdleOvrShift) //((16)<<ptModuleModeConf->ucOvrShift)
#define IDLE_LINE_FILTER_LOWER_LIMIT		(-((50)<<ptModuleModeConf->ucIdleOvrShift)) //(-((16)<<ptModuleModeConf->ucOvrShift))
#endif /* (USED_MODULE_DEF == MODULE_DEF_S_1) */
	int16_t lDiff;
	int16_t lDiffSum = 0;
	uint32_t lDiffSumCnt = 0;
	int32_t lLowTHD, lUpperTHD;
	uint16_t * pIdleBaseImage;

	lUpperTHD = IDLE_LINE_FILTER_UPPER_LIMIT;
	lLowTHD = IDLE_LINE_FILTER_LOWER_LIMIT;
	pIdleBaseImage = HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_NI);

	for(r=0; r<NI_ROW_MAX; r++)
	{
		lDiffSumCnt = 0;
		lDiffSum = 0;

		for(c = 0; c < COL_MAX; c+=2)
		{
			lDiff = (int16_t)HAL_NI_READ_RAW_IMAGE(r, c) - (int16_t)(*(pIdleBaseImage));
			pIdleBaseImage += 2;
			if(lDiff < lUpperTHD && lDiff > lLowTHD)
			{
				lDiffSum += lDiff;
				lDiffSumCnt++;
			}
		}

		if(lDiffSumCnt > 3)
		{
			sLFOffsetRow[r] = lDiffSum / ((int16_t)lDiffSumCnt);

			for(c = 0; c < COL_MAX; c++)
			{
				lDiff = (((int16_t)HAL_NI_READ_RAW_IMAGE(r, c)) - sLFOffsetRow[r]);
				if(lDiff<0)lDiff=0;
				HAL_NI_WRITE_RAW_IMAGE(r, c, (uint16_t)lDiff);
			}
		}
	}
}
#endif /* USED_MNT_S3_MODE_FUNCTION */

int16_t sLFOffsetCol[COL_MAX];
void alogorithm_vertical_linefilter(eSENSING_MODE_t eSensingMode)
{
	uint32_t r, c;
	int16_t LINE_FILTER_UPPER_LIMIT			= ((15)<<ptModuleModeConf->ucOvrShift); //thisModeConf->SensingFilter.sLineFilterUpLimit<<ptModuleModeConf->ucOvrShift;
	int16_t LINE_FILTER_LOWER_LIMIT			= (-((15)<<ptModuleModeConf->ucOvrShift)); //thisModeConf->SensingFilter.sLineFilterLowLimit<<ptModuleModeConf->ucOvrShift;
	uint8_t LINE_FILTER_ROW_OFFSET			= 3;//(thisModeConf->SensingFilter.ucLineFilterColOffset);

	int16_t lDiff;
	int16_t lDiffSum = 0;
	uint32_t lDiffSumCnt = 0;
	int32_t lLowTHD, lUpperTHD;
	uint16_t * pBaseImage;

	lUpperTHD = (LINE_FILTER_UPPER_LIMIT>>1);
	lLowTHD = (LINE_FILTER_LOWER_LIMIT>>1);

#if USED_NOISE_HOPPING_FREQ
	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	{
		pBaseImage = g_pFingerBaseImage;
	}
	else
	{
		pBaseImage = g_pFingerHop1BaseImage;
	}
//	pBaseImage = HAL_GET_FREQ_BASELINE_PTR(ptAppInfo->eSelectFreq);
#else /* USED_NOISE_HOPPING_FREQ */
	pBaseImage = g_pFingerBaseImage;//HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
#endif /* USED_NOISE_HOPPING_FREQ */

	for(c=0; c<COL_MAX; c++)
	{
		lDiffSumCnt = 0;
		lDiffSum = 0;
		for(r = 0; r < ROW_MAX; r+=LINE_FILTER_ROW_OFFSET)
		{
			lDiff = (int16_t)(HAL_READ_RAW_IMAGE(r, c) - pBaseImage[(r*COL_MAX)+c]);
			if(lDiff < lUpperTHD && lDiff > lLowTHD)
			{
				lDiffSum += lDiff;
				lDiffSumCnt++;
			}
			else
			{
				if(lDiff > lUpperTHD)
				{
					lDiff += lUpperTHD;
					lDiffSumCnt++;
				}
				else if(lDiff < lLowTHD)
				{
					lDiff += lLowTHD;
					lDiffSumCnt++;
				}
			}
		}

		if(lDiffSumCnt > 3)
		{
			sLFOffsetCol[c] = lDiffSum / ((int16_t)lDiffSumCnt);
#if !FAST_LF_EN		
			for(r = 0; r < ROW_MAX; r++)
			{
				lDiff = (((int16_t)HAL_READ_RAW_IMAGE(r, c)) - sLFOffsetCol[c]);
				if(lDiff<0)
					lDiff=0;
				HAL_WRITE_RAW_IMAGE(r, c, (uint16_t)lDiff);
			}
#endif
		}
	}
}

void alogorithm_vertical_linefilter_simple(eSENSING_MODE_t eSensingMode)
{
	uint32_t r, c, pos;
	int16_t LINE_FILTER_UPPER_LIMIT			= thisModeConf->SensingFilter.sLineFilterUpLimit<<ptModuleModeConf->ucOvrShift;
	int16_t LINE_FILTER_LOWER_LIMIT			= thisModeConf->SensingFilter.sLineFilterLowLimit<<ptModuleModeConf->ucOvrShift;
//	uint8_t LINE_FILTER_COL_OFFSET			= (thisModeConf->SensingFilter.ucLineFilterColOffset);
	
	int16_t sLFOffsetCol[COL_MAX] = {0};
	int16_t lDiff;
	int16_t lDiffSum = 0;
	uint32_t lDiffSumCnt = 0;
	int32_t lLowTHD, lUpperTHD;
	uint16_t * pBaseImage;
//	uint16_t rawdata;
//	eActivePenType_t eLocalFingerOPType = hal_Info_GetControlLocalFingerOPType();

	lUpperTHD = LINE_FILTER_UPPER_LIMIT;
	lLowTHD = LINE_FILTER_LOWER_LIMIT;

#if USED_NOISE_HOPPING_FREQ
	if(ptAppInfo->eSelectFreq == FREQ_MAIN)
	{
		pBaseImage = g_pFingerBaseImage;
	}
	else
	{
		pBaseImage = g_pFingerHop1BaseImage;
	}
//	pBaseImage = HAL_GET_FREQ_BASELINE_PTR(ptAppInfo->eSelectFreq);
#else /* USED_NOISE_HOPPING_FREQ */
	pBaseImage = g_pFingerBaseImage;//HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
#endif /* USED_NOISE_HOPPING_FREQ */

	for(c=0; c<COL_MAX; c++)
	{
		lDiffSumCnt = 0;
		lDiffSum = 0;
		
		pos = c;
		for(r = 0; r < ROW_MAX; r+=2,pos += (COL_MAX<<1))
		{
			lDiff = (int16_t)(HAL_READ_RAW_IMAGE(r, c) - pBaseImage[pos]);
			if(lDiff < lUpperTHD && lDiff > lLowTHD)
			{
				lDiffSum += lDiff;
				lDiffSumCnt++;
			}
		}

		if(lDiffSumCnt > 3)
		{
			sLFOffsetCol[c] = lDiffSum / ((int16_t)lDiffSumCnt);
#if !FAST_LF_EN		
			for(r = 0; r < ROW_MAX; r++)
			{
				lDiff = (((int16_t)HAL_READ_RAW_IMAGE(r, c)) - sLFOffsetCol[c]);
				if(lDiff<0)lDiff=0;
				HAL_WRITE_RAW_IMAGE(r, c, (uint16_t)lDiff);
			}
#endif
		}
	}
}

#ifndef PenNoiseReduction_OPCODE
#ifdef PenNoiseReduction_SW
extern 	ePartialSensing_t g_RetVal;
void algorithm_PenNoiseReduction(int mode)
{
	if( thisInfo->bTouchExpect_local )
	{
		int rs, re, cs, ce;
		int r, c;
		int prev_sum = 0;
		int sum_col;
		int start_slop = thisInfo->tDelta_local.tValidRect.cs;
		int end_slop = -1;
		tCell_t cal_max_pos;
		int left_size, right_size;
		int MaxR,MaxC;
		
		#ifdef TILT_ON
		if(g_RetVal==PARTIAL_PEN_COORD2 && mode == LOCAL_MODE)
		{
			MaxR = thisInfo->tPenInfo.cRing_PreMaxR;
			MaxC = thisInfo->tPenInfo.cRing_PreMaxC;					
		}
		else
		#endif
		{
			MaxR = thisInfo->tPenInfo.cPreMaxR;
			MaxC = thisInfo->tPenInfo.cPreMaxC;
		}
		
		if(MaxR != -1)					
		{
			for(c = thisInfo->tDelta_local.tValidRect.cs; c <= thisInfo->tDelta_local.tValidRect.ce; c++)
			{
				sum_col = 0;
				for(r = thisInfo->tDelta_local.tValidRect.rs; r <= thisInfo->tDelta_local.tValidRect.re; r++)
					sum_col += HAL_READ_LOCAL_DELTA_IMAGE(r, c);
				
				if((sum_col < thisModeConf->Label.usLocalSeedBase || c == thisInfo->tDelta_local.tValidRect.ce) && start_slop != -1)
				{
					end_slop = c;
					
					if(start_slop <= MaxC && MaxC <= end_slop)
					{
						thisInfo->tDelta_local.tValidRect.cs = start_slop;
						thisInfo->tDelta_local.tValidRect.ce = end_slop;
						
						if(thisInfo->tPenInfo.ucCurrentColumnStart > MaxC || MaxC > thisInfo->tPenInfo.ucCurrentColumnEnd)
						{
							if(start_slop - 2 < 0)
								thisInfo->tPenInfo.ucCurrentColumnStart = 0;
							else
								thisInfo->tPenInfo.ucCurrentColumnStart = start_slop - 2;
							
							if(end_slop + 2 > COL_MAX)
								thisInfo->tPenInfo.ucCurrentColumnEnd = COL_MAX;
							else
								thisInfo->tPenInfo.ucCurrentColumnEnd = end_slop + 2;
						}									
						break;
					}
					else
						start_slop = -1;
				}
				else if(sum_col > thisModeConf->Label.usLocalSeedBase && start_slop == -1)
					start_slop = c;
			}
		}
		
		if(thisInfo->tDelta_local.tValidRect.cs <= thisInfo->tDelta_local.tMaxCellPos.c && thisInfo->tDelta_local.tMaxCellPos.c <= thisInfo->tDelta_local.tValidRect.ce)
		{
			cal_max_pos.r = thisInfo->tDelta_local.tMaxCellPos.r;
			cal_max_pos.c = thisInfo->tDelta_local.tMaxCellPos.c;
			
			left_size = cal_max_pos.c - thisInfo->tDelta_local.tValidRect.cs;
			right_size = thisInfo->tDelta_local.tValidRect.ce - cal_max_pos.c;
			
			if(right_size - left_size > 1)
			{
				thisInfo->tDelta_local.tValidRect.ce = cal_max_pos.c + left_size + 1;
				if(thisInfo->tDelta_local.tValidRect.ce + 2 > COL_MAX)
					thisInfo->tPenInfo.ucCurrentColumnEnd = COL_MAX;
				else
					thisInfo->tPenInfo.ucCurrentColumnEnd = thisInfo->tDelta_local.tValidRect.ce + 2;
			}
			else if(left_size - right_size > 1)
			{
				thisInfo->tDelta_local.tValidRect.cs = cal_max_pos.c - (right_size + 1);
				if(thisInfo->tDelta_local.tValidRect.cs - 2 < 0)
					thisInfo->tPenInfo.ucCurrentColumnStart = 0;
				else
					thisInfo->tPenInfo.ucCurrentColumnStart = thisInfo->tDelta_local.tValidRect.cs - 2;
			}
		}
		
		#ifdef PenFingerSameLineNoiseException
		if(mode == LOCAL_MODE || mode == LOCAL_HOVER_MODE)
		{
			#ifdef TILT_ON
			if(g_RetVal==PARTIAL_PEN_COORD2)
			{
				rs = 7; //re = 6;
			}
			else 
			#endif
			{	
//				#ifdef	COVER_GLASS_USE
//				#if (CUSTOMER == NEC || CUSTOMER == MS || CUSTOMER == LENOVO_PEN || CUSTOMER == NEC_PEN)
//				rs = 3; //re = 5;
//				#else
//				rs = 4;
//				#endif
//				#else
				rs = thisModeConf->Noise.ucPenFingerSameLineNoiseSize;
//				#endif
			}
			
			if((thisInfo->tDelta_local.tValidRect.ce - thisInfo->tDelta_local.tValidRect.cs > rs) || (thisInfo->tDelta_local.tValidRect.re - thisInfo->tDelta_local.tValidRect.rs > rs))
			{
				thisInfo->tDelta_local.tValidRect.rs = thisInfo->tDelta_local.tMaxCellPos.r;
				thisInfo->tDelta_local.tValidRect.re = thisInfo->tDelta_local.tMaxCellPos.r;
				thisInfo->tDelta_local.tValidRect.cs = thisInfo->tDelta_local.tMaxCellPos.c;
				thisInfo->tDelta_local.tValidRect.ce = thisInfo->tDelta_local.tMaxCellPos.c;
				
				if(thisInfo->tDelta_local.tValidRect.cs != 0)
					thisInfo->tPenInfo.ucCurrentColumnStart = thisInfo->tDelta_local.tValidRect.cs - 1;
				else
					thisInfo->tPenInfo.ucCurrentColumnStart = 0;
				
				if(thisInfo->tDelta_local.tValidRect.ce != COL_MAX - 1)
					thisInfo->tPenInfo.ucCurrentColumnEnd = thisInfo->tDelta_local.tValidRect.ce + 2;
				else
					thisInfo->tPenInfo.ucCurrentColumnEnd = COL_MAX;
			}
		}
		#endif
	}
}
#endif
#endif

#if USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK
#define DEF_ESD_RECOVERY_DETECTION_ROIC_CHECK_NUM			(SRIC_NUM<<1)
#define DEF_ESD_RECOVERY_SENSING_BUF_IDX_ROLLING			(0 != (FINGER_MUX_NUM % DEF_ROIC_SENSING_BUFFER_NUM))
#define DEF_ESD_RECOVERY_CHECK_CURRENT_FRAME_RAWDATA_STUCK	(0 != (FINGER_MUX_NUM % DEF_ROIC_SENSING_BUFFER_NUM))

#if DEF_ESD_RECOVERY_SENSING_BUF_IDX_ROLLING
int16_t gvsCurrentCheckRawData_AFE_1[FINGER_MUX_NUM][DEF_ESD_RECOVERY_DETECTION_ROIC_CHECK_NUM] = {{0,}};
int16_t gvsCurrentCheckRawData_AFE_2[FINGER_MUX_NUM][DEF_ESD_RECOVERY_DETECTION_ROIC_CHECK_NUM] = {{0,}};
#endif /* DEF_ESD_RECOVERY_SENSING_BUF_IDX_ROLLING */

#if DEF_ESD_RECOVERY_CHECK_CURRENT_FRAME_RAWDATA_STUCK
#define RAWDATA_COMPARE_OFFSET_		(DEF_ROIC_SENSING_BUFFER_NUM)
#define RAWDATA_COMPARE_NUM_		(FINGER_MUX_NUM / DEF_ROIC_SENSING_BUFFER_NUM)
bool_t bRawdataStuckDebug = NO;
#endif /* DEF_ESD_RECOVERY_CHECK_CURRENT_FRAME_RAWDATA_STUCK */

bool_t gbSkipTouch = NO;
uint16_t gusSkipTouchCnt = 0;
int16_t gvsPastCheckRawData_AFE_1[FINGER_MUX_NUM][DEF_ESD_RECOVERY_DETECTION_ROIC_CHECK_NUM] = {{0,}};
int16_t gvsPastCheckRawData_AFE_2[FINGER_MUX_NUM][DEF_ESD_RECOVERY_DETECTION_ROIC_CHECK_NUM] = {{0,}};
uint32_t ulDetecForRecovery_Cnt = 0;
uint32_t ulMuxSensingOrder[16] = {
		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_00,
		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_01,
		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_02,

		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_03,
		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_04,
		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_05,

		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_06,
		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_00_fig_mux_07,
		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_08,

		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_09,
		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_10,
		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_11,

		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_12,
		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_13,
		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_14,

		PARAMSET_ROIC_CFGR_FIG_MUX_CFG_01_fig_mux_15,
};

static bool_t algorithm_CheckRawDataStuck(void)
{
	uint32_t ulMuxIdx, ulRoicIdx;
	uint32_t ulMatchingCnt;
	uint16_t usTempRawData;
	uint16_t usTempRawData_2;

	for(ulRoicIdx = 0; ulRoicIdx < DEF_ESD_RECOVERY_DETECTION_ROIC_CHECK_NUM; ulRoicIdx++)
	{
		ulMatchingCnt = 0;
		for(ulMuxIdx = 0; ulMuxIdx < FINGER_MUX_NUM; ulMuxIdx++)
		{
			usTempRawData = HAL_READ_RAW_IMAGE((ulMuxSensingOrder[ulMuxIdx] * ROIC_ALIGNED_ROW_LEN) + DEF_USED_AFE_1_CHECK_ROW_INDEX,
					(ulRoicIdx * R0_COL_LEN) + DEF_USED_AFE_1_CHECK_COL_INDEX);
			usTempRawData_2 = HAL_READ_RAW_IMAGE((ulMuxSensingOrder[ulMuxIdx] * ROIC_ALIGNED_ROW_LEN) + DEF_USED_AFE_2_CHECK_ROW_INDEX,
					(ulRoicIdx * R0_COL_LEN) + DEF_USED_AFE_2_CHECK_COL_INDEX);

#if DEF_ESD_RECOVERY_SENSING_BUF_IDX_ROLLING
			if(ulMuxIdx > DEF_ROIC_SENSING_BUFFER_NUM - 1)
			{
				/*
				 * Recovery Condition
				 * Check 1 : Rawdata of the same AFE are all the same.
				 * Check 2 : The current Frame is same as the previous Frame.
				 */
				if(gvsCurrentCheckRawData_AFE_1[ulMuxIdx-DEF_ROIC_SENSING_BUFFER_NUM][ulRoicIdx] == usTempRawData &&
					gvsPastCheckRawData_AFE_1[ulMuxIdx-DEF_ROIC_SENSING_BUFFER_NUM][ulRoicIdx] == usTempRawData &&
					gvsCurrentCheckRawData_AFE_2[ulMuxIdx-DEF_ROIC_SENSING_BUFFER_NUM][ulRoicIdx] == usTempRawData_2 &&
					gvsPastCheckRawData_AFE_2[ulMuxIdx-DEF_ROIC_SENSING_BUFFER_NUM][ulRoicIdx] == usTempRawData_2)
				{
					ulMatchingCnt++;
				}
			}
			gvsCurrentCheckRawData_AFE_1[ulMuxIdx][ulRoicIdx] = usTempRawData;
			gvsCurrentCheckRawData_AFE_2[ulMuxIdx][ulRoicIdx] = usTempRawData_2;
#else /* DEF_ESD_RECOVERY_SENSING_BUF_IDX_ROLLING */
			if(ulMuxIdx > DEF_ROIC_SENSING_BUFFER_NUM - 1)
			{
				/*
				 * Recovery Condition
				 * Check 1 : Rawdata of the same AFE are all the same.
				 * Check 2 : The current Frame is same as the previous Frame.
				 */
				if(gvsPastCheckRawData_AFE_1[ulMuxIdx-DEF_ROIC_SENSING_BUFFER_NUM][ulRoicIdx] == usTempRawData &&
					gvsPastCheckRawData_AFE_1[ulMuxIdx][ulRoicIdx] == usTempRawData &&
					gvsPastCheckRawData_AFE_2[ulMuxIdx-DEF_ROIC_SENSING_BUFFER_NUM][ulRoicIdx] == usTempRawData_2 &&
					gvsPastCheckRawData_AFE_2[ulMuxIdx][ulRoicIdx] == usTempRawData_2)
				{
					ulMatchingCnt++;
				}
			}
			gvsPastCheckRawData_AFE_1[ulMuxIdx][ulRoicIdx] = usTempRawData;
			gvsPastCheckRawData_AFE_2[ulMuxIdx][ulRoicIdx] = usTempRawData_2;
#endif /* DEF_ESD_RECOVERY_SENSING_BUF_IDX_ROLLING */
		}

#if DEF_ESD_RECOVERY_CHECK_CURRENT_FRAME_RAWDATA_STUCK
		{
			uint8_t i, mux_idx;
			uint8_t ucAFE_1_StuckCnt, ucAFE_2_StuckCnt;
			uint16_t vusAFE_1_Rawdata[RAWDATA_COMPARE_NUM_], vusAFE_2_Rawdata[RAWDATA_COMPARE_NUM_];

			ucAFE_1_StuckCnt = ucAFE_2_StuckCnt = 0;

			for(ulMuxIdx = 0; ulMuxIdx < RAWDATA_COMPARE_NUM_; ulMuxIdx++)
			{
				for (i=0; i<RAWDATA_COMPARE_NUM_; i++)
				{
					mux_idx = ulMuxIdx + (i * RAWDATA_COMPARE_OFFSET_);
					vusAFE_1_Rawdata[i] = gvsCurrentCheckRawData_AFE_1[mux_idx][ulRoicIdx];
					vusAFE_2_Rawdata[i] = gvsCurrentCheckRawData_AFE_2[mux_idx][ulRoicIdx];
				}

				if (vusAFE_1_Rawdata[0] == vusAFE_1_Rawdata[1] && vusAFE_1_Rawdata[1] == vusAFE_1_Rawdata[2])
					ucAFE_1_StuckCnt++;

				if (vusAFE_2_Rawdata[0] == vusAFE_2_Rawdata[1] && vusAFE_2_Rawdata[1] == vusAFE_2_Rawdata[2])
					ucAFE_2_StuckCnt++;
			}

			if ((ucAFE_1_StuckCnt >= RAWDATA_COMPARE_NUM_ ) && (ucAFE_2_StuckCnt >= RAWDATA_COMPARE_NUM_ ))
				gbSkipTouch = YES;

		}

#endif /* DEF_ESD_RECOVERY_CHECK_CURRENT_FRAME_RAWDATA_STUCK */
		if(ulMatchingCnt == FINGER_MUX_NUM - DEF_ROIC_SENSING_BUFFER_NUM)
		{
			return YES;
		}
	}

#if DEF_ESD_RECOVERY_SENSING_BUF_IDX_ROLLING
	memcpy((void*)&(gvsPastCheckRawData_AFE_1[0][0]), (void*)&(gvsCurrentCheckRawData_AFE_1[0][0]), sizeof(uint16_t)*FINGER_MUX_NUM*DEF_ESD_RECOVERY_DETECTION_ROIC_CHECK_NUM);
	memcpy((void*)&(gvsPastCheckRawData_AFE_2[0][0]), (void*)&(gvsCurrentCheckRawData_AFE_2[0][0]), sizeof(uint16_t)*FINGER_MUX_NUM*DEF_ESD_RECOVERY_DETECTION_ROIC_CHECK_NUM);
#endif /* DEF_ESD_RECOVERY_SENSING_BUF_IDX_ROLLING */

	return NO;
}
#endif /* USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK */

#if USED_ESD_RECOVERY_GHOST_TOUCH_DELTA_PATTERN
#define ROW_PER_MUX			(5)
#define MIN_DELTA_RATIO		(8)						//	80%
#define FIRST_MUX_NUM		(0)
#define LAST_MUX_NUM		(FINGER_MUX_NUM - 1)
#define LAST_MUX_ROW		(3)
#define MIN_DELTA			(10)

bool_t gbMuxDeltaDebug = NO;
uint8_t gucDebugCol = 73;
uint8_t gucDebugRow = 26;

bool_t algorithm_Check_Mux_Delta(uint8_t _mux_num, uint8_t _col, uint16_t _delta_thd, bool_t _bUpperCnt)
{
	bool_t bResult = NO;
	uint8_t i, size, ucDeltaCnt;
	int16_t data;

	ucDeltaCnt = 0;
	size = (_mux_num == LAST_MUX_NUM ? LAST_MUX_ROW : ROW_PER_MUX);

	for (i=0; i<size; i++)
	{
		data = HAL_READ_DELTA_IMAGE((_mux_num * ROW_PER_MUX) + i, _col);

		if (_bUpperCnt)
		{
			if (data >= _delta_thd)
				ucDeltaCnt++;
		}
		else
		{
			if (data < _delta_thd)
				ucDeltaCnt++;
		}
	}

	if (ucDeltaCnt >= size)
		bResult = YES;

	return bResult;
}
#endif /* USED_ESD_RECOVERY_GHOST_TOUCH_DELTA_PATTERN */

bool_t algorithm_process(uint8_t mode)
{
	bool_t bIsRecalState = NO;
	eSENSING_MODE_t eSensingMode;
	eSensingMode = HAL_GetSensingMode();
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES) 
	uint8_t ucInterpolation_Ver = 0;
#endif
	
#if USED_NOISE_HOPPING_FREQ
	{
#if USED_PEN_MODE_OPERATION
#define RAWDATA_STABLE_CNT		(1)
#else
#define RAWDATA_STABLE_CNT		(2)
#endif /* USED_PEN_MODE_OPERATION */

		if (ptAppInfo->eHoppingStatus == FREQ_HOPPING_CHANGED)
		{
			ptAppInfo->ucHoppFrameCnt++;

			if (ptAppInfo->ucHoppFrameCnt > RAWDATA_STABLE_CNT)
			{
				ptAppInfo->eHoppingStatus = FREQ_HOPPING_NONE;
			}
			else
			{
				return YES;
			}
		}
	}
#endif
	
#if (INTERPOLATION_VER1_En == YES || INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES) 
	if( (thisModeConf->Coord.ucFullFingerInterpolation_On > 0 && mode == FULL_MODE) || (thisModeConf->Coord.ucLocalFingerInterpolation_On > 0 && mode == LOCAL_FINGER_MODE) )
	{
		if(mode == FULL_MODE)ucInterpolation_Ver = thisModeConf->Coord.ucFullFingerInterpolation_On;
		else ucInterpolation_Ver = thisModeConf->Coord.ucLocalFingerInterpolation_On;
	}
	
#if !USED_DO_NOT_FINGER_TOUCH_REPORT
	if(ucInterpolation_Ver > 0)
	{

#if (INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
		if(ucInterpolation_Ver == 2 || ucInterpolation_Ver == 3)
		{
	#if (PEN_FINGER_1TOUCH_REPORT == NO)
			algorithm_PendTouchEvent();
	#endif
			algorithm_coord_UpdatePosHistoryInfo();
		}
#endif
		
		thisInfo->tCoord.bInterpolation_On = YES;
		algorithm_coord_interpolation(ucInterpolation_Ver);
		
#if (INTERPOLATION_VER1_En == YES)
		if(ucInterpolation_Ver == 1)
		{
	#if (PEN_FINGER_1TOUCH_REPORT == NO)
			algorithm_PendTouchEvent();
	#endif
			algorithm_coord_UpdatePosHistoryInfo();
		}
#endif
	}
	else
#endif /* !USED_DO_NOT_FINGER_TOUCH_REPORT */
	{
		thisInfo->tCoord.bInterpolation_On = NO;
	}
#endif
	
	algorithm_coord_initialise_pos_buffer();

#if USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK
	thisInfo->bIsESDRecovery = algorithm_CheckRawDataStuck();
	if(thisInfo->bIsESDRecovery)
	{
	#if USED_ESD_DEBUG
		gbRawdataStuckReset = thisInfo->bIsESDRecovery;
	#endif
		return YES; //
//		while(1); // watch-dog Reset!!
	}
#endif /* USED_ESD_RECOERY_DETECTION_RAWDATA_STUCK */

#if DEF_ESD_DEBUG_RAWDATA_BEFORE_LINEFILTER
	protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*Raw Data*/);
	#if USED_ESD_RECOVERY_SENSING_WITHOUT_MODULATION
		protocol_LogMatrix(LT_PENPOS_RAWDATA, COL_MAX, HAL_GET_ESD_RAW_IMAGE_PTR(), COL_MAX, FINGER_ESD_SCAN_ROW_MAX_NUM, 84/*Raw Data*/);
	#endif
#endif

	memset(sLFOffsetRow, 0, sizeof(sLFOffsetRow));
	memset(sLFOffsetCol, 0, sizeof(sLFOffsetCol));

	if(!IS_S3_MODE(eSensingMode))
	{
	#if FINGER_LF_VER1_EN
		if(thisModeConf->SensingFilter.cLineFilter == 1)
		{
			alogorithm_linefilter(eSensingMode);
		}
	#endif
	#if FINGER_LF_VER2_EN
		if(thisModeConf->SensingFilter.cLineFilter == 2)
		{
			alogorithm_linefilter_2();
		}
	#endif
	#if	USED_DSPA_FUNC_FOR_FINGER && USED_DSPA_FUNC_FOR_FINGER_LF
		if(thisModeConf->SensingFilter.cLineFilter == 3)
		{
			uint16_t * pBaseImage;
		#if USED_NOISE_HOPPING_FREQ
			if(ptAppInfo->eSelectFreq == FREQ_MAIN)
			{
				pBaseImage = g_pFingerBaseImage;
			}
			else
			{
				pBaseImage = g_pFingerHop1BaseImage;
			}
//			pBaseImage = HAL_GET_FREQ_BASELINE_PTR(ptAppInfo->eSelectFreq);
		#else /* USED_NOISE_HOPPING_FREQ */
			pBaseImage = g_pFingerBaseImage;//HAL_GetBaseImagePointer(HAL_GetSensingMode(), BASELINE_TYPE_FULL);
		#endif /* USED_NOISE_HOPPING_FREQ */
			alogorithm_linefilter_dspA((uint32_t)&RAWIMAGE[0][0],(uint32_t)(&pBaseImage[0]),(uint32_t)&DSPATMPDELTA_Finger[0][0],(uint32_t)&LINEFILTERBUFST2_Finger[0],(uint32_t)&LINEFILTERBUFST3_Finger[0],ROW_MAX,
			(uint32_t)(thisModeConf->SensingFilter.sLineFilterUpLimit<<ptModuleModeConf->ucOvrShift),(uint32_t)(thisModeConf->SensingFilter.sLineFilterLowLimit<<ptModuleModeConf->ucOvrShift),0);
		}
	#endif
	#if FINGER_LF_VER4_EN
		if(thisModeConf->SensingFilter.cLineFilter == 4)
		{
			alogorithm_linefilter_simple(eSensingMode);
			alogorithm_vertical_linefilter_simple(eSensingMode);
		}
	#endif /* (CUSTOMER != MODEL_DEF_FHD_92503B) */
	}

#if (DEF_ESD_DEBUG_RAWDATA_BEFORE_LINEFILTER == NO)
	protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_GET_RAW_IMAGE_PTR(), COL_MAX, ROW_MAX, 84/*Raw Data*/);
#endif

	algorithm_baseline_calculate_delta(mode);
	
	#if USED_ESD_RECOVERY_RESET_TOUCH_AT_FIRST_FRAME
	if(thisInfo->bIsESDGhostRecoveryATFirstFrame_Check)
	{
		if(thisInfo->ulESDGhostRecoveryATFirstFrame_Check_Count == 0)
		{
			thisInfo->ulESDGhostRecoveryATFirstFrame_TouchExpect_Count = 0;
		}

		thisInfo->ulESDGhostRecoveryATFirstFrame_Check_Count++;
		if(thisInfo->ulESDGhostRecoveryATFirstFrame_Check_Count < DEF_ESD_RECOVERY_RESET_TOUCH_AT_FIRST_FRAME_CNT_THD)
		{
			if(thisInfo->bTouchExpect)
			{
				thisInfo->ulESDGhostRecoveryATFirstFrame_TouchExpect_Count++;
				// Touch Skip!!
				return YES;
			}
		}
		else
		{
			thisInfo->bIsESDGhostRecoveryATFirstFrame_Check = NO;
			if(thisInfo->ulESDGhostRecoveryATFirstFrame_TouchExpect_Count > 0)
			{
				thisInfo->bIsESDRecovery = YES;
				// Reset For ESD!!
				return YES;
			}
		}
	}
	#endif /* USED_ESD_RECOVERY_RESET_TOUCH_AT_FIRST_FRAME */

	#if USED_ESD_RECOVERY_CHECK_ABNORMAL_PEN_DELTA
	if (thisInfo->bIsESD_Abnormal_Delta_Reset)
	{
		thisInfo->bIsESDRecovery = YES;
		// Reset For ESD!!
		return YES;
	}
	#endif

	protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);
	#if USED_ESD_RECOVERY_SENSING_WITHOUT_MODULATION
		protocol_LogMatrix(LT_PENPOS_INTENSITY, COL_MAX, HAL_GET_ESD_DELTA_IMAGE_PTR(), COL_MAX, FINGER_ESD_SCAN_ROW_MAX_NUM, 81/*MAX Intensity*/);
	#endif

	#if USED_ESD_RECOVERY_SENSING_WITHOUT_MODULATION
	{
		if(thisInfo->bIsESD_ReportSkip_ByESDScan == YES)
		{
			if(thisInfo->ulESD_ReportSkip_Count_ByESDScan < DEF_ESD_SCAN_REPORT_SKIP_CNT_THD)
			{
				thisInfo->ulESD_ReportSkip_Count_ByESDScan++;
				// Touch Skip!!
				return YES;
			}
			else
			{
				thisInfo->bIsESD_ReportSkip_ByESDScan = NO;
				thisInfo->ulESD_ReportSkip_Count_ByESDScan = 0;
			}
		}
	}
	#endif
//	return YES;
		
	if((mode == FULL_MODE && !thisModeConf->BaseLine.bFullModeReBaseCheckOff) || (mode == LOCAL_FINGER_MODE && !thisModeConf->BaseLine.bLocalModeReBaseCheckOff))
	{
		algorithm_check_recal_cond();
		bIsRecalState = algorithm_is_recalibrate();
	#if USED_ESD_DEBUG
		gbRecalReset = bIsRecalState;
	#endif
	}
	
	if(IS_S3_MODE(eSensingMode) && IS_IDLE_MODE(eSensingMode))
	{
		algorithm_baseline_tracking_continuous(mode);
	}
	else
	{
		if(bIsRecalState == NO)
		{
#if (FingerAreaPenDeltaDelete==1 || FingerAreaPenDeltaNoAcc==1 || FingerAreaLineFilter == 1)
			if(mode == LOCAL_FINGER_MODE)
			{
				if(thisModeConf->BaseLine.cFingerAreaPenDeltaDelete != 0 || thisModeConf->BaseLine.cFingerAreaPenDeltaNoAcc != 0 || thisModeConf->SensingFilter.sFingerAreaLineFilterLimit != 0)
				{
					thisInfo->tPenInfo.LocalFingerArea.rs = ROW_MAX;
					thisInfo->tPenInfo.LocalFingerArea.re = 0;
					thisInfo->tPenInfo.LocalFingerArea.cs = COL_MAX;
					thisInfo->tPenInfo.LocalFingerArea.ce = 0;	
				}
			}
#endif			
			// process label image from delta image
			algorithm_label_process(mode);
			algorithm_coord_process(FULL_MODE);
#if (INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES)
			if(ucInterpolation_Ver >= 2)
			{		
				algorithm_coord_interpolation_v02(ucInterpolation_Ver);
			}
#endif
		}

#if USED_NOISE_HOPPING_FREQ
//		if(mode == FULL_MODE)
		{
			algorithm_noise_process(eSensingMode);
		}
#endif /* USED_NOISE_HOPPING_FREQ */

#if PALM_VER1_EN
		if(thisModeConf->Palm.ucPalmDetectionOn == 1 || (thisModeConf->Palm.ucPalmDetectionOn == 3 && thisInfo->bNewVersionPalm == 0))
			public_func_PalmTouch_handler();
		
		if(thisInfo->bIsPalm || thisInfo->tCoord.tPos.sFinger_ > 5) thisInfo->bNewVersionPalm = 1;
		if(!thisInfo->bTouchExpect) thisInfo->bNewVersionPalm = 0;
#endif
		if(thisInfo->bIsPalm)
		{
			if(thisInfo->tLabel.ucPalmCnt < 100)
				thisInfo->tLabel.ucPalmCnt++;
		}
		else
			thisInfo->tLabel.ucPalmCnt = 0;

#if USED_ESD_RECOVERY_GHOST_TOUCH_DELTA_PATTERN
		{
			bool_t bTopMuxDelta, bBottomMuxDelta;
			uint8_t max_c, mux_num;
			uint16_t min_delta;

//			usLabelThd  = thisModeConf->Label.usSeedBase;
//			usLabelThd += ((temp_delta->iMaxStrength - thisModeConf->Label.usSeedBase) * thisModeConf->Label.ucSeedSlope)>>6;

			if (thisInfo->tDelta.iMaxStrength > thisModeConf->Label.usSeedBase)
			{
				max_c = thisInfo->tDelta.tMaxCellPos.c;
				mux_num = thisInfo->tDelta.tMaxCellPos.r / ROW_PER_MUX;
				min_delta = thisInfo->tDelta.iMaxStrength * MIN_DELTA_RATIO / 10;

				//	1. Check current mux delta
				if (algorithm_Check_Mux_Delta(mux_num, max_c, min_delta, YES))
				{
					//	2. Check top/bottom mux delta

					bTopMuxDelta = bBottomMuxDelta = YES;

					if (mux_num != FIRST_MUX_NUM)
						bTopMuxDelta = algorithm_Check_Mux_Delta(mux_num - 1, max_c, MIN_DELTA, NO);

					if (mux_num != LAST_MUX_NUM)
						bBottomMuxDelta = algorithm_Check_Mux_Delta(mux_num + 1, max_c, MIN_DELTA, NO);


					if (bTopMuxDelta && bBottomMuxDelta)
						gbSkipTouch = YES;	//	ESD Ghost Touch
				}
			}

//			while(gbSkipTouch)	//	Debug
//			{
//				protocol_LogPaddedMatrix(LT_INTENSITY, COL_MAX, HAL_GET_DELTA_IMAGE_PTR(), COL_MAX, ROW_MAX, 81/*MAX Intensity*/);
//				medium_delay(300);
//#ifdef MODE_WDT
//				KICK_DOG();
//#endif
//			};
		}
#endif /* USED_ESD_RECOVERY_GHOST_TOUCH_DELTA_PATTERN */

#if USED_PEN_MODE_OPERATION
		if(mode == FULL_MODE)
		{
			thisInfo->sFullLcoalChangeMinTh = thisModeConf->BaseLine.sFullLcoalChangeMinTh;
			if((thisInfo->bIsPalm == YES && thisInfo->tCoord.tPos.sFinger_ >= 1) || thisInfo->tCoord.tPos.sFinger_ >= 6)
				thisInfo->sFullLcoalChangeMinTh += thisModeConf->BaseLine.cFullLcoalChangeMinThOffset;
			if(thisInfo->tDelta.iMinStrength < thisInfo->sFullLcoalChangeMinTh)
			{
				thisInfo->bLocal_sensing = YES;
				algorithm_baseline_calculate_mux_range(thisInfo->tDelta.tMinCellPos.r, thisInfo->tDelta.tMinCellPos.c);
			}
		}
#endif
	
#if !USED_DO_NOT_FINGER_TOUCH_REPORT
#if (INTERPOLATION_VER2_En == YES || INTERPOLATION_VER3_En == YES) 
		if(ucInterpolation_Ver < 2)
#endif
		{
	#if (FINGER_Latency_Test_ByFW == YES)
			algorithm_coord_latency_cal_test();
	#endif
	#if (PEN_FINGER_1TOUCH_REPORT == NO)
#if (DEF_ESD_RECOVERY_CHECK_CURRENT_FRAME_RAWDATA_STUCK || USED_ESD_RECOVERY_GHOST_TOUCH_DELTA_PATTERN)
			if (!gbSkipTouch)
				algorithm_PendTouchEvent();
			else
			{
				gbSkipTouch = NO;
				gusSkipTouchCnt++;
			}
#else /* (DEF_ESD_RECOVERY_CHECK_CURRENT_FRAME_RAWDATA_STUCK || USED_ESD_RECOVERY_GHOST_TOUCH_DELTA_PATTERN) */
			algorithm_PendTouchEvent();
#endif /* (DEF_ESD_RECOVERY_CHECK_CURRENT_FRAME_RAWDATA_STUCK || USED_ESD_RECOVERY_GHOST_TOUCH_DELTA_PATTERN) */
	#endif
			algorithm_coord_UpdatePosHistoryInfo();
			//Heon
			if(thisInfo->bIsOutIn == YES){
				algorithm_OutInCheck();
			}
			//Heon
		}
#endif /* !USED_DO_NOT_FINGER_TOUCH_REPORT */
		
		if(thisModeConf->BaseLine.bFingerBaseTracking == 1 && ((mode == FULL_MODE && thisModeConf->BaseLine.bFullFingerBaseTracking == 1) || (mode == LOCAL_FINGER_MODE)))
			algorithm_baseline_tracking_continuous(mode);
	}

	return (bIsRecalState == NO);
}

#if USED_MNT_S3_MODE_FUNCTION
#if USED_S3_WAKEUP_DEBUGING
extern uint32_t ulTestS3RawDataRead;
#endif
extern uint8_t g_RemoteWakeup;
bool_t algorithm_process_S3(void)
{
	bool_t bIsRecalState = NO;

	alogorithm_linefilter_S3();
	algorithm_baseline_calculate_delta_S3();

//	algorithm_baseline_tracking_continuous_local_S3();

	protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_NI_GET_RAW_IMAGE_PTR(), COL_MAX, NI_ROW_MAX, 84/*MAX Intensity*/);
	protocol_LogMatrix(LT_INTENSITY, COL_MAX, HAL_NI_GET_DELTA_IMAGE_PTR(), COL_MAX, NI_ROW_MAX, 84/*MAX Intensity*/);

	if(thisInfo->tS3DeltaInfo.bIsSendResumeSignal == YES && g_RemoteWakeup == 0)
	{
#if !USED_S3_WAKEUP_DEBUGING
		algorithm_PendTouchEvent();
		algorithm_coord_UpdatePosHistoryInfo();
		algorithm_baseline_tracking_continuous_S3();
#endif
	}

	if((thisInfo->bTouchExpect == YES) && (g_RemoteWakeup == 1))
	{
		thisInfo->tCoord.tPos.vusR[0] = 100;
		thisInfo->tCoord.tPos.vusS[0] = 100;
		thisInfo->tCoord.tPos.tXY[0].x = 5000;
		thisInfo->tCoord.tPos.tXY[0].y = 5000;

		if(thisInfo->tS3DeltaInfo.bIsSendResumeSignal == NO &&
			IS_GPIO_PIN(_GPIO_S3_POWER_IN) == GPIO_DATA_LOW)
		{
			thisInfo->tS3DeltaInfo.bIsSendResumeSignal = YES;
#if USED_S3_WAKEUP_DEBUGING
			ulTestS3RawDataRead = NO;
#else
			ResumeSigal();
#endif
		}
	}

	return (bIsRecalState == NO);
}
#endif /* USED_MNT_S3_MODE_FUNCTION */

#if USED_IDLE_MODE_CONTROL
bool_t algorithm_process_Idle(void)
{
	bool_t bIsRecalState = NO;

	memset(sLFOffsetRow, 0, sizeof(sLFOffsetRow));
	memset(sLFOffsetCol, 0, sizeof(sLFOffsetCol));
	alogorithm_linefilter_idle();
	algorithm_baseline_calculate_delta_idle();
	algorithm_baseline_tracking_continuous_idle();

	protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_NI_GET_RAW_IMAGE_PTR(), COL_MAX, NI_ROW_MAX, 84/*MAX Intensity*/);
//	#if USED_IDLE_FINGER_EVEN_ODD
//		protocol_LogMatrix(LT_INTENSITY, COL_MAX, HAL_NI_GET_DELTA_IMAGE_PTR(), COL_MAX, (LOCAL_FINGER_1MUX_ROW_NUM<<1), 84/*MAX Intensity*/);
//	#else
		protocol_LogMatrix(LT_INTENSITY, COL_MAX, HAL_NI_GET_DELTA_IMAGE_PTR(), COL_MAX, LOCAL_FINGER_1MUX_ROW_NUM, 84/*MAX Intensity*/);
//	#endif

	return (bIsRecalState == NO);
}
#endif /* USED_IDLE_MODE_CONTROL */

#if USED_LOCAL_IDLE_MODE_CONTROL
bool_t algorithm_process_LocalIdle(void)
{
	bool_t bIsRecalState = NO;
	alogorithm_linefilter_idle();
	algorithm_baseline_calculate_delta_local_idle();
	algorithm_baseline_tracking_continuous_local_idle();

	protocol_LogMatrix(LT_RAWDATA, COL_MAX, HAL_NI_GET_RAW_IMAGE_PTR(), COL_MAX, NI_ROW_MAX, 84/*MAX Intensity*/);
//	#if USED_IDLE_FINGER_EVEN_ODD
//		#if USED_LOCAL_IDLE_PEN_OTHER_CONTROL
//			protocol_LogMatrix(LT_INTENSITY, COL_MAX, HAL_NI_GET_DELTA_IMAGE_PTR(), COL_MAX, (LOCAL_FINGER_1MUX_ROW_NUM + PEN_COORD_ROW_MAX), 84/*MAX Intensity*/);
//		#else /* USED_LOCAL_IDLE_PEN_OTHER_CONTROL */
//			protocol_LogMatrix(LT_INTENSITY, COL_MAX, HAL_NI_GET_DELTA_IMAGE_PTR(), COL_MAX, (LOCAL_FINGER_1MUX_ROW_NUM), 84/*MAX Intensity*/);
//		#endif /* USED_LOCAL_IDLE_PEN_OTHER_CONTROL */
//	#else
		#if USED_LOCAL_IDLE_PEN_OTHER_CONTROL
			protocol_LogMatrix(LT_INTENSITY, COL_MAX, HAL_NI_GET_DELTA_IMAGE_PTR(), COL_MAX, (LOCAL_FINGER_1MUX_ROW_NUM + PEN_COORD_ROW_MAX), 84/*MAX Intensity*/);
		#else /* USED_LOCAL_IDLE_PEN_OTHER_CONTROL */
			protocol_LogMatrix(LT_INTENSITY, COL_MAX, HAL_NI_GET_DELTA_IMAGE_PTR(), COL_MAX, (LOCAL_FINGER_1MUX_ROW_NUM), 84/*MAX Intensity*/);
		#endif /* USED_LOCAL_IDLE_PEN_OTHER_CONTROL */
//	#endif

	return (bIsRecalState == NO);
}
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
