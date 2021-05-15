// PpmIdleRecheckCoordinatedIdleMask 
 
int __fastcall PpmIdleRecheckCoordinatedIdleMask(int a1)
{
  int result; // r0

  result = 0;
  if ( PpmPlatformStates )
  {
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 216) + 4) )
      result = sub_551B98(0);
  }
  return result;
}
