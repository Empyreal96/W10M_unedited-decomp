// PopDiagTraceSessionDisplayStateChange 
 
int __fastcall PopDiagTraceSessionDisplayStateChange(int result, int a2, int a3, int a4)
{
  int *v4; // r4
  int varg_r0; // [sp+4Ch] [bp+8h]

  varg_r0 = result;
  if ( result )
    v4 = POP_ETW_EVENT_SESSION_DISPLAY_OFF;
  else
    v4 = POP_ETW_EVENT_SESSION_DISPLAY_ON;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, v4);
    if ( result )
      result = sub_50FF28();
  }
  return result;
}
