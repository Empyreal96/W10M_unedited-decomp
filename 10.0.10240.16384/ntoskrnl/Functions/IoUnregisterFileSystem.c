// IoUnregisterFileSystem 
 
int __fastcall IoUnregisterFileSystem(int a1)
{
  int v2; // r2
  int v3; // r3
  __int64 v4; // kr00_8
  int *v5; // r4
  void (__fastcall *v6)(int, _DWORD); // r3
  int v7; // r0
  unsigned int v8; // r1
  __int16 v9; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(__int16 *)(v2 + 0x134) - 1;
  *(_WORD *)(v2 + 308) = v3;
  ExAcquireResourceExclusiveLite((int)&IopDatabaseResource, 1, v2, v3);
  if ( *(_DWORD *)(a1 + 52) )
  {
    v4 = *(_QWORD *)(a1 + 52);
    if ( *(_DWORD *)(v4 + 4) != a1 + 52 || *(_DWORD *)HIDWORD(v4) != a1 + 52 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v4) = v4;
    *(_DWORD *)(v4 + 4) = HIDWORD(v4);
  }
  v5 = (int *)IopFsNotifyChangeQueueHead;
  while ( v5 != &IopFsNotifyChangeQueueHead )
  {
    v6 = (void (__fastcall *)(int, _DWORD))v5[3];
    v5 = (int *)*v5;
    v6(a1, 0);
  }
  ++IopFsRegistrationOps;
  v7 = ExReleaseResourceLite((int)&IopDatabaseResource);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(v7);
  return IopDecrementDeviceObjectRefCount(a1, 1);
}
