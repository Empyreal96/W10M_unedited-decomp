// PopPepPlatformStateRegistered 
 
int __fastcall PopPepPlatformStateRegistered(int a1)
{
  int v1; // r10
  unsigned int v2; // r2
  int v3; // r0
  unsigned int v4; // r2
  int result; // r0
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  unsigned int v9; // r1
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2
  int v13; // r2
  int v14; // r1
  int i; // r5
  unsigned int v16; // r2
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r3
  unsigned int *v21; // r8
  int v22; // r0
  unsigned int v23; // r1
  unsigned int v24; // r1
  unsigned int v25; // r2
  bool v26; // zf
  unsigned int v27; // r1
  unsigned int v28; // r1
  unsigned int v29; // r1
  int v30; // r3
  int v32; // [sp+4h] [bp-24h]

  v1 = a1;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PopPepVetoMaskReadyLock, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&PopPepVetoMaskReadyLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&PopPepVetoMaskReadyLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_550F78(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v6 = KeAbPreAcquire((unsigned int)&PopPepDeviceListLock, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned __int8 *)&PopPepDeviceListLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&PopPepDeviceListLock) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopPepDeviceListLock, v6, (unsigned int)&PopPepDeviceListLock);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  if ( PopPepPlatformState )
  {
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned int *)&PopPepDeviceListLock);
    while ( __strex(v27 - 1, (unsigned int *)&PopPepDeviceListLock) );
    if ( (v27 & 2) != 0 && (v27 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&PopPepDeviceListLock);
    KeAbPostRelease((unsigned int)&PopPepDeviceListLock);
    __dmb(0xBu);
    do
      v28 = __ldrex((unsigned int *)&PopPepVetoMaskReadyLock);
    while ( __strex(v28 - 1, (unsigned int *)&PopPepVetoMaskReadyLock) );
    if ( (v28 & 2) != 0 && (v28 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&PopPepVetoMaskReadyLock);
    result = KeAbPostRelease((unsigned int)&PopPepVetoMaskReadyLock);
    v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v30 = (__int16)(*(_WORD *)(v29 + 0x134) + 1);
    *(_WORD *)(v29 + 308) = v30;
    if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  else
  {
    PopPepPlatformState = (void *)(PpmPlatformStates + 128);
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)&PopPepDeviceListLock);
    while ( __strex(v9 - 1, (unsigned int *)&PopPepDeviceListLock) );
    if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&PopPepDeviceListLock);
    KeAbPostRelease((unsigned int)&PopPepDeviceListLock);
    v10 = KeAbPreAcquire((unsigned int)&PopPepDeviceListLock, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex((unsigned int *)&PopPepDeviceListLock);
    while ( !v12 && __strex(0x11u, (unsigned int *)&PopPepDeviceListLock) );
    __dmb(0xBu);
    if ( v12 )
      ExfAcquirePushLockSharedEx(&PopPepDeviceListLock, v10, (unsigned int)&PopPepDeviceListLock);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    if ( v1 )
    {
      v13 = 0;
      v14 = v1;
      do
      {
        *(_DWORD *)((char *)PopPepPlatformState + v13 + 128) = 1;
        v13 += 256;
        --v14;
      }
      while ( v14 );
    }
    for ( i = PopPepDeviceList; (int *)i != &PopPepDeviceList; i = *(_DWORD *)i )
    {
      if ( *(_BYTE *)(i + 76) )
      {
        v21 = (unsigned int *)(i + 44);
        v32 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockSharedAtDpcLevelInstrumented(i + 44);
        }
        else
        {
          v22 = *v21 & 0x7FFFFFFF;
          do
            v23 = __ldrex(v21);
          while ( v23 == v22 && __strex(v22 + 1, v21) );
          __dmb(0xBu);
          if ( v23 != v22 )
            ExpWaitForSpinLockSharedAndAcquire((unsigned int *)(i + 44));
        }
        v1 = *(_DWORD *)(i + 112) == 1;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockSharedFromDpcLevelInstrumented(i + 44);
        }
        else
        {
          __dmb(0xBu);
          do
            v24 = __ldrex(v21);
          while ( __strex(v24 & 0xBFFFFFFF, v21) );
          __dmb(0xBu);
          do
            v25 = __ldrex(v21);
          while ( __strex(v25 - 1, v21) );
        }
        KfLowerIrql(v32);
        v26 = v1 == 0;
        LOBYTE(v1) = a1;
        if ( !v26 )
          PopPepInitializeVetoMasks(i, a1);
      }
    }
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)&PopPepDeviceListLock);
    while ( v16 == 17 && __strex(0, (unsigned int *)&PopPepDeviceListLock) );
    if ( v16 != 17 )
      ExfReleasePushLockShared(&PopPepDeviceListLock);
    KeAbPostRelease((unsigned int)&PopPepDeviceListLock);
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)&PopPepVetoMaskReadyLock);
    while ( __strex(v17 - 1, (unsigned int *)&PopPepVetoMaskReadyLock) );
    if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&PopPepVetoMaskReadyLock);
    v18 = KeAbPostRelease((unsigned int)&PopPepVetoMaskReadyLock);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = (__int16)(*(_WORD *)(v19 + 0x134) + 1);
    *(_WORD *)(v19 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
      KiCheckForKernelApcDelivery(v18);
    result = PopPepUpdateIdleStateRefCount((1 << v1) - 1, 0, 0);
  }
  return result;
}
