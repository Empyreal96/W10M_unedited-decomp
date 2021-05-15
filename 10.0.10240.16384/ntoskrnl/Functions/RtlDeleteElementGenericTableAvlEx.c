// RtlDeleteElementGenericTableAvlEx 
 
int __fastcall RtlDeleteElementGenericTableAvlEx(int a1, int a2)
{
  if ( a2 == *(_DWORD *)(a1 + 32) )
    *(_DWORD *)(a1 + 32) = RealPredecessor(a2);
  ++*(_DWORD *)(a1 + 36);
  DeleteNodeFromTree(a1, a2);
  --*(_DWORD *)(a1 + 24);
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  return (*(int (__fastcall **)(int, int))(a1 + 48))(a1, a2);
}
