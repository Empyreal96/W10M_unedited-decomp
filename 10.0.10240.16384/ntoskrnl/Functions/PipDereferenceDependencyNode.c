// PipDereferenceDependencyNode 
 
int __fastcall PipDereferenceDependencyNode(int result)
{
  int v1; // r3

  v1 = *(_DWORD *)(result + 44) - 1;
  *(_DWORD *)(result + 44) = v1;
  if ( !v1 )
    result = PipDeleteDependencyNode();
  return result;
}
