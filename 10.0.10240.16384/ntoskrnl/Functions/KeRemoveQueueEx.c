// KeRemoveQueueEx 
 
int __fastcall KeRemoveQueueEx(int a1, char a2, int a3, _DWORD *a4, int **a5, unsigned int a6)
{
  int v6; // r6
  int v7; // lr
  int v9; // r7
  char v10; // r5
  int v11; // r10
  int **v12; // r4
  unsigned int v13; // r5
  unsigned int *v14; // r0
  unsigned int v15; // r3
  unsigned int v16; // r2
  _DWORD *v17; // r9
  int v18; // r2
  unsigned int v19; // r2
  int **v20; // r5
  unsigned int v21; // lr
  unsigned int v22; // r5
  unsigned int *v23; // r2
  unsigned int v24; // r1
  _DWORD *v25; // r0
  unsigned int v26; // r1
  int v27; // r0
  unsigned int v28; // r8
  unsigned int v30; // r2
  unsigned int v31; // r1
  unsigned int v32; // r3
  unsigned int v33; // r9
  int v34; // r10
  int v35; // r3
  unsigned int v36; // r1
  unsigned int v37; // r4
  unsigned int *v38; // r1
  int v39; // r3
  unsigned int v40; // r4
  unsigned int v41; // r2
  int v42; // r4
  unsigned int v43; // r2
  unsigned int v44; // r1
  int v45; // r9
  unsigned int v46; // r3
  int v47; // r8
  int v48; // r3
  int **v49; // r1
  __int64 v50; // kr08_8
  unsigned int v51; // r2
  unsigned int v52; // r1
  int v53; // r3
  int v54; // r10
  int v55; // r4
  void (__fastcall **v56)(int); // r3
  int v57; // r0
  __int64 v58; // r0
  unsigned int v59; // r1
  unsigned int v60; // r2
  unsigned int *v61; // r1
  unsigned int v62; // r2
  unsigned int v63; // r2
  unsigned int v64; // r1
  __int64 v65; // r0
  __int64 v66; // r0
  int v67; // lr
  unsigned __int64 *v68; // r6
  unsigned __int64 v69; // kr28_8
  unsigned __int64 v70; // kr30_8
  __int64 v71; // r2
  char v72; // lr
  int v73; // r6
  unsigned __int64 *v74; // r4
  unsigned int v75; // r6
  unsigned __int64 v76; // kr40_8
  unsigned __int64 v77; // kr48_8
  int v78; // r1
  int v79; // r6
  unsigned int v80; // r2
  unsigned int *v81; // r1
  unsigned int v82; // r2
  int v83; // r3
  __int64 v84; // r0
  __int64 v85; // r0
  __int64 v86; // kr50_8
  unsigned __int64 *v87; // r6
  unsigned __int64 v88; // kr58_8
  unsigned __int64 v89; // kr60_8
  __int64 v90; // r2
  char v91; // r5
  int v92; // r5
  unsigned int v93; // r2
  int v94; // r6
  unsigned int *v95; // r1
  unsigned int v96; // r2
  int v97; // r3
  unsigned int v98; // r3
  int v99; // r8
  int v100; // r3
  int v101; // r10
  unsigned int *v102; // r1
  unsigned int v103; // r2
  int v104; // r3
  __int64 v105; // r0
  __int64 v106; // r0
  int v107; // r9
  int v108; // lr
  unsigned __int64 *v109; // r6
  unsigned __int64 v110; // kr68_8
  unsigned __int64 v111; // kr70_8
  __int64 v112; // r2
  char v113; // lr
  int v114; // r6
  int v115; // r5
  unsigned __int64 *v116; // r4
  unsigned int v117; // r5
  unsigned __int64 v118; // kr88_8
  unsigned __int64 v119; // kr90_8
  int v120; // r1
  int v121; // r5
  int v122; // r4
  void (__fastcall **v123)(int); // r3
  int v124; // r0
  unsigned int v125; // r1
  __int64 v126; // r0
  unsigned int v127; // r1
  int v128; // r6
  int v129; // r6
  unsigned __int64 *v130; // r4
  unsigned int v131; // r6
  unsigned __int64 v132; // krA0_8
  unsigned __int64 v133; // krA8_8
  int v134; // r1
  unsigned __int64 v135; // [sp+8h] [bp-48h]
  unsigned int v136; // [sp+8h] [bp-48h]
  unsigned int v137; // [sp+8h] [bp-48h]
  unsigned int v138; // [sp+Ch] [bp-44h]
  unsigned int v139; // [sp+Ch] [bp-44h]
  unsigned int v140; // [sp+Ch] [bp-44h]
  int v141; // [sp+10h] [bp-40h]
  unsigned int v142; // [sp+10h] [bp-40h]
  unsigned int v143; // [sp+10h] [bp-40h]
  unsigned int v144; // [sp+10h] [bp-40h]
  int v145; // [sp+14h] [bp-3Ch]
  unsigned int v146; // [sp+14h] [bp-3Ch]
  char v147; // [sp+14h] [bp-3Ch]
  char v148; // [sp+14h] [bp-3Ch]
  int v150; // [sp+18h] [bp-38h]
  int v152; // [sp+20h] [bp-30h]
  int v153; // [sp+20h] [bp-30h]
  int v154; // [sp+20h] [bp-30h]
  unsigned int v155; // [sp+28h] [bp-28h]
  unsigned int v156; // [sp+28h] [bp-28h]
  unsigned int v157; // [sp+2Ch] [bp-24h]

  v6 = a1;
  v7 = a2;
  v141 = a2;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_BYTE *)(v9 + 0x4C);
  *(_BYTE *)(v9 + 0x4C) = v10 & 0xFB;
  if ( !((unsigned __int8)(v10 & 4) >> 2) )
  {
    v7 = a2;
    *(_BYTE *)(v9 + 134) = KfRaiseIrql(2);
  }
  if ( a4 )
  {
    if ( (int)a4[1] >= 0 )
    {
      v11 = 1;
      HIDWORD(v135) = *a4;
      v53 = a4[1];
    }
    else
    {
      v50 = MEMORY[0xFFFF93B0];
      v51 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v52 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v51 != MEMORY[0xFFFF9010] )
        return sub_530048(v50, v52);
      v7 = v141;
      v53 = (__PAIR64__(v51, v52) - v50 - *(_QWORD *)(v9 + 160) - *(_QWORD *)a4) >> 32;
      HIDWORD(v135) = v52 - v50 - *(_DWORD *)(v9 + 160) - *a4;
      v11 = 2;
    }
    LODWORD(v135) = v53;
  }
  else
  {
    v11 = 0;
    v135 = __PAIR64__(v155, v157);
  }
  v12 = a5;
  if ( *(_DWORD *)(v9 + 152) == v6 )
  {
    if ( *(_DWORD *)(v6 + 4) && *(_DWORD *)(v6 + 24) <= *(_DWORD *)(v6 + 28) )
    {
      do
        v30 = __ldrex((unsigned __int8 *)v6);
      while ( __strex(v30 | 0x80, (unsigned __int8 *)v6) );
      __dmb(0xBu);
      if ( v30 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v6 & 0x80) != 0 );
          do
            v63 = __ldrex((unsigned __int8 *)v6);
          while ( __strex(v63 | 0x80, (unsigned __int8 *)v6) );
          __dmb(0xBu);
        }
        while ( v63 >> 7 );
      }
      if ( !*(_DWORD *)(v6 + 4)
        || *(_DWORD *)(v6 + 24) > *(_DWORD *)(v6 + 28)
        || (v28 = KiAttemptFastRemoveQueue(v6, a5, a6)) == 0 )
      {
        __dmb(0xBu);
        do
          v64 = __ldrex((unsigned int *)v6);
        while ( __strex(v64 & 0xFFFFFF7F, (unsigned int *)v6) );
        goto LABEL_8;
      }
      __dmb(0xBu);
      do
        v31 = __ldrex((unsigned int *)v6);
      while ( __strex(v31 & 0xFFFFFF7F, (unsigned int *)v6) );
      v32 = (unsigned int)KeGetPcr();
      v33 = *(unsigned __int8 *)(v9 + 134);
      v34 = (v32 & 0xFFFFF000) + 1408;
      v35 = *(_DWORD *)((v32 & 0xFFFFF000) + 0x588);
      if ( v33 >= 2 )
      {
        if ( v35 && !*(_BYTE *)(v34 + 1754) )
          HalRequestSoftwareInterrupt(2);
        goto LABEL_56;
      }
      v40 = *(_DWORD *)(v34 + 4);
      v142 = v40;
      if ( v35 )
      {
        KiAbProcessContextSwitch(v40, 0);
        v61 = (unsigned int *)(v34 + 24);
        while ( 1 )
        {
          do
            v62 = __ldrex(v61);
          while ( __strex(1u, v61) );
          __dmb(0xBu);
          if ( !v62 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v61 );
        }
        v152 = *(_DWORD *)(v34 + 8);
        *(_DWORD *)(v34 + 8) = 0;
        __disable_irq();
        *(_BYTE *)(v34 + 16) = 1;
        LODWORD(v65) = ReadTimeStampCounter();
        v67 = HIDWORD(v65);
        v150 = v65;
        v68 = (unsigned __int64 *)(v40 + 48);
        v66 = v65 - *(_QWORD *)(v34 + 2376);
        v136 = HIDWORD(v66);
        v138 = v66;
        v69 = *(_QWORD *)(v40 + 48) + v66;
        __dmb(0xBu);
        do
          v70 = __ldrexd(v68);
        while ( __strexd(v69, v68) );
        __dmb(0xBu);
        v71 = v66 + *(unsigned int *)(v40 + 56);
        if ( HIDWORD(v71) )
          LODWORD(v71) = -1;
        *(_DWORD *)(v34 + 2380) = v67;
        *(_DWORD *)(v34 + 2376) = v150;
        v72 = *(_BYTE *)(v40 + 2);
        *(_DWORD *)(v40 + 56) = v71;
        v147 = v72;
        if ( (v72 & 0x3E) != 0 )
        {
          if ( (v72 & 0x10) != 0 )
          {
            v94 = v34 + 8 * *(unsigned __int8 *)(v40 + 84);
            *(_QWORD *)(v94 + 2392) = *(_QWORD *)(v94 + 2392) - *(_QWORD *)(v34 + 2384) + *(_QWORD *)(v34 + 2376);
            *(_DWORD *)(v34 + 2384) = 0;
            *(_DWORD *)(v34 + 2388) = 0;
            v72 &= 0xEFu;
            v147 = v72;
          }
          if ( (v72 & 0x3E) != 0 )
          {
            if ( (v72 & 0x20) != 0 )
            {
              v73 = *(_DWORD *)(v40 + 1084);
              if ( v73 )
              {
                v74 = (unsigned __int64 *)(v73 + 8 * (*(unsigned __int8 *)(v34 + 2986) + 2 * PoGetFrequencyBucket(v34)));
                v75 = v136;
                v76 = *v74 + __PAIR64__(v136, v138);
                __dmb(0xBu);
                do
                  v77 = __ldrexd(v74);
                while ( __strexd(v76, v74) );
                __dmb(0xBu);
                v40 = v142;
                v72 = v147;
                LODWORD(v66) = v138;
              }
              else
              {
                v75 = HIDWORD(v66);
              }
              v72 &= 0xDFu;
            }
            else
            {
              v75 = HIDWORD(v66);
            }
            if ( (v72 & 0x3E) != 0 )
            {
              v78 = *(_DWORD *)(v40 + 68);
              if ( v78 )
              {
                for ( HIDWORD(v66) = v78 + *(_DWORD *)(v34 + 2352);
                      HIDWORD(v66);
                      HIDWORD(v66) = *(_DWORD *)(HIDWORD(v66) + 236) )
                {
                  *(_QWORD *)HIDWORD(v66) += __PAIR64__(v75, v66);
                }
              }
              if ( (*(_BYTE *)(v40 + 2) & 8) != 0
                && (*(_DWORD *)(v40 + 356) & *(_DWORD *)(*(_DWORD *)(v34 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v34 + 2360) + 260) )
              {
                *(_QWORD *)(v34 + 2368) += __PAIR64__(v75, v66);
              }
              if ( *(_DWORD *)(v40 + 236) )
                KiEndCounterAccumulation(v40);
            }
          }
        }
        v79 = v152;
        __enable_irq();
        *(_DWORD *)(v34 + 4) = v79;
        *(_BYTE *)(v79 + 132) = 2;
        *(_BYTE *)(v40 + 395) = 32;
        *(_BYTE *)(v40 + 134) = v33;
        KiQueueReadyThread(v34, v40);
        if ( !KiSwapContext(v40, v79, v33) )
          goto LABEL_70;
      }
      else if ( (*(_DWORD *)(v40 + 76) & 0x40) == 0 )
      {
LABEL_70:
        KfLowerIrql(v33);
        v12 = a5;
LABEL_56:
        if ( (dword_682604 & 0x1000000) != 0 )
          EtwTraceDequeueWork(v9, v12, v28);
        return v28;
      }
      KfLowerIrql(1);
      *(_DWORD *)(v40 + 76) &= 0xFFFFFFBF;
      KiDeliverApc(0, 0, 0);
      goto LABEL_70;
    }
    if ( !a4 || *(_QWORD *)a4 )
      goto LABEL_8;
    if ( (*(_BYTE *)(v6 + 1) & 1) != 0 )
    {
      v49 = a5;
      *a5 = (int *)128;
      goto LABEL_203;
    }
    if ( a3 )
    {
      v95 = (unsigned int *)(v9 + 44);
      while ( 1 )
      {
        do
          v96 = __ldrex(v95);
        while ( __strex(1u, v95) );
        __dmb(0xBu);
        if ( !v96 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v95 );
      }
      if ( *(_BYTE *)(v7 + v9 + 74) )
      {
        *(_BYTE *)(v7 + v9 + 74) = 0;
        v97 = 257;
        goto LABEL_201;
      }
      if ( v7 && *(_DWORD *)(v9 + 108) != v9 + 108 )
      {
        *(_BYTE *)(v9 + 122) = 1;
        v97 = 192;
        goto LABEL_201;
      }
      if ( *(_BYTE *)(v9 + 74) )
      {
        *(_BYTE *)(v9 + 74) = 0;
        v97 = 257;
        goto LABEL_201;
      }
    }
    else if ( (*(_BYTE *)(v9 + 122) & (unsigned __int8)v7) != 0 )
    {
      v49 = a5;
      *a5 = (int *)192;
      goto LABEL_203;
    }
    v97 = 258;
LABEL_201:
    v49 = a5;
    *a5 = (int *)v97;
    if ( a3 )
    {
      __dmb(0xBu);
      *(_DWORD *)(v9 + 44) = 0;
    }
LABEL_203:
    v98 = (unsigned int)KeGetPcr();
    v99 = (v98 & 0xFFFFF000) + 1408;
    v137 = *(unsigned __int8 *)(v9 + 134);
    v100 = *(_DWORD *)((v98 & 0xFFFFF000) + 0x588);
    if ( v137 >= 2 )
    {
      if ( !v100 || *(_BYTE *)(v99 + 1754) )
      {
LABEL_245:
        if ( (dword_682604 & 0x1000000) != 0 )
LABEL_246:
          EtwTraceDequeueWork(v9, v49, 1);
        return 1;
      }
      v123 = (void (__fastcall **)(int))&HalRequestSoftwareInterrupt;
      v124 = 2;
    }
    else
    {
      v101 = *(_DWORD *)(v99 + 4);
      if ( v100 )
      {
        KiAbProcessContextSwitch(*(_DWORD *)(v99 + 4), 0);
        v102 = (unsigned int *)(v99 + 24);
        while ( 1 )
        {
          do
            v103 = __ldrex(v102);
          while ( __strex(1u, v102) );
          __dmb(0xBu);
          if ( !v103 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v102 );
        }
        v104 = *(_DWORD *)(v99 + 8);
        *(_DWORD *)(v99 + 8) = 0;
        __disable_irq();
        v154 = v104;
        *(_BYTE *)(v99 + 16) = 1;
        LODWORD(v105) = ReadTimeStampCounter();
        v108 = HIDWORD(v105);
        v107 = v105;
        v109 = (unsigned __int64 *)(v101 + 48);
        v106 = v105 - *(_QWORD *)(v99 + 2376);
        v140 = HIDWORD(v106);
        v144 = v106;
        v110 = *(_QWORD *)(v101 + 48) + v106;
        __dmb(0xBu);
        do
          v111 = __ldrexd(v109);
        while ( __strexd(v110, v109) );
        __dmb(0xBu);
        v112 = v106 + *(unsigned int *)(v101 + 56);
        if ( HIDWORD(v112) )
          LODWORD(v112) = -1;
        *(_DWORD *)(v99 + 2376) = v107;
        *(_DWORD *)(v99 + 2380) = v108;
        v113 = *(_BYTE *)(v101 + 2);
        v148 = v113;
        *(_DWORD *)(v101 + 56) = v112;
        if ( (v113 & 0x3E) != 0 )
        {
          if ( (v113 & 0x10) != 0 )
          {
            v114 = v99 + 8 * *(unsigned __int8 *)(v101 + 84);
            *(_QWORD *)(v114 + 2392) = *(_QWORD *)(v114 + 2392) - *(_QWORD *)(v99 + 2384) + *(_QWORD *)(v99 + 2376);
            v113 &= 0xEFu;
            *(_DWORD *)(v99 + 2384) = 0;
            *(_DWORD *)(v99 + 2388) = 0;
            v148 = v113;
          }
          if ( (v113 & 0x3E) != 0 )
          {
            if ( (v113 & 0x20) != 0 )
            {
              v115 = *(_DWORD *)(v101 + 1084);
              if ( v115 )
              {
                v116 = (unsigned __int64 *)(v115 + 8
                                                 * (*(unsigned __int8 *)(v99 + 2986) + 2 * PoGetFrequencyBucket(v99)));
                v117 = v140;
                v118 = __PAIR64__(v140, v144) + *v116;
                __dmb(0xBu);
                do
                  v119 = __ldrexd(v116);
                while ( __strexd(v118, v116) );
                __dmb(0xBu);
                LODWORD(v106) = v144;
                v113 = v148;
              }
              else
              {
                v117 = HIDWORD(v106);
              }
              v113 &= 0xDFu;
            }
            else
            {
              v117 = HIDWORD(v106);
            }
            if ( (v113 & 0x3E) != 0 )
            {
              v120 = *(_DWORD *)(v101 + 68);
              if ( v120 )
              {
                for ( HIDWORD(v106) = v120 + *(_DWORD *)(v99 + 2352);
                      HIDWORD(v106);
                      HIDWORD(v106) = *(_DWORD *)(HIDWORD(v106) + 236) )
                {
                  *(_QWORD *)HIDWORD(v106) += __PAIR64__(v117, v106);
                }
              }
              if ( (*(_BYTE *)(v101 + 2) & 8) != 0
                && (*(_DWORD *)(v101 + 356) & *(_DWORD *)(*(_DWORD *)(v99 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v99 + 2360) + 260) )
              {
                *(_QWORD *)(v99 + 2368) += __PAIR64__(v117, v106);
              }
              if ( *(_DWORD *)(v101 + 236) )
                KiEndCounterAccumulation(v101);
            }
          }
        }
        v121 = v154;
        __enable_irq();
        *(_DWORD *)(v99 + 4) = v121;
        *(_BYTE *)(v121 + 132) = 2;
        *(_BYTE *)(v101 + 395) = 32;
        v122 = v137;
        *(_BYTE *)(v101 + 134) = v137;
        KiQueueReadyThread(v99, v101);
        if ( KiSwapContext(v101, v121, v137) )
        {
          KfLowerIrql(1);
          *(_DWORD *)(v101 + 76) &= 0xFFFFFFBF;
          KiDeliverApc(0, 0, 0);
        }
      }
      else
      {
        if ( (*(_DWORD *)(v101 + 76) & 0x40) != 0 )
        {
          KfLowerIrql(1);
          *(_DWORD *)(v101 + 76) &= 0xFFFFFFBF;
          KiDeliverApc(0, 0, 0);
        }
        v122 = v137;
      }
      v123 = (void (__fastcall **)(int))&KfLowerIrql;
      v124 = v122;
    }
    (*v123)(v124);
    v49 = a5;
    goto LABEL_245;
  }
  while ( 1 )
  {
LABEL_8:
    v13 = *(unsigned __int8 *)(v9 + 134);
    v145 = v13;
    while ( 1 )
    {
      v14 = (unsigned int *)(v9 + 44);
      v15 = *(_DWORD *)(v9 + 76) & 0xFFFFFFEF;
      *(_DWORD *)(v9 + 76) = v15;
      *(_BYTE *)(v9 + 72) = 0;
      *(_BYTE *)(v9 + 135) = v141;
      if ( a3 )
        *(_DWORD *)(v9 + 76) = v15 | 0x10;
      while ( 1 )
      {
        do
          v16 = __ldrex(v14);
        while ( __strex(1u, v14) );
        __dmb(0xBu);
        if ( !v16 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v14 );
      }
      if ( !*(_BYTE *)(v9 + 121) || *(_WORD *)(v9 + 310) || v13 )
        break;
      __dmb(0xBu);
      *v14 = 0;
      KfLowerIrql(1);
      KiDeliverApc(0, 0, 0);
      KfRaiseIrql(2);
      *(_BYTE *)(v9 + 134) = 0;
    }
    v17 = (_DWORD *)(v9 + 216);
    if ( !a3 )
    {
      if ( (*(_BYTE *)(v9 + 122) & (unsigned __int8)v141) != 0 )
        goto LABEL_85;
      goto LABEL_19;
    }
    if ( *(_BYTE *)(v141 + v9 + 74) )
    {
      *(_BYTE *)(v141 + v9 + 74) = 0;
      v45 = 257;
      goto LABEL_86;
    }
    if ( v141 && *(_DWORD *)(v9 + 108) != v9 + 108 )
      break;
    if ( *(_BYTE *)(v9 + 74) )
    {
      *(_BYTE *)(v9 + 74) = 0;
      v45 = 257;
      goto LABEL_86;
    }
LABEL_19:
    *(_BYTE *)(v9 + 132) = 5;
    *(_BYTE *)(v9 + 395) = 15;
    __dmb(0xBu);
    *v14 = 0;
    *(_DWORD *)(v9 + 304) = KeTickCount;
    v18 = *(_DWORD *)(v9 + 152);
    if ( a1 != v18 )
      KiSwitchQueue(v9, a1, v18);
    *(_BYTE *)(v9 + 224) = 1;
    *(_BYTE *)(v9 + 225) = 4;
    *(_WORD *)(v9 + 226) = 128;
    *(_DWORD *)(v9 + 232) = a1;
    do
      v19 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v19 | 0x80, (unsigned __int8 *)a1) );
    __dmb(0xBu);
    if ( v19 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)a1 & 0x80) != 0 );
        do
          v41 = __ldrex((unsigned __int8 *)a1);
        while ( __strex(v41 | 0x80, (unsigned __int8 *)a1) );
        __dmb(0xBu);
      }
      while ( v41 >> 7 );
    }
    v20 = a5;
    if ( *(_DWORD *)(a1 + 4) )
    {
      if ( *(_DWORD *)(a1 + 24) <= *(_DWORD *)(a1 + 28) )
      {
        v28 = KiAttemptFastRemoveQueue(a1, a5, a6);
        if ( v28 )
        {
          __dmb(0xBu);
          do
            v36 = __ldrex((unsigned int *)a1);
          while ( __strex(v36 & 0xFFFFFF7F, (unsigned int *)a1) );
          goto LABEL_62;
        }
      }
    }
    if ( (*(_BYTE *)(a1 + 1) & 1) != 0 )
    {
      if ( *(_DWORD *)(v9 + 152) )
      {
        v126 = *(_QWORD *)(v9 + 312);
        if ( *(_DWORD *)(v126 + 4) != v9 + 312 || *(_DWORD *)HIDWORD(v126) != v9 + 312 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v126) = v126;
        *(_DWORD *)(v126 + 4) = HIDWORD(v126);
        *(_DWORD *)(v9 + 152) = 0;
      }
      __dmb(0xBu);
      do
        v127 = __ldrex((unsigned int *)a1);
      while ( __strex(v127 & 0xFFFFFF7F, (unsigned int *)a1) );
      *a5 = (int *)128;
LABEL_266:
      v28 = 1;
LABEL_62:
      *(_BYTE *)(v9 + 395) = 0;
      v37 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      if ( *(_DWORD *)(v37 + 2948) )
        KiProcessThreadWaitList(v37 + 1408, 1, 0);
      *(_BYTE *)(v9 + 132) = 2;
      __dmb(0xFu);
      v38 = (unsigned int *)(v9 + 44);
      v39 = *(_DWORD *)(v9 + 44);
      __dmb(0xBu);
      if ( v39 )
      {
        while ( 1 )
        {
          do
            v80 = __ldrex(v38);
          while ( __strex(1u, v38) );
          __dmb(0xBu);
          if ( !v80 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v38 );
        }
        __dmb(0xBu);
        *v38 = 0;
      }
      KiExitThreadWait(v37 + 1408, v9, 1);
      if ( (dword_682604 & 0x1000000) != 0 )
        EtwTraceDequeueWork(v9, v20, v28);
      return v28;
    }
    if ( v11 == 2 )
    {
      v156 = MEMORY[0xFFFF93B4];
      v146 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        HIDWORD(v58) = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        LODWORD(v58) = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( HIDWORD(v58) == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
      v60 = (v58 - *(_QWORD *)(v9 + 160) - __PAIR64__(v156, v146)) >> 32;
      v59 = v58 - *(_DWORD *)(v9 + 160) - v146;
    }
    else
    {
      v21 = v135;
      if ( !v11 )
      {
        v22 = HIDWORD(v135);
        goto LABEL_29;
      }
      if ( !v135 )
        goto LABEL_255;
      while ( 1 )
      {
        v60 = MEMORY[0xFFFF9018];
        __dmb(0xBu);
        v59 = MEMORY[0xFFFF9014];
        __dmb(0xBu);
        if ( v60 == MEMORY[0xFFFF901C] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    v21 = v135;
    v17 = (_DWORD *)(v9 + 216);
    if ( v60 > (unsigned int)v135 || (v22 = HIDWORD(v135), v60 >= (unsigned int)v135) && v59 > HIDWORD(v135) )
    {
      v20 = a5;
LABEL_255:
      __dmb(0xBu);
      do
        v125 = __ldrex((unsigned int *)a1);
      while ( __strex(v125 & 0xFFFFFF7F, (unsigned int *)a1) );
      *v20 = (int *)258;
      goto LABEL_266;
    }
LABEL_29:
    __dmb(0xBu);
    v23 = (unsigned int *)(a1 + 24);
    do
      v24 = __ldrex(v23);
    while ( __strex(v24 - 1, v23) );
    __dmb(0xBu);
    v25 = *(_DWORD **)(a1 + 12);
    *v17 = a1 + 8;
    v17[1] = v25;
    if ( *v25 != a1 + 8 )
      __fastfail(3u);
    *v25 = v17;
    *(_DWORD *)(a1 + 12) = v17;
    __dmb(0xBu);
    do
      v26 = __ldrex((unsigned int *)a1);
    while ( __strex(v26 & 0xFFFFFF7F, (unsigned int *)a1) );
    *(_BYTE *)(v9 + 363) = 1;
    v27 = KiCommitThreadWait(v9, (int)v17, v11, 0, __SPAIR64__(v21, v22));
    *(_BYTE *)(v9 + 395) = 0;
    if ( v27 != 256 )
    {
      v28 = 1;
      *a5 = (int *)v27;
      if ( a6 > 1 && v27 != 258 && v27 != 128 && v27 != 257 && v27 != 192 && *(_DWORD *)(a1 + 4) )
      {
        v42 = KfRaiseIrql(2);
        do
          v43 = __ldrex((unsigned __int8 *)a1);
        while ( __strex(v43 | 0x80, (unsigned __int8 *)a1) );
        __dmb(0xBu);
        if ( v43 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( (*(_DWORD *)a1 & 0x80) != 0 );
            do
              v93 = __ldrex((unsigned __int8 *)a1);
            while ( __strex(v93 | 0x80, (unsigned __int8 *)a1) );
            __dmb(0xBu);
          }
          while ( v93 >> 7 );
        }
        if ( *(_DWORD *)(a1 + 4) )
          v28 = KiAttemptFastRemoveQueue(a1, a5 + 1, a6 - 1) + 1;
        __dmb(0xBu);
        do
          v44 = __ldrex((unsigned int *)a1);
        while ( __strex(v44 & 0xFFFFFF7F, (unsigned int *)a1) );
        KfLowerIrql(v42);
      }
      if ( (dword_682604 & 0x1000000) != 0 )
        EtwTraceDequeueWork(v9, a5, v28);
      return v28;
    }
    *(_BYTE *)(v9 + 134) = KfRaiseIrql(2);
  }
  *(_BYTE *)(v9 + 122) = 1;
LABEL_85:
  v45 = 192;
LABEL_86:
  __dmb(0xBu);
  *v14 = 0;
  v46 = (unsigned int)KeGetPcr();
  v47 = (v46 & 0xFFFFF000) + 1408;
  v48 = *(_DWORD *)((v46 & 0xFFFFF000) + 0x588);
  if ( v13 < 2 )
  {
    v54 = *(_DWORD *)(v47 + 4);
    if ( v48 )
    {
      KiAbProcessContextSwitch(*(_DWORD *)(v47 + 4), 0);
      v81 = (unsigned int *)(v47 + 24);
      while ( 1 )
      {
        do
          v82 = __ldrex(v81);
        while ( __strex(1u, v81) );
        __dmb(0xBu);
        if ( !v82 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v81 );
      }
      v83 = *(_DWORD *)(v47 + 8);
      *(_DWORD *)(v47 + 8) = 0;
      __disable_irq();
      v153 = v83;
      *(_BYTE *)(v47 + 16) = 1;
      LODWORD(v84) = ReadTimeStampCounter();
      v86 = v84;
      v87 = (unsigned __int64 *)(v54 + 48);
      v85 = v84 - *(_QWORD *)(v47 + 2376);
      v139 = HIDWORD(v85);
      v143 = v85;
      v88 = v85 + *(_QWORD *)(v54 + 48);
      __dmb(0xBu);
      do
        v89 = __ldrexd(v87);
      while ( __strexd(v88, v87) );
      __dmb(0xBu);
      v90 = v85 + *(unsigned int *)(v54 + 56);
      if ( HIDWORD(v90) )
        LODWORD(v90) = -1;
      *(_QWORD *)(v47 + 2376) = v86;
      v91 = *(_BYTE *)(v54 + 2);
      *(_DWORD *)(v54 + 56) = v90;
      if ( (v91 & 0x3E) != 0 )
      {
        if ( (v91 & 0x10) != 0 )
        {
          v128 = v47 + 8 * *(unsigned __int8 *)(v54 + 84);
          *(_QWORD *)(v128 + 2392) = *(_QWORD *)(v128 + 2392) - *(_QWORD *)(v47 + 2384) + *(_QWORD *)(v47 + 2376);
          v91 &= 0xEFu;
          *(_DWORD *)(v47 + 2384) = 0;
          *(_DWORD *)(v47 + 2388) = 0;
        }
        if ( (v91 & 0x3E) != 0 )
        {
          if ( (v91 & 0x20) != 0 )
          {
            v129 = *(_DWORD *)(v54 + 1084);
            if ( v129 )
            {
              v130 = (unsigned __int64 *)(v129 + 8 * (*(unsigned __int8 *)(v47 + 2986) + 2 * PoGetFrequencyBucket(v47)));
              v131 = v139;
              v132 = __PAIR64__(v139, v143) + *v130;
              __dmb(0xBu);
              do
                v133 = __ldrexd(v130);
              while ( __strexd(v132, v130) );
              __dmb(0xBu);
              LODWORD(v85) = v143;
            }
            else
            {
              v131 = HIDWORD(v85);
            }
            v91 &= 0xDFu;
          }
          else
          {
            v131 = HIDWORD(v85);
          }
          if ( (v91 & 0x3E) != 0 )
          {
            v134 = *(_DWORD *)(v54 + 68);
            if ( v134 )
            {
              for ( HIDWORD(v85) = v134 + *(_DWORD *)(v47 + 2352);
                    HIDWORD(v85);
                    HIDWORD(v85) = *(_DWORD *)(HIDWORD(v85) + 236) )
              {
                *(_QWORD *)HIDWORD(v85) += __PAIR64__(v131, v85);
              }
            }
            if ( (*(_BYTE *)(v54 + 2) & 8) != 0
              && (*(_DWORD *)(v54 + 356) & *(_DWORD *)(*(_DWORD *)(v47 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v47 + 2360) + 260) )
            {
              *(_QWORD *)(v47 + 2368) += __PAIR64__(v131, v85);
            }
            if ( *(_DWORD *)(v54 + 236) )
              KiEndCounterAccumulation(v54);
          }
        }
      }
      v92 = v153;
      __enable_irq();
      *(_DWORD *)(v47 + 4) = v92;
      *(_BYTE *)(v92 + 132) = 2;
      *(_BYTE *)(v54 + 395) = 32;
      v55 = v145;
      *(_BYTE *)(v54 + 134) = v145;
      KiQueueReadyThread(v47, v54);
      if ( KiSwapContext(v54, v92, v145) )
      {
        KfLowerIrql(1);
        *(_DWORD *)(v54 + 76) &= 0xFFFFFFBF;
        KiDeliverApc(0, 0, 0);
        KfLowerIrql(v145);
        goto LABEL_88;
      }
    }
    else
    {
      if ( (*(_DWORD *)(v54 + 76) & 0x40) != 0 )
      {
        KfLowerIrql(1);
        *(_DWORD *)(v54 + 76) &= 0xFFFFFFBF;
        KiDeliverApc(0, 0, 0);
      }
      v55 = v13;
    }
    v56 = (void (__fastcall **)(int))&KfLowerIrql;
    v57 = v55;
    goto LABEL_102;
  }
  if ( v48 && !*(_BYTE *)(v47 + 1754) )
  {
    v56 = (void (__fastcall **)(int))&HalRequestSoftwareInterrupt;
    v57 = 2;
LABEL_102:
    (*v56)(v57);
  }
LABEL_88:
  v49 = a5;
  *a5 = (int *)v45;
  if ( (dword_682604 & 0x1000000) != 0 )
    goto LABEL_246;
  return 1;
}
