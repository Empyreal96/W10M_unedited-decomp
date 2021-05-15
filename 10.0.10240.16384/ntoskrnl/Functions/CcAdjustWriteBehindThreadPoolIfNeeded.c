// CcAdjustWriteBehindThreadPoolIfNeeded 
 
unsigned int __fastcall CcAdjustWriteBehindThreadPoolIfNeeded(unsigned int result)
{
  int v1; // r4
  unsigned int v2; // r5
  int v3; // r6

  v1 = 0;
  v2 = result;
  if ( !(_BYTE)dword_681280 )
  {
    v3 = KeAcquireQueuedSpinLock(8);
    if ( CcPostTickWorkItemCount )
    {
      result = sub_53C710();
    }
    else
    {
      if ( (unsigned int)CcGlobalDirtyPageStatistics > 0x2000 || v2 )
      {
        if ( CcIsWriteBehindThreadpoolAtLowPriority() )
        {
          CcAdjustWriteBehindThreadPool(0);
          v1 = 1;
        }
      }
      else if ( !CcExecutingWriteBehindWorkItems && (int *)CcRegularWorkQueue == &CcRegularWorkQueue )
      {
        CcAdjustWriteBehindThreadPool(1);
      }
      result = KeReleaseQueuedSpinLock(8, v3);
      if ( v1 )
      {
        result = KeGetCurrentIrql(result);
        if ( result < 2 )
          result = CcBoostLowPriorityWorkerThread(0);
      }
    }
  }
  return result;
}
