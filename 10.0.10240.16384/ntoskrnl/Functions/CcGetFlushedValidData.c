// CcGetFlushedValidData 
 
int __fastcall CcGetFlushedValidData(_DWORD *a1, int a2, int a3)
{
  _DWORD *v6; // r4
  int v7; // r0
  int v8; // r0
  _DWORD *v9; // r3
  _DWORD *v10; // r0
  unsigned int *v11; // r6
  int v12; // r7
  unsigned int v13; // r1
  int v14; // r7
  int v15; // r3
  int v16; // r2
  int v17; // r3
  int *v18; // r2
  __int64 v19; // kr18_8
  int **v20; // r0
  int *v21; // r2
  __int64 v22; // r0
  int **v23; // r0
  int v24; // r1
  int v25; // r0
  BOOL v26; // r6
  int *v27; // r2
  __int64 v28; // r0
  int **v29; // r0
  int *v30; // r2
  __int64 v31; // r0
  int **v32; // r0

  if ( !a3 )
    return sub_522F9C();
  v6 = *(_DWORD **)(a2 + 4);
  *a1 = v6[10];
  a1[1] = v6[11];
  if ( v6[19] )
  {
    v7 = v6[26];
    if ( v7 && *(_DWORD *)(v7 + 8) )
    {
      v8 = CcFindBitmapRangeToClean();
      *(_QWORD *)a1 = (*(_QWORD *)(v8 + 8) + *(unsigned int *)(v8 + 16)) << 12;
    }
    v9 = (_DWORD *)v6[4];
    v10 = v6 + 4;
    while ( v9 != v10 && (*((_WORD *)v9 - 8) != 765 || !*((_BYTE *)v9 - 14)) )
      v9 = (_DWORD *)*v9;
    if ( v9 != v10 && *((_QWORD *)v9 - 1) < *(_QWORD *)a1 )
    {
      *a1 = *(v9 - 2);
      a1[1] = *(v9 - 1);
    }
  }
  if ( !a3 )
  {
    v11 = v6 + 45;
    v12 = v6[52];
    v6[46] = 0;
    __dmb(0xBu);
    do
      v13 = __ldrex(v11);
    while ( !v13 && __strex(1u, v11) );
    if ( v13 )
      ExpReleaseFastMutexContended(v6 + 45, v13, 1);
    KfLowerIrql((unsigned __int8)v12);
    KeAbPostRelease(v6 + 45);
    v14 = KeAcquireQueuedSpinLock(5);
    v15 = v6[1] - 1;
    v6[1] = v15;
    if ( v15 )
      goto LABEL_42;
    byte_632771 = 1;
    v16 = v6[24];
    v17 = v6[19];
    if ( (v16 & 0x10000) != 0 )
    {
      if ( !v17 )
      {
        if ( (v16 & 0x3000000) != 0 )
        {
          v18 = v6 + 20;
          v19 = *((_QWORD *)v6 + 10);
          if ( *(_DWORD **)(v19 + 4) != v6 + 20 || *(int **)HIDWORD(v19) != v18 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v19) = v19;
          *(_DWORD *)(v19 + 4) = HIDWORD(v19);
          v20 = (int **)dword_632614;
          *v18 = (int)&CcDirtySharedCacheMapWithLogHandleList;
          v6[21] = v20;
          if ( *v20 != &CcDirtySharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *v20 = v18;
          dword_632614 = (int)(v6 + 20);
        }
        v21 = v6 + 22;
        v22 = *((_QWORD *)v6 + 11);
        if ( *(_DWORD **)(v22 + 4) != v6 + 22 || *(int **)HIDWORD(v22) != v21 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v22) = v22;
        *(_DWORD *)(v22 + 4) = HIDWORD(v22);
        v23 = (int **)dword_632634;
        *v21 = (int)&CcLazyWriterCursor;
        v6[23] = v23;
        if ( *v23 != &CcLazyWriterCursor )
          __fastfail(3u);
        *v23 = v21;
        dword_632634 = (int)(v6 + 22);
      }
      v24 = 1;
      v25 = 1;
    }
    else
    {
      if ( v17 || (v16 & 0x20) != 0 )
        goto LABEL_42;
      v26 = v6[44] != 0;
      if ( (v16 & 0x3000000) != 0 )
      {
        v27 = v6 + 20;
        v28 = *((_QWORD *)v6 + 10);
        if ( *(_DWORD **)(v28 + 4) != v6 + 20 || *(int **)HIDWORD(v28) != v27 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v28) = v28;
        *(_DWORD *)(v28 + 4) = HIDWORD(v28);
        v29 = (int **)dword_632614;
        *v27 = (int)&CcDirtySharedCacheMapWithLogHandleList;
        v6[21] = v29;
        if ( *v29 != &CcDirtySharedCacheMapWithLogHandleList )
          __fastfail(3u);
        *v29 = v27;
        dword_632614 = (int)(v6 + 20);
      }
      v30 = v6 + 22;
      v31 = *((_QWORD *)v6 + 11);
      if ( *(_DWORD **)(v31 + 4) != v6 + 22 || *(int **)HIDWORD(v31) != v30 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v31) = v31;
      *(_DWORD *)(v31 + 4) = HIDWORD(v31);
      v32 = (int **)dword_632634;
      *v30 = (int)&CcLazyWriterCursor;
      v6[23] = v32;
      if ( *v32 != &CcLazyWriterCursor )
        __fastfail(3u);
      *v32 = v30;
      dword_632634 = (int)(v6 + 22);
      v24 = 0;
      v25 = v26;
    }
    CcScheduleLazyWriteScan(v25, v24);
LABEL_42:
    KeReleaseQueuedSpinLock(5, v14);
  }
  return (int)a1;
}
