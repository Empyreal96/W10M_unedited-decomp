// IoTestDependency 
 
int __fastcall IoTestDependency(int a1, int a2)
{
  int v2; // r4
  int v3; // r1

  v2 = 0;
  if ( !a1 || !a2 || a1 == a2 )
    return -1073741811;
  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 44);
  if ( !*(_DWORD *)(*(_DWORD *)(a1 + 176) + 44) || !v3 )
    return sub_52716C();
  PipFindDependencyNodePath();
  return v2;
}
