// PopProcessPowerRequestOverrideQueryResponse 
 
int __fastcall PopProcessPowerRequestOverrideQueryResponse(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r5
  int *v6; // r0
  int v7; // r4
  int v8; // r3
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = a2;
  v10[1] = a3;
  v10[2] = a4;
  v5 = a1[1];
  PopAcquirePowerRequestPushLock(0);
  v6 = (int *)PopPowerRequestFindEntryById(*a1);
  if ( v6 )
  {
    v7 = *v6;
    KeAcquireInStackQueuedSpinLock(&PopPowerRequestSpinLock, v10);
    v8 = *(_DWORD *)(v7 + 16);
    *(_DWORD *)(v7 + 16) = v5;
    if ( v8 != v5 )
      return sub_529614(v8 ^ v5);
    PopQueuePowerRequestCallbacks(v7, 1);
    v6 = (int *)KeReleaseInStackQueuedSpinLock(v10);
  }
  return PopReleasePowerRequestPushLock(v6);
}
