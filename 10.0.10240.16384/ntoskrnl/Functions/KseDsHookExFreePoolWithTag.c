// KseDsHookExFreePoolWithTag 
 
int __fastcall KseDsHookExFreePoolWithTag(int a1)
{
  int vars4; // [sp+Ch] [bp+4h]

  off_617DBC();
  return KsepDsEventPoolFree(a1, vars4);
}
