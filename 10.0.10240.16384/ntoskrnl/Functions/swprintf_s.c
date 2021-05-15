// swprintf_s 
 
int swprintf_s(int a1, int a2, int a3, ...)
{
  va_list varg_r3; // [sp+14h] [bp-4h] BYREF

  va_start(varg_r3, a3);
  return vswprintf_s(a1, a2, a3, (int *)varg_r3);
}
