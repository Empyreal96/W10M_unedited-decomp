// ViPendingQueuePassiveLevelCompletion 
 
int __fastcall ViPendingQueuePassiveLevelCompletion(unsigned int a1)
{
  int v2; // r0
  unsigned int v3; // r2
  int v4; // r5
  int v5; // r1
  unsigned int *v6; // r2
  unsigned int v7; // r6
  int v8; // r2
  unsigned int v9; // r1
  __int16 v10; // r3
  int v12; // r4
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  if ( !ViPendingWorkersCount )
    return 0;
  v2 = KeQueryPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = ViPendingWorkersCount;
  v5 = ViPendingWorkerIndexHint;
  while ( 1 )
  {
    __dmb(0xBu);
    v6 = (unsigned int *)((char *)&unk_61CF44 + 28 * v5);
    do
      v7 = __ldrex(v6);
    while ( !v7 && __strex(a1, v6) );
    __dmb(0xBu);
    v8 = v5 + 1;
    if ( v5 + 1 >= (unsigned int)ViPendingWorkersCount )
      v8 = 0;
    if ( !v7 )
      break;
    v5 = v8;
    if ( !--v4 )
    {
      v5 = -1;
      ++ViPendingWorkersBusyCount;
      goto LABEL_12;
    }
  }
  ViPendingWorkerIndexHint = v8;
LABEL_12:
  if ( v5 == -1 )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      KiCheckForKernelApcDelivery(v2);
    return 0;
  }
  v12 = 7 * v5;
  KeSetPriorityThread(ViPendingWorkers[7 * v5], v2);
  v13 = KeSetEvent((int)&unk_61CF48 + 4 * v12, 0, 0);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return 1;
}
