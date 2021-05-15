// VerifierKeInitializeEvent 
 
int __fastcall VerifierKeInitializeEvent(unsigned int a1, int a2, int a3)
{
  VfUtilSynchronizationObjectSanityChecks(a1, 16);
  return pXdvKeInitializeEvent(a1, a2, a3);
}
