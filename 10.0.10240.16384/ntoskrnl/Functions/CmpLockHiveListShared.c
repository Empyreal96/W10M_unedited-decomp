// CmpLockHiveListShared 
 
int CmpLockHiveListShared()
{
  int result; // r0
  unsigned int v1; // r2

  result = KeAbPreAcquire((unsigned int)&CmpHiveListHeadLock, 0, 0);
  do
    v1 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
  while ( !v1 && __strex(0x11u, (unsigned int *)&CmpHiveListHeadLock) );
  __dmb(0xBu);
  if ( v1 )
    return sub_7D14CC(result, 17);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  return result;
}
