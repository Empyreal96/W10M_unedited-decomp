// VerifierKeReleaseMutexNoReboot 
 
int __fastcall VerifierKeReleaseMutexNoReboot(unsigned int a1, int a2)
{
  if ( a1 < MmHighestUserAddress || a1 + 32 < a1 )
    VerifierBugCheckIfAppropriate(196, 224, a1, 32, 0);
  return pXdvKeReleaseMutex(a1, a2);
}
