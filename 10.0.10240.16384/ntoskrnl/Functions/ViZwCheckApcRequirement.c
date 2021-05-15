// ViZwCheckApcRequirement 
 
int __fastcall ViZwCheckApcRequirement(int a1)
{
  int result; // r0
  int v3; // r4
  int v4; // r3

  result = KeGetCurrentIrql(a1);
  v3 = result;
  if ( result
    || *(_WORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x136)
    || (result = KeAreInterruptsEnabled()) == 0
    || (result = KeGetCurrentIrql(result)) != 0 )
  {
    v4 = ViZwBreakForIssues;
    __dmb(0xBu);
    if ( v4 )
      result = VerifierBugCheckIfAppropriate(
                 196,
                 230,
                 a1,
                 v3,
                 *(__int16 *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x136));
  }
  return result;
}
