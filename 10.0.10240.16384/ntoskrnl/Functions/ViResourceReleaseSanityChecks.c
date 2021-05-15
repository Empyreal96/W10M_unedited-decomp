// ViResourceReleaseSanityChecks 
 
int __fastcall ViResourceReleaseSanityChecks(int a1)
{
  int result; // r0

  result = KeGetCurrentIrql(a1);
  if ( result != 1
    && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) == 0
    && !*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134)
    && result != 2 )
  {
    result = VerifierBugCheckIfAppropriate(
               196,
               56,
               result,
               *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134),
               a1);
  }
  return result;
}
