// CcAddDirtyPagesToExternalCache 
 
int __fastcall CcAddDirtyPagesToExternalCache(int result, int a2)
{
  int v3; // r7
  int v4; // r9
  unsigned int v5; // r2

  v3 = result;
  if ( a2 )
  {
    v4 = KeAcquireQueuedSpinLock(5);
    if ( !*(_DWORD *)(v3 + 4) )
      CcScheduleLazyWriteScan(0, 0);
    *(_DWORD *)(v3 + 4) += a2;
    v5 = CcGlobalDirtyPageStatistics + a2;
    CcGlobalDirtyPageStatistics += a2;
    if ( CcCoalescingState && v5 >= 0x2000 )
      CcScheduleLazyWriteScan(1, 0);
    if ( CcForcedDisableLazywriteScan )
    {
      CcScheduleLazyWriteScan(0, 0);
      CcForcedDisableLazywriteScan = 0;
    }
    CcAdjustWriteBehindThreadPoolIfNeeded(0);
    result = KeReleaseQueuedSpinLock(5, v4);
  }
  return result;
}
