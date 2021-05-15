// EmProviderDeregisterEntry 
 
unsigned int __fastcall EmProviderDeregisterEntry(int a1)
{
  int v2; // r0
  int v3; // r5
  unsigned int v4; // r2
  unsigned int v5; // r1

  v2 = KeAbPreAcquire((unsigned int)&EmpDatabaseLock, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex((unsigned __int8 *)&EmpDatabaseLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&EmpDatabaseLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&EmpDatabaseLock, v2, (unsigned int)&EmpDatabaseLock);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  EmpProviderDeregisterEntry(a1);
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&EmpDatabaseLock);
  while ( __strex(v5 - 1, (unsigned int *)&EmpDatabaseLock) );
  if ( (v5 & 2) != 0 && (v5 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&EmpDatabaseLock);
  return KeAbPostRelease((unsigned int)&EmpDatabaseLock);
}
