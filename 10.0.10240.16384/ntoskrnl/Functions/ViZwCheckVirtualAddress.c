// ViZwCheckVirtualAddress 
 
unsigned int __fastcall ViZwCheckVirtualAddress(unsigned int result, int a2)
{
  int v2; // r3

  if ( result && result < MmHighestUserAddress )
  {
    v2 = ViZwBreakForIssues;
    __dmb(0xBu);
    if ( v2 )
      result = VerifierBugCheckIfAppropriate(196, 227, a2, result, 0);
  }
  return result;
}
