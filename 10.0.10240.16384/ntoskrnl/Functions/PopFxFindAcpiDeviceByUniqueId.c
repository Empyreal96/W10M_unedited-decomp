// PopFxFindAcpiDeviceByUniqueId 
 
int __fastcall PopFxFindAcpiDeviceByUniqueId(int a1, int *a2)
{
  int v2; // r5
  int v3; // r4
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r6
  unsigned int v9; // r2
  int i; // r6
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  unsigned int *v15; // r1
  unsigned int v16; // r2
  unsigned int v17; // r2
  unsigned int v18; // r2

  v2 = -1073741275;
  v3 = 0;
  if ( !a2 )
    return sub_5514B8();
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
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
  for ( i = PopFxAcpiDeviceList; (int *)i != &PopFxAcpiDeviceList; i = *(_DWORD *)i )
  {
    v3 = i - 92;
    if ( *(_DWORD *)(i + 12) && !RtlCompareUnicodeString(i + 8, a1, 0) )
    {
      __dmb(0xBu);
      v15 = (unsigned int *)(i + 44);
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 + 1, v15) );
      __dmb(0xBu);
      if ( *(_BYTE *)(i + 40) )
      {
        __dmb(0xBu);
        do
        {
          v17 = __ldrex(v15);
          v18 = v17 - 1;
        }
        while ( __strex(v18, v15) );
        __dmb(0xBu);
        if ( !v18 )
          KeSetEvent(i + 48, 0, 0);
        v2 = -1073741738;
      }
      else
      {
        v2 = 0;
      }
      break;
    }
  }
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( v11 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
  if ( v11 != 17 )
    ExfReleasePushLockShared(&PopFxDeviceListLock);
  v12 = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  if ( v2 >= 0 )
    *a2 = v3;
  return v2;
}
