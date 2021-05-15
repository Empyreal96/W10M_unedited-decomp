// PnpStartedDeviceNodeDependencyCheck 
 
int __fastcall PnpStartedDeviceNodeDependencyCheck(int a1, int a2)
{
  PnpAcquireDependencyRelationsLock(0, a2);
  PipAttemptDependentsStart(a1);
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  return PpDevNodeUnlockTree(0);
}
