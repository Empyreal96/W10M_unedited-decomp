// CmWorkerEngineQueueWorkItem 
 
int __fastcall CmWorkerEngineQueueWorkItem(_DWORD *a1)
{
  int v2; // r7
  int v3; // r5
  int v4; // r0
  unsigned int v5; // r2
  int result; // r0
  void **v7; // r1
  int v8; // r3
  unsigned __int8 v9; // r5
  unsigned int v10; // r1

  v2 = 0;
  v3 = KeAbPreAcquire((unsigned int)&CmpWorkerEngineLock, 0, 0);
  v4 = KfRaiseIrql(1);
  do
    v5 = __ldrex((unsigned __int8 *)&CmpWorkerEngineLock);
  while ( __strex(v5 & 0xFE, (unsigned __int8 *)&CmpWorkerEngineLock) );
  __dmb(0xBu);
  if ( (v5 & 1) == 0 )
    return sub_7E9CD8(v4);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  dword_6324A4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = (void **)dword_6324C4;
  dword_6324BC = v4;
  *a1 = &CmpWorkerEngineListHead;
  a1[1] = v7;
  if ( *v7 != &CmpWorkerEngineListHead )
    __fastfail(3u);
  *v7 = a1;
  dword_6324C4 = (int)a1;
  v8 = (unsigned __int8)CmpWorkerEngineWorkItemActive;
  __dmb(0xBu);
  if ( !v8 )
  {
    __dmb(0xBu);
    CmpWorkerEngineWorkItemActive = 1;
    v2 = 1;
  }
  dword_6324A4 = 0;
  v9 = dword_6324BC;
  __dmb(0xBu);
  do
    v10 = __ldrex(&CmpWorkerEngineLock);
  while ( !v10 && __strex(1u, &CmpWorkerEngineLock) );
  if ( v10 )
    ExpReleaseFastMutexContended(&CmpWorkerEngineLock, v10);
  KfLowerIrql(v9);
  result = KeAbPostRelease((unsigned int)&CmpWorkerEngineLock);
  if ( v2 )
    result = ExQueueWorkItem(&CmpWorkerEngineWorkItem, 1);
  return result;
}
