// PopPepDeviceStarted 
 
int __fastcall PopPepDeviceStarted(int a1)
{
  unsigned int *v2; // r4
  int v3; // r8
  int result; // r0
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r2
  unsigned int v12; // r2
  unsigned int v13; // r1
  __int16 v14; // r3
  unsigned int v15; // r1

  v2 = (unsigned int *)(a1 + 44);
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_551128();
  v5 = (unsigned __int8 *)v2 + 3;
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v2);
  while ( 1 )
  {
    v7 = *v2;
    if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v7 & 0x40000000) == 0 )
    {
      do
        v15 = __ldrex(v2);
      while ( v15 == v7 && __strex(v7 | 0x40000000, v2) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  *(_DWORD *)(a1 + 112) = 1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2);
  }
  else
  {
    __dmb(0xBu);
    *v2 = 0;
  }
  result = KfLowerIrql(v3);
  if ( *(_BYTE *)(a1 + 76) )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    v9 = KeAbPreAcquire((unsigned int)&PopPepDeviceListLock, 0, 0);
    v10 = v9;
    do
      v11 = __ldrex((unsigned int *)&PopPepDeviceListLock);
    while ( !v11 && __strex(0x11u, (unsigned int *)&PopPepDeviceListLock) );
    __dmb(0xBu);
    if ( v11 )
      ExfAcquirePushLockSharedEx(&PopPepDeviceListLock, v9, (unsigned int)&PopPepDeviceListLock);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
    if ( PopPepPlatformState )
      PopPepInitializeVetoMasks(a1, *(_DWORD *)PpmPlatformStates);
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&PopPepDeviceListLock);
    while ( v12 == 17 && __strex(0, (unsigned int *)&PopPepDeviceListLock) );
    if ( v12 != 17 )
      ExfReleasePushLockShared(&PopPepDeviceListLock);
    result = KeAbPostRelease((unsigned int)&PopPepDeviceListLock);
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = *(_WORD *)(v13 + 0x134) + 1;
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
