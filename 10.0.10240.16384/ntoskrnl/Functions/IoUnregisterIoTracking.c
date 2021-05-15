// IoUnregisterIoTracking 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall IoUnregisterIoTracking(unsigned int a1, int a2, int a3, int a4)
{
  int v5; // r2
  int v6; // r3
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  int v11; // r1 OVERLAPPED
  _DWORD *v12; // r2 OVERLAPPED
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  IoPerfReset(2, a2, a3, a4);
  IopIrpExtensionControl(2i64, v5, v6);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 310);
  v8 = KeAbPreAcquire((unsigned int)&IopPerfIoTrackingLock, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex((unsigned __int8 *)&IopPerfIoTrackingLock);
  while ( __strex(v10 | 1, (unsigned __int8 *)&IopPerfIoTrackingLock) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&IopPerfIoTrackingLock, v8, (unsigned int)&IopPerfIoTrackingLock);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  *(_QWORD *)&v11 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v12 != a1 )
    __fastfail(3u);
  *v12 = v11;
  *(_DWORD *)(v11 + 4) = v12;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&IopPerfIoTrackingLock);
  while ( __strex(v13 - 1, (unsigned int *)&IopPerfIoTrackingLock) );
  if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&IopPerfIoTrackingLock);
  v14 = KeAbPostRelease((unsigned int)&IopPerfIoTrackingLock);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x136) + 1;
  *(_WORD *)(v15 + 310) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 )
    KiCheckForKernelApcDelivery(v14);
  return ExFreePoolWithTag(a1);
}
