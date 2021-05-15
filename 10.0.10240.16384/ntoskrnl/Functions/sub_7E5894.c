// sub_7E5894 
 
void sub_7E5894(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, ...)
{
  va_list va; // [sp+30h] [bp+30h] BYREF

  va_start(va, a16);
  KiStackAttachProcess(a1, 0, (int)va);
  JUMPOUT(0x6EFB62);
}
