// FsRtlInitSystem 
 
int FsRtlInitSystem()
{
  int v0; // r0
  unsigned int v1; // r4
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v6; // [sp+10h] [bp-20h] BYREF
  __int16 v7[2]; // [sp+18h] [bp-18h] BYREF
  const __int16 *v8; // [sp+1Ch] [bp-14h]

  v0 = ExAllocatePoolWithTag(528, 896, 1953649478);
  v1 = 0;
  for ( FsRtlPagingIoResources = v0; ; v0 = FsRtlPagingIoResources )
  {
    v2 = ExInitializeResourceLite(v0 + v1);
    v1 += 56;
    if ( v1 >= 0x380 )
      break;
  }
  v3 = FsRtlInitializeTunnels(v2);
  v4 = FsRtlInitializeFileLocks(v3);
  FsRtlInitializeLargeMcbs(v4);
  ExInitializePagedLookasideList((int)&FsRtlEcpListLookaside, 0, 0, 0, 16, 1818579782, 0);
  FsRtlpUncSemaphore = 5;
  byte_631E82 = 5;
  dword_631E84 = 1;
  dword_631E8C = (int)&dword_631E88;
  dword_631E88 = (int)&dword_631E88;
  dword_631E90 = 0x7FFFFFFF;
  v8 = L"Win95TruncatedExtensions";
  v7[0] = 48;
  v7[1] = 50;
  if ( FsRtlGetCompatibilityModeValue(v7, &v6) >= 0 && v6 )
    FsRtlSafeExtensions = 0;
  if ( FsRtlInitializeWorkerThread() < 0 || FsFilterInit() < 0 || FsRtlInitializeSmssEvent() < 0 )
    return 0;
  FsRtlInitializeTieringHeat();
  return 1;
}
