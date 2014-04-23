/*
mnemonics.h

diStorm3 - Powerful disassembler for X86/AMD64
http://ragestorm.net/distorm/
distorm at gmail dot com
Copyright (C) 2003-2012 Gil Dabah

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/


#ifndef MNEMONICS_H
#define MNEMONICS_H

#ifdef __cplusplus
 extern "C" {
#endif

#ifndef DISTORM_LIGHT

typedef struct WMnemonic {
	unsigned char length;
	unsigned char p[1]; /* p is a null terminated string, which contains 'length' characters. */
} _WMnemonic;

typedef struct WRegister {
	unsigned int length;
	unsigned char p[6]; /* p is a null terminated string. */
} _WRegister;

extern const unsigned char _MNEMONICS[];
extern const _WRegister _REGISTERS[];

#endif /* DISTORM_LIGHT */

#ifdef __cplusplus
} /* End Of Extern */
#endif

#define GET_REGISTER_NAME(r) (unsigned char*)_REGISTERS[(r)].p
#define GET_MNEMONIC_NAME(m) ((_WMnemonic*)&_MNEMONICS[(m)])->p

typedef enum {
	I_UNDEFINED = 0, I_3DNOW = 10034, I_AAA = 66, I_AAD = 389, I_AAM = 384, I_AAS = 76, I_ADC = 31,
	I_ADD = 11, I_ADDPD = 3110, I_ADDPS = 3103, I_ADDSD = 3124, I_ADDSS = 3117,
	I_ADDSUBPD = 6394, I_ADDSUBPS = 6404, I_AESDEC = 9209, I_AESDECLAST = 9226,
	I_AESENC = 9167, I_AESENCLAST = 9184, I_AESIMC = 9150, I_AESKEYGENASSIST = 9795,
	I_AND = 41, I_ANDNPD = 3021, I_ANDNPS = 3013, I_ANDPD = 2990, I_ANDPS = 2983,
	I_ARPL = 111, I_BLENDPD = 9372, I_BLENDPS = 9353, I_BLENDVPD = 7619, I_BLENDVPS = 7609,
	I_BOUND = 104, I_BSF = 4346, I_BSR = 4358, I_BSWAP = 960, I_BT = 872, I_BTC = 934,
	I_BTR = 912, I_BTS = 887, I_CALL = 456, I_CALL_FAR = 260, I_CBW = 228, I_CDQ = 250,
	I_CDQE = 239, I_CLC = 492, I_CLD = 512, I_CLFLUSH = 4329, I_CLGI = 1833, I_CLI = 502,
	I_CLTS = 541, I_CMC = 487, I_CMOVA = 694, I_CMOVAE = 663, I_CMOVB = 656, I_CMOVBE = 686,
	I_CMOVG = 754, I_CMOVGE = 738, I_CMOVL = 731, I_CMOVLE = 746, I_CMOVNO = 648,
	I_CMOVNP = 723, I_CMOVNS = 708, I_CMOVNZ = 678, I_CMOVO = 641, I_CMOVP = 716,
	I_CMOVS = 701, I_CMOVZ = 671, I_CMP = 71, I_CMPEQPD = 4449, I_CMPEQPS = 4370,
	I_CMPEQSD = 4607, I_CMPEQSS = 4528, I_CMPLEPD = 4467, I_CMPLEPS = 4388, I_CMPLESD = 4625,
	I_CMPLESS = 4546, I_CMPLTPD = 4458, I_CMPLTPS = 4379, I_CMPLTSD = 4616, I_CMPLTSS = 4537,
	I_CMPNEQPD = 4488, I_CMPNEQPS = 4409, I_CMPNEQSD = 4646, I_CMPNEQSS = 4567,
	I_CMPNLEPD = 4508, I_CMPNLEPS = 4429, I_CMPNLESD = 4666, I_CMPNLESS = 4587,
	I_CMPNLTPD = 4498, I_CMPNLTPS = 4419, I_CMPNLTSD = 4656, I_CMPNLTSS = 4577,
	I_CMPORDPD = 4518, I_CMPORDPS = 4439, I_CMPORDSD = 4676, I_CMPORDSS = 4597,
	I_CMPS = 301, I_CMPUNORDPD = 4476, I_CMPUNORDPS = 4397, I_CMPUNORDSD = 4634,
	I_CMPUNORDSS = 4555, I_CMPXCHG = 898, I_CMPXCHG16B = 6373, I_CMPXCHG8B = 6362,
	I_COMISD = 2779, I_COMISS = 2771, I_CPUID = 865, I_CQO = 255, I_CRC32 = 9258,
	I_CVTDQ2PD = 6787, I_CVTDQ2PS = 3307, I_CVTPD2DQ = 6797, I_CVTPD2PI = 2681,
	I_CVTPD2PS = 3233, I_CVTPH2PS = 4161, I_CVTPI2PD = 2495, I_CVTPI2PS = 2485,
	I_CVTPS2DQ = 3317, I_CVTPS2PD = 3223, I_CVTPS2PH = 4171, I_CVTPS2PI = 2671,
	I_CVTSD2SI = 2701, I_CVTSD2SS = 3253, I_CVTSI2SD = 2515, I_CVTSI2SS = 2505,
	I_CVTSS2SD = 3243, I_CVTSS2SI = 2691, I_CVTTPD2DQ = 6776, I_CVTTPD2PI = 2614,
	I_CVTTPS2DQ = 3327, I_CVTTPS2PI = 2603, I_CVTTSD2SI = 2636, I_CVTTSS2SI = 2625,
	I_CWD = 245, I_CWDE = 233, I_DAA = 46, I_DAS = 56, I_DEC = 86, I_DIV = 1630,
	I_DIVPD = 3499, I_DIVPS = 3492, I_DIVSD = 3513, I_DIVSS = 3506, I_DPPD = 9615,
	I_DPPS = 9602, I_EMMS = 4100, I_ENTER = 340, I_EXTRACTPS = 9480, I_EXTRQ = 4136,
	I_F2XM1 = 1176, I_FABS = 1107, I_FADD = 1007, I_FADDP = 1533, I_FBLD = 1585,
	I_FBSTP = 1591, I_FCHS = 1101, I_FCLEX = 7289, I_FCMOVB = 1360, I_FCMOVBE = 1376,
	I_FCMOVE = 1368, I_FCMOVNB = 1429, I_FCMOVNBE = 1447, I_FCMOVNE = 1438, I_FCMOVNU = 1457,
	I_FCMOVU = 1385, I_FCOM = 1019, I_FCOMI = 1496, I_FCOMIP = 1607, I_FCOMP = 1025,
	I_FCOMPP = 1547, I_FCOS = 1295, I_FDECSTP = 1222, I_FDIV = 1045, I_FDIVP = 1578,
	I_FDIVR = 1051, I_FDIVRP = 1570, I_FEDISI = 1472, I_FEMMS = 574, I_FENI = 1466,
	I_FFREE = 1511, I_FIADD = 1301, I_FICOM = 1315, I_FICOMP = 1322, I_FIDIV = 1345,
	I_FIDIVR = 1352, I_FILD = 1402, I_FIMUL = 1308, I_FINCSTP = 1231, I_FINIT = 7304,
	I_FIST = 1416, I_FISTP = 1422, I_FISTTP = 1408, I_FISUB = 1330, I_FISUBR = 1337,
	I_FLD = 1058, I_FLD1 = 1125, I_FLDCW = 1082, I_FLDENV = 1074, I_FLDL2E = 1139,
	I_FLDL2T = 1131, I_FLDLG2 = 1154, I_FLDLN2 = 1162, I_FLDPI = 1147, I_FLDZ = 1170,
	I_FMUL = 1013, I_FMULP = 1540, I_FNCLEX = 7281, I_FNINIT = 7296, I_FNOP = 1095,
	I_FNSAVE = 7311, I_FNSTCW = 7266, I_FNSTENV = 7249, I_FNSTSW = 7326, I_FPATAN = 1197,
	I_FPREM = 1240, I_FPREM1 = 1214, I_FPTAN = 1190, I_FRNDINT = 1272, I_FRSTOR = 1503,
	I_FSAVE = 7319, I_FSCALE = 1281, I_FSETPM = 1480, I_FSIN = 1289, I_FSINCOS = 1263,
	I_FSQRT = 1256, I_FST = 1063, I_FSTCW = 7274, I_FSTENV = 7258, I_FSTP = 1068,
	I_FSTSW = 7334, I_FSUB = 1032, I_FSUBP = 1563, I_FSUBR = 1038, I_FSUBRP = 1555,
	I_FTST = 1113, I_FUCOM = 1518, I_FUCOMI = 1488, I_FUCOMIP = 1598, I_FUCOMP = 1525,
	I_FUCOMPP = 1393, I_FXAM = 1119, I_FXCH = 1089, I_FXRSTOR = 9892, I_FXRSTOR64 = 9901,
	I_FXSAVE = 9864, I_FXSAVE64 = 9872, I_FXTRACT = 1205, I_FYL2X = 1183, I_FYL2XP1 = 1247,
	I_GETSEC = 633, I_HADDPD = 4181, I_HADDPS = 4189, I_HLT = 482, I_HSUBPD = 4215,
	I_HSUBPS = 4223, I_IDIV = 1635, I_IMUL = 117, I_IN = 447, I_INC = 81, I_INS = 123,
	I_INSERTPS = 9547, I_INSERTQ = 4143, I_INT = 367, I_INT_3 = 360, I_INT1 = 476,
	I_INTO = 372, I_INVD = 555, I_INVEPT = 8284, I_INVLPG = 1711, I_INVLPGA = 1847,
	I_INVPCID = 8301, I_INVVPID = 8292, I_IRET = 378, I_JA = 166, I_JAE = 147,
	I_JB = 143, I_JBE = 161, I_JCXZ = 427, I_JECXZ = 433, I_JG = 202, I_JGE = 192,
	I_JL = 188, I_JLE = 197, I_JMP = 462, I_JMP_FAR = 467, I_JNO = 138, I_JNP = 183,
	I_JNS = 174, I_JNZ = 156, I_JO = 134, I_JP = 179, I_JRCXZ = 440, I_JS = 170,
	I_JZ = 152, I_LAHF = 289, I_LAR = 522, I_LDDQU = 6994, I_LDMXCSR = 9922, I_LDS = 335,
	I_LEA = 223, I_LEAVE = 347, I_LES = 330, I_LFENCE = 4265, I_LFS = 917, I_LGDT = 1687,
	I_LGS = 922, I_LIDT = 1693, I_LLDT = 1652, I_LMSW = 1705, I_LODS = 313, I_LOOP = 421,
	I_LOOPNZ = 406, I_LOOPZ = 414, I_LSL = 527, I_LSS = 907, I_LTR = 1658, I_LZCNT = 4363,
	I_MASKMOVDQU = 7119, I_MASKMOVQ = 7109, I_MAXPD = 3559, I_MAXPS = 3552, I_MAXSD = 3573,
	I_MAXSS = 3566, I_MFENCE = 4291, I_MINPD = 3439, I_MINPS = 3432, I_MINSD = 3453,
	I_MINSS = 3446, I_MONITOR = 1755, I_MOV = 218, I_MOVAPD = 2459, I_MOVAPS = 2451,
	I_MOVBE = 9251, I_MOVD = 3920, I_MOVDDUP = 2186, I_MOVDQ2Q = 6522, I_MOVDQA = 3946,
	I_MOVDQU = 3954, I_MOVHLPS = 2151, I_MOVHPD = 2345, I_MOVHPS = 2337, I_MOVLHPS = 2328,
	I_MOVLPD = 2168, I_MOVLPS = 2160, I_MOVMSKPD = 2815, I_MOVMSKPS = 2805, I_MOVNTDQ = 6849,
	I_MOVNTDQA = 7895, I_MOVNTI = 952, I_MOVNTPD = 2556, I_MOVNTPS = 2547, I_MOVNTQ = 6841,
	I_MOVNTSD = 2574, I_MOVNTSS = 2565, I_MOVQ = 3926, I_MOVQ2DQ = 6513, I_MOVS = 295,
	I_MOVSD = 2110, I_MOVSHDUP = 2353, I_MOVSLDUP = 2176, I_MOVSS = 2103, I_MOVSX = 939,
	I_MOVSXD = 10013, I_MOVUPD = 2095, I_MOVUPS = 2087, I_MOVZX = 927, I_MPSADBW = 9628,
	I_MUL = 1625, I_MULPD = 3170, I_MULPS = 3163, I_MULSD = 3184, I_MULSS = 3177,
	I_MWAIT = 1764, I_NEG = 1620, I_NOP = 581, I_NOT = 1615, I_OR = 27, I_ORPD = 3053,
	I_ORPS = 3047, I_OUT = 451, I_OUTS = 128, I_PABSB = 7688, I_PABSD = 7718, I_PABSW = 7703,
	I_PACKSSDW = 3849, I_PACKSSWB = 3681, I_PACKUSDW = 7916, I_PACKUSWB = 3759,
	I_PADDB = 7204, I_PADDD = 7234, I_PADDQ = 6481, I_PADDSB = 6930, I_PADDSW = 6947,
	I_PADDUSB = 6620, I_PADDUSW = 6639, I_PADDW = 7219, I_PALIGNR = 9410, I_PAND = 6607,
	I_PANDN = 6665, I_PAUSE = 10021, I_PAVGB = 6680, I_PAVGUSB = 2078, I_PAVGW = 6725,
	I_PBLENDVB = 7599, I_PBLENDW = 9391, I_PCLMULQDQ = 9647, I_PCMPEQB = 4043,
	I_PCMPEQD = 4081, I_PCMPEQQ = 7876, I_PCMPEQW = 4062, I_PCMPESTRI = 9726,
	I_PCMPESTRM = 9703, I_PCMPGTB = 3702, I_PCMPGTD = 3740, I_PCMPGTQ = 8087,
	I_PCMPGTW = 3721, I_PCMPISTRI = 9772, I_PCMPISTRM = 9749, I_PEXTRB = 9429,
	I_PEXTRD = 9446, I_PEXTRQ = 9454, I_PEXTRW = 6311, I_PF2ID = 1914, I_PF2IW = 1907,
	I_PFACC = 2028, I_PFADD = 1977, I_PFCMPEQ = 2035, I_PFCMPGE = 1938, I_PFCMPGT = 1984,
	I_PFMAX = 1993, I_PFMIN = 1947, I_PFMUL = 2044, I_PFNACC = 1921, I_PFPNACC = 1929,
	I_PFRCP = 1954, I_PFRCPIT1 = 2000, I_PFRCPIT2 = 2051, I_PFRSQIT1 = 2010, I_PFRSQRT = 1961,
	I_PFSUB = 1970, I_PFSUBR = 2020, I_PHADDD = 7375, I_PHADDSW = 7392, I_PHADDW = 7358,
	I_PHMINPOSUW = 8259, I_PHSUBD = 7451, I_PHSUBSW = 7468, I_PHSUBW = 7434, I_PI2FD = 1900,
	I_PI2FW = 1893, I_PINSRB = 9530, I_PINSRD = 9568, I_PINSRQ = 9576, I_PINSRW = 6294,
	I_PMADDUBSW = 7411, I_PMADDWD = 7073, I_PMAXSB = 8174, I_PMAXSD = 8191, I_PMAXSW = 6964,
	I_PMAXUB = 6648, I_PMAXUD = 8225, I_PMAXUW = 8208, I_PMINSB = 8106, I_PMINSD = 8123,
	I_PMINSW = 6902, I_PMINUB = 6590, I_PMINUD = 8157, I_PMINUW = 8140, I_PMOVMSKB = 6531,
	I_PMOVSXBD = 7754, I_PMOVSXBQ = 7775, I_PMOVSXBW = 7733, I_PMOVSXDQ = 7838,
	I_PMOVSXWD = 7796, I_PMOVSXWQ = 7817, I_PMOVZXBD = 7982, I_PMOVZXBQ = 8003,
	I_PMOVZXBW = 7961, I_PMOVZXDQ = 8066, I_PMOVZXWD = 8024, I_PMOVZXWQ = 8045,
	I_PMULDQ = 7859, I_PMULHRSW = 7538, I_PMULHRW = 2061, I_PMULHUW = 6740, I_PMULHW = 6759,
	I_PMULLD = 8242, I_PMULLW = 6496, I_PMULUDQ = 7054, I_POP = 22, I_POPA = 98,
	I_POPCNT = 4338, I_POPF = 277, I_POR = 6919, I_PREFETCH = 1872, I_PREFETCHNTA = 2402,
	I_PREFETCHT0 = 2415, I_PREFETCHT1 = 2427, I_PREFETCHT2 = 2439, I_PREFETCHW = 1882,
	I_PSADBW = 7092, I_PSHUFB = 7341, I_PSHUFD = 3988, I_PSHUFHW = 3996, I_PSHUFLW = 4005,
	I_PSHUFW = 3980, I_PSIGNB = 7487, I_PSIGND = 7521, I_PSIGNW = 7504, I_PSLLD = 7024,
	I_PSLLDQ = 9847, I_PSLLQ = 7039, I_PSLLW = 7009, I_PSRAD = 6710, I_PSRAW = 6695,
	I_PSRLD = 6451, I_PSRLDQ = 9830, I_PSRLQ = 6466, I_PSRLW = 6436, I_PSUBB = 7144,
	I_PSUBD = 7174, I_PSUBQ = 7189, I_PSUBSB = 6868, I_PSUBSW = 6885, I_PSUBUSB = 6552,
	I_PSUBUSW = 6571, I_PSUBW = 7159, I_PSWAPD = 2070, I_PTEST = 7629, I_PUNPCKHBW = 3780,
	I_PUNPCKHDQ = 3826, I_PUNPCKHQDQ = 3895, I_PUNPCKHWD = 3803, I_PUNPCKLBW = 3612,
	I_PUNPCKLDQ = 3658, I_PUNPCKLQDQ = 3870, I_PUNPCKLWD = 3635, I_PUSH = 16,
	I_PUSHA = 91, I_PUSHF = 270, I_PXOR = 6981, I_RCL = 977, I_RCPPS = 2953, I_RCPSS = 2960,
	I_RCR = 982, I_RDFSBASE = 9882, I_RDGSBASE = 9912, I_RDMSR = 600, I_RDPMC = 607,
	I_RDRAND = 9980, I_RDTSC = 593, I_RDTSCP = 1864, I_RET = 325, I_RETF = 354,
	I_ROL = 967, I_ROR = 972, I_ROUNDPD = 9296, I_ROUNDPS = 9277, I_ROUNDSD = 9334,
	I_ROUNDSS = 9315, I_RSM = 882, I_RSQRTPS = 2915, I_RSQRTSS = 2924, I_SAHF = 283,
	I_SAL = 997, I_SALC = 394, I_SAR = 1002, I_SBB = 36, I_SCAS = 319, I_SETA = 807,
	I_SETAE = 780, I_SETB = 774, I_SETBE = 800, I_SETG = 859, I_SETGE = 845, I_SETL = 839,
	I_SETLE = 852, I_SETNO = 767, I_SETNP = 832, I_SETNS = 819, I_SETNZ = 793,
	I_SETO = 761, I_SETP = 826, I_SETS = 813, I_SETZ = 787, I_SFENCE = 4321, I_SGDT = 1675,
	I_SHL = 987, I_SHLD = 876, I_SHR = 992, I_SHRD = 892, I_SHUFPD = 6336, I_SHUFPS = 6328,
	I_SIDT = 1681, I_SKINIT = 1839, I_SLDT = 1641, I_SMSW = 1699, I_SQRTPD = 2855,
	I_SQRTPS = 2847, I_SQRTSD = 2871, I_SQRTSS = 2863, I_STC = 497, I_STD = 517,
	I_STGI = 1827, I_STI = 507, I_STMXCSR = 9951, I_STOS = 307, I_STR = 1647, I_SUB = 51,
	I_SUBPD = 3379, I_SUBPS = 3372, I_SUBSD = 3393, I_SUBSS = 3386, I_SWAPGS = 1856,
	I_SYSCALL = 532, I_SYSENTER = 614, I_SYSEXIT = 624, I_SYSRET = 547, I_TEST = 206,
	I_TZCNT = 4351, I_UCOMISD = 2742, I_UCOMISS = 2733, I_UD2 = 569, I_UNPCKHPD = 2296,
	I_UNPCKHPS = 2286, I_UNPCKLPD = 2254, I_UNPCKLPS = 2244, I_VADDPD = 3139,
	I_VADDPS = 3131, I_VADDSD = 3155, I_VADDSS = 3147, I_VADDSUBPD = 6414, I_VADDSUBPS = 6425,
	I_VAESDEC = 9217, I_VAESDECLAST = 9238, I_VAESENC = 9175, I_VAESENCLAST = 9196,
	I_VAESIMC = 9158, I_VAESKEYGENASSIST = 9812, I_VANDNPD = 3038, I_VANDNPS = 3029,
	I_VANDPD = 3005, I_VANDPS = 2997, I_VBLENDPD = 9381, I_VBLENDPS = 9362, I_VBLENDVPD = 9681,
	I_VBLENDVPS = 9670, I_VBROADCASTF128 = 7672, I_VBROADCASTSD = 7658, I_VBROADCASTSS = 7644,
	I_VCMPEQPD = 5088, I_VCMPEQPS = 4686, I_VCMPEQSD = 5892, I_VCMPEQSS = 5490,
	I_VCMPEQ_OSPD = 5269, I_VCMPEQ_OSPS = 4867, I_VCMPEQ_OSSD = 6073, I_VCMPEQ_OSSS = 5671,
	I_VCMPEQ_UQPD = 5175, I_VCMPEQ_UQPS = 4773, I_VCMPEQ_UQSD = 5979, I_VCMPEQ_UQSS = 5577,
	I_VCMPEQ_USPD = 5378, I_VCMPEQ_USPS = 4976, I_VCMPEQ_USSD = 6182, I_VCMPEQ_USSS = 5780,
	I_VCMPFALSEPD = 5210, I_VCMPFALSEPS = 4808, I_VCMPFALSESD = 6014, I_VCMPFALSESS = 5612,
	I_VCMPFALSE_OSPD = 5419, I_VCMPFALSE_OSPS = 5017, I_VCMPFALSE_OSSD = 6223,
	I_VCMPFALSE_OSSS = 5821, I_VCMPGEPD = 5237, I_VCMPGEPS = 4835, I_VCMPGESD = 6041,
	I_VCMPGESS = 5639, I_VCMPGE_OQPD = 5449, I_VCMPGE_OQPS = 5047, I_VCMPGE_OQSD = 6253,
	I_VCMPGE_OQSS = 5851, I_VCMPGTPD = 5247, I_VCMPGTPS = 4845, I_VCMPGTSD = 6051,
	I_VCMPGTSS = 5649, I_VCMPGT_OQPD = 5462, I_VCMPGT_OQPS = 5060, I_VCMPGT_OQSD = 6266,
	I_VCMPGT_OQSS = 5864, I_VCMPLEPD = 5108, I_VCMPLEPS = 4706, I_VCMPLESD = 5912,
	I_VCMPLESS = 5510, I_VCMPLE_OQPD = 5295, I_VCMPLE_OQPS = 4893, I_VCMPLE_OQSD = 6099,
	I_VCMPLE_OQSS = 5697, I_VCMPLTPD = 5098, I_VCMPLTPS = 4696, I_VCMPLTSD = 5902,
	I_VCMPLTSS = 5500, I_VCMPLT_OQPD = 5282, I_VCMPLT_OQPS = 4880, I_VCMPLT_OQSD = 6086,
	I_VCMPLT_OQSS = 5684, I_VCMPNEQPD = 5131, I_VCMPNEQPS = 4729, I_VCMPNEQSD = 5935,
	I_VCMPNEQSS = 5533, I_VCMPNEQ_OQPD = 5223, I_VCMPNEQ_OQPS = 4821, I_VCMPNEQ_OQSD = 6027,
	I_VCMPNEQ_OQSS = 5625, I_VCMPNEQ_OSPD = 5435, I_VCMPNEQ_OSPS = 5033, I_VCMPNEQ_OSSD = 6239,
	I_VCMPNEQ_OSSS = 5837, I_VCMPNEQ_USPD = 5323, I_VCMPNEQ_USPS = 4921, I_VCMPNEQ_USSD = 6127,
	I_VCMPNEQ_USSS = 5725, I_VCMPNGEPD = 5188, I_VCMPNGEPS = 4786, I_VCMPNGESD = 5992,
	I_VCMPNGESS = 5590, I_VCMPNGE_UQPD = 5391, I_VCMPNGE_UQPS = 4989, I_VCMPNGE_UQSD = 6195,
	I_VCMPNGE_UQSS = 5793, I_VCMPNGTPD = 5199, I_VCMPNGTPS = 4797, I_VCMPNGTSD = 6003,
	I_VCMPNGTSS = 5601, I_VCMPNGT_UQPD = 5405, I_VCMPNGT_UQPS = 5003, I_VCMPNGT_UQSD = 6209,
	I_VCMPNGT_UQSS = 5807, I_VCMPNLEPD = 5153, I_VCMPNLEPS = 4751, I_VCMPNLESD = 5957,
	I_VCMPNLESS = 5555, I_VCMPNLE_UQPD = 5351, I_VCMPNLE_UQPS = 4949, I_VCMPNLE_UQSD = 6155,
	I_VCMPNLE_UQSS = 5753, I_VCMPNLTPD = 5142, I_VCMPNLTPS = 4740, I_VCMPNLTSD = 5946,
	I_VCMPNLTSS = 5544, I_VCMPNLT_UQPD = 5337, I_VCMPNLT_UQPS = 4935, I_VCMPNLT_UQSD = 6141,
	I_VCMPNLT_UQSS = 5739, I_VCMPORDPD = 5164, I_VCMPORDPS = 4762, I_VCMPORDSD = 5968,
	I_VCMPORDSS = 5566, I_VCMPORD_SPD = 5365, I_VCMPORD_SPS = 4963, I_VCMPORD_SSD = 6169,
	I_VCMPORD_SSS = 5767, I_VCMPTRUEPD = 5257, I_VCMPTRUEPS = 4855, I_VCMPTRUESD = 6061,
	I_VCMPTRUESS = 5659, I_VCMPTRUE_USPD = 5475, I_VCMPTRUE_USPS = 5073, I_VCMPTRUE_USSD = 6279,
	I_VCMPTRUE_USSS = 5877, I_VCMPUNORDPD = 5118, I_VCMPUNORDPS = 4716, I_VCMPUNORDSD = 5922,
	I_VCMPUNORDSS = 5520, I_VCMPUNORD_SPD = 5308, I_VCMPUNORD_SPS = 4906, I_VCMPUNORD_SSD = 6112,
	I_VCMPUNORD_SSS = 5710, I_VCOMISD = 2796, I_VCOMISS = 2787, I_VCVTDQ2PD = 6819,
	I_VCVTDQ2PS = 3338, I_VCVTPD2DQ = 6830, I_VCVTPD2PS = 3274, I_VCVTPS2DQ = 3349,
	I_VCVTPS2PD = 3263, I_VCVTSD2SI = 2722, I_VCVTSD2SS = 3296, I_VCVTSI2SD = 2536,
	I_VCVTSI2SS = 2525, I_VCVTSS2SD = 3285, I_VCVTSS2SI = 2711, I_VCVTTPD2DQ = 6807,
	I_VCVTTPS2DQ = 3360, I_VCVTTSD2SI = 2659, I_VCVTTSS2SI = 2647, I_VDIVPD = 3528,
	I_VDIVPS = 3520, I_VDIVSD = 3544, I_VDIVSS = 3536, I_VDPPD = 9621, I_VDPPS = 9608,
	I_VERR = 1663, I_VERW = 1669, I_VEXTRACTF128 = 9516, I_VEXTRACTPS = 9491,
	I_VFMADD132PD = 8387, I_VFMADD132PS = 8374, I_VFMADD132SD = 8413, I_VFMADD132SS = 8400,
	I_VFMADD213PD = 8667, I_VFMADD213PS = 8654, I_VFMADD213SD = 8693, I_VFMADD213SS = 8680,
	I_VFMADD231PD = 8947, I_VFMADD231PS = 8934, I_VFMADD231SD = 8973, I_VFMADD231SS = 8960,
	I_VFMADDSUB132PD = 8326, I_VFMADDSUB132PS = 8310, I_VFMADDSUB213PD = 8606,
	I_VFMADDSUB213PS = 8590, I_VFMADDSUB231PD = 8886, I_VFMADDSUB231PS = 8870,
	I_VFMSUB132PD = 8439, I_VFMSUB132PS = 8426, I_VFMSUB132SD = 8465, I_VFMSUB132SS = 8452,
	I_VFMSUB213PD = 8719, I_VFMSUB213PS = 8706, I_VFMSUB213SD = 8745, I_VFMSUB213SS = 8732,
	I_VFMSUB231PD = 8999, I_VFMSUB231PS = 8986, I_VFMSUB231SD = 9025, I_VFMSUB231SS = 9012,
	I_VFMSUBADD132PD = 8358, I_VFMSUBADD132PS = 8342, I_VFMSUBADD213PD = 8638,
	I_VFMSUBADD213PS = 8622, I_VFMSUBADD231PD = 8918, I_VFMSUBADD231PS = 8902,
	I_VFNMADD132PD = 8492, I_VFNMADD132PS = 8478, I_VFNMADD132SD = 8520, I_VFNMADD132SS = 8506,
	I_VFNMADD213PD = 8772, I_VFNMADD213PS = 8758, I_VFNMADD213SD = 8800, I_VFNMADD213SS = 8786,
	I_VFNMADD231PD = 9052, I_VFNMADD231PS = 9038, I_VFNMADD231SD = 9080, I_VFNMADD231SS = 9066,
	I_VFNMSUB132PD = 8548, I_VFNMSUB132PS = 8534, I_VFNMSUB132SD = 8576, I_VFNMSUB132SS = 8562,
	I_VFNMSUB213PD = 8828, I_VFNMSUB213PS = 8814, I_VFNMSUB213SD = 8856, I_VFNMSUB213SS = 8842,
	I_VFNMSUB231PD = 9108, I_VFNMSUB231PS = 9094, I_VFNMSUB231SD = 9136, I_VFNMSUB231SS = 9122,
	I_VHADDPD = 4197, I_VHADDPS = 4206, I_VHSUBPD = 4231, I_VHSUBPS = 4240, I_VINSERTF128 = 9503,
	I_VINSERTPS = 9557, I_VLDDQU = 7001, I_VLDMXCSR = 9941, I_VMASKMOVDQU = 7131,
	I_VMASKMOVPD = 7949, I_VMASKMOVPS = 7937, I_VMAXPD = 3588, I_VMAXPS = 3580,
	I_VMAXSD = 3604, I_VMAXSS = 3596, I_VMCALL = 1719, I_VMCLEAR = 9997, I_VMFUNC = 1787,
	I_VMINPD = 3468, I_VMINPS = 3460, I_VMINSD = 3484, I_VMINSS = 3476, I_VMLAUNCH = 1727,
	I_VMLOAD = 1811, I_VMMCALL = 1802, I_VMOVAPD = 2476, I_VMOVAPS = 2467, I_VMOVD = 3932,
	I_VMOVDDUP = 2234, I_VMOVDQA = 3962, I_VMOVDQU = 3971, I_VMOVHLPS = 2195,
	I_VMOVHPD = 2382, I_VMOVHPS = 2373, I_VMOVLHPS = 2363, I_VMOVLPD = 2214, I_VMOVLPS = 2205,
	I_VMOVMSKPD = 2836, I_VMOVMSKPS = 2825, I_VMOVNTDQ = 6858, I_VMOVNTDQA = 7905,
	I_VMOVNTPD = 2593, I_VMOVNTPS = 2583, I_VMOVQ = 3939, I_VMOVSD = 2143, I_VMOVSHDUP = 2391,
	I_VMOVSLDUP = 2223, I_VMOVSS = 2135, I_VMOVUPD = 2126, I_VMOVUPS = 2117, I_VMPSADBW = 9637,
	I_VMPTRLD = 9988, I_VMPTRST = 6385, I_VMREAD = 4128, I_VMRESUME = 1737, I_VMRUN = 1795,
	I_VMSAVE = 1819, I_VMULPD = 3199, I_VMULPS = 3191, I_VMULSD = 3215, I_VMULSS = 3207,
	I_VMWRITE = 4152, I_VMXOFF = 1747, I_VMXON = 10006, I_VORPD = 3066, I_VORPS = 3059,
	I_VPABSB = 7695, I_VPABSD = 7725, I_VPABSW = 7710, I_VPACKSSDW = 3859, I_VPACKSSWB = 3691,
	I_VPACKUSDW = 7926, I_VPACKUSWB = 3769, I_VPADDB = 7211, I_VPADDD = 7241,
	I_VPADDQ = 6488, I_VPADDSB = 6938, I_VPADDSW = 6955, I_VPADDUSW = 6629, I_VPADDW = 7226,
	I_VPALIGNR = 9419, I_VPAND = 6613, I_VPANDN = 6672, I_VPAVGB = 6687, I_VPAVGW = 6732,
	I_VPBLENDVB = 9692, I_VPBLENDW = 9400, I_VPCLMULQDQ = 9658, I_VPCMPEQB = 4052,
	I_VPCMPEQD = 4090, I_VPCMPEQQ = 7885, I_VPCMPEQW = 4071, I_VPCMPESTRI = 9737,
	I_VPCMPESTRM = 9714, I_VPCMPGTB = 3711, I_VPCMPGTD = 3749, I_VPCMPGTQ = 8096,
	I_VPCMPGTW = 3730, I_VPCMPISTRI = 9783, I_VPCMPISTRM = 9760, I_VPERM2F128 = 9265,
	I_VPERMILPD = 7570, I_VPERMILPS = 7559, I_VPEXTRB = 9437, I_VPEXTRD = 9462,
	I_VPEXTRQ = 9471, I_VPEXTRW = 6319, I_VPHADDD = 7383, I_VPHADDSW = 7401, I_VPHADDW = 7366,
	I_VPHMINPOSUW = 8271, I_VPHSUBD = 7459, I_VPHSUBSW = 7477, I_VPHSUBW = 7442,
	I_VPINSRB = 9538, I_VPINSRD = 9584, I_VPINSRQ = 9593, I_VPINSRW = 6302, I_VPMADDUBSW = 7422,
	I_VPMADDWD = 7082, I_VPMAXSB = 8182, I_VPMAXSD = 8199, I_VPMAXSW = 6972, I_VPMAXUB = 6656,
	I_VPMAXUD = 8233, I_VPMAXUW = 8216, I_VPMINSB = 8114, I_VPMINSD = 8131, I_VPMINSW = 6910,
	I_VPMINUB = 6598, I_VPMINUD = 8165, I_VPMINUW = 8148, I_VPMOVMSKB = 6541,
	I_VPMOVSXBD = 7764, I_VPMOVSXBQ = 7785, I_VPMOVSXBW = 7743, I_VPMOVSXDQ = 7848,
	I_VPMOVSXWD = 7806, I_VPMOVSXWQ = 7827, I_VPMOVZXBD = 7992, I_VPMOVZXBQ = 8013,
	I_VPMOVZXBW = 7971, I_VPMOVZXDQ = 8076, I_VPMOVZXWD = 8034, I_VPMOVZXWQ = 8055,
	I_VPMULDQ = 7867, I_VPMULHRSW = 7548, I_VPMULHUW = 6749, I_VPMULHW = 6767,
	I_VPMULLD = 8250, I_VPMULLW = 6504, I_VPMULUDQ = 7063, I_VPOR = 6924, I_VPSADBW = 7100,
	I_VPSHUFB = 7349, I_VPSHUFD = 4014, I_VPSHUFHW = 4023, I_VPSHUFLW = 4033,
	I_VPSIGNB = 7495, I_VPSIGND = 7529, I_VPSIGNW = 7512, I_VPSLLD = 7031, I_VPSLLDQ = 9855,
	I_VPSLLQ = 7046, I_VPSLLW = 7016, I_VPSRAD = 6717, I_VPSRAW = 6702, I_VPSRLD = 6458,
	I_VPSRLDQ = 9838, I_VPSRLQ = 6473, I_VPSRLW = 6443, I_VPSUBB = 7151, I_VPSUBD = 7181,
	I_VPSUBQ = 7196, I_VPSUBSB = 6876, I_VPSUBSW = 6893, I_VPSUBUSB = 6561, I_VPSUBUSW = 6580,
	I_VPSUBW = 7166, I_VPTEST = 7636, I_VPUNPCKHBW = 3791, I_VPUNPCKHDQ = 3837,
	I_VPUNPCKHQDQ = 3907, I_VPUNPCKHWD = 3814, I_VPUNPCKLBW = 3623, I_VPUNPCKLDQ = 3669,
	I_VPUNPCKLQDQ = 3882, I_VPUNPCKLWD = 3646, I_VPXOR = 6987, I_VRCPPS = 2967,
	I_VRCPSS = 2975, I_VROUNDPD = 9305, I_VROUNDPS = 9286, I_VROUNDSD = 9343,
	I_VROUNDSS = 9324, I_VRSQRTPS = 2933, I_VRSQRTSS = 2943, I_VSHUFPD = 6353,
	I_VSHUFPS = 6344, I_VSQRTPD = 2888, I_VSQRTPS = 2879, I_VSQRTSD = 2906, I_VSQRTSS = 2897,
	I_VSTMXCSR = 9970, I_VSUBPD = 3408, I_VSUBPS = 3400, I_VSUBSD = 3424, I_VSUBSS = 3416,
	I_VTESTPD = 7590, I_VTESTPS = 7581, I_VUCOMISD = 2761, I_VUCOMISS = 2751,
	I_VUNPCKHPD = 2317, I_VUNPCKHPS = 2306, I_VUNPCKLPD = 2275, I_VUNPCKLPS = 2264,
	I_VXORPD = 3095, I_VXORPS = 3087, I_VZEROALL = 4118, I_VZEROUPPER = 4106,
	I_WAIT = 10028, I_WBINVD = 561, I_WRFSBASE = 9931, I_WRGSBASE = 9960, I_WRMSR = 586,
	I_XADD = 946, I_XCHG = 212, I_XGETBV = 1771, I_XLAT = 400, I_XOR = 61, I_XORPD = 3080,
	I_XORPS = 3073, I_XRSTOR = 4273, I_XRSTOR64 = 4281, I_XSAVE = 4249, I_XSAVE64 = 4256,
	I_XSAVEOPT = 4299, I_XSAVEOPT64 = 4309, I_XSETBV = 1779
} _InstructionType;

typedef enum {
	R_RAX, R_RCX, R_RDX, R_RBX, R_RSP, R_RBP, R_RSI, R_RDI, R_R8, R_R9, R_R10, R_R11, R_R12, R_R13, R_R14, R_R15,
	R_EAX, R_ECX, R_EDX, R_EBX, R_ESP, R_EBP, R_ESI, R_EDI, R_R8D, R_R9D, R_R10D, R_R11D, R_R12D, R_R13D, R_R14D, R_R15D,
	R_AX, R_CX, R_DX, R_BX, R_SP, R_BP, R_SI, R_DI, R_R8W, R_R9W, R_R10W, R_R11W, R_R12W, R_R13W, R_R14W, R_R15W,
	R_AL, R_CL, R_DL, R_BL, R_AH, R_CH, R_DH, R_BH, R_R8B, R_R9B, R_R10B, R_R11B, R_R12B, R_R13B, R_R14B, R_R15B,
	R_SPL, R_BPL, R_SIL, R_DIL,
	R_ES, R_CS, R_SS, R_DS, R_FS, R_GS,
	R_RIP,
	R_ST0, R_ST1, R_ST2, R_ST3, R_ST4, R_ST5, R_ST6, R_ST7,
	R_MM0, R_MM1, R_MM2, R_MM3, R_MM4, R_MM5, R_MM6, R_MM7,
	R_XMM0, R_XMM1, R_XMM2, R_XMM3, R_XMM4, R_XMM5, R_XMM6, R_XMM7, R_XMM8, R_XMM9, R_XMM10, R_XMM11, R_XMM12, R_XMM13, R_XMM14, R_XMM15,
	R_YMM0, R_YMM1, R_YMM2, R_YMM3, R_YMM4, R_YMM5, R_YMM6, R_YMM7, R_YMM8, R_YMM9, R_YMM10, R_YMM11, R_YMM12, R_YMM13, R_YMM14, R_YMM15,
	R_CR0, R_UNUSED0, R_CR2, R_CR3, R_CR4, R_UNUSED1, R_UNUSED2, R_UNUSED3, R_CR8,
	R_DR0, R_DR1, R_DR2, R_DR3, R_UNUSED4, R_UNUSED5, R_DR6, R_DR7
} _RegisterType;

#endif /* MNEMONICS_H */
