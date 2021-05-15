// PipDeleteAllDependencyRelations 
 
int __fastcall PipDeleteAllDependencyRelations(int result, int a2, int a3)
{
  int v3; // r5
  _DWORD *v4; // r4
  int v5; // r3
  _DWORD *v6; // r6
  int v7; // r0
  int v8; // r1
  _DWORD *v9; // r7
  int v10; // r0
  _DWORD *v11; // r8
  int v12; // r1
  int *v13; // r0

  v3 = result;
  if ( result )
    v4 = *(_DWORD **)(*(_DWORD *)(result + 176) + 44);
  else
    v4 = 0;
  if ( v4 )
  {
    v5 = v4[11] + 1;
    v4[11] = v5;
    PipConvertResolutionsToReservations((int)v4, a2, a3, v5);
    v6 = (_DWORD *)v4[2];
    while ( v6 != v4 + 2 )
    {
      v7 = PiListEntryToDependencyEdge((int)v6, 0);
      v6 = (_DWORD *)*v6;
      PipFreeDependencyEdge(v7, v8);
    }
    v9 = (_DWORD *)v4[4];
    while ( v9 != v4 + 4 )
    {
      v10 = PiListEntryToDependencyEdge((int)v9, 1);
      v11 = *(_DWORD **)(v10 + 20);
      v9 = (_DWORD *)*v9;
      ++v11[11];
      PipFreeDependencyEdge(v10, 0);
      v13 = (int *)v11[6];
      if ( v13 )
      {
        if ( (_DWORD *)v11[2] != v11 + 2 )
          PipAttemptDependentStart(v13, v12, (int)(v11 + 2));
      }
      PipDereferenceDependencyNode((int)v11);
    }
    PipUnlinkDeviceObjectAndDependencyNode(v3, v4);
    result = PipDereferenceDependencyNode((int)v4);
  }
  return result;
}
