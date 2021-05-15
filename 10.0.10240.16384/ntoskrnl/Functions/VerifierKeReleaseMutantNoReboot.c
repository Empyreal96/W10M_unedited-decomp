// VerifierKeReleaseMutantNoReboot 
 
int __fastcall VerifierKeReleaseMutantNoReboot(unsigned int a1, int a2, int a3, int a4)
{
  if ( a1 < MmHighestUserAddress || a1 + 32 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 32, 0);
  return pXdvKeReleaseMutant(a1, a2, a3, a4);
}
