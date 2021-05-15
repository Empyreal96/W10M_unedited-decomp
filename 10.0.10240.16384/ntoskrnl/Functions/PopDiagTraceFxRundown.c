// PopDiagTraceFxRundown 
 
int PopDiagTraceFxRundown()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r4
  int v3; // r1
  unsigned int v4; // r2
  int *i; // r4
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  int *j; // r4
  unsigned int v11; // r2
  int result; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopFxPluginLock, 0, 0);
  v2 = v1;
  v3 = 17;
  do
    v4 = __ldrex((unsigned int *)&PopFxPluginLock);
  while ( !v4 && __strex(0x11u, (unsigned int *)&PopFxPluginLock) );
  __dmb(0xBu);
  if ( v4 )
    ExfAcquirePushLockSharedEx(&PopFxPluginLock, v1, (unsigned int)&PopFxPluginLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  for ( i = (int *)PopFxPluginList; i != &PopFxPluginList; i = (int *)*i )
    PopDiagTraceFxPluginRegistration(i, v3, i[4], i[5], 1);
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)&PopFxPluginLock);
  while ( v6 == 17 && __strex(0, (unsigned int *)&PopFxPluginLock) );
  if ( v6 != 17 )
    ExfReleasePushLockShared(&PopFxPluginLock);
  KeAbPostRelease((unsigned int)&PopFxPluginLock);
  v7 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( !v9 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( v9 )
    ExfAcquirePushLockSharedEx(&PopFxDeviceListLock, v7, (unsigned int)&PopFxDeviceListLock);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  for ( j = (int *)PopFxDeviceList; j != &PopFxDeviceList; j = (int *)*j )
  {
    if ( j[7] )
    {
      PopFxTraceDeviceRegistration(j, 1);
      PopDiagTraceDeviceVerboseRundown(j);
    }
  }
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( v11 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
  if ( v11 != 17 )
    ExfReleasePushLockShared(&PopFxDeviceListLock);
  result = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
