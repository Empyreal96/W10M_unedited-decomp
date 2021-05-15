// KeInvalidatePage 
 
int __fastcall KeInvalidatePage(int a1, int a2, int a3, int a4)
{
  if ( (KeFeatureBits & 0x100) != 0 )
    return KeInvalidateAllCaches();
  KiInvalidateCacheRange(a1, 4096);
  return off_617AB8(a3, a4);
}
