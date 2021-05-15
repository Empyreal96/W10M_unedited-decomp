// sub_45D8F0 
 
int __fastcall sub_45D8F0(int a1, char a2, int a3)
{
  int result; // r0

  result = MmProbeAndLockPages(a1, a2, a3);
  if ( (MmTrackLockedPages & 1) != 0 )
    result = sub_524AF4(result);
  return result;
}
