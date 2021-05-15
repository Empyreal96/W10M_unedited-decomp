// PipNotifyDeviceDependencyList 
 
int __fastcall PipNotifyDeviceDependencyList(int a1, int a2)
{
  int v2; // r4
  _DWORD **v4; // r0
  _DWORD *v5; // r4
  _DWORD *v6; // r5
  int v8; // r0
  int v9; // r1
  int v10; // r0

  v2 = *(_DWORD *)(a1 + 16);
  PnpAcquireDependencyRelationsLock(0);
  if ( a2 )
  {
    if ( a2 != 1 )
      goto LABEL_5;
    v4 = (_DWORD **)PiGetDependentList(v2);
  }
  else
  {
    v4 = (_DWORD **)PiGetProviderList(v2);
  }
  v5 = v4;
  v6 = *v4;
  while ( v6 != v5 )
  {
    v8 = PiListEntryToDependencyEdge((int)v6, a2);
    v6 = (_DWORD *)*v6;
    if ( a2 )
    {
      v10 = *(_DWORD *)(v8 + 20);
      v9 = 0;
    }
    else
    {
      v9 = *(_DWORD *)(v8 + 16);
      v10 = 0;
    }
    PipNotifyDependenciesChanged(v10, v9);
  }
LABEL_5:
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  return PpDevNodeUnlockTree(0);
}
