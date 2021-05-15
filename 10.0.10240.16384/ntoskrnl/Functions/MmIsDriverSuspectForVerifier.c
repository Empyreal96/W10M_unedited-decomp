// MmIsDriverSuspectForVerifier 
 
int __fastcall MmIsDriverSuspectForVerifier(int a1)
{
  int v1; // r4
  int v2; // r4

  v1 = *(_DWORD *)(a1 + 20);
  if ( !v1 )
    return 0;
  VfDriverLock();
  v2 = ViIsDriverSuspectForVerifier(v1);
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  KeReleaseMutex((int)&ViDriversLoadLock);
  return v2;
}
