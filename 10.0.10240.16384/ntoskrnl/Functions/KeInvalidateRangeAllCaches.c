// KeInvalidateRangeAllCaches 
 
int __fastcall KeInvalidateRangeAllCaches(int a1, int a2)
{
  if ( (KeFeatureBits & 0x100) != 0 )
    return sub_555CA0();
  KiInvalidateCacheRange(a1, a2);
  return off_617A84(1);
}
