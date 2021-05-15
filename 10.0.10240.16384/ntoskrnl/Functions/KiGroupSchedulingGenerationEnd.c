// KiGroupSchedulingGenerationEnd 
 
int __fastcall KiGroupSchedulingGenerationEnd(int a1, int a2, int a3, int a4, unsigned __int8 a5)
{
  __int64 v6; // r0
  int v7; // r9
  unsigned __int64 *v8; // r6
  unsigned int v9; // lr
  __int64 v10; // kr08_8
  unsigned __int64 v11; // kr18_8
  unsigned __int64 v12; // kr20_8
  __int64 v13; // r2
  __int64 v14; // r0
  char v15; // r10
  int v16; // r4
  unsigned int v17; // r5
  unsigned __int64 *v18; // r4
  unsigned __int64 v19; // kr40_8
  int v20; // r4
  int v21; // r5
  int v22; // r0
  int v23; // r0
  int v24; // r6
  int v25; // r8
  __int64 v26; // kr48_8
  int v27; // r10
  unsigned __int64 *v28; // r3
  unsigned __int64 v29; // kr50_8
  unsigned int v30; // r4
  unsigned int v31; // r6
  int v32; // r5
  unsigned __int64 v33; // kr70_8
  char v34; // r2
  char v35; // r2
  int v36; // r0
  int v37; // r2
  unsigned int *v38; // r5
  unsigned int *v39; // r1
  unsigned int v40; // r2
  unsigned int v41; // r6
  unsigned int v42; // r2
  int v43; // r2
  int v44; // r1
  char v45; // r3
  int v46; // r5
  int v47; // r1
  _DWORD *v48; // r2
  int v49; // r6
  int v50; // r2
  int v51; // r1
  int v53; // [sp+Ch] [bp-3Ch]
  int v54; // [sp+14h] [bp-34h]
  int v55; // [sp+18h] [bp-30h]

  HIDWORD(v6) = *(_DWORD *)(a1 + 12);
  v7 = *(_DWORD *)(a1 + 4);
  v54 = a4;
  v55 = a3;
  v53 = 0;
  if ( v7 == HIDWORD(v6) )
  {
    HIDWORD(v6) = 1;
    v53 = 1;
  }
  if ( !a5 )
  {
    __disable_irq();
    *(_BYTE *)(a1 + 16) = 1;
    LODWORD(v6) = ReadTimeStampCounter();
    v8 = (unsigned __int64 *)(v7 + 48);
    v10 = v6 - *(_QWORD *)(a1 + 2376);
    v9 = v10;
    v11 = *(_QWORD *)(v7 + 48) + v10;
    __dmb(0xBu);
    do
      v12 = __ldrexd(v8);
    while ( __strexd(v11, v8) );
    __dmb(0xBu);
    v13 = v10 + *(unsigned int *)(v7 + 56);
    if ( HIDWORD(v13) )
    {
      LODWORD(v14) = sub_52BDA0();
      return v14;
    }
    *(_QWORD *)(a1 + 2376) = v6;
    v15 = *(_BYTE *)(v7 + 2);
    *(_DWORD *)(v7 + 56) = v13;
    if ( (v15 & 0x3E) != 0 )
    {
      if ( (v15 & 0x10) != 0 )
      {
        v49 = a1 + 8 * *(unsigned __int8 *)(v7 + 84);
        HIDWORD(v6) = 0;
        *(_QWORD *)(v49 + 2392) = *(_QWORD *)(v49 + 2392) - *(_QWORD *)(a1 + 2384) + *(_QWORD *)(a1 + 2376);
        *(_DWORD *)(a1 + 2384) = 0;
        *(_DWORD *)(a1 + 2388) = 0;
        v15 &= 0xEFu;
      }
      if ( (v15 & 0x3E) != 0 )
      {
        if ( (v15 & 0x20) != 0 )
        {
          v16 = *(_DWORD *)(v7 + 1084);
          if ( v16 )
          {
            v17 = HIDWORD(v10);
            v9 = v10;
            v18 = (unsigned __int64 *)(v16 + 8 * (*(unsigned __int8 *)(a1 + 2986) + 2 * PoGetFrequencyBucket(a1)));
            LODWORD(v6) = (*v18 + v10) >> 32;
            HIDWORD(v6) = *(_DWORD *)v18 + v10;
            __dmb(0xBu);
            do
              v19 = __ldrexd(v18);
            while ( __strexd(__PAIR64__(v6, HIDWORD(v6)), v18) );
            __dmb(0xBu);
          }
          else
          {
            v17 = HIDWORD(v10);
          }
          v15 &= 0xDFu;
        }
        else
        {
          v17 = HIDWORD(v10);
        }
        if ( (v15 & 0x3E) != 0 )
        {
          HIDWORD(v6) = *(_DWORD *)(v7 + 68);
          if ( HIDWORD(v6) )
          {
            for ( HIDWORD(v6) += *(_DWORD *)(a1 + 2352); HIDWORD(v6); HIDWORD(v6) = *(_DWORD *)(HIDWORD(v6) + 236) )
              *(_QWORD *)HIDWORD(v6) += __PAIR64__(v17, v9);
          }
          if ( (*(_BYTE *)(v7 + 2) & 8) != 0 )
          {
            HIDWORD(v6) = *(_DWORD *)(*(_DWORD *)(a1 + 2360) + 260);
            if ( (HIDWORD(v6) & *(_DWORD *)(v7 + 356)) != HIDWORD(v6) )
              *(_QWORD *)(a1 + 2368) += __PAIR64__(v17, v9);
          }
          if ( *(_DWORD *)(v7 + 236) )
            KiEndCounterAccumulation(v7);
        }
      }
    }
    a4 = v54;
    a3 = v55;
    __enable_irq();
  }
  LODWORD(v14) = KiTransitionSchedulingGroupGeneration(a1, HIDWORD(v6), a3, a4, a5);
  if ( a5 )
    return v14;
  v20 = *(_DWORD *)(a1 + 8);
  v21 = 0;
  if ( v20 && v20 != *(_DWORD *)(a1 + 12) )
  {
    *(_DWORD *)(a1 + 8) = 0;
    if ( (*(_BYTE *)(v7 + 2) & 4) != 0 )
    {
      if ( *(char *)(v7 + 123) < 16
        && *(_DWORD *)(v7 + 68)
        && (v50 = *(_DWORD *)(v7 + 68)) != 0
        && (v51 = *(_DWORD *)(a1 + 2352) + v50) != 0
        && KiGetThreadEffectiveRankNonZero(v7, v51, 0) )
      {
        v35 = 1;
      }
      else
      {
        v35 = *(_BYTE *)(v7 + 123);
      }
    }
    else
    {
      v35 = *(_BYTE *)(v7 + 123);
    }
    **(_BYTE **)(a1 + 28) = v35;
    *(_BYTE *)(v20 + 132) = 1;
    v36 = *(char *)(v20 + 123);
    *(_DWORD *)(v20 + 304) = KeTickCount;
    v37 = *(_DWORD *)(a1 + 3456);
    if ( (*(_DWORD *)(v20 + 80) & 0x1000) != 0 && v37 && (*(_DWORD *)(v20 + 356) & v37) == v37 )
    {
      v38 = *(unsigned int **)(a1 + 3460);
      v39 = &v38[2 * v36 + 2];
      while ( 1 )
      {
        do
          v40 = __ldrex(v38);
        while ( __strex(1u, v38) );
        __dmb(0xBu);
        if ( !v40 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v38 );
      }
      v41 = *v39;
      v42 = v20 + 144;
      *(_DWORD *)(v20 + 144) = *v39;
      *(_DWORD *)(v20 + 148) = v39;
      if ( *(unsigned int **)(v41 + 4) != v39 )
        __fastfail(3u);
      *(_DWORD *)(v41 + 4) = v42;
      *v39 = v42;
      *(_BYTE *)(a1 + (v36 >> 3) + 1936) &= ~(unsigned __int8)(1 << (v36 & 7));
      v38[1] |= 1 << v36;
      *(_DWORD *)(v20 + 328) |= 0x80000000;
      __dmb(0xBu);
      *v38 = 0;
    }
    else
    {
      v46 = *(_DWORD *)(a1 + 8 * (v36 + 256));
      v47 = v20 + 144;
      v48 = (_DWORD *)(a1 + 8 * (v36 + 256));
      *(_DWORD *)(v20 + 144) = v46;
      *(_DWORD *)(v20 + 148) = v48;
      if ( *(_DWORD **)(v46 + 4) != v48 )
        __fastfail(3u);
      *(_DWORD *)(v46 + 4) = v47;
      *v48 = v47;
      *(_BYTE *)(a1 + (v36 >> 3) + 1936) |= 1 << (v36 & 7);
      *(_DWORD *)(a1 + 1932) |= 1 << v36;
    }
    v21 = 1;
  }
  if ( v20 == *(_DWORD *)(a1 + 12) )
    goto LABEL_26;
  if ( v53 )
  {
    v22 = 0;
LABEL_25:
    v23 = KiSelectReadyThread(v22, a1);
    v24 = v23;
    if ( v23 )
    {
      if ( (*(_BYTE *)(v23 + 2) & 4) != 0 )
      {
        if ( *(char *)(v23 + 123) < 16
          && *(_DWORD *)(v23 + 68)
          && (v43 = *(_DWORD *)(v23 + 68)) != 0
          && (v44 = *(_DWORD *)(a1 + 2352) + v43) != 0
          && KiGetThreadEffectiveRankNonZero(v23, v44, 0) )
        {
          v45 = 1;
        }
        else
        {
          v45 = *(_BYTE *)(v24 + 123);
        }
        v34 = v45;
      }
      else
      {
        v34 = *(_BYTE *)(v23 + 123);
      }
      **(_BYTE **)(a1 + 28) = v34;
      *(_DWORD *)(a1 + 8) = v24;
      *(_BYTE *)(v24 + 132) = 3;
      --v21;
    }
LABEL_26:
    if ( v53 )
    {
      if ( v21 > 0 )
      {
        if ( (*(_BYTE *)(a1 + 19) & 1) != 0 )
          KiSetProcessorIdle(a1, 1, 1);
      }
      else if ( v21 < 0 && (*(_BYTE *)(a1 + 19) & 1) == 0 )
      {
        KiSetProcessorIdle(a1, 0, 0);
      }
    }
    goto LABEL_27;
  }
  v22 = *(char *)(v7 + 123);
  if ( v22 < 31 )
    goto LABEL_25;
LABEL_27:
  __disable_irq();
  LODWORD(v14) = ReadTimeStampCounter();
  v25 = HIDWORD(v14);
  v26 = v14 - *(_QWORD *)(a1 + 2376);
  v27 = v14;
  __dmb(0xBu);
  v28 = (unsigned __int64 *)(a1 + 2744);
  do
    v29 = __ldrexd(v28);
  while ( __strexd(v29 + v26, v28) );
  __dmb(0xBu);
  if ( (*(_BYTE *)(v7 + 2) & 0x20) != 0 )
  {
    v31 = (unsigned __int64)(v14 - *(_QWORD *)(a1 + 2376)) >> 32;
    v30 = v14 - *(_DWORD *)(a1 + 2376);
    v32 = a1 + 8 * (*(unsigned __int8 *)(a1 + 2986) + 2 * (PoGetFrequencyBucket(a1) + 1144));
    LODWORD(v14) = *(_DWORD *)(v32 + 4);
    HIDWORD(v14) = *(_DWORD *)v32;
    __dmb(0xBu);
    do
      v33 = __ldrexd((unsigned __int64 *)v32);
    while ( __strexd(__PAIR64__(v31, HIDWORD(v14)) + __PAIR64__(v14, v30), (unsigned __int64 *)v32) );
    __dmb(0xBu);
  }
  *(_DWORD *)(a1 + 2376) = v27;
  *(_DWORD *)(a1 + 2380) = v25;
  if ( (*(_BYTE *)(v7 + 2) & 0x10) != 0 )
  {
    *(_DWORD *)(a1 + 2384) = v27;
    *(_DWORD *)(a1 + 2388) = v25;
  }
  if ( (*(_BYTE *)(v7 + 2) & 2) != 0 )
    LODWORD(v14) = KiBeginCounterAccumulation(v7, 0);
  *(_BYTE *)(a1 + 16) = 0;
  __enable_irq();
  return v14;
}
