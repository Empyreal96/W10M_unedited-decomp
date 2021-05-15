// PipDependencyGraphDepthFirstSearch 
 
int __fastcall PipDependencyGraphDepthFirstSearch(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v7; // r4
  _DWORD *v8; // r6
  _DWORD *v10; // r8
  int v11; // r0

  *a3 = 0;
  *a4 = 0;
  if ( a1 != a2 )
  {
    v7 = *(_DWORD **)(a1 + 8);
    v8 = (_DWORD *)(a1 + 8);
    do
    {
      if ( v7 == v8 )
        return 0;
      v10 = v7;
      v11 = v7[4];
      v7 = (_DWORD *)*v7;
    }
    while ( !PipDependencyGraphDepthFirstSearch(v11, a2, a3, a4) );
    ++*a3;
    *a4 = v10[6];
  }
  return 1;
}
