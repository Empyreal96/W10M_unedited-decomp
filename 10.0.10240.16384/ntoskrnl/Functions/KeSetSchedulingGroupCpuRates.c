// KeSetSchedulingGroupCpuRates 
 
void __fastcall __spoils<R2,R3,R12> KeSetSchedulingGroupCpuRates(int a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int v6; // r3
  _DWORD *v7; // r0
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[2] = a3;
  v8[3] = a4;
  KeAcquireInStackQueuedSpinLock(&KiSchedulingGroupLock, v8);
  v6 = *(_DWORD *)(*a2 + 4);
  if ( (v6 & 1) == 0 )
  {
    *(_DWORD *)(*a2 + 4) = v6 | 1;
    KiUpdateMinimumWeight(0, 1, *(_DWORD *)(*a2 + 60));
    KiAssignSchedulingGroupWeights(0, 0, *(_DWORD *)(*a2 + 60));
  }
  v7 = (_DWORD *)*a2;
  *v7 = *a3;
  v7[1] = a3[1];
  KiUpdateCpuTargetByRate(*a2, 1);
  if ( KiUpdateMinimumWeight(1, 1, *(_DWORD *)(*a2 + 60)) )
    KiAssignSchedulingGroupWeights(1, 0, *(_DWORD *)(*a2 + 60));
  KeReleaseInStackQueuedSpinLock(v8);
}
