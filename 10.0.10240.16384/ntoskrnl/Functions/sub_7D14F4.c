// sub_7D14F4 
 
void sub_7D14F4(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r7
  int v5; // r9
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  CmpDumpKeyBodyList(v5, (int *)va, v4);
  JUMPOUT(0x6D0388);
}
