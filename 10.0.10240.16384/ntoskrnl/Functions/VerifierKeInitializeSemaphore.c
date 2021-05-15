// VerifierKeInitializeSemaphore 
 
int __fastcall VerifierKeInitializeSemaphore(unsigned int a1, int a2, int a3)
{
  VfUtilSynchronizationObjectSanityChecks(a1, 20);
  return pXdvKeInitializeSemaphore(a1, a2, a3);
}
