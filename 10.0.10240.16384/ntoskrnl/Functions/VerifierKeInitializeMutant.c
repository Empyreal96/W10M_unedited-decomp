// VerifierKeInitializeMutant 
 
int __fastcall VerifierKeInitializeMutant(unsigned int a1, int a2)
{
  int result; // r0

  VfUtilSynchronizationObjectSanityChecks(a1, 32);
  pXdvKeInitializeMutant(a1, a2);
  result = VfDeadlockInitializeResource(a1);
  if ( a2 )
    result = VfDeadlockAcquireResource(a1, 1, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0);
  return result;
}
