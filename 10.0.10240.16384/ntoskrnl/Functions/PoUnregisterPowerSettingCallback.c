// PoUnregisterPowerSettingCallback 
 
int __fastcall PoUnregisterPowerSettingCallback(int a1)
{
  int result; // r0

  if ( a1 )
    result = sub_81A42C();
  else
    result = -1073741811;
  return result;
}
