// sub_809010 
 
void sub_809010(int a1, int a2, int a3, int a4, ...)
{
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  ExfAcquireRundownProtection((int *)va);
  JUMPOUT(0x75CFCA);
}
