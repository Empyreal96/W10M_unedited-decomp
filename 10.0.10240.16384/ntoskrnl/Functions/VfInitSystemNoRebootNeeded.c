// VfInitSystemNoRebootNeeded 
 
int __fastcall VfInitSystemNoRebootNeeded(int result, int a2)
{
  int v3; // r6
  int v4; // r0
  int v5; // r0
  int v6; // r0

  v3 = result;
  if ( !ViFullyInitialized )
  {
    if ( !a2 )
    {
      VfInitializedWithoutReboot = 1;
      ViCodeSectionHandle = MmLockPagableDataSection((unsigned int)VfInitVerifierComponents);
      ViDataSectionHandle = MmLockPagableDataSection((unsigned int)&VfSettingsIrpDeferralTime);
      ViConstSectionHandle = MmLockPagableDataSection((unsigned int)ViShortTime);
      ViBssSectionHandle = MmLockPagableDataSection((unsigned int)&ViBugCheckInitialControl);
    }
    if ( v3 || !a2 )
      ExDisableAllLookasideLists();
    VerifierModifyableOptions = 0x1FFF;
    if ( MmVerifyDriverLevel == -1 )
    {
      result = 2491;
      MmVerifierData = 2491;
    }
    else
    {
      result = MmVerifyDriverLevel;
      MmVerifierData = MmVerifyDriverLevel;
    }
    if ( v3 == 1 )
    {
      MmVerifyDriverLevel &= 0xFFFFFFDF;
      MmVerifierData = result & 0xFFFFFFDF;
      ViVerifyAllDrivers = 1;
      ExSetPoolFlags(8);
      result = MmVerifierData;
    }
    ViVerifierDriverAddedThunkListHead = (int)&ViVerifierDriverAddedThunkListHead;
    dword_61CEB4 = (int)&ViVerifierDriverAddedThunkListHead;
    ViVerifierDriverAddedSpecialThunkListHead = (int)&ViVerifierDriverAddedSpecialThunkListHead;
    *(_DWORD *)algn_61D39C = &ViVerifierDriverAddedSpecialThunkListHead;
    if ( !a2 )
    {
      v4 = VfInitVerifierComponents(result, ViVerifyAllDrivers, KernelVerifier);
      v5 = VfPoolInitPhase1(v4);
      v6 = VfSettingsMiscellaneousChecksInitPhase1(v5);
      VfPendingInitPhase1(v6);
      result = IoVerifierInit(MmVerifierData);
    }
    ViFullyInitialized = 1;
  }
  return result;
}
