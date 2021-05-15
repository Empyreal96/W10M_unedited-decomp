// IoInitSystemPreDrivers 
 
int __fastcall IoInitSystemPreDrivers(int a1)
{
  int v2; // r0
  int v3; // r2
  int v4; // r0
  unsigned int v5; // r2
  unsigned int i; // r4
  int v7; // r2
  int *v9; // r4
  bool v10; // r3
  int v11; // r0
  int v12; // r2
  int v13; // r3
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r4
  unsigned int v18; // r1
  int v19; // r2
  int v20; // r3
  int v21; // r0
  int v22; // r0
  int v23; // r0
  int v24; // r4
  int v25; // r0
  __int64 v26; // r0
  int v27; // [sp+10h] [bp-80h] BYREF
  _DWORD *v28; // [sp+14h] [bp-7Ch] BYREF
  unsigned int v29; // [sp+18h] [bp-78h] BYREF
  int v30; // [sp+20h] [bp-70h] BYREF
  int v31; // [sp+24h] [bp-6Ch]
  _DWORD *v32; // [sp+28h] [bp-68h]
  int v33; // [sp+2Ch] [bp-64h]
  int v34; // [sp+30h] [bp-60h]
  int v35; // [sp+34h] [bp-5Ch]
  _DWORD v36[2]; // [sp+38h] [bp-58h] BYREF
  __int16 v37[2]; // [sp+40h] [bp-50h] BYREF
  int *v38; // [sp+44h] [bp-4Ch]
  __int16 v39[6]; // [sp+50h] [bp-40h] BYREF
  int v40; // [sp+5Ch] [bp-34h]
  int v41; // [sp+60h] [bp-30h]
  int v42; // [sp+64h] [bp-2Ch]
  int v43; // [sp+68h] [bp-28h]
  int vars4; // [sp+94h] [bp+4h]

  v38 = IoInitSystem_deviceNameBuffer;
  v37[1] = 256;
  v37[0] = 0;
  ExInitializeResourceLite((int)&IopDriverLoadResource);
  ExInitializeResourceLite((int)&IopDatabaseResource);
  ExInitializeResourceLite((int)&IopSecurityResource);
  ExInitializeResourceLite((int)&IopCrashDumpLock);
  v2 = ExInitializeResourceLite((int)&IopLiveDumpLock);
  IopDiskFileSystemQueueHead = (int)&IopDiskFileSystemQueueHead;
  dword_63187C = (int)&IopDiskFileSystemQueueHead;
  IopCdRomFileSystemQueueHead = (int)&IopCdRomFileSystemQueueHead;
  dword_631884 = (int)&IopCdRomFileSystemQueueHead;
  IopTapeFileSystemQueueHead = (int)&IopTapeFileSystemQueueHead;
  dword_63188C = (int)&IopTapeFileSystemQueueHead;
  IopNetworkFileSystemQueueHead = (int)&IopNetworkFileSystemQueueHead;
  dword_631894 = (int)&IopNetworkFileSystemQueueHead;
  IopBootDriverReinitializeQueueHead[0] = IopBootDriverReinitializeQueueHead;
  IopBootDriverReinitializeQueueHead[1] = IopBootDriverReinitializeQueueHead;
  IopDriverReinitializeQueueHead[0] = IopDriverReinitializeQueueHead;
  IopDriverReinitializeQueueHead[1] = IopDriverReinitializeQueueHead;
  IopNotifyShutdownQueueHead = (int)&IopNotifyShutdownQueueHead;
  *(_DWORD *)algn_6318AC = &IopNotifyShutdownQueueHead;
  IopNotifyLastChanceShutdownQueueHead = (int)&IopNotifyLastChanceShutdownQueueHead;
  *(_DWORD *)algn_6318B4 = &IopNotifyLastChanceShutdownQueueHead;
  IopFsNotifyChangeQueueHead = (int)&IopFsNotifyChangeQueueHead;
  dword_6318BC = (int)&IopFsNotifyChangeQueueHead;
  IopPerfIoTrackingListHead = (int)&IopPerfIoTrackingListHead;
  dword_6318C4 = (int)&IopPerfIoTrackingListHead;
  IopPerfIoTrackingLock = 0;
  IoStatisticsLock = 0;
  IopFunctionPointerLock = 0;
  IopSetIoRoutines(v2);
  v3 = 0;
  IopUniqueDeviceObjectNumber = 0;
  IopIrpStackProfilerFlags = 0;
  if ( !IopLargeIrpStackLocations )
  {
    v3 = 1;
    IopIrpStackProfilerFlags = 1;
    IopLargeIrpStackLocations = 14;
  }
  if ( !IopMediumIrpStackLocations )
  {
    IopMediumIrpStackLocations = 4;
    IopIrpStackProfilerFlags = v3 | 2;
  }
  if ( (unsigned int)IopIrpCompletionTimeoutInSeconds > 0x12C || (unsigned int)IopIrpCompletionTimeoutInSeconds < 2 )
    IopIrpCompletionTimeoutInSeconds = 300;
  IopQueryProcessorInitValues((int)v39);
  ExInitializeSystemLookasideList(
    (int)&IopCompletionLookasideList,
    512,
    28,
    544236361,
    v39[3],
    (int)&ExSystemLookasideListHead);
  ExInitializeSystemLookasideList(
    (int)&IopLargeIrpLookasideList,
    512,
    v42,
    1819308617,
    v39[2],
    (int)&ExSystemLookasideListHead);
  ExInitializeSystemLookasideList(
    (int)&IopMediumIrpLookasideList,
    512,
    v41,
    1836085833,
    v39[1],
    (int)&ExSystemLookasideListHead);
  ExInitializeSystemLookasideList(
    (int)&IopSmallIrpLookasideList,
    512,
    v40,
    1936749129,
    v39[0],
    (int)&ExSystemLookasideListHead);
  ExInitializeSystemLookasideList(
    (int)&IopMdlLookasideList,
    512,
    v43,
    543974477,
    v39[4],
    (int)&ExSystemLookasideListHead);
  ExInitializeNPagedLookasideList((int)&IopSafeCompletionLookasideList, 0, 0, 512);
  FsRtlInitExtraCreateParameterLookasideList((int)&IopSymlinkInfoLookasideList, 0, 274, 1767075657);
  v4 = ExInitializeNPagedLookasideList((int)&IopOplockFoExtLookasideList, 0, 0, 512);
  v5 = 0;
  v29 = 0;
  for ( i = KeNumberProcessors_0; v5 < i; v29 = v5 )
  {
    v4 = IoInitializeProcessor((int)*(&KiProcessorBlock + v5), (int)v39);
    v5 = v29 + 1;
  }
  IopErrorLogLock = 0;
  IopErrorLogListHead = (int)&IopErrorLogListHead;
  dword_6318DC = (int)&IopErrorLogListHead;
  if ( !IopInitializeReserveIrps(v4) )
  {
    v7 = 1;
LABEL_12:
    IopInitFailCode = v7;
    return 0;
  }
  if ( (IopIrpStackProfilerFlags & 3) != 0 )
  {
    IopIrpStackProfilerMinSizeThreshold = 400;
    IopIrpStackProfilerSampleSize = 2000;
    KeInitializeDpc((int)&IopIrpStackProfilerDpc, (int)IopIrpStackProfilerDpcRoutine, 0);
    IopIrpStackProfilerFlags |= 4u;
  }
  v9 = IopRevocationExtension;
  memset(IopRevocationExtension, 0, 36);
  *v9 = 4;
  v30 = 24;
  v31 = 0;
  v33 = 576;
  v32 = &CmRegistryMachineSystemCurrentControlSetServicesEventLog;
  v34 = 0;
  v35 = 0;
  if ( ZwOpenKey() < 0 )
  {
    IopErrorLogDisabledThisBoot = 1;
  }
  else
  {
    RtlInitUnicodeString((unsigned int)v36, L"Start");
    v10 = NtQueryValueKey(v27, v36, 2, (int)&IoInitSystem_valueBuffer, 32, (unsigned int)&v29) < 0
       || dword_98329C != 4
       || dword_9832A4 == 4;
    IopErrorLogDisabledThisBoot = v10;
    ObCloseHandle(v27);
  }
  IopTimerLock = 0;
  IopTimerQueueHead = (int)&IopTimerQueueHead;
  *(_DWORD *)algn_6319A4 = &IopTimerQueueHead;
  KeInitializeDpc((int)&IopTimerDpc, (int)IopTimerDispatch, (int)&IopTimerCount);
  KeInitializeTimerEx(IopTimer, 1);
  IopDeadIrps = (int)&IopDeadIrps;
  dword_631A14 = (int)&IopDeadIrps;
  dword_631A28 = (int)IopHardErrorThread;
  dword_631A2C = 0;
  IopHardError = 0;
  dword_631A34 = (int)&dword_631A30;
  dword_631A30 = (int)&dword_631A30;
  dword_631A38 = 0;
  KeInitializeSemaphore((int)algn_631A3C, 0, 0x7FFFFFFF);
  byte_631A50 = 0;
  dword_631A68 = (int)IopKeepAliveWorker;
  dword_631A6C = 0;
  IopKeepAliveTracker = 0;
  dword_631A74 = (int)&dword_631A70;
  dword_631A70 = (int)&dword_631A70;
  dword_631A78[0] = 0;
  byte_631A90 = 0;
  IopErrorLogSessionPending = 1;
  RtlInitUnicodeString((unsigned int)v36, L"\\Security\\TRKWKS_EVENT");
  v30 = 24;
  v31 = 0;
  v33 = 528;
  v32 = v36;
  v34 = 0;
  v35 = 0;
  if ( NtCreateEvent((unsigned int)&v27, 2031619, (int)&v30, 0, 0) < 0 )
  {
    HeadlessKernelAddLogEntry();
    return 0;
  }
  ObReferenceObjectByHandle(v27, 0, ExEventObjectType, 0, (int)&v28, 0);
  IopLinkTrackingServiceEvent = v28;
  KeInitializeEvent((int)&IopMountCompletionEvent, 0, 0);
  KeInitializeEvent((int)&algn_631AC4[12], 0, 0);
  KeInitializeEvent((int)&IopLinkTrackingPortObject, 1, 1);
  v11 = ObCloseHandle(v27);
  if ( !IopCreateRootDirectories(v11) )
  {
    HeadlessKernelAddLogEntry();
    v7 = 3;
    goto LABEL_12;
  }
  if ( IopInitializeSessionNotifications() < 0 )
  {
    v7 = 15;
    goto LABEL_12;
  }
  if ( IopInitializePlugPlayServices(a1, 0) < 0 )
  {
    HeadlessKernelAddLogEntry();
    v7 = 4;
    goto LABEL_12;
  }
  v14 = KseInitialize(a1, 0, v12, v13);
  v15 = PoInitDriverServices(v14);
  v16 = off_617B80(v15);
  PnpMarkHalDeviceNode(v16);
  if ( !WMIInitialize(0, a1) )
    return 0;
  EtwInitialize(0);
  if ( EtwRegister((int)IoTraceProvider, (int)IopEtwEnableCallback, 0) < 0 )
  {
    v7 = 16;
    goto LABEL_12;
  }
  if ( MmIsThisAnNtAsSystem() && EtwRegister((int)IoMgrProvider, 0, 0) < 0 )
  {
    v7 = 11;
    goto LABEL_12;
  }
  SeAuditBootConfiguration(*(_DWORD *)(*(_DWORD *)(a1 + 132) + 2292));
  BootApplicationPersistentDataProcess(1);
  BapdRecordFirmwareBootStats();
  KdInitialize_0();
  if ( !IopErrorLogDisabledThisBoot )
  {
    v17 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&IopErrorLogLock);
    }
    else
    {
      do
        v18 = __ldrex((unsigned int *)&IopErrorLogLock);
      while ( __strex(1u, (unsigned int *)&IopErrorLogLock) );
      __dmb(0xBu);
      if ( v18 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&IopErrorLogLock);
    }
    if ( (int *)IopErrorLogListHead == &IopErrorLogListHead )
    {
      IopErrorLogSessionPending = 0;
    }
    else
    {
      dword_630E28 = (int)IopErrorLogThread;
      dword_630E2C = 0;
      IopErrorLogWorkItem = 0;
      ExQueueWorkItem(&IopErrorLogWorkItem, 1);
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&IopErrorLogLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      IopErrorLogLock = 0;
    }
    KfLowerIrql(v17);
  }
  IoEtwHandle = 0;
  unk_630E14 = 0;
  WheaInitialize(a1, 0);
  if ( IopStoreArcInformation(a1) < 0 )
    return 0;
  if ( IopInitializePlugPlayServices(a1, 1) < 0 )
  {
    HeadlessKernelAddLogEntry();
    v7 = 5;
    goto LABEL_12;
  }
  RtlInitializeGenericTableAvl(
    (int)&IoStatusBlockRangeTable,
    (unsigned int)IopCompareIosbRanges,
    (unsigned int)IopAllocateGenericTableEntry,
    (int)IopFreeGenericTableEntry,
    0);
  IoStatusBlockRangeTableLock = 1;
  dword_631B64 = 0;
  unk_631B68 = 0;
  byte_631B6C = 1;
  byte_631B6D = 0;
  byte_631B6E = 4;
  dword_631B70 = 0;
  dword_631B78 = (int)&dword_631B74;
  dword_631B74 = (int)&dword_631B74;
  KitInitialize(a1);
  KseInitialize(a1, 1, v19, v20);
  v21 = PnpEtwHandle;
  if ( PnpEtwHandle )
    v21 = EtwWriteStartScenario(
            PnpEtwHandle,
            SHIDWORD(PnpEtwHandle),
            (int)KMPnPEvt_DriverInitPhase_Start,
            (int)&PnpDriverInitPhaseActivityId);
  v22 = IopInitializeActiveConnectList(v21);
  if ( IopInitializePassiveInterruptServices(v22) < 0 )
    return 0;
  IopInitDumpCapsuleSupport();
  if ( !IopInitializeBootDrivers(a1) )
  {
    HeadlessKernelAddLogEntry();
    v7 = 6;
    goto LABEL_12;
  }
  if ( !PoInitSystem(2, a1) )
    KeBugCheck(160);
  SmInitSystem(1);
  EtwInitialize(1u);
  IopInitializeSystemVariableService();
  IoInitializeLiveDump();
  v23 = IopInitCrashDumpDuringSysInit(a1);
  if ( v23 >= 0 )
    v23 = IopRemoveDumpCapsuleSupport();
  PpLastGoodDoBootProcessing(v23);
  v24 = NtGlobalFlag;
  NtGlobalFlag |= 0x40000u;
  v25 = PsLocateSystemDlls();
  NtGlobalFlag = v24;
  if ( v25 < 0 )
  {
    HeadlessKernelAddLogEntry();
    v7 = 7;
    goto LABEL_12;
  }
  PfSnBeginBootPhase(0);
  if ( !IopReassignSystemRoot(a1, v37) )
  {
    HeadlessKernelAddLogEntry();
    v7 = 9;
    goto LABEL_12;
  }
  if ( !IopProtectSystemPartition(a1) )
  {
    HeadlessKernelAddLogEntry();
    v7 = 10;
    goto LABEL_12;
  }
  if ( NtVhdBootFile )
  {
    v30 = 24;
    v31 = 0;
    v33 = 576;
    v32 = (_DWORD *)(PsLoadedModuleList + 36);
    v34 = 0;
    v35 = 0;
    if ( ZwOpenFile() >= 0 )
    {
      if ( ObReferenceObjectByHandle(v27, 128, 0, 0, (int)&v28, 0) >= 0 )
      {
        PpPagePathAssign(v28);
        ObfDereferenceObject((int)v28);
      }
      ZwClose();
    }
  }
  if ( !WMIInitialize(1, 0) )
    return 0;
  v26 = WheaInitialize(a1, 1);
  IopInitializeIoQos(v26, SHIDWORD(v26));
  return 1;
}
