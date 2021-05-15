// KseDsHookExAllocatePool 
 
int __fastcall KseDsHookExAllocatePool(int a1, int a2)
{
  int v4; // r4
  int vars4; // [sp+1Ch] [bp+4h]

  v4 = off_617DCC(a1);
  KsepDsEventPoolAllocate(v4, vars4, a1, a2);
  return v4;
}
