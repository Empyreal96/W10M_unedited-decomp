// PpmIdleExecuteTransition 
 
int __fastcall PpmIdleExecuteTransition(int a1, int a2, unsigned int a3, int a4, unsigned __int64 a5, __int64 a6, unsigned __int8 a7)
{
  int v7; // r7
  int v8; // r4
  int v9; // r10
  int v10; // r3
  unsigned int *v11; // r2
  int v12; // r5
  int v13; // r9
  _BYTE *v14; // r8
  BOOL v15; // r3
  bool v16; // r6
  int result; // r0
  __int64 v18; // r4
  unsigned int v19; // r6
  unsigned int v20; // r4
  int v21; // r6
  int v22; // r0
  unsigned int *v23; // r1
  unsigned int v24; // r8
  BOOL v25; // r2
  int v26; // r6
  int v27; // r10
  int v28; // r0
  int v29; // r1
  unsigned int v30; // r1
  unsigned int v31; // r4
  int v32; // r8
  int v33; // r10
  unsigned int v34; // r2
  unsigned __int64 v35; // kr18_8
  int v36; // lr
  unsigned int v37; // r3
  unsigned int v38; // r2
  unsigned __int64 v39; // r0
  int v40; // r10
  int v41; // lr
  unsigned __int64 v42; // kr20_8
  unsigned __int64 *v43; // r3
  unsigned __int64 v44; // kr28_8
  unsigned int v45; // r3
  unsigned int v46; // r2
  bool v47; // cf
  int v48; // r1
  int v49; // r3
  int v50; // r0
  int v51; // r2
  unsigned __int64 *v52; // r10
  int v53; // lr
  unsigned __int64 v54; // r2
  int (__fastcall *v55)(int, int, unsigned int, _DWORD, _DWORD); // r4
  int v56; // r4
  unsigned int v57; // r4
  int v58; // r6
  int v59; // r5
  __int64 v60; // kr30_8
  char v61; // r0
  __int16 v62; // r4
  int v63; // r5
  int v64; // r0
  int v65; // r4
  unsigned __int64 v66; // r4
  unsigned __int64 v67; // r2
  int v68; // r1
  int v69; // r10
  unsigned int v70; // r2
  unsigned __int64 v71; // kr40_8
  unsigned int v72; // r3
  unsigned int v73; // r6
  unsigned __int64 v74; // kr48_8
  unsigned __int64 v75; // kr50_8
  int v76; // r5
  int v77; // r4
  int v78; // r0
  int v79; // r1
  unsigned __int8 *v80; // r3
  unsigned int v81; // r1
  int v82; // r0
  int v83; // lr
  int v84; // r10
  int v85; // r4
  int v86; // r5
  int v87; // r9
  int v88; // r8
  int v89; // r6
  unsigned int *v90; // r10
  unsigned int v91; // r1
  int v92; // r3
  int v93; // r1
  int v94; // r6
  unsigned int v95; // r5
  int v96; // r9
  int v97; // r10
  unsigned int v98; // r4
  unsigned int v99; // r0
  unsigned int v100; // r2
  unsigned int v101; // r4
  unsigned int v102; // r0
  unsigned int v103; // r2
  int v104; // r3
  unsigned int v105; // r2
  unsigned int v106; // r0
  bool v107; // zf
  unsigned int v108; // r2
  int v109; // r6
  unsigned int *v110; // t2
  unsigned int v111; // r5
  unsigned int v112; // r4
  unsigned int v113; // r0
  unsigned int v114; // r2
  unsigned int *v115; // r6
  int v116; // r4
  unsigned int v117; // r1
  unsigned int v118; // r3
  int v119; // r3
  unsigned int i; // r1
  int v121; // r2
  int v122; // r3
  unsigned int *v123; // t2
  unsigned int v124; // r4
  unsigned int v125; // r0
  unsigned int v126; // r1
  unsigned int v127; // r2
  unsigned int v128; // r2
  int v129; // r3
  int *v130; // r3
  int v131; // r4
  unsigned int *v132; // r2
  unsigned int v133; // r4
  unsigned int v134; // r2
  int v135; // r6
  int v136; // r10
  int v137; // r6
  int v138; // r10
  int v139; // r3
  int v140; // r1
  _DWORD *v141; // r0
  unsigned int v142; // r2
  int v143; // t1
  int v144; // r3
  unsigned int v145; // r2
  unsigned int v146; // r0
  int v147; // r1
  int v148; // r3
  int v149; // r10
  int v150; // r3
  int v151; // lr
  int v152; // r0
  __int64 v153; // kr58_8
  int v154; // r6
  unsigned int v155; // r6
  unsigned int v156; // lr
  int v157; // r1
  unsigned int *v158; // t2
  int v159; // r4
  unsigned int v160; // r1
  unsigned int v161; // r0
  int v162; // r2
  int v163; // r1
  int v164; // r2
  unsigned __int8 *v165; // r3
  unsigned int v166; // r2
  unsigned __int64 v167; // r0
  unsigned __int64 v168; // kr70_8
  int v169; // r1
  int v170; // r2
  unsigned __int8 *v171; // r3
  unsigned int v172; // r2
  int v173; // r1
  int v174; // [sp+18h] [bp-150h]
  unsigned int *v175; // [sp+1Ch] [bp-14Ch]
  int v176; // [sp+1Ch] [bp-14Ch]
  BOOL v177; // [sp+20h] [bp-148h]
  int v179; // [sp+28h] [bp-140h] BYREF
  int v180; // [sp+2Ch] [bp-13Ch]
  int v181; // [sp+30h] [bp-138h]
  unsigned int v182; // [sp+34h] [bp-134h]
  unsigned int v183; // [sp+38h] [bp-130h] BYREF
  int v184; // [sp+3Ch] [bp-12Ch]
  int v185; // [sp+40h] [bp-128h]
  unsigned int v186; // [sp+44h] [bp-124h]
  int v187; // [sp+48h] [bp-120h]
  int v188; // [sp+4Ch] [bp-11Ch]
  int v189; // [sp+50h] [bp-118h]
  int v190; // [sp+54h] [bp-114h]
  int v191; // [sp+58h] [bp-110h]
  int v192[2]; // [sp+60h] [bp-108h] BYREF
  int v193; // [sp+68h] [bp-100h]
  int v194; // [sp+6Ch] [bp-FCh]
  int v195; // [sp+70h] [bp-F8h]
  int v196; // [sp+74h] [bp-F4h]
  int v197; // [sp+78h] [bp-F0h] BYREF
  int v198; // [sp+7Ch] [bp-ECh]
  int v199; // [sp+80h] [bp-E8h]
  int v200; // [sp+84h] [bp-E4h]
  _DWORD v201[2]; // [sp+88h] [bp-E0h] BYREF
  int v202; // [sp+90h] [bp-D8h]
  int v203; // [sp+94h] [bp-D4h]
  int v204; // [sp+98h] [bp-D0h]
  int v205; // [sp+9Ch] [bp-CCh]
  int v206; // [sp+A0h] [bp-C8h]
  int v207; // [sp+A4h] [bp-C4h]
  unsigned __int64 v208; // [sp+A8h] [bp-C0h] BYREF
  unsigned int v209[2]; // [sp+B0h] [bp-B8h] BYREF
  int v210[8]; // [sp+B8h] [bp-B0h] BYREF
  __int16 v211[2]; // [sp+D8h] [bp-90h] BYREF
  int v212; // [sp+DCh] [bp-8Ch]
  int v213; // [sp+E0h] [bp-88h]
  int v214; // [sp+E8h] [bp-80h] BYREF
  __int16 v215; // [sp+ECh] [bp-7Ch]
  char v216; // [sp+EEh] [bp-7Ah]
  char v217; // [sp+EFh] [bp-79h]
  __int64 v218; // [sp+F0h] [bp-78h]
  _DWORD v219[4]; // [sp+F8h] [bp-70h] BYREF
  _DWORD v220[4]; // [sp+108h] [bp-60h] BYREF
  int v221[4]; // [sp+118h] [bp-50h] BYREF
  int v222[4]; // [sp+128h] [bp-40h] BYREF
  int var30[13]; // [sp+138h] [bp-30h] BYREF

  v195 = a4;
  v192[0] = 0;
  v183 = 0;
  v184 = 0;
  v190 = 0;
  v191 = 0;
  v193 = 0;
  v196 = 0;
  v187 = -1;
  v188 = -1;
  v179 = -1;
  v7 = *(_DWORD *)(a1 + 2944);
  v8 = a1 + 2944;
  v9 = a7;
  v10 = *(_DWORD *)(v7 + 120);
  v181 = a1;
  v182 = a3;
  v11 = (unsigned int *)(a1 + 3000);
  v189 = v10;
  v12 = 0;
  v194 = 0;
  v13 = a1;
  v185 = a1 + 2944;
  v14 = (_BYTE *)(v7 + (a2 << 6));
  v174 = 0;
  v175 = (unsigned int *)(a1 + 3000);
  v15 = a7 && !*(_BYTE *)(v7 + 171) && !v14[313];
  v16 = v15;
  v180 = 3;
  result = 1;
  v177 = v15;
  if ( !*(_BYTE *)v7 )
  {
    if ( a7 )
    {
      __pld(v11);
      v98 = *v11;
      do
      {
        v99 = v98;
        __dmb(0xBu);
        do
          v100 = __ldrex(v175);
        while ( v100 == v98 && __strex(v98 & 0xFFFFFF | 0x1000000, v175) );
        v98 = v100;
        __dmb(0xBu);
      }
      while ( v100 != v99 );
      result = 1;
    }
    *(_DWORD *)(v7 + 72) = 0;
    *(_WORD *)(v7 + 68) = 1;
    *(_WORD *)(v7 + 70) = 1;
    *(_DWORD *)(v7 + 76) = 0;
    v18 = *(_QWORD *)(v7 + 180);
    v197 = 65537;
    v198 = 0;
    v199 = 0;
    v200 = 0;
    v209[0] = 1;
    v19 = 0;
    v209[1] = (unsigned int)&v197;
    if ( (_DWORD)v18 )
    {
      while ( 1 )
      {
        if ( *(unsigned __int8 *)(HIDWORD(v18) + 4) != 255 )
        {
          v127 = *(_DWORD *)HIDWORD(v18);
          v198 = *(unsigned __int8 *)(HIDWORD(v18) + 4);
          if ( v127 >= KeNumberProcessors_0 )
            return sub_541974(result);
          result = PpmTestAndLockProcessor(*(&KiProcessorBlock + v127), v7 + 68, v209);
          v174 = result;
          if ( result < 0 )
            break;
        }
        ++v19;
        HIDWORD(v18) += 8;
        if ( v19 >= (unsigned int)v18 )
          goto LABEL_6;
      }
      v21 = result;
    }
    else
    {
LABEL_6:
      v20 = *(_DWORD *)(v7 + 76);
      while ( v20 )
      {
        v134 = __clz(__rbit(v20));
        v20 &= ~(1 << v134);
        if ( v134 >= KeNumberProcessors_0 )
          v135 = 0;
        else
          v135 = (int)*(&KiProcessorBlock + v134);
        v136 = *(_DWORD *)(v135 + 2944);
        v186 = v135 + 2944;
        memset(v210, 0, sizeof(v210));
        LOBYTE(v210[6]) = 1;
        v210[4] = v135;
        v137 = v135 + 2944;
        v210[2] = PopIdleTransitionTimeout;
        v210[3] = MEMORY[0x6824EC];
        while ( 1 )
        {
          result = (*(int (__fastcall **)(_DWORD))(v136 + 112))(*(_DWORD *)(v136 + 120));
          if ( result )
            break;
          if ( (*(_DWORD *)(v137 + 56) & 0xFF000000) != 83886080 )
          {
            v21 = -1073741782;
            goto LABEL_9;
          }
          PpmIdleTransitionStall(v210);
        }
      }
      v21 = 0;
LABEL_9:
      v174 = v21;
      v9 = a7;
    }
    if ( v21 < 0 )
    {
      if ( v9 )
      {
        v158 = v175;
        __pld(v175);
        v159 = *v158;
        do
        {
          result = v159;
          __dmb(0xBu);
          do
            v160 = __ldrex(v175);
          while ( v160 == v159 && __strex(v159 & 0xFFFFFF, v175) );
          v159 = v160;
          __dmb(0xBu);
        }
        while ( v160 != result );
      }
      v180 = 1;
      goto LABEL_164;
    }
    v8 = v185;
    v11 = v175;
    v16 = v177;
    v12 = 0;
  }
  if ( *(_DWORD *)(v7 + 76) )
    *(_WORD *)(v7 + 36) |= 0x20u;
  *(_BYTE *)(v8 + 40) = v16;
  *(_DWORD *)(v8 + 44) = a2;
  if ( v9 )
  {
    *(_BYTE *)(v8 + 41) = v14[310] == 0;
    __pld(v11);
    v101 = *v11;
    do
    {
      v102 = v101;
      __dmb(0xBu);
      do
        v103 = __ldrex(v175);
      while ( v103 == v101 && __strex(v101 & 0xFFFFFF | 0x2000000, v175) );
      v101 = v103;
      __dmb(0xBu);
    }
    while ( v103 != v102 );
    v8 = v185;
  }
  if ( *(_BYTE *)(v7 + 6) )
  {
    v161 = *(_DWORD *)(v7 + 156);
    v162 = *(_DWORD *)(v7 + 152);
    v184 = 1;
    if ( __PAIR64__(v161, v162) <= (unsigned int)KeMaximumIncrement )
    {
      v162 = KeMaximumIncrement;
      v161 = 0;
    }
    *(_QWORD *)(v8 + 32) = a6 + __PAIR64__(v161, KeMaximumIncrement) + (unsigned int)v162;
    v163 = *(unsigned __int8 *)(v13 + 1053);
    v164 = *(_DWORD *)(v13 + 2360) + 132;
    __dmb(0xBu);
    v165 = (unsigned __int8 *)(v164 + (v163 >> 3));
    do
      v166 = __ldrex(v165);
    while ( __strex(v166 | (1 << (v163 & 7)), v165) );
    __dmb(0xBu);
  }
  if ( v14[309] )
    goto LABEL_30;
  v196 = 1;
  v22 = *(_DWORD *)(v13 + 1048);
  v23 = (unsigned int *)(*(_DWORD *)(v13 + 2360) + 128);
  __dmb(0xBu);
  do
    v24 = __ldrex(v23);
  while ( __strex(v24 | v22, v23) );
  __dmb(0xBu);
  v25 = v177;
  v26 = *(_DWORD *)(v13 + 2944);
  v193 = (unsigned __int8)KiTbSendIpiForBroadcastFlushes;
  v27 = 0;
  v190 = 0;
  if ( v177 )
  {
    v190 = 1;
    goto LABEL_127;
  }
  if ( v182 != -1 )
    goto LABEL_127;
  if ( (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~*(_DWORD *)(v26 + 76) >> 16))
                       + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~*(_WORD *)(v26 + 76) >> 8))
                       + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~*(_BYTE *)(v26 + 76))
                       + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~*(_DWORD *)(v26 + 76) >> 24))) == KeNumberProcessors_0 - 1 )
  {
    v12 = 0;
    v25 = 0;
    v190 = 2;
LABEL_127:
    v104 = *(_DWORD *)(v26 + 8);
    v27 = 0;
    if ( v104 )
      *(_DWORD *)(v26 + 8) = v104 - 1;
    if ( *(_DWORD *)(v26 + 8) )
    {
LABEL_134:
      if ( v27 )
      {
        *(_BYTE *)(v26 + 3) = 1;
        if ( !v25 )
          goto LABEL_22;
        *(_DWORD *)(v26 + 40) = -1;
        *(_DWORD *)(v26 + 44) = -1;
      }
      if ( v25 )
        goto LABEL_23;
      goto LABEL_22;
    }
    v105 = 0;
    v106 = PpmExitLatencySamplingPercentage;
    if ( (unsigned int)PpmExitLatencySamplingPercentage > 0x64 )
    {
      v106 = 100;
    }
    else if ( !PpmExitLatencySamplingPercentage )
    {
LABEL_132:
      *(_DWORD *)(v26 + 8) = v105;
      v107 = v105 == 0;
      v25 = v177;
      if ( !v107 )
        v27 = 1;
      goto LABEL_134;
    }
    if ( !v106 )
      __brkdiv0();
    v105 = 0x64 / v106;
    goto LABEL_132;
  }
LABEL_22:
  v12 = 1;
LABEL_23:
  v28 = off_617A48(v12);
  v174 = v28;
  if ( *(_DWORD *)(v13 + 1692) )
  {
    v122 = -2147483631;
LABEL_172:
    v174 = v122;
    goto LABEL_173;
  }
  if ( v28 < 0 )
  {
LABEL_173:
    if ( a7 )
    {
      v123 = v175;
      __pld(v175);
      v124 = *v123;
      do
      {
        v125 = v124;
        __dmb(0xBu);
        do
          v126 = __ldrex(v175);
        while ( v126 == v124 && __strex(v124 & 0xFFFFFF, v175) );
        v124 = v126;
        __dmb(0xBu);
      }
      while ( v126 != v125 );
      v13 = v181;
    }
    v76 = v185;
    v77 = v174;
    v180 = 0;
LABEL_81:
    v78 = *(unsigned __int8 *)(v13 + 1053);
    v79 = *(_DWORD *)(v13 + 2360) + 128;
    __dmb(0xBu);
    v80 = (unsigned __int8 *)(v79 + (v78 >> 3));
    do
      v81 = __ldrex(v80);
    while ( __strex(v81 & ~(unsigned __int8)(1 << (v78 & 7)), v80) );
    __dmb(0xBu);
    if ( v193 )
    {
      __dmb(0xFu);
      __clrex();
    }
    if ( v191 && v77 >= 0 )
    {
      v82 = KeResumeClockTimerFromIdle(&v179);
      v187 = v179;
    }
    else
    {
      v82 = KeResumeClockTimerFromIdle(0);
    }
    off_617A50(v82);
    result = KeAccumulateTicks(v13, *(_DWORD *)(v13 + 1764), KeTickCount, 0, 0);
    goto LABEL_88;
  }
  if ( *(_BYTE *)v7 == 1 && PpmIdleRecheckCoordinatedIdleMask(v7) )
  {
    v122 = -1073741802;
    goto LABEL_172;
  }
  if ( v27 )
    *(_WORD *)(v7 + 36) |= 0x200u;
  if ( v177 )
  {
    v194 = 1;
    do
      v108 = __ldrex((unsigned int *)&PpmNonInterruptibleCount);
    while ( __strex(v108 + 1, (unsigned int *)&PpmNonInterruptibleCount) );
    __dmb(0xBu);
    KiSuspendClockTimer();
  }
  if ( *(_BYTE *)(v7 + 172) )
  {
    if ( !v27 || v177 )
    {
      v119 = 0;
    }
    else
    {
      v119 = 1;
      v191 = 1;
    }
    KePrepareClockTimerForIdle(v195, v29, *(_DWORD *)(v7 + 152), *(_DWORD *)(v7 + 156), v119);
  }
LABEL_30:
  v31 = HIDWORD(a5);
  v30 = a5;
  v32 = *(_DWORD *)(v185 + 264);
  if ( !v32 )
    goto LABEL_42;
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v33 = 0;
  }
  else
  {
    __disable_irq();
    v33 = 1;
  }
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v32);
  }
  else
  {
    do
      v34 = __ldrex((unsigned int *)v32);
    while ( __strex(1u, (unsigned int *)v32) );
    __dmb(0xBu);
    if ( !v34 )
      goto LABEL_36;
    KxWaitForSpinLockAndAcquire(v32);
  }
  v30 = a5;
LABEL_36:
  v35 = *(_QWORD *)(v32 + 16);
  v36 = *(_DWORD *)(v32 + 8);
  if ( __PAIR64__(HIDWORD(a5), v30) > v35 )
  {
    v37 = *(_DWORD *)(v32 + 24);
    v38 = *(_DWORD *)(v32 + 28);
    *(_DWORD *)(v32 + 16) = v30;
    *(_DWORD *)(v32 + 20) = HIDWORD(a5);
    *(_QWORD *)(v32 + 24) = __PAIR64__(HIDWORD(a5), v30) - v35 + __PAIR64__(v38, v37);
    *(_QWORD *)(v32 + 8 * v36 + 32) += __PAIR64__(HIDWORD(a5), v30) - v35;
    v31 = HIDWORD(a5);
  }
  *(_DWORD *)(v32 + 8) = v36 - 1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v32);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v32 = 0;
  }
  if ( v33 )
    __enable_irq();
LABEL_42:
  *(_DWORD *)(v7 + 16) = a2;
  LODWORD(v39) = ReadTimeStampCounter();
  v40 = HIDWORD(v39);
  v41 = v39;
  v42 = __PAIR64__(v31, a5) - *(_QWORD *)(v13 + 3040);
  __dmb(0xBu);
  v43 = (unsigned __int64 *)(v13 + 3056);
  do
    v44 = __ldrexd(v43);
  while ( __strexd(v44 + v42, v43) );
  __dmb(0xBu);
  v45 = *(_DWORD *)(v13 + 3016);
  *(_QWORD *)(v13 + 3040) = a5;
  v46 = *(_DWORD *)(v13 + 3020);
  if ( v39 > __PAIR64__(v46, v45) )
  {
    v47 = (unsigned int)v39 >= v45;
    v48 = v39 - v45;
    v49 = *(_DWORD *)(v13 + 3024);
    v50 = v40 - (v46 + !v47);
    v51 = *(_DWORD *)(v13 + 3028);
    *(_DWORD *)(v13 + 3024) = v49 + v48;
    *(_DWORD *)(v13 + 3028) = v50 + __CFADD__(v49, v48) + v51;
  }
  *(_DWORD *)(v13 + 3016) = v41;
  *(_DWORD *)(v13 + 3020) = v40;
  PpmUpdatePerformanceFeedback(v13, 0, 0, 1);
  if ( PopSnapEnergyCounters )
    PopSnapEnergyCounters(*(_DWORD *)(v13 + 20), 0, 0);
  __dmb(0xBu);
  v52 = (unsigned __int64 *)(v13 + 2968);
  v53 = HIDWORD(a5);
  do
    v54 = __ldrexd(v52);
  while ( __strexd(a5, v52) );
  __dmb(0xBu);
  v55 = *(int (__fastcall **)(int, int, unsigned int, _DWORD, _DWORD))(v7 + 84);
  if ( v55 )
  {
    v56 = v55(v189, a2, v182, *(_DWORD *)(v7 + 240), *(_DWORD *)(v7 + 248));
    v53 = HIDWORD(a5);
    v174 = v56;
  }
  else
  {
    v56 = v174;
  }
  if ( v56 >= 0 )
  {
    v57 = v182;
    v58 = *(_DWORD *)(v7 + 248);
    v59 = *(_DWORD *)(v7 + 240);
    if ( v182 != -1 )
    {
      v183 = v182;
      v138 = PpmPlatformStates + (v182 << 8);
      if ( (dword_682608 & 0x8000) != 0 )
      {
        v221[0] = (int)&v183;
        v221[1] = 0;
        v221[2] = 4;
        v221[3] = 0;
        EtwTraceKernelEvent(v221, 1, 1073774592, 4667, 1538);
        v53 = HIDWORD(a5);
      }
      if ( !*(_QWORD *)&algn_635412[110] )
      {
        v139 = dword_635500;
        __dmb(0xBu);
        if ( v182 == v139 )
        {
          LODWORD(v167) = KeQueryInterruptTime();
          do
            v168 = __ldrexd((unsigned __int64 *)&algn_635412[110]);
          while ( !v168 && __strexd(v167, (unsigned __int64 *)&algn_635412[110]) );
          v53 = HIDWORD(a5);
          v187 = v179;
        }
        else
        {
          v187 = v179;
        }
      }
      if ( *(_BYTE *)(v138 + 156) )
      {
        KdPowerTransition(-2147483644, &KeNumberProcessors_0);
        KdCallPowerHandlers(4);
        v53 = HIDWORD(a5);
      }
      v57 = v182;
      v52 = (unsigned __int64 *)(v13 + 2968);
    }
    if ( v59 )
    {
      if ( *(_BYTE *)(PpmPlatformStates + 12) && (dword_682608 & 0x8000) != 0 )
      {
        v219[0] = v58;
        v219[1] = 0;
        v219[2] = 4 * v59;
        v219[3] = 0;
        EtwTraceKernelEvent(v219, 1, 1073774592, 4671, 1538);
        v53 = HIDWORD(a5);
      }
      v140 = v58 + 4 * v59;
      do
      {
        v141 = (_DWORD *)(PpmPlatformStates + (*(_DWORD *)(v140 - 4) << 8));
        v141[48] = a5;
        v141[49] = v53;
        v142 = v141[47];
        if ( !*(_DWORD *)(PpmPlatformStates + 4) )
          v142 = v142 & 0xFFFFC000 | *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) & 0x3FFF;
        __dmb(0xBu);
        --v59;
        v140 -= 4;
        v141[47] = v142 & 0x8FFFFFFF | 0x40000000;
      }
      while ( v59 );
      v13 = v181;
    }
    if ( v57 != -1 )
      *(_WORD *)(v7 + 36) |= 0x10u;
    v60 = *(_QWORD *)(v7 + 144);
    v61 = *(_BYTE *)(v7 + 173);
    v62 = *(_WORD *)(v7 + 36);
    v63 = a2;
    if ( (dword_682608 & 0x8000) != 0 )
    {
      v217 = 0;
      var30[0] = (int)&v214;
      var30[1] = 0;
      var30[2] = 16;
      var30[3] = 0;
      v218 = v60;
      v216 = v61;
      v214 = a2;
      v215 = v62;
      EtwTraceKernelEvent(var30, 1, 1073774592, 4665, 1538);
    }
    if ( a7 )
    {
      if ( v177 )
        v109 = 4;
      else
        v109 = 3;
      v110 = v175;
      __pld(v175);
      v111 = *v110;
      do
      {
        v112 = v111;
        __dmb(0xBu);
        do
          v113 = __ldrex(v175);
        while ( v113 == v111 && __strex(v111 & 0xFFFFFF | (v109 << 24), v175) );
        v111 = v113;
        __dmb(0xBu);
      }
      while ( v113 != v112 );
      v63 = a2;
      v52 = (unsigned __int64 *)(v13 + 2968);
    }
    v64 = (*(int (__fastcall **)(int, int, unsigned int, _DWORD, _DWORD))(v7 + 88))(
            v189,
            v63,
            v182,
            *(_DWORD *)(v7 + 240),
            *(_DWORD *)(v7 + 248));
    v65 = v64;
    v174 = v64;
    if ( *(int *)(v7 + 48) < 0 && v64 >= 0 )
    {
      v65 = *(_DWORD *)(v7 + 48);
      v174 = v65;
    }
    if ( (dword_682608 & 0x8000) != 0 )
    {
      v222[0] = (int)v192;
      v222[1] = 0;
      v222[2] = 8;
      v222[3] = 0;
      v192[0] = v63;
      v192[1] = v65;
      EtwTraceKernelEvent(v222, 1, 1073774592, 4666, 1538);
    }
  }
  KeQueryPerformanceCounter(&v208, 0);
  v66 = v208;
  v183 = HIDWORD(v208);
  v192[0] = v208;
  __dmb(0xBu);
  do
    v67 = __ldrexd(v52);
  while ( __strexd(0i64, v52) );
  __dmb(0xBu);
  result = ReadTimeStampCounter();
  *(_DWORD *)(v13 + 3016) = result;
  *(_DWORD *)(v13 + 3020) = v68;
  *(_QWORD *)(v13 + 3040) = v66;
  if ( v32 )
  {
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v69 = 0;
    }
    else
    {
      __disable_irq();
      v69 = 1;
    }
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v32);
    }
    else
    {
      do
        v70 = __ldrex((unsigned int *)v32);
      while ( __strex(1u, (unsigned int *)v32) );
      __dmb(0xBu);
      if ( v70 )
        KxWaitForSpinLockAndAcquire(v32);
    }
    v71 = *(_QWORD *)(v32 + 16);
    result = *(_DWORD *)(v32 + 8);
    if ( v66 > v71 )
    {
      v47 = (unsigned int)v66 >= (unsigned int)v71;
      HIDWORD(v66) = v66 - v71;
      v72 = v183;
      *(_DWORD *)(v32 + 16) = v66;
      *(_DWORD *)(v32 + 20) = v72;
      LODWORD(v66) = v32 + 8 * result;
      v73 = v72 - (HIDWORD(v71) + !v47);
      *(_QWORD *)(v32 + 24) += __PAIR64__(v73, HIDWORD(v66));
      v74 = *(_QWORD *)(v66 + 32) + __PAIR64__(v73, HIDWORD(v66));
      HIDWORD(v66) = v183;
      *(_QWORD *)(v66 + 32) = v74;
      LODWORD(v66) = v192[0];
    }
    *(_DWORD *)(v32 + 8) = result + 1;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = KiReleaseSpinLockInstrumented(v32);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v32 = 0;
    }
    if ( v69 )
      __enable_irq();
  }
  v75 = v66 - a5;
  v76 = v185;
  *(_QWORD *)(v185 + 8) = v75;
  if ( a7 )
  {
    v115 = (unsigned int *)(v76 + 56);
    __pld((void *)(v76 + 56));
    v116 = *(_DWORD *)(v76 + 56);
    do
    {
      result = v116;
      __dmb(0xBu);
      do
        v117 = __ldrex(v115);
      while ( v117 == v116 && __strex(v116 & 0xFFFFFF, v115) );
      v116 = v117;
      __dmb(0xBu);
    }
    while ( v117 != result );
    v118 = HIBYTE(v117);
    v77 = v174;
    v13 = v181;
    if ( v174 >= 0 && v118 != 8 && v177 )
      KeBugCheck2(160, 1794, a2, v118, v181, 0);
    *(_BYTE *)(v76 + 41) = 0;
  }
  else
  {
    v77 = v174;
  }
  if ( v196 )
    goto LABEL_81;
LABEL_88:
  if ( v184 )
  {
    v169 = *(unsigned __int8 *)(v13 + 1053);
    v170 = *(_DWORD *)(v13 + 2360) + 132;
    __dmb(0xBu);
    result = 1 << (v169 & 7);
    v171 = (unsigned __int8 *)(v170 + (v169 >> 3));
    do
      v172 = __ldrex(v171);
    while ( __strex(v172 & ~(_BYTE)result, v171) );
    __dmb(0xBu);
    *(_DWORD *)(v76 + 32) = -1;
    *(_DWORD *)(v76 + 36) = -1;
  }
  if ( v180 != 3 )
  {
LABEL_164:
    v83 = 1;
    goto LABEL_91;
  }
  v83 = 0;
LABEL_91:
  v84 = 0;
  v176 = v83;
  v179 = 0;
  if ( PpmPlatformStates )
  {
    result = 992;
    if ( v83 )
    {
      for ( i = 0; i < *(_DWORD *)(v7 + 240); ++*(_DWORD *)(*(_DWORD *)(PpmPlatformStates + 32) + 992 * v121 + 24) )
        v121 = *(_DWORD *)(*(_DWORD *)(v7 + 248) + 4 * i++);
    }
    v85 = *(_DWORD *)PpmPlatformStates;
    if ( *(_DWORD *)PpmPlatformStates )
    {
      v86 = (v85 << 8) - 256;
      v87 = 992 * v85 - 992;
      v191 = -2147483647;
      v88 = v85 - 1;
      do
      {
        v89 = v86 + PpmPlatformStates;
        if ( ((*(_DWORD *)(v86 + PpmPlatformStates + 172) >> *(_DWORD *)(v181 + 20)) & 1) != 0 )
        {
          v201[0] = 0;
          v201[1] = 0;
          v202 = 0;
          v205 = 0;
          v206 = 1;
          v207 = 0;
          v203 = MEMORY[0x6824F4];
          v204 = 0;
          v90 = (unsigned int *)(v89 + 188);
          v91 = *(_DWORD *)(v89 + 188);
          v202 = PopCoordinatedIdleExitTimeout;
          if ( v91 )
          {
            do
            {
              if ( (v91 & 0x40000000) != 0 )
              {
                v145 = v91 & 0xA0003FFF | ((*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) & 0x3FFF | 0x8000) << 14);
                __dmb(0xBu);
                do
                  v146 = __ldrex(v90);
                while ( v146 == v91 && __strex(v145, v90) );
                __dmb(0xBu);
                if ( v146 == v91 )
                {
                  v147 = (v91 & 0x3FFF) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
LABEL_232:
                  v148 = *(_DWORD *)(v7 + 248);
                  v149 = v179;
                  v184 = v147;
                  *(_DWORD *)(v148 + 4 * v179) = v88;
                  v84 = v149 + 1;
                  v179 = v84;
                  if ( v84 != 1 || !*(_BYTE *)(v89 + 157) )
                  {
                    v151 = v176;
                    goto LABEL_237;
                  }
                  v150 = *(unsigned __int8 *)(v89 + 156);
                  v188 = v88;
                  if ( v150 )
                  {
                    KdCallPowerHandlers(1);
                    KdPowerTransition(v191, v173);
                    v147 = v184;
                  }
                  v151 = v176;
                  if ( (PopSimulate & 0x100) != 0 && v174 >= 0 )
                  {
                    if ( v176 )
                    {
                      if ( v195 && v88 == PpmDripsStateIndex )
                        KeBugCheckEx(160, 599, v88);
                      goto LABEL_237;
                    }
LABEL_238:
                    v152 = v87 + *(_DWORD *)(PpmPlatformStates + 32);
                    v153 = *(_QWORD *)(v89 + 192);
                    if ( v183 > HIDWORD(v153) )
                    {
                      v154 = v192[0];
                      goto LABEL_241;
                    }
                    if ( v183 < HIDWORD(v153) || (v154 = v192[0], v192[0] < (unsigned int)v153) )
                    {
                      v155 = 0;
                      v156 = 0;
                    }
                    else
                    {
LABEL_241:
                      v156 = (__PAIR64__(v183, v154) - v153) >> 32;
                      v155 = v154 - v153;
                      *(_QWORD *)(v152 + 56) += __PAIR64__(v156, v155);
                    }
                    if ( v174 >= 0 || !v147 )
                    {
                      v157 = *(_DWORD *)(v152 + 32) + 1;
                      *(_DWORD *)(v152 + 32) = v157;
                      PpmUpdatePlatformIdleAccounting(v152 + 24, v157, v155, v156);
                      result = 992;
                      goto LABEL_98;
                    }
                    ++*(_DWORD *)(v152 + 28);
                  }
                  else
                  {
LABEL_237:
                    if ( !v151 )
                      goto LABEL_238;
                  }
                  result = 992;
                  goto LABEL_98;
                }
                v91 = v146;
              }
              else
              {
                if ( (v91 & 0x30000000) == 0x10000000
                  && (v91 & 0x3FFF) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) )
                {
                  __dmb(0xBu);
                  *v90 = v91 & 0xE0003FFF | ((v91 & 0x3FFF | 0x8000) << 14);
                  v147 = 1;
                  goto LABEL_232;
                }
                PpmIdleTransitionStall(v201);
                v91 = *v90;
              }
            }
            while ( v91 );
            result = 992;
          }
          v84 = v179;
        }
LABEL_98:
        --v85;
        --v88;
        v87 -= 992;
        v86 -= 256;
      }
      while ( v85 );
    }
    if ( v84 && *(_BYTE *)(PpmPlatformStates + 12) && (dword_682608 & 0x8000) != 0 )
    {
      v220[0] = *(_DWORD *)(v7 + 248);
      v220[1] = 0;
      v220[2] = 4 * v84;
      v220[3] = 0;
      result = EtwTraceKernelEvent(v220, 1, 1073774592, 4672, 1538);
    }
  }
  v92 = v180;
  *(_DWORD *)(v7 + 240) = v84;
  if ( v92 == 3 )
  {
    result = (*(int (__fastcall **)(int, int, int, int, _DWORD))(v7 + 104))(v189, a2, v188, v84, *(_DWORD *)(v7 + 248));
  }
  else if ( !*(_BYTE *)v7 )
  {
    result = (*(int (__fastcall **)(int, int))(v7 + 108))(v189, v180);
  }
  v93 = *(_DWORD *)(v7 + 240);
  if ( v93 )
  {
    result = *(_DWORD *)(v7 + 248) + 4 * v93;
    do
    {
      v143 = *(_DWORD *)(result - 4);
      result -= 4;
      v144 = PpmPlatformStates + (v143 << 8);
      __dmb(0xBu);
      *(_DWORD *)(v144 + 188) = 0;
      --v93;
    }
    while ( v93 );
  }
  if ( v194 )
  {
    __dmb(0xBu);
    do
      v114 = __ldrex((unsigned int *)&PpmNonInterruptibleCount);
    while ( __strex(v114 - 1, (unsigned int *)&PpmNonInterruptibleCount) );
  }
  v211[0] = 1;
  v211[1] = 1;
  v212 = 0;
  v213 = 0;
  v94 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  v95 = *(_DWORD *)(v7 + 76);
  while ( v95 )
  {
    v128 = __clz(__rbit(v95));
    v95 &= ~(1 << v128);
    v186 = v128;
    if ( v128 >= KeNumberProcessors_0 )
      v129 = 0;
    else
      v129 = (int)*(&KiProcessorBlock + v128);
    v130 = (int *)(v129 + 2944);
    v131 = *v130;
    if ( PpmIdleUnlockProcessor(v130 + 14) == 6 )
      v213 |= 1 << v186;
    __dmb(0xBu);
    result = ~(1 << v94);
    v132 = (unsigned int *)(v131 + 64);
    do
      v133 = __ldrex(v132);
    while ( __strex(v133 & result, v132) );
    __dmb(0xBu);
    *(_DWORD *)(v7 + 76) &= ~(1 << v186);
  }
  v97 = v180;
  v96 = v181;
  if ( v213 )
    result = HalRequestIpi(0, v211);
  if ( *(_BYTE *)(v7 + 3) )
    result = PpmIdleCompleteExitLatencyTrace(v96, v174, v177);
  *(_DWORD *)(v7 + 48) = v174;
  *(_DWORD *)(v7 + 52) = v97;
  return result;
}
