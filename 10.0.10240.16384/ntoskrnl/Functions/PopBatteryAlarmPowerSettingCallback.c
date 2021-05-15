// PopBatteryAlarmPowerSettingCallback 
 
int __fastcall PopBatteryAlarmPowerSettingCallback(int a1, int a2, int a3, int a4)
{
  int v5; // r4

  PopAcquirePolicyLock();
  v5 = PopBatteryUpdateAlarms(0, a4);
  PopReleasePolicyLock();
  return v5;
}
