// PopInitializePowerSettingCallbacks 
 
int PopInitializePowerSettingCallbacks()
{
  GUID **v0; // r4
  int v1; // r5
  int v2; // r2
  GUID *v3; // t1
  int v4; // r0
  unsigned int i; // r4
  int result; // r0

  v0 = &PopInitialSettingCallbacks;
  v1 = 42;
  do
  {
    v2 = (int)v0[1];
    v3 = *v0;
    v0 += 2;
    v4 = PoRegisterPowerSettingCallback(0, v3, v2, 0, 0);
    --v1;
  }
  while ( v1 );
  PpmInfoRegisterCallbacks(v4);
  for ( i = 0; i < 4; ++i )
  {
    PoRegisterPowerSettingCallback(
      0,
      &GUIDS_BATTERY_DISCHARGE_ACTION[i]->Data1,
      (int)PopBatteryAlarmPowerSettingCallback,
      i,
      0);
    PoRegisterPowerSettingCallback(
      0,
      &GUIDS_BATTERY_DISCHARGE_LEVEL[i]->Data1,
      (int)PopBatteryAlarmPowerSettingCallback,
      i,
      0);
    result = PoRegisterPowerSettingCallback(
               0,
               &GUIDS_BATTERY_DISCHARGE_FLAGS[i]->Data1,
               (int)PopBatteryAlarmPowerSettingCallback,
               i,
               0);
  }
  return result;
}
