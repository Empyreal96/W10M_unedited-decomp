// IoDuplicateDependency 
 
int __fastcall IoDuplicateDependency(int a1, int a2, int a3, int a4)
{
  int v6; // r5
  int *v7; // r0
  int v8; // r4
  _DWORD **v9; // r0
  _DWORD *v10; // r8
  _DWORD *v11; // r6
  int v12; // r0
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r0
  int v18; // r1
  int v19; // r2
  int v20; // r3
  int v22; // [sp+0h] [bp-20h] BYREF
  int v23; // [sp+4h] [bp-1Ch]
  int v24; // [sp+8h] [bp-18h]

  v22 = a2;
  v23 = a3;
  v24 = a4;
  if ( !a1 || !a2 )
    return -1073741811;
  v6 = 0;
  PnpAcquireDependencyRelationsLock(1, a2);
  if ( !*(_DWORD *)(*(_DWORD *)(a1 + 176) + 44) )
    goto LABEL_4;
  v22 = 0;
  v23 = a2;
  v7 = PipQueryBindingResolution(&v22);
  v8 = (int)v7;
  if ( v7 )
  {
    ++v7[11];
  }
  else
  {
    v8 = PipCreateDependencyNode();
    if ( !v8 )
    {
      v6 = -1073741670;
LABEL_4:
      ExReleaseResourceLite((int)&PiDependencyRelationsLock);
      PpDevNodeUnlockTree(0);
      return v6;
    }
  }
  v9 = (_DWORD **)PiGetDependentList(a1);
  v10 = *v9;
  v11 = v9;
  while ( v10 != v11 )
  {
    v12 = PiListEntryToDependencyEdge((int)v10, 1);
    v10 = (_DWORD *)*v10;
    v13 = PipDependencyCopyEdge(v12, v8);
    if ( v13 < 0 )
    {
      v6 = v13;
      break;
    }
  }
  PipDereferenceDependencyNode(v8);
  PipAddDependentsToRebuildPowerRelationsQueue(a2, v14, v15, v16);
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  v17 = PpDevNodeUnlockTree(0);
  PipProcessRebuildPowerRelationsQueue(v17, v18, v19, v20);
  return v6;
}
