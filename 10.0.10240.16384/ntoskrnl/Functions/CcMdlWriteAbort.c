// CcMdlWriteAbort 
 
int __fastcall CcMdlWriteAbort(int a1, int a2)
{
  _DWORD *v2; // r5
  int v3; // r6
  _DWORD *v4; // r4
  _DWORD *v5; // r7
  int result; // r0
  int v7; // r6
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int *v11; // r2
  __int64 v12; // kr00_8
  int **v13; // r0
  int *v14; // r2
  __int64 v15; // r0
  int **v16; // r0
  int v17; // r1
  int v18; // r0
  int *v19; // r2
  __int64 v20; // kr08_8
  int **v21; // r5
  int *v22; // r2
  __int64 v23; // kr10_8
  int **v24; // r4

  v2 = (_DWORD *)a2;
  v3 = 0;
  v4 = *(_DWORD **)(*(_DWORD *)(a1 + 20) + 4);
  if ( (*(_WORD *)(a2 + 6) & 2) != 0 )
    v3 = 1;
  do
  {
    v5 = (_DWORD *)*v2;
    if ( v3 )
      MmUnlockPages((int)v2);
    result = IoFreeMdl((int)v2);
    v2 = v5;
  }
  while ( v5 );
  if ( v3 )
  {
    v7 = KeAcquireQueuedSpinLock(5);
    v8 = v4[1] - 1;
    v4[1] = v8;
    if ( !v8 )
    {
      byte_632771 = 1;
      v9 = v4[24];
      v10 = v4[19];
      if ( (v9 & 0x10000) != 0 )
      {
        if ( !v10 )
        {
          if ( (v9 & 0x3000000) != 0 )
          {
            v11 = v4 + 20;
            v12 = *((_QWORD *)v4 + 10);
            if ( *(_DWORD **)(v12 + 4) != v4 + 20 || *(int **)HIDWORD(v12) != v11 )
              __fastfail(3u);
            *(_DWORD *)HIDWORD(v12) = v12;
            *(_DWORD *)(v12 + 4) = HIDWORD(v12);
            v13 = (int **)dword_632614;
            *v11 = (int)&CcDirtySharedCacheMapWithLogHandleList;
            v4[21] = v13;
            if ( *v13 != &CcDirtySharedCacheMapWithLogHandleList )
              __fastfail(3u);
            *v13 = v11;
            dword_632614 = (int)(v4 + 20);
          }
          v14 = v4 + 22;
          v15 = *((_QWORD *)v4 + 11);
          if ( *(_DWORD **)(v15 + 4) != v4 + 22 || *(int **)HIDWORD(v15) != v14 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v15) = v15;
          *(_DWORD *)(v15 + 4) = HIDWORD(v15);
          v16 = (int **)dword_632634;
          *v14 = (int)&CcLazyWriterCursor;
          v4[23] = v16;
          if ( *v16 != &CcLazyWriterCursor )
            __fastfail(3u);
          *v16 = v14;
          dword_632634 = (int)(v4 + 22);
        }
        v17 = 1;
        v18 = 1;
      }
      else
      {
        if ( v10 || (v9 & 0x20) != 0 )
          goto LABEL_24;
        v18 = v4[44] != 0;
        if ( (v9 & 0x3000000) != 0 )
        {
          v19 = v4 + 20;
          v20 = *((_QWORD *)v4 + 10);
          if ( *(_DWORD **)(v20 + 4) != v4 + 20 || *(int **)HIDWORD(v20) != v19 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v20) = v20;
          *(_DWORD *)(v20 + 4) = HIDWORD(v20);
          v21 = (int **)dword_632614;
          *v19 = (int)&CcDirtySharedCacheMapWithLogHandleList;
          v4[21] = v21;
          if ( *v21 != &CcDirtySharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *v21 = v19;
          dword_632614 = (int)(v4 + 20);
        }
        v22 = v4 + 22;
        v23 = *((_QWORD *)v4 + 11);
        if ( *(_DWORD **)(v23 + 4) != v4 + 22 || *(int **)HIDWORD(v23) != v22 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v23) = v23;
        *(_DWORD *)(v23 + 4) = HIDWORD(v23);
        v24 = (int **)dword_632634;
        *v22 = (int)&CcLazyWriterCursor;
        v22[1] = (int)v24;
        if ( *v24 != &CcLazyWriterCursor )
          __fastfail(3u);
        *v24 = v22;
        dword_632634 = (int)v22;
        v17 = 0;
      }
      CcScheduleLazyWriteScan(v18, v17);
    }
LABEL_24:
    result = KeReleaseQueuedSpinLock(5, v7);
  }
  return result;
}
