// VfAddVerifierEntry 
 
int __fastcall VfAddVerifierEntry(unsigned __int16 *a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r4
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r0
  unsigned int v11; // r4
  int v13[2]; // [sp+0h] [bp-18h] BYREF
  _DWORD v14[4]; // [sp+8h] [bp-10h] BYREF

  v13[0] = (int)a1;
  v13[1] = a2;
  v14[0] = a3;
  v14[1] = a4;
  if ( VfSafeMode )
    return -1073740961;
  VfDriverLock();
  VfInitSystemNoRebootNeeded(KernelVerifier, 0);
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  KeReleaseMutex((int)&ViDriversLoadLock);
  RtlInitUnicodeString((unsigned int)v14, L"*");
  if ( RtlEqualUnicodeString((unsigned __int16 *)v14, a1, 1) )
  {
    v6 = MmAcquireLoadLock();
    v5 = VfDriverEnableVerifierForAll(v6, v7, v8, v9);
    MmReleaseLoadLock(v6);
  }
  else
  {
    v10 = VfSuspectDriversAllocateEntry(a1);
    v11 = v10;
    if ( v10 )
    {
      v5 = MmEnableVerifierForDriver(v10, v13);
      if ( !v13[0] )
        ExFreePoolWithTag(v11);
    }
    else
    {
      v5 = -1073741670;
    }
  }
  return v5;
}
