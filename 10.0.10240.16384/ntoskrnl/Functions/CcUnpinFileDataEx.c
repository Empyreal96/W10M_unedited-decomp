// CcUnpinFileDataEx 
 
unsigned int __fastcall CcUnpinFileDataEx(int a1, int a2, int a3)
{
  unsigned int result; // r0
  unsigned int *v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r1
  int v10; // r9
  unsigned __int8 *v11; // r4
  int v12; // r8
  int v13; // r10
  unsigned int v14; // r2
  int v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r0
  unsigned int *v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r1
  int v22; // r5
  unsigned int v23; // r1
  int v24; // r0
  unsigned int v25; // r2
  unsigned int v26; // r6
  int v27; // r0
  int v28; // lr
  int v29; // r3
  unsigned __int8 *v30; // r6
  int v31; // r0
  int v32; // r7
  unsigned int v33; // r2
  __int64 v34; // r0
  int v35; // r1
  unsigned int v36; // r0
  unsigned int v37; // r2
  int v38; // r3
  int v39; // r0
  unsigned int *v40; // r2
  unsigned int v41; // r1
  unsigned int v42; // r1
  int v43; // r0
  int v44; // r6
  unsigned int v45; // r1
  int v46; // r3
  _DWORD *v47; // r2
  __int64 v48; // r0
  void **v49; // r0
  _DWORD *v50; // r2
  __int64 v51; // r0
  void **v52; // r0

  if ( *(_WORD *)a1 != 765 )
  {
    result = *(_DWORD *)(a1 + 4);
    __dmb(0xBu);
    v7 = (unsigned int *)(a1 + 8);
    do
    {
      v8 = __ldrex(v7);
      v9 = v8 - 1;
    }
    while ( __strex(v9, v7) );
    __dmb(0xBu);
    if ( !(_WORD)v9 )
    {
      result = *(_DWORD *)(result + 116);
      if ( result )
        result = sub_54A32C();
    }
    return result;
  }
  v10 = *(_DWORD *)(a1 + 112);
  if ( (*(_DWORD *)(v10 + 96) & 0x200) == 0 || a3 == 1 )
    a2 = 1;
  v11 = (unsigned __int8 *)(v10 + 180);
  v12 = KeAbPreAcquire(v10 + 180, 0, 0);
  v13 = KfRaiseIrql(1);
  do
    v14 = __ldrex(v11);
  while ( __strex(v14 & 0xFE, v11) );
  __dmb(0xBu);
  if ( (v14 & 1) == 0 )
    ExpAcquireFastMutexContended(v10 + 180, v12);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  v15 = __mrc(15, 0, 13, 0, 3);
  *(_DWORD *)(v10 + 208) = v13;
  *(_DWORD *)(v10 + 184) = v15 & 0xFFFFFFC0;
  if ( !a3 || a3 == 1 )
  {
    v16 = *(_DWORD *)(a1 + 52);
    if ( !v16 )
      KeBugCheckEx(52, 1064, -1073740768);
    *(_DWORD *)(a1 + 52) = v16 - 1;
  }
  else
  {
    if ( a3 != 2 )
      KeBugCheckEx(52, 132191, a3);
    if ( *(_BYTE *)(a1 + 2) )
    {
      v25 = *(_DWORD *)(a1 + 4);
      *(_BYTE *)(a1 + 2) = 0;
      v26 = v25 >> 12;
      *(_DWORD *)(a1 + 32) = 0;
      *(_DWORD *)(a1 + 36) = 0;
      *(_DWORD *)(a1 + 40) = 0;
      *(_DWORD *)(a1 + 44) = 0;
      v27 = KeAcquireQueuedSpinLock(5);
      v28 = v27;
      CcGlobalDirtyPageStatistics -= v26;
      *(_DWORD *)(v10 + 76) -= v26;
      *(_DWORD *)(*(_DWORD *)(v10 + 356) + 20) -= v26;
      if ( (*(_DWORD *)(v10 + 96) & 0x1000000) != 0 )
        *(_DWORD *)(*(_DWORD *)(v10 + 152) + 12) -= v26;
      if ( CcPagesYetToWrite <= v26 )
        v29 = 0;
      else
        v29 = CcPagesYetToWrite - v26;
      CcPagesYetToWrite = v29;
      if ( *(_DWORD *)(v10 + 76) || !*(_DWORD *)(v10 + 4) )
      {
        KeReleaseQueuedSpinLock(5, v27);
      }
      else
      {
        v46 = *(_DWORD *)(v10 + 96);
        if ( (v46 & 0x2000000) != 0 || (v46 & 0x1000000) != 0 )
        {
          v47 = (_DWORD *)(v10 + 80);
          v48 = *(_QWORD *)(v10 + 80);
          if ( *(_DWORD *)(v48 + 4) != v10 + 80 || *(_DWORD **)HIDWORD(v48) != v47 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v48) = v48;
          *(_DWORD *)(v48 + 4) = HIDWORD(v48);
          v49 = (void **)dword_632604;
          *v47 = &CcCleanSharedCacheMapWithLogHandleList;
          *(_DWORD *)(v10 + 84) = v49;
          if ( *v49 != &CcCleanSharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *v49 = v47;
          dword_632604 = v10 + 80;
        }
        v50 = (_DWORD *)(v10 + 88);
        v51 = *(_QWORD *)(v10 + 88);
        if ( *(_DWORD *)(v51 + 4) != v10 + 88 || *(_DWORD **)HIDWORD(v51) != v50 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v51) = v51;
        *(_DWORD *)(v51 + 4) = HIDWORD(v51);
        v52 = (void **)dword_63260C;
        *v50 = &CcCleanSharedCacheMapList;
        *(_DWORD *)(v10 + 92) = v52;
        if ( *v52 != &CcCleanSharedCacheMapList )
          __fastfail(3u);
        *v52 = v50;
        dword_63260C = v10 + 88;
        KeReleaseQueuedSpinLock(5, v28);
      }
    }
  }
  if ( *(_DWORD *)(a1 + 52) )
    goto LABEL_26;
  if ( *(_BYTE *)(a1 + 2) )
  {
    if ( *(_DWORD *)(a1 + 116) )
    {
      v17 = *(_DWORD *)(a1 + 48);
      v18 = *(_DWORD *)(v17 + 4);
      __dmb(0xBu);
      v19 = (unsigned int *)(v17 + 8);
      do
      {
        v20 = __ldrex(v19);
        v21 = v20 - 1;
      }
      while ( __strex(v21, v19) );
      __dmb(0xBu);
      if ( !(_WORD)v21 )
      {
        v24 = *(_DWORD *)(v18 + 116);
        if ( v24 )
          KeSetEvent(v24, 0, 0);
      }
      *(_DWORD *)(a1 + 116) = 0;
      *(_DWORD *)(a1 + 48) = 0;
    }
LABEL_26:
    if ( !a2 )
      ExpReleaseResourceForThreadLite(a1 + 56, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    *(_DWORD *)(v10 + 184) = 0;
    v22 = *(_DWORD *)(v10 + 208);
    __dmb(0xBu);
    do
      v23 = __ldrex((unsigned int *)v11);
    while ( !v23 && __strex(1u, (unsigned int *)v11) );
    if ( v23 )
      ExpReleaseFastMutexContended((unsigned int *)(v10 + 180), v23);
    KfLowerIrql((unsigned __int8)v22);
    return KeAbPostRelease(v10 + 180);
  }
  v30 = (unsigned __int8 *)(v10 + 72);
  v31 = KeAbPreAcquire(v10 + 72, 0, 0);
  v32 = v31;
  do
    v33 = __ldrex(v30);
  while ( __strex(v33 | 1, v30) );
  __dmb(0xBu);
  if ( (v33 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v10 + 72), v31, v10 + 72);
  if ( v32 )
    *(_BYTE *)(v32 + 14) |= 1u;
  v34 = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(v34 + 4) != a1 + 16 || *(_DWORD *)HIDWORD(v34) != a1 + 16 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v34) = v34;
  *(_DWORD *)(v34 + 4) = HIDWORD(v34);
  if ( *(__int64 *)(v10 + 24) > 0x2000000 && (*(_DWORD *)(v10 + 96) & 0x200) != 0 )
    CcAdjustVacbLevelLockCount(v10, HIDWORD(v34), *(_DWORD *)(a1 + 8), *(_DWORD *)(a1 + 12));
  __pld(v30);
  v35 = *(_DWORD *)v30;
  if ( (*(_DWORD *)v30 & 0xFFFFFFF0) > 0x10 )
    v36 = v35 - 16;
  else
    v36 = 0;
  if ( (v35 & 2) != 0 )
    goto LABEL_87;
  __dmb(0xBu);
  do
    v37 = __ldrex((unsigned int *)v30);
  while ( v37 == v35 && __strex(v36, (unsigned int *)v30) );
  if ( v37 != v35 )
LABEL_87:
    ExfReleasePushLock((_DWORD *)(v10 + 72), v35);
  KeAbPostRelease(v10 + 72);
  if ( *(_DWORD *)(a1 + 116) )
  {
    v38 = *(_DWORD *)(a1 + 48);
    v39 = *(_DWORD *)(v38 + 4);
    __dmb(0xBu);
    v40 = (unsigned int *)(v38 + 8);
    do
    {
      v41 = __ldrex(v40);
      v42 = v41 - 1;
    }
    while ( __strex(v42, v40) );
    __dmb(0xBu);
    if ( !(_WORD)v42 )
    {
      v43 = *(_DWORD *)(v39 + 116);
      if ( v43 )
        KeSetEvent(v43, 0, 0);
    }
  }
  v44 = *(_DWORD *)(v10 + 208);
  *(_DWORD *)(v10 + 184) = 0;
  __dmb(0xBu);
  do
    v45 = __ldrex((unsigned int *)v11);
  while ( !v45 && __strex(1u, (unsigned int *)v11) );
  if ( v45 )
    ExpReleaseFastMutexContended((unsigned int *)(v10 + 180), v45);
  KfLowerIrql((unsigned __int8)v44);
  KeAbPostRelease(v10 + 180);
  return CcDeallocateBcb(a1);
}
