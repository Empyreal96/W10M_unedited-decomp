// sub_7BF0A0 
 
void sub_7BF0A0(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r5
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  ExpCreateRestrictedFastCacheRegistryKey(v6, (char *)va);
  JUMPOUT(0x7B5F3C);
}
