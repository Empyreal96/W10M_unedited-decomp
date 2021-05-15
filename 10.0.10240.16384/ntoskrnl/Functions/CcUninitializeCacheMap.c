// CcUninitializeCacheMap 
 
int __fastcall CcUninitializeCacheMap(_DWORD *a1, int a2, _DWORD *a3)
{
  int v6; // r5
  int v7; // r0
  int v8; // r8
  int v9; // r10
  int v10; // r4
  __int64 v11; // kr08_8
  int v12; // r2
  int *v13; // r2
  __int64 v14; // r0
  int **v15; // r0
  BOOL v16; // r0
  int v17; // r6
  int *v19; // r1
  int v20; // r0
  int **v21; // r2
  int *v22; // r5
  int v23; // r0
  unsigned int *v24; // r2
  unsigned int v25; // r0
  unsigned int v26; // r3
  int v27; // r4
  unsigned int v28; // r2
  unsigned int *v29; // r2
  unsigned int v30; // r1
  int *v31; // r2
  __int64 v32; // r0
  int **v33; // r0
  unsigned int v34; // r2
  _DWORD *v35; // [sp+8h] [bp-20h]

  v35 = 0;
  v6 = 0;
  v7 = KeAcquireQueuedSpinLock(5);
  v8 = a1[6];
  v9 = v7;
  v10 = *(_DWORD *)(a1[5] + 4);
  if ( !v8 )
    goto LABEL_9;
  if ( *(_DWORD **)(v8 + 8) != a1 )
    KeBugCheckEx(52, 2177, -1073740768);
  if ( *(_DWORD *)(v8 + 100) )
  {
    KeAcquireQueuedSpinLockAtDpcLevel(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2624);
    v19 = *(int **)(v8 + 100);
    if ( v19 )
    {
      v20 = *v19;
      v35 = *(_DWORD **)(v8 + 100);
      ++CcDbgNumberOfNoopedReadAheads;
      v21 = (int **)v19[1];
      if ( *(int **)(v20 + 4) != v19 || *v21 != v19 )
        __fastfail(3u);
      *v21 = (int *)v20;
      *(_DWORD *)(v20 + 4) = v21;
      *v19 = 0;
      v19[1] = 0;
      if ( (_DWORD *)v19[2] != a1 )
        sub_53C60C();
      --*(_DWORD *)(v10 + 4);
    }
    v22 = (int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2624);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(v22);
    }
    else
    {
      v23 = *v22;
      if ( !*v22 )
      {
        v29 = (unsigned int *)v22[1];
        __dmb(0xBu);
        do
          v30 = __ldrex(v29);
        while ( (int *)v30 == v22 && __strex(0, v29) );
        if ( (int *)v30 == v22 )
          goto LABEL_64;
        v23 = KxWaitForLockChainValid(v22);
      }
      *v22 = 0;
      __dmb(0xBu);
      v24 = (unsigned int *)(v23 + 4);
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 ^ 1, v24) );
    }
LABEL_64:
    v6 = 0;
  }
  --*(_DWORD *)(v10 + 4);
  v11 = *(_QWORD *)(v8 + 92);
  if ( *(_DWORD *)(v11 + 4) != v8 + 92 || *(_DWORD *)HIDWORD(v11) != v8 + 92 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v11) = v11;
  *(_DWORD *)(v11 + 4) = HIDWORD(v11);
  if ( v8 == v10 + 248 )
  {
    *(_WORD *)v8 = 0;
    v8 = 0;
  }
  a1[6] = 0;
LABEL_9:
  if ( !v10 )
  {
    if ( a2 && !*(_QWORD *)a2 && *(_DWORD *)a1[5] )
    {
      KeReleaseQueuedSpinLock(5, v9);
      CcPurgeCacheSection(a1[5], (_QWORD *)a2, 0, 0);
    }
    else
    {
      KeReleaseQueuedSpinLock(5, v9);
    }
    if ( a3 )
      KeSetEvent((int)(a3 + 1), 0, 0);
    goto LABEL_27;
  }
  if ( a2 )
  {
    if ( *(_QWORD *)a2 || !*(_QWORD *)(v10 + 8) )
    {
      if ( *(_DWORD *)(v10 + 144) == v10 + 144 )
      {
        *(_DWORD *)(v10 + 8) = *(_DWORD *)a2;
        *(_DWORD *)(v10 + 12) = *(_DWORD *)(a2 + 4);
      }
    }
    else
    {
      *(_DWORD *)(v10 + 96) |= 0x10u;
    }
  }
  if ( *(_DWORD *)(v10 + 4) )
  {
    if ( a3 )
    {
      if ( *(_DWORD *)(v10 + 144) == v10 + 144 )
      {
        *a3 = *(_DWORD *)(v10 + 176);
        *(_DWORD *)(v10 + 176) = a3;
        if ( (*(_DWORD *)(a1[1] + 32) & 0x10) != 0 )
          v6 = 1;
      }
      else
      {
        KeSetEvent((int)(a3 + 1), 0, 0);
      }
    }
    goto LABEL_26;
  }
  if ( *(_DWORD *)(v10 + 144) != v10 + 144 )
    KeBugCheckEx(52, 2326, -1073740768);
  if ( a3 )
  {
    *a3 = *(_DWORD *)(v10 + 176);
    *(_DWORD *)(v10 + 176) = a3;
    if ( (*(_DWORD *)(a1[1] + 32) & 0x10) != 0 )
      v6 = 1;
  }
  v12 = *(_DWORD *)(v10 + 96);
  if ( (v12 & 4) == 0 && !a3
    || (v12 & 0x20) != 0
    || *(_DWORD *)(v10 + 76)
    || (v12 & 0x400) != 0 && *(_QWORD *)(v10 + 32) != 0x7FFFFFFFFFFFFFFFi64 )
  {
    if ( (v12 & 0x20) == 0 )
    {
      if ( (v12 & 0x2000000) != 0 || (v12 & 0x1000000) != 0 )
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
      v13 = (int *)(v10 + 88);
      v14 = *(_QWORD *)(v10 + 88);
      if ( *(_DWORD *)(v14 + 4) != v10 + 88 || *(int **)HIDWORD(v14) != v13 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v14) = v14;
      *(_DWORD *)(v14 + 4) = HIDWORD(v14);
      v15 = (int **)dword_632634;
      *v13 = (int)&CcLazyWriterCursor;
      *(_DWORD *)(v10 + 92) = v15;
      if ( *v15 != &CcLazyWriterCursor )
        __fastfail(3u);
      *v15 = v13;
      dword_632634 = v10 + 88;
    }
    byte_632771 = 1;
    v16 = a3 && (*(_DWORD *)(v10 + 96) & 0x20) == 0;
    CcScheduleLazyWriteScan(v16, 0);
LABEL_26:
    KeReleaseQueuedSpinLock(5, v9);
LABEL_27:
    v17 = 0;
    goto LABEL_28;
  }
  CcDeleteSharedCacheMap(v10, v9, 0, 0);
  v17 = 1;
  v6 = 0;
LABEL_28:
  if ( v8 )
    ExFreePoolWithTag(v8, 0);
  if ( v6 )
    CcAdjustWriteBehindThreadPoolIfNeeded(1);
  if ( v35 )
  {
    v26 = (unsigned int)KeGetPcr();
    v27 = *(_DWORD *)((v26 & 0xFFFFF000) + 0xB30);
    v28 = *(unsigned __int16 *)(v27 + 8);
    ++*(_DWORD *)(v27 + 20);
    if ( *(unsigned __int16 *)(v27 + 4) < v28
      || (++*(_DWORD *)(v27 + 24),
          v27 = *(_DWORD *)((v26 & 0xFFFFF000) + 0xB34),
          v34 = *(unsigned __int16 *)(v27 + 8),
          ++*(_DWORD *)(v27 + 20),
          *(unsigned __int16 *)(v27 + 4) < v34) )
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)v27, v35);
    }
    else
    {
      ++*(_DWORD *)(v27 + 24);
      (*(void (**)(void))(v27 + 44))();
    }
    ObfDereferenceObjectWithTag((int)a1);
  }
  return v17;
}
