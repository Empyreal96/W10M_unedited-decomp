// NtYieldExecution 
 
int NtYieldExecution()
{
  unsigned int v0; // r3
  int v2; // r4
  int v3; // r8
  unsigned int v4; // r3
  unsigned int v5; // r7
  int v6; // r0
  unsigned int *v7; // r6
  unsigned int v8; // r2
  unsigned int *v9; // r5
  unsigned int v10; // r2
  int v11; // r9
  int v12; // r5
  __int64 v13; // r0
  __int64 v14; // kr10_8
  unsigned __int64 *v15; // lr
  unsigned __int64 v16; // r2
  unsigned int v17; // lr
  int v18; // r2
  char v19; // r5
  int v20; // r4
  unsigned __int64 *v21; // r4
  unsigned __int64 v22; // kr20_8
  unsigned __int64 v23; // kr28_8
  __int64 v24; // kr30_8
  unsigned int v25; // lr
  __int64 v26; // r0
  unsigned __int64 v27; // kr38_8
  unsigned __int64 v28; // kr40_8
  unsigned __int64 *v29; // r4
  unsigned __int64 v30; // kr48_8
  unsigned __int64 v31; // kr50_8
  unsigned __int64 v32; // kr58_8
  int v33; // r4
  unsigned int v34; // r3
  __int64 v35; // r0
  __int64 v36; // kr60_8
  unsigned __int64 v37; // kr70_8
  unsigned __int64 *v38; // r6
  unsigned __int64 v39; // kr78_8
  unsigned int v40; // r6
  __int64 v41; // r2
  char v42; // lr
  int v43; // r4
  unsigned int v44; // r5
  unsigned __int64 *v45; // r4
  unsigned __int64 v46; // kr80_8
  unsigned __int64 v47; // kr88_8
  char v48; // r2
  int v49; // r1
  int v50; // r1
  unsigned int v51; // r0
  int v52; // r1
  int i; // r1
  unsigned __int8 *v54; // r3
  unsigned int v55; // r2
  int v56; // r2
  int v57; // r1
  unsigned int v58; // r1
  unsigned int v59; // r4
  unsigned int v60; // r3
  bool v61; // cf
  unsigned int v62; // r1
  int v63; // r3
  int v64; // r0
  int v65; // r2
  signed int v66; // r3
  unsigned int v67; // r6
  unsigned int v68; // [sp+0h] [bp-40h]
  unsigned __int64 v69; // [sp+4h] [bp-3Ch]
  char v70; // [sp+4h] [bp-3Ch]
  int v71; // [sp+Ch] [bp-34h]
  int v72; // [sp+10h] [bp-30h]

  v0 = (unsigned int)KeGetPcr();
  if ( *(_DWORD *)((v0 & 0xFFFFF000) + 0xD0C) || !*(_DWORD *)(*(_DWORD *)((v0 & 0xFFFFF000) + 0x1304) + 4) )
    return 1073741860;
  v2 = 1073741860;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v71 = KfRaiseIrql(2);
  v4 = (unsigned int)KeGetPcr();
  v5 = (v4 & 0xFFFFF000) + 1408;
  if ( *(_DWORD *)((v4 & 0xFFFFF000) + 0xD0C) || *(_DWORD *)(*(_DWORD *)((v4 & 0xFFFFF000) + 0x1304) + 4) )
  {
    v6 = KiAbProcessContextSwitch(v3, 0);
    v7 = (unsigned int *)(v3 + 44);
    do
      v8 = __ldrex(v7);
    while ( __strex(1u, v7) );
    __dmb(0xBu);
    if ( v8 )
      return sub_529354(v6, 1);
    v9 = (unsigned int *)(v5 + 24);
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
    v11 = *(_DWORD *)(v5 + 8);
    if ( v11 || (v11 = KiSelectReadyThreadEx(v5, 0, 1)) != 0 )
    {
      if ( *(_BYTE *)(v5 + 16) )
      {
        v69 = *(_QWORD *)(v3 + 48);
      }
      else
      {
        __disable_irq();
        *(_BYTE *)(v5 + 16) = 1;
        LODWORD(v13) = ReadTimeStampCounter();
        v14 = v13 - *(_QWORD *)(v5 + 2376);
        v69 = *(_QWORD *)(v3 + 48) + v14;
        __dmb(0xBu);
        v15 = (unsigned __int64 *)(v3 + 48);
        do
          v16 = __ldrexd(v15);
        while ( __strexd(v69, v15) );
        __dmb(0xBu);
        v17 = v14;
        v7 = (unsigned int *)(v3 + 44);
        v18 = *(_DWORD *)(v3 + 56) + v14;
        if ( (v14 + (unsigned __int64)*(unsigned int *)(v3 + 56)) >> 32 )
          v18 = -1;
        *(_QWORD *)(v5 + 2376) = v13;
        v19 = *(_BYTE *)(v3 + 2);
        *(_DWORD *)(v3 + 56) = v18;
        if ( (v19 & 0x3E) != 0 )
        {
          if ( (v19 & 0x10) != 0 )
          {
            v58 = *(_DWORD *)(v5 + 2376);
            v59 = v5 + 8 * *(unsigned __int8 *)(v3 + 84);
            v60 = *(_DWORD *)(v5 + 2384);
            v19 &= 0xEFu;
            v61 = v58 >= v60;
            v62 = v58 - v60;
            v63 = *(_DWORD *)(v59 + 2392);
            v64 = *(_DWORD *)(v5 + 2380) - (*(_DWORD *)(v5 + 2388) + !v61);
            v65 = *(_DWORD *)(v59 + 2396);
            *(_DWORD *)(v59 + 2392) = v63 + v62;
            *(_DWORD *)(v59 + 2396) = v64 + __CFADD__(v63, v62) + v65;
            *(_DWORD *)(v5 + 2384) = 0;
            *(_DWORD *)(v5 + 2388) = 0;
          }
          if ( (v19 & 0x3E) != 0 )
          {
            if ( (v19 & 0x20) != 0 )
            {
              v20 = *(_DWORD *)(v3 + 1084);
              if ( v20 )
              {
                v17 = v14;
                v21 = (unsigned __int64 *)(v20 + 8 * (*(unsigned __int8 *)(v5 + 2986) + 2 * PoGetFrequencyBucket(v5)));
                v22 = *v21 + v14;
                __dmb(0xBu);
                do
                  v23 = __ldrexd(v21);
                while ( __strexd(v22, v21) );
                __dmb(0xBu);
              }
              v19 &= 0xDFu;
            }
            if ( (v19 & 0x3E) != 0 )
            {
              v49 = *(_DWORD *)(v3 + 68);
              if ( v49 && (v50 = v49 + *(_DWORD *)(v5 + 2352)) != 0 )
              {
                v51 = HIDWORD(v14);
                do
                {
                  *(_QWORD *)v50 += __PAIR64__(HIDWORD(v14), v17);
                  v50 = *(_DWORD *)(v50 + 236);
                }
                while ( v50 );
              }
              else
              {
                v51 = HIDWORD(v14);
              }
              if ( (*(_BYTE *)(v3 + 2) & 8) != 0
                && (*(_DWORD *)(*(_DWORD *)(v5 + 2360) + 260) & *(_DWORD *)(v3 + 356)) != *(_DWORD *)(*(_DWORD *)(v5 + 2360) + 260) )
              {
                *(_QWORD *)(v5 + 2368) += __PAIR64__(v51, v17);
              }
              if ( *(_DWORD *)(v3 + 236) )
                KiEndCounterAccumulation(v3);
            }
          }
        }
        LODWORD(v26) = ReadTimeStampCounter();
        v72 = HIDWORD(v26);
        v24 = v26 - *(_QWORD *)(v5 + 2376);
        v25 = v26;
        v68 = v26;
        __dmb(0xBu);
        LODWORD(v26) = v5 + 2744;
        do
          v27 = __ldrexd((unsigned __int64 *)v26);
        while ( __strexd(v27 + v24, (unsigned __int64 *)v26) );
        __dmb(0xBu);
        if ( (*(_BYTE *)(v3 + 2) & 0x20) != 0 )
        {
          v28 = __PAIR64__(HIDWORD(v26), v25) - *(_QWORD *)(v5 + 2376);
          v29 = (unsigned __int64 *)(v5 + 8 * (*(unsigned __int8 *)(v5 + 2986) + 2 * (PoGetFrequencyBucket(v5) + 1144)));
          v30 = *v29 + v28;
          __dmb(0xBu);
          do
            v31 = __ldrexd(v29);
          while ( __strexd(v30, v29) );
          __dmb(0xBu);
          HIDWORD(v26) = v72;
          v25 = v68;
          v7 = (unsigned int *)(v3 + 44);
        }
        *(_DWORD *)(v5 + 2376) = v25;
        *(_DWORD *)(v5 + 2380) = HIDWORD(v26);
        if ( (*(_BYTE *)(v3 + 2) & 0x10) != 0 )
        {
          *(_DWORD *)(v5 + 2384) = v25;
          *(_DWORD *)(v5 + 2388) = HIDWORD(v26);
        }
        if ( (*(_BYTE *)(v3 + 2) & 2) != 0 )
          KiBeginCounterAccumulation(v3, 0);
        *(_BYTE *)(v5 + 16) = 0;
        __enable_irq();
      }
      v32 = v69 + KiCyclesPerClockQuantum * (unsigned int)*(unsigned __int8 *)(v3 + 403);
      if ( (*(_DWORD *)(v3 + 80) & 0x10) != 0 )
      {
        __dmb(0xBu);
        v54 = (unsigned __int8 *)(v3 + 80);
        do
          v55 = __ldrex(v54);
        while ( __strex(v55 & 0xEF, v54) );
        __dmb(0xBu);
      }
      *(_QWORD *)(v3 + 24) = v32;
      v33 = *(char *)(v3 + 123);
      if ( v33 < 16 )
      {
        v33 = (char)(-(*(_BYTE *)(v3 + 348) & 0xF) - (*(_BYTE *)(v3 + 348) >> 4) + v33 - 1);
        if ( v33 < *(char *)(v3 + 347) )
          v33 = *(char *)(v3 + 347);
        if ( *(_BYTE *)(v3 + 348) )
        {
          if ( (*(_BYTE *)(v3 + 348) & 0xF) != 0 )
            *(_DWORD *)(v3 + 812) = KeTickCount;
          *(_BYTE *)(v3 + 348) = 0;
        }
        v34 = *(_DWORD *)(v3 + 800);
        if ( v34 )
        {
          v66 = 31 - __clz(v34);
          if ( v33 < v66 )
            v33 = (char)v66;
        }
      }
      KiAbProcessThreadPriorityModification(v3, v33, 1);
      *(_BYTE *)(v3 + 123) = v33;
      __dmb(0xBu);
      *v7 = 0;
      *(_DWORD *)(v5 + 8) = 0;
      __disable_irq();
      *(_BYTE *)(v5 + 16) = 1;
      LODWORD(v35) = ReadTimeStampCounter();
      v36 = v35 - *(_QWORD *)(v5 + 2376);
      v37 = *(_QWORD *)(v3 + 48) + v36;
      __dmb(0xBu);
      v38 = (unsigned __int64 *)(v3 + 48);
      do
        v39 = __ldrexd(v38);
      while ( __strexd(v37, v38) );
      __dmb(0xBu);
      v40 = v36;
      v41 = v36 + *(unsigned int *)(v3 + 56);
      if ( HIDWORD(v41) )
        LODWORD(v41) = -1;
      *(_QWORD *)(v5 + 2376) = v35;
      v42 = *(_BYTE *)(v3 + 2);
      *(_DWORD *)(v3 + 56) = v41;
      v70 = v42;
      if ( (v42 & 0x3E) != 0 )
      {
        if ( (v42 & 0x10) != 0 )
        {
          v67 = v5 + 8 * *(unsigned __int8 *)(v3 + 84);
          v42 &= 0xEFu;
          *(_QWORD *)(v67 + 2392) = *(_QWORD *)(v67 + 2392) - *(_QWORD *)(v5 + 2384) + *(_QWORD *)(v5 + 2376);
          v40 = v36;
          *(_DWORD *)(v5 + 2384) = 0;
          *(_DWORD *)(v5 + 2388) = 0;
          v70 = v42;
        }
        if ( (v42 & 0x3E) != 0 )
        {
          if ( (v42 & 0x20) != 0 )
          {
            v43 = *(_DWORD *)(v3 + 1084);
            if ( v43 )
            {
              v44 = HIDWORD(v36);
              v45 = (unsigned __int64 *)(v43 + 8 * (*(unsigned __int8 *)(v5 + 2986) + 2 * PoGetFrequencyBucket(v5)));
              v46 = *v45 + __PAIR64__(HIDWORD(v36), v40);
              __dmb(0xBu);
              do
                v47 = __ldrexd(v45);
              while ( __strexd(v46, v45) );
              __dmb(0xBu);
              v42 = v70;
            }
            else
            {
              v44 = HIDWORD(v36);
            }
            v42 &= 0xDFu;
          }
          else
          {
            v44 = HIDWORD(v36);
          }
          if ( (v42 & 0x3E) != 0 )
          {
            v52 = *(_DWORD *)(v3 + 68);
            if ( v52 )
            {
              for ( i = v52 + *(_DWORD *)(v5 + 2352); i; i = *(_DWORD *)(i + 236) )
                *(_QWORD *)i += __PAIR64__(v44, v40);
            }
            if ( (*(_BYTE *)(v3 + 2) & 8) != 0
              && (*(_DWORD *)(*(_DWORD *)(v5 + 2360) + 260) & *(_DWORD *)(v3 + 356)) != *(_DWORD *)(*(_DWORD *)(v5 + 2360)
                                                                                                  + 260) )
            {
              *(_QWORD *)(v5 + 2368) += __PAIR64__(v44, v40);
            }
            if ( *(_DWORD *)(v3 + 236) )
              KiEndCounterAccumulation(v3);
          }
        }
      }
      __enable_irq();
      if ( (*(_BYTE *)(v11 + 2) & 4) != 0 )
      {
        if ( *(char *)(v11 + 123) < 16
          && *(_DWORD *)(v11 + 68)
          && (v56 = *(_DWORD *)(v11 + 68)) != 0
          && (v57 = v56 + *(_DWORD *)(v5 + 2352)) != 0
          && KiGetThreadEffectiveRankNonZero(v11, v57, 0) )
        {
          v48 = 1;
        }
        else
        {
          v48 = *(_BYTE *)(v11 + 123);
        }
      }
      else
      {
        v48 = *(_BYTE *)(v11 + 123);
      }
      v12 = v71;
      **(_BYTE **)(v5 + 28) = v48;
      *(_DWORD *)(v5 + 4) = v11;
      *(_BYTE *)(v11 + 132) = 2;
      *(_BYTE *)(v3 + 395) = 33;
      *(_BYTE *)(v3 + 134) = v71;
      KiQueueReadyThread(v5, v3);
      KiSwapContext(v3, v11, 1);
      v2 = 0;
      goto LABEL_17;
    }
    __dmb(0xBu);
    *v9 = 0;
    __dmb(0xBu);
    *v7 = 0;
  }
  v12 = v71;
LABEL_17:
  KfLowerIrql(v12);
  return v2;
}
