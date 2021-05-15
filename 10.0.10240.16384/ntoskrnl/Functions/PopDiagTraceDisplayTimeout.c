// PopDiagTraceDisplayTimeout 
 
int __fastcall PopDiagTraceDisplayTimeout(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+4Ch] [bp+8h]

  varg_r0 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_ADPM_DISPLAY_TIMEOUT);
    if ( result )
      result = sub_7F22E8();
  }
  return result;
}
