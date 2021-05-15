// PipDependencyCopyEdge 
 
int __fastcall PipDependencyCopyEdge(int a1, int a2)
{
  _DWORD *v3; // r5
  _DWORD *v4; // r4
  int result; // r0
  _DWORD *v7; // r3

  v3 = (_DWORD *)(a1 + 28);
  v4 = *(_DWORD **)(a1 + 28);
  for ( result = 0; result >= 0; result = PipAddDependencyEdgeBetweenNodes(*(_DWORD *)(a1 + 20), a2, (int)(v7 + 2)) )
  {
    if ( v4 == v3 )
      break;
    v7 = v4;
    v4 = (_DWORD *)*v4;
  }
  return result;
}
