// CcWriteBehindInternal 
 
int __fastcall CcWriteBehindInternal(int a1)
{
  int v1; // r4
  _DWORD *v2; // r9
  unsigned int v3; // r10
  int v4; // r0
  int v5; // r1
  int result; // r0
  int v7; // r5
  int v8; // r6
  unsigned int v9; // r2
  int v10; // r0
  int v11; // r2
  int v12; // r5
  int v13; // r10
  unsigned int *v14; // r7
  int v15; // r6
  unsigned int v16; // r1
  unsigned int *v17; // r2
  unsigned int v18; // r0
  int v19; // r5
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v22; // r8
  int v23; // r8
  int v24; // r5
  int v25; // r6
  unsigned int v26; // r2
  unsigned int v27; // r7
  unsigned int v28; // r9
  BOOL v29; // r5
  BOOL v30; // r2
  int v31; // r5
  unsigned int v32; // r1
  int v33; // r0
  int v34; // r5
  int v35; // r3
  _DWORD *v36; // r8
  int v37; // r5
  int v38; // r0
  int v39; // r1
  int v40; // r6
  __int64 v41; // r2
  __int64 v42; // kr18_8
  unsigned int v43; // r3
  unsigned int v44; // r1
  __int64 v45; // r2
  int v46; // r5
  unsigned int v47; // r1
  _DWORD *v48; // r7
  int v49; // r5
  int v50; // r0
  unsigned int v51; // r6
  unsigned int k; // r3
  unsigned int v53; // r1
  int v54; // r5
  int v55; // r6
  unsigned int v56; // r2
  int v57; // r3
  int v58; // r6
  int v59; // r9
  unsigned int v60; // r0
  unsigned int l; // r3
  unsigned int v62; // r1
  unsigned int *v63; // r2
  unsigned int v64; // r0
  int v65; // r2
  unsigned int *v66; // r2
  unsigned int v67; // r0
  _DWORD *v68; // r7
  int v69; // r0
  int v70; // r3
  int v71; // r9
  unsigned int v72; // r6
  unsigned int i; // r3
  unsigned int v74; // r5
  int v75; // r5
  unsigned int v76; // r0
  unsigned int j; // r3
  unsigned int v78; // r1
  _QWORD *v79; // r2
  __int64 v80; // r0
  __int64 v81; // r0
  int *v82; // r2
  __int64 v83; // r0
  int **v84; // r1
  _QWORD *v85; // r2
  __int64 v86; // r0
  __int64 v87; // r0
  int *v88; // r2
  __int64 v89; // r0
  int **v90; // r1
  int v91; // r1
  int v92; // r0
  int v93; // r6
  unsigned int v94; // r3
  int v95; // r3
  int v96; // r2
  int v97; // r3
  int *v98; // r2
  __int64 v99; // r0
  int **v100; // r1
  int *v101; // r2
  __int64 v102; // r0
  int **v103; // r1
  int v104; // r1
  int v105; // r0
  BOOL v106; // r5
  int *v107; // r2
  __int64 v108; // r0
  int **v109; // r1
  int *v110; // r2
  __int64 v111; // r0
  int **v112; // r1
  int v113; // [sp+8h] [bp-50h]
  _DWORD *v114; // [sp+10h] [bp-48h]
  int v115; // [sp+18h] [bp-40h]
  __int64 v117; // [sp+20h] [bp-38h] BYREF
  int v118[2]; // [sp+28h] [bp-30h] BYREF
  __int64 v119; // [sp+30h] [bp-28h] BYREF

  v2 = *(_DWORD **)(a1 + 12);
  v1 = *(_DWORD *)(a1 + 8);
  v115 = *(unsigned __int8 *)(a1 + 32);
  v114 = v2;
  v3 = v1 + 180;
  while ( 1 )
  {
    v113 = 0;
    v4 = KeAcquireQueuedSpinLock(5);
    ++*(_DWORD *)(v1 + 4);
    KeReleaseQueuedSpinLock(5, v4);
    CcApplyLowIoPriorityToThread(1, v1);
    KeAcquireQueuedSpinLock(8);
    if ( !CcIsWriteBehindThreadpoolAtLowPriority() )
      return sub_53CD78();
    KeReleaseQueuedSpinLock(8, v5);
    if ( !(**(int (__fastcall ***)(_DWORD, int))(v1 + 136))(*(_DWORD *)(v1 + 140), 1) )
    {
      CcApplyLowIoPriorityToThread(0, v1);
      v93 = KeAcquireQueuedSpinLock(5);
      v94 = *(_DWORD *)(v1 + 96) & 0xFFFFFFDF;
      *(_DWORD *)(v1 + 96) = v94;
      if ( (v94 & 0x10000) != 0 )
        CcCancelMmWaitForUninitializeCacheMap(v1);
      v95 = *(_DWORD *)(v1 + 4) - 1;
      *(_DWORD *)(v1 + 4) = v95;
      if ( v95 )
        goto LABEL_215;
      byte_632771 = 1;
      v96 = *(_DWORD *)(v1 + 96);
      v97 = *(_DWORD *)(v1 + 76);
      if ( (v96 & 0x10000) != 0 )
      {
        if ( !v97 )
        {
          if ( (v96 & 0x3000000) != 0 )
          {
            v98 = (int *)(v1 + 80);
            v99 = *(_QWORD *)(v1 + 80);
            if ( *(_DWORD *)(v99 + 4) != v1 + 80 || *(int **)HIDWORD(v99) != v98 )
              __fastfail(3u);
            *(_DWORD *)HIDWORD(v99) = v99;
            *(_DWORD *)(v99 + 4) = HIDWORD(v99);
            v100 = (int **)dword_632614;
            *v98 = (int)&CcDirtySharedCacheMapWithLogHandleList;
            *(_DWORD *)(v1 + 84) = v100;
            if ( *v100 != &CcDirtySharedCacheMapWithLogHandleList )
              __fastfail(3u);
            *v100 = v98;
            dword_632614 = v1 + 80;
          }
          v101 = (int *)(v1 + 88);
          v102 = *(_QWORD *)(v1 + 88);
          if ( *(_DWORD *)(v102 + 4) != v1 + 88 || *(int **)HIDWORD(v102) != v101 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v102) = v102;
          *(_DWORD *)(v102 + 4) = HIDWORD(v102);
          v103 = (int **)dword_632634;
          *v101 = (int)&CcLazyWriterCursor;
          *(_DWORD *)(v1 + 92) = v103;
          if ( *v103 != &CcLazyWriterCursor )
            __fastfail(3u);
          *v103 = v101;
          dword_632634 = v1 + 88;
        }
        v104 = 1;
        v105 = 1;
      }
      else
      {
        if ( v97 || (v96 & 0x20) != 0 )
          goto LABEL_215;
        v106 = *(_DWORD *)(v1 + 176) != 0;
        if ( (v96 & 0x3000000) != 0 )
        {
          v107 = (int *)(v1 + 80);
          v108 = *(_QWORD *)(v1 + 80);
          if ( *(_DWORD *)(v108 + 4) != v1 + 80 || *(int **)HIDWORD(v108) != v107 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v108) = v108;
          *(_DWORD *)(v108 + 4) = HIDWORD(v108);
          v109 = (int **)dword_632614;
          *v107 = (int)&CcDirtySharedCacheMapWithLogHandleList;
          *(_DWORD *)(v1 + 84) = v109;
          if ( *v109 != &CcDirtySharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *v109 = v107;
          dword_632614 = v1 + 80;
        }
        v110 = (int *)(v1 + 88);
        v111 = *(_QWORD *)(v1 + 88);
        if ( *(_DWORD *)(v111 + 4) != v1 + 88 || *(int **)HIDWORD(v111) != v110 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v111) = v111;
        *(_DWORD *)(v111 + 4) = HIDWORD(v111);
        v112 = (int **)dword_632634;
        *v110 = (int)&CcLazyWriterCursor;
        *(_DWORD *)(v1 + 92) = v112;
        if ( *v112 != &CcLazyWriterCursor )
          __fastfail(3u);
        *v112 = v110;
        dword_632634 = v1 + 88;
        v104 = 0;
        v105 = v106;
      }
      CcScheduleLazyWriteScan(v105, v104);
LABEL_215:
      result = KeReleaseQueuedSpinLock(5, v93);
      *v2 = -1073741740;
      goto LABEL_55;
    }
    v7 = KeAbPreAcquire(v3, 0, 0);
    v8 = KfRaiseIrql(1);
    do
      v9 = __ldrex((unsigned __int8 *)v3);
    while ( __strex(v9 & 0xFE, (unsigned __int8 *)v3) );
    __dmb(0xBu);
    if ( (v9 & 1) == 0 )
      ExpAcquireFastMutexContended(v3, v7);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    *(_DWORD *)(v3 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v3 + 28) = v8;
    v10 = KeAcquireQueuedSpinLock(5);
    if ( (*(_DWORD *)(v1 + 96) & 0x10000) != 0 )
      v113 = 1;
    v11 = *(_DWORD *)(v1 + 104);
    if ( v11 )
    {
      v43 = *(_DWORD *)(v11 + 8);
      v44 = CcPagesYetToWrite;
      *(_DWORD *)(v11 + 4) = v43;
      if ( v43 > v44 )
        *(_DWORD *)(v11 + 4) = v44;
      v12 = *(_DWORD *)(v11 + 4);
    }
    else
    {
      v12 = *(_DWORD *)(v1 + 120);
    }
    v13 = *(_DWORD *)((*(_DWORD *)(v1 + 68) & 0xFFFFFFF8) + 20);
    KeReleaseQueuedSpinLock(5, v10);
    v14 = (unsigned int *)(v1 + 180);
    v15 = *(_DWORD *)(v1 + 208);
    *(_DWORD *)(v1 + 184) = 0;
    __dmb(0xBu);
    do
      v16 = __ldrex(v14);
    while ( !v16 && __strex(1u, v14) );
    if ( v16 )
      ExpReleaseFastMutexContended((unsigned int *)(v1 + 180), v16);
    KfLowerIrql((unsigned __int8)v15);
    KeAbPostRelease(v1 + 180);
    __dmb(0xBu);
    v17 = (unsigned int *)(*(_DWORD *)(v1 + 356) + 132);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 + v12, v17) );
    __dmb(0xBu);
    if ( (*(_DWORD *)(v1 + 96) & 0x1000000) != 0 )
    {
      __dmb(0xBu);
      v63 = (unsigned int *)(*(_DWORD *)(v1 + 356) + 136);
      do
        v64 = __ldrex(v63);
      while ( __strex(v64 + v12, v63) );
      __dmb(0xBu);
    }
    if ( (*(_DWORD *)(v1 + 96) & 0x1000000) != 0 )
    {
      v65 = *(_DWORD *)(v1 + 152);
      v118[0] = *(_DWORD *)(v65 + 72);
      v118[1] = *(_DWORD *)(v65 + 76);
      CcFlushCachePriv(v13, &CcNoDelay, 1u, v118, 0, (int)v2);
    }
    else
    {
      CcFlushCache(v13, (int)&CcNoDelay, 1);
    }
    CcApplyLowIoPriorityToThread(0, v1);
    __dmb(0xBu);
    v19 = -v12;
    v20 = (unsigned int *)(*(_DWORD *)(v1 + 356) + 132);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 + v19, v20) );
    __dmb(0xBu);
    if ( (*(_DWORD *)(v1 + 96) & 0x1000000) != 0 )
    {
      __dmb(0xBu);
      v66 = (unsigned int *)(*(_DWORD *)(v1 + 356) + 136);
      do
        v67 = __ldrex(v66);
      while ( __strex(v67 + v19, v66) );
      __dmb(0xBu);
    }
    (*(void (__fastcall **)(_DWORD))(*(_DWORD *)(v1 + 136) + 4))(*(_DWORD *)(v1 + 140));
    v22 = *v2;
    if ( *v2 != -2147483626 && v22 < 0 )
    {
      if ( !*(_DWORD *)(v1 + 4) )
        KeBugCheckEx(52, 4935, -1073740768);
      v68 = (_DWORD *)(v1 + 68);
      v69 = ObFastReferenceObject((_DWORD *)(v1 + 68));
      if ( !v69 )
        v69 = CcSlowReferenceSharedCacheMapFileObject(v1);
      v70 = *(_DWORD *)(v69 + 4);
      __pld(v68);
      v71 = *(_DWORD *)(v70 + 32);
      v72 = *v68;
      for ( i = *v68 ^ v69; i < 7; i = v74 ^ v69 )
      {
        __dmb(0xBu);
        do
          v74 = __ldrex(v68);
        while ( v74 == v72 && __strex(v72 + 1, v68) );
        if ( v74 == v72 )
          goto LABEL_133;
        v72 = v74;
      }
      ObDereferenceObjectDeferDeleteWithTag(v69);
LABEL_133:
      if ( MmIsWriteErrorFatal(1, v71 & 0x10, v22) )
      {
        v75 = ObFastReferenceObject((_DWORD *)(v1 + 68));
        if ( !v75 )
          v75 = CcSlowReferenceSharedCacheMapFileObject(v1);
        CcMmLogLostDelayedWriteError(v75, *v114);
        __pld(v68);
        v76 = *v68;
        for ( j = *v68 ^ v75; j < 7; j = v78 ^ v75 )
        {
          __dmb(0xBu);
          do
            v78 = __ldrex(v68);
          while ( v78 == v76 && __strex(v76 + 1, v68) );
          if ( v78 == v76 )
            goto LABEL_144;
          v76 = v78;
        }
        ObDereferenceObjectDeferDeleteWithTag(v75);
      }
LABEL_144:
      v14 = (unsigned int *)(v1 + 180);
    }
    v23 = 0;
    v24 = KeAbPreAcquire((unsigned int)v14, 0, 0);
    v25 = KfRaiseIrql(1);
    do
      v26 = __ldrex((unsigned __int8 *)v14);
    while ( __strex(v26 & 0xFE, (unsigned __int8 *)v14) );
    __dmb(0xBu);
    if ( (v26 & 1) == 0 )
      ExpAcquireFastMutexContended(v14, v24);
    if ( v24 )
      *(_BYTE *)(v24 + 14) |= 1u;
    v14[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14[7] = v25;
    v28 = *(_DWORD *)(v1 + 36);
    v27 = *(_DWORD *)(v1 + 32);
    v29 = *(_DWORD *)(v1 + 4) > 1u && (int *)CcDeferredWrites != &CcDeferredWrites;
    v30 = 0;
    if ( (*(_DWORD *)(v1 + 96) & 0x400) != 0 )
    {
      v42 = *(_QWORD *)(v1 + 32);
      if ( *(_QWORD *)(v1 + 40) >= v42 && v42 != 0x7FFFFFFFFFFFFFFFi64 && *(_QWORD *)(v1 + 8) )
        v30 = 1;
    }
    if ( !v30
      || *(_DWORD *)(v1 + 364)
      || v29
      || (CcGetFlushedValidData(&v119, v13, 1),
          v28 = HIDWORD(v119),
          v27 = v119,
          v45 = *(_QWORD *)(v1 + 32),
          v117 = v119,
          v119 < v45) )
    {
      v3 = v1 + 180;
    }
    else
    {
      v3 = v1 + 180;
      v46 = *(_DWORD *)(v1 + 208);
      *(_DWORD *)(v1 + 184) = 0;
      __dmb(0xBu);
      do
        v47 = __ldrex((unsigned int *)v3);
      while ( !v47 && __strex(1u, (unsigned int *)v3) );
      if ( v47 )
        ExpReleaseFastMutexContended((unsigned int *)(v1 + 180), v47);
      KfLowerIrql((unsigned __int8)v46);
      KeAbPostRelease(v1 + 180);
      v48 = (_DWORD *)(v1 + 68);
      v49 = ObFastReferenceObject((_DWORD *)(v1 + 68));
      if ( !v49 )
        v49 = CcSlowReferenceSharedCacheMapFileObject(v1);
      v50 = CcSetValidData(v49, (int *)&v117);
      __pld(v48);
      v23 = v50;
      v51 = *v48;
      for ( k = *v48 ^ v49; k < 7; k = v53 ^ v49 )
      {
        __dmb(0xBu);
        do
          v53 = __ldrex(v48);
        while ( v53 == v51 && __strex(v51 + 1, v48) );
        if ( v53 == v51 )
          goto LABEL_83;
        v51 = v53;
      }
      ObDereferenceObjectDeferDeleteWithTag(v49);
LABEL_83:
      v54 = KeAbPreAcquire(v1 + 180, 0, 0);
      v55 = KfRaiseIrql(1);
      do
        v56 = __ldrex((unsigned __int8 *)v3);
      while ( __strex(v56 & 0xFE, (unsigned __int8 *)v3) );
      __dmb(0xBu);
      if ( (v56 & 1) == 0 )
        ExpAcquireFastMutexContended(v1 + 180, v54);
      if ( v54 )
        *(_BYTE *)(v54 + 14) |= 1u;
      v57 = __mrc(15, 0, 13, 0, 3);
      *(_DWORD *)(v1 + 208) = v55;
      *(_DWORD *)(v1 + 184) = v57 & 0xFFFFFFC0;
      if ( v23 < 0 )
      {
        if ( v23 == -1073741670 || v23 == -2147483626 || v23 == -1073741740 )
        {
          v28 = HIDWORD(v117);
          v27 = v117;
        }
        else
        {
          v28 = *(_DWORD *)(v1 + 44);
          v27 = *(_DWORD *)(v1 + 40);
        }
      }
      else
      {
        v28 = HIDWORD(v117);
        v27 = v117;
        *(_DWORD *)(v1 + 32) = v117;
        *(_DWORD *)(v1 + 36) = v28;
      }
    }
    v31 = *(_DWORD *)(v3 + 28);
    *(_DWORD *)(v3 + 4) = 0;
    __dmb(0xBu);
    do
      v32 = __ldrex((unsigned int *)v3);
    while ( !v32 && __strex(1u, (unsigned int *)v3) );
    if ( v32 )
      ExpReleaseFastMutexContended((unsigned int *)v3, v32);
    KfLowerIrql((unsigned __int8)v31);
    KeAbPostRelease(v3);
    v33 = KeAcquireQueuedSpinLock(5);
    v34 = v33;
    v35 = *(_DWORD *)(v1 + 4) - 1;
    *(_DWORD *)(v1 + 4) = v35;
    if ( v35 )
    {
      v58 = v113;
LABEL_94:
      v59 = 0;
      goto LABEL_95;
    }
    if ( v23 >= 0 || v23 != -1073741670 && v23 != -2147483626 && v23 != -1073741740 )
    {
      KeReleaseQueuedSpinLock(5, v33);
      v36 = (_DWORD *)(v1 + 68);
      v37 = ObFastReferenceObject((_DWORD *)(v1 + 68));
      if ( !v37 )
        v37 = CcSlowReferenceSharedCacheMapFileObject(v1);
      FsRtlAcquireFileExclusive(v37);
      v38 = KeAcquireQueuedSpinLock(5);
      v39 = *(_DWORD *)(v1 + 4);
      v40 = v38;
      if ( !v39 )
      {
        if ( !*(_DWORD *)(v1 + 76)
          && ((LODWORD(v41) = *(_DWORD *)(v1 + 36), HIDWORD(v41) = *(_DWORD *)(v1 + 32), v41 == 0xFFFFFFFF7FFFFFFFui64)
           || (*(_DWORD *)(v1 + 96) & 0x400) == 0
           || __SPAIR64__(v28, v27) >= *(_QWORD *)(v1 + 40))
          || !*(_QWORD *)(v1 + 8) && (*(_DWORD *)(v1 + 96) & 4) == 0 )
        {
          result = CcDeleteSharedCacheMap(v1, v38, 1, v37);
          v114[1] = 0;
          goto LABEL_55;
        }
      }
      if ( *(_DWORD *)(v1 + 76) )
      {
        if ( v113 )
          CcCancelMmWaitForUninitializeCacheMap(v1);
      }
      else if ( !v39 )
      {
        if ( (*(_DWORD *)(v1 + 96) & 0x3000000) != 0 )
        {
          v85 = (_QWORD *)(v1 + 80);
          v86 = *(_QWORD *)(v1 + 80);
          if ( *(_DWORD *)(v86 + 4) != v1 + 80 || *(_QWORD **)HIDWORD(v86) != v85 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v86) = v86;
          *(_DWORD *)(v86 + 4) = HIDWORD(v86);
          LODWORD(v87) = &CcDirtySharedCacheMapWithLogHandleList;
          HIDWORD(v87) = dword_632614;
          *v85 = v87;
          if ( *(int **)HIDWORD(v87) != &CcDirtySharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v87) = v85;
          dword_632614 = v1 + 80;
        }
        v88 = (int *)(v1 + 88);
        v89 = *(_QWORD *)(v1 + 88);
        if ( *(_DWORD *)(v89 + 4) != v1 + 88 || *(int **)HIDWORD(v89) != v88 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v89) = v89;
        *(_DWORD *)(v89 + 4) = HIDWORD(v89);
        v90 = (int **)dword_632634;
        *v88 = (int)&CcLazyWriterCursor;
        *(_DWORD *)(v1 + 92) = v90;
        if ( *v90 != &CcLazyWriterCursor )
          __fastfail(3u);
        *v90 = v88;
        dword_632634 = v1 + 88;
        v59 = 1;
LABEL_106:
        KeReleaseQueuedSpinLock(5, v40);
        FsRtlReleaseFile(v37);
        __pld(v36);
        v60 = *v36;
        for ( l = *v36 ^ v37; l < 7; l = v62 ^ v37 )
        {
          __dmb(0xBu);
          do
            v62 = __ldrex(v36);
          while ( v62 == v60 && __strex(v60 + 1, v36) );
          if ( v62 == v60 )
            goto LABEL_112;
          v60 = v62;
        }
        ObDereferenceObjectDeferDeleteWithTag(v37);
LABEL_112:
        v58 = v113;
        v34 = KeAcquireQueuedSpinLock(5);
        goto LABEL_95;
      }
      v59 = 0;
      goto LABEL_106;
    }
    v58 = v113;
    if ( v113 )
      CcCancelMmWaitForUninitializeCacheMap(v1);
    if ( *(_DWORD *)(v1 + 76) )
      goto LABEL_94;
    if ( (*(_DWORD *)(v1 + 96) & 0x3000000) != 0 )
    {
      v79 = (_QWORD *)(v1 + 80);
      v80 = *(_QWORD *)(v1 + 80);
      if ( *(_DWORD *)(v80 + 4) != v1 + 80 || *(_QWORD **)HIDWORD(v80) != v79 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v80) = v80;
      *(_DWORD *)(v80 + 4) = HIDWORD(v80);
      LODWORD(v81) = &CcDirtySharedCacheMapWithLogHandleList;
      HIDWORD(v81) = dword_632614;
      *v79 = v81;
      if ( *(int **)HIDWORD(v81) != &CcDirtySharedCacheMapWithLogHandleList )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v81) = v79;
      dword_632614 = v1 + 80;
    }
    v82 = (int *)(v1 + 88);
    v83 = *(_QWORD *)(v1 + 88);
    if ( *(_DWORD *)(v83 + 4) != v1 + 88 || *(int **)HIDWORD(v83) != v82 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v83) = v83;
    *(_DWORD *)(v83 + 4) = HIDWORD(v83);
    v84 = (int **)dword_632634;
    *v82 = (int)&CcLazyWriterCursor;
    *(_DWORD *)(v1 + 92) = v84;
    if ( *v84 != &CcLazyWriterCursor )
      __fastfail(3u);
    *v84 = v82;
    dword_632634 = v1 + 88;
    v59 = 1;
LABEL_95:
    if ( (*(_DWORD *)(v1 + 96) & 0x10000) == 0 || v58 )
      break;
    KeReleaseQueuedSpinLock(5, v34);
    v2 = v114;
  }
  if ( v114[1] != 35422 )
    *(_DWORD *)(v1 + 96) &= 0xFFFFFFDF;
  if ( v59 )
  {
    byte_632771 = 1;
    if ( (*(_DWORD *)(v1 + 96) & 0x10000) != 0 )
    {
      v91 = 1;
      v92 = 1;
    }
    else
    {
      v91 = 0;
      v92 = 0;
    }
    CcScheduleLazyWriteScan(v92, v91);
  }
  result = KeReleaseQueuedSpinLock(5, v34);
LABEL_55:
  if ( v115 )
    result = KeSetEvent(a1 + 16, 0, 0);
  return result;
}
