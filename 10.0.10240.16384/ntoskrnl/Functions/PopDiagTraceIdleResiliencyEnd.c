// PopDiagTraceIdleResiliencyEnd 
 
int PopDiagTraceIdleResiliencyEnd(int a1, int a2, ...)
{
  int result; // r0
  int v3; // [sp+8h] [bp-60h] BYREF
  _DWORD v4[17]; // [sp+10h] [bp-58h] BYREF
  va_list varg_r2; // [sp+60h] [bp-8h] BYREF

  va_start(varg_r2, a2);
  if ( PopDiagHandleRegistered )
  {
    v4[0] = 0;
    v4[1] = 0;
    v3 = 0;
    v4[2] = v4;
    v4[3] = 0;
    v4[4] = 4;
    v4[5] = 0;
    va_copy((va_list)&v4[6], varg_r2);
    v4[7] = 0;
    v4[8] = 4;
    v4[9] = 0;
    v4[10] = &v3;
    v4[11] = 0;
    v4[12] = 4;
    v4[13] = 0;
    result = EtwWrite(PopDiagHandle, dword_61E154, (int)POP_ETW_IDLE_RESILIENCY_END, 0);
  }
  return result;
}
