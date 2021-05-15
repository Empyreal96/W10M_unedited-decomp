// KeWaitForMultipleObjects 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeWaitForMultipleObjects(unsigned int a1, unsigned int *a2, int a3, int a4, char a5, unsigned __int8 a6, int *a7, int *a8)
{
  char v8; // r7
  int v9; // r3
  int *v10; // r5
  int v11; // r4
  char v12; // r2
  int v13; // r9
  unsigned int *v14; // r10
  unsigned int v15; // r6
  int v16; // r3
  unsigned int v17; // r3
  unsigned int v18; // r2
  int *v19; // r5
  char v20; // r8
  char v21; // r7
  int v22; // r9
  unsigned int v23; // r1
  unsigned int v24; // lr
  int *v25; // r7
  int *v26; // r0
  int v27; // r6
  int v28; // t1
  unsigned int v29; // r2
  int v30; // r3
  int **v31; // r1
  unsigned int v32; // r1
  unsigned int v33; // r0
  int v34; // r3
  int v35; // r7
  __int64 v37; // r6
  unsigned int v38; // r0
  unsigned int v39; // r1
  int v40; // r3
  unsigned int v41; // r2
  unsigned int v42; // r1
  int *v43; // r6
  unsigned __int8 *v44; // r0
  unsigned int v45; // r2
  int *v46; // r1 OVERLAPPED
  int **v47; // r2 OVERLAPPED
  unsigned int v48; // r1
  unsigned int v49; // r8
  void (__fastcall **v50)(int); // r3
  int v51; // r0
  __int64 v52; // kr20_8
  unsigned int v53; // r2
  unsigned int v54; // r1
  unsigned int v55; // r1
  unsigned int v56; // r2
  unsigned __int64 v57; // kr28_8
  unsigned int v58; // r2
  int v59; // r3
  unsigned int v60; // r2
  int v61; // r3
  char v62; // r2
  int v63; // r3
  _DWORD *v64; // r0
  int v65; // r2
  unsigned int v66; // r1
  unsigned int v67; // r3
  int v68; // r8
  int v69; // r3
  int v70; // r9
  unsigned int v71; // r2
  unsigned int v72; // r2
  unsigned int *v73; // r1
  unsigned int v74; // r2
  int v75; // r10
  __int64 v76; // r0
  unsigned int v77; // lr
  unsigned __int64 *v78; // r6
  __int64 v79; // kr38_8
  unsigned __int64 v80; // kr48_8
  unsigned __int64 v81; // r2
  char v82; // r6
  int v83; // r4
  __int64 v84; // kr50_8
  unsigned int *v85; // r1
  unsigned int v86; // r2
  int v87; // r3
  int v88; // lr
  __int64 v89; // r0
  __int64 v90; // kr58_8
  unsigned __int64 *v91; // r6
  unsigned __int64 v92; // kr60_8
  unsigned __int64 v93; // kr68_8
  __int64 v94; // r2
  int v95; // lr
  char v96; // r6
  int v97; // r4
  unsigned __int64 *v98; // r4
  unsigned __int64 v99; // kr70_8
  unsigned __int64 v100; // kr78_8
  int v101; // r1
  int v102; // r4
  unsigned int v103; // r1
  unsigned int v104; // r2
  int *v105; // r6
  unsigned __int8 *v106; // r0
  unsigned int v107; // r2
  unsigned int v108; // r2
  int *v109; // r1 OVERLAPPED
  int **v110; // r2 OVERLAPPED
  unsigned int v111; // r1
  unsigned __int8 *v112; // r3
  unsigned int v113; // r2
  unsigned int *v114; // r4
  unsigned int v115; // r2
  unsigned int v116; // r1
  int v117; // r4
  unsigned int v118; // r3
  bool v119; // cf
  int v120; // r3
  int v121; // r2
  int v122; // r2
  __int64 v123; // kr80_8
  unsigned int *v124; // r1
  unsigned int v125; // r2
  int v126; // r3
  int v127; // r10
  __int64 v128; // r0
  unsigned int v129; // lr
  unsigned __int64 *v130; // r6
  unsigned int v131; // r2
  unsigned int v132; // r3
  unsigned __int64 v133; // krA0_8
  unsigned __int64 v134; // r2
  int v135; // r4
  char v136; // r6
  unsigned int v137; // r1
  int v138; // r4
  unsigned int v139; // r3
  int v140; // r3
  int v141; // r2
  int v142; // r4
  unsigned __int64 *v143; // r4
  unsigned __int64 v144; // krA8_8
  unsigned __int64 v145; // krB0_8
  int v146; // r1
  int v147; // r4
  int v148; // r3
  unsigned int v149; // r1
  int v150; // r4
  unsigned int v151; // r3
  int v152; // r3
  int v153; // r2
  int v154; // r2
  int v155; // r4
  unsigned __int64 *v156; // r4
  unsigned __int64 v157; // krB8_8
  unsigned __int64 v158; // krC0_8
  int v159; // r1
  unsigned int v160; // [sp+10h] [bp-58h]
  int v161; // [sp+10h] [bp-58h]
  int v162; // [sp+14h] [bp-54h]
  __int64 v163; // [sp+18h] [bp-50h]
  int v165; // [sp+24h] [bp-44h]
  unsigned int v166; // [sp+24h] [bp-44h]
  unsigned int v167; // [sp+24h] [bp-44h]
  int *v168; // [sp+28h] [bp-40h] BYREF
  int v169; // [sp+2Ch] [bp-3Ch]
  int v170; // [sp+30h] [bp-38h]
  int v171; // [sp+34h] [bp-34h]
  __int64 v172; // [sp+38h] [bp-30h]

  v8 = a4;
  v170 = a4;
  LODWORD(v172) = a2;
  if ( a1 == 1 )
    return KeWaitForSingleObject(*a2, a4, a5, (_DWORD *)a6, a7);
  v9 = __mrc(15, 0, 13, 0, 3);
  v10 = a8;
  v11 = v9 & 0xFFFFFFC0;
  v168 = a8;
  if ( a8 )
  {
    if ( a1 > 0x40 )
      sub_52F9A4();
  }
  else
  {
    if ( a1 > 3 )
      KeBugCheck(12);
    v10 = (int *)(v11 + 216);
    v168 = (int *)(v11 + 216);
  }
  if ( !a3 )
    return KiWaitForAllObjects(a1, (int *)a2, v8, a5, a6, (int)a7, v10);
  v12 = *(_BYTE *)((v9 & 0xFFFFFFC0) + 0x4C);
  *(_BYTE *)((v9 & 0xFFFFFFC0) + 0x4C) = v12 & 0xFB;
  v165 = (unsigned __int8)(v12 & 4) >> 2;
  if ( !v165 )
    *(_BYTE *)((v9 & 0xFFFFFFC0) + 0x86) = KfRaiseIrql(2);
  if ( a7 )
  {
    if ( a7[1] >= 0 )
    {
      v13 = 1;
      LODWORD(v163) = *a7;
      v40 = a7[1];
    }
    else
    {
      v37 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        v38 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v39 = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v38 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
      v13 = 2;
      v40 = (__PAIR64__(v38, v39) - v37 - *(_QWORD *)a7 - *(_QWORD *)(v11 + 160)) >> 32;
      LODWORD(v163) = v39 - v37 - *a7 - *(_DWORD *)(v11 + 160);
    }
    HIDWORD(v163) = v40;
  }
  else
  {
    v13 = 0;
    v163 = v172;
  }
  v162 = v13;
  v14 = (unsigned int *)(v11 + 44);
LABEL_11:
  v15 = *(unsigned __int8 *)(v11 + 134);
  v160 = v15;
  while ( 1 )
  {
    v16 = *(_DWORD *)(v11 + 76);
    *(_BYTE *)(v11 + 72) = 0;
    *(_BYTE *)(v11 + 135) = a5;
    v17 = v16 & 0xFFFFFFEF;
    *(_DWORD *)(v11 + 76) = v17;
    if ( a6 )
      *(_DWORD *)(v11 + 76) = v17 | 0x10;
    while ( 1 )
    {
      do
        v18 = __ldrex(v14);
      while ( __strex(1u, v14) );
      __dmb(0xBu);
      if ( !v18 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v14 );
    }
    if ( !*(_BYTE *)(v11 + 121) || *(_WORD *)(v11 + 310) || v15 )
      break;
    __dmb(0xBu);
    *v14 = 0;
    KfLowerIrql(1);
    KiDeliverApc(0, 0, 0);
    KfRaiseIrql(2);
    *(_BYTE *)(v11 + 134) = 0;
  }
  v19 = v168;
  v20 = a1;
  v21 = v170;
  v22 = v162;
  if ( a6 )
  {
    if ( *(_BYTE *)(a5 + v11 + 74) )
    {
      *(_BYTE *)(a5 + v11 + 74) = 0;
      v35 = 257;
      goto LABEL_105;
    }
    if ( a5 && *(_DWORD *)(v11 + 108) != v11 + 108 )
    {
      *(_BYTE *)(v11 + 122) = 1;
LABEL_104:
      v35 = 192;
LABEL_105:
      __dmb(0xBu);
      *v14 = 0;
      v67 = (unsigned int)KeGetPcr();
      v68 = (v67 & 0xFFFFF000) + 1408;
      v69 = *(_DWORD *)((v67 & 0xFFFFF000) + 0x588);
      if ( v15 >= 2 )
      {
        if ( v69 && !*(_BYTE *)(v68 + 1754) )
          goto LABEL_108;
        return v35;
      }
      v70 = *(_DWORD *)(v68 + 4);
      if ( v69 )
      {
        KiAbProcessContextSwitch(*(_DWORD *)(v68 + 4), 0);
        v73 = (unsigned int *)(v68 + 24);
        while ( 1 )
        {
          do
            v74 = __ldrex(v73);
          while ( __strex(1u, v73) );
          __dmb(0xBu);
          if ( !v74 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v73 );
        }
        v170 = *(_DWORD *)(v68 + 8);
        *(_DWORD *)(v68 + 8) = 0;
        __disable_irq();
        *(_BYTE *)(v68 + 16) = 1;
        LODWORD(v76) = ReadTimeStampCounter();
        v75 = v76;
        v78 = (unsigned __int64 *)(v70 + 48);
        v77 = (unsigned __int64)(v76 - *(_QWORD *)(v68 + 2376)) >> 32;
        LODWORD(v76) = v76 - *(_DWORD *)(v68 + 2376);
        v79 = *(_QWORD *)(v70 + 48);
        v166 = v76;
        LODWORD(v172) = v77;
        __dmb(0xBu);
        do
          v80 = __ldrexd(v78);
        while ( __strexd(v79 + __PAIR64__(v77, v76), v78) );
        __dmb(0xBu);
        v81 = __PAIR64__(v77, *(_DWORD *)(v70 + 56)) + (unsigned int)v76;
        if ( HIDWORD(v81) )
        {
          v169 = 0;
          LODWORD(v81) = -1;
        }
        *(_DWORD *)(v68 + 2376) = v75;
        *(_DWORD *)(v68 + 2380) = HIDWORD(v76);
        v82 = *(_BYTE *)(v70 + 2);
        *(_DWORD *)(v70 + 56) = v81;
        if ( (v82 & 0x3E) != 0 )
        {
          if ( (v82 & 0x10) != 0 )
          {
            v149 = *(_DWORD *)(v68 + 2376);
            v150 = v68 + 8 * *(unsigned __int8 *)(v70 + 84);
            v151 = *(_DWORD *)(v68 + 2384);
            v82 &= 0xEFu;
            v119 = v149 >= v151;
            HIDWORD(v76) = v149 - v151;
            v152 = *(_DWORD *)(v150 + 2392);
            LODWORD(v76) = *(_DWORD *)(v68 + 2380) - (*(_DWORD *)(v68 + 2388) + !v119);
            v153 = *(_DWORD *)(v150 + 2396);
            *(_DWORD *)(v150 + 2392) = v152 + HIDWORD(v76);
            v154 = v76 + __CFADD__(v152, HIDWORD(v76)) + v153;
            LODWORD(v76) = v166;
            *(_DWORD *)(v150 + 2396) = v154;
            *(_DWORD *)(v68 + 2384) = 0;
            *(_DWORD *)(v68 + 2388) = 0;
          }
          if ( (v82 & 0x3E) != 0 )
          {
            if ( (v82 & 0x20) != 0 )
            {
              v155 = *(_DWORD *)(v70 + 1084);
              if ( v155 )
              {
                v77 = v172;
                v156 = (unsigned __int64 *)(v155 + 8
                                                 * (*(unsigned __int8 *)(v68 + 2986) + 2 * PoGetFrequencyBucket(v68)));
                v157 = __PAIR64__(v172, v166) + *v156;
                __dmb(0xBu);
                do
                  v158 = __ldrexd(v156);
                while ( __strexd(v157, v156) );
                __dmb(0xBu);
                LODWORD(v76) = v166;
              }
              v82 &= 0xDFu;
            }
            if ( (v82 & 0x3E) != 0 )
            {
              v159 = *(_DWORD *)(v70 + 68);
              if ( v159 )
              {
                for ( HIDWORD(v76) = v159 + *(_DWORD *)(v68 + 2352);
                      HIDWORD(v76);
                      HIDWORD(v76) = *(_DWORD *)(HIDWORD(v76) + 236) )
                {
                  *(_QWORD *)HIDWORD(v76) += __PAIR64__(v77, v76);
                }
              }
              if ( (*(_BYTE *)(v70 + 2) & 8) != 0
                && (*(_DWORD *)(v70 + 356) & *(_DWORD *)(*(_DWORD *)(v68 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v68 + 2360) + 260) )
              {
                *(_QWORD *)(v68 + 2368) += __PAIR64__(v77, v76);
              }
              if ( *(_DWORD *)(v70 + 236) )
                KiEndCounterAccumulation(v70);
            }
          }
        }
        v83 = v170;
        v15 = v160;
        __enable_irq();
        *(_DWORD *)(v68 + 4) = v83;
        *(_BYTE *)(v83 + 132) = 2;
        *(_BYTE *)(v70 + 395) = 32;
        *(_BYTE *)(v70 + 134) = v15;
        KiQueueReadyThread(v68, v70);
        if ( !KiSwapContext(v70, v83, v15) )
          goto LABEL_111;
      }
      else if ( (*(_DWORD *)(v70 + 76) & 0x40) == 0 )
      {
LABEL_111:
        KfLowerIrql(v15);
        return v35;
      }
      KfLowerIrql(1);
      *(_DWORD *)(v70 + 76) &= 0xFFFFFFBF;
      KiDeliverApc(0, 0, 0);
      goto LABEL_111;
    }
    if ( *(_BYTE *)(v11 + 74) )
    {
      *(_BYTE *)(v11 + 74) = 0;
      v35 = 257;
      goto LABEL_105;
    }
  }
  else if ( (*(unsigned __int8 *)(v11 + 122) & a5) != 0 )
  {
    goto LABEL_104;
  }
  *(_BYTE *)(v11 + 132) = 5;
  *(_BYTE *)(v11 + 395) = v21;
  __dmb(0xBu);
  *v14 = 0;
  *(_DWORD *)(v11 + 304) = KeTickCount;
  v23 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  v161 = v23;
  v24 = 0;
  v25 = (int *)v172;
  v26 = v19;
  while ( 1 )
  {
    v28 = *v25++;
    v27 = v28;
    *((_BYTE *)v26 + 8) = 1;
    *((_BYTE *)v26 + 9) = 4;
    *((_WORD *)v26 + 5) = v24;
    v26[3] = v11;
    v26[4] = v28;
    do
      v29 = __ldrex((unsigned __int8 *)v27);
    while ( __strex(v29 | 0x80, (unsigned __int8 *)v27) );
    __dmb(0xBu);
    if ( v29 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v27 & 0x80) != 0 );
        do
          v71 = __ldrex((unsigned __int8 *)v27);
        while ( __strex(v71 | 0x80, (unsigned __int8 *)v27) );
        __dmb(0xBu);
      }
      while ( v71 >> 7 );
    }
    v30 = *(_DWORD *)(v27 + 4);
    if ( (*(_BYTE *)v27 & 0x7F) == 2 )
      break;
    if ( v30 > 0 )
    {
      while ( 1 )
      {
        do
          v41 = __ldrex(v14);
        while ( __strex(1u, v14) );
        __dmb(0xBu);
        if ( !v41 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v14 );
      }
      if ( (*(_BYTE *)(v11 + 72) & 7) != 0 )
        goto LABEL_45;
      *(_DWORD *)(v11 + 136) = v24;
      if ( (*(_BYTE *)v27 & 7) == 1 )
      {
        v59 = 0;
      }
      else
      {
        if ( (*(_BYTE *)v27 & 0x7F) != 5 )
          goto LABEL_45;
        v59 = *(_DWORD *)(v27 + 4) - 1;
      }
      *(_DWORD *)(v27 + 4) = v59;
LABEL_45:
      __dmb(0xBu);
      do
        v42 = __ldrex((unsigned int *)v27);
      while ( __strex(v42 & 0xFFFFFF7F, (unsigned int *)v27) );
      goto LABEL_47;
    }
LABEL_25:
    v31 = *(int ***)(v27 + 12);
    *v26 = v27 + 8;
    v26[1] = (int)v31;
    if ( *v31 != (int *)(v27 + 8) )
      __fastfail(3u);
    *v31 = v26;
    *(_DWORD *)(v27 + 12) = v26;
    __dmb(0xBu);
    do
      v32 = __ldrex((unsigned int *)v27);
    while ( __strex(v32 & 0xFFFFFF7F, (unsigned int *)v27) );
    ++v24;
    v23 = v161;
    v26 += 6;
    if ( v24 >= a1 )
    {
      if ( v162 == 2 )
      {
        v52 = MEMORY[0xFFFF93B0];
        while ( 1 )
        {
          v53 = MEMORY[0xFFFF900C];
          __dmb(0xBu);
          v54 = MEMORY[0xFFFF9008];
          __dmb(0xBu);
          if ( v53 == MEMORY[0xFFFF9010] )
            break;
          __dmb(0xAu);
          __yield();
        }
        v57 = __PAIR64__(v53, v54) - v52 - *(_QWORD *)(v11 + 160);
        v56 = HIDWORD(v57);
        v55 = v57;
        v33 = v163;
      }
      else
      {
        v34 = HIDWORD(v163);
        v33 = v163;
        if ( !v162 )
          goto LABEL_31;
        if ( !v163 )
        {
          while ( 1 )
          {
            do
LABEL_74:
              v58 = __ldrex(v14);
            while ( __strex(1u, v14) );
            __dmb(0xBu);
            if ( !v58 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v14 );
          }
          if ( (*(_BYTE *)(v11 + 72) & 7) == 0 )
            *(_DWORD *)(v11 + 136) = 258;
          goto LABEL_47;
        }
        while ( 1 )
        {
          v56 = MEMORY[0xFFFF9018];
          __dmb(0xBu);
          v55 = MEMORY[0xFFFF9014];
          __dmb(0xBu);
          if ( v56 == MEMORY[0xFFFF901C] )
            break;
          __dmb(0xAu);
          __yield();
        }
      }
      v34 = HIDWORD(v163);
      v20 = a1;
      v22 = v162;
      v14 = (unsigned int *)(v11 + 44);
      if ( v56 > HIDWORD(v163) || v56 >= HIDWORD(v163) && v55 > v33 )
        goto LABEL_74;
LABEL_31:
      *(_BYTE *)(v11 + 363) = v20;
      v35 = KiCommitThreadWait(v11, (int)v19, v22, v34, __SPAIR64__(v34, v33));
      if ( v35 != 256 )
        return v35;
      v165 = 0;
      *(_BYTE *)(v11 + 134) = KfRaiseIrql(2);
      goto LABEL_11;
    }
  }
  if ( v30 <= 0 && (v11 != *(_DWORD *)(v27 + 24) || *(unsigned __int8 *)(v27 + 2) != *(unsigned __int8 *)(v23 + 1754)) )
    goto LABEL_25;
  if ( *(_DWORD *)(v27 + 4) == 0x80000000 )
  {
    __dmb(0xBu);
    do
      v103 = __ldrex((unsigned int *)v27);
    while ( __strex(v103 & 0xFFFFFF7F, (unsigned int *)v27) );
    while ( 1 )
    {
      do
        v104 = __ldrex(v14);
      while ( __strex(1u, v14) );
      __dmb(0xBu);
      if ( !v104 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v14 );
    }
    *(_BYTE *)(v11 + 132) = 2;
    __dmb(0xBu);
    *v14 = 0;
    if ( v24 )
    {
      v105 = &v19[6 * (unsigned __int8)v24];
      do
      {
        if ( *((unsigned __int8 *)v19 + 9) < 5u )
        {
          v106 = (unsigned __int8 *)v19[4];
          do
            v107 = __ldrex(v106);
          while ( __strex(v107 | 0x80, v106) );
          __dmb(0xBu);
          if ( v107 >> 7 )
          {
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
              }
              while ( (*(_DWORD *)v106 & 0x80) != 0 );
              do
                v108 = __ldrex(v106);
              while ( __strex(v108 | 0x80, v106) );
              __dmb(0xBu);
            }
            while ( v108 >> 7 );
          }
          if ( *((_BYTE *)v19 + 9) == 4 )
          {
            *(_QWORD *)&v109 = *(_QWORD *)v19;
            if ( *(int **)(*v19 + 4) != v19 || *v110 != v19 )
              __fastfail(3u);
            *v110 = v109;
            v109[1] = (int)v110;
          }
          __dmb(0xBu);
          do
            v111 = __ldrex((unsigned int *)v106);
          while ( __strex(v111 & 0xFFFFFF7F, (unsigned int *)v106) );
        }
        v19 += 6;
      }
      while ( v19 != v105 );
    }
    KiExitThreadWait(v161, v11, v165);
    RtlRaiseStatus(-1073741423);
  }
  while ( 1 )
  {
    do
      v60 = __ldrex(v14);
    while ( __strex(1u, v14) );
    __dmb(0xBu);
    if ( !v60 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v14 );
  }
  if ( (*(_BYTE *)(v11 + 72) & 7) == 0 )
  {
    *(_DWORD *)(v11 + 136) = v24;
    v61 = *(_DWORD *)(v27 + 4) - 1;
    *(_DWORD *)(v27 + 4) = v61;
    if ( !v61 )
    {
      *(_WORD *)(v11 + 308) -= *(unsigned __int8 *)(v27 + 29);
      if ( *(_DWORD *)(v23 + 4) == v11 )
        v62 = *(_BYTE *)(v23 + 1754);
      else
        v62 = 0;
      LODWORD(v172) = *(_DWORD *)v27;
      BYTE2(v172) = v62;
      *(_DWORD *)v27 = v172;
      v63 = *(unsigned __int8 *)(v27 + 28);
      *(_DWORD *)(v27 + 24) = v11;
      if ( v63 )
      {
        *(_BYTE *)(v27 + 28) = 0;
        *(_DWORD *)(v11 + 136) |= 0x80u;
      }
      v64 = *(_DWORD **)(v11 + 480);
      v65 = v27 + 16;
      *(_DWORD *)(v27 + 16) = v11 + 476;
      *(_DWORD *)(v27 + 20) = v64;
      if ( *v64 != v11 + 476 )
        __fastfail(3u);
      *v64 = v65;
      *(_DWORD *)(v11 + 480) = v65;
    }
  }
  __dmb(0xBu);
  do
    v66 = __ldrex((unsigned int *)v27);
  while ( __strex(v66 & 0xFFFFFF7F, (unsigned int *)v27) );
LABEL_47:
  *(_BYTE *)(v11 + 132) = 2;
  __dmb(0xBu);
  *v14 = 0;
  v35 = *(_DWORD *)(v11 + 136);
  if ( v24 )
  {
    v43 = &v19[6 * (unsigned __int8)v24];
    do
    {
      if ( *((unsigned __int8 *)v19 + 9) < 5u )
      {
        v44 = (unsigned __int8 *)v19[4];
        do
          v45 = __ldrex(v44);
        while ( __strex(v45 | 0x80, v44) );
        __dmb(0xBu);
        if ( v45 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( (*(_DWORD *)v44 & 0x80) != 0 );
            do
              v72 = __ldrex(v44);
            while ( __strex(v72 | 0x80, v44) );
            __dmb(0xBu);
          }
          while ( v72 >> 7 );
        }
        if ( *((_BYTE *)v19 + 9) == 4 )
        {
          *(_QWORD *)&v46 = *(_QWORD *)v19;
          if ( *(int **)(*v19 + 4) != v19 || *v47 != v19 )
            __fastfail(3u);
          *v47 = v46;
          v46[1] = (int)v47;
        }
        __dmb(0xBu);
        do
          v48 = __ldrex((unsigned int *)v44);
        while ( __strex(v48 & 0xFFFFFF7F, (unsigned int *)v44) );
      }
      v19 += 6;
    }
    while ( v19 != v43 );
  }
  v49 = *(unsigned __int8 *)(v11 + 134);
  if ( (*(_BYTE *)(v11 + 72) & 0x38) != 0 )
  {
    if ( (*(_BYTE *)(v11 + 72) & 0x18) != 0 )
    {
      if ( (*(_BYTE *)(v11 + 72) & 8) != 0 )
      {
        v112 = (unsigned __int8 *)(v11 + 81);
        do
          v113 = __ldrex(v112);
        while ( __strex(v113 | 8, v112) );
      }
      v168 = 0;
      v114 = (unsigned int *)(v161 + 24);
      while ( 1 )
      {
        do
          v115 = __ldrex(v114);
        while ( __strex(1u, v114) );
        __dmb(0xBu);
        if ( !v115 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v114 );
      }
      if ( !*(_DWORD *)(v161 + 8) )
        KiSelectNextThread(v161, &v168);
      __dmb(0xBu);
      *v114 = 0;
      KiProcessDeferredReadyList(v161, &v168, v49);
      return v35;
    }
    v84 = *(_QWORD *)(v161 + 4);
    if ( HIDWORD(v84) )
    {
      KiAbProcessContextSwitch(v84, 0);
      v85 = (unsigned int *)(v161 + 24);
      while ( 1 )
      {
        do
          v86 = __ldrex(v85);
        while ( __strex(1u, v85) );
        __dmb(0xBu);
        if ( !v86 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v85 );
      }
      v87 = *(_DWORD *)(v161 + 8);
      *(_DWORD *)(v161 + 8) = 0;
      __disable_irq();
      LODWORD(v172) = v87;
      *(_BYTE *)(v161 + 16) = 1;
      LODWORD(v89) = ReadTimeStampCounter();
      v88 = v89;
      v91 = (unsigned __int64 *)(v84 + 48);
      v90 = v89 - *(_QWORD *)(v161 + 2376);
      LODWORD(v89) = HIDWORD(v90);
      v92 = *(_QWORD *)(v84 + 48) + v90;
      __dmb(0xBu);
      do
        v93 = __ldrexd(v91);
      while ( __strexd(v92, v91) );
      __dmb(0xBu);
      v94 = v90 + *(unsigned int *)(v84 + 56);
      if ( HIDWORD(v94) )
      {
        v171 = 0;
        LODWORD(v94) = -1;
      }
      *(_DWORD *)(v161 + 2376) = v88;
      v95 = v161;
      *(_DWORD *)(v161 + 2380) = HIDWORD(v89);
      v96 = *(_BYTE *)(v84 + 2);
      *(_DWORD *)(v84 + 56) = v94;
      if ( (v96 & 0x3E) != 0 )
      {
        if ( (v96 & 0x10) != 0 )
        {
          v116 = *(_DWORD *)(v161 + 2376);
          v117 = v161 + 8 * *(unsigned __int8 *)(v84 + 84);
          v118 = *(_DWORD *)(v161 + 2384);
          v96 &= 0xEFu;
          v119 = v116 >= v118;
          HIDWORD(v89) = v116 - v118;
          v120 = *(_DWORD *)(v117 + 2392);
          LODWORD(v89) = *(_DWORD *)(v161 + 2380) - (*(_DWORD *)(v161 + 2388) + !v119);
          v121 = *(_DWORD *)(v117 + 2396);
          *(_DWORD *)(v117 + 2392) = v120 + HIDWORD(v89);
          v122 = v89 + __CFADD__(v120, HIDWORD(v89)) + v121;
          LODWORD(v89) = HIDWORD(v90);
          *(_DWORD *)(v117 + 2396) = v122;
          *(_DWORD *)(v161 + 2384) = 0;
          *(_DWORD *)(v161 + 2388) = 0;
        }
        if ( (v96 & 0x3E) != 0 )
        {
          if ( (v96 & 0x20) != 0 )
          {
            v97 = *(_DWORD *)(v84 + 1084);
            if ( v97 )
            {
              v95 = v161;
              v98 = (unsigned __int64 *)(v97 + 8 * (*(unsigned __int8 *)(v161 + 2986) + 2 * PoGetFrequencyBucket(v161)));
              v99 = *v98 + v90;
              __dmb(0xBu);
              do
                v100 = __ldrexd(v98);
              while ( __strexd(v99, v98) );
              __dmb(0xBu);
              LODWORD(v89) = HIDWORD(v90);
            }
            v96 &= 0xDFu;
          }
          if ( (v96 & 0x3E) != 0 )
          {
            v101 = *(_DWORD *)(v84 + 68);
            if ( v101 )
            {
              for ( HIDWORD(v89) = v101 + *(_DWORD *)(v95 + 2352);
                    HIDWORD(v89);
                    HIDWORD(v89) = *(_DWORD *)(HIDWORD(v89) + 236) )
              {
                *(_QWORD *)HIDWORD(v89) += __PAIR64__(v89, v90);
              }
            }
            if ( (*(_BYTE *)(v84 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v95 + 2360) + 260) & *(_DWORD *)(v84 + 356)) != *(_DWORD *)(*(_DWORD *)(v95 + 2360) + 260) )
            {
              *(_QWORD *)(v95 + 2368) += __PAIR64__(v89, v90);
            }
            if ( *(_DWORD *)(v84 + 236) )
            {
              KiEndCounterAccumulation(v84);
              v95 = v161;
            }
          }
        }
      }
      v102 = v172;
      __enable_irq();
      *(_DWORD *)(v95 + 4) = v102;
      *(_BYTE *)(v102 + 132) = 2;
      *(_BYTE *)(v84 + 395) = 32;
      *(_BYTE *)(v84 + 134) = 1;
      KiQueueReadyThread(v95, v84);
      if ( !KiSwapContext(v84, v102, 1) )
        goto LABEL_176;
    }
    else if ( (*(_DWORD *)(v84 + 76) & 0x40) == 0 )
    {
      goto LABEL_176;
    }
    KfLowerIrql(1);
    *(_DWORD *)(v84 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
LABEL_176:
    KfLowerIrql(1);
    KiDeliverApc(0, 0, 0);
    KfLowerIrql(0);
    return v35;
  }
  if ( !v165 )
  {
LABEL_62:
    v50 = (void (__fastcall **)(int))&KfLowerIrql;
    v51 = v49;
    goto LABEL_63;
  }
  if ( v49 < 2 )
  {
    v123 = *(_QWORD *)(v161 + 4);
    if ( HIDWORD(v123) )
    {
      KiAbProcessContextSwitch(v123, 0);
      v124 = (unsigned int *)(v161 + 24);
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
      v126 = *(_DWORD *)(v161 + 8);
      *(_DWORD *)(v161 + 8) = 0;
      __disable_irq();
      v170 = v126;
      *(_BYTE *)(v161 + 16) = 1;
      LODWORD(v128) = ReadTimeStampCounter();
      v127 = v128;
      v130 = (unsigned __int64 *)(v123 + 48);
      v129 = (unsigned __int64)(v128 - *(_QWORD *)(v161 + 2376)) >> 32;
      LODWORD(v128) = v128 - *(_DWORD *)(v161 + 2376);
      v131 = *(_DWORD *)(v123 + 52);
      v132 = *(_DWORD *)(v123 + 48);
      v167 = v128;
      LODWORD(v172) = v129;
      __dmb(0xBu);
      do
        v133 = __ldrexd(v130);
      while ( __strexd(__PAIR64__(v131, v128) + __PAIR64__(v129, v132), v130) );
      __dmb(0xBu);
      v134 = __PAIR64__(v129, *(_DWORD *)(v123 + 56)) + (unsigned int)v128;
      if ( HIDWORD(v134) )
      {
        v169 = 0;
        LODWORD(v134) = -1;
      }
      v135 = v161;
      *(_DWORD *)(v161 + 2376) = v127;
      *(_DWORD *)(v161 + 2380) = HIDWORD(v128);
      v136 = *(_BYTE *)(v123 + 2);
      *(_DWORD *)(v123 + 56) = v134;
      if ( (v136 & 0x3E) != 0 )
      {
        if ( (v136 & 0x10) != 0 )
        {
          v137 = *(_DWORD *)(v161 + 2376);
          v138 = v161 + 8 * *(unsigned __int8 *)(v123 + 84);
          v139 = *(_DWORD *)(v161 + 2384);
          v136 &= 0xEFu;
          v119 = v137 >= v139;
          HIDWORD(v128) = v137 - v139;
          v140 = *(_DWORD *)(v138 + 2392);
          LODWORD(v128) = *(_DWORD *)(v161 + 2380) - (*(_DWORD *)(v161 + 2388) + !v119);
          v141 = *(_DWORD *)(v138 + 2396);
          *(_DWORD *)(v138 + 2392) = v140 + HIDWORD(v128);
          *(_DWORD *)(v138 + 2396) = v128 + __CFADD__(v140, HIDWORD(v128)) + v141;
          v135 = v161;
          LODWORD(v128) = v167;
          *(_DWORD *)(v161 + 2384) = 0;
          *(_DWORD *)(v161 + 2388) = 0;
        }
        if ( (v136 & 0x3E) != 0 )
        {
          if ( (v136 & 0x20) != 0 )
          {
            v142 = *(_DWORD *)(v123 + 1084);
            if ( v142 )
            {
              v129 = v172;
              v143 = (unsigned __int64 *)(v142 + 8
                                               * (*(unsigned __int8 *)(v161 + 2986) + 2 * PoGetFrequencyBucket(v161)));
              v144 = __PAIR64__(v172, v167) + *v143;
              __dmb(0xBu);
              do
                v145 = __ldrexd(v143);
              while ( __strexd(v144, v143) );
              __dmb(0xBu);
              LODWORD(v128) = v167;
            }
            v135 = v161;
            v136 &= 0xDFu;
          }
          if ( (v136 & 0x3E) != 0 )
          {
            v146 = *(_DWORD *)(v123 + 68);
            if ( v146 )
            {
              for ( HIDWORD(v128) = v146 + *(_DWORD *)(v135 + 2352);
                    HIDWORD(v128);
                    HIDWORD(v128) = *(_DWORD *)(HIDWORD(v128) + 236) )
              {
                *(_QWORD *)HIDWORD(v128) += __PAIR64__(v129, v128);
              }
            }
            if ( (*(_BYTE *)(v123 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v135 + 2360) + 260) & *(_DWORD *)(v123 + 356)) != *(_DWORD *)(*(_DWORD *)(v135 + 2360) + 260) )
            {
              *(_QWORD *)(v135 + 2368) += __PAIR64__(v129, v128);
            }
            if ( *(_DWORD *)(v123 + 236) )
              KiEndCounterAccumulation(v123);
          }
        }
      }
      v147 = v170;
      v148 = v161;
      __enable_irq();
      *(_DWORD *)(v148 + 4) = v147;
      *(_BYTE *)(v147 + 132) = 2;
      *(_BYTE *)(v123 + 395) = 32;
      *(_BYTE *)(v123 + 134) = v49;
      KiQueueReadyThread(v148, v123);
      if ( !KiSwapContext(v123, v147, v49) )
        goto LABEL_62;
    }
    else if ( (*(_DWORD *)(v123 + 76) & 0x40) == 0 )
    {
      goto LABEL_62;
    }
    KfLowerIrql(1);
    *(_DWORD *)(v123 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
    goto LABEL_62;
  }
  if ( *(_DWORD *)(v161 + 8) && !*(_BYTE *)(v161 + 1754) )
  {
LABEL_108:
    v50 = (void (__fastcall **)(int))&HalRequestSoftwareInterrupt;
    v51 = 2;
LABEL_63:
    (*v50)(v51);
  }
  return v35;
}
