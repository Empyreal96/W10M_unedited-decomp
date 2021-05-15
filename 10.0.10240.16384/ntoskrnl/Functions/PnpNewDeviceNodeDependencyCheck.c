// PnpNewDeviceNodeDependencyCheck 
 
int __fastcall PnpNewDeviceNodeDependencyCheck(int a1)
{
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int result; // r0
  int v7; // [sp+0h] [bp-8h] BYREF

  v7 = 0;
  PnpAcquireDependencyRelationsLock(1);
  PipAddtoRebuildPowerRelationsQueue(*(_DWORD *)(a1 + 16));
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  v2 = PpDevNodeUnlockTree(0);
  PipProcessRebuildPowerRelationsQueue(v2);
  PiPnpRtlBeginOperation(&v7, v3, v4, v5);
  PipNotifyDeviceDependencyList(a1, 0);
  PipNotifyDeviceDependencyList(a1, 1);
  result = v7;
  if ( v7 )
    result = PiPnpRtlEndOperation(v7);
  return result;
}
