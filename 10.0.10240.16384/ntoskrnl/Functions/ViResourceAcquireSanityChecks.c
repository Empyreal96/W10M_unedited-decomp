// ViResourceAcquireSanityChecks 
 
int __fastcall ViResourceAcquireSanityChecks(int result, int a2, int a3)
{
  int v5; // r5

  v5 = result;
  if ( (result & 3) != 0 )
    result = VerifierBugCheckIfAppropriate(196, 61, 0, 0, result);
  if ( !a3 )
  {
    result = KeGetCurrentIrql(result);
    if ( result != 1
      && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) == 0
      && !*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134)
      && (result != 2 || a2) )
    {
      result = VerifierBugCheckIfAppropriate(
                 196,
                 55,
                 result,
                 *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134),
                 v5);
    }
  }
  return result;
}
