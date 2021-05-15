// MmEnableVerifierForDriver 
 
int __fastcall MmEnableVerifierForDriver(int a1, _DWORD *a2)
{
  int v4; // r5
  int v5; // r4

  *a2 = 0;
  v4 = MmAcquireLoadLock();
  v5 = VfDriverEnableVerifier(a1, 0, a2);
  MmReleaseLoadLock(v4);
  return v5;
}
