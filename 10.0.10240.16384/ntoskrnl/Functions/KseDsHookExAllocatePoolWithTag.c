// KseDsHookExAllocatePoolWithTag 
 
int __fastcall KseDsHookExAllocatePoolWithTag(int a1)
{
  int v2; // r4
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = off_617DAC(a1);
  KsepDsEventPoolAllocate(v2, vars4, a1);
  return v2;
}
