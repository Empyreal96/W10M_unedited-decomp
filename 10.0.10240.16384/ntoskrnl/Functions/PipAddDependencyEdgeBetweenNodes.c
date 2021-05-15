// PipAddDependencyEdgeBetweenNodes 
 
int __fastcall PipAddDependencyEdgeBetweenNodes(int a1, int a2, int a3)
{
  _DWORD *v4; // r5
  int v7; // r4
  int v8; // r3
  int v9; // r0

  v4 = *(_DWORD **)(a1 + 8);
  v7 = 0;
  while ( v4 != (_DWORD *)(a1 + 8) )
  {
    v8 = v4[4];
    v4 = (_DWORD *)*v4;
    if ( v8 == a2 )
    {
      PipAddRequestToEdge();
      return v7;
    }
  }
  if ( !PipCheckValidNewDependencyEdge(a1, a2) )
    return -1073741823;
  v9 = PipCreateNewDependencyEdge(a1, a2, a3);
  if ( !v9 )
    return -1073741670;
  if ( *(_DWORD *)(*(_DWORD *)(v9 + 16) + 24) )
    PipAddtoRebuildPowerRelationsQueue(*(_DWORD *)(*(_DWORD *)(v9 + 20) + 24));
  return 0;
}
