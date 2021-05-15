// PiDeviceDependencyInit 
 
int PiDeviceDependencyInit()
{
  int v0; // r1

  ExInitializeResourceLite((int)&PiDependencyRelationsLock);
  PiDependencyEdgeWriteLock = 0;
  PnpAcquireDependencyRelationsLock(1, v0);
  PiDependencyNodeListHead = (int)&PiDependencyNodeListHead;
  dword_630D8C = (int)&PiDependencyNodeListHead;
  PiDependencyNodeEmptyList[0] = PiDependencyNodeEmptyList;
  PiDependencyNodeEmptyList[1] = PiDependencyNodeEmptyList;
  PiRebuildPowerRelationsQueue = (int)&PiRebuildPowerRelationsQueue;
  dword_630D94 = (int)&PiRebuildPowerRelationsQueue;
  PnpReleaseDependencyRelationsLock();
  return 0;
}
