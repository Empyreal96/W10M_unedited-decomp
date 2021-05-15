// IoRegisterFileSystem 
 
int __fastcall IoRegisterFileSystem(_DWORD *a1)
{
  unsigned int v2; // r2
  int v3; // r2
  int v4; // r3
  int v5; // r3
  __int64 v6; // r0
  int v7; // r3
  _DWORD *v8; // r2
  _DWORD *v9; // r2
  int *v10; // r5
  void (__fastcall *v11)(_DWORD *, int); // r3
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  int v16; // r1
  _DWORD *v17; // r2
  _DWORD *v18; // r0
  _DWORD *v19; // r2

  FsRtlSetDriverBacking(a1[2], 1);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  IopSetFsRegistrationInProgress(1);
  ExAcquireResourceExclusiveLite((int)&IopDatabaseResource, 1, v3, v4);
  v5 = a1[11];
  if ( v5 == 20 )
  {
    HIDWORD(v6) = &IopNetworkFileSystemQueueHead;
  }
  else
  {
    switch ( v5 )
    {
      case 3:
        HIDWORD(v6) = &IopCdRomFileSystemQueueHead;
        break;
      case 8:
        HIDWORD(v6) = &IopDiskFileSystemQueueHead;
        break;
      case 32:
        HIDWORD(v6) = &IopTapeFileSystemQueueHead;
        break;
      default:
        goto LABEL_13;
    }
    *(_DWORD *)(a1[2] + 8) |= 0x80u;
  }
  v7 = a1[7];
  if ( (v7 & 0x10000) != 0 )
  {
    v16 = *(_DWORD *)(HIDWORD(v6) + 4);
    v17 = a1 + 13;
    v18 = *(_DWORD **)(v16 + 4);
    a1[13] = v16;
    a1[14] = v18;
    if ( *v18 != v16 )
      sub_80C33C();
    *v18 = v17;
    *(_DWORD *)(v16 + 4) = v17;
  }
  else if ( (v7 & 0x200) != 0 )
  {
    LODWORD(v6) = *(_DWORD *)HIDWORD(v6);
    v19 = a1 + 13;
    *(_QWORD *)(a1 + 13) = v6;
    if ( *(_DWORD *)(v6 + 4) != HIDWORD(v6) )
      __fastfail(3u);
    *(_DWORD *)(v6 + 4) = v19;
    *(_DWORD *)HIDWORD(v6) = v19;
  }
  else
  {
    v8 = (_DWORD *)*(_DWORD *)HIDWORD(v6);
    LODWORD(v6) = HIDWORD(v6);
    while ( v8 != (_DWORD *)HIDWORD(v6) && (*(v8 - 6) & 0x200) != 0 )
    {
      LODWORD(v6) = v8;
      v8 = (_DWORD *)*v8;
    }
    HIDWORD(v6) = *(_DWORD *)v6;
    v9 = a1 + 13;
    a1[13] = *(_DWORD *)v6;
    a1[14] = v6;
    if ( *(_DWORD *)(HIDWORD(v6) + 4) != (_DWORD)v6 )
      __fastfail(3u);
    *(_DWORD *)(HIDWORD(v6) + 4) = v9;
    *(_DWORD *)v6 = v9;
  }
LABEL_13:
  ++IopFsRegistrationOps;
  a1[7] &= 0xFFFFFF7F;
  v10 = (int *)IopFsNotifyChangeQueueHead;
  while ( v10 != &IopFsNotifyChangeQueueHead )
  {
    v11 = (void (__fastcall *)(_DWORD *, int))v10[3];
    v10 = (int *)*v10;
    v11(a1, 1);
  }
  IopSetFsRegistrationInProgress(0);
  ExReleaseResourceLite((int)&IopDatabaseResource);
  v12 = IopSetFsRegistrationInProgress(0);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  return IopIncrementDeviceObjectRefCount((int)a1, 1);
}
