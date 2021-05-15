// CcPerformReadAhead 
 
int __fastcall CcPerformReadAhead(int a1, int a2)
{
  unsigned int v2; // r10
  int v3; // r8
  unsigned int v4; // r5
  int v5; // r3
  int v6; // r6
  unsigned int *v7; // r8
  unsigned int v8; // r2
  BOOL v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r8
  unsigned int v15; // r6
  int v16; // r1
  unsigned int v17; // kr00_4
  unsigned __int64 v18; // kr08_8
  unsigned int v19; // r5
  unsigned int *v20; // r6
  unsigned int v21; // r0
  unsigned int v22; // lr
  unsigned int v23; // r1
  unsigned int *v24; // r6
  unsigned int v25; // r0
  unsigned int v26; // lr
  unsigned int v27; // r1
  unsigned int *v28; // r1
  int v29; // r2
  unsigned int v30; // r0
  int v31; // r10
  _DWORD *v32; // r6
  unsigned int *v33; // r8
  unsigned int v34; // r2
  int v35; // r6
  int v36; // r3
  int v37; // r2
  int v38; // r3
  int *v39; // r2
  int v40; // r5
  int **v41; // r1
  int **v42; // r0
  int *v43; // r2
  int v44; // r0
  int **v45; // r1
  int **v46; // r0
  int v47; // r1
  int v48; // r0
  BOOL v49; // r5
  int *v50; // r2
  int v51; // r0
  int **v52; // r1
  int **v53; // r0
  int *v54; // r2
  int v55; // r0
  int **v56; // r1
  int **v57; // r0
  int v59; // [sp+18h] [bp-A8h]
  int v60; // [sp+18h] [bp-A8h]
  int v61; // [sp+1Ch] [bp-A4h]
  int v62; // [sp+1Ch] [bp-A4h]
  __int64 v63; // [sp+20h] [bp-A0h]
  int v64; // [sp+28h] [bp-98h]
  int v65; // [sp+30h] [bp-90h]
  _DWORD *v66; // [sp+34h] [bp-8Ch]
  unsigned int v68; // [sp+3Ch] [bp-84h]
  int v69; // [sp+40h] [bp-80h]
  int v70; // [sp+44h] [bp-7Ch]
  int v71; // [sp+48h] [bp-78h]
  int v72; // [sp+4Ch] [bp-74h]
  int v73; // [sp+50h] [bp-70h]
  int v74; // [sp+54h] [bp-6Ch]
  int v75; // [sp+58h] [bp-68h]
  int v76; // [sp+5Ch] [bp-64h]
  _DWORD *v77; // [sp+60h] [bp-60h] BYREF
  __int64 v78; // [sp+68h] [bp-58h] BYREF
  int v79; // [sp+70h] [bp-50h]
  int v80; // [sp+74h] [bp-4Ch]
  unsigned int v81; // [sp+78h] [bp-48h]
  int v82; // [sp+7Ch] [bp-44h]
  int v83; // [sp+80h] [bp-40h]
  unsigned int v84; // [sp+84h] [bp-3Ch]
  unsigned int v85; // [sp+88h] [bp-38h]
  unsigned int v86; // [sp+8Ch] [bp-34h]
  int v87; // [sp+90h] [bp-30h]
  unsigned int v88; // [sp+94h] [bp-2Ch]
  __int64 v89; // [sp+98h] [bp-28h]
  int anonymous14; // [sp+C8h] [bp+8h]
  int anonymous15; // [sp+CCh] [bp+Ch]

  anonymous15 = a2;
  v79 = a1;
  anonymous14 = a1;
  v71 = 0;
  v73 = 0;
  v75 = 0;
  v65 = 0;
  v72 = 0;
  v83 = 0;
  v2 = 0;
  v85 = 0;
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4) = 0;
  v77 = *(_DWORD **)(*(_DWORD *)(a2 + 20) + 4);
  v66 = v77;
  v69 = v77[34];
  v74 = v77[35];
  v76 = (*(int (**)(void))(v69 + 8))();
  if ( v76 )
  {
    v84 = 0x800000;
    while ( 1 )
    {
      v80 = 0;
      v82 = 0;
      v3 = v87;
      v59 = v87;
      v63 = v78;
      v4 = v68;
      v64 = v70;
      while ( 1 )
      {
        v5 = KeAcquireQueuedSpinLock(5);
        v61 = v5;
        v6 = *(_DWORD *)(a2 + 24);
        if ( v6 )
        {
          v7 = (unsigned int *)(v6 + 80);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented(v6 + 80);
          }
          else
          {
            do
              v8 = __ldrex(v7);
            while ( __strex(1u, v7) );
            __dmb(0xBu);
            if ( v8 )
              KxWaitForSpinLockAndAcquire(v6 + 80);
          }
          v4 = *(_DWORD *)(v6 + 52);
          v9 = v4 == 0;
          v59 = v9;
          v87 = v9;
          v10 = *(_DWORD *)(v6 + 56);
          LODWORD(v63) = v10;
          LODWORD(v78) = v10;
          v11 = *(_DWORD *)(v6 + 60);
          HIDWORD(v63) = v11;
          HIDWORD(v78) = v11;
          v68 = v4;
          if ( v4 > v84 )
          {
            v4 = 0x800000;
            v68 = v84;
          }
          *(_DWORD *)(v6 + 52) = 0;
          if ( !v9 )
            *(_QWORD *)(v6 + 64) = __PAIR64__(v11, v4) + v10;
          if ( (*(_DWORD *)v6 & 0x200000) != 0 )
          {
            v72 = 1;
            v83 = 1;
            v2 = *(_DWORD *)(v6 + 84);
            v85 = v2;
          }
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v6 + 80);
          }
          else
          {
            __dmb(0xBu);
            *v7 = 0;
          }
          v64 = (*(_DWORD *)v6 >> 18) & 7;
          v70 = v64;
          v5 = v61;
          v3 = v59;
        }
        KeReleaseQueuedSpinLock(5, v5);
        if ( !v6 || v3 )
          break;
        v12 = v77[2];
        v13 = v77[3];
        if ( v63 < __SPAIR64__(v13, v12) )
        {
          v73 = 1;
          if ( v63 + v4 >= __SPAIR64__(v13, v12) )
          {
            v4 = v12 - v63;
            v71 = 1;
          }
          v4 = (v4 + 4095) & 0xFFFFF000;
          v68 = v4;
          v14 = v4;
          v86 = v4;
          v89 = v63;
          v88 = v4;
          if ( v72 )
          {
            if ( !v2 )
              KeBugCheckEx(52, 2535, -1073740768);
            if ( v4 <= v2 )
              v15 = v4;
            else
              v15 = v2;
            v81 = v15;
          }
          else
          {
            v15 = v4;
            v81 = v4;
          }
          v16 = 0x20000;
          if ( (dword_682610 & 0x20000) != 0 )
          {
            CcPerfLogReadAhead(v79, &v78, v4, v64);
            goto LABEL_35;
          }
          while ( v14 )
          {
            if ( v15 > v14 )
            {
              v15 = v14;
              v81 = v14;
            }
            if ( (dword_682610 & 0x20000) != 0 )
              CcPerfLogReadAheadPrefetch(v79, &v78, v15, v64);
            v75 |= MmPrefetchForCacheManager(a2, v16, v63, HIDWORD(v63));
            v65 = v75;
            v14 -= v15;
            v86 = v14;
            v17 = v63;
            LODWORD(v63) = v63 + v15;
            v18 = __PAIR64__(HIDWORD(v63), v17) + v15;
            HIDWORD(v63) = HIDWORD(v18);
            v78 = v18;
            v80 = v82;
LABEL_35:
            v16 = 0x20000;
          }
          v3 = v59;
        }
      }
      if ( !v80 )
        break;
      v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( (*(_DWORD *)(*(_DWORD *)(v19 + 0x150) + 192) & 0x100000) != 0 && ((*(_DWORD *)(v19 + 0x3C0) >> 12) & 7u) >= 2 )
        v60 = 2;
      else
        v60 = (*(_DWORD *)(v19 + 0x3C0) >> 12) & 7;
      MmWaitForCacheManagerPrefetch();
      v20 = (unsigned int *)(v19 + 960);
      v21 = *(_DWORD *)(v19 + 960);
      __dmb(0xBu);
      do
      {
        v22 = v21;
        __dmb(0xBu);
        do
          v23 = __ldrex(v20);
        while ( v23 == v21 && __strex(v21 & 0xFFFF8FFF | (v64 << 12), v20) );
        v21 = v23;
        __dmb(0xBu);
      }
      while ( v23 != v22 );
      if ( (dword_682604 & 0x2000) != 0 )
        EtwTracePriority(v19, 1331, (v22 >> 12) & 7, v70, 0);
      CcMapAndCopyFromCache(a2, v23, v89, HIDWORD(v89), v88, 1, 0, &v77, v70);
      v24 = (unsigned int *)(v19 + 960);
      v25 = *(_DWORD *)(v19 + 960);
      __dmb(0xBu);
      do
      {
        v26 = v25;
        __dmb(0xBu);
        do
          v27 = __ldrex(v24);
        while ( v27 == v25 && __strex(v25 & 0xFFFF8FFF | (v60 << 12), v24) );
        v25 = v27;
        __dmb(0xBu);
      }
      while ( v27 != v26 );
      if ( (dword_682604 & 0x2000) != 0 )
        EtwTracePriority(v19, 1331, (v26 >> 12) & 7, v60, 0);
      v77 = v66;
      v75 = v65;
      v72 = v83;
      v2 = v85;
    }
  }
  v28 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4324);
  v29 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4);
  do
    v30 = __ldrex(v28);
  while ( __strex(v30 + v29, v28) );
  if ( v76 )
    (*(void (__fastcall **)(int))(v69 + 12))(v74);
  v62 = KeAcquireQueuedSpinLock(5);
  v31 = anonymous15;
  v32 = *(_DWORD **)(anonymous15 + 24);
  if ( v32 )
  {
    v33 = v32 + 20;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v32 + 20);
    }
    else
    {
      do
        v34 = __ldrex(v33);
      while ( __strex(1u, v33) );
      __dmb(0xBu);
      if ( v34 )
        KxWaitForSpinLockAndAcquire(v32 + 20);
    }
    *v32 &= 0xFFFEFFFF;
    if ( v71 && (*(_DWORD *)(v31 + 44) & 0x20) != 0 )
    {
      v32[16] = 0;
      v32[17] = 0;
    }
    if ( v73 && !v65 )
      *v32 &= 0xFFFDFFFF;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v32 + 20);
    }
    else
    {
      __dmb(0xBu);
      *v33 = 0;
    }
  }
  KeReleaseQueuedSpinLock(5, v62);
  ObfDereferenceObject(v31);
  v35 = KeAcquireQueuedSpinLock(5);
  v36 = v66[1] - 1;
  v66[1] = v36;
  if ( !v36 )
  {
    byte_632771 = 1;
    v37 = v66[24];
    v38 = v66[19];
    if ( (v37 & 0x10000) != 0 )
    {
      if ( !v38 )
      {
        if ( (v37 & 0x3000000) != 0 )
        {
          v39 = v66 + 20;
          v40 = v66[20];
          v41 = (int **)v66[21];
          if ( *(_DWORD **)(v40 + 4) != v66 + 20 || *v41 != v39 )
            __fastfail(3u);
          *v41 = (int *)v40;
          *(_DWORD *)(v40 + 4) = v41;
          v42 = (int **)dword_632614;
          *v39 = (int)&CcDirtySharedCacheMapWithLogHandleList;
          v66[21] = v42;
          if ( *v42 != &CcDirtySharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *v42 = v39;
          dword_632614 = (int)(v66 + 20);
        }
        v43 = v66 + 22;
        v44 = v66[22];
        v45 = (int **)v66[23];
        if ( *(_DWORD **)(v44 + 4) != v66 + 22 || *v45 != v43 )
          __fastfail(3u);
        *v45 = (int *)v44;
        *(_DWORD *)(v44 + 4) = v45;
        v46 = (int **)dword_632634;
        *v43 = (int)&CcLazyWriterCursor;
        v66[23] = v46;
        if ( *v46 != &CcLazyWriterCursor )
          __fastfail(3u);
        *v46 = v43;
        dword_632634 = (int)(v66 + 22);
      }
      v47 = 1;
      v48 = 1;
LABEL_100:
      CcScheduleLazyWriteScan(v48, v47);
      goto LABEL_116;
    }
    if ( !v38 && (v37 & 0x20) == 0 )
    {
      v49 = v66[44] != 0;
      if ( (v37 & 0x3000000) != 0 )
      {
        v50 = v66 + 20;
        v51 = v66[20];
        v52 = (int **)v66[21];
        if ( *(_DWORD **)(v51 + 4) != v66 + 20 || *v52 != v50 )
          __fastfail(3u);
        *v52 = (int *)v51;
        *(_DWORD *)(v51 + 4) = v52;
        v53 = (int **)dword_632614;
        *v50 = (int)&CcDirtySharedCacheMapWithLogHandleList;
        v66[21] = v53;
        if ( *v53 != &CcDirtySharedCacheMapWithLogHandleList )
          __fastfail(3u);
        *v53 = v50;
        dword_632614 = (int)(v66 + 20);
      }
      v54 = v66 + 22;
      v55 = v66[22];
      v56 = (int **)v66[23];
      if ( *(_DWORD **)(v55 + 4) != v66 + 22 || *v56 != v54 )
        __fastfail(3u);
      *v56 = (int *)v55;
      *(_DWORD *)(v55 + 4) = v56;
      v57 = (int **)dword_632634;
      *v54 = (int)&CcLazyWriterCursor;
      v66[23] = v57;
      if ( *v57 != &CcLazyWriterCursor )
        __fastfail(3u);
      *v57 = v54;
      dword_632634 = (int)(v66 + 22);
      v47 = 0;
      v48 = v49;
      goto LABEL_100;
    }
  }
LABEL_116:
  v66[24] &= 0xFFFFBFFF;
  return KeReleaseQueuedSpinLock(5, v35);
}
