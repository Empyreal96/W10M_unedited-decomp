// MiAweViewRemover 
 
unsigned int __fastcall MiAweViewRemover(int a1, int a2, int a3)
{
  unsigned int v4; // r6
  int v5; // r5
  _DWORD *v6; // r4
  int v7; // r2
  int v8; // r0
  __int16 v9; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_DWORD *)(a1 + 328);
  --*(_WORD *)(v4 + 310);
  ExAcquireAutoExpandPushLockExclusive(v5 + 4, 0, a3);
  v6 = MiLocatePhysicalViewInTree(*(_DWORD *)(a2 + 12), (_DWORD *)(v5 + 16));
  RtlAvlRemoveNode(v5 + 16, (int)v6);
  v8 = ExReleaseAutoExpandPushLockExclusive((int *)(v5 + 4), 0, v7);
  v9 = *(_WORD *)(v4 + 310) + 1;
  *(_WORD *)(v4 + 310) = v9;
  if ( !v9 && *(_DWORD *)(v4 + 100) != v4 + 100 )
    KiCheckForKernelApcDelivery(v8);
  return ExFreePoolWithTag((unsigned int)v6);
}
