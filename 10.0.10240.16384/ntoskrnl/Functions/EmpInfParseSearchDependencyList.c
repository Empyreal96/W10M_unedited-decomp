// EmpInfParseSearchDependencyList 
 
int __fastcall EmpInfParseSearchDependencyList(_DWORD **a1, int a2)
{
  _DWORD *v2; // r2
  int v3; // r4

  v2 = *a1;
  v3 = 0;
  while ( v2 )
  {
    if ( *(v2 - 1) == a2 )
      return 1;
    v2 = (_DWORD *)*v2;
  }
  return v3;
}
