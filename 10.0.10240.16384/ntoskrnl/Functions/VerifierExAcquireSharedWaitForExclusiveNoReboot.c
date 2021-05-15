// VerifierExAcquireSharedWaitForExclusiveNoReboot 
 
int __fastcall VerifierExAcquireSharedWaitForExclusiveNoReboot(int a1, int a2)
{
  ViResourceAcquireSanityChecks(a1);
  return pXdvExAcquireSharedWaitForExclusive(a1, a2);
}
