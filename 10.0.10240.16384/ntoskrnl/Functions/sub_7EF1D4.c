// sub_7EF1D4 
 
void sub_7EF1D4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, ...)
{
  int v14; // r5
  va_list va; // [sp+28h] [bp+28h] BYREF

  va_start(va, a14);
  PnpCtxRegDeleteKey(v14, a9, (char *)va);
  JUMPOUT(0x781B10);
}
