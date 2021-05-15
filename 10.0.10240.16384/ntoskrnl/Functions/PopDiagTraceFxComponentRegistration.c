// PopDiagTraceFxComponentRegistration 
 
int PopDiagTraceFxComponentRegistration(int a1, ...)
{
  int v2[29]; // [sp+8h] [bp-88h] BYREF
  int varg_r1; // [sp+84h] [bp-Ch] BYREF
  va_list varg_r1a; // [sp+84h] [bp-Ch]
  void *varg_r2; // [sp+88h] [bp-8h] BYREF
  va_list varg_r2a; // [sp+88h] [bp-8h]
  int varg_r3; // [sp+8Ch] [bp-4h]
  void *v8; // [sp+90h] [bp+0h] BYREF
  va_list va2; // [sp+90h] [bp+0h]
  void *v10; // [sp+94h] [bp+4h] BYREF
  va_list va3; // [sp+94h] [bp+4h]
  int v12; // [sp+98h] [bp+8h]
  va_list va4; // [sp+9Ch] [bp+Ch] BYREF

  va_start(va4, a1);
  va_start(va3, a1);
  va_start(va2, a1);
  va_start(varg_r2a, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r2a, _DWORD);
  va_copy(va2, varg_r2a);
  varg_r2 = va_arg(va2, void *);
  varg_r3 = va_arg(va2, _DWORD);
  va_copy(va3, va2);
  v8 = va_arg(va3, void *);
  va_copy(va4, va3);
  v10 = va_arg(va4, void *);
  v12 = va_arg(va4, _DWORD);
  v2[0] = varg_r3;
  va_copy((va_list)&v2[2], varg_r1a);
  v2[3] = 0;
  v2[4] = 4;
  v2[5] = 0;
  va_copy((va_list)&v2[6], varg_r2a);
  v2[7] = 0;
  v2[8] = 4;
  v2[9] = 0;
  v2[10] = (int)v2;
  v2[11] = 0;
  v2[12] = 4;
  v2[13] = 0;
  va_copy((va_list)&v2[14], va2);
  v2[15] = 0;
  v2[16] = 4;
  v2[17] = 0;
  va_copy((va_list)&v2[18], va3);
  v2[19] = 0;
  v2[20] = 4;
  v2[21] = 0;
  v2[22] = v12;
  v2[23] = 0;
  v2[24] = 24 * (_DWORD)v10;
  v2[25] = 0;
  return EtwWrite(PopDiagHandle, dword_61E154, a1, 0);
}
