// EmpRuleUpdateWorkerThread 
 
int EmpRuleUpdateWorkerThread()
{
  int v0; // r0
  int v1; // r5
  unsigned int v2; // r2
  int *v3; // r5
  unsigned int v4; // r1
  int result; // r0
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r2
  unsigned int v9; // r1
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r1

  v0 = KeAbPreAcquire((unsigned int)&EmpEvaluationQueueLock, 0, 0);
  v1 = v0;
  do
    v2 = __ldrex((unsigned __int8 *)&EmpEvaluationQueueLock);
  while ( __strex(v2 | 1, (unsigned __int8 *)&EmpEvaluationQueueLock) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&EmpEvaluationQueueLock, v0, (unsigned int)&EmpEvaluationQueueLock);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v3 = (int *)EmpRuleUpdateQueue;
  if ( EmpRuleUpdateQueue )
  {
    while ( 1 )
    {
      EmpRuleUpdateQueue = *v3;
      __dmb(0xBu);
      do
        v4 = __ldrex((unsigned int *)&EmpEvaluationQueueLock);
      while ( __strex(v4 - 1, (unsigned int *)&EmpEvaluationQueueLock) );
      if ( (v4 & 2) != 0 )
        break;
      KeAbPostRelease((unsigned int)&EmpEvaluationQueueLock);
      v6 = KeAbPreAcquire((unsigned int)&EmpDatabaseLock, 0, 0);
      v7 = v6;
      do
        v8 = __ldrex((unsigned __int8 *)&EmpDatabaseLock);
      while ( __strex(v8 | 1, (unsigned __int8 *)&EmpDatabaseLock) );
      __dmb(0xBu);
      if ( (v8 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&EmpDatabaseLock, v6, (unsigned int)&EmpDatabaseLock);
      if ( v7 )
        *(_BYTE *)(v7 + 14) |= 1u;
      EmpUpdateRuleState((int *)*(v3 - 1));
      __dmb(0xBu);
      do
        v9 = __ldrex((unsigned int *)&EmpDatabaseLock);
      while ( __strex(v9 - 1, (unsigned int *)&EmpDatabaseLock) );
      if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&EmpDatabaseLock);
      KeAbPostRelease((unsigned int)&EmpDatabaseLock);
      ExFreePoolWithTag(v3 - 1, 1970359621);
      v10 = KeAbPreAcquire((unsigned int)&EmpEvaluationQueueLock, 0, 0);
      v11 = v10;
      do
        v12 = __ldrex((unsigned __int8 *)&EmpEvaluationQueueLock);
      while ( __strex(v12 | 1, (unsigned __int8 *)&EmpEvaluationQueueLock) );
      __dmb(0xBu);
      if ( (v12 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&EmpEvaluationQueueLock, v10, (unsigned int)&EmpEvaluationQueueLock);
      if ( v11 )
        *(_BYTE *)(v11 + 14) |= 1u;
      v3 = (int *)EmpRuleUpdateQueue;
      if ( !EmpRuleUpdateQueue )
        goto LABEL_28;
    }
    result = sub_5536F4(2);
  }
  else
  {
LABEL_28:
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)&EmpEvaluationQueueLock);
    while ( __strex(v13 - 1, (unsigned int *)&EmpEvaluationQueueLock) );
    if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&EmpEvaluationQueueLock);
    KeAbPostRelease((unsigned int)&EmpEvaluationQueueLock);
    __dmb(0xBu);
    result = 0;
    do
      v14 = __ldrex((unsigned int *)&EmpWorkerBusy);
    while ( __strex(0, (unsigned int *)&EmpWorkerBusy) );
    __dmb(0xBu);
  }
  return result;
}
