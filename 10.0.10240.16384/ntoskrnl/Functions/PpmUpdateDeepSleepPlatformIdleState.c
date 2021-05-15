// PpmUpdateDeepSleepPlatformIdleState 
 
int __fastcall PpmUpdateDeepSleepPlatformIdleState(int result)
{
  int v1; // r2

  if ( PpmPlatformStates && *(_DWORD *)PpmPlatformStates )
    v1 = *(_DWORD *)PpmPlatformStates - 1;
  else
    v1 = -1;
  if ( result )
    PpmDripsStateIndex = v1;
  else
    PpmDripsStateIndex = -1;
  return result;
}
