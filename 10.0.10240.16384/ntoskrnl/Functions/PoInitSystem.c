// PoInitSystem 
 
int __fastcall PoInitSystem(int a1, int a2, int a3)
{
  int v3; // r5
  _DWORD *v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r1
  int v10; // r0
  int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r0
  __int64 v16; // r0
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // r0
  int v21; // r0
  int v22; // r0
  _DWORD *v23; // r0
  int v24; // r0
  int v25; // r0
  int v26; // r0
  int v27; // r0
  int v28; // r0
  int v29; // r0
  int v30; // r0
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r4
  int v35; // r5
  int v36; // r1
  int v37; // r2
  int v38; // r3
  int v39; // r1
  int v40; // r0
  int v41; // r1
  int v42; // r0
  int v43; // r1
  unsigned int v44; // r2
  unsigned int v45; // r3
  __int64 v46; // r0
  __int64 v47; // [sp+10h] [bp-48h] BYREF
  char v48[8]; // [sp+18h] [bp-40h] BYREF
  char v49[20]; // [sp+20h] [bp-38h] BYREF
  int v50; // [sp+34h] [bp-24h]

  v3 = a1;
  PopOsInitPhase = a1;
  if ( !a1 )
  {
    KeQueryPerformanceCounter(v48, &v47);
    PopQpcFrequency = v47;
    PopComputeCounterShifts(v47, HIDWORD(v47), &PpmPerformanceDistributionShift, &PpmPerformanceCounterShift);
    PopComputeCounterShifts(
      (unsigned int)dword_989680,
      0,
      &PpmHvPerformanceDistributionShift,
      &PpmHvPerformanceCounterShift);
    PopIrpLock = 0;
    PopIrpList = &PopIrpList;
    dword_61EF34 = (int)&PopIrpList;
    PopInrushIrpList = (int)&PopInrushIrpList;
    dword_61E88C = (int)&PopInrushIrpList;
    ExInitializeNPagedLookasideList((int)&PopIrpDataLookaside, 0, 0, 512);
    KeInitializeMutex((int)&PopWdiTimerMutex);
    PopWdiCurrentScenario = (int)&NullGuid;
    PopWdiCurrentScenarioInstanceId = 0;
    v6 = KeInitializeTimerEx(PopWdiTimer, 0);
    PopWdiTimerTimeoutValue = -50000000;
    unk_61E11C = -1;
    PopWdiTimerDpc = 19;
    byte_61E121 = 1;
    word_61E122 = 0;
    dword_61E12C = (int)PopWdiTimerCallback;
    dword_61E130 = 0;
    dword_61E13C = 0;
    dword_61E128 = 0;
    dword_61E148 = (int)PopWdiTimerWorkerThread;
    dword_61E14C = 0;
    PopWdiTimerWorker = 0;
    PopMonitorOffDueToSleep = 0;
    v7 = PpmCheckInit(v6);
    v8 = PopInitializeIrpWorkers(v7);
    if ( v8 < 0 )
      return 0;
    PopIrpSerialLock = 0;
    dword_61E89C = 0;
    PpmIdlePolicyLock = 0;
    PpmIdleVetoLock = 0;
    byte_61E8A4 = 1;
    byte_61E8A5 = 0;
    byte_61E8A6 = 4;
    dword_61E8A8 = 1;
    dword_61E8B0 = (int)&dword_61E8AC;
    dword_61E8AC = (int)&dword_61E8AC;
    PopIrpSerialList[0] = PopIrpSerialList;
    PopIrpSerialList[1] = PopIrpSerialList;
    PopRequestedIrps[0] = PopRequestedIrps;
    PopRequestedIrps[1] = PopRequestedIrps;
    PopIrpSerialListLength = 0;
    PopInrushPending = 0;
    PopInrushIrpPointer = 0;
    PopInrushIrpReferenceCount = 0;
    PopWorkerLock = 0;
    PopTransitionLock = 1;
    byte_61E411 = 0;
    byte_61E412 = 4;
    dword_61E414 = 1;
    dword_61E41C = (int)&dword_61E418;
    dword_61E418 = (int)&dword_61E418;
    PowerStateDisableReasonListHead = (int)&PowerStateDisableReasonListHead;
    dword_61EF24 = (int)&PowerStateDisableReasonListHead;
    PopDisableSleepMutex = 1;
    dword_61F804 = 0;
    unk_61F808 = 0;
    byte_61F80C = 1;
    byte_61F80D = 0;
    byte_61F80E = 4;
    dword_61F810 = 0;
    dword_61F818 = (int)&dword_61F814;
    dword_61F814 = (int)&dword_61F814;
    PopDisableSleepList = (int)&PopDisableSleepList;
    dword_61F7F4 = (int)&PopDisableSleepList;
    v10 = PopInitShutdownList(v8, v9, &PopDisableSleepMutex);
    PopDopeGlobalLock = 0;
    PopIdleDetectList = (int)&PopIdleDetectList;
    dword_61E8E4 = (int)&PopIdleDetectList;
    if ( PopIdleScanInterval )
      return sub_966ADC(v10);
    PopWorkerSpinLock = 0;
    dword_61E8F8 = (int)PopPolicyWorkerThread;
    dword_61E8FC = 0x80000000;
    PopPolicyWorker = 0;
    PopWorkerStatus = -1;
    ExInitializeResourceLite((int)&PopPolicyLock);
    PopAwaymodeLock = 0;
    KeInitializeGuardedMutex((int)&PopVolumeLock);
    PopPowerSettingCallbackReturned = 0;
    byte_61F341 = 0;
    byte_61F342 = 4;
    dword_61F344 = 0;
    dword_61F34C = (int)&dword_61F348;
    dword_61F348 = (int)&dword_61F348;
    PopThermal = (int)&PopThermal;
    *(_DWORD *)algn_61E97C = &PopThermal;
    PopVolumeDevices = (int)&PopVolumeDevices;
    dword_61E95C = (int)&PopVolumeDevices;
    PopSwitches[0] = PopSwitches;
    PopSwitches[1] = PopSwitches;
    PopFans = (int)&PopFans;
    *(_DWORD *)algn_61E964 = &PopFans;
    IoAddTriageDumpDataBlock((int)&PopThermal, 8);
    PopActionWaiters = (int)&PopActionWaiters;
    dword_61E974 = (int)&PopActionWaiters;
    PopResetActionDefaults();
    PopPolicy = (int)&unk_61EB24;
    v11 = PopDefaultPolicy((int)&unk_61EB24);
    PopAdminPolicy = 2;
    dword_61E9A4 = 5;
    dword_61E9A8 = 0;
    dword_61E9AC = -1;
    dword_61E9B0 = 0;
    dword_61E9B4 = -1;
    PopFullWake = 1;
    PopCoolingMode = 0;
    __dmb(0xBu);
    dword_635500 = -1;
    v12 = PpmInitPolicyConfiguration(v11);
    v13 = PpmInitIdlePolicy(v12);
    v14 = PpmPerfInitialize(v13);
    v15 = PpmInitCoreParkingPolicy(v14);
    v16 = PpmInitHeteroPolicy(v15);
    v19 = PpmIdleRegisterDefaultStates(v16, SHIDWORD(v16), v17, v18);
    PopInitializePowerSettings(v19);
    v20 = PopInitilizeAcDcSettings();
    dword_61E614 = 0;
    PopPolicyDeviceLock = 0;
    PopBatteryInit(v20);
    dword_61E624 = 0;
    PopFanLock = 0;
    v21 = PopThermalInit();
    dword_61E714 = 0;
    PopCoolingExtensionLock = 0;
    PopCoolingExtensionList = (int)&PopCoolingExtensionList;
    dword_61E71C = (int)&PopCoolingExtensionList;
    dword_61EA00 = 4;
    byte_61EA04 = 0;
    dword_61EA08 = (int)PopShutdownHandler;
    v22 = PopWakeSourceInit(v21);
    PpmWmiInit(v22);
    PopUserPresentSetStatus = 0;
    v23 = KeInitializeTimerEx(PopAwayModeUserPresenceTimer, 0);
    PopUserPresentCompletedEvent = 1;
    byte_61F251 = 0;
    byte_61F252 = 4;
    dword_61F254 = 0;
    dword_61F25C = (int)&dword_61F258;
    dword_61F258 = (int)&dword_61F258;
    byte_61F7C4 = 1;
    byte_61F7C5 = 0;
    byte_61F7C6 = 4;
    dword_61F7C8 = 1;
    dword_61F7D0 = (int)&dword_61F7CC;
    dword_61F7CC = (int)&dword_61F7CC;
    a1 = PoFxInitPowerManagement(v23);
    dword_61EC2C = 0;
    dword_61EC30 = 100;
    dword_61EC34 = 0;
    dword_61EC38 = 100;
    dword_61EC3C = 0;
    dword_61EC40 = 100;
  }
  if ( v3 == 1 )
  {
    v24 = PopUmpoInitializeChannel(a1, a2, a3);
    v25 = PopUmpoInitializeMonitorChannel(v24);
    PopPdcDeviceListLock = 0;
    PopPdcDeviceList = (int)&PopPdcDeviceList;
    dword_61E4CC = (int)&PopPdcDeviceList;
    v26 = PopEsInit(v25);
    v27 = PopInitializePowerSettingCallbacks(v26);
    a1 = PopPowerRequestInit(v27);
    if ( a1 < 0 )
      return 0;
  }
  if ( v3 == 2 )
  {
    PoFxRegisterDebugger(a1, a2, a3);
    v28 = HalReportResourceUsage(1);
    v29 = PopBatteryEtwInit(v28);
    if ( PpmEventInitialize(v29) < 0 )
      return 0;
    KeRegisterProcessorChangeCallback((int)PopNewProcessorCallback, 0, 0);
    v30 = PopInitializeHeteroProcessors();
    v33 = PpmPerfArtificialDomainSetting;
    if ( PpmPerfArtificialDomainSetting != -1 )
    {
      v33 = PpmPerfArtificialDomainSetting != 0;
      PpmPerfArtificialDomainEnabled = v33;
    }
    PpmIdleRegisterDefaultStates(v30, v31, v32, v33);
    PpmCheckInitProcessors(0);
    PpmAcquireLock(&PopFxSystemLatencyLock);
    PoFxSendSystemLatencyUpdate();
    PpmReleaseLock((int *)&PopFxSystemLatencyLock);
    PopPdcCsCheckSystemVolumeDevice();
  }
  if ( v3 != 3 )
    return 1;
  if ( PopDiagInitialize() >= 0 )
  {
    PopTriggerDiagTraceAoAcCapability((unsigned __int8)PopPlatformAoAc);
    PopFanReportBootStartDevices();
    v34 = 1;
    v35 = 1;
    if ( PopSkipTickPolicy )
    {
      if ( PopSkipTickPolicy != 1
        || (v35 = 0, HalGetInterruptTargetInformation(2, 0, v49) >= 0) && (PopApicMode = v50, PopCheckSkipTick()) )
      {
        v34 = 0;
      }
    }
    PoDisableSkipTick = v34;
    if ( v34 || v35 )
      PopDiagTraceSkipTick(v34, v35);
    PpmInitIllegalThrottleLogging();
    PopCheckShutdownMarker(a2, v36, v37, v38);
    PopCheckForAbnormalReset();
    PopAcquirePolicyLock();
    PopCheckForUpgradeInProgress();
    if ( InitIsWinPEMode )
      PopLogSleepDisabled(16, 15, 0, 0);
    if ( byte_61EA54 )
      PopLogSleepDisabled(17, 7, 0, 0);
    PopInitializePowerPolicySimulate();
    if ( (PopSimulate & 1) != 0 )
    {
      byte_61EA5E = 1;
      dword_61EA60 = 100;
      dword_61EA64 = 400;
      dword_61EA68 = 10;
      dword_61EA6C = 0xFFFF;
      dword_61EA80 = 4;
      dword_61EA88 = 2;
    }
    if ( (PopSimulate & 2) != 0 )
    {
      PopCapabilities = 1;
      byte_61EA41 = 1;
      byte_61EA42 = 1;
      byte_61EA43 = 1;
      byte_61EA44 = 1;
      byte_61EA45 = 1;
      byte_61EA46 = 1;
      byte_61EA51 = 1;
      byte_61EA52 = 1;
    }
    PopResetCurrentPolicies();
    PopInitializeAdpm();
    PopInitilizeAcDcSettings();
    PopUpdateConsoleDisplayState(1, v39);
    PopReleasePolicyLock();
    PopIdleScanDpc = 19;
    byte_61F981 = 1;
    word_61F982 = 0;
    dword_61F98C = (int)PopCheckForIdleness;
    dword_61F990 = 0;
    dword_61F99C = 0;
    dword_61F988 = 0;
    KeInitializeTimerEx(PopIdleScanTimer, 0);
    v40 = PopIdleInitAoAcDozeS4Timer();
    if ( PopIdleScanInterval )
    {
      LODWORD(v46) = PopIdleScanTimer;
      HIDWORD(v46) = 1000 * PopIdleScanInterval;
      v40 = KeSetCoalescableTimer(
              v46,
              -10000000i64 * (unsigned int)PopIdleScanInterval,
              1000 * PopIdleScanInterval,
              0x3E8u,
              (int)&PopIdleScanDpc);
    }
    PopHiberLoaderScratchPages = *(_DWORD *)(*(_DWORD *)(a2 + 132) + 104);
    PopSetupHighPerfPowerRequest(v40, v41, (int)&PopHiberLoaderScratchPages, PopHiberLoaderScratchPages);
    PpmEnableWmiInterface();
    if ( (*((_DWORD *)KeLoaderBlock_0 + 36) & 8) != 0 )
      PopFirmwareProtection = 1;
    PopCoalescingInitialize();
    PopInitializeDripsWatchdog();
    PopSetupAudioEventNotification();
    v42 = PopCheckPowerSourceAfterRtcWakeInitialize();
    PopSetupFullScrenVideoNotification(v42, v43, v44, v45);
    PopThermalHandlePreviousShutdown();
    return 1;
  }
  return 0;
}
