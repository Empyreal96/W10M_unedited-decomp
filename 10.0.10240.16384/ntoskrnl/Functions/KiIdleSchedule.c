// KiIdleSchedule 
 
int __fastcall KiIdleSchedule(int a1)
{
  unsigned int *v2; // r10
  unsigned int v3; // r2
  __int64 v4; // kr00_8
  __int64 v5; // r0
  unsigned __int64 *v6; // r6
  __int64 v7; // kr08_8
  unsigned int v8; // lr
  unsigned __int64 v9; // kr10_8
  unsigned __int64 v10; // kr18_8
  __int64 v11; // r2
  int result; // r0
  char v13; // r9
  int v14; // r4
  unsigned int v15; // r5
  int v16; // r1
  unsigned __int64 v17; // kr28_8
  int v18; // r8
  int v19; // r0
  unsigned int v20; // r1
  unsigned int v21; // r10
  int v22; // r1
  unsigned __int64 v23; // kr30_8
  unsigned __int64 *v24; // r3
  unsigned __int64 v25; // kr38_8
  unsigned __int64 v26; // kr40_8
  unsigned __int64 *v27; // r5
  unsigned __int64 v28; // kr48_8
  unsigned __int64 v29; // kr58_8
  int v30; // r6
  __int64 v31; // kr20_8
  unsigned __int64 *v32; // r4
  unsigned int v33; // r1
  unsigned __int64 v34; // kr68_8
  int i; // r1
  unsigned __int64 v36; // kr70_8
  unsigned int v37; // [sp+4h] [bp-2Ch]
  int v38; // [sp+4h] [bp-2Ch]

  v2 = (unsigned int *)(a1 + 24);
  while ( 1 )
  {
    do
      v3 = __ldrex(v2);
    while ( __strex(1u, v2) );
    __dmb(0xBu);
    if ( !v3 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v2 );
  }
  *(_BYTE *)(a1 + 1755) = 0;
  v4 = *(_QWORD *)(a1 + 8);
  if ( (_DWORD)v4 == HIDWORD(v4) )
    *(_DWORD *)(a1 + 8) = 0;
  __disable_irq();
  *(_BYTE *)(a1 + 16) = 1;
  LODWORD(v5) = ReadTimeStampCounter();
  v6 = (unsigned __int64 *)(HIDWORD(v4) + 48);
  v7 = v5 - *(_QWORD *)(a1 + 2376);
  v8 = v7;
  v37 = v5 - *(_DWORD *)(a1 + 2376);
  v9 = *(_QWORD *)(HIDWORD(v4) + 48) + v7;
  __dmb(0xBu);
  do
    v10 = __ldrexd(v6);
  while ( __strexd(v9, v6) );
  __dmb(0xBu);
  v11 = v7 + *(unsigned int *)(HIDWORD(v4) + 56);
  if ( HIDWORD(v11) )
    return sub_52FF6C();
  *(_QWORD *)(a1 + 2376) = v5;
  v13 = *(_BYTE *)(HIDWORD(v4) + 2);
  HIDWORD(v11) = 62;
  *(_DWORD *)(HIDWORD(v4) + 56) = v11;
  if ( (v13 & 0x3E) != 0 )
  {
    if ( (v13 & 0x10) != 0 )
    {
      v30 = a1 + 8 * *(unsigned __int8 *)(HIDWORD(v4) + 84);
      v31 = *(_QWORD *)(v30 + 2392) - *(_QWORD *)(a1 + 2384) + *(_QWORD *)(a1 + 2376);
      v11 = HIDWORD(v31) | 0x3E00000000i64;
      *(_QWORD *)(v30 + 2392) = v31;
      *(_DWORD *)(a1 + 2384) = 0;
      *(_DWORD *)(a1 + 2388) = 0;
      v13 &= 0xEFu;
    }
    if ( (v13 & 0x3E) != 0 )
    {
      if ( (v13 & 0x20) != 0 )
      {
        v14 = *(_DWORD *)(HIDWORD(v4) + 1084);
        if ( v14 )
        {
          v15 = HIDWORD(v7);
          v8 = v37;
          v32 = (unsigned __int64 *)(v14 + 8 * (*(unsigned __int8 *)(a1 + 2986) + 2 * PoGetFrequencyBucket(a1)));
          LODWORD(v11) = (*v32 + __PAIR64__(HIDWORD(v7), v37)) >> 32;
          v33 = *(_DWORD *)v32 + v37;
          __dmb(0xBu);
          do
            v34 = __ldrexd(v32);
          while ( __strexd(__PAIR64__(v11, v33), v32) );
          __dmb(0xBu);
          HIDWORD(v11) = 62;
        }
        else
        {
          v15 = HIDWORD(v7);
        }
        v13 &= 0xDFu;
      }
      else
      {
        v15 = HIDWORD(v7);
      }
      if ( (v13 & 0x3E) != 0 )
      {
        v16 = *(_DWORD *)(HIDWORD(v4) + 68);
        if ( v16 )
        {
          for ( i = v16 + *(_DWORD *)(a1 + 2352); i; i = *(_DWORD *)(i + 236) )
          {
            v36 = *(_QWORD *)i + __PAIR64__(v15, v8);
            LODWORD(v11) = HIDWORD(v36);
            *(_QWORD *)i = v36;
          }
        }
        if ( (*(_BYTE *)(HIDWORD(v4) + 2) & 8) != 0 )
        {
          LODWORD(v11) = *(_DWORD *)(HIDWORD(v4) + 356);
          if ( (*(_DWORD *)(*(_DWORD *)(a1 + 2360) + 260) & (unsigned int)v11) != *(_DWORD *)(*(_DWORD *)(a1 + 2360)
                                                                                            + 260) )
          {
            v17 = *(_QWORD *)(a1 + 2368) + __PAIR64__(v15, v8);
            LODWORD(v11) = HIDWORD(v17);
            *(_QWORD *)(a1 + 2368) = v17;
          }
        }
        HIDWORD(v11) = *(_DWORD *)(HIDWORD(v4) + 236);
        if ( HIDWORD(v11) )
          KiEndCounterAccumulation(HIDWORD(v4));
      }
    }
  }
  __enable_irq();
  result = KiSearchForNewThread(a1, 1, v11, SHIDWORD(v11));
  if ( result )
  {
    __dmb(0xBu);
    *v2 = 0;
  }
  else
  {
    v18 = *(_DWORD *)(a1 + 12);
    __disable_irq();
    v19 = ReadTimeStampCounter();
    v21 = v20;
    v22 = v19;
    v23 = __PAIR64__(v21, v19) - *(_QWORD *)(a1 + 2376);
    v38 = v19;
    __dmb(0xBu);
    v24 = (unsigned __int64 *)(a1 + 2744);
    do
      v25 = __ldrexd(v24);
    while ( __strexd(v25 + v23, v24) );
    __dmb(0xBu);
    if ( (*(_BYTE *)(v18 + 2) & 0x20) != 0 )
    {
      v26 = __PAIR64__(v21, v19) - *(_QWORD *)(a1 + 2376);
      v27 = (unsigned __int64 *)(a1 + 8 * (*(unsigned __int8 *)(a1 + 2986) + 2 * (PoGetFrequencyBucket(a1) + 1144)));
      v28 = *v27;
      __dmb(0xBu);
      do
        v29 = __ldrexd(v27);
      while ( __strexd(v28 + v26, v27) );
      __dmb(0xBu);
      v22 = v38;
    }
    *(_DWORD *)(a1 + 2376) = v22;
    *(_DWORD *)(a1 + 2380) = v21;
    if ( (*(_BYTE *)(v18 + 2) & 0x10) != 0 )
    {
      *(_DWORD *)(a1 + 2384) = v22;
      *(_DWORD *)(a1 + 2388) = v21;
    }
    if ( (*(_BYTE *)(v18 + 2) & 2) != 0 )
      KiBeginCounterAccumulation(v18, 0);
    *(_BYTE *)(a1 + 16) = 0;
    __enable_irq();
    result = 0;
  }
  return result;
}
