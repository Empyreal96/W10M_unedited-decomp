// PnpDelayedRemoveWorker 
 
int __fastcall PnpDelayedRemoveWorker(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v5; // r3
  __int64 v6; // r2
  int v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[2] = a4;
  v8[1] = (int)v8;
  v8[0] = (int)v8;
  PpDevNodeLockTree(1, a2);
  ExAcquireResourceExclusiveLite((int)&IopSurpriseRemoveListLock, 1, v4, v5);
  PnpDequeuePendingSurpriseRemoval(v8);
  PnpDelayedRemovePending = 0;
  ExReleaseResourceLite((int)&IopSurpriseRemoveListLock);
  while ( (int *)v8[0] != v8 )
  {
    v6 = *(_QWORD *)v8[0];
    if ( *(int **)(v8[0] + 4) != v8 || *(_DWORD *)(v6 + 4) != v8[0] )
      sub_819864();
    v8[0] = *(_DWORD *)v8[0];
    *(_DWORD *)(v6 + 4) = v8;
    PipRemoveDevicesInRelationList();
  }
  return PpDevNodeUnlockTree(1);
}
