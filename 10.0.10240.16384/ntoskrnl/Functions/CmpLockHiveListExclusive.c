// CmpLockHiveListExclusive 
 
int CmpLockHiveListExclusive()
{
  int result; // r0
  unsigned int v1; // r2

  result = KeAbPreAcquire((unsigned int)&CmpHiveListHeadLock, 0, 0);
  do
    v1 = __ldrex((unsigned __int8 *)&CmpHiveListHeadLock);
  while ( __strex(v1 | 1, (unsigned __int8 *)&CmpHiveListHeadLock) );
  __dmb(0xBu);
  if ( (v1 & 1) != 0 )
    return sub_7D37C8(result);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  return result;
}
