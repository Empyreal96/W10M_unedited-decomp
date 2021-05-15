// UNLOCK_TRANSACTION_LIST 
 
int UNLOCK_TRANSACTION_LIST()
{
  unsigned int v0; // r1
  int result; // r0
  unsigned int v2; // r1
  __int16 v3; // r3

  dword_632184 = 0;
  __dmb(0xBu);
  do
    v0 = __ldrex((unsigned int *)&CmpTransactionListLock);
  while ( !v0 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
  if ( v0 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v0);
  result = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_WORD *)(v2 + 0x134) + 1;
  *(_WORD *)(v2 + 308) = v3;
  if ( !v3 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
