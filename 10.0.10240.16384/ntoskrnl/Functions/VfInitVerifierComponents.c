// VfInitVerifierComponents 
 
int __fastcall VfInitVerifierComponents(int a1, int a2, int a3)
{
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int v12; // r0
  int v13; // r0
  _DWORD *v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r1
  unsigned int v18; // r2
  int result; // r0

  v6 = ExSetPoolFlags(16);
  v7 = VfIrpDatabaseInit(v6);
  VfWdInit(v7);
  VfKeCheckForChanges(a1);
  ViSettingsIoCheckForChanges(a1);
  if ( (a1 & 8) != 0 )
    MmTrackLockedPages = 1;
  v8 = VfPendingCheckForChanges(a1);
  v9 = VfPoolInitPhase0(v8);
  v10 = VfFaultsInitPhase0(v9);
  v11 = VfLookasideInit(v10);
  VfSessionDataInit(v11);
  v12 = pXdvExInitializeNPagedLookasideList(
          &ViPacketLookaside,
          0,
          VfUtilFreePoolCheckIRQL,
          512,
          148,
          1953526345,
          16,
          VfInitializedWithoutReboot,
          ExInitializeNPagedLookasideListInternal);
  VfResourceInit(v12);
  pXdvExInitializeNPagedLookasideList(
    &ViIrpCallDriverDataList,
    0,
    VfUtilFreePoolCheckIRQL,
    512,
    120,
    1131442761,
    16,
    VfInitializedWithoutReboot,
    ExInitializeNPagedLookasideListInternal);
  memset(ViMajorVerifierRoutines, 0, 1440);
  VfMajorRegisterHandlers(
    27,
    VfPnpDumpIrpStack,
    VfPnpVerifyNewRequest,
    VfPnpVerifyIrpStackDownward,
    VfPnpVerifyIrpStackUpward,
    VfPnpIsSystemRestrictedIrp,
    VfPnpAdvanceIrpStatus,
    0,
    0,
    0,
    0,
    VfPnpTestStartedPdoStack,
    0);
  VfMajorRegisterHandlers(
    22,
    VfPowerDumpIrpStack,
    VfPowerVerifyNewRequest,
    VfPowerVerifyIrpStackDownward,
    VfPowerVerifyIrpStackUpward,
    VfPowerIsSystemRestrictedIrp,
    0,
    0,
    0,
    0,
    0,
    VfPowerTestStartedPdoStack,
    0);
  VfMajorRegisterHandlers(
    23,
    VfWmiDumpIrpStack,
    VfWmiVerifyNewRequest,
    VfWmiVerifyIrpStackDownward,
    VfWmiVerifyIrpStackUpward,
    0,
    0,
    0,
    0,
    0,
    0,
    VfWmiTestStartedPdoStack,
    0);
  v13 = VfMajorRegisterHandlers(
          255,
          ViGenericDumpIrpStack,
          ViGenericVerifyNewRequest,
          ViGenericVerifyIrpStackDownward,
          ViGenericVerifyIrpStackUpward,
          0,
          0,
          ViGenericIsValidIrpStatus,
          ViGenericIsNewRequest,
          ViGenericVerifyNewIrp,
          ViGenericVerifyNewRequest,
          0,
          ViGenericBuildIrpLogEntry);
  VfHalVerifierInitialize(v13);
  ViIrpLogDatabaseLock = 0;
  v14 = (_DWORD *)ExAllocatePoolWithTag(512, 12, 1682531926);
  ViIrpLogDatabase = (int)v14;
  if ( v14 )
  {
    *v14 = 0;
    v14[1] = v14 + 1;
    v14[2] = v14 + 1;
  }
  ViDdiInitialized = 1;
  v15 = VfRemLockInit();
  v16 = VfDevObjInit(v15);
  VfIoCallbacksInit(v16);
  if ( (MmVerifierData & 0x800) != 0 )
  {
    v17 = 16;
    do
    {
      __dmb(0xBu);
      do
        v18 = __ldrex((unsigned int *)&ViCtxInitializedIsrStateBlocks);
      while ( __strex(v18 + 1, (unsigned int *)&ViCtxInitializedIsrStateBlocks) );
      __dmb(0xBu);
      --v17;
    }
    while ( v17 );
  }
  VfDeadlockInitialize(a2, a3);
  result = VfSettingsApplyMiscellaneousChecks(a1);
  IovUtilVerifierEnabled = 1;
  if ( (MmVerifierData & 0x10) != 0 )
    PpvUtilVerifierEnabled = 1;
  ViVerifierEnabled = 1;
  return result;
}
