// sub_7BF0B8 
 
void sub_7BF0B8(int a1, int a2, int a3, int a4, ...)
{
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  PopExecuteOnTargetProcessors((int)va, (int)PpmResetInterruptRate, 0, 0);
  JUMPOUT(0x6A24A6);
}
