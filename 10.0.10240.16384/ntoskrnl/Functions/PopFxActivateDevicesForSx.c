// PopFxActivateDevicesForSx 
 
int __fastcall PopFxActivateDevicesForSx(unsigned int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r2
  int *i; // r4
  int v7; // r6
  int v8; // r3
  unsigned int v9; // r2
  int result; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( !v5 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( v5 )
    ExfAcquirePushLockSharedEx(&PopFxDeviceListLock, v3, (unsigned int)&PopFxDeviceListLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  for ( i = (int *)PopFxDeviceList; i != &PopFxDeviceList; i = (int *)*i )
  {
    v7 = i[7];
    if ( v7 )
    {
      if ( *(unsigned __int8 *)(v7 + 112) < a1 )
      {
        v8 = i[96];
        __dmb(0xBu);
        if ( (v8 & 1) == 0 )
        {
          PopFxActivateDevice(*(_DWORD *)(v7 + 16), 0);
          *(_DWORD *)(v7 + 168) |= 0x1000u;
        }
      }
    }
  }
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( v9 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
  if ( v9 != 17 )
    ExfReleasePushLockShared(&PopFxDeviceListLock);
  result = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
