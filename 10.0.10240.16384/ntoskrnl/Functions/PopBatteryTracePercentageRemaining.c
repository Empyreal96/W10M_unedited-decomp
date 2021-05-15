// PopBatteryTracePercentageRemaining 
 
int __fastcall PopBatteryTracePercentageRemaining(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+64h] [bp+8h]

  varg_r0 = result;
  if ( PopBatteryEtwRegistered )
  {
    result = EtwEventEnabled(PopBatteryEtwHandle, unk_61E594, (int)BATTERY_EVT_BATTERY_PERCENT_REMAINING);
    if ( result )
      result = sub_81C978();
  }
  return result;
}
