// sub_53B360 
 
void sub_53B360(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r6
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  KiAcquireQueuedSpinLockInstrumented((char *)va, v6 + a1);
  JUMPOUT(0x49CCC8);
}
