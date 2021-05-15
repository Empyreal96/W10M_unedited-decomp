// PipMergeDependencyNodes 
 
int __fastcall PipMergeDependencyNodes(_DWORD *a1, int a2)
{
  ++a1[11];
  ++*(_DWORD *)(a2 + 44);
  a1[12] |= *(_DWORD *)(a2 + 48);
  PipMoveListEntries(a1 + 7, a2 + 28);
  PipMergeDependencyEdgeList(a1, a2, 0);
  PipMergeDependencyEdgeList(a1, a2, 1);
  PipDereferenceDependencyNode(a1);
  return PipDereferenceDependencyNode(a2);
}
