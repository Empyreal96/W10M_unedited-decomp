// PopDiagTraceFxDevicePowerState 
 
int __fastcall PopDiagTraceFxDevicePowerState(int result, int a2)
{
  int _5C; // [sp+5Ch] [bp+8h]

  _5C = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICE_POWER_STATE);
    if ( result )
      result = sub_54AFCC();
  }
  return result;
}
