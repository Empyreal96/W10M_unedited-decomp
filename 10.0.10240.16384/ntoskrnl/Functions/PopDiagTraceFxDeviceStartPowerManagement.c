// PopDiagTraceFxDeviceStartPowerManagement 
 
int __fastcall PopDiagTraceFxDeviceStartPowerManagement(int result, int a2)
{
  int _2C; // [sp+2Ch] [bp+8h]

  _2C = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICE_START_POWER_MANAGEMENT);
    if ( result )
      result = sub_812588();
  }
  return result;
}
