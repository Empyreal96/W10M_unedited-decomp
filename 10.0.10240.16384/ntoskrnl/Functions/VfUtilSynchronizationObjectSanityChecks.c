// VfUtilSynchronizationObjectSanityChecks 
 
int __fastcall VfUtilSynchronizationObjectSanityChecks(unsigned int a1, int a2)
{
  int result; // r0
  int v4; // r1
  int v5; // r2

  if ( a1 < MmHighestUserAddress || a1 + a2 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1);
  result = MmIsSessionAddress(a1);
  if ( result )
    result = VerifierBugCheckIfAppropriate(196, 223, a1);
  if ( (MmVerifierData & 2) != 0 )
  {
    result = MmIsNonPagedSystemAddressValid(a1, v4, v5);
    if ( !result )
      result = VerifierBugCheckIfAppropriate(196, 225, a1);
  }
  return result;
}
