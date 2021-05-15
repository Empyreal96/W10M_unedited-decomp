// CmpLogEvent 
 
int CmpLogEvent(int a1, ...)
{
  int result; // r0
  int v3; // r4
  int v4; // r3
  __int16 v5; // [sp+8h] [bp-98h] BYREF
  va_list v6; // [sp+10h] [bp-90h]
  int v7; // [sp+14h] [bp-8Ch]
  int v8; // [sp+18h] [bp-88h]
  int v9; // [sp+1Ch] [bp-84h]
  __int16 *v10; // [sp+20h] [bp-80h]
  int v11; // [sp+24h] [bp-7Ch]
  int v12; // [sp+28h] [bp-78h]
  int v13; // [sp+2Ch] [bp-74h]
  int v14; // [sp+30h] [bp-70h]
  int v15; // [sp+34h] [bp-6Ch]
  int v16; // [sp+38h] [bp-68h]
  int v17; // [sp+3Ch] [bp-64h]
  int varg_r1; // [sp+ACh] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+ACh] [bp+Ch]
  unsigned __int16 *varg_r2; // [sp+B0h] [bp+10h]
  va_list varg_r3; // [sp+B4h] [bp+14h] BYREF

  va_start(varg_r3, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r3, _DWORD);
  varg_r2 = va_arg(varg_r3, unsigned __int16 *);
  result = EtwKernelProvRegHandle;
  if ( EtwKernelProvRegHandle )
  {
    va_copy(v6, varg_r1a);
    v7 = 0;
    v8 = 4;
    v9 = 0;
    if ( varg_r2 )
    {
      v3 = *varg_r2;
      v5 = *varg_r2 >> 1;
      v10 = &v5;
      v11 = 0;
      v12 = 2;
      v13 = 0;
      v4 = *((_DWORD *)varg_r2 + 1);
      v16 = v3;
      v14 = v4;
      v15 = 0;
      v17 = 0;
    }
    result = EtwWrite(EtwKernelProvRegHandle, SHIDWORD(EtwKernelProvRegHandle), a1, 0);
  }
  return result;
}
