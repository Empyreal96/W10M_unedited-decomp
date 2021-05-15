// CcCompleteAsyncReadWorker 
 
_DWORD *__fastcall CcCompleteAsyncReadWorker(_DWORD *result)
{
  _DWORD *v1; // r7
  int v2; // r8
  unsigned int v3; // r1
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  unsigned int v12; // r2
  _DWORD *v13; // [sp+0h] [bp-20h]

  v13 = result;
  if ( result[4] == 4 )
  {
    v1 = (_DWORD *)result[7];
    v2 = result[5];
    CcCompleteAsyncRead(v1);
    v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v4 = *(_DWORD *)(v3 + 2864);
    v5 = *(unsigned __int16 *)(v4 + 8);
    ++*(_DWORD *)(v4 + 20);
    if ( *(unsigned __int16 *)(v4 + 4) < v5
      || (++*(_DWORD *)(v4 + 24),
          v4 = *(_DWORD *)(v3 + 2868),
          v12 = *(unsigned __int16 *)(v4 + 8),
          ++*(_DWORD *)(v4 + 20),
          *(unsigned __int16 *)(v4 + 4) < v12) )
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)v4, v1);
    }
    else
    {
      ++*(_DWORD *)(v4 + 24);
      (*(void (__fastcall **)(_DWORD *))(v4 + 44))(v1);
    }
    v6 = KeAbPreAcquire((unsigned int)&CcAsyncReadWorkQueueLock, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex((unsigned __int8 *)&CcAsyncReadWorkQueueLock);
    while ( __strex(v8 | 1, (unsigned __int8 *)&CcAsyncReadWorkQueueLock) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&CcAsyncReadWorkQueueLock, v6, (unsigned int)&CcAsyncReadWorkQueueLock);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    if ( *(_DWORD *)(CcAsyncReadCompletionWorkQueue + 8 * v2) == CcAsyncReadCompletionWorkQueue + 8 * v2 )
    {
      --*(_DWORD *)(CcNumberActiveCompleteAsyncReadWorkItems + 4 * v2);
      __pld(&CcAsyncReadWorkQueueLock);
      v9 = CcAsyncReadWorkQueueLock;
      if ( (CcAsyncReadWorkQueueLock & 0xFFFFFFF0) > 0x10 )
        v10 = CcAsyncReadWorkQueueLock - 16;
      else
        v10 = 0;
      if ( (CcAsyncReadWorkQueueLock & 2) != 0 )
        goto LABEL_24;
      __dmb(0xBu);
      do
        v11 = __ldrex((unsigned int *)&CcAsyncReadWorkQueueLock);
      while ( v11 == v9 && __strex(v10, (unsigned int *)&CcAsyncReadWorkQueueLock) );
      if ( v11 != v9 )
LABEL_24:
        ExfReleasePushLock(&CcAsyncReadWorkQueueLock, v9);
      KeAbPostRelease((unsigned int)&CcAsyncReadWorkQueueLock);
      result = (_DWORD *)ExFreePoolWithTag(v13, 1901552451);
    }
    else
    {
      result = (_DWORD *)sub_54A174();
    }
  }
  return result;
}
