// KiFlushRectangle 
 
unsigned int __fastcall KiFlushRectangle(unsigned int result, unsigned int a2, int a3, int a4, char a5)
{
  unsigned int j; // r3
  unsigned int i; // r4

  if ( a5 )
  {
    for ( ; result < a2; result += a4 )
    {
      for ( i = result & ~(KiMinimumDcacheLine - 1); i < result + a3; i += KiMinimumDcacheLine )
        __mcr(15, 0, i, 7, 6, 1);
    }
  }
  else
  {
    for ( ; result < a2; result += a4 )
    {
      for ( j = result & ~(KiMinimumDcacheLine - 1); j < result + a3; j += KiMinimumDcacheLine )
        __mcr(15, 0, j, 7, 10, 1);
    }
  }
  __dsb(0xFu);
  return result;
}
