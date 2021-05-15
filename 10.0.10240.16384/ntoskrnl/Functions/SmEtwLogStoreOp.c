// SmEtwLogStoreOp 
 
int SmEtwLogStoreOp(int *a1, int a2, int a3, int a4, ...)
{
  int v4; // r2
  const struct _EVENT_DESCRIPTOR **v5; // r5
  int var60[25]; // [sp+20h] [bp-60h] BYREF
  int v8; // [sp+98h] [bp+18h] BYREF
  va_list va; // [sp+98h] [bp+18h]
  void *v10; // [sp+9Ch] [bp+1Ch] BYREF
  va_list va1; // [sp+9Ch] [bp+1Ch]
  void *v12; // [sp+A0h] [bp+20h] BYREF
  va_list va2; // [sp+A0h] [bp+20h]
  va_list va3; // [sp+A4h] [bp+24h] BYREF

  va_start(va3, a4);
  va_start(va2, a4);
  va_start(va1, a4);
  va_start(va, a4);
  v8 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v10 = va_arg(va2, void *);
  va_copy(va3, va2);
  v12 = va_arg(va3, void *);
  var60[0] = a3;
  v4 = 3;
  v5 = (&SmEtwDescriptorPtrs)[a2];
  var60[1] = 0;
  var60[2] = 4;
  var60[3] = 0;
  va_copy((va_list)&var60[4], va1);
  var60[5] = 0;
  var60[6] = 4;
  var60[7] = 0;
  va_copy((va_list)&var60[8], va);
  var60[9] = 0;
  var60[10] = 4;
  var60[11] = 0;
  if ( a2 != 1 )
  {
    va_copy((va_list)&var60[12], va2);
    var60[13] = 0;
    var60[14] = 2;
    var60[15] = 0;
    va_copy((va_list)&var60[16], va3);
    var60[17] = 0;
    var60[18] = 2;
    var60[19] = 0;
    v4 = 5;
  }
  return EtwWriteEx(*a1, a1[1], (int)v5, 1, 0, 0, 1, 0, 0, v4, (int)var60);
}
