// CcMdlWriteComplete2 
 
int __fastcall CcMdlWriteComplete2(int a1, unsigned int *a2, int a3)
{
  _DWORD *v4; // r7
  unsigned int v5; // r10
  _DWORD *v6; // r4
  int v7; // r5
  _DWORD *v8; // r6
  _DWORD *v9; // r8
  int result; // r0
  unsigned int v11; // r3
  unsigned int v12; // r2
  int v13; // r6
  int v14; // r3
  _DWORD *v15; // r4
  int v16; // r2
  int v17; // r3
  int v18; // r5
  int *v19; // r2
  __int64 v20; // kr08_8
  int **v21; // r0
  int *v22; // r2
  __int64 v23; // r0
  int **v24; // r0
  int v25; // r1
  int v26; // r0
  int *v27; // r2
  __int64 v28; // r0
  int **v29; // r0
  int *v30; // r2
  __int64 v31; // r0
  int **v32; // r0
  unsigned int v33; // [sp+8h] [bp-38h]
  unsigned __int64 v34; // [sp+10h] [bp-30h] BYREF

  v4 = (_DWORD *)a3;
  v5 = *a2;
  v6 = *(_DWORD **)(*(_DWORD *)(a1 + 20) + 4);
  v7 = 0;
  v33 = a2[1];
  LODWORD(v34) = *a2;
  HIDWORD(v34) = v33;
  v8 = (_DWORD *)a3;
  if ( (*(_WORD *)(a3 + 6) & 2) != 0 )
    v7 = 1;
  do
  {
    v9 = (_DWORD *)*v8;
    if ( v7 )
      MmUnlockPages(v8);
    if ( (*(_DWORD *)(a1 + 44) & 0x10) != 0 )
      return sub_51AC0C();
    CcSetDirtyInMask(v6, &v34, v8[5], 0);
    v11 = v8[5];
    v8 = v9;
    v12 = (__PAIR64__(v33, v5) + v11) >> 32;
    v5 += v11;
    v33 = v12;
    v34 = __PAIR64__(v12, v5);
  }
  while ( v9 );
  if ( v7 )
  {
    v13 = KeAcquireQueuedSpinLock(5);
    v14 = v6[1] - 1;
    v6[1] = v14;
    if ( !v14 )
    {
      byte_632771 = 1;
      v16 = v6[24];
      v17 = v6[19];
      if ( (v16 & 0x10000) != 0 )
      {
        if ( !v17 )
        {
          if ( (v16 & 0x3000000) != 0 )
          {
            v19 = v6 + 20;
            v20 = *((_QWORD *)v6 + 10);
            if ( *(_DWORD **)(v20 + 4) != v6 + 20 || *(int **)HIDWORD(v20) != v19 )
              __fastfail(3u);
            *(_DWORD *)HIDWORD(v20) = v20;
            *(_DWORD *)(v20 + 4) = HIDWORD(v20);
            v21 = (int **)dword_632614;
            *v19 = (int)&CcDirtySharedCacheMapWithLogHandleList;
            v6[21] = v21;
            if ( *v21 != &CcDirtySharedCacheMapWithLogHandleList )
              __fastfail(3u);
            *v21 = v19;
            dword_632614 = (int)(v6 + 20);
          }
          v22 = v6 + 22;
          v23 = *((_QWORD *)v6 + 11);
          if ( *(_DWORD **)(v23 + 4) != v6 + 22 || *(int **)HIDWORD(v23) != v22 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v23) = v23;
          *(_DWORD *)(v23 + 4) = HIDWORD(v23);
          v24 = (int **)dword_632634;
          *v22 = (int)&CcLazyWriterCursor;
          v6[23] = v24;
          if ( *v24 != &CcLazyWriterCursor )
            __fastfail(3u);
          *v24 = v22;
          dword_632634 = (int)(v6 + 22);
        }
        v25 = 1;
        v26 = 1;
      }
      else
      {
        if ( v17 || (v16 & 0x20) != 0 )
          goto LABEL_10;
        v18 = 0;
        if ( v6[44] )
          v18 = 1;
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
        v25 = 0;
        v26 = v18;
      }
      CcScheduleLazyWriteScan(v26, v25);
    }
LABEL_10:
    KeReleaseQueuedSpinLock(5, v13);
    goto LABEL_11;
  }
  do
  {
LABEL_11:
    v15 = (_DWORD *)*v4;
    result = IoFreeMdl((int)v4);
    v4 = v15;
  }
  while ( v15 );
  return result;
}
