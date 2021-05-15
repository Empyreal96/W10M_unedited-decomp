// CcQueueLazyWriteScanThread 
 
int CcQueueLazyWriteScanThread()
{
  int v1; // r2
  int v2; // r2
  _DWORD *v3; // r7
  int v4; // r5
  int v5; // r0
  int v6; // r5
  __int64 v7; // kr00_8
  int v8; // r0
  unsigned int v9[12]; // [sp+10h] [bp-30h] BYREF

  v9[0] = (unsigned int)&CcLowMemoryEvent;
  v9[1] = (unsigned int)&CcPowerEvent;
  v9[2] = (unsigned int)&CcPeriodicEvent;
  v9[3] = (unsigned int)&CcWaitingForTeardownEvent;
  v9[4] = (unsigned int)&CcCoalescingFlushEvent;
  while ( KeWaitForMultipleObjects(5u, v9, 1, 8, 0, 0, 0, dword_647400) == 2 )
  {
    if ( CcNumberOfExternalCaches && (int *)CcExternalCacheList != &CcExternalCacheList )
      CcNotifyExternalCaches(4);
    CcAdjustWriteBehindThreadPoolIfNeeded(0);
    v1 = KeAcquireQueuedSpinLock(5);
    if ( byte_632773 || byte_632772 )
    {
LABEL_14:
      KeReleaseQueuedSpinLock(5, v1);
    }
    else
    {
      CcSetLazyWriteScanQueued(4, 1);
      KeReleaseQueuedSpinLock(5, v2);
      v3 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
      v4 = v3[716];
      ++*(_DWORD *)(v4 + 12);
      v5 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v4);
      if ( !v5 )
      {
        ++*(_DWORD *)(v4 + 16);
        v6 = v3[717];
        ++*(_DWORD *)(v6 + 12);
        v5 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v6);
        if ( !v5 )
        {
          v7 = *(_QWORD *)(v6 + 32);
          v8 = *(_DWORD *)(v6 + 28);
          ++*(_DWORD *)(v6 + 16);
          v5 = (*(int (__fastcall **)(int, _DWORD, _DWORD))(v6 + 40))(v8, HIDWORD(v7), v7);
          if ( !v5 )
          {
            ++CcDbgNumberOfFailedWorkQueueEntryAllocations;
            KeAcquireQueuedSpinLock(5);
            byte_632770 = 0;
            CcSetLazyWriteScanQueued(4, 0);
            goto LABEL_14;
          }
        }
      }
      *(_DWORD *)v5 = v3[357];
      *(_BYTE *)(v5 + 64) = 3;
      *(_DWORD *)(v5 + 8) = 4;
      CcPostWorkQueue(v5, (int)&CcRegularWorkQueue);
    }
  }
  return sub_551D80();
}
