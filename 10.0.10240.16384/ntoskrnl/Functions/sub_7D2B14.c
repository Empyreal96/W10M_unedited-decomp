// sub_7D2B14 
 
void sub_7D2B14(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r4
  int v7; // r5
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  EtwWrite(v7, v6, (int)va, 0);
  JUMPOUT(0x6D2880);
}
