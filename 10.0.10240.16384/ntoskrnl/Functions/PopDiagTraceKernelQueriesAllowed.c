// PopDiagTraceKernelQueriesAllowed 
 
int __fastcall PopDiagTraceKernelQueriesAllowed(int result)
{
  int v1; // r4
  __int64 v2; // kr00_8
  int v3[10]; // [sp+8h] [bp-28h] BYREF

  v1 = result;
  if ( PopDiagHandleRegistered )
  {
    v2 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_KERNEL_QUERY_ALLOWED);
    if ( result )
    {
      v3[2] = (int)v3;
      v3[3] = 0;
      v3[4] = 4;
      v3[5] = 0;
      v3[0] = v1;
      result = EtwWrite(v2, SHIDWORD(v2), (int)POP_ETW_EVENT_KERNEL_QUERY_ALLOWED, 0);
    }
  }
  return result;
}
