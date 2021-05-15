// PopDiagTraceFxDeviceUnregistration 
 
int __fastcall PopDiagTraceFxDeviceUnregistration(int result, int a2)
{
  __int64 v2; // kr00_8
  int vars8; // [sp+30h] [bp+8h]

  vars8 = result;
  if ( PopDiagHandleRegistered )
  {
    v2 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICE_UNREGISTRATION);
    if ( result )
      result = EtwWrite(v2, SHIDWORD(v2), (int)POP_ETW_EVENT_DEVICE_UNREGISTRATION, 0);
  }
  return result;
}
