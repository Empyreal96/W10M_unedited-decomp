// PopDiagTraceFxDeviceAccounting 
 
int __fastcall PopDiagTraceFxDeviceAccounting(int result, int a2, int a3, int a4)
{
  __int64 v4; // kr00_8
  int var40[17]; // [sp+8h] [bp-40h] BYREF
  int varg_r0[2]; // [sp+50h] [bp+8h] BYREF
  int varg_r2[2]; // [sp+58h] [bp+10h] BYREF

  varg_r0[0] = result;
  varg_r0[1] = a2;
  varg_r2[0] = a3;
  varg_r2[1] = a4;
  if ( PopDiagHandleRegistered )
  {
    v4 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, POP_ETW_EVENT_DEVICE_ACCOUNTING);
    if ( result )
    {
      var40[0] = (int)&PopWdiCurrentScenarioInstanceId;
      var40[1] = 0;
      var40[2] = 1;
      var40[3] = 0;
      var40[4] = (int)varg_r0;
      var40[5] = 0;
      var40[6] = 4;
      var40[7] = 0;
      var40[8] = (int)varg_r2;
      var40[9] = 0;
      var40[10] = 8;
      var40[11] = 0;
      result = ((int (__fastcall *)(_DWORD, _DWORD, int *, _DWORD, int, int *))EtwWrite)(
                 v4,
                 HIDWORD(v4),
                 POP_ETW_EVENT_DEVICE_ACCOUNTING,
                 0,
                 3,
                 var40);
    }
  }
  return result;
}
