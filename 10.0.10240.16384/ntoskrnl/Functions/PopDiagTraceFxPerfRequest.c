// PopDiagTraceFxPerfRequest 
 
int PopDiagTraceFxPerfRequest(int result, ...)
{
  int v1; // r7
  int v2; // r8
  __int64 v3; // kr00_8
  int v4; // r2
  int var60[25]; // [sp+8h] [bp-60h] BYREF
  unsigned int varg_r1; // [sp+74h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+74h] [bp+Ch]
  int varg_r2; // [sp+78h] [bp+10h]
  va_list varg_r3; // [sp+7Ch] [bp+14h] BYREF

  va_start(varg_r3, result);
  va_start(varg_r1a, result);
  varg_r1 = va_arg(varg_r3, _DWORD);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v1 = varg_r2;
  v2 = result;
  if ( PopDiagHandleRegistered )
  {
    v3 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_COMPONENT_PERFORMANCE_STATE_INITIATING);
    if ( result )
    {
      v4 = *(_DWORD *)v2;
      var60[2] = *(_DWORD *)(*(_DWORD *)v2 + 48) + 28;
      var60[3] = 0;
      var60[4] = 4;
      var60[5] = 0;
      var60[6] = v4 + 16;
      var60[7] = 0;
      var60[8] = 4;
      var60[9] = 0;
      va_copy((va_list)&var60[10], varg_r1a);
      var60[11] = 0;
      var60[12] = 4;
      var60[13] = 0;
      result = RtlULongLongToULong(16 * varg_r1, (unsigned __int64)varg_r1 >> 28, var60);
      if ( result >= 0 )
      {
        var60[14] = v1;
        var60[15] = 0;
        var60[16] = var60[0];
        var60[17] = 0;
        result = EtwWrite(v3, SHIDWORD(v3), (int)POP_ETW_EVENT_COMPONENT_PERFORMANCE_STATE_INITIATING, 0);
      }
    }
  }
  return result;
}
