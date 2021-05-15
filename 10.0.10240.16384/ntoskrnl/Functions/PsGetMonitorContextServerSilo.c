// PsGetMonitorContextServerSilo 
 
int __fastcall PsGetMonitorContextServerSilo(int a1, int a2, _DWORD *a3)
{
  unsigned int v3; // r10
  _DWORD *v4; // lr
  int v5; // r4
  int result; // r0
  unsigned int v8; // r8
  int v9; // r6
  unsigned int v10; // r5
  unsigned int *v11; // r9
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  unsigned int v16; // r2
  int v17; // r0
  __int16 v18; // r3
  int v19; // r2
  _DWORD *v20; // r6
  int v21; // r3
  int v22; // r0
  int v23; // r4
  unsigned int v24; // r2
  int v25; // r8
  int v26; // r3
  unsigned int v27; // r0
  unsigned int *v28; // r2
  unsigned int v29; // r1
  int v30; // r4
  unsigned int v31; // r1
  int v32; // r0
  unsigned int v33; // r1
  __int16 v34; // r3
  unsigned int v35; // r2
  char v36; // r3
  char v37; // r3

  v3 = *(_DWORD *)(a1 + 64);
  v4 = a3;
  v5 = a2;
  if ( a2 == -1 )
  {
    if ( (unsigned int)KeGetCurrentIrql() >= 2 )
      return sub_50A338();
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = *(_DWORD *)(v8 + 0x150);
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v10 + 0x134);
    v11 = (unsigned int *)(v9 + 168);
    v12 = KeAbPreAcquire(v9 + 168, 0, 0);
    v13 = v12;
    do
      v14 = __ldrex(v11);
    while ( !v14 && __strex(0x11u, v11) );
    __dmb(0xBu);
    if ( v14 )
      ExfAcquirePushLockSharedEx(v9 + 168, v12, v9 + 168);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    v5 = *(_DWORD *)(v8 + 1096);
    if ( v5 == -3 )
      v5 = *(_DWORD *)(v9 + 804);
    while ( v5 && !*(_DWORD *)(v5 + 144) )
      v5 = *(_DWORD *)(v5 + 84);
    if ( v5 )
      ObfReferenceObject(v5);
    __dmb(0xBu);
    do
      v16 = __ldrex(v11);
    while ( v16 == 17 && __strex(0, v11) );
    if ( v16 != 17 )
      ExfReleasePushLockShared(v9 + 168, 0);
    v17 = KeAbPostRelease(v9 + 168);
    v18 = *(_WORD *)(v10 + 308) + 1;
    *(_WORD *)(v10 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery(v17);
    v4 = a3;
    v19 = 1;
  }
  else
  {
    v19 = 0;
  }
  if ( v5 )
  {
    v36 = PspDebugFlags;
    __dmb(0xBu);
    if ( (v36 & 0x10) != 0 && *(int *)(*(_DWORD *)(v5 + 144) + 56) < 1 || *(int *)(*(_DWORD *)(v5 + 144) + 56) >= 3 )
    {
      v37 = PspDebugFlags;
      __dmb(0xBu);
      if ( (v37 & 0x20) != 0 )
        __debugbreak();
    }
    v20 = *(_DWORD **)(v5 + 144);
  }
  else
  {
    v20 = &InfrastructureSiloGlobals;
  }
  if ( v5 && v19 )
  {
    ObfDereferenceObjectWithTag(v5, 1953261124);
    v4 = a3;
  }
  if ( v3 < v20[9] )
  {
    if ( *(_BYTE *)(a1 + 69) )
    {
      v21 = __mrc(15, 0, 13, 0, 3);
      --*(_WORD *)((v21 & 0xFFFFFFC0) + 0x134);
      v22 = KeAbPreAcquire(&SiloMonitorLock, 0, 0);
      v23 = v22;
      do
        v24 = __ldrex((unsigned __int8 *)&SiloMonitorLock);
      while ( __strex(v24 | 1, (unsigned __int8 *)&SiloMonitorLock) );
      __dmb(0xBu);
      if ( (v24 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&SiloMonitorLock, v22, &SiloMonitorLock);
      if ( v23 )
        *(_BYTE *)(v23 + 14) |= 1u;
      v25 = 0;
    }
    else
    {
      v25 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(&SiloMonitorNonpagedContextSpinLock);
      }
      else
      {
        do
          v35 = __ldrex((unsigned int *)&SiloMonitorNonpagedContextSpinLock);
        while ( __strex(1u, (unsigned int *)&SiloMonitorNonpagedContextSpinLock) );
        __dmb(0xBu);
        if ( v35 )
          KxWaitForSpinLockAndAcquire(&SiloMonitorNonpagedContextSpinLock);
      }
    }
    v26 = *(_DWORD *)(v20[8] + 4 * v3);
    __dmb(0xBu);
    v27 = v26 & 0xFFFFFFFC;
    if ( (v26 & 0xFFFFFFFC) != 0 )
    {
      __dmb(0xBu);
      v28 = (unsigned int *)(v27 + 24);
      do
        v29 = __ldrex(v28);
      while ( __strex(v29 + 1, v28) );
      __dmb(0xBu);
      v30 = 0;
      *a3 = v27 + 48;
    }
    else
    {
      v30 = -1073741275;
      *a3 = 0;
    }
    if ( *(_BYTE *)(a1 + 69) )
    {
      __dmb(0xBu);
      do
        v31 = __ldrex((unsigned int *)&SiloMonitorLock);
      while ( __strex(v31 - 1, (unsigned int *)&SiloMonitorLock) );
      if ( (v31 & 2) != 0 && (v31 & 4) == 0 )
        ExfTryToWakePushLock(&SiloMonitorLock);
      v32 = KeAbPostRelease(&SiloMonitorLock);
      v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v34 = *(_WORD *)(v33 + 0x134) + 1;
      *(_WORD *)(v33 + 308) = v34;
      if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
      {
        KiCheckForKernelApcDelivery(v32);
        return v30;
      }
    }
    else
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&SiloMonitorNonpagedContextSpinLock);
      }
      else
      {
        __dmb(0xBu);
        SiloMonitorNonpagedContextSpinLock = 0;
      }
      KfLowerIrql(v25);
    }
    return v30;
  }
  result = -1073741811;
  *v4 = 0;
  return result;
}
