// PopDiagTraceInputTimeout 
 
int __fastcall PopDiagTraceInputTimeout(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+4Ch] [bp+8h]

  varg_r0 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_ADPM_INPUT_TIMEOUT);
    if ( result )
      result = sub_7F229C();
  }
  return result;
}
