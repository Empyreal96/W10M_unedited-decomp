// EtwTraceSystemTimeChange 
 
int EtwTraceSystemTimeChange(int *a1, int *a2, ...)
{
  int v4; // r3
  int result; // r0
  int v6; // [sp+8h] [bp-B0h] BYREF
  int v7[2]; // [sp+10h] [bp-A8h] BYREF
  int v8[14]; // [sp+18h] [bp-A0h] BYREF
  _DWORD var68[27]; // [sp+50h] [bp-68h] BYREF
  int varg_r2; // [sp+C8h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+C8h] [bp+10h]
  va_list varg_r3; // [sp+CCh] [bp+14h] BYREF

  va_start(varg_r3, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3, _DWORD);
  if ( (unsigned int)dword_617748 > 5 && TlgKeywordOn((int)&dword_617748, 0x200000000000i64) )
  {
    v4 = *a1;
    v6 = varg_r2;
    v8[0] = v4;
    v8[1] = a1[1];
    v7[0] = *a2;
    v7[1] = a2[1];
    var68[8] = v8;
    var68[9] = 0;
    var68[10] = 8;
    var68[11] = 0;
    var68[12] = v7;
    var68[13] = 0;
    var68[14] = 8;
    var68[15] = 0;
    var68[16] = &v6;
    var68[17] = 0;
    var68[18] = 4;
    var68[19] = 0;
    TlgWrite(&dword_617748, (unsigned __int8 *)dword_414A68, 0, 0, 5, var68);
  }
  result = EtwKernelProvRegHandle;
  if ( EtwKernelProvRegHandle )
  {
    v8[2] = (int)a1;
    v8[3] = 0;
    v8[4] = 8;
    v8[5] = 0;
    v8[6] = (int)a2;
    v8[7] = 0;
    v8[8] = 8;
    v8[9] = 0;
    va_copy((va_list)&v8[10], varg_r2a);
    v8[11] = 0;
    v8[12] = 4;
    v8[13] = 0;
    result = EtwWrite(
               EtwKernelProvRegHandle,
               SHIDWORD(EtwKernelProvRegHandle),
               (int)KernelSystemTimeChangeWithReason,
               0);
  }
  return result;
}
