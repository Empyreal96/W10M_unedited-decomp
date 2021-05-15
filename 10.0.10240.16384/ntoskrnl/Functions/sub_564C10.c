// sub_564C10 
 
int __fastcall sub_564C10(int a1, int a2, int a3, int a4, int a5)
{
  int result; // r0

  result = MmProbeAndLockPages(a1);
  if ( (MmTrackLockedPages & 1) != 0 )
    result = MmUpdateMdlTracker(a1, *(_DWORD *)(*(_DWORD *)(a4 + 8) + 4 * a5 + 56), a4);
  return result;
}
