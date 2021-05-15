// LOCK_HIVE_LOAD 
 
int LOCK_HIVE_LOAD()
{
  unsigned int v0; // r6
  int result; // r0
  int v2; // r4
  unsigned int v3; // r2

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  result = KeAbPreAcquire((unsigned int)&CmpLoadHiveLock, 0, 0);
  v2 = result;
  do
    v3 = __ldrex((unsigned __int8 *)&CmpLoadHiveLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&CmpLoadHiveLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    result = ExfAcquirePushLockExclusiveEx(&CmpLoadHiveLock, result, (unsigned int)&CmpLoadHiveLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  CmpLoadHiveLockOwner = v0;
  return result;
}
