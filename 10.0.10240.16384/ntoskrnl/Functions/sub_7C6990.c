// sub_7C6990 
 
void sub_7C6990(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, ...)
{
  va_list va; // [sp+40h] [bp+40h] BYREF

  va_start(va, a20);
  if ( PiDmGetObject(a8, a7, (int *)va) < 0 )
    JUMPOUT(0x6C89FE);
  JUMPOUT(0x6C8A22);
}
