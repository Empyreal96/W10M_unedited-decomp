// PnpReleaseDependencyRelationsLock 
 
int PnpReleaseDependencyRelationsLock()
{
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  return PpDevNodeUnlockTree(0);
}
