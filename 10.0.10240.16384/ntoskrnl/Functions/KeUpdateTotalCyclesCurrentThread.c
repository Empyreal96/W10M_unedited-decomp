// KeUpdateTotalCyclesCurrentThread 
 
int __fastcall KeUpdateTotalCyclesCurrentThread(int a1, _QWORD *a2)
{
  int v4; // r7
  __int64 v5; // r0
  unsigned __int64 *v6; // r4
  unsigned int v7; // r5
  unsigned int v8; // r6
  __int64 v9; // kr00_8
  unsigned __int64 v10; // kr08_8
  unsigned __int64 v11; // r2
  __int64 v12; // r2
  int result; // r0
  char v14; // r9
  int v15; // r4
  unsigned __int64 *v16; // r4
  unsigned __int64 v17; // kr20_8
  unsigned __int64 v18; // kr28_8
  int v19; // r1
  int i; // r1
  __int64 v21; // r0
  int v22; // r9
  __int64 v23; // kr30_8
  int v24; // r10
  unsigned __int64 *v25; // r3
  unsigned __int64 v26; // kr38_8
  __int64 v27; // kr40_8
  unsigned __int64 *v28; // r4
  unsigned __int64 v29; // kr48_8
  unsigned __int64 v30; // kr58_8
  int v31; // r6
  __int64 v32; // [sp+8h] [bp-38h]

  __disable_irq();
  v4 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  *(_BYTE *)(v4 + 16) = 1;
  LODWORD(v5) = ReadTimeStampCounter();
  v6 = (unsigned __int64 *)(a1 + 48);
  v9 = v5 - *(_QWORD *)(v4 + 2376);
  v8 = HIDWORD(v9);
  v7 = v9;
  v32 = v5;
  v10 = *(_QWORD *)(a1 + 48) + v9;
  __dmb(0xBu);
  do
    v11 = __ldrexd(v6);
  while ( __strexd(v10, v6) );
  __dmb(0xBu);
  v12 = v9 + *(unsigned int *)(a1 + 56);
  if ( HIDWORD(v12) )
    return sub_5277CC();
  *(_QWORD *)(v4 + 2376) = v5;
  v14 = *(_BYTE *)(a1 + 2);
  *(_DWORD *)(a1 + 56) = v12;
  if ( (v14 & 0x3E) != 0 )
  {
    if ( (v14 & 0x10) != 0 )
    {
      v31 = v4 + 8 * *(unsigned __int8 *)(a1 + 84);
      *(_QWORD *)(v31 + 2392) = *(_QWORD *)(v31 + 2392) - *(_QWORD *)(v4 + 2384) + *(_QWORD *)(v4 + 2376);
      v8 = HIDWORD(v9);
      v7 = v9;
      *(_DWORD *)(v4 + 2384) = 0;
      *(_DWORD *)(v4 + 2388) = 0;
      v14 &= 0xEFu;
    }
    if ( (v14 & 0x3E) != 0 )
    {
      if ( (v14 & 0x20) != 0 )
      {
        v15 = *(_DWORD *)(a1 + 1084);
        if ( v15 )
        {
          v16 = (unsigned __int64 *)(v15 + 8 * (*(unsigned __int8 *)(v4 + 2986) + 2 * PoGetFrequencyBucket(v4)));
          v17 = *v16 + __PAIR64__(v8, v7);
          __dmb(0xBu);
          do
            v18 = __ldrexd(v16);
          while ( __strexd(v17, v16) );
          __dmb(0xBu);
        }
        v14 &= 0xDFu;
      }
      if ( (v14 & 0x3E) != 0 )
      {
        v19 = *(_DWORD *)(a1 + 68);
        if ( v19 )
        {
          for ( i = v19 + *(_DWORD *)(v4 + 2352); i; i = *(_DWORD *)(i + 236) )
            *(_QWORD *)i += __PAIR64__(v8, v7);
        }
        if ( (*(_BYTE *)(a1 + 2) & 8) != 0
          && (*(_DWORD *)(*(_DWORD *)(v4 + 2360) + 260) & *(_DWORD *)(a1 + 356)) != *(_DWORD *)(*(_DWORD *)(v4 + 2360)
                                                                                              + 260) )
        {
          *(_QWORD *)(v4 + 2368) += __PAIR64__(v8, v7);
        }
        if ( *(_DWORD *)(a1 + 236) )
          KiEndCounterAccumulation(a1);
      }
    }
  }
  if ( a2 )
    *a2 = v32;
  LODWORD(v21) = ReadTimeStampCounter();
  v22 = HIDWORD(v21);
  v23 = v21 - *(_QWORD *)(v4 + 2376);
  v24 = v21;
  __dmb(0xBu);
  v25 = (unsigned __int64 *)(v4 + 2744);
  do
    v26 = __ldrexd(v25);
  while ( __strexd(v26 + v23, v25) );
  __dmb(0xBu);
  if ( (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
  {
    v27 = v21 - *(_QWORD *)(v4 + 2376);
    v28 = (unsigned __int64 *)(v4 + 8 * (*(unsigned __int8 *)(v4 + 2986) + 2 * (PoGetFrequencyBucket(v4) + 1144)));
    v29 = *v28;
    __dmb(0xBu);
    do
      v30 = __ldrexd(v28);
    while ( __strexd(v29 + v27, v28) );
    __dmb(0xBu);
  }
  *(_DWORD *)(v4 + 2376) = v24;
  *(_DWORD *)(v4 + 2380) = v22;
  if ( (*(_BYTE *)(a1 + 2) & 0x10) != 0 )
  {
    *(_DWORD *)(v4 + 2384) = v24;
    *(_DWORD *)(v4 + 2388) = v22;
  }
  if ( (*(_BYTE *)(a1 + 2) & 2) != 0 )
    KiBeginCounterAccumulation(a1, 0);
  result = v10;
  *(_BYTE *)(v4 + 16) = 0;
  __enable_irq();
  return result;
}
