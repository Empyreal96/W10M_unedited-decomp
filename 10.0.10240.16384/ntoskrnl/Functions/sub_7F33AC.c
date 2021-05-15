// sub_7F33AC 
 
void sub_7F33AC(int a1, int a2, int a3, void (*a4)(void), ...)
{
  unsigned int v4; // r5
  unsigned int v5; // r7
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  a4();
  KeDelayExecutionThread(0, 0, (unsigned int *)va);
  if ( v4 > v5 )
    IopDisassociateThreadIrp();
  JUMPOUT(0x70C79A);
}
