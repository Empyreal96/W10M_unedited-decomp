// CcWorkerThread 
 
int __fastcall CcWorkerThread(int *a1)
{
  int *v2; // r6
  int v3; // r5
  int v4; // r3
  int v5; // r3
  int v6; // r4
  int *v7; // r2
  int v8; // r2
  int v9; // r1
  int *v10; // r0
  int *v11; // r6
  BOOL v12; // r0
  int v13; // r0
  signed __int64 v14; // kr08_8
  int v15; // r0
  int v16; // r1
  _DWORD *v17; // r0
  int v18; // r2
  unsigned int v19; // r4
  unsigned int v20; // r6
  int v21; // r1
  _DWORD *v22; // r0
  int v23; // r2
  int v24; // r4
  unsigned int v25; // r2
  unsigned int v26; // r2
  int v27; // r3
  int v28; // r3
  unsigned int v29; // r2
  unsigned int v30; // r3
  unsigned int v31; // r2
  unsigned int v32; // r2
  unsigned int v33; // r2
  unsigned int v34; // r1
  int v35; // r4
  int **v36; // r2
  unsigned int v37; // r2
  int **v38; // r2
  int result; // r0
  int v40; // [sp+Ch] [bp-74h]
  int v41; // [sp+14h] [bp-6Ch]
  int v42; // [sp+18h] [bp-68h]
  int *v43; // [sp+20h] [bp-60h]
  int v44; // [sp+28h] [bp-58h] BYREF
  int v45; // [sp+2Ch] [bp-54h]
  __int64 v46; // [sp+38h] [bp-48h] BYREF
  int v47; // [sp+40h] [bp-40h]
  unsigned int v48; // [sp+44h] [bp-3Ch]
  int v49; // [sp+48h] [bp-38h]
  int *v50; // [sp+4Ch] [bp-34h]
  unsigned int v51; // [sp+58h] [bp-28h]

  v2 = 0;
  v3 = 0;
  v42 = 0;
  v50 = a1;
  v46 = 0i64;
  v44 = 0;
  v45 = 0;
  v4 = a1[4];
  if ( v4 == 1 )
  {
    v5 = 0;
  }
  else
  {
    if ( v4 != 2 )
      KeBugCheckEx(52, 5643, -1073740768);
    v5 = 1;
  }
  v41 = v5;
  while ( 1 )
  {
    v6 = 0;
    v48 = 0;
    v51 = 0;
    v40 = 0;
    v47 = KeAcquireQueuedSpinLock(8);
    if ( v42 )
    {
      CcQueueThrottle = 0;
      v42 = 0;
      CcReEngageWorkerThreads(CcThreadsActiveBeforeThrottle, CcExtraWBThreadsActiveBeforeThrottle);
    }
    if ( v45 == 35422 )
    {
      if ( *(_BYTE *)(v3 + 64) == 2 )
        *(_DWORD *)(*(_DWORD *)(v3 + 8) + 352) = v3;
      v7 = (int *)v2[1];
      *(_DWORD *)v3 = v2;
      *(_DWORD *)(v3 + 4) = v7;
      if ( (int *)*v7 != v2 )
        __fastfail(3u);
      *v7 = v3;
      v2[1] = v3;
      v45 = 0;
    }
    v8 = v41;
    if ( v41 )
    {
      if ( CcRemoveExtraThreadPending )
        break;
    }
    while ( 2 )
    {
      v9 = CcActiveExtraWriteBehindThreads;
      while ( 1 )
      {
        do
        {
          if ( v8
            || ((v6 & 1) != 0
             || (v6 |= 1u, v10 = &CcFastTeardownWorkQueue, (int *)CcFastTeardownWorkQueue == &CcFastTeardownWorkQueue))
            && ((v6 & 2) != 0 || (v6 |= 2u, v10 = &CcExpressWorkQueue, (int *)CcExpressWorkQueue == &CcExpressWorkQueue)) )
          {
            if ( (v6 & 4) != 0 )
              goto LABEL_99;
            v6 |= 4u;
            if ( (int *)CcRegularWorkQueue == &CcRegularWorkQueue )
              goto LABEL_99;
            v11 = &CcRegularWorkQueue;
          }
          else
          {
            v11 = v10;
          }
          v43 = v11;
          if ( !v8 )
            break;
          v12 = CcIsWriteBehindThreadpoolAtLowPriority();
          v8 = v41;
        }
        while ( v12 );
        if ( v11 == &CcRegularWorkQueue )
          goto LABEL_35;
        if ( CcPostTickWorkItemCount )
        {
          if ( CcExecutingHighPriorityWorkItem + 1 >= (unsigned int)CcNumberWorkerThreads )
          {
            v8 = v41;
            if ( !v9 )
              continue;
          }
        }
        if ( v11 != &CcRegularWorkQueue )
          break;
LABEL_35:
        v8 = v41;
        if ( CcExecutingWriteBehindWorkItems + 1 <= (unsigned int)CcMaxNumberOfWriteBehindThreads )
          break;
      }
      v3 = CcFindNextWorkQueueEntry(v11);
      v49 = v3;
      if ( !v3 )
      {
        v8 = v41;
        continue;
      }
      break;
    }
    v13 = KeQuerySystemTime(&v46);
    v14 = v46;
    if ( CcAddExtraWriteBehindThreads
      && v46 >= CcPrevExtraWBThreadCheckTime + (unsigned int)CcExtraWBThreadDelay
      && (int *)CcIdleWorkerThreadList == &CcIdleWorkerThreadList
      && CcPagesYetToWrite
      && (int *)CcRegularWorkQueue != &CcRegularWorkQueue
      && (int *)CcIdleExtraWriteBehindThreadList != &CcIdleExtraWriteBehindThreadList )
    {
      v15 = CcOkToAddWriteBehindThread(v13);
      CcPrevExtraWBThreadCheckTime = v14;
      v16 = CcActiveExtraWriteBehindThreads;
      if ( CcActiveExtraWriteBehindThreads && v15 == 3 )
        CcRemoveExtraThreadPending = 1;
      if ( v15 == 2 )
      {
        v17 = (_DWORD *)CcIdleExtraWriteBehindThreadList;
        v18 = *(_DWORD *)CcIdleExtraWriteBehindThreadList;
        if ( *(int **)(CcIdleExtraWriteBehindThreadList + 4) != &CcIdleExtraWriteBehindThreadList
          || *(_DWORD *)(v18 + 4) != CcIdleExtraWriteBehindThreadList )
        {
          __fastfail(3u);
        }
        CcIdleExtraWriteBehindThreadList = *(_DWORD *)CcIdleExtraWriteBehindThreadList;
        *(_DWORD *)(v18 + 4) = &CcIdleExtraWriteBehindThreadList;
        CcActiveExtraWriteBehindThreads = v16 + 1;
        *v17 = 0;
        ExQueueWorkItem(v17, 0);
        v40 = 1;
      }
    }
    if ( v11 == &CcRegularWorkQueue )
    {
      v20 = HIDWORD(v14);
      v19 = v14;
      CcPrevRegularQueueItemRunTime = v14;
    }
    else
    {
      v20 = HIDWORD(CcPrevRegularQueueItemRunTime);
      v19 = CcPrevRegularQueueItemRunTime;
    }
    if ( CcIsWriteBehindThreadpoolAtLowPriority()
      || v14 < (__int64)(__PAIR64__(v20, CcExtraWBThreadDelay) + v19)
      || (int *)CcIdleWorkerThreadList != &CcIdleWorkerThreadList
      || (int *)CcRegularWorkQueue == &CcRegularWorkQueue
      || (int *)CcIdleExtraWriteBehindThreadList == &CcIdleExtraWriteBehindThreadList
      || v21 )
    {
      v24 = v40;
    }
    else
    {
      v22 = (_DWORD *)CcIdleExtraWriteBehindThreadList;
      v23 = *(_DWORD *)CcIdleExtraWriteBehindThreadList;
      if ( *(int **)(CcIdleExtraWriteBehindThreadList + 4) != &CcIdleExtraWriteBehindThreadList
        || *(_DWORD *)(v23 + 4) != CcIdleExtraWriteBehindThreadList )
      {
        __fastfail(3u);
      }
      CcIdleExtraWriteBehindThreadList = *(_DWORD *)CcIdleExtraWriteBehindThreadList;
      *(_DWORD *)(v23 + 4) = &CcIdleExtraWriteBehindThreadList;
      CcActiveExtraWriteBehindThreads = 1;
      *v22 = 0;
      ExQueueWorkItem(v22, 0);
      CcPrevRegularQueueItemRunTime = v14;
      v24 = 1;
    }
    v2 = v43;
    __dmb(0xBu);
    if ( v2 == &CcRegularWorkQueue )
    {
      do
        v26 = __ldrex((unsigned int *)&CcExecutingWriteBehindWorkItems);
      while ( __strex(v26 + 1, (unsigned int *)&CcExecutingWriteBehindWorkItems) );
    }
    else
    {
      do
        v25 = __ldrex((unsigned int *)&CcExecutingHighPriorityWorkItem);
      while ( __strex(v25 + 1, (unsigned int *)&CcExecutingHighPriorityWorkItem) );
    }
    __dmb(0xBu);
    KeReleaseQueuedSpinLock(8, v47);
    v27 = dword_682610;
    if ( (dword_682610 & 0x20000) != 0 && v24 )
    {
      CcLogExtraWBThreadAction(2);
      v27 = dword_682610;
    }
    if ( (v27 & 0x20000) != 0 )
      CcPerfLogWorkItemDequeue(v3);
    v28 = *(unsigned __int8 *)(v3 + 64);
    switch ( v28 )
    {
      case 1:
        CcPerformReadAhead(v3, *(_DWORD *)(v3 + 8));
        break;
      case 2:
        v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        *(_DWORD *)(v29 + 964) |= 2u;
        do
        {
          v45 = v3;
          CcWriteBehind(*(_DWORD *)(v3 + 8), (int)&v44);
          v30 = v48;
          if ( v48 >= 0xA )
            break;
          ++v48;
          v51 = v30 + 1;
        }
        while ( v45 == 35422 );
        v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        *(_DWORD *)(v31 + 964) &= 0xFFFFFFFD;
        break;
      case 3:
        CcLazyWriteScan(v3, *(_DWORD *)(v3 + 8));
        break;
      case 4:
        KeSetEvent(*(_DWORD *)(v3 + 8), 0, 0);
        v42 = 1;
        break;
    }
    __dmb(0xBu);
    if ( v43 == &CcRegularWorkQueue )
    {
      do
        v33 = __ldrex((unsigned int *)&CcExecutingWriteBehindWorkItems);
      while ( __strex(v33 - 1, (unsigned int *)&CcExecutingWriteBehindWorkItems) );
    }
    else
    {
      do
        v32 = __ldrex((unsigned int *)&CcExecutingHighPriorityWorkItem);
      while ( __strex(v32 - 1, (unsigned int *)&CcExecutingHighPriorityWorkItem) );
    }
    __dmb(0xBu);
    if ( v45 == 35422 )
    {
      if ( (dword_682610 & 0x20000) != 0 )
        CcPerfLogWorkItemEnqueue(v43, v3, 1, 0);
    }
    else
    {
      if ( (dword_682610 & 0x20000) != 0 )
        CcPerfLogWorkItemComplete(v3, 0x20000);
      v34 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      v35 = *(_DWORD *)(v34 + 2864);
      ++*(_DWORD *)(v35 + 20);
      if ( *(unsigned __int16 *)(v35 + 4) < (unsigned int)*(unsigned __int16 *)(v35 + 8)
        || (++*(_DWORD *)(v35 + 24),
            v35 = *(_DWORD *)(v34 + 2868),
            ++*(_DWORD *)(v35 + 20),
            *(unsigned __int16 *)(v35 + 4) < (unsigned int)*(unsigned __int16 *)(v35 + 8)) )
      {
        RtlpInterlockedPushEntrySList((unsigned __int64 *)v35, (_DWORD *)v3);
      }
      else
      {
        ++*(_DWORD *)(v35 + 24);
        (*(void (__fastcall **)(int))(v35 + 44))(v3);
      }
    }
  }
  CcRemoveExtraThreadPending = 0;
  v9 = CcActiveExtraWriteBehindThreads;
LABEL_99:
  if ( v8 )
  {
    v36 = (int **)dword_63280C;
    *a1 = (int)&CcIdleExtraWriteBehindThreadList;
    a1[1] = (int)v36;
    if ( *v36 != &CcIdleExtraWriteBehindThreadList )
      __fastfail(3u);
    *v36 = a1;
    dword_63280C = (int)a1;
    CcActiveExtraWriteBehindThreads = --v9;
    v37 = CcNumberActiveWorkerThreads;
  }
  else
  {
    v38 = (int **)dword_63268C;
    *a1 = (int)&CcIdleWorkerThreadList;
    a1[1] = (int)v38;
    if ( *v38 != &CcIdleWorkerThreadList )
      __fastfail(3u);
    *v38 = a1;
    dword_63268C = (int)a1;
    v37 = --CcNumberActiveWorkerThreads;
  }
  if ( CcAddExtraWriteBehindThreads && !v9 && v37 <= 1 )
  {
    CcAddExtraWriteBehindThreads = 0;
    memset((_BYTE *)CcThroughputStats, 0, 8 * (CcMaxExtraWriteBehindThreads + 1));
  }
  result = KeReleaseQueuedSpinLock(8, v47);
  if ( (dword_682610 & 0x20000) != 0 )
  {
    if ( v41 )
      result = CcLogExtraWBThreadAction(3);
  }
  return result;
}
