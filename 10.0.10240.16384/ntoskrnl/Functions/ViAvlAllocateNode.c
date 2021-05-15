// ViAvlAllocateNode 
 
int __fastcall ViAvlAllocateNode(int a1)
{
  int v1; // r3

  v1 = *(_DWORD *)(a1 + 56);
  *(_DWORD *)(a1 + 56) = 0;
  return v1 - 16;
}
