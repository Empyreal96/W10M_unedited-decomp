// PopDiagTraceFxDevicePreparation 
 
int __fastcall PopDiagTraceFxDevicePreparation(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+7Ch] [bp+8h]

  varg_r0 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICE_PREPARATION);
    if ( result )
      result = sub_7E0E04();
  }
  return result;
}
