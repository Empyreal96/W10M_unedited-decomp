// SmEtwLogRegionOp 
 
int SmEtwLogRegionOp(int *a1, int a2, ...)
{
  int var58[23]; // [sp+20h] [bp-58h] BYREF
  int varg_r2; // [sp+88h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+88h] [bp+10h]
  void *varg_r3; // [sp+8Ch] [bp+14h] BYREF
  va_list varg_r3a; // [sp+8Ch] [bp+14h]
  void *v8; // [sp+90h] [bp+18h] BYREF
  va_list va2; // [sp+90h] [bp+18h]
  void *v10; // [sp+94h] [bp+1Ch] BYREF
  va_list va3; // [sp+94h] [bp+1Ch]
  va_list va4; // [sp+98h] [bp+20h] BYREF

  va_start(va4, a2);
  va_start(va3, a2);
  va_start(va2, a2);
  va_start(varg_r3a, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3a, _DWORD);
  va_copy(va2, varg_r3a);
  varg_r3 = va_arg(va2, void *);
  va_copy(va3, va2);
  v8 = va_arg(va3, void *);
  va_copy(va4, va3);
  v10 = va_arg(va4, void *);
  va_copy((va_list)var58, varg_r2a);
  var58[1] = 0;
  var58[2] = 4;
  var58[3] = 0;
  va_copy((va_list)&var58[4], varg_r3a);
  var58[5] = 0;
  var58[6] = 4;
  var58[7] = 0;
  va_copy((va_list)&var58[8], va2);
  var58[9] = 0;
  var58[10] = 4;
  var58[11] = 0;
  va_copy((va_list)&var58[12], va3);
  var58[13] = 0;
  var58[14] = 2;
  var58[15] = 0;
  va_copy((va_list)&var58[16], va4);
  var58[17] = 0;
  var58[18] = 2;
  var58[19] = 0;
  return EtwWriteEx(
           *a1,
           a1[1],
           (int)(&SmEtwDescriptorPtrs)[a2],
           (int)&SmEtwDescriptorPtrs,
           0,
           0,
           1,
           0,
           0,
           5,
           (int)var58);
}
