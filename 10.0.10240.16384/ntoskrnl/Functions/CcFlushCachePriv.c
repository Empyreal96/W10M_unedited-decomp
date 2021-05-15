// CcFlushCachePriv 
 
int __fastcall CcFlushCachePriv(int a1, void *a2, unsigned int a3, _DWORD *a4, char a5, int a6)
{
  int v6; // r9
  int v7; // r5
  int v9; // r7
  int v10; // r8
  int v11; // r10
  char *v12; // r6
  int v13; // r0
  int v14; // r4
  int v15; // r3
  signed __int64 v16; // kr20_8
  int result; // r0
  int v18; // r3
  int v19; // r10
  int *v20; // r0
  unsigned __int8 v21; // r3
  signed __int64 *v22; // r1
  int v23; // r3
  unsigned int v24; // r7
  BOOL v25; // r10
  int v26; // r0
  int v27; // r9
  int v28; // r3
  int v29; // r0
  unsigned int *v30; // r2
  unsigned int v31; // r1
  unsigned int v32; // r1
  int v33; // r0
  unsigned int *v34; // r2
  unsigned int v35; // r1
  int v36; // r7
  char v37; // r3
  int v38; // r0
  unsigned int v39; // r7
  unsigned int v40; // kr08_4
  signed __int64 v41; // kr28_8
  unsigned int v42; // r3
  int v43; // r5
  int v44; // r3
  int v45; // r9
  int v46; // r7
  unsigned int v47; // r2
  unsigned int v48; // r2
  unsigned int v49; // r1
  unsigned int *v50; // r1
  unsigned int v51; // r0
  unsigned int *v52; // r1
  unsigned int v53; // r3
  int v54; // r0
  int v55; // r2
  int v56; // r3
  int *v57; // r2
  __int64 v58; // r0
  int **v59; // r0
  int v60; // r1
  int v61; // r0
  int v62; // r0
  BOOL v63; // r7
  int v64; // r3
  _DWORD *v65; // r10
  int v66; // r0
  int v67; // r3
  int v68; // r9
  unsigned int v69; // lr
  unsigned int v70; // r2
  int v71; // r10
  int v72; // r0
  int v73; // r1
  int v74; // r0
  int v75; // r3
  unsigned int *v76; // r2
  int v77; // r9
  unsigned int v78; // lr
  unsigned int v79; // r7
  unsigned int v80; // kr10_4
  int *v81; // r2
  __int64 v82; // r0
  int **v83; // r0
  int *v84; // r2
  __int64 v85; // r0
  int **v86; // r0
  int *v87; // r2
  __int64 v88; // r0
  int **v89; // r0
  unsigned int v90; // [sp+10h] [bp-A0h]
  int v91; // [sp+14h] [bp-9Ch]
  int v92; // [sp+18h] [bp-98h]
  unsigned __int64 v93; // [sp+20h] [bp-90h] BYREF
  int v94; // [sp+28h] [bp-88h]
  int v95; // [sp+2Ch] [bp-84h]
  unsigned __int64 v96; // [sp+30h] [bp-80h] BYREF
  unsigned int v97; // [sp+38h] [bp-78h]
  unsigned int v98; // [sp+3Ch] [bp-74h]
  int v99; // [sp+40h] [bp-70h] BYREF
  unsigned int v100; // [sp+44h] [bp-6Ch] BYREF
  int v101; // [sp+48h] [bp-68h]
  int v102; // [sp+4Ch] [bp-64h]
  int v103; // [sp+50h] [bp-60h]
  int v104; // [sp+54h] [bp-5Ch] BYREF
  unsigned int v105; // [sp+58h] [bp-58h]
  unsigned int v106; // [sp+5Ch] [bp-54h]
  unsigned __int64 v107; // [sp+60h] [bp-50h]
  unsigned int v108; // [sp+68h] [bp-48h]
  char *v109; // [sp+6Ch] [bp-44h]
  signed __int64 v110; // [sp+70h] [bp-40h] BYREF
  _WORD *v111; // [sp+78h] [bp-38h] BYREF
  _DWORD *v112; // [sp+7Ch] [bp-34h]
  __int64 v113; // [sp+80h] [bp-30h] BYREF
  char v114[40]; // [sp+88h] [bp-28h] BYREF

  v6 = a3;
  v97 = a3;
  v7 = (int)a2;
  v9 = 0;
  v103 = 0;
  v104 = 0;
  v98 = 0;
  v94 = 0;
  v95 = 0;
  v10 = 0;
  v91 = 0;
  v92 = 0;
  v11 = 0;
  v112 = a4;
  v101 = a1;
  v102 = (int)a2;
  if ( a4 && a2 != &CcNoDelay )
    return sub_53C9EC();
  v12 = (char *)a6;
  v109 = (char *)a6;
  if ( !a6 )
  {
    v12 = v114;
    v109 = v114;
  }
  *(_DWORD *)v12 = 0;
  v105 = 0;
  v96 = 0i64;
  v108 = 0;
  if ( a2 == &CcNoDelay )
  {
    v10 = 1;
    v94 = *((_DWORD *)v12 + 1);
    v7 = 0;
    v102 = 0;
    *(_DWORD *)v12 = -2147483626;
  }
  else
  {
    v91 = 1;
    if ( a5 )
      v91 = 17;
  }
  *((_DWORD *)v12 + 1) = 0;
  v13 = KeAcquireQueuedSpinLock(5);
  v14 = *(_DWORD *)(a1 + 4);
  if ( v14 )
  {
    v15 = *(_DWORD *)(v14 + 96);
    if ( (v15 & 0x2000) != 0 )
    {
      if ( (v7 & 1) == 0 )
        return KeReleaseQueuedSpinLock(5, v13);
      v7 ^= 1u;
      v102 = v7;
    }
    if ( !v10 )
    {
      if ( !v7 )
      {
LABEL_15:
        ++*(_DWORD *)(v14 + 364);
        goto LABEL_16;
      }
      v16 = *(_QWORD *)(v14 + 24);
      if ( *(_QWORD *)v7 < v16 )
      {
        if ( *(_QWORD *)v7 + (unsigned int)v6 > v16 )
        {
          v6 = *(_DWORD *)(v14 + 24) - *(_DWORD *)v7;
          v97 = v6;
        }
        else
        {
          v6 = v97;
        }
        goto LABEL_15;
      }
      return KeReleaseQueuedSpinLock(5, v13);
    }
    if ( (v15 & 0x10000) != 0 )
    {
      v92 = 1;
      if ( *(_DWORD *)(v14 + 364) )
        v11 = 1;
    }
  }
LABEL_16:
  if ( v7 && !v6 )
  {
    if ( v14 && !v10 )
      --*(_DWORD *)(v14 + 364);
    return KeReleaseQueuedSpinLock(5, v13);
  }
  if ( v14 )
  {
    ++*(_DWORD *)(v14 + 4);
    v9 = *(_DWORD *)((*(_DWORD *)(v14 + 68) & 0xFFFFFFF8) + 12);
  }
  result = KeReleaseQueuedSpinLock(5, v13);
  if ( (dword_682610 & 0x20000) != 0 )
    result = CcPerfLogFlushCache(v94, v14, v7, v6, v10 == 1, v92 == 1, v11 == 1);
  if ( v10 )
  {
LABEL_25:
    if ( (v14
       && ((*(_BYTE *)(v9 + 6) & 0x10) == 0 || (*(_BYTE *)(v9 + 4) & 0x20) == 0)
       && (*(_DWORD *)(v14 + 96) & 0x20000) == 0
       || v10)
      && !v11 )
    {
      if ( !v14 )
        return result;
      if ( (*(_DWORD *)(v14 + 96) & 0x4000000) == 0 )
        goto LABEL_31;
    }
    goto LABEL_103;
  }
  if ( v14 )
  {
    if ( (*(_DWORD *)(v14 + 96) & 0x20) != 0 )
      result = CcBoostLowPriorityWorkerThread(v14);
    goto LABEL_25;
  }
LABEL_103:
  if ( (dword_682610 & 0x20000) != 0 )
    CcPerfLogFlushSection(v94, v14, v7, v6, v91);
  if ( v14 )
    CcUnmapVacbArray(v14, v7, v6, 0, 0);
  result = MmFlushSection(v101, v7, v6);
  v18 = *(_DWORD *)v12;
  if ( *(int *)v12 < 0 )
  {
    v103 = *(_DWORD *)v12;
    goto LABEL_32;
  }
LABEL_31:
  v18 = 0;
LABEL_32:
  if ( !v14 )
    goto LABEL_90;
  if ( (*(_DWORD *)(v14 + 96) & 0x4000000) != 0 )
    goto LABEL_86;
  if ( v7 )
    v110 = *(_QWORD *)v7;
  v19 = 1;
  v99 = 1;
  if ( v6 )
  {
    v19 = v6;
    v99 = v6;
  }
  if ( v10 )
  {
    KeQueryTickCount((int *)&v96);
    v105 = v96 + CcIdleDelayTick / 0xAu;
    v108 = (v96 + CcIdleDelayTick / 0xAu) >> 32;
  }
LABEL_40:
  v20 = &CcLowPriorityWorkerThreadLock;
  while ( (!v10 || *(_DWORD *)(v14 + 120) || v92)
       && (*(_QWORD *)(v14 + 8) || (*(_DWORD *)(v14 + 96) & 4) != 0 || *(_DWORD *)(v14 + 76))
       && !v95 )
  {
    if ( !v10 )
      goto LABEL_47;
    v45 = 0;
    v46 = KeAbPreAcquire((unsigned int)&CcLowPriorityWorkerThreadLock, 0, 0);
    do
      v47 = __ldrex((unsigned __int8 *)&CcLowPriorityWorkerThreadLock);
    while ( __strex(v47 | 1, (unsigned __int8 *)&CcLowPriorityWorkerThreadLock) );
    __dmb(0xBu);
    if ( (v47 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&CcLowPriorityWorkerThreadLock, v46, &CcLowPriorityWorkerThreadLock);
    if ( v46 )
      *(_BYTE *)(v46 + 14) |= 1u;
    v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( CcLowPriWorkerThread == v48 )
      v45 = 1;
    __dmb(0xBu);
    do
      v49 = __ldrex((unsigned int *)&CcLowPriorityWorkerThreadLock);
    while ( __strex(v49 - 1, (unsigned int *)&CcLowPriorityWorkerThreadLock) );
    if ( (v49 & 2) != 0 && (v49 & 4) == 0 )
      ExfTryToWakePushLock(&CcLowPriorityWorkerThreadLock);
    KeAbPostRelease((unsigned int)&CcLowPriorityWorkerThreadLock);
    if ( v45 )
      v21 = 1;
    else
LABEL_47:
      v21 = 0;
    if ( v10 )
    {
      if ( !v92 )
        v19 = 0;
      if ( !v92 )
        goto LABEL_100;
    }
    if ( v7 )
      v22 = &v110;
    else
LABEL_100:
      v22 = 0;
    v20 = (int *)CcAcquireByteRangeForWrite(v14, v22, v19, v112, &v93, &v99, (int *)&v111, v21);
    if ( !v20 )
      break;
    v23 = v99;
    v90 = v99;
    v24 = v99;
    v25 = 0;
    do
    {
      v26 = CcGetVirtualAddressIfMapped(
              v14,
              ((unsigned int)v23 - (unsigned __int64)v24) >> 32,
              v93 + v23 - v24,
              (v93 + (unsigned int)v23 - (unsigned __int64)v24) >> 32,
              &v104,
              &v100);
      v27 = v100;
      if ( v26 )
      {
        if ( v100 > v24 )
        {
          v27 = v24;
          v100 = v24;
        }
        v25 = (MmSetAddressRangeModified(v26, v27) || v25)
           && (signed __int64)(v93 + v90) < *(_QWORD *)(v14 + 32)
           && (*(_DWORD *)(v14 + 172) & 0xF) != 0
           && v10
           && !v92
           && (*(_DWORD *)(v14 + 96) & 0x200) == 0
           && !CcCoalescingState;
        v28 = v104;
        v29 = *(_DWORD *)(v104 + 4);
        __dmb(0xBu);
        v30 = (unsigned int *)(v28 + 8);
        do
        {
          v31 = __ldrex(v30);
          v32 = v31 - 1;
        }
        while ( __strex(v32, v30) );
        __dmb(0xBu);
        if ( !(_WORD)v32 )
        {
          v33 = *(_DWORD *)(v29 + 116);
          if ( v33 )
            KeSetEvent(v33, 0, 0);
        }
      }
      else if ( v100 > v24 )
      {
        v27 = v24;
        v100 = v24;
      }
      v23 = v90;
      v24 -= v27;
    }
    while ( v24 );
    v7 = v102;
    v12 = v109;
    v34 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4264);
    do
      v35 = __ldrex(v34);
    while ( __strex(v35 + v25, v34) );
    if ( v25 )
    {
      v62 = KeAcquireQueuedSpinLock(5);
      v19 = v90;
      CcPagesSkippedDueToHotSpot += v90 >> 12;
      KeReleaseQueuedSpinLock(5, v62);
    }
    else
    {
      v19 = v90;
      if ( (dword_682610 & 0x20000) != 0 )
        CcPerfLogFlushSection(v94, v14, &v93, v90, v91);
      MmFlushSection(v101, &v93, v90);
      v36 = *(_DWORD *)v12;
      if ( *(int *)v12 >= 0 )
      {
        if ( (*(_DWORD *)(v14 + 96) & 0x400) == 0 )
        {
          v54 = KeAcquireQueuedSpinLock(5);
          *(_DWORD *)(v14 + 96) |= 0x400u;
          KeReleaseQueuedSpinLock(5, v54);
        }
        if ( v10 )
        {
          v50 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4268);
          do
            v51 = __ldrex(v50);
          while ( __strex(v51 + 1, v50) );
          v52 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4272);
          do
            v53 = __ldrex(v52);
          while ( __strex(v53 + ((v90 + 4095) >> 12), v52) );
        }
        goto LABEL_78;
      }
      v64 = *(_DWORD *)(v14 + 4);
      v106 = v90;
      v107 = v93;
      v96 = v93;
      if ( !v64 )
        KeBugCheckEx(52, 4935, -1073740768);
      v65 = (_DWORD *)(v14 + 68);
      v66 = ObFastReferenceObject((_DWORD *)(v14 + 68));
      if ( !v66 )
        v66 = CcSlowReferenceSharedCacheMapFileObject(v14);
      v67 = *(_DWORD *)(v66 + 4);
      __pld(v65);
      v68 = *(_DWORD *)(v67 + 32);
      v69 = *v65;
      if ( (*v65 ^ (unsigned int)v66) >= 7 )
      {
LABEL_178:
        ObDereferenceObjectDeferDeleteWithTag(v66);
      }
      else
      {
        while ( 1 )
        {
          __dmb(0xBu);
          do
            v70 = __ldrex(v65);
          while ( v70 == v69 && __strex(v69 + 1, v65) );
          if ( v70 == v69 )
            break;
          v69 = v70;
          if ( (v70 ^ v66) >= 7 )
            goto LABEL_178;
        }
      }
      if ( MmIsWriteErrorFatal(1, v68 & 0x10, v36) )
      {
        do
        {
          if ( (dword_682610 & 0x20000) != 0 )
            CcPerfLogFlushSection(v94, v14, &v96, 4096, v91);
          MmFlushSection(v101, &v96, 4096);
          v71 = *(_DWORD *)v12;
          if ( *(int *)v12 < 0 )
          {
            if ( !*(_DWORD *)(v14 + 4) )
              KeBugCheckEx(52, 4935, -1073740768);
            v74 = ObFastReferenceObject((_DWORD *)(v14 + 68));
            if ( !v74 )
              v74 = CcSlowReferenceSharedCacheMapFileObject(v14);
            v75 = *(_DWORD *)(v74 + 4);
            v76 = (unsigned int *)(v14 + 68);
            __pld((void *)(v14 + 68));
            v77 = *(_DWORD *)(v75 + 32);
            v78 = *(_DWORD *)(v14 + 68);
            if ( (v78 ^ v74) >= 7 )
            {
LABEL_194:
              ObDereferenceObjectDeferDeleteWithTag(v74);
            }
            else
            {
              while ( 1 )
              {
                __dmb(0xBu);
                do
                  v79 = __ldrex(v76);
                while ( v79 == v78 && __strex(v78 + 1, v76) );
                if ( v79 == v78 )
                  break;
                v78 = v79;
                if ( (v79 ^ v74) >= 7 )
                  goto LABEL_194;
              }
            }
            if ( MmIsWriteErrorFatal(1, v77 & 0x10, v71) )
            {
              v73 = v95;
              v103 = *(_DWORD *)v12;
            }
            else
            {
              v73 = 1;
              v95 = 1;
            }
          }
          else
          {
            v72 = KeAcquireQueuedSpinLock(5);
            *(_DWORD *)(v14 + 96) |= 0x400u;
            KeReleaseQueuedSpinLock(5, v72);
            v73 = v95;
          }
          v80 = v107;
          LODWORD(v107) = v107 + 4096;
          LODWORD(v96) = v107;
          v107 = __PAIR64__(HIDWORD(v107), v80) + 4096;
          HIDWORD(v96) = HIDWORD(v107);
          v106 -= 4096;
        }
        while ( v106 );
        if ( !v73 )
        {
          v19 = v90;
LABEL_78:
          v37 = 0;
          goto LABEL_79;
        }
      }
      else
      {
        v95 = 1;
      }
      v19 = v90;
    }
    v37 = 1;
LABEL_79:
    v38 = CcReleaseByteRangeFromWrite(v14, (unsigned int *)&v93, v19, v111, v37);
    v98 += v19;
    if ( v98 >= 0x40000 && (int *)CcDeferredWrites != &CcDeferredWrites )
    {
      CcPostDeferredWrites(v38);
      v98 = 0;
    }
    if ( v10 )
    {
      if ( !v92 && (int *)CcDeferredWrites == &CcDeferredWrites )
      {
        v20 = KeQueryTickCount((int *)&v113);
        if ( v113 > __SPAIR64__(v108, v105) )
        {
          *((_DWORD *)v12 + 1) = 35422;
          break;
        }
      }
    }
    v20 = &CcLowPriorityWorkerThreadLock;
    if ( v7 )
    {
      v39 = *(_DWORD *)v7;
      v40 = v93;
      LODWORD(v93) = v19 + v93;
      v41 = __PAIR64__(HIDWORD(v93), v19) + v40;
      v20 = (int *)HIDWORD(v41);
      v42 = *(_DWORD *)(v7 + 4);
      HIDWORD(v93) = HIDWORD(v41);
      if ( (__int64)(__PAIR64__(v42, v97) + v39) <= v41 )
        break;
      v19 = v39 - v41 + v97;
      v99 = v19;
      v110 = v41;
      goto LABEL_40;
    }
  }
  if ( v98 && (int *)CcDeferredWrites != &CcDeferredWrites )
    CcPostDeferredWrites(v20);
LABEL_86:
  v43 = KeAcquireQueuedSpinLock(5);
  v44 = *(_DWORD *)(v14 + 4) - 1;
  *(_DWORD *)(v14 + 4) = v44;
  if ( !v44 )
  {
    byte_632771 = 1;
    v55 = *(_DWORD *)(v14 + 96);
    v56 = *(_DWORD *)(v14 + 76);
    if ( (v55 & 0x10000) != 0 )
    {
      if ( !v56 )
      {
        if ( (v55 & 0x3000000) != 0 )
        {
          v81 = (int *)(v14 + 80);
          v82 = *(_QWORD *)(v14 + 80);
          if ( *(_DWORD *)(v82 + 4) != v14 + 80 || *(int **)HIDWORD(v82) != v81 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v82) = v82;
          *(_DWORD *)(v82 + 4) = HIDWORD(v82);
          v83 = (int **)dword_632614;
          *v81 = (int)&CcDirtySharedCacheMapWithLogHandleList;
          *(_DWORD *)(v14 + 84) = v83;
          if ( *v83 != &CcDirtySharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *v83 = v81;
          dword_632614 = v14 + 80;
        }
        v84 = (int *)(v14 + 88);
        v85 = *(_QWORD *)(v14 + 88);
        if ( *(_DWORD *)(v85 + 4) != v14 + 88 || *(int **)HIDWORD(v85) != v84 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v85) = v85;
        *(_DWORD *)(v85 + 4) = HIDWORD(v85);
        v86 = (int **)dword_632634;
        *v84 = (int)&CcLazyWriterCursor;
        *(_DWORD *)(v14 + 92) = v86;
        if ( *v86 != &CcLazyWriterCursor )
          __fastfail(3u);
        *v86 = v84;
        dword_632634 = v14 + 88;
      }
      v60 = 1;
      v61 = 1;
    }
    else
    {
      if ( v56 || (v55 & 0x20) != 0 )
        goto LABEL_87;
      v63 = *(_DWORD *)(v14 + 176) != 0;
      if ( (v55 & 0x3000000) != 0 )
      {
        v87 = (int *)(v14 + 80);
        v88 = *(_QWORD *)(v14 + 80);
        if ( *(_DWORD *)(v88 + 4) != v14 + 80 || *(int **)HIDWORD(v88) != v87 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v88) = v88;
        *(_DWORD *)(v88 + 4) = HIDWORD(v88);
        v89 = (int **)dword_632614;
        *v87 = (int)&CcDirtySharedCacheMapWithLogHandleList;
        *(_DWORD *)(v14 + 84) = v89;
        if ( *v89 != &CcDirtySharedCacheMapWithLogHandleList )
          __fastfail(3u);
        *v89 = v87;
        dword_632614 = v14 + 80;
      }
      v57 = (int *)(v14 + 88);
      v58 = *(_QWORD *)(v14 + 88);
      if ( *(_DWORD *)(v58 + 4) != v14 + 88 || *(int **)HIDWORD(v58) != v57 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v58) = v58;
      *(_DWORD *)(v58 + 4) = HIDWORD(v58);
      v59 = (int **)dword_632634;
      *v57 = (int)&CcLazyWriterCursor;
      *(_DWORD *)(v14 + 92) = v59;
      if ( *v59 != &CcLazyWriterCursor )
        __fastfail(3u);
      *v59 = v57;
      dword_632634 = v14 + 88;
      v60 = 0;
      v61 = v63;
    }
    CcScheduleLazyWriteScan(v61, v60);
  }
LABEL_87:
  if ( !v10 )
    --*(_DWORD *)(v14 + 364);
  result = KeReleaseQueuedSpinLock(5, v43);
  v18 = v103;
LABEL_90:
  if ( v18 < 0 )
    *(_DWORD *)v12 = v18;
  return result;
}
