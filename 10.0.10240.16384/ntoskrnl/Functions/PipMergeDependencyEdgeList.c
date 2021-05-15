// PipMergeDependencyEdgeList 
 
int __fastcall PipMergeDependencyEdgeList(_DWORD *a1, int a2, int a3)
{
  _DWORD **v5; // r6
  _DWORD *v6; // r9
  _DWORD *v7; // r10
  int result; // r0
  int v9; // r0
  int v10; // r1
  int v11; // r5
  int v12; // r0
  int v13; // r1
  int v14; // [sp+4h] [bp-2Ch] BYREF
  int v15; // [sp+8h] [bp-28h]
  int v16; // [sp+Ch] [bp-24h]

  v14 = 0;
  v15 = a3;
  v16 = a2;
  if ( a3 )
  {
    v5 = (_DWORD **)(a2 + 16);
    v6 = a1 + 4;
  }
  else
  {
    v5 = (_DWORD **)(a2 + 8);
    v6 = a1 + 2;
  }
  PiPnpRtlBeginOperation(&v14, a2, a3, 0);
  v7 = *v5;
  while ( v7 != v5 )
  {
    v9 = PiListEntryToDependencyEdge((int)v7, v15);
    v7 = (_DWORD *)*v7;
    v11 = v9;
    if ( (_DWORD *)*v6 != v6 )
      return sub_811928();
    if ( v10 )
    {
      v12 = *(_DWORD *)(v9 + 20);
      *(_DWORD *)(v11 + 16) = a1;
      v13 = (int)a1;
    }
    else
    {
      v13 = *(_DWORD *)(v9 + 16);
      *(_DWORD *)(v9 + 20) = a1;
      v12 = (int)a1;
    }
    PipNotifyDependenciesChanged(v12, v13);
    ++a1[11];
    PipDereferenceDependencyNode(a2);
  }
  PipMoveListEntries(v6, (int)v5);
  result = v14;
  if ( v14 )
    result = PiPnpRtlEndOperation(v14);
  return result;
}
