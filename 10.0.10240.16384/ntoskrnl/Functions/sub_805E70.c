// sub_805E70 
 
// bad sp value at call has been detected, the output may be wrong!
void sub_805E70(int a1, int a2, int a3, void (__fastcall *a4)(int, int *), ...)
{
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  a4(a1, (int *)va);
  JUMPOUT(0x7522C4);
}
