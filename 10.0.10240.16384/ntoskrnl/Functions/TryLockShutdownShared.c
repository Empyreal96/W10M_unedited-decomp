// TryLockShutdownShared 
 
int TryLockShutdownShared()
{
  unsigned int v0; // r2
  int v1; // r4
  unsigned int v2; // r2
  int v3; // r0
  unsigned int v4; // r1
  __int16 v5; // r3
  int result; // r0

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&CmpShutdownLock, 0, 1);
  do
    v2 = __ldrex((unsigned int *)&CmpShutdownLock);
  while ( !v2 && __strex(0x11u, (unsigned int *)&CmpShutdownLock) );
  __dmb(0xBu);
  if ( !v2 || (v3 = ExfTryAcquirePushLockShared((unsigned int *)&CmpShutdownLock)) != 0 )
  {
    if ( v1 )
      *(_BYTE *)(v1 + 14) |= 1u;
    result = 1;
  }
  else
  {
    if ( v1 )
      v3 = KeAbPostReleaseEx((int)&CmpShutdownLock, v1);
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v5 = *(_WORD *)(v4 + 0x134) + 1;
    *(_WORD *)(v4 + 308) = v5;
    if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
      KiCheckForKernelApcDelivery(v3);
    result = 0;
  }
  return result;
}
