// PopDiagTraceDevicesLevel 
 
int __fastcall PopDiagTraceDevicesLevel(int result, int a2, int a3, int a4)
{
  int *v4; // r4
  __int64 v5; // kr00_8
  int varg_r0; // [sp+40h] [bp+8h]

  varg_r0 = result;
  if ( a2 )
  {
    if ( a4 )
      v4 = POP_ETW_EVENT_DEVICESWAKELEVEL;
    else
      v4 = POP_ETW_EVENT_DEVICESWAKELEVEL_END;
  }
  else if ( a4 )
  {
    v4 = POP_ETW_EVENT_DEVICESSUSPENDLEVEL;
  }
  else
  {
    v4 = POP_ETW_EVENT_DEVICESSUSPENDLEVEL_END;
  }
  if ( PopDiagHandleRegistered )
  {
    v5 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)v4);
    if ( result )
      result = EtwWrite(v5, SHIDWORD(v5), (int)v4, 0);
  }
  return result;
}
