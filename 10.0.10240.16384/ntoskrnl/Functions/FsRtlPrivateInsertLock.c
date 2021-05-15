// FsRtlPrivateInsertLock 
 
int __fastcall FsRtlPrivateInsertLock(_QWORD *a1, int a2, int a3)
{
  int v6; // r0
  int v7; // r5
  int v9; // r3
  int v10; // r0
  int v11; // r5

  if ( *(_BYTE *)(a3 + 16) )
  {
    v10 = ExAllocateFromNPagedLookasideList(&FsRtlExclusiveLockLookasideList);
    v11 = v10;
    if ( v10 )
    {
      memmove(v10 + 16, a3, 0x28u);
      FsRtlPrivateInsertExclusiveLock(a1 + 2, v11);
      v9 = v11 + 16;
      goto LABEL_6;
    }
LABEL_11:
    JUMPOUT(0x51E056);
  }
  v6 = ExAllocateFromNPagedLookasideList(&FsRtlSharedLockLookasideList);
  v7 = v6;
  if ( !v6 )
    goto LABEL_11;
  memmove(v6 + 8, a3, 0x28u);
  if ( !FsRtlPrivateInsertSharedLock(a1 + 2, v7) )
    return sub_51E04C();
  v9 = v7 + 8;
LABEL_6:
  *(_DWORD *)(a2 + 72) = v9;
  if ( *(_QWORD *)a3 < *a1 )
    *a1 = *(_QWORD *)a3;
  return 1;
}
