// IoDeleteAllDependencyRelations 
 
int __fastcall IoDeleteAllDependencyRelations(int a1)
{
  int v2; // r0

  if ( !a1 )
    return -1073741811;
  v2 = PnpAcquireDependencyRelationsLock(1);
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 176) + 44) )
    return sub_7CA7E4(v2);
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  PpDevNodeUnlockTree(0);
  return 0;
}
