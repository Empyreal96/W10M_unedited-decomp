// PopDiagTraceShutdownAction 
 
int PopDiagTraceShutdownAction(int result, ...)
{
  int v1; // r7
  __int64 v2; // kr00_8
  int v3; // [sp+8h] [bp-50h] BYREF
  _DWORD var4C[20]; // [sp+Ch] [bp-4Ch] BYREF
  int varg_r1; // [sp+64h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+64h] [bp+Ch]
  int varg_r2; // [sp+68h] [bp+10h]
  va_list varg_r3; // [sp+6Ch] [bp+14h] BYREF

  va_start(varg_r3, result);
  va_start(varg_r1a, result);
  varg_r1 = va_arg(varg_r3, _DWORD);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v1 = result;
  if ( PopDiagHandleRegistered )
  {
    v2 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_SHUTDOWN_ACTION);
    if ( result )
    {
      var4C[0] = v1;
      var4C[1] = var4C;
      var4C[2] = 0;
      var4C[3] = 4;
      var4C[4] = 0;
      va_copy((va_list)&var4C[5], varg_r1a);
      var4C[6] = 0;
      var4C[7] = 4;
      var4C[8] = 0;
      var4C[9] = &v3;
      var4C[10] = 0;
      var4C[11] = 4;
      var4C[12] = 0;
      v3 = varg_r2;
      result = EtwWrite(v2, SHIDWORD(v2), (int)POP_ETW_EVENT_SHUTDOWN_ACTION, 0);
    }
  }
  return result;
}
