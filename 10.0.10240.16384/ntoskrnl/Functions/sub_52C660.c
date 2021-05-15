// sub_52C660 
 
void sub_52C660(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  int v8; // r4
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  KiAcquireQueuedSpinLockInstrumented((char *)va, v8);
  JUMPOUT(0x47253A);
}
