// sub_7CF3C8 
 
void sub_7CF3C8(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  IopQueryProcessorInitValues((int)va);
  JUMPOUT(0x788A2C);
}
