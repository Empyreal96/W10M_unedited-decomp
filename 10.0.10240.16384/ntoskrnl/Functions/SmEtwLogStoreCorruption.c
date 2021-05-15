// SmEtwLogStoreCorruption 
 
int SmEtwLogStoreCorruption(int *a1, int a2, ...)
{
  int v3; // r2
  int v5; // [sp+20h] [bp-A0h] BYREF
  int v6; // [sp+24h] [bp-9Ch] BYREF
  int v7; // [sp+28h] [bp-98h] BYREF
  int v8[2]; // [sp+30h] [bp-90h] BYREF
  int v9[2]; // [sp+38h] [bp-88h] BYREF
  int var80[33]; // [sp+40h] [bp-80h] BYREF
  int varg_r2; // [sp+D0h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+D0h] [bp+10h]
  int varg_r3; // [sp+D4h] [bp+14h]
  void *v14; // [sp+D8h] [bp+18h] BYREF
  va_list va1; // [sp+D8h] [bp+18h]
  int *v16; // [sp+DCh] [bp+1Ch]
  va_list va2; // [sp+E0h] [bp+20h] BYREF

  va_start(va2, a2);
  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v14 = va_arg(va2, void *);
  v16 = va_arg(va2, int *);
  v3 = *v16;
  v7 = varg_r3;
  v5 = v3;
  v6 = v16[1];
  va_copy((va_list)var80, varg_r2a);
  var80[1] = 0;
  var80[2] = 4;
  var80[3] = 0;
  var80[4] = (int)&v7;
  var80[5] = 0;
  var80[6] = 4;
  var80[7] = 0;
  MmGetPhysicalAddress((int)v8, v7, 0, v7);
  v9[0] = v8[0];
  v9[1] = v8[1];
  var80[8] = (int)v9;
  var80[9] = 0;
  var80[10] = 8;
  var80[11] = 0;
  va_copy((va_list)&var80[12], va1);
  var80[13] = 0;
  var80[14] = 2;
  var80[15] = 0;
  var80[16] = (int)&v5;
  var80[17] = 0;
  var80[18] = 1;
  var80[19] = 0;
  var80[20] = (int)&v5 + 1;
  var80[21] = 0;
  var80[22] = 1;
  var80[23] = 0;
  var80[24] = (int)&v6;
  var80[25] = 0;
  var80[26] = 4;
  var80[27] = 0;
  return EtwWriteEx(*a1, a1[1], (int)StEventStoreCorruption, 1, 0, 0, 1, 0, 0, 7, (int)var80);
}
