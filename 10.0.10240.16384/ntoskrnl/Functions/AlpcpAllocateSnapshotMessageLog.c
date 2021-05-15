// AlpcpAllocateSnapshotMessageLog 
 
int AlpcpAllocateSnapshotMessageLog()
{
  int result; // r0
  int v1; // r2
  __int64 v2; // kr00_8
  __int64 v3; // kr08_8
  int **v4; // r4
  int *v5; // r0
  __int64 v6; // kr10_8
  int **v7; // r7
  int **v8; // r0
  __int64 v9; // r2

  while ( 1 )
  {
    result = AlpcpFreeMessageSnapshotListHead;
    if ( (int *)AlpcpFreeMessageSnapshotListHead != &AlpcpFreeMessageSnapshotListHead )
      break;
    v1 = AlpcpMessageLogListHead;
    if ( (int *)AlpcpMessageLogListHead == &AlpcpMessageLogListHead )
      return 0;
    v2 = *(_QWORD *)AlpcpMessageLogListHead;
    if ( *(int **)(AlpcpMessageLogListHead + 4) != &AlpcpMessageLogListHead
      || *(_DWORD *)(v2 + 4) != AlpcpMessageLogListHead )
    {
      __fastfail(3u);
    }
    AlpcpMessageLogListHead = *(_DWORD *)AlpcpMessageLogListHead;
    *(_DWORD *)(v2 + 4) = &AlpcpMessageLogListHead;
    *(_DWORD *)(v1 + 24) = 0;
    v3 = *(_QWORD *)(v1 + 8);
    if ( *(_DWORD *)(v3 + 4) != v1 + 8 || *(_DWORD *)HIDWORD(v3) != v1 + 8 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v3) = v3;
    *(_DWORD *)(v3 + 4) = HIDWORD(v3);
    v4 = (int **)(v1 + 28);
    while ( *v4 != (int *)v4 )
    {
      v5 = *v4;
      v6 = *(_QWORD *)*v4;
      if ( (int **)HIDWORD(v6) != v4 || *(int **)(v6 + 4) != v5 )
        __fastfail(3u);
      *v4 = (int *)v6;
      *(_DWORD *)(v6 + 4) = v4;
      v7 = (int **)dword_6212CC;
      *v5 = (int)&AlpcpFreeMessageSnapshotListHead;
      v5[1] = (int)v7;
      if ( *v7 != &AlpcpFreeMessageSnapshotListHead )
        __fastfail(3u);
      *v7 = v5;
      dword_6212CC = (int)v5;
    }
    v8 = (int **)dword_6212D4;
    *(_DWORD *)v1 = &AlpcpFreeMessageLogListHead;
    *(_DWORD *)(v1 + 4) = v8;
    if ( *v8 != &AlpcpFreeMessageLogListHead )
      __fastfail(3u);
    *v8 = (int *)v1;
    dword_6212D4 = v1;
  }
  v9 = *(_QWORD *)AlpcpFreeMessageSnapshotListHead;
  if ( *(int **)(AlpcpFreeMessageSnapshotListHead + 4) != &AlpcpFreeMessageSnapshotListHead
    || *(_DWORD *)(v9 + 4) != AlpcpFreeMessageSnapshotListHead )
  {
    __fastfail(3u);
  }
  AlpcpFreeMessageSnapshotListHead = *(_DWORD *)AlpcpFreeMessageSnapshotListHead;
  *(_DWORD *)(v9 + 4) = &AlpcpFreeMessageSnapshotListHead;
  return result;
}
