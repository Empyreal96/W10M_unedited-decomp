// sub_521970 
 
void sub_521970(int a1, int a2, int a3, int a4, ...)
{
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  EtwpLogMemInfo(0, (int *)va);
  JUMPOUT(0x455EC0);
}
