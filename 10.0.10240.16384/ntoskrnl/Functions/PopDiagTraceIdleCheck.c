// PopDiagTraceIdleCheck 
 
int PopDiagTraceIdleCheck(int a1, ...)
{
  __int64 v1; // kr00_8
  int result; // r0
  BOOL v3; // [sp+8h] [bp-90h] BYREF
  BOOL v4; // [sp+Ch] [bp-8Ch] BYREF
  int v5; // [sp+10h] [bp-88h] BYREF
  int var84[34]; // [sp+14h] [bp-84h] BYREF
  int varg_r1; // [sp+A4h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+A4h] [bp+Ch]
  va_list varg_r2; // [sp+A8h] [bp+10h] BYREF

  va_start(varg_r2, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r2, _DWORD);
  v5 = 0;
  if ( PopDiagHandleRegistered )
  {
    v1 = *(_QWORD *)&PopDiagHandle;
    result = EtwEventEnabled(PopDiagHandle, dword_61E154, (int)POP_ETW_EVENT_IDLE_CHECK);
    if ( result )
    {
      var84[0] = 0;
      v3 = dword_61E808 >= (unsigned int)dword_61E80C;
      v4 = dword_60E1E8 != 0;
      var84[1] = (int)&v5;
      var84[2] = 0;
      var84[3] = 4;
      var84[4] = 0;
      va_copy((va_list)&var84[5], varg_r1a);
      var84[6] = 0;
      var84[7] = 4;
      var84[8] = 0;
      va_copy((va_list)&var84[9], varg_r2);
      var84[10] = 0;
      var84[11] = 4;
      var84[12] = 0;
      var84[13] = (int)&dword_61E808;
      var84[14] = 0;
      var84[15] = 4;
      var84[16] = 0;
      var84[17] = (int)var84;
      var84[18] = 0;
      var84[19] = 4;
      var84[20] = 0;
      var84[21] = (int)&v3;
      var84[22] = 0;
      var84[23] = 4;
      var84[24] = 0;
      var84[25] = (int)&v4;
      var84[26] = 0;
      var84[27] = 4;
      var84[28] = 0;
      result = EtwWrite(v1, SHIDWORD(v1), (int)POP_ETW_EVENT_IDLE_CHECK, 0);
    }
  }
  return result;
}
