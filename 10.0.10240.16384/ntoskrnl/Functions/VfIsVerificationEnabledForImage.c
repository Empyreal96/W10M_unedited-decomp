// VfIsVerificationEnabledForImage 
 
int __fastcall VfIsVerificationEnabledForImage(int a1)
{
  int v2; // r4

  VfDriverLock();
  v2 = ViIsDriverSuspectForVerifier(a1);
  VfDriverUnlock();
  return v2;
}
