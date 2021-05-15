// MiReduceCommitLimits 
 
int __fastcall MiReduceCommitLimits(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[1] = a3;
  v8[2] = a4;
  KeAcquireInStackQueuedSpinLock(a1 + 806, (unsigned int)v8);
  if ( a3 )
    a1[801] -= a3;
  if ( a2 )
    a1[1029] -= a2;
  MiComputeCommitThresholds(a1);
  return KeReleaseInStackQueuedSpinLock((int)v8);
}
