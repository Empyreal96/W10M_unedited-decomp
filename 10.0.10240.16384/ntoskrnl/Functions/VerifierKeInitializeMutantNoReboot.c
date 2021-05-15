// VerifierKeInitializeMutantNoReboot 
 
int __fastcall VerifierKeInitializeMutantNoReboot(unsigned int a1, int a2)
{
  VfUtilSynchronizationObjectSanityChecks(a1, 32);
  return pXdvKeInitializeMutant(a1, a2);
}
