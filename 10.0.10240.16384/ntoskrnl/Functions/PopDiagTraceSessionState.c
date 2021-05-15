// PopDiagTraceSessionState 
 
int __fastcall PopDiagTraceSessionState(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+3Ch] [bp+8h]

  varg_r0 = result;
  if ( PopDiagHandleRegistered )
  {
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, result);
    if ( result )
      result = sub_7F2508();
  }
  return result;
}
