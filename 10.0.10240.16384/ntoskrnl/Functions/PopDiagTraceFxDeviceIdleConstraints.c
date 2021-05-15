// PopDiagTraceFxDeviceIdleConstraints 
 
int __fastcall PopDiagTraceFxDeviceIdleConstraints(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+54h] [bp+8h]

  varg_r0 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICE_IDLE_CONSTRAINTS);
    if ( result )
      result = sub_55133C();
  }
  return result;
}
