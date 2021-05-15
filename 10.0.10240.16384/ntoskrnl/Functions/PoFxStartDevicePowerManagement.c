// PoFxStartDevicePowerManagement 
 
int __fastcall PoFxStartDevicePowerManagement(int a1)
{
  __int64 v2; // kr00_8
  int v3; // r2
  unsigned int *v4; // r4
  int v5; // r10
  int result; // r0
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  int v10; // r7
  int v11; // r3
  unsigned int v12; // r3
  unsigned int i; // r8
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r4
  unsigned int v17; // r2
  int v18; // r4
  unsigned int v19; // r2
  unsigned int v20; // r1
  __int16 v21; // r3
  unsigned int j; // r4
  unsigned int v23; // r1
  int v24; // r4
  int v25; // [sp+0h] [bp-48h] BYREF
  char v26[64]; // [sp+8h] [bp-40h] BYREF

  v2 = *(_QWORD *)(a1 + 28);
  PopPepDeviceStarted(HIDWORD(v2));
  v3 = *(_DWORD *)(a1 + 36);
  if ( v3 )
  {
    v25 = *(_DWORD *)(a1 + 40);
    (*(void (__fastcall **)(int, int *))(v3 + 64))(18, &v25);
  }
  if ( !(_DWORD)v2 )
    goto LABEL_20;
  v4 = (unsigned int *)(v2 + 44);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5510A4();
  v7 = (unsigned __int8 *)(v2 + 47);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  __dmb(0xBu);
  if ( v8 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v2 + 44));
  while ( 1 )
  {
    v9 = *v4;
    if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v9 & 0x40000000) == 0 )
    {
      do
        v23 = __ldrex(v4);
      while ( v23 == v9 && __strex(v9 | 0x40000000, v4) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v10 = *(_DWORD *)(v2 + 64);
  v11 = *(_DWORD *)(a1 + 384);
  __dmb(0xBu);
  if ( (v11 & 1) == 0 )
    goto LABEL_12;
  if ( v10 )
  {
    v10 = 0;
    *(_DWORD *)(v2 + 64) = 0;
LABEL_12:
    if ( v10 )
    {
      v12 = *(_DWORD *)(a1 + 388);
      do
      {
        for ( i = 0; i < v12; ++i )
        {
          PoFxActivateComponent((unsigned int *)a1, i, 2);
          v12 = *(_DWORD *)(a1 + 388);
        }
        --v10;
      }
      while ( v10 );
    }
  }
  *(_DWORD *)(v2 + 168) |= 4u;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2 + 44);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  KfLowerIrql(v5);
  PopDiagTraceFxDeviceStartPowerManagement(v2);
LABEL_20:
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v14 + 308);
  v15 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
  v16 = v15;
  do
    v17 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( !v17 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( v17 )
    ExfAcquirePushLockSharedEx(&PopFxDeviceListLock, v15, (unsigned int)&PopFxDeviceListLock);
  if ( v16 )
    *(_BYTE *)(v16 + 14) |= 1u;
  v18 = (unsigned __int8)PopFxEnableShutdownActiveBias;
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( v19 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
  if ( v19 != 17 )
    ExfReleasePushLockShared(&PopFxDeviceListLock);
  result = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( v18 )
  {
    v24 = *(_DWORD *)(v2 + 16);
    PopFxActivateDevice(v24, 0);
    result = PopFxIncrementDeviceSleepCount(v24);
  }
  for ( j = 0; j < *(_DWORD *)(a1 + 388); ++j )
    result = PopFxIdleComponent((_DWORD *)a1, j, 1, (int)v26);
  return result;
}
