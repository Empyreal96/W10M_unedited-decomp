// KeRemovePriQueue 
 
int __fastcall KeRemovePriQueue(int a1, char a2, unsigned int a3, int a4)
{
  int v5; // r7
  char v6; // r5
  int v7; // r5
  unsigned int *v8; // r6
  unsigned int v9; // r4
  unsigned int v10; // r5
  int v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r2
  int v14; // r9
  bool v15; // zf
  int v16; // r5
  _DWORD *v17; // r10
  int v18; // r2
  unsigned int v19; // r2
  unsigned int v20; // r2
  int v21; // r1
  unsigned int *v22; // r1
  unsigned int v23; // r0
  _DWORD *v24; // r1
  unsigned int v25; // r1
  int v26; // r0
  int v27; // r8
  unsigned int v29; // r2
  int v30; // r8
  int v31; // r3
  int v32; // r10
  int v33; // r3
  unsigned int v34; // r1
  unsigned int v35; // r3
  int v36; // r4
  unsigned int v37; // r3
  unsigned int v38; // r2
  unsigned int v39; // r3
  int v40; // r6
  __int64 v41; // r0
  unsigned __int64 *v42; // r4
  __int64 v43; // kr08_8
  unsigned __int64 v44; // r2
  __int64 v45; // r2
  char v46; // r5
  int v47; // r4
  unsigned __int64 *v48; // r4
  unsigned __int64 v49; // kr18_8
  unsigned __int64 v50; // kr20_8
  unsigned __int64 v51; // r0
  unsigned int v52; // r3
  unsigned int v53; // r2
  unsigned __int64 v54; // kr28_8
  int v55; // lr
  unsigned __int64 *v56; // r3
  unsigned __int64 v57; // kr30_8
  unsigned __int64 v58; // kr38_8
  unsigned __int64 *v59; // r4
  unsigned __int64 v60; // kr40_8
  unsigned __int64 v61; // kr48_8
  unsigned __int64 v62; // kr50_8
  int v63; // r3
  int v64; // r4
  unsigned int *v65; // r1
  unsigned int v66; // r0
  unsigned int *v67; // r1
  unsigned int v68; // r0
  unsigned int v69; // r1
  unsigned int v70; // r2
  unsigned int v71; // r1
  unsigned int v72; // r1
  int v73; // r4
  unsigned int v74; // r3
  bool v75; // cf
  unsigned int v76; // r1
  int v77; // r3
  int v78; // r0
  int v79; // r2
  int v80; // r1
  int v81; // r1
  unsigned int v82; // r0
  unsigned int v83; // r4
  unsigned int v84; // r1
  unsigned int v85; // r2
  unsigned int v86; // r3
  int v87; // r9
  int v88; // r3
  int v89; // r10
  unsigned int *v90; // r1
  unsigned int v91; // r2
  __int64 v92; // r0
  __int64 v93; // r0
  int v94; // r7
  int v95; // lr
  unsigned __int64 *v96; // r6
  unsigned __int64 v97; // kr58_8
  unsigned __int64 v98; // kr60_8
  __int64 v99; // r2
  char v100; // lr
  int v101; // r6
  int v102; // r5
  unsigned __int64 *v103; // r4
  unsigned int v104; // r5
  unsigned __int64 v105; // kr78_8
  unsigned __int64 v106; // kr80_8
  int v107; // r1
  int v108; // r5
  void (__fastcall **v109)(int); // r3
  int v110; // r0
  int v111; // [sp+8h] [bp-50h]
  unsigned int v112; // [sp+8h] [bp-50h]
  unsigned __int64 v113; // [sp+Ch] [bp-4Ch]
  char v114; // [sp+10h] [bp-48h]
  int v115; // [sp+14h] [bp-44h]
  unsigned int v116; // [sp+14h] [bp-44h]
  unsigned int v117; // [sp+18h] [bp-40h]
  unsigned int v118; // [sp+18h] [bp-40h]
  int v119; // [sp+1Ch] [bp-3Ch] BYREF
  unsigned int v120; // [sp+20h] [bp-38h]
  int v121; // [sp+24h] [bp-34h]
  unsigned int v122; // [sp+28h] [bp-30h]
  unsigned __int64 v123; // [sp+30h] [bp-28h]

  v115 = a2;
  v120 = a3;
  v122 = a1;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(_BYTE *)(v5 + 0x4C);
  *(_BYTE *)(v5 + 0x4C) = v6 & 0xFB;
  if ( !((unsigned __int8)(v6 & 4) >> 2) )
  {
    a1 = KfRaiseIrql(2);
    *(_BYTE *)(v5 + 134) = a1;
  }
  if ( a4 )
  {
    if ( *(int *)(a4 + 4) < 0 )
      return sub_53F2C4(a1);
    v7 = 1;
    v113 = *(_QWORD *)a4;
  }
  else
  {
    v7 = 0;
    v113 = v123;
  }
  v111 = v7;
  v8 = (unsigned int *)(v5 + 44);
  while ( 1 )
  {
    v9 = *(unsigned __int8 *)(v5 + 134);
    v10 = v120;
    LODWORD(v123) = v9;
    while ( 1 )
    {
      v11 = *(_DWORD *)(v5 + 76);
      *(_BYTE *)(v5 + 72) = 0;
      *(_BYTE *)(v5 + 135) = v115;
      v12 = v11 & 0xFFFFFFEF;
      *(_DWORD *)(v5 + 76) = v12;
      if ( v10 )
        *(_DWORD *)(v5 + 76) = v12 | 0x10;
      while ( 1 )
      {
        do
          v13 = __ldrex(v8);
        while ( __strex(1u, v8) );
        __dmb(0xBu);
        if ( !v13 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v8 );
      }
      if ( !*(_BYTE *)(v5 + 121) || *(_WORD *)(v5 + 310) || v9 )
        break;
      __dmb(0xBu);
      *v8 = 0;
      KfLowerIrql(1);
      KiDeliverApc(0, 0, 0);
      KfRaiseIrql(2);
      *(_BYTE *)(v5 + 134) = 0;
    }
    v14 = v122;
    v15 = v10 == 0;
    v16 = v111;
    v17 = (_DWORD *)(v5 + 216);
    if ( v15 )
    {
      if ( (*(_BYTE *)(v5 + 122) & (unsigned __int8)v115) != 0 )
        goto LABEL_137;
    }
    else
    {
      if ( *(_BYTE *)(v115 + v5 + 74) )
      {
        *(_BYTE *)(v115 + v5 + 74) = 0;
        v27 = 257;
        goto LABEL_138;
      }
      if ( v115 && *(_DWORD *)(v5 + 108) != v5 + 108 )
      {
        *(_BYTE *)(v5 + 122) = 1;
LABEL_137:
        v27 = 192;
LABEL_138:
        __dmb(0xBu);
        *v8 = 0;
        v86 = (unsigned int)KeGetPcr();
        v87 = (v86 & 0xFFFFF000) + 1408;
        v88 = *(_DWORD *)((v86 & 0xFFFFF000) + 0x588);
        if ( v9 >= 2 )
        {
          if ( !v88 || *(_BYTE *)(v87 + 1754) )
            return v27;
          v109 = (void (__fastcall **)(int))&HalRequestSoftwareInterrupt;
          v110 = 2;
LABEL_178:
          (*v109)(v110);
          return v27;
        }
        v89 = *(_DWORD *)(v87 + 4);
        if ( v88 )
        {
          KiAbProcessContextSwitch(*(_DWORD *)(v87 + 4), 0);
          v90 = (unsigned int *)(v87 + 24);
          while ( 1 )
          {
            do
              v91 = __ldrex(v90);
            while ( __strex(1u, v90) );
            __dmb(0xBu);
            if ( !v91 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v90 );
          }
          v122 = *(_DWORD *)(v87 + 8);
          *(_DWORD *)(v87 + 8) = 0;
          __disable_irq();
          *(_BYTE *)(v87 + 16) = 1;
          LODWORD(v92) = ReadTimeStampCounter();
          v94 = HIDWORD(v92);
          v95 = v92;
          v96 = (unsigned __int64 *)(v89 + 48);
          v93 = v92 - *(_QWORD *)(v87 + 2376);
          v116 = HIDWORD(v93);
          v118 = v93;
          v97 = *(_QWORD *)(v89 + 48) + v93;
          __dmb(0xBu);
          do
            v98 = __ldrexd(v96);
          while ( __strexd(v97, v96) );
          __dmb(0xBu);
          v99 = v93 + *(unsigned int *)(v89 + 56);
          if ( HIDWORD(v99) )
          {
            v121 = 0;
            LODWORD(v99) = -1;
          }
          *(_DWORD *)(v87 + 2376) = v95;
          *(_DWORD *)(v87 + 2380) = v94;
          v100 = *(_BYTE *)(v89 + 2);
          v114 = v100;
          *(_DWORD *)(v89 + 56) = v99;
          if ( (v100 & 0x3E) != 0 )
          {
            if ( (v100 & 0x10) != 0 )
            {
              v101 = v87 + 8 * *(unsigned __int8 *)(v89 + 84);
              *(_QWORD *)(v101 + 2392) = *(_QWORD *)(v101 + 2392) - *(_QWORD *)(v87 + 2384) + *(_QWORD *)(v87 + 2376);
              v100 &= 0xEFu;
              *(_DWORD *)(v87 + 2384) = 0;
              *(_DWORD *)(v87 + 2388) = 0;
              v114 = v100;
            }
            if ( (v100 & 0x3E) != 0 )
            {
              if ( (v100 & 0x20) != 0 )
              {
                v102 = *(_DWORD *)(v89 + 1084);
                if ( v102 )
                {
                  v103 = (unsigned __int64 *)(v102
                                            + 8 * (*(unsigned __int8 *)(v87 + 2986) + 2 * PoGetFrequencyBucket(v87)));
                  v104 = v116;
                  v105 = __PAIR64__(v116, v118) + *v103;
                  __dmb(0xBu);
                  do
                    v106 = __ldrexd(v103);
                  while ( __strexd(v105, v103) );
                  __dmb(0xBu);
                  v100 = v114;
                  LODWORD(v93) = v118;
                }
                else
                {
                  v104 = HIDWORD(v93);
                }
                v100 &= 0xDFu;
              }
              else
              {
                v104 = HIDWORD(v93);
              }
              if ( (v100 & 0x3E) != 0 )
              {
                v107 = *(_DWORD *)(v89 + 68);
                if ( v107 )
                {
                  for ( HIDWORD(v93) = v107 + *(_DWORD *)(v87 + 2352);
                        HIDWORD(v93);
                        HIDWORD(v93) = *(_DWORD *)(HIDWORD(v93) + 236) )
                  {
                    *(_QWORD *)HIDWORD(v93) += __PAIR64__(v104, v93);
                  }
                }
                if ( (*(_BYTE *)(v89 + 2) & 8) != 0
                  && (*(_DWORD *)(v89 + 356) & *(_DWORD *)(*(_DWORD *)(v87 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v87 + 2360) + 260) )
                {
                  *(_QWORD *)(v87 + 2368) += __PAIR64__(v104, v93);
                }
                if ( *(_DWORD *)(v89 + 236) )
                  KiEndCounterAccumulation(v89);
              }
            }
          }
          v108 = v122;
          __enable_irq();
          *(_DWORD *)(v87 + 4) = v108;
          *(_BYTE *)(v108 + 132) = 2;
          *(_BYTE *)(v89 + 395) = 32;
          v9 = v123;
          *(_BYTE *)(v89 + 134) = v123;
          KiQueueReadyThread(v87, v89);
          if ( !KiSwapContext(v89, v108, v9) )
            goto LABEL_174;
        }
        else if ( (*(_DWORD *)(v89 + 76) & 0x40) == 0 )
        {
LABEL_174:
          v109 = (void (__fastcall **)(int))&KfLowerIrql;
          v110 = v9;
          goto LABEL_178;
        }
        KfLowerIrql(1);
        *(_DWORD *)(v89 + 76) &= 0xFFFFFFBF;
        KiDeliverApc(0, 0, 0);
        goto LABEL_174;
      }
      if ( *(_BYTE *)(v5 + 74) )
      {
        *(_BYTE *)(v5 + 74) = 0;
        v27 = 257;
        goto LABEL_138;
      }
    }
    *(_BYTE *)(v5 + 132) = 5;
    *(_BYTE *)(v5 + 395) = 15;
    __dmb(0xBu);
    *v8 = 0;
    *(_DWORD *)(v5 + 304) = KeTickCount;
    v18 = *(_DWORD *)(v5 + 152);
    if ( v14 != v18 )
      KiSwitchPriQueue(v5, v14, v18);
    *(_BYTE *)(v5 + 224) = 1;
    *(_BYTE *)(v5 + 225) = 4;
    *(_WORD *)(v5 + 226) = 128;
    *(_DWORD *)(v5 + 232) = v14;
    do
      v19 = __ldrex((unsigned __int8 *)v14);
    while ( __strex(v19 | 0x80, (unsigned __int8 *)v14) );
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
        while ( (*(_DWORD *)v14 & 0x80) != 0 );
        do
          v38 = __ldrex((unsigned __int8 *)v14);
        while ( __strex(v38 | 0x80, (unsigned __int8 *)v14) );
        __dmb(0xBu);
      }
      while ( v38 >> 7 );
    }
    if ( *(_DWORD *)(v14 + 4) )
      break;
LABEL_21:
    if ( v111 )
    {
      if ( !v113 )
        goto LABEL_88;
      while ( 1 )
      {
        v70 = MEMORY[0xFFFF9018];
        __dmb(0xBu);
        v71 = MEMORY[0xFFFF9014];
        __dmb(0xBu);
        if ( v70 == MEMORY[0xFFFF901C] )
          break;
        __dmb(0xAu);
        __yield();
      }
      v16 = v111;
      v17 = (_DWORD *)(v5 + 216);
      if ( __PAIR64__(v70, v71) > v113 )
      {
LABEL_88:
        __dmb(0xBu);
        do
          v69 = __ldrex((unsigned int *)v14);
        while ( __strex(v69 & 0xFFFFFF7F, (unsigned int *)v14) );
        v30 = 258;
        goto LABEL_39;
      }
    }
    while ( 1 )
    {
      do
        v20 = __ldrex(v8);
      while ( __strex(1u, v8) );
      __dmb(0xBu);
      if ( !v20 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v8 );
    }
    v21 = *(unsigned __int8 *)(v5 + 332);
    *(_DWORD *)(v5 + 332) = v21 | 0x100;
    __dmb(0xBu);
    v22 = (unsigned int *)(v14 + 4 * (v21 + 68));
    do
      v23 = __ldrex(v22);
    while ( __strex(v23 - 1, v22) );
    __dmb(0xBu);
    *v8 = 0;
    v24 = *(_DWORD **)(v14 + 12);
    *v17 = v14 + 8;
    v17[1] = v24;
    if ( *v24 != v14 + 8 )
      __fastfail(3u);
    *v24 = v17;
    *(_DWORD *)(v14 + 12) = v17;
    __dmb(0xBu);
    do
      v25 = __ldrex((unsigned int *)v14);
    while ( __strex(v25 & 0xFFFFFF7F, (unsigned int *)v14) );
    *(_BYTE *)(v5 + 363) = 1;
    v26 = KiCommitThreadWait(v5, (int)v17, v16, 1, v113);
    *(_BYTE *)(v5 + 395) = 0;
    v27 = v26;
    if ( v26 != 256 )
      return v27;
    *(_BYTE *)(v5 + 134) = KfRaiseIrql(2);
  }
  while ( 1 )
  {
    do
      v29 = __ldrex(v8);
    while ( __strex(1u, v8) );
    __dmb(0xBu);
    if ( !v29 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v8 );
  }
  v30 = KiAttemptFastRemovePriQueue(v14, &v119, *(unsigned __int8 *)(v5 + 332));
  if ( !v30 )
  {
    __dmb(0xBu);
    *v8 = 0;
    goto LABEL_21;
  }
  v31 = *(_DWORD *)(v5 + 332);
  v32 = v119;
  if ( (unsigned __int8)v31 != v119 )
  {
    if ( (v31 & 0x100) == 0 )
    {
      v64 = *(_DWORD *)(v5 + 152);
      __dmb(0xBu);
      v65 = (unsigned int *)(v64 + 4 * ((unsigned __int8)v31 + 68));
      do
        v66 = __ldrex(v65);
      while ( __strex(v66 - 1, v65) );
      __dmb(0xBu);
      v67 = (unsigned int *)(v64 + 4 * (v32 + 68));
      do
        v68 = __ldrex(v67);
      while ( __strex(v68 + 1, v67) );
      __dmb(0xBu);
    }
    *(_DWORD *)(v5 + 332) = (unsigned __int8)v32 | v31 & 0x100;
  }
  *(_BYTE *)(v5 + 397) = 0;
  KiAbProcessThreadPriorityModification(v5, (char)v32, 0);
  v33 = *(char *)(v5 + 348);
  *(_BYTE *)(v5 + 347) = v32;
  if ( v33 )
  {
    if ( (v33 & 0xF) != 0 )
      *(_DWORD *)(v5 + 812) = KeTickCount;
    *(_BYTE *)(v5 + 348) = 0;
  }
  if ( v32 != *(char *)(v5 + 123) )
  {
    v39 = (unsigned int)KeGetPcr();
    v40 = (v39 & 0xFFFFF000) + 1408;
    if ( *(_BYTE *)((v39 & 0xFFFFF000) + 0x590) )
    {
      v117 = *(_DWORD *)(v5 + 52);
      v112 = *(_DWORD *)(v5 + 48);
    }
    else
    {
      __disable_irq();
      *(_BYTE *)((v39 & 0xFFFFF000) + 0x590) = 1;
      LODWORD(v41) = ReadTimeStampCounter();
      v42 = (unsigned __int64 *)(v5 + 48);
      v43 = v41 - *(_QWORD *)(v40 + 2376);
      v112 = *(_DWORD *)(v5 + 48) + v43;
      v117 = (unsigned __int64)(*(_QWORD *)(v5 + 48) + v43) >> 32;
      __dmb(0xBu);
      do
        v44 = __ldrexd(v42);
      while ( __strexd(__PAIR64__(v117, v112), v42) );
      __dmb(0xBu);
      v32 = v119;
      v45 = v43 + *(unsigned int *)(v5 + 56);
      if ( HIDWORD(v45) )
      {
        HIDWORD(v123) = 0;
        LODWORD(v45) = -1;
      }
      *(_QWORD *)(v40 + 2376) = v41;
      v46 = *(_BYTE *)(v5 + 2);
      *(_DWORD *)(v5 + 56) = v45;
      if ( (v46 & 0x3E) != 0 )
      {
        if ( (v46 & 0x10) != 0 )
        {
          v72 = *(_DWORD *)(v40 + 2376);
          v73 = v40 + 8 * *(unsigned __int8 *)(v5 + 84);
          v74 = *(_DWORD *)(v40 + 2384);
          v46 &= 0xEFu;
          v75 = v72 >= v74;
          v76 = v72 - v74;
          v77 = *(_DWORD *)(v73 + 2392);
          v78 = *(_DWORD *)(v40 + 2380) - (*(_DWORD *)(v40 + 2388) + !v75);
          v79 = *(_DWORD *)(v73 + 2396);
          *(_DWORD *)(v73 + 2392) = v77 + v76;
          *(_DWORD *)(v73 + 2396) = v78 + __CFADD__(v77, v76) + v79;
          *(_DWORD *)(v40 + 2384) = 0;
          *(_DWORD *)(v40 + 2388) = 0;
        }
        if ( (v46 & 0x3E) != 0 )
        {
          if ( (v46 & 0x20) != 0 )
          {
            v47 = *(_DWORD *)(v5 + 1084);
            if ( v47 )
            {
              v48 = (unsigned __int64 *)(v47 + 8 * (*(unsigned __int8 *)(v40 + 2986) + 2 * PoGetFrequencyBucket(v40)));
              v49 = *v48 + v43;
              __dmb(0xBu);
              do
                v50 = __ldrexd(v48);
              while ( __strexd(v49, v48) );
              __dmb(0xBu);
            }
            v46 &= 0xDFu;
          }
          if ( (v46 & 0x3E) != 0 )
          {
            v80 = *(_DWORD *)(v5 + 68);
            if ( v80 && (v81 = v80 + *(_DWORD *)(v40 + 2352)) != 0 )
            {
              v83 = HIDWORD(v43);
              v82 = v43;
              do
              {
                *(_QWORD *)v81 += v43;
                v81 = *(_DWORD *)(v81 + 236);
              }
              while ( v81 );
            }
            else
            {
              v83 = HIDWORD(v43);
              v82 = v43;
            }
            if ( (*(_BYTE *)(v5 + 2) & 8) != 0
              && (*(_DWORD *)(v5 + 356) & *(_DWORD *)(*(_DWORD *)(v40 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v40 + 2360) + 260) )
            {
              *(_QWORD *)(v40 + 2368) += __PAIR64__(v83, v82);
            }
            if ( *(_DWORD *)(v5 + 236) )
              KiEndCounterAccumulation(v5);
          }
        }
      }
      LODWORD(v51) = ReadTimeStampCounter();
      v52 = *(_DWORD *)(v40 + 2376);
      v53 = *(_DWORD *)(v40 + 2380);
      v122 = HIDWORD(v51);
      v54 = v51 - __PAIR64__(v53, v52);
      v120 = v51;
      __dmb(0xBu);
      v55 = v40;
      v56 = (unsigned __int64 *)(v40 + 2744);
      do
        v57 = __ldrexd(v56);
      while ( __strexd(v57 + v54, v56) );
      __dmb(0xBu);
      if ( (*(_BYTE *)(v5 + 2) & 0x20) != 0 )
      {
        v58 = v51 - *(_QWORD *)(v40 + 2376);
        v55 = v40;
        v59 = (unsigned __int64 *)(v40 + 8 * (*(unsigned __int8 *)(v40 + 2986) + 2 * (PoGetFrequencyBucket(v40) + 1144)));
        v60 = *v59 + v58;
        __dmb(0xBu);
        do
          v61 = __ldrexd(v59);
        while ( __strexd(v60, v59) );
        __dmb(0xBu);
        v51 = __PAIR64__(v122, v120);
      }
      *(_QWORD *)(v55 + 2376) = v51;
      if ( (*(_BYTE *)(v5 + 2) & 0x10) != 0 )
        *(_QWORD *)(v55 + 2384) = v51;
      if ( (*(_BYTE *)(v5 + 2) & 2) != 0 )
      {
        KiBeginCounterAccumulation(v5, 0);
        v55 = v40;
      }
      *(_BYTE *)(v55 + 16) = 0;
      __enable_irq();
    }
    v62 = __PAIR64__(v117, v112) + (unsigned int)*(unsigned __int8 *)(v5 + 403) * KiCyclesPerClockQuantum;
    v63 = *(_DWORD *)(v5 + 80);
    if ( (v63 & 0x10) != 0 )
    {
      __dmb(0xBu);
      v63 = v5 + 80;
      do
        v84 = __ldrex((unsigned __int8 *)v63);
      while ( __strex(v84 & 0xEF, (unsigned __int8 *)v63) );
      __dmb(0xBu);
    }
    *(_QWORD *)(v5 + 24) = v62;
    KiSetPriorityThread(v5, 0, v32, v63);
    v8 = (unsigned int *)(v5 + 44);
  }
  __dmb(0xBu);
  *v8 = 0;
  __dmb(0xBu);
  do
    v34 = __ldrex((unsigned int *)v14);
  while ( __strex(v34 & 0xFFFFFF7F, (unsigned int *)v14) );
LABEL_39:
  *(_BYTE *)(v5 + 395) = 0;
  v35 = (unsigned int)KeGetPcr();
  v36 = (v35 & 0xFFFFF000) + 1408;
  if ( *(_DWORD *)((v35 & 0xFFFFF000) + 0xB84) )
    KiProcessThreadWaitList(v36, 1, 0);
  *(_BYTE *)(v5 + 132) = 2;
  __dmb(0xFu);
  v37 = *v8;
  __dmb(0xBu);
  if ( v37 )
  {
    while ( 1 )
    {
      do
        v85 = __ldrex(v8);
      while ( __strex(1u, v8) );
      __dmb(0xBu);
      if ( !v85 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v8 );
    }
    __dmb(0xBu);
    *v8 = 0;
  }
  KiExitThreadWait(v36, v5, 1);
  return v30;
}
