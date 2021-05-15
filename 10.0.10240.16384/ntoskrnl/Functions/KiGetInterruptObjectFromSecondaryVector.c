// KiGetInterruptObjectFromSecondaryVector 
 
int __fastcall KiGetInterruptObjectFromSecondaryVector(int a1)
{
  int v1; // r3

  v1 = 0;
  if ( (unsigned int)(a1 - 4096) < 0x100 )
    v1 = *(_DWORD *)(KiGlobalSecondaryIDT + 28 * (a1 - 4096) + 24);
  return v1;
}
