// sub_80C0B8 
 
void sub_80C0B8(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r4
  int v5; // r6
  va_list va; // [sp+38h] [bp+0h] BYREF

  va_start(va, a4);
  RtlpMuiRegInitLIPLanguage(v4, v5, (int *)va);
  JUMPOUT(0x792390);
}
