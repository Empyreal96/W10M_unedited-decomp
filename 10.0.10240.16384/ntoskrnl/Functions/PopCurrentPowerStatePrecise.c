// PopCurrentPowerStatePrecise 
 
int __fastcall PopCurrentPowerStatePrecise(int a1)
{
  PopBatteryUpdateCurrentState();
  return PopCurrentPowerState(a1);
}
