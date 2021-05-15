// VerifierKeReleaseMutant 
 
int __fastcall VerifierKeReleaseMutant(unsigned int a1, int a2, int a3, int a4)
{
  int v8; // r1

  if ( a1 < MmHighestUserAddress || a1 + 32 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 32, 0);
  if ( a3 )
    v8 = 2;
  else
    v8 = 1;
  VfDeadlockReleaseResource(a1, v8, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  return pXdvKeReleaseMutant(a1, a2, a3, a4);
}
