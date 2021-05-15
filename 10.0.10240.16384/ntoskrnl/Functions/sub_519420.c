// sub_519420 
 
void sub_519420(int a1, int a2, int a3, int a4, ...)
{
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  NtDelayExecution(0, (int *)va);
  JUMPOUT(0x4DAE32);
}
