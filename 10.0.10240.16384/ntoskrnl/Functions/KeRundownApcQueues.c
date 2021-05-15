// KeRundownApcQueues 
 
int __fastcall KeRundownApcQueues(int a1)
{
  int v2; // r0
  __int16 v3; // r3
  int result; // r0
  int v5; // r5
  int v6; // r0

  --*(_WORD *)(a1 + 308);
  *(_DWORD *)(a1 + 76) &= 0xFFFFBFFF;
  KiAcquireReleaseThreadLock(a1);
  v2 = KeForceResumeThread(a1);
  v3 = *(_WORD *)(a1 + 308) + 1;
  *(_WORD *)(a1 + 308) = v3;
  if ( !v3 && *(_DWORD *)(a1 + 100) != a1 + 100 && !*(_WORD *)(a1 + 310) )
    KiCheckForKernelApcDelivery(v2);
  if ( KiFlushQueueApc(a1, 1) )
    return sub_7F7944();
  result = KiFlushQueueApc(a1, 0);
  v5 = result;
  if ( result || *(_DWORD *)(a1 + 308) )
  {
    v6 = KeGetCurrentIrql(result);
    KeBugCheckEx(32, v5, *(_DWORD *)(a1 + 308), v6, 0);
  }
  return result;
}
