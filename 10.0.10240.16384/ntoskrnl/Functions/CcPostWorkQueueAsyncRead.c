// CcPostWorkQueueAsyncRead 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CcPostWorkQueueAsyncRead(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r6
  int v5; // r8
  int result; // r0
  int v9; // r9
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  _DWORD *v13; // r2
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  _DWORD *v17; // r0
  _DWORD *v18; // r7
  int v19; // r0
  int v20; // r5
  unsigned int v21; // r2
  int v22; // r2
  int v23; // r1
  unsigned int v24; // r0
  unsigned int v25; // r2
  int v26; // r0
  int v27; // r7
  unsigned int v28; // r2
  _DWORD *v29; // r1 OVERLAPPED
  int v30; // r7
  _DWORD *v31; // r2 OVERLAPPED
  int v32; // r1
  unsigned int v33; // r0
  unsigned int v34; // r2
  unsigned int v35; // r1
  int v36; // r4
  unsigned int v37; // r2
  unsigned int v38; // r2
  int v39[8]; // [sp+0h] [bp-20h] BYREF

  v39[0] = a4;
  v4 = 0;
  v5 = *(_DWORD *)(a1 + 60);
  v39[0] = 0;
  if ( (dword_682610 & 0x20000) != 0 )
    return sub_522C94();
  if ( *(_BYTE *)(a1 + 64) == 5 )
  {
    v9 = 0;
    v10 = KeAbPreAcquire(&CcAsyncReadWorkQueueLock, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex((unsigned __int8 *)&CcAsyncReadWorkQueueLock);
    while ( __strex(v12 | 1, (unsigned __int8 *)&CcAsyncReadWorkQueueLock) );
    __dmb(0xBu);
    if ( (v12 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&CcAsyncReadWorkQueueLock, v10, &CcAsyncReadWorkQueueLock);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    v13 = *(_DWORD **)(a2 + 4);
    *(_DWORD *)a1 = a2;
    *(_DWORD *)(a1 + 4) = v13;
    if ( *v13 != a2 )
      __fastfail(3u);
    *v13 = a1;
    *(_DWORD *)(a2 + 4) = a1;
    if ( *(_DWORD *)(CcAsyncReadCompletionWorkQueue + 8 * v5) == CcAsyncReadCompletionWorkQueue + 8 * v5
      || *(_DWORD *)(CcNumberActiveAsyncReadWorkerThreads + 4 * v5) <= 1u )
    {
      KeSetEvent(CcNewAsyncReadRequestEvent + 16 * v5, 0, 0);
    }
    else
    {
      v9 = 1;
    }
    __pld(&CcAsyncReadWorkQueueLock);
    v14 = CcAsyncReadWorkQueueLock;
    if ( (CcAsyncReadWorkQueueLock & 0xFFFFFFF0) > 0x10 )
      v15 = CcAsyncReadWorkQueueLock - 16;
    else
      v15 = 0;
    if ( (CcAsyncReadWorkQueueLock & 2) != 0 )
      goto LABEL_42;
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)&CcAsyncReadWorkQueueLock);
    while ( v16 == v14 && __strex(v15, (unsigned int *)&CcAsyncReadWorkQueueLock) );
    if ( v16 != v14 )
LABEL_42:
      ExfReleasePushLock(&CcAsyncReadWorkQueueLock);
    result = KeAbPostRelease(&CcAsyncReadWorkQueueLock);
    if ( !v9 )
    {
      result = CcShouldSpinAsyncReadWorkerThread(v39, v5);
      v4 = (_DWORD *)v39[0];
      if ( result )
      {
        if ( !v39[0] )
          return result;
        *(_DWORD *)(CcReaderThreadsStats + 4 * (*(_DWORD *)(v39[0] + 24) + 101 * v5)) = 0;
      }
      goto LABEL_22;
    }
  }
  else
  {
    if ( *(_DWORD *)(CcAsyncReadCompletionWorkQueue + 8 * v5) == CcAsyncReadCompletionWorkQueue + 8 * v5
      && *(_DWORD *)(CcNumberActiveCompleteAsyncReadWorkItems + 4 * v5) < (unsigned int)CcMaxNumberCompleteAsyncReadExWorkItems )
    {
      goto LABEL_26;
    }
    v26 = KeAbPreAcquire(&CcAsyncReadWorkQueueLock, 0, 0);
    v27 = v26;
    do
      v28 = __ldrex((unsigned __int8 *)&CcAsyncReadWorkQueueLock);
    while ( __strex(v28 | 1, (unsigned __int8 *)&CcAsyncReadWorkQueueLock) );
    __dmb(0xBu);
    if ( (v28 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&CcAsyncReadWorkQueueLock, v26, &CcAsyncReadWorkQueueLock);
    if ( v27 )
      *(_BYTE *)(v27 + 14) |= 1u;
    v29 = (_DWORD *)(CcAsyncReadCompletionWorkQueue + 8 * v5);
    if ( (_DWORD *)*v29 == v29
      && *(_DWORD *)(CcNumberActiveCompleteAsyncReadWorkItems + 4 * v5) < (unsigned int)CcMaxNumberCompleteAsyncReadExWorkItems )
    {
      v30 = 0;
    }
    else
    {
      v31 = (_DWORD *)v29[1];
      *(_QWORD *)a1 = *(_QWORD *)&v29;
      if ( (_DWORD *)*v31 != v29 )
        __fastfail(3u);
      *v31 = a1;
      v29[1] = a1;
      v30 = 1;
    }
    __pld(&CcAsyncReadWorkQueueLock);
    v32 = CcAsyncReadWorkQueueLock;
    if ( (CcAsyncReadWorkQueueLock & 0xFFFFFFF0) <= 0x10 )
      v33 = 0;
    else
      v33 = CcAsyncReadWorkQueueLock - 16;
    if ( (CcAsyncReadWorkQueueLock & 2) != 0 )
      goto LABEL_70;
    __dmb(0xBu);
    do
      v34 = __ldrex((unsigned int *)&CcAsyncReadWorkQueueLock);
    while ( v34 == v32 && __strex(v33, (unsigned int *)&CcAsyncReadWorkQueueLock) );
    if ( v34 != v32 )
LABEL_70:
      ExfReleasePushLock(&CcAsyncReadWorkQueueLock);
    result = KeAbPostRelease(&CcAsyncReadWorkQueueLock);
    if ( !v30 )
    {
LABEL_26:
      v17 = (_DWORD *)ExAllocatePoolWithTag(512, 32, 1901552451);
      v18 = v17;
      if ( v17 )
      {
        v17[2] = CcCompleteAsyncReadWorker;
        v17[3] = v17;
        *v17 = 0;
        v17[5] = v5;
        v17[4] = 4;
        v17[7] = a1;
        v19 = KeAbPreAcquire(&CcAsyncReadWorkQueueLock, 0, 0);
        v20 = v19;
        do
          v21 = __ldrex((unsigned __int8 *)&CcAsyncReadWorkQueueLock);
        while ( __strex(v21 | 1, (unsigned __int8 *)&CcAsyncReadWorkQueueLock) );
        __dmb(0xBu);
        if ( (v21 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&CcAsyncReadWorkQueueLock, v19, &CcAsyncReadWorkQueueLock);
        if ( v20 )
          *(_BYTE *)(v20 + 14) |= 1u;
        v22 = CcNumberActiveCompleteAsyncReadWorkItems;
        v18[6] = *(_DWORD *)(CcNumberActiveCompleteAsyncReadWorkItems + 4 * v5);
        ++*(_DWORD *)(v22 + 4 * v5);
        __pld(&CcAsyncReadWorkQueueLock);
        v23 = CcAsyncReadWorkQueueLock;
        if ( (CcAsyncReadWorkQueueLock & 0xFFFFFFF0) > 0x10 )
          v24 = CcAsyncReadWorkQueueLock - 16;
        else
          v24 = 0;
        if ( (CcAsyncReadWorkQueueLock & 2) != 0 )
          goto LABEL_44;
        __dmb(0xBu);
        do
          v25 = __ldrex((unsigned int *)&CcAsyncReadWorkQueueLock);
        while ( v25 == v23 && __strex(v24, (unsigned int *)&CcAsyncReadWorkQueueLock) );
        if ( v25 != v23 )
LABEL_44:
          ExfReleasePushLock(&CcAsyncReadWorkQueueLock);
        KeAbPostRelease(&CcAsyncReadWorkQueueLock);
        *v18 = 0;
        result = ExQueueWorkItem(v18, 46);
LABEL_22:
        if ( v4 )
        {
          *v4 = 0;
          result = ExQueueWorkItem(v4, 0);
        }
        return result;
      }
      **(_DWORD **)(a1 + 44) = -1073741670;
      CcCompleteAsyncRead(a1);
      v35 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      v36 = *(_DWORD *)(v35 + 2864);
      v37 = *(unsigned __int16 *)(v36 + 8);
      ++*(_DWORD *)(v36 + 20);
      if ( *(unsigned __int16 *)(v36 + 4) < v37
        || (++*(_DWORD *)(v36 + 24),
            v36 = *(_DWORD *)(v35 + 2868),
            v38 = *(unsigned __int16 *)(v36 + 8),
            ++*(_DWORD *)(v36 + 20),
            *(unsigned __int16 *)(v36 + 4) < v38) )
      {
        result = RtlpInterlockedPushEntrySList((unsigned __int64 *)v36, (_DWORD *)a1);
      }
      else
      {
        ++*(_DWORD *)(v36 + 24);
        result = (*(int (__fastcall **)(int))(v36 + 44))(a1);
      }
    }
  }
  return result;
}
