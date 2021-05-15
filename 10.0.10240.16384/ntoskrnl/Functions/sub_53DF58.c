// sub_53DF58 
 
void sub_53DF58(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, ...)
{
  int v10; // r4
  va_list va; // [sp+18h] [bp+18h] BYREF

  va_start(va, a10);
  KiAcquireQueuedSpinLockInstrumented((char *)va, v10);
  JUMPOUT(0x4A57A8);
}
