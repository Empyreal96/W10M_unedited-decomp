// CcInitializeAsyncRead 
 
// local variable allocation has failed, the output may be wrong!
int CcInitializeAsyncRead()
{
  int v0; // r0
  int v1; // lr
  int v2; // r5
  int v3; // r1
  int v4; // r2
  int v5; // r6
  int v6; // r10
  int v7; // r9
  unsigned int v8; // r4 OVERLAPPED
  int v9; // r0
  unsigned int v10; // r7
  int v11; // r8
  _DWORD *v12; // r3
  _DWORD *v13; // r3
  _DWORD *v14; // r3
  int v15; // r3
  _DWORD *v16; // r3
  _BYTE *v17; // r0
  unsigned int v18; // r5
  int v20; // r0
  int v21; // r3
  int v22; // r2
  int *v23; // r1
  int v24; // r4 OVERLAPPED
  int v25; // r0
  int v26; // r3
  int v27; // [sp+20h] [bp-40h] BYREF
  _DWORD v28[14]; // [sp+28h] [bp-38h] BYREF

  CcIdleAsyncReadWorkerThreadList = ExAllocatePoolWithTag(512, 8 * (CcMaxNestingLevel + 1));
  CcAsyncReadWorkQueue = ExAllocatePoolWithTag(512, 8 * (CcMaxNestingLevel + 1));
  CcAsyncReadCompletionWorkQueue = ExAllocatePoolWithTag(512, 8 * (CcMaxNestingLevel + 1));
  CcReaderThreadsStats = ExAllocatePoolWithTag(512, 404 * (CcMaxNestingLevel + 1));
  CcNewAsyncReadRequestEvent = ExAllocatePoolWithTag(512, 16 * (CcMaxNestingLevel + 1));
  CcNumberActiveAsyncReadWorkerThreads = ExAllocatePoolWithTag(512, 4 * (CcMaxNestingLevel + 1));
  v0 = ExAllocatePoolWithTag(512, 4 * (CcMaxNestingLevel + 1));
  v1 = CcIdleAsyncReadWorkerThreadList;
  v2 = v0;
  CcNumberActiveCompleteAsyncReadWorkItems = v0;
  if ( !CcIdleAsyncReadWorkerThreadList
    || (v3 = CcAsyncReadWorkQueue) == 0
    || (v4 = CcAsyncReadCompletionWorkQueue) == 0
    || (v5 = CcReaderThreadsStats) == 0
    || (v6 = CcNewAsyncReadRequestEvent) == 0
    || (v7 = CcNumberActiveAsyncReadWorkerThreads) == 0
    || !v0 )
  {
    KeBugCheckEx(52, 262463, 0);
  }
  v8 = 0;
  v9 = 0;
  v10 = CcMaxAsyncReadWorkerThreads;
  v11 = 0;
  v27 = 0;
  do
  {
    v12 = (_DWORD *)(v1 + 8 * v8);
    *v12 = v12;
    v12[1] = v12;
    v13 = (_DWORD *)(v3 + 8 * v8);
    *v13 = v13;
    v13[1] = v13;
    v14 = (_DWORD *)(v4 + 8 * v8);
    *v14 = v14;
    v14[1] = v14;
    v15 = v9 + v6;
    *(_BYTE *)v15 = 1;
    *(_BYTE *)(v15 + 1) = 0;
    *(_DWORD *)(v15 + 4) = 0;
    *(_BYTE *)(v15 + 2) = 4;
    v16 = (_DWORD *)(v9 + v6 + 8);
    *v16 = v16;
    v16[1] = v16;
    *(_DWORD *)(v7 + 4 * v8) = 0;
    *(_DWORD *)(v2 + 4 * v8) = 0;
    v17 = memset((_BYTE *)(v11 + v5), 255, 4 * v10);
    v18 = 1;
    *(_DWORD *)(v11 + v5) = 0;
    if ( v10 <= 1 )
      return sub_554520(v17);
    do
    {
      v20 = ExAllocatePoolWithTag(512, 32);
      if ( !v20 )
        KeBugCheckEx(52, 262506, 0);
      *(_DWORD *)(v20 + 8) = CcAsyncReadWorkerThread;
      *(_DWORD *)(v20 + 12) = v20;
      v21 = 3;
      *(_DWORD *)v20 = 0;
      *(_QWORD *)(v20 + 16) = *(_QWORD *)(&v8 - 1);
      *(_DWORD *)(v20 + 24) = v18;
      v1 = CcIdleAsyncReadWorkerThreadList;
      v22 = CcIdleAsyncReadWorkerThreadList + 8 * v8;
      v23 = *(int **)(v22 + 4);
      *(_DWORD *)v20 = v22;
      *(_DWORD *)(v20 + 4) = v23;
      if ( *v23 != v22 )
        __fastfail(3u);
      ++v18;
      *v23 = v20;
      v10 = CcMaxAsyncReadWorkerThreads;
      *(_DWORD *)(v22 + 4) = v20;
    }
    while ( v18 < v10 );
    v3 = CcAsyncReadWorkQueue;
    v4 = CcAsyncReadCompletionWorkQueue;
    v5 = CcReaderThreadsStats;
    v6 = CcNewAsyncReadRequestEvent;
    v7 = CcNumberActiveAsyncReadWorkerThreads;
    v2 = CcNumberActiveCompleteAsyncReadWorkItems;
    ++v8;
    v9 = v27 + 16;
    v27 += 16;
    v11 += 404;
  }
  while ( v8 <= CcMaxNestingLevel );
  v24 = 0;
  CcAsyncReadWorkQueueLock = 0;
  while ( 1 )
  {
    v28[4] = 0;
    v28[5] = 0;
    v28[0] = 24;
    v28[1] = 0;
    v28[2] = 0;
    v28[3] = 0;
    v25 = ExAllocatePoolWithTag(512, 32);
    if ( !v25 )
      KeBugCheckEx(52, 262542, 0);
    v26 = 3;
    *(_DWORD *)(v25 + 8) = CcAsyncReadWorkerThread;
    *(_DWORD *)(v25 + 12) = v25;
    *(_DWORD *)v25 = 0;
    *(_QWORD *)(v25 + 16) = *(_QWORD *)(&v24 - 1);
    *(_DWORD *)(v25 + 24) = 0;
    ++*(_DWORD *)(CcNumberActiveAsyncReadWorkerThreads + 4 * v24);
    if ( PsCreateSystemThread(&v27, 0x1FFFFF, v28, 0, 0, CcAsyncReadWorker, v25) < 0 )
      break;
    ZwClose();
    if ( ++v24 > (unsigned int)CcMaxNestingLevel )
      return 1;
  }
  return 0;
}
