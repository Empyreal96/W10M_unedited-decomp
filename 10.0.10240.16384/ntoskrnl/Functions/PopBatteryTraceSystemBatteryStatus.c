// PopBatteryTraceSystemBatteryStatus 
 
int __fastcall PopBatteryTraceSystemBatteryStatus(int result)
{
  int *v1; // r4

  if ( result )
    v1 = BATTERY_EVT_SYSTEM_BATTERY_STATUS_RUNDOWN;
  else
    v1 = BATTERY_EVT_SYSTEM_BATTERY_STATUS_CHANGE;
  if ( PopBatteryEtwRegistered )
  {
    result = EtwEventEnabled(PopBatteryEtwHandle, unk_61E594, v1);
    if ( result )
      result = sub_529C9C();
  }
  return result;
}
