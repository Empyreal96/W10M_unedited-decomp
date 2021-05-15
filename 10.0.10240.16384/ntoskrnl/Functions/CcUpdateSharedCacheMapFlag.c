// CcUpdateSharedCacheMapFlag 
 
int __fastcall CcUpdateSharedCacheMapFlag(int a1, int a2, int a3)
{
  int v6; // r0
  int v7; // r3
  int v8; // r3

  v6 = KeAcquireQueuedSpinLock(5);
  v7 = *(_DWORD *)(a1 + 96);
  if ( a3 )
    v8 = v7 | a2;
  else
    v8 = v7 & ~a2;
  *(_DWORD *)(a1 + 96) = v8;
  return KeReleaseQueuedSpinLock(5, v6);
}
