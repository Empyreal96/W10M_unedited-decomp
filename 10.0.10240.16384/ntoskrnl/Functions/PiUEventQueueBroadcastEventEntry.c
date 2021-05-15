// PiUEventQueueBroadcastEventEntry 
 
_DWORD *__fastcall PiUEventQueueBroadcastEventEntry(int a1)
{
  int v2; // r5
  int v3; // r7
  unsigned int v4; // r2
  BOOL v5; // r7
  int **v6; // r2
  unsigned __int8 v7; // r5
  unsigned int v8; // r1
  _DWORD *result; // r0

  v2 = KeAbPreAcquire((unsigned int)&PiUEventBroadcastEventQueueLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PiUEventBroadcastEventQueueLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PiUEventBroadcastEventQueueLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PiUEventBroadcastEventQueueLock, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_630B44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_630B5C = v3;
  v5 = PiUEventBroadcastEventQueue == (_DWORD)&PiUEventBroadcastEventQueue;
  PiUEventCoalesceBroadcastEvents(a1);
  *(_BYTE *)(a1 + 8) = 1;
  v6 = (int **)dword_630B64;
  *(_DWORD *)a1 = &PiUEventBroadcastEventQueue;
  *(_DWORD *)(a1 + 4) = v6;
  if ( *v6 != &PiUEventBroadcastEventQueue )
    __fastfail(3u);
  *v6 = (int *)a1;
  dword_630B44 = 0;
  dword_630B64 = a1;
  v7 = dword_630B5C;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PiUEventBroadcastEventQueueLock);
  while ( !v8 && __strex(1u, (unsigned int *)&PiUEventBroadcastEventQueueLock) );
  if ( v8 )
    ExpReleaseFastMutexContended((unsigned int *)&PiUEventBroadcastEventQueueLock, v8);
  KfLowerIrql(v7);
  result = (_DWORD *)KeAbPostRelease((unsigned int)&PiUEventBroadcastEventQueueLock);
  if ( v5 )
  {
    result = (_DWORD *)ExAllocatePoolWithTag(512, 16, 1500540496);
    if ( result )
    {
      result[2] = PiUEventBroadcastEventWorker;
      result[3] = result;
      *result = 0;
      result = (_DWORD *)ExQueueWorkItem(result, 4);
    }
  }
  return result;
}
