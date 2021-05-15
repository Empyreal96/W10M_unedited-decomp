// VerifierKeInitializeMutexNoReboot 
 
int __fastcall VerifierKeInitializeMutexNoReboot(unsigned int a1, int a2)
{
  VfUtilSynchronizationObjectSanityChecks(a1, 32);
  return pXdvKeInitializeMutex(a1, a2);
}
