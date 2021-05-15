// CcSetDirtyPinnedData 
 
// local variable allocation has failed, the output may be wrong!
int *__fastcall CcSetDirtyPinnedData(int *result, _DWORD *a2)
{
  int *v3; // r5
  int *v4; // r7
  int v5; // r4
  int v6; // r1
  int v7; // r4
  int v8; // r8
  unsigned __int8 *v9; // r9
  int v10; // r5
  int v11; // r10
  unsigned int v12; // r2
  unsigned int v13; // r1 OVERLAPPED
  unsigned int v14; // r2 OVERLAPPED
  unsigned int v15; // r1 OVERLAPPED
  unsigned int v16; // r2 OVERLAPPED
  int v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // r3
  unsigned int v20; // r5
  int v21; // r10
  int v22; // r0
  int v23; // r1
  _QWORD *v24; // r2
  __int64 v25; // kr08_8
  __int64 v26; // r0
  _QWORD *v27; // r2
  __int64 v28; // r0
  __int64 v29; // r0
  int v30[10]; // [sp+18h] [bp-28h] BYREF

  v3 = result;
  if ( *(_WORD *)result != 765 )
    return (int *)sub_54A418();
  v4 = v30;
  v30[0] = (int)result;
  v30[1] = 0;
  v5 = result[28];
  if ( (*(_DWORD *)(v5 + 96) & 0x1000000) != 0 )
  {
    v6 = *(_DWORD *)(v5 + 152);
    if ( (*(_DWORD *)(v6 + 92) & *(_DWORD *)(v6 + 88)) == -1 )
      result = KeQueryTickCount((int *)(v6 + 88));
  }
  if ( (*(_DWORD *)(v5 + 96) & 0x200) == 0 )
    return (int *)CcSetDirtyInMask(v5, (unsigned int *)v3 + 2, v3[1], 0);
  v7 = v30[0];
  if ( v30[0] )
  {
    do
    {
      ++v4;
      v30[0] = v7;
      if ( (v7 & 1) != 0 )
        KeBugCheckEx(52, 3619, -1073740768);
      v8 = *(_DWORD *)(v7 + 112);
      v9 = (unsigned __int8 *)(v8 + 180);
      v10 = KeAbPreAcquire(v8 + 180, 0, 0);
      v11 = KfRaiseIrql(1);
      do
        v12 = __ldrex(v9);
      while ( __strex(v12 & 0xFE, v9) );
      __dmb(0xBu);
      if ( (v12 & 1) == 0 )
        ExpAcquireFastMutexContended(v8 + 180, v10);
      if ( v10 )
        *(_BYTE *)(v10 + 14) |= 1u;
      *(_DWORD *)(v8 + 184) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v8 + 208) = v11;
      if ( !*(_BYTE *)(v7 + 2) )
      {
        v19 = *(_DWORD *)(v7 + 4);
        *(_BYTE *)(v7 + 2) = 1;
        v20 = v19 >> 12;
        if ( a2 )
        {
          *(_DWORD *)(v7 + 32) = *a2;
          *(_DWORD *)(v7 + 36) = a2[1];
          *(_DWORD *)(v7 + 40) = *a2;
          *(_DWORD *)(v7 + 44) = a2[1];
        }
        v21 = KeAcquireQueuedSpinLock(5);
        if ( !*(_DWORD *)(v8 + 76) && (*(_DWORD *)(v8 + 96) & 2) == 0 )
        {
          CcScheduleLazyWriteScan(0, 0);
          if ( (*(_DWORD *)(v8 + 96) & 0x3000000) != 0 )
          {
            v24 = (_QWORD *)(v8 + 80);
            v25 = *(_QWORD *)(v8 + 80);
            if ( *(_DWORD *)(v25 + 4) != v8 + 80 || *(_QWORD **)HIDWORD(v25) != v24 )
              __fastfail(3u);
            LODWORD(v26) = &CcDirtySharedCacheMapWithLogHandleList;
            *(_DWORD *)HIDWORD(v25) = v25;
            *(_DWORD *)(v25 + 4) = HIDWORD(v25);
            HIDWORD(v26) = dword_632614;
            *v24 = v26;
            if ( *(int **)HIDWORD(v26) != &CcDirtySharedCacheMapWithLogHandleList )
              __fastfail(3u);
            *(_DWORD *)HIDWORD(v26) = v24;
            dword_632614 = v8 + 80;
          }
          v27 = (_QWORD *)(v8 + 88);
          v28 = *(_QWORD *)(v8 + 88);
          if ( *(_DWORD *)(v28 + 4) != v8 + 88 || *(_QWORD **)HIDWORD(v28) != v27 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v28) = v28;
          *(_DWORD *)(v28 + 4) = HIDWORD(v28);
          LODWORD(v29) = &CcLazyWriterCursor;
          HIDWORD(v29) = dword_632634;
          *v27 = v29;
          if ( *(int **)HIDWORD(v29) != &CcLazyWriterCursor )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v29) = v27;
          dword_632634 = v8 + 88;
        }
        CcGlobalDirtyPageStatistics += v20;
        v22 = *(_DWORD *)(v8 + 356);
        *(_DWORD *)(v8 + 76) += v20;
        *(_DWORD *)(v22 + 20) += v20;
        if ( (*(_DWORD *)(v8 + 96) & 0x1000000) != 0 )
        {
          *(_DWORD *)(*(_DWORD *)(v8 + 152) + 12) += v20;
          v23 = *(_DWORD *)(v8 + 152);
          if ( (*(_DWORD *)(v23 + 92) & *(_DWORD *)(v23 + 88)) == -1 )
            KeQueryTickCount((int *)(v23 + 88));
        }
        if ( CcCoalescingState && (unsigned int)CcGlobalDirtyPageStatistics >= 0x2000 )
          CcScheduleLazyWriteScan(1, 0);
        if ( CcForcedDisableLazywriteScan )
        {
          CcScheduleLazyWriteScan(0, 0);
          CcForcedDisableLazywriteScan = 0;
        }
        CcAdjustWriteBehindThreadPoolIfNeeded(0);
        KeReleaseQueuedSpinLock(5, v21);
        if ( (*(_DWORD *)(v8 + 96) & 0x10000000) != 0 )
          PsUpdateDiskCounters(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150), 0i64, v20 << 12, 0, 1u, 0);
      }
      if ( a2 )
      {
        *(_QWORD *)&v13 = *(_QWORD *)(v7 + 32);
        if ( !*(_QWORD *)&v13 || *(_QWORD *)a2 < __SPAIR64__(v14, v13) )
        {
          *(_DWORD *)(v7 + 32) = *a2;
          *(_DWORD *)(v7 + 36) = a2[1];
        }
        *(_QWORD *)&v15 = *(_QWORD *)(v7 + 40);
        if ( !*(_QWORD *)&v15 || *(_QWORD *)a2 > __SPAIR64__(v16, v15) )
        {
          *(_DWORD *)(v7 + 40) = *a2;
          *(_DWORD *)(v7 + 44) = a2[1];
        }
        if ( *(_QWORD *)a2 > *(_QWORD *)(v8 + 160) )
          *(_QWORD *)(v8 + 160) = *(_QWORD *)a2;
      }
      if ( *(_QWORD *)(v7 + 24) > *(_QWORD *)(v8 + 40) )
      {
        *(_DWORD *)(v8 + 40) = *(_DWORD *)(v7 + 24);
        *(_DWORD *)(v8 + 44) = *(_DWORD *)(v7 + 28);
      }
      v17 = *(_DWORD *)(v8 + 208);
      *(_DWORD *)(v8 + 184) = 0;
      __dmb(0xBu);
      do
        v18 = __ldrex((unsigned int *)v9);
      while ( !v18 && __strex(1u, (unsigned int *)v9) );
      if ( v18 )
        ExpReleaseFastMutexContended((unsigned int *)(v8 + 180), v18);
      KfLowerIrql((unsigned __int8)v17);
      result = (int *)KeAbPostRelease(v8 + 180);
      v7 = *v4;
    }
    while ( *v4 );
  }
  return result;
}
