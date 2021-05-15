// CmpDelayFreeRMWorker 
 
unsigned int CmpDelayFreeRMWorker()
{
  int v0; // r5
  int v1; // r7
  unsigned int v2; // r2
  unsigned int v3; // r5
  __int64 v4; // r2
  unsigned __int8 v5; // r7
  unsigned int v6; // r1
  int v7; // r5
  int v8; // r8
  unsigned int v9; // r2
  unsigned int v10; // r1

  v0 = KeAbPreAcquire((unsigned int)&CmpDelayFreeRMLock, 0, 0);
  v1 = KfRaiseIrql(1);
  do
    v2 = __ldrex((unsigned __int8 *)&CmpDelayFreeRMLock);
  while ( __strex(v2 & 0xFE, (unsigned __int8 *)&CmpDelayFreeRMLock) );
  __dmb(0xBu);
  if ( (v2 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpDelayFreeRMLock, v0);
  if ( v0 )
    *(_BYTE *)(v0 + 14) |= 1u;
  dword_631FE4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_631FFC = v1;
  while ( 1 )
  {
    v3 = CmpDelayFreeRMListHead;
    if ( (int *)CmpDelayFreeRMListHead == &CmpDelayFreeRMListHead )
      break;
    v4 = *(_QWORD *)CmpDelayFreeRMListHead;
    if ( *(int **)(CmpDelayFreeRMListHead + 4) != &CmpDelayFreeRMListHead
      || *(_DWORD *)(v4 + 4) != CmpDelayFreeRMListHead )
    {
      __fastfail(3u);
    }
    CmpDelayFreeRMListHead = *(_DWORD *)CmpDelayFreeRMListHead;
    *(_DWORD *)(v4 + 4) = &CmpDelayFreeRMListHead;
    dword_631FE4 = 0;
    v5 = dword_631FFC;
    __dmb(0xBu);
    do
      v6 = __ldrex((unsigned int *)&CmpDelayFreeRMLock);
    while ( !v6 && __strex(1u, (unsigned int *)&CmpDelayFreeRMLock) );
    if ( v6 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpDelayFreeRMLock, v6);
    KfLowerIrql(v5);
    KeAbPostRelease((unsigned int)&CmpDelayFreeRMLock);
    CmpLockRegistryExclusive();
    ExDeleteResourceLite(*(_DWORD **)(v3 + 80));
    ExFreePoolWithTag(*(_DWORD *)(v3 + 80));
    ExFreePoolWithTag(v3);
    CmpUnlockRegistry();
    v7 = KeAbPreAcquire((unsigned int)&CmpDelayFreeRMLock, 0, 0);
    v8 = KfRaiseIrql(1);
    do
      v9 = __ldrex((unsigned __int8 *)&CmpDelayFreeRMLock);
    while ( __strex(v9 & 0xFE, (unsigned __int8 *)&CmpDelayFreeRMLock) );
    __dmb(0xBu);
    if ( (v9 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&CmpDelayFreeRMLock, v7);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    dword_631FE4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_631FFC = v8;
    LOBYTE(v1) = v8;
  }
  CmpDelayFreeRMWorkItemActive = 0;
  dword_631FE4 = 0;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&CmpDelayFreeRMLock);
  while ( !v10 && __strex(1u, (unsigned int *)&CmpDelayFreeRMLock) );
  if ( v10 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpDelayFreeRMLock, v10);
  KfLowerIrql((unsigned __int8)v1);
  return KeAbPostRelease((unsigned int)&CmpDelayFreeRMLock);
}
