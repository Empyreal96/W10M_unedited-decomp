// CcLazyWriteScan 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CcLazyWriteScan(int a1, int a2)
{
  int v3; // r9
  int v4; // r10
  unsigned int v5; // r4
  unsigned int v6; // r7
  int v7; // r5
  __int64 v8; // r0
  __int64 v9; // r0
  __int64 v10; // r0
  unsigned int v11; // r4
  int result; // r0
  int *v13; // r1
  unsigned int v14; // r10
  int v15; // r1 OVERLAPPED
  int v16; // r2
  int v17; // r6
  int v18; // r7
  int v19; // r4
  int v20; // r0
  int *v21; // r8
  unsigned int v22; // r3
  int v23; // r2
  unsigned int v24; // r3
  _DWORD *v25; // r9
  int v26; // r7
  int v27; // r6
  int v28; // r7
  __int64 v29; // kr28_8
  int v30; // r0
  int *v31; // r1
  int *v32; // r0
  int v33; // r2
  __int64 v34; // kr30_8
  int v35; // r1 OVERLAPPED
  int v36; // r2 OVERLAPPED
  int **v37; // r2
  int v38; // r2 OVERLAPPED
  __int64 v39; // r2
  int **v40; // r4 OVERLAPPED
  int **v41; // r3
  int v42; // r2
  int v43; // r1
  unsigned int v44; // r2
  unsigned int v45; // r3
  int *v46; // r1 OVERLAPPED
  int *v47; // [sp+8h] [bp-B8h] BYREF
  int **v48; // [sp+Ch] [bp-B4h]
  unsigned int v49; // [sp+10h] [bp-B0h] BYREF
  int v50; // [sp+14h] [bp-ACh]
  int v51; // [sp+18h] [bp-A8h]
  int v52; // [sp+1Ch] [bp-A4h]
  int v53; // [sp+20h] [bp-A0h]
  int v54; // [sp+24h] [bp-9Ch]
  int v55; // [sp+28h] [bp-98h]
  int v56; // [sp+30h] [bp-90h] BYREF
  int v57; // [sp+34h] [bp-8Ch]
  int v58; // [sp+38h] [bp-88h]
  __int64 v59; // [sp+3Ch] [bp-84h]
  int v60; // [sp+44h] [bp-7Ch]
  unsigned int v61; // [sp+48h] [bp-78h]
  __int64 v62; // [sp+50h] [bp-70h] BYREF
  int v63; // [sp+58h] [bp-68h] BYREF
  int v64[4]; // [sp+60h] [bp-60h] BYREF
  int v65[20]; // [sp+70h] [bp-50h] BYREF

  v53 = a1;
  v50 = a2;
  v51 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v3 = 0;
  CcScanLogHandleList((int *)&v49, a2, &v62);
  v4 = KeAcquireQueuedSpinLock(5);
  v58 = v4;
  CcSetLazyWriteScanQueued(a2, 0);
  v6 = dword_6326E0;
  v5 = *(_DWORD *)algn_6326DC;
  v7 = dword_6326D8;
  LODWORD(v8) = dword_6326E0;
  v60 = dword_6326E0;
  if ( !__PAIR64__(HIDWORD(v8), dword_6326E0) )
    __brkdiv0();
  LODWORD(v9) = _rt_udiv64(v8, qword_6326D0);
  v59 = v9;
  *(_QWORD *)&CcAverageAvailablePages = v9;
  if ( !v6 )
    __brkdiv0();
  v10 = (unsigned int)_rt_udiv64(v6, __PAIR64__(v5, v7));
  v61 = v10;
  *(_QWORD *)&CcAverageDirtyPages = v10;
  v11 = *(_DWORD *)(*(_DWORD *)dword_634340 + 3712);
  __dmb(0xBu);
  if ( v6 <= 1 )
    return sub_54A974();
  qword_6326D0 = v11 + v59 * (unsigned int)(v60 - 1);
  *(_QWORD *)&dword_6326D8 = __PAIR64__(HIDWORD(v10), v61) * (unsigned int)(v60 - 1)
                           + (unsigned int)CcGlobalDirtyPageStatistics;
  if ( !CcGlobalDirtyPageStatistics && !byte_632771 )
  {
    if ( (int *)CcDeferredWrites == &CcDeferredWrites )
    {
      byte_632770 = 0;
      return KeReleaseQueuedSpinLock(5, v4);
    }
    CcRescheduleLazyWriteScan(0);
    result = KeReleaseQueuedSpinLock(5, v4);
    return CcPostDeferredWrites(result);
  }
  v48 = &v47;
  v47 = (int *)&v47;
  while ( 1 )
  {
    v13 = (int *)CcPostTickWorkQueue;
    if ( (int *)CcPostTickWorkQueue == &CcPostTickWorkQueue )
      break;
    v39 = *(_QWORD *)CcPostTickWorkQueue;
    if ( *(int **)(CcPostTickWorkQueue + 4) != &CcPostTickWorkQueue || *(_DWORD *)(v39 + 4) != CcPostTickWorkQueue )
      __fastfail(3u);
    CcPostTickWorkQueue = *(_DWORD *)CcPostTickWorkQueue;
    *(_DWORD *)(v39 + 4) = &CcPostTickWorkQueue;
    v40 = v48;
    v41 = &v47;
    *(_QWORD *)v13 = *(_QWORD *)(&v40 - 1);
    if ( *v40 != (int *)&v47 )
      __fastfail(3u);
    *v40 = v13;
    v48 = (int **)v13;
  }
  byte_632771 = 0;
  v14 = CcCalculatePagesToWrite(v50, &CcGlobalDirtyPageStatistics, &CcGlobalDirtyPageThresholds, 0);
  v49 = v14;
  CcAdjustThrottle(&CcGlobalDirtyPageStatistics, &CcGlobalDirtyPageThresholds, CcPagesYetToWrite);
  CcPagesYetToWrite = v14;
  *(_DWORD *)algn_6325E4 = CcGlobalDirtyPageStatistics;
  dword_6325E8 = v14;
  *(_DWORD *)(CcThroughputStats + 8 * CcActiveExtraWriteBehindThreads) = v14;
  KeQuerySystemTime(&CcPrevExtraWBThreadCheckTime);
  if ( (dword_682610 & 0x20000) != 0 )
  {
    v42 = *(_DWORD *)(*(_DWORD *)dword_634340 + 3712);
    __dmb(0xBu);
    v65[4] = v42;
    v65[0] = v53;
    v65[1] = v50;
    v65[2] = CcPagesYetToWrite;
    v65[3] = CcGlobalDirtyPageStatistics;
    v65[5] = CcGlobalDirtyPageThresholds;
    v65[6] = CcNumberOfMappedVacbs;
    v65[7] = dword_6326C4;
    v65[8] = dword_6326C8;
    v65[9] = CcAverageAvailablePages;
    v65[10] = CcAverageDirtyPages;
    v65[11] = CcConsecutiveWorklessLazyScanCount;
    v64[0] = (int)v65;
    v64[1] = 0;
    v64[2] = 48;
    v64[3] = 0;
    EtwTraceKernelEvent(v64, 1, 0x80020000, 5637, 4194562);
    v14 = v49;
  }
  v17 = 0;
  v18 = v58;
  v49 = 0;
  v19 = CcLazyWriterCursor - 88;
  if ( CcLazyWriterCursor != 88 )
  {
    v16 = 1;
    v20 = 65568;
    v53 = 65568;
    do
    {
      v21 = (int *)(v19 + 88);
      if ( (int *)(v19 + 88) == &CcLazyWriterCursor )
        break;
      if ( !v17 )
        v49 = v19;
      v20 = CcShouldLazyWriteCacheMap(v19, v14, *(_DWORD *)(v19 + 68) & 0xFFFFFFF8, v50);
      if ( v20 )
      {
        if ( (*(_DWORD *)(v19 + 96) & 0x1000000) != 0 )
        {
          KeQueryTickCount(&v63);
          *(_DWORD *)(*(_DWORD *)(v19 + 152) + 96) |= 1u;
          v33 = *(_DWORD *)(v19 + 152);
          v34 = *(_QWORD *)(v19 + 160);
          v55 = 1;
          if ( v34 > *(_QWORD *)(v33 + 72) )
          {
            *(_QWORD *)(v33 + 72) = v34;
            if ( (dword_682610 & 0x20000) != 0 )
              *(_DWORD *)(*(_DWORD *)(v19 + 152) + 84) = *(_DWORD *)((*(_DWORD *)(v19 + 68) & 0xFFFFFFF8) + 12);
          }
        }
        v22 = *(_DWORD *)(v19 + 76);
        v23 = *(_DWORD *)(v19 + 96);
        *(_DWORD *)(v19 + 120) = v22;
        if ( (v23 & 0x200) != 0 && v22 >= 0x40 )
        {
          if ( (v23 & 0x1000000) != 0 )
          {
            v43 = *(_DWORD *)(v19 + 152);
            v44 = *(_DWORD *)(v43 + 64);
            if ( v44 )
            {
              if ( v22 <= v44 )
                v45 = v44 - v22;
              else
                v45 = 0;
              *(_DWORD *)(v43 + 64) = v45;
              ++CcDbgSkippedReductions;
            }
            else
            {
              *(_DWORD *)(v19 + 120) = v22 >> 3;
            }
          }
          else
          {
            *(_DWORD *)(v19 + 120) = v22 >> 3;
          }
        }
        if ( !v54 )
        {
          v24 = *(_DWORD *)(v19 + 120);
          if ( v24 >= v14 )
          {
            if ( (*(_DWORD *)(v19 + 96) & 0x200) != 0 || v49 == v19 && (*(_DWORD *)(v19 + 172) & 0xF) == 0 )
            {
              v52 = 1;
            }
            else
            {
              *(_QWORD *)&v35 = *(_QWORD *)&CcLazyWriterCursor;
              if ( *(int **)(CcLazyWriterCursor + 4) != &CcLazyWriterCursor
                || *(int **)dword_632634 != &CcLazyWriterCursor )
              {
                __fastfail(3u);
              }
              *(_DWORD *)dword_632634 = CcLazyWriterCursor;
              *(_DWORD *)(v35 + 4) = v36;
              v37 = *(int ***)(v19 + 92);
              CcLazyWriterCursor = v19 + 88;
              dword_632634 = (int)v37;
              if ( *v37 != v21 )
                __fastfail(3u);
              *v37 = &CcLazyWriterCursor;
              *(_DWORD *)(v19 + 92) = &CcLazyWriterCursor;
            }
            v54 = 1;
            v14 = 0;
          }
          else
          {
            v14 -= v24;
          }
        }
        *(_DWORD *)(v19 + 96) |= 0x20u;
        ++*(_DWORD *)(v19 + 76);
        KeReleaseQueuedSpinLock(5, v18);
        v25 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
        v26 = v25[716];
        ++*(_DWORD *)(v26 + 12);
        v27 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v26);
        if ( !v27 )
        {
          ++*(_DWORD *)(v26 + 16);
          v28 = v25[717];
          ++*(_DWORD *)(v28 + 12);
          v27 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v28);
          if ( !v27 )
          {
            v29 = *(_QWORD *)(v28 + 32);
            v30 = *(_DWORD *)(v28 + 28);
            ++*(_DWORD *)(v28 + 16);
            v27 = (*(int (__fastcall **)(int, _DWORD, _DWORD))(v28 + 40))(v30, HIDWORD(v29), v29);
            if ( !v27 )
            {
              v20 = KeAcquireQueuedSpinLock(5);
              v18 = v20;
              *(_DWORD *)(v19 + 96) &= 0xFFFFFFDF;
              --*(_DWORD *)(v19 + 76);
              break;
            }
          }
        }
        *(_DWORD *)v27 = v25[357];
        *(_BYTE *)(v27 + 64) = 2;
        *(_DWORD *)(v27 + 8) = v19;
        v18 = KeAcquireQueuedSpinLock(5);
        --*(_DWORD *)(v19 + 76);
        if ( (*(_DWORD *)(v19 + 96) & 0x10000) != 0 )
        {
          v31 = &CcFastTeardownWorkQueue;
          *(_DWORD *)(v19 + 352) = v27 | 1;
        }
        else
        {
          v31 = &CcRegularWorkQueue;
          *(_DWORD *)(v19 + 352) = v27;
        }
        v20 = CcPostWorkQueue(v27, v31);
        v51 = 1;
        v3 = 0;
      }
      else
      {
        v16 = *(_DWORD *)(v19 + 96);
        v15 = v53;
        if ( (v16 & v53) == v53 )
        {
          v20 = CcIncrementWriteBehindPriority(v19);
        }
        else if ( (unsigned int)++v3 >= 0x14 && (v16 & 0x820) == 0 )
        {
          *(_DWORD *)(v19 + 96) = v16 | 0x20;
          ++*(_DWORD *)(v19 + 76);
          KeReleaseQueuedSpinLock(5, v18);
          v3 = 0;
          v20 = KeAcquireQueuedSpinLock(5);
          v18 = v20;
          *(_DWORD *)(v19 + 96) &= 0xFFFFFFDF;
          --*(_DWORD *)(v19 + 76);
        }
      }
      v19 = *(_DWORD *)(v19 + 88) - 88;
      if ( v52 )
      {
        *(_QWORD *)&v15 = *(_QWORD *)&CcLazyWriterCursor;
        if ( *(int **)(CcLazyWriterCursor + 4) != &CcLazyWriterCursor || *(int **)dword_632634 != &CcLazyWriterCursor )
          __fastfail(3u);
        *(_DWORD *)dword_632634 = CcLazyWriterCursor;
        *(_DWORD *)(v15 + 4) = v38;
        CcLazyWriterCursor = *v21;
        v16 = CcLazyWriterCursor;
        dword_632634 = (int)v21;
        if ( *(int **)(CcLazyWriterCursor + 4) != v21 )
          __fastfail(3u);
        *(_DWORD *)(CcLazyWriterCursor + 4) = &CcLazyWriterCursor;
        v52 = 0;
        *v21 = (int)&CcLazyWriterCursor;
      }
      v17 = v49;
    }
    while ( v19 != v49 );
    if ( v55 )
      CcUpdateTimeOnLogHandles(v20, v15, v16, v55);
  }
  v32 = v47;
  if ( v47 != (int *)&v47 )
  {
    v16 = 1;
    v51 = 1;
  }
  while ( v32 != (int *)&v47 )
  {
    *(_QWORD *)&v46 = *(_QWORD *)v32;
    if ( (int **)v32[1] != &v47 || (int *)v46[1] != v32 )
      __fastfail(3u);
    v47 = v46;
    v46[1] = (int)&v47;
    CcPostWorkQueue(v32, &CcRegularWorkQueue);
    v32 = v47;
  }
  v56 = 0;
  v57 = 0;
  if ( !(_BYTE)dword_681280
    && !v51
    && (int *)CcDeferredWrites == &CcDeferredWrites
    && (CcComputeNextScanTime(&v62, &v56, v16, CcDeferredWrites), v56 == -1)
    && v57 == 0x7FFFFFFF )
  {
    CcForcedDisableLazywriteScan = 1;
    byte_632770 = 0;
  }
  else
  {
    CcRescheduleLazyWriteScan(&v56);
    if ( CcForcedDisableLazywriteScan )
      CcForcedDisableLazywriteScan = 0;
  }
  result = KeReleaseQueuedSpinLock(5, v18);
  if ( (dword_682610 & 0x20000) != 0 )
    result = CcPerfLogLoggedStreamsStats(v50, CcPagesYetToWrite);
  if ( (int *)CcDeferredWrites != &CcDeferredWrites )
    return CcPostDeferredWrites(result);
  return result;
}
