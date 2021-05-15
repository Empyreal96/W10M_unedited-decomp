// PipInitializeCoreDriversAndElam 
 
int __fastcall PipInitializeCoreDriversAndElam(int a1)
{
  int v2; // r0
  int v3; // r0
  int result; // r0

  PipInitializeDriverDependentDLLs(0, a1);
  v2 = PipInitializeCoreDriversByGroup(0, a1);
  PspPicoRegistrationDisabled = 1;
  v3 = KeArmDiscoverCacheTopology(v2);
  PspPicoProviderRanges = 0;
  PspKernelRangeList = 0;
  unk_6178C4 = 0;
  PspKernelRanges = 0;
  dword_6178BC = 0;
  if ( *(_DWORD *)(a1 + 40) != a1 + 40 )
    return sub_968944(v3);
  PnpBootDriverCallbackRegistrationClosed = 1;
  PnpNotifyEarlyLaunchStatusUpdate(0);
  PipInitializeDriverDependentDLLs(1, a1);
  PipInitializeCoreDriversByGroup(1, a1);
  result = PipInitializeCoreDriversByGroup(2, a1);
  PnpCoreDriverGroupLoadPhase = 3;
  return result;
}
