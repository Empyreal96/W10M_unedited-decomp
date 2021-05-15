// AlpcpAllocateMessageLog 
 
// local variable allocation has failed, the output may be wrong!
int AlpcpAllocateMessageLog()
{
  int result; // r0
  __int64 v1; // kr00_8
  __int64 v2; // kr08_8
  int v3; // r1 OVERLAPPED
  _DWORD *v4; // r2 OVERLAPPED
  __int64 v5; // r4
  _DWORD **v6; // r1
  __int64 v7; // r2

  result = AlpcpFreeMessageLogListHead;
  if ( (int *)AlpcpFreeMessageLogListHead == &AlpcpFreeMessageLogListHead )
  {
    result = AlpcpMessageLogListHead;
    if ( (int *)AlpcpMessageLogListHead == &AlpcpMessageLogListHead )
    {
      result = 0;
    }
    else
    {
      v2 = *(_QWORD *)AlpcpMessageLogListHead;
      if ( *(int **)(AlpcpMessageLogListHead + 4) != &AlpcpMessageLogListHead
        || *(_DWORD *)(v2 + 4) != AlpcpMessageLogListHead )
      {
        __fastfail(3u);
      }
      AlpcpMessageLogListHead = *(_DWORD *)AlpcpMessageLogListHead;
      *(_DWORD *)(v2 + 4) = &AlpcpMessageLogListHead;
      *(_DWORD *)(result + 24) = 0;
      *(_QWORD *)&v3 = *(_QWORD *)(result + 8);
      if ( *(_DWORD *)(v3 + 4) != result + 8 || *v4 != result + 8 )
        __fastfail(3u);
      *v4 = v3;
      LODWORD(v5) = &AlpcpFreeMessageSnapshotListHead;
      *(_DWORD *)(v3 + 4) = v4;
      v6 = (_DWORD **)(result + 28);
      while ( *v6 != v6 )
      {
        LODWORD(v7) = *v6;
        HIDWORD(v7) = (*v6)[1];
        HIDWORD(v5) = **v6;
        if ( v7 != __PAIR64__((unsigned int)v6, *(_DWORD *)(HIDWORD(v5) + 4)) )
          __fastfail(3u);
        *v6 = (_DWORD *)HIDWORD(v5);
        *(_DWORD *)(HIDWORD(v5) + 4) = v6;
        HIDWORD(v5) = dword_6212CC;
        *(_QWORD *)v7 = v5;
        if ( *(int **)HIDWORD(v5) != &AlpcpFreeMessageSnapshotListHead )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v5) = v7;
        dword_6212CC = v7;
      }
    }
  }
  else
  {
    v1 = *(_QWORD *)AlpcpFreeMessageLogListHead;
    if ( *(int **)(AlpcpFreeMessageLogListHead + 4) != &AlpcpFreeMessageLogListHead
      || *(_DWORD *)(v1 + 4) != AlpcpFreeMessageLogListHead )
    {
      __fastfail(3u);
    }
    AlpcpFreeMessageLogListHead = *(_DWORD *)AlpcpFreeMessageLogListHead;
    *(_DWORD *)(v1 + 4) = &AlpcpFreeMessageLogListHead;
  }
  return result;
}
