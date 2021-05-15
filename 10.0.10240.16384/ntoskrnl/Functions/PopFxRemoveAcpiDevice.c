// PopFxRemoveAcpiDevice 
 
int __fastcall PopFxRemoveAcpiDevice(int a1, int a2)
{
  unsigned int v3; // r2
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  __int64 v7; // r0
  unsigned int v8; // r1
  int result; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex((unsigned __int8 *)&PopFxDeviceListLock);
  while ( __strex(v6 | 1, (unsigned __int8 *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopFxDeviceListLock, v4, (unsigned int)&PopFxDeviceListLock);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v7 = *(_QWORD *)(a2 + 92);
  if ( *(_DWORD *)(v7 + 4) != a2 + 92 || *(_DWORD *)HIDWORD(v7) != a2 + 92 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v7) = v7;
  *(_DWORD *)(v7 + 4) = HIDWORD(v7);
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( __strex(v8 - 1, (unsigned int *)&PopFxDeviceListLock) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&PopFxDeviceListLock);
  result = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
