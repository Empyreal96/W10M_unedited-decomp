// PopGracefulShutdown 
 
void PopGracefulShutdown()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r4
  int v5; // r8
  unsigned int v6; // r2
  unsigned int v7; // r1
  __int64 v8; // kr00_8
  int v9; // r2
  unsigned int v10; // r4
  char v11; // r3
  int v12; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0

  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_GRACEFULSHUTDOWN_START);
  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(dword_61EC94 + 12) = v0;
  v1 = PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_ZEROPAGEFILE_START);
  MmZeroPageFileAtShutdown(v1);
  v2 = PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_ZEROPAGEFILE_STOP);
  if ( !dword_61EC90 )
    off_617B9C(v2);
  v3 = VfShutdownScheduleWatchdog();
  if ( PopShutdownCleanly )
  {
    PsShutdownSystem(v3);
    KeSetEvent((int)&PopShutdownEvent, 0, 0);
    v4 = KeAbPreAcquire((unsigned int)&PopShutdownListMutex, 0, 0);
    v5 = KfRaiseIrql(1);
    do
      v6 = __ldrex((unsigned __int8 *)&PopShutdownListMutex);
    while ( __strex(v6 & 0xFE, (unsigned __int8 *)&PopShutdownListMutex) );
    __dmb(0xBu);
    if ( (v6 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PopShutdownListMutex, v4);
    if ( v4 )
      *(_BYTE *)(v4 + 14) |= 1u;
    __mrc(15, 0, 13, 0, 3);
    dword_61F43C = v5;
    PopShutdownListAvailable = 0;
    dword_61F424 = 0;
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)&PopShutdownListMutex);
    while ( !v7 && __strex(1u, (unsigned int *)&PopShutdownListMutex) );
    if ( v7 )
      ExpReleaseFastMutexContended((unsigned int *)&PopShutdownListMutex, v7);
    KfLowerIrql((unsigned __int8)v5);
    KeAbPostRelease((unsigned int)&PopShutdownListMutex);
    while ( 1 )
    {
      v9 = PopShutdownQueue;
      if ( (int *)PopShutdownQueue == &PopShutdownQueue )
        break;
      v8 = *(_QWORD *)PopShutdownQueue;
      if ( *(int **)(PopShutdownQueue + 4) != &PopShutdownQueue || *(_DWORD *)(v8 + 4) != PopShutdownQueue )
        __fastfail(3u);
      PopShutdownQueue = *(_DWORD *)PopShutdownQueue;
      *(_DWORD *)(v8 + 4) = &PopShutdownQueue;
      (*(void (__fastcall **)(_DWORD))(v9 + 8))(*(_DWORD *)(v9 + 12));
    }
    while ( 1 )
    {
      v10 = PopShutdownThreadList;
      if ( !PopShutdownThreadList )
        break;
      PopShutdownThreadList = *(_DWORD *)PopShutdownThreadList;
      KeWaitForSingleObject(*(_DWORD *)(v10 + 4), 0, 0, 0, 0);
      ObfDereferenceObject(*(_DWORD *)(v10 + 4));
      ExFreePoolWithTag(v10);
    }
  }
  TmShutdownSystem_0();
  CmShutdownSystem(0);
  ExShutdownSystem(0);
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_IOSHUTDOWNSYSTEM_START);
  IoShutdownSystem(0);
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_IOSHUTDOWNSYSTEM_STOP);
  v11 = PopShutdownCleanly;
  if ( PopShutdownCleanly )
  {
    v12 = PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_WAITFORPROCESSES_START);
    PsWaitForAllProcesses(v12);
    PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_WAITFORPROCESSES_STOP);
    v11 = PopShutdownCleanly;
  }
  if ( (v11 & 0x10) != 0 )
    ObShutdownSystem(0);
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_CMSHUTDOWNSYSTEM_START);
  CmShutdownSystem(1);
  PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_CMSHUTDOWNSYSTEM_STOP);
  if ( PopDiagHandleRegistered )
    EtwWriteEndScenario(
      PopDiagHandle,
      dword_61E154,
      POP_ETW_EVENT_GRACEFULSHUTDOWN_STOP,
      PopShutdownDiagnosticsScenarioGuid);
  EtwShutdown(0);
  ExShutdownSystem(1);
  v13 = MmShutdownSystem(0);
  v14 = PopSetShutdownMarker(v13);
  PnpWaitForEmptyDeviceActionQueue(v14);
  IoShutdownSystem(1);
  CcWaitForCurrentLazyWriterActivity();
  v15 = dword_61EC90;
  if ( dword_61EC90 )
  {
    if ( *(_DWORD *)(dword_61EC90 + 4) )
    {
      KeAttachProcess(*(_DWORD *)(dword_61EC90 + 4));
      v15 = dword_61EC90;
    }
    IoAddTriageDumpDataBlock(v15, 36);
    KeBugCheckEx(
      *(_DWORD *)(dword_61EC90 + 16),
      *(_DWORD *)(dword_61EC90 + 20),
      *(_DWORD *)(dword_61EC90 + 24),
      *(_DWORD *)(dword_61EC90 + 28),
      *(_DWORD *)(dword_61EC90 + 32));
  }
  *(_DWORD *)(dword_61EC94 + 244) = 0;
  v16 = PopBuildDeviceNotifyList(dword_61EC94 + 28);
  PopSetDevicesSystemState(v16);
  ExShutdownSystem(2);
  if ( (PopShutdownCleanly & 0x10) != 0 )
    ObShutdownSystem(2);
  MmShutdownSystem(2);
  PopShutdownSystem(dword_61EC64);
}
