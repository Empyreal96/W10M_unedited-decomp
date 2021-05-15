// PopFxEnablePlatformStates 
 
int __fastcall PopFxEnablePlatformStates(int result)
{
  int v1; // r4

  if ( result )
  {
    result = PopPepPlatformStateRegistered();
    if ( PpmPlatformStates && *(_DWORD *)PpmPlatformStates )
      v1 = *(_DWORD *)PpmPlatformStates - 1;
    else
      v1 = -1;
    if ( v1 != -1 )
    {
      PopFxSetDeviceAccountingCsPlatformState(v1);
      result = PopFxInitializeSocSubsystemStaticInfo(v1);
    }
  }
  return result;
}
