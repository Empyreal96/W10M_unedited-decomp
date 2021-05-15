// VerifierKeReleaseMutex 
 
int __fastcall VerifierKeReleaseMutex(unsigned int a1, int a2)
{
  if ( a1 < MmHighestUserAddress || a1 + 32 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 32, 0);
  VfDeadlockReleaseResource(a1, 1, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  return pXdvKeReleaseMutex(a1, a2);
}
