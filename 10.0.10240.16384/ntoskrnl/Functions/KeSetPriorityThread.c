// KeSetPriorityThread 
 
int __fastcall KeSetPriorityThread(int a1, int a2)
{
  unsigned int v5; // r5
  unsigned int v6; // r3
  int v7; // r8
  int v8; // r3
  unsigned int *v9; // r6
  unsigned int v10; // r2
  __int64 v11; // r0
  unsigned __int64 *v12; // r4
  unsigned int v13; // lr
  __int64 v14; // kr18_8
  __int64 v15; // kr20_8
  unsigned __int64 v16; // r0
  unsigned __int64 v17; // r2
  __int64 v18; // r2
  char v19; // r9
  int v20; // r4
  unsigned int v21; // r5
  unsigned __int64 *v22; // r4
  unsigned __int64 v23; // kr28_8
  unsigned __int64 v24; // kr30_8
  int v25; // r0
  unsigned int v26; // r1
  unsigned int v27; // r9
  unsigned int v28; // r1
  unsigned __int64 v29; // kr38_8
  unsigned __int64 *v30; // r3
  unsigned __int64 v31; // kr40_8
  unsigned __int64 v32; // kr48_8
  unsigned __int64 *v33; // r4
  unsigned __int64 v34; // kr50_8
  unsigned __int64 v35; // kr58_8
  int v36; // r1
  int v37; // r4
  int v38; // r0
  unsigned __int64 v39; // r4
  unsigned int v40; // r3
  int v41; // r4
  int v42; // r0
  char v43; // r3
  _DWORD *v44; // r9
  unsigned int v45; // r5
  int v46; // r3
  char v47; // r2
  int v48; // r0
  int v49; // r4
  int v50; // r4
  _DWORD *v51; // r4
  int v52; // r3
  int v53; // r4
  unsigned __int64 *v54; // r1
  int v55; // r6
  int v56; // r8
  unsigned __int64 v57; // kr68_8
  unsigned __int64 *v58; // r3
  unsigned __int64 v59; // kr70_8
  int v60; // r9
  char v61; // r3
  char v62; // r2
  int v63; // r0
  int v64; // r4
  unsigned int *v65; // r1
  unsigned int v66; // r2
  unsigned int v67; // r3
  unsigned int v68; // r2
  __int64 v69; // r0
  unsigned int v70; // lr
  unsigned __int64 *v71; // r6
  unsigned int v72; // r2
  unsigned int v73; // r3
  unsigned __int64 v74; // kr90_8
  unsigned __int64 v75; // r2
  char v76; // r5
  int v77; // r4
  int v78; // r0
  unsigned __int64 *v79; // r4
  unsigned __int64 v80; // kr98_8
  unsigned __int64 v81; // krA0_8
  int v82; // r1
  int v83; // r4
  int v84; // r1
  int i; // r1
  int v86; // r2
  int v87; // r1
  char v88; // r2
  int v89; // r0
  _DWORD *v90; // r1
  int v91; // r2
  int v92; // r1
  unsigned __int8 *v93; // r3
  unsigned int v94; // r2
  int v95; // r6
  signed int v96; // r3
  int v97; // r2
  int v98; // r1
  char v99; // r3
  char v100; // r2
  int v101; // r2
  int v102; // r1
  char v103; // r3
  int v104; // r3
  unsigned int *v105; // r2
  unsigned int v106; // r4
  unsigned int v107; // r3
  unsigned int v108; // r1
  int v109; // r4
  unsigned int v110; // r3
  bool v111; // cf
  int v112; // r3
  int v113; // r2
  int v114; // r2
  unsigned int v115; // [sp+8h] [bp-48h]
  unsigned int v116; // [sp+Ch] [bp-44h] BYREF
  int v117; // [sp+10h] [bp-40h]
  int v118; // [sp+14h] [bp-3Ch]
  unsigned __int64 v119; // [sp+18h] [bp-38h] BYREF
  int v120; // [sp+20h] [bp-30h]
  unsigned int v121; // [sp+24h] [bp-2Ch] BYREF
  int v122; // [sp+2Ch] [bp-24h]

  if ( *(_UNKNOWN **)(a1 + 336) == &KiInitialProcess )
    return sub_52D0BC();
  v119 = 0i64;
  v5 = KfRaiseIrql(2);
  v115 = v5;
  v6 = (unsigned int)KeGetPcr();
  v7 = (v6 & 0xFFFFF000) + 1408;
  v8 = *(_DWORD *)((v6 & 0xFFFFF000) + 0x584);
  v121 = v7;
  v9 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v10 = __ldrex(v9);
    while ( __strex(1u, v9) );
    __dmb(0xBu);
    if ( !v10 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v9 );
  }
  v120 = *(char *)(a1 + 123);
  if ( *(_BYTE *)(a1 + 348) )
  {
    if ( (*(_BYTE *)(a1 + 348) & 0xF) != 0 )
      *(_DWORD *)(a1 + 812) = KeTickCount;
    *(_BYTE *)(a1 + 348) = 0;
  }
  if ( a2 != *(char *)(a1 + 123) )
  {
    if ( a1 == v8 )
    {
      if ( *(_BYTE *)(v7 + 16) )
      {
        v36 = *(_DWORD *)(a1 + 52);
        v37 = *(_DWORD *)(a1 + 48);
      }
      else
      {
        __disable_irq();
        *(_BYTE *)(v7 + 16) = 1;
        LODWORD(v11) = ReadTimeStampCounter();
        v12 = (unsigned __int64 *)(a1 + 48);
        v14 = v11 - *(_QWORD *)(v7 + 2376);
        v13 = v14;
        v15 = v11;
        v16 = *(_QWORD *)(a1 + 48) + v14;
        v116 = HIDWORD(v14);
        v117 = HIDWORD(v16);
        v121 = v14;
        v118 = v16;
        __dmb(0xBu);
        do
          v17 = __ldrexd(v12);
        while ( __strexd(v16, v12) );
        __dmb(0xBu);
        v18 = v14 + *(unsigned int *)(a1 + 56);
        if ( HIDWORD(v18) )
        {
          v122 = 0;
          LODWORD(v18) = -1;
        }
        *(_QWORD *)(v7 + 2376) = v15;
        v19 = *(_BYTE *)(a1 + 2);
        *(_DWORD *)(a1 + 56) = v18;
        if ( (v19 & 0x3E) != 0 )
        {
          if ( (v19 & 0x10) != 0 )
          {
            v95 = v7 + 8 * *(unsigned __int8 *)(a1 + 84);
            *(_QWORD *)(v95 + 2392) = *(_QWORD *)(v95 + 2392) - *(_QWORD *)(v7 + 2384) + *(_QWORD *)(v7 + 2376);
            *(_DWORD *)(v7 + 2384) = 0;
            *(_DWORD *)(v7 + 2388) = 0;
            v19 &= 0xEFu;
          }
          if ( (v19 & 0x3E) != 0 )
          {
            if ( (v19 & 0x20) != 0 )
            {
              v20 = *(_DWORD *)(a1 + 1084);
              if ( v20 )
              {
                v13 = v121;
                v21 = v116;
                v22 = (unsigned __int64 *)(v20 + 8 * (*(unsigned __int8 *)(v7 + 2986) + 2 * PoGetFrequencyBucket(v7)));
                v23 = *v22 + __PAIR64__(v116, v121);
                __dmb(0xBu);
                do
                  v24 = __ldrexd(v22);
                while ( __strexd(v23, v22) );
                __dmb(0xBu);
              }
              else
              {
                v21 = v116;
              }
              v19 &= 0xDFu;
            }
            else
            {
              v21 = v116;
            }
            if ( (v19 & 0x3E) != 0 )
            {
              v84 = *(_DWORD *)(a1 + 68);
              if ( v84 )
              {
                for ( i = v84 + *(_DWORD *)(v7 + 2352); i; i = *(_DWORD *)(i + 236) )
                  *(_QWORD *)i += __PAIR64__(v21, v13);
              }
              if ( (*(_BYTE *)(a1 + 2) & 8) != 0
                && (*(_DWORD *)(*(_DWORD *)(v7 + 2360) + 260) & *(_DWORD *)(a1 + 356)) != *(_DWORD *)(*(_DWORD *)(v7 + 2360) + 260) )
              {
                *(_QWORD *)(v7 + 2368) += __PAIR64__(v21, v13);
              }
              if ( *(_DWORD *)(a1 + 236) )
                KiEndCounterAccumulation(a1);
            }
          }
        }
        v25 = ReadTimeStampCounter();
        v27 = v26;
        v28 = v25;
        v29 = __PAIR64__(v27, v25) - *(_QWORD *)(v7 + 2376);
        v121 = v25;
        __dmb(0xBu);
        v30 = (unsigned __int64 *)(v7 + 2744);
        do
          v31 = __ldrexd(v30);
        while ( __strexd(v31 + v29, v30) );
        __dmb(0xBu);
        if ( (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
        {
          v32 = __PAIR64__(v27, v25) - *(_QWORD *)(v7 + 2376);
          v33 = (unsigned __int64 *)(v7 + 8 * (*(unsigned __int8 *)(v7 + 2986) + 2 * (PoGetFrequencyBucket(v7) + 1144)));
          v34 = *v33 + v32;
          __dmb(0xBu);
          do
            v35 = __ldrexd(v33);
          while ( __strexd(v34, v33) );
          __dmb(0xBu);
          v28 = v121;
        }
        *(_DWORD *)(v7 + 2376) = v28;
        *(_DWORD *)(v7 + 2380) = v27;
        if ( (*(_BYTE *)(a1 + 2) & 0x10) != 0 )
        {
          *(_DWORD *)(v7 + 2384) = v28;
          *(_DWORD *)(v7 + 2388) = v27;
        }
        if ( (*(_BYTE *)(a1 + 2) & 2) != 0 )
          KiBeginCounterAccumulation(a1, 0);
        v36 = v117;
        v37 = v118;
        *(_BYTE *)(v7 + 16) = 0;
        __enable_irq();
        v9 = (unsigned int *)(a1 + 44);
      }
      v38 = 0;
    }
    else
    {
      v54 = (unsigned __int64 *)(a1 + 48);
      while ( 1 )
      {
        v55 = *(_DWORD *)(a1 + 52);
        v56 = *(_DWORD *)v54;
        v117 = v55;
        v118 = v56;
        do
          v57 = __ldrexd(v54);
        while ( __PAIR64__(v57, HIDWORD(v57)) == __PAIR64__(v56, v55) && __strexd(__PAIR64__(v55, v56), v54) );
        if ( __PAIR64__(v56, v55) == __PAIR64__(v57, HIDWORD(v57)) )
          break;
        __dmb(0xAu);
        __yield();
      }
      v7 = v121;
      v36 = v117;
      v37 = v118;
      v38 = 1;
      v9 = (unsigned int *)(a1 + 44);
    }
    v39 = __PAIR64__(v36, v37) + KiCyclesPerClockQuantum * (unsigned int)*(unsigned __int8 *)(a1 + 403);
    if ( (*(_DWORD *)(a1 + 80) & 0x10) != 0 )
    {
      __dmb(0xBu);
      v93 = (unsigned __int8 *)(a1 + 80);
      do
        v94 = __ldrex(v93);
      while ( __strex(v94 & 0xEF, v93) );
      __dmb(0xBu);
    }
    if ( v38 )
    {
      __dmb(0xBu);
      v58 = (unsigned __int64 *)(a1 + 24);
      do
        v59 = __ldrexd(v58);
      while ( __strexd(v39, v58) );
      __dmb(0xBu);
    }
    else
    {
      *(_QWORD *)(a1 + 24) = v39;
    }
    if ( !a2 )
      a2 = *(_BYTE *)(a1 + 347) != 0;
    if ( *(char *)(a1 + 347) >= 16 && a2 < 16 )
      goto LABEL_62;
    v40 = *(_DWORD *)(a1 + 800);
    v41 = (char)a2;
    if ( v40 )
    {
      v96 = 31 - __clz(v40);
      if ( (char)a2 < v96 )
        v41 = (char)v96;
    }
    if ( *(char *)(a1 + 123) == v41 )
      goto LABEL_62;
    v42 = KiAcquireThreadStateLock(a1, &v116, &v121);
    v118 = 1;
    v43 = *(_BYTE *)(a1 + 123);
    v44 = (_DWORD *)v121;
    v45 = v116;
    v117 = v43;
    switch ( v42 )
    {
      case 2:
        if ( *(_DWORD *)(v116 + 8) )
          v118 = 0;
        KiAbProcessThreadPriorityModification(a1, v41, 1);
        v46 = v118;
        *(_BYTE *)(a1 + 123) = v41;
        if ( v46 )
        {
          if ( (*(_BYTE *)(a1 + 2) & 4) != 0 )
          {
            if ( v41 < 16
              && *(_DWORD *)(a1 + 68)
              && (v86 = *(_DWORD *)(a1 + 68)) != 0
              && (v87 = *(_DWORD *)(v45 + 2352) + v86) != 0
              && KiGetThreadEffectiveRankNonZero(a1, v87, 0) )
            {
              v47 = 1;
            }
            else
            {
              v47 = *(_BYTE *)(a1 + 123);
            }
          }
          else
          {
            v47 = v41;
          }
          **(_BYTE **)(v45 + 28) = v47;
          v46 = v118;
        }
        if ( v41 < v117 && v46 )
        {
          if ( *(_BYTE *)(a1 + 132) == 2 )
          {
            v48 = KiSelectReadyThreadEx((_DWORD *)v45, a1, 0);
            v49 = v48;
            if ( v48 )
            {
              if ( (*(_BYTE *)(v48 + 2) & 4) != 0 )
              {
                if ( *(char *)(v48 + 123) < 16
                  && *(_DWORD *)(v48 + 68)
                  && (v91 = *(_DWORD *)(v48 + 68)) != 0
                  && (v92 = *(_DWORD *)(v45 + 2352) + v91) != 0
                  && KiGetThreadEffectiveRankNonZero(v48, v92, 0) )
                {
                  v88 = 1;
                }
                else
                {
                  v88 = *(_BYTE *)(v49 + 123);
                }
              }
              else
              {
                v88 = *(_BYTE *)(v48 + 123);
              }
              **(_BYTE **)(v45 + 28) = v88;
              *(_DWORD *)(v45 + 8) = v49;
              *(_BYTE *)(v49 + 132) = 3;
              v50 = 1;
              goto LABEL_57;
            }
          }
          else if ( *(_DWORD *)(v45 + 1932) >> (v41 + 1) )
          {
            *(_BYTE *)(a1 + 72) |= 0x10u;
          }
        }
        break;
      case 1:
        KiRemoveThreadFromAnyReadyQueue(v116, v121, a1, v43);
        KiAbProcessThreadPriorityModification(a1, v41, 1);
        *(_BYTE *)(a1 + 123) = v41;
        KiPrepareReadyThreadForRescheduling(a1, v41, (_DWORD *)&v119 + 1);
        LODWORD(v119) = HIDWORD(v119);
        break;
      case 3:
        KiAbProcessThreadPriorityModification(a1, v41, 1);
        v61 = *(_BYTE *)(a1 + 2);
        *(_BYTE *)(a1 + 123) = v41;
        if ( (v61 & 4) != 0 )
        {
          if ( v41 < 16
            && *(_DWORD *)(a1 + 68)
            && (v97 = *(_DWORD *)(a1 + 68)) != 0
            && (v98 = *(_DWORD *)(v45 + 2352) + v97) != 0
            && KiGetThreadEffectiveRankNonZero(a1, v98, 0) )
          {
            v99 = 1;
          }
          else
          {
            v99 = *(_BYTE *)(a1 + 123);
          }
          v62 = v99;
        }
        else
        {
          v62 = v41;
        }
        **(_BYTE **)(v45 + 28) = v62;
        if ( v41 < v117 )
        {
          v63 = KiSelectReadyThreadEx((_DWORD *)v45, a1, 0);
          v64 = v63;
          if ( v63 )
          {
            if ( (*(_BYTE *)(v63 + 2) & 4) != 0 )
            {
              if ( *(char *)(v63 + 123) < 16
                && *(_DWORD *)(v63 + 68)
                && (v101 = *(_DWORD *)(v63 + 68)) != 0
                && (v102 = *(_DWORD *)(v45 + 2352) + v101) != 0
                && KiGetThreadEffectiveRankNonZero(v63, v102, 0) )
              {
                v103 = 1;
              }
              else
              {
                v103 = *(_BYTE *)(v64 + 123);
              }
              v100 = v103;
            }
            else
            {
              v100 = *(_BYTE *)(v63 + 123);
            }
            **(_BYTE **)(v45 + 28) = v100;
            *(_DWORD *)(v45 + 8) = v64;
            *(_BYTE *)(v64 + 132) = 3;
            *(_BYTE *)(a1 + 132) = 7;
            *(_DWORD *)(a1 + 144) = 0;
            LODWORD(v119) = a1 + 144;
          }
        }
        break;
      default:
        KiAbProcessThreadPriorityModification(a1, v41, 1);
        *(_BYTE *)(a1 + 123) = v41;
        break;
    }
    v50 = 0;
LABEL_57:
    KiUpdateSharedReadyQueueAffinityThread(0, a1);
    if ( v45 )
    {
      __dmb(0xBu);
      *(_DWORD *)(v45 + 24) = 0;
    }
    if ( v44 )
    {
      __dmb(0xBu);
      *v44 = 0;
    }
    if ( v50 )
    {
      v89 = *(_DWORD *)(v45 + 20);
      if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) != v89 )
      {
        v104 = (int)*(&KiProcessorBlock + v89);
        __dmb(0xBu);
        v105 = (unsigned int *)(v104 + 1676);
        do
          v106 = __ldrex(v105);
        while ( __strex(v106 | 2, v105) );
        __dmb(0xBu);
        v107 = (unsigned int)KeGetPcr();
        ++*(_DWORD *)((v107 & 0xFFFFF000) + 0x1414);
        HalSendSoftwareInterrupt(v89, 2);
      }
    }
LABEL_62:
    v5 = v115;
  }
  __dmb(0xBu);
  v51 = (_DWORD *)v119;
  *v9 = 0;
  while ( v51 )
  {
    v90 = v51 - 36;
    v51 = (_DWORD *)*v51;
    KiDeferredReadyThread(v7, v90);
  }
  v52 = *(_DWORD *)(v7 + 8);
  if ( v5 >= 2 )
  {
    if ( v52 && !*(_BYTE *)(v7 + 1754) )
      HalRequestSoftwareInterrupt(2);
    goto LABEL_66;
  }
  v60 = *(_DWORD *)(v7 + 4);
  if ( v52 )
  {
    KiAbProcessContextSwitch(*(_DWORD *)(v7 + 4), 0);
    v65 = (unsigned int *)(v7 + 24);
    while ( 1 )
    {
      do
        v66 = __ldrex(v65);
      while ( __strex(1u, v65) );
      __dmb(0xBu);
      if ( !v66 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v65 );
    }
    v118 = *(_DWORD *)(v7 + 8);
    *(_DWORD *)(v7 + 8) = 0;
    __disable_irq();
    *(_BYTE *)(v7 + 16) = 1;
    LODWORD(v69) = ReadTimeStampCounter();
    v67 = *(_DWORD *)(v7 + 2376);
    v68 = *(_DWORD *)(v7 + 2380);
    v121 = v69;
    v71 = (unsigned __int64 *)(v60 + 48);
    v70 = (v69 - __PAIR64__(v68, v67)) >> 32;
    LODWORD(v69) = v69 - v67;
    v72 = *(_DWORD *)(v60 + 52);
    v73 = *(_DWORD *)(v60 + 48);
    v119 = __PAIR64__(v70, v69);
    __dmb(0xBu);
    do
      v74 = __ldrexd(v71);
    while ( __strexd(__PAIR64__(v72, v69) + __PAIR64__(v70, v73), v71) );
    __dmb(0xBu);
    v75 = __PAIR64__(v70, *(_DWORD *)(v60 + 56)) + (unsigned int)v69;
    if ( HIDWORD(v75) )
    {
      v122 = 0;
      LODWORD(v75) = -1;
    }
    HIDWORD(v75) = v121;
    *(_DWORD *)(v7 + 2380) = HIDWORD(v69);
    *(_DWORD *)(v7 + 2376) = HIDWORD(v75);
    v76 = *(_BYTE *)(v60 + 2);
    *(_DWORD *)(v60 + 56) = v75;
    if ( (v76 & 0x3E) != 0 )
    {
      if ( (v76 & 0x10) != 0 )
      {
        v108 = *(_DWORD *)(v7 + 2376);
        v109 = v7 + 8 * *(unsigned __int8 *)(v60 + 84);
        v110 = *(_DWORD *)(v7 + 2384);
        v76 &= 0xEFu;
        v111 = v108 >= v110;
        HIDWORD(v69) = v108 - v110;
        v112 = *(_DWORD *)(v109 + 2392);
        LODWORD(v69) = *(_DWORD *)(v7 + 2380) - (*(_DWORD *)(v7 + 2388) + !v111);
        v113 = *(_DWORD *)(v109 + 2396);
        *(_DWORD *)(v109 + 2392) = v112 + HIDWORD(v69);
        v114 = v69 + __CFADD__(v112, HIDWORD(v69)) + v113;
        LODWORD(v69) = v119;
        *(_DWORD *)(v109 + 2396) = v114;
        *(_DWORD *)(v7 + 2384) = 0;
        *(_DWORD *)(v7 + 2388) = 0;
      }
      if ( (v76 & 0x3E) != 0 )
      {
        if ( (v76 & 0x20) != 0 )
        {
          v77 = *(_DWORD *)(v60 + 1084);
          if ( v77 )
          {
            v78 = PoGetFrequencyBucket(v7);
            v70 = HIDWORD(v119);
            v79 = (unsigned __int64 *)(v77 + 8 * (*(unsigned __int8 *)(v7 + 2986) + 2 * v78));
            v80 = *v79 + v119;
            __dmb(0xBu);
            do
              v81 = __ldrexd(v79);
            while ( __strexd(v80, v79) );
            __dmb(0xBu);
            LODWORD(v69) = v119;
          }
          v76 &= 0xDFu;
        }
        if ( (v76 & 0x3E) != 0 )
        {
          v82 = *(_DWORD *)(v60 + 68);
          if ( v82 )
          {
            for ( HIDWORD(v69) = v82 + *(_DWORD *)(v7 + 2352); HIDWORD(v69); HIDWORD(v69) = *(_DWORD *)(HIDWORD(v69) + 236) )
              *(_QWORD *)HIDWORD(v69) += __PAIR64__(v70, v69);
          }
          if ( (*(_BYTE *)(v60 + 2) & 8) != 0
            && (*(_DWORD *)(v60 + 356) & *(_DWORD *)(*(_DWORD *)(v7 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v7 + 2360)
                                                                                                 + 260) )
          {
            *(_QWORD *)(v7 + 2368) += __PAIR64__(v70, v69);
          }
          if ( *(_DWORD *)(v60 + 236) )
            KiEndCounterAccumulation(v60);
        }
      }
    }
    v83 = v118;
    v5 = v115;
    __enable_irq();
    *(_DWORD *)(v7 + 4) = v83;
    *(_BYTE *)(v83 + 132) = 2;
    *(_BYTE *)(v60 + 395) = 32;
    *(_BYTE *)(v60 + 134) = v5;
    KiQueueReadyThread(v7, v60);
    if ( !KiSwapContext(v60, v83, v5) )
      goto LABEL_80;
    goto LABEL_141;
  }
  if ( (*(_DWORD *)(v60 + 76) & 0x40) != 0 )
  {
LABEL_141:
    KfLowerIrql(1);
    *(_DWORD *)(v60 + 76) &= 0xFFFFFFBF;
    KiDeliverApc(0, 0, 0);
  }
LABEL_80:
  KfLowerIrql(v5);
LABEL_66:
  v53 = v120;
  if ( (dword_682604 & 0x2000) != 0 )
    EtwTracePriority(a1, 1328, v120, a2, 0);
  return v53;
}
