// KiVerifyXcpt15 
 
void __noreturn KiVerifyXcpt15(int a1, int a2, int a3, int a4, ...)
{
  va_list va; // [sp+2F8h] [bp+8h] BYREF

  va_start(va, a4);
  KiVerifyXcpt2();
  _jump_unwind((int)va, (int)&loc_930286 + 1);
}
