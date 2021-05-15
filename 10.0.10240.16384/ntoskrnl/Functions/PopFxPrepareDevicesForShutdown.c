// PopFxPrepareDevicesForShutdown 
 
int PopFxPrepareDevicesForShutdown()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r1
  int v5; // r0
  unsigned int v6; // r1
  __int16 v7; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned __int8 *)&PopFxDeviceListLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopFxDeviceListLock, v1, (unsigned int)&PopFxDeviceListLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  PopFxEnableShutdownActiveBias = 1;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( __strex(v4 - 1, (unsigned int *)&PopFxDeviceListLock) );
  if ( (v4 & 2) != 0 && (v4 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&PopFxDeviceListLock);
  v5 = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v5);
  return PopFxActivateDevicesForSx(4u);
}
