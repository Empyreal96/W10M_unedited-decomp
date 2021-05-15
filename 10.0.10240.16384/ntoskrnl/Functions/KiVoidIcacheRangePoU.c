// KiVoidIcacheRangePoU 
 
int KiVoidIcacheRangePoU()
{
  int result; // r0

  if ( (KiCacheType & 0xC000) == 49152 )
    result = KiVoidIcacheRangePoUWithCatch();
  else
    __mcr(15, 0, 0, 7, 1, 0);
  __mcr(15, 0, 0, 7, 5, 6);
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}
