// sub_8136D4 
 
void sub_8136D4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, ...)
{
  va_list va; // [sp+28h] [bp+28h] BYREF

  va_start(va, a14);
  if ( ExUuidCreate((int)va) < 0 )
    JUMPOUT(0x7A5450);
  JUMPOUT(0x7A53C0);
}
