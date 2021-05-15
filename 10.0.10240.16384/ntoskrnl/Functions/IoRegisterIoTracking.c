// IoRegisterIoTracking 
 
int __fastcall IoRegisterIoTracking(int a1, int **a2)
{
  int *v4; // r0
  int *v5; // r4
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r2
  int **v11; // r1
  unsigned int v12; // r1
  int v13; // r0
  int v14; // r2
  unsigned int v15; // r1
  int v16; // r3
  int v17; // r1
  int v18; // r2
  int v19; // r3

  *a2 = 0;
  v4 = (int *)ExAllocatePoolWithTag(512, 12, 1918136137);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[2] = *(_DWORD *)(a1 + 4);
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
  v11 = (int **)dword_6318C4;
  *v5 = (int)&IopPerfIoTrackingListHead;
  v5[1] = (int)v11;
  if ( *v11 != &IopPerfIoTrackingListHead )
    __fastfail(3u);
  *v11 = v5;
  dword_6318C4 = (int)v5;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&IopPerfIoTrackingLock);
  while ( __strex(v12 - 1, (unsigned int *)&IopPerfIoTrackingLock) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&IopPerfIoTrackingLock);
  v13 = KeAbPostRelease((unsigned int)&IopPerfIoTrackingLock);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = (__int16)(*(_WORD *)(v15 + 0x136) + 1);
  *(_WORD *)(v15 + 310) = v16;
  if ( !(_WORD)v16 )
  {
    v16 = *(_DWORD *)(v15 + 100);
    v14 = v15 + 100;
    if ( v16 != v15 + 100 )
      KiCheckForKernelApcDelivery(v13);
  }
  IopIrpExtensionControl(0x100000002i64, v14, v16);
  IoPerfInit(2, v17, v18, v19);
  *a2 = v5;
  return 0;
}
