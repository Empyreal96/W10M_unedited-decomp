// VerifierExReleaseResourceLiteNoReboot 
 
int __fastcall VerifierExReleaseResourceLiteNoReboot(int a1)
{
  ViResourceReleaseSanityChecks();
  return pXdvExReleaseResourceLite(a1);
}
