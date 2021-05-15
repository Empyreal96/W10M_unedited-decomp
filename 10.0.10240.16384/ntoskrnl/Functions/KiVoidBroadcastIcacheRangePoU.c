// KiVoidBroadcastIcacheRangePoU 
 
int __fastcall KiVoidBroadcastIcacheRangePoU(int result, unsigned int a2)
{
  unsigned int i; // r3

  for ( i = result & ~(KiMinimumIcacheLine - 1); i < a2; i += KiMinimumIcacheLine )
    __mcr(15, 0, i, 7, 5, 1);
  return result;
}
