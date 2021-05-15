// KseDsHookExFreePool 
 
int __fastcall KseDsHookExFreePool(int a1)
{
  int vars4; // [sp+Ch] [bp+4h]

  off_617DDC();
  return KsepDsEventPoolFree(a1, vars4, 1701736270);
}
