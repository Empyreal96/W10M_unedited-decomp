// sub_7C6AC0 
 
void sub_7C6AC0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  NtOpenKeyTransacted_Stub(a1, a2, (char *)va);
  JUMPOUT(0x6C954E);
}
