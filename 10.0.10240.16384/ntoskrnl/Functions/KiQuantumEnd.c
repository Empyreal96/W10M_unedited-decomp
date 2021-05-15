// KiQuantumEnd 
 
int KiQuantumEnd()
{
  int v0; // r10
  unsigned int v1; // r3
  int v2; // r7
  int v3; // r6
  int v4; // r2
  unsigned __int64 *v5; // r1
  __int64 v6; // r4
  unsigned __int64 v7; // kr18_8
  int v8; // r8
  int v9; // r3
  int v10; // r5
  _DWORD *v11; // r4
  unsigned int *v12; // r1
  int result; // r0
  unsigned int v14; // r2
  int v15; // r8
  unsigned int *v16; // r8
  unsigned int v17; // r2
  unsigned __int64 v18; // r2
  int v19; // r8
  unsigned int v20; // r3
  unsigned int *v21; // r10
  unsigned int v22; // r2
  int v23; // r3
  int v24; // r3
  int v25; // r8
  unsigned __int64 v26; // kr20_8
  char v27; // r2
  __int64 v28; // r0
  unsigned __int64 *v29; // r5
  __int64 v30; // kr28_8
  unsigned __int64 v31; // kr30_8
  unsigned __int64 v32; // kr38_8
  __int64 v33; // r2
  char v34; // r5
  int v35; // r4
  unsigned __int64 *v36; // r4
  unsigned __int64 v37; // kr40_8
  unsigned __int64 v38; // kr48_8
  char v39; // r2
  int v40; // r2
  int v41; // r1
  unsigned __int8 *v42; // r3
  unsigned int v43; // r2
  int v44; // r1
  int i; // r1
  int v46; // r1
  int v47; // r0
  int v48; // r3
  unsigned __int8 v49; // lr
  unsigned int v50; // r2
  int v51; // r2
  unsigned int v52; // r9
  unsigned int v53; // r2
  int v54; // r3
  _DWORD *v55; // r2
  _DWORD *v56; // r1
  _DWORD *v57; // lr
  int v58; // r3
  int v59; // r3
  int v60; // lr
  char v61; // r3
  int v62; // r2
  int v63; // r1
  int v64; // lr
  int v65; // r2
  int v66; // r8
  unsigned int v67; // r2
  int v68; // r5
  _DWORD *v69; // r2
  _DWORD *v70; // r1
  _DWORD *v71; // lr
  int v72; // r3
  int *v73; // lr
  int v74; // r3
  unsigned int v75; // r5
  int v76; // r2
  int v77; // r1
  unsigned int *v78; // r8
  _DWORD *v79; // r1
  unsigned int v80; // r2
  int v81; // r2
  int v82; // r1
  signed int v83; // r3
  __int64 v84; // kr50_8
  _DWORD *v85; // r3
  int v86; // r3
  int v87; // r4
  int v88; // r4
  int v89; // r3
  _DWORD *v90; // r8
  int v91; // r9
  unsigned __int64 *v92; // r1
  int v93; // r0
  int v94; // lr
  unsigned __int64 v95; // kr60_8
  unsigned int *v96; // r1
  unsigned int v97; // r2
  int v98; // r2
  unsigned __int64 v99; // kr68_8
  int v100; // r0
  int v101; // lr
  int v102; // r2
  int v103; // r3
  unsigned int v104; // r1
  int v105; // r4
  unsigned int v106; // r3
  bool v107; // cf
  unsigned int v108; // r1
  int v109; // r3
  int v110; // r0
  int v111; // r2
  __int64 v112; // kr78_8
  _DWORD *v113; // r3
  int v114; // r3
  int v115; // r9
  int v116; // r9
  int v117; // r3
  int v118; // r0
  int v119; // lr
  unsigned __int64 *v120; // r1
  int v121; // lr
  int v122; // r9
  unsigned __int64 v123; // kr88_8
  unsigned int *v124; // r1
  unsigned int v125; // r2
  int v126; // r2
  int v127; // r1
  int v128; // lr
  unsigned __int64 v129; // kr90_8
  int v130; // r2
  int v131; // r3
  unsigned int *v132; // r1
  unsigned int v133; // r2
  unsigned int v134; // r2
  int v135; // r3
  unsigned __int8 *v136; // r3
  unsigned int v137; // r2
  int v138; // r0
  _DWORD *v139; // r1
  _DWORD *v140; // r3
  unsigned __int8 *v141; // r3
  unsigned int v142; // r2
  char v143; // r2
  int v144; // r2
  int v145; // r1
  char v146; // r3
  int v147; // [sp+8h] [bp-60h] BYREF
  int v148; // [sp+Ch] [bp-5Ch]
  int v149; // [sp+10h] [bp-58h]
  int v150; // [sp+14h] [bp-54h]
  int v151; // [sp+18h] [bp-50h] BYREF
  int v152; // [sp+1Ch] [bp-4Ch]
  int v153; // [sp+20h] [bp-48h] BYREF
  int v154; // [sp+24h] [bp-44h]
  int v155; // [sp+28h] [bp-40h]
  _DWORD *v156; // [sp+2Ch] [bp-3Ch]
  int v157; // [sp+30h] [bp-38h]
  int v158; // [sp+34h] [bp-34h]
  int v159; // [sp+38h] [bp-30h]
  int v160; // [sp+40h] [bp-28h]
  int v161; // [sp+44h] [bp-24h]

  v0 = 0;
  v152 = 0;
  v1 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v2 = v1 + 1408;
  v3 = *(_DWORD *)(v1 + 1412);
  v4 = *(_DWORD *)(v1 + 1420);
  v154 = v3;
  if ( v3 != v4 )
  {
    v5 = (unsigned __int64 *)(v3 + 48);
    while ( 1 )
    {
      LODWORD(v6) = *(_DWORD *)(v3 + 52);
      HIDWORD(v6) = *(_DWORD *)v5;
      do
        v7 = __ldrexd(v5);
      while ( __PAIR64__(v7, HIDWORD(v7)) == v6 && __strexd(__PAIR64__(v6, HIDWORD(v6)), v5) );
      if ( v6 == __PAIR64__(v7, HIDWORD(v7)) )
        break;
      __dmb(0xAu);
      __yield();
    }
    if ( __PAIR64__(v6, HIDWORD(v6)) >= *(_QWORD *)(v3 + 24) || *(_BYTE *)(v3 + 85) )
    {
      v16 = (unsigned int *)(v3 + 44);
      while ( 1 )
      {
        do
          v17 = __ldrex(v16);
        while ( __strex(1u, v16) );
        __dmb(0xBu);
        if ( !v17 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v16 );
      }
      v18 = *(_QWORD *)(v3 + 24);
      if ( __PAIR64__(v6, HIDWORD(v6)) >= v18 )
      {
        if ( (*(_DWORD *)(v3 + 80) & 0x80) != 0 )
          return sub_52B6A0(15, 1, v18);
        v19 = *(char *)(v3 + 123);
        if ( v19 < 16 )
        {
          v19 = (char)(-(*(_BYTE *)(v3 + 348) & 0xF) - (*(_BYTE *)(v3 + 348) >> 4) + v19 - 1);
          if ( v19 < *(char *)(v3 + 347) )
            v19 = *(char *)(v3 + 347);
          if ( *(_BYTE *)(v3 + 348) )
          {
            if ( (*(_BYTE *)(v3 + 348) & 0xF) != 0 )
              *(_DWORD *)(v3 + 812) = KeTickCount;
            *(_BYTE *)(v3 + 348) = 0;
          }
          v20 = *(_DWORD *)(v3 + 800);
          if ( v20 )
          {
            v83 = 31 - __clz(v20);
            if ( v19 < v83 )
              v19 = (char)v83;
          }
        }
        v21 = (unsigned int *)(v2 + 24);
        while ( 1 )
        {
          do
            v22 = __ldrex(v21);
          while ( __strex(1u, v21) );
          __dmb(0xBu);
          if ( !v22 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v21 );
        }
        v151 = *(_DWORD *)(v2 + 8) == 0;
        KiAbProcessThreadPriorityModification(v3, v19, 1);
        v23 = v151;
        *(_BYTE *)(v3 + 123) = v19;
        if ( v23 )
        {
          if ( (*(_BYTE *)(v3 + 2) & 4) != 0 )
          {
            if ( v19 < 16
              && *(_DWORD *)(v3 + 68)
              && (v40 = *(_DWORD *)(v3 + 68)) != 0
              && (v41 = *(_DWORD *)(v2 + 2352) + v40) != 0
              && KiGetThreadEffectiveRankNonZero(v3, v41, 0) )
            {
              LOBYTE(v19) = 1;
            }
            else
            {
              LOBYTE(v19) = *(_BYTE *)(v3 + 123);
            }
          }
          **(_BYTE **)(v2 + 28) = v19;
        }
        __dmb(0xBu);
        *v21 = 0;
        v24 = *(_DWORD *)(v3 + 336);
        v25 = *(unsigned __int8 *)(v3 + 403);
        v0 = 1;
        v152 = 1;
        if ( *(_BYTE *)(v24 + 606) == 2 && *(char *)(v3 + 123) < 16 && (*(_DWORD *)(v3 + 80) & 2) == 0 )
          KiScheduleNextForegroundBoost(v3);
        v26 = __PAIR64__(v6, KiCyclesPerClockQuantum * v25) + HIDWORD(v6);
        if ( (*(_DWORD *)(v3 + 80) & 0x10) != 0 )
        {
          __dmb(0xBu);
          v42 = (unsigned __int8 *)(v3 + 80);
          do
            v43 = __ldrex(v42);
          while ( __strex(v43 & 0xEF, v42) );
          __dmb(0xBu);
        }
        *(_QWORD *)(v3 + 24) = v26;
        if ( *(_DWORD *)(v2 + 1048) != *(_DWORD *)(v2 + 3468) )
        {
          v134 = *(unsigned __int8 *)(v3 + 76);
          *(_BYTE *)(v3 + 76) = v134 & 0x7F;
          if ( !(v134 >> 7)
            && ((*(_DWORD *)(v2 + 1048) | *(_DWORD *)(*(_DWORD *)(v2 + 2360) + 8)) & *(_DWORD *)(v2 + 3468)) != *(_DWORD *)(v2 + 3468) )
          {
            v135 = *((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)(v3 + 364)) + 590);
            if ( (*(_DWORD *)(v3 + 356) & *(_DWORD *)(v135 + 136) & *(_DWORD *)(v135 + 4)) != 0 )
            {
              *(_DWORD *)(v3 + 76) |= 0x80u;
              v136 = (unsigned __int8 *)(v3 + 81);
              do
                v137 = __ldrex(v136);
              while ( __strex(v137 | 8, v136) );
            }
          }
        }
        v16 = (unsigned int *)(v3 + 44);
      }
      if ( *(_BYTE *)(v3 + 85) )
      {
        if ( (v138 = KiGetHeteroCpuPolicyThread(v3, v2),
              KiGenerateHeteroSets(*(_DWORD *)(v2 + 2360), *(_DWORD *)(v3 + 356), v138, &v153, &v151),
              (*(_DWORD *)(v2 + 1048) & v153) == 0)
          && ((v139 = (_DWORD *)*((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)(v3 + 364)) + 590), (*v139 & v153) != 0)
           || (v140 = *(_DWORD **)(v2 + 2360), v140 != v139) && (*v140 & v153) != 0)
          || (*(_DWORD *)(v2 + 1048) & v151) == 0 )
        {
          v141 = (unsigned __int8 *)(v3 + 81);
          do
            v142 = __ldrex(v141);
          while ( __strex(v142 | 8, v141) );
        }
      }
      __dmb(0xBu);
      *v16 = 0;
    }
  }
  v8 = KeTickCount;
  v9 = *(_DWORD *)(v2 + 1772);
  v10 = 0;
  v159 = KeTickCount;
  if ( v9 - KeTickCount < 0 )
  {
    v10 = 1;
    v158 = 1;
    if ( KiShouldScanSharedReadyQueue(v2) )
    {
      v47 = *(_DWORD *)(v2 + 3460);
      v48 = *(_DWORD *)(v47 + 4);
      v160 = v47;
      if ( (v48 & v46) != 0 )
      {
        v49 = *(_BYTE *)(v47 + 298);
        v157 = v49;
        while ( 1 )
        {
          do
            v50 = __ldrex((unsigned int *)v47);
          while ( __strex(1u, (unsigned int *)v47) );
          __dmb(0xBu);
          if ( !v50 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *(_DWORD *)v47 );
        }
        v51 = *(_DWORD *)(v47 + 4) & v46;
        if ( !v51 )
        {
          __dmb(0xBu);
          *(_DWORD *)v47 = 0;
          *(_BYTE *)(v47 + 298) = 1;
          goto LABEL_10;
        }
        v148 = 0;
        v147 = 10;
        v151 = 16;
        v52 = __ROR4__(v51, v49);
        v149 = KeTickCount - 300;
        while ( 1 )
        {
          v53 = __clz(__rbit(v52));
          v52 ^= 1 << v53;
          v155 = v53;
          v54 = ((_BYTE)v53 + v49) & 0x1F;
          v55 = (_DWORD *)(v47 + 8 + 8 * v54);
          v56 = (_DWORD *)*v55;
          v156 = v55;
          v153 = v54;
          do
          {
            v57 = v56 - 36;
            v58 = v56[40];
            v56 = (_DWORD *)*v56;
            if ( v149 - v58 > 0 )
            {
              v84 = *((_QWORD *)v57 + 18);
              v150 = v57[37];
              v85 = *(_DWORD **)(v84 + 4);
              v155 = v84;
              if ( v85 != v57 + 36 || *(_DWORD **)v150 != v57 + 36 )
                __fastfail(3u);
              v86 = v150;
              v87 = v155;
              *(_DWORD *)v150 = v155;
              *(_DWORD *)(v87 + 4) = v86;
              if ( v86 == v87 )
              {
                v55 = v156;
                *(_DWORD *)(v47 + 4) ^= 1 << v153;
              }
              *((_BYTE *)v57 + 132) = 7;
              v88 = v148;
              v148 = (int)(v57 + 36);
              v89 = v147;
              v57[36] = v88;
              v59 = v89 - 1;
              v147 = v59;
            }
            else
            {
              v59 = v147;
            }
            v60 = --v151;
          }
          while ( v56 != v55 && v60 && v59 );
          if ( !v52 || !v59 || !v60 )
            break;
          v49 = v157;
        }
        __dmb(0xBu);
        *(_DWORD *)v47 = 0;
        if ( !v148 )
        {
LABEL_111:
          if ( v60 && v147 || (v61 = v153 + 1, (unsigned int)(v153 + 1) > 0xE) )
            v61 = 1;
          *(_BYTE *)(v47 + 298) = v61;
          goto LABEL_10;
        }
        v90 = (_DWORD *)v148;
        while ( 1 )
        {
          v91 = (int)(v90 - 36);
          v90 = (_DWORD *)*v90;
          v148 = 0;
          v92 = (unsigned __int64 *)(v91 + 48);
          while ( 1 )
          {
            v93 = *(_DWORD *)(v91 + 52);
            v94 = *(_DWORD *)v92;
            v150 = *(_DWORD *)v92;
            v157 = v93;
            do
              v95 = __ldrexd(v92);
            while ( __PAIR64__(v95, HIDWORD(v95)) == __PAIR64__(v94, v93) && __strexd(__PAIR64__(v93, v94), v92) );
            if ( __PAIR64__(v94, v93) == __PAIR64__(v95, HIDWORD(v95)) )
              break;
            __dmb(0xAu);
            __yield();
          }
          v96 = (unsigned int *)(v91 + 44);
          while ( 1 )
          {
            do
              v97 = __ldrex(v96);
            while ( __strex(1u, v96) );
            __dmb(0xBu);
            if ( !v97 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v96 );
          }
          v98 = *(char *)(v91 + 123);
          v149 = v98;
          if ( v98 >= 15 )
            goto LABEL_181;
          v148 = 1;
          *(_BYTE *)(v91 + 348) += 16 * (15 - v98);
          KiAbProcessThreadPriorityModification(v91, 15, 1);
          v99 = *(_QWORD *)(v91 + 24);
          v100 = v157;
          v101 = v150;
          *(_BYTE *)(v91 + 123) = 15;
          if ( __PAIR64__(v100, v101) > v99 )
            break;
          v102 = KiLockQuantumTarget;
          if ( v99 - __PAIR64__(v100, v101) < (unsigned int)KiLockQuantumTarget )
            goto LABEL_247;
LABEL_180:
          v98 = v149;
LABEL_181:
          __dmb(0xBu);
          v103 = v148;
          *(_DWORD *)(v91 + 44) = 0;
          if ( v103 && (dword_682608 & 1) != 0 )
            EtwTraceAntiStarvationBoost(v91, v98);
          KiDeferredReadyThread(v2, v91);
          if ( !v90 )
          {
            v3 = v154;
            v10 = v158;
            v8 = v159;
            v60 = v151;
            v0 = v152;
            v47 = v160;
            goto LABEL_111;
          }
        }
        v102 = KiLockQuantumTarget;
LABEL_247:
        *(_QWORD *)(v91 + 24) = __PAIR64__(v100, v102) + (unsigned int)v101;
        goto LABEL_180;
      }
    }
  }
LABEL_10:
  v11 = 0;
  v147 = 0;
  if ( KiGroupSchedulingEnabled )
  {
    result = KiGroupSchedulingQuantumEnd(v2, v3, v0, &v147);
    v11 = (_DWORD *)v147;
  }
  else
  {
    v12 = (unsigned int *)(v2 + 24);
    result = 1;
    while ( 1 )
    {
      do
        v14 = __ldrex(v12);
      while ( __strex(1u, v12) );
      __dmb(0xBu);
      if ( !v14 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v12 );
    }
  }
  if ( v10 )
  {
    v62 = *(_DWORD *)(v2 + 1932);
    *(_DWORD *)(v2 + 1772) = v8 + 75;
    if ( (v62 & 0x7FFE) != 0 )
    {
      v63 = *(_DWORD *)(v2 + 1940);
      v64 = v2 + 2048;
      v65 = v62 & 0x7FFE;
      v157 = v63;
      if ( !v65 )
      {
LABEL_128:
        v75 = 1;
LABEL_129:
        *(_DWORD *)(v2 + 1940) = v75;
        goto LABEL_15;
      }
      v148 = 0;
      v150 = 10;
      v66 = 16;
      result = __ROR4__(v65, v63);
      v160 = KeTickCount - 300;
      while ( 1 )
      {
        v67 = __clz(__rbit(result));
        result ^= 1 << v67;
        v68 = (v67 + v63) & 0x1F;
        v159 = v67;
        v69 = (_DWORD *)(v64 + 8 * v68);
        v70 = (_DWORD *)*v69;
        v158 = (int)v69;
        v156 = (_DWORD *)v68;
        do
        {
          v71 = v70 - 36;
          v72 = v70[40];
          v70 = (_DWORD *)*v70;
          if ( v160 - v72 > 0 )
          {
            v112 = *((_QWORD *)v71 + 18);
            v153 = v71[37];
            v113 = *(_DWORD **)(v112 + 4);
            v159 = v112;
            if ( v113 != v71 + 36 || *(_DWORD **)v153 != v71 + 36 )
              __fastfail(3u);
            v114 = v153;
            v115 = v159;
            *(_DWORD *)v153 = v159;
            *(_DWORD *)(v115 + 4) = v114;
            if ( v114 == v115 )
            {
              v69 = (_DWORD *)v158;
              *(_DWORD *)(v2 + 1932) ^= 1 << v68;
            }
            v116 = v148;
            *((_BYTE *)v71 + 132) = 7;
            v117 = v150;
            v71[36] = v116;
            v73 = v71 + 36;
            v74 = v117 - 1;
            v150 = v74;
            v148 = (int)v73;
          }
          else
          {
            v73 = (int *)v148;
            v74 = v150;
          }
          v159 = --v66;
        }
        while ( v70 != v69 && v66 && v74 );
        if ( !result || !v74 || !v66 )
          break;
        v63 = v157;
        v64 = v2 + 2048;
      }
      if ( !v73 )
      {
LABEL_126:
        if ( !v66 || !v74 )
        {
          v75 = v68 + 1;
          if ( v75 <= 0xE )
            goto LABEL_129;
        }
        goto LABEL_128;
      }
      __dmb(0xBu);
      *(_DWORD *)(v2 + 24) = 0;
      while ( 1 )
      {
        v118 = (int)(v73 - 36);
        v119 = *v73;
        v152 = v118;
        v153 = 0;
        v148 = v119;
        v120 = (unsigned __int64 *)(v118 + 48);
        while ( 1 )
        {
          v121 = *(_DWORD *)(v118 + 52);
          v149 = *(_DWORD *)v120;
          v160 = v121;
          v122 = v149;
          do
            v123 = __ldrexd(v120);
          while ( __PAIR64__(v123, HIDWORD(v123)) == __PAIR64__(v122, v121) && __strexd(__PAIR64__(v121, v122), v120) );
          if ( __PAIR64__(v122, v121) == __PAIR64__(v123, HIDWORD(v123)) )
            break;
          __dmb(0xAu);
          __yield();
        }
        v124 = (unsigned int *)(v118 + 44);
        while ( 1 )
        {
          do
            v125 = __ldrex(v124);
          while ( __strex(1u, v124) );
          __dmb(0xBu);
          if ( !v125 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v124 );
        }
        v126 = *(char *)(v118 + 123);
        v151 = v126;
        if ( v126 >= 15 )
          goto LABEL_209;
        v153 = 1;
        *(_BYTE *)(v118 + 348) += 16 * (15 - v126);
        KiAbProcessThreadPriorityModification(v118, 15, 1);
        v118 = v152;
        v127 = v160;
        v128 = v149;
        v129 = *(_QWORD *)(v152 + 24);
        *(_BYTE *)(v152 + 123) = 15;
        if ( __PAIR64__(v127, v128) > v129 )
          break;
        v160 = v129 - v128;
        v130 = KiLockQuantumTarget;
        if ( v129 - __PAIR64__(v127, v128) < (unsigned int)KiLockQuantumTarget )
          goto LABEL_253;
LABEL_208:
        v126 = v151;
LABEL_209:
        __dmb(0xBu);
        v131 = v153;
        *(_DWORD *)(v118 + 44) = 0;
        if ( v131 && (dword_682608 & 1) != 0 )
        {
          EtwTraceAntiStarvationBoost(v118, v126);
          v118 = v152;
        }
        KiDeferredReadyThread(v2, v118);
        v73 = (int *)v148;
        if ( !v148 )
        {
          v3 = v154;
          v68 = (int)v156;
          v66 = v159;
          v132 = (unsigned int *)(v2 + 24);
          while ( 1 )
          {
            result = 1;
            do
              v133 = __ldrex(v132);
            while ( __strex(1u, v132) );
            __dmb(0xBu);
            if ( !v133 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v132 );
          }
          v74 = v150;
          goto LABEL_126;
        }
      }
      v130 = KiLockQuantumTarget;
LABEL_253:
      *(_QWORD *)(v118 + 24) = __PAIR64__(v127, v130) + (unsigned int)v128;
      goto LABEL_208;
    }
  }
  while ( 1 )
  {
LABEL_15:
    v15 = *(_DWORD *)(v2 + 8);
    if ( v15 )
    {
      if ( v0 )
        *(_BYTE *)(v3 + 349) = 0;
      goto LABEL_87;
    }
    if ( !v0 || (result = KiSelectReadyThread(*(char *)(v3 + 123), v2), (v15 = result) == 0) )
    {
      if ( (*(_DWORD *)(v3 + 80) & 0x800) == 0 )
        goto LABEL_18;
      result = KiSelectNextThread(v2, &v147);
      v15 = *(_DWORD *)(v2 + 8);
      v11 = (_DWORD *)v147;
LABEL_87:
      if ( !v15 )
        goto LABEL_18;
    }
    if ( v15 != *(_DWORD *)(v2 + 12) )
    {
      v161 = MEMORY[0x681FE4];
      if ( *(_DWORD *)(v15 + 352) != KiCpuSetSequence && (*(_DWORD *)(v15 + 76) & 8) == 0 )
      {
        if ( (*(_BYTE *)(v3 + 2) & 4) != 0 )
        {
          if ( *(char *)(v3 + 123) < 16
            && *(_DWORD *)(v3 + 68)
            && (v81 = *(_DWORD *)(v3 + 68)) != 0
            && (v82 = v81 + *(_DWORD *)(v2 + 2352)) != 0
            && (result = KiGetThreadEffectiveRankNonZero(v3, v82, 0)) != 0 )
          {
            v27 = 1;
          }
          else
          {
            v27 = *(_BYTE *)(v3 + 123);
          }
        }
        else
        {
          v27 = *(_BYTE *)(v3 + 123);
        }
        **(_BYTE **)(v2 + 28) = v27;
        if ( *(_DWORD *)(v2 + 8) == v15 )
        {
          result = KiSelectNextThread(v2, &v147);
          v11 = (_DWORD *)v147;
        }
        *(_BYTE *)(v15 + 132) = 7;
        *(_DWORD *)(v15 + 144) = v11;
        v11 = (_DWORD *)(v15 + 144);
        v15 = 0;
      }
    }
LABEL_18:
    if ( !v11 )
      break;
    if ( v15 && v15 != *(_DWORD *)(v2 + 12) && *(_DWORD *)(v2 + 8) != v15 )
    {
      if ( (*(_BYTE *)(v15 + 2) & 4) != 0 )
      {
        if ( *(char *)(v15 + 123) < 16
          && *(_DWORD *)(v15 + 68)
          && (v144 = *(_DWORD *)(v15 + 68)) != 0
          && (v145 = v144 + *(_DWORD *)(v2 + 2352)) != 0
          && KiGetThreadEffectiveRankNonZero(v15, v145, 0) )
        {
          v146 = 1;
        }
        else
        {
          v146 = *(_BYTE *)(v15 + 123);
        }
        v143 = v146;
      }
      else
      {
        v143 = *(_BYTE *)(v15 + 123);
      }
      **(_BYTE **)(v2 + 28) = v143;
      *(_DWORD *)(v2 + 8) = v15;
      *(_BYTE *)(v15 + 132) = 3;
    }
    __dmb(0xBu);
    v78 = (unsigned int *)(v2 + 24);
    *(_DWORD *)(v2 + 24) = 0;
    do
    {
      v79 = v11 - 36;
      v11 = (_DWORD *)*v11;
      result = KiDeferredReadyThread(v2, v79);
    }
    while ( v11 );
    v11 = 0;
    v147 = 0;
    while ( 1 )
    {
      do
        v80 = __ldrex(v78);
      while ( __strex(1u, v78) );
      __dmb(0xBu);
      if ( !v80 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v78 );
    }
  }
  if ( !v15 || v3 == *(_DWORD *)(v2 + 12) )
  {
    __dmb(0xBu);
    *(_DWORD *)(v2 + 24) = 0;
  }
  else
  {
    *(_DWORD *)(v2 + 8) = 0;
    __disable_irq();
    *(_BYTE *)(v2 + 16) = 1;
    LODWORD(v28) = ReadTimeStampCounter();
    v29 = (unsigned __int64 *)(v3 + 48);
    v30 = v28 - *(_QWORD *)(v2 + 2376);
    v31 = v30 + *(_QWORD *)(v3 + 48);
    __dmb(0xBu);
    do
      v32 = __ldrexd(v29);
    while ( __strexd(v31, v29) );
    __dmb(0xBu);
    v33 = v30 + *(unsigned int *)(v3 + 56);
    if ( HIDWORD(v33) )
    {
      v161 = 0;
      LODWORD(v33) = -1;
    }
    *(_QWORD *)(v2 + 2376) = v28;
    v34 = *(_BYTE *)(v3 + 2);
    *(_DWORD *)(v3 + 56) = v33;
    if ( (v34 & 0x3E) != 0 )
    {
      if ( (v34 & 0x10) != 0 )
      {
        v104 = *(_DWORD *)(v2 + 2376);
        v105 = v2 + 8 * *(unsigned __int8 *)(v3 + 84);
        v106 = *(_DWORD *)(v2 + 2384);
        v34 &= 0xEFu;
        v107 = v104 >= v106;
        v108 = v104 - v106;
        v109 = *(_DWORD *)(v105 + 2392);
        v110 = *(_DWORD *)(v2 + 2380) - (*(_DWORD *)(v2 + 2388) + !v107);
        v111 = *(_DWORD *)(v105 + 2396);
        *(_DWORD *)(v105 + 2392) = v109 + v108;
        *(_DWORD *)(v105 + 2396) = v110 + __CFADD__(v109, v108) + v111;
        *(_DWORD *)(v2 + 2384) = 0;
        *(_DWORD *)(v2 + 2388) = 0;
      }
      if ( (v34 & 0x3E) != 0 )
      {
        if ( (v34 & 0x20) != 0 )
        {
          v35 = *(_DWORD *)(v3 + 1084);
          if ( v35 )
          {
            v36 = (unsigned __int64 *)(v35 + 8 * (*(unsigned __int8 *)(v2 + 2986) + 2 * PoGetFrequencyBucket(v2)));
            v37 = *v36 + v30;
            __dmb(0xBu);
            do
              v38 = __ldrexd(v36);
            while ( __strexd(v37, v36) );
            __dmb(0xBu);
          }
          v34 &= 0xDFu;
        }
        if ( (v34 & 0x3E) != 0 )
        {
          v44 = *(_DWORD *)(v3 + 68);
          if ( v44 )
          {
            for ( i = v44 + *(_DWORD *)(v2 + 2352); i; i = *(_DWORD *)(i + 236) )
              *(_QWORD *)i += v30;
          }
          if ( (*(_BYTE *)(v3 + 2) & 8) != 0
            && (*(_DWORD *)(*(_DWORD *)(v2 + 2360) + 260) & *(_DWORD *)(v3 + 356)) != *(_DWORD *)(*(_DWORD *)(v2 + 2360)
                                                                                                + 260) )
          {
            *(_QWORD *)(v2 + 2368) += v30;
          }
          if ( *(_DWORD *)(v3 + 236) )
            KiEndCounterAccumulation(v3);
        }
      }
    }
    __enable_irq();
    if ( (*(_BYTE *)(v15 + 2) & 4) != 0 )
    {
      if ( *(char *)(v15 + 123) < 16
        && *(_DWORD *)(v15 + 68)
        && (v76 = *(_DWORD *)(v15 + 68)) != 0
        && (v77 = *(_DWORD *)(v2 + 2352) + v76) != 0
        && KiGetThreadEffectiveRankNonZero(v15, v77, 0) )
      {
        v39 = 1;
      }
      else
      {
        v39 = *(_BYTE *)(v15 + 123);
      }
    }
    else
    {
      v39 = *(_BYTE *)(v15 + 123);
    }
    **(_BYTE **)(v2 + 28) = v39;
    *(_DWORD *)(v2 + 4) = v15;
    *(_BYTE *)(v15 + 132) = 2;
    *(_BYTE *)(v3 + 395) = 30;
    KiQueueReadyThread(v2, v3);
    KiAbProcessContextSwitch(v3, 1);
    result = KiSwapContext(v3, v15, 1);
  }
  return result;
}
