// PopFxIdleDevicesFromSx 
 
int PopFxIdleDevicesFromSx()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  int *i; // r4
  int v5; // r5
  int v6; // r3
  unsigned int v7; // r2
  int result; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( !v3 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( v3 )
    ExfAcquirePushLockSharedEx(&PopFxDeviceListLock, v1, (unsigned int)&PopFxDeviceListLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  for ( i = (int *)PopFxDeviceList; i != &PopFxDeviceList; i = (int *)*i )
  {
    v5 = i[7];
    if ( v5 )
    {
      v6 = i[96];
      __dmb(0xBu);
      if ( (v6 & 1) == 0 && !*(_BYTE *)(v5 + 112) )
      {
        PoFxIdleDevice(*(_DWORD *)(v5 + 16));
        *(_DWORD *)(v5 + 168) &= 0xFFFFEFFF;
      }
    }
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( v7 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
  if ( v7 != 17 )
    ExfReleasePushLockShared(&PopFxDeviceListLock);
  result = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
