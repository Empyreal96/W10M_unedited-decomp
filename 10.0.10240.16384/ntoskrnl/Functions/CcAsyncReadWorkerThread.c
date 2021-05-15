// CcAsyncReadWorkerThread 
 
int *__fastcall CcAsyncReadWorkerThread(int *result)
{
  int v1; // r8
  int *v2; // r6
  int v3; // r4
  int v4; // r7
  int v5; // r0
  int v6; // r5
  unsigned int v7; // r2
  int **v8; // r2
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2

  v1 = result[5];
  v2 = result;
  v3 = CcReaderThreadsStats + 404 * v1;
  v4 = CcIdleAsyncReadWorkerThreadList + 8 * v1;
  if ( result[4] == 3 )
  {
    *(_DWORD *)(v3 + 4 * result[6]) = 0;
    CcAsyncReadWorker(result);
    *(_DWORD *)(v3 + 4 * v2[6]) = -1;
    v5 = KeAbPreAcquire((unsigned int)&CcAsyncReadWorkQueueLock, 0, 0);
    v6 = v5;
    do
      v7 = __ldrex((unsigned __int8 *)&CcAsyncReadWorkQueueLock);
    while ( __strex(v7 | 1, (unsigned __int8 *)&CcAsyncReadWorkQueueLock) );
    __dmb(0xBu);
    if ( (v7 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&CcAsyncReadWorkQueueLock, v5, (unsigned int)&CcAsyncReadWorkQueueLock);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    v8 = *(int ***)(v4 + 4);
    *v2 = v4;
    v2[1] = (int)v8;
    if ( *v8 != (int *)v4 )
      __fastfail(3u);
    *v8 = v2;
    *(_DWORD *)(v4 + 4) = v2;
    --*(_DWORD *)(CcNumberActiveAsyncReadWorkerThreads + 4 * v1);
    __pld(&CcAsyncReadWorkQueueLock);
    v9 = CcAsyncReadWorkQueueLock;
    v10 = CcAsyncReadWorkQueueLock - 16;
    if ( (CcAsyncReadWorkQueueLock & 0xFFFFFFF0) <= 0x10 )
      v10 = 0;
    if ( (CcAsyncReadWorkQueueLock & 2) != 0 )
      goto LABEL_17;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&CcAsyncReadWorkQueueLock);
    while ( v11 == v9 && __strex(v10, (unsigned int *)&CcAsyncReadWorkQueueLock) );
    if ( v11 != v9 )
LABEL_17:
      ExfReleasePushLock(&CcAsyncReadWorkQueueLock, v9);
    result = (int *)KeAbPostRelease((unsigned int)&CcAsyncReadWorkQueueLock);
  }
  return result;
}
