// CcSetDirtyInMask 
 
// local variable allocation has failed, the output may be wrong!
_BYTE *__fastcall CcSetDirtyInMask(int a1, unsigned int *a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // r8
  int v6; // r0
  __int64 v7; // kr40_8
  _BYTE *v8; // r10
  int v9; // r3
  int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r1
  unsigned int v13; // r8
  unsigned int v14; // r3
  unsigned int v15; // r7
  int v16; // r4
  int v17; // r5
  unsigned int v18; // r2
  _BYTE *v19; // r7
  unsigned int v20; // r5
  int v21; // r9
  __int64 v22; // r2
  __int64 v23; // kr58_8
  unsigned int *v24; // r4
  int v25; // r5
  unsigned int v26; // r1
  _BYTE *result; // r0
  _DWORD *v28; // r4
  __int64 v29; // kr60_8
  int v30; // r10
  int v31; // r0
  int v32; // r3
  _DWORD *v33; // r2
  int v34; // r9
  int v35; // r1
  int v36; // r0
  int v37; // r5
  int v38; // r1
  int v39; // r1
  _QWORD *v40; // r2
  __int64 v41; // r0
  __int64 v42; // r0
  _BYTE *v43; // r0
  _BYTE *v44; // r2
  _DWORD *v45; // r0
  _BYTE *v46; // r1
  _BYTE *v47; // r3
  _DWORD *v48; // r0
  _BYTE *v49; // r1
  int v50; // r4
  unsigned int v51; // r1
  int v52; // r1
  _QWORD *v53; // r2
  __int64 v54; // kr70_8
  __int64 v55; // r0
  int v56; // r0
  _BYTE *v57; // [sp+18h] [bp-50h] BYREF
  int v58; // [sp+1Ch] [bp-4Ch]
  int v59; // [sp+20h] [bp-48h]
  int v60; // [sp+24h] [bp-44h]
  unsigned int v61; // [sp+28h] [bp-40h]
  int v62; // [sp+2Ch] [bp-3Ch]
  unsigned int v63; // [sp+30h] [bp-38h]
  int v64; // [sp+38h] [bp-30h]
  unsigned int *v65; // [sp+40h] [bp-28h]
  unsigned int v66; // [sp+44h] [bp-24h]

  v61 = a4;
  v4 = *a2;
  v6 = a2[1];
  v7 = *(_QWORD *)a2 + a3 - 1i64;
  v65 = a2;
  v66 = a3;
  v62 = 0;
  v60 = 0;
  v8 = 0;
  v64 = (v6 << 9) | (v4 >> 23);
  v57 = 0;
  if ( __SPAIR64__(v6, v4) / 0x1000000 != v7 / 0x1000000 )
    KeBugCheckEx(52, 3079, -1073740768);
  v9 = v6 << 20;
  v10 = v6 >> 12;
  v11 = *(_DWORD *)(a1 + 28);
  v58 = v10;
  v12 = *(_DWORD *)(a1 + 24);
  v63 = v9 | (v4 >> 12);
  v13 = v7 >> 12;
  v14 = *(_DWORD *)(a1 + 24);
  v64 = (v11 << 21) | (v12 >> 11);
  v59 = SHIDWORD(v7) >> 12;
  if ( __SPAIR64__(v11, v14) / 4096 <= v7 >> 12 )
    KeBugCheckEx(52, 3097, -1073740768);
  while ( 2 )
  {
    v15 = a1 + 180;
    while ( 1 )
    {
      if ( *(__int64 *)(a1 + 24) > 0x200000 )
      {
        result = (_BYTE *)ExAllocateFromNPagedLookasideList((int)&CcBitmapLookasideList);
        if ( !result )
        {
          ++CcDbgNumberOfFailedBitmapAllocations;
          goto LABEL_83;
        }
        v8 = result;
        v57 = result;
      }
      v62 = 1;
      v16 = KeAbPreAcquire(v15, 0, 0);
      v17 = KfRaiseIrql(1);
      do
        v18 = __ldrex((unsigned __int8 *)v15);
      while ( __strex(v18 & 0xFE, (unsigned __int8 *)v15) );
      __dmb(0xBu);
      if ( (v18 & 1) == 0 )
        ExpAcquireFastMutexContended(v15, v16);
      if ( v16 )
        *(_BYTE *)(v16 + 14) |= 1u;
      *(_DWORD *)(v15 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v15 + 28) = v17;
      v19 = *(_BYTE **)(a1 + 104);
      if ( !v19 )
      {
        result = CcAllocateInitializeMbcb();
        v19 = result;
        if ( !result )
          goto LABEL_83;
        *(_DWORD *)(a1 + 104) = result;
      }
      v20 = v63;
      v21 = v58;
      if ( v63 == v13 && v58 == v59 )
      {
        LODWORD(v22) = *((_DWORD *)v19 + 9);
        HIDWORD(v22) = *((_DWORD *)v19 + 8);
        if ( __PAIR64__(v63, v58) == v22 )
          goto LABEL_15;
      }
      if ( v59 < 0 || v59 <= 0 && v13 < 0x200 || *(_WORD *)v19 == 761 )
        break;
      v43 = memset(v8, 0, 512);
      if ( *((_DWORD *)v19 + 16) )
        return (_BYTE *)sub_53D474(v43);
      v44 = v19 + 16;
      *((_DWORD *)v19 + 17) = v8;
      v45 = (_DWORD *)*((_DWORD *)v19 + 5);
      v46 = v19 + 72;
      *((_DWORD *)v19 + 18) = v19 + 16;
      *((_DWORD *)v19 + 19) = v45;
      v47 = (_BYTE *)*v45;
      v8 = 0;
      v57 = 0;
      if ( v47 != v19 + 16 )
        __fastfail(3u);
      *v45 = v46;
      *((_DWORD *)v19 + 5) = v46;
      *((_DWORD *)v19 + 20) = -1;
      *((_DWORD *)v19 + 21) = 0x7FFFFFFF;
      *((_DWORD *)v19 + 22) = -1;
      v48 = (_DWORD *)*((_DWORD *)v19 + 5);
      v49 = v19 + 104;
      *((_DWORD *)v19 + 26) = v44;
      *((_DWORD *)v19 + 27) = v48;
      if ( (_BYTE *)*v48 != v44 )
        __fastfail(3u);
      *v48 = v49;
      *((_DWORD *)v19 + 5) = v49;
      *((_DWORD *)v19 + 28) = -1;
      *((_DWORD *)v19 + 29) = 0x7FFFFFFF;
      *((_DWORD *)v19 + 30) = -1;
      *(_WORD *)v19 = 761;
      v15 = a1 + 180;
      v50 = *(_DWORD *)(a1 + 208);
      *(_DWORD *)(a1 + 184) = 0;
      __dmb(0xBu);
      do
        v51 = __ldrex((unsigned int *)v15);
      while ( !v51 && __strex(1u, (unsigned int *)v15) );
      if ( v51 )
        ExpReleaseFastMutexContended((unsigned int *)(a1 + 180), v51);
      KfLowerIrql((unsigned __int8)v50);
      KeAbPostRelease(a1 + 180);
      v62 = 0;
    }
    result = (_BYTE *)CcFindBitmapRangeToDirty(v19, v59, v63, v58, &v57);
    v28 = result;
    if ( result )
    {
      v29 = *((_QWORD *)result + 1);
      if ( __SPAIR64__(v21, v20) < v29 + *((unsigned int *)result + 4) )
        *((_DWORD *)result + 4) = v20 - v29;
      v30 = v59;
      if ( __SPAIR64__(v59, v13) > v29 + *((unsigned int *)result + 5) )
        *((_DWORD *)result + 5) = v13 - v29;
      v31 = KeAcquireQueuedSpinLock(5);
      v32 = *(_DWORD *)(a1 + 76);
      v64 = v31;
      if ( !v32 && (*(_DWORD *)(a1 + 96) & 2) == 0 )
      {
        CcScheduleLazyWriteScan(0, 0);
        if ( (*(_DWORD *)(a1 + 96) & 0x3000000) != 0 )
        {
          v53 = (_QWORD *)(a1 + 80);
          v54 = *(_QWORD *)(a1 + 80);
          if ( *(_DWORD *)(v54 + 4) != a1 + 80 || *(_QWORD **)HIDWORD(v54) != v53 )
            __fastfail(3u);
          LODWORD(v55) = &CcDirtySharedCacheMapWithLogHandleList;
          *(_DWORD *)HIDWORD(v54) = v54;
          *(_DWORD *)(v54 + 4) = HIDWORD(v54);
          HIDWORD(v55) = dword_632614;
          *v53 = v55;
          if ( *(int **)HIDWORD(v55) != &CcDirtySharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v55) = v53;
          dword_632614 = a1 + 80;
        }
        v40 = (_QWORD *)(a1 + 88);
        v41 = *(_QWORD *)(a1 + 88);
        if ( *(_DWORD *)(v41 + 4) != a1 + 88 || *(_QWORD **)HIDWORD(v41) != v40 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v41) = v41;
        *(_DWORD *)(v41 + 4) = HIDWORD(v41);
        LODWORD(v42) = &CcLazyWriterCursor;
        HIDWORD(v42) = dword_632634;
        *v40 = v42;
        if ( *(int **)HIDWORD(v42) != &CcLazyWriterCursor )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v42) = v40;
        dword_632634 = a1 + 88;
        *((_DWORD *)v19 + 6) = v20;
        *((_DWORD *)v19 + 7) = v21;
      }
      v33 = (_DWORD *)(v28[7] + 4 * ((v20 - v28[2]) >> 5));
      v34 = 1 << (v20 & 0x1F);
      v35 = v58;
      if ( v58 <= v30 && (v58 < v30 || v20 <= v13) )
      {
        v36 = v60;
        do
        {
          if ( (*v33 & v34) == 0 )
          {
            *v33 |= v34;
            ++v36;
          }
          v34 *= 2;
          if ( !v34 )
          {
            ++v33;
            v34 = 1;
          }
          v35 = (__PAIR64__(v35, v20++) + 1) >> 32;
        }
        while ( __SPAIR64__(v35, v20) <= __SPAIR64__(v30, v13) );
        v60 = v36;
        v58 = v35;
        v63 = v20;
      }
      v37 = v60;
      CcGlobalDirtyPageStatistics += v60;
      if ( v19 )
        *((_DWORD *)v19 + 2) += v60;
      v28[6] += v37;
      v38 = *(_DWORD *)(a1 + 356);
      *(_DWORD *)(a1 + 76) += v37;
      *(_DWORD *)(v38 + 20) += v37;
      if ( (*(_DWORD *)(a1 + 96) & 0x1000000) != 0 )
      {
        *(_DWORD *)(*(_DWORD *)(a1 + 152) + 12) += v37;
        v52 = *(_DWORD *)(a1 + 152);
        if ( (*(_DWORD *)(v52 + 92) & *(_DWORD *)(v52 + 88)) == -1 )
          KeQueryTickCount((int *)(v52 + 88));
      }
      if ( CcCoalescingState && (unsigned int)CcGlobalDirtyPageStatistics >= 0x2000 )
        CcScheduleLazyWriteScan(1, 0);
      if ( CcForcedDisableLazywriteScan )
      {
        CcScheduleLazyWriteScan(0, 0);
        CcForcedDisableLazywriteScan = 0;
      }
      CcAdjustWriteBehindThreadPoolIfNeeded(0);
      KeReleaseQueuedSpinLock(5, v64);
      if ( (*(_DWORD *)(a1 + 96) & 0x10000000) != 0 && v37 )
      {
        if ( !v61 )
          v61 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        PsUpdateDiskCounters(*(_DWORD *)(v61 + 336), v39, 0, 0, v37 << 12, 0, 0, 1, 0);
      }
      if ( !v34 )
      {
        v8 = v57;
        continue;
      }
      *((_DWORD *)v19 + 8) = v13;
      *((_DWORD *)v19 + 9) = v30;
      v8 = v57;
LABEL_15:
      v23 = *(_QWORD *)v65 + v66;
      if ( v23 > *(_QWORD *)(a1 + 40) )
        *(_QWORD *)(a1 + 40) = v23;
LABEL_17:
      v24 = (unsigned int *)(a1 + 180);
      v25 = *(_DWORD *)(a1 + 208);
      *(_DWORD *)(a1 + 184) = 0;
      __dmb(0xBu);
      do
        v26 = __ldrex(v24);
      while ( !v26 && __strex(1u, v24) );
      if ( v26 )
        ExpReleaseFastMutexContended((unsigned int *)(a1 + 180), v26);
      KfLowerIrql((unsigned __int8)v25);
      result = (_BYTE *)KeAbPostRelease(a1 + 180);
      goto LABEL_23;
    }
    break;
  }
  v8 = v57;
LABEL_83:
  if ( (*(_DWORD *)(a1 + 96) & 0x20000) == 0 )
  {
    v56 = KeAcquireQueuedSpinLock(5);
    *(_DWORD *)(a1 + 96) |= 0x20000u;
    result = (_BYTE *)KeReleaseQueuedSpinLock(5, v56);
  }
  if ( v62 )
    goto LABEL_17;
LABEL_23:
  if ( v8 )
    result = (_BYTE *)ExFreeToNPagedLookasideList(&CcBitmapLookasideList, v8);
  return result;
}
