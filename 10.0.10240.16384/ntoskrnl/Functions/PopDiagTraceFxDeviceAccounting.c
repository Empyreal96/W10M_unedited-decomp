// PopDiagTraceFxDeviceAccounting 
 
int __fastcall PopDiagTraceFxDeviceAccounting(int result, int a2, int a3, int a4)
{
  __int64 v4; // kr00_8
  int varg_r0; // [sp+50h] [bp+8h]

  varg_r0 = result;
  if ( PopDiagHandleRegistered )
  {
    v4 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_DEVICE_ACCOUNTING);
    if ( result )
      result = EtwWrite(v4, SHIDWORD(v4), (int)POP_ETW_EVENT_DEVICE_ACCOUNTING, 0);
  }
  return result;
}
