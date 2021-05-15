// PnpCheckForActiveDependencies 
 
int __fastcall PnpCheckForActiveDependencies(int a1, int a2)
{
  int v4; // r4

  if ( PipIsDevNodeDNStarted(a1) )
    return 0;
  PnpAcquireDependencyRelationsLock(0);
  v4 = PipCheckForUnsatisfiedDependencies(a1, a2);
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  PpDevNodeUnlockTree(0);
  return v4;
}
