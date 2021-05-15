// VfDriverEnableVerifierForAll 
 
int __fastcall VfDriverEnableVerifierForAll(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int i; // r4
  unsigned int v6; // r6
  int v7; // r0
  unsigned int v8; // r6
  int v10; // [sp+8h] [bp-18h] BYREF
  int v11[5]; // [sp+Ch] [bp-14h] BYREF

  v10 = a3;
  v11[0] = a4;
  v4 = 0;
  VfDriverLock();
  ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
  for ( i = *(_DWORD *)PsLoadedModuleList; (int *)i != &PsLoadedModuleList; i = *(_DWORD *)i )
  {
    if ( !VfUtilIsProtectedDriver((unsigned __int16 *)(i + 44)) )
    {
      v6 = *(_DWORD *)(i + 24);
      if ( MmIsSessionAddress(v6) || RtlImageNtHeaderEx(1, v6, 0i64, v11) >= 0 )
      {
        v7 = VfSuspectDriversAllocateEntry(i + 44);
        v8 = v7;
        if ( !v7 )
        {
          v4 = -1073741670;
          break;
        }
        v10 = 0;
        v4 = VfDriverEnableVerifier(v7, i, &v10);
        if ( !v10 )
          ExFreePoolWithTag(v8);
        if ( v4 < 0 )
          break;
      }
    }
  }
  ExReleaseResourceLite((int)&PsLoadedModuleResource);
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  KeReleaseMutex((int)&ViDriversLoadLock);
  return v4;
}
