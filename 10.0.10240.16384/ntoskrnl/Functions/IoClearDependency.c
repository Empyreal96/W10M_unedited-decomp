// IoClearDependency 
 
int __fastcall IoClearDependency(int a1, int a2)
{
  int v4; // r4
  int v5; // r8
  int *v6; // r7
  int v7; // r2
  int v8; // r0
  int *v9; // r2
  int v10; // r9
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3

  if ( !a1 || !a2 )
    return -1073741811;
  v4 = -1073741811;
  v5 = 0;
  PnpAcquireDependencyRelationsLock(1, a2);
  v6 = (int *)PiGetProviderList(a1);
  v7 = *v6;
  while ( (int *)v7 != v6 )
  {
    v8 = PiListEntryToDependencyEdge(v7, 0);
    v7 = *v9;
    v10 = v8;
    if ( *(_DWORD *)(*(_DWORD *)(v8 + 16) + 24) == a2 )
    {
      v5 = 1;
      PipAddtoRebuildPowerRelationsQueue(a1);
      PipFreeDependencyEdge(v10, 0);
      v4 = 0;
      break;
    }
  }
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  v11 = PpDevNodeUnlockTree(0);
  if ( v5 )
    PipProcessRebuildPowerRelationsQueue(v11, v12, v13, v14);
  return v4;
}
