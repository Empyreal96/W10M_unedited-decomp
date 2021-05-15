// CmpFinishBeingActiveFlusherAndReconciler 
 
int __fastcall CmpFinishBeingActiveFlusherAndReconciler(int *a1)
{
  int v2; // r2
  int v3; // r3
  int v4; // r0
  int v5; // r4
  int v6; // r5

  CmpLockRegistry();
  v4 = ExAcquireResourceExclusiveLite(a1[468], 1, v2, v3);
  a1[828] &= 0xFFFFFFFC;
  v5 = CmpReleaseWriteQueue(v4, a1 + 822);
  v6 = CmpReleaseWriteQueue(v5, a1 + 825);
  ExReleaseResourceLite(a1[468]);
  CmpUnlockRegistry();
  CmpWakeWriteQueueWaiters(v5);
  return CmpWakeWriteQueueWaiters(v6);
}
