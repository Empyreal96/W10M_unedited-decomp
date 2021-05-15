// CcCompleteAsyncRead 
 
int __fastcall CcCompleteAsyncRead(_DWORD *a1)
{
  unsigned int v2; // r0
  unsigned int v3; // r2
  int v4; // r10
  int *v5; // r4
  unsigned int *v6; // r9
  unsigned int v7; // r5
  unsigned int v8; // r8
  unsigned int v9; // r1
  int v10; // r6
  int v11; // r0
  __int64 v12; // kr00_8
  int v13; // r3
  int v14; // r0
  unsigned int *v15; // r8
  unsigned int v16; // r6
  unsigned int v17; // r9
  unsigned int v18; // r4
  _DWORD *v19; // r4
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r6
  int v23; // r3
  int v24; // r2
  int v25; // r3
  int *v26; // r2
  int v27; // r5
  int **v28; // r1
  int **v29; // r0
  int *v30; // r2
  int v31; // r0
  int **v32; // r1
  int **v33; // r0
  int v34; // r1
  int v35; // r0
  BOOL v36; // r5
  int *v37; // r2
  int v38; // r0
  int **v39; // r1
  int **v40; // r0
  int *v41; // r2
  int v42; // r0
  int **v43; // r1
  int **v44; // r0
  int v46; // [sp+1Ch] [bp-5Ch] BYREF
  _DWORD *v47; // [sp+20h] [bp-58h]
  int v48; // [sp+24h] [bp-54h]
  int v49; // [sp+28h] [bp-50h]
  int v50; // [sp+2Ch] [bp-4Ch]
  int v51; // [sp+30h] [bp-48h]
  int v52; // [sp+34h] [bp-44h]
  int v53; // [sp+38h] [bp-40h]
  int v54; // [sp+3Ch] [bp-3Ch]
  int v55; // [sp+40h] [bp-38h]
  int v56; // [sp+44h] [bp-34h]
  int v57; // [sp+48h] [bp-30h]
  int *v58; // [sp+4Ch] [bp-2Ch]
  int v59; // [sp+50h] [bp-28h]

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v50 = v2;
  v3 = (*(_DWORD *)(v2 + 0x3C0) >> 12) & 7;
  if ( (*(_DWORD *)(*(_DWORD *)(v2 + 0x150) + 192) & 0x100000) != 0 && v3 >= 2 )
    v3 = 2;
  v48 = v3;
  v46 = 0;
  v49 = 0;
  v59 = 0;
  v47 = (_DWORD *)a1[2];
  v56 = a1[6];
  v54 = a1[4];
  v57 = a1[5];
  v4 = a1[7];
  v52 = a1[9];
  v55 = a1[10];
  v5 = (int *)a1[11];
  v58 = v5;
  v51 = a1[12];
  v6 = (unsigned int *)(v2 + 960);
  v7 = *(_DWORD *)(v2 + 960);
  __dmb(0xBu);
  do
  {
    v8 = v7;
    __dmb(0xBu);
    do
      v9 = __ldrex(v6);
    while ( v9 == v7 && __strex(v7 & 0xFFFF8FFF | (v52 << 12), v6) );
    v7 = v9;
    __dmb(0xBu);
  }
  while ( v9 != v8 );
  if ( (dword_682604 & 0x2000) != 0 )
    EtwTracePriority(v2, 1331, (v8 >> 12) & 7, v52, 0);
  v10 = v55;
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 7;
  if ( *v5 >= 0 )
  {
    *v5 = 0;
    v5[1] = v4;
    if ( (*(_WORD *)(v10 + 6) & 5) != 0 )
      v11 = *(_DWORD *)(v10 + 12);
    else
      v11 = MmMapLockedPagesSpecifyCache(v10, 0, 1, 0, 0, 1073741856);
    v53 = v11;
    v59 = v11;
    if ( v11 )
      CcMapAndCopyFromCache(v56, &v46, v54, v57, v4, 1, v11, &v46, v52);
    else
      *v5 = -1073741670;
  }
  if ( v46 )
  {
    v12 = *(_QWORD *)&CcNumberAsyncReadRefaulted + 1i64;
    __dmb(0xBu);
    *(_QWORD *)&CcNumberAsyncReadRefaulted = v12;
  }
  if ( v51 && *(_DWORD *)v51 )
    (*(void (__fastcall **)(_DWORD))v51)(*(_DWORD *)(v51 + 4));
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 0;
  v13 = v48;
  v14 = v50;
  v15 = (unsigned int *)(v50 + 960);
  v16 = *(_DWORD *)(v50 + 960);
  __dmb(0xBu);
  do
  {
    v17 = v16;
    __dmb(0xBu);
    do
      v18 = __ldrex(v15);
    while ( v18 == v16 && __strex(v16 & 0xFFFF8FFF | (v13 << 12), v15) );
    v16 = v18;
    __dmb(0xBu);
  }
  while ( v18 != v17 );
  if ( (dword_682604 & 0x2000) != 0 )
    EtwTracePriority(v14, 1331, (v17 >> 12) & 7, v13, 0);
  __dmb(0xBu);
  v19 = v47;
  v20 = v47 + 92;
  do
    v21 = __ldrex(v20);
  while ( __strex(v21 - 1, v20) );
  __dmb(0xBu);
  v22 = KeAcquireQueuedSpinLock(5);
  v23 = v19[1] - 1;
  v19[1] = v23;
  if ( !v23 )
  {
    byte_632771 = 1;
    v24 = v19[24];
    v25 = v19[19];
    if ( (v24 & 0x10000) != 0 )
    {
      if ( !v25 )
      {
        if ( (v24 & 0x3000000) != 0 )
        {
          v26 = v19 + 20;
          v27 = v19[20];
          v28 = (int **)v19[21];
          if ( *(_DWORD **)(v27 + 4) != v19 + 20 || *v28 != v26 )
            __fastfail(3u);
          *v28 = (int *)v27;
          *(_DWORD *)(v27 + 4) = v28;
          v29 = (int **)dword_632614;
          *v26 = (int)&CcDirtySharedCacheMapWithLogHandleList;
          v19[21] = v29;
          if ( *v29 != &CcDirtySharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *v29 = v26;
          dword_632614 = (int)(v19 + 20);
        }
        v30 = v19 + 22;
        v31 = v19[22];
        v32 = (int **)v19[23];
        if ( *(_DWORD **)(v31 + 4) != v19 + 22 || *v32 != v30 )
          __fastfail(3u);
        *v32 = (int *)v31;
        *(_DWORD *)(v31 + 4) = v32;
        v33 = (int **)dword_632634;
        *v30 = (int)&CcLazyWriterCursor;
        v19[23] = v33;
        if ( *v33 != &CcLazyWriterCursor )
          __fastfail(3u);
        *v33 = v30;
        dword_632634 = (int)(v19 + 22);
      }
      v34 = 1;
      v35 = 1;
LABEL_49:
      CcScheduleLazyWriteScan(v35, v34);
      return KeReleaseQueuedSpinLock(5, v22);
    }
    if ( !v25 && (v24 & 0x20) == 0 )
    {
      v36 = v19[44] != 0;
      if ( (v24 & 0x3000000) != 0 )
      {
        v37 = v19 + 20;
        v38 = v19[20];
        v39 = (int **)v19[21];
        if ( *(_DWORD **)(v38 + 4) != v19 + 20 || *v39 != v37 )
          __fastfail(3u);
        *v39 = (int *)v38;
        *(_DWORD *)(v38 + 4) = v39;
        v40 = (int **)dword_632614;
        *v37 = (int)&CcDirtySharedCacheMapWithLogHandleList;
        v19[21] = v40;
        if ( *v40 != &CcDirtySharedCacheMapWithLogHandleList )
          __fastfail(3u);
        *v40 = v37;
        dword_632614 = (int)(v19 + 20);
      }
      v41 = v19 + 22;
      v42 = v19[22];
      v43 = (int **)v19[23];
      if ( *(_DWORD **)(v42 + 4) != v19 + 22 || *v43 != v41 )
        __fastfail(3u);
      *v43 = (int *)v42;
      *(_DWORD *)(v42 + 4) = v43;
      v44 = (int **)dword_632634;
      *v41 = (int)&CcLazyWriterCursor;
      v19[23] = v44;
      if ( *v44 != &CcLazyWriterCursor )
        __fastfail(3u);
      *v44 = v41;
      dword_632634 = (int)(v19 + 22);
      v34 = 0;
      v35 = v36;
      goto LABEL_49;
    }
  }
  return KeReleaseQueuedSpinLock(5, v22);
}
