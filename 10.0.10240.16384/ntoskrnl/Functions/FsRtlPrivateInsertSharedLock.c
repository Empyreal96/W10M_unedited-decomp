// FsRtlPrivateInsertSharedLock 
 
int __fastcall FsRtlPrivateInsertSharedLock(int a1, int a2)
{
  int v4; // r0
  int v5; // r4
  int v6; // r0
  int v7; // r2
  __int64 v8; // r0
  int v9; // r2
  int result; // r0
  int *v11; // r1
  _DWORD *v12; // r0
  unsigned __int64 v13; // kr00_8
  unsigned __int64 v14; // kr08_8
  char v15[4]; // [sp+8h] [bp-20h] BYREF
  int v16[7]; // [sp+Ch] [bp-1Ch] BYREF

  v4 = FsRtlFindFirstOverlappingSharedNode(*(_DWORD *)(a1 + 4), a2 + 8, a2 + 40, v16, v15);
  v5 = v4;
  if ( v4 )
  {
    v11 = *(int **)(v4 - 16);
    v12 = (_DWORD *)(v4 - 16);
    if ( v11 )
    {
      v13 = *(_QWORD *)(a2 + 8);
      do
      {
        v14 = *((_QWORD *)v11 + 1);
        if ( v13 < v14 || v13 == v14 && (!*(_QWORD *)(a2 + 16) || *((_QWORD *)v11 + 2)) )
          break;
        v12 = v11;
        v11 = (int *)*v11;
      }
      while ( v11 );
    }
    if ( !*v12 )
      *(_DWORD *)(v5 + 12) = a2;
    *(_DWORD *)a2 = *v12;
    *v12 = a2;
    *(_DWORD *)(a1 + 4) = RtlSplay(v5);
    if ( *(_QWORD *)(a2 + 40) <= *(_QWORD *)(v5 - 8) )
    {
      if ( *(_BYTE *)(v5 - 12) )
        FsRtlSplitLocks(v5 - 16, 0, 0, 0);
      return 1;
    }
    result = sub_51E05C();
  }
  else
  {
    v6 = ExAllocateFromNPagedLookasideList(&FsRtlLockTreeNodeLookasideList);
    v7 = v6;
    if ( v6 )
    {
      v8 = (unsigned int)(v6 + 16);
      *(_QWORD *)v8 = v8;
      *(_DWORD *)(v8 + 8) = 0;
      *(_BYTE *)(v7 + 4) = 0;
      *(_DWORD *)(v7 + 28) = a2;
      *(_DWORD *)v7 = a2;
      *(_DWORD *)(v7 + 8) = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(v7 + 12) = *(_DWORD *)(a2 + 44);
      v9 = v16[0];
      *(_DWORD *)a2 = 0;
      if ( v9 )
      {
        if ( v15[0] )
          *(_DWORD *)(v9 + 4) = v8;
        else
          *(_DWORD *)(v9 + 8) = v8;
        *(_DWORD *)v8 = v9;
        LODWORD(v8) = RtlSplay(v8);
      }
      *(_DWORD *)(a1 + 4) = v8;
      return 1;
    }
    result = 0;
  }
  return result;
}
