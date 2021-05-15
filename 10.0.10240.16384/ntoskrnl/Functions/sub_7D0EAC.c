// sub_7D0EAC 
 
void sub_7D0EAC(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // [sp+8h] [bp+8h] BYREF
  va_list va; // [sp+8h] [bp+8h]
  int v8; // [sp+Ch] [bp+Ch]
  va_list va1; // [sp+10h] [bp+10h] BYREF

  va_start(va1, a6);
  va_start(va, a6);
  v6 = va_arg(va1, _DWORD);
  v8 = va_arg(va1, _DWORD);
  KeQueryPerformanceCounter((int *)va, va1);
  JUMPOUT(0x6CF7B8);
}
