// PopDiagTraceIdleResiliencyStart 
 
int PopDiagTraceIdleResiliencyStart(int a1, int a2, ...)
{
  int result; // r0
  _DWORD v3[17]; // [sp+8h] [bp-58h] BYREF
  int varg_r2; // [sp+58h] [bp-8h] BYREF
  va_list varg_r2a; // [sp+58h] [bp-8h]
  int varg_r3; // [sp+5Ch] [bp-4h]
  unsigned __int64 v7; // [sp+60h] [bp+0h] BYREF
  va_list va1; // [sp+60h] [bp+0h]
  va_list va2; // [sp+68h] [bp+8h] BYREF

  va_start(va2, a2);
  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v7 = va_arg(va2, _QWORD);
  if ( PopDiagHandleRegistered )
  {
    v3[0] = 0;
    v3[1] = 0;
    if ( v7 >= 0xFFFFFFFF )
      v7 = 0xFFFFFFFFi64;
    v3[2] = v3;
    v3[3] = 0;
    v3[4] = 4;
    v3[5] = 0;
    va_copy((va_list)&v3[6], varg_r2a);
    v3[7] = 0;
    v3[8] = 4;
    v3[9] = 0;
    va_copy((va_list)&v3[10], va1);
    v3[11] = 0;
    v3[12] = 4;
    v3[13] = 0;
    result = EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_IDLE_RESILIENCY_START, 0);
  }
  return result;
}
