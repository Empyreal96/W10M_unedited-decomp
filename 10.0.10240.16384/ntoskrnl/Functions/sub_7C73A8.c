// sub_7C73A8 
 
void sub_7C73A8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  int v8; // r6
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  if ( RegRtlOpenPredefinedKey(v8, (int)va) < 0 )
    JUMPOUT(0x6CBEC4);
  JUMPOUT(0x6CBE70);
}
