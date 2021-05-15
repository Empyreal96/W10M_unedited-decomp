// CcSetFileSizesEx 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CcSetFileSizesEx(int a1, int a2)
{
  unsigned int v2; // r7
  unsigned int v4; // r9 OVERLAPPED
  unsigned int v5; // r10 OVERLAPPED
  int v6; // r8
  int v7; // r0
  int v8; // r3
  int v9; // r4
  unsigned int v10; // r1 OVERLAPPED
  unsigned int v11; // r2 OVERLAPPED
  unsigned int v12; // r9
  int v13; // r3
  int v15; // r0
  int v16; // r2
  int v17; // r3
  int *v18; // r2
  __int64 v19; // r0
  int **v20; // r1
  int v21; // r1
  int v22; // r0
  int v23; // r0
  int v24; // r1
  int v25; // r9
  int v26; // r3
  int v27; // r2
  int v28; // r3
  int *v29; // r2
  __int64 v30; // r0
  int **v31; // r1
  int v32; // r1
  int v33; // r0
  BOOL v34; // lr
  int *v35; // r2
  __int64 v36; // r0
  int **v37; // r1
  int *v38; // r2
  __int64 v39; // r0
  int **v40; // r1
  int *v41; // r2
  __int64 v42; // r0
  int **v43; // r1
  int *v44; // r2
  __int64 v45; // r0
  int **v46; // r1
  int *v47; // r2
  __int64 v48; // r0
  int **v49; // r1
  BOOL v50; // r7
  int *v51; // r2
  __int64 v52; // r0
  int **v53; // r1
  __int64 v54; // [sp+8h] [bp-48h] BYREF
  unsigned int v55; // [sp+10h] [bp-40h]
  int v56; // [sp+14h] [bp-3Ch]
  int v57; // [sp+18h] [bp-38h]
  int v58; // [sp+1Ch] [bp-34h]
  unsigned __int64 v59; // [sp+20h] [bp-30h] BYREF
  int v60; // [sp+28h] [bp-28h]

  v2 = *(_DWORD *)(a2 + 8);
  *(_QWORD *)&v4 = *(_QWORD *)a2;
  v55 = *(_DWORD *)(a2 + 12);
  v56 = a1;
  v59 = __PAIR64__(v55, v2);
  v6 = 0;
  v57 = *(_DWORD *)(a2 + 16);
  v58 = *(_DWORD *)(a2 + 20);
  v7 = KeAcquireQueuedSpinLock(5);
  v8 = *(_DWORD *)(a1 + 20);
  LODWORD(v54) = v7;
  v9 = *(_DWORD *)(v8 + 4);
  if ( !v9 || !*(_DWORD *)(v9 + 108) )
  {
    KeReleaseQueuedSpinLock(5, v7);
    if ( (v2 & 0xFFF) != 0 )
    {
      MmFlushSection(*(_DWORD *)(a1 + 20), &v59, 1);
      v6 = v60;
      if ( v60 < 0 )
        return v6;
    }
    if ( !CcPurgeCacheSection(*(_DWORD *)(a1 + 20), &v59, 0, 0) )
      return -1073740747;
    return 0;
  }
  if ( __SPAIR64__(v5, v4) >= *(_QWORD *)(v9 + 8) )
    v6 = 0;
  if ( __SPAIR64__(v5, v4) <= *(_QWORD *)(v9 + 24) )
  {
LABEL_6:
    *(_QWORD *)&v10 = *(_QWORD *)(v9 + 32);
    ++*(_DWORD *)(v9 + 4);
    if ( __PAIR64__(v11, v10) == 0x7FFFFFFFFFFFFFFFi64 )
    {
      v12 = v55;
    }
    else
    {
      v12 = v55;
      if ( __SPAIR64__(v55, v2) < __SPAIR64__(v11, v10) )
      {
        *(_DWORD *)(v9 + 32) = v2;
        *(_DWORD *)(v9 + 36) = v12;
      }
      *(_DWORD *)(v9 + 40) = v57;
      *(_DWORD *)(v9 + 44) = v58;
    }
    if ( __SPAIR64__(v12, v2) < *(_QWORD *)(v9 + 8) && (*(_DWORD *)(v9 + 96) & 4) == 0 )
    {
      KeReleaseQueuedSpinLock(5, v7);
      if ( CcUnmapVacbArray(v9, &v59, 0, 0, 0) )
      {
        if ( !(v2 | v12) )
        {
          if ( *(_DWORD *)(v9 + 104) )
            CcDeleteMbcb(v9);
          if ( *(_DWORD *)(v9 + 16) != v9 + 16 )
            CcDeleteBcbs(v9);
        }
        v15 = CcPurgeAndClearCacheSection(v9, (int)&v59);
        v12 = HIDWORD(v59);
        v2 = v59;
        v6 = v15;
      }
      v7 = KeAcquireQueuedSpinLock(5);
      LODWORD(v54) = v7;
    }
    v13 = *(_DWORD *)(v9 + 4);
    *(_DWORD *)(v9 + 8) = v2;
    *(_DWORD *)(v9 + 12) = v12;
    *(_DWORD *)(v9 + 4) = --v13;
    if ( v13 )
      goto LABEL_10;
    byte_632771 = 1;
    v16 = *(_DWORD *)(v9 + 96);
    v17 = *(_DWORD *)(v9 + 76);
    if ( (v16 & 0x10000) != 0 )
    {
      if ( !v17 )
      {
        if ( (v16 & 0x2000000) != 0 || (v16 & 0x1000000) != 0 )
        {
          v44 = (int *)(v9 + 80);
          v45 = *(_QWORD *)(v9 + 80);
          if ( *(_DWORD *)(v45 + 4) != v9 + 80 || *(int **)HIDWORD(v45) != v44 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v45) = v45;
          *(_DWORD *)(v45 + 4) = HIDWORD(v45);
          v46 = (int **)dword_632614;
          *v44 = (int)&CcDirtySharedCacheMapWithLogHandleList;
          *(_DWORD *)(v9 + 84) = v46;
          if ( *v46 != &CcDirtySharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *v46 = v44;
          dword_632614 = v9 + 80;
        }
        v47 = (int *)(v9 + 88);
        v48 = *(_QWORD *)(v9 + 88);
        if ( *(_DWORD *)(v48 + 4) != v9 + 88 || *(int **)HIDWORD(v48) != v47 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v48) = v48;
        *(_DWORD *)(v48 + 4) = HIDWORD(v48);
        v49 = (int **)dword_632634;
        *v47 = (int)&CcLazyWriterCursor;
        *(_DWORD *)(v9 + 92) = v49;
        if ( *v49 != &CcLazyWriterCursor )
          __fastfail(3u);
        *v49 = v47;
        dword_632634 = v9 + 88;
      }
      v21 = 1;
      v22 = 1;
    }
    else
    {
      if ( v17 || (v16 & 0x20) != 0 )
        goto LABEL_10;
      v50 = *(_DWORD *)(v9 + 176) != 0;
      if ( (v16 & 0x2000000) != 0 || (v16 & 0x1000000) != 0 )
      {
        v51 = (int *)(v9 + 80);
        v52 = *(_QWORD *)(v9 + 80);
        if ( *(_DWORD *)(v52 + 4) != v9 + 80 || *(int **)HIDWORD(v52) != v51 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v52) = v52;
        *(_DWORD *)(v52 + 4) = HIDWORD(v52);
        v53 = (int **)dword_632614;
        *v51 = (int)&CcDirtySharedCacheMapWithLogHandleList;
        *(_DWORD *)(v9 + 84) = v53;
        if ( *v53 != &CcDirtySharedCacheMapWithLogHandleList )
          __fastfail(3u);
        *v53 = v51;
        dword_632614 = v9 + 80;
      }
      v18 = (int *)(v9 + 88);
      v19 = *(_QWORD *)(v9 + 88);
      if ( *(_DWORD *)(v19 + 4) != v9 + 88 || *(int **)HIDWORD(v19) != v18 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v19) = v19;
      *(_DWORD *)(v19 + 4) = HIDWORD(v19);
      v20 = (int **)dword_632634;
      *v18 = (int)&CcLazyWriterCursor;
      *(_DWORD *)(v9 + 92) = v20;
      if ( *v20 != &CcLazyWriterCursor )
        __fastfail(3u);
      *v20 = v18;
      dword_632634 = v9 + 88;
      v21 = 0;
      v22 = v50;
    }
    CcScheduleLazyWriteScan(v22, v21);
    v7 = v54;
LABEL_10:
    KeReleaseQueuedSpinLock(5, v7);
    return v6;
  }
  ++*(_DWORD *)(v9 + 4);
  KeReleaseQueuedSpinLock(5, v7);
  v23 = *(_DWORD *)(v9 + 108);
  LODWORD(v54) = (v4 + 0xFFFFF) & 0xFFF00000;
  HIDWORD(v54) = (__PAIR64__(v5, v4) + 0xFFFFF) >> 32;
  if ( MmExtendSection(v23, &v54, 1) >= 0 )
  {
    v25 = CcExtendVacbArray((_DWORD *)v9, v24, v54);
    v7 = KeAcquireQueuedSpinLock(5);
    v26 = *(_DWORD *)(v9 + 4);
    LODWORD(v54) = v7;
    *(_DWORD *)(v9 + 4) = --v26;
    if ( !v26 )
    {
      byte_632771 = 1;
      v27 = *(_DWORD *)(v9 + 96);
      v28 = *(_DWORD *)(v9 + 76);
      if ( (v27 & 0x10000) != 0 )
      {
        if ( !v28 )
        {
          if ( (v27 & 0x2000000) != 0 || (v27 & 0x1000000) != 0 )
          {
            v35 = (int *)(v9 + 80);
            v36 = *(_QWORD *)(v9 + 80);
            if ( *(_DWORD *)(v36 + 4) != v9 + 80 || *(int **)HIDWORD(v36) != v35 )
              __fastfail(3u);
            *(_DWORD *)HIDWORD(v36) = v36;
            *(_DWORD *)(v36 + 4) = HIDWORD(v36);
            v37 = (int **)dword_632614;
            *v35 = (int)&CcDirtySharedCacheMapWithLogHandleList;
            *(_DWORD *)(v9 + 84) = v37;
            if ( *v37 != &CcDirtySharedCacheMapWithLogHandleList )
              __fastfail(3u);
            *v37 = v35;
            dword_632614 = v9 + 80;
          }
          v38 = (int *)(v9 + 88);
          v39 = *(_QWORD *)(v9 + 88);
          if ( *(_DWORD *)(v39 + 4) != v9 + 88 || *(int **)HIDWORD(v39) != v38 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v39) = v39;
          *(_DWORD *)(v39 + 4) = HIDWORD(v39);
          v40 = (int **)dword_632634;
          *v38 = (int)&CcLazyWriterCursor;
          *(_DWORD *)(v9 + 92) = v40;
          if ( *v40 != &CcLazyWriterCursor )
            __fastfail(3u);
          *v40 = v38;
          dword_632634 = v9 + 88;
        }
        v32 = 1;
        v33 = 1;
      }
      else
      {
        if ( v28 || (v27 & 0x20) != 0 )
          goto LABEL_37;
        v34 = *(_DWORD *)(v9 + 176) != 0;
        if ( (v27 & 0x2000000) != 0 || (v27 & 0x1000000) != 0 )
        {
          v41 = (int *)(v9 + 80);
          v42 = *(_QWORD *)(v9 + 80);
          if ( *(_DWORD *)(v42 + 4) != v9 + 80 || *(int **)HIDWORD(v42) != v41 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v42) = v42;
          *(_DWORD *)(v42 + 4) = HIDWORD(v42);
          v43 = (int **)dword_632614;
          *v41 = (int)&CcDirtySharedCacheMapWithLogHandleList;
          *(_DWORD *)(v9 + 84) = v43;
          if ( *v43 != &CcDirtySharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *v43 = v41;
          dword_632614 = v9 + 80;
        }
        v29 = (int *)(v9 + 88);
        v30 = *(_QWORD *)(v9 + 88);
        if ( *(_DWORD *)(v30 + 4) != v9 + 88 || *(int **)HIDWORD(v30) != v29 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v30) = v30;
        *(_DWORD *)(v30 + 4) = HIDWORD(v30);
        v31 = (int **)dword_632634;
        *v29 = (int)&CcLazyWriterCursor;
        *(_DWORD *)(v9 + 92) = v31;
        if ( *v31 != &CcLazyWriterCursor )
          __fastfail(3u);
        *v31 = v29;
        dword_632634 = v9 + 88;
        v32 = 0;
        v33 = v34;
      }
      CcScheduleLazyWriteScan(v33, v32);
      v7 = v54;
    }
LABEL_37:
    if ( v25 < 0 )
    {
      KeReleaseQueuedSpinLock(5, v7);
      RtlRaiseStatus(v25);
    }
    v9 = *(_DWORD *)(*(_DWORD *)(v56 + 20) + 4);
    if ( v9 )
      goto LABEL_6;
    KeReleaseQueuedSpinLock(5, v7);
    return 0;
  }
  return sub_53BFF0();
}
