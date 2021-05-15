// SmEtwLogStoreStateChange 
 
int SmEtwLogStoreStateChange(int *a1, int a2, ...)
{
  int v3[11]; // [sp+20h] [bp-40h] BYREF
  int varg_r2; // [sp+58h] [bp-8h] BYREF
  va_list varg_r2a; // [sp+58h] [bp-8h]
  va_list varg_r3; // [sp+5Ch] [bp-4h] BYREF

  va_start(varg_r3, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3, _DWORD);
  va_copy((va_list)v3, varg_r2a);
  v3[1] = 0;
  v3[2] = 4;
  v3[3] = 0;
  va_copy((va_list)&v3[4], varg_r3);
  v3[5] = 0;
  v3[6] = 4;
  v3[7] = 0;
  return EtwWriteEx(*a1, a1[1], (int)StEventStoreEmpty, (int)&SmEtwDescriptorPtrs, 0, 0, 1, 0, 0, 2, (int)v3);
}
