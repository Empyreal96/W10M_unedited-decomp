// PopDiagTracePowerSetting 
 
int __fastcall PopDiagTracePowerSetting(int result, int a2, int a3, int a4)
{
  int *v4; // r4
  int varg_r0; // [sp+74h] [bp+8h]

  varg_r0 = result;
  if ( result )
    v4 = POP_ETW_EVENT_POWER_SETTING_RUNDOWN;
  else
    v4 = POP_ETW_EVENT_POWER_SETTING_CHANGE;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)v4);
    if ( result )
      result = sub_7F2C48();
  }
  return result;
}
