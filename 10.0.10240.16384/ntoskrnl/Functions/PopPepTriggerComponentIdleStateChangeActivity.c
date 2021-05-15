// PopPepTriggerComponentIdleStateChangeActivity 
 
int __fastcall PopPepTriggerComponentIdleStateChangeActivity(int a1, int a2, int a3)
{
  int result; // r0
  int v6; // r2

  if ( a2 )
  {
    if ( a3 < 0 )
      result = PopPepTryPowerUpComponent();
    if ( *(_DWORD *)(a2 + 144) )
      v6 = 0;
    else
      v6 = a3 & 0x7FFFFFFF;
    *(_DWORD *)(*(_DWORD *)(a2 + 52) + 4) = v6;
  }
  return result;
}
