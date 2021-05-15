// KiInitiateUserApc 
 
int KiInitiateUserApc(int a1, int a2, int a3, int a4, ...)
{
  int v5; // [sp+0h] [bp-30h] BYREF
  va_list va; // [sp+38h] [bp+8h] BYREF

  va_start(va, a4);
  return KiDeliverApc(1, &v5, (char *)va);
}
