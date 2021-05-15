// sub_7C8F78 
 
void sub_7C8F78(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, ...)
{
  va_list va; // [sp+14h] [bp+14h] BYREF

  va_start(va, a9);
  IopGetRegistryValue(a9, L"Deny_Execute", 0, (int *)va);
  JUMPOUT(0x767EF0);
}
