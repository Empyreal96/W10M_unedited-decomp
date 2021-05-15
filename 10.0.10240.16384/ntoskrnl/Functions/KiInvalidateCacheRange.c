// KiInvalidateCacheRange 
 
int __fastcall KiInvalidateCacheRange(int a1, int a2)
{
  unsigned int i; // r3
  int result; // r0

  for ( i = a1 & ~(KiMinimumDcacheLine - 1); i < a1 + a2; i += KiMinimumDcacheLine )
    __mcr(15, 0, i, 7, 14, 1);
  __dsb(0xFu);
  result = KiVoidIcacheRangePoU();
  __mcr(15, 0, 0, 7, 5, 6);
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}
