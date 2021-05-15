// sub_522F24 
 
void sub_522F24(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  PpmIdleTransitionStall((int)va, a2, a3, a4);
  JUMPOUT(0x458DC0);
}
