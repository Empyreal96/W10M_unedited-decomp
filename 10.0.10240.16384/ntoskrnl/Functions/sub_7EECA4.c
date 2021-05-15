// sub_7EECA4 
 
void sub_7EECA4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, ...)
{
  int v18; // r9
  int v19; // r10
  va_list va; // [sp+38h] [bp+38h] BYREF

  va_start(va, a18);
  if ( PiDmGetObject(v18, v19, (int *)va) < 0 )
    JUMPOUT(0x780F96);
  JUMPOUT(0x780ED2);
}
