// ViKeLowerIrqlSanityChecks 
 
int __fastcall ViKeLowerIrqlSanityChecks(unsigned int a1, unsigned int a2)
{
  int v4; // r3

  if ( (MmVerifierData & 2) != 0 )
  {
    if ( a1 < a2 )
      VerifierBugCheckIfAppropriate(196, 49, a1, a2, 0);
    if ( a1 >= 2 && a2 < 2 )
    {
      v4 = *(unsigned __int8 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5A);
      __dmb(0xBu);
      if ( v4 )
        VerifierBugCheckIfAppropriate(196, 49, a1, a2, 1);
    }
    if ( a2 > 0xF )
      VerifierBugCheckIfAppropriate(196, 49, a1, a2, 0);
  }
  return VfKeIrqlTransitionReserveLogEntry(a1, a2);
}
