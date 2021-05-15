// PopUpdateConsoleDisplayState 
 
int __fastcall PopUpdateConsoleDisplayState(int result, int a2)
{
  int v2; // r0
  int v3[2]; // [sp+10h] [bp-8h] BYREF

  if ( PopConsoleDisplayState != result )
  {
    PopConsoleDisplayState = result;
    v2 = PopDiagTraceConsoleDisplayState(result, a2);
    PopCheckResiliencyScenarios(v2);
    v3[0] = PopConsoleDisplayState;
    PopSetPowerSettingValueAcDc(&GUID_CONSOLE_DISPLAY_STATE, 4, v3);
    v3[0] = PopConsoleDisplayState != 0;
    PopSetPowerSettingValueAcDc(&GUID_MONITOR_POWER_ON, 4, v3);
    result = ZwUpdateWnfStateData();
    if ( PopPlatformAoAc )
      result = PopSpoilBatteryEstimate(0, PopConsoleDisplayState == 0);
  }
  return result;
}
