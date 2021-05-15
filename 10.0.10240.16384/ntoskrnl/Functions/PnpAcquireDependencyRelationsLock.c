// PnpAcquireDependencyRelationsLock 
 
int __fastcall PnpAcquireDependencyRelationsLock(int a1, int a2)
{
  int v3; // r2
  int v4; // r3
  int result; // r0

  PpDevNodeLockTree(0, a2);
  if ( a1 )
    result = ExAcquireResourceExclusiveLite((int)&PiDependencyRelationsLock, 1, v3, v4);
  else
    result = ExAcquireResourceSharedLite((int)&PiDependencyRelationsLock, 1);
  return result;
}
