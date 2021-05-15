// sub_7EAC80 
 
void sub_7EAC80(int a1, int a2, int a3, int a4, ...)
{
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  KeDelayExecutionThread(0, 0, (unsigned int *)va);
  JUMPOUT(0x70747A);
}
