// PopDiagTracePowerRequestChange 
 
int __fastcall PopDiagTracePowerRequestChange(int result, int a2)
{
  int vars8; // [sp+94h] [bp+8h]

  vars8 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, POP_ETW_EVENT_CHANGE_POWER_REQUEST);
    if ( result )
      result = sub_529780();
  }
  return result;
}
