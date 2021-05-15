// CmpQueueLazyCommitWorker 
 
int __fastcall CmpQueueLazyCommitWorker(_DWORD *a1)
{
  int v2; // r6
  unsigned int v3; // r2
  unsigned int v4; // r8
  int v5; // r0
  int v6; // r5
  unsigned int v7; // r2
  int **v8; // r0
  unsigned int v9; // r1
  int result; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v5);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  dword_632184 = v4;
  a1[16] &= 0xFFFFFFBF;
  v8 = (int **)dword_6321C4;
  a1[4] = &CmpLazyCommitListHead;
  a1[5] = v8;
  if ( *v8 != &CmpLazyCommitListHead )
    __fastfail(3u);
  *v8 = a1 + 4;
  dword_6321C4 = (int)(a1 + 4);
  if ( !CmpLazyCommitWorkItemActive )
  {
    v2 = 1;
    CmpLazyCommitWorkItemActive = 1;
  }
  dword_632184 = 0;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&CmpTransactionListLock);
  while ( !v9 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
  if ( v9 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v9);
  result = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( v2 )
    result = KiSetTimerEx((int)&CmpLazyCommitTimer, 0, -300000000i64, 0, 0, (int)&CmpLazyCommitDpc);
  return result;
}
