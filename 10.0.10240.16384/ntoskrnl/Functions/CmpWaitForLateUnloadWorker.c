// CmpWaitForLateUnloadWorker 
 
int __fastcall CmpWaitForLateUnloadWorker(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r7
  unsigned int v6; // r2
  int v7; // r5
  unsigned __int8 v8; // r7
  unsigned int v9; // r1
  int result; // r0
  int v11[8]; // [sp+8h] [bp-20h] BYREF

  v11[0] = a4;
  while ( 1 )
  {
    v4 = KeAbPreAcquire(&CmpWorkerEngineLock, 0, 0);
    v5 = KfRaiseIrql(1);
    do
      v6 = __ldrex((unsigned __int8 *)&CmpWorkerEngineLock);
    while ( __strex(v6 & 0xFE, (unsigned __int8 *)&CmpWorkerEngineLock) );
    __dmb(0xBu);
    if ( (v6 & 1) == 0 )
      ExpAcquireFastMutexContended(&CmpWorkerEngineLock, v4);
    if ( v4 )
      *(_BYTE *)(v4 + 14) |= 1u;
    dword_6324A4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_6324BC = v5;
    v7 = (unsigned __int8)CmpWorkerEngineWorkItemActive;
    LOBYTE(v11[0]) = CmpWorkerEngineWorkItemActive;
    __dmb(0xBu);
    dword_6324A4 = 0;
    v8 = dword_6324BC;
    __dmb(0xBu);
    do
      v9 = __ldrex(&CmpWorkerEngineLock);
    while ( !v9 && __strex(1u, &CmpWorkerEngineLock) );
    if ( v9 )
      break;
    KfLowerIrql(v8);
    result = KeAbPostRelease(&CmpWorkerEngineLock);
    if ( !v7 )
      return result;
    ExBlockOnAddressPushLock(&CmpWorkerEngineFinishedEvent, &CmpWorkerEngineWorkItemActive, v11, 1);
  }
  return sub_529148();
}
