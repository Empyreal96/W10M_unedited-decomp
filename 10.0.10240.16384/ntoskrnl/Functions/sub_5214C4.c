// sub_5214C4 
 
void __fastcall sub_5214C4(int a1, int a2)
{
  int v2; // r4
  unsigned int v3; // r5
  int v4; // r2
  int v5; // r3

  if ( v3 >= *(_DWORD *)(a2 + 8968) - v2 && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) == 0 )
  {
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v4 = 0;
    }
    else
    {
      __disable_irq();
      v4 = 1;
    }
    v5 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v4 )
      __enable_irq();
    if ( (v5 & 0x10001) == 0 )
    {
      ++*(_DWORD *)(a2 + 8944);
      JUMPOUT(0x454ECC);
    }
  }
  JUMPOUT(0x454ECA);
}
