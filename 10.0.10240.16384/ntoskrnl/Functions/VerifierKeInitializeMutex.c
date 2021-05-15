// VerifierKeInitializeMutex 
 
int __fastcall VerifierKeInitializeMutex(unsigned int a1, int a2)
{
  VfUtilSynchronizationObjectSanityChecks(a1, 32);
  pXdvKeInitializeMutex(a1, a2);
  return VfDeadlockInitializeResource(a1);
}
