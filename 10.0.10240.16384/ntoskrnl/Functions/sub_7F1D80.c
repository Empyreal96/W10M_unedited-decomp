// sub_7F1D80 
 
void sub_7F1D80(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, ...)
{
  va_list va; // [sp+24h] [bp+24h] BYREF

  va_start(va, a13);
  PopDefaultPolicy((int)va);
  JUMPOUT(0x78D8AC);
}
