// PipDeleteDependencyNode 
 
int __fastcall PipDeleteDependencyNode(int a1)
{
  int v2; // r0

  v2 = PipDeleteBindingIds(a1);
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 )
    __fastfail(3u);
  return sub_811988(v2);
}
