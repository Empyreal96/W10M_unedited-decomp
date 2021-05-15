// LockShutdownShared 
 
int LockShutdownShared()
{
  unsigned int v0; // r2
  int result; // r0
  int v2; // r4
  unsigned int v3; // r2

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  result = KeAbPreAcquire((unsigned int)&CmpShutdownLock, 0, 0);
  v2 = result;
  do
    v3 = __ldrex((unsigned int *)&CmpShutdownLock);
  while ( !v3 && __strex(0x11u, (unsigned int *)&CmpShutdownLock) );
  __dmb(0xBu);
  if ( v3 )
    result = ExfAcquirePushLockSharedEx(&CmpShutdownLock, result, (unsigned int)&CmpShutdownLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  return result;
}
