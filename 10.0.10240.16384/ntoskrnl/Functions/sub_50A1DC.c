// sub_50A1DC 
 
void sub_50A1DC(int a1, int a2, int a3, int a4, ...)
{
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  KeReleaseInStackQueuedSpinLock((int)va);
  JUMPOUT(0x432882);
}
