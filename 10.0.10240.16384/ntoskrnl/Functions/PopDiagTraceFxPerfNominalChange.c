// PopDiagTraceFxPerfNominalChange 
 
int PopDiagTraceFxPerfNominalChange(int result, int a2, ...)
{
  int v3; // r8
  __int64 v4; // r4
  int v5; // r2
  int v6; // r3
  int v7; // [sp+8h] [bp-80h] BYREF
  int var7C[32]; // [sp+Ch] [bp-7Ch] BYREF
  int varg_r2; // [sp+98h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+98h] [bp+10h]
  unsigned int varg_r3; // [sp+9Ch] [bp+14h] BYREF
  va_list varg_r3a; // [sp+9Ch] [bp+14h]
  int v13; // [sp+A0h] [bp+18h]
  va_list va2; // [sp+A4h] [bp+1Ch] BYREF

  va_start(va2, a2);
  va_start(varg_r3a, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3a, _DWORD);
  va_copy(va2, varg_r3a);
  varg_r3 = va_arg(va2, _DWORD);
  v13 = va_arg(va2, _DWORD);
  v3 = result;
  if ( PopDiagHandleRegistered )
  {
    v4 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_COMPONENT_PERFORMANCE_STATE_NOMINAL_CHANGE);
    if ( result )
    {
      v5 = *(_DWORD *)v3;
      v6 = *(_DWORD *)(*(_DWORD *)v3 + 48);
      var7C[0] = a2;
      var7C[1] = v6 + 28;
      var7C[2] = 0;
      var7C[3] = 4;
      var7C[4] = 0;
      var7C[5] = v5 + 16;
      var7C[6] = 0;
      var7C[7] = 4;
      var7C[8] = 0;
      var7C[9] = (int)var7C;
      var7C[10] = 0;
      var7C[11] = 4;
      var7C[12] = 0;
      va_copy((va_list)&var7C[13], varg_r2a);
      var7C[14] = 0;
      var7C[15] = 4;
      var7C[16] = 0;
      va_copy((va_list)&var7C[17], varg_r3a);
      var7C[18] = 0;
      var7C[19] = 4;
      var7C[20] = 0;
      result = RtlULongLongToULong(16 * varg_r3, (unsigned __int64)varg_r3 >> 28, &v7);
      if ( result >= 0 )
      {
        var7C[21] = v13;
        var7C[22] = 0;
        var7C[23] = v7;
        var7C[24] = 0;
        result = EtwWrite(v4, SHIDWORD(v4), (int)POP_ETW_EVENT_COMPONENT_PERFORMANCE_STATE_NOMINAL_CHANGE, 0);
      }
    }
  }
  return result;
}
