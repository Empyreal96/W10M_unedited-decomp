// sub_7C2890 
 
void sub_7C2890(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, ...)
{
  va_list va; // [sp+40h] [bp+40h] BYREF

  va_start(va, a20);
  memmove((int)va, a4 + 8, 0x40u);
  JUMPOUT(0x6B00AC);
}
