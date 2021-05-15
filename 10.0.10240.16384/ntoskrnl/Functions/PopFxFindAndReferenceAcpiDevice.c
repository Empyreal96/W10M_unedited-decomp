// PopFxFindAndReferenceAcpiDevice 
 
int __fastcall PopFxFindAndReferenceAcpiDevice(int a1)
{
  int v1; // r6
  unsigned int v3; // r2
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  int i; // r3
  unsigned int *v8; // r0
  unsigned int v9; // r2
  unsigned int v10; // r2
  unsigned int v11; // r2
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  v1 = -1073741810;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( !v6 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( v6 )
    ExfAcquirePushLockSharedEx(&PopFxDeviceListLock, v4, (unsigned int)&PopFxDeviceListLock);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  for ( i = PopFxAcpiDeviceList; (int *)i != &PopFxAcpiDeviceList; i = *(_DWORD *)i )
  {
    if ( i - 92 == a1 )
    {
      __dmb(0xBu);
      v8 = (unsigned int *)(i + 44);
      do
        v9 = __ldrex(v8);
      while ( __strex(v9 + 1, v8) );
      __dmb(0xBu);
      if ( *(_BYTE *)(i + 40) )
      {
        __dmb(0xBu);
        do
        {
          v10 = __ldrex(v8);
          v11 = v10 - 1;
        }
        while ( __strex(v11, v8) );
        __dmb(0xBu);
        if ( !v11 )
          KeSetEvent(i + 48, 0, 0);
        v1 = -1073741738;
      }
      else
      {
        v1 = 0;
      }
      break;
    }
  }
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( v12 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
  if ( v12 != 17 )
    ExfReleasePushLockShared(&PopFxDeviceListLock);
  v13 = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return v1;
}
