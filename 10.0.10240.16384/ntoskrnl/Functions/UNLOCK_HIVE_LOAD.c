// UNLOCK_HIVE_LOAD 
 
unsigned int UNLOCK_HIVE_LOAD()
{
  unsigned int v0; // r4
  int v1; // r1
  unsigned int v2; // r0
  unsigned int v3; // r2
  unsigned int result; // r0
  __int16 v5; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  __pld(&CmpLoadHiveLock);
  CmpLoadHiveLockOwner = 0;
  v1 = CmpLoadHiveLock;
  if ( (CmpLoadHiveLock & 0xFFFFFFF0) > 0x10 )
    v2 = CmpLoadHiveLock - 16;
  else
    v2 = 0;
  if ( (CmpLoadHiveLock & 2) != 0 )
    goto LABEL_13;
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)&CmpLoadHiveLock);
  while ( v3 == v1 && __strex(v2, (unsigned int *)&CmpLoadHiveLock) );
  if ( v3 != v1 )
LABEL_13:
    ExfReleasePushLock(&CmpLoadHiveLock, v1);
  result = KeAbPostRelease((unsigned int)&CmpLoadHiveLock);
  v5 = *(_WORD *)(v0 + 308) + 1;
  *(_WORD *)(v0 + 308) = v5;
  if ( !v5 && *(_DWORD *)(v0 + 100) != v0 + 100 )
    result = sub_7D3CF8(result);
  return result;
}
