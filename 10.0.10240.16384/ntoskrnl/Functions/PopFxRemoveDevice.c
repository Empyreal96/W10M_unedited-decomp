// PopFxRemoveDevice 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopFxRemoveDevice(int a1, int a2)
{
  unsigned int v3; // r2
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  int v7; // r1 OVERLAPPED
  _DWORD *v8; // r2 OVERLAPPED
  unsigned int v9; // r1
  int result; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

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
  *(_QWORD *)&v7 = *(_QWORD *)a2;
  if ( *(_DWORD *)(*(_DWORD *)a2 + 4) != a2 || *v8 != a2 )
    __fastfail(3u);
  *v8 = v7;
  *(_DWORD *)(v7 + 4) = v8;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( __strex(v9 - 1, (unsigned int *)&PopFxDeviceListLock) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&PopFxDeviceListLock);
  result = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
