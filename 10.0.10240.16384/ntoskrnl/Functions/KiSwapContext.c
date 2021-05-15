// KiSwapContext 
 
int __fastcall KiSwapContext(int a1, int a2, int a3)
{
  return SwapContext(a1, a2, a3, ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408);
}
