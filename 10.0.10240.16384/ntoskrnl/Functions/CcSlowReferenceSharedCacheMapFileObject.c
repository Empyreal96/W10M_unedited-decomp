// CcSlowReferenceSharedCacheMapFileObject 
 
int __fastcall CcSlowReferenceSharedCacheMapFileObject(int a1)
{
  int v2; // r0
  unsigned int v3; // r2
  int v5; // r4
  unsigned int v6; // r2

  v2 = KeAbPreAcquire((unsigned int)&CcChangeSharedCacheMapFileLock, 0, 0);
  do
    v3 = __ldrex(&CcChangeSharedCacheMapFileLock);
  while ( !v3 && __strex(0x11u, &CcChangeSharedCacheMapFileLock) );
  __dmb(0xBu);
  if ( v3 )
    return sub_50DF10(v2, 17);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v5 = ObFastReferenceObjectLocked(a1 + 68);
  __dmb(0xBu);
  do
    v6 = __ldrex(&CcChangeSharedCacheMapFileLock);
  while ( v6 == 17 && __strex(0, &CcChangeSharedCacheMapFileLock) );
  if ( v6 != 17 )
    ExfReleasePushLockShared(&CcChangeSharedCacheMapFileLock, 0);
  KeAbPostRelease((unsigned int)&CcChangeSharedCacheMapFileLock);
  return v5;
}
