// VerifierKeInitializeTimerEx 
 
int __fastcall VerifierKeInitializeTimerEx(unsigned int a1, int a2)
{
  VfUtilSynchronizationObjectSanityChecks(a1, 48);
  KeCheckForTimer(a1, 48);
  return pXdvKeInitializeTimerEx(a1, a2);
}
