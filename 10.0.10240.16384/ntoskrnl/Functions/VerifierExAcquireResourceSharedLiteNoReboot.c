// VerifierExAcquireResourceSharedLiteNoReboot 
 
int __fastcall VerifierExAcquireResourceSharedLiteNoReboot(int a1, int a2)
{
  ViResourceAcquireSanityChecks(a1);
  return pXdvExAcquireResourceSharedLite(a1, a2);
}
