// PipCheckValidNewDependencyEdge 
 
int __fastcall PipCheckValidNewDependencyEdge(int a1, int a2)
{
  int v4; // r3
  int v5; // r1
  int v6; // r3
  int v7; // r2
  _DWORD *v8; // r2
  _DWORD *v9; // r4
  int v11; // r0

  if ( a1 == a2 )
    return 0;
  v4 = *(_DWORD *)(a1 + 24);
  if ( v4 )
    v5 = *(_DWORD *)(*(_DWORD *)(v4 + 176) + 20);
  else
    v5 = 0;
  v6 = *(_DWORD *)(a2 + 24);
  if ( v6 )
    v7 = *(_DWORD *)(*(_DWORD *)(v6 + 176) + 20);
  else
    v7 = 0;
  if ( v5 && v7 )
  {
    do
    {
      v7 = *(_DWORD *)(v7 + 8);
      if ( v7 == v5 )
        return 0;
    }
    while ( v7 != IopRootDeviceNode );
  }
  v8 = (_DWORD *)(a2 + 8);
  v9 = *(_DWORD **)(a2 + 8);
  while ( v9 != v8 )
  {
    v11 = PiListEntryToDependencyEdge((int)v9, 0);
    v9 = (_DWORD *)*v9;
    if ( *(_DWORD *)(v11 + 16) == a1 )
      return 0;
  }
  return 1;
}
