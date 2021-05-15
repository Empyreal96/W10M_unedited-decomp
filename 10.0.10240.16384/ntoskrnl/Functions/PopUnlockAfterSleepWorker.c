// PopUnlockAfterSleepWorker 
 
int PopUnlockAfterSleepWorker()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  CmSetLazyFlushState(1);
  ExSwapinWorkerThreads(1);
  ExNotifyCallback(ExCbPowerState, 3, 1);
  PopRunNormalIrpWorkers();
  v0 = MmUnlockPagableImageSection(ExPageLockHandle);
  v1 = PopClearSleepMarker(v0);
  PopFreeHiberContext(v1);
  v2 = PopAcquirePolicyLock();
  if ( byte_61EA48 )
    PopAdjustHiberFile(v2);
  v3 = PopReleasePolicyLock();
  return PopReleaseTransitionLock(v3);
}
