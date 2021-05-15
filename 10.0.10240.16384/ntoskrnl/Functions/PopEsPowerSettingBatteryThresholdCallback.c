// PopEsPowerSettingBatteryThresholdCallback 
 
int __fastcall PopEsPowerSettingBatteryThresholdCallback(int a1, int a2, int a3)
{
  int result; // r0

  if ( a2 && a3 == 4 )
    result = sub_81BF48();
  else
    result = -1073741811;
  return result;
}
