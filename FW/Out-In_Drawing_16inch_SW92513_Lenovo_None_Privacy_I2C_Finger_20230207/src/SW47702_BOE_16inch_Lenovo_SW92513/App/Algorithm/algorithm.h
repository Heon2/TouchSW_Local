/*
 * algorithm.h
 *
 *  Created on: 2015. 5. 6.
 *      Author: parkyj2
 */

#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#ifdef TILT_ON
//#define GetAngleLookUpHighResolution 1
#endif

#if (USED_PEN_MODE_OPERATION && LOCAL_REBASE_ALGO_EN)
extern void algorithm_check_recal_pen(void);
#endif
extern void GetOperTimeUS(uint64_t* StartTime, uint32_t* ScanTime);
extern bool_t LGD_error_frame_process(void);
extern void algorithm_init(void); // NOTE : spelling Modify!!
extern void algorithm_init_param(void);
#if USED_IDLE_MODE_CONTROL
extern bool_t algorithm_CheckFingerIdleModeControl(void);
#endif /* USED_IDLE_MODE_CONTROL */
#if USED_PEN_MODE_OPERATION
#if USED_LOCAL_IDLE_MODE_CONTROL
extern bool_t algorithm_CheckLocalPenIdleModeControl(void);
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
extern bool_t algorithm_CheckFingerPenModeControl(void);
extern void app_normal_Init_param(void);
#endif /* USED_PEN_MODE_OPERATION */
extern void algorithm_PendTouchEvent(void);
extern void algorithm_OutInCheck(void);

extern bool_t algorithm_process(uint8_t mode);
#if USED_MNT_S3_MODE_FUNCTION
bool_t algorithm_process_S3(void);
#endif /* USED_MNT_S3_MODE_FUNCTION */
#if USED_IDLE_MODE_CONTROL
extern bool_t algorithm_process_Idle(void);
#endif /* USED_IDLE_MODE_CONTROL */
#if USED_LOCAL_IDLE_MODE_CONTROL
extern bool_t algorithm_process_LocalIdle(void);
#endif /* USED_LOCAL_IDLE_MODE_CONTROL */
//extern void algorithm_local_process(int mode,ePartialSensing_t Ret);
extern int32_t algorithm_calc_sqrt(int32_t d);

#ifdef GetAngleLookUpHighResolution
extern int32_t algorithm_calc_angle_inter_2points_HighResolution(int diff_x, int diff_y);
#else
#ifndef TILT_OPCODE
extern int32_t algorithm_calc_angle_inter_2points(int diff_x, int diff_y);
#endif /* TILT_OPCODE */
#endif

#ifdef GetAngleLookUpHighResolution
static int32_t ArcTanLookUp[1001]      =
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

#endif /* __ALGORITHM_H__ */
