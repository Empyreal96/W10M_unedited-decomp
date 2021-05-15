// sub_7E9560 
 
void sub_7E9560(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r4
  va_list va; // [sp+50h] [bp+8h] BYREF

  va_start(va, a6);
  (*(void (__fastcall **)(int, char *))(v6 + 8))(v6, (char *)va);
  JUMPOUT(0x70234C);
}
