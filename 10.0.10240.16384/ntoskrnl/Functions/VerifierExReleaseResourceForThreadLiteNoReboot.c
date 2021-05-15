// VerifierExReleaseResourceForThreadLiteNoReboot 
 
int __fastcall VerifierExReleaseResourceForThreadLiteNoReboot(int a1, int a2)
{
  ViResourceReleaseSanityChecks();
  return pXdvExReleaseResourceForThreadLite(a1, a2);
}
