// IopProcessIoTracking 
 
int __fastcall IopProcessIoTracking(int a1, int a2, int a3)
{
  int v3; // r7
  unsigned int v4; // r2
  int v5; // r4
  unsigned int v6; // r2
  int result; // r0
  int i; // r4
  unsigned int v9; // r2
  unsigned int v10; // r1
  __int16 v11; // r3
  __int16 v12[4]; // [sp+0h] [bp-30h] BYREF
  int v13; // [sp+8h] [bp-28h]
  int v14; // [sp+Ch] [bp-24h]
  int v15; // [sp+10h] [bp-20h]

  v12[0] = 24;
  v3 = 0;
  v13 = a1;
  v14 = a2;
  v15 = a3;
  if ( (unsigned int)KeGetCurrentIrql(a1) < 2 )
  {
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v4 + 310);
    v3 = 1;
  }
  v5 = KeAbPreAcquire((unsigned int)&IopPerfIoTrackingLock, 0, 1);
  do
    v6 = __ldrex((unsigned int *)&IopPerfIoTrackingLock);
  while ( !v6 && __strex(0x11u, (unsigned int *)&IopPerfIoTrackingLock) );
  __dmb(0xBu);
  if ( !v6 || (result = ExfTryAcquirePushLockShared((unsigned int *)&IopPerfIoTrackingLock)) != 0 )
  {
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
    for ( i = IopPerfIoTrackingListHead; (int *)i != &IopPerfIoTrackingListHead; i = *(_DWORD *)i )
      (*(void (__fastcall **)(__int16 *))(i + 8))(v12);
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)&IopPerfIoTrackingLock);
    while ( v9 == 17 && __strex(0, (unsigned int *)&IopPerfIoTrackingLock) );
    if ( v9 != 17 )
      ExfReleasePushLockShared(&IopPerfIoTrackingLock);
    result = KeAbPostRelease((unsigned int)&IopPerfIoTrackingLock);
  }
  else if ( v5 )
  {
    result = KeAbPostReleaseEx((int)&IopPerfIoTrackingLock, v5);
  }
  if ( v3 == 1 )
  {
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(_WORD *)(v10 + 0x136) + 1;
    *(_WORD *)(v10 + 310) = v11;
    if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
