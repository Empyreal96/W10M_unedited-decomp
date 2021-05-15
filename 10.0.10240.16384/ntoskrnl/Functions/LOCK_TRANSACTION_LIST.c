// LOCK_TRANSACTION_LIST 
 
int LOCK_TRANSACTION_LIST()
{
  unsigned int v0; // r2
  unsigned int v1; // r6
  int result; // r0
  int v3; // r4
  unsigned int v4; // r2

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
  v3 = result;
  do
    v4 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    result = ExpAcquireFastMutexContended((int)&CmpTransactionListLock, result);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  dword_632184 = v1;
  return result;
}
