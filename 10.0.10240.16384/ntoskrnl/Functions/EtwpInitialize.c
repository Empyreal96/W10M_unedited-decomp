// EtwpInitialize 
 
int __fastcall EtwpInitialize(int result)
{
  __int64 v1; // r0
  unsigned int i; // r4
  int v3; // r0
  int j; // r3
  unsigned int v5; // r4
  int *v6; // r6
  int v7; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r0
  _QWORD *v11; // r3
  int v12; // r0
  int v13; // r1
  int v14; // r0
  __int64 v15; // r2
  __int64 v16; // r2
  int v17; // r0
  __int64 v18; // [sp+10h] [bp-38h] BYREF
  __int64 v19; // [sp+18h] [bp-30h] BYREF
  int v20[10]; // [sp+20h] [bp-28h] BYREF

  if ( result )
  {
    if ( result == 1 )
      result = EtwpUpdateFileInfoDriverState(PerfGlobalGroupMask, (int)PerfGlobalGroupMask, 1, 0);
  }
  else
  {
    KeQueryBootTimeValues(&EtwpRefTimeSystem, &v19, &v18);
    EtwpBootTime = v19 - v18;
    KeQueryPerformanceCounter(&v19, 0);
    EtwpRefTimePerfCounter = v19;
    LODWORD(v1) = ReadTimeStampCounter();
    *(_QWORD *)&EtwpRefTimeCycle = v1;
    for ( i = 0; i < 0x40; ++i )
    {
      WmipLoggerContext[i] = 1;
      v3 = ExAllocateCacheAwareRundownProtection(512, 1668772933);
      EtwpLoggerRundown[i] = v3;
      if ( !v3 )
        KeBugCheckEx(285, 8, i, 0, 0);
    }
    if ( EtwpInitializeSecurity() < 0 )
      sub_966324();
    for ( j = -27776; j != -27758; j += 2 )
      *(_WORD *)j = 0;
    v5 = 0;
    if ( KeNumberProcessors_0 )
    {
      v6 = (int *)&KiProcessorBlock;
      if ( !KeNumberProcessors_0 )
      {
        v7 = 0;
        goto LABEL_12;
      }
      do
      {
        v7 = *v6;
LABEL_12:
        v8 = EtwInitializeProcessor(v7);
        if ( v8 < 0 )
          KeBugCheck2(285, 2, v8, v5, 0, 0);
        ++v5;
        ++v6;
      }
      while ( v5 < KeNumberProcessors_0 );
    }
    KeInitializeMutex((int)&EtwpGroupMaskMutex);
    KeInitializeMutex((int)&EtwpStartTraceMutex);
    KeInitializeMutex((int)&EtwpCrimsonMaskMutex);
    EtwpSecurityLock = 0;
    EtwpInitializeStackLookasideList();
    v9 = EtwpReadConfigParameters();
    v10 = EtwpInitializeRegistration(v9);
    EtwpInitializeRealTimeConnection(v10);
    if ( KeNumberProcessors_0 )
      v11 = KiProcessorBlock;
    else
      v11 = 0;
    v12 = _rt_udiv64(1000000i64, v11[121]);
    HIDWORD(v19) = v13;
    EtwCPUSpeedInMHz = v12;
    KeQueryPerformanceCounter(&v19, &EtwPerfFreq);
    EtwpBufferAdjustmentCount = 8;
    dword_61A768 = (int)EtwpAdjustTraceBuffers;
    dword_61A76C = (int)&EtwpBufferAdjustmentActive;
    EtwpAdjustBuffersWorkItem = 0;
    KeInitializeTimerEx(EtwpMemInfoTimer, 1);
    EtwpMemInfoDpc = 19;
    byte_61AA81 = 1;
    word_61AA82 = 0;
    dword_61AA8C = (int)EtwpLogMemInfoDpc;
    dword_61AA90 = 0;
    dword_61AA9C = 0;
    dword_61AA88 = 0;
    EtwpInitializeProviderTraits();
    EtwRegister((int)EventTracingProvGuid, (int)EtwpTracingProvEnableCallback, 0);
    if ( !ExRegisterCallback(ExCbPowerState, (int)EtwpPowerStateCallback, 0) )
      KeBugCheck(285);
    byte_61A638 = 0;
    KeRegisterBugCheckReasonCallback(
      (int)&EtwpBugCheckCallback,
      (int)EtwpBugCheckMultiPartCallback,
      5,
      (int)EtwpComponentName);
    memset(v20, 0, 24);
    LOWORD(v20[0]) = 1;
    HIWORD(v20[0]) |= 1u;
    v20[1] = (int)EtwpServerSiloCreateNotify;
    v20[2] = (int)EtwpServerSiloTerminateNotify;
    v20[5] = (int)AlpcMessageDeleteProcedure;
    PsRegisterMonitorServerSilo(0, L"NTOS_ETW", (unsigned __int16 *)v20, (unsigned int *)&EtwSiloMonitor);
    PsStartMonitorServerSilo((_DWORD *)EtwSiloMonitor);
    v14 = WdipSemInitialize();
    PerfDiagInitialize(v14);
    EtwRegister((int)KernelProvGuid, (int)EtwpKernelProvEnableCallback, 0);
    TraceLoggingRegister((int)&dword_617748, v15);
    EtwRegister((int)PsProvGuid, (int)EtwpCrimsonProvEnableCallback, 1);
    LODWORD(v16) = PsProvTraceLoggingGuid;
    TraceLoggingRegisterEx((int)&dword_616438, v16);
    EtwRegister((int)NetProvGuid, (int)EtwpCrimsonProvEnableCallback, 0x10000);
    EtwRegister((int)DiskProvGuid, (int)EtwpCrimsonProvEnableCallback, 256);
    EtwRegister((int)FileProvGuid, (int)EtwpCrimsonProvEnableCallback, 0x2000000);
    EtwRegister((int)RegistryProvGuid, (int)EtwpRegTraceEnableCallback, 0);
    EtwRegister((int)MemoryProvGuid, (int)EtwpCrimsonProvEnableCallback, 536870913);
    EtwRegister((int)MS_Windows_Kernel_AppCompat_Provider, 0, 0);
    EtwRegister((int)KernelAuditApiCallsGuid, 0, 0);
    EtwpInitialized = 1;
    ZwUpdateWnfStateData();
    v17 = ZwUpdateWnfStateData();
    result = EtwpTraceSystemInitialization(v17);
  }
  return result;
}
