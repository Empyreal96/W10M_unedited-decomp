// NtSetSystemPowerState 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall NtSetSystemPowerState(int a1, int a2, int a3)
{
  unsigned int v6; // r3
  int v7; // r6
  int v8; // r0
  int v9; // r4
  int v10; // r3
  int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r10
  int i; // r1
  char v19; // r3
  int v20; // r4
  int v21; // r7
  unsigned int v22; // r2
  int v23; // r0
  int v24; // r2
  int v25; // r2
  unsigned int v26; // r1
  unsigned int v27; // r0
  int v28; // r1
  int v29; // r0
  int v30; // r1
  int v31; // r4
  int v32; // r0
  int v33; // r7
  bool v34; // zf
  unsigned int v35; // r10
  int v36; // r0
  __int64 v37; // r0
  int v38; // r2
  int v39; // r0
  int v40; // r1
  __int64 v41; // r0
  unsigned int v42; // r6
  unsigned int v43; // r7
  unsigned int v44; // r2
  int v45; // r4
  int v46; // lr
  unsigned int v47; // r9 OVERLAPPED
  unsigned int v48; // r10 OVERLAPPED
  BOOL v49; // r2
  int v50; // r0
  int v51; // r3
  BOOL v52; // r3
  int v53; // r0
  int v54; // r1
  int v55; // r2
  int v56; // r3
  int v57; // r0
  int v58; // r1
  int v59; // r4
  int v60; // r0
  int v61; // r3
  int v62; // r10
  int v63; // r2
  __int64 v64; // r0
  int v65; // r0
  int v66; // r0
  int v67; // r4
  int v68; // r0
  int v69; // r7
  int v70; // r0
  char *v71; // r2
  int v72; // r3
  int v73; // r2
  char v75[4]; // [sp+10h] [bp-118h] BYREF
  int v76; // [sp+14h] [bp-114h]
  int v77; // [sp+18h] [bp-110h]
  int v78; // [sp+1Ch] [bp-10Ch]
  char v79[4]; // [sp+20h] [bp-108h] BYREF
  int v80; // [sp+24h] [bp-104h] BYREF
  int v81; // [sp+28h] [bp-100h]
  int v82; // [sp+2Ch] [bp-FCh]
  int v83; // [sp+30h] [bp-F8h]
  int v84; // [sp+34h] [bp-F4h]
  int v85; // [sp+38h] [bp-F0h]
  int v86; // [sp+3Ch] [bp-ECh] BYREF
  int v87; // [sp+40h] [bp-E8h]
  __int64 v88; // [sp+48h] [bp-E0h] BYREF
  int v89; // [sp+50h] [bp-D8h]
  int v90[2]; // [sp+58h] [bp-D0h] BYREF
  int v91; // [sp+60h] [bp-C8h] BYREF
  int v92[2]; // [sp+68h] [bp-C0h] BYREF
  int v93[2]; // [sp+70h] [bp-B8h] BYREF
  int v94[2]; // [sp+78h] [bp-B0h] BYREF
  int v95; // [sp+80h] [bp-A8h]
  int v96; // [sp+88h] [bp-A0h] BYREF
  int v97; // [sp+8Ch] [bp-9Ch]
  int v98; // [sp+90h] [bp-98h]
  int v99; // [sp+94h] [bp-94h]
  int v100[4]; // [sp+98h] [bp-90h] BYREF
  _DWORD v101[2]; // [sp+A8h] [bp-80h] BYREF
  char v102[16]; // [sp+B0h] [bp-78h] BYREF
  char v103[16]; // [sp+C0h] [bp-68h] BYREF
  char v104[20]; // [sp+D0h] [bp-58h] BYREF
  int v105; // [sp+E4h] [bp-44h]
  char v106[64]; // [sp+E8h] [bp-40h] BYREF

  v101[0] = 0;
  v101[1] = 0;
  v94[0] = 0;
  v87 = 0;
  v88 = 0i64;
  v90[0] = 1;
  v83 = 0;
  v84 = 0;
  v80 = 0;
  v92[0] = 0;
  v93[0] = 0;
  v82 = 0;
  v77 = a3;
  v95 = a2;
  if ( (unsigned int)(a2 - 1) > 5 || (unsigned int)(a1 - 1) > 6 || (a3 & 0xFFFFFF0) != 0 )
  {
    if ( (PoDebug & 2) != 0 )
      DbgPrint("NtSetSystemPowerState: Bad parameters!\n");
    if ( (PoDebug & 2) != 0 )
      DbgPrint("                       SystemAction: 0x%x\n", a1);
    if ( (PoDebug & 2) != 0 )
      DbgPrint("                       LightestSystemState: 0x%x\n", a2);
    if ( (PoDebug & 2) != 0 )
      DbgPrint("                       Flags: 0x%x\n", a3);
    return -1073741811;
  }
  if ( a1 < 4 && dword_61EC74 >= 11 )
  {
    if ( (PoDebug & 2) != 0 )
      DbgPrint("NtSetSystemPowerState: Bad parameters!\n");
    if ( (PoDebug & 2) != 0 )
      DbgPrint("                       PopAction.DeviceType - %d\n", dword_61EC74);
    return -1073741811;
  }
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(v6 + 346) )
  {
    if ( SeSinglePrivilegeCheck(SeShutdownPrivilege, dword_922B8C, *(char *)(v6 + 346)) )
      v7 = ZwSetSystemPowerState();
    else
      v7 = -1073741727;
    return v7;
  }
  if ( a1 == 4 )
    PopReadShutdownPolicy();
  v8 = PsGetCurrentServerSilo();
  v9 = v8;
  if ( v8 )
  {
    if ( a1 < 4 )
      v7 = -1073741637;
    else
      v7 = PsTerminateServerSilo(v8, -1073741077);
    PspDereferenceSiloObject(v9);
    return v7;
  }
  if ( a1 >= 4 )
    v8 = PspShutdownServerSilos();
  v100[1] = a3;
  v100[2] = 0;
  v96 = 0;
  v97 = 0;
  v98 = 0;
  v99 = 0;
  v10 = dword_61EC74;
  v100[0] = a1;
  if ( dword_61EC74 >= 11 )
    v10 = 5;
  v96 = v10;
  v97 = 128;
  PopAcquireTransitionLock(v8);
  MmLockPagableSectionByHandle(ExPageLockHandle);
  PopRunMaximumIrpWorkers();
  dword_61E408 = (int)PopUnlockAfterSleepWorker;
  dword_61E40C = 0;
  PopUnlockAfterSleepWorkItem = 0;
  v11 = CmSetLazyFlushState(0);
  PopNotifyCallbacksPreSleep(v11);
  v12 = ExSwapinWorkerThreads(0);
  v7 = PoInitializeBroadcast(v12);
  if ( v7 < 0 )
  {
LABEL_31:
    ExQueueWorkItem(&PopUnlockAfterSleepWorkItem, 1);
    return v7;
  }
  PopCheckPowerSourceAfterRtcWakeCancel();
  PopAcquirePolicyLock();
  v76 = 1;
  v13 = PopFilterCapabilities(&PopCapabilities, &unk_61ED10);
  if ( byte_61EC61 )
  {
    if ( byte_61EC61 != 2 )
    {
      if ( (PoDebug & 8) != 0 )
        DbgPrint("NtSetSystemPowerState: already committed\n");
      v14 = PopReleasePolicyLock();
      PoClearBroadcast(v14);
      v7 = -1073741791;
      goto LABEL_31;
    }
  }
  else
  {
    PopResetActionDefaults(v13);
  }
  byte_61EC61 = 3;
  dword_61EC94 = dword_61E84C;
  PopExecutePowerAction(&v96, 0, v100, a2, 1);
  v15 = PopIgnoreBatteryStatusChange();
  PopCheckResiliencyScenarios(v15);
  PopEnforceResiliencyScenarios((int)v101);
  v16 = PopExecuteOnTargetProcessors((int)&KeActiveProcessors, (int)PpmStopIllegalProcessorThrottleLogging, 0, 0);
  if ( a1 == 6 )
    dword_61EC64 = 6;
  if ( (a1 == 4 || a1 == 5 || a1 == 6) && PopHiberInfo && dword_61EEA4 && MmZeroPageFileAtShutdown(v16) )
    PopZeroHiberFile(PopHiberInfo, dword_61EEA4);
  v81 = 0;
  v75[0] = 0;
  v17 = 0;
  v78 = 0;
  v91 = 0;
  if ( a1 == 2 || a1 == 3 )
    PoPowerDownActionInProgress = 1;
  v7 = -1073741536;
  v85 = 0x10000000;
  for ( i = 1; ; i = v76 )
  {
    while ( 1 )
    {
      if ( !i )
      {
        PopAcquirePolicyLock();
        v76 = 1;
      }
      if ( !dword_61EC64 )
        goto LABEL_168;
      v19 = PopAction[0];
      PopAction[0] = 0;
      if ( v7 == -1073741536 )
      {
        if ( (v19 & 2) != 0 && dword_61EC6C >= 0 && (dword_61EC6C & 3) != 0 )
        {
          PopGetPolicyWorker(2);
          goto LABEL_169;
        }
        PopActionRetrieveInitialState(&dword_61EC68, &v91, &dword_61EC80, v75);
        if ( dword_61EC64 == 4 || dword_61EC64 == 5 || dword_61EC64 == 6 )
        {
          byte_61EC62 = 1;
          dword_61EC6C = v77;
        }
        v17 = v91;
        v7 = 0;
        v81 = (unsigned __int8)v75[0];
        v78 = v91;
      }
      if ( v7 < 0 )
        goto LABEL_169;
      PopReleasePolicyLock();
      v76 = 0;
      v89 = 1;
      v82 = 0;
      v20 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
      v21 = KfRaiseIrql(1);
      do
        v22 = __ldrex((unsigned __int8 *)&PopSettingLock);
      while ( __strex(v22 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
      __dmb(0xBu);
      if ( (v22 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&PopSettingLock, v20);
      if ( v20 )
        *(_BYTE *)(v20 + 14) |= 1u;
      dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_61F33C = v21;
      v23 = PopFindPowerSettingConfiguration(&GUID_ALLOW_RTC_WAKE, -1);
      if ( v23 )
      {
        v24 = *(_DWORD *)(v23 + 48);
        if ( v24 && *(_DWORD *)(v24 + 4) >= 4u )
          v89 = *(_DWORD *)(v24 + 12);
        v25 = *(_DWORD *)(v23 + 52);
        if ( v25 && *(_DWORD *)(v25 + 4) >= 4u )
          v82 = *(_DWORD *)(v25 + 12);
      }
      dword_61F324 = 0;
      __dmb(0xBu);
      do
        v26 = __ldrex((unsigned int *)&PopSettingLock);
      while ( !v26 && __strex(1u, (unsigned int *)&PopSettingLock) );
      if ( v26 )
        ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v26);
      KfLowerIrql((unsigned __int8)v21);
      v27 = KeAbPostRelease((unsigned int)&PopSettingLock);
      if ( (dword_61EC6C & 0x40000000) != 0 )
      {
        v89 = 0;
        v82 = 0;
      }
      PopInitializePowerPolicySimulate(v27);
      dword_61EC84 = dword_61EC80;
      v28 = (dword_61EC6C & v85) != 0 ? 2 : 0;
      v29 = PopAdvanceSystemPowerState(&dword_61EC84, v28, dword_61EC68, v17);
      v30 = v77 & 8;
      if ( (v77 & 8) != 0 )
      {
        v31 = 0;
        byte_61EED0 = 1;
        dword_61EC88 = 5;
        v32 = dword_61EC80;
        v33 = 6;
      }
      else
      {
        v34 = PopFastS4Check(v29, 0) == 0;
        v32 = dword_61EC80;
        v33 = dword_61EC80;
        if ( !v34 )
        {
          dword_61EC88 = 5;
          v35 = 6;
          v31 = 1;
          goto LABEL_90;
        }
        dword_61EC88 = dword_61EC80;
        v31 = 0;
      }
      v35 = PopPowerStateHandlerLookup[v32];
      if ( v35 > 6 )
        goto LABEL_100;
LABEL_90:
      if ( !PopPowerStateHandlers[4 * v35 + 2] )
        goto LABEL_100;
      if ( v30 )
      {
        v32 = 6;
      }
      else if ( byte_61EC62 )
      {
        goto LABEL_95;
      }
      PopSetSleepMarker(v32);
LABEL_95:
      PopAcquirePolicyLock();
      if ( (PopAction[0] & 6) == 0 )
        break;
      i = 1;
      v76 = 1;
      v7 = -1073741536;
LABEL_47:
      v17 = v78;
    }
    PopReleasePolicyLock();
    byte_61EC7C = 3;
    PopDiagTraceKernelQueriesAllowed(v81);
    if ( !v81 )
      break;
    v36 = PopSetDevicesSystemState();
    v7 = v36;
    if ( v36 >= 0 )
      goto LABEL_104;
    if ( v36 == -1073741536 )
      break;
LABEL_100:
    v17 = v78;
    if ( !PopFindNextSystemPowerState(v78, v31, v75) )
      goto LABEL_169;
    v7 = 0;
    v81 = (unsigned __int8)v75[0];
LABEL_102:
    ;
  }
  if ( v7 < 0 )
    goto LABEL_46;
LABEL_104:
  LODWORD(v37) = PopAllocateHiberContext();
  v7 = v37;
  v38 = -1073741536;
  if ( (int)v37 < 0 )
  {
LABEL_46:
    i = v76;
    goto LABEL_47;
  }
  if ( !byte_61EC62 )
    v37 = PopDiagTracePreSleepNotification(v33, dword_61EC88, dword_61EC74, dword_61EC78);
  PopEsEnterSleepShutdown(v37, HIDWORD(v37), v38);
  v39 = PopForceCompleteSleepStudySession(dword_61EC74);
  PopThermalSxEntry(v39, v40);
  if ( !v94[0] )
  {
    if ( byte_61EC62 && RtlLockBootStatusData(&v86) >= 0 )
    {
      v79[0] = 1;
      RtlGetSetBootStatusData(v86, 0, 5, v79, 1, 0);
      RtlGetSetBootStatusData(v86, 0, 11, -27964, 4, 0);
      RtlUnlockBootStatusData(v86);
    }
    v94[0] = 1;
  }
  PopNotifyTelemetryOsState(dword_61EC64, dword_61EC80, dword_61EC88, v77, 1);
  PopFlushVolumes(dword_61EC80);
  if ( dword_61EC88 < dword_61EC80 )
    dword_61EC88 = dword_61EC80;
  byte_61EC7C = 2;
  if ( byte_61EC62 )
  {
    PopFxPrepareDevicesForShutdown();
    IoFreePoDeviceNotifyList((_BYTE *)(dword_61EC94 + 28));
    if ( dword_61EC74 == 2 )
    {
      __dmb(0xBu);
      PopCriticalShutdownInProgress = 1;
    }
    v63 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    if ( v63 != PsInitialSystemProcess )
    {
      dword_61E2D8 = (int)PopGracefulShutdown;
      dword_61E2DC = 0;
      PopShutdownWorkItem = 0;
      ExQueueWorkItem(&PopShutdownWorkItem, 0);
      KeSuspendThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      return -1073741077;
    }
    PopGracefulShutdown();
LABEL_168:
    v7 = 0;
LABEL_169:
    v62 = v77;
    v59 = 0;
    goto LABEL_170;
  }
  v7 = PopInitSystemSleeperThread(v35, v102);
  if ( v7 < 0 )
  {
    v17 = v78;
    goto LABEL_102;
  }
  if ( !byte_61ED00 )
  {
    ExWakeTimersPause();
    byte_61ED00 = 1;
  }
  LODWORD(v41) = KeQueryInterruptTime();
  v42 = HIDWORD(v41);
  v43 = v41;
  v44 = *(_DWORD *)(PopPolicy + 88);
  if ( v44 && dword_61EC80 != 5 && byte_61EA48 && byte_61EA56 == 2 && (dword_61EC6C & 0x40000000) == 0 && byte_61ED16 )
  {
    v45 = v44 * (_DWORD)dword_989680 + v41;
    v84 = (v44 * (unsigned __int64)(unsigned int)dword_989680 + v41) >> 32;
    v92[0] = v45;
  }
  else
  {
    v45 = 0;
  }
  memset(&qword_61ECB8, 0, 72);
  dword_61ECB0 = 3;
  if ( !byte_61EED0 )
  {
    v46 = v84;
    if ( v45 | v84 )
    {
      LODWORD(qword_61ECB8) = v45;
      HIDWORD(qword_61ECB8) = v84;
      LODWORD(qword_61ECC0) = v45;
      HIDWORD(qword_61ECC0) = v84;
      LODWORD(qword_61ECD0) = v45;
      HIDWORD(qword_61ECD0) = v84;
      LODWORD(qword_61ECD8) = v45;
      HIDWORD(qword_61ECD8) = v84;
      dword_61ECC8 = -1;
      dword_61ECE0 = -1;
    }
    *(_QWORD *)&v47 = *(_QWORD *)&dword_61ED08;
    if ( v89 )
    {
      v49 = v89 == 2 && (PopSimulate & v85) == 0;
      v50 = ExGetNextWakeTime(
              dword_61ED08 + 1,
              (unsigned __int64)(*(_QWORD *)&dword_61ED08 + 1i64) >> 32,
              v92[0],
              v84,
              v49,
              &v88,
              &v80);
      v46 = v84;
      if ( v50 )
      {
        qword_61ECB8 = v88;
        qword_61ECC0 = v88;
        v51 = v80;
        dword_61ECC8 = v80;
      }
      else
      {
        v51 = v80;
      }
      v83 = v51;
    }
    if ( v82 )
    {
      v52 = v82 == 2 && (PopSimulate & v85) == 0;
      if ( ExGetNextWakeTime(v47 + 1, (__PAIR64__(v48, v47) + 1) >> 32, v92[0], v46, v52, &v88, &v80) )
      {
        qword_61ECD0 = v88;
        qword_61ECD8 = v88;
        dword_61ECE0 = v80;
      }
      v83 = v80;
    }
  }
  if ( qword_61ECB8 && qword_61ECB8 < __PAIR64__(v42, v43) + 300000000 )
    qword_61ECC0 = qword_61ECC0 - qword_61ECB8 + __PAIR64__(v42, v43) + 300000000;
  if ( qword_61ECD0 && qword_61ECD0 < __PAIR64__(v42, v43) + 300000000 )
    qword_61ECD8 = qword_61ECD8 - qword_61ECD0 + __PAIR64__(v42, v43) + 300000000;
  KeQueryPerformanceCounter(v90, 0);
  dword_61EF50 = v90[0];
  dword_61EF54 = v90[1];
  ExUpdateSystemTimeFromCmos(1, 1);
  off_617988(qword_61ECC0, HIDWORD(qword_61ECC0), qword_61ECD8, HIDWORD(qword_61ECD8));
  v53 = PopSetDevicesSystemState();
  PopNewWakeInfo(v53, v54, v55, v56);
  v57 = KeQueryInterruptTime();
  v93[0] = v58;
  v59 = v57;
  v90[0] = dword_61EC0C;
  KeSetEvent((int)v103, 0, 1);
  KeWaitForSingleObject((unsigned int)v104, 0, 0, 0, 0);
  dword_61EF1C = 0;
  v7 = v105;
  v60 = dword_61EC80;
  if ( PoResumeFromHibernate )
  {
    v61 = dword_61EC88;
    dword_61EC8C = dword_61EC88;
  }
  else
  {
    v61 = dword_61EC80;
    dword_61EC8C = dword_61EC80;
  }
  v62 = v77;
  v87 = v61;
  if ( (v77 & 8) != 0 )
    v60 = 6;
  PopDiagTracePostSleepNotification(v60);
  if ( v7 < 0 && dword_61EC80 == 5 )
  {
    StringCchPrintfW(PopHibernationErrorSubstitutionString, 0x80u, (int)L"0x%x", v7);
    RtlInitUnicodeString((unsigned int)v92, PopHibernationErrorSubstitutionString);
    IoRaiseInformationalHardError(-1073740783, (unsigned __int16 *)v92, 0);
    PopDiagTraceHibernateErrorStatus(v7);
  }
LABEL_170:
  if ( byte_61EED0 )
  {
    KeQueryPerformanceCounter(v94, 0);
    dword_61F110 = v94[0];
    dword_61F114 = v94[1];
    dword_61EEB8 = PopQpcTimeInMs(&dword_61F108, &dword_61F110);
  }
  if ( v7 >= 0 )
  {
    unk_61ECA8 = v59;
    unk_61ECAC = v93[0];
    ExUpdateSystemTimeFromCmos(1, 1);
    KeQueryPerformanceCounter(v93, 0);
    dword_61EF58 = v93[0];
    dword_61EF5C = v93[1];
    PfPowerActionNotify(2, 0, 0);
    LODWORD(v64) = KeQueryInterruptTime();
    unk_61ECA0 = v64;
  }
  byte_61EC7D = 1;
  PoPowerDownActionInProgress = 0;
  if ( dword_61EC94 )
  {
    PfPowerActionNotify(3, 0, 0);
    PopSetDevicesSystemState();
    PfPowerActionNotify(3, 1, 0);
  }
  if ( v83 )
    ExDeleteWakeTimerInfo(v83);
  off_617988(0, 0, 0, 0);
  v65 = PopNotifyTelemetryOsState(dword_61EC64, dword_61EC80, dword_61EC88, v62, 0);
  PopQueueBatteryStatusTimeout(v65);
  v66 = PopExecuteOnTargetProcessors((int)&KeActiveProcessors, (int)PpmStartIllegalProcessorThrottleLogging, 0, 0);
  v67 = v76;
  if ( v76 )
  {
    v66 = PopReleasePolicyLock();
    v76 = 0;
    v67 = 0;
  }
  v68 = PoClearBroadcast(v66);
  dword_61EC94 = 0;
  PopEsExitSleep(v68);
  PopCurrentPowerStatePrecise(v106);
  v69 = dword_61EC0C;
  dword_61E2E8 = (int)PopSpoilEstimatesOnPowerStateTransitionWorker;
  dword_61E2EC = 0;
  PopSpoilEstimatesOnPowerStateTransitionWorkItem = 0;
  ExQueueWorkItem(&PopSpoilEstimatesOnPowerStateTransitionWorkItem, 1);
  v70 = PopThermalSxExit((unsigned __int8)PoResumeFromHibernate, 1);
  if ( !v67 )
    v70 = PopAcquirePolicyLock();
  if ( v7 < 0 || (v70 = PopInitSIdle(v70), PopAction[0] = 0, (unsigned int)dword_61ECB0 >= 3) )
  {
LABEL_192:
    v73 = 1;
    goto LABEL_193;
  }
  v71 = &PopAction[24 * dword_61ECB0];
  dword_61ED08 = *((_DWORD *)v71 + 24);
  dword_61ED0C = *((_DWORD *)v71 + 25);
  PopFullWake = 0;
  if ( *((_DWORD *)v71 + 26) == -1 )
  {
    dword_61EC64 = 2;
    v72 = 5;
    goto LABEL_189;
  }
  if ( dword_61EC0C != 1 || v82 )
  {
    if ( v90[0] == v69 )
      v70 = PopCheckPowerSourceAfterRtcWakeSet();
    goto LABEL_192;
  }
  v72 = v95;
  dword_61EC64 = a1;
LABEL_189:
  dword_61EC68 = v72;
  v73 = 0;
  PopAction[0] |= 2u;
LABEL_193:
  if ( byte_61ED00 && v73 )
  {
    v70 = ExWakeTimersResume();
    byte_61ED00 = 0;
    dword_61ED08 = 0;
    dword_61ED0C = 0;
  }
  if ( PoResumeFromHibernate )
  {
    v70 = PopBootLoaderTraceProcess(v70);
    PoResumeFromHibernate = 0;
  }
  if ( v87 == 4 )
    v70 = PopDiagTraceFirmwareS3Stats(v70);
  byte_61EED0 = 0;
  PopResetActionDefaults(v70);
  byte_61EC61 = 2;
  PopReleasePolicyLock();
  if ( (PopFullWake & 2) != 0 )
    PopSetNotificationWork(1);
  ExQueueWorkItem(&PopUnlockAfterSleepWorkItem, 1);
  PopCheckForWork();
  if ( v7 >= 0 )
    PpmPerfReApplyStates();
  dword_61EC74 = 11;
  *(_QWORD *)&dword_61F0A0 = PopCaptureTimeOnProcZero();
  return v7;
}
