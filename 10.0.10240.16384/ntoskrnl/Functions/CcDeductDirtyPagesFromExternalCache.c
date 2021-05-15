// CcDeductDirtyPagesFromExternalCache 
 
int __fastcall CcDeductDirtyPagesFromExternalCache(int result, unsigned int a2)
{
  unsigned int v2; // r4
  int v3; // r6
  unsigned int v4; // r5
  int v5; // r0
  unsigned int v6; // r3

  v2 = a2;
  v3 = result;
  if ( a2 )
  {
    v4 = a2;
    v5 = KeAcquireQueuedSpinLock(5);
    v6 = *(_DWORD *)(v3 + 4);
    if ( v6 < v2 )
      v4 = *(_DWORD *)(v3 + 4);
    *(_DWORD *)(v3 + 4) = v6 - v4;
    CcGlobalDirtyPageStatistics -= v4;
    result = KeReleaseQueuedSpinLock(5, v5);
  }
  if ( (int *)CcDeferredWrites != &CcDeferredWrites )
    result = CcPostDeferredWrites(result);
  return result;
}
