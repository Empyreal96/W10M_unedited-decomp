// KiFreezeTargetExecution 
 
int __fastcall KiFreezeTargetExecution(int a1, int a2)
{
  int v2; // r6
  int v3; // r8
  int result; // r0
  unsigned int v5; // r3
  unsigned int v6; // r7
  int v7; // r1
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r4
  unsigned int v11; // r0
  int v12; // r0
  int v13; // r8
  __int64 v14; // r0
  unsigned __int64 *v15; // r6
  int v16; // lr
  __int64 v17; // kr08_8
  __int64 v18; // kr10_8
  unsigned __int64 v19; // kr20_8
  __int64 v20; // r2
  char v21; // r9
  unsigned int v22; // r6
  int v23; // r4
  unsigned __int64 *v24; // r4
  unsigned __int64 v25; // kr28_8
  unsigned __int64 v26; // kr30_8
  int v27; // r1
  int i; // r1
  __int64 v29; // r0
  int v30; // r9
  __int64 v31; // kr38_8
  int v32; // r10
  unsigned __int64 *v33; // r3
  unsigned __int64 v34; // kr40_8
  __int64 v35; // kr48_8
  unsigned __int64 *v36; // r5
  unsigned __int64 v37; // kr50_8
  unsigned __int64 v38; // kr58_8
  __int64 v39; // r0
  __int64 v40; // kr60_8
  unsigned __int64 *v41; // r3
  unsigned __int64 v42; // kr68_8
  unsigned __int64 *v43; // r4
  unsigned __int64 v44; // kr70_8
  unsigned __int64 v45; // kr80_8
  int v46; // r0
  int v47; // [sp+0h] [bp-98h]
  int v48; // [sp+4h] [bp-94h]
  int v49[2]; // [sp+8h] [bp-90h] BYREF
  int v50[2]; // [sp+10h] [bp-88h] BYREF
  int v51; // [sp+18h] [bp-80h]
  int v52; // [sp+24h] [bp-74h]
  int v53[28]; // [sp+28h] [bp-70h] BYREF

  v2 = a1;
  v47 = a2;
  v3 = a2;
  v49[0] = a1;
  if ( !KiFreezeExecutionLock )
    return sub_51B034();
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v48 = 0;
  }
  else
  {
    v48 = 1;
    __disable_irq();
  }
  v51 = KfRaiseIrql(15);
  v5 = (unsigned int)KeGetPcr();
  v6 = (v5 & 0xFFFFF000) + 1408;
  if ( !*(_BYTE *)((v5 & 0xFFFFF000) + 0x590) && !PoAllProcIntrDisabled )
  {
    v13 = *(_DWORD *)((v5 & 0xFFFFF000) + 0x584);
    *(_BYTE *)((v5 & 0xFFFFF000) + 0x590) = 1;
    LODWORD(v14) = ReadTimeStampCounter();
    v15 = (unsigned __int64 *)(v13 + 48);
    v17 = v14 - *(_QWORD *)(v6 + 2376);
    v16 = HIDWORD(v17);
    v18 = *(_QWORD *)(v13 + 48);
    v50[0] = HIDWORD(v17);
    __dmb(0xBu);
    do
      v19 = __ldrexd(v15);
    while ( __strexd(v18 + v17, v15) );
    __dmb(0xBu);
    v20 = v17 + *(unsigned int *)(v13 + 56);
    if ( HIDWORD(v20) )
    {
      v52 = 0;
      LODWORD(v20) = -1;
    }
    *(_QWORD *)(v6 + 2376) = v14;
    v21 = *(_BYTE *)(v13 + 2);
    *(_DWORD *)(v13 + 56) = v20;
    if ( (v21 & 0x3E) != 0 )
    {
      if ( (v21 & 0x10) != 0 )
      {
        v22 = v6 + 8 * *(unsigned __int8 *)(v13 + 84);
        *(_QWORD *)(v22 + 2392) = *(_QWORD *)(v22 + 2392) - *(_QWORD *)(v6 + 2384) + *(_QWORD *)(v6 + 2376);
        *(_DWORD *)(v6 + 2384) = 0;
        *(_DWORD *)(v6 + 2388) = 0;
        v21 &= 0xEFu;
      }
      if ( (v21 & 0x3E) != 0 )
      {
        if ( (v21 & 0x20) != 0 )
        {
          v23 = *(_DWORD *)(v13 + 1084);
          if ( v23 )
          {
            v16 = v50[0];
            v24 = (unsigned __int64 *)(v23 + 8 * (*(unsigned __int8 *)(v6 + 2986) + 2 * PoGetFrequencyBucket(v6)));
            v25 = *v24 + __PAIR64__(v50[0], v17);
            __dmb(0xBu);
            do
              v26 = __ldrexd(v24);
            while ( __strexd(v25, v24) );
            __dmb(0xBu);
          }
          v21 &= 0xDFu;
        }
        if ( (v21 & 0x3E) != 0 )
        {
          v27 = *(_DWORD *)(v13 + 68);
          if ( v27 )
          {
            for ( i = v27 + *(_DWORD *)(v6 + 2352); i; i = *(_DWORD *)(i + 236) )
              *(_QWORD *)i += __PAIR64__(v16, v17);
          }
          if ( (*(_BYTE *)(v13 + 2) & 8) != 0
            && (*(_DWORD *)(v13 + 356) & *(_DWORD *)(*(_DWORD *)(v6 + 2360) + 260)) != *(_DWORD *)(*(_DWORD *)(v6 + 2360)
                                                                                                 + 260) )
          {
            *(_QWORD *)(v6 + 2368) += __PAIR64__(v16, v17);
          }
          if ( *(_DWORD *)(v13 + 236) )
            KiEndCounterAccumulation(v13);
        }
      }
    }
    LODWORD(v29) = ReadTimeStampCounter();
    v30 = HIDWORD(v29);
    v31 = v29 - *(_QWORD *)(v6 + 2376);
    v32 = v29;
    __dmb(0xBu);
    v33 = (unsigned __int64 *)(v6 + 2744);
    do
      v34 = __ldrexd(v33);
    while ( __strexd(v34 + v31, v33) );
    __dmb(0xBu);
    if ( (*(_BYTE *)(v13 + 2) & 0x20) != 0 )
    {
      v35 = v29 - *(_QWORD *)(v6 + 2376);
      v36 = (unsigned __int64 *)(v6 + 8 * (*(unsigned __int8 *)(v6 + 2986) + 2 * (PoGetFrequencyBucket(v6) + 1144)));
      v37 = *v36 + v35;
      __dmb(0xBu);
      do
        v38 = __ldrexd(v36);
      while ( __strexd(v37, v36) );
      __dmb(0xBu);
    }
    *(_DWORD *)(v6 + 2376) = v32;
    *(_DWORD *)(v6 + 2380) = v30;
    if ( (*(_BYTE *)(v13 + 2) & 0x10) != 0 )
    {
      *(_DWORD *)(v6 + 2384) = v32;
      *(_DWORD *)(v6 + 2388) = v30;
    }
    if ( (*(_BYTE *)(v13 + 2) & 2) != 0 )
      KiBeginCounterAccumulation(v13, 0);
    v2 = v49[0];
    v3 = v47;
    *(_BYTE *)(v6 + 16) = 0;
  }
  *(_DWORD *)(v6 + 1672) = 2;
  off_617A44(1, 0);
  if ( v2 )
  {
    v10 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    **(_DWORD **)(v10 + 2712) = *(_DWORD *)(v10 + 2716);
    KeContextFromKframes(v2, v3);
    v11 = v10 + 1440;
  }
  else
  {
    RtlCaptureContext(*(_DWORD **)(v6 + 1304), v7, v8, v9);
    v11 = v6 + 32;
  }
  KiSaveProcessorControlState(v11);
  KeQueryPerformanceCounter(v49, 0);
  v50[0] = v49[0];
  v50[1] = v49[1];
  while ( (*(_DWORD *)(v6 + 1672) & 0xF) == 2 )
  {
    if ( v6 == KiDebuggerOwner )
    {
      memset(v53, 0, 80);
      v53[0] = -2147483641;
      v53[2] = (int)v53;
      v53[3] = *(_DWORD *)(*(_DWORD *)(v6 + 1304) + 64);
      if ( KiDebugSwitchRoutine(v53, *(_DWORD *)(v6 + 1304), 0) != 3 )
        KiSetDebuggerOwner(KiFreezeOwner);
    }
    KiCheckStall(v6, 1);
    KiTurnOffProcessorWhileFrozen(v50);
  }
  ((void (__cdecl *)())off_617A44)();
  if ( v2 )
    v12 = KiRestoreProcessorState(v2, v47);
  else
    v12 = KiRestoreProcessorControlState(v6 + 32);
  __dsb(0xFu);
  __mcr(15, 0, 0, 8, 7, 0);
  __dsb(0xFu);
  __isb(0xFu);
  KiSweepCurrentIcache(v12);
  __dmb(0xBu);
  *(_DWORD *)(v6 + 1672) = 0;
  if ( !*(_BYTE *)(v6 + 16) && !PoAllProcIntrDisabled )
  {
    LODWORD(v39) = ReadTimeStampCounter();
    v40 = v39 - *(_QWORD *)(v6 + 2376);
    __dmb(0xBu);
    v41 = (unsigned __int64 *)(v6 + 2744);
    do
      v42 = __ldrexd(v41);
    while ( __strexd(v42 + v40, v41) );
    __dmb(0xBu);
    if ( (*(_BYTE *)(*(_DWORD *)(v6 + 4) + 2) & 0x20) != 0 )
    {
      v43 = (unsigned __int64 *)(v6 + 8 * (*(unsigned __int8 *)(v6 + 2986) + 2 * (PoGetFrequencyBucket(v6) + 1144)));
      v44 = *v43;
      __dmb(0xBu);
      do
        v45 = __ldrexd(v43);
      while ( __strexd(v44 + v40, v43) );
      __dmb(0xBu);
    }
    v46 = *(_DWORD *)(v6 + 4);
    *(_QWORD *)(v6 + 2376) += v40;
    if ( (*(_BYTE *)(v46 + 2) & 2) != 0 )
      KiBeginCounterAccumulation(v46, 0);
  }
  result = KfLowerIrql(v51);
  if ( v48 )
    __enable_irq();
  return result;
}
