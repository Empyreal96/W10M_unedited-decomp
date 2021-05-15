// KeTransitionProcessorParkState 
 
int __fastcall KeTransitionProcessorParkState(int a1)
{
  unsigned int *v1; // r6
  int v2; // r9
  unsigned int *v3; // r8
  BOOL v5; // lr
  unsigned int *v6; // r7
  int result; // r0
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r5
  unsigned int *v11; // r10
  unsigned int v12; // r2
  unsigned int v13; // r1
  int v14; // r2
  int v15; // r1
  int v16; // r2
  int v17; // r8
  int v18; // r5
  int v19; // r0
  int v20; // r0
  unsigned int v21; // r1
  int v22; // r6
  char v23; // r2
  unsigned int v24; // r1
  int v25; // r3
  int v26; // r3
  unsigned int v27; // r1
  int v28; // r3
  int v29; // r1
  int v30; // r2
  int v31; // r6
  int v32; // r7
  int v33; // r1
  int v34; // r0
  unsigned int v35; // r1
  unsigned __int8 *v36; // r3
  unsigned int v37; // r2
  int v38; // r3
  char v39; // r3
  unsigned int v40; // r1
  int v41; // r2
  int v42; // r1
  char v43; // r3
  unsigned int *v44; // r5
  unsigned int v45; // r2
  int var24[10]; // [sp+Ch] [bp-24h] BYREF

  v1 = *(unsigned int **)(a1 + 2360);
  v2 = *(_DWORD *)(a1 + 1048);
  v3 = v1 + 34;
  var24[0] = 0;
  v5 = (v2 & v1[34]) != 0;
  v6 = v1 + 35;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52B56C();
  v8 = (unsigned __int8 *)v1 + 143;
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v1 + 35);
  while ( 1 )
  {
    v10 = *v6;
    if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v10 & 0x40000000) == 0 )
    {
      do
        v40 = __ldrex(v6);
      while ( v40 == v10 && __strex(v10 | 0x40000000, v6) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v11 = (unsigned int *)(a1 + 24);
  while ( 1 )
  {
    do
      v12 = __ldrex(v11);
    while ( __strex(1u, v11) );
    __dmb(0xBu);
    if ( !v12 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v11 );
  }
  __dmb(0xBu);
  do
    v13 = __ldrex(v3);
  while ( __strex(v13 ^ v2, v3) );
  __dmb(0xBu);
  v14 = *(_DWORD *)(a1 + 3456);
  if ( !v14 )
    goto LABEL_17;
  v15 = *(_DWORD *)(a1 + 3460);
  v16 = v14 & v1[34];
  if ( v16 )
  {
    if ( v16 == v2 )
    {
      *((_DWORD *)*(&KiProcessorBlock + *(unsigned __int8 *)(v15 + 300)) + 866) = 0;
      v39 = *(_BYTE *)(a1 + 1053);
      *(_DWORD *)(a1 + 3464) = 1;
    }
    else
    {
      if ( !*(_DWORD *)(a1 + 3464) || !v5 )
        goto LABEL_17;
      v38 = (int)*(&KiProcessorBlock + 31 - __clz(v16));
      *(_DWORD *)(a1 + 3464) = 0;
      *(_DWORD *)(v38 + 3464) = 1;
      v39 = *(_BYTE *)(v38 + 1053);
    }
    *(_BYTE *)(v15 + 300) = v39;
LABEL_17:
    v17 = 0;
    goto LABEL_18;
  }
  v17 = 1;
LABEL_18:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v1 + 35);
  }
  else
  {
    __dmb(0xBu);
    *v6 = 0;
  }
  v18 = *(_DWORD *)(a1 + 12);
  if ( !v5 )
  {
    v19 = *(unsigned __int8 *)(a1 + 19);
    if ( (v19 & 2) == 0 )
      __fastfail(0x21u);
    v20 = v19 - 2;
    *(_BYTE *)(a1 + 19) = v20;
    if ( !v20 )
    {
      __dmb(0xBu);
      do
        v21 = __ldrex(v1);
      while ( __strex(v21 ^ v2, v1) );
      __dmb(0xBu);
    }
    v22 = 0;
    if ( !v20 )
    {
      *(_BYTE *)(a1 + 1755) = 1;
      v22 = 1;
    }
    result = KiAbProcessThreadPriorityModification(v18, 0, 1);
    *(_BYTE *)(v18 + 123) = 0;
    if ( v22 )
    {
      if ( (*(_BYTE *)(v18 + 2) & 4) != 0 )
      {
        if ( *(_DWORD *)(v18 + 68)
          && (v41 = *(_DWORD *)(v18 + 68)) != 0
          && (v42 = v41 + *(_DWORD *)(a1 + 2352)) != 0
          && (result = KiGetThreadEffectiveRankNonZero(v18, v42, 0)) != 0 )
        {
          v43 = 1;
        }
        else
        {
          v43 = *(_BYTE *)(v18 + 123);
        }
        v23 = v43;
      }
      else
      {
        v23 = 0;
      }
      **(_BYTE **)(a1 + 28) = v23;
    }
    __dmb(0xBu);
    *v11 = 0;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned __int16 *)0xFFFF936A);
    while ( __strex(v24 + 1, (unsigned __int16 *)0xFFFF936A) );
    __dmb(0xBu);
    return result;
  }
  v25 = *(unsigned __int8 *)(a1 + 19);
  if ( (v25 & 2) != 0 )
    __fastfail(0x21u);
  v26 = v25 + 2;
  *(_BYTE *)(a1 + 19) = v26;
  if ( v26 == 2 )
  {
    __dmb(0xBu);
    do
      v27 = __ldrex(v1);
    while ( __strex(v27 ^ v2, v1) );
    __dmb(0xBu);
  }
  v28 = *(_DWORD *)(a1 + 8);
  if ( !v28 || v28 == v18 )
  {
    v29 = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 8) = 0;
    *(_BYTE *)(v28 + 132) = 7;
    *(_DWORD *)(v28 + 144) = 0;
    var24[0] = v28 + 144;
    v28 = 0;
    v29 = 1;
  }
  v30 = *(_DWORD *)(a1 + 4);
  v31 = 1;
  if ( v30 == v18 )
  {
    if ( v29 )
      KiSetProcessorIdle(a1, 1, 0);
  }
  else if ( !v28 )
  {
    if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
    {
      v31 = 0;
    }
    else
    {
      *(_BYTE *)(v30 + 349) = 1;
      v36 = (unsigned __int8 *)(v30 + 81);
      do
        v37 = __ldrex(v36);
      while ( __strex(v37 | 8, v36) );
      *(_DWORD *)(a1 + 8) = v18;
      KiSetProcessorIdle(a1, 1, 0);
      if ( (*(_WORD *)(a1 + 1756) & 1) == 0 )
      {
        v32 = 1;
        goto LABEL_47;
      }
    }
  }
  v32 = 0;
LABEL_47:
  KiAbProcessThreadPriorityModification(v18, 127, 1);
  *(_BYTE *)(v18 + 123) = 127;
  if ( v31 )
    **(_BYTE **)(a1 + 28) = 127;
  if ( KiGroupSchedulingEnabled )
  {
    while ( 1 )
    {
      v33 = dword_690384;
      __dmb(0xBu);
      v34 = KeTickCount;
      __dmb(0xBu);
      if ( v33 == dword_690388 )
        break;
      __dmb(0xAu);
      __yield();
    }
    KiGroupSchedulingGenerationEnd(a1, v33, v34, v33, 1);
  }
  KiFlushReadyLists(a1 + 2048, a1 + 1932, var24);
  if ( v17 )
  {
    v44 = *(unsigned int **)(a1 + 3460);
    while ( 1 )
    {
      do
        v45 = __ldrex(v44);
      while ( __strex(1u, v44) );
      __dmb(0xBu);
      if ( !v45 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v44 );
    }
    KiFlushReadyLists(v44 + 2, v44 + 1, var24);
    __dmb(0xBu);
    *v44 = 0;
  }
  __dmb(0xBu);
  *v11 = 0;
  result = KiProcessDeferredReadyList(a1, var24, 2);
  __dmb(0xBu);
  do
    v35 = __ldrex((unsigned __int16 *)0xFFFF936A);
  while ( __strex(v35 - 1, (unsigned __int16 *)0xFFFF936A) );
  __dmb(0xBu);
  if ( v32 )
    result = HalRequestSoftwareInterrupt(2);
  return result;
}
