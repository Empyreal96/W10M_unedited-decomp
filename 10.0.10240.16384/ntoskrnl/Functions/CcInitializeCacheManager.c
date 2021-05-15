// CcInitializeCacheManager 
 
int CcInitializeCacheManager()
{
  int v0; // r9
  int v1; // r2
  unsigned int v2; // r3
  int result; // r0
  int v4; // r3
  unsigned int v5; // r4
  __int16 v6; // r2
  int v7; // r3
  unsigned int v8; // r4
  int *v9; // r5
  int v10; // t1
  int v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r3
  _BYTE *v14; // r0
  int *v15; // r0
  int **v16; // r2
  int *v17; // r0
  int **v18; // r2
  int v19; // r0
  int v20; // r5
  int v21; // r2
  int v22; // r3
  int v23; // [sp+10h] [bp-40h] BYREF
  int v24[14]; // [sp+18h] [bp-38h] BYREF

  v0 = (unsigned __int8)dword_681280;
  if ( !KeMaximumIncrement )
    __brkdiv0();
  CcIdleDelayTick = (unsigned int)dword_989680 / KeMaximumIncrement;
  dword_632628 = 2048;
  CcCleanSharedCacheMapWithLogHandleList = &CcCleanSharedCacheMapWithLogHandleList;
  dword_632604 = (int)&CcCleanSharedCacheMapWithLogHandleList;
  CcCleanSharedCacheMapList = &CcCleanSharedCacheMapList;
  dword_63260C = (int)&CcCleanSharedCacheMapList;
  CcDirtySharedCacheMapWithLogHandleList = (int)&CcDirtySharedCacheMapWithLogHandleList;
  dword_632614 = (int)&CcDirtySharedCacheMapWithLogHandleList;
  CcLazyWriterCursor = (int)&CcDirtySharedCacheMapList;
  dword_632634 = (int)&CcDirtySharedCacheMapList;
  CcDirtySharedCacheMapList = (int)&CcLazyWriterCursor;
  *(_DWORD *)algn_632624 = &CcLazyWriterCursor;
  dword_632638 = 2048;
  CcVolumeCacheMapList = (int)&CcVolumeCacheMapList;
  dword_632644 = (int)&CcVolumeCacheMapList;
  CcBcbTrimNotificationListLock = 1;
  dword_632664 = 0;
  unk_632668 = 0;
  byte_63266C = 1;
  byte_63266D = 0;
  byte_63266E = 4;
  dword_632670 = 0;
  dword_632678 = (int)&dword_632674;
  dword_632674 = (int)&dword_632674;
  CcBcbTrimNotificationList = (int)&CcBcbTrimNotificationList;
  *(_DWORD *)algn_632684 = &CcBcbTrimNotificationList;
  CcMaxAsyncReadWorkerThreads = 100;
  CcMaxNestingLevel = 2;
  if ( !(_BYTE)dword_681280 )
  {
    CcMaxAsyncReadWorkerThreads = 50;
    if ( FsRtlIsMobileOS() )
      CcMaxAsyncReadWorkerThreads = 10;
  }
  CcFastTeardownWorkQueue = (int)&CcFastTeardownWorkQueue;
  dword_632694 = (int)&CcFastTeardownWorkQueue;
  CcExpressWorkQueue = (int)&CcExpressWorkQueue;
  *(_DWORD *)algn_63269C = &CcExpressWorkQueue;
  CcIdleWorkerThreadList = (int)&CcIdleWorkerThreadList;
  dword_63268C = (int)&CcIdleWorkerThreadList;
  CcIdleExtraWriteBehindThreadList = (int)&CcIdleExtraWriteBehindThreadList;
  dword_63280C = (int)&CcIdleExtraWriteBehindThreadList;
  CcRegularWorkQueue = (int)&CcRegularWorkQueue;
  *(_DWORD *)algn_6326A4 = &CcRegularWorkQueue;
  CcPostTickWorkQueue = (int)&CcPostTickWorkQueue;
  dword_6326AC = (int)&CcPostTickWorkQueue;
  CcGlobalDirtyPageStatistics = 0;
  *(_DWORD *)algn_6325E4 = 0;
  dword_6325E8 = 0;
  memset(&CcGlobalDirtyPageThresholds, 0, 40);
  CcLowPriWorkerThread = 0;
  CcLowPriSharedCacheMap = 0;
  CcLowPriOldCpuPriority = 32;
  CcLowPriOldIoPriority = 5;
  CcLowPriorityWorkerThreadLock = 0;
  v1 = CcNumberWorkerThreads;
  if ( !CcNumberWorkerThreads )
  {
    v2 = *(_DWORD *)(*(_DWORD *)dword_634340 + 3592);
    if ( v0 )
      return sub_965D90();
    dword_6326C4 = v2 >> 3;
    dword_6326C8 = v2 >> 3;
    CcMaxLazyWritePages = 256;
    CcMaxExtraWriteBehindThreads = 1;
    CcExtraWBThreadDelay = (int)dword_989680;
    CcGlobalDirtyPageThresholds = v2 >> 3;
    dword_6326E0 = 10;
    dword_6326D8 = 0;
    *(_DWORD *)algn_6326DC = 0;
    v1 = ExCriticalWorkerThreads - 1;
    v4 = *(_DWORD *)(*(_DWORD *)dword_634340 + 3592);
    CcNumberWorkerThreads = ExCriticalWorkerThreads - 1;
    qword_6326D0 = (unsigned int)(10 * v4);
    CcAggressiveZeroThreshold = 4;
    dword_6326CC = ((unsigned int)CcGlobalDirtyPageThresholds >> 1) + ((unsigned int)CcGlobalDirtyPageThresholds >> 2);
  }
  v5 = 0;
  CcAggressiveZeroCount = 0;
  if ( v1 )
  {
    do
    {
      v15 = (int *)ExAllocatePoolWithTag(512, 32, 1901552451);
      if ( !v15 )
        KeBugCheckEx(52, 262811, 0, 0, 0);
      v15[2] = (int)CcWorkerThread;
      v15[3] = (int)v15;
      *v15 = 0;
      v15[4] = 1;
      v16 = (int **)dword_63268C;
      *v15 = (int)&CcIdleWorkerThreadList;
      v15[1] = (int)v16;
      if ( *v16 != &CcIdleWorkerThreadList )
        __fastfail(3u);
      ++v5;
      *v16 = v15;
      dword_63268C = (int)v15;
    }
    while ( v5 < CcNumberWorkerThreads );
  }
  v12 = 0;
  if ( CcMaxExtraWriteBehindThreads )
  {
    do
    {
      v17 = (int *)ExAllocatePoolWithTag(512, 32, 1901552451);
      if ( !v17 )
        KeBugCheckEx(52, 262836, 0, 0, 0);
      v17[2] = (int)CcWorkerThread;
      v17[3] = (int)v17;
      *v17 = 0;
      v17[4] = 2;
      v17[6] = v12;
      v18 = (int **)dword_63280C;
      *v17 = (int)&CcIdleExtraWriteBehindThreadList;
      v17[1] = (int)v18;
      if ( *v18 != &CcIdleExtraWriteBehindThreadList )
        __fastfail(3u);
      v13 = CcMaxExtraWriteBehindThreads;
      ++v12;
      *v18 = v17;
      dword_63280C = (int)v17;
    }
    while ( v12 < v13 );
  }
  CcAsyncReadWorkQueueLock = 0;
  if ( v0 )
  {
    CcMaxNumberCompleteAsyncReadExWorkItems = 500;
  }
  else
  {
    CcMaxNumberCompleteAsyncReadExWorkItems = 50;
    if ( FsRtlIsMobileOS() )
      CcMaxNumberCompleteAsyncReadExWorkItems = 9;
  }
  v14 = (_BYTE *)ExAllocatePoolWithTag(512, 8 * (CcMaxExtraWriteBehindThreads + 1), 1884578627);
  CcThroughputStats = (int)v14;
  if ( !v14 )
    KeBugCheckEx(52, 262888, 0, 0, 0);
  memset(v14, 0, 8 * (CcMaxExtraWriteBehindThreads + 1));
  memset(&LazyWriter, 0, 88);
  CcLowMemoryEvent = 1;
  byte_632781 = 0;
  byte_632782 = 4;
  dword_632784 = 0;
  dword_63278C = (int)&dword_632788;
  dword_632788 = (int)&dword_632788;
  CcPowerEvent = 1;
  byte_632791 = 0;
  byte_632792 = 4;
  dword_632794 = 0;
  dword_63279C = (int)&dword_632798;
  dword_632798 = (int)&dword_632798;
  CcPeriodicEvent = 1;
  byte_6327A1 = 0;
  byte_6327A2 = 4;
  dword_6327A4 = 0;
  dword_6327AC = (int)&dword_6327A8;
  dword_6327A8 = (int)&dword_6327A8;
  CcWaitingForTeardownEvent = 1;
  byte_6327B1 = 0;
  byte_6327B2 = 4;
  dword_6327B4 = 0;
  dword_6327BC = (int)&dword_6327B8;
  dword_6327B8 = (int)&dword_6327B8;
  CcCoalescingFlushEvent = 1;
  byte_6327C1 = 0;
  byte_6327C2 = 4;
  dword_6327C4 = 0;
  dword_6327CC = (int)&dword_6327C8;
  dword_6327C8 = (int)&dword_6327C8;
  CcPrepareDelayedFlushTimers();
  v19 = ExAllocatePoolWithTag(512, 4, 1482911812);
  v20 = v19;
  if ( v19 )
  {
    ExFreePoolWithTag(v19);
    ExGenRandom(0);
    if ( (ExGenRandom(0) & 1) != 0 )
      v22 = 1;
    else
      v22 = 2;
    v21 = v22 | v20;
  }
  else
  {
    v21 = 0;
  }
  LazyWriter = 19;
  byte_632721 = 1;
  word_632722 = 0;
  unk_63272C = CcScanDpc;
  unk_632730 = v21;
  dword_63273C = 0;
  dword_632728 = 0;
  KeInitializeTimerEx(dword_632740, 0);
  CcConsecutiveWorklessLazyScanCount = 0;
  CcMaxWorklessLazywriteScans = 1;
  CcForcedDisableLazywriteScan = 0;
  v6 = 128;
  if ( v0 )
    v6 = 256;
  ExInitializeSystemLookasideList(
    (int)&CcTwilightLookasideList,
    512,
    72,
    1800889155,
    v6,
    (int)&ExSystemLookasideListHead);
  if ( v0 )
    v7 = 0x2000000;
  else
    v7 = 0x100000;
  CcMaxZeroTransferSize = v7;
  v8 = 0;
  if ( KeNumberProcessors_0 )
  {
    v9 = (int *)&KiProcessorBlock;
    do
    {
      v10 = *v9++;
      CcInitializeProcessor(v10);
      ++v8;
    }
    while ( v8 < KeNumberProcessors_0 );
  }
  CcDbgNumberOfFailedWorkQueueEntryAllocations = 0;
  ExInitializeNPagedLookasideList((int)&CcBitmapLookasideList, 0, 0, 512);
  CcDbgNumberOfFailedBitmapAllocations = 0;
  ExInitializeNPagedLookasideList((int)&CcVacbLevelLookasideList, 0, 0, 512);
  v11 = ExInitializeNPagedLookasideList((int)&CcVacbLevelWithBcbListHeadsLookasideList, 0, 0, 512);
  CcDeferredWriteSpinLock = 0;
  CcDeferredWrites = (int)&CcDeferredWrites;
  *(_DWORD *)algn_6327EC = &CcDeferredWrites;
  CcExternalCacheListLock = 0;
  CcExternalCacheList = (int)&CcExternalCacheList;
  dword_6327FC = (int)&CcExternalCacheList;
  CcInitializeVacbs(v11);
  v24[0] = 24;
  v24[1] = 0;
  v24[2] = 0;
  v24[3] = 0;
  v24[4] = 0;
  v24[5] = 0;
  if ( PsCreateSystemThread((int)&v23, 0x1FFFFF, (int)v24) < 0 )
    return 0;
  ZwClose();
  if ( !CcInitializeAsyncRead() )
    return 0;
  memset(CcTestControlData, 0, sizeof(CcTestControlData));
  if ( PoRegisterCoalescingCallback((int)CcCoalescingCallBack, 1, CcCoalescingRegistration, 0) < 0 )
    KeBugCheckEx(52, 939, -1073740768, 0, 0);
  result = 1;
  CcInitializationComplete = 1;
  return result;
}
