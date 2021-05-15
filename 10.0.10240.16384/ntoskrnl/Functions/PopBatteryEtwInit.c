// PopBatteryEtwInit 
 
int PopBatteryEtwInit()
{
  int result; // r0

  result = EtwRegister((int)BATTERY_ETW_PROVIDER, (int)PopBatteryEtwCallback, 0);
  if ( result >= 0 )
    PopBatteryEtwRegistered = 1;
  return result;
}
