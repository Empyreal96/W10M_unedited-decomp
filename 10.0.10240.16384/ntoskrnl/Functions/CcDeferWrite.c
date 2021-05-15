// CcDeferWrite 
 
int __fastcall CcDeferWrite(int a1, int (__fastcall *a2)(int, int), int a3, int a4, int a5, char a6)
{
  int v10; // r0
  int *v12; // r1
  __int64 **v13; // r0
  int v14; // r4

  v10 = ExAllocatePoolWithTag(512, 36);
  if ( !v10 )
    return a2(a3, a4);
  *(_WORD *)v10 = 764;
  *(_WORD *)(v10 + 2) = 36;
  *(_DWORD *)(v10 + 4) = a1;
  *(_DWORD *)(v10 + 8) = a5;
  *(_DWORD *)(v10 + 20) = 0;
  *(_DWORD *)(v10 + 24) = a2;
  *(_DWORD *)(v10 + 28) = a3;
  *(_DWORD *)(v10 + 32) = a4;
  v12 = (int *)(v10 + 12);
  if ( a6 )
    v13 = (__int64 **)ExInterlockedInsertHeadList(&CcDeferredWrites, v12, (unsigned int *)&CcDeferredWriteSpinLock);
  else
    v13 = ExInterlockedInsertTailList(
            (__int64 *)&CcDeferredWrites,
            (__int64 *)v12,
            (unsigned int *)&CcDeferredWriteSpinLock);
  CcPostDeferredWrites(v13);
  v14 = KeAcquireQueuedSpinLock(5);
  CcScheduleLazyWriteScan(1, 0);
  return KeReleaseQueuedSpinLock(5, v14);
}
