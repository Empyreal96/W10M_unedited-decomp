// KeSweepIcacheRange 
 
int *__fastcall KeSweepIcacheRange(int a1, int a2, unsigned int a3)
{
  int *result; // r0
  unsigned int v5; // r3
  unsigned int i; // r1

  result = &KiICacheFlushPromoteThreshold;
  if ( a3 > KiICacheFlushPromoteThreshold )
    return (int *)KeSweepIcache();
  v5 = a2 & ~(KiMinimumDcacheLine - 1);
  for ( i = a2 + a3; v5 < i; v5 += KiMinimumDcacheLine )
    __mcr(15, 0, v5, 7, 11, 1);
  __dsb(0xFu);
  if ( (KiCacheType & 0xC000) == 49152 )
    return (int *)sub_544C00();
  __mcr(15, 0, 0, 7, 1, 0);
  __mcr(15, 0, 0, 7, 5, 6);
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}
