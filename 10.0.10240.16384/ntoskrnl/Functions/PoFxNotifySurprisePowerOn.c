// PoFxNotifySurprisePowerOn 
 
int __fastcall PoFxNotifySurprisePowerOn(int a1)
{
  _DWORD *v1; // r0
  int result; // r0
  int v3; // r4

  if ( a1 )
    v1 = *(_DWORD **)(*(_DWORD *)(a1 + 176) + 20);
  else
    v1 = 0;
  result = PopFxLockDevice(v1, 1);
  v3 = result;
  if ( result )
  {
    PopPepSurprisePowerOn(*(_DWORD *)(result + 32));
    result = PopFxReleaseDevice(v3);
  }
  return result;
}
