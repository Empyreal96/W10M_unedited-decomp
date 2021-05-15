// VerifierExAcquireResourceExclusiveLiteNoReboot 
 
int __fastcall VerifierExAcquireResourceExclusiveLiteNoReboot(int a1, int a2)
{
  ViResourceAcquireSanityChecks(a1);
  return pXdvExAcquireResourceExclusiveLite(a1, a2);
}
