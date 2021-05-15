// VerifierExReleaseResourceAndLeavePriorityRegion 
 
int __fastcall VerifierExReleaseResourceAndLeavePriorityRegion(int a1)
{
  ViResourceReleaseSanityChecks();
  return pXdvExReleaseResourceAndLeavePriorityRegion(a1);
}
