// PpmEnableCoordinatedIdleStates 
 
int __fastcall PpmEnableCoordinatedIdleStates(int *a1, char a2)
{
  int v2; // r0
  int result; // r0

  PpmIdleCoordinatedMode = a2;
  __dmb(0xBu);
  PpmPlatformStates = (int)a1;
  v2 = PopFxEnablePlatformStates(*a1);
  if ( PpmPlatformStates )
    result = sub_812320(v2);
  else
    result = -1;
  return result;
}
