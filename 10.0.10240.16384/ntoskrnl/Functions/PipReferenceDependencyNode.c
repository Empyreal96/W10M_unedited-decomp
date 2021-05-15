// PipReferenceDependencyNode 
 
int __fastcall PipReferenceDependencyNode(int result)
{
  ++*(_DWORD *)(result + 44);
  return result;
}
