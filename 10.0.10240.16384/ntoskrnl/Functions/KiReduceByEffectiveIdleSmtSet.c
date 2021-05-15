// KiReduceByEffectiveIdleSmtSet 
 
int __fastcall KiReduceByEffectiveIdleSmtSet(int a1, _DWORD *a2)
{
  _DWORD *v2; // r5
  int v4; // r4
  int v5; // r2
  int v6; // r0
  int v7; // r1
  int v8; // r8
  __int64 v9; // r0
  unsigned __int64 *v10; // r6
  __int64 v11; // kr08_8
  unsigned __int64 v12; // kr10_8
  unsigned __int64 v13; // kr18_8
  __int64 v14; // r2
  char v15; // r9
  int v16; // r6
  int v17; // r4
  unsigned __int64 *v18; // r4
  unsigned __int64 v19; // kr28_8
  unsigned __int64 v20; // kr30_8
  int v21; // r1
  int i; // r1
  __int64 v23; // r0
  int v24; // r9
  __int64 v25; // kr38_8
  int v26; // r10
  unsigned __int64 *v27; // r3
  unsigned __int64 v28; // kr40_8
  __int64 v29; // kr48_8
  unsigned __int64 *v30; // r4
  unsigned __int64 v31; // kr50_8
  unsigned __int64 v32; // kr60_8
  __int64 v33; // kr68_8
  int v35; // [sp+4h] [bp-34h]

  v2 = a2;
  v4 = *a2;
  v5 = *(_DWORD *)(a1 + 1048);
  v6 = *a2 & *(_DWORD *)(*(_DWORD *)(a1 + 2360) + 8);
  v7 = *(_DWORD *)(a1 + 3468) & ~v5;
  v35 = v7;
  if ( (v4 & v7) == 0 || (v7 & v6) != v7 || (*(_WORD *)(a1 + 1756) & 1) != 0 || *(_DWORD *)(a1 + 1932) )
    return 0;
  v8 = *(_DWORD *)(a1 + 4);
  if ( !*(_BYTE *)(a1 + 16) )
  {
    __disable_irq();
    *(_BYTE *)(a1 + 16) = 1;
    LODWORD(v9) = ReadTimeStampCounter();
    v10 = (unsigned __int64 *)(v8 + 48);
    v11 = v9 - *(_QWORD *)(a1 + 2376);
    v12 = *(_QWORD *)(v8 + 48) + v11;
    __dmb(0xBu);
    do
      v13 = __ldrexd(v10);
    while ( __strexd(v12, v10) );
    __dmb(0xBu);
    v14 = v11 + *(unsigned int *)(v8 + 56);
    if ( HIDWORD(v14) )
      LODWORD(v14) = -1;
    *(_QWORD *)(a1 + 2376) = v9;
    v15 = *(_BYTE *)(v8 + 2);
    *(_DWORD *)(v8 + 56) = v14;
    if ( (v15 & 0x3E) != 0 )
    {
      if ( (v15 & 0x10) != 0 )
      {
        v16 = a1 + 8 * *(unsigned __int8 *)(v8 + 84);
        *(_QWORD *)(v16 + 2392) = *(_QWORD *)(v16 + 2392) - *(_QWORD *)(a1 + 2384) + *(_QWORD *)(a1 + 2376);
        *(_DWORD *)(a1 + 2384) = 0;
        *(_DWORD *)(a1 + 2388) = 0;
        v15 &= 0xEFu;
      }
      if ( (v15 & 0x3E) != 0 )
      {
        if ( (v15 & 0x20) != 0 )
        {
          v17 = *(_DWORD *)(v8 + 1084);
          if ( v17 )
          {
            v18 = (unsigned __int64 *)(v17 + 8 * (*(unsigned __int8 *)(a1 + 2986) + 2 * PoGetFrequencyBucket(a1)));
            v19 = *v18 + v11;
            __dmb(0xBu);
            do
              v20 = __ldrexd(v18);
            while ( __strexd(v19, v18) );
            __dmb(0xBu);
          }
          v15 &= 0xDFu;
        }
        if ( (v15 & 0x3E) != 0 )
        {
          v21 = *(_DWORD *)(v8 + 68);
          if ( v21 )
          {
            for ( i = v21 + *(_DWORD *)(a1 + 2352); i; i = *(_DWORD *)(i + 236) )
              *(_QWORD *)i += v11;
          }
          if ( (*(_BYTE *)(v8 + 2) & 8) != 0
            && (*(_DWORD *)(*(_DWORD *)(a1 + 2360) + 260) & *(_DWORD *)(v8 + 356)) != *(_DWORD *)(*(_DWORD *)(a1 + 2360)
                                                                                                + 260) )
          {
            *(_QWORD *)(a1 + 2368) += v11;
          }
          if ( *(_DWORD *)(v8 + 236) )
            KiEndCounterAccumulation(v8);
        }
      }
    }
    LODWORD(v23) = ReadTimeStampCounter();
    v24 = HIDWORD(v23);
    v25 = v23 - *(_QWORD *)(a1 + 2376);
    v26 = v23;
    __dmb(0xBu);
    v27 = (unsigned __int64 *)(a1 + 2744);
    do
      v28 = __ldrexd(v27);
    while ( __strexd(v28 + v25, v27) );
    __dmb(0xBu);
    if ( (*(_BYTE *)(v8 + 2) & 0x20) != 0 )
    {
      v29 = v23 - *(_QWORD *)(a1 + 2376);
      v30 = (unsigned __int64 *)(a1 + 8 * (*(unsigned __int8 *)(a1 + 2986) + 2 * (PoGetFrequencyBucket(a1) + 1144)));
      v31 = *v30;
      __dmb(0xBu);
      do
        v32 = __ldrexd(v30);
      while ( __strexd(v31 + v29, v30) );
      __dmb(0xBu);
    }
    *(_DWORD *)(a1 + 2376) = v26;
    *(_DWORD *)(a1 + 2380) = v24;
    if ( (*(_BYTE *)(v8 + 2) & 0x10) != 0 )
    {
      *(_DWORD *)(a1 + 2384) = v26;
      *(_DWORD *)(a1 + 2388) = v24;
    }
    if ( (*(_BYTE *)(v8 + 2) & 2) != 0 )
      KiBeginCounterAccumulation(v8, 0);
    v7 = v35;
    v2 = a2;
    *(_BYTE *)(a1 + 16) = 0;
    __enable_irq();
  }
  v33 = *(_QWORD *)(v8 + 56);
  if ( (unsigned int)v33 < HIDWORD(v33) && HIDWORD(v33) - (int)v33 >= (unsigned int)KiShortExecutionCycles )
    return 0;
  *v2 &= v7;
  return 1;
}
