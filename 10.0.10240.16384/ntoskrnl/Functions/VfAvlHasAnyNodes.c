// VfAvlHasAnyNodes 
 
BOOL __fastcall VfAvlHasAnyNodes(int a1)
{
  int v1; // r3

  v1 = *(_DWORD *)(a1 + 4);
  __dmb(0xBu);
  return v1 != 0;
}
