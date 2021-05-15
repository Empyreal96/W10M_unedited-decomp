// EmpQueueRuleUpdateState 
 
unsigned int __fastcall EmpQueueRuleUpdateState(int a1, int a2)
{
  int v4; // r0
  unsigned int v5; // r2
  _DWORD *i; // r2
  _DWORD *v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // r2

  v4 = KeAbPreAcquire((unsigned int)&EmpEvaluationQueueLock, 0, 0);
  do
    v5 = __ldrex((unsigned __int8 *)&EmpEvaluationQueueLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&EmpEvaluationQueueLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    return sub_54F9C8(v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  for ( i = (_DWORD *)EmpRuleUpdateQueue; i; i = (_DWORD *)*i )
  {
    if ( *(i - 1) == a1 )
    {
      if ( i != (_DWORD *)4 )
      {
        i[1] = 0;
        goto LABEL_13;
      }
      break;
    }
  }
  v8 = (_DWORD *)ExAllocatePoolWithTag(1, 12);
  if ( v8 )
  {
    *v8 = a1;
    v8[2] = a2;
    v8[1] = EmpRuleUpdateQueue;
    EmpRuleUpdateQueue = (int)(v8 + 1);
    if ( !EmpWorkerBusy )
    {
      __dmb(0xBu);
      do
        v10 = __ldrex((unsigned int *)&EmpWorkerBusy);
      while ( __strex(1u, (unsigned int *)&EmpWorkerBusy) );
      __dmb(0xBu);
      ExQueueWorkItem(&EmpRuleUpdateWorker, 1);
    }
  }
LABEL_13:
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&EmpEvaluationQueueLock);
  while ( __strex(v9 - 1, (unsigned int *)&EmpEvaluationQueueLock) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&EmpEvaluationQueueLock);
  return KeAbPostRelease((unsigned int)&EmpEvaluationQueueLock);
}
