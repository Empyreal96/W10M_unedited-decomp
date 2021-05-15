// sub_537A8C 
 
void sub_537A8C(unsigned int *a1, int a2, int a3, int a4, ...)
{
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  MiLockTransitionLeafPage(a1, (unsigned int)va);
  JUMPOUT(0x495730);
}
