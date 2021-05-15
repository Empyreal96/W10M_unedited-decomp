// PopPerfBoostPowerRequest 
 
int __fastcall PopPerfBoostPowerRequest(int a1)
{
  if ( a1 )
    PoLatencySensitivityHint();
  ZwUpdateWnfStateData();
  return 0;
}
