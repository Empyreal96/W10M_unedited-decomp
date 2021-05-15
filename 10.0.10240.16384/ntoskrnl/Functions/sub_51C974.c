// sub_51C974 
 
void sub_51C974(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r8
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  KiAcquireQueuedSpinLockInstrumented((int *)va, v4);
  JUMPOUT(0x4485BC);
}
