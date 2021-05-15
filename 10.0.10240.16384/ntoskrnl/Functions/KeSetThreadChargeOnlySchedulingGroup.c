// KeSetThreadChargeOnlySchedulingGroup 
 
int __fastcall KeSetThreadChargeOnlySchedulingGroup(int a1, int a2)
{
  bool v5; // zf
  int v6; // r8
  __int64 v7; // r0
  __int64 v8; // kr00_8
  unsigned __int64 *v9; // r6
  unsigned __int64 v10; // kr08_8
  unsigned __int64 v11; // kr10_8
  __int64 v12; // r2
  char v13; // r9
  int v14; // r4
  unsigned int v15; // r5
  unsigned __int64 *v16; // r4
  unsigned __int64 v17; // kr18_8
  unsigned __int64 v18; // kr20_8
  int v19; // r1
  int i; // r1
  int v21; // r0
  unsigned int v22; // r1
  unsigned int v23; // r9
  int v24; // r1
  unsigned __int64 v25; // kr28_8
  unsigned __int64 *v26; // r3
  unsigned __int64 v27; // kr30_8
  unsigned __int64 v28; // kr38_8
  unsigned __int64 *v29; // r4
  unsigned __int64 v30; // kr40_8
  unsigned __int64 v31; // kr50_8
  unsigned int *v32; // r0
  unsigned int v33; // r2
  unsigned __int8 *v34; // r3
  unsigned int v35; // r2
  unsigned __int8 *v36; // r3
  unsigned int v37; // r2
  unsigned __int8 *v38; // r3
  unsigned int v39; // r2
  unsigned __int8 *v40; // r3
  unsigned int v41; // r2
  int v42; // r6
  int v43; // [sp+4h] [bp-2Ch]

  if ( (*(_DWORD *)(a1 + 80) & 0x100) != 0 )
  {
    v5 = a2 == 0;
  }
  else
  {
    if ( !a2 )
      return sub_527430();
    v5 = *(_DWORD *)(a1 + 68) == 0;
  }
  if ( !v5 )
    return sub_527430();
  KfRaiseIrql(2);
  v6 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  __disable_irq();
  *(_BYTE *)(v6 + 16) = 1;
  LODWORD(v7) = ReadTimeStampCounter();
  v9 = (unsigned __int64 *)(a1 + 48);
  v8 = v7 - *(_QWORD *)(v6 + 2376);
  v10 = *(_QWORD *)(a1 + 48) + v8;
  __dmb(0xBu);
  do
    v11 = __ldrexd(v9);
  while ( __strexd(v10, v9) );
  __dmb(0xBu);
  v12 = v8 + *(unsigned int *)(a1 + 56);
  if ( HIDWORD(v12) )
    LODWORD(v12) = -1;
  *(_QWORD *)(v6 + 2376) = v7;
  v13 = *(_BYTE *)(a1 + 2);
  *(_DWORD *)(a1 + 56) = v12;
  if ( (v13 & 0x3E) != 0 )
  {
    if ( (v13 & 0x10) != 0 )
    {
      v42 = v6 + 8 * *(unsigned __int8 *)(a1 + 84);
      *(_QWORD *)(v42 + 2392) = *(_QWORD *)(v42 + 2392) - *(_QWORD *)(v6 + 2384) + *(_QWORD *)(v6 + 2376);
      *(_DWORD *)(v6 + 2384) = 0;
      *(_DWORD *)(v6 + 2388) = 0;
      v13 &= 0xEFu;
    }
    if ( (v13 & 0x3E) != 0 )
    {
      if ( (v13 & 0x20) != 0 )
      {
        v14 = *(_DWORD *)(a1 + 1084);
        if ( v14 )
        {
          v15 = HIDWORD(v8);
          v16 = (unsigned __int64 *)(v14 + 8 * (*(unsigned __int8 *)(v6 + 2986) + 2 * PoGetFrequencyBucket(v6)));
          v17 = *v16 + v8;
          __dmb(0xBu);
          do
            v18 = __ldrexd(v16);
          while ( __strexd(v17, v16) );
          __dmb(0xBu);
        }
        else
        {
          v15 = HIDWORD(v8);
        }
        v13 &= 0xDFu;
      }
      else
      {
        v15 = HIDWORD(v8);
      }
      if ( (v13 & 0x3E) != 0 )
      {
        v19 = *(_DWORD *)(a1 + 68);
        if ( v19 )
        {
          for ( i = v19 + *(_DWORD *)(v6 + 2352); i; i = *(_DWORD *)(i + 236) )
            *(_QWORD *)i += __PAIR64__(v15, v8);
        }
        if ( (*(_BYTE *)(a1 + 2) & 8) != 0
          && (*(_DWORD *)(*(_DWORD *)(v6 + 2360) + 260) & *(_DWORD *)(a1 + 356)) != *(_DWORD *)(*(_DWORD *)(v6 + 2360)
                                                                                              + 260) )
        {
          *(_QWORD *)(v6 + 2368) += __PAIR64__(v15, v8);
        }
        if ( *(_DWORD *)(a1 + 236) )
          KiEndCounterAccumulation(a1);
      }
    }
  }
  v21 = ReadTimeStampCounter();
  v23 = v22;
  v24 = v21;
  v25 = __PAIR64__(v23, v21) - *(_QWORD *)(v6 + 2376);
  v43 = v21;
  __dmb(0xBu);
  v26 = (unsigned __int64 *)(v6 + 2744);
  do
    v27 = __ldrexd(v26);
  while ( __strexd(v27 + v25, v26) );
  __dmb(0xBu);
  if ( (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
  {
    v28 = __PAIR64__(v23, v21) - *(_QWORD *)(v6 + 2376);
    v29 = (unsigned __int64 *)(v6 + 8 * (*(unsigned __int8 *)(v6 + 2986) + 2 * (PoGetFrequencyBucket(v6) + 1144)));
    v30 = *v29;
    __dmb(0xBu);
    do
      v31 = __ldrexd(v29);
    while ( __strexd(v30 + v28, v29) );
    __dmb(0xBu);
    v24 = v43;
  }
  *(_DWORD *)(v6 + 2376) = v24;
  *(_DWORD *)(v6 + 2380) = v23;
  if ( (*(_BYTE *)(a1 + 2) & 0x10) != 0 )
  {
    *(_DWORD *)(v6 + 2384) = v24;
    *(_DWORD *)(v6 + 2388) = v23;
  }
  if ( (*(_BYTE *)(a1 + 2) & 2) != 0 )
    KiBeginCounterAccumulation(a1, 0);
  *(_BYTE *)(v6 + 16) = 0;
  __enable_irq();
  v32 = (unsigned int *)(v6 + 24);
  while ( 1 )
  {
    do
      v33 = __ldrex(v32);
    while ( __strex(1u, v32) );
    __dmb(0xBu);
    if ( !v33 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v32 );
  }
  __dmb(0xBu);
  if ( a2 )
  {
    v38 = (unsigned __int8 *)(a1 + 81);
    do
      v39 = __ldrex(v38);
    while ( __strex(v39 | 1, v38) );
    __dmb(0xBu);
    *(_DWORD *)(a1 + 68) = a2;
    __dmb(0xBu);
    v40 = (unsigned __int8 *)(a1 + 2);
    do
      v41 = __ldrex(v40);
    while ( __strex(v41 | 4, v40) );
  }
  else
  {
    v34 = (unsigned __int8 *)(a1 + 2);
    do
      v35 = __ldrex(v34);
    while ( __strex(v35 & 0xFB, v34) );
    __dmb(0xBu);
    *(_DWORD *)(a1 + 68) = 0;
    __dmb(0xBu);
    v36 = (unsigned __int8 *)(a1 + 81);
    do
      v37 = __ldrex(v36);
    while ( __strex(v37 & 0xFE, v36) );
  }
  __dmb(0xBu);
  __dmb(0xBu);
  *v32 = 0;
  KfLowerIrql(0);
  return 1;
}
