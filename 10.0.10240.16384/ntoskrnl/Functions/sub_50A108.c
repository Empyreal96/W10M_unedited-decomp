// sub_50A108 
 
void sub_50A108(int a1, int a2, int a3, int a4, ...)
{
  unsigned int v4; // r8
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  MiInsertTbFlushEntry((int)va, v4, 1, 0);
  JUMPOUT(0x4315E0);
}
