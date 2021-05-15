// VerifierExAcquireSharedStarveExclusiveNoReboot 
 
int __fastcall VerifierExAcquireSharedStarveExclusiveNoReboot(int a1, int a2)
{
  ViResourceAcquireSanityChecks(a1);
  return pXdvExAcquireSharedStarveExclusive(a1, a2);
}
