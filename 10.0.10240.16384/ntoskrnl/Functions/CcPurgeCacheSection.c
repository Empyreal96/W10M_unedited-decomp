// CcPurgeCacheSection 
 
int __fastcall CcPurgeCacheSection(int a1, _QWORD *a2, int a3, char a4)
{
  char v4; // r4
  int v5; // r5
  int v8; // r9
  int v9; // r0
  int v10; // r5
  int v12; // r8
  int v13; // r6
  unsigned int v14; // r3
  int v15; // r6
  int v16; // r3
  int v17; // r2
  int v18; // r3
  int *v19; // r2
  __int64 v20; // r0
  int **v21; // r0
  int v22; // r1
  int v23; // r0
  BOOL v24; // r4
  int *v25; // r2
  __int64 v26; // kr18_8
  int **v27; // r0
  int *v28; // r2
  __int64 v29; // r0
  int **v30; // r0
  int *v31; // r2
  __int64 v32; // r0
  int **v33; // r0
  int i; // [sp+Ch] [bp-24h]

  v4 = a4;
  v5 = a1;
  v8 = 0;
  v9 = KeAcquireQueuedSpinLock(5);
  v10 = *(_DWORD *)(v5 + 4);
  if ( v10 )
  {
    if ( (*(_DWORD *)(v10 + 96) & 0x2000) != 0 )
      return sub_5119C8(v9);
    v4 = a4;
    ++*(_DWORD *)(v10 + 4);
  }
  KeReleaseQueuedSpinLock(5, v9);
  if ( v10 )
  {
    if ( (v4 & 1) != 0 )
      JUMPOUT(0x5119D2);
    if ( (v4 & 8) != 0 )
      JUMPOUT(0x5119F4);
    CcUnmapVacbArray(v10, a2, a3, 0, 1);
    v12 = a1;
    if ( a2 )
      v8 = 1;
  }
  else
  {
    v12 = a1;
  }
  if ( (v4 & 4) != 0 )
    v8 |= 2u;
  if ( (v4 & 4) != 0 )
    v13 = 5;
  else
    v13 = -1;
  for ( i = MmPurgeSection(v12, a2, a3, v8); !i; i = MmPurgeSection(v12, a2, 0, v8) )
  {
    if ( a3 )
      break;
    if ( !MmCanFileBeTruncated(v12, a2) )
      break;
    if ( (v4 & 2) != 0 )
      break;
    KeDelayExecutionThread(0, 0, &CcCollisionDelay);
    if ( !--v13 )
      break;
  }
  if ( v10 )
  {
    if ( a3 )
      goto LABEL_20;
    if ( a2 )
    {
      if ( *a2 >= *(_QWORD *)(v10 + 240) )
      {
LABEL_20:
        v15 = KeAcquireQueuedSpinLock(5);
        v16 = *(_DWORD *)(v10 + 4) - 1;
        *(_DWORD *)(v10 + 4) = v16;
        if ( !v16 )
        {
          byte_632771 = 1;
          v17 = *(_DWORD *)(v10 + 96);
          v18 = *(_DWORD *)(v10 + 76);
          if ( (v17 & 0x10000) != 0 )
          {
            if ( !v18 )
            {
              if ( (v17 & 0x3000000) != 0 )
              {
                v25 = (int *)(v10 + 80);
                v26 = *(_QWORD *)(v10 + 80);
                if ( *(_DWORD *)(v26 + 4) != v10 + 80 || *(int **)HIDWORD(v26) != v25 )
                  __fastfail(3u);
                *(_DWORD *)HIDWORD(v26) = v26;
                *(_DWORD *)(v26 + 4) = HIDWORD(v26);
                v27 = (int **)dword_632614;
                *v25 = (int)&CcDirtySharedCacheMapWithLogHandleList;
                *(_DWORD *)(v10 + 84) = v27;
                if ( *v27 != &CcDirtySharedCacheMapWithLogHandleList )
                  __fastfail(3u);
                *v27 = v25;
                dword_632614 = v10 + 80;
              }
              v28 = (int *)(v10 + 88);
              v29 = *(_QWORD *)(v10 + 88);
              if ( *(_DWORD *)(v29 + 4) != v10 + 88 || *(int **)HIDWORD(v29) != v28 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v29) = v29;
              *(_DWORD *)(v29 + 4) = HIDWORD(v29);
              v30 = (int **)dword_632634;
              *v28 = (int)&CcLazyWriterCursor;
              *(_DWORD *)(v10 + 92) = v30;
              if ( *v30 != &CcLazyWriterCursor )
                __fastfail(3u);
              *v30 = v28;
              dword_632634 = v10 + 88;
            }
            v22 = 1;
            v23 = 1;
          }
          else
          {
            if ( v18 || (v17 & 0x20) != 0 )
              goto LABEL_21;
            v24 = *(_DWORD *)(v10 + 176) != 0;
            if ( (v17 & 0x3000000) != 0 )
            {
              v31 = (int *)(v10 + 80);
              v32 = *(_QWORD *)(v10 + 80);
              if ( *(_DWORD *)(v32 + 4) != v10 + 80 || *(int **)HIDWORD(v32) != v31 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v32) = v32;
              *(_DWORD *)(v32 + 4) = HIDWORD(v32);
              v33 = (int **)dword_632614;
              *v31 = (int)&CcDirtySharedCacheMapWithLogHandleList;
              *(_DWORD *)(v10 + 84) = v33;
              if ( *v33 != &CcDirtySharedCacheMapWithLogHandleList )
                __fastfail(3u);
              *v33 = v31;
              dword_632614 = v10 + 80;
            }
            v19 = (int *)(v10 + 88);
            v20 = *(_QWORD *)(v10 + 88);
            if ( *(_DWORD *)(v20 + 4) != v10 + 88 || *(int **)HIDWORD(v20) != v19 )
              __fastfail(3u);
            *(_DWORD *)HIDWORD(v20) = v20;
            *(_DWORD *)(v20 + 4) = HIDWORD(v20);
            v21 = (int **)dword_632634;
            *v19 = (int)&CcLazyWriterCursor;
            *(_DWORD *)(v10 + 92) = v21;
            if ( *v21 != &CcLazyWriterCursor )
              __fastfail(3u);
            *v21 = v19;
            dword_632634 = v10 + 88;
            v22 = 0;
            v23 = v24;
          }
          CcScheduleLazyWriteScan(v23, v22);
        }
LABEL_21:
        KeReleaseQueuedSpinLock(5, v15);
        return i;
      }
      v14 = ((*(_DWORD *)a2 + 0x3FFFF) & 0xFFFC0000) + 0x40000;
      *(_DWORD *)(v10 + 244) = (__PAIR64__(
                                  (unsigned __int64)(*a2 + 0x3FFFFi64) >> 32,
                                  (*(_DWORD *)a2 + 0x3FFFF) & 0xFFFC0000)
                              + 0x40000) >> 32;
    }
    else
    {
      v14 = 0;
      *(_DWORD *)(v10 + 244) = 0;
    }
    *(_DWORD *)(v10 + 240) = v14;
    goto LABEL_20;
  }
  return i;
}
