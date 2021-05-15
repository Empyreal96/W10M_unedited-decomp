// sub_805E64 
 
void sub_805E64(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r4
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  (*(void (__fastcall **)(int, int *))(v4 + 8))(v4, (int *)va);
  JUMPOUT(0x75225A);
}
