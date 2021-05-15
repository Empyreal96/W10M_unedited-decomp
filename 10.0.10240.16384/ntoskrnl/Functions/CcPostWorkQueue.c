// CcPostWorkQueue 
 
int __fastcall CcPostWorkQueue(int a1, int a2)
{
  _DWORD *v2; // r6
  int result; // r0
  int v6; // r7
  _DWORD *v7; // r2
  int v8; // r1
  __int64 v9; // r2
  unsigned int v10; // r2

  v2 = 0;
  if ( (dword_682610 & 0x20000) != 0 )
    return sub_54AB04();
  v6 = KeAcquireQueuedSpinLock(8);
  if ( *(_BYTE *)(a1 + 64) == 3 && (int *)CcRegularWorkQueue != &CcRegularWorkQueue )
  {
    if ( CcGlobalDirtyPageStatistics >= (unsigned int)CcGlobalDirtyPageThresholds >> 2
      || (v10 = *(_DWORD *)(*(_DWORD *)dword_634340 + 3712), __dmb(0xBu), CcGlobalDirtyPageStatistics > v10 >> 1) )
    {
      if ( !CcIsWriteBehindThreadpoolAtLowPriority() )
        CcAddExtraWriteBehindThreads = 1;
    }
  }
  v7 = *(_DWORD **)(a2 + 4);
  *(_DWORD *)a1 = a2;
  *(_DWORD *)(a1 + 4) = v7;
  if ( *v7 != a2 )
    __fastfail(3u);
  *v7 = a1;
  *(_DWORD *)(a2 + 4) = a1;
  if ( !CcQueueThrottle )
  {
    v8 = CcIdleWorkerThreadList;
    if ( (int *)CcIdleWorkerThreadList != &CcIdleWorkerThreadList
      && (*(_BYTE *)(a1 + 64) != 2
       || CcExecutingWriteBehindWorkItems + 1 <= (unsigned int)CcMaxNumberOfWriteBehindThreads) )
    {
      v9 = *(_QWORD *)CcIdleWorkerThreadList;
      if ( *(int **)(CcIdleWorkerThreadList + 4) != &CcIdleWorkerThreadList
        || *(_DWORD *)(v9 + 4) != CcIdleWorkerThreadList )
      {
        __fastfail(3u);
      }
      CcIdleWorkerThreadList = *(_DWORD *)CcIdleWorkerThreadList;
      *(_DWORD *)(v9 + 4) = &CcIdleWorkerThreadList;
      v2 = (_DWORD *)v8;
      ++CcNumberActiveWorkerThreads;
    }
  }
  result = KeReleaseQueuedSpinLock(8, v6);
  if ( v2 )
  {
    *v2 = 0;
    result = ExQueueWorkItem(v2, 0);
  }
  return result;
}
