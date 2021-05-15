// LOCK_POST_LIST 
 
int LOCK_POST_LIST()
{
  unsigned int v0; // r6
  int result; // r0
  int v2; // r4
  unsigned int v3; // r2

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = KeAbPreAcquire((unsigned int)&CmpPostLock, 0, 0);
  v2 = result;
  do
    v3 = __ldrex((unsigned __int8 *)&CmpPostLock);
  while ( __strex(v3 & 0xFE, (unsigned __int8 *)&CmpPostLock) );
  __dmb(0xBu);
  if ( (v3 & 1) == 0 )
    result = ExpAcquireFastMutexContended((int)&CmpPostLock, result);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_632444 = v0;
  return result;
}
