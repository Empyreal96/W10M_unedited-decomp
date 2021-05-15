// VerifierExReleaseResourceAndLeaveCriticalRegionNoReboot 
 
int __fastcall VerifierExReleaseResourceAndLeaveCriticalRegionNoReboot(int a1)
{
  ViResourceReleaseSanityChecks();
  return pXdvExReleaseResourceAndLeaveCriticalRegion(a1);
}
