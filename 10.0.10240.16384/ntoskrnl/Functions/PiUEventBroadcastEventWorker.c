// PiUEventBroadcastEventWorker 
 
unsigned int __fastcall PiUEventBroadcastEventWorker(unsigned int a1)
{
  int v2; // r9
  int v3; // r5
  int v4; // r8
  unsigned int v5; // r2
  int v6; // r3
  unsigned int v7; // r5
  int v8; // r6
  unsigned int v9; // r1
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r6
  int v14; // r8
  unsigned int v15; // r2
  __int64 v16; // r2
  unsigned __int8 v17; // r6
  unsigned int v18; // r1

  v2 = 0;
  do
  {
    v3 = KeAbPreAcquire((unsigned int)&PiUEventBroadcastEventQueueLock, 0, 0);
    v4 = KfRaiseIrql(1);
    do
      v5 = __ldrex((unsigned __int8 *)&PiUEventBroadcastEventQueueLock);
    while ( __strex(v5 & 0xFE, (unsigned __int8 *)&PiUEventBroadcastEventQueueLock) );
    __dmb(0xBu);
    if ( (v5 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PiUEventBroadcastEventQueueLock, v3);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= 1u;
    v6 = __mrc(15, 0, 13, 0, 3);
    v7 = PiUEventBroadcastEventQueue;
    dword_630B44 = v6 & 0xFFFFFFC0;
    dword_630B5C = v4;
    v8 = *(unsigned __int8 *)(PiUEventBroadcastEventQueue + 8);
    dword_630B44 = 0;
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)&PiUEventBroadcastEventQueueLock);
    while ( !v9 && __strex(1u, (unsigned int *)&PiUEventBroadcastEventQueueLock) );
    if ( v9 )
      ExpReleaseFastMutexContended((unsigned int *)&PiUEventBroadcastEventQueueLock, v9);
    KfLowerIrql((unsigned __int8)v4);
    KeAbPostRelease((unsigned int)&PiUEventBroadcastEventQueueLock);
    if ( v8 )
    {
      v12 = *(_DWORD *)(v7 + 12);
      if ( v12 )
      {
        switch ( v12 )
        {
          case 1:
            PiUEventBroadcastVolumesChangedEvent(*(_DWORD *)(v7 + 16));
            break;
          case 2:
            PiUEventBroadcastHardwareProfilesChangedEvent(*(_DWORD *)(v7 + 16), v7 + 20);
            break;
          case 3:
            PiUEventBroadcastPortsChangedEvent(*(_DWORD *)(v7 + 16), v7 + 20, v7 + 36);
            break;
        }
      }
      else
      {
        PiUEventBroadcastDevnodesChangedEvent(*(_DWORD *)(v7 + 16), v10, v11, 0);
      }
    }
    v13 = KeAbPreAcquire((unsigned int)&PiUEventBroadcastEventQueueLock, 0, 0);
    v14 = KfRaiseIrql(1);
    do
      v15 = __ldrex((unsigned __int8 *)&PiUEventBroadcastEventQueueLock);
    while ( __strex(v15 & 0xFE, (unsigned __int8 *)&PiUEventBroadcastEventQueueLock) );
    __dmb(0xBu);
    if ( (v15 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PiUEventBroadcastEventQueueLock, v13);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    dword_630B44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_630B5C = v14;
    v16 = *(_QWORD *)PiUEventBroadcastEventQueue;
    if ( *(int **)(PiUEventBroadcastEventQueue + 4) != &PiUEventBroadcastEventQueue
      || *(_DWORD *)(v16 + 4) != PiUEventBroadcastEventQueue )
    {
      __fastfail(3u);
    }
    PiUEventBroadcastEventQueue = *(_DWORD *)PiUEventBroadcastEventQueue;
    *(_DWORD *)(v16 + 4) = &PiUEventBroadcastEventQueue;
    if ( (int *)PiUEventBroadcastEventQueue == &PiUEventBroadcastEventQueue )
      v2 = 1;
    dword_630B44 = 0;
    v17 = dword_630B5C;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)&PiUEventBroadcastEventQueueLock);
    while ( !v18 && __strex(1u, (unsigned int *)&PiUEventBroadcastEventQueueLock) );
    if ( v18 )
      ExpReleaseFastMutexContended((unsigned int *)&PiUEventBroadcastEventQueueLock, v18);
    KfLowerIrql(v17);
    KeAbPostRelease((unsigned int)&PiUEventBroadcastEventQueueLock);
    ExFreePoolWithTag(v7);
  }
  while ( !v2 );
  return ExFreePoolWithTag(a1);
}
